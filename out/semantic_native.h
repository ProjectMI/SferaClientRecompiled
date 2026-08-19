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
/* These objects no longer live in the synthetic .data image.  Lifted consumers use
 * normal C storage and take an address only when the recovered ABI actually passes
 * an object/field by pointer. */

typedef struct SferaItemArray { uint32_t block_vector_begin; uint32_t block_vector_end; uint32_t block_vector_capacity_end; uint32_t reserved; uint32_t free_items; uint32_t free_count; uint32_t growth_count; } SferaItemArray;
typedef struct SferaServerWall { uint32_t wall_data; uint32_t reserved_04; uint32_t wall_count; uint32_t generated_data; uint32_t generated_points; uint32_t segment_count; uint32_t effect_handle; } SferaServerWall;
typedef struct SferaDirectPlayCaps32 { uint32_t words[12]; } SferaDirectPlayCaps32;
typedef struct SferaNetworkMessageSlot { uint8_t bytes[0x1A8]; } SferaNetworkMessageSlot;
typedef struct SferaNetworkRuntime { uint32_t initialization_result; uint32_t server_port; uint32_t local_port_candidate; uint32_t connection_slot; uint32_t pending_slot; uint32_t active_slot; uint32_t shutdown_state; uint8_t timeout_marker_pending; uint8_t net_log_has_error; uint8_t network_error_active; uint8_t initialized; uint32_t bytes_sent_delta; uint32_t bytes_retried_delta; uint32_t bytes_received_delta; uint32_t error_budget; SferaDirectPlayCaps32 directplay_caps; uint32_t message_call_scratch; SferaNetworkMessageSlot message_slots[3048]; } SferaNetworkRuntime;
typedef struct SferaGraphicsRuntime { float fog_distance; float saved_fog_distance; uint32_t lods_enabled; uint32_t hardware_cursor_enabled; float environment_factor; uint8_t render_mode_enabled; uint32_t base_microtexture_id; float view_parameter; float view_scale; uint32_t post_effects_enabled; uint32_t rebuild_percent; uint32_t runtime_counter; uint32_t texture_runtime_id; float base_render_factor; } SferaGraphicsRuntime;
typedef struct SferaWorldObjectRuntime { uint32_t max_occupied_object_handle; uint32_t controlled_object_handle; uint32_t contour_mode; } SferaWorldObjectRuntime;
typedef struct SferaControlOptionsRuntime { uint32_t active_slot; } SferaControlOptionsRuntime;
typedef struct SferaSpriteRuntime { uint32_t render_mode; } SferaSpriteRuntime;
typedef struct SferaCrashRuntime { uint8_t report_pending; } SferaCrashRuntime;
typedef struct SferaContoursRuntime { uint32_t round_robin_counter; } SferaContoursRuntime;
typedef struct SferaDynGreenRuntime { uint32_t previous_timestamp_low; uint32_t previous_timestamp_high; } SferaDynGreenRuntime;
typedef struct SferaExecutionMonitorRuntime { uint32_t thread_handle; uint8_t reserved_04[8]; uint16_t stop_requested; char log_path[0x36]; uint8_t critical_section[24]; uint32_t current_value_a; uint32_t current_value_b; } SferaExecutionMonitorRuntime;
typedef struct SferaErrorLogRuntime { uint8_t object[0x18]; uint8_t index_table[0x80]; } SferaErrorLogRuntime;
typedef struct SferaPacketCodecRuntime { uint8_t substitution[256]; uint32_t initialized; uint16_t checksum[256]; } SferaPacketCodecRuntime;
typedef struct SferaOleHostAbi { uint32_t storage_vtable[18]; uint32_t storage_object_vtable; uint32_t inplace_frame_vtable[15]; uint32_t client_site_vtable[9]; uint32_t inplace_site_vtable[15]; uint32_t doc_host_ui_handler_vtable[18]; } SferaOleHostAbi;
typedef struct SferaInterfaceRuntime { uint32_t cursor_kind; uint8_t primary_gate; uint8_t secondary_gate; uint32_t cross_enabled; uint32_t sounds_enabled; uint32_t description_auto_popup; uint32_t invite_messages; } SferaInterfaceRuntime;
typedef struct SferaStdAllocator { uint32_t vptr; } SferaStdAllocator;
typedef struct SferaMemoryRuntime { uint32_t allocation_source_file; uint32_t allocation_source_line; uint32_t critical_error_callback; uint32_t tracker_primary; uint32_t tracker_auxiliary; uint32_t tracker_floor; uint32_t tracker_ceiling; } SferaMemoryRuntime;
typedef struct SferaRenderBufferCapacities { uint32_t vertex32; uint32_t vertex28; uint32_t index_primary; uint32_t index_secondary; } SferaRenderBufferCapacities;
typedef struct SferaAutoBoundsArray { uint32_t data; uint32_t capacity; uint32_t maximum; uint32_t growth; uint32_t element_size; char debug_file[32]; uint32_t debug_line; } SferaAutoBoundsArray;
typedef struct SferaFileRuntime { uint32_t crash_report_instance; uint32_t callback_enabled; uint32_t search_path_count; uint32_t open_file_count; uint32_t callback; SferaAutoBoundsArray search_paths; SferaAutoBoundsArray open_files; } SferaFileRuntime;
typedef struct SferaVec3F { float x; float y; float z; } SferaVec3F;
typedef struct SferaBoundCheckArray { uint32_t data; uint32_t capacity; char debug_file[32]; uint32_t debug_line; } SferaBoundCheckArray;
typedef struct SferaEffectListenerMap { uint8_t comparator; uint8_t _alignment[3]; uint32_t head; uint32_t size; } SferaEffectListenerMap;
typedef struct SferaIntrusiveListHeader { uint32_t first; uint32_t last; } SferaIntrusiveListHeader;
#if defined(__cplusplus)
static_assert(sizeof(SferaIntrusiveListHeader) == 8u, "SferaIntrusiveListHeader ABI layout");
#else
_Static_assert(sizeof(SferaIntrusiveListHeader) == 8u, "SferaIntrusiveListHeader ABI layout");
#endif
typedef struct SferaEffectManagerRuntime { uint32_t deferred_lifecycle; uint32_t render_cycle; uint32_t active_resource_count; uint32_t detail_setting; uint32_t effects_enabled; uint32_t render_slot_count; uint32_t particle_random_table; uint32_t particle_resource_head; uint32_t effect_definition_head; uint32_t initialized; uint32_t render_sort_indices; uint32_t render_index_buffer; uint32_t render_batch_buffer; uint32_t active_effect_count; SferaIntrusiveListHeader active_effects; uint32_t generation; uint32_t last_processed_generation; uint32_t flare_transition; uint32_t flare_enabled; uint32_t flare_alpha; SferaVec3F viewer_position; SferaBoundCheckArray render_slots; SferaEffectListenerMap effect_listeners; } SferaEffectManagerRuntime;

#ifdef __cplusplus
extern "C" {
#endif
extern SferaItemArray g_sfera_effect_items;
extern SferaItemArray g_sfera_sound_effect_items;
extern SferaServerWall g_sfera_server_wall;
extern SferaNetworkRuntime g_sfera_network_runtime;
extern SferaGraphicsRuntime g_sfera_graphics_runtime;
extern SferaWorldObjectRuntime g_sfera_world_objects;
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
/* All 351 former compatibility-address materializations are resolved here.
 * Each root keeps canonical contiguous pointer identity; semantic storage is selected at dereference, not while the pointer value flows through lifted/native ABI.
 * Categories describe the concrete use at the original callsite. */

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
/* array base root; sfera_sub_00435110 @ lifted_functions_005.c:7261; source=0x00916E49 */
#define SFERA_DATA_ARRAY_BASE_00916E49_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00916E49))
/* array base root; sfera_sub_00435110 @ lifted_functions_005.c:7269; source=0x00916E4A */
#define SFERA_DATA_ARRAY_BASE_00916E4A_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00916E4A))
/* array base root; sfera_sub_004349A0 @ lifted_functions_005.c:6623; source=0x00B6FA3C */
#define SFERA_DATA_ARRAY_BASE_00B6FA3C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FA3C))
/* array base root; sfera_sub_00443F20 @ lifted_functions_007.c:2215; source=0x00B6FA74 */
#define SFERA_DATA_ARRAY_BASE_00B6FA74_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FA74))
/* arithmetic base root; sfera_sub_00449180 @ lifted_functions_007.c:7258; source=0x00B6FBC8 */
#define SFERA_DATA_ARITHMETIC_BASE_00B6FBC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FBC8))
/* array base root; sfera_sub_004349A0 @ lifted_functions_005.c:6645; source=0x00B6FD34 */
#define SFERA_DATA_ARRAY_BASE_00B6FD34_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FD34))
/* arithmetic base root; sfera_sub_00434900 @ lifted_functions_005.c:6545; source=0x04007710 */
#define SFERA_DATA_ARITHMETIC_BASE_04007710_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04007710))
/* array base root; sfera_sub_00436E20 @ lifted_functions_005.c:9563; source=0x0401A66C */
#define SFERA_DATA_ARRAY_BASE_0401A66C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A66C))
/* array base root; sfera_sub_00436ED0 @ lifted_functions_005.c:9629; source=0x0401A680 */
#define SFERA_DATA_ARRAY_BASE_0401A680_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A680))
/* array base root; sfera_sub_00436ED0 @ lifted_functions_005.c:9630; source=0x0401A684 */
#define SFERA_DATA_ARRAY_BASE_0401A684_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A684))
/* array base root; sfera_sub_00449180 @ lifted_functions_007.c:7394; source=0x0401C687 */
#define SFERA_DATA_ARRAY_BASE_0401C687_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401C687))
/* arithmetic base root; sfera_sub_00435230 @ lifted_functions_005.c:8111; source=0x0401C6A8 */
#define SFERA_DATA_ARITHMETIC_BASE_0401C6A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401C6A8))
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
#define SFERA_DATA_CALL_ARGUMENT_04ED1304_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1304))
/* indexed table base root; sfera_sub_00468750 @ lifted_functions_010.c:6796; source=0x04ED1328 */
#define SFERA_DATA_TABLE_BASE_04ED1328_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1328))
/* call argument root; sfera_sub_004F5C90 @ lifted_functions_025.c:2356; source=0x04ED1A44 */
#define SFERA_DATA_CALL_ARGUMENT_04ED1A44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1A44))
/* call argument root; sfera_sub_004F5B60 @ lifted_functions_025.c:2189; source=0x04ED1A7C */
#define SFERA_DATA_CALL_ARGUMENT_04ED1A7C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1A7C))
/* arithmetic base root; sfera_sub_00457E80 @ lifted_functions_009.c:754; source=0x04ED1AAC */
#define SFERA_DATA_ARITHMETIC_BASE_04ED1AAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1AAC))
/* global object root; sfera_sub_00454BA0 @ lifted_functions_008.c:8468; source=0x04ED1AB0 */
#define SFERA_DATA_GLOBAL_OBJECT_04ED1AB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1AB0))
/* global object root; sfera_sub_00454A40 @ lifted_functions_008.c:8352; source=0x04ED1AB4 */
#define SFERA_DATA_GLOBAL_OBJECT_04ED1AB4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1AB4))
/* arithmetic base root; sfera_sub_0044E480 @ lifted_functions_008.c:491; source=0x04ED1ABC */
#define SFERA_DATA_ARITHMETIC_BASE_04ED1ABC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1ABC))
/* pointer value root; sfera_sub_00454A40 @ lifted_functions_008.c:8398; source=0x04ED29B4 */
#define SFERA_DATA_POINTER_VALUE_04ED29B4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED29B4))
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
#define SFERA_DATA_GLOBAL_OBJECT_04EE057C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE057C))
/* pointer value root; sfera_sub_0047DB70 @ lifted_functions_012.c:7290; source=0x04EE097C */
#define SFERA_DATA_POINTER_VALUE_04EE097C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE097C))
/* global object root; sfera_sub_0047DB70 @ lifted_functions_012.c:7325; source=0x04EE0AAC */
#define SFERA_DATA_GLOBAL_OBJECT_04EE0AAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE0AAC))
/* pointer value root; sfera_sub_0047DB70 @ lifted_functions_012.c:7352; source=0x04EE0EAC */
#define SFERA_DATA_POINTER_VALUE_04EE0EAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE0EAC))
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

/* ===== Recovered .data objects ===== */
/* Phase-3 semantic data objects. Objects are addressed through independent semantic spans.
 * A compatibility alias of the same backing bytes remains only for unresolved source-style pointers and native ABI paths.
 * Names remain source-VA based until class/field semantics are proven. */

#pragma pack(push, 1)





































typedef struct SferaDataObject_006BE110 {
    uint32_t f_006BE110;
    uint32_t f_006BE114;
    uint32_t f_006BE118;
    uint8_t _pad_00[UINT32_C(0x00000018)];
    uint8_t f_006BE134[UINT32_C(0x00000001)];
    uint8_t _pad_01[UINT32_C(0x00000017)];
    uint32_t f_006BE14C;
    uint8_t _pad_02[UINT32_C(0x00000008)];
    uint32_t f_006BE158;
    uint32_t f_006BE15C;
} SferaDataObject_006BE110;
#define SFERA_DATA_OBJECT_006BE110 ((SferaDataObject_006BE110*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE110))))

typedef struct SferaDataObject_006BE1B4 {
    uint32_t f_006BE1B4;
    uint8_t f_006BE1B8;
    uint8_t f_006BE1B9;
    uint8_t f_006BE1BA;
    uint8_t _pad_00[UINT32_C(0x00000001)];
    uint32_t f_006BE1BC;
    uint32_t f_006BE1C0;
    uint32_t f_006BE1C4;
    uint32_t f_006BE1C8;
    uint32_t f_006BE1CC;
    uint32_t f_006BE1D0;
    uint32_t f_006BE1D4;
    uint32_t f_006BE1D8;
    uint32_t f_006BE1DC;
    uint32_t f_006BE1E0;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint32_t f_006BE1E8;
} SferaDataObject_006BE1B4;
#define SFERA_DATA_OBJECT_006BE1B4 ((SferaDataObject_006BE1B4*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1B4))))

typedef struct SferaDataObject_006BE2B8 {
    uint32_t f_006BE2B8;
    uint32_t f_006BE2BC;
    uint32_t f_006BE2C0;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_006BE2C8;
    uint32_t f_006BE2CC;
    uint32_t f_006BE2D0;
    uint32_t f_006BE2D4;
} SferaDataObject_006BE2B8;
#define SFERA_DATA_OBJECT_006BE2B8 ((SferaDataObject_006BE2B8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE2B8))))

typedef struct SferaDataObject_006BE408 {
    uint32_t f_006BE408;
    uint8_t f_006BE40C;
    uint8_t _pad_00[UINT32_C(0x00000001)];
    uint8_t f_006BE40E;
    uint8_t f_006BE40F;
    uint32_t f_006BE410;
    uint32_t f_006BE414;
} SferaDataObject_006BE408;
#define SFERA_DATA_OBJECT_006BE408 ((SferaDataObject_006BE408*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE408))))

typedef struct SferaDataObject_00916E40 {
    uint32_t f_00916E40;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint8_t f_00916E48;
    uint8_t _pad_01[UINT32_C(0x00000002)];
    uint16_t f_00916E4B;
} SferaDataObject_00916E40;
#define SFERA_DATA_OBJECT_00916E40 ((SferaDataObject_00916E40*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00916E40))))

typedef struct SferaDataObject_0091756C {
    uint32_t f_0091756C;
    uint8_t f_00917570;
} SferaDataObject_0091756C;
#define SFERA_DATA_OBJECT_0091756C ((SferaDataObject_0091756C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0091756C))))

typedef struct SferaDataObject_00B6F8B0 {
    uint32_t f_00B6F8B0;
    uint32_t f_00B6F8B4;
    uint32_t f_00B6F8B8;
    uint32_t f_00B6F8BC;
    uint8_t f_00B6F8C0;
} SferaDataObject_00B6F8B0;
#define SFERA_DATA_OBJECT_00B6F8B0 ((SferaDataObject_00B6F8B0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00B6F8B0))))

typedef struct SferaDataObject_00B6F9E8 {
    uint32_t f_00B6F9E8;
    uint32_t f_00B6F9EC;
    uint8_t f_00B6F9F0[UINT32_C(0x00000001)];
    uint8_t _pad_00[UINT32_C(0x0000000F)];
    uint8_t f_00B6FA00[UINT32_C(0x00000001)];
} SferaDataObject_00B6F9E8;
#define SFERA_DATA_OBJECT_00B6F9E8 ((SferaDataObject_00B6F9E8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00B6F9E8))))

typedef struct SferaDataObject_00B6FA34 {
    uint32_t f_00B6FA34;
    uint32_t f_00B6FA38;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_00B6FA40;
    uint8_t _pad_01[UINT32_C(0x00000018)];
    uint32_t f_00B6FA5C;
    uint32_t f_00B6FA60;
} SferaDataObject_00B6FA34;
#define SFERA_DATA_OBJECT_00B6FA34 ((SferaDataObject_00B6FA34*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00B6FA34))))

typedef struct SferaDataObject_00B6FA84 {
    uint32_t f_00B6FA84;
    uint8_t _pad_00[UINT32_C(0x0000001C)];
    uint32_t f_00B6FAA4;
    uint8_t f_00B6FAA8;
    uint8_t _pad_01[UINT32_C(0x0000000F)];
    uint32_t f_00B6FAB8;
    uint32_t f_00B6FABC;
} SferaDataObject_00B6FA84;
#define SFERA_DATA_OBJECT_00B6FA84 ((SferaDataObject_00B6FA84*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00B6FA84))))

typedef struct SferaDataObject_00B6FCC4 {
    uint16_t f_00B6FCC4;
    uint8_t _pad_00[UINT32_C(0x0000000E)];
    uint32_t f_00B6FCD4;
} SferaDataObject_00B6FCC4;
#define SFERA_DATA_OBJECT_00B6FCC4 ((SferaDataObject_00B6FCC4*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00B6FCC4))))

typedef struct SferaDataObject_03FEF9F0 {
    uint32_t f_03FEF9F0;
    uint32_t f_03FEF9F4;
    uint32_t f_03FEF9F8;
} SferaDataObject_03FEF9F0;
#define SFERA_DATA_OBJECT_03FEF9F0 ((SferaDataObject_03FEF9F0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x03FEF9F0))))

typedef struct SferaDataObject_040070F8 {
    uint32_t f_040070F8;
    uint32_t f_040070FC;
    uint8_t f_04007100[UINT32_C(0x00000001)];
} SferaDataObject_040070F8;
#define SFERA_DATA_OBJECT_040070F8 ((SferaDataObject_040070F8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x040070F8))))

typedef struct SferaDataObject_0400722C {
    uint32_t f_0400722C;
    uint32_t f_04007230;
    uint32_t f_04007234;
    uint32_t f_04007238;
} SferaDataObject_0400722C;
#define SFERA_DATA_OBJECT_0400722C ((SferaDataObject_0400722C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0400722C))))

typedef struct SferaDataObject_04007638 {
    uint32_t f_04007638;
    uint32_t f_0400763C;
    uint32_t f_04007640;
    uint32_t f_04007644;
} SferaDataObject_04007638;
#define SFERA_DATA_OBJECT_04007638 ((SferaDataObject_04007638*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04007638))))

typedef struct SferaDataObject_04007670 {
    uint32_t f_04007670;
    uint32_t f_04007674;
    uint8_t f_04007678[UINT32_C(0x00000001)];
} SferaDataObject_04007670;
#define SFERA_DATA_OBJECT_04007670 ((SferaDataObject_04007670*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04007670))))

typedef struct SferaDataObject_040076F0 {
    uint32_t f_040076F0;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint8_t f_040076F8[UINT32_C(0x00000001)];
} SferaDataObject_040076F0;
#define SFERA_DATA_OBJECT_040076F0 ((SferaDataObject_040076F0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x040076F0))))

typedef struct SferaDataObject_04008378 {
    uint32_t f_04008378;
    uint32_t f_0400837C;
    uint32_t f_04008380;
} SferaDataObject_04008378;
#define SFERA_DATA_OBJECT_04008378 ((SferaDataObject_04008378*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04008378))))

typedef struct SferaDataObject_04013F00 {
    uint32_t f_04013F00;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint8_t f_04013F08[UINT32_C(0x00000002)];
} SferaDataObject_04013F00;
#define SFERA_DATA_OBJECT_04013F00 ((SferaDataObject_04013F00*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04013F00))))

typedef struct SferaDataObject_04016618 {
    uint32_t f_04016618;
    uint32_t f_0401661C;
    uint32_t f_04016620;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04016628;
} SferaDataObject_04016618;
#define SFERA_DATA_OBJECT_04016618 ((SferaDataObject_04016618*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04016618))))

typedef struct SferaDataObject_04016680 {
    uint32_t f_04016680;
    uint32_t f_04016684;
    uint8_t f_04016688[UINT32_C(0x00000004)];
} SferaDataObject_04016680;
#define SFERA_DATA_OBJECT_04016680 ((SferaDataObject_04016680*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04016680))))

typedef struct SferaDataObject_0401A668 {
    uint32_t f_0401A668;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_0401A670;
    uint32_t f_0401A674;
    uint32_t f_0401A678;
    uint8_t f_0401A67C[UINT32_C(0x00000004)];
    uint8_t _pad_01[UINT32_C(0x00000008)];
    uint8_t f_0401A688[UINT32_C(0x00000004)];
    uint8_t _pad_02[UINT32_C(0x00000004)];
    uint32_t f_0401A690;
    uint32_t f_0401A694;
    uint32_t f_0401A698;
    uint8_t f_0401A69C[UINT32_C(0x00000004)];
    uint32_t f_0401A6A0;
    uint32_t f_0401A6A4;
} SferaDataObject_0401A668;
#define SFERA_DATA_OBJECT_0401A668 ((SferaDataObject_0401A668*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0401A668))))

typedef struct SferaDataObject_0401C5C8 {
    uint32_t f_0401C5C8;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_0401C5D0;
    uint32_t f_0401C5D4;
    uint32_t f_0401C5D8;
    uint32_t f_0401C5DC;
} SferaDataObject_0401C5C8;
#define SFERA_DATA_OBJECT_0401C5C8 ((SferaDataObject_0401C5C8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0401C5C8))))

typedef struct SferaDataObject_048F4688 {
    uint32_t f_048F4688;
    uint32_t f_048F468C;
    uint8_t f_048F4690;
} SferaDataObject_048F4688;
#define SFERA_DATA_OBJECT_048F4688 ((SferaDataObject_048F4688*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x048F4688))))

typedef struct SferaDataObject_048F5A98 {
    uint32_t f_048F5A98;
    uint32_t f_048F5A9C;
} SferaDataObject_048F5A98;
#define SFERA_DATA_OBJECT_048F5A98 ((SferaDataObject_048F5A98*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x048F5A98))))

typedef struct SferaDataObject_048F5B04 {
    uint32_t f_048F5B04;
    uint32_t f_048F5B08;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_048F5B10;
    uint32_t f_048F5B14;
    uint8_t f_048F5B18[UINT32_C(0x00000001)];
} SferaDataObject_048F5B04;
#define SFERA_DATA_OBJECT_048F5B04 ((SferaDataObject_048F5B04*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x048F5B04))))

typedef struct SferaDataObject_04B5DDA0 {
    uint32_t f_04B5DDA0;
    uint32_t f_04B5DDA4;
    uint32_t f_04B5DDA8;
} SferaDataObject_04B5DDA0;
#define SFERA_DATA_OBJECT_04B5DDA0 ((SferaDataObject_04B5DDA0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04B5DDA0))))

typedef struct SferaDataObject_04B5FE78 {
    uint32_t f_04B5FE78;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04B5FE80;
} SferaDataObject_04B5FE78;
#define SFERA_DATA_OBJECT_04B5FE78 ((SferaDataObject_04B5FE78*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04B5FE78))))

typedef struct SferaDataObject_04B602C4 {
    uint32_t f_04B602C4;
    uint32_t f_04B602C8;
    uint32_t f_04B602CC;
    uint8_t f_04B602D0[UINT32_C(0x00000001)];
} SferaDataObject_04B602C4;
#define SFERA_DATA_OBJECT_04B602C4 ((SferaDataObject_04B602C4*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04B602C4))))

typedef struct SferaDataObject_04DBC430 {
    uint32_t f_04DBC430;
    uint32_t f_04DBC434;
    uint32_t f_04DBC438;
    uint32_t f_04DBC43C;
    uint32_t f_04DBC440;
    uint32_t f_04DBC444;
    uint8_t _pad_00[UINT32_C(0x00000010)];
    uint32_t f_04DBC458;
    uint8_t _pad_01[UINT32_C(0x00000008)];
    uint32_t f_04DBC464;
    uint32_t f_04DBC468;
    uint8_t _pad_02[UINT32_C(0x00000004)];
    uint32_t f_04DBC470;
    uint8_t _pad_03[UINT32_C(0x00000014)];
    uint32_t f_04DBC488;
    uint32_t f_04DBC48C;
    uint32_t f_04DBC490;
} SferaDataObject_04DBC430;
#define SFERA_DATA_OBJECT_04DBC430 ((SferaDataObject_04DBC430*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC430))))

typedef struct SferaDataObject_04DBC4FC {
    float f_04DBC4FC;
    uint8_t _pad_00[UINT32_C(0x00000008)];
    uint8_t f_04DBC508[UINT32_C(0x00000001)];
} SferaDataObject_04DBC4FC;
#define SFERA_DATA_OBJECT_04DBC4FC ((SferaDataObject_04DBC4FC*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC4FC))))

typedef struct SferaDataObject_04DC0680 {
    uint8_t f_04DC0680[UINT32_C(0x00000001)];
    uint8_t _pad_00[UINT32_C(0x00000007)];
    uint32_t f_04DC0688;
    uint8_t f_04DC068C[UINT32_C(0x00000004)];
    uint32_t f_04DC0690;
    uint8_t _pad_01[UINT32_C(0x00000008)];
    uint32_t f_04DC069C;
    uint8_t _pad_02[UINT32_C(0x00000008)];
    uint32_t f_04DC06A8;
    uint32_t f_04DC06AC;
    uint32_t f_04DC06B0;
} SferaDataObject_04DC0680;
#define SFERA_DATA_OBJECT_04DC0680 ((SferaDataObject_04DC0680*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DC0680))))

typedef struct SferaDataObject_04DD0C50 {
    uint32_t f_04DD0C50;
    uint32_t f_04DD0C54;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04DD0C5C;
    uint32_t f_04DD0C60;
    uint32_t f_04DD0C64;
} SferaDataObject_04DD0C50;
#define SFERA_DATA_OBJECT_04DD0C50 ((SferaDataObject_04DD0C50*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0C50))))

typedef struct SferaDataObject_04DD1068 {
    uint8_t f_04DD1068;
    uint8_t f_04DD1069;
    uint8_t _pad_00[UINT32_C(0x00000006)];
    uint32_t f_04DD1070;
} SferaDataObject_04DD1068;
#define SFERA_DATA_OBJECT_04DD1068 ((SferaDataObject_04DD1068*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1068))))

typedef struct SferaDataObject_04DD1250 {
    float f_04DD1250;
    uint32_t f_04DD1254;
    uint32_t f_04DD1258;
    uint32_t f_04DD125C;
    uint8_t _pad_00[UINT32_C(0x00000010)];
    uint32_t f_04DD1270;
    uint32_t f_04DD1274;
    uint8_t _pad_01[UINT32_C(0x00000010)];
    uint32_t f_04DD1288;
    uint32_t f_04DD128C;
    uint32_t f_04DD1290;
    uint32_t f_04DD1294;
    uint32_t f_04DD1298;
    uint32_t f_04DD129C;
    uint32_t f_04DD12A0;
    uint32_t f_04DD12A4;
} SferaDataObject_04DD1250;
#define SFERA_DATA_OBJECT_04DD1250 ((SferaDataObject_04DD1250*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1250))))

typedef struct SferaDataObject_04DD52A8 {
    float f_04DD52A8;
    uint8_t _pad_00[UINT32_C(0x0000001C)];
    float f_04DD52C8;
} SferaDataObject_04DD52A8;
#define SFERA_DATA_OBJECT_04DD52A8 ((SferaDataObject_04DD52A8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD52A8))))

typedef struct SferaDataObject_04DD54A8 {
    float f_04DD54A8;
    uint16_t f_04DD54AC;
} SferaDataObject_04DD54A8;
#define SFERA_DATA_OBJECT_04DD54A8 ((SferaDataObject_04DD54A8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD54A8))))

typedef struct SferaDataObject_04DD57D0 {
    uint32_t f_04DD57D0;
    uint8_t _pad_00[UINT32_C(0x00000008)];
    uint32_t f_04DD57DC;
    float f_04DD57E0;
    uint32_t f_04DD57E4;
    uint32_t f_04DD57E8;
    uint32_t f_04DD57EC;
    uint32_t f_04DD57F0;
    float f_04DD57F4;
    float f_04DD57F8;
    uint32_t f_04DD57FC;
    uint32_t f_04DD5800;
    uint8_t f_04DD5804[UINT32_C(0x00000004)];
    uint32_t f_04DD5808;
    float f_04DD580C;
    float f_04DD5810;
    uint32_t f_04DD5814;
    uint32_t f_04DD5818;
    uint32_t f_04DD581C;
    uint8_t _pad_01[UINT32_C(0x00000008)];
    uint32_t f_04DD5828;
    uint32_t f_04DD582C;
    uint32_t f_04DD5830;
    uint32_t f_04DD5834;
    uint8_t f_04DD5838;
    uint8_t f_04DD5839;
} SferaDataObject_04DD57D0;
#define SFERA_DATA_OBJECT_04DD57D0 ((SferaDataObject_04DD57D0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57D0))))

typedef struct SferaDataObject_04DD7A40 {
    uint32_t f_04DD7A40;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04DD7A48;
} SferaDataObject_04DD7A40;
#define SFERA_DATA_OBJECT_04DD7A40 ((SferaDataObject_04DD7A40*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7A40))))

typedef struct SferaDataObject_04DD7C28 {
    uint32_t f_04DD7C28;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04DD7C30;
    float f_04DD7C34;
    float f_04DD7C38;
    uint32_t f_04DD7C3C;
    uint32_t f_04DD7C40;
    uint8_t _pad_01[UINT32_C(0x00000008)];
    uint32_t f_04DD7C4C;
    uint32_t f_04DD7C50;
    uint32_t f_04DD7C54;
    uint8_t _pad_02[UINT32_C(0x00000004)];
    uint32_t f_04DD7C5C;
    uint32_t f_04DD7C60;
} SferaDataObject_04DD7C28;
#define SFERA_DATA_OBJECT_04DD7C28 ((SferaDataObject_04DD7C28*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7C28))))

typedef struct SferaDataObject_04DD8A2C {
    uint32_t f_04DD8A2C;
    float f_04DD8A30;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04DD8A38;
} SferaDataObject_04DD8A2C;
#define SFERA_DATA_OBJECT_04DD8A2C ((SferaDataObject_04DD8A2C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8A2C))))

typedef struct SferaDataObject_04DD8B00 {
    uint32_t f_04DD8B00;
    uint8_t _pad_00[UINT32_C(0x0000000C)];
    uint32_t f_04DD8B10;
    uint32_t f_04DD8B14;
    uint32_t f_04DD8B18;
    uint32_t f_04DD8B1C;
    uint32_t f_04DD8B20;
    uint32_t f_04DD8B24;
    uint32_t f_04DD8B28;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint32_t f_04DD8B30;
    float f_04DD8B34;
} SferaDataObject_04DD8B00;
#define SFERA_DATA_OBJECT_04DD8B00 ((SferaDataObject_04DD8B00*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B00))))

typedef struct SferaDataObject_04DD93B8 {
    uint32_t f_04DD93B8;
    uint32_t f_04DD93BC;
    uint32_t f_04DD93C0;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04DD93C8;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    float f_04DD93D0;
    float f_04DD93D4;
    float f_04DD93D8;
    float f_04DD93DC;
    float f_04DD93E0;
    float f_04DD93E4;
    uint8_t _pad_02[UINT32_C(0x00000008)];
    uint32_t f_04DD93F0;
} SferaDataObject_04DD93B8;
#define SFERA_DATA_OBJECT_04DD93B8 ((SferaDataObject_04DD93B8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD93B8))))

typedef struct SferaDataObject_04DDF9E4 {
    uint32_t f_04DDF9E4;
    uint32_t f_04DDF9E8;
    float f_04DDF9EC;
    float f_04DDF9F0;
    float f_04DDF9F4;
    float f_04DDF9F8;
    float f_04DDF9FC;
    float f_04DDFA00;
    uint32_t f_04DDFA04;
    uint32_t f_04DDFA08;
    uint32_t f_04DDFA0C;
    uint32_t f_04DDFA10;
    float f_04DDFA14;
    uint32_t f_04DDFA18;
} SferaDataObject_04DDF9E4;
#define SFERA_DATA_OBJECT_04DDF9E4 ((SferaDataObject_04DDF9E4*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDF9E4))))

typedef struct SferaDataObject_04DDFE18 {
    float f_04DDFE18;
    uint32_t f_04DDFE1C;
    uint8_t _pad_00[UINT32_C(0x00000008)];
    uint8_t f_04DDFE28[UINT32_C(0x00000001)];
} SferaDataObject_04DDFE18;
#define SFERA_DATA_OBJECT_04DDFE18 ((SferaDataObject_04DDFE18*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDFE18))))

typedef struct SferaDataObject_04DE04B8 {
    uint32_t f_04DE04B8;
    uint32_t f_04DE04BC;
    uint32_t f_04DE04C0;
} SferaDataObject_04DE04B8;
#define SFERA_DATA_OBJECT_04DE04B8 ((SferaDataObject_04DE04B8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DE04B8))))

typedef struct SferaDataObject_04DE0538 {
    uint32_t f_04DE0538;
    uint8_t _pad_00[UINT32_C(0x00000014)];
    uint8_t f_04DE0550;
} SferaDataObject_04DE0538;
#define SFERA_DATA_OBJECT_04DE0538 ((SferaDataObject_04DE0538*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DE0538))))

typedef struct SferaDataObject_04DE1150 {
    uint32_t f_04DE1150;
    uint32_t f_04DE1154;
    uint32_t f_04DE1158;
    uint8_t _pad_00[UINT32_C(0x00000014)];
    uint8_t f_04DE1170[UINT32_C(0x00000001)];
} SferaDataObject_04DE1150;
#define SFERA_DATA_OBJECT_04DE1150 ((SferaDataObject_04DE1150*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DE1150))))

typedef struct SferaDataObject_04E01170 {
    uint32_t f_04E01170;
    uint32_t f_04E01174;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint8_t f_04E0117C[UINT32_C(0x00000004)];
    uint8_t _pad_01[UINT32_C(0x00000008)];
    uint32_t f_04E01188;
    uint8_t _pad_02[UINT32_C(0x00000014)];
    uint8_t f_04E011A0[UINT32_C(0x00000001)];
} SferaDataObject_04E01170;
#define SFERA_DATA_OBJECT_04E01170 ((SferaDataObject_04E01170*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E01170))))

typedef struct SferaDataObject_04E01670 {
    uint32_t f_04E01670;
    uint32_t f_04E01674;
    uint8_t _pad_00[UINT32_C(0x00000014)];
    uint32_t f_04E0168C;
    uint8_t f_04E01690[UINT32_C(0x00000001)];
    uint8_t _pad_01[UINT32_C(0x00000003)];
    uint8_t f_04E01694[UINT32_C(0x00000001)];
} SferaDataObject_04E01670;
#define SFERA_DATA_OBJECT_04E01670 ((SferaDataObject_04E01670*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E01670))))

typedef struct SferaDataObject_04E1CF30 {
    uint32_t f_04E1CF30;
    uint32_t f_04E1CF34;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04E1CF3C;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint32_t f_04E1CF44;
    uint8_t _pad_02[UINT32_C(0x00000004)];
    uint8_t f_04E1CF4C;
    uint8_t _pad_03[UINT32_C(0x00000003)];
    uint32_t f_04E1CF50;
    uint32_t f_04E1CF54;
} SferaDataObject_04E1CF30;
#define SFERA_DATA_OBJECT_04E1CF30 ((SferaDataObject_04E1CF30*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1CF30))))

typedef struct SferaDataObject_04E1D268 {
    uint32_t f_04E1D268;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint8_t f_04E1D270[UINT32_C(0x00000001)];
    uint8_t _pad_01[UINT32_C(0x00000003)];
    uint8_t f_04E1D274[UINT32_C(0x00000001)];
} SferaDataObject_04E1D268;
#define SFERA_DATA_OBJECT_04E1D268 ((SferaDataObject_04E1D268*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1D268))))

typedef struct SferaDataObject_04E1D66C {
    float f_04E1D66C;
    uint8_t f_04E1D670[UINT32_C(0x00000001)];
} SferaDataObject_04E1D66C;
#define SFERA_DATA_OBJECT_04E1D66C ((SferaDataObject_04E1D66C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1D66C))))

typedef struct SferaDataObject_04E1DC00 {
    uint32_t f_04E1DC00;
    float f_04E1DC04;
    uint32_t f_04E1DC08;
    uint32_t f_04E1DC0C;
} SferaDataObject_04E1DC00;
#define SFERA_DATA_OBJECT_04E1DC00 ((SferaDataObject_04E1DC00*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DC00))))

typedef struct SferaDataObject_04E1DD14 {
    uint32_t f_04E1DD14;
    uint8_t _pad_00[UINT32_C(0x00000008)];
    uint32_t f_04E1DD20;
    uint32_t f_04E1DD24;
    uint32_t f_04E1DD28;
    uint32_t f_04E1DD2C;
    uint32_t f_04E1DD30;
    uint32_t f_04E1DD34;
} SferaDataObject_04E1DD14;
#define SFERA_DATA_OBJECT_04E1DD14 ((SferaDataObject_04E1DD14*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DD14))))

typedef struct SferaDataObject_04E1DE00 {
    uint32_t f_04E1DE00;
    uint8_t _pad_00[UINT32_C(0x00000010)];
    float f_04E1DE14;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint32_t f_04E1DE1C;
    uint8_t f_04E1DE20;
} SferaDataObject_04E1DE00;
#define SFERA_DATA_OBJECT_04E1DE00 ((SferaDataObject_04E1DE00*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DE00))))

typedef struct SferaDataObject_04E1DEA0 {
    uint32_t f_04E1DEA0;
    float f_04E1DEA4;
} SferaDataObject_04E1DEA0;
#define SFERA_DATA_OBJECT_04E1DEA0 ((SferaDataObject_04E1DEA0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DEA0))))

typedef struct SferaDataObject_04E2C0B0 {
    uint32_t f_04E2C0B0;
    uint32_t f_04E2C0B4;
    uint32_t f_04E2C0B8;
} SferaDataObject_04E2C0B0;
#define SFERA_DATA_OBJECT_04E2C0B0 ((SferaDataObject_04E2C0B0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C0B0))))

typedef struct SferaDataObject_04E2C130 {
    uint32_t f_04E2C130;
    float f_04E2C134;
    uint32_t f_04E2C138;
    uint32_t f_04E2C13C;
    uint32_t f_04E2C140;
    uint32_t f_04E2C144;
} SferaDataObject_04E2C130;
#define SFERA_DATA_OBJECT_04E2C130 ((SferaDataObject_04E2C130*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C130))))

typedef struct SferaDataObject_04E2C898 {
    uint32_t f_04E2C898;
    uint8_t f_04E2C89C;
    uint8_t _pad_00[UINT32_C(0x0000001F)];
    uint32_t f_04E2C8BC;
    uint32_t f_04E2C8C0;
    uint32_t f_04E2C8C4;
    uint8_t _pad_01[UINT32_C(0x00000008)];
    float f_04E2C8D0;
    float f_04E2C8D4;
    uint32_t f_04E2C8D8;
    uint32_t f_04E2C8DC;
    float f_04E2C8E0;
} SferaDataObject_04E2C898;
#define SFERA_DATA_OBJECT_04E2C898 ((SferaDataObject_04E2C898*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C898))))

typedef struct SferaDataObject_04E2C940 {
    uint32_t f_04E2C940;
    uint32_t f_04E2C944;
    uint32_t f_04E2C948;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint8_t f_04E2C950[UINT32_C(0x00000004)];
    float f_04E2C954;
} SferaDataObject_04E2C940;
#define SFERA_DATA_OBJECT_04E2C940 ((SferaDataObject_04E2C940*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C940))))

typedef struct SferaDataObject_04E2C9A0 {
    float f_04E2C9A0;
    float f_04E2C9A4;
} SferaDataObject_04E2C9A0;
#define SFERA_DATA_OBJECT_04E2C9A0 ((SferaDataObject_04E2C9A0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C9A0))))

typedef struct SferaDataObject_04E2C9F0 {
    float f_04E2C9F0;
    float f_04E2C9F4;
} SferaDataObject_04E2C9F0;
#define SFERA_DATA_OBJECT_04E2C9F0 ((SferaDataObject_04E2C9F0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C9F0))))

typedef struct SferaDataObject_04E2CA44 {
    uint32_t f_04E2CA44;
    uint16_t f_04E2CA48;
    uint16_t f_04E2CA4A;
    uint16_t f_04E2CA4C;
    uint16_t f_04E2CA4E;
    uint16_t f_04E2CA50;
    uint16_t f_04E2CA52;
} SferaDataObject_04E2CA44;
#define SFERA_DATA_OBJECT_04E2CA44 ((SferaDataObject_04E2CA44*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2CA44))))

typedef struct SferaDataObject_04E2DC44 {
    uint32_t f_04E2DC44;
    uint8_t _pad_00[UINT32_C(0x00000014)];
    uint32_t f_04E2DC5C;
    uint32_t f_04E2DC60;
} SferaDataObject_04E2DC44;
#define SFERA_DATA_OBJECT_04E2DC44 ((SferaDataObject_04E2DC44*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2DC44))))

typedef struct SferaDataObject_04E2DE08 {
    float f_04E2DE08;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04E2DE10;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint16_t f_04E2DE18;
    uint16_t f_04E2DE1A;
    uint16_t f_04E2DE1C;
} SferaDataObject_04E2DE08;
#define SFERA_DATA_OBJECT_04E2DE08 ((SferaDataObject_04E2DE08*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2DE08))))

typedef struct SferaDataObject_04E2E2BC {
    uint32_t f_04E2E2BC;
    uint8_t f_04E2E2C0[UINT32_C(0x00000004)];
    float f_04E2E2C4;
} SferaDataObject_04E2E2BC;
#define SFERA_DATA_OBJECT_04E2E2BC ((SferaDataObject_04E2E2BC*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2E2BC))))

typedef struct SferaDataObject_04E2E310 {
    float f_04E2E310;
    float f_04E2E314;
} SferaDataObject_04E2E310;
#define SFERA_DATA_OBJECT_04E2E310 ((SferaDataObject_04E2E310*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2E310))))

typedef struct SferaDataObject_04E2E360 {
    float f_04E2E360;
    float f_04E2E364;
} SferaDataObject_04E2E360;
#define SFERA_DATA_OBJECT_04E2E360 ((SferaDataObject_04E2E360*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2E360))))

typedef struct SferaDataObject_04E2E3B4 {
    uint32_t f_04E2E3B4;
    uint32_t f_04E2E3B8;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint8_t f_04E2E3C0[UINT32_C(0x00000001)];
    uint8_t _pad_01[UINT32_C(0x00000013)];
    uint8_t f_04E2E3D4;
    uint8_t f_04E2E3D5;
} SferaDataObject_04E2E3B4;
#define SFERA_DATA_OBJECT_04E2E3B4 ((SferaDataObject_04E2E3B4*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2E3B4))))

typedef struct SferaDataObject_04E509C0 {
    uint8_t f_04E509C0;
    uint8_t _pad_00[UINT32_C(0x0000001C)];
    uint8_t f_04E509DD;
    uint8_t _pad_01[UINT32_C(0x0000000C)];
    uint8_t f_04E509EA;
    uint8_t _pad_02[UINT32_C(0x0000000B)];
    uint8_t f_04E509F6;
    uint8_t _pad_03[UINT32_C(0x00000001)];
    uint8_t f_04E509F8;
} SferaDataObject_04E509C0;
#define SFERA_DATA_OBJECT_04E509C0 ((SferaDataObject_04E509C0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E509C0))))

typedef struct SferaDataObject_04E50AC0 {
    uint32_t f_04E50AC0;
    uint32_t f_04E50AC4;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04E50ACC;
    uint32_t f_04E50AD0;
} SferaDataObject_04E50AC0;
#define SFERA_DATA_OBJECT_04E50AC0 ((SferaDataObject_04E50AC0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E50AC0))))

typedef struct SferaDataObject_04E51ED0 {
    uint32_t f_04E51ED0;
    uint32_t f_04E51ED4;
    uint8_t f_04E51ED8[UINT32_C(0x00000004)];
} SferaDataObject_04E51ED0;
#define SFERA_DATA_OBJECT_04E51ED0 ((SferaDataObject_04E51ED0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E51ED0))))

typedef struct SferaDataObject_04E51F0C {
    uint32_t f_04E51F0C;
    uint32_t f_04E51F10;
} SferaDataObject_04E51F0C;
#define SFERA_DATA_OBJECT_04E51F0C ((SferaDataObject_04E51F0C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E51F0C))))

typedef struct SferaDataObject_04E522F0 {
    uint32_t f_04E522F0;
    uint32_t f_04E522F4;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04E522FC;
    uint32_t f_04E52300;
    uint32_t f_04E52304;
    uint16_t f_04E52308;
} SferaDataObject_04E522F0;
#define SFERA_DATA_OBJECT_04E522F0 ((SferaDataObject_04E522F0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E522F0))))

typedef struct SferaDataObject_04E72308 { uint8_t storage[UINT32_C(0x00000028)]; } SferaDataObject_04E72308;
#define SFERA_DATA_OBJECT_04E72308 ((SferaDataObject_04E72308*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E72308))))

typedef struct SferaDataObject_04E73320 {
    uint32_t f_04E73320;
    uint32_t f_04E73324;
} SferaDataObject_04E73320;
#define SFERA_DATA_OBJECT_04E73320 ((SferaDataObject_04E73320*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E73320))))

typedef struct SferaDataObject_04E769D8 {
    uint32_t f_04E769D8;
    uint32_t f_04E769DC;
    uint32_t f_04E769E0;
    float f_04E769E4;
    uint8_t _pad_00[UINT32_C(0x00000014)];
    uint32_t f_04E769FC;
    uint32_t f_04E76A00;
    uint8_t f_04E76A04[UINT32_C(0x00000004)];
} SferaDataObject_04E769D8;
#define SFERA_DATA_OBJECT_04E769D8 ((SferaDataObject_04E769D8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E769D8))))

typedef struct SferaDataObject_04E78A08 {
    uint32_t f_04E78A08;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04E78A10;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint32_t f_04E78A18;
} SferaDataObject_04E78A08;
#define SFERA_DATA_OBJECT_04E78A08 ((SferaDataObject_04E78A08*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78A08))))

typedef struct SferaDataObject_04E78A90 {
    uint32_t f_04E78A90;
    uint8_t f_04E78A94[UINT32_C(0x00000004)];
    uint8_t f_04E78A98[UINT32_C(0x00000001)];
    uint8_t _pad_00[UINT32_C(0x00000003)];
    float f_04E78A9C;
    float f_04E78AA0;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    float f_04E78AA8;
} SferaDataObject_04E78A90;
#define SFERA_DATA_OBJECT_04E78A90 ((SferaDataObject_04E78A90*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78A90))))

typedef struct SferaDataObject_04E78D64 {
    float f_04E78D64;
    float f_04E78D68;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    float f_04E78D70;
    uint8_t _pad_01[UINT32_C(0x00000018)];
    uint32_t f_04E78D8C;
    uint32_t f_04E78D90;
    uint32_t f_04E78D94;
    uint8_t f_04E78D98[UINT32_C(0x00000004)];
    uint8_t _pad_02[UINT32_C(0x00000008)];
    float f_04E78DA4;
    float f_04E78DA8;
} SferaDataObject_04E78D64;
#define SFERA_DATA_OBJECT_04E78D64 ((SferaDataObject_04E78D64*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78D64))))

typedef struct SferaDataObject_04E78F8C {
    uint32_t f_04E78F8C;
    uint32_t f_04E78F90;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    float f_04E78F98;
    float f_04E78F9C;
    uint32_t f_04E78FA0;
    uint8_t f_04E78FA4[UINT32_C(0x00000004)];
    uint32_t f_04E78FA8;
    float f_04E78FAC;
    uint32_t f_04E78FB0;
    uint32_t f_04E78FB4;
} SferaDataObject_04E78F8C;
#define SFERA_DATA_OBJECT_04E78F8C ((SferaDataObject_04E78F8C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78F8C))))

typedef struct SferaDataObject_04E79234 {
    uint32_t f_04E79234;
    uint32_t f_04E79238;
    uint8_t _pad_00[UINT32_C(0x00000008)];
    uint32_t f_04E79244;
    uint32_t f_04E79248;
    float f_04E7924C;
    uint8_t f_04E79250[UINT32_C(0x00000001)];
    uint8_t _pad_01[UINT32_C(0x00000017)];
    uint32_t f_04E79268;
} SferaDataObject_04E79234;
#define SFERA_DATA_OBJECT_04E79234 ((SferaDataObject_04E79234*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79234))))

typedef struct SferaDataObject_04E792E0 {
    uint32_t f_04E792E0;
    uint32_t f_04E792E4;
    uint32_t f_04E792E8;
    uint32_t f_04E792EC;
    uint32_t f_04E792F0;
    uint32_t f_04E792F4;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04E792FC;
    uint32_t f_04E79300;
    uint32_t f_04E79304;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint32_t f_04E7930C;
    uint8_t f_04E79310;
} SferaDataObject_04E792E0;
#define SFERA_DATA_OBJECT_04E792E0 ((SferaDataObject_04E792E0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792E0))))

typedef struct SferaDataObject_04E79B14 {
    uint32_t f_04E79B14;
    uint8_t _pad_00[UINT32_C(0x00000008)];
    uint8_t f_04E79B20[UINT32_C(0x00000001)];
} SferaDataObject_04E79B14;
#define SFERA_DATA_OBJECT_04E79B14 ((SferaDataObject_04E79B14*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79B14))))

typedef struct SferaDataObject_04EB9C28 {
    uint32_t f_04EB9C28;
    float f_04EB9C2C;
    uint32_t f_04EB9C30;
    uint8_t _pad_00[UINT32_C(0x00000010)];
    uint8_t f_04EB9C44[UINT32_C(0x00000001)];
    uint8_t _pad_01[UINT32_C(0x00000013)];
    uint32_t f_04EB9C58;
    uint32_t f_04EB9C5C;
} SferaDataObject_04EB9C28;
#define SFERA_DATA_OBJECT_04EB9C28 ((SferaDataObject_04EB9C28*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9C28))))

typedef struct SferaDataObject_04EB9CC4 {
    uint32_t f_04EB9CC4;
    float f_04EB9CC8;
    float f_04EB9CCC;
    uint32_t f_04EB9CD0;
    uint32_t f_04EB9CD4;
    uint32_t f_04EB9CD8;
    uint8_t _pad_00[UINT32_C(0x00000010)];
    uint32_t f_04EB9CEC;
    float f_04EB9CF0;
} SferaDataObject_04EB9CC4;
#define SFERA_DATA_OBJECT_04EB9CC4 ((SferaDataObject_04EB9CC4*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9CC4))))

typedef struct SferaDataObject_04EB9E80 {
    uint32_t f_04EB9E80;
    float f_04EB9E84;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04EB9E8C;
    uint32_t f_04EB9E90;
    uint32_t f_04EB9E94;
} SferaDataObject_04EB9E80;
#define SFERA_DATA_OBJECT_04EB9E80 ((SferaDataObject_04EB9E80*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9E80))))

typedef struct SferaDataObject_04EC4EE0 {
    uint32_t f_04EC4EE0;
    uint32_t f_04EC4EE4;
    uint8_t _pad_00[UINT32_C(0x00000001)];
    uint8_t f_04EC4EE9;
    uint8_t f_04EC4EEA;
    uint8_t f_04EC4EEB;
    uint32_t f_04EC4EEC;
    uint32_t f_04EC4EF0;
    uint32_t f_04EC4EF4;
    uint32_t f_04EC4EF8;
    uint32_t f_04EC4EFC;
    uint32_t f_04EC4F00;
    uint32_t f_04EC4F04;
    uint32_t f_04EC4F08;
    float f_04EC4F0C;
    uint32_t f_04EC4F10;
    uint32_t f_04EC4F14;
    uint32_t f_04EC4F18;
    uint8_t _pad_01[UINT32_C(0x00000008)];
    uint32_t f_04EC4F24;
    uint8_t _pad_02[UINT32_C(0x00000008)];
    uint32_t f_04EC4F30;
    uint8_t _pad_03[UINT32_C(0x0000000C)];
    uint32_t f_04EC4F40;
    uint8_t _pad_04[UINT32_C(0x00000004)];
    uint32_t f_04EC4F48;
    uint32_t f_04EC4F4C;
    uint32_t f_04EC4F50;
    uint32_t f_04EC4F54;
    uint32_t f_04EC4F58;
    uint8_t _pad_05[UINT32_C(0x00000005)];
    uint8_t f_04EC4F61;
    uint8_t f_04EC4F62;
    uint8_t _pad_06[UINT32_C(0x00000001)];
    uint32_t f_04EC4F64;
    uint8_t _pad_07[UINT32_C(0x00000004)];
    uint32_t f_04EC4F6C;
    uint32_t f_04EC4F70;
    uint32_t f_04EC4F74;
    uint8_t _pad_08[UINT32_C(0x00000008)];
    uint32_t f_04EC4F80;
    uint32_t f_04EC4F84;
} SferaDataObject_04EC4EE0;
#define SFERA_DATA_OBJECT_04EC4EE0 ((SferaDataObject_04EC4EE0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EE0))))

typedef struct SferaDataObject_04EC4FB0 {
    uint8_t f_04EC4FB0[UINT32_C(0x00000001)];
    uint8_t _pad_00[UINT32_C(0x0000000B)];
    uint32_t f_04EC4FBC;
} SferaDataObject_04EC4FB0;
#define SFERA_DATA_OBJECT_04EC4FB0 ((SferaDataObject_04EC4FB0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4FB0))))

typedef struct SferaDataObject_04EC4FF0 {
    float f_04EC4FF0;
    float f_04EC4FF4;
    float f_04EC4FF8;
} SferaDataObject_04EC4FF0;
#define SFERA_DATA_OBJECT_04EC4FF0 ((SferaDataObject_04EC4FF0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4FF0))))

typedef struct SferaDataObject_04ECBA38 {
    uint32_t f_04ECBA38;
    uint32_t f_04ECBA3C;
    uint32_t f_04ECBA40;
    float f_04ECBA44;
    float f_04ECBA48;
    float f_04ECBA4C;
    uint8_t f_04ECBA50[UINT32_C(0x00000001)];
} SferaDataObject_04ECBA38;
#define SFERA_DATA_OBJECT_04ECBA38 ((SferaDataObject_04ECBA38*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ECBA38))))

typedef struct SferaDataObject_04ED0E14 {
    uint32_t f_04ED0E14;
    uint32_t f_04ED0E18;
    uint8_t f_04ED0E1C[UINT32_C(0x00000001)];
} SferaDataObject_04ED0E14;
#define SFERA_DATA_OBJECT_04ED0E14 ((SferaDataObject_04ED0E14*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E14))))

typedef struct SferaDataObject_04ED0E40 {
    uint8_t f_04ED0E40[UINT32_C(0x00000004)];
    uint8_t f_04ED0E44[UINT32_C(0x00000004)];
    uint8_t f_04ED0E48[UINT32_C(0x00000004)];
    float f_04ED0E4C;
    float f_04ED0E50;
    float f_04ED0E54;
    float f_04ED0E58;
    float f_04ED0E5C;
    float f_04ED0E60;
    float f_04ED0E64;
    float f_04ED0E68;
    float f_04ED0E6C;
    float f_04ED0E70;
    float f_04ED0E74;
    float f_04ED0E78;
} SferaDataObject_04ED0E40;
#define SFERA_DATA_OBJECT_04ED0E40 ((SferaDataObject_04ED0E40*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E40))))

typedef struct SferaDataObject_04ED0EA0 {
    uint32_t f_04ED0EA0;
    uint32_t f_04ED0EA4;
    uint32_t f_04ED0EA8;
    uint32_t f_04ED0EAC;
    uint32_t f_04ED0EB0;
    uint32_t f_04ED0EB4;
    uint8_t f_04ED0EB8[UINT32_C(0x00000004)];
    uint8_t f_04ED0EBC[UINT32_C(0x00000004)];
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04ED0EC4;
    uint32_t f_04ED0EC8;
    uint8_t f_04ED0ECC[UINT32_C(0x00000001)];
} SferaDataObject_04ED0EA0;
#define SFERA_DATA_OBJECT_04ED0EA0 ((SferaDataObject_04ED0EA0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EA0))))

typedef struct SferaDataObject_04ED0F30 {
    uint32_t f_04ED0F30;
    uint32_t f_04ED0F34;
    uint8_t f_04ED0F38[UINT32_C(0x00000001)];
} SferaDataObject_04ED0F30;
#define SFERA_DATA_OBJECT_04ED0F30 ((SferaDataObject_04ED0F30*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0F30))))

typedef struct SferaDataObject_04ED0F5C {
    uint32_t f_04ED0F5C;
    uint32_t f_04ED0F60;
    uint8_t f_04ED0F64[UINT32_C(0x00000001)];
} SferaDataObject_04ED0F5C;
#define SFERA_DATA_OBJECT_04ED0F5C ((SferaDataObject_04ED0F5C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0F5C))))

typedef struct SferaDataObject_04ED0FE8 {
    uint32_t f_04ED0FE8;
    uint32_t f_04ED0FEC;
    uint8_t f_04ED0FF0[UINT32_C(0x00000001)];
} SferaDataObject_04ED0FE8;
#define SFERA_DATA_OBJECT_04ED0FE8 ((SferaDataObject_04ED0FE8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0FE8))))

typedef struct SferaDataObject_04ED1014 {
    uint32_t f_04ED1014;
    uint32_t f_04ED1018;
    uint8_t f_04ED101C[UINT32_C(0x00000001)];
} SferaDataObject_04ED1014;
#define SFERA_DATA_OBJECT_04ED1014 ((SferaDataObject_04ED1014*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1014))))

typedef struct SferaDataObject_04ED10E0 {
    uint8_t f_04ED10E0[UINT32_C(0x00000001)];
    uint8_t _pad_00[UINT32_C(0x0000000B)];
    float f_04ED10EC;
    uint8_t _pad_01[UINT32_C(0x0000000C)];
    float f_04ED10FC;
    uint8_t _pad_02[UINT32_C(0x0000000C)];
    float f_04ED110C;
    uint8_t _pad_03[UINT32_C(0x00000010)];
    uint32_t f_04ED1120;
} SferaDataObject_04ED10E0;
#define SFERA_DATA_OBJECT_04ED10E0 ((SferaDataObject_04ED10E0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED10E0))))

typedef struct SferaDataObject_04ED1190 {
    uint32_t f_04ED1190;
    uint32_t f_04ED1194;
    uint8_t f_04ED1198[UINT32_C(0x00000001)];
} SferaDataObject_04ED1190;
#define SFERA_DATA_OBJECT_04ED1190 ((SferaDataObject_04ED1190*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1190))))

typedef struct SferaDataObject_04ED11BC {
    uint32_t f_04ED11BC;
    uint32_t f_04ED11C0;
    uint8_t f_04ED11C4[UINT32_C(0x00000001)];
} SferaDataObject_04ED11BC;
#define SFERA_DATA_OBJECT_04ED11BC ((SferaDataObject_04ED11BC*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED11BC))))

typedef struct SferaDataObject_04ED1258 {
    uint32_t f_04ED1258;
    uint32_t f_04ED125C;
    uint8_t f_04ED1260[UINT32_C(0x00000001)];
} SferaDataObject_04ED1258;
#define SFERA_DATA_OBJECT_04ED1258 ((SferaDataObject_04ED1258*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1258))))

typedef struct SferaDataObject_04ED1284 {
    uint32_t f_04ED1284;
    uint32_t f_04ED1288;
    uint8_t f_04ED128C[UINT32_C(0x00000001)];
} SferaDataObject_04ED1284;
#define SFERA_DATA_OBJECT_04ED1284 ((SferaDataObject_04ED1284*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1284))))

typedef struct SferaDataObject_04ED12F0 {
    uint32_t f_04ED12F0;
    uint32_t f_04ED12F4;
} SferaDataObject_04ED12F0;
#define SFERA_DATA_OBJECT_04ED12F0 ((SferaDataObject_04ED12F0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED12F0))))

typedef struct SferaDataObject_04ED29A0 {
    uint32_t f_04ED29A0;
    uint32_t f_04ED29A4;
    uint8_t f_04ED29A8[UINT32_C(0x00000001)];
} SferaDataObject_04ED29A0;
#define SFERA_DATA_OBJECT_04ED29A0 ((SferaDataObject_04ED29A0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED29A0))))

typedef struct SferaDataObject_04ED29CC {
    uint32_t f_04ED29CC;
    uint32_t f_04ED29D0;
    uint8_t f_04ED29D4[UINT32_C(0x00000001)];
} SferaDataObject_04ED29CC;
#define SFERA_DATA_OBJECT_04ED29CC ((SferaDataObject_04ED29CC*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED29CC))))

typedef struct SferaDataObject_04ED29F8 {
    uint32_t f_04ED29F8;
    uint32_t f_04ED29FC;
    uint8_t f_04ED2A00[UINT32_C(0x00000001)];
} SferaDataObject_04ED29F8;
#define SFERA_DATA_OBJECT_04ED29F8 ((SferaDataObject_04ED29F8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED29F8))))

typedef struct SferaDataObject_04ED2A24 {
    uint32_t f_04ED2A24;
    uint32_t f_04ED2A28;
    uint8_t f_04ED2A2C[UINT32_C(0x00000001)];
} SferaDataObject_04ED2A24;
#define SFERA_DATA_OBJECT_04ED2A24 ((SferaDataObject_04ED2A24*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A24))))

typedef struct SferaDataObject_04ED2A7C {
    uint32_t f_04ED2A7C;
    uint32_t f_04ED2A80;
    uint8_t f_04ED2A84[UINT32_C(0x00000001)];
} SferaDataObject_04ED2A7C;
#define SFERA_DATA_OBJECT_04ED2A7C ((SferaDataObject_04ED2A7C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A7C))))

typedef struct SferaDataObject_04ED2AA8 {
    uint32_t f_04ED2AA8;
    uint32_t f_04ED2AAC;
    uint8_t f_04ED2AB0[UINT32_C(0x00000001)];
} SferaDataObject_04ED2AA8;
#define SFERA_DATA_OBJECT_04ED2AA8 ((SferaDataObject_04ED2AA8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2AA8))))

typedef struct SferaDataObject_04ED2AD4 {
    uint32_t f_04ED2AD4;
    uint32_t f_04ED2AD8;
    uint8_t f_04ED2ADC[UINT32_C(0x00000001)];
} SferaDataObject_04ED2AD4;
#define SFERA_DATA_OBJECT_04ED2AD4 ((SferaDataObject_04ED2AD4*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2AD4))))

typedef struct SferaDataObject_04ED2B00 {
    uint8_t f_04ED2B00[UINT32_C(0x00000004)];
    uint8_t f_04ED2B04[UINT32_C(0x00000004)];
    uint8_t f_04ED2B08[UINT32_C(0x00000004)];
    uint32_t f_04ED2B0C;
    uint32_t f_04ED2B10;
    uint8_t f_04ED2B14[UINT32_C(0x00000001)];
} SferaDataObject_04ED2B00;
#define SFERA_DATA_OBJECT_04ED2B00 ((SferaDataObject_04ED2B00*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2B00))))

typedef struct SferaDataObject_04ED2BE0 {
    uint32_t f_04ED2BE0;
    uint32_t f_04ED2BE4;
    uint32_t f_04ED2BE8;
    uint32_t f_04ED2BEC;
    uint32_t f_04ED2BF0;
    uint8_t f_04ED2BF4[UINT32_C(0x00000001)];
} SferaDataObject_04ED2BE0;
#define SFERA_DATA_OBJECT_04ED2BE0 ((SferaDataObject_04ED2BE0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BE0))))

typedef struct SferaDataObject_04ED2C18 {
    uint32_t f_04ED2C18;
    uint32_t f_04ED2C1C;
    uint8_t f_04ED2C20[UINT32_C(0x00000001)];
} SferaDataObject_04ED2C18;
#define SFERA_DATA_OBJECT_04ED2C18 ((SferaDataObject_04ED2C18*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C18))))

typedef struct SferaDataObject_04ED2C44 {
    uint32_t f_04ED2C44;
    uint32_t f_04ED2C48;
    uint8_t f_04ED2C4C[UINT32_C(0x00000001)];
} SferaDataObject_04ED2C44;
#define SFERA_DATA_OBJECT_04ED2C44 ((SferaDataObject_04ED2C44*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C44))))

typedef struct SferaDataObject_04ED2C70 {
    float f_04ED2C70;
    uint8_t f_04ED2C74[UINT32_C(0x00000004)];
    uint8_t f_04ED2C78[UINT32_C(0x00000004)];
    float f_04ED2C7C;
    float f_04ED2C80;
    float f_04ED2C84;
    float f_04ED2C88;
    float f_04ED2C8C;
    float f_04ED2C90;
    uint8_t f_04ED2C94[UINT32_C(0x00000004)];
    uint8_t f_04ED2C98[UINT32_C(0x00000004)];
    uint8_t f_04ED2C9C[UINT32_C(0x00000004)];
    uint8_t f_04ED2CA0;
    uint8_t _pad_00[UINT32_C(0x00000003)];
    uint8_t f_04ED2CA4[UINT32_C(0x00000004)];
    uint8_t f_04ED2CA8[UINT32_C(0x00000004)];
    uint8_t f_04ED2CAC[UINT32_C(0x00000004)];
    float f_04ED2CB0;
    uint8_t f_04ED2CB4[UINT32_C(0x00000004)];
    float f_04ED2CB8;
} SferaDataObject_04ED2C70;
#define SFERA_DATA_OBJECT_04ED2C70 ((SferaDataObject_04ED2C70*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C70))))

typedef struct SferaDataObject_04ED2D60 {
    uint8_t f_04ED2D60[UINT32_C(0x00000004)];
    uint8_t f_04ED2D64[UINT32_C(0x00000004)];
    uint8_t f_04ED2D68[UINT32_C(0x00000004)];
    uint8_t f_04ED2D6C[UINT32_C(0x00000004)];
    uint8_t f_04ED2D70[UINT32_C(0x00000004)];
    uint8_t f_04ED2D74[UINT32_C(0x00000004)];
    float f_04ED2D78;
} SferaDataObject_04ED2D60;
#define SFERA_DATA_OBJECT_04ED2D60 ((SferaDataObject_04ED2D60*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D60))))

typedef struct SferaDataObject_04ED2DE4 {
    uint32_t f_04ED2DE4;
    uint32_t f_04ED2DE8;
    uint8_t f_04ED2DEC[UINT32_C(0x00000001)];
} SferaDataObject_04ED2DE4;
#define SFERA_DATA_OBJECT_04ED2DE4 ((SferaDataObject_04ED2DE4*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2DE4))))

typedef struct SferaDataObject_04ED2E10 {
    uint32_t f_04ED2E10;
    uint32_t f_04ED2E14;
    uint32_t f_04ED2E18;
    uint32_t f_04ED2E1C;
    uint32_t f_04ED2E20;
    uint32_t f_04ED2E24;
    uint8_t f_04ED2E28[UINT32_C(0x00000004)];
    uint8_t f_04ED2E2C[UINT32_C(0x00000004)];
    uint8_t f_04ED2E30[UINT32_C(0x00000004)];
    uint32_t f_04ED2E34;
    uint32_t f_04ED2E38;
    uint8_t f_04ED2E3C[UINT32_C(0x00000001)];
} SferaDataObject_04ED2E10;
#define SFERA_DATA_OBJECT_04ED2E10 ((SferaDataObject_04ED2E10*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E10))))

typedef struct SferaDataObject_04ED2E60 {
    uint32_t f_04ED2E60;
    uint32_t f_04ED2E64;
    uint8_t f_04ED2E68[UINT32_C(0x00000001)];
} SferaDataObject_04ED2E60;
#define SFERA_DATA_OBJECT_04ED2E60 ((SferaDataObject_04ED2E60*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E60))))

typedef struct SferaDataObject_04ED2E8C {
    uint32_t f_04ED2E8C;
    uint32_t f_04ED2E90;
    uint8_t f_04ED2E94[UINT32_C(0x00000001)];
} SferaDataObject_04ED2E8C;
#define SFERA_DATA_OBJECT_04ED2E8C ((SferaDataObject_04ED2E8C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E8C))))

typedef struct SferaDataObject_04ED2EB8 {
    uint8_t f_04ED2EB8[UINT32_C(0x00000004)];
    uint8_t f_04ED2EBC[UINT32_C(0x00000004)];
    uint8_t f_04ED2EC0[UINT32_C(0x00000004)];
    uint32_t f_04ED2EC4;
    uint32_t f_04ED2EC8;
    uint8_t f_04ED2ECC[UINT32_C(0x00000001)];
} SferaDataObject_04ED2EB8;
#define SFERA_DATA_OBJECT_04ED2EB8 ((SferaDataObject_04ED2EB8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EB8))))

typedef struct SferaDataObject_04ED2F1C {
    uint32_t f_04ED2F1C;
    uint32_t f_04ED2F20;
    uint8_t f_04ED2F24[UINT32_C(0x00000001)];
} SferaDataObject_04ED2F1C;
#define SFERA_DATA_OBJECT_04ED2F1C ((SferaDataObject_04ED2F1C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F1C))))

typedef struct SferaDataObject_04ED2F48 {
    uint32_t f_04ED2F48;
    uint32_t f_04ED2F4C;
    uint8_t f_04ED2F50[UINT32_C(0x00000001)];
} SferaDataObject_04ED2F48;
#define SFERA_DATA_OBJECT_04ED2F48 ((SferaDataObject_04ED2F48*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F48))))

typedef struct SferaDataObject_04ED2F74 {
    uint32_t f_04ED2F74;
    uint32_t f_04ED2F78;
    uint8_t f_04ED2F7C[UINT32_C(0x00000001)];
} SferaDataObject_04ED2F74;
#define SFERA_DATA_OBJECT_04ED2F74 ((SferaDataObject_04ED2F74*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F74))))

typedef struct SferaDataObject_04ED2FE0 {
    uint32_t f_04ED2FE0;
    uint32_t f_04ED2FE4;
    uint8_t f_04ED2FE8[UINT32_C(0x00000001)];
} SferaDataObject_04ED2FE0;
#define SFERA_DATA_OBJECT_04ED2FE0 ((SferaDataObject_04ED2FE0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2FE0))))

typedef struct SferaDataObject_04ED300C {
    uint32_t f_04ED300C;
    uint32_t f_04ED3010;
    uint8_t f_04ED3014[UINT32_C(0x00000001)];
} SferaDataObject_04ED300C;
#define SFERA_DATA_OBJECT_04ED300C ((SferaDataObject_04ED300C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED300C))))

typedef struct SferaDataObject_04ED3070 {
    uint32_t f_04ED3070;
    uint32_t f_04ED3074;
    uint8_t f_04ED3078[UINT32_C(0x00000001)];
} SferaDataObject_04ED3070;
#define SFERA_DATA_OBJECT_04ED3070 ((SferaDataObject_04ED3070*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3070))))

typedef struct SferaDataObject_04ED309C {
    uint32_t f_04ED309C;
    uint32_t f_04ED30A0;
    uint8_t f_04ED30A4[UINT32_C(0x00000001)];
} SferaDataObject_04ED309C;
#define SFERA_DATA_OBJECT_04ED309C ((SferaDataObject_04ED309C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED309C))))

typedef struct SferaDataObject_04ED3100 {
    uint32_t f_04ED3100;
    uint32_t f_04ED3104;
    uint8_t f_04ED3108[UINT32_C(0x00000001)];
} SferaDataObject_04ED3100;
#define SFERA_DATA_OBJECT_04ED3100 ((SferaDataObject_04ED3100*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3100))))

typedef struct SferaDataObject_04ED312C {
    uint8_t f_04ED312C[UINT32_C(0x00000004)];
    uint8_t f_04ED3130[UINT32_C(0x00000004)];
    uint8_t f_04ED3134[UINT32_C(0x00000004)];
    uint32_t f_04ED3138;
} SferaDataObject_04ED312C;
#define SFERA_DATA_OBJECT_04ED312C ((SferaDataObject_04ED312C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED312C))))

typedef struct SferaDataObject_04ED36A0 {
    float f_04ED36A0;
    float f_04ED36A4;
    float f_04ED36A8;
    float f_04ED36AC;
    uint32_t f_04ED36B0;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    float f_04ED36B8;
    float f_04ED36BC;
    float f_04ED36C0;
    float f_04ED36C4;
    float f_04ED36C8;
    float f_04ED36CC;
    uint32_t f_04ED36D0;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    float f_04ED36D8;
    float f_04ED36DC;
    float f_04ED36E0;
    float f_04ED36E4;
    float f_04ED36E8;
    float f_04ED36EC;
    uint32_t f_04ED36F0;
    uint8_t _pad_02[UINT32_C(0x00000004)];
    float f_04ED36F8;
    float f_04ED36FC;
    float f_04ED3700;
    float f_04ED3704;
    float f_04ED3708;
    float f_04ED370C;
    uint32_t f_04ED3710;
    uint8_t _pad_03[UINT32_C(0x00000004)];
    float f_04ED3718;
    float f_04ED371C;
} SferaDataObject_04ED36A0;
#define SFERA_DATA_OBJECT_04ED36A0 ((SferaDataObject_04ED36A0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED36A0))))

typedef struct SferaDataObject_04EDCCA0 {
    uint32_t f_04EDCCA0;
    uint32_t f_04EDCCA4;
    uint8_t f_04EDCCA8[UINT32_C(0x00000001)];
} SferaDataObject_04EDCCA0;
#define SFERA_DATA_OBJECT_04EDCCA0 ((SferaDataObject_04EDCCA0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCCA0))))

typedef struct SferaDataObject_04EDCD58 {
    uint32_t f_04EDCD58;
    uint32_t f_04EDCD5C;
    uint32_t f_04EDCD60;
    uint32_t f_04EDCD64;
    uint32_t f_04EDCD68;
    uint32_t f_04EDCD6C;
    uint8_t f_04EDCD70[UINT32_C(0x00000001)];
    uint8_t _pad_00[UINT32_C(0x00000003)];
    uint32_t f_04EDCD74;
    uint8_t _pad_01[UINT32_C(0x00000008)];
    uint8_t f_04EDCD80[UINT32_C(0x00000004)];
    uint8_t f_04EDCD84[UINT32_C(0x00000004)];
    uint8_t f_04EDCD88[UINT32_C(0x00000004)];
    uint8_t f_04EDCD8C[UINT32_C(0x00000004)];
    uint8_t f_04EDCD90[UINT32_C(0x00000004)];
    uint8_t f_04EDCD94[UINT32_C(0x00000004)];
    uint32_t f_04EDCD98;
} SferaDataObject_04EDCD58;
#define SFERA_DATA_OBJECT_04EDCD58 ((SferaDataObject_04EDCD58*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD58))))

typedef struct SferaDataObject_04EDCDD0 {
    uint32_t f_04EDCDD0;
    uint32_t f_04EDCDD4;
    uint8_t f_04EDCDD8[UINT32_C(0x00000001)];
} SferaDataObject_04EDCDD0;
#define SFERA_DATA_OBJECT_04EDCDD0 ((SferaDataObject_04EDCDD0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCDD0))))

typedef struct SferaDataObject_04EDCDFC {
    uint32_t f_04EDCDFC;
    uint32_t f_04EDCE00;
    uint8_t f_04EDCE04[UINT32_C(0x00000001)];
} SferaDataObject_04EDCDFC;
#define SFERA_DATA_OBJECT_04EDCDFC ((SferaDataObject_04EDCDFC*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCDFC))))

typedef struct SferaDataObject_04EDCE28 {
    uint32_t f_04EDCE28;
    uint32_t f_04EDCE2C;
    uint8_t f_04EDCE30[UINT32_C(0x00000001)];
} SferaDataObject_04EDCE28;
#define SFERA_DATA_OBJECT_04EDCE28 ((SferaDataObject_04EDCE28*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE28))))

typedef struct SferaDataObject_04EDCE54 {
    uint32_t f_04EDCE54;
    uint32_t f_04EDCE58;
    uint8_t f_04EDCE5C[UINT32_C(0x00000001)];
} SferaDataObject_04EDCE54;
#define SFERA_DATA_OBJECT_04EDCE54 ((SferaDataObject_04EDCE54*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE54))))

typedef struct SferaDataObject_04EDCE80 {
    float f_04EDCE80;
    float f_04EDCE84;
    float f_04EDCE88;
    float f_04EDCE8C;
    uint32_t f_04EDCE90;
    uint32_t f_04EDCE94;
    float f_04EDCE98;
    float f_04EDCE9C;
    float f_04EDCEA0;
    float f_04EDCEA4;
    float f_04EDCEA8;
    float f_04EDCEAC;
    uint32_t f_04EDCEB0;
    uint32_t f_04EDCEB4;
    float f_04EDCEB8;
    float f_04EDCEBC;
    float f_04EDCEC0;
    float f_04EDCEC4;
    float f_04EDCEC8;
    float f_04EDCECC;
    uint32_t f_04EDCED0;
    uint32_t f_04EDCED4;
    float f_04EDCED8;
    float f_04EDCEDC;
    float f_04EDCEE0;
    float f_04EDCEE4;
    float f_04EDCEE8;
    float f_04EDCEEC;
    uint32_t f_04EDCEF0;
    uint32_t f_04EDCEF4;
    float f_04EDCEF8;
    float f_04EDCEFC;
    uint8_t f_04EDCF00[UINT32_C(0x00000001)];
} SferaDataObject_04EDCE80;
#define SFERA_DATA_OBJECT_04EDCE80 ((SferaDataObject_04EDCE80*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE80))))

typedef struct SferaDataObject_04EDCF78 {
    uint32_t f_04EDCF78;
    uint32_t f_04EDCF7C;
    uint8_t f_04EDCF80[UINT32_C(0x00000001)];
} SferaDataObject_04EDCF78;
#define SFERA_DATA_OBJECT_04EDCF78 ((SferaDataObject_04EDCF78*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCF78))))

typedef struct SferaDataObject_04EDCFA4 {
    uint32_t f_04EDCFA4;
    uint32_t f_04EDCFA8;
    uint8_t f_04EDCFAC[UINT32_C(0x00000001)];
} SferaDataObject_04EDCFA4;
#define SFERA_DATA_OBJECT_04EDCFA4 ((SferaDataObject_04EDCFA4*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCFA4))))

typedef struct SferaDataObject_04EDD068 { uint8_t storage[UINT32_C(0x00000076)]; } SferaDataObject_04EDD068;
#define SFERA_DATA_OBJECT_04EDD068 ((SferaDataObject_04EDD068*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD068))))

typedef struct SferaDataObject_04EDD270 {
    float f_04EDD270;
    float f_04EDD274;
    uint8_t _pad_00[UINT32_C(0x0000001C)];
    float f_04EDD294;
    uint8_t _pad_01[UINT32_C(0x00000010)];
    uint8_t f_04EDD2A8[UINT32_C(0x00000001)];
} SferaDataObject_04EDD270;
#define SFERA_DATA_OBJECT_04EDD270 ((SferaDataObject_04EDD270*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD270))))

typedef struct SferaDataObject_04EDD308 {
    float f_04EDD308;
    float f_04EDD30C;
    uint8_t _pad_00[UINT32_C(0x0000000C)];
    float f_04EDD31C;
} SferaDataObject_04EDD308;
#define SFERA_DATA_OBJECT_04EDD308 ((SferaDataObject_04EDD308*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD308))))

typedef struct SferaDataObject_04EDD348 {
    float f_04EDD348;
    float f_04EDD34C;
    float f_04EDD350;
    float f_04EDD354;
    float f_04EDD358;
    uint8_t f_04EDD35C[UINT32_C(0x00000004)];
    uint8_t f_04EDD360[UINT32_C(0x00000004)];
    uint8_t f_04EDD364[UINT32_C(0x00000004)];
    uint32_t f_04EDD368;
    uint8_t _pad_00[UINT32_C(0x00000008)];
    uint32_t f_04EDD374;
    uint8_t _pad_01[UINT32_C(0x00000008)];
    uint32_t f_04EDD380;
    uint32_t f_04EDD384;
    uint32_t f_04EDD388;
    uint8_t f_04EDD38C[UINT32_C(0x00000001)];
    uint8_t _pad_02[UINT32_C(0x0000000B)];
    uint8_t f_04EDD398[UINT32_C(0x00000001)];
} SferaDataObject_04EDD348;
#define SFERA_DATA_OBJECT_04EDD348 ((SferaDataObject_04EDD348*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD348))))

typedef struct SferaDataObject_04EDD460 {
    uint32_t f_04EDD460;
    uint8_t f_04EDD464;
} SferaDataObject_04EDD460;
#define SFERA_DATA_OBJECT_04EDD460 ((SferaDataObject_04EDD460*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD460))))

typedef struct SferaDataObject_04EDD590 {
    uint8_t f_04EDD590;
    uint8_t _pad_00[UINT32_C(0x00000007)];
    uint8_t f_04EDD598[UINT32_C(0x00000001)];
} SferaDataObject_04EDD590;
#define SFERA_DATA_OBJECT_04EDD590 ((SferaDataObject_04EDD590*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD590))))

typedef struct SferaDataObject_04EE0478 {
    uint32_t f_04EE0478;
    uint8_t f_04EE047C[UINT32_C(0x00000001)];
    uint8_t _pad_00[UINT32_C(0x0000001B)];
    uint8_t f_04EE0498[UINT32_C(0x00000004)];
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint32_t f_04EE04A0;
    uint8_t _pad_02[UINT32_C(0x00000004)];
    uint32_t f_04EE04A8;
} SferaDataObject_04EE0478;
#define SFERA_DATA_OBJECT_04EE0478 ((SferaDataObject_04EE0478*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EE0478))))

typedef struct SferaDataObject_04EE1104 {
    uint8_t f_04EE1104[UINT32_C(0x00000001)];
    uint8_t _pad_00[UINT32_C(0x0000001F)];
    uint8_t f_04EE1124;
} SferaDataObject_04EE1104;
#define SFERA_DATA_OBJECT_04EE1104 ((SferaDataObject_04EE1104*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EE1104))))

typedef struct SferaDataObject_04EE8158 {
    uint32_t f_04EE8158;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint8_t f_04EE8160;
} SferaDataObject_04EE8158;
#define SFERA_DATA_OBJECT_04EE8158 ((SferaDataObject_04EE8158*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EE8158))))

typedef struct SferaDataObject_04EEA008 {
    uint32_t f_04EEA008;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04EEA010;
} SferaDataObject_04EEA008;
#define SFERA_DATA_OBJECT_04EEA008 ((SferaDataObject_04EEA008*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA008))))

typedef struct SferaDataObject_04EEA0E0 {
    uint32_t f_04EEA0E0;
    uint8_t f_04EEA0E4;
    uint8_t _pad_00[UINT32_C(0x00000003)];
    uint8_t f_04EEA0E8[UINT32_C(0x00000001)];
} SferaDataObject_04EEA0E0;
#define SFERA_DATA_OBJECT_04EEA0E0 ((SferaDataObject_04EEA0E0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA0E0))))

typedef struct SferaDataObject_04EEA128 {
    uint32_t f_04EEA128;
    uint32_t f_04EEA12C;
    uint32_t f_04EEA130;
    uint32_t f_04EEA134;
    uint8_t f_04EEA138[UINT32_C(0x00000001)];
    uint8_t _pad_00[UINT32_C(0x00000017)];
    uint32_t f_04EEA150;
} SferaDataObject_04EEA128;
#define SFERA_DATA_OBJECT_04EEA128 ((SferaDataObject_04EEA128*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA128))))

typedef struct SferaDataObject_04EEA518 {
    uint32_t f_04EEA518;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint8_t f_04EEA520[UINT32_C(0x00000004)];
    uint32_t f_04EEA524;
    uint8_t f_04EEA528;
} SferaDataObject_04EEA518;
#define SFERA_DATA_OBJECT_04EEA518 ((SferaDataObject_04EEA518*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA518))))

typedef struct SferaDataObject_04EEA628 {
    uint32_t f_04EEA628;
    uint32_t f_04EEA62C;
    uint32_t f_04EEA630;
    uint32_t f_04EEA634;
    uint32_t f_04EEA638;
} SferaDataObject_04EEA628;
#define SFERA_DATA_OBJECT_04EEA628 ((SferaDataObject_04EEA628*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA628))))

typedef struct SferaDataObject_04EEAD00 {
    uint32_t f_04EEAD00;
    uint32_t f_04EEAD04;
    uint32_t f_04EEAD08;
    uint32_t f_04EEAD0C;
    uint32_t f_04EEAD10;
} SferaDataObject_04EEAD00;
#define SFERA_DATA_OBJECT_04EEAD00 ((SferaDataObject_04EEAD00*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAD00))))

typedef struct SferaDataObject_04EEB080 {
    uint32_t f_04EEB080;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04EEB088;
} SferaDataObject_04EEB080;
#define SFERA_DATA_OBJECT_04EEB080 ((SferaDataObject_04EEB080*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB080))))

typedef struct SferaDataObject_04EEB158 {
    uint32_t f_04EEB158;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04EEB160;
} SferaDataObject_04EEB158;
#define SFERA_DATA_OBJECT_04EEB158 ((SferaDataObject_04EEB158*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB158))))

typedef struct SferaDataObject_04EEB430 {
    uint32_t f_04EEB430;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04EEB438;
} SferaDataObject_04EEB430;
#define SFERA_DATA_OBJECT_04EEB430 ((SferaDataObject_04EEB430*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB430))))

typedef struct SferaDataObject_04EEB508 {
    uint32_t f_04EEB508;
    uint32_t f_04EEB50C;
    uint32_t f_04EEB510;
} SferaDataObject_04EEB508;
#define SFERA_DATA_OBJECT_04EEB508 ((SferaDataObject_04EEB508*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB508))))

typedef struct SferaDataObject_04EEB5E0 {
    uint32_t f_04EEB5E0;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04EEB5E8;
    uint32_t f_04EEB5EC;
    uint32_t f_04EEB5F0;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint32_t f_04EEB5F8;
    uint32_t f_04EEB5FC;
    uint32_t f_04EEB600;
    uint32_t f_04EEB604;
    uint8_t _pad_02[UINT32_C(0x00000008)];
    uint16_t f_04EEB610;
} SferaDataObject_04EEB5E0;
#define SFERA_DATA_OBJECT_04EEB5E0 ((SferaDataObject_04EEB5E0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB5E0))))

typedef struct SferaDataObject_04F17960 {
    uint32_t f_04F17960;
    uint32_t f_04F17964;
    uint16_t f_04F17968;
} SferaDataObject_04F17960;
#define SFERA_DATA_OBJECT_04F17960 ((SferaDataObject_04F17960*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F17960))))

typedef struct SferaDataObject_04F37968 {
    uint32_t f_04F37968;
    uint32_t f_04F3796C;
    uint32_t f_04F37970;
} SferaDataObject_04F37968;
#define SFERA_DATA_OBJECT_04F37968 ((SferaDataObject_04F37968*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37968))))

typedef struct SferaDataObject_04F379E0 {
    uint32_t f_04F379E0;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04F379E8;
} SferaDataObject_04F379E0;
#define SFERA_DATA_OBJECT_04F379E0 ((SferaDataObject_04F379E0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F379E0))))

typedef struct SferaDataObject_04F37B88 { uint8_t storage[UINT32_C(0x00000008)]; } SferaDataObject_04F37B88;
#define SFERA_DATA_OBJECT_04F37B88 ((SferaDataObject_04F37B88*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37B88))))

typedef struct SferaDataObject_04F37EA8 {
    uint32_t f_04F37EA8;
    uint32_t f_04F37EAC;
    uint32_t f_04F37EB0;
    uint32_t f_04F37EB4;
    uint8_t _pad_00[UINT32_C(0x00000008)];
    uint32_t f_04F37EC0;
    uint32_t f_04F37EC4;
    uint32_t f_04F37EC8;
    uint32_t f_04F37ECC;
    uint32_t f_04F37ED0;
    uint32_t f_04F37ED4;
    uint8_t f_04F37ED8;
} SferaDataObject_04F37EA8;
#define SFERA_DATA_OBJECT_04F37EA8 ((SferaDataObject_04F37EA8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EA8))))

typedef struct SferaDataObject_04F37F3C {
    uint32_t f_04F37F3C;
    uint32_t f_04F37F40;
    uint32_t f_04F37F44;
} SferaDataObject_04F37F3C;
#define SFERA_DATA_OBJECT_04F37F3C ((SferaDataObject_04F37F3C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37F3C))))

typedef struct SferaDataObject_04F383F0 {
    uint32_t f_04F383F0;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04F383F8;
    uint32_t f_04F383FC;
    uint32_t f_04F38400;
} SferaDataObject_04F383F0;
#define SFERA_DATA_OBJECT_04F383F0 ((SferaDataObject_04F383F0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F383F0))))

typedef struct SferaDataObject_04F38800 {
    uint32_t f_04F38800;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04F38808;
    uint8_t _pad_01[UINT32_C(0x0000000C)];
    uint32_t f_04F38818;
} SferaDataObject_04F38800;
#define SFERA_DATA_OBJECT_04F38800 ((SferaDataObject_04F38800*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38800))))

typedef struct SferaDataObject_04F38884 {
    uint32_t f_04F38884;
    uint32_t f_04F38888;
    uint8_t f_04F3888C[UINT32_C(0x00000001)];
} SferaDataObject_04F38884;
#define SFERA_DATA_OBJECT_04F38884 ((SferaDataObject_04F38884*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38884))))

typedef struct SferaDataObject_04F389D8 {
    float f_04F389D8;
    float f_04F389DC;
    uint8_t f_04F389E0;
    uint8_t _pad_00[UINT32_C(0x00000003)];
    uint32_t f_04F389E4;
    uint32_t f_04F389E8;
} SferaDataObject_04F389D8;
#define SFERA_DATA_OBJECT_04F389D8 ((SferaDataObject_04F389D8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F389D8))))

typedef struct SferaDataObject_04F38F28 {
    uint32_t f_04F38F28;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04F38F30;
} SferaDataObject_04F38F28;
#define SFERA_DATA_OBJECT_04F38F28 ((SferaDataObject_04F38F28*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38F28))))

typedef struct SferaDataObject_04F3A460 {
    uint32_t f_04F3A460;
    uint32_t f_04F3A464;
    uint32_t f_04F3A468;
} SferaDataObject_04F3A460;
#define SFERA_DATA_OBJECT_04F3A460 ((SferaDataObject_04F3A460*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A460))))

typedef struct SferaDataObject_04F3A4D4 {
    uint32_t f_04F3A4D4;
    uint32_t f_04F3A4D8;
} SferaDataObject_04F3A4D4;
#define SFERA_DATA_OBJECT_04F3A4D4 ((SferaDataObject_04F3A4D4*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A4D4))))

typedef struct SferaDataObject_04F3AD58 {
    uint32_t f_04F3AD58;
    uint32_t f_04F3AD5C;
    uint32_t f_04F3AD60;
} SferaDataObject_04F3AD58;
#define SFERA_DATA_OBJECT_04F3AD58 ((SferaDataObject_04F3AD58*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3AD58))))

typedef struct SferaDataObject_04F3B080 {
    uint32_t f_04F3B080;
    uint32_t f_04F3B084;
    uint8_t f_04F3B088;
    uint8_t _pad_00[UINT32_C(0x00000003)];
    uint32_t f_04F3B08C;
    uint32_t f_04F3B090;
    uint32_t f_04F3B094;
    uint32_t f_04F3B098;
    uint32_t f_04F3B09C;
    uint32_t f_04F3B0A0;
    uint32_t f_04F3B0A4;
    uint32_t f_04F3B0A8;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint32_t f_04F3B0B0;
} SferaDataObject_04F3B080;
#define SFERA_DATA_OBJECT_04F3B080 ((SferaDataObject_04F3B080*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B080))))

typedef struct SferaDataObject_04F3B11C {
    uint32_t f_04F3B11C;
    uint32_t f_04F3B120;
} SferaDataObject_04F3B11C;
#define SFERA_DATA_OBJECT_04F3B11C ((SferaDataObject_04F3B11C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B11C))))

typedef struct SferaDataObject_04F3B188 {
    uint32_t f_04F3B188;
    uint32_t f_04F3B18C;
    uint32_t f_04F3B190;
    uint32_t f_04F3B194;
    uint32_t f_04F3B198;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04F3B1A0;
    uint32_t f_04F3B1A4;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint32_t f_04F3B1AC;
    uint32_t f_04F3B1B0;
    uint8_t _pad_02[UINT32_C(0x00000004)];
    uint32_t f_04F3B1B8;
    uint32_t f_04F3B1BC;
    uint8_t _pad_03[UINT32_C(0x00000004)];
    uint8_t f_04F3B1C4[UINT32_C(0x00000001)];
    uint8_t _pad_04[UINT32_C(0x00000003)];
    uint8_t f_04F3B1C8[UINT32_C(0x00000001)];
} SferaDataObject_04F3B188;
#define SFERA_DATA_OBJECT_04F3B188 ((SferaDataObject_04F3B188*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B188))))

typedef struct SferaDataObject_04F3B4C0 {
    uint8_t f_04F3B4C0[UINT32_C(0x00000004)];
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint8_t f_04F3B4C8[UINT32_C(0x00000001)];
} SferaDataObject_04F3B4C0;
#define SFERA_DATA_OBJECT_04F3B4C0 ((SferaDataObject_04F3B4C0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B4C0))))

typedef struct SferaDataObject_04F47FA8 {
    uint32_t f_04F47FA8;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04F47FB0;
} SferaDataObject_04F47FA8;
#define SFERA_DATA_OBJECT_04F47FA8 ((SferaDataObject_04F47FA8*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F47FA8))))

typedef struct SferaDataObject_04F48A5C {
    uint32_t f_04F48A5C;
    uint32_t f_04F48A60;
    float f_04F48A64;
    float f_04F48A68;
    uint32_t f_04F48A6C;
    uint32_t f_04F48A70;
} SferaDataObject_04F48A5C;
#define SFERA_DATA_OBJECT_04F48A5C ((SferaDataObject_04F48A5C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48A5C))))

typedef struct SferaDataObject_04F48B6C {
    uint32_t f_04F48B6C;
    uint32_t f_04F48B70;
    uint32_t f_04F48B74;
    uint32_t f_04F48B78;
    uint32_t f_04F48B7C;
    uint32_t f_04F48B80;
    uint32_t f_04F48B84;
    uint32_t f_04F48B88;
    uint32_t f_04F48B8C;
    uint32_t f_04F48B90;
    uint32_t f_04F48B94;
    uint32_t f_04F48B98;
    uint32_t f_04F48B9C;
    uint8_t f_04F48BA0[UINT32_C(0x00000004)];
    uint32_t f_04F48BA4;
    uint32_t f_04F48BA8;
    uint32_t f_04F48BAC;
    uint32_t f_04F48BB0;
    uint32_t f_04F48BB4;
    uint32_t f_04F48BB8;
    uint32_t f_04F48BBC;
    uint32_t f_04F48BC0;
    uint32_t f_04F48BC4;
    uint32_t f_04F48BC8;
    uint32_t f_04F48BCC;
    uint32_t f_04F48BD0;
    uint32_t f_04F48BD4;
    uint32_t f_04F48BD8;
    uint32_t f_04F48BDC;
    uint32_t f_04F48BE0;
    uint32_t f_04F48BE4;
    uint32_t f_04F48BE8;
    uint32_t f_04F48BEC;
    uint8_t f_04F48BF0[UINT32_C(0x00000001)];
} SferaDataObject_04F48B6C;
#define SFERA_DATA_OBJECT_04F48B6C ((SferaDataObject_04F48B6C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B6C))))

typedef struct SferaDataObject_04F499F0 {
    uint32_t f_04F499F0;
    uint8_t _pad_00[UINT32_C(0x0000000C)];
    uint32_t f_04F49A00;
    uint32_t f_04F49A04;
    uint32_t f_04F49A08;
    uint32_t f_04F49A0C;
    uint8_t f_04F49A10[UINT32_C(0x00000001)];
} SferaDataObject_04F499F0;
#define SFERA_DATA_OBJECT_04F499F0 ((SferaDataObject_04F499F0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F499F0))))

typedef struct SferaDataObject_04F49A94 {
    uint32_t f_04F49A94;
    uint32_t f_04F49A98;
    uint32_t f_04F49A9C;
    uint32_t f_04F49AA0;
} SferaDataObject_04F49A94;
#define SFERA_DATA_OBJECT_04F49A94 ((SferaDataObject_04F49A94*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49A94))))

typedef struct SferaDataObject_04F49B70 {
    uint32_t f_04F49B70;
    uint32_t f_04F49B74;
    uint8_t _pad_00[UINT32_C(0x00000008)];
    uint32_t f_04F49B80;
    uint32_t f_04F49B84;
    uint8_t _pad_01[UINT32_C(0x00000008)];
    uint32_t f_04F49B90;
    uint32_t f_04F49B94;
    uint8_t _pad_02[UINT32_C(0x00000008)];
    uint8_t f_04F49BA0[UINT32_C(0x00000001)];
} SferaDataObject_04F49B70;
#define SFERA_DATA_OBJECT_04F49B70 ((SferaDataObject_04F49B70*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B70))))

typedef struct SferaDataObject_04F49F40 {
    uint8_t f_04F49F40[UINT32_C(0x00000004)];
    float f_04F49F44;
    float f_04F49F48;
    float f_04F49F4C;
    uint32_t f_04F49F50;
    uint8_t _pad_00[UINT32_C(0x0000000C)];
    float f_04F49F60;
    float f_04F49F64;
    float f_04F49F68;
    float f_04F49F6C;
    uint32_t f_04F49F70;
    uint8_t _pad_01[UINT32_C(0x0000000C)];
    float f_04F49F80;
    float f_04F49F84;
    float f_04F49F88;
    float f_04F49F8C;
    uint32_t f_04F49F90;
    uint8_t _pad_02[UINT32_C(0x0000000C)];
    float f_04F49FA0;
    float f_04F49FA4;
    float f_04F49FA8;
    float f_04F49FAC;
    uint32_t f_04F49FB0;
    uint8_t _pad_03[UINT32_C(0x0000000C)];
    uint8_t f_04F49FC0[UINT32_C(0x00000001)];
} SferaDataObject_04F49F40;
#define SFERA_DATA_OBJECT_04F49F40 ((SferaDataObject_04F49F40*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49F40))))

typedef struct SferaDataObject_04F4A49C {
    uint32_t f_04F4A49C;
    uint32_t f_04F4A4A0;
} SferaDataObject_04F4A49C;
#define SFERA_DATA_OBJECT_04F4A49C ((SferaDataObject_04F4A49C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A49C))))

typedef struct SferaDataObject_04F4A508 {
    uint8_t f_04F4A508[UINT32_C(0x00000001)];
    uint8_t _pad_00[UINT32_C(0x00000003)];
    uint32_t f_04F4A50C;
    uint32_t f_04F4A510;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint8_t f_04F4A518[UINT32_C(0x00000004)];
    uint8_t _pad_02[UINT32_C(0x00000004)];
    uint32_t f_04F4A520;
} SferaDataObject_04F4A508;
#define SFERA_DATA_OBJECT_04F4A508 ((SferaDataObject_04F4A508*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A508))))

typedef struct SferaDataObject_04F4C5F0 {
    uint32_t f_04F4C5F0;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint8_t f_04F4C5F8[UINT32_C(0x00000001)];
} SferaDataObject_04F4C5F0;
#define SFERA_DATA_OBJECT_04F4C5F0 ((SferaDataObject_04F4C5F0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4C5F0))))

typedef struct SferaDataObject_04F4C6FC {
    uint32_t f_04F4C6FC;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04F4C704;
    uint8_t _pad_01[UINT32_C(0x00000008)];
    uint32_t f_04F4C710;
} SferaDataObject_04F4C6FC;
#define SFERA_DATA_OBJECT_04F4C6FC ((SferaDataObject_04F4C6FC*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4C6FC))))

typedef struct SferaDataObject_04F4C8B0 {
    uint8_t f_04F4C8B0[UINT32_C(0x00000001)];
    uint8_t _pad_00[UINT32_C(0x0000000F)];
    uint8_t f_04F4C8C0[UINT32_C(0x00000004)];
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint32_t f_04F4C8C8;
} SferaDataObject_04F4C8B0;
#define SFERA_DATA_OBJECT_04F4C8B0 ((SferaDataObject_04F4C8B0*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4C8B0))))

typedef struct SferaDataObject_04F4CB38 {
    uint32_t f_04F4CB38;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04F4CB40;
} SferaDataObject_04F4CB38;
#define SFERA_DATA_OBJECT_04F4CB38 ((SferaDataObject_04F4CB38*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CB38))))

typedef struct SferaDataObject_04F4CC10 {
    uint32_t f_04F4CC10;
    uint32_t f_04F4CC14;
    uint32_t f_04F4CC18;
} SferaDataObject_04F4CC10;
#define SFERA_DATA_OBJECT_04F4CC10 ((SferaDataObject_04F4CC10*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CC10))))

typedef struct SferaDataObject_04F4CD94 {
    uint32_t f_04F4CD94;
    uint32_t f_04F4CD98;
    uint32_t f_04F4CD9C;
} SferaDataObject_04F4CD94;
#define SFERA_DATA_OBJECT_04F4CD94 ((SferaDataObject_04F4CD94*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CD94))))

typedef struct SferaDataObject_04F8F770 {
    uint8_t f_04F8F770;
    uint8_t f_04F8F771;
    uint8_t _pad_00[UINT32_C(0x00000002)];
    uint32_t f_04F8F774;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint32_t f_04F8F77C;
    uint8_t f_04F8F780[UINT32_C(0x00000001)];
} SferaDataObject_04F8F770;
#define SFERA_DATA_OBJECT_04F8F770 ((SferaDataObject_04F8F770*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8F770))))

typedef struct SferaDataObject_04F8FAC7 {
    uint8_t f_04F8FAC7;
    uint32_t f_04F8FAC8;
    uint32_t f_04F8FACC;
    uint32_t f_04F8FAD0;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint8_t f_04F8FAD8[UINT32_C(0x00000001)];
} SferaDataObject_04F8FAC7;
#define SFERA_DATA_OBJECT_04F8FAC7 ((SferaDataObject_04F8FAC7*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8FAC7))))

typedef struct SferaDataObject_04F90068 {
    uint8_t f_04F90068;
    uint8_t _pad_00[UINT32_C(0x00000003)];
    uint32_t f_04F9006C;
    uint16_t f_04F90070;
} SferaDataObject_04F90068;
#define SFERA_DATA_OBJECT_04F90068 ((SferaDataObject_04F90068*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90068))))

typedef struct SferaDataObject_04F90370 {
    uint32_t f_04F90370;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint8_t f_04F90378[UINT32_C(0x00000001)];
} SferaDataObject_04F90370;
#define SFERA_DATA_OBJECT_04F90370 ((SferaDataObject_04F90370*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90370))))

typedef struct SferaDataObject_04F903FC {
    uint8_t f_04F903FC[UINT32_C(0x00000001)];
    uint8_t _pad_00[UINT32_C(0x00000017)];
    uint8_t f_04F90414;
    uint8_t f_04F90415;
    uint8_t _pad_01[UINT32_C(0x0000000E)];
    uint32_t f_04F90424;
    uint8_t _pad_02[UINT32_C(0x00000004)];
    uint32_t f_04F9042C;
    uint32_t f_04F90430;
    uint32_t f_04F90434;
} SferaDataObject_04F903FC;
#define SFERA_DATA_OBJECT_04F903FC ((SferaDataObject_04F903FC*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F903FC))))

typedef struct SferaDataObject_04F9076C {
    uint32_t f_04F9076C;
    uint8_t _pad_00[UINT32_C(0x00000004)];
    uint32_t f_04F90774;
    uint8_t _pad_01[UINT32_C(0x00000004)];
    uint32_t f_04F9077C;
    uint8_t _pad_02[UINT32_C(0x00000004)];
    uint32_t f_04F90784;
    uint32_t f_04F90788;
    uint32_t f_04F9078C;
} SferaDataObject_04F9076C;
#define SFERA_DATA_OBJECT_04F9076C ((SferaDataObject_04F9076C*)(void*)((uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F9076C))))

#pragma pack(pop)

/* ===== Recovered static symbols ===== */
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
#define SFERA_STATIC_006BE114_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE114))
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
#define SFERA_STATIC_006BE15C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE15C))
#define SFERA_STATIC_006BE15C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE15C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_006BE1B4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1B4))
#define SFERA_STATIC_006BE1B4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1B4)))

/* data refs=4 u8=4 */
#define SFERA_STATIC_006BE1B8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1B8))
#define SFERA_STATIC_006BE1B8_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1B8)))

/* data refs=3 u8=3 */
#define SFERA_STATIC_006BE1B9_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1B9))
#define SFERA_STATIC_006BE1B9_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1B9)))

/* data refs=4 u8=4 */
#define SFERA_STATIC_006BE1BA_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1BA))
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
#define SFERA_STATIC_006BE1D4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1D4))
#define SFERA_STATIC_006BE1D4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1D4)))

/* data refs=2 u32=4 */
#define SFERA_STATIC_006BE1D8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1D8))
#define SFERA_STATIC_006BE1D8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1D8)))

/* data refs=2 u32=4 */
#define SFERA_STATIC_006BE1DC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1DC))
#define SFERA_STATIC_006BE1DC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1DC)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_006BE1E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1E0))
#define SFERA_STATIC_006BE1E0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1E0)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_006BE1E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE1E8))
#define SFERA_STATIC_006BE1E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE1E8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_006BE2B8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE2B8))
#define SFERA_STATIC_006BE2B8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE2B8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_006BE2BC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE2BC))
#define SFERA_STATIC_006BE2BC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE2BC)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_006BE2C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE2C0))
#define SFERA_STATIC_006BE2C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE2C0)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_006BE2C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE2C8))
#define SFERA_STATIC_006BE2C8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE2C8)))

/* data refs=34 u32=34 */
#define SFERA_STATIC_006BE2CC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE2CC))
#define SFERA_STATIC_006BE2CC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE2CC)))

/* data refs=12 addr=7 u32=5 */
#define SFERA_STATIC_006BE2D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE2D0))
#define SFERA_STATIC_006BE2D0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE2D0)))

/* data refs=147 u32=163 */
#define SFERA_STATIC_006BE2D4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE2D4))
#define SFERA_STATIC_006BE2D4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE2D4)))

/* data refs=11 addr=8 u8=3 */
#define SFERA_STATIC_006BE3C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE3C8))
#define SFERA_STATIC_006BE3C8_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE3C8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_006BE408_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE408))
#define SFERA_STATIC_006BE408_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE408)))

/* data refs=4 u8=4 */
#define SFERA_STATIC_006BE40C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE40C))
#define SFERA_STATIC_006BE40C_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE40C)))

/* data refs=3 u8=3 */
#define SFERA_STATIC_006BE40E_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE40E))
#define SFERA_STATIC_006BE40E_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE40E)))

/* data refs=3 u8=3 */
#define SFERA_STATIC_006BE40F_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE40F))
#define SFERA_STATIC_006BE40F_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE40F)))

/* data refs=7 u32=9 */
#define SFERA_STATIC_006BE410_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE410))
#define SFERA_STATIC_006BE410_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE410)))

/* data refs=26 u32=26 */
#define SFERA_STATIC_006BE414_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE414))
#define SFERA_STATIC_006BE414_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE414)))

/* data refs=54 addr=52 u8=2 */
#define SFERA_STATIC_006BE618_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BE618))
#define SFERA_STATIC_006BE618_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BE618)))

/* data refs=6 addr=1 u32=3 u8=2 */
#define SFERA_STATIC_006BEC00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x006BEC00))
#define SFERA_STATIC_006BEC00_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x006BEC00)))

/* data refs=20 u32=19 */
#define SFERA_STATIC_00916E40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00916E40))
#define SFERA_STATIC_00916E40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00916E40)))

/* data refs=8 addr=2 u8=6 */
#define SFERA_STATIC_00916E48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00916E48))

/* data refs=2 u16=2 */
#define SFERA_STATIC_00916E4B_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00916E4B))

/* data refs=128 u32=162 */
#define SFERA_STATIC_0091756C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0091756C))
#define SFERA_STATIC_0091756C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0091756C)))

/* data refs=9 addr=8 u8=1 */
#define SFERA_STATIC_00917570_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00917570))

/* data refs=26 u32=26 */
#define SFERA_STATIC_00B6F8B0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6F8B0))
#define SFERA_STATIC_00B6F8B0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00B6F8B0)))

/* data refs=35 u32=35 */
#define SFERA_STATIC_00B6F8B4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6F8B4))
#define SFERA_STATIC_00B6F8B4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00B6F8B4)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_00B6F8B8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6F8B8))
#define SFERA_STATIC_00B6F8B8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00B6F8B8)))

/* data refs=25 u32=25 */
#define SFERA_STATIC_00B6F8BC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6F8BC))
#define SFERA_STATIC_00B6F8BC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00B6F8BC)))

/* data refs=3 addr=2 u8=1 */
#define SFERA_STATIC_00B6F8C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6F8C0))
#define SFERA_STATIC_00B6F8C0_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00B6F8C0)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_00B6F8E4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6F8E4))

/* data refs=12 u32=14 */
#define SFERA_STATIC_00B6F9E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6F9E8))
#define SFERA_STATIC_00B6F9E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00B6F9E8)))

/* data refs=8 addr=2 u32=6 */
#define SFERA_STATIC_00B6F9EC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6F9EC))
#define SFERA_STATIC_00B6F9EC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00B6F9EC)))

/* data refs=26 addr=26 */
#define SFERA_STATIC_00B6F9F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6F9F0))

/* data refs=3 addr=3 */
#define SFERA_STATIC_00B6FA00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FA00))

/* data refs=5 u32=5 */
#define SFERA_STATIC_00B6FA34_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FA34))

/* data refs=2 u32=2 */
#define SFERA_STATIC_00B6FA38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FA38))

/* data refs=6 u32=6 */
#define SFERA_STATIC_00B6FA40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FA40))

/* data refs=26 u32=26 */
#define SFERA_STATIC_00B6FA5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FA5C))

/* data refs=6 u32=6 */
#define SFERA_STATIC_00B6FA60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FA60))

/* data refs=4 u32=8 */
#define SFERA_STATIC_00B6FA84_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FA84))

/* data refs=30 u32=30 */
#define SFERA_STATIC_00B6FAA4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FAA4))

/* data refs=2 u8=2 */
#define SFERA_STATIC_00B6FAA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FAA8))

/* data refs=3 u32=3 */
#define SFERA_STATIC_00B6FAB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FAB8))

/* data refs=2 u32=2 */
#define SFERA_STATIC_00B6FABC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FABC))

/* data refs=7 u16=7 */
#define SFERA_STATIC_00B6FCC4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FCC4))
#define SFERA_STATIC_00B6FCC4_U16 (*(uint16_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00B6FCC4)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_00B6FCD4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00B6FCD4))

/* data refs=5 addr=1 u32=4 */
#define SFERA_STATIC_03FEF9F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x03FEF9F0))
#define SFERA_STATIC_03FEF9F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x03FEF9F0)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_03FEF9F4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x03FEF9F4))
#define SFERA_STATIC_03FEF9F4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x03FEF9F4)))

/* data refs=6 addr=3 u32=3 */
#define SFERA_STATIC_03FEF9F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x03FEF9F8))

/* data refs=12 u32=12 */
#define SFERA_STATIC_040070F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x040070F8))
#define SFERA_STATIC_040070F8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x040070F8)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_040070FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x040070FC))
#define SFERA_STATIC_040070FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x040070FC)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04007100_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04007100))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04007124_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04007124))

/* data refs=18 u32=18 */
#define SFERA_STATIC_0400722C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0400722C))
#define SFERA_STATIC_0400722C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0400722C)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04007230_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04007230))
#define SFERA_STATIC_04007230_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04007230)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04007234_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04007234))
#define SFERA_STATIC_04007234_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04007234)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04007238_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04007238))

/* data refs=10 u32=12 */
#define SFERA_STATIC_04007638_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04007638))
#define SFERA_STATIC_04007638_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04007638)))

/* data refs=23 u32=23 */
#define SFERA_STATIC_0400763C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0400763C))
#define SFERA_STATIC_0400763C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0400763C)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04007640_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04007640))
#define SFERA_STATIC_04007640_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04007640)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04007644_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04007644))
#define SFERA_STATIC_04007644_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04007644)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04007670_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04007670))
#define SFERA_STATIC_04007670_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04007670)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04007674_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04007674))
#define SFERA_STATIC_04007674_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04007674)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04007678_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04007678))

/* data refs=2 u32=2 */
#define SFERA_STATIC_040076F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x040076F0))

/* data refs=3 addr=3 */
#define SFERA_STATIC_040076F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x040076F8))

/* data refs=4 u32=8 */
#define SFERA_STATIC_04008378_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04008378))

/* data refs=6 u32=12 */
#define SFERA_STATIC_0400837C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0400837C))

/* data refs=6 u32=12 */
#define SFERA_STATIC_04008380_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04008380))

/* data refs=16 addr=2 u32=14 */
#define SFERA_STATIC_04013F00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04013F00))
#define SFERA_STATIC_04013F00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04013F00)))

/* data refs=12 addr=9 u16=1 u8=2 */
#define SFERA_STATIC_04013F08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04013F08))
#define SFERA_STATIC_04013F08_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04013F08)))
#define SFERA_STATIC_04013F08_U16 (*(uint16_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04013F08)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04016618_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04016618))
#define SFERA_STATIC_04016618_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04016618)))

/* data refs=65 u32=71 */
#define SFERA_STATIC_0401661C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401661C))
#define SFERA_STATIC_0401661C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0401661C)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04016620_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04016620))
#define SFERA_STATIC_04016620_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04016620)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04016628_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04016628))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04016680_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04016680))
#define SFERA_STATIC_04016680_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04016680)))

/* data refs=27 u32=27 */
#define SFERA_STATIC_04016684_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04016684))
#define SFERA_STATIC_04016684_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04016684)))

/* data refs=5 u32=4 u8=1 */
#define SFERA_STATIC_04016688_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04016688))

/* data refs=30 addr=25 u32=5 */
#define SFERA_STATIC_0401A668_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A668))

/* data refs=4 u32=4 */
#define SFERA_STATIC_0401A670_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A670))

/* data refs=3 u32=3 */
#define SFERA_STATIC_0401A674_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A674))

/* data refs=2 u32=2 */
#define SFERA_STATIC_0401A678_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A678))

/* data refs=14 addr=1 f32=1 u32=21 */
#define SFERA_STATIC_0401A67C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A67C))

/* data refs=111 addr=34 u32=73 u8=4 */
#define SFERA_STATIC_0401A688_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A688))

/* data refs=56 u32=56 */
#define SFERA_STATIC_0401A690_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A690))

/* data refs=55 u32=55 */
#define SFERA_STATIC_0401A694_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A694))

/* data refs=55 u32=55 */
#define SFERA_STATIC_0401A698_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A698))

/* data refs=75 addr=6 f32=6 u32=65 u8=4 */
#define SFERA_STATIC_0401A69C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A69C))

/* data refs=3 u32=3 */
#define SFERA_STATIC_0401A6A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A6A0))

/* data refs=3 u32=3 */
#define SFERA_STATIC_0401A6A4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401A6A4))

/* data refs=2 u32=2 */
#define SFERA_STATIC_0401C5C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401C5C8))
#define SFERA_STATIC_0401C5C8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0401C5C8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_0401C5D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401C5D0))
#define SFERA_STATIC_0401C5D0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0401C5D0)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_0401C5D4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401C5D4))
#define SFERA_STATIC_0401C5D4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0401C5D4)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_0401C5D8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401C5D8))
#define SFERA_STATIC_0401C5D8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0401C5D8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_0401C5DC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401C5DC))
#define SFERA_STATIC_0401C5DC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0401C5DC)))

/* data refs=16 addr=11 u8=5 */
#define SFERA_STATIC_0401C688_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x0401C688))

/* data refs=9 addr=3 u32=6 */
#define SFERA_STATIC_048F4688_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F4688))
#define SFERA_STATIC_048F4688_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x048F4688)))

/* data refs=9 addr=3 u32=6 */
#define SFERA_STATIC_048F468C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F468C))
#define SFERA_STATIC_048F468C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x048F468C)))

/* data refs=5 u8=5 */
#define SFERA_STATIC_048F4690_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F4690))

/* data refs=23 u32=23 */
#define SFERA_STATIC_048F5694_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F5694))
#define SFERA_STATIC_048F5694_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x048F5694)))

/* data refs=22 u32=23 */
#define SFERA_STATIC_048F5A98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F5A98))
#define SFERA_STATIC_048F5A98_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x048F5A98)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_048F5A9C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F5A9C))
#define SFERA_STATIC_048F5A9C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x048F5A9C)))

/* data refs=254 u32=286 */
#define SFERA_STATIC_048F5B04_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F5B04))
#define SFERA_STATIC_048F5B04_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x048F5B04)))

/* data refs=3 u32=5 */
#define SFERA_STATIC_048F5B08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F5B08))
#define SFERA_STATIC_048F5B08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x048F5B08)))

/* data refs=24 u32=24 */
#define SFERA_STATIC_048F5B10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F5B10))
#define SFERA_STATIC_048F5B10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x048F5B10)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_048F5B14_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F5B14))
#define SFERA_STATIC_048F5B14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x048F5B14)))

/* data refs=7 addr=7 */
#define SFERA_STATIC_048F5B18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F5B18))

/* data refs=4 addr=4 */
#define SFERA_STATIC_048F5B58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x048F5B58))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04905B5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04905B5C))
#define SFERA_STATIC_04905B5C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04905B5C)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04B5DDA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04B5DDA0))
#define SFERA_STATIC_04B5DDA0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04B5DDA0)))

/* data refs=104 u32=104 */
#define SFERA_STATIC_04B5DDA4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04B5DDA4))
#define SFERA_STATIC_04B5DDA4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04B5DDA4)))

/* data refs=4 addr=1 u32=3 */
#define SFERA_STATIC_04B5DDA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04B5DDA8))

/* data refs=455 addr=1 u32=454 */
#define SFERA_STATIC_04B5FE78_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04B5FE78))
#define SFERA_STATIC_04B5FE78_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04B5FE78)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04B5FE80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04B5FE80))

/* data refs=9 addr=7 u8=2 */
#define SFERA_STATIC_04B60280_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04B60280))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04B602C4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04B602C4))
#define SFERA_STATIC_04B602C4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04B602C4)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04B602C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04B602C8))
#define SFERA_STATIC_04B602C8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04B602C8)))

/* data refs=413 u32=413 */
#define SFERA_STATIC_04B602CC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04B602CC))
#define SFERA_STATIC_04B602CC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04B602CC)))

/* data refs=7 addr=7 */
#define SFERA_STATIC_04B602D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04B602D0))

/* data refs=16 addr=15 u8=1 */
#define SFERA_STATIC_04B64150_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04B64150))

/* data refs=2 addr=1 u16=1 */
#define SFERA_STATIC_04DBC390_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC390))

/* data refs=3 u32=5 */
#define SFERA_STATIC_04DBC430_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC430))
#define SFERA_STATIC_04DBC430_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC430)))

/* data refs=45 u32=45 */
#define SFERA_STATIC_04DBC434_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC434))
#define SFERA_STATIC_04DBC434_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC434)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04DBC438_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC438))
#define SFERA_STATIC_04DBC438_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC438)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04DBC43C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC43C))
#define SFERA_STATIC_04DBC43C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC43C)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04DBC440_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC440))
#define SFERA_STATIC_04DBC440_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC440)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DBC444_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC444))
#define SFERA_STATIC_04DBC444_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC444)))

/* data refs=16 u32=16 */
#define SFERA_STATIC_04DBC458_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC458))
#define SFERA_STATIC_04DBC458_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC458)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04DBC464_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC464))
#define SFERA_STATIC_04DBC464_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC464)))

/* data refs=4 u32=8 */
#define SFERA_STATIC_04DBC468_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC468))
#define SFERA_STATIC_04DBC468_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC468)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04DBC470_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC470))
#define SFERA_STATIC_04DBC470_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC470)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04DBC488_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC488))
#define SFERA_STATIC_04DBC488_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DBC488)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DBC48C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DBC48C))
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
#define SFERA_STATIC_04DC0688_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DC0688))
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
#define SFERA_STATIC_04DC06A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DC06A8))
#define SFERA_STATIC_04DC06A8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DC06A8)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DC06AC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DC06AC))
#define SFERA_STATIC_04DC06AC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DC06AC)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DC06B0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DC06B0))
#define SFERA_STATIC_04DC06B0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DC06B0)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04DD0A20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0A20))
#define SFERA_STATIC_04DD0A20_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0A20)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD0AF8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0AF8))
#define SFERA_STATIC_04DD0AF8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0AF8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD0B24_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0B24))
#define SFERA_STATIC_04DD0B24_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B24)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD0B50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0B50))
#define SFERA_STATIC_04DD0B50_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B50)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04DD0B80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0B80))
#define SFERA_STATIC_04DD0B80_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B80)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04DD0C50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0C50))
#define SFERA_STATIC_04DD0C50_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0C50)))

/* data refs=3 u32=5 */
#define SFERA_STATIC_04DD0C54_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0C54))
#define SFERA_STATIC_04DD0C54_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0C54)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD0C5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0C5C))
#define SFERA_STATIC_04DD0C5C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0C5C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD0C60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0C60))
#define SFERA_STATIC_04DD0C60_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0C60)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DD0C64_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD0C64))
#define SFERA_STATIC_04DD0C64_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0C64)))

/* data refs=5 u8=5 */
#define SFERA_STATIC_04DD1068_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1068))
#define SFERA_STATIC_04DD1068_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1068)))

/* data refs=3 u8=3 */
#define SFERA_STATIC_04DD1069_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1069))
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
#define SFERA_STATIC_04DD1270_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1270))
#define SFERA_STATIC_04DD1270_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1270)))

/* data refs=3 addr=2 u32=1 */
#define SFERA_STATIC_04DD1274_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1274))
#define SFERA_STATIC_04DD1274_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1274)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD1288_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1288))
#define SFERA_STATIC_04DD1288_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1288)))

/* data refs=9 u32=15 */
#define SFERA_STATIC_04DD128C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD128C))
#define SFERA_STATIC_04DD128C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD128C)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DD1290_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1290))
#define SFERA_STATIC_04DD1290_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1290)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04DD1294_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1294))
#define SFERA_STATIC_04DD1294_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1294)))

/* data refs=15 u32=19 */
#define SFERA_STATIC_04DD1298_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD1298))
#define SFERA_STATIC_04DD1298_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD1298)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD129C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD129C))
#define SFERA_STATIC_04DD129C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD129C)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04DD12A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD12A0))
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
#define SFERA_STATIC_04DD54AC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD54AC))
#define SFERA_STATIC_04DD54AC_U16 (*(uint16_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD54AC)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04DD57D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57D0))
#define SFERA_STATIC_04DD57D0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57D0)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DD57DC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57DC))
#define SFERA_STATIC_04DD57DC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57DC)))

/* data refs=16 addr=11 f32=16 */
#define SFERA_STATIC_04DD57E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57E0))
#define SFERA_STATIC_04DD57E0_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57E0)))

/* data refs=20 u32=28 */
#define SFERA_STATIC_04DD57E4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57E4))
#define SFERA_STATIC_04DD57E4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57E4)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD57E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57E8))
#define SFERA_STATIC_04DD57E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57E8)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD57EC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57EC))
#define SFERA_STATIC_04DD57EC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57EC)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD57F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57F0))
#define SFERA_STATIC_04DD57F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57F0)))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04DD57F4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57F4))

/* data refs=17 addr=17 f32=17 */
#define SFERA_STATIC_04DD57F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57F8))

/* data refs=7 addr=1 u32=6 */
#define SFERA_STATIC_04DD57FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD57FC))
#define SFERA_STATIC_04DD57FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD57FC)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD5800_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5800))
#define SFERA_STATIC_04DD5800_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5800)))

/* data refs=7 u32=5 u8=2 */
#define SFERA_STATIC_04DD5804_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5804))
#define SFERA_STATIC_04DD5804_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5804)))
#define SFERA_STATIC_04DD5804_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5804)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD5808_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5808))
#define SFERA_STATIC_04DD5808_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5808)))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04DD580C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD580C))

/* data refs=11 addr=2 f32=11 */
#define SFERA_STATIC_04DD5810_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5810))
#define SFERA_STATIC_04DD5810_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5810)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD5814_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5814))
#define SFERA_STATIC_04DD5814_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5814)))

/* data refs=19 u32=19 */
#define SFERA_STATIC_04DD5818_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5818))
#define SFERA_STATIC_04DD5818_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5818)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD581C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD581C))
#define SFERA_STATIC_04DD581C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD581C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD5828_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5828))
#define SFERA_STATIC_04DD5828_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5828)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD582C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD582C))
#define SFERA_STATIC_04DD582C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD582C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD5830_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5830))
#define SFERA_STATIC_04DD5830_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5830)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04DD5834_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5834))
#define SFERA_STATIC_04DD5834_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5834)))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04DD5838_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5838))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04DD5839_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5839))

/* data refs=30 u32=30 */
#define SFERA_STATIC_04DD5A38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD5A38))
#define SFERA_STATIC_04DD5A38_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD5A38)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04DD7A40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7A40))
#define SFERA_STATIC_04DD7A40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7A40)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD7A48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7A48))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD7C28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C28))
#define SFERA_STATIC_04DD7C28_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7C28)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD7C30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C30))
#define SFERA_STATIC_04DD7C30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7C30)))

/* data refs=15 addr=15 f32=15 */
#define SFERA_STATIC_04DD7C34_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C34))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04DD7C38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C38))

/* data refs=4 u32=8 */
#define SFERA_STATIC_04DD7C3C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C3C))
#define SFERA_STATIC_04DD7C3C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7C3C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD7C40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C40))
#define SFERA_STATIC_04DD7C40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD7C40)))

/* data refs=14 u32=14 */
#define SFERA_STATIC_04DD7C4C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD7C4C))
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
#define SFERA_STATIC_04DD8A2C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8A2C))
#define SFERA_STATIC_04DD8A2C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8A2C)))

/* data refs=16 addr=16 f32=16 */
#define SFERA_STATIC_04DD8A30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8A30))

/* data refs=5 addr=3 u32=2 */
#define SFERA_STATIC_04DD8A38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8A38))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04DD8B00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8B00))
#define SFERA_STATIC_04DD8B00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B00)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD8B10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8B10))
#define SFERA_STATIC_04DD8B10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B10)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD8B14_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8B14))
#define SFERA_STATIC_04DD8B14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B14)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD8B18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8B18))
#define SFERA_STATIC_04DD8B18_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B18)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04DD8B1C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8B1C))
#define SFERA_STATIC_04DD8B1C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B1C)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04DD8B20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8B20))
#define SFERA_STATIC_04DD8B20_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B20)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD8B24_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8B24))
#define SFERA_STATIC_04DD8B24_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B24)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DD8B28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8B28))
#define SFERA_STATIC_04DD8B28_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD8B28)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04DD8B30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8B30))

/* data refs=11 addr=11 f32=11 */
#define SFERA_STATIC_04DD8B34_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD8B34))

/* data refs=6 addr=1 u32=5 */
#define SFERA_STATIC_04DD9170_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD9170))
#define SFERA_STATIC_04DD9170_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD9170)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04DD93B8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD93B8))
#define SFERA_STATIC_04DD93B8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD93B8)))

/* data refs=16 u32=20 */
#define SFERA_STATIC_04DD93BC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD93BC))
#define SFERA_STATIC_04DD93BC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD93BC)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04DD93C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DD93C0))
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
#define SFERA_STATIC_04DDF9E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDF9E8))
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
#define SFERA_STATIC_04DDFA04_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDFA04))
#define SFERA_STATIC_04DDFA04_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDFA04)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DDFA08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDFA08))
#define SFERA_STATIC_04DDFA08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDFA08)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04DDFA0C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDFA0C))
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
#define SFERA_STATIC_04DDFE1C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDFE1C))
#define SFERA_STATIC_04DDFE1C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DDFE1C)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04DDFE28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DDFE28))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04DE04B8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DE04B8))
#define SFERA_STATIC_04DE04B8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DE04B8)))

/* data refs=13 u32=13 */
#define SFERA_STATIC_04DE04BC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DE04BC))
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
#define SFERA_STATIC_04DE1154_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DE1154))
#define SFERA_STATIC_04DE1154_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DE1154)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04DE1158_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DE1158))
#define SFERA_STATIC_04DE1158_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DE1158)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04DE1170_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04DE1170))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E01170_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E01170))
#define SFERA_STATIC_04E01170_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E01170)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E01174_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E01174))
#define SFERA_STATIC_04E01174_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E01174)))

/* data refs=10 addr=7 u32=1 u8=2 */
#define SFERA_STATIC_04E0117C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E0117C))
#define SFERA_STATIC_04E0117C_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E0117C)))
#define SFERA_STATIC_04E0117C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E0117C)))

/* data refs=15 u32=15 */
#define SFERA_STATIC_04E01188_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E01188))
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
#define SFERA_STATIC_04E01674_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E01674))
#define SFERA_STATIC_04E01674_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E01674)))

/* data refs=62 addr=1 u32=61 */
#define SFERA_STATIC_04E0168C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E0168C))
#define SFERA_STATIC_04E0168C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E0168C)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04E01690_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E01690))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04E01694_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E01694))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04E1CF30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1CF30))
#define SFERA_STATIC_04E1CF30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1CF30)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E1CF34_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1CF34))
#define SFERA_STATIC_04E1CF34_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1CF34)))

/* data refs=13 u32=13 */
#define SFERA_STATIC_04E1CF3C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1CF3C))
#define SFERA_STATIC_04E1CF3C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1CF3C)))

/* data refs=13 u32=13 */
#define SFERA_STATIC_04E1CF44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1CF44))
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
#define SFERA_STATIC_04E1DC00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DC00))
#define SFERA_STATIC_04E1DC00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DC00)))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04E1DC04_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DC04))

/* data refs=3 u32=5 */
#define SFERA_STATIC_04E1DC08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DC08))
#define SFERA_STATIC_04E1DC08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DC08)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E1DC0C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DC0C))
#define SFERA_STATIC_04E1DC0C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DC0C)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04E1DD14_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DD14))
#define SFERA_STATIC_04E1DD14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DD14)))

/* data refs=6 u32=10 */
#define SFERA_STATIC_04E1DD20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DD20))
#define SFERA_STATIC_04E1DD20_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DD20)))

/* data refs=26 u32=26 */
#define SFERA_STATIC_04E1DD24_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DD24))
#define SFERA_STATIC_04E1DD24_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DD24)))

/* data refs=100 u32=100 */
#define SFERA_STATIC_04E1DD28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DD28))
#define SFERA_STATIC_04E1DD28_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DD28)))

/* data refs=10 u32=18 */
#define SFERA_STATIC_04E1DD2C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DD2C))
#define SFERA_STATIC_04E1DD2C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E1DD2C)))

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
#define SFERA_STATIC_04E1DE1C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E1DE1C))
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
#define SFERA_STATIC_04E2BFA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2BFA8))
#define SFERA_STATIC_04E2BFA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2BFA8)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04E2C0B0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C0B0))
#define SFERA_STATIC_04E2C0B0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C0B0)))

/* data refs=2 u32=4 */
#define SFERA_STATIC_04E2C0B4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C0B4))
#define SFERA_STATIC_04E2C0B4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C0B4)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04E2C0B8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C0B8))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04E2C130_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C130))
#define SFERA_STATIC_04E2C130_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C130)))

/* data refs=19 addr=19 f32=19 */
#define SFERA_STATIC_04E2C134_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C134))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04E2C138_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C138))
#define SFERA_STATIC_04E2C138_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C138)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E2C13C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C13C))
#define SFERA_STATIC_04E2C13C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C13C)))

/* data refs=7 u32=9 */
#define SFERA_STATIC_04E2C140_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C140))
#define SFERA_STATIC_04E2C140_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C140)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04E2C144_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C144))
#define SFERA_STATIC_04E2C144_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C144)))

/* data refs=23 u32=23 */
#define SFERA_STATIC_04E2C550_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C550))
#define SFERA_STATIC_04E2C550_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C550)))

/* data refs=16 u32=16 */
#define SFERA_STATIC_04E2C898_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C898))
#define SFERA_STATIC_04E2C898_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C898)))

/* data refs=4 addr=2 u8=2 */
#define SFERA_STATIC_04E2C89C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C89C))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E2C8BC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C8BC))
#define SFERA_STATIC_04E2C8BC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C8BC)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E2C8C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C8C0))
#define SFERA_STATIC_04E2C8C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C8C0)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04E2C8C4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C8C4))
#define SFERA_STATIC_04E2C8C4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C8C4)))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04E2C8D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C8D0))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04E2C8D4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C8D4))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E2C8D8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C8D8))
#define SFERA_STATIC_04E2C8D8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C8D8)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04E2C8DC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C8DC))
#define SFERA_STATIC_04E2C8DC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C8DC)))

/* data refs=18 addr=18 f32=1 */
#define SFERA_STATIC_04E2C8E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C8E0))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04E2C940_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C940))
#define SFERA_STATIC_04E2C940_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C940)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E2C944_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C944))
#define SFERA_STATIC_04E2C944_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2C944)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E2C948_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2C948))
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
#define SFERA_STATIC_04E2CA44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2CA44))
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
#define SFERA_STATIC_04E2DC5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DC5C))
#define SFERA_STATIC_04E2DC5C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2DC5C)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04E2DC60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DC60))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04E2DE08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DE08))

/* data refs=19 u32=19 */
#define SFERA_STATIC_04E2DE10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DE10))
#define SFERA_STATIC_04E2DE10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E2DE10)))

/* data refs=6 addr=3 u16=3 */
#define SFERA_STATIC_04E2DE18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DE18))

/* data refs=3 u16=3 */
#define SFERA_STATIC_04E2DE1A_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DE1A))

/* data refs=3 u16=3 */
#define SFERA_STATIC_04E2DE1C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2DE1C))

/* data refs=13 u32=13 */
#define SFERA_STATIC_04E2E2BC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2E2BC))
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
#define SFERA_STATIC_04E2E3B4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E2E3B4))
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
#define SFERA_STATIC_04E509DD_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E509DD))
#define SFERA_STATIC_04E509DD_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E509DD)))

/* data refs=5 u8=5 */
#define SFERA_STATIC_04E509EA_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E509EA))
#define SFERA_STATIC_04E509EA_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E509EA)))

/* data refs=5 u8=5 */
#define SFERA_STATIC_04E509F6_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E509F6))
#define SFERA_STATIC_04E509F6_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E509F6)))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04E509F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E509F8))
#define SFERA_STATIC_04E509F8_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E509F8)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04E50AC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E50AC0))
#define SFERA_STATIC_04E50AC0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E50AC0)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E50AC4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E50AC4))
#define SFERA_STATIC_04E50AC4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E50AC4)))

/* data refs=11 u32=13 */
#define SFERA_STATIC_04E50ACC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E50ACC))
#define SFERA_STATIC_04E50ACC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E50ACC)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04E50AD0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E50AD0))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E51480_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E51480))

/* data refs=34 u32=34 */
#define SFERA_STATIC_04E51ED0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E51ED0))
#define SFERA_STATIC_04E51ED0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E51ED0)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E51ED4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E51ED4))
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
#define SFERA_STATIC_04E51F50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E51F50))
#define SFERA_STATIC_04E51F50_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E51F50)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04E5215C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E5215C))
#define SFERA_STATIC_04E5215C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E5215C)))

/* data refs=18 u32=18 */
#define SFERA_STATIC_04E522F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E522F0))
#define SFERA_STATIC_04E522F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E522F0)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E522F4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E522F4))
#define SFERA_STATIC_04E522F4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E522F4)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E522FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E522FC))
#define SFERA_STATIC_04E522FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E522FC)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E52300_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E52300))
#define SFERA_STATIC_04E52300_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E52300)))

/* data refs=21 u32=25 */
#define SFERA_STATIC_04E52304_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E52304))
#define SFERA_STATIC_04E52304_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E52304)))

/* data refs=4 addr=2 u16=4 */
#define SFERA_STATIC_04E52308_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E52308))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E72308_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E72308))
#define SFERA_STATIC_04E72308_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E72308)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E72310_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E72310))
#define SFERA_STATIC_04E72310_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E72310)))

/* data refs=21 addr=11 u16=5 u32=1 u8=4 */
#define SFERA_STATIC_04E72314_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E72314))
#define SFERA_STATIC_04E72314_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E72314)))
#define SFERA_STATIC_04E72314_U16 (*(uint16_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E72314)))
#define SFERA_STATIC_04E72314_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E72314)))

/* data refs=5 u8=5 */
#define SFERA_STATIC_04E72316_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E72316))
#define SFERA_STATIC_04E72316_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E72316)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04E7231C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E7231C))
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
#define SFERA_STATIC_04E73320_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E73320))
#define SFERA_STATIC_04E73320_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E73320)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E73324_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E73324))
#define SFERA_STATIC_04E73324_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E73324)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E769D8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E769D8))
#define SFERA_STATIC_04E769D8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E769D8)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E769DC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E769DC))
#define SFERA_STATIC_04E769DC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E769DC)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E769E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E769E0))
#define SFERA_STATIC_04E769E0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E769E0)))

/* data refs=19 addr=19 f32=19 */
#define SFERA_STATIC_04E769E4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E769E4))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E769FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E769FC))
#define SFERA_STATIC_04E769FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E769FC)))

/* data refs=4 u32=8 */
#define SFERA_STATIC_04E76A00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E76A00))
#define SFERA_STATIC_04E76A00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E76A00)))

/* data refs=8 u32=7 u8=1 */
#define SFERA_STATIC_04E76A04_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E76A04))
#define SFERA_STATIC_04E76A04_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E76A04)))
#define SFERA_STATIC_04E76A04_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E76A04)))

/* data refs=30 u32=30 */
#define SFERA_STATIC_04E78A08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78A08))
#define SFERA_STATIC_04E78A08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78A08)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04E78A10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78A10))
#define SFERA_STATIC_04E78A10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78A10)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04E78A18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78A18))
#define SFERA_STATIC_04E78A18_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78A18)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E78A90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78A90))
#define SFERA_STATIC_04E78A90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78A90)))

/* data refs=2 u32=1 u8=1 */
#define SFERA_STATIC_04E78A94_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78A94))
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
#define SFERA_STATIC_04E78D8C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78D8C))
#define SFERA_STATIC_04E78D8C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78D8C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E78D90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78D90))
#define SFERA_STATIC_04E78D90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78D90)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E78D94_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78D94))
#define SFERA_STATIC_04E78D94_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78D94)))

/* data refs=2 u16=1 u32=1 */
#define SFERA_STATIC_04E78D98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78D98))
#define SFERA_STATIC_04E78D98_U16 (*(uint16_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78D98)))
#define SFERA_STATIC_04E78D98_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78D98)))

/* data refs=9 addr=8 f32=9 */
#define SFERA_STATIC_04E78DA4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78DA4))
#define SFERA_STATIC_04E78DA4_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78DA4)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04E78DA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78DA8))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E78F8C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78F8C))
#define SFERA_STATIC_04E78F8C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78F8C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E78F90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78F90))
#define SFERA_STATIC_04E78F90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78F90)))

/* data refs=6 addr=6 f32=5 */
#define SFERA_STATIC_04E78F98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78F98))

/* data refs=11 addr=11 f32=10 */
#define SFERA_STATIC_04E78F9C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78F9C))

/* data refs=15 addr=1 u32=14 */
#define SFERA_STATIC_04E78FA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78FA0))
#define SFERA_STATIC_04E78FA0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78FA0)))

/* data refs=2 u32=1 u8=1 */
#define SFERA_STATIC_04E78FA4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78FA4))
#define SFERA_STATIC_04E78FA4_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78FA4)))
#define SFERA_STATIC_04E78FA4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78FA4)))

/* data refs=29 u32=29 */
#define SFERA_STATIC_04E78FA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78FA8))
#define SFERA_STATIC_04E78FA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78FA8)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04E78FAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78FAC))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04E78FB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78FB0))
#define SFERA_STATIC_04E78FB0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78FB0)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E78FB4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E78FB4))
#define SFERA_STATIC_04E78FB4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E78FB4)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E79234_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79234))
#define SFERA_STATIC_04E79234_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79234)))

/* data refs=18 u32=18 */
#define SFERA_STATIC_04E79238_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79238))
#define SFERA_STATIC_04E79238_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79238)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E79244_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79244))
#define SFERA_STATIC_04E79244_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79244)))

/* data refs=15 u32=15 */
#define SFERA_STATIC_04E79248_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79248))
#define SFERA_STATIC_04E79248_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79248)))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04E7924C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E7924C))

/* data refs=8 addr=8 */
#define SFERA_STATIC_04E79250_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79250))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04E79268_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79268))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04E792E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E792E0))
#define SFERA_STATIC_04E792E0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792E0)))

/* data refs=61 addr=1 u32=60 */
#define SFERA_STATIC_04E792E4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E792E4))
#define SFERA_STATIC_04E792E4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792E4)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04E792E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E792E8))
#define SFERA_STATIC_04E792E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792E8)))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04E792EC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E792EC))
#define SFERA_STATIC_04E792EC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792EC)))

/* data refs=12 addr=1 u32=11 */
#define SFERA_STATIC_04E792F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E792F0))
#define SFERA_STATIC_04E792F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792F0)))

/* data refs=29 u32=29 */
#define SFERA_STATIC_04E792F4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E792F4))
#define SFERA_STATIC_04E792F4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792F4)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04E792FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E792FC))
#define SFERA_STATIC_04E792FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E792FC)))

/* data refs=11 u32=15 */
#define SFERA_STATIC_04E79300_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79300))
#define SFERA_STATIC_04E79300_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79300)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04E79304_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79304))
#define SFERA_STATIC_04E79304_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79304)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04E7930C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E7930C))
#define SFERA_STATIC_04E7930C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E7930C)))

/* data refs=83 addr=44 u8=39 */
#define SFERA_STATIC_04E79310_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79310))
#define SFERA_STATIC_04E79310_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79310)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04E79B14_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79B14))
#define SFERA_STATIC_04E79B14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04E79B14)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04E79B20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04E79B20))

/* data refs=4 u8=4 */
#define SFERA_STATIC_04EB9B28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9B28))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EB9C28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9C28))
#define SFERA_STATIC_04EB9C28_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9C28)))

/* data refs=5 addr=5 f32=5 */
#define SFERA_STATIC_04EB9C2C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9C2C))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EB9C30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9C30))

/* data refs=4 addr=4 */
#define SFERA_STATIC_04EB9C44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9C44))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EB9C58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9C58))
#define SFERA_STATIC_04EB9C58_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9C58)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EB9C5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9C5C))
#define SFERA_STATIC_04EB9C5C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9C5C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EB9CC4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9CC4))
#define SFERA_STATIC_04EB9CC4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9CC4)))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04EB9CC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9CC8))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04EB9CCC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9CCC))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04EB9CD0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9CD0))
#define SFERA_STATIC_04EB9CD0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9CD0)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EB9CD4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9CD4))
#define SFERA_STATIC_04EB9CD4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9CD4)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EB9CD8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9CD8))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EB9CEC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9CEC))
#define SFERA_STATIC_04EB9CEC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9CEC)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04EB9CF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9CF0))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04EB9E80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9E80))
#define SFERA_STATIC_04EB9E80_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EB9E80)))

/* data refs=19 addr=19 f32=19 */
#define SFERA_STATIC_04EB9E84_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9E84))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EB9E8C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EB9E8C))
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
#define SFERA_STATIC_04EC4EE4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4EE4))
#define SFERA_STATIC_04EC4EE4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EE4)))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04EC4EE9_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4EE9))
#define SFERA_STATIC_04EC4EE9_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EE9)))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04EC4EEA_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4EEA))
#define SFERA_STATIC_04EC4EEA_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EEA)))

/* data refs=3 u8=3 */
#define SFERA_STATIC_04EC4EEB_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4EEB))
#define SFERA_STATIC_04EC4EEB_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EEB)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EC4EEC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4EEC))
#define SFERA_STATIC_04EC4EEC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EEC)))

/* data refs=14 u32=16 */
#define SFERA_STATIC_04EC4EF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4EF0))
#define SFERA_STATIC_04EC4EF0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EF0)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04EC4EF4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4EF4))
#define SFERA_STATIC_04EC4EF4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4EF4)))

/* data refs=23 u32=23 */
#define SFERA_STATIC_04EC4EF8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4EF8))
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
#define SFERA_STATIC_04EC4F08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F08))
#define SFERA_STATIC_04EC4F08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F08)))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04EC4F0C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F0C))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EC4F10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F10))
#define SFERA_STATIC_04EC4F10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F10)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EC4F14_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F14))
#define SFERA_STATIC_04EC4F14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F14)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EC4F18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F18))
#define SFERA_STATIC_04EC4F18_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F18)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EC4F24_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F24))
#define SFERA_STATIC_04EC4F24_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F24)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EC4F30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F30))
#define SFERA_STATIC_04EC4F30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F30)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EC4F40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F40))
#define SFERA_STATIC_04EC4F40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F40)))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04EC4F48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F48))
#define SFERA_STATIC_04EC4F48_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F48)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04EC4F4C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F4C))
#define SFERA_STATIC_04EC4F4C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F4C)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EC4F50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F50))
#define SFERA_STATIC_04EC4F50_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F50)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EC4F54_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F54))
#define SFERA_STATIC_04EC4F54_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F54)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EC4F58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F58))
#define SFERA_STATIC_04EC4F58_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F58)))

/* data refs=16 u8=16 */
#define SFERA_STATIC_04EC4F61_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F61))
#define SFERA_STATIC_04EC4F61_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F61)))

/* data refs=3 u8=3 */
#define SFERA_STATIC_04EC4F62_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F62))
#define SFERA_STATIC_04EC4F62_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F62)))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04EC4F64_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F64))
#define SFERA_STATIC_04EC4F64_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F64)))

/* data refs=9 addr=1 u32=8 */
#define SFERA_STATIC_04EC4F6C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F6C))
#define SFERA_STATIC_04EC4F6C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F6C)))

/* data refs=8 addr=1 u32=7 */
#define SFERA_STATIC_04EC4F70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F70))
#define SFERA_STATIC_04EC4F70_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F70)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04EC4F74_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F74))
#define SFERA_STATIC_04EC4F74_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F74)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EC4F80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F80))
#define SFERA_STATIC_04EC4F80_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F80)))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04EC4F84_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4F84))
#define SFERA_STATIC_04EC4F84_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F84)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EC4FB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4FB0))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EC4FBC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4FBC))
#define SFERA_STATIC_04EC4FBC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4FBC)))

/* data refs=2 addr=2 f32=1 */
#define SFERA_STATIC_04EC4FF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4FF0))

/* data refs=3 addr=3 f32=2 */
#define SFERA_STATIC_04EC4FF4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4FF4))

/* data refs=2 addr=2 f32=1 */
#define SFERA_STATIC_04EC4FF8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EC4FF8))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04ECBA38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ECBA38))
#define SFERA_STATIC_04ECBA38_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ECBA38)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04ECBA3C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ECBA3C))
#define SFERA_STATIC_04ECBA3C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ECBA3C)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04ECBA40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ECBA40))
#define SFERA_STATIC_04ECBA40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ECBA40)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ECBA44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ECBA44))

/* data refs=2 addr=1 f32=2 */
#define SFERA_STATIC_04ECBA48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ECBA48))
#define SFERA_STATIC_04ECBA48_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ECBA48)))

/* data refs=2 addr=1 f32=2 */
#define SFERA_STATIC_04ECBA4C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ECBA4C))
#define SFERA_STATIC_04ECBA4C_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ECBA4C)))

/* data refs=124 addr=124 */
#define SFERA_STATIC_04ECBA50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ECBA50))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED0D70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0D70))
#define SFERA_STATIC_04ED0D70_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0D70)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04ED0DA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0DA8))
#define SFERA_STATIC_04ED0DA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0DA8)))

/* data refs=4 addr=1 u32=3 */
#define SFERA_STATIC_04ED0E14_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E14))
#define SFERA_STATIC_04ED0E14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E14)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED0E18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E18))
#define SFERA_STATIC_04ED0E18_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E18)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04ED0E1C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E1C))

/* data refs=15 addr=7 f32=11 u32=2 */
#define SFERA_STATIC_04ED0E40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E40))
#define SFERA_STATIC_04ED0E40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E40)))
#define SFERA_STATIC_04ED0E40_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E40)))

/* data refs=13 addr=5 f32=11 u32=2 */
#define SFERA_STATIC_04ED0E44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E44))
#define SFERA_STATIC_04ED0E44_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E44)))
#define SFERA_STATIC_04ED0E44_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E44)))

/* data refs=13 addr=5 f32=11 u32=2 */
#define SFERA_STATIC_04ED0E48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E48))
#define SFERA_STATIC_04ED0E48_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E48)))
#define SFERA_STATIC_04ED0E48_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E48)))

/* data refs=7 addr=6 f32=7 */
#define SFERA_STATIC_04ED0E4C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E4C))
#define SFERA_STATIC_04ED0E4C_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E4C)))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04ED0E50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E50))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04ED0E54_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E54))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04ED0E58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E58))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04ED0E5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E5C))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04ED0E60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E60))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED0E64_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E64))

/* data refs=2 addr=1 f32=2 */
#define SFERA_STATIC_04ED0E68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E68))
#define SFERA_STATIC_04ED0E68_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E68)))

/* data refs=2 addr=1 f32=2 */
#define SFERA_STATIC_04ED0E6C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E6C))
#define SFERA_STATIC_04ED0E6C_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E6C)))

/* data refs=5 addr=5 f32=5 */
#define SFERA_STATIC_04ED0E70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E70))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04ED0E74_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E74))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04ED0E78_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0E78))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04ED0EA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0EA0))
#define SFERA_STATIC_04ED0EA0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EA0)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04ED0EA4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0EA4))
#define SFERA_STATIC_04ED0EA4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EA4)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04ED0EA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0EA8))
#define SFERA_STATIC_04ED0EA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EA8)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04ED0EAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0EAC))
#define SFERA_STATIC_04ED0EAC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EAC)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04ED0EB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0EB0))
#define SFERA_STATIC_04ED0EB0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EB0)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04ED0EB4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0EB4))
#define SFERA_STATIC_04ED0EB4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EB4)))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED0EB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0EB8))
#define SFERA_STATIC_04ED0EB8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EB8)))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED0EBC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0EBC))
#define SFERA_STATIC_04ED0EBC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EBC)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04ED0EC4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0EC4))
#define SFERA_STATIC_04ED0EC4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EC4)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04ED0EC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0EC8))
#define SFERA_STATIC_04ED0EC8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EC8)))

/* data refs=4 addr=4 */
#define SFERA_STATIC_04ED0ECC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0ECC))

/* data refs=16 u32=16 */
#define SFERA_STATIC_04ED0F30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0F30))
#define SFERA_STATIC_04ED0F30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0F30)))

/* data refs=15 u32=15 */
#define SFERA_STATIC_04ED0F34_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0F34))
#define SFERA_STATIC_04ED0F34_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0F34)))

/* data refs=29 addr=29 */
#define SFERA_STATIC_04ED0F38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0F38))

/* data refs=5 addr=1 u32=4 */
#define SFERA_STATIC_04ED0F5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0F5C))
#define SFERA_STATIC_04ED0F5C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0F5C)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04ED0F60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0F60))
#define SFERA_STATIC_04ED0F60_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0F60)))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04ED0F64_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0F64))

/* data refs=5 addr=1 u32=4 */
#define SFERA_STATIC_04ED0FE8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0FE8))
#define SFERA_STATIC_04ED0FE8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0FE8)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04ED0FEC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0FEC))
#define SFERA_STATIC_04ED0FEC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0FEC)))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04ED0FF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED0FF0))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04ED1014_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1014))
#define SFERA_STATIC_04ED1014_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1014)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04ED1018_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1018))
#define SFERA_STATIC_04ED1018_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1018)))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04ED101C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED101C))

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
#define SFERA_STATIC_04ED1120_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1120))
#define SFERA_STATIC_04ED1120_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1120)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04ED1158_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1158))
#define SFERA_STATIC_04ED1158_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1158)))

/* data refs=21 u32=21 */
#define SFERA_STATIC_04ED1190_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1190))
#define SFERA_STATIC_04ED1190_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1190)))

/* data refs=20 u32=20 */
#define SFERA_STATIC_04ED1194_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1194))
#define SFERA_STATIC_04ED1194_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1194)))

/* data refs=32 addr=32 */
#define SFERA_STATIC_04ED1198_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1198))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04ED11BC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED11BC))
#define SFERA_STATIC_04ED11BC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED11BC)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04ED11C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED11C0))
#define SFERA_STATIC_04ED11C0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED11C0)))

/* data refs=7 addr=7 */
#define SFERA_STATIC_04ED11C4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED11C4))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04ED11E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED11E8))
#define SFERA_STATIC_04ED11E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED11E8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED1220_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1220))
#define SFERA_STATIC_04ED1220_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1220)))

/* data refs=5 addr=1 u32=4 */
#define SFERA_STATIC_04ED1258_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1258))
#define SFERA_STATIC_04ED1258_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1258)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04ED125C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED125C))
#define SFERA_STATIC_04ED125C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED125C)))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04ED1260_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1260))

/* data refs=12 addr=1 u32=11 */
#define SFERA_STATIC_04ED1284_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1284))
#define SFERA_STATIC_04ED1284_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1284)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04ED1288_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1288))
#define SFERA_STATIC_04ED1288_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1288)))

/* data refs=12 addr=12 */
#define SFERA_STATIC_04ED128C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED128C))

/* data refs=14 addr=14 f32=1 */
#define SFERA_STATIC_04ED12B0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED12B0))

/* data refs=66 addr=32 u32=34 */
#define SFERA_STATIC_04ED12F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED12F0))
#define SFERA_STATIC_04ED12F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED12F0)))

/* data refs=33 u32=33 */
#define SFERA_STATIC_04ED12F4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED12F4))
#define SFERA_STATIC_04ED12F4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED12F4)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04ED132C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED132C))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04ED1358_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1358))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED1A30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1A30))
#define SFERA_STATIC_04ED1A30_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A30)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED1A68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1A68))
#define SFERA_STATIC_04ED1A68_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A68)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04ED1AA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED1AA0))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04ED29A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED29A0))
#define SFERA_STATIC_04ED29A0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED29A0)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04ED29A4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED29A4))
#define SFERA_STATIC_04ED29A4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED29A4)))

/* data refs=17 addr=17 */
#define SFERA_STATIC_04ED29A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED29A8))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04ED29CC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED29CC))
#define SFERA_STATIC_04ED29CC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED29CC)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04ED29D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED29D0))
#define SFERA_STATIC_04ED29D0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED29D0)))

/* data refs=4 addr=4 */
#define SFERA_STATIC_04ED29D4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED29D4))

/* data refs=25 u32=25 */
#define SFERA_STATIC_04ED29F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED29F8))
#define SFERA_STATIC_04ED29F8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED29F8)))

/* data refs=24 u32=24 */
#define SFERA_STATIC_04ED29FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED29FC))
#define SFERA_STATIC_04ED29FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED29FC)))

/* data refs=47 addr=47 */
#define SFERA_STATIC_04ED2A00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2A00))

/* data refs=37 u32=37 */
#define SFERA_STATIC_04ED2A24_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2A24))
#define SFERA_STATIC_04ED2A24_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A24)))

/* data refs=36 u32=36 */
#define SFERA_STATIC_04ED2A28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2A28))
#define SFERA_STATIC_04ED2A28_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A28)))

/* data refs=58 addr=58 */
#define SFERA_STATIC_04ED2A2C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2A2C))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2A50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2A50))
#define SFERA_STATIC_04ED2A50_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A50)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04ED2A7C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2A7C))
#define SFERA_STATIC_04ED2A7C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A7C)))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04ED2A80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2A80))
#define SFERA_STATIC_04ED2A80_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A80)))

/* data refs=19 addr=19 */
#define SFERA_STATIC_04ED2A84_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2A84))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04ED2AA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2AA8))
#define SFERA_STATIC_04ED2AA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2AA8)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04ED2AAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2AAC))
#define SFERA_STATIC_04ED2AAC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2AAC)))

/* data refs=13 addr=13 */
#define SFERA_STATIC_04ED2AB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2AB0))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04ED2AD4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2AD4))
#define SFERA_STATIC_04ED2AD4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2AD4)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04ED2AD8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2AD8))
#define SFERA_STATIC_04ED2AD8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2AD8)))

/* data refs=21 addr=21 */
#define SFERA_STATIC_04ED2ADC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2ADC))

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

/* data refs=7 addr=1 u32=6 */
#define SFERA_STATIC_04ED2B0C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2B0C))
#define SFERA_STATIC_04ED2B0C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2B0C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04ED2B10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2B10))
#define SFERA_STATIC_04ED2B10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2B10)))

/* data refs=8 addr=8 */
#define SFERA_STATIC_04ED2B14_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2B14))

/* data refs=2 addr=2 f32=1 */
#define SFERA_STATIC_04ED2B38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2B38))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2BA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2BA8))
#define SFERA_STATIC_04ED2BA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BA8)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04ED2BE0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2BE0))
#define SFERA_STATIC_04ED2BE0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BE0)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2BE4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2BE4))
#define SFERA_STATIC_04ED2BE4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BE4)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2BE8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2BE8))
#define SFERA_STATIC_04ED2BE8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BE8)))

/* data refs=15 u32=15 */
#define SFERA_STATIC_04ED2BEC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2BEC))
#define SFERA_STATIC_04ED2BEC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BEC)))

/* data refs=14 u32=14 */
#define SFERA_STATIC_04ED2BF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2BF0))
#define SFERA_STATIC_04ED2BF0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BF0)))

/* data refs=26 addr=26 */
#define SFERA_STATIC_04ED2BF4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2BF4))

/* data refs=5 addr=1 u32=4 */
#define SFERA_STATIC_04ED2C18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C18))
#define SFERA_STATIC_04ED2C18_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C18)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04ED2C1C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C1C))
#define SFERA_STATIC_04ED2C1C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C1C)))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04ED2C20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C20))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04ED2C44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C44))
#define SFERA_STATIC_04ED2C44_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C44)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04ED2C48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C48))
#define SFERA_STATIC_04ED2C48_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C48)))

/* data refs=9 addr=9 */
#define SFERA_STATIC_04ED2C4C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2C4C))

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
#define SFERA_STATIC_04ED2CA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2CA0))
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
#define SFERA_STATIC_04ED2D28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2D28))
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
#define SFERA_STATIC_04ED2DB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2DB8))
#define SFERA_STATIC_04ED2DB8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2DB8)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04ED2DE4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2DE4))
#define SFERA_STATIC_04ED2DE4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2DE4)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04ED2DE8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2DE8))
#define SFERA_STATIC_04ED2DE8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2DE8)))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04ED2DEC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2DEC))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2E10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E10))
#define SFERA_STATIC_04ED2E10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E10)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2E14_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E14))
#define SFERA_STATIC_04ED2E14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E14)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2E18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E18))
#define SFERA_STATIC_04ED2E18_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E18)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2E1C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E1C))
#define SFERA_STATIC_04ED2E1C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E1C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2E20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E20))
#define SFERA_STATIC_04ED2E20_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E20)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2E24_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E24))
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

/* data refs=12 u32=12 */
#define SFERA_STATIC_04ED2E34_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E34))
#define SFERA_STATIC_04ED2E34_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E34)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04ED2E38_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E38))
#define SFERA_STATIC_04ED2E38_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E38)))

/* data refs=21 addr=21 */
#define SFERA_STATIC_04ED2E3C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E3C))

/* data refs=6 addr=2 u32=4 */
#define SFERA_STATIC_04ED2E60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E60))
#define SFERA_STATIC_04ED2E60_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E60)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04ED2E64_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E64))
#define SFERA_STATIC_04ED2E64_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E64)))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04ED2E68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E68))

/* data refs=45 u32=45 */
#define SFERA_STATIC_04ED2E8C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E8C))
#define SFERA_STATIC_04ED2E8C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E8C)))

/* data refs=44 u32=44 */
#define SFERA_STATIC_04ED2E90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E90))
#define SFERA_STATIC_04ED2E90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E90)))

/* data refs=84 addr=84 */
#define SFERA_STATIC_04ED2E94_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2E94))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED2EB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2EB8))
#define SFERA_STATIC_04ED2EB8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EB8)))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED2EBC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2EBC))
#define SFERA_STATIC_04ED2EBC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EBC)))

/* data refs=2 addr=1 f32=1 u32=1 */
#define SFERA_STATIC_04ED2EC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2EC0))
#define SFERA_STATIC_04ED2EC0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EC0)))

/* data refs=54 u32=54 */
#define SFERA_STATIC_04ED2EC4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2EC4))
#define SFERA_STATIC_04ED2EC4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EC4)))

/* data refs=53 u32=53 */
#define SFERA_STATIC_04ED2EC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2EC8))
#define SFERA_STATIC_04ED2EC8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EC8)))

/* data refs=63 addr=63 */
#define SFERA_STATIC_04ED2ECC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2ECC))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED2EF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2EF0))
#define SFERA_STATIC_04ED2EF0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EF0)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04ED2F1C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2F1C))
#define SFERA_STATIC_04ED2F1C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F1C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04ED2F20_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2F20))
#define SFERA_STATIC_04ED2F20_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F20)))

/* data refs=9 addr=9 */
#define SFERA_STATIC_04ED2F24_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2F24))

/* data refs=237 addr=7 u32=230 */
#define SFERA_STATIC_04ED2F48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2F48))
#define SFERA_STATIC_04ED2F48_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F48)))

/* data refs=225 u32=225 */
#define SFERA_STATIC_04ED2F4C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2F4C))
#define SFERA_STATIC_04ED2F4C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F4C)))

/* data refs=304 addr=304 */
#define SFERA_STATIC_04ED2F50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2F50))

/* data refs=32 u32=32 */
#define SFERA_STATIC_04ED2F74_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2F74))
#define SFERA_STATIC_04ED2F74_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F74)))

/* data refs=29 u32=29 */
#define SFERA_STATIC_04ED2F78_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2F78))
#define SFERA_STATIC_04ED2F78_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F78)))

/* data refs=57 addr=57 */
#define SFERA_STATIC_04ED2F7C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2F7C))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04ED2FE0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2FE0))
#define SFERA_STATIC_04ED2FE0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2FE0)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04ED2FE4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2FE4))
#define SFERA_STATIC_04ED2FE4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2FE4)))

/* data refs=15 addr=15 */
#define SFERA_STATIC_04ED2FE8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED2FE8))

/* data refs=26 u32=26 */
#define SFERA_STATIC_04ED300C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED300C))
#define SFERA_STATIC_04ED300C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED300C)))

/* data refs=25 u32=25 */
#define SFERA_STATIC_04ED3010_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3010))
#define SFERA_STATIC_04ED3010_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3010)))

/* data refs=47 addr=47 */
#define SFERA_STATIC_04ED3014_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3014))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED3038_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3038))
#define SFERA_STATIC_04ED3038_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3038)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04ED3070_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3070))
#define SFERA_STATIC_04ED3070_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3070)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04ED3074_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3074))
#define SFERA_STATIC_04ED3074_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3074)))

/* data refs=9 addr=9 */
#define SFERA_STATIC_04ED3078_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3078))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04ED309C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED309C))
#define SFERA_STATIC_04ED309C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED309C)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04ED30A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED30A0))
#define SFERA_STATIC_04ED30A0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED30A0)))

/* data refs=7 addr=7 */
#define SFERA_STATIC_04ED30A4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED30A4))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED30C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED30C8))
#define SFERA_STATIC_04ED30C8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED30C8)))

/* data refs=7 addr=3 u32=4 */
#define SFERA_STATIC_04ED3100_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3100))
#define SFERA_STATIC_04ED3100_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3100)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04ED3104_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3104))
#define SFERA_STATIC_04ED3104_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3104)))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04ED3108_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3108))

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
#define SFERA_STATIC_04ED36A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36A0))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36A4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36A4))

/* data refs=3 addr=3 f32=2 */
#define SFERA_STATIC_04ED36A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36A8))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36AC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36AC))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED36B0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36B0))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04ED36B8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36B8))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36BC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36BC))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36C0))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36C4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36C4))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36C8))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36CC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36CC))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED36D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36D0))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36D8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36D8))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36DC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36DC))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36E0))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36E4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36E4))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36E8))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36EC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36EC))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED36F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36F0))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36F8))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED36FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED36FC))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED3700_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3700))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED3704_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3704))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED3708_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3708))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED370C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED370C))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04ED3710_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3710))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED3718_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED3718))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04ED371C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04ED371C))

/* data refs=26 u32=26 */
#define SFERA_STATIC_04EDCCA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCCA0))
#define SFERA_STATIC_04EDCCA0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCCA0)))

/* data refs=25 u32=25 */
#define SFERA_STATIC_04EDCCA4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCCA4))
#define SFERA_STATIC_04EDCCA4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCCA4)))

/* data refs=50 addr=50 */
#define SFERA_STATIC_04EDCCA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCCA8))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDCCCC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCCCC))
#define SFERA_STATIC_04EDCCCC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCCCC)))

/* data refs=18 addr=18 */
#define SFERA_STATIC_04EDCCF8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCCF8))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EDCD58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD58))
#define SFERA_STATIC_04EDCD58_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD58)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EDCD5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD5C))
#define SFERA_STATIC_04EDCD5C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD5C)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EDCD60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD60))
#define SFERA_STATIC_04EDCD60_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD60)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EDCD64_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD64))
#define SFERA_STATIC_04EDCD64_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD64)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EDCD68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD68))
#define SFERA_STATIC_04EDCD68_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD68)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EDCD6C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD6C))
#define SFERA_STATIC_04EDCD6C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD6C)))

/* data refs=6 addr=6 */
#define SFERA_STATIC_04EDCD70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD70))

/* data refs=16 u32=16 */
#define SFERA_STATIC_04EDCD74_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD74))
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
#define SFERA_STATIC_04EDCD98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCD98))
#define SFERA_STATIC_04EDCD98_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD98)))

/* data refs=19 u32=19 */
#define SFERA_STATIC_04EDCDD0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCDD0))
#define SFERA_STATIC_04EDCDD0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCDD0)))

/* data refs=18 u32=18 */
#define SFERA_STATIC_04EDCDD4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCDD4))
#define SFERA_STATIC_04EDCDD4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCDD4)))

/* data refs=35 addr=35 */
#define SFERA_STATIC_04EDCDD8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCDD8))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04EDCDFC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCDFC))
#define SFERA_STATIC_04EDCDFC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCDFC)))

/* data refs=10 u32=10 */
#define SFERA_STATIC_04EDCE00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE00))
#define SFERA_STATIC_04EDCE00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE00)))

/* data refs=14 addr=14 */
#define SFERA_STATIC_04EDCE04_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE04))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04EDCE28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE28))
#define SFERA_STATIC_04EDCE28_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE28)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04EDCE2C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE2C))
#define SFERA_STATIC_04EDCE2C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE2C)))

/* data refs=11 addr=11 */
#define SFERA_STATIC_04EDCE30_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE30))

/* data refs=10 addr=2 u32=8 */
#define SFERA_STATIC_04EDCE54_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE54))
#define SFERA_STATIC_04EDCE54_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE54)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04EDCE58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE58))
#define SFERA_STATIC_04EDCE58_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE58)))

/* data refs=12 addr=12 */
#define SFERA_STATIC_04EDCE5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE5C))

/* data refs=12 addr=12 f32=7 */
#define SFERA_STATIC_04EDCE80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE80))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04EDCE84_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE84))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04EDCE88_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE88))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04EDCE8C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE8C))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EDCE90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE90))
#define SFERA_STATIC_04EDCE90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE90)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EDCE94_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE94))
#define SFERA_STATIC_04EDCE94_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE94)))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04EDCE98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE98))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04EDCE9C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCE9C))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04EDCEA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEA0))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04EDCEA4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEA4))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04EDCEA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEA8))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04EDCEAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEAC))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EDCEB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEB0))
#define SFERA_STATIC_04EDCEB0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCEB0)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EDCEB4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEB4))
#define SFERA_STATIC_04EDCEB4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCEB4)))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04EDCEB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEB8))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04EDCEBC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEBC))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04EDCEC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEC0))

/* data refs=7 addr=7 f32=7 */
#define SFERA_STATIC_04EDCEC4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEC4))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04EDCEC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEC8))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04EDCECC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCECC))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EDCED0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCED0))
#define SFERA_STATIC_04EDCED0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCED0)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EDCED4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCED4))
#define SFERA_STATIC_04EDCED4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCED4)))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04EDCED8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCED8))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04EDCEDC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEDC))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04EDCEE0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEE0))

/* data refs=4 addr=4 f32=4 */
#define SFERA_STATIC_04EDCEE4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEE4))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04EDCEE8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEE8))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04EDCEEC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEEC))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EDCEF0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEF0))
#define SFERA_STATIC_04EDCEF0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCEF0)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EDCEF4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEF4))
#define SFERA_STATIC_04EDCEF4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCEF4)))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04EDCEF8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEF8))

/* data refs=6 addr=6 f32=6 */
#define SFERA_STATIC_04EDCEFC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCEFC))

/* data refs=6 addr=6 */
#define SFERA_STATIC_04EDCF00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCF00))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDCF40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCF40))
#define SFERA_STATIC_04EDCF40_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCF40)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04EDCF78_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCF78))
#define SFERA_STATIC_04EDCF78_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCF78)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04EDCF7C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCF7C))
#define SFERA_STATIC_04EDCF7C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCF7C)))

/* data refs=11 addr=11 */
#define SFERA_STATIC_04EDCF80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCF80))

/* data refs=14 u32=14 */
#define SFERA_STATIC_04EDCFA4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCFA4))
#define SFERA_STATIC_04EDCFA4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCFA4)))

/* data refs=13 u32=13 */
#define SFERA_STATIC_04EDCFA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCFA8))
#define SFERA_STATIC_04EDCFA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCFA8)))

/* data refs=25 addr=25 */
#define SFERA_STATIC_04EDCFAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCFAC))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EDCFD0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDCFD0))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04EDD030_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD030))
#define SFERA_STATIC_04EDD030_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD030)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EDD068_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD068))
#define SFERA_STATIC_04EDD068_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD068)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EDD06C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD06C))
#define SFERA_STATIC_04EDD06C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD06C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EDD070_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD070))
#define SFERA_STATIC_04EDD070_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD070)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04EDD074_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD074))

/* data refs=4 u32=6 */
#define SFERA_STATIC_04EDD078_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD078))
#define SFERA_STATIC_04EDD078_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD078)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD080_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD080))
#define SFERA_STATIC_04EDD080_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD080)))

/* data refs=4 u32=6 */
#define SFERA_STATIC_04EDD088_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD088))
#define SFERA_STATIC_04EDD088_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD088)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD090_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD090))
#define SFERA_STATIC_04EDD090_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD090)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD0A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0A0))
#define SFERA_STATIC_04EDD0A0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0A0)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EDD0A4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0A4))
#define SFERA_STATIC_04EDD0A4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0A4)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EDD0A8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0A8))
#define SFERA_STATIC_04EDD0A8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0A8)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EDD0AC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0AC))

/* data refs=5 u32=6 u8=1 */
#define SFERA_STATIC_04EDD0C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0C8))
#define SFERA_STATIC_04EDD0C8_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0C8)))
#define SFERA_STATIC_04EDD0C8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0C8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD0CC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0CC))
#define SFERA_STATIC_04EDD0CC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0CC)))

/* data refs=32 addr=24 u32=8 */
#define SFERA_STATIC_04EDD0D0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0D0))
#define SFERA_STATIC_04EDD0D0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0D0)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04EDD0D4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0D4))
#define SFERA_STATIC_04EDD0D4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0D4)))

/* data refs=8 u16=2 u32=6 */
#define SFERA_STATIC_04EDD0D8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0D8))
#define SFERA_STATIC_04EDD0D8_U16 (*(uint16_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0D8)))
#define SFERA_STATIC_04EDD0D8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0D8)))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04EDD0DA_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0DA))
#define SFERA_STATIC_04EDD0DA_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD0DA)))

/* data refs=6 u16=6 */
#define SFERA_STATIC_04EDD0DC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD0DC))
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
#define SFERA_STATIC_04EDD35C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD35C))
#define SFERA_STATIC_04EDD35C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD35C)))
#define SFERA_STATIC_04EDD35C_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD35C)))

/* data refs=2 f32=1 u32=1 */
#define SFERA_STATIC_04EDD360_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD360))
#define SFERA_STATIC_04EDD360_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD360)))
#define SFERA_STATIC_04EDD360_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD360)))

/* data refs=2 f32=1 u32=1 */
#define SFERA_STATIC_04EDD364_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD364))
#define SFERA_STATIC_04EDD364_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD364)))
#define SFERA_STATIC_04EDD364_F32 (*(float*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD364)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EDD368_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD368))
#define SFERA_STATIC_04EDD368_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD368)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EDD374_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD374))
#define SFERA_STATIC_04EDD374_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD374)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EDD380_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD380))
#define SFERA_STATIC_04EDD380_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD380)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD384_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD384))
#define SFERA_STATIC_04EDD384_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD384)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD388_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD388))
#define SFERA_STATIC_04EDD388_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD388)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EDD38C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD38C))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04EDD398_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD398))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EDD460_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD460))
#define SFERA_STATIC_04EDD460_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD460)))

/* data refs=4 addr=3 u8=1 */
#define SFERA_STATIC_04EDD464_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD464))

/* data refs=8 addr=8 */
#define SFERA_STATIC_04EDD490_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD490))

/* data refs=16 u32=16 */
#define SFERA_STATIC_04EDD510_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD510))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04EDD590_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EDD590))
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
#define SFERA_STATIC_04EE04A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE04A0))
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
#define SFERA_STATIC_04EE8158_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EE8158))
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
#define SFERA_STATIC_04EEA008_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA008))
#define SFERA_STATIC_04EEA008_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA008)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEA010_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA010))
#define SFERA_STATIC_04EEA010_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA010)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04EEA0E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA0E0))
#define SFERA_STATIC_04EEA0E0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA0E0)))

/* data refs=3 u8=3 */
#define SFERA_STATIC_04EEA0E4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA0E4))
#define SFERA_STATIC_04EEA0E4_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA0E4)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04EEA0E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA0E8))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EEA128_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA128))
#define SFERA_STATIC_04EEA128_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA128)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EEA12C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA12C))
#define SFERA_STATIC_04EEA12C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA12C)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EEA130_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA130))
#define SFERA_STATIC_04EEA130_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA130)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EEA134_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA134))
#define SFERA_STATIC_04EEA134_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA134)))

/* data refs=6 addr=6 */
#define SFERA_STATIC_04EEA138_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA138))

/* data refs=3 addr=2 u32=1 */
#define SFERA_STATIC_04EEA150_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA150))
#define SFERA_STATIC_04EEA150_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA150)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EEA330_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA330))
#define SFERA_STATIC_04EEA330_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA330)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EEA518_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA518))
#define SFERA_STATIC_04EEA518_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA518)))

/* data refs=4 u32=3 u8=1 */
#define SFERA_STATIC_04EEA520_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA520))
#define SFERA_STATIC_04EEA520_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA520)))
#define SFERA_STATIC_04EEA520_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA520)))

/* data refs=58 u32=62 */
#define SFERA_STATIC_04EEA524_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA524))
#define SFERA_STATIC_04EEA524_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA524)))

/* data refs=15 addr=11 u8=4 */
#define SFERA_STATIC_04EEA528_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA528))

/* data refs=25 u32=31 */
#define SFERA_STATIC_04EEA628_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA628))
#define SFERA_STATIC_04EEA628_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA628)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EEA62C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA62C))
#define SFERA_STATIC_04EEA62C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEA62C)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04EEA630_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA630))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EEA634_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA634))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04EEA638_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA638))

/* data refs=104 addr=104 */
#define SFERA_STATIC_04EEA720_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEA720))

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
#define SFERA_STATIC_04EEAD00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAD00))
#define SFERA_STATIC_04EEAD00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAD00)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04EEAD04_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAD04))
#define SFERA_STATIC_04EEAD04_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAD04)))

/* data refs=17 u32=17 */
#define SFERA_STATIC_04EEAD08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAD08))
#define SFERA_STATIC_04EEAD08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEAD08)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EEAD0C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEAD0C))
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
#define SFERA_STATIC_04EEB080_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB080))
#define SFERA_STATIC_04EEB080_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB080)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEB088_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB088))
#define SFERA_STATIC_04EEB088_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB088)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04EEB158_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB158))
#define SFERA_STATIC_04EEB158_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB158)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEB160_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB160))
#define SFERA_STATIC_04EEB160_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB160)))

/* data refs=8 addr=4 u32=1 u8=3 */
#define SFERA_STATIC_04EEB230_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB230))
#define SFERA_STATIC_04EEB230_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB230)))
#define SFERA_STATIC_04EEB230_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB230)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04EEB430_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB430))
#define SFERA_STATIC_04EEB430_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB430)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEB438_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB438))
#define SFERA_STATIC_04EEB438_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB438)))

/* data refs=12 addr=4 u32=8 */
#define SFERA_STATIC_04EEB508_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB508))
#define SFERA_STATIC_04EEB508_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB508)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04EEB50C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB50C))
#define SFERA_STATIC_04EEB50C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB50C)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04EEB510_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB510))
#define SFERA_STATIC_04EEB510_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB510)))

/* data refs=18 u32=22 */
#define SFERA_STATIC_04EEB5E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB5E0))
#define SFERA_STATIC_04EEB5E0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB5E0)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EEB5E8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB5E8))
#define SFERA_STATIC_04EEB5E8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB5E8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EEB5EC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB5EC))
#define SFERA_STATIC_04EEB5EC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB5EC)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EEB5F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB5F0))
#define SFERA_STATIC_04EEB5F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB5F0)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04EEB5F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB5F8))
#define SFERA_STATIC_04EEB5F8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB5F8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04EEB5FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB5FC))
#define SFERA_STATIC_04EEB5FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB5FC)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04EEB600_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB600))
#define SFERA_STATIC_04EEB600_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB600)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04EEB604_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB604))
#define SFERA_STATIC_04EEB604_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EEB604)))

/* data refs=4 addr=1 u16=3 */
#define SFERA_STATIC_04EEB610_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04EEB610))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04F0B610_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F0B610))

/* data refs=2 u32=4 */
#define SFERA_STATIC_04F17960_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F17960))
#define SFERA_STATIC_04F17960_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F17960)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F17964_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F17964))
#define SFERA_STATIC_04F17964_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F17964)))

/* data refs=4 u16=4 */
#define SFERA_STATIC_04F17968_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F17968))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04F37968_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37968))
#define SFERA_STATIC_04F37968_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37968)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F3796C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3796C))
#define SFERA_STATIC_04F3796C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3796C)))

/* data refs=11 u32=11 */
#define SFERA_STATIC_04F37970_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37970))
#define SFERA_STATIC_04F37970_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37970)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F379E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F379E0))
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
#define SFERA_STATIC_04F37EA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37EA8))
#define SFERA_STATIC_04F37EA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EA8)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F37EAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37EAC))
#define SFERA_STATIC_04F37EAC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EAC)))

/* data refs=3 u32=5 */
#define SFERA_STATIC_04F37EB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37EB0))
#define SFERA_STATIC_04F37EB0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EB0)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F37EB4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37EB4))
#define SFERA_STATIC_04F37EB4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EB4)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F37EC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37EC0))
#define SFERA_STATIC_04F37EC0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EC0)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F37EC4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37EC4))
#define SFERA_STATIC_04F37EC4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EC4)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F37EC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37EC8))
#define SFERA_STATIC_04F37EC8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37EC8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F37ECC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37ECC))
#define SFERA_STATIC_04F37ECC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37ECC)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F37ED0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37ED0))
#define SFERA_STATIC_04F37ED0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37ED0)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F37ED4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37ED4))
#define SFERA_STATIC_04F37ED4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37ED4)))

/* data refs=4 u8=4 */
#define SFERA_STATIC_04F37ED8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37ED8))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F37F3C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37F3C))
#define SFERA_STATIC_04F37F3C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F37F3C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F37F40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37F40))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F37F44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F37F44))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F38260_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38260))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F383F0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F383F0))
#define SFERA_STATIC_04F383F0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F383F0)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F383F8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F383F8))
#define SFERA_STATIC_04F383F8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F383F8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F383FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F383FC))
#define SFERA_STATIC_04F383FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F383FC)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F38400_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38400))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F38800_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38800))
#define SFERA_STATIC_04F38800_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38800)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F38808_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38808))
#define SFERA_STATIC_04F38808_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38808)))

/* data refs=3 addr=2 u32=1 */
#define SFERA_STATIC_04F38818_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38818))
#define SFERA_STATIC_04F38818_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38818)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F38884_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38884))
#define SFERA_STATIC_04F38884_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38884)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F38888_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38888))
#define SFERA_STATIC_04F38888_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F38888)))

/* data refs=7 addr=7 */
#define SFERA_STATIC_04F3888C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3888C))

/* data refs=5 addr=5 */
#define SFERA_STATIC_04F38910_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38910))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04F389D8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F389D8))

/* data refs=3 addr=3 f32=3 */
#define SFERA_STATIC_04F389DC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F389DC))

/* data refs=2 u8=2 */
#define SFERA_STATIC_04F389E0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F389E0))
#define SFERA_STATIC_04F389E0_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F389E0)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04F389E4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F389E4))
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
#define SFERA_STATIC_04F38F28_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F38F28))
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
#define SFERA_STATIC_04F3A460_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A460))
#define SFERA_STATIC_04F3A460_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A460)))

/* data refs=9 u32=9 */
#define SFERA_STATIC_04F3A464_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A464))
#define SFERA_STATIC_04F3A464_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A464)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F3A468_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A468))
#define SFERA_STATIC_04F3A468_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A468)))

/* data refs=10 addr=1 u32=9 */
#define SFERA_STATIC_04F3A4D4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A4D4))
#define SFERA_STATIC_04F3A4D4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A4D4)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04F3A4D8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3A4D8))
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
#define SFERA_STATIC_04F3AD58_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AD58))
#define SFERA_STATIC_04F3AD58_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3AD58)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F3AD5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3AD5C))
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
#define SFERA_STATIC_04F3B084_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B084))
#define SFERA_STATIC_04F3B084_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B084)))

/* data refs=5 u8=5 */
#define SFERA_STATIC_04F3B088_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B088))
#define SFERA_STATIC_04F3B088_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B088)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F3B08C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B08C))
#define SFERA_STATIC_04F3B08C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B08C)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04F3B090_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B090))
#define SFERA_STATIC_04F3B090_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B090)))

/* data refs=15 u32=15 */
#define SFERA_STATIC_04F3B094_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B094))
#define SFERA_STATIC_04F3B094_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B094)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F3B098_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B098))
#define SFERA_STATIC_04F3B098_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B098)))

/* data refs=14 u32=14 */
#define SFERA_STATIC_04F3B09C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B09C))
#define SFERA_STATIC_04F3B09C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B09C)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04F3B0A0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B0A0))
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
#define SFERA_STATIC_04F3B18C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B18C))
#define SFERA_STATIC_04F3B18C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B18C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F3B190_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B190))
#define SFERA_STATIC_04F3B190_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B190)))

/* data refs=12 u32=12 */
#define SFERA_STATIC_04F3B194_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B194))
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
#define SFERA_STATIC_04F3B1BC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B1BC))
#define SFERA_STATIC_04F3B1BC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B1BC)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04F3B1C4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B1C4))

/* data refs=7 addr=7 */
#define SFERA_STATIC_04F3B1C8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B1C8))

/* data refs=3 u8=3 */
#define SFERA_STATIC_04F3B210_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B210))
#define SFERA_STATIC_04F3B210_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B210)))

/* data refs=7 addr=6 u8=1 */
#define SFERA_STATIC_04F3B3C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B3C0))

/* data refs=2 u32=1 u8=1 */
#define SFERA_STATIC_04F3B4C0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F3B4C0))
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
#define SFERA_STATIC_04F47FA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F47FA8))
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
#define SFERA_STATIC_04F48A5C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48A5C))
#define SFERA_STATIC_04F48A5C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48A5C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F48A60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48A60))
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

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F48B6C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48B6C))
#define SFERA_STATIC_04F48B6C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B6C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F48B70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48B70))
#define SFERA_STATIC_04F48B70_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B70)))

/* data refs=5 addr=2 u32=3 */
#define SFERA_STATIC_04F48B74_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48B74))
#define SFERA_STATIC_04F48B74_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B74)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F48B78_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48B78))
#define SFERA_STATIC_04F48B78_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B78)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F48B7C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48B7C))
#define SFERA_STATIC_04F48B7C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B7C)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F48B80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48B80))
#define SFERA_STATIC_04F48B80_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B80)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F48B84_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48B84))
#define SFERA_STATIC_04F48B84_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B84)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F48B88_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48B88))
#define SFERA_STATIC_04F48B88_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B88)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F48B8C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48B8C))
#define SFERA_STATIC_04F48B8C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B8C)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F48B90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48B90))
#define SFERA_STATIC_04F48B90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B90)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F48B94_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48B94))
#define SFERA_STATIC_04F48B94_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B94)))

/* data refs=4 addr=2 u32=2 */
#define SFERA_STATIC_04F48B98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48B98))
#define SFERA_STATIC_04F48B98_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B98)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F48B9C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48B9C))
#define SFERA_STATIC_04F48B9C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48B9C)))

/* data refs=5 u32=4 u8=1 */
#define SFERA_STATIC_04F48BA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BA0))
#define SFERA_STATIC_04F48BA0_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BA0)))
#define SFERA_STATIC_04F48BA0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BA0)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F48BA4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BA4))
#define SFERA_STATIC_04F48BA4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BA4)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F48BA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BA8))
#define SFERA_STATIC_04F48BA8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BA8)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04F48BAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BAC))
#define SFERA_STATIC_04F48BAC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BAC)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F48BB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BB0))
#define SFERA_STATIC_04F48BB0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BB0)))

/* data refs=7 u32=7 */
#define SFERA_STATIC_04F48BB4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BB4))
#define SFERA_STATIC_04F48BB4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BB4)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F48BB8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BB8))
#define SFERA_STATIC_04F48BB8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BB8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F48BBC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BBC))
#define SFERA_STATIC_04F48BBC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BBC)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F48BC0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BC0))
#define SFERA_STATIC_04F48BC0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BC0)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F48BC4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BC4))
#define SFERA_STATIC_04F48BC4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BC4)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F48BC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BC8))
#define SFERA_STATIC_04F48BC8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BC8)))

/* data refs=5 addr=2 u32=3 */
#define SFERA_STATIC_04F48BCC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BCC))
#define SFERA_STATIC_04F48BCC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BCC)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F48BD0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BD0))
#define SFERA_STATIC_04F48BD0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BD0)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F48BD4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BD4))
#define SFERA_STATIC_04F48BD4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BD4)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F48BD8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BD8))
#define SFERA_STATIC_04F48BD8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BD8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F48BDC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BDC))
#define SFERA_STATIC_04F48BDC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BDC)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04F48BE0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BE0))
#define SFERA_STATIC_04F48BE0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BE0)))

/* data refs=6 addr=1 u32=5 */
#define SFERA_STATIC_04F48BE4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BE4))
#define SFERA_STATIC_04F48BE4_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BE4)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F48BE8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BE8))
#define SFERA_STATIC_04F48BE8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BE8)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F48BEC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F48BEC))
#define SFERA_STATIC_04F48BEC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F48BEC)))

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
#define SFERA_STATIC_04F49A00_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49A00))
#define SFERA_STATIC_04F49A00_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49A00)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F49A04_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49A04))
#define SFERA_STATIC_04F49A04_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49A04)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F49A08_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49A08))
#define SFERA_STATIC_04F49A08_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49A08)))

/* data refs=9 addr=1 u32=8 */
#define SFERA_STATIC_04F49A0C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49A0C))
#define SFERA_STATIC_04F49A0C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49A0C)))

/* data refs=4 addr=4 */
#define SFERA_STATIC_04F49A10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49A10))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F49A94_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49A94))
#define SFERA_STATIC_04F49A94_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49A94)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F49A98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49A98))
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
#define SFERA_STATIC_04F49B74_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49B74))
#define SFERA_STATIC_04F49B74_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B74)))

/* data refs=9 addr=4 u32=5 */
#define SFERA_STATIC_04F49B80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49B80))
#define SFERA_STATIC_04F49B80_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B80)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F49B84_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49B84))
#define SFERA_STATIC_04F49B84_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B84)))

/* data refs=18 addr=2 u32=16 */
#define SFERA_STATIC_04F49B90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49B90))
#define SFERA_STATIC_04F49B90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B90)))

/* data refs=8 u32=8 */
#define SFERA_STATIC_04F49B94_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49B94))
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

/* data refs=4 addr=2 f32=2 u32=2 */
#define SFERA_STATIC_04F49F40_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F40))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49F44_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F44))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49F48_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F48))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49F4C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F4C))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F49F50_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F50))
#define SFERA_STATIC_04F49F50_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49F50)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49F60_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F60))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49F64_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F64))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49F68_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F68))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49F6C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F6C))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F49F70_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F70))
#define SFERA_STATIC_04F49F70_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49F70)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49F80_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F80))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49F84_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F84))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49F88_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F88))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49F8C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F8C))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F49F90_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49F90))
#define SFERA_STATIC_04F49F90_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49F90)))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49FA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49FA0))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49FA4_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49FA4))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49FA8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49FA8))

/* data refs=2 addr=2 f32=2 */
#define SFERA_STATIC_04F49FAC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49FAC))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F49FB0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F49FB0))
#define SFERA_STATIC_04F49FB0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49FB0)))

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
#define SFERA_STATIC_04F4A50C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A50C))
#define SFERA_STATIC_04F4A50C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4A50C)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F4A510_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4A510))
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
#define SFERA_STATIC_04F4C6FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C6FC))
#define SFERA_STATIC_04F4C6FC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4C6FC)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F4C704_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4C704))
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

/* data refs=473 u32=473 */
#define SFERA_STATIC_04F4CC10_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CC10))
#define SFERA_STATIC_04F4CC10_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CC10)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F4CC14_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CC14))
#define SFERA_STATIC_04F4CC14_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CC14)))

/* data refs=2 addr=1 u32=1 */
#define SFERA_STATIC_04F4CC18_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CC18))
#define SFERA_STATIC_04F4CC18_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CC18)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04F4CCEC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CCEC))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04F4CD2C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CD2C))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F4CD94_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CD94))
#define SFERA_STATIC_04F4CD94_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CD94)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F4CD98_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CD98))
#define SFERA_STATIC_04F4CD98_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F4CD98)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F4CD9C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F4CD9C))
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
#define SFERA_STATIC_04F8F770_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8F770))
#define SFERA_STATIC_04F8F770_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8F770)))

/* data refs=12 u8=12 */
#define SFERA_STATIC_04F8F771_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8F771))
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
#define SFERA_STATIC_04F8FAC7_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8FAC7))
#define SFERA_STATIC_04F8FAC7_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8FAC7)))

/* data refs=4 u32=6 */
#define SFERA_STATIC_04F8FAC8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8FAC8))
#define SFERA_STATIC_04F8FAC8_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8FAC8)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04F8FACC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8FACC))
#define SFERA_STATIC_04F8FACC_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8FACC)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F8FAD0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8FAD0))
#define SFERA_STATIC_04F8FAD0_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F8FAD0)))

/* data refs=3 addr=3 */
#define SFERA_STATIC_04F8FAD8_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8FAD8))

/* data refs=6 addr=6 */
#define SFERA_STATIC_04F8FDA0_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F8FDA0))

/* data refs=12 u8=12 */
#define SFERA_STATIC_04F90068_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90068))
#define SFERA_STATIC_04F90068_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90068)))

/* data refs=6 u32=6 */
#define SFERA_STATIC_04F9006C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F9006C))
#define SFERA_STATIC_04F9006C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F9006C)))

/* data refs=3 u16=3 */
#define SFERA_STATIC_04F90070_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90070))

/* data refs=10 u8=10 */
#define SFERA_STATIC_04F90270_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90270))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F90370_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90370))
#define SFERA_STATIC_04F90370_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90370)))

/* data refs=2 addr=2 */
#define SFERA_STATIC_04F90378_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90378))

/* data refs=21 addr=21 */
#define SFERA_STATIC_04F903FC_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F903FC))

/* data refs=10 u8=10 */
#define SFERA_STATIC_04F90414_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90414))
#define SFERA_STATIC_04F90414_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90414)))

/* data refs=12 u8=12 */
#define SFERA_STATIC_04F90415_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90415))
#define SFERA_STATIC_04F90415_U8 (*(uint8_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90415)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F90424_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90424))
#define SFERA_STATIC_04F90424_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90424)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F9042C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F9042C))
#define SFERA_STATIC_04F9042C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F9042C)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F90430_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90430))
#define SFERA_STATIC_04F90430_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90430)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F90434_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90434))
#define SFERA_STATIC_04F90434_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90434)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F9076C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F9076C))
#define SFERA_STATIC_04F9076C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F9076C)))

/* data refs=5 u32=5 */
#define SFERA_STATIC_04F90774_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90774))
#define SFERA_STATIC_04F90774_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90774)))

/* data refs=2 u32=2 */
#define SFERA_STATIC_04F9077C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F9077C))
#define SFERA_STATIC_04F9077C_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F9077C)))

/* data refs=3 addr=1 u32=2 */
#define SFERA_STATIC_04F90784_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90784))
#define SFERA_STATIC_04F90784_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90784)))

/* data refs=3 u32=3 */
#define SFERA_STATIC_04F90788_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F90788))
#define SFERA_STATIC_04F90788_U32 (*(uint32_t*)(uintptr_t)SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90788)))

/* data refs=4 u32=4 */
#define SFERA_STATIC_04F9078C_ADDR SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x04F9078C))
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
