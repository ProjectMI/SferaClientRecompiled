#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CD0D0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000CD0D0;
    label_000CA300: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA300u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"sound_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA30Du); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000CA49F;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CA445;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA324u); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"sound_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA334u); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000CA445;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebx + 0xF8u, LIFT_CALLBACK(sfera_sub_004CA180));
    lift_native_call(cpu, native_function_address32(&SI_GetStreamVolume), LIFT_CODE_TOKEN_VA(0x4CA34Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA34Fu);
    g_sfera_sphere_options_runtime.saved_music_volume = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA359u); lift_push32(cpu, r); sfera_sub_00497980(cpu,r); if (cpu->eip != r) return; }
    g_sfera_options_dialog_runtime.audio_settings = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, 0u); lift_push32(cpu, 0x9C6u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA398u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, 0u); lift_push32(cpu, 0x9C6u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA3AAu);
    cpu->eax = g_sfera_sphere_options_runtime.saved_music_volume;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x9C5u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA3C0u);
    cpu->ecx = g_sfera_options_dialog_runtime.audio_settings;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x9C5u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA3D7u);
    lift_native_call(cpu, native_function_address32(&SI_GetHardwareMixing), LIFT_CODE_TOKEN_VA(0x4CA3D7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA3DDu);
    cpu->eax = cpu->eax & 0xFFu;
    g_sfera_graphics_options_runtime.graphics_values[7] = (uint32_t)(cpu->eax);
    g_sfera_graphics_options_runtime.graphics_values[12] = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CA447;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT33";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA3F8u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA402;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA404;
    label_000CA402: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA402u);
    cpu->ecx = cpu->eax;
    label_000CA404: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA404u);
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA42A;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CA42A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA42Au);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000CA430: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA430u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CA430;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA443u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000CA445: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA445u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CA447: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA447u);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT34";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA451u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA45B;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA45D;
    label_000CA45B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA45Bu);
    cpu->ecx = cpu->eax;
    label_000CA45D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA45Du);
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->edx = cpu->ecx;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA483;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CA483: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA483u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CA488: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA488u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CA488;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA49Bu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CA49F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA49Fu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CA445;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA4AFu); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_sphere_options_runtime.saved_music_volume;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA4BAu); lift_push32(cpu, r); sfera_sub_004982F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_options_dialog_runtime.audio_settings;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA4C5u); lift_push32(cpu, r); sfera_sub_00497B60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA4CCu); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_graphics_options_runtime.graphics_values[7]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&SI_SetHardwareMixing), LIFT_CODE_TOKEN_VA(0x4CA4DAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA4E0u);
    cpu->esp += 4u;
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA4EDu); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_options_dialog_runtime.audio_settings;
    cpu->ecx = (uint32_t)(uintptr_t)"SNDVOL";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA4FDu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_sphere_options_runtime.saved_music_volume;
    cpu->ecx = (uint32_t)(uintptr_t)"MUSVOL";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA50Du); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_options_runtime.graphics_values[7];
    cpu->ecx = (uint32_t)(uintptr_t)"HWMIX";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA51Du); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_00448490(cpu, stop_address); return;
    label_000CA890: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA890u);
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(uintptr_t)"control_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA8ADu); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000CAB0E;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CABB6;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA8C4u); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"control_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA8D4u); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000CABB6;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x100u); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_control_options.configured_bindings[0]);
    lift_store32(cpu->ebx + 0xF8u, LIFT_CALLBACK(sfera_sub_004CA530));
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4CA8F5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA8FAu);
    cpu->esp += 0xCu;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS_NUMBER";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA909u); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    cpu->esi = 0u;
    label_000CA911: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA911u);
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA91Du); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA924u); lift_push32(cpu, r); sfera_sub_004BEBA0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.configured_bindings[0]), cpu->eax);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(5u)) goto label_000CA911;
    cpu->esi = 5u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000CA958;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000CA940: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA940u);
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA94Cu); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.configured_bindings[0]), cpu->eax);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000CA940;
    label_000CA958: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA958u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"INMS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA964u); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0x40u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_control_options.configured_bindings[0];
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_control_options.working_bindings[0];
    g_sfera_control_options.configured_bindings[63] = (uint32_t)(cpu->eax);
    lift_movs32(cpu, 1u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CA9BC;
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT23";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA988u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA992;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA994;
    label_000CA992: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA992u);
    cpu->ecx = cpu->eax;
    label_000CA994: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA994u);
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA9AE;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CA9AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9AEu);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CA9B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9B3u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CA9B3;
    goto label_000CA9F8;
    label_000CA9BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9BCu);
    cpu->ecx = (uint32_t)(uintptr_t)"UISTR_WT_OPT24";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CA9C6u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CA9D0;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000CA9D2;
    label_000CA9D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9D0u);
    cpu->ecx = cpu->eax;
    label_000CA9D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9D2u);
    cpu->edx = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->edx);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000CA9EC;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CA9EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9ECu);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CA9F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9F1u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CA9F1;
    label_000CA9F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CA9F8u);
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAA04u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_000CAAF1;
    goto label_000CAA2B;
    label_000CAA27: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA27u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    label_000CAA2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA2Bu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0xFA2u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA3Du);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAA46u); lift_push32(cpu, r); sfera_sub_004B8750(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"UISTR_WT_KEY%02u"); lift_push32(cpu, (uintptr_t)&g_sfera_options_dialog_runtime.widget_key_name[0]);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4CAA5Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA60u);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.widget_key_name[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAA6Du); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CAA75;
    cpu->eax = lift_load32(cpu->eax);
    label_000CAA75: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA75u);
    cpu->ecx = lift_load32(cpu->edi + 0xA0u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->edx);
    cpu->ebx = lift_load32(cpu->edx + 8u);
    cpu->ecx = cpu->eax;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CAA8D;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_000CAA8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA8Du);
    cpu->eax = cpu->ecx;
    cpu->ebp = (uint32_t)(cpu->eax + 1u);
    label_000CAA92: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAA92u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CAA92;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAAA5u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.configured_bindings[0]));
    cpu->edi = lift_load32(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAAC0u); lift_push32(cpu, r); sfera_sub_004BEC00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CAACB;
    cpu->edx = (uint32_t)(uintptr_t)"";
    label_000CAACB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAACBu);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000CAAD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAAD0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CAAD0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAAE3u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000CAA27;
    label_000CAAF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAAF1u);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    g_sfera_options_dialog_runtime.widget_keys_initialized = (uint32_t)(1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_000CAB0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAB0Eu);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000CABB6;
    cpu->edx = (uint32_t)(cpu->ebx + 1u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB22u); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB29u); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_control_options.configured_bindings[63];
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(uintptr_t)"INMS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB3Au); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CAB40: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAB40u);
    cpu->ecx = lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.configured_bindings[0]));
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB4Du); lift_push32(cpu, r); sfera_sub_004BEB80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB59u); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(5u)) goto label_000CAB40;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS_NUMBER";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB6Bu); lift_push32(cpu, r); sfera_sub_00437F60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->esi = 5u;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000CAB97;
    label_000CAB80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAB80u);
    cpu->edx = lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_control_options.configured_bindings[0]));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"SSKS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CAB92u); lift_push32(cpu, r); sfera_sub_00437E20(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->edi)) goto label_000CAB80;
    label_000CAB97: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CAB97u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x20u, 0x10u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CABB0u); lift_push32(cpu, r); sfera_sub_004BA680(cpu,r); if (cpu->eip != r) return; }
    g_sfera_options_dialog_runtime.widget_keys_initialized = (uint32_t)(cpu->ebx);
    label_000CABB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CABB6u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_000CD0D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD0D0u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x64u)) goto label_000CD179;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x3E9u)) goto label_000CD144;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->eax += 0xFFFFFFFDu;
    if ((uint32_t)(cpu->eax) > (uint32_t)(5u)) goto label_000CD144;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000CD0F5;
        case 1u: goto label_000CD0FC;
        case 2u: goto label_000CD103;
        case 3u: goto label_000CD10A;
        case 4u: goto label_000CD111;
        case 5u: goto label_000CD145;
        default: lift_trap(cpu, 0x4CD0EEu, "resolved jump-table index out of range"); return;
    }
label_000CD0F5: ;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    sfera_sub_004CC280(cpu, stop_address); return;
    label_000CD0FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD0FCu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    goto label_000CA300;
    label_000CD103: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD103u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    goto label_000CA890;
    label_000CD10A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD10Au);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    sfera_sub_004CB100(cpu, stop_address); return;
    label_000CD111: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD111u);
    cpu->ecx = (uint32_t)(uintptr_t)"authors";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD11Bu); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CD144;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD126u); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"authors";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD136u); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD144;
    lift_store32(cpu->eax + 0xF8u, LIFT_CALLBACK(sfera_sub_004C9C30));
    label_000CD144: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD144u);
    lift_return(cpu, 0u, stop_address); return;
    label_000CD145: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD145u);
    cpu->ecx = (uint32_t)(uintptr_t)"quit";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD14Fu); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CD144;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD15Au); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"quit";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD16Au); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD144;
    lift_store32(cpu->eax + 0xF8u, LIFT_CALLBACK(sfera_sub_004C9C40));
    lift_return(cpu, 0u, stop_address); return;
    label_000CD179: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD179u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    sfera_sub_004CD1A0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CD1A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD1A0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD1ADu); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)((cpu->ebx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CD1D3;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CD1D2;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD1C4u); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD1D2;
    lift_store32(cpu->eax + 0xF8u, LIFT_CALLBACK(sfera_sub_004CD0D0));
    label_000CD1D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD1D2u);
    lift_return(cpu, 0u, stop_address); return;
    label_000CD1D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD1D3u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD1D2;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    sfera_sub_004B8700(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CD1F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD1F0u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x64u)) goto label_000CD24B;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x3E9u)) goto label_000CD229;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x1DE4u)) goto label_000CD21D;
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CD21E;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CD21D;
    cpu->eax = lift_load32(cpu->edx + 0xCu);
    cpu->ecx = g_sfera_options_dialog_runtime.chat_edit_fonts.begin;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    label_000CD21D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD21Du);
    lift_return(cpu, 0u, stop_address); return;
    label_000CD21E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD21Eu);
    cpu->edx = lift_load32(cpu->edx + 0xCu);
    cpu->eax = g_sfera_options_dialog_runtime.chat_edit_fonts.begin;
    lift_store32(cpu->eax, cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
    label_000CD229: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD229u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CD233;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CD24B;
    lift_return(cpu, 0u, stop_address); return;
    label_000CD233: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD233u);
    cpu->ecx = g_sfera_options_dialog_runtime.chat_edit_fonts.end;
    cpu->edx = g_sfera_options_dialog_runtime.chat_edit_fonts.begin;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCD24Bu); lift_push32(cpu, r); sfera_sub_004AB160(cpu,r); if (cpu->eip != r) return; }
    label_000CD24B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD24Bu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD260u);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"font_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD27Cu); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000CD3AD;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CD410;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD293u); lift_push32(cpu, r); sfera_sub_004CB100(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD29Du); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD2AD;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCD2ADu); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    label_000CD2AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD2ADu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"font_options";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD2BDu); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000CD410;
    lift_push32(cpu, 2u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    lift_store32(cpu->esi + 0xF8u, LIFT_CALLBACK(sfera_sub_004CD1F0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD2DDu); lift_push32(cpu, r); sfera_sub_00429830(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 2u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.chat_edit_fonts;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD2E9u); lift_push32(cpu, r); sfera_sub_00429830(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    lift_store32(cpu->esp + 0xCu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD300u); lift_push32(cpu, r); sfera_sub_004BDF90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.chat_list_fonts;
    lift_store32(cpu->esp + 0xCu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD317u); lift_push32(cpu, r); sfera_sub_004BDF90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD321u); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->ecx = (uint32_t)(uintptr_t)"CHAT_LIST_FONT";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD331u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx += 4u;
    cpu->ecx = (uint32_t)(uintptr_t)"CHAT_EDIT_FONT";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD344u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->eax = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD362u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setFont(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD384u);
    cpu->ecx = g_sfera_options_dialog_runtime.chat_list_fonts.end;
    cpu->edx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.chat_edit_fonts;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD39Cu); lift_push32(cpu, r); sfera_sub_004AB160(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_000CD3AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD3ADu);
    cpu->esi = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000CD410;
    cpu->edx = (uint32_t)(cpu->esi + 1u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD3BDu); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD3C4u); lift_push32(cpu, r); sfera_sub_004CB100(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD3CEu); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)"CHAT_LIST_FONT";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD3DFu); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = (uint32_t)(uintptr_t)"CHAT_EDIT_FONT";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD3F2u); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD3F7u); lift_push32(cpu, r); sfera_sub_00448490(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x14u, 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCD410u); lift_push32(cpu, r); sfera_sub_004BA680(cpu,r); if (cpu->eip != r) return; }
    label_000CD410: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD410u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CD430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD430u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD438u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x1A0u, cpu->eax);
    lift_store16(cpu->esi + 0x1BCu, cpu->eax & 0xFFFFu);
    cpu->eax = 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    lift_store8(cpu->esi + 0x1BEu, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x1B0u, cpu->eax);
    std::construct_at(reinterpret_cast<SphereUI::SpinButton*>(cpu->esi));
    lift_store32(cpu->esi + 0x1B8u, cpu->ecx);
    lift_store32(cpu->esi + 0x50u, 0x10u);
    lift_store32(cpu->esi + 0x1A4u, 0x64u);
    lift_store32(cpu->esi + 0x1ACu, cpu->ecx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CD4A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD4A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::SpinButton*>(cpu->esi));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x198u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CD501;
    cpu->edx = 0x4Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\SpinCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD4EEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000CD501;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000CD501: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD501u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x19Cu)) == (uint32_t)(0u)) goto label_000CD52C;
    cpu->edx = 0x50u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\SpinCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD519u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000CD52C;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000CD52C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD52Cu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD53Bu); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CD550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD550u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD567u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x9Cu)) != (uint32_t)(0u)) goto label_000CD58A;
    lift_push32(cpu, 0x60u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\SpinCtrl.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD581u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD587u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000CD58A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD58Au);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"defButtonStyle");
    cpu->ecx = cpu->edi;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD59Fu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD5B1;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD5ACu); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    label_000CD5B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD5B1u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"leftbutton");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD5C5u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD610;
    lift_push32(cpu, 1u); lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD5DFu); lift_push32(cpu, r); sfera_sub_004D4230(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD5EDu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000CD610;
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    lift_x87_push(cpu, (double)0.15000000596046448f);
    lift_store32(cpu->eax + 0x1A8u, (uint64_t)(lift_load32(cpu->eax + 0x1A8u)) | (uint64_t)(6u));
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    lift_store_f32(cpu->eax + 0x1BCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000CD610: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD610u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"rightbutton");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD628u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD66F;
    lift_push32(cpu, 2u); lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD63Eu); lift_push32(cpu, r); sfera_sub_004D4230(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD64Cu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000CD66F;
    cpu->eax = lift_load32(cpu->esi + 0x19Cu);
    lift_x87_push(cpu, (double)0.15000000596046448f);
    lift_store32(cpu->eax + 0x1A8u, (uint64_t)(lift_load32(cpu->eax + 0x1A8u)) | (uint64_t)(6u));
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    lift_store_f32(cpu->ecx + 0x1BCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000CD66F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD66Fu);
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"range");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD680u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD6C4;
    cpu->edx = (uint32_t)(cpu->esi + 0x1A4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x1A0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4CD69Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD6A1u);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000CD6C4;
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"SpinButton::LoadUI(%s,%d,%d) -> Invalid args in 'range'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD6BBu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD6C1u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000CD6C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD6C4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"spinPos");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD6D1u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD6E4;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD6DEu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    label_000CD6E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD6E4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"badyCtrlID");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD6F1u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD704;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD6FEu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    label_000CD704: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD704u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"notifyChange");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD711u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD72B;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD720u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esi + 0x1BDu, cpu->ecx & 0xFFu);
    label_000CD72B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD72Bu);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esi + 0x1BCu, 0u);
    lift_store32(cpu->esi + 0x1B0u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD748u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CD760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD760u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000CD812;
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000CD7BE;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xDCu)) == (uint32_t)(cpu->eax)) goto label_000CD7B1;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 4u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000CD79A;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CD79A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD79Au);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000CD7B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD7B1u);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000CD7BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD7BEu);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000CD812;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xDCu)) == (uint32_t)(cpu->eax)) goto label_000CD801;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 4u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000CD7EA;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CD7EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD7EAu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (255.0));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    label_000CD801: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD801u);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    lift_return(cpu, 0u, stop_address); return;
    label_000CD812: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD812u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CD820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD820u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x30u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000CD939;
    if ((uint8_t)(lift_load8(cpu->esi + 0x49u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000CD88D;
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x1A4u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CD864;
    lift_push32(cpu, cpu->ebx);
    goto label_000CD866;
    label_000CD864: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD864u);
    lift_push32(cpu, 1u);
    label_000CD866: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD866u);
    lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD86Au);
    cpu->ecx = lift_load32(cpu->esi + 0x1A8u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x1A0u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CD887;
    lift_push32(cpu, cpu->ebx);
    goto label_000CD889;
    label_000CD887: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD887u);
    lift_push32(cpu, 1u);
    label_000CD889: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD889u);
    lift_push32(cpu, 0x70u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000CD88D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD88Du);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000CD89F;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000CD89F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD89Fu);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000CD8B1;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000CD8B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD8B1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD8BDu); lift_push32(cpu, r); sfera_sub_004D32C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CD928;
    cpu->edi = 0x3E9u;
    label_000CD8C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD8C6u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) != (uint32_t)(cpu->edi)) goto label_000CD918;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CD8F2;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CD918;
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    cpu->edx = lift_load32(cpu->esi + 0x1A4u);
    cpu->ecx = lift_load32(cpu->esi + 0x1A8u);
    cpu->edx -= cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(cpu->edx)) goto label_000CD918;
    cpu->eax += cpu->ecx;
    goto label_000CD90C;
    label_000CD8F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD8F2u);
    cpu->ecx = lift_load32(cpu->esi + 0x1B0u);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->edx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_000CD918;
    cpu->eax -= cpu->ecx;
    label_000CD90C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD90Cu);
    lift_store8(cpu->esi + 0x1BCu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    label_000CD918: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD918u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD924u); lift_push32(cpu, r); sfera_sub_004D32C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CD8C6;
    label_000CD928: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD928u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1BCu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000CD939;

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::SpinButton*>(cpu->esi)->updateStatus(cpu);
    label_000CD939: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD939u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CD950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD950u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Set Range %d %d");
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD969u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD96Fu); lift_push32(cpu, r); sfera_sub_0042E480(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_store32(cpu->esi + 0x1A4u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1A0u, cpu->ebx);
    lift_store8(cpu->esi + 0x1BCu, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CD990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD990u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"Set pos %d");
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD9A3u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD9A9u); lift_push32(cpu, r); sfera_sub_0042E480(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0x1A8u, cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 0x1BCu, cpu->eax & 0xFFu);
    lift_store8(cpu->esi + 0x1BEu, cpu->eax & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CD9D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CD9D0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"Set step %d");
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD9E3u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CD9E9u); lift_push32(cpu, r); sfera_sub_0042E480(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0x1B0u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CDA00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDA00u);
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CDA10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDA10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDA18u); lift_push32(cpu, r); sfera_sub_004CD4A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000CDA28;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDA25u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000CDA28: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDA28u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CDA30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDA30u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFEA82u);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x62u)) goto label_000CDB0C;
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFEA82u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x62u)) goto label_000CDB0C;
    switch ((uint32_t)(cpu->eax)) {
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
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDA70u); lift_push32(cpu, r); sfera_sub_004CD990(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000CDA7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDA7Au);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDA8Bu); lift_push32(cpu, r); sfera_sub_004CD950(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000CDA95: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDA95u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDAA1u); lift_push32(cpu, r); sfera_sub_004CD9D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000CDAAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDAABu);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000CDAC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDAC1u);
    cpu->edx = lift_load32(cpu->esi + 0x1A0u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 0x1A4u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000CDAE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDAE3u);

    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::SpinButton*>(cpu->esi)->updateStatus(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDAECu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000CDAF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDAF6u);
    cpu->eax = lift_load32(cpu->esi + 0x1B0u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000CDB0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDB0Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(0x70u)) goto label_000CDB20;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0x6Cu)) goto label_000CDB52;
    label_000CDB20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDB20u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x198u)) == (uint32_t)(0u)) goto label_000CDB39;
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000CDB39: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDB39u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x19Cu)) == (uint32_t)(0u)) goto label_000CDB52;
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000CDB52: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDB52u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDB5Cu); lift_push32(cpu, r); sfera_sub_004D2DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CDBF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDBF0u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x9Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CDD37;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1B4u)) != (uint32_t)(0u)) goto label_000CDC5D;
    cpu->edx = lift_load32(cpu->esi + 0x1B8u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xFFFFFFFFu)) goto label_000CDC5D;
    if ((uint32_t)(cpu->edx) == 0u) goto label_000CDC3F;
    cpu->eax = lift_load32(cpu->eax + 0xA0u);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edx) <= (uint32_t)(1u)) goto label_000CDC3C;
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFFFu);
    label_000CDC37: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDC37u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CDC37;
    label_000CDC3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDC3Cu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    label_000CDC3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDC3Fu);
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CDC5D;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"SpinButton::UpdateStatus() -> Bady '%d' not found.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDC54u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDC5Au); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000CDC5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDC5Du);
    cpu->eax = lift_load32(cpu->esi + 0x1A0u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1A8u)) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000CDC71;
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    label_000CDC71: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDC71u);
    cpu->eax = lift_load32(cpu->esi + 0x1A4u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1A8u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000CDC85;
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    label_000CDC85: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDC85u);
    cpu->eax = lift_load32(cpu->esi + 0x1A8u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1ACu)) == (uint32_t)(cpu->eax)) goto label_000CDD29;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1B4u)) == (uint32_t)(0u)) goto label_000CDCDB;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.spin_value_text);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4CDCACu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDCB2u);
    cpu->edx = lift_load32(cpu->esi + 0x1B4u);
    cpu->eax = (uint32_t)(uintptr_t)g_sfera_ui_load_scratch_runtime.spin_value_text;
    cpu->esp += 0xCu;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CDCC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDCC3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CDCC3;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.spin_value_text);
    cpu->ecx = (uint32_t)(cpu->edx + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDCDAu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_000CDCDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDCDBu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x1BDu)) == (uint8_t)(0u)) goto label_000CDD1D;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1BEu)) == (uint8_t)(0u)) goto label_000CDD1D;
    cpu->ecx = lift_load32(cpu->esi + 0xD8u);
    cpu->edx = lift_load32(cpu->esi + 0x1A8u);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x10u, 0x157Du);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCDD1Du); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000CDD1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDD1Du);
    cpu->ecx = lift_load32(cpu->esi + 0x1A8u);
    lift_store32(cpu->esi + 0x1ACu, cpu->ecx);
    label_000CDD29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDD29u);
    lift_store8(cpu->esi + 0x1BCu, 1u);
    lift_store8(cpu->esi + 0x1BEu, 1u);
    label_000CDD37: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDD37u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CDD50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDD50u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDD5Eu); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
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
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1BDu)) & 0xFFu);
    lift_store8(cpu->esi + 0x1BDu, cpu->ecx & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x1BEu)) & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 0x1BEu, cpu->edx & 0xFFu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CDE00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDE00u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0xAFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\SpinCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDE34u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1C0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDE3Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CDE5C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDE58u); lift_push32(cpu, r); sfera_sub_004CD430(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000CDE5E;
    label_000CDE5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDE5Cu);
    cpu->esi = 0u;
    label_000CDE5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDE5Eu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDE6Eu); lift_push32(cpu, r); sfera_sub_004CDD50(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x198u)) == (uint32_t)(0u)) goto label_000CDE96;
    cpu->ecx = lift_load32(cpu->edi + 0x198u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDE88u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCDE96u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000CDE96: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDE96u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x19Cu)) == (uint32_t)(0u)) goto label_000CDEBA;
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDEACu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCDEBAu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000CDEBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDEBAu);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_000CDEDE;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDED0u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCDEDEu); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000CDEDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDEDEu);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CDF00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDF00u);
    lift_x87_push(cpu, 1.0);
    cpu->eax = cpu->ecx;
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_store32(cpu->eax + 0x8Cu, cpu->ecx);
    lift_store32(cpu->eax + 0x90u, cpu->ecx);
    lift_store32(cpu->eax + 0x94u, cpu->ecx);
    lift_store_f32(cpu->eax + 0x18u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    cpu->edx |= 0xFFFFFFFFu;
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x1Cu, cpu->edx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + 0x20u, cpu->ecx);
    lift_store_f32(cpu->eax + 0x38u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x3Cu, cpu->edx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + 0x40u, cpu->ecx);
    lift_store_f32(cpu->eax + 0x34u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x5Cu, cpu->edx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + 0x60u, cpu->ecx);
    lift_store_f32(cpu->eax + 0x58u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x7Cu, cpu->edx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + 0x80u, cpu->ecx);
    lift_store_f32(cpu->eax + 0x54u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CDF70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDF70u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000CDFBC;
    cpu->edx = 0xA6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDF8Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000CDF93: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDF93u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CDF93;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDFA3u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CDFB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDFB0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000CDFB0;
    goto label_000CDFC2;
    label_000CDFBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDFBCu);
    lift_store32(cpu->esi, 0u);
    label_000CDFC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDFC2u);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000CDFDE;
    cpu->edx = 0xACu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDFD5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CDFDBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000CDFDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDFDEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CDFF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CDFF0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x94u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_000CE0D4;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x90u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CE078;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CE059;
    cpu->edi = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CE020: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE020u);
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    if ((uint32_t)(lift_load32(cpu->edi + cpu->eax)) == (uint32_t)(0u)) goto label_000CE04D;
    cpu->edx = 0xBAu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE03Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    cpu->edx = lift_load32(cpu->edi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE04Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000CE04D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE04Du);
    ++cpu->ebx;
    cpu->edi += 0x3Cu;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esi + 0x94u))) goto label_000CE020;
    label_000CE059: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE059u);
    cpu->edx = 0xBCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE068u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE074u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ebx = lift_pop32(cpu);
    label_000CE078: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE078u);
    cpu->edi = 0u;
    lift_store32(cpu->esi + 0x90u, cpu->edi);
    lift_store32(cpu->esi + 0x94u, cpu->edi);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->edi)) goto label_000CE0D3;
    cpu->edx = 0xC3u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE099u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->ebp;
    cpu->edx = 0x3Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE0B1u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebp;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    cpu->ecx -= cpu->ebp;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x90u, cpu->eax);
    lift_store32(cpu->esi + 0x94u, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4CE0CBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE0D0u);
    cpu->esp += 0x10u;
    label_000CE0D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE0D3u);
    cpu->edi = lift_pop32(cpu);
    label_000CE0D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE0D4u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CE0E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE0E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(g_sfera_sprite_runtime.render_mode) == (uint32_t)(cpu->esi)) goto label_000CE137;
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CE126;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CE10F;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CE131;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 2u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE107u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    g_sfera_sprite_runtime.render_mode = (uint32_t)(cpu->esi);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CE10F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE10Fu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE11Eu); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    g_sfera_sprite_runtime.render_mode = (uint32_t)(cpu->esi);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CE126: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE126u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCE131u); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    label_000CE131: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE131u);
    g_sfera_sprite_runtime.render_mode = (uint32_t)(cpu->esi);
    label_000CE137: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE137u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CE140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE140u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, 6u);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE156u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x94u);
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ebp)) goto label_000CE2A7;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, 0.5);
    lift_store32(cpu->esp + 0x10u, 0xFFFFFFFFu);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    lift_push32(cpu, cpu->edi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->ebx = (uint32_t)(cpu->esi + 0xCu);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 0x24u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000CE191: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE191u);
    cpu->edi = lift_load32(cpu->esi + 0x90u);
    cpu->edi += lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) == (uint32_t)(cpu->ecx)) goto label_000CE1BF;
    cpu->edx = 1u;
    if ((uint32_t)(g_sfera_sprite_runtime.render_mode) == (uint32_t)(cpu->edx)) goto label_000CE1B3;
    cpu->edx = 0u;
    label_000CE1B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE1B3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE1B8u); lift_push32(cpu, r); sfera_sub_0044FCB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_000CE1BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE1BFu);
    cpu->ecx = lift_load32(cpu->edi + 0x2Cu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x2Cu)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE1CF;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE1CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE1CFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->edi + 0x34u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x34u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CE1EB;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE1EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE1EBu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1Cu));
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x30u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000CE214;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE214: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE214u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x20u));
    lift_store_f32(cpu->esi + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2Cu));
    lift_store_f32(cpu->esi + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->edi + 0x38u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x38u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE243;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE243: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE243u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x1C4u);
    lift_store_f32(cpu->esi + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x24u));
    lift_store_f32(cpu->esi + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx));
    lift_store_f32(cpu->esi + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x50u));
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x18u));
    lift_store_f32(cpu->esi + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x28u));
    lift_store_f32(cpu->esi + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE281u); lift_push32(cpu, r); sfera_sub_004D8B70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 2u); lift_push32(cpu, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE293u); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x3Cu) + (uint64_t)(0u));
    ++cpu->ebp;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(lift_load32(cpu->esi + 0x94u))) goto label_000CE191;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000CE2A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE2A7u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CE2B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE2B0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFC0u;
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x94u)) == (uint32_t)(cpu->edi)) goto label_000CE4E6;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE2DBu); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 8u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 4u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000CE2FF;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE2FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE2FFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 8u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE329;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE329: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE329u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x94u);
    lift_store32(cpu->esp + 0x2Cu, 0xFFFFFFFFu);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 2u, (lift_x87_get(cpu, 2u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->ebp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->edi)) goto label_000CE4E6;
    lift_store32(cpu->esp + 0x38u, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->esi + 0xCu);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    label_000CE362: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE362u);
    cpu->edi = lift_load32(cpu->esi + 0x90u);
    cpu->edi += lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x2Cu)) == (uint32_t)(cpu->ecx)) goto label_000CE390;
    cpu->edx = 1u;
    if ((uint32_t)(g_sfera_sprite_runtime.render_mode) == (uint32_t)(cpu->edx)) goto label_000CE384;
    cpu->edx = 0u;
    label_000CE384: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE384u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE389u); lift_push32(cpu, r); sfera_sub_0044FCB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    label_000CE390: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE390u);
    cpu->eax = lift_load32(cpu->edi + 0x2Cu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x2Cu)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000CE3A0;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE3A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE3A0u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x30u))));
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE3B7u); lift_push32(cpu, r); sfera_sub_004EED66(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 8u))));
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x34u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE3D4;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE3D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE3D4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE3E8u); lift_push32(cpu, r); sfera_sub_004EED66(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0xCu))));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1Cu));
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->edi + 0x30u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x30u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CE412;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE412: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE412u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE426u); lift_push32(cpu, r); sfera_sub_004EED66(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 8u))));
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x20u));
    lift_store_f32(cpu->esi + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2Cu));
    lift_store_f32(cpu->esi + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->edi + 0x38u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x38u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000CE45C;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE45C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE45Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE470u); lift_push32(cpu, r); sfera_sub_004EED66(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_push32(cpu, 0x1C4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0xCu))));
    lift_store_f32(cpu->esi + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x24u));
    lift_store_f32(cpu->esi + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx));
    lift_store_f32(cpu->esi + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x50u));
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x18u));
    lift_store_f32(cpu->esi + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x28u));
    lift_store_f32(cpu->esi + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE4BAu); lift_push32(cpu, r); sfera_sub_004D8B70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 2u); lift_push32(cpu, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE4CCu); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->esp + 0x28u, (uint64_t)(lift_load32(cpu->esp + 0x28u)) + (uint64_t)(0x3Cu) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0x94u))) goto label_000CE362;
    label_000CE4E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE4E6u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CE4F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE4F0u);
    { uint64_t l=cpu->esp, r=(uint64_t)(0x20u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->edx -= cpu->eax;
    cpu->eax = lift_load32(cpu->ecx + 0x90u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CE558;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->ecx + 1u);
    label_000CE524: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE524u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CE524;
    cpu->ecx -= cpu->edi;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CE530: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE530u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CE530;
    cpu->eax -= cpu->edi;
    cpu->edi = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->eax)) goto label_000CE585;
    cpu->edx = 0x23Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE54Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE555u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000CE558: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE558u);
    cpu->edx = 0x23Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE567u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->ebp;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CE570: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE570u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CE570;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE580u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, cpu->eax);
    label_000CE585: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE585u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->ecx = cpu->ebp;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000CE590: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE590u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000CE590;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE5A1u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000CE5BD;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Sprite::Texture not found '%s'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE5B4u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE5BAu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000CE5BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE5BDu);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE5C9u); lift_push32(cpu, r); sfera_sub_0044FC60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CE689;
    cpu->edx = lift_load32(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CE5E3;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE5E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE5E3u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE5F5;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE5F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE5F5u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 4u)))));
    cpu->edx = lift_load32(cpu->eax + 4u);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CE60A;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE60A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE60Au);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE61C;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE61C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE61Cu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 8u)))));
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CE631;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE631: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE631u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE643;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE643: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE643u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 0xCu)))));
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CE658;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE658: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE658u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000CE66A;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE66A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE66Au);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000CE6A5;
    label_000CE689: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE689u);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000CE6A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE6A5u);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CE6C3;
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esi + 0x2Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esi + 0x34u, cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esi + 0x30u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    goto label_000CE6DC;
    label_000CE6C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE6C3u);
    lift_store32(cpu->esi + 0x34u, 0u);
    lift_store32(cpu->esi + 0x2Cu, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 0x30u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_000CE6DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE6DCu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esi + 0x38u, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CE700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE700u);
    cpu->esp -= 0x20u;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ecx + 0x94u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000CE88D;
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->edx -= cpu->eax;
    cpu->eax = lift_load32(cpu->ecx + 0x90u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_000CE88C;
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE745u); lift_push32(cpu, r); sfera_sub_0044FC60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CE88C;
    cpu->ecx = lift_load32(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE75F;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE75F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE75Fu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CE771;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE771: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE771u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 4u)))));
    cpu->ecx = lift_load32(cpu->eax + 4u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE786;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE786: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE786u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CE798;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE798: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE798u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 8u)))));
    cpu->ecx = lift_load32(cpu->eax + 8u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE7AD;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE7AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE7ADu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CE7BF;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE7BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE7BFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 0xCu)))));
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE7D4;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE7D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE7D4u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CE7E6;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE7E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE7E6u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 0x10u)))));
    cpu->ecx = lift_load32(cpu->eax + 0x10u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE7FB;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE7FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE7FBu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CE80D;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE80D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE80Du);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 0x14u)))));
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE822;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE822: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE822u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CE834;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE834: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE834u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 0x18u)))));
    cpu->ecx = lift_load32(cpu->eax + 0x18u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE849;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE849: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE849u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CE85B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE85B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE85Bu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->eax + 0x1Cu);
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 4u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000CE875;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE875: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE875u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000CE887;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CE887: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE887u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000CE88C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE88Cu);
    cpu->esi = lift_pop32(cpu);
    label_000CE88D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE88Du);
    cpu->esp += 0x20u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CE8A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE8A0u);
    cpu->esp -= 0x148u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x150u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x15Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x164u);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"name");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE8E4u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CE908;
    cpu->eax = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE8F6u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CE908;
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE906u); lift_push32(cpu, r); sfera_sub_004CDF70(cpu,r); if (cpu->eip != r) return; }
    goto label_000CE923;
    label_000CE908: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE908u);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> Name not specified.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE91Au); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE920u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000CE923: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE923u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"size");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE930u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CE94E;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE93Du); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->ebp + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE949u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 8u, cpu->eax);
    goto label_000CE969;
    label_000CE94E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE94Eu);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> Size not specified.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE960u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE966u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000CE969: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE969u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE975u); lift_push32(cpu, r); sfera_sub_00494920(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE97Du); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"texture");
    cpu->ecx = cpu->esi;
    cpu->ebx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE98Bu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CE9A5;
    (void)cpu;
    label_000CE990: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE990u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"texture");
    cpu->ecx = cpu->esi;
    ++cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE99Du); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CE990;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000CE9C4;
    label_000CE9A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE9A5u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edi);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> At least one texture must be specified.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE9BBu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE9C1u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000CE9C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE9C4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE9CCu); lift_push32(cpu, r); sfera_sub_004CDFF0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000CEB41;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    cpu->ebx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE9DEu); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"texture");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CE9EAu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = native_function_address32(&::sscanf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CEA97;
    label_000CE9F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CE9F8u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEA06u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CEA83;
    cpu->edx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_sprite_runtime.texture_token[0]);
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%s %d %d %d %d %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0xCEA42u), LIFT_CODE_TOKEN_RVA(0xCEA40u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEA42u);
    cpu->esp += 0x2Cu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(9u)) goto label_000CEA69;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> Incorrect number of args in 'texture'.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEA60u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEA66u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000CEA69: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEA69u);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEA82u); lift_push32(cpu, r); sfera_sub_004CE4F0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->ebx;
    label_000CEA83: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEA83u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"texture");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEA8Fu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CE9F8;
    label_000CEA97: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEA97u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEA9Fu); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"tcoords");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEAABu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CEB41;
    cpu->ebx = (uint32_t)(cpu->esi + 0x10u);
    label_000CEAB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEAB6u);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %d %d %d %d %d %d %d %d"); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0x40u, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0xCEAF3u), LIFT_CODE_TOKEN_RVA(0xCEAF1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEAF3u);
    cpu->esp += 0x2Cu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(9u)) goto label_000CEB1A;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Sprite::Load(%s,%d,%d) -> Incorrect number of args in 'tcoords'.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEB11u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEB17u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000CEB1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEB1Au);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEB2Du); lift_push32(cpu, r); sfera_sub_004CE700(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"tcoords");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEB39u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CEAB6;
    label_000CEB41: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEB41u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEB4Du); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x148u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CEB70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEB70u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEB82u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].x, lift_x87_get(cpu, 0u));
    g_sfera_scene_render_runtime.interface_quad[0].diffuse = (uint32_t)(cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    g_sfera_scene_render_runtime.interface_quad[1].diffuse = (uint32_t)(cpu->esi);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].y, lift_x87_get(cpu, 0u));
    g_sfera_scene_render_runtime.interface_quad[2].diffuse = (uint32_t)(cpu->esi);
    lift_x87_push(cpu, 1.0);
    g_sfera_scene_render_runtime.interface_quad[3].diffuse = (uint32_t)(cpu->esi);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].rhw, lift_x87_get(cpu, 0u));
    cpu->esi = lift_pop32(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].z, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].x, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].rhw, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].z, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].y, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].rhw, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].z, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].rhw, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].z, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x10u, 0x20u);
    lift_store32(cpu->esp + 0xCu, (uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].x);
    lift_store32(cpu->esp + 8u, 2u);
    lift_store32(cpu->esp + 4u, 6u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    sfera_sub_004D9050(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CEC50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEC50u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    g_sfera_scene_render_runtime.interface_quad[0].diffuse = (uint32_t)(cpu->ecx);
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].x, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store32(cpu->esp + 8u, 2u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].y, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].rhw, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].z, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    g_sfera_scene_render_runtime.interface_quad[1].diffuse = (uint32_t)(cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 5u)));
    lift_store32(cpu->esp + 0xCu, (uintptr_t)&g_sfera_scene_render_runtime.interface_quad[0].x);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].x, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].rhw, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].z, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0xCu));
    g_sfera_scene_render_runtime.interface_quad[2].diffuse = (uint32_t)(cpu->ecx);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[1].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store32(cpu->esp + 0x10u, 0x20u);
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store32(cpu->esp + 4u, 6u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].y, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].rhw, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].z, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x14u));
    g_sfera_scene_render_runtime.interface_quad[3].diffuse = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[2].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].rhw, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].z, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x18u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.interface_quad[3].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    sfera_sub_004D9050(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CEDA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEDA0u);
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_000CEDBA;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEDB8u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    goto label_000CEDD3;
    label_000CEDBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEDBAu);
    { uint64_t l=(uint64_t)(g_sfera_sprite_runtime.render_mode), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CEDC9;
    cpu->edx = 0u;
    goto label_000CEDCE;
    label_000CEDC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEDC9u);
    cpu->edx = 1u;
    label_000CEDCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEDCEu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCEDD3u); lift_push32(cpu, r); sfera_sub_0044FCB0(cpu,r); if (cpu->eip != r) return; }
    label_000CEDD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEDD3u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->esp -= 0x10u;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEE00u); lift_push32(cpu, r); sfera_sub_004CEC50(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CEE10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEE10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEE21u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->esp -= 0x10u;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEE4Eu); lift_push32(cpu, r); sfera_sub_004CEC50(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CEE60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEE60u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x94u)) == (uint32_t)(0u)) goto label_000CEFE3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_push32(cpu, cpu->edi);
    lift_store_f64(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEE81u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEE8Eu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->edi = lift_load32(cpu->esi + 0x90u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = 1u;
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 4u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_sprite_runtime.render_mode) == (uint32_t)(cpu->edx)) goto label_000CEF4C;
    cpu->edx = 0u;
    label_000CEF4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEF4Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEF51u); lift_push32(cpu, r); sfera_sub_0044FCB0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_push32(cpu, 0x20u);
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    lift_push32(cpu, 2u);
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 6u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1Cu));
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x20u));
    lift_store_f32(cpu->esi + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esi + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x24u));
    lift_store_f32(cpu->esi + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x18u));
    lift_store_f32(cpu->esi + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x28u));
    lift_store_f32(cpu->esi + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CEFE2u); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_000CEFE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEFE3u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CEFF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CEFF0u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x90u)) == (uint32_t)(cpu->edi)) goto label_000CF005;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCF005u); lift_push32(cpu, r); sfera_sub_004CDFF0(cpu,r); if (cpu->eip != r) return; }
    label_000CF005: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF005u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, 1.0);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x94u);
    lift_store32(cpu->esi + 0x94u, cpu->edx);
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    cpu->eax |= 0xFFFFFFFFu;
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->esi + 0x20u, cpu->edi);
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x3Cu, cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x5Cu, cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->esi + 0x60u, cpu->edi);
    lift_store_f32(cpu->esi + 0x58u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x7Cu, cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->esi + 0x80u, cpu->edi);
    lift_store_f32(cpu->esi + 0x54u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->ebp);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000CF074;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCF074u); lift_push32(cpu, r); sfera_sub_004CDF70(cpu,r); if (cpu->eip != r) return; }
    label_000CF074: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF074u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x94u)) <= (uint32_t)(cpu->edi)) goto label_000CF154;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0x71u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF090u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x94u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0x3Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF0ACu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x94u);
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->edx -= cpu->ecx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_store32(cpu->esi + 0x90u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x90u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4CF0CCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF0D1u);
    cpu->esp += 0x10u;
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x94u)) <= (uint32_t)(cpu->edi)) goto label_000CF14B;
    cpu->edi = cpu->edi;
    label_000CF0E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF0E0u);
    cpu->edx = lift_load32(cpu->ebp + 0x90u);
    if ((uint32_t)(lift_load32(cpu->edi + cpu->edx)) == (uint32_t)(0u)) goto label_000CF13F;
    cpu->edx = 0x78u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF0FBu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x90u);
    cpu->eax = lift_load32(cpu->edi + cpu->eax);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000CF107: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF107u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000CF107;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF117u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_store32(cpu->edi + cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 0x90u);
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    cpu->ecx = lift_load32(cpu->edi + cpu->edx);
    cpu->edx = lift_load32(cpu->edi + cpu->eax);
    cpu->esp += 4u;
    label_000CF135: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF135u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000CF135;
    label_000CF13F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF13Fu);
    ++cpu->ebx;
    cpu->edi += 0x3Cu;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esi + 0x94u))) goto label_000CF0E0;
    label_000CF14B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF14Bu);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000CF154: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF154u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CF160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF160u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_000CF182;
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF177u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF17Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000CF182: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF182u);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF191u); lift_push32(cpu, r); sfera_sub_004CDFF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CF1A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF1A0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF1AEu); lift_push32(cpu, r); sfera_sub_004CDF70(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF1B7u); lift_push32(cpu, r); sfera_sub_004CDFF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF1C5u); lift_push32(cpu, r); sfera_sub_004CE4F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax |= 0xFFFFFFFFu;
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    lift_store32(cpu->esi + 0x3Cu, cpu->eax);
    lift_store32(cpu->esi + 0x5Cu, cpu->eax);
    lift_store32(cpu->esi + 0x7Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    cpu->ecx = lift_load32(cpu->eax + 0x30u);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0x38u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CF1F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF1F0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF1FEu); lift_push32(cpu, r); sfera_sub_004CDF70(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF207u); lift_push32(cpu, r); sfera_sub_004CDFF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x98u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (2u)) == 0u) goto label_000CF21A;
    cpu->eax = (uint32_t)(cpu->edi + 0x88u);
    goto label_000CF21C;
    label_000CF21A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF21Au);
    cpu->eax = 0u;
    label_000CF21C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF21Cu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(4u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (uint32_t)(cpu->edi + 0x40u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CF226;
    cpu->ecx = cpu->edi;
    label_000CF226: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF226u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF232u); lift_push32(cpu, r); sfera_sub_004CE4F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax |= 0xFFFFFFFFu;
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    lift_store32(cpu->esi + 0x3Cu, cpu->eax);
    lift_store32(cpu->esi + 0x5Cu, cpu->eax);
    lift_store32(cpu->esi + 0x7Cu, cpu->eax);
    if ((uint8_t)((lift_load8(cpu->edi + 0x98u)) & (1u)) == 0u) goto label_000CF261;
    cpu->eax = lift_load32(cpu->edi + 0x80u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x84u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000CF261: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF261u);
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    cpu->edx = lift_load32(cpu->eax + 0x30u);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x38u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CF280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF280u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x8Cu);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000CF296;
    --cpu->eax;
    lift_store32(cpu->esi + 0x8Cu, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000CF296: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF296u);
    cpu->edx = 0x9Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF2A5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_000CF2C4;
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Sprite.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF2B9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF2C1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000CF2C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF2C4u);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF2D3u); lift_push32(cpu, r); sfera_sub_004CDFF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF2D9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CF2E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF2E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF2E8u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    std::construct_at(reinterpret_cast<SphereUI::TextCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x50u, 2u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CF310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF310u);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)((lift_load8(cpu->esi + 0x198u)) & (1u)) == 0u) goto label_000CF3C7;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_000CF36C;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_store32(cpu->esp + 8u, cpu->edx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000CF35E;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCF35Eu); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000CF35E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF35Eu);
    cpu->ecx = lift_load32(cpu->edi + 0x30u);
    cpu->edx = lift_load32(cpu->edi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 0xCu);
    cpu->edx += lift_load32(cpu->esp + 8u);
    label_000CF36C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF36Cu);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x38u);
    cpu->ecx += cpu->edx;
    cpu->edx = lift_load32(cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->eax)) goto label_000CF3C5;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0x28u);
    cpu->ebx += cpu->eax;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_pop32(cpu);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000CF3C5;
    cpu->eax = lift_load32(cpu->ebp + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000CF3C5;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000CF3C5;
    if ((uint8_t)((lift_load8(cpu->ebp + 0xCu)) & (1u)) == 0u) goto label_000CF3C5;
    cpu->eax = lift_load32(cpu->esi + 0xD8u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, 0x3E9u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCF3C5u); lift_push32(cpu, r); sfera_sub_004D3290(cpu,r); if (cpu->eip != r) return; }
    label_000CF3C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF3C5u);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_000CF3C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF3C7u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x28u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CF3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF3E0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF3F8u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0x28u);
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(cpu->edi)) goto label_000CF406;
    if ((uint32_t)(lift_load32(cpu->esi + 0x2Cu)) != (uint32_t)(cpu->edi)) goto label_000CF431;
    label_000CF406: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF406u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x64u)) <= (uint32_t)(cpu->edi)) goto label_000CF431;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x68u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x54u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000CF416;
    cpu->eax = lift_load32(cpu->eax);
    label_000CF416: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF416u);
    cpu->edx = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Du);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCF431u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    label_000CF431: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF431u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"textStyle");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF442u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CF49A;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0x198u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF454u); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->edi)) goto label_000CF499;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000CF460: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF460u);
    lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.text_style_token); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF46Du); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000CF492;
    lift_push32(cpu, (uintptr_t)"NOTIFY_CLICK"); lift_push32(cpu, (uintptr_t)g_sfera_ui_load_scratch_runtime.text_style_token);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4CF47Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF481u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000CF492;
    lift_store32(cpu->esi + 0x198u, 1u);
    label_000CF492: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF492u);
    cpu->edi += 2u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_000CF460;
    label_000CF499: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF499u);
    cpu->ebx = lift_pop32(cpu);
    label_000CF49A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF49Au);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF4A6u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CF4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF4C0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000CF661;
    cpu->edx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x64u)) == (uint32_t)(cpu->edx)) goto label_000CF661;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->ebp = 0u;
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_000CF51D;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000CF50D;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCF50Du); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000CF50D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF50Du);
    cpu->ebp = lift_load32(cpu->edi + 0x30u);
    cpu->ebx = lift_load32(cpu->edi + 0x34u);
    cpu->ebp += lift_load32(cpu->esp + 0x14u);
    cpu->ebx += lift_load32(cpu->esp + 0x10u);
    cpu->edx = 0u;
    label_000CF51D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF51Du);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += cpu->ebp;
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->ecx += cpu->ebx;
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->ecx);
    cpu->edi = lift_load32(cpu->esi + 0x28u);
    cpu->edi += cpu->eax;
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->edi);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax += cpu->ecx;
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((uint32_t)(lift_load32(cpu->esi + 0x118u)) == (uint32_t)(cpu->edx)) goto label_000CF5E0;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x68u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x54u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000CF566;
    cpu->eax = lift_load32(cpu->eax);
    label_000CF566: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF566u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Du);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF586u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x118u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_000CF5A2;
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000CF5A2;
    cpu->eax -= cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_000CF5A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF5A2u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (2u)) == 0u) goto label_000CF5B8;
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000CF5B8;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000CF5B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF5B8u);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (4u)) == 0u) goto label_000CF5CC;
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000CF5CC;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_000CF5CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF5CCu);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (8u)) == 0u) goto label_000CF5E0;
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000CF5E0;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000CF5E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF5E0u);
    cpu->edi = 0xFFu;
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(cpu->edi)) goto label_000CF5FD;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000CF5FD;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCF5FDu); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000CF5FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF5FDu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x68u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x54u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000CF608;
    cpu->eax = lift_load32(cpu->eax);
    label_000CF608: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF608u);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Du);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->edx += cpu->ebx;
    cpu->edx += lift_load32(cpu->esi + 0x34u);
    cpu->ecx += cpu->ebp;
    cpu->ecx += lift_load32(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF63Fu); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xDCu)), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CF661;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000CF661;
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    sfera_sub_004CE0E0(cpu, stop_address); return;
    label_000CF661: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF661u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CF670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF670u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0xAEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\TextCtrl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF6A4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1A0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF6AEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000CF6E7;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF6CAu); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    std::construct_at(reinterpret_cast<SphereUI::TextCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x198u, 0u);
    lift_store32(cpu->esi + 0x50u, 2u);
    lift_store8(cpu->esi + 0x48u, 0u);
    goto label_000CF6E9;
    label_000CF6E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF6E7u);
    cpu->esi = 0u;
    label_000CF6E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF6E9u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF6F9u); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x198u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    lift_store8(cpu->esi + 0x4Bu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_000CF72D;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF71Fu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCF72Du); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000CF72D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF72Du);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CF750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF750u);
    lift_x87_push(cpu, 0.0);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_store_f32(cpu->ecx + 0x1B0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->ecx + 0x48u, 1u);
    lift_store8(cpu->ecx + 0x1A0u, cpu->eax & 0xFFu);
    lift_store8(cpu->ecx + 0x1CCu, cpu->eax & 0xFFu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CF770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF770u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1B0u));
    lift_x87_push(cpu, 0.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000CF795;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF789u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    lift_store32(cpu->esi + 0x1BCu, cpu->edx);
    label_000CF795: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF795u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->eax += 0xAu;
    cpu->ecx += 0x14u;
    lift_store8(cpu->esi + 0x48u, 0u);
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    lift_store32(cpu->esi + 0x19Cu, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CF7C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF7C0u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x1D4u);
    cpu->ecx -= lift_load32(cpu->esi + 0x1D0u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CF9EE;
    cpu->ecx = lift_load32(cpu->esi + 0x1D0u);
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x10u)) == (uint32_t)(cpu->ebx)) goto label_000CF9EE;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000CF869;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1B0u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000CF869;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF818u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x1B8u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esi + 0x1BCu)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10000.0));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (4.0));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esi + 0x1B0u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000CF867;
    lift_store_f32(cpu->esi + 0x1B0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000CF869;
    label_000CF867: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF867u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000CF869: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF869u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_000CF9B9;
    if ((uint8_t)(lift_load8(cpu->edi + 0x48u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000CF9B9;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0xCu, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000CF8A2;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCF8A2u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000CF8A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF8A2u);
    cpu->ebx = lift_load32(cpu->edi + 0x34u);
    cpu->ebx += lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->edi + 0x28u);
    cpu->ecx = lift_load32(cpu->edi + 0x2Cu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->edi + 0x30u);
    cpu->ebp += lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    cpu->edx = lift_load32(cpu->edi + 0xCu);
    cpu->eax += cpu->ebp;
    cpu->ecx += cpu->ebx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (3u)) != 0u) goto label_000CF8D5;
    if ((uint32_t)(lift_load32(cpu->edi + 8u)) == (uint32_t)(0u)) goto label_000CF8E0;
    label_000CF8D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF8D5u);
    lift_store8(cpu->esi + 0x1CCu, 1u);
    lift_store8(cpu->esi + 0x48u, 1u);
    label_000CF8E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF8E0u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) == (uint8_t)(0u)) goto label_000CF96B;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1CCu)) != (uint8_t)(0u)) goto label_000CF96B;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1A0u)) == (uint8_t)(0u)) goto label_000CF9C2;
    cpu->edx = lift_load32(cpu->esi + 0x198u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_000CF9C2;
    cpu->edx = lift_load32(cpu->esi + 0x19Cu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_000CF9C2;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF922u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x1A8u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esi + 0x1ACu)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 0x1Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10000.0));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)0.5f));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000CF963;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCF963u); lift_push32(cpu, r); sfera_sub_004CF770(cpu,r); if (cpu->eip != r) return; }
    label_000CF963: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF963u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    label_000CF96B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF96Bu);
    cpu->edx = lift_load32(cpu->edi);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_pop32(cpu);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000CF9CB;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000CF9CB;
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_000CF9CB;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000CF9CB;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1A0u)) != (uint8_t)(0u)) goto label_000CF9B9;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) == (uint8_t)(0u)) goto label_000CF9B9;
    lift_store8(cpu->esi + 0x1A0u, 1u);
    cpu->edx = lift_load32(cpu->edi);
    lift_store32(cpu->esi + 0x198u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CF9ADu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    lift_store32(cpu->esi + 0x1ACu, cpu->edx);
    label_000CF9B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF9B9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
    label_000CF9C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF9C2u);
    lift_store8(cpu->esi + 0x1A0u, 0u);
    goto label_000CF96B;
    label_000CF9CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF9CBu);
    lift_x87_push(cpu, 0.0);
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->esi + 0x1B0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->esi + 0x48u, 1u);
    lift_store8(cpu->esi + 0x1A0u, 0u);
    lift_store8(cpu->esi + 0x1CCu, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
    label_000CF9EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CF9EEu);
    lift_store8(cpu->esi + 0x48u, 1u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CFA00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFA00u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000CFD88;
    cpu->ecx = lift_load32(cpu->esi + 0x1C4u);
    cpu->edx = lift_load32(cpu->esi + 0x198u);
    cpu->eax = g_sfera_graphics_runtime.display_width;
    cpu->edx += cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000CFA33;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esi + 0x198u, cpu->eax);
    label_000CFA33: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFA33u);
    cpu->ecx = lift_load32(cpu->esi + 0x19Cu);
    cpu->eax = g_sfera_graphics_runtime.display_height;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0x1C8u);
    cpu->ecx += cpu->ebx;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000CFA55;
    cpu->eax -= cpu->ebx;
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    label_000CFA55: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFA55u);
    cpu->ecx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x198u)) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000CFA65;
    lift_store32(cpu->esi + 0x198u, cpu->ecx);
    label_000CFA65: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFA65u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x19Cu)) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000CFA73;
    lift_store32(cpu->esi + 0x19Cu, cpu->ecx);
    label_000CFA73: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFA73u);
    cpu->eax = lift_load32(cpu->esi + 0x9Cu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000CFA7F;
    cpu->eax = cpu->esi;
    label_000CFA7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFA7Fu);
    cpu->edx = lift_load32(cpu->eax + 0xDCu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 0xDCu)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000CFA95;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000CFA95: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFA95u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x1B0u))));
    cpu->edx = lift_load32(cpu->esi + 0x19Cu);
    cpu->ebp = lift_load32(cpu->esi + 0x198u);
    lift_store16(cpu->esp + 0x10u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->esp -= 0x10u;
    cpu->ecx &= 0xFFFFFFu;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x24u));
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    lift_store64(cpu->esp + 0x30u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->esp + 0x30u);
    cpu->eax = cpu->edi;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x20u));
    cpu->ecx |= cpu->eax;
    lift_store32(cpu->esi + 0x90u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x1C0u);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    cpu->ebp += lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx |= cpu->eax;
    lift_store32(cpu->esp + 0x2Cu, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CFB2Bu); lift_push32(cpu, r); sfera_sub_004CEB70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x19Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1C4u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    cpu->esp -= 0x10u;
    cpu->eax += cpu->ecx;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CFB7Du); lift_push32(cpu, r); sfera_sub_004CEB70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x19Cu);
    cpu->eax += lift_load32(cpu->esi + 0x1C8u);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    cpu->edx = lift_load32(cpu->esi + 0x1C4u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    cpu->esp -= 0x10u;
    cpu->edx += cpu->ecx;
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    --cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CFBD5u); lift_push32(cpu, r); sfera_sub_004CEB70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x19Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x1C8u);
    cpu->edx += cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    cpu->esp -= 0x10u;
    ++cpu->ecx;
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CFC27u); lift_push32(cpu, r); sfera_sub_004CEB70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x19Cu);
    cpu->edx = lift_load32(cpu->esi + 0x1C8u);
    cpu->ecx = lift_load32(cpu->esi + 0x198u);
    cpu->ecx += lift_load32(cpu->esi + 0x1C4u);
    cpu->edx += cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    cpu->esp -= 0x10u;
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    --cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CFC7Fu); lift_push32(cpu, r); sfera_sub_004CEB70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFu)) goto label_000CFC97;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000CFC97;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xCFC97u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000CFC97: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFC97u);
    cpu->ebp = lift_load32(cpu->esi + 0x1E4u);
    cpu->edi = lift_load32(cpu->esi + 0x1E8u);
    cpu->ebp += lift_load32(cpu->esi + 0x198u);
    cpu->edi += lift_load32(cpu->esi + 0x19Cu);
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->ebp);
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->edi);
    cpu->eax = lift_load32(cpu->esi + 0x1C4u);
    cpu->eax += cpu->ebp;
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x1C8u);
    cpu->ecx += cpu->edi;
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x1D4u);
    cpu->ecx -= lift_load32(cpu->esi + 0x1D0u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CFD64;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000CFD00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFD00u);
    cpu->eax = lift_load32(cpu->esi + 0x1D0u);
    cpu->eax += lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CFD12;
    cpu->eax = lift_load32(cpu->eax);
    label_000CFD12: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFD12u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Cu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CFD35u); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x1D4u);
    cpu->ecx -= lift_load32(cpu->esi + 0x1D0u);
    cpu->edi += lift_load32(cpu->esi + 0x1E0u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u));
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    ++cpu->ebx;
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->eax)) goto label_000CFD00;
    label_000CFD64: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFD64u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), r=(uint64_t)(0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000CFD88;
    if ((uint8_t)(lift_load8(cpu->esi + 0x8Cu)) >= (uint8_t)(2u)) goto label_000CFD88;
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    sfera_sub_004CE0E0(cpu, stop_address); return;
    label_000CFD88: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFD88u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CFD90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFD90u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x1D4u);
    cpu->ecx -= lift_load32(cpu->esi + 0x1D0u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->edi);
    lift_flags_logic(cpu,0u,32u); cpu->ebp = 0u;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->edi = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0xCu, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000CFE28;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    label_000CFDC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFDC4u);
    cpu->eax = lift_load32(cpu->esi + 0x1D0u);
    cpu->eax += cpu->ebx;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000CFDD4;
    cpu->eax = lift_load32(cpu->eax);
    label_000CFDD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFDD4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CFDEEu); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ebp)) goto label_000CFE00;
    cpu->ebp = cpu->eax;
    label_000CFE00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFE00u);
    cpu->ecx = lift_load32(cpu->esi + 0x1D4u);
    cpu->ecx -= lift_load32(cpu->esi + 0x1D0u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    ++cpu->edi;
    cpu->ecx += cpu->edx;
    cpu->ebx += 0x1Cu;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->ecx)) goto label_000CFDC4;
    cpu->ebx = lift_pop32(cpu);
    label_000CFE28: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFE28u);
    cpu->eax = lift_load32(cpu->esi + 0x1ECu);
    cpu->eax += lift_load32(cpu->esi + 0x1E4u);
    cpu->ecx = lift_load32(cpu->esi + 0x1F0u);
    cpu->ecx += lift_load32(cpu->esi + 0x1E8u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax += cpu->ebp;
    cpu->ecx += lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1E0u, cpu->edx);
    lift_store32(cpu->esi + 0x1C4u, cpu->eax);
    lift_store32(cpu->esi + 0x1C8u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CFE70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFE70u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CFE78u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->eax = 0u;
    lift_store8(cpu->esi + 0x1A0u, cpu->eax & 0xFFu);
    std::construct_at(reinterpret_cast<SphereUI::ToolTipCtrl*>(cpu->esi));
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    lift_store32(cpu->esi + 0x1ACu, cpu->eax);
    lift_store_f32(cpu->esi + 0x1B0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    lift_store32(cpu->esi + 0x1BCu, cpu->eax);
    lift_store8(cpu->esi + 0x1CCu, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x1C0u, 0xFFFFE1u);
    lift_store32(cpu->esi + 0x1D0u, cpu->eax);
    lift_store32(cpu->esi + 0x1D4u, cpu->eax);
    lift_store32(cpu->esi + 0x1D8u, cpu->eax);
    lift_store32(cpu->esi + 0x90u, cpu->eax);
    cpu->eax = 2u;
    cpu->ecx = 1u;
    lift_store8(cpu->esi + 0x8Cu, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x1ECu, cpu->eax);
    lift_store32(cpu->esi + 0x50u, 9u);
    lift_store8(cpu->esi + 0x48u, cpu->ecx & 0xFFu);
    lift_store32(cpu->esi + 0x1C4u, 0x34u);
    lift_store32(cpu->esi + 0x1C8u, 0xCu);
    lift_store32(cpu->esi + 0x1E4u, 3u);
    lift_store32(cpu->esi + 0x1E8u, cpu->ecx);
    lift_store32(cpu->esi + 0x1F0u, cpu->ecx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CFF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFF20u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x95u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\ToolTip.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CFF54u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CFF5Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000CFF78;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CFF76u); lift_push32(cpu, r); sfera_sub_004CFE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    label_000CFF78: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFF78u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4CFF88u); lift_push32(cpu, r); sfera_sub_004C3420(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004CFFA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFFA0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D003B;
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esp + 0x20u, 0xFu);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    lift_store8(cpu->esp + 0xCu, 0u);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000CFFF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4CFFF4u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000CFFF4;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0008u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1D0u);
    lift_store32(cpu->esp + 0x38u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0020u); lift_push32(cpu, r); sfera_sub_004C5A50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0027u); lift_push32(cpu, r); sfera_sub_004CFD90(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x20u)) < (uint32_t)(0x10u)) goto label_000D003B;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0038u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D003B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D003Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0060u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebx + 0x1D4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ebx + 0x1D0u);
    cpu->ecx -= cpu->ebp;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->eax)) goto label_000D00A0;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D009Au); lift_push32(cpu, r); sfera_sub_004CFFA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000D00A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D00A0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000D011C;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    cpu->edx -= cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u) + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->edx) * 4u));
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D00BF;
    cpu->eax = lift_load32(cpu->eax);
    label_000D00BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D00BFu);
    cpu->ecx = cpu->esi;
    label_000D00C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D00C1u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D00E1;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_000D00DD;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D00E1;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000D00C1;
    label_000D00DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D00DDu);
    cpu->eax = 0u;
    goto label_000D00E6;
    label_000D00E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D00E1u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000D00E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D00E6u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D0115;
    cpu->edx = cpu->esi;
    label_000D00EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D00ECu);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000D00F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D00F1u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000D00F1;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->eax) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D010Eu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD0115u); lift_push32(cpu, r); sfera_sub_004CFD90(cpu,r); if (cpu->eip != r) return; }
    label_000D0115: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0115u);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000D011C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D011Cu);
    cpu->edx = (uint32_t)(uintptr_t)"";
    goto label_000D00EC;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0130u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = (uint32_t)(cpu->edx + 0xFFFFF447u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x1F3u)) goto label_000D020B;
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xDACu)) goto label_000D01F4;
    if ((uint32_t)(cpu->eax) > (uint32_t)(3u)) goto label_000D0206;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000D01B9;
        case 1u: goto label_000D0161;
        case 2u: goto label_000D01D0;
        case 3u: goto label_000D01E2;
        default: lift_trap(cpu, 0x4D015Au, "resolved jump-table index out of range"); return;
    }
label_000D0161: ;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x1D4u);
    cpu->esi -= lift_load32(cpu->ecx + 0x1D0u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000D01B1;
    cpu->ecx = lift_load32(cpu->ecx + 0x1D0u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    cpu->eax -= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D01A5;
    cpu->eax = lift_load32(cpu->eax);
    label_000D01A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D01A5u);
    cpu->edx -= cpu->eax;
    label_000D01A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D01A7u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000D01A7;
    label_000D01B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D01B1u);
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000D01B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D01B9u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D01C8u); lift_push32(cpu, r); sfera_sub_004D0060(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000D01D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D01D0u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D01DAu); lift_push32(cpu, r); sfera_sub_004CFFA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000D01E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D01E2u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx + 0x1C0u, cpu->eax);
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000D01F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D01F4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx + 0x90u, cpu->edx);
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000D0206: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0206u);
    cpu->eax = 0u;
    lift_return(cpu, 12u, stop_address); return;
    label_000D020B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D020Bu);
    lift_store32(cpu->esp + 4u, cpu->edx);
    sfera_sub_004D2DD0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0230u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x5Cu);
    cpu->ebp = lift_load32(cpu->esp + 0x60u);
    cpu->edi = lift_load32(cpu->esp + 0x64u);
    cpu->esi = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0280u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x9Cu)) != (uint32_t)(0u)) goto label_000D02A3;
    lift_push32(cpu, 0x66u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\ToolTip.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D029Au); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D02A0u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000D02A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D02A3u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"font");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D02B0u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D02C3;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D02BDu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x8Cu, cpu->eax & 0xFFu);
    label_000D02C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D02C3u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"textColor");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D02D0u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = native_function_address32(&::sscanf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D033E;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD02F4u), LIFT_CODE_TOKEN_RVA(0xD02F2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D02F4u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000D031B;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"ToolTipCtrl::LoadUI(%s,%d,%d) -> Not enough args in 'textcolor'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0312u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0318u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D031B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D031Bu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load8(cpu->esp + 0x14u);
    cpu->edx = lift_load8(cpu->esp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax |= cpu->edx;
    lift_store32(cpu->esi + 0x90u, cpu->eax);
    label_000D033E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D033Eu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"backcolor");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D034Bu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D03B4;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD0369u), LIFT_CODE_TOKEN_RVA(0xD0367u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0369u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000D0390;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edi);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ToolTipCtrl::LoadUI(%s,%d,%d) -> Not enough args in 'backcolor'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0387u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D038Du); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D0390: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0390u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load8(cpu->esp + 0x14u);
    cpu->eax = lift_load8(cpu->esp + 0x1Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->eax;
    lift_store32(cpu->esi + 0x1C0u, cpu->ecx);
    label_000D03B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D03B4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"margin");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D03C1u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D0413;
    cpu->ecx = (uint32_t)(cpu->esi + 0x1F0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x1ECu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x1E8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1E4u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD03ECu), LIFT_CODE_TOKEN_RVA(0xD03EAu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D03ECu);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(4u)) goto label_000D0413;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"ToolTipCtrl::LoadUI(%s,%d,%d) -> Not enough args in 'margin'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D040Au); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0410u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D0413: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0413u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D041Bu); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"toolstr");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0427u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D04E6;
    (void)cpu;
    label_000D0430: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0430u);
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_ui_load_scratch_runtime.tooltip_key);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D043Fu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D04D2;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_ui_load_scratch_runtime.tooltip_key;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0451u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000D045B;
    cpu->ecx = lift_load32(cpu->eax);
    goto label_000D045D;
    label_000D045B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D045Bu);
    cpu->ecx = cpu->eax;
    label_000D045D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D045Du);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000D04D2;
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esp + 0x40u, 0xFu);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x2Cu, cpu->ebx & 0xFFu);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000D0476: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0476u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000D0476;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D048Au); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1D0u);
    lift_store32(cpu->esp + 0x58u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D049Eu); lift_push32(cpu, r); sfera_sub_004C5A50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D04A5u); lift_push32(cpu, r); sfera_sub_004CFD90(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x40u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x54u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D04C1;
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D04BEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D04C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D04C1u);
    lift_store32(cpu->esp + 0x40u, 0xFu);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x2Cu, 0u);
    label_000D04D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D04D2u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"toolstr");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D04DEu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D0430;
    label_000D04E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D04E6u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D04EDu); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D04F9u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0520u);
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000D0658;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1B4u)) == (uint32_t)(0u)) goto label_000D0658;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000D0586;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D0578;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD0578u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000D0578: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0578u);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0xCu);
    cpu->ecx += lift_load32(cpu->esp + 8u);
    label_000D0586: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0586u);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->esp + 8u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x1B4u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    cpu->edx = (uint32_t)(cpu->eax + 4u);
    cpu->edi = (uint32_t)(cpu->eax + 8u);
    lift_push32(cpu, 0u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 0xCu)))));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xDCu);
    { uint64_t l=cpu->esp, r=(uint64_t)(0x10u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edx)))));
    cpu->ecx |= 0xFFFFFFu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, ((double)(((int32_t)(lift_load32(cpu->edi))))) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi)))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edx)))));
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0657u); lift_push32(cpu, r); sfera_sub_004CEE10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_000D0658: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0658u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0670u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1B8u)) == (uint32_t)(cpu->edx)) goto label_000D077F;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_000D06C2;
    cpu->ecx = lift_load32(cpu->edi + 0x9Cu);
    lift_store32(cpu->esp + 8u, cpu->edx);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000D06B4;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD06B4u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000D06B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D06B4u);
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 8u);
    cpu->ecx += lift_load32(cpu->esp + 0xCu);
    label_000D06C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D06C2u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi + 0x30u);
    cpu->ebp += cpu->eax;
    cpu->eax = lift_load32(cpu->edi);
    cpu->ebx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebp) > (int32_t)(uint32_t)(cpu->eax)) goto label_000D0786;
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->ecx += cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000D0786;
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(cpu->eax)) goto label_000D0786;
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000D0786;
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000D0734;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1BCu)) != (uint8_t)(0u)) goto label_000D0734;
    lift_store8(cpu->esi + 0x1BCu, cpu->ecx & 0xFFu);
    lift_store8(cpu->esi + 0x4Au, cpu->ecx & 0xFFu);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->eax -= cpu->ebx;
    cpu->ecx -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x1B8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0732u); lift_push32(cpu, r); sfera_sub_0049D2F0(cpu,r); if (cpu->eip != r) return; }
    goto label_000D075E;
    label_000D0734: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0734u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_000D075E;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1BCu)) == (uint8_t)(0u)) goto label_000D075E;
    cpu->ecx = lift_load32(cpu->esi + 0x1B8u);
    lift_store8(cpu->esi + 0x1BCu, 0u);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->edi);
    cpu->edx -= cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD075Eu); lift_push32(cpu, r); sfera_sub_0049D370(cpu,r); if (cpu->eip != r) return; }
    label_000D075E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D075Eu);
    cpu->eax = lift_load32(cpu->edi + 8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D077C;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edi);
    cpu->ecx -= cpu->ebx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x1B8u);
    cpu->edx -= cpu->ebp;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD077Cu); lift_push32(cpu, r); sfera_sub_0049D470(cpu,r); if (cpu->eip != r) return; }
    label_000D077C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D077Cu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_000D077F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D077Fu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_000D0786: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0786u);
    if ((uint8_t)((lift_load8(cpu->edi + 0xCu)) & (1u)) == 0u) goto label_000D077C;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store8(cpu->esi + 0x4Au, 0u);
    cpu->eax = g_sfera_window_runtime.main_window;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_native_call_return(cpu, (uint32_t)(native_function_address32(&::SetFocus)), LIFT_CODE_TOKEN_VA(0x4D07A0u), stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D07B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D07B0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = 0u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x1B4u)) == (uint32_t)(cpu->eax)) goto label_000D087F;
    if ((uint32_t)(lift_load32(cpu->edi + 0x1B8u)) == (uint32_t)(cpu->eax)) goto label_000D087F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edi + 0x9Cu);
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000D080D;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000D07FF;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD07FFu); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000D07FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D07FFu);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->eax += lift_load32(cpu->esp + 0xCu);
    cpu->ecx += lift_load32(cpu->esp + 0x10u);
    label_000D080D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D080Du);
    cpu->esi = lift_load32(cpu->edi + 0x30u);
    cpu->ebx = lift_load32(cpu->edi + 0x34u);
    cpu->esi += cpu->eax;
    cpu->ebx += cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D081Cu); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D082Au);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(cpu->esi) > (int32_t)(uint32_t)(cpu->eax)) goto label_000D085D;
    cpu->ecx = lift_load32(cpu->edi + 0x28u);
    cpu->ecx += cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000D085D;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(cpu->ecx)) goto label_000D085D;
    cpu->edx = lift_load32(cpu->edi + 0x2Cu);
    cpu->edx += cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000D085D;
    cpu->ecx -= cpu->ebx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x1B8u);
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD085Du); lift_push32(cpu, r); sfera_sub_0049D3F0(cpu,r); if (cpu->eip != r) return; }
    label_000D085D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D085Du);
    cpu->eax = lift_load32(cpu->edi + 0x1B4u);
    cpu->ecx = lift_load32(cpu->eax + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x1B8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0872u); lift_push32(cpu, r); sfera_sub_0049D220(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x1B4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D087Du); lift_push32(cpu, r); sfera_sub_00419BF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D087F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D087Fu);
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0890u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0898u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    std::construct_at(reinterpret_cast<SphereUI::CWebBrowserControl*>(cpu->esi));
    lift_store32(cpu->esi + 0x1A8u, cpu->eax);
    lift_store32(cpu->esi + 0x1ACu, 0xFu);
    lift_store8(cpu->esi + 0x198u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    lift_store8(cpu->esi + 0x1BCu, cpu->eax & 0xFFu);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x50u, 0x13u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D08E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D08E0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::CWebBrowserControl*>(cpu->esi));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1B4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x18u, 1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D0949;
    cpu->edx = 0xA4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D092Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x1B4u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000D0949;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0940u); lift_push32(cpu, r); sfera_sub_00419BB0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0946u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D0949: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0949u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1B8u)) == (uint32_t)(0u)) goto label_000D097B;
    cpu->edx = 0xA6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0961u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x1B8u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000D097B;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0972u); lift_push32(cpu, r); sfera_sub_0049D520(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0978u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D097B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D097Bu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1ACu)) < (uint32_t)(0x10u)) goto label_000D0993;
    cpu->eax = lift_load32(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0990u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D0993: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0993u);
    lift_store32(cpu->esi + 0x1ACu, 0xFu);
    lift_store32(cpu->esi + 0x1A8u, 0u);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi + 0x198u, 0u);
    lift_store32(cpu->esp + 0x18u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D09BDu); lift_push32(cpu, r); sfera_sub_004D37D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D09D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D09D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D09D8u); lift_push32(cpu, r); sfera_sub_004D08E0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000D09E8;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D09E5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D09E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D09E8u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D09F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D09F0u);
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
    cpu->esi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->esi);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0A29u); lift_push32(cpu, r); sfera_sub_004D51A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    std::construct_at(reinterpret_cast<SphereUI::CWebBrowserControl*>(cpu->esi));
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->edi + 0x198u);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0A55u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x1BCu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x1B4u, cpu->ebx);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1B4u)) == (uint32_t)(cpu->ebx)) goto label_000D0AE8;
    cpu->edx = (uint32_t)(cpu->ebx + 0x1Au);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0A7Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0A85u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 3u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D0AB0;
    cpu->ecx = lift_load32(cpu->edi + 0x1B4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0AA1u); lift_push32(cpu, r); sfera_sub_00419F50(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 1u);
    goto label_000D0AE8;
    label_000D0AB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0AB0u);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 1u);
    label_000D0AE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0AE8u);
    lift_store32(cpu->esi + 0x1B8u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1B8u)) == (uint32_t)(cpu->ebx)) goto label_000D0B73;
    cpu->edx = 0x25u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0B09u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0B10u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 6u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D0B3B;
    cpu->edx = lift_load32(cpu->edi + 0x1B8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0B2Cu); lift_push32(cpu, r); sfera_sub_0049D710(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 1u);
    goto label_000D0B73;
    label_000D0B3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0B3Bu);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 1u);
    label_000D0B73: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0B73u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(cpu->ebx)) goto label_000D0B96;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0B88u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD0B96u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000D0B96: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0B96u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0AC1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0AC1u);
    lift_push32(cpu, (uintptr_t)"SphereUI::CWebBrowserControl::CWebBrowserControl(): failed to create bitmap/texture"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0AD0u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 1u);
    cpu->eax = LIFT_CALLBACK(sfera_sub_004D0AE0);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0AE0u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x1B8u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1B8u)) == (uint32_t)(cpu->ebx)) goto label_000D0B73;
    cpu->edx = 0x25u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0B09u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0B10u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 6u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D0B3B;
    cpu->edx = lift_load32(cpu->edi + 0x1B8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0B2Cu); lift_push32(cpu, r); sfera_sub_0049D710(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 1u);
    goto label_000D0B73;
    label_000D0B3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0B3Bu);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 1u);
    label_000D0B73: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0B73u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(cpu->ebx)) goto label_000D0B96;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0B88u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD0B96u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000D0B96: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0B96u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0B4C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0B4Cu);
    lift_push32(cpu, (uintptr_t)"SphereUI::CWebBrowserControl::CWebBrowserControl(): failed to create web browser object"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0B5Bu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 1u);
    cpu->eax = LIFT_CALLBACK(sfera_sub_004D0B6B);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0B6B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0B6Bu);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(cpu->ebx)) goto label_000D0B96;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0B88u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD0B96u); lift_push32(cpu, r); sfera_sub_004D19D0(cpu,r); if (cpu->eip != r) return; }
    label_000D0B96: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0B96u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0BB0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0xBEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0BE3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1C0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0BEDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D0C19;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0C08u); lift_push32(cpu, r); sfera_sub_004D09F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D0C19: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0C19u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0C30u);
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
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->esi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x28u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u)) {
        sfera_sub_004D0D7A(cpu, stop_address);
        return;
    }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0C6Au);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x2Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u)) {
        sfera_sub_004D0D7A(cpu, stop_address);
        return;
    }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0C74u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000D0C96;
    cpu->eax = cpu->edx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000D0C80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0C80u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000D0C80;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x198u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD0C96u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    label_000D0C96: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0C96u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1B4u)) != (uint32_t)(0u)) goto label_000D0D1B;
    cpu->edx = 0x3Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0CB5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0CBCu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 8u, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D0CE8;
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0CD9u); lift_push32(cpu, r); sfera_sub_00419F30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    goto label_000D0D1B;
    label_000D0CE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0CE8u);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x1B4u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    label_000D0D1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0D1Bu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1B8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u)) {
        sfera_sub_004D0D7A(cpu, stop_address);
        return;
    }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0D24u);
    cpu->edx = 0x49u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0D3Au); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0D41u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 8u, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D0D72;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1ACu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x198u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D0D60;
    cpu->edx = lift_load32(cpu->edx);
    label_000D0D60: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0D60u);
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0D70u); lift_push32(cpu, r); sfera_sub_0049D6A0(cpu,r); if (cpu->eip != r) return; }
    goto label_000D0D74;
    label_000D0D72: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0D72u);
    cpu->eax = 0u;
    label_000D0D74: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0D74u);
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    sfera_sub_004D0D7A(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0CF9(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0CF9u);
    lift_push32(cpu, (uintptr_t)"SphereUI::CWebBrowserControl::ProcessInitializeMessage(): failed to create bitmap/texture"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0D08u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    cpu->eax = LIFT_CALLBACK(sfera_sub_004D0D18);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0D18(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0D18u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFECu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1B8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u)) {
        sfera_sub_004D0D7A(cpu, stop_address);
        return;
    }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0D24u);
    cpu->edx = 0x49u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp";
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0D3Au); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0D41u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 8u, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D0D72;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1ACu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x198u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D0D60;
    cpu->edx = lift_load32(cpu->edx);
    label_000D0D60: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0D60u);
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0D70u); lift_push32(cpu, r); sfera_sub_0049D6A0(cpu,r); if (cpu->eip != r) return; }
    goto label_000D0D74;
    label_000D0D72: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0D72u);
    cpu->eax = 0u;
    label_000D0D74: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0D74u);
    lift_store32(cpu->esi + 0x1B8u, cpu->eax);
    sfera_sub_004D0D7A(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0D7A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0D7Au);
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0D93(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0D93u);
    lift_push32(cpu, (uintptr_t)"SphereUI::CWebBrowserControl::ProcessInitializeMessage(): failed to create web browser object"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0DA2u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->eax = LIFT_CALLBACK(sfera_sub_004D0D7A);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0DB0u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->edi + 0x1B8u)) == (uint32_t)(0u)) goto label_000D0DFD;
    cpu->edx = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000D0DFD;
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000D0DD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0DD0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000D0DD0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax);
    cpu->esi = (uint32_t)(cpu->edi + 0x198u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0DE8u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000D0DF0;
    cpu->esi = lift_load32(cpu->esi);
    label_000D0DF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0DF0u);
    cpu->ecx = lift_load32(cpu->edi + 0x1B8u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0DFCu); lift_push32(cpu, r); sfera_sub_0049D590(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    label_000D0DFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0DFDu);
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0E10u);
    cpu->esp -= 0x10Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x11Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x124u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0E43u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"URL");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0E50u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D0E8A;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0E62u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D0E8A;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000D0E70: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0E70u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000D0E70;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD0E8Au); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    label_000D0E8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0E8Au);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0E96u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x10Cu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0EC0u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = (uint32_t)(cpu->edx + 0xFFFFE4A7u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_000D0F30;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000D0ED6;
        case 1u: goto label_000D0EE3;
        case 2u: goto label_000D0EEB;
        case 3u: goto label_000D0EF8;
        case 4u: goto label_000D0F0F;
        default: lift_trap(cpu, 0x4D0ECFu, "resolved jump-table index out of range"); return;
    }
label_000D0ED6: ;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0EE0u); lift_push32(cpu, r); sfera_sub_004D0C30(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 12u, stop_address); return;
    label_000D0EE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0EE3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0EE8u); lift_push32(cpu, r); sfera_sub_004D07B0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 12u, stop_address); return;
    label_000D0EEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0EEBu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0EF5u); lift_push32(cpu, r); sfera_sub_004D0DB0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 12u, stop_address); return;
    label_000D0EF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0EF8u);
    cpu->ecx = lift_load32(cpu->ecx + 0x1B8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D0F07;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD0F07u); lift_push32(cpu, r); sfera_sub_0049D1F0(cpu,r); if (cpu->eip != r) return; }
    label_000D0F07: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0F07u);
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000D0F0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0F0Fu);
    cpu->ecx = lift_load32(cpu->ecx + 0x1B8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D0F07;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0F28u); lift_push32(cpu, r); sfera_sub_0049D200(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000D0F30: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0F30u);
    lift_store32(cpu->esp + 4u, cpu->edx);
    sfera_sub_004D2DD0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0F50u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000D0F57;
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D0F57: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0F57u);
    cpu->ecx = lift_load32(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetDlgItem), LIFT_CODE_TOKEN_VA(0x4D0F5Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0F62u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0F70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0F70u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->edi);
    cpu->esi = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000D0FAE;
    label_000D0F87: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0F87u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) != (uint32_t)(cpu->edx)) goto label_000D0FA8;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->esi + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D0FA0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) - 1u);
    goto label_000D0FAA;
    label_000D0FA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0FA8u);
    cpu->esi = lift_load32(cpu->esi);
    label_000D0FAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0FAAu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000D0F87;
    label_000D0FAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0FAEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D0FC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0FC0u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::PeekMessageA);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD0FD9u), LIFT_CODE_TOKEN_RVA(0xD0FD7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0FD9u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D1046;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::TranslateMessage);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::IsDialogMessageA);
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D0FF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D0FF0u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) == (uint32_t)(0x12u)) goto label_000D104B;
    cpu->eax = g_sfera_win32_dialog_registry.sentinel;
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000D101E;
    label_000D1002: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1002u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->ecx + 0x20u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1010u), LIFT_CODE_TOKEN_RVA(0xD100Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1010u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1030;
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(g_sfera_win32_dialog_registry.sentinel)) goto label_000D1002;
    label_000D101E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D101Eu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0xD1025u), LIFT_CODE_TOKEN_RVA(0xD1023u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1025u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::DispatchMessageA), LIFT_CODE_TOKEN_RVA(0xD102Au));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD1030u);
    label_000D1030: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1030u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD103Fu), LIFT_CODE_TOKEN_RVA(0xD103Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D103Fu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D0FF0;
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000D1046: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1046u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_000D104B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D104Bu);
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_VA(0x4D104Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1053u);
    lift_trap(cpu, 0x4D1053u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1060u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D1090;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_win32_dialog_registry.sentinel;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000D107C;
    label_000D1071: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1071u);
    if ((uint32_t)(lift_load32(cpu->eax + 8u)) == (uint32_t)(cpu->ecx)) goto label_000D1095;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000D1071;
    label_000D107C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D107Cu);
    cpu->eax = cpu->ecx;
    label_000D107E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D107Eu);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(0xAu)) goto label_000D10A1;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::EnableWindow), LIFT_CODE_TOKEN_RVA(0xD108Au));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD1090u);
    label_000D1090: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1090u);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_000D1095: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1095u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D107C;
    cpu->eax = lift_load32(cpu->eax + 0x20u);
    goto label_000D107E;
    label_000D10A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D10A1u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(7u)) goto label_000D10B2;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetFocus), LIFT_CODE_TOKEN_VA(0x4D10A7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D10ADu);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_000D10B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D10B2u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SendMessageA), LIFT_CODE_TOKEN_VA(0x4D10BEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D10C4u);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D10D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D10D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_win32_dialog_registry.sentinel;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000D10FF;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000D10E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D10E0u);
    if ((uint32_t)(lift_load32(cpu->eax + 8u)) == (uint32_t)(cpu->ecx)) goto label_000D10F5;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000D10E0;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SetWindowTextA), LIFT_CODE_TOKEN_VA(0x4D10EDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D10F3u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D10F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D10F5u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D10FF;
    cpu->ecx = lift_load32(cpu->eax + 0x20u);
    label_000D10FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D10FFu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SetWindowTextA), LIFT_CODE_TOKEN_VA(0x4D1101u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1107u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1110u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_win32_dialog_registry.sentinel;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000D1146;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000D1120: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1120u);
    if ((uint32_t)(lift_load32(cpu->eax + 8u)) == (uint32_t)(cpu->ecx)) goto label_000D113C;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000D1120;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetWindowTextA), LIFT_CODE_TOKEN_VA(0x4D1132u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1138u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000D113C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D113Cu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D1146;
    cpu->ecx = lift_load32(cpu->eax + 0x20u);
    label_000D1146: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1146u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetWindowTextA), LIFT_CODE_TOKEN_VA(0x4D114Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1153u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1160u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x34u)) == (uint32_t)(cpu->esi)) goto label_000D118D;
    label_000D1168: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1168u);
    cpu->eax = lift_load32(cpu->ecx + 0x34u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000D1188;
    lift_store32(cpu->ecx + 0x30u, (uint64_t)(lift_load32(cpu->ecx + 0x30u)) + 1u);
    cpu->edx = lift_load32(cpu->ecx + 0x30u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x2Cu)) > (uint32_t)(cpu->edx)) goto label_000D117D;
    lift_store32(cpu->ecx + 0x30u, cpu->esi);
    label_000D117D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D117Du);
    --cpu->eax;
    lift_store32(cpu->ecx + 0x34u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000D1188;
    lift_store32(cpu->ecx + 0x30u, cpu->esi);
    label_000D1188: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1188u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x34u)) != (uint32_t)(cpu->esi)) goto label_000D1168;
    label_000D118D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D118Du);
    lift_store32(cpu->ecx + 0x3Cu, cpu->esi);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D11A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D11A0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x3Cu)) != (uint32_t)(0u)) goto label_000D11B5;
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000D11B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D11B5u);
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D11C3u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D11CB;
    cpu->ecx = lift_load32(cpu->ecx);
    label_000D11CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D11CBu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000D11D7;
    cpu->eax -= cpu->edx;
    label_000D11D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D11D7u);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = 7u;
    lift_movs32(cpu, 1u);
    cpu->eax = lift_load32(cpu->ebp + 0x34u);
    cpu->edx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000D120E;
    lift_store32(cpu->ebp + 0x30u, (uint64_t)(lift_load32(cpu->ebp + 0x30u)) + 1u);
    cpu->ecx = lift_load32(cpu->ebp + 0x30u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x2Cu)) > (uint32_t)(cpu->ecx)) goto label_000D1203;
    lift_store32(cpu->ebp + 0x30u, cpu->edx);
    label_000D1203: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1203u);
    --cpu->eax;
    lift_store32(cpu->ebp + 0x34u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000D120E;
    lift_store32(cpu->ebp + 0x30u, cpu->edx);
    label_000D120E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D120Eu);
    lift_store32(cpu->ebp + 0x3Cu, (uint64_t)(lift_load32(cpu->ebp + 0x3Cu)) - 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1220u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x4D122Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1232u);
    cpu->esi = cpu->eax;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000D12A8;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x30u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0x111u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D125F;
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->edx = cpu->ecx & 0xFFFFu;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x10u), 32u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    goto label_000D127F;
    label_000D125F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D125Fu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) == (uint32_t)(cpu->edi)) goto label_000D126B;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetDlgCtrlID), LIFT_CODE_TOKEN_RVA(0xD1265u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD126Bu);
    label_000D126B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D126Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    label_000D127F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D127Fu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x3Cu)), r=(uint64_t)(0x80u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D1298;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD1298u); lift_push32(cpu, r); sfera_sub_004D1160(cpu,r); if (cpu->eip != r) return; }
    label_000D1298: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1298u);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D12A5u); lift_push32(cpu, r); sfera_sub_004A01D0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x3Cu, (uint64_t)(lift_load32(cpu->esi + 0x3Cu)) + 1u);
    label_000D12A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D12A8u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D12C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D12C0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000D1352;
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    lift_store32(cpu->esp + 4u, cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D12EC;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DestroyWindow), LIFT_CODE_TOKEN_VA(0x4D12D8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D12DEu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x20u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD12ECu); lift_push32(cpu, r); sfera_sub_004D1160(cpu,r); if (cpu->eip != r) return; }
    label_000D12EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D12ECu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_win32_dialog_registry.sentinel;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D12FCu); lift_push32(cpu, r); sfera_sub_004D0F70(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0xA2u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Win32Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D130Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1313u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D131Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x24u, 0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D1338;
    cpu->edx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1335u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D1338: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1338u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D134Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D1352: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1352u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1360u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000D1367;
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D1367: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1367u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D136Du); lift_push32(cpu, r); sfera_sub_004D11A0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1370u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    cpu->ebx = 0u;
    lift_store32(cpu->edi + 0x14u, 0xFu);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_store8(cpu->edi, cpu->ebx & 0xFFu);
    cpu->esi = (uint32_t)(cpu->edi + 0x24u);
    lift_store32(cpu->edi + 0x1Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    lift_store32(cpu->esi, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0x34u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D13C6u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D1400;
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->edi + 0x3Cu, cpu->ebx);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D1400: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1400u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D142Au); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4D142Au, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1430u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1441;
    label_000D143B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D143Bu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000D1441: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1441u);
    lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004D1220));
    cpu->eax = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CreateDialogParamA), LIFT_CODE_TOKEN_VA(0x4D1458u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D145Eu);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D143B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetWindowLongA), LIFT_CODE_TOKEN_VA(0x4D1469u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D146Fu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object;
    lift_push32(cpu, 0x71u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::LoadIconA), LIFT_CODE_TOKEN_VA(0x4D1478u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D147Eu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    lift_push32(cpu, 0xFFFFFFF2u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetClassLongA), LIFT_CODE_TOKEN_VA(0x4D1485u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D148Bu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D14A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D14A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->edx = 0x8Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Win32Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D14D4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D14DBu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D14F9;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D14F5u); lift_push32(cpu, r); sfera_sub_004D1370(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000D14FB;
    label_000D14F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D14F9u);
    cpu->esi = 0u;
    label_000D14FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D14FBu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D150Fu); lift_push32(cpu, r); sfera_sub_004D1430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1580;
    cpu->edx = 0x8Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Win32Interface.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1522u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == 0u) goto label_000D156C;
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D152Eu); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1537u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x24u, 0u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000D1552;
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D154Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D1552: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1552u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1569u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D156C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D156Cu);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D1580: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1580u);
    cpu->eax = g_sfera_win32_dialog_registry.sentinel;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = (uint32_t)(cpu->eax + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_win32_dialog_registry.sentinel;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D159Cu); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= g_sfera_win32_dialog_registry.size;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000D15B7;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD15B7u);
    label_000D15B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D15B7u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_win32_dialog_registry.size, (uint64_t)(g_sfera_win32_dialog_registry.size) + 1u);
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D15E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D15E0u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000D15EA;
    cpu->eax = 0x7FFFFFFFu;
    lift_return(cpu, 0u, stop_address); return;
    label_000D15EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D15EAu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"BUTTON"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD15F9u), LIFT_CODE_TOKEN_RVA(0xD15F7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D15F9u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1607;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1607: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1607u);
    lift_push32(cpu, (uintptr_t)"TEXT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD160Fu), LIFT_CODE_TOKEN_RVA(0xD160Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D160Fu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D161D;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D161D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D161Du);
    lift_push32(cpu, (uintptr_t)"IMAGE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1625u), LIFT_CODE_TOKEN_RVA(0xD1623u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1625u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1633;
    cpu->eax = 3u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1633: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1633u);
    lift_push32(cpu, (uintptr_t)"PROGRESS_BAR"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD163Bu), LIFT_CODE_TOKEN_RVA(0xD1639u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D163Bu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1649;
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1649: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1649u);
    lift_push32(cpu, (uintptr_t)"SCROLL_BAR"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1651u), LIFT_CODE_TOKEN_RVA(0xD164Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1651u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D165F;
    cpu->eax = 5u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D165F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D165Fu);
    lift_push32(cpu, (uintptr_t)"HYPER_TEXT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1667u), LIFT_CODE_TOKEN_RVA(0xD1665u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1667u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1675;
    cpu->eax = 6u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1675: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1675u);
    lift_push32(cpu, (uintptr_t)"CHECKBOX"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD167Du), LIFT_CODE_TOKEN_RVA(0xD167Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D167Du);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D168B;
    cpu->eax = 7u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D168B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D168Bu);
    lift_push32(cpu, (uintptr_t)"RADIOBUTTON"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1693u), LIFT_CODE_TOKEN_RVA(0xD1691u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1693u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D16A1;
    cpu->eax = 8u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D16A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D16A1u);
    lift_push32(cpu, (uintptr_t)"TEXTLIST"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD16A9u), LIFT_CODE_TOKEN_RVA(0xD16A7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D16A9u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D16B7;
    cpu->eax = 0xAu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D16B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D16B7u);
    lift_push32(cpu, (uintptr_t)"SLIDER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD16BFu), LIFT_CODE_TOKEN_RVA(0xD16BDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D16BFu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D16CD;
    cpu->eax = 0xBu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D16CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D16CDu);
    lift_push32(cpu, (uintptr_t)"LISTITEM"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD16D5u), LIFT_CODE_TOKEN_RVA(0xD16D3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D16D5u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D16E3;
    cpu->eax = 0xCu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D16E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D16E3u);
    lift_push32(cpu, (uintptr_t)"EDIT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD16EBu), LIFT_CODE_TOKEN_RVA(0xD16E9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D16EBu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D16F9;
    cpu->eax = 0xDu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D16F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D16F9u);
    lift_push32(cpu, (uintptr_t)"SLOT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1701u), LIFT_CODE_TOKEN_RVA(0xD16FFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1701u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D170F;
    cpu->eax = 0xEu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D170F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D170Fu);
    lift_push32(cpu, (uintptr_t)"SPINBUTTON"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1717u), LIFT_CODE_TOKEN_RVA(0xD1715u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1717u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1725;
    cpu->eax = 0x10u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1725: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1725u);
    lift_push32(cpu, (uintptr_t)"RICHEDIT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD172Du), LIFT_CODE_TOKEN_RVA(0xD172Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D172Du);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D173B;
    cpu->eax = 0x11u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D173B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D173Bu);
    lift_push32(cpu, (uintptr_t)"FILTERLISTCTRL"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1743u), LIFT_CODE_TOKEN_RVA(0xD1741u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1743u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1751;
    cpu->eax = 0x12u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1751: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1751u);
    lift_push32(cpu, (uintptr_t)"WEBBROWSER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1759u), LIFT_CODE_TOKEN_RVA(0xD1757u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1759u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1767;
    cpu->eax = 0x13u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1767: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1767u);
    lift_push32(cpu, (uintptr_t)"MINIMAP"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD176Fu), LIFT_CODE_TOKEN_RVA(0xD176Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D176Fu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D177D;
    cpu->eax = 0x14u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D177D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D177Du);
    lift_push32(cpu, (uintptr_t)"MENULISTCTRL"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1785u), LIFT_CODE_TOKEN_RVA(0xD1783u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1785u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1793;
    cpu->eax = 0x15u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1793: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1793u);
    lift_push32(cpu, (uintptr_t)"HTCHATLISTCTRL"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD179Bu), LIFT_CODE_TOKEN_RVA(0xD1799u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D179Bu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D17A9;
    cpu->eax = 0x16u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D17A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D17A9u);
    lift_push32(cpu, (uintptr_t)"HTEDIT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD17B1u), LIFT_CODE_TOKEN_RVA(0xD17AFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D17B1u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D17BF;
    cpu->eax = 0x17u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D17BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D17BFu);
    lift_push32(cpu, (uintptr_t)"FONTPICKER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD17C7u), LIFT_CODE_TOKEN_RVA(0xD17C5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D17C7u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D17D5;
    cpu->eax = 0x18u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D17D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D17D5u);
    lift_push32(cpu, (uintptr_t)"COLORPICKER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD17DDu), LIFT_CODE_TOKEN_RVA(0xD17DBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D17DDu);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0x7FFFFFE6u;
    cpu->eax += 0x19u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D17F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D17F0u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000D17F7;
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D17F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D17F7u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"ALPHA_IN"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1806u), LIFT_CODE_TOKEN_RVA(0xD1804u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1806u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1814;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1814: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1814u);
    lift_push32(cpu, (uintptr_t)"ALPHA_OUT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD181Cu), LIFT_CODE_TOKEN_RVA(0xD181Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D181Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D182A;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D182A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D182Au);
    lift_push32(cpu, (uintptr_t)"MOVE_LEFT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1832u), LIFT_CODE_TOKEN_RVA(0xD1830u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1832u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1840;
    cpu->eax = 3u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1840: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1840u);
    lift_push32(cpu, (uintptr_t)"MOVE_RIGHT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1848u), LIFT_CODE_TOKEN_RVA(0xD1846u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1848u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1856;
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1856: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1856u);
    lift_push32(cpu, (uintptr_t)"MOVE_TOP"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD185Eu), LIFT_CODE_TOKEN_RVA(0xD185Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D185Eu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D186C;
    cpu->eax = 5u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D186C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D186Cu);
    lift_push32(cpu, (uintptr_t)"MOVE_BOTTOM"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1874u), LIFT_CODE_TOKEN_RVA(0xD1872u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1874u);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFFFAu;
    cpu->eax += 6u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1890u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000D1897;
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D1897: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1897u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"LEFT_X"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD18A6u), LIFT_CODE_TOKEN_RVA(0xD18A4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D18A6u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D18B4;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D18B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D18B4u);
    lift_push32(cpu, (uintptr_t)"CENTER_X"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD18BCu), LIFT_CODE_TOKEN_RVA(0xD18BAu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D18BCu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D18CA;
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D18CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D18CAu);
    lift_push32(cpu, (uintptr_t)"RIGHT_X"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD18D2u), LIFT_CODE_TOKEN_RVA(0xD18D0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D18D2u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D18E0;
    cpu->eax = 8u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D18E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D18E0u);
    lift_push32(cpu, (uintptr_t)"LEFT_Y"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD18E8u), LIFT_CODE_TOKEN_RVA(0xD18E6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D18E8u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D18F6;
    cpu->eax = 0x10u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D18F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D18F6u);
    lift_push32(cpu, (uintptr_t)"CENTER_Y"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD18FEu), LIFT_CODE_TOKEN_RVA(0xD18FCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D18FEu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D190C;
    cpu->eax = 0x20u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D190C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D190Cu);
    lift_push32(cpu, (uintptr_t)"RIGHT_Y"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1914u), LIFT_CODE_TOKEN_RVA(0xD1912u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1914u);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFFC0u;
    cpu->eax += 0x40u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1930u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000D1937;
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D1937: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1937u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"RIGHT_X"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1946u), LIFT_CODE_TOKEN_RVA(0xD1944u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1946u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1954;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1954: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1954u);
    lift_push32(cpu, (uintptr_t)"RIGHT_Y"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD195Cu), LIFT_CODE_TOKEN_RVA(0xD195Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D195Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D196A;
    cpu->eax = 2u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D196A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D196Au);
    lift_push32(cpu, (uintptr_t)"CENTER_X"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1972u), LIFT_CODE_TOKEN_RVA(0xD1970u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1972u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1980;
    cpu->eax = 4u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1980: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1980u);
    lift_push32(cpu, (uintptr_t)"CENTER_Y"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD1988u), LIFT_CODE_TOKEN_RVA(0xD1986u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1988u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D1996;
    cpu->eax = 8u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D1996: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1996u);
    lift_push32(cpu, (uintptr_t)"CENTER"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD199Eu), LIFT_CODE_TOKEN_RVA(0xD199Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D199Eu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D19AC;
    cpu->eax = 0xCu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D19AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D19ACu);
    lift_push32(cpu, (uintptr_t)"RIGHT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD19B4u), LIFT_CODE_TOKEN_RVA(0xD19B2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D19B4u);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFFFDu;
    cpu->eax += 3u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D19D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D19D0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->ecx + 0x9Cu, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D19E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D19E0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx + 0x30u, cpu->eax);
    lift_store32(cpu->ecx + 0x34u, cpu->edx);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1A00u);
    cpu->eax = lift_load32(cpu->ecx + 0x50u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1A10u);
    cpu->eax = lift_load32(cpu->ecx + 0x38u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (8u)) == 0u) goto label_000D1A23;
    cpu->edx = g_sfera_graphics_runtime.display_width;
    cpu->edx -= lift_load32(cpu->ecx + 0x28u);
    lift_store32(cpu->ecx + 0x30u, (uint64_t)(lift_load32(cpu->ecx + 0x30u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    label_000D1A23: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1A23u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0x40u)) == 0u) goto label_000D1A33;
    cpu->edx = g_sfera_graphics_runtime.display_height;
    cpu->edx -= lift_load32(cpu->ecx + 0x2Cu);
    lift_store32(cpu->ecx + 0x34u, (uint64_t)(lift_load32(cpu->ecx + 0x34u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    label_000D1A33: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1A33u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_000D1A45;
    cpu->edx = g_sfera_graphics_runtime.display_width;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ecx + 0x28u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    lift_store32(cpu->ecx + 0x30u, (uint64_t)(lift_load32(cpu->ecx + 0x30u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    label_000D1A45: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1A45u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0x20u)) == 0u) goto label_000D1A56;
    cpu->eax = g_sfera_graphics_runtime.display_height;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ecx + 0x2Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->ecx + 0x34u, (uint64_t)(lift_load32(cpu->ecx + 0x34u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_000D1A56: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1A56u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1A60u);
    cpu->edx = lift_load32(cpu->ecx + 0x38u);
    cpu->eax = lift_load32(cpu->ecx + 0x40u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x44u);
    lift_store32(cpu->ecx + 0x30u, cpu->eax);
    lift_store32(cpu->ecx + 0x34u, cpu->esi);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (8u)) == 0u) goto label_000D1A81;
    cpu->eax -= lift_load32(cpu->ecx + 0x28u);
    cpu->eax += g_sfera_graphics_runtime.display_width;
    lift_store32(cpu->ecx + 0x30u, cpu->eax);
    label_000D1A81: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1A81u);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (0x40u)) == 0u) goto label_000D1A92;
    cpu->esi -= lift_load32(cpu->ecx + 0x2Cu);
    cpu->esi += g_sfera_graphics_runtime.display_height;
    lift_store32(cpu->ecx + 0x34u, cpu->esi);
    label_000D1A92: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1A92u);
    cpu->esi = lift_pop32(cpu);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (4u)) == 0u) goto label_000D1AA5;
    cpu->eax = g_sfera_graphics_runtime.display_width;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ecx + 0x28u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->ecx + 0x30u, (uint64_t)(lift_load32(cpu->ecx + 0x30u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_000D1AA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1AA5u);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (0x20u)) == 0u) goto label_000D1AB8;
    cpu->edx = g_sfera_graphics_runtime.display_height;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ecx + 0x2Cu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    lift_store32(cpu->ecx + 0x34u, (uint64_t)(lift_load32(cpu->ecx + 0x34u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    label_000D1AB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1AB8u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1AC0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x5C6u); lift_push32(cpu, (uintptr_t)"SphereUI::Window::setFont"); lift_push32(cpu, (uintptr_t)"%s():%d font = %d");
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1ADDu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1AE3u); lift_push32(cpu, r); sfera_sub_0042E480(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    lift_store8(cpu->esi + 0x8Cu, cpu->ebx & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1B00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1B00u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load8(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x5CCu); lift_push32(cpu, (uintptr_t)"SphereUI::Window::getFont"); lift_push32(cpu, (uintptr_t)"%s():%d font = %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1B1Fu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1B25u); lift_push32(cpu, r); sfera_sub_0042E480(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load8(cpu->esi + 0x8Cu);
    cpu->esp += 0x14u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1B40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1B40u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load8(cpu->eax);
    --cpu->ecx;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(5u)) goto label_000D1C06;
    lift_push32(cpu, cpu->edi);
    switch ((uint32_t)(cpu->ecx)) {
        case 0u: goto label_000D1B5C;
        case 1u: goto label_000D1B72;
        case 2u: goto label_000D1B94;
        case 3u: goto label_000D1BB8;
        case 4u: goto label_000D1BDA;
        case 5u: goto label_000D1BE8;
        default: lift_trap(cpu, 0x4D1B55u, "resolved jump-table index out of range"); return;
    }
label_000D1B5C: ;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1B6Du);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000D1B72: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1B72u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1B8Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000D1B94: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1B94u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_push32(cpu, cpu->ecx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1BABu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1BB3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000D1BB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1BB8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_push32(cpu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x1Cu))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1BCDu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1BD5u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000D1BDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1BDAu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000D1BF2;
    label_000D1BE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1BE8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x1Cu))));
    label_000D1BF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1BF2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1BF9u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1C05u);
    cpu->edi = lift_pop32(cpu);
    label_000D1C06: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1C06u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1C30u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) != (uint8_t)(0u)) goto label_000D1C4A;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000D1C40: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1C40u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) == (uint8_t)(0u)) goto label_000D1C40;
    label_000D1C4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1C4Au);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1C50u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x170u)) == (uint32_t)(0u)) goto label_000D1CF8;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x170u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1C6Fu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->edi + 8u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->edi + 0xCu)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 8u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10000.0));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->edi + 0x10u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000D1CB2;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000D1CBE;
    label_000D1CB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1CB2u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    goto label_000D1CC0;
    label_000D1CBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1CBEu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000D1CC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1CC0u);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1CCCu); lift_push32(cpu, r); sfera_sub_004D1B40(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, 1.0);
    cpu->edi = lift_pop32(cpu);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000D1CF8;
    cpu->eax = lift_load32(cpu->esi + 0x170u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x20u)) != (uint32_t)(3u)) goto label_000D1CEF;
    lift_store8(cpu->esi + 0xE1u, 1u);
    label_000D1CEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1CEFu);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD1CF8u); lift_push32(cpu, r); sfera_sub_004D1D00(cpu,r); if (cpu->eip != r) return; }
    label_000D1CF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1CF8u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1D00u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = 0u;
    if ((uint8_t)(lift_load8(cpu->edi + 0xE0u)) != (uint8_t)(1u)) goto label_000D1D22;
    lift_x87_push(cpu, 1.0);
    cpu->eax = lift_load32(cpu->edi + 0x170u);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD1D22u); lift_push32(cpu, r); sfera_sub_004D1B40(cpu,r); if (cpu->eip != r) return; }
    label_000D1D22: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1D22u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ebp) > (uint32_t)(3u)) goto label_000D1D62;
    switch ((uint32_t)(cpu->ebp)) {
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
    lift_store32(cpu->edi + 0x170u, cpu->esi);
    lift_store8(cpu->edi + 0xE0u, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000D1D45: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1D45u);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1D54u);
    cpu->esi = (uint32_t)(cpu->edi + 0x120u);
    goto label_000D1D62;
    label_000D1D5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1D5Cu);
    cpu->esi = (uint32_t)(cpu->edi + 0x148u);
    label_000D1D62: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1D62u);
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0u)) goto label_000D1D7E;
    lift_store8(cpu->edi + 0xE0u, 0u);
    lift_store32(cpu->edi + 0x170u, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000D1D7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1D7Eu);
    lift_store8(cpu->edi + 0xE0u, 1u);
    lift_store32(cpu->edi + 0x170u, cpu->esi);
    cpu->eax = lift_load8(cpu->esi);
    cpu->eax += 0xFFFFFFFDu;
    if ((uint32_t)(cpu->eax) > (uint32_t)(3u)) goto label_000D1DB8;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000D1D9D;
        case 1u: goto label_000D1DA2;
        case 2u: goto label_000D1DA7;
        case 3u: goto label_000D1DAC;
        default: lift_trap(cpu, 0x4D1D96u, "resolved jump-table index out of range"); return;
    }
    label_000D1D9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1D9Du);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x30u)))));
    goto label_000D1DB2;
    label_000D1DA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1DA2u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x30u)))));
    goto label_000D1DAF;
    label_000D1DA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1DA7u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x34u)))));
    goto label_000D1DB2;
    label_000D1DAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1DACu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x34u)))));
    label_000D1DAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1DAFu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x14u))));
    label_000D1DB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1DB2u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x18u))));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000D1DB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1DB8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1DBDu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    lift_store32(cpu->esi + 0x20u, cpu->ebp);
    if ((uint32_t)(g_sfera_interface_runtime.sounds_enabled) == (uint32_t)(0u)) goto label_000D1DE7;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"Sounds\\in_winopen.wav";
    if ((uint32_t)(cpu->ebp) == (uint32_t)(1u)) goto label_000D1DE0;
    cpu->ecx = (uint32_t)(uintptr_t)"Sounds\\in_winclose.wav";
    label_000D1DE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1DE0u);
    cpu->edx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD1DE7u); lift_push32(cpu, r); sfera_sub_00498060(cpu,r); if (cpu->eip != r) return; }
    label_000D1DE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1DE7u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1DEEu); lift_push32(cpu, r); sfera_sub_004D1C50(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1E20u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D1E3F;
    lift_store8(cpu->edi + 0x48u, cpu->ebx & 0xFFu);
    lift_store8(cpu->edi + 0xE1u, cpu->ebx & 0xFFu);
    lift_store8(cpu->edi + 0x4Au, 0u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000D1E3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1E3Fu);
    if ((uint8_t)(lift_load8(cpu->edi + 0xE0u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D1E59;
    lift_x87_push(cpu, 1.0);
    cpu->eax = lift_load32(cpu->edi + 0x170u);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD1E59u); lift_push32(cpu, r); sfera_sub_004D1B40(cpu,r); if (cpu->eip != r) return; }
    label_000D1E59: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1E59u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x148u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->edi + 0x148u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D1E7C;
    lift_store8(cpu->edi + 0xE0u, 0u);
    lift_store32(cpu->edi + 0x170u, 0u);
    goto label_000D1EE5;
    label_000D1E7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1E7Cu);
    lift_store8(cpu->edi + 0xE0u, cpu->ebx & 0xFFu);
    lift_store32(cpu->edi + 0x170u, cpu->esi);
    cpu->eax = lift_load8(cpu->esi);
    cpu->eax += 0xFFFFFFFDu;
    if ((uint32_t)(cpu->eax) > (uint32_t)(3u)) goto label_000D1EB5;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000D1E9A;
        case 1u: goto label_000D1E9F;
        case 2u: goto label_000D1EA4;
        case 3u: goto label_000D1EA9;
        default: lift_trap(cpu, 0x4D1E93u, "resolved jump-table index out of range"); return;
    }
label_000D1E9A: ;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x30u)))));
    goto label_000D1EAF;
    label_000D1E9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1E9Fu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x30u)))));
    goto label_000D1EAC;
    label_000D1EA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1EA4u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x34u)))));
    goto label_000D1EAF;
    label_000D1EA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1EA9u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi + 0x34u)))));
    label_000D1EAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1EACu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x14u))));
    label_000D1EAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1EAFu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x18u))));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000D1EB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1EB5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1EBAu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    lift_store32(cpu->esi + 0x20u, 3u);
    if ((uint32_t)(g_sfera_interface_runtime.sounds_enabled) == (uint32_t)(0u)) goto label_000D1EDE;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"Sounds\\in_winclose.wav";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD1EDEu); lift_push32(cpu, r); sfera_sub_00498060(cpu,r); if (cpu->eip != r) return; }
    label_000D1EDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1EDEu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD1EE5u); lift_push32(cpu, r); sfera_sub_004D1C50(cpu,r); if (cpu->eip != r) return; }
    label_000D1EE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1EE5u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0xE0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D1EF5;
    lift_store8(cpu->edi + 0xE1u, cpu->ebx & 0xFFu);
    label_000D1EF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1EF5u);
    lift_store8(cpu->edi + 0x4Au, 0u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D1F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1F10u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D1FFA;
    cpu->ebx = 1u;
    if ((uint8_t)(lift_load8(cpu->esi + 0xE0u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D1F3F;
    lift_x87_push(cpu, 1.0);
    cpu->eax = lift_load32(cpu->esi + 0x170u);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD1F3Fu); lift_push32(cpu, r); sfera_sub_004D1B40(cpu,r); if (cpu->eip != r) return; }
    label_000D1F3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1F3Fu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x148u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x148u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D1F61;
    lift_store8(cpu->esi + 0xE0u, 0u);
    lift_store32(cpu->esi + 0x170u, 0u);
    goto label_000D1FCA;
    label_000D1F61: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1F61u);
    lift_store8(cpu->esi + 0xE0u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x170u, cpu->edi);
    cpu->eax = lift_load8(cpu->edi);
    cpu->eax += 0xFFFFFFFDu;
    if ((uint32_t)(cpu->eax) > (uint32_t)(3u)) goto label_000D1F9A;
    switch ((uint32_t)(cpu->eax)) {
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
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x30u)))));
    goto label_000D1F94;
    label_000D1F84: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1F84u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x30u)))));
    goto label_000D1F91;
    label_000D1F89: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1F89u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x34u)))));
    goto label_000D1F94;
    label_000D1F8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1F8Eu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x34u)))));
    label_000D1F91: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1F91u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0x14u))));
    label_000D1F94: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1F94u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x18u))));
    lift_store_f32(cpu->edi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000D1F9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1F9Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D1F9Fu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 8u, cpu->eax);
    lift_store32(cpu->edi + 0xCu, cpu->edx);
    lift_store32(cpu->edi + 0x20u, 2u);
    if ((uint32_t)(g_sfera_interface_runtime.sounds_enabled) == (uint32_t)(0u)) goto label_000D1FC3;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"Sounds\\in_winclose.wav";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD1FC3u); lift_push32(cpu, r); sfera_sub_00498060(cpu,r); if (cpu->eip != r) return; }
    label_000D1FC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1FC3u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD1FCAu); lift_push32(cpu, r); sfera_sub_004D1C50(cpu,r); if (cpu->eip != r) return; }
    label_000D1FCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1FCAu);
    if ((uint8_t)(lift_load8(cpu->esi + 0xE0u)) != (uint8_t)(0u)) goto label_000D1FEE;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x6Cu);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1FE1u);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 0x11Cu, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000D1FEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1FEEu);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 0x11Cu, cpu->ebx & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000D1FFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D1FFAu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x6Cu);
    lift_store8(cpu->esi + 0x11Cu, 0u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D200Eu);
    cpu->ebx = 1u;
    if ((uint8_t)(lift_load8(cpu->esi + 0xE0u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D202F;
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x170u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD202Fu); lift_push32(cpu, r); sfera_sub_004D1B40(cpu,r); if (cpu->eip != r) return; }
    label_000D202F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D202Fu);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D203Eu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x120u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x120u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D2064;
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 0xE0u, 0u);
    lift_store32(cpu->esi + 0x170u, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000D2064: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2064u);
    lift_store8(cpu->esi + 0xE0u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x170u, cpu->edi);
    cpu->eax = lift_load8(cpu->edi);
    cpu->eax += 0xFFFFFFFDu;
    if ((uint32_t)(cpu->eax) > (uint32_t)(3u)) goto label_000D209D;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000D2082;
        case 1u: goto label_000D2087;
        case 2u: goto label_000D208C;
        case 3u: goto label_000D2091;
        default: lift_trap(cpu, 0x4D207Bu, "resolved jump-table index out of range"); return;
    }
    label_000D2082: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2082u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x30u)))));
    goto label_000D2097;
    label_000D2087: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2087u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x30u)))));
    goto label_000D2094;
    label_000D208C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D208Cu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x34u)))));
    goto label_000D2097;
    label_000D2091: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2091u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x34u)))));
    label_000D2094: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2094u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0x14u))));
    label_000D2097: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2097u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x18u))));
    lift_store_f32(cpu->edi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000D209D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D209Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D20A2u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 8u, cpu->eax);
    lift_store32(cpu->edi + 0xCu, cpu->edx);
    lift_store32(cpu->edi + 0x20u, cpu->ebx);
    if ((uint32_t)(g_sfera_interface_runtime.sounds_enabled) == (uint32_t)(0u)) goto label_000D20C2;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"Sounds\\in_winopen.wav";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD20C2u); lift_push32(cpu, r); sfera_sub_00498060(cpu,r); if (cpu->eip != r) return; }
    label_000D20C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D20C2u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D20C9u); lift_push32(cpu, r); sfera_sub_004D1C50(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D20F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D20F0u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D2134;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D2110: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2110u);
    cpu->esi = lift_load32(cpu->eax + 0xCu);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_000D211C;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_000D212C;
    label_000D211C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D211Cu);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) == (uint8_t)(0u)) goto label_000D2128;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->esi)) goto label_000D2128;
    cpu->edx = cpu->eax;
    label_000D2128: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2128u);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_000D212C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D212Cu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) == (uint8_t)(0u)) goto label_000D2110;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000D2134: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2134u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) == (uint8_t)(0u)) goto label_000D2142;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_000D2144;
    label_000D2142: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2142u);
    cpu->eax = lift_load32(cpu->edx);
    label_000D2144: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2144u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) != (uint8_t)(0u)) goto label_000D2164;
    cpu->ecx = lift_load32(cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000D2150: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2150u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(lift_load32(cpu->eax + 0xCu))) goto label_000D215B;
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    goto label_000D215E;
    label_000D215B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D215Bu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    label_000D215E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D215Eu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) == (uint8_t)(0u)) goto label_000D2150;
    label_000D2164: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2164u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D2180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2180u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x3FFFFFFEu)) goto label_000D21A2;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2194u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"map/set<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD21A2u);
    label_000D21A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D21A2u);
    ++cpu->eax;
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000D21CC;
    lift_store32(cpu->edx + 4u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx, cpu->ebp);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    goto label_000D21ED;
    label_000D21CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D21CCu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x10u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D21DF;
    lift_store32(cpu->eax, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_000D21ED;
    lift_store32(cpu->edx, cpu->ebp);
    goto label_000D21ED;
    label_000D21DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D21DFu);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_000D21ED;
    lift_store32(cpu->edx + 8u, cpu->ebp);
    label_000D21ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D21EDu);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if ((uint8_t)(lift_load8(cpu->edx + 0x10u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D238E;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000D2200: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2200u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi))) goto label_000D22CF;
    cpu->esi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x10u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D2232;
    lift_store8(cpu->edx + 0x10u, 1u);
    lift_store8(cpu->esi + 0x10u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x10u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_000D2380;
    label_000D2232: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2232u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_000D2271;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    if ((uint8_t)(lift_load8(cpu->esi + 0x11u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D224B;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000D224B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D224Bu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000D225E;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_000D226C;
    label_000D225E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D225Eu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi))) goto label_000D2269;
    lift_store32(cpu->esi, cpu->edx);
    goto label_000D226C;
    label_000D2269: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2269u);
    lift_store32(cpu->esi + 8u, cpu->edx);
    label_000D226C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D226Cu);
    lift_store32(cpu->edx, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_000D2271: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2271u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x10u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x10u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->edx, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x11u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D2299;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_000D2299: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2299u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_000D22B2;
    lift_store32(cpu->edi + 4u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000D237D;
    label_000D22B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D22B2u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_000D22C5;
    lift_store32(cpu->edi + 8u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000D237D;
    label_000D22C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D22C5u);
    lift_store32(cpu->edi, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000D237D;
    label_000D22CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D22CFu);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->esi + 0x10u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D22F2;
    lift_store8(cpu->edx + 0x10u, 1u);
    lift_store8(cpu->esi + 0x10u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x10u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_000D2380;
    label_000D22F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D22F2u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_000D2332;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x11u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D230A;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000D230A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D230Au);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000D231D;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_000D232C;
    label_000D231D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D231Du);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000D232A;
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000D232C;
    label_000D232A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D232Au);
    lift_store32(cpu->esi, cpu->edx);
    label_000D232C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D232Cu);
    lift_store32(cpu->edx + 8u, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_000D2332: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2332u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x10u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x10u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx + 8u);
    cpu->edi = lift_load32(cpu->esi);
    lift_store32(cpu->edx + 8u, cpu->edi);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->edi + 0x11u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D235A;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_000D235A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D235Au);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_000D236D;
    lift_store32(cpu->edi + 4u, cpu->esi);
    goto label_000D237B;
    label_000D236D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D236Du);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_000D2378;
    lift_store32(cpu->edi, cpu->esi);
    goto label_000D237B;
    label_000D2378: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2378u);
    lift_store32(cpu->edi + 8u, cpu->esi);
    label_000D237B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D237Bu);
    lift_store32(cpu->esi, cpu->edx);
    label_000D237D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D237Du);
    lift_store32(cpu->edx + 4u, cpu->esi);
    label_000D2380: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2380u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x10u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D2200;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000D238E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D238Eu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->ecx + 0x10u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D23B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D23B0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x14u);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D23BDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000D23F1;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 0xCu);
    lift_store16(cpu->eax + 0x10u, cpu->edx & 0xFFFFu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000D23EA;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_000D23EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D23EAu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000D23F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D23F1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D241Bu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4D241Bu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D2420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2420u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0xCu);
    lift_store32(cpu->esi + 4u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2434u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D244B;
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D244B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D244Bu);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 8u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2479u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4D2479u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D2480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2480u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D24CD;
    cpu->edx = lift_load32(cpu->ebx + 0xCu);
    label_000D24A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D24A1u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D24B2;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0xCu)), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000D24B8;
    label_000D24B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D24B2u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0xCu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_000D24B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D24B8u);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_000D24C4;
    cpu->eax = lift_load32(cpu->eax);
    goto label_000D24C7;
    label_000D24C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D24C4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    label_000D24C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D24C7u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) == (uint8_t)(0u)) goto label_000D24A1;
    label_000D24CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D24CDu);
    cpu->edi = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_000D250A;
    cpu->eax = lift_load32(cpu->ebp + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax))) goto label_000D2501;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D24EEu); lift_push32(cpu, r); sfera_sub_004D2180(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000D2501: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2501u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2506u); lift_push32(cpu, r); sfera_sub_00402140(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    label_000D250A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D250Au);
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->ebx + 0xCu))) goto label_000D2538;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2525u); lift_push32(cpu, r); sfera_sub_004D2180(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000D2538: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2538u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D253Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->esp += 4u;
    lift_store32(cpu->eax, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D2560(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2560u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0xF4u);
    lift_store32(cpu->esp + 8u, cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D2581;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D257Du); lift_push32(cpu, r); sfera_sub_004D2560(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D25C5;
    label_000D2581: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2581u);
    cpu->eax = lift_load32(cpu->esi + 0x174u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D2591;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000D2591: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2591u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000D25C1;
    cpu->ebp = native_function_address32(&::_stricmp);
    label_000D25A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D25A1u);
    cpu->edi = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0xD25AAu), LIFT_CODE_TOKEN_RVA(0xD25A8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D25AAu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D25CB;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->esi = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->eax + 0x174u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->ecx))) goto label_000D25A1;
    label_000D25C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D25C1u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    label_000D25C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D25C5u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000D25CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D25CBu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D25E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D25E0u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000D2809;
    cpu->eax = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x9Cu)) == (uint32_t)(cpu->eax)) goto label_000D2608;
    cpu->eax = lift_load32(cpu->esi + 0x9Cu);
    cpu->ecx = lift_load32(cpu->eax + 0x30u);
    cpu->eax = lift_load32(cpu->eax + 0x34u);
    label_000D2608: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2608u);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    cpu->edx += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->ecx += cpu->eax;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x24u)), r=(uint64_t)(2u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D2671;
    cpu->ecx = lift_load32(cpu->esi + 0x194u);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D2671;
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->eax |= 0xFFFFFFu;
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->ecx + 0x3Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ecx + 0x7Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x194u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD2671u); lift_push32(cpu, r); sfera_sub_004CE140(cpu,r); if (cpu->eip != r) return; }
    label_000D2671: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2671u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x24u)), r=(uint64_t)(4u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D27E8;
    if ((uint32_t)(lift_load32(cpu->esi + 0x64u)) <= (uint32_t)(0u)) goto label_000D27E8;
    cpu->edx = lift_load8(cpu->esi + 0x8Cu);
    cpu->edi = lift_load32(cpu->esi + 0x104u);
    cpu->edi -= lift_load32(cpu->esi + 0xFCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi + 0x108u);
    cpu->ebp -= lift_load32(cpu->esi + 0x100u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x68u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (uint32_t)(cpu->esi + 0x54u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D26B8;
    cpu->ecx = lift_load32(cpu->ebx);
    goto label_000D26BA;
    label_000D26B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D26B8u);
    cpu->ecx = cpu->ebx;
    label_000D26BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D26BAu);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load8(cpu->esi + 0x8Du);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D26D1u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) <= (uint32_t)(cpu->edi)) goto label_000D2731;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = 2u;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D26EA;
    cpu->ecx = lift_load32(cpu->ebx);
    goto label_000D26EC;
    label_000D26EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D26EAu);
    cpu->ecx = cpu->ebx;
    label_000D26EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D26ECu);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load8(cpu->esi + 0x8Du);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2703u); lift_push32(cpu, r); sfera_sub_0045AE50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0xE8u)))));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esp + 0x24u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x100u))))));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000D272D;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000D272D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D272Du);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000D2741;
    label_000D2731: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2731u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0xE8u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x100u))))));
    label_000D2741: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2741u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2746u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_screen_clip_runtime.top = (uint32_t)(cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0xE4u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0xFCu))))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2760u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_screen_clip_runtime.top;
    cpu->edx = (uint32_t)(cpu->eax + cpu->edi + 0xAu);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->edx);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->ebp + 0xAu);
    cpu->ebp = 0xFFu;
    g_sfera_screen_clip_runtime.left = (uint32_t)(cpu->eax);
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->edx);
    if ((uint32_t)(lift_load32(cpu->esi + 0xDCu)) != (uint32_t)(cpu->ebp)) goto label_000D27A1;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(2u)) goto label_000D27A1;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D279Cu); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_screen_clip_runtime.left;
    label_000D27A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D27A1u);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x14u)) < (uint32_t)(0x10u)) goto label_000D27A9;
    cpu->ebx = lift_load32(cpu->ebx);
    label_000D27A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D27A9u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x8Du);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_screen_clip_runtime.top;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D27CFu); lift_push32(cpu, r); sfera_sub_0044CD30(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xDCu)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D27E8;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(2u)) goto label_000D27E8;
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD27E8u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_000D27E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D27E8u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->edi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000D2808;
    label_000D27F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D27F4u);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D27FEu);
    cpu->edi = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0xA0u))) goto label_000D27F4;
    label_000D2808: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2808u);
    cpu->edi = lift_pop32(cpu);
    label_000D2809: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2809u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D2810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2810u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 0xA0u);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000D284B;
    label_000D2820: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2820u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 0xECu)) == (uint32_t)(0u)) goto label_000D2841;
    if ((uint8_t)(lift_load8(cpu->eax + 0x48u)) != (uint8_t)(0u)) goto label_000D2841;
    cpu->eax = lift_load32(cpu->eax + 0xECu);
    cpu->ecx = cpu->eax;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    label_000D2841: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2841u);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->edi + 0xA0u))) goto label_000D2820;
    label_000D284B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D284Bu);
    cpu->eax = lift_load32(cpu->edi + 0xF0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D2866;
    if ((uint8_t)(lift_load8(cpu->eax + 0x48u)) != (uint8_t)(0u)) goto label_000D2866;
    cpu->ecx = cpu->eax;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw(cpu);
    lift_return(cpu, 0u, stop_address); return;
    label_000D2866: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2866u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D2870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2870u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D2883;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD2883u); lift_push32(cpu, r); sfera_sub_004CF750(cpu,r); if (cpu->eip != r) return; }
    label_000D2883: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2883u);
    cpu->eax = lift_load32(cpu->edi + 0xA0u);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000D28A2;
    (void)cpu;
    label_000D2890: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2890u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2898u); lift_push32(cpu, r); sfera_sub_004D2870(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->edi + 0xA0u))) goto label_000D2890;
    label_000D28A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D28A2u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D28B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D28B0u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Au)) == (uint8_t)(0u)) goto label_000D2A32;
    if ((uint8_t)(lift_load8(cpu->esi + 0x11Cu)) == (uint8_t)(0u)) goto label_000D28ED;
    if ((uint8_t)(lift_load8(cpu->esi + 0xE0u)) != (uint8_t)(0u)) goto label_000D28ED;

    lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, 0x6Cu);
    lift_store8(cpu->esi + 0x11Cu, 0u);
    reinterpret_cast<SphereUI::Window*>(cpu->esi)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D28E6u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
    label_000D28ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D28EDu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0xCu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D2998;
    cpu->ebp = lift_load32(cpu->esi + 0xFCu);
    cpu->edi = lift_load32(cpu->esi + 0x104u);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->edi)) goto label_000D2998;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000D2935;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD2935u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000D2935: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2935u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esi + 0x100u);
    cpu->ebx = lift_load32(cpu->ebx);
    cpu->edi += cpu->eax;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x108u);
    cpu->ebp += cpu->eax;
    cpu->edx += cpu->ecx;
    cpu->edi += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_000D2994;
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_000D2994;
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    cpu->ebp = lift_load32(cpu->ebp + 4u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(cpu->edx)) goto label_000D2994;
    if ((int32_t)(uint32_t)(cpu->ebp) > (int32_t)(uint32_t)(cpu->edi)) goto label_000D2994;
    cpu->eax -= cpu->ebx;
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esi + 0x110u, cpu->eax);
    cpu->ecx -= lift_load32(cpu->ebx + 4u);
    lift_store8(cpu->esi + 0x10Cu, 1u);
    lift_store32(cpu->esi + 0x114u, cpu->ecx);
    goto label_000D2998;
    label_000D2994: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2994u);
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    label_000D2998: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2998u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x10Cu)) == (uint8_t)(0u)) goto label_000D29D2;
    cpu->eax = lift_load32(cpu->esi + 0x110u);
    cpu->eax += lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->esi + 0x114u);
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    cpu->ecx += lift_load32(cpu->ebx + 4u);
    lift_store32(cpu->esi + 0x34u, cpu->ecx);
    if ((uint8_t)((lift_load8(cpu->ebx + 0xCu)) & (4u)) == 0u) goto label_000D29D2;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x4Eu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store8(cpu->esi + 0x10Cu, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D29D2;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD29D2u); lift_push32(cpu, r); sfera_sub_004BC5F0(cpu,r); if (cpu->eip != r) return; }
    label_000D29D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D29D2u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->ebp = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->eax)) goto label_000D2A15;
    cpu->edi = cpu->edi;
    label_000D29E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D29E0u);
    cpu->edi = lift_load32(cpu->ebp + 8u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x49u)) != (uint8_t)(0u)) goto label_000D2A0A;
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_000D2A00;
    cpu->ecx = lift_load32(cpu->edi + 0xECu);
    lift_push32(cpu, cpu->ebx);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000D2A00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2A00u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000D2A0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2A0Au);
    cpu->ebp = lift_load32(cpu->ebp);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->esi + 0xA0u))) goto label_000D29E0;
    label_000D2A15: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2A15u);
    cpu->esi = lift_load32(cpu->esi + 0xF0u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000D2A2F;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000D2A2F;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(cpu);
    label_000D2A2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2A2Fu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D2A32: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2A32u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D2A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2A40u);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->esi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    cpu->esi = cpu->ecx;
    lift_store16(cpu->esp + 6u, cpu->fpu_control);
    lift_push32(cpu, cpu->edi);
    cpu->eax = lift_load16(cpu->esp + 0xAu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xC00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0xCu));
    lift_store64(cpu->esp + 0xCu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    cpu->edx = lift_load32(cpu->esi + 0x98u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0xAu));
    lift_store32(cpu->esi + 0xDCu, cpu->eax);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->ecx &= 0xFFFFFFu;
    cpu->edx &= 0xFFFFFFu;
    cpu->ecx |= cpu->eax;
    cpu->edx |= cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    lift_store32(cpu->esi + 0x90u, cpu->ecx);
    lift_store32(cpu->esi + 0x98u, cpu->edx);
    cpu->edi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000D2ACC;
    label_000D2AB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2AB0u);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setOpacity(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2AC2u);
    cpu->edi = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0xA0u))) goto label_000D2AB0;
    label_000D2ACC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2ACCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D2AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2AE0u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->ecx + 0xA0u);
    lift_store32(cpu->esp + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esp, cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000D2B6E;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    label_000D2B06: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2B06u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x3Cu)) == (uint32_t)(cpu->edi)) goto label_000D2B17;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000D2B54;
    label_000D2B17: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2B17u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(lift_load32(cpu->esi + 0x50u))) goto label_000D2B24;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0x7FFFFFFFu)) goto label_000D2B38;
    label_000D2B24: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2B24u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    label_000D2B38: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2B38u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x50u)) != (uint32_t)(0xCu)) goto label_000D2B54;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->dispatchMessage(cpu);
    label_000D2B54: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2B54u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 0xA0u))) goto label_000D2B06;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D2B6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2B6Eu);
    cpu->esp += 8u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D2B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2B80u);
    lift_push32(cpu, cpu->ecx);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x48u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D2B90;
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000D2B90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2B90u);
    cpu->eax = lift_load32(cpu->ecx + 0xA0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->eax)) goto label_000D2C21;
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D2BB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2BB0u);
    cpu->esi = lift_load32(cpu->ebx + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Cu)) == (uint8_t)(0u)) goto label_000D2C13;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000D2BDC;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD2BDCu); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000D2BDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2BDCu);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(cpu->edi)) goto label_000D2C13;
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000D2C13;
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(cpu->ebp)) goto label_000D2C13;
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000D2C13;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->hitTest(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2C0Fu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D2C21;
    label_000D2C13: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2C13u);
    cpu->ebx = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(lift_load32(cpu->ecx + 0xA0u))) goto label_000D2BB0;
    label_000D2C21: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2C21u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D2C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2C30u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = 0u;
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)((cpu->eax & 0xFFu))) goto label_000D2D15;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000D2C62;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD2C62u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000D2C62: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2C62u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(cpu->edi)) goto label_000D2C94;
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000D2C94;
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(cpu->ebp)) goto label_000D2C94;
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->eax)) goto label_000D2CA0;
    label_000D2C94: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2C94u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
    label_000D2CA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2CA0u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000D2D10;
    label_000D2CB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2CB1u);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->ebx + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x48u)) != (uint8_t)(0u)) goto label_000D2D08;
    cpu->ecx = lift_load32(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000D2CE0;
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD2CE0u); lift_push32(cpu, r); sfera_sub_0049EC80(cpu,r); if (cpu->eip != r) return; }
    label_000D2CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2CE0u);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->eax += lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->ecx += lift_load32(cpu->esp + 0x20u);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(cpu->edi)) goto label_000D2D08;
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000D2D08;
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(cpu->ebp)) goto label_000D2D08;
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->eax)) goto label_000D2D1C;
    label_000D2D08: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2D08u);
    cpu->eax = cpu->ebx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000D2CB1;
    label_000D2D10: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2D10u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    label_000D2D15: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2D15u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
    label_000D2D1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2D1Cu);
    cpu->eax = lift_load32(cpu->esi + 0xD8u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D2D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2D30u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D2D5A;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edi);
    label_000D2D45: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2D45u);
    if ((uint32_t)(lift_load32(cpu->eax + 0xCu)) >= (uint32_t)(cpu->esi)) goto label_000D2D4F;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_000D2D53;
    label_000D2D4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2D4Fu);
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_000D2D53: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2D53u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) == (uint8_t)(0u)) goto label_000D2D45;
    cpu->esi = lift_pop32(cpu);
    label_000D2D5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2D5Au);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->eax)) goto label_000D2D7D;
    cpu->ecx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->edx + 0xCu))) goto label_000D2D7D;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000D2D7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2D7Du);
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D2DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2DA0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2DB5u); lift_push32(cpu, r); sfera_sub_004D2D30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 4u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D2DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2DD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFF447u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x1F3u)) goto label_000D2E8C;
    if ((uint32_t)(lift_load32(cpu->esi + 0xECu)) != (uint32_t)(0u)) goto label_000D2E60;
    cpu->edx = 0x1C9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2E24u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2E2Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D2E4A;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2E48u); lift_push32(cpu, r); sfera_sub_004CFE70(cpu,r); if (cpu->eip != r) return; }
    goto label_000D2E4C;
    label_000D2E4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2E4Au);
    cpu->eax = 0u;
    label_000D2E4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2E4Cu);
    lift_store32(cpu->esi + 0xECu, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x9Cu, cpu->esi);
    label_000D2E60: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2E60u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esi + 0xECu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2E78u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 12u, stop_address); return;
    label_000D2E8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2E8Cu);
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFFF97u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x12u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000D301A;
    switch ((uint32_t)(cpu->eax)) {
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
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xB8u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->ecx, cpu->eax);
    goto label_000D301A;
    label_000D2EB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2EB5u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xB8u)) != (uint32_t)(0u)) goto label_000D301A;
    cpu->edx = lift_load32(cpu->esp + 0x28u);

    lift_push32(cpu, 0u); lift_push32(cpu, 1u);
    lift_store32(cpu->esi + 0xB8u, cpu->edx);

    lift_push32(cpu, 0x73u);
    reinterpret_cast<SphereUI::Window*>(cpu->esi)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2ED9u);
    goto label_000D301A;
    label_000D2EDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2EDEu);
    if ((uint32_t)(lift_load32(cpu->esi + 0xB8u)) == (uint32_t)(0u)) goto label_000D301A;

    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x73u);
    lift_store32(cpu->esi + 0xB8u, 0u);
    reinterpret_cast<SphereUI::Window*>(cpu->esi)->handleMessage(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2F02u);
    goto label_000D301A;
    label_000D2F07: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2F07u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x28u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esi + 0x4Au, cpu->eax & 0xFFu);
    goto label_000D301A;
    label_000D2F17: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2F17u);
    cpu->ecx = lift_load8(cpu->esi + 0x4Au);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->edx, cpu->ecx);
    goto label_000D301A;
    label_000D2F26: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2F26u);
    cpu->eax = lift_load32(cpu->esi + 0xDCu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->ecx &= 0xFFFFFFu;
    cpu->eax |= cpu->ecx;
    lift_store32(cpu->esi + 0x90u, cpu->eax);
    goto label_000D301A;
    label_000D2F46: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2F46u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x28u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esi + 0x48u, cpu->eax & 0xFFu);
    label_000D2F51: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2F51u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000D301A;
    cpu->ecx = lift_load32(cpu->esi + 0xECu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D301A;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2F6Cu); lift_push32(cpu, r); sfera_sub_004CF750(cpu,r); if (cpu->eip != r) return; }
    goto label_000D301A;
    label_000D2F71: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2F71u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x28u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = cpu->edx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2F82u); lift_push32(cpu, r); sfera_sub_004D1F10(cpu,r); if (cpu->eip != r) return; }
    goto label_000D301A;
    label_000D2F87: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2F87u);
    cpu->ecx = lift_load8(cpu->esi + 0x48u);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->edx, cpu->ecx);
    goto label_000D301A;
    label_000D2F96: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2F96u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x28u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esi + 0x49u, cpu->eax & 0xFFu);
    goto label_000D2F51;
    label_000D2FA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2FA3u);
    cpu->eax = lift_load8(cpu->esi + 0x49u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->ecx, cpu->eax);
    goto label_000D301A;
    label_000D2FAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2FAFu);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esi + 0x118u, cpu->edx);
    goto label_000D301A;
    label_000D2FBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2FBBu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);

    cpu->edx = lift_load32(cpu->esp + 0x28u);

    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->esi)->setPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2FCEu);
    goto label_000D301A;
    label_000D2FD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2FD0u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esi + 0x28u, cpu->ecx);
    lift_store32(cpu->esi + 0x2Cu, cpu->edx);
    goto label_000D301A;
    label_000D2FE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2FE0u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);

    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->esi)->setFont(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2FEEu);
    goto label_000D301A;
    label_000D2FF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2FF0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D2FF5u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3003u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3014u); lift_push32(cpu, r); sfera_sub_004D2C30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->edx, cpu->eax);
    label_000D301A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D301Au);
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D3080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3080u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->ecx + 0xCCu)) == (uint32_t)(cpu->esi)) goto label_000D30CD;
    label_000D3090: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3090u);
    cpu->eax = lift_load32(cpu->ecx + 0xCCu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000D30C5;
    lift_store32(cpu->ecx + 0xC8u, (uint64_t)(lift_load32(cpu->ecx + 0xC8u)) + 1u);
    cpu->edx = lift_load32(cpu->ecx + 0xC8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xC4u)) > (uint32_t)(cpu->edx)) goto label_000D30B4;
    lift_store32(cpu->ecx + 0xC8u, cpu->esi);
    label_000D30B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D30B4u);
    --cpu->eax;
    lift_store32(cpu->ecx + 0xCCu, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000D30C5;
    lift_store32(cpu->ecx + 0xC8u, cpu->esi);
    label_000D30C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D30C5u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0xCCu)) != (uint32_t)(cpu->esi)) goto label_000D3090;
    label_000D30CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D30CDu);
    lift_store32(cpu->ecx + 0xD4u, cpu->esi);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D30E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D30E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    lift_store32(cpu->esi + 4u, 0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi))) goto label_000D3112;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000D3100: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3100u);
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3108u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi))) goto label_000D3100;
    cpu->edi = lift_pop32(cpu);
    label_000D3112: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3112u);
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D311Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000D312D;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D312Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D312D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D312Du);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D3140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3140u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3170u); lift_push32(cpu, r); sfera_sub_004D2560(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_000D3272;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3181u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000D3270;
    cpu->edx = 0x188u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3199u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x98u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D31A3u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D31BB;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D31B9u); lift_push32(cpu, r); sfera_sub_004CDF00(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    label_000D31BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D31BBu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D31CFu); lift_push32(cpu, r); sfera_sub_004CF1A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x174u)) != (uint32_t)(0u)) goto label_000D321A;
    cpu->edx = 0x18Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D31E7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D31EEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D320A;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3208u); lift_push32(cpu, r); sfera_sub_004D2420(cpu,r); if (cpu->eip != r) return; }
    goto label_000D320C;
    label_000D320A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D320Au);
    cpu->eax = 0u;
    label_000D320C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D320Cu);
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x174u, cpu->eax);
    label_000D321A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D321Au);
    cpu->esi = lift_load32(cpu->esi + 0x174u);
    cpu->edi = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3233u); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000D324D;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD324Du);
    label_000D324D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D324Du);
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = cpu->ebx;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
    label_000D3270: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3270u);
    cpu->eax = 0u;
    label_000D3272: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3272u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D3290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3290u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0xD4u)) < (uint32_t)(0x40u)) goto label_000D32A1;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD32A1u); lift_push32(cpu, r); sfera_sub_004D3080(cpu,r); if (cpu->eip != r) return; }
    label_000D32A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D32A1u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0xBCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D32B1u); lift_push32(cpu, r); sfera_sub_004A01D0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xD4u, (uint64_t)(lift_load32(cpu->esi + 0xD4u)) + 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D32C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D32C0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xD4u)) != (uint32_t)(0u)) goto label_000D32D8;
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000D32D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D32D8u);
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xBCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D32E9u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D32F1;
    cpu->ecx = lift_load32(cpu->ecx);
    label_000D32F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D32F1u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000D32FD;
    cpu->eax -= cpu->edx;
    label_000D32FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D32FDu);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = 7u;
    lift_movs32(cpu, 1u);
    cpu->eax = lift_load32(cpu->ebp + 0xCCu);
    cpu->edx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000D3349;
    lift_store32(cpu->ebp + 0xC8u, (uint64_t)(lift_load32(cpu->ebp + 0xC8u)) + 1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xC8u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xC4u)) > (uint32_t)(cpu->ecx)) goto label_000D3338;
    lift_store32(cpu->ebp + 0xC8u, cpu->edx);
    label_000D3338: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3338u);
    --cpu->eax;
    lift_store32(cpu->ebp + 0xCCu, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000D3349;
    lift_store32(cpu->ebp + 0xC8u, cpu->edx);
    label_000D3349: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3349u);
    lift_store32(cpu->ebp + 0xD4u, (uint64_t)(lift_load32(cpu->ebp + 0xD4u)) - 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D3360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3360u);
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xF8u)) == (uint32_t)(0u)) goto label_000D3416;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000D3381: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3381u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xD4u)) == (uint32_t)(0u)) goto label_000D3413;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xBCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D339Eu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D33A6;
    cpu->ecx = lift_load32(cpu->ecx);
    label_000D33A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D33A6u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000D33B2;
    cpu->eax -= cpu->edx;
    label_000D33B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D33B2u);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->ebp + 0xCCu);
    cpu->edx = 0u;
    cpu->ecx = 7u;
    cpu->edi = (uint32_t)(cpu->esp + 0x1Cu);
    lift_movs32(cpu, 1u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000D33FA;
    lift_store32(cpu->ebp + 0xC8u, (uint64_t)(lift_load32(cpu->ebp + 0xC8u)) + 1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xC8u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xC4u)) > (uint32_t)(cpu->ecx)) goto label_000D33E9;
    lift_store32(cpu->ebp + 0xC8u, cpu->edx);
    label_000D33E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D33E9u);
    --cpu->eax;
    lift_store32(cpu->ebp + 0xCCu, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000D33FA;
    lift_store32(cpu->ebp + 0xC8u, cpu->edx);
    label_000D33FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D33FAu);
    cpu->eax = lift_load32(cpu->ebp + 0xF8u);
    lift_store32(cpu->ebp + 0xD4u, (uint64_t)(lift_load32(cpu->ebp + 0xD4u)) - 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->ebp;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD340Eu), LIFT_CODE_TOKEN_RVA(0xD340Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D340Eu);
    goto label_000D3381;
    label_000D3413: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3413u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D3416: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3416u);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D3430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3430u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = 1u;
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_control_reference_registry_guard)) & ((cpu->ebx & 0xFFu))) != 0u) goto label_000D34BC;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_control_reference_registry_guard, (uint64_t)(g_sfera_control_reference_registry_guard) | (uint64_t)(cpu->ebx));
    lift_push32(cpu, 0x14u);
    lift_store32(cpu->esp + 0x24u, 0u);
    g_sfera_control_reference_registry.size = (uint32_t)(0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3480u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D34D2;
    g_sfera_control_reference_registry.sentinel = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    lift_store8(cpu->eax + 0x10u, cpu->ebx & 0xFFu);
    cpu->ecx = g_sfera_control_reference_registry.sentinel;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC030));
    lift_store8(cpu->ecx + 0x11u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D34B9u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D34BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D34BCu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_control_reference_registry;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_000D34D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D34D2u);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0xCu, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3500u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4D3500u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D3510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3510u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::Window*>(cpu->esi));
    cpu->ebx = 0u;
    cpu->ebp = 0xFu;
    lift_store32(cpu->esi + 0x1Cu, cpu->ebp);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_store8(cpu->esi + 8u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x24u, cpu->ebx);
    lift_store32(cpu->esi + 0x28u, cpu->ebx);
    lift_store32(cpu->esi + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x30u, cpu->ebx);
    lift_store32(cpu->esi + 0x34u, cpu->ebx);
    lift_store32(cpu->esi + 0x38u, cpu->ebx);
    lift_store32(cpu->esi + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x48u, 1u);
    lift_store32(cpu->esi + 0x4Cu, 0x10100u);
    lift_store32(cpu->esi + 0x50u, cpu->ebx);
    lift_store32(cpu->esi + 0x68u, cpu->ebp);
    lift_store32(cpu->esi + 0x64u, cpu->ebx);
    lift_store32(cpu->esp + 0x44u, cpu->ebx);
    lift_store8(cpu->esi + 0x54u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x84u, cpu->ebp);
    lift_store32(cpu->esi + 0x80u, cpu->ebx);
    lift_store8(cpu->esi + 0x70u, cpu->ebx & 0xFFu);
    lift_store16(cpu->esi + 0x8Cu, 0x100u);
    lift_store32(cpu->esi + 0x90u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x94u, cpu->ebx);
    lift_store32(cpu->esi + 0x98u, 0xFF000000u);
    lift_store32(cpu->esi + 0x9Cu, cpu->ebx);
    lift_push32(cpu, 0xCu);
    lift_store8(cpu->esp + 0x48u, 2u);
    lift_store32(cpu->esi + 0xA4u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D35D0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D379F;
    lift_store32(cpu->esi + 0xA0u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_push32(cpu, 0xCu);
    lift_store8(cpu->esp + 0x48u, 3u);
    lift_store32(cpu->esi + 0xB0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D35FEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D3775;
    lift_store32(cpu->esi + 0xACu, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xACu);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->edi = (uint32_t)(cpu->esi + 0xBCu);
    lift_store32(cpu->esi + 0xB8u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_store32(cpu->edi, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0x48u, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3638u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D374B;
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
    lift_store32(cpu->esi + 0xD4u, cpu->ebx);
    lift_store32(cpu->esi + 0xD8u, cpu->ebx);
    lift_store32(cpu->esi + 0xDCu, 0xFFu);
    lift_store16(cpu->esi + 0xE0u, cpu->ebx & 0xFFFFu);
    lift_store32(cpu->esi + 0xECu, cpu->ebx);
    lift_store32(cpu->esi + 0xF0u, cpu->ebx);
    lift_store32(cpu->esi + 0xF4u, cpu->ebx);
    lift_store32(cpu->esi + 0xF8u, cpu->ebx);
    lift_store8(cpu->esi + 0x10Cu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x118u, cpu->ebx);
    lift_store8(cpu->esi + 0x11Cu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x170u, cpu->ebx);
    lift_store32(cpu->esi + 0x174u, cpu->ebx);
    lift_store32(cpu->esi + 0x18Cu, cpu->ebp);
    lift_store32(cpu->esi + 0x188u, cpu->ebx);
    lift_store8(cpu->esi + 0x178u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0x44u, 7u);
    lift_store32(cpu->esi + 0x194u, cpu->ebx);
    lift_store8(cpu->esi + 0x120u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esi + 0x148u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0xE4u, cpu->ebx);
    lift_store32(cpu->esi + 0xE8u, cpu->ebx);
    lift_store32(cpu->esi + 0xFCu, cpu->ebx);
    lift_store32(cpu->esi + 0x104u, cpu->ebx);
    lift_store32(cpu->esi + 0x100u, cpu->ebx);
    lift_store32(cpu->esi + 0x108u, cpu->ebx);
    lift_store32(cpu->esi + 0x110u, cpu->ebx);
    lift_store32(cpu->esi + 0x114u, cpu->ebx);
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    lift_store32(cpu->esi + 0x44u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3719u); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3728u); lift_push32(cpu, r); sfera_sub_004D23B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3735u); lift_push32(cpu, r); sfera_sub_004D2480(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D374B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D374Bu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD3775u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000D3775: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3775u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD379Fu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000D379F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D379Fu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D37C9u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4D37C9u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D37D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D37D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::Window*>(cpu->esi));
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x2Cu, 6u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x4Bu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D3888;
    cpu->eax = lift_load32(cpu->esi + 0x174u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D3888;
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) <= (uint32_t)(cpu->ebx)) goto label_000D3862;
    cpu->eax = lift_load32(cpu->eax);
    cpu->edi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000D3862;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D3830: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3830u);
    cpu->edx = 0x143u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D383Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->edi + 8u);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_000D3856;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D384Du); lift_push32(cpu, r); sfera_sub_004CF160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3853u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D3856: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3856u);
    cpu->edi = lift_load32(cpu->edi);
    cpu->eax = lift_load32(cpu->esi + 0x174u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_000D3830;
    label_000D3862: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3862u);
    cpu->edx = 0x145u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3871u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x174u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000D3882;
    lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD3882u); lift_push32(cpu, r); sfera_sub_004D30E0(cpu,r); if (cpu->eip != r) return; }
    label_000D3882: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3882u);
    lift_store32(cpu->esi + 0x174u, cpu->ebx);
    label_000D3888: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3888u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xA4u)) <= (uint32_t)(cpu->ebx)) goto label_000D3905;
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->edi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000D38C9;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D38A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D38A0u);
    cpu->edx = 0x14Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D38AFu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 8u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000D38BF;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000D38BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D38BFu);
    cpu->edi = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0xA0u))) goto label_000D38A0;
    label_000D38C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D38C9u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    lift_store32(cpu->esi + 0xA4u, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0xA0u))) goto label_000D3905;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000D38F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D38F0u);
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D38F8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0xA0u))) goto label_000D38F0;
    label_000D3905: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3905u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xECu)) == (uint32_t)(cpu->ebx)) goto label_000D3935;
    cpu->edx = 0x153u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D391Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xECu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000D392F;
    lift_push32(cpu, 1u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000D392F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D392Fu);
    lift_store32(cpu->esi + 0xECu, cpu->ebx);
    label_000D3935: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3935u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D393Eu); lift_push32(cpu, r); sfera_sub_004D3430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edi = cpu->eax;
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3951u); lift_push32(cpu, r); sfera_sub_004D20F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3967u); lift_push32(cpu, r); sfera_sub_004B2C40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x18Cu)) < (uint32_t)(0x10u)) goto label_000D397F;
    cpu->eax = lift_load32(cpu->esi + 0x178u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D397Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D397F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D397Fu);
    cpu->ebp = 0xFu;
    lift_store32(cpu->esi + 0x18Cu, cpu->ebp);
    lift_store32(cpu->esi + 0x188u, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi + 0xBCu);
    lift_store8(cpu->esi + 0x178u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D39A1u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xBCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D39ADu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xBCu, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esi + 0xACu);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xACu);
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0xB0u, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0xACu))) goto label_000D39EC;
    label_000D39D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D39D7u);
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D39DFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0xACu))) goto label_000D39D7;
    label_000D39EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D39ECu);
    cpu->edx = lift_load32(cpu->esi + 0xACu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D39F8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0xA4u, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0xA0u))) goto label_000D3A35;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D3A20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3A20u);
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3A28u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0xA0u))) goto label_000D3A20;
    label_000D3A35: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3A35u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3A41u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0x10u;
    cpu->esp += 4u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x84u)) < (uint32_t)(cpu->edi)) goto label_000D3A5D;
    cpu->ecx = lift_load32(cpu->esi + 0x70u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3A5Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D3A5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3A5Du);
    lift_store32(cpu->esi + 0x84u, cpu->ebp);
    lift_store32(cpu->esi + 0x80u, cpu->ebx);
    lift_store8(cpu->esi + 0x70u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x68u)) < (uint32_t)(cpu->edi)) goto label_000D3A7D;
    cpu->edx = lift_load32(cpu->esi + 0x54u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3A7Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D3A7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3A7Du);
    lift_store32(cpu->esi + 0x68u, cpu->ebp);
    lift_store32(cpu->esi + 0x64u, cpu->ebx);
    lift_store8(cpu->esi + 0x54u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (uint32_t)(cpu->edi)) goto label_000D3A97;
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3A94u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D3A97: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3A97u);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebp);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_store8(cpu->esi + 8u, cpu->ebx & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D3AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3AC0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0x18u)) goto label_000D4191;
    switch ((uint32_t)(cpu->ecx)) {
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
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3B00u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3B0Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3B28u); lift_push32(cpu, r); sfera_sub_004D3510(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3B38: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3B38u);
    cpu->edx = 0xDAu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3B47u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3B51u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3B6Fu); lift_push32(cpu, r); sfera_sub_0049ED60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3B7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3B7Fu);
    cpu->edx = 0xDBu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3B8Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1A0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3B98u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3BB6u); lift_push32(cpu, r); sfera_sub_004CF2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3BC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3BC6u);
    cpu->edx = 0xDCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3BD5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3BDFu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 3u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3BFDu); lift_push32(cpu, r); sfera_sub_004C3BA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3C0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3C0Du);
    cpu->edx = 0xDDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3C1Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3C26u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3C44u); lift_push32(cpu, r); sfera_sub_004C6A20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3C54: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3C54u);
    cpu->edx = 0xDEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3C63u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1B8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3C6Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 5u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3C8Bu); lift_push32(cpu, r); sfera_sub_004B77A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3C9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3C9Bu);
    cpu->edx = 0xDFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3CAAu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x310u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3CB4u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 6u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3CD2u); lift_push32(cpu, r); sfera_sub_004B0100(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3CE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3CE2u);
    cpu->edx = 0xE0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3CF1u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3CFBu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 7u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3D19u); lift_push32(cpu, r); sfera_sub_004A0E60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3D29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3D29u);
    cpu->edx = 0xE1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3D38u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3D42u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3D60u); lift_push32(cpu, r); sfera_sub_004C43A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3D70: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3D70u);
    cpu->edx = 0xE2u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3D7Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3D89u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 9u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3DA7u); lift_push32(cpu, r); sfera_sub_004BFB90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3DB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3DB7u);
    cpu->edx = 0xE3u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3DC6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x248u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3DD0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0xAu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3DEEu); lift_push32(cpu, r); sfera_sub_004C8020(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3DFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3DFEu);
    cpu->edx = 0xE4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3E0Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1E8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3E17u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0xBu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3E35u); lift_push32(cpu, r); sfera_sub_004BDCD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3E45: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3E45u);
    cpu->edx = 0xE5u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3E54u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x65F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3E5Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3E7Cu); lift_push32(cpu, r); sfera_sub_004A2D20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3E8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3E8Cu);
    cpu->edx = 0xE6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3E9Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x298u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3EA5u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0xDu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3EC3u); lift_push32(cpu, r); sfera_sub_004C8F60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3ED3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3ED3u);
    cpu->edx = 0xE7u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3EE2u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3EECu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0xEu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3F0Au); lift_push32(cpu, r); sfera_sub_004C3250(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3F1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3F1Au);
    cpu->edx = 0xE8u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3F29u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1C0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3F33u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0xFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3F51u); lift_push32(cpu, r); sfera_sub_004CD430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3F61: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3F61u);
    cpu->edx = 0xE9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3F70u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1D0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3F7Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3F98u); lift_push32(cpu, r); sfera_sub_004C5D00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3FA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3FA8u);
    cpu->edx = 0xEAu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3FB7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x210u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3FC1u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0x11u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3FDFu); lift_push32(cpu, r); sfera_sub_004A41B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D3FEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D3FEFu);
    cpu->edx = 0xEDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D3FFEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1C0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4008u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0x12u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4026u); lift_push32(cpu, r); sfera_sub_004D0890(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D4036: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4036u);
    cpu->edx = 0xEEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4045u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D404Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0x13u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D406Du); lift_push32(cpu, r); sfera_sub_004C3640(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D407D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D407Du);
    cpu->edx = 0xEFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D408Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x240u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4096u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D40B4u); lift_push32(cpu, r); sfera_sub_004C2770(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D40C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D40C4u);
    cpu->edx = 0xF0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D40D3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x298u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D40DDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0x15u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D40FBu); lift_push32(cpu, r); sfera_sub_004AA410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D410B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D410Bu);
    cpu->edx = 0xF1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D411Au); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x280u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4124u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0x16u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D413Eu); lift_push32(cpu, r); sfera_sub_004B4DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D414E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D414Eu);
    cpu->edx = 0xF2u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D415Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1A0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4167u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0x17u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D41AE;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4181u); lift_push32(cpu, r); sfera_sub_004A55D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D4191: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4191u);
    lift_push32(cpu, 0xF5u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D41A5u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D41ABu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000D41AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D41AEu);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D4230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4230u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x134u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x148u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x164u);
    cpu->eax = lift_load32(cpu->esp + 0x158u);
    cpu->ebx = lift_load32(cpu->esp + 0x160u);
    cpu->edi = lift_load32(cpu->esp + 0x15Cu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(0x7FFFFFFFu)) goto label_000D42A2;
    label_000D429B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D429Bu);
    cpu->eax = 0u;
    goto label_000D4784;
    label_000D42A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D42A2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D42A7u); lift_push32(cpu, r); sfera_sub_004D3AC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->esi = 0u;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->esi)) goto label_000D429B;
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D42BBu); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"tooltip");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D42CFu); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4351;
    cpu->edx = 0x393u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D42E2u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D42ECu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x150u, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000D4307;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4305u); lift_push32(cpu, r); sfera_sub_004CFE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    label_000D4307: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4307u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x15Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x9Cu, cpu->ebp);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->loadUi(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D432Bu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4337;
    lift_store32(cpu->ebp + 0xECu, cpu->esi);
    goto label_000D4351;
    label_000D4337: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4337u);
    cpu->edx = 0x399u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4346u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    label_000D4351: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4351u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"position");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D435Eu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = native_function_address32(&::sscanf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D43AA;
    cpu->ecx = (uint32_t)(cpu->ebp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD437Bu), LIFT_CODE_TOKEN_RVA(0xD4379u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D437Bu);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000D43AA;
    cpu->ecx = lift_load32(cpu->esp + 0x168u);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Window::LoadControl(%s,%d,%d) -> Position is wrong in control %d.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D43A1u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D43A7u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    label_000D43AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D43AAu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"size");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D43B7u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D43FD;
    cpu->edx = (uint32_t)(cpu->ebp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD43CEu), LIFT_CODE_TOKEN_RVA(0xD43CCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D43CEu);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000D43FD;
    cpu->edx = lift_load32(cpu->esp + 0x168u);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Window::LoadControl(%s,%d,%d) -> Size is wrong in control %d.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D43F4u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D43FAu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    label_000D43FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D43FDu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"disabledcolor");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D440Au); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4473;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD4428u), LIFT_CODE_TOKEN_RVA(0xD4426u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4428u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000D444F;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ebx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadControl(%s,%d,%d) -> Not enough args in 'disabledColor'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4446u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D444Cu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D444F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D444Fu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = lift_load8(cpu->esp + 0x30u);
    cpu->eax = lift_load8(cpu->esp + 0x1Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->eax;
    lift_store32(cpu->ebp + 0x98u, cpu->ecx);
    label_000D4473: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4473u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"showTitle");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4480u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D44C8;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xE8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xE4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD449Du), LIFT_CODE_TOKEN_RVA(0xD449Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D449Du);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000D44C4;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ebx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadControl(%s,%d,%d) -> Not enough args in 'showTitle'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D44BBu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D44C1u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D44C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D44C4u);
    lift_store32(cpu->ebp + 0x24u, (uint64_t)(lift_load32(cpu->ebp + 0x24u)) | (uint64_t)(4u));
    label_000D44C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D44C8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"disabled");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D44D5u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D44EA;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D44E2u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->ebp + 0x49u, cpu->ecx & 0xFFu);
    label_000D44EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D44EAu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"hidden");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D44F7u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D450C;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4504u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->ebp + 0x48u, cpu->edx & 0xFFu);
    label_000D450C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D450Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"group");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4519u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4529;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4526u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x3Cu, cpu->eax);
    label_000D4529: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4529u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"font");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4536u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4550;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4543u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->ebp + 0x8Cu, cpu->eax & 0xFFu);
    lift_store8(cpu->ebp + 0x8Du, 1u);
    label_000D4550: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4550u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"textFormat");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D455Du); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D45C5;
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D456Fu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D45C5;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebp + 0x118u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4584u); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_000D45BB;
    label_000D4590: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4590u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D459Du); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D45B4;
    cpu->esi = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D45AAu); lift_push32(cpu, r); sfera_sub_004D1930(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x118u, (uint64_t)(lift_load32(cpu->ebp + 0x118u)) | (uint64_t)(cpu->eax));
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    label_000D45B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D45B4u);
    cpu->ebx += 2u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->esi)) goto label_000D4590;
    label_000D45BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D45BBu);
    cpu->esi = native_function_address32(&::sscanf);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    label_000D45C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D45C5u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"textColor");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D45D2u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4643;
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD45F0u), LIFT_CODE_TOKEN_RVA(0xD45EEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D45F0u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000D461F;
    cpu->eax = lift_load32(cpu->esp + 0x168u);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadControl(%s,%d,%d) -> Not enough args in 'textColor' in control %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4616u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D461Cu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    label_000D461F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D461Fu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load8(cpu->esp + 0x24u);
    cpu->eax = lift_load8(cpu->esp + 0x20u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->eax;
    lift_store32(cpu->ebp + 0x90u, cpu->ecx);
    label_000D4643: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4643u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"windowText");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4650u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D467C;
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4662u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D467C;
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D466Fu); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD467Cu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_000D467C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D467Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"windowHelp");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4689u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D46BD;
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D469Bu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D46BD;
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000D46A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D46A6u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000D46A6;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x70u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD46BDu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    label_000D46BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D46BDu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"setWindowText");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D46CAu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D46FE;
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D46DCu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D46FE;
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000D46E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D46E7u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000D46E7;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD46FEu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    label_000D46FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D46FEu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"canDragDrop");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D470Bu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4720;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4718u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->ebp + 0x4Cu, cpu->eax & 0xFFu);
    label_000D4720: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4720u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->ecx + 0x9Cu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D4730;
    cpu->eax = cpu->ecx;
    label_000D4730: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4730u);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ebp + 0x9Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->loadUi(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4746u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D4769;
    cpu->edx = 0x3F0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4759u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->destroy(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4765u);
    cpu->ebp = 0u;
    goto label_000D4776;
    label_000D4769: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4769u);
    cpu->eax = lift_load32(cpu->esp + 0x168u);
    lift_store32(cpu->ebp + 0xD8u, cpu->eax);
    label_000D4776: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4776u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4782u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->ebp;
    label_000D4784: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4784u);
    cpu->ecx = lift_load32(cpu->esp + 0x148u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x140u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D47B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D47B0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x144u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x158u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x168u);
    cpu->edi = lift_load32(cpu->esp + 0x16Cu);
    cpu->ebx = lift_load32(cpu->esp + 0x170u);
    cpu->ebp = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4816u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"hitTransparent");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4823u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4838;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4830u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->ebp + 0x4Fu, cpu->edx & 0xFFu);
    label_000D4838: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4838u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"windowName");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4845u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D487C;
    cpu->eax = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4857u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D487C;
    cpu->eax = (uint32_t)(cpu->esp + 0x54u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000D4862: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4862u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000D4862;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x178u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD487Cu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    label_000D487C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D487Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"spritesDef");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4890u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4A0E;
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D48A4u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"sprite");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D48B5u); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4A07;
    label_000D48BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D48BDu);
    cpu->edx = 0x2B4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D48CCu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x98u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D48D6u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x160u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D48F7;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D48F3u); lift_push32(cpu, r); sfera_sub_004CDF00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000D48F9;
    label_000D48F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D48F7u);
    cpu->esi = 0u;
    label_000D48F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D48F9u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x16Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D491Au); lift_push32(cpu, r); sfera_sub_004CE8A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D49CB;
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x174u)) != (uint32_t)(cpu->ebx)) goto label_000D498D;
    cpu->edx = 0x2BDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D493Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4942u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    lift_store32(cpu->esp + 0x160u, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000D497A;
    lift_push32(cpu, 0xCu);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4964u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D4AB2;
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->eax);
    goto label_000D497C;
    label_000D497A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D497Au);
    cpu->esi = 0u;
    label_000D497C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D497Cu);
    lift_store32(cpu->esp + 0x160u, 0xFFFFFFFFu);
    lift_store32(cpu->ebp + 0x174u, cpu->esi);
    label_000D498D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D498Du);
    cpu->esi = lift_load32(cpu->ebp + 0x174u);
    cpu->ebx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D49A6u); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) < (uint32_t)(1u)) goto label_000D4ADC;
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->ebx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->ecx, cpu->eax);
    goto label_000D49EE;
    label_000D49CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D49CBu);
    cpu->edx = 0x2C2u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D49DAu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == 0u) goto label_000D49EE;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D49E5u); lift_push32(cpu, r); sfera_sub_004CF160(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D49EBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D49EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D49EEu);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"sprite");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D49FFu); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D48BD;
    label_000D4A07: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4A07u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD4A0Eu); lift_push32(cpu, r); sfera_sub_004948B0(cpu,r); if (cpu->eip != r) return; }
    label_000D4A0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4A0Eu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"drawMethod");
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebp + 0x194u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4A25u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4AFA;
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4A3Bu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4AFA;
    cpu->esi = native_function_address32(&::_stricmp);
    cpu->eax = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, (uintptr_t)"SPRITE"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD4A55u), LIFT_CODE_TOKEN_RVA(0xD4A53u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4A55u);
    cpu->esp += 8u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D4AE7;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4A6Eu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4AFA;
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4A82u); lift_push32(cpu, r); sfera_sub_004D3140(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x194u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D4AFA;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Sprite '%s' not found.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4AA7u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4AADu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    goto label_000D4AFA;
    label_000D4AB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4AB2u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD4ADCu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000D4ADC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4ADCu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD4AE7u);
    label_000D4AE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4AE7u);
    lift_push32(cpu, (uintptr_t)"NONE"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD4AEFu), LIFT_CODE_TOKEN_RVA(0xD4AEDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4AEFu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D4AFA;
    lift_store32(cpu->ebp + 0x24u, (uint64_t)(lift_load32(cpu->ebp + 0x24u)) | (uint64_t)(2u));
    label_000D4AFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4AFAu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"showTitle");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4B07u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = native_function_address32(&::sscanf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4B55;
    cpu->edx = (uint32_t)(cpu->ebp + 0xE8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xE4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD4B2Au), LIFT_CODE_TOKEN_RVA(0xD4B28u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4B2Au);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000D4B51;
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Not enough args in 'showTitle'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4B48u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4B4Eu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D4B51: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4B51u);
    lift_store32(cpu->ebp + 0x24u, (uint64_t)(lift_load32(cpu->ebp + 0x24u)) | (uint64_t)(4u));
    label_000D4B55: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4B55u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"escapeHandle");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4B62u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4B77;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4B6Fu); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4B77;
    lift_store32(cpu->ebp + 0x24u, (uint64_t)(lift_load32(cpu->ebp + 0x24u)) | (uint64_t)(8u));
    label_000D4B77: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4B77u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"position");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4B84u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4BDE;
    cpu->esi = (uint32_t)(cpu->ebp + 0x34u);
    lift_push32(cpu, cpu->esi);
    cpu->ebx = (uint32_t)(cpu->ebp + 0x30u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4D4B99u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4B9Fu);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000D4BCA;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Not enough args in 'position'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4BC1u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4BC7u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D4BCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4BCAu);
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->edx = lift_load32(cpu->esi);
    cpu->esi = native_function_address32(&::sscanf);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->ebp + 0x40u, cpu->ecx);
    lift_store32(cpu->ebp + 0x44u, cpu->edx);
    label_000D4BDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4BDEu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"size");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4BEBu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4C29;
    cpu->eax = (uint32_t)(cpu->ebp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD4C02u), LIFT_CODE_TOKEN_RVA(0xD4C00u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4C02u);
    cpu->esp += 0x10u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_000D4C29;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Not enough args in 'size'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4C20u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4C26u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D4C29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4C29u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"windowText");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4C36u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4C62;
    cpu->eax = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4C48u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4C62;
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4C55u); lift_push32(cpu, r); sfera_sub_004B90A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD4C62u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_000D4C62: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4C62u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"windowHelp");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4C6Fu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4CA7;
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4C81u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4CA7;
    cpu->eax = (uint32_t)(cpu->esp + 0x54u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D4C90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4C90u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000D4C90;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x70u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD4CA7u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    label_000D4CA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4CA7u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"canDragDrop");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4CB4u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4CC9;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4CC1u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->ebp + 0x4Cu, cpu->eax & 0xFFu);
    label_000D4CC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4CC9u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"canGoTop");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4CD6u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4CEB;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4CE3u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->ebp + 0x4Du, cpu->ecx & 0xFFu);
    label_000D4CEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4CEBu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"canNotCross");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4CF8u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4D0D;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4D05u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4D0D;
    lift_store32(cpu->ebp + 0x24u, (uint64_t)(lift_load32(cpu->ebp + 0x24u)) | (uint64_t)(0x10u));
    label_000D4D0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4D0Du);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"rectTitle");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4D1Au); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4D6C;
    cpu->edx = (uint32_t)(cpu->ebp + 0x108u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0x104u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x100u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d %d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD4D45u), LIFT_CODE_TOKEN_RVA(0xD4D43u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4D45u);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(4u)) goto label_000D4D6C;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ebx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Not enough args in 'rectTitle'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4D63u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4D69u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D4D6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4D6Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"saveLastPosition");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4D79u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4D8E;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4D86u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->ebp + 0x4Eu, cpu->ecx & 0xFFu);
    label_000D4D8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4D8Eu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"font");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4D9Bu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4DB5;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4DA8u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->ebp + 0x8Cu, cpu->eax & 0xFFu);
    lift_store8(cpu->ebp + 0x8Du, 1u);
    label_000D4DB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4DB5u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"alignWin");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4DC2u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4E08;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4DCDu); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_000D4E08;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D4DE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4DE0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4DEDu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4E01;
    cpu->esi = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4DFAu); lift_push32(cpu, r); sfera_sub_004D1890(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x38u, (uint64_t)(lift_load32(cpu->ebp + 0x38u)) | (uint64_t)(cpu->eax));
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_000D4E01: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4E01u);
    cpu->ebx += 2u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->esi)) goto label_000D4DE0;
    label_000D4E08: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4E08u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"textColor");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4E19u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4E86;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4D4E35u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4E3Bu);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000D4E62;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Not enough args in 'textColor'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4E59u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4E5Fu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D4E62: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4E62u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load8(cpu->esp + 0x20u);
    cpu->eax = lift_load8(cpu->esp + 0x24u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->eax;
    lift_store32(cpu->ebp + 0x90u, cpu->ecx);
    label_000D4E86: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4E86u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"disabledcolor");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4E93u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4F00;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4D4EAFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4EB5u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000D4EDC;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Not enough args in 'disabledColor'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4ED3u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4ED9u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D4EDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4EDCu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load8(cpu->esp + 0x20u);
    cpu->ecx = lift_load8(cpu->esp + 0x24u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx |= cpu->ecx;
    lift_store32(cpu->ebp + 0x98u, cpu->edx);
    label_000D4F00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4F00u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"showEffect");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4F0Du); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4F7C;
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4F1Fu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4F7C;
    cpu->esi = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4F2Cu); lift_push32(cpu, r); sfera_sub_004D17F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->ebp + 0x120u, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4F3Bu); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->ebp + 0x130u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4F4Au); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->ebp + 0x134u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 3u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4F59u); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->ebp + 0x138u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x130u));
    lift_x87_push(cpu, 0.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000D4F7C;
    lift_x87_push(cpu, (double)0.25f);
    lift_store_f32(cpu->ebp + 0x130u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000D4F7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4F7Cu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"hideEffect");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4F8Du); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4FFC;
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4F9Fu); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D4FFC;
    cpu->esi = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4FACu); lift_push32(cpu, r); sfera_sub_004D17F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->ebp + 0x148u, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4FBBu); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->ebp + 0x158u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4FCAu); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->ebp + 0x15Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 3u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D4FD9u); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->ebp + 0x160u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x158u));
    lift_x87_push(cpu, 0.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000D4FFC;
    lift_x87_push(cpu, (double)0.25f);
    lift_store_f32(cpu->ebp + 0x158u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000D4FFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D4FFCu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebx = 1u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5015u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"control");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5026u); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D5156;
    cpu->edi = cpu->edi;
    label_000D5030: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5030u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"classID");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5041u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D5114;
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5057u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D5114;
    cpu->esi = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5068u); lift_push32(cpu, r); sfera_sub_004D15E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0x7FFFFFFFu)) goto label_000D509B;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> Unknown ClassID(%s) in control %d.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5092u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5098u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000D509B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D509Bu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D50AFu); lift_push32(cpu, r); sfera_sub_004D4230(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D5138;
    cpu->ebx = lift_load32(cpu->ebp + 0xA0u);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xA0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D50D6u); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xA4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) < (uint32_t)(1u)) goto label_000D4ADC;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    ++cpu->ecx;
    lift_store32(cpu->ebp + 0xA4u, cpu->ecx);
    lift_store32(cpu->ebx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->edx + 0xD8u, cpu->eax);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    goto label_000D5138;
    label_000D5114: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5114u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Window::LoadUI(%s,%d,%d) -> ClassID not defined in control %d.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D512Fu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5135u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    label_000D5138: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5138u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    ++cpu->ebx;
    lift_push32(cpu, (uint32_t)(uintptr_t)"control");
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D514Eu); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D5030;
    label_000D5156: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5156u);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5162u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->esp + 0x158u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x150u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D51A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D51A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    std::construct_at(reinterpret_cast<SphereUI::Window*>(cpu->esi));
    cpu->ebx = 0u;
    cpu->eax = 0xFu;
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_store8(cpu->esi + 8u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x68u, cpu->eax);
    lift_store32(cpu->esi + 0x64u, cpu->ebx);
    lift_store32(cpu->esp + 0x44u, cpu->ebx);
    lift_store8(cpu->esi + 0x54u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x84u, cpu->eax);
    lift_store32(cpu->esi + 0x80u, cpu->ebx);
    lift_store8(cpu->esi + 0x70u, cpu->ebx & 0xFFu);
    lift_push32(cpu, 0xCu);
    lift_store8(cpu->esp + 0x48u, 2u);
    lift_store32(cpu->esi + 0xA4u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5211u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D54DA;
    lift_store32(cpu->esi + 0xA0u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_push32(cpu, 0xCu);
    lift_store8(cpu->esp + 0x48u, 3u);
    lift_store32(cpu->esi + 0xB0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D523Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D54B0;
    lift_store32(cpu->esi + 0xACu, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xACu);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->ebp = (uint32_t)(cpu->esi + 0xBCu);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    lift_store32(cpu->ebp, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0x48u, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5274u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D5486;
    lift_store32(cpu->ebp, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp);
    lift_store32(cpu->eax, cpu->ebp);
    lift_store32(cpu->ebp + 4u, cpu->ebx);
    lift_store32(cpu->ebp + 8u, cpu->ebx);
    lift_store32(cpu->ebp + 0xCu, cpu->ebx);
    lift_store32(cpu->ebp + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x18Cu, 0xFu);
    lift_store32(cpu->esi + 0x188u, cpu->ebx);
    lift_store8(cpu->esi + 0x178u, cpu->ebx & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x48u, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D52C1u); lift_push32(cpu, r); sfera_sub_004A0A40(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x4Bu, 1u);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xA0u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->esi + 0xA4u, cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esi + 0xA0u))) goto label_000D52FB;
    label_000D52E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D52E6u);
    cpu->ebp = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D52EEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->ebp;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->esi + 0xA0u))) goto label_000D52E6;
    label_000D52FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D52FBu);
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    cpu->eax = lift_load32(cpu->edx + 0xA0u);
    cpu->ebp = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->eax)) goto label_000D53C4;
    label_000D5313: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5313u);
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_control_reference_registry_guard)) & (1u)) != 0u) goto label_000D537C;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_control_reference_registry_guard, (uint64_t)(g_sfera_control_reference_registry_guard) | (uint64_t)(1u));
    lift_push32(cpu, 0x14u);
    lift_store8(cpu->esp + 0x48u, 8u);
    g_sfera_control_reference_registry.size = (uint32_t)(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5335u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D545C;
    g_sfera_control_reference_registry.sentinel = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->edx = g_sfera_control_reference_registry.sentinel;
    lift_store8(cpu->edx + 0x10u, 1u);
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC030));
    lift_store8(cpu->eax + 0x11u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5374u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store8(cpu->esp + 0x44u, 7u);
    label_000D537C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D537Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_control_reference_registry;
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5390u); lift_push32(cpu, r); sfera_sub_004D23B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_control_reference_registry;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D53A0u); lift_push32(cpu, r); sfera_sub_004D2480(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 4u, stop_address); return;
    label_000D53C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D53C0u);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    label_000D53C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D53C4u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D53CEu);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D5422;
    cpu->ebp = lift_load32(cpu->esi + 0xA0u);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + 0xA0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D53F1u); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) < (uint32_t)(1u)) goto label_000D5451;
    ++cpu->ecx;
    lift_store32(cpu->esi + 0xA4u, cpu->ecx);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->eax + 0x9Cu, cpu->esi);
    goto label_000D5435;
    label_000D5422: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5422u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"WARNING: Can't create reference from control.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D542Cu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5432u); lift_push32(cpu, r); sfera_sub_0042E480(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000D5435: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5435u);
    cpu->ebp = lift_load32(cpu->ebp);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->ecx + 0xA0u))) goto label_000D53C0;
    goto label_000D5313;
    label_000D5451: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5451u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD545Cu);
    label_000D545C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D545Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x50u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD5486u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000D5486: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5486u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD54B0u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000D54B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D54B0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD54DAu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000D54DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D54DAu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5504u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4D5504u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D5510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5510u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0x401u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Interface\\Window.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5543u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D554Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D5579;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5568u); lift_push32(cpu, r); sfera_sub_004D51A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D5579: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5579u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D5590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5590u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_crash_report_runtime.report_length;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x1C00u)) goto label_000D55C7;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.report_text[0]);
    lift_native_call(cpu, native_function_address32(&::lstrlenA), LIFT_CODE_TOKEN_VA(0x4D55A9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D55AFu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.report_text[0]); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::WriteFile), LIFT_CODE_TOKEN_VA(0x4D55BAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D55C0u);
    cpu->eax = 0u;
    g_sfera_crash_report_runtime.report_length = (uint32_t)(cpu->eax);
    label_000D55C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D55C7u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_crash_report_runtime.report_text[0]));
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::wvsprintfA), LIFT_CODE_TOKEN_VA(0x4D55D8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D55DEu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_crash_report_runtime.report_length, (uint64_t)(g_sfera_crash_report_runtime.report_length) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D55F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D55F0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFEu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF0u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esp);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->edi);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000D5690;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    lift_push32(cpu, (uint32_t)(uintptr_t)"raising exception\r\n");
    lift_native_call(cpu, native_function_address32(&::OutputDebugStringA), LIFT_CODE_TOKEN_VA(0x4D5638u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D563Eu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x80000003u);
    lift_native_call(cpu, native_function_address32(&::RaiseException), LIFT_CODE_TOKEN_VA(0x4D5646u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D564Cu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000D5690: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5690u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"writing minidump\r\n");
    lift_native_call(cpu, native_function_address32(&::OutputDebugStringA), LIFT_CODE_TOKEN_VA(0x4D5695u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D569Bu);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThreadId), LIFT_CODE_TOKEN_VA(0x4D569Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D56A1u);
    lift_store32(cpu->ebp + 0xFFFFFFD8u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->ebx);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcessId), LIFT_CODE_TOKEN_VA(0x4D56B2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D56B8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4D56B9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D56BFu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MiniDumpWriteDump), LIFT_CODE_TOKEN_VA(0x4D56C0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D56C5u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D5665(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5665u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5670u); lift_push32(cpu, r); sfera_sub_004D55F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D5674(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5674u);
    cpu->esp = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFEu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D56E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D56E0u);
    cpu->esp -= 8u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esi, 0u);
    lift_native_call(cpu, native_function_address32(&::FileTimeToLocalFileTime), LIFT_CODE_TOKEN_VA(0x4D56EEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D56F4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D5756;
    cpu->edx = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::FileTimeToDosDateTime), LIFT_CODE_TOKEN_VA(0x4D5706u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D570Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D5756;
    cpu->ecx = lift_load16(cpu->esp);
    cpu->eax = lift_load16(cpu->esp + 4u);
    cpu->edx = cpu->ecx;
    cpu->edx &= 0x1Fu;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x3Fu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    lift_push32(cpu, cpu->edx);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0xBu), 32u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(9u), 32u);
    cpu->edx = cpu->eax;
    cpu->ecx += 0x7BCu;
    lift_push32(cpu, cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x1Fu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    lift_push32(cpu, cpu->edx);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax &= 0xFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%d/%d %02d:%02d:%02d"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::wsprintfA), LIFT_CODE_TOKEN_VA(0x4D574Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5753u);
    cpu->esp += 0x20u;
    label_000D5756: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5756u);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D5760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5760u);
    cpu->esp -= 0x3F4u;
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetSystemTimeAsFileTime), LIFT_CODE_TOKEN_VA(0x4D577Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5780u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->esi = (uint32_t)(cpu->esp + 0xC8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5796u); lift_push32(cpu, r); sfera_sub_004D56E0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Error occurred at %s\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D57A4u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x208u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1FCu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D57B3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D57B8u);
    cpu->esp += 0x18u;
    lift_push32(cpu, 0x206u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1F0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetModuleFileNameA), LIFT_CODE_TOKEN_VA(0x4D57CAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D57D0u);
    cpu->esi = native_function_address32(&::lstrcpyA);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D57E9;
    lift_push32(cpu, (uint32_t)(uintptr_t)"Unknown");
    cpu->eax = (uint32_t)(cpu->esp + 0x1F0u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD57E9u), LIFT_CODE_TOKEN_RVA(0xD57E7u))) { return; }
    label_000D57E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D57E9u);
    lift_push32(cpu, 0xC8u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x128u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D57F8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D57FDu);
    cpu->esp += 0xCu;
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x128u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0xCu, 0xC6u);
    lift_native_call(cpu, native_function_address32(&::GetUserNameA), LIFT_CODE_TOKEN_VA(0x4D5815u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D581Bu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D582E;
    lift_push32(cpu, (uint32_t)(uintptr_t)"Unknown");
    cpu->ecx = (uint32_t)(cpu->esp + 0x128u);
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD582Eu), LIFT_CODE_TOKEN_RVA(0xD582Cu))) { return; }
    label_000D582E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D582Eu);
    cpu->edx = (uint32_t)(cpu->esp + 0x124u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1F0u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s, run by %s\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5849u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5861u); lift_push32(cpu, r); sfera_sub_004D6300(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x8Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"OS:  %s (%s)\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5879u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetSystemInfo), LIFT_CODE_TOKEN_VA(0x4D5881u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5887u);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d processor(s), type %d\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D589Cu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x3Cu, 0x20u);
    lift_native_call(cpu, native_function_address32(&::GlobalMemoryStatus), LIFT_CODE_TOKEN_VA(0x4D58ACu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D58B2u);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%d%% memory in use\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D58C2u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x14u), 32u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d MB physical memory\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D58DAu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x14u), 32u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d MB physical memory free\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D58F3u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x6Cu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFFFFu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(0x14u), 32u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%d MB paging file\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D590Cu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x7Cu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x14u), 32u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d MB paging file free\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5924u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x8Cu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x14u), 32u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d MB user address space\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5940u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x9Cu);
    cpu->esp += 0x48u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFFFFu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(0x14u), 32u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%d MB user address space free\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D595Fu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x3F4u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D5980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5980u);
    cpu->esp -= 0xC4u;
    lift_store32(cpu->esp, 0x40010005u);
    lift_store32(cpu->esp + 4u, (uintptr_t)"a Control-C");
    lift_store32(cpu->esp + 8u, 0x40010008u);
    lift_store32(cpu->esp + 0xCu, (uintptr_t)"a Control-Break");
    lift_store32(cpu->esp + 0x10u, 0x80000002u);
    lift_store32(cpu->esp + 0x14u, (uintptr_t)"a Datatype Misalignment");
    lift_store32(cpu->esp + 0x18u, 0x80000003u);
    lift_store32(cpu->esp + 0x1Cu, (uintptr_t)"a Breakpoint");
    lift_store32(cpu->esp + 0x20u, 0xC0000005u);
    lift_store32(cpu->esp + 0x24u, (uintptr_t)"an Access Violation");
    lift_store32(cpu->esp + 0x28u, 0xC0000006u);
    lift_store32(cpu->esp + 0x2Cu, (uintptr_t)"an In Page Error");
    lift_store32(cpu->esp + 0x30u, 0xC0000017u);
    lift_store32(cpu->esp + 0x34u, (uintptr_t)"a No Memory");
    lift_store32(cpu->esp + 0x38u, 0xC000001Du);
    lift_store32(cpu->esp + 0x3Cu, (uintptr_t)"an Illegal Instruction");
    lift_store32(cpu->esp + 0x40u, 0xC0000025u);
    lift_store32(cpu->esp + 0x44u, (uintptr_t)"a Noncontinuable Exception");
    lift_store32(cpu->esp + 0x48u, 0xC0000026u);
    lift_store32(cpu->esp + 0x4Cu, (uintptr_t)"an Invalid Disposition");
    lift_store32(cpu->esp + 0x50u, 0xC000008Cu);
    lift_store32(cpu->esp + 0x54u, (uintptr_t)"a Array Bounds Exceeded");
    lift_store32(cpu->esp + 0x58u, 0xC000008Du);
    lift_store32(cpu->esp + 0x5Cu, (uintptr_t)"a Float Denormal Operand");
    lift_store32(cpu->esp + 0x60u, 0xC000008Eu);
    lift_store32(cpu->esp + 0x64u, (uintptr_t)"a Float Divide by Zero");
    lift_store32(cpu->esp + 0x68u, 0xC000008Fu);
    lift_store32(cpu->esp + 0x6Cu, (uintptr_t)"a Float Inexact Result");
    lift_store32(cpu->esp + 0x70u, 0xC0000090u);
    lift_store32(cpu->esp + 0x74u, (uintptr_t)"a Float Invalid Operation");
    lift_store32(cpu->esp + 0x78u, 0xC0000091u);
    lift_store32(cpu->esp + 0x7Cu, (uintptr_t)"a Float Overflow");
    lift_store32(cpu->esp + 0x80u, 0xC0000092u);
    lift_store32(cpu->esp + 0x84u, (uintptr_t)"a Float Stack Check");
    lift_store32(cpu->esp + 0x88u, 0xC0000093u);
    lift_store32(cpu->esp + 0x8Cu, (uintptr_t)"a Float Underflow");
    lift_store32(cpu->esp + 0x90u, 0xC0000094u);
    lift_store32(cpu->esp + 0x94u, (uintptr_t)"an Integer Divide by Zero");
    lift_store32(cpu->esp + 0x98u, 0xC0000095u);
    lift_store32(cpu->esp + 0x9Cu, (uintptr_t)"an Integer Overflow");
    lift_store32(cpu->esp + 0xA0u, 0xC0000096u);
    lift_store32(cpu->esp + 0xA4u, (uintptr_t)"a Privileged Instruction");
    lift_store32(cpu->esp + 0xA8u, 0xC00000FDu);
    lift_store32(cpu->esp + 0xACu, (uintptr_t)"a Stack Overflow");
    lift_store32(cpu->esp + 0xB0u, 0xC0000142u);
    lift_store32(cpu->esp + 0xB4u, (uintptr_t)"a DLL Initialization Failed");
    lift_store32(cpu->esp + 0xB8u, 0xE06D7363u);
    lift_store32(cpu->esp + 0xBCu, (uintptr_t)"a Microsoft C++ Exception");
    cpu->eax = 0u;
    label_000D5B45: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5B45u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esp + ((uint32_t)(cpu->eax) * 8u)))) goto label_000D5B6A;
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x18u)) goto label_000D5B45;
    cpu->eax = (uint32_t)(uintptr_t)"an Unknown exception type";
    cpu->esp += 0xC4u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D5B6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5B6Au);
    cpu->eax = lift_load32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 4u);
    cpu->esp += 0xC4u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D5B90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5B90u);
    cpu->ecx = cpu->eax;
    label_000D5B92: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5B92u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000D5B92;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D5BA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5BA0u);
    --cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000D5BAE;
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0x5Cu)) goto label_000D5BA0;
    cpu->eax = (uint32_t)(cpu->ecx + 1u);
    lift_return(cpu, 0u, stop_address); return;
    label_000D5BAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5BAEu);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0x5Cu)) goto label_000D5BB6;
    cpu->eax = (uint32_t)(cpu->ecx + 1u);
    label_000D5BB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5BB6u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D5BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5BC0u);
    cpu->esp -= 0x520u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"\r\n\r\nStack:\r\nAddress   Frame     Where\r\n"); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5BE1u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4D5BE4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5BEAu);
    lift_push32(cpu, 1u);
    cpu->ebp = 0u;
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::SymInitialize), LIFT_CODE_TOKEN_VA(0x4D5BF2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5BF8u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D5C28;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x4D5BFCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5C02u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"DbgHelp not initialized, code: %d\r\n"); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5C0Eu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x520u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D5C28: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5C28u);
    lift_push32(cpu, 0xA4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D5C33u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5C38u);
    cpu->edx = lift_load32(cpu->ebx + 0xC4u);
    cpu->ecx = lift_load32(cpu->ebx + 0xB8u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->eax = 3u;
    lift_store32(cpu->esp + 0x50u, cpu->edx);
    cpu->edx = native_function_address32(&::SymGetModuleBase);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esp + 0x5Cu, cpu->eax);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    cpu->eax = native_function_address32(&::SymFunctionTableAccess);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0xB4u);
    lift_push32(cpu, cpu->ebp);
    lift_store32(cpu->esp + 0x50u, cpu->ecx);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x4D5C7Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5C85u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x14Cu);
    lift_native_call(cpu, native_function_address32(&::StackWalk), LIFT_CODE_TOKEN_VA(0x4D5C8Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5C92u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D5DE9;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000D5CA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5CA0u);
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_000D5DF7;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%08X  %08X  "); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5CBDu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    cpu->eax = 0u;
    cpu->esp += 0x10u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0xDCu, 0x458u);
    lift_store32(cpu->esp + 0x12Cu, 0x400u);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x20u, 0x14u);
    lift_native_call(cpu, native_function_address32(&::SymGetLineFromAddr), LIFT_CODE_TOKEN_VA(0x4D5D08u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5D0Eu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D5D4F;
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = cpu->ebp;
    label_000D5D18: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5D18u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000D5D18;
    (void)cpu;
    label_000D5D20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5D20u);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_000D5D2D;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Cu)) goto label_000D5D20;
    ++cpu->eax;
    goto label_000D5D37;
    label_000D5D2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5D2Du);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Cu)) goto label_000D5D35;
    ++cpu->eax;
    goto label_000D5D37;
    label_000D5D35: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5D35u);
    cpu->eax = cpu->ebp;
    label_000D5D37: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5D37u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s:%u "); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5D48u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    cpu->ebp = 0u;
    goto label_000D5D5D;
    label_000D5D4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5D4Fu);
    lift_push32(cpu, (uintptr_t)"Unknown:0 "); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5D5Au); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000D5D5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5D5Du);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::SymFromAddr), LIFT_CODE_TOKEN_VA(0x4D5D71u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5D77u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D5D9D;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x128u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"(%hs+%I64X)"); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5D98u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    goto label_000D5DAB;
    label_000D5D9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5D9Du);
    lift_push32(cpu, (uintptr_t)"()"); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5DA8u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000D5DAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5DABu);
    lift_push32(cpu, (uintptr_t)"\r\n"); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5DB6u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = native_function_address32(&::SymGetModuleBase);
    cpu->ecx = native_function_address32(&::SymFunctionTableAccess);
    cpu->esp += 8u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x4D5DCEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5DD4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x14Cu);
    lift_native_call(cpu, native_function_address32(&::StackWalk), LIFT_CODE_TOKEN_VA(0x4D5DDBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5DE1u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D5CA0;
    label_000D5DE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5DE9u);
    lift_push32(cpu, (uintptr_t)"...\r\n"); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5DF4u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000D5DF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5DF7u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x520u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D5E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5E10u);
    lift_push32(cpu, (uintptr_t)"\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5E1Bu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xB0u);
    cpu->ecx = lift_load32(cpu->esi + 0xA0u);
    cpu->edx = lift_load32(cpu->esi + 0x9Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"EDI:\t0x%08x\tESI:\t0x%08x\tEAX:\t0x%08x\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5E3Bu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xA8u);
    cpu->ecx = lift_load32(cpu->esi + 0xACu);
    cpu->edx = lift_load32(cpu->esi + 0xA4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"EBX:\t0x%08x\tECX\t0x%08x\tEDX:\t0x%08x\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5E5Bu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xBCu);
    cpu->ecx = lift_load32(cpu->esi + 0xB4u);
    cpu->edx = lift_load32(cpu->esi + 0xB8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"EIP:\t0x%08x\tEBP:\t0x%08x\tSegCs:\t0x%08x\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5E7Bu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xC8u);
    cpu->ecx = lift_load32(cpu->esi + 0xC4u);
    cpu->edx = lift_load32(cpu->esi + 0xC0u);
    cpu->esp += 0x44u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"EFlags:\t0x%08x\tESP:\t0x%08x\tSegSs:\t0x%08x\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5E9Eu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D5EB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5EB0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->esp + 0xFFFFF4F8u);
    cpu->esp -= 0xB08u;
    lift_push32(cpu, 0xFFFFFFFEu); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x90u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF0u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esp);
    cpu->edi = lift_load32(cpu->ebp + 0xB10u);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->edi);
    cpu->esi = lift_load32(cpu->ebp + 0xB14u);
    lift_store32(cpu->ebp + 0xFFFFFFD8u, cpu->esi);
    if ((uint8_t)(g_sfera_crash_runtime.report_pending) == (uint8_t)(0u)) goto label_000D5FB1;
    g_sfera_crash_runtime.report_pending = (uint8_t)(0u);
    lift_push32(cpu, 0x208u); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x8FCu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D5F2Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5F30u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x206u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x8FCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetModuleFileNameA), LIFT_CODE_TOKEN_VA(0x4D5F41u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5F47u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D5F5D;
    lift_push32(cpu, (uint32_t)(uintptr_t)"Unknown");
    cpu->edx = (uint32_t)(cpu->ebp + 0x8FCu);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::lstrcpyA), LIFT_CODE_TOKEN_RVA(0xD5F57u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD5F5Du);
    label_000D5F5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5F5Du);
    cpu->eax = (uint32_t)(cpu->ebp + 0x8FCu);
    label_000D5F63: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5F63u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000D5F63;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000D5F70: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5F70u);
    --cpu->eax;
    cpu->edx = (uint32_t)(cpu->ebp + 0x8FCu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000D5F80;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Cu)) goto label_000D5F70;
    label_000D5F80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5F80u);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Cu)) goto label_000D5F88;
    ++cpu->eax;
    goto label_000D5F8E;
    label_000D5F88: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5F88u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x8FCu);
    label_000D5F8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5F8Eu);
    lift_store32(cpu->ebp + 0xFFFFFFD0u, cpu->eax);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 0x3E8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::lstrcpyA), LIFT_CODE_TOKEN_VA(0x4D5F99u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5F9Fu);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000D5FB8;
    lift_push32(cpu, (uintptr_t)"pExceptPtrs == NULL"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5FAEu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000D5FB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5FB1u);
    cpu->eax = 0u;
    goto label_000D62DD;
    label_000D5FB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5FB8u);
    cpu->ebx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000D5FCC;
    lift_push32(cpu, (uintptr_t)"Exception == NULL"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5FC9u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000D5FCC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5FCCu);
    cpu->esi = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->ebp + 0xFFFFFFDCu, cpu->esi);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000D5FE4;
    lift_push32(cpu, (uintptr_t)"Context == NULL"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D5FE1u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000D5FE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5FE4u);
    lift_push32(cpu, 0x208u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x5F0u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D5FF2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5FF7u);
    cpu->esp += 0xCu;
    cpu->edi = (uint32_t)(uintptr_t)"Unknown";
    lift_push32(cpu, 0x1Cu);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFF60u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0xB8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::VirtualQuery), LIFT_CODE_TOKEN_VA(0x4D600Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6015u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D6043;
    lift_push32(cpu, 0x206u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x5F0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFF64u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetModuleFileNameA), LIFT_CODE_TOKEN_VA(0x4D602Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6032u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D6043;
    cpu->eax = (uint32_t)(cpu->ebp + 0x5F0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6041u); lift_push32(cpu, r); sfera_sub_004D5B90(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    label_000D6043: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6043u);
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->eax = lift_load32(cpu->esi + 0xB8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0xBCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D605Au); lift_push32(cpu, r); sfera_sub_004D5980(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 0x3E8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s caused %s (0x%08x) \r\nin %s at %04x:%08x\r\n\r\n");
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6070u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x20u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6078u); lift_push32(cpu, r); sfera_sub_004D5760(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->ebx)) != (uint32_t)(0xC0000005u)) goto label_000D60BE;
    if ((uint32_t)(lift_load32(cpu->ebx + 0x10u)) < (uint32_t)(2u)) goto label_000D60BE;
    cpu->eax = (uint32_t)(uintptr_t)"Read from";
    if ((uint32_t)(lift_load32(cpu->ebx + 0x14u)) == (uint32_t)(0u)) goto label_000D6096;
    cpu->eax = (uint32_t)(uintptr_t)"Write to";
    label_000D6096: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6096u);
    cpu->ecx = lift_load32(cpu->ebx + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s location %08x caused an access violation\r\n");
    cpu->edx = (uint32_t)(cpu->ebp);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::wsprintfA), LIFT_CODE_TOKEN_VA(0x4D60A4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D60AAu);
    cpu->eax = (uint32_t)(cpu->ebp);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D60BBu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000D60BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D60BEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D60C3u); lift_push32(cpu, r); sfera_sub_004D5E10(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)"\r\nBytes at CS:EIP:\r\n"); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D60CEu); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->edx = lift_load32(cpu->esi + 0xB8u);
    lift_store32(cpu->ebp + 0xFFFFFFD4u, cpu->edx);
    cpu->ebx = 0u;
    cpu->edi = (uint32_t)(cpu->ebx + 0xFFFFFFFEu);
    label_000D60DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D60DFu);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(0x10u)) goto label_000D6138;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx = lift_load8(cpu->ebx + cpu->eax);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%02x ");
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6104u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->edi);
    ++cpu->ebx;
    goto label_000D60DF;
    label_000D6138: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6138u);
    cpu->ebx = cpu->esi;
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6142u); lift_push32(cpu, r); sfera_sub_004D5BC0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)"ERRORLOG.TXT"); lift_push32(cpu, (uintptr_t)"\r\n===== [end of %s] =====\r\n"); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6152u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    if ((int32_t)(uint32_t)(g_sfera_crash_report_runtime.report_length) <= (int32_t)(uint32_t)(0u)) goto label_000D6186;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.report_text[0]);
    lift_native_call(cpu, native_function_address32(&::lstrlenA), LIFT_CODE_TOKEN_VA(0x4D6169u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D616Fu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.report_text[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::WriteFile), LIFT_CODE_TOKEN_VA(0x4D6176u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D617Cu);
    g_sfera_crash_report_runtime.report_length = (uint32_t)(0u);
    label_000D6186: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6186u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"CRASH.DMP");
    cpu->ebx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    lift_push32(cpu, cpu->ebx);
    cpu->edi = native_function_address32(&::lstrcpyA);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD6197u), LIFT_CODE_TOKEN_RVA(0xD6195u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6197u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x80000080u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x40000000u);
    cpu->edx = (uint32_t)(cpu->ebp + 0x8FCu);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x4D61B0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D61B6u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_000D61CE;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D61C7u); lift_push32(cpu, r); sfera_sub_004D55F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0xD61C8u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD61CEu);
    label_000D61CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D61CEu);
    lift_native_call(cpu, native_function_address32(&::IsDebuggerPresent), LIFT_CODE_TOKEN_VA(0x4D61CEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D61D4u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D5FB1;
    lift_push32(cpu, (uintptr_t)"CrashReport.exe"); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD61E4u), LIFT_CODE_TOKEN_RVA(0xD61E2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D61E4u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x8FCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x7F8u);
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD61F4u), LIFT_CODE_TOKEN_RVA(0xD61F2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D61F4u);
    lift_push32(cpu, (uint32_t)(uintptr_t)" \"");
    cpu->edx = (uint32_t)(cpu->ebp + 0x7F8u);
    lift_push32(cpu, cpu->edx);
    cpu->esi = native_function_address32(&::lstrcatA);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD6208u), LIFT_CODE_TOKEN_RVA(0xD6206u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6208u);
    lift_push32(cpu, 0x208u); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x8FCu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D6216u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D621Bu);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x206u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x8FCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetModuleFileNameA), LIFT_CODE_TOKEN_VA(0x4D622Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6232u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x8FCu);
    label_000D6238: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6238u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000D6238;
    (void)cpu;
    label_000D6240: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6240u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ebp + 0x8FCu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000D6250;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Cu)) goto label_000D6240;
    label_000D6250: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6250u);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Cu)) goto label_000D6258;
    ++cpu->eax;
    goto label_000D625E;
    label_000D6258: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6258u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x8FCu);
    label_000D625E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D625Eu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->ebp + 0x7F8u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD6268u), LIFT_CODE_TOKEN_RVA(0xD6266u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6268u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"\"");
    cpu->eax = (uint32_t)(cpu->ebp + 0x7F8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD6276u), LIFT_CODE_TOKEN_RVA(0xD6274u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6276u);
    lift_push32(cpu, 0x44u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF7Cu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D6281u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6286u);
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFF7Cu, 0x44u);
    lift_store32(cpu->ebp + 0xFFFFFFA8u, 1u);
    cpu->edx = 5u;
    lift_store16(cpu->ebp + 0xFFFFFFACu, cpu->edx & 0xFFFFu);
    cpu->eax = 0u;
    lift_store32(cpu->ebp + 0xFFFFFFC0u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFC4u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFC8u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFCCu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF7Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0x7F8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateProcessA), LIFT_CODE_TOKEN_VA(0x4D62D1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D62D7u);
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    label_000D62DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D62DDu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = (uint32_t)(cpu->ebp + 0xB08u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D610D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D610Du);
    cpu->eax = 1u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6113(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000D6113;
    label_000D5FB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D5FB1u);
    cpu->eax = 0u;
    goto label_000D62DD;
    label_000D60DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D60DFu);
    lift_store32(cpu->ebp + 0xFFFFFFE0u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(0x10u)) goto label_000D6138;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx = lift_load8(cpu->ebx + cpu->eax);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%02x ");
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6104u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->edi);
    ++cpu->ebx;
    goto label_000D60DF;
    label_000D6113: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6113u);
    cpu->esp = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"\077\077 ");
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6124u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->edi = 0xFFFFFFFEu;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->edi);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFDCu);
    cpu->ebx = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    ++cpu->ebx;
    goto label_000D60DF;
    label_000D6138: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6138u);
    cpu->ebx = cpu->esi;
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6142u); lift_push32(cpu, r); sfera_sub_004D5BC0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)"ERRORLOG.TXT"); lift_push32(cpu, (uintptr_t)"\r\n===== [end of %s] =====\r\n"); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6152u); lift_push32(cpu, r); sfera_sub_004D5590(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    if ((int32_t)(uint32_t)(g_sfera_crash_report_runtime.report_length) <= (int32_t)(uint32_t)(0u)) goto label_000D6186;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFDCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.report_text[0]);
    lift_native_call(cpu, native_function_address32(&::lstrlenA), LIFT_CODE_TOKEN_VA(0x4D6169u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D616Fu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.report_text[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::WriteFile), LIFT_CODE_TOKEN_VA(0x4D6176u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D617Cu);
    g_sfera_crash_report_runtime.report_length = (uint32_t)(0u);
    label_000D6186: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6186u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"CRASH.DMP");
    cpu->ebx = lift_load32(cpu->ebp + 0xFFFFFFD0u);
    lift_push32(cpu, cpu->ebx);
    cpu->edi = native_function_address32(&::lstrcpyA);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD6197u), LIFT_CODE_TOKEN_RVA(0xD6195u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6197u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x80000080u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x40000000u);
    cpu->edx = (uint32_t)(cpu->ebp + 0x8FCu);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x4D61B0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D61B6u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_000D61CE;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D61C7u); lift_push32(cpu, r); sfera_sub_004D55F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0xD61C8u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD61CEu);
    label_000D61CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D61CEu);
    lift_native_call(cpu, native_function_address32(&::IsDebuggerPresent), LIFT_CODE_TOKEN_VA(0x4D61CEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D61D4u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D5FB1;
    lift_push32(cpu, (uintptr_t)"CrashReport.exe"); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD61E4u), LIFT_CODE_TOKEN_RVA(0xD61E2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D61E4u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x8FCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x7F8u);
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD61F4u), LIFT_CODE_TOKEN_RVA(0xD61F2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D61F4u);
    lift_push32(cpu, (uint32_t)(uintptr_t)" \"");
    cpu->edx = (uint32_t)(cpu->ebp + 0x7F8u);
    lift_push32(cpu, cpu->edx);
    cpu->esi = native_function_address32(&::lstrcatA);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD6208u), LIFT_CODE_TOKEN_RVA(0xD6206u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6208u);
    lift_push32(cpu, 0x208u); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x8FCu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D6216u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D621Bu);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x206u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x8FCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetModuleFileNameA), LIFT_CODE_TOKEN_VA(0x4D622Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6232u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x8FCu);
    label_000D6238: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6238u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000D6238;
    (void)cpu;
    label_000D6240: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6240u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ebp + 0x8FCu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000D6250;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Cu)) goto label_000D6240;
    label_000D6250: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6250u);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Cu)) goto label_000D6258;
    ++cpu->eax;
    goto label_000D625E;
    label_000D6258: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6258u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x8FCu);
    label_000D625E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D625Eu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->ebp + 0x7F8u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD6268u), LIFT_CODE_TOKEN_RVA(0xD6266u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6268u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"\"");
    cpu->eax = (uint32_t)(cpu->ebp + 0x7F8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD6276u), LIFT_CODE_TOKEN_RVA(0xD6274u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6276u);
    lift_push32(cpu, 0x44u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF7Cu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4D6281u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6286u);
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFF7Cu, 0x44u);
    lift_store32(cpu->ebp + 0xFFFFFFA8u, 1u);
    cpu->edx = 5u;
    lift_store16(cpu->ebp + 0xFFFFFFACu, cpu->edx & 0xFFFFu);
    cpu->eax = 0u;
    lift_store32(cpu->ebp + 0xFFFFFFC0u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFC4u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFC8u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFCCu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF7Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0x7F8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateProcessA), LIFT_CODE_TOKEN_VA(0x4D62D1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D62D7u);
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    label_000D62DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D62DDu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = (uint32_t)(cpu->ebp + 0xB08u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6300u);
    cpu->esp -= 0xA8u;
    cpu->eax = lift_load32(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000D65A7;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000D65A7;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D65A7;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::lstrcpyA);
    lift_push32(cpu, (uintptr_t)"unknown Windows version"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD634Cu), LIFT_CODE_TOKEN_RVA(0xD634Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D634Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->edi, 0u);
    lift_store32(cpu->esp + 0x20u, 0x94u);
    lift_native_call(cpu, native_function_address32(&::GetVersionExA), LIFT_CODE_TOKEN_VA(0x4D635Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6365u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D6383;
    label_000D6369: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6369u);
    cpu->ebx = lift_pop32(cpu);
    label_000D636A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D636Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xA8u;
    lift_return(cpu, 4u, stop_address); return;
    label_000D6383: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6383u);
    cpu->edx = lift_load16(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, (uintptr_t)"%u.%u.%u"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::wsprintfA), LIFT_CODE_TOKEN_VA(0x4D63AEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D63B4u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(1u)) goto label_000D64CA;
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) != (uint32_t)(4u)) goto label_000D659C;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xAu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000D643B;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x3B6u)) goto label_000D63F1;
    lift_push32(cpu, (uintptr_t)"Windows 95"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD63E7u), LIFT_CODE_TOKEN_RVA(0xD63E5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D63E7u);
    lift_store32(cpu->edi, cpu->ebp);
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D63F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D63F1u);
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFC49u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(0x81u)) goto label_000D6418;
    lift_push32(cpu, (uintptr_t)"Windows 95 SP1"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD6407u), LIFT_CODE_TOKEN_RVA(0xD6405u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6407u);
    lift_store32(cpu->edi, 2u);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D6418: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6418u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x438u)) goto label_000D6438;
    lift_push32(cpu, (uintptr_t)"Windows 95 OSR2"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD6427u), LIFT_CODE_TOKEN_RVA(0xD6425u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6427u);
    lift_store32(cpu->edi, 3u);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D6438: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6438u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xAu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_000D643B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D643Bu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D64A8;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x7CEu)) goto label_000D645D;
    lift_push32(cpu, (uintptr_t)"Windows 98"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD644Cu), LIFT_CODE_TOKEN_RVA(0xD644Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D644Cu);
    lift_store32(cpu->edi, 4u);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D645D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D645Du);
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFF831u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0xB7u)) goto label_000D6484;
    lift_push32(cpu, (uintptr_t)"Windows 98 SP1"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD6473u), LIFT_CODE_TOKEN_RVA(0xD6471u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6473u);
    lift_store32(cpu->edi, 5u);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D6484: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6484u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x887u)) goto label_000D659C;
    lift_push32(cpu, (uintptr_t)"Windows 98 SE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD6497u), LIFT_CODE_TOKEN_RVA(0xD6495u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6497u);
    lift_store32(cpu->edi, 6u);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D64A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D64A8u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(0x5Au)) goto label_000D659C;
    lift_push32(cpu, (uintptr_t)"Windows ME"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD64B9u), LIFT_CODE_TOKEN_RVA(0xD64B7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D64B9u);
    lift_store32(cpu->edi, 7u);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D64CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D64CAu);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(2u)) goto label_000D6589;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_000D64FE;
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) != (uint32_t)(0x33u)) goto label_000D659C;
    lift_push32(cpu, (uintptr_t)"Windows NT 3.51"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD64EFu), LIFT_CODE_TOKEN_RVA(0xD64EDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D64EFu);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    lift_store32(cpu->edi, 0x65u);
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D64FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D64FEu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_000D6527;
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) != (uint32_t)(0u)) goto label_000D659C;
    lift_push32(cpu, (uintptr_t)"Windows NT 4"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD6516u), LIFT_CODE_TOKEN_RVA(0xD6514u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6516u);
    lift_store32(cpu->edi, 0x66u);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D6527: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6527u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_000D659C;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D654D;
    lift_push32(cpu, (uintptr_t)"Windows 2000"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD653Cu), LIFT_CODE_TOKEN_RVA(0xD653Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D653Cu);
    lift_store32(cpu->edi, 0x67u);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D654D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D654Du);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000D656B;
    lift_push32(cpu, (uintptr_t)"Windows XP"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD655Au), LIFT_CODE_TOKEN_RVA(0xD6558u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D655Au);
    lift_store32(cpu->edi, 0x68u);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D656B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D656Bu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_000D659C;
    lift_push32(cpu, (uintptr_t)"Windows 2003 Server"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD6578u), LIFT_CODE_TOKEN_RVA(0xD6576u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6578u);
    lift_store32(cpu->edi, 0x69u);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D6589: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6589u);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(3u)) goto label_000D659C;
    lift_push32(cpu, (uintptr_t)"Windows CE"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD6596u), LIFT_CODE_TOKEN_RVA(0xD6594u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6596u);
    lift_store32(cpu->edi, 0xC9u);
    label_000D659C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D659Cu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    goto label_000D6369;
    label_000D65A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D65A7u);
    cpu->eax = 0u;
    goto label_000D636A;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D65B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D65B0u);
    cpu->esp -= 0x3ECu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x3F4u);
    cpu->edx = 0x3E8u;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D65DAu); lift_push32(cpu, r); sfera_sub_0044BFE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"Exception!\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D65E4u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D65EDu); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"  ";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D65F7u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4D65FCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6602u);
    cpu->esp += 4u;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D660Eu); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6613u); lift_push32(cpu, r); sfera_sub_00451DC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"End of exception\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D661Du); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_warning_log_runtime.object[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6627u); lift_push32(cpu, r); sfera_sub_0049B470(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"End of warning flush\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6631u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0x80000000u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x40000000u); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0]);
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x4D6648u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D664Eu);
    g_sfera_crash_report_runtime.error_log_handle = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000D66E4;
    cpu->ecx = (uint32_t)(uintptr_t)"Writing  ";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6666u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6670u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D667Au); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_crash_report_runtime.error_log_handle;
    lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SetFilePointer), LIFT_CODE_TOKEN_VA(0x4D6687u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D668Du);
    cpu->edx = g_sfera_crash_report_runtime.error_log_handle;
    lift_push32(cpu, (uintptr_t)"start"); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D669Fu); lift_push32(cpu, r); sfera_sub_004D5EB0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = g_sfera_crash_report_runtime.error_log_handle;
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x4D66AAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D66B0u);
    g_sfera_crash_report_runtime.error_log_handle = (uint32_t)(0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D66BFu); lift_push32(cpu, r); sfera_sub_00434D90(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D66CA;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD66CAu); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    label_000D66CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D66CAu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x3ECu;
    lift_return(cpu, 4u, stop_address); return;
    label_000D66E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D66E4u);
    cpu->ecx = (uint32_t)(uintptr_t)"Could not open  ";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D66EEu); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D66F8u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6702u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x3ECu;
    lift_return(cpu, 4u, stop_address); return;
}
