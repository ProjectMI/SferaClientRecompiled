#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_0047AB30(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2]; double x87_p0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x418u;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 == 1u) goto label_0007AF8D;
    cpu->edx = g_sfera_graphics_runtime.display_height;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) != 0u);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_graphics_runtime.display_width;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    g_sfera_interface.showLoadingScreen((cpu->ecx & 255u) != 0u, static_cast<std::int32_t>(cpu->edx), static_cast<std::int32_t>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)), (*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u) & 255u) != 0u); cpu->esp += 8u;
    cpu->esi = native_function_address32(&::Sleep);

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    cpu->edi |= 0xFFFFFFFFu;
    cpu->ecx = 0u;
    g_sfera_graphics_runtime.rebuild_percent = cpu->edi;
    GameInterface::updateLoadingProgress(cpu->ecx);
    cpu->ecx = 0u;
    g_sfera_graphics_runtime.rebuild_percent = cpu->edi;
    GameInterface::updateLoadingProgress(cpu->ecx);
    cpu->ecx = 0u;
    g_sfera_effect_manager.detail_setting = cpu->ecx;

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    g_sfera_effect_manager.initialize();

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    cpu->ecx = (uintptr_t)"models\\materls.mtr";
    g_sfera_materials.load(reinterpret_cast<const char*>(cpu->ecx));

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    TerrainAssets::loadMap();

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    cpu->edx = 0x42C7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x1030u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 0u;
    if (cpu->eax == 0u) goto label_0007AC27;
    lift_push32(cpu, (uintptr_t)"sky.txt");
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(reinterpret_cast<SkyEnvironment*>(cpu->ecx)->load(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)))));  cpu->esp += 4u;
    goto label_0007AC29;
    label_0007AC27:
    cpu->eax = 0u;
    label_0007AC29:
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20) == 0u;
    *(uint32_t*)(cpu->esp + 0x420u) = cpu->edi;
    g_sfera_primary_sky_environment = reinterpret_cast<decltype(g_sfera_primary_sky_environment)>(cpu->eax);
    if (sub_pred[0]) goto label_0007AC89;
    cpu->edx = 0x42C9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x1030u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 1u;
    if (cpu->eax == 0u) goto label_0007AC7B;
    lift_push32(cpu, (uintptr_t)"landscape_hr\\sky_hr.txt");
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(reinterpret_cast<SkyEnvironment*>(cpu->ecx)->load(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)))));  cpu->esp += 4u;
    goto label_0007AC7D;
    label_0007AC7B:
    cpu->eax = 0u;
    label_0007AC7D:
    *(uint32_t*)(cpu->esp + 0x420u) = cpu->edi;
    g_sfera_main_aux_runtime.secondary_world_manager = reinterpret_cast<decltype(g_sfera_main_aux_runtime.secondary_world_manager)>(cpu->eax);
    label_0007AC89:

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    g_sfera_models.initialize();
    g_sfera_models.addFolder("models\\");
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20 == 0u) goto label_0007ACF8;
    lift_push32(cpu, (uintptr_t)"models_hr\\");
    g_sfera_models.addFolder(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    label_0007ACF8:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21 == 0u) goto label_0007AD11;
    lift_push32(cpu, (uintptr_t)"models_ph\\");
    g_sfera_models.addFolder(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    label_0007AD11:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22 == 0u) goto label_0007AD2A;
    lift_push32(cpu, (uintptr_t)"models_rd\\");
    g_sfera_models.addFolder(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    label_0007AD2A:
    g_sfera_models.finishRegistration();
    cpu->edx = 0x42DCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esp + 0x10u) = (uintptr_t)"xadd\\";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x7540u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 3u;
    if (cpu->eax == 0u) goto label_0007AD7C;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(reinterpret_cast<SphereRender::CharacterModels*>(cpu->ecx)->load(reinterpret_cast<const char* const*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u))));  cpu->esp += 8u;
    goto label_0007AD7E;
    label_0007AD7C:
    cpu->eax = 0u;
    label_0007AD7E:
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.minimum_lod_distance.f32);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_p0; 
    cpu->ecx = cpu->eax;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32);
    *(uint32_t*)(cpu->esp + 0x428u) = cpu->edi;
    *(float*)(cpu->esp) = x87_p0; 
    g_sfera_recovered_static_runtime.render_state_08 = reinterpret_cast<decltype(g_sfera_recovered_static_runtime.render_state_08)>(cpu->eax);
    reinterpret_cast<SphereRender::CharacterModels*>(cpu->ecx)->setDistances(*reinterpret_cast<const float*>(cpu->esp), *reinterpret_cast<const float*>(cpu->esp + 4u));  cpu->esp += 8u;

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    cpu->edx = 0x42E3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(new Contours(2000, 2999)));
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    label_0007ADEF:
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = cpu->edi;
    g_sfera_client_process_runtime.client_object = reinterpret_cast<decltype(g_sfera_client_process_runtime.client_object)>(cpu->eax);
    reinterpret_cast<Contours*>(cpu->ecx)->load();

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    cpu->edx = 0x42F3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, sizeof(WeatherScenarios));
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 5u;
    if (cpu->eax == 0u) goto label_0007AE43;
    lift_push32(cpu, (uintptr_t)"landscape\\weather.txt");
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(std::construct_at(reinterpret_cast<WeatherScenarios*>(cpu->ecx))->load(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)))));  cpu->esp += 4u;
    goto label_0007AE45;
    label_0007AE43:
    cpu->eax = 0u;
    label_0007AE45:
    sub_pred[1] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20) == 0u;
    *(uint32_t*)(cpu->esp + 0x420u) = cpu->edi;
    g_sfera_weather_runtime.standard = reinterpret_cast<WeatherScenarios*>(cpu->eax);
    if (sub_pred[1]) goto label_0007AEA5;
    cpu->edx = 0x42F5u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, sizeof(WeatherScenarios));
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 6u;
    if (cpu->eax == 0u) goto label_0007AE97;
    lift_push32(cpu, (uintptr_t)"landscape_hr\\weather_hr.txt");
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(std::construct_at(reinterpret_cast<WeatherScenarios*>(cpu->ecx))->load(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)))));  cpu->esp += 4u;
    goto label_0007AE99;
    label_0007AE97:
    cpu->eax = 0u;
    label_0007AE99:
    *(uint32_t*)(cpu->esp + 0x420u) = cpu->edi;
    g_sfera_weather_runtime.highres = reinterpret_cast<WeatherScenarios*>(cpu->eax);
    if (g_sfera_weather_runtime.highres == nullptr) g_sfera_weather_runtime.highres = g_sfera_weather_runtime.standard;
    label_0007AEA5:

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    g_sfera_vegetation.patterns.loadPlanting();
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"cam_cube";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_world_objects.create(reinterpret_cast<const char*>(cpu->ecx), reinterpret_cast<SferaMbcProcessRecord*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u) != 0u));  cpu->esp += 8u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)0u) goto label_0007AED3;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7AED3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7AED3u));
    label_0007AED3:
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object_handles.data));
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->eax != 0u) goto label_0007AF34;
    label_0007AEDF:
    lift_push32(cpu, 1u); lift_push32(cpu, 5u);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"cam_cube";
    *(uint8_t*)(cpu->eax + 0x141u) = 0u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_world_objects.create(reinterpret_cast<const char*>(cpu->ecx), reinterpret_cast<SferaMbcProcessRecord*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u) != 0u));  cpu->esp += 8u;
    g_sfera_vegetation.initialize();

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(0x32u);
    cpu->edx = 0x4304u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, sizeof(SphereUI::ChatFilter));
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x420u) = 7u;
    if (cpu->eax == 0u) goto label_0007AF7C;
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(std::construct_at(reinterpret_cast<SphereUI::ChatFilter*>(cpu->ecx))));
    goto label_0007AF7E;
    label_0007AF34:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_0007AEDF;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>((*reinterpret_cast<const std::uint32_t*>(cpu->esp) > 5000u && *reinterpret_cast<const std::uint32_t*>(cpu->esp) != UINT32_MAX) ? reinterpret_cast<SphereRender::Model*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)) : g_sfera_models.model(*reinterpret_cast<const std::uint32_t*>(cpu->esp)))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0007AF55;
    cpu->eax = (uintptr_t)"<none>";
    label_0007AF55:
    lift_push32(cpu, 0x42FAu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47AF6Au));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7AF7Cu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x7AF7Cu));
    label_0007AF7C:
    cpu->eax = 0u;
    label_0007AF7E:
    g_sfera_input_device_runtime.shared_object = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19) = 1u;
    label_0007AF8D:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x418u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0047D040(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2]; double x87_v0, x87_v1;
    (void)stop_address;
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->esi = 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_04) = cpu->esi;
    cpu->edi = 0u;
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    (void)cpu;
    label_0007D070:
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    cpu->ecx = cpu->eax;
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edi += cpu->ecx;
    if ((cpu->edi == 0x2710u) || ((int32_t)(cpu->edi) < (int32_t)(0x2710u))) goto label_0007D08A;
    cpu->edi = 0x2710u;
    label_0007D08A:
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    cpu->ecx = cpu->edi + 0x1Au;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x4EC4EC4Fu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->ebp = cpu->edx;
    cpu->ebp = cpu->ebp >> 31u;
    cpu->ebp += cpu->edx;
    cpu->edx = cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xFFFFFFCCu);
    cpu->edi += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    if (cpu->ebp != cpu->ebx) goto label_0007D0E5;
    cpu->ecx = 0x34u;
    cpu->ecx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x66666667u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if ((int32_t)cpu->eax <= (int32_t)0x32u) goto label_0007D0D9;
    cpu->eax = 0x14u;
    goto label_0007D0DD;
    label_0007D0D9:
    if ((int32_t)cpu->eax <= (int32_t)cpu->esi) goto label_0007D0E5;
    label_0007D0DD:
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_RVA(0x7D0DFu));
    label_0007D0E5:
    cpu->ecx = 0u;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->ebx) goto label_0007D47C;
    label_0007D100:
    cpu->eax = g_sfera_pending_key_runtime.count;
    if (cpu->eax == cpu->ebx) goto label_0007D136;
    cpu->ecx = g_sfera_pending_key_runtime.key_codes[0];
    --cpu->eax;
    g_sfera_world_load_runtime.active_tool_context = cpu->ecx;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebx) goto label_0007D131;
    std::memmove((void*)((uintptr_t)&g_sfera_pending_key_runtime.key_codes[0]),(void*)((uintptr_t)&g_sfera_pending_key_runtime.key_codes[1]),(cpu->eax)*4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = 1u;
    label_0007D131:
    g_sfera_pending_key_runtime.count = cpu->eax;
    label_0007D136:
    cpu->eax = g_sfera_scene_control_runtime.context_count;
    if (cpu->eax == cpu->ebx) goto label_0007D16C;
    cpu->edx = g_sfera_scene_control_runtime.context_queue[0];
    --cpu->eax;
    g_sfera_scene_control_runtime.active_context = cpu->edx;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebx) goto label_0007D167;
    std::memmove((void*)((uintptr_t)&g_sfera_scene_control_runtime.context_queue[0]),(void*)((uintptr_t)&g_sfera_scene_control_runtime.context_queue[1]),(cpu->eax)*4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = 1u;
    label_0007D167:
    g_sfera_scene_control_runtime.context_count = cpu->eax;
    label_0007D16C:
    cpu->eax = g_sfera_direct_input_runtime.takeKeyPress();
    g_sfera_recovered_static_runtime.graphics_state = cpu->eax;
    if (cpu->eax != cpu->esi) goto label_0007D186;
    if (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.escape_without_query == cpu->esi) goto label_0007D71A;
    label_0007D186:
    if (g_sfera_input_device_runtime.render_state != cpu->ebx) goto label_0007D735;
    if (cpu->eax != 0x58u) goto label_0007D19F;
    g_sfera_landscape_map_runtime.show_fps = (uint64_t)(g_sfera_landscape_map_runtime.show_fps) ^ (uint64_t)(cpu->esi);
    goto label_0007D1AA;
    label_0007D19F:
    if (cpu->eax != 0x41u) goto label_0007D1AA;
    g_sfera_recovered_static_runtime.client_state_05 = (uint64_t)(g_sfera_recovered_static_runtime.client_state_05) ^ (uint64_t)(cpu->esi);
    label_0007D1AA:
    g_sfera_direct_input_runtime.pollKeyboard();
    g_sfera_main_input_state_runtime.mouse = g_sfera_direct_input_runtime.pollMouse();
    if (((g_sfera_direct_input_runtime.view_adjust_state) & (0x80u)) == 0u) goto label_0007D226;
    g_sfera_graphics_runtime.view_parameter = (((((((double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.mouse.dx)))))) * (0.0005000000237487257)))) + (((double)g_sfera_graphics_runtime.view_parameter)));
    x87_v0 = 0.0;
    x87_v1 = (double)g_sfera_graphics_runtime.view_parameter;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_0007D1FF; }
    x87_v0 = (x87_v0) + (1.0);
    g_sfera_graphics_runtime.view_parameter = x87_v0; 
    x87_v0 = (double)g_sfera_graphics_runtime.view_parameter;
    label_0007D1FF:
    { const double lift_left=1.0; const double lift_right=x87_v0; if (!(lift_left<=lift_right)) goto label_0007D218; }
    x87_v0 = (x87_v0) - (1.0);
    g_sfera_graphics_runtime.view_parameter = x87_v0; 
    goto label_0007D21A;
    label_0007D218:
    x87_v0 = x87_v0; 
    label_0007D21A:
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.mouse.dy) = cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.mouse.dx) = cpu->ebx;
    label_0007D226:
    GameInterface::updateInput();
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.mouse.wheel;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.mouse.buttons;
    cpu->edx = g_sfera_world_load_runtime.active_tool_context;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_scene_control_runtime.active_context;
    g_sfera_interface.update(static_cast<std::uint8_t>(cpu->ecx), static_cast<std::uint8_t>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), static_cast<std::int32_t>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u))); cpu->esp += 8u;
    if (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_08 != cpu->esi) goto label_0007D2CF;
    if (g_sfera_recovered_static_runtime.interaction_enabled != cpu->ebx) goto label_0007D2CF;
    if (g_sfera_recovered_static_runtime.render_gate != cpu->ebx) goto label_0007D2CF;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13 == cpu->ebx) goto label_0007D2C8;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebx) goto label_0007D27D;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D27Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7D27Du));
    label_0007D27D:
    x87_v0 = (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.mouse.dx))));
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object_handles.data));
    cpu->eax = *(uint32_t*)(cpu->edx);
    x87_v0 = (x87_v0) * (0.5);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->eax + 8u)));
    *(float*)(cpu->eax + 8u) = x87_v0; 
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebx) goto label_0007D2AB;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D2ABu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x7D2ABu));
    label_0007D2AB:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object_handles.data));
    cpu->eax = *(uint32_t*)(cpu->eax);
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    x87_v1 = (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.mouse.dy))));
    x87_v1 = (x87_v1) * (0.5);
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->eax + 0x10u) = x87_v0; 
    goto label_0007D322;
    label_0007D2C8:
    g_sfera_motion.updateOrientation();
    goto label_0007D322;
    label_0007D2CF:
    x87_v0 = 0.0;
    cpu->ecx = cpu->esp + 0x30u;
    g_sfera_main_view_state_runtime.view_coefficients[5] = x87_v0;
    g_sfera_main_view_state_runtime.view_coefficients[4] = x87_v0;
    g_sfera_main_view_state_runtime.view_coefficients[3] = x87_v0;
    g_sfera_main_view_state_runtime.view_coefficients[2] = x87_v0;
    g_sfera_main_view_state_runtime.view_coefficients[1] = x87_v0;
    g_sfera_main_view_state_runtime.view_coefficients[0] = x87_v0;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.secondary_vector.z.f32) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.secondary_vector.y.f32) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.secondary_vector.x.f32) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.z.f32) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.y.f32) = x87_v0;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.x.f32) = x87_v0; 
    *reinterpret_cast<SferaMouseInputState*>(cpu->ecx) = g_sfera_direct_input_runtime.pollMouse();
    label_0007D322:
    cpu->ecx = cpu->esi;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D330u)); sfera_sub_004496F0(cpu, LIFT_CODE_TOKEN_VA(0x47D330u));
    cpu->ecx = cpu->esi;
    g_sfera_profiler_runtime.end(cpu->ecx);
    cpu->ecx = 2u;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    if (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_08 != cpu->ebx) goto label_0007D358;
    x87_v0 = (double)0.0052083334885537624f;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    g_sfera_motion.updateControlled(*reinterpret_cast<const float*>(cpu->esp));  cpu->esp += 4u;
    label_0007D358:
    cpu->ecx = 2u;
    g_sfera_profiler_runtime.end(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax != 4u) goto label_0007D396;
    cpu->ecx = cpu->eax + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    x87_v0 = (double)0.02083333395421505f;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    g_sfera_motion.updateObjects(*reinterpret_cast<const float*>(cpu->esp));  cpu->esp += 4u;
    cpu->ecx = 3u;
    g_sfera_profiler_runtime.end(cpu->ecx);
    label_0007D396:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->eax != 6u) goto label_0007D3D7;
    SphereRender::SceneRenderer::adaptFog();
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_16 != cpu->ebx) goto label_0007D3D7;
    cpu->ecx = 4u;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 != cpu->esi) goto label_0007D3CD;
    g_sfera_effect_manager.updateActiveEffects();
    label_0007D3CD:
    cpu->ecx = 4u;
    g_sfera_profiler_runtime.end(cpu->ecx);
    label_0007D3D7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if (cpu->eax != 6u) goto label_0007D40B;
    cpu->eax = g_sfera_landscape_render_runtime.rotation_step;
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    g_sfera_landscape_render_runtime.rotation_step = cpu->eax;
    if (cpu->eax != 0x20u) goto label_0007D401;
    g_sfera_landscape_render_runtime.rotation_step = cpu->ebx;
    label_0007D401:
    TerrainAssets::evictUnused();
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D40Bu)); sfera_sub_00432880(cpu, LIFT_CODE_TOKEN_RVA(0x7D40Bu));
    label_0007D40B:
    cpu->ecx = 5u;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    g_sfera_world_objects.updateExtendedSpatialIndices();
    cpu->ecx = 5u;
    g_sfera_profiler_runtime.end(cpu->ecx);
    x87_v0 = (double)g_sfera_recovered_static_runtime.animation_phase;
    x87_v0 = (x87_v0) + (0.0005000000237487257);
    g_sfera_scene_control_runtime.active_context = cpu->ebx;
    g_sfera_world_load_runtime.active_tool_context = cpu->ebx;
    g_sfera_recovered_static_runtime.animation_phase = x87_v0; 
    x87_v0 = 1.0;
    x87_v1 = (double)g_sfera_recovered_static_runtime.animation_phase;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left>lift_right)) goto label_0007D463; }
    x87_v0 = (x87_v0) - (1.0);
    g_sfera_recovered_static_runtime.animation_phase = x87_v0; 
    goto label_0007D465;
    label_0007D463:
    x87_v0 = x87_v0; 
    label_0007D465:
    g_sfera_vegetation.updateGrassView();
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->ebp) goto label_0007D100;
    label_0007D47C:
    cpu->eax = g_sfera_frame_runtime.frame_state;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0007D49D;
    cpu->eax += cpu->esi;
    g_sfera_frame_runtime.frame_state = cpu->eax;
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    g_sfera_frame_runtime.frame_state_anchor.high = cpu->edx;
    g_sfera_frame_runtime.frame_state_anchor.low = cpu->eax;
    label_0007D49D:
    cpu->ecx = 6u;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    cpu->ecx = 6u;
    g_sfera_profiler_runtime.end(cpu->ecx);
    cpu->ecx = 7u;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 != cpu->esi) goto label_0007D5D4;
    {
        bool useHighResolution = false;
        if (g_sfera_client_config_runtime.state_20 != 0u) {
            const auto* reference = g_sfera_world_objects.object(1u);
            if (reference == nullptr) WorldDiagnostics::fail("Weather update: missing reference object");
            useHighResolution = reference->position.y > 300.0f && reference->position.y < 800.0f;
        }
        auto* weather = useHighResolution ? g_sfera_weather_runtime.highres : g_sfera_weather_runtime.standard;
        if (weather == nullptr) weather = useHighResolution ? g_sfera_weather_runtime.standard : g_sfera_weather_runtime.highres;
        if (weather != nullptr) weather->update(static_cast<std::int32_t>(WorldClock::calendarTicks()), g_sfera_graphics_runtime.environment_factor, g_sfera_weather_runtime.current, SphereWorld::Vegetation::alternatePatterns());
    }
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_10 != cpu->esi) goto label_0007D5C8;
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_11 <= (int32_t)cpu->ebx) goto label_0007D589;
    lift_native_call(cpu, native_function_address32(&SI_GetStreamVolume), LIFT_CODE_TOKEN_VA(0x47D574u));
    cpu->ecx = cpu->esi + cpu->eax;
    cpu->eax = static_cast<std::uint32_t>((SI_SetStreamVolume(static_cast<std::int32_t>(cpu->ecx)), 1u));
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_11) = cpu->ebx;
    goto label_0007D59D;
    label_0007D589:
    lift_native_call(cpu, native_function_address32(&SI_GetStreamVolume), LIFT_CODE_TOKEN_VA(0x47D589u));
    cpu->ecx = cpu->eax;
    cpu->ecx -= cpu->esi;
    cpu->eax = static_cast<std::uint32_t>((SI_SetStreamVolume(static_cast<std::int32_t>(cpu->ecx)), 1u));
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_11) = cpu->esi;
    label_0007D59D:
    g_sfera_client_config_runtime.scalar_01 = ((((double)g_sfera_client_config_runtime.scalar_01)) + (1.0));
    { const double lift_left=(double)g_sfera_client_config_runtime.scalar_01; const double lift_right=50.0; if (!(lift_left>lift_right)) goto label_0007D5C8; }
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_10) = cpu->ebx;
    label_0007D5C8:
    SphereRender::SceneRenderer::drawFrame();
    
    goto label_0007D635;
    label_0007D5D4:
    if (g_sfera_texture_cache_runtime.cache_enabled != cpu->ebx) goto label_0007D5EC;
    if (g_sfera_window_runtime.windowed == cpu->ebx) goto label_0007D635;
    lift_push32(cpu, 0x64u);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_RVA(0x7D5E6u));
    label_0007D5EC:
    x87_v0 = 1.0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_graphics_runtime.d3d_runtime.get()));
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 3u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<CD3D9Device*>(cpu->ecx)->checkResult(reinterpret_cast<CD3D9Device*>(cpu->ecx)->native_device->Clear(*reinterpret_cast<const std::uint32_t*>(cpu->esp), reinterpret_cast<const D3DRECT*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u)), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 8u), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 12u), *reinterpret_cast<const float*>(cpu->esp + 16u), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 20u)), "Clear")); cpu->esp += 24u;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_graphics_runtime.d3d_runtime.get()));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | static_cast<std::uint32_t>(reinterpret_cast<CD3D9Device*>(cpu->ecx)->beginScene());
    if ((cpu->eax & 0xFFu) == 0u) goto label_0007D635;
    GameInterface::drawFrame();
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_graphics_runtime.d3d_runtime.get()));
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<CD3D9Device*>(cpu->ecx)->checkResult(reinterpret_cast<CD3D9Device*>(cpu->ecx)->native_device->EndScene(), "EndScene"));
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_graphics_runtime.d3d_runtime.get()));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<CD3D9Device*>(cpu->ecx)->checkResult(reinterpret_cast<CD3D9Device*>(cpu->ecx)->native_device->Present(reinterpret_cast<const RECT*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)), reinterpret_cast<const RECT*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u)), reinterpret_cast<HWND__*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 8u)), reinterpret_cast<const RGNDATA*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 12u))), "Present")); cpu->esp += 16u;
    label_0007D635:
    cpu->ecx = 7u;
    g_sfera_profiler_runtime.end(cpu->ecx);
    cpu->ecx = 8u;
    g_sfera_profiler_runtime.begin(cpu->ecx);
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 != cpu->esi) goto label_0007D656;
    g_sfera_sound_runtime.update();
    label_0007D656:
    cpu->ecx = 8u;
    g_sfera_profiler_runtime.end(cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D665u)); sfera_sub_0044C160(cpu, LIFT_CODE_TOKEN_VA(0x47D665u));
    if ((uint32_t)(g_sfera_render_lookup_runtime.initialized) == cpu->esi) goto label_0007D752;
    cpu->ecx = 0u;
    g_sfera_profiler_runtime.end(cpu->ecx);
    sub_pred[0] = (uint32_t)((uint64_t)(g_sfera_profiler_runtime.accumulated_ticks[0].high)) == cpu->ebx; sub_pred[1] = (int32_t)((uint32_t)((uint64_t)(g_sfera_profiler_runtime.accumulated_ticks[0].high))) < (int32_t)(cpu->ebx);
    if ((int32_t)((uint32_t)((uint64_t)(g_sfera_profiler_runtime.accumulated_ticks[0].high))) < (int32_t)(cpu->ebx)) goto label_0007D070;
    if ((!sub_pred[0]) && (!sub_pred[1])) goto label_0007D696;
    if ((uint32_t)(g_sfera_profiler_runtime.accumulated_ticks[0].low) <= 0xF4240u) goto label_0007D070;
    label_0007D696:
    cpu->ebp = 0u;
    cpu->esi = 1u;
    cpu->edi = (uintptr_t)&g_sfera_profiler_runtime.report_percent[1];
    label_0007D6B0:
    cpu->edx = g_sfera_profiler_runtime.accumulated_ticks[cpu->esi].high;
    cpu->eax = g_sfera_profiler_runtime.accumulated_ticks[cpu->esi].low;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D6C8u)); sfera_sub_004EED20(cpu, LIFT_CODE_TOKEN_VA(0x47D6C8u));
    lift_push32(cpu, g_sfera_profiler_runtime.accumulated_ticks[0].high); lift_push32(cpu, g_sfera_profiler_runtime.accumulated_ticks[0].low); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D6DBu)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x47D6DBu));
    *(uint32_t*)(cpu->edi) = cpu->eax;
    g_sfera_profiler_runtime.accumulated_ticks[cpu->esi].low = cpu->ebx;
    g_sfera_profiler_runtime.accumulated_ticks[cpu->esi].high = cpu->ebx;
    cpu->edi += 4u;
    cpu->ebp += cpu->eax;
    ++cpu->esi;
    if ((int32_t)cpu->edi <= (int32_t)((uintptr_t)&g_sfera_profiler_runtime.report_percent[8])) goto label_0007D6B0;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_profiler_runtime.report_percent[0])) = cpu->ebp;
    g_sfera_profiler_runtime.accumulated_ticks[0].low = cpu->ebx;
    g_sfera_profiler_runtime.accumulated_ticks[0].high = cpu->ebx;
    cpu->esi = 1u;
    goto label_0007D070;
    label_0007D71A:
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D724u)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x47D724u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D729u)); sfera_sub_0049A730(cpu, LIFT_CODE_TOKEN_VA(0x47D729u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D72Eu)); sfera_sub_004595F0(cpu, LIFT_CODE_TOKEN_VA(0x47D72Eu));
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_RVA(0x7D72Fu));
    label_0007D735:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x13u));
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x17u;
    lift_push32(cpu, cpu->edx);
    g_sfera_input_device_runtime.render_state = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Bu) = cpu->ecx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D752u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x7D752u));
    label_0007D752:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D757u)); sfera_sub_004595F0(cpu, LIFT_CODE_TOKEN_VA(0x47D757u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D75Cu)); sfera_sub_0042EB70(cpu, LIFT_CODE_TOKEN_VA(0x47D75Cu));
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_VA(0x47D75Du));
    cpu->eip = 0x47D763u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_0047D770(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_p0;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x47D773u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetThreadAffinityMask), LIFT_CODE_TOKEN_VA(0x47D77Au));

    const uint32_t launch_guard = (uintptr_t)"/15FCE220-0246-58ec-3EH2-968B3072ACF8";
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_strstr_address32();
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_strstr_address32()))(cpu->edi, launch_guard);

    if (cpu->eax == 0u) goto label_0007D7E5;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"\316\370\350\341\352\340 \347\340\357\363\361\352\340."); lift_push32(cpu, (uintptr_t)"\307\340\357\363\361\352 \357\360\356\350\347\342\356\344\350\362\361\377 \357\360\356\343\360\340\354\354\356\351 Sphere.exe."); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x47D7D7u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0007D7E5:
    cpu->eax = 0u;
    lift_push32(cpu, (uintptr_t)"/locale"); lift_push32(cpu, cpu->edi);
    (*(uint32_t*)(void*)&g_sfera_client_process_runtime.locale[0]) = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_client_process_runtime.locale[4]) = cpu->eax;
    (*(uint16_t*)(void*)&g_sfera_client_process_runtime.locale[8]) = cpu->eax & 0xFFFFu;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_strstr_address32()))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0007D845;
    cpu->eax += 7u;
    label_0007D810:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->ecx & 0xFFu) == 0x20u) goto label_0007D81C;
    if ((cpu->ecx & 0xFFu) != 9u) goto label_0007D81F;
    label_0007D81C:
    ++cpu->eax;
    goto label_0007D810;
    label_0007D81F:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->edx = 0u;
    if ((cpu->ecx & 0xFFu) == 0x20u) goto label_0007D845;
    label_0007D828:
    if ((cpu->ecx & 0xFFu) == 9u) goto label_0007D845;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0007D845;
    if ((int32_t)cpu->edx >= (int32_t)0xAu) goto label_0007D845;
    ++cpu->eax;
    *(uint8_t*)(cpu->edx + ((uintptr_t)&g_sfera_client_process_runtime.locale[0])) = cpu->ecx & 0xFFu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->edx;
    if ((cpu->ecx & 0xFFu) != 0x20u) goto label_0007D828;
    label_0007D845:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_strstr_address32()))(cpu->edi, (uintptr_t)"/login");

    if (cpu->eax == 0u) goto label_0007D85D;
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.gamexp_sid_present) = 1u;
    goto label_0007D8B4;
    label_0007D85D:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_strstr_address32()))(cpu->edi, (uintptr_t)"/gamexp_sid");

    if (cpu->eax == 0u) goto label_0007D9A0;
    cpu->eax += 0xBu;
    label_0007D873:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->ecx & 0xFFu) == 0x20u) goto label_0007D87F;
    if ((cpu->ecx & 0xFFu) != 9u) goto label_0007D882;
    label_0007D87F:
    ++cpu->eax;
    goto label_0007D873;
    label_0007D882:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->edx = 0u;
    if ((cpu->ecx & 0xFFu) == 0x20u) goto label_0007D8AD;
    label_0007D890:
    if ((cpu->ecx & 0xFFu) == 9u) goto label_0007D8AD;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0007D8AD;
    if ((int32_t)cpu->edx >= (int32_t)0x1Eu) goto label_0007D8AD;
    ++cpu->eax;
    *(uint8_t*)(cpu->edx + ((uintptr_t)&g_sfera_main_ui_state_runtime.gamexp_sid[0])) = cpu->ecx & 0xFFu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->edx;
    if ((cpu->ecx & 0xFFu) != 0x20u) goto label_0007D890;
    label_0007D8AD:
    *(uint8_t*)(cpu->edx + ((uintptr_t)&g_sfera_main_ui_state_runtime.gamexp_sid[0])) = 0u;
    label_0007D8B4:
    cpu->ecx = (uintptr_t)"connect.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D8BEu)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x47D8BEu));
    if (cpu->eax != 0u) goto label_0007D8ED;
    cpu->edx = cpu->esp + 8u;
    cpu->ecx = (uintptr_t)"CONNECT_TYPE";
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D8D4u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x47D8D4u));
    if (cpu->eax != 0u) goto label_0007D8E6;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 8u) == 1u;
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled) = 1u;
    if (sub_pred[0]) goto label_0007D8ED;
    label_0007D8E6:
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled) = 0u;
    label_0007D8ED:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D8F4u)); sfera_sub_0042E920(cpu, LIFT_CODE_TOKEN_VA(0x47D8F4u));
    ::InitializeCriticalSection(&g_sfera_network_send_runtime.critical_section);

    ::InitializeCriticalSection(&g_sfera_window_runtime.timing_critical_section);

    ::InitializeCriticalSection(&g_sfera_recovered_static_runtime.scene_lock);
    cpu->ebp = native_function_address32(&::CreateFileA);
    cpu->ebx = native_function_address32(&::CreateDirectoryA);
    cpu->edi = 0u;
    label_0007D920:
    cpu->esi = (uintptr_t)(cpu->edi == 0u ? ".\\logs" : ".\\players");

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CreateFileA)))(cpu->esi, 1u, 0u, 0u, 3u, 0u, 0u);
    if (cpu->eax != 0xFFFFFFFFu) goto label_0007D941;

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CreateDirectoryA)))(cpu->esi, 0u);
    goto label_0007D948;
    label_0007D941:
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0x7D942u));
    label_0007D948:
    cpu->edi += 4u;
    if (cpu->edi < 8u) goto label_0007D920;
    x87_p0 = 0.30000001192092896;
    cpu->esp -= 0x10u;
    *(double*)(cpu->esp + 8u) = x87_p0;
    x87_p0 = 1.0;
    *(double*)(cpu->esp) = x87_p0;
    SphereRender::SceneRenderer::buildColorRemap(*reinterpret_cast<const double*>(cpu->esp), *reinterpret_cast<const double*>(cpu->esp + 8u));  cpu->esp += 16u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = (uintptr_t)&g_sfera_startup_command_line_runtime.text[0];
    cpu->ebp = lift_pop32(cpu);
    g_sfera_startup_command_line_runtime.parser_state = cpu->ecx;
    cpu->edx -= cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    label_0007D987:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0007D987;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D996u)); sfera_sub_00464BA0(cpu, LIFT_CODE_TOKEN_VA(0x47D996u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47D99Bu)); sfera_sub_0045BC60(cpu, LIFT_CODE_TOKEN_VA(0x47D99Bu));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x7D9A0u)); sfera_sub_0047D040(cpu, LIFT_CODE_TOKEN_RVA(0x7D9A0u));
    label_0007D9A0:
    lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"\316\370\350\341\352\340 \347\340\357\363\361\352\340"); lift_push32(cpu, (uintptr_t)"\307\340\357\363\361\352 \357\360\356\350\347\342\356\344\350\362\361\377 \357\360\356\343\360\340\354\354\356\351 launchpoint.exe."); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x47D9AEu));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047D9C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)((uintptr_t)"BM"));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint16_t*)(cpu->esp + 0x10u) = cpu->eax & 0xFFFFu;
    cpu->ebx = cpu->edi + (cpu->edi * 2u);
    cpu->eax = cpu->ebx + 3u;
    cpu->eax &= 0xFFFFFFFCu;
    cpu->edx = cpu->eax;
    cpu->esi = cpu->ecx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"BM") + 2u));
    *(uint8_t*)(cpu->esp + 0x12u) = cpu->ecx & 0xFFu;
    cpu->ecx = cpu->edx + 0x39u;
    cpu->ecx &= 0xFFFFFFFCu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->ecx -= cpu->edx;
    cpu->ecx -= 0x36u;
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->eax;
    cpu->eax -= cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.create(reinterpret_cast<const char*>(cpu->ecx)));
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    cpu->ebx = 0u;
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x36u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x28u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 1u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x18u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xB12u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.write(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<const void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047DB30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x4Eu);
    cpu->edx = (uintptr_t)"MapGenerator.cpp";
    cpu->ecx = 0xC0000u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    lift_push32(cpu, 0x2000u);
    *(uint32_t*)(cpu->esi + 0x54u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, 0x2000u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47DB5Du)); sfera_sub_0047D9C0(cpu, LIFT_CODE_TOKEN_VA(0x47DB5Du));
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0047E850(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->edx < 0xEu) goto label_0007E863;
    if (*(uint32_t*)(cpu->ecx) != 0x52485053u) goto label_0007E863;
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007E863:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E870(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebx = cpu->ecx;
    if (cpu->ebp < 0xEu) goto label_0007E8F2;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"SPHR"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x47E88Du));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_0007E8F2;
    if (*(uint32_t*)(cpu->edi) != cpu->eax) goto label_0007E8BA;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0xEu));
    *(uint8_t*)(cpu->edi) = (uint64_t)(*(uint8_t*)(cpu->edi)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->edi + 1u) = (uint64_t)(*(uint8_t*)(cpu->edi + 1u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->edi + 2u) = (uint64_t)(*(uint8_t*)(cpu->edi + 2u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->edi + 3u) = (uint64_t)(*(uint8_t*)(cpu->edi + 3u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0007E8BA:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 8u));
    *(uint8_t*)(cpu->esi + 9u) = (uint64_t)(*(uint8_t*)(cpu->esi + 9u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 0x11u) = (uint64_t)(*(uint8_t*)(cpu->esi + 0x11u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 0x14u) = (uint64_t)(*(uint8_t*)(cpu->esi + 0x14u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0xEu));
    *(uint8_t*)(cpu->esi + 4u) = (uint64_t)(*(uint8_t*)(cpu->esi + 4u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 5u) = (uint64_t)(*(uint8_t*)(cpu->esi + 5u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 6u) = (uint64_t)(*(uint8_t*)(cpu->esi + 6u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 7u) = (uint64_t)(*(uint8_t*)(cpu->esi + 7u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    cpu->ecx = cpu->esi + 8u;
    cpu->ebp += 0xFFFFFFFCu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E8E4u)); sfera_sub_004DD810(cpu, LIFT_CODE_TOKEN_VA(0x47E8E4u));
    cpu->esp += 0x10u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = -cpu->eax;
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0007E8F2:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFEu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->ebx = cpu->esi + 8u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47E91Eu)); sfera_sub_004DD8E0(cpu, LIFT_CODE_TOKEN_VA(0x47E91Eu));
    cpu->esp += 0x14u;
    if (cpu->eax == 0u) goto label_0007E92F;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0007E92F:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx));
    *(uint8_t*)(cpu->esi + 9u) = (uint64_t)(*(uint8_t*)(cpu->esi + 9u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 0x11u) = (uint64_t)(*(uint8_t*)(cpu->esi + 0x11u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 0x14u) = (uint64_t)(*(uint8_t*)(cpu->esi + 0x14u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0xEu));
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebp;
    *(uint8_t*)(cpu->esi + 4u) = (uint64_t)(*(uint8_t*)(cpu->esi + 4u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 5u) = (uint64_t)(*(uint8_t*)(cpu->esi + 5u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 6u) = (uint64_t)(*(uint8_t*)(cpu->esi + 6u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint8_t*)(cpu->esi + 7u) = (uint64_t)(*(uint8_t*)(cpu->esi + 7u)) ^ (uint64_t)((cpu->eax & 0xFFu));
    *(uint32_t*)(cpu->esi) = 0x52485053u;
    *(uint32_t*)(cpu->edi) = (uint64_t)(*(uint32_t*)(cpu->edi)) + (uint64_t)(8u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047E960(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)g_sfera_string_utility_runtime.format_buffer);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x47E96Fu));
    cpu->esp += 0xCu;
    cpu->ecx = (uintptr_t)g_sfera_string_utility_runtime.format_buffer;
    sfera_sub_00459B10(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0047EBA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"check_error: FALSE, File:%s, Line:%d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x47EBACu)); sfera_sub_0047E960(cpu, LIFT_CODE_TOKEN_VA(0x47EBACu));
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0047FEB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    g_sfera_network_probe_runtime.context_a = cpu->ecx;
    g_sfera_network_probe_runtime.context_c = cpu->edx;
    g_sfera_network_probe_runtime.context_b = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047FED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x8Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if ((cpu->edx & 0xFFu) != 0u) goto label_0007FEF6;
    cpu->eax = (uintptr_t)"at";
    label_0007FEF6:
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uintptr_t)"Net.log";
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x47FEFDu));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0007FF56;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x47FF12u));
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x47FF1Du));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m %H:%M:%S ");
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x47FF33u));
    cpu->edi = native_function_address32(&::fputs);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x47FF4Cu));
    cpu->esp += 0x2Cu;
    cpu->edi = lift_pop32(cpu);
    label_0007FF56:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x8Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0047FF70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x104u;
    cpu->eax = (uintptr_t)"Net.log";
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x47FF90u));
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebp != 0u) goto label_0007FFB5;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x104u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0007FFB5:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_network_probe_runtime.critical_section);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x47FFBCu));
    cpu->esi = (uintptr_t)&g_sfera_network_probe_runtime.samples[0];
    std::memmove((void*)((uintptr_t)&g_sfera_network_probe_runtime.snapshot[0]),(void*)(cpu->esi),480u); cpu->esi += 480u;
    cpu->ecx = g_sfera_network_probe_runtime.sample_count;
    lift_push32(cpu, (uintptr_t)&g_sfera_network_probe_runtime.critical_section);
    g_sfera_network_probe_runtime.snapshot_count = cpu->ecx;
    g_sfera_network_probe_runtime.sample_count = 0u;
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x47FFEEu));
    cpu->edi = g_sfera_network_probe_runtime.snapshot_count;
    if ((int32_t)(--cpu->edi) < 0) goto label_00080069;
    cpu->esi = cpu->edi + (cpu->edi * 2u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::fputs);
    cpu->esi = (cpu->esi * 8u) + ((uintptr_t)&g_sfera_network_probe_runtime.snapshot[0].context_a);
    label_00080010:
    cpu->edx = cpu->esi + 0xFFFFFFF4u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x480014u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m %H:%M:%S ");
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x48002Au));
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, (uintptr_t)"%d %d %d %d\n"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480051u));
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esp += 0x3Cu;
    cpu->esi -= 0x18u;
    if ((int32_t)(--cpu->edi) >= 0) goto label_00080010;
    cpu->ebx = lift_pop32(cpu);
    label_00080069:
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x48006Au));
    cpu->eax = g_sfera_network_probe_runtime.snapshot_count;
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x104u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480090(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    cpu->eax = cpu->ecx;
    cpu->edx = (uintptr_t)g_sfera_network_probe_runtime.host;
    g_sfera_network_probe_runtime.sample_count = cpu->ebx;
    cpu->edx -= cpu->eax;
    label_000800A3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000800A3;
    lift_push32(cpu, (uintptr_t)&g_sfera_network_probe_runtime.critical_section);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4800B2u));
    cpu->eax = cpu->esp + 4u;
    g_sfera_network_probe_runtime.stop_requested = (uint8_t)((cpu->ebx & 0xFFu));
    g_sfera_network_probe_runtime.context_a = cpu->ebx;
    g_sfera_network_probe_runtime.context_c = cpu->ebx;
    g_sfera_network_probe_runtime.context_b = cpu->ebx;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateThread(nullptr, 0u, &sfera_network_probe_thread, nullptr, 0u, reinterpret_cast<DWORD*>(static_cast<uintptr_t>(cpu->eax)))));
    sub_pred[0] = cpu->eax == cpu->ebx;
    g_sfera_network_probe_runtime.thread_handle = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00080102;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x4800EEu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"CreateThread error: %d\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4800FFu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4800FFu));
    cpu->esp += 8u;
    label_00080102:
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480110(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::GetExitCodeThread);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::Sleep);
    *(uint8_t*)(cpu->esp + 0xCu) = cpu->ecx & 0xFFu;
    g_sfera_network_probe_runtime.stop_requested = (uint8_t)(1u);
    cpu->esi = 0u;
    (void)cpu;
    label_00080130:
    cpu->eax = g_sfera_network_probe_runtime.thread_handle;
    if (cpu->eax == 0u) goto label_000801A3;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::GetExitCodeThread)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u)); cpu->esp += 0x8u;
    if (cpu->eax == 0u) goto label_00080161;
    if (*(uint32_t*)(cpu->esp + 0x10u) != 0x103u) goto label_00080161;

    reinterpret_cast<void (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::Sleep)))(7u);
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)0x28u) goto label_00080130;
    label_00080161:
    cpu->eax = g_sfera_network_probe_runtime.thread_handle;
    if (cpu->eax == 0u) goto label_000801A3;
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::GetExitCodeThread)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u)); cpu->esp += 0x8u;
    if (cpu->eax == 0u) goto label_000801A3;
    if (*(uint32_t*)(cpu->esp + 0x10u) != 0x103u) goto label_000801A3;
    cpu->eax = g_sfera_network_probe_runtime.thread_handle;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateThread), LIFT_CODE_TOKEN_VA(0x480190u));
    cpu->ecx = g_sfera_network_probe_runtime.thread_handle;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0x8019Du));
    label_000801A3:
    lift_push32(cpu, (uintptr_t)&g_sfera_network_probe_runtime.critical_section);
    lift_native_call(cpu, native_function_address32(&::DeleteCriticalSection), LIFT_CODE_TOKEN_VA(0x4801A8u));
    sub_pred[0] = *(uint8_t*)(cpu->esp + 0xCu) == 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000801CE;
    cpu->edx = (uintptr_t)"NetError.log";
    cpu->eax = (uintptr_t)"Net.log";
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4801C5u));
    cpu->esp += 8u;
    label_000801CE:
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004801E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_network_connection_checker.instance;
    if (cpu->eax != 0u) goto label_00080217;
    cpu->edx = cpu->eax + 0x1Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\NetworkConnectionChecker.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 4u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_00080210;
    *(uint32_t*)(cpu->eax) = 0u;
    g_sfera_network_connection_checker.instance = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00080210:
    cpu->eax = 0u;
    g_sfera_network_connection_checker.instance = cpu->eax;
    label_00080217:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_000802AE;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x48029Au));
    if (cpu->eax == 0u) goto label_000802AE;
    if (*(uint32_t*)(cpu->esp + 4u) == 0x103u) goto label_000802ED;
    label_000802AE:
    cpu->edx = cpu->esp + 8u;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateThread(nullptr, 0u, &sfera_directplay_heartbeat_thread, nullptr, 0u, reinterpret_cast<DWORD*>(static_cast<uintptr_t>(cpu->edx)))));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    if (cpu->eax != 0u) goto label_000802ED;
    cpu->ecx = (uintptr_t)"CClNetworkConnectionChecker::Start(): CreateThread error: ";
    g_sfera_log_runtime.files[0].write(reinterpret_cast<const char*>(cpu->ecx));
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x4802D6u));
    cpu->ecx = cpu->eax;
    g_sfera_log_runtime.files[0].write(static_cast<std::int32_t>(cpu->ecx));
    cpu->ecx = (uintptr_t)"\n";
    g_sfera_log_runtime.files[0].write(reinterpret_cast<const char*>(cpu->ecx));
    label_000802ED:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00480300(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->edx = 0x26u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\NetworkConnectionChecker.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = g_sfera_network_connection_checker.instance;
    cpu->esi = cpu->eax;
    if (cpu->eax == 0u) goto label_00080367;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008035E;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x480330u));
    if (cpu->eax == 0u) goto label_0008035E;
    if (*(uint32_t*)(cpu->esp + 4u) != 0x103u) goto label_0008035E;
    cpu->edx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::TerminateThread), LIFT_CODE_TOKEN_VA(0x480349u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x480352u));
    *(uint32_t*)(cpu->esi) = 0u;
    label_0008035E:
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00080367:
    g_sfera_network_connection_checker.instance = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
