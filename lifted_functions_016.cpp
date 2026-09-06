#include "lifted_functions.h"
#include <cmath>
namespace lifted {

static uint32_t sfera_zoning_config_error_context() { return (uintptr_t)"Wrong format of \"Landscape\\zoning.cfg\""; }
__declspec(noinline) void sfera_sub_0049DF00(LiftCpu* cpu, uint32_t stop_address) {
    std::optional<SphereRender::ConfigDocument> configuration_document;
    cpu->esp -= 0x15Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x16Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 0u;
    SphereRender::ConfigDocument::setStorageMode(cpu->ecx == 0u ? SphereRender::ConfigDocument::StorageMode::Plain : cpu->ecx == 1u ? SphereRender::ConfigDocument::StorageMode::Encoded : SphereRender::ConfigDocument::StorageMode::Preserve);
    cpu->ecx = cpu->esi;
    configuration_document.emplace(SphereRender::ConfigDocument::open(SferaAbi::pointer<const char>(cpu->ecx))); cpu->eax = SferaAbi::address(&*configuration_document);
    cpu->esi = cpu->eax;
    cpu->edx = (uintptr_t)"zonesParams";
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->arraySize(SferaAbi::pointer<const char>(cpu->edx)).value_or(static_cast<std::size_t>(-1)));
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
    cpu->eax = SferaAbi::address(SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->objectAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))))); cpu->esp += 4u;
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
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->real(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = *value; }; cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0009DFB7;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"xPatchMin\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DFB4u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49DFB4u));
    cpu->esp += 0xCu;
    label_0009DFB7:
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)"zPatchMin";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->real(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = *value; }; cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0009DFDF;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"zPatchMin\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DFDCu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49DFDCu));
    cpu->esp += 0xCu;
    label_0009DFDF:
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uintptr_t)"xMin";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->real(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = *value; }; cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0009E007;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"xMin\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E004u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E004u));
    cpu->esp += 0xCu;
    label_0009E007:
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"xMax";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->real(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = *value; }; cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0009E02F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"xMax\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E02Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E02Cu));
    cpu->esp += 0xCu;
    label_0009E02F:
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)"zMin";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->real(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = *value; }; cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0009E057;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"zMin\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E054u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E054u));
    cpu->esp += 0xCu;
    label_0009E057:
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uintptr_t)"zMax";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->real(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = *value; }; cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0009E07F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"zMax\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E07Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E07Cu));
    cpu->esp += 0xCu;
    label_0009E07F:
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"borderFadeDist";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->real(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = *value; }; cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0009E0A7;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"borderFadeDist\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E0A4u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E0A4u));
    cpu->esp += 0xCu;
    label_0009E0A7:
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)"skyFogAlpha";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->real(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = *value; }; cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0009E0CF;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"skyFogAlpha\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E0CCu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E0CCu));
    cpu->esp += 0xCu;
    label_0009E0CF:
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uintptr_t)"fogNear";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->real(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = *value; }; cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0009E0F7;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogNear\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E0F4u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E0F4u));
    cpu->esp += 0xCu;
    label_0009E0F7:
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"fogFar";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->real(SferaAbi::pointer<const char>(cpu->edx)); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) = *value; }; cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0009E11F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogFar\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E11Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E11Cu));
    cpu->esp += 0xCu;
    label_0009E11F:
    cpu->edx = (uintptr_t)"dayColors";
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->arraySize(SferaAbi::pointer<const char>(cpu->edx)).value_or(static_cast<std::size_t>(-1)));
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
    cpu->eax = SferaAbi::address(SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->objectAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))))); cpu->esp += 4u;
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
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->realAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)) = *value; }; cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0009E1A4;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogColor[%d].r\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E1A1u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E1A1u));
    cpu->esp += 0x10u;
    label_0009E1A4:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    cpu->edx = (uintptr_t)"fogColor";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->realAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)) = *value; }; cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0009E1CB;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogColor[%d].g\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E1C8u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E1C8u));
    cpu->esp += 0x10u;
    label_0009E1CB:
    cpu->eax = cpu->ebx + 4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 2u);
    cpu->edx = (uintptr_t)"fogColor";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->realAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)) = *value; }; cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0009E1F5;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"fogColor[%d].b\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E1F2u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E1F2u));
    cpu->esp += 0x10u;
    label_0009E1F5:
    cpu->ecx = cpu->ebx + 0x5Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->edx = (uintptr_t)"ambientColor";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->realAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)) = *value; }; cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0009E21F;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"ambientColor[%d].r\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E21Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E21Cu));
    cpu->esp += 0x10u;
    label_0009E21F:
    cpu->edx = cpu->ebx + 0x60u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->edx = (uintptr_t)"ambientColor";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->realAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)) = *value; }; cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0009E249;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"ambientColor[%d].g\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E246u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E246u));
    cpu->esp += 0x10u;
    label_0009E249:
    cpu->eax = cpu->ebx + 0x64u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 2u);
    cpu->edx = (uintptr_t)"ambientColor";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->realAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)) = *value; }; cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0009E273;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"ambientColor[%d].b\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E270u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E270u));
    cpu->esp += 0x10u;
    label_0009E273:
    cpu->ecx = cpu->ebx + 0xBCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->edx = (uintptr_t)"sunColor";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->realAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)) = *value; }; cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0009E2A0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"sunColor[%d].r\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E29Du)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E29Du));
    cpu->esp += 0x10u;
    label_0009E2A0:
    cpu->edx = cpu->ebx + 0xC0u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->edx = (uintptr_t)"sunColor";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->realAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)) = *value; }; cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0009E2CD;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, sfera_zoning_config_error_context()); lift_push32(cpu, (uintptr_t)"%s : zonesParams[%d] : param \"sunColor[%d].g\"");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49E2CAu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x49E2CAu));
    cpu->esp += 0x10u;
    label_0009E2CD:
    cpu->eax = cpu->ebx + 0xC4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 2u);
    cpu->edx = (uintptr_t)"sunColor";
    cpu->ecx = cpu->edi;
    { const auto value = SferaAbi::pointer<SphereRender::ConfigDocument>(cpu->ecx)->realAt(SferaAbi::pointer<const char>(cpu->edx), static_cast<std::size_t>(static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->eax = value ? 1u : 0u; if (value) *SferaAbi::pointer<float>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)) = *value; }; cpu->esp += 8u;
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
    configuration_document.reset();
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





__declspec(noinline) void sfera_ui_description_window_has_instance(LiftCpu* cpu, uint32_t stop_address) { cpu->eax = SphereUI::Runtime::descriptionWindow() != nullptr ? 1u : 0u; cpu->esp += 4u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_description_window_update(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::CDescriptionWindow*>(static_cast<std::uintptr_t>(cpu->ecx))->update(); cpu->esp += 4u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_description_window_instance(LiftCpu* cpu, uint32_t stop_address) { cpu->eax = address32(SphereUI::CDescriptionWindow::instance()); cpu->esp += 4u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_description_window_show_description(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::CDescriptionWindow*>(static_cast<std::uintptr_t>(cpu->ecx))->showDescription(reinterpret_cast<const char*>(static_cast<std::uintptr_t>(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u)))), *reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 8u)), *reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 12u)), *reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 16u)) != 0u); cpu->esp += 20u; cpu->eip = stop_address; }







} // namespace lifted
