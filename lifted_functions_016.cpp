#include "lifted_functions.h"
#include <cmath>
namespace lifted {

static uint32_t sfera_zoning_config_error_context() { return (uintptr_t)"Wrong format of \"Landscape\\zoning.cfg\""; }
__declspec(noinline) void sfera_sub_0049DF00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x15Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x16Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DF2Au)); sfera_sub_004815D0(cpu, LIFT_CODE_TOKEN_VA(0x49DF2Au));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DF31u)); sfera_sub_00482170(cpu, LIFT_CODE_TOKEN_VA(0x49DF31u));
    cpu->esi = cpu->eax;
    cpu->edx = (uintptr_t)"zonesParams";
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DF43u)); sfera_sub_004811B0(cpu, LIFT_CODE_TOKEN_VA(0x49DF43u));
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)cpu->eax <= 0) goto label_0009E45D;
    label_0009DF51:
    lift_push32(cpu, 0x148u);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x49DF5Du));
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uintptr_t)"zonesParams";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DF72u)); sfera_sub_00481300(cpu, LIFT_CODE_TOKEN_VA(0x49DF72u));
    cpu->edi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if (cpu->edi != 0u) goto label_0009DF8F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : zoneParamsCfg is NULL");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DF8Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49DF8Cu));
    cpu->esp += 0xCu;
    label_0009DF8F:
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"xPatchMin";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DFA0u)); sfera_sub_00481150(cpu, LIFT_CODE_TOKEN_VA(0x49DFA0u));
    if (cpu->eax != 0u) goto label_0009DFB7;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"xPatchMin\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DFB4u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49DFB4u));
    cpu->esp += 0xCu;
    label_0009DFB7:
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)"zPatchMin";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DFC8u)); sfera_sub_00481150(cpu, LIFT_CODE_TOKEN_VA(0x49DFC8u));
    if (cpu->eax != 0u) goto label_0009DFDF;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"zPatchMin\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DFDCu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49DFDCu));
    cpu->esp += 0xCu;
    label_0009DFDF:
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uintptr_t)"xMin";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DFF0u)); sfera_sub_00481150(cpu, LIFT_CODE_TOKEN_VA(0x49DFF0u));
    if (cpu->eax != 0u) goto label_0009E007;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"xMin\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E004u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E004u));
    cpu->esp += 0xCu;
    label_0009E007:
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"xMax";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E018u)); sfera_sub_00481150(cpu, LIFT_CODE_TOKEN_VA(0x49E018u));
    if (cpu->eax != 0u) goto label_0009E02F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"xMax\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E02Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E02Cu));
    cpu->esp += 0xCu;
    label_0009E02F:
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)"zMin";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E040u)); sfera_sub_00481150(cpu, LIFT_CODE_TOKEN_VA(0x49E040u));
    if (cpu->eax != 0u) goto label_0009E057;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"zMin\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E054u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E054u));
    cpu->esp += 0xCu;
    label_0009E057:
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uintptr_t)"zMax";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E068u)); sfera_sub_00481150(cpu, LIFT_CODE_TOKEN_VA(0x49E068u));
    if (cpu->eax != 0u) goto label_0009E07F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"zMax\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E07Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E07Cu));
    cpu->esp += 0xCu;
    label_0009E07F:
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"borderFadeDist";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E090u)); sfera_sub_00481150(cpu, LIFT_CODE_TOKEN_VA(0x49E090u));
    if (cpu->eax != 0u) goto label_0009E0A7;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"borderFadeDist\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E0A4u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E0A4u));
    cpu->esp += 0xCu;
    label_0009E0A7:
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)"skyFogAlpha";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E0B8u)); sfera_sub_00481150(cpu, LIFT_CODE_TOKEN_VA(0x49E0B8u));
    if (cpu->eax != 0u) goto label_0009E0CF;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"skyFogAlpha\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E0CCu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E0CCu));
    cpu->esp += 0xCu;
    label_0009E0CF:
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uintptr_t)"fogNear";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E0E0u)); sfera_sub_00481150(cpu, LIFT_CODE_TOKEN_VA(0x49E0E0u));
    if (cpu->eax != 0u) goto label_0009E0F7;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogNear\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E0F4u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E0F4u));
    cpu->esp += 0xCu;
    label_0009E0F7:
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"fogFar";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E108u)); sfera_sub_00481150(cpu, LIFT_CODE_TOKEN_VA(0x49E108u));
    if (cpu->eax != 0u) goto label_0009E11F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogFar\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E11Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E11Cu));
    cpu->esp += 0xCu;
    label_0009E11F:
    cpu->edx = (uintptr_t)"dayColors";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E12Bu)); sfera_sub_004811B0(cpu, LIFT_CODE_TOKEN_VA(0x49E12Bu));
    if (cpu->eax == 8u) goto label_0009E143;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : wrong size of \"dayColors\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E140u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E140u));
    cpu->esp += 0xCu;
    label_0009E143:
    cpu->esi = 0u;
    cpu->ebx = cpu->esp + 0x4Cu;
    goto label_0009E154;
    label_0009E150:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    label_0009E154:
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uintptr_t)"dayColors";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E161u)); sfera_sub_00481300(cpu, LIFT_CODE_TOKEN_VA(0x49E161u));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_0009E17A;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : dayColorCfg is NULL");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E177u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E177u));
    cpu->esp += 0xCu;
    label_0009E17A:
    cpu->edx = cpu->ebx + 0xFFFFFFFCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->edx = (uintptr_t)"fogColor";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E18Cu)); sfera_sub_00481250(cpu, LIFT_CODE_TOKEN_VA(0x49E18Cu));
    if (cpu->eax != 0u) goto label_0009E1A4;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogColor[%d].r\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E1A1u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E1A1u));
    cpu->esp += 0x10u;
    label_0009E1A4:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    cpu->edx = (uintptr_t)"fogColor";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E1B3u)); sfera_sub_00481250(cpu, LIFT_CODE_TOKEN_VA(0x49E1B3u));
    if (cpu->eax != 0u) goto label_0009E1CB;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogColor[%d].g\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E1C8u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E1C8u));
    cpu->esp += 0x10u;
    label_0009E1CB:
    cpu->eax = cpu->ebx + 4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 2u);
    cpu->edx = (uintptr_t)"fogColor";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E1DDu)); sfera_sub_00481250(cpu, LIFT_CODE_TOKEN_VA(0x49E1DDu));
    if (cpu->eax != 0u) goto label_0009E1F5;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogColor[%d].b\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E1F2u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E1F2u));
    cpu->esp += 0x10u;
    label_0009E1F5:
    cpu->ecx = cpu->ebx + 0x5Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->edx = (uintptr_t)"ambientColor";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E207u)); sfera_sub_00481250(cpu, LIFT_CODE_TOKEN_VA(0x49E207u));
    if (cpu->eax != 0u) goto label_0009E21F;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"ambientColor[%d].r\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E21Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E21Cu));
    cpu->esp += 0x10u;
    label_0009E21F:
    cpu->edx = cpu->ebx + 0x60u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->edx = (uintptr_t)"ambientColor";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E231u)); sfera_sub_00481250(cpu, LIFT_CODE_TOKEN_VA(0x49E231u));
    if (cpu->eax != 0u) goto label_0009E249;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"ambientColor[%d].g\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E246u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E246u));
    cpu->esp += 0x10u;
    label_0009E249:
    cpu->eax = cpu->ebx + 0x64u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 2u);
    cpu->edx = (uintptr_t)"ambientColor";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E25Bu)); sfera_sub_00481250(cpu, LIFT_CODE_TOKEN_VA(0x49E25Bu));
    if (cpu->eax != 0u) goto label_0009E273;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"ambientColor[%d].b\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E270u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E270u));
    cpu->esp += 0x10u;
    label_0009E273:
    cpu->ecx = cpu->ebx + 0xBCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->edx = (uintptr_t)"sunColor";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E288u)); sfera_sub_00481250(cpu, LIFT_CODE_TOKEN_VA(0x49E288u));
    if (cpu->eax != 0u) goto label_0009E2A0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"sunColor[%d].r\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E29Du)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E29Du));
    cpu->esp += 0x10u;
    label_0009E2A0:
    cpu->edx = cpu->ebx + 0xC0u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->edx = (uintptr_t)"sunColor";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E2B5u)); sfera_sub_00481250(cpu, LIFT_CODE_TOKEN_VA(0x49E2B5u));
    if (cpu->eax != 0u) goto label_0009E2CD;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"sunColor[%d].g\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E2CAu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E2CAu));
    cpu->esp += 0x10u;
    label_0009E2CD:
    cpu->eax = cpu->ebx + 0xC4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 2u);
    cpu->edx = (uintptr_t)"sunColor";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E2E2u)); sfera_sub_00481250(cpu, LIFT_CODE_TOKEN_VA(0x49E2E2u));
    if (cpu->eax != 0u) goto label_0009E2FA;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"sunColor[%d].b\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E2F7u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E2F7u));
    cpu->esp += 0x10u;
    label_0009E2FA:
    ++cpu->esi;
    cpu->ebx += 0xCu;
    if ((int32_t)cpu->esi < (int32_t)8u) goto label_0009E150;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = cpu->esp + 0x20u;
    if (cpu->edx >= cpu->ecx) goto label_0009E3C6;
    cpu->ebx = *(uint32_t*)(cpu->edi);
    cpu->eax = cpu->edx;
    if (cpu->ebx > cpu->eax) goto label_0009E3C6;
    cpu->edi = *(uint32_t*)(cpu->edi + 8u);
    cpu->edx -= cpu->ebx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x63E7063Fu * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    if (cpu->ecx != cpu->edi) goto label_0009E3A0;
    cpu->ecx -= cpu->ebx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x63E7063Fu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    if (cpu->ecx > 0xC7CE0Bu) goto label_0009E47F;
    cpu->edi -= cpu->ebx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x63E7063Fu * (int32_t)(cpu->edi))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    ++cpu->ecx;
    cpu->eax += cpu->edx;
    if (cpu->ecx <= cpu->eax) goto label_0009E3A0;
    cpu->edx = cpu->eax;
    cpu->edx >>= 1u;
    cpu->edi = 0xC7CE0Cu;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_0009E38A;
    cpu->eax = 0u;
    goto label_0009E38C;
    label_0009E38A:
    cpu->eax += cpu->edx;
    label_0009E38C:
    if (cpu->eax >= cpu->ecx) goto label_0009E392;
    cpu->eax = cpu->ecx;
    label_0009E392:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E39Eu)); sfera_sub_0049DCD0(cpu, LIFT_CODE_TOKEN_VA(0x49E39Eu));
    goto label_0009E3A4;
    label_0009E3A0:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0009E3A4:
    cpu->edi = *(uint32_t*)(cpu->ebx + 4u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x148u);
    cpu->esi += *(uint32_t*)(cpu->ebx);
    if (cpu->edi == 0u) goto label_0009E3BA;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),328u); cpu->esi += 328u; cpu->edi += 328u; cpu->ecx = 0u;
    label_0009E3BA:
    *(uint32_t*)(cpu->ebx + 4u) = (uint64_t)(*(uint32_t*)(cpu->ebx + 4u)) + (uint64_t)(0x148u) + (uint64_t)(0u);
    goto label_0009E44E;
    label_0009E3C6:
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    if (cpu->ecx != cpu->esi) goto label_0009E42F;
    cpu->edi = *(uint32_t*)(cpu->edi);
    cpu->ecx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x63E7063Fu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    if (cpu->ecx > 0xC7CE0Bu) goto label_0009E47F;
    cpu->esi -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x63E7063Fu * (int32_t)(cpu->esi))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    ++cpu->ecx;
    cpu->eax += cpu->edx;
    if (cpu->ecx <= cpu->eax) goto label_0009E42B;
    cpu->edx = cpu->eax;
    cpu->edx >>= 1u;
    cpu->esi = 0xC7CE0Cu;
    cpu->esi -= cpu->edx;
    if (cpu->esi >= cpu->eax) goto label_0009E419;
    cpu->eax = 0u;
    goto label_0009E41B;
    label_0009E419:
    cpu->eax += cpu->edx;
    label_0009E41B:
    if (cpu->eax >= cpu->ecx) goto label_0009E421;
    cpu->eax = cpu->ecx;
    label_0009E421:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9E42Bu)); sfera_sub_0049DCD0(cpu, LIFT_CODE_TOKEN_RVA(0x9E42Bu));
    label_0009E42B:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0009E42F:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->eax == 0u) goto label_0009E447;
    std::memmove((void*)(cpu->eax),(void*)(cpu->esp + 0x20u),328u); cpu->ecx = 0u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0009E447:
    *(uint32_t*)(cpu->edi + 4u) = (uint64_t)(*(uint32_t*)(cpu->edi + 4u)) + (uint64_t)(0x148u) + (uint64_t)(0u);
    label_0009E44E:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0009DF51;
    label_0009E45D:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E464u)); sfera_sub_004815C0(cpu, LIFT_CODE_TOKEN_VA(0x49E464u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x15Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009E47F:
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x49E47Fu), "std::length_error");
    lift_trap(cpu, 0x49E48Au, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0049E490(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->edi >= cpu->eax) goto label_0009E4D7;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx > cpu->edi) goto label_0009E4D7;
    cpu->edi -= cpu->ecx;
    cpu->edi = (int32_t)(cpu->edi) >> 3u;
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_0009E4B8;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9E4B8u)); sfera_sub_0049DEA0(cpu, LIFT_CODE_TOKEN_RVA(0x9E4B8u));
    label_0009E4B8:
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = cpu->eax + (cpu->edi * 8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_0009E4F6;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(float*)(cpu->eax + 4u) = (double)*(float*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(8u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009E4D7:
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_0009E4E5;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9E4E5u)); sfera_sub_0049DEA0(cpu, LIFT_CODE_TOKEN_RVA(0x9E4E5u));
    label_0009E4E5:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_0009E4F6;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(float*)(cpu->eax + 4u) = (double)*(float*)(cpu->edi + 4u);
    label_0009E4F6:
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(8u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049E500(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3;
 double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x7Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xB4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xB0u);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x63E7063Fu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    if ((cpu->ecx += cpu->edx) != 0u) goto label_0009E56E;
    lift_push32(cpu, (uintptr_t)"Error in ZoningMgr::calc_params() : zonesParams is Empty");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E56Bu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E56Bu));
    cpu->esp += 4u;
label_0009E56E:
    x87_p0 = (double)*(float*)(cpu->esp + 0xACu);
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E58Fu)); sfera_sub_0049D780(cpu, LIFT_CODE_TOKEN_VA(0x49E58Fu));
    x87_p0 = (double)*(float*)(cpu->esp + 0xACu);
    cpu->edx = cpu->esp + 0x74u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x84u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E5AEu)); sfera_sub_00495490(cpu, LIFT_CODE_TOKEN_VA(0x49E5AEu));
    cpu->ecx = cpu->esp + 0x74u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x84u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E5C2u)); sfera_sub_0049DA20(cpu, LIFT_CODE_TOKEN_VA(0x49E5C2u));
    if (*(uint8_t*)(cpu->esp + 0xA0u) != 0u) goto label_0009E6B4;
    cpu->ecx = 0u;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x63E7063Fu * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->ebx = 0u;
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x98u) = cpu->ecx;
    if (cpu->eax == 0u) goto label_0009E69C;
label_0009E607:
    x87_p0 = (double)*(float*)(cpu->esp + 0xA8u);
    cpu->edi += cpu->ebp;
    lift_push32(cpu, cpu->edi);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_p0; 
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0xB0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E629u)); value_3 = sfera_sub_0049D910(cpu, LIFT_CODE_TOKEN_VA(0x49E629u));
    *(float*)(cpu->esp + 0x20u) = value_3; 
    value_1 = (double)0.009999999776482582f;
    x87_p0 = (double)*(float*)(cpu->esp + 0x20u);
     value_2 = x87_p0; if ((value_2)<(value_1)) goto label_0009E66B;
    cpu->ecx = cpu->esp + 0x14u;
    *(float*)(cpu->esp + 0x18u) = value_2; 
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x28u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E658u)); sfera_sub_0049E490(cpu, LIFT_CODE_TOKEN_VA(0x49E658u));
     if (((double)*(float*)(cpu->esp + 0x20u))>(0.9900000095367432)) goto label_0009E694;
    goto label_0009E66D;
label_0009E66B:
label_0009E66D:
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x63E7063Fu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    ++cpu->ebx;
    cpu->eax += cpu->edx;
    cpu->ebp += 0x148u;
    if (cpu->ebx < cpu->eax) goto label_0009E607;
label_0009E694:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
label_0009E69C:
    cpu->ecx -= cpu->ebp;
    cpu->edi = cpu->ecx;
    cpu->edi = (int32_t)(cpu->edi) >> 3u;
    if (cpu->edi != 0u) goto label_0009E6FD;
    if (cpu->ebp == 0u) goto label_0009E6B4;
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E6B1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49E6B1u));
    cpu->esp += 4u;
label_0009E6B4:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x40u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, cpu->edx);
    cpu->ecx -= cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x63E7063Fu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x148u);
    cpu->edx = cpu->ecx + cpu->edi + 0xFFFFFEB8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E6F8u)); sfera_sub_0049D820(cpu, LIFT_CODE_TOKEN_VA(0x49E6F8u));
    goto label_0009EC4A;
label_0009E6FD:
    if (cpu->edi != 1u) goto label_0009E731;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x40u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x148u);
    cpu->eax += *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E72Cu)); sfera_sub_0049D820(cpu, LIFT_CODE_TOKEN_VA(0x49E72Cu));
    goto label_0009EC41;
label_0009E731:
    cpu->ebx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->ebp + (cpu->edi * 8u) + 0xFFFFFFF4u);
    cpu->esi = *(uint32_t*)(cpu->ebp + (cpu->edi * 8u) + 0xFFFFFFF0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + (cpu->edi * 8u) + 0xFFFFFFF8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x148u);
    x87_p0 = (double)*(float*)(cpu->esi + cpu->ebx + 0x1Cu);
    cpu->esi += cpu->ebx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x148u);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->ecx + cpu->ebx + 0x1Cu)));
    x87_p1 = (double)*(float*)(cpu->esp + 0x20u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p2 = (double)*(float*)(cpu->ecx + cpu->ebx + 0x1Cu);
    x87_p0 = x87_p0 + x87_p2; 
    std::swap(x87_p1, x87_p0);
    cpu->ecx += cpu->ebx;
    *(float*)(cpu->esp + 0x44u) = x87_p1; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    x87_p1 = (double)*(float*)(cpu->esi + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->ecx + 0x20u)));
    cpu->edx = cpu->edx + (cpu->edx * 2u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    x87_p1 = (x87_p1) * (x87_p0);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->ecx + 0x20u)));
    *(float*)(cpu->esp + 0x48u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esi + 0x24u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->ecx + 0x24u)));
    x87_p1 = (x87_p1) * (x87_p0);
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->ecx + 0x24u)));
    *(float*)(cpu->esp + 0x4Cu) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->edx + cpu->ecx + 0x28u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x28u)));
    x87_p2 = (double)*(float*)(cpu->esp + 0x40u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = (double)*(float*)(cpu->eax + cpu->ecx + 0x28u);
    x87_p1 = x87_p1 + x87_p3; 
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0x24u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->ecx + 0x2Cu);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x2Cu)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->ecx + 0x2Cu)));
    *(float*)(cpu->esp + 0x28u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->ecx + 0x30u);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x30u)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->ecx + 0x30u)));
    *(float*)(cpu->esp + 0x2Cu) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->esi + 0x28u);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->esi + 0x28u)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->esi + 0x28u)));
    *(float*)(cpu->esp + 0x14u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->esi + 0x2Cu);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->esi + 0x2Cu)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->esi + 0x2Cu)));
    *(float*)(cpu->esp + 0x18u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->esi + 0x30u);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->esi + 0x30u)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->esi + 0x30u)));
    *(float*)(cpu->esp + 0x1Cu) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p3 = (double)*(float*)(cpu->esp + 0x24u); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    x87_p4 = x87_p0;
    x87_p2 = x87_p2 * x87_p4; 
    x87_p2 = x87_p2 + x87_p3; 
    *(float*)(cpu->esp + 0x50u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p3 = (double)*(float*)(cpu->esp + 0x28u); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    x87_p4 = x87_p0;
    x87_p2 = x87_p2 * x87_p4; 
    x87_p2 = x87_p2 + x87_p3; 
    *(float*)(cpu->esp + 0x54u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p3 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    x87_p4 = x87_p0;
    x87_p2 = x87_p2 * x87_p4; 
    x87_p2 = x87_p2 + x87_p3; 
    *(float*)(cpu->esp + 0x58u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->ecx + 0x88u);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x88u)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->ecx + 0x88u)));
    *(float*)(cpu->esp + 0x24u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->ecx + 0x8Cu);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x8Cu)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->ecx + 0x8Cu)));
    *(float*)(cpu->esp + 0x28u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->ecx + 0x90u);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x90u)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->ecx + 0x90u)));
    *(float*)(cpu->esp + 0x2Cu) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->esi + 0x88u);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->esi + 0x88u)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->esi + 0x88u)));
    *(float*)(cpu->esp + 0x14u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->esi + 0x8Cu);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->esi + 0x8Cu)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->esi + 0x8Cu)));
    *(float*)(cpu->esp + 0x18u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->esi + 0x90u);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->esi + 0x90u)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->esi + 0x90u)));
    *(float*)(cpu->esp + 0x1Cu) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p3 = (double)*(float*)(cpu->esp + 0x24u); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    x87_p4 = x87_p0;
    x87_p2 = x87_p2 * x87_p4; 
    x87_p2 = x87_p2 + x87_p3; 
    *(float*)(cpu->esp + 0x5Cu) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p3 = (double)*(float*)(cpu->esp + 0x28u); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    x87_p4 = x87_p0;
    x87_p2 = x87_p2 * x87_p4; 
    x87_p2 = x87_p2 + x87_p3; 
    *(float*)(cpu->esp + 0x60u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p3 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    x87_p4 = x87_p0;
    x87_p2 = x87_p2 * x87_p4; 
    x87_p2 = x87_p2 + x87_p3; 
    *(float*)(cpu->esp + 0x64u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->ecx + 0xE8u);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->ecx + 0xE8u)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->ecx + 0xE8u)));
    *(float*)(cpu->esp + 0x24u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->ecx + 0xECu);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->ecx + 0xECu)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->ecx + 0xECu)));
    *(float*)(cpu->esp + 0x28u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->ecx + 0xF0u);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->ecx + 0xF0u)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->ecx + 0xF0u)));
    *(float*)(cpu->esp + 0x2Cu) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->esi + 0xE8u);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->esi + 0xE8u)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->esi + 0xE8u)));
    *(float*)(cpu->esp + 0x14u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->esi + 0xECu);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->esi + 0xECu)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->esi + 0xECu)));
    *(float*)(cpu->esp + 0x18u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->edx + cpu->esi + 0xF0u);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->eax + cpu->esi + 0xF0u)));
    x87_p2 = (x87_p2) * (x87_p1);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->eax + cpu->esi + 0xF0u)));
    cpu->esi = cpu->edi + 0xFFFFFFFDu;
    *(float*)(cpu->esp + 0x1Cu) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p3 = (double)*(float*)(cpu->esp + 0x24u); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    x87_p4 = x87_p0;
    x87_p2 = x87_p2 * x87_p4; 
    x87_p2 = x87_p2 + x87_p3; 
    *(float*)(cpu->esp + 0x68u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p3 = (double)*(float*)(cpu->esp + 0x28u); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    x87_p4 = x87_p0;
    x87_p2 = x87_p2 * x87_p4; 
    x87_p2 = x87_p2 + x87_p3; 
    *(float*)(cpu->esp + 0x6Cu) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p3 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    std::swap(x87_p3, x87_p2);
    x87_p0 = x87_p0 * x87_p3; 
    x87_p0 = x87_p0 + x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x70u) = x87_p1; 
     value_0 = x87_p0; if ((int32_t)cpu->esi < 0) goto label_0009EC2C;
label_0009EA30:
    cpu->ecx = *(uint32_t*)(cpu->ebp + (cpu->esi * 8u));
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->ebp + (cpu->esi * 8u) + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x148u);
    x87_p0 = (double)*(float*)(cpu->ecx + cpu->ebx + 0x1Cu);
    x87_p1 = (double)*(float*)(cpu->esp + 0x44u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x20u); x87_p3 = x87_p2;
    x87_p0 = x87_p0 * x87_p3; 
    cpu->ecx += cpu->ebx;
    std::swap(x87_p2, x87_p0);
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x44u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->ecx + 0x20u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x48u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    x87_p3 = x87_p0;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x48u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->ecx + 0x24u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x4Cu); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    x87_p3 = x87_p0;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x4Cu) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->edx + cpu->ecx + 0x28u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x28u)));
    x87_p1 = (x87_p1) * (value_0);
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->eax + cpu->ecx + 0x28u)));
    *(float*)(cpu->esp + 0x14u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->edx + cpu->ecx + 0x2Cu);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x2Cu)));
    x87_p1 = (x87_p1) * (value_0);
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->eax + cpu->ecx + 0x2Cu)));
    *(float*)(cpu->esp + 0x18u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->edx + cpu->ecx + 0x30u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x30u)));
    x87_p1 = (x87_p1) * (value_0);
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->eax + cpu->ecx + 0x30u)));
    *(float*)(cpu->esp + 0x1Cu) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x50u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    x87_p3 = x87_p0;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x50u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x54u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    x87_p3 = x87_p0;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x54u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p2 = (double)*(float*)(cpu->esp + 0x58u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    x87_p3 = x87_p0;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x58u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->edx + cpu->ecx + 0x88u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x88u)));
    x87_p1 = (x87_p1) * (value_0);
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->eax + cpu->ecx + 0x88u)));
    *(float*)(cpu->esp + 0x14u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->edx + cpu->ecx + 0x8Cu);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x8Cu)));
    x87_p1 = (x87_p1) * (value_0);
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->eax + cpu->ecx + 0x8Cu)));
    *(float*)(cpu->esp + 0x18u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->edx + cpu->ecx + 0x90u);
    --cpu->esi;
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x90u)));
    cpu->edi = cpu->eax + cpu->ecx + 0xF0u;
    x87_p1 = (x87_p1) * (value_0);
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->eax + cpu->ecx + 0x90u)));
    *(float*)(cpu->esp + 0x1Cu) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x5Cu); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    x87_p3 = x87_p0;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x5Cu) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x60u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    x87_p3 = x87_p0;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x60u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p2 = (double)*(float*)(cpu->esp + 0x64u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    x87_p3 = x87_p0;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x64u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->edx + cpu->ecx + 0xE8u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->eax + cpu->ecx + 0xE8u)));
    x87_p1 = (x87_p1) * (value_0);
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->eax + cpu->ecx + 0xE8u)));
    *(float*)(cpu->esp + 0x14u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->edx + cpu->ecx + 0xECu);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->eax + cpu->ecx + 0xECu)));
    x87_p1 = (x87_p1) * (value_0);
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->eax + cpu->ecx + 0xECu)));
    *(float*)(cpu->esp + 0x18u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->edx + cpu->ecx + 0xF0u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->edi)));
    x87_p1 = (x87_p1) * (value_0);
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->edi)));
    *(float*)(cpu->esp + 0x1Cu) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x68u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    x87_p3 = x87_p0;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x68u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x6Cu); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    x87_p3 = x87_p0;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x6Cu) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p2 = (double)*(float*)(cpu->esp + 0x70u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    std::swap(x87_p2, x87_p1);
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x70u) = x87_p0; 
    if ((int32_t)(cpu->esi) >= 0) goto label_0009EA30;
label_0009EC2C:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi = cpu->esp + 0x44u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),48u); cpu->esi += 48u; cpu->edi += 48u; cpu->ecx = 0u;
     if (cpu->ebp == 0u) goto label_0009EC4A;
label_0009EC41:
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EC47u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49EC47u));
    cpu->esp += 4u;
label_0009EC4A:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x88u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049EC80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_0009ECA9;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9ECA9u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0x9ECA9u));
    label_0009ECA9:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->edx += *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049ECD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->esi != 0u) goto label_0009ECDB;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009ECDB:
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"LOSTCHECK");

    if (cpu->eax != 0u) goto label_0009ECF9;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 2u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009ECF9:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"NOTIFY_LB");

    if (cpu->eax != 0u) goto label_0009ED10;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009ED10:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"SEND_QUIT");

    if (cpu->eax != 0u) goto label_0009ED27;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 8u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009ED27:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"CENTER_TEXT");

    if (cpu->eax != 0u) goto label_0009ED3E;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009ED3E:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"SEND_HELP");

    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax &= 0xFFFFFFE0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 0x20u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049ED60(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49ED68u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x49ED68u));
    x87_v0 = (double)0.05000000074505806f;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    std::construct_at(reinterpret_cast<SphereUI::ButtonCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    *(float*)(cpu->esi + 0x1BCu) = x87_v0; 
    *(uint8_t*)(cpu->esi + 0x1B8u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1C0u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x50u) = 1u;
    *(uint32_t*)(cpu->esi + 0x118u) = 0xCu;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->eax;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049EDE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x18u;
    cpu->edi = cpu->ecx;
    { const uint32_t __parser_arg_016_0_0 = static_cast<uint32_t>(cpu->eax);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->getBlockRange(reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_0_0))); }
    if (*(uint32_t*)(cpu->edi + 0x9Cu) != 0u) goto label_0009EE1F;
    lift_push32(cpu, 0x84u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Button.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EE16u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x49EE16u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EE1Cu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x49EE1Cu));
    cpu->esp += 0x10u;
    label_0009EE1F:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    { const uint32_t __parser_arg_016_1_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_1_1 = static_cast<uint32_t>((uintptr_t)"checkedImage");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_1_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_1_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_0009EE7D;
    { const uint32_t __parser_arg_016_2_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); const uint32_t __parser_arg_016_2_1 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readQuotedString(__parser_arg_016_2_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_016_2_0))))); }
    if (cpu->eax == 0u) goto label_0009EE7D;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EE56u)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x49EE56u));
    *(uint32_t*)(cpu->edi + 0x1A0u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0009EE7D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ButtonCtrl::LoadUI(%s) -> Can't find sprite '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EE74u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x49EE74u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EE7Au)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x49EE7Au));
    cpu->esp += 0x10u;
    label_0009EE7D:
    { const uint32_t __parser_arg_016_3_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_3_1 = static_cast<uint32_t>((uintptr_t)"focusedImage");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_3_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_3_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_0009EED9;
    { const uint32_t __parser_arg_016_4_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); const uint32_t __parser_arg_016_4_1 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readQuotedString(__parser_arg_016_4_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_016_4_0))))); }
    if (cpu->eax == 0u) goto label_0009EED9;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EEB0u)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x49EEB0u));
    *(uint32_t*)(cpu->edi + 0x1A4u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0009EED9;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"ButtonCtrl::LoadUI(%s) -> Can't find sprite '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EECEu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x49EECEu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EED4u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x49EED4u));
    cpu->esp += 0x10u;
    goto label_0009EEDD;
    label_0009EED9:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    label_0009EEDD:
    { const uint32_t __parser_arg_016_5_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_5_1 = static_cast<uint32_t>((uintptr_t)"disabledImage");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_5_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_5_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_0009EF33;
    { const uint32_t __parser_arg_016_6_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); const uint32_t __parser_arg_016_6_1 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readQuotedString(__parser_arg_016_6_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_016_6_0))))); }
    if (cpu->eax == 0u) goto label_0009EF33;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EF10u)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x49EF10u));
    *(uint32_t*)(cpu->edi + 0x1C4u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0009EF33;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"ButtonCtrl::LoadUI(%s) -> Can't find sprite '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EF2Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x49EF2Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EF30u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x49EF30u));
    cpu->esp += 0x10u;
    label_0009EF33:
    { const uint32_t __parser_arg_016_7_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_7_1 = static_cast<uint32_t>((uintptr_t)"uncheckedImage");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_7_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_7_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_0009EF89;
    { const uint32_t __parser_arg_016_8_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); const uint32_t __parser_arg_016_8_1 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readQuotedString(__parser_arg_016_8_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_016_8_0))))); }
    if (cpu->eax == 0u) goto label_0009EF89;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EF66u)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x49EF66u));
    *(uint32_t*)(cpu->edi + 0x19Cu) = cpu->eax;
    if (cpu->eax != 0u) goto label_0009EF89;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"ButtonCtrl::LoadUI(%s) -> Can't find sprite '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EF80u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x49EF80u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EF86u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x49EF86u));
    cpu->esp += 0x10u;
    label_0009EF89:
    { const uint32_t __parser_arg_016_9_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_9_1 = static_cast<uint32_t>((uintptr_t)"buttonStyle");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_9_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_9_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_0009EFDC;
    cpu->ecx = cpu->esi;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->tokenCount(); }
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if ((int32_t)cpu->ebp <= 0) goto label_0009EFD8;
    label_0009EFB0:
    { const uint32_t __parser_arg_016_11_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); const uint32_t __parser_arg_016_11_1 = static_cast<uint32_t>(cpu->ebx);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readString(__parser_arg_016_11_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_016_11_0))))); }
    if (cpu->eax == 0u) goto label_0009EFD1;
    cpu->ecx = (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EFCBu)); sfera_sub_0049ECD0(cpu, LIFT_CODE_TOKEN_VA(0x49EFCBu));
    *(uint32_t*)(cpu->edi + 0x1A8u) = (uint64_t)(*(uint32_t*)(cpu->edi + 0x1A8u)) | (uint64_t)(cpu->eax);
    label_0009EFD1:
    cpu->ebx += 2u;
    if ((int32_t)cpu->ebx < (int32_t)cpu->ebp) goto label_0009EFB0;
    label_0009EFD8:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0009EFDC:
    { const uint32_t __parser_arg_016_12_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_12_1 = static_cast<uint32_t>((uintptr_t)"drawMethod");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_12_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_12_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_0009F038;
    { const uint32_t __parser_arg_016_13_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]); const uint32_t __parser_arg_016_13_1 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readString(__parser_arg_016_13_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_016_13_0))))); }
    if (cpu->eax == 0u) goto label_0009F038;
    cpu->ebx = native_function_address32(&::_stricmp);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))((uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0], (uintptr_t)"SPRITE");

    if (cpu->eax != 0u) goto label_0009F021;
    *(uint32_t*)(cpu->edi + 0x1A8u) = (uint64_t)(*(uint32_t*)(cpu->edi + 0x1A8u)) | (uint64_t)(1u);
    goto label_0009F038;
    label_0009F021:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))((uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0], (uintptr_t)"NONE");

    if (cpu->eax != 0u) goto label_0009F038;
    *(uint32_t*)(cpu->edi + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->edi + 0x24u)) | (uint64_t)(2u);
    label_0009F038:
    { const uint32_t __parser_arg_016_14_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_14_1 = static_cast<uint32_t>((uintptr_t)"hotKey");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_14_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_14_0))) ? 1u : 0u; }
    cpu->ebx = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_0009F0F7;
    { const uint32_t __parser_arg_016_15_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    cpu->ebp = 0u;
    const uint32_t __parser_arg_016_15_1 = static_cast<uint32_t>(cpu->ebp);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readQuotedString(__parser_arg_016_15_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_016_15_0))))); }
    if (cpu->eax == 0u) goto label_0009F0F3;
    cpu->ecx = (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F074u)); sfera_sub_004BEBC0(cpu, LIFT_CODE_TOKEN_VA(0x49F074u));
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->edi + 0x1ACu) = cpu->eax;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.button_value[0]);
    cpu->edx = cpu->esi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%s %d %d %d"); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebp;
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x9F0A3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->esp += 0x18u;
    cpu->eax = 0u;
    if (cpu->ecx != 1u) goto label_0009F0B7;
    cpu->eax = cpu->ecx;
    goto label_0009F0BE;
    label_0009F0B7:
    if (cpu->ecx != 2u) goto label_0009F0BE;
    cpu->eax = cpu->ecx;
    label_0009F0BE:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != 1u) goto label_0009F0CC;
    cpu->eax |= 4u;
    goto label_0009F0D4;
    label_0009F0CC:
    if (cpu->ecx != 2u) goto label_0009F0D4;
    cpu->eax |= 8u;
    label_0009F0D4:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != 1u) goto label_0009F0E2;
    cpu->eax|=0x10u;
    goto label_0009F0EA;
    label_0009F0E2:
    if (cpu->ecx != 2u) goto label_0009F0EA;
    cpu->eax|=0x20u;
    label_0009F0EA:
    cpu->eax <<= 16u;
    *(uint32_t*)(cpu->edi + 0x1ACu) = (uint64_t)(*(uint32_t*)(cpu->edi + 0x1ACu)) | (uint64_t)(cpu->eax);
    label_0009F0F3:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0009F0F7:
    { const uint32_t __parser_arg_016_16_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_16_1 = static_cast<uint32_t>((uintptr_t)"focuscolor");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_16_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_16_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_0009F16A;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x9F120u));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_0009F14A;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Button::LoadUI(%s,%d,%d) -> Not enough args in 'focuscolor'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F141u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x49F141u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F147u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x49F147u));
    cpu->esp += 0x14u;
    label_0009F14A:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint8_t*)(cpu->esp + 0x14u);
    cpu->ecx|=0xFFFFFF00u;
    cpu->ecx <<= 8u;
    cpu->ecx|=cpu->edx;
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->eax;
    goto label_0009F170;
    label_0009F16A:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x90u);
    label_0009F170:
    cpu->edx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->edi + 0x1C0u) = cpu->ecx;
    { const uint32_t __parser_arg_016_17_0 = static_cast<uint32_t>(cpu->edx);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->setBlockRange(reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_17_0))); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049F1A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    std::construct_at(reinterpret_cast<SphereUI::ButtonCtrl*>(cpu->esi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F1AEu)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x49F1AEu));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_0009F1BE;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F1BBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49F1BBu));
    cpu->esp += 4u;
    label_0009F1BE:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049F1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_0009F227;
    if (cpu->ecx > 0x3FFFFFFFu) goto label_0009F1F9;
    cpu->eax = cpu->ecx * 4u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F1F2u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x49F1F2u));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0009F227;
    label_0009F1F9:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9F227u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x9F227u));
    label_0009F227:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049F230(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[1]; double x87_v0, x87_v1, x87_v2;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_0009F508;
    if (((*(uint8_t*)(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_0009F508;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ebx = 0u;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == cpu->ebx) goto label_0009F28B;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (cpu->ecx == cpu->ebx) goto label_0009F27D;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9F27Du)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0x9F27Du));
    label_0009F27D:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    label_0009F28B:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    cpu->eax += cpu->ecx;
    lift_test[0]=(*(uint8_t*)(cpu->esi + 0x1A8u)&1u)==0u;
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x10u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u);
    if (lift_test[0]) goto label_0009F345;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->ecx = *(uint32_t*)(cpu->esi + (cpu->ecx * 4u) + 0x19Cu);
    if (*(uint8_t*)(cpu->esi + 0x49u) == (cpu->ebx & 0xFFu)) goto label_0009F2DA;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C4u);
    label_0009F2DA:
    if (cpu->ecx == cpu->ebx) goto label_0009F345;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->eax <<= 24u;
    cpu->eax |= 0xFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu))));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    if ((int32_t)cpu->edx >= 0) goto label_0009F308;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_0009F308:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    x87_v2 = (x87_v2) + (x87_v1);
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0x24u) = x87_v2; 
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0x24u);
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x28u))));
    if ((int32_t)cpu->eax >= 0) goto label_0009F329;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_0009F329:
    x87_v2 = (x87_v2) + (x87_v0);
    *(float*)(cpu->esp + 0x24u) = x87_v2; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 4u) = x87_v1; 
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F343u)); sfera_sub_004CE2B0(cpu, LIFT_CODE_TOKEN_VA(0x49F343u));
    goto label_0009F349;
    label_0009F345:
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    label_0009F349:
    if (*(uint32_t*)(cpu->esi + 0x64u) <= cpu->ebx) goto label_0009F506;
    if (*(uint32_t*)(cpu->esi + 0x198u) != cpu->ebx) goto label_0009F362;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    goto label_0009F368;
    label_0009F362:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C0u);
    label_0009F368:
    if (*(uint8_t*)(cpu->esi + 0x49u) == (cpu->ebx & 0xFFu)) goto label_0009F373;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x98u);
    label_0009F373:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xDCu);
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->eax&=0xFFFFFFu;
    x87_v1 = x87_v0;
    cpu->ecx <<= 24u;
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u); x87_v2 = x87_v1;
    g_sfera_screen_clip_runtime.left = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    g_sfera_screen_clip_runtime.top = cpu->eax;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x28u))));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    if ((int32_t)cpu->edx >= 0) goto label_0009F3B6;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_0009F3B6:
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    g_sfera_screen_clip_runtime.right = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu))));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    if ((int32_t)cpu->eax >= 0) goto label_0009F3D4;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_0009F3D4:
    x87_v0 = x87_v0 + x87_v1; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    g_sfera_screen_clip_runtime.bottom = cpu->eax;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x118u) == 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ebx = 0x10u;
    if (sub_pred[0]) goto label_0009F47E;
    cpu->eax = cpu->esi + 0x54u;
    if (*(uint32_t*)(cpu->esi + 0x68u) < cpu->ebx) goto label_0009F404;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0009F404:
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Du);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F424u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x49F424u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x118u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    if ((((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_0009F440;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    if (cpu->edi >= cpu->eax) goto label_0009F440;
    cpu->eax -= cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    label_0009F440:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    if ((((cpu->ecx & 0xFFu)) & (2u)) == 0u) goto label_0009F456;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    if (cpu->edx >= cpu->eax) goto label_0009F456;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_0009F456:
    if ((((cpu->ecx & 0xFFu)) & (4u)) == 0u) goto label_0009F46A;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    if (cpu->edi >= cpu->eax) goto label_0009F46A;
    cpu->eax -= cpu->edi;
    cpu->eax >>= 1u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    label_0009F46A:
    if ((((cpu->ecx & 0xFFu)) & (8u)) == 0u) goto label_0009F47E;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    if (cpu->edx >= cpu->eax) goto label_0009F47E;
    cpu->eax -= cpu->edx;
    cpu->eax >>= 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_0009F47E:
    cpu->edi = 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0xDCu) != cpu->edi) goto label_0009F49B;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_0009F49B;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9F49Bu)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0x9F49Bu));
    label_0009F49B:
    cpu->eax = cpu->esi + 0x54u;
    if (*(uint32_t*)(cpu->esi + 0x68u) < cpu->ebx) goto label_0009F4A5;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0009F4A5:
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    x87_v0 = 0.0;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Du);
    *(float*)(cpu->esp) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x28u)));
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->ebx = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u))));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x34u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F4E4u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x49F4E4u));
    cpu->ebp = lift_pop32(cpu);
    if (*(uint32_t*)(cpu->esi + 0xDCu) != cpu->edi) goto label_0009F506;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_0009F506;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    sfera_sub_004CE0E0(cpu, stop_address); return;
    label_0009F506:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0009F508:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049F510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x3E9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F547u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x49F547u));
    if (((*(uint8_t*)(cpu->esi + 0x1A8u)) & (8u)) == 0u) goto label_0009F568;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x10u) = 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9F568u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0x9F568u));
    label_0009F568:
    if (((*(uint8_t*)(cpu->esi + 0x1A8u)) & (0x20u)) == 0u) goto label_0009F58E;
    cpu->eax = cpu->esi + 0x70u;
    if (*(uint32_t*)(cpu->esi + 0x84u) < 0x10u) goto label_0009F57F;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0009F57F:
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->edx = 0xEu;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9F58Eu)); sfera_sub_004BB750(cpu, LIFT_CODE_TOKEN_RVA(0x9F58Eu));
    label_0009F58E:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049F5A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->eax != 0x3ECu) goto label_0009F5B8;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F5B0u)); sfera_sub_0049F510(cpu, LIFT_CODE_TOKEN_VA(0x49F5B0u));
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0009F5B8:
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    sfera_sub_004D2DD0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0049F5D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edx += *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049F5F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    if (*(uint32_t*)(cpu->esp + 0xCu) == cpu->ecx) goto label_0009F65C;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    (void)cpu;
    label_0009F600:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    --cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    if (cpu->edx == 0u) goto label_0009F60F;
    cpu->edx = *(uint32_t*)(cpu->edx);
    label_0009F60F:
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    if (cpu->esi > cpu->ecx) goto label_0009F618;
    cpu->ecx -= cpu->esi;
    label_0009F618:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    --cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    if (cpu->edx != 0u) goto label_0009F633;
    cpu->edi = 0u;
    goto label_0009F635;
    label_0009F633:
    cpu->edi = *(uint32_t*)(cpu->edx);
    label_0009F635:
    cpu->ebx = *(uint32_t*)(cpu->edi + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ebx > cpu->ecx) goto label_0009F642;
    cpu->ecx -= cpu->ebx;
    cpu->edx = cpu->ecx;
    label_0009F642:
    cpu->edi = *(uint32_t*)(cpu->edi + 4u);
    cpu->edi = *(uint32_t*)(cpu->edi + (cpu->edx * 4u));
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->esi += 28u; cpu->edi += 28u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    if (*(uint32_t*)(cpu->esp + 0x18u) != cpu->ecx) goto label_0009F600;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0009F65C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    if (cpu->ecx == 0u) goto label_0009F67B;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == 0u) goto label_0009F685;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0009F67B:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
    label_0009F685:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049F690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x18u)) goto label_0009F6FF;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_0009F6A3:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->esi != 0u) goto label_0009F6AF;
    cpu->ebx = 0u;
    goto label_0009F6B1;
    label_0009F6AF:
    cpu->ebx = *(uint32_t*)(cpu->esi);
    label_0009F6B1:
    cpu->esi = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edi = cpu->ecx;
    if (cpu->esi > cpu->ecx) goto label_0009F6BE;
    cpu->ecx -= cpu->esi;
    cpu->edi = cpu->ecx;
    label_0009F6BE:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->ecx == 0u) goto label_0009F6C8;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0009F6C8:
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->esi > cpu->edx) goto label_0009F6D1;
    cpu->edx -= cpu->esi;
    label_0009F6D1:
    cpu->esi = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = *(uint32_t*)(cpu->esi + (cpu->edi * 4u));
    cpu->edi = *(uint32_t*)(cpu->ebx + (cpu->edx * 4u));
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->esi += 28u; cpu->edi += 28u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    ++cpu->ecx;
    ++cpu->edx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x24u)) goto label_0009F6A3;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0009F6FF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    if (cpu->ecx == 0u) goto label_0009F721;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == 0u) goto label_0009F721;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0009F721:
    cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049F730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x10u)) goto label_0009F78F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_0009F743:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->ebx + 8u);
    cpu->esi = cpu->ecx;
    if (cpu->edi > cpu->ecx) goto label_0009F754;
    cpu->ecx -= cpu->edi;
    cpu->esi = cpu->ecx;
    label_0009F754:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    if (cpu->ecx > cpu->edx) goto label_0009F761;
    cpu->edx -= cpu->ecx;
    label_0009F761:
    cpu->ebx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edi = *(uint32_t*)(cpu->edi + 4u);
    cpu->edi = *(uint32_t*)(cpu->edi + (cpu->edx * 4u));
    cpu->esi = *(uint32_t*)(cpu->ebx + (cpu->esi * 4u));
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->esi += 28u; cpu->edi += 28u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    ++cpu->ecx;
    ++cpu->edx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0009F743;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0009F78F:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->esp += 0x20u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049F7A0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_0009F9B8;
    if (*(uint8_t*)(cpu->esi + 0x49u) != 0u) goto label_0009F9B8;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ebx = 0u;
    cpu->ebp = 0u;
    if (cpu->edi == cpu->ebx) goto label_0009F7FA;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (cpu->ecx == cpu->ebx) goto label_0009F7EC;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9F7ECu)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0x9F7ECu));
    label_0009F7EC:
    cpu->ebp = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ebp += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx += *(uint32_t*)(cpu->esp + 0x14u);
    label_0009F7FA:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1ACu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->eax == 0u) goto label_0009F82C;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x14u));
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0009F82C;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->ecx = cpu->ecx & 0xFFu;
    if (cpu->edx != cpu->ecx) goto label_0009F82C;
    cpu->eax >>= 16u;
    if (cpu->eax == 0u) goto label_0009F825;
    if (((*(uint32_t*)(cpu->edi + 0x18u)) & (cpu->eax)) == 0u) goto label_0009F82C;
    label_0009F825:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9F82Cu)); sfera_sub_0049F510(cpu, LIFT_CODE_TOKEN_RVA(0x9F82Cu));
    label_0009F82C:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->eax += cpu->ebp;
    cpu->ecx += cpu->ebx;
    if ((int32_t)cpu->edx < (int32_t)cpu->eax) goto label_0009F96F;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ebx += cpu->eax;
    if ((int32_t)cpu->edx >= (int32_t)cpu->ebx) goto label_0009F96F;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_0009F96F;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)cpu->eax >= (int32_t)cpu->edx) goto label_0009F96F;
    if (*(uint32_t*)(cpu->esi + 0x198u) != 0u) goto label_0009F878;
    *(uint32_t*)(cpu->esi + 0x198u) = 2u;
    label_0009F878:
    if (((*(uint8_t*)(cpu->edi + 0xCu)) & (1u)) == 0u) goto label_0009F88F;
    *(uint32_t*)(cpu->esi + 0x198u) = 1u;
    *(uint8_t*)(cpu->esi + 0x1B8u) = 1u;
    label_0009F88F:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (4u & 0xFFu);
    cpu->ebp = 0u;
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x1A8u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_0009F90D;
    if (*(uint8_t*)(cpu->esi + 0x1B8u) == 0u) goto label_0009F90D;
    if (((*(uint8_t*)(cpu->edi + 0x10u)) & (1u)) == 0u) goto label_0009F90D;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F8AFu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x49F8AFu));
    sub_pred[0] = cpu->eax < *(uint32_t*)(cpu->esi + 0x1B0u); cpu->eax -= *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1B4u) + (sub_pred[0]);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(float*)(cpu->esp + 0x20u) = ((((double)(((int64_t)(*(uint64_t*)(cpu->esp + 0x14u)))))) / (10000.0));
    { const double lift_right=(double)*(float*)(cpu->esp + 0x20u); const double lift_left=(double)*(float*)(cpu->esi + 0x1BCu); if (!(lift_left<lift_right)) goto label_0009F90D; }
    if (*(uint8_t*)(cpu->esi + 0x1B8u) == 0u) goto label_0009F8F7;
    *(uint32_t*)(cpu->esi + 0x198u) = 1u;
    label_0009F8F7:
    cpu->ebp = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F901u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x49F901u));
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->edx;
    label_0009F90D:
    if ((uint8_t)((*(uint8_t*)(cpu->edi + 0xCu)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_0009F95A;
    if (*(uint32_t*)(cpu->esi + 0x198u) != 1u) goto label_0009F95A;
    *(uint32_t*)(cpu->esi + 0x198u) = 2u;
    *(uint8_t*)(cpu->esi + 0x1B8u) = 0u;
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x1A8u)) & ((cpu->ebx & 0xFFu))) != 0u) goto label_0009F95A;
    if (g_sfera_interface_runtime.sounds_enabled == 0u) goto label_0009F95E;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"Sounds\\in_click.wav";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F949u)); sfera_sub_00498060(cpu, LIFT_CODE_TOKEN_VA(0x49F949u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F950u)); sfera_sub_0049F510(cpu, LIFT_CODE_TOKEN_VA(0x49F950u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009F95A:
    if (cpu->ebp == 0u) goto label_0009F9B5;
    label_0009F95E:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F965u)); sfera_sub_0049F510(cpu, LIFT_CODE_TOKEN_VA(0x49F965u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009F96F:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->eax == 0u) goto label_0009F99F;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    if (cpu->eax == 2u) goto label_0009F986;
    if (((*(uint8_t*)(cpu->edi + 0x10u)) & (1u)) != 0u) goto label_0009F988;
    label_0009F986:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    label_0009F988:
    if (((*(uint8_t*)(cpu->esi + 0x1A8u)) & (2u)) != 0u) goto label_0009F995;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0009F99F;
    label_0009F995:
    *(uint32_t*)(cpu->esi + 0x198u) = 0u;
    label_0009F99F:
    if (*(uint8_t*)(cpu->esi + 0x1B8u) == 0u) goto label_0009F9B5;
    if (((*(uint8_t*)(cpu->edi + 0x10u)) & (1u)) != 0u) goto label_0009F9B5;
    *(uint8_t*)(cpu->esi + 0x1B8u) = 0u;
    label_0009F9B5:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0009F9B8:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049F9C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    if (cpu->ecx == 0u) goto label_0009F9E3;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0009F9E3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049F9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    if (cpu->eax == 0u) goto label_0009FA16;
    ++*(uint32_t*)(cpu->ecx + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    if (*(uint32_t*)(cpu->ecx + 8u) > cpu->edx) goto label_0009FA09;
    *(uint32_t*)(cpu->ecx + 0xCu) = 0u;
    label_0009FA09:
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0009FA16;
    *(uint32_t*)(cpu->ecx + 0xCu) = 0u;
    label_0009FA16:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049FA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    if (cpu->eax == 0u) goto label_0009FA34;
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0009FA34;
    *(uint32_t*)(cpu->ecx + 0xCu) = 0u;
    label_0009FA34:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049FA40(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ebx = 0u;
    if (cpu->eax == cpu->ebx) goto label_0009FA62;
    label_0009FA50:
    if (cpu->eax == cpu->ebx) goto label_0009FA5D;
    --cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0009FA5D;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_0009FA5D:
    if (*(uint32_t*)(cpu->esi + 0x10u) != cpu->ebx) goto label_0009FA50;
    label_0009FA62:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->edi <= cpu->ebx) goto label_0009FA8B;
    label_0009FA70:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    --cpu->edi;
    sub_pred[0] = *(uint32_t*)(cpu->eax + (cpu->edi * 4u)) == cpu->ebx;
    cpu->eax = cpu->eax + (cpu->edi * 4u);
    if (sub_pred[0]) goto label_0009FA87;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FA84u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49FA84u));
    cpu->esp += 4u;
    label_0009FA87:
    if (cpu->edi > cpu->ebx) goto label_0009FA70;
    label_0009FA8B:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = lift_pop32(cpu);
    if (cpu->eax == cpu->ebx) goto label_0009FA9C;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FA99u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49FA99u));
    cpu->esp += 4u;
    label_0009FA9C:
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049FAB0(LiftCpu* cpu, uint32_t stop_address) {
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
    if (cpu->ecx == cpu->edx) goto label_0009FADB;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0009FADB;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0009FADB:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0009FB02;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0009FB02;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0009FB02:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0009FB29;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0009FB29;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0009FB29:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FB37u)); sfera_sub_0049F5F0(cpu, LIFT_CODE_TOKEN_VA(0x49FB37u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049FB40(LiftCpu* cpu, uint32_t stop_address) {
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
    if (cpu->ecx == cpu->edx) goto label_0009FB6B;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0009FB6B;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0009FB6B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0009FB92;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0009FB92;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0009FB92:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0009FBB9;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0009FBB9;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0009FBB9:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FBC7u)); sfera_sub_0049F690(cpu, LIFT_CODE_TOKEN_VA(0x49FBC7u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049FBD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    cpu->ecx = 0x9249249u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx -= cpu->eax;
    if (cpu->ecx >= cpu->ebp) goto label_0009FBF4;
    lift_push32(cpu, (uintptr_t)"deque<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x49FBD0u), "std::length_error");
    label_0009FBF4:
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 1u;
    if (cpu->ecx >= 8u) goto label_0009FC02;
    cpu->ecx = 8u;
    label_0009FC02:
    if (cpu->ebp >= cpu->ecx) goto label_0009FC13;
    cpu->edx = 0x9249249u;
    cpu->edx -= cpu->ecx;
    if (cpu->eax > cpu->edx) goto label_0009FC13;
    cpu->ebp = cpu->ecx;
    label_0009FC13:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebx + 0xCu);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx + 0x15u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FC27u)); sfera_sub_0049F1D0(cpu, LIFT_CODE_TOKEN_VA(0x49FC27u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = cpu->eax;
    cpu->esi = cpu->edi * 4u;
    cpu->eax = cpu->esi + cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax -= *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49FC5Fu));
    cpu->eax += *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->esp += 0xCu;
    if (cpu->edi > cpu->ebp) goto label_0009FCB0;
    cpu->esi = (int32_t)(cpu->esi) >> 2u;
    cpu->edx = cpu->esi;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49FC85u));
    cpu->edx = cpu->eax;
    cpu->edx += *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esp += 0xCu;
    if ((cpu->esi -= cpu->edi) == 0u) goto label_0009FCA4;
    cpu->eax = 0u;
    std::memset((void*)(cpu->edx),0x00,(cpu->esi)*4u); cpu->ecx = 0u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    label_0009FCA4:
    if (cpu->edi == 0u) goto label_0009FCF7;
    cpu->ecx = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    goto label_0009FCF3;
    label_0009FCB0:
    cpu->edi = cpu->ebp * 4u;
    cpu->edx = cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49FCC3u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->edi + cpu->eax;
    cpu->esi -= cpu->ecx;
    cpu->esi += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esi = (int32_t)(cpu->esi) >> 2u;
    cpu->esi += cpu->esi;
    cpu->esi += cpu->esi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49FCE1u));
    cpu->esp += 0x18u;
    cpu->edi = cpu->esi + cpu->eax;
    if (cpu->ebp == 0u) goto label_0009FCF7;
    cpu->ecx = cpu->ebp;
    label_0009FCF3:
    std::memset((void*)cpu->edi,0,cpu->ecx*4u);
    label_0009FCF7:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_0009FD09;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FD06u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49FD06u));
    cpu->esp += 4u;
    label_0009FD09:
    *(uint32_t*)(cpu->ebx + 8u) = (uint64_t)(*(uint32_t*)(cpu->ebx + 8u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049FD20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esp -= 0x1Cu;
    if (cpu->eax == cpu->ecx) goto label_0009FD98;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_0009FD31:
    --cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    if (cpu->eax == cpu->ecx) goto label_0009FD96;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->edi + 8u);
    if (cpu->edx > cpu->ecx) goto label_0009FD47;
    cpu->ecx -= cpu->edx;
    label_0009FD47:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->edx > cpu->eax) goto label_0009FD54;
    cpu->eax -= cpu->edx;
    label_0009FD54:
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    std::memmove((void*)(cpu->esp + 8u),(void*)(cpu->eax),28u);
    std::memmove((void*)(cpu->eax),(void*)(cpu->edx),28u);
    cpu->esi = cpu->esp + 8u;
    cpu->edi = cpu->edx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->esi += 28u; cpu->edi += 28u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    if (cpu->eax != cpu->ecx) goto label_0009FD31;
    label_0009FD96:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0009FD98:
    cpu->esp += 0x1Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049FDA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x5Cu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ebx;
    cpu->edi -= cpu->esi;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    if (cpu->ecx == 0u) goto label_0009FDDA;
    label_0009FDC9:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->ecx = cpu->edx;
    if (cpu->edx != 0u) goto label_0009FDC9;
    label_0009FDDA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    if ((int32_t)cpu->eax >= (int32_t)cpu->edi) goto label_0009FF0A;
    if ((int32_t)cpu->eax <= 0) goto label_0009FF0A;
    label_0009FDEE:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax += cpu->esi;
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->esi = cpu->eax;
    if (cpu->edx != cpu->ebx) goto label_0009FE1D;
    cpu->eax = cpu->ebp + 8u;
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    goto label_0009FE48;
    label_0009FE1D:
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    cpu->eax = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    goto label_0009FE48;
    label_0009FE40:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    label_0009FE48:
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    cpu->eax = cpu->edx;
    if (cpu->ecx > cpu->edx) goto label_0009FE53;
    cpu->eax -= cpu->ecx;
    label_0009FE53:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->ecx = cpu->esi;
    if (cpu->ebx > cpu->esi) goto label_0009FE64;
    cpu->esi -= cpu->ebx;
    cpu->ecx = cpu->esi;
    label_0009FE64:
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi + (cpu->eax * 4u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->ebx = *(uint32_t*)(cpu->esi + (cpu->ecx * 4u));
    std::memmove((void*)(cpu->esp + 0x4Cu),(void*)(cpu->ebx),28u);
    std::memmove((void*)(cpu->ebx),(void*)(cpu->eax),28u);
    std::memmove((void*)(cpu->eax),(void*)(cpu->esp + 0x4Cu),28u);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = cpu->ebx;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    if ((int32_t)cpu->edi >= (int32_t)cpu->eax) goto label_0009FECD;
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edx;
    cpu->edx += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    cpu->eax = cpu->esp + 0x2Cu;
    goto label_0009FEE6;
    label_0009FECD:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->eax;
    cpu->ecx += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    cpu->eax = cpu->esp + 0x34u;
    label_0009FEE6:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    if (cpu->edx != *(uint32_t*)(cpu->esp + 0x40u)) goto label_0009FE40;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    --cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if ((int32_t)cpu->eax > 0) goto label_0009FDEE;
    label_0009FF0A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049FF20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
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
    if (cpu->ecx == cpu->ebx) goto label_0009FF4B;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0009FF4B;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0009FF4B:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FF5Eu)); sfera_sub_0049F9C0(cpu, LIFT_CODE_TOKEN_VA(0x49FF5Eu));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_0009FF7E;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0009FF7E;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0009FF7E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FF91u)); sfera_sub_0049F9C0(cpu, LIFT_CODE_TOKEN_VA(0x49FF91u));
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FF9Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x49FF9Du));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FFC0u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x49FFC0u));
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
    if (sub_pred[0]) goto label_000A0070;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->ecx == cpu->ebx) goto label_0009FFF6;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0009FFF6;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0009FFF6:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_000A001D;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_000A001D;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000A001D:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0035u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A0035u));
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A003Eu)); sfera_sub_0049FAB0(cpu, LIFT_CODE_TOKEN_VA(0x4A003Eu));
    if (cpu->ebp <= cpu->ebx) goto label_000A00E1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    label_000A0050:
    if (cpu->ecx == cpu->ebx) goto label_000A0068;
    ++*(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if (*(uint32_t*)(cpu->esi + 8u) > cpu->eax) goto label_000A0062;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_000A0062:
    if ((--cpu->ecx) != 0u) goto label_000A0068;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_000A0068:
    if ((--cpu->ebp) != 0u) goto label_000A0050;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    goto label_000A00E1;
    label_000A0070:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->ecx == cpu->ebx) goto label_000A0082;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_000A0082;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000A0082:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A009Au)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4A009Au));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_000A00BA;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_000A00BA;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000A00BA:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->esp + 0x50u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A00CAu)); sfera_sub_0049FB40(cpu, LIFT_CODE_TOKEN_VA(0x4A00CAu));
    if (cpu->ebp <= cpu->ebx) goto label_000A00E1;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    label_000A00D1:
    if (cpu->eax == cpu->ebx) goto label_000A00DB;
    if ((--cpu->eax) != 0u) goto label_000A00DB;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_000A00DB:
    if ((--cpu->ebp) != 0u) goto label_000A00D1;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    label_000A00E1:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A00F3u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A00F3u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A00FAu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A00FAu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 0x20u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A0110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == cpu->ecx) goto label_000A012F;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == cpu->ecx) goto label_000A012F;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_000A0135;
    label_000A012F:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    goto label_000A013B;
    label_000A0135:
    cpu->eax = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000A013B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x3Cu);
    if (cpu->eax == cpu->ecx) goto label_000A0153;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == cpu->ecx) goto label_000A0153;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_000A0157;
    label_000A0153:
    cpu->edi = 0u;
    goto label_000A0159;
    label_000A0157:
    cpu->edi = *(uint32_t*)(cpu->eax);
    label_000A0159:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    if (cpu->eax == cpu->ecx) goto label_000A0173;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == cpu->ecx) goto label_000A0173;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == cpu->ecx) goto label_000A0173;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000A0173:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A018Fu)); sfera_sub_0049F730(cpu, LIFT_CODE_TOKEN_VA(0x4A018Fu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    cpu->eax = cpu->esi;
    if (cpu->ecx == 0u) goto label_000A01BB;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == 0u) goto label_000A01BB;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    label_000A01BB:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A01D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    ++cpu->eax;
    lift_push32(cpu, cpu->esi);
    if (*(uint32_t*)(cpu->ebx + 8u) > cpu->eax) goto label_000A01E7;
    lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA01E7u)); sfera_sub_0049FBD0(cpu, LIFT_CODE_TOKEN_RVA(0xA01E7u));
    label_000A01E7:
    cpu->esi = *(uint32_t*)(cpu->ebx + 0xCu);
    cpu->esi += *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    if (cpu->eax > cpu->esi) goto label_000A01F6;
    cpu->esi -= cpu->eax;
    label_000A01F6:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) != 0u) goto label_000A0213;
    lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0206u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A0206u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000A0235;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = cpu->eax;
    label_000A0213:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (cpu->edi == 0u) goto label_000A0229;
    std::memmove((void*)(cpu->edi),(void*)(*(uint32_t*)(cpu->esp + 0x20u)),28u);
    label_000A0229:
    ++*(uint32_t*)(cpu->ebx + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A0235:
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0263u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4A0263u));
    lift_trap(cpu, 0x4A0263u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004A0270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi == cpu->ebx) goto label_000A02FB;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->ebx == cpu->ebp) goto label_000A02FB;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->eax == 0u) goto label_000A029E;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000A029E;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000A02A2;
    label_000A029E:
    cpu->edx = 0u;
    goto label_000A02A4;
    label_000A02A2:
    cpu->edx = *(uint32_t*)(cpu->eax);
    label_000A02A4:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->eax == 0u) goto label_000A02B8;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000A02B8;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000A02BC;
    label_000A02B8:
    cpu->ecx = 0u;
    goto label_000A02BE;
    label_000A02BC:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000A02BE:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax == 0u) goto label_000A02D2;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000A02D2;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000A02D6;
    label_000A02D2:
    cpu->eax = 0u;
    goto label_000A02D8;
    label_000A02D6:
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000A02D8:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A02E7u)); sfera_sub_0049FDA0(cpu, LIFT_CODE_TOKEN_VA(0x4A02E7u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    cpu->esi += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    label_000A02FB:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->edi) = 0u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    if (cpu->eax == 0u) goto label_000A031D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000A031D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    label_000A031D:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A0330(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    label_000A0370:
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x10u)) goto label_000A03E6;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax += 8u;
    cpu->esi = cpu->ecx + 4u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A038Au)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4A038Au));
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000A03A4;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A0370u), "std::length_error");
    label_000A03A4:
    ++cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->eax;
    goto label_000A0370;
    label_000A03E6:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A03B9(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    if (cpu->esi == *(uint32_t*)(cpu->ebp + 0xCu)) goto label_000A03DD;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    label_000A03C4:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A03D6u)); sfera_sub_004A63C0(cpu, LIFT_CODE_TOKEN_VA(0x4A03D6u));
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(cpu->ebp + 0xCu)) goto label_000A03C4;
    label_000A03DD:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A03E6u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4A03E6u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A0400(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x6Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->ebx;
    cpu->eax = cpu->ebp + 0xFFFFFFB8u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0439u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A0439u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    if (cpu->edx == *(uint32_t*)(cpu->ebp + 0x28u)) goto label_000A075B;
    cpu->eax >>= 1u;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) > cpu->eax) goto label_000A0621;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    label_000A0470:
    if (cpu->edx == *(uint32_t*)(cpu->ebp + 0x28u)) goto label_000A0555;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x14u);
    if (cpu->eax != 0u) goto label_000A0484;
    cpu->ecx = 0u;
    goto label_000A0486;
    label_000A0484:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000A0486:
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->edx;
    if (cpu->esi > cpu->edx) goto label_000A0491;
    cpu->eax -= cpu->esi;
    label_000A0491:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    ++cpu->eax;
    if (*(uint32_t*)(cpu->ebx + 8u) > cpu->eax) goto label_000A04AC;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A04A9u)); sfera_sub_0049FBD0(cpu, LIFT_CODE_TOKEN_VA(0x4A04A9u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    label_000A04AC:
    cpu->esi = *(uint32_t*)(cpu->ebx + 0xCu);
    if (cpu->esi != 0u) goto label_000A04B8;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->esi = cpu->ecx;
    label_000A04B8:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    --cpu->esi;
    sub_pred[0] = *(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esi;
    if (!sub_pred[0]) goto label_000A04DC;
    lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A04CCu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A04CCu));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000A0506;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    label_000A04DC:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (cpu->eax == 0u) goto label_000A04F7;
    cpu->esi = cpu->edi;
    cpu->edi = cpu->eax;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->edi += 28u; cpu->ecx = 0u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    label_000A04F7:
    ++*(uint32_t*)(cpu->ebx + 0x10u);
    ++cpu->edx;
    *(uint32_t*)(cpu->ebx + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0x1Cu) = cpu->edx;
    goto label_000A0470;
    label_000A0506:
    cpu->edx = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0xFFFFFFD0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0xFFFFFFD0u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA052Fu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xA052Fu));
    sfera_sub_004A052F(cpu, stop_address); return;
    label_000A0555:
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->esi -= *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = cpu->ebp + 0xFFFFFFC4u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFA0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A056Bu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A056Bu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0572u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A0572u));
    cpu->ecx = cpu->ebp + 0xFFFFFFB8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A057Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A057Du));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    if (cpu->eax == 0u) goto label_000A0594;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000A0594;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000A0598;
    label_000A0594:
    cpu->ecx = 0u;
    goto label_000A059A;
    label_000A0598:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000A059A:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFB8u);
    lift_push32(cpu, cpu->ecx);
    if (cpu->eax == 0u) goto label_000A05B2;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000A05B2;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000A05B6;
    label_000A05B2:
    cpu->ecx = 0u;
    goto label_000A05B8;
    label_000A05B6:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000A05B8:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A05C2u)); sfera_sub_0049FD20(cpu, LIFT_CODE_TOKEN_VA(0x4A05C2u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebp + 0xFFFFFFA0u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFB8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A05DFu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A05DFu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A05E6u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A05E6u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A05EDu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A05EDu));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esp;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFF94u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0602u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A0602u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0609u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A0609u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0619u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A0619u));
    cpu->ecx = cpu->ebp + 0xFFFFFF88u;
    goto label_000A0756;
    label_000A0621:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    label_000A0630:
    if (cpu->edx == *(uint32_t*)(cpu->ebp + 0x28u)) goto label_000A0705;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x14u);
    if (cpu->eax != 0u) goto label_000A0644;
    cpu->ecx = 0u;
    goto label_000A0646;
    label_000A0644:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000A0646:
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->edx;
    if (cpu->esi > cpu->edx) goto label_000A0651;
    cpu->eax -= cpu->esi;
    label_000A0651:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    ++cpu->eax;
    if (*(uint32_t*)(cpu->ebx + 8u) > cpu->eax) goto label_000A066C;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0669u)); sfera_sub_0049FBD0(cpu, LIFT_CODE_TOKEN_VA(0x4A0669u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    label_000A066C:
    cpu->edi = *(uint32_t*)(cpu->ebx + 0xCu);
    cpu->edi += *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    if (cpu->eax > cpu->edi) goto label_000A067B;
    cpu->edi -= cpu->eax;
    label_000A067B:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ecx + (cpu->edi * 4u)) != 0u) goto label_000A069B;
    lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A068Bu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A068Bu));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000A06BB;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    *(uint32_t*)(cpu->edx + (cpu->edi * 4u)) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    label_000A069B:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    if (cpu->edi == 0u) goto label_000A06AF;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->esi += 28u; cpu->edi += 28u; cpu->ecx = 0u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    label_000A06AF:
    ++*(uint32_t*)(cpu->ebx + 0x10u);
    ++cpu->edx;
    *(uint32_t*)(cpu->ebp + 0x1Cu) = cpu->edx;
    goto label_000A0630;
    label_000A06BB:
    cpu->eax = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFACu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFACu;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA06E4u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xA06E4u));
    sfera_sub_004A06E4(cpu, stop_address); return;
    label_000A0705:
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0715u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4A0715u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0xFFFFFF88u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A072Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A072Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0734u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A0734u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0xFFFFFF94u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A074Cu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A074Cu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0753u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A0753u));
    cpu->ecx = cpu->ebp + 0xFFFFFFA0u;
    label_000A0756:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA075Bu)); sfera_sub_004A0270(cpu, LIFT_CODE_TOKEN_RVA(0xA075Bu));
    label_000A075B:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A052F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    if (cpu->edi >= *(uint32_t*)(cpu->esi + 0x10u)) goto label_000A054C;
    label_000A0540:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0547u)); sfera_sub_0049F9F0(cpu, LIFT_CODE_TOKEN_VA(0x4A0547u));
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x10u)) goto label_000A0540;
    label_000A054C:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0555u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4A0555u));
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->esi -= *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = cpu->ebp + 0xFFFFFFC4u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFA0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A056Bu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A056Bu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0572u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A0572u));
    cpu->ecx = cpu->ebp + 0xFFFFFFB8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A057Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A057Du));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    if (cpu->eax == 0u) goto label_000A0594;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000A0594;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000A0598;
    label_000A0594:
    cpu->ecx = 0u;
    goto label_000A059A;
    label_000A0598:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000A059A:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFB8u);
    lift_push32(cpu, cpu->ecx);
    if (cpu->eax == 0u) goto label_000A05B2;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_000A05B2;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_000A05B6;
    label_000A05B2:
    cpu->ecx = 0u;
    goto label_000A05B8;
    label_000A05B6:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_000A05B8:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A05C2u)); sfera_sub_0049FD20(cpu, LIFT_CODE_TOKEN_VA(0x4A05C2u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebp + 0xFFFFFFA0u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFB8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A05DFu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A05DFu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A05E6u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A05E6u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A05EDu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A05EDu));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esp;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFF94u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0602u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A0602u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0609u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A0609u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0619u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A0619u));
    cpu->ecx = cpu->ebp + 0xFFFFFF88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A075Bu)); sfera_sub_004A0270(cpu, LIFT_CODE_TOKEN_VA(0x4A075Bu));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A06E4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    if (cpu->edi >= *(uint32_t*)(cpu->esi + 0x10u)) goto label_000A06FC;
    (void)cpu;
    label_000A06F0:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A06F7u)); sfera_sub_0049FA20(cpu, LIFT_CODE_TOKEN_VA(0x4A06F7u));
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x10u)) goto label_000A06F0;
    label_000A06FC:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0705u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4A0705u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0715u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4A0715u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0xFFFFFF88u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A072Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A072Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0734u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A0734u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0xFFFFFF94u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A074Cu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A074Cu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0753u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A0753u));
    cpu->ecx = cpu->ebp + 0xFFFFFFA0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A075Bu)); sfera_sub_004A0270(cpu, LIFT_CODE_TOKEN_VA(0x4A075Bu));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A0770(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esp;
    if (cpu->edx == 0u) goto label_000A079E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_000A079E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000A079E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    if (cpu->edx == 0u) goto label_000A07CD;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_000A07CD;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000A07CD:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esp;
    if (cpu->edx == 0u) goto label_000A07FC;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_000A07FC;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000A07FC:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0808u)); sfera_sub_004A0400(cpu, LIFT_CODE_TOKEN_VA(0x4A0808u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A0810(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    if (cpu->eax == *(uint32_t*)(cpu->esi)) goto label_000A0842;
    lift_push32(cpu, cpu->edi);
    label_000A0830:
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0838u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A0838u));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if (cpu->edi != *(uint32_t*)(cpu->esi)) goto label_000A0830;
    cpu->edi = lift_pop32(cpu);
    label_000A0842:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A085Du)); sfera_sub_004A0330(cpu, LIFT_CODE_TOKEN_VA(0x4A085Du));
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A0870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->edi == cpu->esi) goto label_000A0A2B;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ebp = 0u;
    if (cpu->ecx != cpu->ebp) goto label_000A08A1;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0895u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4A0895u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A08A1:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    if (cpu->ecx > cpu->eax) goto label_000A0957;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A08BDu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A08BDu));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A08CEu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4A08CEu));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->esp;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A08DFu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A08DFu));
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A08E8u)); sfera_sub_004A0110(cpu, LIFT_CODE_TOKEN_VA(0x4A08E8u));
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A08F4u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4A08F4u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->ebp;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esp;
    if (cpu->edx == cpu->ebp) goto label_000A0912;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == cpu->ebp) goto label_000A0912;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_000A0912:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebp;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esp;
    if (cpu->ecx == cpu->ebp) goto label_000A0938;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebp) goto label_000A0938;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000A0938:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A094Bu)); sfera_sub_0049FF20(cpu, LIFT_CODE_TOKEN_VA(0x4A094Bu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A0957:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0969u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A0969u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0970u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4A0970u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0981u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A0981u));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebp;
    if (cpu->ebx == cpu->ebp) goto label_000A09A1;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    if (cpu->ecx == cpu->ebp) goto label_000A09A1;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000A09A1:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->esp;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A09B9u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4A09B9u));
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A09C2u)); sfera_sub_004A0110(cpu, LIFT_CODE_TOKEN_VA(0x4A09C2u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A09D3u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4A09D3u));
    cpu->esp -= 0xCu;
    cpu->esi = 0u;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    if (cpu->ebx == cpu->esi) goto label_000A09F1;
    cpu->ebx = *(uint32_t*)(cpu->ebx);
    if (cpu->ebx == cpu->esi) goto label_000A09F1;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000A09F1:
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0A00u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4A0A00u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->esp;
    if (cpu->edx == cpu->esi) goto label_000A0A1E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == cpu->esi) goto label_000A0A1E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_000A0A1E:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA0A2Bu)); sfera_sub_004A0770(cpu, LIFT_CODE_TOKEN_RVA(0xA0A2Bu));
    label_000A0A2B:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A0A40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0A5Au)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4A0A5Au));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x24u);
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x28u);
    *(uint32_t*)(cpu->ebx + 0x28u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x2Cu);
    *(uint32_t*)(cpu->ebx + 0x2Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x30u);
    *(uint32_t*)(cpu->ebx + 0x30u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x34u);
    *(uint32_t*)(cpu->ebx + 0x34u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x38u);
    *(uint32_t*)(cpu->ebx + 0x38u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    *(uint32_t*)(cpu->ebx + 0x3Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x40u);
    *(uint32_t*)(cpu->ebx + 0x40u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x44u);
    *(uint32_t*)(cpu->ebx + 0x44u) = cpu->eax;
    cpu->ecx = *(uint8_t*)(cpu->ebp + 0x48u);
    *(uint8_t*)(cpu->ebx + 0x48u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint8_t*)(cpu->ebp + 0x49u);
    *(uint8_t*)(cpu->ebx + 0x49u) = cpu->edx & 0xFFu;
    cpu->eax = *(uint8_t*)(cpu->ebp + 0x4Au);
    *(uint8_t*)(cpu->ebx + 0x4Au) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint8_t*)(cpu->ebp + 0x4Bu);
    *(uint8_t*)(cpu->ebx + 0x4Bu) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint8_t*)(cpu->ebp + 0x4Cu);
    *(uint8_t*)(cpu->ebx + 0x4Cu) = cpu->edx & 0xFFu;
    cpu->eax = *(uint8_t*)(cpu->ebp + 0x4Du);
    *(uint8_t*)(cpu->ebx + 0x4Du) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint8_t*)(cpu->ebp + 0x4Eu);
    *(uint8_t*)(cpu->ebx + 0x4Eu) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint8_t*)(cpu->ebp + 0x4Fu);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0x54u;
    *(uint8_t*)(cpu->ebx + 0x4Fu) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x50u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx + 0x54u;
    *(uint32_t*)(cpu->ebx + 0x50u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0ADEu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4A0ADEu));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0x70u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx + 0x70u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0AEEu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4A0AEEu));
    cpu->eax = *(uint8_t*)(cpu->ebp + 0x8Cu);
    *(uint8_t*)(cpu->ebx + 0x8Cu) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint8_t*)(cpu->ebp + 0x8Du);
    *(uint8_t*)(cpu->ebx + 0x8Du) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x90u);
    *(uint32_t*)(cpu->ebx + 0x90u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x94u);
    *(uint32_t*)(cpu->ebx + 0x94u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x98u);
    *(uint32_t*)(cpu->ebx + 0x98u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x9Cu);
    cpu->eax = cpu->ebp + 0xA0u;
    cpu->ecx = cpu->ebx + 0xA0u;
    *(uint32_t*)(cpu->ebx + 0x9Cu) = cpu->edx;
    if (cpu->ecx == cpu->eax) goto label_000A0B58;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA0B58u)); sfera_sub_004A0810(cpu, LIFT_CODE_TOKEN_RVA(0xA0B58u));
    label_000A0B58:
    cpu->eax = cpu->ebp + 0xACu;
    cpu->ecx = cpu->ebx + 0xACu;
    if (cpu->ecx == cpu->eax) goto label_000A0B78;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA0B78u)); sfera_sub_004A0810(cpu, LIFT_CODE_TOKEN_RVA(0xA0B78u));
    label_000A0B78:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xB8u);
    cpu->ecx = cpu->ebp + 0xBCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx + 0xBCu;
    *(uint32_t*)(cpu->ebx + 0xB8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0B96u)); sfera_sub_004A0870(cpu, LIFT_CODE_TOKEN_VA(0x4A0B96u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xD4u);
    *(uint32_t*)(cpu->ebx + 0xD4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xD8u);
    *(uint32_t*)(cpu->ebx + 0xD8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xDCu);
    *(uint32_t*)(cpu->ebx + 0xDCu) = cpu->ecx;
    cpu->edx = *(uint8_t*)(cpu->ebp + 0xE0u);
    *(uint8_t*)(cpu->ebx + 0xE0u) = cpu->edx & 0xFFu;
    cpu->eax = *(uint8_t*)(cpu->ebp + 0xE1u);
    *(uint8_t*)(cpu->ebx + 0xE1u) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xE4u);
    *(uint32_t*)(cpu->ebx + 0xE4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xE8u);
    *(uint32_t*)(cpu->ebx + 0xE8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xECu);
    *(uint32_t*)(cpu->ebx + 0xECu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xF0u);
    *(uint32_t*)(cpu->ebx + 0xF0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xF4u);
    *(uint32_t*)(cpu->ebx + 0xF4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xF8u);
    *(uint32_t*)(cpu->ebx + 0xF8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFCu);
    *(uint32_t*)(cpu->ebx + 0xFCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x100u);
    *(uint32_t*)(cpu->ebx + 0x100u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x104u);
    *(uint32_t*)(cpu->ebx + 0x104u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x108u);
    *(uint32_t*)(cpu->ebx + 0x108u) = cpu->ecx;
    cpu->edx = *(uint8_t*)(cpu->ebp + 0x10Cu);
    *(uint8_t*)(cpu->ebx + 0x10Cu) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x110u);
    *(uint32_t*)(cpu->ebx + 0x110u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x114u);
    *(uint32_t*)(cpu->ebx + 0x114u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x118u);
    *(uint32_t*)(cpu->ebx + 0x118u) = cpu->edx;
    cpu->eax = *(uint8_t*)(cpu->ebp + 0x11Cu);
    *(uint8_t*)(cpu->ebx + 0x11Cu) = cpu->eax & 0xFFu;
    std::memmove((void*)(cpu->ebx + 0x120u),(void*)(cpu->ebp + 0x120u),40u);
    std::memmove((void*)(cpu->ebx + 0x148u),(void*)(cpu->ebp + 0x148u),40u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x170u);
    lift_push32(cpu, 0xFFFFFFFFu);
    *(uint32_t*)(cpu->ebx + 0x170u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x174u);
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0x178u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx + 0x178u;
    *(uint32_t*)(cpu->ebx + 0x174u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0CDEu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4A0CDEu));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x194u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 0x194u) = cpu->ecx;
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A0D00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0D0Eu)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4A0D0Eu));
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
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1B8u));
    *(uint8_t*)(cpu->esi + 0x1B8u) = cpu->edx & 0xFFu;
    *(float*)(cpu->esi + 0x1BCu) = (double)*(float*)(cpu->edi + 0x1BCu);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1C0u);
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1C4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A0DB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = cpu->ecx;
    cpu->edx = 0x12Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Button.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0DE4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A0DE4u));
    lift_push32(cpu, 0x1C8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0DEEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A0DEEu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_000A0E0C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0E08u)); sfera_sub_0049ED60(cpu, LIFT_CODE_TOKEN_VA(0x4A0E08u));
    cpu->esi = cpu->eax;
    goto label_000A0E0E;
    label_000A0E0C:
    cpu->esi = 0u;
    label_000A0E0E:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0E1Eu)); sfera_sub_004A0D00(cpu, LIFT_CODE_TOKEN_VA(0x4A0E1Eu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_000A0E46;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA0E46u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xA0E46u));
    label_000A0E46:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A0E60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0E68u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4A0E68u));
    cpu->eax = 0u;
    *(uint16_t*)(cpu->esi + 0x1A8u) = cpu->eax & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    std::construct_at(reinterpret_cast<SphereUI::CheckBox*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x1C0u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x50u) = 7u;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->eax;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A0ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = cpu->esp + 0x14u;
    { const uint32_t __parser_arg_016_18_0 = static_cast<uint32_t>(cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->eax;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->getBlockRange(reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_18_0))); }
    if (*(uint32_t*)(cpu->esi + 0x9Cu) != 0u) goto label_000A0F18;
    lift_push32(cpu, 0x6Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\CheckBox.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0F0Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A0F0Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0F15u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A0F15u));
    cpu->esp += 0x10u;
    label_000A0F18:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x28u);
    { const uint32_t __parser_arg_016_19_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_19_1 = static_cast<uint32_t>((uintptr_t)"checkedImage");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_19_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_19_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000A0F78;
    { const uint32_t __parser_arg_016_20_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); const uint32_t __parser_arg_016_20_1 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readQuotedString(__parser_arg_016_20_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_016_20_0))))); }
    if (cpu->eax == 0u) goto label_000A0F78;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0F4Fu)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4A0F4Fu));
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000A0F78;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s) -> Can't find sprite '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0F6Du)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A0F6Du));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0F73u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A0F73u));
    cpu->esp += 0x10u;
    goto label_000A0F7C;
    label_000A0F78:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    label_000A0F7C:
    { const uint32_t __parser_arg_016_21_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_21_1 = static_cast<uint32_t>((uintptr_t)"focusedImage");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_21_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_21_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000A0FD2;
    { const uint32_t __parser_arg_016_22_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); const uint32_t __parser_arg_016_22_1 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readQuotedString(__parser_arg_016_22_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_016_22_0))))); }
    if (cpu->eax == 0u) goto label_000A0FD2;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0FAFu)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4A0FAFu));
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    if (cpu->eax != 0u) goto label_000A0FD2;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s) -> Can't find sprite '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0FC9u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A0FC9u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A0FCFu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A0FCFu));
    cpu->esp += 0x10u;
    label_000A0FD2:
    { const uint32_t __parser_arg_016_23_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_23_1 = static_cast<uint32_t>((uintptr_t)"uncheckedImage");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_23_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_23_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000A1028;
    { const uint32_t __parser_arg_016_24_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); const uint32_t __parser_arg_016_24_1 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readQuotedString(__parser_arg_016_24_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_016_24_0))))); }
    if (cpu->eax == 0u) goto label_000A1028;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1005u)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4A1005u));
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000A1028;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s) -> Can't find sprite '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A101Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A101Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1025u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A1025u));
    cpu->esp += 0x10u;
    label_000A1028:
    { const uint32_t __parser_arg_016_25_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_25_1 = static_cast<uint32_t>((uintptr_t)"checkfocusImage");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_25_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_25_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000A107E;
    { const uint32_t __parser_arg_016_26_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); const uint32_t __parser_arg_016_26_1 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readQuotedString(__parser_arg_016_26_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_016_26_0))))); }
    if (cpu->eax == 0u) goto label_000A107E;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A105Bu)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4A105Bu));
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000A107E;
    lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s) -> Can't find sprite '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1075u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A1075u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A107Bu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A107Bu));
    cpu->esp += 0x10u;
    label_000A107E:
    { const uint32_t __parser_arg_016_27_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_27_1 = static_cast<uint32_t>((uintptr_t)"imageOffset");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_27_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_27_0))) ? 1u : 0u; }
    cpu->ebx = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_000A10CE;
    cpu->edx = cpu->esi + 0x1B0u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x1ACu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xA10ACu));
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000A10CE;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s) -> Invalid params in 'imageOffset'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A10C5u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A10C5u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A10CBu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A10CBu));
    cpu->esp += 0xCu;
    label_000A10CE:
    { const uint32_t __parser_arg_016_28_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_28_1 = static_cast<uint32_t>((uintptr_t)"textOffset");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_28_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_28_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000A1118;
    cpu->eax = cpu->esi + 0x1BCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1B8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xA10F6u));
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000A1118;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s) -> Invalid params in 'textOffset'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A110Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A110Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1115u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A1115u));
    cpu->esp += 0xCu;
    label_000A1118:
    { const uint32_t __parser_arg_016_29_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_29_1 = static_cast<uint32_t>((uintptr_t)"focuscolor");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_29_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_29_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000A118F;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xA1141u));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000A116B;
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"CheckBox::LoadUI(%s,%d,%d) -> Not enough args in 'focuscolor'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1162u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A1162u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1168u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A1168u));
    cpu->esp += 0x14u;
    label_000A116B:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint8_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x10u);
    cpu->edx|=0xFFFFFF00u;
    cpu->edx <<= 8u;
    cpu->edx|=cpu->eax;
    cpu->edx <<= 8u;
    cpu->edx |= cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->edx;
    label_000A118F:
    { const uint32_t __parser_arg_016_30_0 = static_cast<uint32_t>(cpu->ebp); const uint32_t __parser_arg_016_30_1 = static_cast<uint32_t>((uintptr_t)"buttonStyle");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_30_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_30_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000A11D8;
    cpu->ecx = cpu->edi;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->tokenCount(); }
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if ((int32_t)cpu->ebp <= 0) goto label_000A11D8;
    (void)cpu;
    label_000A11B0:
    { const uint32_t __parser_arg_016_32_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0]); const uint32_t __parser_arg_016_32_1 = static_cast<uint32_t>(cpu->ebx);
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readString(__parser_arg_016_32_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_016_32_0))))); }
    if (cpu->eax == 0u) goto label_000A11D1;
    cpu->ecx = (uintptr_t)&g_sfera_ui_load_scratch_runtime.checkbox_value[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A11CBu)); sfera_sub_0049ECD0(cpu, LIFT_CODE_TOKEN_VA(0x4A11CBu));
    *(uint32_t*)(cpu->esi + 0x1B4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1B4u)) | (uint64_t)(cpu->eax);
    label_000A11D1:
    cpu->ebx += 2u;
    if ((int32_t)cpu->ebx < (int32_t)cpu->ebp) goto label_000A11B0;
    label_000A11D8:
    cpu->edx = cpu->esp + 0x14u;
    { const uint32_t __parser_arg_016_33_0 = static_cast<uint32_t>(cpu->edx);
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->setBlockRange(reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_33_0))); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A1200(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ecx = 0u;
    cpu->edx = 0u;
    if (cpu->edi == 0u) goto label_000A1244;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    if (cpu->ecx == 0u) goto label_000A1236;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA1236u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xA1236u));
    label_000A1236:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 8u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0xCu);
    label_000A1244:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->edx < (int32_t)cpu->eax) goto label_000A129A;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ebp += cpu->eax;
    sub_pred[0] = (int32_t)(cpu->edx) < (int32_t)(cpu->ebp);
    cpu->ebp = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000A129A;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_000A129A;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)cpu->eax >= (int32_t)cpu->edx) goto label_000A129A;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    if (*(uint8_t*)(cpu->esi + 0x1A9u) != 0u) goto label_000A1284;
    *(uint8_t*)(cpu->esi + 0x1A9u) = cpu->eax & 0xFFu;
    label_000A1284:
    if ((uint8_t)((*(uint8_t*)(cpu->edi + 0xCu)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000A12AA;
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::CheckBox*>(cpu->esi)->playClickSound(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A129A:
    if (*(uint8_t*)(cpu->esi + 0x1A9u) == 0u) goto label_000A12AA;
    *(uint8_t*)(cpu->esi + 0x1A9u) = 0u;
    label_000A12AA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A12C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == 0x3EBu;
    if (cpu->eax > 0x3EBu) goto label_000A131C;
    if (sub_pred[0]) goto label_000A130B;
    if (cpu->eax == 0x70u) goto label_000A12F0;
    if (cpu->eax != 0x3EAu) goto label_000A1323;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((cpu->edx!=0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->ecx + 0x1A8u) = cpu->eax & 0xFFu;
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A12F0:
    if (cpu->edx != 0u) goto label_000A1323;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ecx + 0x1A8u) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1307u)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_VA(0x4A1307u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A130B:
    cpu->ecx = *(uint8_t*)(cpu->ecx + 0x1A8u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A131C:
    if (cpu->eax == 0x3ECu) goto label_000A1334;
    label_000A1323:
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1330u)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_VA(0x4A1330u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A1334:
    reinterpret_cast<SphereUI::CheckBox*>(cpu->ecx)->playClickSound(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A1350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xD8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 0x1A8u) == 0u);
    *(uint8_t*)(cpu->eax + 0x1A8u) = cpu->ecx & 0xFFu;
    cpu->ecx = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x9Cu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0xCu) = 0x3E9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1395u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4A1395u));
    if (g_sfera_interface_runtime.sounds_enabled == 0u) goto label_000A13AA;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"Sounds\\in_click.wav";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA13AAu)); sfera_sub_00498060(cpu, LIFT_CODE_TOKEN_RVA(0xA13AAu));
    label_000A13AA:
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A13C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A13C8u)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4A13C8u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000A13D8;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A13D5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A13D5u));
    cpu->esp += 4u;
    label_000A13D8:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A13E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000A1685;
    if (((*(uint8_t*)(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000A1685;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ebx = 0u;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == cpu->ebx) goto label_000A143B;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebx;
    if (cpu->ecx == cpu->ebx) goto label_000A142D;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA142Du)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xA142Du));
    label_000A142D:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0xCu);
    label_000A143B:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0xCu) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    if (*(uint8_t*)(cpu->esi + 0x1A9u) == (cpu->ebx & 0xFFu)) goto label_000A14FD;
    if (*(uint8_t*)(cpu->esi + 0x1A8u) == (cpu->ebx & 0xFFu)) goto label_000A1483;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A4u);
    if (cpu->ecx != cpu->ebx) goto label_000A1497;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    goto label_000A1493;
    label_000A1483:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    if (cpu->ecx != cpu->ebx) goto label_000A1497;
    label_000A148D:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    label_000A1493:
    if (cpu->ecx == cpu->ebx) goto label_000A14E4;
    label_000A1497:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->eax <<= 24u;
    cpu->eax |= 0xFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1B0u))));
    cpu->esp -= 8u;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 0x20u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1ACu)))))) + (((double)*(float*)(cpu->esp + 0x18u))));
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA14E4u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_RVA(0xA14E4u));
    label_000A14E4:
    if (*(uint32_t*)(cpu->esi + 0x64u) <= cpu->ebx) goto label_000A1683;
    if (*(uint8_t*)(cpu->esi + 0x1A9u) == (cpu->ebx & 0xFFu)) goto label_000A150D;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C0u);
    goto label_000A1513;
    label_000A14FD:
    if (*(uint8_t*)(cpu->esi + 0x1A8u) == (cpu->ebx & 0xFFu)) goto label_000A148D;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    goto label_000A1493;
    label_000A150D:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    label_000A1513:
    if (*(uint8_t*)(cpu->esi + 0x49u) == (cpu->ebx & 0xFFu)) goto label_000A151E;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x98u);
    label_000A151E:
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0xDCu);
    x87_v1 = x87_v0;
    cpu->eax&=0xFFFFFFu;
    cpu->ebp = cpu->ebp << 24u;
    cpu->ebp |= cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    g_sfera_screen_clip_runtime.left = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    g_sfera_screen_clip_runtime.top = cpu->eax;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x28u))));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    if ((int32_t)cpu->edx >= 0) goto label_000A155F;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_000A155F:
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    g_sfera_screen_clip_runtime.right = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu))));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    if ((int32_t)cpu->eax >= 0) goto label_000A157D;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000A157D:
    x87_v0 = x87_v0 + x87_v1; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    g_sfera_screen_clip_runtime.bottom = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->ebx = 0x10u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x1B4u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_000A15FB;
    cpu->eax = cpu->esi + 0x54u;
    if (*(uint32_t*)(cpu->esi + 0x68u) < cpu->ebx) goto label_000A15B4;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000A15B4:
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Du);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A15D4u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4A15D4u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->ecx >= cpu->eax) goto label_000A15E7;
    cpu->eax -= cpu->ecx;
    cpu->eax >>= 1u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    label_000A15E7:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->ecx >= cpu->eax) goto label_000A15FB;
    cpu->eax -= cpu->ecx;
    --cpu->eax;
    cpu->eax >>= 1u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    label_000A15FB:
    cpu->edi = 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0xDCu) != cpu->edi) goto label_000A1618;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000A1618;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA1618u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xA1618u));
    label_000A1618:
    cpu->eax = cpu->esi + 0x54u;
    if (*(uint32_t*)(cpu->esi + 0x68u) < cpu->ebx) goto label_000A1622;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000A1622:
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    x87_v0 = 0.0;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Du);
    *(float*)(cpu->esp) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x24u)));
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->ebx = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u))));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x2Cu)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1661u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4A1661u));
    cpu->ebp = lift_pop32(cpu);
    if (*(uint32_t*)(cpu->esi + 0xDCu) != cpu->edi) goto label_000A1683;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000A1683;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    sfera_sub_004CE0E0(cpu, stop_address); return;
    label_000A1683:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000A1685:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A1690(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A169Eu)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4A169Eu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x198u);
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1A0u);
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1A4u);
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1A8u));
    *(uint8_t*)(cpu->esi + 0x1A8u) = cpu->ecx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1A9u));
    *(uint8_t*)(cpu->esi + 0x1A9u) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1ACu);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B0u);
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1B4u);
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1B8u);
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1BCu);
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1C0u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->edx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A1740(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = cpu->ecx;
    cpu->edx = 0x11Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\CheckBox.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1774u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A1774u));
    lift_push32(cpu, 0x1C8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A177Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A177Eu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_000A179C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1798u)); sfera_sub_004A0E60(cpu, LIFT_CODE_TOKEN_VA(0x4A1798u));
    cpu->esi = cpu->eax;
    goto label_000A179E;
    label_000A179C:
    cpu->esi = 0u;
    label_000A179E:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A17AEu)); sfera_sub_004A1690(cpu, LIFT_CODE_TOKEN_VA(0x4A17AEu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_000A17D6;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA17D6u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xA17D6u));
    label_000A17D6:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A17F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    x87_v0 = 0.0;
    cpu->eax = cpu->ecx;
    *(uint16_t*)(cpu->eax) = 1u;
    *(uint8_t*)(cpu->eax + 8u) = 0xFFu;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    *(float*)(cpu->eax + 0x1Cu) = x87_v0;
    x87_v1 = 1.0;
    cpu->edx |= 0xFFFFFFFFu;
    *(float*)(cpu->eax + 0x20u) = x87_v1;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->edx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->eax + 0x28u) = cpu->ecx;
    *(float*)(cpu->eax + 0x3Cu) = x87_v1;
    *(uint32_t*)(cpu->eax + 0x44u) = cpu->edx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->eax + 0x48u) = cpu->ecx;
    *(float*)(cpu->eax + 0x40u) = x87_v1;
    *(uint32_t*)(cpu->eax + 0x64u) = cpu->edx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->eax + 0x68u) = cpu->ecx;
    *(float*)(cpu->eax + 0x5Cu) = x87_v1;
    *(uint32_t*)(cpu->eax + 0x84u) = cpu->edx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->eax + 0x88u) = cpu->ecx;
    *(float*)(cpu->eax + 0x60u) = x87_v1;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + 0x7Cu) = x87_v1; 
    *(float*)(cpu->eax + 0x80u) = x87_v0; 
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A1860(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 4u) == 0u) goto label_000A188B;
    cpu->edx = 0x68u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1878u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A1878u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1881u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A1881u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    label_000A188B:
    if (*(uint32_t*)(cpu->esi + 0xCu) == 0u) goto label_000A18B3;
    cpu->edx = 0x6Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A18A0u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A18A0u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A18A9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A18A9u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0xCu) = 0u;
    label_000A18B3:
    if (*(uint32_t*)(cpu->esi + 0x10u) == 0u) goto label_000A18DB;
    cpu->edx = 0x74u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A18C8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A18C8u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A18D1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A18D1u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    label_000A18DB:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A18E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 4u) == 0u) goto label_000A190B;
    cpu->edx = 0x81u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A18F8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A18F8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1901u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A1901u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    label_000A190B:
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0x88u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A191Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A191Bu));
    lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1922u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A1922u));
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edi = 0u;
    label_000A1940:
    cpu->ecx = sfera_cursor_texture_name(cpu->edi >> 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A194Bu)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x4A194Bu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edi + cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->edi + cpu->edx) != 0xFFFFFFFFu) goto label_000A1974;
    cpu->eax = sfera_cursor_texture_name(cpu->edi >> 2u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Cursor texture '%s' not found");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A196Bu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A196Bu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1971u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A1971u));
    cpu->esp += 0xCu;
    label_000A1974:
    cpu->edi += 4u;
    if (cpu->edi < 0x10u) goto label_000A1940;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0xCu) == 0u;
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000A19A6;
    cpu->edx = 0x97u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1996u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A1996u));
    lift_push32(cpu, 0x114u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A19A0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A19A0u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    label_000A19A6:
    if (*(uint32_t*)(cpu->esi + 0x10u) != 0u) goto label_000A19CB;
    cpu->edx = 0x9Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A19BBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A19BBu));
    lift_push32(cpu, 0x114u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A19C5u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A19C5u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    label_000A19CB:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, 0x114u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A19D6u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, 0x114u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A19E6u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->ecx + 0x64u) = 0xFFFFFFFFu;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->esp += 0x18u;
    *(uint32_t*)(cpu->edx + 0xC0u) = 0xFFFFFFFFu;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A1A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x5Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esi + cpu->eax) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->eax + cpu->esi + 4u) = cpu->edx;
    if (cpu->ecx != 0u) goto label_000A1A5B;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_000A1A60;
    label_000A1A5B:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA1A60u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_RVA(0xA1A60u));
    label_000A1A60:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xCu);
    *(uint32_t*)(cpu->ecx + cpu->esi + 8u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->edi + 0xCu);
    if (*(uint32_t*)(cpu->edx + cpu->esi + 8u) == 0xFFFFFFFFu) goto label_000A1AA7;
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->esi + 8u);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1A7Eu)); sfera_sub_0044FC60(cpu, LIFT_CODE_TOKEN_VA(0x4A1A7Eu));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx + cpu->esi + 0x54u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + cpu->esi + 0x58u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000A1AA7:
    cpu->eax = 0x20u;
    *(uint32_t*)(cpu->edx + cpu->esi + 0x54u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xCu);
    *(uint32_t*)(cpu->ecx + cpu->esi + 0x58u) = cpu->eax;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A1AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x5Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->edx + cpu->eax + 0x54u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx + cpu->eax + 0x58u) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A1B00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x5Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->edx + cpu->esi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->ecx + cpu->esi + 0x4Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax + cpu->esi + 0x50u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax != 0u) goto label_000A1B4A;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->edx + cpu->esi + 0xCu) = cpu->eax & 0xFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
    label_000A1B4A:
    lift_push32(cpu, 0x3Fu); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = cpu->eax + cpu->esi + 0xCu;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4A1B55u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->edx + cpu->esi + 0x4Bu) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A1B70(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi) == 0u) goto label_000A1DA2;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1B8Cu)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x4A1B8Cu));
    if (*(uint8_t*)(cpu->esi + 1u) == 0u) goto label_000A1BAC;
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v1 = 16.0;
    x87_v0 = (x87_v0) - (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0xCu) = x87_v1; 
    x87_v0 = (((double)*(float*)(cpu->esp + 0x10u))) - (x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    label_000A1BAC:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 8u));
    if ((cpu->eax & 0xFFu) == 0xFFu) goto label_000A1C6C;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = cpu->eax & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    if (cpu->ecx == 0u) goto label_000A1C6C;
    cpu->edx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1BD2u)); sfera_sub_0044FCB0(cpu, LIFT_CODE_TOKEN_VA(0x4A1BD2u));
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v1 = 0.5;
    cpu->eax = cpu->esi + 0x14u;
    x87_v0 = (x87_v0) - (x87_v1);
    lift_push32(cpu, 0x20u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 2u);
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    lift_push32(cpu, 6u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->eax) = x87_v1;
    x87_v2 = (double)*(float*)(cpu->esp + 0x20u);
    x87_v0 = x87_v2 - x87_v0; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esi + 0x18u) = x87_v1;
    x87_v2 = 0.0;
    *(float*)(cpu->esi + 0x2Cu) = x87_v2;
    *(float*)(cpu->esi + 0x30u) = x87_v2;
    x87_v3 = x87_v0;
    x87_v4 = 32.0;
    x87_v3 = (x87_v3) + (x87_v4);
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x14u) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esi + 0x34u) = x87_v4;
    { double temporary = x87_v4; x87_v4 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esi + 0x38u) = x87_v4;
    x87_v5 = 1.0;
    *(float*)(cpu->esi + 0x4Cu) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esi + 0x50u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esi + 0x54u) = x87_v5; 
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)(cpu->esp + 0x14u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esi + 0x58u) = x87_v3;
    *(float*)(cpu->esi + 0x78u) = x87_v3; 
    *(float*)(cpu->esi + 0x6Cu) = x87_v2;
    *(float*)(cpu->esi + 0x70u) = x87_v2;
    *(float*)(cpu->esi + 0x90u) = x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esi + 0x74u) = x87_v1; 
    *(float*)(cpu->esi + 0x8Cu) = x87_v0; 
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA1C6Cu)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_RVA(0xA1C6Cu));
    label_000A1C6C:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    label_000A1C71:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->edi + cpu->edx + 8u);
    if (cpu->ecx == 0xFFFFFFFFu) goto label_000A1D36;
    cpu->edx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1C8Bu)); sfera_sub_0044FCB0(cpu, LIFT_CODE_TOKEN_VA(0x4A1C8Bu));
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    x87_v1 = 0.5;
    x87_v0 = (x87_v0) - (x87_v1);
    cpu->eax += cpu->edi;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->eax))));
    cpu->ecx = cpu->esi + 0x14u;
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->ecx) = x87_v1; 
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 4u))));
    x87_v2 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v0 = x87_v2 - x87_v0; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esi + 0x18u) = x87_v0; 
    x87_v0 = 0.0;
    *(float*)(cpu->esi + 0x2Cu) = x87_v0;
    *(float*)(cpu->esi + 0x30u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x54u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0x54u))));
    if ((int32_t)cpu->edx >= 0) goto label_000A1CCD;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000A1CCD:
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->ecx)));
    *(float*)(cpu->esi + 0x34u) = x87_v1; 
    *(float*)(cpu->esi + 0x38u) = (double)*(float*)(cpu->esi + 0x18u);
    x87_v1 = 1.0;
    *(float*)(cpu->esi + 0x4Cu) = x87_v1;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esi + 0x50u) = x87_v1;
    *(float*)(cpu->esi + 0x54u) = (double)*(float*)(cpu->esi + 0x34u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x58u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    if ((int32_t)cpu->eax >= 0) goto label_000A1CFD;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_000A1CFD:
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esi + 0x18u)));
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 2u);
    *(float*)(cpu->esi + 0x58u) = x87_v2; 
    lift_push32(cpu, 6u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esi + 0x6Cu) = x87_v1;
    *(float*)(cpu->esi + 0x70u) = x87_v1;
    *(float*)(cpu->esi + 0x74u) = (double)*(float*)(cpu->ecx);
    *(float*)(cpu->esi + 0x78u) = (double)*(float*)(cpu->esi + 0x58u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esi + 0x8Cu) = x87_v1; 
    *(float*)(cpu->esi + 0x90u) = x87_v0; 
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA1D36u)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_RVA(0xA1D36u));
    label_000A1D36:
    cpu->edi += 0x5Cu;
    if (cpu->edi < 0x114u) goto label_000A1C71;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1D50u)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_VA(0x4A1D50u));
    cpu->ebx = 0u;
    label_000A1D52:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = cpu->ebx + cpu->ecx;
    cpu->eax = cpu->edi + 0xCu;
    if (*(uint8_t*)(cpu->edi + 0xCu) == 0u) goto label_000A1D94;
    x87_v0 = 0.0;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->edi + 4u))));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x50u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x2Cu)));
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->edi))));
    cpu->ebp = cpu->eax;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x2Cu)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA1D94u)); sfera_sub_0044D190(cpu, LIFT_CODE_TOKEN_RVA(0xA1D94u));
    label_000A1D94:
    cpu->ebx += 0x5Cu;
    if (cpu->ebx < 0x114u) goto label_000A1D52;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000A1DA2:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A1DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(g_sfera_interface_runtime.description_window) != cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A1DF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    std::construct_at(reinterpret_cast<SphereUI::CDescriptionWindow*>(cpu->esi));
    g_sfera_interface_runtime.description_window = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1E08u)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4A1E08u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000A1E18;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1E15u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A1E15u));
    cpu->esp += 4u;
    label_000A1E18:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A1E20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1E31u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4A1E31u));
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1E55u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4A1E55u));
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->cursorKind(cpu);
    if (cpu->eax >= 4u) goto label_000A1E80;
    cpu->ecx = sfera_cursor_texture_name(cpu->eax);
    if (*(uint8_t*)(cpu->ecx) == 0x5Fu) goto label_000A1E80;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1E74u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4A1E74u));
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->ebx = cpu->eax;
    cpu->ebx = (int32_t)(cpu->ebx) >> 1u;
    goto label_000A1E82;
    label_000A1E80:
    cpu->ebx = 0u;
    label_000A1E82:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1E87u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4A1E87u));
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->cursorKind(cpu);
    if (cpu->eax >= 4u) goto label_000A1EB0;
    cpu->ecx = sfera_cursor_texture_name(cpu->eax);
    if (*(uint8_t*)(cpu->ecx) == 0x5Fu) goto label_000A1EB0;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1EA6u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4A1EA6u));
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    goto label_000A1EB8;
    label_000A1EB0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1EB5u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4A1EB5u));
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    label_000A1EB8:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = g_sfera_graphics_runtime.display_width;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx + cpu->edx;
    cpu->ebp += cpu->eax;
    if ((int32_t)cpu->ebp > (int32_t)cpu->edi) goto label_000A1ED3;
    *(uint32_t*)(cpu->esi) = (uint64_t)(*(uint32_t*)(cpu->esi)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    goto label_000A1EE3;
    label_000A1ED3:
    cpu->edx -= cpu->ecx;
    if ((int32_t)(cpu->edx -= cpu->ebx) < 0) goto label_000A1EDF;
    cpu->ecx += cpu->ebx;
    *(uint32_t*)(cpu->esi) = (uint64_t)(*(uint32_t*)(cpu->esi)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u);
    goto label_000A1EE3;
    label_000A1EDF:
    cpu->edi -= cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    label_000A1EE3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1EE8u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4A1EE8u));
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->cursorKind(cpu);
    if (cpu->eax >= 4u) goto label_000A1F13;
    cpu->ecx = sfera_cursor_texture_name(cpu->eax);
    if (*(uint8_t*)(cpu->ecx) == 0x5Fu) goto label_000A1F13;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1F07u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4A1F07u));
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->ebx = cpu->eax;
    cpu->ebx = (int32_t)(cpu->ebx) >> 1u;
    goto label_000A1F15;
    label_000A1F13:
    cpu->ebx = 0u;
    label_000A1F15:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1F1Au)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4A1F1Au));
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->cursorKind(cpu);
    if (cpu->eax >= 4u) goto label_000A1F43;
    cpu->ecx = sfera_cursor_texture_name(cpu->eax);
    if (*(uint8_t*)(cpu->ecx) == 0x5Fu) goto label_000A1F43;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1F39u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4A1F39u));
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    goto label_000A1F4B;
    label_000A1F43:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1F48u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4A1F48u));
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    label_000A1F4B:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = g_sfera_graphics_runtime.display_height;
    cpu->ebp = cpu->ecx + cpu->edx;
    cpu->ebp += cpu->eax;
    sub_pred[0] = cpu->ebp == cpu->edi; sub_pred[1] = (int32_t)(cpu->ebp) < (int32_t)(cpu->edi);
    cpu->ebp = lift_pop32(cpu);
    if ((!sub_pred[0]) && (!sub_pred[1])) goto label_000A1F74;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A1F74:
    cpu->edx -= cpu->ecx;
    if ((int32_t)(cpu->edx -= cpu->ebx) < 0) goto label_000A1F8A;
    cpu->ecx += cpu->ebx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A1F8A:
    cpu->edi -= cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A1FA0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    goto label_000A1FA0;
    label_000A1DC0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x19Cu) = 0u;
    *(uint32_t*)(cpu->esi + 0x1A0u) = 0u;
    *(uint8_t*)(cpu->esi + 0x48u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1DE0u)); sfera_sub_004D2870(cpu, LIFT_CODE_TOKEN_VA(0x4A1DE0u));
    *(uint8_t*)(cpu->esi + 0x4Au) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A1FA0:
    sub_pred[0] = (uint32_t)(g_sfera_interface_runtime.description_auto_popup) == 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (!sub_pred[0]) goto label_000A1FCD;
    if (*(uint8_t*)(cpu->esi + 0x1C0u) != 0u) goto label_000A1FCD;
    if (g_sfera_direct_input_runtime.keyboard_state[0x2A] != 0u) goto label_000A1FFB;
    if (g_sfera_direct_input_runtime.keyboard_state[0x36] != 0u) goto label_000A1FFB;
    cpu->esi = lift_pop32(cpu);
    goto label_000A1DC0;
    label_000A1FCD:
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000A1FFB;
    if (g_sfera_direct_input_runtime.keyboard_state[0x2A] != 0u) goto label_000A1FFB;
    if (g_sfera_direct_input_runtime.keyboard_state[0x36] != 0u) goto label_000A1FFB;
    lift_native_call(cpu, native_function_address32(&::GetTickCount), LIFT_CODE_TOKEN_VA(0x4A1FE5u));
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0x1A8u)) goto label_000A1FFB;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    goto label_000A1DC0;
    label_000A1FFB:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A2000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->eax == 0x64u) goto label_000A2019;
    if (cpu->eax != 0x3E9u) goto label_000A2033;
    if (*(uint32_t*)(cpu->edx + 4u) != 2u) goto label_000A2033;
    label_000A2019:
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x48u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2030u)); sfera_sub_004D2870(cpu, LIFT_CODE_TOKEN_VA(0x4A2030u));
    *(uint8_t*)(cpu->esi + 0x4Au) = cpu->ebx & 0xFFu;
    label_000A2033:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A2040(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->ecx = (uintptr_t)"objdesc2";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2074u)); sfera_sub_004B9850(cpu, LIFT_CODE_TOKEN_VA(0x4A2074u));
    cpu->edi = cpu->eax;
    cpu->ebx = 0u;
    if (cpu->edi != cpu->ebx) goto label_000A2094;
    lift_push32(cpu, (uintptr_t)"objdesc2"); lift_push32(cpu, (uintptr_t)"SphereUI::FindTemplateWindowGuaranteed(): failed to find window \"%s\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A208Bu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A208Bu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2091u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A2091u));
    cpu->esp += 0xCu;
    label_000A2094:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A209Cu)); sfera_sub_004D51A0(cpu, LIFT_CODE_TOKEN_VA(0x4A209Cu));
    lift_push32(cpu, (uintptr_t)"window_caption");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    std::construct_at(reinterpret_cast<SphereUI::CDescriptionWindow*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A20CAu)); sfera_sub_004D2560(cpu, LIFT_CODE_TOKEN_VA(0x4A20CAu));
    cpu->edi = cpu->eax;
    if (cpu->edi != cpu->ebx) goto label_000A20E8;
    lift_push32(cpu, (uintptr_t)"window_caption"); lift_push32(cpu, (uintptr_t)"SphereUI::CDescriptionWindow::FindSpriteGuaranteed(): failed to find sprite \"%s\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A20DFu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A20DFu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A20E5u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A20E5u));
    cpu->esp += 0xCu;
    label_000A20E8:
    lift_push32(cpu, (uintptr_t)"window_bottom");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A20FAu)); sfera_sub_004D2560(cpu, LIFT_CODE_TOKEN_VA(0x4A20FAu));
    cpu->edi = cpu->eax;
    if (cpu->edi != cpu->ebx) goto label_000A2118;
    lift_push32(cpu, (uintptr_t)"window_bottom"); lift_push32(cpu, (uintptr_t)"SphereUI::CDescriptionWindow::FindSpriteGuaranteed(): failed to find sprite \"%s\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A210Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A210Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2115u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A2115u));
    cpu->esp += 0xCu;
    label_000A2118:
    lift_push32(cpu, (uintptr_t)"window_left");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A212Au)); sfera_sub_004D2560(cpu, LIFT_CODE_TOKEN_VA(0x4A212Au));
    cpu->edi = cpu->eax;
    if (cpu->edi != cpu->ebx) goto label_000A2148;
    lift_push32(cpu, (uintptr_t)"window_left"); lift_push32(cpu, (uintptr_t)"SphereUI::CDescriptionWindow::FindSpriteGuaranteed(): failed to find sprite \"%s\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A213Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A213Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2145u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A2145u));
    cpu->esp += 0xCu;
    label_000A2148:
    lift_push32(cpu, (uintptr_t)"window_right");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A215Au)); sfera_sub_004D2560(cpu, LIFT_CODE_TOKEN_VA(0x4A215Au));
    cpu->edi = cpu->eax;
    if (cpu->edi != cpu->ebx) goto label_000A2178;
    lift_push32(cpu, (uintptr_t)"window_right"); lift_push32(cpu, (uintptr_t)"SphereUI::CDescriptionWindow::FindSpriteGuaranteed(): failed to find sprite \"%s\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A216Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A216Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2175u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A2175u));
    cpu->esp += 0xCu;
    label_000A2178:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edi != cpu->ebx) goto label_000A21A2;
    lift_push32(cpu, 1u); lift_push32(cpu, (uintptr_t)"SphereUI::CDescriptionWindow::CDescriptionWindow(): failed to find control #%u");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2199u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A2199u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A219Fu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A219Fu));
    cpu->esp += 0xCu;
    label_000A21A2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ecx -= *(uint32_t*)(cpu->edi + 0x2Cu);
    *(uint32_t*)(cpu->esi + 0xF8u) = LIFT_CALLBACK(sfera_sub_004A2000);
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->ecx;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x48u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A21CFu)); sfera_sub_004D2870(cpu, LIFT_CODE_TOKEN_VA(0x4A21CFu));
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi + 0x4Au) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A21D9u)); sfera_sub_004BA870(cpu, LIFT_CODE_TOKEN_VA(0x4A21D9u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A21F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = g_sfera_interface_runtime.description_window;
    if (cpu->eax != 0u) goto label_000A2269;
    cpu->edx = 0x87u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\DescriptionWindow.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2229u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A2229u));
    lift_push32(cpu, 0x1C8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2233u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A2233u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (cpu->eax == 0u) goto label_000A2262;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A224Du)); sfera_sub_004A2040(cpu, LIFT_CODE_TOKEN_VA(0x4A224Du));
    g_sfera_interface_runtime.description_window = cpu->eax;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A2262:
    cpu->eax = 0u;
    g_sfera_interface_runtime.description_window = cpu->eax;
    label_000A2269:
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A2280(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0u;
    if (*(uint8_t*)(cpu->esi + 0x48u) != (uint8_t)(cpu->edx)) goto label_000A2667;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1ACu);
    cpu->eax <<= 24u;
    cpu->eax|=0xFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->eax <<= 24u;
    cpu->eax|=0xFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B4u);
    cpu->eax <<= 24u;
    cpu->eax|=0xFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B8u);
    cpu->eax <<= 24u;
    cpu->eax |= 0xFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    if (cpu->ecx == cpu->edx) goto label_000A2332;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA2332u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xA2332u));
    label_000A2332:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ebx += *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B4u);
    lift_push32(cpu, cpu->ebp);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->edi);
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    x87_v1 = 0.5;
    cpu->ecx = cpu->edi;
    x87_v0 = (x87_v0) - (x87_v1);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u))));
    if ((int32_t)cpu->ecx >= 0) goto label_000A2386;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_000A2386:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1ACu);
    x87_v1 = x87_v1 + x87_v2; 
    cpu->ebp = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax = cpu->ebp;
    *(float*)(cpu->esp + 0x24u) = x87_v1; 
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu))));
    x87_v0 = (((double)*(float*)(cpu->esp + 0x14u))) - (x87_v0);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    if (((cpu->eax)&0x80000000u)==0u) goto label_000A23BD;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000A23BD:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xDCu);
    x87_v0 = x87_v0 + x87_v1; 
    cpu->ecx *= 0xA6u;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu))));
    cpu->edx = (uint32_t)(((uint64_t)0x80808081u * (uint32_t)(cpu->ecx)) >> 32u);
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ecx >>= 7u;
    cpu->ecx <<= 24u;
    cpu->ecx |= 0x282420u;
    if ((int32_t)cpu->edx >= 0) goto label_000A23F4;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000A23F4:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu))));
    if ((int32_t)(cpu->edx) >= 0) goto label_000A240F;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000A240F:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    x87_v0 = x87_v0 - x87_v1; 
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x30u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x30u) = x87_v1; 
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0x30u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x28u))));
    if ((int32_t)cpu->eax >= 0) goto label_000A2442;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000A2442:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1B8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u))));
    if ((int32_t)(cpu->eax) >= 0) goto label_000A245D;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_000A245D:
    x87_v1 = x87_v1 - x87_v2; 
    *(float*)(cpu->esp + 0x30u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x30u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x34u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x34u) = x87_v2; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 0x34u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_v1; 
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A248Bu)); sfera_sub_004CEB70(cpu, LIFT_CODE_TOKEN_VA(0x4A248Bu));
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1ACu);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A24A8u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_VA(0x4A24A8u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx -= *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u))));
    if ((int32_t)(cpu->edx) >= 0) goto label_000A24C6;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000A24C6:
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A24D9u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_VA(0x4A24D9u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B4u);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ebp -= *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1ACu);
    cpu->ebp -= *(uint32_t*)(cpu->eax + 8u);
    cpu->edi = *(uint32_t*)(cpu->edx + 8u);
    if ((int32_t)cpu->edi > (int32_t)cpu->ebp) goto label_000A2566;
    label_000A2500:
    cpu->eax = cpu->edi + cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u))));
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2526u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_VA(0x4A2526u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B8u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx -= *(uint32_t*)(cpu->ecx + 4u);
    cpu->esp -= 8u;
    cpu->edx += *(uint32_t*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu))));
    if ((int32_t)(cpu->edx) >= 0) goto label_000A2551;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000A2551:
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2559u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_VA(0x4A2559u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B4u);
    cpu->edi += *(uint32_t*)(cpu->ecx + 8u);
    if ((int32_t)cpu->edi <= (int32_t)cpu->ebp) goto label_000A2500;
    label_000A2566:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax -= *(uint32_t*)(cpu->ecx + 8u);
    if ((int32_t)cpu->edi >= (int32_t)cpu->eax) goto label_000A2644;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B4u);
    cpu->edi += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u))));
    cpu->eax += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u))));
    if ((int32_t)(cpu->eax) >= 0) goto label_000A25A0;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000A25A0:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp -= 0x10u;
    cpu->edx += cpu->edi;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u))));
    if ((int32_t)(cpu->edx) >= 0) goto label_000A25C0;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000A25C0:
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A25D8u)); sfera_sub_004CE2B0(cpu, LIFT_CODE_TOKEN_VA(0x4A25D8u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ebp -= *(uint32_t*)(cpu->edx + 8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B8u);
    cpu->ebp += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u))));
    if ((int32_t)(cpu->ebp) >= 0) goto label_000A25FF;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000A25FF:
    cpu->edx = cpu->eax + cpu->edi;
    cpu->esp -= 0x10u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u))));
    if ((int32_t)cpu->edx >= 0) goto label_000A261B;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000A261B:
    cpu->eax -= *(uint32_t*)(cpu->ecx + 4u);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    cpu->eax += cpu->edi;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u))));
    if ((int32_t)(cpu->eax) >= 0) goto label_000A263C;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000A263C:
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA2644u)); sfera_sub_004CE2B0(cpu, LIFT_CODE_TOKEN_RVA(0xA2644u));
    label_000A2644:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (cpu->edi == cpu->eax) goto label_000A2664;
    label_000A2650:
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    cpu->edi = *(uint32_t*)(cpu->edi);
    if (cpu->edi != *(uint32_t*)(cpu->esi + 0xA0u)) goto label_000A2650;
    label_000A2664:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000A2667:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A2670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->edi != 0u) goto label_000A269C;
    lift_push32(cpu, 1u); lift_push32(cpu, (uintptr_t)"SphereUI::CDescriptionWindow::ShowDescription(): failed to find control #%u");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2693u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A2693u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2699u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A2699u));
    cpu->esp += 0xCu;
    label_000A269C:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = cpu->edx;
    cpu->ebx = cpu->eax + 1u;
    label_000A26A5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A26A5;
    cpu->eax -= cpu->ebx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, 0xA92u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0xA93u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1BCu);
    cpu->eax += *(uint32_t*)(cpu->edi + 0x2Cu);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A26E8u)); sfera_sub_004A1E20(cpu, LIFT_CODE_TOKEN_VA(0x4A26E8u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::GetTickCount), LIFT_CODE_TOKEN_VA(0x4A270Bu));
    cpu->eax += *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x20u));
    *(uint8_t*)(cpu->esi + 0x1C0u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x48u) = 0u;
    *(uint8_t*)(cpu->esi + 0x4Au) = 1u;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A2740(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = cpu->eax + 1u;
    label_000A2750:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A2750;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_000A2801;
    if (*(uint8_t*)(cpu->esp + 0x10u) == (cpu->ecx & 0xFFu)) goto label_000A277E;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0xFAu); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2779u)); sfera_sub_004A2670(cpu, LIFT_CODE_TOKEN_VA(0x4A2779u));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A277E:
    if (g_sfera_interface_runtime.description_auto_popup == 0u) goto label_000A2801;
    if (g_sfera_direct_input_runtime.keyboard_state[0x2A] != 0u) goto label_000A2801;
    if (g_sfera_direct_input_runtime.keyboard_state[0x36] != 0u) goto label_000A2801;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::GetTickCount);
    if (*(uint32_t*)(cpu->esi + 0x1A0u) == cpu->eax) goto label_000A27BF;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)()>(static_cast<uintptr_t>(native_function_address32(&::GetTickCount)))();
    cpu->eax += 0x1F4u;
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->eax;
    label_000A27BF:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    if (cpu->ecx == *(uint32_t*)(cpu->esi + 0x1A0u)) goto label_000A27F3;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)()>(static_cast<uintptr_t>(native_function_address32(&::GetTickCount)))();
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0x1A4u)) goto label_000A2800;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0xFAu); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A27EDu)); sfera_sub_004A2670(cpu, LIFT_CODE_TOKEN_VA(0x4A27EDu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A27F3:
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)()>(static_cast<uintptr_t>(native_function_address32(&::GetTickCount)))();
    cpu->eax += 0xFAu;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    label_000A2800:
    cpu->edi = lift_pop32(cpu);
    label_000A2801:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A2810(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2]; double x87_v0, x87_v1, x87_v2;
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if (*(uint8_t*)(cpu->esi + 0x48u) != (cpu->ebx & 0xFFu)) goto label_000A2D03;
    if (((*(uint8_t*)(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000A2D03;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == cpu->ebx) goto label_000A2876;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if (cpu->ecx == cpu->ebx) goto label_000A2868;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA2868u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xA2868u));
    label_000A2868:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    label_000A2876:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    cpu->ecx = cpu->esi + 0x54u;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    *(float*)(cpu->esp + 0x34u) = x87_v0; 
    if (*(uint8_t*)(cpu->esi + 0x1A9u) == (cpu->ebx & 0xFFu)) goto label_000A28B1;
    cpu->edx = cpu->esi + 0x1B4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    label_000A28B1:
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u); x87_v1 = x87_v0;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    x87_v1 = (double)*(float*)(cpu->esp + 0x34u);
    cpu->edi = cpu->eax;
    x87_v2 = x87_v1;
    g_sfera_screen_clip_runtime.left = cpu->edi;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    cpu->ebp = cpu->eax;
    g_sfera_screen_clip_runtime.top = cpu->ebp;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x28u))));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    if ((int32_t)cpu->eax >= 0) goto label_000A28E7;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_000A28E7:
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    g_sfera_screen_clip_runtime.right = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x2Cu))));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    if ((int32_t)cpu->ecx >= 0) goto label_000A2905;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_000A2905:
    x87_v0 = x87_v0 + x87_v1; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    g_sfera_screen_clip_runtime.bottom = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = cpu->esp + 0x58u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2961u)); sfera_sub_004D8990(cpu, LIFT_CODE_TOKEN_VA(0x4A2961u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x58u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x5Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->ecx += cpu->eax;
    cpu->edx += cpu->ebx;
    if (cpu->edi >= cpu->eax) goto label_000A297B;
    cpu->edi = cpu->eax;
    label_000A297B:
    if (cpu->ebp >= cpu->ebx) goto label_000A2981;
    cpu->ebp = cpu->ebx;
    label_000A2981:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ebx + cpu->edi;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ecx) goto label_000A2990;
    cpu->ecx -= cpu->edi;
    cpu->ebx = cpu->ecx;
    label_000A2990:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = cpu->eax + cpu->ebp;
    if ((int32_t)cpu->ecx <= (int32_t)cpu->edx) goto label_000A299F;
    cpu->edx -= cpu->ebp;
    cpu->eax = cpu->edx;
    label_000A299F:
    if ((int32_t)cpu->edi >= 0) goto label_000A29A7;
    cpu->ebx += cpu->edi;
    cpu->edi = 0u;
    label_000A29A7:
    if ((int32_t)cpu->ebp >= 0) goto label_000A29AF;
    cpu->eax += cpu->ebp;
    cpu->ebp = 0u;
    label_000A29AF:
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    cpu->edx = cpu->ebx + cpu->edi;
    if ((int32_t)cpu->edx <= (int32_t)cpu->ecx) goto label_000A29C0;
    cpu->ecx -= cpu->edi;
    cpu->ebx = cpu->ecx;
    label_000A29C0:
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    cpu->edx = cpu->eax + cpu->ebp;
    if ((int32_t)cpu->edx <= (int32_t)cpu->ecx) goto label_000A29D1;
    cpu->ecx -= cpu->ebp;
    cpu->eax = cpu->ecx;
    label_000A29D1:
    x87_v0 = 0.0;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(float*)(cpu->esp + 0x50u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    x87_v0 = 1.0;
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x58u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A29FDu)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x4A29FDu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x64u);
    if (*(uint32_t*)(cpu->esi + 0x1E8u) == cpu->eax) goto label_000A2A0E;
    *(uint32_t*)(cpu->esi + 0x1E4u) = cpu->eax;
    label_000A2A0E:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = 0x10u;
    if (*(uint32_t*)(cpu->edi + 0x14u) < cpu->ebx) goto label_000A2A20;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    goto label_000A2A22;
    label_000A2A20:
    cpu->ecx = cpu->edi;
    label_000A2A22:
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Du);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2A40u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4A2A40u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    *(uint32_t*)(cpu->esp + 0x30u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x30u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    if (*(uint32_t*)(cpu->edi + 0x14u) < cpu->ebx) goto label_000A2A5D;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    goto label_000A2A5F;
    label_000A2A5D:
    cpu->ecx = cpu->edi;
    label_000A2A5F:
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    cpu->eax = cpu->esp + 0x18u;
    cpu->edx -= 2u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1E4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2A7Fu)); sfera_sub_004A5330(cpu, LIFT_CODE_TOKEN_VA(0x4A2A7Fu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    if (cpu->ecx <= cpu->eax) goto label_000A2ABB;
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx ^= cpu->edx;
    cpu->ecx -= cpu->edx;
    if (cpu->eax >= cpu->ecx) goto label_000A2AE1;
    if (*(uint32_t*)(cpu->esi + 0x1E4u) != cpu->ebp) goto label_000A2AAD;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    goto label_000A2AE1;
    label_000A2AAD:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->edx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    goto label_000A2AE1;
    label_000A2ABB:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x118u);
    if ((((cpu->edx & 0xFFu)) & (4u)) == 0u) goto label_000A2AD6;
    cpu->ebp = cpu->eax;
    cpu->ebp -= cpu->ecx;
    cpu->ebp += *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->ebp = cpu->ebp >> 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    label_000A2AD6:
    if ((((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_000A2AE1;
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000A2AE1:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->ecx >= cpu->eax) goto label_000A2AF6;
    cpu->edx = cpu->eax;
    cpu->edx -= cpu->ecx;
    cpu->edx >>= 1u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    label_000A2AF6:
    if (((*(uint8_t*)(cpu->esi + 0x118u)) & (2u)) == 0u) goto label_000A2B09;
    if (cpu->ecx >= cpu->eax) goto label_000A2B09;
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    label_000A2B09:
    cpu->ebp = 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0xDCu) != cpu->ebp) goto label_000A2B26;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000A2B26;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA2B26u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xA2B26u));
    label_000A2B26:
    if (*(uint32_t*)(cpu->edi + 0x14u) < cpu->ebx) goto label_000A2B2F;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_000A2B31;
    label_000A2B2F:
    cpu->eax = cpu->edi;
    label_000A2B31:
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x3Cu)));
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    *(double*)(cpu->esp + 0x3Cu) = x87_v0;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x30u)));
    *(double*)(cpu->esp + 0x28u) = x87_v1;
    *(float*)(cpu->esp) = (double)(0.0);
    lift_push32(cpu, cpu->ecx);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->edi = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2B80u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4A2B80u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1D8u);
    cpu->edx|=*(uint32_t*)(cpu->esi + 0x1DCu);
    if (cpu->edx!=0u) goto label_000A2B9F;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2B93u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4A2B93u));
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->edx;
    label_000A2B9F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2BA4u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4A2BA4u));
    sub_pred[0] = cpu->eax < *(uint32_t*)(cpu->esi + 0x1D8u); cpu->eax -= *(uint32_t*)(cpu->esi + 0x1D8u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1DCu) + (sub_pred[0]);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    *(float*)(cpu->esp + 0x28u) = ((((double)(((int64_t)(*(uint64_t*)(cpu->esp + 0x18u)))))) / (10000.0));
    x87_v0 = 0.0;
    x87_v1 = (double)*(float*)(cpu->esp + 0x28u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_000A2BEE; }
    x87_v0 = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2BDEu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4A2BDEu));
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->edx;
    label_000A2BEE:
    x87_v1 = 0.4000000059604645;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_000A2C35; }
    x87_v0 = (x87_v0) - (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->eax = 0xE7Fu;
    *(float*)(cpu->esp + 0x18u) = x87_v1; 
    x87_v0 = (((double)*(float*)(cpu->esp + 0x18u))) / (x87_v0);
    *(uint32_t*)(cpu->esp + 0x18u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x18u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    *(uint8_t*)(cpu->esi + 0x1E0u) = cpu->eax & 0xFFu;
    goto label_000A2C39;
    label_000A2C35:
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    label_000A2C39:
    if (*(uint8_t*)(cpu->esi + 0x4Au) == 0u) goto label_000A2CD6;
    if (*(uint8_t*)(cpu->esi + 0x1E0u) == 0u) goto label_000A2CD6;
    if (*(uint8_t*)(cpu->esi + 0x1E1u) == 0u) goto label_000A2C6D;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x1D0u)) goto label_000A2C6D;
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->eax;
    label_000A2C6D:
    x87_v0 = 0.0;
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Du);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1D0u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    *(float*)(cpu->esp) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x1A4u))));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->eax&=0xFFFFFFu;
    x87_v0 = (x87_v0) + (*(double*)(cpu->esp + 0x40u));
    cpu->ecx <<= 24u;
    lift_push32(cpu, cpu->edx);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"_");
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu))));
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->edx >= 0) goto label_000A2CC4;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000A2CC4:
    x87_v0 = (x87_v0) + (*(double*)(cpu->esp + 0x38u));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA2CD6u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_RVA(0xA2CD6u));
    label_000A2CD6:
    sub_pred[1] = *(uint32_t*)(cpu->esi + 0xDCu) == cpu->ebp;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (!sub_pred[1]) goto label_000A2CF3;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000A2CF3;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA2CF3u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xA2CF3u));
    label_000A2CF3:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    cpu->eax = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA2D03u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_RVA(0xA2D03u));
    label_000A2D03:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x64u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A2D20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2D2Bu)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4A2D2Bu));
    cpu->ebx = 0u;
    std::construct_at(reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi));
    *(uint16_t*)(cpu->esi + 0x1A8u) = cpu->ebx & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 0x1ACu) = 0x100u;
    *(uint32_t*)(cpu->esi + 0x1C8u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x1B4u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1D0u) = 0xFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->ebx;
    *(uint16_t*)(cpu->esi + 0x1E0u) = 0x101u;
    *(uint8_t*)(cpu->esi + 0x1E2u) = 1u;
    *(uint32_t*)(cpu->esi + 0x1E4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1E8u) = 0xFFFFFFFFu;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x50u) = 0xDu;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1B0u) = 5u;
    *(uint8_t*)(cpu->esi + 0x4Au) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1ECu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1F0u) = cpu->ebx;
    cpu->edi = cpu->esi + 0x1F4u;
    cpu->ebp = cpu->ebx + 0x64u;
    label_000A2DD4:
    lift_push32(cpu, 0xFAu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A2DDBu));
    cpu->esp += 0xCu;
    cpu->edi += 0x100u;
    if ((--cpu->ebp) != 0u) goto label_000A2DD4;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A2E00(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3];
    cpu->esp -= 0x104u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    sub_pred[2] = *(uint8_t*)(cpu->ebx + 0x4Bu) == 0u;
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 8u) = cpu->ebx;
    std::construct_at(reinterpret_cast<SphereUI::EditCtrl*>(cpu->ebx));
    if (sub_pred[2]) goto label_000A2F84;
    cpu->eax = 0x79616C70u;
    cpu->ecx = 0x5C737265u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x9Cu);
    cpu->eax += 0x178u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->edx & 0xFFu;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000A2E5E;
    cpu->esi = *(uint32_t*)(cpu->eax);
    goto label_000A2E60;
    label_000A2E5E:
    cpu->esi = cpu->eax;
    label_000A2E60:
    cpu->edx = (uintptr_t)"";
    cpu->ecx = cpu->esi;
    label_000A2E67:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    sub_pred[0] = (uint8_t)(cpu->eax) < *(uint8_t*)(cpu->edx);
    if ((uint8_t)(cpu->eax) != *(uint8_t*)(cpu->edx)) goto label_000A2E87;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000A2E83;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 1u));
    sub_pred[0] = (uint8_t)(cpu->eax) < *(uint8_t*)(cpu->edx + 1u);
    if ((uint8_t)(cpu->eax) != *(uint8_t*)(cpu->edx + 1u)) goto label_000A2E87;
    cpu->ecx += 2u;
    cpu->edx += 2u;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000A2E67;
    label_000A2E83:
    cpu->eax = 0u;
    goto label_000A2E8C;
    label_000A2E87:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000A2E8C:
    if (cpu->eax == 0u) goto label_000A2F84;
    cpu->edx = (uintptr_t)"testui";
    cpu->ecx = cpu->esi;
    label_000A2EA0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    sub_pred[1] = (uint8_t)(cpu->eax) < *(uint8_t*)(cpu->edx);
    if ((uint8_t)(cpu->eax) != *(uint8_t*)(cpu->edx)) goto label_000A2EC0;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000A2EBC;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 1u));
    sub_pred[1] = (uint8_t)(cpu->eax) < *(uint8_t*)(cpu->edx + 1u);
    if ((uint8_t)(cpu->eax) != *(uint8_t*)(cpu->edx + 1u)) goto label_000A2EC0;
    cpu->ecx += 2u;
    cpu->edx += 2u;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000A2EA0;
    label_000A2EBC:
    cpu->eax = 0u;
    goto label_000A2EC5;
    label_000A2EC0:
    cpu->eax = (sub_pred[1]) ? 0xFFFFFFFFu : 1u;
    label_000A2EC5:
    if (cpu->eax != 0u) goto label_000A2F84;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->esi;
    label_000A2ED1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A2ED1;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esp + 0x10u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_000A2EE0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000A2EE0;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = cpu->esp + 0x10u;
    --cpu->eax;
    label_000A2F00:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A2F00;
    cpu->ecx = 0x7478742Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    lift_push32(cpu, cpu->ebp);
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4A2F24u));
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebp == 0u) goto label_000A2F82;
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->ebx + 0x1ECu) <= cpu->esi) goto label_000A2F71;
    cpu->edi = cpu->ebx + 0x1F4u;
    cpu->ebx = native_function_address32(&::fprintf);
    label_000A2F50:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%s\n"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xA2F57u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++cpu->esi;
    cpu->esp += 0xCu;
    cpu->edi += 0x100u;
    if (cpu->esi < *(uint32_t*)(cpu->ecx + 0x1ECu)) goto label_000A2F50;
    cpu->ebx = cpu->ecx;
    label_000A2F71:
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4A2F72u));
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4A2F79u));
    cpu->esp += 8u;
    label_000A2F82:
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_000A2F84:
    cpu->esi = 0u;
    g_sfera_texture_cache_runtime.render_gate = cpu->esi;
    if (*(uint32_t*)(cpu->ebx + 0x1C8u) < 0x10u) goto label_000A2FA4;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x1B4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2FA1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A2FA1u));
    cpu->esp += 4u;
    label_000A2FA4:
    *(uint32_t*)(cpu->ebx + 0x1C8u) = 0xFu;
    *(uint32_t*)(cpu->ebx + 0x1C4u) = cpu->esi;
    cpu->ecx = cpu->ebx;
    *(uint8_t*)(cpu->ebx + 0x1B4u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2FC2u)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4A2FC2u));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x104u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A2FE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2FE8u)); sfera_sub_004A2E00(cpu, LIFT_CODE_TOKEN_VA(0x4A2FE8u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000A2FF8;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A2FF5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A2FF5u));
    cpu->esp += 4u;
    label_000A2FF8:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3000(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[4];
    cpu->esp -= 0x11Cu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x120u);
    cpu->edx = 0x5C737265u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x128u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = 0x79616C70u;
    *(uint8_t*)(cpu->esp + 0x2Cu) = cpu->eax & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x9Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x138u);
    cpu->eax += 0x178u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    sub_pred[0] = *(uint32_t*)(cpu->eax + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_000A306D;
    cpu->esi = *(uint32_t*)(cpu->eax);
    goto label_000A306F;
    label_000A306D:
    cpu->esi = cpu->eax;
    label_000A306F:
    cpu->edx = (uintptr_t)"";
    cpu->ecx = cpu->esi;
    label_000A3076:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    sub_pred[1] = (uint8_t)(cpu->eax) < *(uint8_t*)(cpu->edx);
    if ((uint8_t)(cpu->eax) != *(uint8_t*)(cpu->edx)) goto label_000A3096;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000A3092;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 1u));
    sub_pred[1] = (uint8_t)(cpu->eax) < *(uint8_t*)(cpu->edx + 1u);
    if ((uint8_t)(cpu->eax) != *(uint8_t*)(cpu->edx + 1u)) goto label_000A3096;
    cpu->ecx += 2u;
    cpu->edx += 2u;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000A3076;
    label_000A3092:
    cpu->eax = 0u;
    goto label_000A309B;
    label_000A3096:
    cpu->eax = (sub_pred[1]) ? 0xFFFFFFFFu : 1u;
    label_000A309B:
    if (cpu->eax == 0u) goto label_000A3192;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->esi;
    label_000A30A7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A30A7;
    cpu->edi = cpu->esp + 0x2Cu;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_000A30B5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000A30B5;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = cpu->esp + 0x2Cu;
    --cpu->eax;
    label_000A30D2:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A30D2;
    cpu->ecx = 0x7478742Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, (uintptr_t)"r"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4A30F5u));
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->edi == 0u) goto label_000A318E;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::feof), LIFT_CODE_TOKEN_VA(0x4A3109u));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_000A3172;
    cpu->ebx = native_function_address32(&::fgets);
    cpu->esi = cpu->ebp + 0x1F4u;
    label_000A3122:
    if (*(uint32_t*)(cpu->ebp + 0x1ECu) >= 0x63u) goto label_000A316E;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fgets)))(cpu->esi, 0xFDu, cpu->edi);

    cpu->eax = 0u;
    label_000A3140:
    if (*(uint8_t*)(cpu->esi + cpu->eax) == 0xAu) goto label_000A3150;
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)0xFDu) goto label_000A3140;
    goto label_000A3154;
    label_000A3150:
    *(uint8_t*)(cpu->esi + cpu->eax) = 0u;
    label_000A3154:
    ++*(uint32_t*)(cpu->ebp + 0x1ECu);
    lift_push32(cpu, cpu->edi);
    cpu->esi += 0x100u;
    lift_native_call(cpu, native_function_address32(&::feof), LIFT_CODE_TOKEN_VA(0x4A3161u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000A3122;
    label_000A316E:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    label_000A3172:
    --*(uint32_t*)(cpu->ebp + 0x1ECu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1ECu);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0x1F0u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4A3185u));
    cpu->esp += 4u;
    label_000A318E:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_000A3192:
    cpu->ecx = cpu->esp + 0x20u;
    { const uint32_t __parser_arg_016_34_0 = static_cast<uint32_t>(cpu->ecx);
    cpu->ecx = cpu->ebx;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->getBlockRange(reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_34_0))); }
    if (*(uint32_t*)(cpu->ebp + 0x9Cu) != 0u) goto label_000A31C4;
    lift_push32(cpu, 0xC6u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\EditCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A31BBu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A31BBu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A31C1u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A31C1u));
    cpu->esp += 0x10u;
    label_000A31C4:
    { const uint32_t __parser_arg_016_35_0 = static_cast<uint32_t>(cpu->edi); const uint32_t __parser_arg_016_35_1 = static_cast<uint32_t>((uintptr_t)"maxsymbols");
    cpu->ecx = cpu->ebx;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_35_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_35_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000A31E4;
    { const uint32_t __parser_arg_016_36_0 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->ebx;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(__parser_direct->readInt(__parser_arg_016_36_0)); }
    *(uint32_t*)(cpu->ebp + 0x1ACu) = cpu->eax;
    label_000A31E4:
    { const uint32_t __parser_arg_016_37_0 = static_cast<uint32_t>(cpu->edi); const uint32_t __parser_arg_016_37_1 = static_cast<uint32_t>((uintptr_t)"numeric");
    cpu->ecx = cpu->ebx;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_37_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_37_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000A3209;
    { const uint32_t __parser_arg_016_38_0 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->ebx;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->readBool(__parser_arg_016_38_0) ? 1u : 0u; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax!=0u) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->ebp + 0x1A8u) = cpu->edx & 0xFFu;
    label_000A3209:
    { const uint32_t __parser_arg_016_39_0 = static_cast<uint32_t>(cpu->edi); const uint32_t __parser_arg_016_39_1 = static_cast<uint32_t>((uintptr_t)"password");
    cpu->ecx = cpu->ebx;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_39_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_39_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000A322E;
    { const uint32_t __parser_arg_016_40_0 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->ebx;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->readBool(__parser_arg_016_40_0) ? 1u : 0u; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((cpu->eax!=0u) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->ebp + 0x1A9u) = cpu->eax & 0xFFu;
    label_000A322E:
    { const uint32_t __parser_arg_016_41_0 = static_cast<uint32_t>(cpu->edi); const uint32_t __parser_arg_016_41_1 = static_cast<uint32_t>((uintptr_t)"enteredOnFocus");
    cpu->ecx = cpu->ebx;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_41_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_41_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000A3253;
    { const uint32_t __parser_arg_016_42_0 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->ebx;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->readBool(__parser_arg_016_42_0) ? 1u : 0u; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax!=0u) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->ebp + 0x1E2u) = cpu->ecx & 0xFFu;
    label_000A3253:
    { const uint32_t __parser_arg_016_43_0 = static_cast<uint32_t>(cpu->edi); const uint32_t __parser_arg_016_43_1 = static_cast<uint32_t>((uintptr_t)"cursorcolor");
    cpu->ecx = cpu->ebx;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_43_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_43_0))) ? 1u : 0u; }
    cpu->esi = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_000A32D1;
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xA3282u));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000A32AB;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"EditCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'cursorcolor'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A32A2u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A32A2u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A32A8u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A32A8u));
    cpu->esp += 0x14u;
    label_000A32AB:
    cpu->eax = *(uint8_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x1Cu);
    cpu->eax <<= 8u;
    cpu->eax|=cpu->ecx;
    cpu->eax <<= 8u;
    cpu->eax |= cpu->edx;
    *(uint32_t*)(cpu->ebp + 0x1D0u) = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0x1E1u) = 0u;
    label_000A32D1:
    { const uint32_t __parser_arg_016_44_0 = static_cast<uint32_t>(cpu->edi); const uint32_t __parser_arg_016_44_1 = static_cast<uint32_t>((uintptr_t)"cursoroffset");
    cpu->ecx = cpu->ebx;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_44_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_44_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000A3322;
    cpu->eax = cpu->ebp + 0x1A4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x1A0u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xA32F9u));
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000A3322;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"EditCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'cursorOffset'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3319u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A3319u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A331Fu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A331Fu));
    cpu->esp += 0x14u;
    label_000A3322:
    if (*(uint32_t*)(cpu->ebp + 0x1ACu) != 0u) goto label_000A3335;
    *(uint32_t*)(cpu->ebp + 0x1ACu) = 0x100u;
    label_000A3335:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1ACu);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x64u);
    cpu->esi = cpu->ebp + 0x54u;
    ++cpu->eax;
    if (cpu->edi > cpu->eax) goto label_000A3368;
    if (*(uint32_t*)(cpu->esi + 0x14u) == cpu->eax) goto label_000A3368;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3355u)); sfera_sub_00403CA0(cpu, LIFT_CODE_TOKEN_VA(0x4A3355u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000A3368;
    sub_pred[2] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[2]) goto label_000A3364;
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_000A3364:
    *(uint8_t*)(cpu->esi + cpu->edi) = 0u;
    label_000A3368:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1ACu);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x1C4u);
    cpu->esi = cpu->ebp + 0x1B4u;
    ++cpu->eax;
    if (cpu->edi > cpu->eax) goto label_000A33A1;
    if (*(uint32_t*)(cpu->esi + 0x14u) == cpu->eax) goto label_000A33A1;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A338Eu)); sfera_sub_00403CA0(cpu, LIFT_CODE_TOKEN_VA(0x4A338Eu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000A33A1;
    sub_pred[3] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[3]) goto label_000A339D;
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_000A339D:
    *(uint8_t*)(cpu->esi + cpu->edi) = 0u;
    label_000A33A1:
    cpu->edx = *(uint8_t*)(cpu->ebp + 0x8Cu);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ebp + 0x1B0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    cpu->ecx = (uintptr_t)"_";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A33C0u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4A33C0u));
    ++*(uint32_t*)(cpu->esi);
    cpu->ecx = cpu->esp + 0x20u;
    { const uint32_t __parser_arg_016_45_0 = static_cast<uint32_t>(cpu->ecx);
    cpu->ecx = cpu->ebx;
    *(uint8_t*)(cpu->ebp + 0x4Au) = 0u;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->setBlockRange(reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_45_0))); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x11Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3400(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[4];
    cpu->esp -= 0x22Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = 0u;
    if (*(uint8_t*)(cpu->esi + 0x4Au) == (cpu->eax & 0xFFu)) goto label_000A3428;
    g_sfera_texture_cache_runtime.render_gate = 1u;
    label_000A3428:
    if (*(uint8_t*)(cpu->esi + 0x48u) != (cpu->eax & 0xFFu)) goto label_000A3974;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if (cpu->edi == cpu->eax) goto label_000A347B;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000A3465;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA3465u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xA3465u));
    label_000A3465:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 8u);
    cpu->edi = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->edi += *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    label_000A347B:
    sub_pred[1] = *(uint8_t*)(cpu->esi + 0x4Au) == 0u;
    lift_push32(cpu, cpu->ebx);
    if (sub_pred[1]) goto label_000A38E1;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x23Cu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0x15u));
    if ((cpu->eax & 0xFFu) < 0x20u) goto label_000A34EF;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x64u);
    if (cpu->ecx >= *(uint32_t*)(cpu->esi + 0x1ACu)) goto label_000A34EF;
    if (*(uint8_t*)(cpu->esi + 0x1A8u) == 0u) goto label_000A34B0;
    if ((cpu->eax & 0xFFu) < 0x30u) goto label_000A34EF;
    if ((cpu->eax & 0xFFu) > 0x39u) goto label_000A34EF;
    label_000A34B0:
    *(uint8_t*)(cpu->esp + 0xCu) = cpu->eax & 0xFFu;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000A34EF;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1E4u);
    sub_pred[2] = cpu->eax == cpu->ecx;
    cpu->ecx = cpu->esi + 0x54u;
    if (!sub_pred[2]) goto label_000A34DC;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A34D1u)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_VA(0x4A34D1u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x64u);
    *(uint32_t*)(cpu->esi + 0x1E4u) = cpu->ecx;
    goto label_000A34EF;
    label_000A34DC:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A34E9u)); sfera_sub_0048E480(cpu, LIFT_CODE_TOKEN_VA(0x4A34E9u));
    ++*(uint32_t*)(cpu->esi + 0x1E4u);
    label_000A34EF:
    if (*(uint8_t*)(cpu->ebx + 0x14u) != 8u) goto label_000A3517;
    if (*(uint32_t*)(cpu->esi + 0x64u) <= 0u) goto label_000A3517;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1E4u);
    if ((int32_t)cpu->eax <= 0) goto label_000A3517;
    lift_push32(cpu, 1u);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3511u)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x4A3511u));
    --*(uint32_t*)(cpu->esi + 0x1E4u);
    label_000A3517:
    if (*(uint8_t*)(cpu->ebx + 0x14u) != 0x2Eu) goto label_000A3539;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x64u);
    if (cpu->ecx == 0u) goto label_000A3539;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1E4u);
    if (cpu->eax == cpu->ecx) goto label_000A3539;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA3539u)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_RVA(0xA3539u));
    label_000A3539:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0x14u));
    if ((cpu->eax & 0xFFu) != 0x25u) goto label_000A3548;
    --*(uint32_t*)(cpu->esi + 0x1E4u);
    goto label_000A3552;
    label_000A3548:
    if ((cpu->eax & 0xFFu) != 0x27u) goto label_000A3552;
    ++*(uint32_t*)(cpu->esi + 0x1E4u);
    label_000A3552:
    if (*(uint8_t*)(cpu->ebx + 0x14u) != 0x24u) goto label_000A3562;
    *(uint32_t*)(cpu->esi + 0x1E4u) = 0u;
    label_000A3562:
    if (*(uint8_t*)(cpu->ebx + 0x14u) != 0x23u) goto label_000A3571;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x64u);
    *(uint32_t*)(cpu->esi + 0x1E4u) = cpu->eax;
    label_000A3571:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1E4u) >= (int32_t)0u) goto label_000A3584;
    *(uint32_t*)(cpu->esi + 0x1E4u) = 0u;
    label_000A3584:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x64u);
    if (*(uint32_t*)(cpu->esi + 0x1E4u) <= cpu->eax) goto label_000A3595;
    *(uint32_t*)(cpu->esi + 0x1E4u) = cpu->eax;
    label_000A3595:
    sub_pred[3] = *(uint8_t*)(cpu->esi + 0x1A9u) == 0u;
    *(uint32_t*)(cpu->esi + 0x1E8u) = cpu->eax;
    if (sub_pred[3]) goto label_000A35F3;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x1C4u)) goto label_000A35F3;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi + 0x54u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x1B4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A35BFu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4A35BFu));
    cpu->eax = 0u;
    if (*(uint32_t*)(cpu->esi + 0x1C4u) <= cpu->eax) goto label_000A35F3;
    cpu->edx = 0x10u;
    label_000A35D0:
    if (*(uint32_t*)(cpu->esi + 0x1C8u) < cpu->edx) goto label_000A35E0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B4u);
    goto label_000A35E6;
    label_000A35E0:
    cpu->ecx = cpu->esi + 0x1B4u;
    label_000A35E6:
    *(uint8_t*)(cpu->ecx + cpu->eax) = 0x2Au;
    ++cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0x1C4u)) goto label_000A35D0;
    label_000A35F3:
    if (*(uint8_t*)(cpu->ebx + 0x14u) != 0x26u) goto label_000A3664;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1F0u);
    if (cpu->eax == 0u) goto label_000A3664;
    lift_push32(cpu, 0u);
    --cpu->eax;
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esi + 0x1F0u) = cpu->eax;
    lift_push32(cpu, 0x1198u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    if (cpu->eax != 1u) goto label_000A3664;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1F0u);
    cpu->eax <<= 8u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->eax + cpu->esi + 0x1F4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x1196u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1F0u);
    cpu->eax <<= 8u;
    cpu->eax = cpu->eax + cpu->esi + 0x1F4u;
    cpu->edx = cpu->eax + 1u;
    label_000A3655:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A3655;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esi + 0x1E4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1E4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_000A3664:
    if (*(uint8_t*)(cpu->ebx + 0x14u) != 0x28u) goto label_000A36DF;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1F0u);
    if (cpu->eax >= *(uint32_t*)(cpu->esi + 0x1ECu)) goto label_000A36DF;
    lift_push32(cpu, 0u);
    ++cpu->eax;
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esi + 0x1F0u) = cpu->eax;
    lift_push32(cpu, 0x1198u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    if (cpu->eax != 1u) goto label_000A36DF;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1F0u);
    cpu->eax <<= 8u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->eax + cpu->esi + 0x1F4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x1196u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1F0u);
    cpu->eax <<= 8u;
    cpu->eax = cpu->eax + cpu->esi + 0x1F4u;
    cpu->edx = cpu->eax + 1u;
    label_000A36D0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A36D0;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esi + 0x1E4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1E4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_000A36DF:
    if (*(uint8_t*)(cpu->ebx + 0x14u) != 9u) goto label_000A370B;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->edx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = 0x119Au;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA370Bu)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xA370Bu));
    label_000A370B:
    if (*(uint8_t*)(cpu->ebx + 0x14u) != 0xDu) goto label_000A38E1;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = 0x1195u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A373Bu)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_VA(0x4A373Bu));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x1198u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    if (cpu->eax != 1u) goto label_000A38E1;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->eax + 0x62u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, 0x1197u);
    if (*(uint32_t*)(cpu->esi + 0x1ECu) >= cpu->ebp) goto label_000A37B9;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->eax <<= 8u;
    cpu->ecx = cpu->esp + 0x38u;
    cpu->edx = cpu->eax + cpu->esi + 0x1F4u;
    label_000A3790:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu)!=0u) goto label_000A3790;
    ++*(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1ECu);
    *(uint32_t*)(cpu->esi + 0x1F0u) = cpu->eax;
    cpu->eax <<= 8u;
    *(uint8_t*)(cpu->eax + cpu->esi + 0x1F4u) = 0u;
    goto label_000A3817;
    label_000A37B9:
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0xA37B9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->eax <<= 8u;
    cpu->ecx = cpu->esp + 0x38u;
    cpu->edx = cpu->eax + cpu->esi + 0x1F4u;
    (void)cpu;
    label_000A37D0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000A37D0;
    cpu->edi = cpu->esi + 0x2F4u;
    label_000A37E0:
    cpu->eax = cpu->edi;
    cpu->edx = 0xFFFFFF00u;
    label_000A37E7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->eax + cpu->edx) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A37E7;
    cpu->edi += 0x100u;
    if ((--cpu->ebp) != 0u) goto label_000A37E0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->ecx <<= 8u;
    *(uint8_t*)(cpu->ecx + cpu->esi + 0x1F4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1ECu);
    *(uint32_t*)(cpu->esi + 0x1F0u) = cpu->edx;
    label_000A3817:
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->edi = 0u;
    if (cpu->ebx == 0u) goto label_000A38E0;
    cpu->ebp = cpu->esi + 0x1F4u;
    label_000A3830:
    if (cpu->ebx <= 1u) goto label_000A3879;
    cpu->eax = cpu->ebx + 0xFFFFFFFFu;
    if (cpu->edi == cpu->eax) goto label_000A3879;
    cpu->ecx = cpu->ebx;
    cpu->ecx <<= 8u;
    cpu->ecx = cpu->ecx + cpu->esi + 0xF4u;
    cpu->eax = cpu->ebp;
    label_000A3850:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_000A3870;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000A386C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_000A3870;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000A3850;
    label_000A386C:
    cpu->eax = 0u;
    goto label_000A3875;
    label_000A3870:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000A3875:
    if (cpu->eax == 0u) goto label_000A388A;
    label_000A3879:
    ++cpu->edi;
    cpu->ebp += 0x100u;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x1ECu)) goto label_000A3830;
    goto label_000A38E0;
    label_000A388A:
    --cpu->ebx;
    cpu->ebp = cpu->edi;
    if (cpu->edi >= cpu->ebx) goto label_000A38C3;
    cpu->edi <<= 8u;
    cpu->edi = cpu->edi + cpu->esi + 0x2F4u;
    label_000A38A0:
    cpu->eax = cpu->edi;
    cpu->edx = 0xFFFFFF00u;
    label_000A38A7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->eax + cpu->edx) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A38A7;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1ECu);
    ++cpu->ebp;
    --cpu->edx;
    cpu->edi += 0x100u;
    if (cpu->ebp < cpu->edx) goto label_000A38A0;
    label_000A38C3:
    --*(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1ECu);
    *(uint32_t*)(cpu->esi + 0x1F0u) = cpu->eax;
    cpu->eax <<= 8u;
    *(uint8_t*)(cpu->eax + cpu->esi + 0x1F4u) = 0u;
    label_000A38E0:
    cpu->ebp = lift_pop32(cpu);
    label_000A38E1:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x23Cu);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    if (((*(uint8_t*)(cpu->edi + 0xCu)) & (1u)) == 0u) goto label_000A3972;
    cpu->edx = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->edx < (int32_t)cpu->eax) goto label_000A3963;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ebx += cpu->eax;
    if ((int32_t)cpu->edx >= (int32_t)cpu->ebx) goto label_000A3963;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_000A3963;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)cpu->eax >= (int32_t)cpu->edx) goto label_000A3963;
    if (*(uint8_t*)(cpu->esi + 0x4Au) != 0u) goto label_000A3972;
    lift_push32(cpu, 0xDu); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3935u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4A3935u));
    lift_push32(cpu, 0x11u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3949u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4A3949u));
    lift_push32(cpu, 0x17u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A395Du)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4A395Du));
    *(uint8_t*)(cpu->esi + 0x4Au) = 1u;
    goto label_000A3972;
    label_000A3963:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x69u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::EditCtrl*>(cpu->esi)->handleMessage(cpu);
    label_000A3972:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_000A3974:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x22Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3990(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if (cpu->ebp != 0x1199u) goto label_000A39E0;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x64u);
    *(uint32_t*)(cpu->esi + 0x1E4u) = cpu->eax;
    label_000A39BD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A39CBu)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_VA(0x4A39CBu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A39E0:
    if (cpu->ebp != 0x1198u) goto label_000A3A01;
    cpu->eax = *(uint8_t*)(cpu->esi + 0x4Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A3A01:
    if (cpu->ebp != 0x1196u) goto label_000A3A35;
    cpu->edx = cpu->ebx;
    if (cpu->ebx != 0u) goto label_000A3A14;
    cpu->edx = (uintptr_t)"";
    label_000A3A14:
    cpu->eax = cpu->edx;
    cpu->edi = cpu->eax + 1u;
    label_000A3A20:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A3A20;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x54u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3A33u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4A3A33u));
    goto label_000A39BD;
    label_000A3A35:
    if (cpu->ebp != 0x1197u) goto label_000A3A6D;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x64u);
    if (cpu->edi <= 0xFAu) goto label_000A3A4D;
    cpu->edi = 0xFAu;
    label_000A3A4D:
    cpu->eax = cpu->esi + 0x54u;
    if (*(uint32_t*)(cpu->esi + 0x68u) < 0x10u) goto label_000A3A58;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000A3A58:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4A3A5Bu));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->ebx + cpu->edi) = 0u;
    goto label_000A39BD;
    label_000A3A6D:
    if (cpu->ebp != 0x69u) goto label_000A39BD;
    lift_test[0]=cpu->ebx==0u;
    if (cpu->ebx!=0u) goto label_000A3AAF;
    if (*(uint8_t*)(cpu->esi + 0x4Au) == (cpu->ebx & 0xFFu)) goto label_000A3AAD;
    if (*(uint8_t*)(cpu->esi + 0x1E2u) == (cpu->ebx & 0xFFu)) goto label_000A3AAD;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->edx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0x1195u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA3AADu)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xA3AADu));
    label_000A3AAD:
    lift_test[0]=cpu->ebx==0u;
    label_000A3AAF:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((!lift_test[0]) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->esi + 0x4Au) = cpu->eax & 0xFFu;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000A3AFD;
    lift_push32(cpu, 0xDu); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    *(uint8_t*)(cpu->esi + 0x4Au) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3AD1u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4A3AD1u));
    lift_push32(cpu, 0x11u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3AE5u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4A3AE5u));
    lift_push32(cpu, 0x17u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0x69u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3AF9u)); sfera_sub_004B9970(cpu, LIFT_CODE_TOKEN_VA(0x4A3AF9u));
    *(uint8_t*)(cpu->esi + 0x4Au) = 1u;
    label_000A3AFD:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x20u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3B20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3B30u)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4A3B30u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    *(uint32_t*)(cpu->ebx + 0x198u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    *(uint32_t*)(cpu->ebx + 0x19Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    *(uint32_t*)(cpu->ebx + 0x1A0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A4u);
    *(uint32_t*)(cpu->ebx + 0x1A4u) = cpu->eax;
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x1A8u);
    *(uint8_t*)(cpu->ebx + 0x1A8u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint8_t*)(cpu->esi + 0x1A9u);
    *(uint8_t*)(cpu->ebx + 0x1A9u) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1ACu);
    lift_push32(cpu, 0xFFFFFFFFu);
    *(uint32_t*)(cpu->ebx + 0x1ACu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B0u);
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esi + 0x1B4u;
    *(uint32_t*)(cpu->ebx + 0x1B0u) = cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx + 0x1B4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3BA8u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4A3BA8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1D0u);
    *(uint32_t*)(cpu->ebx + 0x1D0u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D8u);
    *(uint32_t*)(cpu->ebx + 0x1D8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1DCu);
    *(uint32_t*)(cpu->ebx + 0x1DCu) = cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x1E0u));
    *(uint8_t*)(cpu->ebx + 0x1E0u) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x1E1u);
    *(uint8_t*)(cpu->ebx + 0x1E1u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint8_t*)(cpu->esi + 0x1E2u);
    *(uint8_t*)(cpu->ebx + 0x1E2u) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1E4u);
    *(uint32_t*)(cpu->ebx + 0x1E4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1E8u);
    *(uint32_t*)(cpu->ebx + 0x1E8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1ECu);
    *(uint32_t*)(cpu->ebx + 0x1ECu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1F0u);
    cpu->edx = cpu->esi;
    *(uint32_t*)(cpu->ebx + 0x1F0u) = cpu->eax;
    cpu->eax = cpu->ebx + 0x1F4u;
    cpu->edx -= cpu->ebx;
    cpu->ebp = 0x64u;
    label_000A3C31:
    cpu->esi = cpu->edx + cpu->eax;
    cpu->edi = cpu->eax;
    cpu->eax += 0x100u;
    --cpu->ebp; sub_pred[0] = cpu->ebp == 0u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),256u); cpu->esi += 256u; cpu->edi += 256u; cpu->ecx = 0u;
    if (!sub_pred[0]) goto label_000A3C31;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3C50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = cpu->ecx;
    cpu->edx = 0x197u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\EditCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3C84u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A3C84u));
    lift_push32(cpu, 0x65F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3C8Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A3C8Eu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_000A3CAC;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3CA8u)); sfera_sub_004A2D20(cpu, LIFT_CODE_TOKEN_VA(0x4A3CA8u));
    cpu->esi = cpu->eax;
    goto label_000A3CAE;
    label_000A3CAC:
    cpu->esi = 0u;
    label_000A3CAE:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3CBEu)); sfera_sub_004A3B20(cpu, LIFT_CODE_TOKEN_VA(0x4A3CBEu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_000A3CE6;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA3CE6u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xA3CE6u));
    label_000A3CE6:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_000A3D57;
    if (cpu->ecx > 0x71C71C7u) goto label_000A3D29;
    cpu->eax = cpu->ecx + (cpu->ecx * 8u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3D22u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A3D22u));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_000A3D57;
    label_000A3D29:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA3D57u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xA3D57u));
    label_000A3D57:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3D60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    if (cpu->edi != cpu->eax) goto label_000A3D7D;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A3D7D:
    if (cpu->edi <= 0x71C71C7u) goto label_000A3D90;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A3D7Du), "std::length_error");
    label_000A3D90:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3D99u)); sfera_sub_004A3D00(cpu, LIFT_CODE_TOKEN_VA(0x4A3D99u));
    cpu->ecx = cpu->edi + (cpu->edi * 8u);
    cpu->edx = cpu->eax + (cpu->ecx * 4u);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3DB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->esi = cpu->ecx;
    if (cpu->esi == cpu->ebx) goto label_000A3DEA;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    (void)cpu;
    label_000A3DC0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3DCCu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4A3DCCu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    *(uint32_t*)(cpu->edi + 0x20u) = cpu->ecx;
    cpu->esi += 0x24u;
    cpu->edi += 0x24u;
    if (cpu->esi != cpu->ebx) goto label_000A3DC0;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000A3DEA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3E00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000A3E14;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3E11u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A3E11u));
    cpu->esp += 4u;
    label_000A3E14:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3E30(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000A3E70:
    if (cpu->edi == *(uint32_t*)(cpu->ebp + 0xFFFFFFECu)) goto label_000A3ED9;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->ebx) goto label_000A3EA3;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3E97u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4A3E97u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x20u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ecx;
    label_000A3EA3:
    cpu->esi += 0x24u;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    cpu->edi += 0x24u;
    goto label_000A3E70;
    label_000A3ED9:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3EB1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->esi == cpu->edi) goto label_000A3ED0;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    label_000A3EC0:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3EC9u)); sfera_sub_004A3E00(cpu, LIFT_CODE_TOKEN_VA(0x4A3EC9u));
    cpu->esi += 0x24u;
    if (cpu->esi != cpu->edi) goto label_000A3EC0;
    label_000A3ED0:
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3ED9u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4A3ED9u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3EF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    if (cpu->esi == cpu->edi) goto label_000A3F29;
    label_000A3F00:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000A3F11;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3F0Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A3F0Eu));
    cpu->esp += 4u;
    label_000A3F11:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->esi += 0x24u;
    if (cpu->esi != cpu->edi) goto label_000A3F00;
    label_000A3F29:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3F30(LiftCpu* cpu, uint32_t stop_address) {
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
    label_000A3F70:
    if (cpu->edi == *(uint32_t*)(cpu->ebp + 0xFFFFFFECu)) goto label_000A3FD9;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->ebx) goto label_000A3FA3;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3F97u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4A3F97u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x20u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ecx;
    label_000A3FA3:
    cpu->esi += 0x24u;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    cpu->edi += 0x24u;
    goto label_000A3F70;
    label_000A3FD9:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3FB1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->esi == cpu->edi) goto label_000A3FD0;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    label_000A3FC0:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3FC9u)); sfera_sub_004A3E00(cpu, LIFT_CODE_TOKEN_VA(0x4A3FC9u));
    cpu->esi += 0x24u;
    if (cpu->esi != cpu->edi) goto label_000A3FC0;
    label_000A3FD0:
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A3FD9u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4A3FD9u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A3FF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4006u)); sfera_sub_004A3EF0(cpu, LIFT_CODE_TOKEN_VA(0x4A4006u));
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A40FA(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4103u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A4103u));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A410Fu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4A410Fu));
    lift_trap(cpu, 0x4A410Fu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004A4110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A412Bu)); sfera_sub_004A3F30(cpu, LIFT_CODE_TOKEN_VA(0x4A412Bu));
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A4130(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000A4130;
    label_000A4010:
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
    if (cpu->ebx <= 0x71C71C7u) goto label_000A4053;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A4010u), "std::length_error");
    label_000A4053:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->eax >= cpu->ebx) goto label_000A40E6;
    cpu->edi = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4078u)); sfera_sub_004A3D00(cpu, LIFT_CODE_TOKEN_VA(0x4A4078u));
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4094u)); sfera_sub_004A3E30(cpu, LIFT_CODE_TOKEN_VA(0x4A4094u));
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->edx -= cpu->ecx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if (cpu->ecx == 0u) goto label_000A40CC;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A40C1u)); sfera_sub_004A3EF0(cpu, LIFT_CODE_TOKEN_VA(0x4A40C1u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A40C9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A40C9u));
    cpu->esp += 4u;
    label_000A40CC:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = cpu->eax + (cpu->ecx * 4u);
    cpu->ecx = cpu->edi + (cpu->edi * 8u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->edx = cpu->eax + (cpu->ecx * 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    label_000A40E6:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A4130:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    cpu->edx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->edx))) >> 32u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    cpu->edx = 0x71C71C7u;
    cpu->edx -= cpu->eax;
    if (cpu->edx >= cpu->esi) goto label_000A4164;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A4130u), "std::length_error");
    label_000A4164:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->esi += cpu->eax;
    cpu->edx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->esi <= cpu->eax) goto label_000A41A6;
    cpu->edx = cpu->eax;
    cpu->edx >>= 1u;
    cpu->edi = 0x71C71C7u;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_000A4193;
    cpu->eax = 0u;
    goto label_000A4195;
    label_000A4193:
    cpu->eax += cpu->edx;
    label_000A4195:
    if (cpu->eax >= cpu->esi) goto label_000A419B;
    cpu->eax = cpu->esi;
    label_000A419B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    goto label_000A4010;
    label_000A41A6:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A41B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A41B8u)); sfera_sub_004BFB90(cpu, LIFT_CODE_TOKEN_VA(0x4A41B8u));
    cpu->eax = 0u;
    std::construct_at(reinterpret_cast<SphereUI::FilterListCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x1F8u) = 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1FCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x200u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x204u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x20Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x50u) = 0x12u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A41F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1FCu);
    if (cpu->ecx == 0u) goto label_000A4224;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi + 0x208u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x200u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4215u)); sfera_sub_004A3EF0(cpu, LIFT_CODE_TOKEN_VA(0x4A4215u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1FCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4221u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A4221u));
    cpu->esp += 4u;
    label_000A4224:
    *(uint32_t*)(cpu->esi + 0x1FCu) = 0u;
    *(uint32_t*)(cpu->esi + 0x200u) = 0u;
    *(uint32_t*)(cpu->esi + 0x204u) = 0u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004BFC50(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004A4250(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->esi == cpu->ebx) goto label_000A43C4;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx -= *(uint32_t*)(cpu->ebx);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != 0u) goto label_000A42B3;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == cpu->ecx) goto label_000A43C3;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4293u)); sfera_sub_004A3DB0(cpu, LIFT_CODE_TOKEN_VA(0x4A4293u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A42A8u)); sfera_sub_004A3EF0(cpu, LIFT_CODE_TOKEN_VA(0x4A42A8u));
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A42B3:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esi);
    cpu->edx -= cpu->ebp;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if (cpu->ecx > cpu->edi) goto label_000A431D;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A42E0u)); sfera_sub_004A3DB0(cpu, LIFT_CODE_TOKEN_VA(0x4A42E0u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A42F3u)); sfera_sub_004A3EF0(cpu, LIFT_CODE_TOKEN_VA(0x4A42F3u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx -= *(uint32_t*)(cpu->ebx);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->eax = cpu->eax + (cpu->eax * 8u);
    cpu->ebp = lift_pop32(cpu);
    cpu->edx = cpu->ecx + (cpu->eax * 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A431D:
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx -= cpu->ebp;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->ecx > cpu->eax) goto label_000A4371;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->edi + (cpu->edi * 8u);
    cpu->edi = cpu->ecx + (cpu->edx * 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A434Cu)); sfera_sub_004A3DB0(cpu, LIFT_CODE_TOKEN_VA(0x4A434Cu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ebx = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4365u)); sfera_sub_004A3F30(cpu, LIFT_CODE_TOKEN_VA(0x4A4365u));
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A4371:
    if (cpu->ebp == 0u) goto label_000A438C;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4381u)); sfera_sub_004A3FF0(cpu, LIFT_CODE_TOKEN_VA(0x4A4381u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4389u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A4389u));
    cpu->esp += 4u;
    label_000A438C:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx -= *(uint32_t*)(cpu->ebx);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A43AAu)); sfera_sub_004A3D60(cpu, LIFT_CODE_TOKEN_VA(0x4A43AAu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000A43C2;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A43BFu)); sfera_sub_004A4110(cpu, LIFT_CODE_TOKEN_VA(0x4A43BFu));
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_000A43C2:
    cpu->ebp = lift_pop32(cpu);
    label_000A43C3:
    cpu->edi = lift_pop32(cpu);
    label_000A43C4:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A43D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->esi >= cpu->ecx) goto label_000A446A;
    cpu->eax = *(uint32_t*)(cpu->edi);
    if (cpu->eax > cpu->esi) goto label_000A446A;
    cpu->esi -= cpu->eax;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->esi))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 8u)) goto label_000A4428;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA4428u)); sfera_sub_004A4130(cpu, LIFT_CODE_TOKEN_RVA(0xA4428u));
    label_000A4428:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->eax = cpu->esi + (cpu->esi * 8u);
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    cpu->ebx = cpu->ecx + (cpu->eax * 4u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if (cpu->esi == cpu->eax) goto label_000A44B4;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A445Cu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4A445Cu));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x20u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    goto label_000A44B4;
    label_000A446A:
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 8u)) goto label_000A4478;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA4478u)); sfera_sub_004A4130(cpu, LIFT_CODE_TOKEN_RVA(0xA4478u));
    label_000A4478:
    cpu->ebx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 1u;
    if (cpu->ebx == cpu->eax) goto label_000A44B4;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ebx + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    *(uint8_t*)(cpu->ebx) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A44A8u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4A44A8u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->ebx + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x20u);
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->edx;
    label_000A44B4:
    *(uint32_t*)(cpu->edi + 4u) = (uint64_t)(*(uint32_t*)(cpu->edi + 4u)) + (uint64_t)(0x24u) + (uint64_t)(0u);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A44D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A44D8u)); sfera_sub_004A41F0(cpu, LIFT_CODE_TOKEN_VA(0x4A44D8u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000A44E8;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A44E5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A44E5u));
    cpu->esp += 4u;
    label_000A44E8:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A44F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A44FEu)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4A44FEu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x198u);
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    cpu->edx = cpu->edi + 0x1A0u;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x1A0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4528u)); sfera_sub_004A4250(cpu, LIFT_CODE_TOKEN_VA(0x4A4528u));
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
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1CCu));
    *(uint8_t*)(cpu->esi + 0x1CCu) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint8_t*)(cpu->edi + 0x1CDu);
    *(uint8_t*)(cpu->esi + 0x1CDu) = cpu->edx & 0xFFu;
    cpu->eax = *(uint8_t*)(cpu->edi + 0x1CEu);
    *(uint8_t*)(cpu->esi + 0x1CEu) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1D0u);
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->ecx;
    cpu->edx = *(uint8_t*)(cpu->edi + 0x1D4u);
    *(uint8_t*)(cpu->esi + 0x1D4u) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1D8u);
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1DCu);
    *(uint32_t*)(cpu->esi + 0x1DCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1E0u);
    *(uint32_t*)(cpu->esi + 0x1E0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1E4u);
    *(uint32_t*)(cpu->esi + 0x1E4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1E8u);
    *(uint32_t*)(cpu->esi + 0x1E8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1ECu);
    *(uint32_t*)(cpu->esi + 0x1ECu) = cpu->edx;
    cpu->eax = *(uint8_t*)(cpu->edi + 0x1F0u);
    *(uint8_t*)(cpu->esi + 0x1F0u) = cpu->eax & 0xFFu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A4620(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x200u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1FCu);
    if (cpu->eax == cpu->ecx) goto label_000A4664;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4642u)); sfera_sub_004A3DB0(cpu, LIFT_CODE_TOKEN_VA(0x4A4642u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x200u);
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x208u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A465Du)); sfera_sub_004A3EF0(cpu, LIFT_CODE_TOKEN_VA(0x4A465Du));
    *(uint32_t*)(cpu->esi + 0x200u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    label_000A4664:
    *(uint32_t*)(cpu->esi + 0x20Cu) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A4680(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x3Cu;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->eax = 0u;
    if (cpu->ebx != cpu->eax) goto label_000A4737;
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    if (cpu->ebp != cpu->eax) goto label_000A46E1;
    cpu->ebp = (uintptr_t)" ";
    label_000A46E1:
    cpu->eax = cpu->ebp;
    cpu->edx = cpu->eax + 1u;
    label_000A46E6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A46E6;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A46FAu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4A46FAu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->edx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    cpu->ecx = cpu->esi + 0x1FCu;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A471Au)); sfera_sub_004A43D0(cpu, LIFT_CODE_TOKEN_VA(0x4A471Au));
    if (*(uint32_t*)(cpu->esp + 0x28u) < 0x10u) goto label_000A4870;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A472Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A472Fu));
    cpu->esp += 4u;
    goto label_000A4870;
    label_000A4737:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x200u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1FCu);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    if (cpu->ecx >= cpu->ebx) goto label_000A47F4;
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x24u) = 0u;
    *(uint8_t*)(cpu->esp + 0x14u) = 0u;
    cpu->ebx = 1u;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebx;
    if (cpu->ebp != 0u) goto label_000A4783;
    cpu->ebp = (uintptr_t)" ";
    label_000A4783:
    cpu->eax = cpu->ebp;
    cpu->edx = cpu->eax + 1u;
    label_000A4788:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A4788;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A479Cu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4A479Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x1FCu;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A47BCu)); sfera_sub_004A43D0(cpu, LIFT_CODE_TOKEN_VA(0x4A47BCu));
    *(uint32_t*)(cpu->esi + 0x20Cu) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x20Cu)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20Cu);
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0x1B0u)) goto label_000A47DA;
    *(uint32_t*)(cpu->esi + 0x20Cu) = 0u;
    label_000A47DA:
    if (*(uint32_t*)(cpu->esp + 0x28u) < 0x10u) goto label_000A4870;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A47EFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A47EFu));
    cpu->esp += 4u;
    goto label_000A4870;
    label_000A47F4:
    if (cpu->ebp != 0u) goto label_000A47FD;
    cpu->ebp = (uintptr_t)" ";
    label_000A47FD:
    cpu->eax = cpu->ebp;
    cpu->edx = cpu->eax + 1u;
    label_000A4802:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A4802;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1FCu);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20Cu);
    cpu->eax = cpu->eax + (cpu->eax * 8u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->ecx + (cpu->eax * 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4824u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4A4824u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->edx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1FCu);
    *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x20u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->edx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1FCu);
    *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x1Cu) = cpu->ecx;
    ++*(uint32_t*)(cpu->esi + 0x20Cu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20Cu);
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0x1B0u)) goto label_000A4870;
    *(uint32_t*)(cpu->esi + 0x20Cu) = 0u;
    label_000A4870:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A48A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ecx;
    cpu->eax -= 0x1965u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == 0u) goto label_000A4998;
    if ((--cpu->eax) == 0u) goto label_000A497E;
    if ((--cpu->eax) == 0u) goto label_000A48DA;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A48D3u)); sfera_sub_004C08C0(cpu, LIFT_CODE_TOKEN_VA(0x4A48D3u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A48DA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    if (*(uint32_t*)(cpu->esi + 0x1F8u) == cpu->eax) goto label_000A4972;
    *(uint32_t*)(cpu->esi + 0x1F8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x200u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1FCu);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    if ((cpu->eax += cpu->edx) == 0u) goto label_000A4972;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4916u)); sfera_sub_004C0170(cpu, LIFT_CODE_TOKEN_VA(0x4A4916u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x200u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1FCu);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x38E38E39u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if ((int32_t)cpu->eax <= 0) goto label_000A4972;
    cpu->edi = 0u;
    cpu->ebx = cpu->eax;
    cpu->ebp = cpu->edi + 0x10u;
    label_000A4940:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1FCu);
    cpu->edx = *(uint32_t*)(cpu->edi + cpu->ecx + 0x1Cu);
    cpu->eax = cpu->edi + cpu->ecx;
    if (((*(uint32_t*)(cpu->esi + 0x1F8u)) & (cpu->edx)) == 0u) goto label_000A496C;
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebp) goto label_000A495E;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000A4960;
    label_000A495E:
    cpu->ecx = cpu->eax;
    label_000A4960:
    cpu->eax = *(uint32_t*)(cpu->eax + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA496Cu)); sfera_sub_004C0590(cpu, LIFT_CODE_TOKEN_RVA(0xA496Cu));
    label_000A496C:
    cpu->edi += 0x24u;
    if ((--cpu->ebx) != 0u) goto label_000A4940;
    label_000A4972:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A497E:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4985u)); sfera_sub_004A4620(cpu, LIFT_CODE_TOKEN_VA(0x4A4985u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A498Cu)); sfera_sub_004C0170(cpu, LIFT_CODE_TOKEN_VA(0x4A498Cu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A4998:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->ebp == 0u) goto label_000A4972;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = cpu->eax;
    cpu->eax&=0xFFFFFFu;
    cpu->edi >>= 24u;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A49BAu)); sfera_sub_004A4680(cpu, LIFT_CODE_TOKEN_VA(0x4A49BAu));
    if (((*(uint32_t*)(cpu->esi + 0x1F8u)) & (cpu->edi)) == 0u) goto label_000A4972;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0xE11u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A49D0u)); sfera_sub_004C08C0(cpu, LIFT_CODE_TOKEN_VA(0x4A49D0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A49E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->edi = cpu->ecx;
    cpu->edx = 0x48u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\FilterListCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4A15u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A4A15u));
    lift_push32(cpu, 0x210u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4A1Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A4A1Fu));
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    if (cpu->esi == cpu->ebx) goto label_000A4A6A;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4A39u)); sfera_sub_004BFB90(cpu, LIFT_CODE_TOKEN_VA(0x4A4A39u));
    std::construct_at(reinterpret_cast<SphereUI::FilterListCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x1F8u) = 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1FCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x200u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x204u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x20Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x50u) = 0x12u;
    goto label_000A4A6C;
    label_000A4A6A:
    cpu->esi = 0u;
    label_000A4A6C:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4A7Cu)); sfera_sub_004A44F0(cpu, LIFT_CODE_TOKEN_VA(0x4A4A7Cu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1F8u);
    cpu->ecx = cpu->edi + 0x1FCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x1FCu;
    *(uint32_t*)(cpu->esi + 0x1F8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4A9Au)); sfera_sub_004A4250(cpu, LIFT_CODE_TOKEN_VA(0x4A4A9Au));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x20Cu);
    *(uint32_t*)(cpu->esi + 0x20Cu) = cpu->edx;
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0xECu) == cpu->ebx) goto label_000A4ACD;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA4ACDu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xA4ACDu));
    label_000A4ACD:
    if (*(uint32_t*)(cpu->edi + 0x1D0u) == cpu->ebx) goto label_000A4AF0;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1D0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA4AF0u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xA4AF0u));
    label_000A4AF0:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A4B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = 0x1B4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4B1Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A4B1Fu));
    lift_push32(cpu, 0x9600u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4B29u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A4B29u));
    cpu->esp += 4u;
    g_sfera_font_factory_runtime.vertex_buffer = cpu->eax;
    if (cpu->eax != 0u) goto label_000A4B48;
    lift_push32(cpu, (uintptr_t)"Can't initialize vertex buffer for font factory.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4B3Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A4B3Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4B45u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A4B45u));
    cpu->esp += 8u;
    label_000A4B48:
    g_sfera_font_factory_runtime.vertex_count = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A4B60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->edi == 0u) goto label_000A4BAC;
    cpu->edx = 0x39Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4B7Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A4B7Fu));
    cpu->eax = cpu->edi;
    cpu->edx = cpu->eax + 1u;
    label_000A4B84:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A4B84;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4B94u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A4B94u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->eax;
    label_000A4BA0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000A4BA0;
    goto label_000A4BB3;
    label_000A4BAC:
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    label_000A4BB3:
    if (cpu->ebx == 0u) goto label_000A4BCF;
    cpu->edx = 0x3A1u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4BC6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A4BC6u));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4BCCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A4BCCu));
    cpu->esp += 4u;
    label_000A4BCF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A4BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x110u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x114u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x120u);
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x128u);
    lift_push32(cpu, (uintptr_t)"rb"); lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4A4C1Cu));
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->edi != 0u) goto label_000A4C46;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Can't open font '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4C36u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A4C36u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4C3Cu)); sfera_sub_0042E480(cpu, LIFT_CODE_TOKEN_VA(0x4A4C3Cu));
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    goto label_000A4D8F;
    label_000A4C46:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x4A4C58u));
    cpu->esp += 0x10u;
    if (*(uint32_t*)(cpu->esp + 0xCu) == 0x544E4653u) goto label_000A4C7C;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4A4C6Cu));
    cpu->esp += 4u;
    cpu->eax = 0u;
    goto label_000A4D8F;
    label_000A4C7C:
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::fgetc);
    cpu->ebp = 0u;
    label_000A4C85:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fgetc)))(cpu->edi);

    *(uint8_t*)(cpu->esp + cpu->ebp + 0x1Cu) = cpu->eax & 0xFFu;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000A4C9C;
    ++cpu->ebp;
    if (cpu->ebp != 0x100u) goto label_000A4C85;
    label_000A4C9C:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = cpu->ebx;
    if (cpu->eax != 0u) goto label_000A4CAA;
    cpu->eax = cpu->esp + 0x1Cu;
    label_000A4CAA:
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4CB0u)); sfera_sub_004A4B60(cpu, LIFT_CODE_TOKEN_VA(0x4A4CB0u));
    cpu->ebp = 0u;
    label_000A4CB2:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fgetc)))(cpu->edi);

    if ((cpu->eax & 0xFFu) == 0u) goto label_000A4CC5;
    ++cpu->ebp;
    if (cpu->ebp != 0x100u) goto label_000A4CB2;
    label_000A4CC5:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4CD0u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x4A4CD0u));
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_000A4CFD;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"Can't load texture '%s' for font '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4CE6u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A4CE6u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4CECu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A4CECu));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4A4CEDu));
    cpu->esp += 0x14u;
    cpu->eax = 0u;
    goto label_000A4D8E;
    label_000A4CFD:
    cpu->esi = native_function_address32(&::fread);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->edx = cpu->ebx + 0xCu;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->edx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fread)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u), *(uint32_t*)(cpu->esp + 0xCu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->ebp = cpu->ebx + 0x10u;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->ebp);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fread)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u), *(uint32_t*)(cpu->esp + 0xCu));
    cpu->esp += 0x20u;
    cpu->edx = 0x3DBu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4D2Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A4D2Bu));
    lift_push32(cpu, 0x1C00u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4D35u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A4D35u));
    lift_push32(cpu, 0x1C00u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A4D40u));
    cpu->esp += 0x10u;
    cpu->esi = 0x380u;
    label_000A4D50:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x4A4D5Bu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->ebp));
    *(uint16_t*)(cpu->esi + cpu->ecx + 6u) = (uint64_t)(*(uint16_t*)(cpu->esi + cpu->ecx + 6u)) - (uint64_t)((cpu->edx & 0xFFFFu)) - (uint64_t)(0u);
    cpu->eax = cpu->esi + cpu->ecx + 6u;
    cpu->esi += 0x1Cu;
    cpu->esp += 0x10u;
    if (cpu->esi < 0x1C00u) goto label_000A4D50;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4A4D80u));
    cpu->esp += 4u;
    cpu->eax = 1u;
    label_000A4D8E:
    cpu->esi = lift_pop32(cpu);
    label_000A4D8F:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x110u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A4DB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 4u) == 0u) goto label_000A4DD4;
    cpu->edx = 0x38Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4DC8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A4DC8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4DD1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A4DD1u));
    cpu->esp += 4u;
    label_000A4DD4:
    if (*(uint32_t*)(cpu->esi + 8u) == 0u) goto label_000A4DF5;
    cpu->edx = 0x38Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4DE9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A4DE9u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4DF2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A4DF2u));
    cpu->esp += 4u;
    label_000A4DF5:
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000A4E05;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4E02u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A4E02u));
    cpu->esp += 4u;
    label_000A4E05:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A4E10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6;
    bool lift_cmp[1];
    cpu->esp -= 0x4Cu;
    x87_v0 = (double)*(float*)(cpu->esp + 0x54u);
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    x87_v1 = (double)(((int32_t)(g_sfera_screen_clip_runtime.bottom)));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u));
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    lift_cmp[0]=x87_v1<x87_v0;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    if (lift_cmp[0]) goto label_000A5250;
    x87_v0 = (x87_v0) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0xCu)))));
    x87_v1 = (double)(((int32_t)(g_sfera_screen_clip_runtime.top)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (lift_left>=lift_right) goto label_000A5252; }
    if (*(uint8_t*)(cpu->esp + 0x60u) == 0u) goto label_000A4E62;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA4E62u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xA4E62u));
    label_000A4E62:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4E71u)); sfera_sub_0044FCB0(cpu, LIFT_CODE_TOKEN_VA(0x4A4E71u));
    cpu->edx = g_sfera_font_factory_runtime.vertex_count;
    if (cpu->edx >= 0x4ACu) goto label_000A4E90;
    cpu->edi = cpu->edx;
    cpu->edx <<= 5u;
    cpu->edx += g_sfera_font_factory_runtime.vertex_buffer;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    goto label_000A4EA3;
    label_000A4E90:
    cpu->edx = g_sfera_font_factory_runtime.vertex_buffer;
    cpu->eax = 0u;
    g_sfera_font_factory_runtime.vertex_count = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->edi = cpu->eax;
    label_000A4EA3:
    x87_v0 = (double)*(float*)(cpu->esp + 0x60u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x68u);
    x87_v1 = 0.5;
    cpu->ebx = 0u;
    x87_v0 = (x87_v0) - (x87_v1);
    cpu->ebp = 0u;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x60u) = x87_v1; 
    x87_v0 = (((double)*(float*)(cpu->esp + 0x64u))) - (x87_v0);
    *(float*)(cpu->esp + 0x64u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x60u);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    if (*(uint8_t*)(cpu->esi) == (cpu->ebx & 0xFFu)) goto label_000A5236;
    x87_v1 = 0.0;
    x87_v2 = 1.0;
    goto label_000A4EDD;
    label_000A4EDB:
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    label_000A4EDD:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    if ((cpu->eax & 0xFFu) != 0xAu) goto label_000A4F0A;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = x87_v2; 
    *(float*)(cpu->esp + 0x60u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x64u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->ecx + 0xCu)))))) + (((double)*(float*)(cpu->esp + 0x64u))));
    x87_v2 = (double)*(float*)(cpu->esp + 0x60u);
    goto label_000A51EA;
    label_000A4F0A:
    sub_pred[0] = (uint8_t)(cpu->eax) == 0x20u;
    if ((uint8_t)(cpu->eax) < 0x20u) goto label_000A51F7;
    if (!sub_pred[0]) goto label_000A4F3B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = (int16_t)(*(uint16_t*)(cpu->ecx + 0x388u));
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->eax;
    x87_v3 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x60u))));
    x87_v0 = x87_v0 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x60u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x60u);
    goto label_000A51EA;
    label_000A4F3B:
    cpu->eax = cpu->eax & 0xFFu;
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = cpu->eax + (cpu->ecx * 4u);
    cpu->eax = *(uint16_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    x87_v3 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x68u))));
    x87_v4 = x87_v0;
    x87_v4 = (x87_v4) + (x87_v3);
    x87_v5 = (double)(((int32_t)(g_sfera_screen_clip_runtime.left)));
    { const double lift_left=x87_v5; const double lift_right=x87_v4;   if (!(lift_left>=lift_right)) goto label_000A4F92; }
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->ecx + 8u));
    x87_v3 = x87_v3; 
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ecx;
    x87_v3 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x60u))));
    x87_v0 = x87_v0 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x60u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x60u);
    goto label_000A51EA;
    label_000A4F92:
    { const double lift_left=(double)(((int32_t)(g_sfera_screen_clip_runtime.right))); const double lift_right=x87_v0; if (lift_left<lift_right) goto label_000A51FB; }
    cpu->eax = (int16_t)(*(uint16_t*)(cpu->ecx + 4u));
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->eax;
    cpu->eax = (int16_t)(*(uint16_t*)(cpu->ecx + 6u));
    x87_v4 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x68u))));
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->ecx + 2u);
    x87_v0 = x87_v0 + x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->esp + 0x50u) = 0u;
    *(float*)(cpu->esp + 0x20u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x64u);
    x87_v4 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x68u))));
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v3 = x87_v3 - x87_v4; 
    *(float*)(cpu->esp + 0x24u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x20u); x87_v4 = x87_v3;
    x87_v0 = x87_v0 + x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x20u) = x87_v3; 
    x87_v3 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x68u))));
    x87_v4 = (double)*(float*)(cpu->esp + 0x24u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 + x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x2Cu) = x87_v4; 
    *(float*)(cpu->esp + 0x68u) = (double)*(float*)(cpu->ecx + 0xCu);
    *(float*)(cpu->esp + 0x28u) = (double)*(float*)(cpu->ecx + 0x14u);
    *(float*)(cpu->esp + 0x24u) = (double)*(float*)(cpu->ecx + 0x10u);
    x87_v4 = (double)*(float*)(cpu->ecx + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0x30u) = x87_v4; 
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ecx;
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x3Cu) = x87_v3;
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x40u) = x87_v3;
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x44u) = x87_v3;
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x48u) = x87_v3;
    x87_v4 = (double)*(float*)(cpu->esp + 0x68u);
    *(float*)(cpu->esp + 0x54u) = x87_v4;
    x87_v5 = (double)*(float*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x58u) = x87_v5;
    std::memmove((void*)(cpu->edx),(void*)(cpu->esp + 0x3Cu),32u);
    x87_v6 = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 0x3Cu) = x87_v6;
    { double temporary = x87_v6; x87_v6 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x40u) = x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x44u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x48u) = x87_v5;
    x87_v6 = (double)*(float*)(cpu->esp + 0x28u);
    *(float*)(cpu->esp + 0x54u) = x87_v6;
    { double temporary = x87_v6; x87_v6 = x87_v2; x87_v2 = temporary; }
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    *(float*)(cpu->esp + 0x58u) = x87_v6; 
    *(uint32_t*)(cpu->esp + 0x50u) = 0u;
    { double temporary = x87_v5; x87_v5 = x87_v0; x87_v0 = temporary; }
    std::memmove((void*)(cpu->edx + 0x20u),(void*)(cpu->esp + 0x3Cu),32u);
    *(float*)(cpu->esp + 0x3Cu) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x2Cu);
    *(float*)(cpu->esp + 0x40u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x44u) = x87_v5;
    { double temporary = x87_v5; x87_v5 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x48u) = x87_v5;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x50u) = 0u;
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->esp + 0x54u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x30u);
    *(float*)(cpu->esp + 0x58u) = x87_v5;
    std::memmove((void*)(cpu->edx + 0x40u),(void*)(cpu->esp + 0x3Cu),32u);
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x3Cu) = x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x40u) = x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x44u) = x87_v3;
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x48u) = x87_v3;
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x54u) = x87_v3; 
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    cpu->edi = cpu->edx + 0x60u;
    *(float*)(cpu->esp + 0x58u) = x87_v2; 
    cpu->eax = cpu->ebx + 2u;
    cpu->esi = cpu->esp + 0x3Cu;
    *(uint32_t*)(cpu->esp + 0x50u) = 0u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),32u); cpu->esi += 32u; cpu->edi += 32u;
    *(uint16_t*)((cpu->ebp * 2u) + ((uintptr_t)&g_sfera_font_factory_runtime.quad_indices[0])) = cpu->eax & 0xFFFFu;
    cpu->eax = cpu->ebx + 3u;
    *(uint16_t*)((cpu->ebp * 2u) + ((uintptr_t)&g_sfera_font_factory_runtime.quad_indices[2])) = cpu->eax & 0xFFFFu;
    *(uint16_t*)((cpu->ebp * 2u) + ((uintptr_t)&g_sfera_font_factory_runtime.quad_indices[4])) = cpu->eax & 0xFFFFu;
    cpu->eax = g_sfera_font_factory_runtime.vertex_count;
    cpu->ecx = cpu->ebx + 1u;
    *(uint16_t*)((cpu->ebp * 2u) + ((uintptr_t)&g_sfera_font_factory_runtime.quad_indices[1])) = cpu->ebx & 0xFFFFu;
    *(uint16_t*)((cpu->ebp * 2u) + ((uintptr_t)&g_sfera_font_factory_runtime.quad_indices[5])) = cpu->ebx & 0xFFFFu;
    cpu->eax += 4u;
    *(uint16_t*)((cpu->ebp * 2u) + ((uintptr_t)&g_sfera_font_factory_runtime.quad_indices[3])) = cpu->ecx & 0xFFFFu;
    cpu->edx -= 0xFFFFFF80u;
    cpu->ebx += 4u;
    cpu->ebp += 6u;
    g_sfera_font_factory_runtime.vertex_count = cpu->eax;
    if (cpu->eax <= 0x4AAu) goto label_000A51C0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = x87_v1; 
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    x87_v0 = x87_v0; 
    lift_push32(cpu, 0x20u);
    cpu->edx <<= 5u;
    cpu->edx += g_sfera_font_factory_runtime.vertex_buffer;
    cpu->eax = 0xAAAAAAABu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(((uint64_t)cpu->eax * (uint32_t)(cpu->ebp)) >> 32u);
    lift_push32(cpu, 0x65u); lift_push32(cpu, (uintptr_t)&g_sfera_font_factory_runtime.quad_indices[0]);
    cpu->edx >>= 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A51AAu)); sfera_sub_004D8FE0(cpu, LIFT_CODE_TOKEN_VA(0x4A51AAu));
    cpu->edx = g_sfera_font_factory_runtime.vertex_buffer;
    x87_v0 = 0.0;
    g_sfera_font_factory_runtime.vertex_count = cpu->ebx;
    x87_v1 = 1.0;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ebp = 0u;
    label_000A51C0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax + 8u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->ecx;
    *(float*)(cpu->esp + 0x60u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x68u)))))) + (((double)*(float*)(cpu->esp + 0x60u))));
    x87_v2 = (double)*(float*)(cpu->esp + 0x60u);
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    label_000A51EA:
    if (*(uint8_t*)(cpu->esi) != 0u) goto label_000A4EDB;
    x87_v1 = x87_v2; 
    goto label_000A51FF;
    label_000A51F7:
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    goto label_000A51EA;
    label_000A51FB:
    x87_v1 = x87_v3; 
    x87_v2 = x87_v2; 
    label_000A51FF:
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    if (cpu->ebx==0u) goto label_000A5238;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    cpu->eax = 0xAAAAAAABu;
    lift_push32(cpu, 0x20u);
    cpu->edx = (uint32_t)(((uint64_t)cpu->eax * (uint32_t)(cpu->ebp)) >> 32u);
    cpu->edi <<= 5u;
    cpu->edi += g_sfera_font_factory_runtime.vertex_buffer;
    cpu->edx >>= 1u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x65u); lift_push32(cpu, (uintptr_t)&g_sfera_font_factory_runtime.quad_indices[0]); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5234u)); sfera_sub_004D8FE0(cpu, LIFT_CODE_TOKEN_VA(0x4A5234u));
    goto label_000A5238;
    label_000A5236:
    x87_v0 = x87_v0; 
    label_000A5238:
    sub_pred[1] = *(uint8_t*)(cpu->esp + 0x6Cu) == 0u;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (sub_pred[1]) goto label_000A5252;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5249u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_VA(0x4A5249u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000A5250:
    x87_v0 = x87_v0; 
    label_000A5252:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A5260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_font_factory_runtime.fonts_end;
    cpu->eax -= g_sfera_font_factory_runtime.fonts_begin;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A5270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_font_factory_runtime.fonts_end;
    cpu->ecx -= cpu->eax;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->esi;
    if (cpu->ecx > cpu->edx) goto label_000A5299;
    lift_push32(cpu, (uintptr_t)"invalid vector<T> subscript");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A5270u), "std::out_of_range");
    label_000A5299:
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edx * 4u));
    cpu->eax = cpu->esi;
    cpu->esi = cpu->eax + 1u;
    label_000A52A1:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000A52A1;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = 0u;
    cpu->esi = 0u;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->ebp) = cpu->ebx;
    if ((int32_t)cpu->eax <= 0) goto label_000A52EF;
    label_000A52C2:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + cpu->edx));
    if ((cpu->edx & 0xFFu) != 0xB8u) goto label_000A530C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (0xE5u & 0xFFu);
    label_000A52D0:
    cpu->edx = cpu->edx & 0xFFu;
    cpu->eax = cpu->edx * 8u;
    cpu->eax -= cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = (int16_t)(*(uint16_t*)(cpu->edx + (cpu->eax * 4u) + 8u));
    cpu->esi += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    label_000A52EA:
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)cpu->eax) goto label_000A52C2;
    label_000A52EF:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx += cpu->ebx;
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    if (cpu->esi <= *(uint32_t*)(cpu->ebp)) goto label_000A5302;
    *(uint32_t*)(cpu->ebp) = cpu->esi;
    label_000A5302:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000A530C:
    if ((cpu->edx & 0xFFu) != 0xA8u) goto label_000A5315;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (0xC5u & 0xFFu);
    goto label_000A52D0;
    label_000A5315:
    if ((cpu->edx & 0xFFu) != 0xAu) goto label_000A52D0;
    cpu->ebx += *(uint32_t*)(cpu->ecx + 0xCu);
    if (cpu->esi <= *(uint32_t*)(cpu->ebp)) goto label_000A5325;
    *(uint32_t*)(cpu->ebp) = cpu->esi;
    label_000A5325:
    cpu->esi = 0u;
    goto label_000A52EA;
}
__declspec(noinline) void sfera_sub_004A5330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    *(uint32_t*)(cpu->esp) = cpu->ecx;
    cpu->ecx = g_sfera_font_factory_runtime.fonts_end;
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    if (cpu->ecx > cpu->esi) goto label_000A535E;
    lift_push32(cpu, (uintptr_t)"invalid vector<T> subscript");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A5330u), "std::out_of_range");
    label_000A535E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->esi = 0u;
    cpu->ebp = 0u;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    if ((int32_t)cpu->edx <= 0) goto label_000A53A0;
    label_000A5374:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + cpu->eax));
    if ((cpu->eax & 0xFFu) != 0xB8u) goto label_000A53BB;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (0xE5u & 0xFFu);
    label_000A5381:
    cpu->eax = cpu->eax & 0xFFu;
    cpu->edx = cpu->eax * 8u;
    cpu->edx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = (int16_t)(*(uint16_t*)(cpu->eax + (cpu->edx * 4u) + 8u));
    cpu->esi += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    label_000A539B:
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)cpu->edx) goto label_000A5374;
    label_000A53A0:
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax += cpu->ebp;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (cpu->esi <= *(uint32_t*)(cpu->ecx)) goto label_000A53B4;
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    label_000A53B4:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A53BB:
    if ((cpu->eax & 0xFFu) != 0xA8u) goto label_000A53C3;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (0xC5u & 0xFFu);
    goto label_000A5381;
    label_000A53C3:
    if ((cpu->eax & 0xFFu) != 0xAu) goto label_000A5381;
    cpu->ebp += *(uint32_t*)(cpu->edi + 0xCu);
    if (cpu->esi <= *(uint32_t*)(cpu->ecx)) goto label_000A53D0;
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    label_000A53D0:
    cpu->esi = 0u;
    goto label_000A539B;
}
__declspec(noinline) void sfera_sub_004A53E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_font_factory_runtime.fonts_end;
    cpu->esi -= cpu->eax;
    cpu->esi = (int32_t)(cpu->esi) >> 2u;
    if (cpu->esi > cpu->edx) goto label_000A5400;
    lift_push32(cpu, (uintptr_t)"invalid vector<T> subscript");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A53E0u), "std::out_of_range");
    label_000A5400:
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->edx * 4u));
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if ((cpu->ecx & 0xFFu) != 0xB8u) goto label_000A5425;
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax + 0x1914u));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000A5425:
    if ((cpu->ecx & 0xFFu) != 0xA8u) goto label_000A543B;
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax + 0x1594u));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000A543B:
    cpu->ecx = cpu->ecx & 0xFFu;
    cpu->edx = cpu->ecx * 8u;
    cpu->edx -= cpu->ecx;
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax + (cpu->edx * 4u) + 8u));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A5460(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->ecx = g_sfera_font_factory_runtime.fonts_end;
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->edi = 0u;
    if (cpu->edx == 0u) goto label_000A54E9;
    label_000A5480:
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    if (cpu->esi == 0u) goto label_000A54DD;
    if (*(uint32_t*)(cpu->esi + 4u) == 0u) goto label_000A54A8;
    cpu->edx = 0x38Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A549Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A549Cu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A54A5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A54A5u));
    cpu->esp += 4u;
    label_000A54A8:
    if (*(uint32_t*)(cpu->esi + 8u) == 0u) goto label_000A54C9;
    cpu->edx = 0x38Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A54BDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A54BDu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A54C6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A54C6u));
    cpu->esp += 4u;
    label_000A54C9:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A54CFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A54CFu));
    cpu->ecx = g_sfera_font_factory_runtime.fonts_end;
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    cpu->esp += 4u;
    label_000A54DD:
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    ++cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    if (cpu->edi < cpu->edx) goto label_000A5480;
    label_000A54E9:
    if (cpu->eax == cpu->ecx) goto label_000A5502;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4A54F3u));
    cpu->esp += 0xCu;
    g_sfera_font_factory_runtime.fonts_end = cpu->esi;
    label_000A5502:
    sub_pred[0] = (uint32_t)(g_sfera_font_factory_runtime.vertex_buffer) == 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000A5534;
    cpu->edx = 0x1EEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A551Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A551Cu));
    cpu->eax = g_sfera_font_factory_runtime.vertex_buffer;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5527u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A5527u));
    cpu->esp += 4u;
    g_sfera_font_factory_runtime.vertex_buffer = 0u;
    label_000A5534:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A5540(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebx = cpu->ecx;
    cpu->edx = 0x1C3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5558u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A5558u));
    lift_push32(cpu, 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A555Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A555Fu));
    cpu->ebp = 0u;
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebp) goto label_000A557E;
    *(uint32_t*)(cpu->eax) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ebp;
    cpu->esi = cpu->eax;
    goto label_000A5580;
    label_000A557E:
    cpu->esi = 0u;
    label_000A5580:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A558Eu)); sfera_sub_004A4BE0(cpu, LIFT_CODE_TOKEN_VA(0x4A558Eu));
    if (cpu->eax != 0u) goto label_000A55B6;
    cpu->edx = 0x1C6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A55A1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A55A1u));
    if (cpu->esi == cpu->ebp) goto label_000A55AE;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA55AEu)); sfera_sub_004A4DB0(cpu, LIFT_CODE_TOKEN_RVA(0xA55AEu));
    label_000A55AE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A55B6:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_font_factory_runtime.fonts_begin;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A55C5u)); sfera_sub_004BDF90(cpu, LIFT_CODE_TOKEN_VA(0x4A55C5u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A55D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A55D8u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4A55D8u));
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    std::construct_at(reinterpret_cast<SphereUI::FontPicker*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x50u) = 0x18u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A5600(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[0] = *(uint8_t*)(cpu->esi + 0x48u) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x48u);
    if (!sub_pred[0]) goto label_000A56CA;
    if (*(uint32_t*)(cpu->esi + 0x198u) == 0u) goto label_000A5637;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000A5637:
    if (*(uint32_t*)(cpu->esi + 0x19Cu) == 0u) goto label_000A564E;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000A564E:
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A565Au)); sfera_sub_004D32C0(cpu, LIFT_CODE_TOKEN_VA(0x4A565Au));
    if (cpu->eax != 1u) goto label_000A56CA;
    cpu->edi = 0x1DE4u;
    label_000A5664:
    if (*(uint32_t*)(cpu->esp + 0x2Cu) != 0x157Du) goto label_000A56B9;
    if (*(uint32_t*)(cpu->esi + 0x19Cu) == 0u) goto label_000A56B9;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax += 2u;
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->ecx += 2u;
    cpu->edx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA56B9u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xA56B9u));
    label_000A56B9:
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A56C5u)); sfera_sub_004D32C0(cpu, LIFT_CODE_TOKEN_VA(0x4A56C5u));
    if (cpu->eax == 1u) goto label_000A5664;
    label_000A56CA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A56E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000A579C;
    if (((*(uint8_t*)(cpu->esi + 0x24u)) & (2u)) != 0u) goto label_000A579C;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->ecx == 0u) goto label_000A5748;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    if (*(uint32_t*)(cpu->ecx + 0xDCu) == cpu->eax) goto label_000A573B;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 4u))));
    if ((int32_t)cpu->eax >= 0) goto label_000A5724;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000A5724:
    x87_v0 = (x87_v0) / (255.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000A573B:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000A5748:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    if (cpu->ecx == 0u) goto label_000A579C;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    if (*(uint32_t*)(cpu->ecx + 0xDCu) == cpu->eax) goto label_000A578B;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 4u))));
    if ((int32_t)cpu->eax >= 0) goto label_000A5774;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_000A5774:
    x87_v0 = (x87_v0) / (255.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000A578B:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A579C:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A57A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->edx;
    cpu->eax -= 0x1DE2u;
    lift_push32(cpu, cpu->esi);
    if (cpu->eax == 0u) goto label_000A57E4;
    if ((--cpu->eax) == 0u) goto label_000A57BB;
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    sfera_sub_004D2DD0(cpu, stop_address); return;
    label_000A57BB:
    if (*(uint32_t*)(cpu->ecx + 0x19Cu) == 0u) goto label_000A57F0;
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->esi == 0u) goto label_000A57F0;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x19Cu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->getFont(cpu);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A57E4:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    label_000A57F0:
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A5800(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x9Cu) == 0u;
    lift_push32(cpu, cpu->edi);
    if (!sub_pred[0]) goto label_000A582C;
    lift_push32(cpu, 0x66u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\FontPicker.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5823u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A5823u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5829u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A5829u));
    cpu->esp += 0x10u;
    label_000A582C:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax = cpu->esp + 0x20u;
    { const uint32_t __parser_arg_016_46_0 = static_cast<uint32_t>(cpu->eax);
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->getBlockRange(reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_46_0))); }
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x34u);
    { const uint32_t __parser_arg_016_47_0 = static_cast<uint32_t>(1u); const uint32_t __parser_arg_016_47_1 = static_cast<uint32_t>(cpu->ebp);
    cpu->ecx = cpu->esp + 0x10u;
    const uint32_t __parser_arg_016_47_2 = static_cast<uint32_t>(cpu->ecx); const uint32_t __parser_arg_016_47_3 = static_cast<uint32_t>((uintptr_t)"text");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findBlock(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_47_3)), reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_47_2)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_47_1)), static_cast<int32_t>(__parser_arg_016_47_0)) ? 1u : 0u; }
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->eax == 0u) goto label_000A587C;
    lift_push32(cpu, 2u); lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A586Eu)); sfera_sub_004D4230(cpu, LIFT_CODE_TOKEN_VA(0x4A586Eu));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA587Cu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xA587Cu));
    label_000A587C:
    { const uint32_t __parser_arg_016_48_0 = static_cast<uint32_t>(1u); const uint32_t __parser_arg_016_48_1 = static_cast<uint32_t>(cpu->ebp);
    cpu->eax = cpu->esp + 0x18u;
    const uint32_t __parser_arg_016_48_2 = static_cast<uint32_t>(cpu->eax); const uint32_t __parser_arg_016_48_3 = static_cast<uint32_t>((uintptr_t)"spinButton");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findBlock(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_016_48_3)), reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_48_2)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_48_1)), static_cast<int32_t>(__parser_arg_016_48_0)) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000A58B4;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x10u);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A58A6u)); sfera_sub_004D4230(cpu, LIFT_CODE_TOKEN_VA(0x4A58A6u));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA58B4u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xA58B4u));
    label_000A58B4:
    cpu->edx = cpu->esp + 0x20u;
    { const uint32_t __parser_arg_016_49_0 = static_cast<uint32_t>(cpu->edx);
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->setBlockRange(reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_016_49_0))); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A58D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::FontPicker*>(cpu->esi));
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x198u) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (sub_pred[0]) goto label_000A593B;
    cpu->edx = 0x82u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\FontPicker.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A591Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A591Eu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->ecx == 0u) goto label_000A5931;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000A5931:
    *(uint32_t*)(cpu->esi + 0x198u) = 0u;
    label_000A593B:
    if (*(uint32_t*)(cpu->esi + 0x19Cu) == 0u) goto label_000A5970;
    cpu->edx = 0x87u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\FontPicker.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5953u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A5953u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    if (cpu->ecx == 0u) goto label_000A5966;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000A5966:
    *(uint32_t*)(cpu->esi + 0x19Cu) = 0u;
    label_000A5970:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A597Fu)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4A597Fu));
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A5990(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x8Eu); lift_push32(cpu, (uintptr_t)"SphereUI::FontPicker::setFont"); lift_push32(cpu, (uintptr_t)"%s():%d font = %d");
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A59ADu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A59ADu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A59B3u)); sfera_sub_0042E480(cpu, LIFT_CODE_TOKEN_VA(0x4A59B3u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->esp += 0x14u;
    if (cpu->ecx == 0u) goto label_000A59C9;
    cpu->eax = cpu->edi + 0xFFFFFFFEu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA59C9u)); sfera_sub_004CD990(cpu, LIFT_CODE_TOKEN_RVA(0xA59C9u));
    label_000A59C9:
    if (*(uint32_t*)(cpu->esi + 0x19Cu) == 0u) goto label_000A59E0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    label_000A59E0:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A59E8u)); sfera_sub_004D1AC0(cpu, LIFT_CODE_TOKEN_VA(0x4A59E8u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A59F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x98u); lift_push32(cpu, (uintptr_t)"SphereUI::FontPicker::getFont"); lift_push32(cpu, (uintptr_t)"%s():%d font = %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5A0Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A5A0Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5A15u)); sfera_sub_0042E480(cpu, LIFT_CODE_TOKEN_VA(0x4A5A15u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->esp += 0x14u;
    if (cpu->ecx == 0u) goto label_000A5A2C;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5A27u)); sfera_sub_004CDA00(cpu, LIFT_CODE_TOKEN_VA(0x4A5A27u));
    cpu->eax += 2u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A5A2C:
    if (*(uint32_t*)(cpu->esi + 0x19Cu) == 0u) goto label_000A5A43;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->esi = lift_pop32(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->getFont(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A5A43:
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004D1B00(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004A5A50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5A58u)); sfera_sub_004A58D0(cpu, LIFT_CODE_TOKEN_VA(0x4A5A58u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000A5A68;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5A65u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A5A65u));
    cpu->esp += 4u;
    label_000A5A68:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A5A70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5A9Eu)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4A5A9Eu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    std::construct_at(reinterpret_cast<SphereUI::FontPicker*>(cpu->esi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5AB8u)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4A5AB8u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x198u);
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 0x198u) == 0u) goto label_000A5B15;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5AF4u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_VA(0x4A5AF4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5AF9u)); sfera_sub_004A5260(cpu, LIFT_CODE_TOKEN_VA(0x4A5AF9u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    --cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5B08u)); sfera_sub_004CD950(cpu, LIFT_CODE_TOKEN_VA(0x4A5B08u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA5B15u)); sfera_sub_004CD9D0(cpu, LIFT_CODE_TOKEN_RVA(0xA5B15u));
    label_000A5B15:
    if (*(uint32_t*)(cpu->edi + 0x19Cu) == 0u) goto label_000A5B55;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5B39u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_VA(0x4A5B39u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->getFont(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->eax -= 2u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA5B55u)); sfera_sub_004CD990(cpu, LIFT_CODE_TOKEN_RVA(0xA5B55u));
    label_000A5B55:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A5B70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    cpu->edx = 0x7Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\FontPicker.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5BA3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A5BA3u));
    lift_push32(cpu, 0x1A0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5BADu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A5BADu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->eax == 0u) goto label_000A5BD9;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5BC8u)); sfera_sub_004A5A70(cpu, LIFT_CODE_TOKEN_VA(0x4A5BC8u));
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A5BD9:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A5BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x90u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x94u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0xA0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    *(uint32_t*)(cpu->ecx) = 0u;
    cpu->edx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->ebp) = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->edx -= cpu->eax;
    label_000A5C32:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A5C32;
    cpu->edi = native_function_address32(&::strtok);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, (uintptr_t)","); lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strtok)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->ebx = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebx != 0u) goto label_000A5C71;
    lift_push32(cpu, 0x53u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5C68u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A5C68u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5C6Eu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A5C6Eu));
    cpu->esp += 0x10u;
    label_000A5C71:
    cpu->edx = cpu->esi;
    cpu->eax = cpu->ebx;
    cpu->edx -= cpu->ebx;
    label_000A5C77:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A5C77;
    lift_push32(cpu, (uintptr_t)","); lift_push32(cpu, 0u);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strtok)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_000A5D6A;
    cpu->ebx = native_function_address32(&::_stricmp);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"BOT");

    if (cpu->eax != 0u) goto label_000A5CB5;
    *(uint32_t*)(cpu->ebp) = 1u;
    goto label_000A5CCB;
    label_000A5CB5:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"MID");

    if (cpu->eax != 0u) goto label_000A5CCB;
    *(uint32_t*)(cpu->ebp) = 2u;
    label_000A5CCB:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strtok)))(0u, (uintptr_t)",");

    if (cpu->eax == 0u) goto label_000A5D6A;
    cpu->esi = native_function_address32(&::atoi);
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::atoi)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, (uintptr_t)","); lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strtok)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esp += 0xCu;
    if (cpu->eax == 0u) goto label_000A5D6A;
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::atoi)))(*(uint32_t*)(cpu->esp));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, (uintptr_t)","); lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strtok)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esp += 0xCu;
    if (cpu->eax!=0u) goto label_000A5D2D;
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->ebx & 0xFFu;
    cpu->ecx <<= 8u;
    cpu->ecx|=cpu->edx;
    cpu->ecx <<= 8u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_000A5D6A;
    label_000A5D2D:
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::atoi)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, (uintptr_t)","); lift_push32(cpu, 0u);
    cpu->ebx = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strtok)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esp += 0xCu;
    if (cpu->eax == 0u) goto label_000A5D6A;
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::atoi)))(*(uint32_t*)(cpu->esp));
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x1Cu);
    cpu->eax <<= 8u;
    cpu->eax|=cpu->ecx;
    cpu->eax <<= 8u;
    cpu->eax|=cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = cpu->ebx & 0xFFu;
    cpu->eax <<= 8u;
    cpu->esp += 4u;
    cpu->eax |= cpu->ecx;
    *(uint32_t*)(cpu->edx) = cpu->eax;
    label_000A5D6A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x90u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A5D90(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->esi != 0u) goto label_000A5D9A;
    cpu->eax = 0x7FFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A5D9A:
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"br");

    if (cpu->eax != 0u) goto label_000A5DB7;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A5DB7:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"cl");

    if (cpu->eax != 0u) goto label_000A5DCD;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A5DCD:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"l");

    if (cpu->eax != 0u) goto label_000A5DE3;
    cpu->eax = 3u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A5DE3:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"\\l");

    if (cpu->eax == 0u) goto label_000A5E01;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"/l");

    if (cpu->eax != 0u) goto label_000A5E08;
    label_000A5E01:
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A5E08:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"sp");

    if (cpu->eax != 0u) goto label_000A5E1E;
    cpu->eax = 5u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A5E1E:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"tab");

    if (cpu->eax != 0u) goto label_000A5E34;
    cpu->eax = 8u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A5E34:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"img");

    if (cpu->eax != 0u) goto label_000A5E4A;
    cpu->eax = 9u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A5E4A:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"t");

    if (cpu->eax != 0u) goto label_000A5E60;
    cpu->eax = 0xAu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A5E60:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"\\t");

    if (cpu->eax != 0u) goto label_000A5E76;
    cpu->eax = 0xBu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A5E76:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"/t");

    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax &= 0x7FFFFFF4u;
    cpu->eax += 0xBu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A5E90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->esi);
    if (cpu->edi == 0u) goto label_000A5EDC;
    cpu->edx = 0xF1u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5EAEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A5EAEu));
    cpu->eax = cpu->edi;
    cpu->edx = cpu->eax + 1u;
    label_000A5EB3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000A5EB3;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5EC3u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A5EC3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->eax;
    label_000A5ED0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000A5ED0;
    goto label_000A5EE2;
    label_000A5EDC:
    *(uint32_t*)(cpu->esi) = 0u;
    label_000A5EE2:
    if (cpu->ebx == 0u) goto label_000A5EFE;
    cpu->edx = 0xF7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5EF5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A5EF5u));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5EFBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A5EFBu));
    cpu->esp += 4u;
    label_000A5EFE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A5F10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ebx = 0u;
    if (cpu->esi == cpu->ebx) goto label_000A613B;
    if (*(uint8_t*)(cpu->esi) != 0x3Cu) goto label_000A613B;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0]);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A5F35u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    cpu->esp += 0xCu;
    cpu->edi = 0u;
    if ((cpu->eax & 0xFFu) == 0x3Eu) goto label_000A5F79;
    label_000A5F47:
    *(uint8_t*)(cpu->edi + ((uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0])) = cpu->eax & 0xFFu;
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)cpu->edi < (int32_t)0x80u) goto label_000A5F6B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"Invalid hypertext command: %s");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5F62u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4A5F62u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5F68u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4A5F68u));
    cpu->esp += 0xCu;
    label_000A5F6B:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) == (cpu->ebx & 0xFFu)) goto label_000A5FF3;
    if ((cpu->eax & 0xFFu) != 0x3Eu) goto label_000A5F47;
    label_000A5F79:
    cpu->eax = (uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0];
    cpu->edx = cpu->eax + 1u;
    label_000A5F81:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000A5F81;
    lift_push32(cpu, 0x100u);
    cpu->eax -= cpu->edx;
    cpu->edi = (uintptr_t)&g_sfera_hypertext_scratch_runtime.attribute_name[0];
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->esi = (uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0];
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A5F9Fu));
    cpu->esp += 0xCu;
    if ((uint8_t)(g_sfera_hypertext_scratch_runtime.command_text[0]) == (cpu->ebx & 0xFFu)) goto label_000A5FC2;
    (void)cpu;
    label_000A5FB0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) == 0x3Du) goto label_000A5FC7;
    if ((cpu->eax & 0xFFu) == 0x20u) goto label_000A5FBD;
    *(uint8_t*)(cpu->edi) = cpu->eax & 0xFFu;
    ++cpu->edi;
    label_000A5FBD:
    ++cpu->esi;
    if (*(uint8_t*)(cpu->esi) != (cpu->ebx & 0xFFu)) goto label_000A5FB0;
    label_000A5FC2:
    if (*(uint8_t*)(cpu->esi) != 0x3Du) goto label_000A5FDC;
    label_000A5FC7:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) == (cpu->ebx & 0xFFu)) goto label_000A5FDC;
    (void)cpu;
    label_000A5FD0:
    if ((cpu->eax & 0xFFu) != 0x20u) goto label_000A5FFB;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000A5FD0;
    label_000A5FDC:
    g_sfera_hypertext_scratch_runtime.command_text[0] = (uint8_t)((cpu->ebx & 0xFFu));
    label_000A5FE2:
    cpu->esi = (uintptr_t)&g_sfera_hypertext_scratch_runtime.attribute_name[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5FECu)); sfera_sub_004A5D90(cpu, LIFT_CODE_TOKEN_VA(0x4A5FECu));
    if (cpu->eax != 0x7FFFFFFFu) goto label_000A603C;
    label_000A5FF3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000A5FFB:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) == (cpu->ebx & 0xFFu)) goto label_000A5FDC;
    if ((cpu->eax & 0xFFu) != 0x22u) goto label_000A6024;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    ++cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0];
    if ((cpu->eax & 0xFFu) == (cpu->ebx & 0xFFu)) goto label_000A6020;
    label_000A6012:
    if ((cpu->eax & 0xFFu) == 0x22u) goto label_000A6020;
    ++cpu->esi;
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    ++cpu->ecx;
    if ((cpu->eax & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000A6012;
    label_000A6020:
    *(uint8_t*)(cpu->ecx) = cpu->ebx & 0xFFu;
    goto label_000A5FE2;
    label_000A6024:
    cpu->edx = (uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0];
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    label_000A6030:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000A6030;
    goto label_000A5FE2;
    label_000A603C:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax += 0xFFFFFFFEu;
    if (cpu->eax > 8u) goto label_000A6131;
    switch (cpu->eax) {
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
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4A6063u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esi) = (uint64_t)(*(uint32_t*)(cpu->esi)) | (uint64_t)(0xFF000000u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000A607C:
    cpu->eax = (uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0];
    cpu->esi += 8u;
    cpu->esi -= cpu->eax;
    label_000A6086:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->esi + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000A6086;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000A609A:
    cpu->eax = (uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0];
    cpu->esi += 8u;
    cpu->esi -= cpu->eax;
    label_000A60A4:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->esi + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000A60A4;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000A60B8:
    lift_push32(cpu, cpu->ebp);
    cpu->eax = cpu->esi + 4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_hypertext_scratch_runtime.command_text[0]);
    cpu->ecx = cpu->esi + 0x90u;
    cpu->edx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A60D0u)); sfera_sub_004A5BF0(cpu, LIFT_CODE_TOKEN_VA(0x4A60D0u));
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A60D8u)); sfera_sub_004B8250(cpu, LIFT_CODE_TOKEN_VA(0x4A60D8u));
    *(uint32_t*)(cpu->esi + 0x98u) = cpu->eax;
    if (cpu->eax == cpu->ebx) goto label_000A6130;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x90u);
    cpu->ebp = cpu->ebx;
    cpu->ebp = cpu->ebp >> 24u;
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((cpu->ebp + *(uint16_t*)(cpu->eax + 8u)) & 0xFFFFu);
    cpu->ecx = cpu->ebx;
    cpu->edx = cpu->ebx;
    cpu->edx >>= 8u;
    cpu->ebx = cpu->ebx & 0xFFu;
    cpu->ebx = (cpu->ebx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(*(uint16_t*)(cpu->eax + 4u)) + (uint64_t)(0u))) & 0xFFFFu);
    cpu->edx &= 0xFFu;
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((cpu->ebp + cpu->edx) & 0xFFFFu);
    cpu->ecx >>= 16u;
    cpu->ecx &= 0xFFu;
    cpu->ebp = cpu->ebp & 0xFFFFu;
    cpu->ebx = (cpu->ebx & 0xFFFF0000u) | ((cpu->ebx + cpu->ecx) & 0xFFFFu);
    cpu->eax = cpu->ebx & 0xFFFFu;
    cpu->ebp = cpu->ebp << 16u;
    cpu->ebp|=cpu->eax;
    cpu->edx <<= 16u;
    cpu->edx |= cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x94u) = cpu->edx;
    label_000A6130:
    cpu->ebp = lift_pop32(cpu);
    label_000A6131:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000A613B:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A6220(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = 0u;
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if ((int32_t)(cpu->ebx) < (int32_t)(2u)) goto label_000A6254;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x58u);
    cpu->edx = cpu->ebx + 0xFFFFFFFEu;
    cpu->edx >>= 1u;
    ++cpu->edx;
    cpu->ebp = cpu->edx + cpu->edx;
    label_000A6245:
    cpu->esi += *(uint32_t*)(cpu->eax);
    cpu->edi += *(uint32_t*)(cpu->eax + 4u);
    cpu->eax += 8u;
    if ((--cpu->edx) != 0u) goto label_000A6245;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000A6254:
    if (cpu->ebp >= cpu->ebx) goto label_000A625E;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x58u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ebp * 4u));
    label_000A625E:
    cpu->eax = cpu->edi + cpu->esi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax += cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A6270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_000A62C6;
    if (cpu->ecx > 0xDD67C8u) goto label_000A6298;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x128u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6291u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A6291u));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_000A62C6;
    label_000A6298:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA62C6u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xA62C6u));
    label_000A62C6:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A62D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    if (cpu->ecx == cpu->edx) goto label_000A62FC;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000A62E0:
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    cpu->ebx += 0x128u;
    cpu->eax += 0x128u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),296u); cpu->esi += 296u; cpu->edi += 296u; cpu->ecx = 0u;
    if (cpu->ebx != cpu->edx) goto label_000A62E0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000A62FC:
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A6300(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    if (cpu->edi != cpu->eax) goto label_000A631D;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000A631D:
    if (cpu->edi <= 0xDD67C8u) goto label_000A6330;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A631Du), "std::length_error");
    label_000A6330:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6339u)); sfera_sub_004A6270(cpu, LIFT_CODE_TOKEN_VA(0x4A6339u));
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x128u);
    cpu->edi += cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A6350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0xA4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A635Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A635Du));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000A638D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->edi == 0u) goto label_000A6386;
    lift_push32(cpu, cpu->esi);
    std::memmove((void*)(cpu->edi),(void*)(*(uint32_t*)(cpu->esp + 0x20u)),156u);
    cpu->esi = lift_pop32(cpu);
    label_000A6386:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000A638D:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A63BBu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4A63BBu));
    lift_trap(cpu, 0x4A63BBu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004A63C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi)) goto label_000A63F0;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A63E6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A63E6u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->esi + 4u);
    label_000A63F0:
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A6400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->ecx == cpu->edx) goto label_000A6431;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    label_000A6410:
    if (cpu->eax == 0u) goto label_000A641F;
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),296u); cpu->esi += 296u; cpu->edi += 296u; cpu->ecx = 0u;
    label_000A641F:
    cpu->ebx += 0x128u;
    cpu->eax += 0x128u;
    if (cpu->ebx != cpu->edx) goto label_000A6410;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000A6431:
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A6440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->ecx == cpu->edx) goto label_000A6471;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    label_000A6450:
    if (cpu->eax == 0u) goto label_000A645F;
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),296u); cpu->esi += 296u; cpu->edi += 296u; cpu->ecx = 0u;
    label_000A645F:
    cpu->ebx += 0x128u;
    cpu->eax += 0x128u;
    if (cpu->ebx != cpu->edx) goto label_000A6450;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000A6471:
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A6480(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0x24u)) goto label_000A6526;
    cpu->edx = 0x170u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A64BEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A64BEu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->eax += 0x64u;
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A64DAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A64DAu));
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx = (cpu->eax * 4u) + 0x190u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4A64EAu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4A64FCu));
    cpu->esp += 0x1Cu;
    cpu->edx = 0x173u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6513u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A6513u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A651Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A651Cu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x24u)) + (uint64_t)(0x64u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->edi;
    label_000A6526:
    cpu->edx = 0x178u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6535u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A6535u));
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A653Cu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A653Cu));
    cpu->edi = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    if (cpu->edi == 0u) goto label_000A65A4;
    lift_push32(cpu, 0xA4u);
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6562u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4A6562u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000A6576;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = cpu->edi;
    goto label_000A65A6;
    label_000A6576:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA65A4u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xA65A4u));
    label_000A65A4:
    cpu->eax = 0u;
    label_000A65A6:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->edx + (cpu->ecx * 4u)) = cpu->eax;
    ++*(uint32_t*)(cpu->esi + 0x20u);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A65D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3]; double x87_v0;
    cpu->esp -= 0x54u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if (cpu->ebx != 0xFFu) goto label_000A65F1;
    if (*(uint32_t*)(cpu->esi + 0x2Cu) >= 2u) goto label_000A65F1;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA65F1u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xA65F1u));
    label_000A65F1:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x68u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x6Cu);
    cpu->ebx <<= 24u;
    cpu->ecx = 0u;
    cpu->edx = cpu->edi + cpu->eax;
    cpu->edi += *(uint32_t*)(cpu->esp + 0x70u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    cpu->ebx |= 0xFFFFFFu;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x68u) = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint8_t*)(cpu->esp + 0x6Cu) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x20u) <= cpu->ecx) goto label_000A6A6F;
    lift_push32(cpu, cpu->ebp);
    label_000A6642:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x58u);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x68u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u));
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebp;
    if (cpu->ebp == cpu->eax) goto label_000A6922;
    label_000A6670:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax += 0xFFFFFFFEu;
    if (cpu->eax > 9u) goto label_000A68D7;
    switch (cpu->eax) {
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
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x98u);
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->ecx;
    label_000A6690:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebx &= 0xFFFFFFu;
    cpu->ebx |= cpu->eax;
    sub_pred[0] = *(uint8_t*)(cpu->esp + 0x6Cu) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (sub_pred[0]) goto label_000A68D7;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x128u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x30u);
    if (*(uint8_t*)(cpu->ecx + cpu->ebx + 0x125u) == 0u) goto label_000A66D9;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x54u);
    cpu->ebx &= 0xFFFFFFu;
    cpu->ebx |= cpu->eax;
    goto label_000A68D3;
    label_000A66D9:
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x50u);
    cpu->ebx &= 0xFFFFFFu;
    cpu->ebx |= cpu->eax;
    goto label_000A68D3;
    label_000A66E9:
    cpu->edi += *(uint32_t*)(cpu->ebp + 0xCu);
    goto label_000A68D7;
    label_000A66F1:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xA0u);
    if (cpu->ecx == 0u) goto label_000A6740;
    cpu->eax = *(uint16_t*)(cpu->ebp + 0x9Cu);
    cpu->eax += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->ebp + 0x9Eu);
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu))));
    cpu->esp -= 8u;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A673Cu)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_VA(0x4A673Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000A6740:
    cpu->ecx = *(uint16_t*)(cpu->ebp + 0x98u);
    cpu->edi += cpu->ecx;
    goto label_000A68D7;
    label_000A674E:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x40u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x128u);
    *(uint32_t*)(cpu->eax + cpu->ecx + 0x120u) = 0u;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->edx;
    *(uint8_t*)(cpu->esp + 0x70u) = 1u;
    goto label_000A68D7;
    label_000A677B:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x128u);
    *(uint32_t*)(cpu->ecx + cpu->eax + 0x120u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->ecx += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    sub_pred[1] = *(uint8_t*)(cpu->ecx + cpu->eax + 0x125u) == 0u;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    if (sub_pred[1]) goto label_000A67CC;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x54u);
    cpu->ebx &= 0xFFFFFFu;
    cpu->ebx |= *(uint32_t*)(cpu->esp + 0x28u);
    *(uint8_t*)(cpu->esp + 0x6Cu) = 1u;
    goto label_000A68D3;
    label_000A67CC:
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x50u);
    cpu->ebx &= 0xFFFFFFu;
    cpu->ebx |= *(uint32_t*)(cpu->esp + 0x28u);
    *(uint8_t*)(cpu->esp + 0x6Cu) = 1u;
    goto label_000A68D3;
    label_000A67E3:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x58u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->eax += *(uint32_t*)(cpu->esp + 0x58u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x128u);
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    *(uint8_t*)(cpu->eax + cpu->ecx + 0x124u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->ecx + 0x120u);
    cpu->eax += 8u;
    cpu->eax <<= 4u;
    cpu->eax += cpu->edx;
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x58u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ebx;
    ++*(uint32_t*)(cpu->edx + cpu->ecx + 0x120u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint8_t*)(cpu->esp + 0x70u) = 0u;
    goto label_000A68D7;
    label_000A684A:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x128u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ebp += *(uint32_t*)(cpu->esp + 0x48u);
    *(uint8_t*)(cpu->edx + cpu->ecx + 0x124u) = 1u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ebp += *(uint32_t*)(cpu->esp + 0x74u);
    cpu->edx = 2u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->edi;
    if (cpu->eax >= cpu->edx) goto label_000A6890;
    *(uint32_t*)(cpu->esp + 0x48u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x48u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    if (cpu->eax != 0u) goto label_000A6886;
    cpu->ebp += cpu->edx;
    goto label_000A6889;
    label_000A6886:
    cpu->ebp += 3u;
    label_000A6889:
    cpu->eax = cpu->edi + 2u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    label_000A6890:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->ecx + 0x120u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->eax += 8u;
    cpu->eax <<= 4u;
    cpu->eax += cpu->edx;
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ebp;
    ++*(uint32_t*)(cpu->edx + cpu->ecx + 0x120u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint8_t*)(cpu->esp + 0x6Cu) = 0u;
    label_000A68D3:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    label_000A68D7:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x90u);
    if (cpu->eax == 0u) goto label_000A690B;
    if (*(uint8_t*)(cpu->eax) == 0u) goto label_000A690B;
    x87_v0 = 0.0;
    cpu->edx += *(uint32_t*)(cpu->esp + 0x74u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6901u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4A6901u));
    cpu->edi += *(uint32_t*)(cpu->ebp + 0x94u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000A690B:
    cpu->ebp = *(uint32_t*)(cpu->ebp);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    sub_pred[2] = cpu->ebp == *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebp;
    if (!sub_pred[2]) goto label_000A6670;
    label_000A6922:
    if (*(uint8_t*)(cpu->esp + 0x6Cu) == 0u) goto label_000A69D4;
    if ((int32_t)cpu->edi <= (int32_t)*(uint32_t*)(cpu->esp + 0x44u)) goto label_000A69BB;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x128u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ebp += *(uint32_t*)(cpu->esp + 0x48u);
    *(uint8_t*)(cpu->edx + cpu->ecx + 0x124u) = 1u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->ebp += *(uint32_t*)(cpu->esp + 0x74u);
    cpu->edx = 2u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->edi;
    if (cpu->eax >= cpu->edx) goto label_000A697D;
    *(uint32_t*)(cpu->esp + 0x48u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x48u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    if (cpu->eax != 0u) goto label_000A6973;
    cpu->ebp += cpu->edx;
    goto label_000A6976;
    label_000A6973:
    cpu->ebp += 3u;
    label_000A6976:
    cpu->eax = cpu->edi + 2u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    label_000A697D:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->ecx + 0x120u);
    cpu->eax += 8u;
    cpu->eax <<= 4u;
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ebp;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    ++*(uint32_t*)(cpu->eax + cpu->ecx + 0x120u);
    label_000A69BB:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x68u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x74u);
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    label_000A69D4:
    if (*(uint8_t*)(cpu->esp + 0x70u) == 0u) goto label_000A6A52;
    if ((int32_t)cpu->edi <= (int32_t)*(uint32_t*)(cpu->esp + 0x54u)) goto label_000A6A3A;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x58u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->eax += *(uint32_t*)(cpu->esp + 0x58u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x128u);
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    *(uint8_t*)(cpu->eax + cpu->ecx + 0x124u) = 1u;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->ecx + cpu->ebp + 0x120u);
    cpu->eax += 8u;
    cpu->eax <<= 4u;
    cpu->eax += cpu->ebp;
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x58u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    ++*(uint32_t*)(cpu->ecx + cpu->ebp + 0x120u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000A6A3A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x68u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x58u);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u));
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    label_000A6A52:
    cpu->edx += *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if ((int32_t)cpu->edx > (int32_t)*(uint32_t*)(cpu->esp + 0x40u)) goto label_000A6A6E;
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if (cpu->ecx < *(uint32_t*)(cpu->esi + 0x20u)) goto label_000A6642;
    label_000A6A6E:
    cpu->ebp = lift_pop32(cpu);
    label_000A6A6F:
    if (*(uint32_t*)(cpu->esp + 0x74u) != 0xFFu) goto label_000A6A89;
    if (*(uint32_t*)(cpu->esi + 0x2Cu) >= 2u) goto label_000A6A89;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA6A89u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xA6A89u));
    label_000A6A89:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A6AC0(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    label_000A6B00:
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x10u)) goto label_000A6B76;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax += 8u;
    cpu->esi = cpu->ecx + 4u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6B1Au)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A6B1Au));
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000A6B34;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A6B00u), "std::length_error");
    label_000A6B34:
    ++cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->eax;
    goto label_000A6B00;
    label_000A6B76:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A6B49(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    if (cpu->esi == *(uint32_t*)(cpu->ebp + 0xCu)) goto label_000A6B6D;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    label_000A6B54:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6B66u)); sfera_sub_004A63C0(cpu, LIFT_CODE_TOKEN_VA(0x4A6B66u));
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(cpu->ebp + 0xCu)) goto label_000A6B54;
    label_000A6B6D:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6B76u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4A6B76u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A6B90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6BA7u)); sfera_sub_004A6350(cpu, LIFT_CODE_TOKEN_VA(0x4A6BA7u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 0x1A41A40u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000A6BC1;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4A6B90u), "std::length_error");
    label_000A6BC1:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A6BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6BFBu)); sfera_sub_004A6400(cpu, LIFT_CODE_TOKEN_VA(0x4A6BFBu));
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004A6C00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0x20u) <= cpu->edi) goto label_000A6C6A;
    lift_push32(cpu, cpu->ebx);
    label_000A6C10:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    if (*(uint32_t*)(cpu->eax + (cpu->edi * 4u)) == 0u) goto label_000A6C59;
    cpu->edx = 0x25Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\HyperText.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6C28u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A6C28u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    if (cpu->eax == 0u) goto label_000A6C4F;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->ebx = cpu->eax + 0xFFFFFFFCu;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00416610)); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xCu); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6C46u)); sfera_sub_004EEB86(cpu, LIFT_CODE_TOKEN_VA(0x4A6C46u));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6C4Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4A6C4Cu));
    cpu->esp += 4u;
    label_000A6C4F:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->eax + (cpu->edi * 4u)) = 0u;
    label_000A6C59:
    ++cpu->edi;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x20u)) goto label_000A6C10;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x20u) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000A6C6A:
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
