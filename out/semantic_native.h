#pragma once

/*
 * semantic_native.h
 *
 * Semantic storage surface for the lifted client.
 *
 * Current state:
 *   - source .rdata has no materialized backing store; strings and scalar constants live at their consumers.
 *   - client vtables are semantic class tokens: virtual slot reads resolve directly to the lifted override callback.
 *   - MSVC C++ EH frame metadata and __CxxFrameHandler3 entrypoints are eliminated; lifted throw paths terminate semantically.
 *   - .data keeps a compatibility view only for state whose source address is still observable; compiler-only TypeDescriptor objects are removed after initialization.
 *
 * Lifted function shards remain separate only to keep MSVC compile times sane.
 */

#include "lifted_abi.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>

static inline uint32_t sfera_f32_bits(float value) { uint32_t bits; memcpy(&bits, &value, sizeof(bits)); return bits; }

#if defined(__cplusplus)
#define SFERA_STATIC_ASSERT(condition, message) static_assert(condition, message)
#else
#define SFERA_STATIC_ASSERT(condition, message) _Static_assert(condition, message)
#endif

/* ===== Native static storage and address translation ===== */
/* Source .rdata addresses survive only as semantic class/vptr tokens.
 * .data still has a canonical compatibility view while its remaining address-sensitive state is lifted by consumer.
 */

#ifdef __cplusplus
extern "C" {
#endif

/* Named native import symbols. These are resolved once at startup and are not an emulated IAT. */

extern const SferaMsvcVbtable2 g_sfera_vbtable_basic_ofstream;
extern const SferaMsvcVbtable2 g_sfera_vbtable_basic_ifstream;
extern const SferaMsvcVbtable2 g_sfera_vbtable_basic_ostringstream;
extern uint32_t g_sfera_native_vtable_basic_filebuf[15];
extern uint32_t g_sfera_native_vtable_basic_ofstream[1];
extern uint32_t g_sfera_native_vtable_basic_ifstream[1];
extern uint32_t g_sfera_native_vtable_basic_stringbuf[15];
extern uint32_t g_sfera_native_vtable_basic_ostringstream[1];
extern const SferaGuid32 g_sfera_guid_direct_input_key;
extern const SferaGuid32 g_sfera_guid_direct_input_x_axis;
extern const SferaGuid32 g_sfera_guid_direct_input_y_axis;
extern const SferaGuid32 g_sfera_guid_direct_input_z_axis;
int sfera_bind_native_std_stream_vtables(void);
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
extern uint8_t* g_sfera_data_compat_base;
extern uint32_t g_sfera_security_cookie;
extern uint32_t g_sfera_security_cookie_complement;
extern uint32_t g_sfera_log_first_write;
#define SFERA_DATA_PAGE_SHIFT UINT32_C(16)
#define SFERA_DATA_PAGE_SIZE UINT32_C(0x00010000)
#define SFERA_DATA_PAGE_COUNT UINT32_C(0x000004A8)
extern uint8_t* g_sfera_data_semantic_page_alias[SFERA_DATA_PAGE_COUNT];

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
#define SFERA_DATA_SOURCE_BEGIN UINT32_C(0x00520000)
#define SFERA_DATA_SOURCE_SIZE UINT32_C(0x04A70790)
#define SFERA_DATA_STORAGE_SIZE UINT32_C(0x04A80000)
#define SFERA_DATA_SEMANTIC_VA(source_va) ((uint32_t)(uintptr_t)(g_sfera_data_semantic_page_alias[(((uint32_t)(source_va) - SFERA_DATA_SOURCE_BEGIN) >> SFERA_DATA_PAGE_SHIFT)] + (((uint32_t)(source_va) - SFERA_DATA_SOURCE_BEGIN) & (SFERA_DATA_PAGE_SIZE - 1u))))
#define SFERA_DATA_CANONICAL_ADDR(source_va) ((uint32_t)(uintptr_t)(g_sfera_data_compat_base + ((uint32_t)(source_va) - SFERA_DATA_SOURCE_BEGIN)))




/* ===== Resolved semantic native state ===== */
/* Resolved state lives in native C storage. Source virtual addresses remain only for regions
 * whose semantics have not yet been lifted. */

typedef struct SferaItemArray { uint32_t block_vector_begin; uint32_t block_vector_end; uint32_t block_vector_capacity_end; uint32_t reserved; uint32_t free_items; uint32_t free_count; uint32_t growth_count; } SferaItemArray;
typedef struct SferaServerWall { uint32_t wall_data; uint32_t reserved_04; uint32_t wall_count; uint32_t generated_data; uint32_t generated_points; uint32_t segment_count; uint32_t effect_handle; } SferaServerWall;
typedef struct SferaDirectPlayCaps32 { uint32_t words[12]; } SferaDirectPlayCaps32;
typedef struct SferaNetworkMessageSlot { uint8_t bytes[0x1A8]; } SferaNetworkMessageSlot;
typedef struct SferaNetworkRuntime { uint32_t initialization_result; uint32_t server_port; uint32_t local_port_candidate; uint32_t connection_slot; uint32_t pending_slot; uint32_t active_slot; uint32_t shutdown_state; uint8_t timeout_marker_pending; uint8_t net_log_has_error; uint8_t network_error_active; uint8_t initialized; uint32_t bytes_sent_delta; uint32_t bytes_retried_delta; uint32_t bytes_received_delta; uint32_t error_budget; SferaDirectPlayCaps32 directplay_caps; uint32_t message_call_scratch; SferaNetworkMessageSlot message_slots[3048]; } SferaNetworkRuntime;
typedef struct SferaNetworkConnectionCheckerRuntime { uint32_t instance; } SferaNetworkConnectionCheckerRuntime;
typedef struct SferaGraphicsRuntime { float fog_distance; float saved_fog_distance; uint32_t lods_enabled; uint32_t hardware_cursor_enabled; float environment_factor; uint8_t render_mode_enabled; uint32_t base_microtexture_id; float view_parameter; float view_scale; uint32_t post_effects_enabled; uint32_t rebuild_percent; uint32_t runtime_counter; uint32_t texture_runtime_id; float base_render_factor; uint32_t display_width; uint32_t display_height; uint32_t d3d9_device; } SferaGraphicsRuntime;
typedef struct SferaBoundCheckArray { uint32_t data; uint32_t capacity; char debug_file[32]; uint32_t debug_line; } SferaBoundCheckArray;
SFERA_STATIC_ASSERT(sizeof(SferaBoundCheckArray) == 0x2Cu, "SferaBoundCheckArray ABI size");
SFERA_STATIC_ASSERT(offsetof(SferaBoundCheckArray, debug_file) == 0x08u, "SferaBoundCheckArray debug file offset");
SFERA_STATIC_ASSERT(offsetof(SferaBoundCheckArray, debug_line) == 0x28u, "SferaBoundCheckArray debug line offset");
typedef struct SferaWorldObjectRuntime { uint32_t max_occupied_object_handle; uint32_t controlled_object_handle; uint32_t contour_mode; SferaBoundCheckArray object_handles; SferaBoundCheckArray extended_object_handles; uint32_t extended_object_count; } SferaWorldObjectRuntime;
typedef struct SferaGrassRuntime { SferaBoundCheckArray instance_offsets; SferaBoundCheckArray model_handles; SferaBoundCheckArray instance_indices; SferaBoundCheckArray type_records; } SferaGrassRuntime;
typedef struct SferaLightRuntime { SferaBoundCheckArray cell_light_ids; SferaBoundCheckArray cell_records; SferaBoundCheckArray cell_indices; SferaBoundCheckArray handles; SferaBoundCheckArray visible_handles; SferaBoundCheckArray active_handles; } SferaLightRuntime;
typedef struct SferaAutoBoundsArray { uint32_t data; uint32_t capacity; uint32_t maximum; uint32_t growth; uint32_t element_size; char debug_file[32]; uint32_t debug_line; } SferaAutoBoundsArray;
SFERA_STATIC_ASSERT(sizeof(SferaAutoBoundsArray) == 0x38u, "SferaAutoBoundsArray ABI size");
SFERA_STATIC_ASSERT(offsetof(SferaAutoBoundsArray, debug_file) == 0x14u, "SferaAutoBoundsArray debug file offset");
SFERA_STATIC_ASSERT(offsetof(SferaAutoBoundsArray, debug_line) == 0x34u, "SferaAutoBoundsArray debug line offset");
typedef struct SferaLandscapeRuntime { SferaBoundCheckArray file_records; SferaBoundCheckArray microtexture_handles; } SferaLandscapeRuntime;
typedef struct SferaCollisionRuntime { SferaBoundCheckArray candidate_handles; SferaBoundCheckArray near_result_handles; SferaAutoBoundsArray contact_objects; } SferaCollisionRuntime;
typedef struct SferaSceneArrayRuntime { SferaBoundCheckArray cloud_records; SferaBoundCheckArray surface_index_map; SferaBoundCheckArray scene_records; SferaBoundCheckArray render_pass_slots; SferaBoundCheckArray surface_handles; SferaBoundCheckArray clip_vectors; SferaBoundCheckArray surface_records; SferaBoundCheckArray scene_points; SferaBoundCheckArray object_positions; SferaBoundCheckArray model_matrices; SferaBoundCheckArray world_cell_records; SferaBoundCheckArray render_work_records; SferaBoundCheckArray reflection_targets; SferaBoundCheckArray object_sort_keys; SferaBoundCheckArray render_ranges; SferaBoundCheckArray object_draw_indices; SferaBoundCheckArray object_visibility_indices; SferaBoundCheckArray clip_points; SferaBoundCheckArray character_matrices; SferaBoundCheckArray object_sort_indices; SferaBoundCheckArray clip_indices; } SferaSceneArrayRuntime;
typedef struct SferaWeatherRuntime { SferaBoundCheckArray sky_texture_handles; } SferaWeatherRuntime;
typedef struct SferaModelRuntime { uint32_t repository; } SferaModelRuntime;
typedef struct SferaWarningLogRuntime { uint8_t object[0x5320]; } SferaWarningLogRuntime;
SFERA_STATIC_ASSERT(sizeof(SferaWarningLogRuntime) == 0x5320u, "warning log runtime ABI size");
typedef struct SferaControlOptionsRuntime { uint32_t active_slot; } SferaControlOptionsRuntime;
typedef struct SferaSpriteRuntime { uint32_t render_mode; } SferaSpriteRuntime;
typedef struct SferaCrashRuntime { uint8_t report_pending; } SferaCrashRuntime;
typedef struct SferaContoursRuntime { uint32_t round_robin_counter; } SferaContoursRuntime;
typedef struct SferaDynGreenRuntime { uint32_t previous_timestamp_low; uint32_t previous_timestamp_high; } SferaDynGreenRuntime;
typedef struct SferaExecutionMonitorRuntime { uint32_t thread_handle; uint8_t reserved_04[8]; uint16_t stop_requested; char log_path[0x36]; uint8_t critical_section[24]; uint32_t current_value_a; uint32_t current_value_b; } SferaExecutionMonitorRuntime;
typedef struct SferaErrorLogRuntime { uint8_t object[0x18]; uint8_t index_table[0x80]; } SferaErrorLogRuntime;
typedef struct SferaPacketCodecRuntime { uint8_t substitution[256]; uint32_t initialized; uint16_t checksum[256]; } SferaPacketCodecRuntime;
typedef struct SferaOleHostAbi { uint32_t storage_vtable[18]; uint32_t storage_object_vtable; uint32_t inplace_frame_vtable[15]; uint32_t client_site_vtable[9]; uint32_t inplace_site_vtable[15]; uint32_t doc_host_ui_handler_vtable[18]; } SferaOleHostAbi;
typedef struct SferaInterfaceRuntime { uint32_t cursor_kind; uint8_t primary_gate; uint8_t secondary_gate; uint32_t cross_enabled; uint32_t sounds_enabled; uint32_t description_auto_popup; uint32_t invite_messages; SferaBoundCheckArray windows; SferaBoundCheckArray window_handle_table; } SferaInterfaceRuntime;
typedef struct SferaStdAllocator { uint32_t vptr; } SferaStdAllocator;
typedef struct SferaMemoryRuntime { uint32_t allocation_source_file; uint32_t allocation_source_line; uint32_t critical_error_callback; uint32_t tracker_primary; uint32_t tracker_auxiliary; uint32_t tracker_floor; uint32_t tracker_ceiling; } SferaMemoryRuntime;
typedef struct SferaRenderBufferCapacities { uint32_t vertex32; uint32_t vertex28; uint32_t index_primary; uint32_t index_secondary; } SferaRenderBufferCapacities;
typedef struct SferaFileRuntime { uint32_t crash_report_instance; uint32_t callback_enabled; uint32_t search_path_count; uint32_t open_file_count; uint32_t callback; SferaAutoBoundsArray search_paths; SferaAutoBoundsArray open_files; } SferaFileRuntime;
typedef struct SferaVec3F { float x; float y; float z; } SferaVec3F;
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
SFERA_STATIC_ASSERT(sizeof(SferaGraphicsOptionsRuntime) == 0x84u, "graphics options lifted block size");
typedef struct SferaIntBounds3 { uint32_t min_x; uint32_t max_x; uint32_t min_y; uint32_t max_y; uint32_t min_z; uint32_t max_z; } SferaIntBounds3;
SFERA_STATIC_ASSERT(sizeof(SferaIntBounds3) == 0x18u, "integer bounds raw-dword ABI size");
typedef struct SferaViewGeometryRuntime { SferaVec3F reference_points[5]; SferaIntBounds3 projected_bounds; SferaIntBounds3 clipping_bounds; } SferaViewGeometryRuntime;

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
extern SferaNetworkConnectionCheckerRuntime g_sfera_network_connection_checker;
extern SferaGraphicsRuntime g_sfera_graphics_runtime;
extern SferaSceneRenderRuntime g_sfera_scene_render_runtime;
extern SferaScreenVertex g_sfera_sky_screen_vertices[SFERA_SKY_SCREEN_VERTEX_COUNT];
extern SferaScreenVertex g_sfera_landscape_screen_vertices[SFERA_LANDSCAPE_SCREEN_VERTEX_COUNT];
extern SferaBoundCheckArray g_sfera_character_index_map;
extern SferaBoundCheckArray g_sfera_mesh_partition_indices;
extern SferaGraphicsOptionsRuntime g_sfera_graphics_options_runtime;
extern SferaViewGeometryRuntime g_sfera_view_geometry_runtime;
extern SferaWorldObjectRuntime g_sfera_world_objects;
extern SferaGrassRuntime g_sfera_grass_runtime;
extern SferaLightRuntime g_sfera_light_runtime;
extern SferaLandscapeRuntime g_sfera_landscape_runtime;
extern SferaCollisionRuntime g_sfera_collision_runtime;
extern SferaSceneArrayRuntime g_sfera_scene_array_runtime;
extern SferaWeatherRuntime g_sfera_weather_runtime;
extern SferaModelRuntime g_sfera_model_runtime;
extern SferaWarningLogRuntime g_sfera_warning_log_runtime;
extern SferaControlOptionsRuntime g_sfera_control_options;
extern SferaSpriteRuntime g_sfera_sprite_runtime;
extern SferaCrashRuntime g_sfera_crash_runtime;
extern SferaContoursRuntime g_sfera_contours_runtime;
extern SferaDynGreenRuntime g_sfera_dyn_green_runtime;
extern SferaExecutionMonitorRuntime g_sfera_execution_monitor_runtime;
extern SferaErrorLogRuntime g_sfera_error_log_runtime;
extern SferaPacketCodecRuntime g_sfera_packet_codec_runtime;
extern SferaOleHostAbi g_sfera_ole_host_abi;
extern uint32_t g_sfera_graphics_display_depth_bits;
extern SferaInterfaceRuntime g_sfera_interface_runtime;
extern SferaStdAllocator g_sfera_std_allocator;
extern SferaMemoryRuntime g_sfera_memory_runtime;
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

SFERA_STATIC_INLINE uint32_t sfera_data_deref_address(uint32_t address) { uint32_t begin; uint32_t offset; uint8_t* alias; if (!g_sfera_data_compat_base) { return address; } begin = (uint32_t)(uintptr_t)g_sfera_data_compat_base; offset = address - begin; if (offset >= SFERA_DATA_SOURCE_SIZE) { return address; } alias = g_sfera_data_semantic_page_alias[offset >> SFERA_DATA_PAGE_SHIFT]; return alias ? (uint32_t)(uintptr_t)(alias + (offset & (SFERA_DATA_PAGE_SIZE - 1u))) : address; }
SFERA_STATIC_INLINE uint32_t sfera_data_deref_range(uint32_t address, uint32_t size) { uint32_t first; uint32_t last; if (size == 0u || address > UINT32_MAX - (size - 1u)) { return address; } first = sfera_data_deref_address(address); if (first == address) { return address; } last = sfera_data_deref_address(address + size - 1u); return last != address + size - 1u && last - first == size - 1u ? first : address; }

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
SFERA_STATIC_INLINE uint32_t sfera_data_semantic_address(uint32_t source_va) { uint32_t offset; uint8_t* alias; if (source_va < SFERA_DATA_SOURCE_BEGIN) { return 0u; } offset = source_va - SFERA_DATA_SOURCE_BEGIN; if (offset >= SFERA_DATA_SOURCE_SIZE) { return 0u; } alias = g_sfera_data_semantic_page_alias[offset >> SFERA_DATA_PAGE_SHIFT]; return alias ? (uint32_t)(uintptr_t)(alias + (offset & (SFERA_DATA_PAGE_SIZE - 1u))) : 0u; }
SFERA_STATIC_INLINE uint32_t sfera_calendar_days_in_month(uint32_t month) { if (month < 1u || month > 12u) { return 0u; } return 30u + ((month + (month > 7u ? 1u : 0u)) & 1u) - (month == 2u ? 2u : 0u); }
SFERA_STATIC_INLINE uint32_t sfera_calendar_days_before_month(uint32_t month) { uint32_t days = 0u; uint32_t current; if (month < 1u || month > 13u) { return 0u; } for (current = 1u; current < month; ++current) { days += sfera_calendar_days_in_month(current); } return days; }
SFERA_STATIC_INLINE uint32_t sfera_data_source_rva(uint32_t address) { uint32_t begin; uint32_t offset; uint32_t page; if (g_sfera_data_compat_base) { begin = (uint32_t)(uintptr_t)g_sfera_data_compat_base; offset = address - begin; if (offset < SFERA_DATA_SOURCE_SIZE) { return UINT32_C(0x00120000) + offset; } } for (page = 0u; page < SFERA_DATA_PAGE_COUNT; ++page) { uint8_t* alias = g_sfera_data_semantic_page_alias[page]; if (!alias) { continue; } begin = (uint32_t)(uintptr_t)alias; offset = address - begin; if (offset < SFERA_DATA_PAGE_SIZE) { return UINT32_C(0x00120000) + page * SFERA_DATA_PAGE_SIZE + offset; } } return UINT32_MAX; }

#undef SFERA_STATIC_INLINE

/* ===== Semantic virtual dispatch ===== */
/* Source vptr values are class-identity tokens. There is no materialized .rdata backing. */
#ifdef __cplusplus
extern "C" {
#endif
void sfera_initialize_data_storage(uint8_t* storage);
uint32_t sfera_cursor_texture_name(uint32_t slot);
int sfera_vtable_try_load32(uint32_t source_slot_va, uint32_t* value);
int sfera_vtable_token_address(uint32_t address);
#ifdef __cplusplus
}
#endif
#define SFERA_VPTR_TOKEN_BASE UINT32_C(0xF1000000)
#define SFERA_VPTR_TOKEN(class_id) (SFERA_VPTR_TOKEN_BASE + ((uint32_t)(class_id) << 6u))
#define SFERA_VPTR_BLOODEFFLISTENER SFERA_VPTR_TOKEN(0u) /* .?AVBloodEffListener@@, 3 virtual slot(s) */
#define SFERA_VPTR_IEFFECTMANAGER SFERA_VPTR_TOKEN(1u) /* .?AVIEffectManager@@, 12 virtual slot(s) */
#define SFERA_VPTR_CSCRIPTEDEFFECT SFERA_VPTR_TOKEN(2u) /* .?AVCScriptedEffect@@, 12 virtual slot(s) */
#define SFERA_VPTR_CSPIRALEFFECT SFERA_VPTR_TOKEN(3u) /* .?AVCSpiralEffect@@, 12 virtual slot(s) */
#define SFERA_VPTR_CMOLEFFECT SFERA_VPTR_TOKEN(4u) /* .?AVCMolEffect@@, 12 virtual slot(s) */
#define SFERA_VPTR_CBLADEEFFECT SFERA_VPTR_TOKEN(5u) /* .?AVCBladeEffect@@, 12 virtual slot(s) */
#define SFERA_VPTR_CGAZERLAKEEFFECT SFERA_VPTR_TOKEN(6u) /* .?AVCGazerLakeEffect@@, 12 virtual slot(s) */
#define SFERA_VPTR_CRAINEFFECT SFERA_VPTR_TOKEN(7u) /* .?AVCRainEffect@@, 12 virtual slot(s) */
#define SFERA_VPTR_IOUTPUTDEVICE SFERA_VPTR_TOKEN(8u) /* .?AVIOutputDevice@@, 1 virtual slot(s) */
#define SFERA_VPTR_COUTPUTLOGDEVICE SFERA_VPTR_TOKEN(9u) /* .?AVCOutputLogDevice@@, 1 virtual slot(s) */
#define SFERA_VPTR_CSPHEREERROR SFERA_VPTR_TOKEN(10u) /* .?AVCSphereError@@, 1 virtual slot(s) */
#define SFERA_VPTR_GRASSMAPMNGR SFERA_VPTR_TOKEN(11u) /* .?AVGrassMapMngr@@, 1 virtual slot(s) */
#define SFERA_VPTR_HYPERTEXTELEMENT_WORDWRAP SFERA_VPTR_TOKEN(12u) /* .?AUHyperTextElement_WordWrap@@, 1 virtual slot(s) */
#define SFERA_VPTR_HYPERTEXTELEMENT SFERA_VPTR_TOKEN(13u) /* .?AUHyperTextElement@@, 1 virtual slot(s) */
#define SFERA_VPTR_HYPERTEXTELEMENTWITHPARAMETERS SFERA_VPTR_TOKEN(14u) /* .?AUHyperTextElementWithParameters@@, 1 virtual slot(s) */
#define SFERA_VPTR_HYPERTEXTELEMENT_PLAINTEXT SFERA_VPTR_TOKEN(15u) /* .?AUHyperTextElement_PlainText@@, 1 virtual slot(s) */
#define SFERA_VPTR_HYPERTEXTELEMENT_LINK SFERA_VPTR_TOKEN(16u) /* .?AUHyperTextElement_Link@@, 1 virtual slot(s) */
#define SFERA_VPTR_CITEM SFERA_VPTR_TOKEN(17u) /* .?AVCItem@@, 2 virtual slot(s) */
#define SFERA_VPTR_CCOMMONITEM SFERA_VPTR_TOKEN(18u) /* .?AVCCommonItem@@, 2 virtual slot(s) */
#define SFERA_VPTR_CITEMLIST_COMMONITEM SFERA_VPTR_TOKEN(19u) /* .?AV?$CItemList@VCCommonItem@@@@, 2 virtual slot(s) */
#define SFERA_VPTR_CBASEMANAGER_CITEMLIST_COMMONITEM SFERA_VPTR_TOKEN(20u) /* .?AV?$CBaseManager@V?$CItemList@VCCommonItem@@@@VCCommonItem@@@@, 5 virtual slot(s) */
#define SFERA_VPTR_CLIGHTEFFECT SFERA_VPTR_TOKEN(21u) /* .?AVCLightEffect@@, 12 virtual slot(s) */
#define SFERA_VPTR_NATURERAINLISTENER SFERA_VPTR_TOKEN(22u) /* .?AVNatureRainListener@@, 3 virtual slot(s) */
#define SFERA_VPTR_LIGHTINGLISTENER SFERA_VPTR_TOKEN(23u) /* .?AVLightingListener@@, 3 virtual slot(s) */
#define SFERA_VPTR_CSOUNDFX SFERA_VPTR_TOKEN(24u) /* .?AVCSoundFX@@, 3 virtual slot(s) */
#define SFERA_VPTR_BUTTONCTRL_SPHEREUI SFERA_VPTR_TOKEN(25u) /* .?AVButtonCtrl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_CHECKBOX_SPHEREUI SFERA_VPTR_TOKEN(26u) /* .?AVCheckBox@SphereUI@@, 13 virtual slot(s) */
#define SFERA_VPTR_CDESCRIPTIONWINDOW_SPHEREUI SFERA_VPTR_TOKEN(27u) /* .?AVCDescriptionWindow@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_EDITCTRL_SPHEREUI SFERA_VPTR_TOKEN(28u) /* .?AVEditCtrl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_FILTERLISTCTRL_SPHEREUI SFERA_VPTR_TOKEN(29u) /* .?AVFilterListCtrl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_FONTPICKER_SPHEREUI SFERA_VPTR_TOKEN(30u) /* .?AVFontPicker@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_HYPERTEXTCHATLISTCONTROL_SPHEREUI SFERA_VPTR_TOKEN(31u) /* .?AVHyperTextChatListControl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_HYPERTEXTCTRL_SPHEREUI SFERA_VPTR_TOKEN(32u) /* .?AVHyperTextCtrl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_STD_BASIC_FILEBUF ((uint32_t)(uintptr_t)&g_sfera_native_vtable_basic_filebuf[0]) /* native MSVCP ABI bridge; 15 virtual slot(s) */
#define SFERA_VPTR_STD_BASIC_OFSTREAM ((uint32_t)(uintptr_t)&g_sfera_native_vtable_basic_ofstream[0]) /* native MSVCP ABI bridge; 1 virtual slot */
#define SFERA_VPTR_STD_BASIC_IFSTREAM ((uint32_t)(uintptr_t)&g_sfera_native_vtable_basic_ifstream[0]) /* native MSVCP ABI bridge; 1 virtual slot */
#define SFERA_VPTR_HYPERTEXTEDITCONTROL_SPHEREUI SFERA_VPTR_TOKEN(36u) /* .?AVHyperTextEditControl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_IMAGECTRL_SPHEREUI SFERA_VPTR_TOKEN(37u) /* .?AVImageCtrl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_STD_BASIC_STRINGBUF ((uint32_t)(uintptr_t)&g_sfera_native_vtable_basic_stringbuf[0]) /* native MSVCP ABI bridge; 15 virtual slot(s) */
#define SFERA_VPTR_STD_BASIC_OSTRINGSTREAM ((uint32_t)(uintptr_t)&g_sfera_native_vtable_basic_ostringstream[0]) /* native MSVCP ABI bridge; 1 virtual slot */
#define SFERA_VPTR_LISTITEMCTRL_SPHEREUI SFERA_VPTR_TOKEN(40u) /* .?AVListItemCtrl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_LISTCTRL_SPHEREUI SFERA_VPTR_TOKEN(41u) /* .?AVListCtrl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_CMENULISTCONTROL_SPHEREUI SFERA_VPTR_TOKEN(42u) /* .?AVCMenuListControl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_MINIHELPCTRL_SPHEREUI SFERA_VPTR_TOKEN(43u) /* .?AVMiniHelpCtrl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_CMINIMAPCONTROL_SPHEREUI SFERA_VPTR_TOKEN(44u) /* .?AVCMinimapControl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_PROGRESSBAR_SPHEREUI SFERA_VPTR_TOKEN(45u) /* .?AVProgressBar@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_RADIOBUTTONCTRL_SPHEREUI SFERA_VPTR_TOKEN(46u) /* .?AVRadioButtonCtrl@SphereUI@@, 13 virtual slot(s) */
#define SFERA_VPTR_RICHEDITCTRL_SPHEREUI SFERA_VPTR_TOKEN(47u) /* .?AVRichEditCtrl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_SCROLLBAR_SPHEREUI SFERA_VPTR_TOKEN(48u) /* .?AVScrollBar@SphereUI@@, 14 virtual slot(s) */
#define SFERA_VPTR_SLIDERCTRL_SPHEREUI SFERA_VPTR_TOKEN(49u) /* .?AVSliderCtrl@SphereUI@@, 14 virtual slot(s) */
#define SFERA_VPTR_SLOTCTRL_SPHEREUI SFERA_VPTR_TOKEN(50u) /* .?AVSlotCtrl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_SPINBUTTON_SPHEREUI SFERA_VPTR_TOKEN(51u) /* .?AVSpinButton@SphereUI@@, 13 virtual slot(s) */
#define SFERA_VPTR_TEXTCTRL_SPHEREUI SFERA_VPTR_TOKEN(52u) /* .?AVTextCtrl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_TOOLTIPCTRL_SPHEREUI SFERA_VPTR_TOKEN(53u) /* .?AVToolTipCtrl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_CWEBBROWSERCONTROL_SPHEREUI SFERA_VPTR_TOKEN(54u) /* .?AVCWebBrowserControl@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_WINDOW_SPHEREUI SFERA_VPTR_TOKEN(55u) /* .?AVWindow@SphereUI@@, 12 virtual slot(s) */
#define SFERA_VPTR_CCURSOR SFERA_VPTR_TOKEN(56u) /* .?AVCCursor@@, 14 virtual slot(s) */
#define SFERA_VPTR_CHARDWARECURSOR SFERA_VPTR_TOKEN(57u) /* .?AVCHardwareCursor@@, 14 virtual slot(s) */
#define SFERA_VPTR_CSOFTWARECURSOR SFERA_VPTR_TOKEN(58u) /* .?AVCSoftwareCursor@@, 14 virtual slot(s) */
#define SFERA_VPTR_UNMANAGEDRESOURCEVB SFERA_VPTR_TOKEN(59u) /* .?AVUnmanagedResourceVB@@, 2 virtual slot(s) */
#define SFERA_VPTR_UNMANAGEDRESOURCEIB SFERA_VPTR_TOKEN(60u) /* .?AVUnmanagedResourceIB@@, 2 virtual slot(s) */
#define SFERA_VPTR_UNMANAGEDRESOURCETEXTURE SFERA_VPTR_TOKEN(61u) /* .?AVUnmanagedResourceTexture@@, 2 virtual slot(s) */
#define SFERA_VPTR_VECT_UNMANAGEDRESOURCE_PTR SFERA_VPTR_TOKEN(62u) /* .?AV?$Vect@PAVUnmanagedResourceBase@@@@, 1 virtual slot(s) */
#define SFERA_VPTR_STDALLOCATOR SFERA_VPTR_TOKEN(63u) /* .?AVStdAllocator@@, 3 virtual slot(s) */
#define SFERA_VPTR_BAD_ALLOC SFERA_VPTR_TOKEN(64u) /* std::bad_alloc, semantic exception object */
#define SFERA_VPTR_COM_ERROR SFERA_VPTR_TOKEN(65u) /* _com_error, semantic exception object */

/* ===== Resolved .data pointer roots ===== */
/* Compatibility-address roots remain here only until their owning native objects are recovered.
 * Resolved runtime state must be addressed through its typed storage rather than a source-image constant. */

/* Native OLE32 consumes these exact x86 interface layouts. They are retained as a typed ABI bridge, not as generic source-image pointers. */
/* arithmetic base root; sfera_sub_00449180 @ lifted_functions_007.c:7297; source=0x00663FC0 */
#define SFERA_DATA_ARITHMETIC_BASE_00663FC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00663FC0))
/* call argument root; sfera_sub_00449180 @ lifted_functions_007.c:7301; source=0x006BDD5C */
#define SFERA_DATA_CALL_ARGUMENT_006BDD5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BDD5C))
/* call argument root; sfera_sub_00449180 @ lifted_functions_007.c:7309; source=0x006BDEF4 */
#define SFERA_DATA_CALL_ARGUMENT_006BDEF4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BDEF4))
/* call argument root; sfera_sub_00432790 @ lifted_functions_005.c:3881; source=0x006BE154 */
#define SFERA_DATA_CALL_ARGUMENT_006BE154_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE154))
/* global object root; sfera_sub_004F5450 @ lifted_functions_025.c:1713; source=0x006BE1F8 */
#define SFERA_DATA_GLOBAL_OBJECT_006BE1F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1F8))
/* global object root; sfera_sub_004F5480 @ lifted_functions_025.c:1735; source=0x006BE258 */
#define SFERA_DATA_GLOBAL_OBJECT_006BE258_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE258))
/* indexed table base root; sfera_sub_0043ECC0 @ lifted_functions_006.c:7183; source=0x048F5698 */
#define SFERA_DATA_TABLE_BASE_048F5698_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F5698))
/* global object root; sfera_sub_004F54C0 @ lifted_functions_025.c:1746; source=0x04DBC4A0 */
#define SFERA_DATA_GLOBAL_OBJECT_04DBC4A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC4A0))
/* global object root; sfera_sub_004F54F0 @ lifted_functions_025.c:1768; source=0x04DC0520 */
#define SFERA_DATA_GLOBAL_OBJECT_04DC0520_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DC0520))
/* global object root; sfera_sub_004F55B0 @ lifted_functions_025.c:1848; source=0x04DD0A30 */
#define SFERA_DATA_GLOBAL_OBJECT_04DD0A30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0A30))
/* global object root; sfera_sub_004F55E0 @ lifted_functions_025.c:1870; source=0x04DD0A98 */
#define SFERA_DATA_GLOBAL_OBJECT_04DD0A98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0A98))
/* call argument root; sfera_sub_004F5700 @ lifted_functions_025.c:1941; source=0x04DD0B00 */
#define SFERA_DATA_CALL_ARGUMENT_04DD0B00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0B00))
/* call argument root; sfera_sub_004F5690 @ lifted_functions_025.c:1917; source=0x04DD0B2C */
#define SFERA_DATA_CALL_ARGUMENT_04DD0B2C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0B2C))
/* call argument root; sfera_sub_004F5620 @ lifted_functions_025.c:1893; source=0x04DD0B58 */
#define SFERA_DATA_CALL_ARGUMENT_04DD0B58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0B58))
/* global object root; sfera_sub_004F5770 @ lifted_functions_025.c:1953; source=0x04DD0B90 */
#define SFERA_DATA_GLOBAL_OBJECT_04DD0B90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0B90))
/* global object root; sfera_sub_004F57A0 @ lifted_functions_025.c:1975; source=0x04DD0BF0 */
#define SFERA_DATA_GLOBAL_OBJECT_04DD0BF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0BF0))
/* global object root; sfera_sub_00454BA0 @ lifted_functions_008.c:8467; source=0x04DD1074 */
#define SFERA_DATA_GLOBAL_OBJECT_04DD1074_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1074))
/* arithmetic base root; sfera_sub_0045BE50 @ lifted_functions_009.c:4909; source=0x04DD12A8 */
#define SFERA_DATA_ARITHMETIC_BASE_04DD12A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD12A8))
/* global object root; sfera_sub_00464BA0 @ lifted_functions_010.c:3282; source=0x04DD12A9 */
#define SFERA_DATA_GLOBAL_OBJECT_04DD12A9_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD12A9))
/* pointer value root; sfera_sub_00464BA0 @ lifted_functions_010.c:3365; source=0x04DD52A9 */
#define SFERA_DATA_POINTER_VALUE_04DD52A9_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD52A9))
/* indexed table base root; sfera_sub_0047D040 @ lifted_functions_012.c:6540; source=0x04DD563C */
#define SFERA_DATA_TABLE_BASE_04DD563C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD563C))
/* global object root; sfera_sub_0047D040 @ lifted_functions_012.c:6523; source=0x04DD5640 */
#define SFERA_DATA_GLOBAL_OBJECT_04DD5640_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5640))
/* pointer value root; sfera_sub_0047D040 @ lifted_functions_012.c:6537; source=0x04DD565C */
#define SFERA_DATA_POINTER_VALUE_04DD565C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD565C))
/* indexed table base root; sfera_sub_0044E480 @ lifted_functions_008.c:590; source=0x04DD7A4C */
#define SFERA_DATA_TABLE_BASE_04DD7A4C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7A4C))
/* indexed table base root; sfera_sub_0044E480 @ lifted_functions_008.c:592; source=0x04DD7A78 */
#define SFERA_DATA_TABLE_BASE_04DD7A78_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7A78))
/* indexed table base root; sfera_sub_0044E480 @ lifted_functions_008.c:606; source=0x04DD7A7C */
#define SFERA_DATA_TABLE_BASE_04DD7A7C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7A7C))
/* indexed table base root; sfera_sub_0044D960 @ lifted_functions_007.c:12513; source=0x04DD7C58 */
#define SFERA_DATA_TABLE_BASE_04DD7C58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C58))
/* global object root; sfera_sub_0047A150 @ lifted_functions_012.c:2398; source=0x04DDFE60 */
#define SFERA_DATA_GLOBAL_OBJECT_04DDFE60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDFE60))
/* global object root; sfera_sub_0047D040 @ lifted_functions_012.c:6150; source=0x04DE04C4 */
#define SFERA_DATA_GLOBAL_OBJECT_04DE04C4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DE04C4))
/* pointer value root; sfera_sub_0047A150 @ lifted_functions_012.c:2414; source=0x04DE04F0 */
#define SFERA_DATA_POINTER_VALUE_04DE04F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DE04F0))
/* arithmetic base root; sfera_sub_00459FA0 @ lifted_functions_009.c:2939; source=0x04DE1172 */
#define SFERA_DATA_ARITHMETIC_BASE_04DE1172_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DE1172))
/* arithmetic base root; sfera_sub_00461220 @ lifted_functions_009.c:10850; source=0x04E016A8 */
#define SFERA_DATA_ARITHMETIC_BASE_04E016A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E016A8))
/* arithmetic base root; sfera_sub_00461220 @ lifted_functions_009.c:10861; source=0x04E016AC */
#define SFERA_DATA_ARITHMETIC_BASE_04E016AC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E016AC))
/* arithmetic base root; sfera_sub_00461220 @ lifted_functions_009.c:10906; source=0x04E01AF4 */
#define SFERA_DATA_ARITHMETIC_BASE_04E01AF4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E01AF4))
/* arithmetic base root; sfera_sub_0045BE50 @ lifted_functions_009.c:4862; source=0x04E1CF48 */
#define SFERA_DATA_ARITHMETIC_BASE_04E1CF48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1CF48))
/* pointer value root; sfera_sub_0045BE50 @ lifted_functions_009.c:4841; source=0x04E1D26C */
#define SFERA_DATA_POINTER_VALUE_04E1D26C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1D26C))
/* arithmetic base root; sfera_sub_0044EBC0 @ lifted_functions_008.c:1104; source=0x04E1DC0F */
#define SFERA_DATA_ARITHMETIC_BASE_04E1DC0F_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DC0F))
/* array base root; sfera_sub_0047A150 @ lifted_functions_012.c:3009; source=0x04E1DC10 */
#define SFERA_DATA_ARRAY_BASE_04E1DC10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DC10))
/* arithmetic base root; sfera_sub_0044DAC0 @ lifted_functions_007.c:12639; source=0x04E2BFB0 */
#define SFERA_DATA_ARITHMETIC_BASE_04E2BFB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2BFB0))
/* global object root; sfera_sub_0048A740 @ lifted_functions_013.c:10941; source=0x04E2C930 */
#define SFERA_DATA_GLOBAL_OBJECT_04E2C930_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C930))
/* indexed table base root; sfera_sub_00457E80 @ lifted_functions_009.c:1018; source=0x04E2DE1E */
#define SFERA_DATA_TABLE_BASE_04E2DE1E_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DE1E))
/* indexed table base root; sfera_sub_00457E80 @ lifted_functions_009.c:1020; source=0x04E2DE20 */
#define SFERA_DATA_TABLE_BASE_04E2DE20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DE20))
/* indexed table base root; sfera_sub_00457E80 @ lifted_functions_009.c:1021; source=0x04E2DE22 */
#define SFERA_DATA_TABLE_BASE_04E2DE22_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DE22))
/* indexed table base root; sfera_sub_0047B3D0 @ lifted_functions_012.c:4006; source=0x04E73328 */
#define SFERA_DATA_TABLE_BASE_04E73328_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E73328))
/* global object root; sfera_sub_0045BC60 @ lifted_functions_009.c:4722; source=0x04E769E8 */
#define SFERA_DATA_GLOBAL_OBJECT_04E769E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E769E8))
/* global object root; sfera_sub_0047D040 @ lifted_functions_012.c:6167; source=0x04E78A1C */
#define SFERA_DATA_GLOBAL_OBJECT_04E78A1C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78A1C))
/* global object root; sfera_sub_0047C670 @ lifted_functions_012.c:5389; source=0x04E78AAC */
#define SFERA_DATA_GLOBAL_OBJECT_04E78AAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78AAC))
/* global object root; sfera_sub_0047C670 @ lifted_functions_012.c:5386; source=0x04E78C08 */
#define SFERA_DATA_GLOBAL_OBJECT_04E78C08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78C08))
/* arithmetic base root; sfera_sub_0044EBC0 @ lifted_functions_008.c:1103; source=0x04E78FB7 */
#define SFERA_DATA_ARITHMETIC_BASE_04E78FB7_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78FB7))
/* array base root; sfera_sub_0047A150 @ lifted_functions_012.c:3007; source=0x04E78FB8 */
#define SFERA_DATA_ARRAY_BASE_04E78FB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78FB8))
/* arithmetic base root; sfera_sub_0044EBC0 @ lifted_functions_008.c:1106; source=0x04E790B7 */
#define SFERA_DATA_ARITHMETIC_BASE_04E790B7_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E790B7))
/* array base root; sfera_sub_0047A150 @ lifted_functions_012.c:3014; source=0x04E790B8 */
#define SFERA_DATA_ARRAY_BASE_04E790B8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E790B8))
/* call argument root; sfera_sub_004F6470 @ lifted_functions_025.c:2853; source=0x04EC4F8C */
#define SFERA_DATA_CALL_ARGUMENT_04EC4F8C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F8C))
/* call argument root; sfera_sub_004F6510 @ lifted_functions_025.c:2877; source=0x04EC4FC4 */
#define SFERA_DATA_CALL_ARGUMENT_04EC4FC4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4FC4))
/* call argument root; sfera_sub_0047A150 @ lifted_functions_012.c:2972; source=0x04EC4FE8 */
#define SFERA_DATA_CALL_ARGUMENT_04EC4FE8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4FE8))
/* arithmetic base root; sfera_sub_0047A150 @ lifted_functions_012.c:2495; source=0x04EC4FEC */
#define SFERA_DATA_ARITHMETIC_BASE_04EC4FEC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4FEC))
/* arithmetic base root; sfera_sub_0047A150 @ lifted_functions_012.c:2499; source=0x04EC4FFC */
#define SFERA_DATA_ARITHMETIC_BASE_04EC4FFC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4FFC))
/* arithmetic base root; sfera_sub_0047A150 @ lifted_functions_012.c:2501; source=0x04EC5000 */
#define SFERA_DATA_ARITHMETIC_BASE_04EC5000_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC5000))
/* arithmetic base root; sfera_sub_0047A150 @ lifted_functions_012.c:2503; source=0x04EC5004 */
#define SFERA_DATA_ARITHMETIC_BASE_04EC5004_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC5004))
/* arithmetic base root; sfera_sub_0047A150 @ lifted_functions_012.c:2510; source=0x04EC5134 */
#define SFERA_DATA_ARITHMETIC_BASE_04EC5134_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC5134))
/* arithmetic base root; sfera_sub_0047A150 @ lifted_functions_012.c:2504; source=0x04EC5140 */
#define SFERA_DATA_ARITHMETIC_BASE_04EC5140_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC5140))
/* arithmetic base root; sfera_sub_0047A150 @ lifted_functions_012.c:2506; source=0x04EC5144 */
#define SFERA_DATA_ARITHMETIC_BASE_04EC5144_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC5144))
/* arithmetic base root; sfera_sub_0047A150 @ lifted_functions_012.c:2508; source=0x04EC5148 */
#define SFERA_DATA_ARITHMETIC_BASE_04EC5148_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC5148))
/* global object root; sfera_sub_0047A150 @ lifted_functions_012.c:2790; source=0x04EC55DC */
#define SFERA_DATA_GLOBAL_OBJECT_04EC55DC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC55DC))
/* global object root; sfera_sub_0047A150 @ lifted_functions_012.c:2670; source=0x04EC5BC0 */
#define SFERA_DATA_GLOBAL_OBJECT_04EC5BC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC5BC0))
/* call argument root; sfera_sub_004F5920 @ lifted_functions_025.c:2081; source=0x04ED0D84 */
#define SFERA_DATA_CALL_ARGUMENT_04ED0D84_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0D84))
/* global object root; sfera_sub_004F57E0 @ lifted_functions_025.c:1986; source=0x04ED0DB8 */
#define SFERA_DATA_GLOBAL_OBJECT_04ED0DB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0DB8))
/* global object root; sfera_sub_004F5810 @ lifted_functions_025.c:2008; source=0x04ED0F88 */
#define SFERA_DATA_GLOBAL_OBJECT_04ED0F88_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0F88))
/* call argument root; sfera_sub_004F6650 @ lifted_functions_025.c:2965; source=0x04ED1134 */
#define SFERA_DATA_CALL_ARGUMENT_04ED1134_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1134))
/* call argument root; sfera_sub_004F6580 @ lifted_functions_025.c:2921; source=0x04ED116C */
#define SFERA_DATA_CALL_ARGUMENT_04ED116C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED116C))
/* call argument root; sfera_sub_004F6720 @ lifted_functions_025.c:3009; source=0x04ED11FC */
#define SFERA_DATA_CALL_ARGUMENT_04ED11FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED11FC))
/* call argument root; sfera_sub_004F5A40 @ lifted_functions_025.c:2135; source=0x04ED1234 */
#define SFERA_DATA_CALL_ARGUMENT_04ED1234_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1234))
/* call argument root; sfera_sub_004F5BF0 @ lifted_functions_025.c:2216; source=0x04ED1304 */
/* indexed table base root; sfera_sub_00468750 @ lifted_functions_010.c:6796; source=0x04ED1328 */
#define SFERA_DATA_TABLE_BASE_04ED1328_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1328))
/* call argument root; sfera_sub_004F5C90 @ lifted_functions_025.c:2356; source=0x04ED1A44 */
#define SFERA_DATA_CALL_ARGUMENT_04ED1A44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1A44))
/* call argument root; sfera_sub_004F5B60 @ lifted_functions_025.c:2189; source=0x04ED1A7C */
#define SFERA_DATA_CALL_ARGUMENT_04ED1A7C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1A7C))
/* call argument root; sfera_sub_004F7010 @ lifted_functions_025.c:3481; source=0x04ED2A58 */
#define SFERA_DATA_CALL_ARGUMENT_04ED2A58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2A58))
/* call argument root; sfera_sub_004F59B0 @ lifted_functions_025.c:2108; source=0x04ED2BBC */
#define SFERA_DATA_CALL_ARGUMENT_04ED2BBC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2BBC))
/* global object root; sfera_sub_00443F20 @ lifted_functions_007.c:4219; source=0x04ED2CC0 */
#define SFERA_DATA_GLOBAL_OBJECT_04ED2CC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2CC0))
/* call argument root; sfera_sub_004F68C0 @ lifted_functions_025.c:3080; source=0x04ED2D3C */
#define SFERA_DATA_CALL_ARGUMENT_04ED2D3C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2D3C))
/* call argument root; sfera_sub_004F6B10 @ lifted_functions_025.c:3200; source=0x04ED2DC0 */
#define SFERA_DATA_CALL_ARGUMENT_04ED2DC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2DC0))
/* call argument root; sfera_sub_004F6FA0 @ lifted_functions_025.c:3457; source=0x04ED2EF8 */
#define SFERA_DATA_CALL_ARGUMENT_04ED2EF8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2EF8))
/* call argument root; sfera_sub_004F5AD0 @ lifted_functions_025.c:2162; source=0x04ED304C */
#define SFERA_DATA_CALL_ARGUMENT_04ED304C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED304C))
/* call argument root; sfera_sub_004F5D20 @ lifted_functions_025.c:2383; source=0x04ED30DC */
#define SFERA_DATA_CALL_ARGUMENT_04ED30DC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED30DC))
/* call argument root; sfera_sub_004F7080 @ lifted_functions_025.c:3505; source=0x04EDCCD4 */
#define SFERA_DATA_CALL_ARGUMENT_04EDCCD4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCCD4))
/* call argument root; sfera_sub_004F5890 @ lifted_functions_025.c:2054; source=0x04EDCDAC */
#define SFERA_DATA_CALL_ARGUMENT_04EDCDAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCDAC))
/* call argument root; sfera_sub_004F6B80 @ lifted_functions_025.c:3227; source=0x04EDCF54 */
#define SFERA_DATA_CALL_ARGUMENT_04EDCF54_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCF54))
/* call argument root; sfera_sub_004F67F0 @ lifted_functions_025.c:3053; source=0x04EDD044 */
#define SFERA_DATA_CALL_ARGUMENT_04EDD044_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD044))
/* global object root; sfera_sub_004F7780 @ lifted_functions_025.c:3877; source=0x04EE04B8 */
#define SFERA_DATA_GLOBAL_OBJECT_04EE04B8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE04B8))
/* global object root; sfera_sub_004F77B0 @ lifted_functions_025.c:3899; source=0x04EE0518 */
#define SFERA_DATA_GLOBAL_OBJECT_04EE0518_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE0518))
/* global object root; sfera_sub_0047DB70 @ lifted_functions_012.c:7263; source=0x04EE057C */
/* pointer value root; sfera_sub_0047DB70 @ lifted_functions_012.c:7290; source=0x04EE097C */
/* global object root; sfera_sub_0047DB70 @ lifted_functions_012.c:7325; source=0x04EE0AAC */
/* pointer value root; sfera_sub_0047DB70 @ lifted_functions_012.c:7352; source=0x04EE0EAC */
/* array base root; sfera_sub_0047E520 @ lifted_functions_012.c:7809; source=0x04EE6157 */
#define SFERA_DATA_ARRAY_BASE_04EE6157_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE6157))
/* global object root; sfera_sub_004F77F0 @ lifted_functions_025.c:3910; source=0x04EE8570 */
#define SFERA_DATA_GLOBAL_OBJECT_04EE8570_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE8570))
/* global object root; sfera_sub_004F7820 @ lifted_functions_025.c:3932; source=0x04EE85D0 */
#define SFERA_DATA_GLOBAL_OBJECT_04EE85D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE85D0))
/* global object root; sfera_sub_004F7860 @ lifted_functions_025.c:3943; source=0x04EE8640 */
#define SFERA_DATA_GLOBAL_OBJECT_04EE8640_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE8640))
/* global object root; sfera_sub_004F7890 @ lifted_functions_025.c:3965; source=0x04EE86A0 */
#define SFERA_DATA_GLOBAL_OBJECT_04EE86A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE86A0))
/* global object root; sfera_sub_004F78D0 @ lifted_functions_025.c:3976; source=0x04EEA020 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEA020_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA020))
/* global object root; sfera_sub_004F7900 @ lifted_functions_025.c:3998; source=0x04EEA080 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEA080_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA080))
/* call argument root; sfera_sub_0047FDC0 @ lifted_functions_012.c:9933; source=0x04EEA168 */
#define SFERA_DATA_CALL_ARGUMENT_04EEA168_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA168))
/* global object root; sfera_sub_0047FF70 @ lifted_functions_012.c:10047; source=0x04EEA338 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEA338_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA338))
/* indexed table base root; sfera_sub_0047FF70 @ lifted_functions_012.c:10060; source=0x04EEA344 */
#define SFERA_DATA_TABLE_BASE_04EEA344_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA344))
/* global object root; sfera_sub_004F7940 @ lifted_functions_025.c:4009; source=0x04EEA830 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEA830_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA830))
/* global object root; sfera_sub_004F7970 @ lifted_functions_025.c:4031; source=0x04EEA890 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEA890_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA890))
/* global object root; sfera_sub_004F79B0 @ lifted_functions_025.c:4042; source=0x04EEA900 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEA900_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA900))
/* global object root; sfera_sub_004F79E0 @ lifted_functions_025.c:4064; source=0x04EEA960 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEA960_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA960))
/* global object root; sfera_sub_004F7A20 @ lifted_functions_025.c:4075; source=0x04EEA9D0 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEA9D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA9D0))
/* global object root; sfera_sub_004F7A50 @ lifted_functions_025.c:4097; source=0x04EEAA30 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEAA30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAA30))
/* global object root; sfera_sub_004F7A90 @ lifted_functions_025.c:4108; source=0x04EEAAA0 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEAAA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAAA0))
/* global object root; sfera_sub_004F7AC0 @ lifted_functions_025.c:4130; source=0x04EEAB00 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEAB00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAB00))
/* global object root; sfera_sub_004F7B00 @ lifted_functions_025.c:4141; source=0x04EEAB70 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEAB70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAB70))
/* global object root; sfera_sub_004F7B30 @ lifted_functions_025.c:4163; source=0x04EEABD0 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEABD0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEABD0))
/* global object root; sfera_sub_004F7B70 @ lifted_functions_025.c:4174; source=0x04EEAC40 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEAC40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAC40))
/* global object root; sfera_sub_004F7BA0 @ lifted_functions_025.c:4196; source=0x04EEACA0 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEACA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEACA0))
/* global object root; sfera_sub_004F7BF0 @ lifted_functions_025.c:4214; source=0x04EEAD20 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEAD20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAD20))
/* global object root; sfera_sub_004F7C20 @ lifted_functions_025.c:4236; source=0x04EEAD80 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEAD80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAD80))
/* global object root; sfera_sub_004F7CA0 @ lifted_functions_025.c:4267; source=0x04EEAEF0 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEAEF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAEF0))
/* global object root; sfera_sub_004F7CD0 @ lifted_functions_025.c:4289; source=0x04EEAF50 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEAF50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAF50))
/* global object root; sfera_sub_004F7D10 @ lifted_functions_025.c:4300; source=0x04EEAFC0 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEAFC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAFC0))
/* global object root; sfera_sub_004F7D40 @ lifted_functions_025.c:4322; source=0x04EEB020 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEB020_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB020))
/* global object root; sfera_sub_004F7D80 @ lifted_functions_025.c:4333; source=0x04EEB098 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEB098_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB098))
/* global object root; sfera_sub_004F7DB0 @ lifted_functions_025.c:4355; source=0x04EEB0F8 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEB0F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB0F8))
/* global object root; sfera_sub_004F7E00 @ lifted_functions_025.c:4373; source=0x04EEB170 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEB170_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB170))
/* global object root; sfera_sub_004F7E30 @ lifted_functions_025.c:4395; source=0x04EEB1D0 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEB1D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB1D0))
/* global object root; sfera_sub_004F7E70 @ lifted_functions_025.c:4406; source=0x04EEB448 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEB448_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB448))
/* global object root; sfera_sub_004F7EA0 @ lifted_functions_025.c:4428; source=0x04EEB4A8 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEB4A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB4A8))
/* global object root; sfera_sub_004F7EF0 @ lifted_functions_025.c:4446; source=0x04EEB520 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEB520_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB520))
/* global object root; sfera_sub_004F7F20 @ lifted_functions_025.c:4468; source=0x04EEB580 */
#define SFERA_DATA_GLOBAL_OBJECT_04EEB580_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB580))
/* indexed table base root; sfera_sub_00499980 @ lifted_functions_015.c:6893; source=0x04F17928 */
#define SFERA_DATA_TABLE_BASE_04F17928_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F17928))
/* global object root; sfera_sub_004F7F60 @ lifted_functions_025.c:4479; source=0x04F379F8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F379F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F379F8))
/* global object root; sfera_sub_004F7F90 @ lifted_functions_025.c:4501; source=0x04F37A58 */
#define SFERA_DATA_GLOBAL_OBJECT_04F37A58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37A58))
/* global object root; sfera_sub_004F7FD0 @ lifted_functions_025.c:4512; source=0x04F37AC8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F37AC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37AC8))
/* global object root; sfera_sub_004F8000 @ lifted_functions_025.c:4534; source=0x04F37B28 */
#define SFERA_DATA_GLOBAL_OBJECT_04F37B28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37B28))
/* global object root; sfera_sub_004F8040 @ lifted_functions_025.c:4545; source=0x04F38828 */
#define SFERA_DATA_GLOBAL_OBJECT_04F38828_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38828))
/* global object root; sfera_sub_004F8070 @ lifted_functions_025.c:4567; source=0x04F388B0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F388B0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F388B0))
/* global object root; sfera_sub_004F8120 @ lifted_functions_025.c:4602; source=0x04F389F8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F389F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F389F8))
/* global object root; sfera_sub_004F8150 @ lifted_functions_025.c:4624; source=0x04F38A58 */
#define SFERA_DATA_GLOBAL_OBJECT_04F38A58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38A58))
/* global object root; sfera_sub_004F8190 @ lifted_functions_025.c:4635; source=0x04F38BC8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F38BC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38BC8))
/* global object root; sfera_sub_004F81C0 @ lifted_functions_025.c:4657; source=0x04F38C28 */
#define SFERA_DATA_GLOBAL_OBJECT_04F38C28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38C28))
/* global object root; sfera_sub_004F8240 @ lifted_functions_025.c:4688; source=0x04F38D98 */
#define SFERA_DATA_GLOBAL_OBJECT_04F38D98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38D98))
/* global object root; sfera_sub_004F8270 @ lifted_functions_025.c:4710; source=0x04F38DF8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F38DF8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38DF8))
/* global object root; sfera_sub_004F82F0 @ lifted_functions_025.c:4741; source=0x04F38E68 */
#define SFERA_DATA_GLOBAL_OBJECT_04F38E68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38E68))
/* global object root; sfera_sub_004F8320 @ lifted_functions_025.c:4763; source=0x04F38EC8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F38EC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38EC8))
/* global object root; sfera_sub_004F8360 @ lifted_functions_025.c:4774; source=0x04F38F40 */
#define SFERA_DATA_GLOBAL_OBJECT_04F38F40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38F40))
/* global object root; sfera_sub_004F8390 @ lifted_functions_025.c:4796; source=0x04F38FA0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F38FA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38FA0))
/* global object root; sfera_sub_004F8410 @ lifted_functions_025.c:4827; source=0x04F39010 */
#define SFERA_DATA_GLOBAL_OBJECT_04F39010_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F39010))
/* global object root; sfera_sub_004F8440 @ lifted_functions_025.c:4849; source=0x04F39070 */
#define SFERA_DATA_GLOBAL_OBJECT_04F39070_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F39070))
/* global object root; sfera_sub_004F84C0 @ lifted_functions_025.c:4880; source=0x04F390E0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F390E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F390E0))
/* global object root; sfera_sub_004F84F0 @ lifted_functions_025.c:4902; source=0x04F39140 */
#define SFERA_DATA_GLOBAL_OBJECT_04F39140_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F39140))
/* indexed table base root; sfera_sub_004A4E10 @ lifted_functions_016.c:9531; source=0x04F391A2 */
#define SFERA_DATA_TABLE_BASE_04F391A2_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F391A2))
/* indexed table base root; sfera_sub_004A4E10 @ lifted_functions_016.c:9527; source=0x04F391A4 */
#define SFERA_DATA_TABLE_BASE_04F391A4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F391A4))
/* indexed table base root; sfera_sub_004A4E10 @ lifted_functions_016.c:9534; source=0x04F391A6 */
#define SFERA_DATA_TABLE_BASE_04F391A6_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F391A6))
/* indexed table base root; sfera_sub_004A4E10 @ lifted_functions_016.c:9528; source=0x04F391A8 */
#define SFERA_DATA_TABLE_BASE_04F391A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F391A8))
/* indexed table base root; sfera_sub_004A4E10 @ lifted_functions_016.c:9532; source=0x04F391AA */
#define SFERA_DATA_TABLE_BASE_04F391AA_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F391AA))
/* global object root; sfera_sub_004F8570 @ lifted_functions_025.c:4933; source=0x04F3A478 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3A478_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A478))
/* global object root; sfera_sub_004F85A0 @ lifted_functions_025.c:4955; source=0x04F3A4E8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3A4E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A4E8))
/* global object root; sfera_sub_004F85F0 @ lifted_functions_025.c:4973; source=0x04F3A558 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3A558_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A558))
/* global object root; sfera_sub_004F8620 @ lifted_functions_025.c:4995; source=0x04F3A5B8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3A5B8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A5B8))
/* global object root; sfera_sub_004F86A0 @ lifted_functions_025.c:5026; source=0x04F3A928 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3A928_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A928))
/* global object root; sfera_sub_004F86D0 @ lifted_functions_025.c:5048; source=0x04F3A988 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3A988_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A988))
/* global object root; sfera_sub_004F8710 @ lifted_functions_025.c:5059; source=0x04F3A9F8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3A9F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A9F8))
/* global object root; sfera_sub_004F8740 @ lifted_functions_025.c:5081; source=0x04F3AA58 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3AA58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AA58))
/* global object root; sfera_sub_004F87C0 @ lifted_functions_025.c:5112; source=0x04F3AAC8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3AAC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AAC8))
/* global object root; sfera_sub_004F87F0 @ lifted_functions_025.c:5134; source=0x04F3AB28 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3AB28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AB28))
/* global object root; sfera_sub_004F8870 @ lifted_functions_025.c:5165; source=0x04F3AC98 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3AC98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AC98))
/* global object root; sfera_sub_004F88A0 @ lifted_functions_025.c:5187; source=0x04F3ACF8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3ACF8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3ACF8))
/* global object root; sfera_sub_004F8920 @ lifted_functions_025.c:5218; source=0x04F3AD70 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3AD70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AD70))
/* global object root; sfera_sub_004F8950 @ lifted_functions_025.c:5240; source=0x04F3ADD0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3ADD0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3ADD0))
/* global object root; sfera_sub_004F89D0 @ lifted_functions_025.c:5271; source=0x04F3AF40 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3AF40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AF40))
/* global object root; sfera_sub_004F8A00 @ lifted_functions_025.c:5293; source=0x04F3AFA0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3AFA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AFA0))
/* global object root; sfera_sub_004F8A80 @ lifted_functions_025.c:5324; source=0x04F3B0C0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3B0C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B0C0))
/* global object root; sfera_sub_004F8AB0 @ lifted_functions_025.c:5346; source=0x04F3B128 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3B128_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B128))
/* global object root; sfera_sub_004F8DA0 @ lifted_functions_025.c:5569; source=0x04F3BAD8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3BAD8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3BAD8))
/* global object root; sfera_sub_004F8DD0 @ lifted_functions_025.c:5591; source=0x04F3BB38 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3BB38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3BB38))
/* global object root; sfera_sub_004F8E50 @ lifted_functions_025.c:5622; source=0x04F3BBA8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3BBA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3BBA8))
/* global object root; sfera_sub_004F8E80 @ lifted_functions_025.c:5644; source=0x04F3BC08 */
#define SFERA_DATA_GLOBAL_OBJECT_04F3BC08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3BC08))
/* global object root; sfera_sub_004F8EC0 @ lifted_functions_025.c:5655; source=0x04F47C78 */
#define SFERA_DATA_GLOBAL_OBJECT_04F47C78_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47C78))
/* global object root; sfera_sub_004F8EF0 @ lifted_functions_025.c:5677; source=0x04F47CD8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F47CD8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47CD8))
/* global object root; sfera_sub_004F8F70 @ lifted_functions_025.c:5708; source=0x04F47D48 */
#define SFERA_DATA_GLOBAL_OBJECT_04F47D48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47D48))
/* global object root; sfera_sub_004F8FA0 @ lifted_functions_025.c:5730; source=0x04F47DA8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F47DA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47DA8))
/* global object root; sfera_sub_004F9080 @ lifted_functions_025.c:5791; source=0x04F47E18 */
#define SFERA_DATA_GLOBAL_OBJECT_04F47E18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47E18))
/* global object root; sfera_sub_004F90B0 @ lifted_functions_025.c:5813; source=0x04F47E78 */
#define SFERA_DATA_GLOBAL_OBJECT_04F47E78_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47E78))
/* global object root; sfera_sub_004F9130 @ lifted_functions_025.c:5844; source=0x04F47EE8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F47EE8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47EE8))
/* global object root; sfera_sub_004F9160 @ lifted_functions_025.c:5866; source=0x04F47F48 */
#define SFERA_DATA_GLOBAL_OBJECT_04F47F48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47F48))
/* global object root; sfera_sub_004F91E0 @ lifted_functions_025.c:5897; source=0x04F47FC0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F47FC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47FC0))
/* global object root; sfera_sub_004F9210 @ lifted_functions_025.c:5919; source=0x04F48020 */
#define SFERA_DATA_GLOBAL_OBJECT_04F48020_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48020))
/* global object root; sfera_sub_004F9250 @ lifted_functions_025.c:5930; source=0x04F48190 */
#define SFERA_DATA_GLOBAL_OBJECT_04F48190_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48190))
/* global object root; sfera_sub_004F9280 @ lifted_functions_025.c:5952; source=0x04F481F0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F481F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F481F0))
/* global object root; sfera_sub_004F9300 @ lifted_functions_025.c:5983; source=0x04F48260 */
#define SFERA_DATA_GLOBAL_OBJECT_04F48260_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48260))
/* global object root; sfera_sub_004F9330 @ lifted_functions_025.c:6005; source=0x04F482C0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F482C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F482C0))
/* global object root; sfera_sub_004F93B0 @ lifted_functions_025.c:6036; source=0x04F48330 */
#define SFERA_DATA_GLOBAL_OBJECT_04F48330_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48330))
/* global object root; sfera_sub_004F93E0 @ lifted_functions_025.c:6058; source=0x04F48390 */
#define SFERA_DATA_GLOBAL_OBJECT_04F48390_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48390))
/* global object root; sfera_sub_004F9460 @ lifted_functions_025.c:6089; source=0x04F48500 */
#define SFERA_DATA_GLOBAL_OBJECT_04F48500_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48500))
/* global object root; sfera_sub_004F9490 @ lifted_functions_025.c:6111; source=0x04F48560 */
#define SFERA_DATA_GLOBAL_OBJECT_04F48560_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48560))
/* global object root; sfera_sub_004F9510 @ lifted_functions_025.c:6142; source=0x04F486D0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F486D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F486D0))
/* global object root; sfera_sub_004F9540 @ lifted_functions_025.c:6164; source=0x04F48730 */
#define SFERA_DATA_GLOBAL_OBJECT_04F48730_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48730))
/* global object root; sfera_sub_004F95C0 @ lifted_functions_025.c:6195; source=0x04F488A0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F488A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F488A0))
/* global object root; sfera_sub_004F95F0 @ lifted_functions_025.c:6217; source=0x04F48900 */
#define SFERA_DATA_GLOBAL_OBJECT_04F48900_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48900))
/* global object root; sfera_sub_004C9EB0 @ lifted_functions_020.c:7862; source=0x04F48DF0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F48DF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48DF0))
/* global object root; sfera_sub_004C9EB0 @ lifted_functions_020.c:7876; source=0x04F48FF0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F48FF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48FF0))
/* global object root; sfera_sub_004C9EB0 @ lifted_functions_020.c:7890; source=0x04F491F0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F491F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F491F0))
/* global object root; sfera_sub_004F9670 @ lifted_functions_025.c:6248; source=0x04F49AB0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F49AB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49AB0))
/* global object root; sfera_sub_004F96A0 @ lifted_functions_025.c:6270; source=0x04F49B10 */
#define SFERA_DATA_GLOBAL_OBJECT_04F49B10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49B10))
/* global object root; sfera_sub_004F9750 @ lifted_functions_025.c:6322; source=0x04F49CB0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F49CB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49CB0))
/* global object root; sfera_sub_004F9780 @ lifted_functions_025.c:6344; source=0x04F49D10 */
#define SFERA_DATA_GLOBAL_OBJECT_04F49D10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49D10))
/* call argument root; sfera_sub_004CE8A0 @ lifted_functions_021.c:2503; source=0x04F49D70 */
#define SFERA_DATA_CALL_ARGUMENT_04F49D70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49D70))
/* global object root; sfera_sub_004F9800 @ lifted_functions_025.c:6375; source=0x04F49E80 */
#define SFERA_DATA_GLOBAL_OBJECT_04F49E80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49E80))
/* global object root; sfera_sub_004F9830 @ lifted_functions_025.c:6397; source=0x04F49EE0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F49EE0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49EE0))
/* global object root; sfera_sub_004F9870 @ lifted_functions_025.c:6408; source=0x04F4A0D0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4A0D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A0D0))
/* global object root; sfera_sub_004F98A0 @ lifted_functions_025.c:6430; source=0x04F4A130 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4A130_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A130))
/* global object root; sfera_sub_004F9920 @ lifted_functions_025.c:6461; source=0x04F4A2A0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4A2A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A2A0))
/* global object root; sfera_sub_004F9950 @ lifted_functions_025.c:6483; source=0x04F4A300 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4A300_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A300))
/* global object root; sfera_sub_004F99D0 @ lifted_functions_025.c:6514; source=0x04F4A370 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4A370_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A370))
/* global object root; sfera_sub_004F9A00 @ lifted_functions_025.c:6536; source=0x04F4A3D0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4A3D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A3D0))
/* global object root; sfera_sub_004F9A80 @ lifted_functions_025.c:6567; source=0x04F4A440 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4A440_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A440))
/* global object root; sfera_sub_004F9AB0 @ lifted_functions_025.c:6589; source=0x04F4A4A8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4A4A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A4A8))
/* global object root; sfera_sub_004F9B50 @ lifted_functions_025.c:6631; source=0x04F4A530 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4A530_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A530))
/* global object root; sfera_sub_004F9B80 @ lifted_functions_025.c:6653; source=0x04F4A590 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4A590_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A590))
/* global object root; sfera_sub_004F9C00 @ lifted_functions_025.c:6684; source=0x04F4C708 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4C708_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C708))
/* global object root; sfera_sub_004F9C20 @ lifted_functions_025.c:6693; source=0x04F4C720 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4C720_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C720))
/* global object root; sfera_sub_004F9C50 @ lifted_functions_025.c:6715; source=0x04F4C780 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4C780_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C780))
/* global object root; sfera_sub_004F9C90 @ lifted_functions_025.c:6726; source=0x04F4C7F0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4C7F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C7F0))
/* global object root; sfera_sub_004F9CC0 @ lifted_functions_025.c:6748; source=0x04F4C850 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4C850_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C850))
/* global object root; sfera_sub_004F9D00 @ lifted_functions_025.c:6759; source=0x04F4C8D8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4C8D8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C8D8))
/* global object root; sfera_sub_004F9D30 @ lifted_functions_025.c:6781; source=0x04F4C938 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4C938_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C938))
/* global object root; sfera_sub_004F9D70 @ lifted_functions_025.c:6792; source=0x04F4C9A8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4C9A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C9A8))
/* global object root; sfera_sub_004F9DA0 @ lifted_functions_025.c:6814; source=0x04F4CA08 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4CA08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CA08))
/* global object root; sfera_sub_004F9DE0 @ lifted_functions_025.c:6825; source=0x04F4CA78 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4CA78_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CA78))
/* global object root; sfera_sub_004F9E10 @ lifted_functions_025.c:6847; source=0x04F4CAD8 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4CAD8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CAD8))
/* global object root; sfera_sub_004F9E50 @ lifted_functions_025.c:6858; source=0x04F4CB50 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4CB50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CB50))
/* global object root; sfera_sub_004F9E80 @ lifted_functions_025.c:6880; source=0x04F4CBB0 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4CBB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CBB0))
/* global object root; sfera_sub_004F9EC0 @ lifted_functions_025.c:6891; source=0x04F4CC28 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4CC28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CC28))
/* global object root; sfera_sub_004F9EF0 @ lifted_functions_025.c:6913; source=0x04F4CC88 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4CC88_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CC88))
/* call argument root; sfera_sub_004DC1D0 @ lifted_functions_022.c:7603; source=0x04F4CDE4 */
#define SFERA_DATA_CALL_ARGUMENT_04F4CDE4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CDE4))
/* global object root; sfera_sub_004F9F30 @ lifted_functions_025.c:6924; source=0x04F4CE20 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4CE20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CE20))
/* global object root; sfera_sub_004F9F60 @ lifted_functions_025.c:6946; source=0x04F4CE80 */
#define SFERA_DATA_GLOBAL_OBJECT_04F4CE80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CE80))
/* call argument root; sfera_sub_004EEE61 @ lifted_functions_024.c:5124; source=0x04F90418 */
#define SFERA_DATA_CALL_ARGUMENT_04F90418_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90418))
/* call argument root; sfera_sub_004EEE61 @ lifted_functions_024.c:5124; source=0x04F9041C */
#define SFERA_DATA_CALL_ARGUMENT_04F9041C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F9041C))
/* call argument root; sfera_sub_004EEE61 @ lifted_functions_024.c:5124; source=0x04F90420 */
#define SFERA_DATA_CALL_ARGUMENT_04F90420_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90420))
/* global object root; sfera_sub_004FC15A @ lifted_functions_025.c:10330; source=0x04F90770 */
#define SFERA_DATA_GLOBAL_OBJECT_04F90770_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90770))
/* global object root; sfera_sub_004EF142 @ lifted_functions_024.c:5246; source=0x04F90778 */
#define SFERA_DATA_GLOBAL_OBJECT_04F90778_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90778))

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
#define SFERA_STATIC_00663F88_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00663F88))
#define SFERA_STATIC_00663F88_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00663F88)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_00663FB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00663FB0))

/* data refs=2 u32=2 */
#define SFERA_STATIC_00663FC4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00663FC4))

/* data refs=18 addr=1 u32=17 */
#define SFERA_STATIC_006BE110_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE110))
#define SFERA_STATIC_006BE110_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE110)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_006BE114_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE114)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_006BE118_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE118))
#define SFERA_STATIC_006BE118_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE118)))

/* data refs=9 addr=9 */
#define SFERA_STATIC_006BE134_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE134))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_006BE14C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE14C))
#define SFERA_STATIC_006BE14C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE14C)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_006BE158_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE158))
#define SFERA_STATIC_006BE158_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE158)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_006BE15C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE15C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_006BE1B4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1B4)))

/* data refs=4 u8=4 */
#define SFERA_STATIC_006BE1B8_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1B8)))

/* data refs=3 u8=3 */
#define SFERA_STATIC_006BE1B9_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1B9)))

/* data refs=4 u8=4 */
#define SFERA_STATIC_006BE1BA_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1BA)))

/* data refs=7 addr=1 u32=6 */
#define SFERA_STATIC_006BE1BC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1BC))
#define SFERA_STATIC_006BE1BC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1BC)))

/* data refs=7 addr=1 u32=6 */
#define SFERA_STATIC_006BE1C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1C0))
#define SFERA_STATIC_006BE1C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1C0)))

/* data refs=4 u32=8 */
#define SFERA_STATIC_006BE1C4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1C4))
#define SFERA_STATIC_006BE1C4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1C4)))

/* data refs=4 u32=8 */
#define SFERA_STATIC_006BE1C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1C8))
#define SFERA_STATIC_006BE1C8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1C8)))

/* data refs=4 u32=8 */
#define SFERA_STATIC_006BE1CC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1CC))
#define SFERA_STATIC_006BE1CC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1CC)))

/* data refs=2 u32=4 */
#define SFERA_STATIC_006BE1D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1D0))
#define SFERA_STATIC_006BE1D0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1D0)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_006BE1D4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1D4)))

/* data refs=2 u32=4 */
#define SFERA_STATIC_006BE1D8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1D8))
#define SFERA_STATIC_006BE1D8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1D8)))

/* data refs=2 u32=4 */
#define SFERA_STATIC_006BE1DC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1DC))
#define SFERA_STATIC_006BE1DC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1DC)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_006BE1E0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1E0)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_006BE1E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1E8))
#define SFERA_STATIC_006BE1E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1E8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_006BE2B8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE2B8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_006BE2BC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE2BC)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_006BE2C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE2C0)))

/* data refs=5 u32=5 */


/* data refs=147 u32=163 */


/* data refs=2 u32=2 */
#define SFERA_STATIC_006BE408_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE408)))


/* data refs=6 addr=1 u32=3 u8=2 */
#define SFERA_STATIC_006BEC00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BEC00))
#define SFERA_STATIC_006BEC00_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BEC00)))

/* data refs=20 u32=19 */
#define SFERA_STATIC_00916E40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00916E40)))

/* data refs=8 addr=2 u8=6 */

/* data refs=2 u16=2 */

/* data refs=128 u32=162 */

/* data refs=9 addr=8 u8=1 */
#define SFERA_STATIC_00917570_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00917570))

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
#define SFERA_STATIC_04007638_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04007638))
#define SFERA_STATIC_04007638_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04007638)))


/* data refs=6 u32=6 */

/* data refs=8 u32=8 */


/* data refs=2 u32=2 */
#define SFERA_STATIC_04016618_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04016618)))

/* data refs=65 u32=71 */

/* data refs=8 u32=8 */

/* data refs=8 u32=8 */
#define SFERA_STATIC_04016680_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04016680)))

/* data refs=27 u32=27 */
#define SFERA_STATIC_04016684_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04016684)))


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
#define SFERA_STATIC_048F5A98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F5A98))
#define SFERA_STATIC_048F5A98_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x048F5A98)))

/* data refs=254 u32=286 */


/* data refs=8 u32=8 */


/* data refs=6 u32=6 */
#define SFERA_STATIC_04905B5C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04905B5C)))


/* data refs=104 u32=104 */


/* data refs=455 addr=1 u32=454 */


/* data refs=12 u32=12 */

/* data refs=413 u32=413 */


/* data refs=3 u32=5 */
#define SFERA_STATIC_04DBC430_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC430))
#define SFERA_STATIC_04DBC430_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC430)))

/* data refs=45 u32=45 */
#define SFERA_STATIC_04DBC434_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC434)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04DBC438_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC438)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04DBC43C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC43C)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04DBC440_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC440)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DBC444_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC444)))

/* data refs=16 u32=16 */
#define SFERA_STATIC_04DBC458_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC458)))


/* data refs=6 u32=6 */
#define SFERA_STATIC_04DBC470_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC470)))


/* data refs=2 u32=2 */
#define SFERA_STATIC_04DBC48C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC48C)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04DBC490_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC490))
#define SFERA_STATIC_04DBC490_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC490)))

/* data refs=2 addr=2 f32=1 */
#define SFERA_STATIC_04DBC4FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC4FC))

/* data refs=7 addr=7 */
#define SFERA_STATIC_04DBC508_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC508))

/* data refs=3 addr=2 f32=3 */
#define SFERA_STATIC_04DC051C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DC051C))
#define SFERA_STATIC_04DC051C_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DC051C)))

/* data refs=15 addr=15 */
#define SFERA_STATIC_04DC0580_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DC0580))

/* data refs=10 addr=10 */
#define SFERA_STATIC_04DC0680_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DC0680))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04DC0688_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DC0688)))

/* data refs=34 u32=42 u8=8 */
#define SFERA_STATIC_04DC068C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DC068C))
#define SFERA_STATIC_04DC068C_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DC068C)))
#define SFERA_STATIC_04DC068C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DC068C)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04DC0690_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DC0690))
#define SFERA_STATIC_04DC0690_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DC0690)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04DC069C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DC069C))
#define SFERA_STATIC_04DC069C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DC069C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DC06A8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DC06A8)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DC06AC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DC06AC)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DC06B0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DC06B0)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04DD0A20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0A20))
#define SFERA_STATIC_04DD0A20_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0A20)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD0AF8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0AF8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD0B24_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B24)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD0B50_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B50)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04DD0B80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0B80))
#define SFERA_STATIC_04DD0B80_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B80)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04DD0C50_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0C50)))

/* data refs=3 u32=5 */
#define SFERA_STATIC_04DD0C54_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0C54))
#define SFERA_STATIC_04DD0C54_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0C54)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD0C5C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0C5C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD0C60_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0C60)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DD0C64_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0C64)))

/* data refs=5 u8=5 */
#define SFERA_STATIC_04DD1068_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1068)))

/* data refs=3 u8=3 */
#define SFERA_STATIC_04DD1069_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1069)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD1070_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1070))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04DD1250_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1250))

/* data refs=4 addr=1 u32=3 */
#define SFERA_STATIC_04DD1254_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1254))
#define SFERA_STATIC_04DD1254_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1254)))

/* data refs=27 u32=41 */
#define SFERA_STATIC_04DD1258_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1258))
#define SFERA_STATIC_04DD1258_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1258)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04DD125C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD125C))
#define SFERA_STATIC_04DD125C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD125C)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04DD1270_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1270)))

/* data refs=3 addr=2 u32=1 */
#define SFERA_STATIC_04DD1274_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1274))
#define SFERA_STATIC_04DD1274_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1274)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD1288_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1288)))

/* data refs=9 u32=15 */
#define SFERA_STATIC_04DD128C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD128C))
#define SFERA_STATIC_04DD128C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD128C)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DD1290_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1290)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04DD1294_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1294))
#define SFERA_STATIC_04DD1294_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1294)))

/* data refs=15 u32=19 */
#define SFERA_STATIC_04DD1298_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1298))
#define SFERA_STATIC_04DD1298_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1298)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD129C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD129C)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04DD12A0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD12A0)))

/* data refs=13 u32=19 */
#define SFERA_STATIC_04DD12A4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD12A4))
#define SFERA_STATIC_04DD12A4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD12A4)))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04DD52A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD52A8))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04DD52C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD52C8))

/* data refs=9 addr=9 f32=9 */
#define SFERA_STATIC_04DD54A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD54A8))

/* data refs=4 u16=4 */
#define SFERA_STATIC_04DD54AC_U16 (*(uint16_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD54AC)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04DD57D0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57D0)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DD57DC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57DC)))

/* data refs=16 addr=11 f32=16 */
#define SFERA_STATIC_04DD57E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57E0))
#define SFERA_STATIC_04DD57E0_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57E0)))

/* data refs=20 u32=28 */
#define SFERA_STATIC_04DD57E4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57E4))
#define SFERA_STATIC_04DD57E4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57E4)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD57E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57E8)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD57EC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57EC)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD57F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57F0)))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04DD57F4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57F4))

/* data refs=17 addr=17 f32=17 */
#define SFERA_STATIC_04DD57F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57F8))

/* data refs=7 addr=1 u32=6 */
#define SFERA_STATIC_04DD57FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57FC))
#define SFERA_STATIC_04DD57FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57FC)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD5800_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5800)))

/* data refs=7 u32=5 u8=2 */
#define SFERA_STATIC_04DD5804_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5804)))
#define SFERA_STATIC_04DD5804_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5804)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD5808_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5808)))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04DD580C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD580C))

/* data refs=11 addr=2 f32=11 */
#define SFERA_STATIC_04DD5810_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5810))
#define SFERA_STATIC_04DD5810_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5810)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD5814_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5814)))

/* data refs=19 u32=19 */
#define SFERA_STATIC_04DD5818_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5818)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD581C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD581C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD5828_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5828)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD582C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD582C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD5830_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5830)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04DD5834_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5834)))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04DD5838_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5838))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04DD5839_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5839))

/* data refs=30 u32=30 */
#define SFERA_STATIC_04DD5A38_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5A38)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04DD7A40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7A40)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD7A48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7A48))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD7C28_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7C28)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD7C30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7C30)))

/* data refs=15 addr=15 f32=15 */
#define SFERA_STATIC_04DD7C34_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C34))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04DD7C38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C38))

/* data refs=4 u32=8 */
#define SFERA_STATIC_04DD7C3C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C3C))
#define SFERA_STATIC_04DD7C3C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7C3C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD7C40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7C40)))

/* data refs=14 u32=14 */
#define SFERA_STATIC_04DD7C4C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7C4C)))

/* data refs=7 addr=1 u32=6 */
#define SFERA_STATIC_04DD7C50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C50))
#define SFERA_STATIC_04DD7C50_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7C50)))

/* data refs=15 addr=1 u32=14 */
#define SFERA_STATIC_04DD7C54_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C54))
#define SFERA_STATIC_04DD7C54_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7C54)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD7C5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C5C))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DD7C60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C60))

/* data refs=2 addr=1 u8=1 */
#define SFERA_STATIC_04DD8108_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8108))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04DD8A2C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8A2C)))

/* data refs=16 addr=16 f32=16 */
#define SFERA_STATIC_04DD8A30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8A30))

/* data refs=5 addr=3 u32=2 */
#define SFERA_STATIC_04DD8A38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8A38))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04DD8B00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8B00))
#define SFERA_STATIC_04DD8B00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B00)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD8B10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B10)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD8B14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B14)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD8B18_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B18)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD8B1C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B1C)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04DD8B20_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B20)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD8B24_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B24)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DD8B28_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B28)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04DD8B30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8B30))

/* data refs=11 addr=11 f32=11 */
#define SFERA_STATIC_04DD8B34_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8B34))

/* data refs=6 addr=1 u32=5 */
#define SFERA_STATIC_04DD9170_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD9170))
#define SFERA_STATIC_04DD9170_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD9170)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD93B8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD93B8)))

/* data refs=16 u32=20 */
#define SFERA_STATIC_04DD93BC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD93BC))
#define SFERA_STATIC_04DD93BC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD93BC)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD93C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD93C0)))

/* data refs=17 u32=19 */
#define SFERA_STATIC_04DD93C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD93C8))
#define SFERA_STATIC_04DD93C8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD93C8)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04DD93D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD93D0))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04DD93D4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD93D4))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04DD93D8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD93D8))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04DD93DC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD93DC))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04DD93E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD93E0))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04DD93E4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD93E4))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04DD93F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD93F0))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04DDF7F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDF7F0))

/* data refs=12 u32=22 */
#define SFERA_STATIC_04DDF9E4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDF9E4))
#define SFERA_STATIC_04DDF9E4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDF9E4)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DDF9E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDF9E8)))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04DDF9EC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDF9EC))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04DDF9F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDF9F0))

/* data refs=4 addr=3 f32=4 */
#define SFERA_STATIC_04DDF9F4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDF9F4))
#define SFERA_STATIC_04DDF9F4_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDF9F4)))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04DDF9F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDF9F8))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04DDF9FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDF9FC))

/* data refs=4 addr=3 f32=4 */
#define SFERA_STATIC_04DDFA00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDFA00))
#define SFERA_STATIC_04DDFA00_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDFA00)))

/* data refs=26 u32=26 */
#define SFERA_STATIC_04DDFA04_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDFA04)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DDFA08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDFA08)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DDFA0C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDFA0C)))

/* data refs=4 addr=1 u32=5 */
#define SFERA_STATIC_04DDFA10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDFA10))
#define SFERA_STATIC_04DDFA10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDFA10)))

/* data refs=4 addr=2 f32=4 */
#define SFERA_STATIC_04DDFA14_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDFA14))
#define SFERA_STATIC_04DDFA14_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDFA14)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04DDFA18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDFA18))

/* data refs=19 addr=19 f32=19 */
#define SFERA_STATIC_04DDFE18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDFE18))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DDFE1C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDFE1C)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04DDFE28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDFE28))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04DE04B8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DE04B8)))

/* data refs=13 u32=13 */
#define SFERA_STATIC_04DE04BC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DE04BC)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04DE04C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DE04C0))
#define SFERA_STATIC_04DE04C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DE04C0)))

/* data refs=10 addr=9 u32=1 */
#define SFERA_STATIC_04DE0538_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DE0538))

/* data refs=3 addr=1 u8=2 */
#define SFERA_STATIC_04DE0550_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DE0550))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04DE1150_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DE1150))
#define SFERA_STATIC_04DE1150_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DE1150)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04DE1154_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DE1154)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04DE1158_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DE1158)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04DE1170_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DE1170))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E01170_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E01170)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E01174_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E01174)))

/* data refs=10 addr=7 u32=1 u8=2 */
#define SFERA_STATIC_04E0117C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E0117C))
#define SFERA_STATIC_04E0117C_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E0117C)))
#define SFERA_STATIC_04E0117C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E0117C)))

/* data refs=15 u32=15 */
#define SFERA_STATIC_04E01188_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E01188)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04E011A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E011A0))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04E01530_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E01530))

/* data refs=5 addr=3 u32=1 u8=1 */
#define SFERA_STATIC_04E01630_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E01630))
#define SFERA_STATIC_04E01630_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E01630)))
#define SFERA_STATIC_04E01630_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E01630)))

/* data refs=37 u32=59 */
#define SFERA_STATIC_04E01670_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E01670))
#define SFERA_STATIC_04E01670_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E01670)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E01674_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E01674)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04E01690_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E01690))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04E01694_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E01694))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04E1CF30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1CF30)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E1CF34_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1CF34)))

/* data refs=13 u32=13 */
#define SFERA_STATIC_04E1CF3C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1CF3C)))

/* data refs=13 u32=13 */
#define SFERA_STATIC_04E1CF44_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1CF44)))

/* data refs=2 addr=1 u8=1 */
#define SFERA_STATIC_04E1CF4C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1CF4C))

/* data refs=7 addr=2 u32=5 */
#define SFERA_STATIC_04E1CF50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1CF50))

/* data refs=6 addr=2 u32=4 */
#define SFERA_STATIC_04E1CF54_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1CF54))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04E1D268_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1D268))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04E1D270_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1D270))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04E1D274_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1D274))

/* data refs=19 addr=19 f32=19 */
#define SFERA_STATIC_04E1D66C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1D66C))

/* data refs=6 addr=6 */
#define SFERA_STATIC_04E1D670_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1D670))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E1DA5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DA5C))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04E1DC00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DC00)))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04E1DC04_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DC04))

/* data refs=3 u32=5 */
#define SFERA_STATIC_04E1DC08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DC08))
#define SFERA_STATIC_04E1DC08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DC08)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E1DC0C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DC0C)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04E1DD14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DD14)))

/* data refs=6 u32=10 */
#define SFERA_STATIC_04E1DD20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DD20))
#define SFERA_STATIC_04E1DD20_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DD20)))

/* data refs=26 u32=26 */
#define SFERA_STATIC_04E1DD24_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DD24)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04E1DD30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DD30))
#define SFERA_STATIC_04E1DD30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DD30)))

/* data refs=4 u32=8 */
#define SFERA_STATIC_04E1DD34_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DD34))
#define SFERA_STATIC_04E1DD34_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DD34)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04E1DE00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DE00))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04E1DE14_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DE14))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E1DE1C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DE1C)))

/* data refs=3 addr=2 u8=1 */
#define SFERA_STATIC_04E1DE20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DE20))
#define SFERA_STATIC_04E1DE20_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DE20)))

/* data refs=18 addr=1 u32=17 */
#define SFERA_STATIC_04E1DEA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DEA0))
#define SFERA_STATIC_04E1DEA0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DEA0)))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04E1DEA4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DEA4))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04E2BFA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2BFA8)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04E2C0B0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C0B0)))

/* data refs=2 u32=4 */
#define SFERA_STATIC_04E2C0B4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C0B4))
#define SFERA_STATIC_04E2C0B4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C0B4)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04E2C0B8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C0B8))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04E2C130_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C130)))

/* data refs=19 addr=19 f32=19 */
#define SFERA_STATIC_04E2C134_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C134))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04E2C138_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C138)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E2C13C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C13C)))

/* data refs=7 u32=9 */
#define SFERA_STATIC_04E2C140_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C140))
#define SFERA_STATIC_04E2C140_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C140)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04E2C144_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C144)))

/* data refs=23 u32=23 */
#define SFERA_STATIC_04E2C550_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C550)))

/* data refs=16 u32=16 */
#define SFERA_STATIC_04E2C898_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C898)))

/* data refs=4 addr=2 u8=2 */
#define SFERA_STATIC_04E2C89C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C89C))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E2C8BC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C8BC)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E2C8C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C8C0)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04E2C8C4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C8C4)))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04E2C8D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C8D0))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04E2C8D4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C8D4))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E2C8D8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C8D8)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04E2C8DC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C8DC)))

/* data refs=18 addr=18 f32=1 */
#define SFERA_STATIC_04E2C8E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C8E0))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04E2C940_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C940)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E2C944_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C944)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E2C948_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C948)))

/* data refs=21 addr=6 f32=6 u32=15 */
#define SFERA_STATIC_04E2C950_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C950))
#define SFERA_STATIC_04E2C950_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C950)))

/* data refs=16 addr=10 f32=16 */
#define SFERA_STATIC_04E2C954_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C954))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04E2C9A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C9A0))

/* data refs=16 addr=10 f32=16 */
#define SFERA_STATIC_04E2C9A4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C9A4))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04E2C9F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C9F0))

/* data refs=16 addr=10 f32=16 */
#define SFERA_STATIC_04E2C9F4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C9F4))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E2CA44_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2CA44)))

/* data refs=6 addr=4 u16=2 */
#define SFERA_STATIC_04E2CA48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2CA48))

/* data refs=2 u16=2 */
#define SFERA_STATIC_04E2CA4A_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2CA4A))

/* data refs=2 u16=2 */
#define SFERA_STATIC_04E2CA4C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2CA4C))

/* data refs=2 u16=2 */
#define SFERA_STATIC_04E2CA4E_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2CA4E))

/* data refs=2 u16=2 */
#define SFERA_STATIC_04E2CA50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2CA50))

/* data refs=2 u16=2 */
#define SFERA_STATIC_04E2CA52_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2CA52))

/* data refs=22 addr=22 */
#define SFERA_STATIC_04E2D858_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2D858))

/* data refs=9 addr=8 u32=1 */
#define SFERA_STATIC_04E2DC44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DC44))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E2DC5C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2DC5C)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04E2DC60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DC60))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04E2DE08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DE08))

/* data refs=19 u32=19 */
#define SFERA_STATIC_04E2DE10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2DE10)))

/* data refs=6 addr=3 u16=3 */
#define SFERA_STATIC_04E2DE18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DE18))

/* data refs=3 u16=3 */
#define SFERA_STATIC_04E2DE1A_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DE1A))

/* data refs=3 u16=3 */
#define SFERA_STATIC_04E2DE1C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DE1C))

/* data refs=13 u32=13 */
#define SFERA_STATIC_04E2E2BC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2E2BC)))

/* data refs=18 addr=6 f32=6 u32=12 */
#define SFERA_STATIC_04E2E2C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2E2C0))
#define SFERA_STATIC_04E2E2C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2E2C0)))

/* data refs=14 addr=8 f32=14 */
#define SFERA_STATIC_04E2E2C4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2E2C4))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04E2E310_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2E310))

/* data refs=14 addr=8 f32=14 */
#define SFERA_STATIC_04E2E314_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2E314))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04E2E360_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2E360))

/* data refs=14 addr=8 f32=14 */
#define SFERA_STATIC_04E2E364_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2E364))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E2E3B4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2E3B4)))

/* data refs=3 u32=5 */
#define SFERA_STATIC_04E2E3B8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2E3B8))
#define SFERA_STATIC_04E2E3B8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2E3B8)))

/* data refs=10 addr=10 */
#define SFERA_STATIC_04E2E3C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2E3C0))

/* data refs=9 addr=1 u8=8 */
#define SFERA_STATIC_04E2E3D4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2E3D4))

/* data refs=8 u8=8 */
#define SFERA_STATIC_04E2E3D5_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2E3D5))

/* data refs=8 addr=5 u8=5 */
#define SFERA_STATIC_04E509C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E509C0))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04E509DD_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E509DD)))

/* data refs=5 u8=5 */
#define SFERA_STATIC_04E509EA_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E509EA)))

/* data refs=5 u8=5 */
#define SFERA_STATIC_04E509F6_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E509F6)))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04E509F8_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E509F8)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04E50AC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E50AC0))
#define SFERA_STATIC_04E50AC0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E50AC0)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E50AC4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E50AC4)))

/* data refs=11 u32=13 */
#define SFERA_STATIC_04E50ACC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E50ACC))
#define SFERA_STATIC_04E50ACC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E50ACC)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04E50AD0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E50AD0))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E51480_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E51480))

/* data refs=34 u32=34 */
#define SFERA_STATIC_04E51ED0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E51ED0)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E51ED4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E51ED4)))

/* data refs=20 addr=10 u32=1 u8=9 */
#define SFERA_STATIC_04E51ED8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E51ED8))
#define SFERA_STATIC_04E51ED8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E51ED8)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04E51F0C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E51F0C))
#define SFERA_STATIC_04E51F0C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E51F0C)))

/* data refs=31 addr=2 u32=29 */
#define SFERA_STATIC_04E51F10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E51F10))
#define SFERA_STATIC_04E51F10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E51F10)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E51F50_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E51F50)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04E5215C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E5215C)))

/* data refs=18 u32=18 */
#define SFERA_STATIC_04E522F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E522F0)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E522F4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E522F4)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E522FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E522FC)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E52300_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E52300)))

/* data refs=21 u32=25 */
#define SFERA_STATIC_04E52304_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E52304))
#define SFERA_STATIC_04E52304_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E52304)))

/* data refs=4 addr=2 u16=4 */
#define SFERA_STATIC_04E52308_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E52308))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E72308_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E72308)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E72310_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E72310)))

/* data refs=21 addr=11 u16=5 u32=1 u8=4 */
#define SFERA_STATIC_04E72314_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E72314))
#define SFERA_STATIC_04E72314_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E72314)))
#define SFERA_STATIC_04E72314_U16 (*(uint16_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E72314)))
#define SFERA_STATIC_04E72314_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E72314)))

/* data refs=5 u8=5 */
#define SFERA_STATIC_04E72316_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E72316)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04E7231C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E7231C)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E72320_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E72320))

/* data refs=5 addr=5 f32=5 */
#define SFERA_STATIC_04E72324_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E72324))

/* data refs=5 addr=5 f32=5 */
#define SFERA_STATIC_04E72328_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E72328))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04E7232C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E7232C))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04E73320_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E73320)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E73324_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E73324))
#define SFERA_STATIC_04E73324_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E73324)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E769D8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E769D8)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E769DC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E769DC)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E769E0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E769E0)))

/* data refs=19 addr=19 f32=19 */
#define SFERA_STATIC_04E769E4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E769E4))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E769FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E769FC)))

/* data refs=4 u32=8 */
#define SFERA_STATIC_04E76A00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E76A00))
#define SFERA_STATIC_04E76A00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E76A00)))

/* data refs=8 u32=7 u8=1 */
#define SFERA_STATIC_04E76A04_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E76A04)))
#define SFERA_STATIC_04E76A04_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E76A04)))

/* data refs=30 u32=30 */
#define SFERA_STATIC_04E78A08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78A08)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04E78A10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78A10))
#define SFERA_STATIC_04E78A10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78A10)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04E78A18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78A18))
#define SFERA_STATIC_04E78A18_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78A18)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E78A90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78A90)))

/* data refs=2 u32=1 u8=1 */
#define SFERA_STATIC_04E78A94_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78A94)))
#define SFERA_STATIC_04E78A94_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78A94)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04E78A98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78A98))

/* data refs=2 addr=1 f32=2 */
#define SFERA_STATIC_04E78A9C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78A9C))
#define SFERA_STATIC_04E78A9C_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78A9C)))

/* data refs=2 addr=1 f32=2 */
#define SFERA_STATIC_04E78AA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78AA0))
#define SFERA_STATIC_04E78AA0_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78AA0)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04E78AA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78AA8))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04E78D64_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78D64))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04E78D68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78D68))

/* data refs=5 addr=3 f32=5 */
#define SFERA_STATIC_04E78D70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78D70))
#define SFERA_STATIC_04E78D70_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78D70)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E78D8C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78D8C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E78D90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78D90)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E78D94_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78D94)))

/* data refs=2 u16=1 u32=1 */
#define SFERA_STATIC_04E78D98_U16 (*(uint16_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78D98)))
#define SFERA_STATIC_04E78D98_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78D98)))

/* data refs=9 addr=8 f32=9 */
#define SFERA_STATIC_04E78DA4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78DA4))
#define SFERA_STATIC_04E78DA4_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78DA4)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04E78DA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78DA8))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E78F8C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78F8C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E78F90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78F90)))

/* data refs=6 addr=6 f32=5 */
#define SFERA_STATIC_04E78F98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78F98))

/* data refs=11 addr=11 f32=10 */
#define SFERA_STATIC_04E78F9C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78F9C))

/* data refs=15 addr=1 u32=14 */
#define SFERA_STATIC_04E78FA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78FA0))
#define SFERA_STATIC_04E78FA0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78FA0)))

/* data refs=2 u32=1 u8=1 */
#define SFERA_STATIC_04E78FA4_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78FA4)))
#define SFERA_STATIC_04E78FA4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78FA4)))

/* data refs=29 u32=29 */
#define SFERA_STATIC_04E78FA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78FA8)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04E78FAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78FAC))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E78FB0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78FB0)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E78FB4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78FB4)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E79234_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79234)))

/* data refs=18 u32=18 */
#define SFERA_STATIC_04E79238_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79238)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E79244_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79244)))

/* data refs=15 u32=15 */
#define SFERA_STATIC_04E79248_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79248)))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04E7924C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E7924C))

/* data refs=8 addr=8 */
#define SFERA_STATIC_04E79250_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79250))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04E79268_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79268))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E792E0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792E0)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04E792E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792E8)))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04E792EC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792EC)))

/* data refs=12 addr=1 u32=11 */
#define SFERA_STATIC_04E792F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E792F0))
#define SFERA_STATIC_04E792F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792F0)))

/* data refs=29 u32=29 */
#define SFERA_STATIC_04E792F4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792F4)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04E792FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792FC)))

/* data refs=11 u32=15 */
#define SFERA_STATIC_04E79300_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79300))
#define SFERA_STATIC_04E79300_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79300)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04E79304_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79304))
#define SFERA_STATIC_04E79304_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79304)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E7930C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E7930C)))

/* data refs=83 addr=44 u8=39 */
#define SFERA_STATIC_04E79310_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79310))
#define SFERA_STATIC_04E79310_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79310)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E79B14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79B14)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04E79B20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79B20))

/* data refs=4 u8=4 */
#define SFERA_STATIC_04EB9B28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9B28))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EB9C28_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9C28)))

/* data refs=5 addr=5 f32=5 */
#define SFERA_STATIC_04EB9C2C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9C2C))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EB9C30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9C30))

/* data refs=4 addr=4 */
#define SFERA_STATIC_04EB9C44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9C44))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EB9C58_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9C58)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EB9C5C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9C5C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EB9CC4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9CC4)))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04EB9CC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9CC8))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04EB9CCC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9CCC))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04EB9CD0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9CD0)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EB9CD4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9CD4)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EB9CD8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9CD8))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EB9CEC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9CEC)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04EB9CF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9CF0))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04EB9E80_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9E80)))

/* data refs=19 addr=19 f32=19 */
#define SFERA_STATIC_04EB9E84_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9E84))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EB9E8C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9E8C)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04EB9E90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9E90))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EB9E94_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9E94))

/* data refs=3 addr=1 u8=2 */
#define SFERA_STATIC_04EBA690_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EBA690))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04EBB294_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EBB294))

/* data refs=10 addr=2 u32=8 */
#define SFERA_STATIC_04EC4EE0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4EE0))
#define SFERA_STATIC_04EC4EE0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EE0)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EC4EE4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EE4)))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04EC4EE9_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EE9)))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04EC4EEA_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EEA)))

/* data refs=3 u8=3 */
#define SFERA_STATIC_04EC4EEB_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EEB)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EC4EEC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EEC)))

/* data refs=14 u32=16 */
#define SFERA_STATIC_04EC4EF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4EF0))
#define SFERA_STATIC_04EC4EF0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EF0)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04EC4EF4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EF4)))

/* data refs=23 u32=23 */
#define SFERA_STATIC_04EC4EF8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EF8)))

/* data refs=11 u32=13 */
#define SFERA_STATIC_04EC4EFC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4EFC))
#define SFERA_STATIC_04EC4EFC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EFC)))

/* data refs=29 u32=43 */
#define SFERA_STATIC_04EC4F00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F00))
#define SFERA_STATIC_04EC4F00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F00)))

/* data refs=14 addr=1 u32=13 */
#define SFERA_STATIC_04EC4F04_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F04))
#define SFERA_STATIC_04EC4F04_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F04)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EC4F08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F08)))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04EC4F0C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F0C))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EC4F10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F10)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EC4F14_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F14))
#define SFERA_STATIC_04EC4F14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F14)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EC4F18_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F18)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EC4F24_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F24)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EC4F30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F30)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EC4F40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F40)))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04EC4F48_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F48)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04EC4F4C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F4C)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EC4F50_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F50)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EC4F54_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F54)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EC4F58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F58))
#define SFERA_STATIC_04EC4F58_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F58)))

/* data refs=16 u8=16 */
#define SFERA_STATIC_04EC4F61_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F61)))

/* data refs=3 u8=3 */
#define SFERA_STATIC_04EC4F62_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F62)))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04EC4F64_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F64)))

/* data refs=9 addr=1 u32=8 */
#define SFERA_STATIC_04EC4F6C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F6C))
#define SFERA_STATIC_04EC4F6C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F6C)))

/* data refs=8 addr=1 u32=7 */
#define SFERA_STATIC_04EC4F70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F70))
#define SFERA_STATIC_04EC4F70_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F70)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04EC4F74_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F74)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EC4F80_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F80)))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04EC4F84_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F84)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EC4FB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4FB0))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EC4FBC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4FBC)))

/* data refs=2 addr=2 f32=1 */
#define SFERA_STATIC_04EC4FF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4FF0))

/* data refs=3 addr=3 f32=2 */
#define SFERA_STATIC_04EC4FF4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4FF4))

/* data refs=2 addr=2 f32=1 */
#define SFERA_STATIC_04EC4FF8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4FF8))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04ECBA38_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ECBA38)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04ECBA3C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ECBA3C)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04ECBA40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ECBA40)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ECBA44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ECBA44))

/* data refs=2 addr=1 f32=2 */
#define SFERA_STATIC_04ECBA48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ECBA48))
#define SFERA_STATIC_04ECBA48_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ECBA48)))

/* data refs=2 addr=1 f32=2 */
#define SFERA_STATIC_04ECBA4C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ECBA4C))
#define SFERA_STATIC_04ECBA4C_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ECBA4C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED0D70_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0D70)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04ED0DA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0DA8))
#define SFERA_STATIC_04ED0DA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0DA8)))


/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED0EB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0EB8))
#define SFERA_STATIC_04ED0EB8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EB8)))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED0EBC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0EBC))
#define SFERA_STATIC_04ED0EBC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EBC)))


/* data refs=2 addr=2 */
#define SFERA_STATIC_04ED1080_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1080))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04ED10E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED10E0))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED10EC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED10EC))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED10FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED10FC))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED110C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED110C))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04ED1120_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1120)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04ED1158_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1158)))


/* data refs=11 u32=11 */
#define SFERA_STATIC_04ED11E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED11E8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED1220_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1220)))


/* data refs=14 addr=14 f32=1 */
#define SFERA_STATIC_04ED12B0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED12B0))


/* data refs=3 addr=3 */
#define SFERA_STATIC_04ED132C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED132C))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04ED1358_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1358))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED1A30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A30)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED1A68_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A68)))

/* data refs=3 addr=3 */


/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2A50_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A50)))


/* data refs=3 addr=1 f32=2 u32=1 */
#define SFERA_STATIC_04ED2B00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2B00))
#define SFERA_STATIC_04ED2B00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2B00)))
#define SFERA_STATIC_04ED2B00_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2B00)))

/* data refs=3 addr=1 f32=2 u32=1 */
#define SFERA_STATIC_04ED2B04_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2B04))
#define SFERA_STATIC_04ED2B04_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2B04)))
#define SFERA_STATIC_04ED2B04_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2B04)))

/* data refs=3 addr=1 f32=2 u32=1 */
#define SFERA_STATIC_04ED2B08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2B08))
#define SFERA_STATIC_04ED2B08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2B08)))
#define SFERA_STATIC_04ED2B08_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2B08)))


/* data refs=2 addr=2 f32=1 */
#define SFERA_STATIC_04ED2B38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2B38))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2BA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BA8)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04ED2BE0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2BE0))
#define SFERA_STATIC_04ED2BE0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BE0)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2BE4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BE4)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2BE8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BE8)))


/* data refs=4 addr=4 f32=2 */
#define SFERA_STATIC_04ED2C70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C70))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED2C74_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C74))
#define SFERA_STATIC_04ED2C74_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C74)))

/* data refs=4 addr=3 f32=3 u32=1 */
#define SFERA_STATIC_04ED2C78_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C78))
#define SFERA_STATIC_04ED2C78_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C78)))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04ED2C7C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C7C))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04ED2C80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C80))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04ED2C84_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C84))

/* data refs=6 addr=3 f32=6 */
#define SFERA_STATIC_04ED2C88_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C88))
#define SFERA_STATIC_04ED2C88_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C88)))

/* data refs=6 addr=3 f32=6 */
#define SFERA_STATIC_04ED2C8C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C8C))
#define SFERA_STATIC_04ED2C8C_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C8C)))

/* data refs=6 addr=3 f32=6 */
#define SFERA_STATIC_04ED2C90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C90))
#define SFERA_STATIC_04ED2C90_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C90)))

/* data refs=18 addr=5 f32=6 u32=12 */
#define SFERA_STATIC_04ED2C94_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C94))
#define SFERA_STATIC_04ED2C94_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C94)))
#define SFERA_STATIC_04ED2C94_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C94)))

/* data refs=18 addr=5 f32=6 u32=12 */
#define SFERA_STATIC_04ED2C98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C98))
#define SFERA_STATIC_04ED2C98_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C98)))
#define SFERA_STATIC_04ED2C98_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C98)))

/* data refs=18 addr=4 f32=6 u32=12 */
#define SFERA_STATIC_04ED2C9C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C9C))
#define SFERA_STATIC_04ED2C9C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C9C)))
#define SFERA_STATIC_04ED2C9C_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C9C)))

/* data refs=12 u8=12 */
#define SFERA_STATIC_04ED2CA0_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2CA0)))

/* data refs=16 addr=12 f32=11 u32=3 */
#define SFERA_STATIC_04ED2CA4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2CA4))
#define SFERA_STATIC_04ED2CA4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2CA4)))
#define SFERA_STATIC_04ED2CA4_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2CA4)))

/* data refs=20 addr=16 f32=17 u32=3 */
#define SFERA_STATIC_04ED2CA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2CA8))
#define SFERA_STATIC_04ED2CA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2CA8)))
#define SFERA_STATIC_04ED2CA8_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2CA8)))

/* data refs=14 addr=9 f32=10 u32=3 */
#define SFERA_STATIC_04ED2CAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2CAC))
#define SFERA_STATIC_04ED2CAC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2CAC)))
#define SFERA_STATIC_04ED2CAC_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2CAC)))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04ED2CB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2CB0))

/* data refs=7 addr=6 f32=6 u32=1 */
#define SFERA_STATIC_04ED2CB4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2CB4))
#define SFERA_STATIC_04ED2CB4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2CB4)))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04ED2CB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2CB8))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2D28_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D28)))

/* data refs=14 addr=5 f32=6 u32=8 */
#define SFERA_STATIC_04ED2D60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2D60))
#define SFERA_STATIC_04ED2D60_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D60)))
#define SFERA_STATIC_04ED2D60_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D60)))

/* data refs=12 addr=3 f32=4 u32=8 */
#define SFERA_STATIC_04ED2D64_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2D64))
#define SFERA_STATIC_04ED2D64_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D64)))
#define SFERA_STATIC_04ED2D64_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D64)))

/* data refs=14 addr=5 f32=6 u32=8 */
#define SFERA_STATIC_04ED2D68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2D68))
#define SFERA_STATIC_04ED2D68_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D68)))
#define SFERA_STATIC_04ED2D68_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D68)))

/* data refs=7 addr=2 f32=4 u32=3 */
#define SFERA_STATIC_04ED2D6C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2D6C))
#define SFERA_STATIC_04ED2D6C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D6C)))
#define SFERA_STATIC_04ED2D6C_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D6C)))

/* data refs=13 addr=10 f32=10 u32=3 */
#define SFERA_STATIC_04ED2D70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2D70))
#define SFERA_STATIC_04ED2D70_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D70)))

/* data refs=7 addr=4 f32=4 u32=3 */
#define SFERA_STATIC_04ED2D74_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2D74))
#define SFERA_STATIC_04ED2D74_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D74)))

/* data refs=2 addr=2 f32=1 */
#define SFERA_STATIC_04ED2D78_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2D78))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2DB8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2DB8)))


/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2E10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E10)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2E14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E14)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2E18_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E18)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2E1C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E1C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2E20_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E20)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2E24_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E24)))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED2E28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E28))
#define SFERA_STATIC_04ED2E28_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E28)))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED2E2C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E2C))
#define SFERA_STATIC_04ED2E2C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E2C)))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED2E30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E30))
#define SFERA_STATIC_04ED2E30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E30)))


/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED2EB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2EB8))
#define SFERA_STATIC_04ED2EB8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EB8)))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED2EBC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2EBC))
#define SFERA_STATIC_04ED2EBC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EBC)))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED2EC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2EC0))
#define SFERA_STATIC_04ED2EC0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EC0)))


/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2EF0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EF0)))


/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED3038_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3038)))


/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED30C8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED30C8)))


/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED312C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED312C))
#define SFERA_STATIC_04ED312C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED312C)))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED3130_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3130))
#define SFERA_STATIC_04ED3130_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3130)))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED3134_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3134))
#define SFERA_STATIC_04ED3134_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3134)))

/* data refs=12 addr=11 u32=1 */
#define SFERA_STATIC_04ED3138_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3138))
#define SFERA_STATIC_04ED3138_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3138)))

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
#define SFERA_STATIC_04EDCCCC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCCCC)))

/* data refs=18 addr=18 */
#define SFERA_STATIC_04EDCCF8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCCF8))


/* data refs=6 addr=6 */
#define SFERA_STATIC_04EDCD70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD70))

/* data refs=16 u32=16 */
#define SFERA_STATIC_04EDCD74_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD74)))

/* data refs=4 addr=3 f32=2 u32=1 */
#define SFERA_STATIC_04EDCD80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD80))
#define SFERA_STATIC_04EDCD80_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD80)))

/* data refs=3 addr=2 f32=2 u32=1 */
#define SFERA_STATIC_04EDCD84_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD84))
#define SFERA_STATIC_04EDCD84_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD84)))

/* data refs=3 addr=2 f32=2 u32=1 */
#define SFERA_STATIC_04EDCD88_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD88))
#define SFERA_STATIC_04EDCD88_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD88)))

/* data refs=3 addr=2 f32=2 u32=1 */
#define SFERA_STATIC_04EDCD8C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD8C))
#define SFERA_STATIC_04EDCD8C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD8C)))

/* data refs=3 addr=2 f32=2 u32=1 */
#define SFERA_STATIC_04EDCD90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD90))
#define SFERA_STATIC_04EDCD90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD90)))

/* data refs=3 addr=2 f32=2 u32=1 */
#define SFERA_STATIC_04EDCD94_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD94))
#define SFERA_STATIC_04EDCD94_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD94)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDCD98_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD98)))


/* data refs=6 addr=6 */
#define SFERA_STATIC_04EDCF00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCF00))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDCF40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCF40)))


/* data refs=2 addr=2 */
#define SFERA_STATIC_04EDCFD0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCFD0))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04EDD030_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD030)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EDD068_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD068)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EDD06C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD06C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EDD070_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD070)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04EDD074_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD074))

/* data refs=4 u32=6 */
#define SFERA_STATIC_04EDD078_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD078))
#define SFERA_STATIC_04EDD078_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD078)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD080_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD080)))

/* data refs=4 u32=6 */
#define SFERA_STATIC_04EDD088_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD088))
#define SFERA_STATIC_04EDD088_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD088)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD090_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD090)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD0A0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0A0)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EDD0A4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0A4)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EDD0A8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0A8)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EDD0AC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0AC))

/* data refs=5 u32=6 u8=1 */
#define SFERA_STATIC_04EDD0C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0C8))
#define SFERA_STATIC_04EDD0C8_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0C8)))
#define SFERA_STATIC_04EDD0C8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0C8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD0CC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0CC)))

/* data refs=32 addr=24 u32=8 */
#define SFERA_STATIC_04EDD0D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0D0))
#define SFERA_STATIC_04EDD0D0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0D0)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EDD0D4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0D4)))

/* data refs=8 u16=2 u32=6 */
#define SFERA_STATIC_04EDD0D8_U16 (*(uint16_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0D8)))
#define SFERA_STATIC_04EDD0D8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0D8)))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04EDD0DA_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0DA)))

/* data refs=6 u16=6 */
#define SFERA_STATIC_04EDD0DC_U16 (*(uint16_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0DC)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04EDD1D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD1D0))

/* data refs=4 addr=2 f32=4 */
#define SFERA_STATIC_04EDD270_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD270))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04EDD274_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD274))

/* data refs=2 addr=1 f32=2 */
#define SFERA_STATIC_04EDD294_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD294))
#define SFERA_STATIC_04EDD294_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD294)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EDD2A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD2A8))

/* data refs=4 addr=2 f32=4 */
#define SFERA_STATIC_04EDD308_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD308))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04EDD30C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD30C))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04EDD31C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD31C))

/* data refs=15 addr=15 f32=15 */
#define SFERA_STATIC_04EDD348_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD348))

/* data refs=10 addr=9 f32=10 */
#define SFERA_STATIC_04EDD34C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD34C))
#define SFERA_STATIC_04EDD34C_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD34C)))

/* data refs=11 addr=11 f32=11 */
#define SFERA_STATIC_04EDD350_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD350))

/* data refs=11 addr=11 f32=11 */
#define SFERA_STATIC_04EDD354_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD354))

/* data refs=10 addr=10 f32=10 */
#define SFERA_STATIC_04EDD358_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD358))

/* data refs=2 f32=1 u32=1 */
#define SFERA_STATIC_04EDD35C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD35C)))
#define SFERA_STATIC_04EDD35C_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD35C)))

/* data refs=2 f32=1 u32=1 */
#define SFERA_STATIC_04EDD360_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD360)))
#define SFERA_STATIC_04EDD360_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD360)))

/* data refs=2 f32=1 u32=1 */
#define SFERA_STATIC_04EDD364_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD364)))
#define SFERA_STATIC_04EDD364_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD364)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EDD368_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD368))
#define SFERA_STATIC_04EDD368_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD368)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EDD374_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD374))
#define SFERA_STATIC_04EDD374_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD374)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EDD380_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD380)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD384_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD384)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD388_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD388)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EDD38C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD38C))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04EDD398_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD398))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD460_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD460)))

/* data refs=4 addr=3 u8=1 */
#define SFERA_STATIC_04EDD464_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD464))

/* data refs=8 addr=8 */
#define SFERA_STATIC_04EDD490_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD490))

/* data refs=16 u32=16 */
#define SFERA_STATIC_04EDD510_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD510))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04EDD590_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD590)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EDD598_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD598))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EDED08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDED08))

/* data refs=3 u32=5 */
#define SFERA_STATIC_04EE0478_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE0478))
#define SFERA_STATIC_04EE0478_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EE0478)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EE047C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE047C))

/* data refs=5 u32=6 u8=1 */
#define SFERA_STATIC_04EE0498_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE0498))
#define SFERA_STATIC_04EE0498_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EE0498)))
#define SFERA_STATIC_04EE0498_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EE0498)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EE04A0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EE04A0)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EE04A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE04A8))
#define SFERA_STATIC_04EE04A8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EE04A8)))

/* data refs=5 addr=3 u32=2 */
#define SFERA_STATIC_04EE0578_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE0578))

/* data refs=5 addr=3 u32=2 */
#define SFERA_STATIC_04EE0AA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE0AA8))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04EE1104_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE1104))

/* data refs=10 addr=9 u8=1 */
#define SFERA_STATIC_04EE1124_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE1124))
#define SFERA_STATIC_04EE1124_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EE1124)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04EE1148_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE1148))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EE2148_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE2148))

/* data refs=5 addr=2 u32=3 */
#define SFERA_STATIC_04EE4150_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE4150))

/* data refs=9 addr=6 u8=3 */
#define SFERA_STATIC_04EE6158_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE6158))
#define SFERA_STATIC_04EE6158_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EE6158)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04EE7158_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE7158))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EE8158_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EE8158)))

/* data refs=3 u8=3 */
#define SFERA_STATIC_04EE8160_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE8160))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04EE8260_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE8260))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EE8360_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE8360))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EE8560_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE8560))
#define SFERA_STATIC_04EE8560_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EE8560)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EE8630_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE8630))
#define SFERA_STATIC_04EE8630_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EE8630)))

/* data refs=16 u32=16 */
#define SFERA_STATIC_04EEA008_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA008)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEA010_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA010))
#define SFERA_STATIC_04EEA010_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA010)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04EEA0E0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA0E0)))

/* data refs=3 u8=3 */
#define SFERA_STATIC_04EEA0E4_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA0E4)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EEA0E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA0E8))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EEA128_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA128)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EEA12C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA12C)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EEA130_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA130)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EEA134_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA134)))

/* data refs=6 addr=6 */
#define SFERA_STATIC_04EEA138_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA138))

/* data refs=3 addr=2 u32=1 */
#define SFERA_STATIC_04EEA150_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA150))
#define SFERA_STATIC_04EEA150_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA150)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EEA330_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA330)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEA820_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA820))
#define SFERA_STATIC_04EEA820_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA820)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEA8F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA8F0))
#define SFERA_STATIC_04EEA8F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA8F0)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEA9C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA9C0))
#define SFERA_STATIC_04EEA9C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA9C0)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEAA90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAA90))
#define SFERA_STATIC_04EEAA90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAA90)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEAB60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAB60))
#define SFERA_STATIC_04EEAB60_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAB60)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEAC30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAC30))
#define SFERA_STATIC_04EEAC30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAC30)))

/* data refs=15 u32=15 */
#define SFERA_STATIC_04EEAD00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAD00)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04EEAD04_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAD04)))

/* data refs=17 u32=17 */
#define SFERA_STATIC_04EEAD08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAD08)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EEAD0C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAD0C)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEAD10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAD10))
#define SFERA_STATIC_04EEAD10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAD10)))

/* data refs=3 addr=2 u8=1 */
#define SFERA_STATIC_04EEADE0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEADE0))
#define SFERA_STATIC_04EEADE0_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEADE0)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEAEE0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAEE0))
#define SFERA_STATIC_04EEAEE0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAEE0)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEAFB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAFB0))
#define SFERA_STATIC_04EEAFB0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAFB0)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EEB080_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB080)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEB088_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB088))
#define SFERA_STATIC_04EEB088_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB088)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04EEB158_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB158)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEB160_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB160))
#define SFERA_STATIC_04EEB160_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB160)))

/* data refs=8 addr=4 u32=1 u8=3 */
#define SFERA_STATIC_04EEB230_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB230))
#define SFERA_STATIC_04EEB230_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB230)))
#define SFERA_STATIC_04EEB230_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB230)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04EEB430_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB430)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEB438_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB438))
#define SFERA_STATIC_04EEB438_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB438)))

/* data refs=12 addr=4 u32=8 */
#define SFERA_STATIC_04EEB508_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB508))
#define SFERA_STATIC_04EEB508_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB508)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04EEB50C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB50C)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEB510_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB510))
#define SFERA_STATIC_04EEB510_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB510)))

/* data refs=18 u32=22 */
#define SFERA_STATIC_04EEB5E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB5E0))
#define SFERA_STATIC_04EEB5E0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB5E0)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EEB5E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB5E8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EEB5EC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB5EC)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EEB5F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB5F0)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04EEB5F8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB5F8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EEB5FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB5FC)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EEB600_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB600)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EEB604_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB604)))

/* data refs=4 addr=1 u16=3 */
#define SFERA_STATIC_04EEB610_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB610))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04F0B610_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F0B610))

/* data refs=2 u32=4 */
#define SFERA_STATIC_04F17960_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F17960))
#define SFERA_STATIC_04F17960_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F17960)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F17964_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F17964)))

/* data refs=4 u16=4 */
#define SFERA_STATIC_04F17968_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F17968))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04F37968_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37968)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F3796C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3796C)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04F37970_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37970)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F379E0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F379E0)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F379E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F379E8))
#define SFERA_STATIC_04F379E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F379E8)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F37AB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37AB8))
#define SFERA_STATIC_04F37AB8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37AB8)))

/* data refs=7 addr=1 u32=5 u64=1 */
#define SFERA_STATIC_04F37B88_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37B88))
#define SFERA_STATIC_04F37B88_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37B88)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F37B8C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37B8C))
#define SFERA_STATIC_04F37B8C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37B8C)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F37EA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EA8)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F37EAC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EAC)))

/* data refs=3 u32=5 */
#define SFERA_STATIC_04F37EB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37EB0))
#define SFERA_STATIC_04F37EB0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EB0)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F37EB4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EB4)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F37EC0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EC0)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F37EC4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EC4)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F37EC8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EC8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F37ECC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37ECC)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F37ED0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37ED0)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F37ED4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37ED4)))

/* data refs=4 u8=4 */
#define SFERA_STATIC_04F37ED8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37ED8))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F37F3C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37F3C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F37F40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37F40))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F37F44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37F44))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F38260_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38260))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F383F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F383F0)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F383F8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F383F8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F383FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F383FC)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F38400_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38400))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F38800_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38800)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F38808_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38808))
#define SFERA_STATIC_04F38808_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38808)))

/* data refs=3 addr=2 u32=1 */
#define SFERA_STATIC_04F38818_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38818))
#define SFERA_STATIC_04F38818_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38818)))


/* data refs=5 addr=5 */
#define SFERA_STATIC_04F38910_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38910))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04F389D8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F389D8))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04F389DC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F389DC))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04F389E0_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F389E0)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04F389E4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F389E4)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F389E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F389E8))
#define SFERA_STATIC_04F389E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F389E8)))

/* data refs=20 addr=20 */
#define SFERA_STATIC_04F38AB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38AB8))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F38BB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38BB8))
#define SFERA_STATIC_04F38BB8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38BB8)))

/* data refs=14 addr=14 */
#define SFERA_STATIC_04F38C88_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38C88))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F38D88_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38D88))
#define SFERA_STATIC_04F38D88_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38D88)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F38E58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38E58))
#define SFERA_STATIC_04F38E58_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38E58)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F38F28_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38F28)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F38F30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38F30))
#define SFERA_STATIC_04F38F30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38F30)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F39000_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F39000))
#define SFERA_STATIC_04F39000_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F39000)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F390D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F390D0))
#define SFERA_STATIC_04F390D0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F390D0)))

/* data refs=3 addr=2 u16=1 */
#define SFERA_STATIC_04F391A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F391A0))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04F3A460_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A460)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04F3A464_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A464)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F3A468_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A468))
#define SFERA_STATIC_04F3A468_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A468)))

/* data refs=10 addr=1 u32=9 */
#define SFERA_STATIC_04F3A4D4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A4D4))
#define SFERA_STATIC_04F3A4D4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A4D4)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04F3A4D8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A4D8)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F3A548_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A548))
#define SFERA_STATIC_04F3A548_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A548)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04F3A618_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A618))

/* data refs=12 addr=9 u8=3 */
#define SFERA_STATIC_04F3A718_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A718))
#define SFERA_STATIC_04F3A718_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A718)))

/* data refs=5 addr=2 u8=3 */
#define SFERA_STATIC_04F3A818_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A818))
#define SFERA_STATIC_04F3A818_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A818)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F3A918_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A918))
#define SFERA_STATIC_04F3A918_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A918)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F3A9E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A9E8))
#define SFERA_STATIC_04F3A9E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A9E8)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F3AAB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AAB8))
#define SFERA_STATIC_04F3AAB8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3AAB8)))

/* data refs=4 addr=4 */
#define SFERA_STATIC_04F3AB88_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AB88))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F3AC88_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AC88))
#define SFERA_STATIC_04F3AC88_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3AC88)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04F3AD58_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3AD58)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F3AD5C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3AD5C)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F3AD60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AD60))
#define SFERA_STATIC_04F3AD60_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3AD60)))

/* data refs=6 addr=6 */
#define SFERA_STATIC_04F3AE30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AE30))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F3AF30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AF30))
#define SFERA_STATIC_04F3AF30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3AF30)))

/* data refs=3 addr=1 u8=2 */
#define SFERA_STATIC_04F3B000_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B000))
#define SFERA_STATIC_04F3B000_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B000)))

/* data refs=11 u32=17 */
#define SFERA_STATIC_04F3B080_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B080))
#define SFERA_STATIC_04F3B080_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B080)))

/* data refs=18 u32=18 */
#define SFERA_STATIC_04F3B084_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B084)))

/* data refs=5 u8=5 */
#define SFERA_STATIC_04F3B088_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B088)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F3B08C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B08C)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04F3B090_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B090)))

/* data refs=15 u32=15 */
#define SFERA_STATIC_04F3B094_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B094)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F3B098_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B098)))

/* data refs=14 u32=14 */
#define SFERA_STATIC_04F3B09C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B09C)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04F3B0A0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B0A0)))

/* data refs=15 addr=5 u32=10 */
#define SFERA_STATIC_04F3B0A4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B0A4))
#define SFERA_STATIC_04F3B0A4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B0A4)))

/* data refs=7 u32=11 */
#define SFERA_STATIC_04F3B0A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B0A8))
#define SFERA_STATIC_04F3B0A8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B0A8)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F3B0B0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B0B0))
#define SFERA_STATIC_04F3B0B0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B0B0)))

/* data refs=50 addr=5 u32=45 */
#define SFERA_STATIC_04F3B11C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B11C))
#define SFERA_STATIC_04F3B11C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B11C)))

/* data refs=28 u32=48 */
#define SFERA_STATIC_04F3B120_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B120))
#define SFERA_STATIC_04F3B120_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B120)))

/* data refs=10 addr=5 u32=5 */
#define SFERA_STATIC_04F3B188_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B188))
#define SFERA_STATIC_04F3B188_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B188)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F3B18C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B18C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F3B190_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B190)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04F3B194_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B194)))

/* data refs=12 u32=14 */
#define SFERA_STATIC_04F3B198_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B198))
#define SFERA_STATIC_04F3B198_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B198)))

/* data refs=17 addr=2 u32=15 */
#define SFERA_STATIC_04F3B1A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B1A0))
#define SFERA_STATIC_04F3B1A0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B1A0)))

/* data refs=9 u32=13 */
#define SFERA_STATIC_04F3B1A4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B1A4))
#define SFERA_STATIC_04F3B1A4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B1A4)))

/* data refs=15 addr=1 u32=14 */
#define SFERA_STATIC_04F3B1AC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B1AC))
#define SFERA_STATIC_04F3B1AC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B1AC)))

/* data refs=5 u32=7 */
#define SFERA_STATIC_04F3B1B0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B1B0))
#define SFERA_STATIC_04F3B1B0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B1B0)))

/* data refs=10 addr=3 u32=7 */
#define SFERA_STATIC_04F3B1B8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B1B8))
#define SFERA_STATIC_04F3B1B8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B1B8)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04F3B1BC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B1BC)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04F3B1C4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B1C4))

/* data refs=7 addr=7 */
#define SFERA_STATIC_04F3B1C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B1C8))

/* data refs=3 u8=3 */
#define SFERA_STATIC_04F3B210_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B210)))

/* data refs=7 addr=6 u8=1 */
#define SFERA_STATIC_04F3B3C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B3C0))

/* data refs=2 u32=1 u8=1 */
#define SFERA_STATIC_04F3B4C0_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B4C0)))
#define SFERA_STATIC_04F3B4C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B4C0)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04F3B4C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B4C8))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04F3B8C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B8C8))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04F3B9C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B9C8))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F3BAC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3BAC8))
#define SFERA_STATIC_04F3BAC8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3BAC8)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F3BB98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3BB98))
#define SFERA_STATIC_04F3BB98_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3BB98)))

/* data refs=18 addr=8 u8=10 */
#define SFERA_STATIC_04F3BC68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3BC68))
#define SFERA_STATIC_04F3BC68_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3BC68)))

/* data refs=3 addr=2 u8=1 */
#define SFERA_STATIC_04F3FC68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3FC68))
#define SFERA_STATIC_04F3FC68_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3FC68)))

/* data refs=8 addr=6 u8=2 */
#define SFERA_STATIC_04F43C68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F43C68))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F47C68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47C68))
#define SFERA_STATIC_04F47C68_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F47C68)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F47D38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47D38))
#define SFERA_STATIC_04F47D38_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F47D38)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F47E08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47E08))
#define SFERA_STATIC_04F47E08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F47E08)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F47ED8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47ED8))
#define SFERA_STATIC_04F47ED8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F47ED8)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04F47FA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F47FA8)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F47FB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47FB0))
#define SFERA_STATIC_04F47FB0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F47FB0)))

/* data refs=8 addr=8 */
#define SFERA_STATIC_04F48080_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48080))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F48180_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48180))
#define SFERA_STATIC_04F48180_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48180)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F48250_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48250))
#define SFERA_STATIC_04F48250_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48250)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F48320_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48320))
#define SFERA_STATIC_04F48320_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48320)))

/* data refs=10 addr=10 */
#define SFERA_STATIC_04F483F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F483F0))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F484F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F484F0))
#define SFERA_STATIC_04F484F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F484F0)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04F485C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F485C0))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F486C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F486C0))
#define SFERA_STATIC_04F486C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F486C0)))

/* data refs=14 addr=14 */
#define SFERA_STATIC_04F48790_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48790))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F48890_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48890))
#define SFERA_STATIC_04F48890_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48890)))

/* data refs=15 addr=5 u32=10 */
#define SFERA_STATIC_04F48960_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48960))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F48A5C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48A5C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F48A60_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48A60)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F48A64_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48A64))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F48A68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48A68))

/* data refs=9 addr=1 u32=8 */
#define SFERA_STATIC_04F48A6C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48A6C))
#define SFERA_STATIC_04F48A6C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48A6C)))

/* data refs=8 addr=3 u32=5 */
#define SFERA_STATIC_04F48A70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48A70))
#define SFERA_STATIC_04F48A70_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48A70)))


/* data refs=3 addr=3 */
#define SFERA_STATIC_04F48BF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BF0))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04F493F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F493F0))

/* data refs=7 addr=7 */
#define SFERA_STATIC_04F495F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F495F0))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04F497F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F497F0))

/* data refs=12 addr=11 u32=1 */
#define SFERA_STATIC_04F499F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F499F0))
#define SFERA_STATIC_04F499F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F499F0)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F49A00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49A00)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F49A04_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49A04)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F49A08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49A08)))

/* data refs=9 addr=1 u32=8 */
#define SFERA_STATIC_04F49A0C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49A0C))
#define SFERA_STATIC_04F49A0C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49A0C)))

/* data refs=4 addr=4 */
#define SFERA_STATIC_04F49A10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49A10))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F49A94_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49A94)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F49A98_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49A98)))

/* data refs=12 addr=1 u32=11 */
#define SFERA_STATIC_04F49A9C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49A9C))
#define SFERA_STATIC_04F49A9C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49A9C)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F49AA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49AA0))
#define SFERA_STATIC_04F49AA0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49AA0)))

/* data refs=23 addr=7 u32=16 */
#define SFERA_STATIC_04F49B70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49B70))
#define SFERA_STATIC_04F49B70_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B70)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F49B74_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B74)))

/* data refs=9 addr=4 u32=5 */
#define SFERA_STATIC_04F49B80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49B80))
#define SFERA_STATIC_04F49B80_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B80)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F49B84_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B84)))

/* data refs=18 addr=2 u32=16 */
#define SFERA_STATIC_04F49B90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49B90))
#define SFERA_STATIC_04F49B90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B90)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04F49B94_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B94)))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04F49BA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49BA0))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04F49C20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49C20))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F49CA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49CA0))
#define SFERA_STATIC_04F49CA0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49CA0)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F49E70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49E70))
#define SFERA_STATIC_04F49E70_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49E70)))


/* data refs=2 addr=2 */
#define SFERA_STATIC_04F49FC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49FC0))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4A0C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A0C0))
#define SFERA_STATIC_04F4A0C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A0C0)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04F4A190_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A190))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4A290_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A290))
#define SFERA_STATIC_04F4A290_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A290)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4A360_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A360))
#define SFERA_STATIC_04F4A360_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A360)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4A430_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A430))
#define SFERA_STATIC_04F4A430_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A430)))

/* data refs=14 addr=2 u32=12 */
#define SFERA_STATIC_04F4A49C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A49C))
#define SFERA_STATIC_04F4A49C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A49C)))

/* data refs=4 u32=6 */
#define SFERA_STATIC_04F4A4A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A4A0))
#define SFERA_STATIC_04F4A4A0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A4A0)))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04F4A508_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A508))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04F4A50C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A50C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F4A510_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A510)))

/* data refs=10 u32=12 u8=2 */
#define SFERA_STATIC_04F4A518_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A518))
#define SFERA_STATIC_04F4A518_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A518)))
#define SFERA_STATIC_04F4A518_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A518)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4A520_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A520))
#define SFERA_STATIC_04F4A520_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A520)))

/* data refs=7 addr=7 */
#define SFERA_STATIC_04F4A5F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A5F0))

/* data refs=8 u32=10 */
#define SFERA_STATIC_04F4C5F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C5F0))
#define SFERA_STATIC_04F4C5F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4C5F0)))

/* data refs=8 addr=8 */
#define SFERA_STATIC_04F4C5F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C5F8))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F4C6FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4C6FC)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F4C704_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4C704)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4C710_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C710))
#define SFERA_STATIC_04F4C710_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4C710)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4C7E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C7E0))
#define SFERA_STATIC_04F4C7E0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4C7E0)))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04F4C8B0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C8B0))

/* data refs=10 u32=12 u8=2 */
#define SFERA_STATIC_04F4C8C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C8C0))
#define SFERA_STATIC_04F4C8C0_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4C8C0)))
#define SFERA_STATIC_04F4C8C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4C8C0)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4C8C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C8C8))
#define SFERA_STATIC_04F4C8C8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4C8C8)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4C998_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C998))
#define SFERA_STATIC_04F4C998_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4C998)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4CA68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CA68))
#define SFERA_STATIC_04F4CA68_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CA68)))

/* data refs=4 addr=1 u32=3 */
#define SFERA_STATIC_04F4CB38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CB38))
#define SFERA_STATIC_04F4CB38_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CB38)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4CB40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CB40))
#define SFERA_STATIC_04F4CB40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CB40)))


/* data refs=5 u32=5 */
#define SFERA_STATIC_04F4CC14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CC14)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4CC18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CC18))
#define SFERA_STATIC_04F4CC18_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CC18)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04F4CCEC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CCEC))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04F4CD2C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CD2C))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F4CD94_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CD94)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F4CD98_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CD98)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F4CD9C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CD9C)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4CE10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CE10))
#define SFERA_STATIC_04F4CE10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CE10)))

/* data refs=9 addr=9 */
#define SFERA_STATIC_04F4CF50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CF50))

/* data refs=19 addr=8 u32=11 */
#define SFERA_STATIC_04F4D760_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4D760))
#define SFERA_STATIC_04F4D760_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4D760)))

/* data refs=10 addr=2 u32=16 */
#define SFERA_STATIC_04F8D770_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8D770))

/* data refs=10 addr=2 u32=16 */
#define SFERA_STATIC_04F8E770_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8E770))

/* data refs=5 u8=5 */
#define SFERA_STATIC_04F8F770_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8F770)))

/* data refs=12 u8=12 */
#define SFERA_STATIC_04F8F771_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8F771)))

/* data refs=9 u32=17 */
#define SFERA_STATIC_04F8F774_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8F774))
#define SFERA_STATIC_04F8F774_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8F774)))

/* data refs=4 u32=6 */
#define SFERA_STATIC_04F8F77C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8F77C))
#define SFERA_STATIC_04F8F77C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8F77C)))

/* data refs=12 addr=12 */
#define SFERA_STATIC_04F8F780_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8F780))

/* data refs=15 addr=15 */
#define SFERA_STATIC_04F8FA48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8FA48))

/* data refs=5 u8=5 */
#define SFERA_STATIC_04F8FAC7_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8FAC7)))

/* data refs=4 u32=6 */
#define SFERA_STATIC_04F8FAC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8FAC8))
#define SFERA_STATIC_04F8FAC8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8FAC8)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04F8FACC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8FACC)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F8FAD0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8FAD0)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04F8FAD8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8FAD8))

/* data refs=6 addr=6 */
#define SFERA_STATIC_04F8FDA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8FDA0))

/* data refs=12 u8=12 */
#define SFERA_STATIC_04F90068_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90068)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04F9006C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F9006C)))

/* data refs=3 u16=3 */
#define SFERA_STATIC_04F90070_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90070))

/* data refs=10 u8=10 */
#define SFERA_STATIC_04F90270_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90270))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F90370_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90370)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04F90378_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90378))

/* data refs=21 addr=21 */
#define SFERA_STATIC_04F903FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F903FC))

/* data refs=10 u8=10 */
#define SFERA_STATIC_04F90414_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90414)))

/* data refs=12 u8=12 */
#define SFERA_STATIC_04F90415_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90415)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F90424_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90424)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F9042C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F9042C))
#define SFERA_STATIC_04F9042C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F9042C)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F90430_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90430)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F90434_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90434)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F9076C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F9076C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F90774_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90774)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F9077C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F9077C)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04F90784_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90784))
#define SFERA_STATIC_04F90784_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90784)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F90788_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90788)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F9078C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F9078C)))

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
