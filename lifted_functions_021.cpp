#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_004CD0D0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000CD0D0;
    label_000CA300:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ecx = (uintptr_t)"sound_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA30Du)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CA30Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000CA49F;
    if (cpu->eax != 0u) goto label_000CA445;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA324u)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA324u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"sound_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA334u)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4CA334u));
    cpu->ebx = cpu->eax;
    if (cpu->ebx == 0u) goto label_000CA445;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebx + 0xF8u) = LIFT_CALLBACK(sfera_sub_004CA180);
    lift_native_call(cpu, native_function_address32(&SI_GetStreamVolume), LIFT_CODE_TOKEN_VA(0x4CA34Au));
    g_sfera_sphere_options_runtime.saved_music_volume = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA359u)); sfera_sub_00497980(cpu, LIFT_CODE_TOKEN_VA(0x4CA359u));
    g_sfera_options_dialog_runtime.audio_settings = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, 0u); lift_push32(cpu, 0x9C6u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    lift_push32(cpu, 0x64u); lift_push32(cpu, 0u); lift_push32(cpu, 0x9C6u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eax = g_sfera_sphere_options_runtime.saved_music_volume;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x9C5u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = g_sfera_options_dialog_runtime.audio_settings;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x9C5u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    lift_native_call(cpu, native_function_address32(&SI_GetHardwareMixing), LIFT_CODE_TOKEN_VA(0x4CA3D7u));
    cpu->eax = cpu->eax & 0xFFu;
    g_sfera_graphics_options_runtime.graphics_values[7] = cpu->eax;
    g_sfera_graphics_options_runtime.graphics_values[12] = cpu->eax;
    if (cpu->eax != 0u) goto label_000CA447;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT33";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA3F8u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA3F8u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA402;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA404;
    label_000CA402:
    cpu->ecx = cpu->eax;
    label_000CA404:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CA42A;
    cpu->edx = (uintptr_t)"";
    label_000CA42A:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    (void)cpu;
    label_000CA430:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CA430;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA443u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CA443u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000CA445:
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CA447:
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT34";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA451u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA451u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA45B;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA45D;
    label_000CA45B:
    cpu->ecx = cpu->eax;
    label_000CA45D:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000CA483;
    cpu->edx = (uintptr_t)"";
    label_000CA483:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CA488:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CA488;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA49Bu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CA49Bu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CA49F:
    if (cpu->eax == 0u) goto label_000CA445;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA4AFu)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_VA(0x4CA4AFu));
    cpu->ecx = g_sfera_sphere_options_runtime.saved_music_volume;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA4BAu)); sfera_sub_004982F0(cpu, LIFT_CODE_TOKEN_VA(0x4CA4BAu));
    cpu->ecx = g_sfera_options_dialog_runtime.audio_settings;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA4C5u)); sfera_sub_00497B60(cpu, LIFT_CODE_TOKEN_VA(0x4CA4C5u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA4CCu)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA4CCu));
    { uint64_t l=g_sfera_graphics_options_runtime.graphics_values[7], r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&SI_SetHardwareMixing), LIFT_CODE_TOKEN_VA(0x4CA4DAu));
    cpu->esp += 4u;
    cpu->ecx = (uintptr_t)"config.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA4EDu)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4CA4EDu));
    cpu->edx = g_sfera_options_dialog_runtime.audio_settings;
    cpu->ecx = (uintptr_t)"SNDVOL";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA4FDu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CA4FDu));
    cpu->edx = g_sfera_sphere_options_runtime.saved_music_volume;
    cpu->ecx = (uintptr_t)"MUSVOL";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA50Du)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CA50Du));
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[7];
    cpu->ecx = (uintptr_t)"HWMIX";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA51Du)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CA51Du));
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_00448490(cpu, stop_address); return;
    label_000CA890:
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uintptr_t)"control_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA8ADu)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CA8ADu));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000CAB0E;
    if (cpu->eax != 0u) goto label_000CABB6;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA8C4u)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA8C4u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"control_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA8D4u)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4CA8D4u));
    cpu->ebx = cpu->eax;
    if (cpu->ebx == 0u) goto label_000CABB6;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x100u); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_control_options.configured_bindings[0]);
    *(uint32_t*)(cpu->ebx + 0xF8u) = LIFT_CALLBACK(sfera_sub_004CA530);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4CA8F5u));
    cpu->esp += 0xCu;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"SSKS_NUMBER";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA909u)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CA909u));
    cpu->ebp = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    cpu->esi = 0u;
    label_000CA911:
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)"SSKS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA91Du)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CA91Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA924u)); sfera_sub_004BEBA0(cpu, LIFT_CODE_TOKEN_VA(0x4CA924u));
    *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_control_options.configured_bindings[0])) = cpu->eax;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)5u) goto label_000CA911;
    cpu->esi = 5u;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->esi) goto label_000CA958;
    label_000CA940:
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)"SSKS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA94Cu)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CA94Cu));
    *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_control_options.configured_bindings[0])) = cpu->eax;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->ebp) goto label_000CA940;
    label_000CA958:
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"INMS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA964u)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CA964u));
    cpu->ecx = 0x40u;
    cpu->esi = (uintptr_t)&g_sfera_control_options.configured_bindings[0];
    cpu->edi = (uintptr_t)&g_sfera_control_options.working_bindings[0];
    g_sfera_control_options.configured_bindings[63] = cpu->eax;
    lift_movs32(cpu, 1u);
    if (cpu->eax != 0u) goto label_000CA9BC;
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT23";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA988u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA988u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA992;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA994;
    label_000CA992:
    cpu->ecx = cpu->eax;
    label_000CA994:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CA9AE;
    cpu->ecx = (uintptr_t)"";
    label_000CA9AE:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CA9B3:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CA9B3;
    goto label_000CA9F8;
    label_000CA9BC:
    cpu->ecx = (uintptr_t)"UISTR_WT_OPT24";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CA9C6u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CA9C6u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CA9D0;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000CA9D2;
    label_000CA9D0:
    cpu->ecx = cpu->eax;
    label_000CA9D2:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx != 0u) goto label_000CA9EC;
    cpu->ecx = (uintptr_t)"";
    label_000CA9EC:
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000CA9F1:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CA9F1;
    label_000CA9F8:
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAA04u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CAA04u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if ((int32_t)cpu->ebp <= 0) goto label_000CAAF1;
    goto label_000CAA2B;
    label_000CAA27:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    label_000CAA2B:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0xFA2u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAA46u)); sfera_sub_004B8750(cpu, LIFT_CODE_TOKEN_VA(0x4CAA46u));
    cpu->edi = cpu->eax;
    cpu->eax = cpu->esi + 1u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"UISTR_WT_KEY%02u"); lift_push32(cpu, (uintptr_t)&g_sfera_options_dialog_runtime.widget_key_name[0]);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4CAA5Au));
    cpu->esp += 0xCu;
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.widget_key_name[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAA6Du)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4CAA6Du));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CAA75;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000CAA75:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->edx);
    cpu->ebx = *(uint32_t*)(cpu->edx + 8u);
    cpu->ecx = cpu->eax;
    if (cpu->eax != 0u) goto label_000CAA8D;
    cpu->ecx = (uintptr_t)"";
    label_000CAA8D:
    cpu->eax = cpu->ecx;
    cpu->ebp = cpu->eax + 1u;
    label_000CAA92:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CAA92;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAAA5u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CAAA5u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_control_options.configured_bindings[0]));
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAAC0u)); sfera_sub_004BEC00(cpu, LIFT_CODE_TOKEN_VA(0x4CAAC0u));
    cpu->edx = cpu->eax;
    if (cpu->eax != 0u) goto label_000CAACB;
    cpu->edx = (uintptr_t)"";
    label_000CAACB:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000CAAD0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CAAD0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAAE3u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CAAE3u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x14u)) goto label_000CAA27;
    label_000CAAF1:
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    g_sfera_options_dialog_runtime.widget_keys_initialized = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CAB0E:
    cpu->ebx = 0u;
    if (cpu->eax == cpu->ebx) goto label_000CABB6;
    cpu->edx = cpu->ebx + 1u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB22u)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_VA(0x4CAB22u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB29u)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CAB29u));
    cpu->edx = g_sfera_control_options.configured_bindings[63];
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uintptr_t)"INMS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB3Au)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CAB3Au));
    cpu->esi = 0u;
    label_000CAB40:
    cpu->ecx = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_control_options.configured_bindings[0]));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB4Du)); sfera_sub_004BEB80(cpu, LIFT_CODE_TOKEN_VA(0x4CAB4Du));
    cpu->edx = cpu->eax;
    cpu->ecx = (uintptr_t)"SSKS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB59u)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CAB59u));
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)5u) goto label_000CAB40;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"SSKS_NUMBER";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB6Bu)); sfera_sub_00437F60(cpu, LIFT_CODE_TOKEN_VA(0x4CAB6Bu));
    cpu->edi = cpu->eax;
    cpu->esi = 5u;
    if ((int32_t)cpu->edi <= (int32_t)cpu->esi) goto label_000CAB97;
    label_000CAB80:
    cpu->edx = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_control_options.configured_bindings[0]));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)"SSKS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CAB92u)); sfera_sub_00437E20(cpu, LIFT_CODE_TOKEN_VA(0x4CAB92u));
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->edi) goto label_000CAB80;
    label_000CAB97:
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x10u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CABB0u)); sfera_sub_004BA680(cpu, LIFT_CODE_TOKEN_VA(0x4CABB0u));
    g_sfera_options_dialog_runtime.widget_keys_initialized = cpu->ebx;
    label_000CABB6:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CD0D0:
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    if (cpu->eax == 0x64u) goto label_000CD179;
    if (cpu->eax != 0x3E9u) goto label_000CD144;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax += 0xFFFFFFFDu;
    if (cpu->eax > 5u) goto label_000CD144;
    switch (cpu->eax) {
        case 0u: goto label_000CD0F5;
        case 1u: goto label_000CD0FC;
        case 2u: goto label_000CD103;
        case 3u: goto label_000CD10A;
        case 4u: goto label_000CD111;
        case 5u: goto label_000CD145;
        default: lift_trap(cpu, 0x4CD0EEu, "resolved jump-table index out of range"); return;
    }
label_000CD0F5: ;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    sfera_sub_004CC280(cpu, stop_address); return;
    label_000CD0FC:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    goto label_000CA300;
    label_000CD103:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    goto label_000CA890;
    label_000CD10A:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    sfera_sub_004CB100(cpu, stop_address); return;
    label_000CD111:
    cpu->ecx = (uintptr_t)"authors";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD11Bu)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CD11Bu));
    if (cpu->eax != 0u) goto label_000CD144;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD126u)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CD126u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"authors";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD136u)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4CD136u));
    if (cpu->eax == 0u) goto label_000CD144;
    *(uint32_t*)(cpu->eax + 0xF8u) = LIFT_CALLBACK(sfera_sub_004C9C30);
    label_000CD144:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CD145:
    cpu->ecx = (uintptr_t)"quit";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD14Fu)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CD14Fu));
    if (cpu->eax != 0u) goto label_000CD144;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD15Au)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4CD15Au));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"quit";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD16Au)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4CD16Au));
    if (cpu->eax == 0u) goto label_000CD144;
    *(uint32_t*)(cpu->eax + 0xF8u) = LIFT_CALLBACK(sfera_sub_004C9C40);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CD179:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    sfera_sub_004CD1A0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004CD1A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ecx = (uintptr_t)"options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD1ADu)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CD1ADu));
    { uint64_t v= cpu->ebx & 0xFFu; lift_flags_logic(cpu,v,8u); }
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CD1D3;
    if (cpu->eax != 0u) goto label_000CD1D2;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD1C4u)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4CD1C4u));
    if (cpu->eax == 0u) goto label_000CD1D2;
    *(uint32_t*)(cpu->eax + 0xF8u) = LIFT_CALLBACK(sfera_sub_004CD0D0);
    label_000CD1D2:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CD1D3:
    if (cpu->eax == 0u) goto label_000CD1D2;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    sfera_sub_004B8700(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004CD1F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    if (cpu->eax == 0x64u) goto label_000CD24B;
    if (cpu->eax == 0x3E9u) goto label_000CD229;
    if (cpu->eax != 0x1DE4u) goto label_000CD21D;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    { uint64_t l=cpu->eax, r=3u, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CD21E;
    { uint64_t l=cpu->eax, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CD21D;
    cpu->eax = *(uint32_t*)(cpu->edx + 0xCu);
    cpu->ecx = g_sfera_options_dialog_runtime.chat_edit_fonts.begin;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    label_000CD21D:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CD21E:
    cpu->edx = *(uint32_t*)(cpu->edx + 0xCu);
    cpu->eax = g_sfera_options_dialog_runtime.chat_edit_fonts.begin;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CD229:
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    { uint64_t l=cpu->eax, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CD233;
    { uint64_t l=cpu->eax, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CD24B;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CD233:
    cpu->ecx = g_sfera_options_dialog_runtime.chat_edit_fonts.end;
    cpu->edx = g_sfera_options_dialog_runtime.chat_edit_fonts.begin;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCD24Bu)); sfera_sub_004AB160(cpu, LIFT_CODE_TOKEN_RVA(0xCD24Bu));
    label_000CD24B:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)"font_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD27Cu)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CD27Cu));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000CD3AD;
    if (cpu->eax != 0u) goto label_000CD410;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD293u)); sfera_sub_004CB100(cpu, LIFT_CODE_TOKEN_VA(0x4CD293u));
    cpu->ecx = (uintptr_t)"options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD29Du)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4CD29Du));
    if (cpu->eax == 0u) goto label_000CD2AD;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCD2ADu)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_RVA(0xCD2ADu));
    label_000CD2AD:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"font_options";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD2BDu)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4CD2BDu));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_000CD410;
    lift_push32(cpu, 2u);
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    *(uint32_t*)(cpu->esi + 0xF8u) = LIFT_CALLBACK(sfera_sub_004CD1F0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD2DDu)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_VA(0x4CD2DDu));
    lift_push32(cpu, 2u);
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.chat_edit_fonts;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD2E9u)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_VA(0x4CD2E9u));
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    *(uint32_t*)(cpu->esp + 0xCu) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD300u)); sfera_sub_004BDF90(cpu, LIFT_CODE_TOKEN_VA(0x4CD300u));
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    *(uint32_t*)(cpu->esp + 0xCu) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD317u)); sfera_sub_004BDF90(cpu, LIFT_CODE_TOKEN_VA(0x4CD317u));
    cpu->ecx = (uintptr_t)"config.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD321u)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4CD321u));
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->ecx = (uintptr_t)"CHAT_LIST_FONT";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD331u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4CD331u));
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx += 4u;
    cpu->ecx = (uintptr_t)"CHAT_EDIT_FONT";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD344u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4CD344u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    cpu->ecx = g_sfera_options_dialog_runtime.chat_list_fonts.end;
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.chat_edit_fonts;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD39Cu)); sfera_sub_004AB160(cpu, LIFT_CODE_TOKEN_VA(0x4CD39Cu));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CD3AD:
    cpu->esi = 0u;
    if (cpu->eax == cpu->esi) goto label_000CD410;
    cpu->edx = cpu->esi + 1u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD3BDu)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_VA(0x4CD3BDu));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD3C4u)); sfera_sub_004CB100(cpu, LIFT_CODE_TOKEN_VA(0x4CD3C4u));
    cpu->ecx = (uintptr_t)"config.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD3CEu)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4CD3CEu));
    cpu->eax = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = (uintptr_t)"CHAT_LIST_FONT";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD3DFu)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CD3DFu));
    cpu->ecx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = (uintptr_t)"CHAT_EDIT_FONT";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD3F2u)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x4CD3F2u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD3F7u)); sfera_sub_00448490(cpu, LIFT_CODE_TOKEN_VA(0x4CD3F7u));
    cpu->ecx = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0x14u) = 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCD410u)); sfera_sub_004BA680(cpu, LIFT_CODE_TOKEN_RVA(0xCD410u));
    label_000CD410:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CD430(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD438u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4CD438u));
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->eax;
    *(uint16_t*)(cpu->esi + 0x1BCu) = cpu->eax & 0xFFFFu;
    cpu->eax = 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    *(uint8_t*)(cpu->esi + 0x1BEu) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->eax;
    std::construct_at(reinterpret_cast<SphereUI::SpinButton*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x50u) = 0x10u;
    *(uint32_t*)(cpu->esi + 0x1A4u) = 0x64u;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CD4A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::SpinButton*>(cpu->esi));
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x198u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CD501;
    cpu->edx = 0x4Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SpinCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD4EEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CD4EEu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->ecx == 0u) goto label_000CD501;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000CD501:
    if (*(uint32_t*)(cpu->esi + 0x19Cu) == 0u) goto label_000CD52C;
    cpu->edx = 0x50u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SpinCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD519u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CD519u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    if (cpu->ecx == 0u) goto label_000CD52C;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000CD52C:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD53Bu)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4CD53Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CD550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD567u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4CD567u));
    if (*(uint32_t*)(cpu->esi + 0x9Cu) != 0u) goto label_000CD58A;
    lift_push32(cpu, 0x60u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SpinCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD581u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CD581u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD587u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CD587u));
    cpu->esp += 0x10u;
    label_000CD58A:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"defButtonStyle");
    cpu->ecx = cpu->edi;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD59Fu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4CD59Fu));
    if (cpu->eax == 0u) goto label_000CD5B1;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD5ACu)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4CD5ACu));
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    label_000CD5B1:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"leftbutton");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD5C5u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4CD5C5u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->eax == 0u) goto label_000CD610;
    lift_push32(cpu, 1u); lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD5DFu)); sfera_sub_004D4230(cpu, LIFT_CODE_TOKEN_VA(0x4CD5DFu));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD5EDu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_VA(0x4CD5EDu));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000CD610;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    lift_x87_push(cpu, (double)0.15000000596046448f);
    *(uint32_t*)(cpu->eax + 0x1A8u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x1A8u)) | (uint64_t)(6u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    *(float*)(cpu->eax + 0x1BCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000CD610:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"rightbutton");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD628u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4CD628u));
    if (cpu->eax == 0u) goto label_000CD66F;
    lift_push32(cpu, 2u); lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD63Eu)); sfera_sub_004D4230(cpu, LIFT_CODE_TOKEN_VA(0x4CD63Eu));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD64Cu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_VA(0x4CD64Cu));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000CD66F;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_x87_push(cpu, (double)0.15000000596046448f);
    *(uint32_t*)(cpu->eax + 0x1A8u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x1A8u)) | (uint64_t)(6u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    *(float*)(cpu->ecx + 0x1BCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000CD66F:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"range");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD680u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4CD680u));
    if (cpu->eax == 0u) goto label_000CD6C4;
    cpu->edx = cpu->esi + 0x1A4u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x1A0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4CD69Bu));
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000CD6C4;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"SpinButton::LoadUI(%s,%d,%d) -> Invalid args in 'range'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD6BBu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CD6BBu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD6C1u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CD6C1u));
    cpu->esp += 0x14u;
    label_000CD6C4:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"spinPos");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD6D1u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4CD6D1u));
    if (cpu->eax == 0u) goto label_000CD6E4;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD6DEu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4CD6DEu));
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    label_000CD6E4:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"badyCtrlID");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD6F1u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4CD6F1u));
    if (cpu->eax == 0u) goto label_000CD704;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD6FEu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4CD6FEu));
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    label_000CD704:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"notifyChange");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD711u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4CD711u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_000CD72B;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD720u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4CD720u));
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->esi + 0x1BDu) = cpu->ecx & 0xFFu;
    label_000CD72B:
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esi + 0x1BCu) = 0u;
    *(uint32_t*)(cpu->esi + 0x1B0u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD748u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4CD748u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CD760(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000CD812;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->ecx == 0u) goto label_000CD7BE;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    if (*(uint32_t*)(cpu->ecx + 0xDCu) == cpu->eax) goto label_000CD7B1;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 4u)))));
    if ((int32_t)cpu->eax >= 0) goto label_000CD79A;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CD79A:
    cpu->fpu[0u] = (cpu->fpu[0u]) / (255.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000CD7B1:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000CD7BE:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    if (cpu->ecx == 0u) goto label_000CD812;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    if (*(uint32_t*)(cpu->ecx + 0xDCu) == cpu->eax) goto label_000CD801;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 4u)))));
    if ((int32_t)cpu->eax >= 0) goto label_000CD7EA;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CD7EA:
    cpu->fpu[0u] = (cpu->fpu[0u]) / (255.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000CD801:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CD812:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CD820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x30u);
    if (*(uint8_t*)(cpu->esi + 0x48u) != (cpu->ebx & 0xFFu)) goto label_000CD939;
    if (*(uint8_t*)(cpu->esi + 0x49u) != (cpu->ebx & 0xFFu)) goto label_000CD88D;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esi + 0x1A4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CD864;
    lift_push32(cpu, cpu->ebx);
    goto label_000CD866;
    label_000CD864:
    lift_push32(cpu, 1u);
    label_000CD866:
    lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A8u);
    { uint64_t l=cpu->ecx, r=*(uint32_t*)(cpu->esi + 0x1A0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CD887;
    lift_push32(cpu, cpu->ebx);
    goto label_000CD889;
    label_000CD887:
    lift_push32(cpu, 1u);
    label_000CD889:
    lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000CD88D:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->ecx == cpu->ebx) goto label_000CD89F;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000CD89F:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    if (cpu->ecx == cpu->ebx) goto label_000CD8B1;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000CD8B1:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD8BDu)); sfera_sub_004D32C0(cpu, LIFT_CODE_TOKEN_VA(0x4CD8BDu));
    if (cpu->eax == 0u) goto label_000CD928;
    cpu->edi = 0x3E9u;
    label_000CD8C6:
    if (*(uint32_t*)(cpu->esp + 0x14u) != cpu->edi) goto label_000CD918;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    { uint64_t l=cpu->eax, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CD8F2;
    { uint64_t l=cpu->eax, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CD918;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->edx -= cpu->eax;
    if ((int32_t)cpu->ecx > (int32_t)cpu->edx) goto label_000CD918;
    cpu->eax += cpu->ecx;
    goto label_000CD90C;
    label_000CD8F2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->edx += cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_000CD918;
    cpu->eax -= cpu->ecx;
    label_000CD90C:
    *(uint8_t*)(cpu->esi + 0x1BCu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    label_000CD918:
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD924u)); sfera_sub_004D32C0(cpu, LIFT_CODE_TOKEN_VA(0x4CD924u));
    if (cpu->eax != 0u) goto label_000CD8C6;
    label_000CD928:
    if (*(uint8_t*)(cpu->esi + 0x1BCu) != (cpu->ebx & 0xFFu)) goto label_000CD939;
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::SpinButton*>(cpu->esi)->updateStatus(cpu);
    label_000CD939:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CD950(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Set Range %d %d");
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD969u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CD969u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD96Fu)); sfera_sub_0042E480(cpu, LIFT_CODE_TOKEN_VA(0x4CD96Fu));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->esi + 0x1A4u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x1A0u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x1BCu) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CD990(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"Set pos %d");
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD9A3u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CD9A3u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD9A9u)); sfera_sub_0042E480(cpu, LIFT_CODE_TOKEN_VA(0x4CD9A9u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->edi;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 0x1BCu) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x1BEu) = cpu->eax & 0xFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CD9D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"Set step %d");
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD9E3u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CD9E3u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CD9E9u)); sfera_sub_0042E480(cpu, LIFT_CODE_TOKEN_VA(0x4CD9E9u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esi + 0x1B0u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CDA00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1A8u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CDA10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDA18u)); sfera_sub_004CD4A0(cpu, LIFT_CODE_TOKEN_VA(0x4CDA18u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000CDA28;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDA25u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4CDA25u));
    cpu->esp += 4u;
    label_000CDA28:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CDA30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = cpu->edi + 0xFFFFEA82u;
    cpu->esi = cpu->ecx;
    if (cpu->eax > 0x62u) goto label_000CDB0C;
    cpu->eax = cpu->edi + 0xFFFFEA82u;
    if (cpu->eax > 0x62u) goto label_000CDB0C;
    switch (cpu->eax) {
        case 0u: goto label_000CDA64;
        case 1u: goto label_000CDA7A;
        case 2u: goto label_000CDAC1;
        case 3u: goto label_000CDAE3;
        case 4u: goto label_000CDA95;
        case 5u: goto label_000CDAF6;
        case 98u: goto label_000CDAAB;
        default: goto label_000CDB0C;
    }
label_000CDA64: ;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDA70u)); sfera_sub_004CD990(cpu, LIFT_CODE_TOKEN_VA(0x4CDA70u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000CDA7A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDA8Bu)); sfera_sub_004CD950(cpu, LIFT_CODE_TOKEN_VA(0x4CDA8Bu));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000CDA95:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDAA1u)); sfera_sub_004CD9D0(cpu, LIFT_CODE_TOKEN_VA(0x4CDAA1u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000CDAAB:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000CDAC1:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A0u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000CDAE3:
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::SpinButton*>(cpu->esi)->updateStatus(cpu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000CDAF6:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B0u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000CDB0C:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->edi == 0x70u) goto label_000CDB20;
    if (cpu->edi != 0x6Cu) goto label_000CDB52;
    label_000CDB20:
    if (*(uint32_t*)(cpu->esi + 0x198u) == 0u) goto label_000CDB39;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000CDB39:
    if (*(uint32_t*)(cpu->esi + 0x19Cu) == 0u) goto label_000CDB52;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000CDB52:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDB5Cu)); sfera_sub_004D2DD0(cpu, LIFT_CODE_TOKEN_VA(0x4CDB5Cu));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CDBF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x9Cu);
    if (cpu->eax == 0u) goto label_000CDD37;
    if (*(uint32_t*)(cpu->esi + 0x1B4u) != 0u) goto label_000CDC5D;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1B8u);
    if (cpu->edx == 0xFFFFFFFFu) goto label_000CDC5D;
    if (cpu->edx == 0u) goto label_000CDC3F;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx <= 1u) goto label_000CDC3C;
    cpu->ecx = cpu->edx + 0xFFFFFFFFu;
    label_000CDC37:
    { uint64_t l=cpu->ecx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = *(uint32_t*)(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CDC37;
    label_000CDC3C:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    label_000CDC3F:
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000CDC5D;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"SpinButton::UpdateStatus() -> Bady '%d' not found.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDC54u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CDC54u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDC5Au)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CDC5Au));
    cpu->esp += 0xCu;
    label_000CDC5D:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A0u);
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1A8u) >= (int32_t)cpu->eax) goto label_000CDC71;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    label_000CDC71:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A4u);
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x1A8u) <= (int32_t)cpu->eax) goto label_000CDC85;
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    label_000CDC85:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1A8u);
    if (*(uint32_t*)(cpu->esi + 0x1ACu) == cpu->eax) goto label_000CDD29;
    if (*(uint32_t*)(cpu->esi + 0x1B4u) == 0u) goto label_000CDCDB;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.spin_value_text);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4CDCACu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1B4u);
    cpu->eax = (uintptr_t)g_sfera_ui_load_scratch_runtime.spin_value_text;
    cpu->esp += 0xCu;
    cpu->edi = cpu->eax + 1u;
    label_000CDCC3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CDCC3;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.spin_value_text);
    cpu->ecx = cpu->edx + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDCDAu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4CDCDAu));
    cpu->edi = lift_pop32(cpu);
    label_000CDCDB:
    if (*(uint8_t*)(cpu->esi + 0x1BDu) == 0u) goto label_000CDD1D;
    if (*(uint8_t*)(cpu->esi + 0x1BEu) == 0u) goto label_000CDD1D;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A8u);
    cpu->eax = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x157Du;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCDD1Du)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xCDD1Du));
    label_000CDD1D:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A8u);
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->ecx;
    label_000CDD29:
    *(uint8_t*)(cpu->esi + 0x1BCu) = 1u;
    *(uint8_t*)(cpu->esi + 0x1BEu) = 1u;
    label_000CDD37:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CDD50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDD5Eu)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4CDD5Eu));
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
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1BDu));
    *(uint8_t*)(cpu->esi + 0x1BDu) = cpu->ecx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x1BEu));
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 0x1BEu) = cpu->edx & 0xFFu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CDE00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0xAFu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SpinCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDE34u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CDE34u));
    lift_push32(cpu, 0x1C0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDE3Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4CDE3Eu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_000CDE5C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDE58u)); sfera_sub_004CD430(cpu, LIFT_CODE_TOKEN_VA(0x4CDE58u));
    cpu->esi = cpu->eax;
    goto label_000CDE5E;
    label_000CDE5C:
    cpu->esi = 0u;
    label_000CDE5E:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDE6Eu)); sfera_sub_004CDD50(cpu, LIFT_CODE_TOKEN_VA(0x4CDE6Eu));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0x198u) == 0u) goto label_000CDE96;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCDE96u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xCDE96u));
    label_000CDE96:
    if (*(uint32_t*)(cpu->edi + 0x19Cu) == 0u) goto label_000CDEBA;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCDEBAu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xCDEBAu));
    label_000CDEBA:
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_000CDEDE;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCDEDEu)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xCDEDEu));
    label_000CDEDE:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CDF00(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_push(cpu, 1.0);
    cpu->eax = cpu->ecx;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x8Cu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x90u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x94u) = cpu->ecx;
    *(float*)(cpu->eax + 0x18u) = cpu->fpu[0u];
    lift_x87_push(cpu, 0.0);
    cpu->edx |= 0xFFFFFFFFu;
    *(float*)(cpu->eax + 0x14u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->edx;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ecx;
    *(float*)(cpu->eax + 0x38u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->eax + 0x3Cu) = cpu->edx;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(uint32_t*)(cpu->eax + 0x40u) = cpu->ecx;
    *(float*)(cpu->eax + 0x34u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->edx;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(uint32_t*)(cpu->eax + 0x60u) = cpu->ecx;
    *(float*)(cpu->eax + 0x58u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->eax + 0x7Cu) = cpu->edx;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(uint32_t*)(cpu->eax + 0x80u) = cpu->ecx;
    *(float*)(cpu->eax + 0x54u) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->eax + 0x78u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->eax + 0x74u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CDF70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->esi);
    if (cpu->edi == 0u) goto label_000CDFBC;
    cpu->edx = 0xA6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDF8Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CDF8Eu));
    cpu->eax = cpu->edi;
    cpu->edx = cpu->eax + 1u;
    label_000CDF93:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CDF93;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDFA3u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4CDFA3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->eax;
    label_000CDFB0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000CDFB0;
    goto label_000CDFC2;
    label_000CDFBC:
    *(uint32_t*)(cpu->esi) = 0u;
    label_000CDFC2:
    if (cpu->ebx == 0u) goto label_000CDFDE;
    cpu->edx = 0xACu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDFD5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CDFD5u));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CDFDBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4CDFDBu));
    cpu->esp += 4u;
    label_000CDFDE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CDFF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x94u);
    if (cpu->eax == cpu->ebp) goto label_000CE0D4;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x90u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CE078;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if (cpu->eax == 0u) goto label_000CE059;
    cpu->edi = 0u;
    label_000CE020:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    if (*(uint32_t*)(cpu->edi + cpu->eax) == 0u) goto label_000CE04D;
    cpu->edx = 0xBAu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE03Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE03Bu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->edi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE04Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4CE04Au));
    cpu->esp += 4u;
    label_000CE04D:
    ++cpu->ebx;
    cpu->edi += 0x3Cu;
    if (cpu->ebx < *(uint32_t*)(cpu->esi + 0x94u)) goto label_000CE020;
    label_000CE059:
    cpu->edx = 0xBCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE068u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE068u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE074u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4CE074u));
    cpu->esp += 4u;
    cpu->ebx = lift_pop32(cpu);
    label_000CE078:
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x94u) = cpu->edi;
    if (cpu->ebp == cpu->edi) goto label_000CE0D3;
    cpu->edx = 0xC3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE099u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE099u));
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->ebp;
    cpu->edx = 0x3Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE0B1u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4CE0B1u));
    cpu->ecx = cpu->ebp;
    cpu->ecx <<= 4u;
    cpu->ecx -= cpu->ebp;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x94u) = cpu->ebp;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4CE0CBu));
    cpu->esp += 0x10u;
    label_000CE0D3:
    cpu->edi = lift_pop32(cpu);
    label_000CE0D4:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CE0E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (g_sfera_sprite_runtime.render_mode == cpu->esi) goto label_000CE137;
    cpu->eax = cpu->esi;
    { uint64_t l=cpu->eax, r=0u, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CE126;
    { uint64_t l=cpu->eax, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CE10F;
    { uint64_t l=cpu->eax, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CE131;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 2u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE107u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x4CE107u));
    g_sfera_sprite_runtime.render_mode = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CE10F:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE11Eu)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x4CE11Eu));
    g_sfera_sprite_runtime.render_mode = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CE126:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCE131u)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_RVA(0xCE131u));
    label_000CE131:
    g_sfera_sprite_runtime.render_mode = cpu->esi;
    label_000CE137:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CE140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, 6u);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE156u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x4CE156u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x94u);
    cpu->ebp = 0u;
    if (cpu->eax <= cpu->ebp) goto label_000CE2A7;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, 0.5);
    *(uint32_t*)(cpu->esp + 0x10u) = 0xFFFFFFFFu;
    cpu->fpu[1u] = (cpu->fpu[1u]) - (cpu->fpu[0u]);
    lift_push32(cpu, cpu->edi);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->ebx = cpu->esi + 0xCu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (((double)*(float*)(cpu->esp + 0x24u))) - (cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000CE191:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x90u);
    cpu->edi += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    if (*(uint32_t*)(cpu->esp + 0x14u) == cpu->ecx) goto label_000CE1BF;
    cpu->edx = 1u;
    if (g_sfera_sprite_runtime.render_mode == cpu->edx) goto label_000CE1B3;
    cpu->edx = 0u;
    label_000CE1B3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE1B8u)); sfera_sub_0044FCB0(cpu, LIFT_CODE_TOKEN_VA(0x4CE1B8u));
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_000CE1BF:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2Cu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x2Cu)))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE1CF;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE1CF:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->ebx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x34u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x34u)))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE1EB;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE1EB:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    *(float*)(cpu->esi + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x1Cu));
    *(float*)(cpu->esi + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x30u)))));
    if ((int32_t)cpu->eax >= 0) goto label_000CE214;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE214:
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    *(float*)(cpu->esi + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    *(float*)(cpu->esi + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x20u));
    *(float*)(cpu->esi + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x2Cu));
    *(float*)(cpu->esi + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x38u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x38u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE243;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE243:
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 0x1C4u);
    *(float*)(cpu->esi + 0x50u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x14u));
    *(float*)(cpu->esi + 0x64u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x24u));
    *(float*)(cpu->esi + 0x68u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx));
    *(float*)(cpu->esi + 0x6Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x50u));
    *(float*)(cpu->esi + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x18u));
    *(float*)(cpu->esi + 0x84u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x28u));
    *(float*)(cpu->esi + 0x88u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE281u)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x4CE281u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 2u); lift_push32(cpu, 6u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE293u)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x4CE293u));
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x3Cu) + (uint64_t)(0u);
    ++cpu->ebp;
    if (cpu->ebp < *(uint32_t*)(cpu->esi + 0x94u)) goto label_000CE191;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000CE2A7:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CE2B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFC0u;
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0x94u) == cpu->edi) goto label_000CE4E6;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE2DBu)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x4CE2DBu));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 4u)))));
    if ((int32_t)cpu->eax >= 0) goto label_000CE2FF;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE2FF:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xCu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 8u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE329;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE329:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x94u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFFFFFFFFu;
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.5);
    cpu->fpu[2u] = (cpu->fpu[2u]) - (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->ebp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->ebp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->eax <= cpu->edi) goto label_000CE4E6;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edi;
    cpu->ebx = cpu->esi + 0xCu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    label_000CE362:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x90u);
    cpu->edi += *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    if (*(uint32_t*)(cpu->esp + 0x2Cu) == cpu->ecx) goto label_000CE390;
    cpu->edx = 1u;
    if (g_sfera_sprite_runtime.render_mode == cpu->edx) goto label_000CE384;
    cpu->edx = 0u;
    label_000CE384:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE389u)); sfera_sub_0044FCB0(cpu, LIFT_CODE_TOKEN_VA(0x4CE389u));
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    label_000CE390:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x2Cu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x2Cu)))));
    if ((int32_t)cpu->eax >= 0) goto label_000CE3A0;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE3A0:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x30u)));
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE3B7u)); sfera_sub_004EED66(cpu, LIFT_CODE_TOKEN_VA(0x4CE3B7u));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebp + 8u)));
    *(float*)(cpu->ebx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x34u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE3D4;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE3D4:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE3E8u)); sfera_sub_004EED66(cpu, LIFT_CODE_TOKEN_VA(0x4CE3E8u));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebp + 0xCu)));
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    *(float*)(cpu->esi + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x1Cu));
    *(float*)(cpu->esi + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x30u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x30u)))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE412;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE412:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x38u)));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE426u)); sfera_sub_004EED66(cpu, LIFT_CODE_TOKEN_VA(0x4CE426u));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebp + 8u)));
    *(float*)(cpu->esi + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    *(float*)(cpu->esi + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    *(float*)(cpu->esi + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x20u));
    *(float*)(cpu->esi + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x2Cu));
    *(float*)(cpu->esi + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x38u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x38u)))));
    if ((int32_t)cpu->eax >= 0) goto label_000CE45C;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE45C:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE470u)); sfera_sub_004EED66(cpu, LIFT_CODE_TOKEN_VA(0x4CE470u));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 8u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    lift_push32(cpu, 0x1C4u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebp + 0xCu)));
    *(float*)(cpu->esi + 0x50u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x14u));
    *(float*)(cpu->esi + 0x64u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x24u));
    *(float*)(cpu->esi + 0x68u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx));
    *(float*)(cpu->esi + 0x6Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x50u));
    *(float*)(cpu->esi + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x18u));
    *(float*)(cpu->esi + 0x84u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x28u));
    *(float*)(cpu->esi + 0x88u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE4BAu)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x4CE4BAu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 2u); lift_push32(cpu, 6u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE4CCu)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x4CE4CCu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esp + 0x28u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x28u)) + (uint64_t)(0x3Cu) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0x94u)) goto label_000CE362;
    label_000CE4E6:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CE4F0(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=cpu->esp, r=0x20u, v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = cpu->eax;
    cpu->edx <<= 4u;
    cpu->edx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x90u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + (cpu->edx * 4u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_000CE558;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx + 1u;
    label_000CE524:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CE524;
    cpu->ecx -= cpu->edi;
    cpu->edi = cpu->eax + 1u;
    label_000CE530:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CE530;
    cpu->eax -= cpu->edi;
    cpu->edi = lift_pop32(cpu);
    if (cpu->ecx <= cpu->eax) goto label_000CE585;
    cpu->edx = 0x23Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE54Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE54Du));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE555u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4CE555u));
    cpu->esp += 4u;
    label_000CE558:
    cpu->edx = 0x23Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE567u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE567u));
    cpu->eax = cpu->ebp;
    cpu->edx = cpu->eax + 1u;
    label_000CE570:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CE570;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE580u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4CE580u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    label_000CE585:
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = cpu->ebp;
    label_000CE590:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000CE590;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE5A1u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x4CE5A1u));
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_000CE5BD;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Sprite::Texture not found '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE5B4u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CE5B4u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE5BAu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE5BAu));
    cpu->esp += 0xCu;
    label_000CE5BD:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE5C9u)); sfera_sub_0044FC60(cpu, LIFT_CODE_TOKEN_VA(0x4CE5C9u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->eax == 0u) goto label_000CE689;
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax)))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE5E3;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE5E3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE5F5;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE5F5:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax + 4u)))));
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    if ((int32_t)cpu->edx >= 0) goto label_000CE60A;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE60A:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE61C;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE61C:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax + 8u)))));
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if ((int32_t)cpu->edx >= 0) goto label_000CE631;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE631:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE643;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE643:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0xCu)))));
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    if ((int32_t)cpu->edx >= 0) goto label_000CE658;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE658:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    if ((int32_t)cpu->eax >= 0) goto label_000CE66A;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE66A:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x14u));
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x1Cu));
    *(float*)(cpu->esi + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0xCu));
    *(float*)(cpu->esi + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x24u));
    *(float*)(cpu->esi + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000CE6A5;
    label_000CE689:
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u];
    lift_x87_push(cpu, 1.0);
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x24u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x20u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000CE6A5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    if (cpu->eax == 0u) goto label_000CE6C3;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    goto label_000CE6DC;
    label_000CE6C3:
    *(uint32_t*)(cpu->esi + 0x34u) = 0u;
    *(uint32_t*)(cpu->esi + 0x2Cu) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000CE6DC:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CE700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->ecx + 0x94u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000CE88D;
    cpu->edx = cpu->eax;
    cpu->edx <<= 4u;
    cpu->edx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + (cpu->edx * 4u);
    if (cpu->ecx == 0xFFFFFFFFu) goto label_000CE88C;
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE745u)); sfera_sub_0044FC60(cpu, LIFT_CODE_TOKEN_VA(0x4CE745u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->eax == 0u) goto label_000CE88C;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax)))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE75F;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE75F:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE771;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE771:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax + 4u)))));
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    if ((int32_t)cpu->ecx >= 0) goto label_000CE786;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE786:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE798;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE798:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax + 8u)))));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    if ((int32_t)cpu->ecx >= 0) goto label_000CE7AD;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE7AD:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE7BF;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE7BF:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0xCu)))));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    if ((int32_t)cpu->ecx >= 0) goto label_000CE7D4;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE7D4:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE7E6;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE7E6:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0x10u)))));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x10u);
    if ((int32_t)cpu->ecx >= 0) goto label_000CE7FB;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE7FB:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE80D;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE80D:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0x14u)))));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    if ((int32_t)cpu->ecx >= 0) goto label_000CE822;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE822:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE834;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE834:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0x18u)))));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18u);
    if ((int32_t)cpu->ecx >= 0) goto label_000CE849;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE849:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((int32_t)cpu->edx >= 0) goto label_000CE85B;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE85B:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 4u)))));
    if ((int32_t)cpu->eax >= 0) goto label_000CE875;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE875:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    if ((int32_t)cpu->ecx >= 0) goto label_000CE887;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CE887:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000CE88C:
    cpu->esi = lift_pop32(cpu);
    label_000CE88D:
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CE8A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x148u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x150u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x15Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x164u);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"name");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE8E4u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4CE8E4u));
    if (cpu->eax == 0u) goto label_000CE908;
    cpu->eax = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE8F6u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4CE8F6u));
    if (cpu->eax == 0u) goto label_000CE908;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE906u)); sfera_sub_004CDF70(cpu, LIFT_CODE_TOKEN_VA(0x4CE906u));
    goto label_000CE923;
    label_000CE908:
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> Name not specified.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE91Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CE91Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE920u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE920u));
    cpu->esp += 0x14u;
    label_000CE923:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"size");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE930u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4CE930u));
    if (cpu->eax == 0u) goto label_000CE94E;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE93Du)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4CE93Du));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE949u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4CE949u));
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    goto label_000CE969;
    label_000CE94E:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> Size not specified.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE960u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CE960u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE966u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE966u));
    cpu->esp += 0x14u;
    label_000CE969:
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE975u)); sfera_sub_00494920(cpu, LIFT_CODE_TOKEN_VA(0x4CE975u));
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE97Du)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x4CE97Du));
    lift_push32(cpu, (uintptr_t)"texture");
    cpu->ecx = cpu->esi;
    cpu->ebx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE98Bu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE98Bu));
    if (cpu->eax == 0u) goto label_000CE9A5;
    (void)cpu;
    label_000CE990:
    lift_push32(cpu, (uintptr_t)"texture");
    cpu->ecx = cpu->esi;
    ++cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE99Du)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE99Du));
    if (cpu->eax != 0u) goto label_000CE990;
    if (cpu->ebx != 0u) goto label_000CE9C4;
    label_000CE9A5:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> At least one texture must be specified.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE9BBu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CE9BBu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE9C1u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE9C1u));
    cpu->esp += 0x14u;
    label_000CE9C4:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE9CCu)); sfera_sub_004CDFF0(cpu, LIFT_CODE_TOKEN_VA(0x4CE9CCu));
    if ((int32_t)cpu->ebx <= 0) goto label_000CEB41;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    cpu->ebx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE9DEu)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x4CE9DEu));
    lift_push32(cpu, (uintptr_t)"texture");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CE9EAu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4CE9EAu));
    cpu->ebp = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_000CEA97;
    label_000CE9F8:
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEA06u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4CEA06u));
    if (cpu->eax == 0u) goto label_000CEA83;
    cpu->edx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_sprite_runtime.texture_token[0]);
    cpu->ecx = cpu->esi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%s %d %d %d %d %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0xCEA42u), LIFT_CODE_TOKEN_RVA(0xCEA40u))) { return; }
    cpu->esp += 0x2Cu;
    if (cpu->eax == 9u) goto label_000CEA69;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> Incorrect number of args in 'texture'.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEA60u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CEA60u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEA66u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CEA66u));
    cpu->esp += 0x14u;
    label_000CEA69:
    cpu->edx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x5Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEA82u)); sfera_sub_004CE4F0(cpu, LIFT_CODE_TOKEN_VA(0x4CEA82u));
    ++cpu->ebx;
    label_000CEA83:
    lift_push32(cpu, (uintptr_t)"texture");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEA8Fu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4CEA8Fu));
    if (cpu->eax != 0u) goto label_000CE9F8;
    label_000CEA97:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEA9Fu)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x4CEA9Fu));
    lift_push32(cpu, (uintptr_t)"tcoords");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEAABu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4CEAABu));
    if (cpu->eax == 0u) goto label_000CEB41;
    cpu->ebx = cpu->esi + 0x10u;
    label_000CEAB6:
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %d %d %d %d %d %d %d %d"); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x40u) = 0u;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0xCEAF3u), LIFT_CODE_TOKEN_RVA(0xCEAF1u))) { return; }
    cpu->esp += 0x2Cu;
    if (cpu->eax == 9u) goto label_000CEB1A;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> Incorrect number of args in 'tcoords'.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEB11u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4CEB11u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEB17u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4CEB17u));
    cpu->esp += 0x14u;
    label_000CEB1A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEB2Du)); sfera_sub_004CE700(cpu, LIFT_CODE_TOKEN_VA(0x4CEB2Du));
    lift_push32(cpu, (uintptr_t)"tcoords");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEB39u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4CEB39u));
    if (cpu->eax != 0u) goto label_000CEAB6;
    label_000CEB41:
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEB4Du)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x4CEB4Du));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x148u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CEB70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEB82u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x4CEB82u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].x) = cpu->fpu[0u];
    g_sfera_scene_render_runtime.interface_quad[0].diffuse = cpu->esi;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    g_sfera_scene_render_runtime.interface_quad[1].diffuse = cpu->esi;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].y) = cpu->fpu[0u];
    g_sfera_scene_render_runtime.interface_quad[2].diffuse = cpu->esi;
    lift_x87_push(cpu, 1.0);
    g_sfera_scene_render_runtime.interface_quad[3].diffuse = cpu->esi;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].rhw) = cpu->fpu[0u];
    cpu->esi = lift_pop32(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].z) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].x) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].y) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].rhw) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].z) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].x) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].y) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].rhw) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].z) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].x) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].y) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].rhw) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].z) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x10u) = 0x20u;
    *(uint32_t*)(cpu->esp + 0xCu) = (uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].x;
    *(uint32_t*)(cpu->esp + 8u) = 2u;
    *(uint32_t*)(cpu->esp + 4u) = 6u;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    sfera_sub_004D9050(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004CEC50(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    g_sfera_scene_render_runtime.interface_quad[0].diffuse = cpu->ecx;
    lift_x87_push(cpu, 0.5);
    cpu->fpu[1u] = (cpu->fpu[1u]) - (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].x) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    *(uint32_t*)(cpu->esp + 8u) = 2u;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[2u]);
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].y) = cpu->fpu[0u];
    lift_x87_push(cpu, 1.0);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].rhw) = cpu->fpu[0u];
    lift_x87_push(cpu, 0.0);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].z) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 4u));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].v) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    g_sfera_scene_render_runtime.interface_quad[1].diffuse = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[5u]);
    *(uint32_t*)(cpu->esp + 0xCu) = (uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].x;
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].x) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].y) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].rhw) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].z) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 8u));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0xCu));
    g_sfera_scene_render_runtime.interface_quad[2].diffuse = cpu->ecx;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].v) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].x) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(uint32_t*)(cpu->esp + 0x10u) = 0x20u;
    cpu->fpu[4u] = cpu->fpu[0u] - cpu->fpu[4u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(uint32_t*)(cpu->esp + 4u) = 6u;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].y) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].rhw) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].z) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x10u));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x14u));
    g_sfera_scene_render_runtime.interface_quad[3].diffuse = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].v) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].x) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].y) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].rhw) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].z) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x18u));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x1Cu));
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].v) = cpu->fpu[0u]; lift_x87_pop(cpu);
    sfera_sub_004D9050(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004CEDA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->eax > 0) goto label_000CEDBA;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEDB8u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x4CEDB8u));
    goto label_000CEDD3;
    label_000CEDBA:
    { uint64_t l=g_sfera_sprite_runtime.render_mode, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CEDC9;
    cpu->edx = 0u;
    goto label_000CEDCE;
    label_000CEDC9:
    cpu->edx = 1u;
    label_000CEDCE:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCEDD3u)); sfera_sub_0044FCB0(cpu, LIFT_CODE_TOKEN_RVA(0xCEDD3u));
    label_000CEDD3:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEE00u)); sfera_sub_004CEC50(cpu, LIFT_CODE_TOKEN_VA(0x4CEE00u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CEE10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEE21u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x4CEE21u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEE4Eu)); sfera_sub_004CEC50(cpu, LIFT_CODE_TOKEN_VA(0x4CEE4Eu));
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CEE60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x94u) == 0u) goto label_000CEFE3;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    lift_push32(cpu, cpu->edi);
    *(double*)(cpu->esp + 0x10u) = cpu->fpu[0u];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEE81u)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x4CEE81u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, *(double*)(cpu->esp + 0x10u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEE8Eu)); sfera_sub_004EE9F2(cpu, LIFT_CODE_TOKEN_VA(0x4CEE8Eu));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x90u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x1Cu)));
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = 1u;
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, 0.5);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x2Cu)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[0u] = (cpu->fpu[0u]) - (cpu->fpu[4u]);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x24u)));
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x2Cu)));
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x20u)));
    cpu->fpu[4u] = cpu->fpu[0u] - cpu->fpu[4u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (g_sfera_sprite_runtime.render_mode == cpu->edx) goto label_000CEF4C;
    cpu->edx = 0u;
    label_000CEF4C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEF51u)); sfera_sub_0044FCB0(cpu, LIFT_CODE_TOKEN_VA(0x4CEF51u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u];
    cpu->eax = cpu->esi + 0xCu;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    lift_push32(cpu, 0x20u);
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    lift_push32(cpu, 2u);
    *(float*)(cpu->esi + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 6u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x1Cu));
    *(float*)(cpu->esi + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[2u]);
    *(float*)(cpu->esi + 0x2Cu) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[2u]);
    *(float*)(cpu->esi + 0x30u) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    *(float*)(cpu->esi + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x20u));
    *(float*)(cpu->esi + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[3u] = cpu->fpu[3u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esi + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x50u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x14u));
    *(float*)(cpu->esi + 0x64u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x24u));
    *(float*)(cpu->esi + 0x68u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x6Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x18u));
    *(float*)(cpu->esi + 0x84u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x28u));
    *(float*)(cpu->esi + 0x88u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CEFE2u)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x4CEFE2u));
    cpu->edi = lift_pop32(cpu);
    label_000CEFE3:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CEFF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0x90u) == cpu->edi) goto label_000CF005;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCF005u)); sfera_sub_004CDFF0(cpu, LIFT_CODE_TOKEN_RVA(0xCF005u));
    label_000CF005:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    lift_x87_push(cpu, 1.0);
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x94u);
    *(uint32_t*)(cpu->esi + 0x94u) = cpu->edx;
    *(float*)(cpu->esi + 0x18u) = cpu->fpu[0u];
    lift_x87_push(cpu, 0.0);
    cpu->eax |= 0xFFFFFFFFu;
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->edi;
    *(float*)(cpu->esi + 0x38u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->eax;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->edi;
    *(float*)(cpu->esi + 0x34u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->eax;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->edi;
    *(float*)(cpu->esi + 0x58u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->esi + 0x7Cu) = cpu->eax;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(uint32_t*)(cpu->esi + 0x80u) = cpu->edi;
    *(float*)(cpu->esi + 0x54u) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x78u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x74u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->ebp);
    if (cpu->eax == cpu->edi) goto label_000CF074;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCF074u)); sfera_sub_004CDF70(cpu, LIFT_CODE_TOKEN_RVA(0xCF074u));
    label_000CF074:
    if (*(uint32_t*)(cpu->esi + 0x94u) <= cpu->edi) goto label_000CF154;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0x71u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF090u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CF090u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x94u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0x3Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF0ACu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4CF0ACu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x94u);
    cpu->edx = cpu->ecx;
    cpu->edx <<= 4u;
    cpu->edx -= cpu->ecx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x90u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4CF0CCu));
    cpu->esp += 0x10u;
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x94u) <= cpu->edi) goto label_000CF14B;
    label_000CF0E0:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x90u);
    if (*(uint32_t*)(cpu->edi + cpu->edx) == 0u) goto label_000CF13F;
    cpu->edx = 0x78u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF0FBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CF0FBu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x90u);
    cpu->eax = *(uint32_t*)(cpu->edi + cpu->eax);
    cpu->edx = cpu->eax + 1u;
    label_000CF107:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000CF107;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF117u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4CF117u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    *(uint32_t*)(cpu->edi + cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x90u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->edi + cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->edi + cpu->eax);
    cpu->esp += 4u;
    label_000CF135:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000CF135;
    label_000CF13F:
    ++cpu->ebx;
    cpu->edi += 0x3Cu;
    if (cpu->ebx < *(uint32_t*)(cpu->esi + 0x94u)) goto label_000CF0E0;
    label_000CF14B:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000CF154:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF160(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_000CF182;
    cpu->edx = 0x88u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF177u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CF177u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF17Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4CF17Fu));
    cpu->esp += 4u;
    label_000CF182:
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF191u)); sfera_sub_004CDFF0(cpu, LIFT_CODE_TOKEN_VA(0x4CF191u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF1A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF1AEu)); sfera_sub_004CDF70(cpu, LIFT_CODE_TOKEN_VA(0x4CF1AEu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF1B7u)); sfera_sub_004CDFF0(cpu, LIFT_CODE_TOKEN_VA(0x4CF1B7u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF1C5u)); sfera_sub_004CE4F0(cpu, LIFT_CODE_TOKEN_VA(0x4CF1C5u));
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x7Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x30u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x38u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF1F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF1FEu)); sfera_sub_004CDF70(cpu, LIFT_CODE_TOKEN_VA(0x4CF1FEu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF207u)); sfera_sub_004CDFF0(cpu, LIFT_CODE_TOKEN_VA(0x4CF207u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x98u);
    if ((((cpu->ecx & 0xFFu)) & (2u)) == 0u) goto label_000CF21A;
    cpu->eax = cpu->edi + 0x88u;
    goto label_000CF21C;
    label_000CF21A:
    cpu->eax = 0u;
    label_000CF21C:
    { uint64_t l=(cpu->ecx & 0xFFu), r=4u, v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ecx = cpu->edi + 0x40u;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CF226;
    cpu->ecx = cpu->edi;
    label_000CF226:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF232u)); sfera_sub_004CE4F0(cpu, LIFT_CODE_TOKEN_VA(0x4CF232u));
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x7Cu) = cpu->eax;
    if (((*(uint8_t*)(cpu->edi + 0x98u)) & (1u)) == 0u) goto label_000CF261;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x80u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x84u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000CF261:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x30u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x38u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF280(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x8Cu);
    if ((int32_t)cpu->eax <= 0) goto label_000CF296;
    --cpu->eax;
    *(uint32_t*)(cpu->esi + 0x8Cu) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000CF296:
    cpu->edx = 0x9Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF2A5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CF2A5u));
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_000CF2C4;
    cpu->edx = 0x88u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF2B9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CF2B9u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF2C1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4CF2C1u));
    cpu->esp += 4u;
    label_000CF2C4:
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF2D3u)); sfera_sub_004CDFF0(cpu, LIFT_CODE_TOKEN_VA(0x4CF2D3u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF2D9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4CF2D9u));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF2E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF2E8u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4CF2E8u));
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    std::construct_at(reinterpret_cast<SphereUI::TextCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x50u) = 2u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (((*(uint8_t*)(cpu->esi + 0x198u)) & (1u)) == 0u) goto label_000CF3C7;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == cpu->edx) goto label_000CF36C;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    if (cpu->ecx == cpu->edx) goto label_000CF35E;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCF35Eu)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xCF35Eu));
    label_000CF35E:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += *(uint32_t*)(cpu->esp + 8u);
    label_000CF36C:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    if ((int32_t)cpu->edx < (int32_t)cpu->eax) goto label_000CF3C5;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ebx += cpu->eax;
    { uint64_t l=cpu->edx, r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_pop32(cpu);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000CF3C5;
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_000CF3C5;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)cpu->eax >= (int32_t)cpu->edx) goto label_000CF3C5;
    if (((*(uint8_t*)(cpu->ebp + 0xCu)) & (1u)) == 0u) goto label_000CF3C5;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x3E9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCF3C5u)); sfera_sub_004D3290(cpu, LIFT_CODE_TOKEN_RVA(0xCF3C5u));
    label_000CF3C5:
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_000CF3C7:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF3F8u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4CF3F8u));
    cpu->ecx = cpu->esi + 0x28u;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->ecx) == cpu->edi) goto label_000CF406;
    if (*(uint32_t*)(cpu->esi + 0x2Cu) != cpu->edi) goto label_000CF431;
    label_000CF406:
    if (*(uint32_t*)(cpu->esi + 0x64u) <= cpu->edi) goto label_000CF431;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x68u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->esi + 0x54u;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000CF416;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000CF416:
    cpu->edx = cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Du);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCF431u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_RVA(0xCF431u));
    label_000CF431:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"textStyle");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF442u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4CF442u));
    if (cpu->eax == 0u) goto label_000CF49A;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF454u)); sfera_sub_004947E0(cpu, LIFT_CODE_TOKEN_VA(0x4CF454u));
    cpu->ebx = cpu->eax;
    if ((int32_t)cpu->ebx <= (int32_t)cpu->edi) goto label_000CF499;
    label_000CF460:
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.text_style_token); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF46Du)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4CF46Du));
    if (cpu->eax == 0u) goto label_000CF492;
    lift_push32(cpu, (uintptr_t)"NOTIFY_CLICK"); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.text_style_token);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4CF47Bu));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000CF492;
    *(uint32_t*)(cpu->esi + 0x198u) = 1u;
    label_000CF492:
    cpu->edi += 2u;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebx) goto label_000CF460;
    label_000CF499:
    cpu->ebx = lift_pop32(cpu);
    label_000CF49A:
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF4A6u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4CF4A6u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000CF661;
    cpu->edx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x64u) == cpu->edx) goto label_000CF661;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ebp = 0u;
    cpu->ebx = 0u;
    if (cpu->edi == cpu->edx) goto label_000CF51D;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if (cpu->ecx == cpu->edx) goto label_000CF50D;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCF50Du)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xCF50Du));
    label_000CF50D:
    cpu->ebp = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ebp += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = 0u;
    label_000CF51D:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += cpu->ebp;
    g_sfera_screen_clip_runtime.left = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += cpu->ebx;
    g_sfera_screen_clip_runtime.top = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edi += cpu->eax;
    g_sfera_screen_clip_runtime.right = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax += cpu->ecx;
    g_sfera_screen_clip_runtime.bottom = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0x118u) == cpu->edx) goto label_000CF5E0;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x68u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->esi + 0x54u;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000CF566;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000CF566:
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Du);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF586u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4CF586u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x118u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    if ((((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_000CF5A2;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    if (cpu->edi >= cpu->eax) goto label_000CF5A2;
    cpu->eax -= cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_000CF5A2:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((((cpu->edx & 0xFFu)) & (2u)) == 0u) goto label_000CF5B8;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    if (cpu->ecx >= cpu->eax) goto label_000CF5B8;
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000CF5B8:
    if ((((cpu->edx & 0xFFu)) & (4u)) == 0u) goto label_000CF5CC;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    if (cpu->edi >= cpu->eax) goto label_000CF5CC;
    { uint64_t l=cpu->eax, r=cpu->edi, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax >>= 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_000CF5CC:
    if ((((cpu->edx & 0xFFu)) & (8u)) == 0u) goto label_000CF5E0;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    if (cpu->ecx >= cpu->eax) goto label_000CF5E0;
    { uint64_t l=cpu->eax, r=cpu->ecx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax >>= 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000CF5E0:
    cpu->edi = 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0xDCu) != cpu->edi) goto label_000CF5FD;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000CF5FD;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCF5FDu)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xCF5FDu));
    label_000CF5FD:
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x68u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->esi + 0x54u;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000CF608;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000CF608:
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Du);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx += cpu->ebx;
    cpu->edx += *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += cpu->ebp;
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF63Fu)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4CF63Fu));
    { uint64_t l=*(uint32_t*)(cpu->esi + 0xDCu), r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CF661;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000CF661;
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    sfera_sub_004CE0E0(cpu, stop_address); return;
    label_000CF661:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF670(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0xAEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\TextCtrl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF6A4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CF6A4u));
    lift_push32(cpu, 0x1A0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF6AEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4CF6AEu));
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->esi == 0u) goto label_000CF6E7;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF6CAu)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4CF6CAu));
    std::construct_at(reinterpret_cast<SphereUI::TextCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x198u) = 0u;
    *(uint32_t*)(cpu->esi + 0x50u) = 2u;
    *(uint8_t*)(cpu->esi + 0x48u) = 0u;
    goto label_000CF6E9;
    label_000CF6E7:
    cpu->esi = 0u;
    label_000CF6E9:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF6F9u)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4CF6F9u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x198u);
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_000CF72D;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCF72Du)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xCF72Du));
    label_000CF72D:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF750(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_push(cpu, 0.0);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    *(float*)(cpu->ecx + 0x1B0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint8_t*)(cpu->ecx + 0x48u) = 1u;
    *(uint8_t*)(cpu->ecx + 0x1A0u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->ecx + 0x1CCu) = cpu->eax & 0xFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF770(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x1B0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000CF795;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF789u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4CF789u));
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->edx;
    label_000CF795:
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax += 0xAu;
    cpu->ecx += 0x14u;
    *(uint8_t*)(cpu->esi + 0x48u) = 0u;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CF7C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->ecx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CF9EE;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->ecx + 0x10u) == cpu->ebx) goto label_000CF9EE;
    if (*(uint8_t*)(cpu->esi + 0x48u) != (cpu->ebx & 0xFFu)) goto label_000CF869;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x1B0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000CF869;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF818u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4CF818u));
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esi + 0x1B8u), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(*(uint32_t*)(cpu->esi + 0x1BCu)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_x87_push(cpu, (double)(((int64_t)(*(uint64_t*)(cpu->esp + 0xCu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (10000.0);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (4.0);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    *(float*)(cpu->esi + 0x1B0u) = cpu->fpu[0u];
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000CF867;
    *(float*)(cpu->esi + 0x1B0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000CF869;
    label_000CF867:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000CF869:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    if (cpu->edi == cpu->ebx) goto label_000CF9B9;
    if (*(uint8_t*)(cpu->edi + 0x48u) != (cpu->ebx & 0xFFu)) goto label_000CF9B9;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if (cpu->ecx == cpu->ebx) goto label_000CF8A2;
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCF8A2u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xCF8A2u));
    label_000CF8A2:
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ebx += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2Cu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ebp += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->eax += cpu->ebp;
    cpu->ecx += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if ((((cpu->edx & 0xFFu)) & (3u)) != 0u) goto label_000CF8D5;
    if (*(uint32_t*)(cpu->edi + 8u) == 0u) goto label_000CF8E0;
    label_000CF8D5:
    *(uint8_t*)(cpu->esi + 0x1CCu) = 1u;
    *(uint8_t*)(cpu->esi + 0x48u) = 1u;
    label_000CF8E0:
    if (*(uint8_t*)(cpu->esi + 0x48u) == 0u) goto label_000CF96B;
    if (*(uint8_t*)(cpu->esi + 0x1CCu) != 0u) goto label_000CF96B;
    if (*(uint8_t*)(cpu->esi + 0x1A0u) == 0u) goto label_000CF9C2;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x198u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_000CF9C2;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x19Cu);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_000CF9C2;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF922u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4CF922u));
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esi + 0x1A8u), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(*(uint32_t*)(cpu->esi + 0x1ACu)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    lift_x87_push(cpu, (double)(((int64_t)(*(uint64_t*)(cpu->esp + 0x1Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (10000.0);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)0.5f));
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000CF963;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCF963u)); sfera_sub_004CF770(cpu, LIFT_CODE_TOKEN_RVA(0xCF963u));
    label_000CF963:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    label_000CF96B:
    cpu->edx = *(uint32_t*)(cpu->edi);
    { uint64_t l=cpu->edx, r=cpu->ebp, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_pop32(cpu);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000CF9CB;
    if ((int32_t)cpu->edx >= (int32_t)cpu->eax) goto label_000CF9CB;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if ((int32_t)cpu->eax < (int32_t)cpu->ebx) goto label_000CF9CB;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_000CF9CB;
    if (*(uint8_t*)(cpu->esi + 0x1A0u) != 0u) goto label_000CF9B9;
    if (*(uint8_t*)(cpu->esi + 0x48u) == 0u) goto label_000CF9B9;
    *(uint8_t*)(cpu->esi + 0x1A0u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CF9ADu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4CF9ADu));
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->edx;
    label_000CF9B9:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000CF9C2:
    *(uint8_t*)(cpu->esi + 0x1A0u) = 0u;
    goto label_000CF96B;
    label_000CF9CB:
    lift_x87_push(cpu, 0.0);
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->esi + 0x1B0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint8_t*)(cpu->esi + 0x48u) = 1u;
    *(uint8_t*)(cpu->esi + 0x1A0u) = 0u;
    *(uint8_t*)(cpu->esi + 0x1CCu) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000CF9EE:
    *(uint8_t*)(cpu->esi + 0x48u) = 1u;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CFA00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000CFD88;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->eax = g_sfera_graphics_runtime.display_width;
    cpu->edx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if ((int32_t)cpu->edx <= (int32_t)cpu->eax) goto label_000CFA33;
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->eax;
    label_000CFA33:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->eax = g_sfera_graphics_runtime.display_height;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->ecx += cpu->ebx;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->ecx <= (int32_t)cpu->eax) goto label_000CFA55;
    cpu->eax -= cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->eax;
    label_000CFA55:
    cpu->ecx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x198u) >= (int32_t)cpu->ecx) goto label_000CFA65;
    *(uint32_t*)(cpu->esi + 0x198u) = cpu->ecx;
    label_000CFA65:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x19Cu) >= (int32_t)cpu->ecx) goto label_000CFA73;
    *(uint32_t*)(cpu->esi + 0x19Cu) = cpu->ecx;
    label_000CFA73:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x9Cu);
    if (cpu->eax != cpu->ecx) goto label_000CFA7F;
    cpu->eax = cpu->esi;
    label_000CFA7F:
    cpu->edx = *(uint32_t*)(cpu->eax + 0xDCu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0xDCu)))));
    if ((int32_t)cpu->edx >= 0) goto label_000CFA95;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000CFA95:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x1B0u)));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x198u);
    *(uint16_t*)(cpu->esp + 0x10u) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->esp -= 0x10u;
    cpu->ecx &= 0xFFFFFFu;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    { uint64_t l=cpu->edx, r=cpu->ebx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    *(uint64_t*)(cpu->esp + 0x30u) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax = cpu->edi;
    cpu->eax <<= 24u;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x20u);
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C0u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    cpu->ebp += *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebp;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))));
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu)))));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u)))));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u)))));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CFB2Bu)); sfera_sub_004CEB70(cpu, LIFT_CODE_TOKEN_VA(0x4CFB2Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C4u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    cpu->esp -= 0x10u;
    cpu->eax += cpu->ecx;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu)))));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u)))));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u)))));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CFB7Du)); sfera_sub_004CEB70(cpu, LIFT_CODE_TOKEN_VA(0x4CFB7Du));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->eax += *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C4u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    cpu->esp -= 0x10u;
    cpu->edx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    --cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu)))));
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu)))));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u)))));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CFBD5u)); sfera_sub_004CEB70(cpu, LIFT_CODE_TOKEN_VA(0x4CFBD5u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    cpu->esp -= 0x10u;
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu)))));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u)))));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u)))));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CFC27u)); sfera_sub_004CEB70(cpu, LIFT_CODE_TOKEN_VA(0x4CFC27u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x19Cu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    cpu->esp -= 0x10u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    --cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))));
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u)))));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu)))));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CFC7Fu)); sfera_sub_004CEB70(cpu, LIFT_CODE_TOKEN_VA(0x4CFC7Fu));
    if (cpu->edi != 0xFFu) goto label_000CFC97;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000CFC97;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xCFC97u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xCFC97u));
    label_000CFC97:
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x1E4u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1E8u);
    cpu->ebp += *(uint32_t*)(cpu->esi + 0x198u);
    cpu->edi += *(uint32_t*)(cpu->esi + 0x19Cu);
    g_sfera_screen_clip_runtime.left = cpu->ebp;
    g_sfera_screen_clip_runtime.top = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1C4u);
    cpu->eax += cpu->ebp;
    g_sfera_screen_clip_runtime.right = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C8u);
    cpu->ecx += cpu->edi;
    g_sfera_screen_clip_runtime.bottom = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->ecx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->ebx = 0u;
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CFD64;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    label_000CFD00:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CFD12;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000CFD12:
    lift_x87_push(cpu, 0.0);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x90u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Cu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CFD35u)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4CFD35u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->edi += *(uint32_t*)(cpu->esi + 0x1E0u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->ecx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    ++cpu->ebx;
    cpu->eax += cpu->edx;
    if (cpu->ebx < cpu->eax) goto label_000CFD00;
    label_000CFD64:
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x20u), r=0xFFu, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CFD88;
    if (*(uint8_t*)(cpu->esi + 0x8Cu) >= 2u) goto label_000CFD88;
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    sfera_sub_004CE0E0(cpu, stop_address); return;
    label_000CFD88:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CFD90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->ecx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->edi);
    lift_flags_logic(cpu,0u,32u); cpu->ebp = 0u;
    cpu->eax >>= 31u;
    cpu->edi = 0u;
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CFE28;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    label_000CFDC4:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->eax += cpu->ebx;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000CFDD4;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000CFDD4:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CFDEEu)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4CFDEEu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->eax <= cpu->ebp) goto label_000CFE00;
    cpu->ebp = cpu->eax;
    label_000CFE00:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1D4u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x1D0u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->ecx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    ++cpu->edi;
    cpu->ecx += cpu->edx;
    cpu->ebx += 0x1Cu;
    if (cpu->edi < cpu->ecx) goto label_000CFDC4;
    cpu->ebx = lift_pop32(cpu);
    label_000CFE28:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1ECu);
    cpu->eax += *(uint32_t*)(cpu->esi + 0x1E4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1F0u);
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x1E8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += cpu->ebp;
    cpu->ecx += *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x1E0u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x1C4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CFE70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CFE78u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4CFE78u));
    lift_x87_push(cpu, 0.0);
    cpu->eax = 0u;
    *(uint8_t*)(cpu->esi + 0x1A0u) = cpu->eax & 0xFFu;
    std::construct_at(reinterpret_cast<SphereUI::ToolTipCtrl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1ACu) = cpu->eax;
    *(float*)(cpu->esi + 0x1B0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1BCu) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x1CCu) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1C0u) = 0xFFFFE1u;
    *(uint32_t*)(cpu->esi + 0x1D0u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1D4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1D8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->eax;
    cpu->eax = 2u;
    cpu->ecx = 1u;
    *(uint8_t*)(cpu->esi + 0x8Cu) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1ECu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x50u) = 9u;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1C4u) = 0x34u;
    *(uint32_t*)(cpu->esi + 0x1C8u) = 0xCu;
    *(uint32_t*)(cpu->esi + 0x1E4u) = 3u;
    *(uint32_t*)(cpu->esi + 0x1E8u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x1F0u) = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CFF20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x95u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ToolTip.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CFF54u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4CFF54u));
    lift_push32(cpu, 0x1F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CFF5Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4CFF5Eu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if (cpu->eax == cpu->esi) goto label_000CFF78;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CFF76u)); sfera_sub_004CFE70(cpu, LIFT_CODE_TOKEN_VA(0x4CFF76u));
    cpu->esi = cpu->eax;
    label_000CFF78:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4CFF88u)); sfera_sub_004C3420(cpu, LIFT_CODE_TOKEN_VA(0x4CFF88u));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004CFFA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x2Cu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    if (cpu->ecx == 0u) goto label_000D003B;
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    *(uint8_t*)(cpu->esp + 0xCu) = 0u;
    cpu->edi = cpu->eax + 1u;
    label_000CFFF4:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000CFFF4;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0008u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4D0008u));
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1D0u;
    *(uint32_t*)(cpu->esp + 0x38u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0020u)); sfera_sub_004C5A50(cpu, LIFT_CODE_TOKEN_VA(0x4D0020u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0027u)); sfera_sub_004CFD90(cpu, LIFT_CODE_TOKEN_VA(0x4D0027u));
    if (*(uint32_t*)(cpu->esp + 0x20u) < 0x10u) goto label_000D003B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0038u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D0038u));
    cpu->esp += 4u;
    label_000D003B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0060(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1D4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->ebx + 0x1D0u);
    cpu->ecx -= cpu->ebp;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->ecx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += cpu->edx;
    if (cpu->edi < cpu->eax) goto label_000D00A0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D009Au)); sfera_sub_004CFFA0(cpu, LIFT_CODE_TOKEN_VA(0x4D009Au));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D00A0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->esi == 0u) goto label_000D011C;
    cpu->edx = cpu->edi * 8u;
    cpu->edx -= cpu->edi;
    { uint64_t l=*(uint32_t*)(cpu->ebp + (cpu->edx * 4u) + 0x14u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->ebp + (cpu->edx * 4u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D00BF;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000D00BF:
    cpu->ecx = cpu->esi;
    label_000D00C1:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D00E1;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000D00DD;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx + 1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D00E1;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000D00C1;
    label_000D00DD:
    cpu->eax = 0u;
    goto label_000D00E6;
    label_000D00E1:
    { uint64_t l=cpu->eax, r=cpu->eax, c=((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000D00E6:
    if (cpu->eax == 0u) goto label_000D0115;
    cpu->edx = cpu->esi;
    label_000D00EC:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000D00F1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000D00F1;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->edi * 8u;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + (cpu->eax * 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D010Eu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4D010Eu));
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD0115u)); sfera_sub_004CFD90(cpu, LIFT_CODE_TOKEN_RVA(0xD0115u));
    label_000D0115:
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D011C:
    cpu->edx = (uintptr_t)"";
    goto label_000D00EC;
}
__declspec(noinline) void sfera_sub_004D0130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->edx + 0xFFFFF447u;
    if (cpu->eax > 0x1F3u) goto label_000D020B;
    if (cpu->edx == 0xDACu) goto label_000D01F4;
    if (cpu->eax > 3u) goto label_000D0206;
    switch (cpu->eax) {
        case 0u: goto label_000D01B9;
        case 1u: goto label_000D0161;
        case 2u: goto label_000D01D0;
        case 3u: goto label_000D01E2;
        default: lift_trap(cpu, 0x4D015Au, "resolved jump-table index out of range"); return;
    }
label_000D0161: ;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x1D4u);
    cpu->esi -= *(uint32_t*)(cpu->ecx + 0x1D0u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->esi, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx >= cpu->eax) goto label_000D01B1;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x1D0u);
    cpu->eax = cpu->edx * 8u;
    cpu->eax -= cpu->edx;
    { uint64_t l=*(uint32_t*)(cpu->ecx + (cpu->eax * 4u) + 0x14u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D01A5;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000D01A5:
    cpu->edx -= cpu->eax;
    label_000D01A7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000D01A7;
    label_000D01B1:
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D01B9:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D01C8u)); sfera_sub_004D0060(cpu, LIFT_CODE_TOKEN_VA(0x4D01C8u));
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D01D0:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D01DAu)); sfera_sub_004CFFA0(cpu, LIFT_CODE_TOKEN_VA(0x4D01DAu));
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D01E2:
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx + 0x1C0u) = cpu->eax;
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D01F4:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx + 0x90u) = cpu->edx;
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D0206:
    cpu->eax = 0u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D020B:
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    sfera_sub_004D2DD0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004D0230(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x4Cu;
    (void)0; /* source SEH registration eliminated */
    cpu->eax = *(uint32_t*)(cpu->esp + 0x5Cu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->esi = cpu->ecx;
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0280u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4D0280u));
    if (*(uint32_t*)(cpu->esi + 0x9Cu) != 0u) goto label_000D02A3;
    lift_push32(cpu, 0x66u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ToolTip.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D029Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D029Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D02A0u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D02A0u));
    cpu->esp += 0x10u;
    label_000D02A3:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"font");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D02B0u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D02B0u));
    if (cpu->eax == 0u) goto label_000D02C3;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D02BDu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4D02BDu));
    *(uint8_t*)(cpu->esi + 0x8Cu) = cpu->eax & 0xFFu;
    label_000D02C3:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"textColor");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D02D0u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D02D0u));
    cpu->ebx = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_000D033E;
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD02F4u), LIFT_CODE_TOKEN_RVA(0xD02F2u))) { return; }
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000D031B;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"ToolTipCtrl::LoadUI(%s,%d,%d) -> Not enough args in 'textcolor'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0312u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D0312u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0318u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D0318u));
    cpu->esp += 0x14u;
    label_000D031B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x18u);
    { uint64_t l=cpu->eax, r=0xFFFFFF00u, v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax <<= 8u;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax <<= 8u;
    cpu->eax |= cpu->edx;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->eax;
    label_000D033E:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"backcolor");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D034Bu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D034Bu));
    if (cpu->eax == 0u) goto label_000D03B4;
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD0369u), LIFT_CODE_TOKEN_RVA(0xD0367u))) { return; }
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000D0390;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ToolTipCtrl::LoadUI(%s,%d,%d) -> Not enough args in 'backcolor'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0387u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D0387u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D038Du)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D038Du));
    cpu->esp += 0x14u;
    label_000D0390:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint8_t*)(cpu->esp + 0x1Cu);
    { uint64_t l=cpu->ecx, r=0xFFFFFF00u, v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx <<= 8u;
    { uint64_t l=cpu->ecx, r=cpu->edx, v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1C0u) = cpu->ecx;
    label_000D03B4:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"margin");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D03C1u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D03C1u));
    if (cpu->eax == 0u) goto label_000D0413;
    cpu->ecx = cpu->esi + 0x1F0u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x1ECu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x1E8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1E4u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD03ECu), LIFT_CODE_TOKEN_RVA(0xD03EAu))) { return; }
    cpu->esp += 0x18u;
    if (cpu->eax == 4u) goto label_000D0413;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"ToolTipCtrl::LoadUI(%s,%d,%d) -> Not enough args in 'margin'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D040Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D040Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0410u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D0410u));
    cpu->esp += 0x14u;
    label_000D0413:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D041Bu)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x4D041Bu));
    lift_push32(cpu, (uintptr_t)"toolstr");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0427u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4D0427u));
    if (cpu->eax == 0u) goto label_000D04E6;
    (void)cpu;
    label_000D0430:
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.tooltip_key);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D043Fu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4D043Fu));
    if (cpu->eax == 0u) goto label_000D04D2;
    cpu->ecx = (uintptr_t)g_sfera_ui_load_scratch_runtime.tooltip_key;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0451u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4D0451u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000D045B;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    goto label_000D045D;
    label_000D045B:
    cpu->ecx = cpu->eax;
    label_000D045D:
    if (cpu->ecx == cpu->ebx) goto label_000D04D2;
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x40u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x2Cu) = cpu->ebx & 0xFFu;
    cpu->edi = cpu->eax + 1u;
    label_000D0476:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000D0476;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D048Au)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4D048Au));
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1D0u;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D049Eu)); sfera_sub_004C5A50(cpu, LIFT_CODE_TOKEN_VA(0x4D049Eu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D04A5u)); sfera_sub_004CFD90(cpu, LIFT_CODE_TOKEN_VA(0x4D04A5u));
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x40u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x54u) = 0xFFFFFFFFu;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D04C1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D04BEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D04BEu));
    cpu->esp += 4u;
    label_000D04C1:
    *(uint32_t*)(cpu->esp + 0x40u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x2Cu) = 0u;
    label_000D04D2:
    lift_push32(cpu, (uintptr_t)"toolstr");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D04DEu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4D04DEu));
    if (cpu->eax != 0u) goto label_000D0430;
    label_000D04E6:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D04EDu)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_VA(0x4D04EDu));
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D04F9u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4D04F9u));
    cpu->eax = 1u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000D0658;
    if (*(uint32_t*)(cpu->esi + 0x1B4u) == 0u) goto label_000D0658;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == 0u) goto label_000D0586;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    if (cpu->ecx == 0u) goto label_000D0578;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD0578u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xD0578u));
    label_000D0578:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 8u);
    label_000D0586:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1B4u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    cpu->edx = cpu->eax + 4u;
    cpu->edi = cpu->eax + 8u;
    lift_push32(cpu, 0u);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0xCu)))));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xDCu);
    { uint64_t l=cpu->esp, r=0x10u, v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx <<= 24u;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edx)))));
    cpu->ecx |= 0xFFFFFFu;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = ((double)(((int32_t)(*(uint32_t*)(cpu->edi))))) / (cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi)))));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edx)))));
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0657u)); sfera_sub_004CEE10(cpu, LIFT_CODE_TOKEN_VA(0x4D0657u));
    cpu->edi = lift_pop32(cpu);
    label_000D0658:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x1B8u) == cpu->edx) goto label_000D077F;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == cpu->edx) goto label_000D06C2;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    if (cpu->ecx == cpu->edx) goto label_000D06B4;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD06B4u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xD06B4u));
    label_000D06B4:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0xCu);
    label_000D06C2:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ebp += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ebx += cpu->ecx;
    if ((int32_t)cpu->ebp > (int32_t)cpu->eax) goto label_000D0786;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx += cpu->ebp;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_000D0786;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if ((int32_t)cpu->ebx > (int32_t)cpu->eax) goto label_000D0786;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ebx;
    if ((int32_t)cpu->eax >= (int32_t)cpu->edx) goto label_000D0786;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000D0734;
    if (*(uint8_t*)(cpu->esi + 0x1BCu) != 0u) goto label_000D0734;
    *(uint8_t*)(cpu->esi + 0x1BCu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x4Au) = cpu->ecx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->eax -= cpu->ebx;
    cpu->ecx -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0732u)); sfera_sub_0049D2F0(cpu, LIFT_CODE_TOKEN_VA(0x4D0732u));
    goto label_000D075E;
    label_000D0734:
    if ((((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_000D075E;
    if (*(uint8_t*)(cpu->esi + 0x1BCu) == 0u) goto label_000D075E;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B8u);
    *(uint8_t*)(cpu->esi + 0x1BCu) = 0u;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->edx -= cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD075Eu)); sfera_sub_0049D370(cpu, LIFT_CODE_TOKEN_RVA(0xD075Eu));
    label_000D075E:
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    if (cpu->eax == 0u) goto label_000D077C;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->ecx -= cpu->ebx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1B8u);
    cpu->edx -= cpu->ebp;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD077Cu)); sfera_sub_0049D470(cpu, LIFT_CODE_TOKEN_RVA(0xD077Cu));
    label_000D077C:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_000D077F:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D0786:
    if (((*(uint8_t*)(cpu->edi + 0xCu)) & (1u)) == 0u) goto label_000D077C;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 0x4Au) = 0u;
    cpu->eax = g_sfera_window_runtime.main_window;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->esp += 4u; lift_native_call(cpu, native_function_address32(&::SetFocus), LIFT_CODE_TOKEN_VA(0x4D07A0u)); cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4D0786u), "function fell through without control transfer");
}
__declspec(noinline) void sfera_sub_004D07B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = 0u;
    if (*(uint32_t*)(cpu->edi + 0x1B4u) == cpu->eax) goto label_000D087F;
    if (*(uint32_t*)(cpu->edi + 0x1B8u) == cpu->eax) goto label_000D087F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi + 0x9Cu);
    cpu->ecx = 0u;
    if (cpu->esi == cpu->eax) goto label_000D080D;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000D07FF;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD07FFu)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xD07FFu));
    label_000D07FF:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    label_000D080D:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->esi += cpu->eax;
    cpu->ebx += cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D081Cu)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4D081Cu));
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)cpu->esi > (int32_t)cpu->eax) goto label_000D085D;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x28u);
    cpu->ecx += cpu->esi;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_000D085D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->ebx > (int32_t)cpu->ecx) goto label_000D085D;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x2Cu);
    cpu->edx += cpu->ebx;
    if ((int32_t)cpu->ecx >= (int32_t)cpu->edx) goto label_000D085D;
    cpu->ecx -= cpu->ebx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B8u);
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD085Du)); sfera_sub_0049D3F0(cpu, LIFT_CODE_TOKEN_RVA(0xD085Du));
    label_000D085D:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1B4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0872u)); sfera_sub_0049D220(cpu, LIFT_CODE_TOKEN_VA(0x4D0872u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D087Du)); sfera_sub_00419BF0(cpu, LIFT_CODE_TOKEN_VA(0x4D087Du));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D087F:
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0890(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0898u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4D0898u));
    cpu->eax = 0u;
    std::construct_at(reinterpret_cast<SphereUI::CWebBrowserControl*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x1A8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1ACu) = 0xFu;
    *(uint8_t*)(cpu->esi + 0x198u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x1BCu) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x50u) = 0x13u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D08E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::CWebBrowserControl*>(cpu->esi));
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x1B4u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D0949;
    cpu->edx = 0xA4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D092Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D092Fu));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1B4u);
    if (cpu->edi == 0u) goto label_000D0949;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0940u)); sfera_sub_00419BB0(cpu, LIFT_CODE_TOKEN_VA(0x4D0940u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0946u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D0946u));
    cpu->esp += 4u;
    label_000D0949:
    if (*(uint32_t*)(cpu->esi + 0x1B8u) == 0u) goto label_000D097B;
    cpu->edx = 0xA6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0961u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D0961u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1B8u);
    if (cpu->edi == 0u) goto label_000D097B;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0972u)); sfera_sub_0049D520(cpu, LIFT_CODE_TOKEN_VA(0x4D0972u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0978u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D0978u));
    cpu->esp += 4u;
    label_000D097B:
    if (*(uint32_t*)(cpu->esi + 0x1ACu) < 0x10u) goto label_000D0993;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0990u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D0990u));
    cpu->esp += 4u;
    label_000D0993:
    *(uint32_t*)(cpu->esi + 0x1ACu) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1A8u) = 0u;
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi + 0x198u) = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D09BDu)); sfera_sub_004D37D0(cpu, LIFT_CODE_TOKEN_VA(0x4D09BDu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D09D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D09D8u)); sfera_sub_004D08E0(cpu, LIFT_CODE_TOKEN_VA(0x4D09D8u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000D09E8;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D09E5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D09E5u));
    cpu->esp += 4u;
    label_000D09E8:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D09F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->esi;
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0A29u)); sfera_sub_004D51A0(cpu, LIFT_CODE_TOKEN_VA(0x4D0A29u));
    cpu->ebx = 0u;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = cpu->esi + 0x198u;
    std::construct_at(reinterpret_cast<SphereUI::CWebBrowserControl*>(cpu->esi));
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->edi + 0x198u;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    *(uint8_t*)(cpu->ecx) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0A55u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4D0A55u));
    *(uint8_t*)(cpu->esi + 0x1BCu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->ebx;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (*(uint32_t*)(cpu->edi + 0x1B4u) == cpu->ebx) goto label_000D0AE8;
    cpu->edx = cpu->ebx + 0x1Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0A7Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D0A7Eu));
    lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0A85u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D0A85u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 3u;
    if (cpu->eax == cpu->ebx) goto label_000D0AB0;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0AA1u)); sfera_sub_00419F50(cpu, LIFT_CODE_TOKEN_VA(0x4D0AA1u));
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    goto label_000D0AE8;
    label_000D0AB0:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    label_000D0AE8:
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->ebx;
    if (*(uint32_t*)(cpu->edi + 0x1B8u) == cpu->ebx) goto label_000D0B73;
    cpu->edx = 0x25u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0B09u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D0B09u));
    lift_push32(cpu, 0x3Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0B10u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D0B10u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 6u;
    if (cpu->eax == cpu->ebx) goto label_000D0B3B;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1B8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0B2Cu)); sfera_sub_0049D710(cpu, LIFT_CODE_TOKEN_VA(0x4D0B2Cu));
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    goto label_000D0B73;
    label_000D0B3B:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    label_000D0B73:
    if (*(uint32_t*)(cpu->edi + 0xECu) == cpu->ebx) goto label_000D0B96;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD0B96u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xD0B96u));
    label_000D0B96:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0AC1(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, (uintptr_t)"SphereUI::CWebBrowserControl::CWebBrowserControl(): failed to create bitmap/texture"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0AD0u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4D0AD0u));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    cpu->eax = LIFT_CALLBACK(sfera_sub_004D0AE0);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->ebx;
    if (*(uint32_t*)(cpu->edi + 0x1B8u) == cpu->ebx) goto label_000D0B73;
    cpu->edx = 0x25u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0B09u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D0B09u));
    lift_push32(cpu, 0x3Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0B10u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D0B10u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 6u;
    if (cpu->eax == cpu->ebx) goto label_000D0B3B;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1B8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0B2Cu)); sfera_sub_0049D710(cpu, LIFT_CODE_TOKEN_VA(0x4D0B2Cu));
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    goto label_000D0B73;
    label_000D0B3B:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    label_000D0B73:
    if (*(uint32_t*)(cpu->edi + 0xECu) == cpu->ebx) goto label_000D0B96;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD0B96u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xD0B96u));
    label_000D0B96:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->fs_data + (0u)) = cpu->ecx;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0B4C(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, (uintptr_t)"SphereUI::CWebBrowserControl::CWebBrowserControl(): failed to create web browser object"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0B5Bu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4D0B5Bu));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    cpu->eax = LIFT_CALLBACK(sfera_sub_004D0B6B);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0B6B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->edi + 0xECu) == cpu->ebx) goto label_000D0B96;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD0B96u)); sfera_sub_004D19D0(cpu, LIFT_CODE_TOKEN_RVA(0xD0B96u));
    label_000D0B96:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->fs_data + (0u)) = cpu->ecx;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0BB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0xBEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0BE3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D0BE3u));
    lift_push32(cpu, 0x1C0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0BEDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D0BEDu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->eax == 0u) goto label_000D0C19;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0C08u)); sfera_sub_004D09F0(cpu, LIFT_CODE_TOKEN_VA(0x4D0C08u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D0C19:
    cpu->eax = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0C30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->esi;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x28u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u)) {
        sfera_sub_004D0D7A(cpu, stop_address);
        return;
    }
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x2Cu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u)) {
        sfera_sub_004D0D7A(cpu, stop_address);
        return;
    }
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->edx == 0u) goto label_000D0C96;
    cpu->eax = cpu->edx;
    cpu->edi = cpu->eax + 1u;
    label_000D0C80:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000D0C80;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x198u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD0C96u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_RVA(0xD0C96u));
    label_000D0C96:
    if (*(uint32_t*)(cpu->esi + 0x1B4u) != 0u) goto label_000D0D1B;
    cpu->edx = 0x3Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0CB5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D0CB5u));
    lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0CBCu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D0CBCu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->eax == 0u) goto label_000D0CE8;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0CD9u)); sfera_sub_00419F30(cpu, LIFT_CODE_TOKEN_VA(0x4D0CD9u));
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    goto label_000D0D1B;
    label_000D0CE8:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x1B4u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    label_000D0D1B:
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x1B8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u)) {
        sfera_sub_004D0D7A(cpu, stop_address);
        return;
    }
    cpu->edx = 0x49u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0D3Au)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D0D3Au));
    lift_push32(cpu, 0x3Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0D41u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D0D41u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 4u;
    if (cpu->eax == 0u) goto label_000D0D72;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x1ACu), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = cpu->esi + 0x198u;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D0D60;
    cpu->edx = *(uint32_t*)(cpu->edx);
    label_000D0D60:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0D70u)); sfera_sub_0049D6A0(cpu, LIFT_CODE_TOKEN_VA(0x4D0D70u));
    goto label_000D0D74;
    label_000D0D72:
    cpu->eax = 0u;
    label_000D0D74:
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    sfera_sub_004D0D7A(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004D0CF9(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, (uintptr_t)"SphereUI::CWebBrowserControl::ProcessInitializeMessage(): failed to create bitmap/texture"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0D08u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4D0D08u));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    cpu->eax = LIFT_CALLBACK(sfera_sub_004D0D18);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0D18(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x1B8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u)) {
        sfera_sub_004D0D7A(cpu, stop_address);
        return;
    }
    cpu->edx = 0x49u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0D3Au)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D0D3Au));
    lift_push32(cpu, 0x3Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0D41u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D0D41u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 4u;
    if (cpu->eax == 0u) goto label_000D0D72;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x1ACu), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = cpu->esi + 0x198u;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D0D60;
    cpu->edx = *(uint32_t*)(cpu->edx);
    label_000D0D60:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0D70u)); sfera_sub_0049D6A0(cpu, LIFT_CODE_TOKEN_VA(0x4D0D70u));
    goto label_000D0D74;
    label_000D0D72:
    cpu->eax = 0u;
    label_000D0D74:
    *(uint32_t*)(cpu->esi + 0x1B8u) = cpu->eax;
    sfera_sub_004D0D7A(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004D0D7A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 1u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->fs_data + (0u)) = cpu->ecx;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0D93(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, (uintptr_t)"SphereUI::CWebBrowserControl::ProcessInitializeMessage(): failed to create web browser object"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0DA2u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4D0DA2u));
    cpu->esp += 8u;
    cpu->eax = LIFT_CALLBACK(sfera_sub_004D0D7A);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0DB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 0x1B8u) == 0u) goto label_000D0DFD;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->edx == 0u) goto label_000D0DFD;
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + 1u;
    label_000D0DD0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000D0DD0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->edi + 0x198u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0DE8u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4D0DE8u));
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000D0DF0;
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_000D0DF0:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1B8u);
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0DFCu)); sfera_sub_0049D590(cpu, LIFT_CODE_TOKEN_VA(0x4D0DFCu));
    cpu->esi = lift_pop32(cpu);
    label_000D0DFD:
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x11Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x124u);
    cpu->eax = cpu->esp + 0xCu;
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0E43u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4D0E43u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"URL");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0E50u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D0E50u));
    if (cpu->eax == 0u) goto label_000D0E8A;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0E62u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4D0E62u));
    if (cpu->eax == 0u) goto label_000D0E8A;
    cpu->eax = cpu->esp + 0x14u;
    cpu->edx = cpu->eax + 1u;
    label_000D0E70:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000D0E70;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx + 0x198u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD0E8Au)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_RVA(0xD0E8Au));
    label_000D0E8A:
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0E96u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4D0E96u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x10Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D0EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->edx + 0xFFFFE4A7u;
    if (cpu->eax > 4u) goto label_000D0F30;
    switch (cpu->eax) {
        case 0u: goto label_000D0ED6;
        case 1u: goto label_000D0EE3;
        case 2u: goto label_000D0EEB;
        case 3u: goto label_000D0EF8;
        case 4u: goto label_000D0F0F;
        default: lift_trap(cpu, 0x4D0ECFu, "resolved jump-table index out of range"); return;
    }
label_000D0ED6: ;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0EE0u)); sfera_sub_004D0C30(cpu, LIFT_CODE_TOKEN_VA(0x4D0EE0u));
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D0EE3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0EE8u)); sfera_sub_004D07B0(cpu, LIFT_CODE_TOKEN_VA(0x4D0EE8u));
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D0EEB:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0EF5u)); sfera_sub_004D0DB0(cpu, LIFT_CODE_TOKEN_VA(0x4D0EF5u));
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D0EF8:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x1B8u);
    if (cpu->ecx == 0u) goto label_000D0F07;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD0F07u)); sfera_sub_0049D1F0(cpu, LIFT_CODE_TOKEN_RVA(0xD0F07u));
    label_000D0F07:
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D0F0F:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x1B8u);
    if (cpu->ecx == 0u) goto label_000D0F07;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0F28u)); sfera_sub_0049D200(cpu, LIFT_CODE_TOKEN_VA(0x4D0F28u));
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D0F30:
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    sfera_sub_004D2DD0(cpu, stop_address); return;
}
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D0FA0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D0FA0u));
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
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD0FD9u), LIFT_CODE_TOKEN_RVA(0xD0FD7u))) { return; }
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
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1010u), LIFT_CODE_TOKEN_RVA(0xD100Eu))) { return; }
    if (cpu->eax != 0u) goto label_000D1030;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != g_sfera_win32_dialog_registry.sentinel) goto label_000D1002;
    label_000D101E:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0xD1025u), LIFT_CODE_TOKEN_RVA(0xD1023u))) { return; }
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::DispatchMessageA), LIFT_CODE_TOKEN_RVA(0xD102Au));
    label_000D1030:
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD103Fu), LIFT_CODE_TOKEN_RVA(0xD103Du))) { return; }
    if (cpu->eax != 0u) goto label_000D0FF0;
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000D1046:
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D104B:
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_VA(0x4D104Du));
    lift_trap(cpu, 0x4D1053u, "INT3"); return;
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
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = 7u;
    lift_movs32(cpu, 1u);
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
__declspec(noinline) void sfera_sub_004D1220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x4D122Cu));
    cpu->esi = cpu->eax;
    cpu->eax = 0u;
    if (cpu->esi == cpu->eax) goto label_000D12A8;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x30u);
    { uint64_t l=cpu->ebx, r=0x111u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D125F;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edx = cpu->ecx & 0xFFFFu;
    cpu->ecx >>= 16u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    goto label_000D127F;
    label_000D125F:
    if (*(uint32_t*)(cpu->esi + 0x20u) == cpu->edi) goto label_000D126B;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetDlgCtrlID), LIFT_CODE_TOKEN_RVA(0xD1265u));
    label_000D126B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    label_000D127F:
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x3Cu), r=0x80u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D1298;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD1298u)); sfera_sub_004D1160(cpu, LIFT_CODE_TOKEN_RVA(0xD1298u));
    label_000D1298:
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D12A5u)); sfera_sub_004A01D0(cpu, LIFT_CODE_TOKEN_VA(0x4D12A5u));
    ++*(uint32_t*)(cpu->esi + 0x3Cu);
    label_000D12A8:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D12C0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D131Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D131Cu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x24u) = 0u;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x14u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D1338;
    cpu->edx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1335u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D1335u));
    cpu->esp += 4u;
    label_000D1338:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D134Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D134Fu));
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
    (void)0; /* source SEH registration eliminated */
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D13C6u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D13C6u));
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
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
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
    lift_trap(cpu, 0x4D142Au, "INT3"); return;
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
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004D1220));
    cpu->eax = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CreateDialogParamA), LIFT_CODE_TOKEN_VA(0x4D1458u));
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
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x8Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Win32Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D14D4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D14D4u));
    lift_push32(cpu, 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D14DBu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D14DBu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1537u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D1537u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x24u) = 0u;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000D1552;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D154Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D154Fu));
    cpu->esp += 4u;
    label_000D1552:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1569u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D1569u));
    cpu->esp += 4u;
    label_000D156C:
    cpu->eax = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
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
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4D1580u), "std::length_error");
    label_000D15B7:
    ++g_sfera_win32_dialog_registry.size;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D15E0(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->esi != 0u) goto label_000D15EA;
    cpu->eax = 0x7FFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D15EA:
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"BUTTON"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD15F9u), LIFT_CODE_TOKEN_RVA(0xD15F7u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1607;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1607:
    lift_push32(cpu, (uintptr_t)"TEXT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD160Fu), LIFT_CODE_TOKEN_RVA(0xD160Du))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D161D;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D161D:
    lift_push32(cpu, (uintptr_t)"IMAGE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1625u), LIFT_CODE_TOKEN_RVA(0xD1623u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1633;
    cpu->eax = 3u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1633:
    lift_push32(cpu, (uintptr_t)"PROGRESS_BAR"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD163Bu), LIFT_CODE_TOKEN_RVA(0xD1639u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1649;
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1649:
    lift_push32(cpu, (uintptr_t)"SCROLL_BAR"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1651u), LIFT_CODE_TOKEN_RVA(0xD164Fu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D165F;
    cpu->eax = 5u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D165F:
    lift_push32(cpu, (uintptr_t)"HYPER_TEXT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1667u), LIFT_CODE_TOKEN_RVA(0xD1665u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1675;
    cpu->eax = 6u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1675:
    lift_push32(cpu, (uintptr_t)"CHECKBOX"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD167Du), LIFT_CODE_TOKEN_RVA(0xD167Bu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D168B;
    cpu->eax = 7u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D168B:
    lift_push32(cpu, (uintptr_t)"RADIOBUTTON"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1693u), LIFT_CODE_TOKEN_RVA(0xD1691u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D16A1;
    cpu->eax = 8u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D16A1:
    lift_push32(cpu, (uintptr_t)"TEXTLIST"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD16A9u), LIFT_CODE_TOKEN_RVA(0xD16A7u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D16B7;
    cpu->eax = 0xAu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D16B7:
    lift_push32(cpu, (uintptr_t)"SLIDER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD16BFu), LIFT_CODE_TOKEN_RVA(0xD16BDu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D16CD;
    cpu->eax = 0xBu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D16CD:
    lift_push32(cpu, (uintptr_t)"LISTITEM"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD16D5u), LIFT_CODE_TOKEN_RVA(0xD16D3u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D16E3;
    cpu->eax = 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D16E3:
    lift_push32(cpu, (uintptr_t)"EDIT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD16EBu), LIFT_CODE_TOKEN_RVA(0xD16E9u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D16F9;
    cpu->eax = 0xDu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D16F9:
    lift_push32(cpu, (uintptr_t)"SLOT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1701u), LIFT_CODE_TOKEN_RVA(0xD16FFu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D170F;
    cpu->eax = 0xEu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D170F:
    lift_push32(cpu, (uintptr_t)"SPINBUTTON"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1717u), LIFT_CODE_TOKEN_RVA(0xD1715u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1725;
    cpu->eax = 0x10u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1725:
    lift_push32(cpu, (uintptr_t)"RICHEDIT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD172Du), LIFT_CODE_TOKEN_RVA(0xD172Bu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D173B;
    cpu->eax = 0x11u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D173B:
    lift_push32(cpu, (uintptr_t)"FILTERLISTCTRL"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1743u), LIFT_CODE_TOKEN_RVA(0xD1741u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1751;
    cpu->eax = 0x12u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1751:
    lift_push32(cpu, (uintptr_t)"WEBBROWSER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1759u), LIFT_CODE_TOKEN_RVA(0xD1757u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1767;
    cpu->eax = 0x13u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1767:
    lift_push32(cpu, (uintptr_t)"MINIMAP"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD176Fu), LIFT_CODE_TOKEN_RVA(0xD176Du))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D177D;
    cpu->eax = 0x14u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D177D:
    lift_push32(cpu, (uintptr_t)"MENULISTCTRL"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1785u), LIFT_CODE_TOKEN_RVA(0xD1783u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1793;
    cpu->eax = 0x15u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1793:
    lift_push32(cpu, (uintptr_t)"HTCHATLISTCTRL"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD179Bu), LIFT_CODE_TOKEN_RVA(0xD1799u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D17A9;
    cpu->eax = 0x16u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D17A9:
    lift_push32(cpu, (uintptr_t)"HTEDIT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD17B1u), LIFT_CODE_TOKEN_RVA(0xD17AFu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D17BF;
    cpu->eax = 0x17u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D17BF:
    lift_push32(cpu, (uintptr_t)"FONTPICKER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD17C7u), LIFT_CODE_TOKEN_RVA(0xD17C5u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D17D5;
    cpu->eax = 0x18u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D17D5:
    lift_push32(cpu, (uintptr_t)"COLORPICKER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD17DDu), LIFT_CODE_TOKEN_RVA(0xD17DBu))) { return; }
    cpu->esp += 8u;
    { uint64_t x=cpu->eax, v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0x7FFFFFE6u;
    cpu->eax += 0x19u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D17F0(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->esi != 0u) goto label_000D17F7;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D17F7:
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"ALPHA_IN"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1806u), LIFT_CODE_TOKEN_RVA(0xD1804u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1814;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1814:
    lift_push32(cpu, (uintptr_t)"ALPHA_OUT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD181Cu), LIFT_CODE_TOKEN_RVA(0xD181Au))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D182A;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D182A:
    lift_push32(cpu, (uintptr_t)"MOVE_LEFT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1832u), LIFT_CODE_TOKEN_RVA(0xD1830u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1840;
    cpu->eax = 3u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1840:
    lift_push32(cpu, (uintptr_t)"MOVE_RIGHT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1848u), LIFT_CODE_TOKEN_RVA(0xD1846u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1856;
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1856:
    lift_push32(cpu, (uintptr_t)"MOVE_TOP"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD185Eu), LIFT_CODE_TOKEN_RVA(0xD185Cu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D186C;
    cpu->eax = 5u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D186C:
    lift_push32(cpu, (uintptr_t)"MOVE_BOTTOM"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1874u), LIFT_CODE_TOKEN_RVA(0xD1872u))) { return; }
    cpu->esp += 8u;
    { uint64_t x=cpu->eax, v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFFFAu;
    cpu->eax += 6u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1890(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->esi != 0u) goto label_000D1897;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1897:
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"LEFT_X"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD18A6u), LIFT_CODE_TOKEN_RVA(0xD18A4u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D18B4;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D18B4:
    lift_push32(cpu, (uintptr_t)"CENTER_X"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD18BCu), LIFT_CODE_TOKEN_RVA(0xD18BAu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D18CA;
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D18CA:
    lift_push32(cpu, (uintptr_t)"RIGHT_X"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD18D2u), LIFT_CODE_TOKEN_RVA(0xD18D0u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D18E0;
    cpu->eax = 8u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D18E0:
    lift_push32(cpu, (uintptr_t)"LEFT_Y"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD18E8u), LIFT_CODE_TOKEN_RVA(0xD18E6u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D18F6;
    cpu->eax = 0x10u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D18F6:
    lift_push32(cpu, (uintptr_t)"CENTER_Y"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD18FEu), LIFT_CODE_TOKEN_RVA(0xD18FCu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D190C;
    cpu->eax = 0x20u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D190C:
    lift_push32(cpu, (uintptr_t)"RIGHT_Y"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1914u), LIFT_CODE_TOKEN_RVA(0xD1912u))) { return; }
    cpu->esp += 8u;
    { uint64_t x=cpu->eax, v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFFC0u;
    cpu->eax += 0x40u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1930(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->esi != 0u) goto label_000D1937;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1937:
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"RIGHT_X"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1946u), LIFT_CODE_TOKEN_RVA(0xD1944u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1954;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1954:
    lift_push32(cpu, (uintptr_t)"RIGHT_Y"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD195Cu), LIFT_CODE_TOKEN_RVA(0xD195Au))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D196A;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D196A:
    lift_push32(cpu, (uintptr_t)"CENTER_X"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1972u), LIFT_CODE_TOKEN_RVA(0xD1970u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1980;
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1980:
    lift_push32(cpu, (uintptr_t)"CENTER_Y"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD1988u), LIFT_CODE_TOKEN_RVA(0xD1986u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D1996;
    cpu->eax = 8u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D1996:
    lift_push32(cpu, (uintptr_t)"CENTER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD199Eu), LIFT_CODE_TOKEN_RVA(0xD199Cu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D19AC;
    cpu->eax = 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D19AC:
    lift_push32(cpu, (uintptr_t)"RIGHT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD19B4u), LIFT_CODE_TOKEN_RVA(0xD19B2u))) { return; }
    cpu->esp += 8u;
    { uint64_t x=cpu->eax, v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFFFDu;
    cpu->eax += 3u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D19D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->ecx + 0x9Cu) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D19E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->edx;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x50u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x38u);
    if ((((cpu->eax & 0xFFu)) & (8u)) == 0u) goto label_000D1A23;
    cpu->edx = g_sfera_graphics_runtime.display_width;
    cpu->edx -= *(uint32_t*)(cpu->ecx + 0x28u);
    *(uint32_t*)(cpu->ecx + 0x30u) = (uint64_t)(*(uint32_t*)(cpu->ecx + 0x30u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    label_000D1A23:
    if ((((cpu->eax & 0xFFu)) & (0x40u)) == 0u) goto label_000D1A33;
    cpu->edx = g_sfera_graphics_runtime.display_height;
    cpu->edx -= *(uint32_t*)(cpu->ecx + 0x2Cu);
    *(uint32_t*)(cpu->ecx + 0x34u) = (uint64_t)(*(uint32_t*)(cpu->ecx + 0x34u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    label_000D1A33:
    if ((((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_000D1A45;
    cpu->edx = g_sfera_graphics_runtime.display_width;
    { uint64_t l=cpu->edx, r=*(uint32_t*)(cpu->ecx + 0x28u), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx >>= 1u;
    *(uint32_t*)(cpu->ecx + 0x30u) = (uint64_t)(*(uint32_t*)(cpu->ecx + 0x30u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    label_000D1A45:
    if ((((cpu->eax & 0xFFu)) & (0x20u)) == 0u) goto label_000D1A56;
    cpu->eax = g_sfera_graphics_runtime.display_height;
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->ecx + 0x2Cu), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax >>= 1u;
    *(uint32_t*)(cpu->ecx + 0x34u) = (uint64_t)(*(uint32_t*)(cpu->ecx + 0x34u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_000D1A56:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x38u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x40u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x44u);
    *(uint32_t*)(cpu->ecx + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->esi;
    if ((((cpu->edx & 0xFFu)) & (8u)) == 0u) goto label_000D1A81;
    cpu->eax -= *(uint32_t*)(cpu->ecx + 0x28u);
    cpu->eax += g_sfera_graphics_runtime.display_width;
    *(uint32_t*)(cpu->ecx + 0x30u) = cpu->eax;
    label_000D1A81:
    if ((((cpu->edx & 0xFFu)) & (0x40u)) == 0u) goto label_000D1A92;
    cpu->esi -= *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->esi += g_sfera_graphics_runtime.display_height;
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->esi;
    label_000D1A92:
    cpu->esi = lift_pop32(cpu);
    if ((((cpu->edx & 0xFFu)) & (4u)) == 0u) goto label_000D1AA5;
    cpu->eax = g_sfera_graphics_runtime.display_width;
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->ecx + 0x28u), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax >>= 1u;
    *(uint32_t*)(cpu->ecx + 0x30u) = (uint64_t)(*(uint32_t*)(cpu->ecx + 0x30u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_000D1AA5:
    if ((((cpu->edx & 0xFFu)) & (0x20u)) == 0u) goto label_000D1AB8;
    cpu->edx = g_sfera_graphics_runtime.display_height;
    { uint64_t l=cpu->edx, r=*(uint32_t*)(cpu->ecx + 0x2Cu), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx >>= 1u;
    *(uint32_t*)(cpu->ecx + 0x34u) = (uint64_t)(*(uint32_t*)(cpu->ecx + 0x34u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    label_000D1AB8:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1AC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x5C6u); lift_push32(cpu, (uintptr_t)"SphereUI::Window::setFont"); lift_push32(cpu, (uintptr_t)"%s():%d font = %d");
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1ADDu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D1ADDu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1AE3u)); sfera_sub_0042E480(cpu, LIFT_CODE_TOKEN_VA(0x4D1AE3u));
    cpu->esp += 0x14u;
    *(uint8_t*)(cpu->esi + 0x8Cu) = cpu->ebx & 0xFFu;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1B00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x5CCu); lift_push32(cpu, (uintptr_t)"SphereUI::Window::getFont"); lift_push32(cpu, (uintptr_t)"%s():%d font = %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1B1Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D1B1Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1B25u)); sfera_sub_0042E480(cpu, LIFT_CODE_TOKEN_VA(0x4D1B25u));
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Cu);
    cpu->esp += 0x14u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1B40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint8_t*)(cpu->eax);
    --cpu->ecx;
    if (cpu->ecx > 5u) goto label_000D1C06;
    lift_push32(cpu, cpu->edi);
    switch (cpu->ecx) {
        case 0u: goto label_000D1B5C;
        case 1u: goto label_000D1B72;
        case 2u: goto label_000D1B94;
        case 3u: goto label_000D1BB8;
        case 4u: goto label_000D1BDA;
        case 5u: goto label_000D1BE8;
        default: lift_trap(cpu, 0x4D1B55u, "resolved jump-table index out of range"); return;
    }
label_000D1B5C: ;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D1B72:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D1B94:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x1Cu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x10u)));
    lift_push32(cpu, cpu->ecx);
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1BABu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4D1BABu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D1BB8:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x10u)));
    lift_push32(cpu, cpu->ecx);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0x1Cu)));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1BCDu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4D1BCDu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D1BDA:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x1Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x10u)));
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000D1BF2;
    label_000D1BE8:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x10u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0x1Cu)));
    label_000D1BF2:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1BF9u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4D1BF9u));
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    cpu->edi = lift_pop32(cpu);
    label_000D1C06:
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
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
__declspec(noinline) void sfera_sub_004D1C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x170u) == 0u) goto label_000D1CF8;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x170u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1C6Fu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4D1C6Fu));
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->edi + 8u), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(*(uint32_t*)(cpu->edi + 0xCu)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    lift_x87_push(cpu, (double)(((int64_t)(*(uint64_t*)(cpu->esp + 8u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (10000.0);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->edi + 0x10u)));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000D1CB2;
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000D1CBE;
    label_000D1CB2:
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    goto label_000D1CC0;
    label_000D1CBE:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000D1CC0:
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1CCCu)); sfera_sub_004D1B40(cpu, LIFT_CODE_TOKEN_VA(0x4D1CCCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_push(cpu, 1.0);
    cpu->edi = lift_pop32(cpu);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000D1CF8;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x170u);
    if (*(uint32_t*)(cpu->eax + 0x20u) != 3u) goto label_000D1CEF;
    *(uint8_t*)(cpu->esi + 0xE1u) = 1u;
    label_000D1CEF:
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD1CF8u)); sfera_sub_004D1D00(cpu, LIFT_CODE_TOKEN_RVA(0xD1CF8u));
    label_000D1CF8:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1D00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = 0u;
    if (*(uint8_t*)(cpu->edi + 0xE0u) != 1u) goto label_000D1D22;
    lift_x87_push(cpu, 1.0);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x170u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD1D22u)); sfera_sub_004D1B40(cpu, LIFT_CODE_TOKEN_RVA(0xD1D22u));
    label_000D1D22:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ebp > 3u) goto label_000D1D62;
    switch (cpu->ebp) {
        case 0u: goto label_000D1D32;
        case 1u: goto label_000D1D45;
        case 2u: case 3u: goto label_000D1D5C;
        case 4u: goto label_000D1D9D;
        case 5u: goto label_000D1DA2;
        case 6u: goto label_000D1DA7;
        case 7u: goto label_000D1DAC;
        default: lift_trap(cpu, 0x4D1D2Bu, "resolved jump-table index out of range"); return;
    }
label_000D1D32: ;
    *(uint32_t*)(cpu->edi + 0x170u) = cpu->esi;
    *(uint8_t*)(cpu->edi + 0xE0u) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D1D45:
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    cpu->esi = cpu->edi + 0x120u;
    goto label_000D1D62;
    label_000D1D5C:
    cpu->esi = cpu->edi + 0x148u;
    label_000D1D62:
    if (*(uint8_t*)(cpu->esi) != 0u) goto label_000D1D7E;
    *(uint8_t*)(cpu->edi + 0xE0u) = 0u;
    *(uint32_t*)(cpu->edi + 0x170u) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D1D7E:
    *(uint8_t*)(cpu->edi + 0xE0u) = 1u;
    *(uint32_t*)(cpu->edi + 0x170u) = cpu->esi;
    cpu->eax = *(uint8_t*)(cpu->esi);
    cpu->eax += 0xFFFFFFFDu;
    if (cpu->eax > 3u) goto label_000D1DB8;
    switch (cpu->eax) {
        case 0u: goto label_000D1D9D;
        case 1u: goto label_000D1DA2;
        case 2u: goto label_000D1DA7;
        case 3u: goto label_000D1DAC;
        default: lift_trap(cpu, 0x4D1D96u, "resolved jump-table index out of range"); return;
    }
    label_000D1D9D:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x30u)))));
    goto label_000D1DB2;
    label_000D1DA2:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x30u)))));
    goto label_000D1DAF;
    label_000D1DA7:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x34u)))));
    goto label_000D1DB2;
    label_000D1DAC:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x34u)))));
    label_000D1DAF:
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0x14u)));
    label_000D1DB2:
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x18u)));
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000D1DB8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1DBDu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4D1DBDu));
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ebp;
    if (g_sfera_interface_runtime.sounds_enabled == 0u) goto label_000D1DE7;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    cpu->ecx = (uintptr_t)"Sounds\\in_winopen.wav";
    if (cpu->ebp == 1u) goto label_000D1DE0;
    cpu->ecx = (uintptr_t)"Sounds\\in_winclose.wav";
    label_000D1DE0:
    cpu->edx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD1DE7u)); sfera_sub_00498060(cpu, LIFT_CODE_TOKEN_RVA(0xD1DE7u));
    label_000D1DE7:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1DEEu)); sfera_sub_004D1C50(cpu, LIFT_CODE_TOKEN_VA(0x4D1DEEu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1E20(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=*(uint8_t*)(cpu->esp + 4u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D1E3F;
    *(uint8_t*)(cpu->edi + 0x48u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->edi + 0xE1u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->edi + 0x4Au) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D1E3F:
    if (*(uint8_t*)(cpu->edi + 0xE0u) != (cpu->ebx & 0xFFu)) goto label_000D1E59;
    lift_x87_push(cpu, 1.0);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x170u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD1E59u)); sfera_sub_004D1B40(cpu, LIFT_CODE_TOKEN_RVA(0xD1E59u));
    label_000D1E59:
    { uint64_t l=*(uint8_t*)(cpu->edi + 0x148u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edi + 0x148u;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D1E7C;
    *(uint8_t*)(cpu->edi + 0xE0u) = 0u;
    *(uint32_t*)(cpu->edi + 0x170u) = 0u;
    goto label_000D1EE5;
    label_000D1E7C:
    *(uint8_t*)(cpu->edi + 0xE0u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->edi + 0x170u) = cpu->esi;
    cpu->eax = *(uint8_t*)(cpu->esi);
    cpu->eax += 0xFFFFFFFDu;
    if (cpu->eax > 3u) goto label_000D1EB5;
    switch (cpu->eax) {
        case 0u: goto label_000D1E9A;
        case 1u: goto label_000D1E9F;
        case 2u: goto label_000D1EA4;
        case 3u: goto label_000D1EA9;
        default: lift_trap(cpu, 0x4D1E93u, "resolved jump-table index out of range"); return;
    }
label_000D1E9A: ;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x30u)))));
    goto label_000D1EAF;
    label_000D1E9F:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x30u)))));
    goto label_000D1EAC;
    label_000D1EA4:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x34u)))));
    goto label_000D1EAF;
    label_000D1EA9:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi + 0x34u)))));
    label_000D1EAC:
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0x14u)));
    label_000D1EAF:
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x18u)));
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000D1EB5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1EBAu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4D1EBAu));
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x20u) = 3u;
    if (g_sfera_interface_runtime.sounds_enabled == 0u) goto label_000D1EDE;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"Sounds\\in_winclose.wav";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD1EDEu)); sfera_sub_00498060(cpu, LIFT_CODE_TOKEN_RVA(0xD1EDEu));
    label_000D1EDE:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD1EE5u)); sfera_sub_004D1C50(cpu, LIFT_CODE_TOKEN_RVA(0xD1EE5u));
    label_000D1EE5:
    { uint64_t l=*(uint8_t*)(cpu->edi + 0xE0u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D1EF5;
    *(uint8_t*)(cpu->edi + 0xE1u) = cpu->ebx & 0xFFu;
    label_000D1EF5:
    *(uint8_t*)(cpu->edi + 0x4Au) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D1F10(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=*(uint8_t*)(cpu->esp + 4u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D1FFA;
    cpu->ebx = 1u;
    if (*(uint8_t*)(cpu->esi + 0xE0u) != (cpu->ebx & 0xFFu)) goto label_000D1F3F;
    lift_x87_push(cpu, 1.0);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x170u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD1F3Fu)); sfera_sub_004D1B40(cpu, LIFT_CODE_TOKEN_RVA(0xD1F3Fu));
    label_000D1F3F:
    { uint64_t l=*(uint8_t*)(cpu->esi + 0x148u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = cpu->esi + 0x148u;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D1F61;
    *(uint8_t*)(cpu->esi + 0xE0u) = 0u;
    *(uint32_t*)(cpu->esi + 0x170u) = 0u;
    goto label_000D1FCA;
    label_000D1F61:
    *(uint8_t*)(cpu->esi + 0xE0u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x170u) = cpu->edi;
    cpu->eax = *(uint8_t*)(cpu->edi);
    cpu->eax += 0xFFFFFFFDu;
    if (cpu->eax > 3u) goto label_000D1F9A;
    switch (cpu->eax) {
        case 0u: goto label_000D1F7F;
        case 1u: goto label_000D1F84;
        case 2u: goto label_000D1F89;
        case 3u: goto label_000D1F8E;
        case 4u: goto label_000D2082;
        case 5u: goto label_000D2087;
        case 6u: goto label_000D208C;
        case 7u: goto label_000D2091;
        default: lift_trap(cpu, 0x4D1F78u, "resolved jump-table index out of range"); return;
    }
label_000D1F7F: ;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x30u)))));
    goto label_000D1F94;
    label_000D1F84:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x30u)))));
    goto label_000D1F91;
    label_000D1F89:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x34u)))));
    goto label_000D1F94;
    label_000D1F8E:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x34u)))));
    label_000D1F91:
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edi + 0x14u)));
    label_000D1F94:
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x18u)));
    *(float*)(cpu->edi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000D1F9A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D1F9Fu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4D1F9Fu));
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->edi + 0x20u) = 2u;
    if (g_sfera_interface_runtime.sounds_enabled == 0u) goto label_000D1FC3;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"Sounds\\in_winclose.wav";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD1FC3u)); sfera_sub_00498060(cpu, LIFT_CODE_TOKEN_RVA(0xD1FC3u));
    label_000D1FC3:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD1FCAu)); sfera_sub_004D1C50(cpu, LIFT_CODE_TOKEN_RVA(0xD1FCAu));
    label_000D1FCA:
    if (*(uint8_t*)(cpu->esi + 0xE0u) != 0u) goto label_000D1FEE;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x6Cu);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 0x11Cu) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D1FEE:
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 0x11Cu) = cpu->ebx & 0xFFu;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D1FFA:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x6Cu);
    *(uint8_t*)(cpu->esi + 0x11Cu) = 0u;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ebx = 1u;
    if (*(uint8_t*)(cpu->esi + 0xE0u) != (cpu->ebx & 0xFFu)) goto label_000D202F;
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x170u);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD202Fu)); sfera_sub_004D1B40(cpu, LIFT_CODE_TOKEN_RVA(0xD202Fu));
    label_000D202F:
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    { uint64_t l=*(uint8_t*)(cpu->esi + 0x120u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = cpu->esi + 0x120u;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D2064;
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 0xE0u) = 0u;
    *(uint32_t*)(cpu->esi + 0x170u) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D2064:
    *(uint8_t*)(cpu->esi + 0xE0u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x170u) = cpu->edi;
    cpu->eax = *(uint8_t*)(cpu->edi);
    cpu->eax += 0xFFFFFFFDu;
    if (cpu->eax > 3u) goto label_000D209D;
    switch (cpu->eax) {
        case 0u: goto label_000D2082;
        case 1u: goto label_000D2087;
        case 2u: goto label_000D208C;
        case 3u: goto label_000D2091;
        default: lift_trap(cpu, 0x4D207Bu, "resolved jump-table index out of range"); return;
    }
    label_000D2082:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x30u)))));
    goto label_000D2097;
    label_000D2087:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x30u)))));
    goto label_000D2094;
    label_000D208C:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x34u)))));
    goto label_000D2097;
    label_000D2091:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x34u)))));
    label_000D2094:
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edi + 0x14u)));
    label_000D2097:
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x18u)));
    *(float*)(cpu->edi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000D209D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D20A2u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4D20A2u));
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->edi + 0x20u) = cpu->ebx;
    if (g_sfera_interface_runtime.sounds_enabled == 0u) goto label_000D20C2;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"Sounds\\in_winopen.wav";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD20C2u)); sfera_sub_00498060(cpu, LIFT_CODE_TOKEN_RVA(0xD20C2u));
    label_000D20C2:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D20C9u)); sfera_sub_004D1C50(cpu, LIFT_CODE_TOKEN_VA(0x4D20C9u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D20F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    { uint64_t l=*(uint8_t*)(cpu->eax + 0x11u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D2134;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp);
    label_000D2110:
    cpu->esi = *(uint32_t*)(cpu->eax + 0xCu);
    if (cpu->esi >= cpu->edi) goto label_000D211C;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_000D212C;
    label_000D211C:
    if (*(uint8_t*)(cpu->edx + 0x11u) == 0u) goto label_000D2128;
    if (cpu->edi >= cpu->esi) goto label_000D2128;
    cpu->edx = cpu->eax;
    label_000D2128:
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000D212C:
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_000D2110;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000D2134:
    if (*(uint8_t*)(cpu->edx + 0x11u) == 0u) goto label_000D2142;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_000D2144;
    label_000D2142:
    cpu->eax = *(uint32_t*)(cpu->edx);
    label_000D2144:
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_000D2164;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    label_000D2150:
    if (cpu->ecx >= *(uint32_t*)(cpu->eax + 0xCu)) goto label_000D215B;
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    goto label_000D215E;
    label_000D215B:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    label_000D215E:
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_000D2150;
    label_000D2164:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D2180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->eax < 0x3FFFFFFEu) goto label_000D21A2;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2194u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D2194u));
    cpu->esp += 4u;
    lift_push32(cpu, (uintptr_t)"map/set<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4D2180u), "std::length_error");
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D23BDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D23BDu));
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
    lift_trap(cpu, 0x4D241Bu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004D2420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0xCu);
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2434u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D2434u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000D244B;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D244B:
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 8u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2479u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4D2479u));
    lift_trap(cpu, 0x4D2479u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004D2480(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    { uint64_t l=*(uint8_t*)(cpu->eax + 0x11u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D24CD;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xCu);
    label_000D24A1:
    { uint64_t l=*(uint8_t*)(cpu->esp + 0x1Cu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D24B2;
    { uint64_t l=*(uint32_t*)(cpu->eax + 0xCu), r=cpu->edx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000D24B8;
    label_000D24B2:
    { uint64_t l=cpu->edx, r=*(uint32_t*)(cpu->eax + 0xCu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_000D24B8:
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_000D24C4;
    cpu->eax = *(uint32_t*)(cpu->eax);
    goto label_000D24C7;
    label_000D24C4:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    label_000D24C7:
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_000D24A1;
    label_000D24CD:
    cpu->edi = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_000D250A;
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = cpu->esp + 0x1Cu;
    if (cpu->esi != *(uint32_t*)(cpu->eax)) goto label_000D2501;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D24EEu)); sfera_sub_004D2180(cpu, LIFT_CODE_TOKEN_VA(0x4D24EEu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D2501:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2506u)); sfera_sub_00402140(cpu, LIFT_CODE_TOKEN_VA(0x4D2506u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000D250A:
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    if (cpu->eax >= *(uint32_t*)(cpu->ebx + 0xCu)) goto label_000D2538;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2525u)); sfera_sub_004D2180(cpu, LIFT_CODE_TOKEN_VA(0x4D2525u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D2538:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D253Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D253Du));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp += 4u;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D2560(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xF4u);
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    if (cpu->ecx == 0u) goto label_000D2581;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D257Du)); sfera_sub_004D2560(cpu, LIFT_CODE_TOKEN_VA(0x4D257Du));
    if (cpu->eax != 0u) goto label_000D25C5;
    label_000D2581:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x174u);
    if (cpu->eax != 0u) goto label_000D2591;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D2591:
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if (cpu->esi == cpu->eax) goto label_000D25C1;
    cpu->ebp = native_function_address32(&::_stricmp);
    label_000D25A1:
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0xD25AAu), LIFT_CODE_TOKEN_RVA(0xD25A8u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000D25CB;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x174u);
    if (cpu->esi != *(uint32_t*)(cpu->ecx)) goto label_000D25A1;
    label_000D25C1:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    label_000D25C5:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D25CB:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D25E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000D2809;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x9Cu) == cpu->eax) goto label_000D2608;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x34u);
    label_000D2608:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edx += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->ecx += cpu->eax;
    { uint64_t l=*(uint8_t*)(cpu->esi + 0x24u), r=2u, v=l & r; lift_flags_logic(cpu,v,8u); }
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D2671;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x194u);
    { uint64_t v=cpu->ecx; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D2671;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    cpu->eax <<= 24u;
    cpu->eax |= 0xFFFFFFu;
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x194u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD2671u)); sfera_sub_004CE140(cpu, LIFT_CODE_TOKEN_RVA(0xD2671u));
    label_000D2671:
    { uint64_t l=*(uint8_t*)(cpu->esi + 0x24u), r=4u, v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D27E8;
    if (*(uint32_t*)(cpu->esi + 0x64u) <= 0u) goto label_000D27E8;
    cpu->edx = *(uint8_t*)(cpu->esi + 0x8Cu);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x104u);
    cpu->edi -= *(uint32_t*)(cpu->esi + 0xFCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x108u);
    cpu->ebp -= *(uint32_t*)(cpu->esi + 0x100u);
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x68u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->esi + 0x54u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D26B8;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    goto label_000D26BA;
    label_000D26B8:
    cpu->ecx = cpu->ebx;
    label_000D26BA:
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Du);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D26D1u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4D26D1u));
    if (*(uint32_t*)(cpu->esp + 0x18u) <= cpu->edi) goto label_000D2731;
    { uint64_t l=*(uint32_t*)(cpu->ebx + 0x14u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = 2u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D26EA;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    goto label_000D26EC;
    label_000D26EA:
    cpu->ecx = cpu->ebx;
    label_000D26EC:
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x8Du);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2703u)); sfera_sub_0045AE50(cpu, LIFT_CODE_TOKEN_VA(0x4D2703u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0xE8u)))));
    { uint64_t l=cpu->ecx, r=*(uint32_t*)(cpu->esp + 0x24u), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x10u)));
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, 1u, 32u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x100u)))));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000D272D;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000D272D:
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000D2741;
    label_000D2731:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0xE8u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x10u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x100u)))));
    label_000D2741:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2746u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4D2746u));
    g_sfera_screen_clip_runtime.top = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0xE4u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0xFCu)))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2760u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4D2760u));
    cpu->ecx = g_sfera_screen_clip_runtime.top;
    cpu->edx = cpu->eax + cpu->edi + 0xAu;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    g_sfera_screen_clip_runtime.right = cpu->edx;
    cpu->edx = cpu->ecx + cpu->ebp + 0xAu;
    cpu->ebp = 0xFFu;
    g_sfera_screen_clip_runtime.left = cpu->eax;
    g_sfera_screen_clip_runtime.bottom = cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0xDCu) != cpu->ebp) goto label_000D27A1;
    if ((int32_t)cpu->edi >= (int32_t)2u) goto label_000D27A1;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D279Cu)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_VA(0x4D279Cu));
    cpu->eax = g_sfera_screen_clip_runtime.left;
    label_000D27A1:
    if (*(uint32_t*)(cpu->ebx + 0x14u) < 0x10u) goto label_000D27A9;
    cpu->ebx = *(uint32_t*)(cpu->ebx);
    label_000D27A9:
    lift_x87_push(cpu, 0.0);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x90u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x8Du);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_screen_clip_runtime.top;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D27CFu)); sfera_sub_0044CD30(cpu, LIFT_CODE_TOKEN_VA(0x4D27CFu));
    { uint64_t l=*(uint32_t*)(cpu->esi + 0xDCu), r=cpu->ebp, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D27E8;
    if ((int32_t)cpu->edi >= (int32_t)2u) goto label_000D27E8;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD27E8u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0xD27E8u));
    label_000D27E8:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (cpu->edi == cpu->eax) goto label_000D2808;
    label_000D27F4:
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    cpu->edi = *(uint32_t*)(cpu->edi);
    if (cpu->edi != *(uint32_t*)(cpu->esi + 0xA0u)) goto label_000D27F4;
    label_000D2808:
    cpu->edi = lift_pop32(cpu);
    label_000D2809:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D2810(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000D284B;
    label_000D2820:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint32_t*)(cpu->eax + 0xECu) == 0u) goto label_000D2841;
    if (*(uint8_t*)(cpu->eax + 0x48u) != 0u) goto label_000D2841;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xECu);
    cpu->ecx = cpu->eax;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000D2841:
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(cpu->edi + 0xA0u)) goto label_000D2820;
    label_000D284B:
    cpu->eax = *(uint32_t*)(cpu->edi + 0xF0u);
    if (cpu->eax == 0u) goto label_000D2866;
    if (*(uint8_t*)(cpu->eax + 0x48u) != 0u) goto label_000D2866;
    cpu->ecx = cpu->eax;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D2866:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D2870(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    if (cpu->ecx == 0u) goto label_000D2883;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD2883u)); sfera_sub_004CF750(cpu, LIFT_CODE_TOKEN_RVA(0xD2883u));
    label_000D2883:
    cpu->eax = *(uint32_t*)(cpu->edi + 0xA0u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000D28A2;
    (void)cpu;
    label_000D2890:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2898u)); sfera_sub_004D2870(cpu, LIFT_CODE_TOKEN_VA(0x4D2898u));
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(cpu->edi + 0xA0u)) goto label_000D2890;
    label_000D28A2:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D28B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0x4Au) == 0u) goto label_000D2A32;
    if (*(uint8_t*)(cpu->esi + 0x11Cu) == 0u) goto label_000D28ED;
    if (*(uint8_t*)(cpu->esi + 0xE0u) != 0u) goto label_000D28ED;
    lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, 0x6Cu);
    *(uint8_t*)(cpu->esi + 0x11Cu) = 0u;
    reinterpret_cast<SphereUI::Window*>(cpu->esi)->handleMessage(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D28ED:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    { uint64_t l=*(uint8_t*)(cpu->ebx + 0xCu), r=1u, v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D2998;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0xFCu);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x104u);
    if (cpu->ebp == cpu->edi) goto label_000D2998;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000D2935;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD2935u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xD2935u));
    label_000D2935:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x100u);
    cpu->ebx = *(uint32_t*)(cpu->ebx);
    cpu->edi += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x108u);
    cpu->ebp += cpu->eax;
    cpu->edx += cpu->ecx;
    cpu->edi += cpu->ecx;
    if ((int32_t)cpu->ebx <= (int32_t)cpu->ebp) goto label_000D2994;
    if ((int32_t)cpu->ebx > (int32_t)*(uint32_t*)(cpu->esp + 0x20u)) goto label_000D2994;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ebp = *(uint32_t*)(cpu->ebp + 4u);
    if ((int32_t)cpu->ebp <= (int32_t)cpu->edx) goto label_000D2994;
    if ((int32_t)cpu->ebp > (int32_t)cpu->edi) goto label_000D2994;
    cpu->eax -= cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esi + 0x110u) = cpu->eax;
    cpu->ecx -= *(uint32_t*)(cpu->ebx + 4u);
    *(uint8_t*)(cpu->esi + 0x10Cu) = 1u;
    *(uint32_t*)(cpu->esi + 0x114u) = cpu->ecx;
    goto label_000D2998;
    label_000D2994:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_000D2998:
    if (*(uint8_t*)(cpu->esi + 0x10Cu) == 0u) goto label_000D29D2;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x110u);
    cpu->eax += *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x114u);
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->eax;
    cpu->ecx += *(uint32_t*)(cpu->ebx + 4u);
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ecx;
    if (((*(uint8_t*)(cpu->ebx + 0xCu)) & (4u)) == 0u) goto label_000D29D2;
    { uint64_t l=*(uint8_t*)(cpu->esi + 0x4Eu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    *(uint8_t*)(cpu->esi + 0x10Cu) = 0u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D29D2;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD29D2u)); sfera_sub_004BC5F0(cpu, LIFT_CODE_TOKEN_RVA(0xD29D2u));
    label_000D29D2:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->ebp = *(uint32_t*)(cpu->eax);
    if (cpu->ebp == cpu->eax) goto label_000D2A15;
    label_000D29E0:
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint8_t*)(cpu->edi + 0x49u) != 0u) goto label_000D2A0A;
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_000D2A00;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xECu);
    lift_push32(cpu, cpu->ebx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000D2A00:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000D2A0A:
    cpu->ebp = *(uint32_t*)(cpu->ebp);
    if (cpu->ebp != *(uint32_t*)(cpu->esi + 0xA0u)) goto label_000D29E0;
    label_000D2A15:
    cpu->esi = *(uint32_t*)(cpu->esi + 0xF0u);
    if (cpu->esi == 0u) goto label_000D2A2F;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000D2A2F;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000D2A2F:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D2A32:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D2A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->esi);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (255.0);
    cpu->esi = cpu->ecx;
    *(uint16_t*)(cpu->esp + 6u) = cpu->fpu_control;
    lift_push32(cpu, cpu->edi);
    cpu->eax = *(uint16_t*)(cpu->esp + 0xAu);
    { uint64_t l=cpu->eax, r=0xC00u, v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0xCu);
    *(uint64_t*)(cpu->esp + 0xCu) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x98u);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0xAu);
    *(uint32_t*)(cpu->esi + 0xDCu) = cpu->eax;
    cpu->eax <<= 24u;
    cpu->ecx &= 0xFFFFFFu;
    cpu->edx &= 0xFFFFFFu;
    cpu->ecx |= cpu->eax;
    cpu->edx |= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x98u) = cpu->edx;
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (cpu->edi == cpu->eax) goto label_000D2ACC;
    label_000D2AB0:
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    cpu->edi = *(uint32_t*)(cpu->edi);
    if (cpu->edi != *(uint32_t*)(cpu->esi + 0xA0u)) goto label_000D2AB0;
    label_000D2ACC:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D2AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xA0u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp) = cpu->ecx;
    if (cpu->ecx == cpu->eax) goto label_000D2B6E;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000D2B06:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint32_t*)(cpu->esi + 0x3Cu) == cpu->edi) goto label_000D2B17;
    if (cpu->edi != 0xFFFFFFFFu) goto label_000D2B54;
    label_000D2B17:
    if (cpu->ebx == *(uint32_t*)(cpu->esi + 0x50u)) goto label_000D2B24;
    if (cpu->ebx != 0x7FFFFFFFu) goto label_000D2B38;
    label_000D2B24:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000D2B38:
    if (*(uint32_t*)(cpu->esi + 0x50u) != 0xCu) goto label_000D2B54;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->dispatchMessage(cpu);
    label_000D2B54:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->eax != *(uint32_t*)(cpu->edx + 0xA0u)) goto label_000D2B06;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D2B6E:
    cpu->esp += 8u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D2B80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x48u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    *(uint32_t*)(cpu->esp) = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D2B90;
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D2B90:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xA0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (cpu->ebx == cpu->eax) goto label_000D2C21;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    label_000D2BB0:
    cpu->esi = *(uint32_t*)(cpu->ebx + 8u);
    if (*(uint8_t*)(cpu->esi + 0x4Cu) == 0u) goto label_000D2C13;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000D2BDC;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD2BDCu)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xD2BDCu));
    label_000D2BDC:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->eax > (int32_t)cpu->edi) goto label_000D2C13;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)cpu->edi >= (int32_t)cpu->edx) goto label_000D2C13;
    if ((int32_t)cpu->ecx > (int32_t)cpu->ebp) goto label_000D2C13;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax += cpu->ecx;
    if ((int32_t)cpu->ebp >= (int32_t)cpu->eax) goto label_000D2C13;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->hitTest(cpu);
    if (cpu->eax != 0u) goto label_000D2C21;
    label_000D2C13:
    cpu->ebx = *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ebx != *(uint32_t*)(cpu->ecx + 0xA0u)) goto label_000D2BB0;
    label_000D2C21:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D2C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = 0u;
    if (*(uint8_t*)(cpu->esi + 0x48u) != (cpu->eax & 0xFFu)) goto label_000D2D15;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000D2C62;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD2C62u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xD2C62u));
    label_000D2C62:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->eax > (int32_t)cpu->edi) goto label_000D2C94;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)cpu->edi >= (int32_t)cpu->edx) goto label_000D2C94;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((int32_t)cpu->ecx > (int32_t)cpu->ebp) goto label_000D2C94;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax += cpu->ecx;
    if ((int32_t)cpu->ebp < (int32_t)cpu->eax) goto label_000D2CA0;
    label_000D2C94:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D2CA0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if (cpu->eax == cpu->ecx) goto label_000D2D10;
    label_000D2CB1:
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->ebx + 8u);
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000D2D08;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000D2CE0;
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD2CE0u)); sfera_sub_0049EC80(cpu, LIFT_CODE_TOKEN_RVA(0xD2CE0u));
    label_000D2CE0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x20u);
    if ((int32_t)cpu->eax > (int32_t)cpu->edi) goto label_000D2D08;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)cpu->edi >= (int32_t)cpu->edx) goto label_000D2D08;
    if ((int32_t)cpu->ecx > (int32_t)cpu->ebp) goto label_000D2D08;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax += cpu->ecx;
    if ((int32_t)cpu->ebp < (int32_t)cpu->eax) goto label_000D2D1C;
    label_000D2D08:
    cpu->eax = cpu->ebx;
    if (cpu->eax != *(uint32_t*)(cpu->esp + 0x14u)) goto label_000D2CB1;
    label_000D2D10:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    label_000D2D15:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D2D1C:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xD8u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D2D30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    { uint64_t l=*(uint8_t*)(cpu->eax + 0x11u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D2D5A;
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
__declspec(noinline) void sfera_sub_004D2DA0(LiftCpu* cpu, uint32_t stop_address) {
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
    { uint64_t l=cpu->edx, r=*(uint32_t*)(cpu->esi + 4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D2DD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = cpu->edi + 0xFFFFF447u;
    if (cpu->eax > 0x1F3u) goto label_000D2E8C;
    if (*(uint32_t*)(cpu->esi + 0xECu) != 0u) goto label_000D2E60;
    cpu->edx = 0x1C9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2E24u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D2E24u));
    lift_push32(cpu, 0x1F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2E2Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D2E2Eu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    if (cpu->eax == 0u) goto label_000D2E4A;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2E48u)); sfera_sub_004CFE70(cpu, LIFT_CODE_TOKEN_VA(0x4D2E48u));
    goto label_000D2E4C;
    label_000D2E4A:
    cpu->eax = 0u;
    label_000D2E4C:
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x9Cu) = cpu->esi;
    label_000D2E60:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xECu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D2E8C:
    cpu->eax = cpu->edi + 0xFFFFFF97u;
    { uint64_t l=cpu->eax, r=0x12u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000D301A;
    switch (cpu->eax) {
        case 0u: goto label_000D2F07;
        case 1u: goto label_000D2F17;
        case 2u: goto label_000D2F26;
        case 3u: goto label_000D2F46;
        case 4u: goto label_000D2F87;
        case 5u: case 6u: case 13u: goto label_000D301A;
        case 7u: goto label_000D2F96;
        case 8u: goto label_000D2FA3;
        case 9u: goto label_000D2FAF;
        case 10u: goto label_000D2F71;
        case 11u: goto label_000D2FBB;
        case 12u: goto label_000D2FF0;
        case 14u: goto label_000D2E9F;
        case 15u: goto label_000D2EDE;
        case 16u: goto label_000D2EB5;
        case 17u: goto label_000D2FD0;
        case 18u: goto label_000D2FE0;
        default: lift_trap(cpu, 0x4D2E98u, "resolved jump-table index out of range"); return;
    }
label_000D2E9F: ;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = 0u;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0xB8u), r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    goto label_000D301A;
    label_000D2EB5:
    if (*(uint32_t*)(cpu->esi + 0xB8u) != 0u) goto label_000D301A;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, 0u); lift_push32(cpu, 1u);
    *(uint32_t*)(cpu->esi + 0xB8u) = cpu->edx;
    lift_push32(cpu, 0x73u);
    reinterpret_cast<SphereUI::Window*>(cpu->esi)->handleMessage(cpu);
    goto label_000D301A;
    label_000D2EDE:
    if (*(uint32_t*)(cpu->esi + 0xB8u) == 0u) goto label_000D301A;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x73u);
    *(uint32_t*)(cpu->esi + 0xB8u) = 0u;
    reinterpret_cast<SphereUI::Window*>(cpu->esi)->handleMessage(cpu);
    goto label_000D301A;
    label_000D2F07:
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x28u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->esi + 0x4Au) = cpu->eax & 0xFFu;
    goto label_000D301A;
    label_000D2F17:
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x4Au);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    goto label_000D301A;
    label_000D2F26:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax <<= 24u;
    cpu->ecx &= 0xFFFFFFu;
    cpu->eax |= cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->eax;
    goto label_000D301A;
    label_000D2F46:
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x28u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->esi + 0x48u) = cpu->eax & 0xFFu;
    label_000D2F51:
    if ((cpu->eax & 0xFFu) == 0u) goto label_000D301A;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xECu);
    if (cpu->ecx == 0u) goto label_000D301A;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2F6Cu)); sfera_sub_004CF750(cpu, LIFT_CODE_TOKEN_VA(0x4D2F6Cu));
    goto label_000D301A;
    label_000D2F71:
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x28u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = cpu->edx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2F82u)); sfera_sub_004D1F10(cpu, LIFT_CODE_TOKEN_VA(0x4D2F82u));
    goto label_000D301A;
    label_000D2F87:
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x48u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    goto label_000D301A;
    label_000D2F96:
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x28u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->esi + 0x49u) = cpu->eax & 0xFFu;
    goto label_000D2F51;
    label_000D2FA3:
    cpu->eax = *(uint8_t*)(cpu->esi + 0x49u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    goto label_000D301A;
    label_000D2FAF:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esi + 0x118u) = cpu->edx;
    goto label_000D301A;
    label_000D2FBB:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->esi)->setPosition(cpu);
    goto label_000D301A;
    label_000D2FD0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edx;
    goto label_000D301A;
    label_000D2FE0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->esi)->setFont(cpu);
    goto label_000D301A;
    label_000D2FF0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2FF5u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4D2FF5u));
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3014u)); sfera_sub_004D2C30(cpu, LIFT_CODE_TOKEN_VA(0x4D3014u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    label_000D301A:
    cpu->eax = 1u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D3080(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->ecx + 0xCCu) == cpu->esi) goto label_000D30CD;
    label_000D3090:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCCu);
    if (cpu->eax == cpu->esi) goto label_000D30C5;
    ++*(uint32_t*)(cpu->ecx + 0xC8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xC8u);
    if (*(uint32_t*)(cpu->ecx + 0xC4u) > cpu->edx) goto label_000D30B4;
    *(uint32_t*)(cpu->ecx + 0xC8u) = cpu->esi;
    label_000D30B4:
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 0xCCu) = cpu->eax;
    if (cpu->eax != cpu->esi) goto label_000D30C5;
    *(uint32_t*)(cpu->ecx + 0xC8u) = cpu->esi;
    label_000D30C5:
    if (*(uint32_t*)(cpu->ecx + 0xCCu) != cpu->esi) goto label_000D3090;
    label_000D30CD:
    *(uint32_t*)(cpu->ecx + 0xD4u) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D30E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    if (cpu->eax == *(uint32_t*)(cpu->esi)) goto label_000D3112;
    lift_push32(cpu, cpu->edi);
    label_000D3100:
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3108u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D3108u));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if (cpu->edi != *(uint32_t*)(cpu->esi)) goto label_000D3100;
    cpu->edi = lift_pop32(cpu);
    label_000D3112:
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D311Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D311Au));
    cpu->esp += 4u;
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000D312D;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D312Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D312Au));
    cpu->esp += 4u;
    label_000D312D:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D3140(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3170u)); sfera_sub_004D2560(cpu, LIFT_CODE_TOKEN_VA(0x4D3170u));
    cpu->ebx = 0u;
    if (cpu->eax != cpu->ebx) goto label_000D3272;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3181u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x4D3181u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_000D3270;
    cpu->edx = 0x188u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3199u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3199u));
    lift_push32(cpu, 0x98u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D31A3u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D31A3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    if (cpu->eax == cpu->ebx) goto label_000D31BB;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D31B9u)); sfera_sub_004CDF00(cpu, LIFT_CODE_TOKEN_VA(0x4D31B9u));
    cpu->ebx = cpu->eax;
    label_000D31BB:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D31CFu)); sfera_sub_004CF1A0(cpu, LIFT_CODE_TOKEN_VA(0x4D31CFu));
    if (*(uint32_t*)(cpu->esi + 0x174u) != 0u) goto label_000D321A;
    cpu->edx = 0x18Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D31E7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D31E7u));
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D31EEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D31EEu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 1u;
    if (cpu->eax == 0u) goto label_000D320A;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3208u)); sfera_sub_004D2420(cpu, LIFT_CODE_TOKEN_VA(0x4D3208u));
    goto label_000D320C;
    label_000D320A:
    cpu->eax = 0u;
    label_000D320C:
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x174u) = cpu->eax;
    label_000D321A:
    cpu->esi = *(uint32_t*)(cpu->esi + 0x174u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3233u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4D3233u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000D324D;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4D321Au), "std::length_error");
    label_000D324D:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D3270:
    cpu->eax = 0u;
    label_000D3272:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D3290(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0xD4u) < 0x40u) goto label_000D32A1;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD32A1u)); sfera_sub_004D3080(cpu, LIFT_CODE_TOKEN_RVA(0xD32A1u));
    label_000D32A1:
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0xBCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D32B1u)); sfera_sub_004A01D0(cpu, LIFT_CODE_TOKEN_VA(0x4D32B1u));
    ++*(uint32_t*)(cpu->esi + 0xD4u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D32C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if (*(uint32_t*)(cpu->ebp + 0xD4u) != 0u) goto label_000D32D8;
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D32D8:
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xBCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D32E9u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4D32E9u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx == 0u) goto label_000D32F1;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_000D32F1:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->edx > cpu->eax) goto label_000D32FD;
    cpu->eax -= cpu->edx;
    label_000D32FD:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = 7u;
    lift_movs32(cpu, 1u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCCu);
    cpu->edx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if (cpu->eax == cpu->edx) goto label_000D3349;
    ++*(uint32_t*)(cpu->ebp + 0xC8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xC8u);
    if (*(uint32_t*)(cpu->ebp + 0xC4u) > cpu->ecx) goto label_000D3338;
    *(uint32_t*)(cpu->ebp + 0xC8u) = cpu->edx;
    label_000D3338:
    --cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xCCu) = cpu->eax;
    if (cpu->eax != cpu->edx) goto label_000D3349;
    *(uint32_t*)(cpu->ebp + 0xC8u) = cpu->edx;
    label_000D3349:
    --*(uint32_t*)(cpu->ebp + 0xD4u);
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D3360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if (*(uint32_t*)(cpu->ebp + 0xF8u) == 0u) goto label_000D3416;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000D3381:
    if (*(uint32_t*)(cpu->ebp + 0xD4u) == 0u) goto label_000D3413;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xBCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D339Eu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4D339Eu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx == 0u) goto label_000D33A6;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_000D33A6:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->edx > cpu->eax) goto label_000D33B2;
    cpu->eax -= cpu->edx;
    label_000D33B2:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCCu);
    cpu->edx = 0u;
    cpu->ecx = 7u;
    cpu->edi = cpu->esp + 0x1Cu;
    lift_movs32(cpu, 1u);
    if (cpu->eax == cpu->edx) goto label_000D33FA;
    ++*(uint32_t*)(cpu->ebp + 0xC8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xC8u);
    if (*(uint32_t*)(cpu->ebp + 0xC4u) > cpu->ecx) goto label_000D33E9;
    *(uint32_t*)(cpu->ebp + 0xC8u) = cpu->edx;
    label_000D33E9:
    --cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xCCu) = cpu->eax;
    if (cpu->eax != cpu->edx) goto label_000D33FA;
    *(uint32_t*)(cpu->ebp + 0xC8u) = cpu->edx;
    label_000D33FA:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xF8u);
    --*(uint32_t*)(cpu->ebp + 0xD4u);
    cpu->edx = cpu->esp + 0x1Cu;
    cpu->ecx = cpu->ebp;
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0xD340Eu), LIFT_CODE_TOKEN_RVA(0xD340Cu))) { return; }
    goto label_000D3381;
    label_000D3413:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D3416:
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D3430(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = 1u;
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_control_reference_registry_guard)) & ((cpu->ebx & 0xFFu))) != 0u) goto label_000D34BC;
    *(uint32_t*)((uintptr_t)&g_sfera_control_reference_registry_guard) = (uint64_t)(g_sfera_control_reference_registry_guard) | (uint64_t)(cpu->ebx);
    lift_push32(cpu, 0x14u);
    *(uint32_t*)(cpu->esp + 0x24u) = 0u;
    g_sfera_control_reference_registry.size = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3480u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3480u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000D34D2;
    g_sfera_control_reference_registry.sentinel = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    *(uint8_t*)(cpu->eax + 0x10u) = cpu->ebx & 0xFFu;
    cpu->ecx = g_sfera_control_reference_registry.sentinel;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC030));
    *(uint8_t*)(cpu->ecx + 0x11u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D34B9u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4D34B9u));
    cpu->esp += 4u;
    label_000D34BC:
    cpu->eax = (uintptr_t)&g_sfera_control_reference_registry;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D34D2:
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3500u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4D3500u));
    lift_trap(cpu, 0x4D3500u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004D3510(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x3Cu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::Window*>(cpu->esi));
    cpu->ebx = 0u;
    cpu->ebp = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 8u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x48u) = 1u;
    *(uint32_t*)(cpu->esi + 0x4Cu) = 0x10100u;
    *(uint32_t*)(cpu->esi + 0x50u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x54u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x84u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x80u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x70u) = cpu->ebx & 0xFFu;
    *(uint16_t*)(cpu->esi + 0x8Cu) = 0x100u;
    *(uint32_t*)(cpu->esi + 0x90u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x94u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x98u) = 0xFF000000u;
    *(uint32_t*)(cpu->esi + 0x9Cu) = cpu->ebx;
    lift_push32(cpu, 0xCu);
    *(uint8_t*)(cpu->esp + 0x48u) = 2u;
    *(uint32_t*)(cpu->esi + 0xA4u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D35D0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D35D0u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000D379F;
    *(uint32_t*)(cpu->esi + 0xA0u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    lift_push32(cpu, 0xCu);
    *(uint8_t*)(cpu->esp + 0x48u) = 3u;
    *(uint32_t*)(cpu->esi + 0xB0u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D35FEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D35FEu));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000D3775;
    *(uint32_t*)(cpu->esi + 0xACu) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xACu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->edi = cpu->esi + 0xBCu;
    *(uint32_t*)(cpu->esi + 0xB8u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    *(uint32_t*)(cpu->edi) = cpu->ebx;
    lift_push32(cpu, 8u);
    *(uint8_t*)(cpu->esp + 0x48u) = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3638u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3638u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000D374B;
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
    *(uint32_t*)(cpu->esi + 0xD4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xD8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xDCu) = 0xFFu;
    *(uint16_t*)(cpu->esi + 0xE0u) = cpu->ebx & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xF0u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xF4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xF8u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x10Cu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x118u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x11Cu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x170u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x174u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x188u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x178u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x44u) = 7u;
    *(uint32_t*)(cpu->esi + 0x194u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x120u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x148u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0xE4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xE8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xFCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x104u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x100u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x108u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x110u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x114u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3719u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4D3719u));
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x18u;
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3728u)); sfera_sub_004D23B0(cpu, LIFT_CODE_TOKEN_VA(0x4D3728u));
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3735u)); sfera_sub_004D2480(cpu, LIFT_CODE_TOKEN_VA(0x4D3735u));
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D374B:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x28u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD3775u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xD3775u));
    label_000D3775:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x28u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD379Fu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xD379Fu));
    label_000D379F:
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x34u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D37C9u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4D37C9u));
    lift_trap(cpu, 0x4D37C9u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004D37D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x24u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::Window*>(cpu->esi));
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 6u;
    if (*(uint8_t*)(cpu->esi + 0x4Bu) != (cpu->ebx & 0xFFu)) goto label_000D3888;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x174u);
    if (cpu->eax == cpu->ebx) goto label_000D3888;
    if (*(uint32_t*)(cpu->eax + 4u) <= cpu->ebx) goto label_000D3862;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (cpu->edi == cpu->eax) goto label_000D3862;
    label_000D3830:
    cpu->edx = 0x143u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D383Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D383Fu));
    cpu->ebp = *(uint32_t*)(cpu->edi + 8u);
    if (cpu->ebp == cpu->ebx) goto label_000D3856;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D384Du)); sfera_sub_004CF160(cpu, LIFT_CODE_TOKEN_VA(0x4D384Du));
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3853u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D3853u));
    cpu->esp += 4u;
    label_000D3856:
    cpu->edi = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x174u);
    if (cpu->edi != *(uint32_t*)(cpu->eax)) goto label_000D3830;
    label_000D3862:
    cpu->edx = 0x145u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3871u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3871u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x174u);
    if (cpu->ecx == cpu->ebx) goto label_000D3882;
    lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD3882u)); sfera_sub_004D30E0(cpu, LIFT_CODE_TOKEN_RVA(0xD3882u));
    label_000D3882:
    *(uint32_t*)(cpu->esi + 0x174u) = cpu->ebx;
    label_000D3888:
    if (*(uint32_t*)(cpu->esi + 0xA4u) <= cpu->ebx) goto label_000D3905;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (cpu->edi == cpu->eax) goto label_000D38C9;
    label_000D38A0:
    cpu->edx = 0x14Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D38AFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D38AFu));
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    if (cpu->ecx == cpu->ebx) goto label_000D38BF;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000D38BF:
    cpu->edi = *(uint32_t*)(cpu->edi);
    if (cpu->edi != *(uint32_t*)(cpu->esi + 0xA0u)) goto label_000D38A0;
    label_000D38C9:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0xA4u) = cpu->ebx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0xA0u)) goto label_000D3905;
    label_000D38F0:
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D38F8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D38F8u));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if (cpu->edi != *(uint32_t*)(cpu->esi + 0xA0u)) goto label_000D38F0;
    label_000D3905:
    if (*(uint32_t*)(cpu->esi + 0xECu) == cpu->ebx) goto label_000D3935;
    cpu->edx = 0x153u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D391Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D391Cu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xECu);
    if (cpu->ecx == cpu->ebx) goto label_000D392F;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000D392F:
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->ebx;
    label_000D3935:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D393Eu)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4D393Eu));
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edi = cpu->eax;
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3951u)); sfera_sub_004D20F0(cpu, LIFT_CODE_TOKEN_VA(0x4D3951u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3967u)); sfera_sub_004B2C40(cpu, LIFT_CODE_TOKEN_VA(0x4D3967u));
    if (*(uint32_t*)(cpu->esi + 0x18Cu) < 0x10u) goto label_000D397F;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x178u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D397Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D397Cu));
    cpu->esp += 4u;
    label_000D397F:
    cpu->ebp = 0xFu;
    *(uint32_t*)(cpu->esi + 0x18Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x188u) = cpu->ebx;
    cpu->ecx = cpu->esi + 0xBCu;
    *(uint8_t*)(cpu->esi + 0x178u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D39A1u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4D39A1u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xBCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D39ADu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D39ADu));
    *(uint32_t*)(cpu->esi + 0xBCu) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xACu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xACu);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0xB0u) = cpu->ebx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0xACu)) goto label_000D39EC;
    label_000D39D7:
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D39DFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D39DFu));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if (cpu->edi != *(uint32_t*)(cpu->esi + 0xACu)) goto label_000D39D7;
    label_000D39EC:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xACu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D39F8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D39F8u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0xA4u) = cpu->ebx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0xA0u)) goto label_000D3A35;
    label_000D3A20:
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3A28u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D3A28u));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if (cpu->edi != *(uint32_t*)(cpu->esi + 0xA0u)) goto label_000D3A20;
    label_000D3A35:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3A41u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D3A41u));
    cpu->edi = 0x10u;
    cpu->esp += 4u;
    if (*(uint32_t*)(cpu->esi + 0x84u) < cpu->edi) goto label_000D3A5D;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x70u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3A5Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D3A5Au));
    cpu->esp += 4u;
    label_000D3A5D:
    *(uint32_t*)(cpu->esi + 0x84u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x80u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x70u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0x68u) < cpu->edi) goto label_000D3A7D;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x54u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3A7Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D3A7Au));
    cpu->esp += 4u;
    label_000D3A7D:
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x54u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < cpu->edi) goto label_000D3A97;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3A94u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D3A94u));
    cpu->esp += 4u;
    label_000D3A97:
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 8u) = cpu->ebx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D3AC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    (void)0; /* source SEH registration eliminated */
    if (cpu->ecx > 0x18u) goto label_000D4191;
    switch (cpu->ecx) {
        case 0u: goto label_000D3AF1;
        case 1u: goto label_000D3B38;
        case 2u: goto label_000D3B7F;
        case 3u: goto label_000D3C54;
        case 4u: goto label_000D3BC6;
        case 5u: goto label_000D3C0D;
        case 6u: goto label_000D3C9B;
        case 7u: goto label_000D3CE2;
        case 8u: goto label_000D3D29;
        case 9u: goto label_000D4191;
        case 10u: goto label_000D3D70;
        case 11u: goto label_000D3DB7;
        case 12u: goto label_000D3DFE;
        case 13u: goto label_000D3E45;
        case 14u: goto label_000D3E8C;
        case 15u: goto label_000D3ED3;
        case 16u: goto label_000D3F1A;
        case 17u: goto label_000D3F61;
        case 18u: goto label_000D3FA8;
        case 19u: goto label_000D3FEF;
        case 20u: goto label_000D4036;
        case 21u: goto label_000D407D;
        case 22u: goto label_000D40C4;
        case 23u: goto label_000D410B;
        case 24u: goto label_000D414E;
        default: lift_trap(cpu, 0x4D3AEAu, "resolved jump-table index out of range"); return;
    }
label_000D3AF1: ;
    cpu->edx = 0xD9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3B00u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3B00u));
    lift_push32(cpu, 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3B0Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3B0Au));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3B28u)); sfera_sub_004D3510(cpu, LIFT_CODE_TOKEN_VA(0x4D3B28u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3B38:
    cpu->edx = 0xDAu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3B47u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3B47u));
    lift_push32(cpu, 0x1C8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3B51u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3B51u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3B6Fu)); sfera_sub_0049ED60(cpu, LIFT_CODE_TOKEN_VA(0x4D3B6Fu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3B7F:
    cpu->edx = 0xDBu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3B8Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3B8Eu));
    lift_push32(cpu, 0x1A0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3B98u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3B98u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 2u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3BB6u)); sfera_sub_004CF2E0(cpu, LIFT_CODE_TOKEN_VA(0x4D3BB6u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3BC6:
    cpu->edx = 0xDCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3BD5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3BD5u));
    lift_push32(cpu, 0x1F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3BDFu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3BDFu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 3u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3BFDu)); sfera_sub_004C3BA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3BFDu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3C0D:
    cpu->edx = 0xDDu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3C1Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3C1Cu));
    lift_push32(cpu, 0x1F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3C26u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3C26u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 4u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3C44u)); sfera_sub_004C6A20(cpu, LIFT_CODE_TOKEN_VA(0x4D3C44u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3C54:
    cpu->edx = 0xDEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3C63u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3C63u));
    lift_push32(cpu, 0x1B8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3C6Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3C6Du));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 5u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3C8Bu)); sfera_sub_004B77A0(cpu, LIFT_CODE_TOKEN_VA(0x4D3C8Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3C9B:
    cpu->edx = 0xDFu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3CAAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3CAAu));
    lift_push32(cpu, 0x310u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3CB4u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3CB4u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 6u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3CD2u)); sfera_sub_004B0100(cpu, LIFT_CODE_TOKEN_VA(0x4D3CD2u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3CE2:
    cpu->edx = 0xE0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3CF1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3CF1u));
    lift_push32(cpu, 0x1C8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3CFBu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3CFBu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 7u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3D19u)); sfera_sub_004A0E60(cpu, LIFT_CODE_TOKEN_VA(0x4D3D19u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3D29:
    cpu->edx = 0xE1u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3D38u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3D38u));
    lift_push32(cpu, 0x1C8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3D42u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3D42u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 8u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3D60u)); sfera_sub_004C43A0(cpu, LIFT_CODE_TOKEN_VA(0x4D3D60u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3D70:
    cpu->edx = 0xE2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3D7Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3D7Fu));
    lift_push32(cpu, 0x1F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3D89u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3D89u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 9u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3DA7u)); sfera_sub_004BFB90(cpu, LIFT_CODE_TOKEN_VA(0x4D3DA7u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3DB7:
    cpu->edx = 0xE3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3DC6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3DC6u));
    lift_push32(cpu, 0x248u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3DD0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3DD0u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0xAu;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3DEEu)); sfera_sub_004C8020(cpu, LIFT_CODE_TOKEN_VA(0x4D3DEEu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3DFE:
    cpu->edx = 0xE4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3E0Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3E0Du));
    lift_push32(cpu, 0x1E8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3E17u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3E17u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0xBu;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3E35u)); sfera_sub_004BDCD0(cpu, LIFT_CODE_TOKEN_VA(0x4D3E35u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3E45:
    cpu->edx = 0xE5u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3E54u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3E54u));
    lift_push32(cpu, 0x65F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3E5Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3E5Eu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0xCu;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3E7Cu)); sfera_sub_004A2D20(cpu, LIFT_CODE_TOKEN_VA(0x4D3E7Cu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3E8C:
    cpu->edx = 0xE6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3E9Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3E9Bu));
    lift_push32(cpu, 0x298u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3EA5u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3EA5u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0xDu;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3EC3u)); sfera_sub_004C8F60(cpu, LIFT_CODE_TOKEN_VA(0x4D3EC3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3ED3:
    cpu->edx = 0xE7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3EE2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3EE2u));
    lift_push32(cpu, 0x1F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3EECu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3EECu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0xEu;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3F0Au)); sfera_sub_004C3250(cpu, LIFT_CODE_TOKEN_VA(0x4D3F0Au));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3F1A:
    cpu->edx = 0xE8u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3F29u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3F29u));
    lift_push32(cpu, 0x1C0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3F33u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3F33u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0xFu;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3F51u)); sfera_sub_004CD430(cpu, LIFT_CODE_TOKEN_VA(0x4D3F51u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3F61:
    cpu->edx = 0xE9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3F70u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3F70u));
    lift_push32(cpu, 0x1D0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3F7Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3F7Au));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x10u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3F98u)); sfera_sub_004C5D00(cpu, LIFT_CODE_TOKEN_VA(0x4D3F98u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3FA8:
    cpu->edx = 0xEAu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3FB7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3FB7u));
    lift_push32(cpu, 0x210u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3FC1u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D3FC1u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x11u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3FDFu)); sfera_sub_004A41B0(cpu, LIFT_CODE_TOKEN_VA(0x4D3FDFu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D3FEF:
    cpu->edx = 0xEDu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D3FFEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D3FFEu));
    lift_push32(cpu, 0x1C0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4008u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D4008u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x12u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4026u)); sfera_sub_004D0890(cpu, LIFT_CODE_TOKEN_VA(0x4D4026u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D4036:
    cpu->edx = 0xEEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4045u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4045u));
    lift_push32(cpu, 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D404Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D404Fu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x13u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D406Du)); sfera_sub_004C3640(cpu, LIFT_CODE_TOKEN_VA(0x4D406Du));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D407D:
    cpu->edx = 0xEFu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D408Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D408Cu));
    lift_push32(cpu, 0x240u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4096u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D4096u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x14u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D40B4u)); sfera_sub_004C2770(cpu, LIFT_CODE_TOKEN_VA(0x4D40B4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D40C4:
    cpu->edx = 0xF0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D40D3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D40D3u));
    lift_push32(cpu, 0x298u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D40DDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D40DDu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x15u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D40FBu)); sfera_sub_004AA410(cpu, LIFT_CODE_TOKEN_VA(0x4D40FBu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D410B:
    cpu->edx = 0xF1u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D411Au)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D411Au));
    lift_push32(cpu, 0x280u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4124u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D4124u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x16u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D413Eu)); sfera_sub_004B4DD0(cpu, LIFT_CODE_TOKEN_VA(0x4D413Eu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D414E:
    cpu->edx = 0xF2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D415Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D415Du));
    lift_push32(cpu, 0x1A0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4167u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D4167u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x17u;
    if (cpu->eax == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4181u)); sfera_sub_004A55D0(cpu, LIFT_CODE_TOKEN_VA(0x4D4181u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D4191:
    lift_push32(cpu, 0xF5u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D41A5u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D41A5u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D41ABu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D41ABu));
    cpu->esp += 0x10u;
    label_000D41AE:
    cpu->eax = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D4230(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x134u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x148u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x164u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x158u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x160u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x15Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if (cpu->ecx != 0x7FFFFFFFu) goto label_000D42A2;
    label_000D429B:
    cpu->eax = 0u;
    goto label_000D4784;
    label_000D42A2:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D42A7u)); sfera_sub_004D3AC0(cpu, LIFT_CODE_TOKEN_VA(0x4D42A7u));
    cpu->ebp = cpu->eax;
    cpu->esi = 0u;
    if (cpu->ebp == cpu->esi) goto label_000D429B;
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D42BBu)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4D42BBu));
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"tooltip");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D42CFu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4D42CFu));
    if (cpu->eax == 0u) goto label_000D4351;
    cpu->edx = 0x393u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D42E2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D42E2u));
    lift_push32(cpu, 0x1F8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D42ECu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D42ECu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x150u) = cpu->esi;
    if (cpu->eax == cpu->esi) goto label_000D4307;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4305u)); sfera_sub_004CFE70(cpu, LIFT_CODE_TOKEN_VA(0x4D4305u));
    cpu->esi = cpu->eax;
    label_000D4307:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x15Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x9Cu) = cpu->ebp;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->loadUi(cpu);
    if (cpu->eax == 0u) goto label_000D4337;
    *(uint32_t*)(cpu->ebp + 0xECu) = cpu->esi;
    goto label_000D4351;
    label_000D4337:
    cpu->edx = 0x399u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4346u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4346u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000D4351:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"position");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D435Eu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D435Eu));
    cpu->esi = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_000D43AA;
    cpu->ecx = cpu->ebp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD437Bu), LIFT_CODE_TOKEN_RVA(0xD4379u))) { return; }
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000D43AA;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x168u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Window::LoadControl(%s,%d,%d) -> Position is wrong in control %d.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D43A1u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D43A1u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D43A7u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D43A7u));
    cpu->esp += 0x18u;
    label_000D43AA:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"size");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D43B7u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D43B7u));
    if (cpu->eax == 0u) goto label_000D43FD;
    cpu->edx = cpu->ebp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD43CEu), LIFT_CODE_TOKEN_RVA(0xD43CCu))) { return; }
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000D43FD;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x168u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Window::LoadControl(%s,%d,%d) -> Size is wrong in control %d.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D43F4u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D43F4u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D43FAu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D43FAu));
    cpu->esp += 0x18u;
    label_000D43FD:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"disabledcolor");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D440Au)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D440Au));
    if (cpu->eax == 0u) goto label_000D4473;
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD4428u), LIFT_CODE_TOKEN_RVA(0xD4426u))) { return; }
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000D444F;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadControl(%s,%d,%d) -> Not enough args in 'disabledColor'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4446u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D4446u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D444Cu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D444Cu));
    cpu->esp += 0x14u;
    label_000D444F:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x30u);
    cpu->eax = *(uint8_t*)(cpu->esp + 0x1Cu);
    { uint64_t l=cpu->ecx, r=0xFFFFFF00u, v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx <<= 8u;
    { uint64_t l=cpu->ecx, r=cpu->edx, v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x98u) = cpu->ecx;
    label_000D4473:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"showTitle");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4480u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4480u));
    if (cpu->eax == 0u) goto label_000D44C8;
    cpu->ecx = cpu->ebp + 0xE8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xE4u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD449Du), LIFT_CODE_TOKEN_RVA(0xD449Bu))) { return; }
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000D44C4;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadControl(%s,%d,%d) -> Not enough args in 'showTitle'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D44BBu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D44BBu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D44C1u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D44C1u));
    cpu->esp += 0x14u;
    label_000D44C4:
    *(uint32_t*)(cpu->ebp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->ebp + 0x24u)) | (uint64_t)(4u);
    label_000D44C8:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"disabled");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D44D5u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D44D5u));
    if (cpu->eax == 0u) goto label_000D44EA;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D44E2u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4D44E2u));
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->ebp + 0x49u) = cpu->ecx & 0xFFu;
    label_000D44EA:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"hidden");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D44F7u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D44F7u));
    if (cpu->eax == 0u) goto label_000D450C;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4504u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4D4504u));
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->ebp + 0x48u) = cpu->edx & 0xFFu;
    label_000D450C:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"group");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4519u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4519u));
    if (cpu->eax == 0u) goto label_000D4529;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4526u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4D4526u));
    *(uint32_t*)(cpu->ebp + 0x3Cu) = cpu->eax;
    label_000D4529:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"font");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4536u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4536u));
    if (cpu->eax == 0u) goto label_000D4550;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4543u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4D4543u));
    *(uint8_t*)(cpu->ebp + 0x8Cu) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->ebp + 0x8Du) = 1u;
    label_000D4550:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"textFormat");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D455Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D455Du));
    if (cpu->eax == 0u) goto label_000D45C5;
    cpu->eax = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D456Fu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4D456Fu));
    if (cpu->eax == 0u) goto label_000D45C5;
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0x118u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4584u)); sfera_sub_004947E0(cpu, LIFT_CODE_TOKEN_VA(0x4D4584u));
    cpu->esi = cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    if ((int32_t)cpu->esi <= 0) goto label_000D45BB;
    label_000D4590:
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D459Du)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4D459Du));
    if (cpu->eax == 0u) goto label_000D45B4;
    cpu->esi = cpu->esp + 0x44u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D45AAu)); sfera_sub_004D1930(cpu, LIFT_CODE_TOKEN_VA(0x4D45AAu));
    *(uint32_t*)(cpu->ebp + 0x118u) = (uint64_t)(*(uint32_t*)(cpu->ebp + 0x118u)) | (uint64_t)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000D45B4:
    cpu->ebx += 2u;
    if ((int32_t)cpu->ebx < (int32_t)cpu->esi) goto label_000D4590;
    label_000D45BB:
    cpu->esi = native_function_address32(&::sscanf);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    label_000D45C5:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"textColor");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D45D2u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D45D2u));
    if (cpu->eax == 0u) goto label_000D4643;
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD45F0u), LIFT_CODE_TOKEN_RVA(0xD45EEu))) { return; }
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000D461F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x168u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadControl(%s,%d,%d) -> Not enough args in 'textColor' in control %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4616u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D4616u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D461Cu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D461Cu));
    cpu->esp += 0x18u;
    label_000D461F:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint8_t*)(cpu->esp + 0x20u);
    { uint64_t l=cpu->ecx, r=0xFFFFFF00u, v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx <<= 8u;
    { uint64_t l=cpu->ecx, r=cpu->edx, v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x90u) = cpu->ecx;
    label_000D4643:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"windowText");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4650u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4650u));
    if (cpu->eax == 0u) goto label_000D467C;
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4662u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4D4662u));
    if (cpu->eax == 0u) goto label_000D467C;
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D466Fu)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4D466Fu));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD467Cu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xD467Cu));
    label_000D467C:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"windowHelp");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4689u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4689u));
    if (cpu->eax == 0u) goto label_000D46BD;
    cpu->edx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D469Bu)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4D469Bu));
    if (cpu->eax == 0u) goto label_000D46BD;
    cpu->eax = cpu->esp + 0x44u;
    cpu->edx = cpu->eax + 1u;
    label_000D46A6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000D46A6;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x70u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD46BDu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_RVA(0xD46BDu));
    label_000D46BD:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"setWindowText");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D46CAu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D46CAu));
    if (cpu->eax == 0u) goto label_000D46FE;
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D46DCu)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4D46DCu));
    if (cpu->eax == 0u) goto label_000D46FE;
    cpu->eax = cpu->esp + 0x44u;
    cpu->edx = cpu->eax + 1u;
    label_000D46E7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000D46E7;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD46FEu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_RVA(0xD46FEu));
    label_000D46FE:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"canDragDrop");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D470Bu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D470Bu));
    if (cpu->eax == 0u) goto label_000D4720;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4718u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4D4718u));
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->ebp + 0x4Cu) = cpu->eax & 0xFFu;
    label_000D4720:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x9Cu);
    if (cpu->eax != 0u) goto label_000D4730;
    cpu->eax = cpu->ecx;
    label_000D4730:
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ebp + 0x9Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->loadUi(cpu);
    if (cpu->eax != 0u) goto label_000D4769;
    cpu->edx = 0x3F0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4759u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4759u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    cpu->ebp = 0u;
    goto label_000D4776;
    label_000D4769:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x168u);
    *(uint32_t*)(cpu->ebp + 0xD8u) = cpu->eax;
    label_000D4776:
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4782u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4D4782u));
    cpu->eax = cpu->ebp;
    label_000D4784:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x148u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x140u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D47B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x144u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x158u;
    (void)0; /* source SEH registration eliminated */
    cpu->eax = *(uint32_t*)(cpu->esp + 0x168u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x16Cu);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x170u);
    cpu->ebp = cpu->ecx;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4816u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4D4816u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"hitTransparent");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4823u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4823u));
    if (cpu->eax == 0u) goto label_000D4838;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4830u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4D4830u));
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->ebp + 0x4Fu) = cpu->edx & 0xFFu;
    label_000D4838:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"windowName");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4845u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4845u));
    if (cpu->eax == 0u) goto label_000D487C;
    cpu->eax = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4857u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4D4857u));
    if (cpu->eax == 0u) goto label_000D487C;
    cpu->eax = cpu->esp + 0x54u;
    cpu->edx = cpu->eax + 1u;
    label_000D4862:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000D4862;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0x178u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD487Cu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_RVA(0xD487Cu));
    label_000D487C:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"spritesDef");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4890u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4D4890u));
    if (cpu->eax == 0u) goto label_000D4A0E;
    cpu->eax = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D48A4u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4D48A4u));
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"sprite");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D48B5u)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x4D48B5u));
    if (cpu->eax == 0u) goto label_000D4A07;
    label_000D48BD:
    cpu->edx = 0x2B4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D48CCu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D48CCu));
    lift_push32(cpu, 0x98u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D48D6u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D48D6u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x160u) = 0u;
    if (cpu->eax == 0u) goto label_000D48F7;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D48F3u)); sfera_sub_004CDF00(cpu, LIFT_CODE_TOKEN_VA(0x4D48F3u));
    cpu->esi = cpu->eax;
    goto label_000D48F9;
    label_000D48F7:
    cpu->esi = 0u;
    label_000D48F9:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x16Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D491Au)); sfera_sub_004CE8A0(cpu, LIFT_CODE_TOKEN_VA(0x4D491Au));
    if (cpu->eax == 0u) goto label_000D49CB;
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->ebp + 0x174u) != cpu->ebx) goto label_000D498D;
    cpu->edx = 0x2BDu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D493Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D493Bu));
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4942u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D4942u));
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x160u) = 1u;
    if (cpu->esi == cpu->ebx) goto label_000D497A;
    lift_push32(cpu, 0xCu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4964u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D4964u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000D4AB2;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    goto label_000D497C;
    label_000D497A:
    cpu->esi = 0u;
    label_000D497C:
    *(uint32_t*)(cpu->esp + 0x160u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebp + 0x174u) = cpu->esi;
    label_000D498D:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x174u);
    cpu->ebx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D49A6u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4D49A6u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx < 1u) goto label_000D4ADC;
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    goto label_000D49EE;
    label_000D49CB:
    cpu->edx = 0x2C2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D49DAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D49DAu));
    if (cpu->esi == 0u) goto label_000D49EE;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D49E5u)); sfera_sub_004CF160(cpu, LIFT_CODE_TOKEN_VA(0x4D49E5u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D49EBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D49EBu));
    cpu->esp += 4u;
    label_000D49EE:
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"sprite");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D49FFu)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x4D49FFu));
    if (cpu->eax != 0u) goto label_000D48BD;
    label_000D4A07:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD4A0Eu)); sfera_sub_004948B0(cpu, LIFT_CODE_TOKEN_RVA(0xD4A0Eu));
    label_000D4A0E:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"drawMethod");
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0x194u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4A25u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4A25u));
    if (cpu->eax == 0u) goto label_000D4AFA;
    cpu->edx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4A3Bu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4D4A3Bu));
    if (cpu->eax == 0u) goto label_000D4AFA;
    cpu->esi = native_function_address32(&::_stricmp);
    cpu->eax = cpu->esp + 0x54u;
    lift_push32(cpu, (uintptr_t)"SPRITE"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD4A55u), LIFT_CODE_TOKEN_RVA(0xD4A53u))) { return; }
    cpu->esp += 8u;
    cpu->ecx = cpu->esp + 0x54u;
    if (cpu->eax != 0u) goto label_000D4AE7;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4A6Eu)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4D4A6Eu));
    if (cpu->eax == 0u) goto label_000D4AFA;
    cpu->edx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4A82u)); sfera_sub_004D3140(cpu, LIFT_CODE_TOKEN_VA(0x4D4A82u));
    *(uint32_t*)(cpu->ebp + 0x194u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000D4AFA;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->eax = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Sprite '%s' not found.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4AA7u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D4AA7u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4AADu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4AADu));
    cpu->esp += 0x18u;
    goto label_000D4AFA;
    label_000D4AB2:
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x44u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD4ADCu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xD4ADCu));
    label_000D4ADC:
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4D4ADCu), "std::length_error");
    label_000D4AE7:
    lift_push32(cpu, (uintptr_t)"NONE"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD4AEFu), LIFT_CODE_TOKEN_RVA(0xD4AEDu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000D4AFA;
    *(uint32_t*)(cpu->ebp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->ebp + 0x24u)) | (uint64_t)(2u);
    label_000D4AFA:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"showTitle");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4B07u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4B07u));
    cpu->esi = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_000D4B55;
    cpu->edx = cpu->ebp + 0xE8u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xE4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD4B2Au), LIFT_CODE_TOKEN_RVA(0xD4B28u))) { return; }
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000D4B51;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Not enough args in 'showTitle'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4B48u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D4B48u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4B4Eu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4B4Eu));
    cpu->esp += 0x14u;
    label_000D4B51:
    *(uint32_t*)(cpu->ebp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->ebp + 0x24u)) | (uint64_t)(4u);
    label_000D4B55:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"escapeHandle");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4B62u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4B62u));
    if (cpu->eax == 0u) goto label_000D4B77;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4B6Fu)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4D4B6Fu));
    if (cpu->eax == 0u) goto label_000D4B77;
    *(uint32_t*)(cpu->ebp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->ebp + 0x24u)) | (uint64_t)(8u);
    label_000D4B77:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"position");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4B84u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4B84u));
    if (cpu->eax == 0u) goto label_000D4BDE;
    cpu->esi = cpu->ebp + 0x34u;
    lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ebp + 0x30u;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4D4B99u));
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000D4BCA;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Not enough args in 'position'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4BC1u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D4BC1u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4BC7u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4BC7u));
    cpu->esp += 0x14u;
    label_000D4BCA:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->esi = native_function_address32(&::sscanf);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->ebp + 0x40u) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0x44u) = cpu->edx;
    label_000D4BDE:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"size");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4BEBu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4BEBu));
    if (cpu->eax == 0u) goto label_000D4C29;
    cpu->eax = cpu->ebp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x28u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD4C02u), LIFT_CODE_TOKEN_RVA(0xD4C00u))) { return; }
    cpu->esp += 0x10u;
    if (cpu->eax == 2u) goto label_000D4C29;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Not enough args in 'size'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4C20u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D4C20u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4C26u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4C26u));
    cpu->esp += 0x14u;
    label_000D4C29:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"windowText");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4C36u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4C36u));
    if (cpu->eax == 0u) goto label_000D4C62;
    cpu->eax = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4C48u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4D4C48u));
    if (cpu->eax == 0u) goto label_000D4C62;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4C55u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4D4C55u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD4C62u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xD4C62u));
    label_000D4C62:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"windowHelp");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4C6Fu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4C6Fu));
    if (cpu->eax == 0u) goto label_000D4CA7;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4C81u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4D4C81u));
    if (cpu->eax == 0u) goto label_000D4CA7;
    cpu->eax = cpu->esp + 0x54u;
    cpu->edx = cpu->eax + 1u;
    label_000D4C90:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000D4C90;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0x70u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD4CA7u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_RVA(0xD4CA7u));
    label_000D4CA7:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"canDragDrop");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4CB4u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4CB4u));
    if (cpu->eax == 0u) goto label_000D4CC9;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4CC1u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4D4CC1u));
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->ebp + 0x4Cu) = cpu->eax & 0xFFu;
    label_000D4CC9:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"canGoTop");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4CD6u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4CD6u));
    if (cpu->eax == 0u) goto label_000D4CEB;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4CE3u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4D4CE3u));
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->ebp + 0x4Du) = cpu->ecx & 0xFFu;
    label_000D4CEB:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"canNotCross");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4CF8u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4CF8u));
    if (cpu->eax == 0u) goto label_000D4D0D;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4D05u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4D4D05u));
    if (cpu->eax == 0u) goto label_000D4D0D;
    *(uint32_t*)(cpu->ebp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->ebp + 0x24u)) | (uint64_t)(0x10u);
    label_000D4D0D:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"rectTitle");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4D1Au)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4D1Au));
    if (cpu->eax == 0u) goto label_000D4D6C;
    cpu->edx = cpu->ebp + 0x108u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0x104u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x100u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFCu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD4D45u), LIFT_CODE_TOKEN_RVA(0xD4D43u))) { return; }
    cpu->esp += 0x18u;
    if (cpu->eax == 4u) goto label_000D4D6C;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Not enough args in 'rectTitle'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4D63u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D4D63u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4D69u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4D69u));
    cpu->esp += 0x14u;
    label_000D4D6C:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"saveLastPosition");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4D79u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4D79u));
    if (cpu->eax == 0u) goto label_000D4D8E;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4D86u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x4D4D86u));
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->ebp + 0x4Eu) = cpu->ecx & 0xFFu;
    label_000D4D8E:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"font");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4D9Bu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4D9Bu));
    if (cpu->eax == 0u) goto label_000D4DB5;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4DA8u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4D4DA8u));
    *(uint8_t*)(cpu->ebp + 0x8Cu) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->ebp + 0x8Du) = 1u;
    label_000D4DB5:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"alignWin");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4DC2u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4DC2u));
    if (cpu->eax == 0u) goto label_000D4E08;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4DCDu)); sfera_sub_004947E0(cpu, LIFT_CODE_TOKEN_VA(0x4D4DCDu));
    cpu->esi = cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if ((int32_t)cpu->esi <= 0) goto label_000D4E08;
    label_000D4DE0:
    cpu->edx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4DEDu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4D4DEDu));
    if (cpu->eax == 0u) goto label_000D4E01;
    cpu->esi = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4DFAu)); sfera_sub_004D1890(cpu, LIFT_CODE_TOKEN_VA(0x4D4DFAu));
    *(uint32_t*)(cpu->ebp + 0x38u) = (uint64_t)(*(uint32_t*)(cpu->ebp + 0x38u)) | (uint64_t)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    label_000D4E01:
    cpu->ebx += 2u;
    if ((int32_t)cpu->ebx < (int32_t)cpu->esi) goto label_000D4DE0;
    label_000D4E08:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"textColor");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4E19u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4E19u));
    if (cpu->eax == 0u) goto label_000D4E86;
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4D4E35u));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000D4E62;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Not enough args in 'textColor'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4E59u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D4E59u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4E5Fu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4E5Fu));
    cpu->esp += 0x14u;
    label_000D4E62:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint8_t*)(cpu->esp + 0x24u);
    { uint64_t l=cpu->ecx, r=0xFFFFFF00u, v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx <<= 8u;
    { uint64_t l=cpu->ecx, r=cpu->edx, v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx <<= 8u;
    cpu->ecx |= cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x90u) = cpu->ecx;
    label_000D4E86:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"disabledcolor");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4E93u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4E93u));
    if (cpu->eax == 0u) goto label_000D4F00;
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4D4EAFu));
    cpu->esp += 0x14u;
    if (cpu->eax == 3u) goto label_000D4EDC;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Not enough args in 'disabledColor'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4ED3u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D4ED3u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4ED9u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4ED9u));
    cpu->esp += 0x14u;
    label_000D4EDC:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint8_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x24u);
    { uint64_t l=cpu->edx, r=0xFFFFFF00u, v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx <<= 8u;
    { uint64_t l=cpu->edx, r=cpu->eax, v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx <<= 8u;
    cpu->edx |= cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0x98u) = cpu->edx;
    label_000D4F00:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"showEffect");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4F0Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4F0Du));
    if (cpu->eax == 0u) goto label_000D4F7C;
    cpu->edx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4F1Fu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4D4F1Fu));
    if (cpu->eax == 0u) goto label_000D4F7C;
    cpu->esi = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4F2Cu)); sfera_sub_004D17F0(cpu, LIFT_CODE_TOKEN_VA(0x4D4F2Cu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->ebp + 0x120u) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4F3Bu)); sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4F3Bu));
    *(float*)(cpu->ebp + 0x130u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4F4Au)); sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4F4Au));
    *(float*)(cpu->ebp + 0x134u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 3u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4F59u)); sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4F59u));
    *(float*)(cpu->ebp + 0x138u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x130u));
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000D4F7C;
    lift_x87_push(cpu, (double)0.25f);
    *(float*)(cpu->ebp + 0x130u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000D4F7C:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"hideEffect");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4F8Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D4F8Du));
    if (cpu->eax == 0u) goto label_000D4FFC;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4F9Fu)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4D4F9Fu));
    if (cpu->eax == 0u) goto label_000D4FFC;
    cpu->esi = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4FACu)); sfera_sub_004D17F0(cpu, LIFT_CODE_TOKEN_VA(0x4D4FACu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->ebp + 0x148u) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4FBBu)); sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4FBBu));
    *(float*)(cpu->ebp + 0x158u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4FCAu)); sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4FCAu));
    *(float*)(cpu->ebp + 0x15Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 3u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D4FD9u)); sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4D4FD9u));
    *(float*)(cpu->ebp + 0x160u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x158u));
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000D4FFC;
    lift_x87_push(cpu, (double)0.25f);
    *(float*)(cpu->ebp + 0x158u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000D4FFC:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebx = 1u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5015u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4D5015u));
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"control");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5026u)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x4D5026u));
    if (cpu->eax == 0u) goto label_000D5156;
    label_000D5030:
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"classID");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5041u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4D5041u));
    if (cpu->eax == 0u) goto label_000D5114;
    cpu->edx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5057u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x4D5057u));
    if (cpu->eax == 0u) goto label_000D5114;
    cpu->esi = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5068u)); sfera_sub_004D15E0(cpu, LIFT_CODE_TOKEN_VA(0x4D5068u));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0x7FFFFFFFu) goto label_000D509B;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Unknown ClassID(%s) in control %d.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5092u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D5092u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5098u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D5098u));
    cpu->esp += 0x1Cu;
    label_000D509B:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D50AFu)); sfera_sub_004D4230(cpu, LIFT_CODE_TOKEN_VA(0x4D50AFu));
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if (cpu->eax == 0u) goto label_000D5138;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xA0u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp + 0xA0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D50D6u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4D50D6u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xA4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx < 1u) goto label_000D4ADC;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xA4u) = cpu->ecx;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->edx + 0xD8u) = cpu->eax;
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    goto label_000D5138;
    label_000D5114:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> ClassID not defined in control %d.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D512Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D512Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5135u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4D5135u));
    cpu->esp += 0x18u;
    label_000D5138:
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx);
    ++cpu->ebx;
    lift_push32(cpu, (uintptr_t)"control");
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D514Eu)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x4D514Eu));
    if (cpu->eax != 0u) goto label_000D5030;
    label_000D5156:
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5162u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4D5162u));
    cpu->eax = 1u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x158u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x150u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D51A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x3Cu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    std::construct_at(reinterpret_cast<SphereUI::Window*>(cpu->esi));
    cpu->ebx = 0u;
    cpu->eax = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 8u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x54u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x84u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x80u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x70u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, 0xCu);
    *(uint8_t*)(cpu->esp + 0x48u) = 2u;
    *(uint32_t*)(cpu->esi + 0xA4u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5211u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D5211u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000D54DA;
    *(uint32_t*)(cpu->esi + 0xA0u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    lift_push32(cpu, 0xCu);
    *(uint8_t*)(cpu->esp + 0x48u) = 3u;
    *(uint32_t*)(cpu->esi + 0xB0u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D523Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D523Fu));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000D54B0;
    *(uint32_t*)(cpu->esi + 0xACu) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xACu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->ebp = cpu->esi + 0xBCu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    *(uint32_t*)(cpu->ebp) = cpu->ebx;
    lift_push32(cpu, 8u);
    *(uint8_t*)(cpu->esp + 0x48u) = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5274u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D5274u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000D5486;
    *(uint32_t*)(cpu->ebp) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    *(uint32_t*)(cpu->ebp + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18Cu) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x188u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x178u) = cpu->ebx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x48u) = 7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D52C1u)); sfera_sub_004A0A40(cpu, LIFT_CODE_TOKEN_VA(0x4D52C1u));
    *(uint8_t*)(cpu->esi + 0x4Bu) = 1u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA0u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xA4u) = cpu->ebx;
    if (cpu->ecx == *(uint32_t*)(cpu->esi + 0xA0u)) goto label_000D52FB;
    label_000D52E6:
    cpu->ebp = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D52EEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D52EEu));
    cpu->esp += 4u;
    cpu->ecx = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->esi + 0xA0u)) goto label_000D52E6;
    label_000D52FB:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->eax = *(uint32_t*)(cpu->edx + 0xA0u);
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if (cpu->ebp != cpu->eax) goto label_000D53C4;
    label_000D5313:
    if ((((*(uint8_t*)(void*)&g_sfera_control_reference_registry_guard)) & (1u)) != 0u) goto label_000D537C;
    *(uint32_t*)((uintptr_t)&g_sfera_control_reference_registry_guard) = (uint64_t)(g_sfera_control_reference_registry_guard) | (uint64_t)(1u);
    lift_push32(cpu, 0x14u);
    *(uint8_t*)(cpu->esp + 0x48u) = 8u;
    g_sfera_control_reference_registry.size = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5335u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D5335u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000D545C;
    g_sfera_control_reference_registry.sentinel = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->edx = g_sfera_control_reference_registry.sentinel;
    *(uint8_t*)(cpu->edx + 0x10u) = 1u;
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC030));
    *(uint8_t*)(cpu->eax + 0x11u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5374u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4D5374u));
    cpu->esp += 4u;
    *(uint8_t*)(cpu->esp + 0x44u) = 7u;
    label_000D537C:
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_control_reference_registry;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5390u)); sfera_sub_004D23B0(cpu, LIFT_CODE_TOKEN_VA(0x4D5390u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_control_reference_registry;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D53A0u)); sfera_sub_004D2480(cpu, LIFT_CODE_TOKEN_VA(0x4D53A0u));
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D53C0:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    label_000D53C4:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->eax == cpu->ebx) goto label_000D5422;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi + 0xA0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D53F1u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4D53F1u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx < 1u) goto label_000D5451;
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 0xA4u) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->eax + 0x9Cu) = cpu->esi;
    goto label_000D5435;
    label_000D5422:
    lift_push32(cpu, (uintptr_t)"WARNING: Can't create reference from control.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D542Cu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4D542Cu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5432u)); sfera_sub_0042E480(cpu, LIFT_CODE_TOKEN_VA(0x4D5432u));
    cpu->esp += 8u;
    label_000D5435:
    cpu->ebp = *(uint32_t*)(cpu->ebp);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->ecx + 0xA0u)) goto label_000D53C0;
    goto label_000D5313;
    label_000D5451:
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4D5451u), "std::length_error");
    label_000D545C:
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x28u;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD5486u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xD5486u));
    label_000D5486:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x28u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD54B0u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xD54B0u));
    label_000D54B0:
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x28u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD54DAu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xD54DAu));
    label_000D54DA:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x34u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5504u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4D5504u));
    lift_trap(cpu, 0x4D5504u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004D5510(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0x401u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5543u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D5543u));
    lift_push32(cpu, 0x198u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D554Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D554Du));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->eax == 0u) goto label_000D5579;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5568u)); sfera_sub_004D51A0(cpu, LIFT_CODE_TOKEN_VA(0x4D5568u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D5579:
    cpu->eax = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D5590(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_crash_report_runtime.report_length;
    if ((int32_t)cpu->eax <= (int32_t)0x1C00u) goto label_000D55C7;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.report_text[0]);
    lift_native_call(cpu, native_function_address32(&::lstrlenA), LIFT_CODE_TOKEN_VA(0x4D55A9u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.report_text[0]); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::WriteFile), LIFT_CODE_TOKEN_VA(0x4D55BAu));
    cpu->eax = 0u;
    g_sfera_crash_report_runtime.report_length = cpu->eax;
    label_000D55C7:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax + ((uintptr_t)&g_sfera_crash_report_runtime.report_text[0]);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::wvsprintfA), LIFT_CODE_TOKEN_VA(0x4D55D8u));
    g_sfera_crash_report_runtime.report_length = (uint64_t)(g_sfera_crash_report_runtime.report_length) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D55F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFEu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF0u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esp;
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->edi;
    cpu->ebx = 0u;
    if (cpu->esi != cpu->ebx) goto label_000D5690;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    lift_push32(cpu, (uintptr_t)"raising exception\r\n");
    lift_native_call(cpu, native_function_address32(&::OutputDebugStringA), LIFT_CODE_TOKEN_VA(0x4D5638u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x80000003u);
    lift_native_call(cpu, native_function_address32(&::RaiseException), LIFT_CODE_TOKEN_VA(0x4D5646u));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFEu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D5690:
    lift_push32(cpu, (uintptr_t)"writing minidump\r\n");
    lift_native_call(cpu, native_function_address32(&::OutputDebugStringA), LIFT_CODE_TOKEN_VA(0x4D5695u));
    lift_native_call(cpu, native_function_address32(&::GetCurrentThreadId), LIFT_CODE_TOKEN_VA(0x4D569Bu));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->ebx;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcessId), LIFT_CODE_TOKEN_VA(0x4D56B2u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4D56B9u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MiniDumpWriteDump), LIFT_CODE_TOKEN_VA(0x4D56C0u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D5665(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5670u)); sfera_sub_004D55F0(cpu, LIFT_CODE_TOKEN_VA(0x4D5670u));
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D5674(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFEu;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->fs_data + (0u)) = cpu->ecx;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D56E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->ecx);
    *(uint8_t*)(cpu->esi) = 0u;
    lift_native_call(cpu, native_function_address32(&::FileTimeToLocalFileTime), LIFT_CODE_TOKEN_VA(0x4D56EEu));
    if (cpu->eax == 0u) goto label_000D5756;
    cpu->edx = cpu->esp;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::FileTimeToDosDateTime), LIFT_CODE_TOKEN_VA(0x4D5706u));
    if (cpu->eax == 0u) goto label_000D5756;
    cpu->ecx = *(uint16_t*)(cpu->esp);
    cpu->eax = *(uint16_t*)(cpu->esp + 4u);
    cpu->edx = cpu->ecx;
    cpu->edx &= 0x1Fu;
    { uint64_t l=cpu->edx, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ecx;
    cpu->edx >>= 5u;
    { uint64_t l=cpu->edx, r=0x3Fu, v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    lift_push32(cpu, cpu->edx);
    cpu->ecx >>= 11u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 9u;
    cpu->edx = cpu->eax;
    cpu->ecx += 0x7BCu;
    lift_push32(cpu, cpu->ecx);
    { uint64_t l=cpu->edx, r=0x1Fu, v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    lift_push32(cpu, cpu->edx);
    cpu->eax >>= 5u;
    cpu->eax &= 0xFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%d/%d %02d:%02d:%02d"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::wsprintfA), LIFT_CODE_TOKEN_VA(0x4D574Du));
    cpu->esp += 0x20u;
    label_000D5756:
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D5760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x3F4u;
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetSystemTimeAsFileTime), LIFT_CODE_TOKEN_VA(0x4D577Au));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->esi = cpu->esp + 0xC8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5796u)); sfera_sub_004D56E0(cpu, LIFT_CODE_TOKEN_VA(0x4D5796u));
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Error occurred at %s\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D57A4u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D57A4u));
    lift_push32(cpu, 0x208u);
    cpu->ecx = cpu->esp + 0x1FCu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D57B3u));
    cpu->esp += 0x18u;
    lift_push32(cpu, 0x206u);
    cpu->edx = cpu->esp + 0x1F0u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetModuleFileNameA), LIFT_CODE_TOKEN_VA(0x4D57CAu));
    cpu->esi = native_function_address32(&::lstrcpyA);
    if (cpu->eax != 0u) goto label_000D57E9;
    lift_push32(cpu, (uintptr_t)"Unknown");
    cpu->eax = cpu->esp + 0x1F0u;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD57E9u), LIFT_CODE_TOKEN_RVA(0xD57E7u))) { return; }
    label_000D57E9:
    lift_push32(cpu, 0xC8u);
    cpu->ecx = cpu->esp + 0x128u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D57F8u));
    cpu->esp += 0xCu;
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x128u;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0xCu) = 0xC6u;
    lift_native_call(cpu, native_function_address32(&::GetUserNameA), LIFT_CODE_TOKEN_VA(0x4D5815u));
    if (cpu->eax != 0u) goto label_000D582E;
    lift_push32(cpu, (uintptr_t)"Unknown");
    cpu->ecx = cpu->esp + 0x128u;
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD582Eu), LIFT_CODE_TOKEN_RVA(0xD582Cu))) { return; }
    label_000D582E:
    cpu->edx = cpu->esp + 0x124u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x1F0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s, run by %s\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5849u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5849u));
    cpu->esp += 0x10u;
    cpu->ecx = cpu->esp + 0x8Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->esp + 0x5Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5861u)); sfera_sub_004D6300(cpu, LIFT_CODE_TOKEN_VA(0x4D5861u));
    cpu->edx = cpu->esp + 0x8Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x5Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"OS:  %s (%s)\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5879u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5879u));
    cpu->esp += 0x10u;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetSystemInfo), LIFT_CODE_TOKEN_VA(0x4D5881u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d processor(s), type %d\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D589Cu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D589Cu));
    cpu->esp += 0x10u;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x3Cu) = 0x20u;
    lift_native_call(cpu, native_function_address32(&::GlobalMemoryStatus), LIFT_CODE_TOKEN_VA(0x4D58ACu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%d%% memory in use\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D58C2u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D58C2u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    { uint64_t l=cpu->eax, r=0xFFFFFu, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax >>= 20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d MB physical memory\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D58DAu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D58DAu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x5Cu);
    { uint64_t l=cpu->ecx, r=0xFFFFFu, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx >>= 20u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d MB physical memory free\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D58F3u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D58F3u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x6Cu);
    { uint64_t l=cpu->edx, r=0xFFFFFu, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx >>= 20u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%d MB paging file\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D590Cu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D590Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x7Cu);
    { uint64_t l=cpu->eax, r=0xFFFFFu, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax >>= 20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d MB paging file free\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5924u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5924u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x8Cu);
    { uint64_t l=cpu->ecx, r=0xFFFFFu, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx >>= 20u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d MB user address space\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5940u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5940u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x9Cu);
    cpu->esp += 0x48u;
    { uint64_t l=cpu->edx, r=0xFFFFFu, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx >>= 20u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%d MB user address space free\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D595Fu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D595Fu));
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x3F4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D5980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xC4u;
    *(uint32_t*)(cpu->esp) = 0x40010005u;
    *(uint32_t*)(cpu->esp + 4u) = (uintptr_t)"a Control-C";
    *(uint32_t*)(cpu->esp + 8u) = 0x40010008u;
    *(uint32_t*)(cpu->esp + 0xCu) = (uintptr_t)"a Control-Break";
    *(uint32_t*)(cpu->esp + 0x10u) = 0x80000002u;
    *(uint32_t*)(cpu->esp + 0x14u) = (uintptr_t)"a Datatype Misalignment";
    *(uint32_t*)(cpu->esp + 0x18u) = 0x80000003u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uintptr_t)"a Breakpoint";
    *(uint32_t*)(cpu->esp + 0x20u) = 0xC0000005u;
    *(uint32_t*)(cpu->esp + 0x24u) = (uintptr_t)"an Access Violation";
    *(uint32_t*)(cpu->esp + 0x28u) = 0xC0000006u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = (uintptr_t)"an In Page Error";
    *(uint32_t*)(cpu->esp + 0x30u) = 0xC0000017u;
    *(uint32_t*)(cpu->esp + 0x34u) = (uintptr_t)"a No Memory";
    *(uint32_t*)(cpu->esp + 0x38u) = 0xC000001Du;
    *(uint32_t*)(cpu->esp + 0x3Cu) = (uintptr_t)"an Illegal Instruction";
    *(uint32_t*)(cpu->esp + 0x40u) = 0xC0000025u;
    *(uint32_t*)(cpu->esp + 0x44u) = (uintptr_t)"a Noncontinuable Exception";
    *(uint32_t*)(cpu->esp + 0x48u) = 0xC0000026u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = (uintptr_t)"an Invalid Disposition";
    *(uint32_t*)(cpu->esp + 0x50u) = 0xC000008Cu;
    *(uint32_t*)(cpu->esp + 0x54u) = (uintptr_t)"a Array Bounds Exceeded";
    *(uint32_t*)(cpu->esp + 0x58u) = 0xC000008Du;
    *(uint32_t*)(cpu->esp + 0x5Cu) = (uintptr_t)"a Float Denormal Operand";
    *(uint32_t*)(cpu->esp + 0x60u) = 0xC000008Eu;
    *(uint32_t*)(cpu->esp + 0x64u) = (uintptr_t)"a Float Divide by Zero";
    *(uint32_t*)(cpu->esp + 0x68u) = 0xC000008Fu;
    *(uint32_t*)(cpu->esp + 0x6Cu) = (uintptr_t)"a Float Inexact Result";
    *(uint32_t*)(cpu->esp + 0x70u) = 0xC0000090u;
    *(uint32_t*)(cpu->esp + 0x74u) = (uintptr_t)"a Float Invalid Operation";
    *(uint32_t*)(cpu->esp + 0x78u) = 0xC0000091u;
    *(uint32_t*)(cpu->esp + 0x7Cu) = (uintptr_t)"a Float Overflow";
    *(uint32_t*)(cpu->esp + 0x80u) = 0xC0000092u;
    *(uint32_t*)(cpu->esp + 0x84u) = (uintptr_t)"a Float Stack Check";
    *(uint32_t*)(cpu->esp + 0x88u) = 0xC0000093u;
    *(uint32_t*)(cpu->esp + 0x8Cu) = (uintptr_t)"a Float Underflow";
    *(uint32_t*)(cpu->esp + 0x90u) = 0xC0000094u;
    *(uint32_t*)(cpu->esp + 0x94u) = (uintptr_t)"an Integer Divide by Zero";
    *(uint32_t*)(cpu->esp + 0x98u) = 0xC0000095u;
    *(uint32_t*)(cpu->esp + 0x9Cu) = (uintptr_t)"an Integer Overflow";
    *(uint32_t*)(cpu->esp + 0xA0u) = 0xC0000096u;
    *(uint32_t*)(cpu->esp + 0xA4u) = (uintptr_t)"a Privileged Instruction";
    *(uint32_t*)(cpu->esp + 0xA8u) = 0xC00000FDu;
    *(uint32_t*)(cpu->esp + 0xACu) = (uintptr_t)"a Stack Overflow";
    *(uint32_t*)(cpu->esp + 0xB0u) = 0xC0000142u;
    *(uint32_t*)(cpu->esp + 0xB4u) = (uintptr_t)"a DLL Initialization Failed";
    *(uint32_t*)(cpu->esp + 0xB8u) = 0xE06D7363u;
    *(uint32_t*)(cpu->esp + 0xBCu) = (uintptr_t)"a Microsoft C++ Exception";
    cpu->eax = 0u;
    label_000D5B45:
    if (cpu->ecx == *(uint32_t*)(cpu->esp + (cpu->eax * 8u))) goto label_000D5B6A;
    ++cpu->eax;
    if (cpu->eax < 0x18u) goto label_000D5B45;
    cpu->eax = (uintptr_t)"an Unknown exception type";
    cpu->esp += 0xC4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D5B6A:
    cpu->eax = *(uint32_t*)(cpu->esp + (cpu->eax * 8u) + 4u);
    cpu->esp += 0xC4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D5B90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = cpu->eax;
    label_000D5B92:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000D5B92;
    label_000D5BA0:
    --cpu->ecx;
    if (cpu->ecx == cpu->eax) goto label_000D5BAE;
    if (*(uint8_t*)(cpu->ecx) != 0x5Cu) goto label_000D5BA0;
    cpu->eax = cpu->ecx + 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D5BAE:
    if (*(uint8_t*)(cpu->ecx) != 0x5Cu) goto label_000D5BB6;
    cpu->eax = cpu->ecx + 1u;
    label_000D5BB6:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D5BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x520u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"\r\n\r\nStack:\r\nAddress   Frame     Where\r\n"); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5BE1u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5BE1u));
    cpu->esp += 8u;
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4D5BE4u));
    lift_push32(cpu, 1u);
    cpu->ebp = 0u;
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::SymInitialize), LIFT_CODE_TOKEN_VA(0x4D5BF2u));
    if (cpu->eax != 0u) goto label_000D5C28;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x4D5BFCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"DbgHelp not initialized, code: %d\r\n"); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5C0Eu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5C0Eu));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x520u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D5C28:
    lift_push32(cpu, 0xA4u);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D5C33u));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xC4u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xB8u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->eax = 3u;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->edx;
    cpu->edx = native_function_address32(&::SymGetModuleBase);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    cpu->eax = native_function_address32(&::SymFunctionTableAccess);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xB4u);
    lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x4D5C7Fu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x14Cu);
    lift_native_call(cpu, native_function_address32(&::StackWalk), LIFT_CODE_TOKEN_VA(0x4D5C8Cu));
    if (cpu->eax == 0u) goto label_000D5DE9;
    label_000D5CA0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    if (cpu->eax == cpu->ebp) goto label_000D5DF7;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%08X  %08X  "); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5CBDu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5CBDu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->eax = 0u;
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0xDCu) = 0x458u;
    *(uint32_t*)(cpu->esp + 0x12Cu) = 0x400u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x14u;
    lift_native_call(cpu, native_function_address32(&::SymGetLineFromAddr), LIFT_CODE_TOKEN_VA(0x4D5D08u));
    if (cpu->eax == 0u) goto label_000D5D4F;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->ebp;
    label_000D5D18:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000D5D18;
    (void)cpu;
    label_000D5D20:
    --cpu->eax;
    if (cpu->eax == cpu->ebp) goto label_000D5D2D;
    if (*(uint8_t*)(cpu->eax) != 0x5Cu) goto label_000D5D20;
    ++cpu->eax;
    goto label_000D5D37;
    label_000D5D2D:
    if (*(uint8_t*)(cpu->eax) != 0x5Cu) goto label_000D5D35;
    ++cpu->eax;
    goto label_000D5D37;
    label_000D5D35:
    cpu->eax = cpu->ebp;
    label_000D5D37:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s:%u "); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5D48u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5D48u));
    cpu->esp += 0x10u;
    cpu->ebp = 0u;
    goto label_000D5D5D;
    label_000D5D4F:
    lift_push32(cpu, (uintptr_t)"Unknown:0 "); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5D5Au)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5D5Au));
    cpu->esp += 8u;
    label_000D5D5D:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = cpu->esp + 0xCCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::SymFromAddr), LIFT_CODE_TOKEN_VA(0x4D5D71u));
    if (cpu->eax == 0u) goto label_000D5D9D;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x128u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"(%hs+%I64X)"); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5D98u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5D98u));
    cpu->esp += 0x14u;
    goto label_000D5DAB;
    label_000D5D9D:
    lift_push32(cpu, (uintptr_t)"()"); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5DA8u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5DA8u));
    cpu->esp += 8u;
    label_000D5DAB:
    lift_push32(cpu, (uintptr_t)"\r\n"); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5DB6u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5DB6u));
    cpu->eax = native_function_address32(&::SymGetModuleBase);
    cpu->ecx = native_function_address32(&::SymFunctionTableAccess);
    cpu->esp += 8u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x4D5DCEu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x14Cu);
    lift_native_call(cpu, native_function_address32(&::StackWalk), LIFT_CODE_TOKEN_VA(0x4D5DDBu));
    if (cpu->eax != 0u) goto label_000D5CA0;
    label_000D5DE9:
    lift_push32(cpu, (uintptr_t)"...\r\n"); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5DF4u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5DF4u));
    cpu->esp += 8u;
    label_000D5DF7:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x520u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D5E10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, (uintptr_t)"\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5E1Bu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5E1Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xB0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"EDI:\t0x%08x\tESI:\t0x%08x\tEAX:\t0x%08x\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5E3Bu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5E3Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xACu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"EBX:\t0x%08x\tECX\t0x%08x\tEDX:\t0x%08x\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5E5Bu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5E5Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xBCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xB4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xB8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"EIP:\t0x%08x\tEBP:\t0x%08x\tSegCs:\t0x%08x\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5E7Bu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5E7Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xC8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xC0u);
    cpu->esp += 0x44u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"EFlags:\t0x%08x\tESP:\t0x%08x\tSegSs:\t0x%08x\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5E9Eu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5E9Eu));
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D5EB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp + 0xFFFFF4F8u;
    cpu->esp -= 0xB08u;
    lift_push32(cpu, 0xFFFFFFFEu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x90u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0xFFFFFFF0u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esp;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xB10u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->edi;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xB14u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u) = cpu->esi;
    if (g_sfera_crash_runtime.report_pending == 0u) goto label_000D5FB1;
    g_sfera_crash_runtime.report_pending = 0u;
    lift_push32(cpu, 0x208u); lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0x8FCu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D5F2Bu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x206u);
    cpu->ecx = cpu->ebp + 0x8FCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetModuleFileNameA), LIFT_CODE_TOKEN_VA(0x4D5F41u));
    if (cpu->eax != 0u) goto label_000D5F5D;
    lift_push32(cpu, (uintptr_t)"Unknown");
    cpu->edx = cpu->ebp + 0x8FCu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::lstrcpyA), LIFT_CODE_TOKEN_RVA(0xD5F57u));
    label_000D5F5D:
    cpu->eax = cpu->ebp + 0x8FCu;
    label_000D5F63:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000D5F63;
    label_000D5F70:
    --cpu->eax;
    cpu->edx = cpu->ebp + 0x8FCu;
    if (cpu->eax == cpu->edx) goto label_000D5F80;
    if (*(uint8_t*)(cpu->eax) != 0x5Cu) goto label_000D5F70;
    label_000D5F80:
    if (*(uint8_t*)(cpu->eax) != 0x5Cu) goto label_000D5F88;
    ++cpu->eax;
    goto label_000D5F8E;
    label_000D5F88:
    cpu->eax = cpu->ebp + 0x8FCu;
    label_000D5F8E:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u) = cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ebp + 0x3E8u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::lstrcpyA), LIFT_CODE_TOKEN_VA(0x4D5F99u));
    if (cpu->esi != 0u) goto label_000D5FB8;
    lift_push32(cpu, (uintptr_t)"pExceptPtrs == NULL"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5FAEu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5FAEu));
    cpu->esp += 8u;
    label_000D5FB1:
    cpu->eax = 0u;
    goto label_000D62DD;
    label_000D5FB8:
    cpu->ebx = *(uint32_t*)(cpu->esi);
    if (cpu->ebx != 0u) goto label_000D5FCC;
    lift_push32(cpu, (uintptr_t)"Exception == NULL"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5FC9u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5FC9u));
    cpu->esp += 8u;
    label_000D5FCC:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esi;
    if (cpu->esi != 0u) goto label_000D5FE4;
    lift_push32(cpu, (uintptr_t)"Context == NULL"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D5FE1u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D5FE1u));
    cpu->esp += 8u;
    label_000D5FE4:
    lift_push32(cpu, 0x208u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0x5F0u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D5FF2u));
    cpu->esp += 0xCu;
    cpu->edi = (uintptr_t)"Unknown";
    lift_push32(cpu, 0x1Cu);
    cpu->edx = cpu->ebp + 0xFFFFFF60u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xB8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::VirtualQuery), LIFT_CODE_TOKEN_VA(0x4D600Fu));
    if (cpu->eax == 0u) goto label_000D6043;
    lift_push32(cpu, 0x206u);
    cpu->ecx = cpu->ebp + 0x5F0u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFF64u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetModuleFileNameA), LIFT_CODE_TOKEN_VA(0x4D602Cu));
    if (cpu->eax == 0u) goto label_000D6043;
    cpu->eax = cpu->ebp + 0x5F0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6041u)); sfera_sub_004D5B90(cpu, LIFT_CODE_TOKEN_VA(0x4D6041u));
    cpu->edi = cpu->eax;
    label_000D6043:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xB8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xBCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D605Au)); sfera_sub_004D5980(cpu, LIFT_CODE_TOKEN_VA(0x4D605Au));
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ebp + 0x3E8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s caused %s (0x%08x) \r\nin %s at %04x:%08x\r\n\r\n");
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6070u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D6070u));
    cpu->esp += 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6078u)); sfera_sub_004D5760(cpu, LIFT_CODE_TOKEN_VA(0x4D6078u));
    if (*(uint32_t*)(cpu->ebx) != 0xC0000005u) goto label_000D60BE;
    if (*(uint32_t*)(cpu->ebx + 0x10u) < 2u) goto label_000D60BE;
    cpu->eax = (uintptr_t)"Read from";
    if (*(uint32_t*)(cpu->ebx + 0x14u) == 0u) goto label_000D6096;
    cpu->eax = (uintptr_t)"Write to";
    label_000D6096:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s location %08x caused an access violation\r\n");
    cpu->edx = cpu->ebp;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::wsprintfA), LIFT_CODE_TOKEN_VA(0x4D60A4u));
    cpu->eax = cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D60BBu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D60BBu));
    cpu->esp += 0x1Cu;
    label_000D60BE:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D60C3u)); sfera_sub_004D5E10(cpu, LIFT_CODE_TOKEN_VA(0x4D60C3u));
    lift_push32(cpu, (uintptr_t)"\r\nBytes at CS:EIP:\r\n"); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D60CEu)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D60CEu));
    cpu->esp += 8u;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xB8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->edx;
    cpu->ebx = 0u;
    cpu->edi = cpu->ebx + 0xFFFFFFFEu;
    label_000D60DF:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->ebx;
    if ((int32_t)cpu->ebx >= (int32_t)0x10u) goto label_000D6138;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx = *(uint8_t*)(cpu->ebx + cpu->eax);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%02x ");
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6104u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D6104u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edi;
    ++cpu->ebx;
    goto label_000D60DF;
    label_000D6138:
    cpu->ebx = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6142u)); sfera_sub_004D5BC0(cpu, LIFT_CODE_TOKEN_VA(0x4D6142u));
    lift_push32(cpu, (uintptr_t)"ERRORLOG.TXT"); lift_push32(cpu, (uintptr_t)"\r\n===== [end of %s] =====\r\n"); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6152u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D6152u));
    cpu->esp += 0xCu;
    if ((int32_t)g_sfera_crash_report_runtime.report_length <= (int32_t)0u) goto label_000D6186;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.report_text[0]);
    lift_native_call(cpu, native_function_address32(&::lstrlenA), LIFT_CODE_TOKEN_VA(0x4D6169u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.report_text[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::WriteFile), LIFT_CODE_TOKEN_VA(0x4D6176u));
    g_sfera_crash_report_runtime.report_length = 0u;
    label_000D6186:
    lift_push32(cpu, (uintptr_t)"CRASH.DMP");
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u);
    lift_push32(cpu, cpu->ebx);
    cpu->edi = native_function_address32(&::lstrcpyA);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD6197u), LIFT_CODE_TOKEN_RVA(0xD6195u))) { return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0x80000080u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x40000000u);
    cpu->edx = cpu->ebp + 0x8FCu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x4D61B0u));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0xFFFFFFFFu) goto label_000D61CE;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D61C7u)); sfera_sub_004D55F0(cpu, LIFT_CODE_TOKEN_VA(0x4D61C7u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0xD61C8u));
    label_000D61CE:
    lift_native_call(cpu, native_function_address32(&::IsDebuggerPresent), LIFT_CODE_TOKEN_VA(0x4D61CEu));
    if (cpu->eax != 0u) goto label_000D5FB1;
    lift_push32(cpu, (uintptr_t)"CrashReport.exe"); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD61E4u), LIFT_CODE_TOKEN_RVA(0xD61E2u))) { return; }
    cpu->eax = cpu->ebp + 0x8FCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x7F8u;
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD61F4u), LIFT_CODE_TOKEN_RVA(0xD61F2u))) { return; }
    lift_push32(cpu, (uintptr_t)" \"");
    cpu->edx = cpu->ebp + 0x7F8u;
    lift_push32(cpu, cpu->edx);
    cpu->esi = native_function_address32(&::lstrcatA);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD6208u), LIFT_CODE_TOKEN_RVA(0xD6206u))) { return; }
    lift_push32(cpu, 0x208u); lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0x8FCu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D6216u));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x206u);
    cpu->ecx = cpu->ebp + 0x8FCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetModuleFileNameA), LIFT_CODE_TOKEN_VA(0x4D622Cu));
    cpu->eax = cpu->ebp + 0x8FCu;
    label_000D6238:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000D6238;
    (void)cpu;
    label_000D6240:
    --cpu->eax;
    cpu->ecx = cpu->ebp + 0x8FCu;
    if (cpu->eax == cpu->ecx) goto label_000D6250;
    if (*(uint8_t*)(cpu->eax) != 0x5Cu) goto label_000D6240;
    label_000D6250:
    if (*(uint8_t*)(cpu->eax) != 0x5Cu) goto label_000D6258;
    ++cpu->eax;
    goto label_000D625E;
    label_000D6258:
    cpu->eax = cpu->ebp + 0x8FCu;
    label_000D625E:
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebp + 0x7F8u;
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD6268u), LIFT_CODE_TOKEN_RVA(0xD6266u))) { return; }
    lift_push32(cpu, (uintptr_t)"\"");
    cpu->eax = cpu->ebp + 0x7F8u;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD6276u), LIFT_CODE_TOKEN_RVA(0xD6274u))) { return; }
    lift_push32(cpu, 0x44u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D6281u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFF7Cu) = 0x44u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFA8u) = 1u;
    cpu->edx = 5u;
    *(uint16_t*)(cpu->ebp + 0xFFFFFFACu) = cpu->edx & 0xFFFFu;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) = cpu->eax;
    cpu->eax = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0x7F8u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateProcessA), LIFT_CODE_TOKEN_VA(0x4D62D1u));
    { uint64_t x=cpu->eax, v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    label_000D62DD:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp + 0xB08u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D610D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D6113(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000D6113;
    label_000D5FB1:
    cpu->eax = 0u;
    goto label_000D62DD;
    label_000D60DF:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->ebx;
    if ((int32_t)cpu->ebx >= (int32_t)0x10u) goto label_000D6138;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx = *(uint8_t*)(cpu->ebx + cpu->eax);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%02x ");
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6104u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D6104u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edi;
    ++cpu->ebx;
    goto label_000D60DF;
    label_000D6113:
    cpu->esp = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, (uintptr_t)"\077\077 ");
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6124u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D6124u));
    cpu->esp += 8u;
    cpu->edi = 0xFFFFFFFEu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->edi;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    ++cpu->ebx;
    goto label_000D60DF;
    label_000D6138:
    cpu->ebx = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6142u)); sfera_sub_004D5BC0(cpu, LIFT_CODE_TOKEN_VA(0x4D6142u));
    lift_push32(cpu, (uintptr_t)"ERRORLOG.TXT"); lift_push32(cpu, (uintptr_t)"\r\n===== [end of %s] =====\r\n"); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6152u)); sfera_sub_004D5590(cpu, LIFT_CODE_TOKEN_VA(0x4D6152u));
    cpu->esp += 0xCu;
    if ((int32_t)g_sfera_crash_report_runtime.report_length <= (int32_t)0u) goto label_000D6186;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFDCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.report_text[0]);
    lift_native_call(cpu, native_function_address32(&::lstrlenA), LIFT_CODE_TOKEN_VA(0x4D6169u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.report_text[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::WriteFile), LIFT_CODE_TOKEN_VA(0x4D6176u));
    g_sfera_crash_report_runtime.report_length = 0u;
    label_000D6186:
    lift_push32(cpu, (uintptr_t)"CRASH.DMP");
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD0u);
    lift_push32(cpu, cpu->ebx);
    cpu->edi = native_function_address32(&::lstrcpyA);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD6197u), LIFT_CODE_TOKEN_RVA(0xD6195u))) { return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0x80000080u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x40000000u);
    cpu->edx = cpu->ebp + 0x8FCu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x4D61B0u));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0xFFFFFFFFu) goto label_000D61CE;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D61C7u)); sfera_sub_004D55F0(cpu, LIFT_CODE_TOKEN_VA(0x4D61C7u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0xD61C8u));
    label_000D61CE:
    lift_native_call(cpu, native_function_address32(&::IsDebuggerPresent), LIFT_CODE_TOKEN_VA(0x4D61CEu));
    if (cpu->eax != 0u) goto label_000D5FB1;
    lift_push32(cpu, (uintptr_t)"CrashReport.exe"); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD61E4u), LIFT_CODE_TOKEN_RVA(0xD61E2u))) { return; }
    cpu->eax = cpu->ebp + 0x8FCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x7F8u;
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0xD61F4u), LIFT_CODE_TOKEN_RVA(0xD61F2u))) { return; }
    lift_push32(cpu, (uintptr_t)" \"");
    cpu->edx = cpu->ebp + 0x7F8u;
    lift_push32(cpu, cpu->edx);
    cpu->esi = native_function_address32(&::lstrcatA);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD6208u), LIFT_CODE_TOKEN_RVA(0xD6206u))) { return; }
    lift_push32(cpu, 0x208u); lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0x8FCu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D6216u));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x206u);
    cpu->ecx = cpu->ebp + 0x8FCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetModuleFileNameA), LIFT_CODE_TOKEN_VA(0x4D622Cu));
    cpu->eax = cpu->ebp + 0x8FCu;
    label_000D6238:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000D6238;
    (void)cpu;
    label_000D6240:
    --cpu->eax;
    cpu->ecx = cpu->ebp + 0x8FCu;
    if (cpu->eax == cpu->ecx) goto label_000D6250;
    if (*(uint8_t*)(cpu->eax) != 0x5Cu) goto label_000D6240;
    label_000D6250:
    if (*(uint8_t*)(cpu->eax) != 0x5Cu) goto label_000D6258;
    ++cpu->eax;
    goto label_000D625E;
    label_000D6258:
    cpu->eax = cpu->ebp + 0x8FCu;
    label_000D625E:
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebp + 0x7F8u;
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD6268u), LIFT_CODE_TOKEN_RVA(0xD6266u))) { return; }
    lift_push32(cpu, (uintptr_t)"\"");
    cpu->eax = cpu->ebp + 0x7F8u;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0xD6276u), LIFT_CODE_TOKEN_RVA(0xD6274u))) { return; }
    lift_push32(cpu, 0x44u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D6281u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFF7Cu) = 0x44u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFA8u) = 1u;
    cpu->edx = 5u;
    *(uint16_t*)(cpu->ebp + 0xFFFFFFACu) = cpu->edx & 0xFFFFu;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC0u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC4u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu) = cpu->eax;
    cpu->eax = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFF7Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0x7F8u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateProcessA), LIFT_CODE_TOKEN_VA(0x4D62D1u));
    { uint64_t x=cpu->eax, v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    label_000D62DD:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    *(uint32_t*)(cpu->fs_data + (0u)) = cpu->ecx;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp + 0xB08u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D6300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xA8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->esi == 0u) goto label_000D65A7;
    if (cpu->edi == 0u) goto label_000D65A7;
    if (cpu->eax == 0u) goto label_000D65A7;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::lstrcpyA);
    lift_push32(cpu, (uintptr_t)"unknown Windows version"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD634Cu), LIFT_CODE_TOKEN_RVA(0xD634Au))) { return; }
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->edi) = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x94u;
    lift_native_call(cpu, native_function_address32(&::GetVersionExA), LIFT_CODE_TOKEN_VA(0x4D635Fu));
    if (cpu->eax != 0u) goto label_000D6383;
    label_000D6369:
    cpu->ebx = lift_pop32(cpu);
    label_000D636A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xA8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D6383:
    cpu->edx = *(uint16_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, (uintptr_t)"%u.%u.%u"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::wsprintfA), LIFT_CODE_TOKEN_VA(0x4D63AEu));
    cpu->esp += 0x14u;
    if (cpu->ebp != 1u) goto label_000D64CA;
    if (*(uint32_t*)(cpu->esp + 0x14u) != 4u) goto label_000D659C;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    { uint64_t l=cpu->ecx, r=0xAu, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000D643B;
    if (cpu->eax != 0x3B6u) goto label_000D63F1;
    lift_push32(cpu, (uintptr_t)"Windows 95"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD63E7u), LIFT_CODE_TOKEN_RVA(0xD63E5u))) { return; }
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D63F1:
    cpu->edx = cpu->eax + 0xFFFFFC49u;
    if (cpu->edx > 0x81u) goto label_000D6418;
    lift_push32(cpu, (uintptr_t)"Windows 95 SP1"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD6407u), LIFT_CODE_TOKEN_RVA(0xD6405u))) { return; }
    *(uint32_t*)(cpu->edi) = 2u;
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D6418:
    if (cpu->eax <= 0x438u) goto label_000D6438;
    lift_push32(cpu, (uintptr_t)"Windows 95 OSR2"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD6427u), LIFT_CODE_TOKEN_RVA(0xD6425u))) { return; }
    *(uint32_t*)(cpu->edi) = 3u;
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D6438:
    { uint64_t l=cpu->ecx, r=0xAu, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_000D643B:
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D64A8;
    if (cpu->eax != 0x7CEu) goto label_000D645D;
    lift_push32(cpu, (uintptr_t)"Windows 98"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD644Cu), LIFT_CODE_TOKEN_RVA(0xD644Au))) { return; }
    *(uint32_t*)(cpu->edi) = 4u;
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D645D:
    cpu->ecx = cpu->eax + 0xFFFFF831u;
    if (cpu->ecx > 0xB7u) goto label_000D6484;
    lift_push32(cpu, (uintptr_t)"Windows 98 SP1"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD6473u), LIFT_CODE_TOKEN_RVA(0xD6471u))) { return; }
    *(uint32_t*)(cpu->edi) = 5u;
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D6484:
    if (cpu->eax < 0x887u) goto label_000D659C;
    lift_push32(cpu, (uintptr_t)"Windows 98 SE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD6497u), LIFT_CODE_TOKEN_RVA(0xD6495u))) { return; }
    *(uint32_t*)(cpu->edi) = 6u;
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D64A8:
    if (cpu->ecx != 0x5Au) goto label_000D659C;
    lift_push32(cpu, (uintptr_t)"Windows ME"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD64B9u), LIFT_CODE_TOKEN_RVA(0xD64B7u))) { return; }
    *(uint32_t*)(cpu->edi) = 7u;
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D64CA:
    if (cpu->ebp != 2u) goto label_000D6589;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax != 3u) goto label_000D64FE;
    if (*(uint32_t*)(cpu->esp + 0x10u) != 0x33u) goto label_000D659C;
    lift_push32(cpu, (uintptr_t)"Windows NT 3.51"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD64EFu), LIFT_CODE_TOKEN_RVA(0xD64EDu))) { return; }
    cpu->eax = cpu->ebp + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->edi) = 0x65u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D64FE:
    if (cpu->eax != 4u) goto label_000D6527;
    if (*(uint32_t*)(cpu->esp + 0x10u) != 0u) goto label_000D659C;
    lift_push32(cpu, (uintptr_t)"Windows NT 4"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD6516u), LIFT_CODE_TOKEN_RVA(0xD6514u))) { return; }
    *(uint32_t*)(cpu->edi) = 0x66u;
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D6527:
    if (cpu->eax != 5u) goto label_000D659C;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax != 0u) goto label_000D654D;
    lift_push32(cpu, (uintptr_t)"Windows 2000"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD653Cu), LIFT_CODE_TOKEN_RVA(0xD653Au))) { return; }
    *(uint32_t*)(cpu->edi) = 0x67u;
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D654D:
    if (cpu->eax != 1u) goto label_000D656B;
    lift_push32(cpu, (uintptr_t)"Windows XP"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD655Au), LIFT_CODE_TOKEN_RVA(0xD6558u))) { return; }
    *(uint32_t*)(cpu->edi) = 0x68u;
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D656B:
    if (cpu->eax != 2u) goto label_000D659C;
    lift_push32(cpu, (uintptr_t)"Windows 2003 Server"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD6578u), LIFT_CODE_TOKEN_RVA(0xD6576u))) { return; }
    *(uint32_t*)(cpu->edi) = 0x69u;
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D6589:
    if (cpu->ebp != 3u) goto label_000D659C;
    lift_push32(cpu, (uintptr_t)"Windows CE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0xD6596u), LIFT_CODE_TOKEN_RVA(0xD6594u))) { return; }
    *(uint32_t*)(cpu->edi) = 0xC9u;
    label_000D659C:
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D65A7:
    cpu->eax = 0u;
    goto label_000D636A;
}
__declspec(noinline) void sfera_sub_004D65B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x3ECu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x3F4u);
    cpu->edx = 0x3E8u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D65DAu)); sfera_sub_0044BFE0(cpu, LIFT_CODE_TOKEN_VA(0x4D65DAu));
    cpu->ecx = (uintptr_t)"Exception!\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D65E4u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D65E4u));
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D65EDu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D65EDu));
    cpu->ecx = (uintptr_t)"  ";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D65F7u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D65F7u));
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4D65FCu));
    cpu->esp += 4u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D660Eu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D660Eu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6613u)); sfera_sub_00451DC0(cpu, LIFT_CODE_TOKEN_VA(0x4D6613u));
    cpu->ecx = (uintptr_t)"End of exception\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D661Du)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D661Du));
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6627u)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x4D6627u));
    cpu->ecx = (uintptr_t)"End of warning flush\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6631u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D6631u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0x80000000u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x40000000u); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0]);
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x4D6648u));
    g_sfera_crash_report_runtime.error_log_handle = cpu->eax;
    if (cpu->eax == 0xFFFFFFFFu) goto label_000D66E4;
    cpu->ecx = (uintptr_t)"Writing  ";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6666u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D6666u));
    cpu->ecx = (uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6670u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D6670u));
    cpu->ecx = (uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D667Au)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D667Au));
    cpu->ecx = g_sfera_crash_report_runtime.error_log_handle;
    lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SetFilePointer), LIFT_CODE_TOKEN_VA(0x4D6687u));
    cpu->edx = g_sfera_crash_report_runtime.error_log_handle;
    lift_push32(cpu, (uintptr_t)"start"); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D669Fu)); sfera_sub_004D5EB0(cpu, LIFT_CODE_TOKEN_VA(0x4D669Fu));
    cpu->esi = cpu->eax;
    cpu->eax = g_sfera_crash_report_runtime.error_log_handle;
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x4D66AAu));
    g_sfera_crash_report_runtime.error_log_handle = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D66BFu)); sfera_sub_00434D90(cpu, LIFT_CODE_TOKEN_VA(0x4D66BFu));
    if (cpu->eax == 0u) goto label_000D66CA;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD66CAu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_RVA(0xD66CAu));
    label_000D66CA:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x3ECu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D66E4:
    cpu->ecx = (uintptr_t)"Could not open  ";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D66EEu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D66EEu));
    cpu->ecx = (uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D66F8u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D66F8u));
    cpu->ecx = (uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6702u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D6702u));
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x3ECu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

} // namespace lifted
