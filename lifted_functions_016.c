#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

static uint32_t sfera_zoning_config_error_context(void) { return (uint32_t)(uintptr_t)"Wrong format of \"Landscape\\zoning.cfg\""; }

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049DF00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49DF00u);
    cpu->esp -= 0x15Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x16Cu);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DF2Au); lift_push32(cpu, r); sfera_sub_004815D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DF31u); lift_push32(cpu, r); sfera_sub_00482170(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->edx = (uint32_t)(uintptr_t)"zonesParams";
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DF43u); lift_push32(cpu, r); sfera_sub_004811B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0009E45D;
    label_0009DF51: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DF51u);
    lift_push32(cpu, 0x148u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x49DF5Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49DF62u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(uintptr_t)"zonesParams";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DF72u); lift_push32(cpu, r); sfera_sub_00481300(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((uint32_t)(cpu->edi) != 0u) goto label_0009DF8F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : zoneParamsCfg is NULL");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DF8Cu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0009DF8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DF8Fu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(uintptr_t)"xPatchMin";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DFA0u); lift_push32(cpu, r); sfera_sub_00481150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009DFB7;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"xPatchMin\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DFB4u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0009DFB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DFB7u);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)"zPatchMin";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DFC8u); lift_push32(cpu, r); sfera_sub_00481150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009DFDF;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"zPatchMin\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DFDCu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0009DFDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DFDFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(uintptr_t)"xMin";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DFF0u); lift_push32(cpu, r); sfera_sub_00481150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E007;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"xMin\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E004u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0009E007: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E007u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(uintptr_t)"xMax";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E018u); lift_push32(cpu, r); sfera_sub_00481150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E02F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"xMax\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E02Cu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0009E02F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E02Fu);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)"zMin";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E040u); lift_push32(cpu, r); sfera_sub_00481150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E057;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"zMin\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E054u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0009E057: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E057u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(uintptr_t)"zMax";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E068u); lift_push32(cpu, r); sfera_sub_00481150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E07F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"zMax\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E07Cu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0009E07F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E07Fu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(uintptr_t)"borderFadeDist";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E090u); lift_push32(cpu, r); sfera_sub_00481150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E0A7;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"borderFadeDist\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E0A4u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0009E0A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E0A7u);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)"skyFogAlpha";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E0B8u); lift_push32(cpu, r); sfera_sub_00481150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E0CF;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"skyFogAlpha\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E0CCu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0009E0CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E0CFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(uintptr_t)"fogNear";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E0E0u); lift_push32(cpu, r); sfera_sub_00481150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E0F7;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogNear\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E0F4u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0009E0F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E0F7u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(uintptr_t)"fogFar";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E108u); lift_push32(cpu, r); sfera_sub_00481150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E11F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogFar\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E11Cu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0009E11F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E11Fu);
    cpu->edx = (uint32_t)(uintptr_t)"dayColors";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E12Bu); lift_push32(cpu, r); sfera_sub_004811B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(8u)) goto label_0009E143;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : wrong size of \"dayColors\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E140u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0009E143: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E143u);
    cpu->esi = 0u;
    cpu->ebx = (uint32_t)(cpu->esp + 0x4Cu);
    goto label_0009E154;
    label_0009E150: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E150u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    label_0009E154: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E154u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(uintptr_t)"dayColors";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E161u); lift_push32(cpu, r); sfera_sub_00481300(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_0009E17A;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : dayColorCfg is NULL");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E177u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0009E17A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E17Au);
    cpu->edx = (uint32_t)(cpu->ebx + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(uintptr_t)"fogColor";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E18Cu); lift_push32(cpu, r); sfera_sub_00481250(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E1A4;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogColor[%d].r\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E1A1u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0009E1A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E1A4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(uintptr_t)"fogColor";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E1B3u); lift_push32(cpu, r); sfera_sub_00481250(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E1CB;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogColor[%d].g\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E1C8u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0009E1CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E1CBu);
    cpu->eax = (uint32_t)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(uintptr_t)"fogColor";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E1DDu); lift_push32(cpu, r); sfera_sub_00481250(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E1F5;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogColor[%d].b\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E1F2u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0009E1F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E1F5u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x5Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(uintptr_t)"ambientColor";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E207u); lift_push32(cpu, r); sfera_sub_00481250(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E21F;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"ambientColor[%d].r\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E21Cu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0009E21F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E21Fu);
    cpu->edx = (uint32_t)(cpu->ebx + 0x60u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(uintptr_t)"ambientColor";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E231u); lift_push32(cpu, r); sfera_sub_00481250(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E249;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"ambientColor[%d].g\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E246u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0009E249: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E249u);
    cpu->eax = (uint32_t)(cpu->ebx + 0x64u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(uintptr_t)"ambientColor";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E25Bu); lift_push32(cpu, r); sfera_sub_00481250(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E273;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"ambientColor[%d].b\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E270u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0009E273: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E273u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0xBCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(uintptr_t)"sunColor";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E288u); lift_push32(cpu, r); sfera_sub_00481250(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E2A0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"sunColor[%d].r\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E29Du); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0009E2A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E2A0u);
    cpu->edx = (uint32_t)(cpu->ebx + 0xC0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(uintptr_t)"sunColor";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E2B5u); lift_push32(cpu, r); sfera_sub_00481250(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E2CD;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"sunColor[%d].g\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E2CAu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0009E2CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E2CDu);
    cpu->eax = (uint32_t)(cpu->ebx + 0xC4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(uintptr_t)"sunColor";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E2E2u); lift_push32(cpu, r); sfera_sub_00481250(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009E2FA;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"sunColor[%d].b\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E2F7u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0009E2FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E2FAu);
    ++cpu->esi;
    cpu->ebx += 0xCu;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(8u)) goto label_0009E150;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->ecx)) goto label_0009E3C6;
    cpu->ebx = lift_load32(cpu->edi);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->ebx) > (uint32_t)(cpu->eax)) goto label_0009E3C6;
    cpu->edi = lift_load32(cpu->edi + 8u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x63E7063Fu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edi)) goto label_0009E3A0;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x63E7063Fu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0xC7CE0Bu)) goto label_0009E47F;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->eax = 0x63E7063Fu;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    ++cpu->ecx;
    cpu->eax += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0009E3A0;
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->edi = 0xC7CE0Cu;
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_0009E38A;
    cpu->eax = 0u;
    goto label_0009E38C;
    label_0009E38A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E38Au);
    cpu->eax += cpu->edx;
    label_0009E38C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E38Cu);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_0009E392;
    cpu->eax = cpu->ecx;
    label_0009E392: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E392u);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E39Eu); lift_push32(cpu, r); sfera_sub_0049DCD0(cpu,r); if (cpu->eip != r) return; }
    goto label_0009E3A4;
    label_0009E3A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E3A0u);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_0009E3A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E3A4u);
    cpu->edi = lift_load32(cpu->ebx + 4u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x148u);
    cpu->esi += lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0009E3BA;
    cpu->ecx = 0x52u;
    lift_movs32(cpu, 1u);
    label_0009E3BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E3BAu);
    lift_store32(cpu->ebx + 4u, (uint64_t)(lift_load32(cpu->ebx + 4u)) + (uint64_t)(0x148u) + (uint64_t)(0u));
    goto label_0009E44E;
    label_0009E3C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E3C6u);
    cpu->esi = lift_load32(cpu->edi + 8u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_0009E42F;
    cpu->edi = lift_load32(cpu->edi);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x63E7063Fu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0xC7CE0Bu)) goto label_0009E47F;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->eax = 0x63E7063Fu;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    ++cpu->ecx;
    cpu->eax += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0009E42B;
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->esi = 0xC7CE0Cu;
    cpu->esi -= cpu->edx;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->eax)) goto label_0009E419;
    cpu->eax = 0u;
    goto label_0009E41B;
    label_0009E419: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E419u);
    cpu->eax += cpu->edx;
    label_0009E41B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E41Bu);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_0009E421;
    cpu->eax = cpu->ecx;
    label_0009E421: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E421u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9E42Bu); lift_push32(cpu, r); sfera_sub_0049DCD0(cpu,r); if (cpu->eip != r) return; }
    label_0009E42B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E42Bu);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    label_0009E42F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E42Fu);
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009E447;
    cpu->ecx = 0x52u;
    cpu->esi = (uint32_t)(cpu->esp + 0x20u);
    cpu->edi = cpu->eax;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    label_0009E447: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E447u);
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) + (uint64_t)(0x148u) + (uint64_t)(0u));
    label_0009E44E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E44Eu);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0009DF51;
    label_0009E45D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E45Du);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E464u); lift_push32(cpu, r); sfera_sub_004815C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x15Cu;
    lift_return(cpu, 4u, stop_address); return;
    label_0009E47F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E47Fu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    lift_trap(cpu, 0x49E48Au, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049E490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49E490u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_0009E4D7;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edi)) goto label_0009E4D7;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0009E4B8;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9E4B8u); lift_push32(cpu, r); sfera_sub_0049DEA0(cpu,r); if (cpu->eip != r) return; }
    label_0009E4B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E4B8u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 8u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009E4F6;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(8u) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0009E4D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E4D7u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0009E4E5;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9E4E5u); lift_push32(cpu, r); sfera_sub_0049DEA0(cpu,r); if (cpu->eip != r) return; }
    label_0009E4E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E4E5u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009E4F6;
    cpu->ecx = lift_load32(cpu->edi);
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009E4F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E4F6u);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(8u) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049E500(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49E500u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x7Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x90u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0xB4u);
    cpu->edi = lift_load32(cpu->esp + 0xB0u);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    cpu->eax = 0x63E7063Fu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009E56E;
    lift_push32(cpu, (uint32_t)(uintptr_t)"Error in ZoningMgr::calc_params() : zonesParams is Empty");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E56Bu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009E56E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E56Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xACu));
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E58Fu); lift_push32(cpu, r); sfera_sub_0049D780(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xACu));
    cpu->edx = (uint32_t)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x84u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E5AEu); lift_push32(cpu, r); sfera_sub_00495490(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x84u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E5C2u); lift_push32(cpu, r); sfera_sub_0049DA20(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->esp + 0xA0u)) != (uint8_t)(0u)) goto label_0009E6B4;
    cpu->ecx = 0u;
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    cpu->edi = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x63E7063Fu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x98u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009E69C;
    label_0009E607: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E607u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA8u));
    cpu->edi += cpu->ebp;
    lift_push32(cpu, cpu->edi);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E629u); lift_push32(cpu, r); sfera_sub_0049D910(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.009999999776482582f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0009E66B;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E658u); lift_push32(cpu, r); sfera_sub_0049E490(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.9900000095367432);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0009E694;
    goto label_0009E66D;
    label_0009E66B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E66Bu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009E66D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E66Du);
    cpu->edi = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x63E7063Fu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    ++cpu->ebx;
    cpu->eax += cpu->edx;
    cpu->ebp += 0x148u;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->eax)) goto label_0009E607;
    label_0009E694: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E694u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    label_0009E69C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E69Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edi = cpu->ecx;
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_0009E6FD;
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0009E6B4;
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E6B1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009E6B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E6B4u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    cpu->edi = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->eax);
    cpu->eax = 0x63E7063Fu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x148u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->edi + 0xFFFFFEB8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E6F8u); lift_push32(cpu, r); sfera_sub_0049D820(cpu,r); if (cpu->eip != r) return; }
    goto label_0009EC4A;
    label_0009E6FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E6FDu);
    if ((uint32_t)(cpu->edi) != (uint32_t)(1u)) goto label_0009E731;
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x148u);
    cpu->eax += lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49E72Cu); lift_push32(cpu, r); sfera_sub_0049D820(cpu,r); if (cpu->eip != r) return; }
    goto label_0009EC41;
    label_0009E731: cpu->eip = LIFT_CODE_TOKEN_VA(0x49E731u);
    cpu->ebx = lift_load32(cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->edi) * 8u) + 0xFFFFFFF4u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->ebp + ((uint32_t)(cpu->edi) * 8u) + 0xFFFFFFF0u);
    cpu->ecx = lift_load32(cpu->ebp + ((uint32_t)(cpu->edi) * 8u) + 0xFFFFFFF8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x148u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + cpu->ebx + 0x1Cu));
    cpu->esi += cpu->ebx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x148u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + cpu->ebx + 0x1Cu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + cpu->ebx + 0x1Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->ecx += cpu->ebx;
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 0x20u))));
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0x20u))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 0x24u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0x24u))));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x28u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ecx + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x2Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x30u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x30u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->esi + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->esi + 0x28u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->esi + 0x28u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->esi + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->esi + 0x2Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->esi + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->esi + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->esi + 0x30u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->esi + 0x30u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x88u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x88u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x88u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x8Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x8Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x8Cu))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x90u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x90u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x90u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->esi + 0x88u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->esi + 0x88u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->esi + 0x88u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->esi + 0x8Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->esi + 0x8Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->esi + 0x8Cu))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->esi + 0x90u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->esi + 0x90u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->esi + 0x90u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0xE8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0xE8u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0xE8u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0xECu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0xECu))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0xF0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0xF0u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0xF0u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->esi + 0xE8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->esi + 0xE8u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->esi + 0xE8u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->esi + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->esi + 0xECu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->esi + 0xECu))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->esi + 0xF0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->esi + 0xF0u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->esi + 0xF0u))));
    cpu->esi = (uint32_t)(cpu->edi + 0xFFFFFFFDu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0009EC2C;
    label_0009EA30: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EA30u);
    cpu->ecx = lift_load32(cpu->ebp + ((uint32_t)(cpu->esi) * 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->esi) * 8u) + 4u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x148u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + cpu->ebx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx += cpu->ebx;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x28u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x28u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x2Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x30u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x30u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x88u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x88u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x88u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x8Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x8Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x8Cu))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x90u));
    { uint64_t l=(uint64_t)(cpu->esi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x90u))));
    cpu->edi = (uint32_t)(cpu->eax + cpu->ecx + 0xF0u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x90u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0xE8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0xE8u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0xE8u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0xECu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + cpu->ecx + 0xECu))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0xF0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x68u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x70u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0009EA30;
    label_0009EC2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EC2Cu);
    cpu->edi = lift_load32(cpu->esp + 0x34u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 0xCu;
    cpu->esi = (uint32_t)(cpu->esp + 0x44u);
    lift_movs32(cpu, 1u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0009EC4A;
    label_0009EC41: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EC41u);
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EC47u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009EC4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EC4Au);
    cpu->ecx = lift_load32(cpu->esp + 0x90u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x88u;
    lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049EC80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49EC80u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_0009ECA9;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9ECA9u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_0009ECA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49ECA9u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x34u);
    cpu->edx += lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049ECD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49ECD0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0009ECDB;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009ECDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x49ECDBu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"LOSTCHECK"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9ECEAu), LIFT_CODE_TOKEN_RVA(0x9ECE8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49ECEAu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009ECF9;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 2u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009ECF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49ECF9u);
    lift_push32(cpu, (uintptr_t)"NOTIFY_LB"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9ED01u), LIFT_CODE_TOKEN_RVA(0x9ECFFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49ED01u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009ED10;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009ED10: cpu->eip = LIFT_CODE_TOKEN_VA(0x49ED10u);
    lift_push32(cpu, (uintptr_t)"SEND_QUIT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9ED18u), LIFT_CODE_TOKEN_RVA(0x9ED16u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49ED18u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009ED27;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 8u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009ED27: cpu->eip = LIFT_CODE_TOKEN_VA(0x49ED27u);
    lift_push32(cpu, (uintptr_t)"CENTER_TEXT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9ED2Fu), LIFT_CODE_TOKEN_RVA(0x9ED2Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49ED2Fu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009ED3E;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0x10u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009ED3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49ED3Eu);
    lift_push32(cpu, (uintptr_t)"SEND_HELP"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9ED46u), LIFT_CODE_TOKEN_RVA(0x9ED44u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49ED46u);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFFE0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 0x20u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049ED60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49ED60u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49ED68u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)0.05000000074505806f);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    std::construct_at(reinterpret_cast<SphereUI::ButtonCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    lift_store_f32(cpu->esi + 0x1BCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->esi + 0x1B8u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x1C0u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x50u, 1u);
    lift_store32(cpu->esi + 0x118u, 0xCu);
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049EDE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49EDE0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EDF9u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->edi + 0x9Cu)) != (uint32_t)(0u)) goto label_0009EE1F;
    lift_push32(cpu, 0x84u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Button.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EE16u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EE1Cu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0009EE1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EE1Fu);
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"checkedImage");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EE30u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009EE7D;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EE42u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009EE7D;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EE56u); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x1A0u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009EE7D;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ButtonCtrl::LoadUI(%s) -> Can't find sprite '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EE74u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EE7Au); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0009EE7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EE7Du);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"focusedImage");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EE8Au); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009EED9;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EE9Cu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009EED9;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EEB0u); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x1A4u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009EED9;
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"ButtonCtrl::LoadUI(%s) -> Can't find sprite '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EECEu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EED4u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    goto label_0009EEDD;
    label_0009EED9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EED9u);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    label_0009EEDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EEDDu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"disabledImage");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EEEAu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009EF33;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EEFCu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009EF33;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EF10u); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x1C4u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009EF33;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"ButtonCtrl::LoadUI(%s) -> Can't find sprite '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EF2Au); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EF30u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0009EF33: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EF33u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"uncheckedImage");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EF40u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009EF89;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EF52u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009EF89;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EF66u); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x19Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009EF89;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"ButtonCtrl::LoadUI(%s) -> Can't find sprite '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EF80u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EF86u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0009EF89: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EF89u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"buttonStyle");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EF96u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009EFDC;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EFA1u); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_0009EFD8;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0009EFB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EFB0u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EFBDu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009EFD1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EFCBu); lift_push32(cpu, r); sfera_sub_0049ECD0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x1A8u, (uint64_t)(lift_load32(cpu->edi + 0x1A8u)) | (uint64_t)(cpu->eax));
    label_0009EFD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EFD1u);
    cpu->ebx += 2u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0009EFB0;
    label_0009EFD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EFD8u);
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    label_0009EFDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x49EFDCu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"drawMethod");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EFE9u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009F038;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49EFFBu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009F038;
    cpu->ebx = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"SPRITE"); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x9F011u), LIFT_CODE_TOKEN_RVA(0x9F00Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F011u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009F021;
    lift_store32(cpu->edi + 0x1A8u, (uint64_t)(lift_load32(cpu->edi + 0x1A8u)) | (uint64_t)(1u));
    goto label_0009F038;
    label_0009F021: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F021u);
    lift_push32(cpu, (uintptr_t)"NONE"); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x9F02Du), LIFT_CODE_TOKEN_RVA(0x9F02Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F02Du);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009F038;
    lift_store32(cpu->edi + 0x24u, (uint64_t)(lift_load32(cpu->edi + 0x24u)) | (uint64_t)(2u));
    label_0009F038: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F038u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"hotKey");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F045u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = native_function_address32(&::sscanf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009F0F7;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F062u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009F0F3;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F074u); lift_push32(cpu, r); sfera_sub_004BEBC0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->edi + 0x1ACu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    cpu->edx = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%s %d %d %d"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x40u, cpu->ebp);
    lift_store32(cpu->esp + 0x28u, cpu->ebp);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x9F0A5u), LIFT_CODE_TOKEN_RVA(0x9F0A3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F0A5u);
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    cpu->esp += 0x18u;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(1u)) goto label_0009F0B7;
    cpu->eax = cpu->ecx;
    goto label_0009F0BE;
    label_0009F0B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F0B7u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(2u)) goto label_0009F0BE;
    cpu->eax = cpu->ecx;
    label_0009F0BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F0BEu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(1u)) goto label_0009F0CC;
    cpu->eax |= 4u;
    goto label_0009F0D4;
    label_0009F0CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F0CCu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(2u)) goto label_0009F0D4;
    cpu->eax |= 8u;
    label_0009F0D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F0D4u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(1u)) goto label_0009F0E2;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x10u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    goto label_0009F0EA;
    label_0009F0E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F0E2u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009F0EA;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x20u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    label_0009F0EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F0EAu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x10u), 32u);
    lift_store32(cpu->edi + 0x1ACu, (uint64_t)(lift_load32(cpu->edi + 0x1ACu)) | (uint64_t)(cpu->eax));
    label_0009F0F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F0F3u);
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    label_0009F0F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F0F7u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"focuscolor");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F104u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009F16A;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x9F122u), LIFT_CODE_TOKEN_RVA(0x9F120u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F122u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_0009F14A;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Button::LoadUI(%s,%d,%d) -> Not enough args in 'focuscolor'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F141u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F147u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_0009F14A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F14Au);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = lift_load8(cpu->esp + 0x28u);
    cpu->eax = lift_load8(cpu->esp + 0x14u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->eax;
    goto label_0009F170;
    label_0009F16A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F16Au);
    cpu->ecx = lift_load32(cpu->edi + 0x90u);
    label_0009F170: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F170u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->edi + 0x1C0u, cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F182u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049F1A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F1A0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    std::construct_at(reinterpret_cast<SphereUI::ButtonCtrl*>(cpu->esi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F1AEu); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_0009F1BE;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F1BBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009F1BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F1BEu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049F1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F1D0u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009F227;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0x3FFFFFFFu)) goto label_0009F1F9;
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ecx) * 4u));
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F1F2u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009F227;
    label_0009F1F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F1F9u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9F227u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_0009F227: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F227u);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049F230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F230u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_0009F508;
    if ((uint8_t)((lift_load8(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_0009F508;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ebx = 0u;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_0009F28B;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0009F27D;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9F27Du); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_0009F27D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F27Du);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0x18u);
    cpu->ecx += lift_load32(cpu->esp + 0x14u);
    label_0009F28B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F28Bu);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    cpu->eax += cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x1A8u)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009F345;
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    cpu->ecx = lift_load32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0x19Cu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x49u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0009F2DA;
    cpu->ecx = lift_load32(cpu->esi + 0x1C4u);
    label_0009F2DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F2DAu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009F345;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->eax |= 0xFFFFFFu;
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_0009F308;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0009F308: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F308u);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    cpu->esp -= 0x10u;
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x28u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0009F329;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0009F329: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F329u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F343u); lift_push32(cpu, r); sfera_sub_004CE2B0(cpu,r); if (cpu->eip != r) return; }
    goto label_0009F349;
    label_0009F345: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F345u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009F349: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F349u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x64u)) <= (uint32_t)(cpu->ebx)) goto label_0009F506;
    if ((uint32_t)(lift_load32(cpu->esi + 0x198u)) != (uint32_t)(cpu->ebx)) goto label_0009F362;
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    goto label_0009F368;
    label_0009F362: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F362u);
    cpu->eax = lift_load32(cpu->esi + 0x1C0u);
    label_0009F368: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F368u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x49u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0009F373;
    cpu->eax = lift_load32(cpu->esi + 0x98u);
    label_0009F373: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F373u);
    cpu->ecx = lift_load32(cpu->esi + 0xDCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F391u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F3A1u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x28u)))));
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_0009F3B6;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0009F3B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F3B6u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F3BFu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0009F3D4;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0009F3D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F3D4u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F3DBu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->eax);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x118u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->ebx = 0x10u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009F47E;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x68u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x54u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009F404;
    cpu->eax = lift_load32(cpu->eax);
    label_0009F404: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F404u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Du);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F424u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x118u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_0009F440;
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_0009F440;
    cpu->eax -= cpu->edi;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    label_0009F440: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F440u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (2u)) == 0u) goto label_0009F456;
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_0009F456;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_0009F456: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F456u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (4u)) == 0u) goto label_0009F46A;
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_0009F46A;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    label_0009F46A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F46Au);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (8u)) == 0u) goto label_0009F47E;
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_0009F47E;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_0009F47E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F47Eu);
    cpu->edi = 0xFFu;
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(cpu->edi)) goto label_0009F49B;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_0009F49B;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9F49Bu); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_0009F49B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F49Bu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x68u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x54u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009F4A5;
    cpu->eax = lift_load32(cpu->eax);
    label_0009F4A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F4A5u);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Du);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F4CCu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x30u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x34u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F4DBu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F4E4u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(cpu->edi)) goto label_0009F506;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_0009F506;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    sfera_sub_004CE0E0(cpu, stop_address); return;
    label_0009F506: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F506u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0009F508: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F508u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049F510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F510u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xD8u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0x3E9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F547u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x1A8u)) & (8u)) == 0u) goto label_0009F568;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x10u, 0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9F568u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_0009F568: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F568u);
    if ((uint8_t)((lift_load8(cpu->esi + 0x1A8u)) & (0x20u)) == 0u) goto label_0009F58E;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x84u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x70u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009F57F;
    cpu->eax = lift_load32(cpu->eax);
    label_0009F57F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F57Fu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->edx = 0xEu;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9F58Eu); lift_push32(cpu, r); sfera_sub_004BB750(cpu,r); if (cpu->eip != r) return; }
    label_0009F58E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F58Eu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049F5A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F5A0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x3ECu)) goto label_0009F5B8;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F5B0u); lift_push32(cpu, r); sfera_sub_0049F510(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_0009F5B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F5B8u);
    lift_store32(cpu->esp + 4u, cpu->eax);
    sfera_sub_004D2DD0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049F5D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F5D0u);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    cpu->edx += lift_load32(cpu->ecx + 0xCu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 4u, 0u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049F5F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F5F0u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(lift_load32(cpu->esp + 0xCu)) == (uint32_t)(cpu->ecx)) goto label_0009F65C;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    (void)cpu;
    label_0009F600: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F600u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    --cpu->ecx;
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0009F60F;
    cpu->edx = lift_load32(cpu->edx);
    label_0009F60F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F60Fu);
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->ecx)) goto label_0009F618;
    cpu->ecx -= cpu->esi;
    label_0009F618: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F618u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    --cpu->ecx;
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    if ((uint32_t)(cpu->edx) != 0u) goto label_0009F633;
    cpu->edi = 0u;
    goto label_0009F635;
    label_0009F633: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F633u);
    cpu->edi = lift_load32(cpu->edx);
    label_0009F635: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F635u);
    cpu->ebx = lift_load32(cpu->edi + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ebx) > (uint32_t)(cpu->ecx)) goto label_0009F642;
    cpu->ecx -= cpu->ebx;
    cpu->edx = cpu->ecx;
    label_0009F642: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F642u);
    cpu->edi = lift_load32(cpu->edi + 4u);
    cpu->edi = lift_load32(cpu->edi + ((uint32_t)(cpu->edx) * 4u));
    cpu->ecx = 7u;
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(cpu->ecx)) goto label_0009F600;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0009F65C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F65Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009F67B;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009F685;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0009F67B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F67Bu);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_return(cpu, 40u, stop_address); return;
    label_0009F685: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F685u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_return(cpu, 40u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049F690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F690u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_0009F6FF;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_0009F6A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F6A3u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_0009F6AF;
    cpu->ebx = 0u;
    goto label_0009F6B1;
    label_0009F6AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F6AFu);
    cpu->ebx = lift_load32(cpu->esi);
    label_0009F6B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F6B1u);
    cpu->esi = lift_load32(cpu->ebx + 8u);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->ecx)) goto label_0009F6BE;
    cpu->ecx -= cpu->esi;
    cpu->edi = cpu->ecx;
    label_0009F6BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F6BEu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009F6C8;
    cpu->ecx = lift_load32(cpu->ecx);
    label_0009F6C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F6C8u);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->edx)) goto label_0009F6D1;
    cpu->edx -= cpu->esi;
    label_0009F6D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F6D1u);
    cpu->esi = lift_load32(cpu->ebx + 4u);
    cpu->ebx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_load32(cpu->esi + ((uint32_t)(cpu->edi) * 4u));
    cpu->edi = lift_load32(cpu->ebx + ((uint32_t)(cpu->edx) * 4u));
    cpu->ecx = 7u;
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    ++cpu->ecx;
    ++cpu->edx;
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_0009F6A3;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0009F6FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F6FFu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009F721;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009F721;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0009F721: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F721u);
    lift_return(cpu, 40u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049F730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F730u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_0009F78F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_0009F743: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F743u);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->ebx + 8u);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->ecx)) goto label_0009F754;
    cpu->ecx -= cpu->edi;
    cpu->esi = cpu->ecx;
    label_0009F754: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F754u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edx)) goto label_0009F761;
    cpu->edx -= cpu->ecx;
    label_0009F761: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F761u);
    cpu->ebx = lift_load32(cpu->ebx + 4u);
    cpu->edi = lift_load32(cpu->edi + 4u);
    cpu->edi = lift_load32(cpu->edi + ((uint32_t)(cpu->edx) * 4u));
    cpu->esi = lift_load32(cpu->ebx + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = 7u;
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    ++cpu->ecx;
    ++cpu->edx;
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0009F743;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0009F78F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F78Fu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_return(cpu, 28u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049F7A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F7A0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_0009F9B8;
    if ((uint8_t)(lift_load8(cpu->esi + 0x49u)) != (uint8_t)(0u)) goto label_0009F9B8;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ebx = 0u;
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_0009F7FA;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0009F7EC;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9F7ECu); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_0009F7EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F7ECu);
    cpu->ebp = lift_load32(cpu->edi + 0x30u);
    cpu->ebx = lift_load32(cpu->edi + 0x34u);
    cpu->ebp += lift_load32(cpu->esp + 0x10u);
    cpu->ebx += lift_load32(cpu->esp + 0x14u);
    label_0009F7FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F7FAu);
    cpu->eax = lift_load32(cpu->esi + 0x1ACu);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009F82C;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x14u)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0009F82C;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->ecx = cpu->ecx & 0xFFu;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009F82C;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x10u), 32u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009F825;
    if ((uint32_t)((lift_load32(cpu->edi + 0x18u)) & (cpu->eax)) == 0u) goto label_0009F82C;
    label_0009F825: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F825u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9F82Cu); lift_push32(cpu, r); sfera_sub_0049F510(cpu,r); if (cpu->eip != r) return; }
    label_0009F82C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F82Cu);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->edx = lift_load32(cpu->edi);
    cpu->eax += cpu->ebp;
    cpu->ecx += cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->eax)) goto label_0009F96F;
    cpu->ebx = lift_load32(cpu->esi + 0x28u);
    cpu->ebx += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0009F96F;
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_0009F96F;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0009F96F;
    if ((uint32_t)(lift_load32(cpu->esi + 0x198u)) != (uint32_t)(0u)) goto label_0009F878;
    lift_store32(cpu->esi + 0x198u, 2u);
    label_0009F878: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F878u);
    if ((uint8_t)((lift_load8(cpu->edi + 0xCu)) & (1u)) == 0u) goto label_0009F88F;
    lift_store32(cpu->esi + 0x198u, 1u);
    lift_store8(cpu->esi + 0x1B8u, 1u);
    label_0009F88F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F88Fu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(4u) & 0xFFu);
    cpu->ebp = 0u;
    if ((uint8_t)((lift_load8(cpu->esi + 0x1A8u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_0009F90D;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1B8u)) == (uint8_t)(0u)) goto label_0009F90D;
    if ((uint8_t)((lift_load8(cpu->edi + 0x10u)) & (1u)) == 0u) goto label_0009F90D;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F8AFu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x1B0u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esi + 0x1B4u)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10000.0));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1BCu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0009F90D;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1B8u)) == (uint8_t)(0u)) goto label_0009F8F7;
    lift_store32(cpu->esi + 0x198u, 1u);
    label_0009F8F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F8F7u);
    cpu->ebp = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F901u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    lift_store32(cpu->esi + 0x1B4u, cpu->edx);
    label_0009F90D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F90Du);
    if ((uint8_t)((lift_load8(cpu->edi + 0xCu)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_0009F95A;
    if ((uint32_t)(lift_load32(cpu->esi + 0x198u)) != (uint32_t)(1u)) goto label_0009F95A;
    lift_store32(cpu->esi + 0x198u, 2u);
    lift_store8(cpu->esi + 0x1B8u, 0u);
    if ((uint8_t)((lift_load8(cpu->esi + 0x1A8u)) & ((cpu->ebx & 0xFFu))) != 0u) goto label_0009F95A;
    if ((uint32_t)(g_sfera_interface_runtime.sounds_enabled) == (uint32_t)(0u)) goto label_0009F95E;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"Sounds\\in_click.wav";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F949u); lift_push32(cpu, r); sfera_sub_00498060(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F950u); lift_push32(cpu, r); sfera_sub_0049F510(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_0009F95A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F95Au);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0009F9B5;
    label_0009F95E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F95Eu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49F965u); lift_push32(cpu, r); sfera_sub_0049F510(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_0009F96F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F96Fu);
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009F99F;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_0009F986;
    if ((uint8_t)((lift_load8(cpu->edi + 0x10u)) & (1u)) != 0u) goto label_0009F988;
    label_0009F986: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F986u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    label_0009F988: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F988u);
    if ((uint8_t)((lift_load8(cpu->esi + 0x1A8u)) & (2u)) != 0u) goto label_0009F995;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0009F99F;
    label_0009F995: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F995u);
    lift_store32(cpu->esi + 0x198u, 0u);
    label_0009F99F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F99Fu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1B8u)) == (uint8_t)(0u)) goto label_0009F9B5;
    if ((uint8_t)((lift_load8(cpu->edi + 0x10u)) & (1u)) != 0u) goto label_0009F9B5;
    lift_store8(cpu->esi + 0x1B8u, 0u);
    label_0009F9B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F9B5u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0009F9B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F9B8u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049F9C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F9C0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009F9E3;
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_return(cpu, 16u, stop_address); return;
    label_0009F9E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49F9E3u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049F9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49F9F0u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009FA16;
    lift_store32(cpu->ecx + 0xCu, (uint64_t)(lift_load32(cpu->ecx + 0xCu)) + 1u);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    if ((uint32_t)(lift_load32(cpu->ecx + 8u)) > (uint32_t)(cpu->edx)) goto label_0009FA09;
    lift_store32(cpu->ecx + 0xCu, 0u);
    label_0009FA09: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FA09u);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009FA16;
    lift_store32(cpu->ecx + 0xCu, 0u);
    label_0009FA16: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FA16u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049FA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49FA20u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009FA34;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009FA34;
    lift_store32(cpu->ecx + 0xCu, 0u);
    label_0009FA34: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FA34u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049FA40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49FA40u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0009FA62;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0009FA50: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FA50u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0009FA5D;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009FA5D;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_0009FA5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FA5Du);
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) != (uint32_t)(cpu->ebx)) goto label_0009FA50;
    label_0009FA62: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FA62u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(cpu->ebx)) goto label_0009FA8B;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0009FA70: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FA70u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    --cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009FA87;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49FA84u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009FA87: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FA87u);
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->ebx)) goto label_0009FA70;
    label_0009FA8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FA8Bu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0009FA9C;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49FA99u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009FA9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FA9Cu);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049FAB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49FAB0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->edx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x14u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009FADB;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009FADB;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0009FADB: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FADBu);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009FB02;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009FB02;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0009FB02: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FB02u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x2Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009FB29;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009FB29;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_0009FB29: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FB29u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49FB37u); lift_push32(cpu, r); sfera_sub_0049F5F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 36u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049FB40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49FB40u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->edx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x14u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009FB6B;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009FB6B;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0009FB6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FB6Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009FB92;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009FB92;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0009FB92: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FB92u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x2Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009FBB9;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009FBB9;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_0009FBB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FBB9u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49FBC7u); lift_push32(cpu, r); sfera_sub_0049F690(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 36u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049FBD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49FBD0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    cpu->ecx = 0x9249249u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->ecx -= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_0009FBF4;
    lift_push32(cpu, (uint32_t)(uintptr_t)"deque<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x9FBF4u);
    label_0009FBF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FBF4u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(8u)) goto label_0009FC02;
    cpu->ecx = 8u;
    label_0009FC02: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FC02u);
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->ecx)) goto label_0009FC13;
    cpu->edx = 0x9249249u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->edx)) goto label_0009FC13;
    cpu->ebp = cpu->ecx;
    label_0009FC13: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FC13u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebx + 0xCu);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x15u);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49FC27u); lift_push32(cpu, r); sfera_sub_0049F1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = cpu->eax;
    cpu->esi = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    cpu->eax = (uint32_t)(cpu->esi + cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 8u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax -= lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49FC5Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49FC65u);
    cpu->eax += lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0009FCB0;
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->edx = cpu->esi;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ebp;
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49FC85u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49FC8Bu);
    cpu->edx = cpu->eax;
    cpu->edx += lift_load32(cpu->esp + 0x20u);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009FCA4;
    cpu->ecx = cpu->esi;
    cpu->eax = 0u;
    cpu->edi = cpu->edx;
    lift_stos32(cpu, 1u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    label_0009FCA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FCA4u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0009FCF7;
    cpu->ecx = cpu->edi;
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    goto label_0009FCF3;
    label_0009FCB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FCB0u);
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebp) * 4u));
    cpu->edx = cpu->edi;
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49FCC3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49FCC9u);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->eax);
    cpu->esi -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->esi += cpu->esi;
    cpu->esi += cpu->esi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49FCE1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49FCE7u);
    cpu->esp += 0x18u;
    cpu->edi = (uint32_t)(cpu->esi + cpu->eax);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0009FCF7;
    cpu->ecx = cpu->ebp;
    label_0009FCF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FCF3u);
    cpu->eax = 0u;
    lift_stos32(cpu, 1u);
    label_0009FCF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FCF7u);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009FD09;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49FD06u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009FD09: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FD09u);
    lift_store32(cpu->ebx + 8u, (uint64_t)(lift_load32(cpu->ebx + 8u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049FD20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49FD20u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->esp -= 0x1Cu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0009FD98;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_0009FD31: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FD31u);
    --cpu->ecx;
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0009FD96;
    cpu->edi = lift_load32(cpu->esp + 0x30u);
    cpu->edx = lift_load32(cpu->edi + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_0009FD47;
    cpu->ecx -= cpu->edx;
    label_0009FD47: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FD47u);
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_0009FD54;
    cpu->eax -= cpu->edx;
    label_0009FD54: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FD54u);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esi = cpu->eax;
    cpu->ecx = 7u;
    cpu->edi = (uint32_t)(cpu->esp + 8u);
    lift_movs32(cpu, 1u);
    cpu->edi = cpu->eax;
    cpu->ecx = 7u;
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(cpu->esp + 8u);
    cpu->edi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0009FD31;
    label_0009FD96: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FD96u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0009FD98: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FD98u);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049FDA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49FDA0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x5Cu;
    cpu->eax = lift_load32(cpu->ebp + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebp + 0xCu);
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ebx;
    cpu->edi -= cpu->esi;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009FDDA;
    label_0009FDC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FDC9u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->ecx = cpu->edx;
    if ((uint32_t)(cpu->edx) != 0u) goto label_0009FDC9;
    label_0009FDDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FDDAu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edi)) goto label_0009FF0A;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0009FF0A;
    label_0009FDEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FDEEu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->eax += cpu->esi;
    cpu->edx += cpu->eax;
    lift_store32(cpu->esp + 0x40u, cpu->esi);
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->ebx)) goto label_0009FE1D;
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    goto label_0009FE48;
    label_0009FE1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FE1Du);
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    goto label_0009FE48;
    label_0009FE40: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FE40u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_0009FE48: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FE48u);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edx)) goto label_0009FE53;
    cpu->eax -= cpu->ecx;
    label_0009FE53: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FE53u);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load32(cpu->ebx + 8u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ebx) > (uint32_t)(cpu->esi)) goto label_0009FE64;
    cpu->esi -= cpu->ebx;
    cpu->ecx = cpu->esi;
    label_0009FE64: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FE64u);
    cpu->esi = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->ebx = lift_load32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    cpu->esi = cpu->ebx;
    cpu->ecx = 7u;
    cpu->edi = (uint32_t)(cpu->esp + 0x4Cu);
    lift_movs32(cpu, 1u);
    cpu->esi = cpu->eax;
    cpu->edi = cpu->ebx;
    cpu->ecx = 7u;
    lift_movs32(cpu, 1u);
    cpu->edi = cpu->eax;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(cpu->esp + 0x4Cu);
    lift_movs32(cpu, 1u);
    cpu->ebx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = cpu->ebx;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->eax)) goto label_0009FECD;
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esp + 0x48u, cpu->edx);
    cpu->edx += cpu->edi;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    goto label_0009FEE6;
    label_0009FECD: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FECDu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->eax;
    cpu->ecx += cpu->edi;
    lift_store32(cpu->esp + 0x48u, cpu->esi);
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    label_0009FEE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FEE6u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esp + 0x40u))) goto label_0009FE40;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    --cpu->eax;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_0009FDEE;
    label_0009FF0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FF0Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049FF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49FF20u);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    cpu->ebx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0009FF4B;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0009FF4B;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0009FF4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FF4Bu);
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49FF5Eu); lift_push32(cpu, r); sfera_sub_0049F9C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0009FF7E;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0009FF7E;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0009FF7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FF7Eu);
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49FF91u); lift_push32(cpu, r); sfera_sub_0049F9C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49FF9Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    cpu->edx = cpu->eax;
    cpu->edx -= cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    cpu->ebp = cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    cpu->ebp -= cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49FFC0u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->eax -= cpu->edi;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esp -= 0xCu;
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->ebx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A0070;
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0009FFF6;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0009FFF6;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0009FFF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49FFF6u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x28u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000A001D;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000A001D;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000A001D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A001Du);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->esp -= 0xCu;
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x34u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0035u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A003Eu); lift_push32(cpu, r); sfera_sub_0049FAB0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(cpu->ebx)) goto label_000A00E1;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A0050: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0050u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000A0068;
    lift_store32(cpu->esi + 0xCu, (uint64_t)(lift_load32(cpu->esi + 0xCu)) + 1u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) > (uint32_t)(cpu->eax)) goto label_000A0062;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_000A0062: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0062u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A0068;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_000A0068: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0068u);
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A0050;
    lift_store32(cpu->esi + 0x10u, cpu->ecx);
    goto label_000A00E1;
    label_000A0070: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0070u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000A0082;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000A0082;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000A0082: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0082u);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->esp -= 0xCu;
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x28u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A009Au); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    lift_store32(cpu->esp + 0x34u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000A00BA;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000A00BA;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000A00BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A00BAu);
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A00CAu); lift_push32(cpu, r); sfera_sub_0049FB40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(cpu->ebx)) goto label_000A00E1;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    label_000A00D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A00D1u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000A00DB;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A00DB;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_000A00DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A00DBu);
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A00D1;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    label_000A00E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A00E1u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A00F3u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A00FAu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    lift_return(cpu, 28u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A0110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0110u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A012F;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A012F;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000A0135;
    label_000A012F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A012Fu);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_000A013B;
    label_000A0135: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0135u);
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000A013B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A013Bu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ebx = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A0153;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A0153;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000A0157;
    label_000A0153: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0153u);
    cpu->edi = 0u;
    goto label_000A0159;
    label_000A0157: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0157u);
    cpu->edi = lift_load32(cpu->eax);
    label_000A0159: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0159u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A0173;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A0173;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A0173;
    cpu->ecx = lift_load32(cpu->eax);
    label_000A0173: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0173u);
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A018Fu); lift_push32(cpu, r); sfera_sub_0049F730(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A01BB;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A01BB;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->esi, cpu->ecx);
    label_000A01BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A01BBu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 36u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A01D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A01D0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    ++cpu->eax;
    lift_push32(cpu, cpu->esi);
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) > (uint32_t)(cpu->eax)) goto label_000A01E7;
    lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA01E7u); lift_push32(cpu, r); sfera_sub_0049FBD0(cpu,r); if (cpu->eip != r) return; }
    label_000A01E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A01E7u);
    cpu->esi = lift_load32(cpu->ebx + 0xCu);
    cpu->esi += lift_load32(cpu->ebx + 0x10u);
    cpu->eax = lift_load32(cpu->ebx + 8u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->esi)) goto label_000A01F6;
    cpu->esi -= cpu->eax;
    label_000A01F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A01F6u);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_000A0213;
    lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0206u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A0235;
    cpu->edx = lift_load32(cpu->ebx + 4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 4u), cpu->eax);
    label_000A0213: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0213u);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A0229;
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = 7u;
    lift_movs32(cpu, 1u);
    label_000A0229: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0229u);
    lift_store32(cpu->ebx + 0x10u, (uint64_t)(lift_load32(cpu->ebx + 0x10u)) + 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
    label_000A0235: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0235u);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0xCu, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0263u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4A0263u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A0270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0270u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000A02FB;
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ebp)) goto label_000A02FB;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A029E;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A029E;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A02A2;
    label_000A029E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A029Eu);
    cpu->edx = 0u;
    goto label_000A02A4;
    label_000A02A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A02A2u);
    cpu->edx = lift_load32(cpu->eax);
    label_000A02A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A02A4u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A02B8;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A02B8;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A02BC;
    label_000A02B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A02B8u);
    cpu->ecx = 0u;
    goto label_000A02BE;
    label_000A02BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A02BCu);
    cpu->ecx = lift_load32(cpu->eax);
    label_000A02BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A02BEu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A02D2;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A02D2;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A02D6;
    label_000A02D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A02D2u);
    cpu->eax = 0u;
    goto label_000A02D8;
    label_000A02D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A02D6u);
    cpu->eax = lift_load32(cpu->eax);
    label_000A02D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A02D8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A02E7u); lift_push32(cpu, r); sfera_sub_0049FDA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    cpu->esi += cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    label_000A02FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A02FBu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->edi, 0u);
    lift_store32(cpu->edi + 4u, 0u);
    lift_store32(cpu->edi + 8u, cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A031D;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A031D;
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->edi, cpu->eax);
    label_000A031D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A031Du);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 36u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A0330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0330u);
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
    cpu->edi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edi);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A0370: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0370u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0x10u))) goto label_000A03E6;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->eax += 8u;
    cpu->esi = (uint32_t)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A038Au); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000A03A4;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xA03A4u);
    label_000A03A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A03A4u);
    ++cpu->ecx;
    lift_store32(cpu->edi + 4u, cpu->ecx);
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->ebp + 0xCu, cpu->eax);
    goto label_000A0370;
    label_000A03E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A03E6u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A03B9(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A03B9u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFECu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->ebp + 0xCu))) goto label_000A03DD;
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_000A03C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A03C4u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A03D6u); lift_push32(cpu, r); sfera_sub_004A63C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->ebp + 0xCu))) goto label_000A03C4;
    label_000A03DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A03DDu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A03E6u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A0400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0400u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x6Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0439u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ebp + 0x28u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A075B;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFE8u)) > (uint32_t)(cpu->eax)) goto label_000A0621;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    label_000A0470: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0470u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(lift_load32(cpu->ebp + 0x28u))) goto label_000A0555;
    cpu->eax = lift_load32(cpu->ebp + 0x14u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A0484;
    cpu->ecx = 0u;
    goto label_000A0486;
    label_000A0484: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0484u);
    cpu->ecx = lift_load32(cpu->eax);
    label_000A0486: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0486u);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->edx)) goto label_000A0491;
    cpu->eax -= cpu->esi;
    label_000A0491: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0491u);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->edi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    ++cpu->eax;
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) > (uint32_t)(cpu->eax)) goto label_000A04AC;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A04A9u); lift_push32(cpu, r); sfera_sub_0049FBD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    label_000A04AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A04ACu);
    cpu->esi = lift_load32(cpu->ebx + 0xCu);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000A04B8;
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->esi = cpu->ecx;
    label_000A04B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A04B8u);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    --cpu->esi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A04DC;
    lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A04CCu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A0506;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u), cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    label_000A04DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A04DCu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A04F7;
    cpu->esi = cpu->edi;
    cpu->ecx = 7u;
    cpu->edi = cpu->eax;
    lift_movs32(cpu, 1u);
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    label_000A04F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A04F7u);
    lift_store32(cpu->ebx + 0x10u, (uint64_t)(lift_load32(cpu->ebx + 0x10u)) + 1u);
    ++cpu->edx;
    lift_store32(cpu->ebx + 0xCu, cpu->esi);
    lift_store32(cpu->ebp + 0x1Cu, cpu->edx);
    goto label_000A0470;
    label_000A0506: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0506u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD0u);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA052Fu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    sfera_sub_004A052F(cpu, stop_address); return;
    label_000A0555: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0555u);
    cpu->esi = lift_load32(cpu->ebx + 0x10u);
    cpu->esi -= lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFA0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A056Bu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0572u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A057Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC4u);
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A0594;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A0594;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A0598;
    label_000A0594: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0594u);
    cpu->ecx = 0u;
    goto label_000A059A;
    label_000A0598: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0598u);
    cpu->ecx = lift_load32(cpu->eax);
    label_000A059A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A059Au);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFB8u);
    lift_push32(cpu, cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A05B2;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A05B2;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A05B6;
    label_000A05B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A05B2u);
    cpu->ecx = 0u;
    goto label_000A05B8;
    label_000A05B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A05B6u);
    cpu->ecx = lift_load32(cpu->eax);
    label_000A05B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A05B8u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A05C2u); lift_push32(cpu, r); sfera_sub_0049FD20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esp);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFA0u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A05DFu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A05E6u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A05EDu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFF94u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0602u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0609u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0619u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF88u);
    goto label_000A0756;
    label_000A0621: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0621u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    label_000A0630: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0630u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(lift_load32(cpu->ebp + 0x28u))) goto label_000A0705;
    cpu->eax = lift_load32(cpu->ebp + 0x14u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A0644;
    cpu->ecx = 0u;
    goto label_000A0646;
    label_000A0644: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0644u);
    cpu->ecx = lift_load32(cpu->eax);
    label_000A0646: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0646u);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->edx)) goto label_000A0651;
    cpu->eax -= cpu->esi;
    label_000A0651: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0651u);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    ++cpu->eax;
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) > (uint32_t)(cpu->eax)) goto label_000A066C;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0669u); lift_push32(cpu, r); sfera_sub_0049FBD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    label_000A066C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A066Cu);
    cpu->edi = lift_load32(cpu->ebx + 0xCu);
    cpu->edi += lift_load32(cpu->ebx + 0x10u);
    cpu->eax = lift_load32(cpu->ebx + 8u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->edi)) goto label_000A067B;
    cpu->edi -= cpu->eax;
    label_000A067B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A067Bu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(0u)) goto label_000A069B;
    lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A068Bu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A06BB;
    cpu->edx = lift_load32(cpu->ebx + 4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->edi) * 4u), cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    label_000A069B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A069Bu);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->edi = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A06AF;
    cpu->ecx = 7u;
    lift_movs32(cpu, 1u);
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    label_000A06AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A06AFu);
    lift_store32(cpu->ebx + 0x10u, (uint64_t)(lift_load32(cpu->ebx + 0x10u)) + 1u);
    ++cpu->edx;
    lift_store32(cpu->ebp + 0x1Cu, cpu->edx);
    goto label_000A0630;
    label_000A06BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A06BBu);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFACu);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFACu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA06E4u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    sfera_sub_004A06E4(cpu, stop_address); return;
    label_000A0705: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0705u);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0715u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esp);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF88u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A072Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0734u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esp);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF94u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A074Cu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0753u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFA0u);
    label_000A0756: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0756u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA075Bu); lift_push32(cpu, r); sfera_sub_004A0270(cpu,r); if (cpu->eip != r) return; }
    label_000A075B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A075Bu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 40u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A052F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A052Fu);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFECu);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000A054C;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000A0540: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0540u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0547u); lift_push32(cpu, r); sfera_sub_0049F9F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000A0540;
    label_000A054C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A054Cu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0555u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->ebx + 0x10u);
    cpu->esi -= lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFA0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A056Bu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0572u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A057Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC4u);
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A0594;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A0594;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A0598;
    label_000A0594: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0594u);
    cpu->ecx = 0u;
    goto label_000A059A;
    label_000A0598: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0598u);
    cpu->ecx = lift_load32(cpu->eax);
    label_000A059A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A059Au);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFB8u);
    lift_push32(cpu, cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A05B2;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A05B2;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A05B6;
    label_000A05B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A05B2u);
    cpu->ecx = 0u;
    goto label_000A05B8;
    label_000A05B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A05B6u);
    cpu->ecx = lift_load32(cpu->eax);
    label_000A05B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A05B8u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A05C2u); lift_push32(cpu, r); sfera_sub_0049FD20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esp);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFA0u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFB8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A05DFu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A05E6u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A05EDu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFF94u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0602u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0609u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0619u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF88u);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0756u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A075Bu); lift_push32(cpu, r); sfera_sub_004A0270(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 40u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A06E4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A06E4u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFECu);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000A06FC;
    (void)cpu;
    label_000A06F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A06F0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A06F7u); lift_push32(cpu, r); sfera_sub_0049FA20(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000A06F0;
    label_000A06FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A06FCu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0705u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0715u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esp);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF88u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A072Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0734u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esp);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF94u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A074Cu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0753u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFA0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A075Bu); lift_push32(cpu, r); sfera_sub_004A0270(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 40u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A0770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0770u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x10u, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000A079E;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000A079E;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_000A079E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A079Eu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000A07CD;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000A07CD;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_000A07CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A07CDu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x28u, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000A07FC;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000A07FC;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_000A07FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A07FCu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0808u); lift_push32(cpu, r); sfera_sub_004A0400(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 36u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A0810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0810u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    lift_store32(cpu->esi + 4u, 0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi))) goto label_000A0842;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000A0830: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0830u);
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0838u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi))) goto label_000A0830;
    cpu->edi = lift_pop32(cpu);
    label_000A0842: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0842u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A085Du); lift_push32(cpu, r); sfera_sub_004A0330(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A0870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0870u);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->esi)) goto label_000A0A2B;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebp)) goto label_000A08A1;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0895u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 4u, stop_address); return;
    label_000A08A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A08A1u);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000A0957;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A08BDu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A08CEu); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->esp + 0x5Cu, cpu->esp);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A08DFu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A08E8u); lift_push32(cpu, r); sfera_sub_004A0110(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A08F4u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->ebp);
    lift_store32(cpu->ecx + 4u, cpu->ebp);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ebp)) goto label_000A0912;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ebp)) goto label_000A0912;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_000A0912: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0912u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebp);
    lift_store32(cpu->eax + 4u, cpu->ebp);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000A0938;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000A0938;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000A0938: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0938u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A094Bu); lift_push32(cpu, r); sfera_sub_0049FF20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 4u, stop_address); return;
    label_000A0957: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0957u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0969u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0970u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0981u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    lift_store32(cpu->eax, cpu->ebp);
    lift_store32(cpu->eax + 4u, cpu->ebp);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ebp)) goto label_000A09A1;
    cpu->ecx = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000A09A1;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000A09A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A09A1u);
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->esp + 0x5Cu, cpu->esp);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->eax + 8u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A09B9u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A09C2u); lift_push32(cpu, r); sfera_sub_004A0110(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x44u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A09D3u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->esi = 0u;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x50u, cpu->esp);
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->esi);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->esi)) goto label_000A09F1;
    cpu->ebx = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->esi)) goto label_000A09F1;
    cpu->ecx = lift_load32(cpu->ebx);
    lift_store32(cpu->eax, cpu->ecx);
    label_000A09F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A09F1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->eax + 8u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0A00u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->esi);
    lift_store32(cpu->ecx + 4u, cpu->esi);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x5Cu, cpu->esp);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000A0A1E;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000A0A1E;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_000A0A1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0A1Eu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA0A2Bu); lift_push32(cpu, r); sfera_sub_004A0770(cpu,r); if (cpu->eip != r) return; }
    label_000A0A2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0A2Bu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A0A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0A40u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebx + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0A5Au); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0x24u);
    lift_store32(cpu->ebx + 0x24u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x28u);
    lift_store32(cpu->ebx + 0x28u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0x2Cu);
    lift_store32(cpu->ebx + 0x2Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x30u);
    lift_store32(cpu->ebx + 0x30u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x34u);
    lift_store32(cpu->ebx + 0x34u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0x38u);
    lift_store32(cpu->ebx + 0x38u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x3Cu);
    lift_store32(cpu->ebx + 0x3Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x40u);
    lift_store32(cpu->ebx + 0x40u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0x44u);
    lift_store32(cpu->ebx + 0x44u, cpu->eax);
    cpu->ecx = lift_load8(cpu->ebp + 0x48u);
    lift_store8(cpu->ebx + 0x48u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load8(cpu->ebp + 0x49u);
    lift_store8(cpu->ebx + 0x49u, cpu->edx & 0xFFu);
    cpu->eax = lift_load8(cpu->ebp + 0x4Au);
    lift_store8(cpu->ebx + 0x4Au, cpu->eax & 0xFFu);
    cpu->ecx = lift_load8(cpu->ebp + 0x4Bu);
    lift_store8(cpu->ebx + 0x4Bu, cpu->ecx & 0xFFu);
    cpu->edx = lift_load8(cpu->ebp + 0x4Cu);
    lift_store8(cpu->ebx + 0x4Cu, cpu->edx & 0xFFu);
    cpu->eax = lift_load8(cpu->ebp + 0x4Du);
    lift_store8(cpu->ebx + 0x4Du, cpu->eax & 0xFFu);
    cpu->ecx = lift_load8(cpu->ebp + 0x4Eu);
    lift_store8(cpu->ebx + 0x4Eu, cpu->ecx & 0xFFu);
    cpu->edx = lift_load8(cpu->ebp + 0x4Fu);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x54u);
    lift_store8(cpu->ebx + 0x4Fu, cpu->edx & 0xFFu);
    cpu->eax = lift_load32(cpu->ebp + 0x50u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x54u);
    lift_store32(cpu->ebx + 0x50u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0ADEu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0x70u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x70u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0AEEu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load8(cpu->ebp + 0x8Cu);
    lift_store8(cpu->ebx + 0x8Cu, cpu->eax & 0xFFu);
    cpu->ecx = lift_load8(cpu->ebp + 0x8Du);
    lift_store8(cpu->ebx + 0x8Du, cpu->ecx & 0xFFu);
    cpu->edx = lift_load32(cpu->ebp + 0x90u);
    lift_store32(cpu->ebx + 0x90u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0x94u);
    lift_store32(cpu->ebx + 0x94u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x98u);
    lift_store32(cpu->ebx + 0x98u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x9Cu);
    cpu->eax = (uint32_t)(cpu->ebp + 0xA0u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0xA0u);
    lift_store32(cpu->ebx + 0x9Cu, cpu->edx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000A0B58;
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA0B58u); lift_push32(cpu, r); sfera_sub_004A0810(cpu,r); if (cpu->eip != r) return; }
    label_000A0B58: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0B58u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xACu);
    cpu->ecx = (uint32_t)(cpu->ebx + 0xACu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000A0B78;
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA0B78u); lift_push32(cpu, r); sfera_sub_004A0810(cpu,r); if (cpu->eip != r) return; }
    label_000A0B78: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0B78u);
    cpu->eax = lift_load32(cpu->ebp + 0xB8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xBCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0xBCu);
    lift_store32(cpu->ebx + 0xB8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0B96u); lift_push32(cpu, r); sfera_sub_004A0870(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 0xD4u);
    lift_store32(cpu->ebx + 0xD4u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0xD8u);
    lift_store32(cpu->ebx + 0xD8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xDCu);
    lift_store32(cpu->ebx + 0xDCu, cpu->ecx);
    cpu->edx = lift_load8(cpu->ebp + 0xE0u);
    lift_store8(cpu->ebx + 0xE0u, cpu->edx & 0xFFu);
    cpu->eax = lift_load8(cpu->ebp + 0xE1u);
    lift_store8(cpu->ebx + 0xE1u, cpu->eax & 0xFFu);
    cpu->ecx = lift_load32(cpu->ebp + 0xE4u);
    lift_store32(cpu->ebx + 0xE4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xE8u);
    lift_store32(cpu->ebx + 0xE8u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0xECu);
    lift_store32(cpu->ebx + 0xECu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xF0u);
    lift_store32(cpu->ebx + 0xF0u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xF4u);
    lift_store32(cpu->ebx + 0xF4u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0xF8u);
    lift_store32(cpu->ebx + 0xF8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFCu);
    lift_store32(cpu->ebx + 0xFCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x100u);
    lift_store32(cpu->ebx + 0x100u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0x104u);
    lift_store32(cpu->ebx + 0x104u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x108u);
    lift_store32(cpu->ebx + 0x108u, cpu->ecx);
    cpu->edx = lift_load8(cpu->ebp + 0x10Cu);
    lift_store8(cpu->ebx + 0x10Cu, cpu->edx & 0xFFu);
    cpu->eax = lift_load32(cpu->ebp + 0x110u);
    lift_store32(cpu->ebx + 0x110u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x114u);
    lift_store32(cpu->ebx + 0x114u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x118u);
    lift_store32(cpu->ebx + 0x118u, cpu->edx);
    cpu->eax = lift_load8(cpu->ebp + 0x11Cu);
    lift_store8(cpu->ebx + 0x11Cu, cpu->eax & 0xFFu);
    cpu->esi = (uint32_t)(cpu->ebp + 0x120u);
    cpu->edi = (uint32_t)(cpu->ebx + 0x120u);
    cpu->ecx = 0xAu;
    lift_movs32(cpu, 1u);
    cpu->esi = (uint32_t)(cpu->ebp + 0x148u);
    cpu->edi = (uint32_t)(cpu->ebx + 0x148u);
    cpu->ecx = 0xAu;
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->ebp + 0x170u);
    lift_push32(cpu, 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0x170u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x174u);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x178u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x178u);
    lift_store32(cpu->ebx + 0x174u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0CDEu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0x194u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->ebx + 0x194u, cpu->ecx);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A0D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0D00u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0D0Eu); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
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
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1B8u)) & 0xFFu);
    lift_store8(cpu->esi + 0x1B8u, cpu->edx & 0xFFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1BCu));
    lift_store_f32(cpu->esi + 0x1BCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->edi + 0x1C0u);
    lift_store32(cpu->esi + 0x1C0u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1C4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1C4u, cpu->ecx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A0DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0DB0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x12Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Button.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0DE4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0DEEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A0E0C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0E08u); lift_push32(cpu, r); sfera_sub_0049ED60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000A0E0E;
    label_000A0E0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0E0Cu);
    cpu->esi = 0u;
    label_000A0E0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0E0Eu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0E1Eu); lift_push32(cpu, r); sfera_sub_004A0D00(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_000A0E46;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0E38u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA0E46u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000A0E46: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0E46u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A0E60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0E60u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0E68u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store16(cpu->esi + 0x1A8u, cpu->eax & 0xFFFFu);
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    std::construct_at(reinterpret_cast<SphereUI::CheckBox*>(cpu->esi));
    lift_store32(cpu->esi + 0x1C0u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x50u, 7u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A0ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0ED0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esi + 0x1C0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0EF5u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x9Cu)) != (uint32_t)(0u)) goto label_000A0F18;
    lift_push32(cpu, 0x6Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\CheckBox.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0F0Fu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0F15u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000A0F18: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0F18u);
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"checkedImage");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0F29u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A0F78;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0F3Bu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A0F78;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0F4Fu); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A0F78;
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s) -> Can't find sprite '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0F6Du); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0F73u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    goto label_000A0F7C;
    label_000A0F78: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0F78u);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    label_000A0F7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0F7Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"focusedImage");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0F89u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A0FD2;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0F9Bu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A0FD2;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0FAFu); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A0FD2;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s) -> Can't find sprite '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0FC9u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0FCFu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000A0FD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A0FD2u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"uncheckedImage");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0FDFu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A1028;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A0FF1u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A1028;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1005u); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A1028;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s) -> Can't find sprite '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A101Fu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1025u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000A1028: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1028u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"checkfocusImage");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1035u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A107E;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1047u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A107E;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A105Bu); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A107E;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s) -> Can't find sprite '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1075u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A107Bu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000A107E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A107Eu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"imageOffset");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A108Bu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = native_function_address32(&::sscanf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A10CE;
    cpu->edx = (uint32_t)(cpu->esi + 0x1B0u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x1ACu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xA10AEu), LIFT_CODE_TOKEN_RVA(0xA10ACu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A10AEu);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000A10CE;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s) -> Invalid params in 'imageOffset'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A10C5u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A10CBu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000A10CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A10CEu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"textOffset");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A10DBu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A1118;
    cpu->eax = (uint32_t)(cpu->esi + 0x1BCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xA10F8u), LIFT_CODE_TOKEN_RVA(0xA10F6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A10F8u);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000A1118;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s) -> Invalid params in 'textOffset'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A110Fu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1115u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000A1118: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1118u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"focuscolor");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1125u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A118F;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xA1143u), LIFT_CODE_TOKEN_RVA(0xA1141u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1143u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000A116B;
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->eax = lift_load32(cpu->ebp);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s,%d,%d) -> Not enough args in 'focuscolor'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1162u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1168u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000A116B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A116Bu);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load8(cpu->esp + 0x28u);
    cpu->ecx = lift_load8(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx |= cpu->ecx;
    lift_store32(cpu->esi + 0x1C0u, cpu->edx);
    label_000A118F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A118Fu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"buttonStyle");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A119Cu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A11D8;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A11A7u); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_000A11D8;
    (void)cpu;
    label_000A11B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A11B0u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A11BDu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A11D1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A11CBu); lift_push32(cpu, r); sfera_sub_0049ECD0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1B4u, (uint64_t)(lift_load32(cpu->esi + 0x1B4u)) | (uint64_t)(cpu->eax));
    label_000A11D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A11D1u);
    cpu->ebx += 2u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000A11B0;
    label_000A11D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A11D8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A11E4u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A1200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1200u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ecx = 0u;
    cpu->edx = 0u;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A1244;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A1236;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA1236u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000A1236: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1236u);
    cpu->ecx = lift_load32(cpu->edi + 0x30u);
    cpu->edx = lift_load32(cpu->edi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 8u);
    cpu->edx += lift_load32(cpu->esp + 0xCu);
    label_000A1244: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1244u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->ecx += cpu->edx;
    cpu->edx = lift_load32(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->eax)) goto label_000A129A;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    cpu->ebp += cpu->eax;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_pop32(cpu);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000A129A;
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000A129A;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000A129A;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x1A9u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A1284;
    lift_store8(cpu->esi + 0x1A9u, cpu->eax & 0xFFu);
    label_000A1284: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1284u);
    if ((uint8_t)((lift_load8(cpu->edi + 0xCu)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000A12AA;

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::CheckBox*>(cpu->esi)->playClickSound(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1292u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_000A129A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A129Au);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1A9u)) == (uint8_t)(0u)) goto label_000A12AA;
    lift_store8(cpu->esi + 0x1A9u, 0u);
    label_000A12AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A12AAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A12C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A12C0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x3EBu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000A131C;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A130B;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x70u)) goto label_000A12F0;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x3EAu)) goto label_000A1323;
    { uint64_t v=(uint64_t)(cpu->edx); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->ecx + 0x1A8u, cpu->eax & 0xFFu);
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000A12F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A12F0u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000A1323;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ecx + 0x1A8u, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1307u); lift_push32(cpu, r); sfera_sub_004D2DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000A130B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A130Bu);
    cpu->ecx = lift_load8(cpu->ecx + 0x1A8u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000A131C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A131Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x3ECu)) goto label_000A1334;
    label_000A1323: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1323u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1330u); lift_push32(cpu, r); sfera_sub_004D2DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000A1334: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1334u);
    reinterpret_cast<SphereUI::CheckBox*>(cpu->ecx)->playClickSound(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A133Bu);
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A1350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1350u);
    cpu->esp -= 0x20u;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x1A8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = lift_load32(cpu->eax + 0xD8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->eax + 0x1A8u, cpu->ecx & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x9Cu);
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->edx);
    lift_store32(cpu->esp + 0xCu, 0x3E9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1395u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_interface_runtime.sounds_enabled) == (uint32_t)(0u)) goto label_000A13AA;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"Sounds\\in_click.wav";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA13AAu); lift_push32(cpu, r); sfera_sub_00498060(cpu,r); if (cpu->eip != r) return; }
    label_000A13AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A13AAu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A13C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A13C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A13C8u); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000A13D8;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A13D5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A13D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A13D8u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A13E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A13E0u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000A1685;
    if ((uint8_t)((lift_load8(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000A1685;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ebx = 0u;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_000A143B;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0xCu, cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000A142D;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA142Du); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000A142D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A142Du);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    cpu->ecx += lift_load32(cpu->esp + 0xCu);
    label_000A143B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A143Bu);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1A9u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A14FD;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1A8u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A1483;
    cpu->ecx = lift_load32(cpu->esi + 0x1A4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A1497;
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    goto label_000A1493;
    label_000A1483: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1483u);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A1497;
    label_000A148D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A148Du);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    label_000A1493: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1493u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A14E4;
    label_000A1497: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1497u);
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->eax |= 0xFFFFFFu;
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x1B0u)))));
    cpu->esp -= 8u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x1ACu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA14E4u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    label_000A14E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A14E4u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x64u)) <= (uint32_t)(cpu->ebx)) goto label_000A1683;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1A9u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A150D;
    cpu->eax = lift_load32(cpu->esi + 0x1C0u);
    goto label_000A1513;
    label_000A14FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A14FDu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1A8u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A148D;
    cpu->ecx = lift_load32(cpu->esi + 0x1A0u);
    goto label_000A1493;
    label_000A150D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A150Du);
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    label_000A1513: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1513u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x49u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A151E;
    cpu->eax = lift_load32(cpu->esi + 0x98u);
    label_000A151E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A151Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi + 0xDCu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(0x18u), 32u);
    cpu->ebp |= cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A153Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A154Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x28u)))));
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000A155F;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A155F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A155Fu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1568u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000A157D;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A157D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A157Du);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1584u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x1B8u);
    cpu->edx = lift_load32(cpu->esi + 0x1BCu);
    cpu->ebx = 0x10u;
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    if ((uint8_t)((lift_load8(cpu->esi + 0x1B4u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_000A15FB;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x68u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x54u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000A15B4;
    cpu->eax = lift_load32(cpu->eax);
    label_000A15B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A15B4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Du);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A15D4u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000A15E7;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    label_000A15E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A15E7u);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000A15FB;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    label_000A15FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A15FBu);
    cpu->edi = 0xFFu;
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(cpu->edi)) goto label_000A1618;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000A1618;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA1618u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000A1618: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1618u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x68u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x54u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000A1622;
    cpu->eax = lift_load32(cpu->eax);
    label_000A1622: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1622u);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Du);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1649u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x34u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1658u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1661u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(cpu->edi)) goto label_000A1683;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000A1683;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    sfera_sub_004CE0E0(cpu, stop_address); return;
    label_000A1683: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1683u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000A1685: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1685u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A1690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1690u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A169Eu); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    lift_store32(cpu->esi + 0x19Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1A0u);
    lift_store32(cpu->esi + 0x1A0u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1A4u);
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1A8u)) & 0xFFu);
    lift_store8(cpu->esi + 0x1A8u, cpu->ecx & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1A9u)) & 0xFFu);
    lift_store8(cpu->esi + 0x1A9u, cpu->edx & 0xFFu);
    cpu->eax = lift_load32(cpu->edi + 0x1ACu);
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1B0u);
    lift_store32(cpu->esi + 0x1B0u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1B4u);
    lift_store32(cpu->esi + 0x1B4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1B8u);
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1BCu);
    lift_store32(cpu->esi + 0x1BCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1C0u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1C0u, cpu->edx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A1740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1740u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x11Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\CheckBox.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1774u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A177Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A179C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1798u); lift_push32(cpu, r); sfera_sub_004A0E60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000A179E;
    label_000A179C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A179Cu);
    cpu->esi = 0u;
    label_000A179E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A179Eu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A17AEu); lift_push32(cpu, r); sfera_sub_004A1690(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_000A17D6;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A17C8u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA17D6u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000A17D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A17D6u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A17F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A17F0u);
    lift_x87_push(cpu, 0.0);
    cpu->eax = cpu->ecx;
    lift_store16(cpu->eax, 1u);
    lift_store8(cpu->eax + 8u, 0xFFu);
    cpu->ecx = 0u;
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    lift_store_f32(cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    cpu->edx |= 0xFFFFFFFFu;
    lift_store_f32(cpu->eax + 0x20u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x24u, cpu->edx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + 0x28u, cpu->ecx);
    lift_store_f32(cpu->eax + 0x3Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x44u, cpu->edx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + 0x48u, cpu->ecx);
    lift_store_f32(cpu->eax + 0x40u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x64u, cpu->edx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + 0x68u, cpu->ecx);
    lift_store_f32(cpu->eax + 0x5Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x84u, cpu->edx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + 0x88u, cpu->ecx);
    lift_store_f32(cpu->eax + 0x60u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A1860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1860u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(0u)) goto label_000A188B;
    cpu->edx = 0x68u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1878u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1881u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 4u, 0u);
    label_000A188B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A188Bu);
    if ((uint32_t)(lift_load32(cpu->esi + 0xCu)) == (uint32_t)(0u)) goto label_000A18B3;
    cpu->edx = 0x6Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A18A0u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A18A9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0xCu, 0u);
    label_000A18B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A18B3u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(0u)) goto label_000A18DB;
    cpu->edx = 0x74u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A18C8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A18D1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x10u, 0u);
    label_000A18DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A18DBu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A18E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A18E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(0u)) goto label_000A190B;
    cpu->edx = 0x81u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A18F8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1901u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 4u, 0u);
    label_000A190B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A190Bu);
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A191Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1922u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->esp += 4u;
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->edi = 0u;
    label_000A1940: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1940u);
    cpu->ecx = sfera_cursor_texture_name(cpu->edi >> 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A194Bu); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edi + cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->edi + cpu->edx)) != (uint32_t)(0xFFFFFFFFu)) goto label_000A1974;
    cpu->eax = sfera_cursor_texture_name(cpu->edi >> 2u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Cursor texture '%s' not found");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A196Bu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1971u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000A1974: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1974u);
    cpu->edi += 4u;
    if ((uint32_t)(cpu->edi) < (uint32_t)(0x10u)) goto label_000A1940;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esi + 8u, 0u);
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A19A6;
    cpu->edx = 0x97u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1996u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x114u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A19A0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    label_000A19A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A19A6u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) != (uint32_t)(0u)) goto label_000A19CB;
    cpu->edx = 0x9Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A19BBu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x114u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A19C5u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    label_000A19CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A19CBu);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, 0x114u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A19D6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A19DBu);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, 0x114u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A19E6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A19EBu);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->ecx + 0x64u, 0xFFFFFFFFu);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->esp += 0x18u;
    lift_store32(cpu->edx + 0xC0u, 0xFFFFFFFFu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A1A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1A20u);
    cpu->esp -= 0x1Cu;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x5Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esi + cpu->eax, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->eax + cpu->esi + 4u, cpu->edx);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000A1A5B;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_000A1A60;
    label_000A1A5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1A5Bu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA1A60u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    label_000A1A60: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1A60u);
    cpu->ecx = lift_load32(cpu->edi + 0xCu);
    lift_store32(cpu->ecx + cpu->esi + 8u, cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 0xCu);
    if ((uint32_t)(lift_load32(cpu->edx + cpu->esi + 8u)) == (uint32_t)(0xFFFFFFFFu)) goto label_000A1AA7;
    cpu->ecx = lift_load32(cpu->edx + cpu->esi + 8u);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1A7Eu); lift_push32(cpu, r); sfera_sub_0044FC60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx + cpu->esi + 0x54u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + cpu->esi + 0x58u, cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 16u, stop_address); return;
    label_000A1AA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1AA7u);
    cpu->eax = 0x20u;
    lift_store32(cpu->edx + cpu->esi + 0x54u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0xCu);
    lift_store32(cpu->ecx + cpu->esi + 0x58u, cpu->eax);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A1AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1AD0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x5Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->edx + cpu->eax + 0x54u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->ecx + cpu->eax + 0x58u, cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A1B00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1B00u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x5Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edx + cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->ecx + cpu->esi + 0x4Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->eax + cpu->esi + 0x50u, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A1B4A;
    cpu->edx = lift_load32(cpu->edi + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->edx + cpu->esi + 0xCu, cpu->eax & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 24u, stop_address); return;
    label_000A1B4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1B4Au);
    lift_push32(cpu, 0x3Fu); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4A1B55u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1B5Bu);
    cpu->edx = lift_load32(cpu->edi + 0x10u);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->edx + cpu->esi + 0x4Bu, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A1B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1B70u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0u)) goto label_000A1DA2;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1B8Cu); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->esi + 1u)) == (uint8_t)(0u)) goto label_000A1BAC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, 16.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 0x10u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000A1BAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1BACu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 8u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0xFFu)) goto label_000A1C6C;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = cpu->eax & 0xFFu;
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A1C6C;
    cpu->edx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1BD2u); lift_push32(cpu, r); sfera_sub_0044FCB0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, 0.5);
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    lift_push32(cpu, 0x20u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 2u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 6u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_push(cpu, 32.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x4Cu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esi + 0x50u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esi + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esi + 0x58u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x6Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA1C6Cu); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    label_000A1C6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1C6Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    label_000A1C71: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1C71u);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->edi + cpu->edx + 8u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_000A1D36;
    cpu->edx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1C8Bu); lift_push32(cpu, r); sfera_sub_0044FCB0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    cpu->eax += cpu->edi;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax)))));
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 4u)))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->eax + 0x54u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 0x54u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000A1CCD;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A1CCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1CCDu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx))));
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x4Cu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x50u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    lift_store_f32(cpu->esi + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->eax + 0x58u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000A1CFD;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A1CFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1CFDu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x18u))));
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 2u);
    lift_store_f32(cpu->esi + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 6u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x6Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->esi + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x58u));
    lift_store_f32(cpu->esi + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA1D36u); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    label_000A1D36: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1D36u);
    cpu->edi += 0x5Cu;
    if ((uint32_t)(cpu->edi) < (uint32_t)(0x114u)) goto label_000A1C71;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1D50u); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    label_000A1D52: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1D52u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->edi = (uint32_t)(cpu->ebx + cpu->ecx);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (uint32_t)(cpu->edi + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A1D94;
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load32(cpu->edi + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 4u)))));
    cpu->ecx = lift_load32(cpu->edi + 0x50u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1D7Eu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi)))));
    cpu->ebp = cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1D8Bu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA1D94u); lift_push32(cpu, r); sfera_sub_0044D190(cpu,r); if (cpu->eip != r) return; }
    label_000A1D94: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1D94u);
    cpu->ebx += 0x5Cu;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(0x114u)) goto label_000A1D52;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000A1DA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1DA2u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A1DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1DB0u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(g_sfera_interface_runtime.description_window), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A1DF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1DF0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    std::construct_at(reinterpret_cast<SphereUI::CDescriptionWindow*>(cpu->esi));
    g_sfera_interface_runtime.description_window = (uint32_t)(0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1E08u); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000A1E18;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1E15u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A1E18: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1E18u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A1E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1E20u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1E31u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1E3Fu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1E55u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = cpu->eax;

    reinterpret_cast<CCursor*>(cpu->ecx)->cursorKind(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1E5Eu);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000A1E80;
    cpu->ecx = sfera_cursor_texture_name(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx)) == (uint8_t)(0x5Fu)) goto label_000A1E80;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1E74u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ebx = cpu->eax;
    cpu->ebx = lift_shift_arithmetic(cpu, cpu->ebx, (uint32_t)(1u), 32u);
    goto label_000A1E82;
    label_000A1E80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1E80u);
    cpu->ebx = 0u;
    label_000A1E82: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1E82u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1E87u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = cpu->eax;

    reinterpret_cast<CCursor*>(cpu->ecx)->cursorKind(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1E90u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000A1EB0;
    cpu->ecx = sfera_cursor_texture_name(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx)) == (uint8_t)(0x5Fu)) goto label_000A1EB0;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1EA6u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    goto label_000A1EB8;
    label_000A1EB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1EB0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1EB5u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 4u);
    label_000A1EB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1EB8u);
    cpu->ecx = lift_load32(cpu->edi + 0x28u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = g_sfera_graphics_runtime.display_width;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->edx);
    cpu->ebp += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebp) > (int32_t)(uint32_t)(cpu->edi)) goto label_000A1ED3;
    lift_store32(cpu->esi, (uint64_t)(lift_load32(cpu->esi)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    goto label_000A1EE3;
    label_000A1ED3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1ED3u);
    cpu->edx -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000A1EDF;
    cpu->ecx += cpu->ebx;
    lift_store32(cpu->esi, (uint64_t)(lift_load32(cpu->esi)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u));
    goto label_000A1EE3;
    label_000A1EDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1EDFu);
    cpu->edi -= cpu->ecx;
    lift_store32(cpu->esi, cpu->edi);
    label_000A1EE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1EE3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1EE8u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = cpu->eax;

    reinterpret_cast<CCursor*>(cpu->ecx)->cursorKind(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1EF1u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000A1F13;
    cpu->ecx = sfera_cursor_texture_name(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx)) == (uint8_t)(0x5Fu)) goto label_000A1F13;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1F07u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ebx = cpu->eax;
    cpu->ebx = lift_shift_arithmetic(cpu, cpu->ebx, (uint32_t)(1u), 32u);
    goto label_000A1F15;
    label_000A1F13: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1F13u);
    cpu->ebx = 0u;
    label_000A1F15: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1F15u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1F1Au); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = cpu->eax;

    reinterpret_cast<CCursor*>(cpu->ecx)->cursorKind(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1F23u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000A1F43;
    cpu->ecx = sfera_cursor_texture_name(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx)) == (uint8_t)(0x5Fu)) goto label_000A1F43;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1F39u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    goto label_000A1F4B;
    label_000A1F43: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1F43u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1F48u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 8u);
    label_000A1F4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1F4Bu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + 0x2Cu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edi = g_sfera_graphics_runtime.display_height;
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->edx);
    cpu->ebp += cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_pop32(cpu);
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_000A1F74;
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000A1F74: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1F74u);
    cpu->edx -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000A1F8A;
    cpu->ecx += cpu->ebx;
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000A1F8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1F8Au);
    cpu->edi -= cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A1FA0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000A1FA0;
    label_000A1DC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1DC0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esi + 0x19Cu, 0u);
    lift_store32(cpu->esi + 0x1A0u, 0u);
    lift_store8(cpu->esi + 0x48u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A1DE0u); lift_push32(cpu, r); sfera_sub_004D2870(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Au, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000A1FA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1FA0u);
    { uint64_t l=(uint64_t)(g_sfera_interface_runtime.description_auto_popup), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A1FCD;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1C0u)) != (uint8_t)(0u)) goto label_000A1FCD;
    if ((uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x2A]) != (uint8_t)(0u)) goto label_000A1FFB;
    if ((uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x36]) != (uint8_t)(0u)) goto label_000A1FFB;
    cpu->esi = lift_pop32(cpu);
    goto label_000A1DC0;
    label_000A1FCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1FCDu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000A1FFB;
    if ((uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x2A]) != (uint8_t)(0u)) goto label_000A1FFB;
    if ((uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x36]) != (uint8_t)(0u)) goto label_000A1FFB;
    lift_native_call(cpu, native_function_address32(&::GetTickCount), LIFT_CODE_TOKEN_VA(0x4A1FE5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1FEBu);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0x1A8u))) goto label_000A1FFB;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    goto label_000A1DC0;
    label_000A1FFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A1FFBu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A2000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2000u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x64u)) goto label_000A2019;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x3E9u)) goto label_000A2033;
    if ((uint32_t)(lift_load32(cpu->edx + 4u)) != (uint32_t)(2u)) goto label_000A2033;
    label_000A2019: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2019u);
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x19Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x1A0u, cpu->ebx);
    lift_store8(cpu->esi + 0x48u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2030u); lift_push32(cpu, r); sfera_sub_004D2870(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Au, cpu->ebx & 0xFFu);
    label_000A2033: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2033u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A2040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2040u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"objdesc2";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2074u); lift_push32(cpu, r); sfera_sub_004B9850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ebx)) goto label_000A2094;
    lift_push32(cpu, (uintptr_t)"objdesc2"); lift_push32(cpu, (uintptr_t)"SphereUI::FindTemplateWindowGuaranteed(): failed to find window \"%s\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A208Bu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2091u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000A2094: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2094u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A209Cu); lift_push32(cpu, r); sfera_sub_004D51A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"window_caption");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    std::construct_at(reinterpret_cast<SphereUI::CDescriptionWindow*>(cpu->esi));
    lift_store32(cpu->esi + 0x19Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x1A0u, cpu->ebx);
    lift_store32(cpu->esi + 0x1A8u, cpu->ebx);
    lift_store32(cpu->esi + 0x1A4u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A20CAu); lift_push32(cpu, r); sfera_sub_004D2560(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ebx)) goto label_000A20E8;
    lift_push32(cpu, (uintptr_t)"window_caption"); lift_push32(cpu, (uintptr_t)"SphereUI::CDescriptionWindow::FindSpriteGuaranteed(): failed to find sprite \"%s\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A20DFu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A20E5u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000A20E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A20E8u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"window_bottom");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x1ACu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A20FAu); lift_push32(cpu, r); sfera_sub_004D2560(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ebx)) goto label_000A2118;
    lift_push32(cpu, (uintptr_t)"window_bottom"); lift_push32(cpu, (uintptr_t)"SphereUI::CDescriptionWindow::FindSpriteGuaranteed(): failed to find sprite \"%s\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A210Fu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2115u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000A2118: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2118u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"window_left");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x1B0u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A212Au); lift_push32(cpu, r); sfera_sub_004D2560(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ebx)) goto label_000A2148;
    lift_push32(cpu, (uintptr_t)"window_left"); lift_push32(cpu, (uintptr_t)"SphereUI::CDescriptionWindow::FindSpriteGuaranteed(): failed to find sprite \"%s\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A213Fu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2145u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000A2148: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2148u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"window_right");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x1B4u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A215Au); lift_push32(cpu, r); sfera_sub_004D2560(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ebx)) goto label_000A2178;
    lift_push32(cpu, (uintptr_t)"window_right"); lift_push32(cpu, (uintptr_t)"SphereUI::CDescriptionWindow::FindSpriteGuaranteed(): failed to find sprite \"%s\"");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A216Fu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2175u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000A2178: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2178u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    lift_store32(cpu->esi + 0x1B8u, cpu->edi);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ebx)) goto label_000A21A2;
    lift_push32(cpu, 1u); lift_push32(cpu, (uintptr_t)"SphereUI::CDescriptionWindow::CDescriptionWindow(): failed to find control #%u");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2199u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A219Fu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000A21A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A21A2u);
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    cpu->ecx -= lift_load32(cpu->edi + 0x2Cu);
    lift_store32(cpu->esi + 0xF8u, LIFT_CALLBACK(sfera_sub_004A2000));
    lift_store32(cpu->esi + 0x1BCu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x19Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x1A0u, cpu->ebx);
    lift_store8(cpu->esi + 0x48u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A21CFu); lift_push32(cpu, r); sfera_sub_004D2870(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi + 0x4Au, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A21D9u); lift_push32(cpu, r); sfera_sub_004BA870(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A21F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A21F0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = g_sfera_interface_runtime.description_window;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A2269;
    cpu->edx = 0x87u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\DescriptionWindow.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2229u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2233u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A2262;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A224Du); lift_push32(cpu, r); sfera_sub_004A2040(cpu,r); if (cpu->eip != r) return; }
    g_sfera_interface_runtime.description_window = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000A2262: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2262u);
    cpu->eax = 0u;
    g_sfera_interface_runtime.description_window = (uint32_t)(cpu->eax);
    label_000A2269: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2269u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A2280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2280u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x48u)), r=(uint64_t)((cpu->edx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A2667;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->ecx = lift_load32(cpu->esi + 0x1ACu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFFu), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFFu), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->ecx = lift_load32(cpu->esi + 0x1B4u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFFu), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->ecx = lift_load32(cpu->esi + 0x1B8u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->eax |= 0xFFFFFFu;
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_store32(cpu->esp + 8u, cpu->edx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000A2332;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA2332u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000A2332: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2332u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0x34u);
    cpu->ebx += lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->eax = lift_load32(cpu->esi + 0x1B4u);
    lift_push32(cpu, cpu->ebp);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->edi = lift_load32(cpu->eax + 4u);
    lift_x87_push(cpu, 0.5);
    cpu->ecx = cpu->edi;
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000A2386;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A2386: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2386u);
    cpu->edx = lift_load32(cpu->esi + 0x1ACu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->edx + 8u);
    cpu->eax = cpu->ebp;
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 0x14u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000A23BD;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A23BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A23BDu);
    cpu->ecx = lift_load32(cpu->esi + 0xDCu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { int64_t v=(int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA6u); cpu->ecx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    cpu->eax = 0x80808081u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(7u), 32u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    cpu->ecx |= 0x282420u;
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000A23F4;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A23F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A23F4u);
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000A240F;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A240F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A240Fu);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 0x10u;
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x28u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000A2442;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A2442: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2442u);
    cpu->edx = lift_load32(cpu->esi + 0x1B8u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x30u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000A245D;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A245D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A245Du);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A248Bu); lift_push32(cpu, r); sfera_sub_004CEB70(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->ecx = lift_load32(cpu->esi + 0x1ACu);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A24A8u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx -= lift_load32(cpu->ecx + 8u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000A24C6;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A24C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A24C6u);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A24D9u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1B4u);
    cpu->ebp = lift_load32(cpu->esi + 0x2Cu);
    cpu->ebp -= lift_load32(cpu->ecx + 8u);
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    cpu->edx = lift_load32(cpu->esi + 0x1ACu);
    cpu->ebp -= lift_load32(cpu->eax + 8u);
    cpu->edi = lift_load32(cpu->edx + 8u);
    if ((int32_t)(uint32_t)(cpu->edi) > (int32_t)(uint32_t)(cpu->ebp)) goto label_000A2566;
    label_000A2500: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2500u);
    cpu->eax = (uint32_t)(cpu->edi + cpu->ebx);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2526u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1B8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx -= lift_load32(cpu->ecx + 4u);
    cpu->esp -= 8u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esp + 0x20u)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000A2551;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A2551: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2551u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2559u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1B4u);
    cpu->edi += lift_load32(cpu->ecx + 8u);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_000A2500;
    label_000A2566: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2566u);
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax -= lift_load32(cpu->ecx + 8u);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000A2644;
    cpu->ecx = lift_load32(cpu->esi + 0x1B4u);
    cpu->edi += cpu->ebx;
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000A25A0;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A25A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A25A0u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->esp -= 0x10u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x34u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000A25C0;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A25C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A25C0u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A25D8u); lift_push32(cpu, r); sfera_sub_004CE2B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x1B0u);
    cpu->ebp = lift_load32(cpu->esi + 0x2Cu);
    cpu->ebp -= lift_load32(cpu->edx + 8u);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = lift_load32(cpu->esi + 0x1B8u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000A25FF;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A25FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A25FFu);
    cpu->edx = (uint32_t)(cpu->eax + cpu->edi);
    cpu->esp -= 0x10u;
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x34u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000A261B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A261B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A261Bu);
    cpu->eax -= lift_load32(cpu->ecx + 4u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x34u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000A263C;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A263C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A263Cu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA2644u); lift_push32(cpu, r); sfera_sub_004CE2B0(cpu,r); if (cpu->eip != r) return; }
    label_000A2644: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2644u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->edi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000A2664;
    label_000A2650: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2650u);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A265Au);
    cpu->edi = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0xA0u))) goto label_000A2650;
    label_000A2664: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2664u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000A2667: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2667u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A2670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2670u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000A269C;
    lift_push32(cpu, 1u); lift_push32(cpu, (uintptr_t)"SphereUI::CDescriptionWindow::ShowDescription(): failed to find control #%u");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2693u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2699u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000A269C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A269Cu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->edx;
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    label_000A26A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A26A5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A26A5;
    cpu->eax -= cpu->ebx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, 0xA92u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A26BEu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0xA93u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A26D0u);
    cpu->eax = lift_load32(cpu->esi + 0x1BCu);
    cpu->eax += lift_load32(cpu->edi + 0x2Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A26E8u); lift_push32(cpu, r); sfera_sub_004A1E20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A26FBu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetTickCount), LIFT_CODE_TOKEN_VA(0x4A270Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2711u);
    cpu->eax += lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x20u)) & 0xFFu);
    lift_store8(cpu->esi + 0x1C0u, cpu->eax & 0xFFu);
    lift_store8(cpu->esi + 0x48u, 0u);
    lift_store8(cpu->esi + 0x4Au, 1u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A2740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2740u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A2750: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2750u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A2750;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A2801;
    if ((uint8_t)(lift_load8(cpu->esp + 0x10u)) == (uint8_t)((cpu->ecx & 0xFFu))) goto label_000A277E;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0xFAu); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2779u); lift_push32(cpu, r); sfera_sub_004A2670(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000A277E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A277Eu);
    if ((uint32_t)(g_sfera_interface_runtime.description_auto_popup) == (uint32_t)(0u)) goto label_000A2801;
    if ((uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x2A]) != (uint8_t)(0u)) goto label_000A2801;
    if ((uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x36]) != (uint8_t)(0u)) goto label_000A2801;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::GetTickCount);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1A0u)) == (uint32_t)(cpu->eax)) goto label_000A27BF;
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA27B4u), LIFT_CODE_TOKEN_RVA(0xA27B2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A27B4u);
    cpu->eax += 0x1F4u;
    lift_store32(cpu->esi + 0x1A4u, cpu->eax);
    label_000A27BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A27BFu);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esi + 0x1A0u))) goto label_000A27F3;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA27CFu), LIFT_CODE_TOKEN_RVA(0xA27CDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A27CFu);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0x1A4u))) goto label_000A2800;
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0xFAu); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A27EDu); lift_push32(cpu, r); sfera_sub_004A2670(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000A27F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A27F3u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA27F5u), LIFT_CODE_TOKEN_RVA(0xA27F3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A27F5u);
    cpu->eax += 0xFAu;
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    label_000A2800: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2800u);
    cpu->edi = lift_pop32(cpu);
    label_000A2801: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2801u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A2810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2810u);
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A2D03;
    if ((uint8_t)((lift_load8(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000A2D03;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_000A2876;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000A2868;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA2868u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000A2868: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2868u);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0x20u);
    cpu->ecx += lift_load32(cpu->esp + 0x10u);
    label_000A2876: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2876u);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1A9u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A28B1;
    cpu->edx = (uint32_t)(cpu->esi + 0x1B4u);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    label_000A28B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A28B1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A28BCu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    cpu->edi = cpu->eax;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A28CFu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x28u)))));
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000A28E7;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A28E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A28E7u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A28F0u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x2Cu)))));
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000A2905;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A2905: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2905u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A290Cu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_store32(cpu->esp + 0x48u, cpu->eax);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2961u); lift_push32(cpu, r); sfera_sub_004D8990(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x58u);
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    cpu->ebx = lift_load32(cpu->esp + 0x5Cu);
    cpu->edx = lift_load32(cpu->esp + 0x64u);
    cpu->ecx += cpu->eax;
    cpu->edx += cpu->ebx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000A297B;
    cpu->edi = cpu->eax;
    label_000A297B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A297Bu);
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->ebx)) goto label_000A2981;
    cpu->ebp = cpu->ebx;
    label_000A2981: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2981u);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (uint32_t)(cpu->ebx + cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000A2990;
    cpu->ecx -= cpu->edi;
    cpu->ebx = cpu->ecx;
    label_000A2990: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2990u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(cpu->edx)) goto label_000A299F;
    cpu->edx -= cpu->ebp;
    cpu->eax = cpu->edx;
    label_000A299F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A299Fu);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000A29A7;
    cpu->ebx += cpu->edi;
    cpu->edi = 0u;
    label_000A29A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A29A7u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_000A29AF;
    cpu->eax += cpu->ebp;
    cpu->ebp = 0u;
    label_000A29AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A29AFu);
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    cpu->edx = (uint32_t)(cpu->ebx + cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000A29C0;
    cpu->ecx -= cpu->edi;
    cpu->ebx = cpu->ecx;
    label_000A29C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A29C0u);
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000A29D1;
    cpu->ecx -= cpu->ebp;
    cpu->eax = cpu->ecx;
    label_000A29D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A29D1u);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    lift_x87_push(cpu, 1.0);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x44u, cpu->edi);
    lift_store32(cpu->esp + 0x48u, cpu->ebp);
    lift_store32(cpu->esp + 0x4Cu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A29FDu); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x64u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1E8u)) == (uint32_t)(cpu->eax)) goto label_000A2A0E;
    lift_store32(cpu->esi + 0x1E4u, cpu->eax);
    label_000A2A0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2A0Eu);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = 0x10u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000A2A20;
    cpu->ecx = lift_load32(cpu->edi);
    goto label_000A2A22;
    label_000A2A20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2A20u);
    cpu->ecx = cpu->edi;
    label_000A2A22: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2A22u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Du);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2A40u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    lift_store32(cpu->esp + 0x30u, (uint64_t)(lift_load32(cpu->esp + 0x30u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000A2A5D;
    cpu->ecx = lift_load32(cpu->edi);
    goto label_000A2A5F;
    label_000A2A5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2A5Du);
    cpu->ecx = cpu->edi;
    label_000A2A5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2A5Fu);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    cpu->edx -= 2u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x1E4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2A7Fu); lift_push32(cpu, r); sfera_sub_004A5330(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->eax)) goto label_000A2ABB;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx ^= cpu->edx;
    cpu->ecx -= cpu->edx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_000A2AE1;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1E4u)) != (uint32_t)(cpu->ebp)) goto label_000A2AAD;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    goto label_000A2AE1;
    label_000A2AAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2AADu);
    cpu->edx = lift_load32(cpu->esi + 0x1B0u);
    cpu->edx -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    goto label_000A2AE1;
    label_000A2ABB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2ABBu);
    cpu->edx = lift_load32(cpu->esi + 0x118u);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (4u)) == 0u) goto label_000A2AD6;
    cpu->ebp = cpu->eax;
    cpu->ebp -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(lift_load32(cpu->esi + 0x1B0u)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebp = v; }
    cpu->ebp = lift_shift_right(cpu, cpu->ebp, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    label_000A2AD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2AD6u);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_000A2AE1;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000A2AE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2AE1u);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000A2AF6;
    cpu->edx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    label_000A2AF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2AF6u);
    if ((uint8_t)((lift_load8(cpu->esi + 0x118u)) & (2u)) == 0u) goto label_000A2B09;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000A2B09;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    label_000A2B09: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2B09u);
    cpu->ebp = 0xFFu;
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(cpu->ebp)) goto label_000A2B26;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000A2B26;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA2B26u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000A2B26: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2B26u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000A2B2F;
    cpu->eax = lift_load32(cpu->edi);
    goto label_000A2B31;
    label_000A2B2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2B2Fu);
    cpu->eax = cpu->edi;
    label_000A2B31: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2B31u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    cpu->edx = lift_load8(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    lift_store_f64(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_store_f64(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2B70u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2B77u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2B80u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x1D8u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x1DCu)), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A2B9F;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2B93u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1D8u, cpu->eax);
    lift_store32(cpu->esi + 0x1DCu, cpu->edx);
    label_000A2B9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2B9Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2BA4u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x1D8u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esi + 0x1DCu)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 0x18u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10000.0));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000A2BEE;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2BDEu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store32(cpu->esi + 0x1D8u, cpu->eax);
    lift_store32(cpu->esi + 0x1DCu, cpu->edx);
    label_000A2BEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2BEEu);
    lift_x87_push(cpu, 0.4000000059604645);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000A2C35;
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store16(cpu->esp + 0x10u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax |= 0xC00u;
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 0x18u))) / (lift_x87_get(cpu, 0u)));
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0x18u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x18u)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    lift_store8(cpu->esi + 0x1E0u, cpu->eax & 0xFFu);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x10u));
    goto label_000A2C39;
    label_000A2C35: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2C35u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000A2C39: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2C39u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Au)) == (uint8_t)(0u)) goto label_000A2CD6;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1E0u)) == (uint8_t)(0u)) goto label_000A2CD6;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1E1u)) == (uint8_t)(0u)) goto label_000A2C6D;
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x1D0u))) goto label_000A2C6D;
    lift_store32(cpu->esi + 0x1D0u, cpu->eax);
    label_000A2C6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2C6Du);
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load8(cpu->esi + 0x8Du);
    cpu->eax = lift_load32(cpu->esi + 0x1D0u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x1A4u)))));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xDCu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_load_f64(cpu->esp + 0x40u)));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    lift_push32(cpu, cpu->edx);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"_");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2CB0u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000A2CC4;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A2CC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2CC4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_load_f64(cpu->esp + 0x38u)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2CCDu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA2CD6u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    label_000A2CD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2CD6u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xDCu)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A2CF3;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000A2CF3;
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA2CF3u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000A2CF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2CF3u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA2D03u); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    label_000A2D03: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2D03u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x64u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A2D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2D20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2D2Bu); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    std::construct_at(reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi));
    lift_store16(cpu->esi + 0x1A8u, cpu->ebx & 0xFFFFu);
    lift_store32(cpu->esi + 0x1ACu, 0x100u);
    lift_store32(cpu->esi + 0x1C8u, 0xFu);
    lift_store32(cpu->esi + 0x1C4u, cpu->ebx);
    lift_store8(cpu->esi + 0x1B4u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x1D0u, 0xFFFFFFu);
    lift_store32(cpu->esi + 0x1D8u, cpu->ebx);
    lift_store32(cpu->esi + 0x1DCu, cpu->ebx);
    lift_store16(cpu->esi + 0x1E0u, 0x101u);
    lift_store8(cpu->esi + 0x1E2u, 1u);
    lift_store32(cpu->esi + 0x1E4u, cpu->ebx);
    lift_store32(cpu->esi + 0x1E8u, 0xFFFFFFFFu);
    lift_store8(cpu->esi + 0x48u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x50u, 0xDu);
    lift_store32(cpu->esi + 0x198u, cpu->ebx);
    lift_store32(cpu->esi + 0x19Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x1B0u, 5u);
    lift_store8(cpu->esi + 0x4Au, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x1A0u, cpu->ebx);
    lift_store32(cpu->esi + 0x1A4u, cpu->ebx);
    lift_store32(cpu->esi + 0x1ECu, cpu->ebx);
    lift_store32(cpu->esi + 0x1F0u, cpu->ebx);
    cpu->edi = (uint32_t)(cpu->esi + 0x1F4u);
    cpu->ebp = (uint32_t)(cpu->ebx + 0x64u);
    label_000A2DD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2DD4u);
    lift_push32(cpu, 0xFAu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A2DDBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2DE0u);
    cpu->esp += 0xCu;
    cpu->edi += 0x100u;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A2DD4;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A2E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2E00u);
    cpu->esp -= 0x104u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0x4Bu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 8u, cpu->ebx);
    std::construct_at(reinterpret_cast<SphereUI::EditCtrl*>(cpu->ebx));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A2F84;
    cpu->eax = 0x79616C70u;
    cpu->ecx = 0x5C737265u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 0x9Cu);
    cpu->eax += 0x178u;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store8(cpu->esp + 0x14u, cpu->edx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000A2E5E;
    cpu->esi = lift_load32(cpu->eax);
    goto label_000A2E60;
    label_000A2E5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2E5Eu);
    cpu->esi = cpu->eax;
    label_000A2E60: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2E60u);
    cpu->edx = (uint32_t)(uintptr_t)"";
    cpu->ecx = cpu->esi;
    label_000A2E67: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2E67u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A2E87;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A2E83;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A2E87;
    cpu->ecx += 2u;
    cpu->edx += 2u;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000A2E67;
    label_000A2E83: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2E83u);
    cpu->eax = 0u;
    goto label_000A2E8C;
    label_000A2E87: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2E87u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000A2E8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2E8Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A2F84;
    cpu->edx = (uint32_t)(uintptr_t)"testui";
    cpu->ecx = cpu->esi;
    label_000A2EA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2EA0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A2EC0;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A2EBC;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A2EC0;
    cpu->ecx += 2u;
    cpu->edx += 2u;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000A2EA0;
    label_000A2EBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2EBCu);
    cpu->eax = 0u;
    goto label_000A2EC5;
    label_000A2EC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2EC0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000A2EC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2EC5u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A2F84;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->esi;
    label_000A2ED1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2ED1u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A2ED1;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esp + 0x10u);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_000A2EE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2EE0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A2EE0;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_movs8(cpu, 1u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A2F00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2F00u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A2F00;
    cpu->ecx = 0x7478742Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4A2F24u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2F2Au);
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000A2F82;
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->ebx + 0x1ECu)) <= (uint32_t)(cpu->esi)) goto label_000A2F71;
    cpu->edi = (uint32_t)(cpu->ebx + 0x1F4u);
    cpu->ebx = native_function_address32(&::fprintf);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A2F50: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2F50u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%s\n"); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xA2F59u), LIFT_CODE_TOKEN_RVA(0xA2F57u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2F59u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    ++cpu->esi;
    cpu->esp += 0xCu;
    cpu->edi += 0x100u;
    if ((uint32_t)(cpu->esi) < (uint32_t)(lift_load32(cpu->ecx + 0x1ECu))) goto label_000A2F50;
    cpu->ebx = cpu->ecx;
    label_000A2F71: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2F71u);
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4A2F72u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2F78u);
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4A2F79u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2F7Fu);
    cpu->esp += 8u;
    label_000A2F82: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2F82u);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_000A2F84: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2F84u);
    cpu->esi = 0u;
    g_sfera_texture_cache_runtime.render_gate = (uint32_t)(cpu->esi);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x1C8u)) < (uint32_t)(0x10u)) goto label_000A2FA4;
    cpu->edx = lift_load32(cpu->ebx + 0x1B4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2FA1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A2FA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2FA4u);
    lift_store32(cpu->ebx + 0x1C8u, 0xFu);
    lift_store32(cpu->ebx + 0x1C4u, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_store8(cpu->ebx + 0x1B4u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2FC2u); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x104u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A2FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2FE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2FE8u); lift_push32(cpu, r); sfera_sub_004A2E00(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000A2FF8;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A2FF5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A2FF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A2FF8u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3000u);
    cpu->esp -= 0x11Cu;
    cpu->eax = lift_load32(cpu->esp + 0x120u);
    cpu->edx = 0x5C737265u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x128u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = 0x79616C70u;
    lift_store8(cpu->esp + 0x2Cu, cpu->eax & 0xFFu);
    cpu->eax = lift_load32(cpu->ebp + 0x9Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x138u);
    cpu->eax += 0x178u;
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000A306D;
    cpu->esi = lift_load32(cpu->eax);
    goto label_000A306F;
    label_000A306D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A306Du);
    cpu->esi = cpu->eax;
    label_000A306F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A306Fu);
    cpu->edx = (uint32_t)(uintptr_t)"";
    cpu->ecx = cpu->esi;
    label_000A3076: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3076u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A3096;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A3092;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A3096;
    cpu->ecx += 2u;
    cpu->edx += 2u;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000A3076;
    label_000A3092: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3092u);
    cpu->eax = 0u;
    goto label_000A309B;
    label_000A3096: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3096u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000A309B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A309Bu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A3192;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->esi;
    label_000A30A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A30A7u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A30A7;
    cpu->edi = (uint32_t)(cpu->esp + 0x2Cu);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_000A30B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A30B5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A30B5;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_movs8(cpu, 1u);
    --cpu->eax;
    label_000A30D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A30D2u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A30D2;
    cpu->ecx = 0x7478742Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, (uintptr_t)"r"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4A30F5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A30FBu);
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A318E;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::feof), LIFT_CODE_TOKEN_VA(0x4A3109u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A310Fu);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A3172;
    cpu->ebx = native_function_address32(&::fgets);
    cpu->esi = (uint32_t)(cpu->ebp + 0x1F4u);
    label_000A3122: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3122u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x1ECu)) >= (uint32_t)(0x63u)) goto label_000A316E;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xFDu); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xA3134u), LIFT_CODE_TOKEN_RVA(0xA3132u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3134u);
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A3140: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3140u);
    if ((uint8_t)(lift_load8(cpu->esi + cpu->eax)) == (uint8_t)(0xAu)) goto label_000A3150;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFDu)) goto label_000A3140;
    goto label_000A3154;
    label_000A3150: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3150u);
    lift_store8(cpu->esi + cpu->eax, 0u);
    label_000A3154: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3154u);
    lift_store32(cpu->ebp + 0x1ECu, (uint64_t)(lift_load32(cpu->ebp + 0x1ECu)) + 1u);
    lift_push32(cpu, cpu->edi);
    cpu->esi += 0x100u;
    lift_native_call(cpu, native_function_address32(&::feof), LIFT_CODE_TOKEN_VA(0x4A3161u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3167u);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A3122;
    label_000A316E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A316Eu);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    label_000A3172: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3172u);
    lift_store32(cpu->ebp + 0x1ECu, (uint64_t)(lift_load32(cpu->ebp + 0x1ECu)) - 1u);
    cpu->eax = lift_load32(cpu->ebp + 0x1ECu);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0x1F0u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4A3185u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A318Bu);
    cpu->esp += 4u;
    label_000A318E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A318Eu);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    label_000A3192: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3192u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A319Eu); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->ebp + 0x9Cu)) != (uint32_t)(0u)) goto label_000A31C4;
    lift_push32(cpu, 0xC6u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\EditCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A31BBu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A31C1u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000A31C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A31C4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"maxsymbols");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A31D1u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A31E4;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A31DEu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x1ACu, cpu->eax);
    label_000A31E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A31E4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"numeric");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A31F1u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A3209;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A31FEu); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->ebp + 0x1A8u, cpu->edx & 0xFFu);
    label_000A3209: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3209u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"password");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3216u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A322E;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3223u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->ebp + 0x1A9u, cpu->eax & 0xFFu);
    label_000A322E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A322Eu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"enteredOnFocus");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A323Bu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A3253;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3248u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->ebp + 0x1E2u, cpu->ecx & 0xFFu);
    label_000A3253: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3253u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"cursorcolor");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3260u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = native_function_address32(&::sscanf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A32D1;
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xA3284u), LIFT_CODE_TOKEN_RVA(0xA3282u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3284u);
    cpu->esp += 0x14u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A32AB;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"EditCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'cursorcolor'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A32A2u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A32A8u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=cpu->esp, r=(uint64_t)(0x14u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000A32AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A32ABu);
    cpu->eax = lift_load8(cpu->esp + 0x14u);
    cpu->ecx = lift_load8(cpu->esp + 0x10u);
    cpu->edx = lift_load8(cpu->esp + 0x1Cu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax |= cpu->edx;
    lift_store32(cpu->ebp + 0x1D0u, cpu->eax);
    lift_store8(cpu->ebp + 0x1E1u, 0u);
    label_000A32D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A32D1u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"cursoroffset");
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A32DEu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A3322;
    cpu->eax = (uint32_t)(cpu->ebp + 0x1A4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x1A0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xA32FBu), LIFT_CODE_TOKEN_RVA(0xA32F9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A32FBu);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000A3322;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"EditCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'cursorOffset'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3319u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A331Fu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000A3322: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3322u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x1ACu)) != (uint32_t)(0u)) goto label_000A3335;
    lift_store32(cpu->ebp + 0x1ACu, 0x100u);
    label_000A3335: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3335u);
    cpu->eax = lift_load32(cpu->ebp + 0x1ACu);
    cpu->edi = lift_load32(cpu->ebp + 0x64u);
    cpu->esi = (uint32_t)(cpu->ebp + 0x54u);
    ++cpu->eax;
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->eax)) goto label_000A3368;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(cpu->eax)) goto label_000A3368;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3355u); lift_push32(cpu, r); sfera_sub_00403CA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A3368;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000A3364;
    cpu->esi = lift_load32(cpu->esi);
    label_000A3364: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3364u);
    lift_store8(cpu->esi + cpu->edi, 0u);
    label_000A3368: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3368u);
    cpu->eax = lift_load32(cpu->ebp + 0x1ACu);
    cpu->edi = lift_load32(cpu->ebp + 0x1C4u);
    cpu->esi = (uint32_t)(cpu->ebp + 0x1B4u);
    ++cpu->eax;
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->eax)) goto label_000A33A1;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(cpu->eax)) goto label_000A33A1;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A338Eu); lift_push32(cpu, r); sfera_sub_00403CA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A33A1;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000A339D;
    cpu->esi = lift_load32(cpu->esi);
    label_000A339D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A339Du);
    lift_store8(cpu->esi + cpu->edi, 0u);
    label_000A33A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A33A1u);
    cpu->edx = lift_load8(cpu->ebp + 0x8Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = (uint32_t)(cpu->ebp + 0x1B0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)"_";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A33C0u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, (uint64_t)(lift_load32(cpu->esi)) + 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_store8(cpu->ebp + 0x4Au, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A33D2u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x11Cu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3400u);
    cpu->esp -= 0x22Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = 0u;
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Au)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_000A3428;
    g_sfera_texture_cache_runtime.render_gate = (uint32_t)(1u);
    label_000A3428: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3428u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)((cpu->eax & 0xFFu))) goto label_000A3974;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000A347B;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000A3465;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA3465u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000A3465: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3465u);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 8u);
    cpu->edi = lift_load32(cpu->edi + 0x34u);
    cpu->edi += lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    label_000A347B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A347Bu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x4Au)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A38E1;
    cpu->ebx = lift_load32(cpu->esp + 0x23Cu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + 0x15u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) < (uint8_t)(0x20u)) goto label_000A34EF;
    cpu->ecx = lift_load32(cpu->esi + 0x64u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(lift_load32(cpu->esi + 0x1ACu))) goto label_000A34EF;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1A8u)) == (uint8_t)(0u)) goto label_000A34B0;
    if ((uint8_t)((cpu->eax & 0xFFu)) < (uint8_t)(0x30u)) goto label_000A34EF;
    if ((uint8_t)((cpu->eax & 0xFFu)) > (uint8_t)(0x39u)) goto label_000A34EF;
    label_000A34B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A34B0u);
    lift_store8(cpu->esp + 0xCu, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A34EF;
    cpu->eax = lift_load32(cpu->esi + 0x1E4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A34DC;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A34D1u); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x64u);
    lift_store32(cpu->esi + 0x1E4u, cpu->ecx);
    goto label_000A34EF;
    label_000A34DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A34DCu);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A34E9u); lift_push32(cpu, r); sfera_sub_0048E480(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1E4u, (uint64_t)(lift_load32(cpu->esi + 0x1E4u)) + 1u);
    label_000A34EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A34EFu);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x14u)) != (uint8_t)(8u)) goto label_000A3517;
    if ((uint32_t)(lift_load32(cpu->esi + 0x64u)) <= (uint32_t)(0u)) goto label_000A3517;
    cpu->eax = lift_load32(cpu->esi + 0x1E4u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000A3517;
    lift_push32(cpu, 1u);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3511u); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1E4u, (uint64_t)(lift_load32(cpu->esi + 0x1E4u)) - 1u);
    label_000A3517: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3517u);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x14u)) != (uint8_t)(0x2Eu)) goto label_000A3539;
    cpu->ecx = lift_load32(cpu->esi + 0x64u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A3539;
    cpu->eax = lift_load32(cpu->esi + 0x1E4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A3539;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA3539u); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    label_000A3539: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3539u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + 0x14u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x25u)) goto label_000A3548;
    lift_store32(cpu->esi + 0x1E4u, (uint64_t)(lift_load32(cpu->esi + 0x1E4u)) - 1u);
    goto label_000A3552;
    label_000A3548: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3548u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x27u)) goto label_000A3552;
    lift_store32(cpu->esi + 0x1E4u, (uint64_t)(lift_load32(cpu->esi + 0x1E4u)) + 1u);
    label_000A3552: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3552u);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x14u)) != (uint8_t)(0x24u)) goto label_000A3562;
    lift_store32(cpu->esi + 0x1E4u, 0u);
    label_000A3562: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3562u);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x14u)) != (uint8_t)(0x23u)) goto label_000A3571;
    cpu->eax = lift_load32(cpu->esi + 0x64u);
    lift_store32(cpu->esi + 0x1E4u, cpu->eax);
    label_000A3571: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3571u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1E4u)) >= (int32_t)(uint32_t)(0u)) goto label_000A3584;
    lift_store32(cpu->esi + 0x1E4u, 0u);
    label_000A3584: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3584u);
    cpu->eax = lift_load32(cpu->esi + 0x64u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1E4u)) <= (uint32_t)(cpu->eax)) goto label_000A3595;
    lift_store32(cpu->esi + 0x1E4u, cpu->eax);
    label_000A3595: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3595u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x1A9u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esi + 0x1E8u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A35F3;
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x1C4u))) goto label_000A35F3;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A35BFu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1C4u)) <= (uint32_t)(cpu->eax)) goto label_000A35F3;
    cpu->edx = 0x10u;
    cpu->edi = cpu->edi;
    label_000A35D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A35D0u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1C8u)) < (uint32_t)(cpu->edx)) goto label_000A35E0;
    cpu->ecx = lift_load32(cpu->esi + 0x1B4u);
    goto label_000A35E6;
    label_000A35E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A35E0u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1B4u);
    label_000A35E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A35E6u);
    lift_store8(cpu->ecx + cpu->eax, 0x2Au);
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0x1C4u))) goto label_000A35D0;
    label_000A35F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A35F3u);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x14u)) != (uint8_t)(0x26u)) goto label_000A3664;
    cpu->eax = lift_load32(cpu->esi + 0x1F0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A3664;

    lift_push32(cpu, 0u);
    --cpu->eax;
    lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x1F0u, cpu->eax);

    lift_push32(cpu, 0x1198u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A361Cu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A3664;
    cpu->eax = lift_load32(cpu->esi + 0x1F0u);

    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi + 0x1F4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x1196u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3642u);
    cpu->eax = lift_load32(cpu->esi + 0x1F0u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->esi + 0x1F4u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000A3655: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3655u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A3655;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esi + 0x1E4u, (uint64_t)(lift_load32(cpu->esi + 0x1E4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_000A3664: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3664u);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x14u)) != (uint8_t)(0x28u)) goto label_000A36DF;
    cpu->eax = lift_load32(cpu->esi + 0x1F0u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->esi + 0x1ECu))) goto label_000A36DF;

    lift_push32(cpu, 0u);
    ++cpu->eax;
    lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x1F0u, cpu->eax);

    lift_push32(cpu, 0x1198u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3691u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A36DF;
    cpu->eax = lift_load32(cpu->esi + 0x1F0u);

    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi + 0x1F4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x1196u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A36B7u);
    cpu->eax = lift_load32(cpu->esi + 0x1F0u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->esi + 0x1F4u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000A36D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A36D0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A36D0;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esi + 0x1E4u, (uint64_t)(lift_load32(cpu->esi + 0x1E4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_000A36DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A36DFu);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x14u)) != (uint8_t)(9u)) goto label_000A370B;
    cpu->ecx = lift_load32(cpu->esi + 0xD8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esp + 0x24u, 0x119Au);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA370Bu); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000A370B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A370Bu);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x14u)) != (uint8_t)(0xDu)) goto label_000A38E1;
    cpu->eax = lift_load32(cpu->esi + 0xD8u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, 0x1195u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A373Bu); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }

    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x1198u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A374Du);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000A38E1;

    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->eax + 0x62u);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, 0x1197u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1ECu)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000A37B9;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3777u);
    cpu->eax = lift_load32(cpu->esi + 0x1ECu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    cpu->edx = (uint32_t)(cpu->eax + cpu->esi + 0x1F4u);
    label_000A3790: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3790u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    { uint64_t v=(uint64_t)((cpu->eax & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A3790;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1ECu)), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + 0x1ECu, v); }
    cpu->eax = lift_load32(cpu->esi + 0x1ECu);
    lift_store32(cpu->esi + 0x1F0u, cpu->eax);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    lift_store8(cpu->eax + cpu->esi + 0x1F4u, 0u);
    goto label_000A3817;
    label_000A37B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A37B9u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xA37BBu), LIFT_CODE_TOKEN_RVA(0xA37B9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A37BBu);
    cpu->eax = lift_load32(cpu->esi + 0x1ECu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    cpu->edx = (uint32_t)(cpu->eax + cpu->esi + 0x1F4u);
    (void)cpu;
    label_000A37D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A37D0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000A37D0;
    cpu->edi = (uint32_t)(cpu->esi + 0x2F4u);
    label_000A37E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A37E0u);
    cpu->eax = cpu->edi;
    cpu->edx = 0xFFFFFF00u;
    label_000A37E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A37E7u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->eax + cpu->edx, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A37E7;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x100u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A37E0;
    cpu->ecx = lift_load32(cpu->esi + 0x1ECu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    lift_store8(cpu->ecx + cpu->esi + 0x1F4u, 0u);
    cpu->edx = lift_load32(cpu->esi + 0x1ECu);
    lift_store32(cpu->esi + 0x1F0u, cpu->edx);
    label_000A3817: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3817u);
    cpu->ebx = lift_load32(cpu->esi + 0x1ECu);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000A38E0;
    cpu->ebp = (uint32_t)(cpu->esi + 0x1F4u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A3830: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3830u);
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(1u)) goto label_000A3879;
    cpu->eax = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A3879;
    cpu->ecx = cpu->ebx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->esi + 0xF4u);
    cpu->eax = cpu->ebp;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000A3850: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3850u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A3870;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_000A386C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A3870;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000A3850;
    label_000A386C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A386Cu);
    cpu->eax = 0u;
    goto label_000A3875;
    label_000A3870: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3870u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000A3875: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3875u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A388A;
    label_000A3879: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3879u);
    ++cpu->edi;
    cpu->ebp += 0x100u;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x1ECu))) goto label_000A3830;
    goto label_000A38E0;
    label_000A388A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A388Au);
    --cpu->ebx;
    cpu->ebp = cpu->edi;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000A38C3;
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(8u), 32u);
    cpu->edi = (uint32_t)(cpu->edi + cpu->esi + 0x2F4u);
    label_000A38A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A38A0u);
    cpu->eax = cpu->edi;
    cpu->edx = 0xFFFFFF00u;
    label_000A38A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A38A7u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->eax + cpu->edx, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A38A7;
    cpu->edx = lift_load32(cpu->esi + 0x1ECu);
    ++cpu->ebp;
    --cpu->edx;
    cpu->edi += 0x100u;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000A38A0;
    label_000A38C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A38C3u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1ECu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + 0x1ECu, v); }
    cpu->eax = lift_load32(cpu->esi + 0x1ECu);
    lift_store32(cpu->esi + 0x1F0u, cpu->eax);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    lift_store8(cpu->eax + cpu->esi + 0x1F4u, 0u);
    label_000A38E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A38E0u);
    cpu->ebp = lift_pop32(cpu);
    label_000A38E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A38E1u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->edi = lift_load32(cpu->esp + 0x23Cu);
    cpu->eax += lift_load32(cpu->esp + 0x14u);
    cpu->ecx += lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)((lift_load8(cpu->edi + 0xCu)) & (1u)) == 0u) goto label_000A3972;
    cpu->edx = lift_load32(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->eax)) goto label_000A3963;
    cpu->ebx = lift_load32(cpu->esi + 0x28u);
    cpu->ebx += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000A3963;
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000A3963;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000A3963;
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Au)) != (uint8_t)(0u)) goto label_000A3972;
    lift_push32(cpu, 0xDu); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3935u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x11u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3949u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x17u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A395Du); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Au, 1u);
    goto label_000A3972;
    label_000A3963: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3963u);

    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x69u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    label_000A3972: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3972u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_000A3974: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3974u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x22Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3990u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0x1199u)) goto label_000A39E0;
    cpu->eax = lift_load32(cpu->esi + 0x64u);
    lift_store32(cpu->esi + 0x1E4u, cpu->eax);
    label_000A39BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A39BDu);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A39CBu); lift_push32(cpu, r); sfera_sub_004D2DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000A39E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A39E0u);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0x1198u)) goto label_000A3A01;
    cpu->eax = lift_load8(cpu->esi + 0x4Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
    label_000A3A01: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3A01u);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0x1196u)) goto label_000A3A35;
    cpu->edx = cpu->ebx;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000A3A14;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000A3A14: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3A14u);
    cpu->eax = cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A3A20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3A20u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A3A20;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3A33u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    goto label_000A39BD;
    label_000A3A35: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3A35u);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0x1197u)) goto label_000A3A6D;
    cpu->edi = lift_load32(cpu->esi + 0x64u);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0xFAu)) goto label_000A3A4D;
    cpu->edi = 0xFAu;
    label_000A3A4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3A4Du);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x68u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x54u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000A3A58;
    cpu->eax = lift_load32(cpu->eax);
    label_000A3A58: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3A58u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4A3A5Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3A61u);
    cpu->esp += 0xCu;
    lift_store8(cpu->ebx + cpu->edi, 0u);
    goto label_000A39BD;
    label_000A3A6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3A6Du);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0x69u)) goto label_000A39BD;
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A3AAF;
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Au)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A3AAD;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1E2u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A3AAD;
    cpu->ecx = lift_load32(cpu->esi + 0xD8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x1Cu, 0x1195u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA3AADu); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000A3AAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3AADu);
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    label_000A3AAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3AAFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esi + 0x4Au, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A3AFD;
    lift_push32(cpu, 0xDu); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_store8(cpu->esi + 0x4Au, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3AD1u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x11u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3AE5u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x17u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3AF9u); lift_push32(cpu, r); sfera_sub_004B9970(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Au, 1u);
    label_000A3AFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3AFDu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3B20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3B20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3B30u); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    lift_store32(cpu->ebx + 0x198u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    lift_store32(cpu->ebx + 0x19Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    lift_store32(cpu->ebx + 0x1A0u, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0x1A4u);
    lift_store32(cpu->ebx + 0x1A4u, cpu->eax);
    cpu->ecx = lift_load8(cpu->esi + 0x1A8u);
    lift_store8(cpu->ebx + 0x1A8u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load8(cpu->esi + 0x1A9u);
    lift_store8(cpu->ebx + 0x1A9u, cpu->edx & 0xFFu);
    cpu->eax = lift_load32(cpu->esi + 0x1ACu);
    lift_push32(cpu, 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0x1ACu, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esi + 0x1B4u);
    lift_store32(cpu->ebx + 0x1B0u, cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x1B4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3BA8u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1D0u);
    lift_store32(cpu->ebx + 0x1D0u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x1D8u);
    lift_store32(cpu->ebx + 0x1D8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x1DCu);
    lift_store32(cpu->ebx + 0x1DCu, cpu->edx);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x1E0u)) & 0xFFu);
    lift_store8(cpu->ebx + 0x1E0u, cpu->eax & 0xFFu);
    cpu->ecx = lift_load8(cpu->esi + 0x1E1u);
    lift_store8(cpu->ebx + 0x1E1u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load8(cpu->esi + 0x1E2u);
    lift_store8(cpu->ebx + 0x1E2u, cpu->edx & 0xFFu);
    cpu->eax = lift_load32(cpu->esi + 0x1E4u);
    lift_store32(cpu->ebx + 0x1E4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x1E8u);
    lift_store32(cpu->ebx + 0x1E8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x1ECu);
    lift_store32(cpu->ebx + 0x1ECu, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0x1F0u);
    cpu->edx = cpu->esi;
    lift_store32(cpu->ebx + 0x1F0u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebx + 0x1F4u);
    cpu->edx -= cpu->ebx;
    cpu->ebp = 0x64u;
    label_000A3C31: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3C31u);
    cpu->esi = (uint32_t)(cpu->edx + cpu->eax);
    cpu->edi = cpu->eax;
    cpu->ecx = 0x40u;
    cpu->eax += 0x100u;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    lift_movs32(cpu, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A3C31;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3C50u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x197u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\EditCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3C84u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x65F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3C8Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A3CAC;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3CA8u); lift_push32(cpu, r); sfera_sub_004A2D20(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000A3CAE;
    label_000A3CAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3CACu);
    cpu->esi = 0u;
    label_000A3CAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3CAEu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3CBEu); lift_push32(cpu, r); sfera_sub_004A3B20(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_000A3CE6;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3CD8u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA3CE6u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000A3CE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3CE6u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3D00u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A3D57;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0x71C71C7u)) goto label_000A3D29;
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3D22u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A3D57;
    label_000A3D29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3D29u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA3D57u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000A3D57: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3D57u);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3D60u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_000A3D7D;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000A3D7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3D7Du);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0x71C71C7u)) goto label_000A3D90;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xA3D90u);
    label_000A3D90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3D90u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3D99u); lift_push32(cpu, r); sfera_sub_004A3D00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 8u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3DB0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000A3DEA;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    (void)cpu;
    label_000A3DC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3DC0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3DCCu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_store32(cpu->edi + 0x1Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x20u);
    lift_store32(cpu->edi + 0x20u, cpu->ecx);
    cpu->esi += 0x24u;
    cpu->edi += 0x24u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000A3DC0;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000A3DEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3DEAu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3E00u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000A3E14;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3E11u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A3E14: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3E14u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3E30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3E30u);
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
    label_000A3E70: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3E70u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFECu))) goto label_000A3ED9;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000A3EA3;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3E97u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x1Cu);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x20u);
    lift_store32(cpu->esi + 0x20u, cpu->ecx);
    label_000A3EA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3EA3u);
    cpu->esi += 0x24u;
    lift_store8(cpu->ebp + 0xFFFFFFFCu, cpu->ebx & 0xFFu);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    cpu->edi += 0x24u;
    goto label_000A3E70;
    label_000A3ED9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3ED9u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3EB1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3EB1u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_000A3ED0;
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    cpu->edi = cpu->edi;
    label_000A3EC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3EC0u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3EC9u); lift_push32(cpu, r); sfera_sub_004A3E00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += 0x24u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_000A3EC0;
    label_000A3ED0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3ED0u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3ED9u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3EF0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_000A3F29;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000A3F00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3F00u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000A3F11;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3F0Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A3F11: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3F11u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->esi += 0x24u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_000A3F00;
    label_000A3F29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3F29u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3F30u);
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
    label_000A3F70: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3F70u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFECu))) goto label_000A3FD9;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000A3FA3;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3F97u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x1Cu);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x20u);
    lift_store32(cpu->esi + 0x20u, cpu->ecx);
    label_000A3FA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3FA3u);
    cpu->esi += 0x24u;
    lift_store8(cpu->ebp + 0xFFFFFFFCu, cpu->ebx & 0xFFu);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    cpu->edi += 0x24u;
    goto label_000A3F70;
    label_000A3FD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3FD9u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3FB1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3FB1u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_000A3FD0;
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    cpu->edi = cpu->edi;
    label_000A3FC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3FC0u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3FC9u); lift_push32(cpu, r); sfera_sub_004A3E00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += 0x24u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_000A3FC0;
    label_000A3FD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3FD0u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A3FD9u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A3FF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A3FF0u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4006u); lift_push32(cpu, r); sfera_sub_004A3EF0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A40FA(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A40FAu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4103u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A410Fu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4A410Fu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A4110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4110u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A412Bu); lift_push32(cpu, r); sfera_sub_004A3F30(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A4130(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000A4130;
    label_000A4010: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4010u);
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
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(0x71C71C7u)) goto label_000A4053;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xA4053u);
    label_000A4053: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4053u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebx)) goto label_000A40E6;
    cpu->edi = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4078u); lift_push32(cpu, r); sfera_sub_004A3D00(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4094u); lift_push32(cpu, r); sfera_sub_004A3E30(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A40CC;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A40C1u); lift_push32(cpu, r); sfera_sub_004A3EF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A40C9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A40CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A40CCu);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 8u));
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    lift_store32(cpu->esi + 4u, cpu->edx);
    lift_store32(cpu->esi, cpu->eax);
    label_000A40E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A40E6u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000A4130: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4130u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    cpu->edx = 0x71C71C7u;
    cpu->edx -= cpu->eax;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->esi)) goto label_000A4164;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xA4164u);
    label_000A4164: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4164u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->esi += cpu->eax;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000A41A6;
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->edi = 0x71C71C7u;
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000A4193;
    cpu->eax = 0u;
    goto label_000A4195;
    label_000A4193: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4193u);
    cpu->eax += cpu->edx;
    label_000A4195: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4195u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->esi)) goto label_000A419B;
    cpu->eax = cpu->esi;
    label_000A419B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A419Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->esp + 4u, cpu->eax);
    goto label_000A4010;
    label_000A41A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A41A6u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A41B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A41B0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A41B8u); lift_push32(cpu, r); sfera_sub_004BFB90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    std::construct_at(reinterpret_cast<SphereUI::FilterListCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x1F8u, 0xFFu);
    lift_store32(cpu->esi + 0x1FCu, cpu->eax);
    lift_store32(cpu->esi + 0x200u, cpu->eax);
    lift_store32(cpu->esi + 0x204u, cpu->eax);
    lift_store32(cpu->esi + 0x20Cu, cpu->eax);
    lift_store32(cpu->esi + 0x50u, 0x12u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A41F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A41F0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x1FCu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A4224;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0x208u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4215u); lift_push32(cpu, r); sfera_sub_004A3EF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1FCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4221u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A4224: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4224u);
    lift_store32(cpu->esi + 0x1FCu, 0u);
    lift_store32(cpu->esi + 0x200u, 0u);
    lift_store32(cpu->esi + 0x204u, 0u);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004BFC50(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A4250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4250u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000A43C4;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->ebx)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A42B3;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A43C3;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4293u); lift_push32(cpu, r); sfera_sub_004A3DB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A42A8u); lift_push32(cpu, r); sfera_sub_004A3EF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000A42B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A42B3u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edi)) goto label_000A431D;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A42E0u); lift_push32(cpu, r); sfera_sub_004A3DB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A42F3u); lift_push32(cpu, r); sfera_sub_004A3EF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->ebx)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->ebp = lift_pop32(cpu);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000A431D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A431Du);
    cpu->edx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000A4371;
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 8u));
    cpu->edi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A434Cu); lift_push32(cpu, r); sfera_sub_004A3DB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ebx = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4365u); lift_push32(cpu, r); sfera_sub_004A3F30(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000A4371: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4371u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000A438C;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4381u); lift_push32(cpu, r); sfera_sub_004A3FF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4389u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A438C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A438Cu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->ebx)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A43AAu); lift_push32(cpu, r); sfera_sub_004A3D60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A43C2;
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A43BFu); lift_push32(cpu, r); sfera_sub_004A4110(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000A43C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A43C2u);
    cpu->ebp = lift_pop32(cpu);
    label_000A43C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A43C3u);
    cpu->edi = lift_pop32(cpu);
    label_000A43C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A43C4u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A43D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A43D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ecx)) goto label_000A446A;
    cpu->eax = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->esi)) goto label_000A446A;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_000A4428;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA4428u); lift_push32(cpu, r); sfera_sub_004A4130(cpu,r); if (cpu->eip != r) return; }
    label_000A4428: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4428u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->esi = lift_load32(cpu->edi + 4u);
    cpu->ebx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000A44B4;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A445Cu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebx + 0x1Cu);
    lift_store32(cpu->esi + 0x1Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebx + 0x20u);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    goto label_000A44B4;
    label_000A446A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A446Au);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_000A4478;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA4478u); lift_push32(cpu, r); sfera_sub_004A4130(cpu,r); if (cpu->eip != r) return; }
    label_000A4478: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4478u);
    cpu->ebx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x1Cu, 1u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->eax)) goto label_000A44B4;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebx + 0x14u, 0xFu);
    lift_store32(cpu->ebx + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_store8(cpu->ebx, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A44A8u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    lift_store32(cpu->ebx + 0x1Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x20u);
    lift_store32(cpu->ebx + 0x20u, cpu->edx);
    label_000A44B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A44B4u);
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) + (uint64_t)(0x24u) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A44D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A44D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A44D8u); lift_push32(cpu, r); sfera_sub_004A41F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000A44E8;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A44E5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A44E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A44E8u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A44F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A44F0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A44FEu); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    cpu->edx = (uint32_t)(cpu->edi + 0x1A0u);
    lift_store32(cpu->esi + 0x19Cu, cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1A0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4528u); lift_push32(cpu, r); sfera_sub_004A4250(cpu,r); if (cpu->eip != r) return; }
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
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1CCu)) & 0xFFu);
    lift_store8(cpu->esi + 0x1CCu, cpu->ecx & 0xFFu);
    cpu->edx = lift_load8(cpu->edi + 0x1CDu);
    lift_store8(cpu->esi + 0x1CDu, cpu->edx & 0xFFu);
    cpu->eax = lift_load8(cpu->edi + 0x1CEu);
    lift_store8(cpu->esi + 0x1CEu, cpu->eax & 0xFFu);
    cpu->ecx = lift_load32(cpu->edi + 0x1D0u);
    lift_store32(cpu->esi + 0x1D0u, cpu->ecx);
    cpu->edx = lift_load8(cpu->edi + 0x1D4u);
    lift_store8(cpu->esi + 0x1D4u, cpu->edx & 0xFFu);
    cpu->eax = lift_load32(cpu->edi + 0x1D8u);
    lift_store32(cpu->esi + 0x1D8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1DCu);
    lift_store32(cpu->esi + 0x1DCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1E0u);
    lift_store32(cpu->esi + 0x1E0u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x1E4u);
    lift_store32(cpu->esi + 0x1E4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1E8u);
    lift_store32(cpu->esi + 0x1E8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1ECu);
    lift_store32(cpu->esi + 0x1ECu, cpu->edx);
    cpu->eax = lift_load8(cpu->edi + 0x1F0u);
    lift_store8(cpu->esi + 0x1F0u, cpu->eax & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A4620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4620u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x200u);
    cpu->eax = lift_load32(cpu->esi + 0x1FCu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A4664;
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4642u); lift_push32(cpu, r); sfera_sub_004A3DB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x200u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x208u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A465Du); lift_push32(cpu, r); sfera_sub_004A3EF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x200u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    label_000A4664: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4664u);
    lift_store32(cpu->esi + 0x20Cu, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A4680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4680u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = lift_load32(cpu->esp + 0x4Cu);
    cpu->esi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->esi + 0x1B0u);
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->eax)) goto label_000A4737;
    lift_store32(cpu->esp + 0x28u, 0xFu);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store8(cpu->esp + 0x14u, cpu->eax & 0xFFu);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->eax)) goto label_000A46E1;
    cpu->ebp = (uint32_t)(uintptr_t)" ";
    label_000A46E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A46E1u);
    cpu->eax = cpu->ebp;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000A46E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A46E6u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A46E6;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A46FAu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    cpu->eax = lift_load32(cpu->esp + 0x50u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1FCu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A471Au); lift_push32(cpu, r); sfera_sub_004A43D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) < (uint32_t)(0x10u)) goto label_000A4870;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A472Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    goto label_000A4870;
    label_000A4737: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4737u);
    cpu->ecx = lift_load32(cpu->esi + 0x200u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x1FCu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->ebx)) goto label_000A47F4;
    lift_store32(cpu->esp + 0x28u, 0xFu);
    lift_store32(cpu->esp + 0x24u, 0u);
    lift_store8(cpu->esp + 0x14u, 0u);
    cpu->ebx = 1u;
    lift_store32(cpu->esp + 0x44u, cpu->ebx);
    if ((uint32_t)(cpu->ebp) != 0u) goto label_000A4783;
    cpu->ebp = (uint32_t)(uintptr_t)" ";
    label_000A4783: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4783u);
    cpu->eax = cpu->ebp;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000A4788: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4788u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A4788;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A479Cu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    cpu->eax = lift_load32(cpu->esp + 0x54u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1FCu);
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A47BCu); lift_push32(cpu, r); sfera_sub_004A43D0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x20Cu, (uint64_t)(lift_load32(cpu->esi + 0x20Cu)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esi + 0x20Cu);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0x1B0u))) goto label_000A47DA;
    lift_store32(cpu->esi + 0x20Cu, 0u);
    label_000A47DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A47DAu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) < (uint32_t)(0x10u)) goto label_000A4870;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A47EFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    goto label_000A4870;
    label_000A47F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A47F4u);
    if ((uint32_t)(cpu->ebp) != 0u) goto label_000A47FD;
    cpu->ebp = (uint32_t)(uintptr_t)" ";
    label_000A47FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A47FDu);
    cpu->eax = cpu->ebp;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000A4802: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4802u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A4802;
    cpu->ecx = lift_load32(cpu->esi + 0x1FCu);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x20Cu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4824u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x20Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->esi + 0x1FCu);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x20u, cpu->ecx);
    cpu->eax = lift_load32(cpu->esi + 0x20Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->esi + 0x1FCu);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x1Cu, cpu->ecx);
    lift_store32(cpu->esi + 0x20Cu, (uint64_t)(lift_load32(cpu->esi + 0x20Cu)) + 1u);
    cpu->eax = lift_load32(cpu->esi + 0x20Cu);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0x1B0u))) goto label_000A4870;
    lift_store32(cpu->esi + 0x20Cu, 0u);
    label_000A4870: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4870u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A48A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A48A0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x1965u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A4998;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A497E;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A48DA;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A48D3u); lift_push32(cpu, r); sfera_sub_004C08C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000A48DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A48DAu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1F8u)) == (uint32_t)(cpu->eax)) goto label_000A4972;
    lift_store32(cpu->esi + 0x1F8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x200u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x1FCu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A4972;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4916u); lift_push32(cpu, r); sfera_sub_004C0170(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x200u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x1FCu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x38E38E39u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000A4972;
    cpu->edi = 0u;
    cpu->ebx = cpu->eax;
    cpu->ebp = (uint32_t)(cpu->edi + 0x10u);
    cpu->edi = cpu->edi;
    label_000A4940: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4940u);
    cpu->ecx = lift_load32(cpu->esi + 0x1FCu);
    cpu->edx = lift_load32(cpu->edi + cpu->ecx + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->edi + cpu->ecx);
    if ((uint32_t)((lift_load32(cpu->esi + 0x1F8u)) & (cpu->edx)) == 0u) goto label_000A496C;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_000A495E;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000A4960;
    label_000A495E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A495Eu);
    cpu->ecx = cpu->eax;
    label_000A4960: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4960u);
    cpu->eax = lift_load32(cpu->eax + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA496Cu); lift_push32(cpu, r); sfera_sub_004C0590(cpu,r); if (cpu->eip != r) return; }
    label_000A496C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A496Cu);
    cpu->edi += 0x24u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A4940;
    label_000A4972: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4972u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000A497E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A497Eu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4985u); lift_push32(cpu, r); sfera_sub_004A4620(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A498Cu); lift_push32(cpu, r); sfera_sub_004C0170(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000A4998: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4998u);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000A4972;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x18u), 32u);
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A49BAu); lift_push32(cpu, r); sfera_sub_004A4680(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((lift_load32(cpu->esi + 0x1F8u)) & (cpu->edi)) == 0u) goto label_000A4972;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0xE11u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A49D0u); lift_push32(cpu, r); sfera_sub_004C08C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A49E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A49E0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x48u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\FilterListCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4A15u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x210u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4A1Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000A4A6A;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4A39u); lift_push32(cpu, r); sfera_sub_004BFB90(cpu,r); if (cpu->eip != r) return; }
    std::construct_at(reinterpret_cast<SphereUI::FilterListCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x1F8u, 0xFFu);
    lift_store32(cpu->esi + 0x1FCu, cpu->ebx);
    lift_store32(cpu->esi + 0x200u, cpu->ebx);
    lift_store32(cpu->esi + 0x204u, cpu->ebx);
    lift_store32(cpu->esi + 0x20Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x50u, 0x12u);
    goto label_000A4A6C;
    label_000A4A6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4A6Au);
    cpu->esi = 0u;
    label_000A4A6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4A6Cu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4A7Cu); lift_push32(cpu, r); sfera_sub_004A44F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x1F8u);
    cpu->ecx = (uint32_t)(cpu->edi + 0x1FCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1FCu);
    lift_store32(cpu->esi + 0x1F8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4A9Au); lift_push32(cpu, r); sfera_sub_004A4250(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0x20Cu);
    lift_store32(cpu->esi + 0x20Cu, cpu->edx);
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(cpu->ebx)) goto label_000A4ACD;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4ABFu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA4ACDu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000A4ACD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4ACDu);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1D0u)) == (uint32_t)(cpu->ebx)) goto label_000A4AF0;
    cpu->ecx = lift_load32(cpu->edi + 0x1D0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4AE2u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x1D0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA4AF0u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000A4AF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4AF0u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A4B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4B10u);
    cpu->edx = 0x1B4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4B1Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x9600u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4B29u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    g_sfera_font_factory_runtime.vertex_buffer = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A4B48;
    lift_push32(cpu, (uint32_t)(uintptr_t)"Can't initialize vertex buffer for font factory.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4B3Fu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4B45u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000A4B48: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4B48u);
    g_sfera_font_factory_runtime.vertex_count = (uint32_t)(0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A4B60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4B60u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A4BAC;
    cpu->edx = 0x39Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4B7Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000A4B84: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4B84u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A4B84;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4B94u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->eax;
    cpu->edi = cpu->edi;
    label_000A4BA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4BA0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000A4BA0;
    goto label_000A4BB3;
    label_000A4BAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4BACu);
    lift_store32(cpu->esi + 8u, 0u);
    label_000A4BB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4BB3u);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000A4BCF;
    cpu->edx = 0x3A1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4BC6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4BCCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A4BCF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4BCFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A4BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4BE0u);
    cpu->esp -= 0x110u;
    cpu->eax = lift_load32(cpu->esp + 0x114u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x120u);
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x128u);
    lift_push32(cpu, (uintptr_t)"rb"); lift_push32(cpu, cpu->ebp);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4A4C1Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4C22u);
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->edi) != 0u) goto label_000A4C46;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Can't open font '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4C36u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4C3Cu); lift_push32(cpu, r); sfera_sub_0042E480(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    goto label_000A4D8F;
    label_000A4C46: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4C46u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x4A4C58u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4C5Eu);
    cpu->esp += 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0xCu)) == (uint32_t)(0x544E4653u)) goto label_000A4C7C;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4A4C6Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4C72u);
    cpu->esp += 4u;
    cpu->eax = 0u;
    goto label_000A4D8F;
    label_000A4C7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4C7Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::fgetc);
    cpu->ebp = 0u;
    label_000A4C85: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4C85u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xA4C88u), LIFT_CODE_TOKEN_RVA(0xA4C86u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4C88u);
    cpu->esp += 4u;
    lift_store8(cpu->esp + cpu->ebp + 0x1Cu, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A4C9C;
    ++cpu->ebp;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0x100u)) goto label_000A4C85;
    label_000A4C9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4C9Cu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = cpu->ebx;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A4CAA;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    label_000A4CAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4CAAu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4CB0u); lift_push32(cpu, r); sfera_sub_004A4B60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0u;
    label_000A4CB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4CB2u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xA4CB5u), LIFT_CODE_TOKEN_RVA(0xA4CB3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4CB5u);
    cpu->esp += 4u;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000A4CC5;
    ++cpu->ebp;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0x100u)) goto label_000A4CB2;
    label_000A4CC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4CC5u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4CD0u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000A4CFD;
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"Can't load texture '%s' for font '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4CE6u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4CECu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4A4CEDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4CF3u);
    cpu->esp += 0x14u;
    cpu->eax = 0u;
    goto label_000A4D8E;
    label_000A4CFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4CFDu);
    cpu->esi = native_function_address32(&::fread);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->ebx + 0xCu);
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xA4D0Eu), LIFT_CODE_TOKEN_RVA(0xA4D0Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4D0Eu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->ebp = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xA4D19u), LIFT_CODE_TOKEN_RVA(0xA4D17u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4D19u);
    cpu->esp += 0x20u;
    cpu->edx = 0x3DBu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4D2Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1C00u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4D35u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1C00u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebx + 4u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A4D40u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4D45u);
    cpu->esp += 0x10u;
    cpu->esi = 0x380u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A4D50: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4D50u);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x4A4D5Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4D61u);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ebp)) & 0xFFFFu);
    lift_store16(cpu->esi + cpu->ecx + 6u, (uint64_t)(lift_load16(cpu->esi + cpu->ecx + 6u)) - (uint64_t)((cpu->edx & 0xFFFFu)) - (uint64_t)(0u));
    cpu->eax = (uint32_t)(cpu->esi + cpu->ecx + 6u);
    cpu->esi += 0x1Cu;
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->esi) < (uint32_t)(0x1C00u)) goto label_000A4D50;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4A4D80u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4D86u);
    cpu->esp += 4u;
    cpu->eax = 1u;
    label_000A4D8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4D8Eu);
    cpu->esi = lift_pop32(cpu);
    label_000A4D8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4D8Fu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x110u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A4DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4DB0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(0u)) goto label_000A4DD4;
    cpu->edx = 0x38Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4DC8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4DD1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A4DD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4DD4u);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(0u)) goto label_000A4DF5;
    cpu->edx = 0x38Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4DE9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4DF2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A4DF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4DF5u);
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000A4E05;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4E02u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A4E05: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4E05u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A4E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4E10u);
    cpu->esp -= 0x4Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_screen_clip_runtime.bottom))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_x87_pop(cpu);
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000A5250;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0xCu))))));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_screen_clip_runtime.top))));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_000A5252;
    if ((uint8_t)(lift_load8(cpu->esp + 0x60u)) == (uint8_t)(0u)) goto label_000A4E62;
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA4E62u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000A4E62: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4E62u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A4E71u); lift_push32(cpu, r); sfera_sub_0044FCB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_font_factory_runtime.vertex_count;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x4ACu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000A4E90;
    cpu->edi = cpu->edx;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->edx += g_sfera_font_factory_runtime.vertex_buffer;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    goto label_000A4EA3;
    label_000A4E90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4E90u);
    cpu->edx = g_sfera_font_factory_runtime.vertex_buffer;
    cpu->eax = 0u;
    g_sfera_font_factory_runtime.vertex_count = (uint32_t)(cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->edi = cpu->eax;
    label_000A4EA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4EA3u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    cpu->esi = lift_load32(cpu->esp + 0x68u);
    lift_x87_push(cpu, 0.5);
    cpu->ebx = 0u;
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    cpu->ebp = 0u;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 0x64u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A5236;
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, 1.0);
    goto label_000A4EDD;
    label_000A4EDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4EDBu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_000A4EDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4EDDu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    ++cpu->esi;
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xAu)) goto label_000A4F0A;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ecx + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x64u))));
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    goto label_000A51EA;
    label_000A4F0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4F0Au);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000A51F7;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A4F3B;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = (int16_t)(lift_load16(cpu->ecx + 0x388u));
    lift_store32(cpu->esp + 0x60u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x60u)))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    goto label_000A51EA;
    label_000A4F3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4F3Bu);
    cpu->eax = cpu->eax & 0xFFu;
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->eax = lift_load16(cpu->ecx);
    lift_store32(cpu->esp + 0x68u, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x68u)))));
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_screen_clip_runtime.left))));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_000A4F92;
    cpu->ecx = (int16_t)(lift_load16(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x60u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x60u)))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    goto label_000A51EA;
    label_000A4F92: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A4F92u);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_screen_clip_runtime.right))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 4u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000A51FB;
    cpu->eax = (int16_t)(lift_load16(cpu->ecx + 4u));
    lift_store32(cpu->esp + 0x68u, cpu->eax);
    cpu->eax = (int16_t)(lift_load16(cpu->ecx + 6u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x68u)))));
    lift_store32(cpu->esp + 0x68u, cpu->eax);
    cpu->eax = lift_load16(cpu->ecx + 2u);
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store32(cpu->esp + 0x50u, 0u);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = (uint32_t)(cpu->esp + 0x3Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u));
    cpu->edi = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x68u)))));
    lift_store32(cpu->esp + 0x68u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x68u)))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x18u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x4Cu, cpu->ecx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    cpu->ecx = 8u;
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x68u));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u));
    lift_movs32(cpu, 1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x50u, 0u);
    cpu->ecx = 8u;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    cpu->esi = (uint32_t)(cpu->esp + 0x3Cu);
    cpu->edi = (uint32_t)(cpu->edx + 0x20u);
    lift_movs32(cpu, 1u);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    lift_store32(cpu->esp + 0x50u, 0u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->edi = (uint32_t)(cpu->edx + 0x40u);
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 8u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    cpu->esi = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u));
    lift_movs32(cpu, 1u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->edi = (uint32_t)(cpu->edx + 0x60u);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->ebx + 2u);
    cpu->ecx = 8u;
    cpu->esi = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x50u, 0u);
    lift_movs32(cpu, 1u);
    lift_store16(((uint32_t)(cpu->ebp) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_font_factory_runtime.quad_indices[0]), cpu->eax & 0xFFFFu);
    cpu->eax = (uint32_t)(cpu->ebx + 3u);
    lift_store16(((uint32_t)(cpu->ebp) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_font_factory_runtime.quad_indices[2]), cpu->eax & 0xFFFFu);
    lift_store16(((uint32_t)(cpu->ebp) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_font_factory_runtime.quad_indices[4]), cpu->eax & 0xFFFFu);
    cpu->eax = g_sfera_font_factory_runtime.vertex_count;
    cpu->ecx = (uint32_t)(cpu->ebx + 1u);
    lift_store16(((uint32_t)(cpu->ebp) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_font_factory_runtime.quad_indices[1]), cpu->ebx & 0xFFFFu);
    lift_store16(((uint32_t)(cpu->ebp) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_font_factory_runtime.quad_indices[5]), cpu->ebx & 0xFFFFu);
    cpu->eax += 4u;
    lift_store16(((uint32_t)(cpu->ebp) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_font_factory_runtime.quad_indices[3]), cpu->ecx & 0xFFFFu);
    cpu->edx -= 0xFFFFFF80u;
    cpu->ebx += 4u;
    cpu->ebp += 6u;
    g_sfera_font_factory_runtime.vertex_count = (uint32_t)(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x4AAu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000A51C0;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x20u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(g_sfera_font_factory_runtime.vertex_buffer), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = 0xAAAAAAABu;
    lift_push32(cpu, cpu->edx);
    lift_multiply_accumulator(cpu, cpu->ebp, 32u, 0u);
    lift_push32(cpu, 0x65u); lift_push32(cpu, (uintptr_t)&g_sfera_font_factory_runtime.quad_indices[0]);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A51AAu); lift_push32(cpu, r); sfera_sub_004D8FE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_font_factory_runtime.vertex_buffer;
    lift_x87_push(cpu, 0.0);
    g_sfera_font_factory_runtime.vertex_count = (uint32_t)(cpu->ebx);
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->ebp = 0u;
    label_000A51C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A51C0u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->ecx = (int16_t)(lift_load16(cpu->eax + 8u));
    cpu->esi = lift_load32(cpu->esp + 0x38u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x68u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x68u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x60u))));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_000A51EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A51EAu);
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0u)) goto label_000A4EDB;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000A51FF;
    label_000A51F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A51F7u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    goto label_000A51EA;
    label_000A51FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A51FBu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000A51FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A51FFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A5238;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = 0xAAAAAAABu;
    lift_push32(cpu, 0x20u);
    lift_multiply_accumulator(cpu, cpu->ebp, 32u, 0u);
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(g_sfera_font_factory_runtime.vertex_buffer), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x65u); lift_push32(cpu, (uintptr_t)&g_sfera_font_factory_runtime.quad_indices[0]); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5234u); lift_push32(cpu, r); sfera_sub_004D8FE0(cpu,r); if (cpu->eip != r) return; }
    goto label_000A5238;
    label_000A5236: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5236u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000A5238: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5238u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x6Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A5252;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5249u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    lift_return(cpu, 16u, stop_address); return;
    label_000A5250: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5250u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000A5252: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5252u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5260u);
    cpu->eax = g_sfera_font_factory_runtime.fonts_end;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(g_sfera_font_factory_runtime.fonts_begin), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5270u);
    cpu->esp -= 8u;
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_font_factory_runtime.fonts_end;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_store32(cpu->esp + 4u, cpu->esi);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edx)) goto label_000A5299;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid vector<T> subscript");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xA5299u);
    label_000A5299: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5299u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->eax = cpu->esi;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000A52A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A52A1u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000A52A1;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = 0u;
    cpu->esi = 0u;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->ebp, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000A52EF;
    label_000A52C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A52C2u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + cpu->edx)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0xB8u)) goto label_000A530C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(0xE5u) & 0xFFu);
    label_000A52D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A52D0u);
    cpu->edx = cpu->edx & 0xFFu;
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    cpu->eax -= cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = (int16_t)(lift_load16(cpu->edx + ((uint32_t)(cpu->eax) * 4u) + 8u));
    cpu->esi += cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    label_000A52EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A52EAu);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->eax)) goto label_000A52C2;
    label_000A52EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A52EFu);
    cpu->ecx = lift_load32(cpu->ecx + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx += cpu->ebx;
    lift_store32(cpu->edx, cpu->ecx);
    if ((uint32_t)(cpu->esi) <= (uint32_t)(lift_load32(cpu->ebp))) goto label_000A5302;
    lift_store32(cpu->ebp, cpu->esi);
    label_000A5302: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5302u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
    label_000A530C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A530Cu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0xA8u)) goto label_000A5315;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(0xC5u) & 0xFFu);
    goto label_000A52D0;
    label_000A5315: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5315u);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0xAu)) goto label_000A52D0;
    cpu->ebx += lift_load32(cpu->ecx + 0xCu);
    if ((uint32_t)(cpu->esi) <= (uint32_t)(lift_load32(cpu->ebp))) goto label_000A5325;
    lift_store32(cpu->ebp, cpu->esi);
    label_000A5325: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5325u);
    cpu->esi = 0u;
    goto label_000A52EA;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5330u);
    cpu->esp -= 8u;
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    lift_store32(cpu->esp, cpu->ecx);
    cpu->ecx = g_sfera_font_factory_runtime.fonts_end;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_store32(cpu->esp + 8u, cpu->edx);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->esi)) goto label_000A535E;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid vector<T> subscript");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xA535Eu);
    label_000A535E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A535Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->esi = 0u;
    cpu->ebp = 0u;
    cpu->ebx = 0u;
    lift_store32(cpu->ecx, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_000A53A0;
    label_000A5374: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5374u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xB8u)) goto label_000A53BB;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(0xE5u) & 0xFFu);
    label_000A5381: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5381u);
    cpu->eax = cpu->eax & 0xFFu;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx -= cpu->eax;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->edx = (int16_t)(lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 8u));
    cpu->esi += cpu->edx;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    label_000A539B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A539Bu);
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->edx)) goto label_000A5374;
    label_000A53A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A53A0u);
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->eax += cpu->ebp;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->edx, cpu->eax);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->esi) <= (uint32_t)(lift_load32(cpu->ecx))) goto label_000A53B4;
    lift_store32(cpu->ecx, cpu->esi);
    label_000A53B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A53B4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_000A53BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A53BBu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xA8u)) goto label_000A53C3;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(0xC5u) & 0xFFu);
    goto label_000A5381;
    label_000A53C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A53C3u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xAu)) goto label_000A5381;
    cpu->ebp += lift_load32(cpu->edi + 0xCu);
    if ((uint32_t)(cpu->esi) <= (uint32_t)(lift_load32(cpu->ecx))) goto label_000A53D0;
    lift_store32(cpu->ecx, cpu->esi);
    label_000A53D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A53D0u);
    cpu->esi = 0u;
    goto label_000A539B;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A53E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A53E0u);
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_font_factory_runtime.fonts_end;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->edx)) goto label_000A5400;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid vector<T> subscript");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xA5400u);
    label_000A5400: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5400u);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0xB8u)) goto label_000A5425;
    cpu->ecx = (int16_t)(lift_load16(cpu->eax + 0x1914u));
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000A5425: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5425u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0xA8u)) goto label_000A543B;
    cpu->ecx = (int16_t)(lift_load16(cpu->eax + 0x1594u));
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000A543B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A543Bu);
    cpu->ecx = cpu->ecx & 0xFFu;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->edx -= cpu->ecx;
    cpu->ecx = (int16_t)(lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 8u));
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5460u);
    cpu->ecx = g_sfera_font_factory_runtime.fonts_end;
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    cpu->edx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->edx) == 0u) goto label_000A54E9;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000A5480: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5480u);
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    if ((uint32_t)(cpu->esi) == 0u) goto label_000A54DD;
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(0u)) goto label_000A54A8;
    cpu->edx = 0x38Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A549Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A54A5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A54A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A54A8u);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(0u)) goto label_000A54C9;
    cpu->edx = 0x38Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A54BDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A54C6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A54C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A54C9u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A54CFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_font_factory_runtime.fonts_end;
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    cpu->esp += 4u;
    label_000A54DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A54DDu);
    cpu->edx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    { uint64_t l=(uint64_t)(cpu->edi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->edx)) goto label_000A5480;
    label_000A54E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A54E9u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000A5502;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4A54F3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A54F9u);
    cpu->esp += 0xCu;
    g_sfera_font_factory_runtime.fonts_end = (uint32_t)(cpu->esi);
    label_000A5502: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5502u);
    { uint64_t l=(uint64_t)(g_sfera_font_factory_runtime.vertex_buffer), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A5534;
    cpu->edx = 0x1EEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A551Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_font_factory_runtime.vertex_buffer;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5527u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    g_sfera_font_factory_runtime.vertex_buffer = (uint32_t)(0u);
    label_000A5534: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5534u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5540u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebx = cpu->ecx;
    cpu->edx = 0x1C3u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5558u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A555Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0u;
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_000A557E;
    lift_store32(cpu->eax, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 4u, cpu->ebp);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    lift_store32(cpu->eax + 0xCu, cpu->ebp);
    lift_store32(cpu->eax + 0x10u, cpu->ebp);
    cpu->esi = cpu->eax;
    goto label_000A5580;
    label_000A557E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A557Eu);
    cpu->esi = 0u;
    label_000A5580: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5580u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A558Eu); lift_push32(cpu, r); sfera_sub_004A4BE0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A55B6;
    cpu->edx = 0x1C6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A55A1u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebp)) goto label_000A55AE;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA55AEu); lift_push32(cpu, r); sfera_sub_004A4DB0(cpu,r); if (cpu->eip != r) return; }
    label_000A55AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A55AEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000A55B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A55B6u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_font_factory_runtime.fonts_begin;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A55C5u); lift_push32(cpu, r); sfera_sub_004BDF90(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A55D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A55D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A55D8u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    std::construct_at(reinterpret_cast<SphereUI::FontPicker*>(cpu->esi));
    lift_store32(cpu->esi + 0x50u, 0x18u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5600(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5600u);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x48u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x48u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A56CA;
    if ((uint32_t)(lift_load32(cpu->esi + 0x198u)) == (uint32_t)(0u)) goto label_000A5637;
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000A5637: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5637u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x19Cu)) == (uint32_t)(0u)) goto label_000A564E;
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000A564E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A564Eu);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A565Au); lift_push32(cpu, r); sfera_sub_004D32C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000A56CA;
    cpu->edi = 0x1DE4u;
    label_000A5664: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5664u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x2Cu)) != (uint32_t)(0x157Du)) goto label_000A56B9;
    if ((uint32_t)(lift_load32(cpu->esi + 0x19Cu)) == (uint32_t)(0u)) goto label_000A56B9;
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->eax += 2u;
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A568Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    cpu->eax = lift_load32(cpu->esi + 0xD8u);
    cpu->ecx += 2u;
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA56B9u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000A56B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A56B9u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A56C5u); lift_push32(cpu, r); sfera_sub_004D32C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000A5664;
    label_000A56CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A56CAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A56E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A56E0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000A579C;
    if ((uint8_t)((lift_load8(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000A579C;
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A5748;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xDCu)) == (uint32_t)(cpu->eax)) goto label_000A573B;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 4u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000A5724;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A5724: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5724u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000A573B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A573Bu);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000A5748: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5748u);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A579C;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xDCu)) == (uint32_t)(cpu->eax)) goto label_000A578B;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 4u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000A5774;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000A5774: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5774u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000A578B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A578Bu);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    lift_return(cpu, 0u, stop_address); return;
    label_000A579C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A579Cu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A57A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A57A0u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x1DE2u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A57E4;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A57BB;
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->esp + 4u, cpu->edx);
    sfera_sub_004D2DD0(cpu, stop_address); return;
    label_000A57BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A57BBu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x19Cu)) == (uint32_t)(0u)) goto label_000A57F0;
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000A57F0;
    cpu->ecx = lift_load32(cpu->ecx + 0x19Cu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->getFont(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A57D9u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000A57E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A57E4u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    label_000A57F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A57F0u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5800u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x9Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A582C;
    lift_push32(cpu, 0x66u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\FontPicker.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5823u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5829u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000A582C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A582Cu);
    cpu->edi = lift_load32(cpu->esp + 0x30u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A583Cu); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"text");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5854u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A587C;
    lift_push32(cpu, 2u); lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A586Eu); lift_push32(cpu, r); sfera_sub_004D4230(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA587Cu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000A587C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A587Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"spinButton");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5890u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A58B4;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x10u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A58A6u); lift_push32(cpu, r); sfera_sub_004D4230(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA58B4u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000A58B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A58B4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A58C0u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A58D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A58D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::FontPicker*>(cpu->esi));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x198u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A593B;
    cpu->edx = 0x82u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\FontPicker.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A591Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A5931;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000A5931: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5931u);
    lift_store32(cpu->esi + 0x198u, 0u);
    label_000A593B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A593Bu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x19Cu)) == (uint32_t)(0u)) goto label_000A5970;
    cpu->edx = 0x87u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\FontPicker.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5953u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A5966;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000A5966: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5966u);
    lift_store32(cpu->esi + 0x19Cu, 0u);
    label_000A5970: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5970u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A597Fu); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5990u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x8Eu); lift_push32(cpu, (uintptr_t)"SphereUI::FontPicker::setFont"); lift_push32(cpu, (uintptr_t)"%s():%d font = %d");
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A59ADu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A59B3u); lift_push32(cpu, r); sfera_sub_0042E480(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A59C9;
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFFFFEu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA59C9u); lift_push32(cpu, r); sfera_sub_004CD990(cpu,r); if (cpu->eip != r) return; }
    label_000A59C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A59C9u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x19Cu)) == (uint32_t)(0u)) goto label_000A59E0;
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    label_000A59E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A59E0u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A59E8u); lift_push32(cpu, r); sfera_sub_004D1AC0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A59F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A59F0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x98u); lift_push32(cpu, (uintptr_t)"SphereUI::FontPicker::getFont"); lift_push32(cpu, (uintptr_t)"%s():%d font = %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5A0Fu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5A15u); lift_push32(cpu, r); sfera_sub_0042E480(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A5A2C;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5A27u); lift_push32(cpu, r); sfera_sub_004CDA00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax += 2u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000A5A2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5A2Cu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x19Cu)) == (uint32_t)(0u)) goto label_000A5A43;
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->esi = lift_pop32(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->getFont(cpu);
    lift_return(cpu, 0u, stop_address); return;
    label_000A5A43: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5A43u);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004D1B00(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5A50u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5A58u); lift_push32(cpu, r); sfera_sub_004A58D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000A5A68;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5A65u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A5A68: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5A68u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5A70u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5A9Eu); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0u);
    std::construct_at(reinterpret_cast<SphereUI::FontPicker*>(cpu->esi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5AB8u); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    lift_store32(cpu->esi + 0x19Cu, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->edi + 0x198u)) == (uint32_t)(0u)) goto label_000A5B15;
    cpu->ecx = lift_load32(cpu->edi + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5AE6u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5AF4u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5AF9u); lift_push32(cpu, r); sfera_sub_004A5260(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    --cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5B08u); lift_push32(cpu, r); sfera_sub_004CD950(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA5B15u); lift_push32(cpu, r); sfera_sub_004CD9D0(cpu,r); if (cpu->eip != r) return; }
    label_000A5B15: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5B15u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x19Cu)) == (uint32_t)(0u)) goto label_000A5B55;
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5B2Bu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5B39u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->getFont(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5B46u);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    cpu->eax -= 2u;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA5B55u); lift_push32(cpu, r); sfera_sub_004CD990(cpu,r); if (cpu->eip != r) return; }
    label_000A5B55: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5B55u);
    cpu->eax = cpu->esi;
    lift_store8(cpu->esi + 0x4Bu, 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5B70u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0x7Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\FontPicker.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5BA3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1A0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5BADu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A5BD9;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5BC8u); lift_push32(cpu, r); sfera_sub_004A5A70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000A5BD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5BD9u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5BF0u);
    cpu->esp -= 0x90u;
    cpu->eax = lift_load32(cpu->esp + 0x94u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0xA0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    lift_store32(cpu->ecx, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->ebp, 0u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store8(cpu->esi, 0u);
    cpu->edx -= cpu->eax;
    label_000A5C32: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5C32u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A5C32;
    cpu->edi = native_function_address32(&::strtok);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)","); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5C4Eu), LIFT_CODE_TOKEN_RVA(0xA5C4Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5C4Eu);
    cpu->ebx = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000A5C71;
    lift_push32(cpu, 0x53u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5C68u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5C6Eu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000A5C71: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5C71u);
    cpu->edx = cpu->esi;
    cpu->eax = cpu->ebx;
    cpu->edx -= cpu->ebx;
    label_000A5C77: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5C77u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A5C77;
    lift_push32(cpu, (uintptr_t)","); lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5C8Au), LIFT_CODE_TOKEN_RVA(0xA5C88u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5C8Au);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000A5D6A;
    cpu->ebx = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"BOT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xA5CA5u), LIFT_CODE_TOKEN_RVA(0xA5CA3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5CA5u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A5CB5;
    lift_store32(cpu->ebp, 1u);
    goto label_000A5CCB;
    label_000A5CB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5CB5u);
    lift_push32(cpu, (uintptr_t)"MID"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xA5CBDu), LIFT_CODE_TOKEN_RVA(0xA5CBBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5CBDu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A5CCB;
    lift_store32(cpu->ebp, 2u);
    label_000A5CCB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5CCBu);
    lift_push32(cpu, (uintptr_t)","); lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5CD4u), LIFT_CODE_TOKEN_RVA(0xA5CD2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5CD4u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A5D6A;
    cpu->esi = native_function_address32(&::atoi);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xA5CE8u), LIFT_CODE_TOKEN_RVA(0xA5CE6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5CE8u);
    lift_push32(cpu, (uintptr_t)","); lift_push32(cpu, 0u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5CF5u), LIFT_CODE_TOKEN_RVA(0xA5CF3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5CF5u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A5D6A;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xA5CFFu), LIFT_CODE_TOKEN_RVA(0xA5CFDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5CFFu);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, (uintptr_t)","); lift_push32(cpu, 0u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5D0Eu), LIFT_CODE_TOKEN_RVA(0xA5D0Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5D0Eu);
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A5D2D;
    cpu->ecx = lift_load8(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = cpu->ebx & 0xFFu;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    lift_store32(cpu->eax, cpu->ecx);
    goto label_000A5D6A;
    label_000A5D2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5D2Du);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xA5D30u), LIFT_CODE_TOKEN_RVA(0xA5D2Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5D30u);
    lift_push32(cpu, (uintptr_t)","); lift_push32(cpu, 0u);
    cpu->ebx = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5D3Bu), LIFT_CODE_TOKEN_RVA(0xA5D39u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5D3Bu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A5D6A;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xA5D45u), LIFT_CODE_TOKEN_RVA(0xA5D43u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5D45u);
    cpu->ecx = lift_load8(cpu->esp + 0x18u);
    cpu->edx = lift_load8(cpu->esp + 0x1Cu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = cpu->ebx & 0xFFu;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->esp += 4u;
    cpu->eax |= cpu->ecx;
    lift_store32(cpu->edx, cpu->eax);
    label_000A5D6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5D6Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x90u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5D90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5D90u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000A5D9A;
    cpu->eax = 0x7FFFFFFFu;
    lift_return(cpu, 0u, stop_address); return;
    label_000A5D9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5D9Au);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"br"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5DA9u), LIFT_CODE_TOKEN_RVA(0xA5DA7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5DA9u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A5DB7;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000A5DB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5DB7u);
    lift_push32(cpu, (uintptr_t)"cl"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5DBFu), LIFT_CODE_TOKEN_RVA(0xA5DBDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5DBFu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A5DCD;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000A5DCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5DCDu);
    lift_push32(cpu, (uintptr_t)"l"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5DD5u), LIFT_CODE_TOKEN_RVA(0xA5DD3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5DD5u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A5DE3;
    cpu->eax = 3u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000A5DE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5DE3u);
    lift_push32(cpu, (uintptr_t)"\\l"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5DEBu), LIFT_CODE_TOKEN_RVA(0xA5DE9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5DEBu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A5E01;
    lift_push32(cpu, (uintptr_t)"/l"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5DFAu), LIFT_CODE_TOKEN_RVA(0xA5DF8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5DFAu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A5E08;
    label_000A5E01: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E01u);
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000A5E08: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E08u);
    lift_push32(cpu, (uintptr_t)"sp"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5E10u), LIFT_CODE_TOKEN_RVA(0xA5E0Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E10u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A5E1E;
    cpu->eax = 5u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000A5E1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E1Eu);
    lift_push32(cpu, (uintptr_t)"tab"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5E26u), LIFT_CODE_TOKEN_RVA(0xA5E24u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E26u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A5E34;
    cpu->eax = 8u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000A5E34: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E34u);
    lift_push32(cpu, (uintptr_t)"img"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5E3Cu), LIFT_CODE_TOKEN_RVA(0xA5E3Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E3Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A5E4A;
    cpu->eax = 9u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000A5E4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E4Au);
    lift_push32(cpu, (uintptr_t)"t"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5E52u), LIFT_CODE_TOKEN_RVA(0xA5E50u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E52u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A5E60;
    cpu->eax = 0xAu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000A5E60: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E60u);
    lift_push32(cpu, (uintptr_t)"\\t"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5E68u), LIFT_CODE_TOKEN_RVA(0xA5E66u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E68u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A5E76;
    cpu->eax = 0xBu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000A5E76: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E76u);
    lift_push32(cpu, (uintptr_t)"/t"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xA5E7Eu), LIFT_CODE_TOKEN_RVA(0xA5E7Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E7Eu);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0x7FFFFFF4u;
    cpu->eax += 0xBu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5E90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5E90u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A5EDC;
    cpu->edx = 0xF1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5EAEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000A5EB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5EB3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000A5EB3;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5EC3u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A5ED0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5ED0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000A5ED0;
    goto label_000A5EE2;
    label_000A5EDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5EDCu);
    lift_store32(cpu->esi, 0u);
    label_000A5EE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5EE2u);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000A5EFE;
    cpu->edx = 0xF7u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5EF5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5EFBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A5EFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5EFEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A5F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5F10u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000A613B;
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0x3Cu)) goto label_000A613B;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0]);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A5F35u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5F3Au);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    cpu->esp += 0xCu;
    cpu->edi = 0u;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x3Eu)) goto label_000A5F79;
    label_000A5F47: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5F47u);
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0]), cpu->eax & 0xFFu);
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0x80u)) goto label_000A5F6B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"Invalid hypertext command: %s");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5F62u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5F68u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000A5F6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5F6Bu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A5FF3;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x3Eu)) goto label_000A5F47;
    label_000A5F79: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5F79u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0];
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000A5F81: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5F81u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A5F81;
    lift_push32(cpu, 0x100u);
    cpu->eax -= cpu->edx;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_hypertext_scratch_runtime.attribute_name[0];
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0];
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A5F9Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5FA4u);
    cpu->esp += 0xCu;
    if ((uint8_t)(g_sfera_hypertext_scratch_runtime.command_text[0]) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A5FC2;
    (void)cpu;
    label_000A5FB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5FB0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x3Du)) goto label_000A5FC7;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_000A5FBD;
    lift_store8(cpu->edi, cpu->eax & 0xFFu);
    ++cpu->edi;
    label_000A5FBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5FBDu);
    ++cpu->esi;
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A5FB0;
    label_000A5FC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5FC2u);
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0x3Du)) goto label_000A5FDC;
    label_000A5FC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5FC7u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A5FDC;
    (void)cpu;
    label_000A5FD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5FD0u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x20u)) goto label_000A5FFB;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A5FD0;
    label_000A5FDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5FDCu);
    g_sfera_hypertext_scratch_runtime.command_text[0] = (uint8_t)((cpu->ebx & 0xFFu));
    label_000A5FE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5FE2u);
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_hypertext_scratch_runtime.attribute_name[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A5FECu); lift_push32(cpu, r); sfera_sub_004A5D90(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x7FFFFFFFu)) goto label_000A603C;
    label_000A5FF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5FF3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000A5FFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A5FFBu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A5FDC;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x22u)) goto label_000A6024;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0];
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A6020;
    label_000A6012: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6012u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x22u)) goto label_000A6020;
    ++cpu->esi;
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A6012;
    label_000A6020: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6020u);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    goto label_000A5FE2;
    label_000A6024: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6024u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0];
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A6030: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6030u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A6030;
    goto label_000A5FE2;
    label_000A603C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A603Cu);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax += 0xFFFFFFFEu;
    if ((uint32_t)(cpu->eax) > (uint32_t)(8u)) goto label_000A6131;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000A6055;
        case 1u: goto label_000A607C;
        case 2u: case 3u: case 4u: case 5u: case 6u: goto label_000A6131;
        case 7u: goto label_000A60B8;
        case 8u: goto label_000A609A;
        default: lift_trap(cpu, 0x4A604Eu, "resolved jump-table index out of range"); return;
    }
label_000A6055: ;
    cpu->esi += 4u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%x"); lift_push32(cpu, (uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0]);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4A6063u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6069u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    lift_store32(cpu->esi, (uint64_t)(lift_load32(cpu->esi)) | (uint64_t)(0xFF000000u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000A607C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A607Cu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0];
    cpu->esi += 8u;
    cpu->esi -= cpu->eax;
    label_000A6086: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6086u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->esi + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A6086;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000A609A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A609Au);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0];
    cpu->esi += 8u;
    cpu->esi -= cpu->eax;
    label_000A60A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A60A4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->esi + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000A60A4;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000A60B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A60B8u);
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0]);
    cpu->ecx = (uint32_t)(cpu->esi + 0x90u);
    cpu->edx = (uint32_t)(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A60D0u); lift_push32(cpu, r); sfera_sub_004A5BF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A60D8u); lift_push32(cpu, r); sfera_sub_004B8250(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x98u, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A6130;
    cpu->ebx = lift_load32(cpu->esi + 0x90u);
    cpu->ebp = cpu->ebx;
    cpu->ebp = lift_shift_right(cpu, cpu->ebp, (uint32_t)(0x18u), 32u);
    { uint64_t l=(uint64_t)((cpu->ebp & 0xFFFFu)), r=(uint64_t)(lift_load16(cpu->eax + 8u)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,16u); cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)((v)) & 0xFFFFu); }
    cpu->ecx = cpu->ebx;
    cpu->edx = cpu->ebx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->ebx = cpu->ebx & 0xFFu;
    cpu->ebx = (cpu->ebx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(lift_load16(cpu->eax + 4u)) + (uint64_t)(0u))) & 0xFFFFu);
    cpu->edx &= 0xFFu;
    { uint64_t l=(uint64_t)((cpu->ebp & 0xFFFFu)), r=(uint64_t)((cpu->edx & 0xFFFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,16u); cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)((v)) & 0xFFFFu); }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x10u), 32u);
    cpu->ecx &= 0xFFu;
    cpu->ebp = cpu->ebp & 0xFFFFu;
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFFFu)), r=(uint64_t)((cpu->ecx & 0xFFFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,16u); cpu->ebx = (cpu->ebx & 0xFFFF0000u) | ((uint32_t)((v)) & 0xFFFFu); }
    cpu->eax = cpu->ebx & 0xFFFFu;
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(0x10u), 32u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(0x10u), 32u);
    cpu->edx |= cpu->ecx;
    lift_store32(cpu->esi + 0x90u, cpu->ebp);
    lift_store32(cpu->esi + 0x94u, cpu->edx);
    label_000A6130: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6130u);
    cpu->ebp = lift_pop32(cpu);
    label_000A6131: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6131u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000A613B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A613Bu);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A6220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6220u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = 0u;
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000A6254;
    cpu->eax = lift_load32(cpu->ecx + 0x58u);
    cpu->edx = (uint32_t)(cpu->ebx + 0xFFFFFFFEu);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    ++cpu->edx;
    cpu->ebp = (uint32_t)(cpu->edx + cpu->edx);
    label_000A6245: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6245u);
    cpu->esi += lift_load32(cpu->eax);
    cpu->edi += lift_load32(cpu->eax + 4u);
    cpu->eax += 8u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A6245;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_000A6254: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6254u);
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->ebx)) goto label_000A625E;
    cpu->eax = lift_load32(cpu->ecx + 0x58u);
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebp) * 4u));
    label_000A625E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A625Eu);
    cpu->eax = (uint32_t)(cpu->edi + cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax += cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A6270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6270u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A62C6;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0xDD67C8u)) goto label_000A6298;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x128u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6291u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A62C6;
    label_000A6298: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6298u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA62C6u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000A62C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A62C6u);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A62D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A62D0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000A62FC;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A62E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A62E0u);
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    cpu->ebx += 0x128u;
    cpu->ecx = 0x4Au;
    cpu->eax += 0x128u;
    lift_movs32(cpu, 1u);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->edx)) goto label_000A62E0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000A62FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A62FCu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A6300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6300u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_000A631D;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000A631D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A631Du);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0xDD67C8u)) goto label_000A6330;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xA6330u);
    label_000A6330: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6330u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6339u); lift_push32(cpu, r); sfera_sub_004A6270(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x128u);
    cpu->edi += cpu->eax;
    lift_store32(cpu->esi + 8u, cpu->edi);
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A6350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6350u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0xA4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A635Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A638D;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->eax + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A6386;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = 0x27u;
    lift_movs32(cpu, 1u);
    cpu->esi = lift_pop32(cpu);
    label_000A6386: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6386u);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_000A638D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A638Du);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A63BBu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4A63BBu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A63C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A63C0u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi))) goto label_000A63F0;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A63E6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) - 1u);
    label_000A63F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A63F0u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A6400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6400u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000A6431;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A6410: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6410u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A641F;
    cpu->ecx = 0x4Au;
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    lift_movs32(cpu, 1u);
    label_000A641F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A641Fu);
    cpu->ebx += 0x128u;
    cpu->eax += 0x128u;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->edx)) goto label_000A6410;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000A6431: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6431u);
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A6440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6440u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000A6471;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A6450: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6450u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A645F;
    cpu->ecx = 0x4Au;
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    lift_movs32(cpu, 1u);
    label_000A645F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A645Fu);
    cpu->ebx += 0x128u;
    cpu->eax += 0x128u;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->edx)) goto label_000A6450;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000A6471: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6471u);
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A6480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6480u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0x24u))) goto label_000A6526;
    cpu->edx = 0x170u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A64BEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x64u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A64DAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 4u) + 0x190u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A64EAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A64EFu);
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4A64FCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6501u);
    cpu->esp += 0x1Cu;
    cpu->edx = 0x173u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6513u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A651Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x24u, (uint64_t)(lift_load32(cpu->esi + 0x24u)) + (uint64_t)(0x64u) + (uint64_t)(0u));
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    label_000A6526: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6526u);
    cpu->edx = 0x178u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6535u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A653Cu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->esp + 0x28u, 0u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000A65A4;
    lift_push32(cpu, 0xA4u);
    lift_store32(cpu->edi + 4u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6562u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A6576;
    lift_store32(cpu->edi, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = cpu->edi;
    goto label_000A65A6;
    label_000A6576: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6576u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA65A4u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000A65A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A65A4u);
    cpu->eax = 0u;
    label_000A65A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A65A6u);
    cpu->ecx = lift_load32(cpu->esi + 0x20u);
    cpu->edx = lift_load32(cpu->esi + 0x1Cu);
    lift_store32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u), cpu->eax);
    lift_store32(cpu->esi + 0x20u, (uint64_t)(lift_load32(cpu->esi + 0x20u)) + 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A65D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A65D0u);
    cpu->esp -= 0x54u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A65F1;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x2Cu)), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000A65F1;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA65F1u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000A65F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A65F1u);
    cpu->edi = lift_load32(cpu->esp + 0x68u);
    cpu->eax = lift_load32(cpu->esp + 0x6Cu);
    cpu->ebx = lift_shift_left(cpu, cpu->ebx, (uint32_t)(0x18u), 32u);
    cpu->ecx = 0u;
    cpu->edx = (uint32_t)(cpu->edi + cpu->eax);
    cpu->edi += lift_load32(cpu->esp + 0x70u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    cpu->ebx |= 0xFFFFFFu;
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x68u, 0u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store8(cpu->esp + 0x6Cu, cpu->ecx & 0xFFu);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_store32(cpu->esp + 0x3Cu, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) <= (uint32_t)(cpu->ecx)) goto label_000A6A6F;
    lift_push32(cpu, cpu->ebp);
    label_000A6642: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6642u);
    cpu->eax = lift_load32(cpu->esi + 0x58u);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edi = lift_load32(cpu->esp + 0x68u);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ebp = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebp);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->eax)) goto label_000A6922;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000A6670: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6670u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->eax += 0xFFFFFFFEu;
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_000A68D7;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000A6690;
        case 1u: goto label_000A677B;
        case 2u: goto label_000A684A;
        case 3u: goto label_000A68D7;
        case 4u: goto label_000A6686;
        case 5u: case 6u: goto label_000A66E9;
        case 7u: goto label_000A66F1;
        case 8u: goto label_000A674E;
        case 9u: goto label_000A67E3;
        default: lift_trap(cpu, 0x4A667Fu, "resolved jump-table index out of range"); return;
    }
label_000A6686: ;
    cpu->ecx = lift_load32(cpu->ebp + 0x98u);
    lift_store32(cpu->esp + 0x74u, cpu->ecx);
    label_000A6690: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6690u);
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ebx &= 0xFFFFFFu;
    cpu->ebx |= cpu->eax;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x6Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A68D7;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x128u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0x30u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->ebx + 0x125u)) == (uint8_t)(0u)) goto label_000A66D9;
    cpu->ebx = lift_load32(cpu->esi + 0x54u);
    cpu->ebx &= 0xFFFFFFu;
    cpu->ebx |= cpu->eax;
    goto label_000A68D3;
    label_000A66D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A66D9u);
    cpu->ebx = lift_load32(cpu->esi + 0x50u);
    cpu->ebx &= 0xFFFFFFu;
    cpu->ebx |= cpu->eax;
    goto label_000A68D3;
    label_000A66E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A66E9u);
    cpu->edi += lift_load32(cpu->ebp + 0xCu);
    goto label_000A68D7;
    label_000A66F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A66F1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xA0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000A6740;
    cpu->eax = lift_load16(cpu->ebp + 0x9Cu);
    cpu->eax += cpu->edi;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    cpu->eax = lift_load16(cpu->ebp + 0x9Eu);
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    cpu->esp -= 8u;
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A673Cu); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_000A6740: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6740u);
    cpu->ecx = lift_load16(cpu->ebp + 0x98u);
    cpu->edi += cpu->ecx;
    goto label_000A68D7;
    label_000A674E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A674Eu);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 0x40u);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x128u);
    lift_store32(cpu->eax + cpu->ecx + 0x120u, 0u);
    lift_store32(cpu->esp + 0x54u, cpu->edi);
    lift_store32(cpu->esp + 0x58u, cpu->edx);
    lift_store8(cpu->esp + 0x70u, 1u);
    goto label_000A68D7;
    label_000A677B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A677Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x128u);
    lift_store32(cpu->ecx + cpu->eax + 0x120u, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0x74u);
    cpu->ecx += cpu->edx;
    lift_store32(cpu->esp + 0x48u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + cpu->eax + 0x125u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x44u, cpu->edi);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000A67CC;
    cpu->ebx = lift_load32(cpu->esi + 0x54u);
    cpu->ebx &= 0xFFFFFFu;
    cpu->ebx |= lift_load32(cpu->esp + 0x28u);
    lift_store8(cpu->esp + 0x6Cu, 1u);
    goto label_000A68D3;
    label_000A67CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A67CCu);
    cpu->ebx = lift_load32(cpu->esi + 0x50u);
    cpu->ebx &= 0xFFFFFFu;
    cpu->ebx |= lift_load32(cpu->esp + 0x28u);
    lift_store8(cpu->esp + 0x6Cu, 1u);
    goto label_000A68D3;
    label_000A67E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A67E3u);
    cpu->edx = lift_load32(cpu->esi + 0x58u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->eax += lift_load32(cpu->esp + 0x58u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->ebx = lift_load32(cpu->esp + 0x54u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x128u);
    lift_store32(cpu->esp + 0x60u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    lift_store8(cpu->eax + cpu->ecx + 0x124u, 1u);
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->eax = lift_load32(cpu->edx + cpu->ecx + 0x120u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(8u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax += cpu->edx;
    cpu->eax += cpu->ecx;
    lift_store32(cpu->eax, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x58u);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x60u);
    lift_store32(cpu->eax + 8u, cpu->edi);
    lift_store32(cpu->eax + 0xCu, cpu->ebx);
    lift_store32(cpu->edx + cpu->ecx + 0x120u, (uint64_t)(lift_load32(cpu->edx + cpu->ecx + 0x120u)) + 1u);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store8(cpu->esp + 0x70u, 0u);
    goto label_000A68D7;
    label_000A684A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A684Au);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x128u);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->ebp += lift_load32(cpu->esp + 0x48u);
    lift_store8(cpu->edx + cpu->ecx + 0x124u, 1u);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->ebp += lift_load32(cpu->esp + 0x74u);
    cpu->edx = 2u;
    lift_store32(cpu->esp + 0x4Cu, cpu->edi);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_000A6890;
    lift_store32(cpu->esp + 0x48u, (uint64_t)(lift_load32(cpu->esp + 0x48u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A6886;
    cpu->ebp += cpu->edx;
    goto label_000A6889;
    label_000A6886: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6886u);
    cpu->ebp += 3u;
    label_000A6889: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6889u);
    cpu->eax = (uint32_t)(cpu->edi + 2u);
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    label_000A6890: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6890u);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->eax = lift_load32(cpu->edx + cpu->ecx + 0x120u);
    cpu->ebx = lift_load32(cpu->esp + 0x44u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(8u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax += cpu->edx;
    cpu->eax += cpu->ecx;
    lift_store32(cpu->eax, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->eax + 8u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->eax + 0xCu, cpu->ebp);
    lift_store32(cpu->edx + cpu->ecx + 0x120u, (uint64_t)(lift_load32(cpu->edx + cpu->ecx + 0x120u)) + 1u);
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store8(cpu->esp + 0x6Cu, 0u);
    label_000A68D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A68D3u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    label_000A68D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A68D7u);
    cpu->eax = lift_load32(cpu->ebp + 0x90u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A690B;
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0u)) goto label_000A690B;
    lift_x87_push(cpu, 0.0);
    cpu->edx += lift_load32(cpu->esp + 0x74u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6901u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi += lift_load32(cpu->ebp + 0x94u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_000A690B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A690Bu);
    cpu->ebp = lift_load32(cpu->ebp);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(lift_load32(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000A6670;
    label_000A6922: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6922u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x6Cu)) == (uint8_t)(0u)) goto label_000A69D4;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u))) goto label_000A69BB;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x128u);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->ebp += lift_load32(cpu->esp + 0x48u);
    lift_store8(cpu->edx + cpu->ecx + 0x124u, 1u);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->ebp += lift_load32(cpu->esp + 0x74u);
    cpu->edx = 2u;
    lift_store32(cpu->esp + 0x4Cu, cpu->edi);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_000A697D;
    lift_store32(cpu->esp + 0x48u, (uint64_t)(lift_load32(cpu->esp + 0x48u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_000A6973;
    cpu->ebp += cpu->edx;
    goto label_000A6976;
    label_000A6973: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6973u);
    cpu->ebp += 3u;
    label_000A6976: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6976u);
    cpu->eax = (uint32_t)(cpu->edi + 2u);
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    label_000A697D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A697Du);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->eax = lift_load32(cpu->edx + cpu->ecx + 0x120u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(8u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    cpu->eax += cpu->ecx;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax + 0xCu, cpu->ebp);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + cpu->ecx + 0x120u, (uint64_t)(lift_load32(cpu->eax + cpu->ecx + 0x120u)) + 1u);
    label_000A69BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A69BBu);
    cpu->eax = lift_load32(cpu->esp + 0x68u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->eax += lift_load32(cpu->esp + 0x74u);
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    label_000A69D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A69D4u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x70u)) == (uint8_t)(0u)) goto label_000A6A52;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x54u))) goto label_000A6A3A;
    cpu->edx = lift_load32(cpu->esi + 0x58u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->eax += lift_load32(cpu->esp + 0x58u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x128u);
    lift_store32(cpu->esp + 0x60u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    lift_store8(cpu->eax + cpu->ecx + 0x124u, 1u);
    cpu->ebp = lift_load32(cpu->esi + 0x40u);
    cpu->eax = lift_load32(cpu->ecx + cpu->ebp + 0x120u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(8u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax += cpu->ebp;
    cpu->eax += cpu->ecx;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    lift_store32(cpu->eax + 8u, cpu->edi);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    lift_store32(cpu->ecx + cpu->ebp + 0x120u, (uint64_t)(lift_load32(cpu->ecx + cpu->ebp + 0x120u)) + 1u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_000A6A3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6A3Au);
    cpu->eax = lift_load32(cpu->esp + 0x68u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x54u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x58u);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x58u, cpu->eax);
    label_000A6A52: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6A52u);
    cpu->edx += lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) > (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x40u))) goto label_000A6A6E;
    ++cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->esi + 0x20u))) goto label_000A6642;
    label_000A6A6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6A6Eu);
    cpu->ebp = lift_pop32(cpu);
    label_000A6A6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6A6Fu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x74u)) != (uint32_t)(0xFFu)) goto label_000A6A89;
    if ((uint32_t)(lift_load32(cpu->esi + 0x2Cu)) >= (uint32_t)(2u)) goto label_000A6A89;
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA6A89u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000A6A89: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6A89u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A6AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6AC0u);
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
    cpu->edi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edi);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000A6B00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6B00u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0x10u))) goto label_000A6B76;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->eax += 8u;
    cpu->esi = (uint32_t)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6B1Au); lift_push32(cpu, r); sfera_sub_004A6350(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000A6B34;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xA6B34u);
    label_000A6B34: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6B34u);
    ++cpu->ecx;
    lift_store32(cpu->edi + 4u, cpu->ecx);
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->ebp + 0xCu, cpu->eax);
    goto label_000A6B00;
    label_000A6B76: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6B76u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A6B49(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6B49u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFECu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->ebp + 0xCu))) goto label_000A6B6D;
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    label_000A6B54: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6B54u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6B66u); lift_push32(cpu, r); sfera_sub_004A63C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->ebp + 0xCu))) goto label_000A6B54;
    label_000A6B6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6B6Du);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6B76u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A6B90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6B90u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6BA7u); lift_push32(cpu, r); sfera_sub_004A6350(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000A6BC1;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xA6BC1u);
    label_000A6BC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6BC1u);
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A6BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6BE0u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6BFBu); lift_push32(cpu, r); sfera_sub_004A6400(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004A6C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6C00u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) <= (uint32_t)(cpu->edi)) goto label_000A6C6A;
    lift_push32(cpu, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000A6C10: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6C10u);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))) == (uint32_t)(0u)) goto label_000A6C59;
    cpu->edx = 0x25Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6C28u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000A6C4F;
    cpu->edx = lift_load32(cpu->eax + 0xFFFFFFFCu);
    cpu->ebx = (uint32_t)(cpu->eax + 0xFFFFFFFCu);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00416610)); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xCu); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6C46u); lift_push32(cpu, r); sfera_sub_004EEB86(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4A6C4Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000A6C4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6C4Fu);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 4u), 0u);
    label_000A6C59: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6C59u);
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x20u))) goto label_000A6C10;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x20u, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000A6C6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4A6C6Au);
    lift_store32(cpu->esi + 0x20u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}
