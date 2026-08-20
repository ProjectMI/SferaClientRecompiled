#include "semantic_native.h"
#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <stddef.h>

extern "C" uint32_t g_sfera_security_cookie = UINT32_C(0xBB40E64E);
extern "C" uint32_t g_sfera_security_cookie_complement = UINT32_C(0x44BF19B1);
extern "C" uint32_t g_sfera_log_first_write = 1u;
#include <stdint.h>
#include <string.h>

/* ===== Native storage definitions ===== */
#if defined(_MSC_VER)
#define SFERA_STORAGE_ALIGN __declspec(align(64))
#else
#define SFERA_STORAGE_ALIGN __attribute__((aligned(64)))
#endif

extern "C" {

SferaItemArray g_sfera_effect_items = {};
SferaItemArray g_sfera_sound_effect_items = {};
SferaServerWall g_sfera_server_wall = {};
SferaNetworkRuntime g_sfera_network_runtime = {};
SferaNetworkConnectionCheckerRuntime g_sfera_network_connection_checker = {};
SferaGraphicsRuntime g_sfera_graphics_runtime = {};
SferaSceneRenderRuntime g_sfera_scene_render_runtime = {};
SferaScreenVertex g_sfera_sky_screen_vertices[SFERA_SKY_SCREEN_VERTEX_COUNT] = {};
SferaScreenVertex g_sfera_landscape_screen_vertices[SFERA_LANDSCAPE_SCREEN_VERTEX_COUNT] = {};
SferaBoundCheckArray g_sfera_character_index_map = {};
SferaBoundCheckArray g_sfera_mesh_partition_indices = {};
SferaGraphicsOptionsRuntime g_sfera_graphics_options_runtime = {};
SferaViewGeometryRuntime g_sfera_view_geometry_runtime = {};
SferaWorldObjectRuntime g_sfera_world_objects = {};
SferaGrassRuntime g_sfera_grass_runtime = {};
SferaLightRuntime g_sfera_light_runtime = {};
SferaLandscapeRuntime g_sfera_landscape_runtime = {};
SferaCollisionRuntime g_sfera_collision_runtime = {};
SferaSceneArrayRuntime g_sfera_scene_array_runtime = {};
SferaWeatherRuntime g_sfera_weather_runtime = {};
SferaModelRuntime g_sfera_model_runtime = {};
SferaWarningLogRuntime g_sfera_warning_log_runtime = {};
SferaControlOptionsRuntime g_sfera_control_options = {};
SferaSpriteRuntime g_sfera_sprite_runtime = {};
SferaCrashRuntime g_sfera_crash_runtime = {};
SferaContoursRuntime g_sfera_contours_runtime = {};
SferaDynGreenRuntime g_sfera_dyn_green_runtime = {};
SferaExecutionMonitorRuntime g_sfera_execution_monitor_runtime = {};
SferaErrorLogRuntime g_sfera_error_log_runtime = {};
SferaPacketCodecRuntime g_sfera_packet_codec_runtime = {};
SferaOleHostAbi g_sfera_ole_host_abi = {};
uint32_t g_sfera_graphics_display_depth_bits = 32u;
SferaInterfaceRuntime g_sfera_interface_runtime = {};
SferaStdAllocator g_sfera_std_allocator = {};
SferaMemoryRuntime g_sfera_memory_runtime = {};
SferaRenderBufferCapacities g_sfera_render_buffer_capacities = {30000u, 30000u, 5000u, 5000u};
uint32_t g_sfera_blood_effect_instance = 0u;
SferaFileRuntime g_sfera_file_runtime = {};
SferaEffectManagerRuntime g_sfera_effect_manager = {};
SferaConfigParserRuntime g_sfera_config_parser_runtime = {};
static SferaMbcRuntime g_sfera_mbc_runtime_storage = {};
SferaMbcRuntime* g_sfera_mbc_runtime = &g_sfera_mbc_runtime_storage;
SferaMbcInterpreterStorage g_sfera_mbc_interpreter_storage = {};
SferaMbcModuleMemoryStats g_sfera_mbc_module_memory_stats[SFERA_MBC_MODULE_STATS_COUNT] = {};
char g_sfera_array_error_buffer[256] = {};
SferaMsvcString32 g_sfera_shared_parser_whitespace = {};
SferaMsvcString32 g_sfera_shared_parser_path_separators = {};
SferaMsvcString32 g_sfera_server_parser_whitespace = {};
SferaMsvcString32 g_sfera_server_parser_path_separators = {};
SferaMsvcString32 g_sfera_menu_parser_whitespace = {};
SferaMsvcString32 g_sfera_menu_parser_path_separators = {};
SferaMsvcString32 g_sfera_menu_list_missing_parameter_message = {};
SferaMsvcString32 g_sfera_menu_not_enough_arguments_message = {};
SferaMsvcString32 g_sfera_menu_sprite_not_found_message = {};

const SferaMsvcVbtable2 g_sfera_vbtable_basic_ofstream = {0, 0x60};
const SferaMsvcVbtable2 g_sfera_vbtable_basic_ifstream = {0, 0x68};
const SferaMsvcVbtable2 g_sfera_vbtable_basic_ostringstream = {0, 0x50};
uint32_t g_sfera_native_vtable_basic_filebuf[15] = {};
uint32_t g_sfera_native_vtable_basic_ofstream[1] = {};
uint32_t g_sfera_native_vtable_basic_ifstream[1] = {};
uint32_t g_sfera_native_vtable_basic_stringbuf[15] = {};
uint32_t g_sfera_native_vtable_basic_ostringstream[1] = {};
const SferaGuid32 g_sfera_guid_iid_doc_host_ui_handler = {UINT32_C(0xBD3F23C0), UINT16_C(0xD43E), UINT16_C(0x11CF), {UINT8_C(0x89), UINT8_C(0x3B), UINT8_C(0x00), UINT8_C(0xAA), UINT8_C(0x00), UINT8_C(0xBD), UINT8_C(0xCE), UINT8_C(0x1A)}};
const SferaGuid32 g_sfera_guid_iid_ole_client_site = {UINT32_C(0x00000118), UINT16_C(0x0000), UINT16_C(0x0000), {UINT8_C(0xC0), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x46)}};
const SferaGuid32 g_sfera_guid_iid_ole_object = {UINT32_C(0x00000112), UINT16_C(0x0000), UINT16_C(0x0000), {UINT8_C(0xC0), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x46)}};
const SferaGuid32 g_sfera_guid_00000114 = {UINT32_C(0x00000114), UINT16_C(0x0000), UINT16_C(0x0000), {UINT8_C(0xC0), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x46)}};
const SferaGuid32 g_sfera_guid_00000113 = {UINT32_C(0x00000113), UINT16_C(0x0000), UINT16_C(0x0000), {UINT8_C(0xC0), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x46)}};
const SferaGuid32 g_sfera_guid_00000119 = {UINT32_C(0x00000119), UINT16_C(0x0000), UINT16_C(0x0000), {UINT8_C(0xC0), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x46)}};
const SferaGuid32 g_sfera_guid_00000127 = {UINT32_C(0x00000127), UINT16_C(0x0000), UINT16_C(0x0000), {UINT8_C(0xC0), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x46)}};
const SferaGuid32 g_sfera_guid_iid_iunknown = {UINT32_C(0x00000000), UINT16_C(0x0000), UINT16_C(0x0000), {UINT8_C(0xC0), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x00), UINT8_C(0x46)}};
const SferaGuid32 g_sfera_guid_iid_web_browser2 = {UINT32_C(0xD30C1661), UINT16_C(0xCDAF), UINT16_C(0x11D0), {UINT8_C(0x8A), UINT8_C(0x3E), UINT8_C(0x00), UINT8_C(0xC0), UINT8_C(0x4F), UINT8_C(0xC9), UINT8_C(0xE2), UINT8_C(0x6E)}};
const SferaGuid32 g_sfera_guid_clsid_web_browser = {UINT32_C(0x8856F961), UINT16_C(0x340A), UINT16_C(0x11D0), {UINT8_C(0xA9), UINT8_C(0x6B), UINT8_C(0x00), UINT8_C(0xC0), UINT8_C(0x4F), UINT8_C(0xD7), UINT8_C(0x05), UINT8_C(0xA2)}};
const SferaGuid32 g_sfera_guid_332c4425 = {UINT32_C(0x332C4425), UINT16_C(0x26CB), UINT16_C(0x11D0), {UINT8_C(0xB4), UINT8_C(0x83), UINT8_C(0x00), UINT8_C(0xC0), UINT8_C(0x4F), UINT8_C(0xD9), UINT8_C(0x01), UINT8_C(0x19)}};
const SferaGuid32 g_sfera_guid_direct_input_key = {UINT32_C(0x55728220), UINT16_C(0xD33C), UINT16_C(0x11CF), {UINT8_C(0xBF), UINT8_C(0xC7), UINT8_C(0x44), UINT8_C(0x45), UINT8_C(0x53), UINT8_C(0x54), UINT8_C(0x00), UINT8_C(0x00)}};
const SferaGuid32 g_sfera_guid_direct_input_x_axis = {UINT32_C(0xA36D02E0), UINT16_C(0xC9F3), UINT16_C(0x11CF), {UINT8_C(0xBF), UINT8_C(0xC7), UINT8_C(0x44), UINT8_C(0x45), UINT8_C(0x53), UINT8_C(0x54), UINT8_C(0x00), UINT8_C(0x00)}};
const SferaGuid32 g_sfera_guid_direct_input_y_axis = {UINT32_C(0xA36D02E1), UINT16_C(0xC9F3), UINT16_C(0x11CF), {UINT8_C(0xBF), UINT8_C(0xC7), UINT8_C(0x44), UINT8_C(0x45), UINT8_C(0x53), UINT8_C(0x54), UINT8_C(0x00), UINT8_C(0x00)}};
const SferaGuid32 g_sfera_guid_direct_input_z_axis = {UINT32_C(0xA36D02E2), UINT16_C(0xC9F3), UINT16_C(0x11CF), {UINT8_C(0xBF), UINT8_C(0xC7), UINT8_C(0x44), UINT8_C(0x45), UINT8_C(0x53), UINT8_C(0x54), UINT8_C(0x00), UINT8_C(0x00)}};
extern "C" uint32_t sfera_cursor_texture_name(uint32_t slot) { switch (slot) { case 0u: return (uint32_t)(uintptr_t)"_cursor1"; case 1u: return (uint32_t)(uintptr_t)"_cursor2"; case 2u: return (uint32_t)(uintptr_t)"cursor2"; case 3u: return (uint32_t)(uintptr_t)"cursor1"; default: return 0u; } }

uint32_t SFERA_IMPORT_WINMM_timeGetTime = 0u;
uint32_t SFERA_IMPORT_DINPUT8_DirectInput8Create = 0u;
uint32_t SFERA_IMPORT_COMCTL32_ordinal_17 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_19 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_16 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_151 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_18 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_116 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_3 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_111 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_4 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_52 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_12 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_11 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_9 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_115 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_2 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_10 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_51 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_23 = 0u;
uint32_t SFERA_IMPORT_WS2_32_ordinal_21 = 0u;
uint32_t SFERA_IMPORT_d3dx9_26_D3DXCreateTexture = 0u;
uint32_t SFERA_IMPORT_d3dx9_26_D3DXGetShaderConstantTable = 0u;
uint32_t SFERA_IMPORT_d3dx9_26_D3DXMatrixLookAtRH = 0u;
uint32_t SFERA_IMPORT_d3dx9_26_D3DXMatrixRotationQuaternion = 0u;
uint32_t SFERA_IMPORT_d3dx9_26_D3DXCreateCubeTextureFromFileInMemory = 0u;
uint32_t SFERA_IMPORT_d3dx9_26_D3DXMatrixPerspectiveFovRH = 0u;
uint32_t SFERA_IMPORT_d3dx9_26_D3DXCreateTextureFromFileInMemoryEx = 0u;
uint32_t SFERA_IMPORT_d3dx9_26_D3DXMatrixMultiply = 0u;
uint32_t SFERA_IMPORT_d3d9_Direct3DCreate9 = 0u;
uint32_t SFERA_IMPORT_KERNEL32_IsDebuggerPresent = 0u;
uint32_t SFERA_IMPORT_KERNEL32_IsProcessorFeaturePresent = 0u;
uint32_t SFERA_IMPORT_KERNEL32_UnhandledExceptionFilter = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetStartupInfoW = 0u;
uint32_t SFERA_IMPORT_KERNEL32_HeapSetInformation = 0u;
uint32_t SFERA_IMPORT_KERNEL32_InterlockedCompareExchange = 0u;
uint32_t SFERA_IMPORT_KERNEL32_InterlockedExchange = 0u;
uint32_t SFERA_IMPORT_KERNEL32_DecodePointer = 0u;
uint32_t SFERA_IMPORT_KERNEL32_EncodePointer = 0u;
uint32_t SFERA_IMPORT_KERNEL32_TryEnterCriticalSection = 0u;
uint32_t SFERA_IMPORT_KERNEL32_LocalFree = 0u;
uint32_t SFERA_IMPORT_KERNEL32_SetFilePointer = 0u;
uint32_t SFERA_IMPORT_KERNEL32_SetUnhandledExceptionFilter = 0u;
uint32_t SFERA_IMPORT_KERNEL32_Sleep = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetLocalTime = 0u;
uint32_t SFERA_IMPORT_KERNEL32_EnterCriticalSection = 0u;
uint32_t SFERA_IMPORT_KERNEL32_LeaveCriticalSection = 0u;
uint32_t SFERA_IMPORT_KERNEL32_CloseHandle = 0u;
uint32_t SFERA_IMPORT_KERNEL32_TerminateThread = 0u;
uint32_t SFERA_IMPORT_KERNEL32_WaitForSingleObject = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetTickCount = 0u;
uint32_t SFERA_IMPORT_KERNEL32_SetThreadPriority = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetLastError = 0u;
uint32_t SFERA_IMPORT_KERNEL32_CreateThread = 0u;
uint32_t SFERA_IMPORT_KERNEL32_UnmapViewOfFile = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetExitCodeThread = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetCurrentProcess = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetCurrentThread = 0u;
uint32_t SFERA_IMPORT_KERNEL32_InitializeCriticalSection = 0u;
uint32_t SFERA_IMPORT_KERNEL32_DeleteCriticalSection = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GlobalFree = 0u;
uint32_t SFERA_IMPORT_KERNEL32_WideCharToMultiByte = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GlobalAlloc = 0u;
uint32_t SFERA_IMPORT_KERNEL32_MultiByteToWideChar = 0u;
uint32_t SFERA_IMPORT_KERNEL32_ExitProcess = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetFileSize = 0u;
uint32_t SFERA_IMPORT_KERNEL32_ReadFile = 0u;
uint32_t SFERA_IMPORT_KERNEL32_CreateFileA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_FindClose = 0u;
uint32_t SFERA_IMPORT_KERNEL32_FindNextFileA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_FindFirstFileA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_Process32Next = 0u;
uint32_t SFERA_IMPORT_KERNEL32_Process32First = 0u;
uint32_t SFERA_IMPORT_KERNEL32_CreateToolhelp32Snapshot = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetVolumeInformationA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_MapViewOfFile = 0u;
uint32_t SFERA_IMPORT_KERNEL32_CreateFileMappingA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_CreateDirectoryA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_SetThreadAffinityMask = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetExitCodeProcess = 0u;
uint32_t SFERA_IMPORT_KERNEL32_TerminateProcess = 0u;
uint32_t SFERA_IMPORT_KERNEL32_CreateProcessA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetSystemDirectoryA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_QueryPerformanceCounter = 0u;
uint32_t SFERA_IMPORT_KERNEL32_QueryPerformanceFrequency = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetModuleHandleA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GlobalUnlock = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GlobalLock = 0u;
uint32_t SFERA_IMPORT_KERNEL32_WriteFile = 0u;
uint32_t SFERA_IMPORT_KERNEL32_lstrlenA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetVersionExA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetCurrentThreadId = 0u;
uint32_t SFERA_IMPORT_KERNEL32_RaiseException = 0u;
uint32_t SFERA_IMPORT_KERNEL32_OutputDebugStringA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_FileTimeToDosDateTime = 0u;
uint32_t SFERA_IMPORT_KERNEL32_FileTimeToLocalFileTime = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GlobalMemoryStatus = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetSystemInfo = 0u;
uint32_t SFERA_IMPORT_KERNEL32_lstrcpyA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetModuleFileNameA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetSystemTimeAsFileTime = 0u;
uint32_t SFERA_IMPORT_KERNEL32_lstrcatA = 0u;
uint32_t SFERA_IMPORT_KERNEL32_GetCurrentProcessId = 0u;
uint32_t SFERA_IMPORT_KERNEL32_VirtualQuery = 0u;
uint32_t SFERA_IMPORT_USER32_BringWindowToTop = 0u;
uint32_t SFERA_IMPORT_USER32_DestroyWindow = 0u;
uint32_t SFERA_IMPORT_USER32_GetSystemMetrics = 0u;
uint32_t SFERA_IMPORT_USER32_SendMessageA = 0u;
uint32_t SFERA_IMPORT_USER32_UpdateWindow = 0u;
uint32_t SFERA_IMPORT_USER32_InvalidateRect = 0u;
uint32_t SFERA_IMPORT_USER32_ShowWindow = 0u;
uint32_t SFERA_IMPORT_USER32_ReleaseDC = 0u;
uint32_t SFERA_IMPORT_USER32_GetDC = 0u;
uint32_t SFERA_IMPORT_USER32_GetWindowLongA = 0u;
uint32_t SFERA_IMPORT_USER32_GetClientRect = 0u;
uint32_t SFERA_IMPORT_USER32_SetWindowLongA = 0u;
uint32_t SFERA_IMPORT_USER32_DefWindowProcA = 0u;
uint32_t SFERA_IMPORT_USER32_MessageBeep = 0u;
uint32_t SFERA_IMPORT_USER32_TranslateMessage = 0u;
uint32_t SFERA_IMPORT_USER32_DispatchMessageA = 0u;
uint32_t SFERA_IMPORT_USER32_PeekMessageA = 0u;
uint32_t SFERA_IMPORT_USER32_MessageBoxA = 0u;
uint32_t SFERA_IMPORT_USER32_ShowCursor = 0u;
uint32_t SFERA_IMPORT_USER32_SetCursorPos = 0u;
uint32_t SFERA_IMPORT_USER32_GetCursorPos = 0u;
uint32_t SFERA_IMPORT_USER32_ScreenToClient = 0u;
uint32_t SFERA_IMPORT_USER32_SetCursor = 0u;
uint32_t SFERA_IMPORT_USER32_ClipCursor = 0u;
uint32_t SFERA_IMPORT_USER32_DestroyCursor = 0u;
uint32_t SFERA_IMPORT_USER32_CreateIconIndirect = 0u;
uint32_t SFERA_IMPORT_USER32_wsprintfA = 0u;
uint32_t SFERA_IMPORT_USER32_wvsprintfA = 0u;
uint32_t SFERA_IMPORT_USER32_CreateDialogParamA = 0u;
uint32_t SFERA_IMPORT_USER32_SetClassLongA = 0u;
uint32_t SFERA_IMPORT_USER32_GetDlgCtrlID = 0u;
uint32_t SFERA_IMPORT_USER32_GetWindowTextA = 0u;
uint32_t SFERA_IMPORT_USER32_SetWindowTextA = 0u;
uint32_t SFERA_IMPORT_USER32_EnableWindow = 0u;
uint32_t SFERA_IMPORT_USER32_IsDialogMessageA = 0u;
uint32_t SFERA_IMPORT_USER32_GetDlgItem = 0u;
uint32_t SFERA_IMPORT_USER32_IsClipboardFormatAvailable = 0u;
uint32_t SFERA_IMPORT_USER32_OpenClipboard = 0u;
uint32_t SFERA_IMPORT_USER32_GetClipboardData = 0u;
uint32_t SFERA_IMPORT_USER32_CloseClipboard = 0u;
uint32_t SFERA_IMPORT_USER32_SetFocus = 0u;
uint32_t SFERA_IMPORT_USER32_ClientToScreen = 0u;
uint32_t SFERA_IMPORT_USER32_CallWindowProcA = 0u;
uint32_t SFERA_IMPORT_USER32_FindWindowA = 0u;
uint32_t SFERA_IMPORT_USER32_LoadIconA = 0u;
uint32_t SFERA_IMPORT_USER32_LoadCursorA = 0u;
uint32_t SFERA_IMPORT_USER32_RegisterClassExA = 0u;
uint32_t SFERA_IMPORT_USER32_PostQuitMessage = 0u;
uint32_t SFERA_IMPORT_USER32_SetRect = 0u;
uint32_t SFERA_IMPORT_USER32_AdjustWindowRect = 0u;
uint32_t SFERA_IMPORT_USER32_CreateWindowExA = 0u;
uint32_t SFERA_IMPORT_USER32_UnregisterClassA = 0u;
uint32_t SFERA_IMPORT_GDI32_GetObjectType = 0u;
uint32_t SFERA_IMPORT_GDI32_CreateBitmap = 0u;
uint32_t SFERA_IMPORT_GDI32_GetStockObject = 0u;
uint32_t SFERA_IMPORT_GDI32_CreateCompatibleDC = 0u;
uint32_t SFERA_IMPORT_GDI32_CreateCompatibleBitmap = 0u;
uint32_t SFERA_IMPORT_GDI32_GetDIBits = 0u;
uint32_t SFERA_IMPORT_GDI32_SelectObject = 0u;
uint32_t SFERA_IMPORT_GDI32_DeleteDC = 0u;
uint32_t SFERA_IMPORT_GDI32_SetPixel = 0u;
uint32_t SFERA_IMPORT_GDI32_DeleteObject = 0u;
uint32_t SFERA_IMPORT_ADVAPI32_GetUserNameA = 0u;
uint32_t SFERA_IMPORT_SHELL32_ShellExecuteA = 0u;
uint32_t SFERA_IMPORT_ole32_CoInitialize = 0u;
uint32_t SFERA_IMPORT_ole32_CoCreateInstance = 0u;
uint32_t SFERA_IMPORT_ole32_CoUninitialize = 0u;
uint32_t SFERA_IMPORT_ole32_OleCreate = 0u;
uint32_t SFERA_IMPORT_ole32_OleSetContainedObject = 0u;
uint32_t SFERA_IMPORT_OLEAUT32_ordinal_6 = 0u;
uint32_t SFERA_IMPORT_OLEAUT32_ordinal_9 = 0u;
uint32_t SFERA_IMPORT_OLEAUT32_ordinal_2 = 0u;
uint32_t SFERA_IMPORT_OLEAUT32_ordinal_8 = 0u;
uint32_t SFERA_IMPORT_dbghelp_SymFromAddr = 0u;
uint32_t SFERA_IMPORT_dbghelp_SymGetModuleBase = 0u;
uint32_t SFERA_IMPORT_dbghelp_SymFunctionTableAccess = 0u;
uint32_t SFERA_IMPORT_dbghelp_StackWalk = 0u;
uint32_t SFERA_IMPORT_dbghelp_SymGetLineFromAddr = 0u;
uint32_t SFERA_IMPORT_dbghelp_SymSetOptions = 0u;
uint32_t SFERA_IMPORT_dbghelp_SymInitialize = 0u;
uint32_t SFERA_IMPORT_dbghelp_MiniDumpWriteDump = 0u;
uint32_t SFERA_IMPORT_Sound_SI_SetHardwareMixing_YAX_N_Z = 0u;
uint32_t SFERA_IMPORT_Sound_CSoundListener_GetOrientation = 0u;
uint32_t SFERA_IMPORT_Sound_CSoundListener_SetPosition = 0u;
uint32_t SFERA_IMPORT_Sound_CSoundListener_SetVelocity = 0u;
uint32_t SFERA_IMPORT_Sound_CSoundListener_SetOrientation = 0u;
uint32_t SFERA_IMPORT_Sound_CSoundInterface_UpdateSettings = 0u;
uint32_t SFERA_IMPORT_Sound_CSound_SetAllParameters = 0u;
uint32_t SFERA_IMPORT_Sound_CSound_LoadSound = 0u;
uint32_t SFERA_IMPORT_Sound_CSound_SetVolume = 0u;
uint32_t SFERA_IMPORT_Sound_SI_GetStreamVolume_YAHXZ = 0u;
uint32_t SFERA_IMPORT_Sound_CSound_Rewind = 0u;
uint32_t SFERA_IMPORT_Sound_CSound_Stop = 0u;
uint32_t SFERA_IMPORT_Sound_CSound_ctor = 0u;
uint32_t SFERA_IMPORT_Sound_SI_CreateInterface_YAPAVCSoundInterface_PAUHWND_HKK_Z = 0u;
uint32_t SFERA_IMPORT_Sound_CSound_SetPosition = 0u;
uint32_t SFERA_IMPORT_Sound_CSound_GetPlayTimepos = 0u;
uint32_t SFERA_IMPORT_Sound_CSound_IsSoundPlaying = 0u;
uint32_t SFERA_IMPORT_Sound_CSound_SetPlayTimepos = 0u;
uint32_t SFERA_IMPORT_Sound_CSound_Play = 0u;
uint32_t SFERA_IMPORT_Sound_SI_GetInterface_YAPAVCSoundInterface_XZ = 0u;
uint32_t SFERA_IMPORT_Sound_CSoundStream_SetDecodeSignal = 0u;
uint32_t SFERA_IMPORT_Sound_CSoundStream_SeekToTime = 0u;
uint32_t SFERA_IMPORT_Sound_CSoundStream_SetPlaySignal = 0u;
uint32_t SFERA_IMPORT_Sound_CSoundStream_Stop = 0u;
uint32_t SFERA_IMPORT_Sound_CSoundStream_IsStreamPlaying = 0u;
uint32_t SFERA_IMPORT_Sound_CSoundStream_PlayEx = 0u;
uint32_t SFERA_IMPORT_Sound_SI_Close_YAXXZ = 0u;
uint32_t SFERA_IMPORT_Sound_SI_SetLogFile_YAXPBD_Z = 0u;
uint32_t SFERA_IMPORT_Sound_CSound_SetVelocity = 0u;
uint32_t SFERA_IMPORT_Sound_SI_SetStreamVolume_YAXH_Z = 0u;
uint32_t SFERA_IMPORT_Sound_SI_StreamCreateFile_YAKPBDK_Z = 0u;
uint32_t SFERA_IMPORT_Sound_SI_StreamFree_YAXK_Z = 0u;
uint32_t SFERA_IMPORT_Sound_SI_GetHardwareMixing_YA_NXZ = 0u;
uint32_t SFERA_IMPORT_Sound_CSound_dtor = 0u;
uint32_t SFERA_IMPORT_MSVCR100_initterm = 0u;
uint32_t SFERA_IMPORT_MSVCR100_acmdln = 0u;
uint32_t SFERA_IMPORT_MSVCR100_ismbblead = 0u;
uint32_t SFERA_IMPORT_MSVCR100_XcptFilter = 0u;
uint32_t SFERA_IMPORT_MSVCR100_exit = 0u;
uint32_t SFERA_IMPORT_MSVCR100_cexit = 0u;
uint32_t SFERA_IMPORT_MSVCR100_getmainargs = 0u;
uint32_t SFERA_IMPORT_MSVCR100_amsg_exit = 0u;
uint32_t SFERA_IMPORT_MSVCR100_terminate_YAXXZ = 0u;
uint32_t SFERA_IMPORT_MSVCR100_onexit = 0u;
uint32_t SFERA_IMPORT_MSVCR100_lock = 0u;
uint32_t SFERA_IMPORT_MSVCR100_dllonexit = 0u;
uint32_t SFERA_IMPORT_MSVCR100_initterm_e = 0u;
uint32_t SFERA_IMPORT_MSVCR100_configthreadlocale = 0u;
uint32_t SFERA_IMPORT_MSVCR100_setusermatherr = 0u;
uint32_t SFERA_IMPORT_MSVCR100_commode = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fmode = 0u;
uint32_t SFERA_IMPORT_MSVCR100_set_app_type = 0u;
uint32_t SFERA_IMPORT_MSVCR100_crt_debugger_hook = 0u;
uint32_t SFERA_IMPORT_MSVCR100_type_info_type_info_dtor_internal_method = 0u;
uint32_t SFERA_IMPORT_MSVCR100_invoke_watson = 0u;
uint32_t SFERA_IMPORT_MSVCR100_isalnum = 0u;
uint32_t SFERA_IMPORT_MSVCR100_atoi = 0u;
uint32_t SFERA_IMPORT_MSVCR100_atof = 0u;
uint32_t SFERA_IMPORT_MSVCR100_utime64 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_stat64i32 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_strnicmp = 0u;
uint32_t SFERA_IMPORT_MSVCR100_controlfp_s = 0u;
uint32_t SFERA_IMPORT_MSVCR100_toupper = 0u;
uint32_t SFERA_IMPORT_MSVCR100_unlock = 0u;
uint32_t SFERA_IMPORT_MSVCR100_printf = 0u;
uint32_t SFERA_IMPORT_MSVCR100_calloc = 0u;
uint32_t SFERA_IMPORT_MSVCR100_isdigit = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fsetpos = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fseeki64 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_CIasin = 0u;
uint32_t SFERA_IMPORT_MSVCR100_isalpha = 0u;
uint32_t SFERA_IMPORT_MSVCR100_unlink = 0u;
uint32_t SFERA_IMPORT_MSVCR100_execl = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fflush = 0u;
uint32_t SFERA_IMPORT_MSVCR100_floor = 0u;
uint32_t SFERA_IMPORT_MSVCR100_CIatan = 0u;
uint32_t SFERA_IMPORT_MSVCR100_CIacos = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fgetpos = 0u;
uint32_t SFERA_IMPORT_MSVCR100_memcpy_s = 0u;
uint32_t SFERA_IMPORT_MSVCR100_setvbuf = 0u;
uint32_t SFERA_IMPORT_MSVCR100_unlock_file = 0u;
uint32_t SFERA_IMPORT_MSVCR100_lock_file = 0u;
uint32_t SFERA_IMPORT_MSVCR100_ungetc = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fputc = 0u;
uint32_t SFERA_IMPORT_MSVCR100_bad_cast_ctor = 0u;
uint32_t SFERA_IMPORT_MSVCR100_bad_cast_dtor = 0u;
uint32_t SFERA_IMPORT_MSVCR100_bad_cast_ctor_272 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_strtok = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fgetc = 0u;
uint32_t SFERA_IMPORT_MSVCR100_feof = 0u;
uint32_t SFERA_IMPORT_MSVCR100_CItan = 0u;
uint32_t SFERA_IMPORT_MSVCR100_spawnl = 0u;
uint32_t SFERA_IMPORT_MSVCR100_mkdir = 0u;
uint32_t SFERA_IMPORT_MSVCR100_getenv = 0u;
uint32_t SFERA_IMPORT_MSVCR100_atoi64 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_rename = 0u;
uint32_t SFERA_IMPORT_MSVCR100_chsize = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fstat64i32 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_locking = 0u;
uint32_t SFERA_IMPORT_MSVCR100_sopen_YAHPBDHHH_Z = 0u;
uint32_t SFERA_IMPORT_MSVCR100_vscprintf = 0u;
uint32_t SFERA_IMPORT_MSVCR100_vsnprintf = 0u;
uint32_t SFERA_IMPORT_MSVCR100_exit_288 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_msize = 0u;
uint32_t SFERA_IMPORT_MSVCR100_strtime = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fputs = 0u;
uint32_t SFERA_IMPORT_MSVCR100_strrchr = 0u;
uint32_t SFERA_IMPORT_MSVCR100_futime64 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_mktime64 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_difftime64 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_CIexp = 0u;
uint32_t SFERA_IMPORT_MSVCR100_CIatan2 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_strstr = 0u;
uint32_t SFERA_IMPORT_MSVCR100_vswprintf = 0u;
uint32_t SFERA_IMPORT_MSVCR100_memchr = 0u;
uint32_t SFERA_IMPORT_MSVCR100_access = 0u;
uint32_t SFERA_IMPORT_MSVCR100_strerror = 0u;
uint32_t SFERA_IMPORT_MSVCR100_remove = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fread = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fwrite = 0u;
uint32_t SFERA_IMPORT_MSVCR100_asctime = 0u;
uint32_t SFERA_IMPORT_MSVCR100_vsprintf = 0u;
uint32_t SFERA_IMPORT_MSVCR100_stricmp = 0u;
uint32_t SFERA_IMPORT_MSVCR100_purecall = 0u;
uint32_t SFERA_IMPORT_MSVCR100_close = 0u;
uint32_t SFERA_IMPORT_MSVCR100_read = 0u;
uint32_t SFERA_IMPORT_MSVCR100_open_YAHPBDHH_Z = 0u;
uint32_t SFERA_IMPORT_MSVCR100_write = 0u;
uint32_t SFERA_IMPORT_MSVCR100_lseek = 0u;
uint32_t SFERA_IMPORT_MSVCR100_memcpy = 0u;
uint32_t SFERA_IMPORT_MSVCR100_memset = 0u;
uint32_t SFERA_IMPORT_MSVCR100_sprintf = 0u;
uint32_t SFERA_IMPORT_MSVCR100_chmod = 0u;
uint32_t SFERA_IMPORT_MSVCR100_sscanf = 0u;
uint32_t SFERA_IMPORT_MSVCR100_exception_ctor = 0u;
uint32_t SFERA_IMPORT_MSVCR100_exception_what = 0u;
uint32_t SFERA_IMPORT_MSVCR100_exception_dtor = 0u;
uint32_t SFERA_IMPORT_MSVCR100_memmove = 0u;
uint32_t SFERA_IMPORT_MSVCR100_exception_ctor_325 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_ldiv = 0u;
uint32_t SFERA_IMPORT_MSVCR100_vfprintf = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fprintf = 0u;
uint32_t SFERA_IMPORT_MSVCR100_ftell = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fseek = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fclose = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fopen = 0u;
uint32_t SFERA_IMPORT_MSVCR100_snprintf = 0u;
uint32_t SFERA_IMPORT_MSVCR100_rand = 0u;
uint32_t SFERA_IMPORT_MSVCR100_errno = 0u;
uint32_t SFERA_IMPORT_MSVCR100_CIsqrt = 0u;
uint32_t SFERA_IMPORT_MSVCR100_CIcos = 0u;
uint32_t SFERA_IMPORT_MSVCR100_CIsin = 0u;
uint32_t SFERA_IMPORT_MSVCR100_CIpow = 0u;
uint32_t SFERA_IMPORT_MSVCR100_findclose = 0u;
uint32_t SFERA_IMPORT_MSVCR100_findnext64i32 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_findfirst64i32 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_localtime64 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_time64 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_strncpy = 0u;
uint32_t SFERA_IMPORT_MSVCR100_strftime = 0u;
uint32_t SFERA_IMPORT_MSVCR100_strchr = 0u;
uint32_t SFERA_IMPORT_MSVCR100_filelength = 0u;
uint32_t SFERA_IMPORT_MSVCR100_malloc = 0u;
uint32_t SFERA_IMPORT_MSVCR100_free = 0u;
uint32_t SFERA_IMPORT_MSVCR100_tolower = 0u;
uint32_t SFERA_IMPORT_MSVCR100_strncmp = 0u;
uint32_t SFERA_IMPORT_MSVCR100_qsort = 0u;
uint32_t SFERA_IMPORT_MSVCR100_realloc = 0u;
uint32_t SFERA_IMPORT_MSVCR100_srand = 0u;
uint32_t SFERA_IMPORT_MSVCR100_fgets = 0u;
uint32_t SFERA_IMPORT_MSVCP100_6_basic_ostream_DU_char_traits_D_std_std_QAEAAV01_I_Z = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sgetc = 0u;
uint32_t SFERA_IMPORT_MSVCP100_std_BADOFF = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_imbue = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sync = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_dtor = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_ios_dtor = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_ctor = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_ios_vftable = 0u;
uint32_t SFERA_IMPORT_MSVCP100_ios_base_vftable = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sbumpc = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_snextc = 0u;
uint32_t SFERA_IMPORT_MSVCP100_codecvt_unshift = 0u;
uint32_t SFERA_IMPORT_MSVCP100_codecvt_in = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_setg = 0u;
uint32_t SFERA_IMPORT_MSVCP100_codecvt_out = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_ios_clear = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sputc = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sputn = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_ios_setstate = 0u;
uint32_t SFERA_IMPORT_MSVCP100_std_uncaught_exception = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_Osfx = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_flush = 0u;
uint32_t SFERA_IMPORT_MSVCP100_std_Fiopen = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_getloc = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_xsputn = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_xsgetn = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_showmanyc = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_ctor = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_dtor = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_istream_Ipfx = 0u;
uint32_t SFERA_IMPORT_MSVCP100_Lockit_ctor = 0u;
uint32_t SFERA_IMPORT_MSVCP100_codecvt_id = 0u;
uint32_t SFERA_IMPORT_MSVCP100_Lockit_dtor = 0u;
uint32_t SFERA_IMPORT_MSVCP100_id_Id_cnt = 0u;
uint32_t SFERA_IMPORT_MSVCP100_codecvt_Getcat = 0u;
uint32_t SFERA_IMPORT_MSVCP100_facet_Incref = 0u;
uint32_t SFERA_IMPORT_MSVCP100_codecvt_base_always_noconv = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_Init = 0u;
uint32_t SFERA_IMPORT_MSVCP100_locale_Getgloballocale = 0u;
uint32_t SFERA_IMPORT_MSVCP100_facet_Decref = 0u;
uint32_t SFERA_IMPORT_MSVCP100_Container_base12_dtor = 0u;
uint32_t SFERA_IMPORT_MSVCP100_std_Xlength_error = 0u;
uint32_t SFERA_IMPORT_MSVCP100_std_Xout_of_range = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_Pninc = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_setbuf = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_uflow = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_Unlock = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_Lock = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_istream_vftable = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_istream_ctor = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_istream_dtor = 0u;
uint32_t SFERA_IMPORT_MSVCP100_ios_base_Ios_base_dtor = 0u;
uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_vftable = 0u;

/* Static control-flow tables are resolved into direct C switches in lifted_functions_*.c. */

uint8_t* g_sfera_data_compat_base = nullptr;
uint8_t* g_sfera_data_semantic_page_alias[SFERA_DATA_PAGE_COUNT] = {};
}

#undef SFERA_STORAGE_ALIGN

/* ===== Semantic virtual dispatch ===== */
/* Source vptr values are class-identity tokens; no .rdata storage is materialized. */
namespace {
uint32_t sfera_window_virtual_rva(uint32_t slot) {
    switch (slot) {
    case 0u: return UINT32_C(0x000D47B0);
    case 1u: return UINT32_C(0x000D5510);
    case 2u: return UINT32_C(0x000D2DD0);
    case 3u: return UINT32_C(0x000D19E0);
    case 4u: return UINT32_C(0x000D25E0);
    case 5u: return UINT32_C(0x000D28B0);
    case 6u: return UINT32_C(0x000D2A40);
    case 7u: return UINT32_C(0x000D2B80);
    case 8u: return UINT32_C(0x000D2AE0);
    case 9u: return UINT32_C(0x000D1AC0);
    case 10u: return UINT32_C(0x000D1B00);
    case 11u: return UINT32_C(0x000A13C0);
    default: return 0u;
    }
}
uint32_t sfera_virtual_override_rva(uint32_t class_id, uint32_t slot) {
    switch (class_id) {
    case 0u: /* .?AVBloodEffListener@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0001A090);
        case 1u: return UINT32_C(0x0001A070);
        case 2u: return UINT32_C(0x0001A9F0);
        default: return 0u;
        }
    case 1u: /* .?AVIEffectManager@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000EEB22);
        case 1u: return UINT32_C(0x000EEB22);
        case 2u: return UINT32_C(0x0002B3D0);
        case 3u: return UINT32_C(0x000EEB22);
        case 4u: return UINT32_C(0x000EEB22);
        case 5u: return UINT32_C(0x000EEB22);
        case 6u: return UINT32_C(0x000EEB22);
        case 7u: return UINT32_C(0x000EEB22);
        case 8u: return UINT32_C(0x0002B7D0);
        case 9u: return UINT32_C(0x00025F60);
        case 10u: return UINT32_C(0x00025F90);
        case 11u: return UINT32_C(0x00027590);
        default: return 0u;
        }
    case 2u: /* .?AVCScriptedEffect@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000294E0);
        case 1u: return UINT32_C(0x00026640);
        case 2u: return UINT32_C(0x00029280);
        case 3u: return UINT32_C(0x000266B0);
        case 4u: return UINT32_C(0x00027750);
        case 5u: return UINT32_C(0x000266D0);
        case 6u: return UINT32_C(0x000278E0);
        case 7u: return UINT32_C(0x0002B3D0);
        case 8u: return UINT32_C(0x0002B7D0);
        case 9u: return UINT32_C(0x000276A0);
        case 10u: return UINT32_C(0x000261A0);
        case 11u: return UINT32_C(0x00029A10);
        default: return 0u;
        }
    case 3u: /* .?AVCSpiralEffect@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0002B800);
        case 1u: return UINT32_C(0x0002B3D0);
        case 2u: return UINT32_C(0x0002B3D0);
        case 3u: return UINT32_C(0x0002B710);
        case 4u: return UINT32_C(0x0002B0A0);
        case 5u: return UINT32_C(0x0002B7D0);
        case 6u: return UINT32_C(0x0002B0B0);
        case 7u: return UINT32_C(0x0002B130);
        case 8u: return UINT32_C(0x0002B7D0);
        case 9u: return UINT32_C(0x00025F60);
        case 10u: return UINT32_C(0x00025F90);
        case 11u: return UINT32_C(0x0002B7E0);
        default: return 0u;
        }
    case 4u: /* .?AVCMolEffect@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0002BAD0);
        case 1u: return UINT32_C(0x0002B200);
        case 2u: return UINT32_C(0x0002B3D0);
        case 3u: return UINT32_C(0x0002B710);
        case 4u: return UINT32_C(0x0002B0A0);
        case 5u: return UINT32_C(0x0002B7D0);
        case 6u: return UINT32_C(0x0002B260);
        case 7u: return UINT32_C(0x0002B300);
        case 8u: return UINT32_C(0x0002B7D0);
        case 9u: return UINT32_C(0x00025F60);
        case 10u: return UINT32_C(0x00025F90);
        case 11u: return UINT32_C(0x0002BA50);
        default: return 0u;
        }
    case 5u: /* .?AVCBladeEffect@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0002C050);
        case 1u: return UINT32_C(0x0002B3D0);
        case 2u: return UINT32_C(0x0002B3D0);
        case 3u: return UINT32_C(0x0002B710);
        case 4u: return UINT32_C(0x0002B0A0);
        case 5u: return UINT32_C(0x0002B7D0);
        case 6u: return UINT32_C(0x0002B3E0);
        case 7u: return UINT32_C(0x0002B480);
        case 8u: return UINT32_C(0x0002B7D0);
        case 9u: return UINT32_C(0x00025F60);
        case 10u: return UINT32_C(0x00025F90);
        case 11u: return UINT32_C(0x0002C020);
        default: return 0u;
        }
    case 6u: /* .?AVCGazerLakeEffect@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0002B530);
        case 1u: return UINT32_C(0x0002B3D0);
        case 2u: return UINT32_C(0x0002B3D0);
        case 3u: return UINT32_C(0x0002B710);
        case 4u: return UINT32_C(0x0002B0A0);
        case 5u: return UINT32_C(0x0002B7D0);
        case 6u: return UINT32_C(0x0002C6B0);
        case 7u: return UINT32_C(0x0002B3D0);
        case 8u: return UINT32_C(0x0002B7D0);
        case 9u: return UINT32_C(0x00025F60);
        case 10u: return UINT32_C(0x00025F90);
        case 11u: return UINT32_C(0x0002C690);
        default: return 0u;
        }
    case 7u: /* .?AVCRainEffect@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0002C800);
        case 1u: return UINT32_C(0x0002B3D0);
        case 2u: return UINT32_C(0x0002B3D0);
        case 3u: return UINT32_C(0x0002B710);
        case 4u: return UINT32_C(0x0002B0A0);
        case 5u: return UINT32_C(0x0002B7D0);
        case 6u: return UINT32_C(0x0002CFC0);
        case 7u: return UINT32_C(0x0002B3D0);
        case 8u: return UINT32_C(0x0002B7D0);
        case 9u: return UINT32_C(0x00025F60);
        case 10u: return UINT32_C(0x00025F90);
        case 11u: return UINT32_C(0x0002C770);
        default: return 0u;
        }
    case 8u: /* .?AVIOutputDevice@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000EEB22);
        default: return 0u;
        }
    case 9u: /* .?AVCOutputLogDevice@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0002E3F0);
        default: return 0u;
        }
    case 10u: /* .?AVCSphereError@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0002E430);
        default: return 0u;
        }
    case 11u: /* .?AVGrassMapMngr@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x00030AC0);
        default: return 0u;
        }
    case 12u: /* .?AUHyperTextElement_WordWrap@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0001FBB0);
        default: return 0u;
        }
    case 13u: /* .?AUHyperTextElement@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0001FBB0);
        default: return 0u;
        }
    case 14u: /* .?AUHyperTextElementWithParameters@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0001FBB0);
        default: return 0u;
        }
    case 15u: /* .?AUHyperTextElement_PlainText@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0001FBB0);
        default: return 0u;
        }
    case 16u: /* .?AUHyperTextElement_Link@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0001FBB0);
        default: return 0u;
        }
    case 17u: /* .?AVCItem@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0002B7D0);
        case 1u: return UINT32_C(0x0002B7D0);
        default: return 0u;
        }
    case 18u: /* .?AVCCommonItem@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0002B7D0);
        case 1u: return UINT32_C(0x0002B7D0);
        default: return 0u;
        }
    case 19u: /* .?AV?$CItemList@VCCommonItem@@@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x00047DD0);
        case 1u: return UINT32_C(0x0002B7D0);
        default: return 0u;
        }
    case 20u: /* .?AV?$CBaseManager@V?$CItemList@VCCommonItem@@@@VCCommonItem@@@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x00047DD0);
        case 1u: return UINT32_C(0x0002B7D0);
        case 2u: return UINT32_C(0x0003B130);
        case 3u: return UINT32_C(0x0003B130);
        case 4u: return UINT32_C(0x000219F0);
        default: return 0u;
        }
    case 21u: /* .?AVCLightEffect@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0004B230);
        case 1u: return UINT32_C(0x0002B3D0);
        case 2u: return UINT32_C(0x0002B3D0);
        case 3u: return UINT32_C(0x0004B340);
        case 4u: return UINT32_C(0x0004B380);
        case 5u: return UINT32_C(0x0004B3B0);
        case 6u: return UINT32_C(0x0004B3C0);
        case 7u: return UINT32_C(0x0004B440);
        case 8u: return UINT32_C(0x0002B7D0);
        case 9u: return UINT32_C(0x00025F60);
        case 10u: return UINT32_C(0x00025F90);
        case 11u: return UINT32_C(0x0004B510);
        default: return 0u;
        }
    case 22u: /* .?AVNatureRainListener@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0007FA50);
        case 1u: return UINT32_C(0x0007F7B0);
        case 2u: return UINT32_C(0x0001A080);
        default: return 0u;
        }
    case 23u: /* .?AVLightingListener@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0007F820);
        case 1u: return UINT32_C(0x0007F5A0);
        case 2u: return UINT32_C(0x0007F5C0);
        default: return 0u;
        }
    case 24u: /* .?AVCSoundFX@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000EE7F2);
        case 1u: return UINT32_C(0x000EE7F8);
        case 2u: return UINT32_C(0x000EE7FE);
        default: return 0u;
        }
    case 25u: /* .?AVButtonCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x0009EDE0);
        case 1u: return UINT32_C(0x000A0DB0);
        case 2u: return UINT32_C(0x0009F5A0);
        case 4u: return UINT32_C(0x0009F230);
        case 5u: return UINT32_C(0x0009F7A0);
        case 11u: return UINT32_C(0x0009F1A0);
        default: return sfera_window_virtual_rva(slot);
        }
    case 26u: /* .?AVCheckBox@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000A0ED0);
        case 1u: return UINT32_C(0x000A1740);
        case 2u: return UINT32_C(0x000A12C0);
        case 4u: return UINT32_C(0x000A13E0);
        case 5u: return UINT32_C(0x000A1200);
        case 12u: return UINT32_C(0x000A1350);
        default: return sfera_window_virtual_rva(slot);
        }
    case 27u: /* .?AVCDescriptionWindow@SphereUI@@ */
        switch (slot) {
        case 4u: return UINT32_C(0x000A2280);
        case 11u: return UINT32_C(0x000A1DF0);
        default: return sfera_window_virtual_rva(slot);
        }
    case 28u: /* .?AVEditCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000A3000);
        case 1u: return UINT32_C(0x000A3C50);
        case 2u: return UINT32_C(0x000A3990);
        case 4u: return UINT32_C(0x000A2810);
        case 5u: return UINT32_C(0x000A3400);
        case 11u: return UINT32_C(0x000A2FE0);
        default: return sfera_window_virtual_rva(slot);
        }
    case 29u: /* .?AVFilterListCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000C0D80);
        case 1u: return UINT32_C(0x000A49E0);
        case 2u: return UINT32_C(0x000A48A0);
        case 4u: return UINT32_C(0x000BF210);
        case 5u: return UINT32_C(0x000BEEF0);
        case 11u: return UINT32_C(0x000A44D0);
        default: return sfera_window_virtual_rva(slot);
        }
    case 30u: /* .?AVFontPicker@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000A5800);
        case 1u: return UINT32_C(0x000A5B70);
        case 2u: return UINT32_C(0x000A57A0);
        case 4u: return UINT32_C(0x000A56E0);
        case 5u: return UINT32_C(0x000A5600);
        case 9u: return UINT32_C(0x000A5990);
        case 10u: return UINT32_C(0x000A59F0);
        case 11u: return UINT32_C(0x000A5A50);
        default: return sfera_window_virtual_rva(slot);
        }
    case 31u: /* .?AVHyperTextChatListControl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000A9CC0);
        case 1u: return UINT32_C(0x000AD590);
        case 2u: return UINT32_C(0x000ACE10);
        case 4u: return UINT32_C(0x000AB430);
        case 5u: return UINT32_C(0x000AB7C0);
        case 9u: return UINT32_C(0x000AA0D0);
        case 11u: return UINT32_C(0x000AAB30);
        default: return sfera_window_virtual_rva(slot);
        }
    case 32u: /* .?AVHyperTextCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000AEEA0);
        case 1u: return UINT32_C(0x000B1210);
        case 2u: return UINT32_C(0x000B08B0);
        case 4u: return UINT32_C(0x000AF040);
        case 5u: return UINT32_C(0x000B0590);
        case 11u: return UINT32_C(0x000B0250);
        default: return sfera_window_virtual_rva(slot);
        }
    case 33u: /* .?AV?$basic_filebuf@DU?$char_traits@D@std@@@std@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000B3B70);
        case 1u: return UINT32_C(0x000B15E0);
        case 2u: return UINT32_C(0x000B15F0);
        case 3u: return UINT32_C(0x000B2680);
        case 4u: return UINT32_C(0x000B16D0);
        case 5u: return UINT32_C(0x000EF656);
        case 6u: return UINT32_C(0x000B1600);
        case 7u: return UINT32_C(0x000B28A0);
        case 8u: return UINT32_C(0x000EF65C);
        case 9u: return UINT32_C(0x000EF662);
        case 10u: return UINT32_C(0x000B2EE0);
        case 11u: return UINT32_C(0x000B2FE0);
        case 12u: return UINT32_C(0x000B1760);
        case 13u: return UINT32_C(0x000B1650);
        case 14u: return UINT32_C(0x000B17F0);
        default: return 0u;
        }
    case 34u: /* .?AV?$basic_ofstream@DU?$char_traits@D@std@@@std@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000B4D90);
        default: return 0u;
        }
    case 35u: /* .?AV?$basic_ifstream@DU?$char_traits@D@std@@@std@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000B5780);
        default: return 0u;
        }
    case 36u: /* .?AVHyperTextEditControl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000B6410);
        case 1u: return UINT32_C(0x000B7720);
        case 2u: return UINT32_C(0x000B45C0);
        case 4u: return UINT32_C(0x000B47D0);
        case 5u: return UINT32_C(0x000B6F30);
        case 11u: return UINT32_C(0x000B6F10);
        default: return sfera_window_virtual_rva(slot);
        }
    case 37u: /* .?AVImageCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000B77F0);
        case 1u: return UINT32_C(0x000B80A0);
        case 2u: return UINT32_C(0x000B7DC0);
        case 4u: return UINT32_C(0x000B7970);
        case 5u: return UINT32_C(0x000B7AF0);
        case 6u: return UINT32_C(0x000B7F10);
        case 11u: return UINT32_C(0x000B7F90);
        default: return sfera_window_virtual_rva(slot);
        }
    case 38u: /* .?AV?$basic_stringbuf@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000B9070);
        case 1u: return UINT32_C(0x000EF668);
        case 2u: return UINT32_C(0x000EF66E);
        case 3u: return UINT32_C(0x000B8D40);
        case 4u: return UINT32_C(0x000B8F00);
        case 5u: return UINT32_C(0x000EF656);
        case 6u: return UINT32_C(0x000B8B10);
        case 7u: return UINT32_C(0x000EF674);
        case 8u: return UINT32_C(0x000EF65C);
        case 9u: return UINT32_C(0x000EF662);
        case 10u: return UINT32_C(0x000B8B80);
        case 11u: return UINT32_C(0x000B8F50);
        case 12u: return UINT32_C(0x000EF67A);
        case 13u: return UINT32_C(0x000EF680);
        case 14u: return UINT32_C(0x000EF686);
        default: return 0u;
        }
    case 39u: /* .?AV?$basic_ostringstream@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000B92A0);
        default: return 0u;
        }
    case 40u: /* .?AVListItemCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000BE3E0);
        case 1u: return UINT32_C(0x000BE8C0);
        case 2u: return UINT32_C(0x000BE170);
        case 4u: return UINT32_C(0x000BD000);
        case 5u: return UINT32_C(0x000BD340);
        case 6u: return UINT32_C(0x000BD880);
        case 7u: return UINT32_C(0x000BD970);
        case 8u: return UINT32_C(0x000BDA30);
        case 11u: return UINT32_C(0x000BE3C0);
        default: return sfera_window_virtual_rva(slot);
        }
    case 41u: /* .?AVListCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000C0D80);
        case 1u: return UINT32_C(0x000C04C0);
        case 2u: return UINT32_C(0x000C08C0);
        case 4u: return UINT32_C(0x000BF210);
        case 5u: return UINT32_C(0x000BEEF0);
        case 11u: return UINT32_C(0x000BFE80);
        default: return sfera_window_virtual_rva(slot);
        }
    case 42u: /* .?AVCMenuListControl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000C1B30);
        case 1u: return UINT32_C(0x000C2FB0);
        case 2u: return UINT32_C(0x000C2A40);
        case 4u: return UINT32_C(0x000C1A40);
        case 5u: return UINT32_C(0x000C1660);
        case 11u: return UINT32_C(0x000C2A20);
        default: return sfera_window_virtual_rva(slot);
        }
    case 43u: /* .?AVMiniHelpCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000D0230);
        case 1u: return UINT32_C(0x000C3520);
        case 2u: return UINT32_C(0x000D0130);
        case 4u: return UINT32_C(0x000CFA00);
        case 5u: return UINT32_C(0x000C3060);
        case 11u: return UINT32_C(0x000C3270);
        default: return sfera_window_virtual_rva(slot);
        }
    case 44u: /* .?AVCMinimapControl@SphereUI@@ */
        switch (slot) {
        case 1u: return UINT32_C(0x000C3670);
        case 2u: return UINT32_C(0x000C3710);
        case 4u: return UINT32_C(0x000C3750);
        case 11u: return UINT32_C(0x000C3720);
        default: return sfera_window_virtual_rva(slot);
        }
    case 45u: /* .?AVProgressBar@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000C3FC0);
        case 1u: return UINT32_C(0x000C42B0);
        case 2u: return UINT32_C(0x000C3EB0);
        case 4u: return UINT32_C(0x000C3C00);
        case 5u: return UINT32_C(0x0002B0A0);
        default: return sfera_window_virtual_rva(slot);
        }
    case 46u: /* .?AVRadioButtonCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000A0ED0);
        case 1u: return UINT32_C(0x000C43C0);
        case 2u: return UINT32_C(0x000A12C0);
        case 4u: return UINT32_C(0x000A13E0);
        case 5u: return UINT32_C(0x000A1200);
        case 12u: return UINT32_C(0x000C4360);
        default: return sfera_window_virtual_rva(slot);
        }
    case 47u: /* .?AVRichEditCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000C4480);
        case 1u: return UINT32_C(0x000C5E10);
        case 2u: return UINT32_C(0x000C6370);
        case 4u: return UINT32_C(0x000C4D90);
        case 5u: return UINT32_C(0x000C6810);
        case 11u: return UINT32_C(0x000C5990);
        default: return sfera_window_virtual_rva(slot);
        }
    case 48u: /* .?AVScrollBar@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000C6B80);
        case 1u: return UINT32_C(0x000C7F20);
        case 2u: return UINT32_C(0x000C7AB0);
        case 4u: return UINT32_C(0x000C6EC0);
        case 5u: return UINT32_C(0x000C7120);
        case 11u: return UINT32_C(0x000C7DC0);
        case 12u: return UINT32_C(0x000C7880);
        case 13u: return UINT32_C(0x000C7CF0);
        default: return sfera_window_virtual_rva(slot);
        }
    case 49u: /* .?AVSliderCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000C80C0);
        case 1u: return UINT32_C(0x000C8450);
        case 2u: return UINT32_C(0x000C7AB0);
        case 4u: return UINT32_C(0x000C82E0);
        case 5u: return UINT32_C(0x000C7120);
        case 11u: return UINT32_C(0x000C7DC0);
        case 12u: return UINT32_C(0x000C8270);
        case 13u: return UINT32_C(0x000C8060);
        default: return sfera_window_virtual_rva(slot);
        }
    case 50u: /* .?AVSlotCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000C95F0);
        case 1u: return UINT32_C(0x000C99D0);
        case 2u: return UINT32_C(0x000C9250);
        case 4u: return UINT32_C(0x000C85E0);
        case 5u: return UINT32_C(0x000C8D00);
        case 7u: return UINT32_C(0x000C8570);
        case 11u: return UINT32_C(0x000C9150);
        default: return sfera_window_virtual_rva(slot);
        }
    case 51u: /* .?AVSpinButton@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000CD550);
        case 1u: return UINT32_C(0x000CDE00);
        case 2u: return UINT32_C(0x000CDA30);
        case 4u: return UINT32_C(0x000CD760);
        case 5u: return UINT32_C(0x000CD820);
        case 11u: return UINT32_C(0x000CDA10);
        case 12u: return UINT32_C(0x000CDBF0);
        default: return sfera_window_virtual_rva(slot);
        }
    case 52u: /* .?AVTextCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000CF3E0);
        case 1u: return UINT32_C(0x000CF670);
        case 4u: return UINT32_C(0x000CF4C0);
        case 5u: return UINT32_C(0x000CF310);
        default: return sfera_window_virtual_rva(slot);
        }
    case 53u: /* .?AVToolTipCtrl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000D0230);
        case 1u: return UINT32_C(0x000CFF20);
        case 2u: return UINT32_C(0x000D0130);
        case 4u: return UINT32_C(0x000CFA00);
        case 5u: return UINT32_C(0x000CF7C0);
        case 11u: return UINT32_C(0x000C3270);
        default: return sfera_window_virtual_rva(slot);
        }
    case 54u: /* .?AVCWebBrowserControl@SphereUI@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000D0E10);
        case 1u: return UINT32_C(0x000D0BB0);
        case 2u: return UINT32_C(0x000D0EC0);
        case 4u: return UINT32_C(0x000D0520);
        case 5u: return UINT32_C(0x000D0670);
        case 11u: return UINT32_C(0x000D09D0);
        default: return sfera_window_virtual_rva(slot);
        }
    case 55u: return sfera_window_virtual_rva(slot); /* .?AVWindow@SphereUI@@ */
    case 56u: /* .?AVCCursor@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000EEB22);
        case 1u: return UINT32_C(0x000EEB22);
        case 2u: return UINT32_C(0x000EEB22);
        case 3u: return UINT32_C(0x000EEB22);
        case 4u: return UINT32_C(0x000EEB22);
        case 5u: return UINT32_C(0x000EEB22);
        case 6u: return UINT32_C(0x000EEB22);
        case 7u: return UINT32_C(0x000EEB22);
        case 8u: return UINT32_C(0x000EEB22);
        case 9u: return UINT32_C(0x000EEB22);
        case 10u: return UINT32_C(0x000EEB22);
        case 11u: return UINT32_C(0x000EEB22);
        case 12u: return UINT32_C(0x000EEB22);
        case 13u: return UINT32_C(0x000EEB22);
        default: return 0u;
        }
    case 57u: /* .?AVCHardwareCursor@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000D8340);
        case 1u: return UINT32_C(0x000D7C50);
        case 2u: return UINT32_C(0x000D7CB0);
        case 3u: return UINT32_C(0x000D7CF0);
        case 4u: return UINT32_C(0x000D7D00);
        case 5u: return UINT32_C(0x0002B7D0);
        case 6u: return UINT32_C(0x000D7D10);
        case 7u: return UINT32_C(0x000D7D60);
        case 8u: return UINT32_C(0x000D7DA0);
        case 9u: return UINT32_C(0x000D7DD0);
        case 10u: return UINT32_C(0x000D7E10);
        case 11u: return UINT32_C(0x000D7E30);
        case 12u: return UINT32_C(0x000D7E50);
        case 13u: return UINT32_C(0x000D7E60);
        default: return 0u;
        }
    case 58u: /* .?AVCSoftwareCursor@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000D8340);
        case 1u: return UINT32_C(0x000D7FB0);
        case 2u: return UINT32_C(0x000D8030);
        case 3u: return UINT32_C(0x000D80A0);
        case 4u: return UINT32_C(0x0002B7D0);
        case 5u: return UINT32_C(0x000D8100);
        case 6u: return UINT32_C(0x000D8140);
        case 7u: return UINT32_C(0x000D8160);
        case 8u: return UINT32_C(0x000D8180);
        case 9u: return UINT32_C(0x000D82D0);
        case 10u: return UINT32_C(0x000D82E0);
        case 11u: return UINT32_C(0x000D82F0);
        case 12u: return UINT32_C(0x000D8300);
        case 13u: return UINT32_C(0x000D8310);
        default: return 0u;
        }
    case 59u: /* .?AVUnmanagedResourceVB@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000D9740);
        case 1u: return UINT32_C(0x000D9820);
        default: return 0u;
        }
    case 60u: /* .?AVUnmanagedResourceIB@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000D97B0);
        case 1u: return UINT32_C(0x000D9820);
        default: return 0u;
        }
    case 61u: /* .?AVUnmanagedResourceTexture@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000D9840);
        case 1u: return UINT32_C(0x000D9820);
        default: return 0u;
        }
    case 62u: /* .?AV?$Vect@PAVUnmanagedResourceBase@@@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000DA510);
        default: return 0u;
        }
    case 63u: /* .?AVStdAllocator@@ */
        switch (slot) {
        case 0u: return UINT32_C(0x000ED770);
        case 1u: return UINT32_C(0x000ED790);
        case 2u: return UINT32_C(0x000ED7B0);
        default: return 0u;
        }
    case 64u: /* std::bad_alloc */
        switch (slot) { case 0u: return UINT32_C(0x00001BB0); case 1u: return UINT32_C(0x000EE924); default: return 0u; }
    case 65u: /* _com_error */
        switch (slot) { case 0u: return UINT32_C(0x000EF740); default: return 0u; }
    default: return 0u;
    }
}
int sfera_decode_vptr_token(uint32_t address, uint32_t* class_id, uint32_t* slot) {
    const uint32_t offset = address - SFERA_VPTR_TOKEN_BASE;
    if (offset >= UINT32_C(0x00001080) || (offset & 3u) != 0u) { return 0; }
    const uint32_t decoded_class = offset >> 6u;
    const uint32_t decoded_slot = (offset & 0x3Fu) >> 2u;
    if (sfera_virtual_override_rva(decoded_class, decoded_slot) == 0u) { return 0; }
    if (class_id) { *class_id = decoded_class; }
    if (slot) { *slot = decoded_slot; }
    return 1;
}
}

extern "C" int sfera_bind_native_std_stream_vtables(void) { struct NativeVtableBinding { uint32_t class_id; uint32_t* slots; uint32_t slot_count; }; const NativeVtableBinding bindings[] = {{33u, g_sfera_native_vtable_basic_filebuf, 15u}, {34u, g_sfera_native_vtable_basic_ofstream, 1u}, {35u, g_sfera_native_vtable_basic_ifstream, 1u}, {38u, g_sfera_native_vtable_basic_stringbuf, 15u}, {39u, g_sfera_native_vtable_basic_ostringstream, 1u}}; for (const NativeVtableBinding& binding : bindings) { for (uint32_t slot = 0u; slot < binding.slot_count; ++slot) { const uint32_t rva = sfera_virtual_override_rva(binding.class_id, slot); if (rva == 0u) { return 0; } const uint32_t callback = lift_callback_address_rva(rva); if (callback == 0u) { return 0; } binding.slots[slot] = callback; } } return 1; }
extern "C" int sfera_vtable_token_address(uint32_t address) { return sfera_decode_vptr_token(address, nullptr, nullptr); }
extern "C" int sfera_vtable_try_load32(uint32_t address, uint32_t* value) {
    uint32_t class_id = 0u; uint32_t slot = 0u;
    if (!value || !sfera_decode_vptr_token(address, &class_id, &slot)) { return 0; }
    *value = lift_callback_address_rva(sfera_virtual_override_rva(class_id, slot));
    return 1;
}

namespace {
template <typename T>
static T& sfera_initial_data(uint8_t* storage, uint32_t source_va) { return *reinterpret_cast<T*>(storage + (source_va - SFERA_DATA_SOURCE_BEGIN)); }

static_assert(sizeof(SferaStdAllocator) == 4u, "StdAllocator state layout changed");
static_assert(sizeof(SferaAutoBoundsArray) == 0x38u, "AutoBoundsArray state layout changed");
static_assert(sizeof(SferaFileRuntime) == 0x84u, "file runtime state layout changed");
static_assert(sizeof(SferaBoundCheckArray) == 0x2Cu, "BoundCheckArray state layout changed");
static_assert(offsetof(SferaBoundCheckArray, debug_file) == 0x08u, "BoundCheckArray debug file moved");
static_assert(offsetof(SferaBoundCheckArray, debug_line) == 0x28u, "BoundCheckArray debug line moved");
static_assert(sizeof(SferaEffectListenerMap) == 0x0Cu, "effect-listener map layout changed");
static_assert(offsetof(SferaEffectListenerMap, head) == 0x04u, "effect-listener map head moved");
static_assert(offsetof(SferaEffectListenerMap, size) == 0x08u, "effect-listener map size moved");
static_assert(offsetof(SferaFileRuntime, search_paths) == 0x14u, "file search-path array moved");
static_assert(offsetof(SferaFileRuntime, open_files) == 0x4Cu, "file open-record array moved");
static_assert(sizeof(SferaItemArray) == 28u, "ItemArray state layout changed");
static_assert(offsetof(SferaItemArray, growth_count) == 0x18u, "ItemArray growth field moved");
static_assert(sizeof(SferaServerWall) == 28u, "ServerWall state layout changed");
static_assert(sizeof(SferaNetworkRuntime) == 0x13B8A4u, "NetworkRuntime state layout changed");
static_assert(sizeof(SferaExecutionMonitorRuntime) == 0x64u, "ExecutionMonitor ABI layout changed");
static_assert(offsetof(SferaExecutionMonitorRuntime, stop_requested) == 0x0Cu, "ExecutionMonitor stop flag moved");
static_assert(offsetof(SferaExecutionMonitorRuntime, log_path) == 0x0Eu, "ExecutionMonitor log path moved");
static_assert(offsetof(SferaExecutionMonitorRuntime, critical_section) == 0x44u, "ExecutionMonitor critical section moved");
static_assert(offsetof(SferaExecutionMonitorRuntime, current_value_a) == 0x5Cu, "ExecutionMonitor value A moved");
static_assert(offsetof(SferaExecutionMonitorRuntime, current_value_b) == 0x60u, "ExecutionMonitor value B moved");
static_assert(offsetof(SferaServerWall, effect_handle) == 0x18u, "ServerWall effect handle moved");

static void sfera_initialize_network_defaults(void) {
    memset(&g_sfera_network_runtime, 0, sizeof(g_sfera_network_runtime));
    g_sfera_network_connection_checker = {};
    g_sfera_network_runtime.initialization_result = UINT32_MAX;
    g_sfera_network_runtime.server_port = UINT32_C(25858);
    g_sfera_network_runtime.local_port_candidate = UINT32_C(26860);
    g_sfera_network_runtime.connection_slot = UINT32_MAX;
    g_sfera_network_runtime.pending_slot = UINT32_MAX;
    g_sfera_network_runtime.active_slot = UINT32_MAX;
    g_sfera_network_runtime.shutdown_state = UINT32_MAX;
}

static void sfera_initialize_graphics_defaults(void) {
    g_sfera_graphics_display_depth_bits = UINT32_C(32);
    g_sfera_graphics_runtime = {};
    g_sfera_graphics_runtime.fog_distance = 100.0f;
    g_sfera_graphics_runtime.saved_fog_distance = 50.0f;
    g_sfera_graphics_runtime.lods_enabled = 1u;
    g_sfera_graphics_runtime.hardware_cursor_enabled = 1u;
    g_sfera_graphics_runtime.environment_factor = 0.8500000238418579f;
    g_sfera_graphics_runtime.render_mode_enabled = UINT8_C(1);
    g_sfera_graphics_runtime.base_microtexture_id = UINT32_MAX;
    g_sfera_graphics_runtime.view_parameter = 0.6460000276565552f;
    g_sfera_graphics_runtime.view_scale = 1.0f;
    g_sfera_graphics_runtime.post_effects_enabled = 1u;
    g_sfera_graphics_runtime.rebuild_percent = UINT32_MAX;
    g_sfera_graphics_runtime.runtime_counter = UINT32_C(2000);
    g_sfera_graphics_runtime.texture_runtime_id = UINT32_C(1000000);
}

static void sfera_initialize_interface_defaults(void) {
    g_sfera_interface_runtime = {};
    g_sfera_interface_runtime.primary_gate = UINT8_C(1);
    g_sfera_interface_runtime.secondary_gate = UINT8_C(1);
    g_sfera_interface_runtime.cross_enabled = 1u;
    g_sfera_interface_runtime.sounds_enabled = 1u;
    g_sfera_interface_runtime.description_auto_popup = 1u;
    g_sfera_interface_runtime.invite_messages = 1u;
}

static void sfera_initialize_object_runtime(void) {
    g_sfera_effect_items = {};
    g_sfera_effect_items.growth_count = UINT32_C(6000);
    g_sfera_server_wall = {};
    g_sfera_server_wall.effect_handle = UINT32_MAX;
    g_sfera_sound_effect_items = {};
    g_sfera_sound_effect_items.growth_count = UINT32_C(128);
}

static void sfera_initialize_runtime_sentinels(void) {
    g_sfera_world_objects = {UINT32_MAX, UINT32_MAX, UINT32_MAX};
    g_sfera_grass_runtime = {};
    g_sfera_light_runtime = {};
    g_sfera_landscape_runtime = {};
    g_sfera_collision_runtime = {};
    g_sfera_scene_array_runtime = {};
    g_sfera_weather_runtime = {};
    g_sfera_model_runtime = {};
    g_sfera_warning_log_runtime = {};
    g_sfera_scene_render_runtime = {};
    memset(g_sfera_sky_screen_vertices, 0, sizeof(g_sfera_sky_screen_vertices));
    memset(g_sfera_landscape_screen_vertices, 0, sizeof(g_sfera_landscape_screen_vertices));
    g_sfera_character_index_map = {};
    g_sfera_mesh_partition_indices = {};
    g_sfera_graphics_options_runtime = {};
    g_sfera_view_geometry_runtime = {};
    g_sfera_control_options = {UINT32_MAX};
    g_sfera_sprite_runtime = {UINT32_MAX};
    g_sfera_crash_runtime = {UINT8_C(1)};
    g_sfera_contours_runtime = {};
    g_sfera_dyn_green_runtime = {};
    g_sfera_execution_monitor_runtime = {};
    g_sfera_error_log_runtime = {};
    g_sfera_packet_codec_runtime = {};
    g_sfera_ole_host_abi = {};
    g_sfera_render_buffer_capacities = {30000u, 30000u, 5000u, 5000u};
    g_sfera_effect_manager.deferred_lifecycle = 1u;
    g_sfera_effect_manager.render_cycle = UINT32_C(31);
}

static void sfera_initialize_memory_runtime(void) {
    g_sfera_memory_runtime = {};
    g_sfera_memory_runtime.allocation_source_file = (uint32_t)(uintptr_t)"Unknown";
    g_sfera_memory_runtime.tracker_primary = UINT32_C(1000000000);
    g_sfera_memory_runtime.tracker_floor = UINT32_C(1000000000);
    g_sfera_memory_runtime.tracker_ceiling = UINT32_C(1000000000);
    g_sfera_std_allocator.vptr = SFERA_VPTR_STDALLOCATOR;
}
}

extern "C" void sfera_initialize_data_storage(uint8_t* storage) {
    if (!storage) { return; }
    memset(&g_sfera_mbc_runtime_storage, 0, sizeof(g_sfera_mbc_runtime_storage));
    g_sfera_mbc_runtime = &g_sfera_mbc_runtime_storage;
    memset(&g_sfera_mbc_interpreter_storage, 0, sizeof(g_sfera_mbc_interpreter_storage));
    memset(g_sfera_mbc_module_memory_stats, 0, sizeof(g_sfera_mbc_module_memory_stats));
    memset(storage, 0, UINT32_C(0x00005600));
    memset(g_sfera_array_error_buffer, 0, sizeof(g_sfera_array_error_buffer));
    g_sfera_shared_parser_whitespace = {};
    g_sfera_shared_parser_path_separators = {};
    g_sfera_server_parser_whitespace = {};
    g_sfera_server_parser_path_separators = {};
    g_sfera_menu_parser_whitespace = {};
    g_sfera_menu_parser_path_separators = {};
    g_sfera_menu_list_missing_parameter_message = {};
    g_sfera_menu_not_enough_arguments_message = {};
    g_sfera_menu_sprite_not_found_message = {};
    g_sfera_std_allocator = {};
    g_sfera_file_runtime = {};
    g_sfera_config_parser_runtime = {};
    g_sfera_effect_manager = {};
    g_sfera_effect_manager.last_processed_generation = UINT32_MAX;
    g_sfera_blood_effect_instance = 0u;
    sfera_initialize_network_defaults();
    sfera_initialize_graphics_defaults();
    sfera_initialize_interface_defaults();
    sfera_initialize_object_runtime();
    sfera_initialize_runtime_sentinels();
    sfera_initialize_memory_runtime();
}

/* ===== Recovered zlib 1.1.3 semantic core ===== */
namespace {
struct SferaZStream32 {
    uint32_t next_in;
    uint32_t avail_in;
    uint32_t total_in;
    uint32_t next_out;
    uint32_t avail_out;
    uint32_t total_out;
    uint32_t msg;
    uint32_t state;
    uint32_t zalloc;
    uint32_t zfree;
    uint32_t opaque;
    int32_t data_type;
    uint32_t adler;
    uint32_t reserved;
};

struct SferaDeflateStatePrefix32 {
    uint32_t strm;
    int32_t status;
    uint32_t pending_buf;
    uint32_t pending_buf_size;
    uint32_t pending_out;
    int32_t pending;
    int32_t noheader;
    uint8_t data_type;
    uint8_t method;
    uint16_t reserved_1e;
    int32_t last_flush;
    uint32_t w_size;
    uint32_t w_bits;
    uint32_t w_mask;
    uint32_t window;
    uint32_t window_size;
    uint32_t prev;
    uint32_t head;
    uint32_t ins_h;
    uint32_t hash_size;
    uint32_t hash_bits;
    uint32_t hash_mask;
    uint32_t hash_shift;
    int32_t block_start;
    uint32_t match_length;
    uint32_t prev_match;
    int32_t match_available;
    uint32_t strstart;
    uint32_t match_start;
    uint32_t lookahead;
    uint32_t prev_length;
    uint32_t max_chain_length;
    uint32_t max_lazy_match;
    int32_t level;
    int32_t strategy;
    uint32_t good_match;
    int32_t nice_match;
};

struct SferaDeflateConfig {
    uint16_t good_length;
    uint16_t max_lazy;
    uint16_t nice_length;
    uint16_t max_chain;
};

struct SferaInflateHuft32 {
    uint8_t operation;
    uint8_t bits;
    uint16_t reserved;
    uint32_t base;
};

static_assert(sizeof(SferaZStream32) == 0x38u, "recovered z_stream layout changed");
static_assert(offsetof(SferaDeflateStatePrefix32, window) == 0x30u, "recovered deflate window offset changed");
static_assert(offsetof(SferaDeflateStatePrefix32, strstart) == 0x64u, "recovered deflate strstart offset changed");
static_assert(offsetof(SferaDeflateStatePrefix32, level) == 0x7Cu, "recovered deflate level offset changed");
static_assert(sizeof(SferaDeflateStatePrefix32) == 0x8Cu, "recovered deflate prefix layout changed");
static_assert(sizeof(SferaInflateHuft32) == 8u, "recovered inflate_huft layout changed");

static SferaInflateHuft32 g_sfera_zlib_fixed_literal_pool[512] = {};
static SferaInflateHuft32 g_sfera_zlib_fixed_distance_pool[512] = {};

template <typename T>
static T* sfera_zlib_pointer(uint32_t address) {
    return reinterpret_cast<T*>(static_cast<uintptr_t>(sfera_data_deref_address(address)));
}

static uint8_t* sfera_zlib_bytes(uint32_t address, uint32_t size) {
    return reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(sfera_data_deref_range(address, size)));
}

static SferaDeflateConfig sfera_zlib_deflate_config(int32_t level) {
    switch (level) {
        case 0: return {0u, 0u, 0u, 0u};
        case 1: return {4u, 4u, 8u, 4u};
        case 2: return {4u, 5u, 16u, 8u};
        case 3: return {4u, 6u, 32u, 32u};
        case 4: return {4u, 4u, 16u, 16u};
        case 5: return {8u, 16u, 32u, 32u};
        case 6: return {8u, 16u, 128u, 128u};
        case 7: return {8u, 32u, 128u, 256u};
        case 8: return {32u, 128u, 258u, 1024u};
        case 9: return {32u, 258u, 258u, 4096u};
        default: return {0u, 0u, 0u, 0u};
    }
}
}

extern "C" {
struct SferaCtData32 {
    uint16_t code;
    uint16_t length;
};
static_assert(sizeof(SferaCtData32) == 4u, "zlib ct_data layout mismatch");


struct SferaTreeDesc32 {
    uint32_t dynamic_tree;
    int32_t max_code;
    uint32_t static_descriptor;
};
static_assert(sizeof(SferaTreeDesc32) == 12u, "zlib tree_desc layout mismatch");

struct SferaDeflateState32 {
    SferaDeflateStatePrefix32 prefix;
    SferaCtData32 dynamic_literal_tree[573];
    SferaCtData32 dynamic_distance_tree[61];
    SferaCtData32 bit_length_tree[39];
    SferaTreeDesc32 literal_descriptor;
    SferaTreeDesc32 distance_descriptor;
    SferaTreeDesc32 bit_length_descriptor;
    uint16_t bit_length_counts[16];
    uint32_t heap[573];
    int32_t heap_length;
    int32_t heap_max;
    uint8_t depth[573];
    uint8_t depth_padding[3];
    uint32_t literal_buffer;
    uint32_t literal_buffer_size;
    uint32_t last_literal;
    uint32_t distance_buffer;
    uint32_t optimal_length;
    uint32_t static_length;
    uint32_t matches;
    int32_t last_eob_length;
    uint16_t bit_buffer;
    uint16_t bit_buffer_padding;
    int32_t valid_bits;
};
static_assert(offsetof(SferaDeflateState32, dynamic_literal_tree) == 0x8Cu, "zlib dyn_ltree offset mismatch");
static_assert(offsetof(SferaDeflateState32, dynamic_distance_tree) == 0x980u, "zlib dyn_dtree offset mismatch");
static_assert(offsetof(SferaDeflateState32, bit_length_tree) == 0xA74u, "zlib bl_tree offset mismatch");
static_assert(offsetof(SferaDeflateState32, literal_descriptor) == 0xB10u, "zlib l_desc offset mismatch");
static_assert(offsetof(SferaDeflateState32, bit_length_counts) == 0xB34u, "zlib bl_count offset mismatch");
static_assert(offsetof(SferaDeflateState32, heap) == 0xB54u, "zlib heap offset mismatch");
static_assert(offsetof(SferaDeflateState32, heap_length) == 0x1448u, "zlib heap_len offset mismatch");
static_assert(offsetof(SferaDeflateState32, depth) == 0x1450u, "zlib depth offset mismatch");
static_assert(offsetof(SferaDeflateState32, literal_buffer) == 0x1690u, "zlib l_buf offset mismatch");
static_assert(offsetof(SferaDeflateState32, distance_buffer) == 0x169Cu, "zlib d_buf offset mismatch");
static_assert(offsetof(SferaDeflateState32, bit_buffer) == 0x16B0u, "zlib bi_buf offset mismatch");
static_assert(offsetof(SferaDeflateState32, valid_bits) == 0x16B4u, "zlib bi_valid offset mismatch");
static_assert(sizeof(SferaDeflateState32) == 0x16B8u, "zlib deflate_state size mismatch");

static uint16_t sfera_zlib_reverse_bits(uint32_t value, uint32_t bit_count) {
    uint32_t result = 0u;
    for (uint32_t bit = 0u; bit != bit_count; ++bit) { result = (result << 1u) | ((value >> bit) & 1u); }
    return static_cast<uint16_t>(result);
}

uint32_t sfera_zlib_fixed_literal_length(uint32_t symbol) {
    if (symbol <= 143u) { return 8u; }
    if (symbol <= 255u) { return 9u; }
    if (symbol <= 279u) { return 7u; }
    return symbol <= 287u ? 8u : 0u;
}

uint32_t sfera_zlib_fixed_literal_code(uint32_t symbol) {
    if (symbol <= 143u) { return sfera_zlib_reverse_bits(symbol + 0x30u, 8u); }
    if (symbol <= 255u) { return sfera_zlib_reverse_bits(symbol - 144u + 0x190u, 9u); }
    if (symbol <= 279u) { return sfera_zlib_reverse_bits(symbol - 256u, 7u); }
    if (symbol <= 287u) { return sfera_zlib_reverse_bits(symbol - 280u + 0xC0u, 8u); }
    return 0u;
}

uint32_t sfera_zlib_fixed_distance_code(uint32_t symbol) {
    return symbol < 30u ? sfera_zlib_reverse_bits(symbol, 5u) : 0u;
}

static SferaCtData32 sfera_zlib_tree_entry(uint32_t tree_address, uint32_t symbol, bool distance_tree) {
    if (tree_address != 0u) { return sfera_zlib_pointer<SferaCtData32>(tree_address)[symbol]; }
    SferaCtData32 entry = {};
    entry.code = static_cast<uint16_t>(distance_tree ? sfera_zlib_fixed_distance_code(symbol) : sfera_zlib_fixed_literal_code(symbol));
    entry.length = static_cast<uint16_t>(distance_tree ? 5u : sfera_zlib_fixed_literal_length(symbol));
    return entry;
}

static void sfera_zlib_put_short_le(uint32_t state_address, uint16_t value) {
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    uint8_t* pending = sfera_zlib_bytes(state->pending_buf, state->pending_buf_size);
    pending[state->pending++] = static_cast<uint8_t>(value);
    pending[state->pending++] = static_cast<uint8_t>(value >> 8u);
}

static void sfera_zlib_send_bits(uint32_t state_address, uint32_t value, uint32_t length) {
    uint16_t& bit_buffer = *sfera_zlib_pointer<uint16_t>(state_address + 0x16B0u);
    uint32_t& valid_bits = *sfera_zlib_pointer<uint32_t>(state_address + 0x16B4u);
    if (length == 0u) { return; }
    if (valid_bits > 16u - length) {
        bit_buffer = static_cast<uint16_t>(bit_buffer | static_cast<uint16_t>(value << valid_bits));
        sfera_zlib_put_short_le(state_address, bit_buffer);
        bit_buffer = static_cast<uint16_t>(value >> (16u - valid_bits));
        valid_bits += length - 16u;
    }
    else {
        bit_buffer = static_cast<uint16_t>(bit_buffer | static_cast<uint16_t>(value << valid_bits));
        valid_bits += length;
    }
}

static void sfera_zlib_send_tree_code(uint32_t state_address, uint32_t tree_address, uint32_t symbol, bool distance_tree) {
    const SferaCtData32 entry = sfera_zlib_tree_entry(tree_address, symbol, distance_tree);
    sfera_zlib_send_bits(state_address, entry.code, entry.length);
}


uint32_t sfera_zlib_bit_reverse(uint32_t value, uint32_t bit_count) {
    return sfera_zlib_reverse_bits(value, bit_count);
}

void sfera_zlib_bit_flush(uint32_t state_address) {
    uint16_t& bit_buffer = *sfera_zlib_pointer<uint16_t>(state_address + 0x16B0u);
    uint32_t& valid_bits = *sfera_zlib_pointer<uint32_t>(state_address + 0x16B4u);
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    uint8_t* pending = sfera_zlib_bytes(state->pending_buf, state->pending_buf_size);
    if (valid_bits == 16u) { pending[state->pending++] = static_cast<uint8_t>(bit_buffer); pending[state->pending++] = static_cast<uint8_t>(bit_buffer >> 8u); bit_buffer = 0u; valid_bits = 0u; }
    else if (valid_bits >= 8u) { pending[state->pending++] = static_cast<uint8_t>(bit_buffer); bit_buffer = static_cast<uint16_t>(bit_buffer >> 8u); valid_bits -= 8u; }
}

void sfera_zlib_bit_windup(uint32_t state_address) {
    uint16_t& bit_buffer = *sfera_zlib_pointer<uint16_t>(state_address + 0x16B0u);
    uint32_t& valid_bits = *sfera_zlib_pointer<uint32_t>(state_address + 0x16B4u);
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    uint8_t* pending = sfera_zlib_bytes(state->pending_buf, state->pending_buf_size);
    if (valid_bits > 8u) { pending[state->pending++] = static_cast<uint8_t>(bit_buffer); pending[state->pending++] = static_cast<uint8_t>(bit_buffer >> 8u); }
    else if (valid_bits != 0u) { pending[state->pending++] = static_cast<uint8_t>(bit_buffer); }
    bit_buffer = 0u;
    valid_bits = 0u;
}

void sfera_zlib_copy_stored_block(uint32_t state_address, uint32_t buffer_address, uint32_t length, uint32_t write_header) {
    sfera_zlib_bit_windup(state_address);
    *sfera_zlib_pointer<uint32_t>(state_address + 0x16ACu) = 8u;
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    uint8_t* pending = sfera_zlib_bytes(state->pending_buf, state->pending_buf_size);
    if (write_header != 0u) {
        const uint16_t block_length = static_cast<uint16_t>(length);
        const uint16_t complement = static_cast<uint16_t>(~block_length);
        pending[state->pending++] = static_cast<uint8_t>(block_length);
        pending[state->pending++] = static_cast<uint8_t>(block_length >> 8u);
        pending[state->pending++] = static_cast<uint8_t>(complement);
        pending[state->pending++] = static_cast<uint8_t>(complement >> 8u);
    }
    if (length != 0u) { memcpy(pending + state->pending, sfera_zlib_bytes(buffer_address, length), length); state->pending += static_cast<int32_t>(length); }
}


void sfera_zlib_write_stored_block(uint32_t state_address, uint32_t buffer_address, uint32_t length, uint32_t end_of_file) {
    sfera_zlib_send_bits(state_address, end_of_file & 1u, 3u);
    sfera_zlib_copy_stored_block(state_address, buffer_address, length, 1u);
}

void sfera_zlib_align_static_block(uint32_t state_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    sfera_zlib_send_bits(state_address, 2u, 3u);
    sfera_zlib_send_tree_code(state_address, 0u, 256u, false);
    sfera_zlib_bit_flush(state_address);
    if (1 + state->last_eob_length + 10 - state->valid_bits < 9) {
        sfera_zlib_send_bits(state_address, 2u, 3u);
        sfera_zlib_send_tree_code(state_address, 0u, 256u, false);
        sfera_zlib_bit_flush(state_address);
    }
    state->last_eob_length = 7;
}

void sfera_zlib_set_data_type(uint32_t state_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    uint32_t binary_frequency = 0u;
    uint32_t ascii_frequency = 0u;
    uint32_t symbol = 0u;
    while (symbol < 7u) { binary_frequency += state->dynamic_literal_tree[symbol++].code; }
    while (symbol < 128u) { ascii_frequency += state->dynamic_literal_tree[symbol++].code; }
    while (symbol < 256u) { binary_frequency += state->dynamic_literal_tree[symbol++].code; }
    state->prefix.data_type = static_cast<uint8_t>(binary_frequency > (ascii_frequency >> 2u) ? 0u : 1u);
}



enum class SferaZlibTreeKind : uint32_t { Literal, Distance, BitLength, Unknown };

static SferaZlibTreeKind sfera_zlib_tree_kind(uint32_t state_address, uint32_t descriptor_address) {
    const uint32_t offset = descriptor_address - state_address;
    if (offset == offsetof(SferaDeflateState32, literal_descriptor)) { return SferaZlibTreeKind::Literal; }
    if (offset == offsetof(SferaDeflateState32, distance_descriptor)) { return SferaZlibTreeKind::Distance; }
    if (offset == offsetof(SferaDeflateState32, bit_length_descriptor)) { return SferaZlibTreeKind::BitLength; }
    return SferaZlibTreeKind::Unknown;
}

static uint32_t sfera_zlib_tree_element_count(SferaZlibTreeKind kind) {
    switch (kind) { case SferaZlibTreeKind::Literal: return 286u; case SferaZlibTreeKind::Distance: return 30u; case SferaZlibTreeKind::BitLength: return 19u; default: return 0u; }
}

static uint32_t sfera_zlib_tree_max_length(SferaZlibTreeKind kind) { return kind == SferaZlibTreeKind::BitLength ? 7u : 15u; }

static uint32_t sfera_zlib_tree_extra_bits(SferaZlibTreeKind kind, uint32_t symbol) {
    if (kind == SferaZlibTreeKind::Literal && symbol >= 257u) { const uint32_t code = symbol - 257u; return code >= 8u && code < 28u ? (code - 4u) >> 2u : 0u; }
    if (kind == SferaZlibTreeKind::Distance) { return symbol >= 4u && symbol < 30u ? (symbol >> 1u) - 1u : 0u; }
    if (kind == SferaZlibTreeKind::BitLength) { if (symbol == 16u) { return 2u; } if (symbol == 17u) { return 3u; } if (symbol == 18u) { return 7u; } }
    return 0u;
}

static uint32_t sfera_zlib_static_symbol_length(SferaZlibTreeKind kind, uint32_t symbol) {
    if (kind == SferaZlibTreeKind::Literal) { return sfera_zlib_fixed_literal_length(symbol); }
    if (kind == SferaZlibTreeKind::Distance) { return 5u; }
    return 0u;
}

static bool sfera_zlib_heap_less(const SferaDeflateState32* state, const SferaCtData32* tree, uint32_t left, uint32_t right) {
    return tree[left].code < tree[right].code || (tree[left].code == tree[right].code && state->depth[left] <= state->depth[right]);
}

static void sfera_zlib_pq_down_heap_impl(SferaDeflateState32* state, SferaCtData32* tree, uint32_t heap_index) {
    const uint32_t value = state->heap[heap_index];
    uint32_t child = heap_index << 1u;
    while (child <= static_cast<uint32_t>(state->heap_length)) {
        if (child < static_cast<uint32_t>(state->heap_length) && sfera_zlib_heap_less(state, tree, state->heap[child + 1u], state->heap[child])) { ++child; }
        if (sfera_zlib_heap_less(state, tree, value, state->heap[child])) { break; }
        state->heap[heap_index] = state->heap[child];
        heap_index = child;
        child <<= 1u;
    }
    state->heap[heap_index] = value;
}

static void sfera_zlib_generate_codes_impl(SferaCtData32* tree, int32_t max_code, const uint16_t* bit_counts) {
    uint16_t next_code[16] = {};
    uint32_t code = 0u;
    for (uint32_t bits = 1u; bits <= 15u; ++bits) { code = (code + bit_counts[bits - 1u]) << 1u; next_code[bits] = static_cast<uint16_t>(code); }
    for (int32_t symbol = 0; symbol <= max_code; ++symbol) { const uint32_t length = tree[symbol].length; if (length != 0u) { tree[symbol].code = sfera_zlib_reverse_bits(next_code[length]++, length); } }
}

static void sfera_zlib_generate_bit_lengths_impl(uint32_t state_address, uint32_t descriptor_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    SferaTreeDesc32* descriptor = sfera_zlib_pointer<SferaTreeDesc32>(descriptor_address);
    SferaCtData32* tree = sfera_zlib_pointer<SferaCtData32>(descriptor->dynamic_tree);
    const SferaZlibTreeKind kind = sfera_zlib_tree_kind(state_address, descriptor_address);
    const uint32_t max_length = sfera_zlib_tree_max_length(kind);
    for (uint32_t bits = 0u; bits <= 15u; ++bits) { state->bit_length_counts[bits] = 0u; }
    tree[state->heap[state->heap_max]].length = 0u;
    int32_t overflow = 0;
    for (int32_t heap_index = state->heap_max + 1; heap_index < 573; ++heap_index) {
        const uint32_t symbol = state->heap[heap_index];
        uint32_t bits = static_cast<uint32_t>(tree[tree[symbol].length].length) + 1u;
        if (bits > max_length) { bits = max_length; ++overflow; }
        tree[symbol].length = static_cast<uint16_t>(bits);
        if (symbol > static_cast<uint32_t>(descriptor->max_code)) { continue; }
        ++state->bit_length_counts[bits];
        const uint32_t extra = sfera_zlib_tree_extra_bits(kind, symbol);
        const uint32_t frequency = tree[symbol].code;
        state->optimal_length += frequency * (bits + extra);
        const uint32_t fixed_length = sfera_zlib_static_symbol_length(kind, symbol);
        if (fixed_length != 0u) { state->static_length += frequency * (fixed_length + extra); }
    }
    while (overflow > 0) {
        int32_t bits = static_cast<int32_t>(max_length) - 1;
        while (bits > 0 && state->bit_length_counts[bits] == 0u) { --bits; }
        --state->bit_length_counts[bits];
        state->bit_length_counts[bits + 1] = static_cast<uint16_t>(state->bit_length_counts[bits + 1] + 2u);
        --state->bit_length_counts[max_length];
        overflow -= 2;
    }
    int32_t heap_index = 573;
    for (int32_t bits = static_cast<int32_t>(max_length); bits != 0; --bits) {
        uint32_t remaining = state->bit_length_counts[bits];
        while (remaining != 0u) {
            const uint32_t symbol = state->heap[--heap_index];
            if (symbol > static_cast<uint32_t>(descriptor->max_code)) { continue; }
            if (tree[symbol].length != static_cast<uint32_t>(bits)) { state->optimal_length += static_cast<uint32_t>((static_cast<int32_t>(bits) - static_cast<int32_t>(tree[symbol].length)) * static_cast<int32_t>(tree[symbol].code)); tree[symbol].length = static_cast<uint16_t>(bits); }
            --remaining;
        }
    }
}

void sfera_zlib_pq_down_heap(uint32_t state_address, uint32_t tree_address, uint32_t heap_index) {
    sfera_zlib_pq_down_heap_impl(sfera_zlib_pointer<SferaDeflateState32>(state_address), sfera_zlib_pointer<SferaCtData32>(tree_address), heap_index);
}

void sfera_zlib_generate_bit_lengths(uint32_t state_address, uint32_t descriptor_address) { sfera_zlib_generate_bit_lengths_impl(state_address, descriptor_address); }

void sfera_zlib_generate_codes(uint32_t tree_address, int32_t max_code, uint32_t bit_counts_address) { sfera_zlib_generate_codes_impl(sfera_zlib_pointer<SferaCtData32>(tree_address), max_code, sfera_zlib_pointer<uint16_t>(bit_counts_address)); }

void sfera_zlib_init_block(uint32_t state_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    for (uint32_t symbol = 0u; symbol != 286u; ++symbol) { state->dynamic_literal_tree[symbol].code = 0u; }
    for (uint32_t symbol = 0u; symbol != 30u; ++symbol) { state->dynamic_distance_tree[symbol].code = 0u; }
    for (uint32_t symbol = 0u; symbol != 19u; ++symbol) { state->bit_length_tree[symbol].code = 0u; }
    state->dynamic_literal_tree[256].code = 1u;
    state->optimal_length = 0u;
    state->static_length = 0u;
    state->matches = 0u;
    state->last_literal = 0u;
}

void sfera_zlib_tree_init(uint32_t state_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    state->literal_descriptor.dynamic_tree = state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, dynamic_literal_tree));
    state->literal_descriptor.max_code = -1;
    state->literal_descriptor.static_descriptor = 0u;
    state->distance_descriptor.dynamic_tree = state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, dynamic_distance_tree));
    state->distance_descriptor.max_code = -1;
    state->distance_descriptor.static_descriptor = 0u;
    state->bit_length_descriptor.dynamic_tree = state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, bit_length_tree));
    state->bit_length_descriptor.max_code = -1;
    state->bit_length_descriptor.static_descriptor = 0u;
    state->bit_buffer = 0u;
    state->valid_bits = 0;
    state->last_eob_length = 8;
    sfera_zlib_init_block(state_address);
}

void sfera_zlib_build_tree(uint32_t state_address, uint32_t descriptor_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    SferaTreeDesc32* descriptor = sfera_zlib_pointer<SferaTreeDesc32>(descriptor_address);
    const SferaZlibTreeKind kind = sfera_zlib_tree_kind(state_address, descriptor_address);
    const uint32_t element_count = sfera_zlib_tree_element_count(kind);
    SferaCtData32* tree = sfera_zlib_pointer<SferaCtData32>(descriptor->dynamic_tree);
    int32_t max_code = -1;
    state->heap_length = 0;
    state->heap_max = 573;
    for (uint32_t symbol = 0u; symbol != element_count; ++symbol) {
        if (tree[symbol].code != 0u) { state->heap[++state->heap_length] = symbol; max_code = static_cast<int32_t>(symbol); state->depth[symbol] = 0u; }
        else { tree[symbol].length = 0u; }
    }
    while (state->heap_length < 2) {
        const uint32_t symbol = max_code < 2 ? static_cast<uint32_t>(++max_code) : 0u;
        state->heap[++state->heap_length] = symbol;
        tree[symbol].code = 1u;
        state->depth[symbol] = 0u;
        --state->optimal_length;
        const uint32_t fixed_length = sfera_zlib_static_symbol_length(kind, symbol);
        if (fixed_length != 0u) { state->static_length -= fixed_length; }
    }
    descriptor->max_code = max_code;
    for (int32_t heap_index = state->heap_length / 2; heap_index >= 1; --heap_index) { sfera_zlib_pq_down_heap_impl(state, tree, static_cast<uint32_t>(heap_index)); }
    uint32_t node = element_count;
    do {
        const uint32_t first = state->heap[1];
        state->heap[1] = state->heap[state->heap_length--];
        sfera_zlib_pq_down_heap_impl(state, tree, 1u);
        const uint32_t second = state->heap[1];
        state->heap[--state->heap_max] = first;
        state->heap[--state->heap_max] = second;
        tree[node].code = static_cast<uint16_t>(tree[first].code + tree[second].code);
        state->depth[node] = static_cast<uint8_t>((state->depth[first] > state->depth[second] ? state->depth[first] : state->depth[second]) + 1u);
        tree[first].length = static_cast<uint16_t>(node);
        tree[second].length = static_cast<uint16_t>(node);
        state->heap[1] = node++;
        sfera_zlib_pq_down_heap_impl(state, tree, 1u);
    } while (state->heap_length >= 2);
    state->heap[--state->heap_max] = state->heap[1];
    sfera_zlib_generate_bit_lengths_impl(state_address, descriptor_address);
    sfera_zlib_generate_codes_impl(tree, max_code, state->bit_length_counts);
}

void sfera_zlib_scan_tree(uint32_t state_address, uint32_t tree_address, int32_t max_code) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    SferaCtData32* tree = sfera_zlib_pointer<SferaCtData32>(tree_address);
    int32_t previous_length = -1;
    int32_t next_length = tree[0].length;
    uint32_t count = 0u;
    uint32_t maximum_count = next_length == 0 ? 138u : 7u;
    uint32_t minimum_count = next_length == 0 ? 3u : 4u;
    tree[max_code + 1].length = 0xFFFFu;
    for (int32_t symbol = 0; symbol <= max_code; ++symbol) {
        const int32_t current_length = next_length;
        next_length = tree[symbol + 1].length;
        ++count;
        if (count < maximum_count && current_length == next_length) { continue; }
        if (count < minimum_count) { state->bit_length_tree[current_length].code = static_cast<uint16_t>(state->bit_length_tree[current_length].code + count); }
        else if (current_length != 0) { if (current_length != previous_length) { ++state->bit_length_tree[current_length].code; } ++state->bit_length_tree[16].code; }
        else if (count <= 10u) { ++state->bit_length_tree[17].code; }
        else { ++state->bit_length_tree[18].code; }
        count = 0u;
        previous_length = current_length;
        if (next_length == 0) { maximum_count = 138u; minimum_count = 3u; }
        else if (current_length == next_length) { maximum_count = 6u; minimum_count = 3u; }
        else { maximum_count = 7u; minimum_count = 4u; }
    }
}

void sfera_zlib_send_tree(uint32_t state_address, uint32_t tree_address, int32_t max_code) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    SferaCtData32* tree = sfera_zlib_pointer<SferaCtData32>(tree_address);
    const uint32_t bit_tree_address = state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, bit_length_tree));
    int32_t previous_length = -1;
    int32_t next_length = tree[0].length;
    uint32_t count = 0u;
    uint32_t maximum_count = next_length == 0 ? 138u : 7u;
    uint32_t minimum_count = next_length == 0 ? 3u : 4u;
    for (int32_t symbol = 0; symbol <= max_code; ++symbol) {
        const int32_t current_length = next_length;
        next_length = tree[symbol + 1].length;
        ++count;
        if (count < maximum_count && current_length == next_length) { continue; }
        if (count < minimum_count) { while (count-- != 0u) { sfera_zlib_send_tree_code(state_address, bit_tree_address, static_cast<uint32_t>(current_length), false); } }
        else if (current_length != 0) {
            if (current_length != previous_length) { sfera_zlib_send_tree_code(state_address, bit_tree_address, static_cast<uint32_t>(current_length), false); --count; }
            sfera_zlib_send_tree_code(state_address, bit_tree_address, 16u, false);
            sfera_zlib_send_bits(state_address, count - 3u, 2u);
        }
        else if (count <= 10u) { sfera_zlib_send_tree_code(state_address, bit_tree_address, 17u, false); sfera_zlib_send_bits(state_address, count - 3u, 3u); }
        else { sfera_zlib_send_tree_code(state_address, bit_tree_address, 18u, false); sfera_zlib_send_bits(state_address, count - 11u, 7u); }
        count = 0u;
        previous_length = current_length;
        if (next_length == 0) { maximum_count = 138u; minimum_count = 3u; }
        else if (current_length == next_length) { maximum_count = 6u; minimum_count = 3u; }
        else { maximum_count = 7u; minimum_count = 4u; }
    }
}

int32_t sfera_zlib_build_bit_length_tree(uint32_t state_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    sfera_zlib_scan_tree(state_address, state->literal_descriptor.dynamic_tree, state->literal_descriptor.max_code);
    sfera_zlib_scan_tree(state_address, state->distance_descriptor.dynamic_tree, state->distance_descriptor.max_code);
    sfera_zlib_build_tree(state_address, state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, bit_length_descriptor)));
    int32_t last_rank = 18;
    while (last_rank >= 3) { const uint32_t rank = static_cast<uint32_t>(last_rank); const uint32_t order = rank == 3u ? 0u : (rank < 3u ? 16u + rank : 8u + ((rank - 4u) & 1u ? -static_cast<int32_t>((rank - 3u) >> 1u) : static_cast<int32_t>((rank - 4u) >> 1u))); if (state->bit_length_tree[order].length != 0u) { break; } --last_rank; }
    state->optimal_length += static_cast<uint32_t>(3 * (last_rank + 1) + 14);
    return last_rank;
}

void sfera_zlib_send_all_trees(uint32_t state_address, uint32_t literal_codes, uint32_t distance_codes, uint32_t bit_length_codes) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    sfera_zlib_send_bits(state_address, literal_codes - 257u, 5u);
    sfera_zlib_send_bits(state_address, distance_codes - 1u, 5u);
    sfera_zlib_send_bits(state_address, bit_length_codes - 4u, 4u);
    for (uint32_t rank = 0u; rank != bit_length_codes; ++rank) { const uint32_t order = rank < 3u ? 16u + rank : (rank == 3u ? 0u : 8u + ((rank - 4u) & 1u ? -static_cast<int32_t>((rank - 3u) >> 1u) : static_cast<int32_t>((rank - 4u) >> 1u))); sfera_zlib_send_bits(state_address, state->bit_length_tree[order].length, 3u); }
    sfera_zlib_send_tree(state_address, state->literal_descriptor.dynamic_tree, static_cast<int32_t>(literal_codes - 1u));
    sfera_zlib_send_tree(state_address, state->distance_descriptor.dynamic_tree, static_cast<int32_t>(distance_codes - 1u));
}

void sfera_zlib_flush_block(uint32_t state_address, uint32_t buffer_address, uint32_t stored_length, uint32_t end_of_file) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    uint32_t optimal_bytes = 0u;
    uint32_t static_bytes = 0u;
    int32_t last_bit_length_rank = 0;
    if (state->prefix.level > 0) {
        if (state->prefix.data_type == 2u) { sfera_zlib_set_data_type(state_address); }
        sfera_zlib_build_tree(state_address, state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, literal_descriptor)));
        sfera_zlib_build_tree(state_address, state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, distance_descriptor)));
        last_bit_length_rank = sfera_zlib_build_bit_length_tree(state_address);
        optimal_bytes = (state->optimal_length + 10u) >> 3u;
        static_bytes = (state->static_length + 10u) >> 3u;
        if (static_bytes <= optimal_bytes) { optimal_bytes = static_bytes; }
    }
    else { optimal_bytes = static_bytes = stored_length + 5u; }
    if (buffer_address != 0u && stored_length + 4u <= optimal_bytes) { sfera_zlib_write_stored_block(state_address, buffer_address, stored_length, end_of_file); }
    else if (static_bytes == optimal_bytes) { sfera_zlib_send_bits(state_address, 2u + (end_of_file & 1u), 3u); sfera_zlib_compress_block(state_address, 0u, 0u); }
    else {
        sfera_zlib_send_bits(state_address, 4u + (end_of_file & 1u), 3u);
        sfera_zlib_send_all_trees(state_address, static_cast<uint32_t>(state->literal_descriptor.max_code + 1), static_cast<uint32_t>(state->distance_descriptor.max_code + 1), static_cast<uint32_t>(last_bit_length_rank + 1));
        sfera_zlib_compress_block(state_address, state->literal_descriptor.dynamic_tree, state->distance_descriptor.dynamic_tree);
    }
    sfera_zlib_init_block(state_address);
    if (end_of_file != 0u) { sfera_zlib_bit_windup(state_address); }
}
void sfera_zlib_compress_block(uint32_t state_address, uint32_t literal_tree_address, uint32_t distance_tree_address) {
    const uint32_t literal_buffer_address = *sfera_zlib_pointer<uint32_t>(state_address + 0x1690u);
    const uint32_t literal_count = *sfera_zlib_pointer<uint32_t>(state_address + 0x1698u);
    const uint32_t distance_buffer_address = *sfera_zlib_pointer<uint32_t>(state_address + 0x169Cu);
    uint8_t* literals = sfera_zlib_pointer<uint8_t>(literal_buffer_address);
    uint16_t* distances = sfera_zlib_pointer<uint16_t>(distance_buffer_address);
    for (uint32_t index = 0u; index != literal_count; ++index) {
        uint32_t distance = distances[index];
        const uint32_t literal_or_length = literals[index];
        if (distance == 0u) { sfera_zlib_send_tree_code(state_address, literal_tree_address, literal_or_length, false); continue; }
        uint32_t length_code = literal_or_length;
        if (literal_or_length >= 255u) { length_code = 28u; } else if (literal_or_length >= 8u) { uint32_t highest_bit = 0u; for (uint32_t value = literal_or_length; value > 1u; value >>= 1u) { ++highest_bit; } const uint32_t extra = highest_bit - 2u; const uint32_t base = 1u << (extra + 2u); length_code = 4u * extra + 4u + ((literal_or_length - base) >> extra); }
        sfera_zlib_send_tree_code(state_address, literal_tree_address, length_code + 257u, false);
        const uint32_t length_extra = length_code >= 8u && length_code < 28u ? (length_code - 4u) >> 2u : 0u;
        if (length_extra != 0u) { const uint32_t group_begin = 4u * length_extra + 4u; const uint32_t base = (1u << (length_extra + 2u)) + ((length_code - group_begin) << length_extra); sfera_zlib_send_bits(state_address, literal_or_length - base, length_extra); }
        --distance;
        uint32_t distance_code = distance;
        if (distance >= 4u) { uint32_t highest_bit = 0u; for (uint32_t value = distance; value > 1u; value >>= 1u) { ++highest_bit; } const uint32_t extra = highest_bit - 1u; distance_code = (highest_bit << 1u) + ((distance >> extra) & 1u); }
        sfera_zlib_send_tree_code(state_address, distance_tree_address, distance_code, true);
        const uint32_t distance_extra = distance_code >= 4u ? (distance_code >> 1u) - 1u : 0u;
        if (distance_extra != 0u) { const uint32_t base = (1u << (distance_extra + 1u)) + ((distance_code & 1u) << distance_extra); sfera_zlib_send_bits(state_address, distance - base, distance_extra); }
    }
    sfera_zlib_send_tree_code(state_address, literal_tree_address, 256u, false);
    *sfera_zlib_pointer<uint32_t>(state_address + 0x16ACu) = sfera_zlib_tree_entry(literal_tree_address, 256u, false).length;
}




static bool sfera_zlib_tally(uint32_t state_address, uint32_t distance, uint32_t literal_or_length) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    uint8_t* literals = sfera_zlib_pointer<uint8_t>(state->literal_buffer);
    uint16_t* distances = sfera_zlib_pointer<uint16_t>(state->distance_buffer);
    const uint32_t index = state->last_literal++;
    distances[index] = static_cast<uint16_t>(distance);
    literals[index] = static_cast<uint8_t>(literal_or_length);
    if (distance == 0u) { ++state->dynamic_literal_tree[literal_or_length].code; }
    else {
        ++state->matches;
        const uint32_t normalized_distance = distance - 1u;
        uint32_t distance_code = normalized_distance;
        if (normalized_distance >= 4u) { uint32_t highest_bit = 0u; for (uint32_t value = normalized_distance; value > 1u; value >>= 1u) { ++highest_bit; } distance_code = (highest_bit << 1u) + ((normalized_distance >> (highest_bit - 1u)) & 1u); }
        uint32_t length_code = literal_or_length;
        if (literal_or_length >= 255u) { length_code = 28u; } else if (literal_or_length >= 8u) { uint32_t highest_bit = 0u; for (uint32_t value = literal_or_length; value > 1u; value >>= 1u) { ++highest_bit; } const uint32_t extra = highest_bit - 2u; length_code = 4u * extra + 4u + ((literal_or_length - (1u << (extra + 2u))) >> extra); }
        ++state->dynamic_literal_tree[length_code + 257u].code;
        ++state->dynamic_distance_tree[distance_code].code;
    }
    return state->last_literal == state->literal_buffer_size - 1u;
}

static uint32_t sfera_zlib_insert_string(SferaDeflateState32* state, uint8_t* window, uint16_t* previous, uint16_t* heads) {
    state->prefix.ins_h = ((state->prefix.ins_h << state->prefix.hash_shift) ^ window[state->prefix.strstart + 2u]) & state->prefix.hash_mask;
    const uint32_t hash_head = heads[state->prefix.ins_h];
    previous[state->prefix.strstart & state->prefix.w_mask] = static_cast<uint16_t>(hash_head);
    heads[state->prefix.ins_h] = static_cast<uint16_t>(state->prefix.strstart);
    return hash_head;
}

static int32_t sfera_zlib_flush_current_block(uint32_t state_address, bool end_of_file) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    const uint32_t buffer_address = state->prefix.block_start >= 0 ? state->prefix.window + static_cast<uint32_t>(state->prefix.block_start) : 0u;
    const uint32_t stored_length = static_cast<uint32_t>(static_cast<int64_t>(state->prefix.strstart) - static_cast<int64_t>(state->prefix.block_start));
    sfera_zlib_flush_block(state_address, buffer_address, stored_length, end_of_file ? 1u : 0u);
    state->prefix.block_start = static_cast<int32_t>(state->prefix.strstart);
    sfera_zlib_deflate_flush_pending(state->prefix.strm);
    SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(state->prefix.strm);
    if (stream->avail_out == 0u) { return end_of_file ? 2 : 0; }
    return -1;
}




uint32_t sfera_zlib_deflate_reset(uint32_t stream_address) {
    if (stream_address == 0u) { return static_cast<uint32_t>(-2); }
    SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(stream_address);
    if (stream->state == 0u || stream->zalloc == 0u || stream->zfree == 0u) { return static_cast<uint32_t>(-2); }
    stream->total_in = 0u;
    stream->total_out = 0u;
    stream->msg = 0u;
    stream->data_type = 2;
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(stream->state);
    state->prefix.pending = 0;
    state->prefix.pending_out = state->prefix.pending_buf;
    if (state->prefix.noheader < 0) { state->prefix.noheader = 0; }
    state->prefix.status = state->prefix.noheader != 0 ? 113 : 42;
    stream->adler = 1u;
    state->prefix.last_flush = 0;
    sfera_zlib_tree_init(stream->state);
    sfera_zlib_deflate_lm_init(stream->state);
    return 0u;
}

uint32_t sfera_zlib_deflate(uint32_t stream_address, int32_t flush) {
    if (stream_address == 0u || flush < 0 || flush > 4) { return static_cast<uint32_t>(-2); }
    SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(stream_address);
    if (stream->state == 0u) { return static_cast<uint32_t>(-2); }
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(stream->state);
    if (stream->next_out == 0u || (stream->next_in == 0u && stream->avail_in != 0u) || (state->prefix.status == 666 && flush != 4)) { stream->msg = static_cast<uint32_t>(reinterpret_cast<uintptr_t>("stream error")); return static_cast<uint32_t>(-2); }
    if (stream->avail_out == 0u) { stream->msg = static_cast<uint32_t>(reinterpret_cast<uintptr_t>("buffer error")); return static_cast<uint32_t>(-5); }
    state->prefix.strm = stream_address;
    const int32_t previous_flush = state->prefix.last_flush;
    state->prefix.last_flush = flush;
    if (state->prefix.status == 42) {
        uint32_t header = (static_cast<uint32_t>(state->prefix.method) + ((state->prefix.w_bits - 8u) << 4u)) << 8u;
        uint32_t level_flags = static_cast<uint32_t>((state->prefix.level - 1) >> 1);
        if (level_flags > 3u) { level_flags = 3u; }
        header |= level_flags << 6u;
        if (state->prefix.strstart != 0u) { header |= 0x20u; }
        header += 31u - header % 31u;
        state->prefix.status = 113;
        sfera_zlib_deflate_put_short_msb(stream->state, header);
        if (state->prefix.strstart != 0u) { sfera_zlib_deflate_put_short_msb(stream->state, stream->adler >> 16u); sfera_zlib_deflate_put_short_msb(stream->state, stream->adler & 0xFFFFu); }
        stream->adler = 1u;
    }
    if (state->prefix.pending != 0) {
        sfera_zlib_deflate_flush_pending(stream_address);
        if (stream->avail_out == 0u) { state->prefix.last_flush = -1; return 0u; }
    }
    else if (stream->avail_in == 0u && flush <= previous_flush && flush != 4) { stream->msg = static_cast<uint32_t>(reinterpret_cast<uintptr_t>("buffer error")); return static_cast<uint32_t>(-5); }
    if (state->prefix.status == 666 && stream->avail_in != 0u) { stream->msg = static_cast<uint32_t>(reinterpret_cast<uintptr_t>("buffer error")); return static_cast<uint32_t>(-5); }
    if (stream->avail_in != 0u || state->prefix.lookahead != 0u || (flush != 0 && state->prefix.status != 666)) {
        uint32_t block_state = 0u;
        if (state->prefix.level == 0) { block_state = sfera_zlib_deflate_stored(stream->state, flush); }
        else if (state->prefix.level <= 3) { block_state = sfera_zlib_deflate_fast(stream->state, flush); }
        else { block_state = sfera_zlib_deflate_slow(stream->state, flush); }
        if (block_state == 2u || block_state == 3u) { state->prefix.status = 666; }
        if (block_state == 0u || block_state == 2u) { if (stream->avail_out == 0u) { state->prefix.last_flush = -1; } return 0u; }
        if (block_state == 1u) {
            if (flush == 1) { sfera_zlib_align_static_block(stream->state); }
            else {
                sfera_zlib_write_stored_block(stream->state, 0u, 0u, 0u);
                if (flush == 3) { memset(sfera_zlib_pointer<uint16_t>(state->prefix.head), 0, state->prefix.hash_size * sizeof(uint16_t)); }
            }
            sfera_zlib_deflate_flush_pending(stream_address);
            if (stream->avail_out == 0u) { state->prefix.last_flush = -1; return 0u; }
        }
    }
    if (flush != 4) { return 0u; }
    if (state->prefix.noheader != 0) { return 1u; }
    sfera_zlib_deflate_put_short_msb(stream->state, stream->adler >> 16u);
    sfera_zlib_deflate_put_short_msb(stream->state, stream->adler & 0xFFFFu);
    sfera_zlib_deflate_flush_pending(stream_address);
    state->prefix.noheader = -1;
    return state->prefix.pending != 0 ? 0u : 1u;
}


uint32_t sfera_zlib_deflate_stored(uint32_t state_address, int32_t flush) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    uint32_t max_block_size = 0xFFFFu;
    if (max_block_size > state->prefix.pending_buf_size - 5u) { max_block_size = state->prefix.pending_buf_size - 5u; }
    for (;;) {
        if (state->prefix.lookahead <= 1u) {
            sfera_zlib_deflate_fill_window(state_address);
            if (state->prefix.lookahead == 0u && flush == 0) { return 0u; }
            if (state->prefix.lookahead == 0u) { break; }
        }
        state->prefix.strstart += state->prefix.lookahead;
        state->prefix.lookahead = 0u;
        const uint32_t max_start = static_cast<uint32_t>(state->prefix.block_start) + max_block_size;
        if (state->prefix.strstart == 0u || state->prefix.strstart >= max_start) {
            state->prefix.lookahead = state->prefix.strstart - max_start;
            state->prefix.strstart = max_start;
            const int32_t result = sfera_zlib_flush_current_block(state_address, false);
            if (result >= 0) { return static_cast<uint32_t>(result); }
        }
        if (state->prefix.strstart - static_cast<uint32_t>(state->prefix.block_start) >= state->prefix.w_size - 262u) {
            const int32_t result = sfera_zlib_flush_current_block(state_address, false);
            if (result >= 0) { return static_cast<uint32_t>(result); }
        }
    }
    const bool finishing = flush == 4;
    const int32_t result = sfera_zlib_flush_current_block(state_address, finishing);
    return result >= 0 ? static_cast<uint32_t>(result) : (finishing ? 3u : 1u);
}

uint32_t sfera_zlib_deflate_fast(uint32_t state_address, int32_t flush) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    uint8_t* window = sfera_zlib_pointer<uint8_t>(state->prefix.window);
    uint16_t* previous = sfera_zlib_pointer<uint16_t>(state->prefix.prev);
    uint16_t* heads = sfera_zlib_pointer<uint16_t>(state->prefix.head);
    for (;;) {
        if (state->prefix.lookahead < 262u) {
            sfera_zlib_deflate_fill_window(state_address);
            if (state->prefix.lookahead < 262u && flush == 0) { return 0u; }
            if (state->prefix.lookahead == 0u) { break; }
        }
        uint32_t hash_head = 0u;
        if (state->prefix.lookahead >= 3u) { hash_head = sfera_zlib_insert_string(state, window, previous, heads); }
        if (hash_head != 0u && state->prefix.strstart - hash_head <= state->prefix.w_size - 262u && state->prefix.strategy != 2) { state->prefix.match_length = sfera_zlib_deflate_longest_match(state_address, hash_head); }
        bool flush_block = false;
        if (state->prefix.match_length >= 3u) {
            flush_block = sfera_zlib_tally(state_address, state->prefix.strstart - state->prefix.match_start, state->prefix.match_length - 3u);
            state->prefix.lookahead -= state->prefix.match_length;
            if (state->prefix.match_length <= state->prefix.max_lazy_match && state->prefix.lookahead >= 3u) {
                --state->prefix.match_length;
                do { ++state->prefix.strstart; hash_head = sfera_zlib_insert_string(state, window, previous, heads); } while (--state->prefix.match_length != 0u);
                ++state->prefix.strstart;
            }
            else {
                state->prefix.strstart += state->prefix.match_length;
                state->prefix.match_length = 0u;
                state->prefix.ins_h = window[state->prefix.strstart];
                state->prefix.ins_h = ((state->prefix.ins_h << state->prefix.hash_shift) ^ window[state->prefix.strstart + 1u]) & state->prefix.hash_mask;
            }
        }
        else {
            flush_block = sfera_zlib_tally(state_address, 0u, window[state->prefix.strstart]);
            --state->prefix.lookahead;
            ++state->prefix.strstart;
        }
        if (flush_block) { const int32_t result = sfera_zlib_flush_current_block(state_address, false); if (result >= 0) { return static_cast<uint32_t>(result); } }
    }
    const bool finishing = flush == 4;
    const int32_t result = sfera_zlib_flush_current_block(state_address, finishing);
    return result >= 0 ? static_cast<uint32_t>(result) : (finishing ? 3u : 1u);
}

uint32_t sfera_zlib_deflate_slow(uint32_t state_address, int32_t flush) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    uint8_t* window = sfera_zlib_pointer<uint8_t>(state->prefix.window);
    uint16_t* previous = sfera_zlib_pointer<uint16_t>(state->prefix.prev);
    uint16_t* heads = sfera_zlib_pointer<uint16_t>(state->prefix.head);
    for (;;) {
        if (state->prefix.lookahead < 262u) {
            sfera_zlib_deflate_fill_window(state_address);
            if (state->prefix.lookahead < 262u && flush == 0) { return 0u; }
            if (state->prefix.lookahead == 0u) { break; }
        }
        uint32_t hash_head = 0u;
        if (state->prefix.lookahead >= 3u) { hash_head = sfera_zlib_insert_string(state, window, previous, heads); }
        state->prefix.prev_length = state->prefix.match_length;
        state->prefix.prev_match = state->prefix.match_start;
        state->prefix.match_length = 2u;
        if (hash_head != 0u && state->prefix.prev_length < state->prefix.max_lazy_match && state->prefix.strstart - hash_head <= state->prefix.w_size - 262u && state->prefix.strategy != 2) {
            state->prefix.match_length = sfera_zlib_deflate_longest_match(state_address, hash_head);
            if (state->prefix.match_length <= 5u && (state->prefix.strategy == 1 || (state->prefix.match_length == 3u && state->prefix.strstart - state->prefix.match_start > 4096u))) { state->prefix.match_length = 2u; }
        }
        if (state->prefix.prev_length >= 3u && state->prefix.match_length <= state->prefix.prev_length) {
            const uint32_t max_insert = state->prefix.strstart + state->prefix.lookahead - 3u;
            const bool flush_block = sfera_zlib_tally(state_address, state->prefix.strstart - 1u - state->prefix.prev_match, state->prefix.prev_length - 3u);
            state->prefix.lookahead -= state->prefix.prev_length - 1u;
            state->prefix.prev_length -= 2u;
            do { if (++state->prefix.strstart <= max_insert) { hash_head = sfera_zlib_insert_string(state, window, previous, heads); } } while (--state->prefix.prev_length != 0u);
            state->prefix.match_available = 0;
            state->prefix.match_length = 2u;
            ++state->prefix.strstart;
            if (flush_block) { const int32_t result = sfera_zlib_flush_current_block(state_address, false); if (result >= 0) { return static_cast<uint32_t>(result); } }
        }
        else if (state->prefix.match_available != 0) {
            const bool flush_block = sfera_zlib_tally(state_address, 0u, window[state->prefix.strstart - 1u]);
            if (flush_block) { sfera_zlib_flush_current_block(state_address, false); }
            ++state->prefix.strstart;
            --state->prefix.lookahead;
            SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(state->prefix.strm);
            if (stream->avail_out == 0u) { return 0u; }
        }
        else { state->prefix.match_available = 1; ++state->prefix.strstart; --state->prefix.lookahead; }
    }
    if (state->prefix.match_available != 0) { sfera_zlib_tally(state_address, 0u, window[state->prefix.strstart - 1u]); state->prefix.match_available = 0; }
    const bool finishing = flush == 4;
    const int32_t result = sfera_zlib_flush_current_block(state_address, finishing);
    return result >= 0 ? static_cast<uint32_t>(result) : (finishing ? 3u : 1u);
}
uint32_t sfera_zlib_inflate_fixed(uint32_t literal_bits_address, uint32_t distance_bits_address, uint32_t literal_root_address, uint32_t distance_root_address) {
    uint32_t literal_lengths[288];
    uint32_t literal_work[288];
    uint32_t distance_lengths[30];
    uint32_t distance_work[30];
    for (uint32_t symbol = 0u; symbol < 288u; ++symbol) { literal_lengths[symbol] = symbol < 144u ? 8u : symbol < 256u ? 9u : symbol < 280u ? 7u : 8u; }
    for (uint32_t symbol = 0u; symbol < 30u; ++symbol) { distance_lengths[symbol] = 5u; }
    uint32_t literal_bits = 9u;
    uint32_t distance_bits = 5u;
    uint32_t literal_root = 0u;
    uint32_t distance_root = 0u;
    uint32_t used = 0u;
    uint32_t status = sfera_zlib_huft_build((uint32_t)(uintptr_t)literal_lengths, 288u, 257u, 0u, 0u, (uint32_t)(uintptr_t)&literal_root, (uint32_t)(uintptr_t)&literal_bits, ((uint32_t)(uintptr_t)&g_sfera_zlib_fixed_literal_pool[0]), (uint32_t)(uintptr_t)&used, (uint32_t)(uintptr_t)literal_work);
    if (status != 0u) { return status; }
    used = 0u;
    status = sfera_zlib_huft_build((uint32_t)(uintptr_t)distance_lengths, 30u, 0u, 0u, 0u, (uint32_t)(uintptr_t)&distance_root, (uint32_t)(uintptr_t)&distance_bits, ((uint32_t)(uintptr_t)&g_sfera_zlib_fixed_distance_pool[0]), (uint32_t)(uintptr_t)&used, (uint32_t)(uintptr_t)distance_work);
    const bool canonical_incomplete_distance_tree = status == static_cast<uint32_t>(-5);
    if (status != 0u && !canonical_incomplete_distance_tree) { return status; }
    *sfera_zlib_pointer<uint32_t>(literal_bits_address) = literal_bits;
    *sfera_zlib_pointer<uint32_t>(distance_bits_address) = distance_bits;
    *sfera_zlib_pointer<uint32_t>(literal_root_address) = literal_root;
    *sfera_zlib_pointer<uint32_t>(distance_root_address) = distance_root;
    return 0u;
}

uint32_t sfera_zlib_huft_build(uint32_t lengths_address, uint32_t code_count, uint32_t simple_count, uint32_t base_values_address, uint32_t extra_bits_address, uint32_t root_address, uint32_t root_bits_address, uint32_t pool_address, uint32_t used_address, uint32_t work_address) {
    uint32_t* lengths = sfera_zlib_pointer<uint32_t>(lengths_address);
    uint32_t* root = sfera_zlib_pointer<uint32_t>(root_address);
    uint32_t* root_bits = sfera_zlib_pointer<uint32_t>(root_bits_address);
    SferaInflateHuft32* pool = sfera_zlib_pointer<SferaInflateHuft32>(pool_address);
    uint32_t* used = sfera_zlib_pointer<uint32_t>(used_address);
    uint32_t* values = sfera_zlib_pointer<uint32_t>(work_address);
    uint32_t counts[16] = {};
    for (uint32_t index = 0u; index != code_count; ++index) {
        if (lengths[index] > 15u) { return static_cast<uint32_t>(-3); }
        ++counts[lengths[index]];
    }
    if (counts[0] == code_count) { *root = 0u; *root_bits = 0u; return 0u; }
    uint32_t minimum_bits = 1u;
    while (minimum_bits <= 15u && counts[minimum_bits] == 0u) { ++minimum_bits; }
    uint32_t maximum_bits = 15u;
    while (maximum_bits != 0u && counts[maximum_bits] == 0u) { --maximum_bits; }
    uint32_t table_bits = *root_bits;
    if (table_bits < minimum_bits) { table_bits = minimum_bits; }
    if (table_bits > maximum_bits) { table_bits = maximum_bits; }
    *root_bits = table_bits;
    int32_t unused_patterns = 1 << minimum_bits;
    for (uint32_t bits = minimum_bits; bits < maximum_bits; ++bits) {
        unused_patterns -= static_cast<int32_t>(counts[bits]);
        if (unused_patterns < 0) { return static_cast<uint32_t>(-3); }
        unused_patterns <<= 1;
    }
    unused_patterns -= static_cast<int32_t>(counts[maximum_bits]);
    if (unused_patterns < 0) { return static_cast<uint32_t>(-3); }
    counts[maximum_bits] += static_cast<uint32_t>(unused_patterns);
    uint32_t offsets[16] = {};
    offsets[1] = 0u;
    uint32_t cumulative = 0u;
    for (uint32_t bits = 1u; bits < maximum_bits; ++bits) { cumulative += counts[bits]; offsets[bits + 1u] = cumulative; }
    uint32_t positions[16];
    memcpy(positions, offsets, sizeof(positions));
    for (uint32_t symbol = 0u; symbol != code_count; ++symbol) { const uint32_t bits = lengths[symbol]; if (bits != 0u) { values[positions[bits]++] = symbol; } }
    const uint32_t real_value_count = positions[maximum_bits];
    uint32_t code = 0u;
    uint32_t value_index = 0u;
    SferaInflateHuft32 entry = {};
    int32_t level = -1;
    int32_t bits_before_table = -static_cast<int32_t>(table_bits);
    SferaInflateHuft32* table_stack[15] = {};
    SferaInflateHuft32* current_table = nullptr;
    uint32_t current_entries = 0u;
    offsets[0] = 0u;
    for (uint32_t code_bits = minimum_bits; code_bits <= maximum_bits; ++code_bits) {
        uint32_t remaining = counts[code_bits];
        while (remaining-- != 0u) {
            while (static_cast<int32_t>(code_bits) > bits_before_table + static_cast<int32_t>(table_bits)) {
                ++level;
                bits_before_table += static_cast<int32_t>(table_bits);
                uint32_t candidate_bits = maximum_bits - static_cast<uint32_t>(bits_before_table);
                if (candidate_bits > table_bits) { candidate_bits = table_bits; }
                uint32_t selected_bits = code_bits - static_cast<uint32_t>(bits_before_table);
                uint32_t patterns = 1u << selected_bits;
                if (patterns > remaining + 1u) {
                    patterns -= remaining + 1u;
                    uint32_t probe_bits = code_bits;
                    while (selected_bits < candidate_bits) {
                        ++selected_bits;
                        ++probe_bits;
                        patterns <<= 1u;
                        if (patterns <= counts[probe_bits]) { break; }
                        patterns -= counts[probe_bits];
                    }
                }
                current_entries = 1u << selected_bits;
                if (*used + current_entries > 1440u) { return static_cast<uint32_t>(-4); }
                current_table = pool + *used;
                *used += current_entries;
                table_stack[level] = current_table;
                if (level == 0) { *root = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(current_table)); }
                else {
                    offsets[level] = code;
                    entry.bits = static_cast<uint8_t>(table_bits);
                    entry.operation = static_cast<uint8_t>(selected_bits);
                    const uint32_t parent_index = code >> static_cast<uint32_t>(bits_before_table - static_cast<int32_t>(table_bits));
                    entry.base = static_cast<uint32_t>(current_table - table_stack[level - 1]) - parent_index;
                    table_stack[level - 1][parent_index] = entry;
                }
            }
            entry.bits = static_cast<uint8_t>(code_bits - static_cast<uint32_t>(bits_before_table));
            if (value_index >= real_value_count) { entry.operation = 192u; }
            else {
                const uint32_t symbol = values[value_index++];
                if (symbol < simple_count) { entry.operation = static_cast<uint8_t>(symbol < 256u ? 0u : 96u); entry.base = symbol; }
                else {
                    const uint32_t index = symbol - simple_count;
                    if (base_values_address != 0u && extra_bits_address != 0u) {
                        const uint32_t* base_values = sfera_zlib_pointer<uint32_t>(base_values_address);
                        const uint32_t* extra_bits = sfera_zlib_pointer<uint32_t>(extra_bits_address);
                        entry.operation = static_cast<uint8_t>(extra_bits[index] + 80u);
                        entry.base = base_values[index];
                    } else if (simple_count == 257u && index < 31u) {
                        const uint32_t extra = index < 8u ? 0u : (index < 28u ? (index - 4u) >> 2u : (index == 28u ? 0u : 112u));
                        entry.operation = static_cast<uint8_t>(extra + 80u);
                        if (index < 8u) { entry.base = index + 3u; } else if (index < 28u) { const uint32_t group_begin = 4u * extra + 4u; entry.base = (1u << (extra + 2u)) + ((index - group_begin) << extra) + 3u; } else { entry.base = index == 28u ? 258u : 0u; }
                    } else if (simple_count == 0u && code_count <= 30u && index < 30u) {
                        const uint32_t extra = index >= 4u ? (index >> 1u) - 1u : 0u;
                        entry.operation = static_cast<uint8_t>(extra + 80u);
                        entry.base = (index < 4u ? index : (1u << (extra + 1u)) + ((index & 1u) << extra)) + 1u;
                    } else {
                        return static_cast<uint32_t>(-3);
                    }
                }
            }
            const uint32_t stride = 1u << (code_bits - static_cast<uint32_t>(bits_before_table));
            for (uint32_t index = code >> static_cast<uint32_t>(bits_before_table); index < current_entries; index += stride) { current_table[index] = entry; }
            uint32_t bit = 1u << (code_bits - 1u);
            while ((code & bit) != 0u) { code ^= bit; bit >>= 1u; }
            code ^= bit;
            uint32_t mask = bits_before_table == 0 ? 0u : (1u << static_cast<uint32_t>(bits_before_table)) - 1u;
            while (level > 0 && (code & mask) != offsets[level]) { --level; bits_before_table -= static_cast<int32_t>(table_bits); mask = bits_before_table == 0 ? 0u : (1u << static_cast<uint32_t>(bits_before_table)) - 1u; }
        }
    }
    return unused_patterns != 0 && maximum_bits != 1u ? static_cast<uint32_t>(-5) : 0u;
}

uint32_t sfera_zlib_adler32(uint32_t adler, uint32_t buffer_address, uint32_t length) {
    if (buffer_address == 0u) { return 1u; }
    uint32_t low = adler & 0xFFFFu;
    uint32_t high = (adler >> 16u) & 0xFFFFu;
    uint32_t offset = 0u;
    while (offset != length) {
        uint32_t chunk = length - offset;
        if (chunk > 5552u) { chunk = 5552u; }
        uint8_t* input = sfera_zlib_bytes(buffer_address + offset, chunk);
        for (uint32_t index = 0u; index != chunk; ++index) { low += input[index]; high += low; }
        low %= 65521u;
        high %= 65521u;
        offset += chunk;
    }
    return (high << 16u) | low;
}

void sfera_zlib_deflate_put_short_msb(uint32_t state_address, uint32_t value) {
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    uint8_t* pending = sfera_zlib_bytes(state->pending_buf, state->pending_buf_size);
    pending[state->pending++] = static_cast<uint8_t>(value >> 8u);
    pending[state->pending++] = static_cast<uint8_t>(value);
}

void sfera_zlib_deflate_flush_pending(uint32_t stream_address) {
    SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(stream_address);
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(stream->state);
    uint32_t length = static_cast<uint32_t>(state->pending);
    if (length > stream->avail_out) { length = stream->avail_out; }
    if (length == 0u) { return; }
    memcpy(sfera_zlib_bytes(stream->next_out, length), sfera_zlib_bytes(state->pending_out, length), length);
    stream->next_out += length;
    state->pending_out += length;
    stream->total_out += length;
    stream->avail_out -= length;
    state->pending -= static_cast<int32_t>(length);
    if (state->pending == 0) { state->pending_out = state->pending_buf; }
}

void sfera_zlib_deflate_lm_init(uint32_t state_address) {
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    state->window_size = state->w_size * 2u;
    uint16_t* heads = sfera_zlib_pointer<uint16_t>(state->head);
    memset(heads, 0, state->hash_size * sizeof(uint16_t));
    const SferaDeflateConfig config = sfera_zlib_deflate_config(state->level);
    state->max_lazy_match = config.max_lazy;
    state->good_match = config.good_length;
    state->nice_match = config.nice_length;
    state->max_chain_length = config.max_chain;
    state->strstart = 0u;
    state->block_start = 0;
    state->lookahead = 0u;
    state->match_length = 2u;
    state->prev_length = 2u;
    state->match_available = 0;
    state->ins_h = 0u;
}

uint32_t sfera_zlib_deflate_read_buf(uint32_t stream_address, uint32_t destination_address, uint32_t size) {
    SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(stream_address);
    uint32_t length = stream->avail_in;
    if (length > size) { length = size; }
    if (length == 0u) { return 0u; }
    stream->avail_in -= length;
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(stream->state);
    if (state->noheader == 0) { stream->adler = sfera_zlib_adler32(stream->adler, stream->next_in, length); }
    memcpy(sfera_zlib_bytes(destination_address, length), sfera_zlib_bytes(stream->next_in, length), length);
    stream->next_in += length;
    stream->total_in += length;
    return length;
}

uint32_t sfera_zlib_deflate_longest_match(uint32_t state_address, uint32_t current_match) {
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    uint8_t* window = sfera_zlib_pointer<uint8_t>(state->window);
    uint16_t* previous = sfera_zlib_pointer<uint16_t>(state->prev);
    uint32_t chain_left = state->max_chain_length;
    uint32_t best_length = state->prev_length;
    uint32_t nice_length = state->nice_match > 0 ? static_cast<uint32_t>(state->nice_match) : 0u;
    if (nice_length > state->lookahead) { nice_length = state->lookahead; }
    if (state->prev_length >= state->good_match) { chain_left >>= 2u; }
    const uint32_t max_distance = state->w_size - 262u;
    const uint32_t limit = state->strstart > max_distance ? state->strstart - max_distance : 0u;
    const uint32_t compare_limit = state->lookahead < 258u ? state->lookahead : 258u;
    if (best_length >= compare_limit || chain_left == 0u) { return best_length < state->lookahead ? best_length : state->lookahead; }
    while (true) {
        if (current_match >= state->strstart) { break; }
        if (window[current_match] == window[state->strstart] && window[current_match + 1u] == window[state->strstart + 1u] && window[current_match + best_length] == window[state->strstart + best_length]) {
            uint32_t length = 2u;
            while (length < compare_limit && window[current_match + length] == window[state->strstart + length]) { ++length; }
            if (length > best_length) {
                state->match_start = current_match;
                best_length = length;
                if (best_length >= nice_length) { break; }
            }
        }
        const uint32_t next_match = previous[current_match & state->w_mask];
        if (next_match <= limit) { break; }
        if (--chain_left == 0u) { break; }
        current_match = next_match;
    }
    return best_length < state->lookahead ? best_length : state->lookahead;
}

void sfera_zlib_deflate_fill_window(uint32_t state_address) {
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(state->strm);
    uint8_t* window = sfera_zlib_pointer<uint8_t>(state->window);
    uint16_t* heads = sfera_zlib_pointer<uint16_t>(state->head);
    uint16_t* previous = sfera_zlib_pointer<uint16_t>(state->prev);
    const uint32_t window_size = state->w_size;
    while (true) {
        uint32_t more = state->window_size - state->lookahead - state->strstart;
        if (more == 0u && state->strstart == 0u && state->lookahead == 0u) { more = window_size; }
        else if (more == UINT32_MAX) { --more; }
        else if (state->strstart >= window_size + (window_size - 262u)) {
            memcpy(window, window + window_size, window_size);
            state->match_start -= window_size;
            state->strstart -= window_size;
            state->block_start -= static_cast<int32_t>(window_size);
            for (uint32_t index = 0u; index != state->hash_size; ++index) { const uint32_t value = heads[index]; heads[index] = static_cast<uint16_t>(value >= window_size ? value - window_size : 0u); }
            for (uint32_t index = 0u; index != window_size; ++index) { const uint32_t value = previous[index]; previous[index] = static_cast<uint16_t>(value >= window_size ? value - window_size : 0u); }
            more += window_size;
        }
        if (stream->avail_in == 0u) { return; }
        const uint32_t destination = state->window + state->strstart + state->lookahead;
        state->lookahead += sfera_zlib_deflate_read_buf(state->strm, destination, more);
        if (state->lookahead >= 3u) {
            state->ins_h = window[state->strstart];
            state->ins_h = ((state->ins_h << state->hash_shift) ^ window[state->strstart + 1u]) & state->hash_mask;
        }
        if (state->lookahead >= 262u || stream->avail_in == 0u) { return; }
    }
}
}

/* ===== Manually semanticized lifted routines ===== */
extern "C" {
static uint32_t sfera_config_lookup(uint32_t key_address) {
    const uint32_t text_address = SFERA_STATIC_00916E40_U32;
    const uint32_t text_length = SFERA_STATIC_048F5A98_U32;
    if (text_address == 0u || key_address == 0u) { return 0u; }
    size_t key_length = 0u;
    while (key_length != 4096u && lift_load8(key_address + (uint32_t)key_length) != 0u) { ++key_length; }
    if (key_length == 4096u) { return 0u; }
    const size_t bounded_length = text_length < UINT32_C(0x0025823F) ? (size_t)text_length : (size_t)UINT32_C(0x0025823F);
    const size_t scan_limit = bounded_length + 1u;
    if ((uint64_t)text_address + (uint64_t)scan_limit > UINT64_C(0x100000000)) { return 0u; }
    size_t line = 0u;
    while (line < scan_limit) {
        size_t token_end = line;
        while (token_end < scan_limit) {
            const uint8_t value = lift_load8(text_address + (uint32_t)token_end);
            if (value == (uint8_t)' ' || value == (uint8_t)'\t' || value == (uint8_t)'\r' || value == 0u) { break; }
            ++token_end;
        }
        int matches = token_end - line == key_length;
        for (size_t index = 0u; matches && index != key_length; ++index) {
            matches = lift_load8(text_address + (uint32_t)(line + index)) == lift_load8(key_address + (uint32_t)index);
        }
        if (matches) {
            size_t value = token_end;
            while (value < scan_limit) {
                const uint8_t current = lift_load8(text_address + (uint32_t)value);
                if (current != (uint8_t)' ' && current != (uint8_t)'\t') { break; }
                ++value;
            }
            return value < scan_limit ? text_address + (uint32_t)value : 0u;
        }
        size_t next_line = token_end;
        while (next_line < scan_limit) {
            const uint8_t current = lift_load8(text_address + (uint32_t)next_line);
            if (current == (uint8_t)'\n' || current == 0u) { break; }
            ++next_line;
        }
        if (next_line == scan_limit || lift_load8(text_address + (uint32_t)next_line) == 0u) { return 0u; }
        line = next_line + 1u;
    }
    return 0u;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401600(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    goto label_00001600;
label_00001600: ;
    LIFT_ENTER(UINT32_C(0x00401600));
    const uint32_t key_address = lift_load32(cpu->esp + 4u);
    cpu->eax = sfera_config_lookup(key_address);
    LIFT_RET(4u);
}

void LIFT_CDECL sfera_u32_to_sso_decimal(LiftCpu* cpu) {
    const uint32_t destination = cpu->ecx;
    uint32_t value = lift_load32(cpu->edx);
    uint8_t reversed[16];
    size_t length = 0u;
    do {
        reversed[length++] = (uint8_t)('0' + value % 10u);
        value /= 10u;
    } while (value != 0u);
    for (size_t index = 0u; index != 16u; ++index) {
        const uint8_t output = index < length ? reversed[length - index - 1u] : 0u;
        lift_store8(destination + (uint32_t)index, output);
    }
    lift_store32(destination + 0x10u, (uint32_t)length);
    lift_store32(destination + 0x14u, 15u);
    cpu->eax = destination;
}
}
