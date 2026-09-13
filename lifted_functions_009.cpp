#include "lifted_functions.h"
#include <cmath>
namespace lifted {



__declspec(noinline) void sfera_sub_004595F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x90u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (g_sfera_view_motion_runtime.mode_value == cpu->edi) goto label_00059648;
    cpu->esi = native_function_address32(&::ShowCursor);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(cpu->edi);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(1u);
    if ((int32_t)cpu->eax >= 0) goto label_00059629;
    label_00059621:

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(1u);
    if ((int32_t)cpu->eax < 0) goto label_00059621;
    label_00059629:
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"Error"); lift_push32(cpu, (uintptr_t)"Reenter in epilog detected!"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x45963Bu));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x59642u));
    label_00059648:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    g_sfera_view_motion_runtime.mode_value = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45965Eu)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x45965Eu));
    if (static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_render_runtime.world_spatial_index)) == cpu->edi) goto label_00059695;
    cpu->edx = 0x44Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_render_runtime.world_spatial_index));
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_0005968F;
    std::destroy_at(reinterpret_cast<SphereWorld::DynamicVegetation*>(cpu->ecx));
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0005968F:
    g_sfera_world_render_runtime.world_spatial_index = reinterpret_cast<decltype(g_sfera_world_render_runtime.world_spatial_index)>(cpu->edi);
    label_00059695:
    if (*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_01 == 0u) goto label_000596AB;
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->halt_all_requested = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x596ABu)); sfera_sub_004496F0(cpu, LIFT_CODE_TOKEN_RVA(0x596ABu));
    label_000596AB:
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4596B5u)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x4596B5u));
    g_sfera_sound_runtime.shutdown();
    if (g_sfera_input_device_runtime.shared_object == cpu->edi) goto label_000596F1;
    cpu->edx = 0x457u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = g_sfera_input_device_runtime.shared_object;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_000596EB;
    std::destroy_at(reinterpret_cast<SphereUI::ChatFilter*>(cpu->ecx));
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_000596EB:
    g_sfera_input_device_runtime.shared_object = cpu->edi;
    label_000596F1:
    if (static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_client_process_runtime.client_object)) == cpu->edi) goto label_00059728;
    cpu->edx = 0x458u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_client_process_runtime.client_object));
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_00059722;
    delete reinterpret_cast<Contours*>(cpu->ecx);
    label_00059722:
    g_sfera_client_process_runtime.client_object = reinterpret_cast<decltype(g_sfera_client_process_runtime.client_object)>(cpu->edi);
    label_00059728:
    if (static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_primary_sky_environment)) == cpu->edi) goto label_00059757;
    cpu->edx = 0x459u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_primary_sky_environment));
    if (cpu->eax == cpu->edi) goto label_00059751;
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00059751:
    g_sfera_primary_sky_environment = reinterpret_cast<decltype(g_sfera_primary_sky_environment)>(cpu->edi);
    label_00059757:
    if (static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_main_aux_runtime.secondary_world_manager)) == cpu->edi) goto label_00059786;
    cpu->edx = 0x45Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_main_aux_runtime.secondary_world_manager));
    if (cpu->eax == cpu->edi) goto label_00059780;
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00059780:
    g_sfera_main_aux_runtime.secondary_world_manager = reinterpret_cast<decltype(g_sfera_main_aux_runtime.secondary_world_manager)>(cpu->edi);
    label_00059786:
    if (auto* zones = g_sfera_window_runtime.path_zones) { zones->~PathZones(); WorldMemory::release(zones); g_sfera_window_runtime.path_zones = nullptr; }
    label_000597BD:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_mode;
    if (cpu->eax == cpu->edi) goto label_000597CD;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_RVA(0x597C7u));
    label_000597CD:
    g_sfera_effect_manager.shutdown();
    cpu->eax = static_cast<std::uint32_t>(g_sfera_interface.shutdown());
    ShadowMap::shutdown();
    g_sfera_world_objects.destroyAll();
    g_sfera_player_lists.resetItem();
    g_sfera_models.clear();
    label_00059818:
    if (static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_recovered_static_runtime.render_state_08)) == cpu->edi) goto label_0005984F;
    cpu->edx = 0x46Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_recovered_static_runtime.render_state_08));
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_00059849;
    reinterpret_cast<SphereRender::CharacterModels*>(cpu->ecx)->clear();
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00059849:
    g_sfera_recovered_static_runtime.render_state_08 = reinterpret_cast<decltype(g_sfera_recovered_static_runtime.render_state_08)>(cpu->edi);
    label_0005984F:
    g_sfera_direct_input_runtime.release();
    g_sfera_font_runtime.clear();
    if (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_state == cpu->edi) goto label_00059888;
    cpu->edx = 0x473u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_state;
    if (cpu->ecx == cpu->edi) goto label_00059882;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x59880u));
    label_00059882:
    (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_state) = cpu->edi;
    label_00059888:
    TerrainTextureCache::release();
    cpu->eax = g_sfera_window_runtime.main_window;
    if (cpu->eax == cpu->edi) goto label_000598A3;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DestroyWindow), LIFT_CODE_TOKEN_VA(0x459897u));
    g_sfera_window_runtime.main_window = cpu->edi;
    label_000598A3:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, reinterpret_cast<std::uintptr_t>(GameInterface::nativeWindowClassName));
    lift_native_call(cpu, native_function_address32(&::UnregisterClassA), LIFT_CODE_TOKEN_VA(0x4598AFu));
    lift_native_call(cpu, native_function_address32(&::CoUninitialize), LIFT_CODE_TOKEN_VA(0x4598B5u));
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_mode <= (int32_t)cpu->edi) goto label_00059A6F;
    cpu->ebx = native_function_address32(&::fflush);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::fputs);
    cpu->esi = (uintptr_t)&g_sfera_log_runtime.files[0].has_written;
    (void)cpu;
    label_000598E0:
    if (*(uint32_t*)(cpu->esi + 0xFFFFFFFCu) != cpu->edi) goto label_00059A56;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_log_runtime.files[cpu->ecx].open()));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_0005990F;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"**** Quit: ");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x459900u));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->esi) = 1u;
    label_0005990F:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x459914u));
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x45991Fu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%A, %d %B %Y");
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x459935u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp += 0x18u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_log_runtime.files[cpu->ecx].open()));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_00059968;
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x459959u));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->esi) = 1u;
    label_00059968:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_log_runtime.files[cpu->ecx].open()));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_00059992;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"  ");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x459983u));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->esi) = 1u;
    label_00059992:
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x459997u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_log_runtime.files[cpu->ecx].open()));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_000599CA;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4599BBu));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->esi) = 1u;
    label_000599CA:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_log_runtime.files[cpu->ecx].open()));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_000599F4;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"\n\n");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4599E5u));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->esi) = 1u;
    label_000599F4:
    cpu->eax = 0u;
    if (*(uint8_t*)(cpu->esi + 0xFFFFFFC8u) == 0x2Eu) goto label_00059A10;
    label_00059A00:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + cpu->eax + 0xFFFFFFC8u));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x1Cu) = cpu->edx & 0xFFu;
    ++cpu->eax;
    if (*(uint8_t*)(cpu->esi + cpu->eax + 0xFFFFFFC8u) != 0x2Eu) goto label_00059A00;
    label_00059A10:
    *(uint8_t*)(cpu->esp + cpu->eax + 0x1Cu) = 0u;
    cpu->eax = cpu->esp + 0x1Cu;
    --cpu->eax;
    label_00059A20:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00059A20;
    cpu->ecx = *(uint32_t*)((uintptr_t)".log");
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)".log") + 4u));
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(reinterpret_cast<const char*>(cpu->ecx)));
    if ((int32_t)cpu->eax <= (int32_t)cpu->edi) goto label_00059A54;
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59A54u)); sfera_sub_0044C020(cpu, LIFT_CODE_TOKEN_RVA(0x59A54u));
    label_00059A54:
    cpu->edi = 0u;
    label_00059A56:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    cpu->esi += 0x40u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_mode) goto label_000598E0;
    cpu->ebp = lift_pop32(cpu);
    label_00059A6F:
    sub_pred[0] = (uint8_t)g_sfera_process_runtime.executable_path[0] == 0u;
    cpu->ebx = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00059A92;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_relaunch_runtime.argument[0]); lift_push32(cpu, (uintptr_t)&g_sfera_process_runtime.executable_path[0]); lift_push32(cpu, (uintptr_t)&g_sfera_process_runtime.executable_path[0]);
    lift_native_call(cpu, native_function_address32(&::_execl), LIFT_CODE_TOKEN_VA(0x459A89u));
    cpu->esp += 0x10u;
    label_00059A92:
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459A9Cu)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x459A9Cu));
    ::DeleteCriticalSection(&g_sfera_network_send_runtime.critical_section);

    ::DeleteCriticalSection(&g_sfera_window_runtime.timing_critical_section);

    ::DeleteCriticalSection(&g_sfera_recovered_static_runtime.scene_lock);
    if (*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled != 1u) goto label_00059AF1;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24 == cpu->edi) goto label_00059AF1;
    cpu->edx = 0x4B4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_00059AF1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459AE8u)); sfera_sub_00418D50(cpu, LIFT_CODE_TOKEN_VA(0x459AE8u));
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00059AF1:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x90u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00459B10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    (void)stop_address;
    sub_pred[0] = (uint32_t)((uint64_t)(g_sfera_view_motion_runtime.initialized)) == 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (sub_pred[0]) goto label_00059B58;
    cpu->esi = native_function_address32(&::ShowCursor);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(0u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(1u);
    if ((int32_t)cpu->eax >= 0) goto label_00059B38;
    label_00059B30:

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(1u);
    if ((int32_t)cpu->eax < 0) goto label_00059B30;
    label_00059B38:
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"Error"); lift_push32(cpu, (uintptr_t)"Reenter in exit_msg detected!"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x459B4Au));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x59B52u));
    label_00059B58:
    cpu->ecx = g_sfera_recovered_static_runtime.server_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ServerN=%d  "); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0]);
    g_sfera_view_motion_runtime.initialized = 1u;
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x459B73u));
    cpu->eax = cpu->esi;
    cpu->esp += 0xCu;
    cpu->ecx = cpu->eax;
    label_00059B80:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00059B80;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0];
    cpu->eax -= cpu->ecx;
    --cpu->edi;
    label_00059B92:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00059B92;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459BB2u)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x459BB2u));
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldDiagnostics::scriptContext()));
    if (cpu->eax == 0u) goto label_00059BFC;
    cpu->edi = (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0];
    --cpu->edi;
    label_00059BC1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00059BC1;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    *(uint16_t*)(cpu->edi) = cpu->edx & 0xFFFFu;
    cpu->ecx = cpu->eax;
    label_00059BD5:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00059BD5;
    cpu->edi = (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00059BE6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00059BE6;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax);
    label_00059BFC:
    cpu->ecx = 0u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_log_runtime.files[cpu->ecx].open()));
    cpu->edi = native_function_address32(&::fputs);
    cpu->ebx = native_function_address32(&::fflush);
    cpu->ebp = native_function_address32(&::fclose);
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00059C36;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0]);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_00059C36:
    cpu->ecx = 0u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_log_runtime.files[cpu->ecx].open()));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00059C5E;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_00059C5E:
    cpu->esi = native_function_address32(&::ShowCursor);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(0u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(1u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((int32_t)cpu->eax >= 0) goto label_00059C7B;
    label_00059C73:

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(1u);
    if ((int32_t)cpu->eax < 0) goto label_00059C73;
    label_00059C7B:
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"\316\370\350\341\352\340"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0]); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x459C8Du));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459C98u)); sfera_sub_004595F0(cpu, LIFT_CODE_TOKEN_VA(0x459C98u));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_VA(0x459C9Au));
    cpu->eip = 0x459CA0u; ::DebugBreak(); return;
}


__declspec(noinline) void sfera_sub_0045AFB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45AFBCu)); sfera_sub_00449180(cpu, LIFT_CODE_TOKEN_VA(0x45AFBCu));
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_01) = 1u;
    cpu->edi = 0u;
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    cpu->ebx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    g_sfera_client_process_runtime.shutdown_requested = cpu->edi;
    label_0005AFD6:
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    cpu->ecx = cpu->eax;
    cpu->ecx -= cpu->ebx;
    cpu->edi += cpu->ecx;
    if ((cpu->edi == 0x2710u) || ((int32_t)(cpu->edi) < (int32_t)(0x2710u))) goto label_0005AFEE;
    cpu->edi = 0x2710u;
    label_0005AFEE:
    cpu->ebx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->ecx = cpu->edi + 0x1Au;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x4EC4EC4Fu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    cpu->edx = cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xFFFFFFCCu);
    cpu->edi += cpu->edx;
    cpu->ebp = 0u;
    if ((int32_t)cpu->esi <= 0) goto label_0005B02A;
    label_0005B015:
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B01Cu)); sfera_sub_004496F0(cpu, LIFT_CODE_TOKEN_VA(0x45B01Cu));
    if (g_sfera_client_process_runtime.shutdown_requested != 0u) goto label_0005B054;
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)cpu->esi) goto label_0005B015;
    label_0005B02A:
    g_sfera_win32_dialogs.pumpMessages();
    if ((uint32_t)(g_sfera_render_lookup_runtime.initialized) == 1u) goto label_0005B042;
    lift_push32(cpu, 0xAu);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x45B03Au));
    goto label_0005AFD6;
    label_0005B042:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B047u)); sfera_sub_004595F0(cpu, LIFT_CODE_TOKEN_VA(0x45B047u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B04Cu)); sfera_sub_0042EB70(cpu, LIFT_CODE_TOKEN_VA(0x45B04Cu));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_RVA(0x5B04Eu));
    label_0005B054:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0045BC60(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = 0u;
    g_sfera_window_runtime.runtime_debug_enabled = 1u;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.debug_config_enabled == cpu->esi) goto label_0005BCCE;
    cpu->ecx = (uintptr_t)"debug.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCA1u)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x45BCA1u));
    cpu->edx = (uintptr_t)&g_sfera_window_runtime.runtime_debug_enabled;
    cpu->ecx = (uintptr_t)"RUNTIME";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCB0u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x45BCB0u));
    cpu->edx = (uintptr_t)&g_sfera_main_command_state_runtime.escape_without_query;
    cpu->ecx = (uintptr_t)"ESCNOQUERY";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCBFu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x45BCBFu));
    cpu->edx = (uintptr_t)&g_sfera_world_load_runtime.render_shadows;
    cpu->ecx = (uintptr_t)"RENDERSHADOW";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5BCCEu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_RVA(0x5BCCEu));
    label_0005BCCE:
    g_sfera_world_objects.destroyAll();
    g_sfera_sound_runtime.initialize();
    cpu->ecx = 1u;
    ShadowMap::initialize(cpu->ecx); cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_shadows.get()));
    WorldGuiControls::destroyAllText();
    WorldDebugDraw::clear();
    x87_v0 = 0.0;
    cpu->eax = *(uint32_t*)((uintptr_t)"cursor1");
    g_sfera_main_view_state_runtime.view_coefficients[5] = x87_v0;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"cursor1") + 4u);
    g_sfera_main_view_state_runtime.view_coefficients[4] = x87_v0;
    g_sfera_main_view_state_runtime.view_coefficients[3] = x87_v0;
    cpu->edi |= 0xFFFFFFFFu;
    g_sfera_main_view_state_runtime.view_coefficients[2] = x87_v0;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.default_cursor_token[0]) = cpu->eax;
    g_sfera_main_view_state_runtime.view_coefficients[1] = x87_v0;
    g_sfera_world_objects.controlled_object_handle = cpu->edi;
    g_sfera_main_view_state_runtime.view_coefficients[0] = x87_v0;
    g_sfera_recovered_static_runtime.interaction_enabled = cpu->esi;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.z.f32) = x87_v0;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.render_channel_mask) = 0xFFu;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.y.f32) = x87_v0;
    g_sfera_main_command_state_runtime.default_cursor_token[1] = cpu->ecx;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.x.f32) = x87_v0;
    g_sfera_window_runtime.active_window_index = cpu->edi;
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.render_scale.x.f32) = x87_v0;
    g_sfera_texture_cache_runtime.render_gate = cpu->esi;
    x87_v1 = 1.0;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_02) = cpu->esi;
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.render_scale.y.f32) = x87_v1; 
    cpu->eax = (uintptr_t)&g_sfera_texture_cache_runtime.entries[0].use_count;
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.render_scale.z.f32) = x87_v0; 
    g_sfera_graphics_runtime.base_render_factor = (double)0.05999999865889549f;
    label_0005BD96:
    *(uint32_t*)(cpu->eax + 0xFFFFFFF4u) = cpu->esi;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->eax += 0x10u;
    if ((int32_t)(cpu->eax) < (int32_t)((uint32_t)((uintptr_t)&g_sfera_texture_cache_runtime.entries[kTextureCacheEntryCount] + offsetof(SferaTextureCacheEntry, use_count)))) goto label_0005BD96;
    cpu->edx = 0x15C2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(new EnvironmentZones));
    label_0005BDD5:
    lift_push32(cpu, (uintptr_t)"Landscape\\zoning.cfg");
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    g_sfera_recovered_static_runtime.scene_state_08 = reinterpret_cast<decltype(g_sfera_recovered_static_runtime.scene_state_08)>(cpu->eax);
    reinterpret_cast<EnvironmentZones*>(cpu->ecx)->load(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));  cpu->esp += 4u;
    cpu->edx = 0x15C4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(new EnvironmentZones));
    label_0005BE1E:
    lift_push32(cpu, (uintptr_t)"Landscape\\zoningHaron.cfg");
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    g_sfera_alternate_environment_zones = reinterpret_cast<decltype(g_sfera_alternate_environment_zones)>(cpu->eax);
    reinterpret_cast<EnvironmentZones*>(cpu->ecx)->load(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));  cpu->esp += 4u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}





__declspec(noinline) void sfera_sub_004623C0(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->esp -= 0x404u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x408u);
    cpu->eax = cpu->esp + 0x40Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x4623E9u));
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4623FAu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4623FAu));
    cpu->eip = 0x4623FAu; ::DebugBreak(); return;
}


} // namespace lifted
