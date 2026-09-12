#include "lifted_functions.h"
#include <cmath>
namespace lifted {

static uint32_t sfera_window_class_name() { return (uintptr_t)"SphereWclName"; }

__declspec(noinline) void sfera_sub_00458E80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->ebp < 0) goto label_0005904B;
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00058EA2;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58EA2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58EA2u));
    label_00058EA2:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->eax + (cpu->ebp * 4u)) == 0u) goto label_0005904B;
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00058EC5;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58EC5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58EC5u));
    label_00058EC5:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->edi = *(uint32_t*)(cpu->ecx + (cpu->ebp * 4u));
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->edi += 0x44u;
    cpu->ebx = 0x1B58u;
    label_00058EE0:
    cpu->esi = *(uint32_t*)(cpu->edi);
    if (cpu->esi == 0xFFFFFFFFu) goto label_00058F1E;
    if ((int32_t)cpu->esi >= 0) goto label_00058EF5;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58EF5u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x58EF5u));
    label_00058EF5:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_00058F09;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58F09u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58F09u));
    label_00058F09:
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (*(uint32_t*)(cpu->eax) != 0u) goto label_00058F1E;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    WorldGuiControls::destroyText(cpu->ecx);
    label_00058F1E:
    cpu->edi += 4u;
    if ((--cpu->ebx) != 0u) goto label_00058EE0;
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ebx = lift_pop32(cpu);
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count <= (int32_t)cpu->esi) goto label_00058FE1;
    label_00058F35:
    if ((int32_t)cpu->esi >= 0) goto label_00058F43;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58F43u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x58F43u));
    label_00058F43:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00058F57;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58F57u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58F57u));
    label_00058F57:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) != 0u) goto label_00058F66;
    ++cpu->esi;
    goto label_00058F35;
    label_00058F66:
    if ((int32_t)cpu->esi >= 0) goto label_00058F74;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58F74u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x58F74u));
    label_00058F74:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00058F88;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58F88u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58F88u));
    label_00058F88:
    cpu->edx = g_sfera_interface_runtime.windows.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6DA4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    if ((int32_t)cpu->ecx <= (int32_t)*(uint32_t*)(cpu->edx + 0x6DA4u)) goto label_00058FD3;
    if ((int32_t)cpu->esi >= 0) goto label_00058FB1;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58FB1u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x58FB1u));
    label_00058FB1:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00058FC5;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58FC5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58FC5u));
    label_00058FC5:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    --*(uint32_t*)(cpu->eax + 0x6DA4u);
    label_00058FD3:
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count) goto label_00058F35;
    label_00058FE1:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00058FF5;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58FF5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58FF5u));
    label_00058FF5:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->ebp * 4u));
    lift_push32(cpu, 0x2E59u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45900Du)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45900Du));
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00059021;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59021u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x59021u));
    label_00059021:
    cpu->edx = g_sfera_interface_runtime.windows.data;
    *(uint32_t*)(cpu->edx + (cpu->ebp * 4u)) = 0u;
    g_sfera_main_command_state_runtime.window_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count)) - 1u;
    if (g_sfera_window_runtime.active_window_index != cpu->ebp) goto label_00059046;
    g_sfera_window_runtime.active_window_index = 0xFFFFFFFFu;
    label_00059046:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005904B:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00059058:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00059058;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"delete_window: wrong handle"),28u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 4u;
    WorldDiagnostics::flushScriptContext();  cpu->esp += 4u; cpu->eip = stop_address; return;
}





__declspec(noinline) void sfera_sub_00459530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_world_render_runtime.render_queue_count;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebx = cpu->ecx;
    if (cpu->eax != 0u) goto label_00059544;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00059544:
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_world_render_queue_runtime.entries[0]));
    if ((int32_t)cpu->esi >= 0) goto label_0005955A;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5955Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5955Au));
    label_0005955A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005956E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5956Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5956Eu));
    label_0005956E:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->edx = cpu->ebx;
    cpu->edx -= cpu->eax;
    label_00059590:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00059590;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->edi) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edi + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = g_sfera_world_render_runtime.render_queue_count;
    cpu->ecx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_world_render_queue_runtime.entries[0]));
    g_sfera_world_objects.destroy(cpu->ecx);
    --g_sfera_world_render_runtime.render_queue_count;
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
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
    if (g_sfera_world_render_runtime.world_spatial_index == cpu->edi) goto label_00059695;
    cpu->edx = 0x44Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459675u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x459675u));
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_0005968F;
    std::destroy_at(SferaAbi::pointer<SphereWorld::DynamicVegetation>(cpu->ecx));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45968Cu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x45968Cu));
    cpu->esp += 4u;
    label_0005968F:
    g_sfera_world_render_runtime.world_spatial_index = cpu->edi;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4596D1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4596D1u));
    cpu->ecx = g_sfera_input_device_runtime.shared_object;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_000596EB;
    std::destroy_at(SferaAbi::pointer<SphereUI::ChatFilter>(cpu->ecx));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4596E8u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4596E8u));
    cpu->esp += 4u;
    label_000596EB:
    g_sfera_input_device_runtime.shared_object = cpu->edi;
    label_000596F1:
    if (g_sfera_client_process_runtime.client_object == cpu->edi) goto label_00059728;
    cpu->edx = 0x458u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459708u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x459708u));
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_00059722;
    delete SferaAbi::pointer<Contours>(cpu->ecx);
    label_00059722:
    g_sfera_client_process_runtime.client_object = cpu->edi;
    label_00059728:
    if (g_sfera_font_runtime.renderer == cpu->edi) goto label_00059757;
    cpu->edx = 0x459u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45973Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45973Fu));
    cpu->eax = g_sfera_font_runtime.renderer;
    if (cpu->eax == cpu->edi) goto label_00059751;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45974Eu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x45974Eu));
    cpu->esp += 4u;
    label_00059751:
    g_sfera_font_runtime.renderer = cpu->edi;
    label_00059757:
    if (g_sfera_main_aux_runtime.secondary_world_manager == cpu->edi) goto label_00059786;
    cpu->edx = 0x45Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45976Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45976Eu));
    cpu->eax = g_sfera_main_aux_runtime.secondary_world_manager;
    if (cpu->eax == cpu->edi) goto label_00059780;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45977Du)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x45977Du));
    cpu->esp += 4u;
    label_00059780:
    g_sfera_main_aux_runtime.secondary_world_manager = cpu->edi;
    label_00059786:
    if (g_sfera_window_runtime.input_runtime_object == cpu->edi) goto label_000597BD;
    cpu->edx = 0x45Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45979Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45979Du));
    cpu->ecx = g_sfera_window_runtime.input_runtime_object;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_000597B7;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4597AEu)); sfera_sub_00489810(cpu, LIFT_CODE_TOKEN_VA(0x4597AEu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4597B4u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4597B4u));
    cpu->esp += 4u;
    label_000597B7:
    g_sfera_window_runtime.input_runtime_object = cpu->edi;
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
    g_sfera_models.clear();
    label_00059818:
    if (g_sfera_recovered_static_runtime.render_state_08 == cpu->edi) goto label_0005984F;
    cpu->edx = 0x46Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45982Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45982Fu));
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_00059849;
    SferaAbi::pointer<SphereRender::CharacterModels>(cpu->ecx)->clear();
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459846u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x459846u));
    cpu->esp += 4u;
    label_00059849:
    g_sfera_recovered_static_runtime.render_state_08 = cpu->edi;
    label_0005984F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459854u)); sfera_sub_0044CB70(cpu, LIFT_CODE_TOKEN_VA(0x459854u));
    GameInterface::releaseFontAtlas();
    if (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_state == cpu->edi) goto label_00059888;
    cpu->edx = 0x473u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459870u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x459870u));
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
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, sfera_window_class_name());
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
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
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
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
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
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
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
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
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
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459AD7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x459AD7u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_00059AF1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459AE8u)); sfera_sub_00418D50(cpu, LIFT_CODE_TOKEN_VA(0x459AE8u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459AEEu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x459AEEu));
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
    cpu->eax = SferaAbi::address(WorldDiagnostics::scriptContext());
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
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
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
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
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
__declspec(noinline) void sfera_sub_00459CB0(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax = cpu->edx;
    cpu->esi -= cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    label_00059CC0:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->ebx & 0xFFu;
    ++cpu->ecx;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_00059CC0;
    cpu->ebx = lift_pop32(cpu);
    label_00059CD0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00059CD0;
    cpu->edi = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax -= cpu->edx;
    --cpu->edi;
    (void)cpu;
    label_00059CE0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00059CE0;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459D02u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x459D02u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eip = 0x459D04u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00459D10(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax = cpu->edx;
    cpu->esi -= cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    label_00059D20:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->ebx & 0xFFu;
    ++cpu->ecx;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_00059D20;
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    label_00059D30:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00059D30;
    cpu->edi = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00059D41:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00059D41;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    --cpu->eax;
    label_00059D60:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00059D60;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x202C)) & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint16_t*)(cpu->eax) = cpu->ecx & 0xFFFFu;
    *(uint8_t*)(cpu->eax + 2u) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = cpu->eax;
    label_00059D81:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00059D81;
    cpu->edi = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00059D92:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00059D92;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459DB2u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x459DB2u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eip = 0x459DB4u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00459E40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::GetSystemMetrics);
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::GetSystemMetrics)))(0u);
    lift_push32(cpu, 1u);
    g_sfera_scene_control_runtime.timing_anchor = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::GetSystemMetrics)))(*(uint32_t*)(cpu->esp)); cpu->esp += 0x4u;
    cpu->esi = g_sfera_graphics_runtime.display_width;
    g_sfera_recovered_static_runtime.scene_state_07 = cpu->eax;
    if ((int32_t)cpu->esi >= (int32_t)0x320u) goto label_00059E83;
    cpu->esi = 0x320u;
    g_sfera_graphics_runtime.display_width = cpu->esi;
    label_00059E83:
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    if ((int32_t)cpu->ecx >= (int32_t)0x258u) goto label_00059E9C;
    cpu->ecx = 0x258u;
    g_sfera_graphics_runtime.display_height = cpu->ecx;
    label_00059E9C:
    cpu->ebx = 0u;
    cpu->edi = 0u;
    if (g_sfera_window_runtime.windowed == cpu->ebx) goto label_00059EF3;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ebp = 0xCA0000u;
    lift_native_call(cpu, native_function_address32(&::SetRect), LIFT_CODE_TOKEN_VA(0x459EB6u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::AdjustWindowRect), LIFT_CODE_TOKEN_VA(0x459EC3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi -= *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_recovered_static_runtime.scene_state_07) goto label_00059F33;
    cpu->esi = g_sfera_graphics_runtime.display_width;
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    g_sfera_window_runtime.windowed = cpu->ebx;
    label_00059EF3:
    cpu->ebp = 0x80000000u;
    label_00059EF8:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Sphere"); lift_push32(cpu, sfera_window_class_name()); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateWindowExA), LIFT_CODE_TOKEN_VA(0x459F16u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    g_sfera_window_runtime.main_window = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    if (cpu->eax != 0u) goto label_00059F51;
    cpu->ecx = (uintptr_t)"CreateWindowEx() failed! => init_main_window()";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59F33u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x59F33u));
    label_00059F33:
    cpu->eax = g_sfera_scene_control_runtime.timing_anchor;
    cpu->eax -= cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_recovered_static_runtime.scene_state_07;
    cpu->eax -= cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->ebx = cpu->eax;
    cpu->edi = (int32_t)(cpu->edi) >> 1u;
    cpu->ebx = (int32_t)(cpu->ebx) >> 1u;
    goto label_00059EF8;
    label_00059F51:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::ShowWindow), LIFT_CODE_TOKEN_VA(0x459F54u));
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::InvalidateRect), LIFT_CODE_TOKEN_VA(0x459F64u));
    cpu->ecx = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::UpdateWindow), LIFT_CODE_TOKEN_VA(0x459F71u));
    cpu->edx = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::BringWindowToTop), LIFT_CODE_TOKEN_VA(0x459F7Eu));
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00459FA0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17, value_18, value_19, value_20, value_21, value_22, value_23, value_24, value_25, value_26, value_27, value_28, value_29, value_30, value_31, value_32, value_33, value_34, value_35, value_36;
 bool sub_pred[3]; double x87_p0;
    cpu->esp -= 0xB4u;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->edi = cpu->edx;
    if (cpu->eax == 0u) goto label_00059FE9;
    if (cpu->eax == 1u) goto label_00059FE9;
    lift_push32(cpu, (uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    cpu->eax = cpu->esp + 0x84u;
    lift_push32(cpu, (uintptr_t)"fonts\\font%s.txt"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x459FDEu));
    cpu->esp += 0xCu;
    goto label_00059FFF;
label_00059FE9:
    cpu->ecx = cpu->esp + 0x80u;
    lift_push32(cpu, (uintptr_t)"fonts\\font.txt"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x459FF6u));
    cpu->esp += 8u;
label_00059FFF:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 0x20020u); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_font_atlas_staging_runtime);
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0])) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x45A01Du));
    cpu->esp += 0xCu;
    cpu->eax = 0x100u;
    lift_push32(cpu, 0x7F9u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x400u;
    g_sfera_font_atlas_staging_runtime.magic = 0x6D786554u;
    g_sfera_font_atlas_staging_runtime.width = cpu->eax;
    g_sfera_font_atlas_staging_runtime.height = cpu->eax;
    g_sfera_font_atlas_staging_runtime.mip_count = UINT32_C(1);
    g_sfera_font_atlas_staging_runtime.encoding = 0x115Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A066u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45A066u));
    lift_push32(cpu, 0x7FAu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x400u;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A07Eu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45A07Eu));
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x7FDu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A09Cu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45A09Cu));
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    cpu->ebx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.open(SferaAbi::pointer<const char>(cpu->ecx), static_cast<std::int32_t>(cpu->edx)));
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.read(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.close(static_cast<std::int32_t>(cpu->ecx)));
    cpu->edi = *(uint16_t*)(cpu->ebx + 0xAu);
    cpu->edx = *(uint16_t*)(cpu->ebx + 6u);
    cpu->ecx = cpu->ebx + cpu->esi + 0xFFFFFD00u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->edi -= cpu->edx;
    cpu->ecx = cpu->esp + 0x80u;
    ++cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x805u);
    cpu->ecx = cpu->esi + 1u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A0F0u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45A0F0u));
    cpu->ebp = cpu->eax;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x80u;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->ebp;
    *(uint8_t*)(cpu->esi + cpu->ebp) = 0u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.open(SferaAbi::pointer<const char>(cpu->ecx), static_cast<std::int32_t>(cpu->edx)));
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.read(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.close(static_cast<std::int32_t>(cpu->ecx)));
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    if ((int32_t)cpu->esi <= (int32_t)cpu->eax) goto label_0005A140;
    cpu->ecx = cpu->eax;
label_0005A130:
    if (*(uint8_t*)(cpu->eax + cpu->ebp) != 0x23u) goto label_0005A137;
    ++cpu->ecx;
label_0005A137:
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->esi) goto label_0005A130;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ecx;
label_0005A140:
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x118u);
    lift_push32(cpu, 0x810u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A15Bu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45A15Bu));
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    cpu->eax = cpu->ebx + 0x80u;
    goto label_0005A174;
label_0005A170:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
label_0005A174:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    if ((cpu->edx & 0xFFu) <= 0xC0u) goto label_0005A18E;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0x3Fu))) & 0xFFu);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
label_0005A18E:
    cpu->eax = cpu->ecx & 0xFFu;
    cpu->edi -= cpu->eax;
label_0005A193:
    *(uint8_t*)(cpu->esi) = cpu->edx & 0xFFu;
    ++cpu->esi;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->ecx - 1u) & 0xFFu);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0005A193;
    if (cpu->edi != 0u) goto label_0005A170;
    cpu->edx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x10u) <= (int32_t)cpu->edx) goto label_0005A1DA;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x38u);
label_0005A1B0:
    cpu->ecx = *(uint8_t*)(cpu->esi + cpu->edx);
    cpu->eax = cpu->edi + (cpu->ecx * 2u);
    cpu->ecx += cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (0xF0u & 0xFFu);
    if (*(uint8_t*)(cpu->ecx) <= (cpu->eax & 0xFFu)) goto label_0005A1CF;
    if (*(uint8_t*)(cpu->ecx + 1u) <= (cpu->eax & 0xFFu)) goto label_0005A1CF;
    if (*(uint8_t*)(cpu->ecx + 2u) <= (cpu->eax & 0xFFu)) goto label_0005A1CF;
    *(uint8_t*)(cpu->esi + cpu->edx) = 1u;
    goto label_0005A1D3;
label_0005A1CF:
    *(uint8_t*)(cpu->esi + cpu->edx) = 0u;
label_0005A1D3:
    ++cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->esp + 0x10u)) goto label_0005A1B0;
label_0005A1DA:
    lift_push32(cpu, 0x82Cu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A1EBu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45A1EBu));
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->eax = 0u;
    cpu->edx = 0x1Au;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x4Cu) <= (int32_t)cpu->esi) goto label_0005A829;
    x87_p0 = 0.00390625;
    cpu->ecx = cpu->ebp;
     value_35 = x87_p0; value_0 = value_35; goto label_0005A229;
label_0005A225:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u); value_0 = value_34;
label_0005A229:
    if (*(uint8_t*)(cpu->ecx) == 0x23u) { value_2 = value_0; goto label_0005A235; } value_1 = value_0;
label_0005A22E:
    ++cpu->eax;
    if (*(uint8_t*)(cpu->eax + cpu->ebp) != 0x23u) goto label_0005A22E; value_2 = value_1;
label_0005A235:
    cpu->ecx = cpu->eax + 0xFFFFFFFFu;
    if (*(uint8_t*)(cpu->eax + cpu->ebp + 0xFFFFFFFFu) != 0x20u) { value_4 = value_2; goto label_0005A24C; } value_3 = value_2;
label_0005A23F:
    if ((--cpu->ecx) == 0u) goto label_0005A8B2;
    if (*(uint8_t*)(cpu->ecx + cpu->ebp) == 0x20u) goto label_0005A23F; value_4 = value_3;
label_0005A24C:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + cpu->ebp));
    if ((cpu->edx & 0xFFu) < 0x30u) goto label_0005A8B2;
    if ((cpu->edx & 0xFFu) > 0x39u) goto label_0005A8B2;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + cpu->ebp + 0xFFFFFFFFu));
    if ((cpu->ecx & 0xFFu) < 0x41u) goto label_0005A8B2;
    if ((cpu->ecx & 0xFFu) > 0x5Au) goto label_0005A8B2;
    cpu->edi = cpu->edx & 0xFFu;
    cpu->ebx = cpu->ecx & 0xFFu;
    ++cpu->eax;
    cpu->edi -= 0x30u;
    cpu->ebx -= 0x41u;
    sub_pred[0] = *(uint8_t*)(cpu->eax + cpu->ebp) == 0x20u;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    if (!sub_pred[0]) { value_6 = value_4; goto label_0005A2A4; } value_5 = value_4;
label_0005A28E:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->ebp + 1u));
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0005A8B2;
    if ((cpu->ecx & 0xFFu) == 0x20u) goto label_0005A28E; value_6 = value_5;
label_0005A2A4:
    sub_pred[1] = *(uint8_t*)(cpu->eax + cpu->ebp) == 0x27u;
    cpu->ecx = cpu->eax + cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ecx;
    if (!sub_pred[1]) goto label_0005A8B2;
    cpu->ecx = *(uint8_t*)(cpu->eax + cpu->ebp + 1u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx <<= 5u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    cpu->esi <<= 5u;
    cpu->ecx <<= 8u;
    cpu->ecx += cpu->esi;
    cpu->edx -= cpu->eax;
    cpu->ecx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->ecx;
    cpu->ecx = cpu->ecx + ((uintptr_t)&g_sfera_font_atlas_staging_runtime.pixels[0]);
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = 0x20u; value_7 = value_6;
label_0005A2F7:
    cpu->esi = 0x20u; value_8 = value_7;
label_0005A2FC:
    cpu->ebp = 0u;
    *(uint16_t*)(cpu->ecx) = cpu->ebp & 0xFFFFu;
    *(uint8_t*)(cpu->edx + cpu->eax) = 0u;
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ecx += 2u;
    ++cpu->eax;
    if ((--cpu->esi) != 0u) goto label_0005A2FC;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx += 0x200u;
    --*(uint32_t*)(cpu->esp + 0x24u); sub_pred[2] = *(uint32_t*)(cpu->esp + 0x24u) == 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (!sub_pred[2]) { value_7 = value_8; goto label_0005A2F7; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x1Au);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x1Au);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->ebx += 0x14u;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->ebx;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x118u);
    cpu->edi += 0x14u;
    cpu->ebx += cpu->edi;
    cpu->eax += cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xC8u);
    cpu->edx = 0x60u;
    cpu->ecx += 3u;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx; value_9 = value_8;
label_0005A36C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = 0u;
    cpu->ecx += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx; value_10 = value_9;
label_0005A37C:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint8_t*)(cpu->esi) = cpu->ecx & 0xFFu;
    if (*(uint8_t*)(cpu->eax) == 0u) { value_18 = value_10; goto label_0005A3D9; }
    cpu->esi = 0u;
    if ((int32_t)cpu->ebx < 0) { value_18 = value_10; goto label_0005A3D9; } value_11 = value_10;
label_0005A38F:
    cpu->eax = 0u; value_12 = value_11;
label_0005A391:
    if (cpu->ebx == 1u) { value_16 = value_12; goto label_0005A3BA; }
    cpu->ecx = cpu->ebx;
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    if (cpu->eax != cpu->ecx) { value_13 = value_12; goto label_0005A3A2; }
    if (cpu->esi == cpu->ecx) { value_17 = value_12; goto label_0005A3C4; } value_13 = value_12;
label_0005A3A2:
    if (cpu->eax != cpu->ebx) { value_14 = value_13; goto label_0005A3AA; }
    if (cpu->esi == cpu->ebx) { value_17 = value_13; goto label_0005A3C4; } value_14 = value_13;
label_0005A3AA:
    if (cpu->eax != cpu->ecx) { value_15 = value_14; goto label_0005A3B2; }
    if (cpu->esi == cpu->ebx) { value_17 = value_14; goto label_0005A3C4; } value_15 = value_14;
label_0005A3B2:
    if (cpu->eax != cpu->ebx) { value_16 = value_15; goto label_0005A3BA; }
    if (cpu->esi == cpu->ecx) { value_17 = value_15; goto label_0005A3C4; } value_16 = value_15;
label_0005A3BA:
    cpu->ecx = cpu->edx + cpu->eax;
    cpu->ecx += cpu->ebp;
    *(uint8_t*)(cpu->ecx + cpu->edi + 3u) = 1u; value_17 = value_16;
label_0005A3C4:
    ++cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebx) { value_12 = value_17; goto label_0005A391; }
    ++cpu->esi;
    cpu->edx += 0x20u;
    if ((int32_t)cpu->esi <= (int32_t)cpu->ebx) { value_11 = value_17; goto label_0005A38F; }
    cpu->edx = *(uint32_t*)(cpu->esp + 0x68u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u); value_18 = value_17;
label_0005A3D9:
    ++*(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ebp;
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if ((int32_t)cpu->ebp < (int32_t)0x1Au) { value_10 = value_18; goto label_0005A37C; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->edx += 0x20u;
    cpu->eax += 0x118u;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->eax;
    if ((int32_t)cpu->edx < (int32_t)0x3A0u) { value_9 = value_18; goto label_0005A36C; }
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esi = 0x19u;
    cpu->edx += 0x1B71u; value_19 = value_18;
label_0005A417:
    cpu->eax = 0x19u;
    cpu->ecx = cpu->edx; value_20 = value_19;
label_0005A41E:
    if (*(uint8_t*)(cpu->ecx) != 0u) goto label_0005A46F;
    cpu->ecx -= 0x118u;
    if ((int32_t)(--cpu->eax) >= 0) goto label_0005A41E;
    --cpu->edx;
    if ((int32_t)(--cpu->esi) >= 0) { value_19 = value_20; goto label_0005A417; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = cpu->edx + (cpu->eax * 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xD0u);
    cpu->ecx += cpu->eax;
    *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0])) = cpu->edx; value_21 = value_20;
label_0005A44B:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = 0u; value_22 = value_21;
label_0005A451:
    cpu->eax = 0u;
    cpu->ecx = cpu->esi; value_23 = value_22;
label_0005A455:
    if (*(uint8_t*)(cpu->ecx) != 0u) goto label_0005A486;
    ++cpu->eax;
    ++cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)0x1Au) goto label_0005A455;
    ++cpu->edx;
    cpu->esi += 0x118u;
    if ((int32_t)cpu->edx < (int32_t)0x1Au) { value_22 = value_23; goto label_0005A451; }
    value_24 = value_23; goto label_0005A490;
label_0005A46F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->esi;
    cpu->ecx = cpu->edx + (cpu->eax * 4u);
    cpu->ecx += cpu->eax;
    *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0])) = cpu->esi;
    value_21 = value_20; goto label_0005A44B;
label_0005A486:
    if ((int32_t)cpu->edx >= (int32_t)*(uint32_t*)(cpu->esp + 0x44u)) { value_24 = value_23; goto label_0005A490; }
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx; value_24 = value_23;
label_0005A490:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x7Cu);
    cpu->esi = 0x19u;
    cpu->eax += cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x118u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x58u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x38u); value_25 = value_24;
label_0005A4A9:
    cpu->ecx = 0u;
    cpu->edx = cpu->eax; value_26 = value_25;
label_0005A4AD:
    if (*(uint8_t*)(cpu->edx) != 0u) goto label_0005A4C3;
    ++cpu->ecx;
    ++cpu->edx;
    if ((int32_t)cpu->ecx < (int32_t)0x1Au) goto label_0005A4AD;
    cpu->eax -= 0x118u;
    if ((int32_t)(--cpu->esi) >= 0) { value_25 = value_26; goto label_0005A4A9; }
    value_27 = value_26; goto label_0005A4CD;
label_0005A4C3:
    if ((int32_t)cpu->esi <= (int32_t)*(uint32_t*)(cpu->esp + 0x3Cu)) { value_27 = value_26; goto label_0005A4CD; }
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi; value_27 = value_26;
label_0005A4CD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->eax -= cpu->edi;
    cpu->edx = cpu->edx + ((uintptr_t)((uint8_t*)&g_sfera_font_atlas_staging_runtime.pixels[0] + 2u));
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->edi + 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0x20u; value_28 = value_27;
label_0005A4F4:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = cpu->eax;
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 8u; value_29 = value_28;
label_0005A504:
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFFFDu) == 0u) goto label_0005A517;
    cpu->ecx = 0xFu;
    cpu->edx = cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    value_30 = value_29; goto label_0005A52A;
label_0005A517:
    cpu->ecx = 0u;
    cpu->edx = 0u;
    cpu->esi = 0u;
    if (*(uint8_t*)(cpu->ebx + 0xFFFFFFFFu) == 0u) goto label_0005A528;
    cpu->eax = cpu->ecx + 0xFu;
    value_30 = value_29; goto label_0005A52A;
label_0005A528:
    cpu->eax=0u; value_30 = value_29;
label_0005A52A:
    cpu->eax <<= 4u;
    cpu->eax|=cpu->esi;
    cpu->eax <<= 4u;
    cpu->eax|=cpu->edx;
    cpu->eax <<= 4u;
    cpu->eax |= cpu->ecx;
    *(uint16_t*)(cpu->edi + 0xFFFFFFFEu) = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x58u);
    if (*(uint8_t*)(cpu->eax + cpu->ebx) == 0u) goto label_0005A554;
    cpu->ecx = 0xFu;
    cpu->edx = cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    value_31 = value_30; goto label_0005A566;
label_0005A554:
    cpu->ecx = 0u;
    cpu->edx = 0u;
    cpu->esi = 0u;
    if (*(uint8_t*)(cpu->ebx) == 0u) goto label_0005A564;
    cpu->eax = cpu->ecx + 0xFu;
    value_31 = value_30; goto label_0005A566;
label_0005A564:
    cpu->eax=0u; value_31 = value_30;
label_0005A566:
    cpu->eax <<= 4u;
    cpu->eax|=cpu->esi;
    cpu->eax <<= 4u;
    cpu->eax|=cpu->edx;
    cpu->eax <<= 4u;
    cpu->eax |= cpu->ecx;
    *(uint16_t*)(cpu->edi) = cpu->eax & 0xFFFFu;
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFFFFu) == 0u) goto label_0005A58B;
    cpu->ecx = 0xFu;
    cpu->edx = cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    value_32 = value_31; goto label_0005A59E;
label_0005A58B:
    cpu->ecx = 0u;
    cpu->edx = 0u;
    cpu->esi = 0u;
    if (*(uint8_t*)(cpu->ebx + 1u) == 0u) goto label_0005A59C;
    cpu->eax = cpu->ecx + 0xFu;
    value_32 = value_31; goto label_0005A59E;
label_0005A59C:
    cpu->eax=0u; value_32 = value_31;
label_0005A59E:
    cpu->eax <<= 4u;
    cpu->eax|=cpu->esi;
    cpu->eax <<= 4u;
    cpu->eax|=cpu->edx;
    cpu->eax <<= 4u;
    cpu->eax |= cpu->ecx;
    *(uint16_t*)(cpu->edi + 2u) = cpu->eax & 0xFFFFu;
    if (*(uint8_t*)(cpu->ebp) == 0u) goto label_0005A5C4;
    cpu->ecx = 0xFu;
    cpu->edx = cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    value_33 = value_32; goto label_0005A5D7;
label_0005A5C4:
    cpu->ecx = 0u;
    cpu->edx = 0u;
    cpu->esi = 0u;
    if (*(uint8_t*)(cpu->ebx + 2u) == 0u) goto label_0005A5D5;
    cpu->eax = cpu->ecx + 0xFu;
    value_33 = value_32; goto label_0005A5D7;
label_0005A5D5:
    cpu->eax=0u; value_33 = value_32;
label_0005A5D7:
    cpu->eax <<= 4u;
    cpu->eax|=cpu->esi;
    cpu->eax <<= 4u;
    cpu->eax|=cpu->edx;
    cpu->eax <<= 4u;
    cpu->eax |= cpu->ecx;
    *(uint16_t*)(cpu->edi + 4u) = cpu->eax & 0xFFFFu;
    cpu->edi += 8u;
    cpu->ebp += 4u;
    cpu->ebx += 4u;
    if ((--*(uint32_t*)(cpu->esp + 0x1Cu)) != 0u) { value_29 = value_33; goto label_0005A504; }
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x200u) + (uint64_t)(0u);
    --*(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = cpu->ebp;
    cpu->ecx = cpu->ebx;
    if (*(uint32_t*)(cpu->esp + 0x2Cu) != 0u) { value_28 = value_33; goto label_0005A4F4; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xC8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx -= cpu->edx;
    cpu->ecx += 3u;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ecx;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x60u))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax <<= 4u;
    cpu->ecx -= cpu->edx;
    x87_p0 = (x87_p0) * (value_33);
    cpu->ecx += 3u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    ++cpu->esi;
    *(float*)(cpu->eax + ((uintptr_t)&g_sfera_font_runtime.glyphs[0].u)) = x87_p0; 
    *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_font_runtime.glyphs[0].defined)) = 1u;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u))));
    *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_font_runtime.glyphs[0].texture_index)) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    x87_p0 = (x87_p0) * (value_33);
    *(float*)(cpu->eax + ((uintptr_t)&g_sfera_font_runtime.glyphs[0].v)) = x87_p0; 
    if (cpu->esi != 8u) { value_34 = value_33; goto label_0005A746; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    ++cpu->eax;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    if (cpu->eax != 8u) { value_34 = value_33; goto label_0005A746; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = g_sfera_font_atlas_staging_runtime.height;
    cpu->eax = cpu->edi;
    cpu->edi = cpu->ecx + (cpu->eax * 4u);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->edi += cpu->eax;
    cpu->eax = g_sfera_font_atlas_staging_runtime.width;
    cpu->edi = (cpu->edi * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.atlas_resources[0][0]);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, 0x1Au);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->edx = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
     cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(D3DXCreateTexture(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device, *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u), static_cast<D3DFORMAT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), static_cast<D3DPOOL>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u)), SferaAbi::pointer<IDirect3DTexture9*>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 28u))), "D3DXCreateTexture")); cpu->esp += 32u;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x74u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x4Cu);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x5A6DFu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x70u);
    cpu->ebp = (uintptr_t)&g_sfera_font_atlas_staging_runtime.pixels[0];
    if ((int32_t)g_sfera_font_atlas_staging_runtime.height <= (int32_t)cpu->ebx) goto label_0005A728;
    cpu->eax = g_sfera_font_atlas_staging_runtime.width;
    cpu->eax += cpu->eax;
label_0005A700:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x45A703u));
    cpu->edx = g_sfera_font_atlas_staging_runtime.width;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u);
    cpu->eax = cpu->edx + cpu->edx;
    cpu->ecx >>= 1u;
    ++cpu->ebx;
    cpu->esp += 0xCu;
    cpu->ebp += cpu->eax;
    cpu->esi = cpu->esi + (cpu->ecx * 2u);
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_font_atlas_staging_runtime.height) goto label_0005A700;
label_0005A728:
    cpu->edi = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x50u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, cpu->ecx, LIFT_CODE_TOKEN_RVA(0x5A732u));
    x87_p0 = 0.00390625;
    ++*(uint32_t*)(cpu->esp + 0x28u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40u);
     value_36 = x87_p0;  value_34 = value_36;
label_0005A746:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x5Cu);
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_0005A225;
     if (cpu->esi != 0u) goto label_0005A771;
    if (*(uint32_t*)(cpu->esp + 0x34u) == cpu->esi) goto label_0005A821;
label_0005A771:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = g_sfera_font_atlas_staging_runtime.height;
    cpu->ecx = g_sfera_font_atlas_staging_runtime.width;
    cpu->esi = cpu->edx + (cpu->edi * 4u);
    cpu->esi += cpu->edi;
    cpu->esi = (cpu->esi * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.atlas_resources[0][0]);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, 0x1Au); lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->edx = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(D3DXCreateTexture(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device, *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u), static_cast<D3DFORMAT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), static_cast<D3DPOOL>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u)), SferaAbi::pointer<IDirect3DTexture9*>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 28u))), "D3DXCreateTexture")); cpu->esp += 32u;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x74u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x4Cu);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x5A7BDu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x70u);
    cpu->ebx = (uintptr_t)&g_sfera_font_atlas_staging_runtime.pixels[0];
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (((uint32_t)(g_sfera_font_atlas_staging_runtime.height) == 0u) || ((int32_t)((uint32_t)(g_sfera_font_atlas_staging_runtime.height)) < (int32_t)(0u))) goto label_0005A810;
    cpu->eax = g_sfera_font_atlas_staging_runtime.width;
    cpu->eax += cpu->eax;
label_0005A7E0:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x45A7E3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u);
    cpu->edx = g_sfera_font_atlas_staging_runtime.width;
    cpu->ecx >>= 1u;
    cpu->esi = cpu->esi + (cpu->ecx * 2u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = cpu->edx + cpu->edx;
    ++cpu->ecx;
    cpu->esp += 0xCu;
    cpu->ebx += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_font_atlas_staging_runtime.height) goto label_0005A7E0;
label_0005A810:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x50u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5A81Eu));
    ++cpu->edi;
label_0005A821:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
label_0005A829:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx -= cpu->edx;
    cpu->ecx += 3u;
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.span[0])) = cpu->ecx;
    cpu->ecx = 0x14u;
    cpu->ecx -= cpu->edx;
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.cell_step[0])) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.origin[0])) = cpu->edx;
    lift_push32(cpu, 0x8C8u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.resource_count[0])) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A868u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45A868u));
    lift_push32(cpu, 0x8C9u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A879u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45A879u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    lift_push32(cpu, 0x8CAu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A88Cu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45A88Cu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    lift_push32(cpu, 0x8CBu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A89Fu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45A89Fu));
    if ((uint32_t)(g_sfera_font_runtime.glyphs[124].defined) != 0u) goto label_0005A8BE;
    cpu->ecx = (uintptr_t)"Symbol for CODE_FOR_UNDIFINED_SYMBOL is not found in font.txt";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5A8B2u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5A8B2u));
label_0005A8B2:
    cpu->ecx = (uintptr_t)"wrong format of font1.txt";
     lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5A8BEu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5A8BEu));
label_0005A8BE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xB4u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0045A9C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, 0x8000000u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 1u);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, 0x80000000u); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x45A9D7u));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0xFFFFFFFFu) goto label_0005A9F0;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)"\316\370\350\341\352\340 \356\362\352\360\373\362\350\377 \364\340\351\353\3402: ";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5A9F0u)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x5A9F0u));
    label_0005A9F0:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::CreateFileMappingA), LIFT_CODE_TOKEN_VA(0x45A9FDu));
    cpu->ebx = native_function_address32(&::CloseHandle);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CloseHandle)))(*(uint32_t*)(cpu->esp)); cpu->esp += 0x4u;
    if (cpu->esi != 0xFFFFFFFFu) goto label_0005AA1D;
    cpu->ecx = (uintptr_t)"CreateFileMapping failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AA1Du)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AA1Du));
    label_0005AA1D:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 4u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::MapViewOfFile), LIFT_CODE_TOKEN_VA(0x45AA26u));
    lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CloseHandle)))(*(uint32_t*)(cpu->esp)); cpu->esp += 0x4u;
    if (cpu->edi != 0u) goto label_0005AA41;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)"MapViewOfFile failed  ";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AA41u)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x5AA41u));
    label_0005AA41:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045AA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    cpu->eax = address32(::GetModuleHandleW(nullptr));
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_direct_input_runtime.direct_input); lift_push32(cpu, address32(&IID_IDirectInput8A)); lift_push32(cpu, 0x800u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DirectInput8Create), LIFT_CODE_TOKEN_VA(0x45AA75u));
    if (cpu->eax == 0u) goto label_0005AA88;
    cpu->ecx = (uintptr_t)"DirectInputCreate failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AA88u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AA88u));
    label_0005AA88:
    cpu->eax = g_sfera_direct_input_runtime.direct_input;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_input_device_runtime.keyboard_device); lift_push32(cpu, address32(&GUID_SysKeyboard)); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5AA9Fu));
    if (cpu->eax == 0u) goto label_0005AAAF;
    cpu->ecx = (uintptr_t)"CreateDevice failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AAAFu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AAAFu));
    label_0005AAAF:
    cpu->eax = g_sfera_direct_input_runtime.direct_input;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_direct_input_runtime.mouse_device); lift_push32(cpu, address32(&GUID_SysMouse)); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5AAC6u));
    if (cpu->eax == 0u) goto label_0005AAD6;
    cpu->ecx = (uintptr_t)"CreateDevice failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AAD6u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AAD6u));
    label_0005AAD6:
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 6u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x34u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x5AAEAu));
    if (cpu->eax == 0u) goto label_0005AAFA;
    cpu->ecx = (uintptr_t)"SetCooperativeLevel failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AAFAu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AAFAu));
    label_0005AAFA:
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 6u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x34u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x5AB0Eu));
    if (cpu->eax == 0u) goto label_0005AB1E;
    cpu->ecx = (uintptr_t)"SetCooperativeLevel failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AB1Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AB1Eu));
    label_0005AB1E:
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    lift_push32(cpu, address32(&c_dfDIKeyboard)); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5AB2Eu));
    if (cpu->eax == 0u) goto label_0005AB3E;
    cpu->ecx = (uintptr_t)"SetDataFormat failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AB3Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AB3Eu));
    label_0005AB3E:
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    lift_push32(cpu, address32(&c_dfDIMouse)); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5AB4Eu));
    if (cpu->eax == 0u) goto label_0005AB5E;
    cpu->ecx = (uintptr_t)"SetDataFormat failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AB5Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AB5Eu));
    label_0005AB5E:
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->edx = cpu->esp;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 4u) = 0x14u;
    *(uint32_t*)(cpu->esp + 8u) = 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 8u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x18u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x5AB97u));
    if (cpu->eax == 0u) goto label_0005ABA7;
    cpu->ecx = (uintptr_t)"SetProperty failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ABA7u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5ABA7u));
    label_0005ABA7:
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5ABB2u));
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5ABBFu));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045AC40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_0005AC54;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AC54u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5AC54u));
    label_0005AC54:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005AC68;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AC68u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5AC68u));
    label_0005AC68:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) != 0u) goto label_0005AC7D;
    cpu->ecx = (uintptr_t)"text_color: wrong handle";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AC7Du)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AC7Du));
    label_0005AC7D:
    if ((int32_t)cpu->esi >= 0) goto label_0005AC8B;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AC8Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5AC8Bu));
    label_0005AC8B:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005AC9F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AC9Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5AC9Fu));
    label_0005AC9F:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->edx + 0x28u) = cpu->edi;
    if ((int32_t)cpu->esi >= 0) goto label_0005ACB9;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ACB9u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5ACB9u));
    label_0005ACB9:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005ACCD;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ACCDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5ACCDu));
    label_0005ACCD:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx + 0xE80u) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B02Fu)); sfera_sub_004D0FC0(cpu, LIFT_CODE_TOKEN_VA(0x45B02Fu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCD8u)); sfera_sub_004980F0(cpu, LIFT_CODE_TOKEN_VA(0x45BCD8u));
    cpu->ecx = 1u;
    ShadowMap::initialize(cpu->ecx); cpu->eax = SferaAbi::address(g_sfera_shadows.get());
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCE7u)); sfera_sub_00457490(cpu, LIFT_CODE_TOKEN_VA(0x45BCE7u));
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
    *(float*)((uintptr_t)((uint8_t *)&g_sfera_static_render_lookup_runtime.atlas_resources[0][0] + 0xF4u)) = (double)9.999999747378752e-05f;
    label_0005BD96:
    *(uint32_t*)(cpu->eax + 0xFFFFFFF4u) = cpu->esi;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->eax += 0x10u;
    if ((int32_t)(cpu->eax) < (int32_t)((uint32_t)((uintptr_t)&g_sfera_texture_cache_runtime.entries[kTextureCacheEntryCount] + offsetof(SferaTextureCacheEntry, use_count)))) goto label_0005BD96;
    cpu->edx = 0x15C2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BDB4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45BDB4u));
    cpu->eax = SferaAbi::address(new EnvironmentZones);
    label_0005BDD5:
    lift_push32(cpu, (uintptr_t)"Landscape\\zoning.cfg");
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    g_sfera_recovered_static_runtime.scene_state_08 = cpu->eax;
    SferaAbi::pointer<EnvironmentZones>(cpu->ecx)->load(SferaAbi::pointer<const char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)));  cpu->esp += 4u;
    cpu->edx = 0x15C4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BDF9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45BDF9u));
    cpu->eax = SferaAbi::address(new EnvironmentZones);
    label_0005BE1E:
    lift_push32(cpu, (uintptr_t)"Landscape\\zoningHaron.cfg");
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    g_sfera_world_render_queue_runtime.entries[0] = cpu->eax;
    SferaAbi::pointer<EnvironmentZones>(cpu->ecx)->load(SferaAbi::pointer<const char>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)));  cpu->esp += 4u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}




__declspec(noinline) void sfera_sub_0045CC30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_0005CD20;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005CC63;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CC63u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5CC63u));
    label_0005CC63:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_0005CD20;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005CC86;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CC86u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5CC86u));
    label_0005CC86:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (*(uint8_t*)(cpu->edx + 0x138u) == 0u) goto label_0005CD4B;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005CCB0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CCB0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5CCB0u));
    label_0005CCB0:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_0005CCD8;
    label_0005CCBC:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18Cu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005CCD8:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0005CCBC;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0005CCF9;
    cpu->eax = (uintptr_t)"<none>";
    label_0005CCF9:
    lift_push32(cpu, 0x2475u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45CD0Eu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CD20u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5CD20u));
    label_0005CD20:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005CD30:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005CD30;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetProcess: wrong handle"),25u); cpu->ecx = 0u;
    WorldDiagnostics::flushScriptContext();
    cpu->edi = lift_pop32(cpu);
    label_0005CD4B:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}









__declspec(noinline) void sfera_sub_0045DC60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_0005DC74;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5DC74u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5DC74u));
    label_0005DC74:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005DC88;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5DC88u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5DC88u));
    label_0005DC88:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = cpu->esi + 0x44u;
    cpu->eax = 0u;
    if (*(uint32_t*)(cpu->ecx) == 0xFFFFFFFFu) goto label_0005DCB0;
    label_0005DCA0:
    ++cpu->eax;
    cpu->ecx += 4u;
    if (cpu->eax == 0x1B58u) goto label_0005DCBA;
    if (*(uint32_t*)(cpu->ecx) != 0xFFFFFFFFu) goto label_0005DCA0;
    label_0005DCB0:
    *(uint32_t*)(cpu->esi + (cpu->eax * 4u) + 0x44u) = cpu->edi;
    ++*(uint32_t*)(cpu->esi + 0x40u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005DCBA:
    cpu->ecx = (uintptr_t)"MNO_CONTROLS_IN_WINDOW exceed";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45DCC4u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x45DCC4u));
    cpu->eip = 0x45DCC4u; ::DebugBreak(); return;
}



__declspec(noinline) void sfera_sub_0045EB60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_0005EB74;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EB74u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5EB74u));
    label_0005EB74:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005EB88;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EB88u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5EB88u));
    label_0005EB88:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) != 0u) goto label_0005EB9D;
    cpu->ecx = (uintptr_t)"set_sprite_alpha: wrong handle";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EB9Du)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5EB9Du));
    label_0005EB9D:
    if ((int32_t)cpu->esi >= 0) goto label_0005EBAB;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EBABu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5EBABu));
    label_0005EBAB:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005EBBF;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EBBFu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5EBBFu));
    label_0005EBBF:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->edx + 0xE80u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045EBE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->esi < (int32_t)cpu->ebx) goto label_0005ECF0;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005EC06;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EC06u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5EC06u));
    label_0005EC06:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == cpu->ebx) goto label_0005ECF0;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005EC28;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EC28u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5EC28u));
    label_0005EC28:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->edi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((int32_t)*(uint32_t*)(cpu->edi + 0x40u) <= (int32_t)cpu->ebx) goto label_0005ECB1;
    label_0005EC41:
    cpu->eax = cpu->edi + (cpu->ebx * 4u) + 0x44u;
    if (*(uint32_t*)(cpu->edi + (cpu->ebx * 4u) + 0x44u) != 0xFFFFFFFFu) goto label_0005EC59;
    label_0005EC50:
    cpu->eax += 4u;
    ++cpu->ebx;
    if (*(uint32_t*)(cpu->eax) == 0xFFFFFFFFu) goto label_0005EC50;
    label_0005EC59:
    cpu->esi = *(uint32_t*)(cpu->edi + (cpu->ebx * 4u) + 0x44u);
    if ((int32_t)cpu->esi >= 0) goto label_0005EC6B;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EC6Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5EC6Bu));
    label_0005EC6B:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005EC7F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EC7Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5EC7Fu));
    label_0005EC7F:
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (cpu->esi == 0u) goto label_0005ECE6;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebp) goto label_0005EC95;
    cpu->ebp = cpu->eax;
    label_0005EC95:
    cpu->esi = *(uint32_t*)(cpu->esi + 0x18u);
    if ((int32_t)cpu->esi <= (int32_t)*(uint32_t*)(cpu->esp + 0x10u)) goto label_0005ECA2;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_0005ECA2:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edi + 0x40u)) goto label_0005EC41;
    label_0005ECB1:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x20u);
    cpu->eax -= *(uint32_t*)(cpu->edi + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x28u);
    cpu->ecx -= *(uint32_t*)(cpu->edi + 0x24u);
    ++*(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ebp;
    ++cpu->eax;
    ++cpu->ecx;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebp) goto label_0005ECCA;
    cpu->ebp = cpu->eax;
    label_0005ECCA:
    if ((int32_t)cpu->ecx <= (int32_t)*(uint32_t*)(cpu->esp + 0x10u)) goto label_0005ECD4;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_0005ECD4:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edi + 0x2Cu) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->edi + 0x30u) = cpu->eax;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005ECE6:
    cpu->ecx = (uintptr_t)"internal error 47581837";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ECF0u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5ECF0u));
    label_0005ECF0:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = cpu->ebx & 0xFFu;
    --cpu->edi;
    label_0005ED00:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005ED00;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"recalc_virtual_window_size: wrong handle"),41u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    WorldDiagnostics::flushScriptContext();  cpu->esp += 4u; cpu->eip = stop_address; return;
}















__declspec(noinline) void sfera_sub_00461DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x424u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->esi = cpu->eax;
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    cpu->edx = (uintptr_t)"trap";
    cpu->ecx = cpu->esi;
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461E0Du)); sfera_sub_0044CB00(cpu, LIFT_CODE_TOKEN_VA(0x461E0Du));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00061F47;
    cpu->ecx = cpu->ebx;
    cpu->ecx -= g_sfera_model_material_lookup_runtime.refresh_tick;
    if (cpu->ecx <= 0x2710u) goto label_00061F47;
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00061F41;
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_00061E47;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61E47u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x61E47u));
    label_00061E47:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00061E5B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61E5Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61E5Bu));
    label_00061E5B:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (cpu->eax != 0u) goto label_00061E93;
    label_00061E68:
    if (*(uint32_t*)(cpu->eax + 0x18Cu) == 0u) goto label_00061F41;
    cpu->eax = 0u;
    cpu->ecx = cpu->edi + 0x10Cu;
    label_00061E80:
    if (*(uint32_t*)(cpu->ecx) != 0xFFFFFFFFu) goto label_00061EDB;
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((int32_t)cpu->eax < (int32_t)0xAu) goto label_00061E80;
    goto label_00061F41;
    label_00061E93:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_00061E68;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_00061EB4;
    cpu->eax = (uintptr_t)"<none>";
    label_00061EB4:
    lift_push32(cpu, 0x4A1Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x461EC9u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61EDBu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x61EDBu));
    label_00061EDB:
    cpu->ecx = *(uint32_t*)(cpu->edi + (cpu->eax * 4u) + 0x10Cu);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_effect_manager.listenerKey(cpu->ecx));
    cpu->edi = native_function_address32(&::sprintf);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"trap %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x61EF8u));
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
    cpu->esp += 0xCu;
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_00061F12;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61F12u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x61F12u));
    label_00061F12:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00061F26;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61F26u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61F26u));
    label_00061F26:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->eax != 0u) goto label_00061F5F;
    label_00061F32:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18Cu);
    cpu->edx = cpu->esp + 0xCu;
    SferaAbi::pointer<SferaMbcProcessRecord>(cpu->ecx)->appendCommand(SferaAbi::pointer<const char>(cpu->edx));
    label_00061F41:
    g_sfera_model_material_lookup_runtime.refresh_tick = cpu->ebx;
    label_00061F47:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x424u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00061F5F:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_00061F32;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_00061F80;
    cpu->eax = (uintptr_t)"<none>";
    label_00061F80:
    lift_push32(cpu, 0x4A25u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x61F95u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461FA3u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x461FA3u));
    cpu->eip = 0x461FA3u; ::DebugBreak(); return;
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
__declspec(noinline) void sfera_sub_00462690(LiftCpu* cpu, uint32_t stop_address) {
    WNDCLASSEXA window_class{};
    window_class.cbSize = sizeof(window_class);
    window_class.style = CS_HREDRAW | CS_VREDRAW;
    window_class.lpfnWndProc = &sfera_main_window_proc;
    window_class.hInstance = reinterpret_cast<HINSTANCE>(static_cast<uintptr_t>(g_sfera_main_ui_state_runtime.active_ui_object));
    window_class.hIcon = ::LoadIconA(window_class.hInstance, MAKEINTRESOURCEA(0x71));
    window_class.hCursor = ::LoadCursorW(nullptr, IDC_ARROW);
    window_class.hbrBackground = reinterpret_cast<HBRUSH>(::GetStockObject(BLACK_BRUSH));
    window_class.lpszClassName = reinterpret_cast<LPCSTR>(static_cast<uintptr_t>(sfera_window_class_name()));
    window_class.hIconSm = window_class.hIcon;
    if (::RegisterClassExA(&window_class) == 0u) { cpu->ecx = reinterpret_cast<uint32_t>("RegisterClassEx() failed! => init_main_window_class()"); lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x62730u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x62730u)); }
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


} // namespace lifted
