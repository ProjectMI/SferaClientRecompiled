#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

static void sfera_filebuf_write_bytes(LiftCpu* cpu, uint32_t filebuf, uint32_t data, uint32_t count) {
    uint32_t written = 0u;
    while (written < count) {
        lift_push32(cpu, lift_load8(data + written));
        cpu->ecx = filebuf;
        { uint32_t r=LIFT_CALLBACK_SENTINEL; lift_push32(cpu, r); sfera_sub_004B2680(cpu,r); if (cpu->eip != r) return; }
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

static FILE* sfera_filebuf_file(uint32_t filebuf) { return reinterpret_cast<FILE*>(static_cast<uintptr_t>(lift_load32(filebuf + 0x54u))); }

static bool sfera_filebuf_close_native(uint32_t filebuf) {
    FILE* file = sfera_filebuf_file(filebuf);
    if (file == nullptr) { return false; }
    const bool success = std::fclose(file) == 0;
    lift_store8(filebuf + 0x50u, 0u);
    lift_store8(filebuf + 0x49u, 0u);
    lift_store32(filebuf + 0x54u, 0u);
    lift_store32(filebuf + 0x4Cu, g_sfera_recovered_static_runtime.ui_counter_a);
    lift_store32(filebuf + 0x44u, 0u);
    return success;
}

static uint8_t sfera_string_obfuscation_primary_shift(uint32_t index) { switch (index % 13u) { case 0u: return 1u; case 1u: return 2u; case 2u: return 3u; case 3u: return UINT8_C(0xFE); case 4u: return 1u; case 5u: return UINT8_C(0xFF); case 6u: return UINT8_C(0xFE); case 7u: return UINT8_C(0xFD); case 8u: return 2u; case 9u: return UINT8_C(0xFF); case 10u: return 0u; case 11u: return UINT8_C(0xFE); default: return 2u; } }
static uint8_t sfera_string_obfuscation_secondary_shift(uint32_t index) { switch (index % 7u) { case 0u: return 0u; case 1u: return UINT8_C(0xFF); case 2u: return UINT8_C(0xFE); case 3u: return 2u; case 4u: return UINT8_C(0xFF); case 5u: return 0u; default: return 1u; } }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AFD50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFD50u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::HyperTextCtrl*>(cpu->esi));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x198u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x18u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000AFDB9;
    cpu->edx = 0x6Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFD9Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000AFDB9;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFDB0u); lift_push32(cpu, r); sfera_sub_004A7A00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFDB6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000AFDB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFDB9u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x2C4u)) == (uint32_t)(0u)) goto label_000AFDEB;
    cpu->edx = 0x70u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFDD1u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x2C4u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000AFDEB;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFDE2u); lift_push32(cpu, r); sfera_sub_004A7A00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFDE8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000AFDEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFDEBu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x2D8u)) == (uint32_t)(0u)) goto label_000AFE16;
    cpu->edx = 0x71u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFE03u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x2D8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000AFE16;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000AFE16: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFE16u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x2DCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFE21u); lift_push32(cpu, r); sfera_sub_004AF470(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x2DCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFE2Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x2DCu, 0u);
    lift_store32(cpu->esp + 0x18u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFE49u); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004AFE60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFE60u);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    cpu->ebx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AFE8B;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AFE8B;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AFE8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFE8Bu);
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFE9Eu); lift_push32(cpu, r); sfera_sub_0049F9C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AFEBE;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AFEBE;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AFEBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFEBEu);
    cpu->edx = lift_load32(cpu->esp + 0x68u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFED1u); lift_push32(cpu, r); sfera_sub_0049F9C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFEDDu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edi = lift_load32(cpu->esp + 0x30u);
    cpu->edx = cpu->eax;
    cpu->edx -= cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->edi)) goto label_000AFEFE;
    cpu->ebp = cpu->edi;
    cpu->ebp -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    goto label_000AFF08;
    label_000AFEFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFEFEu);
    cpu->ecx = cpu->edi;
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->ebp = cpu->ecx;
    label_000AFF08: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFF08u);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFF14u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->eax -= cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esp -= 0xCu;
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->ebx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x24u, cpu->esp);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000AFFE8;
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AFF48;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AFF48;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AFF48: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFF48u);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x30u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AFF6F;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AFF6F;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AFF6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFF6Fu);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    cpu->esp -= 0xCu;
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x3Cu, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFF87u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFF90u); lift_push32(cpu, r); sfera_sub_004AFA50(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(cpu->ebx)) goto label_000B0094;
    cpu->ebp = 0xFu;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000AFFA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFFA0u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(cpu->ebx)) goto label_000AFFDD;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_000AFFBF;
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4AFFBCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000AFFBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFFBFu);
    lift_store32(cpu->edi + 0x14u, cpu->ebp);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_store8(cpu->edi, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0xCu, (uint64_t)(lift_load32(cpu->esi + 0xCu)) + 1u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) > (uint32_t)(cpu->eax)) goto label_000AFFD5;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_000AFFD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFFD5u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AFFDD;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_000AFFDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFFDDu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000AFFA0;
    goto label_000B0094;
    label_000AFFE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFFE8u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AFFFA;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000AFFFA;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000AFFFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4AFFFAu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->esp -= 0xCu;
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x30u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0012u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x3Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000B0032;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000B0032;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000B0032: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0032u);
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0042u); lift_push32(cpu, r); sfera_sub_004AFAE0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(cpu->ebx)) goto label_000B0094;
    cpu->ebp = 0xFu;
    label_000B0050: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0050u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000B008E;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0xFFFFFFFFu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000B0067;
    cpu->eax -= cpu->ecx;
    label_000B0067: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0067u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_000B007E;
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B007Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B007E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B007Eu);
    lift_store32(cpu->edi + 0x14u, cpu->ebp);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_store8(cpu->edi, cpu->ebx & 0xFFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B008E;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_000B008E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B008Eu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B0050;
    label_000B0094: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0094u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B00AAu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B00B1u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 28u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B00C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B00C0u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000B00FB;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000B00D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B00D0u);
    --cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000B00FB;
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B00EAu); lift_push32(cpu, r); sfera_sub_004AFB70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000B00D0;
    label_000B00FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B00FBu);
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B0100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0100u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0131u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 1.0);
    cpu->ebx = 0u;
    lift_store_f32(cpu->esi + 0x2C8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    std::construct_at(reinterpret_cast<SphereUI::HyperTextCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x198u, cpu->ebx);
    lift_store8(cpu->esi + 0x2A0u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x2A4u, cpu->ebx);
    lift_store32(cpu->esi + 0x2A8u, cpu->ebx);
    lift_store32(cpu->esi + 0x2ACu, cpu->ebx);
    lift_store32(cpu->esi + 0x2B0u, cpu->ebx);
    lift_store32(cpu->esi + 0x2B4u, cpu->ebx);
    lift_store32(cpu->esi + 0x2C4u, cpu->ebx);
    lift_store8(cpu->esi + 0x2CCu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x2D0u, cpu->ebx);
    lift_store32(cpu->esi + 0x2D4u, cpu->ebx);
    cpu->edi = (uint32_t)(cpu->esi + 0x2DCu);
    lift_store32(cpu->esi + 0x2D8u, cpu->ebx);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_store32(cpu->edi, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0x34u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B01A5u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000B0222;
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->edi + 4u, cpu->ebx);
    lift_store32(cpu->edi + 8u, cpu->ebx);
    lift_store32(cpu->edi + 0xCu, cpu->ebx);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x2F4u, 0xFFFF0000u);
    lift_store32(cpu->esi + 0x2F8u, 0xFFFFFF00u);
    lift_store32(cpu->esi + 0x2FCu, 0xFFFFFFFFu);
    lift_store8(cpu->esi + 0x308u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esi + 0x48u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x50u, 6u);
    lift_store8(cpu->esi + 0x1A0u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x19Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x300u, cpu->ebx);
    lift_store32(cpu->esi + 0x304u, cpu->ebx);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_000B0222: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0222u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B024Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4B024Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B0250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0250u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0258u); lift_push32(cpu, r); sfera_sub_004AFD50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000B0268;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0265u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B0268: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0268u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B0270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0270u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x58u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x1A0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (uint32_t)(cpu->esi + 0x1A0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B056B;
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x300u)) != (uint32_t)(cpu->ebx)) goto label_000B02CA;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B02C6u); lift_push32(cpu, r); sfera_sub_004B9350(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    goto label_000B0335;
    label_000B02CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B02CAu);
    cpu->edx = 0x14Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B02D9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x68u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B02E0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x60u, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000B02FA;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B02F6u); lift_push32(cpu, r); sfera_sub_004A78F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    goto label_000B02FC;
    label_000B02FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B02FAu);
    cpu->ecx = 0u;
    label_000B02FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B02FCu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x8Cu)) & 0xFFu);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    lift_store32(cpu->esp + 0x60u, 0xFFFFFFFFu);
    cpu->ebp = cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) >= (uint8_t)(2u)) goto label_000B0316;
    cpu->edx -= 2u;
    label_000B0316: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0316u);
    cpu->eax = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x300u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x304u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB0335u); lift_push32(cpu, r); sfera_sub_004A8720(cpu,r); if (cpu->eip != r) return; }
    label_000B0335: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0335u);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_000B0558;
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    lift_store8(cpu->esp + 0x17u, 0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000B044B;
    if ((uint8_t)(lift_load8(cpu->esi + 0x308u)) == (uint8_t)(0u)) goto label_000B038D;
    cpu->edx = 0x15Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0368u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_000B0382;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0379u); lift_push32(cpu, r); sfera_sub_004A7A00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B037Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B0382: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0382u);
    lift_store32(cpu->esi + 0x198u, cpu->ebx);
    goto label_000B0410;
    label_000B038D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B038Du);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x2A0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_x87_push(cpu, 0.0);
    cpu->ebx = 1u;
    lift_store_f32(cpu->esi + 0x2C8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->esi + 0x2CCu, cpu->ebx & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B03DA;
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B03B5u); lift_push32(cpu, r); sfera_sub_004090F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x2DCu);
    lift_store32(cpu->esp + 0x64u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B03C9u); lift_push32(cpu, r); sfera_sub_004AF8A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_store32(cpu->esp + 0x60u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB03DAu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    label_000B03DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B03DAu);
    cpu->edx = lift_load32(cpu->esi + 0x198u);
    cpu->eax = lift_load32(cpu->esi + 0x2ACu);
    cpu->ecx = lift_load32(cpu->esi + 0x2B0u);
    lift_store32(cpu->esi + 0x2C4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x2B4u);
    lift_store8(cpu->esp + 0x17u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x2B8u, cpu->eax);
    lift_store32(cpu->esi + 0x2BCu, cpu->ecx);
    lift_store32(cpu->esi + 0x2C0u, cpu->edx);
    cpu->ebx = 0u;
    label_000B0410: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0410u);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000B043A;
    cpu->eax = lift_load32(cpu->esi + 0xD8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, cpu->esi);
    lift_store32(cpu->esp + 0x44u, 0xA90u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB043Au); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000B043A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B043Au);
    cpu->ecx = lift_load32(cpu->esi + 0xECu);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x48u)) != (uint8_t)(0u)) goto label_000B044B;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB044Bu); lift_push32(cpu, r); sfera_sub_004CF750(cpu,r); if (cpu->eip != r) return; }
    label_000B044B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B044Bu);
    lift_store32(cpu->esi + 0x2FCu, 0xFFFFFFFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x300u)) != (uint32_t)(cpu->ebx)) goto label_000B0489;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x8Cu)) & 0xFFu);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) >= (uint8_t)(2u)) goto label_000B046E;
    cpu->eax -= 2u;
    label_000B046E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B046Eu);
    cpu->edx = lift_load32(cpu->esi + 0x19Cu);
    cpu->ecx = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0481u); lift_push32(cpu, r); sfera_sub_004A88A0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    goto label_000B048F;
    label_000B0489: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0489u);
    lift_store32(cpu->esi + 0x198u, cpu->ebp);
    label_000B048F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B048Fu);
    cpu->ecx = lift_load32(cpu->esi + 0x2F8u);
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    cpu->edx = lift_load32(cpu->esi + 0x2F4u);
    lift_store32(cpu->eax + 0x50u, cpu->edx);
    lift_store32(cpu->eax + 0x54u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B04B2u); lift_push32(cpu, r); sfera_sub_004A6220(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->esp + 0x68u)) == (uint8_t)(0u)) goto label_000B04C0;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000B04C0;
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    label_000B04C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B04C0u);
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->eax)) goto label_000B04CF;
    lift_store32(cpu->esi + 0x2A4u, cpu->ebx);
    goto label_000B04D7;
    label_000B04CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B04CFu);
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esi + 0x2A4u, cpu->eax);
    label_000B04D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B04D7u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x2A8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B04E4u); lift_push32(cpu, r); sfera_sub_004AEC80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x2D8u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000B0540;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x2A4u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x28u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    lift_store32(cpu->esp + 0x24u, 0x17u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB0540u); lift_push32(cpu, r); sfera_sub_004C79A0(cpu,r); if (cpu->eip != r) return; }
    label_000B0540: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0540u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) == (uint8_t)(0u)) goto label_000B0558;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B054Cu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x2D0u, cpu->eax);
    lift_store32(cpu->esi + 0x2D4u, cpu->edx);
    label_000B0558: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0558u);
    lift_store8(cpu->esi + 0x1A0u, 0u);
    lift_store32(cpu->esi + 0x300u, cpu->ebx);
    lift_store32(cpu->esi + 0x304u, cpu->ebx);
    label_000B056B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B056Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B0590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0590u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0x1A0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B05AC;
    lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB05ACu); lift_push32(cpu, r); sfera_sub_004B0270(cpu,r); if (cpu->eip != r) return; }
    label_000B05AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B05ACu);
    cpu->ecx = lift_load32(cpu->ebp + 0x2D8u);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000B05C4;
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000B05C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B05C4u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x2CCu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B0678;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B05D5u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebp + 0x2D0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->ebp + 0x2D4u)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 0x20u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10000.0));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->ebp + 0x2C8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000B0620;
    lift_store_f32(cpu->ebp + 0x2C8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000B0622;
    label_000B0620: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0620u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000B0622: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0622u);
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->ebp + 0x2C8u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000B0676;
    lift_store_f32(cpu->ebp + 0x2C8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->ebp + 0x2CCu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x2C4u)) == (uint32_t)(cpu->ebx)) goto label_000B0678;
    cpu->edx = 0x1C6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0654u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->ebp + 0x2C4u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000B066E;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0665u); lift_push32(cpu, r); sfera_sub_004A7A00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B066Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B066E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B066Eu);
    lift_store32(cpu->ebp + 0x2C4u, cpu->ebx);
    goto label_000B0678;
    label_000B0676: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0676u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000B0678: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0678u);
    cpu->esi = lift_load32(cpu->ebp + 0x198u);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000B08A5;
    cpu->ecx = lift_load32(cpu->esi + 0x44u);
    cpu->ecx -= lift_load32(cpu->esi + 0x40u);
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    lift_store32(cpu->esp + 0x24u, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000B076C;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000B06C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B06C0u);
    cpu->ecx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx += lift_load32(cpu->esp + 0x18u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x124u)) == (uint8_t)(0u)) goto label_000B0745;
    cpu->esi = 0u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x120u)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000B0716;
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->ebp = lift_load32(cpu->eax);
    cpu->eax = (uint32_t)(cpu->ecx + 0x88u);
    label_000B06E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B06E8u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xFFFFFFF8u))) goto label_000B0702;
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->eax))) goto label_000B0702;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xFFFFFFFCu))) goto label_000B0702;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 4u))) goto label_000B0710;
    label_000B0702: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0702u);
    ++cpu->esi;
    cpu->eax += 0x10u;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x120u))) goto label_000B06E8;
    goto label_000B0712;
    label_000B0710: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0710u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    label_000B0712: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0712u);
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    label_000B0716: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0716u);
    lift_store8(cpu->ecx + 0x125u, cpu->ebx & 0xFFu);
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_000B0760;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ebp + 0x2FCu))) goto label_000B0741;
    cpu->ecx = lift_load32(cpu->ebp + 0xECu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0737u); lift_push32(cpu, r); sfera_sub_004CF750(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x2FCu, 0xFFFFFFFFu);
    label_000B0741: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0741u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    label_000B0745: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0745u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(0x128u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_000B06C0;
    goto label_000B076C;
    label_000B0760: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0760u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    label_000B076C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B076Cu);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->ebp + 0x2FCu))) goto label_000B07C3;
    cpu->ecx = lift_load32(cpu->ebp + 0xECu);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x48u)) != (uint8_t)(0u)) goto label_000B0789;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB0789u); lift_push32(cpu, r); sfera_sub_004CF750(cpu,r); if (cpu->eip != r) return; }
    label_000B0789: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0789u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_000B07C3;
    cpu->ecx = lift_load32(cpu->ebp + 0xECu);
    cpu->edx = cpu->edi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x128u);
    cpu->edx += lift_load32(cpu->esi + 0x40u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B07A7u); lift_push32(cpu, r); sfera_sub_004D0060(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0xECu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B07BDu); lift_push32(cpu, r); sfera_sub_004CF770(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x2FCu, cpu->edi);
    label_000B07C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B07C3u);
    cpu->edi = lift_load32(cpu->ebp + 0x198u);
    cpu->esi = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->ecx -= cpu->esi;
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B08A4;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    label_000B07F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B07F0u);
    cpu->esi += lift_load32(cpu->esp + 0x1Cu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x124u)) == (uint8_t)(0u)) goto label_000B0878;
    cpu->edx = 0u;
    lift_store8(cpu->esp + 0x13u, 0u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x120u)) <= (int32_t)(uint32_t)(cpu->edx)) goto label_000B086E;
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->ebp = lift_load32(cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 0x88u);
    label_000B0818: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0818u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xFFFFFFF8u))) goto label_000B0832;
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->eax))) goto label_000B0832;
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xFFFFFFFCu))) goto label_000B0832;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 4u))) goto label_000B0840;
    label_000B0832: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0832u);
    ++cpu->edx;
    cpu->eax += 0x10u;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x120u))) goto label_000B0818;
    goto label_000B086E;
    label_000B0840: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0840u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    if ((uint8_t)((lift_load8(cpu->edx + 0xCu)) & (1u)) == 0u) goto label_000B0869;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0854u); lift_push32(cpu, r); sfera_sub_004AED90(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_interface_runtime.sounds_enabled) == (uint32_t)(0u)) goto label_000B0869;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"Sounds\\in_link.wav";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB0869u); lift_push32(cpu, r); sfera_sub_00498060(cpu,r); if (cpu->eip != r) return; }
    label_000B0869: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0869u);
    lift_store8(cpu->esp + 0x13u, 1u);
    label_000B086E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B086Eu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x13u)) & 0xFFu);
    lift_store8(cpu->esi + 0x125u, cpu->eax & 0xFFu);
    label_000B0878: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0878u);
    cpu->esi = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(0x128u) + (uint64_t)(0u));
    cpu->ecx -= cpu->esi;
    cpu->eax = 0xDD67C8A7u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    ++cpu->ebx;
    cpu->ecx += cpu->edx;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->ecx)) goto label_000B07F0;
    label_000B08A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B08A4u);
    cpu->edi = lift_pop32(cpu);
    label_000B08A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B08A5u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B08B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B08B0u);
    cpu->esp -= 0x20u;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xA8Du), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000B0998;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B090E;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x66u)) goto label_000B0ADE;
    if ((uint32_t)(lift_load32(cpu->esi + 0x198u)) == (uint32_t)(0u)) goto label_000B08F6;
    lift_store32(cpu->esi + 0x2A8u, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB08F6u); lift_push32(cpu, r); sfera_sub_004AEC80(cpu,r); if (cpu->eip != r) return; }
    label_000B08F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B08F6u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000B090E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B090Eu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x2ECu)) == (uint32_t)(0u)) goto label_000B0980;
    cpu->ecx = (uint32_t)(cpu->esi + 0x2DCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0922u); lift_push32(cpu, r); sfera_sub_004AF350(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x28u, 0xFu);
    lift_store32(cpu->esp + 0x24u, 0u);
    lift_store8(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0945u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0x2DCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0950u); lift_push32(cpu, r); sfera_sub_004AF410(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) >= (uint32_t)(cpu->edi)) goto label_000B0963;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    label_000B0963: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0963u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B096Du); lift_push32(cpu, r); sfera_sub_004AED40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) < (uint32_t)(cpu->edi)) goto label_000B0980;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B097Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B0980: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0980u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000B0998: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0998u);
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFF572u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(5u)) goto label_000B0ADE;
    switch ((uint32_t)(cpu->edx)) {
        case 0u: goto label_000B09AE;
        case 1u: goto label_000B0A6C;
        case 2u: goto label_000B0ADE;
        case 3u: goto label_000B0A2E;
        case 4u: goto label_000B0A98;
        case 5u: goto label_000B0ABD;
        default: lift_trap(cpu, 0x4B09A7u, "resolved jump-table index out of range"); return;
    }
label_000B09AE: ;
    cpu->eax = lift_load32(cpu->esi + 0x2ECu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0A16;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000B09D4;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000B09C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B09C0u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x2DCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B09CBu); lift_push32(cpu, r); sfera_sub_004AF410(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x2ECu)) != (uint32_t)(1u)) goto label_000B09C0;
    label_000B09D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B09D4u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x2DCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B09DFu); lift_push32(cpu, r); sfera_sub_004AF350(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B09E9u); lift_push32(cpu, r); sfera_sub_00431460(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0x2DCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B09F4u); lift_push32(cpu, r); sfera_sub_004AF410(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x1Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 8u);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000B0A03;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    label_000B0A03: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0A03u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0A0Du); lift_push32(cpu, r); sfera_sub_004AED40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB0A16u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    label_000B0A16: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0A16u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000B0A2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0A2Eu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x2ECu)) == (uint32_t)(0u)) goto label_000B0A54;
    label_000B0A40: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0A40u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x2DCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0A4Bu); lift_push32(cpu, r); sfera_sub_004AF410(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x2ECu)) != (uint32_t)(0u)) goto label_000B0A40;
    label_000B0A54: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0A54u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000B0A6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0A6Cu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x34u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = cpu->edx & 0xFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0A80u); lift_push32(cpu, r); sfera_sub_004AED40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000B0A98: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0A98u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0AA5u); lift_push32(cpu, r); sfera_sub_004AECE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000B0ABD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0ABDu);
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0AC6u); lift_push32(cpu, r); sfera_sub_004B0270(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000B0ADE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0ADEu);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0AECu); lift_push32(cpu, r); sfera_sub_004D2DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B0B20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0B20u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000B0BAB;
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ebp)) goto label_000B0BAB;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0B4E;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0B4E;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B0B52;
    label_000B0B4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0B4Eu);
    cpu->edx = 0u;
    goto label_000B0B54;
    label_000B0B52: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0B52u);
    cpu->edx = lift_load32(cpu->eax);
    label_000B0B54: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0B54u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0B68;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0B68;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B0B6C;
    label_000B0B68: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0B68u);
    cpu->ecx = 0u;
    goto label_000B0B6E;
    label_000B0B6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0B6Cu);
    cpu->ecx = lift_load32(cpu->eax);
    label_000B0B6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0B6Eu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0B82;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0B82;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B0B86;
    label_000B0B82: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0B82u);
    cpu->eax = 0u;
    goto label_000B0B88;
    label_000B0B86: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0B86u);
    cpu->eax = lift_load32(cpu->eax);
    label_000B0B88: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0B88u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0B97u); lift_push32(cpu, r); sfera_sub_004AFC40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    cpu->esi += cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    label_000B0BAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0BABu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->edi, 0u);
    lift_store32(cpu->edi + 4u, 0u);
    lift_store32(cpu->edi + 8u, cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0BCD;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0BCD;
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->edi, cpu->eax);
    label_000B0BCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0BCDu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 36u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B0BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0BE0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x70u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->edi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0C19u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000B0C2C;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->esi);
    goto label_000B0C33;
    label_000B0C2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0C2Cu);
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    cpu->esi = cpu->eax;
    label_000B0C33: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0C33u);
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebp + 0x28u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B0E2C;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->ecx)) goto label_000B0D7C;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    label_000B0C58: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0C58u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0x28u))) goto label_000B0CAA;
    cpu->ecx = lift_load32(cpu->ebp + 0x14u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000B0C68;
    cpu->edx = 0u;
    goto label_000B0C6A;
    label_000B0C68: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0C68u);
    cpu->edx = lift_load32(cpu->ecx);
    label_000B0C6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0C6Au);
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000B0C73;
    cpu->eax -= cpu->ecx;
    label_000B0C73: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0C73u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0C81u); lift_push32(cpu, r); sfera_sub_004AF790(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    ++cpu->eax;
    lift_store32(cpu->ebp + 0x1Cu, cpu->eax);
    goto label_000B0C58;
    label_000B0CAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0CAAu);
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    cpu->esi -= cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0CC6u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0CCDu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0CD8u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0CEF;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0CEF;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B0CF3;
    label_000B0CEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0CEFu);
    cpu->ecx = 0u;
    goto label_000B0CF5;
    label_000B0CF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0CF3u);
    cpu->ecx = lift_load32(cpu->eax);
    label_000B0CF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0CF5u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0D0D;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0D0D;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B0D11;
    label_000B0D0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0D0Du);
    cpu->ecx = 0u;
    goto label_000B0D13;
    label_000B0D11: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0D11u);
    cpu->ecx = lift_load32(cpu->eax);
    label_000B0D13: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0D13u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D1Du); lift_push32(cpu, r); sfera_sub_004B00C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D3Au); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D41u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D48u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFB4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D5Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D64u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D74u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFA8u);
    goto label_000B0E27;
    label_000B0D7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0D7Cu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    label_000B0D83: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0D83u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0x28u))) goto label_000B0DD5;
    cpu->ecx = lift_load32(cpu->ebp + 0x14u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000B0D93;
    cpu->edx = 0u;
    goto label_000B0D95;
    label_000B0D93: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0D93u);
    cpu->edx = lift_load32(cpu->ecx);
    label_000B0D95: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0D95u);
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000B0D9E;
    cpu->eax -= cpu->ecx;
    label_000B0D9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0D9Eu);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0DACu); lift_push32(cpu, r); sfera_sub_004AF8A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    ++cpu->eax;
    lift_store32(cpu->ebp + 0x1Cu, cpu->eax);
    goto label_000B0D83;
    label_000B0DD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0DD5u);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0DECu); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0E01u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0E08u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFF90u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0E1Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0E24u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF84u);
    label_000B0E27: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0E27u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB0E2Cu); lift_push32(cpu, r); sfera_sub_004B0B20(cpu,r); if (cpu->eip != r) return; }
    label_000B0E2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0E2Cu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 40u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B0C8A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0C8Au);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000B0CA1;
    label_000B0C95: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0C95u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0C9Cu); lift_push32(cpu, r); sfera_sub_004AF510(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000B0C95;
    label_000B0CA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0CA1u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0CAAu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    cpu->esi -= cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0CC6u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0CCDu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0CD8u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0CEF;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0CEF;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B0CF3;
    label_000B0CEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0CEFu);
    cpu->ecx = 0u;
    goto label_000B0CF5;
    label_000B0CF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0CF3u);
    cpu->ecx = lift_load32(cpu->eax);
    label_000B0CF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0CF5u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0D0D;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B0D0D;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B0D11;
    label_000B0D0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0D0Du);
    cpu->ecx = 0u;
    goto label_000B0D13;
    label_000B0D11: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0D11u);
    cpu->ecx = lift_load32(cpu->eax);
    label_000B0D13: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0D13u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D1Du); lift_push32(cpu, r); sfera_sub_004B00C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D3Au); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D41u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D48u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFB4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D5Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D64u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0D74u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFA8u);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0E27u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0E2Cu); lift_push32(cpu, r); sfera_sub_004B0B20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 40u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B0DB5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0DB5u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000B0DCC;
    label_000B0DC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0DC0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0DC7u); lift_push32(cpu, r); sfera_sub_004AF410(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000B0DC0;
    label_000B0DCC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0DCCu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0DD5u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0DECu); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFF9Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0E01u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0E08u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFF90u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0E1Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0E24u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF84u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0E2Cu); lift_push32(cpu, r); sfera_sub_004B0B20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 40u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B0E40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0E40u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x10u, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000B0E6E;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000B0E6E;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_000B0E6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0E6Eu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000B0E9D;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000B0E9D;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_000B0E9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0E9Du);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x28u, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000B0ECC;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000B0ECC;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_000B0ECC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0ECCu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0ED8u); lift_push32(cpu, r); sfera_sub_004B0BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 36u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B0EE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0EE0u);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->esi)) goto label_000B109B;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebp)) goto label_000B0F11;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0F05u); lift_push32(cpu, r); sfera_sub_004AF470(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 4u, stop_address); return;
    label_000B0F11: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0F11u);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000B0FC7;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0F2Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0F3Eu); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->esp + 0x5Cu, cpu->esp);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0F4Fu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0F58u); lift_push32(cpu, r); sfera_sub_004AF990(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0F64u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->ebp);
    lift_store32(cpu->ecx + 4u, cpu->ebp);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ebp)) goto label_000B0F82;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ebp)) goto label_000B0F82;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_000B0F82: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0F82u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebp);
    lift_store32(cpu->eax + 4u, cpu->ebp);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000B0FA8;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000B0FA8;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000B0FA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0FA8u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0FBBu); lift_push32(cpu, r); sfera_sub_004AFE60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 4u, stop_address); return;
    label_000B0FC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B0FC7u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0FD9u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0FE0u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B0FF1u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    lift_store32(cpu->eax, cpu->ebp);
    lift_store32(cpu->eax + 4u, cpu->ebp);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ebp)) goto label_000B1011;
    cpu->ecx = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000B1011;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000B1011: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1011u);
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->esp + 0x5Cu, cpu->esp);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->eax + 8u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B1029u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B1032u); lift_push32(cpu, r); sfera_sub_004AF990(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B1043u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->esi = 0u;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->esi);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->esi)) goto label_000B1061;
    cpu->ebx = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->esi)) goto label_000B1061;
    cpu->ecx = lift_load32(cpu->ebx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000B1061: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1061u);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->eax + 8u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B1070u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->esi);
    lift_store32(cpu->ecx + 4u, cpu->esi);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x5Cu, cpu->esp);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000B108E;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000B108E;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_000B108E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B108Eu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB109Bu); lift_push32(cpu, r); sfera_sub_004B0E40(cpu,r); if (cpu->eip != r) return; }
    label_000B109B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B109Bu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B10B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B10B0u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B10BFu); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    lift_store32(cpu->esi + 0x19Cu, cpu->ecx);
    cpu->ecx = cpu->edi;
    cpu->eax = (uint32_t)(cpu->esi + 0x1A0u);
    cpu->ecx -= cpu->esi;
    cpu->ebp = 0x100u;
    label_000B10E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B10E6u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + cpu->eax)) & 0xFFu);
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B10E6;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x2A0u)) & 0xFFu);
    lift_store8(cpu->esi + 0x2A0u, cpu->eax & 0xFFu);
    cpu->ecx = lift_load32(cpu->edi + 0x2A4u);
    lift_store32(cpu->esi + 0x2A4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x2A8u);
    lift_store32(cpu->esi + 0x2A8u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x2ACu);
    lift_store32(cpu->esi + 0x2ACu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x2B0u);
    lift_store32(cpu->esi + 0x2B0u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x2B4u);
    lift_store32(cpu->esi + 0x2B4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x2B8u);
    lift_store32(cpu->esi + 0x2B8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x2BCu);
    lift_store32(cpu->esi + 0x2BCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x2C0u);
    lift_store32(cpu->esi + 0x2C0u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x2C4u);
    lift_store32(cpu->esi + 0x2C4u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x2C8u));
    lift_store_f32(cpu->esi + 0x2C8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x2CCu)) & 0xFFu);
    lift_store8(cpu->esi + 0x2CCu, cpu->ecx & 0xFFu);
    cpu->edx = lift_load32(cpu->edi + 0x2D0u);
    lift_store32(cpu->esi + 0x2D0u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x2D4u);
    lift_store32(cpu->esi + 0x2D4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x2D8u);
    cpu->edx = (uint32_t)(cpu->edi + 0x2DCu);
    lift_store32(cpu->esi + 0x2D8u, cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x2DCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B11B5u); lift_push32(cpu, r); sfera_sub_004B0EE0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x2F4u);
    lift_store32(cpu->esi + 0x2F4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x2F8u);
    lift_store32(cpu->esi + 0x2F8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x2FCu);
    lift_store32(cpu->esi + 0x2FCu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x300u);
    lift_store32(cpu->esi + 0x300u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x304u);
    lift_store32(cpu->esi + 0x304u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x308u)) & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 0x308u, cpu->edx & 0xFFu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B1210(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1210u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x12Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B1244u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x310u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B124Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B126C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B1268u); lift_push32(cpu, r); sfera_sub_004B0100(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000B126E;
    label_000B126C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B126Cu);
    cpu->esi = 0u;
    label_000B126E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B126Eu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B127Eu); lift_push32(cpu, r); sfera_sub_004B10B0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x2D8u)) == (uint32_t)(0u)) goto label_000B12A6;
    cpu->ecx = lift_load32(cpu->edi + 0x2D8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1298u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x2D8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB12A6u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000B12A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B12A6u);
    cpu->edx = 0x13Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B12B5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B12BFu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B12DB;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B12D9u); lift_push32(cpu, r); sfera_sub_004CFE70(cpu,r); if (cpu->eip != r) return; }
    goto label_000B12DD;
    label_000B12DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B12DBu);
    cpu->eax = 0u;
    label_000B12DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B12DDu);
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B1340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1340u);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = (uint32_t)(cpu->ecx + 0x48u);
    if ((uint32_t)(lift_load32(cpu->edx)) != (uint32_t)(cpu->eax)) goto label_000B1360;
    cpu->eax = lift_load32(cpu->ecx + 0x40u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x3Cu);
    lift_store32(cpu->edx, cpu->esi);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    lift_store32(cpu->edx, cpu->eax);
    cpu->ecx = lift_load32(cpu->ecx + 0x30u);
    cpu->eax -= cpu->eax;
    lift_store32(cpu->ecx, cpu->eax);
    cpu->esi = lift_pop32(cpu);
    label_000B1360: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1360u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B1370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1370u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) != (uint8_t)(0u)) goto label_000B13BA;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x11u)) != (uint8_t)(0u)) goto label_000B139D;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) != (uint8_t)(0u)) goto label_000B139A;
    label_000B1390: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1390u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) == (uint8_t)(0u)) goto label_000B1390;
    label_000B139A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B139Au);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_000B139D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B139Du);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) != (uint8_t)(0u)) goto label_000B13B8;
    label_000B13A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B13A6u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_000B13B8;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) == (uint8_t)(0u)) goto label_000B13A6;
    label_000B13B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B13B8u);
    lift_store32(cpu->eax, cpu->edx);
    label_000B13BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B13BAu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B14F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B14F0u);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esi + 0x25Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B1514u); lift_push32(cpu, r); sfera_sub_004D8990(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    cpu->edx = 0u;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B1537;
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B1532u); lift_push32(cpu, r); sfera_sub_004A8A30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    label_000B1537: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1537u);
    cpu->eax += lift_load32(cpu->edi + 0x34u);
    lift_x87_push(cpu, 0.0);
    cpu->edx += lift_load32(cpu->edi + 0x30u);
    lift_store32(cpu->esi + 0x278u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x278u);
    cpu->ecx += lift_load32(cpu->esi + 0x34u);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esi + 0x274u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B15A3u); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B1830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1830u);
    const uint32_t filebuf = cpu->ecx;
    const auto* path = reinterpret_cast<const char*>(static_cast<uintptr_t>(lift_load32(cpu->esp + 4u)));
    const uint32_t open_mode = lift_load32(cpu->esp + 8u);
    if (sfera_filebuf_file(filebuf) != nullptr) { cpu->eax = 0u; LIFT_RET(12u); }
    FILE* file = std::fopen(path, sfera_filebuf_open_mode(open_mode));
    if (file != nullptr && (open_mode & 4u) != 0u && std::fseek(file, 0, SEEK_END) != 0) { std::fclose(file); file = nullptr; }
    if (file == nullptr) { cpu->eax = 0u; LIFT_RET(12u); }
    lift_store8(filebuf + 0x50u, 1u);
    lift_store8(filebuf + 0x49u, 0u);
    lift_store32(filebuf + 0x54u, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(file)));
    lift_store32(filebuf + 0x4Cu, g_sfera_recovered_static_runtime.ui_counter_a);
    lift_store32(filebuf + 0x44u, 0u);
    lift_store32(filebuf + 0x10u, 0u);
    lift_store32(filebuf + 0x14u, 0u);
    lift_store32(filebuf + 0x20u, 0u);
    lift_store32(filebuf + 0x24u, 0u);
    lift_store32(filebuf + 0x30u, 0u);
    lift_store32(filebuf + 0x34u, 0u);
    cpu->eax = filebuf;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B19D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B19D0u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->edx + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->esi + 0x11u)) != (uint8_t)(0u)) goto label_000B19E8;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_000B19E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B19E8u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_000B1A02;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_000B1A02: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1A02u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx))) goto label_000B1A13;
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_000B1A13: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1A13u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B1A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1A20u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edx, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x11u)) != (uint8_t)(0u)) goto label_000B1A38;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_000B1A38: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1A38u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_000B1A53;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_000B1A53: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1A53u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_000B1A67;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_000B1A67: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1A67u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B1A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1A80u);
    const uint32_t stream = cpu->ecx;
    const uint32_t string = cpu->edx;
    const uint32_t size = lift_load32(string + 0x10u);
    const uint32_t data = lift_load32(string + 0x14u) >= 0x10u ? lift_load32(string) : string;
    sfera_filebuf_write_bytes(cpu, stream + 4u, data, size);
    if (cpu->eip != LIFT_CALLBACK_SENTINEL) { return; }
    if (cpu->eax != size) { LIFT_LOGIC(lift_load32(stream + 0x6Cu), 4u, |, 32u, lift_store32(stream + 0x6Cu, result);); }
    cpu->eax = stream;
    lift_return(cpu, 0u, stop_address); return;
}


LIFT_ENTRY void LIFT_CDECL sfera_sub_004B1CB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1CB0u);
    const uint32_t stream = cpu->ecx;
    const uint32_t data = cpu->edx;
    uint32_t size = 0u;
    while (lift_load8(data + size) != 0u) { ++size; }
    sfera_filebuf_write_bytes(cpu, stream + 4u, data, size);
    if (cpu->eip != LIFT_CALLBACK_SENTINEL) { return; }
    if (cpu->eax != size) { LIFT_LOGIC(lift_load32(stream + 0x6Cu), 4u, |, 32u, lift_store32(stream + 0x6Cu, result);); }
    cpu->eax = stream;
    lift_return(cpu, 0u, stop_address); return;
}


LIFT_ENTRY void LIFT_CDECL sfera_sub_004B1F00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1F00u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1FEB;
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) <= (uint32_t)(0u)) goto label_000B1FEB;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x18u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B1F77;
    cpu->edi = 0u;
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B1F62;
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    label_000B1F32: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1F32u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000B1F3C;
    cpu->eax = lift_load32(cpu->esi);
    goto label_000B1F3E;
    label_000B1F3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1F3Cu);
    cpu->eax = cpu->esi;
    label_000B1F3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1F3Eu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->ebx)) & 0xFFu);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B1F52u); lift_push32(cpu, r); sfera_sub_004A53E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi += lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->edi) > (uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_000B1F6D;
    ++cpu->ebx;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000B1F32;
    label_000B1F62: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1F62u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_000B1F6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1F6Du);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_000B1F77: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1F77u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000B1F81;
    cpu->ecx = lift_load32(cpu->esi);
    goto label_000B1F83;
    label_000B1F81: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1F81u);
    cpu->ecx = cpu->esi;
    label_000B1F83: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1F83u);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B1F98u); lift_push32(cpu, r); sfera_sub_004A5270(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) <= (uint32_t)(cpu->eax)) goto label_000B1FE1;
    cpu->edi = lift_load32(cpu->esi + 0x10u);
    cpu->ebx = 0u;
    label_000B1FA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1FA7u);
    --cpu->edi;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000B1FE1;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000B1FB7;
    cpu->eax = lift_load32(cpu->esi);
    goto label_000B1FB9;
    label_000B1FB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1FB7u);
    cpu->eax = cpu->esi;
    label_000B1FB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1FB9u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edi)) & 0xFFu);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B1FCDu); lift_push32(cpu, r); sfera_sub_004A53E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx += lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_000B1FA7;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_000B1FE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1FE1u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_000B1FEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B1FEBu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B2000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2000u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B2019;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xB2019u);
    label_000B2019: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2019u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B202Bu); lift_push32(cpu, r); sfera_sub_004B1370(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x11u)) == (uint8_t)(0u)) goto label_000B2038;
    cpu->edi = lift_load32(cpu->ebx + 8u);
    goto label_000B2050;
    label_000B2038: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2038u);
    cpu->eax = lift_load32(cpu->ebx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) == (uint8_t)(0u)) goto label_000B2045;
    cpu->edi = cpu->ecx;
    goto label_000B2050;
    label_000B2045: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2045u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_000B20B7;
    label_000B2050: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2050u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->ebx + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B205C;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_000B205C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B205Cu);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(cpu->ebx)) goto label_000B2069;
    lift_store32(cpu->eax + 4u, cpu->edi);
    goto label_000B2074;
    label_000B2069: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2069u);
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(cpu->ebx)) goto label_000B2071;
    lift_store32(cpu->esi, cpu->edi);
    goto label_000B2074;
    label_000B2071: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2071u);
    lift_store32(cpu->esi + 8u, cpu->edi);
    label_000B2074: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2074u);
    cpu->ebx = lift_load32(cpu->ebp + 4u);
    cpu->ecx = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_000B2092;
    if ((uint8_t)(lift_load8(cpu->edi + 0x11u)) == (uint8_t)(0u)) goto label_000B2089;
    cpu->eax = cpu->esi;
    goto label_000B2090;
    label_000B2089: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2089u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB2090u); lift_push32(cpu, r); sfera_sub_004D1C30(cpu,r); if (cpu->eip != r) return; }
    label_000B2090: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2090u);
    lift_store32(cpu->ebx, cpu->eax);
    label_000B2092: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2092u);
    cpu->ebx = lift_load32(cpu->ebp + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) != (uint32_t)(cpu->edx)) goto label_000B210E;
    if ((uint8_t)(lift_load8(cpu->edi + 0x11u)) == (uint8_t)(0u)) goto label_000B20AB;
    cpu->eax = cpu->esi;
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_000B210E;
    label_000B20AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B20ABu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B20B2u); lift_push32(cpu, r); sfera_sub_00402100(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_000B210E;
    label_000B20B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B20B7u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ebx + 8u))) goto label_000B20C7;
    cpu->esi = cpu->eax;
    goto label_000B20E1;
    label_000B20C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B20C7u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B20D3;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_000B20D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B20D3u);
    lift_store32(cpu->esi, cpu->edi);
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebx + 8u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    label_000B20E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B20E1u);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(cpu->ebx)) goto label_000B20EE;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_000B20FC;
    label_000B20EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B20EEu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->ebx)) goto label_000B20F9;
    lift_store32(cpu->ecx, cpu->eax);
    goto label_000B20FC;
    label_000B20F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B20F9u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_000B20FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B20FCu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + 0x10u)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x10u)) & 0xFFu);
    lift_store8(cpu->eax + 0x10u, cpu->edx & 0xFFu);
    lift_store8(cpu->ebx + 0x10u, cpu->ecx & 0xFFu);
    label_000B210E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B210Eu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x10u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B2216;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_000B2213;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000B2130: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2130u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x10u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B2213;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_000B21A2;
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x10u)) != (uint8_t)(0u)) goto label_000B215A;
    lift_store8(cpu->eax + 0x10u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esi + 0x10u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B2157u); lift_push32(cpu, r); sfera_sub_004B19D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    label_000B215A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B215Au);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) != (uint8_t)(0u)) goto label_000B21D2;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x10u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B216F;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x10u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B21CE;
    label_000B216F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B216Fu);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x10u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B2189;
    lift_store8(cpu->edx + 0x10u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->eax + 0x10u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B2186u); lift_push32(cpu, r); sfera_sub_004B1A20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    label_000B2189: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2189u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x10u)) & 0xFFu);
    lift_store8(cpu->eax + 0x10u, cpu->ecx & 0xFFu);
    lift_store8(cpu->esi + 0x10u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->edx + 0x10u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B21A0u); lift_push32(cpu, r); sfera_sub_004B19D0(cpu,r); if (cpu->eip != r) return; }
    goto label_000B2213;
    label_000B21A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B21A2u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x10u)) != (uint8_t)(0u)) goto label_000B21B9;
    lift_store8(cpu->eax + 0x10u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esi + 0x10u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B21B7u); lift_push32(cpu, r); sfera_sub_004B1A20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    label_000B21B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B21B9u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) != (uint8_t)(0u)) goto label_000B21D2;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x10u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B21E5;
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x10u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B21E5;
    label_000B21CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B21CEu);
    lift_store8(cpu->eax + 0x10u, 0u);
    label_000B21D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B21D2u);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->edx + 4u))) goto label_000B2130;
    goto label_000B2213;
    label_000B21E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B21E5u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x10u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B21FD;
    lift_store8(cpu->edx + 0x10u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->eax + 0x10u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B21FBu); lift_push32(cpu, r); sfera_sub_004B19D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    label_000B21FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B21FDu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x10u)) & 0xFFu);
    lift_store8(cpu->eax + 0x10u, cpu->ecx & 0xFFu);
    lift_store8(cpu->esi + 0x10u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->edx + 0x10u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB2213u); lift_push32(cpu, r); sfera_sub_004B1A20(cpu,r); if (cpu->eip != r) return; }
    label_000B2213: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2213u);
    lift_store8(cpu->edi + 0x10u, cpu->ebx & 0xFFu);
    label_000B2216: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2216u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B2220u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B2231;
    --cpu->eax;
    lift_store32(cpu->ebp + 8u, cpu->eax);
    label_000B2231: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2231u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B2240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2240u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = cpu->ecx;
    cpu->esi = cpu->edi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B226F;
    label_000B2251: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2251u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B225Cu); lift_push32(cpu, r); sfera_sub_004B2240(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B2264u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B2251;
    label_000B226F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B226Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B2280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2280u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_000B2314;
    cpu->eax = lift_load32(cpu->edx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->edx + 0x10u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    goto label_000B22B4;
    label_000B22B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B22B0u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_000B22B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B22B4u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edi)) goto label_000B22BF;
    cpu->eax -= cpu->ecx;
    label_000B22BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B22BFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B22CE;
    cpu->edx = lift_load32(cpu->edx);
    label_000B22CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B22CEu);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_000B22D7;
    label_000B22D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B22D7u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_000B22DF;
    cpu->ecx = cpu->ebx;
    label_000B22DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B22DFu);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000B22E7;
    cpu->eax = lift_load32(cpu->eax);
    label_000B22E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B22E7u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B22EFu); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B2303;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_000B2303;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B230E;
    label_000B2303: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2303u);
    ++cpu->edi;
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esp + 0x2Cu))) goto label_000B22B0;
    label_000B230E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B230Eu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000B2314: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2314u);
    lift_store32(cpu->eax + 4u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B2330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2330u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000B2348;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xB2348u);
    label_000B2348: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2348u);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0xFFFFFFFEu)) goto label_000B2358;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xB2358u);
    label_000B2358: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2358u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_000B2382;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B2369u); lift_push32(cpu, r); sfera_sub_00403230(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == 0u) goto label_000B23E6;
    label_000B236D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B236Du);
    if ((uint32_t)(cpu->edi) != (uint32_t)(1u)) goto label_000B23AE;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000B23A4;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x10u)) & 0xFFu);
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    goto label_000B23CA;
    label_000B2382: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2382u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000B236D;
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_000B239A;
    cpu->eax = lift_load32(cpu->esi);
    lift_store8(cpu->eax, 0u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000B239A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B239Au);
    cpu->eax = cpu->esi;
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000B23A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B23A4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x10u)) & 0xFFu);
    cpu->eax = cpu->esi;
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    goto label_000B23CA;
    label_000B23AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B23AEu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000B23B8;
    cpu->eax = lift_load32(cpu->esi);
    goto label_000B23BA;
    label_000B23B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B23B8u);
    cpu->eax = cpu->esi;
    label_000B23BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B23BAu);
    cpu->edx = (int8_t)(lift_load8(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4B23C2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B23C7u);
    cpu->esp += 0xCu;
    label_000B23CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B23CAu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B23E0;
    cpu->eax = lift_load32(cpu->esi);
    lift_store8(cpu->eax + cpu->edi, 0u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000B23E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B23E0u);
    cpu->eax = cpu->esi;
    lift_store8(cpu->eax + cpu->edi, 0u);
    label_000B23E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B23E6u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B23F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B23F0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B2407u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B240Eu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B2416;
    cpu->ecx = lift_load32(cpu->ecx);
    label_000B2416: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2416u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000B242E;
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->eax -= cpu->edx;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
    label_000B242E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B242Eu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B2440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2440u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B246A;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edi);
    label_000B2455: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2455u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu)) >= (int32_t)(uint32_t)(cpu->esi)) goto label_000B245F;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_000B2463;
    label_000B245F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B245Fu);
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_000B2463: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2463u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) == (uint8_t)(0u)) goto label_000B2455;
    cpu->esi = lift_pop32(cpu);
    label_000B246A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B246Au);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->eax)) goto label_000B248D;
    cpu->ecx = lift_load32(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->edx + 0xCu))) goto label_000B248D;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000B248D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B248Du);
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B24B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B24B0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B24E1;
    label_000B24C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B24C3u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B24CEu); lift_push32(cpu, r); sfera_sub_004B2240(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B24D6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B24C3;
    label_000B24E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B24E1u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    lift_store32(cpu->edi + 8u, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B2500(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2500u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->ebx);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B2587;
    cpu->ecx = (uint32_t)(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B254Au); lift_push32(cpu, r); sfera_sub_004D23B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x10u)) & 0xFFu);
    lift_store8(cpu->esi + 0x10u, cpu->eax & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x11u)) == (uint8_t)(0u)) goto label_000B2564;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->esi);
    label_000B2564: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2564u);
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B2576u); lift_push32(cpu, r); sfera_sub_004B2500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B2584u); lift_push32(cpu, r); sfera_sub_004B2500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_000B2587: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2587u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B259E(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B259Eu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B25AAu); lift_push32(cpu, r); sfera_sub_004B2240(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B25B3u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4B25B3u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B25C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B25C0u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B25DA;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B25DA;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B25DE;
    label_000B25DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B25DAu);
    cpu->ecx = 0u;
    goto label_000B25E0;
    label_000B25DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B25DEu);
    cpu->ecx = lift_load32(cpu->eax);
    label_000B25E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B25E0u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B25FA;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B25FA;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B25FE;
    label_000B25FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B25FAu);
    cpu->ecx = 0u;
    goto label_000B2600;
    label_000B25FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B25FEu);
    cpu->ecx = lift_load32(cpu->eax);
    label_000B2600: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2600u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B260Fu); lift_push32(cpu, r); sfera_sub_004B2280(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B2640;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B2640;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->esi, cpu->edx);
    label_000B2640: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2640u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B2650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2650u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B2675u); lift_push32(cpu, r); sfera_sub_004B2330(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B2680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2680u);
    const uint32_t ch = lift_load32(cpu->esp + 4u);
    if (ch == UINT32_MAX) { cpu->eax = 0u; LIFT_RET(4u); }
    FILE* file = sfera_filebuf_file(cpu->ecx);
    cpu->eax = file != nullptr && std::fputc(static_cast<unsigned char>(ch), file) != EOF ? ch : UINT32_MAX;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B2AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2AD0u);
    cpu->eax = 1u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B2C40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2C40u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_000B2C6E;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_000B2C6E;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B2C5Eu); lift_push32(cpu, r); sfera_sub_004B24B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000B2C6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2C6Eu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000B2CDF;
    label_000B2C72: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2C72u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B2CC8;
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) != (uint8_t)(0u)) goto label_000B2CA0;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) != (uint8_t)(0u)) goto label_000B2C9A;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000B2C90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2C90u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) == (uint8_t)(0u)) goto label_000B2C90;
    label_000B2C9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2C9Au);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_000B2CC8;
    label_000B2CA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2CA0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) != (uint8_t)(0u)) goto label_000B2CC4;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000B2CB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2CB0u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000B2CC4;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) == (uint8_t)(0u)) goto label_000B2CB0;
    label_000B2CC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2CC4u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000B2CC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2CC8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B2CD5u); lift_push32(cpu, r); sfera_sub_004B2000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000B2C72;
    label_000B2CDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2CDFu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B2CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2CF0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B2D09u); lift_push32(cpu, r); sfera_sub_004B2500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->eax = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) != (uint8_t)(0u)) goto label_000B2D55;
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x11u)) != (uint8_t)(0u)) goto label_000B2D30;
    label_000B2D26: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2D26u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x11u)) == (uint8_t)(0u)) goto label_000B2D26;
    label_000B2D30: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2D30u);
    lift_store32(cpu->edx, cpu->eax);
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) != (uint8_t)(0u)) goto label_000B2D4C;
    label_000B2D41: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2D41u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) == (uint8_t)(0u)) goto label_000B2D41;
    label_000B2D4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2D4Cu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000B2D55: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2D55u);
    lift_store32(cpu->edx, cpu->edx);
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 8u, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B2D70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2D70u);
    const uint32_t stream = cpu->ecx;
    const uint32_t destination = cpu->edx;
    const uint32_t delimiter = lift_load32(cpu->esp + 4u) & 0xFFu;
    const uint32_t filebuf = stream + 0x10u;
    uint32_t state = 0u;
    bool extracted = false;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = destination;
    { uint32_t r=LIFT_CALLBACK_SENTINEL; lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    if (cpu->eip != LIFT_CALLBACK_SENTINEL) { return; }
    FILE* file = sfera_filebuf_file(filebuf);
    if (file == nullptr || (lift_load32(stream + 0x74u) & 6u) != 0u) {
        state |= 2u;
    } else {
        for (;;) {
            const int value = std::fgetc(file);
            if (value == EOF) { state |= 1u; break; }
            const uint32_t character = static_cast<uint32_t>(static_cast<unsigned char>(value));
            if (character == delimiter) { extracted = true; break; }
            if (lift_load32(destination + 0x10u) >= 0xFFFFFFFEu) { state |= 2u; break; }
            lift_push32(cpu, character); lift_push32(cpu, 1u);
            cpu->ecx = destination;
            { uint32_t r=LIFT_CALLBACK_SENTINEL; lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
            if (cpu->eip != LIFT_CALLBACK_SENTINEL) { return; }
            extracted = true;
        }
    }
    if (!extracted) { state |= 2u; }
    if (state != 0u) { lift_store32(stream + 0x74u, lift_load32(stream + 0x74u) | state); }
    cpu->eax = stream;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B30C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B30C0u);
    const uint32_t filebuf = cpu->ecx;
    cpu->eax = sfera_filebuf_close_native(filebuf) ? filebuf : 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B3110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3110u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x210u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B31AA;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3135u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3145u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000B31A9;
    lift_push32(cpu, cpu->edi);
    (void)cpu;
    label_000B3150: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3150u);
    cpu->edx = 0x273u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextEditControl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B315Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B316B;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    goto label_000B316D;
    label_000B316B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B316Bu);
    cpu->edx = lift_load32(cpu->eax);
    label_000B316D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B316Du);
    cpu->edi = lift_load32(cpu->edx + 8u);
    cpu->eax = cpu->esi;
    cpu->ecx = cpu->esi;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->eax)) goto label_000B3180;
    cpu->eax -= cpu->edi;
    label_000B3180: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3180u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B318Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x200u);
    ++cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B31A3u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000B3150;
    cpu->edi = lift_pop32(cpu);
    label_000B31A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B31A9u);
    cpu->ebx = lift_pop32(cpu);
    label_000B31AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B31AAu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B31B5u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->ebp + 0x1C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B31C8u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->ebp + 0x1E4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B31D9u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x254u, cpu->esi);
    lift_store32(cpu->ebp + 0x258u, cpu->esi);
    lift_store32(cpu->ebp + 0x21Cu, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B3200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3200u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x6Cu);
    cpu->esi = lift_load32(cpu->esp + 0x74u);
    cpu->ebp = lift_load32(cpu->esp + 0x70u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000B3253;
    cpu->eax -= lift_load32(cpu->esi);
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    goto label_000B3256;
    label_000B3253: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3253u);
    cpu->ebx |= 0xFFFFFFFFu;
    label_000B3256: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3256u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3262u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x70u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B327Au); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0x10u;
    lift_store8(cpu->esp + 0x64u, 2u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) < (uint32_t)(cpu->ebx)) goto label_000B3297;
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3294u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B3297: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3297u);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x50u, 0xFu);
    lift_store32(cpu->esp + 0x4Cu, 0u);
    lift_store8(cpu->esp + 0x3Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B32B3u); lift_push32(cpu, r); sfera_sub_00431210(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000B32C0;
    cpu->esi = lift_load32(cpu->edi + 0x244u);
    goto label_000B32D3;
    label_000B32C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B32C0u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_000B32CD;
    cpu->esi = lift_load32(cpu->edi + 0x240u);
    goto label_000B32D3;
    label_000B32CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B32CDu);
    cpu->esi = lift_load32(cpu->edi + 0x248u);
    label_000B32D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B32D3u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) >= (uint32_t)(cpu->ebx)) goto label_000B32E1;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    label_000B32E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B32E1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->edi + 0x8Cu);
    cpu->edx -= 2u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B32FAu); lift_push32(cpu, r); sfera_sub_004A5270(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B330Bu); lift_push32(cpu, r); sfera_sub_00431220(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) >= (uint32_t)(cpu->ebx)) goto label_000B3319;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    label_000B3319: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3319u);
    cpu->edx = lift_load32(cpu->edi + 0xDCu);
    cpu->ecx = lift_load8(cpu->edi + 0x8Cu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    { uint64_t l=cpu->esp, r=(uint64_t)(8u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(0x18u), 32u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 4u)))));
    cpu->esi &= 0xFFFFFFu;
    cpu->edx |= cpu->esi;
    cpu->ecx -= 2u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B334Fu); lift_push32(cpu, r); sfera_sub_004A4E10(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(cpu->ebx)) goto label_000B3362;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B335Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B3362: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3362u);
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B3390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3390u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x50u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x74u);
    cpu->edi = lift_load32(cpu->esp + 0x80u);
    cpu->ebp = lift_load32(cpu->esp + 0x78u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000B33E6;
    cpu->eax -= lift_load32(cpu->edi);
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    goto label_000B33E9;
    label_000B33E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B33E6u);
    cpu->ebx |= 0xFFFFFFFFu;
    label_000B33E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B33E9u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B33F5u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x78u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B340Du); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0x10u;
    cpu->ebx = 2u;
    lift_store8(cpu->esp + 0x6Cu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x58u)) < (uint32_t)(cpu->edi)) goto label_000B342E;
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B342Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B342E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B342Eu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_store32(cpu->esp + 0x60u, 0xFu);
    lift_store32(cpu->esp + 0x5Cu, 0u);
    lift_store8(cpu->esp + 0x4Cu, 0u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B345Cu); lift_push32(cpu, r); sfera_sub_004B2440(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edx) == (uint32_t)(lift_load32(cpu->esi + 0x1BCu))) goto label_000B3476;
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, 0x2Au); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB3476u); lift_push32(cpu, r); sfera_sub_004B2330(cpu,r); if (cpu->eip != r) return; }
    label_000B3476: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3476u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x3Cu)) >= (uint32_t)(cpu->edi)) goto label_000B3484;
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    label_000B3484: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3484u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->edx -= cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B349Cu); lift_push32(cpu, r); sfera_sub_004A5270(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B34ADu); lift_push32(cpu, r); sfera_sub_00431220(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x3Cu)) >= (uint32_t)(cpu->edi)) goto label_000B34BB;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    label_000B34BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B34BBu);
    cpu->edx = lift_load32(cpu->esi + 0xDCu);
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x84u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(0x18u), 32u);
    cpu->edx |= cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    cpu->ecx -= cpu->ebx;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 4u)))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B34F6u); lift_push32(cpu, r); sfera_sub_004A4E10(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x3Cu)) < (uint32_t)(cpu->edi)) goto label_000B3509;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3506u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B3509: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3509u);
    cpu->ecx = lift_load32(cpu->esp + 0x64u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x5Cu;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B3530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3530u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x218u)) == (uint32_t)(0u)) goto label_000B3737;
    cpu->ecx = lift_load32(cpu->esi + 0x254u);
    cpu->eax = lift_load32(cpu->esi + 0x21Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000B35E4;
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3594u); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0x10u;
    lift_store32(cpu->esp + 0x4Cu, 0u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->edi)) goto label_000B35A8;
    cpu->eax = lift_load32(cpu->eax);
    label_000B35A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B35A8u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    cpu->edx -= 2u;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B35C3u); lift_push32(cpu, r); sfera_sub_004A5270(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x4Cu, 0xFFFFFFFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x38u)) < (uint32_t)(cpu->edi)) goto label_000B35DE;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B35DBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B35DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B35DEu);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    goto label_000B35E6;
    label_000B35E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B35E4u);
    cpu->ebx = 0u;
    label_000B35E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B35E6u);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    cpu->edx = 0u;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B3609;
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3604u); lift_push32(cpu, r); sfera_sub_004A8A30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    label_000B3609: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3609u);
    cpu->eax += lift_load32(cpu->edi + 0x34u);
    cpu->edx += lift_load32(cpu->edi + 0x30u);
    lift_store32(cpu->esi + 0x278u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += cpu->edx;
    cpu->ebx += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x218u);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    lift_store32(cpu->esi + 0x274u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B369C;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B3737;
    cpu->edx = lift_load32(cpu->esi + 0x238u);
    cpu->ecx = lift_load32(cpu->esi + 0xDCu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x278u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x22Cu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    cpu->eax += lift_load32(cpu->esi + 0x34u);
    cpu->edx &= 0xFFFFFFu;
    cpu->edx |= cpu->ecx;
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x228u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"_");
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    cpu->esp -= 8u;
    cpu->ecx -= 2u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000B368F;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000B368F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B368Fu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3697u); lift_push32(cpu, r); sfera_sub_004A4E10(cpu,r); if (cpu->eip != r) return; }
    goto label_000B3737;
    label_000B369C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B369Cu);
    cpu->edi = lift_load32(cpu->esi + 0x228u);
    cpu->ecx = lift_load32(cpu->esi + 0x238u);
    cpu->edx = lift_load32(cpu->esi + 0x34u);
    cpu->eax = lift_load32(cpu->esi + 0x278u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->ebx = lift_load32(cpu->esi + 0xDCu);
    cpu->ebx = lift_shift_left(cpu, cpu->ebx, (uint32_t)(0x18u), 32u);
    cpu->ecx &= 0xFFFFFFu;
    cpu->ecx |= cpu->ebx;
    cpu->ebx = lift_load32(cpu->esi + 0x2Cu);
    cpu->ebx -= lift_load32(cpu->esi + 0x234u);
    cpu->ebx += cpu->edx;
    cpu->ebx = (uint32_t)(cpu->ebx + cpu->eax + 0xFFFFFFFEu);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000B36E5;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000B36E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B36E5u);
    cpu->ebx = (uint32_t)(cpu->edi + 1u);
    cpu->esp -= 0x10u;
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000B3701;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000B3701: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3701u);
    cpu->esi = lift_load32(cpu->esi + 0x22Cu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi += cpu->edx;
    cpu->edx = (uint32_t)(cpu->esi + cpu->eax + 2u);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000B372F;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000B372F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B372Fu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB3737u); lift_push32(cpu, r); sfera_sub_004CEB70(cpu,r); if (cpu->eip != r) return; }
    label_000B3737: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3737u);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B3760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3760u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x258u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B37ABu); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx -= lift_load32(cpu->esi + 0x230u);
    cpu->eax = lift_load8(cpu->esi + 0x8Cu);
    cpu->edx -= lift_load32(cpu->esi + 0x228u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->eax -= 2u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x40u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B37DCu); lift_push32(cpu, r); sfera_sub_004B1F00(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B37E1;
    ++cpu->eax;
    label_000B37E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B37E1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x1Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x254u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B37FB;
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B37F8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B37FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B37FBu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B3820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3820u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x254u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B386Au); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx -= lift_load32(cpu->esi + 0x230u);
    cpu->eax = lift_load8(cpu->esi + 0x8Cu);
    cpu->edx -= lift_load32(cpu->esi + 0x228u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    cpu->eax -= 2u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x40u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B389Bu); lift_push32(cpu, r); sfera_sub_004B1F00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esi + 0x254u);
    lift_store32(cpu->esi + 0x258u, cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000B38BB;
    cpu->edx = (uint32_t)(cpu->ecx + cpu->edx + 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x258u, cpu->edx);
    goto label_000B38C3;
    label_000B38BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B38BBu);
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esi + 0x258u, cpu->ecx);
    label_000B38C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B38C3u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) < (uint32_t)(0x10u)) goto label_000B38D7;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B38D4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B38D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B38D7u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B3900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3900u);
    const uint32_t stream = cpu->ecx;
    const uint32_t filebuf = stream + 0x10u;
    const bool success = sfera_filebuf_close_native(filebuf);
    if (!success) { LIFT_STORE32(stream + 0x74u, lift_load32(stream + 0x74u) | 2u); }
    cpu->eax = success ? filebuf : 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B3970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3970u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) == (uint32_t)(cpu->ebx)) goto label_000B39CB;
    lift_store32(cpu->edi + 0x6Cu, 0u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, 1u);
    label_000B39CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B39CBu);
    cpu->esi = (uint32_t)(cpu->edi + 4u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x20u, 1u);
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x20u, 2u);
    lift_store8(cpu->esi + 0x50u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esi + 0x49u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x54u, cpu->ebx);
    cpu->ecx = g_sfera_recovered_static_runtime.ui_counter_a;
    lift_store32(cpu->esi + 0x4Cu, cpu->ecx);
    lift_store32(cpu->esi + 0x44u, cpu->ebx);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B3A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3A40u);
    const uint32_t filebuf = cpu->ecx + 4u;
    if (sfera_filebuf_file(filebuf) != nullptr) { (void)sfera_filebuf_close_native(filebuf); }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B3B00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3B00u);
    const uint32_t stream = cpu->ecx;
    const uint32_t filebuf = stream + 4u;
    const bool success = sfera_filebuf_close_native(filebuf);
    if (!success) { LIFT_STORE32(stream + 0x6Cu, lift_load32(stream + 0x6Cu) | 2u); }
    cpu->eax = success ? filebuf : 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B3C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3C10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x10u, 0u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->edi = lift_load32(cpu->esi + 0x10u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->eax)) goto label_000B3C96;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(cpu->eax)) goto label_000B3C96;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3C7Fu); lift_push32(cpu, r); sfera_sub_00403CA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B3C96;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B3C90;
    cpu->eax = lift_load32(cpu->esi);
    goto label_000B3C92;
    label_000B3C90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3C90u);
    cpu->eax = cpu->esi;
    label_000B3C92: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3C92u);
    lift_store8(cpu->eax + cpu->edi, 0u);
    label_000B3C96: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3C96u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3CA2u); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3CB0u); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B3D40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3D40u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x5Cu)) & 0xFFu);
    cpu->esi = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ebx = 0u;
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    cpu->edi = lift_load32(cpu->esi + 0x1BCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_store8(cpu->esp + 0x20u, cpu->eax & 0xFFu);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3DA1u); lift_push32(cpu, r); sfera_sub_004B2440(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(cpu->edi)) goto label_000B3F31;
    cpu->eax = lift_load32(cpu->esi + 0x1D8u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->esi + 0x24Cu))) goto label_000B3F31;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_store32(cpu->esp + 0x1Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3DD8u); lift_push32(cpu, r); sfera_sub_004B2440(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(cpu->edi)) goto label_000B3DF3;
    cpu->edx = (int8_t)(lift_load8(cpu->esp + 0x18u));
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::isdigit), LIFT_CODE_TOKEN_VA(0x4B3DE2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3DE8u);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B3F31;
    label_000B3DF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3DF3u);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x21Cu);
    cpu->edx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3E0Eu); lift_push32(cpu, r); sfera_sub_0048E950(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B3E7A;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x18u)) & 0xFFu);
    lift_store32(cpu->esp + 0x40u, 0xFu);
    lift_store8(cpu->esp + 0x2Cu, cpu->edx & 0xFFu);
    lift_store32(cpu->esp + 0x3Cu, 1u);
    lift_store8(cpu->esp + 0x2Du, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x200u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x5Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3E4Fu); lift_push32(cpu, r); sfera_sub_00492010(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x40u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    lift_store32(cpu->esp + 0x54u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B3E6D;
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3E6Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B3E6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3E6Du);
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000B3F31;
    goto label_000B3F07;
    label_000B3E7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3E7Au);
    cpu->edx = 0x16Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextEditControl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3E89u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3E90u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    lift_store32(cpu->esp + 0x54u, 1u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000B3ED3;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3EB5u); lift_push32(cpu, r); sfera_sub_004B2650(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->ebx = 1u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x64u, 2u);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3ED1u); lift_push32(cpu, r); sfera_sub_004315D0(cpu,r); if (cpu->eip != r) return; }
    goto label_000B3ED5;
    label_000B3ED3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3ED3u);
    cpu->eax = 0u;
    label_000B3ED5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3ED5u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    lift_store32(cpu->esp + 0x58u, 3u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3EF1u); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x54u, 0xFFFFFFFFu);
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_000B3F07;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB3F07u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    label_000B3F07: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3F07u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3F12u); lift_push32(cpu, r); sfera_sub_00491D00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esi + 0x1C8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + 0x1E4u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3F2Au); lift_push32(cpu, r); sfera_sub_00491500(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB3F31u); lift_push32(cpu, r); sfera_sub_004B4100(cpu,r); if (cpu->eip != r) return; }
    label_000B3F31: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3F31u);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B3F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3F60u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1D8u)) == (uint32_t)(0u)) goto label_000B4057;
    if ((uint32_t)(lift_load32(cpu->esi + 0x210u)) == (uint32_t)(0u)) goto label_000B4057;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x21Cu);
    cpu->edx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3F9Cu); lift_push32(cpu, r); sfera_sub_0048E950(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B4056;
    cpu->edx = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xFFFFFFFFu)) goto label_000B3FBD;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000B3FB9;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B3FBD;
    label_000B3FB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3FB9u);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    goto label_000B3FE6;
    label_000B3FBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3FBDu);
    cpu->ecx = lift_load32(cpu->esi + 0x21Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    --cpu->ecx;
    cpu->edx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3FD9u); lift_push32(cpu, r); sfera_sub_0048E950(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B4056;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    label_000B3FE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B3FE6u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B3FF1u); lift_push32(cpu, r); sfera_sub_0048F420(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B4056;
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4000u); lift_push32(cpu, r); sfera_sub_00491D00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esi + 0x1C8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + 0x1E4u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4018u); lift_push32(cpu, r); sfera_sub_00491500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x258u, (uint64_t)(lift_load32(cpu->esi + 0x258u)) - 1u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x254u)) <= (uint32_t)(0u)) goto label_000B402E;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB402Eu); lift_push32(cpu, r); sfera_sub_004B3760(cpu,r); if (cpu->eip != r) return; }
    label_000B402E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B402Eu);
    cpu->eax = lift_load32(cpu->esi + 0x21Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B4056;
    cpu->ecx = lift_load32(cpu->esi + 0x254u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000B4050;
    --cpu->ecx;
    lift_store32(cpu->esi + 0x254u, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB4050u); lift_push32(cpu, r); sfera_sub_004B3820(cpu,r); if (cpu->eip != r) return; }
    label_000B4050: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4050u);
    lift_store32(cpu->esi + 0x21Cu, (uint64_t)(lift_load32(cpu->esi + 0x21Cu)) - 1u);
    label_000B4056: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4056u);
    cpu->edi = lift_pop32(cpu);
    label_000B4057: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4057u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B4060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4060u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x21Cu);
    cpu->edx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4082u); lift_push32(cpu, r); sfera_sub_0048E950(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B40C8;
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B409Au); lift_push32(cpu, r); sfera_sub_0048F420(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B40C8;
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B40A9u); lift_push32(cpu, r); sfera_sub_00491D00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0x1C8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0x1E4u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B40C1u); lift_push32(cpu, r); sfera_sub_00491500(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB40C8u); lift_push32(cpu, r); sfera_sub_004B3820(cpu,r); if (cpu->eip != r) return; }
    label_000B40C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B40C8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B40D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B40D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x21Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B40FB;
    cpu->eax = lift_load32(cpu->esi + 0x254u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_000B40F5;
    --cpu->eax;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x254u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB40F5u); lift_push32(cpu, r); sfera_sub_004B3820(cpu,r); if (cpu->eip != r) return; }
    label_000B40F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B40F5u);
    lift_store32(cpu->esi + 0x21Cu, (uint64_t)(lift_load32(cpu->esi + 0x21Cu)) - 1u);
    label_000B40FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B40FBu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B4100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4100u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x21Cu);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(lift_load32(cpu->esi + 0x1D8u))) goto label_000B413C;
    cpu->eax = lift_load32(cpu->esi + 0x258u);
    ++cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B4131;
    lift_store32(cpu->esi + 0x258u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4129u); lift_push32(cpu, r); sfera_sub_004B3760(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x21Cu, (uint64_t)(lift_load32(cpu->esi + 0x21Cu)) + 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B4131: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4131u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4136u); lift_push32(cpu, r); sfera_sub_004B3820(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x21Cu, (uint64_t)(lift_load32(cpu->esi + 0x21Cu)) + 1u);
    label_000B413C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B413Cu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B4140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4140u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    lift_store32(cpu->esi + 0x254u, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1D8u)) == (uint32_t)(cpu->edi)) goto label_000B4162;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4159u); lift_push32(cpu, r); sfera_sub_004B3820(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x21Cu, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B4162: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4162u);
    lift_store32(cpu->esi + 0x258u, cpu->edi);
    lift_store32(cpu->esi + 0x21Cu, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B4180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4180u);
    cpu->eax = lift_load32(cpu->ecx + 0x1D8u);
    cpu->edx = 0u;
    lift_store32(cpu->ecx + 0x21Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000B419E;
    --cpu->eax;
    lift_store32(cpu->ecx + 0x258u, cpu->eax);
    sfera_sub_004B3760(cpu, stop_address); return;
    label_000B419E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B419Eu);
    lift_store32(cpu->ecx + 0x254u, cpu->edx);
    lift_store32(cpu->ecx + 0x258u, cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B41B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B41B0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->esp + 0x10u, 0u);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->edi + 0x14u, 0xFu);
    lift_store32(cpu->edi + 0x10u, 0u);
    lift_store8(cpu->edi, 0u);
    lift_push32(cpu, 1u);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store32(cpu->esp + 0x14u, 1u);
    lift_native_call(cpu, native_function_address32(&::IsClipboardFormatAvailable), LIFT_CODE_TOKEN_VA(0x4B4203u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4209u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000B4257;
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::OpenClipboard), LIFT_CODE_TOKEN_VA(0x4B4210u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4216u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000B4257;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetClipboardData), LIFT_CODE_TOKEN_VA(0x4B421Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4222u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000B4251;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::GlobalLock), LIFT_CODE_TOKEN_VA(0x4B4229u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B422Fu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B4251;
    cpu->ecx = cpu->eax;
    cpu->ebp = (uint32_t)(cpu->ecx + 1u);
    label_000B4238: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4238u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000B4238;
    cpu->ecx -= cpu->ebp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B424Au); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::GlobalUnlock), LIFT_CODE_TOKEN_RVA(0xB424Bu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xB4251u);
    label_000B4251: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4251u);
    lift_native_call(cpu, native_function_address32(&::CloseClipboard), LIFT_CODE_TOKEN_RVA(0xB4251u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xB4257u);
    label_000B4257: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4257u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B4270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4270u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x7Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x90u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0xA4u);
    cpu->edi = lift_load32(cpu->esp + 0xA0u);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B44F6;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B4590;
    if ((uint32_t)(lift_load32(cpu->edi + 0x10u)) == (uint32_t)(cpu->ebx)) goto label_000B4590;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store32(cpu->esp + 0x9Cu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B42E1u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000B44CC;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    cpu->ebp = 0xFu;
    lift_store32(cpu->esp + 0x98u, 1u);
    lift_store32(cpu->esp + 0x84u, cpu->ebp);
    lift_store32(cpu->esp + 0x80u, cpu->ebx);
    lift_store8(cpu->esp + 0x70u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x68u, cpu->ebp);
    lift_store32(cpu->esp + 0x64u, cpu->ebx);
    lift_store8(cpu->esp + 0x54u, cpu->ebx & 0xFFu);
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x9Cu, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4357u); lift_push32(cpu, r); sfera_sub_00490C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x64u);
    cpu->ecx += lift_load32(cpu->esi + 0x1D8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(lift_load32(cpu->esi + 0x24Cu))) goto label_000B43FD;
    cpu->edi = lift_load32(cpu->edi + 0x10u);
    cpu->edi += lift_load32(cpu->esi + 0x1F4u);
    if ((uint32_t)(cpu->edi) > (uint32_t)(lift_load32(cpu->esi + 0x250u))) goto label_000B43FD;
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4391u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x2Cu, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B43A4u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B43B4u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x38u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B43C3u); lift_push32(cpu, r); sfera_sub_0048DD80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B43CEu); lift_push32(cpu, r); sfera_sub_0048F7E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B43D9u); lift_push32(cpu, r); sfera_sub_00491D00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0x1C8u);
    cpu->edx = (uint32_t)(cpu->esi + 0x1E4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B43F1u); lift_push32(cpu, r); sfera_sub_00491500(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B43F8u); lift_push32(cpu, r); sfera_sub_004B4180(cpu,r); if (cpu->eip != r) return; }
    goto label_000B4491;
    label_000B43FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B43FDu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) == (uint32_t)(cpu->ebx)) goto label_000B4488;
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4415u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4423u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x38u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000B4488;
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    label_000B4430: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4430u);
    cpu->edx = 0x266u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextEditControl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B443Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B4447;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    goto label_000B444A;
    label_000B4447: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4447u);
    cpu->edx = lift_load32(cpu->ebp);
    label_000B444A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B444Au);
    cpu->edi = lift_load32(cpu->edx + 8u);
    cpu->eax = cpu->esi;
    cpu->ecx = cpu->esi;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->eax)) goto label_000B445D;
    cpu->eax -= cpu->edi;
    label_000B445D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B445Du);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B446Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    ++cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B447Eu); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000B4430;
    cpu->ebp = 0xFu;
    label_000B4488: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4488u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB4491u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    label_000B4491: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4491u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x68u)) < (uint32_t)(0x10u)) goto label_000B44A5;
    cpu->eax = lift_load32(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B44A2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B44A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B44A5u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x68u, cpu->ebp);
    lift_store32(cpu->esp + 0x64u, cpu->ebx);
    lift_store8(cpu->esp + 0x54u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B44BAu); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B44C4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    goto label_000B4590;
    label_000B44CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B44CCu);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB44F6u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000B44F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B44F6u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1F8u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->esi + 0x1F4u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B450D;
    cpu->eax = lift_load32(cpu->esi + 0x1E4u);
    goto label_000B4513;
    label_000B450D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B450Du);
    cpu->eax = (uint32_t)(cpu->esi + 0x1E4u);
    label_000B4513: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4513u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4521u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B4590;
    cpu->edx = lift_load32(cpu->edi + 0x10u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(lift_load32(cpu->esi + 0x250u))) goto label_000B4590;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4537u); lift_push32(cpu, r); sfera_sub_004B3110(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->edi + 0x10u)) == (uint32_t)(cpu->ebx)) goto label_000B4590;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1E4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B454Bu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = (uint32_t)(cpu->esi + 0x1C8u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + 0x200u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1E4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4563u); lift_push32(cpu, r); sfera_sub_00490C50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4577u); lift_push32(cpu, r); sfera_sub_004923E0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + 0x1E4u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4589u); lift_push32(cpu, r); sfera_sub_00491500(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB4590u); lift_push32(cpu, r); sfera_sub_004B4180(cpu,r); if (cpu->eip != r) return; }
    label_000B4590: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4590u);
    cpu->ecx = lift_load32(cpu->esp + 0x90u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x88u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B45C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B45C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    cpu->edi = lift_load32(cpu->esp + 0x48u);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x1DB0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000B46E1;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B4674;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x69u)) goto label_000B4780;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B4666;
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Au)) != (uint8_t)(0u)) goto label_000B4666;
    lift_push32(cpu, 0xDu); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = cpu->eax;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4630u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x11u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4644u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x17u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4658u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Au, 1u);
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B4666: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4666u);
    lift_store8(cpu->esi + 0x4Au, 0u);
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B4674: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4674u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B4779;
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esp + 0x24u, 0xFu);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store8(cpu->esp + 0x10u, 0u);
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    label_000B4696: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4696u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000B4696;
    cpu->eax -= cpu->ebx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B46AAu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x40u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B46BFu); lift_push32(cpu, r); sfera_sub_004B4270(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) < (uint32_t)(0x10u)) goto label_000B4779;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B46D4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B46E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B46E1u);
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFE24Fu);
    if ((uint32_t)(cpu->edx) > (uint32_t)(5u)) goto label_000B4780;
    switch ((uint32_t)(cpu->edx)) {
        case 0u: goto label_000B4707;
        case 1u: goto label_000B4731;
        case 2u: case 4u: goto label_000B4780;
        case 3u: goto label_000B4761;
        case 5u: goto label_000B46F7;
        default: lift_trap(cpu, 0x4B46F0u, "resolved jump-table index out of range"); return;
    }
label_000B46F7: ;
    lift_store32(cpu->esi + 0x23Cu, cpu->ecx);
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B4707: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4707u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B4779;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1DCu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x1C8u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B471C;
    cpu->eax = lift_load32(cpu->eax);
    label_000B471C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B471Cu);
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    label_000B4720: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4720u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000B4720;
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B4731: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4731u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B4779;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1F8u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x1E4u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B4746;
    cpu->eax = lift_load32(cpu->eax);
    label_000B4746: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4746u);
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000B4750: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4750u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000B4750;
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B4761: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4761u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B476D;
    cpu->edx = lift_load32(cpu->esi + 0x1D8u);
    lift_store32(cpu->ecx, cpu->edx);
    label_000B476D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B476Du);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000B4779;
    cpu->eax = lift_load32(cpu->esi + 0x1F4u);
    lift_store32(cpu->edi, cpu->eax);
    label_000B4779: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4779u);
    cpu->eax = 1u;
    goto label_000B478A;
    label_000B4780: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4780u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB478Au); lift_push32(cpu, r); sfera_sub_004D2DD0(cpu,r); if (cpu->eip != r) return; }
    label_000B478A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B478Au);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B47D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B47D0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x48u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B4A68;
    if ((uint8_t)((lift_load8(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000B4A68;
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    cpu->edx = 0u;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B4820;
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B481Bu); lift_push32(cpu, r); sfera_sub_004A8A30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    label_000B4820: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4820u);
    cpu->eax += lift_load32(cpu->edi + 0x34u);
    cpu->edx += lift_load32(cpu->edi + 0x30u);
    cpu->edi = lift_load32(cpu->esi + 0x30u);
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->ebx = cpu->eax;
    cpu->ebx += lift_load32(cpu->esi + 0x34u);
    cpu->edi += cpu->edx;
    lift_store32(cpu->esi + 0x274u, cpu->edx);
    lift_store32(cpu->esi + 0x278u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->edi + 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebx + 0xFFFFFFFFu);
    cpu->eax = lift_load32(cpu->esi + 0x22Cu);
    lift_store32(cpu->esp + 0x48u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x228u);
    lift_store32(cpu->esp + 0x4Cu, cpu->ecx);
    cpu->edx += cpu->edi;
    cpu->eax += cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4871u); lift_push32(cpu, r); sfera_sub_004B14F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->edi);
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->ebx);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->ecx);
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetTickCount), LIFT_CODE_TOKEN_VA(0x4B4891u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4897u);
    cpu->ecx = cpu->eax;
    cpu->ecx -= lift_load32(cpu->esi + 0x220u);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(0x1F4u)) goto label_000B48BD;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x224u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esi + 0x220u, cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esi + 0x224u, cpu->edx & 0xFFu);
    label_000B48BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B48BDu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x224u)) == (uint8_t)(0u)) goto label_000B48D3;
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Au)) == (uint8_t)(0u)) goto label_000B48D3;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB48D3u); lift_push32(cpu, r); sfera_sub_004B3530(cpu,r); if (cpu->eip != r) return; }
    label_000B48D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B48D3u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1D8u)) == (uint32_t)(0u)) goto label_000B4A56;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x254u);
    cpu->edx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B48FBu); lift_push32(cpu, r); sfera_sub_0048E950(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B4A56;
    cpu->ebx |= 0xFFFFFFFFu;
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) == (uint32_t)(cpu->ebx)) goto label_000B4A56;
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) == (uint32_t)(cpu->ebx)) goto label_000B4A56;
    cpu->ecx = lift_load32(cpu->esi + 0x258u);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4935u); lift_push32(cpu, r); sfera_sub_0048E950(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B4A56;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_000B4950;
    cpu->eax = lift_load32(cpu->esi + 0x210u);
    --cpu->eax;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    label_000B4950: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4950u);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint32_t)(cpu->ebx) > (uint32_t)(cpu->eax)) goto label_000B4A56;
    label_000B4960: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4960u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B496Cu); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4974u);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B497Fu); lift_push32(cpu, r); sfera_sub_004312C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B4A47;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4993u); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B49A9u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    --cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B49B6u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_000B49C8;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    label_000B49C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B49C8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esp + 0xCu))) goto label_000B49D2;
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    label_000B49D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B49D2u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B49DEu); lift_push32(cpu, r); sfera_sub_00431240(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_000B4A0E;
    cpu->eax = lift_load32(cpu->esi + 0x23Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x4Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4A0Cu); lift_push32(cpu, r); sfera_sub_004B3390(cpu,r); if (cpu->eip != r) return; }
    goto label_000B4A31;
    label_000B4A0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4A0Eu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_000B4A31;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    lift_store32(cpu->esp + 0x3Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB4A31u); lift_push32(cpu, r); sfera_sub_004B3200(cpu,r); if (cpu->eip != r) return; }
    label_000B4A31: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4A31u);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4A3Du); lift_push32(cpu, r); sfera_sub_00431260(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    label_000B4A47: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4A47u);
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(lift_load32(cpu->esp + 0xCu))) goto label_000B4960;
    label_000B4A56: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4A56u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi += 0x25Cu;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB4A68u); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    label_000B4A68: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4A68u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B4AB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4AB0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4AD8u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) <= (uint32_t)(cpu->ebx)) goto label_000B4B50;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    label_000B4AE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4AE1u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_000B4AED;
    cpu->ebx = lift_load32(cpu->esi);
    goto label_000B4AEF;
    label_000B4AED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4AEDu);
    cpu->ebx = cpu->esi;
    label_000B4AEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4AEFu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B4AF8;
    cpu->edi = lift_load32(cpu->esi);
    goto label_000B4AFA;
    label_000B4AF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4AF8u);
    cpu->edi = cpu->esi;
    label_000B4AFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4AFAu);
    cpu->eax = 0x4EC4EC4Fu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xDu);
    cpu->ebp = cpu->ecx;
    cpu->ebp -= cpu->eax;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->eax = cpu->ecx;
    cpu->eax -= cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(sfera_string_obfuscation_primary_shift(cpu->ebp)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(sfera_string_obfuscation_secondary_shift(cpu->eax)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    ++cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(lift_load8(cpu->ebx + cpu->ecx + 0xFFFFFFFFu)) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->edi + cpu->ecx + 0xFFFFFFFFu, cpu->edx & 0xFFu);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000B4AE1;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000B4B50: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4B50u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B4B60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4B60u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    lift_store32(cpu->edi + 0x14u, 0xFu);
    lift_store32(cpu->edi + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x14u, 0u);
    lift_store8(cpu->edi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4B90u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x10u)) <= (uint32_t)(cpu->esi)) goto label_000B4C05;
    lift_push32(cpu, cpu->ebp);
    label_000B4B98: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4B98u);
    cpu->eax = lift_load32(cpu->edi + 0x14u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_000B4BA4;
    cpu->ecx = lift_load32(cpu->edi);
    goto label_000B4BA6;
    label_000B4BA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4BA4u);
    cpu->ecx = cpu->edi;
    label_000B4BA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4BA6u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B4BAF;
    cpu->ebp = lift_load32(cpu->edi);
    goto label_000B4BB1;
    label_000B4BAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4BAFu);
    cpu->ebp = cpu->edi;
    label_000B4BB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4BB1u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + cpu->esi)) & 0xFFu);
    cpu->eax = 0x4EC4EC4Fu;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xDu);
    cpu->edx = cpu->esi;
    cpu->edx -= cpu->eax;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(sfera_string_obfuscation_primary_shift(cpu->edx)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->eax = cpu->esi;
    cpu->eax -= cpu->edx;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(sfera_string_obfuscation_secondary_shift(cpu->eax)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    ++cpu->esi;
    lift_store8(cpu->esi + cpu->ebp + 0xFFFFFFFFu, cpu->ecx & 0xFFu);
    if ((uint32_t)(cpu->esi) < (uint32_t)(lift_load32(cpu->edi + 0x10u))) goto label_000B4B98;
    cpu->ebp = lift_pop32(cpu);
    label_000B4C05: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4C05u);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B4C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4C10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) == (uint32_t)(cpu->ebx)) goto label_000B4C6B;
    lift_store32(cpu->edi + 0x74u, 0u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, 1u);
    label_000B4C6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4C6Bu);
    cpu->esi = (uint32_t)(cpu->edi + 0x10u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x20u, 1u);
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x20u, 2u);
    lift_store8(cpu->esi + 0x50u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esi + 0x49u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x54u, cpu->ebx);
    cpu->ecx = g_sfera_recovered_static_runtime.ui_counter_a;
    lift_store32(cpu->esi + 0x4Cu, cpu->ecx);
    lift_store32(cpu->esi + 0x44u, cpu->ebx);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B4CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4CE0u);
    const uint32_t filebuf = cpu->ecx + 0x10u;
    if (sfera_filebuf_file(filebuf) != nullptr) { (void)sfera_filebuf_close_native(filebuf); }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B4DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4DD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4E01u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    cpu->edi = (uint32_t)(cpu->esi + 0x198u);
    std::construct_at(reinterpret_cast<SphereUI::HyperTextEditControl*>(cpu->esi));
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->edi, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0x40u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4E25u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000B4F82;
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->edi + 4u, cpu->ebx);
    lift_store32(cpu->edi + 8u, cpu->ebx);
    lift_store32(cpu->edi + 0xCu, cpu->ebx);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_push32(cpu, 0x14u);
    lift_store8(cpu->esp + 0x40u, 2u);
    lift_store32(cpu->esi + 0x1C0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4E5Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000B4F58;
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1BCu);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1BCu);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x1BCu);
    lift_store8(cpu->ecx + 0x10u, 1u);
    cpu->edx = lift_load32(cpu->esi + 0x1BCu);
    lift_store8(cpu->edx + 0x11u, 1u);
    cpu->eax = 0xFu;
    lift_store32(cpu->esi + 0x1DCu, cpu->eax);
    lift_store32(cpu->esi + 0x1D8u, cpu->ebx);
    lift_store8(cpu->esi + 0x1C8u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x1F8u, cpu->eax);
    lift_store32(cpu->esi + 0x1F4u, cpu->ebx);
    lift_store8(cpu->esi + 0x1E4u, cpu->ebx & 0xFFu);
    cpu->edi = (uint32_t)(cpu->esi + 0x200u);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_store32(cpu->edi, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0x40u, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4ED7u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000B4F2E;
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->edi + 4u, cpu->ebx);
    lift_store32(cpu->edi + 8u, cpu->ebx);
    lift_store32(cpu->edi + 0xCu, cpu->ebx);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x21Cu, cpu->ebx);
    lift_store8(cpu->esi + 0x224u, 1u);
    lift_store32(cpu->esi + 0x254u, cpu->ebx);
    lift_store32(cpu->esi + 0x258u, cpu->ebx);
    lift_store32(cpu->esi + 0x50u, 0x17u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_000B4F2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4F2Eu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB4F58u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000B4F58: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4F58u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB4F82u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000B4F82: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4F82u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4FACu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4B4FACu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B4FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4FB0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_store32(cpu->esp + 0xCu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B4FD3u); lift_push32(cpu, r); sfera_sub_004B2440(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi + 0x1BCu))) goto label_000B5013;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1A8u)) == (uint32_t)(0u)) goto label_000B5013;
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B4FF7;
    --cpu->eax;
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    label_000B4FF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B4FF7u);
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B500Bu); lift_push32(cpu, r); sfera_sub_004B23F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB5013u); lift_push32(cpu, r); sfera_sub_004B4270(cpu,r); if (cpu->eip != r) return; }
    label_000B5013: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5013u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B5020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5020u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_store32(cpu->esp + 0xCu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5043u); lift_push32(cpu, r); sfera_sub_004B2440(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi + 0x1BCu))) goto label_000B5089;
    cpu->ecx = lift_load32(cpu->esi + 0x1A8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B5089;
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_000B5068;
    ++cpu->eax;
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    label_000B5068: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5068u);
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B5079;
    --cpu->eax;
    label_000B5079: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5079u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B507Fu); lift_push32(cpu, r); sfera_sub_004B23F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB5089u); lift_push32(cpu, r); sfera_sub_004B4270(cpu,r); if (cpu->eip != r) return; }
    label_000B5089: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5089u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B5090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5090u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x80u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x94u);
    (void)0; /* source SEH registration eliminated */
    lift_push32(cpu, 2u);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    cpu->edi = 0xFu;
    lift_push32(cpu, (uint32_t)(uintptr_t)"  ");
    cpu->ecx = (uint32_t)(cpu->esp + 0x60u);
    lift_store32(cpu->esp + 0x74u, cpu->edi);
    lift_store32(cpu->esp + 0x70u, cpu->ebx);
    lift_store8(cpu->esp + 0x60u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B50EDu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"\n\r");
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0xA4u, cpu->ebx);
    lift_store32(cpu->esp + 0x3Cu, cpu->edi);
    lift_store32(cpu->esp + 0x38u, cpu->ebx);
    lift_store8(cpu->esp + 0x28u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5110u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0xA0u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5124u); lift_push32(cpu, r); sfera_sub_004B41B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_store8(cpu->esp + 0xA4u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5141u); lift_push32(cpu, r); sfera_sub_00490530(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x88u)) < (uint32_t)(cpu->ebp)) goto label_000B515C;
    cpu->eax = lift_load32(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5159u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B515C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B515Cu);
    lift_store32(cpu->esp + 0x88u, cpu->edi);
    lift_store32(cpu->esp + 0x84u, cpu->ebx);
    lift_store8(cpu->esp + 0x74u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(cpu->ebp)) goto label_000B5181;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B517Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5181: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5181u);
    lift_store32(cpu->esp + 0x34u, cpu->edi);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0x9Cu, 6u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x6Cu)) < (uint32_t)(cpu->ebp)) goto label_000B51A8;
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B51A5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B51A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B51A8u);
    cpu->ecx = lift_load32(cpu->esi + 0x1D8u);
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    cpu->eax = lift_load32(cpu->esi + 0x24Cu);
    cpu->edx += cpu->ecx;
    lift_store32(cpu->esp + 0x6Cu, cpu->edi);
    lift_store32(cpu->esp + 0x68u, cpu->ebx);
    lift_store8(cpu->esp + 0x58u, cpu->ebx & 0xFFu);
    if ((uint32_t)(cpu->edx) <= (uint32_t)(cpu->eax)) goto label_000B51D8;
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB51D8u); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    label_000B51D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B51D8u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x4Cu)) == (uint32_t)(cpu->ebx)) goto label_000B52DE;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x21Cu);
    cpu->edx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B51FDu); lift_push32(cpu, r); sfera_sub_0048E950(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B5220;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0x200u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B521Au); lift_push32(cpu, r); sfera_sub_00492010(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B529B;
    goto label_000B5278;
    label_000B5220: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5220u);
    cpu->edx = 0x208u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextEditControl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B522Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5236u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store8(cpu->esp + 0x9Cu, 7u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000B525A;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5258u); lift_push32(cpu, r); sfera_sub_004315D0(cpu,r); if (cpu->eip != r) return; }
    goto label_000B525C;
    label_000B525A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B525Au);
    cpu->eax = 0u;
    label_000B525C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B525Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    lift_store8(cpu->esp + 0xA0u, 6u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB5278u); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    label_000B5278: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5278u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5283u); lift_push32(cpu, r); sfera_sub_00491D00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0x1C8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0x1E4u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB529Bu); lift_push32(cpu, r); sfera_sub_00491500(cpu,r); if (cpu->eip != r) return; }
    label_000B529B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B529Bu);
    cpu->ecx = lift_load32(cpu->esi + 0x21Cu);
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->esi + 0x1D8u))) goto label_000B52DE;
    cpu->eax = lift_load32(cpu->esi + 0x258u);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B52CF;
    cpu->eax += cpu->edx;
    lift_store32(cpu->esi + 0x258u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B52CDu); lift_push32(cpu, r); sfera_sub_004B3760(cpu,r); if (cpu->eip != r) return; }
    goto label_000B52D4;
    label_000B52CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B52CFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB52D4u); lift_push32(cpu, r); sfera_sub_004B3820(cpu,r); if (cpu->eip != r) return; }
    label_000B52D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B52D4u);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->esi + 0x21Cu, (uint64_t)(lift_load32(cpu->esi + 0x21Cu)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    label_000B52DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B52DEu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) < (uint32_t)(cpu->ebp)) goto label_000B52F1;
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B52EEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B52F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B52F1u);
    cpu->ecx = lift_load32(cpu->esp + 0x94u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x8Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B5350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5350u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x110u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x124u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = lift_load32(cpu->esp + 0x134u);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_push32(cpu, cpu->ebx);
    cpu->ebp = 0xFu;
    lift_store32(cpu->edi + 0x14u, cpu->ebp);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x134u, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store8(cpu->edi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B53BDu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    cpu->esi = 1u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0xD4u);
    lift_store32(cpu->esp + 0x134u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esp + 0xE8u, cpu->ebp);
    lift_store32(cpu->esp + 0xE4u, cpu->ebx);
    lift_store8(cpu->esp + 0xD4u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B53F4u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x130u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5405u); lift_push32(cpu, r); sfera_sub_004B4C10(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu); lift_push32(cpu, (uintptr_t)"connectn.cfg");
    cpu->ecx = (uint32_t)(cpu->esp + 0xF0u);
    lift_store8(cpu->esp + 0x134u, 2u);
    lift_store32(cpu->esp + 0x104u, cpu->ebp);
    lift_store32(cpu->esp + 0x100u, cpu->ebx);
    lift_store8(cpu->esp + 0xF0u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5435u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0xFCu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 0xE8u);
    lift_store8(cpu->esp + 0x12Cu, 3u);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000B5455;
    cpu->eax = (uint32_t)(cpu->esp + 0xE8u);
    label_000B5455: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5455u);
    lift_push32(cpu, 0x40u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5462u); lift_push32(cpu, r); sfera_sub_004B1830(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B547C;
    lift_store32(cpu->esp + 0x90u, 2u);
    goto label_000B548E;
    label_000B547C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B547Cu);
    lift_store32(cpu->esp + 0x90u, 0u);
    label_000B548E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B548Eu);
    if ((uint32_t)((lift_load32(cpu->esp + 0x90u)) & (6u)) != 0u) goto label_000B56DA;
    lift_push32(cpu, 0xAu);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B54BEu); lift_push32(cpu, r); sfera_sub_004B2D70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((lift_load32(cpu->eax + 0x74u)) & (6u)) != 0u) goto label_000B5658;
    label_000B54E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B54E0u);
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    if ((uint32_t)(cpu->esi) < (uint32_t)(2u)) goto label_000B562C;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B54F4u); lift_push32(cpu, r); sfera_sub_0048DBE0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x4Du)) goto label_000B562C;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5506u); lift_push32(cpu, r); sfera_sub_0048DBE0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x41u)) goto label_000B562C;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->ebx)) goto label_000B562C;
    cpu->edx = lift_load32(cpu->edi + 0x14u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000B5520: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5520u);
    if ((uint32_t)(cpu->edx) < (uint32_t)(0x10u)) goto label_000B5529;
    cpu->eax = lift_load32(cpu->edi);
    goto label_000B552B;
    label_000B5529: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5529u);
    cpu->eax = cpu->edi;
    label_000B552B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B552Bu);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ecx)) == (uint8_t)(0x2Eu)) goto label_000B5539;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000B5520;
    goto label_000B562C;
    label_000B5539: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5539u);
    cpu->ebp = (uint32_t)(cpu->ecx + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000B5540: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5540u);
    cpu->ecx = lift_load32(cpu->edi + 0x14u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_000B554C;
    cpu->eax = lift_load32(cpu->edi);
    goto label_000B554E;
    label_000B554C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B554Cu);
    cpu->eax = cpu->edi;
    label_000B554E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B554Eu);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebp)) == (uint8_t)(0x22u)) goto label_000B5627;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_000B5561;
    cpu->eax = lift_load32(cpu->edi);
    goto label_000B5563;
    label_000B5561: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5561u);
    cpu->eax = cpu->edi;
    label_000B5563: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5563u);
    cpu->ecx = lift_load8(cpu->eax + cpu->ebp);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xD0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x108u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B557Bu); lift_push32(cpu, r); sfera_sub_004B3C10(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->edx = (uint32_t)(cpu->esp + 0xCCu);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000B55FF;
    if ((uint32_t)(lift_load32(cpu->esp + 0xE0u)) < (uint32_t)(0x10u)) goto label_000B55A2;
    cpu->eax = lift_load32(cpu->esp + 0xCCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B559Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B55A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B55A2u);
    lift_store32(cpu->esp + 0xE0u, 0xFu);
    lift_store32(cpu->esp + 0xDCu, cpu->ebx);
    lift_store8(cpu->esp + 0xCCu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) >= (uint32_t)(0x10u)) goto label_000B55DA;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xD0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4B55CFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B55D5u);
    cpu->esp += 0xCu;
    goto label_000B55E5;
    label_000B55DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B55DAu);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0xCCu, cpu->edx);
    lift_store32(cpu->esi, cpu->ebx);
    label_000B55E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B55E5u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esp + 0xDCu, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0xE0u, cpu->ecx);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    label_000B55FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B55FFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x118u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x12Cu, 3u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B5621;
    cpu->edx = lift_load32(cpu->esp + 0x104u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B561Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5621: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5621u);
    ++cpu->ebp;
    goto label_000B5540;
    label_000B5627: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5627u);
    cpu->ebp = 0xFu;
    label_000B562C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B562Cu);
    lift_push32(cpu, 0xAu);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5639u); lift_push32(cpu, r); sfera_sub_004B2D70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((lift_load32(cpu->eax + 0x74u)) & (6u)) == 0u) goto label_000B54E0;
    label_000B5658: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5658u);
    cpu->esi = (uint32_t)(cpu->esp + 0x2Cu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x80u)) == (uint32_t)(cpu->ebx)) goto label_000B5687;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B566Cu); lift_push32(cpu, r); sfera_sub_004B2AD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000B5672;
    cpu->esi = 0u;
    label_000B5672: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5672u);
    cpu->ecx = lift_load32(cpu->esp + 0x80u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4B567Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5680u);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B5689;
    label_000B5687: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5687u);
    cpu->esi = 0u;
    label_000B5689: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5689u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store8(cpu->esp + 0x7Cu, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0x75u, cpu->ebx & 0xFFu);
    cpu->edx = g_sfera_recovered_static_runtime.ui_counter_a;
    lift_store32(cpu->esp + 0x80u, cpu->ebx);
    lift_store32(cpu->esp + 0x78u, cpu->edx);
    lift_store32(cpu->esp + 0x70u, cpu->ebx);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000B56C8;
    lift_store32(cpu->esp + 0x90u, (uint64_t)(lift_load32(cpu->esp + 0x90u)) | (uint64_t)(2u));
    label_000B56C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B56C8u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0xD4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB56DAu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_000B56DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B56DAu);
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0xFCu)) < (uint32_t)(cpu->esi)) goto label_000B56F8;
    cpu->edx = lift_load32(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B56F5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B56F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B56F8u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0xFCu, cpu->ebp);
    lift_store32(cpu->esp + 0xF8u, cpu->ebx);
    lift_store8(cpu->esp + 0xE8u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0x12Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5721u); lift_push32(cpu, r); sfera_sub_004B4CE0(cpu,r); if (cpu->eip != r) return; }
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xB572Eu);
    if ((uint32_t)(lift_load32(cpu->esp + 0xE0u)) < (uint32_t)(cpu->esi)) goto label_000B5747;
    cpu->eax = lift_load32(cpu->esp + 0xCCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5744u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5747: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5747u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x124u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x11Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B57C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B57C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x19Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1B0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->esi = lift_load32(cpu->ebp + 0x1BCu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x1B8u);
    lift_store32(cpu->esp + 0x1Cu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5820u); lift_push32(cpu, r); sfera_sub_004B2440(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax)) != (uint32_t)(cpu->esi)) goto label_000B5CE8;
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5833u); lift_push32(cpu, r); sfera_sub_004B4C10(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    lift_push32(cpu, 0x12u);
    cpu->edi = 0xFu;
    lift_push32(cpu, (uint32_t)(uintptr_t)"_hyperTextEdit.log");
    cpu->ecx = (uint32_t)(cpu->esp + 0x128u);
    lift_store32(cpu->esp + 0x1C0u, cpu->ebx);
    lift_store32(cpu->esp + 0x13Cu, cpu->edi);
    lift_store32(cpu->esp + 0x138u, cpu->ebx);
    lift_store8(cpu->esp + 0x128u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5869u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esp + 0x1BCu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5880u); lift_push32(cpu, r); sfera_sub_004B5350(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x9Cu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x18Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x1B8u, 2u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B58A3;
    cpu->esi = lift_load32(cpu->eax + 0x178u);
    goto label_000B58A9;
    label_000B58A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B58A3u);
    cpu->esi = (uint32_t)(cpu->eax + 0x178u);
    label_000B58A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B58A9u);
    cpu->eax = cpu->esi;
    lift_store32(cpu->esp + 0x118u, cpu->edi);
    lift_store32(cpu->esp + 0x114u, cpu->ebx);
    lift_store8(cpu->esp + 0x104u, cpu->ebx & 0xFFu);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000B58C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B58C3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B58C3;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B58DAu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->esi = 0xFu;
    lift_push32(cpu, (uint32_t)(uintptr_t)"players\\");
    cpu->ecx = (uint32_t)(cpu->esp + 0xD4u);
    lift_store8(cpu->esp + 0x1C0u, 3u);
    lift_store32(cpu->esp + 0xE8u, cpu->esi);
    lift_store32(cpu->esp + 0xE4u, cpu->ebx);
    lift_store8(cpu->esp + 0xD4u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B590Fu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x104u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xD0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x178u);
    lift_store8(cpu->esp + 0x1BCu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5932u); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"_");
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x194u);
    lift_store8(cpu->esp + 0x1BCu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B594Du); lift_push32(cpu, r); sfera_sub_004903C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x15Cu);
    lift_store8(cpu->esp + 0x1BCu, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5968u); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x120u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x140u);
    lift_store8(cpu->esp + 0x1BCu, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5986u); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x16Cu)) < (uint32_t)(cpu->edi)) goto label_000B59A4;
    cpu->eax = lift_load32(cpu->esp + 0x158u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B59A1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B59A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B59A4u);
    lift_store32(cpu->esp + 0x16Cu, cpu->esi);
    lift_store32(cpu->esp + 0x168u, cpu->ebx);
    lift_store8(cpu->esp + 0x158u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1A4u)) < (uint32_t)(cpu->edi)) goto label_000B59D2;
    cpu->ecx = lift_load32(cpu->esp + 0x190u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B59CFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B59D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B59D2u);
    lift_store32(cpu->esp + 0x1A4u, cpu->esi);
    lift_store32(cpu->esp + 0x1A0u, cpu->ebx);
    lift_store8(cpu->esp + 0x190u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x188u)) < (uint32_t)(cpu->edi)) goto label_000B5A00;
    cpu->edx = lift_load32(cpu->esp + 0x174u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B59FDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5A00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5A00u);
    lift_store32(cpu->esp + 0x188u, cpu->esi);
    lift_store32(cpu->esp + 0x184u, cpu->ebx);
    lift_store8(cpu->esp + 0x174u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0xE0u)) < (uint32_t)(cpu->edi)) goto label_000B5A2E;
    cpu->eax = lift_load32(cpu->esp + 0xCCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5A2Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5A2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5A2Eu);
    lift_store32(cpu->esp + 0xE0u, cpu->esi);
    lift_store32(cpu->esp + 0xDCu, cpu->ebx);
    lift_store8(cpu->esp + 0xCCu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x118u)) < (uint32_t)(cpu->edi)) goto label_000B5A5C;
    cpu->ecx = lift_load32(cpu->esp + 0x104u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5A59u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5A5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5A5Cu);
    lift_store32(cpu->esp + 0x118u, cpu->esi);
    lift_store32(cpu->esp + 0x114u, cpu->ebx);
    lift_store8(cpu->esp + 0x104u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0xFCu)) < (uint32_t)(cpu->edi)) goto label_000B5A8A;
    cpu->edx = lift_load32(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5A87u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5A8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5A8Au);
    lift_store32(cpu->esp + 0xFCu, cpu->esi);
    lift_store32(cpu->esp + 0xF8u, cpu->ebx);
    lift_store8(cpu->esp + 0xE8u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0x1B8u, 0xFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x134u)) < (uint32_t)(cpu->edi)) goto label_000B5AC0;
    cpu->eax = lift_load32(cpu->esp + 0x120u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5ABDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5AC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5AC0u);
    cpu->eax = lift_load32(cpu->esp + 0x13Cu);
    lift_store32(cpu->esp + 0x134u, cpu->esi);
    lift_store32(cpu->esp + 0x130u, cpu->ebx);
    lift_store8(cpu->esp + 0x120u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x150u)) >= (uint32_t)(cpu->edi)) goto label_000B5AEC;
    cpu->eax = (uint32_t)(cpu->esp + 0x13Cu);
    label_000B5AEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5AECu);
    lift_push32(cpu, 0x40u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5AFAu); lift_push32(cpu, r); sfera_sub_004B1830(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B5B14;
    lift_store32(cpu->esp + 0x90u, 2u);
    goto label_000B5B26;
    label_000B5B14: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5B14u);
    lift_store32(cpu->esp + 0x90u, 0u);
    label_000B5B26: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5B26u);
    if ((uint32_t)((lift_load32(cpu->esp + 0x90u)) & (6u)) != 0u) goto label_000B5C96;
    lift_store32(cpu->esp + 0xE0u, cpu->esi);
    lift_store32(cpu->esp + 0xDCu, cpu->ebx);
    lift_store8(cpu->esp + 0xCCu, cpu->ebx & 0xFFu);
    lift_push32(cpu, 0xAu);
    cpu->edx = (uint32_t)(cpu->esp + 0xD0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store8(cpu->esp + 0x1BCu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5B78u); lift_push32(cpu, r); sfera_sub_004B2D70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((lift_load32(cpu->eax + 0x74u)) & (6u)) != 0u) goto label_000B5C5F;
    label_000B5BA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5BA0u);
    cpu->eax = lift_load32(cpu->ebp + 0x1A8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0x1B4u))) goto label_000B5C5F;
    if ((uint32_t)(lift_load32(cpu->esp + 0xDCu)) == (uint32_t)(cpu->ebx)) goto label_000B5C30;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xECu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5BD2u); lift_push32(cpu, r); sfera_sub_004B4AB0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xD0u);
    lift_store8(cpu->esp + 0x1BCu, 0x11u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5BE7u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x1B8u, 0x10u);
    if ((uint32_t)(lift_load32(cpu->esp + 0xFCu)) < (uint32_t)(cpu->edi)) goto label_000B5C08;
    cpu->eax = lift_load32(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5C05u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5C08: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5C08u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x198u);
    lift_store32(cpu->esp + 0x100u, cpu->esi);
    lift_store32(cpu->esp + 0xFCu, cpu->ebx);
    lift_store8(cpu->esp + 0xECu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB5C30u); lift_push32(cpu, r); sfera_sub_004AF8A0(cpu,r); if (cpu->eip != r) return; }
    label_000B5C30: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5C30u);
    lift_push32(cpu, 0xAu);
    cpu->edx = (uint32_t)(cpu->esp + 0xD0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5C42u); lift_push32(cpu, r); sfera_sub_004B2D70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((lift_load32(cpu->eax + 0x74u)) & (6u)) == 0u) goto label_000B5BA0;
    label_000B5C5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5C5Fu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5C68u); lift_push32(cpu, r); sfera_sub_004B3900(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0xE0u)) < (uint32_t)(cpu->edi)) goto label_000B5C81;
    cpu->eax = lift_load32(cpu->esp + 0xCCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5C7Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5C81: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5C81u);
    lift_store32(cpu->esp + 0xE0u, cpu->esi);
    lift_store32(cpu->esp + 0xDCu, cpu->ebx);
    lift_store8(cpu->esp + 0xCCu, cpu->ebx & 0xFFu);
    label_000B5C96: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5C96u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x150u)) < (uint32_t)(cpu->edi)) goto label_000B5CAF;
    cpu->ecx = lift_load32(cpu->esp + 0x13Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5CACu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5CAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5CAFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x150u, cpu->esi);
    lift_store32(cpu->esp + 0x14Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x13Cu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x1B8u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5CDBu); lift_push32(cpu, r); sfera_sub_004B4CE0(cpu,r); if (cpu->eip != r) return; }
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xB5CE8u);
    label_000B5CE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5CE8u);
    cpu->ecx = lift_load32(cpu->esp + 0x1B0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1A8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B5D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5D10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1E8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1FCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edi = lift_load32(cpu->esi + 0x1BCu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    lift_store32(cpu->esp + 0x1Cu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5D74u); lift_push32(cpu, r); sfera_sub_004B2440(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax)) != (uint32_t)(cpu->edi)) goto label_000B623D;
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1A8u)) == (uint32_t)(cpu->ebx)) goto label_000B623D;
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5D95u); lift_push32(cpu, r); sfera_sub_004B3970(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x12u);
    cpu->edi = 0xFu;
    lift_push32(cpu, (uint32_t)(uintptr_t)"_hyperTextEdit.log");
    cpu->ecx = (uint32_t)(cpu->esp + 0xE8u);
    lift_store32(cpu->esp + 0x20Cu, cpu->ebx);
    lift_store32(cpu->esp + 0xFCu, cpu->edi);
    lift_store32(cpu->esp + 0xF8u, cpu->ebx);
    lift_store8(cpu->esp + 0xE8u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5DC9u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x188u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x208u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5DE0u); lift_push32(cpu, r); sfera_sub_004B5350(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x9Cu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x18Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x204u, 2u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B5E03;
    cpu->esi = lift_load32(cpu->eax + 0x178u);
    goto label_000B5E09;
    label_000B5E03: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5E03u);
    cpu->esi = (uint32_t)(cpu->eax + 0x178u);
    label_000B5E09: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5E09u);
    cpu->eax = cpu->esi;
    lift_store32(cpu->esp + 0x148u, cpu->edi);
    lift_store32(cpu->esp + 0x144u, cpu->ebx);
    lift_store8(cpu->esp + 0x134u, cpu->ebx & 0xFFu);
    cpu->ebp = (uint32_t)(cpu->eax + 1u);
    label_000B5E23: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5E23u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B5E23;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x13Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5E3Au); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u); lift_push32(cpu, (uintptr_t)"players\\");
    cpu->ecx = (uint32_t)(cpu->esp + 0x120u);
    lift_store8(cpu->esp + 0x20Cu, 3u);
    lift_store32(cpu->esp + 0x134u, cpu->edi);
    lift_store32(cpu->esp + 0x130u, cpu->ebx);
    lift_store8(cpu->esp + 0x120u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5E6Au); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x134u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x11Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1C4u);
    lift_store8(cpu->esp + 0x208u, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5E8Du); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"_");
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x170u);
    lift_store8(cpu->esp + 0x208u, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5EA8u); lift_push32(cpu, r); sfera_sub_004903C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1E0u);
    lift_store8(cpu->esp + 0x208u, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5EC3u); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0xE0u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x154u);
    lift_store8(cpu->esp + 0x208u, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5EE1u); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1F0u)) < (uint32_t)(cpu->esi)) goto label_000B5EFF;
    cpu->eax = lift_load32(cpu->esp + 0x1DCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5EFCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5EFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5EFFu);
    lift_store32(cpu->esp + 0x1F0u, cpu->edi);
    lift_store32(cpu->esp + 0x1ECu, cpu->ebx);
    lift_store8(cpu->esp + 0x1DCu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x180u)) < (uint32_t)(cpu->esi)) goto label_000B5F2D;
    cpu->ecx = lift_load32(cpu->esp + 0x16Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5F2Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5F2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5F2Du);
    lift_store32(cpu->esp + 0x180u, cpu->edi);
    lift_store32(cpu->esp + 0x17Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x16Cu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1D4u)) < (uint32_t)(cpu->esi)) goto label_000B5F5B;
    cpu->edx = lift_load32(cpu->esp + 0x1C0u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5F58u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5F5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5F5Bu);
    lift_store32(cpu->esp + 0x1D4u, cpu->edi);
    lift_store32(cpu->esp + 0x1D0u, cpu->ebx);
    lift_store8(cpu->esp + 0x1C0u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x12Cu)) < (uint32_t)(cpu->esi)) goto label_000B5F89;
    cpu->eax = lift_load32(cpu->esp + 0x118u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5F86u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5F89: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5F89u);
    lift_store32(cpu->esp + 0x12Cu, cpu->edi);
    lift_store32(cpu->esp + 0x128u, cpu->ebx);
    lift_store8(cpu->esp + 0x118u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x148u)) < (uint32_t)(cpu->esi)) goto label_000B5FB7;
    cpu->ecx = lift_load32(cpu->esp + 0x134u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5FB4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5FB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5FB7u);
    lift_store32(cpu->esp + 0x148u, cpu->edi);
    lift_store32(cpu->esp + 0x144u, cpu->ebx);
    lift_store8(cpu->esp + 0x134u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x19Cu)) < (uint32_t)(cpu->esi)) goto label_000B5FE5;
    cpu->edx = lift_load32(cpu->esp + 0x188u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B5FE2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B5FE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B5FE5u);
    lift_store32(cpu->esp + 0x19Cu, cpu->edi);
    lift_store32(cpu->esp + 0x198u, cpu->ebx);
    lift_store8(cpu->esp + 0x188u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0x204u, 0xFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0xF4u)) < (uint32_t)(cpu->esi)) goto label_000B601B;
    cpu->eax = lift_load32(cpu->esp + 0xE0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6018u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B601B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B601Bu);
    cpu->eax = lift_load32(cpu->esp + 0x150u);
    lift_store32(cpu->esp + 0xF4u, cpu->edi);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    lift_store8(cpu->esp + 0xE0u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x164u)) >= (uint32_t)(cpu->esi)) goto label_000B6047;
    cpu->eax = (uint32_t)(cpu->esp + 0x150u);
    label_000B6047: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6047u);
    lift_push32(cpu, 0x40u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6055u); lift_push32(cpu, r); sfera_sub_004B1830(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B606F;
    lift_store32(cpu->esp + 0xA4u, 2u);
    goto label_000B6081;
    label_000B606F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B606Fu);
    lift_store32(cpu->esp + 0xA4u, 0u);
    label_000B6081: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6081u);
    if ((uint32_t)((lift_load32(cpu->esp + 0xA4u)) & (6u)) != 0u) goto label_000B61EB;
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    cpu->ebp += 0x198u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B60BAu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B60C6u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(lift_load32(cpu->eax + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B61DD;
    label_000B60D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B60D8u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_000B60E4;
    cpu->ecx = 0u;
    goto label_000B60E6;
    label_000B60E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B60E4u);
    cpu->ecx = lift_load32(cpu->eax);
    label_000B60E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B60E6u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->esi)) goto label_000B60F1;
    cpu->eax -= cpu->edx;
    label_000B60F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B60F1u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x108u);
    lift_store32(cpu->esp + 0x11Cu, cpu->edi);
    lift_store32(cpu->esp + 0x118u, cpu->ebx);
    lift_store8(cpu->esp + 0x108u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B611Cu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0xFCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1A8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store8(cpu->esp + 0x20Cu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B613Du); lift_push32(cpu, r); sfera_sub_004B4B60(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_store8(cpu->esp + 0x204u, 0x11u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6150u); lift_push32(cpu, r); sfera_sub_004B1A80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)"\n";
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B615Cu); lift_push32(cpu, r); sfera_sub_004B1CB0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x1B8u)) < (uint32_t)(0x10u)) goto label_000B6176;
    cpu->edx = lift_load32(cpu->esp + 0x1A4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6173u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B6176: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6176u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x110u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1B8u, cpu->edi);
    lift_store32(cpu->esp + 0x1B4u, cpu->ebx);
    lift_store8(cpu->esp + 0x1A4u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0x204u, 0xFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B61AD;
    cpu->eax = lift_load32(cpu->esp + 0xFCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B61AAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B61AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B61ADu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x114u, cpu->edi);
    lift_store32(cpu->esp + 0x110u, cpu->ebx);
    lift_store8(cpu->esp + 0x100u, cpu->ebx & 0xFFu);
    ++cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B61CFu); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(lift_load32(cpu->eax + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B60D8;
    label_000B61DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B61DDu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B61E6u); lift_push32(cpu, r); sfera_sub_004B3B00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0x10u;
    label_000B61EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B61EBu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x164u)) < (uint32_t)(cpu->esi)) goto label_000B6204;
    cpu->edx = lift_load32(cpu->esp + 0x150u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6201u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B6204: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6204u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_store32(cpu->esp + 0x164u, cpu->edi);
    lift_store32(cpu->esp + 0x160u, cpu->ebx);
    lift_store8(cpu->esp + 0x150u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x204u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6230u); lift_push32(cpu, r); sfera_sub_004B3A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xB623Du);
    label_000B623D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B623Du);
    cpu->ecx = lift_load32(cpu->esp + 0x1FCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1F4u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B6270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6270u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x14u, cpu->esp);
    lift_push32(cpu, 1u);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B628Au); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B62B2;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B62B2;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000B62B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B62B2u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B62C5u); lift_push32(cpu, r); sfera_sub_004AFE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B62D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B62D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::HyperTextEditControl*>(cpu->esi));
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x4Bu)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x24u, 5u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B6315;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB6315u); lift_push32(cpu, r); sfera_sub_004B5D10(cpu,r); if (cpu->eip != r) return; }
    label_000B6315: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6315u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B631Cu); lift_push32(cpu, r); sfera_sub_004B3110(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    g_sfera_texture_cache_runtime.render_gate = (uint32_t)(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B632Fu); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x200u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B633Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x200u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1F8u)) < (uint32_t)(0x10u)) goto label_000B635C;
    cpu->eax = lift_load32(cpu->esi + 0x1E4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6359u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B635C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B635Cu);
    cpu->edi = 0xFu;
    lift_store32(cpu->esi + 0x1F8u, cpu->edi);
    lift_store32(cpu->esi + 0x1F4u, cpu->ebx);
    lift_store8(cpu->esi + 0x1E4u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1DCu)) < (uint32_t)(0x10u)) goto label_000B638B;
    cpu->eax = lift_load32(cpu->esi + 0x1C8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6388u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B638B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B638Bu);
    lift_store32(cpu->esi + 0x1DCu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x1B8u);
    lift_store32(cpu->esi + 0x1D8u, cpu->ebx);
    lift_store8(cpu->esi + 0x1C8u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x30u, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B63BFu); lift_push32(cpu, r); sfera_sub_004B2C40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B63C8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B63D6u); lift_push32(cpu, r); sfera_sub_004AF470(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B63E2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x198u, cpu->ebx);
    lift_store32(cpu->esp + 0x24u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B63FAu); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B6410(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6410u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x190u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1A4u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x1B4u);
    cpu->ebp = lift_load32(cpu->esp + 0x1BCu);
    cpu->edi = lift_load32(cpu->esp + 0x1B8u);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->ebp);
    if ((uint32_t)(lift_load32(cpu->esi + 0x9Cu)) != (uint32_t)(cpu->ebx)) goto label_000B6492;
    lift_push32(cpu, 0x2Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextEditControl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6489u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B648Fu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000B6492: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6492u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B649Eu); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"textColor");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B64ABu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B652C;
    cpu->esi = native_function_address32(&::sscanf);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xB64CFu), LIFT_CODE_TOKEN_RVA(0xB64CDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B64CFu);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000B6502;
    cpu->eax = lift_load32(cpu->ebp + 4u);
    cpu->ecx = lift_load32(cpu->ebp);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"textColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B64F9u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B64FFu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000B6502: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6502u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load8(cpu->esp + 0x28u);
    cpu->eax = lift_load8(cpu->esp + 0x20u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->eax;
    lift_store32(cpu->edx + 0x23Cu, cpu->ecx);
    goto label_000B653C;
    label_000B652C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B652Cu);
    lift_store32(cpu->esi + 0x23Cu, 0xFFFFFFFFu);
    cpu->esi = native_function_address32(&::sscanf);
    label_000B653C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B653Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"cursorColor");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6549u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B65C5;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xB6567u), LIFT_CODE_TOKEN_RVA(0xB6565u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6567u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000B659B;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"cursorColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6592u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6598u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000B659B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B659Bu);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load8(cpu->esp + 0x28u);
    cpu->ecx = lift_load8(cpu->esp + 0x20u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx |= cpu->ecx;
    lift_store32(cpu->eax + 0x238u, cpu->edx);
    goto label_000B65D3;
    label_000B65C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B65C5u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->ecx + 0x238u, 0xFFFFFFFFu);
    label_000B65D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B65D3u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"linkColor");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B65E0u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B665B;
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xB65FEu), LIFT_CODE_TOKEN_RVA(0xB65FCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B65FEu);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000B6631;
    cpu->eax = lift_load32(cpu->ebp + 4u);
    cpu->ecx = lift_load32(cpu->ebp);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"linkColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6628u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B662Eu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000B6631: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6631u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load8(cpu->esp + 0x28u);
    cpu->eax = lift_load8(cpu->esp + 0x20u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->eax;
    lift_store32(cpu->edx + 0x248u, cpu->ecx);
    goto label_000B6686;
    label_000B665B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B665Bu);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    cpu->ecx = lift_load32(cpu->ebp);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uintptr_t)"%s(): HyperTextEdit control must have '%s' parameter in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"linkColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B667Du); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6683u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000B6686: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6686u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"playerLinkColor");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6693u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B670E;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xB66B1u), LIFT_CODE_TOKEN_RVA(0xB66AFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B66B1u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000B66E5;
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->eax = lift_load32(cpu->ebp);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"playerLinkColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B66DCu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B66E2u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000B66E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B66E5u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load8(cpu->esp + 0x28u);
    cpu->edx = lift_load8(cpu->esp + 0x20u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax |= cpu->edx;
    lift_store32(cpu->ecx + 0x240u, cpu->eax);
    goto label_000B671E;
    label_000B670E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B670Eu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->eax + 0x248u);
    lift_store32(cpu->eax + 0x240u, cpu->edx);
    label_000B671E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B671Eu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"itemLinkColor");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B672Bu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B67A7;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xB6749u), LIFT_CODE_TOKEN_RVA(0xB6747u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6749u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000B677D;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"itemLinkColor"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6774u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B677Au); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000B677D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B677Du);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load8(cpu->esp + 0x28u);
    cpu->ecx = lift_load8(cpu->esp + 0x20u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx |= cpu->ecx;
    lift_store32(cpu->eax + 0x244u, cpu->edx);
    goto label_000B67B7;
    label_000B67A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B67A7u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->eax + 0x248u);
    lift_store32(cpu->eax + 0x244u, cpu->ecx);
    label_000B67B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B67B7u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"maxVisibleTextLength");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B67C4u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0x100u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B67E1;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B67D5u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edx + 0x24Cu, cpu->eax);
    goto label_000B67EB;
    label_000B67E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B67E1u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->eax + 0x24Cu, cpu->esi);
    label_000B67EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B67EBu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"maxHyperTextLength");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B67F8u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B6810;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6804u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->ecx + 0x250u, cpu->eax);
    goto label_000B681E;
    label_000B6810: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6810u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edx + 0x250u, 0xC00u);
    label_000B681E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B681Eu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"maxHistoryLength");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B682Bu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B6843;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6837u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->ecx + 0x1B4u, cpu->eax);
    goto label_000B684D;
    label_000B6843: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6843u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edx + 0x1B4u, cpu->esi);
    label_000B684D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B684Du);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"cursorType");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B685Au); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0xFu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B6A17;
    cpu->eax = (uint32_t)(cpu->esp + 0xA0u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6877u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B6A17;
    cpu->eax = (uint32_t)(cpu->esp + 0xA0u);
    lift_store32(cpu->esp + 0x98u, cpu->ebp);
    lift_store32(cpu->esp + 0x94u, cpu->ebx);
    lift_store8(cpu->esp + 0x84u, cpu->ebx & 0xFFu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000B68A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B68A0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B68A0;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xA4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x8Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B68BEu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"none");
    cpu->ecx = (uint32_t)(cpu->esp + 0x70u);
    lift_store32(cpu->esp + 0x1B4u, cpu->ebx);
    lift_store32(cpu->esp + 0x84u, cpu->ebp);
    lift_store32(cpu->esp + 0x80u, cpu->ebx);
    lift_store8(cpu->esp + 0x70u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B68E7u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x84u);
    lift_store8(cpu->esp + 0x1ACu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B68FFu); lift_push32(cpu, r); sfera_sub_0048DFB0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0x10u;
    lift_store8(cpu->esp + 0x17u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x1ACu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x7Cu)) < (uint32_t)(cpu->esi)) goto label_000B6922;
    cpu->edx = lift_load32(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B691Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B6922: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6922u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B6937;
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esi + 0x218u, cpu->ebx);
    goto label_000B69F0;
    label_000B6937: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6937u);
    lift_push32(cpu, 5u); lift_push32(cpu, (uintptr_t)"vline");
    cpu->ecx = (uint32_t)(cpu->esp + 0x70u);
    lift_store32(cpu->esp + 0x84u, cpu->ebp);
    lift_store32(cpu->esp + 0x80u, cpu->ebx);
    lift_store8(cpu->esp + 0x70u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6959u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x84u);
    lift_store8(cpu->esp + 0x1ACu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6971u); lift_push32(cpu, r); sfera_sub_0048DFB0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x17u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x1ACu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x7Cu)) < (uint32_t)(cpu->esi)) goto label_000B698F;
    cpu->eax = lift_load32(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B698Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B698F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B698Fu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B69A7;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->ecx + 0x218u, 1u);
    cpu->esi = cpu->ecx;
    goto label_000B69F0;
    label_000B69A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B69A7u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"uline");
    cpu->ecx = (uint32_t)(cpu->esp + 0x6Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B69B5u); lift_push32(cpu, r); sfera_sub_004090F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x84u);
    lift_store8(cpu->esp + 0x1ACu, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B69CDu); lift_push32(cpu, r); sfera_sub_0048DFB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x68u);
    lift_store8(cpu->esp + 0x17u, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B69DAu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x17u)), r=(uint64_t)((cpu->ebx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->eax;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    ++cpu->edx;
    lift_store32(cpu->eax + 0x218u, cpu->edx);
    label_000B69F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B69F0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x98u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1ACu, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B6A27;
    cpu->ecx = lift_load32(cpu->esp + 0x84u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6A12u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    goto label_000B6A27;
    label_000B6A17: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6A17u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edx + 0x218u, 1u);
    cpu->esi = cpu->edx;
    label_000B6A27: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6A27u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"editMode");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6A38u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B6CC3;
    cpu->ecx = (uint32_t)(cpu->esp + 0xA0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x38u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6A54u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B6CC3;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000B6A60: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6A60u);
    cpu->eax = (uint32_t)(cpu->esp + 0xA0u);
    lift_store32(cpu->esp + 0x98u, cpu->ebp);
    lift_store32(cpu->esp + 0x94u, cpu->ebx);
    lift_store8(cpu->esp + 0x84u, cpu->ebx & 0xFFu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000B6A80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6A80u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B6A80;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xA4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x8Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6A9Eu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xEu); lift_push32(cpu, (uintptr_t)"enterPlainText");
    cpu->ecx = (uint32_t)(cpu->esp + 0x70u);
    lift_store32(cpu->esp + 0x1B4u, 4u);
    lift_store32(cpu->esp + 0x84u, cpu->ebp);
    lift_store32(cpu->esp + 0x80u, cpu->ebx);
    lift_store8(cpu->esp + 0x70u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6ACBu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x84u);
    lift_store8(cpu->esp + 0x1ACu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6AE3u); lift_push32(cpu, r); sfera_sub_0048DFB0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x7Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x17u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x1ACu, 4u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B6B03;
    cpu->eax = lift_load32(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6B00u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B6B03: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6B03u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B6B2F;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6B1Eu); lift_push32(cpu, r); sfera_sub_004D23B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    goto label_000B6C74;
    label_000B6B2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6B2Fu);
    lift_push32(cpu, 0xBu); lift_push32(cpu, (uintptr_t)"numbersOnly");
    cpu->ecx = (uint32_t)(cpu->esp + 0x70u);
    lift_store32(cpu->esp + 0x84u, cpu->ebp);
    lift_store32(cpu->esp + 0x80u, cpu->ebx);
    lift_store8(cpu->esp + 0x70u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6B51u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x84u);
    lift_store8(cpu->esp + 0x1ACu, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6B69u); lift_push32(cpu, r); sfera_sub_0048DFB0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x7Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x17u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x1ACu, 4u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B6B89;
    cpu->eax = lift_load32(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6B86u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B6B89: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6B89u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B6BD3;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    cpu->esi += 0x1B8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6BA6u); lift_push32(cpu, r); sfera_sub_004D23B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6BB3u); lift_push32(cpu, r); sfera_sub_004043F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6BC8u); lift_push32(cpu, r); sfera_sub_004D23B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->ecx);
    goto label_000B6C72;
    label_000B6BD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6BD3u);
    lift_push32(cpu, 8u); lift_push32(cpu, (uintptr_t)"password");
    cpu->ecx = (uint32_t)(cpu->esp + 0x70u);
    lift_store32(cpu->esp + 0x84u, cpu->ebp);
    lift_store32(cpu->esp + 0x80u, cpu->ebx);
    lift_store8(cpu->esp + 0x70u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6BF5u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x84u);
    lift_store8(cpu->esp + 0x1ACu, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6C0Du); lift_push32(cpu, r); sfera_sub_0048DFB0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x7Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x17u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x1ACu, 4u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B6C2D;
    cpu->edx = lift_load32(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6C2Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B6C2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6C2Du);
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000B6C7D;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    cpu->esi += 0x1B8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6C4Au); lift_push32(cpu, r); sfera_sub_004D23B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6C57u); lift_push32(cpu, r); sfera_sub_004043F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6C6Cu); lift_push32(cpu, r); sfera_sub_004D23B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    label_000B6C72: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6C72u);
    cpu->ecx = cpu->esi;
    label_000B6C74: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6C74u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6C79u); lift_push32(cpu, r); sfera_sub_004043F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_000B6C7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6C7Du);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x98u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1ACu, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B6CA2;
    cpu->ecx = lift_load32(cpu->esp + 0x84u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6C9Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B6CA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6CA2u);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->edx = (uint32_t)(cpu->esp + 0xA0u);
    ++cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6CBBu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B6A60;
    label_000B6CC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6CC3u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1C0u)) != (uint32_t)(cpu->ebx)) goto label_000B6CF5;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6CE0u); lift_push32(cpu, r); sfera_sub_004D23B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6CF1u); lift_push32(cpu, r); sfera_sub_004043F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_000B6CF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6CF5u);
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"titleTextMargin");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6D06u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B6D6B;
    cpu->edx = (uint32_t)(cpu->esi + 0x234u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x230u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x22Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x228u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4B6D2Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6D35u);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(4u)) goto label_000B6D83;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"visibleTextMargin"); lift_push32(cpu, (uintptr_t)"SphereUI::HyperTextEditControl::LoadUI"); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6D60u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6D66u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    goto label_000B6D83;
    label_000B6D6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6D6Bu);
    lift_store32(cpu->esi + 0x228u, cpu->ebx);
    lift_store32(cpu->esi + 0x22Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x230u, cpu->ebx);
    lift_store32(cpu->esi + 0x234u, cpu->ebx);
    label_000B6D83: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6D83u);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6D8Fu); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6D96u); lift_push32(cpu, r); sfera_sub_004B57C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->esp + 0x1A4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x19Cu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B6DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6DD0u);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xD8u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, 0x1DB3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6E09u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x1F4u)) == (uint32_t)(0u)) goto label_000B6EFC;
    cpu->edi = lift_load32(cpu->esi + 0x1BCu);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_store32(cpu->esp + 0x18u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6E39u); lift_push32(cpu, r); sfera_sub_004B2440(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax)) != (uint32_t)(cpu->edi)) goto label_000B6EFC;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1A8u)) == (uint32_t)(0u)) goto label_000B6EDE;
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x18u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6E63u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->esp + 0x24u, cpu->esp);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6E78u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esi + 0x1E4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6E87u); lift_push32(cpu, r); sfera_sub_004B25C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6E97u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000B6EBB;
    cpu->edx = lift_load32(cpu->esi + 0x1A8u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi + 0x1B4u))) goto label_000B6EDE;
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6EB9u); lift_push32(cpu, r); sfera_sub_004AF510(cpu,r); if (cpu->eip != r) return; }
    goto label_000B6EDE;
    label_000B6EBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6EBBu);
    cpu->esp -= 0xCu;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x18u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6ECEu); lift_push32(cpu, r); sfera_sub_0048DD80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB6EDEu); lift_push32(cpu, r); sfera_sub_004B6270(cpu,r); if (cpu->eip != r) return; }
    label_000B6EDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6EDEu);
    cpu->edx = (uint32_t)(cpu->esi + 0x1E4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6EF0u); lift_push32(cpu, r); sfera_sub_004AF8A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    label_000B6EFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6EFCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B6F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6F10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6F18u); lift_push32(cpu, r); sfera_sub_004B62D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000B6F28;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6F25u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B6F28: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6F28u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B6F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6F30u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x6Cu);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x48u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000B7254;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6F7Cu); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6F8Au);
    cpu->ebx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->edx = 0u;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B6FB6;
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B6FB1u); lift_push32(cpu, r); sfera_sub_004A8A30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    label_000B6FB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B6FB6u);
    cpu->eax += lift_load32(cpu->edi + 0x34u);
    cpu->edx += lift_load32(cpu->edi + 0x30u);
    cpu->edi = lift_load32(cpu->esi + 0x30u);
    cpu->ebp = cpu->eax;
    cpu->ebp += lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->esi + 0x278u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->edi += cpu->edx;
    lift_store32(cpu->esi + 0x274u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi + 0xFFFFFFFFu);
    cpu->eax = (uint32_t)(cpu->edx + cpu->ebp + 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x4Au)) & 0xFFu);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B70B3;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 0x14u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B708F;
    if ((uint8_t)(lift_load8(cpu->ecx + 0x15u)) != (uint8_t)(0u)) goto label_000B708F;
    cpu->eax = cpu->eax & 0xFFu;
    cpu->eax += 0xFFFFFFF8u;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xB3u)) goto label_000B709F;
    switch ((uint32_t)(cpu->eax)) {
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
    label_000B702F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B702Fu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7036u); lift_push32(cpu, r); sfera_sub_004B3F60(cpu,r); if (cpu->eip != r) return; }
    goto label_000B709F;
    label_000B7038: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7038u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B703Fu); lift_push32(cpu, r); sfera_sub_004B4060(cpu,r); if (cpu->eip != r) return; }
    goto label_000B709F;
    label_000B7041: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7041u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7048u); lift_push32(cpu, r); sfera_sub_004B40D0(cpu,r); if (cpu->eip != r) return; }
    goto label_000B709F;
    label_000B704A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B704Au);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7051u); lift_push32(cpu, r); sfera_sub_004B4100(cpu,r); if (cpu->eip != r) return; }
    goto label_000B709F;
    label_000B7053: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7053u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B705Au); lift_push32(cpu, r); sfera_sub_004B4FB0(cpu,r); if (cpu->eip != r) return; }
    goto label_000B709F;
    label_000B705C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B705Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7063u); lift_push32(cpu, r); sfera_sub_004B5020(cpu,r); if (cpu->eip != r) return; }
    goto label_000B709F;
    label_000B7065: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7065u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B706Cu); lift_push32(cpu, r); sfera_sub_004B4140(cpu,r); if (cpu->eip != r) return; }
    goto label_000B709F;
    label_000B706E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B706Eu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7075u); lift_push32(cpu, r); sfera_sub_004B4180(cpu,r); if (cpu->eip != r) return; }
    goto label_000B709F;
    label_000B7077: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7077u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B707Eu); lift_push32(cpu, r); sfera_sub_004B6DD0(cpu,r); if (cpu->eip != r) return; }
    goto label_000B709F;
    label_000B7080: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7080u);
    if ((uint8_t)((lift_load8(cpu->ecx + 0x18u)) & (3u)) == 0u) goto label_000B709F;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B708Du); lift_push32(cpu, r); sfera_sub_004B5090(cpu,r); if (cpu->eip != r) return; }
    goto label_000B709F;
    label_000B708F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B708Fu);
    cpu->eax = lift_load8(cpu->ecx + 0x15u);
    if ((uint8_t)((cpu->eax & 0xFFu)) < (uint8_t)(0x20u)) goto label_000B709F;
    lift_push32(cpu, cpu->eax);
    label_000B7098: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7098u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB709Fu); lift_push32(cpu, r); sfera_sub_004B3D40(cpu,r); if (cpu->eip != r) return; }
    label_000B709F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B709Fu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store16(cpu->eax + 0x14u, 0u);
    g_sfera_texture_cache_runtime.render_gate = (uint32_t)(1u);
    label_000B70B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B70B3u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint8_t)((lift_load8(cpu->eax + 0xCu)) & (1u)) == 0u) goto label_000B7254;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->edi)) goto label_000B724A;
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x28u))) goto label_000B724A;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu)) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000B724A;
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x2Cu))) goto label_000B724A;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x4Au)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000B712E;
    lift_push32(cpu, 0xDu); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7102u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x11u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7116u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x17u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B712Au); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Au, 1u);
    label_000B712E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B712Eu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1D8u)) == (uint32_t)(0u)) goto label_000B7254;
    cpu->eax = lift_load32(cpu->esi + 0x254u);
    cpu->ecx = lift_load32(cpu->esi + 0x258u);
    cpu->ecx -= cpu->eax;
    ++cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B715Cu); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx -= lift_load32(cpu->esi + 0x228u);
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, 0u);
    cpu->ebx -= cpu->edi;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx -= 2u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x74u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7182u); lift_push32(cpu, r); sfera_sub_004B1F00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax += lift_load32(cpu->esi + 0x254u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esi + 0x21Cu, cpu->eax);
    lift_store32(cpu->esp + 0x64u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B719Fu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((uint8_t)((lift_load8(cpu->edx + 0x18u)) & (1u)) == 0u) goto label_000B7254;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x21Cu);
    cpu->edx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B71C8u); lift_push32(cpu, r); sfera_sub_0048E950(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B7254;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000B71E4;
    cpu->eax = lift_load32(cpu->esi + 0x210u);
    --cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_000B71E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B71E4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B71F0u); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B71F8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_000B7254;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B720Du); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7219u); lift_push32(cpu, r); sfera_sub_00431680(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x64u, 1u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B7229;
    cpu->eax = lift_load32(cpu->eax);
    label_000B7229: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7229u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0xFAu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7238u); lift_push32(cpu, r); sfera_sub_004A21F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B723Fu); lift_push32(cpu, r); sfera_sub_004A2670(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7248u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_000B7254;
    label_000B724A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B724Au);
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Au)) == (uint8_t)(0u)) goto label_000B7254;
    lift_store8(cpu->esi + 0x4Au, 0u);
    label_000B7254: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7254u);
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B7360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7360u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7370u); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->edi + 0x198u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7382u); lift_push32(cpu, r); sfera_sub_004B0EE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x1B0u);
    lift_store32(cpu->esi + 0x1B0u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1B4u);
    cpu->ebp = (uint32_t)(cpu->edi + 0x1B8u);
    cpu->ebx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_store32(cpu->esi + 0x1B4u, cpu->edx);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ebp)) goto label_000B73C5;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B73BDu); lift_push32(cpu, r); sfera_sub_004B2C40(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB73C5u); lift_push32(cpu, r); sfera_sub_004B2CF0(cpu,r); if (cpu->eip != r) return; }
    label_000B73C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B73C5u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->edi + 0x1C8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B73DBu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->edi + 0x1E4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1E4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B73F1u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->edi + 0x200u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7403u); lift_push32(cpu, r); sfera_sub_004AADE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x218u);
    lift_store32(cpu->esi + 0x218u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x21Cu);
    lift_store32(cpu->esi + 0x21Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x220u);
    lift_store32(cpu->esi + 0x220u, cpu->eax);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x224u)) & 0xFFu);
    lift_store8(cpu->esi + 0x224u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load32(cpu->edi + 0x228u);
    lift_store32(cpu->esi + 0x228u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x22Cu);
    lift_store32(cpu->esi + 0x22Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x230u);
    lift_store32(cpu->esi + 0x230u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x234u);
    lift_store32(cpu->esi + 0x234u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x238u);
    lift_store32(cpu->esi + 0x238u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x23Cu);
    lift_store32(cpu->esi + 0x23Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x240u);
    lift_store32(cpu->esi + 0x240u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x244u);
    lift_store32(cpu->esi + 0x244u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x248u);
    lift_store32(cpu->esi + 0x248u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x24Cu);
    lift_store32(cpu->esi + 0x24Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x250u);
    lift_store32(cpu->esi + 0x250u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x254u);
    lift_store32(cpu->esi + 0x254u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x258u);
    lift_store32(cpu->esi + 0x258u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x25Cu);
    lift_store32(cpu->esi + 0x25Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x260u);
    lift_store32(cpu->esi + 0x260u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x264u);
    lift_store32(cpu->esi + 0x264u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x268u);
    lift_store32(cpu->esi + 0x268u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x26Cu);
    lift_store32(cpu->esi + 0x26Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x270u);
    lift_store32(cpu->esi + 0x270u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x274u);
    lift_store32(cpu->esi + 0x274u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x278u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x278u, cpu->ecx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B7540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7540u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7571u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    cpu->edi = (uint32_t)(cpu->esi + 0x198u);
    std::construct_at(reinterpret_cast<SphereUI::HyperTextEditControl*>(cpu->esi));
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->edi, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0x40u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7595u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000B76F5;
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->edi + 4u, cpu->ebx);
    lift_store32(cpu->edi + 8u, cpu->ebx);
    lift_store32(cpu->edi + 0xCu, cpu->ebx);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_push32(cpu, 0x14u);
    lift_store8(cpu->esp + 0x40u, 2u);
    lift_store32(cpu->esi + 0x1C0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B75CDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000B76CB;
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1BCu);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1BCu);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x1BCu);
    lift_store8(cpu->ecx + 0x10u, 1u);
    cpu->edx = lift_load32(cpu->esi + 0x1BCu);
    lift_store8(cpu->edx + 0x11u, 1u);
    cpu->eax = 0xFu;
    lift_store32(cpu->esi + 0x1DCu, cpu->eax);
    lift_store32(cpu->esi + 0x1D8u, cpu->ebx);
    lift_store8(cpu->esi + 0x1C8u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x1F8u, cpu->eax);
    lift_store32(cpu->esi + 0x1F4u, cpu->ebx);
    lift_store8(cpu->esi + 0x1E4u, cpu->ebx & 0xFFu);
    cpu->edi = (uint32_t)(cpu->esi + 0x200u);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_store32(cpu->edi, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0x40u, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7647u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000B76A1;
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->edi + 4u, cpu->ebx);
    lift_store32(cpu->edi + 8u, cpu->ebx);
    lift_store32(cpu->edi + 0xCu, cpu->ebx);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x40u, 7u);
    lift_store32(cpu->esi + 0x254u, cpu->ebx);
    lift_store32(cpu->esi + 0x258u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7686u); lift_push32(cpu, r); sfera_sub_004B7360(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 4u, stop_address); return;
    label_000B76A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B76A1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB76CBu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000B76CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B76CBu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB76F5u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000B76F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B76F5u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B771Fu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4B771Fu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B7720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7720u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0x24u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperTextEditControl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7753u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x280u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B775Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B7789;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7778u); lift_push32(cpu, r); sfera_sub_004B7540(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000B7789: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7789u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B77A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B77A0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B77A8u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->eax = 0u;
    lift_store_f32(cpu->esi + 0x1A8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    lift_store8(cpu->esi + 0x19Cu, cpu->eax & 0xFFu);
    lift_store_f32(cpu->esi + 0x1B0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    lift_store8(cpu->esi + 0x1A4u, cpu->eax & 0xFFu);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    std::construct_at(reinterpret_cast<SphereUI::ImageCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x1ACu, 0xFFu);
    lift_store32(cpu->esi + 0x50u, 3u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B77F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B77F0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7809u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebp = 0u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"image");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->edi + 0x194u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7822u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B7875;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.image_value[0]); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7833u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B7875;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.image_value[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7847u); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x194u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_000B7875;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ebx);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.image_value[0]); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ImageCtrl::LoadUI(%s,%d,%d) -> Sprite '%s' not found.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B786Cu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7872u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    label_000B7875: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7875u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"alpha");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7882u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B7894;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B788Eu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x1ACu, cpu->eax);
    label_000B7894: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7894u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"imageStyle");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B78A1u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B7917;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->edi + 0x198u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B78B2u); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_000B7917;
    cpu->ebx = native_function_address32(&::_stricmp);
    label_000B78C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B78C0u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.image_value[0]); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B78CDu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B790A;
    lift_push32(cpu, (uintptr_t)"NOTIFY_LB"); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.image_value[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xB78DDu), LIFT_CODE_TOKEN_RVA(0xB78DBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B78DDu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B78EB;
    cpu->eax = 1u;
    goto label_000B7904;
    label_000B78EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B78EBu);
    lift_push32(cpu, (uintptr_t)"NOTIFY_FOCUS"); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.image_value[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xB78F7u), LIFT_CODE_TOKEN_RVA(0xB78F5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B78F7u);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFFFEu;
    cpu->eax += 2u;
    label_000B7904: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7904u);
    lift_store32(cpu->edi + 0x198u, (uint64_t)(lift_load32(cpu->edi + 0x198u)) | (uint64_t)(cpu->eax));
    label_000B790A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B790Au);
    cpu->ebp += 2u;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_000B78C0;
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    label_000B7917: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7917u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"rotate");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7924u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B794A;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7931u); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);

    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xA2Au);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::ImageCtrl*>(cpu->edi)->handleMessage(cpu);
    label_000B794A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B794Au);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7956u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B7970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7970u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000B7AE7;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000B79BE;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B79B0;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB79B0u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000B79B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B79B0u);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 8u);
    cpu->ecx += lift_load32(cpu->esp + 0xCu);
    label_000B79BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B79BEu);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x194u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B7AE7;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->eax |= 0xFFFFFFu;
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1A4u)) != (uint8_t)(0u)) goto label_000B7A7A;
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000B7A22;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000B7A22: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7A22u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->esp -= 0x10u;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x28u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000B7A4B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000B7A4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7A4Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->ecx = lift_load32(cpu->esi + 0x194u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7A75u); lift_push32(cpu, r); sfera_sub_004CE2B0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_000B7A7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7A7Au);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1A8u));
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->esp -= 0x14u;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000B7A97;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000B7A97: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7A97u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x28u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000B7ABD;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000B7ABD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7ABDu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->ecx = lift_load32(cpu->esi + 0x194u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB7AE7u); lift_push32(cpu, r); sfera_sub_004CEE60(cpu,r); if (cpu->eip != r) return; }
    label_000B7AE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7AE7u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B7AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7AF0u);
    cpu->esp -= 0x2Cu;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    if ((uint32_t)(lift_load32(cpu->esi + 0x198u)) == (uint32_t)(cpu->edi)) goto label_000B7C88;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->edi)) goto label_000B7B5A;
    cpu->ecx = lift_load32(cpu->ebx + 0x9Cu);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000B7B4C;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7B48u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_000B7B4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7B4Cu);
    cpu->eax = lift_load32(cpu->ebx + 0x30u);
    cpu->ecx = lift_load32(cpu->ebx + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0x14u);
    cpu->ecx += lift_load32(cpu->esp + 0xCu);
    label_000B7B5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7B5Au);
    cpu->edi = lift_load32(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi + 0x34u);
    cpu->edi += cpu->eax;
    cpu->eax = lift_load32(cpu->edx);
    cpu->ebp += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_000B7C4B;
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->ecx += cpu->edi;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000B7C4B;
    cpu->eax = lift_load32(cpu->edx + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000B7C4B;
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    cpu->ecx += cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000B7C4B;
    if ((uint8_t)(lift_load8(cpu->esi + 0x19Cu)) != (uint8_t)(0u)) goto label_000B7BD3;
    if ((uint8_t)((lift_load8(cpu->esi + 0x198u)) & (2u)) == 0u) goto label_000B7BD3;
    cpu->edx = lift_load32(cpu->esi + 0xD8u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_store32(cpu->esp + 0x28u, 0x67u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7BC8u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store8(cpu->esi + 0x19Cu, 1u);
    label_000B7BD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7BD3u);
    if ((uint8_t)((lift_load8(cpu->edx + 0xCu)) & (1u)) == 0u) goto label_000B7C86;
    if ((uint8_t)((lift_load8(cpu->esi + 0x198u)) & (1u)) == 0u) goto label_000B7C86;
    cpu->ecx = lift_load32(cpu->esi + 0xD8u);
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->ecx -= cpu->ebp;
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->edi;
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    lift_store32(cpu->esp + 0x28u, 0x3E9u);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7C21u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_interface_runtime.sounds_enabled) == (uint32_t)(0u)) goto label_000B7C86;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"Sounds\\in_click.wav";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7C36u); lift_push32(cpu, r); sfera_sub_00498060(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 4u, stop_address); return;
    label_000B7C4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7C4Bu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x19Cu)) == (uint8_t)(0u)) goto label_000B7C86;
    if ((uint8_t)((lift_load8(cpu->esi + 0x198u)) & (2u)) == 0u) goto label_000B7C86;
    cpu->eax = lift_load32(cpu->esi + 0xD8u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, 0x68u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7C7Fu); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x19Cu, 0u);
    label_000B7C86: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7C86u);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000B7C88: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7C88u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B7CA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7CA0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000B7CE6;
    lift_store32(cpu->esi + 0x194u, cpu->edi);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000B7CE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7CE6u);
    cpu->eax = lift_load32(cpu->esi + 0x194u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B7D05;
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4B7CF4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7CFAu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B7DA4;
    label_000B7D05: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7D05u);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esi + 0x194u, 0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B7D25;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7D1Fu); lift_push32(cpu, r); sfera_sub_004D2560(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x194u, cpu->eax);
    label_000B7D25: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7D25u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x194u)) != (uint32_t)(0u)) goto label_000B7DA4;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7D35u); lift_push32(cpu, r); sfera_sub_004B8360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x194u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B7DA4;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1A0u)) != (uint32_t)(cpu->eax)) goto label_000B7D8C;
    cpu->edx = 0x123u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ImageCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7D56u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x98u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7D60u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B7D7C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7D7Au); lift_push32(cpu, r); sfera_sub_004CDF00(cpu,r); if (cpu->eip != r) return; }
    goto label_000B7D7E;
    label_000B7D7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7D7Cu);
    cpu->eax = 0u;
    label_000B7D7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7D7Eu);
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    label_000B7D8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7D8Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7D98u); lift_push32(cpu, r); sfera_sub_004CF1F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    lift_store32(cpu->esi + 0x194u, cpu->eax);
    label_000B7DA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7DA4u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B7DC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7DC0u);
    cpu->esp -= 0xA4u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xB4u);
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFF5D7u);
    lift_store32(cpu->esp + 8u, cpu->edi);
    if ((uint32_t)(cpu->eax) > (uint32_t)(3u)) goto label_000B7ECE;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000B7E12;
        case 1u: goto label_000B7E5C;
        case 2u: goto label_000B7E00;
        case 3u: goto label_000B7E9C;
        default: lift_trap(cpu, 0x4B7DF9u, "resolved jump-table index out of range"); return;
    }
label_000B7E00: ;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7E08u); lift_push32(cpu, r); sfera_sub_004B7CA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    goto label_000B7EDF;
    label_000B7E12: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7E12u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000B7E24;
    lift_store32(cpu->esi + 0x194u, cpu->edi);
    cpu->eax = (uint32_t)(cpu->edi + 1u);
    goto label_000B7EDF;
    label_000B7E24: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7E24u);
    lift_push32(cpu, 0x9Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4B7E30u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7E35u);
    lift_push32(cpu, 0x40u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4B7E3Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7E43u);
    cpu->esp += 0x18u;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7E52u); lift_push32(cpu, r); sfera_sub_004B7CA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    goto label_000B7EDF;
    label_000B7E5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7E5Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esi + 0x1A8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000B7E7C;
    lift_store8(cpu->esi + 0x1A4u, 0u);
    goto label_000B7E83;
    label_000B7E7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7E7Cu);
    lift_store8(cpu->esi + 0x1A4u, 1u);
    label_000B7E83: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7E83u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (180.0));
    cpu->eax = 1u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    lift_store_f32(cpu->esi + 0x1A8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000B7EDF;
    label_000B7E9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7E9Cu);
    lift_store32(cpu->esi + 0x1ACu, cpu->edi);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0xFFu)) goto label_000B7EB4;
    lift_store32(cpu->esi + 0x1ACu, 0xFFu);
    label_000B7EB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7EB4u);

    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1B0u));

    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::ImageCtrl*>(cpu->esi)->setOpacity(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7EC7u);
    cpu->eax = 1u;
    goto label_000B7EDF;
    label_000B7ECE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7ECEu);
    cpu->eax = lift_load32(cpu->esp + 0xB8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB7EDFu); lift_push32(cpu, r); sfera_sub_004D2DD0(cpu,r); if (cpu->eip != r) return; }
    label_000B7EDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7EDFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xA4u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B7F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7F10u);
    cpu->eax = lift_load32(cpu->ecx + 0x1ACu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ecx + 0x1ACu)))));
    cpu->esp -= 8u;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000B7F29;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000B7F29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7F29u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store16(cpu->esp + 0xCu, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0xCu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->eax |= 0xC00u;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp, cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp));
    lift_store64(cpu->esp, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp);
    cpu->edx = lift_load32(cpu->ecx + 0x90u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFFFFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0xCu));
    lift_store32(cpu->ecx + 0xDCu, cpu->eax);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->edx |= cpu->eax;
    lift_store32(cpu->ecx + 0x90u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x98u);
    cpu->edx &= 0xFFFFFFu;
    cpu->edx |= cpu->eax;
    lift_store_f32(cpu->ecx + 0x1B0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ecx + 0x98u, cpu->edx);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B7F90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7F90u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::ImageCtrl*>(cpu->esi));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1A0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B7FF9;
    cpu->edx = 0x5Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ImageCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7FDFu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x1A0u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000B7FF9;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7FF0u); lift_push32(cpu, r); sfera_sub_004CF160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B7FF6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B7FF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B7FF9u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8008u); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x20u)) & (1u)) == 0u) goto label_000B8018;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8015u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B8018: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8018u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8030u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B803Eu); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x19Cu)) & 0xFFu);
    lift_store8(cpu->esi + 0x19Cu, cpu->ecx & 0xFFu);
    cpu->edx = lift_load32(cpu->edi + 0x1A0u);
    lift_store32(cpu->esi + 0x1A0u, cpu->edx);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1A4u)) & 0xFFu);
    lift_store8(cpu->esi + 0x1A4u, cpu->eax & 0xFFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1A8u));
    lift_store_f32(cpu->esi + 0x1A8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->edi + 0x1ACu);
    lift_store32(cpu->esi + 0x1ACu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1B0u));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->esi + 0x1B0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B80A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B80A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0xB5u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ImageCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B80D4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1B8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B80DEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B80FC;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B80F8u); lift_push32(cpu, r); sfera_sub_004B77A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000B80FE;
    label_000B80FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B80FCu);
    cpu->esi = 0u;
    label_000B80FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B80FEu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B810Eu); lift_push32(cpu, r); sfera_sub_004B8030(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_000B8136;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8128u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB8136u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000B8136: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8136u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8150u);
    { uint64_t l=(uint64_t)((*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[0])), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B8160;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B8160: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8160u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x2Eu); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_strrchr_address32(), LIFT_CODE_TOKEN_VA(0x4B8165u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B816Bu);
    cpu->ebx = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000B81AC;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->eax = cpu->edi;
    cpu->edx -= cpu->edi;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000B8180: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8180u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000B8180;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_font_runtime.language_suffix[0];
    cpu->edx = cpu->eax;
    label_000B8191: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8191u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000B8191;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_000B81A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B81A0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B81A0;
    cpu->esi = cpu->edx;
    goto label_000B8219;
    label_000B81AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B81ACu);
    cpu->esi = cpu->ebx;
    cpu->esi -= cpu->edi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4B81B7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B81BCu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_font_runtime.language_suffix[0];
    cpu->esp += 0xCu;
    lift_store8(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0]), 0u);
    cpu->ecx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000B81D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B81D0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000B81D0;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_000B81E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B81E1u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B81E1;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = cpu->ebx;
    lift_movs8(cpu, 1u);
    cpu->ecx = cpu->eax;
    label_000B8200: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8200u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000B8200;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_000B8211: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8211u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B8211;
    label_000B8219: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8219u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8230u);
    g_sfera_client_process_runtime.ui_bridge = (uint32_t)(cpu->ecx);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_07) = (uint32_t)(cpu->edx);
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.command_state) = (uint32_t)(0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8250u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = cpu->ecx;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08)) == (uint32_t)(0u)) goto label_000B82B4;
    cpu->esi = 0u;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09)) <= (uint32_t)(cpu->esi)) goto label_000B82B4;
    cpu->ebp = native_function_address32(&::_stricmp);
    cpu->edi = 0u;
    label_000B8292: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8292u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    cpu->eax = lift_load32(cpu->edi + cpu->eax);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0xB829Eu), LIFT_CODE_TOKEN_RVA(0xB829Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B829Eu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B831D;
    ++cpu->esi;
    cpu->edi += 0x98u;
    if ((uint32_t)(cpu->esi) < (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09))) goto label_000B8292;
    label_000B82B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B82B4u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B82BBu); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000B8347;
    cpu->edx = 0x2E9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B82D3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x98u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B82DDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000B82F7;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B82F5u); lift_push32(cpu, r); sfera_sub_004CDF00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    label_000B82F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B82F7u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8307u); lift_push32(cpu, r); sfera_sub_004CF1A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000B831D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B831Du);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x98u);
    lift_store32(cpu->esi + cpu->ecx + 0x8Cu, (uint64_t)(lift_load32(cpu->esi + cpu->ecx + 0x8Cu)) + 1u);
    cpu->eax = (uint32_t)(cpu->esi + cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000B8347: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8347u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8360u);
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B83A3;
    cpu->edi = 0u;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09)) <= (uint32_t)(cpu->edi)) goto label_000B83A3;
    cpu->ebx = native_function_address32(&::_stricmp);
    cpu->esi = 0u;
    label_000B8381: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8381u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    cpu->eax = lift_load32(cpu->esi + cpu->eax);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xB838Du), LIFT_CODE_TOKEN_RVA(0xB838Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B838Du);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B83AA;
    ++cpu->edi;
    cpu->esi += 0x98u;
    if ((uint32_t)(cpu->edi) < (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09))) goto label_000B8381;
    label_000B83A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B83A3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B83AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B83AAu);
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x98u);
    cpu->eax += (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B83C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B83C0u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B83D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B83D0u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    cpu->edx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000B8407;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(3u)) goto label_000B83F9;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(2u)) goto label_000B83F1;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(1u)) goto label_000B8407;
    lift_store8(cpu->eax + 8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 1u, cpu->edx & 0xFFu);
    lift_return(cpu, 0u, stop_address); return;
    label_000B83F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B83F1u);
    lift_store8(cpu->eax + 8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 1u, 1u);
    lift_return(cpu, 0u, stop_address); return;
    label_000B83F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B83F9u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(0xFFu)) goto label_000B8407;
    lift_store8(cpu->eax + 8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 1u, cpu->edx & 0xFFu);
    label_000B8407: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8407u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8430u);
    cpu->esp -= 0x1Cu;
    cpu->eax = cpu->ecx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000B8450;
    cpu->ecx = sfera_cursor_texture_name(cpu->eax);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000B8463;
    label_000B8450: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8450u);
    cpu->eax = 0u;
    cpu->edx = 0u;
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_000B8463: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8463u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8468u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8472u); lift_push32(cpu, r); sfera_sub_0044FC60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8490u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B849B;
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    label_000B849B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B849Bu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B84B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B84B0u);
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B8550;
    cpu->eax += 0xFFFFFFC0u;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xBFu)) goto label_000B8550;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: case 1u: goto label_000B84F6;
        case 2u: goto label_000B8515;
        case 3u: goto label_000B8534;
        case 191u: goto label_000B84DC;
        default: goto label_000B8550;
    }
label_000B84DC: ;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B84E9u); lift_push32(cpu, r); sfera_sub_004A1A20(cpu,r); if (cpu->eip != r) return; }
    g_sfera_interface_runtime.cursor_kind = (uint32_t)(0xFFu);
    lift_return(cpu, 4u, stop_address); return;
    label_000B84F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B84F6u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"curseye"); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8508u); lift_push32(cpu, r); sfera_sub_004A1A20(cpu,r); if (cpu->eip != r) return; }
    g_sfera_interface_runtime.cursor_kind = (uint32_t)(0x40u);
    lift_return(cpu, 4u, stop_address); return;
    label_000B8515: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8515u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"cursman"); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8527u); lift_push32(cpu, r); sfera_sub_004A1A20(cpu,r); if (cpu->eip != r) return; }
    g_sfera_interface_runtime.cursor_kind = (uint32_t)(0x42u);
    lift_return(cpu, 4u, stop_address); return;
    label_000B8534: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8534u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"cursman"); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8546u); lift_push32(cpu, r); sfera_sub_004A1A20(cpu,r); if (cpu->eip != r) return; }
    g_sfera_interface_runtime.cursor_kind = (uint32_t)(0x43u);
    label_000B8550: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8550u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8630u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B867A;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000B8656;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B864Bu); lift_push32(cpu, r); sfera_sub_004A1A20(cpu,r); if (cpu->eip != r) return; }
    g_sfera_ui_load_scratch_runtime.cursor_name[0] = (uint8_t)(0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000B8656: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8656u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8664u); lift_push32(cpu, r); sfera_sub_004A1A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)g_sfera_ui_load_scratch_runtime.cursor_name;
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000B8670: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8670u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000B8670;
    label_000B867A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B867Au);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8680u);
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B869F;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B869Eu); lift_push32(cpu, r); sfera_sub_004A1A20(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    label_000B869F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B869Fu);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B86B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B86B0u);
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B86CA;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B86C9u); lift_push32(cpu, r); sfera_sub_004A1AD0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    label_000B86CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B86CAu);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B86D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B86D0u);
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B86F3;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B86F2u); lift_push32(cpu, r); sfera_sub_004A1B00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    label_000B86F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B86F3u);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8700u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000B8737;
    if ((uint32_t)(lift_load32(cpu->esi + 0xD8u)) == (uint32_t)(0u)) goto label_000B8727;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"DestroWindowUI(%d) -> Can't destroy controls.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B871Eu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8724u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000B8727: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8727u);
    { uint64_t v=(uint64_t)(cpu->edi); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB8737u); lift_push32(cpu, r); sfera_sub_004D1E20(cpu,r); if (cpu->eip != r) return; }
    label_000B8737: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8737u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8740u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000B8747;
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_000B8747: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8747u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B874Du); lift_push32(cpu, r); sfera_sub_004D32C0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8750u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000B875F;
    label_000B875A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B875Au);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B875F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B875Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8764u); lift_push32(cpu, r); sfera_sub_004D1A00(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xCu)) goto label_000B875A;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8771u); lift_push32(cpu, r); sfera_sub_004BD940(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8780u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B8792;
    cpu->eax = lift_load32(cpu->ecx + 0x28u);
    lift_store32(cpu->edx, cpu->eax);
    cpu->ecx = lift_load32(cpu->ecx + 0x2Cu);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->edx, cpu->ecx);
    label_000B8792: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8792u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B87A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B87A0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B87B2;
    cpu->eax = lift_load32(cpu->ecx + 0x30u);
    lift_store32(cpu->edx, cpu->eax);
    cpu->ecx = lift_load32(cpu->ecx + 0x34u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->edx, cpu->ecx);
    label_000B87B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B87B2u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B87C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B87C0u);
    g_sfera_interface_runtime.cross_enabled = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B87D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B87D0u);
    g_sfera_interface_runtime.sounds_enabled = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B87E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B87E0u);
    cpu->eax = g_sfera_interface_runtime.sounds_enabled;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B87F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B87F0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)((lift_load8(cpu->esi + 0x40u)) & (1u)) == 0u) goto label_000B8807;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8804u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B8807: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8807u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->edx, 0u);
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    lift_store32(cpu->eax, 0u);
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    lift_store32(cpu->ecx, 0u);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->edx, 0u);
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_store32(cpu->eax, 0u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->ecx, 0u);
    lift_store32(cpu->esi + 0x40u, (uint64_t)(lift_load32(cpu->esi + 0x40u)) & (uint64_t)(0xFFFFFFFEu));
    lift_store32(cpu->esi + 0x3Cu, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8850u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = 0u;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08)) == (uint32_t)(cpu->edi)) goto label_000B88C4;
    cpu->edx = 0x216u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8895u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000B88BE;
    cpu->ecx = lift_load32(cpu->eax + 0xFFFFFFFCu);
    cpu->esi = (uint32_t)(cpu->eax + 0xFFFFFFFCu);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004CF160)); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x98u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B88B5u); lift_push32(cpu, r); sfera_sub_004EEB86(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B88BBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B88BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B88BEu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08) = (uint32_t)(cpu->edi);
    label_000B88C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B88C4u);
    cpu->edx = 0x21Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09) = (uint32_t)(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B88D9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x420u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B88E3u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000B88FD;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B88F9u); lift_push32(cpu, r); sfera_sub_00493BF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000B88FF;
    label_000B88FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B88FDu);
    cpu->esi = 0u;
    label_000B88FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B88FFu);
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x2Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8912u); lift_push32(cpu, r); sfera_sub_00494940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"sprite");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B891Fu); lift_push32(cpu, r); sfera_sub_00494030(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000B8A07;
    cpu->edx = 0x226u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8938u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0x98u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B895Cu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B8991;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004CF160)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004CDF00)); lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->eax + 4u);
    lift_push32(cpu, 0x98u); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->eax, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B898Au); lift_push32(cpu, r); sfera_sub_004EEBE9(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    goto label_000B8993;
    label_000B8991: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8991u);
    cpu->eax = 0u;
    label_000B8993: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8993u);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x2Cu, 0xFFFFFFFFu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08) = (uint32_t)(cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09) = (uint32_t)(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B89AFu); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"sprite");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B89C0u); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B8A00;
    cpu->edi = 0u;
    label_000B89D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B89D0u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edx);
    lift_push32(cpu, cpu->ebx);
    cpu->edi += 0x98u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B89EBu); lift_push32(cpu, r); sfera_sub_004CE8A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"sprite");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B89FCu); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B89D0;
    label_000B8A00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8A00u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB8A07u); lift_push32(cpu, r); sfera_sub_004948B0(cpu,r); if (cpu->eip != r) return; }
    label_000B8A07: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8A07u);
    cpu->edx = 0x234u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8A16u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == 0u) goto label_000B8A2A;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8A21u); lift_push32(cpu, r); sfera_sub_00493C00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8A27u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B8A2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8A2Au);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8A40u);
    cpu->esp -= 8u;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000B8A5C;
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_interface_core_runtime.text_object_ready)) != (uint8_t)((cpu->ecx & 0xFFu))) goto label_000B8A93;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    cpu->esp += 8u;
    sfera_sub_004CF750(cpu, stop_address); return;
    label_000B8A5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8A5Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 0xBB9u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8A6Eu); lift_push32(cpu, r); sfera_sub_004D0130(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8A73u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8A80u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esp);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB8A93u); lift_push32(cpu, r); sfera_sub_004CF770(cpu,r); if (cpu->eip != r) return; }
    label_000B8A93: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8A93u);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B8AA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8AA0u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B8AFF;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0x4924924u)) goto label_000B8AD1;
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->eax -= cpu->ecx;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B8ACAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B8AFF;
    label_000B8AD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8AD1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB8AFFu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000B8AFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8AFFu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B90A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B90A0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    cpu->ecx -= cpu->edi;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->esi = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B9114;
    cpu->ebx = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000B90D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B90D0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + cpu->edi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ebx + cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B90DC;
    cpu->eax = lift_load32(cpu->eax);
    label_000B90DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B90DCu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4B90DEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B90E4u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B911C;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    cpu->edi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    cpu->ecx -= cpu->edi;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    ++cpu->esi;
    cpu->ecx += cpu->edx;
    cpu->ebx += 0x38u;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ecx)) goto label_000B90D0;
    label_000B9114: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9114u);
    cpu->eax = (uint32_t)(cpu->edi + 0x1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B911C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B911Cu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi) * 8u));
    cpu->edi = lift_pop32(cpu);
    cpu->edx -= cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 8u) + 0x1Cu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9140u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9145u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000B914D;
    cpu->eax = lift_load32(cpu->eax);
    label_000B914D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B914Du);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9150u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B9185;
    cpu->eax = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B9185;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x64u);
    if ((uint32_t)(cpu->esi) <= (uint32_t)(cpu->eax)) goto label_000B9169;
    cpu->esi = cpu->eax;
    label_000B9169: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9169u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x68u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ecx + 0x54u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B9174;
    cpu->eax = lift_load32(cpu->eax);
    label_000B9174: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9174u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4B9177u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B917Du);
    cpu->esp += 0xCu;
    lift_store8(cpu->esi + cpu->edi, 0u);
    cpu->esi = lift_pop32(cpu);
    label_000B9185: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9185u);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9190u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B919Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B91C3;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B91BD;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_000B91BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B91BDu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_000B91C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B91C3u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B91F1u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4B91F1u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B92D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B92D0u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000B92D9;
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
    label_000B92D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B92D9u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000B932E;
    label_000B92E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B92E7u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000B92F2;
    cpu->eax = lift_load32(cpu->eax);
    label_000B92F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B92F2u);
    cpu->ecx = cpu->edi;
    label_000B92F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B92F4u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B9314;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_000B9310;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B9314;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000B92F4;
    label_000B9310: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9310u);
    cpu->eax = 0u;
    goto label_000B9319;
    label_000B9314: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9314u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000B9319: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9319u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B932A;
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000B92E7;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000B932A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B932Au);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000B9335;
    label_000B932E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B932Eu);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000B9335: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9335u);
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9350u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000B9380;
    cpu->ebx = native_function_address32(&::_stricmp);
    label_000B9366: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9366u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xB936Fu), LIFT_CODE_TOKEN_RVA(0xB936Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B936Fu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B9386;
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b))) goto label_000B9366;
    label_000B9380: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9380u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B9386: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9386u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9390u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000B93D2;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000B93A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B93A0u);
    cpu->edx = 0x1A8u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B93AFu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000B93C6;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B93BDu); lift_push32(cpu, r); sfera_sub_004A7A00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B93C3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000B93C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B93C6u);
    cpu->esi = lift_load32(cpu->esi);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->eax)) goto label_000B93A0;
    cpu->edi = lift_pop32(cpu);
    label_000B93D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B93D2u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    lift_store32(cpu->eax + 4u, cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b_cursor) = (uint32_t)(0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b))) goto label_000B9405;
    label_000B93F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B93F0u);
    cpu->esi = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B93F8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) != (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b))) goto label_000B93F0;
    label_000B9405: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9405u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9410(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9410u);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor)) <= (uint32_t)(0u)) goto label_000B9496;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_000B945B;
    label_000B9430: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9430u);
    cpu->edx = 0x273u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B943Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B944F;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000B944F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B944Fu);
    cpu->esi = lift_load32(cpu->esi);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_000B9430;
    label_000B945B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B945Bu);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor) = (uint32_t)(0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a))) goto label_000B9495;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000B9480: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9480u);
    cpu->esi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9488u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->esi) != (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a))) goto label_000B9480;
    label_000B9495: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9495u);
    cpu->esi = lift_pop32(cpu);
    label_000B9496: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9496u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B94A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B94A0u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000B9534;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000B94B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B94B4u);
    cpu->edi = lift_load32(cpu->eax + 8u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0xD8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B94DC;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"DestroWindowUI(0x%X) -> Can't destroy controls.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B94CDu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B94D3u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esp += 0xCu;
    label_000B94DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B94DCu);
    cpu->esi = lift_load32(cpu->ecx);
    cpu->ebp = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_000B950A;
    label_000B94E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B94E4u);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) != (uint32_t)(cpu->edi)) goto label_000B9504;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->esi + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B94F9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.list_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u);
    goto label_000B9506;
    label_000B9504: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9504u);
    cpu->esi = lift_load32(cpu->esi);
    label_000B9506: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9506u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebp)) goto label_000B94E4;
    label_000B950A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B950Au);
    cpu->edx = 0x283u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9519u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9524u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = cpu->ebx;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->ecx)) goto label_000B94B4;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000B9534: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9534u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9540u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x64u)) goto label_000B9614;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x3E9u)) goto label_000B95DD;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xA90u)) goto label_000B95C1;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B956Bu); lift_push32(cpu, r); sfera_sub_004AEE90(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B959B;
    lift_push32(cpu, (uint32_t)(uintptr_t)"Language\\helpindex.hts");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B957Bu); lift_push32(cpu, r); sfera_sub_004AEE90(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4B957Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9582u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000B959B;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0xA91u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000B959B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B959Bu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B95A2u); lift_push32(cpu, r); sfera_sub_004AF340(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    lift_push32(cpu, 0u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000B95C3;
    cpu->eax = lift_load32(cpu->edi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000B95C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B95C1u);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B95C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B95C3u);
    cpu->ecx = lift_load32(cpu->edi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B95DBu);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B95DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B95DDu);
    cpu->edx = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B9607;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B95C1;
    cpu->ecx = lift_load32(cpu->edi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0xA8Du);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9605u);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B9607: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9607u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"Language\\helpindex.hts";
    cpu->edi = lift_pop32(cpu);
    sfera_sub_004BAD10(cpu, stop_address); return;
    label_000B9614: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9614u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu);
    sfera_sub_004BAD10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9620u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9650u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_interface_runtime.primary_gate), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = g_sfera_screen_clip_runtime.top;
    cpu->ecx = g_sfera_screen_clip_runtime.bottom;
    cpu->edi = g_sfera_screen_clip_runtime.left;
    cpu->ebp = g_sfera_screen_clip_runtime.right;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000B96B2;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000B9698;
    label_000B9683: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9683u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B968Du);
    cpu->esi = lift_load32(cpu->esi);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->eax)) goto label_000B9683;
    label_000B9698: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9698u);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000B96B2;
    cpu->edi = cpu->edi;
    label_000B96A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B96A0u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B96A8u); lift_push32(cpu, r); sfera_sub_004D2810(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head))) goto label_000B96A0;
    label_000B96B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B96B2u);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_interface_core_runtime.text_object_ready)) != (uint8_t)(0u)) goto label_000B96C5;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB96C5u); lift_push32(cpu, r); sfera_sub_004CFA00(cpu,r); if (cpu->eip != r) return; }
    label_000B96C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B96C5u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B97D8;
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0u)) goto label_000B97D8;
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    cpu->edx = g_sfera_graphics_runtime.display_width;
    cpu->esi |= 0xFFFFFFFFu;
    { uint64_t l=(uint64_t)((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    g_sfera_screen_clip_runtime.left = (uint32_t)(0u);
    g_sfera_screen_clip_runtime.top = (uint32_t)(0u);
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->ecx);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B973D;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.initialized_flags, (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(1u));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    lift_store32(cpu->esp + 0x28u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B972Cu); lift_push32(cpu, r); sfera_sub_004D79F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA360));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9736u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    label_000B973D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B973Du);
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000B9757;
    cpu->ecx = (uint32_t)(uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9751u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    label_000B9757: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9757u);

    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9763u);
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & (1u)) != 0u) goto label_000B9796;
    cpu->eax = 1u;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.initialized_flags, (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(cpu->eax));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9785u); lift_push32(cpu, r); sfera_sub_004D79F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA360));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B978Fu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    label_000B9796: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9796u);
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000B97B0;
    cpu->ecx = (uint32_t)(uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B97AAu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    label_000B97B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B97B0u);

    reinterpret_cast<CCursor*>(cpu->ecx)->isInsideViewport(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B97B7u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000B97D8;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB97D8u); lift_push32(cpu, r); sfera_sub_004A1B70(cpu,r); if (cpu->eip != r) return; }
    label_000B97D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B97D8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->ecx);
    cpu->ecx = 0u;
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->edi);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->ebp);
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B97FFu); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9820u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000B9849;
    if ((uint32_t)(cpu->edx) != 0u) goto label_000B982B;
    cpu->eax = cpu->ecx;
    lift_return(cpu, 0u, stop_address); return;
    label_000B982B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B982Bu);
    cpu->eax = lift_load32(cpu->ecx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edx) <= (uint32_t)(1u)) goto label_000B9845;
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFFFu);
    label_000B9840: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9840u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000B9840;
    label_000B9845: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9845u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_return(cpu, 0u, stop_address); return;
    label_000B9849: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9849u);
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9850u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000B9895;
    cpu->ebx = native_function_address32(&::_stricmp);
    label_000B9870: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9870u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->eax += 0x178u;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000B9880;
    cpu->eax = lift_load32(cpu->eax);
    label_000B9880: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9880u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xB9884u), LIFT_CODE_TOKEN_RVA(0xB9882u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9884u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B989B;
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a))) goto label_000B9870;
    label_000B9895: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9895u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000B989B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B989Bu);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B98B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B98B0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B98BCu); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B98CAu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->ebp = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_000B995B;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    (void)cpu;
    label_000B98E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B98E0u);
    cpu->edi = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edi + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000B9941;
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Fu)) != (uint8_t)(0u)) goto label_000B9941;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000B9915;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xB9915u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000B9915: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9915u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(cpu->ebx)) goto label_000B9941;
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000B9941;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(cpu->eax)) goto label_000B9941;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_000B9951;
    label_000B9941: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9941u);
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_000B98E0;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000B9951: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9951u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000B995B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B995Bu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B9970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9970u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000B99B8;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000B99B3;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000B9990: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9990u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->dispatchMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B99A7u);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head))) goto label_000B9990;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000B99B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B99B3u);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_000B99B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B99B8u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->dispatchMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B99D4u);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004B99E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B99E0u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    cpu->ecx = lift_load32(cpu->edx);
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000B9A05;
    lift_push32(cpu, cpu->esi);
    (void)cpu;
    label_000B99F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B99F0u);
    cpu->esi = lift_load32(cpu->ecx + 0x18u);
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->eax = (uint32_t)(cpu->eax + cpu->esi + 9u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_000B99F0;
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B9A05;
    cpu->eax += 4u;
    label_000B9A05: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9A05u);
    lift_return(cpu, 0u, stop_address); return;
}
