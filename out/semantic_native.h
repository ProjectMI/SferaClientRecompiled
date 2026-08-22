#pragma once

/*
 * semantic_native.h
 *
 * Semantic storage surface for the lifted client.
 *
 * Current state:
 *   - source .rdata has no materialized backing store; strings and scalar constants live at their consumers.
 *   - recovered client classes use compiler-generated C++ virtual dispatch; no semantic vtable token layer remains.
 *   - MSVC C++ EH frame metadata and __CxxFrameHandler3 entrypoints are eliminated; lifted throw paths terminate semantically.
 *   - source .data has been lifted into native typed storage; no compatibility mapping of the original .data address space remains.
 *
 * Lifted function shards remain separate only to keep MSVC compile times sane.
 */

#include "lifted_abi.h"
#ifdef __cplusplus
#include "semantic_classes.h"
#endif
#include <stdint.h>
#include <stddef.h>
#include <string.h>

static inline uint32_t sfera_f32_bits(float value) { uint32_t bits; memcpy(&bits, &value, sizeof(bits)); return bits; }

#if defined(__cplusplus)
#define SFERA_STATIC_ASSERT(condition, message) static_assert(condition, message)
#else
#define SFERA_STATIC_ASSERT(condition, message) _Static_assert(condition, message)
#endif

/* ===== Native static storage ===== */
/* Source .data addresses do not survive: all recognized static state lives in native typed storage. */

#ifdef __cplusplus
extern "C" {
#endif

/* Named native import symbols. These are resolved once at startup and are not an emulated IAT. */

extern const SferaMsvcVbtable2 g_sfera_vbtable_basic_ofstream;
extern const SferaMsvcVbtable2 g_sfera_vbtable_basic_ifstream;
extern const SferaMsvcVbtable2 g_sfera_vbtable_basic_ostringstream;
extern uint32_t g_sfera_msvcp100_vtable_basic_filebuf[15];
extern uint32_t g_sfera_msvcp100_vtable_basic_ofstream[1];
extern uint32_t g_sfera_msvcp100_vtable_basic_ifstream[1];
extern uint32_t g_sfera_msvcp100_vtable_basic_stringbuf[15];
extern uint32_t g_sfera_msvcp100_vtable_basic_ostringstream[1];
extern uint32_t g_sfera_legacy_vtable_bad_alloc[2];
extern uint32_t g_sfera_legacy_vtable_com_error[1];
extern const SferaGuid32 g_sfera_guid_direct_input_key;
extern const SferaGuid32 g_sfera_guid_direct_input_x_axis;
extern const SferaGuid32 g_sfera_guid_direct_input_y_axis;
extern const SferaGuid32 g_sfera_guid_direct_input_z_axis;
int sfera_bind_legacy_cpp_vtables(void);
void sfera_initialize_native_storage(void);
uint32_t sfera_cursor_texture_name(uint32_t slot);
extern const SferaGuid32 g_sfera_guid_iid_doc_host_ui_handler;
extern const SferaGuid32 g_sfera_guid_iid_ole_client_site;
extern const SferaGuid32 g_sfera_guid_iid_ole_object;
extern const SferaGuid32 g_sfera_guid_00000114;
extern const SferaGuid32 g_sfera_guid_00000113;
extern const SferaGuid32 g_sfera_guid_00000119;
extern const SferaGuid32 g_sfera_guid_00000127;
extern const SferaGuid32 g_sfera_guid_iid_iunknown;
extern const SferaGuid32 g_sfera_guid_iid_web_browser2;
extern const SferaGuid32 g_sfera_guid_clsid_web_browser;
extern const SferaGuid32 g_sfera_guid_332c4425;

extern uint32_t SFERA_IMPORT_WINMM_timeGetTime;
extern uint32_t SFERA_IMPORT_DINPUT8_DirectInput8Create;
extern uint32_t SFERA_IMPORT_COMCTL32_ordinal_17;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_19;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_16;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_151;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_18;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_116;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_3;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_111;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_4;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_52;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_12;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_11;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_9;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_115;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_2;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_10;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_51;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_23;
extern uint32_t SFERA_IMPORT_WS2_32_ordinal_21;
extern uint32_t SFERA_IMPORT_d3dx9_26_D3DXCreateTexture;
extern uint32_t SFERA_IMPORT_d3dx9_26_D3DXGetShaderConstantTable;
extern uint32_t SFERA_IMPORT_d3dx9_26_D3DXMatrixLookAtRH;
extern uint32_t SFERA_IMPORT_d3dx9_26_D3DXMatrixRotationQuaternion;
extern uint32_t SFERA_IMPORT_d3dx9_26_D3DXCreateCubeTextureFromFileInMemory;
extern uint32_t SFERA_IMPORT_d3dx9_26_D3DXMatrixPerspectiveFovRH;
extern uint32_t SFERA_IMPORT_d3dx9_26_D3DXCreateTextureFromFileInMemoryEx;
extern uint32_t SFERA_IMPORT_d3dx9_26_D3DXMatrixMultiply;
extern uint32_t SFERA_IMPORT_d3d9_Direct3DCreate9;
extern uint32_t SFERA_IMPORT_KERNEL32_IsDebuggerPresent;
extern uint32_t SFERA_IMPORT_KERNEL32_IsProcessorFeaturePresent;
extern uint32_t SFERA_IMPORT_KERNEL32_UnhandledExceptionFilter;
extern uint32_t SFERA_IMPORT_KERNEL32_GetStartupInfoW;
extern uint32_t SFERA_IMPORT_KERNEL32_HeapSetInformation;
extern uint32_t SFERA_IMPORT_KERNEL32_InterlockedCompareExchange;
extern uint32_t SFERA_IMPORT_KERNEL32_InterlockedExchange;
extern uint32_t SFERA_IMPORT_KERNEL32_DecodePointer;
extern uint32_t SFERA_IMPORT_KERNEL32_EncodePointer;
extern uint32_t SFERA_IMPORT_KERNEL32_TryEnterCriticalSection;
extern uint32_t SFERA_IMPORT_KERNEL32_LocalFree;
extern uint32_t SFERA_IMPORT_KERNEL32_SetFilePointer;
extern uint32_t SFERA_IMPORT_KERNEL32_SetUnhandledExceptionFilter;
extern uint32_t SFERA_IMPORT_KERNEL32_Sleep;
extern uint32_t SFERA_IMPORT_KERNEL32_GetLocalTime;
extern uint32_t SFERA_IMPORT_KERNEL32_EnterCriticalSection;
extern uint32_t SFERA_IMPORT_KERNEL32_LeaveCriticalSection;
extern uint32_t SFERA_IMPORT_KERNEL32_CloseHandle;
extern uint32_t SFERA_IMPORT_KERNEL32_TerminateThread;
extern uint32_t SFERA_IMPORT_KERNEL32_WaitForSingleObject;
extern uint32_t SFERA_IMPORT_KERNEL32_GetTickCount;
extern uint32_t SFERA_IMPORT_KERNEL32_SetThreadPriority;
extern uint32_t SFERA_IMPORT_KERNEL32_GetLastError;
extern uint32_t SFERA_IMPORT_KERNEL32_CreateThread;
extern uint32_t SFERA_IMPORT_KERNEL32_UnmapViewOfFile;
extern uint32_t SFERA_IMPORT_KERNEL32_GetExitCodeThread;
extern uint32_t SFERA_IMPORT_KERNEL32_GetCurrentProcess;
extern uint32_t SFERA_IMPORT_KERNEL32_GetCurrentThread;
extern uint32_t SFERA_IMPORT_KERNEL32_InitializeCriticalSection;
extern uint32_t SFERA_IMPORT_KERNEL32_DeleteCriticalSection;
extern uint32_t SFERA_IMPORT_KERNEL32_GlobalFree;
extern uint32_t SFERA_IMPORT_KERNEL32_WideCharToMultiByte;
extern uint32_t SFERA_IMPORT_KERNEL32_GlobalAlloc;
extern uint32_t SFERA_IMPORT_KERNEL32_MultiByteToWideChar;
extern uint32_t SFERA_IMPORT_KERNEL32_ExitProcess;
extern uint32_t SFERA_IMPORT_KERNEL32_GetFileSize;
extern uint32_t SFERA_IMPORT_KERNEL32_ReadFile;
extern uint32_t SFERA_IMPORT_KERNEL32_CreateFileA;
extern uint32_t SFERA_IMPORT_KERNEL32_FindClose;
extern uint32_t SFERA_IMPORT_KERNEL32_FindNextFileA;
extern uint32_t SFERA_IMPORT_KERNEL32_FindFirstFileA;
extern uint32_t SFERA_IMPORT_KERNEL32_Process32Next;
extern uint32_t SFERA_IMPORT_KERNEL32_Process32First;
extern uint32_t SFERA_IMPORT_KERNEL32_CreateToolhelp32Snapshot;
extern uint32_t SFERA_IMPORT_KERNEL32_GetVolumeInformationA;
extern uint32_t SFERA_IMPORT_KERNEL32_MapViewOfFile;
extern uint32_t SFERA_IMPORT_KERNEL32_CreateFileMappingA;
extern uint32_t SFERA_IMPORT_KERNEL32_CreateDirectoryA;
extern uint32_t SFERA_IMPORT_KERNEL32_SetThreadAffinityMask;
extern uint32_t SFERA_IMPORT_KERNEL32_GetExitCodeProcess;
extern uint32_t SFERA_IMPORT_KERNEL32_TerminateProcess;
extern uint32_t SFERA_IMPORT_KERNEL32_CreateProcessA;
extern uint32_t SFERA_IMPORT_KERNEL32_GetSystemDirectoryA;
extern uint32_t SFERA_IMPORT_KERNEL32_QueryPerformanceCounter;
extern uint32_t SFERA_IMPORT_KERNEL32_QueryPerformanceFrequency;
extern uint32_t SFERA_IMPORT_KERNEL32_GetModuleHandleA;
extern uint32_t SFERA_IMPORT_KERNEL32_GlobalUnlock;
extern uint32_t SFERA_IMPORT_KERNEL32_GlobalLock;
extern uint32_t SFERA_IMPORT_KERNEL32_WriteFile;
extern uint32_t SFERA_IMPORT_KERNEL32_lstrlenA;
extern uint32_t SFERA_IMPORT_KERNEL32_GetVersionExA;
extern uint32_t SFERA_IMPORT_KERNEL32_GetCurrentThreadId;
extern uint32_t SFERA_IMPORT_KERNEL32_RaiseException;
extern uint32_t SFERA_IMPORT_KERNEL32_OutputDebugStringA;
extern uint32_t SFERA_IMPORT_KERNEL32_FileTimeToDosDateTime;
extern uint32_t SFERA_IMPORT_KERNEL32_FileTimeToLocalFileTime;
extern uint32_t SFERA_IMPORT_KERNEL32_GlobalMemoryStatus;
extern uint32_t SFERA_IMPORT_KERNEL32_GetSystemInfo;
extern uint32_t SFERA_IMPORT_KERNEL32_lstrcpyA;
extern uint32_t SFERA_IMPORT_KERNEL32_GetModuleFileNameA;
extern uint32_t SFERA_IMPORT_KERNEL32_GetSystemTimeAsFileTime;
extern uint32_t SFERA_IMPORT_KERNEL32_lstrcatA;
extern uint32_t SFERA_IMPORT_KERNEL32_GetCurrentProcessId;
extern uint32_t SFERA_IMPORT_KERNEL32_VirtualQuery;
extern uint32_t SFERA_IMPORT_USER32_BringWindowToTop;
extern uint32_t SFERA_IMPORT_USER32_DestroyWindow;
extern uint32_t SFERA_IMPORT_USER32_GetSystemMetrics;
extern uint32_t SFERA_IMPORT_USER32_SendMessageA;
extern uint32_t SFERA_IMPORT_USER32_UpdateWindow;
extern uint32_t SFERA_IMPORT_USER32_InvalidateRect;
extern uint32_t SFERA_IMPORT_USER32_ShowWindow;
extern uint32_t SFERA_IMPORT_USER32_ReleaseDC;
extern uint32_t SFERA_IMPORT_USER32_GetDC;
extern uint32_t SFERA_IMPORT_USER32_GetWindowLongA;
extern uint32_t SFERA_IMPORT_USER32_GetClientRect;
extern uint32_t SFERA_IMPORT_USER32_SetWindowLongA;
extern uint32_t SFERA_IMPORT_USER32_DefWindowProcA;
extern uint32_t SFERA_IMPORT_USER32_MessageBeep;
extern uint32_t SFERA_IMPORT_USER32_TranslateMessage;
extern uint32_t SFERA_IMPORT_USER32_DispatchMessageA;
extern uint32_t SFERA_IMPORT_USER32_PeekMessageA;
extern uint32_t SFERA_IMPORT_USER32_MessageBoxA;
extern uint32_t SFERA_IMPORT_USER32_ShowCursor;
extern uint32_t SFERA_IMPORT_USER32_SetCursorPos;
extern uint32_t SFERA_IMPORT_USER32_GetCursorPos;
extern uint32_t SFERA_IMPORT_USER32_ScreenToClient;
extern uint32_t SFERA_IMPORT_USER32_SetCursor;
extern uint32_t SFERA_IMPORT_USER32_ClipCursor;
extern uint32_t SFERA_IMPORT_USER32_DestroyCursor;
extern uint32_t SFERA_IMPORT_USER32_CreateIconIndirect;
extern uint32_t SFERA_IMPORT_USER32_wsprintfA;
extern uint32_t SFERA_IMPORT_USER32_wvsprintfA;
extern uint32_t SFERA_IMPORT_USER32_CreateDialogParamA;
extern uint32_t SFERA_IMPORT_USER32_SetClassLongA;
extern uint32_t SFERA_IMPORT_USER32_GetDlgCtrlID;
extern uint32_t SFERA_IMPORT_USER32_GetWindowTextA;
extern uint32_t SFERA_IMPORT_USER32_SetWindowTextA;
extern uint32_t SFERA_IMPORT_USER32_EnableWindow;
extern uint32_t SFERA_IMPORT_USER32_IsDialogMessageA;
extern uint32_t SFERA_IMPORT_USER32_GetDlgItem;
extern uint32_t SFERA_IMPORT_USER32_IsClipboardFormatAvailable;
extern uint32_t SFERA_IMPORT_USER32_OpenClipboard;
extern uint32_t SFERA_IMPORT_USER32_GetClipboardData;
extern uint32_t SFERA_IMPORT_USER32_CloseClipboard;
extern uint32_t SFERA_IMPORT_USER32_SetFocus;
extern uint32_t SFERA_IMPORT_USER32_ClientToScreen;
extern uint32_t SFERA_IMPORT_USER32_CallWindowProcA;
extern uint32_t SFERA_IMPORT_USER32_FindWindowA;
extern uint32_t SFERA_IMPORT_USER32_LoadIconA;
extern uint32_t SFERA_IMPORT_USER32_LoadCursorA;
extern uint32_t SFERA_IMPORT_USER32_RegisterClassExA;
extern uint32_t SFERA_IMPORT_USER32_PostQuitMessage;
extern uint32_t SFERA_IMPORT_USER32_SetRect;
extern uint32_t SFERA_IMPORT_USER32_AdjustWindowRect;
extern uint32_t SFERA_IMPORT_USER32_CreateWindowExA;
extern uint32_t SFERA_IMPORT_USER32_UnregisterClassA;
extern uint32_t SFERA_IMPORT_GDI32_GetObjectType;
extern uint32_t SFERA_IMPORT_GDI32_CreateBitmap;
extern uint32_t SFERA_IMPORT_GDI32_GetStockObject;
extern uint32_t SFERA_IMPORT_GDI32_CreateCompatibleDC;
extern uint32_t SFERA_IMPORT_GDI32_CreateCompatibleBitmap;
extern uint32_t SFERA_IMPORT_GDI32_GetDIBits;
extern uint32_t SFERA_IMPORT_GDI32_SelectObject;
extern uint32_t SFERA_IMPORT_GDI32_DeleteDC;
extern uint32_t SFERA_IMPORT_GDI32_SetPixel;
extern uint32_t SFERA_IMPORT_GDI32_DeleteObject;
extern uint32_t SFERA_IMPORT_ADVAPI32_GetUserNameA;
extern uint32_t SFERA_IMPORT_SHELL32_ShellExecuteA;
extern uint32_t SFERA_IMPORT_ole32_CoInitialize;
extern uint32_t SFERA_IMPORT_ole32_CoCreateInstance;
extern uint32_t SFERA_IMPORT_ole32_CoUninitialize;
extern uint32_t SFERA_IMPORT_ole32_OleCreate;
extern uint32_t SFERA_IMPORT_ole32_OleSetContainedObject;
extern uint32_t SFERA_IMPORT_OLEAUT32_ordinal_6;
extern uint32_t SFERA_IMPORT_OLEAUT32_ordinal_9;
extern uint32_t SFERA_IMPORT_OLEAUT32_ordinal_2;
extern uint32_t SFERA_IMPORT_OLEAUT32_ordinal_8;
extern uint32_t SFERA_IMPORT_dbghelp_SymFromAddr;
extern uint32_t SFERA_IMPORT_dbghelp_SymGetModuleBase;
extern uint32_t SFERA_IMPORT_dbghelp_SymFunctionTableAccess;
extern uint32_t SFERA_IMPORT_dbghelp_StackWalk;
extern uint32_t SFERA_IMPORT_dbghelp_SymGetLineFromAddr;
extern uint32_t SFERA_IMPORT_dbghelp_SymSetOptions;
extern uint32_t SFERA_IMPORT_dbghelp_SymInitialize;
extern uint32_t SFERA_IMPORT_dbghelp_MiniDumpWriteDump;
extern uint32_t SFERA_IMPORT_Sound_SI_SetHardwareMixing_YAX_N_Z;
extern uint32_t SFERA_IMPORT_Sound_CSoundListener_GetOrientation;
extern uint32_t SFERA_IMPORT_Sound_CSoundListener_SetPosition;
extern uint32_t SFERA_IMPORT_Sound_CSoundListener_SetVelocity;
extern uint32_t SFERA_IMPORT_Sound_CSoundListener_SetOrientation;
extern uint32_t SFERA_IMPORT_Sound_CSoundInterface_UpdateSettings;
extern uint32_t SFERA_IMPORT_Sound_CSound_SetAllParameters;
extern uint32_t SFERA_IMPORT_Sound_CSound_LoadSound;
extern uint32_t SFERA_IMPORT_Sound_CSound_SetVolume;
extern uint32_t SFERA_IMPORT_Sound_SI_GetStreamVolume_YAHXZ;
extern uint32_t SFERA_IMPORT_Sound_CSound_Rewind;
extern uint32_t SFERA_IMPORT_Sound_CSound_Stop;
extern uint32_t SFERA_IMPORT_Sound_CSound_ctor;
extern uint32_t SFERA_IMPORT_Sound_SI_CreateInterface_YAPAVCSoundInterface_PAUHWND_HKK_Z;
extern uint32_t SFERA_IMPORT_Sound_CSound_SetPosition;
extern uint32_t SFERA_IMPORT_Sound_CSound_GetPlayTimepos;
extern uint32_t SFERA_IMPORT_Sound_CSound_IsSoundPlaying;
extern uint32_t SFERA_IMPORT_Sound_CSound_SetPlayTimepos;
extern uint32_t SFERA_IMPORT_Sound_CSound_Play;
extern uint32_t SFERA_IMPORT_Sound_SI_GetInterface_YAPAVCSoundInterface_XZ;
extern uint32_t SFERA_IMPORT_Sound_CSoundStream_SetDecodeSignal;
extern uint32_t SFERA_IMPORT_Sound_CSoundStream_SeekToTime;
extern uint32_t SFERA_IMPORT_Sound_CSoundStream_SetPlaySignal;
extern uint32_t SFERA_IMPORT_Sound_CSoundStream_Stop;
extern uint32_t SFERA_IMPORT_Sound_CSoundStream_IsStreamPlaying;
extern uint32_t SFERA_IMPORT_Sound_CSoundStream_PlayEx;
extern uint32_t SFERA_IMPORT_Sound_SI_Close_YAXXZ;
extern uint32_t SFERA_IMPORT_Sound_SI_SetLogFile_YAXPBD_Z;
extern uint32_t SFERA_IMPORT_Sound_CSound_SetVelocity;
extern uint32_t SFERA_IMPORT_Sound_SI_SetStreamVolume_YAXH_Z;
extern uint32_t SFERA_IMPORT_Sound_SI_StreamCreateFile_YAKPBDK_Z;
extern uint32_t SFERA_IMPORT_Sound_SI_StreamFree_YAXK_Z;
extern uint32_t SFERA_IMPORT_Sound_SI_GetHardwareMixing_YA_NXZ;
extern uint32_t SFERA_IMPORT_Sound_CSound_dtor;
extern uint32_t SFERA_IMPORT_MSVCR100_initterm;
extern uint32_t SFERA_IMPORT_MSVCR100_acmdln;
extern uint32_t SFERA_IMPORT_MSVCR100_ismbblead;
extern uint32_t SFERA_IMPORT_MSVCR100_XcptFilter;
extern uint32_t SFERA_IMPORT_MSVCR100_exit;
extern uint32_t SFERA_IMPORT_MSVCR100_cexit;
extern uint32_t SFERA_IMPORT_MSVCR100_getmainargs;
extern uint32_t SFERA_IMPORT_MSVCR100_amsg_exit;
extern uint32_t SFERA_IMPORT_MSVCR100_terminate_YAXXZ;
extern uint32_t SFERA_IMPORT_MSVCR100_onexit;
extern uint32_t SFERA_IMPORT_MSVCR100_lock;
extern uint32_t SFERA_IMPORT_MSVCR100_dllonexit;
extern uint32_t SFERA_IMPORT_MSVCR100_initterm_e;
extern uint32_t SFERA_IMPORT_MSVCR100_configthreadlocale;
extern uint32_t SFERA_IMPORT_MSVCR100_setusermatherr;
extern uint32_t SFERA_IMPORT_MSVCR100_commode;
extern uint32_t SFERA_IMPORT_MSVCR100_fmode;
extern uint32_t SFERA_IMPORT_MSVCR100_set_app_type;
extern uint32_t SFERA_IMPORT_MSVCR100_crt_debugger_hook;
extern uint32_t SFERA_IMPORT_MSVCR100_type_info_type_info_dtor_internal_method;
extern uint32_t SFERA_IMPORT_MSVCR100_invoke_watson;
extern uint32_t SFERA_IMPORT_MSVCR100_isalnum;
extern uint32_t SFERA_IMPORT_MSVCR100_atoi;
extern uint32_t SFERA_IMPORT_MSVCR100_atof;
extern uint32_t SFERA_IMPORT_MSVCR100_utime64;
extern uint32_t SFERA_IMPORT_MSVCR100_stat64i32;
extern uint32_t SFERA_IMPORT_MSVCR100_strnicmp;
extern uint32_t SFERA_IMPORT_MSVCR100_controlfp_s;
extern uint32_t SFERA_IMPORT_MSVCR100_toupper;
extern uint32_t SFERA_IMPORT_MSVCR100_unlock;
extern uint32_t SFERA_IMPORT_MSVCR100_printf;
extern uint32_t SFERA_IMPORT_MSVCR100_calloc;
extern uint32_t SFERA_IMPORT_MSVCR100_isdigit;
extern uint32_t SFERA_IMPORT_MSVCR100_fsetpos;
extern uint32_t SFERA_IMPORT_MSVCR100_fseeki64;
extern uint32_t SFERA_IMPORT_MSVCR100_CIasin;
extern uint32_t SFERA_IMPORT_MSVCR100_isalpha;
extern uint32_t SFERA_IMPORT_MSVCR100_unlink;
extern uint32_t SFERA_IMPORT_MSVCR100_execl;
extern uint32_t SFERA_IMPORT_MSVCR100_fflush;
extern uint32_t SFERA_IMPORT_MSVCR100_floor;
extern uint32_t SFERA_IMPORT_MSVCR100_CIatan;
extern uint32_t SFERA_IMPORT_MSVCR100_CIacos;
extern uint32_t SFERA_IMPORT_MSVCR100_fgetpos;
extern uint32_t SFERA_IMPORT_MSVCR100_memcpy_s;
extern uint32_t SFERA_IMPORT_MSVCR100_setvbuf;
extern uint32_t SFERA_IMPORT_MSVCR100_unlock_file;
extern uint32_t SFERA_IMPORT_MSVCR100_lock_file;
extern uint32_t SFERA_IMPORT_MSVCR100_ungetc;
extern uint32_t SFERA_IMPORT_MSVCR100_fputc;
extern uint32_t SFERA_IMPORT_MSVCR100_bad_cast_ctor;
extern uint32_t SFERA_IMPORT_MSVCR100_bad_cast_dtor;
extern uint32_t SFERA_IMPORT_MSVCR100_bad_cast_ctor_272;
extern uint32_t SFERA_IMPORT_MSVCR100_strtok;
extern uint32_t SFERA_IMPORT_MSVCR100_fgetc;
extern uint32_t SFERA_IMPORT_MSVCR100_feof;
extern uint32_t SFERA_IMPORT_MSVCR100_CItan;
extern uint32_t SFERA_IMPORT_MSVCR100_spawnl;
extern uint32_t SFERA_IMPORT_MSVCR100_mkdir;
extern uint32_t SFERA_IMPORT_MSVCR100_getenv;
extern uint32_t SFERA_IMPORT_MSVCR100_atoi64;
extern uint32_t SFERA_IMPORT_MSVCR100_rename;
extern uint32_t SFERA_IMPORT_MSVCR100_chsize;
extern uint32_t SFERA_IMPORT_MSVCR100_fstat64i32;
extern uint32_t SFERA_IMPORT_MSVCR100_locking;
extern uint32_t SFERA_IMPORT_MSVCR100_sopen_YAHPBDHHH_Z;
extern uint32_t SFERA_IMPORT_MSVCR100_vscprintf;
extern uint32_t SFERA_IMPORT_MSVCR100_vsnprintf;
extern uint32_t SFERA_IMPORT_MSVCR100_exit_288;
extern uint32_t SFERA_IMPORT_MSVCR100_msize;
extern uint32_t SFERA_IMPORT_MSVCR100_strtime;
extern uint32_t SFERA_IMPORT_MSVCR100_fputs;
extern uint32_t SFERA_IMPORT_MSVCR100_strrchr;
extern uint32_t SFERA_IMPORT_MSVCR100_futime64;
extern uint32_t SFERA_IMPORT_MSVCR100_mktime64;
extern uint32_t SFERA_IMPORT_MSVCR100_difftime64;
extern uint32_t SFERA_IMPORT_MSVCR100_CIexp;
extern uint32_t SFERA_IMPORT_MSVCR100_CIatan2;
extern uint32_t SFERA_IMPORT_MSVCR100_strstr;
extern uint32_t SFERA_IMPORT_MSVCR100_vswprintf;
extern uint32_t SFERA_IMPORT_MSVCR100_memchr;
extern uint32_t SFERA_IMPORT_MSVCR100_access;
extern uint32_t SFERA_IMPORT_MSVCR100_strerror;
extern uint32_t SFERA_IMPORT_MSVCR100_remove;
extern uint32_t SFERA_IMPORT_MSVCR100_fread;
extern uint32_t SFERA_IMPORT_MSVCR100_fwrite;
extern uint32_t SFERA_IMPORT_MSVCR100_asctime;
extern uint32_t SFERA_IMPORT_MSVCR100_vsprintf;
extern uint32_t SFERA_IMPORT_MSVCR100_stricmp;
extern uint32_t SFERA_IMPORT_MSVCR100_purecall;
extern uint32_t SFERA_IMPORT_MSVCR100_close;
extern uint32_t SFERA_IMPORT_MSVCR100_read;
extern uint32_t SFERA_IMPORT_MSVCR100_open_YAHPBDHH_Z;
extern uint32_t SFERA_IMPORT_MSVCR100_write;
extern uint32_t SFERA_IMPORT_MSVCR100_lseek;
extern uint32_t SFERA_IMPORT_MSVCR100_memcpy;
extern uint32_t SFERA_IMPORT_MSVCR100_memset;
extern uint32_t SFERA_IMPORT_MSVCR100_sprintf;
extern uint32_t SFERA_IMPORT_MSVCR100_chmod;
extern uint32_t SFERA_IMPORT_MSVCR100_sscanf;
extern uint32_t SFERA_IMPORT_MSVCR100_exception_ctor;
extern uint32_t SFERA_IMPORT_MSVCR100_exception_what;
extern uint32_t SFERA_IMPORT_MSVCR100_exception_dtor;
extern uint32_t SFERA_IMPORT_MSVCR100_memmove;
extern uint32_t SFERA_IMPORT_MSVCR100_exception_ctor_325;
extern uint32_t SFERA_IMPORT_MSVCR100_ldiv;
extern uint32_t SFERA_IMPORT_MSVCR100_vfprintf;
extern uint32_t SFERA_IMPORT_MSVCR100_fprintf;
extern uint32_t SFERA_IMPORT_MSVCR100_ftell;
extern uint32_t SFERA_IMPORT_MSVCR100_fseek;
extern uint32_t SFERA_IMPORT_MSVCR100_fclose;
extern uint32_t SFERA_IMPORT_MSVCR100_fopen;
extern uint32_t SFERA_IMPORT_MSVCR100_snprintf;
extern uint32_t SFERA_IMPORT_MSVCR100_rand;
extern uint32_t SFERA_IMPORT_MSVCR100_errno;
extern uint32_t SFERA_IMPORT_MSVCR100_CIsqrt;
extern uint32_t SFERA_IMPORT_MSVCR100_CIcos;
extern uint32_t SFERA_IMPORT_MSVCR100_CIsin;
extern uint32_t SFERA_IMPORT_MSVCR100_CIpow;
extern uint32_t SFERA_IMPORT_MSVCR100_findclose;
extern uint32_t SFERA_IMPORT_MSVCR100_findnext64i32;
extern uint32_t SFERA_IMPORT_MSVCR100_findfirst64i32;
extern uint32_t SFERA_IMPORT_MSVCR100_localtime64;
extern uint32_t SFERA_IMPORT_MSVCR100_time64;
extern uint32_t SFERA_IMPORT_MSVCR100_strncpy;
extern uint32_t SFERA_IMPORT_MSVCR100_strftime;
extern uint32_t SFERA_IMPORT_MSVCR100_strchr;
extern uint32_t SFERA_IMPORT_MSVCR100_filelength;
extern uint32_t SFERA_IMPORT_MSVCR100_malloc;
extern uint32_t SFERA_IMPORT_MSVCR100_free;
extern uint32_t SFERA_IMPORT_MSVCR100_tolower;
extern uint32_t SFERA_IMPORT_MSVCR100_strncmp;
extern uint32_t SFERA_IMPORT_MSVCR100_qsort;
extern uint32_t SFERA_IMPORT_MSVCR100_realloc;
extern uint32_t SFERA_IMPORT_MSVCR100_srand;
extern uint32_t SFERA_IMPORT_MSVCR100_fgets;
extern uint32_t SFERA_IMPORT_MSVCP100_6_basic_ostream_DU_char_traits_D_std_std_QAEAAV01_I_Z;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sgetc;
extern uint32_t SFERA_IMPORT_MSVCP100_std_BADOFF;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_imbue;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sync;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_dtor;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_ios_dtor;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_ctor;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_ios_vftable;
extern uint32_t SFERA_IMPORT_MSVCP100_ios_base_vftable;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sbumpc;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_snextc;
extern uint32_t SFERA_IMPORT_MSVCP100_codecvt_unshift;
extern uint32_t SFERA_IMPORT_MSVCP100_codecvt_in;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_setg;
extern uint32_t SFERA_IMPORT_MSVCP100_codecvt_out;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_ios_clear;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sputc;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_sputn;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_ios_setstate;
extern uint32_t SFERA_IMPORT_MSVCP100_std_uncaught_exception;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_Osfx;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_flush;
extern uint32_t SFERA_IMPORT_MSVCP100_std_Fiopen;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_getloc;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_xsputn;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_xsgetn;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_showmanyc;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_ctor;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_dtor;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_istream_Ipfx;
extern uint32_t SFERA_IMPORT_MSVCP100_Lockit_ctor;
extern uint32_t SFERA_IMPORT_MSVCP100_codecvt_id;
extern uint32_t SFERA_IMPORT_MSVCP100_Lockit_dtor;
extern uint32_t SFERA_IMPORT_MSVCP100_id_Id_cnt;
extern uint32_t SFERA_IMPORT_MSVCP100_codecvt_Getcat;
extern uint32_t SFERA_IMPORT_MSVCP100_facet_Incref;
extern uint32_t SFERA_IMPORT_MSVCP100_codecvt_base_always_noconv;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_Init;
extern uint32_t SFERA_IMPORT_MSVCP100_locale_Getgloballocale;
extern uint32_t SFERA_IMPORT_MSVCP100_facet_Decref;
extern uint32_t SFERA_IMPORT_MSVCP100_Container_base12_dtor;
extern uint32_t SFERA_IMPORT_MSVCP100_std_Xlength_error;
extern uint32_t SFERA_IMPORT_MSVCP100_std_Xout_of_range;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_Pninc;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_setbuf;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_uflow;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_Unlock;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_streambuf_Lock;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_istream_vftable;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_istream_ctor;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_istream_dtor;
extern uint32_t SFERA_IMPORT_MSVCP100_ios_base_Ios_base_dtor;
extern uint32_t SFERA_IMPORT_MSVCP100_basic_ostream_vftable;
extern uint32_t g_sfera_security_cookie;
extern uint32_t g_sfera_security_cookie_complement;
extern uint32_t g_sfera_log_first_write;

#ifdef __cplusplus
}
#endif

#if defined(_MSC_VER)
#define SFERA_STATIC_INLINE static __forceinline
#else
#define SFERA_STATIC_INLINE static inline __attribute__((always_inline))
#endif

#define SFERA_ELIMINATED_RDATA_BEGIN UINT32_C(0x004FD000)
#define SFERA_ELIMINATED_RDATA_SIZE UINT32_C(0x00022E00)




/* ===== Resolved semantic native state ===== */
/* Resolved state lives in native C storage. Source virtual addresses remain only for regions
 * whose semantics have not yet been lifted. */

typedef struct SferaItemArray { uint32_t block_vector_begin; uint32_t block_vector_end; uint32_t block_vector_capacity_end; uint32_t reserved; uint32_t free_items; uint32_t free_count; uint32_t growth_count; } SferaItemArray;
typedef struct SferaServerWall { uint32_t wall_data; uint32_t reserved_04; uint32_t wall_count; uint32_t generated_data; uint32_t generated_points; uint32_t segment_count; uint32_t effect_handle; } SferaServerWall;
typedef struct SferaDirectPlayCaps32 { uint32_t words[12]; } SferaDirectPlayCaps32;
typedef struct SferaDpnCapsRuntime { uint32_t size; uint32_t flags; uint32_t connect_timeout_ms; uint32_t connect_retries; uint32_t timeout_until_keepalive_ms; } SferaDpnCapsRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaDpnCapsRuntime) == 0x14u, "DPN_CAPS ABI size");
typedef struct SferaDpnBufferDescRuntime { uint32_t buffer_size; uint32_t buffer_data; } SferaDpnBufferDescRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaDpnBufferDescRuntime) == 0x08u, "DPN_BUFFER_DESC ABI size");
typedef struct SferaDpnConnectionInfoRuntime { uint32_t size; uint32_t round_trip_latency_ms; uint32_t throughput_bps; uint32_t peak_throughput_bps; uint32_t bytes_sent_guaranteed; uint32_t packets_sent_guaranteed; uint32_t bytes_sent_non_guaranteed; uint32_t packets_sent_non_guaranteed; uint32_t bytes_retried; uint32_t packets_retried; uint32_t bytes_dropped; uint32_t packets_dropped; uint32_t messages_transmitted_high_priority; uint32_t messages_timed_out_high_priority; uint32_t messages_transmitted_normal_priority; uint32_t messages_timed_out_normal_priority; uint32_t messages_transmitted_low_priority; uint32_t messages_timed_out_low_priority; uint32_t bytes_received_guaranteed; uint32_t packets_received_guaranteed; uint32_t bytes_received_non_guaranteed; uint32_t packets_received_non_guaranteed; uint32_t messages_received; } SferaDpnConnectionInfoRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaDpnConnectionInfoRuntime) == 0x5Cu, "DPN_CONNECTION_INFO ABI size");
SFERA_STATIC_ASSERT(offsetof(SferaDpnConnectionInfoRuntime, bytes_sent_guaranteed) == 0x10u, "DPN_CONNECTION_INFO sent offset");
SFERA_STATIC_ASSERT(offsetof(SferaDpnConnectionInfoRuntime, bytes_retried) == 0x20u, "DPN_CONNECTION_INFO retried offset");
SFERA_STATIC_ASSERT(offsetof(SferaDpnConnectionInfoRuntime, bytes_received_guaranteed) == 0x48u, "DPN_CONNECTION_INFO received offset");
typedef struct SferaCounter64Words { uint32_t low; uint32_t high; } SferaCounter64Words;
typedef struct SferaNetworkTransportRuntime { uint32_t mode; uint8_t transport_flag; uint8_t receive_busy; uint8_t receive_corrupted; uint8_t reserved_07; uint32_t primary_address; uint32_t secondary_address; uint32_t sent_packet_count; SferaCounter64Words sent_bytes; uint32_t received_packet_count; uint32_t receive_read_index; SferaCounter64Words received_bytes; uint32_t receive_write_index; uint32_t reserved_30; } SferaNetworkTransportRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaNetworkTransportRuntime) == 0x34u, "network transport ABI size");
SFERA_STATIC_ASSERT(offsetof(SferaNetworkTransportRuntime, primary_address) == 0x08u, "network transport address offset");
SFERA_STATIC_ASSERT(offsetof(SferaNetworkTransportRuntime, receive_read_index) == 0x20u, "network transport read index offset");
typedef struct SferaDirectPlayRuntime { uint32_t peer; SferaDpnCapsRuntime caps; uint8_t critical_section[24]; SferaDpnBufferDescRuntime send_buffer; uint32_t send_async_handle; SferaDpnConnectionInfoRuntime connection_info; SferaNetworkTransportRuntime transport; } SferaDirectPlayRuntime;
typedef struct SferaNetworkMessageSlot { uint8_t bytes[0x1A8]; } SferaNetworkMessageSlot;
typedef struct SferaNetworkRuntime { uint32_t initialization_result; uint32_t server_port; uint32_t local_port_candidate; uint32_t connection_slot; uint32_t pending_slot; uint32_t active_slot; uint32_t shutdown_state; uint8_t timeout_marker_pending; uint8_t net_log_has_error; uint8_t network_error_active; uint8_t initialized; uint32_t bytes_sent_delta; uint32_t bytes_retried_delta; uint32_t bytes_received_delta; uint32_t error_budget; SferaDirectPlayCaps32 directplay_caps; uint32_t message_call_scratch; SferaNetworkMessageSlot message_slots[3048]; } SferaNetworkRuntime;
typedef struct SferaNetworkConnectionCheckerRuntime { uint32_t instance; } SferaNetworkConnectionCheckerRuntime;
typedef struct SferaNetworkSendRuntime { uint8_t critical_section[0x18]; } SferaNetworkSendRuntime;
typedef struct SferaFontGlyphRuntime { uint32_t texture_index; float u; float v; uint32_t defined; } SferaFontGlyphRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaFontGlyphRuntime) == 0x10u, "font glyph ABI size");
typedef struct SferaFontRuntime { char language_suffix[8]; uint32_t renderer; SferaFontGlyphRuntime glyphs[256]; } SferaFontRuntime;
#define SFERA_FONT_QUAD_INDEX_COUNT UINT32_C(2400)
typedef struct SferaFontFactoryRuntime { uint16_t quad_indices[SFERA_FONT_QUAD_INDEX_COUNT]; uint32_t vertex_count; uint32_t vertex_buffer; uint32_t fonts_begin; uint32_t fonts_end; uint32_t fonts_capacity; } SferaFontFactoryRuntime;
SFERA_STATIC_ASSERT(sizeof(((SferaFontFactoryRuntime*)0)->quad_indices) == 0x12C0u, "font quad index scratch source span");
SFERA_STATIC_ASSERT(offsetof(SferaFontFactoryRuntime, vertex_count) == 0x12C0u, "font factory vertex count offset");
SFERA_STATIC_ASSERT(offsetof(SferaFontRuntime, renderer) == 0x08u, "font renderer source offset");
SFERA_STATIC_ASSERT(offsetof(SferaFontRuntime, glyphs) == 0x0Cu, "font glyph table source offset");
SFERA_STATIC_ASSERT(sizeof(SferaFontRuntime) == 0x100Cu, "font runtime source span");
SFERA_STATIC_ASSERT(offsetof(SferaFontRuntime, glyphs) + 124u * sizeof(SferaFontGlyphRuntime) + offsetof(SferaFontGlyphRuntime, defined) == 0x7D8u, "undefined-symbol glyph source offset");
typedef struct SferaCursorManagerRuntime { uint8_t object[8]; uint32_t active_cursor; uint32_t initialized_flags; } SferaCursorManagerRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaCursorManagerRuntime) == 0x10u, "cursor manager runtime size");
typedef struct SferaSliceReference32 { uint32_t base; uint32_t begin; uint32_t end; } SferaSliceReference32;
SFERA_STATIC_ASSERT(sizeof(SferaSliceReference32) == 0x0Cu, "slice reference ABI size");
typedef struct SferaInterpreterScratchRuntime { uint32_t diagnostic_step_counter; uint32_t network_poll_counter; uint32_t item_lookup_result; } SferaInterpreterScratchRuntime;
typedef struct SferaGraphicsRuntime { float fog_distance; float saved_fog_distance; uint32_t lods_enabled; uint32_t hardware_cursor_enabled; float environment_factor; uint8_t render_mode_enabled; uint32_t base_microtexture_id; float view_parameter; float view_scale; uint32_t post_effects_enabled; uint32_t rebuild_percent; uint32_t runtime_counter; uint32_t texture_runtime_id; float base_render_factor; uint32_t display_width; uint32_t display_height; uint32_t d3d9_device; } SferaGraphicsRuntime;
typedef struct SferaBoundCheckArray { uint32_t data; uint32_t capacity; char debug_file[32]; uint32_t debug_line; } SferaBoundCheckArray;
SFERA_STATIC_ASSERT(sizeof(SferaBoundCheckArray) == 0x2Cu, "SferaBoundCheckArray ABI size");
SFERA_STATIC_ASSERT(offsetof(SferaBoundCheckArray, debug_file) == 0x08u, "SferaBoundCheckArray debug file offset");
SFERA_STATIC_ASSERT(offsetof(SferaBoundCheckArray, debug_line) == 0x28u, "SferaBoundCheckArray debug line offset");
typedef struct SferaWorldObjectRuntime { uint32_t max_occupied_object_handle; uint32_t controlled_object_handle; uint32_t contour_mode; SferaBoundCheckArray object_handles; SferaBoundCheckArray extended_object_handles; uint32_t extended_object_count; } SferaWorldObjectRuntime;
typedef struct SferaGrassRuntime { SferaBoundCheckArray instance_offsets; SferaBoundCheckArray model_handles; SferaBoundCheckArray instance_indices; SferaBoundCheckArray type_records; } SferaGrassRuntime;
typedef struct SferaLightRuntime { SferaBoundCheckArray cell_light_ids; SferaBoundCheckArray cell_records; SferaBoundCheckArray cell_indices; SferaBoundCheckArray handles; SferaBoundCheckArray visible_handles; SferaBoundCheckArray active_handles; uint32_t render_candidate_indices[30]; uint32_t render_candidate_active[30]; } SferaLightRuntime;
typedef struct SferaAutoBoundsArray { uint32_t data; uint32_t capacity; uint32_t maximum; uint32_t growth; uint32_t element_size; char debug_file[32]; uint32_t debug_line; } SferaAutoBoundsArray;
SFERA_STATIC_ASSERT(sizeof(SferaAutoBoundsArray) == 0x38u, "SferaAutoBoundsArray ABI size");
SFERA_STATIC_ASSERT(offsetof(SferaAutoBoundsArray, debug_file) == 0x14u, "SferaAutoBoundsArray debug file offset");
SFERA_STATIC_ASSERT(offsetof(SferaAutoBoundsArray, debug_line) == 0x34u, "SferaAutoBoundsArray debug line offset");
typedef struct SferaLandscapeRuntime { SferaBoundCheckArray file_records; SferaBoundCheckArray microtexture_handles; } SferaLandscapeRuntime;
typedef struct SferaCollisionRuntime { SferaBoundCheckArray candidate_handles; SferaBoundCheckArray near_result_handles; SferaAutoBoundsArray contact_objects; } SferaCollisionRuntime;
typedef struct SferaSceneArrayRuntime { SferaBoundCheckArray cloud_records; SferaBoundCheckArray surface_index_map; SferaBoundCheckArray scene_records; SferaBoundCheckArray render_pass_slots; SferaBoundCheckArray surface_handles; SferaBoundCheckArray clip_vectors; SferaBoundCheckArray surface_records; SferaBoundCheckArray scene_points; SferaBoundCheckArray object_positions; SferaBoundCheckArray model_matrices; SferaBoundCheckArray world_cell_records; SferaBoundCheckArray render_work_records; SferaBoundCheckArray reflection_targets; SferaBoundCheckArray object_sort_keys; SferaBoundCheckArray render_ranges; SferaBoundCheckArray object_draw_indices; SferaBoundCheckArray object_visibility_indices; SferaBoundCheckArray clip_points; SferaBoundCheckArray character_matrices; SferaBoundCheckArray object_sort_indices; SferaBoundCheckArray clip_indices; } SferaSceneArrayRuntime;
#define SFERA_LANDSCAPE_DEBUG_DIMENSION UINT32_C(256)
typedef struct SferaSceneBuildRuntime { uint32_t object_count; uint16_t landscape_debug_pixels[SFERA_LANDSCAPE_DEBUG_DIMENSION * SFERA_LANDSCAPE_DEBUG_DIMENSION]; } SferaSceneBuildRuntime;
SFERA_STATIC_ASSERT(offsetof(SferaSceneBuildRuntime, landscape_debug_pixels) == 0x04u, "scene build debug pixel offset");
SFERA_STATIC_ASSERT(sizeof(SferaSceneBuildRuntime) == 0x20004u, "scene build runtime ABI span");
#define SFERA_WEATHER_INTERPOLATION_OFFSET_COUNT UINT32_C(8)
#define SFERA_WEATHER_PARSE_ERROR_CAPACITY UINT32_C(0xC8)
typedef struct SferaWeatherRuntime { SferaBoundCheckArray sky_texture_handles; uint32_t interpolation_offsets[SFERA_WEATHER_INTERPOLATION_OFFSET_COUNT]; char parse_error[SFERA_WEATHER_PARSE_ERROR_CAPACITY]; float direction_cos_component; float direction_sin_component; uint32_t standard_object; uint32_t highres_object; } SferaWeatherRuntime;
typedef struct SferaModelRuntime { uint32_t repository; } SferaModelRuntime;
typedef struct SferaModelRegistryRuntime { uint8_t comparator; uint8_t reserved_01[3]; uint32_t sentinel; uint32_t size; } SferaModelRegistryRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaModelRegistryRuntime) == 0x0Cu, "model registry ABI size");
typedef struct SferaModelMaterialLookupRuntime { uint32_t refresh_tick; char material_name[0xAC]; } SferaModelMaterialLookupRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaModelMaterialLookupRuntime) == 0xB0u, "model material lookup span");
#define SFERA_DYNAMIC_INDEX_SCRATCH_COUNT UINT32_C(3000)
SFERA_STATIC_ASSERT(SFERA_DYNAMIC_INDEX_SCRATCH_COUNT * sizeof(uint16_t) == 0x1770u, "dynamic index scratch span");
typedef struct SferaListStackRuntime { uint32_t head; uint32_t tail; } SferaListStackRuntime;
typedef struct SferaNatureRuntime { uint32_t manager; } SferaNatureRuntime;
typedef struct SferaSoundRuntime { uint32_t effect_manager; uint32_t manager; SferaListStackRuntime tracks; } SferaSoundRuntime;
typedef struct SferaWarningLogRuntime { uint8_t object[0x5320]; } SferaWarningLogRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaWarningLogRuntime) == 0x5320u, "warning log runtime ABI size");
typedef struct SferaControlOptionsRuntime { uint32_t active_slot; uint32_t configured_bindings[64]; uint32_t working_bindings[64]; } SferaControlOptionsRuntime;
#define SFERA_SPRITE_TEXTURE_TOKEN_CAPACITY UINT32_C(0x110)
typedef struct SferaSpriteRuntime { uint32_t render_mode; char texture_token[SFERA_SPRITE_TEXTURE_TOKEN_CAPACITY]; } SferaSpriteRuntime;
typedef struct SferaCrashRuntime { uint8_t report_pending; } SferaCrashRuntime;
typedef struct SferaContoursRuntime { uint32_t round_robin_counter; } SferaContoursRuntime;
typedef struct SferaDynGreenRuntime { uint32_t previous_timestamp_low; uint32_t previous_timestamp_high; } SferaDynGreenRuntime;
typedef struct SferaExecutionMonitorRuntime { uint32_t thread_handle; uint8_t reserved_04[8]; uint16_t stop_requested; char log_path[0x36]; uint8_t critical_section[24]; uint32_t current_value_a; uint32_t current_value_b; } SferaExecutionMonitorRuntime;
typedef struct SferaErrorLogRuntime { uint8_t object[0x18]; uint8_t index_table[0x80]; } SferaErrorLogRuntime;
typedef struct SferaPacketCodecRuntime { uint8_t substitution[256]; uint32_t initialized; uint16_t checksum[256]; } SferaPacketCodecRuntime;
typedef struct SferaU64Words { uint32_t low; uint32_t high; } SferaU64Words;
SFERA_STATIC_ASSERT(sizeof(SferaU64Words) == 8u, "64-bit word pair ABI size");
typedef struct SferaFrameRuntime { float fps; uint32_t fps_sample_count; SferaU64Words fps_anchor; uint32_t frame_sample_count; SferaU64Words frame_anchor; SferaU64Words frame_state_anchor; uint32_t frame_state; uint32_t primary_toggle; uint32_t secondary_toggle; uint8_t color_lookup_object[0x1C]; uint32_t color_lookup_flags; uint32_t warning_header_written; } SferaFrameRuntime;
typedef struct SferaHighResolutionClockRuntime { SferaU64Words elapsed_counter; SferaU64Words epoch_microseconds; SferaU64Words performance_frequency; uint32_t frequency_shift; uint32_t initialized; SferaU64Words counter_anchor; } SferaHighResolutionClockRuntime;
#define SFERA_PROFILE_SLOT_COUNT UINT32_C(100)
typedef struct SferaProfilerRuntime { SferaU64Words accumulated_ticks[SFERA_PROFILE_SLOT_COUNT]; uint8_t active[SFERA_PROFILE_SLOT_COUNT]; uint32_t frame_count; SferaU64Words start_time_us[SFERA_PROFILE_SLOT_COUNT]; uint32_t call_count[SFERA_PROFILE_SLOT_COUNT]; uint32_t frame_time_total; SferaU64Words report_clock_snapshot; uint32_t report_percent[10]; } SferaProfilerRuntime;
typedef struct SferaCrc32Runtime { uint32_t table[256]; uint32_t current; } SferaCrc32Runtime;
typedef struct SferaUiLoadScratchRuntime { char button_value[256]; char checkbox_value[256]; char text_value[256]; char image_value[256]; char cursor_name[128]; char resolved_ui_path[256]; char localized_text[1024]; char localized_key[256]; char list_item_value[256]; char progress_bar_value[256]; char scroll_bar_value[256]; char slider_status_value[256]; char slot_value[256]; char resolution_text[128]; char spin_value_text[128]; char text_style_token[256]; char tooltip_key[256]; } SferaUiLoadScratchRuntime;
typedef struct SferaHyperTextScratchRuntime { char attribute_name[256]; char command_text[256]; char token_text[256]; } SferaHyperTextScratchRuntime;
typedef struct SferaStringLookupRuntime { uint16_t hash_mix[256]; uint8_t case_fold[256]; uint32_t initialized; } SferaStringLookupRuntime;
typedef struct SferaAsciiLowerRuntime { uint8_t table[256]; } SferaAsciiLowerRuntime;
typedef struct SferaModelLoadScratchRuntime { char filename[128]; } SferaModelLoadScratchRuntime;
typedef struct SferaStringUtilityRuntime { uint32_t case_tables_initialized; uint8_t lowercase[256]; uint8_t uppercase[256]; char format_buffer[512]; } SferaStringUtilityRuntime;
typedef struct SferaNetworkProbeSample { SferaU64Words timestamp; uint32_t probe_result; uint32_t context_a; uint32_t context_b; uint32_t context_c; } SferaNetworkProbeSample;
SFERA_STATIC_ASSERT(sizeof(SferaNetworkProbeSample) == 0x18u, "network probe sample ABI size");
#define SFERA_NETWORK_PROBE_SAMPLE_COUNT UINT32_C(20)
typedef struct SferaNetworkProbeRuntime { uint32_t sample_count; uint8_t stop_requested; uint8_t host[64]; uint32_t context_a; uint32_t context_b; uint32_t snapshot_count; uint32_t thread_handle; uint32_t critical_section_words[6]; SferaNetworkProbeSample samples[SFERA_NETWORK_PROBE_SAMPLE_COUNT]; uint32_t context_c; SferaNetworkProbeSample snapshot[SFERA_NETWORK_PROBE_SAMPLE_COUNT]; } SferaNetworkProbeRuntime;
typedef struct SferaConfigParseScratchRuntime { uint8_t token[256]; } SferaConfigParseScratchRuntime;
typedef struct SferaMusicRuntime { uint8_t requested_path[512]; uint32_t current_stream; } SferaMusicRuntime;
typedef struct SferaContainerDiagnosticsRuntime { char range_error[128]; } SferaContainerDiagnosticsRuntime;
typedef struct SferaOleHostAbi { uint32_t storage_vtable[18]; uint32_t storage_object_vtable; uint32_t inplace_frame_vtable[15]; uint32_t client_site_vtable[9]; uint32_t inplace_site_vtable[15]; uint32_t doc_host_ui_handler_vtable[18]; } SferaOleHostAbi;
typedef union SferaMainCommandStateRuntime { uint32_t alignment[144]; uint8_t storage[0x240]; } SferaMainCommandStateRuntime;
typedef union SferaMainInputStateRuntime { uint32_t alignment[155]; uint8_t storage[0x26C]; } SferaMainInputStateRuntime;
typedef union SferaMainViewStateRuntime { uint32_t alignment[139]; uint8_t storage[0x22C]; } SferaMainViewStateRuntime;
typedef union SferaMainUiStateRuntime { uint32_t alignment[108]; uint8_t storage[0x1B0]; } SferaMainUiStateRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaMainUiStateRuntime) == 0x1B0u, "main UI runtime span before screen quad indices");
#define SFERA_SCREEN_QUAD_INDEX_COUNT UINT32_C(1800)
SFERA_STATIC_ASSERT(SFERA_SCREEN_QUAD_INDEX_COUNT * sizeof(uint16_t) == 0x0E10u, "screen quad index scratch ABI span");
typedef union SferaClientConfigRuntime { uint32_t alignment[67]; uint8_t storage[0x10C]; } SferaClientConfigRuntime;
typedef union SferaGrassPlacementSlot { uint32_t alignment[189]; uint8_t storage[0x2F4]; } SferaGrassPlacementSlot;
SFERA_STATIC_ASSERT(sizeof(SferaGrassPlacementSlot) == 0x2F4u, "grass placement slot ABI stride");
#define SFERA_GRASS_PLACEMENT_SLOT_COUNT UINT32_C(36)
typedef struct SferaGrassPlacementRuntime { SferaGrassPlacementSlot slots[SFERA_GRASS_PLACEMENT_SLOT_COUNT]; } SferaGrassPlacementRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaGrassPlacementRuntime) == 0x6A50u, "grass placement runtime ABI span");
typedef union SferaInterfaceCoreRuntime { uint32_t alignment[207]; uint8_t storage[0x33C]; } SferaInterfaceCoreRuntime;
typedef struct SferaClientMainScalarRuntime { uint32_t counter_01; uint32_t state_01; uint32_t state_02; uint32_t state_03; uint32_t state_04; uint32_t counter_02; uint32_t counter_03; uint32_t mode_01; uint32_t mode_02; uint32_t state_05; uint32_t state_06; uint32_t state_07; uint32_t state_09; uint32_t state_10; uint32_t state_11; uint32_t state_12; uint32_t state_13; uint32_t state_14; uint32_t state_15; uint32_t state_16; uint32_t state_17; uint32_t state_18; uint32_t state_19; uint32_t state_20; uint32_t state_21; uint32_t state_22; uint32_t state_23; uint32_t state_24; uint32_t state_25; uint32_t state_26; uint32_t state_27; uint32_t state_28; uint32_t state_29; uint32_t state_30; uint32_t state_31; uint32_t state_32; uint32_t state_33; uint32_t state_34; uint32_t state_35; uint32_t state_36; uint32_t counter_04; } SferaClientMainScalarRuntime;
typedef struct SferaInterScalarRuntime { uint32_t state_01; uint32_t state_02; uint32_t state_03; uint32_t mode_01; uint32_t mode_02; uint32_t mode_03; uint32_t state_04; uint32_t mode_04; uint32_t state_05; uint32_t state_06; uint32_t state_07; } SferaInterScalarRuntime;
typedef struct SferaTextureSetScalarRuntime { uint32_t state_01; uint32_t state_02; uint32_t mode_01; uint32_t state_03; uint32_t mode_02; uint32_t record_default_38; uint32_t record_default_3c; uint32_t last_selector; } SferaTextureSetScalarRuntime;
#define SFERA_TEXTURE_HASH_BUCKET_COUNT UINT32_C(65536)
#define SFERA_TEXTURE_PATH_COUNT_MAX UINT32_C(500)
#define SFERA_TEXTURE_PATH_CAPACITY UINT32_C(100)
#define SFERA_TEXTURE_HASH_MIX_COUNT UINT32_C(256)
typedef struct SferaTextureRegistryRuntime { uint32_t texture_count; uint32_t stream_direction_flag; uint32_t batch_count; uint32_t initialized; uint32_t path_count; uint32_t batch_records; uint16_t hash_heads[SFERA_TEXTURE_HASH_BUCKET_COUNT]; char paths[SFERA_TEXTURE_PATH_COUNT_MAX][SFERA_TEXTURE_PATH_CAPACITY]; uint32_t preload_request_count; uint32_t default_texture_id; uint16_t hash_mix[SFERA_TEXTURE_HASH_MIX_COUNT]; } SferaTextureRegistryRuntime;
SFERA_STATIC_ASSERT(sizeof(((SferaTextureRegistryRuntime*)0)->hash_heads) == 0x20000u, "texture hash-head table ABI span");
SFERA_STATIC_ASSERT(sizeof(((SferaTextureRegistryRuntime*)0)->paths) == 50000u, "texture path table ABI span");
SFERA_STATIC_ASSERT(sizeof(((SferaTextureRegistryRuntime*)0)->hash_mix) == 0x200u, "texture hash-mix table ABI span");
typedef struct SferaInterfaceRuntime { uint32_t cursor_kind; uint8_t primary_gate; uint8_t secondary_gate; uint32_t cross_enabled; uint32_t sounds_enabled; uint32_t description_auto_popup; uint32_t invite_messages; uint32_t description_window; uint32_t previous_input_modifiers; SferaBoundCheckArray windows; SferaBoundCheckArray window_handle_table; } SferaInterfaceRuntime;
#ifdef __cplusplus
using SferaStdAllocator = StdAllocator;
#else
typedef struct SferaStdAllocator { uint32_t vptr; } SferaStdAllocator;
#endif
typedef struct SferaMemoryRuntime { uint32_t allocation_source_file; uint32_t allocation_source_line; uint32_t critical_error_callback; uint32_t tracker_primary; uint32_t tracker_auxiliary; uint32_t tracker_floor; uint32_t tracker_ceiling; uint32_t bucket_bytes[1024]; uint32_t bucket_allocations[1024]; uint8_t tracking_initialized; uint8_t diagnostics_dirty; uint32_t live_allocation_count; uint32_t validation_pass_count; uint32_t lock_words[6]; uint8_t lock_initialized; uint8_t lock_held; } SferaMemoryRuntime;
#define SFERA_MEMORY_SOURCE_HASH_BUCKET_COUNT UINT32_C(1024)
typedef struct SferaMemorySourceHashRuntime { uint32_t entries; uint32_t capacity; uint16_t free_index; uint16_t bucket_heads[SFERA_MEMORY_SOURCE_HASH_BUCKET_COUNT]; uint8_t reserved_80a[6]; } SferaMemorySourceHashRuntime;
SFERA_STATIC_ASSERT(offsetof(SferaMemorySourceHashRuntime, bucket_heads) == 0x0Au, "memory source hash bucket offset");
SFERA_STATIC_ASSERT(sizeof(SferaMemorySourceHashRuntime) == 0x810u, "memory source hash ABI span");
#define SFERA_ALLOCATION_HASH_BUCKET_COUNT UINT32_C(65536)
typedef struct SferaAllocationHashRuntime { uint32_t records; uint32_t capacity; uint32_t free_index; uint32_t bucket_heads[SFERA_ALLOCATION_HASH_BUCKET_COUNT]; } SferaAllocationHashRuntime;
SFERA_STATIC_ASSERT(offsetof(SferaAllocationHashRuntime, bucket_heads) == 0x0Cu, "allocation hash bucket offset");
SFERA_STATIC_ASSERT(sizeof(SferaAllocationHashRuntime) == 0x4000Cu, "allocation hash ABI span");
typedef struct SferaAntifloodQueueRuntime { uint8_t records[0x280]; uint32_t count; uint32_t write_index; uint32_t read_index; } SferaAntifloodQueueRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaAntifloodQueueRuntime) == 0x28Cu, "antiflood queue ABI span");
typedef struct SferaDiagnosticLogObjectRuntime { uint8_t header[0x38]; SferaAntifloodQueueRuntime antiflood_queue; uint32_t reserved_2c4; } SferaDiagnosticLogObjectRuntime;
SFERA_STATIC_ASSERT(offsetof(SferaDiagnosticLogObjectRuntime, antiflood_queue) == 0x38u, "diagnostic log antiflood queue offset");
SFERA_STATIC_ASSERT(sizeof(SferaDiagnosticLogObjectRuntime) == 0x2C8u, "diagnostic log object ABI span");
typedef struct SferaWin32DialogRegistryRuntime { uint32_t sentinel; uint32_t size; } SferaWin32DialogRegistryRuntime;
typedef SferaModelRegistryRuntime SferaControlReferenceRegistryRuntime;
typedef SferaModelRegistryRuntime SferaCursorTextureRegistryRuntime;
typedef struct SferaBrowserWindowRuntime { uint8_t class_registered; uint8_t reserved_01[3]; uint32_t original_window_proc; } SferaBrowserWindowRuntime;
typedef struct SferaMinimapTextureRuntime { uint32_t singleton; } SferaMinimapTextureRuntime;
typedef struct SferaCrtStartupRuntime { uint32_t managed_app; uint32_t environment; uint32_t main_return_code; uint32_t has_cctor; uint32_t dynamic_tls_dtor_callbacks; uint32_t startup_state; uint32_t processor_feature_10; uint32_t dynamic_tls_init_callback; uint32_t encoded_onexit_begin; uint32_t encoded_onexit_end; uint32_t argc; uint32_t argv; uint32_t envp; uint32_t mainargs_result; uint32_t new_mode; uint32_t environment_mode; uint32_t commode; uint32_t fmode; uint32_t startup_lock; uint32_t tls_cleanup_object; uint32_t heap_compatibility_flag; } SferaCrtStartupRuntime;
#define SFERA_CRASH_REPORT_TEXT_CAPACITY UINT32_C(0x2000)
#define SFERA_CRASH_PATH_CAPACITY UINT32_C(0x104)
typedef struct SferaCrashReportRuntime { char report_text[SFERA_CRASH_REPORT_TEXT_CAPACITY]; uint32_t report_length; uint32_t reserved_2004; char error_log_path[SFERA_CRASH_PATH_CAPACITY]; uint32_t previous_exception_filter; uint32_t process_handle; uint32_t error_log_handle; } SferaCrashReportRuntime;
SFERA_STATIC_ASSERT(offsetof(SferaCrashReportRuntime, report_length) == 0x2000u, "crash report length source offset");
SFERA_STATIC_ASSERT(offsetof(SferaCrashReportRuntime, error_log_path) == 0x2008u, "crash path source offset");
SFERA_STATIC_ASSERT(offsetof(SferaCrashReportRuntime, previous_exception_filter) == 0x210Cu, "crash filter source offset");
SFERA_STATIC_ASSERT(offsetof(SferaCrashReportRuntime, process_handle) == 0x2110u, "crash process source offset");
SFERA_STATIC_ASSERT(offsetof(SferaCrashReportRuntime, error_log_handle) == 0x2114u, "crash log handle source offset");
typedef struct SferaRenderBufferCapacities { uint32_t vertex32; uint32_t vertex28; uint32_t index_primary; uint32_t index_secondary; } SferaRenderBufferCapacities;
typedef struct SferaFileRuntime { uint32_t crash_report_instance; uint32_t callback_enabled; uint32_t search_path_count; uint32_t open_file_count; uint32_t callback; SferaAutoBoundsArray search_paths; SferaAutoBoundsArray open_files; } SferaFileRuntime;
typedef struct SferaVec3F { float x; float y; float z; } SferaVec3F;
typedef union SferaFloatWord { float f32; uint32_t u32; } SferaFloatWord;
typedef struct SferaVec3Word { SferaFloatWord x; SferaFloatWord y; SferaFloatWord z; } SferaVec3Word;
typedef struct SferaSceneVectorRuntime { SferaVec3Word render_scale; SferaVec3Word transform_scratch; SferaVec3Word frame_102_position; SferaVec3Word frame_101_position; SferaVec3Word object_position_delta; } SferaSceneVectorRuntime;
typedef struct SferaSpatialBoundsRuntime { SferaVec3Word minimum; SferaVec3Word maximum; } SferaSpatialBoundsRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaSpatialBoundsRuntime) == 0x18u, "spatial bounds runtime layout");
typedef struct SferaViewSpatialRuntime { SferaVec3Word basis[4]; uint8_t alternate_projection; uint8_t reserved_31[3]; SferaVec3Word position_offset; SferaVec3Word scale; SferaVec3Word world_anchor; SferaVec3Word view_axis; } SferaViewSpatialRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaViewSpatialRuntime) == 0x64u, "view spatial runtime layout");
typedef struct SferaLandscapeSampleSeries { uint32_t count; float samples[19]; } SferaLandscapeSampleSeries;
SFERA_STATIC_ASSERT(sizeof(SferaLandscapeSampleSeries) == 0x50u, "landscape sample series ABI stride");
typedef struct SferaLandscapeInterpolationRuntime { uint32_t subdivision_count; SferaLandscapeSampleSeries axes[3]; } SferaLandscapeInterpolationRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaLandscapeInterpolationRuntime) == 0xF4u, "landscape interpolation runtime layout");
typedef union SferaLogPath { char text[52]; uint32_t words[13]; } SferaLogPath;
typedef struct SferaLogFileRuntime { SferaLogPath path; uint32_t truncate_on_first_write; uint32_t has_written; uint32_t size_limit; } SferaLogFileRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaLogFileRuntime) == 0x40u, "log file runtime ABI stride");
typedef struct SferaLogRuntime { SferaLogFileRuntime files[3]; } SferaLogRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaLogRuntime) == 0xC0u, "log runtime file table span");
typedef struct SferaMatrix4x4F { float m[4][4]; } SferaMatrix4x4F;
SFERA_STATIC_ASSERT(sizeof(SferaMatrix4x4F) == 0x40u, "4x4 float matrix ABI size");
typedef struct SferaD3D9SemanticStateRuntime { uint32_t vertex_declaration; uint32_t shader_manager; SferaMatrix4x4F view_matrix; SferaMatrix4x4F projection_matrix; uint32_t sampler_min_filter; uint32_t sampler_mag_filter; uint32_t sampler_mip_filter; } SferaD3D9SemanticStateRuntime;
typedef struct SferaVec4F { float x; float y; float z; float w; } SferaVec4F;
typedef struct SferaTransformRuntime { uint32_t matrix_address; uint32_t reserved_04[3]; SferaMatrix4x4F matrix; SferaVec3F scale; SferaVec3F secondary_scale; uint32_t flags; uint32_t reserved_6c; } SferaTransformRuntime;
SFERA_STATIC_ASSERT(offsetof(SferaTransformRuntime, matrix) == 0x10u, "transform matrix offset");
SFERA_STATIC_ASSERT(sizeof(SferaTransformRuntime) == 0x70u, "transform runtime ABI size");
typedef struct SferaBoundsCornersRuntime { SferaVec3F corners[8]; } SferaBoundsCornersRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaBoundsCornersRuntime) == 0x60u, "bounds corner runtime ABI size");
typedef struct SferaSpatialStateRuntime { SferaTransformRuntime transform; SferaBoundsCornersRuntime bounds; } SferaSpatialStateRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaSpatialStateRuntime) == 0xD0u, "spatial state runtime ABI size");
#define SFERA_SPATIAL_STATE_COUNT UINT32_C(67)
typedef struct SferaSkyInterpolationRuntime { SferaVec4F primary_samples[10]; float primary_key_positions[10]; SferaVec4F primary_reference; SferaVec4F secondary_samples[6]; float secondary_key_positions[6]; } SferaSkyInterpolationRuntime;
SFERA_STATIC_ASSERT(offsetof(SferaSkyInterpolationRuntime, primary_key_positions) == 0xA0u, "sky primary key offset");
SFERA_STATIC_ASSERT(offsetof(SferaSkyInterpolationRuntime, primary_reference) == 0xC8u, "sky reference offset");
SFERA_STATIC_ASSERT(offsetof(SferaSkyInterpolationRuntime, secondary_samples) == 0xD8u, "sky secondary sample offset");
SFERA_STATIC_ASSERT(offsetof(SferaSkyInterpolationRuntime, secondary_key_positions) == 0x138u, "sky secondary key offset");
SFERA_STATIC_ASSERT(sizeof(SferaSkyInterpolationRuntime) == 0x150u, "sky interpolation runtime ABI size");
typedef struct SferaColorExpansionRuntime { uint32_t five_bit_to_eight_bit[32]; uint8_t initialized; } SferaColorExpansionRuntime;
typedef struct SferaUiParseScratchRuntime { char token_buffer[0x4000]; char auxiliary_text[0x4000]; char input_text[0x4000]; } SferaUiParseScratchRuntime;
SFERA_STATIC_ASSERT(offsetof(SferaUiParseScratchRuntime, auxiliary_text) == 0x4000u, "UI parse auxiliary buffer offset");
SFERA_STATIC_ASSERT(offsetof(SferaUiParseScratchRuntime, input_text) == 0x8000u, "UI parse input buffer offset");
SFERA_STATIC_ASSERT(sizeof(SferaUiParseScratchRuntime) == 0xC000u, "UI parse scratch span");
typedef struct SferaCriticalDiagnosticsRuntime { char allocation_context[128]; uint32_t processing_depth; uint32_t serial_number; uint32_t stack_dump_callback; uint32_t log_chain_head; } SferaCriticalDiagnosticsRuntime;
typedef struct SferaScreenVertex { float x; float y; float z; float rhw; uint32_t diffuse; uint32_t specular; float u; float v; } SferaScreenVertex;
SFERA_STATIC_ASSERT(sizeof(SferaScreenVertex) == 0x20u, "screen vertex ABI size");
SFERA_STATIC_ASSERT(offsetof(SferaScreenVertex, z) == 0x08u, "screen vertex z offset");
SFERA_STATIC_ASSERT(offsetof(SferaScreenVertex, rhw) == 0x0Cu, "screen vertex rhw offset");
SFERA_STATIC_ASSERT(offsetof(SferaScreenVertex, diffuse) == 0x10u, "screen vertex diffuse offset");
SFERA_STATIC_ASSERT(offsetof(SferaScreenVertex, specular) == 0x14u, "screen vertex specular offset");
SFERA_STATIC_ASSERT(offsetof(SferaScreenVertex, u) == 0x18u, "screen vertex u offset");
SFERA_STATIC_ASSERT(offsetof(SferaScreenVertex, v) == 0x1Cu, "screen vertex v offset");
#define SFERA_SKY_SCREEN_VERTEX_COUNT UINT32_C(120)
#define SFERA_LANDSCAPE_SCREEN_VERTEX_COUNT UINT32_C(1200)
SFERA_STATIC_ASSERT(sizeof(SferaScreenVertex) * SFERA_SKY_SCREEN_VERTEX_COUNT == 0x0F00u, "sky screen vertex scratch span");
SFERA_STATIC_ASSERT(sizeof(SferaScreenVertex) * SFERA_LANDSCAPE_SCREEN_VERTEX_COUNT == 0x9600u, "landscape screen vertex scratch span");
#define SFERA_SCREEN_VERTEX_ADDR(vertices, index, member) ((uint32_t)(uintptr_t)&(vertices)[(index)].member)
#define SFERA_SCREEN_VERTEX_FIELD_END_ADDR(vertices, member) (SFERA_SCREEN_VERTEX_ADDR(vertices, 0u, member) + (uint32_t)sizeof(vertices))
typedef struct SferaSceneRenderRuntime { SferaScreenVertex textured_quad[4]; SferaScreenVertex interface_quad[4]; } SferaSceneRenderRuntime;
typedef struct SferaGraphicsOptionsRuntime { uint32_t dialog_state; uint32_t graphics_page; uint32_t interface_values[9]; uint32_t graphics_values[13]; uint32_t saved_interface_values[9]; } SferaGraphicsOptionsRuntime;
#define SFERA_OPTIONS_LABEL_COUNT UINT32_C(7)
#define SFERA_OPTIONS_LABEL_CAPACITY UINT32_C(0x200)
typedef struct SferaSphereOptionsRuntime { uint32_t saved_lods_enabled; SferaFloatWord saved_lod_distance; SferaFloatWord saved_fog_distance; uint32_t saved_music_volume; char option_labels[SFERA_OPTIONS_LABEL_COUNT][SFERA_OPTIONS_LABEL_CAPACITY]; } SferaSphereOptionsRuntime;
typedef struct SferaVector32 { uint32_t begin; uint32_t end; uint32_t capacity_end; } SferaVector32;
SFERA_STATIC_ASSERT(sizeof(SferaVector32) == 0x0Cu, "32-bit vector ABI size");
typedef struct SferaOptionsDialogRuntime { uint32_t graphics_snapshot[7]; uint32_t audio_settings; char widget_key_name[0x80]; uint32_t pending_graphics_value; uint32_t comparison_graphics_value; uint32_t widget_keys_initialized; uint32_t reflection_quality; uint32_t aligned_storage_token; uint8_t aligned_storage_padding[0x0C]; uint8_t aligned_storage_object[0xC0]; SferaVector32 chat_list_fonts; uint32_t reserved_18c; SferaVector32 chat_edit_fonts; uint32_t reserved_19c; SferaVector32 graphics_modes; } SferaOptionsDialogRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaOptionsDialogRuntime) == 0x1ACu, "options dialog runtime ABI span");
SFERA_STATIC_ASSERT(offsetof(SferaOptionsDialogRuntime, widget_key_name) == 0x20u, "options dialog key buffer offset");
SFERA_STATIC_ASSERT(offsetof(SferaOptionsDialogRuntime, reflection_quality) == 0xACu, "options dialog reflection quality offset");
SFERA_STATIC_ASSERT(offsetof(SferaOptionsDialogRuntime, chat_list_fonts) == 0x180u, "options dialog first vector offset");
SFERA_STATIC_ASSERT(offsetof(SferaOptionsDialogRuntime, chat_edit_fonts) == 0x190u, "options dialog second vector offset");
SFERA_STATIC_ASSERT(offsetof(SferaOptionsDialogRuntime, graphics_modes) == 0x1A0u, "options dialog third vector offset");
typedef struct SferaWindowRuntime { uint32_t render_vertex_buffer; uint32_t reserved_004; uint32_t render_state_word; uint32_t reserved_00c; uint32_t clip_vector_count; SferaFloatWord distance_scratch; uint8_t timing_critical_section[24]; uint8_t reserved_030[0x78]; uint32_t input_runtime_object; uint32_t reserved_0ac; uint32_t input_state; uint32_t active_window_index; uint32_t windowed; uint32_t main_window; uint32_t reserved_0c0; uint32_t landscape_grid_records; uint32_t landscape_grid_count; uint32_t runtime_debug_enabled; uint32_t reserved_0d0; uint32_t scene_record_count; char diagnostic_message[0x800]; uint32_t reserved_8d8; } SferaWindowRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaWindowRuntime) == 0x8DCu, "window runtime ABI span");
SFERA_STATIC_ASSERT(offsetof(SferaWindowRuntime, timing_critical_section) == 0x18u, "window runtime critical section offset");
SFERA_STATIC_ASSERT(offsetof(SferaWindowRuntime, windowed) == 0xB8u, "window runtime windowed flag offset");
SFERA_STATIC_ASSERT(offsetof(SferaWindowRuntime, main_window) == 0xBCu, "window runtime HWND offset");
SFERA_STATIC_ASSERT(offsetof(SferaWindowRuntime, diagnostic_message) == 0xD8u, "window runtime diagnostic buffer offset");
typedef struct SferaInputDeviceRuntime { uint32_t process_value; uint32_t input_generation; uint32_t reserved_008; SferaFloatWord minimum_lod_distance; SferaFloatWord lod_distance; uint32_t keyboard_device; uint32_t keyboard_state_code; uint32_t reserved_01c; SferaFloatWord frame_interval; uint32_t render_state; uint32_t shared_object; } SferaInputDeviceRuntime;
typedef struct SferaScreenClipRuntime { uint32_t left; uint32_t top; uint32_t right; uint32_t bottom; } SferaScreenClipRuntime;
typedef struct SferaDirectInputRuntime { uint32_t direct_input; uint32_t mouse_device; uint8_t keyboard_state[256]; uint32_t acquire_failure_state; uint8_t view_adjust_state; uint8_t modifier_08; uint8_t modifier_20; uint8_t reserved_10b; } SferaDirectInputRuntime;
typedef struct SferaShadowRuntime { uint32_t projected_points; uint32_t span_records; uint32_t manager; uint32_t projected_point_capacity; uint32_t aligned_global_object; } SferaShadowRuntime;
#define SFERA_TRANSFORM_BOUNDS_STORAGE_SIZE UINT32_C(0xC0)
typedef struct SferaWorldRenderRuntime { uint32_t active_model; uint32_t world_spatial_index; uint32_t feature_toggle; uint32_t render_queue_count; uint32_t scene_active; } SferaWorldRenderRuntime;
typedef struct SferaWorldLoadRuntime { uint32_t render_shadows; uint32_t active_tool_context; uint32_t live_object_count; uint32_t packed_variant; uint32_t loading_work_total; uint32_t snow_path_object; } SferaWorldLoadRuntime;
typedef struct SferaWorldBoundsRuntime { SferaVec3Word minimum; SferaVec3Word maximum; } SferaWorldBoundsRuntime;
#define SFERA_RENDER_LOOKUP_COUNT UINT32_C(256)
typedef struct SferaRenderLookupEntry { uint32_t resource; uint32_t mask; } SferaRenderLookupEntry;
SFERA_STATIC_ASSERT(sizeof(SferaRenderLookupEntry) == 0x08u, "render lookup entry ABI size");
SFERA_STATIC_ASSERT(SFERA_RENDER_LOOKUP_COUNT * sizeof(SferaRenderLookupEntry) == 0x800u, "render lookup source span");
typedef struct SferaRenderLookupRuntime { uint32_t initialized; uint32_t alpha_component; SferaRenderLookupEntry entries[SFERA_RENDER_LOOKUP_COUNT]; } SferaRenderLookupRuntime;
typedef struct SferaLandscapeRenderRuntime { uint32_t grid_buffer_bytes; SferaFloatWord view_offset_x; SferaFloatWord view_offset_y; uint32_t rotation_step; uint32_t source_record_count; uint32_t source_section_base; } SferaLandscapeRenderRuntime;
typedef struct SferaProcessRuntime { char executable_path[64]; uint32_t packed_layout_bytes; uint32_t packed_record_count; } SferaProcessRuntime;
#define SFERA_CLIENT_LOG_MESSAGE_CAPACITY UINT32_C(0x390)
typedef struct SferaClientProcessRuntime { uint32_t ui_bridge; uint32_t shutdown_requested; char locale[10]; uint32_t client_object; char log_message[SFERA_CLIENT_LOG_MESSAGE_CAPACITY]; } SferaClientProcessRuntime;
typedef struct SferaMainRenderRuntime { uint32_t world_object_count; uint32_t secondary_render_pass; uint32_t material_count; uint32_t grass_depth_mode; } SferaMainRenderRuntime;
#define SFERA_MICROTEXTURE_RECORD_COUNT UINT32_C(100)
typedef struct SferaMicrotextureRecord { uint16_t lookup_key; uint16_t reserved_02; uint32_t name; uint32_t resource; } SferaMicrotextureRecord;
SFERA_STATIC_ASSERT(sizeof(SferaMicrotextureRecord) == 0x0Cu, "microtexture record ABI size");
SFERA_STATIC_ASSERT(SFERA_MICROTEXTURE_RECORD_COUNT * sizeof(SferaMicrotextureRecord) == 0x4B0u, "microtexture table source span");
#define SFERA_SCENE_CONTEXT_QUEUE_CAPACITY UINT32_C(30)
typedef struct SferaSceneControlRuntime { uint32_t packed_section_base; uint32_t timing_anchor; SferaFloatWord camera_x; SferaFloatWord camera_y; SferaFloatWord environment_parameter; uint32_t active_context; uint32_t context_count; uint32_t context_queue[SFERA_SCENE_CONTEXT_QUEUE_CAPACITY]; uint32_t microtexture_count; SferaMicrotextureRecord microtextures[SFERA_MICROTEXTURE_RECORD_COUNT]; } SferaSceneControlRuntime;
typedef struct SferaMainAuxRuntime { uint32_t secondary_world_manager; uint32_t color_component; uint32_t resource_word; } SferaMainAuxRuntime;
#define SFERA_LANDSCAPE_MAP_RECORD_COUNT UINT32_C(6400)
typedef struct SferaLandscapeMapRecord { char material_name[20]; uint8_t tile_x; uint8_t tile_y; } SferaLandscapeMapRecord;
SFERA_STATIC_ASSERT(sizeof(SferaLandscapeMapRecord) == 0x16u, "landscape map record ABI size");
typedef struct SferaLandscapeMapRuntime { uint32_t material_remap; uint32_t show_fps; SferaLandscapeMapRecord records[SFERA_LANDSCAPE_MAP_RECORD_COUNT]; } SferaLandscapeMapRuntime;
#define SFERA_SKY_INDEX_COUNT UINT32_C(594)
typedef struct SferaSkyRuntime { SferaFloatWord horizon_scale; uint32_t draw_resource; uint16_t indices[SFERA_SKY_INDEX_COUNT]; } SferaSkyRuntime;
#define SFERA_TEXTURE_CACHE_ENTRY_COUNT UINT32_C(50)
typedef struct SferaTextureCacheEntry { uint32_t owner; uint8_t kind; uint8_t reserved_05[3]; uint32_t resource; uint32_t use_count; } SferaTextureCacheEntry;
SFERA_STATIC_ASSERT(sizeof(SferaTextureCacheEntry) == 0x10u, "texture cache entry ABI size");
typedef struct SferaTextureCacheRuntime { uint32_t active_index; uint32_t upload_serial; uint32_t reserved_08; uint32_t render_gate; uint32_t reserved_10; uint32_t cache_enabled; SferaTextureCacheEntry entries[SFERA_TEXTURE_CACHE_ENTRY_COUNT]; } SferaTextureCacheRuntime;
SFERA_STATIC_ASSERT(offsetof(SferaTextureCacheRuntime, render_gate) == 0x0Cu, "texture cache render gate source offset");
SFERA_STATIC_ASSERT(offsetof(SferaTextureCacheRuntime, cache_enabled) == 0x14u, "texture cache enable source offset");
SFERA_STATIC_ASSERT(offsetof(SferaTextureCacheRuntime, entries) == 0x18u, "texture cache entries source offset");
SFERA_STATIC_ASSERT(sizeof(SferaTextureCacheRuntime) == 0x338u, "texture cache source span");
typedef struct SferaFontAtlasLayoutRuntime { uint32_t span[5]; uint32_t origin[5]; uint32_t cell_step[5]; uint32_t resource_count[5]; uint32_t code_base[5]; } SferaFontAtlasLayoutRuntime;
#define SFERA_FONT_ATLAS_STAGING_DIMENSION UINT32_C(256)
typedef struct SferaFontAtlasStagingRuntime { uint32_t magic; uint32_t width; uint32_t height; uint32_t mip_count; uint32_t reserved_10[3]; uint32_t encoding; uint16_t pixels[SFERA_FONT_ATLAS_STAGING_DIMENSION * SFERA_FONT_ATLAS_STAGING_DIMENSION]; } SferaFontAtlasStagingRuntime;
SFERA_STATIC_ASSERT(offsetof(SferaFontAtlasStagingRuntime, pixels) == 0x20u, "font atlas staging pixel offset");
SFERA_STATIC_ASSERT(sizeof(SferaFontAtlasStagingRuntime) == 0x20020u, "font atlas staging source span");
#define SFERA_PARTITION_SORT_ENTRY_COUNT UINT32_C(200)
typedef struct SferaPartitionSortEntry { uint32_t partition_index; float sort_key; } SferaPartitionSortEntry;
SFERA_STATIC_ASSERT(sizeof(SferaPartitionSortEntry) == 0x08u, "partition sort entry ABI size");
typedef struct SferaPartitionSortRuntime { SferaPartitionSortEntry entries[SFERA_PARTITION_SORT_ENTRY_COUNT]; } SferaPartitionSortRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaPartitionSortRuntime) == 0x640u, "partition sort source span");
#define SFERA_ERROR_MESSAGE_CAPACITY UINT32_C(0x3EC)
typedef struct SferaErrorMessageScratchRuntime { char fatal_message[SFERA_ERROR_MESSAGE_CAPACITY]; char formatted_message[SFERA_ERROR_MESSAGE_CAPACITY]; } SferaErrorMessageScratchRuntime;
#define SFERA_MATERIAL_FILTER_CHAR_COUNT UINT32_C(256)
#define SFERA_MATERIAL_FILTER_TEXT_CAPACITY UINT32_C(0x1000)
#define SFERA_MATERIAL_FILTER_TOKEN_CAPACITY UINT32_C(2048)
typedef struct SferaMaterialFilterRuntime { uint32_t character_map[2][SFERA_MATERIAL_FILTER_CHAR_COUNT]; char exception_scratch[32]; char filter_word[36]; char match_buffer[SFERA_MATERIAL_FILTER_TEXT_CAPACITY]; uint32_t token_lengths[SFERA_MATERIAL_FILTER_TOKEN_CAPACITY]; uint32_t token_starts[SFERA_MATERIAL_FILTER_TOKEN_CAPACITY]; char normalized_input[SFERA_MATERIAL_FILTER_TEXT_CAPACITY]; char tag_stripped_input[SFERA_MATERIAL_FILTER_TEXT_CAPACITY]; } SferaMaterialFilterRuntime;
typedef struct SferaGrassMapManagerRuntime { uint32_t vptr; uint32_t cache_state[5]; uint32_t initialized; } SferaGrassMapManagerRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaGrassMapManagerRuntime) == 0x1Cu, "grass map manager source span");
typedef struct SferaGrassMapRuntime { uint32_t alternating_update_phase; SferaGrassMapManagerRuntime manager; uint32_t init_guard; SferaU64Words last_frame_timestamp; } SferaGrassMapRuntime;
SFERA_STATIC_ASSERT(sizeof(((SferaMaterialFilterRuntime*)0)->character_map[0]) == 0x400u, "material filter character map span");
SFERA_STATIC_ASSERT(sizeof(((SferaMaterialFilterRuntime*)0)->match_buffer) == 0x1000u, "material filter match buffer span");
SFERA_STATIC_ASSERT(sizeof(((SferaMaterialFilterRuntime*)0)->token_lengths) == 0x2000u, "material filter token length span");
typedef struct SferaPhysicsRuntime { char damage_text[20]; float response_curve[100]; } SferaPhysicsRuntime;
SFERA_STATIC_ASSERT(sizeof(((SferaPhysicsRuntime*)0)->response_curve) == 0x190u, "physics response curve ABI span");
SFERA_STATIC_ASSERT(sizeof(SferaInputDeviceRuntime) == 0x2Cu, "input device runtime ABI span");
SFERA_STATIC_ASSERT(offsetof(SferaInputDeviceRuntime, minimum_lod_distance) == 0x0Cu, "input device minimum LOD offset");
SFERA_STATIC_ASSERT(offsetof(SferaInputDeviceRuntime, keyboard_device) == 0x14u, "input device keyboard pointer offset");
SFERA_STATIC_ASSERT(offsetof(SferaInputDeviceRuntime, frame_interval) == 0x20u, "input device frame interval offset");
SFERA_STATIC_ASSERT(sizeof(SferaGraphicsOptionsRuntime) == 0x84u, "graphics options lifted block size");
typedef struct SferaIntBounds3 { uint32_t min_x; uint32_t max_x; uint32_t min_y; uint32_t max_y; uint32_t min_z; uint32_t max_z; } SferaIntBounds3;
SFERA_STATIC_ASSERT(sizeof(SferaIntBounds3) == 0x18u, "integer bounds raw-dword ABI size");
typedef struct SferaViewGeometryRuntime { SferaVec3F reference_points[5]; SferaIntBounds3 projected_bounds; SferaIntBounds3 clipping_bounds; } SferaViewGeometryRuntime;
typedef struct SferaViewProjectionScratchRuntime { SferaVec3F corners[8]; SferaIntBounds3 clipping_bounds; } SferaViewProjectionScratchRuntime;
SFERA_STATIC_ASSERT(offsetof(SferaViewProjectionScratchRuntime, clipping_bounds) == 0x60u, "view projection clipping offset");
SFERA_STATIC_ASSERT(sizeof(SferaViewProjectionScratchRuntime) == 0x78u, "view projection scratch ABI size");
typedef struct SferaTerrainNeighborRuntime { uint32_t cells[8]; } SferaTerrainNeighborRuntime;
#define SFERA_LANDSCAPE_PATCH_GRID_COUNT UINT32_C(6400)
typedef struct SferaLandscapePatchLookupRuntime { uint32_t visible_count; uint32_t active_count; SferaFloatWord parameter; SferaVec3Word primary_vector; SferaVec3Word secondary_vector; uint32_t patch_records[SFERA_LANDSCAPE_PATCH_GRID_COUNT]; } SferaLandscapePatchLookupRuntime;
typedef struct SferaDebugWindowRuntime { uint32_t spider_window; } SferaDebugWindowRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaTerrainNeighborRuntime) == 0x20u, "terrain neighbor runtime ABI span");
typedef struct SferaLandscapeProbeRuntime { char size_path[16]; } SferaLandscapeProbeRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaLandscapeProbeRuntime) == 0x10u, "landscape probe path ABI span");
typedef struct SferaViewMotionRuntime { SferaFloatWord motion_terms[5]; SferaVec3Word reference_point; SferaVec3Word projected_a; SferaVec3Word projected_b; uint32_t update_serial; uint32_t mode_value; uint32_t initialized; } SferaViewMotionRuntime;
#define SFERA_RENDER_SAMPLE_COUNT UINT32_C(120)
typedef struct SferaRenderSampleRuntime { SferaFloatWord direction_x; SferaFloatWord direction_y; SferaFloatWord blend_weights[7]; uint32_t material_base; uint32_t record_base; uint32_t active_record; SferaFloatWord material_code; SferaFloatWord phase; float samples[SFERA_RENDER_SAMPLE_COUNT]; } SferaRenderSampleRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaViewMotionRuntime) == 0x44u, "view motion runtime ABI span");
SFERA_STATIC_ASSERT(offsetof(SferaViewMotionRuntime, reference_point) == 0x14u, "view motion reference point offset");
SFERA_STATIC_ASSERT(offsetof(SferaViewMotionRuntime, projected_a) == 0x20u, "view motion first projected point offset");
SFERA_STATIC_ASSERT(offsetof(SferaViewMotionRuntime, projected_b) == 0x2Cu, "view motion second projected point offset");
typedef struct SferaTerrainDiagnosticRuntime { char normalize_code[12]; char planting_message[0xC8]; } SferaTerrainDiagnosticRuntime;
#define SFERA_WORLD_SLOT_COUNT UINT32_C(401)
#define SFERA_WORLD_SLOT_STRIDE UINT32_C(0x398)
typedef union SferaWorldSlotRecord { uint32_t alignment[SFERA_WORLD_SLOT_STRIDE / 4u]; uint8_t storage[SFERA_WORLD_SLOT_STRIDE]; } SferaWorldSlotRecord;
typedef struct SferaWorldSlotTableRuntime { SferaWorldSlotRecord slots[SFERA_WORLD_SLOT_COUNT]; uint32_t active_limit; } SferaWorldSlotTableRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaWorldSlotRecord) == 0x398u, "world slot record ABI stride");
#define SFERA_CONFIG_TEXT_CAPACITY UINT32_C(0x00258240)
typedef struct SferaConfigTextRuntime { uint8_t owned_text[SFERA_CONFIG_TEXT_CAPACITY]; uint32_t current_text; uint32_t text_length; char format_scratch[512]; char parser_path[1024]; } SferaConfigTextRuntime;
#define SFERA_PLANTING_RECORD_STRIDE UINT32_C(0x468)
#define SFERA_PLANTING_RECORD_COUNT UINT32_C(100)
typedef union SferaPlantingRecord { uint32_t alignment[SFERA_PLANTING_RECORD_STRIDE / 4u]; uint8_t storage[SFERA_PLANTING_RECORD_STRIDE]; } SferaPlantingRecord;
typedef struct SferaPlantingTableRuntime { SferaPlantingRecord records[SFERA_PLANTING_RECORD_COUNT]; } SferaPlantingTableRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaPlantingRecord) == 0x468u, "planting record ABI stride");
#define SFERA_FONT_LOOKUP_CLASS_COUNT UINT32_C(5)
#define SFERA_FONT_LOOKUP_GLYPH_COUNT UINT32_C(256)
#define SFERA_RENDER_QUANTIZATION_TABLE_SIZE UINT32_C(3072)
#define SFERA_RENDER_BLEND_LUT_STORAGE_SIZE UINT32_C(0x4001)
typedef struct SferaStaticRenderLookupRuntime { float normalized_levels[7]; float command_samples[SFERA_RENDER_SAMPLE_COUNT]; float view_phase; uint16_t packed_format_code; uint16_t reserved_1e; uint32_t sample_state; uint32_t sample_flags[SFERA_RENDER_SAMPLE_COUNT]; uint8_t glyph_presence[SFERA_FONT_LOOKUP_GLYPH_COUNT]; uint32_t atlas_resources[SFERA_FONT_LOOKUP_GLYPH_COUNT][SFERA_FONT_LOOKUP_CLASS_COUNT]; uint8_t quantization_a[SFERA_RENDER_QUANTIZATION_TABLE_SIZE]; uint8_t quantization_b[SFERA_RENDER_QUANTIZATION_TABLE_SIZE]; uint32_t glyph_metrics[SFERA_FONT_LOOKUP_GLYPH_COUNT][SFERA_FONT_LOOKUP_CLASS_COUNT]; float projection_scale; uint8_t blend_lut[SFERA_RENDER_BLEND_LUT_STORAGE_SIZE]; uint8_t color_remap_a[256]; uint8_t color_remap_b[256]; uint8_t color_remap_c[256]; uint8_t legacy_crc_low_table[256]; } SferaStaticRenderLookupRuntime;
#define SFERA_UI_SORT_INDEX_COUNT UINT32_C(100)
#define SFERA_QUADTREE_GRID_DIMENSION UINT32_C(256)
typedef struct SferaSpatialIndexRuntime { uint32_t ui_sort_indices[SFERA_UI_SORT_INDEX_COUNT]; uint32_t quadtree_cells[SFERA_QUADTREE_GRID_DIMENSION * SFERA_QUADTREE_GRID_DIMENSION]; uint32_t quadtree_state; } SferaSpatialIndexRuntime;
#define SFERA_STARTUP_COMMAND_LINE_CAPACITY UINT32_C(0x160)
typedef struct SferaStartupCommandLineRuntime { char text[SFERA_STARTUP_COMMAND_LINE_CAPACITY]; uint32_t parser_state; } SferaStartupCommandLineRuntime;
#define SFERA_LIGHT_CANDIDATE_COUNT UINT32_C(30)
#define SFERA_LIGHT_CANDIDATE_STRIDE UINT32_C(0x3C)
#define SFERA_VIEW_TRANSFORM_STORAGE_SIZE UINT32_C(0x568)
typedef struct SferaCollisionScratchRuntime { uint8_t debug_vertices[0x70]; uint8_t light_candidates[SFERA_LIGHT_CANDIDATE_COUNT][SFERA_LIGHT_CANDIDATE_STRIDE]; uint16_t dynamic_indices_aux[SFERA_DYNAMIC_INDEX_SCRATCH_COUNT]; uint8_t view_transform[SFERA_VIEW_TRANSFORM_STORAGE_SIZE]; } SferaCollisionScratchRuntime;
SFERA_STATIC_ASSERT(sizeof(((SferaCollisionScratchRuntime*)0)->view_transform) == 0x568u, "view transform ABI span");
typedef union SferaGrassPatternRecord { uint32_t alignment[14]; uint8_t storage[0x38]; } SferaGrassPatternRecord;
SFERA_STATIC_ASSERT(sizeof(SferaGrassPatternRecord) == 0x38u, "grass pattern record ABI stride");
typedef struct SferaMbcStaticRuntime { uint32_t profile_fallback; uint32_t stack_default_values[256]; SferaU64Words startup_time; uint32_t init_marker; uint8_t init_flag; uint8_t service_flag; uint8_t reserved[2]; } SferaMbcStaticRuntime;
typedef struct SferaViewRenderObjectRuntime { uint8_t storage[0x15C]; } SferaViewRenderObjectRuntime;
typedef struct SferaViewRenderObjectsRuntime { SferaViewRenderObjectRuntime primary; SferaViewRenderObjectRuntime alternate; uint8_t reset_flag; } SferaViewRenderObjectsRuntime;
typedef struct SferaMapGeneratorRuntime { uint8_t storage[0x68]; } SferaMapGeneratorRuntime;
typedef struct SferaAlphaMaterialRuntime { int32_t selected_slot; uint8_t option_a; uint8_t option_b; uint8_t option_c; uint8_t reserved_07; float alpha[4]; } SferaAlphaMaterialRuntime;
typedef struct SferaClientArrayRuntime { SferaAutoBoundsArray e7_records; SferaAutoBoundsArray e8_indices; SferaAutoBoundsArray e9_indices; SferaAutoBoundsArray eb_records; SferaAutoBoundsArray ed_indices; SferaAutoBoundsArray line_102_indices; SferaAutoBoundsArray line_105_records; SferaAutoBoundsArray line_6b1_indices; SferaAutoBoundsArray line_6b3_indices; SferaAutoBoundsArray line_6b4_indices; SferaAutoBoundsArray line_6b5_records; SferaBoundCheckArray line_124d_records; SferaBoundCheckArray line_24de_records; SferaBoundCheckArray line_24e0_records; SferaBoundCheckArray line_24e2_records; } SferaClientArrayRuntime;
typedef struct SferaRecoveredStaticRuntime { uint32_t network_bytes_sent_snapshot; uint32_t network_bytes_retried_snapshot; uint32_t network_bytes_received_snapshot; uint32_t simulation_tick; uint32_t vertical_sync_enabled; uint32_t memory_warning_as_error; uint32_t mbc_stack_table_cursor; uint32_t server_number; uint32_t loadcount_guard; SferaVec3Word mbc_vector_scratch; uint8_t mbc_service_object[0x4010]; float inverse_40; SferaBoundCheckArray legacy_light_arrays[3]; uint32_t view_transition_counter; uint32_t view_direction_state; uint32_t render_record_state; uint8_t glyph_presence_shadow[256]; SferaGrassPatternRecord grass_patterns[30]; uint32_t scene_mode; uint32_t scene_counter; uint8_t scene_lock[24]; uint32_t input_state_a; float cursor_accumulator; uint32_t input_state_b; uint32_t render_gate; uint32_t text_size_height; uint32_t client_state_01; uint32_t client_state_02; uint32_t client_state_03; float ui_cell_width; float clip_depth; uint32_t client_state_04; uint32_t client_state_05; uint32_t client_state_06; uint32_t graphics_state; uint32_t font_renderer_state; uint32_t font_state; uint32_t render_state_07; uint32_t render_state_08; uint32_t render_state_09; uint32_t render_state_10; uint32_t scene_state_07; uint32_t scene_state_08; uint32_t scene_state_09; uint32_t interaction_enabled; uint32_t interaction_input_flags; uint32_t environment_lookup_result; float primary_frame_interval; float secondary_frame_interval; float transition_factor; uint32_t animation_state; float animation_phase; uint32_t animation_result_a; uint32_t animation_result_b; SferaAutoBoundsArray primary_auto_array; SferaVec3Word flare_clip_vector; SferaAutoBoundsArray secondary_auto_array; SferaAutoBoundsArray tertiary_auto_array; uint32_t ui_counter_a; uint32_t ui_counter_b; } SferaRecoveredStaticRuntime;
#define SFERA_PENDING_KEY_CAPACITY UINT32_C(30)
typedef struct SferaPendingKeyRuntime { uint32_t count; uint32_t key_codes[SFERA_PENDING_KEY_CAPACITY]; } SferaPendingKeyRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaPendingKeyRuntime) == 0x7Cu, "pending key runtime size");
#define SFERA_RELAUNCH_ARGUMENT_CAPACITY UINT32_C(0x84)
typedef struct SferaRelaunchRuntime { char argument[SFERA_RELAUNCH_ARGUMENT_CAPACITY]; } SferaRelaunchRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaRelaunchRuntime) == 0x84u, "relaunch argument storage size");
#define SFERA_WORLD_RENDER_QUEUE_CAPACITY UINT32_C(0xDAC)
typedef struct SferaWorldRenderQueueRuntime { uint32_t entries[SFERA_WORLD_RENDER_QUEUE_CAPACITY + 1u]; } SferaWorldRenderQueueRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaWorldRenderQueueRuntime) == 0x36B4u, "world render queue storage size");
SFERA_STATIC_ASSERT(sizeof(SferaTerrainDiagnosticRuntime) == 0xD4u, "terrain diagnostic runtime ABI span");
SFERA_STATIC_ASSERT(offsetof(SferaTerrainDiagnosticRuntime, planting_message) == 0x0Cu, "terrain diagnostic message offset");

typedef struct SferaEffectListenerMap { uint8_t comparator; uint8_t _alignment[3]; uint32_t head; uint32_t size; } SferaEffectListenerMap;
typedef struct SferaIntrusiveListHeader { uint32_t first; uint32_t last; } SferaIntrusiveListHeader;
SFERA_STATIC_ASSERT(sizeof(SferaIntrusiveListHeader) == 8u, "SferaIntrusiveListHeader ABI layout");

typedef struct SferaEffectManagerRuntime { uint32_t deferred_lifecycle; uint32_t render_cycle; uint32_t active_resource_count; uint32_t detail_setting; uint32_t effects_enabled; uint32_t render_slot_count; uint32_t particle_random_table; uint32_t particle_resource_head; uint32_t effect_definition_head; uint32_t initialized; uint32_t render_sort_indices; uint32_t render_index_buffer; uint32_t render_batch_buffer; uint32_t active_effect_count; SferaIntrusiveListHeader active_effects; uint32_t generation; uint32_t last_processed_generation; uint32_t flare_transition; uint32_t flare_enabled; uint32_t flare_alpha; SferaVec3F viewer_position; SferaBoundCheckArray render_slots; SferaEffectListenerMap effect_listeners; } SferaEffectManagerRuntime;

typedef struct SferaMbcValue { uint32_t type; uint32_t width; uint32_t source_id; uint32_t range_begin; uint32_t range_end; uint32_t payload[3]; } SferaMbcValue;
SFERA_STATIC_ASSERT(sizeof(SferaMbcValue) == 32u, "SferaMbcValue layout");
typedef struct SferaMbcExecutionContext { uint32_t program_table_base; uint32_t instruction_cursor; uint32_t bytecode_base; uint32_t process_memory_base; uint32_t process_index; uint32_t program_index; uint32_t process_id; uint32_t active_process; } SferaMbcExecutionContext;
SFERA_STATIC_ASSERT(sizeof(SferaMbcExecutionContext) == 0x20u, "MBC execution context ABI size");
SFERA_STATIC_ASSERT(offsetof(SferaMbcExecutionContext, process_index) == 0x10u, "MBC execution context process index offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcExecutionContext, process_id) == 0x18u, "MBC execution context process id offset");
typedef struct SferaFindData64i32 { uint32_t attrib; uint32_t reserved_04; int64_t time_create; int64_t time_access; int64_t time_write; uint32_t size; char name[260]; } SferaFindData64i32;
typedef struct SferaMbcFileIndexNode { uint32_t next; uint32_t prev; char name[0x40]; uint8_t reserved_048[0xC0]; int64_t checksum; uint32_t file_size; uint32_t reserved_114; } SferaMbcFileIndexNode;
SFERA_STATIC_ASSERT(sizeof(SferaFindData64i32) == 0x128, "_finddata64i32 ABI size");
SFERA_STATIC_ASSERT(offsetof(SferaFindData64i32, size) == 0x20, "_finddata64i32 size offset");
SFERA_STATIC_ASSERT(offsetof(SferaFindData64i32, name) == 0x24, "_finddata64i32 name offset");
SFERA_STATIC_ASSERT(sizeof(SferaMbcFileIndexNode) == 0x118, "MBC file index node size");
SFERA_STATIC_ASSERT(offsetof(SferaMbcFileIndexNode, checksum) == 0x108, "MBC file index checksum offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcFileIndexNode, file_size) == 0x110, "MBC file index size offset");

typedef struct SferaMbcModuleMemoryStats { uint32_t process_count; uint32_t process_memory_bytes; uint32_t dynamic_memory_bytes; } SferaMbcModuleMemoryStats;
SFERA_STATIC_ASSERT(sizeof(SferaMbcModuleMemoryStats) == 0x0Cu, "MBC module memory stats ABI size");

typedef struct SferaMbcNamedVectorRecord { uint32_t values; uint32_t size; uint32_t reserved_08; uint32_t name; } SferaMbcNamedVectorRecord;
SFERA_STATIC_ASSERT(sizeof(SferaMbcNamedVectorRecord) == 0x10, "MBC named vector record ABI size");

typedef struct SferaMbcModuleRecord { char name[0x20]; uint8_t runtime[0x8B8]; } SferaMbcModuleRecord;
SFERA_STATIC_ASSERT(sizeof(SferaMbcModuleRecord) == 0x8D8, "MBC module record ABI size");
SFERA_STATIC_ASSERT(offsetof(SferaMbcModuleRecord, runtime) == 0x20, "MBC module runtime offset");

typedef struct SferaMbcProcessRecord { uint8_t file_header_prefix[0x0C]; uint8_t header_code_0c; uint8_t header_code_0d; uint8_t header_code_0e; uint8_t header_code_0f; char name[0x20]; uint8_t module_key[0x10]; uint32_t field_040; uint32_t module_tag; uint32_t bytecode_base; uint32_t bytecode_size; uint32_t process_memory_base; uint32_t process_memory_size; uint32_t program_count; uint32_t program_table_base; uint32_t field_060; uint32_t auxiliary_record_count; uint32_t auxiliary_record_table; int32_t chain_prev_index; int32_t chain_next_index; uint16_t program_map_a[4]; uint16_t program_map_b[4]; uint32_t field_084; uint32_t field_088; uint32_t field_08c; uint32_t field_090; uint32_t flags; uint8_t reserved_098[0x02]; uint8_t field_09a[0x04]; uint8_t reserved_09e[0x02]; uint32_t owned_block_a; uint32_t cleanup_entries; uint32_t cleanup_entry_count; uint32_t cleanup_capacity; uint32_t owned_block_b; uint32_t process_id; uint8_t state_byte_b8; uint8_t execution_linked; uint8_t reserved_0ba[0x02]; uint32_t field_0bc; uint32_t field_0c0; uint32_t workspace_base; int32_t execution_prev_index; int32_t execution_next_index; uint32_t module_record_base; uint32_t field_0d4; int32_t field_0d8; uint8_t reserved_0dc[0xFC]; uint8_t execution_scratch[0xFC]; uint16_t code_range_ids[8]; uint32_t code_range_begin[8]; uint32_t code_range_size[8]; uint32_t code_range_memory_offset[8]; uint16_t code_range_count; uint16_t reserved_346; } SferaMbcProcessRecord;
SFERA_STATIC_ASSERT(sizeof(SferaMbcProcessRecord) == 0x348, "MBC process record ABI size");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, name) == 0x10, "MBC process name offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, module_key) == 0x30, "MBC process module key offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, field_040) == 0x40, "MBC process field 040 offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, module_tag) == 0x44, "MBC process module tag offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, bytecode_base) == 0x48, "MBC process bytecode offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, bytecode_size) == 0x4C, "MBC process bytecode size offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, process_memory_base) == 0x50, "MBC process memory offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, process_memory_size) == 0x54, "MBC process memory size offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, program_count) == 0x58, "MBC process program count offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, program_table_base) == 0x5C, "MBC process program table offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, auxiliary_record_count) == 0x64, "MBC process auxiliary count offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, auxiliary_record_table) == 0x68, "MBC process auxiliary table offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, chain_prev_index) == 0x6C, "MBC process chain prev offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, chain_next_index) == 0x70, "MBC process chain next offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, program_map_a) == 0x74, "MBC process program map A offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, program_map_b) == 0x7C, "MBC process program map B offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, field_084) == 0x84, "MBC process field 084 offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, flags) == 0x94, "MBC process flags offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, field_09a) == 0x9A, "MBC process field 09a offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, owned_block_a) == 0xA0, "MBC process owned block A offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, cleanup_entries) == 0xA4, "MBC process cleanup entries offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, cleanup_entry_count) == 0xA8, "MBC process cleanup count offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, owned_block_b) == 0xB0, "MBC process owned block B offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, process_id) == 0xB4, "MBC process id offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, workspace_base) == 0xC4, "MBC process workspace offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, execution_prev_index) == 0xC8, "MBC process execution prev offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, execution_next_index) == 0xCC, "MBC process execution next offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, module_record_base) == 0xD0, "MBC process module record offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, execution_scratch) == 0x1D8, "MBC process scratch offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, code_range_ids) == 0x2D4, "MBC process code range ids offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, code_range_begin) == 0x2E4, "MBC process code range begin offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, code_range_size) == 0x304, "MBC process code range size offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, code_range_memory_offset) == 0x324, "MBC process code range memory offset");
SFERA_STATIC_ASSERT(offsetof(SferaMbcProcessRecord, code_range_count) == 0x344, "MBC process code range count offset");

#define SFERA_MBC_SEND_FIELD_STORAGE_WORD_COUNT 4088u
#define SFERA_MBC_VALUE_STACK_ENTRY_COUNT 256u
#define SFERA_MBC_MODULE_COUNT 4096u
#define SFERA_MBC_MODULE_STATS_COUNT 4000u
#define SFERA_MBC_STARTUP_OPTION_CAPACITY 0x80u
#define SFERA_MBC_TEXT_BUFFER_CAPACITY 10000u
#define SFERA_MBC_LINK_WORKSPACE_WORD_COUNT 80u
typedef struct SferaMbcValueStackStorage { SferaMbcValue base_slot; SferaMbcValue entries[SFERA_MBC_VALUE_STACK_ENTRY_COUNT]; } SferaMbcValueStackStorage;
typedef struct SferaMbcInterpreterStorage { uint32_t send_field_data[SFERA_MBC_SEND_FIELD_STORAGE_WORD_COUNT]; SferaMbcValueStackStorage value_stack; SferaMbcModuleRecord module_records[SFERA_MBC_MODULE_COUNT]; } SferaMbcInterpreterStorage;
typedef struct SferaMbcSavedInvocationState { uint32_t process_memory_base; uint32_t value_stack_size; uint32_t argument_cursor; uint32_t argument_end; } SferaMbcSavedInvocationState;
SFERA_STATIC_ASSERT(offsetof(SferaMbcInterpreterStorage, value_stack) == 0x3FE0u, "MBC send field storage size");
SFERA_STATIC_ASSERT(offsetof(SferaMbcValueStackStorage, entries) == 0x20u, "MBC value stack slot one offset");
SFERA_STATIC_ASSERT(sizeof(SferaMbcValueStackStorage) == 0x2020u, "MBC value stack storage size");
SFERA_STATIC_ASSERT(offsetof(SferaMbcInterpreterStorage, module_records) == 0x6000u, "MBC module pool offset");
SFERA_STATIC_ASSERT(sizeof(SferaMbcInterpreterStorage) == 0x8DE000u, "MBC interpreter storage size");
SFERA_STATIC_ASSERT(SFERA_MBC_MODULE_STATS_COUNT * sizeof(SferaMbcModuleMemoryStats) == 0xBB80u, "MBC module memory stats storage size");
SFERA_STATIC_ASSERT(SFERA_MBC_LINK_WORKSPACE_WORD_COUNT * sizeof(uint16_t) == 0xA0u, "MBC link workspace size");

typedef struct SferaConfigParserFrame { uint32_t container_begin; uint32_t count_or_cursor; uint32_t payload_end; } SferaConfigParserFrame;
SFERA_STATIC_ASSERT(sizeof(SferaConfigParserFrame) == 0x0Cu, "config parser frame ABI size");
typedef struct SferaConfigParserRuntime { uint32_t current_value_type; uint32_t line_number; char token[256]; uint32_t frame_depth; uint32_t open_mode; SferaConfigParserFrame frames[20]; char error_message[256]; } SferaConfigParserRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaConfigParserRuntime) == 0x300u, "config parser runtime ABI size");
SFERA_STATIC_ASSERT(offsetof(SferaConfigParserRuntime, line_number) == 0x04u, "config parser line offset");
SFERA_STATIC_ASSERT(offsetof(SferaConfigParserRuntime, token) == 0x08u, "config parser token offset");
SFERA_STATIC_ASSERT(offsetof(SferaConfigParserRuntime, frame_depth) == 0x108u, "config parser depth offset");
SFERA_STATIC_ASSERT(offsetof(SferaConfigParserRuntime, open_mode) == 0x10Cu, "config parser mode offset");
SFERA_STATIC_ASSERT(offsetof(SferaConfigParserRuntime, frames) == 0x110u, "config parser frame offset");
SFERA_STATIC_ASSERT(offsetof(SferaConfigParserRuntime, error_message) == 0x200u, "config parser error offset");

typedef struct SferaMbcRuntime { int32_t execution_chain_tail; int32_t execution_chain_head; uint32_t execution_chain_count; int32_t process_chain_first; int32_t process_chain_last; uint32_t program_table_base; uint32_t shared_buffer_size; uint32_t instruction_cursor; char file_search_pattern[0x40]; uint32_t named_vector_cursor; char diagnostic_context[0x5E8]; uint8_t module_link_stream[0x724]; uint16_t link_workspace_words[SFERA_MBC_LINK_WORKSPACE_WORD_COUNT]; uint32_t argument_count; uint32_t argument_end; uint32_t process_index; uint32_t current_instruction_address; uint32_t active_tag; SferaFindData64i32 file_find_data; SferaFindData64i32 script_find_data; char startup_option[SFERA_MBC_STARTUP_OPTION_CAPACITY]; uint8_t text_buffer[SFERA_MBC_TEXT_BUFFER_CAPACITY]; uint32_t call_frame_depth; uint32_t module_link_stream_size; SferaMbcProcessRecord processes[65536]; uint32_t process_search_cursor; uint32_t instruction_step_count; uint32_t link_relocation_offsets[24000]; uint32_t program_index; uint32_t pending_program_index; uint32_t dispatch_process_count; uint32_t resolved_position_pointer; uint32_t file_index_scan_prev; uint32_t execution_context_depth; uint32_t opcode_handlers[256]; uint32_t bytecode_base; uint32_t registered_object_count; SferaMbcExecutionContext execution_context_stack[100]; uint32_t file_crc32; uint32_t argument_cursor; uint32_t frame_stack_base[22]; uint32_t halt_all_requested; uint32_t link_relocation_count; uint8_t send_field_width[4096]; uint32_t active_program_record; uint32_t value_stack_size; uint32_t file_index_current; char file_path_buffer[0x40]; uint8_t file_io_buffer[0x10000]; uint32_t file_index_scan; uint32_t active_process; uint32_t registered_objects[2100]; uint32_t process_memory_base; uint32_t file_crc32_table[256]; char file_normalized_name[0x44]; uint32_t send_field_count; uint32_t execution_failed; uint32_t trace_steps_remaining; uint8_t current_opcode; uint8_t trace_program_header_pending; uint8_t trace_process_header_pending; uint8_t trace_reserved; SferaMbcNamedVectorRecord named_vectors[1000]; uint8_t shared_buffer[0x258240]; uint32_t named_vector_count; uint32_t file_index_head; SferaMbcSavedInvocationState saved_invocation; } SferaMbcRuntime;

#undef SFERA_STATIC_ASSERT

#ifdef __cplusplus
extern "C" {
#endif
extern SferaItemArray g_sfera_effect_items;
extern SferaItemArray g_sfera_sound_effect_items;
extern SferaServerWall g_sfera_server_wall;
extern SferaNetworkRuntime g_sfera_network_runtime;
extern SferaDirectPlayRuntime g_sfera_directplay_runtime;
extern SferaNetworkConnectionCheckerRuntime g_sfera_network_connection_checker;
extern SferaNetworkSendRuntime g_sfera_network_send_runtime;
extern SferaFontRuntime g_sfera_font_runtime;
extern SferaCursorManagerRuntime g_sfera_cursor_manager_runtime;
extern SferaSliceReference32 g_sfera_pop_slice_fallback;
extern SferaSliceReference32 g_sfera_pop_sliceup_fallback;
extern SferaInterpreterScratchRuntime g_sfera_interpreter_scratch_runtime;
extern SferaGraphicsRuntime g_sfera_graphics_runtime;
extern SferaSceneRenderRuntime g_sfera_scene_render_runtime;
extern SferaMatrix4x4F g_sfera_model_coordinate_matrix;
extern SferaMatrix4x4F g_sfera_character_frame_matrix;
extern SferaBoundsCornersRuntime g_sfera_client_bounds_corners;
extern SferaMatrix4x4F g_sfera_character_rotation_matrix;
extern SferaScreenVertex g_sfera_sky_screen_vertices[SFERA_SKY_SCREEN_VERTEX_COUNT];
extern SferaScreenVertex g_sfera_landscape_screen_vertices[SFERA_LANDSCAPE_SCREEN_VERTEX_COUNT];
extern SferaBoundCheckArray g_sfera_character_index_map;
extern SferaBoundCheckArray g_sfera_mesh_partition_indices;
extern SferaGraphicsOptionsRuntime g_sfera_graphics_options_runtime;
extern SferaSphereOptionsRuntime g_sfera_sphere_options_runtime;
extern SferaOptionsDialogRuntime g_sfera_options_dialog_runtime;
extern uint32_t g_sfera_options_dialog_cleanup_state;
extern SferaWindowRuntime g_sfera_window_runtime;
extern SferaInputDeviceRuntime g_sfera_input_device_runtime;
extern SferaScreenClipRuntime g_sfera_screen_clip_runtime;
extern SferaDirectInputRuntime g_sfera_direct_input_runtime;
extern SferaShadowRuntime g_sfera_shadow_runtime;
extern SferaWorldRenderRuntime g_sfera_world_render_runtime;
extern SferaWorldLoadRuntime g_sfera_world_load_runtime;
extern SferaWorldBoundsRuntime g_sfera_world_bounds_runtime;
extern SferaRenderLookupRuntime g_sfera_render_lookup_runtime;
extern SferaLandscapeRenderRuntime g_sfera_landscape_render_runtime;
extern SferaProcessRuntime g_sfera_process_runtime;
extern SferaClientProcessRuntime g_sfera_client_process_runtime;
extern SferaMainRenderRuntime g_sfera_main_render_runtime;
extern SferaSceneControlRuntime g_sfera_scene_control_runtime;
extern SferaMainAuxRuntime g_sfera_main_aux_runtime;
extern SferaLandscapeMapRuntime g_sfera_landscape_map_runtime;
extern SferaSkyRuntime g_sfera_sky_runtime;
extern SferaTextureCacheRuntime g_sfera_texture_cache_runtime;
extern SferaFontAtlasLayoutRuntime g_sfera_font_atlas_layout_runtime;
extern SferaFontAtlasStagingRuntime g_sfera_font_atlas_staging_runtime;
extern SferaPartitionSortRuntime g_sfera_partition_sort_runtime;
extern SferaErrorMessageScratchRuntime g_sfera_error_message_scratch_runtime;
extern SferaMaterialFilterRuntime g_sfera_material_filter_runtime;
extern SferaGrassMapRuntime g_sfera_grass_map_runtime;
extern SferaFontFactoryRuntime g_sfera_font_factory_runtime;
extern SferaPhysicsRuntime g_sfera_physics_runtime;
extern SferaViewGeometryRuntime g_sfera_view_geometry_runtime;
extern SferaViewProjectionScratchRuntime g_sfera_view_projection_scratch_runtime;
extern SferaMatrix4x4F g_sfera_model_transform_scratch_matrix;
extern SferaBoundsCornersRuntime g_sfera_model_bounds_corners;
extern SferaSkyInterpolationRuntime g_sfera_sky_interpolation_runtime;
extern SferaColorExpansionRuntime g_sfera_color_expansion_runtime;
extern SferaSpatialStateRuntime g_sfera_spatial_states[SFERA_SPATIAL_STATE_COUNT];
extern SferaUiParseScratchRuntime g_sfera_ui_parse_scratch_runtime;
extern SferaCriticalDiagnosticsRuntime g_sfera_critical_diagnostics_runtime;
extern SferaTerrainNeighborRuntime g_sfera_terrain_neighbor_runtime;
extern SferaLandscapePatchLookupRuntime g_sfera_landscape_patch_lookup_runtime;
extern SferaDebugWindowRuntime g_sfera_debug_window_runtime;
extern SferaLandscapeProbeRuntime g_sfera_landscape_probe_runtime;
extern SferaViewMotionRuntime g_sfera_view_motion_runtime;
extern SferaRenderSampleRuntime g_sfera_render_sample_runtime;
extern SferaSceneVectorRuntime g_sfera_scene_vector_runtime;
extern SferaVec3Word g_sfera_flare_projection;
extern SferaTerrainDiagnosticRuntime g_sfera_terrain_diagnostic_runtime;
extern SferaWorldSlotTableRuntime g_sfera_world_slot_table_runtime;
extern SferaConfigTextRuntime g_sfera_config_text_runtime;
extern SferaPlantingTableRuntime g_sfera_planting_table_runtime;
extern SferaStaticRenderLookupRuntime g_sfera_static_render_lookup_runtime;
extern SferaMbcStaticRuntime g_sfera_mbc_static_runtime;
extern SferaViewRenderObjectsRuntime g_sfera_view_render_objects_runtime;
extern SferaMapGeneratorRuntime g_sfera_map_generator_runtime;
extern SferaAlphaMaterialRuntime g_sfera_alpha_material_runtime;
extern SferaClientArrayRuntime g_sfera_client_array_runtime;
extern uint8_t g_sfera_shadow_object_storage[SFERA_TRANSFORM_BOUNDS_STORAGE_SIZE];
extern uint8_t g_sfera_options_dialog_object_storage[SFERA_TRANSFORM_BOUNDS_STORAGE_SIZE];
extern SferaSpatialIndexRuntime g_sfera_spatial_index_runtime;
extern SferaStartupCommandLineRuntime g_sfera_startup_command_line_runtime;
extern SferaCollisionScratchRuntime g_sfera_collision_scratch_runtime;
extern SferaRecoveredStaticRuntime g_sfera_recovered_static_runtime;
extern SferaPendingKeyRuntime g_sfera_pending_key_runtime;
extern SferaRelaunchRuntime g_sfera_relaunch_runtime;
extern SferaWorldRenderQueueRuntime g_sfera_world_render_queue_runtime;
extern SferaViewSpatialRuntime g_sfera_view_spatial_runtime;
extern SferaSpatialBoundsRuntime g_sfera_spatial_bounds_runtime;
extern SferaWorldObjectRuntime g_sfera_world_objects;
extern SferaGrassRuntime g_sfera_grass_runtime;
extern SferaLightRuntime g_sfera_light_runtime;
extern SferaLandscapeRuntime g_sfera_landscape_runtime;
extern SferaLandscapeInterpolationRuntime g_sfera_landscape_interpolation_runtime;
extern SferaCollisionRuntime g_sfera_collision_runtime;
extern SferaSceneArrayRuntime g_sfera_scene_array_runtime;
extern SferaSceneBuildRuntime g_sfera_scene_build_runtime;
extern SferaWeatherRuntime g_sfera_weather_runtime;
extern SferaModelRuntime g_sfera_model_runtime;
extern SferaModelRegistryRuntime g_sfera_model_registry_runtime;
extern SferaModelMaterialLookupRuntime g_sfera_model_material_lookup_runtime;
extern uint16_t g_sfera_dynamic_index_scratch[SFERA_DYNAMIC_INDEX_SCRATCH_COUNT];
extern SferaNatureRuntime g_sfera_nature_runtime;
extern SferaSoundRuntime g_sfera_sound_runtime;
extern SferaWarningLogRuntime g_sfera_warning_log_runtime;
extern SferaControlOptionsRuntime g_sfera_control_options;
extern SferaSpriteRuntime g_sfera_sprite_runtime;
extern SferaCrashRuntime g_sfera_crash_runtime;
extern SferaContoursRuntime g_sfera_contours_runtime;
extern SferaDynGreenRuntime g_sfera_dyn_green_runtime;
extern SferaExecutionMonitorRuntime g_sfera_execution_monitor_runtime;
extern SferaErrorLogRuntime g_sfera_error_log_runtime;
extern SferaLogRuntime g_sfera_log_runtime;
extern SferaPacketCodecRuntime g_sfera_packet_codec_runtime;
extern SferaFrameRuntime g_sfera_frame_runtime;
extern SferaHighResolutionClockRuntime g_sfera_high_resolution_clock_runtime;
extern SferaProfilerRuntime g_sfera_profiler_runtime;
extern SferaCrc32Runtime g_sfera_crc32_runtime;
extern SferaUiLoadScratchRuntime g_sfera_ui_load_scratch_runtime;
extern SferaHyperTextScratchRuntime g_sfera_hypertext_scratch_runtime;
extern SferaStringLookupRuntime g_sfera_string_lookup_runtime;
extern SferaAsciiLowerRuntime g_sfera_ascii_lower_runtime;
extern SferaModelLoadScratchRuntime g_sfera_model_load_scratch_runtime;
extern SferaStringUtilityRuntime g_sfera_string_utility_runtime;
extern SferaNetworkProbeRuntime g_sfera_network_probe_runtime;
extern SferaConfigParseScratchRuntime g_sfera_config_parse_scratch_runtime;
extern SferaMusicRuntime g_sfera_music_runtime;
extern SferaContainerDiagnosticsRuntime g_sfera_container_diagnostics_runtime;
extern SferaOleHostAbi g_sfera_ole_host_abi;
extern uint32_t g_sfera_graphics_display_depth_bits;
extern SferaMainCommandStateRuntime g_sfera_main_command_state_runtime;
extern SferaMainInputStateRuntime g_sfera_main_input_state_runtime;
extern SferaMainViewStateRuntime g_sfera_main_view_state_runtime;
extern SferaMainUiStateRuntime g_sfera_main_ui_state_runtime;
extern uint16_t g_sfera_screen_quad_indices[SFERA_SCREEN_QUAD_INDEX_COUNT];
extern SferaClientConfigRuntime g_sfera_client_config_runtime;
extern SferaGrassPlacementRuntime g_sfera_grass_placement_runtime;
extern SferaInterfaceCoreRuntime g_sfera_interface_core_runtime;
extern SferaClientMainScalarRuntime g_sfera_client_main_scalar_runtime;
extern SferaInterScalarRuntime g_sfera_inter_scalar_runtime;
extern SferaTextureSetScalarRuntime g_sfera_texture_set_scalar_runtime;
extern SferaTextureRegistryRuntime g_sfera_texture_registry_runtime;
extern SferaInterfaceRuntime g_sfera_interface_runtime;
extern SferaStdAllocator g_sfera_std_allocator;
extern SferaMemoryRuntime g_sfera_memory_runtime;
extern SferaMemorySourceHashRuntime g_sfera_memory_source_hash_runtime;
extern SferaAllocationHashRuntime g_sfera_allocation_hash_runtime;
extern SferaDiagnosticLogObjectRuntime g_sfera_log_memory_object;
extern SferaDiagnosticLogObjectRuntime g_sfera_log_warnings_object;
extern SferaDiagnosticLogObjectRuntime g_sfera_log_errors_object;
extern uint8_t g_sfera_diagnostic_log_byte;
extern SferaWin32DialogRegistryRuntime g_sfera_win32_dialog_registry;
extern SferaControlReferenceRegistryRuntime g_sfera_control_reference_registry;
extern SferaCursorTextureRegistryRuntime g_sfera_cursor_texture_registry;
extern uint32_t g_sfera_cursor_texture_registry_guard;
extern SferaD3D9SemanticStateRuntime g_sfera_d3d9_semantic_state;
extern SferaBrowserWindowRuntime g_sfera_browser_window_runtime;
extern SferaMinimapTextureRuntime g_sfera_minimap_texture_runtime;
extern uint32_t g_sfera_control_reference_registry_guard;
extern SferaCrtStartupRuntime g_sfera_crt_startup_runtime;
extern SferaCrashReportRuntime g_sfera_crash_report_runtime;
extern SferaRenderBufferCapacities g_sfera_render_buffer_capacities;
extern uint32_t g_sfera_blood_effect_instance;
extern SferaFileRuntime g_sfera_file_runtime;
extern SferaEffectManagerRuntime g_sfera_effect_manager;
extern SferaConfigParserRuntime g_sfera_config_parser_runtime;
extern SferaMbcRuntime* g_sfera_mbc_runtime;
extern SferaMbcInterpreterStorage g_sfera_mbc_interpreter_storage;
extern SferaMbcModuleMemoryStats g_sfera_mbc_module_memory_stats[SFERA_MBC_MODULE_STATS_COUNT];
extern char g_sfera_array_error_buffer[256];
extern SferaMsvcString32 g_sfera_shared_parser_whitespace;
extern SferaMsvcString32 g_sfera_shared_parser_path_separators;
extern SferaMsvcString32 g_sfera_server_parser_whitespace;
extern SferaMsvcString32 g_sfera_server_parser_path_separators;
extern SferaMsvcString32 g_sfera_menu_parser_whitespace;
extern SferaMsvcString32 g_sfera_menu_parser_path_separators;
extern SferaMsvcString32 g_sfera_menu_list_missing_parameter_message;
extern SferaMsvcString32 g_sfera_menu_not_enough_arguments_message;
extern SferaMsvcString32 g_sfera_menu_sprite_not_found_message;
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif
uint32_t sfera_zlib_adler32(uint32_t adler, uint32_t buffer_address, uint32_t length);
void sfera_zlib_deflate_put_short_msb(uint32_t state_address, uint32_t value);
void sfera_zlib_deflate_flush_pending(uint32_t stream_address);
void sfera_zlib_deflate_lm_init(uint32_t state_address);
void sfera_zlib_deflate_fill_window(uint32_t state_address);
uint32_t sfera_zlib_deflate_read_buf(uint32_t stream_address, uint32_t destination_address, uint32_t size);
uint32_t sfera_zlib_deflate_longest_match(uint32_t state_address, uint32_t current_match);
uint32_t sfera_zlib_fixed_literal_length(uint32_t symbol);
uint32_t sfera_zlib_fixed_literal_code(uint32_t symbol);
uint32_t sfera_zlib_fixed_distance_code(uint32_t symbol);
void sfera_zlib_pq_down_heap(uint32_t state_address, uint32_t tree_address, uint32_t heap_index);
void sfera_zlib_generate_bit_lengths(uint32_t state_address, uint32_t descriptor_address);
void sfera_zlib_generate_codes(uint32_t tree_address, int32_t max_code, uint32_t bit_counts_address);
void sfera_zlib_init_block(uint32_t state_address);
void sfera_zlib_tree_init(uint32_t state_address);
void sfera_zlib_build_tree(uint32_t state_address, uint32_t descriptor_address);
void sfera_zlib_scan_tree(uint32_t state_address, uint32_t tree_address, int32_t max_code);
void sfera_zlib_send_tree(uint32_t state_address, uint32_t tree_address, int32_t max_code);
int32_t sfera_zlib_build_bit_length_tree(uint32_t state_address);
void sfera_zlib_send_all_trees(uint32_t state_address, uint32_t literal_codes, uint32_t distance_codes, uint32_t bit_length_codes);
void sfera_zlib_flush_block(uint32_t state_address, uint32_t buffer_address, uint32_t stored_length, uint32_t end_of_file);
void sfera_zlib_compress_block(uint32_t state_address, uint32_t literal_tree_address, uint32_t distance_tree_address);
uint32_t sfera_zlib_bit_reverse(uint32_t value, uint32_t bit_count);
void sfera_zlib_bit_flush(uint32_t state_address);
void sfera_zlib_bit_windup(uint32_t state_address);
void sfera_zlib_copy_stored_block(uint32_t state_address, uint32_t buffer_address, uint32_t length, uint32_t write_header);
void sfera_zlib_write_stored_block(uint32_t state_address, uint32_t buffer_address, uint32_t length, uint32_t end_of_file);
void sfera_zlib_align_static_block(uint32_t state_address);
void sfera_zlib_set_data_type(uint32_t state_address);
uint32_t sfera_zlib_deflate_reset(uint32_t stream_address);
uint32_t sfera_zlib_deflate(uint32_t stream_address, int32_t flush);
uint32_t sfera_zlib_deflate_stored(uint32_t state_address, int32_t flush);
uint32_t sfera_zlib_deflate_fast(uint32_t state_address, int32_t flush);
uint32_t sfera_zlib_deflate_slow(uint32_t state_address, int32_t flush);
uint32_t sfera_zlib_inflate_fixed(uint32_t literal_bits_address, uint32_t distance_bits_address, uint32_t literal_root_address, uint32_t distance_root_address);
uint32_t sfera_zlib_huft_build(uint32_t lengths_address, uint32_t code_count, uint32_t simple_count, uint32_t base_values_address, uint32_t extra_bits_address, uint32_t root_address, uint32_t root_bits_address, uint32_t pool_address, uint32_t used_address, uint32_t work_address);
#ifdef __cplusplus
}
#endif
SFERA_STATIC_INLINE uint32_t sfera_calendar_days_in_month(uint32_t month) { if (month < 1u || month > 12u) { return 0u; } return 30u + ((month + (month > 7u ? 1u : 0u)) & 1u) - (month == 2u ? 2u : 0u); }
SFERA_STATIC_INLINE uint32_t sfera_calendar_days_before_month(uint32_t month) { uint32_t days = 0u; uint32_t current; if (month < 1u || month > 13u) { return 0u; } for (current = 1u; current < month; ++current) { days += sfera_calendar_days_in_month(current); } return days; }

#undef SFERA_STATIC_INLINE

/* ===== External C++ ABI bridge ===== */
/* MSVCP100 and compiler-runtime exception objects still need concrete ABI slots until those external types are lifted separately. */
#define SFERA_MSVCP100_VPTR_BASIC_FILEBUF ((uint32_t)(uintptr_t)&g_sfera_msvcp100_vtable_basic_filebuf[0])
#define SFERA_MSVCP100_VPTR_BASIC_OFSTREAM ((uint32_t)(uintptr_t)&g_sfera_msvcp100_vtable_basic_ofstream[0])
#define SFERA_MSVCP100_VPTR_BASIC_IFSTREAM ((uint32_t)(uintptr_t)&g_sfera_msvcp100_vtable_basic_ifstream[0])
#define SFERA_MSVCP100_VPTR_BASIC_STRINGBUF ((uint32_t)(uintptr_t)&g_sfera_msvcp100_vtable_basic_stringbuf[0])
#define SFERA_MSVCP100_VPTR_BASIC_OSTRINGSTREAM ((uint32_t)(uintptr_t)&g_sfera_msvcp100_vtable_basic_ostringstream[0])
#define SFERA_LEGACY_VPTR_BAD_ALLOC ((uint32_t)(uintptr_t)&g_sfera_legacy_vtable_bad_alloc[0])
#define SFERA_LEGACY_VPTR_COM_ERROR ((uint32_t)(uintptr_t)&g_sfera_legacy_vtable_com_error[0])

/* ===== Recovered static symbols ===== */
/* Remaining source-VA symbols are compatibility identities for state that has not
 * been semantically lifted yet. Resolved subsystems must not add new entries here. */

/* Generated source-level identities for repeated static references. */
/* Names intentionally preserve source VA until semantic names/types are proven. */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=3 u32=3 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=6 u8=6 */

/* data refs=3 u16=1 u32=2 */

/* data refs=7 u32=7 */

/* data refs=51 u32=51 */

/* data refs=7 addr=6 f32=7 */

/* data refs=7 addr=7 f32=7 */

/* data refs=7 addr=1 u32=6 */

/* data refs=4 u32=4 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 u32=3 */

/* data refs=3 u32=3 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=4 u32=4 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=8 u32=8 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=1 u8=1 */

/* data refs=2 u32=2 */

/* data refs=2 u8=2 */

/* data refs=12 u32=12 */

/* data refs=4 u32=4 */

/* data refs=7 u32=7 */

/* data refs=7 u32=7 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 u32=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=4 addr=1 u32=3 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=5 u32=9 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=3 addr=3 */

/* data refs=3 addr=1 u8=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=5 u8=5 */

/* data refs=2 u32=2 */

/* data refs=3 u16=3 */

/* data refs=4 u32=6 */

/* data refs=3 addr=2 u32=1 */

/* data refs=2 addr=2 */

/* data refs=3 addr=2 u32=1 */

/* data refs=2 addr=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=5 u32=5 */


/* data refs=147 u32=163 */


/* data refs=2 u32=2 */


/* data refs=6 addr=1 u32=3 u8=2 */

/* data refs=20 u32=19 */

/* data refs=8 addr=2 u8=6 */

/* data refs=2 u16=2 */

/* data refs=128 u32=162 */

/* data refs=9 addr=8 u8=1 */

/* data refs=26 u32=26 */

/* data refs=35 u32=35 */

/* data refs=9 u32=9 */

/* data refs=25 u32=25 */


/* data refs=12 u32=14 */

/* data refs=8 addr=2 u32=6 */

/* data refs=26 addr=26 */

/* data refs=3 addr=3 */

/* data refs=5 u32=5 */

/* data refs=2 u32=2 */

/* data refs=6 u32=6 */

/* data refs=26 u32=26 */

/* data refs=6 u32=6 */

/* data refs=4 u32=8 */

/* data refs=30 u32=30 */

/* data refs=2 u8=2 */

/* data refs=3 u32=3 */

/* data refs=2 u32=2 */

/* data refs=7 u16=7 */

/* data refs=2 addr=1 u32=1 */

/* data refs=5 addr=1 u32=4 */

/* data refs=4 u32=4 */

/* data refs=6 addr=3 u32=3 */


/* data refs=10 u32=12 */


/* data refs=6 u32=6 */

/* data refs=8 u32=8 */


/* data refs=2 u32=2 */

/* data refs=65 u32=71 */

/* data refs=8 u32=8 */

/* data refs=8 u32=8 */

/* data refs=27 u32=27 */


/* data refs=30 addr=25 u32=5 */

/* data refs=4 u32=4 */

/* data refs=3 u32=3 */

/* data refs=2 u32=2 */

/* data refs=14 addr=1 f32=1 u32=21 */

/* data refs=111 addr=34 u32=73 u8=4 */

/* data refs=56 u32=56 */

/* data refs=55 u32=55 */

/* data refs=55 u32=55 */

/* data refs=75 addr=6 f32=6 u32=65 u8=4 */

/* data refs=3 u32=3 */

/* data refs=3 u32=3 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=16 addr=11 u8=5 */

/* data refs=9 addr=3 u32=6 */

/* data refs=9 addr=3 u32=6 */


/* data refs=22 u32=23 */

/* data refs=254 u32=286 */


/* data refs=8 u32=8 */


/* data refs=6 u32=6 */


/* data refs=104 u32=104 */


/* data refs=455 addr=1 u32=454 */


/* data refs=12 u32=12 */

/* data refs=413 u32=413 */


/* data refs=3 u32=5 */

/* data refs=45 u32=45 */

/* data refs=6 u32=6 */

/* data refs=9 u32=9 */

/* data refs=9 u32=9 */

/* data refs=2 u32=2 */

/* data refs=16 u32=16 */


/* data refs=6 u32=6 */


/* data refs=2 u32=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=2 f32=1 */

/* data refs=7 addr=7 */

/* data refs=3 addr=2 f32=3 */

/* data refs=15 addr=15 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=11 u32=11 */

/* data refs=3 u32=5 */

/* data refs=5 u32=5 */

/* data refs=2 u32=2 */

/* data refs=4 u32=4 */

/* data refs=5 u8=5 */

/* data refs=3 u8=3 */

/* data refs=2 u32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=4 addr=1 u32=3 */

/* data refs=27 u32=41 */

/* data refs=2 addr=1 u32=1 */

/* data refs=8 u32=8 */

/* data refs=3 addr=2 u32=1 */

/* data refs=2 u32=2 */

/* data refs=9 u32=15 */

/* data refs=4 u32=4 */

/* data refs=2 addr=1 u32=1 */

/* data refs=15 u32=19 */

/* data refs=3 u32=3 */

/* data refs=7 u32=7 */

/* data refs=13 u32=19 */

/* data refs=4 addr=4 f32=4 */

/* data refs=6 addr=6 f32=6 */

/* data refs=9 addr=9 f32=9 */

/* data refs=4 u16=4 */

/* data refs=6 u32=6 */

/* data refs=4 u32=4 */

/* data refs=16 addr=11 f32=16 */

/* data refs=20 u32=28 */

/* data refs=2 u32=2 */

/* data refs=5 u32=5 */

/* data refs=5 u32=5 */

/* data refs=7 addr=7 f32=7 */

/* data refs=17 addr=17 f32=17 */

/* data refs=7 addr=1 u32=6 */

/* data refs=5 u32=5 */

/* data refs=7 u32=5 u8=2 */

/* data refs=2 u32=2 */

/* data refs=3 addr=3 f32=3 */

/* data refs=11 addr=2 f32=11 */

/* data refs=2 u32=2 */

/* data refs=19 u32=19 */

/* data refs=3 u32=3 */

/* data refs=5 u32=5 */

/* data refs=5 u32=5 */

/* data refs=5 u32=5 */

/* data refs=7 u32=7 */

/* data refs=2 u8=2 */

/* data refs=2 u8=2 */

/* data refs=30 u32=30 */

/* data refs=7 u32=7 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=3 u32=3 */

/* data refs=15 addr=15 f32=15 */

/* data refs=2 addr=2 f32=2 */

/* data refs=4 u32=8 */

/* data refs=5 u32=5 */

/* data refs=14 u32=14 */

/* data refs=7 addr=1 u32=6 */

/* data refs=15 addr=1 u32=14 */

/* data refs=3 u32=3 */

/* data refs=4 u32=4 */

/* data refs=2 addr=1 u8=1 */

/* data refs=6 u32=6 */

/* data refs=16 addr=16 f32=16 */

/* data refs=5 addr=3 u32=2 */






/* data refs=8 u32=8 */

/* data refs=2 u32=2 */

/* data refs=4 u32=4 */

/* data refs=2 u32=2 */

/* data refs=16 u32=20 */

/* data refs=5 u32=5 */

/* data refs=17 u32=19 */

/* data refs=2 addr=2 f32=2 */

/* data refs=3 addr=3 f32=3 */

/* data refs=2 addr=2 f32=2 */

/* data refs=3 addr=3 f32=3 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=10 u32=10 */

/* data refs=3 addr=3 f32=3 */

/* data refs=12 u32=22 */

/* data refs=3 u32=3 */

/* data refs=4 addr=4 f32=4 */

/* data refs=4 addr=4 f32=4 */

/* data refs=4 addr=3 f32=4 */

/* data refs=4 addr=4 f32=4 */

/* data refs=4 addr=4 f32=4 */

/* data refs=4 addr=3 f32=4 */

/* data refs=26 u32=26 */

/* data refs=4 u32=4 */

/* data refs=4 u32=4 */

/* data refs=4 addr=1 u32=5 */

/* data refs=4 addr=2 f32=4 */

/* data refs=9 u32=9 */

/* data refs=19 addr=19 f32=19 */

/* data refs=2 u32=2 */

/* data refs=2 addr=2 */

/* data refs=8 u32=8 */

/* data refs=13 u32=13 */

/* data refs=3 addr=1 u32=2 */

/* data refs=10 addr=9 u32=1 */

/* data refs=3 addr=1 u8=2 */


/* data refs=4 u32=4 */

/* data refs=3 u32=3 */

/* data refs=10 addr=7 u32=1 u8=2 */

/* data refs=15 u32=15 */

/* data refs=2 addr=2 */

/* data refs=2 addr=2 */

/* data refs=5 addr=3 u32=1 u8=1 */

/* data refs=37 u32=59 */

/* data refs=5 u32=5 */

/* data refs=3 addr=3 */

/* data refs=2 addr=2 */

/* data refs=9 u32=9 */

/* data refs=3 u32=3 */

/* data refs=13 u32=13 */

/* data refs=13 u32=13 */

/* data refs=2 addr=1 u8=1 */

/* data refs=7 addr=2 u32=5 */

/* data refs=6 addr=2 u32=4 */

/* data refs=10 u32=10 */

/* data refs=2 addr=2 */

/* data refs=19 addr=19 f32=19 */

/* data refs=10 u32=10 */

/* data refs=7 addr=7 f32=7 */

/* data refs=3 u32=5 */

/* data refs=2 u32=2 */

/* data refs=9 u32=9 */

/* data refs=6 u32=10 */

/* lifted into semantic runtime */

/* data refs=3 addr=1 u32=2 */

/* data refs=4 u32=8 */

/* data refs=7 addr=7 f32=7 */

/* data refs=4 u32=4 */

/* data refs=3 addr=2 u8=1 */

/* lifted into semantic runtime */

/* data refs=4 addr=4 f32=4 */

/* data refs=6 u32=6 */

/* data refs=8 u32=8 */

/* data refs=2 u32=4 */

/* data refs=12 u32=12 */

/* data refs=11 u32=11 */

/* data refs=19 addr=19 f32=19 */

/* data refs=11 u32=11 */

/* data refs=3 u32=3 */

/* data refs=7 u32=9 */

/* data refs=8 u32=8 */

/* data refs=23 u32=23 */

/* data refs=16 u32=16 */

/* data refs=4 addr=2 u8=2 */

/* data refs=3 u32=3 */

/* data refs=4 u32=4 */

/* data refs=6 u32=6 */

/* data refs=6 addr=6 f32=6 */

/* data refs=2 addr=2 f32=2 */

/* data refs=4 u32=4 */

/* data refs=7 u32=7 */

/* data refs=18 addr=18 f32=1 */

/* data refs=10 u32=10 */

/* data refs=5 u32=5 */

/* data refs=3 u32=3 */

/* data refs=21 addr=6 f32=6 u32=15 */

/* data refs=16 addr=10 f32=16 */

/* data refs=6 addr=6 f32=6 */

/* data refs=16 addr=10 f32=16 */

/* data refs=6 addr=6 f32=6 */

/* data refs=16 addr=10 f32=16 */

/* data refs=5 u32=5 */

/* data refs=6 addr=4 u16=2 */

/* data refs=2 u16=2 */

/* data refs=2 u16=2 */

/* data refs=2 u16=2 */

/* data refs=2 u16=2 */

/* data refs=2 u16=2 */

/* data refs=4 u32=4 */

/* data refs=4 addr=4 f32=4 */

/* data refs=19 u32=19 */

/* data refs=6 addr=3 u16=3 */

/* data refs=3 u16=3 */

/* data refs=3 u16=3 */

/* data refs=13 u32=13 */

/* data refs=18 addr=6 f32=6 u32=12 */

/* data refs=14 addr=8 f32=14 */

/* data refs=6 addr=6 f32=6 */

/* data refs=14 addr=8 f32=14 */

/* data refs=6 addr=6 f32=6 */

/* data refs=14 addr=8 f32=14 */

/* data refs=5 u32=5 */

/* data refs=3 u32=5 */

/* data refs=10 addr=10 */

/* data refs=9 addr=1 u8=8 */

/* data refs=8 u8=8 */

/* data refs=2 addr=1 u32=1 */

/* data refs=3 u32=3 */

/* data refs=11 u32=13 */

/* data refs=7 u32=7 */

/* data refs=2 u32=2 */

/* lifted into semantic runtime */

/* data refs=2 u32=2 */

/* data refs=20 addr=10 u32=1 u8=9 */

/* data refs=11 u32=11 */

/* data refs=31 addr=2 u32=29 */

/* data refs=4 u32=4 */

/* data refs=9 u32=9 */

/* data refs=18 u32=18 */

/* data refs=4 u32=4 */

/* data refs=3 u32=3 */

/* data refs=2 u32=2 */

/* data refs=21 u32=25 */

/* data refs=4 addr=2 u16=4 */

/* data refs=5 u32=5 */

/* data refs=2 u32=2 */

/* data refs=9 u32=9 */

/* data refs=9 u32=9 */

/* data refs=4 u32=4 */

/* data refs=4 u32=4 */

/* data refs=4 u32=4 */

/* data refs=4 u32=4 */

/* data refs=19 addr=19 f32=19 */

/* data refs=4 u32=4 */

/* data refs=4 u32=8 */

/* data refs=8 u32=7 u8=1 */

/* lifted into semantic runtime */


/* data refs=3 addr=1 u32=2 */

/* data refs=5 u32=5 */

/* data refs=2 u32=1 u8=1 */

/* data refs=2 addr=2 */

/* data refs=2 addr=1 f32=2 */

/* data refs=2 addr=1 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=3 addr=3 f32=3 */

/* data refs=3 addr=3 f32=3 */

/* data refs=5 addr=3 f32=5 */

/* data refs=3 u32=3 */

/* data refs=2 u32=2 */

/* data refs=5 u32=5 */

/* data refs=2 u16=1 u32=1 */

/* data refs=9 addr=8 f32=9 */

/* data refs=2 addr=2 f32=2 */

/* lifted into SferaInputDeviceRuntime */


/* data refs=3 u32=3 */

/* lifted into SferaWindowRuntime */


/* data refs=3 u32=3 */

/* data refs=3 addr=3 */

/* data refs=4 u8=4 */

/* data refs=5 u32=5 */

/* data refs=5 addr=5 f32=5 */

/* lifted into semantic runtime */

/* lifted into semantic runtime */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=5 u32=5 */

/* data refs=7 addr=7 f32=7 */

/* data refs=7 addr=7 f32=7 */

/* data refs=11 u32=11 */

/* data refs=4 u32=4 */

/* lifted into semantic runtime */

/* data refs=2 u32=2 */

/* lifted into semantic runtime */

/* data refs=6 u32=6 */

/* data refs=19 addr=19 f32=19 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=3 addr=1 u8=2 */

/* data refs=4 addr=4 f32=4 */

/* data refs=10 addr=2 u32=8 */

/* data refs=8 u32=8 */

/* data refs=2 u8=2 */

/* data refs=2 u8=2 */

/* data refs=3 u8=3 */

/* data refs=4 u32=4 */

/* data refs=14 u32=16 */

/* data refs=11 u32=11 */

/* data refs=23 u32=23 */

/* data refs=11 u32=13 */

/* data refs=29 u32=43 */

/* data refs=14 addr=1 u32=13 */

/* data refs=3 u32=3 */

/* data refs=4 addr=4 f32=4 */

/* data refs=3 u32=3 */

/* data refs=2 u32=2 */

/* data refs=8 u32=8 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=10 u32=10 */

/* data refs=12 u32=12 */

/* data refs=8 u32=8 */

/* data refs=8 u32=8 */

/* data refs=2 addr=1 u32=1 */

/* data refs=16 u8=16 */

/* data refs=3 u8=3 */

/* data refs=10 u32=10 */

/* data refs=9 addr=1 u32=8 */

/* data refs=8 addr=1 u32=7 */

/* data refs=6 u32=6 */

/* data refs=3 u32=3 */

/* data refs=10 u32=10 */

/* data refs=2 addr=2 */

/* data refs=2 u32=2 */

/* data refs=2 addr=2 f32=1 */

/* data refs=3 addr=3 f32=2 */

/* data refs=2 addr=2 f32=1 */

/* data refs=4 u32=4 */

/* data refs=4 u32=4 */

/* data refs=4 u32=4 */


/* data refs=2 u32=2 */

/* data refs=2 addr=1 u32=1 */




/* data refs=11 u32=11 */

/* data refs=11 u32=11 */


/* data refs=11 u32=11 */

/* data refs=2 u32=2 */



/* data refs=3 addr=3 */

/* data refs=2 addr=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=3 addr=3 */


/* data refs=2 u32=2 */


/* data refs=3 addr=1 f32=2 u32=1 */

/* data refs=3 addr=1 f32=2 u32=1 */

/* data refs=3 addr=1 f32=2 u32=1 */


/* data refs=2 addr=2 f32=1 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */


/* data refs=4 addr=4 f32=2 */

/* data refs=2 addr=1 f32=1 u32=1 */

/* data refs=4 addr=3 f32=3 u32=1 */

/* data refs=3 addr=3 f32=3 */

/* data refs=3 addr=3 f32=3 */

/* data refs=3 addr=3 f32=3 */

/* data refs=6 addr=3 f32=6 */

/* data refs=6 addr=3 f32=6 */

/* data refs=6 addr=3 f32=6 */

/* data refs=18 addr=5 f32=6 u32=12 */

/* data refs=18 addr=5 f32=6 u32=12 */

/* data refs=18 addr=4 f32=6 u32=12 */

/* data refs=12 u8=12 */

/* data refs=16 addr=12 f32=11 u32=3 */

/* data refs=20 addr=16 f32=17 u32=3 */

/* data refs=14 addr=9 f32=10 u32=3 */

/* data refs=6 addr=6 f32=6 */

/* data refs=7 addr=6 f32=6 u32=1 */

/* data refs=4 addr=4 f32=4 */

/* data refs=2 u32=2 */

/* data refs=14 addr=5 f32=6 u32=8 */

/* data refs=12 addr=3 f32=4 u32=8 */

/* data refs=14 addr=5 f32=6 u32=8 */

/* data refs=7 addr=2 f32=4 u32=3 */

/* data refs=13 addr=10 f32=10 u32=3 */

/* data refs=7 addr=4 f32=4 u32=3 */

/* data refs=2 addr=2 f32=1 */

/* data refs=2 u32=2 */


/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */



/* data refs=2 u32=2 */


/* data refs=2 u32=2 */


/* data refs=2 u32=2 */


/* data refs=2 addr=1 f32=1 u32=1 */

/* data refs=2 addr=1 f32=1 u32=1 */

/* data refs=2 addr=1 f32=1 u32=1 */

/* data refs=12 addr=11 u32=1 */

/* data refs=6 addr=6 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=3 addr=3 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 u32=2 */

/* data refs=4 addr=4 f32=4 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 u32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 u32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 u32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */


/* data refs=2 u32=2 */

/* data refs=18 addr=18 */


/* data refs=6 addr=6 */

/* data refs=16 u32=16 */







/* data refs=2 u32=2 */


/* data refs=6 addr=6 */

/* data refs=2 u32=2 */


/* data refs=2 addr=2 */

/* data refs=11 u32=11 */

/* data refs=5 u32=5 */

/* data refs=5 u32=5 */

/* data refs=5 u32=5 */

/* data refs=2 addr=2 f32=2 */

/* data refs=4 u32=6 */

/* data refs=2 u32=2 */

/* data refs=4 u32=6 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=4 u32=4 */

/* data refs=4 u32=4 */

/* data refs=2 addr=2 */

/* data refs=5 u32=6 u8=1 */

/* data refs=2 u32=2 */






/* data refs=3 addr=3 */

/* data refs=4 addr=2 f32=4 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=1 f32=2 */

/* data refs=2 addr=2 */

/* data refs=4 addr=2 f32=4 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */
















/* data refs=2 u32=2 */

/* data refs=4 addr=3 u8=1 */

/* data refs=8 addr=8 */

/* data refs=16 u32=16 */

/* data refs=2 u8=2 */

/* data refs=2 addr=2 */

/* data refs=2 addr=2 */


/* data refs=2 addr=1 u32=1 */










/* data refs=3 u32=3 */

/* data refs=3 u8=3 */

/* data refs=2 u8=2 */

/* data refs=2 addr=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=16 u32=16 */

/* data refs=2 addr=1 u32=1 */

/* data refs=6 u32=6 */

/* data refs=3 u8=3 */

/* data refs=2 addr=2 */

/* data refs=3 u32=3 */

/* data refs=3 u32=3 */

/* data refs=3 u32=3 */

/* data refs=5 u32=5 */

/* data refs=6 addr=6 */

/* data refs=3 addr=2 u32=1 */

/* data refs=3 u32=3 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=15 u32=15 */

/* data refs=12 u32=12 */

/* data refs=17 u32=17 */

/* data refs=2 u32=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=3 addr=2 u8=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=8 u32=8 */

/* data refs=2 addr=1 u32=1 */

/* data refs=12 u32=12 */

/* data refs=2 addr=1 u32=1 */

/* data refs=8 addr=4 u32=1 u8=3 */

/* data refs=6 u32=6 */

/* data refs=2 addr=1 u32=1 */

/* data refs=12 addr=4 u32=8 */

/* data refs=6 u32=6 */

/* data refs=2 addr=1 u32=1 */

/* data refs=18 u32=22 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=11 u32=11 */

/* data refs=2 u32=2 */

/* data refs=3 u32=3 */

/* data refs=5 u32=5 */

/* data refs=4 addr=1 u16=3 */

/* data refs=2 addr=2 */

/* data refs=2 u32=4 */

/* data refs=4 u32=4 */

/* data refs=4 u16=4 */

/* data refs=12 u32=12 */

/* data refs=4 u32=4 */

/* data refs=11 u32=11 */

/* data refs=2 u32=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=7 addr=1 u32=5 u64=1 */

/* data refs=5 u32=5 */

/* data refs=3 u32=3 */

/* data refs=3 u32=3 */

/* data refs=3 u32=5 */

/* data refs=3 u32=3 */

/* data refs=4 u32=4 */

/* data refs=4 u32=4 */

/* data refs=4 u32=4 */

/* data refs=2 u32=2 */

/* data refs=3 u32=3 */

/* data refs=3 u32=3 */

/* data refs=4 u8=4 */

/* data refs=3 u32=3 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=5 u32=5 */

/* data refs=3 u32=3 */

/* data refs=3 u32=3 */

/* data refs=2 u32=2 */

/* data refs=2 u32=2 */

/* data refs=4 u32=4 */

/* data refs=2 addr=1 u32=1 */

/* data refs=3 addr=2 u32=1 */


/* data refs=5 addr=5 */

/* data refs=3 addr=3 f32=3 */

/* data refs=3 addr=3 f32=3 */

/* data refs=2 u8=2 */

/* data refs=9 u32=9 */

/* data refs=2 addr=1 u32=1 */

/* data refs=20 addr=20 */

/* data refs=2 addr=1 u32=1 */

/* data refs=14 addr=14 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */


/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=3 addr=2 u16=1 */

/* data refs=6 u32=6 */

/* data refs=9 u32=9 */

/* data refs=2 addr=1 u32=1 */

/* data refs=10 addr=1 u32=9 */

/* data refs=8 u32=8 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=2 */

/* data refs=12 addr=9 u8=3 */

/* data refs=5 addr=2 u8=3 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=4 addr=4 */

/* data refs=2 addr=1 u32=1 */

/* data refs=8 u32=8 */

/* data refs=2 u32=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=6 addr=6 */

/* data refs=2 addr=1 u32=1 */

/* data refs=3 addr=1 u8=2 */

/* data refs=11 u32=17 */

/* data refs=18 u32=18 */

/* data refs=5 u8=5 */

/* data refs=5 u32=5 */

/* data refs=7 u32=7 */

/* data refs=15 u32=15 */

/* data refs=2 u32=2 */

/* data refs=14 u32=14 */

/* data refs=7 u32=7 */

/* data refs=15 addr=5 u32=10 */

/* data refs=7 u32=11 */

/* data refs=2 addr=1 u32=1 */

/* data refs=50 addr=5 u32=45 */

/* data refs=28 u32=48 */

/* data refs=10 addr=5 u32=5 */

/* data refs=4 u32=4 */

/* data refs=5 u32=5 */

/* data refs=12 u32=12 */

/* data refs=12 u32=14 */

/* data refs=17 addr=2 u32=15 */

/* data refs=9 u32=13 */

/* data refs=15 addr=1 u32=14 */

/* data refs=5 u32=7 */

/* data refs=10 addr=3 u32=7 */

/* data refs=7 u32=7 */

/* data refs=2 addr=2 */

/* data refs=7 addr=7 */

/* data refs=3 u8=3 */

/* data refs=7 addr=6 u8=1 */


/* data refs=3 addr=3 */

/* data refs=3 addr=3 */

/* data refs=3 addr=3 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=18 addr=8 u8=10 */

/* data refs=3 addr=2 u8=1 */

/* data refs=8 addr=6 u8=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=6 u32=6 */

/* data refs=2 addr=1 u32=1 */

/* data refs=8 addr=8 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=10 addr=10 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=14 addr=14 */

/* data refs=2 addr=1 u32=1 */

/* lifted into SferaControlOptionsRuntime */

/* lifted into SferaControlOptionsRuntime */

/* data refs=2 u32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=2 addr=2 f32=2 */

/* data refs=9 addr=1 u32=8 */

/* lifted into SferaControlOptionsRuntime */


/* data refs=3 addr=3 */

/* data refs=3 addr=3 */

/* data refs=7 addr=7 */

/* data refs=3 addr=3 */

/* lifted into SferaOptionsDialogRuntime */

/* data refs=5 addr=5 */

/* data refs=3 addr=3 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */


/* data refs=2 addr=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=14 addr=2 u32=12 */

/* data refs=4 u32=6 */

/* data refs=5 addr=5 */

/* data refs=12 u32=12 */

/* data refs=2 u32=2 */

/* data refs=10 u32=12 u8=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=7 addr=7 */

/* data refs=8 u32=10 */

/* data refs=8 addr=8 */

/* data refs=2 u32=2 */

/* data refs=5 u32=5 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=5 addr=5 */

/* data refs=10 u32=12 u8=2 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=1 u32=1 */

/* data refs=4 addr=1 u32=3 */

/* data refs=2 addr=1 u32=1 */


/* data refs=5 u32=5 */

/* data refs=2 addr=1 u32=1 */

/* data refs=2 addr=2 */

/* data refs=2 addr=2 */

/* data refs=3 u32=3 */

/* data refs=3 u32=3 */

/* data refs=3 u32=3 */

/* data refs=2 addr=1 u32=1 */

/* data refs=9 addr=9 */

/* data refs=19 addr=8 u32=11 */

/* data refs=10 addr=2 u32=16 */

/* data refs=10 addr=2 u32=16 */

/* data refs=5 u8=5 */

/* data refs=12 u8=12 */

/* data refs=9 u32=17 */

/* data refs=4 u32=6 */

/* data refs=12 addr=12 */

/* data refs=15 addr=15 */

/* data refs=5 u8=5 */

/* data refs=4 u32=6 */

/* data refs=6 u32=6 */

/* data refs=2 u32=2 */

/* data refs=3 addr=3 */

/* data refs=6 addr=6 */

/* data refs=12 u8=12 */

/* data refs=6 u32=6 */

/* data refs=3 u16=3 */

/* data refs=10 u8=10 */

/* data refs=2 u32=2 */

/* lifted: BaseVect range diagnostics scratch buffer */

/* data refs=21 addr=21 */

/* data refs=10 u8=10 */

/* data refs=12 u8=12 */

/* data refs=3 u32=3 */

/* data refs=2 u32=2 */

/* data refs=4 u32=4 */

/* data refs=3 u32=3 */

/* data refs=4 u32=4 */

/* data refs=5 u32=5 */

/* data refs=2 u32=2 */

/* data refs=3 addr=1 u32=2 */

/* data refs=3 u32=3 */

/* data refs=4 u32=4 */

/* Semantically known IAT slots referenced by lifted code. */


/* ===== Resolved static control-flow tables ===== */
/* Compiler jump tables and sparse selector lookup blocks were folded into direct C control flow. */

#ifdef __cplusplus
#include <array>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <string_view>
/* ===== Native runtime identity ===== */
namespace lifted {
inline constexpr std::uint8_t kRead = 1u;
inline constexpr std::uint8_t kWrite = 2u;
inline constexpr std::uint8_t kExecute = 4u;
inline constexpr std::uint32_t kSourceImageBase = 0x00400000u;
inline constexpr std::uint32_t kEntryRva = 0x000EF142u;
inline constexpr std::uint32_t kImageSize = 0x04C62000u;
inline constexpr std::uint32_t kStackReserve = 0x00100000u;
inline constexpr std::uint16_t kMachine = 0x014Cu;
inline constexpr std::size_t kExpectedImportCount = 409u;
inline constexpr std::string_view kClientExecutableName = "sphereclient_patched.exe";
enum class ImportBehavior : std::uint8_t { generic, float_return, raise_exception, module_handle_a, module_handle_w, module_filename_a, module_filename_w, ci_atan2, ci_pow, ci_acos, ci_asin, ci_atan, ci_cos, ci_exp, ci_sin, ci_sqrt, ci_tan, process_module_argument0 };
} // namespace lifted

#endif /* __cplusplus */
