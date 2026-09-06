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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49E47Fu); throw std::length_error("std::length_error");
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E6B1u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x49E6B1u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49EC47u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x49EC47u));
    cpu->esp += 4u;
label_0009EC4A:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x88u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_ui_window_get_absolute_position(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::Window*>(static_cast<std::uintptr_t>(cpu->ecx))->getAbsolutePosition(*reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(*(uint32_t*)(cpu->esp + 4u))), *reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(*(uint32_t*)(cpu->esp + 8u)))); cpu->esp += 12u; cpu->eip = stop_address; }

__declspec(noinline) void sfera_sub_0049F1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_0009F227;
    if (cpu->ecx > 0x3FFFFFFFu) goto label_0009F1F9;
    cpu->eax = cpu->ecx * 4u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49F1F2u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x49F1F2u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FA84u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x49FA84u));
    cpu->esp += 4u;
    label_0009FA87:
    if (cpu->edi > cpu->ebx) goto label_0009FA70;
    label_0009FA8B:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = lift_pop32(cpu);
    if (cpu->eax == cpu->ebx) goto label_0009FA9C;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FA99u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x49FA99u));
    cpu->esp += 4u;
    label_0009FA9C:
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49FBD0u); throw std::length_error("std::length_error");
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49FD06u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x49FD06u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1881u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A1881u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    label_000A188B:
    if (*(uint32_t*)(cpu->esi + 0xCu) == 0u) goto label_000A18B3;
    cpu->edx = 0x6Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A18A0u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A18A0u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A18A9u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A18A9u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0xCu) = 0u;
    label_000A18B3:
    if (*(uint32_t*)(cpu->esi + 0x10u) == 0u) goto label_000A18DB;
    cpu->edx = 0x74u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A18C8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A18C8u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A18D1u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A18D1u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1901u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A1901u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    label_000A190B:
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0x88u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A191Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A191Bu));
    lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A1922u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A1922u));
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edi = 0u;
    label_000A1940:
    cpu->ecx = address32(sfera_cursor_texture_name(cpu->edi >> 2u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A194Bu)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x4A194Bu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edi + cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->edi + cpu->edx) != 0xFFFFFFFFu) goto label_000A1974;
    cpu->eax = address32(sfera_cursor_texture_name(cpu->edi >> 2u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A19A0u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A19A0u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    label_000A19A6:
    if (*(uint32_t*)(cpu->esi + 0x10u) != 0u) goto label_000A19CB;
    cpu->edx = 0x9Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Cursor.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A19BBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A19BBu));
    lift_push32(cpu, 0x114u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A19C5u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A19C5u));
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
__declspec(noinline) void sfera_ui_description_window_has_instance(LiftCpu* cpu, uint32_t stop_address) { cpu->eax = SphereUI::Runtime::descriptionWindow() != nullptr ? 1u : 0u; cpu->esp += 4u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_description_window_update(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::CDescriptionWindow*>(static_cast<std::uintptr_t>(cpu->ecx))->update(); cpu->esp += 4u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_description_window_instance(LiftCpu* cpu, uint32_t stop_address) { cpu->eax = address32(SphereUI::CDescriptionWindow::instance()); cpu->esp += 4u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_description_window_show_description(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::CDescriptionWindow*>(static_cast<std::uintptr_t>(cpu->ecx))->showDescription(reinterpret_cast<const char*>(static_cast<std::uintptr_t>(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u)))), *reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 8u)), *reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 12u)), *reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 16u)) != 0u); cpu->esp += 20u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_sub_004A4B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = 0x1B4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4B1Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A4B1Fu));
    lift_push32(cpu, 0x9600u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4B29u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A4B29u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4B94u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A4B94u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4BCCu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A4BCCu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4D35u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A4D35u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4DD1u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A4DD1u));
    cpu->esp += 4u;
    label_000A4DD4:
    if (*(uint32_t*)(cpu->esi + 8u) == 0u) goto label_000A4DF5;
    cpu->edx = 0x38Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4DE9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A4DE9u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4DF2u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A4DF2u));
    cpu->esp += 4u;
    label_000A4DF5:
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000A4E05;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A4E02u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A4E02u));
    cpu->esp += 4u;
    label_000A4E05:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A54A5u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A54A5u));
    cpu->esp += 4u;
    label_000A54A8:
    if (*(uint32_t*)(cpu->esi + 8u) == 0u) goto label_000A54C9;
    cpu->edx = 0x38Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Font.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A54BDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4A54BDu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A54C6u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A54C6u));
    cpu->esp += 4u;
    label_000A54C9:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A54CFu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A54CFu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5527u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A5527u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A555Fu)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A555Fu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A55C5u)); sfera_ui_pointer_vector_append(cpu, LIFT_CODE_TOKEN_VA(0x4A55C5u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5EC3u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A5EC3u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A5EFBu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4A5EFBu));
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
        default: cpu->eip = 0x4A604Eu; throw std::out_of_range("resolved jump-table index out of range"); return;
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
__declspec(noinline) void sfera_sub_004A6270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_000A62C6;
    if (cpu->ecx > 0xDD67C8u) goto label_000A6298;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x128u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A6291u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A6291u));
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
__declspec(noinline) void sfera_sub_004A6350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0xA4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4A635Du)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4A635Du));
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
    cpu->eip = 0x4A63BBu; ::DebugBreak(); return;
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

} // namespace lifted
