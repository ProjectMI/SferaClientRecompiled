#pragma once

#include "lifted_abi.h"
#include "semantic_classes.h"
#include <bit>
#include <cstddef>
#include <cstdint>

inline uint32_t sfera_f32_bits(float value) { return std::bit_cast<uint32_t>(value); }

inline uint32_t g_sfera_msvcp100_vtable_basic_filebuf[15];
inline uint32_t g_sfera_msvcp100_vtable_basic_ofstream[1];
inline uint32_t g_sfera_msvcp100_vtable_basic_ifstream[1];
inline uint32_t g_sfera_msvcp100_vtable_basic_stringbuf[15];
inline uint32_t g_sfera_msvcp100_vtable_basic_ostringstream[1];
inline uint32_t g_sfera_legacy_vtable_bad_alloc[2];
inline uint32_t g_sfera_legacy_vtable_com_error[1];

namespace {
inline uint32_t address32(const void* pointer) { return static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(pointer)); }

const SferaMsvcVbtable2 g_sfera_vbtable_basic_ofstream{0, 0x60};
const SferaMsvcVbtable2 g_sfera_vbtable_basic_ifstream{0, 0x68};
const SferaMsvcVbtable2 g_sfera_vbtable_basic_ostringstream{0, 0x50};

const SferaGuid32 g_sfera_guid_direct_input_key{0x55728220, 0xD33C, 0x11CF, {0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00}};
const SferaGuid32 g_sfera_guid_direct_input_x_axis{0xA36D02E0, 0xC9F3, 0x11CF, {0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00}};
const SferaGuid32 g_sfera_guid_direct_input_y_axis{0xA36D02E1, 0xC9F3, 0x11CF, {0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00}};
const SferaGuid32 g_sfera_guid_direct_input_z_axis{0xA36D02E2, 0xC9F3, 0x11CF, {0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00}};
const SferaGuid32 g_sfera_guid_iid_doc_host_ui_handler{0xBD3F23C0, 0xD43E, 0x11CF, {0x89, 0x3B, 0x00, 0xAA, 0x00, 0xBD, 0xCE, 0x1A}};
const SferaGuid32 g_sfera_guid_iid_ole_client_site{0x00000118, 0x0000, 0x0000, {0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46}};
const SferaGuid32 g_sfera_guid_iid_ole_object{0x00000112, 0x0000, 0x0000, {0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46}};
const SferaGuid32 g_sfera_guid_00000114{0x00000114, 0x0000, 0x0000, {0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46}};
const SferaGuid32 g_sfera_guid_00000113{0x00000113, 0x0000, 0x0000, {0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46}};
const SferaGuid32 g_sfera_guid_00000119{0x00000119, 0x0000, 0x0000, {0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46}};
const SferaGuid32 g_sfera_guid_00000127{0x00000127, 0x0000, 0x0000, {0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46}};
const SferaGuid32 g_sfera_guid_iid_iunknown{0x00000000, 0x0000, 0x0000, {0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46}};
const SferaGuid32 g_sfera_guid_iid_web_browser2{0xD30C1661, 0xCDAF, 0x11D0, {0x8A, 0x3E, 0x00, 0xC0, 0x4F, 0xC9, 0xE2, 0x6E}};
const SferaGuid32 g_sfera_guid_clsid_web_browser{0x8856F961, 0x340A, 0x11D0, {0xA9, 0x6B, 0x00, 0xC0, 0x4F, 0xD7, 0x05, 0xA2}};
const SferaGuid32 g_sfera_guid_332c4425{0x332C4425, 0x26CB, 0x11D0, {0xB4, 0x83, 0x00, 0xC0, 0x4F, 0xD9, 0x01, 0x19}};

const uint32_t kDynamicIndexScratchCount = 3000;
const uint32_t kErrorMessageCapacity = 0x3EC;
const uint32_t kFontLookupClassCount = 5;
const uint32_t kFontLookupGlyphCount = 256;
const uint32_t kLandscapeMapRecordCount = 6400;
const uint32_t kMaterialFilterCharCount = 256;
const uint32_t kMaterialFilterTextCapacity = 0x1000;
const uint32_t kMaterialFilterTokenCapacity = 2048;
const uint32_t kNetworkProbeSampleCount = 20;
const uint32_t kProfileSlotCount = 100;
const uint32_t kRenderBlendLutStorageSize = 0x4001;
const uint32_t kRenderQuantizationTableSize = 3072;
const uint32_t kRenderSampleCount = 120;
const uint32_t kTextureCacheEntryCount = 50;
const uint32_t kTransformBoundsStorageSize = 0xC0;
const uint32_t kUiSortIndexCount = 100;
const uint32_t kWeatherInterpolationOffsetCount = 8;
const uint32_t kStackReserve = 0x00100000;

const uint32_t kMsvcp100VptrBasicFilebuf = address32(g_sfera_msvcp100_vtable_basic_filebuf);
const uint32_t kMsvcp100VptrBasicOfstream = address32(g_sfera_msvcp100_vtable_basic_ofstream);
const uint32_t kMsvcp100VptrBasicIfstream = address32(g_sfera_msvcp100_vtable_basic_ifstream);
const uint32_t kMsvcp100VptrBasicStringbuf = address32(g_sfera_msvcp100_vtable_basic_stringbuf);
const uint32_t kMsvcp100VptrBasicOstringstream = address32(g_sfera_msvcp100_vtable_basic_ostringstream);
const uint32_t kLegacyVptrBadAlloc = address32(g_sfera_legacy_vtable_bad_alloc);
const uint32_t kLegacyVptrComError = address32(g_sfera_legacy_vtable_com_error);
}

int sfera_bind_legacy_cpp_vtables();
uint32_t sfera_cursor_texture_name(uint32_t slot);

inline uint32_t SFERA_IMPORT_WINMM_timeGetTime;
inline uint32_t SFERA_IMPORT_DINPUT8_DirectInput8Create;
inline uint32_t SFERA_IMPORT_COMCTL32_ordinal_17;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_19;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_16;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_151;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_18;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_116;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_3;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_111;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_4;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_52;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_12;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_11;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_9;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_115;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_2;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_10;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_51;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_23;
inline uint32_t SFERA_IMPORT_WS2_32_ordinal_21;
inline uint32_t SFERA_IMPORT_d3dx9_26_D3DXCreateTexture;
inline uint32_t SFERA_IMPORT_d3dx9_26_D3DXGetShaderConstantTable;
inline uint32_t SFERA_IMPORT_d3dx9_26_D3DXMatrixLookAtRH;
inline uint32_t SFERA_IMPORT_d3dx9_26_D3DXMatrixRotationQuaternion;
inline uint32_t SFERA_IMPORT_d3dx9_26_D3DXCreateCubeTextureFromFileInMemory;
inline uint32_t SFERA_IMPORT_d3dx9_26_D3DXMatrixPerspectiveFovRH;
inline uint32_t SFERA_IMPORT_d3dx9_26_D3DXCreateTextureFromFileInMemoryEx;
inline uint32_t SFERA_IMPORT_d3dx9_26_D3DXMatrixMultiply;
inline uint32_t SFERA_IMPORT_d3d9_Direct3DCreate9;
inline uint32_t SFERA_IMPORT_KERNEL32_IsDebuggerPresent;
inline uint32_t SFERA_IMPORT_KERNEL32_IsProcessorFeaturePresent;
inline uint32_t SFERA_IMPORT_KERNEL32_UnhandledExceptionFilter;
inline uint32_t SFERA_IMPORT_KERNEL32_GetStartupInfoW;
inline uint32_t SFERA_IMPORT_KERNEL32_HeapSetInformation;
inline uint32_t SFERA_IMPORT_KERNEL32_InterlockedCompareExchange;
inline uint32_t SFERA_IMPORT_KERNEL32_InterlockedExchange;
inline uint32_t SFERA_IMPORT_KERNEL32_DecodePointer;
inline uint32_t SFERA_IMPORT_KERNEL32_EncodePointer;
inline uint32_t SFERA_IMPORT_KERNEL32_TryEnterCriticalSection;
inline uint32_t SFERA_IMPORT_KERNEL32_LocalFree;
inline uint32_t SFERA_IMPORT_KERNEL32_SetFilePointer;
inline uint32_t SFERA_IMPORT_KERNEL32_SetUnhandledExceptionFilter;
inline uint32_t SFERA_IMPORT_KERNEL32_Sleep;
inline uint32_t SFERA_IMPORT_KERNEL32_GetLocalTime;
inline uint32_t SFERA_IMPORT_KERNEL32_EnterCriticalSection;
inline uint32_t SFERA_IMPORT_KERNEL32_LeaveCriticalSection;
inline uint32_t SFERA_IMPORT_KERNEL32_CloseHandle;
inline uint32_t SFERA_IMPORT_KERNEL32_TerminateThread;
inline uint32_t SFERA_IMPORT_KERNEL32_WaitForSingleObject;
inline uint32_t SFERA_IMPORT_KERNEL32_GetTickCount;
inline uint32_t SFERA_IMPORT_KERNEL32_SetThreadPriority;
inline uint32_t SFERA_IMPORT_KERNEL32_GetLastError;
inline uint32_t SFERA_IMPORT_KERNEL32_CreateThread;
inline uint32_t SFERA_IMPORT_KERNEL32_UnmapViewOfFile;
inline uint32_t SFERA_IMPORT_KERNEL32_GetExitCodeThread;
inline uint32_t SFERA_IMPORT_KERNEL32_GetCurrentProcess;
inline uint32_t SFERA_IMPORT_KERNEL32_GetCurrentThread;
inline uint32_t SFERA_IMPORT_KERNEL32_InitializeCriticalSection;
inline uint32_t SFERA_IMPORT_KERNEL32_DeleteCriticalSection;
inline uint32_t SFERA_IMPORT_KERNEL32_GlobalFree;
inline uint32_t SFERA_IMPORT_KERNEL32_WideCharToMultiByte;
inline uint32_t SFERA_IMPORT_KERNEL32_GlobalAlloc;
inline uint32_t SFERA_IMPORT_KERNEL32_MultiByteToWideChar;
inline uint32_t SFERA_IMPORT_KERNEL32_ExitProcess;
inline uint32_t SFERA_IMPORT_KERNEL32_GetFileSize;
inline uint32_t SFERA_IMPORT_KERNEL32_ReadFile;
inline uint32_t SFERA_IMPORT_KERNEL32_CreateFileA;
inline uint32_t SFERA_IMPORT_KERNEL32_FindClose;
inline uint32_t SFERA_IMPORT_KERNEL32_FindNextFileA;
inline uint32_t SFERA_IMPORT_KERNEL32_FindFirstFileA;
inline uint32_t SFERA_IMPORT_KERNEL32_Process32Next;
inline uint32_t SFERA_IMPORT_KERNEL32_Process32First;
inline uint32_t SFERA_IMPORT_KERNEL32_CreateToolhelp32Snapshot;
inline uint32_t SFERA_IMPORT_KERNEL32_GetVolumeInformationA;
inline uint32_t SFERA_IMPORT_KERNEL32_MapViewOfFile;
inline uint32_t SFERA_IMPORT_KERNEL32_CreateFileMappingA;
inline uint32_t SFERA_IMPORT_KERNEL32_CreateDirectoryA;
inline uint32_t SFERA_IMPORT_KERNEL32_SetThreadAffinityMask;
inline uint32_t SFERA_IMPORT_KERNEL32_GetExitCodeProcess;
inline uint32_t SFERA_IMPORT_KERNEL32_TerminateProcess;
inline uint32_t SFERA_IMPORT_KERNEL32_CreateProcessA;
inline uint32_t SFERA_IMPORT_KERNEL32_GetSystemDirectoryA;
inline uint32_t SFERA_IMPORT_KERNEL32_QueryPerformanceCounter;
inline uint32_t SFERA_IMPORT_KERNEL32_QueryPerformanceFrequency;
inline uint32_t SFERA_IMPORT_KERNEL32_GetModuleHandleA;
inline uint32_t SFERA_IMPORT_KERNEL32_GlobalUnlock;
inline uint32_t SFERA_IMPORT_KERNEL32_GlobalLock;
inline uint32_t SFERA_IMPORT_KERNEL32_WriteFile;
inline uint32_t SFERA_IMPORT_KERNEL32_lstrlenA;
inline uint32_t SFERA_IMPORT_KERNEL32_GetVersionExA;
inline uint32_t SFERA_IMPORT_KERNEL32_GetCurrentThreadId;
inline uint32_t SFERA_IMPORT_KERNEL32_RaiseException;
inline uint32_t SFERA_IMPORT_KERNEL32_OutputDebugStringA;
inline uint32_t SFERA_IMPORT_KERNEL32_FileTimeToDosDateTime;
inline uint32_t SFERA_IMPORT_KERNEL32_FileTimeToLocalFileTime;
inline uint32_t SFERA_IMPORT_KERNEL32_GlobalMemoryStatus;
inline uint32_t SFERA_IMPORT_KERNEL32_GetSystemInfo;
inline uint32_t SFERA_IMPORT_KERNEL32_lstrcpyA;
inline uint32_t SFERA_IMPORT_KERNEL32_GetModuleFileNameA;
inline uint32_t SFERA_IMPORT_KERNEL32_GetSystemTimeAsFileTime;
inline uint32_t SFERA_IMPORT_KERNEL32_lstrcatA;
inline uint32_t SFERA_IMPORT_KERNEL32_GetCurrentProcessId;
inline uint32_t SFERA_IMPORT_KERNEL32_VirtualQuery;
inline uint32_t SFERA_IMPORT_USER32_BringWindowToTop;
inline uint32_t SFERA_IMPORT_USER32_DestroyWindow;
inline uint32_t SFERA_IMPORT_USER32_GetSystemMetrics;
inline uint32_t SFERA_IMPORT_USER32_SendMessageA;
inline uint32_t SFERA_IMPORT_USER32_UpdateWindow;
inline uint32_t SFERA_IMPORT_USER32_InvalidateRect;
inline uint32_t SFERA_IMPORT_USER32_ShowWindow;
inline uint32_t SFERA_IMPORT_USER32_ReleaseDC;
inline uint32_t SFERA_IMPORT_USER32_GetDC;
inline uint32_t SFERA_IMPORT_USER32_GetWindowLongA;
inline uint32_t SFERA_IMPORT_USER32_GetClientRect;
inline uint32_t SFERA_IMPORT_USER32_SetWindowLongA;
inline uint32_t SFERA_IMPORT_USER32_DefWindowProcA;
inline uint32_t SFERA_IMPORT_USER32_MessageBeep;
inline uint32_t SFERA_IMPORT_USER32_TranslateMessage;
inline uint32_t SFERA_IMPORT_USER32_DispatchMessageA;
inline uint32_t SFERA_IMPORT_USER32_PeekMessageA;
inline uint32_t SFERA_IMPORT_USER32_MessageBoxA;
inline uint32_t SFERA_IMPORT_USER32_ShowCursor;
inline uint32_t SFERA_IMPORT_USER32_SetCursorPos;
inline uint32_t SFERA_IMPORT_USER32_GetCursorPos;
inline uint32_t SFERA_IMPORT_USER32_ScreenToClient;
inline uint32_t SFERA_IMPORT_USER32_SetCursor;
inline uint32_t SFERA_IMPORT_USER32_ClipCursor;
inline uint32_t SFERA_IMPORT_USER32_DestroyCursor;
inline uint32_t SFERA_IMPORT_USER32_CreateIconIndirect;
inline uint32_t SFERA_IMPORT_USER32_wsprintfA;
inline uint32_t SFERA_IMPORT_USER32_wvsprintfA;
inline uint32_t SFERA_IMPORT_USER32_CreateDialogParamA;
inline uint32_t SFERA_IMPORT_USER32_SetClassLongA;
inline uint32_t SFERA_IMPORT_USER32_GetDlgCtrlID;
inline uint32_t SFERA_IMPORT_USER32_GetWindowTextA;
inline uint32_t SFERA_IMPORT_USER32_SetWindowTextA;
inline uint32_t SFERA_IMPORT_USER32_EnableWindow;
inline uint32_t SFERA_IMPORT_USER32_IsDialogMessageA;
inline uint32_t SFERA_IMPORT_USER32_GetDlgItem;
inline uint32_t SFERA_IMPORT_USER32_IsClipboardFormatAvailable;
inline uint32_t SFERA_IMPORT_USER32_OpenClipboard;
inline uint32_t SFERA_IMPORT_USER32_GetClipboardData;
inline uint32_t SFERA_IMPORT_USER32_CloseClipboard;
inline uint32_t SFERA_IMPORT_USER32_SetFocus;
inline uint32_t SFERA_IMPORT_USER32_ClientToScreen;
inline uint32_t SFERA_IMPORT_USER32_CallWindowProcA;
inline uint32_t SFERA_IMPORT_USER32_FindWindowA;
inline uint32_t SFERA_IMPORT_USER32_LoadIconA;
inline uint32_t SFERA_IMPORT_USER32_LoadCursorA;
inline uint32_t SFERA_IMPORT_USER32_RegisterClassExA;
inline uint32_t SFERA_IMPORT_USER32_PostQuitMessage;
inline uint32_t SFERA_IMPORT_USER32_SetRect;
inline uint32_t SFERA_IMPORT_USER32_AdjustWindowRect;
inline uint32_t SFERA_IMPORT_USER32_CreateWindowExA;
inline uint32_t SFERA_IMPORT_USER32_UnregisterClassA;
inline uint32_t SFERA_IMPORT_GDI32_GetObjectType;
inline uint32_t SFERA_IMPORT_GDI32_CreateBitmap;
inline uint32_t SFERA_IMPORT_GDI32_GetStockObject;
inline uint32_t SFERA_IMPORT_GDI32_CreateCompatibleDC;
inline uint32_t SFERA_IMPORT_GDI32_CreateCompatibleBitmap;
inline uint32_t SFERA_IMPORT_GDI32_GetDIBits;
inline uint32_t SFERA_IMPORT_GDI32_SelectObject;
inline uint32_t SFERA_IMPORT_GDI32_DeleteDC;
inline uint32_t SFERA_IMPORT_GDI32_SetPixel;
inline uint32_t SFERA_IMPORT_GDI32_DeleteObject;
inline uint32_t SFERA_IMPORT_ADVAPI32_GetUserNameA;
inline uint32_t SFERA_IMPORT_SHELL32_ShellExecuteA;
inline uint32_t SFERA_IMPORT_ole32_CoInitialize;
inline uint32_t SFERA_IMPORT_ole32_CoCreateInstance;
inline uint32_t SFERA_IMPORT_ole32_CoUninitialize;
inline uint32_t SFERA_IMPORT_ole32_OleCreate;
inline uint32_t SFERA_IMPORT_ole32_OleSetContainedObject;
inline uint32_t SFERA_IMPORT_OLEAUT32_ordinal_6;
inline uint32_t SFERA_IMPORT_OLEAUT32_ordinal_9;
inline uint32_t SFERA_IMPORT_OLEAUT32_ordinal_2;
inline uint32_t SFERA_IMPORT_OLEAUT32_ordinal_8;
inline uint32_t SFERA_IMPORT_dbghelp_SymFromAddr;
inline uint32_t SFERA_IMPORT_dbghelp_SymGetModuleBase;
inline uint32_t SFERA_IMPORT_dbghelp_SymFunctionTableAccess;
inline uint32_t SFERA_IMPORT_dbghelp_StackWalk;
inline uint32_t SFERA_IMPORT_dbghelp_SymGetLineFromAddr;
inline uint32_t SFERA_IMPORT_dbghelp_SymSetOptions;
inline uint32_t SFERA_IMPORT_dbghelp_SymInitialize;
inline uint32_t SFERA_IMPORT_dbghelp_MiniDumpWriteDump;
inline uint32_t SFERA_IMPORT_Sound_SI_SetHardwareMixing_YAX_N_Z;
inline uint32_t SFERA_IMPORT_Sound_CSoundListener_GetOrientation;
inline uint32_t SFERA_IMPORT_Sound_CSoundListener_SetPosition;
inline uint32_t SFERA_IMPORT_Sound_CSoundListener_SetVelocity;
inline uint32_t SFERA_IMPORT_Sound_CSoundListener_SetOrientation;
inline uint32_t SFERA_IMPORT_Sound_CSoundInterface_UpdateSettings;
inline uint32_t SFERA_IMPORT_Sound_CSound_SetAllParameters;
inline uint32_t SFERA_IMPORT_Sound_CSound_LoadSound;
inline uint32_t SFERA_IMPORT_Sound_CSound_SetVolume;
inline uint32_t SFERA_IMPORT_Sound_SI_GetStreamVolume_YAHXZ;
inline uint32_t SFERA_IMPORT_Sound_CSound_Rewind;
inline uint32_t SFERA_IMPORT_Sound_CSound_Stop;
inline uint32_t SFERA_IMPORT_Sound_CSound_ctor;
inline uint32_t SFERA_IMPORT_Sound_SI_CreateInterface_YAPAVCSoundInterface_PAUHWND_HKK_Z;
inline uint32_t SFERA_IMPORT_Sound_CSound_SetPosition;
inline uint32_t SFERA_IMPORT_Sound_CSound_GetPlayTimepos;
inline uint32_t SFERA_IMPORT_Sound_CSound_IsSoundPlaying;
inline uint32_t SFERA_IMPORT_Sound_CSound_SetPlayTimepos;
inline uint32_t SFERA_IMPORT_Sound_CSound_Play;
inline uint32_t SFERA_IMPORT_Sound_SI_GetInterface_YAPAVCSoundInterface_XZ;
inline uint32_t SFERA_IMPORT_Sound_CSoundStream_SetDecodeSignal;
inline uint32_t SFERA_IMPORT_Sound_CSoundStream_SeekToTime;
inline uint32_t SFERA_IMPORT_Sound_CSoundStream_SetPlaySignal;
inline uint32_t SFERA_IMPORT_Sound_CSoundStream_Stop;
inline uint32_t SFERA_IMPORT_Sound_CSoundStream_IsStreamPlaying;
inline uint32_t SFERA_IMPORT_Sound_CSoundStream_PlayEx;
inline uint32_t SFERA_IMPORT_Sound_SI_Close_YAXXZ;
inline uint32_t SFERA_IMPORT_Sound_SI_SetLogFile_YAXPBD_Z;
inline uint32_t SFERA_IMPORT_Sound_CSound_SetVelocity;
inline uint32_t SFERA_IMPORT_Sound_SI_SetStreamVolume_YAXH_Z;
inline uint32_t SFERA_IMPORT_Sound_SI_StreamCreateFile_YAKPBDK_Z;
inline uint32_t SFERA_IMPORT_Sound_SI_StreamFree_YAXK_Z;
inline uint32_t SFERA_IMPORT_Sound_SI_GetHardwareMixing_YA_NXZ;
inline uint32_t SFERA_IMPORT_Sound_CSound_dtor;
inline uint32_t SFERA_IMPORT_MSVCR100_initterm;
inline uint32_t SFERA_IMPORT_MSVCR100_acmdln;
inline uint32_t SFERA_IMPORT_MSVCR100_ismbblead;
inline uint32_t SFERA_IMPORT_MSVCR100_XcptFilter;
inline uint32_t SFERA_IMPORT_MSVCR100_exit;
inline uint32_t SFERA_IMPORT_MSVCR100_cexit;
inline uint32_t SFERA_IMPORT_MSVCR100_getmainargs;
inline uint32_t SFERA_IMPORT_MSVCR100_amsg_exit;
inline uint32_t SFERA_IMPORT_MSVCR100_terminate_YAXXZ;
inline uint32_t SFERA_IMPORT_MSVCR100_onexit;
inline uint32_t SFERA_IMPORT_MSVCR100_lock;
inline uint32_t SFERA_IMPORT_MSVCR100_dllonexit;
inline uint32_t SFERA_IMPORT_MSVCR100_initterm_e;
inline uint32_t SFERA_IMPORT_MSVCR100_configthreadlocale;
inline uint32_t SFERA_IMPORT_MSVCR100_setusermatherr;
inline uint32_t SFERA_IMPORT_MSVCR100_commode;
inline uint32_t SFERA_IMPORT_MSVCR100_fmode;
inline uint32_t SFERA_IMPORT_MSVCR100_set_app_type;
inline uint32_t SFERA_IMPORT_MSVCR100_crt_debugger_hook;
inline uint32_t SFERA_IMPORT_MSVCR100_type_info_type_info_dtor_internal_method;
inline uint32_t SFERA_IMPORT_MSVCR100_invoke_watson;
inline uint32_t SFERA_IMPORT_MSVCR100_isalnum;
inline uint32_t SFERA_IMPORT_MSVCR100_atoi;
inline uint32_t SFERA_IMPORT_MSVCR100_atof;
inline uint32_t SFERA_IMPORT_MSVCR100_utime64;
inline uint32_t SFERA_IMPORT_MSVCR100_stat64i32;
inline uint32_t SFERA_IMPORT_MSVCR100_strnicmp;
inline uint32_t SFERA_IMPORT_MSVCR100_controlfp_s;
inline uint32_t SFERA_IMPORT_MSVCR100_toupper;
inline uint32_t SFERA_IMPORT_MSVCR100_unlock;
inline uint32_t SFERA_IMPORT_MSVCR100_printf;
inline uint32_t SFERA_IMPORT_MSVCR100_calloc;
inline uint32_t SFERA_IMPORT_MSVCR100_isdigit;
inline uint32_t SFERA_IMPORT_MSVCR100_fsetpos;
inline uint32_t SFERA_IMPORT_MSVCR100_fseeki64;
inline uint32_t SFERA_IMPORT_MSVCR100_CIasin;
inline uint32_t SFERA_IMPORT_MSVCR100_isalpha;
inline uint32_t SFERA_IMPORT_MSVCR100_unlink;
inline uint32_t SFERA_IMPORT_MSVCR100_execl;
inline uint32_t SFERA_IMPORT_MSVCR100_fflush;
inline uint32_t SFERA_IMPORT_MSVCR100_floor;
inline uint32_t SFERA_IMPORT_MSVCR100_CIatan;
inline uint32_t SFERA_IMPORT_MSVCR100_CIacos;
inline uint32_t SFERA_IMPORT_MSVCR100_fgetpos;
inline uint32_t SFERA_IMPORT_MSVCR100_memcpy_s;
inline uint32_t SFERA_IMPORT_MSVCR100_setvbuf;
inline uint32_t SFERA_IMPORT_MSVCR100_unlock_file;
inline uint32_t SFERA_IMPORT_MSVCR100_lock_file;
inline uint32_t SFERA_IMPORT_MSVCR100_ungetc;
inline uint32_t SFERA_IMPORT_MSVCR100_fputc;
inline uint32_t SFERA_IMPORT_MSVCR100_bad_cast_ctor;
inline uint32_t SFERA_IMPORT_MSVCR100_bad_cast_dtor;
inline uint32_t SFERA_IMPORT_MSVCR100_bad_cast_ctor_272;
inline uint32_t SFERA_IMPORT_MSVCR100_strtok;
inline uint32_t SFERA_IMPORT_MSVCR100_fgetc;
inline uint32_t SFERA_IMPORT_MSVCR100_feof;
inline uint32_t SFERA_IMPORT_MSVCR100_CItan;
inline uint32_t SFERA_IMPORT_MSVCR100_spawnl;
inline uint32_t SFERA_IMPORT_MSVCR100_mkdir;
inline uint32_t SFERA_IMPORT_MSVCR100_getenv;
inline uint32_t SFERA_IMPORT_MSVCR100_atoi64;
inline uint32_t SFERA_IMPORT_MSVCR100_rename;
inline uint32_t SFERA_IMPORT_MSVCR100_chsize;
inline uint32_t SFERA_IMPORT_MSVCR100_fstat64i32;
inline uint32_t SFERA_IMPORT_MSVCR100_locking;
inline uint32_t SFERA_IMPORT_MSVCR100_sopen_YAHPBDHHH_Z;
inline uint32_t SFERA_IMPORT_MSVCR100_vscprintf;
inline uint32_t SFERA_IMPORT_MSVCR100_vsnprintf;
inline uint32_t SFERA_IMPORT_MSVCR100_exit_288;
inline uint32_t SFERA_IMPORT_MSVCR100_msize;
inline uint32_t SFERA_IMPORT_MSVCR100_strtime;
inline uint32_t SFERA_IMPORT_MSVCR100_fputs;
inline uint32_t SFERA_IMPORT_MSVCR100_strrchr;
inline uint32_t SFERA_IMPORT_MSVCR100_futime64;
inline uint32_t SFERA_IMPORT_MSVCR100_mktime64;
inline uint32_t SFERA_IMPORT_MSVCR100_difftime64;
inline uint32_t SFERA_IMPORT_MSVCR100_CIexp;
inline uint32_t SFERA_IMPORT_MSVCR100_CIatan2;
inline uint32_t SFERA_IMPORT_MSVCR100_strstr;
inline uint32_t SFERA_IMPORT_MSVCR100_vswprintf;
inline uint32_t SFERA_IMPORT_MSVCR100_memchr;
inline uint32_t SFERA_IMPORT_MSVCR100_access;
inline uint32_t SFERA_IMPORT_MSVCR100_strerror;
inline uint32_t SFERA_IMPORT_MSVCR100_remove;
inline uint32_t SFERA_IMPORT_MSVCR100_fread;
inline uint32_t SFERA_IMPORT_MSVCR100_fwrite;
inline uint32_t SFERA_IMPORT_MSVCR100_asctime;
inline uint32_t SFERA_IMPORT_MSVCR100_vsprintf;
inline uint32_t SFERA_IMPORT_MSVCR100_stricmp;
inline uint32_t SFERA_IMPORT_MSVCR100_purecall;
inline uint32_t SFERA_IMPORT_MSVCR100_close;
inline uint32_t SFERA_IMPORT_MSVCR100_read;
inline uint32_t SFERA_IMPORT_MSVCR100_open_YAHPBDHH_Z;
inline uint32_t SFERA_IMPORT_MSVCR100_write;
inline uint32_t SFERA_IMPORT_MSVCR100_lseek;
inline uint32_t SFERA_IMPORT_MSVCR100_memcpy;
inline uint32_t SFERA_IMPORT_MSVCR100_memset;
inline uint32_t SFERA_IMPORT_MSVCR100_sprintf;
inline uint32_t SFERA_IMPORT_MSVCR100_chmod;
inline uint32_t SFERA_IMPORT_MSVCR100_sscanf;
inline uint32_t SFERA_IMPORT_MSVCR100_exception_ctor;
inline uint32_t SFERA_IMPORT_MSVCR100_exception_what;
inline uint32_t SFERA_IMPORT_MSVCR100_exception_dtor;
inline uint32_t SFERA_IMPORT_MSVCR100_memmove;
inline uint32_t SFERA_IMPORT_MSVCR100_exception_ctor_325;
inline uint32_t SFERA_IMPORT_MSVCR100_ldiv;
inline uint32_t SFERA_IMPORT_MSVCR100_vfprintf;
inline uint32_t SFERA_IMPORT_MSVCR100_fprintf;
inline uint32_t SFERA_IMPORT_MSVCR100_ftell;
inline uint32_t SFERA_IMPORT_MSVCR100_fseek;
inline uint32_t SFERA_IMPORT_MSVCR100_fclose;
inline uint32_t SFERA_IMPORT_MSVCR100_fopen;
inline uint32_t SFERA_IMPORT_MSVCR100_snprintf;
inline uint32_t SFERA_IMPORT_MSVCR100_rand;
inline uint32_t SFERA_IMPORT_MSVCR100_errno;
inline uint32_t SFERA_IMPORT_MSVCR100_CIsqrt;
inline uint32_t SFERA_IMPORT_MSVCR100_CIcos;
inline uint32_t SFERA_IMPORT_MSVCR100_CIsin;
inline uint32_t SFERA_IMPORT_MSVCR100_CIpow;
inline uint32_t SFERA_IMPORT_MSVCR100_findclose;
inline uint32_t SFERA_IMPORT_MSVCR100_findnext64i32;
inline uint32_t SFERA_IMPORT_MSVCR100_findfirst64i32;
inline uint32_t SFERA_IMPORT_MSVCR100_localtime64;
inline uint32_t SFERA_IMPORT_MSVCR100_time64;
inline uint32_t SFERA_IMPORT_MSVCR100_strncpy;
inline uint32_t SFERA_IMPORT_MSVCR100_strftime;
inline uint32_t SFERA_IMPORT_MSVCR100_strchr;
inline uint32_t SFERA_IMPORT_MSVCR100_filelength;
inline uint32_t SFERA_IMPORT_MSVCR100_malloc;
inline uint32_t SFERA_IMPORT_MSVCR100_free;
inline uint32_t SFERA_IMPORT_MSVCR100_tolower;
inline uint32_t SFERA_IMPORT_MSVCR100_strncmp;
inline uint32_t SFERA_IMPORT_MSVCR100_qsort;
inline uint32_t SFERA_IMPORT_MSVCR100_realloc;
inline uint32_t SFERA_IMPORT_MSVCR100_srand;
inline uint32_t SFERA_IMPORT_MSVCR100_fgets;
inline uint32_t SFERA_IMPORT_MSVCP100_6_basic_ostream_DU_char_traits_D_std_std_QAEAAV01_I_Z;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sgetc;
inline uint32_t SFERA_IMPORT_MSVCP100_std_BADOFF;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_imbue;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sync;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_dtor;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_ios_dtor;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_ctor;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_ios_vftable;
inline uint32_t SFERA_IMPORT_MSVCP100_ios_base_vftable;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sbumpc;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_snextc;
inline uint32_t SFERA_IMPORT_MSVCP100_codecvt_unshift;
inline uint32_t SFERA_IMPORT_MSVCP100_codecvt_in;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_setg;
inline uint32_t SFERA_IMPORT_MSVCP100_codecvt_out;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_ios_clear;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sputc;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sputn;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_ios_setstate;
inline uint32_t SFERA_IMPORT_MSVCP100_std_uncaught_exception;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_Osfx;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_flush;
inline uint32_t SFERA_IMPORT_MSVCP100_std_Fiopen;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_getloc;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_xsputn;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_xsgetn;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_showmanyc;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_ctor;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_dtor;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_istream_Ipfx;
inline uint32_t SFERA_IMPORT_MSVCP100_Lockit_ctor;
inline uint32_t SFERA_IMPORT_MSVCP100_codecvt_id;
inline uint32_t SFERA_IMPORT_MSVCP100_Lockit_dtor;
inline uint32_t SFERA_IMPORT_MSVCP100_id_Id_cnt;
inline uint32_t SFERA_IMPORT_MSVCP100_codecvt_Getcat;
inline uint32_t SFERA_IMPORT_MSVCP100_facet_Incref;
inline uint32_t SFERA_IMPORT_MSVCP100_codecvt_base_always_noconv;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_Init;
inline uint32_t SFERA_IMPORT_MSVCP100_locale_Getgloballocale;
inline uint32_t SFERA_IMPORT_MSVCP100_facet_Decref;
inline uint32_t SFERA_IMPORT_MSVCP100_Container_base12_dtor;
inline uint32_t SFERA_IMPORT_MSVCP100_std_Xlength_error;
inline uint32_t SFERA_IMPORT_MSVCP100_std_Xout_of_range;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_Pninc;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_setbuf;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_uflow;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_Unlock;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_Lock;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_istream_vftable;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_istream_ctor;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_istream_dtor;
inline uint32_t SFERA_IMPORT_MSVCP100_ios_base_Ios_base_dtor;
inline uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_vftable;
inline uint32_t g_sfera_security_cookie = UINT32_C(0xBB40E64E);
inline uint32_t g_sfera_security_cookie_complement = UINT32_C(0x44BF19B1);
inline uint32_t g_sfera_log_first_write = 1u;

struct SferaItemArray {
    uint32_t block_vector_begin;
    uint32_t block_vector_end;
    uint32_t block_vector_capacity_end;
    uint32_t reserved;
    uint32_t free_items;
    uint32_t free_count;
    uint32_t growth_count;
};
struct SferaServerWall {
    uint32_t wall_data;
    uint32_t reserved_04;
    uint32_t wall_count;
    uint32_t generated_data;
    uint32_t generated_points;
    uint32_t segment_count;
    uint32_t effect_handle;
};
struct SferaDirectPlayCaps32 {
    uint32_t words[12];
};
struct SferaDpnCapsRuntime {
    uint32_t size;
    uint32_t flags;
    uint32_t connect_timeout_ms;
    uint32_t connect_retries;
    uint32_t timeout_until_keepalive_ms;
};
struct SferaDpnBufferDescRuntime {
    uint32_t buffer_size;
    uint32_t buffer_data;
};
struct SferaDpnConnectionInfoRuntime {
    uint32_t size;
    uint32_t round_trip_latency_ms;
    uint32_t throughput_bps;
    uint32_t peak_throughput_bps;
    uint32_t bytes_sent_guaranteed;
    uint32_t packets_sent_guaranteed;
    uint32_t bytes_sent_non_guaranteed;
    uint32_t packets_sent_non_guaranteed;
    uint32_t bytes_retried;
    uint32_t packets_retried;
    uint32_t bytes_dropped;
    uint32_t packets_dropped;
    uint32_t messages_transmitted_high_priority;
    uint32_t messages_timed_out_high_priority;
    uint32_t messages_transmitted_normal_priority;
    uint32_t messages_timed_out_normal_priority;
    uint32_t messages_transmitted_low_priority;
    uint32_t messages_timed_out_low_priority;
    uint32_t bytes_received_guaranteed;
    uint32_t packets_received_guaranteed;
    uint32_t bytes_received_non_guaranteed;
    uint32_t packets_received_non_guaranteed;
    uint32_t messages_received;
};
struct SferaU64Words {
    uint32_t low;
    uint32_t high;
};
using SferaCounter64Words = SferaU64Words;
struct SferaNetworkTransportRuntime {
    uint32_t mode;
    uint8_t transport_flag;
    uint8_t receive_busy;
    uint8_t receive_corrupted;
    uint8_t reserved_07;
    uint32_t primary_address;
    uint32_t secondary_address;
    uint32_t sent_packet_count;
    SferaCounter64Words sent_bytes;
    uint32_t received_packet_count;
    uint32_t receive_read_index;
    SferaCounter64Words received_bytes;
    uint32_t receive_write_index;
    uint32_t reserved_30;
};
struct SferaDirectPlayRuntime {
    uint32_t peer;
    SferaDpnCapsRuntime caps;
    uint8_t critical_section[24];
    SferaDpnBufferDescRuntime send_buffer;
    uint32_t send_async_handle;
    SferaDpnConnectionInfoRuntime connection_info;
    SferaNetworkTransportRuntime transport;
};
struct SferaNetworkMessageSlot {
    uint8_t bytes[0x1A8];
};
struct SferaNetworkRuntime {
    uint32_t initialization_result;
    uint32_t server_port;
    uint32_t local_port_candidate;
    uint32_t connection_slot;
    uint32_t pending_slot;
    uint32_t active_slot;
    uint32_t shutdown_state;
    uint8_t timeout_marker_pending;
    uint8_t net_log_has_error;
    uint8_t network_error_active;
    uint8_t initialized;
    uint32_t bytes_sent_delta;
    uint32_t bytes_retried_delta;
    uint32_t bytes_received_delta;
    uint32_t error_budget;
    SferaDirectPlayCaps32 directplay_caps;
    uint32_t message_call_scratch;
    SferaNetworkMessageSlot message_slots[3048];
};
struct SferaNetworkConnectionCheckerRuntime {
    uint32_t instance;
};
struct SferaNetworkSendRuntime {
    uint8_t critical_section[0x18];
};
struct SferaFontGlyphRuntime {
    uint32_t texture_index;
    float u;
    float v;
    uint32_t defined;
};
struct SferaFontRuntime {
    char language_suffix[8];
    uint32_t renderer;
    SferaFontGlyphRuntime glyphs[256];
};
struct SferaFontFactoryRuntime {
    uint16_t quad_indices[2400];
    uint32_t vertex_count;
    uint32_t vertex_buffer;
    uint32_t fonts_begin;
    uint32_t fonts_end;
    uint32_t fonts_capacity;
};
struct SferaCursorManagerRuntime {
    uint8_t object[8];
    uint32_t active_cursor;
    uint32_t initialized_flags;
};
struct SferaSliceReference32 {
    uint32_t base;
    uint32_t begin;
    uint32_t end;
};
struct SferaInterpreterScratchRuntime {
    uint32_t diagnostic_step_counter;
    uint32_t network_poll_counter;
    uint32_t item_lookup_result;
};
struct SferaGraphicsRuntime {
    float fog_distance;
    float saved_fog_distance;
    uint32_t lods_enabled;
    uint32_t hardware_cursor_enabled;
    float environment_factor;
    uint8_t render_mode_enabled;
    uint32_t base_microtexture_id;
    float view_parameter;
    float view_scale;
    uint32_t post_effects_enabled;
    uint32_t rebuild_percent;
    uint32_t runtime_counter;
    uint32_t texture_runtime_id;
    float base_render_factor;
    uint32_t display_width;
    uint32_t display_height;
    uint32_t d3d9_device;
};
struct SferaBoundCheckArray {
    uint32_t data;
    uint32_t capacity;
    char debug_file[32];
    uint32_t debug_line;
};
struct SferaWorldObjectRuntime {
    uint32_t max_occupied_object_handle;
    uint32_t controlled_object_handle;
    uint32_t contour_mode;
    SferaBoundCheckArray object_handles;
    SferaBoundCheckArray extended_object_handles;
    uint32_t extended_object_count;
};
struct SferaGrassRuntime {
    SferaBoundCheckArray instance_offsets;
    SferaBoundCheckArray model_handles;
    SferaBoundCheckArray instance_indices;
    SferaBoundCheckArray type_records;
};
struct SferaLightRuntime {
    SferaBoundCheckArray cell_light_ids;
    SferaBoundCheckArray cell_records;
    SferaBoundCheckArray cell_indices;
    SferaBoundCheckArray handles;
    SferaBoundCheckArray visible_handles;
    SferaBoundCheckArray active_handles;
    uint32_t render_candidate_indices[30];
    uint32_t render_candidate_active[30];
};
struct SferaAutoBoundsArray {
    uint32_t data;
    uint32_t capacity;
    uint32_t maximum;
    uint32_t growth;
    uint32_t element_size;
    char debug_file[32];
    uint32_t debug_line;
};
struct SferaLandscapeRuntime {
    SferaBoundCheckArray file_records;
    SferaBoundCheckArray microtexture_handles;
};
struct SferaCollisionRuntime {
    SferaBoundCheckArray candidate_handles;
    SferaBoundCheckArray near_result_handles;
    SferaAutoBoundsArray contact_objects;
};
struct SferaSceneArrayRuntime {
    SferaBoundCheckArray cloud_records;
    SferaBoundCheckArray surface_index_map;
    SferaBoundCheckArray scene_records;
    SferaBoundCheckArray render_pass_slots;
    SferaBoundCheckArray surface_handles;
    SferaBoundCheckArray clip_vectors;
    SferaBoundCheckArray surface_records;
    SferaBoundCheckArray scene_points;
    SferaBoundCheckArray object_positions;
    SferaBoundCheckArray model_matrices;
    SferaBoundCheckArray world_cell_records;
    SferaBoundCheckArray render_work_records;
    SferaBoundCheckArray reflection_targets;
    SferaBoundCheckArray object_sort_keys;
    SferaBoundCheckArray render_ranges;
    SferaBoundCheckArray object_draw_indices;
    SferaBoundCheckArray object_visibility_indices;
    SferaBoundCheckArray clip_points;
    SferaBoundCheckArray character_matrices;
    SferaBoundCheckArray object_sort_indices;
    SferaBoundCheckArray clip_indices;
};
struct SferaSceneBuildRuntime {
    uint32_t object_count;
    uint16_t landscape_debug_pixels[256 * 256];
};
struct SferaWeatherRuntime {
    SferaBoundCheckArray sky_texture_handles;
    uint32_t interpolation_offsets[kWeatherInterpolationOffsetCount];
    char parse_error[0xC8];
    float direction_cos_component;
    float direction_sin_component;
    uint32_t standard_object;
    uint32_t highres_object;
};
struct SferaModelRuntime {
    uint32_t repository;
};
struct SferaTreeMapHeader {
    uint8_t comparator;
    uint8_t reserved[3];
    uint32_t sentinel;
    uint32_t size;
};
using SferaModelRegistryRuntime = SferaTreeMapHeader;
struct SferaModelMaterialLookupRuntime {
    uint32_t refresh_tick;
    char material_name[0xAC];
};
struct SferaIntrusiveListHeader {
    uint32_t first;
    uint32_t last;
};
using SferaListStackRuntime = SferaIntrusiveListHeader;
struct SferaNatureRuntime {
    uint32_t manager;
};
struct SferaSoundRuntime {
    uint32_t effect_manager;
    uint32_t manager;
    SferaListStackRuntime tracks;
};
struct SferaWarningLogRuntime {
    uint8_t object[0x5320];
};
struct SferaControlOptionsRuntime {
    uint32_t active_slot;
    uint32_t configured_bindings[64];
    uint32_t working_bindings[64];
};
struct SferaSpriteRuntime {
    uint32_t render_mode;
    char texture_token[0x110];
};
struct SferaCrashRuntime {
    uint8_t report_pending;
};
struct SferaContoursRuntime {
    uint32_t round_robin_counter;
};
using SferaDynGreenRuntime = SferaU64Words;
struct SferaExecutionMonitorRuntime {
    uint32_t thread_handle;
    uint8_t reserved_04[8];
    uint16_t stop_requested;
    char log_path[0x36];
    uint8_t critical_section[24];
    uint32_t current_value_a;
    uint32_t current_value_b;
};
struct SferaErrorLogRuntime {
    uint8_t object[0x18];
    uint8_t index_table[0x80];
};
struct SferaPacketCodecRuntime {
    uint8_t substitution[256];
    uint32_t initialized;
    uint16_t checksum[256];
};
struct SferaFrameRuntime {
    float fps;
    uint32_t fps_sample_count;
    SferaU64Words fps_anchor;
    uint32_t frame_sample_count;
    SferaU64Words frame_anchor;
    SferaU64Words frame_state_anchor;
    uint32_t frame_state;
    uint32_t primary_toggle;
    uint32_t secondary_toggle;
    uint8_t color_lookup_object[0x1C];
    uint32_t color_lookup_flags;
    uint32_t warning_header_written;
};
struct SferaHighResolutionClockRuntime {
    SferaU64Words elapsed_counter;
    SferaU64Words epoch_microseconds;
    SferaU64Words performance_frequency;
    uint32_t frequency_shift;
    uint32_t initialized;
    SferaU64Words counter_anchor;
};
struct SferaProfilerRuntime {
    SferaU64Words accumulated_ticks[kProfileSlotCount];
    uint8_t active[kProfileSlotCount];
    uint32_t frame_count;
    SferaU64Words start_time_us[kProfileSlotCount];
    uint32_t call_count[kProfileSlotCount];
    uint32_t frame_time_total;
    SferaU64Words report_clock_snapshot;
    uint32_t report_percent[10];
};
struct SferaCrc32Runtime {
    uint32_t table[256];
    uint32_t current;
};
struct SferaUiLoadScratchRuntime {
    char button_value[256];
    char checkbox_value[256];
    char text_value[256];
    char image_value[256];
    char cursor_name[128];
    char resolved_ui_path[256];
    char localized_text[1024];
    char localized_key[256];
    char list_item_value[256];
    char progress_bar_value[256];
    char scroll_bar_value[256];
    char slider_status_value[256];
    char slot_value[256];
    char resolution_text[128];
    char spin_value_text[128];
    char text_style_token[256];
    char tooltip_key[256];
};
struct SferaHyperTextScratchRuntime {
    char attribute_name[256];
    char command_text[256];
    char token_text[256];
};
struct SferaStringLookupRuntime {
    uint16_t hash_mix[256];
    uint8_t case_fold[256];
    uint32_t initialized;
};
struct SferaAsciiLowerRuntime {
    uint8_t table[256];
};
struct SferaModelLoadScratchRuntime {
    char filename[128];
};
struct SferaStringUtilityRuntime {
    uint32_t case_tables_initialized;
    uint8_t lowercase[256];
    uint8_t uppercase[256];
    char format_buffer[512];
};
struct SferaNetworkProbeSample {
    SferaU64Words timestamp;
    uint32_t probe_result;
    uint32_t context_a;
    uint32_t context_b;
    uint32_t context_c;
};
struct SferaNetworkProbeRuntime {
    uint32_t sample_count;
    uint8_t stop_requested;
    uint8_t host[64];
    uint32_t context_a;
    uint32_t context_b;
    uint32_t snapshot_count;
    uint32_t thread_handle;
    uint32_t critical_section_words[6];
    SferaNetworkProbeSample samples[kNetworkProbeSampleCount];
    uint32_t context_c;
    SferaNetworkProbeSample snapshot[kNetworkProbeSampleCount];
};
struct SferaConfigParseScratchRuntime {
    uint8_t token[256];
};
struct SferaMusicRuntime {
    uint8_t requested_path[512];
    uint32_t current_stream;
};
struct SferaContainerDiagnosticsRuntime {
    char range_error[128];
};
struct SferaOleHostAbi {
    uint32_t storage_vtable[18];
    uint32_t storage_object_vtable;
    uint32_t inplace_frame_vtable[15];
    uint32_t client_site_vtable[9];
    uint32_t inplace_site_vtable[15];
    uint32_t doc_host_ui_handler_vtable[18];
};
struct SferaMainCommandStateRuntime {
    uint8_t command_enabled;
    uint8_t lighting_enabled;
    uint8_t reserved_002[6];
    uint32_t render_samples[120];
    float sky_blend_factor;
    uint32_t lighting_state;
    uint32_t light_update_counter;
    uint32_t default_cursor_token[2];
    uint8_t reserved_1fc[0x0C];
    uint32_t draw_selection_state;
    uint32_t async_status;
    uint8_t async_status_bytes[0x10];
    uint32_t render_channel_mask;
    uint32_t object_reference_count;
    uint32_t command_state;
    uint32_t escape_without_query;
    uint32_t window_count;
    uint32_t viewport_state;
    uint32_t interface_state;
    uint32_t near_collision_count;
};

struct SferaMainInputStateRuntime {
    uint32_t input_state;
    uint8_t reserved_004[8];
    uint32_t input_mode;
    float motion_accumulator;
    uint32_t timing_accumulator;
    uint32_t input_state_02;
    uint32_t input_state_03;
    uint32_t input_enabled;
    float camera_step;
    uint8_t reserved_028[4];
    int32_t cursor_x;
    int32_t cursor_y;
    uint32_t cursor_state;
    uint32_t cursor_flags;
    float motion_x;
    float motion_y;
    uint32_t input_state_04;
    uint32_t active_input_handle;
    uint32_t input_state_05;
    uint8_t reserved_050[8];
    uint32_t reference_position[3];
    uint32_t landscape_texture_base;
    uint8_t landscape_texture_lut[256][2];
    uint32_t landscape_state;
};

struct SferaMainViewStateRuntime {
    float projection_samples[125];
    uint32_t projection_sample_count;
    uint32_t view_state;
    float view_coefficients[6];
    uint32_t view_base_index;
    uint32_t view_flags;
    uint32_t view_mode;
    uint32_t view_accumulator;
    float projection_scale;
    uint32_t ui_sort_keys[kUiSortIndexCount];
};

struct SferaInterpolationAxisState {
    uint32_t count;
    float samples[19];
};

struct SferaMainUiStateRuntime {
    uint32_t ui_state;
    char gamexp_sid[32];
    uint32_t ui_state_02;
    uint32_t ui_state_03;
    uint32_t ui_state_04;
    uint8_t reserved_030[8];
    float scene_factor;
    float scene_scale;
    uint32_t ui_state_05;
    uint32_t active_ui_object;
    float clip_planes[6][4];
    uint32_t ui_state_06;
    uint32_t ui_state_07;
    uint32_t ui_state_08;
    uint8_t reserved_0b4[4];
    SferaInterpolationAxisState interpolation_axes[3];
    uint32_t reserved_1a8;
    uint32_t ui_state_09;
};

struct SferaClientConfigRuntime {
    uint32_t state_01;
    uint32_t state_02;
    uint8_t reserved_008;
    uint8_t flag_01;
    uint8_t flag_02;
    uint8_t flag_03;
    uint32_t state_03;
    uint32_t state_04;
    uint32_t state_05;
    uint32_t state_06;
    uint32_t state_07;
    uint32_t state_08;
    uint32_t state_09;
    uint32_t state_10;
    float scalar_01;
    uint32_t state_11;
    uint32_t state_12;
    uint32_t state_13;
    uint32_t state_14;
    uint32_t state_15;
    uint32_t state_16;
    uint8_t reserved_048[4];
    uint32_t state_17;
    uint32_t state_18;
    uint8_t reserved_054[0x0C];
    uint32_t debug_config_enabled;
    uint8_t reserved_064[4];
    uint32_t state_19;
    uint32_t state_20;
    uint32_t state_21;
    uint32_t state_22;
    uint32_t state_23;
    uint8_t reserved_07c[5];
    uint8_t connect_type_enabled;
    uint8_t gamexp_sid_present;
    uint8_t reserved_083;
    uint32_t state_24;
    uint8_t reserved_088[4];
    uint32_t state_25;
    uint32_t state_26;
    uint32_t state_27;
    uint8_t reserved_098[8];
    uint32_t state_28;
    uint32_t state_29;
    uint32_t text_length_01;
    char text_01[0x10];
    uint8_t reserved_0bc[0x10];
    uint32_t text_capacity_01;
    uint8_t object_01[0x0C];
    uint32_t state_30;
    uint32_t text_length_02;
    char text_02[0x10];
    uint8_t reserved_0f4[0x10];
    uint32_t text_capacity_02;
    uint32_t auto_grass_object;
};

struct SferaGrassPlacementSlot {
    uint32_t model_handle;
    float position_x;
    float position_y;
    float position_z;
    uint32_t state_01;
    uint32_t state_02;
    uint32_t state_03;
    uint8_t reserved_01c[0x12C];
    float scale;
    uint8_t reserved_14c[8];
    float vector_x;
    float vector_y;
    float vector_z;
    uint8_t reserved_160[0x194];
};
struct SferaGrassPlacementRuntime {
    SferaGrassPlacementSlot slots[36];
};

struct SferaSavedControlledPositionRuntime {
    uint32_t x;
    uint32_t y;
    uint32_t z;
};

struct SferaInterfaceCoreRuntime {
    uint32_t state_01;
    uint32_t state_02;
    uint32_t state_03;
    uint32_t state_04;
    uint32_t state_05;
    uint32_t state_06;
    uint32_t state_07;
    uint32_t state_08;
    uint32_t state_09;
    uint32_t state_10;
    uint32_t state_11;
    uint8_t reserved_02c[4];
    uint32_t state_12;
    uint8_t reserved_034[0x0C];
    uint8_t lookup_object[0x5C];
    uint32_t list_head;
    uint32_t list_count;
    uint8_t reserved_0a4[4];
    uint8_t manager_object[0x60];
    uint32_t queue_head;
    uint32_t queue_state;
    uint32_t queue_begin;
    uint32_t queue_end;
    uint32_t queue_cursor;
    uint8_t reserved_11c[4];
    uint32_t free_list_a;
    uint32_t free_list_a_cursor;
    uint8_t reserved_128[4];
    uint32_t free_list_b;
    uint32_t free_list_b_cursor;
    uint8_t reserved_134[4];
    uint32_t object_head;
    uint32_t object_count;
    uint32_t object_state;
    uint32_t object_aux;
    uint8_t text_object[0x48];
    uint8_t text_object_ready;
    uint8_t reserved_191[3];
};
struct SferaClientMainScalarRuntime {
    uint32_t counter_01;
    uint32_t state_01;
    uint32_t state_02;
    uint32_t state_03;
    uint32_t state_04;
    uint32_t counter_02;
    uint32_t counter_03;
    uint32_t mode_01;
    uint32_t mode_02;
    uint32_t state_05;
    uint32_t state_06;
    uint32_t state_07;
    uint32_t state_11;
    uint32_t state_12;
    uint32_t state_13;
    uint32_t state_14;
    uint32_t state_15;
    uint32_t state_16;
    uint32_t state_17;
    uint32_t state_18;
    uint32_t state_19;
    uint32_t state_20;
    uint32_t state_21;
    uint32_t state_22;
    uint32_t state_23;
    uint32_t state_24;
    uint32_t state_25;
    uint32_t state_26;
    uint32_t state_27;
    uint32_t state_28;
    uint32_t state_29;
    uint32_t state_30;
    uint32_t state_31;
    uint32_t state_32;
    uint32_t state_33;
    uint32_t state_34;
    uint32_t state_35;
    uint32_t state_36;
    uint32_t counter_04;
};
struct SferaInterScalarRuntime {
    uint32_t state_01;
    uint32_t state_02;
    uint32_t state_03;
    uint32_t mode_01;
    uint32_t mode_02;
    uint32_t mode_03;
    uint32_t state_04;
    uint32_t mode_04;
    uint32_t state_05;
    uint32_t state_06;
    uint32_t state_07;
};
struct SferaTextureSetScalarRuntime {
    uint32_t state_01;
    uint32_t state_02;
    uint32_t mode_01;
    uint32_t state_03;
    uint32_t mode_02;
    uint32_t record_default_38;
    uint32_t record_default_3c;
    uint32_t last_selector;
};
struct SferaTextureRegistryRuntime {
    uint32_t texture_count;
    uint32_t stream_direction_flag;
    uint32_t batch_count;
    uint32_t initialized;
    uint32_t path_count;
    uint32_t batch_records;
    uint16_t hash_heads[65536];
    char paths[500][100];
    uint32_t preload_request_count;
    uint32_t default_texture_id;
    uint16_t hash_mix[256];
};
struct SferaInterfaceRuntime {
    uint32_t cursor_kind;
    uint8_t primary_gate;
    uint8_t secondary_gate;
    uint32_t cross_enabled;
    uint32_t sounds_enabled;
    uint32_t description_auto_popup;
    uint32_t invite_messages;
    uint32_t description_window;
    uint32_t previous_input_modifiers;
    SferaBoundCheckArray windows;
    SferaBoundCheckArray window_handle_table;
};
using SferaStdAllocator = StdAllocator;
struct SferaMemoryRuntime {
    uint32_t allocation_source_file;
    uint32_t allocation_source_line;
    uint32_t critical_error_callback;
    uint32_t tracker_primary;
    uint32_t tracker_auxiliary;
    uint32_t tracker_floor;
    uint32_t tracker_ceiling;
    uint32_t bucket_bytes[1024];
    uint32_t bucket_allocations[1024];
    uint8_t tracking_initialized;
    uint8_t diagnostics_dirty;
    uint32_t live_allocation_count;
    uint32_t validation_pass_count;
    uint32_t lock_words[6];
    uint8_t lock_initialized;
    uint8_t lock_held;
};
struct SferaMemorySourceHashRuntime {
    uint32_t entries;
    uint32_t capacity;
    uint16_t free_index;
    uint16_t bucket_heads[1024];
    uint8_t reserved_80a[6];
};
struct SferaAllocationHashRuntime {
    uint32_t records;
    uint32_t capacity;
    uint32_t free_index;
    uint32_t bucket_heads[65536];
};
struct SferaAntifloodQueueRuntime {
    uint8_t records[0x280];
    uint32_t count;
    uint32_t write_index;
    uint32_t read_index;
};
struct SferaDiagnosticLogObjectRuntime {
    uint8_t header[0x38];
    SferaAntifloodQueueRuntime antiflood_queue;
    uint32_t reserved_2c4;
};
struct SferaWin32DialogRegistryRuntime {
    uint32_t sentinel;
    uint32_t size;
};
using SferaControlReferenceRegistryRuntime = SferaTreeMapHeader;
using SferaCursorTextureRegistryRuntime = SferaTreeMapHeader;
struct SferaBrowserWindowRuntime {
    uint8_t class_registered;
    uint8_t reserved_01[3];
    uint32_t original_window_proc;
};
struct SferaMinimapTextureRuntime {
    uint32_t singleton;
};
struct SferaCrtStartupRuntime {
    uint32_t managed_app;
    uint32_t environment;
    uint32_t main_return_code;
    uint32_t has_cctor;
    uint32_t dynamic_tls_dtor_callbacks;
    uint32_t startup_state;
    uint32_t processor_feature_10;
    uint32_t dynamic_tls_init_callback;
    uint32_t encoded_onexit_begin;
    uint32_t encoded_onexit_end;
    uint32_t argc;
    uint32_t argv;
    uint32_t envp;
    uint32_t mainargs_result;
    uint32_t new_mode;
    uint32_t environment_mode;
    uint32_t commode;
    uint32_t fmode;
    uint32_t startup_lock;
    uint32_t tls_cleanup_object;
    uint32_t heap_compatibility_flag;
};
struct SferaCrashReportRuntime {
    char report_text[0x2000];
    uint32_t report_length;
    uint32_t reserved_2004;
    char error_log_path[0x104];
    uint32_t previous_exception_filter;
    uint32_t process_handle;
    uint32_t error_log_handle;
};
struct SferaRenderBufferCapacities {
    uint32_t vertex32;
    uint32_t vertex28;
    uint32_t index_primary;
    uint32_t index_secondary;
};
struct SferaFileRuntime {
    uint32_t crash_report_instance;
    uint32_t callback_enabled;
    uint32_t search_path_count;
    uint32_t open_file_count;
    uint32_t callback;
    SferaAutoBoundsArray search_paths;
    SferaAutoBoundsArray open_files;
};
struct SferaVec3F {
    float x;
    float y;
    float z;
};
union SferaFloatWord {
    float f32;
    uint32_t u32;
};
struct SferaVec3Word {
    SferaFloatWord x;
    SferaFloatWord y;
    SferaFloatWord z;
};
struct SferaSceneVectorRuntime {
    SferaVec3Word render_scale;
    SferaVec3Word transform_scratch;
    SferaVec3Word frame_102_position;
    SferaVec3Word frame_101_position;
    SferaVec3Word object_position_delta;
};
struct SferaSpatialBoundsRuntime {
    SferaVec3Word minimum;
    SferaVec3Word maximum;
};
struct SferaViewSpatialRuntime {
    SferaVec3Word basis[4];
    uint8_t alternate_projection;
    uint8_t reserved_31[3];
    SferaVec3Word position_offset;
    SferaVec3Word scale;
    SferaVec3Word world_anchor;
    SferaVec3Word view_axis;
};
using SferaLandscapeSampleSeries = SferaInterpolationAxisState;
struct SferaLandscapeInterpolationRuntime {
    uint32_t subdivision_count;
    SferaLandscapeSampleSeries axes[3];
};
union SferaLogPath {
    char text[52];
    uint32_t words[13];
};
struct SferaLogFileRuntime {
    SferaLogPath path;
    uint32_t truncate_on_first_write;
    uint32_t has_written;
    uint32_t size_limit;
};
struct SferaLogRuntime {
    SferaLogFileRuntime files[3];
};
struct SferaMatrix4x4F {
    float m[4][4];
};
struct SferaD3D9SemanticStateRuntime {
    uint32_t vertex_declaration;
    uint32_t shader_manager;
    SferaMatrix4x4F view_matrix;
    SferaMatrix4x4F projection_matrix;
    uint32_t sampler_min_filter;
    uint32_t sampler_mag_filter;
    uint32_t sampler_mip_filter;
};
struct SferaVec4F {
    float x;
    float y;
    float z;
    float w;
};
struct SferaTransformRuntime {
    uint32_t matrix_address;
    uint32_t reserved_04[3];
    SferaMatrix4x4F matrix;
    SferaVec3F scale;
    SferaVec3F secondary_scale;
    uint32_t flags;
    uint32_t reserved_6c;
};
struct SferaBoundsCornersRuntime {
    SferaVec3F corners[8];
};
struct SferaSpatialStateRuntime {
    SferaTransformRuntime transform;
    SferaBoundsCornersRuntime bounds;
};
struct SferaSkyInterpolationRuntime {
    SferaVec4F primary_samples[10];
    float primary_key_positions[10];
    SferaVec4F primary_reference;
    SferaVec4F secondary_samples[6];
    float secondary_key_positions[6];
};
struct SferaColorExpansionRuntime {
    uint32_t five_bit_to_eight_bit[32];
    uint8_t initialized;
};
struct SferaUiParseScratchRuntime {
    char token_buffer[0x4000];
    char auxiliary_text[0x4000];
    char input_text[0x4000];
};
struct SferaCriticalDiagnosticsRuntime {
    char allocation_context[128];
    uint32_t processing_depth;
    uint32_t serial_number;
    uint32_t stack_dump_callback;
    uint32_t log_chain_head;
};
struct SferaScreenVertex {
    float x;
    float y;
    float z;
    float rhw;
    uint32_t diffuse;
    uint32_t specular;
    float u;
    float v;
};
template <std::size_t N, typename Member>
inline uint32_t sfera_screen_vertex_address(SferaScreenVertex (&vertices)[N], std::size_t index, Member SferaScreenVertex::* member) {
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&(vertices[index].*member)));
}

template <std::size_t N, typename Member>
inline uint32_t sfera_screen_vertex_field_end_address(SferaScreenVertex (&vertices)[N], Member SferaScreenVertex::* member) {
    return sfera_screen_vertex_address(vertices, 0u, member) + static_cast<uint32_t>(sizeof(vertices));
}
struct SferaSceneRenderRuntime {
    SferaScreenVertex textured_quad[4];
    SferaScreenVertex interface_quad[4];
};
struct SferaGraphicsOptionsRuntime {
    uint32_t dialog_state;
    uint32_t graphics_page;
    uint32_t interface_values[9];
    uint32_t graphics_values[13];
    uint32_t saved_interface_values[9];
};
struct SferaSphereOptionsRuntime {
    uint32_t saved_lods_enabled;
    SferaFloatWord saved_lod_distance;
    SferaFloatWord saved_fog_distance;
    uint32_t saved_music_volume;
    char option_labels[7][0x200];
};
struct SferaVector32 {
    uint32_t begin;
    uint32_t end;
    uint32_t capacity_end;
};
struct SferaOptionsDialogRuntime {
    uint32_t graphics_snapshot[7];
    uint32_t audio_settings;
    char widget_key_name[0x80];
    uint32_t pending_graphics_value;
    uint32_t comparison_graphics_value;
    uint32_t widget_keys_initialized;
    uint32_t reflection_quality;
    uint32_t aligned_storage_token;
    uint8_t aligned_storage_padding[0x0C];
    uint8_t aligned_storage_object[0xC0];
    SferaVector32 chat_list_fonts;
    uint32_t reserved_18c;
    SferaVector32 chat_edit_fonts;
    uint32_t reserved_19c;
    SferaVector32 graphics_modes;
};
struct SferaWindowRuntime {
    uint32_t render_vertex_buffer;
    uint32_t reserved_004;
    uint32_t render_state_word;
    uint32_t reserved_00c;
    uint32_t clip_vector_count;
    SferaFloatWord distance_scratch;
    uint8_t timing_critical_section[24];
    uint8_t reserved_030[0x78];
    uint32_t input_runtime_object;
    uint32_t reserved_0ac;
    uint32_t input_state;
    uint32_t active_window_index;
    uint32_t windowed;
    uint32_t main_window;
    uint32_t reserved_0c0;
    uint32_t landscape_grid_records;
    uint32_t landscape_grid_count;
    uint32_t runtime_debug_enabled;
    uint32_t reserved_0d0;
    uint32_t scene_record_count;
    char diagnostic_message[0x800];
    uint32_t reserved_8d8;
};
struct SferaInputDeviceRuntime {
    uint32_t process_value;
    uint32_t input_generation;
    uint32_t reserved_008;
    SferaFloatWord minimum_lod_distance;
    SferaFloatWord lod_distance;
    uint32_t keyboard_device;
    uint32_t keyboard_state_code;
    uint32_t reserved_01c;
    SferaFloatWord frame_interval;
    uint32_t render_state;
    uint32_t shared_object;
};
struct SferaScreenClipRuntime {
    uint32_t left;
    uint32_t top;
    uint32_t right;
    uint32_t bottom;
};
struct SferaDirectInputRuntime {
    uint32_t direct_input;
    uint32_t mouse_device;
    uint8_t keyboard_state[256];
    uint32_t acquire_failure_state;
    uint8_t view_adjust_state;
    uint8_t modifier_08;
    uint8_t modifier_20;
    uint8_t reserved_10b;
};
struct SferaShadowRuntime {
    uint32_t projected_points;
    uint32_t span_records;
    uint32_t manager;
    uint32_t projected_point_capacity;
    uint32_t aligned_global_object;
};
struct SferaWorldRenderRuntime {
    uint32_t active_model;
    uint32_t world_spatial_index;
    uint32_t feature_toggle;
    uint32_t render_queue_count;
    uint32_t scene_active;
};
struct SferaWorldLoadRuntime {
    uint32_t render_shadows;
    uint32_t active_tool_context;
    uint32_t live_object_count;
    uint32_t packed_variant;
    uint32_t loading_work_total;
    uint32_t snow_path_object;
};
using SferaWorldBoundsRuntime = SferaSpatialBoundsRuntime;
struct SferaRenderLookupEntry {
    uint32_t resource;
    uint32_t mask;
};
struct SferaRenderLookupRuntime {
    uint32_t initialized;
    uint32_t alpha_component;
    SferaRenderLookupEntry entries[256];
};
struct SferaLandscapeRenderRuntime {
    uint32_t grid_buffer_bytes;
    SferaFloatWord view_offset_x;
    SferaFloatWord view_offset_y;
    uint32_t rotation_step;
    uint32_t source_record_count;
    uint32_t source_section_base;
};
struct SferaProcessRuntime {
    char executable_path[64];
    uint32_t packed_layout_bytes;
    uint32_t packed_record_count;
};
struct SferaClientProcessRuntime {
    uint32_t ui_bridge;
    uint32_t shutdown_requested;
    char locale[10];
    uint32_t client_object;
    char log_message[0x390];
};
struct SferaMainRenderRuntime {
    uint32_t world_object_count;
    uint32_t secondary_render_pass;
    uint32_t material_count;
    uint32_t grass_depth_mode;
};
struct SferaMicrotextureRecord {
    uint16_t lookup_key;
    uint16_t reserved_02;
    uint32_t name;
    uint32_t resource;
};
struct SferaSceneControlRuntime {
    uint32_t packed_section_base;
    uint32_t timing_anchor;
    SferaFloatWord camera_x;
    SferaFloatWord camera_y;
    SferaFloatWord environment_parameter;
    uint32_t active_context;
    uint32_t context_count;
    uint32_t context_queue[30];
    uint32_t microtexture_count;
    SferaMicrotextureRecord microtextures[100];
};
struct SferaMainAuxRuntime {
    uint32_t secondary_world_manager;
    uint32_t color_component;
    uint32_t resource_word;
};
struct SferaLandscapeMapRecord {
    char material_name[20];
    uint8_t tile_x;
    uint8_t tile_y;
};
struct SferaLandscapeMapRuntime {
    uint32_t material_remap;
    uint32_t show_fps;
    SferaLandscapeMapRecord records[kLandscapeMapRecordCount];
};
struct SferaSkyRuntime {
    SferaFloatWord horizon_scale;
    uint32_t draw_resource;
    uint16_t indices[594];
};
struct SferaTextureCacheEntry {
    uint32_t owner;
    uint8_t kind;
    uint8_t reserved_05[3];
    uint32_t resource;
    uint32_t use_count;
};
struct SferaTextureCacheRuntime {
    uint32_t active_index;
    uint32_t upload_serial;
    uint32_t reserved_08;
    uint32_t render_gate;
    uint32_t reserved_10;
    uint32_t cache_enabled;
    SferaTextureCacheEntry entries[kTextureCacheEntryCount];
};
struct SferaFontAtlasLayoutRuntime {
    uint32_t span[5];
    uint32_t origin[5];
    uint32_t cell_step[5];
    uint32_t resource_count[5];
    uint32_t code_base[5];
};
struct SferaFontAtlasStagingRuntime {
    uint32_t magic;
    uint32_t width;
    uint32_t height;
    uint32_t mip_count;
    uint32_t reserved_10[3];
    uint32_t encoding;
    uint16_t pixels[256 * 256];
};
struct SferaPartitionSortEntry {
    uint32_t partition_index;
    float sort_key;
};
struct SferaPartitionSortRuntime {
    SferaPartitionSortEntry entries[200];
};
struct SferaErrorMessageScratchRuntime {
    char fatal_message[kErrorMessageCapacity];
    char formatted_message[kErrorMessageCapacity];
};
struct SferaMaterialFilterRuntime {
    uint32_t character_map[2][kMaterialFilterCharCount];
    char exception_scratch[32];
    char filter_word[36];
    char match_buffer[kMaterialFilterTextCapacity];
    uint32_t token_lengths[kMaterialFilterTokenCapacity];
    uint32_t token_starts[kMaterialFilterTokenCapacity];
    char normalized_input[kMaterialFilterTextCapacity];
    char tag_stripped_input[kMaterialFilterTextCapacity];
};
struct SferaGrassMapManagerRuntime {
    uint32_t vptr;
    uint32_t cache_state[5];
    uint32_t initialized;
};
struct SferaGrassMapRuntime {
    uint32_t alternating_update_phase;
    SferaGrassMapManagerRuntime manager;
    uint32_t init_guard;
    SferaU64Words last_frame_timestamp;
};
struct SferaPhysicsRuntime {
    char damage_text[20];
    float response_curve[100];
};
struct SferaIntBounds3 {
    uint32_t min_x;
    uint32_t max_x;
    uint32_t min_y;
    uint32_t max_y;
    uint32_t min_z;
    uint32_t max_z;
};
struct SferaViewGeometryRuntime {
    SferaVec3F reference_points[5];
    SferaIntBounds3 projected_bounds;
    SferaIntBounds3 clipping_bounds;
};
struct SferaViewProjectionScratchRuntime {
    SferaVec3F corners[8];
    SferaIntBounds3 clipping_bounds;
};
struct SferaTerrainNeighborRuntime {
    uint32_t cells[8];
};
struct SferaLandscapePatchLookupRuntime {
    uint32_t visible_count;
    uint32_t active_count;
    SferaFloatWord parameter;
    SferaVec3Word primary_vector;
    SferaVec3Word secondary_vector;
    uint32_t patch_records[6400];
};
struct SferaDebugWindowRuntime {
    uint32_t spider_window;
};
struct SferaLandscapeProbeRuntime {
    char size_path[16];
};
struct SferaViewMotionRuntime {
    SferaFloatWord motion_terms[5];
    SferaVec3Word reference_point;
    SferaVec3Word projected_a;
    SferaVec3Word projected_b;
    uint32_t update_serial;
    uint32_t mode_value;
    uint32_t initialized;
};
struct SferaRenderSampleRuntime {
    SferaFloatWord direction_x;
    SferaFloatWord direction_y;
    SferaFloatWord blend_weights[7];
    uint32_t material_base;
    uint32_t record_base;
    uint32_t active_record;
    SferaFloatWord material_code;
    SferaFloatWord phase;
    float samples[kRenderSampleCount];
};
struct SferaTerrainDiagnosticRuntime {
    char normalize_code[12];
    char planting_message[0xC8];
};
struct SferaWorldSlotRecord {
    uint32_t object_handle;
    uint8_t reserved_004[0x0C];
    uint32_t state;
    uint32_t linked_handle;
    uint8_t reserved_018[0x0C];
    uint32_t primary_state;
    uint32_t primary_flags;
    uint8_t primary_payload[0x190];
    uint32_t secondary_state;
    uint32_t secondary_flags;
    uint8_t secondary_payload[0x190];
    uint32_t record_state;
    uint8_t reserved_358[0x40];
};
struct SferaWorldSlotTableRuntime {
    SferaWorldSlotRecord slots[401];
    uint32_t active_limit;
};
struct SferaConfigTextRuntime {
    uint8_t owned_text[0x00258240];
    uint32_t current_text;
    uint32_t text_length;
    char format_scratch[512];
    char parser_path[1024];
};
struct SferaPlantingEntry {
    char name[20];
    uint32_t value;
    uint32_t radius;
};
struct SferaPlantingRecord {
    uint32_t descriptor;
    SferaPlantingEntry entries[40];
    uint32_t count;
};
struct SferaPlantingTableRuntime {
    SferaPlantingRecord records[100];
};
struct SferaStaticRenderLookupRuntime {
    float normalized_levels[7];
    float command_samples[kRenderSampleCount];
    float view_phase;
    uint16_t packed_format_code;
    uint16_t reserved_1e;
    uint32_t sample_state;
    uint32_t sample_flags[kRenderSampleCount];
    uint8_t glyph_presence[kFontLookupGlyphCount];
    uint32_t atlas_resources[kFontLookupGlyphCount][kFontLookupClassCount];
    uint8_t quantization_a[kRenderQuantizationTableSize];
    uint8_t quantization_b[kRenderQuantizationTableSize];
    uint32_t glyph_metrics[kFontLookupGlyphCount][kFontLookupClassCount];
    float projection_scale;
    uint8_t blend_lut[kRenderBlendLutStorageSize];
    uint8_t color_remap_a[256];
    uint8_t color_remap_b[256];
    uint8_t color_remap_c[256];
    uint8_t legacy_crc_low_table[256];
};
struct SferaSpatialIndexRuntime {
    uint32_t ui_sort_indices[kUiSortIndexCount];
    uint32_t quadtree_cells[256 * 256];
    uint32_t quadtree_state;
};
struct SferaStartupCommandLineRuntime {
    char text[0x160];
    uint32_t parser_state;
};
struct SferaCollisionScratchRuntime {
    uint8_t debug_vertices[0x70];
    uint8_t light_candidates[30][0x3C];
    uint16_t dynamic_indices_aux[kDynamicIndexScratchCount];
    uint8_t view_transform[0x568];
};
struct SferaGrassPatternRecord {
    uint32_t id;
    char variants[10][5];
    uint8_t reserved_036[2];
};
struct SferaMbcStaticRuntime {
    uint32_t profile_fallback;
    uint32_t stack_default_values[256];
    SferaU64Words startup_time;
    uint32_t init_marker;
    uint8_t init_flag;
    uint8_t service_flag;
    uint8_t reserved[2];
};
struct SferaViewRenderObjectRuntime {
    uint8_t storage[0x15C];
};
struct SferaViewRenderObjectsRuntime {
    SferaViewRenderObjectRuntime primary;
    SferaViewRenderObjectRuntime alternate;
    uint8_t reset_flag;
};
struct SferaMapGeneratorRuntime {
    uint8_t storage[0x68];
};
struct SferaAlphaMaterialRuntime {
    int32_t selected_slot;
    uint8_t option_a;
    uint8_t option_b;
    uint8_t option_c;
    uint8_t reserved_07;
    float alpha[4];
};
struct SferaClientArrayRuntime {
    SferaAutoBoundsArray e7_records;
    SferaAutoBoundsArray e8_indices;
    SferaAutoBoundsArray e9_indices;
    SferaAutoBoundsArray eb_records;
    SferaAutoBoundsArray ed_indices;
    SferaAutoBoundsArray line_102_indices;
    SferaAutoBoundsArray line_105_records;
    SferaAutoBoundsArray line_6b1_indices;
    SferaAutoBoundsArray line_6b3_indices;
    SferaAutoBoundsArray line_6b4_indices;
    SferaAutoBoundsArray line_6b5_records;
    SferaBoundCheckArray line_124d_records;
    SferaBoundCheckArray line_24de_records;
    SferaBoundCheckArray line_24e0_records;
    SferaBoundCheckArray line_24e2_records;
};
struct SferaRecoveredStaticRuntime {
    uint32_t network_bytes_sent_snapshot;
    uint32_t network_bytes_retried_snapshot;
    uint32_t network_bytes_received_snapshot;
    uint32_t simulation_tick;
    uint32_t vertical_sync_enabled;
    uint32_t memory_warning_as_error;
    uint32_t mbc_stack_table_cursor;
    uint32_t server_number;
    uint32_t loadcount_guard;
    SferaVec3Word mbc_vector_scratch;
    uint8_t mbc_service_object[0x4010];
    float inverse_40;
    SferaBoundCheckArray legacy_light_arrays[3];
    uint32_t view_transition_counter;
    uint32_t view_direction_state;
    SferaGrassPatternRecord grass_patterns[30];
    uint32_t scene_mode;
    uint32_t scene_counter;
    uint8_t scene_lock[24];
    uint32_t input_state_a;
    float cursor_accumulator;
    uint32_t input_state_b;
    uint32_t render_gate;
    uint32_t text_size_height;
    uint32_t client_state_01;
    uint32_t client_state_02;
    uint32_t client_state_03;
    float ui_cell_width;
    float clip_depth;
    uint32_t client_state_04;
    uint32_t client_state_05;
    uint32_t client_state_06;
    uint32_t graphics_state;
    uint32_t font_renderer_state;
    uint32_t render_state_07;
    uint32_t render_state_08;
    uint32_t render_state_09;
    uint32_t render_state_10;
    uint32_t scene_state_07;
    uint32_t scene_state_08;
    uint32_t scene_state_09;
    uint32_t interaction_enabled;
    uint32_t interaction_input_flags;
    uint32_t environment_lookup_result;
    float primary_frame_interval;
    float secondary_frame_interval;
    float transition_factor;
    uint32_t animation_state;
    float animation_phase;
    uint32_t animation_result_b;
    SferaAutoBoundsArray primary_auto_array;
    SferaVec3Word flare_clip_vector;
    SferaAutoBoundsArray secondary_auto_array;
    SferaAutoBoundsArray tertiary_auto_array;
    uint32_t ui_counter_a;
    uint32_t ui_counter_b;
};
struct SferaPendingKeyRuntime {
    uint32_t count;
    uint32_t key_codes[30];
};
struct SferaRelaunchRuntime {
    char argument[0x84];
};
struct SferaWorldRenderQueueRuntime {
    uint32_t entries[0xDAC + 1u];
};

using SferaEffectListenerMap = SferaTreeMapHeader;
struct SferaEffectManagerRuntime {
    uint32_t deferred_lifecycle;
    uint32_t render_cycle;
    uint32_t active_resource_count;
    uint32_t detail_setting;
    uint32_t effects_enabled;
    uint32_t render_slot_count;
    uint32_t particle_random_table;
    uint32_t particle_resource_head;
    uint32_t effect_definition_head;
    uint32_t initialized;
    uint32_t render_sort_indices;
    uint32_t render_index_buffer;
    uint32_t render_batch_buffer;
    uint32_t active_effect_count;
    SferaIntrusiveListHeader active_effects;
    uint32_t generation;
    uint32_t last_processed_generation;
    uint32_t flare_transition;
    uint32_t flare_enabled;
    uint32_t flare_alpha;
    SferaVec3F viewer_position;
    SferaBoundCheckArray render_slots;
    SferaEffectListenerMap effect_listeners;
};

struct SferaMbcValue {
    uint32_t type;
    uint32_t width;
    uint32_t source_id;
    uint32_t range_begin;
    uint32_t range_end;
    uint32_t payload[3];
};
struct SferaMbcExecutionContext {
    uint32_t program_table_base;
    uint32_t instruction_cursor;
    uint32_t bytecode_base;
    uint32_t process_memory_base;
    uint32_t process_index;
    uint32_t program_index;
    uint32_t process_id;
    uint32_t active_process;
};
struct SferaFindData64i32 {
    uint32_t attrib;
    uint32_t reserved_04;
    int64_t time_create;
    int64_t time_access;
    int64_t time_write;
    uint32_t size;
    char name[260];
};
struct SferaMbcFileIndexNode {
    uint32_t next;
    uint32_t prev;
    char name[0x40];
    uint8_t reserved_048[0xC0];
    int64_t checksum;
    uint32_t file_size;
    uint32_t reserved_114;
};

struct SferaMbcModuleMemoryStats {
    uint32_t process_count;
    uint32_t process_memory_bytes;
    uint32_t dynamic_memory_bytes;
};

struct SferaMbcNamedVectorRecord {
    uint32_t values;
    uint32_t size;
    uint32_t reserved_08;
    uint32_t name;
};

struct SferaMbcModuleRecord {
    char name[0x20];
    uint8_t runtime[0x8B8];
};

struct SferaMbcProcessRecord {
    uint8_t file_header_prefix[0x0C];
    uint8_t header_code_0c;
    uint8_t header_code_0d;
    uint8_t header_code_0e;
    uint8_t header_code_0f;
    char name[0x20];
    uint8_t module_key[0x10];
    uint32_t field_040;
    uint32_t module_tag;
    uint32_t bytecode_base;
    uint32_t bytecode_size;
    uint32_t process_memory_base;
    uint32_t process_memory_size;
    uint32_t program_count;
    uint32_t program_table_base;
    uint32_t field_060;
    uint32_t auxiliary_record_count;
    uint32_t auxiliary_record_table;
    int32_t chain_prev_index;
    int32_t chain_next_index;
    uint16_t program_map_a[4];
    uint16_t program_map_b[4];
    uint32_t field_084;
    uint32_t field_088;
    uint32_t field_08c;
    uint32_t field_090;
    uint32_t flags;
    uint8_t reserved_098[0x02];
    uint8_t field_09a[0x04];
    uint8_t reserved_09e[0x02];
    uint32_t owned_block_a;
    uint32_t cleanup_entries;
    uint32_t cleanup_entry_count;
    uint32_t cleanup_capacity;
    uint32_t owned_block_b;
    uint32_t process_id;
    uint8_t state_byte_b8;
    uint8_t execution_linked;
    uint8_t reserved_0ba[0x02];
    uint32_t field_0bc;
    uint32_t field_0c0;
    uint32_t workspace_base;
    int32_t execution_prev_index;
    int32_t execution_next_index;
    uint32_t module_record_base;
    uint32_t field_0d4;
    int32_t field_0d8;
    uint8_t reserved_0dc[0xFC];
    uint8_t execution_scratch[0xFC];
    uint16_t code_range_ids[8];
    uint32_t code_range_begin[8];
    uint32_t code_range_size[8];
    uint32_t code_range_memory_offset[8];
    uint16_t code_range_count;
    uint16_t reserved_346;
};

struct SferaMbcValueStackStorage {
    SferaMbcValue base_slot;
    SferaMbcValue entries[256];
};
struct SferaMbcInterpreterStorage {
    uint32_t send_field_data[4088];
    SferaMbcValueStackStorage value_stack;
    SferaMbcModuleRecord module_records[4096];
};
struct SferaMbcSavedInvocationState {
    uint32_t process_memory_base;
    uint32_t value_stack_size;
    uint32_t argument_cursor;
    uint32_t argument_end;
};

struct SferaConfigParserFrame {
    uint32_t container_begin;
    uint32_t count_or_cursor;
    uint32_t payload_end;
};
struct SferaConfigParserRuntime {
    uint32_t current_value_type;
    uint32_t line_number;
    char token[256];
    uint32_t frame_depth;
    uint32_t open_mode;
    SferaConfigParserFrame frames[20];
    char error_message[256];
};

struct SferaMbcRuntime {
    int32_t execution_chain_tail;
    int32_t execution_chain_head;
    uint32_t execution_chain_count;
    int32_t process_chain_first;
    int32_t process_chain_last;
    uint32_t program_table_base;
    uint32_t shared_buffer_size;
    uint32_t instruction_cursor;
    char file_search_pattern[0x40];
    uint32_t named_vector_cursor;
    char diagnostic_context[0x5E8];
    uint8_t module_link_stream[0x724];
    uint16_t link_workspace_words[80];
    uint32_t argument_count;
    uint32_t argument_end;
    uint32_t process_index;
    uint32_t current_instruction_address;
    uint32_t active_tag;
    SferaFindData64i32 file_find_data;
    SferaFindData64i32 script_find_data;
    char startup_option[0x80];
    uint8_t text_buffer[10000];
    uint32_t call_frame_depth;
    uint32_t module_link_stream_size;
    SferaMbcProcessRecord processes[65536];
    uint32_t process_search_cursor;
    uint32_t instruction_step_count;
    uint32_t link_relocation_offsets[24000];
    uint32_t program_index;
    uint32_t pending_program_index;
    uint32_t dispatch_process_count;
    uint32_t resolved_position_pointer;
    uint32_t file_index_scan_prev;
    uint32_t execution_context_depth;
    uint32_t opcode_handlers[256];
    uint32_t bytecode_base;
    uint32_t registered_object_count;
    SferaMbcExecutionContext execution_context_stack[100];
    uint32_t file_crc32;
    uint32_t argument_cursor;
    uint32_t frame_stack_base[22];
    uint32_t halt_all_requested;
    uint32_t link_relocation_count;
    uint8_t send_field_width[4096];
    uint32_t active_program_record;
    uint32_t value_stack_size;
    uint32_t file_index_current;
    char file_path_buffer[0x40];
    uint8_t file_io_buffer[0x10000];
    uint32_t file_index_scan;
    uint32_t active_process;
    uint32_t registered_objects[2100];
    uint32_t process_memory_base;
    uint32_t file_crc32_table[256];
    char file_normalized_name[0x44];
    uint32_t send_field_count;
    uint32_t execution_failed;
    uint32_t trace_steps_remaining;
    uint8_t current_opcode;
    uint8_t trace_program_header_pending;
    uint8_t trace_process_header_pending;
    uint8_t trace_reserved;
    SferaMbcNamedVectorRecord named_vectors[1000];
    uint8_t shared_buffer[0x258240];
    uint32_t named_vector_count;
    uint32_t file_index_head;
    SferaMbcSavedInvocationState saved_invocation;
};

inline SferaItemArray g_sfera_effect_items{.growth_count = 6000u};
inline SferaItemArray g_sfera_sound_effect_items{.growth_count = 128u};
inline SferaServerWall g_sfera_server_wall{.effect_handle = UINT32_MAX};
inline SferaNetworkRuntime g_sfera_network_runtime{.initialization_result = UINT32_MAX, .server_port = 25858u, .local_port_candidate = 26860u, .connection_slot = UINT32_MAX, .pending_slot = UINT32_MAX, .active_slot = UINT32_MAX, .shutdown_state = UINT32_MAX};
inline SferaDirectPlayRuntime g_sfera_directplay_runtime;
inline SferaNetworkConnectionCheckerRuntime g_sfera_network_connection_checker;
inline SferaNetworkSendRuntime g_sfera_network_send_runtime;
inline SferaFontRuntime g_sfera_font_runtime;
inline SferaCursorManagerRuntime g_sfera_cursor_manager_runtime;
inline SferaSliceReference32 g_sfera_pop_slice_fallback;
inline SferaSliceReference32 g_sfera_pop_sliceup_fallback;
inline SferaInterpreterScratchRuntime g_sfera_interpreter_scratch_runtime;
inline SferaGraphicsRuntime g_sfera_graphics_runtime{.fog_distance = 100.0f, .saved_fog_distance = 50.0f, .lods_enabled = 1u, .hardware_cursor_enabled = 1u, .environment_factor = 0.8500000238418579f, .render_mode_enabled = 1u, .base_microtexture_id = UINT32_MAX, .view_parameter = 0.6460000276565552f, .view_scale = 1.0f, .post_effects_enabled = 1u, .rebuild_percent = UINT32_MAX, .runtime_counter = 2000u, .texture_runtime_id = 1000000u};
inline SferaSceneRenderRuntime g_sfera_scene_render_runtime;
inline SferaMatrix4x4F g_sfera_model_coordinate_matrix;
inline SferaMatrix4x4F g_sfera_character_frame_matrix;
inline SferaBoundsCornersRuntime g_sfera_client_bounds_corners;
inline SferaMatrix4x4F g_sfera_character_rotation_matrix;
inline SferaScreenVertex g_sfera_sky_screen_vertices[120];
inline SferaScreenVertex g_sfera_landscape_screen_vertices[1200];
inline SferaBoundCheckArray g_sfera_character_index_map;
inline SferaBoundCheckArray g_sfera_mesh_partition_indices;
inline SferaGraphicsOptionsRuntime g_sfera_graphics_options_runtime;
inline SferaSphereOptionsRuntime g_sfera_sphere_options_runtime;
inline SferaOptionsDialogRuntime g_sfera_options_dialog_runtime;
inline uint32_t g_sfera_options_dialog_cleanup_state;
inline SferaWindowRuntime g_sfera_window_runtime;
inline SferaInputDeviceRuntime g_sfera_input_device_runtime;
inline SferaScreenClipRuntime g_sfera_screen_clip_runtime;
inline SferaDirectInputRuntime g_sfera_direct_input_runtime;
inline SferaShadowRuntime g_sfera_shadow_runtime;
inline SferaWorldRenderRuntime g_sfera_world_render_runtime;
inline SferaWorldLoadRuntime g_sfera_world_load_runtime;
inline SferaWorldBoundsRuntime g_sfera_world_bounds_runtime;
inline SferaRenderLookupRuntime g_sfera_render_lookup_runtime;
inline SferaLandscapeRenderRuntime g_sfera_landscape_render_runtime;
inline SferaProcessRuntime g_sfera_process_runtime;
inline SferaClientProcessRuntime g_sfera_client_process_runtime;
inline SferaMainRenderRuntime g_sfera_main_render_runtime;
inline SferaSceneControlRuntime g_sfera_scene_control_runtime;
inline SferaMainAuxRuntime g_sfera_main_aux_runtime;
inline SferaLandscapeMapRuntime g_sfera_landscape_map_runtime;
inline SferaSkyRuntime g_sfera_sky_runtime;
inline SferaTextureCacheRuntime g_sfera_texture_cache_runtime;
inline SferaFontAtlasLayoutRuntime g_sfera_font_atlas_layout_runtime;
inline SferaFontAtlasStagingRuntime g_sfera_font_atlas_staging_runtime;
inline SferaPartitionSortRuntime g_sfera_partition_sort_runtime;
inline SferaErrorMessageScratchRuntime g_sfera_error_message_scratch_runtime;
inline SferaMaterialFilterRuntime g_sfera_material_filter_runtime;
inline SferaGrassMapRuntime g_sfera_grass_map_runtime;
inline SferaFontFactoryRuntime g_sfera_font_factory_runtime;
inline SferaPhysicsRuntime g_sfera_physics_runtime;
inline SferaViewGeometryRuntime g_sfera_view_geometry_runtime;
inline SferaViewProjectionScratchRuntime g_sfera_view_projection_scratch_runtime;
inline SferaMatrix4x4F g_sfera_model_transform_scratch_matrix;
inline SferaBoundsCornersRuntime g_sfera_model_bounds_corners;
inline SferaSkyInterpolationRuntime g_sfera_sky_interpolation_runtime;
inline SferaColorExpansionRuntime g_sfera_color_expansion_runtime;
alignas(64) inline SferaSpatialStateRuntime g_sfera_spatial_states[67];
inline SferaUiParseScratchRuntime g_sfera_ui_parse_scratch_runtime;
inline SferaCriticalDiagnosticsRuntime g_sfera_critical_diagnostics_runtime;
inline SferaTerrainNeighborRuntime g_sfera_terrain_neighbor_runtime;
inline SferaLandscapePatchLookupRuntime g_sfera_landscape_patch_lookup_runtime;
inline SferaDebugWindowRuntime g_sfera_debug_window_runtime;
inline SferaLandscapeProbeRuntime g_sfera_landscape_probe_runtime;
inline SferaViewMotionRuntime g_sfera_view_motion_runtime;
inline SferaRenderSampleRuntime g_sfera_render_sample_runtime;
inline SferaSceneVectorRuntime g_sfera_scene_vector_runtime;
inline SferaVec3Word g_sfera_flare_projection;
inline SferaTerrainDiagnosticRuntime g_sfera_terrain_diagnostic_runtime;
inline SferaWorldSlotTableRuntime g_sfera_world_slot_table_runtime;
inline SferaConfigTextRuntime g_sfera_config_text_runtime;
inline SferaPlantingTableRuntime g_sfera_planting_table_runtime;
inline SferaStaticRenderLookupRuntime g_sfera_static_render_lookup_runtime;
inline SferaMbcStaticRuntime g_sfera_mbc_static_runtime;
inline SferaViewRenderObjectsRuntime g_sfera_view_render_objects_runtime;
inline SferaMapGeneratorRuntime g_sfera_map_generator_runtime;
inline SferaAlphaMaterialRuntime g_sfera_alpha_material_runtime;
inline SferaClientArrayRuntime g_sfera_client_array_runtime;
alignas(64) inline uint8_t g_sfera_shadow_object_storage[kTransformBoundsStorageSize];
alignas(64) inline uint8_t g_sfera_options_dialog_object_storage[kTransformBoundsStorageSize];
inline SferaSpatialIndexRuntime g_sfera_spatial_index_runtime;
inline SferaStartupCommandLineRuntime g_sfera_startup_command_line_runtime;
inline SferaCollisionScratchRuntime g_sfera_collision_scratch_runtime;
inline SferaRecoveredStaticRuntime g_sfera_recovered_static_runtime;
inline SferaPendingKeyRuntime g_sfera_pending_key_runtime;
inline SferaRelaunchRuntime g_sfera_relaunch_runtime;
inline SferaWorldRenderQueueRuntime g_sfera_world_render_queue_runtime;
inline SferaViewSpatialRuntime g_sfera_view_spatial_runtime;
inline SferaSpatialBoundsRuntime g_sfera_spatial_bounds_runtime;
inline SferaWorldObjectRuntime g_sfera_world_objects{.max_occupied_object_handle = UINT32_MAX, .controlled_object_handle = UINT32_MAX, .contour_mode = UINT32_MAX};
inline SferaGrassRuntime g_sfera_grass_runtime;
inline SferaLightRuntime g_sfera_light_runtime;
inline SferaLandscapeRuntime g_sfera_landscape_runtime;
inline SferaLandscapeInterpolationRuntime g_sfera_landscape_interpolation_runtime;
inline SferaCollisionRuntime g_sfera_collision_runtime;
inline SferaSceneArrayRuntime g_sfera_scene_array_runtime;
inline SferaSceneBuildRuntime g_sfera_scene_build_runtime;
inline SferaWeatherRuntime g_sfera_weather_runtime;
inline SferaModelRuntime g_sfera_model_runtime;
inline SferaModelRegistryRuntime g_sfera_model_registry_runtime;
inline SferaModelMaterialLookupRuntime g_sfera_model_material_lookup_runtime;
inline uint16_t g_sfera_dynamic_index_scratch[kDynamicIndexScratchCount];
inline SferaNatureRuntime g_sfera_nature_runtime;
inline SferaSoundRuntime g_sfera_sound_runtime;
inline SferaWarningLogRuntime g_sfera_warning_log_runtime;
inline SferaControlOptionsRuntime g_sfera_control_options{.active_slot = UINT32_MAX};
inline SferaSpriteRuntime g_sfera_sprite_runtime{.render_mode = UINT32_MAX};
inline SferaCrashRuntime g_sfera_crash_runtime{.report_pending = 1u};
inline SferaContoursRuntime g_sfera_contours_runtime;
inline SferaDynGreenRuntime g_sfera_dyn_green_runtime;
inline SferaExecutionMonitorRuntime g_sfera_execution_monitor_runtime;
inline SferaErrorLogRuntime g_sfera_error_log_runtime;
inline SferaLogRuntime g_sfera_log_runtime;
inline SferaPacketCodecRuntime g_sfera_packet_codec_runtime;
inline SferaFrameRuntime g_sfera_frame_runtime;
inline SferaHighResolutionClockRuntime g_sfera_high_resolution_clock_runtime;
inline SferaProfilerRuntime g_sfera_profiler_runtime;
inline SferaCrc32Runtime g_sfera_crc32_runtime;
inline SferaUiLoadScratchRuntime g_sfera_ui_load_scratch_runtime;
inline SferaHyperTextScratchRuntime g_sfera_hypertext_scratch_runtime;
inline SferaStringLookupRuntime g_sfera_string_lookup_runtime;
inline SferaAsciiLowerRuntime g_sfera_ascii_lower_runtime;
inline SferaModelLoadScratchRuntime g_sfera_model_load_scratch_runtime;
inline SferaStringUtilityRuntime g_sfera_string_utility_runtime;
inline SferaNetworkProbeRuntime g_sfera_network_probe_runtime;
inline SferaConfigParseScratchRuntime g_sfera_config_parse_scratch_runtime;
inline SferaMusicRuntime g_sfera_music_runtime;
inline SferaContainerDiagnosticsRuntime g_sfera_container_diagnostics_runtime;
inline SferaOleHostAbi g_sfera_ole_host_abi;
inline uint32_t g_sfera_graphics_display_depth_bits = 32u;
inline SferaMainCommandStateRuntime g_sfera_main_command_state_runtime;
inline SferaMainInputStateRuntime g_sfera_main_input_state_runtime;
inline SferaMainViewStateRuntime g_sfera_main_view_state_runtime;
inline SferaMainUiStateRuntime g_sfera_main_ui_state_runtime;
inline uint16_t g_sfera_screen_quad_indices[1800];
inline SferaClientConfigRuntime g_sfera_client_config_runtime;
inline SferaGrassPlacementRuntime g_sfera_grass_placement_runtime;
inline SferaSavedControlledPositionRuntime g_sfera_saved_controlled_position;
inline SferaInterfaceCoreRuntime g_sfera_interface_core_runtime;
inline SferaClientMainScalarRuntime g_sfera_client_main_scalar_runtime;
inline SferaInterScalarRuntime g_sfera_inter_scalar_runtime;
inline SferaTextureSetScalarRuntime g_sfera_texture_set_scalar_runtime;
inline SferaTextureRegistryRuntime g_sfera_texture_registry_runtime;
inline SferaInterfaceRuntime g_sfera_interface_runtime{.primary_gate = 1u, .secondary_gate = 1u, .cross_enabled = 1u, .sounds_enabled = 1u, .description_auto_popup = 1u, .invite_messages = 1u};
inline SferaStdAllocator g_sfera_std_allocator;
inline SferaMemoryRuntime g_sfera_memory_runtime{.allocation_source_file = static_cast<uint32_t>(reinterpret_cast<uintptr_t>("Unknown")), .tracker_primary = 1000000000u, .tracker_floor = 1000000000u, .tracker_ceiling = 1000000000u};
inline SferaMemorySourceHashRuntime g_sfera_memory_source_hash_runtime;
inline SferaAllocationHashRuntime g_sfera_allocation_hash_runtime;
inline SferaDiagnosticLogObjectRuntime g_sfera_log_memory_object;
inline SferaDiagnosticLogObjectRuntime g_sfera_log_warnings_object;
inline SferaDiagnosticLogObjectRuntime g_sfera_log_errors_object;
inline uint8_t g_sfera_diagnostic_log_byte;
inline SferaWin32DialogRegistryRuntime g_sfera_win32_dialog_registry;
inline SferaControlReferenceRegistryRuntime g_sfera_control_reference_registry;
inline SferaCursorTextureRegistryRuntime g_sfera_cursor_texture_registry;
inline uint32_t g_sfera_cursor_texture_registry_guard;
inline SferaD3D9SemanticStateRuntime g_sfera_d3d9_semantic_state;
inline SferaBrowserWindowRuntime g_sfera_browser_window_runtime;
inline SferaMinimapTextureRuntime g_sfera_minimap_texture_runtime;
inline uint32_t g_sfera_control_reference_registry_guard;
inline SferaCrtStartupRuntime g_sfera_crt_startup_runtime;
inline SferaCrashReportRuntime g_sfera_crash_report_runtime;
inline SferaRenderBufferCapacities g_sfera_render_buffer_capacities{.vertex32 = 30000u, .vertex28 = 30000u, .index_primary = 5000u, .index_secondary = 5000u};
inline uint32_t g_sfera_blood_effect_instance;
inline SferaFileRuntime g_sfera_file_runtime;
inline SferaEffectManagerRuntime g_sfera_effect_manager{.deferred_lifecycle = 1u, .render_cycle = 31u, .last_processed_generation = UINT32_MAX};
inline SferaConfigParserRuntime g_sfera_config_parser_runtime;
inline SferaMbcRuntime g_sfera_mbc_runtime_storage;
inline SferaMbcRuntime* g_sfera_mbc_runtime = &g_sfera_mbc_runtime_storage;
inline SferaMbcInterpreterStorage g_sfera_mbc_interpreter_storage;
inline SferaMbcModuleMemoryStats g_sfera_mbc_module_memory_stats[4000];
inline char g_sfera_array_error_buffer[256];
inline SferaMsvcString32 g_sfera_shared_parser_whitespace;
inline SferaMsvcString32 g_sfera_shared_parser_path_separators;
inline SferaMsvcString32 g_sfera_server_parser_whitespace;
inline SferaMsvcString32 g_sfera_server_parser_path_separators;
inline SferaMsvcString32 g_sfera_menu_parser_whitespace;
inline SferaMsvcString32 g_sfera_menu_parser_path_separators;
inline SferaMsvcString32 g_sfera_menu_list_missing_parameter_message;
inline SferaMsvcString32 g_sfera_menu_not_enough_arguments_message;
inline SferaMsvcString32 g_sfera_menu_sprite_not_found_message;

inline uint32_t sfera_calendar_days_in_month(uint32_t month) {
    if (month < 1u || month > 12u) {
        return 0u;
    }
    return 30u + ((month + (month > 7u ? 1u : 0u)) & 1u) - (month == 2u ? 2u : 0u);
}

inline uint32_t sfera_calendar_days_before_month(uint32_t month) {
    if (month < 1u || month > 13u) {
        return 0u;
    }
    uint32_t days = 0u;
    for (uint32_t current = 1u; current < month; ++current) {
        days += sfera_calendar_days_in_month(current);
    }
    return days;
}

namespace lifted {
enum class ImportBehavior : std::uint8_t { generic, float_return, raise_exception, module_handle_a, module_handle_w, module_filename_a, module_filename_w, ci_atan2, ci_pow, ci_acos, ci_asin, ci_atan, ci_cos, ci_exp, ci_sin, ci_sqrt, ci_tan, process_module_argument0 };
}

