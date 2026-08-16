#include "semantic_native.h"
#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <stddef.h>
#include <stdint.h>
#include <string.h>

/* ===== Native storage definitions ===== */
#if defined(_MSC_VER)
#define SFERA_STORAGE_ALIGN __declspec(align(64))
#else
#define SFERA_STORAGE_ALIGN __attribute__((aligned(64)))
#endif

extern "C" {
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
uint32_t SFERA_IMPORT_MSVCR100_except_handler4_common = 0u;
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
uint32_t SFERA_IMPORT_MSVCR100_CxxThrowException = 0u;
uint32_t SFERA_IMPORT_MSVCR100_exception_ctor_325 = 0u;
uint32_t SFERA_IMPORT_MSVCR100_CxxFrameHandler3 = 0u;
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

/* ===== Fully lifted .rdata semantic backing ===== */
/* IAT slots are not mirrored here. The remaining original .rdata bytes are contiguous because source code and relocated data perform valid pointer arithmetic inside literal/RTTI/table pools. */
extern "C" {
uint8_t* g_sfera_rdata_semantic_storage = nullptr;
}

namespace {
inline void sfera_copy_static_bytes(uint8_t* storage, uint32_t offset, const char* bytes, size_t size) { memcpy(storage + offset, bytes, size); }
void sfera_initialize_rdata_storage(uint8_t* storage) {
    memset(storage, 0, SFERA_RDATA_SEMANTIC_SIZE);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000004), "a\356N\000A\240O\000\340JO\000\020KO\000PKO\000\200KO\000\300KO\000\360KO\0000LO\000`LO\000\240LO\000\320LO\000\020MO\000@MO\000\200MO\000\260MO\000\360MO\000 NO\000`NO\000\240NO\000\320NO\000\020OO\000@OO\000\200OO\000\260OO\000\360OO\000pPO\000\340PO\000\360PO\000 QO\000`QO\000\220QO\000\320QO\000\360QO\000pRO\0000SO\000`SO\000\240SO\000\320SO\000\020TO\0000TO\000PTO\000\200TO\000\300TO\000\360TO\0000UO\000PUO\000pUO\000\200UO\000\220UO\000\260UO\000\340UO\000 VO\000\220VO\000\000WO\000pWO\000\240WO\000\340WO\000\020XO\000PXO\000pXO\000\220XO\000 YO\000\260YO", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000104), "@ZO\000\320ZO\000`[O\000\360[O\000\200\\O\000\220\\O\000 ]O\000\260]O\000\320]O\000\340]O\000P^O\000\300^O\0000_O\000\240_O\000\020`O\000\200`O\000\360`O\000`aO\000\320aO\000@bO\000\260bO\000 cO\000\220cO\000\000dO\000pdO\000\020eO\000\200eO\000PfO\000 gO\000\360gO\000\300hO\000PiO\000\300iO\0000jO\000\240jO\000\020kO\000\200kO\000\020lO\000\200lO\000\360lO\000`mO\000\320mO\000@nO\000\260nO\000 oO\000\240oO\000\020pO\000\200pO\000\360pO\000`qO\000\320qO\000@rO\000\260rO\000 sO\000\220sO\000\000tO\000ptO\000\340tO\000PuO\000\300uO\0000vO\000\240vO\000\020wO\000\200wO", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000204), "\260wO\000\360wO\000 xO\000`xO\000\220xO\000\320xO\000\000yO\000@yO\000pyO\000\260yO\000\340yO\000 zO\000PzO\000\220zO\000\300zO\000\000{O\0000{O\000p{O\000\240{O\000\340{O\000\360{O\000 |O\000`|O\000\200|O\000\240|O\000\320|O\000\020}O\000@}O\000\200}O\000\260}O\000\360}O\000\000~O\0000~O\000p~O\000\240~O\000\340~O\000\360~O\000 \177O\000`\177O\000\220\177O\000\320\177O\000\000\200O\000@\200O\000p\200O\000\260\200O\000 \201O\000P\201O\000\220\201O\000\300\201O\000\000\202O\000 \202O\000@\202O\000p\202O\000\260\202O\000\320\202O\000\360\202O\000 \203O\000`\203O\000\220\203O\000\320\203O\000\360\203O\000\020\204O\000@\204O\000\200\204O", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000304), "\240\204O\000\300\204O\000\360\204O\0000\205O\000P\205O\000p\205O\000\240\205O\000\340\205O\000\360\205O\000 \206O\000`\206O\000\200\206O\000\240\206O\000\320\206O\000\020\207O\000@\207O\000\200\207O\000\240\207O\000\300\207O\000\360\207O\0000\210O\000P\210O\000p\210O\000\240\210O\000\340\210O\000\000\211O\000 \211O\000P\211O\000\220\211O\000\260\211O\000\320\211O\000\000\212O\000@\212O\000`\212O\000\200\212O\000\260\212O\000\360\212O\000\020\213O\0000\213O\000\220\213O\000\360\213O\000P\214O\000`\214O\000 \215O\000\200\215O\000\240\215O\000\320\215O\000\020\216O\0000\216O\000P\216O\000\200\216O\000\300\216O\000\360\216O\0000\217O\000P\217O\000p\217O\000\240\217O\000\340\217O\000\000\220O\000 \220O\000@\220O\000`\220O\000\200\220O\000\260\220O", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000404), "\360\220O\000\020\221O\0000\221O\000`\221O\000\240\221O\000\300\221O\000\340\221O\000\020\222O\000P\222O\000\200\222O\000\300\222O\000\340\222O\000\000\223O\0000\223O\000p\223O\000\220\223O\000\260\223O\000\340\223O\000 \224O\000@\224O\000`\224O\000\220\224O\000\320\224O\000\360\224O\000\020\225O\000@\225O\000\200\225O\000\240\225O\000\300\225O\000\360\225O\0000\226O\000P\226O\000p\226O\000\240\226O\000\340\226O\000\000\227O\000 \227O\0000\227O\000@\227O\000P\227O\000\200\227O\000\300\227O\000\340\227O\000\000\230O\0000\230O\000p\230O\000\240\230O\000\340\230O\000\000\231O\000 \231O\000P\231O\000\220\231O\000\260\231O\000\320\231O\000\000\232O\000@\232O\000`\232O\000\200\232O\000\260\232O\000\360\232O\000P\233O\000\200\233O\000\300\233O\000\340\233O", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000505), "\234O\000 \234O\000P\234O\000\220\234O\000\300\234O\000\000\235O\0000\235O\000p\235O\000\240\235O\000\340\235O\000\020\236O\000P\236O\000\200\236O\000\300\236O\000\360\236O\0000\237O\000`\237O\000\240\237O\000\320\237O\000\020\240O", 78u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000055C), "\210\360N\000\311\362N\000(\363N", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000570), "\247\005\374i\000\000\000\000\002\000\000\000p\000\000\000td\021\000tJ\021", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000588), "..\\ShareClientSeverCode\\Arrays.cpp", 34u); storage[UINT32_C(0x000005AA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000005AC), "AutoBoundsArray error: the index has exceeded a maximum\nFile: %s  Line: %d\n", 75u); storage[UINT32_C(0x000005F7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000005FC), "AutoBoundsArray error: non-uniform growth of an index\nFile: %s  Line: %d\n", 73u); storage[UINT32_C(0x00000645)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000064C), "BoundCheckArray error: index less than zero\nFile: %s  Line: %d\n", 63u); storage[UINT32_C(0x0000068B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000068C), "BoundCheckArray error: index out of range %d\nFile: %s  Line: %d\n", 64u); storage[UINT32_C(0x000006CC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000006D4), " ERROR(2): putbitstream: bufer will overload: count = %d, bufsize = %d", 70u); storage[UINT32_C(0x0000071A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000071C), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inter.h", 82u); storage[UINT32_C(0x0000076E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000774), " ERROR(1): putbitstream: bufer will overload: bitT = %d, count = %d, bufsize = %d", 81u); storage[UINT32_C(0x000007C5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000007C8), "%d", 2u); storage[UINT32_C(0x000007CA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000007CC), "%f", 2u); storage[UINT32_C(0x000007CE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000007D0), "..\\ShareClientSeverCode\\config.cpp", 34u); storage[UINT32_C(0x000007F2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000007F4), "\377\377\177\177\377\377\177\377\344dQ\000\260\033@\000$\351N", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000808), "..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp", 52u); storage[UINT32_C(0x0000083C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000840), "invalid string position", 23u); storage[UINT32_C(0x00000857)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000858), "string too long", 15u); storage[UINT32_C(0x00000867)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000868), "vector<T> too long", 18u); storage[UINT32_C(0x0000087A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000087C), "list<T> too long", 16u); storage[UINT32_C(0x0000088C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000890), "map/set<T> too long", 19u); storage[UINT32_C(0x000008A3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000008A6), "\200O", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000008A8), "invalid map/set<T> iterator", 27u); storage[UINT32_C(0x000008C3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000008C4), "..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp", 51u); storage[UINT32_C(0x000008F7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000008FC), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sMapContainer.h", 99u); storage[UINT32_C(0x0000095F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000960), "..\\ShareClientSeverCode\\DataCont\\sSetContainer.cpp", 50u); storage[UINT32_C(0x00000992)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000994), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h", 100u); storage[UINT32_C(0x000009F8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000009FC), "..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp", 53u); storage[UINT32_C(0x00000A31)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000A34), "%02u.%02u.%04u %02u:%02u:%02u ", 30u); storage[UINT32_C(0x00000A52)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000A54), "w", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000A58), "at", 2u); storage[UINT32_C(0x00000A5A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000A5C), "logs\\%d%s", 9u); storage[UINT32_C(0x00000A65)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000A68), "Create connect manager\n", 23u); storage[UINT32_C(0x00000A7F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000A80), "tcp_ip_connect.log", 18u); storage[UINT32_C(0x00000A92)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000A94), "============================================================================\n", 77u); storage[UINT32_C(0x00000AE1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000AE4), "..\\ShareClientSeverCode\\TCP-IP\\ClientConnectMngr.cpp", 52u); storage[UINT32_C(0x00000B18)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000B1C), "Rnd Thread exit\n", 16u); storage[UINT32_C(0x00000B2C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000B30), "Deinit TCP-IP manager(3)\n", 25u); storage[UINT32_C(0x00000B49)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000B4C), "Deinit TCP-IP manager(2)\n", 25u); storage[UINT32_C(0x00000B65)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000B68), "Deinit TCP-IP manager(1)\n", 25u); storage[UINT32_C(0x00000B81)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000B84), "-------------------------ERROR: send buffer overload\n", 53u); storage[UINT32_C(0x00000BB9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000BBC), "Rcv Thread exit\n", 16u); storage[UINT32_C(0x00000BCC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000BD0), "-------------------------IN(ERROR): (limit connections)\n", 56u); storage[UINT32_C(0x00000C08)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000C0C), "-------------------------CLOSE CONNECTION, err=%d\n", 50u); storage[UINT32_C(0x00000C3E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000C40), "-------------------------LOST CONNECTION, err=%d\n", 49u); storage[UINT32_C(0x00000C71)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000C74), "-------------------------ERROR: select, err=%d\n", 47u); storage[UINT32_C(0x00000CA3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000CA4), "-------------------------ERROR: rcv buffer overload\n", 52u); storage[UINT32_C(0x00000CD8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000CE2), "\010@", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000CE4), "Create connection: socket=%d\n", 29u); storage[UINT32_C(0x00000D01)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000D04), "-------------------------ERROR: local rcv buffer overload\n", 58u); storage[UINT32_C(0x00000D3E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000D40), "Snd Thread exit\n", 16u); storage[UINT32_C(0x00000D50)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000D54), "---error(3)--init connect manager (%d '%s'), error=%d\n", 54u); storage[UINT32_C(0x00000D8A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000D8C), "Init TCP-IP manager(3) (%d '%s'), skt=%d, adr='%s'\n", 51u); storage[UINT32_C(0x00000DBF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000DC0), "---error(7)--init connect manager (%d '%s'), error=%d\n", 54u); storage[UINT32_C(0x00000DF6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000DF8), "---error(6)--init connect manager (%d '%s'), error=%d\n", 54u); storage[UINT32_C(0x00000E2E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000E30), "---error(5)--init connect manager (%d '%s'), error=%d\n", 54u); storage[UINT32_C(0x00000E66)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000E68), "---error(4_3)--init connect manager (%d '%s'), lastError=%d\n", 60u); storage[UINT32_C(0x00000EA4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000EA8), "---error(4_2)--init connect manager (%d '%s'), errno=%d\n", 56u); storage[UINT32_C(0x00000EE0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000EE4), "---error(4_1)--init connect manager (%d '%s') \n", 47u); storage[UINT32_C(0x00000F13)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000F14), "Init TCP-IP manager(2) (%d '%s'), skt=%d, adr='%s'\n", 51u); storage[UINT32_C(0x00000F47)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000F48), "Init TCP-IP manager(1) (%d '%s'), skt=%d, adr='%s'\n", 51u); storage[UINT32_C(0x00000F7B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000F7C), "Init TCP-IP manager (%d '%s') - no delay res = %d\n", 50u); storage[UINT32_C(0x00000FAE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000FB0), "---error(2_1)--init connect manager (%d), error=%d\n", 51u); storage[UINT32_C(0x00000FE3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000FE4), "Init TCP-IP manager (%d '%s'), skt=%d\n", 38u); storage[UINT32_C(0x0000100A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000100C), "---error(2)--init connect manager (%d '%s'), error=%d\n", 54u); storage[UINT32_C(0x00001042)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001044), "---error(1)--init connect manager (%d '%s'), error=%d\n", 54u); storage[UINT32_C(0x0000107A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000107C), "Init TCP-IP manager (%d '%s')\n", 30u); storage[UINT32_C(0x0000109A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000109C), "-------------------------ERROR: ALREADY Init TCP-IP manager (%d '%s')\n", 70u); storage[UINT32_C(0x000010E2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000010E4), "0123456789ABCDEF", 16u); storage[UINT32_C(0x000010F4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000010F8), "BaseCache.cpp", 13u); storage[UINT32_C(0x00001105)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001108), "Bitmap.cpp", 10u); storage[UINT32_C(0x00001112)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001114), "\334\017I@\000\000\376B\000\376\377F\000\000\200D\000\376\377F\230eQ\000\220\240A\000p\240A\000\360\251A", 35u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001142), ".@\000\000\000\000\000\000\340?", 10u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000115B), "@\000\000\000\200\373!\031@\000\000\000\000 \000\000?\000\000\000\000\000\340o@\000\000\000\340Q\270\316?\000\000\000@\n\327\323?\000\000\000\300\314\314\334?\000\000\000\300\314\314\374?\000\000\000\000\000\000\370?\000\000\000\000\000\000\360?\000\000\200\277\000\000\000\000\000\000\000\240\231\231\311?", 89u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000011B4), "Unknown classID for blood spot effect.", 38u); storage[UINT32_C(0x000011DA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000011DC), "fx_bspot", 8u); storage[UINT32_C(0x000011E4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000011E8), "SphereReport::Assertion failed -> File %s, Line %d", 50u); storage[UINT32_C(0x0000121A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000121C), "..\\ShareClientSeverCode\\BloodEffect.cpp", 39u); storage[UINT32_C(0x00001243)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001246), "\376B\000\376\377F\000\000\200D\000\376\377F", 14u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001254), "internal error 759476206789", 27u); storage[UINT32_C(0x0000126F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001270), "Match for bone name not found", 29u); storage[UINT32_C(0x0000128D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001290), "preload_model: wrong file format", 32u); storage[UINT32_C(0x000012B0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000012B4), ".chr", 4u); storage[UINT32_C(0x000012B8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000012BC), "..\\ShareClientSeverCode\\CharMdl.cpp", 35u); storage[UINT32_C(0x000012DF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000012E2), " \300\000\000\000\200\024\256\357?\000\000\000@33\323?\000\000\000`ff\346?", 26u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000012FC), "models\\textures\\wf00.dds", 24u); storage[UINT32_C(0x00001314)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001318), "models\\textures\\wr00.dds", 24u); storage[UINT32_C(0x00001330)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001337), "\300\314\314\354?\000\000\000\340\3426:?\000\000\000\240\231\231\361?\000\000\000\340\3426\032?", 29u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001354), "\n\327#<Wrong handle: set_char_param\n", 33u); storage[UINT32_C(0x00001375)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001378), "Wrong handle: get_char_param\n", 29u); storage[UINT32_C(0x00001395)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001398), "wrong format of subobjs.dat", 27u); storage[UINT32_C(0x000013B3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000013B4), "womanhelmsmall", 14u); storage[UINT32_C(0x000013C2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000013C4), "texture for char model not found. name=", 39u); storage[UINT32_C(0x000013EB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000013EC), "t", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000013F0), "char model not found. name=", 27u); storage[UINT32_C(0x0000140B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000140C), "m\000\000\000s", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001414), "subobjs", 7u); storage[UINT32_C(0x0000141B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000141C), "xadd\\subobjs.dat", 16u); storage[UINT32_C(0x0000142C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001430), "*.chr", 5u); storage[UINT32_C(0x00001435)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001438), "xadd\\woman.skl", 14u); storage[UINT32_C(0x00001446)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001448), "xadd\\man.skl", 12u); storage[UINT32_C(0x00001454)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001458), "o\022\203:\000\000\376B\000\376\377F\000\000\200D\000\376\377F\n", 21u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001470), "%s\n", 3u); storage[UINT32_C(0x00001473)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001474), "333?..\\ShareClientSeverCode\\CheckFiles.cpp", 42u); storage[UINT32_C(0x0000149E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000014A0), "filelist.dat", 12u); storage[UINT32_C(0x000014AC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000014B0), "sphereclient.exe", 16u); storage[UINT32_C(0x000014C0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000014C4), "sphere.exe", 10u); storage[UINT32_C(0x000014CE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000014D0), "xupdate", 7u); storage[UINT32_C(0x000014D7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000014DA), "\376B\000\376\377F\000\000\200D\000\376\377F", 14u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000014E8), "..\\ShareClientSeverCode\\Contours.cpp", 36u); storage[UINT32_C(0x0000150C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001511), "$t\311\000$tI", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001518), "landscape\\contours.bin", 22u); storage[UINT32_C(0x0000152E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000153A), "i@", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000153C), "=======\n", 8u); storage[UINT32_C(0x00001544)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001548), "===serverByType ====\ntypeN=", 27u); storage[UINT32_C(0x00001563)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000156A), ">@\000\000\000\000\000\000\034@\000\000\000\000\000\000I@\000\000\000\240\231\231\271?\000\000\000\000\000@\257@\000\000\000\000\000\000Y@\000\000\310B", 46u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001598), "process_contour_event: wrong type %d", 36u); storage[UINT32_C(0x000015BC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000015C0), "internal error 68247987378235", 29u); storage[UINT32_C(0x000015DD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000015E0), "internal error 672474878765683", 30u); storage[UINT32_C(0x000015FE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001600), "internal error 87236589", 23u); storage[UINT32_C(0x00001617)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001618), "Wrong connection of server contours (case2)", 43u); storage[UINT32_C(0x00001643)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001644), "Wrong connection of server contours (case1)", 43u); storage[UINT32_C(0x0000166F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001670), "logs\\CurrentExecuting.log", 25u); storage[UINT32_C(0x00001689)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000168C), "Browser Example", 15u); storage[UINT32_C(0x0000169B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000169C), "\001\000\000\000\000\000\000\000M\000y\000 \000H\000o\000s\000t\000 \000N\000a\000m\000e\000\000\000\000\000\000\000\376B\000\376\377F\000\000\200D\000\376\377F", 52u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000016D0), "..\\ShareClientSeverCode\\DebugScriptArrays.cpp", 45u); storage[UINT32_C(0x000016FD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001700), ".adb", 4u); storage[UINT32_C(0x00001704)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001708), "mbc\\", 4u); storage[UINT32_C(0x0000170C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001710), "Memory Error! See at Warnings.log", 33u); storage[UINT32_C(0x00001731)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001734), "End of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d", 77u); storage[UINT32_C(0x00001781)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001784), "Start of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d", 79u); storage[UINT32_C(0x000017D3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000017D4), "CDIB::Initialize(): failed to allocate memory block", 51u); storage[UINT32_C(0x00001807)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001808), "..\\ShareClientSeverCode\\DIB.cpp", 31u); storage[UINT32_C(0x00001827)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000182A), "\376B\000\376\377F\000\000\200D\000\376\377F\217\302u=\000\000\000`\373!y?\000\000\000`\373!\031@\000\000\000\000\300\377\337@\000\000\000\000\000\000\350?\000\000\000\000\000\000\010\300\000\000\000\000\000\000\320?\000\000\000\340\316\367\357?\000\000\000\240\231\231\351?\000\000\000\340Q\270\256?\000\000\000@33\303?\000\000\000\000\000\000 @\000\000\000\000\000\000\024@\000\000\000\240\231\231\331?\000\000\000\000\000\0004@\000\000\000\000\000P\244@\000\000\000\000\000\000\020@", 146u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000018BC), "\315\314\314>\364\3754?", 8u); storage[UINT32_C(0x000018C4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000018C7), "?", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000018C8), "..\\ShareClientSeverCode\\DynGreen.cpp", 36u); storage[UINT32_C(0x000018EC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000018F7), "\240\231\231\251?", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000018FC), "dyn_grass_loop: wrong mp->dg_type", 33u); storage[UINT32_C(0x0000191D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001923), "@\000\000\000\000\000@\237@", 9u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000192C), "Parameter phaseMul not found for model ", 39u); storage[UINT32_C(0x00001953)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001954), "phaseMul", 8u); storage[UINT32_C(0x0000195C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001960), "Parameter deadRadius not found for model ", 41u); storage[UINT32_C(0x00001989)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000198C), "deadRadius", 10u); storage[UINT32_C(0x00001996)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001998), "\232\231\031\276", 4u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000199C), "ground_y", 8u); storage[UINT32_C(0x000019A4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000019AA), "\376B\000\376\377F\000\000\200D\000\376\377F\000\000\000\000\000\000\000@\341zt?", 26u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000019C4), "..\\ShareClientSeverCode\\EffectManager.cpp", 41u); storage[UINT32_C(0x000019ED)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000019F0), "\344eQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000019F4), "\"\353N", 3u); storage[UINT32_C(0x000019F7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000019F8), "\"\353N\000\320\263B\000\"\353N\000\"\353N\000\"\353N\000\"\353N\000\"\353N\000\320\267B\000`_B\000\220_B\000\220uB\000,fQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001A28), "\340\224B", 3u); storage[UINT32_C(0x00001A2B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001A2C), "@fB\000\200\222B\000\260fB\000PwB\000\320fB\000\340xB\000\320\263B\000\320\267B\000\240vB\000\240aB\000\020\232B\000\000\000\177C", 48u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001A5C), "light->position_track", 21u); storage[UINT32_C(0x00001A71)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001A74), "position_track", 14u); storage[UINT32_C(0x00001A82)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001A84), "light->alpha_track", 18u); storage[UINT32_C(0x00001A96)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001A98), "alpha_track", 11u); storage[UINT32_C(0x00001AA3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001AA4), "light->color_track", 18u); storage[UINT32_C(0x00001AB6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001AB8), "color_track", 11u); storage[UINT32_C(0x00001AC3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001AC4), "ATTACH_BETWEENHANDS", 19u); storage[UINT32_C(0x00001AD7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001AD8), "ATTACH_RIGHTHAND", 16u); storage[UINT32_C(0x00001AE8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001AEC), "ATTACH_LEFTHAND", 15u); storage[UINT32_C(0x00001AFB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001AFC), "attach", 6u); storage[UINT32_C(0x00001B02)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B04), "brightFreq", 10u); storage[UINT32_C(0x00001B0E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B10), "%f %f", 5u); storage[UINT32_C(0x00001B15)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B18), "brightness", 10u); storage[UINT32_C(0x00001B22)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B24), "%d %d %d %d %d %d", 17u); storage[UINT32_C(0x00001B35)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B38), "random_color", 12u); storage[UINT32_C(0x00001B44)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B48), "%f %f %f %f", 11u); storage[UINT32_C(0x00001B53)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B54), "light_color", 11u); storage[UINT32_C(0x00001B5F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B60), "%f %f %f", 8u); storage[UINT32_C(0x00001B68)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B6C), "light_pos", 9u); storage[UINT32_C(0x00001B75)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B7C), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h", 83u); storage[UINT32_C(0x00001BCF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001BD0), "ATTACH_SWORD", 12u); storage[UINT32_C(0x00001BDC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001BE0), "EFF_PSYSTEM", 11u); storage[UINT32_C(0x00001BEB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001BEC), "EFF_MESH", 8u); storage[UINT32_C(0x00001BF4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001BF8), "subeffect", 9u); storage[UINT32_C(0x00001C01)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C04), "subeffects_num", 14u); storage[UINT32_C(0x00001C12)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C14), "effftype", 8u); storage[UINT32_C(0x00001C1C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C20), "CScriptedEffect::LoadScript(%s) -> Can't load light_def block", 61u); storage[UINT32_C(0x00001C5D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C60), "light_def", 9u); storage[UINT32_C(0x00001C69)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C6C), "sound_def", 9u); storage[UINT32_C(0x00001C75)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C78), "sleeptime", 9u); storage[UINT32_C(0x00001C81)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C84), "worktime", 8u); storage[UINT32_C(0x00001C8C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C9A), "8@", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C9C), "daytime_work", 12u); storage[UINT32_C(0x00001CA8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001CAC), "%f %f %f %f %f %f", 17u); storage[UINT32_C(0x00001CBD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001CC0), "boundbox", 8u); storage[UINT32_C(0x00001CC8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001CCC), "updvisible_only", 15u); storage[UINT32_C(0x00001CDB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001CDC), "effect_timelimit", 16u); storage[UINT32_C(0x00001CEC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001CF0), "effect_time", 11u); storage[UINT32_C(0x00001CFB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001CFC), "effect_number", 13u); storage[UINT32_C(0x00001D09)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001D0C), "effect_name", 11u); storage[UINT32_C(0x00001D17)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001D18), "effect_def", 10u); storage[UINT32_C(0x00001D22)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001D24), "CScriptedEffect::LoadScript(%s) -> Can't load psystem_def block", 63u); storage[UINT32_C(0x00001D63)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001D64), "psystem_def", 11u); storage[UINT32_C(0x00001D6F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001D74), "CScriptedEffect::LoadScript(%s) -> Can't load effectmesh_def block", 66u); storage[UINT32_C(0x00001DB6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001DB8), "effectmesh_def", 14u); storage[UINT32_C(0x00001DC6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001DD2), "p?", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001DD4), "Players\\", 8u); storage[UINT32_C(0x00001DDC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001DE0), "Players\\*.sef", 13u); storage[UINT32_C(0x00001DED)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001DF0), "Effects\\*.sef", 13u); storage[UINT32_C(0x00001DFD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001E00), "Effects\\", 8u); storage[UINT32_C(0x00001E08)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001E0C), "Effects\\*.ssm", 13u); storage[UINT32_C(0x00001E19)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001E21), "\340\357?\000\000\000\000\000\000$@", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001E2C), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h", 86u); storage[UINT32_C(0x00001E82)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001E86), "pA\000\000 A\000\000\240@", 10u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001E90), "EM_RegisterEffectListener::Multiple listeners not implemented.", 62u); storage[UINT32_C(0x00001ECE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001ED0), "\334\017I@", 4u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001ED4), "\254\305'7", 4u); storage[UINT32_C(0x00001ED8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001EE2), "\360\277\000\000\000 \\\217\352?", 10u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001EEC), "\\\217B>", 4u); storage[UINT32_C(0x00001EF0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001EF7), "`ff\326?\000\000\000\000\000\354\243@", 13u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F04), "33\263>fx_flare", 12u); storage[UINT32_C(0x00001F10)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F14), "\315\314\314=\315\314\314\276xfQ", 11u); storage[UINT32_C(0x00001F1F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F21), "\270B\000\320\263B\000\320\263B\000\020\267B\000\240\260B\000\320\267B\000\260\260B\0000\261B\000\320\267B\000`_B\000\220_B\000\340\267B", 46u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F50), "spiral.effect0", 14u); storage[UINT32_C(0x00001F5E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F60), "..\\ShareClientSeverCode\\Effects.cpp", 35u); storage[UINT32_C(0x00001F83)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F84), "\304fQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F88), "\320\272B", 3u); storage[UINT32_C(0x00001F8B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F8D), "\262B\000\320\263B\000\020\267B\000\240\260B\000\320\267B\000`\262B\000\000\263B\000\320\267B\000`_B\000\220_B\000P\272B", 42u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001FB8), "molniya.effect110", 17u); storage[UINT32_C(0x00001FC9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001FCC), "CMolEffect::Texture not found 'fx_light'", 40u); storage[UINT32_C(0x00001FF4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001FF8), "fx_light", 8u); storage[UINT32_C(0x00002000)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002004), "\020gQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002008), "P\300B", 3u); storage[UINT32_C(0x0000200B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000200C), "\320\263B\000\320\263B\000\020\267B\000\240\260B\000\320\267B\000\340\263B\000\200\264B\000\320\267B\000`_B\000\220_B\000 \300B", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002038), "blade", 5u); storage[UINT32_C(0x0000203D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002040), "CBladeEffect::Texture not found 'fx_blade'", 42u); storage[UINT32_C(0x0000206A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000206C), "fx_blade", 8u); storage[UINT32_C(0x00002074)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002078), "\\gQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000207C), "0\265B", 3u); storage[UINT32_C(0x0000207F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002080), "\320\263B\000\320\263B\000\020\267B\000\240\260B\000\320\267B\000\260\306B\000\320\263B\000\320\267B\000`_B\000\220_B\000\220\306B\000\000\000@C\000\000\000\000\000\000\000\200\373!\t@\250gQ\000\000\310B\000\320\263B\000\320\263B\000\020\267B\000\240\260B\000\320\267B\000\300\317B\000\320\263B\000\320\267B\000`_B\000\220_B\000p\307B\000\000\000\360B", 116u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000020F4), "rain", 4u); storage[UINT32_C(0x000020F8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000020FE), "\200@\000\000\000\000\000\000\000\240\231\231\231?\232\231\031>\000\000\000\000\000\000\000@33\363?\000\000\000\000\000@S@\000\000\000\000\000\200I\300\000\000\000\000\000\200i\300\000\000\000\000\000\000T@\000\000\000\000\000\000y@\000\000\240C", 74u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002148), "gazer.lake", 10u); storage[UINT32_C(0x00002152)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002154), "CRainEffect::Texture not found 'fx_rain'", 40u); storage[UINT32_C(0x0000217C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002180), "fx_rain", 7u); storage[UINT32_C(0x00002187)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002188), "\334\017I@", 4u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000218C), "..\\ShareClientSeverCode\\EffectTrack.cpp", 39u); storage[UINT32_C(0x000021B3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000021B8), "\020\000\360>\364gQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000021C0), "\"\353N", 3u); storage[UINT32_C(0x000021C3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000021C4), "..\\ShareClientSeverCode\\ErrorLog.cpp", 36u); storage[UINT32_C(0x000021E8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000021EC), "<hQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000021F0), "\360\343B", 3u); storage[UINT32_C(0x000021F3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000021F4), "--------------------------------------------------------------------------------\n\n", 82u); storage[UINT32_C(0x00002246)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002248), " Log file created on %s", 23u); storage[UINT32_C(0x0000225F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002260), " Sphere log file\n", 17u); storage[UINT32_C(0x00002271)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002274), "--------------------------------------------------------------------------------\n", 81u); storage[UINT32_C(0x000022C5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000022C8), "wt", 2u); storage[UINT32_C(0x000022CA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000022CC), "- %s\n", 5u); storage[UINT32_C(0x000022D1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000022D4), "a+t", 3u); storage[UINT32_C(0x000022D7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000022D8), "\210hQ\0000\344B", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000022E4), "*** ERROR ****************************************************:", 63u); storage[UINT32_C(0x00002323)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002324), "sphere.log", 10u); storage[UINT32_C(0x0000232E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002330), "NetError.log\000\000\000\000client-Crash.1\000\000app-is-Run.1\000\000\000\000error-Cause.1", 61u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002370), "\n%s not found!\n", 15u); storage[UINT32_C(0x0000237F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002380), "\n%s\n->\n", 7u); storage[UINT32_C(0x00002387)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002388), "r", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000238C), "Warnings00.log", 14u); storage[UINT32_C(0x0000239A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000239C), "Error.log", 9u); storage[UINT32_C(0x000023A5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000023A8), "ERRORLOG.TXT", 12u); storage[UINT32_C(0x000023B4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000023B8), "File %s not deleted (~), error cause: %s\n", 41u); storage[UINT32_C(0x000023E1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000023E4), "..\\ShareClientSeverCode\\FastCrashReport.cpp", 43u); storage[UINT32_C(0x0000240F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002410), "..\\ShareClientSeverCode\\Files.cpp", 33u); storage[UINT32_C(0x00002431)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002434), "Attempt of reading from the file with the wrong handle.", 55u); storage[UINT32_C(0x0000246B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000246C), "Attempt of writing to the file with the wrong handle.", 53u); storage[UINT32_C(0x000024A1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000024A4), "Attempt of seeking in the file with the wrong handle.", 53u); storage[UINT32_C(0x000024D9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000024DC), "Attempt of closing the file with the wrong handle.", 50u); storage[UINT32_C(0x0000250E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002510), "%x", 2u); storage[UINT32_C(0x00002512)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002516), "\376B\000\376\377F\000\000\200D\000\376\377F\000\000\000\340Mb\340?", 22u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000252C), "Landscape\\GrassMap\\GrassMap_00_00.bin", 37u); storage[UINT32_C(0x00002551)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002554), "\010iQ\000\300\nC", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000255C), "..\\ShareClientSeverCode\\hash.cpp", 32u); storage[UINT32_C(0x0000257C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002580), "qwertyuiopasdfghjklzxcvbnm\351\366\363\352\345\355\343\370\371\347\365\372\364\373\342\340\357\360\356\353\344\346\375\377\367\361\354\350\362\374\341\376\270", 59u); storage[UINT32_C(0x000025BB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000025BC), "QWERTYUIOPASDFGHJKLZXCVBNM\311\326\323\312\305\315\303\330\331\307\325\332\324\333\302\300\317\320\316\313\304\306\335\337\327\321\314\310\322\334\301\336\250", 59u); storage[UINT32_C(0x000025F7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000025F8), "CHash16::register_str: maxStrLen exceed", 39u); storage[UINT32_C(0x0000261F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002620), "CHash16::register_str: more than 65535 elements", 47u); storage[UINT32_C(0x0000264F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002650), "CHash8Mem: init error", 21u); storage[UINT32_C(0x00002665)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002668), "CHash8Mem::register_str: more than 65535 elements", 49u); storage[UINT32_C(0x00002699)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000269C), "\210iQ\000\260\373A\000\324iQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000026A8), "\260\373A", 3u); storage[UINT32_C(0x000026AB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000026AC), " jQ\000\260\373A\000pjQ\000\260\373A", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000026BC), "://", 3u); storage[UINT32_C(0x000026BF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000026C0), "\300jQ\000\260\373A", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000026C8), "\t\n\r ", 4u); storage[UINT32_C(0x000026CC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000026D0), "\\/", 2u); storage[UINT32_C(0x000026D2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000026D6), "\376B\000\376\377F\000\000\200D\000\376\377F\200\227\033#w\025\325\021\216]\210\217\217\005\252v", 30u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000026F4), "MessID: %u\n", 11u); storage[UINT32_C(0x000026FF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002700), "Unloading _main: %s:%d, %d, %d\n", 31u); storage[UINT32_C(0x0000271F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002720), "Unloading _main: %s:%d\n", 23u); storage[UINT32_C(0x00002737)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002738), "Unloading _main: %s:%d, %d, %d, %d, %d\n", 39u); storage[UINT32_C(0x0000275F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002760), "..\\ShareClientSeverCode\\INet.cpp", 32u); storage[UINT32_C(0x00002780)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002784), "EKill", 5u); storage[UINT32_C(0x00002789)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000278C), "-- T\n", 5u); storage[UINT32_C(0x00002791)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002794), "-- N\n", 5u); storage[UINT32_C(0x00002799)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000279C), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inet_tcp.h", 85u); storage[UINT32_C(0x000027F1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000027F4), "Init TCP-IP manager (%d '%s') = OK\n", 35u); storage[UINT32_C(0x00002817)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002818), "Network initialize error! ", 26u); storage[UINT32_C(0x00002832)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002834), "Init TCP-IP manager (%d '%s') = ERROR\n", 38u); storage[UINT32_C(0x0000285A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000285C), "Try init TCP-IP manager (%d '%s')\n", 34u); storage[UINT32_C(0x0000287E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002880), "Connect\n", 8u); storage[UINT32_C(0x00002888)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000288C), "h\000o\000s\000t\000n\000a\000m\000e\000\000\000\000\000t\000r\000a\000v\000e\000r\000s\000a\000l\000m\000o\000d\000e\000\000\000p\000o\000r\000t", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000028C8), "Initialize\n", 11u); storage[UINT32_C(0x000028D3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000028D4), "%\000S", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000028DC), "Deinit TCP-IP manager = OK\n", 27u); storage[UINT32_C(0x000028F7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000028F8), "Release\n", 8u); storage[UINT32_C(0x00002900)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002904), "logs\\directplay", 15u); storage[UINT32_C(0x00002913)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002914), "%s(): DATA CORRUPTION\n", 22u); storage[UINT32_C(0x0000292A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000292C), "receive_netdata", 15u); storage[UINT32_C(0x0000293B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000293E), "\376B\000\376\377F\000\000\200D\000\376\377F\377\377\377\377\000\000 B\000\000\000\000\000\000\360B", 30u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000295C), " ItemName = ''%s''\n", 19u); storage[UINT32_C(0x0000296F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002974), "CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set", 90u); storage[UINT32_C(0x000029CE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000029D0), "internal error 04975350934760", 29u); storage[UINT32_C(0x000029ED)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000029F0), "internal error 34096874309", 26u); storage[UINT32_C(0x00002A0A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002A0C), "MBINTER MESSAGE: Wrong string to copy: '%s', strlen: %d\n", 56u); storage[UINT32_C(0x00002A44)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002A48), "%s_%02d%02d%02d.log", 19u); storage[UINT32_C(0x00002A5B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002A5C), "%.*s_%02d.%02d.%02d%s", 21u); storage[UINT32_C(0x00002A71)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002A74), "logs\\script.log", 15u); storage[UINT32_C(0x00002A83)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002A84), "logs\\deletings.log", 18u); storage[UINT32_C(0x00002A96)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002A98), "logs\\gm.log", 11u); storage[UINT32_C(0x00002AA3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002AA4), "logs\\trade.log", 14u); storage[UINT32_C(0x00002AB2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002AB4), "logs\\violations.log", 19u); storage[UINT32_C(0x00002AC7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002AC8), "%02i:%02i:%02i ", 15u); storage[UINT32_C(0x00002AD7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002AD8), "logs\\tmp_cl", 11u); storage[UINT32_C(0x00002AE3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002AE4), "\nError in prc call stack\n", 25u); storage[UINT32_C(0x00002AFD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002B00), "\nPrevious prc: %s\nProgram: %s\n", 30u); storage[UINT32_C(0x00002B1E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002B20), "\nCall from C++\n", 15u); storage[UINT32_C(0x00002B2F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002B30), "module:%d, code:%d. ", 20u); storage[UINT32_C(0x00002B44)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002B4C), "Warn!!! pos = %d, sBaseCodePtr = %d, Prc[pos].baseCodePtr = %d. ", 64u); storage[UINT32_C(0x00002B8C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002B90), "%x ", 3u); storage[UINT32_C(0x00002B93)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002B94), "PrcName,CodeOffs: unknown. (Offset not found)", 45u); storage[UINT32_C(0x00002BC1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002BC4), "PrcName,CodeOffs: unknown. (modulesNum == MAX_MODULES_IN_PRC)", 61u); storage[UINT32_C(0x00002C01)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002C04), "PrcName,CodeOffs: unknown. (wrong pos)", 38u); storage[UINT32_C(0x00002C2A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002C2C), " ", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002C30), "MBC-file: %s\nProgram: %s\nCall's depth: %d\nAddress: 0x%08X\n", 58u); storage[UINT32_C(0x00002C6A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002C6C), "%s\n Slice out of range! ptr = %d, ptr+offset = %d, begin = %d, end = %d", 71u); storage[UINT32_C(0x00002CB3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002CB4), "%s\n Slice out of range! ptr = %d, begin = %d, end = %d", 54u); storage[UINT32_C(0x00002CEA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002CEC), "..\\ShareClientSeverCode\\Inter.cpp", 33u); storage[UINT32_C(0x00002D0D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D10), ".mbc", 4u); storage[UINT32_C(0x00002D14)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D18), "prc_unload _main.mbl\n", 21u); storage[UINT32_C(0x00002D2D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D30), "*.dll", 5u); storage[UINT32_C(0x00002D35)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D38), "xlaunch*.exe", 12u); storage[UINT32_C(0x00002D44)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D48), "sphere*.exe", 11u); storage[UINT32_C(0x00002D53)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D54), "*.*", 3u); storage[UINT32_C(0x00002D57)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D58), "\024kQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D5C), "\320\267B", 3u); storage[UINT32_C(0x00002D5F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D60), "\320\267B\000\000\000\000\000\000\374\237@\000\000\000\000\000\000D@\000\000\000\000\000\000^@", 28u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D7C), "\r\n", 2u); storage[UINT32_C(0x00002D7E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D80), "\\kQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D84), "\320\267B", 3u); storage[UINT32_C(0x00002D87)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D88), "\320\267B\000\250kQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D90), "\320}D", 3u); storage[UINT32_C(0x00002D93)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D94), "\320\267B", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D98), " Initialize = 'ERROR'\n", 22u); storage[UINT32_C(0x00002DAE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002DB0), "Initialize complete\n", 20u); storage[UINT32_C(0x00002DC4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002DC8), "~~~~~ItemList~~~INITIALIZE~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 55u); storage[UINT32_C(0x00002DFF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002E00), " FindItem = 'ERROR'\n", 20u); storage[UINT32_C(0x00002E14)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002E18), " FindItem 'OK' = ''%s''\n", 24u); storage[UINT32_C(0x00002E30)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002E34), "~~~~~ItemList~~~FIND ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 54u); storage[UINT32_C(0x00002E6A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002E6C), " Added List = 'ERROR' ER_ITEM_NOT_ADDED\n", 40u); storage[UINT32_C(0x00002E94)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002E98), " Added List = 'ERROR' ER_ITEM_MEMORY_NOT_ALLOC\n", 47u); storage[UINT32_C(0x00002EC7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002EC8), " Added List = 'ERROR' ALREADY EXIST\n", 36u); storage[UINT32_C(0x00002EEC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002EF0), " Added List  'OK' = ''%s''\n", 27u); storage[UINT32_C(0x00002F0B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F0C), "\n-----BaseManager---ADD LIST-----------------------------------------\n", 70u); storage[UINT32_C(0x00002F52)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F54), " Delete List =  'ERROR' ER_CURITEMS_LESS_MINITEMS\n", 50u); storage[UINT32_C(0x00002F86)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F88), " Deleted List  'OK' = ''%s''\n", 29u); storage[UINT32_C(0x00002FA5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002FAC), "\n-----BaseManager---DEL LIST----------------------------------------\n", 69u); storage[UINT32_C(0x00002FF1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002FF4), "\n-----BaseManager---ADD ITEM ITEM----------------------------------------\n", 74u); storage[UINT32_C(0x0000303E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003044), " Add ItemItem    \312\356\355\345\366 \321\350\355\365\360\356\355\350\347\340\366\350\350 '\302\361\345\354 \356\362 \362\345\352\363\371\345\343\356, \362\345\352\363\371\345\354\363 \356\362 \342\361\345\365'\n", 74u); storage[UINT32_C(0x0000308E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003094), " Add ItemItem    \315\340\367\340\353\356 \321\350\355\365\360\356\355\350\347\340\366\350\350 '\302\361\345\354 \356\362 \362\345\352\363\371\345\343\356, \362\345\352\363\371\345\354\363 \356\362 \342\361\345\365'\n", 75u); storage[UINT32_C(0x000030DF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000030E0), " Add ItemItem  'ERROR' ER_ITEM_NOT_ADDED = ''%s''\n", 50u); storage[UINT32_C(0x00003112)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003114), " Add ItemItem  'ERROR' ER_ITEM_MEMORY_NOT_ALLOC = ''%s''\n", 57u); storage[UINT32_C(0x0000314D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003150), " Add pItemTo  'NOT' Found\n", 26u); storage[UINT32_C(0x0000316A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000316C), " Add pItemFrom  'NOT' Found = ''%s''\n", 37u); storage[UINT32_C(0x00003191)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003194), " Added ItemItem REWRITE = ''%s''\n", 33u); storage[UINT32_C(0x000031B5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000031B8), " Added ItemItem  'OK' = ''%s''\n", 31u); storage[UINT32_C(0x000031D7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000031D8), " Delete pItemTo 'NOT' Found\n", 28u); storage[UINT32_C(0x000031F4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000031F8), " Delete pItemFrom 'NOT' Found = ''%s''\n", 39u); storage[UINT32_C(0x0000321F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003220), " Delete ItemItem  'ERROR' ITEM NOT FOUND\n", 41u); storage[UINT32_C(0x00003249)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000324C), " Delete ItemItem ER_CURITEMS_LESS_MINITEMS = ''%s''\n", 52u); storage[UINT32_C(0x00003280)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003284), " Delete ItemItem  'OK' = ''%s''\n", 32u); storage[UINT32_C(0x000032A4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000032AC), "\n-----BaseManager---DEL ITEM ITEM----------------------------------------\n", 74u); storage[UINT32_C(0x000032F6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000032F8), " Deinitialize complete\n", 23u); storage[UINT32_C(0x0000330F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003310), "~~~~~ItemList~~~DEINITIALIZE~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 57u); storage[UINT32_C(0x00003349)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000334C), " FindFirstItem = 'ERROR'\n", 25u); storage[UINT32_C(0x00003365)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003368), " FindFirstItem 'OK' = ''%s''\n", 29u); storage[UINT32_C(0x00003385)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003388), "~~~~~ItemList~~~FIND FIRST ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 60u); storage[UINT32_C(0x000033C4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000033C8), " FindNextItem = 'ERROR'\n", 24u); storage[UINT32_C(0x000033E0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000033E4), " FindNextItem 'OK' = ''%s''\n", 28u); storage[UINT32_C(0x00003400)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003404), "~~~~~ItemList~~~FIND NEXT ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 59u); storage[UINT32_C(0x0000343F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003440), " AddItem = 'ERROR' MEMORY NOT ALLOC\n", 36u); storage[UINT32_C(0x00003464)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003468), " AddItem = 'ERROR' NOT ADD\n", 27u); storage[UINT32_C(0x00003483)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003484), " AddItem Rewrite = ''%s''\n", 26u); storage[UINT32_C(0x0000349E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000034A0), " AddItem = ''%s''\n", 18u); storage[UINT32_C(0x000034B2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000034B4), "~~~~~ItemList~~~ADD ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 53u); storage[UINT32_C(0x000034E9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000034EC), " DelItem = 'ERROR' NOT DELETE\n", 30u); storage[UINT32_C(0x0000350A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000350C), " DelItem = CurItems Less Than CurMax\n", 37u); storage[UINT32_C(0x00003531)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003534), " DelItem 'OK' = ''%s''\n", 23u); storage[UINT32_C(0x0000354B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000354C), "~~~~~ItemList~~~DEL ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 53u); storage[UINT32_C(0x00003581)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003584), ". . . . . . . \n", 15u); storage[UINT32_C(0x00003593)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003594), "~~~~~ItemList~~~ALL ITEMS~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 54u); storage[UINT32_C(0x000035CA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000035CC), "EError", 6u); storage[UINT32_C(0x000035D2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000035D4), "---exit_inter end-----\n", 23u); storage[UINT32_C(0x000035EB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000035EC), "\n---exit_inter start---\nMBINTER MESSAGE:", 40u); storage[UINT32_C(0x00003614)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000361C), "prc_link - memory allocation found in base process, pointer corruption quite possible.", 86u); storage[UINT32_C(0x00003672)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003674), "Cannot link a process - increase MAX_LINKED_PRCS! Linked prc: ", 62u); storage[UINT32_C(0x000036B2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000036B4), "Unknown script code: ", 21u); storage[UINT32_C(0x000036C9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000036CC), "Unlinked function was called", 28u); storage[UINT32_C(0x000036E8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000036EC), "Stack of stacks overflow", 24u); storage[UINT32_C(0x00003704)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003708), "Stack of stacks devastation", 27u); storage[UINT32_C(0x00003723)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003724), "Return to defunct process", 25u); storage[UINT32_C(0x0000373D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003740), "fo12(): return stack underflow", 30u); storage[UINT32_C(0x0000375E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003760), "Division by zero", 16u); storage[UINT32_C(0x00003770)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003774), "fo27(): stack underflow", 23u); storage[UINT32_C(0x0000378B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000378C), "Wrong number of parameters (must be %d, present %d)", 51u); storage[UINT32_C(0x000037BF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000037C0), "fo31(): stack underflow", 23u); storage[UINT32_C(0x000037D7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000037D8), "Too long data for region", 24u); storage[UINT32_C(0x000037F0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000037F7), "`0_D@\000\000\000\000\000@\217@\000\000\000\000\000@\217\300", 21u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000380C), "HashMap::init:  hashTabSize must be power of 2", 46u); storage[UINT32_C(0x0000383A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000383C), "HashMap::init: wrong _maxKeyLen=%d", 34u); storage[UINT32_C(0x0000385E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003864), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h", 82u); storage[UINT32_C(0x000038B6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000038B8), "HashMap::init: wrong _startSize=%d", 34u); storage[UINT32_C(0x000038DA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000038DC), ". . . . . . . . . \n", 19u); storage[UINT32_C(0x000038EF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000038F0), "List Name = ''%s'', min = %d, curmax = %d, cur = %d\n", 52u); storage[UINT32_C(0x00003924)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003928), "\n-----BaseManager---ALL LISTS----------------------------\n", 58u); storage[UINT32_C(0x00003962)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003964), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\ItemList.h", 91u); storage[UINT32_C(0x000039BF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000039C0), "HashMap::insert: more than maxIndexVal elements", 47u); storage[UINT32_C(0x000039EF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000039F0), "HashMap::insert: maxKeyLen exceed", 33u); storage[UINT32_C(0x00003A11)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003A14), "Return stack overflow", 21u); storage[UINT32_C(0x00003A29)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003A2C), "popint(): stack underflow", 25u); storage[UINT32_C(0x00003A45)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003A48), "popsliceref(): stack underflow", 30u); storage[UINT32_C(0x00003A66)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003A68), "Too few parameters", 18u); storage[UINT32_C(0x00003A7A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003A7C), "popsliceup(): stack underflow", 29u); storage[UINT32_C(0x00003A99)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003A9C), "popsliceupref(): stack underflow", 32u); storage[UINT32_C(0x00003ABC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003AC0), "Stack overflow", 14u); storage[UINT32_C(0x00003ACE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003AD0), "pushpointer(): stack overflow", 29u); storage[UINT32_C(0x00003AED)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003AF0), ",lQ\000\320}D\000\320\267B\0000\261C\0000\261C\000\360\031B", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003B08), "%s\nArray boundary error: array size = %d, index = %d", 52u); storage[UINT32_C(0x00003B3C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003B40), "%s\nArray2 boundary error: array size = %d, index = %d", 53u); storage[UINT32_C(0x00003B75)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003B78), "MBInter:\n %f", 12u); storage[UINT32_C(0x00003B84)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003B93), "?", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003B94), "NULL-pointer dereferencing: ffprc_load\n", 39u); storage[UINT32_C(0x00003BBB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003BBC), "Unloading _main: %s:%d", 22u); storage[UINT32_C(0x00003BD2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003BD4), "NULL-pointer dereferencing: ffprc_link\n", 39u); storage[UINT32_C(0x00003BFB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003BFC), "NULL-pointer dereferencing: ffprc_id\n", 37u); storage[UINT32_C(0x00003C21)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003C24), "Double \"func\" call, prob. stack corruption: %s (prc %d, tag %d), called from (prc %d, tag %d).\n", 95u); storage[UINT32_C(0x00003C83)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003C84), "Wrong region for 'send' function", 32u); storage[UINT32_C(0x00003CA4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003CA8), "Wrong data for 'send' function", 30u); storage[UINT32_C(0x00003CC6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003CC8), "Wrong number of parameters for 'send' function", 46u); storage[UINT32_C(0x00003CF6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003CF8), "Wrong flags for 'send' function", 31u); storage[UINT32_C(0x00003D17)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003D18), "Wrong region for 'receive' function", 35u); storage[UINT32_C(0x00003D3B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003D3C), "Wrong number of parameters for 'receive' function", 49u); storage[UINT32_C(0x00003D6D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003D70), "Wrong data for 'receive' function", 33u); storage[UINT32_C(0x00003D91)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003D97), "`\373!\231?", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003D9C), "Size mismatch: ffstrcat\n", 24u); storage[UINT32_C(0x00003DB4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003DB8), "ffstrlen(): end of string was not found in buffer of size %d\n", 61u); storage[UINT32_C(0x00003DF5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003DF8), "ffstrlen(): NULL-pointer dereferencing\n", 39u); storage[UINT32_C(0x00003E1F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003E20), "logs\\chat", 9u); storage[UINT32_C(0x00003E29)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003E2C), "logs\\bigmoney", 13u); storage[UINT32_C(0x00003E39)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003E3C), "logs\\gtstatout", 14u); storage[UINT32_C(0x00003E4A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003E4C), "logs\\gtstatin", 13u); storage[UINT32_C(0x00003E59)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003E5C), "logs\\mstatout", 13u); storage[UINT32_C(0x00003E69)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003E6C), "logs\\mstatin", 12u); storage[UINT32_C(0x00003E78)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003E7C), "logs\\goldtaler", 14u); storage[UINT32_C(0x00003E8A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003E8C), "logs\\add_exp", 12u); storage[UINT32_C(0x00003E98)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003E9C), "logs\\old_things", 15u); storage[UINT32_C(0x00003EAB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003EAC), "Invalid parameter list: fflogf()", 32u); storage[UINT32_C(0x00003ECC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003ED0), "logs\\%s", 7u); storage[UINT32_C(0x00003ED7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003ED8), "NULL-pointer dereferencing: ffflogf, pchFormatString\n", 53u); storage[UINT32_C(0x00003F0D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003F10), "NULL-pointer dereferencing: ffflogf, pchFileName\n", 49u); storage[UINT32_C(0x00003F41)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003F44), "Invalid parameter list: ffflogf()", 33u); storage[UINT32_C(0x00003F65)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003F68), "NULL-pointer dereferencing: ffcreate\n", 37u); storage[UINT32_C(0x00003F8D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003F90), "NULL-pointer dereferencing: ffopen\n", 35u); storage[UINT32_C(0x00003FB3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003FB4), "NULL-pointer dereferencing: ffread\n", 35u); storage[UINT32_C(0x00003FD7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003FD8), "Error creating object: %s", 25u); storage[UINT32_C(0x00003FF1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003FF9), "\320t@", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003FFC), "Wrong parameters for 'text' function", 36u); storage[UINT32_C(0x00004020)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004024), "Error creating sprite", 21u); storage[UINT32_C(0x00004039)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000403C), "Wrong number of parameters: ffsprintf", 37u); storage[UINT32_C(0x00004061)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004064), "NULL-pointer dereferencing: ffmempcpy\n", 38u); storage[UINT32_C(0x0000408A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000408C), "NULL-pointer dereferencing: ffg_norm\n", 37u); storage[UINT32_C(0x000040B1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000040B4), "g_norm: wrong type of parameter (must be float pointer)\n", 56u); storage[UINT32_C(0x000040EC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000040F0), "NULL-pointer dereferencing: ffg_abg\n", 36u); storage[UINT32_C(0x00004114)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004118), "Wrong number of parameters: ffsnprintf", 38u); storage[UINT32_C(0x0000413E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004140), "NULL-pointer dereferencing: ffeditor, EDSC_GETCLICKPOINT\n", 57u); storage[UINT32_C(0x00004179)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000417C), "NULL-pointer dereferencing: window, GET_WINDOW_TEXTGUI\n", 55u); storage[UINT32_C(0x000041B3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000041B4), "NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 4\n", 55u); storage[UINT32_C(0x000041EB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000041EC), "NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 3\n", 55u); storage[UINT32_C(0x00004223)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004224), "NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 2\n", 55u); storage[UINT32_C(0x0000425B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000425C), "NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 1\n", 55u); storage[UINT32_C(0x00004293)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004294), "Error creating GUI window", 25u); storage[UINT32_C(0x000042AD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000042B0), "options", 7u); storage[UINT32_C(0x000042B7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000042B8), "NULL-pointer dereferencing: window, GET_WINDOW_POS, 2\n", 54u); storage[UINT32_C(0x000042EE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000042F0), "NULL-pointer dereferencing: window, GET_WINDOW_POS, 1\n", 54u); storage[UINT32_C(0x00004326)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004328), "NULL-pointer dereferencing: window, GET_SYSTEM_MESSAGE\n", 55u); storage[UINT32_C(0x0000435F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004360), "NULL-pointer dereferencing: window, GET_WINDOW_TEXT\n", 52u); storage[UINT32_C(0x00004394)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004398), "NULL-pointer dereferencing: window, PEEK_MESSAGE, 5\n", 52u); storage[UINT32_C(0x000043CC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000043D0), "NULL-pointer dereferencing: window, PEEK_MESSAGE, 4\n", 52u); storage[UINT32_C(0x00004404)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004408), "NULL-pointer dereferencing: window, PEEK_MESSAGE, 3\n", 52u); storage[UINT32_C(0x0000443C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004440), "NULL-pointer dereferencing: window, PEEK_MESSAGE, 2\n", 52u); storage[UINT32_C(0x00004474)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004478), "NULL-pointer dereferencing: window, PEEK_MESSAGE, 1\n", 52u); storage[UINT32_C(0x000044AC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000044B0), "NULL-pointer dereferencing: window, W_GETCURXY, 2\n", 50u); storage[UINT32_C(0x000044E2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000044E4), "NULL-pointer dereferencing: window, W_GETCURXY, 1\n", 50u); storage[UINT32_C(0x00004516)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004518), "NULL-pointer dereferencing: window, W_TEXTSIZE, 2\n", 50u); storage[UINT32_C(0x0000454A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000454C), "NULL-pointer dereferencing: window, W_TEXTSIZE, 1\n", 50u); storage[UINT32_C(0x0000457E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004580), "NULL-pointer dereferencing: window, W_WINCON, 2\n", 48u); storage[UINT32_C(0x000045B0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000045B4), "NULL-pointer dereferencing: window, W_WINCON, 1\n", 48u); storage[UINT32_C(0x000045E4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000045E8), "NULL-pointer dereferencing: window, W_EVENT, 2\n", 47u); storage[UINT32_C(0x00004617)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004618), "NULL-pointer dereferencing: window, W_EVENT, 1\n", 47u); storage[UINT32_C(0x00004647)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004648), "Error creating window", 21u); storage[UINT32_C(0x0000465D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004660), "NULL-pointer dereferencing: thisname\n", 37u); storage[UINT32_C(0x00004685)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004688), "NULL-pointer dereferencing: prc_name\n", 37u); storage[UINT32_C(0x000046AD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000046B0), "Wrong Handler for Effect %s\n", 28u); storage[UINT32_C(0x000046CC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000046D0), "Effect attached to zero handle!", 31u); storage[UINT32_C(0x000046EF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000046F0), "ffdmalloc: ptr != NULL", 22u); storage[UINT32_C(0x00004706)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000470C), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\basemanager.h", 94u); storage[UINT32_C(0x0000476A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000476C), "poppointerup(): unexpected NULL-pointer fetched", 47u); storage[UINT32_C(0x0000479B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000479C), "PlayersLists", 12u); storage[UINT32_C(0x000047A8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000047AC), "ffparse(). Invalid parsing type", 31u); storage[UINT32_C(0x000047CB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000047CC), "WorldMap.bmp", 12u); storage[UINT32_C(0x000047D8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000047DC), "-------------------------CONNECTION_LOST_NOTIFICATION\n", 54u); storage[UINT32_C(0x00004812)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004814), "NULL-pointer dereferencing: chat, SYS_SET_USER_NAME, 1\n", 55u); storage[UINT32_C(0x0000484B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000484C), "open", 4u); storage[UINT32_C(0x00004850)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004854), "%02d:%02d:%02d", 14u); storage[UINT32_C(0x00004862)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004864), "%d-%02d-%02d ", 13u); storage[UINT32_C(0x00004871)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004874), "%I64u", 5u); storage[UINT32_C(0x00004879)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000487C), "C:\\", 3u); storage[UINT32_C(0x0000487F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004880), "NULL-pointer dereferencing: ffsys, G_VERSION\n", 45u); storage[UINT32_C(0x000048AD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000048B9), "\260\177@\000\200\200C", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000048C9), "@n\300\000\000\000\000\000\300~\300\000\2009\304\000\000\214B", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000048DC), "NULL-pointer dereferencing: ffsys, G_PLANT, 3\n", 46u); storage[UINT32_C(0x0000490A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000490C), "NULL-pointer dereferencing: ffsys, G_PLANT, 2\n", 46u); storage[UINT32_C(0x0000493A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000493C), "NULL-pointer dereferencing: ffsys, G_PLANT, 1\n", 46u); storage[UINT32_C(0x0000496A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000496C), "NULL-pointer dereferencing: ffsys, MAP_PICSIZE, 3\n", 50u); storage[UINT32_C(0x0000499E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000049A0), "NULL-pointer dereferencing: ffsys, MAP_PICSIZE, 2\n", 50u); storage[UINT32_C(0x000049D2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000049D4), "NULL-pointer dereferencing: ffsys, MAP_PICSIZE, 1\n", 50u); storage[UINT32_C(0x00004A06)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004A08), "NULL-pointer dereferencing: ffsys, MAP_SAVE\n", 44u); storage[UINT32_C(0x00004A34)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004A38), "NULL-pointer dereferencing: ffsys, MAP_LOAD\n", 44u); storage[UINT32_C(0x00004A64)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004A68), "NULL-pointer dereferencing: ffsys, GZ_UNPACK, 2\n", 48u); storage[UINT32_C(0x00004A98)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004A9C), "NULL-pointer dereferencing: ffsys, GZ_UNPACK, 1\n", 48u); storage[UINT32_C(0x00004ACC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004AD0), "NULL-pointer dereferencing: ffsys, GZ_PACK, 2\n", 46u); storage[UINT32_C(0x00004AFE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004B00), "NULL-pointer dereferencing: ffsys, GZ_PACK, 1\n", 46u); storage[UINT32_C(0x00004B2E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004B30), "NULL-pointer dereferencing: ffsys, PLAY_MUSIC\n", 46u); storage[UINT32_C(0x00004B5E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004B60), "NULL-pointer dereferencing: ffsys, LINK_ON\n", 43u); storage[UINT32_C(0x00004B8B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004B8C), "NULL-pointer dereferencing: ffsys, G_CURSDIR\n", 45u); storage[UINT32_C(0x00004BB9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004BBC), "NULL-pointer dereferencing: ffsys, G_MOUSEXY, 2\n", 48u); storage[UINT32_C(0x00004BEC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004BF0), "NULL-pointer dereferencing: ffsys, G_MOUSEXY, 1\n", 48u); storage[UINT32_C(0x00004C20)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004C24), "NULL-pointer dereferencing: ffsys, FINDNEXT\n", 44u); storage[UINT32_C(0x00004C50)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004C54), "NULL-pointer dereferencing: ffsys, FINDFIRST\n", 45u); storage[UINT32_C(0x00004C81)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004C84), "NULL-pointer dereferencing: ffsys, G_ERRMSG\n", 44u); storage[UINT32_C(0x00004CB0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004CB7), "`\347\373\357?\000\000\000\000\000\200\266@", 13u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00004CC4), "NULL-pointer dereferencing: ffsys, G_GROUND\n", 44u); storage[UINT32_C(0x00004CF0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004CF4), "\361h\343\210\265\370\344>wrong parameter in cfg_get, '%s'\n", 41u); storage[UINT32_C(0x00004D1D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004D20), "%s\t%s", 5u); storage[UINT32_C(0x00004D25)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004D28), "%s\t\"%s\"", 7u); storage[UINT32_C(0x00004D2F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004D30), "MBInter: Process '_main' not found", 34u); storage[UINT32_C(0x00004D52)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004D54), "_main", 5u); storage[UINT32_C(0x00004D59)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004D5C), "PORT", 4u); storage[UINT32_C(0x00004D60)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004D64), "connectn.cfg", 12u); storage[UINT32_C(0x00004D70)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004D74), "Null tag %s", 11u); storage[UINT32_C(0x00004D7F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004D80), "mbc\\*.mbc", 9u); storage[UINT32_C(0x00004D89)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004D8C), "__debug.mbc", 11u); storage[UINT32_C(0x00004D97)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004D98), "-r", 2u); storage[UINT32_C(0x00004D9A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004D9C), " %s", 3u); storage[UINT32_C(0x00004D9F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004DA0), "Endless cycle found", 19u); storage[UINT32_C(0x00004DB3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004DB4), "=== Player ===\n", 15u); storage[UINT32_C(0x00004DC3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004DC4), "ID=%d", 5u); storage[UINT32_C(0x00004DC9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004DCC), "--- Player ---\n", 15u); storage[UINT32_C(0x00004DDB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004DDC), "EPHalt", 6u); storage[UINT32_C(0x00004DE2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004DE4), "-------------------------------------- ", 39u); storage[UINT32_C(0x00004E0B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004E0C), "NULL-pointer dereferencing: list, L_FINDITEM, 4\n", 48u); storage[UINT32_C(0x00004E3C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004E40), "NULL-pointer dereferencing: list, L_FINDITEM, 3\n", 48u); storage[UINT32_C(0x00004E70)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004E74), "NULL-pointer dereferencing: list, L_FINDITEM, 2\n", 48u); storage[UINT32_C(0x00004EA4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004EA8), "NULL-pointer dereferencing: list, L_FINDITEM, 1\n", 48u); storage[UINT32_C(0x00004ED8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004EDC), "NULL-pointer dereferencing: list, L_FNITEM, 4\n", 46u); storage[UINT32_C(0x00004F0A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004F0C), "NULL-pointer dereferencing: list, L_FNITEM, 3\n", 46u); storage[UINT32_C(0x00004F3A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004F3C), "NULL-pointer dereferencing: list, L_FNITEM, 2\n", 46u); storage[UINT32_C(0x00004F6A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004F6C), "NULL-pointer dereferencing: list, L_FNITEM, 1\n", 46u); storage[UINT32_C(0x00004F9A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004F9C), "NULL-pointer dereferencing: list, L_FFITEM, 4\n", 46u); storage[UINT32_C(0x00004FCA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004FCC), "NULL-pointer dereferencing: list, L_FFITEM, 3\n", 46u); storage[UINT32_C(0x00004FFA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004FFC), "NULL-pointer dereferencing: list, L_FFITEM, 2\n", 46u); storage[UINT32_C(0x0000502A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000502C), "NULL-pointer dereferencing: list, L_FFITEM, 1\n", 46u); storage[UINT32_C(0x0000505A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000505C), "ID-: '%s' '%s' ", 15u); storage[UINT32_C(0x0000506B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000506C), "IA+: '%s' '%s' ", 15u); storage[UINT32_C(0x0000507B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000507C), "LD: '%s' ", 9u); storage[UINT32_C(0x00005085)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005088), "LA: '%s' ", 9u); storage[UINT32_C(0x00005091)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005094), "ffchat_utility(). Invalid Chat utility function type", 52u); storage[UINT32_C(0x000050C8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000050CE), "\376B\000\376\377F\000\000\200D\000\376\377F\334\017I@", 18u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000050E0), "..\\ShareClientSeverCode\\light.cpp", 33u); storage[UINT32_C(0x00005101)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000510A), "?@", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000510C), "  ", 2u); storage[UINT32_C(0x0000510E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005110), "|lQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005114), "0\262D", 3u); storage[UINT32_C(0x00005117)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005118), "\320\263B\000\320\263B\000@\263D\000\200\263D\000\260\263D\000\300\263D\000@\264D\000\320\267B\000`_B\000\220_B\000\020\265D", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005144), "light_source.eff", 16u); storage[UINT32_C(0x00005154)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005158), "..\\ShareClientSeverCode\\LightEffect.cpp", 39u); storage[UINT32_C(0x0000517F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005180), "CLightEffect::SetParameter() -> Unrecognized parameter %d", 57u); storage[UINT32_C(0x000051B9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000051BC), "logo\000\000\000\000slider2\000slider1\000menu2\000\000\000menu1\000\000\000glow", 44u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000051EC), "black", 5u); storage[UINT32_C(0x000051F1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000051F4), "noice\000\000\000menufon\000back_cam\000\000\000\000back_spe\000\000\000\000back_axe\000\000\000\000back_ara\000\000\000\000back_swo\000\000\000\000\000\000\376B\000\376\377F\000\000\200D\000\376\377F\334\017I@\000\000\000\000UU\005A\217\302\365=\027\267Q9\000\000HB\n\327\243<o\022\203:\232\231\231>\000\000@?X\377\177?\177\275\302\202\373!\371?\000\000\000\200\265\370\344>", 152u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000528C), "ErrorTest.log", 13u); storage[UINT32_C(0x00005299)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000529C), "%d\n", 3u); storage[UINT32_C(0x0000529F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000052A0), "%f\n", 3u); storage[UINT32_C(0x000052A3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000052A4), "%A, %d %B %Y", 12u); storage[UINT32_C(0x000052B0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000052B4), "..\\ShareClientSeverCode\\main.cpp", 32u); storage[UINT32_C(0x000052D4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000052D8), "Debug", 5u); storage[UINT32_C(0x000052DD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000052EA), "\276?", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000052EC), "FPS: %4.1f", 10u); storage[UINT32_C(0x000052F6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005301), "\210\303@\000\000\000\277", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005308), "Error", 5u); storage[UINT32_C(0x0000530D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005310), "Critical", 8u); storage[UINT32_C(0x00005318)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000531C), "\"", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000532A), "\220@\000\000\000@33\343?\000\000\000@\341z\224?\215\355\265\240\367\306\260>", 26u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005344), "*************************************************************************\n", 74u); storage[UINT32_C(0x0000538E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005390), "logs\\Warnings00.log", 19u); storage[UINT32_C(0x000053A3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000053A4), "landscape_rd\\", 13u); storage[UINT32_C(0x000053B1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000053B4), "landscape_ph\\", 13u); storage[UINT32_C(0x000053C1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000053C4), "landscape_hr\\", 13u); storage[UINT32_C(0x000053D1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000053D4), ".siz", 4u); storage[UINT32_C(0x000053D8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000053DC), "landscape\\", 10u); storage[UINT32_C(0x000053E6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000053E8), "wb", 2u); storage[UINT32_C(0x000053EA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000053EC), "lndbug.tga", 10u); storage[UINT32_C(0x000053F6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005402), "p@", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005404), "*\343\337g\\8`?", 8u); storage[UINT32_C(0x0000540C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000540F), "\340\3426*?\000\000HC", 9u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005422), "<@\000\000\360A\000\000\240A", 10u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000542C), "loadcount.bin", 13u); storage[UINT32_C(0x00005439)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000543C), "\200\300\312)\207\026\251?{y\001\366j\016 ?\000\000\000\000\000\000,@\000\000\000@\341z\204?", 32u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000545C), "9Y\301\214\373!\231?", 8u); storage[UINT32_C(0x00005464)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005467), "@0_D@\000\000\200\000\000\000\000\000\000\000\000\340MbP?\000\000\000\340\243\000Y@\000\000\000 \\\377X@", 37u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000548C), "\n\327#\274auto", 8u); storage[UINT32_C(0x00005494)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005498), "GetPos: wrong handle", 20u); storage[UINT32_C(0x000054AC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000054B0), "GetAngles: wrong handle", 23u); storage[UINT32_C(0x000054C7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000054C8), "GetObjectPointer: wrong handle", 30u); storage[UINT32_C(0x000054E6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000054E8), "internal error 86557243", 23u); storage[UINT32_C(0x000054FF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005500), "internal error 75248635", 23u); storage[UINT32_C(0x00005517)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005518), "GetWindowPointer: wrong handle", 30u); storage[UINT32_C(0x00005536)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005538), "Project_TopCharToScreen: wrong handle", 37u); storage[UINT32_C(0x0000555D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005560), "delete_sprite: wrong handle", 27u); storage[UINT32_C(0x0000557B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000557C), "GetObjectPos: wrong handle", 26u); storage[UINT32_C(0x00005596)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005598), "GetObjectOrient: wrong handle", 29u); storage[UINT32_C(0x000055B5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000055B8), "DeleteLight: wrong handle", 25u); storage[UINT32_C(0x000055D1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000055D7), "`ff\366?\000\000\000\000\000\200F@", 13u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000055E4), "default", 7u); storage[UINT32_C(0x000055EB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000055F2), "\211@\000\000\226C\000\000\000\000\000\000\000\240/\033\304?", 18u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005604), "}\331 >delete_text: wrong handle", 29u); storage[UINT32_C(0x00005621)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005624), "Wrong hand was used!", 20u); storage[UINT32_C(0x00005638)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000563E), "4C", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005640), "\315\314L>", 4u); storage[UINT32_C(0x00005644)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005645), "@\203D\000\000\202D\000\000\026C\000\000\216B\000\000<B\000\000\230A\000\000@A\000\000\024B\000\000lB\000@yD", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000566C), "\200\313\256\310F\337\241?", 8u); storage[UINT32_C(0x00005674)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005678), "+\207\356?\000\000\000@33\323\277", 12u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005684), "\214\312VJ0_\304?\214\312VJ0_\324?", 16u); storage[UINT32_C(0x00005694)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005697), "\200\373!\371?", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000569C), "stars", 5u); storage[UINT32_C(0x000056A1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000056AA), "@@\000\000\000\240\231\2319@\000\000\000\340QU\365?\000\000\000B\315\314\314A\000\000\000\000\000\000\300?", 34u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000056CC), "delete_window: wrong handle", 27u); storage[UINT32_C(0x000056E7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000056E8), "\027\267\3218", 4u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000056EC), "DeleteObject: wrong handle", 26u); storage[UINT32_C(0x00005706)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005708), "Wrong handle: Link_object_to_object\n", 36u); storage[UINT32_C(0x0000572C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005730), ".log", 4u); storage[UINT32_C(0x00005734)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005738), "\n\n", 2u); storage[UINT32_C(0x0000573A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000573C), "**** Quit: ", 11u); storage[UINT32_C(0x00005747)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005748), "Reenter in epilog detected!", 27u); storage[UINT32_C(0x00005763)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005764), "\316\370\350\341\352\340", 6u); storage[UINT32_C(0x0000576A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000576C), "ServerN=%d  ", 12u); storage[UINT32_C(0x00005778)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000577C), "Reenter in exit_msg detected!", 29u); storage[UINT32_C(0x00005799)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000579C), ", ", 2u); storage[UINT32_C(0x0000579E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000057A0), "\316\370\350\341\352\340 \347\340\352\360\373\362\350\377 \364\340\351\353\340: ", 23u); storage[UINT32_C(0x000057B7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000057B8), "\316\370\350\341\352\340 \357\356\347\350\366\350\356\355\350\360\356\342\340\355\350\377 \342 \364\340\351\353\345: ", 33u); storage[UINT32_C(0x000057D9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000057DC), "\316\370\350\341\352\340 \347\340\357\350\361\350 \364\340\351\353\340: ", 21u); storage[UINT32_C(0x000057F1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000057F4), "\316\370\350\341\352\340 \347\340\357\350\361\350 \364\340\351\353\340 (\342\356\347\354\356\346\355\356, \355\345\362 \354\345\361\362\340 \355\340 \344\350\361\352\345): ", 52u); storage[UINT32_C(0x00005828)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000582C), "\316\370\350\341\352\340 \367\362\345\355\350\377 \364\340\351\353\340: ", 21u); storage[UINT32_C(0x00005841)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005844), "\315\345\356\346\350\344\340\355\355\373\351 \352\356\355\345\366 \364\340\351\353\340: ", 25u); storage[UINT32_C(0x0000585D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005860), "\316\370\350\341\352\340 \361\356\347\344\340\355\350\377 \364\340\351\353\340: ", 23u); storage[UINT32_C(0x00005877)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005878), "\316\370\350\341\352\340 \356\362\352\360\373\362\350\377 \364\340\351\353\3403: ", 24u); storage[UINT32_C(0x00005890)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005894), "CreateWindowEx() failed! => init_main_window()", 46u); storage[UINT32_C(0x000058C2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000058C4), "Sphere", 6u); storage[UINT32_C(0x000058CA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000058CC), "wrong format of font1.txt", 25u); storage[UINT32_C(0x000058E5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000058E8), "Symbol for CODE_FOR_UNDIFINED_SYMBOL is not found in font.txt", 61u); storage[UINT32_C(0x00005925)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005928), "fonts\\font.txt", 14u); storage[UINT32_C(0x00005936)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005938), "fonts\\font%s.txt", 16u); storage[UINT32_C(0x00005948)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000594C), "normalize: normal with extra short length found. Code:", 54u); storage[UINT32_C(0x00005982)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005984), "MapViewOfFile failed  ", 22u); storage[UINT32_C(0x0000599A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000599C), "CreateFileMapping failed", 24u); storage[UINT32_C(0x000059B4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000059B8), "\316\370\350\341\352\340 \356\362\352\360\373\362\350\377 \364\340\351\353\3402: ", 24u); storage[UINT32_C(0x000059D0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000059D4), "SetProperty failed", 18u); storage[UINT32_C(0x000059E6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000059E8), "SetDataFormat failed", 20u); storage[UINT32_C(0x000059FC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005A00), "SetCooperativeLevel failed", 26u); storage[UINT32_C(0x00005A1A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005A1C), "CreateDevice failed", 19u); storage[UINT32_C(0x00005A2F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005A30), "DirectInputCreate failed", 24u); storage[UINT32_C(0x00005A48)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005A4C), "text_color: wrong handle", 24u); storage[UINT32_C(0x00005A64)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005A6F), "\240|\331\022@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005A74), "create_line: wrong handle", 25u); storage[UINT32_C(0x00005A8D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005A90), "MNO_LINES_IN_TEXT exceeded", 26u); storage[UINT32_C(0x00005AAA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005AAC), "Too many landscape files\n", 25u); storage[UINT32_C(0x00005AC5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005AC8), "*.siz files not found", 21u); storage[UINT32_C(0x00005ADD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005AE0), "*.siz", 5u); storage[UINT32_C(0x00005AE5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005AE8), "Patch present in map, but not found in \\landscape. Name: ", 57u); storage[UINT32_C(0x00005B21)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005B24), "FILL_EMPT", 9u); storage[UINT32_C(0x00005B2D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005B30), "landscape\\map.bin", 17u); storage[UINT32_C(0x00005B41)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005B44), "Base microtexture not found: landscape\\??_.mtx", 46u); storage[UINT32_C(0x00005B72)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005B74), "landscape_rd\\*.mtx", 18u); storage[UINT32_C(0x00005B86)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005B88), "landscape_ph\\*.mtx", 18u); storage[UINT32_C(0x00005B9A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005B9C), "landscape_hr\\*.mtx", 18u); storage[UINT32_C(0x00005BAE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005BB0), "landscape\\*.mtx", 15u); storage[UINT32_C(0x00005BBF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005BC4), "Error of smoothing region's edge: numbers of vertex groups are differ", 69u); storage[UINT32_C(0x00005C09)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005C0C), "Landscape\\zoningHaron.cfg", 25u); storage[UINT32_C(0x00005C25)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005C28), "Landscape\\zoning.cfg", 20u); storage[UINT32_C(0x00005C3C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005C40), "\217\302u=cursor1", 11u); storage[UINT32_C(0x00005C4B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005C4C), "RENDERSHADOW", 12u); storage[UINT32_C(0x00005C58)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005C5C), "ESCNOQUERY", 10u); storage[UINT32_C(0x00005C66)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005C68), "RUNTIME", 7u); storage[UINT32_C(0x00005C6F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005C70), "debug.cfg", 9u); storage[UINT32_C(0x00005C79)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005C7C), "BeginDraw has returned texture size != 256x256", 46u); storage[UINT32_C(0x00005CAA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005CAC), "BeginDraw has returned NULL", 27u); storage[UINT32_C(0x00005CC7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005CC8), "moon", 4u); storage[UINT32_C(0x00005CCC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005CD0), "sun", 3u); storage[UINT32_C(0x00005CD3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005CDA), "\204@", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005CDC), "Try to get extended from superstatic: %s, %s:%d", 47u); storage[UINT32_C(0x00005D0B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005D0C), "<none>", 6u); storage[UINT32_C(0x00005D12)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005D14), "%s\t%d\n", 6u); storage[UINT32_C(0x00005D1A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005D1C), "GetProcess: wrong handle", 24u); storage[UINT32_C(0x00005D34)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005D38), "GetSubAnimLen: wrong handle", 27u); storage[UINT32_C(0x00005D53)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005D54), "GetSubAnimLen: negative subanimation number", 43u); storage[UINT32_C(0x00005D7F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005D80), "GetSubAnimLen: model has no animation", 37u); storage[UINT32_C(0x00005DA5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005DA8), "GetAnimation: wrong handle", 26u); storage[UINT32_C(0x00005DC2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005DC4), "GetFrame: wrong handle", 22u); storage[UINT32_C(0x00005DDA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005DDC), "GetInterp: wrong handle", 23u); storage[UINT32_C(0x00005DF3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005DF4), "GetFrame2: wrong handle", 23u); storage[UINT32_C(0x00005E0B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005E0C), "GetAnimation2: wrong handle", 27u); storage[UINT32_C(0x00005E27)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005E28), "CalcCharacterNeck: wrong frame 2", 32u); storage[UINT32_C(0x00005E48)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005E4C), "CalcCharacterNeck: wrong animation 2", 36u); storage[UINT32_C(0x00005E70)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005E74), "CalcCharacterNeck: wrong frame", 30u); storage[UINT32_C(0x00005E92)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005E94), "CalcCharacterNeck: wrong animation", 34u); storage[UINT32_C(0x00005EB6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005EB8), "CalcCharacterNeck: wrong handle", 31u); storage[UINT32_C(0x00005ED7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005ED8), "MNO_CONTROLS_IN_WINDOW exceed", 29u); storage[UINT32_C(0x00005EF5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005EF8), "draw_window: wrong handle", 25u); storage[UINT32_C(0x00005F11)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005F14), "internal error 37185837", 23u); storage[UINT32_C(0x00005F2B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005F2C), "wf_bord", 7u); storage[UINT32_C(0x00005F33)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005F36), "@=\000\000\300<", 6u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005F3C), "winfon", 6u); storage[UINT32_C(0x00005F42)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005F44), "set_sprite_alpha: wrong handle", 30u); storage[UINT32_C(0x00005F62)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005F64), "recalc_virtual_window_size: wrong handle", 40u); storage[UINT32_C(0x00005F8C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005F90), "internal error 47581837", 23u); storage[UINT32_C(0x00005FA7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005FB1), "j\370@\000\000\000\340Q\270\276?", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005FBC), "GetHandPosL: wrong handle", 25u); storage[UINT32_C(0x00005FD5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005FD8), "GetHandPosR: wrong handle", 25u); storage[UINT32_C(0x00005FF1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005FF4), "GetSwordPos: wrong handle", 25u); storage[UINT32_C(0x0000600D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006010), "GetHandOrientL: wrong handle", 28u); storage[UINT32_C(0x0000602C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006030), "GetHandOrientR: wrong handle", 28u); storage[UINT32_C(0x0000604C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006050), "GetSwordOrient: wrong handle", 28u); storage[UINT32_C(0x0000606C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006070), "GetLight: wrong handle", 22u); storage[UINT32_C(0x00006086)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006088), "ActivateLight: num of active lights > 8. Source line = %d", 57u); storage[UINT32_C(0x000060C1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000060C4), "fill", 4u); storage[UINT32_C(0x000060C8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000060CC), "GRASS_PATTERNS_NUM exeeded", 26u); storage[UINT32_C(0x000060E6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000060E8), "100", 3u); storage[UINT32_C(0x000060EB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000060EC), "102", 3u); storage[UINT32_C(0x000060EF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000060F0), "101", 3u); storage[UINT32_C(0x000060F3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000060F4), "001", 3u); storage[UINT32_C(0x000060F7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000060F8), "017", 3u); storage[UINT32_C(0x000060FB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000060FC), "015", 3u); storage[UINT32_C(0x000060FF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006100), "012", 3u); storage[UINT32_C(0x00006103)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006104), "013", 3u); storage[UINT32_C(0x00006107)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006108), "007", 3u); storage[UINT32_C(0x0000610B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000610C), "1_51", 4u); storage[UINT32_C(0x00006110)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006114), "016", 3u); storage[UINT32_C(0x00006117)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006118), "011", 3u); storage[UINT32_C(0x0000611B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000611C), "000", 3u); storage[UINT32_C(0x0000611F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006120), "010", 3u); storage[UINT32_C(0x00006123)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006124), "005", 3u); storage[UINT32_C(0x00006127)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006128), "009", 3u); storage[UINT32_C(0x0000612B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000612C), "004", 3u); storage[UINT32_C(0x0000612F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006130), "1_61", 4u); storage[UINT32_C(0x00006134)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006138), "018", 3u); storage[UINT32_C(0x0000613B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000613C), "006", 3u); storage[UINT32_C(0x0000613F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006140), "003", 3u); storage[UINT32_C(0x00006143)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006144), "1_11", 4u); storage[UINT32_C(0x00006148)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000614C), "1_31", 4u); storage[UINT32_C(0x00006150)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006154), "002", 3u); storage[UINT32_C(0x00006157)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006158), "014", 3u); storage[UINT32_C(0x0000615B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000615C), "1_21", 4u); storage[UINT32_C(0x00006160)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006164), "1_41", 4u); storage[UINT32_C(0x00006168)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000616C), "wrong format of planting.txt\n", 29u); storage[UINT32_C(0x00006189)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000618C), "MAX_OBJS_IN_PATTERN exceeded", 28u); storage[UINT32_C(0x000061A8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000061AC), "v\000\000\000n\000\000\000d", 9u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000061B8), "a00_00", 6u); storage[UINT32_C(0x000061BE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000061C0), "landscape\\planting.txt", 22u); storage[UINT32_C(0x000061D6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000061D8), "\n\327#=ff\346>\315\314L?\n\327\243=\037\205k>\303\365\250>\232\231\031?", 28u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000061F4), "CreateTexture for water reflection failed", 41u); storage[UINT32_C(0x0000621D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006220), "trap %d", 7u); storage[UINT32_C(0x00006227)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006228), "trap", 4u); storage[UINT32_C(0x0000622C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006237), "@\n\327\367?\000\000\200>\000\000HB", 13u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006244), "RegisterClassEx() failed! => init_main_window_class()", 53u); storage[UINT32_C(0x00006279)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000627C), "Wrong format of rgbRand in material struct %d", 45u); storage[UINT32_C(0x000062A9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000062AC), "Field name is absent in material %d", 35u); storage[UINT32_C(0x000062CF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000062D0), "Can't go into material struct %d", 32u); storage[UINT32_C(0x000062F0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000062F4), "rgbRand", 7u); storage[UINT32_C(0x000062FB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000062FC), "name", 4u); storage[UINT32_C(0x00006300)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006304), "materials", 9u); storage[UINT32_C(0x0000630D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006310), "Models\\Materials.cfg", 20u); storage[UINT32_C(0x00006324)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006328), "Shaders\\Vertex\\", 15u); storage[UINT32_C(0x00006337)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006338), "Shaders\\Pixel\\", 14u); storage[UINT32_C(0x00006346)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006348), "players\\", 8u); storage[UINT32_C(0x00006350)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006354), "xadd\\", 5u); storage[UINT32_C(0x00006359)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000635C), "textures\\emblems\\", 17u); storage[UINT32_C(0x0000636D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006370), "textures\\fx\\", 12u); storage[UINT32_C(0x0000637C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006380), "textures\\", 9u); storage[UINT32_C(0x00006389)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000638C), "models_rd\\textures\\", 19u); storage[UINT32_C(0x0000639F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000063A0), "models_ph\\textures\\", 19u); storage[UINT32_C(0x000063B3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000063B4), "models_hr\\textures\\", 19u); storage[UINT32_C(0x000063C7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000063C8), "models\\textures\\", 16u); storage[UINT32_C(0x000063D8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000063DC), "debug\\pics\\", 11u); storage[UINT32_C(0x000063E7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000063E8), "Empty text created", 18u); storage[UINT32_C(0x000063FA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000063FC), "create_text: wrong window handle", 32u); storage[UINT32_C(0x0000641C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006420), "rotate_object: wrong handle", 27u); storage[UINT32_C(0x0000643B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000643C), "recalk_orts: wrong handle", 25u); storage[UINT32_C(0x00006455)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000645C), "9\326\305m0_\304@\205\353Q\270\036\205\357?\000\000\000\240\362\327\252>\334\017\311\277\334\017\311?\345\313\226\300", 36u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006480), "CreateTexture for landscape cash failed", 39u); storage[UINT32_C(0x000064A7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000064B1), "\200k@\000\000\000\000\000\000\220?\000\000\000`UU\265?\000\000\000\000\000\000P@", 27u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000064CC), "UUUUUU\245?", 8u); storage[UINT32_C(0x000064D4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000064DA), "(@\000\000@@\000\000 @\232\231\231?", 14u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000064F2), "\030@", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000064F4), "fonts\\font2.pcx", 15u); storage[UINT32_C(0x00006503)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006504), "fonts\\font2%s.pcx", 17u); storage[UINT32_C(0x00006515)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006518), "fonts\\font1.pcx", 15u); storage[UINT32_C(0x00006527)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006528), "fonts\\font1%s.pcx", 17u); storage[UINT32_C(0x00006539)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000653C), "xadd\\snowpath.bin", 17u); storage[UINT32_C(0x0000654D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006550), "landscape", 9u); storage[UINT32_C(0x00006559)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000655C), "VERTSYNC", 8u); storage[UINT32_C(0x00006564)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006568), "landscape_rd", 12u); storage[UINT32_C(0x00006574)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006578), "landscape_ph", 12u); storage[UINT32_C(0x00006584)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006588), "landscape_hr", 12u); storage[UINT32_C(0x00006594)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000659A), "\270A", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000659C), "POSTEFFECTS", 11u); storage[UINT32_C(0x000065A7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000065A8), "MIN_LOD_DIST", 12u); storage[UINT32_C(0x000065B4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000065B8), "LOD_DISTANCE", 12u); storage[UINT32_C(0x000065C4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000065C8), "GRASS", 5u); storage[UINT32_C(0x000065CD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000065D0), "DEPTH", 5u); storage[UINT32_C(0x000065D5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000065D8), "YRES", 4u); storage[UINT32_C(0x000065DC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000065E0), "XRES", 4u); storage[UINT32_C(0x000065E4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000065E8), "WINDOWED", 8u); storage[UINT32_C(0x000065F0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000065F4), "MEMORY_WARNING_AS_ERROR", 23u); storage[UINT32_C(0x0000660B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000660C), "REFRESH", 7u); storage[UINT32_C(0x00006613)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006614), "SHOWVIDEO", 9u); storage[UINT32_C(0x0000661D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006620), "SpiderWclName", 13u); storage[UINT32_C(0x0000662D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006630), "Spider", 6u); storage[UINT32_C(0x00006636)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006638), "MapViewOfFile failed", 20u); storage[UINT32_C(0x0000664C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006650), "SphereDebug", 11u); storage[UINT32_C(0x0000665B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000665C), "_f", 2u); storage[UINT32_C(0x0000665E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006660), "_spa", 4u); storage[UINT32_C(0x00006664)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006668), "_d", 2u); storage[UINT32_C(0x0000666A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000666C), "_i", 2u); storage[UINT32_C(0x0000666E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006670), "_p", 2u); storage[UINT32_C(0x00006672)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006674), "_e", 2u); storage[UINT32_C(0x00006676)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006678), "it", 2u); storage[UINT32_C(0x0000667A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000667C), "fr", 2u); storage[UINT32_C(0x0000667E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006680), "de", 2u); storage[UINT32_C(0x00006682)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006684), "pt", 2u); storage[UINT32_C(0x00006686)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006688), "es", 2u); storage[UINT32_C(0x0000668A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000668C), "en", 2u); storage[UINT32_C(0x0000668E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006690), "INVITE_MESSAGES", 15u); storage[UINT32_C(0x0000669F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000066A0), "DESCR_AUTO_POPUP", 16u); storage[UINT32_C(0x000066B0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000066B4), "HARDWARE_CURSOR", 15u); storage[UINT32_C(0x000066C3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000066C4), "LODS", 4u); storage[UINT32_C(0x000066C8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000066CC), "EFFECTS", 7u); storage[UINT32_C(0x000066D3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000066D4), "REFLQUAL", 8u); storage[UINT32_C(0x000066DC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000066E0), "FOGDIST", 7u); storage[UINT32_C(0x000066E7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000066E8), "AUTOFOG", 7u); storage[UINT32_C(0x000066EF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000066F0), "ru", 2u); storage[UINT32_C(0x000066F2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000066F4), "LANG", 4u); storage[UINT32_C(0x000066F8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000066FC), "config.cfg", 10u); storage[UINT32_C(0x00006706)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006708), "ERROR: init_first2: CoInitialize error code = ", 46u); storage[UINT32_C(0x00006736)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006738), "**** Start: ", 12u); storage[UINT32_C(0x00006744)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006748), "logs\\memory.log", 15u); storage[UINT32_C(0x00006757)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006758), "test.log", 8u); storage[UINT32_C(0x00006760)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006764), "mbc", 3u); storage[UINT32_C(0x00006767)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006768), "params", 6u); storage[UINT32_C(0x0000676E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006770), "dg_type", 7u); storage[UINT32_C(0x00006777)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006778), "Object has size < MIN_OBJECT_SIZE: ", 35u); storage[UINT32_C(0x0000679B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000679C), "head", 4u); storage[UINT32_C(0x000067A0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000067A4), "neck_m1o1", 9u); storage[UINT32_C(0x000067AD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000067B0), "fingr_m1o1", 10u); storage[UINT32_C(0x000067BA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000067BC), "finr_m1o1", 9u); storage[UINT32_C(0x000067C5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000067C8), "fingl_m1o1", 10u); storage[UINT32_C(0x000067D2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000067D4), "finl_m1o1", 9u); storage[UINT32_C(0x000067DD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000067E0), "land_shade_affect_K", 19u); storage[UINT32_C(0x000067F3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000067F4), "trace", 5u); storage[UINT32_C(0x000067F9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000067FC), "shad_s", 6u); storage[UINT32_C(0x00006802)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006804), "\232\231Y?", 4u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006808), "shad_sp", 7u); storage[UINT32_C(0x0000680F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006810), "shad_f", 6u); storage[UINT32_C(0x00006816)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006818), "lod_pow", 7u); storage[UINT32_C(0x0000681F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006822), "zD", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006824), "lod_f", 5u); storage[UINT32_C(0x00006829)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000682C), "Model has material which not exist in library: ", 47u); storage[UINT32_C(0x0000685B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000685C), "load_model: wrong format. File: ", 32u); storage[UINT32_C(0x0000687C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006880), "File not found: %s", 18u); storage[UINT32_C(0x00006892)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006894), ".mdl", 4u); storage[UINT32_C(0x00006898)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000689C), "create_sprite: wrong window handle", 34u); storage[UINT32_C(0x000068BE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000068C7), " \020\020p?", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000068CC), "Smooth error in %s! Look at lndbug.tga", 38u); storage[UINT32_C(0x000068F2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000068F4), "fatal error 58289563485", 23u); storage[UINT32_C(0x0000690B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000690C), "dg_type parameter not filled in mdlprms.txt for model  %s", 57u); storage[UINT32_C(0x00006945)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000694F), "@33\303\277\000\000\000A333\277", 13u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000695C), "_u_grass", 8u); storage[UINT32_C(0x00006964)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000696A), "\240\300\000\000\000\300\026\244a@", 10u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006974), "AutoGrass", 9u); storage[UINT32_C(0x0000697D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006987), "\240\252\252 @\000\000\000`zj\017@\000\000\000\240|\331\002@\000\000\000\300t\223h?\000\000\000\200\373!\311?", 37u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000069AC), "ww1_00", 6u); storage[UINT32_C(0x000069B2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000069B4), "move_object: wrong handle", 25u); storage[UINT32_C(0x000069CD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000069D0), "Activate light error N4", 23u); storage[UINT32_C(0x000069E7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000069E8), "VB_SIZE exceed!", 15u); storage[UINT32_C(0x000069F7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000069F8), "Activate light error N3", 23u); storage[UINT32_C(0x00006A0F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006A10), "Number of layer masks is not the same in lnd and msk", 52u); storage[UINT32_C(0x00006A44)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006A48), "Patch %s has microtexture which not exist: name=%c%c", 52u); storage[UINT32_C(0x00006A7C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006A80), "_00.lnd", 7u); storage[UINT32_C(0x00006A87)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006A91), "\300o@\000\000\000@\252\252 @", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006A9C), ".wtr", 4u); storage[UINT32_C(0x00006AA0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006AA4), "_00", 3u); storage[UINT32_C(0x00006AA7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006AB1), "p\307@\000\000\000\340Q\270\216?\000\240\014\306\000@\034\306\000\000\000\240\231\231\003@", 27u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006ACC), "GreatherNearCldInfo: wrong handle", 33u); storage[UINT32_C(0x00006AED)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006AF0), "===CLD_NUM problem =======\n", 27u); storage[UINT32_C(0x00006B0B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006B0C), "phDMG %5.1f", 11u); storage[UINT32_C(0x00006B17)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006B1F), "\340Q\270\236?\000\000\000\000\000\300W@\000\000 C", 17u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006B39), "@\277@", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006B3C), "phKILL 1", 8u); storage[UINT32_C(0x00006B44)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006B51), "\340\177@\000\000\000\000\000\220\177@\000\000\202C", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006B6A), "n\300\000\000\000\000\000\240n\300\000\000\000\000\000\240~\300\000\000\000\000\000\360~\300\000\0009\304\000@:\304", 34u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006B8C), "\246\233D;", 4u); storage[UINT32_C(0x00006B90)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006B97), "\240\231\231#@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006B9C), "\315\314L=", 4u); storage[UINT32_C(0x00006BA0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006BA7), "\200\302\365\350?\223\030D?", 9u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006BB0), "tree", 4u); storage[UINT32_C(0x00006BB4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006BB8), "\253\252\252;", 4u); storage[UINT32_C(0x00006BBC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006BC2), "h@", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006BC4), "MNO_INDICES_IN_PRIMITIVE exceed", 31u); storage[UINT32_C(0x00006BE3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006BE9), "\300_@\000\000\000\340\216yE>\000\000\000\340\3426J?", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006BFC), "w\314+2", 4u); storage[UINT32_C(0x00006C00)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006C09), "\224\261@\200gX\014\276\265\362?\254\305\2478\027\267Q:", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006C1C), " = %f %f %f = %d = %d = %d\n", 27u); storage[UINT32_C(0x00006C37)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006C38), " = ", 3u); storage[UINT32_C(0x00006C3B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006C3C), "<empty slot>", 12u); storage[UINT32_C(0x00006C48)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006C4C), "crt04", 5u); storage[UINT32_C(0x00006C51)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006C54), "CreateObject: no model with such name: ", 39u); storage[UINT32_C(0x00006C7B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006C7C), "grass1_21", 9u); storage[UINT32_C(0x00006C85)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006C8F), "@\246\252\020@\000\000\000\000\000\000\004@", 13u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006C9C), "Grass pattern not found. Type=%d", 32u); storage[UINT32_C(0x00006CBC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006CC0), "flower", 6u); storage[UINT32_C(0x00006CC6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006CCF), "\300/\033\324?\000\000\000\240\030W\306?", 13u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006CDC), "grass_s00", 9u); storage[UINT32_C(0x00006CE5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006CE8), "grass", 5u); storage[UINT32_C(0x00006CED)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006CF7), "@\246\252 @", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006CFC), "cam_cube", 8u); storage[UINT32_C(0x00006D04)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006D08), "landscape_hr\\weather_hr.txt", 27u); storage[UINT32_C(0x00006D23)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006D24), "landscape\\weather.txt", 21u); storage[UINT32_C(0x00006D39)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006D3C), "models_rd\\", 10u); storage[UINT32_C(0x00006D46)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006D48), "models_ph\\", 10u); storage[UINT32_C(0x00006D52)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006D54), "models_hr\\", 10u); storage[UINT32_C(0x00006D5E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006D60), "models\\", 7u); storage[UINT32_C(0x00006D67)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006D68), "landscape_hr\\sky_hr.txt", 23u); storage[UINT32_C(0x00006D7F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006D80), "sky.txt", 7u); storage[UINT32_C(0x00006D87)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006D88), "models\\materls.mtr", 18u); storage[UINT32_C(0x00006D9A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006D9F), "@\341z\244?", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006DA4), "treeput", 7u); storage[UINT32_C(0x00006DAB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006DAC), "internal error 743827592", 24u); storage[UINT32_C(0x00006DC4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006DC8), "internal error 764554745", 24u); storage[UINT32_C(0x00006DE0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006DE4), "internal error 763927845", 24u); storage[UINT32_C(0x00006DFC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006E00), "DrawObjects: wrong animation. Name=%s\n", 38u); storage[UINT32_C(0x00006E26)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006E2A), "\240B\200O\303G\000P\303G\253\252\252<\000\000\000\000\000\000\000\340Mb@?", 26u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006E44), "\307\340\357\363\361\352 \357\360\356\350\347\342\356\344\350\362\361\377 \357\360\356\343\360\340\354\354\356\351 launchpoint.exe.", 47u); storage[UINT32_C(0x00006E73)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006E74), "\316\370\350\341\352\340 \347\340\357\363\361\352\340", 14u); storage[UINT32_C(0x00006E82)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006E84), "CONNECT_TYPE", 12u); storage[UINT32_C(0x00006E90)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006E94), "connect.cfg", 11u); storage[UINT32_C(0x00006E9F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006EA0), "/gamexp_sid", 11u); storage[UINT32_C(0x00006EAB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006EAC), "/login", 6u); storage[UINT32_C(0x00006EB2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006EB4), "/locale", 7u); storage[UINT32_C(0x00006EBB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006EBC), "\307\340\357\363\361\352 \357\360\356\350\347\342\356\344\350\362\361\377 \357\360\356\343\360\340\354\354\356\351 Sphere.exe.", 42u); storage[UINT32_C(0x00006EE6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006EE8), "\316\370\350\341\352\340 \347\340\357\363\361\352\340.", 15u); storage[UINT32_C(0x00006EF7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006EF8), ".\\logs\000\000.\\players\000\000\000\000\000\376B\000\376\377F\000\000\200D\000\376\377F", 36u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006F1C), "BM", 2u); storage[UINT32_C(0x00006F1E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006F20), "MapGenerator.cpp", 16u); storage[UINT32_C(0x00006F30)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00006F34), "\341b\000\000\362t\000\000\361s\000\000\364f\000\000\342v\000\000\357p\000\000\360r\000\000\356o\000\000\353l\000\000\344d\000\000\365h\000\000\347z\000\000\343g\000\000\355n\000\000\366c\000\000\345e\270\000\363u\000\000\350\351i\000\355h\000\000\354m\000\000\340a\000\000\361c\000\000\360p\000\000\3560o\000\350\351u\000\365x\000\000\3473\000\000\343r\000\000\352k\000\000\363y\000\000\3416b\000\344g\000\000\345\270e", 131u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00006FBC), "CMatFilter::CMatFilter: field 't' absent in one of array's elements", 67u); storage[UINT32_C(0x00006FFF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007000), "..\\ShareClientSeverCode\\matfilter.cpp", 37u); storage[UINT32_C(0x00007025)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007028), "CMatFilter::CMatFilter: error reading exceptions", 48u); storage[UINT32_C(0x00007058)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000705C), "e", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00007064), "CMatFilter::CMatFilter: field 'w' absent in one of array's elements", 67u); storage[UINT32_C(0x000070A7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000070A8), "CMatFilter::CMatFilter: \354\340\361\361\350\342 words \355\345 \355\340\351\344\345\355 \342 matbase.dat", 60u); storage[UINT32_C(0x000070E4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000070E8), "words", 5u); storage[UINT32_C(0x000070ED)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000070F0), ".dat", 4u); storage[UINT32_C(0x000070F4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000070F8), "xadd\\matbase", 12u); storage[UINT32_C(0x00007104)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007108), "SPHR", 4u); storage[UINT32_C(0x0000710C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007112), "\376B\000\376\377F\000\000\200D\000\376\377F", 14u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00007120), "check_index: wrong index %d, File:%s, Line:%d", 45u); storage[UINT32_C(0x0000714D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007150), "check_pointer: wrong pointer or size %d, File:%s, Line:%d", 57u); storage[UINT32_C(0x00007189)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000718C), "memmove_safe: pDest=%x, pSrc=%x, len=%d, pGuard=%x, guardLen=%d; File:%s, Line:%d", 81u); storage[UINT32_C(0x000071DD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000071E4), "memcpy_safe: pDest=%x, pSrc=%x, len=%d, pGuard1=%x, guardLen1=%d, pGuard2=%x, guardLen2=%d; File:%s, Line:%d", 108u); storage[UINT32_C(0x00007250)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007254), "check_error: FALSE, File:%s, Line:%d", 36u); storage[UINT32_C(0x00007278)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000727C), "..\\ShareClientSeverCode\\miscell.cpp", 35u); storage[UINT32_C(0x0000729F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000072A2), "\376B\000\376\377F\000\000\200D\000\376\377F", 14u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000072B0), "models\\mdlparam.txt", 19u); storage[UINT32_C(0x000072C3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000072C4), "..\\ShareClientSeverCode\\ModelsMngr.cpp", 38u); storage[UINT32_C(0x000072EA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000072EC), "Too long mdl name", 17u); storage[UINT32_C(0x000072FD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007300), "*.mdl", 5u); storage[UINT32_C(0x00007305)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007308), "ModelsMngr::register_folder: MAX_MDL_PATH_LEN exceeded", 54u); storage[UINT32_C(0x0000733E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007340), "ModelsMngr::register_folder: MAX_MDL_PATH_NUM exceeded", 54u); storage[UINT32_C(0x00007376)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007378), "get_model_by_id: id == -1", 25u); storage[UINT32_C(0x00007391)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007394), "\310lQ\000P\372G\000\260\367G\000\200\240A\000\024mQ\000 \370G\000\240\365G\000\300\365G\000\000\000\000\000\000\000t@", 40u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000073BC), "Unknown effect classID for lighting.", 36u); storage[UINT32_C(0x000073E0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000073EA), "N@\000\000pB", 6u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000073F0), "Unknown effect manager for 'rain' not found.", 44u); storage[UINT32_C(0x0000741C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007420), "Unknown effect classID for rain.", 32u); storage[UINT32_C(0x00007440)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007444), "..\\ShareClientSeverCode\\NatureManager.cpp", 41u); storage[UINT32_C(0x0000746D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007470), "Net.log", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00007478), "CreateProcess error: %d\n", 24u); storage[UINT32_C(0x00007490)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007494), "\\ping.exe -n 1 ", 15u); storage[UINT32_C(0x000074A3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000074A4), "%d/%m %H:%M:%S ", 15u); storage[UINT32_C(0x000074B3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000074B4), "%d %d %d %d\n", 12u); storage[UINT32_C(0x000074C0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000074C4), "CreateThread error: %d\n", 23u); storage[UINT32_C(0x000074DB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000074DC), "..\\ShareClientSeverCode\\NetworkConnectionChecker.cpp", 52u); storage[UINT32_C(0x00007510)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007514), "CClNetworkConnectionChecker::Start(): CreateThread error: ", 58u); storage[UINT32_C(0x0000754E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007550), "..\\ShareClientSeverCode\\objparam.cpp", 36u); storage[UINT32_C(0x00007574)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007578), "CObjParamManager::Open: object already initialized", 50u); storage[UINT32_C(0x000075AA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000075AC), "CObjParamManager::GetObjParam: wrong file format", 48u); storage[UINT32_C(0x000075DC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000075E0), "parse_error: %d. Line %d", 24u); storage[UINT32_C(0x000075F8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000075FC), "getCfg: get size for non array. Name:", 37u); storage[UINT32_C(0x00007621)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007624), "getCfg: wrong type of parameter. Name:", 38u); storage[UINT32_C(0x0000764A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000764C), "getCfg: wrong address or corrupted data", 39u); storage[UINT32_C(0x00007673)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007674), "getCfgArraySize: internal error", 31u); storage[UINT32_C(0x00007693)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007694), "getCfg: index out of range", 26u); storage[UINT32_C(0x000076AE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000076B0), "openCfg: duplicate name: ", 25u); storage[UINT32_C(0x000076C9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000076CC), "openCfg: internal error", 23u); storage[UINT32_C(0x000076E3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000076E4), "openCfg: wrong fromat of Cfg %s", 31u); storage[UINT32_C(0x00007703)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007704), "openCfg: file %s is not found", 29u); storage[UINT32_C(0x00007721)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007724), "\334\017I@", 4u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00007728), "PS_FOLLOWWITHSPIN", 17u); storage[UINT32_C(0x00007739)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000773C), "PS_DIRECTVELOCITY", 17u); storage[UINT32_C(0x0000774D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007750), "PS_PARENTLIFETIME", 17u); storage[UINT32_C(0x00007761)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007764), "PS_PARENTALPHA", 14u); storage[UINT32_C(0x00007772)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007774), "PS_EMITCTRLRHW", 14u); storage[UINT32_C(0x00007782)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007784), "PS_MAGFACTORGTIME", 17u); storage[UINT32_C(0x00007795)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007798), "PS_MAGISCHILDPS", 15u); storage[UINT32_C(0x000077A7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000077A8), "PS_RANDOMTEXFRAME", 17u); storage[UINT32_C(0x000077B9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000077BC), "PS_EMITONPOSCHANGE", 18u); storage[UINT32_C(0x000077CE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000077D0), "PS_MAGFACTORISLIFE", 18u); storage[UINT32_C(0x000077E2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000077E4), "PS_USEDISTORTION", 16u); storage[UINT32_C(0x000077F4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000077F8), "PS_USECOLOR", 11u); storage[UINT32_C(0x00007803)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007804), "PS_USEUVTRANSLATE", 17u); storage[UINT32_C(0x00007815)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007818), "PS_NOLOCALTIME", 14u); storage[UINT32_C(0x00007826)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007828), "PS_NOLIFETIME", 13u); storage[UINT32_C(0x00007835)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007838), "PS_NOFACECAMERA", 15u); storage[UINT32_C(0x00007847)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007848), "PS_NOHEAVYATTACH", 16u); storage[UINT32_C(0x00007858)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000785C), "PS_USEMAGNITE", 13u); storage[UINT32_C(0x00007869)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000786C), "PS_DYNAMICEMITALL", 17u); storage[UINT32_C(0x0000787D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007880), "PS_STATICEMITALL", 16u); storage[UINT32_C(0x00007890)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007894), "PS_TRANSLATEONLY", 16u); storage[UINT32_C(0x000078A4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000078A8), "PS_USEROTSCALE", 14u); storage[UINT32_C(0x000078B6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000078B8), "PS_ROTATEZ", 10u); storage[UINT32_C(0x000078C2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000078C4), "PS_ROTATEY", 10u); storage[UINT32_C(0x000078CE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000078D0), "PS_ROTATEX", 10u); storage[UINT32_C(0x000078DA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000078DC), "PS_ROTATEXYZ", 12u); storage[UINT32_C(0x000078E8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000078EC), "I_COSINE", 8u); storage[UINT32_C(0x000078F4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000078F8), "EMITSHAPE_DISK2", 15u); storage[UINT32_C(0x00007907)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007908), "EMITSHAPE_SPHERE", 16u); storage[UINT32_C(0x00007918)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000791C), "EMITSHAPE_CYLINDER", 18u); storage[UINT32_C(0x0000792E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007930), "EMITSHAPE_BOX", 13u); storage[UINT32_C(0x0000793D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007940), "EMITSHAPE_RING", 14u); storage[UINT32_C(0x0000794E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007950), "EMITSHAPE_DISK", 14u); storage[UINT32_C(0x0000795E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007960), "EMITSHAPE_LINE", 14u); storage[UINT32_C(0x0000796E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007970), "%d %f %f %f", 11u); storage[UINT32_C(0x0000797B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000797C), "rkey", 4u); storage[UINT32_C(0x00007980)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007984), "%d %f %f", 8u); storage[UINT32_C(0x0000798C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007990), "key", 3u); storage[UINT32_C(0x00007993)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007994), "..\\ShareClientSeverCode\\ParticleSystem.cpp", 42u); storage[UINT32_C(0x000079BE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000079C0), "numkeys", 7u); storage[UINT32_C(0x000079C7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000079C8), "mrkey", 5u); storage[UINT32_C(0x000079CD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000079D0), "%d %f %f %f %f %f %f %f", 23u); storage[UINT32_C(0x000079E7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000079E8), "%d %f %f %f %f", 14u); storage[UINT32_C(0x000079F6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000079F8), "CEffectMesh::Initialize() -> Texture '%s' not found", 51u); storage[UINT32_C(0x00007A2B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007A2C), "CParticleSystem::Initialize() -> Texture '%s' not found", 55u); storage[UINT32_C(0x00007A63)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007A64), "%d %f %d %d %d %d %d %d %d %d", 29u); storage[UINT32_C(0x00007A81)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007A84), "%d %f %d %d %d %d", 17u); storage[UINT32_C(0x00007A95)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007A98), "texture", 7u); storage[UINT32_C(0x00007A9F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007AA0), "PS_BLENDALPHA", 13u); storage[UINT32_C(0x00007AAD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007AB0), "PS_BLENDADD", 11u); storage[UINT32_C(0x00007ABB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007ABC), "blendmode", 9u); storage[UINT32_C(0x00007AC5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007AC8), "texture_def", 11u); storage[UINT32_C(0x00007AD3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007AD4), "effectmesh->vcoord_track", 24u); storage[UINT32_C(0x00007AEC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007AF0), "vcoord_track", 12u); storage[UINT32_C(0x00007AFC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007B00), "effectmesh->ucoord_track", 24u); storage[UINT32_C(0x00007B18)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007B1C), "ucoord_track", 12u); storage[UINT32_C(0x00007B28)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007B2C), "effectmesh->color_track", 23u); storage[UINT32_C(0x00007B43)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007B44), "scale_track", 11u); storage[UINT32_C(0x00007B4F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007B50), "interpolation", 13u); storage[UINT32_C(0x00007B5D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007B67), "\300F\337\221?", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00007B6C), "rotation_track", 14u); storage[UINT32_C(0x00007B7A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007B7C), "%d %d %d %d", 11u); storage[UINT32_C(0x00007B87)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007B88), "color", 5u); storage[UINT32_C(0x00007B8D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007B90), "self_illumination", 17u); storage[UINT32_C(0x00007BA1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007BA4), "effectmesh_flags", 16u); storage[UINT32_C(0x00007BB4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007BBC), "CEffectMesh::LoadScript(%s) -> SSM Mesh not specified in effectMesh '%s'", 72u); storage[UINT32_C(0x00007C04)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007C08), "effectmesh_ssm", 14u); storage[UINT32_C(0x00007C16)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007C18), "effectmesh_name", 15u); storage[UINT32_C(0x00007C27)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007C28), "child_ps", 8u); storage[UINT32_C(0x00007C30)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007C34), "RANDOM", 6u); storage[UINT32_C(0x00007C3A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007C3C), "texture_frame", 13u); storage[UINT32_C(0x00007C49)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007C4C), "magnite_weight", 14u); storage[UINT32_C(0x00007C5A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007C5C), "number", 6u); storage[UINT32_C(0x00007C62)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007C64), "range", 5u); storage[UINT32_C(0x00007C69)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007C6C), "select", 6u); storage[UINT32_C(0x00007C72)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007C74), "particles_def", 13u); storage[UINT32_C(0x00007C81)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007C84), "%d %f %f %f %f %f %f %f %f", 26u); storage[UINT32_C(0x00007C9E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007CA0), "frame", 5u); storage[UINT32_C(0x00007CA5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007CA8), "animspeed", 9u); storage[UINT32_C(0x00007CB1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007CB4), "PS_TANIMCOORD", 13u); storage[UINT32_C(0x00007CC1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007CC4), "type", 4u); storage[UINT32_C(0x00007CC8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007CCC), "numframes", 9u); storage[UINT32_C(0x00007CD5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007CD8), "psystem->gravitation_track", 26u); storage[UINT32_C(0x00007CF2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007CF4), "gravitation_track", 17u); storage[UINT32_C(0x00007D05)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007D08), "psystem->velocity_track", 23u); storage[UINT32_C(0x00007D1F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007D20), "velocity_track", 14u); storage[UINT32_C(0x00007D2E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007D30), "psystem->color_track", 20u); storage[UINT32_C(0x00007D44)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007D48), "psystem->size_track", 19u); storage[UINT32_C(0x00007D5B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007D5C), "track_num", 9u); storage[UINT32_C(0x00007D65)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007D68), "size_track", 10u); storage[UINT32_C(0x00007D72)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007D74), "ngravitation_tracks", 19u); storage[UINT32_C(0x00007D87)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007D88), "nvelocity_tracks", 16u); storage[UINT32_C(0x00007D98)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007D9C), "ncolor_tracks", 13u); storage[UINT32_C(0x00007DA9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007DAC), "nsize_tracks", 12u); storage[UINT32_C(0x00007DB8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007DBC), "particletracks_def", 18u); storage[UINT32_C(0x00007DCE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007DD0), "psystem->lifetime_track", 23u); storage[UINT32_C(0x00007DE7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007DE8), "lifetime_track", 14u); storage[UINT32_C(0x00007DF6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007DF8), "lifetime_rf", 11u); storage[UINT32_C(0x00007E03)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007E04), "lifetime", 8u); storage[UINT32_C(0x00007E0C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007E10), "particleborn_def", 16u); storage[UINT32_C(0x00007E20)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007E24), "psystem->emissionpos_track", 26u); storage[UINT32_C(0x00007E3E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007E40), "emissionpos_track", 17u); storage[UINT32_C(0x00007E51)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007E54), "psystem->emission_track", 23u); storage[UINT32_C(0x00007E6B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007E6C), "emission_track", 14u); storage[UINT32_C(0x00007E7A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007E7C), "point", 5u); storage[UINT32_C(0x00007E81)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007E84), "shape_points", 12u); storage[UINT32_C(0x00007E90)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007E94), "shape_numpoints", 15u); storage[UINT32_C(0x00007EA3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007EA4), "emitter_pos", 11u); storage[UINT32_C(0x00007EAF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007EB0), "direction", 9u); storage[UINT32_C(0x00007EB9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007EBC), "emit_num", 8u); storage[UINT32_C(0x00007EC4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007EC8), "radius", 6u); storage[UINT32_C(0x00007ECE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007ED0), "width", 5u); storage[UINT32_C(0x00007ED5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007ED8), "height", 6u); storage[UINT32_C(0x00007EDE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007EE0), "randfactor", 10u); storage[UINT32_C(0x00007EEA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007EEC), "randseed", 8u); storage[UINT32_C(0x00007EF4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007EF8), "shape", 5u); storage[UINT32_C(0x00007EFD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007F00), "emission_def", 12u); storage[UINT32_C(0x00007F0C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007F10), "magpos", 6u); storage[UINT32_C(0x00007F16)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007F18), "magfactor", 9u); storage[UINT32_C(0x00007F21)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007F24), "CParticleSystem::LoadSc(%s) -> Invalid index in 'magchildps'", 60u); storage[UINT32_C(0x00007F60)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007F64), "magchildps", 10u); storage[UINT32_C(0x00007F6E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007F70), "psystem->magfactor_track", 24u); storage[UINT32_C(0x00007F88)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007F8C), "magfactor_track", 15u); storage[UINT32_C(0x00007F9B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007F9C), "psystem->magposition_track", 26u); storage[UINT32_C(0x00007FB6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007FB8), "magposition_track", 17u); storage[UINT32_C(0x00007FC9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007FCC), "magnite_def", 11u); storage[UINT32_C(0x00007FD7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007FD8), "child", 5u); storage[UINT32_C(0x00007FDD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007FE0), "childs_num", 10u); storage[UINT32_C(0x00007FEA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007FEC), "childs_def", 10u); storage[UINT32_C(0x00007FF6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00007FF8), "psystem->scale_track", 20u); storage[UINT32_C(0x0000800C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008010), "psystem->position_track", 23u); storage[UINT32_C(0x00008027)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008028), "psystem->power_trac", 19u); storage[UINT32_C(0x0000803B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000803C), "power_track", 11u); storage[UINT32_C(0x00008047)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008048), "power", 5u); storage[UINT32_C(0x0000804D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008050), "distortion_vec", 14u); storage[UINT32_C(0x0000805E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008060), "transform_vec3", 14u); storage[UINT32_C(0x0000806E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008070), "transform_vec2", 14u); storage[UINT32_C(0x0000807E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008080), "transform_vec1", 14u); storage[UINT32_C(0x0000808E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008090), "transform_vec0", 14u); storage[UINT32_C(0x0000809E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000080A0), "psystem_flags", 13u); storage[UINT32_C(0x000080AD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000080B0), "particles_num", 13u); storage[UINT32_C(0x000080BD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000080C0), "psystem_name", 12u); storage[UINT32_C(0x000080CC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000080D2), "\376B\000\376\377F\000\000\200D\000\376\377F", 14u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000080E0), "..\\ShareClientSeverCode\\pathzones.cpp", 37u); storage[UINT32_C(0x00008105)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000810A), "\376B\000\376\377F\000\000\200D\000\376\377F", 14u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00008118), "----ERROR_Quadtree, xi=%d, yi=%d, xc=%d, yc=%d, xa=%d, ya=%d\n", 61u); storage[UINT32_C(0x00008155)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008158), "..\\ShareClientSeverCode\\quadtree.cpp", 36u); storage[UINT32_C(0x0000817C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008180), "internal error 075982391", 24u); storage[UINT32_C(0x00008198)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000819C), "internal error 849385252", 24u); storage[UINT32_C(0x000081B4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000081B8), "internal error 639206792", 24u); storage[UINT32_C(0x000081D0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000081D4), "..\\ShareClientSeverCode\\QuickFile.cpp", 37u); storage[UINT32_C(0x000081F9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000081FC), "Too many files in quickfile\n", 28u); storage[UINT32_C(0x00008218)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000821C), "Too many files in quickfile", 27u); storage[UINT32_C(0x00008237)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008238), "rb", 2u); storage[UINT32_C(0x0000823A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000823C), "*.mbc", 5u); storage[UINT32_C(0x00008241)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008244), "\\", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00008248), "CReadPathManager::~CReadPathManager: object not deinitialized", 61u); storage[UINT32_C(0x00008285)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008288), "\334\017I@\000\000\376B\000\376\377F\000\000\200D\000\376\377F\000\000\200\200", 24u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000082A0), "..\\ShareClientSeverCode\\ServerWall.cpp", 38u); storage[UINT32_C(0x000082C6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000082CA), " B", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000082CC), "fx_swall", 8u); storage[UINT32_C(0x000082D4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000082D8), "\334\017I@\000\000\000?\000\000\000\005\000\000\000\000\000\000\2408", 20u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000082EC), "..\\ShareClientSeverCode\\shadow.cpp", 34u); storage[UINT32_C(0x0000830E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008310), "shadspot", 8u); storage[UINT32_C(0x00008318)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000831C), "\334\017I\277\000\000\000\000\000\000\000\200\373!\351\277\315\314\314\275\000\000\000\000\000\000\000\240\231\231\271\277", 32u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000833C), "SHAD", 4u); storage[UINT32_C(0x00008340)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008344), "invalid deque<T> subscript", 26u); storage[UINT32_C(0x0000835E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008360), "deque<T> too long", 17u); storage[UINT32_C(0x00008371)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008374), "..\\ShareClientSeverCode\\simpleHTMLParser.cpp", 44u); storage[UINT32_C(0x000083A0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083A4), "player", 6u); storage[UINT32_C(0x000083AA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083AC), "item", 4u); storage[UINT32_C(0x000083B0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083B4), "mailto", 6u); storage[UINT32_C(0x000083BA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083BC), "hts", 3u); storage[UINT32_C(0x000083BF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083C0), "/l", 2u); storage[UINT32_C(0x000083C2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083C4), "\\l", 2u); storage[UINT32_C(0x000083C6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083C8), "\\\\", 2u); storage[UINT32_C(0x000083CA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083CC), "\\\"", 2u); storage[UINT32_C(0x000083CE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083D0), "\\]", 2u); storage[UINT32_C(0x000083D2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083D4), "\\[", 2u); storage[UINT32_C(0x000083D6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083D8), "l", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000083DC), "l ", 2u); storage[UINT32_C(0x000083DE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083E0), "l=\"", 3u); storage[UINT32_C(0x000083E3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083E4), ": ", 2u); storage[UINT32_C(0x000083E6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000083E8), "..\\ShareClientSeverCode\\SimpleParser.cpp", 40u); storage[UINT32_C(0x00008410)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008414), "%s", 2u); storage[UINT32_C(0x00008416)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008418), "true", 4u); storage[UINT32_C(0x0000841C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008420), "\334\017I@", 4u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00008424), "e0", 2u); storage[UINT32_C(0x00008426)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008428), "ab", 2u); storage[UINT32_C(0x0000842A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000842C), "ag", 2u); storage[UINT32_C(0x0000842E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008430), "ar", 2u); storage[UINT32_C(0x00008432)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008434), "sb", 2u); storage[UINT32_C(0x00008436)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008438), "sg", 2u); storage[UINT32_C(0x0000843A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000843C), "sr", 2u); storage[UINT32_C(0x0000843E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008440), "time", 4u); storage[UINT32_C(0x00008444)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008448), "d0", 2u); storage[UINT32_C(0x0000844A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000844C), "p\000\000\000a\000\000\000b\000\000\000g", 13u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000845C), "Illegal format of Sky.txt, line: ", 33u); storage[UINT32_C(0x0000847D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008480), "SunriseStateN", 13u); storage[UINT32_C(0x0000848D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008490), "SunsetStateN", 12u); storage[UINT32_C(0x0000849C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000084A0), "c0", 2u); storage[UINT32_C(0x000084A2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000084A4), "n2 >= SKY_STATES_NUM", 20u); storage[UINT32_C(0x000084B8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000084BE), "\376B\000\376\377F\000\000\200D\000\376\377F\n\327\243<\000\000 A", 22u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000084D4), "..\\ShareClientSeverCode\\snow.cpp", 32u); storage[UINT32_C(0x000084F4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000084F8), "SF_PLAY_TIMEGROUPS", 18u); storage[UINT32_C(0x0000850A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000850C), "SF_PLAY_USEREGION", 17u); storage[UINT32_C(0x0000851D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008520), "SF_TYPE_ENVIRONMENT", 19u); storage[UINT32_C(0x00008533)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008534), "SF_PLAY_LOOPED", 14u); storage[UINT32_C(0x00008542)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008544), "SF_PLAY_RANDOMMIX", 17u); storage[UINT32_C(0x00008555)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008558), "SF_PLAY_RANDOM", 14u); storage[UINT32_C(0x00008566)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008568), "..\\ShareClientSeverCode\\SoundEffect.cpp", 39u); storage[UINT32_C(0x0000858F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008590), "none", 4u); storage[UINT32_C(0x00008594)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008598), "(knNcache_lifetime", 18u); storage[UINT32_C(0x000085AA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000085AC), "offset_vec", 10u); storage[UINT32_C(0x000085B6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000085B8), "vol_barier", 10u); storage[UINT32_C(0x000085C2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000085C4), "mix_duration", 12u); storage[UINT32_C(0x000085D0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000085D4), "max_distance", 12u); storage[UINT32_C(0x000085E0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000085E4), "min_distance", 12u); storage[UINT32_C(0x000085F0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000085F4), "\217\302\365<", 4u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000085F8), "region_radius", 13u); storage[UINT32_C(0x00008605)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008608), "flags", 5u); storage[UINT32_C(0x0000860D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008614), "CSoundEffect::LoadScript() -> Invalid audio index in block 'time_groups' line %d", 80u); storage[UINT32_C(0x00008664)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008668), "%f %f %d %d", 11u); storage[UINT32_C(0x00008673)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008674), "time_groups", 11u); storage[UINT32_C(0x0000867F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008680), "audio_file", 10u); storage[UINT32_C(0x0000868A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000868C), "silence", 7u); storage[UINT32_C(0x00008693)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008694), "source", 6u); storage[UINT32_C(0x0000869A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000869C), "audio_files", 11u); storage[UINT32_C(0x000086A7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000086A8), "eff_number", 10u); storage[UINT32_C(0x000086B2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000086B4), "soundeffect", 11u); storage[UINT32_C(0x000086BF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000086C0), "Sounds\\", 7u); storage[UINT32_C(0x000086C7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000086C8), "Sounds\\*.def", 12u); storage[UINT32_C(0x000086D4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000086D8), "`mQ\000\362\347N\000\370\347N\000\376\347N", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000086E8), "..\\ShareClientSeverCode\\SoundManager.cpp", 40u); storage[UINT32_C(0x00008710)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008714), "HWMIX", 5u); storage[UINT32_C(0x00008719)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000871C), "MUSVOL", 6u); storage[UINT32_C(0x00008722)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008724), "SNDVOL", 6u); storage[UINT32_C(0x0000872A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000872C), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ListStack.h", 86u); storage[UINT32_C(0x00008782)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008784), "..\\ShareClientSeverCode\\SoundTrack.cpp", 38u); storage[UINT32_C(0x000087AA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000087AC), "STP", 3u); storage[UINT32_C(0x000087AF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000087B0), "start_pattern", 13u); storage[UINT32_C(0x000087BD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000087C0), "pattern", 7u); storage[UINT32_C(0x000087C7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000087C8), "patterns", 8u); storage[UINT32_C(0x000087D0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000087D4), "%d %s %s", 8u); storage[UINT32_C(0x000087DC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000087E0), "sample", 6u); storage[UINT32_C(0x000087E6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000087E8), "samples", 7u); storage[UINT32_C(0x000087EF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000087F0), "ST_AUTOFREE", 11u); storage[UINT32_C(0x000087FB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000087FC), "volume", 6u); storage[UINT32_C(0x00008802)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008804), "soundtrack", 10u); storage[UINT32_C(0x0000880E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008810), ".sst", 4u); storage[UINT32_C(0x00008814)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008818), "Sounds\\Music\\", 13u); storage[UINT32_C(0x00008825)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000882A), "\376B\000\376\377F\000\000\200D\000\376\377F.dds", 18u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00008840), "..\\ShareClientSeverCode\\texturesset.cpp", 39u); storage[UINT32_C(0x00008867)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008868), "too long texture name", 21u); storage[UINT32_C(0x0000887D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008880), ".", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00008884), "scan_paths_recursive: MAX_PATH_NUM exceeded", 43u); storage[UINT32_C(0x000088AF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000088B0), "*.dds", 5u); storage[UINT32_C(0x000088B5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000088B8), "add_texture_folder: MAX_TEX_PATH_LEN exceeded", 45u); storage[UINT32_C(0x000088E5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000088E8), "preload_texture_from_memory: wrong textureID = %d", 49u); storage[UINT32_C(0x00008919)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000891C), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\sstr.h", 79u); storage[UINT32_C(0x0000896B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000896C), "SSTR::operator=: buffer overflow! - %s", 38u); storage[UINT32_C(0x00008992)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008994), "SSTR::append: buffer overflow!", 30u); storage[UINT32_C(0x000089B2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000089B4), "SSTR::append: wrong count=%d", 28u); storage[UINT32_C(0x000089D0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000089D4), "Texture 'default' not found", 27u); storage[UINT32_C(0x000089EF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000089F0), ".dds", 4u); storage[UINT32_C(0x000089F4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000089F8), "File not found %s", 17u); storage[UINT32_C(0x00008A09)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008A0C), "preload_texture: wrong textureID = %d, texsNum = %d", 51u); storage[UINT32_C(0x00008A3F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008A40), "33\363?\315\314\214?\334\017I@", 12u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00008A4C), "bufSize=%d, elemsNum=%d", 23u); storage[UINT32_C(0x00008A63)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008A64), "INMS", 4u); storage[UINT32_C(0x00008A68)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008A6C), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\BaseVect.h", 83u); storage[UINT32_C(0x00008ABF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008AC0), "BaseVect::erase: out of range. index=%d, num=%d. %s", 51u); storage[UINT32_C(0x00008AF3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008AF4), "N=%d,  ANoC = %5.2f,  AT = %7.1f,  AP = %5.2f\n", 46u); storage[UINT32_C(0x00008B22)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008B24), "N=%d,  ERROR\n", 13u); storage[UINT32_C(0x00008B31)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008B34), "Average frame time = %d  (fps = %d)\n\n", 37u); storage[UINT32_C(0x00008B59)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008B5C), "\n\nProfile results:\n", 19u); storage[UINT32_C(0x00008B6F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008B70), "logs\\profile.txt", 16u); storage[UINT32_C(0x00008B80)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008B84), "DA", 2u); storage[UINT32_C(0x00008B86)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008B88), "..\\ShareClientSeverCode\\UpdateClnt.cpp", 38u); storage[UINT32_C(0x00008BAE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008BB0), "a+b", 3u); storage[UINT32_C(0x00008BB3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008BB4), "w+b", 3u); storage[UINT32_C(0x00008BB7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008BB8), ".crc", 4u); storage[UINT32_C(0x00008BBC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008BC0), "inbox\\", 6u); storage[UINT32_C(0x00008BC6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008BC8), "%s %s\n(%d) %s\n%s\n\n", 18u); storage[UINT32_C(0x00008BDA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008BDC), "%s %s\n%s\n%s\n\n", 13u); storage[UINT32_C(0x00008BE9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008BEC), "\334\017I@\027\267Q9", 8u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00008BF4), "wrong format of weather.txt\n", 28u); storage[UINT32_C(0x00008C10)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C14), "time2", 5u); storage[UINT32_C(0x00008C19)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C1C), "time1", 5u); storage[UINT32_C(0x00008C21)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C24), "scrll", 5u); storage[UINT32_C(0x00008C29)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C2C), "sc2", 3u); storage[UINT32_C(0x00008C2F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C30), "sc1", 3u); storage[UINT32_C(0x00008C33)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C34), "ntex", 4u); storage[UINT32_C(0x00008C38)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C3C), "cs", 2u); storage[UINT32_C(0x00008C3E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C40), "fl2", 3u); storage[UINT32_C(0x00008C43)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C44), "fl1", 3u); storage[UINT32_C(0x00008C47)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C48), "tsky2", 5u); storage[UINT32_C(0x00008C4D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C50), "tsky1", 5u); storage[UINT32_C(0x00008C55)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C58), "nsky2", 5u); storage[UINT32_C(0x00008C5D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C60), "nsky1", 5u); storage[UINT32_C(0x00008C65)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C68), "stime", 5u); storage[UINT32_C(0x00008C6D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C70), "q000", 4u); storage[UINT32_C(0x00008C74)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C78), "t00c", 4u); storage[UINT32_C(0x00008C7C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C80), "s00_0", 5u); storage[UINT32_C(0x00008C85)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008C88), "wScenarioArr[curSN] >= wScenariosNum", 36u); storage[UINT32_C(0x00008CAC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008CB7), "\200\373!\351?", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00008CBC), "Sky texture name absent in params. ", 35u); storage[UINT32_C(0x00008CDF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008CE0), "Sky texture name present in para, but absent in params. ", 56u); storage[UINT32_C(0x00008D18)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008D1C), "internal error 98742756", 23u); storage[UINT32_C(0x00008D33)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008D34), "clouds8a", 8u); storage[UINT32_C(0x00008D3C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008D40), "clouds8", 7u); storage[UINT32_C(0x00008D47)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008D51), "@T@\000\000\000 l\301&?", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00008D5C), "..\\ShareClientSeverCode\\WeatherManager.cpp", 42u); storage[UINT32_C(0x00008D86)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008D8A), "\376B\000\376\377F\000\000\200D\000\376\377F", 14u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00008D98), "%s : zonesParams[%d] : param \"sunColor[%d].b\"", 45u); storage[UINT32_C(0x00008DC5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008DC8), "%s : zonesParams[%d] : param \"sunColor[%d].g\"", 45u); storage[UINT32_C(0x00008DF5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008DF8), "%s : zonesParams[%d] : param \"sunColor[%d].r\"", 45u); storage[UINT32_C(0x00008E25)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008E28), "sunColor", 8u); storage[UINT32_C(0x00008E30)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008E34), "%s : zonesParams[%d] : param \"ambientColor[%d].b\"", 49u); storage[UINT32_C(0x00008E65)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008E68), "%s : zonesParams[%d] : param \"ambientColor[%d].g\"", 49u); storage[UINT32_C(0x00008E99)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008E9C), "%s : zonesParams[%d] : param \"ambientColor[%d].r\"", 49u); storage[UINT32_C(0x00008ECD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008ED0), "ambientColor", 12u); storage[UINT32_C(0x00008EDC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008EE0), "%s : zonesParams[%d] : param \"fogColor[%d].b\"", 45u); storage[UINT32_C(0x00008F0D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008F10), "%s : zonesParams[%d] : param \"fogColor[%d].g\"", 45u); storage[UINT32_C(0x00008F3D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008F40), "%s : zonesParams[%d] : param \"fogColor[%d].r\"", 45u); storage[UINT32_C(0x00008F6D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008F70), "fogColor", 8u); storage[UINT32_C(0x00008F78)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008F7C), "%s : zonesParams[%d] : dayColorCfg is NULL", 42u); storage[UINT32_C(0x00008FA6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008FA8), "%s : zonesParams[%d] : wrong size of \"dayColors\"", 48u); storage[UINT32_C(0x00008FD8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008FDC), "dayColors", 9u); storage[UINT32_C(0x00008FE5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00008FE8), "%s : zonesParams[%d] : param \"fogFar\"", 37u); storage[UINT32_C(0x0000900D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009010), "fogFar", 6u); storage[UINT32_C(0x00009016)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009018), "%s : zonesParams[%d] : param \"fogNear\"", 38u); storage[UINT32_C(0x0000903E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009040), "fogNear", 7u); storage[UINT32_C(0x00009047)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009048), "%s : zonesParams[%d] : param \"skyFogAlpha\"", 42u); storage[UINT32_C(0x00009072)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009074), "skyFogAlpha", 11u); storage[UINT32_C(0x0000907F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009080), "%s : zonesParams[%d] : param \"borderFadeDist\"", 45u); storage[UINT32_C(0x000090AD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000090B0), "borderFadeDist", 14u); storage[UINT32_C(0x000090BE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000090C0), "%s : zonesParams[%d] : param \"zMax\"", 35u); storage[UINT32_C(0x000090E3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000090E4), "zMax", 4u); storage[UINT32_C(0x000090E8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000090EC), "%s : zonesParams[%d] : param \"zMin\"", 35u); storage[UINT32_C(0x0000910F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009110), "zMin", 4u); storage[UINT32_C(0x00009114)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009118), "%s : zonesParams[%d] : param \"xMax\"", 35u); storage[UINT32_C(0x0000913B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000913C), "xMax", 4u); storage[UINT32_C(0x00009140)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009144), "%s : zonesParams[%d] : param \"xMin\"", 35u); storage[UINT32_C(0x00009167)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009168), "xMin", 4u); storage[UINT32_C(0x0000916C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009170), "%s : zonesParams[%d] : param \"zPatchMin\"", 40u); storage[UINT32_C(0x00009198)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000919C), "zPatchMin", 9u); storage[UINT32_C(0x000091A5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000091A8), "%s : zonesParams[%d] : param \"xPatchMin\"", 40u); storage[UINT32_C(0x000091D0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000091D4), "xPatchMin", 9u); storage[UINT32_C(0x000091DD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000091E0), "%s : zonesParams[%d] : zoneParamsCfg is NULL", 44u); storage[UINT32_C(0x0000920C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009210), "zonesParams", 11u); storage[UINT32_C(0x0000921B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000921C), "Error in ZoningMgr::calc_params() : zonesParams is Empty", 56u); storage[UINT32_C(0x00009254)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009258), "SEND_HELP", 9u); storage[UINT32_C(0x00009261)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009264), "CENTER_TEXT", 11u); storage[UINT32_C(0x0000926F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009270), "SEND_QUIT", 9u); storage[UINT32_C(0x00009279)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000927C), "NOTIFY_LB", 9u); storage[UINT32_C(0x00009285)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009288), "LOSTCHECK", 9u); storage[UINT32_C(0x00009291)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009294), "\340mQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009298), "\340\355I", 3u); storage[UINT32_C(0x0000929B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000929C), "\260\rJ\000\240\365I\000\340\031M\0000\362I\000\240\367I\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\240\361I", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000092C8), "Button::LoadUI(%s,%d,%d) -> Not enough args in 'focuscolor'", 59u); storage[UINT32_C(0x00009303)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009304), "%d %d %d", 8u); storage[UINT32_C(0x0000930C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009310), "focuscolor", 10u); storage[UINT32_C(0x0000931A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000931C), "%s %d %d %d", 11u); storage[UINT32_C(0x00009327)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009328), "hotKey", 6u); storage[UINT32_C(0x0000932E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009330), "NONE", 4u); storage[UINT32_C(0x00009334)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009338), "SPRITE", 6u); storage[UINT32_C(0x0000933E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009340), "drawMethod", 10u); storage[UINT32_C(0x0000934A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000934C), "buttonStyle", 11u); storage[UINT32_C(0x00009357)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009358), "uncheckedImage", 14u); storage[UINT32_C(0x00009366)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009368), "disabledImage", 13u); storage[UINT32_C(0x00009375)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009378), "focusedImage", 12u); storage[UINT32_C(0x00009384)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009388), "ButtonCtrl::LoadUI(%s) -> Can't find sprite '%s'", 48u); storage[UINT32_C(0x000093B8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000093BC), "checkedImage", 12u); storage[UINT32_C(0x000093C8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000093CC), "..\\ShareClientSeverCode\\Interface\\Button.cpp", 44u); storage[UINT32_C(0x000093F8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000093FC), "Sounds\\in_click.wav", 19u); storage[UINT32_C(0x0000940F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009410), "`nQ\000\320\016J\000@\027J\000\300\022J\000\340\031M\000\340\023J\000\000\022J\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\300\023J\000P\023J", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009448), "CheckBox::LoadUI(%s,%d,%d) -> Not enough args in 'focuscolor'", 61u); storage[UINT32_C(0x00009485)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009488), "CheckBox::LoadUI(%s) -> Invalid params in 'textOffset'", 54u); storage[UINT32_C(0x000094BE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000094C0), "textOffset", 10u); storage[UINT32_C(0x000094CA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000094CC), "CheckBox::LoadUI(%s) -> Invalid params in 'imageOffset'", 55u); storage[UINT32_C(0x00009503)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009504), "%d %d", 5u); storage[UINT32_C(0x00009509)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000950C), "imageOffset", 11u); storage[UINT32_C(0x00009517)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009518), "checkfocusImage", 15u); storage[UINT32_C(0x00009527)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009528), "CheckBox::LoadUI(%s) -> Can't find sprite '%s'", 46u); storage[UINT32_C(0x00009556)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009558), "..\\ShareClientSeverCode\\Interface\\CheckBox.cpp", 46u); storage[UINT32_C(0x00009586)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009588), "cursor2\000_cursor2\000\000\000\000_cursor1", 28u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000095A8), "..\\ShareClientSeverCode\\Interface\\Cursor.cpp", 44u); storage[UINT32_C(0x000095D4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000095D8), "Cursor texture '%s' not found", 29u); storage[UINT32_C(0x000095F5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009602), "0@", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009604), "SphereUI::FindTemplateWindowGuaranteed(): failed to find window \"%s\"", 68u); storage[UINT32_C(0x00009648)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000964C), "\254nQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009650), "\260GM", 3u); storage[UINT32_C(0x00009653)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009654), "\020UM\000\320-M\000\340\031M\000\200\"J\000\260(M\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\360\035J", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009684), "SphereUI::CDescriptionWindow::FindSpriteGuaranteed(): failed to find sprite \"%s\"", 80u); storage[UINT32_C(0x000096D4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000096D8), "..\\ShareClientSeverCode\\Interface\\DescriptionWindow.cpp", 55u); storage[UINT32_C(0x0000970F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009714), "SphereUI::CDescriptionWindow::CDescriptionWindow(): failed to find control #%u", 78u); storage[UINT32_C(0x00009762)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009764), "window_right", 12u); storage[UINT32_C(0x00009770)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009774), "window_left", 11u); storage[UINT32_C(0x0000977F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009780), "window_bottom", 13u); storage[UINT32_C(0x0000978D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009790), "window_caption", 14u); storage[UINT32_C(0x0000979E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000097A0), "objdesc2", 8u); storage[UINT32_C(0x000097A8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000097AC), "SphereUI::CDescriptionWindow::ShowDescription(): failed to find control #%u", 75u); storage[UINT32_C(0x000097F7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000097F8), "_\000\000\000LoQ\000\0000J\000P<J\000\2209J\000\340\031M\000\020(J\000\0004J\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\340/J", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009830), ".txt", 4u); storage[UINT32_C(0x00009834)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009838), "testui", 6u); storage[UINT32_C(0x0000983E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009840), "EditCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'cursorOffset'", 60u); storage[UINT32_C(0x0000987C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009880), "cursoroffset", 12u); storage[UINT32_C(0x0000988C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009890), "EditCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'cursorcolor'", 59u); storage[UINT32_C(0x000098CB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000098CC), "cursorcolor", 11u); storage[UINT32_C(0x000098D7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000098D8), "enteredOnFocus", 14u); storage[UINT32_C(0x000098E6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000098E8), "password", 8u); storage[UINT32_C(0x000098F0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000098F4), "numeric", 7u); storage[UINT32_C(0x000098FB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000098FC), "maxsymbols", 10u); storage[UINT32_C(0x00009906)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009908), "..\\ShareClientSeverCode\\Interface\\EditCtrl.cpp", 46u); storage[UINT32_C(0x00009936)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009938), "\230oQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000993C), "\200\rL", 3u); storage[UINT32_C(0x0000993F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009940), "\340IJ\000\240HJ\000\340\031M\000\020\362K\000\360\356K\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\320DJ", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000996C), "..\\ShareClientSeverCode\\Interface\\FilterListCtrl.cpp", 52u); storage[UINT32_C(0x000099A0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000099A4), "..\\ShareClientSeverCode\\Interface\\Font.cpp", 42u); storage[UINT32_C(0x000099CE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000099D0), "Can't initialize vertex buffer for font factory.", 48u); storage[UINT32_C(0x00009A00)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009A04), "Can't load texture '%s' for font '%s'", 37u); storage[UINT32_C(0x00009A29)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009A2C), "Can't open font '%s'", 20u); storage[UINT32_C(0x00009A40)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009A44), "invalid vector<T> subscript", 27u); storage[UINT32_C(0x00009A5F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009A60), " pQ\000\000XJ\000p[J\000\240WJ\000\340\031M\000\340VJ\000\000VJ\000@*M\000\200+M\000\340*M\000\220YJ\000\360YJ\000PZJ", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009A94), "spinButton", 10u); storage[UINT32_C(0x00009A9E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009AA0), "text", 4u); storage[UINT32_C(0x00009AA4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009AA8), "..\\ShareClientSeverCode\\Interface\\FontPicker.cpp", 48u); storage[UINT32_C(0x00009AD8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009ADC), "%s():%d font = %d", 17u); storage[UINT32_C(0x00009AED)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009AF0), "SphereUI::FontPicker::setFont", 29u); storage[UINT32_C(0x00009B0D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009B10), "SphereUI::FontPicker::getFont", 29u); storage[UINT32_C(0x00009B2D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009B30), "MID", 3u); storage[UINT32_C(0x00009B33)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009B34), "BOT", 3u); storage[UINT32_C(0x00009B37)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009B38), "..\\ShareClientSeverCode\\Interface\\HyperText.cpp", 47u); storage[UINT32_C(0x00009B67)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009B68), ",", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009B6C), "/t", 2u); storage[UINT32_C(0x00009B6E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009B70), "\\t", 2u); storage[UINT32_C(0x00009B72)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009B74), "img", 3u); storage[UINT32_C(0x00009B77)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009B78), "tab", 3u); storage[UINT32_C(0x00009B7B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009B7C), "sp", 2u); storage[UINT32_C(0x00009B7E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009B80), "cl", 2u); storage[UINT32_C(0x00009B82)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009B84), "br", 2u); storage[UINT32_C(0x00009B86)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009B88), "Invalid hypertext command: %s", 29u); storage[UINT32_C(0x00009BA5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009BA8), "hypertext", 9u); storage[UINT32_C(0x00009BB1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009BB4), "%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]", 59u); storage[UINT32_C(0x00009BEF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009BF4), "%s(): HyperTextChatList control must have '%s' parameter in file '%s', lines: [%d, %d]", 86u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009C4C), "rowHeight", 9u); storage[UINT32_C(0x00009C55)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009C58), "maxItems", 8u); storage[UINT32_C(0x00009C60)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009C64), "itemLinkColor", 13u); storage[UINT32_C(0x00009C71)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009C74), "playerLinkColor", 15u); storage[UINT32_C(0x00009C83)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009C84), "SphereUI::HyperTextChatListControl::LoadUI", 42u); storage[UINT32_C(0x00009CAE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009CB0), "linkColor", 9u); storage[UINT32_C(0x00009CB9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009CBC), "scrollbar", 9u); storage[UINT32_C(0x00009CC5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009CC8), "..\\ShareClientSeverCode\\Interface\\HyperTextChatListControl.cpp", 62u); storage[UINT32_C(0x00009D06)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009D08), "lpQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009D0C), "\300\234J", 3u); storage[UINT32_C(0x00009D0F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009D10), "\220\325J\000\020\316J\000\340\031M\0000\264J\000\300\267J\000@*M\000\200+M\000\340*M\000\320\240J\000\000\033M\0000\253J", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009D3C), "..\\ShareClientSeverCode\\Interface\\HyperTextChatListItem.cpp", 59u); storage[UINT32_C(0x00009D77)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009D78), "PARAGRAPH", 9u); storage[UINT32_C(0x00009D81)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009D84), "CENTER", 6u); storage[UINT32_C(0x00009D8A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009D8C), "RIGHT", 5u); storage[UINT32_C(0x00009D91)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009D94), "buffer", 6u); storage[UINT32_C(0x00009D9A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009D9C), "explorer", 8u); storage[UINT32_C(0x00009DA4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009DA8), "HTS", 3u); storage[UINT32_C(0x00009DAB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009DAC), "DISCARD_OLD_TEXT", 16u); storage[UINT32_C(0x00009DBC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009DC4), "HyperTextCtrl::LoadUI(%s) -> Not enough params in key 'linkcolor'", 65u); storage[UINT32_C(0x00009E05)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009E08), "%x %x", 5u); storage[UINT32_C(0x00009E0D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009E10), "linkcolor", 9u); storage[UINT32_C(0x00009E19)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009E1C), "hyperText", 9u); storage[UINT32_C(0x00009E25)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009E28), "textFormat", 10u); storage[UINT32_C(0x00009E32)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009E34), "..\\ShareClientSeverCode\\Interface\\HyperTextCtrl.cpp", 51u); storage[UINT32_C(0x00009E67)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009E68), "\270pQ\000\240\356J\000\020\022K\000\260\010K\000\340\031M\000@\360J\000\220\005K\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000P\002K", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009E9C), "Sounds\\in_link.wav", 18u); storage[UINT32_C(0x00009EAE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009EB4), "%s(): HyperTextEdit control must have '%s' parameter in file '%s', lines: [%d, %d]", 82u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009F08), "bad cast", 8u); storage[UINT32_C(0x00009F10)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009F14), "\004qQ\000p;K\000\340\025K\000\360\025K\000\200&K\000\320\026K\000V\366N\000\000\026K\000\240(K\000\\\366N\000b\366N\000\340.K\000\340/K\000`\027K\000P\026K\000\360\027K", 63u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009F54), "..\\ShareClientSeverCode\\Interface\\HyperTextEditControl.cpp", 58u); storage[UINT32_C(0x00009F8E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009F90), "\204qQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009F94), "\220MK", 3u); storage[UINT32_C(0x00009F97)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009F9C), "`\000\000\0004sQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009FA4), "\200WK", 3u); storage[UINT32_C(0x00009FA7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009FAC), "h\000\000\000\314sQ\000\020dK\000 wK\000\300EK\000\340\031M\000\320GK\0000oK\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\020oK", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00009FE4), "\n\r", 2u); storage[UINT32_C(0x00009FE6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009FE8), "_hyperTextEdit.log", 18u); storage[UINT32_C(0x00009FFA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00009FFC), "visibleTextMargin", 17u); storage[UINT32_C(0x0000A00D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A010), "titleTextMargin", 15u); storage[UINT32_C(0x0000A01F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A020), "numbersOnly", 11u); storage[UINT32_C(0x0000A02B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A02C), "enterPlainText", 14u); storage[UINT32_C(0x0000A03A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A03C), "editMode", 8u); storage[UINT32_C(0x0000A044)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A048), "uline", 5u); storage[UINT32_C(0x0000A04D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A050), "vline", 5u); storage[UINT32_C(0x0000A055)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A058), "cursorType", 10u); storage[UINT32_C(0x0000A062)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A064), "maxHistoryLength", 16u); storage[UINT32_C(0x0000A074)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A078), "maxHyperTextLength", 18u); storage[UINT32_C(0x0000A08A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A08C), "maxVisibleTextLength", 20u); storage[UINT32_C(0x0000A0A0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A0A4), "cursorColor", 11u); storage[UINT32_C(0x0000A0AF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A0B0), "SphereUI::HyperTextEditControl::LoadUI", 38u); storage[UINT32_C(0x0000A0D6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A0D8), "textColor", 9u); storage[UINT32_C(0x0000A0E1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A0E4), "\334\017I@", 4u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A0E8), "NOTIFY_FOCUS", 12u); storage[UINT32_C(0x0000A0F4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A0F8), "\030tQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A0FC), "\360wK", 3u); storage[UINT32_C(0x0000A0FF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A100), "\240\200K\000\300}K\000\340\031M\000pyK\000\360zK\000\020\177K\000\200+M\000\340*M\000\300\032M\000\000\033M\000\220\177K", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A12C), "rotate", 6u); storage[UINT32_C(0x0000A132)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A134), "imageStyle", 10u); storage[UINT32_C(0x0000A13E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A140), "alpha", 5u); storage[UINT32_C(0x0000A145)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A148), "ImageCtrl::LoadUI(%s,%d,%d) -> Sprite '%s' not found.", 53u); storage[UINT32_C(0x0000A17D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A180), "image", 5u); storage[UINT32_C(0x0000A185)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A188), "..\\ShareClientSeverCode\\Interface\\ImageCtrl.cpp", 47u); storage[UINT32_C(0x0000A1B7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A1C1), "\200f@fonts.cfg", 12u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A1D0), "..\\ShareClientSeverCode\\Interface\\Interface.cpp", 47u); storage[UINT32_C(0x0000A1FF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A200), "cursman", 7u); storage[UINT32_C(0x0000A207)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A208), "curseye", 7u); storage[UINT32_C(0x0000A20F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A210), "DestroWindowUI(%d) -> Can't destroy controls.", 45u); storage[UINT32_C(0x0000A23D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A240), "sprite", 6u); storage[UINT32_C(0x0000A246)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A24C), "dtQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A250), "p\220K", 3u); storage[UINT32_C(0x0000A253)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A254), "h\366N\000n\366N\000@\215K\000\000\217K\000V\366N\000\020\213K\000t\366N\000\\\366N\000b\366N\000\200\213K\000P\217K\000z\366N\000\200\366N\000\206\366N\000\260tQ\000\240\222K\000\000\000\000\000P", 69u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A29C), "DestroWindowUI(0x%X) -> Can't destroy controls.", 47u); storage[UINT32_C(0x0000A2CB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A2CC), "Language\\helpindex.hts", 22u); storage[UINT32_C(0x0000A2E2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A2E4), "\232\231\231>.hts", 8u); storage[UINT32_C(0x0000A2EC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A2F0), "Language\\", 9u); storage[UINT32_C(0x0000A2F9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A2FC), "Language\\*%s.hts", 16u); storage[UINT32_C(0x0000A30C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A310), "WindowUI(%s,%d %d). Window name not specified.", 46u); storage[UINT32_C(0x0000A33E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A340), "windowUI", 8u); storage[UINT32_C(0x0000A348)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A34C), "loadscreen.ui", 13u); storage[UINT32_C(0x0000A359)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A35C), "Effects\\*.ui", 12u); storage[UINT32_C(0x0000A368)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A36C), "Effects\\sprites.ui", 18u); storage[UINT32_C(0x0000A37E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A380), "Can't load font '%s'", 20u); storage[UINT32_C(0x0000A394)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A398), ".sfn", 4u); storage[UINT32_C(0x0000A39C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A3A0), "CreateWindow(%s) -> Can't create reference class", 48u); storage[UINT32_C(0x0000A3D0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A3D4), "help", 4u); storage[UINT32_C(0x0000A3D8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A3DC), "V\273\302TUU\231?", 8u); storage[UINT32_C(0x0000A3E4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A3E9), "\340\317?\000\000\000\000\000\240\352?\000\000\000\000\000\260\327?", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A3FC), "russian_sphere1", 15u); storage[UINT32_C(0x0000A40B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A40C), "english_sphere1", 15u); storage[UINT32_C(0x0000A41B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A41C), "loadscreen", 10u); storage[UINT32_C(0x0000A426)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A428), "File '%s' doesn't exists.", 25u); storage[UINT32_C(0x0000A441)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A444), "NEW_FONT_", 9u); storage[UINT32_C(0x0000A44D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A450), "NEW_FONTS_NUMBER", 16u); storage[UINT32_C(0x0000A460)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A464), "string", 6u); storage[UINT32_C(0x0000A46A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A46C), "stringsUI", 9u); storage[UINT32_C(0x0000A475)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A478), "Language\\strings.ui", 19u); storage[UINT32_C(0x0000A48B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A48C), "NULL", 4u); storage[UINT32_C(0x0000A490)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A494), "null", 4u); storage[UINT32_C(0x0000A498)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A49C), "Effects\\loadscreen.ui", 21u); storage[UINT32_C(0x0000A4B1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A4B4), "INTFS_SOUNDS", 12u); storage[UINT32_C(0x0000A4C0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A4C4), "EN_CROSS", 8u); storage[UINT32_C(0x0000A4CC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A4D0), "control.cfg", 11u); storage[UINT32_C(0x0000A4DB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A4DC), "\010uQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A4E0), "\340\343K", 3u); storage[UINT32_C(0x0000A4E3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A4E4), "\300\350K\000p\341K\000\340\031M\000\000\320K\000@\323K\000\200\330K\000p\331K\0000\332K\000\300\032M\000\000\033M\000\300\343K", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A510), "..\\ShareClientSeverCode\\Interface\\ItemListCtrl.cpp", 50u); storage[UINT32_C(0x0000A542)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A544), "userMove", 8u); storage[UINT32_C(0x0000A54C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A550), "horizontal", 10u); storage[UINT32_C(0x0000A55A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A55C), "canSelectItems", 14u); storage[UINT32_C(0x0000A56A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A56C), "selectedItem", 12u); storage[UINT32_C(0x0000A578)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A57C), "ListItemCtrl::LoadUI(%s,%d,%d) -> Sprite '%s' not found.", 56u); storage[UINT32_C(0x0000A5B4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A5B8), "selectSprite", 12u); storage[UINT32_C(0x0000A5C4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A5C8), "createItems", 11u); storage[UINT32_C(0x0000A5D3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A5D4), "ListItemCtrl::LoadUI(%s,%d,%d) -> Can't load item template.", 59u); storage[UINT32_C(0x0000A60F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A610), "itemTemplate", 12u); storage[UINT32_C(0x0000A61C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A620), "hscrollbar", 10u); storage[UINT32_C(0x0000A62A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A62C), "vscrollbar", 10u); storage[UINT32_C(0x0000A636)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A638), "SHIFT\000\000\000CTRL\000\000\000\000TAB\000/\000\000\000M\000\000\000N\000\000\000B\000\000\000V\000\000\000C\000\000\000X\000\000\000Z\000\000\000'\000\000\000;\000\000\000L\000\000\000K\000\000\000J\000\000\000H\000\000\000G\000\000\000F\000\000\000D\000\000\000S\000\000\000A\000\000\000]\000\000\000[\000\000\000P\000\000\000O\000\000\000I\000\000\000U\000\000\000Y\000\000\000T\000\000\000R\000\000\000E\000\000\000W\000\000\000Q\000\000\000=\000\000\000-\000\000\0000\000\000\0009\000\000\0008\000\000\0007\000\000\0006\000\000\0005\000\000\0004\000\000\0003\000\000\0002\000\000\0001\000\000\000`\000\000\000PAGEDOWN\000\000\000\000PAGEUP\000\000NUMPADPNT\000\000\000NUMPADDIV\000\000\000NUMPADSUBT\000\000NUML", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A738), "OCK\000NUMPADADD\000\000\000NUMPADMULT\000\000NUMPAD9\000NUMPAD8\000NUMPAD7\000NUMPAD6\000NUMPAD5\000NUMPAD4\000NUMPAD3\000NUMPAD2\000NUMPAD1\000NUMPAD0\000CAPSLOCK\000\000\000\000ENTER\000\000\000DELETE\000\000INSERT\000\000DOWN\000\000\000\000UP\000\000LEFT\000\000\000\000HOME\000\000\000\000END\000SPACE\000\000\000BACKSPACE\000\000\000PAUSE\000\000\000SCRL_LOCK\000\000\000F12\000F11\000F10\000F9\000\000F8\000\000F7\000\000F6\000\000F5\000\000F4\000\000F3", 254u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A838), "F2\000\000F1\000\000ESCAPE", 14u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A848), "???", 3u); storage[UINT32_C(0x0000A84B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A84C), "333333\343?  ...", 13u); storage[UINT32_C(0x0000A859)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A85C), "TuQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A860), "\200\rL", 3u); storage[UINT32_C(0x0000A863)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A864), "\300\004L\000\300\010L\000\340\031M\000\020\362K\000\360\356K\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\200\376K", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A890), "..\\ShareClientSeverCode\\Interface\\ListCtrl.cpp", 46u); storage[UINT32_C(0x0000A8BE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A8C0), "ListCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'addstring'", 57u); storage[UINT32_C(0x0000A8F9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A8FC), "%s %x", 5u); storage[UINT32_C(0x0000A901)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A904), "addstring", 9u); storage[UINT32_C(0x0000A90D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A910), "chatlike", 8u); storage[UINT32_C(0x0000A918)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A91C), "ListCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'selectionLineColor'", 66u); storage[UINT32_C(0x0000A95E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A960), "selectionLineColor", 18u); storage[UINT32_C(0x0000A972)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A974), "ListCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'selectionColor'", 62u); storage[UINT32_C(0x0000A9B2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A9B4), "selectionColor", 14u); storage[UINT32_C(0x0000A9C2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A9C4), "selectionBorder", 15u); storage[UINT32_C(0x0000A9D3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A9D4), "canSelect", 9u); storage[UINT32_C(0x0000A9DD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A9E0), "useContinueMark", 15u); storage[UINT32_C(0x0000A9EF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000A9F0), "formatStrings", 13u); storage[UINT32_C(0x0000A9FD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AA00), "CENTER_Y", 8u); storage[UINT32_C(0x0000AA08)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AA0C), "CENTER_X", 8u); storage[UINT32_C(0x0000AA14)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AA18), "RIGHT_Y", 7u); storage[UINT32_C(0x0000AA1F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AA20), "RIGHT_X", 7u); storage[UINT32_C(0x0000AA27)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AA28), "SphereUI::CMenuListControl::GetSprite", 37u); storage[UINT32_C(0x0000AA4D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AA50), "titleTextFormat", 15u); storage[UINT32_C(0x0000AA5F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AA60), "titleColor", 10u); storage[UINT32_C(0x0000AA6A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AA6C), "needShowTitle", 13u); storage[UINT32_C(0x0000AA79)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AA7C), "listItemTextFormat", 18u); storage[UINT32_C(0x0000AA8E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AA90), "listItemTextMargin", 18u); storage[UINT32_C(0x0000AAA2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AAA4), "hoveredColor", 12u); storage[UINT32_C(0x0000AAB0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AAB4), "disabledColor", 13u); storage[UINT32_C(0x0000AAC1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AAC4), "normalColor", 11u); storage[UINT32_C(0x0000AACF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AAD0), "bottomSprite", 12u); storage[UINT32_C(0x0000AADC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AAE0), "middleHoveredSprite", 19u); storage[UINT32_C(0x0000AAF3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AAF4), "middleSprite", 12u); storage[UINT32_C(0x0000AB00)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AB04), "SphereUI::CMenuListControl::LoadUI", 34u); storage[UINT32_C(0x0000AB26)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AB28), "topSprite", 9u); storage[UINT32_C(0x0000AB31)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AB34), "..\\ShareClientSeverCode\\Interface\\MenuListControl.cpp", 53u); storage[UINT32_C(0x0000AB69)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AB6C), "huQ\0000\033L\000\260/L\000@*L\000\340\031M\000@\032L\000`\026L\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000 *L", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000ABA4), "%s(): MenuList control must have '%s' parameter in file '%s', lines: [%d, %d]", 77u); storage[UINT32_C(0x0000ABF1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000ABF4), "%s(): failed to find sprite '%s'", 32u); storage[UINT32_C(0x0000AC14)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AC18), "\264uQ\0000\002M\000 5L\0000\001M\000\340\031M\000\000\372L\000`0L\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000p2L", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AC4C), "..\\ShareClientSeverCode\\Interface\\MiniHelpCtrl.cpp", 50u); storage[UINT32_C(0x0000AC7E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AC80), "<vQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AC84), "\260GM", 3u); storage[UINT32_C(0x0000AC87)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AC88), "p6L\000\0207L\000\340\031M\000P7L\000\260(M\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000 7L", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000ACB4), "..\\ShareClientSeverCode\\Interface\\MinimapControl.cpp", 52u); storage[UINT32_C(0x0000ACE8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000ACEC), "arup", 4u); storage[UINT32_C(0x0000ACF0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000ACF4), "SphereUI::CMinimapTexture::CMinimapTexture(): failed to create a texture", 72u); storage[UINT32_C(0x0000AD3C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AD40), "..\\ShareClientSeverCode\\Interface\\MinimapTexture.cpp", 52u); storage[UINT32_C(0x0000AD74)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AD78), "STYLE1", 6u); storage[UINT32_C(0x0000AD7E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AD80), "PERCENT", 7u); storage[UINT32_C(0x0000AD87)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AD88), "\210vQ\000\300?L\000\260BL\000\260>L\000\340\031M\000\000<L\000\240\260B\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\300\023J", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000ADBC), "%d%%", 4u); storage[UINT32_C(0x0000ADC0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000ADC4), "%d / %d", 7u); storage[UINT32_C(0x0000ADCB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000ADCC), "ProgressBar::LoadUI(%s,%d,%d) -> Not enough args in 'statusPos'.", 64u); storage[UINT32_C(0x0000AE0C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AE10), "statusPos", 9u); storage[UINT32_C(0x0000AE19)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AE1C), "progressPos", 11u); storage[UINT32_C(0x0000AE27)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AE28), "ProgressBar::LoadUI(%s,%d,%d) -> Not enough args in 'range'.", 60u); storage[UINT32_C(0x0000AE64)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AE68), "statusShow", 10u); storage[UINT32_C(0x0000AE72)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AE74), "ProgressBar::LoadUI(%s,%d,%d) -> Sprite '%s' not found.", 55u); storage[UINT32_C(0x0000AEAB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AEAC), "..\\ShareClientSeverCode\\Interface\\ProgressBar.cpp", 49u); storage[UINT32_C(0x0000AEDD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AEE0), "\324vQ\000\320\016J\000\300CL\000\300\022J\000\340\031M\000\340\023J\000\000\022J\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\300\023J\000`CL", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AF18), "..\\ShareClientSeverCode\\Interface\\RadioButton.cpp", 49u); storage[UINT32_C(0x0000AF49)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AF4C), "..\\ShareClientSeverCode\\Interface\\RichEditCtrl.cpp", 50u); storage[UINT32_C(0x0000AF7E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AF80), "$wQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AF84), "\200DL", 3u); storage[UINT32_C(0x0000AF87)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AF88), "\020^L\000pcL\000\340\031M\000\220ML\000\020hL\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\220YL\000pwQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AFB8), "\200kL", 3u); storage[UINT32_C(0x0000AFBB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AFBC), " \177L\000\260zL\000\340\031M\000\300nL\000 qL\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\300}L\000\200xL\000\360|L", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000AFF0), "..\\ShareClientSeverCode\\Interface\\ScrollBar.cpp", 47u); storage[UINT32_C(0x0000B01F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B020), "deltaStep", 9u); storage[UINT32_C(0x0000B029)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B02C), "rightbutton", 11u); storage[UINT32_C(0x0000B037)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B038), "leftbutton", 10u); storage[UINT32_C(0x0000B042)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B044), "ScrollBar::LoadUI(%s,%d,%d) -> Not enough args in 'scrollSpr'.", 62u); storage[UINT32_C(0x0000B082)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B084), "%s %d %d", 8u); storage[UINT32_C(0x0000B08C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B090), "scrollSpr", 9u); storage[UINT32_C(0x0000B099)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B09C), "ScrollBar::LoadUI(%s,%d,%d) -> Sprite '%s' not found.", 53u); storage[UINT32_C(0x0000B0D1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B0D4), "postMessage", 11u); storage[UINT32_C(0x0000B0DF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B0E0), "ScrollBar::LoadUI(%s,%d,%d) -> Invalid args in 'bounds'", 55u); storage[UINT32_C(0x0000B117)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B118), "bounds", 6u); storage[UINT32_C(0x0000B11E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B120), "Sounds\\in_page.wav", 18u); storage[UINT32_C(0x0000B132)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B134), "Sounds\\in_line.wav", 18u); storage[UINT32_C(0x0000B146)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B148), "\274wQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B14C), "\300\200L", 3u); storage[UINT32_C(0x0000B14F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B150), "P\204L\000\260zL\000\340\031M\000\340\202L\000 qL\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\300}L\000p\202L\000`\200L", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B184), "SliderCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'statusPos'", 59u); storage[UINT32_C(0x0000B1BF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B1C0), "defaultPos", 10u); storage[UINT32_C(0x0000B1CA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B1CC), "page", 4u); storage[UINT32_C(0x0000B1D0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B1D4), "step", 4u); storage[UINT32_C(0x0000B1D8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B1DC), "SliderCtrl::LoadUI(%s,%d,%d) -> Invalid args in 'range'", 55u); storage[UINT32_C(0x0000B213)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B214), "..\\ShareClientSeverCode\\Interface\\SliderCtrl.cpp", 48u); storage[UINT32_C(0x0000B244)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B248), "\014xQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B24C), "\360\225L", 3u); storage[UINT32_C(0x0000B24F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B250), "\320\231L\000P\222L\000\340\031M\000\340\205L\000\000\215L\000@*M\000p\205L\000\340*M\000\300\032M\000\000\033M\000P\221L", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B27C), "..\\ShareClientSeverCode\\Interface\\SlotCtrl.cpp", 46u); storage[UINT32_C(0x0000B2AA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B2AC), "slotItem", 8u); storage[UINT32_C(0x0000B2B4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B2B8), "slotnumber", 10u); storage[UINT32_C(0x0000B2C2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B2C4), "SlotCtrl::LoadUI(%s,%d,%d) Invalid args in 'textofs'", 52u); storage[UINT32_C(0x0000B2F8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B2FC), "textofs", 7u); storage[UINT32_C(0x0000B303)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B304), "SlotCtrl::LoadUI(%s,%d,%d) Invalid args in 'slotpicofs'", 55u); storage[UINT32_C(0x0000B33B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B33C), "slotpicofs", 10u); storage[UINT32_C(0x0000B346)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B348), "slotborder", 10u); storage[UINT32_C(0x0000B352)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B354), "slotempty", 9u); storage[UINT32_C(0x0000B35D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B360), "SlotCtrl:: Sprite not found '%s'", 32u); storage[UINT32_C(0x0000B380)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B384), "slotFull", 8u); storage[UINT32_C(0x0000B38C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B390), "slotpic", 7u); storage[UINT32_C(0x0000B397)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B398), "%dx%d %d", 8u); storage[UINT32_C(0x0000B3A0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B3A4), "SSKS_NUMBER", 11u); storage[UINT32_C(0x0000B3AF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B3B0), "quit", 4u); storage[UINT32_C(0x0000B3B4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B3B8), "authors", 7u); storage[UINT32_C(0x0000B3BF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B3C0), "UISTR_WT_OPT36", 14u); storage[UINT32_C(0x0000B3CE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B3D0), "UISTR_WT_OPT16", 14u); storage[UINT32_C(0x0000B3DE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B3E0), "UISTR_WT_OPT17", 14u); storage[UINT32_C(0x0000B3EE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B3F0), "UISTR_WT_OPT18", 14u); storage[UINT32_C(0x0000B3FE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B400), "UISTR_WT_OPT19", 14u); storage[UINT32_C(0x0000B40E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B410), "UISTR_WT_OPT20", 14u); storage[UINT32_C(0x0000B41E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B420), "UISTR_WT_OPT21", 14u); storage[UINT32_C(0x0000B42E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B430), "UISTR_WT_OPT34", 14u); storage[UINT32_C(0x0000B43E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B440), "UISTR_WT_OPT33", 14u); storage[UINT32_C(0x0000B44E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B450), "sound_options", 13u); storage[UINT32_C(0x0000B45D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B460), "UISTR_WT_OPT24", 14u); storage[UINT32_C(0x0000B46E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B470), "UISTR_WT_OPT23", 14u); storage[UINT32_C(0x0000B47E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B480), "control_options", 15u); storage[UINT32_C(0x0000B48F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B490), "UISTR_WT_KEY%02u", 16u); storage[UINT32_C(0x0000B4A0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B4A4), "SSKS", 4u); storage[UINT32_C(0x0000B4A8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B4AC), "BALR", 4u); storage[UINT32_C(0x0000B4B0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B4B4), "MBST", 4u); storage[UINT32_C(0x0000B4B8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B4BC), "IAPM", 4u); storage[UINT32_C(0x0000B4C0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B4C4), "ISAD", 4u); storage[UINT32_C(0x0000B4C8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B4CC), "ISSN", 4u); storage[UINT32_C(0x0000B4D0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B4D4), "INSN", 4u); storage[UINT32_C(0x0000B4D8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B4DC), "INAW", 4u); storage[UINT32_C(0x0000B4E0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B4E4), "interface_options", 17u); storage[UINT32_C(0x0000B4F5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B4F8), "..\\ShareClientSeverCode\\Interface\\SphereOptions.cpp", 51u); storage[UINT32_C(0x0000B52B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B52C), "Found ZERO video modes!", 23u); storage[UINT32_C(0x0000B543)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B544), "UISTR_WT_OPT62", 14u); storage[UINT32_C(0x0000B552)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B554), "UISTR_WT_OPT61", 14u); storage[UINT32_C(0x0000B562)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B564), "gfx_options", 11u); storage[UINT32_C(0x0000B56F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B570), "CHAT_EDIT_FONT", 14u); storage[UINT32_C(0x0000B57E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B580), "CHAT_LIST_FONT", 14u); storage[UINT32_C(0x0000B58E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B590), "font_options", 12u); storage[UINT32_C(0x0000B59C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B5A0), "XxQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B5A4), "P\325L", 3u); storage[UINT32_C(0x0000B5A7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B5A9), "\336L\0000\332L\000\340\031M\000`\327L\000 \330L\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\020\332L\000\360\333L", 46u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B5D8), "..\\ShareClientSeverCode\\Interface\\SpinCtrl.cpp", 46u); storage[UINT32_C(0x0000B606)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B608), "notifyChange", 12u); storage[UINT32_C(0x0000B614)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B618), "badyCtrlID", 10u); storage[UINT32_C(0x0000B622)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B624), "spinPos", 7u); storage[UINT32_C(0x0000B62B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B62C), "SpinButton::LoadUI(%s,%d,%d) -> Invalid args in 'range'", 55u); storage[UINT32_C(0x0000B663)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B664), "defButtonStyle", 14u); storage[UINT32_C(0x0000B672)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B674), "Set Range %d %d", 15u); storage[UINT32_C(0x0000B683)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B684), "Set pos %d", 10u); storage[UINT32_C(0x0000B68E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B690), "Set step %d", 11u); storage[UINT32_C(0x0000B69B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B69C), "SpinButton::UpdateStatus() -> Bady '%d' not found.", 50u); storage[UINT32_C(0x0000B6CE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B6D0), "..\\ShareClientSeverCode\\Interface\\Sprite.cpp", 44u); storage[UINT32_C(0x0000B6FC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B700), "Sprite::Texture not found '%s'", 30u); storage[UINT32_C(0x0000B71E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B724), "Sprite::Load(%s,%d,%d) -> Incorrect number of args in 'tcoords'.", 64u); storage[UINT32_C(0x0000B764)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B768), "%d %d %d %d %d %d %d %d %d", 26u); storage[UINT32_C(0x0000B782)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B784), "tcoords", 7u); storage[UINT32_C(0x0000B78B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B78C), "Sprite::Load(%s,%d,%d) -> Incorrect number of args in 'texture'.", 64u); storage[UINT32_C(0x0000B7CC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B7D0), "%s %d %d %d %d %d %d %d %d", 26u); storage[UINT32_C(0x0000B7EA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B7EC), "Sprite::Load(%s,%d,%d) -> At least one texture must be specified.", 65u); storage[UINT32_C(0x0000B82D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B830), "Sprite::Load(%s,%d,%d) -> Size not specified.", 45u); storage[UINT32_C(0x0000B85D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B860), "size", 4u); storage[UINT32_C(0x0000B864)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B868), "Sprite::Load(%s,%d,%d) -> Name not specified.", 45u); storage[UINT32_C(0x0000B895)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B898), "\244xQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B89C), "\340\363L", 3u); storage[UINT32_C(0x0000B89F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B8A0), "p\366L\000\320-M\000\340\031M\000\300\364L\000\020\363L\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\300\023J", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B8CC), "NOTIFY_CLICK", 12u); storage[UINT32_C(0x0000B8D8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B8DC), "textStyle", 9u); storage[UINT32_C(0x0000B8E5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B8E8), "..\\ShareClientSeverCode\\Interface\\TextCtrl.cpp", 46u); storage[UINT32_C(0x0000B916)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B918), "\360xQ\0000\002M\000 \377L\0000\001M\000\340\031M\000\000\372L\000\300\367L\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000p2L", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B94C), "..\\ShareClientSeverCode\\Interface\\ToolTip.cpp", 45u); storage[UINT32_C(0x0000B979)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B97C), "toolstr", 7u); storage[UINT32_C(0x0000B983)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B984), "ToolTipCtrl::LoadUI(%s,%d,%d) -> Not enough args in 'margin'", 60u); storage[UINT32_C(0x0000B9C0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B9C4), "margin", 6u); storage[UINT32_C(0x0000B9CA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000B9CC), "ToolTipCtrl::LoadUI(%s,%d,%d) -> Not enough args in 'backcolor'", 63u); storage[UINT32_C(0x0000BA0B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BA0C), "backcolor", 9u); storage[UINT32_C(0x0000BA15)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BA1C), "ToolTipCtrl::LoadUI(%s,%d,%d) -> Not enough args in 'textcolor'", 63u); storage[UINT32_C(0x0000BA5B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BA5C), "font", 4u); storage[UINT32_C(0x0000BA60)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BA64), "\004yQ\000\020\016M\000\260\013M\000\300\016M\000\340\031M\000 \005M\000p\006M\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\320\tM", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BA98), "..\\ShareClientSeverCode\\Interface\\WebBrowserControl.cpp", 55u); storage[UINT32_C(0x0000BACF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BAD4), "SphereUI::CWebBrowserControl::CWebBrowserControl(): failed to create web browser object", 87u); storage[UINT32_C(0x0000BB2B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BB2C), "SphereUI::CWebBrowserControl::CWebBrowserControl(): failed to create bitmap/texture", 83u); storage[UINT32_C(0x0000BB7F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BB84), "SphereUI::CWebBrowserControl::ProcessInitializeMessage(): failed to create web browser object", 93u); storage[UINT32_C(0x0000BBE1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BBE4), "SphereUI::CWebBrowserControl::ProcessInitializeMessage(): failed to create bitmap/texture", 89u); storage[UINT32_C(0x0000BC3D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BC40), "URL", 3u); storage[UINT32_C(0x0000BC43)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BC44), "..\\ShareClientSeverCode\\Interface\\Win32Interface.cpp", 52u); storage[UINT32_C(0x0000BC78)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BC7C), "COLORPICKER", 11u); storage[UINT32_C(0x0000BC87)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BC88), "FONTPICKER", 10u); storage[UINT32_C(0x0000BC92)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BC94), "HTEDIT", 6u); storage[UINT32_C(0x0000BC9A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BC9C), "HTCHATLISTCTRL", 14u); storage[UINT32_C(0x0000BCAA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BCAC), "MENULISTCTRL", 12u); storage[UINT32_C(0x0000BCB8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BCBC), "MINIMAP", 7u); storage[UINT32_C(0x0000BCC3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BCC4), "WEBBROWSER", 10u); storage[UINT32_C(0x0000BCCE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BCD0), "FILTERLISTCTRL", 14u); storage[UINT32_C(0x0000BCDE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BCE0), "RICHEDIT", 8u); storage[UINT32_C(0x0000BCE8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BCEC), "SPINBUTTON", 10u); storage[UINT32_C(0x0000BCF6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BCF8), "SLOT", 4u); storage[UINT32_C(0x0000BCFC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD00), "EDIT", 4u); storage[UINT32_C(0x0000BD04)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD08), "LISTITEM", 8u); storage[UINT32_C(0x0000BD10)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD14), "SLIDER", 6u); storage[UINT32_C(0x0000BD1A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD1C), "TEXTLIST", 8u); storage[UINT32_C(0x0000BD24)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD28), "RADIOBUTTON", 11u); storage[UINT32_C(0x0000BD33)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD34), "CHECKBOX", 8u); storage[UINT32_C(0x0000BD3C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD40), "HYPER_TEXT", 10u); storage[UINT32_C(0x0000BD4A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD4C), "SCROLL_BAR", 10u); storage[UINT32_C(0x0000BD56)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD58), "PROGRESS_BAR", 12u); storage[UINT32_C(0x0000BD64)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD68), "IMAGE", 5u); storage[UINT32_C(0x0000BD6D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD70), "TEXT", 4u); storage[UINT32_C(0x0000BD74)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD78), "BUTTON", 6u); storage[UINT32_C(0x0000BD7E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD80), "MOVE_BOTTOM", 11u); storage[UINT32_C(0x0000BD8B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD8C), "MOVE_TOP", 8u); storage[UINT32_C(0x0000BD94)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BD98), "MOVE_RIGHT", 10u); storage[UINT32_C(0x0000BDA2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BDA4), "MOVE_LEFT", 9u); storage[UINT32_C(0x0000BDAD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BDB0), "ALPHA_OUT", 9u); storage[UINT32_C(0x0000BDB9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BDBC), "ALPHA_IN", 8u); storage[UINT32_C(0x0000BDC4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BDC8), "LEFT_Y", 6u); storage[UINT32_C(0x0000BDCE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BDD0), "LEFT_X", 6u); storage[UINT32_C(0x0000BDD6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BDD8), "SphereUI::Window::setFont", 25u); storage[UINT32_C(0x0000BDF1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BDF4), "SphereUI::Window::getFont", 25u); storage[UINT32_C(0x0000BE0D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BE10), "Sounds\\in_winclose.wav", 22u); storage[UINT32_C(0x0000BE26)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BE28), "Sounds\\in_winopen.wav", 21u); storage[UINT32_C(0x0000BE3D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BE40), "..\\ShareClientSeverCode\\Interface\\Window.cpp", 44u); storage[UINT32_C(0x0000BE6C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BE70), "PyQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BE74), "\260GM", 3u); storage[UINT32_C(0x0000BE77)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BE78), "\020UM\000\320-M\000\340\031M\000\340%M\000\260(M\000@*M\000\200+M\000\340*M\000\300\032M\000\000\033M\000\300\023J", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BEA4), "canDragDrop", 11u); storage[UINT32_C(0x0000BEAF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BEB0), "setWindowText", 13u); storage[UINT32_C(0x0000BEBD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BEC0), "windowHelp", 10u); storage[UINT32_C(0x0000BECA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BECC), "windowText", 10u); storage[UINT32_C(0x0000BED6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BEDC), "Window::LoadControl(%s,%d,%d) -> Not enough args in 'textColor' in control %d", 77u); storage[UINT32_C(0x0000BF29)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BF2C), "group", 5u); storage[UINT32_C(0x0000BF31)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BF34), "hidden", 6u); storage[UINT32_C(0x0000BF3A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BF3C), "disabled", 8u); storage[UINT32_C(0x0000BF44)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BF4C), "Window::LoadControl(%s,%d,%d) -> Not enough args in 'showTitle'", 63u); storage[UINT32_C(0x0000BF8B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BF8C), "showTitle", 9u); storage[UINT32_C(0x0000BF95)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BF9C), "Window::LoadControl(%s,%d,%d) -> Not enough args in 'disabledColor'", 67u); storage[UINT32_C(0x0000BFDF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BFE0), "disabledcolor", 13u); storage[UINT32_C(0x0000BFED)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000BFF0), "Window::LoadControl(%s,%d,%d) -> Size is wrong in control %d.", 61u); storage[UINT32_C(0x0000C02D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C034), "Window::LoadControl(%s,%d,%d) -> Position is wrong in control %d.", 65u); storage[UINT32_C(0x0000C075)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C078), "position", 8u); storage[UINT32_C(0x0000C080)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C084), "tooltip", 7u); storage[UINT32_C(0x0000C08B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C08C), "Window::LoadUI(%s,%d,%d) -> ClassID not defined in control %d.", 62u); storage[UINT32_C(0x0000C0CA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C0CC), "Window::LoadUI(%s,%d,%d) -> Unknown ClassID(%s) in control %d.", 62u); storage[UINT32_C(0x0000C10A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C10C), "classID", 7u); storage[UINT32_C(0x0000C113)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C114), "control", 7u); storage[UINT32_C(0x0000C11B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C11C), "hideEffect", 10u); storage[UINT32_C(0x0000C126)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C128), "showEffect", 10u); storage[UINT32_C(0x0000C132)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C134), "Window::LoadUI(%s,%d,%d) -> Not enough args in 'disabledColor'", 62u); storage[UINT32_C(0x0000C172)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C174), "Window::LoadUI(%s,%d,%d) -> Not enough args in 'textColor'", 58u); storage[UINT32_C(0x0000C1AE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C1B0), "alignWin", 8u); storage[UINT32_C(0x0000C1B8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C1BC), "saveLastPosition", 16u); storage[UINT32_C(0x0000C1CC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C1D0), "Window::LoadUI(%s,%d,%d) -> Not enough args in 'rectTitle'", 58u); storage[UINT32_C(0x0000C20A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C20C), "rectTitle", 9u); storage[UINT32_C(0x0000C215)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C218), "canNotCross", 11u); storage[UINT32_C(0x0000C223)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C224), "canGoTop", 8u); storage[UINT32_C(0x0000C22C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C230), "Window::LoadUI(%s,%d,%d) -> Not enough args in 'size'", 53u); storage[UINT32_C(0x0000C265)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C268), "Window::LoadUI(%s,%d,%d) -> Not enough args in 'position'", 57u); storage[UINT32_C(0x0000C2A1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C2A4), "escapeHandle", 12u); storage[UINT32_C(0x0000C2B0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C2B4), "Window::LoadUI(%s,%d,%d) -> Not enough args in 'showTitle'", 58u); storage[UINT32_C(0x0000C2EE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C2F0), "Window::LoadUI(%s,%d,%d) -> Sprite '%s' not found.", 50u); storage[UINT32_C(0x0000C322)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C324), "spritesDef", 10u); storage[UINT32_C(0x0000C32E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C330), "windowName", 10u); storage[UINT32_C(0x0000C33A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C33C), "hitTransparent", 14u); storage[UINT32_C(0x0000C34A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C34C), "WARNING: Can't create reference from control.", 45u); storage[UINT32_C(0x0000C379)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C37C), "writing minidump\r\n", 18u); storage[UINT32_C(0x0000C38E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C390), "raising exception\r\n", 19u); storage[UINT32_C(0x0000C3A3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C3A4), "%d/%d/%d %02d:%02d:%02d", 23u); storage[UINT32_C(0x0000C3BB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C3BC), "%d MB user address space free\r\n", 31u); storage[UINT32_C(0x0000C3DB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C3DC), "%d MB user address space\r\n", 26u); storage[UINT32_C(0x0000C3F6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C3F8), "%d MB paging file free\r\n", 24u); storage[UINT32_C(0x0000C410)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C414), "%d MB paging file\r\n", 19u); storage[UINT32_C(0x0000C427)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C428), "%d MB physical memory free\r\n", 28u); storage[UINT32_C(0x0000C444)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C448), "%d MB physical memory\r\n", 23u); storage[UINT32_C(0x0000C45F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C460), "%d%% memory in use\r\n", 20u); storage[UINT32_C(0x0000C474)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C478), "%d processor(s), type %d\r\n", 26u); storage[UINT32_C(0x0000C492)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C494), "OS:  %s (%s)\r\n", 14u); storage[UINT32_C(0x0000C4A2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C4A4), "%s, run by %s\r\n", 15u); storage[UINT32_C(0x0000C4B3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C4B4), "Unknown", 7u); storage[UINT32_C(0x0000C4BB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C4BC), "Error occurred at %s\r\n", 22u); storage[UINT32_C(0x0000C4D2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C4D4), "an Unknown exception type", 25u); storage[UINT32_C(0x0000C4ED)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C4F0), "a Microsoft C++ Exception", 25u); storage[UINT32_C(0x0000C509)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C50C), "a DLL Initialization Failed", 27u); storage[UINT32_C(0x0000C527)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C528), "a Stack Overflow", 16u); storage[UINT32_C(0x0000C538)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C53C), "a Privileged Instruction", 24u); storage[UINT32_C(0x0000C554)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C558), "an Integer Overflow", 19u); storage[UINT32_C(0x0000C56B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C56C), "an Integer Divide by Zero", 25u); storage[UINT32_C(0x0000C585)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C588), "a Float Underflow", 17u); storage[UINT32_C(0x0000C599)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C59C), "a Float Stack Check", 19u); storage[UINT32_C(0x0000C5AF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C5B0), "a Float Overflow", 16u); storage[UINT32_C(0x0000C5C0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C5C4), "a Float Invalid Operation", 25u); storage[UINT32_C(0x0000C5DD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C5E0), "a Float Inexact Result", 22u); storage[UINT32_C(0x0000C5F6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C5F8), "a Float Divide by Zero", 22u); storage[UINT32_C(0x0000C60E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C610), "a Float Denormal Operand", 24u); storage[UINT32_C(0x0000C628)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C62C), "a Array Bounds Exceeded", 23u); storage[UINT32_C(0x0000C643)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C644), "an Invalid Disposition", 22u); storage[UINT32_C(0x0000C65A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C65C), "a Noncontinuable Exception", 26u); storage[UINT32_C(0x0000C676)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C678), "an Illegal Instruction", 22u); storage[UINT32_C(0x0000C68E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C690), "a No Memory", 11u); storage[UINT32_C(0x0000C69B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C69C), "an In Page Error", 16u); storage[UINT32_C(0x0000C6AC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C6B0), "an Access Violation", 19u); storage[UINT32_C(0x0000C6C3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C6C4), "a Breakpoint", 12u); storage[UINT32_C(0x0000C6D0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C6D4), "a Datatype Misalignment", 23u); storage[UINT32_C(0x0000C6EB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C6EC), "a Control-Break", 15u); storage[UINT32_C(0x0000C6FB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C6FC), "a Control-C", 11u); storage[UINT32_C(0x0000C707)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C708), "...\r\n", 5u); storage[UINT32_C(0x0000C70D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C710), "()", 2u); storage[UINT32_C(0x0000C712)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C714), "(%hs+%I64X)", 11u); storage[UINT32_C(0x0000C71F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C720), "Unknown:0 ", 10u); storage[UINT32_C(0x0000C72A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C72C), "%s:%u ", 6u); storage[UINT32_C(0x0000C732)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C734), "%08X  %08X  ", 12u); storage[UINT32_C(0x0000C740)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C744), "DbgHelp not initialized, code: %d\r\n", 35u); storage[UINT32_C(0x0000C767)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C768), "\r\n\r\nStack:\r\nAddress   Frame     Where\r\n", 39u); storage[UINT32_C(0x0000C78F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C790), "EFlags:\t0x%08x\tESP:\t0x%08x\tSegSs:\t0x%08x\r\n", 42u); storage[UINT32_C(0x0000C7BA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C7BC), "EIP:\t0x%08x\tEBP:\t0x%08x\tSegCs:\t0x%08x\r\n", 39u); storage[UINT32_C(0x0000C7E3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C7E4), "EBX:\t0x%08x\tECX\t0x%08x\tEDX:\t0x%08x\r\n", 36u); storage[UINT32_C(0x0000C808)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C80C), "EDI:\t0x%08x\tESI:\t0x%08x\tEAX:\t0x%08x\r\n", 37u); storage[UINT32_C(0x0000C831)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C834), " \"", 2u); storage[UINT32_C(0x0000C836)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C838), "CrashReport.exe", 15u); storage[UINT32_C(0x0000C847)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C848), "CRASH.DMP", 9u); storage[UINT32_C(0x0000C851)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C854), "\r\n===== [end of %s] =====\r\n", 27u); storage[UINT32_C(0x0000C86F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C870), "?? ", 3u); storage[UINT32_C(0x0000C873)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C874), "%02x ", 5u); storage[UINT32_C(0x0000C879)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C87C), "\r\nBytes at CS:EIP:\r\n", 20u); storage[UINT32_C(0x0000C890)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C894), "%s location %08x caused an access violation\r\n", 45u); storage[UINT32_C(0x0000C8C1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C8C4), "Write to", 8u); storage[UINT32_C(0x0000C8CC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C8D0), "Read from", 9u); storage[UINT32_C(0x0000C8D9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C8DC), "%s caused %s (0x%08x) \r\nin %s at %04x:%08x\r\n\r\n", 46u); storage[UINT32_C(0x0000C90A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C90C), "Context == NULL", 15u); storage[UINT32_C(0x0000C91B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C91C), "Exception == NULL", 17u); storage[UINT32_C(0x0000C92D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C930), "pExceptPtrs == NULL", 19u); storage[UINT32_C(0x0000C943)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C944), "Windows CE", 10u); storage[UINT32_C(0x0000C94E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C950), "Windows 2003 Server", 19u); storage[UINT32_C(0x0000C963)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C964), "Windows XP", 10u); storage[UINT32_C(0x0000C96E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C970), "Windows 2000", 12u); storage[UINT32_C(0x0000C97C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C980), "Windows NT 4", 12u); storage[UINT32_C(0x0000C98C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C990), "Windows NT 3.51", 15u); storage[UINT32_C(0x0000C99F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C9A0), "Windows ME", 10u); storage[UINT32_C(0x0000C9AA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C9AC), "Windows 98 SE", 13u); storage[UINT32_C(0x0000C9B9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C9BC), "Windows 98 SP1", 14u); storage[UINT32_C(0x0000C9CA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C9CC), "Windows 98", 10u); storage[UINT32_C(0x0000C9D6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C9D8), "Windows 95 OSR2", 15u); storage[UINT32_C(0x0000C9E7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C9E8), "Windows 95 SP1", 14u); storage[UINT32_C(0x0000C9F6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000C9F8), "Windows 95", 10u); storage[UINT32_C(0x0000CA02)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CA04), "%u.%u.%u", 8u); storage[UINT32_C(0x0000CA0C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CA10), "unknown Windows version", 23u); storage[UINT32_C(0x0000CA27)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CA28), "Could not open  ", 16u); storage[UINT32_C(0x0000CA38)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CA3C), "start", 5u); storage[UINT32_C(0x0000CA41)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CA44), "Writing  ", 9u); storage[UINT32_C(0x0000CA4D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CA50), "End of warning flush\n", 21u); storage[UINT32_C(0x0000CA65)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CA68), "End of exception\n", 17u); storage[UINT32_C(0x0000CA79)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CA7C), "Exception!\n", 11u); storage[UINT32_C(0x0000CA87)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CA88), "textures\\cursors", 16u); storage[UINT32_C(0x0000CA98)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CA9C), "GDI::CWindowDC::CWindowDC(): failed to retrieve DC", 50u); storage[UINT32_C(0x0000CACE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CAD0), "GDI::CMemoryDC::CMemoryDC(): failed to create DC", 48u); storage[UINT32_C(0x0000CB00)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CB04), "GDI::CBitmap::CBitmap(): failed to create bitmap", 48u); storage[UINT32_C(0x0000CB34)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CB3C), "GDI::CObjectSelector::CObjectSelector(): failed to select object", 64u); storage[UINT32_C(0x0000CB7C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CB80), "CreateCursor(): failed to create cursor", 39u); storage[UINT32_C(0x0000CBA7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CBA8), "CursorImageManager.cpp", 22u); storage[UINT32_C(0x0000CBBE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CBC0), "CreateCursor(): invalid cursor image format", 43u); storage[UINT32_C(0x0000CBEB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CBEC), "CreateCursor(): failed to load cursor image from file", 53u); storage[UINT32_C(0x0000CC21)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CC24), "%s\\%s.bmp", 9u); storage[UINT32_C(0x0000CC2D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CC30), "CursorManager.cpp", 17u); storage[UINT32_C(0x0000CC41)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CC44), "dyQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CC48), "\"\353N", 3u); storage[UINT32_C(0x0000CC4B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CC4C), "\"\353N\000\"\353N\000\"\353N\000\"\353N\000\"\353N\000\"\353N\000\"\353N\000\"\353N\000\"\353N\000\"\353N\000\"\353N\000\"\353N\000\"\353N\000\254yQ\000@\203M\000P|M\000\260|M\000\360|M\000\000}M\000\320\267B\000\020}M\000`}M\000\240}M\000\320}M\000\020~M\0000~M\000P~M\000`~M\000\370yQ\000@\203M\000\260\177M\0000\200M\000\240\200M\000\320\267B\000\000\201M\000@\201M\000`\201M\000\200\201M\000\320\202M\000\340\202M\000\360\202M\000\000\203M\000\020\203M", 171u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CCF8), "CSoftwareCursor::Activate(): SetCooperativeLevel() failed", 57u); storage[UINT32_C(0x0000CD31)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CD34), "CSoftwareCursor::Deactivate(): SetCooperativeLevel() failed", 59u); storage[UINT32_C(0x0000CD6F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CD70), "%s : (%s, %d, %d)\n", 18u); storage[UINT32_C(0x0000CD82)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CD84), "\310\347\342\350\355\350\362\345, \365\340\360\340\352\362\345\360\350\361\362\350\352\350 \302\340\370\345\343\356 3d-\363\361\352\356\360\350\362\345\353\377 \355\345\344\356\361\362\340\362\356\367\355\373 \344\353\377 \347\340\357\363\361\352\340 \350\343\360\373", 75u); storage[UINT32_C(0x0000CDCF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CDD0), "bbuf=", 5u); storage[UINT32_C(0x0000CDD5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CDD8), "CheckDeviceType ERROR(fullscreen):", 34u); storage[UINT32_C(0x0000CDFA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CDFC), "CheckDeviceType ERROR(windowed):", 32u); storage[UINT32_C(0x0000CE1C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CE20), "dx9Render\\CD3D9Device.cpp", 25u); storage[UINT32_C(0x0000CE39)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CE3C), "D3DXGetShaderConstantTable failed", 33u); storage[UINT32_C(0x0000CE5D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CE60), "Render err: cant create query:", 30u); storage[UINT32_C(0x0000CE7E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CE80), "zbuf=", 5u); storage[UINT32_C(0x0000CE85)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CE88), "CreateDevice ERROR:", 19u); storage[UINT32_C(0x0000CE9B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CE9C), "'\n", 2u); storage[UINT32_C(0x0000CE9E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CEA0), "V='", 3u); storage[UINT32_C(0x0000CEA3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CEA4), "\254zQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CEA8), "@\227M", 3u); storage[UINT32_C(0x0000CEAB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CEAC), " \230M\000\370zQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CEB4), "\260\227M", 3u); storage[UINT32_C(0x0000CEB7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CEB8), " \230M\000D{Q\000@\230M\000 \230M\000\220{Q\000\020\245M", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CED0), "CD3D9Device::CD3D9Device() => Direct3DCreate9() failed.", 55u); storage[UINT32_C(0x0000CF07)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CF08), "dx9Render\\PostEffectsMgr.cpp", 28u); storage[UINT32_C(0x0000CF24)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CF2A), "\376B\000\376\377F\000\000\200D\000\376\377F\000\000\000?\232\231\231>\232\231\231>", 26u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CF44), "dx9Render\\ShaderMgr.cpp", 23u); storage[UINT32_C(0x0000CF5B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CF5C), "CShaderMgr::calc_inst_code: to many PIN's in %s", 47u); storage[UINT32_C(0x0000CF8B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CF8C), "No constant %s in shader", 24u); storage[UINT32_C(0x0000CFA4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CFA8), "ID3DXConstantTable::SetValue failed. %s", 39u); storage[UINT32_C(0x0000CFCF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000CFD7), "`\373!\211?\000\000\000`\270\036\345?\000\000\000\200\231\231\311?\000\000\000\200\353Q\310?\000\000\000 \205\353\351?\303\365(?{\024\256>\000\000\300\277\000\000\300?", 53u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D00C), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\sphereclient\\dx9render\\..\\..\\Service\\Containers\\Sstr.h", 108u); storage[UINT32_C(0x0000D078)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D07C), "Unexpected pin combination for %s shader. %d %d %d %d", 53u); storage[UINT32_C(0x0000D0B1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D0B4), "pixel", 5u); storage[UINT32_C(0x0000D0B9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D0BC), ".psc", 4u); storage[UINT32_C(0x0000D0C0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D0C4), "gAlpha", 6u); storage[UINT32_C(0x0000D0CA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D0CC), "gWaterReflectCoefficient", 24u); storage[UINT32_C(0x0000D0E4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D0E8), "gWaterSpecular", 14u); storage[UINT32_C(0x0000D0F6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D0F8), "gWaterGradientCoefficient", 25u); storage[UINT32_C(0x0000D111)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D114), "gTexelCoordsDownFilter", 22u); storage[UINT32_C(0x0000D12A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D12C), "CShaderMgr::load_folder: duplicate shader code", 46u); storage[UINT32_C(0x0000D15A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D15C), "CShaderMgr::set_ps: unknown psg = %d", 36u); storage[UINT32_C(0x0000D180)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D184), "*.psc", 5u); storage[UINT32_C(0x0000D189)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D18C), "*.vsc", 5u); storage[UINT32_C(0x0000D191)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D196), "\377\377\000\000\000\000 deflate 1.1.3 Copyright 1995-1998 Jean-loup Gailly ", 58u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D1DC), "\300\364M\000\004\000\004\000\010\000\004\000\323\371M\000\004\000\005\000\020\000\010\000\323\371M\000\004\000\006\000 \000 \000\323\371M\000\004\000\004\000\020\000\020\000Y\002N\000\010\000\020\000 \000 \000Y\002N\000\010\000\020\000\200\000\200\000Y\002N\000\010\000 \000\200\000\000\001Y\002N\000 \000\200\000\002\001\000\004Y\002N\000 \000\002\001\002\001\000\020Y\002N\000\020\000\000\000\021\000\000\000\022\000\000\000\000\000\000\000\010\000\000\000\007\000\000\000\t\000\000\000\006\000\000\000\n\000\000\000\005\000\000\000\013\000\000\000\004\000\000\000\014\000\000\000\003\000\000\000\r\000\000\000\002\000\000\000\016\000\000\000\001\000\000\000\017", 185u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D2BC), "\001\000\000\000\001\000\000\000\001\000\000\000\001\000\000\000\002\000\000\000\002\000\000\000\002\000\000\000\002\000\000\000\003\000\000\000\003\000\000\000\003\000\000\000\003\000\000\000\004\000\000\000\004\000\000\000\004\000\000\000\004\000\000\000\005\000\000\000\005\000\000\000\005\000\000\000\005", 77u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D324), "\001\000\000\000\001\000\000\000\002\000\000\000\002\000\000\000\003\000\000\000\003\000\000\000\004\000\000\000\004\000\000\000\005\000\000\000\005\000\000\000\006\000\000\000\006\000\000\000\007\000\000\000\007\000\000\000\010\000\000\000\010\000\000\000\t\000\000\000\t\000\000\000\n\000\000\000\n\000\000\000\013\000\000\000\013\000\000\000\014\000\000\000\014\000\000\000\r\000\000\000\r", 101u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D3CC), "\002\000\000\000\003\000\000\000\007\000\000\000\000\000\000\000\020\021\022\000\010\007\t\006\n\005\013\004\014\003\r\002\016\001\017\000\000\000\000\000\014\000\010\000\214\000\010\000L\000\010\000\314\000\010\000,\000\010\000\254\000\010\000l\000\010\000\354\000\010\000\034\000\010\000\234\000\010\000\\\000\010\000\334\000\010\000<\000\010\000\274\000\010\000|\000\010\000\374\000\010\000\002\000\010\000\202\000\010\000B\000\010\000\302\000\010\000\"\000\010\000\242\000\010\000b\000\010\000\342\000\010\000\022\000\010\000\222\000\010\000R\000\010\000\322\000\010\0002\000\010\000\262\000\010\000r\000\010\000\362\000\010\000\n\000\010\000\212\000\010\000J\000\010\000\312\000\010\000*\000\010\000\252\000\010\000j\000\010\000\352\000\010\000\032\000\010\000\232\000\010\000Z\000\010\000\332\000\010\000:\000\010\000\272\000\010\000z\000\010\000\372\000\010\000\006\000\010\000\206\000\010\000F\000\010\000\306\000\010\000&\000\010\000\246\000\010", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D4CC), "f\000\010\000\346\000\010\000\026\000\010\000\226\000\010\000V\000\010\000\326\000\010\0006\000\010\000\266\000\010\000v\000\010\000\366\000\010\000\016\000\010\000\216\000\010\000N\000\010\000\316\000\010\000.\000\010\000\256\000\010\000n\000\010\000\356\000\010\000\036\000\010\000\236\000\010\000^\000\010\000\336\000\010\000>\000\010\000\276\000\010\000~\000\010\000\376\000\010\000\001\000\010\000\201\000\010\000A\000\010\000\301\000\010\000!\000\010\000\241\000\010\000a\000\010\000\341\000\010\000\021\000\010\000\221\000\010\000Q\000\010\000\321\000\010\0001\000\010\000\261\000\010\000q\000\010\000\361\000\010\000\t\000\010\000\211\000\010\000I\000\010\000\311\000\010\000)\000\010\000\251\000\010\000i\000\010\000\351\000\010\000\031\000\010\000\231\000\010\000Y\000\010\000\331\000\010\0009\000\010\000\271\000\010\000y\000\010\000\371\000\010\000\005\000\010\000\205\000\010\000E\000\010\000\305\000\010\000%\000\010\000\245\000\010", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D5CC), "e\000\010\000\345\000\010\000\025\000\010\000\225\000\010\000U\000\010\000\325\000\010\0005\000\010\000\265\000\010\000u\000\010\000\365\000\010\000\r\000\010\000\215\000\010\000M\000\010\000\315\000\010\000-\000\010\000\255\000\010\000m\000\010\000\355\000\010\000\035\000\010\000\235\000\010\000]\000\010\000\335\000\010\000=\000\010\000\275\000\010\000}\000\010\000\375\000\010\000\023\000\t\000\023\001\t\000\223\000\t\000\223\001\t\000S\000\t\000S\001\t\000\323\000\t\000\323\001\t\0003\000\t\0003\001\t\000\263\000\t\000\263\001\t\000s\000\t\000s\001\t\000\363\000\t\000\363\001\t\000\013\000\t\000\013\001\t\000\213\000\t\000\213\001\t\000K\000\t\000K\001\t\000\313\000\t\000\313\001\t\000+\000\t\000+\001\t\000\253\000\t\000\253\001\t\000k\000\t\000k\001\t\000\353\000\t\000\353\001\t\000\033\000\t\000\033\001\t\000\233\000\t\000\233\001\t\000[\000\t\000[\001\t", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D6CC), "\333\000\t\000\333\001\t\000;\000\t\000;\001\t\000\273\000\t\000\273\001\t\000{\000\t\000{\001\t\000\373\000\t\000\373\001\t\000\007\000\t\000\007\001\t\000\207\000\t\000\207\001\t\000G\000\t\000G\001\t\000\307\000\t\000\307\001\t\000'\000\t\000'\001\t\000\247\000\t\000\247\001\t\000g\000\t\000g\001\t\000\347\000\t\000\347\001\t\000\027\000\t\000\027\001\t\000\227\000\t\000\227\001\t\000W\000\t\000W\001\t\000\327\000\t\000\327\001\t\0007\000\t\0007\001\t\000\267\000\t\000\267\001\t\000w\000\t\000w\001\t\000\367\000\t\000\367\001\t\000\017\000\t\000\017\001\t\000\217\000\t\000\217\001\t\000O\000\t\000O\001\t\000\317\000\t\000\317\001\t\000/\000\t\000/\001\t\000\257\000\t\000\257\001\t\000o\000\t\000o\001\t\000\357\000\t\000\357\001\t\000\037\000\t\000\037\001\t\000\237\000\t\000\237\001\t\000_\000\t\000_\001\t", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D7CC), "\337\000\t\000\337\001\t\000?\000\t\000?\001\t\000\277\000\t\000\277\001\t\000\177\000\t\000\177\001\t\000\377\000\t\000\377\001\t\000\000\000\007\000@\000\007\000 \000\007\000`\000\007\000\020\000\007\000P\000\007\0000\000\007\000p\000\007\000\010\000\007\000H\000\007\000(\000\007\000h\000\007\000\030\000\007\000X\000\007\0008\000\007\000x\000\007\000\004\000\007\000D\000\007\000$\000\007\000d\000\007\000\024\000\007\000T\000\007\0004\000\007\000t\000\007\000\003\000\010\000\203\000\010\000C\000\010\000\303\000\010\000#\000\010\000\243\000\010\000c\000\010\000\343\000\010\000\000\000\005\000\020\000\005\000\010\000\005\000\030\000\005\000\004\000\005\000\024\000\005\000\014\000\005\000\034\000\005\000\002\000\005\000\022\000\005\000\n\000\005\000\032\000\005\000\006\000\005\000\026\000\005\000\016\000\005\000\036\000\005\000\001\000\005\000\021\000\005\000\t\000\005\000\031\000\005\000\005\000\005\000\025\000\005", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D8CC), "\r\000\005\000\035\000\005\000\003\000\005\000\023\000\005\000\013\000\005\000\033\000\005\000\007\000\005\000\027\000\005\000\000\001\002\003\004\004\005\005\006\006\006\006\007\007\007\007\010\010\010\010\010\010\010\010\t\t\t\t\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\013\013\013\013\013\013\013\013\013\013\013\013\013\013\013\013\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\014\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\016\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000D9CC), "\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017\000\000\020\021\022\022\023\023\024\024\024\024\025\025\025\025\026\026\026\026\026\026\026\026\027\027\027\027\027\027\027\027\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\034\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DACC), "\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\035\000\001\002\003\004\005\006\007\010\010\t\t\n\n\013\013\014\014\014\014\r\r\r\r\016\016\016\016\017\017\017\017\020\020\020\020\020\020\020\020\021\021\021\021\021\021\021\021\022\022\022\022\022\022\022\022\023\023\023\023\023\023\023\023\024\024\024\024\024\024\024\024\024\024\024\024\024\024\024\024\025\025\025\025\025\025\025\025\025\025\025\025\025\025\025\025\026\026\026\026\026\026\026\026\026\026\026\026\026\026\026\026\027\027\027\027\027\027\027\027\027\027\027\027\027\027\027\027\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\030\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\031\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032\032", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DBCC), "\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\033\034\000\000\000\000\001\000\000\000\002\000\000\000\003\000\000\000\004\000\000\000\005\000\000\000\006\000\000\000\007\000\000\000\010\000\000\000\n\000\000\000\014\000\000\000\016\000\000\000\020\000\000\000\024\000\000\000\030\000\000\000\034\000\000\000 \000\000\000(\000\000\0000\000\000\0008\000\000\000@\000\000\000P\000\000\000`\000\000\000p\000\000\000\200\000\000\000\240\000\000\000\300\000\000\000\340", 141u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DC68), "\001\000\000\000\002\000\000\000\003\000\000\000\004\000\000\000\006\000\000\000\010\000\000\000\014\000\000\000\020\000\000\000\030\000\000\000 \000\000\0000\000\000\000@\000\000\000`\000\000\000\200\000\000\000\300\000\000\000\000\001\000\000\200\001\000\000\000\002\000\000\000\003\000\000\000\004\000\000\000\006\000\000\000\010\000\000\000\014\000\000\000\020\000\000\000\030\000\000\000 \000\000\0000\000\000\000@\000\000\000`\000\000 inflate 1.1.3 Copyright 1995-1998 Mark Adler \000\000\003\000\000\000\004\000\000\000\005\000\000\000\006\000\000\000\007\000\000\000\010\000\000\000\t\000\000\000\n\000\000\000\013\000\000\000\r\000\000\000\017\000\000\000\021\000\000\000\023\000\000\000\027\000\000\000\033\000\000\000\037\000\000\000#\000\000\000+\000\000\0003\000\000\000;\000\000\000C\000\000\000S\000\000\000c", 253u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DD68), "s\000\000\000\203\000\000\000\243\000\000\000\303\000\000\000\343\000\000\000\002\001", 22u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DDAC), "\001\000\000\000\001\000\000\000\001\000\000\000\001\000\000\000\002\000\000\000\002\000\000\000\002\000\000\000\002\000\000\000\003\000\000\000\003\000\000\000\003\000\000\000\003\000\000\000\004\000\000\000\004\000\000\000\004\000\000\000\004\000\000\000\005\000\000\000\005\000\000\000\005\000\000\000\005\000\000\000\000\000\000\000p\000\000\000p\000\000\000\000\000\000\000\001\000\000\000\002\000\000\000\003\000\000\000\004\000\000\000\005\000\000\000\007\000\000\000\t\000\000\000\r\000\000\000\021\000\000\000\031\000\000\000!\000\000\0001\000\000\000A\000\000\000a\000\000\000\201\000\000\000\301\000\000\000\001\001\000\000\201\001\000\000\001\002\000\000\001\003\000\000\001\004\000\000\001\006\000\000\001\010\000\000\001\014\000\000\001\020\000\000\001\030\000\000\001 \000\000\0010\000\000\001@\000\000\001`", 214u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DE94), "\001\000\000\000\001\000\000\000\002\000\000\000\002\000\000\000\003\000\000\000\003\000\000\000\004\000\000\000\004\000\000\000\005\000\000\000\005\000\000\000\006\000\000\000\006\000\000\000\007\000\000\000\007\000\000\000\010\000\000\000\010\000\000\000\t\000\000\000\t\000\000\000\n\000\000\000\n\000\000\000\013\000\000\000\013\000\000\000\014\000\000\000\014\000\000\000\r\000\000\000\r\000\000\000\026", 105u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DF08), "\026", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DF14), "\026", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DF20), "\027\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DF2C), "\027\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DF38), "\024", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DF44), "\024", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DF50), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DF5C), "\030", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DF68), "\030", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DF74), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DF80), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DF8C), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DF98), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DFA4), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DFB0), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DFBC), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DFC8), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DFD4), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DFE0), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DFEC), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000DFF8), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E004), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E010), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E01C), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E028), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E034), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E040), "\024\025", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E04C), "\024\025", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E058), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E064), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E070), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E07C), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E088), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E094), "\030\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E0A0), "\030\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E0AC), "\030\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E0B8), "\030\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E0C4), "\025", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E0D0), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E0DC), "\024", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E0E8), "\030\000\000\000\020\000\000\000\002\000\000\000\020\000\000\000\007\000\000\000\250CR\000\000\000\000\000\026", 29u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E110), "\026", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E11C), "\026", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E128), "\027\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E134), "\027\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E140), "\024", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E14C), "\024", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E158), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E164), "\030", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E170), "\030", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E17C), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E188), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E194), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E1A0), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E1AC), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E1B8), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E1C4), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E1D0), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E1DC), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E1E8), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E1F4), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E200), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E20C), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E218), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E224), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E230), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E23C), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E248), "\024\025", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E254), "\024\025", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E260), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E26C), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E278), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E284), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E290), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E29C), "\030\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E2A8), "\030\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E2B4), "\030\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E2C0), "\030\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E2CC), "\025", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E2D8), "\025\024", 2u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E2E4), "\024", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E2F0), "\030\000\000\000\020\000\000\000\002\000\000\000\000\001\000\000\000\001\000\000\030DR\000\240{\376\353\215b\322\021\256\017\000`\227\260\024\021\315\332\002Q\033$\323\021\256\247\000`\227\260\024\021\306\035?t\272Z\237B\213\337\305M\003%=\302\0003x\203c@\212L\235\263\202\203\n\177\3531#\225J\223\312\243\305K\255\240\326\331]\227\224!a+\035o\240\325\317\021\277\307DEST\000\000`+\035o\240\325\317\021\277\307DEST\000\000 \202rU<\323\317\021\277\307DEST\000\000\342\002m\243\363\311\317\021\277\307DEST\000\000\341\002m\243\363\311\317\021\277\307DEST\000\000\340\002m\243\363\311\317\021\277\307DEST", 198u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E3B8), "0\200y\277:H\242M\252\231]d\3556\227", 15u); storage[UINT32_C(0x0000E3C7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E3C8), "MS_E_SOURCEALREADYDEFINED", 25u); storage[UINT32_C(0x0000E3E1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E3E4), "DIERR_DRIVERFIRST+5", 19u); storage[UINT32_C(0x0000E3F7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E3F8), "DIERR_DRIVERFIRST+4", 19u); storage[UINT32_C(0x0000E40B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E40C), "DIERR_DRIVERFIRST+3", 19u); storage[UINT32_C(0x0000E41F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E420), "DIERR_DRIVERFIRST+2", 19u); storage[UINT32_C(0x0000E433)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E434), "DIERR_DRIVERFIRST+1", 19u); storage[UINT32_C(0x0000E447)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E44C), "Although the audio output from the port will be routed to the same device as the given DirectSound buffer, buffer controls such as pan and volume will not affect the output.", 173u); storage[UINT32_C(0x0000E4F9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E4FC), "The requested operation was not performed because during CollectGarbage the loader determined that the object had been released.", 128u); storage[UINT32_C(0x0000E57C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E584), "The target window or output has been occluded. The application should suspend rendering operations if possible.", 111u); storage[UINT32_C(0x0000E5F3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E5F4), "n/a", 3u); storage[UINT32_C(0x0000E5F7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E5FC), "Returned from IDirectMusicPerformance::MIDIToMusic(),  and IDirectMusicPerformance::MusicToMIDI(), this indicates  that the note conversion generated a note value that is above 127, so it has been bumped down one or more octaves to be in the proper MIDI range of 0 through 127.  Note that this is valid for MIDIToMusic() when using play modes DMUS_PLAYMODE_FIXEDTOCHORD and DMUS_PLAYMODE_FIXEDTOKEY, both of which store MIDI values in wMusicValue. With MusicToMIDI(), it is valid for all play modes. Ofcourse, DMUS_PLAYMODE_FIXED will never return this success code.", 566u); storage[UINT32_C(0x0000E832)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E834), "Returned string has been truncated to fit the buffer size.", 58u); storage[UINT32_C(0x0000E86E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E874), "Returned from IDirectMusicGraph::StampPMsg(), this indicates that the PMsg is already stamped with the last tool in the graph. The returned PMsg's tool pointer is now NULL.", 172u); storage[UINT32_C(0x0000E920)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000E924), "Returned from IDirectMusicPerformance::MusicToMIDI(), this indicates  that no note has been calculated because the music value has the note  at a position higher than the top note of the chord. This applies only to DMUS_PLAYMODE_NORMALCHORD play mode. This success code indicates that the caller should not do anything with the note. It is not meant to be played against this chord.", 382u); storage[UINT32_C(0x0000EAA2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000EAA4), "Returned from IDirectMusicPerformance::MIDIToMusic(),  and IDirectMusicPerformance::MusicToMIDI(), this indicates  that the note conversion generated a note value that is below 0,  so it has been bumped up one or more octaves to be in the proper MIDI range of 0 through 127.  Note that this is valid for MIDIToMusic() when using play modes DMUS_PLAYMODE_FIXEDTOCHORD and DMUS_PLAYMODE_FIXEDTOKEY, both of which store MIDI values in wMusicValue. With MusicToMIDI(), it is valid for all play modes. Ofcourse, DMUS_PLAYMODE_FIXED will never return this success code.", 563u); storage[UINT32_C(0x0000ECD7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000ECDC), "Return value from IDirectMusicTrack::Play() which indicates to the segment that the track has no more data after mtEnd.", 119u); storage[UINT32_C(0x0000ED53)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000ED54), "The object could only load partially. This can happen if some components are not registered properly, such as embedded tracks and tools. This can also happen if some content is missing. For example, if a segment uses a DLS collection that is not in the loader's current search directory.", 287u); storage[UINT32_C(0x0000EE73)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000EE74), "Return value from IDirectMusicBand::Download() which indicates that some of the instruments safely downloaded, but others failed. This usually occurs when some instruments are on PChannels not supported by the performance or port.", 230u); storage[UINT32_C(0x0000EF5A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000EF5C), "Return value from IDirectMusicTool::ProcessPMsg() which indicates to the performance that it should cue the PMsg again automatically.", 133u); storage[UINT32_C(0x0000EFE1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000EFE4), "Return value from IDirectMusicTool::ProcessPMsg() which indicates to the performance that it should free the PMsg automatically.", 128u); storage[UINT32_C(0x0000F064)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F068), "The call succeeded, but we had to substitute the 3D algorithm", 61u); storage[UINT32_C(0x0000F0A5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F0A8), "Full duplex", 11u); storage[UINT32_C(0x0000F0B3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F0B4), "Half duplex", 11u); storage[UINT32_C(0x0000F0BF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F0C0), "Pending", 7u); storage[UINT32_C(0x0000F0C7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F0C8), "The call succeeded but there won't be any mipmaps generated", 59u); storage[UINT32_C(0x0000F103)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F104), "The seek into the movie was not frame accurate.", 47u); storage[UINT32_C(0x0000F133)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F134), "The stop time for the sample was not set.", 41u); storage[UINT32_C(0x0000F15D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F164), "There was no preview pin available, so the capture pin output is being split to provide both capture and preview.", 113u); storage[UINT32_C(0x0000F1D5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F1DC), "The current title was not a sequential set of chapters (PGC), and the returned timing information might not be continuous.", 122u); storage[UINT32_C(0x0000F256)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F25C), "The audio stream did not contain sufficient information to determine the contents of each channel.", 98u); storage[UINT32_C(0x0000F2BE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F2C0), "The graph can't be cued because of lack of or corrupt data.", 59u); storage[UINT32_C(0x0000F2FB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F2FC), "Cannot play back the video stream: format 'RPZA' is not supported.", 66u); storage[UINT32_C(0x0000F33E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F344), "The value returned had to be estimated.  It's accuracy can not be guaranteed.", 77u); storage[UINT32_C(0x0000F391)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F394), "This success code is reserved for internal purposes within ActiveMovie.", 71u); storage[UINT32_C(0x0000F3DB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F3DC), "The stream has been turned off.", 31u); storage[UINT32_C(0x0000F3FB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F3FC), "Cannot play back the audio stream: no audio hardware is available.", 66u); storage[UINT32_C(0x0000F43E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F440), "Some connections have failed and have been deferred.", 52u); storage[UINT32_C(0x0000F474)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F478), "The resource specified is no longer needed.", 43u); storage[UINT32_C(0x0000F4A3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F4A4), "A connection could not be made with the media type in the persistent graph, but has been made with a negotiated media type.", 123u); storage[UINT32_C(0x0000F51F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F524), "Cannot play back the video stream: no suitable decompressor could be found.", 75u); storage[UINT32_C(0x0000F56F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F570), "The file contained some property settings that were not used.", 61u); storage[UINT32_C(0x0000F5AD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F5B0), "The end of the list has been reached.", 37u); storage[UINT32_C(0x0000F5D5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F5DC), "An attempt to add a filter with a duplicate name succeeded with a modified name.", 80u); storage[UINT32_C(0x0000F62C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F630), "The state transition has not completed.", 39u); storage[UINT32_C(0x0000F657)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F65C), "Some of the streams in this movie are in an unsupported format.", 63u); storage[UINT32_C(0x0000F69B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F69C), "End of stream. Sample not updated.", 34u); storage[UINT32_C(0x0000F6BE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F6C0), "The system cannot find the drive specified.", 43u); storage[UINT32_C(0x0000F6EB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F6EC), "The environment is incorrect.", 29u); storage[UINT32_C(0x0000F709)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F70C), "The storage control block address is invalid.", 45u); storage[UINT32_C(0x0000F739)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F73C), "Not enough storage is available to process this command.", 56u); storage[UINT32_C(0x0000F774)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F778), "The handle is invalid.", 22u); storage[UINT32_C(0x0000F78E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F790), "Access is denied.", 17u); storage[UINT32_C(0x0000F7A1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F7A4), "The system cannot open the file.", 32u); storage[UINT32_C(0x0000F7C4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F7C8), "The system cannot find the path specified.", 42u); storage[UINT32_C(0x0000F7F2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F7F4), "The system cannot find the file specified.", 42u); storage[UINT32_C(0x0000F81E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F820), "Call successful, but returned FALSE", 35u); storage[UINT32_C(0x0000F843)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F844), "The function completed successfully", 35u); storage[UINT32_C(0x0000F867)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F868), "No suitable match found", 23u); storage[UINT32_C(0x0000F87F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F880), "The file format is invalid", 26u); storage[UINT32_C(0x0000F89A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F89C), "D3DX only supports color depths of 16 bit or greater", 52u); storage[UINT32_C(0x0000F8D0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F8D4), "An error occured while enumerating surface formats", 50u); storage[UINT32_C(0x0000F906)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F908), "The surface is not paletted", 27u); storage[UINT32_C(0x0000F923)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F924), "There is no such miplevel for this surface", 42u); storage[UINT32_C(0x0000F94E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F950), "There is no surface backing up this texture", 43u); storage[UINT32_C(0x0000F97B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F97C), "Could not bitBlt", 16u); storage[UINT32_C(0x0000F98C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F990), "Could not get device context", 28u); storage[UINT32_C(0x0000F9AC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F9B0), "The app is using the primary in full-screen mode", 48u); storage[UINT32_C(0x0000F9E0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000F9E4), "Front buffer already exists", 27u); storage[UINT32_C(0x0000F9FF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FA00), "Resize does not work for non-windowed contexts", 46u); storage[UINT32_C(0x0000FA2E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FA30), "Resize does not work for full-screen", 36u); storage[UINT32_C(0x0000FA54)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FA58), "Could not obtain device caps", 28u); storage[UINT32_C(0x0000FA74)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FA78), "The image file loading library error", 36u); storage[UINT32_C(0x0000FA9C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FAA0), "The image file format is unrecognized", 37u); storage[UINT32_C(0x0000FAC5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FAC8), "The requested device capabilities are not supported", 51u); storage[UINT32_C(0x0000FAFB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FAFC), "Bad D3DX context", 16u); storage[UINT32_C(0x0000FB0C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FB10), "Failed to render text to the surface", 36u); storage[UINT32_C(0x0000FB34)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FB38), "D3DX is not initialized yet", 27u); storage[UINT32_C(0x0000FB53)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FB54), "D3DXInitialize() must be called first", 37u); storage[UINT32_C(0x0000FB79)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FB7C), "D3DX failed to start up", 23u); storage[UINT32_C(0x0000FB93)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FB94), "D3DX failed to initialize itself", 32u); storage[UINT32_C(0x0000FBB4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FBB8), "One or more of the parameters passed is invalid", 47u); storage[UINT32_C(0x0000FBE7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FBE8), "Display mode is not valid", 25u); storage[UINT32_C(0x0000FC01)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FC04), "Could not create Z buffer", 25u); storage[UINT32_C(0x0000FC1D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FC20), "Failed to update caps database after changing display mode", 58u); storage[UINT32_C(0x0000FC5A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FC5C), "Backbuffer has not been created", 31u); storage[UINT32_C(0x0000FC7B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FC7C), "Direct3D has not been created", 29u); storage[UINT32_C(0x0000FC99)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FC9C), "Direct3D device has not been created", 36u); storage[UINT32_C(0x0000FCC0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FCC4), "Primary surface has not been created", 36u); storage[UINT32_C(0x0000FCE8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FCEC), "Z buffer has not been created", 29u); storage[UINT32_C(0x0000FD09)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FD0C), "DirectDraw has not been created", 31u); storage[UINT32_C(0x0000FD2B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FD2C), "Missing a DSP parameter.", 24u); storage[UINT32_C(0x0000FD44)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FD48), "Out of memory", 13u); storage[UINT32_C(0x0000FD55)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FD58), "A NULL pointer was passed as a parameter", 40u); storage[UINT32_C(0x0000FD80)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FD84), "The Device Index passed in is invalid", 37u); storage[UINT32_C(0x0000FDA9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FDAC), "Unknown command.", 16u); storage[UINT32_C(0x0000FDBC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FDC0), "Error writing a file during auditioning.", 40u); storage[UINT32_C(0x0000FDE8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FDEC), "Missing a soundbank.", 20u); storage[UINT32_C(0x0000FE00)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FE04), "Missing an RPC curve.", 21u); storage[UINT32_C(0x0000FE19)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FE1C), "Missing data for an audition command.", 37u); storage[UINT32_C(0x0000FE41)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FE44), "The wavebank is not prepared.", 29u); storage[UINT32_C(0x0000FE61)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FE64), "Invalid call of method of function from callback.", 49u); storage[UINT32_C(0x0000FE95)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FE98), "No wavebank exists for desired operation.", 41u); storage[UINT32_C(0x0000FEC1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FEC4), "Unable to select a variation.", 29u); storage[UINT32_C(0x0000FEE1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FEE4), "There can be only one audition engine.", 38u); storage[UINT32_C(0x0000FF0A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FF0C), "Unknown event type.", 19u); storage[UINT32_C(0x0000FF1F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FF20), "Error reading a file.", 21u); storage[UINT32_C(0x0000FF35)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FF38), "Invalid sound offset or index.", 30u); storage[UINT32_C(0x0000FF56)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FF58), "Invalid track index.", 20u); storage[UINT32_C(0x0000FF6C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FF70), "Invalid wave index.", 19u); storage[UINT32_C(0x0000FF83)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FF84), "Invalid cue index.", 18u); storage[UINT32_C(0x0000FF96)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FF98), "Invalid category.", 17u); storage[UINT32_C(0x0000FFA9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FFAC), "Invalid variable index.", 23u); storage[UINT32_C(0x0000FFC3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FFC4), "Global Settings not loaded.", 27u); storage[UINT32_C(0x0000FFDF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000FFE0), "Fail to play due to instance limit.", 35u); storage[UINT32_C(0x00010003)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010004), "Invalid data.", 13u); storage[UINT32_C(0x00010011)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010014), "The engine has expired (demo or pre-release version).", 53u); storage[UINT32_C(0x00010049)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001004C), "No notification callback.", 25u); storage[UINT32_C(0x00010065)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010068), "Notification already registered.", 32u); storage[UINT32_C(0x00010088)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001008C), "Invalid usage.", 14u); storage[UINT32_C(0x0001009A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001009C), "The engine has not been initialized.", 36u); storage[UINT32_C(0x000100C0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000100C4), "Was still drawing.", 18u); storage[UINT32_C(0x000100D6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000100D8), "An internal driver error occurred.", 34u); storage[UINT32_C(0x000100FA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000100FC), "The application attempted to perform an operation on an DXGI output that is only legal after the output has been claimed for exclusive owenership.", 146u); storage[UINT32_C(0x0001018E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010190), "The engine is already initialized.", 34u); storage[UINT32_C(0x000101B2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000101B4), "Device reset.", 13u); storage[UINT32_C(0x000101C1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000101C4), "The application has made an erroneous API call that it had enough information to avoid. This error is intended to denote that the application should be altered to avoid the error. Use of the debug version of the DXGI.DLL will provide run-time debug output with further information.", 281u); storage[UINT32_C(0x000102DD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000102E4), "The item requested was not found. For GetPrivateData calls, this means that the specified GUID had not been previously associated with the object.", 146u); storage[UINT32_C(0x00010376)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001037C), "The specified size of the destination buffer is too small to hold the requested data.", 85u); storage[UINT32_C(0x000103D1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000103D4), "Unsupported.", 12u); storage[UINT32_C(0x000103E0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000103E4), "Device removed.", 15u); storage[UINT32_C(0x000103F3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000103F4), "Device hung.", 12u); storage[UINT32_C(0x00010400)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010404), "There are too many unique state objects.", 40u); storage[UINT32_C(0x0001042C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010430), "The file does not contain a valid container object.", 51u); storage[UINT32_C(0x00010463)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010464), "Attempt was made to create an audiopath that sends to a global effects buffer which did not exist.", 98u); storage[UINT32_C(0x000104C6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000104C8), "Invalid data was found in a RIFF file chunk.", 44u); storage[UINT32_C(0x000104F4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000104FC), "Attempt was made to play segment in audiopath mode and there was no audiopath.", 78u); storage[UINT32_C(0x0001054A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001054C), "An audiopath could not be used for playback because it lacked port assignments.", 79u); storage[UINT32_C(0x0001059B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001059C), "An audiopath failed to create because a requested buffer could not be created.", 78u); storage[UINT32_C(0x000105EA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000105EC), "An audiopath is inactive, perhaps because closedown was called.", 63u); storage[UINT32_C(0x0001062B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001062C), "A segment or song was asked for its embedded audio path configuration, but there isn't any. ", 92u); storage[UINT32_C(0x00010688)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001068C), "This is the inverse of the previous error. The Performance has set up some audio paths, which makes is incompatible with the calls to allocate pchannels, etc. ", 159u); storage[UINT32_C(0x0001072B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001072C), "The Performance has set up some PChannels using the AssignPChannel command, which makes it not capable of supporting audio paths.", 129u); storage[UINT32_C(0x000107AD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000107B4), "A script routine written in AudioVBScript failed because a function outside of a script failed to complete. For example, a call to PlaySegment that fails to play because of low memory would return this error.", 208u); storage[UINT32_C(0x00010884)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001088C), "A script routine written in AudioVBScript failed because an invalid operation occurred.  For example, adding the number 3 to a segment object would produce this error.  So would attempting to call a routine that doesn't exist.", 226u); storage[UINT32_C(0x0001096E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010974), "A script written in AudioVBScript could not be read because it contained a statement that is not allowed by the AudioVBScript language.", 135u); storage[UINT32_C(0x000109FB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000109FC), "The file contains an invalid parameter control track.", 53u); storage[UINT32_C(0x00010A31)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010A34), "The file contains an invalid lyrics track.", 42u); storage[UINT32_C(0x00010A5E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010A60), "The file contains an invalid segment trigger track.", 51u); storage[UINT32_C(0x00010A93)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010A94), "Attempt was made to set a script's variable by value to an object that does not support a default value property.", 113u); storage[UINT32_C(0x00010B05)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010B0C), "Attempt was made to set a script's variable by reference to a value that was not an object type.", 96u); storage[UINT32_C(0x00010B6C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010B74), "Scripts variables for content referenced or embedded in a script cannot be set.", 79u); storage[UINT32_C(0x00010BC3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010BC4), "The script does not contain a routine with the specified name.", 62u); storage[UINT32_C(0x00010C02)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010C04), "The script does not contain a variable with the specified name.", 63u); storage[UINT32_C(0x00010C43)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010C44), "The file contains an invalid script track.", 42u); storage[UINT32_C(0x00010C6E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010C70), "The script file is invalid.", 27u); storage[UINT32_C(0x00010C8B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010C8C), "An error occured while parsing a script loaded using LoadScript.  The script that was loaded contains an error.", 111u); storage[UINT32_C(0x00010CFB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010CFC), "Loading of oleaut32.dll failed.  VBScript and other activeX scripting languages require use of oleaut32.dll.  On platforms where oleaut32.dll is not present, only the DirectMusicScript language, which doesn't require oleaut32.dll can be used.", 242u); storage[UINT32_C(0x00010DEE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010DF4), "An error was encountered while parsing or executing the script. The pErrorInfo parameter (if supplied) was filled with information about the error.", 147u); storage[UINT32_C(0x00010E87)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010E8C), "A varient was used that had a type that is not supported by DirectMusic.", 72u); storage[UINT32_C(0x00010ED4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010EDC), "The activeX scripting engine for the script's language is not compatible with DirectMusic.", 90u); storage[UINT32_C(0x00010F36)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010F3C), "An attempt to use this object failed because it first needs to be loaded.", 73u); storage[UINT32_C(0x00010F85)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010F8C), "DMUS_E_DESCEND_CHUNK_FAIL is returned when the end of the file  was reached before the desired chunk was found.", 111u); storage[UINT32_C(0x00010FFB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00010FFC), "A call to MIDIToMusic() or MusicToMIDI() resulted in an error because the requested conversion could not happen. This usually occurs when the provided DMUS_CHORD_KEY structure has an invalid chord or scale pattern.", 214u); storage[UINT32_C(0x000110D2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000110D4), "The default system port could not be opened.", 44u); storage[UINT32_C(0x00011100)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011104), "The DMUS_PMSG was either not allocated by the performance via IDirectMusicPerformance::AllocPMsg(), or it was already freed via IDirectMusicPerformance::FreePMsg().", 164u); storage[UINT32_C(0x000111A8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000111AC), "The file requested is not a valid file.", 39u); storage[UINT32_C(0x000111D3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000111D4), "The tool is already contained in the graph. Create a new instance.", 66u); storage[UINT32_C(0x00011216)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001121C), "Value is out of range, for instance the requested length is longer than the segment.", 84u); storage[UINT32_C(0x00011270)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011274), "Segment initialization failed, most likely due to a critical memory situation.", 78u); storage[UINT32_C(0x000112C2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000112C4), "The DMUS_PMSG has already been sent to the performance object via IDirectMusicPerformance::SendPMsg().", 102u); storage[UINT32_C(0x0001132A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001132C), "The file name is missing from the DMUS_OBJECTDESC.", 50u); storage[UINT32_C(0x0001135E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011364), "The class id field is required and missing in the DMUS_OBJECTDESC.", 66u); storage[UINT32_C(0x000113A6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000113A8), "The requested file path is invalid.", 35u); storage[UINT32_C(0x000113CB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000113CC), "File open failed - either file doesn't exist or is locked.", 58u); storage[UINT32_C(0x00011406)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011408), "Search data type is not supported.", 34u); storage[UINT32_C(0x0001142A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001142C), "Unable to find or create object.", 32u); storage[UINT32_C(0x0001144C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011450), "Object was not found.", 21u); storage[UINT32_C(0x00011465)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001146C), "There is no master clock in the performance. Be sure to call IDirectMusicPerformance::Init().", 93u); storage[UINT32_C(0x000114C9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000114CC), "The track does not support clock time playback or getparam.", 59u); storage[UINT32_C(0x00011507)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011508), "The requested track is not contained by the segment.", 52u); storage[UINT32_C(0x0001153C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011540), "The time is in the past, and the operation can not succeed.", 59u); storage[UINT32_C(0x0001157B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001157C), "The requested parameter type is not supported on the object.", 60u); storage[UINT32_C(0x000115B8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000115BC), "The requested parameter type is currently disabled. Parameter types may be enabled and disabled by certain calls to SetParam().", 127u); storage[UINT32_C(0x0001163B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001163C), "A required object is not initialized or failed to initialize.", 61u); storage[UINT32_C(0x00011679)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001167C), "The segment object was unable to load all tracks from the IStream* object data. This may be due to errors in the stream, or the tracks being incorrectly registered on the client.", 178u); storage[UINT32_C(0x0001172E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011734), "The graph object was unable to load all tools from the IStream* object data. This may be due to errors in the stream, or the tools being incorrectly registered on the client.", 174u); storage[UINT32_C(0x000117E2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000117E4), "The IStream* object's data contains an invalid tool header (ckid is 0 and fccType is NULL,) and therefore can not be read by the graph object.", 142u); storage[UINT32_C(0x00011872)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011874), "The IStream* object's data contains an invalid track header (ckid is 0 and fccType is NULL,) and therefore can not be read by the segment object.", 145u); storage[UINT32_C(0x00011905)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001190C), "The IStream* object's data does not have a tool header as the first chunk, and therefore can not be read by the graph object.", 125u); storage[UINT32_C(0x00011989)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001198C), "The IStream* object's data does not have a track header as the first chunk, and therefore can not be read by the segment object.", 128u); storage[UINT32_C(0x00011A0C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011A10), "The file does not contain a valid band.", 39u); storage[UINT32_C(0x00011A37)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011A38), "The object has already been initialized.", 40u); storage[UINT32_C(0x00011A60)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011A64), "The IStream* object does not contain data supported by the loading object.", 74u); storage[UINT32_C(0x00011AAE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011AB4), "The given event is invalid (either it is not a valid MIDI message or it makes use of running status). The event cannot be packed into the buffer.", 145u); storage[UINT32_C(0x00011B45)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011B4C), "IDirectMusic::SetDirectSound has already been called. It may not be changed while in use.", 89u); storage[UINT32_C(0x00011BA5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011BAC), "The operation cannot be carried out while the synthesizer is inactive.", 70u); storage[UINT32_C(0x00011BF2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011BF4), "Invalid buffer format was handed to the synth sink.", 51u); storage[UINT32_C(0x00011C27)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011C28), "Invalid DirectSound buffer was handed to port. ", 47u); storage[UINT32_C(0x00011C57)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011C58), "The operation cannot be carried out while the port is active.", 61u); storage[UINT32_C(0x00011C95)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011C9C), "The port could not be created because no DirectSound has been specified. Specify a DirectSound interface via the IDirectMusic::SetDirectSound method; pass NULL to have DirectMusic manage usage of DirectSound.", 208u); storage[UINT32_C(0x00011D6C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011D74), "The given operation could not be carried out because the port is a render port.", 79u); storage[UINT32_C(0x00011DC3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011DC4), "The given operation could not be carried out because the port is a capture port.", 80u); storage[UINT32_C(0x00011E14)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011E1C), "The object requested was not found (numerically equal to DMUS_E_NOT_FOUND)", 74u); storage[UINT32_C(0x00011E66)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011E6C), "There is insufficient space to insert the given event into the buffer.", 70u); storage[UINT32_C(0x00011EB2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011EB4), "There was no data in the referenced buffer.", 43u); storage[UINT32_C(0x00011EDF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011EE4), "The operation cannot be performed because the final instance of the DirectMusic object was released. Ports cannot be used after final  release of the DirectMusic object.", 169u); storage[UINT32_C(0x00011F8D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011F94), "An error occurred while attempting to read from the IStream* object.", 68u); storage[UINT32_C(0x00011FD8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00011FDC), "The operation cannot be carried out while the synthesizer is active.", 68u); storage[UINT32_C(0x00012020)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012024), "The operation could not be completed because the software synth has not  yet been fully configured.", 99u); storage[UINT32_C(0x00012087)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001208C), "An attempt was made to close the software synthesizer while it was already  open.", 81u); storage[UINT32_C(0x000120DD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000120E4), "An attempt was made to open the software synthesizer while it was already  open.", 80u); storage[UINT32_C(0x00012134)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001213C), "The operation could not be completed because no sink was connected to the synthesizer.", 86u); storage[UINT32_C(0x00012192)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012194), "Attempted to download unknown data type.", 40u); storage[UINT32_C(0x000121BC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000121C0), "Offset Table for download buffer has errors. ", 45u); storage[UINT32_C(0x000121ED)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000121F0), "Bad wave chunk in DLS collection", 32u); storage[UINT32_C(0x00012210)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012214), "Downoaded DLS wave is not in PCM format. ", 41u); storage[UINT32_C(0x0001223D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012240), "Articulation missing from instrument in DLS collection.", 55u); storage[UINT32_C(0x00012277)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012278), "Wavelink chunk in DLS collection points to invalid wave.", 56u); storage[UINT32_C(0x000122B0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000122B4), "Invalid instrument chunk in DLS collection.", 43u); storage[UINT32_C(0x000122DF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000122E0), "Invalid articulation chunk in DLS collection.", 45u); storage[UINT32_C(0x0001230D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012314), "Wave chunk has more than one interleaved channel. DLS format requires MONO.", 75u); storage[UINT32_C(0x0001235F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012364), "* The specified property item may not be retrieved from the target object.", 74u); storage[UINT32_C(0x000123AE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000123B4), "The specified property item may not be set on the target object.", 64u); storage[UINT32_C(0x000123F4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000123FC), "The specified property item was not recognized by the target object.", 68u); storage[UINT32_C(0x00012440)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012444), "Buffer was already downloaded to synth.", 39u); storage[UINT32_C(0x0001246B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001246C), "Tried to unload an object that was not downloaded or previously unloaded.", 73u); storage[UINT32_C(0x000124B5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000124BC), "Invalid download id was used in the process of creating a download buffer.", 74u); storage[UINT32_C(0x00012506)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001250C), "The RIFF parser doesn't contain a required chunk while parsing file.", 68u); storage[UINT32_C(0x00012550)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012554), "The IStream* doesn't support Write().", 37u); storage[UINT32_C(0x00012579)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001257C), "The IStream* doesn't support Seek().", 36u); storage[UINT32_C(0x000125A0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000125A4), "There is no instrument in the collection that matches patch number.", 67u); storage[UINT32_C(0x000125E7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000125EC), "Error reading wave data from DLS collection. Indicates bad file.", 64u); storage[UINT32_C(0x0001262C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012634), "Second attempt to load a DLS collection that is currently open. ", 64u); storage[UINT32_C(0x00012674)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012678), "Wave chunks in DLS collection file are at incorrect offsets.", 60u); storage[UINT32_C(0x000126B4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000126B8), "Buffer is not large enough for requested operation.", 51u); storage[UINT32_C(0x000126EB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000126EC), "No buffer was prepared for the download data.", 45u); storage[UINT32_C(0x00012719)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001271C), "Download failed due to inability to access or create download buffer.", 69u); storage[UINT32_C(0x00012761)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012764), "Error parsing DLS collection. File is corrupt.", 46u); storage[UINT32_C(0x00012792)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012794), "The requested device is already in use (possibly by a non-DirectMusic client) and cannot be opened again.", 105u); storage[UINT32_C(0x000127FD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012800), "A circular loop of send effects was detected", 44u); storage[UINT32_C(0x0001282C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012834), "The GUID specified in an audiopath file does not match a valid MIXIN buffer", 75u); storage[UINT32_C(0x0001287F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012884), "An unexpected error was returned from a device driver, indicating possible failure of the driver or hardware.", 109u); storage[UINT32_C(0x000128F1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000128F4), "The requested operation cannot be performed while there are  instantiated ports in any process in the system.", 109u); storage[UINT32_C(0x00012961)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012964), "Attempt to use DirectSound 8 functionality on an older DirectSound object", 73u); storage[UINT32_C(0x000129AD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000129B0), "No sound driver is available for use", 36u); storage[UINT32_C(0x000129D4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000129D8), "This object is already initialized", 34u); storage[UINT32_C(0x000129FA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000129FC), "The buffer memory has been lost, and must be restored", 53u); storage[UINT32_C(0x00012A31)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012A34), "Another app has a higher priority level, preventing this call from succeeding", 77u); storage[UINT32_C(0x00012A81)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012A84), "This object has not been initialized", 36u); storage[UINT32_C(0x00012AA8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012AAC), "Tried to create a DSBCAPS_CTRLFX buffer shorter than DSBSIZE_FX_MIN milliseconds", 80u); storage[UINT32_C(0x00012AFC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012B00), "The specified WAVE format is not supported", 42u); storage[UINT32_C(0x00012B2A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012B2C), "Duplicate named fragment", 24u); storage[UINT32_C(0x00012B44)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012B48), "Can Not remove last item", 24u); storage[UINT32_C(0x00012B60)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012B64), "The call failed because resources (such as a priority level) were already being used by another caller", 102u); storage[UINT32_C(0x00012BCA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012BCC), "The control (vol, pan, etc.) requested by the caller is not available", 69u); storage[UINT32_C(0x00012C11)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012C14), "This call is not valid for the current state of this object", 59u); storage[UINT32_C(0x00012C4F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012C54), "The caller does not have the priority level required for the function to succeed", 80u); storage[UINT32_C(0x00012CA4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012CA8), "Loaded mesh has no data", 23u); storage[UINT32_C(0x00012CBF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012CC0), "Can not modify index buffer", 27u); storage[UINT32_C(0x00012CDB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012CDC), "Invalid mesh", 12u); storage[UINT32_C(0x00012CE8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012CEC), "Cannot attr sort", 16u); storage[UINT32_C(0x00012CFC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012D00), "Skinning not supported", 22u); storage[UINT32_C(0x00012D16)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012D18), "Too many influences", 19u); storage[UINT32_C(0x00012D2B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012D2C), "Invalid data", 12u); storage[UINT32_C(0x00012D38)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012D3C), "Driver invalid call", 19u); storage[UINT32_C(0x00012D4F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012D50), "More data", 9u); storage[UINT32_C(0x00012D59)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012D5C), "Device lost", 11u); storage[UINT32_C(0x00012D67)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012D68), "Device not reset", 16u); storage[UINT32_C(0x00012D78)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012D7C), "Not available", 13u); storage[UINT32_C(0x00012D89)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012D8C), "Invalid device", 14u); storage[UINT32_C(0x00012D9A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012D9C), "Invalid call", 12u); storage[UINT32_C(0x00012DA8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012DAC), "Driver internal error", 21u); storage[UINT32_C(0x00012DC1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012DC4), "Conflicting texture palette", 27u); storage[UINT32_C(0x00012DDF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012DE0), "Unsupported texture filter", 26u); storage[UINT32_C(0x00012DFA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012DFC), "Conflicting render state", 24u); storage[UINT32_C(0x00012E14)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012E18), "Unsupported factor value", 24u); storage[UINT32_C(0x00012E30)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012E34), "Conflicting texture filter", 26u); storage[UINT32_C(0x00012E4E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012E50), "Too many operations", 19u); storage[UINT32_C(0x00012E63)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012E64), "Unsupported alpha arg", 21u); storage[UINT32_C(0x00012E79)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012E7C), "Unsupported alpha operation", 27u); storage[UINT32_C(0x00012E97)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012E98), "Unsupported color arg", 21u); storage[UINT32_C(0x00012EAD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012EB0), "Unsupported color operation", 27u); storage[UINT32_C(0x00012ECB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012ECC), "Wrong texture format", 20u); storage[UINT32_C(0x00012EE0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012EE4), "Bad cache file", 14u); storage[UINT32_C(0x00012EF2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012EF4), "No more objects", 15u); storage[UINT32_C(0x00012F03)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012F04), "Bad array size", 14u); storage[UINT32_C(0x00012F12)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012F14), "Parse error", 11u); storage[UINT32_C(0x00012F1F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012F20), "Bad file", 8u); storage[UINT32_C(0x00012F28)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012F2C), "Bad file float size", 19u); storage[UINT32_C(0x00012F3F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012F40), "Bad file version", 16u); storage[UINT32_C(0x00012F50)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012F54), "Bad file type", 13u); storage[UINT32_C(0x00012F61)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012F64), "Bad resource", 12u); storage[UINT32_C(0x00012F70)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012F74), "Resource not found", 18u); storage[UINT32_C(0x00012F86)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012F88), "File not found", 14u); storage[UINT32_C(0x00012F96)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012F98), "Not done yet", 12u); storage[UINT32_C(0x00012FA4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012FA8), "Not found", 9u); storage[UINT32_C(0x00012FB1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012FB4), "Bad type", 8u); storage[UINT32_C(0x00012FBC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012FC0), "Bad value", 9u); storage[UINT32_C(0x00012FC9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012FCC), "Bad object", 10u); storage[UINT32_C(0x00012FD6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012FD8), "No internet", 11u); storage[UINT32_C(0x00012FE3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012FE4), "Bad intrinsics", 14u); storage[UINT32_C(0x00012FF2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00012FF4), "No more stream handles", 22u); storage[UINT32_C(0x0001300A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001300C), "No more data", 12u); storage[UINT32_C(0x00013018)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001301C), "Internal error", 14u); storage[UINT32_C(0x0001302A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001302C), "The driver does not enumerate display mode refresh rates.", 57u); storage[UINT32_C(0x00013065)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001306C), "Surfaces created by one direct draw device cannot be used directly by another direct draw device.", 97u); storage[UINT32_C(0x000130CD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000130D0), "Bad data reference", 18u); storage[UINT32_C(0x000130E2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000130E4), "The monitor does not have EDID data.", 36u); storage[UINT32_C(0x00013108)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001310C), "The mode test has finished executing.", 37u); storage[UINT32_C(0x00013131)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013134), "The mode test has switched to a new mode.", 41u); storage[UINT32_C(0x0001315D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013160), "D3D has not yet been initialized.", 33u); storage[UINT32_C(0x00013181)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013184), "The video port is not active", 28u); storage[UINT32_C(0x000131A0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000131A4), "The data has expired and is therefore no longer valid.", 54u); storage[UINT32_C(0x000131DA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000131DC), "The attempt to page lock a surface failed.", 42u); storage[UINT32_C(0x00013206)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013208), "The attempt to page unlock a surface failed.", 44u); storage[UINT32_C(0x00013234)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001323C), "An attempt was made to page unlock a surface with no outstanding page locks.", 76u); storage[UINT32_C(0x00013288)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001328C), "There is more data available than the specified buffer size could hold", 70u); storage[UINT32_C(0x000132D2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000132D4), "An attempt was made to allocate non-local video memory from a device that does not support non-local video memory.", 114u); storage[UINT32_C(0x00013346)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001334C), "A DC has already been returned for this surface. Only one DC can be retrieved per surface.", 90u); storage[UINT32_C(0x000133A6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000133A8), "Attempt was made to set a palette on a mipmap sublevel", 54u); storage[UINT32_C(0x000133DE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000133E4), "Attempt was made to create or set a device window without first setting the focus window", 88u); storage[UINT32_C(0x0001343C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013444), "Surface is an optimized surface, but has not yet been allocated any memory", 74u); storage[UINT32_C(0x0001348E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013494), "Device does not support optimized surfaces, therefore no video memory optimized surfaces", 88u); storage[UINT32_C(0x000134EC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000134F4), "The requested action could not be performed because the surface was of the wrong type.", 86u); storage[UINT32_C(0x0001354A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001354C), "Operation could not be carried out because there is no mip-map texture mapping hardware present or available.", 109u); storage[UINT32_C(0x000135B9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000135BC), "The display is currently in an unsupported mode", 47u); storage[UINT32_C(0x000135EB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000135EC), "The surface being used is not a palette-based surface", 53u); storage[UINT32_C(0x00013621)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013624), "This surface can not be restored because it is an implicitly created surface.", 77u); storage[UINT32_C(0x00013671)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013674), "This surface can not be restored because it was created in a different mode.", 76u); storage[UINT32_C(0x000136C0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000136C4), "No DC was ever created for this surface.", 40u); storage[UINT32_C(0x000136EC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000136F4), "Windows can not create any more DCs, or a DC was requested for a paltte-indexed surface when the surface had no palette AND the display mode was not palette-indexed (in this case DirectDraw cannot select a proper palette into the DC)", 233u); storage[UINT32_C(0x000137DD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000137E4), "Surface was not locked.  An attempt to unlock a surface that was not locked at all, or by this process, has been attempted.", 123u); storage[UINT32_C(0x0001385F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013864), "Can't duplicate primary & 3D surfaces, or surfaces that are implicitly created.", 79u); storage[UINT32_C(0x000138B3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000138B4), "An attempt has been made to flip a surface that is not flippable.", 65u); storage[UINT32_C(0x000138F5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000138FC), "An attempt was made to set the cooperative level when it was already set to exclusive.", 86u); storage[UINT32_C(0x00013952)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013954), "returned when an overlay member is called for a non-overlay surface", 67u); storage[UINT32_C(0x00013997)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001399C), "returned when the position of the overlay on the destionation is no longer legal for that destionation.", 103u); storage[UINT32_C(0x00013A03)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013A04), "returned when GetOverlayPosition is called on a overlay that UpdateOverlay has never been called on to establish a destionation.", 128u); storage[UINT32_C(0x00013A84)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013A88), "returned when GetOverlayPosition is called on a hidden overlay", 62u); storage[UINT32_C(0x00013AC6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013AC8), "No DirectDraw ROP hardware.", 27u); storage[UINT32_C(0x00013AE3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013AE4), "No blter.", 9u); storage[UINT32_C(0x00013AED)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013AF4), "If a clipper object is attached to the source surface passed into a BltFast call.", 81u); storage[UINT32_C(0x00013B45)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013B48), "No hardware support for 16 or 256 color palettes.", 49u); storage[UINT32_C(0x00013B79)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013B7C), "No palette object attached to this surface.", 43u); storage[UINT32_C(0x00013BA7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013BAC), "The CooperativeLevel HWND has already been set. It can not be reset while the process has surfaces or palettes created.", 119u); storage[UINT32_C(0x00013C23)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013C24), "HWND used by DirectDraw CooperativeLevel has been subclassed, this prevents DirectDraw from restoring state.", 108u); storage[UINT32_C(0x00013C90)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013C94), "Clipper notification requires an HWND or no HWND has previously been set as the CooperativeLevel HWND.", 102u); storage[UINT32_C(0x00013CFA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013CFC), "No clipper object attached to surface object", 44u); storage[UINT32_C(0x00013D28)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013D2C), "an attempt was made to set a clip list for a clipper objec that is already monitoring an hwnd.", 94u); storage[UINT32_C(0x00013D8A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013D8C), "region passed to Clipper::GetClipList is too small.", 51u); storage[UINT32_C(0x00013DBF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013DC0), "software emulation not available.", 33u); storage[UINT32_C(0x00013DE1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013DE4), "this process already has created a primary surface", 50u); storage[UINT32_C(0x00013E16)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013E1C), "A hardware only DirectDraw object creation was attempted but the driver did not support any hardware.", 101u); storage[UINT32_C(0x00013E81)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013E84), "The specified surface type requires specification of the COMPLEX flag", 69u); storage[UINT32_C(0x00013EC9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013ECC), "Rectangle provided was not horizontally aligned on reqd. boundary", 65u); storage[UINT32_C(0x00013F0D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013F14), "The GUID passed to DirectDrawCreate is not a valid DirectDraw driver identifier.", 80u); storage[UINT32_C(0x00013F64)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013F6C), "A DirectDraw object representing this driver has already been created for this process.", 87u); storage[UINT32_C(0x00013FC3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013FC4), "Was still drawing", 17u); storage[UINT32_C(0x00013FD5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00013FD8), "Width requested by DirectDraw is too large.", 43u); storage[UINT32_C(0x00014003)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014004), "Pixel format requested is unsupported by DirectDraw", 51u); storage[UINT32_C(0x00014037)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001403C), "Bitmask in the pixel format requested is unsupported by DirectDraw", 66u); storage[UINT32_C(0x0001407E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014080), "The specified stream contains invalid data", 42u); storage[UINT32_C(0x000140AA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000140AC), "vertical blank is in progress", 29u); storage[UINT32_C(0x000140C9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000140CC), "Size requested by DirectDraw is too large --  The individual height and width are OK.", 85u); storage[UINT32_C(0x00014121)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014124), "Access to Surface refused because Surface is obscured.", 54u); storage[UINT32_C(0x0001415A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001415C), "Access to this surface is being refused because the surface is gone. The DIRECTDRAWSURFACE object representing this surface should have Restore called on it.", 157u); storage[UINT32_C(0x000141F9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000141FC), "The requested surface is not attached.", 38u); storage[UINT32_C(0x00014222)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014224), "Height requested by DirectDraw is too large.", 44u); storage[UINT32_C(0x00014250)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014254), "Access to this surface is being refused because no driver exists which can supply a pointer to the surface. This is most likely to happen when attempting to lock the primary surface when no DCI provider is present. Will also happen on attempts to lock an optimized surface.", 273u); storage[UINT32_C(0x00014365)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001436C), "Access to this palette is being refused because the palette is already locked by another thread.", 96u); storage[UINT32_C(0x000143CC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000143D0), "No src color key specified for this operation.", 46u); storage[UINT32_C(0x000143FE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014404), "This surface is already attached to the surface it is being attached to.", 72u); storage[UINT32_C(0x0001444C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014454), "This surface is already a dependency of the surface it is being made a dependency of.", 85u); storage[UINT32_C(0x000144A9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000144AC), "Access to this surface is being refused because the surface is already locked by another thread.", 96u); storage[UINT32_C(0x0001450C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014510), "Can only have ony color key active at one time for overlays", 59u); storage[UINT32_C(0x0001454B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001454C), "Overlay surfaces could not be z layered based on their BltOrder because the hardware does not support z layering of overlays.", 125u); storage[UINT32_C(0x000145C9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000145CC), "The hardware needed for the requested operation has already been allocated.", 75u); storage[UINT32_C(0x00014617)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014618), "Out of video memory", 19u); storage[UINT32_C(0x0001462B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001462C), "hardware does not support clipped overlays", 42u); storage[UINT32_C(0x00014656)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001465C), "Operation could not be carried out because there is no hardware support for zbuffer blting.", 91u); storage[UINT32_C(0x000146B7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000146BC), "DirectDrawSurface is not in 4 bit color palette and the requested operation requires 4 bit color palette.", 105u); storage[UINT32_C(0x00014725)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001472C), "DirectDrawSurface is not in 4 bit color index palette and the requested operation requires 4 bit color index palette.", 117u); storage[UINT32_C(0x000147A1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000147A4), "DirectDraw Surface is not in 8 bit color mode and the requested operation requires 8 bit color.", 95u); storage[UINT32_C(0x00014803)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014804), "Operation could not be carried out because there is no texture mapping hardware present or available.", 101u); storage[UINT32_C(0x00014869)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001486C), "Operation could not be carried out because there is no hardware support for vertical blank synchronized operations.", 115u); storage[UINT32_C(0x000148DF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000148E4), "Operation could not be carried out because there is no hardware support for stretching", 86u); storage[UINT32_C(0x0001493A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001493C), "Operation could not be carried out because there is no overlay hardware present or available.", 93u); storage[UINT32_C(0x00014999)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001499C), "Operation could not be carried out because the source and destination rectangles are on the same surface and overlap each other.", 128u); storage[UINT32_C(0x00014A1C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014A24), "Operation could not be carried out because there is no appropriate raster op hardware present or available.", 107u); storage[UINT32_C(0x00014A8F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014A94), "Operation could not be carried out because there is no rotation hardware present or available.", 94u); storage[UINT32_C(0x00014AF2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014AF4), "Requested item was not found", 28u); storage[UINT32_C(0x00014B10)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014B14), "No DirectDraw support possible with current display driver", 58u); storage[UINT32_C(0x00014B4E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014B54), "Operation requires the application to have exclusive mode but the application does not have exclusive mode.", 107u); storage[UINT32_C(0x00014BBF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014BC0), "Flipping visible surfaces is not supported.", 43u); storage[UINT32_C(0x00014BEB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014BEC), "There is no GDI present.", 24u); storage[UINT32_C(0x00014C04)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014C0C), "Operation could not be carried out because there is no hardware present or available.", 85u); storage[UINT32_C(0x00014C61)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014C64), "Operation could not be carried out because there is no hardware support of the dest color key.", 94u); storage[UINT32_C(0x00014CC2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014CC4), "no clip list available", 22u); storage[UINT32_C(0x00014CDA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014CDC), "Operation could not be carried out because there is no color conversion hardware present or available.", 102u); storage[UINT32_C(0x00014D42)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014D44), "Create function called without DirectDraw object method SetCooperativeLevel being called.", 89u); storage[UINT32_C(0x00014D9D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014DA0), "Surface doesn't currently have a color key", 42u); storage[UINT32_C(0x00014DCA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014DCC), "Operation could not be carried out because there is no hardware present which supports stereo surfaces", 102u); storage[UINT32_C(0x00014E32)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014E34), "Rectangle provided was invalid.", 31u); storage[UINT32_C(0x00014E53)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014E54), "Operation could not be carried out because one or more surfaces are locked", 74u); storage[UINT32_C(0x00014E9E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014EA0), "There is no 3D present.", 23u); storage[UINT32_C(0x00014EB7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014EBC), "Operation could not be carried out because there is no alpha accleration hardware present or available.", 103u); storage[UINT32_C(0x00014F23)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014F24), "Operation could not be carried out because there is no stereo hardware present or available.", 92u); storage[UINT32_C(0x00014F80)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014F84), "pixel format was invalid as specified", 37u); storage[UINT32_C(0x00014FA9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014FAC), "One or more of the caps bits passed to the callback are incorrect.", 66u); storage[UINT32_C(0x00014FEE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00014FF0), "DirectDraw does not support provided Cliplist.", 46u); storage[UINT32_C(0x0001501E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015020), "DirectDraw does not support the requested mode", 46u); storage[UINT32_C(0x0001504E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015054), "DirectDraw received a pointer that was an invalid DIRECTDRAW object.", 68u); storage[UINT32_C(0x00015098)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001509C), "Unable to match primary surface creation request with existing primary surface.", 79u); storage[UINT32_C(0x000150EB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000150EC), "This surface can not be attached to the requested surface.", 58u); storage[UINT32_C(0x00015126)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015128), "This surface can not be detached from the requested surface.", 60u); storage[UINT32_C(0x00015164)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015168), "Support is currently not available.", 35u); storage[UINT32_C(0x0001518B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001518C), "An exception was encountered while performing the requested operation", 69u); storage[UINT32_C(0x000151D1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000151D4), "Height of rectangle provided is not a multiple of reqd alignment", 64u); storage[UINT32_C(0x00015214)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015218), "Table full", 10u); storage[UINT32_C(0x00015222)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015224), "Timed out", 9u); storage[UINT32_C(0x0001522D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015230), "Uninitialized", 13u); storage[UINT32_C(0x0001523D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015240), "User cancel", 11u); storage[UINT32_C(0x0001524B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001524C), "Session full", 12u); storage[UINT32_C(0x00015258)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001525C), "Player already in group", 23u); storage[UINT32_C(0x00015273)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015274), "Player lost", 11u); storage[UINT32_C(0x0001527F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015280), "Player not in group", 19u); storage[UINT32_C(0x00015293)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015294), "Player not reachable", 20u); storage[UINT32_C(0x000152A8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000152AC), "Send too large", 14u); storage[UINT32_C(0x000152BA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000152BC), "Not registered", 14u); storage[UINT32_C(0x000152CA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000152CC), "No response", 11u); storage[UINT32_C(0x000152D7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000152D8), "Not allowed", 11u); storage[UINT32_C(0x000152E3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000152E4), "Not host", 8u); storage[UINT32_C(0x000152EC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000152F0), "Not ready", 9u); storage[UINT32_C(0x000152F9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000152FC), "No more address components", 26u); storage[UINT32_C(0x00015316)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015318), "Invalid url", 11u); storage[UINT32_C(0x00015323)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015324), "Invalid version", 15u); storage[UINT32_C(0x00015333)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015334), "No caps", 7u); storage[UINT32_C(0x0001533B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001533C), "No connection", 13u); storage[UINT32_C(0x00015349)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001534C), "No host player", 14u); storage[UINT32_C(0x0001535A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001535C), "Invalid string", 14u); storage[UINT32_C(0x0001536A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001536C), "Invalid password", 16u); storage[UINT32_C(0x0001537C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015380), "Invalid player", 14u); storage[UINT32_C(0x0001538E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015390), "Invalid priority", 16u); storage[UINT32_C(0x000153A0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000153A4), "Invalid interface", 17u); storage[UINT32_C(0x000153B5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000153B8), "Invalid flags", 13u); storage[UINT32_C(0x000153C5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000153C8), "Invalid group", 13u); storage[UINT32_C(0x000153D5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000153D8), "Invalid handle", 14u); storage[UINT32_C(0x000153E6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000153E8), "Invalid host address", 20u); storage[UINT32_C(0x000153FC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015400), "Invalid instance", 16u); storage[UINT32_C(0x00015410)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015414), "Invalid end point", 17u); storage[UINT32_C(0x00015425)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015428), "Invalid address format", 22u); storage[UINT32_C(0x0001543E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015440), "Invalid application", 19u); storage[UINT32_C(0x00015453)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015454), "Invalid command", 15u); storage[UINT32_C(0x00015463)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015464), "Invalid device address", 22u); storage[UINT32_C(0x0001547A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001547C), "Incomplete address", 18u); storage[UINT32_C(0x0001548E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015490), "Exception", 9u); storage[UINT32_C(0x00015499)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001549C), "Group not empty", 15u); storage[UINT32_C(0x000154AB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000154AC), "Hosting", 7u); storage[UINT32_C(0x000154B3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000154B4), "Host rejected connection", 24u); storage[UINT32_C(0x000154CC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000154D0), "Host terminated session", 23u); storage[UINT32_C(0x000154E7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000154E8), "Enum response too large", 23u); storage[UINT32_C(0x000154FF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015500), "dpnsvr not available", 20u); storage[UINT32_C(0x00015514)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015518), "Duplicate command", 17u); storage[UINT32_C(0x00015529)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001552C), "End point not receiving", 23u); storage[UINT32_C(0x00015543)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015544), "Enum query too large", 20u); storage[UINT32_C(0x00015558)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001555C), "Does not exist", 14u); storage[UINT32_C(0x0001556A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001556C), "Cant launch application", 23u); storage[UINT32_C(0x00015583)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015584), "Connecting", 10u); storage[UINT32_C(0x0001558E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015590), "Conversion", 10u); storage[UINT32_C(0x0001559A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001559C), "Data too large", 14u); storage[UINT32_C(0x000155AA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000155AC), "Cant create player", 18u); storage[UINT32_C(0x000155BE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000155C0), "Already registered", 18u); storage[UINT32_C(0x000155D2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000155D4), "Buffer too small", 16u); storage[UINT32_C(0x000155E4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000155E8), "Can not cancel", 14u); storage[UINT32_C(0x000155F6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000155F8), "Cant create group", 17u); storage[UINT32_C(0x00015609)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001560C), "Already initialized", 19u); storage[UINT32_C(0x0001561F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015620), "Aborted", 7u); storage[UINT32_C(0x00015627)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015628), "Addressing", 10u); storage[UINT32_C(0x00015632)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015634), "Already closing", 15u); storage[UINT32_C(0x00015643)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015644), "Already connected", 17u); storage[UINT32_C(0x00015655)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015658), "Already disconnecting", 21u); storage[UINT32_C(0x0001566D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015670), "Locked buffer", 13u); storage[UINT32_C(0x0001567D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015680), "Invalid buffer", 14u); storage[UINT32_C(0x0001568E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015690), "No rec vol available", 20u); storage[UINT32_C(0x000156A4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000156A8), "User back", 9u); storage[UINT32_C(0x000156B1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000156B4), "Transport no player", 19u); storage[UINT32_C(0x000156C7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000156C8), "Transport no session", 20u); storage[UINT32_C(0x000156DC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000156E0), "Transport not init", 18u); storage[UINT32_C(0x000156F2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000156F4), "No callback", 11u); storage[UINT32_C(0x000156FF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015700), "No transport", 12u); storage[UINT32_C(0x0001570C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015710), "Initialized", 11u); storage[UINT32_C(0x0001571B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001571C), "Incompatible version", 20u); storage[UINT32_C(0x00015730)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015734), "Run setup", 9u); storage[UINT32_C(0x0001573D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015740), "Send error", 10u); storage[UINT32_C(0x0001574A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001574C), "Playback system error", 21u); storage[UINT32_C(0x00015761)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015764), "Record system error", 19u); storage[UINT32_C(0x00015777)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015778), "Not hosting", 11u); storage[UINT32_C(0x00015783)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015784), "Not buffered", 12u); storage[UINT32_C(0x00015790)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015794), "Already buffered", 16u); storage[UINT32_C(0x000157A4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000157A8), "No 3d sound", 11u); storage[UINT32_C(0x000157B3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000157B4), "Connect aborted", 15u); storage[UINT32_C(0x000157C3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000157C4), "Time out", 8u); storage[UINT32_C(0x000157CC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000157D0), "Sound init failure", 18u); storage[UINT32_C(0x000157E2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000157E4), "Already pending", 15u); storage[UINT32_C(0x000157F3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000157F4), "Compression not supported", 25u); storage[UINT32_C(0x0001580D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015810), "Transport not host", 18u); storage[UINT32_C(0x00015822)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015824), "Invalid target", 14u); storage[UINT32_C(0x00015832)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015834), "Connect aborting", 16u); storage[UINT32_C(0x00015844)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015848), "Not connected", 13u); storage[UINT32_C(0x00015855)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015858), "Connected", 9u); storage[UINT32_C(0x00015861)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015864), "Not initialized", 15u); storage[UINT32_C(0x00015873)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015874), "Session lost", 12u); storage[UINT32_C(0x00015880)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015884), "No voice session", 16u); storage[UINT32_C(0x00015894)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015898), "Connection lost", 15u); storage[UINT32_C(0x000158A7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000158A8), "Invalid object", 14u); storage[UINT32_C(0x000158B6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000158B8), "The specified property set is not supported.", 44u); storage[UINT32_C(0x000158E4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000158E8), "No more items.", 14u); storage[UINT32_C(0x000158F6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000158F8), "The application requires a newer version of DirectInput.", 56u); storage[UINT32_C(0x00015930)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015934), "The application was written for an unsupported prerelease version of DirectInput.", 81u); storage[UINT32_C(0x00015985)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001598C), "The specified property ID is not supported for the specified property set.", 74u); storage[UINT32_C(0x000159D6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000159DC), "The operation cannot be performed while the device is acquired.", 63u); storage[UINT32_C(0x00015A1B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015A1C), "Ran out of memory", 17u); storage[UINT32_C(0x00015A2D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015A30), "Access to the device has been lost.  It must be re-acquired.", 60u); storage[UINT32_C(0x00015A6C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015A70), "An invalid parameter was passed to the returning function", 57u); storage[UINT32_C(0x00015AA9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015AAC), "The object could not be created due to an incompatible driver version or mismatched or incomplete driver components.", 116u); storage[UINT32_C(0x00015B20)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015B24), "The operation cannot be performed unless the device is acquired.", 64u); storage[UINT32_C(0x00015B64)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015B6C), "An attempt was made to load a program with an incorrect format.", 63u); storage[UINT32_C(0x00015BAB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015BAC), "The device was removed.", 23u); storage[UINT32_C(0x00015BC3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015BC4), "Access is denied", 16u); storage[UINT32_C(0x00015BD4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015BD8), "Incorrect version of Direct3D or D3DX.", 38u); storage[UINT32_C(0x00015BFE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015C00), "An error occurred when attempting to create a device.", 53u); storage[UINT32_C(0x00015C35)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015C38), "An error occurred when attempting to reset a device.", 52u); storage[UINT32_C(0x00015C6C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015C70), "An error occurred in the device create callback function.", 57u); storage[UINT32_C(0x00015CA9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015CAC), "An error occurred in the device reset callback function.", 56u); storage[UINT32_C(0x00015CE4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015CEC), "The device interface has a non-zero reference count, meaning that some objects were not released.", 97u); storage[UINT32_C(0x00015D4D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015D50), "The stream type is not valid for this operation.", 48u); storage[UINT32_C(0x00015D80)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015D84), "The object is not in running state.", 35u); storage[UINT32_C(0x00015DA7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015DA8), "Could not initialize Direct3D.", 30u); storage[UINT32_C(0x00015DC6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015DC8), "No device could be found with the specified device settings.", 60u); storage[UINT32_C(0x00015E04)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015E08), "A media file could not be found.", 32u); storage[UINT32_C(0x00015E28)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015E2C), "The object can't accept the call because its initialize function or equivalent has not been called.", 99u); storage[UINT32_C(0x00015E8F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015E90), "The sample is busy.", 19u); storage[UINT32_C(0x00015EA3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015EA4), "The stream formats are not compatible.", 38u); storage[UINT32_C(0x00015ECA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015ECC), "Seeking not supported for this object.", 38u); storage[UINT32_C(0x00015EF2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015EF4), "No stream can be found with the specified attributes.", 53u); storage[UINT32_C(0x00015F29)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015F2C), "A registry entry is corrupt.", 28u); storage[UINT32_C(0x00015F48)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015F4C), "The INF file for the selected device could not be found or is invalid or is damaged. & The specified purpose ID can't be used for the call.", 139u); storage[UINT32_C(0x00015FD7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00015FDC), "The user cancelled the install operation. & The stream already has allocated samples and the surface doesn't match the sample format.", 133u); storage[UINT32_C(0x00016061)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016064), "Registry entry or DLL for class installer invalid or class installer not found.", 79u); storage[UINT32_C(0x000160B3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000160B4), "Device installer errors.", 24u); storage[UINT32_C(0x000160CC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000160D0), "An operation failed due to a certification failure.", 51u); storage[UINT32_C(0x00016103)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016104), "IPinFlowControl::Block() has been called on another thread.  The current thread cannot make any assumptions about this pin's block state.", 137u); storage[UINT32_C(0x0001618D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016194), "This thread has already blocked this output pin.  There is no need to call IPinFlowControl::Block() again.", 106u); storage[UINT32_C(0x000161FE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016200), "There is currently no resume information.", 41u); storage[UINT32_C(0x00016229)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001622C), "The specified path does not point to a valid DVD disc.", 54u); storage[UINT32_C(0x00016262)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016264), "The operation depends on the current title number, however the navigator has not yet entered the VTSM or the title domains, so the 'current' title index is unknown.", 164u); storage[UINT32_C(0x00016308)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001630C), "The specified stream is disabled and cannot be selected.", 56u); storage[UINT32_C(0x00016344)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016348), "Frame step is not supported on this configuration.", 50u); storage[UINT32_C(0x0001637A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001637C), "The current audio is not karaoke content.", 41u); storage[UINT32_C(0x000163A5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000163A8), "The current parental level was too low.", 39u); storage[UINT32_C(0x000163CF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000163D4), "Currently there is no GoUp (Annex J user function) program chain (PGC).", 71u); storage[UINT32_C(0x0001641B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001641C), "The requested DVD stream attribute does not exist.", 50u); storage[UINT32_C(0x0001644E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016450), "The region was not compatible with the current drive.", 53u); storage[UINT32_C(0x00016485)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016488), "The state data is from a different disc.", 40u); storage[UINT32_C(0x000164B0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000164B4), "The state data was corrupt.", 27u); storage[UINT32_C(0x000164CF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000164D0), "The data did not contain a recognized version.", 46u); storage[UINT32_C(0x000164FE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016504), "The specified command was either cancelled or no longer exists.", 63u); storage[UINT32_C(0x00016543)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016544), "The specified menu doesn't exist.", 33u); storage[UINT32_C(0x00016565)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001656C), "The operation cannot be performed at the current playback speed.", 64u); storage[UINT32_C(0x000165AC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000165B0), "This object cannot be used anymore as its time has expired.", 59u); storage[UINT32_C(0x000165EB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000165EC), "Copy protection cannot be enabled. Please make sure any other copy protected content is not being shown now.", 108u); storage[UINT32_C(0x00016658)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001665C), "Version number of DirectDraw not suitable. Make sure to install dx5 or higher version.", 86u); storage[UINT32_C(0x000166B2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000166B4), "DVD-Video playback graph could not be built due to insufficient decoders.", 73u); storage[UINT32_C(0x000166FD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016700), "DVD-Video playback graph building failed.", 41u); storage[UINT32_C(0x00016729)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001672C), "DVD-Video playback graph has not been built yet.", 48u); storage[UINT32_C(0x0001675C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016764), "The specified button is invalid or is not present at the current time, or there is no button present at the specified location.", 127u); storage[UINT32_C(0x000167E3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000167E4), "This Operation is not permitted in the current domain.", 54u); storage[UINT32_C(0x0001681A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001681C), "This User Operation is inhibited by DVD Content at this time.", 61u); storage[UINT32_C(0x00016859)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001685C), "No Capture hardware is available, or the hardware is not responding.", 68u); storage[UINT32_C(0x000168A0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000168A4), "No VideoPort hardware is available, or the hardware is not responding.", 70u); storage[UINT32_C(0x000168EA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000168EC), "Either DirectDraw has not been installed or the Video Card capabilities are not suitable. Make sure the display is not in 16 color mode.", 136u); storage[UINT32_C(0x00016974)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016978), "The VideoPort connection negotiation process has failed.", 56u); storage[UINT32_C(0x000169B0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000169B4), "There is not enough Video Memory at this display resolution and number of colors. Reducing resolution might help.", 113u); storage[UINT32_C(0x00016A25)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016A2C), "The Video CD can't be read correctly by the device or is the data is corrupt.", 77u); storage[UINT32_C(0x00016A79)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016A7C), "Pins cannot connect due to not supporting the same transport.", 61u); storage[UINT32_C(0x00016AB9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016ABC), "Cannot play back the file.  The format is not supported.", 56u); storage[UINT32_C(0x00016AF4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016AF8), "The buffer is not full enough.", 30u); storage[UINT32_C(0x00016B16)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016B1C), "The connection cannot be made because the stream is read only and the filter alters the data.", 93u); storage[UINT32_C(0x00016B79)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016B7C), "Device driver-specific codes. Unless the specific driver has been precisely identified, no meaning should be attributed to these values other than that the driver originated the error.", 184u); storage[UINT32_C(0x00016C34)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016C3C), "Cannot get or set time related information on an object that is using a time format of TIME_FORMAT_NONE.", 104u); storage[UINT32_C(0x00016CA4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016CAC), "Cannot perform the requested function on an object that is not in the filter graph.", 83u); storage[UINT32_C(0x00016CFF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016D04), "ActiveMovie cannot play this video stream because it falls outside the constrained standard.", 92u); storage[UINT32_C(0x00016D60)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016D64), "Cannot play back the video stream: the video format is not supported.", 69u); storage[UINT32_C(0x00016DA9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016DAC), "Cannot play back the audio stream: the audio format is not supported.", 69u); storage[UINT32_C(0x00016DF1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016DF4), "ActiveMovie cannot play MPEG movies on this processor.", 54u); storage[UINT32_C(0x00016E2A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016E2C), "Cannot play back the audio stream: no audio hardware is available, or the hardware is not responding.", 101u); storage[UINT32_C(0x00016E91)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016E94), "Cannot change balance because audio device is mono only.", 56u); storage[UINT32_C(0x00016ECC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016ED0), "No media time format has been selected.", 39u); storage[UINT32_C(0x00016EF7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016EF8), "No media time stamp has been set for this sample.", 49u); storage[UINT32_C(0x00016F29)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016F2C), "No time stamp has been set for this sample.", 43u); storage[UINT32_C(0x00016F57)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016F58), "This file is corrupt: it contains an invalid media type.", 56u); storage[UINT32_C(0x00016F90)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016F94), "This file is corrupt: it contains an invalid class identifier.", 62u); storage[UINT32_C(0x00016FD2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00016FD4), "The version number of the file is invalid.", 42u); storage[UINT32_C(0x00016FFE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017000), "A file appeared to be incomplete.", 33u); storage[UINT32_C(0x00017021)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017024), "The source filter for this file could not be loaded.", 52u); storage[UINT32_C(0x00017058)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001705C), "The media type of this file is not recognized.", 46u); storage[UINT32_C(0x0001708A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001708C), "Cannot call IVideoWindow methods while in full-screen mode.", 59u); storage[UINT32_C(0x000170C7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000170C8), "A full-screen mode is not available.", 36u); storage[UINT32_C(0x000170EC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000170F4), "This Advise cannot be canceled because it was not successfully set.", 67u); storage[UINT32_C(0x00017137)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017138), "No full-screen modes are available.", 35u); storage[UINT32_C(0x0001715B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001715C), "An overlay advise link already exists.", 38u); storage[UINT32_C(0x00017182)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017184), "Cannot render the file because it is corrupt.", 45u); storage[UINT32_C(0x000171B1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000171B4), "The queued command has already been canceled.", 45u); storage[UINT32_C(0x000171E1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000171E4), "An attempt was made to queue a command for a time in the past.", 62u); storage[UINT32_C(0x00017222)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017224), "Updates are not allowed in this state.", 38u); storage[UINT32_C(0x0001724A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001724C), "The filter graph is circular.", 29u); storage[UINT32_C(0x00017269)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001726C), "The list has already been exhausted.", 36u); storage[UINT32_C(0x00017290)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017294), "The file format is invalid.", 27u); storage[UINT32_C(0x000172AF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000172B0), "A time-out has expired.", 23u); storage[UINT32_C(0x000172C7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000172C8), "An attempt to add a filter with a duplicate name failed.", 56u); storage[UINT32_C(0x00017300)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017304), "This sample cannot be rendered because the end of the stream has been reached.", 78u); storage[UINT32_C(0x00017352)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017354), "This sample cannot be rendered.", 31u); storage[UINT32_C(0x00017373)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017374), "This pin cannot use the supplied media type.", 44u); storage[UINT32_C(0x000173A0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000173A4), "The supplied rectangle is invalid.", 34u); storage[UINT32_C(0x000173C6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000173C8), "The sample start time is after the sample end time.", 51u); storage[UINT32_C(0x000173FB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000173FC), "The operation could not be performed because the filter is in the wrong state.", 78u); storage[UINT32_C(0x0001744A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001744C), "The operation could not be performed because the filter is not running.", 71u); storage[UINT32_C(0x00017493)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017494), "The operation could not be performed because the filter is not paused.", 70u); storage[UINT32_C(0x000174DA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000174DC), "The operation could not be performed because the filter is not stopped.", 71u); storage[UINT32_C(0x00017523)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017524), "The state changed while waiting to process the sample.", 54u); storage[UINT32_C(0x0001755A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001755C), "Too many colors for the current display settings.", 49u); storage[UINT32_C(0x0001758D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017590), "Display does not use a palette.", 31u); storage[UINT32_C(0x000175AF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000175B0), "No palette is available.", 24u); storage[UINT32_C(0x000175C8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000175CC), "No matching color key is available.", 35u); storage[UINT32_C(0x000175EF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000175F4), "Setting a palette would conflict with the color key already set.", 64u); storage[UINT32_C(0x00017634)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001763C), "Setting a color key would conflict with the palette already set.", 64u); storage[UINT32_C(0x0001767C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017684), "Current pin connection is not using the IMemInputPin transport.", 63u); storage[UINT32_C(0x000176C3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000176C4), "Current pin connection is not using the IOverlay transport.", 59u); storage[UINT32_C(0x000176FF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017700), "No color key has been set.", 26u); storage[UINT32_C(0x0001771A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001771C), "Could not change formats dynamically.", 37u); storage[UINT32_C(0x00017741)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017744), "No combination of filters could be found to render the stream.", 62u); storage[UINT32_C(0x00017782)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017784), "No combination of intermediate filters could be found to make the connection.", 77u); storage[UINT32_C(0x000177D1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000177D4), "An object or name was not found.", 32u); storage[UINT32_C(0x000177F4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000177F8), "A required interface has not been implemented.", 46u); storage[UINT32_C(0x00017826)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001782C), "Quality messages could not be sent because no quality sink has been defined.", 76u); storage[UINT32_C(0x00017878)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001787C), "Cannot lock for synchronization because no clock has been defined.", 66u); storage[UINT32_C(0x000178BE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000178C0), "Cannot allocate memory because no size has been set.", 52u); storage[UINT32_C(0x000178F4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000178F8), "Cannot allocate a sample when the allocator is not active.", 58u); storage[UINT32_C(0x00017932)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017934), "One or more buffers are still active.", 37u); storage[UINT32_C(0x00017959)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001795C), "Cannot change allocated memory while the filter is active.", 58u); storage[UINT32_C(0x00017996)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017998), "An invalid alignment was specified.", 35u); storage[UINT32_C(0x000179BB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000179BC), "The buffer is not big enough.", 29u); storage[UINT32_C(0x000179D9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000179DC), "No buffer space has been set", 28u); storage[UINT32_C(0x000179F8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000179FC), "A mapper file function failed because reading or writing the user or IHV settings file failed. & A run-time error occurred.", 123u); storage[UINT32_C(0x00017A77)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017A7C), "SendDeviceData failed because more information was requested to be sent than can be sent to the device.  Some devices have restrictions on how much data can be sent to them.  (For example, there might be a limit on the number of buttons that can be pressed at once.) & No sample buffer allocator is available.", 309u); storage[UINT32_C(0x00017BB1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017BB4), "The operation could not be completed because the device is not plugged in. & The operation cannot be performed because the pins are not connected.", 146u); storage[UINT32_C(0x00017C46)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017C4C), "An attempt was made to modify parameters of an effect while it is playing.  Not all hardware devices support altering the parameters of an effect while it is playing. & Two pins of the same direction cannot be connected together.", 229u); storage[UINT32_C(0x00017D31)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017D34), "Attempted to read buffered device data from a device that is not buffered. & There is no common media type between these pins.", 126u); storage[UINT32_C(0x00017DB2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017DB4), "The effect could not be downloaded because essential information is missing.  For example, no axes have been associated with the effect, or no type-specific information has been created. & One of the specified pins supports no media types.", 239u); storage[UINT32_C(0x00017EA3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017EA4), "The operation cannot be performed unless the device is acquired in DISCL_EXCLUSIVE mode. & This operation cannot be performed because the filter is active.", 155u); storage[UINT32_C(0x00017F3F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017F44), "The device cannot be reinitialized because there are still effects attached to it. & At least one of the pins involved in the operation is already connected.", 157u); storage[UINT32_C(0x00017FE1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00017FE4), "The effect is not downloaded. & The enumerator has become invalid.", 66u); storage[UINT32_C(0x00018026)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001802C), "Not all the requested information fit into the buffer. & This object can only be created as an aggregated object.", 113u); storage[UINT32_C(0x0001809D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000180A0), "The device is full. & An invalid media subtype was specified.", 61u); storage[UINT32_C(0x000180DD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000180E4), "Unable to IDirectInputJoyConfig_Acquire because the user does not have sufficient privileges to change the joystick configuration. & An invalid media type was specified", 168u); storage[UINT32_C(0x0001818C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018190), "Catastrophic failure", 20u); storage[UINT32_C(0x000181A4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000181A8), "This object does not support aggregation", 40u); storage[UINT32_C(0x000181D0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000181D4), "Class not registered", 20u); storage[UINT32_C(0x000181E8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000181EC), "CoInitialize has not been called.", 33u); storage[UINT32_C(0x0001820D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018210), "CoInitialize has already been called.", 37u); storage[UINT32_C(0x00018235)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018238), "An undetermined error occurred", 30u); storage[UINT32_C(0x00018256)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001825C), "The data necessary to complete this operation is not yet available.", 67u); storage[UINT32_C(0x0001829F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000182A0), "The function called is not supported at this time", 49u); storage[UINT32_C(0x000182D1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000182D4), "The requested COM interface is not available", 44u); storage[UINT32_C(0x00018300)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018304), "Invalid pointer", 15u); storage[UINT32_C(0x00018313)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018314), "Operation aborted", 17u); storage[UINT32_C(0x00018325)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018328), "\300#?\275>\324\317\021\211;\000\252\000\275\316\032\030\001\000\000\000\000\000\000\300\000\000\000\000\000\000F\022\001\000\000\000\000\000\000\300\000\000\000\000\000\000F\024\001\000\000\000\000\000\000\300\000\000\000\000\000\000F\023\001\000\000\000\000\000\000\300\000\000\000\000\000\000F\031\001\000\000\000\000\000\000\300\000\000\000\000\000\000F'\001\000\000\000\000\000\000\300\000\000\000\000\000\000F\000\000\000\000\000\000\000\000\300\000\000\000\000\000\000Fa\026\014\323\257\315\320\021\212>\000\300O\311\342na\371V\210\n4\320\021\251k\000\300O\327\005\242%D,3\313&\320\021\264\203\000\300O\331\001\031test_ptr2: MEM CORRUPTED! \000\000test_ptr1: MEM CORRUPTED! \000\000test_ptr0: MEM CORRUPTED", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018428), "! \000\000store_ptr: MEM CORRUPTED! \000\000realloc: MEM CORRUPTED! \000\000\000\000free: MEM CORRUPTED! ", 81u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001847C), "alloced: <Source info is corrupted>", 35u); storage[UINT32_C(0x0001849F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000184A0), "alloced: %s %d", 14u); storage[UINT32_C(0x000184AE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000184B0), " (overflow). ", 13u); storage[UINT32_C(0x000184BD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000184C0), " (underflow). ", 14u); storage[UINT32_C(0x000184CE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000184D0), ". ", 2u); storage[UINT32_C(0x000184D2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000184D4), "validate_and_remove_pointer: pointer not in hash", 48u); storage[UINT32_C(0x00018504)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018508), "Free of wrong pointer or double free. %s %d %d", 46u); storage[UINT32_C(0x00018536)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018538), "Memory\\MemoryMgr.cpp", 20u); storage[UINT32_C(0x0001854C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018550), "realloc2 with wrong pointer", 27u); storage[UINT32_C(0x0001856B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001856C), "store_pointer: pointer already in hash", 38u); storage[UINT32_C(0x00018592)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018594), "Memory corruption!", 18u); storage[UINT32_C(0x000185A6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000185A8), "malloc2: Not enough memory. Request size = %d", 45u); storage[UINT32_C(0x000185D5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000185D8), "malloc2: Wrong size value. Size=%d", 34u); storage[UINT32_C(0x000185FA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000185FC), "free2: test system not initialized", 34u); storage[UINT32_C(0x0001861E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018620), "realloc2: Not enough memory. Request size = %d", 46u); storage[UINT32_C(0x0001864E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018650), "realloc2: Wrong size value. Size = %d", 37u); storage[UINT32_C(0x00018675)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018678), "verify before terminate", 23u); storage[UINT32_C(0x0001868F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018690), "LogMemory.log", 13u); storage[UINT32_C(0x0001869D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000186A0), "$d $t ", 6u); storage[UINT32_C(0x000186A6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000186A8), "Criticals.log", 13u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000186B8), "%d ", 3u); storage[UINT32_C(0x000186BB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000186BC), "Stack:\n", 7u); storage[UINT32_C(0x000186C3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000186C4), "(%s:%u)\t(%hs+%I64X)\n", 20u); storage[UINT32_C(0x000186D8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000186DC), "crt0.c", 6u); storage[UINT32_C(0x000186E2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000186E4), "errorsmgr.cpp", 13u); storage[UINT32_C(0x000186F1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000186F4), "stackdump.cpp", 13u); storage[UINT32_C(0x00018701)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018704), "critLogTmp.$$$", 14u); storage[UINT32_C(0x00018712)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018714), "%d/%m/%y %H:%M:%S ", 18u); storage[UINT32_C(0x00018726)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018728), "terminating cause of LERROR", 27u); storage[UINT32_C(0x00018743)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018744), "Error processing reenter. Terminating", 37u); storage[UINT32_C(0x00018769)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001876C), "Warnings.log", 12u); storage[UINT32_C(0x00018778)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001877C), "$d $t $u", 8u); storage[UINT32_C(0x00018784)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018788), "Errors.log", 10u); storage[UINT32_C(0x00018792)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018794), "Log::Log: Not enough memory. Len = %d", 37u); storage[UINT32_C(0x000187B9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000187BC), "Logs\\Log.cpp", 12u); storage[UINT32_C(0x000187C8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000187CC), "Log::Log: trunc log %s and dayly files are mutualy exclusive capabilities.", 74u); storage[UINT32_C(0x00018816)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018818), "Log::append_realloc(): Not enough memory. Len = %d", 50u); storage[UINT32_C(0x0001884A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001884C), "_%y%m%d", 7u); storage[UINT32_C(0x00018853)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018854), "%d/%m/%y", 8u); storage[UINT32_C(0x0001885C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018860), "[%d] ", 5u); storage[UINT32_C(0x00018865)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018868), " *****\n", 7u); storage[UINT32_C(0x0001886F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018870), "***** Quit  ", 12u); storage[UINT32_C(0x0001887C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018880), "qwertyuiopasdfghjklzxcvbnm", 26u); storage[UINT32_C(0x0001889A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001889C), "QWERTYUIOPASDFGHJKLZXCVBNM", 26u); storage[UINT32_C(0x000188B6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000188B8), "Containers\\Containers.cpp", 25u); storage[UINT32_C(0x000188D1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000188D4), "operator[]: out of range. Size=%d, Index=%d", 43u); storage[UINT32_C(0x000188FF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018900), "\020|Q\000p\327N\000\220\327N\000\260\327N", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018914), "h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\Allocator.h", 84u); storage[UINT32_C(0x00018968)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001896C), "Files\\FileMap.cpp", 17u); storage[UINT32_C(0x0001897D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018980), "Error unmappnig file %s", 23u); storage[UINT32_C(0x00018997)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018998), "FileMap::size: file is not opened", 33u); storage[UINT32_C(0x000189B9)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000189BC), "FileMap::size: open file %s error", 33u); storage[UINT32_C(0x000189DD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000189E0), "FileMap::get_ptr: open file %s error", 36u); storage[UINT32_C(0x00018A04)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018A08), "FileMap::get_ptr: file is not opened", 36u); storage[UINT32_C(0x00018A2C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018A30), "Memory\\hash8mem.cpp", 19u); storage[UINT32_C(0x00018A43)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018A44), "CHash8Memory::register_str: Not enough memory. Request size = %d", 64u); storage[UINT32_C(0x00018A84)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018A88), "Memory\\hash32mem.cpp", 20u); storage[UINT32_C(0x00018A9C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018AA0), "CHash32Mem: init. Not enough memory", 35u); storage[UINT32_C(0x00018AC3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018AC4), "CHash32Mem: register_str. Not enough memory. Requested size = %d", 64u); storage[UINT32_C(0x00018B04)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018B08), "Logs\\AntifloodQueue.cpp", 23u); storage[UINT32_C(0x00018B1F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018B20), "Not enough memory. len = %d", 27u); storage[UINT32_C(0x00018B3B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018B3C), "AntifloodQueue::pop_record: queue underflow", 43u); storage[UINT32_C(0x00018B67)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018B68), "AntifloodQueue::copy_str: not enough memory. Len = %d", 53u); storage[UINT32_C(0x00018B9D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018BA0), "AntifloodQueue::push_record: queue overflow", 43u); storage[UINT32_C(0x00018BCB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018BCC), "\\|Q\000\327\350N\0008\004\371\004\220\004\371\004", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018BDC), "@\367N", 3u); storage[UINT32_C(0x00018BDF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00018BE0), "\376\226\301~\005p\321\021\255\220\000\300O\330\375\377\201\246\022\334\177s\317\021\210M\000\252\000K.$\232<5IkQ\321\021\256\246\000\300O\266\210 \200\246\022\334\177s\317\021\210M\000\252\000K.$\231\334V\225\214\202\317\021\243~\000\252\0002@\307\207\246\022\334\177s\317\021\210M\000\252\000K.$\001x\205|\201s\317\021\210M\000\252\000K.$\341Gy\0021\327\316\021\243W\000\000\000\000\000\001u\246\254D\374\350\320\021\240|\000\300O\266\210 t\246\254D\374\350\320\021\240|\000\300O\266\210 \214\272\372\034#\025\321\021\255y\000\300O\330\375\377\004\235s1q4\364L\232|W\244J\347\031V\274\341\207\35332\322\021\256\311\000\300O\266\210 \3072\236\304\213\274\322\021\205\324\000\020Z\037\203\004\305\336Y\243\023\3504H\212*\272\177\035w}v\231<5IkQ\321\021\256\246\000\300O\266\210 ", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018CE0), "\210\302\005'\256y\322\021\263H\000\020Z\037\201w\222<5IkQ\321\021\256\246\000\300O\266\210 \021\370\220E:\035\320\021\211\037\000\252\000K.$\230fKg\222\356\320\021\255q\000\300O\330\375\377( \275I#\025\321\021\255y\000\300O\330\375\377\2060e\232O\027\322\021\265\371\000\020Kp>\375W\227\257m7.\322\021\256\311\000\300O\266\210 \275\341\207\35332\322\021\256\311\000\300O\266\210 \3062\236\304\213\274\322\021\205\324\000\020Z\037\203\004\362f\025\307\036V\321\021\255\207\000\300O\330\375\377\235U\034\215\360\204\263K\247\325V\247CZ\233\246\371\035\263\267\025\325\323\021\241\034\000\020Z\037QZ:\210\277\277\327\312\323\021\241\033\000\020Z\037QZN\227\257m7.\322\021\256\311\000\300O\266\210 RSDS\300C\255\244\307\2475H\215ni\036]\353&\332\007\000\000\000H:\\work\\", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018DE0), "Sphere\\Sphere1_main_update\\~Src\\Output\\Release_S1\\SphereClient\\SphereClient.pdb", 79u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018E3E), "R\000\370dQ", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018E4C), "\002\000\000\000\010eQ\000\024eQ\0000eQ\000\000\000\000\000\000\000R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\370dQ\000\034\000R", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018E88), "\377\377\377\377\000\000\000\000@\000\000\000LeQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018EA0), "\001\000\000\000\\eQ\0000eQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018EB8), "\001\000\000\000teQ\000|eQ\000\000\000\000\000X\000R", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018ED4), "\377\377\377\377\000\000\000\000@\000\000\000deQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018EF0), "x\000R\000\254eQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018F00), "\002\000\000\000\274eQ\000\310eQ\000|eQ\000\000\000\000\000x\000R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\254eQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018F3C), "`\002R\000\370eQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018F4C), "\001\000\000\000\010fQ\000\020fQ\000\000\000\000\000`\002R", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018F68), "\377\377\377\377\000\000\000\000@\000\000\000\370eQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018F84), "\200\002R\000@fQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018F94), "\002\000\000\000PfQ\000\\fQ\000\020fQ\000\000\000\000\000\200\002R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000@fQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018FD0), "\250\002R\000\214fQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00018FE0), "\002\000\000\000\234fQ\000\250fQ\000\020fQ\000\000\000\000\000\250\002R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\214fQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001901C), "\304\002R\000\330fQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001902C), "\002\000\000\000\350fQ\000\364fQ\000\020fQ\000\000\000\000\000\304\002R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\330fQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019068), "\340\002R\000$gQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019078), "\002\000\000\0004gQ\000@gQ\000\020fQ\000\000\000\000\000\340\002R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000$gQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000190B4), "\374\002R\000pgQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000190C4), "\002\000\000\000\200gQ\000\214gQ\000\020fQ\000\000\000\000\000\374\002R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000pgQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019100), "\034\003R\000\274gQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019110), "\002\000\000\000\314gQ\000\330gQ\000\020fQ\000\000\000\000\000\034\003R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\274gQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001914C), "l\005R\000\010hQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001915C), "\001\000\000\000\030hQ\000 hQ\000\000\000\000\000l\005R", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019178), "\377\377\377\377\000\000\000\000@\000\000\000\010hQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019194), "\210\005R\000PhQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000191A4), "\002\000\000\000`hQ\000lhQ\000 hQ\000\000\000\000\000\210\005R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000PhQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000191E0), "\250\005R\000\234hQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000191F0), "\002\000\000\000\254hQ\000\270hQ\000 hQ\000\000\000\000\000\250\005R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\234hQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019228), "\001\000\000\000\344hQ\000\354hQ\000\000\000\000\000\324\005R", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019244), "\377\377\377\377\000\000\000\000@\000\000\000\324hQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019260), "\354\005R\000\034iQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019270), "\002\000\000\000,iQ\0008iQ\000\354hQ\000\000\000\000\000\354\005R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\034iQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000192A8), "\001\000\000\000diQ\000liQ\000\000\000\000\000\030\006R", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000192C4), "\377\377\377\377\000\000\000\000@\000\000\000TiQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000192E0), "<\006R\000\234iQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000192F0), "\002\000\000\000\254iQ\000\270iQ\000liQ\000\000\000\000\000<\006R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\234iQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001932C), "d\006R\000\350iQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001933C), "\002\000\000\000\370iQ\000\004jQ\000liQ\000\000\000\000\000d\006R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\350iQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019378), "\204\006R\0004jQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019388), "\003\000\000\000DjQ\000TjQ\000\004jQ\000liQ\000\000\000\000\000\204\006R\000\002\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\0004jQ", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000193C8), "\264\006R\000\204jQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000193D8), "\003\000\000\000\224jQ\000\244jQ\000\004jQ\000liQ\000\000\000\000\000\264\006R\000\002\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\204jQ", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019418), "\340\006R\000\324jQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019428), "\004\000\000\000\344jQ\000\370jQ\000TjQ\000\004jQ\000liQ\000\000\000\000\000\340\006R\000\003\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\324jQ", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001946C), "\224\020R\000(kQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001947C), "\001\000\000\0008kQ\000@kQ\000\000\000\000\000\224\020R", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019498), "\377\377\377\377\000\000\000\000@\000\000\000(kQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000194B4), "\250\020R\000pkQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000194C4), "\002\000\000\000\200kQ\000\214kQ\000@kQ\000\000\000\000\000\250\020R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000pkQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019500), "\304\020R\000\274kQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019510), "\002\000\000\000\314kQ\000\330kQ\000@kQ\000\000\000\000\000\304\020R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\274kQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019548), "\002\000\000\000\004lQ\000\020lQ\000@kQ\000\000\000\000\000\360\020R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\364kQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019584), "(\021R\000@lQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019594), "\003\000\000\000PlQ\000`lQ\000\020lQ\000@kQ\000\000\000\000\000(\021R\000\002\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000@lQ", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000195D4), "\224\021R\000\220lQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000195E4), "\002\000\000\000\240lQ\000\254lQ\000\020fQ\000\000\000\000\000\224\021R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\220lQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019620), "0\027R\000\334lQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019630), "\002\000\000\000\354lQ\000\370lQ\000|eQ\000\000\000\000\0000\027R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\334lQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001966C), "T\027R\000(mQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001967C), "\002\000\000\0008mQ\000DmQ\000|eQ\000\000\000\000\000T\027R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000(mQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000196B8), "X\030R\000tmQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000196C8), "\002\000\000\000\204mQ\000\220mQ\000\254mQ\000\000\000\000\000X\030R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000tmQ\000p\030R", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019704), "\377\377\377\377\000\000\000\000@\000\000\000\310mQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001971C), "\001\000\000\000\330mQ\000\254mQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019738), "\364\031R\000\364mQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019748), "\002\000\000\000\004nQ\000\020nQ\000,nQ\000\000\000\000\000\364\031R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\364mQ\000\030\032R", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019784), "\377\377\377\377\000\000\000\000@\000\000\000HnQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001979C), "\001\000\000\000XnQ\000,nQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000197B8), "p\032R\000tnQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000197C8), "\002\000\000\000\204nQ\000\220nQ\000,nQ\000\000\000\000\000p\032R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000tnQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019804), "\330\032R\000\300nQ\000\000\000\000\000\001\000\000\000\003\000\000\000\320nQ\000\340nQ\000,nQ\000\374nQ\000\000\000\000\000\330\032R\000\002\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\300nQ\000\004\033R\000\000\000\000\000\231\001\000\000\377\377\377\377\000\000\000\000@\000\000\000\030oQ", 95u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001986C), "\001\000\000\000(oQ\0000oQ\000\000\000\000\000\004\033R", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019888), "\377\377\377\377\000\000\000\000@\000\000\000\030oQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000198A4), "X\033R\000`oQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000198B4), "\002\000\000\000poQ\000|oQ\000,nQ\000\000\000\000\000X\033R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000`oQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000198F0), "\260\033R\000\254oQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019900), "\003\000\000\000\274oQ\000\314oQ\000\350oQ\000,nQ\000\000\000\000\000\260\033R\000\002\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\254oQ\000\330\033R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\004pQ", 79u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019958), "\002\000\000\000\024pQ\000\350oQ\000,nQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019978), "0\034R\0004pQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019988), "\002\000\000\000DpQ\000PpQ\000,nQ\000\000\000\000\0000\034R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\0004pQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000199C4), "\314\034R\000\200pQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000199D4), "\002\000\000\000\220pQ\000\234pQ\000,nQ\000\000\000\000\000\314\034R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\200pQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019A10), "4\035R\000\314pQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019A20), "\002\000\000\000\334pQ\000\350pQ\000,nQ\000\000\000\000\0004\035R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\314pQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019A5C), "@\036R\000\030qQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019A6C), "\002\000\000\000(qQ\0004qQ\000PqQ\000\000\000\000\000@\036R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\030qQ\000|\036R", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019AA8), "\377\377\377\377\000\000\000\000@\000\000\000lqQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019AC0), "\001\000\000\000|qQ\000PqQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019AD4), "`\000\000\000\000\000\000\000\270\036R\000\230qQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019AEC), "\005\000\000\000\250qQ\000\300qQ\000\334qQ\000\034rQ\000\374rQ\000\030sQ\000\000\000\000\000\270\036R\000\004\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\230qQ\000\364\036R\000\003\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\370qQ", 87u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019B4C), "\004\000\000\000\010rQ\000\334qQ\000\034rQ\000\374rQ\000\030sQ\000\000\000\000\0000\037R\000\002", 33u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019B78), "\004\000\000\000P\000\000\0008rQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019B8C), "\003\000\000\000HrQ\000XrQ\000trQ\000\254rQ\000\000\000\000\0000\037R\000\002\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\0008rQ\000h\037R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\220rQ", 79u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019BE4), "\002\000\000\000\240rQ\000trQ\000\254rQ\000\000\000\000\000\204\037R\000\000\000\000\000\010\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\310rQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019C1C), "\001\000\000\000\330rQ\000\340rQ\000\000\000\000\000\204\037R", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019C38), "\377\377\377\377\000\000\000\000@\000\000\000\310rQ\000h\037R\000\001", 21u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019C58), "\004\000\000\000@\000\000\000\220rQ\000\204\037R\000\000\000\000\000\010\000\000\000\000\000\000\000\004\000\000\000@\000\000\000\310rQ\000\000\000\000\000h\000\000\000\000\000\000\000\240\037R\000HsQ", 59u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019C9C), "\005\000\000\000XsQ\000psQ\000\214sQ\000\034rQ\000\374rQ\000\030sQ\000\000\000\000\000\240\037R\000\004\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000HsQ\000\334\037R\000\003\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\250sQ", 87u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019CFC), "\004\000\000\000\270sQ\000\214sQ\000\034rQ\000\374rQ\000\030sQ", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019D24), "\030 R\000\340sQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019D34), "\002\000\000\000\360sQ\000\374sQ\000,nQ\000\000\000\000\000\030 R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\340sQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019D70), "D R\000,tQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019D80), "\002\000\000\000<tQ\000HtQ\000,nQ\000\000\000\000\000D R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000,tQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019DBC), "\370 R\000xtQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019DCC), "\002\000\000\000\210tQ\000\224tQ\000PqQ\000\000\000\000\000\370 R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000xtQ\000\000\000\000\000P\000\000\000\000\000\000\000H!R\000\304tQ", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019E18), "\005\000\000\000\324tQ\000\354tQ\000\334qQ\000\034rQ\000\374rQ\000\030sQ\000\000\000\000\000H!R\000\004\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\304tQ", 59u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019E60), "\234!R\000\034uQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019E70), "\002\000\000\000,uQ\0008uQ\000,nQ\000\000\000\000\000\234!R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\034uQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019EAC), "\330\033R\000\004pQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019EC0), " (R\000|uQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019ED0), "\002\000\000\000\214uQ\000\230uQ\000,nQ\000\000\000\000\000 (R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000|uQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019F0C), "\324(R\000\310uQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019F1C), "\003\000\000\000\330uQ\000\350uQ\000\004vQ\000,nQ\000\000\000\000\000\324(R\000\002\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\310uQ\000\370(R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000 vQ", 79u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019F74), "\002\000\000\0000vQ\000\004vQ\000,nQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019F94), "T)R\000PvQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019FA4), "\002\000\000\000`vQ\000lvQ\000,nQ\000\000\000\000\000T)R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000PvQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019FE0), "\264)R\000\234vQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00019FF0), "\002\000\000\000\254vQ\000\270vQ\000,nQ\000\000\000\000\000\264)R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\234vQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A02C), "\020*R\000\350vQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A03C), "\003\000\000\000\370vQ\000\010wQ\000\220nQ\000,nQ\000\000\000\000\000\020*R\000\002\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\350vQ", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A07C), "p*R\0008wQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A08C), "\002\000\000\000HwQ\000TwQ\000,nQ\000\000\000\000\000p*R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\0008wQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A0C8), "\314*R\000\204wQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A0D8), "\002\000\000\000\224wQ\000\240wQ\000,nQ\000\000\000\000\000\314*R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\204wQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A114), "(+R\000\320wQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A124), "\003\000\000\000\340wQ\000\360wQ\000\240wQ\000,nQ\000\000\000\000\000(+R\000\002\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\320wQ", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A164), "\204+R\000 xQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A174), "\002\000\000\0000xQ\000<xQ\000,nQ\000\000\000\000\000\204+R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000 xQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A1B0), "\030,R\000lxQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A1C0), "\002\000\000\000|xQ\000\210xQ\000,nQ\000\000\000\000\000\030,R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000lxQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A1FC), "x,R\000\270xQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A20C), "\002\000\000\000\310xQ\000\324xQ\000,nQ\000\000\000\000\000x,R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\270xQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A248), "\370(R\000 vQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A25C), "\010-R\000\030yQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A26C), "\002\000\000\000(yQ\0004yQ\000,nQ\000\000\000\000\000\010-R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\030yQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A2A8), "\030\032R\000HnQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A2BC), "\250-R\000xyQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A2CC), "\001\000\000\000\210yQ\000\220yQ\000\000\000\000\000\250-R", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A2E8), "\377\377\377\377\000\000\000\000@\000\000\000xyQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A304), "\300-R\000\300yQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A314), "\002\000\000\000\320yQ\000\334yQ\000\220yQ\000\000\000\000\000\300-R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\300yQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A350), "\340-R\000\014zQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A360), "\002\000\000\000\034zQ\000(zQ\000\220yQ\000\000\000\000\000\340-R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\014zQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A398), "\001\000\000\000TzQ\000\\zQ\000\000\000\000\000\000.R", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A3B4), "\377\377\377\377\000\000\000\000@\000\000\000DzQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A3CC), "\001\000\000\000\210zQ\000\220zQ\000\000\000\000\000$.R", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A3E8), "\377\377\377\377\000\000\000\000@\000\000\000xzQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A404), "X.R\000\300zQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A414), "\002\000\000\000\320zQ\000\334zQ\000\\zQ\000\000\000\000\000X.R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\300zQ", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A450), "|.R\000\014{Q", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A460), "\002\000\000\000\034{Q\000({Q\000\\zQ\000\000\000\000\000|.R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\014{Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A49C), "\240.R\000X{Q", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A4AC), "\002\000\000\000h{Q\000t{Q\000\\zQ\000\000\000\000\000\240.R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000X{Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A4E8), "\310.R\000\244{Q", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A4F8), "\002\000\000\000\264{Q\000\300{Q\000\220zQ\000\000\000\000\000\310.R\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000\244{Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A530), "\001\000\000\000\354{Q\000\364{Q\000\000\000\000\000TTR", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A54C), "\377\377\377\377\000\000\000\000@\000\000\000\334{Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A568), "pTR\000$|Q", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A578), "\002\000\000\0004|Q\000@|Q\000\364{Q\000\000\000\000\000pTR\000\001\000\000\000\000\000\000\000\377\377\377\377\000\000\000\000@\000\000\000$|Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A5B4), "\230TR\000p|Q", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A5C4), "\001\000\000\000\200|Q\000\210|Q\000\000\000\000\000\230TR", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A5E0), "\377\377\377\377\000\000\000\000@\000\000\000p|Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A608), "\240\033@\000\000\000\000\000\310|Q\000\002\000\000\000\324|Q\000\360|Q\000\000\000\000\000\000\000R\000\000\000\000\000\377\377\377\377\000\000\000\000\014\000\000\000\300 @\000\000\000\000\000\034\000R\000\000\000\000\000\377\377\377\377\000\000\000\000\014\000\000\0000\351N\000\377\377\377\377\320\367N\000\"\005\223\031\001\000\000\000\014}Q", 99u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A680), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A690), "\3442@\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A6A0), "l3@\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\001\000\000\000\000\000\000\000\001\000\000\000\000\000\000\000\"\005\223\031\004\000\000\000X}Q\000\002\000\000\000\234}Q", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A6E4), "\001\000\000\000\002\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000H}Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A704), "\003\000\000\000\001\000\000\0008}Q\000@", 13u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A71C), "+\204@\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A738), "\001\000\000\000\001\000\000\000\304}Q\000\"\005\223\031\002\000\000\000\324}Q\000\001\000\000\000\344}Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A764), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A774), "\332\216@\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A784), "\316\216@\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\"\005\223\031\004\000\000\000<~Q\000\002\000\000\000\200~Q", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A7C8), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A7D4), "\001\000\000\000\001\000\000\000,~Q\000\002\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000\034~Q\000\377\377\377\377`\370N\000\377\377\377\377h\370N\000\377\377\377\377p\370N\000\"\005\223\031\003\000\000\000\250~Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A82C), "\001\000\000\000\377\377\377\377\240\370N\000\"\005\223\031\001\000\000\000\344~Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A858), "\001\000\000\000\377\377\377\377\320\370N\000\"\005\223\031\001\000\000\000\020\177Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A884), "\001\000\000\000\377\377\377\377\000\371N\000\000\000\000\000\010\371N\000\"\005\223\031\002\000\000\000<\177Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A8B8), "\001\000\000\000\377\377\377\3770\371N\000\"\005\223\031\001\000\000\000p\177Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A8E4), "\001\000\000\000\377\377\377\377`\371N\000\"\005\223\031\001\000\000\000\234\177Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A910), "\001\000\000\000\377\377\377\377\220\371N\000\"\005\223\031\001\000\000\000\310\177Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A93C), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A94C), "\326\310@\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000\364\177Q\000\377\377\377\377\000\000\000\000\000\000\000\000\300\371N\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\030\200Q\000\001\000\000\000\004\200Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A99C), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A9AC), "\252\311@\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000T\200Q\000\377\377\377\377\000\000\000\000\000\000\000\000\360\371N\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000x\200Q\000\001\000\000\000d\200Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001A9FC), "\001\000\000\000\377\377\377\377\000\000\000\000\000\000\000\000 \372N\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\264\200Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AA38), "\001\000\000\000\377\377\377\377P\372N\000\377\377\377\377X\372N\000\"\005\223\031\002\000\000\000\360\200Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AA6C), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AA7C), "\"\376@\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000$\201Q\000\377\377\377\377\000\000\000\000\000\000\000\000\200\372N\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000H\201Q\000\001\000\000\0004\201Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AACC), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AADC), "\362\376@\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000\204\201Q\000\377\377\377\377\000\000\000\000\000\000\000\000\260\372N\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\250\201Q\000\001\000\000\000\224\201Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AB2C), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AB3C), "\304\377@\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000\344\201Q\000\377\377\377\377\000\000\000\000\000\000\000\000\340\372N\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\010\202Q\000\001\000\000\000\364\201Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AB8C), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AB9C), "\261\000A\000\000\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000D\202Q\000\377\377\377\377\000\000\000\000\000\000\000\000\020\373N\000\001\000\000\000!\373N\000\377\377\377\377\000\000\000\000\"\005\223\031\004\000\000\000h\202Q\000\001\000\000\000T\202Q", 75u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001ABF4), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AC04), "\220\001A\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000\254\202Q\000\377\377\377\377\000\000\000\000\000\000\000\000P\373N\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\320\202Q\000\001\000\000\000\274\202Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AC54), "\001\000\000\000\"\005\223\031\005\000\000\0000\203Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AC78), "\001\000\000\000\377\377\377\377\200\373N\000\377\377\377\377\210\373N\000\377\377\377\377\220\373N\000\002\000\000\000\230\373N\000\377\377\377\377\230\373N\000@", 45u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001ACB0), ".\005A\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001ACCC), "\001\000\000\000\001\000\000\000X\203Q\000\"\005\223\031\002\000\000\000h\203Q\000\001\000\000\000x\203Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001ACF8), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AD08), "\356\tA\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000\260\203Q\000\377\377\377\377\000\000\000\000\000\000\000\000\360\373N\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\324\203Q\000\001\000\000\000\300\203Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AD58), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AD68), "\316\nA\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000\020\204Q\000\377\377\377\377\000\000\000\000\000\000\000\000 \374N\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\0004\204Q\000\001\000\000\000 \204Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001ADB8), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001ADC8), "\260\013A\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000p\204Q\000\377\377\377\377\000\000\000\000\000\000\000\000P\374N\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\224\204Q\000\001\000\000\000\200\204Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AE18), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AE28), "\253\014A\000\000\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000\320\204Q\000\377\377\377\377\000\000\000\000\000\000\000\000\200\374N\000\001\000\000\000\221\374N\000\377\377\377\377\000\000\000\000\"\005\223\031\004\000\000\000\364\204Q\000\001\000\000\000\340\204Q", 75u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AE80), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AE90), "\234\rA\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\0008\205Q\000\377\377\377\377\000\000\000\000\000\000\000\000\300\374N\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\\\205Q\000\001\000\000\000H\205Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AEE0), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AEF0), "\203\016A\000\000\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000\230\205Q\000\377\377\377\377\000\000\000\000\000\000\000\000\360\374N\000\001\000\000\000\001\375N\000\377\377\377\377\000\000\000\000\"\005\223\031\004\000\000\000\274\205Q\000\001\000\000\000\250\205Q", 75u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AF48), "\001\000\000\000\377\377\377\3770\375N\000\377\377\377\3778\375N\000\377\377\377\377@\375N\000\"\005\223\031\003\000\000\000\000\206Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AF84), "\001\000\000\000\377\377\377\377p\375N\000\"\005\223\031\001\000\000\000<\206Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AFB0), "\001\000\000\000\377\377\377\377\240\375N\000\000\000\000\000\250\375N\000\"\005\223\031\002\000\000\000h\206Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001AFE4), "\001\000\000\000\377\377\377\377\320\375N\000\000\000\000\000\330\375N\000\"\005\223\031\002\000\000\000\234\206Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B018), "\001\000\000\000\377\377\377\377\000\376N\000\"\005\223\031\001\000\000\000\320\206Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B044), "\001\000\000\000\377\377\377\3770\376N\000\"\005\223\031\001\000\000\000\374\206Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B070), "\001\000\000\000\377\377\377\377`\376N\000\000\000\000\000h\376N\000\"\005\223\031\002\000\000\000(\207Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B0A4), "\001\000\000\000\377\377\377\377\240\376N\000\000\000\000\000\250\376N\000\000\000\000\000\260\376N\000\"\005\223\031\003\000\000\000\\\207Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B0E0), "\001\000\000\000\377\377\377\377\340\376N\000\000\000\000\000\350\376N\000\000\000\000\000\360\376N\000\"\005\223\031\003\000\000\000\230\207Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B11C), "\001\000\000\000\377\377\377\377 \377N\000\377\377\377\377(\377N\000\377\377\377\3770\377N\000\"\005\223\031\003\000\000\000\324\207Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B158), "\001\000\000\000\377\377\377\377`\377N\000\"\005\223\031\001\000\000\000\020\210Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B184), "\001\000\000\000\377\377\377\377\220\377N\000\000\000\000\000\230\377N\000\377\377\377\377\240\377N\000\377\377\377\377\250\377N\000\"\005\223\031\004\000\000\000<\210Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B1C8), "\001\000\000\000\377\377\377\377\320\377N\000\"\005\223\031\001\000\000\000\200\210Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B1F4), "\001\000\000\000\377\377\377\377\000\000O\000\"\005\223\031\001\000\000\000\254\210Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B220), "\001\000\000\000\377\377\377\3770\000O\000\000\000\000\0008\000O\000\"\005\223\031\002\000\000\000\330\210Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B254), "\001\000\000\000\377\377\377\377p\000O\000\000\000\000\000x\000O\000\000\000\000\000\200\000O\000\"\005\223\031\003\000\000\000\014\211Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B290), "\001\000\000\000\377\377\377\377\260\000O\000\000\000\000\000\270\000O\000\000\000\000\000\300\000O\000\"\005\223\031\003\000\000\000H\211Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B2CC), "\001\000\000\000\377\377\377\377\360\000O\000\377\377\377\377\370\000O\000\"\005\223\031\002\000\000\000\204\211Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B300), "\001\000\000\000\377\377\377\3770\001O\000\377\377\377\3778\001O\000\377\377\377\377@\001O\000\"\005\223\031\003\000\000\000\270\211Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B33C), "\001\000\000\000\377\377\377\377p\001O\000\000\000\000\000x\001O\000\000\000\000\000\200\001O\000\"\005\223\031\003\000\000\000\364\211Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B378), "\001\000\000\000\377\377\377\377\260\001O\000\377\377\377\377\270\001O\000\377\377\377\377\300\001O\000\"\005\223\031\003\000\000\0000\212Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B3B4), "\001\000\000\000\377\377\377\377\360\001O\000\"\005\223\031\001\000\000\000l\212Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B3E0), "\001\000\000\000\377\377\377\377 \002O\000\000\000\000\000(\002O\000\377\377\377\3770\002O\000\377\377\377\3778\002O\000\"\005\223\031\004\000\000\000\230\212Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B424), "\001\000\000\000\377\377\377\377p\002O\000\000\000\000\000x\002O\000\377\377\377\377\200\002O\000\377\377\377\377\210\002O\000\"\005\223\031\004\000\000\000\334\212Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B468), "\001\000\000\000\377\377\377\377\300\002O\000\000\000\000\000\310\002O\000\377\377\377\377\320\002O\000\377\377\377\377\330\002O\000\"\005\223\031\004\000\000\000 \213Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B4AC), "\001\000\000\000\377\377\377\377\020\003O\000\000\000\000\000\030\003O\000\"\005\223\031\002\000\000\000d\213Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B4E0), "\001\000\000\000\377\377\377\377@\003O\000\000\000\000\000H\003O\000\"\005\223\031\002\000\000\000\230\213Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B514), "\001\000\000\000\377\377\377\377p\003O\000\000\000\000\000x\003O\000\"\005\223\031\002\000\000\000\314\213Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B548), "\001\000\000\000\377\377\377\377\240\003O\000\377\377\377\377\253\003O\000\377\377\377\377\266\003O\000\377\377\377\377\301\003O\000\"\005\223\031\004\000\000\000\000\214Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B58C), "\001\000\000\000\377\377\377\377\360\003O\000\000\000\000\000\370\003O\000\"\005\223\031\002\000\000\000D\214Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B5C0), "\001\000\000\000\377\377\377\377 \004O\000\"\005\223\031\001\000\000\000x\214Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B5EC), "\001\000\000\000\377\377\377\377P\004O\000\000\000\000\000X\004O\000\"\005\223\031\002\000\000\000\244\214Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B620), "\001\000\000\000\377\377\377\377\200\004O\000\000\000\000\000\210\004O\000\"\005\223\031\002\000\000\000\330\214Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B654), "\001\000\000\000\377\377\377\377\260\004O\000\000\000\000\000\270\004O\000\"\005\223\031\002\000\000\000\014\215Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B688), "\001\000\000\000\377\377\377\377\340\004O\000\000\000\000\000\350\004O\000\"\005\223\031\002\000\000\000@\215Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B6BC), "\001\000\000\000\377\377\377\377\020\005O\000\000\000\000\000\030\005O\000\"\005\223\031\002\000\000\000t\215Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B6F0), "\001\000\000\000\377\377\377\377K\005O\000\377\377\377\377@\005O\000\"\005\223\031\002\000\000\000\250\215Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B724), "\001\000\000\000\377\377\377\377\200\005O\000\000\000\000\000\210\005O\000\"\005\223\031\002\000\000\000\334\215Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B758), "\001\000\000\000\377\377\377\377\260\005O\000\000\000\000\000\270\005O\000\"\005\223\031\002\000\000\000\020\216Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B78C), "\001\000\000\000\377\377\377\377\340\005O\000\000\000\000\000\350\005O\000\"\005\223\031\002\000\000\000D\216Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B7C0), "\001\000\000\000\377\377\377\377\020\006O\000\"\005\223\031\001\000\000\000x\216Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B7EC), "\001\000\000\000\377\377\377\377@\006O\000\000\000\000\000H\006O\000\001\000\000\000S\006O\000\000\000\000\000^\006O\000\"\005\223\031\004\000\000\000\244\216Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B830), "\001\000\000\000\377\377\377\377\220\006O\000\000\000\000\000\230\006O\000\001\000\000\000\243\006O\000\000\000\000\000\256\006O\000\"\005\223\031\004\000\000\000\350\216Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B874), "\001\000\000\000\377\377\377\377\340\006O\000\000\000\000\000\350\006O\000\001\000\000\000\363\006O\000\000\000\000\000\376\006O\000\"\005\223\031\004\000\000\000,\217Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B8B8), "\001\000\000\000\377\377\377\3770\007O\000\000\000\000\0008\007O\000\001\000\000\000C\007O\000\000\000\000\000N\007O\000\"\005\223\031\004\000\000\000p\217Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B8FC), "\001\000\000\000\377\377\377\377\200\007O\000\"\005\223\031\001\000\000\000\264\217Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B928), "\001\000\000\000\377\377\377\377\260\007O\000\000\000\000\000\270\007O\000\001\000\000\000\303\007O\000\000\000\000\000\316\007O\000\"\005\223\031\004\000\000\000\340\217Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B96C), "\001\000\000\000\377\377\377\377\000\010O\000\000\000\000\000\010\010O\000\001\000\000\000\023\010O\000\000\000\000\000\036\010O\000\"\005\223\031\004\000\000\000$\220Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B9B0), "\001\000\000\000\377\377\377\377P\010O\000\000\000\000\000X\010O\000\001\000\000\000c\010O\000\000\000\000\000n\010O\000\"\005\223\031\004\000\000\000h\220Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001B9F4), "\001\000\000\000\377\377\377\377\240\010O\000\000\000\000\000\250\010O\000\001\000\000\000\263\010O\000\000\000\000\000\276\010O\000\"\005\223\031\004\000\000\000\254\220Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BA38), "\001\000\000\000\377\377\377\377\360\010O\000\000\000\000\000\370\010O\000\001\000\000\000\003\tO\000\000\000\000\000\016\tO\000\"\005\223\031\004\000\000\000\360\220Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BA7C), "\001\000\000\000\377\377\377\377V\tO\000\377\377\377\377K\tO\000\377\377\377\377@\tO\000\"\005\223\031\003\000\000\0004\221Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BAB8), "\001\000\000\000\377\377\377\377\200\tO\000\000\000\000\000\210\tO\000\"\005\223\031\002\000\000\000p\221Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BAEC), "\001\000\000\000\377\377\377\377\260\tO\000\000\000\000\000\270\tO\000\"\005\223\031\002\000\000\000\244\221Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BB20), "\001\000\000\000\377\377\377\377\340\tO\000\"\005\223\031\001\000\000\000\330\221Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BB4C), "\001\000\000\000\377\377\377\377\020\nO\000\000\000\000\000\030\nO\000\"\005\223\031\002\000\000\000\004\222Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BB80), "\001\000\000\000\377\377\377\377@\nO\000\000\000\000\000H\nO\000\"\005\223\031\002\000\000\0008\222Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BBB4), "\001\000\000\000\"\005\223\031\005\000\000\000\220\222Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BBD8), "\001\000\000\000\377\377\377\377p\nO\000\377\377\377\377{\nO\000\377\377\377\377\206\nO\000\377\377\377\377\221\nO\000\377\377\377\377\234\nO\000\377\377\377\377\320\nO\000\"\005\223\031\001\000\000\000\270\222Q", 63u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BC2C), "\001\000\000\000\377\377\377\377\000\013O\000\"\005\223\031\001\000\000\000\344\222Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BC58), "\001\000\000\000\377\377\377\3770\013O\000\"\005\223\031\001\000\000\000\020\223Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BC84), "\001\000\000\000\377\377\377\377`\013O\000\"\005\223\031\001\000\000\000<\223Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BCB0), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BCC0), "\330\223Q\000\010\000\000\0008\000R\000\000\000\000\000\260\236A\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000x\223Q\000\377\377\377\377\000\000\000\000\000\000\000\000\240\013O\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\234\223Q\000\001\000\000\000\210\223Q", 83u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BD20), "\001\000\000\000\001\000\000\000\340\223Q\000\000\000\000\0008\000R\000\000\000\000\000\377\377\377\377\000\000\000\000\001\000\000\000\000\000\000\000\377\377\377\377\320\013O\000\"\005\223\031\001\000\000\000\374\223Q", 59u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BD70), "\001\000\000\000\377\377\377\377\000\014O\000\"\005\223\031\001\000\000\000(\224Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BD9C), "\001\000\000\000\377\377\377\3770\014O\000\377\377\377\377;\014O\000\"\005\223\031\002\000\000\000T\224Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BDD0), "\001\000\000\000\377\377\377\377\200\014O\000\"\005\223\031\001\000\000\000\210\224Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BDFC), "\001\000\000\000\377\377\377\377\300\014O\000\"\005\223\031\001\000\000\000\264\224Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BE28), "\001\000\000\000\"\005\223\031\005\000\000\000\004\225Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BE4C), "\001\000\000\000\377\377\377\377\360\014O\000\377\377\377\377\373\014O\000\377\377\377\377\006\rO\000\377\377\377\377\021\rO\000\377\377\377\377\034\rO\000\"\005\223\031\006\000\000\000P\225Q", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BE98), "\001\000\000\000\377\377\377\377P\rO\000\377\377\377\377^\rO\000\377\377\377\377l\rO\000\377\377\377\377z\rO\000\377\377\377\377\210\rO\000\377\377\377\377\226\rO\000\377\377\377\377\340\rO\000\"\005\223\031\001\000\000\000\200\225Q", 71u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BEF4), "\001\000\000\000\"\005\223\031\010\000\000\000\320\225Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BF18), "\001\000\000\000\377\377\377\377\020\016O\000\377\377\377\377\033\016O\000\377\377\377\377&\016O\000\377\377\377\3771\016O\000\377\377\377\377<\016O\000\377\377\377\377G\016O\000\377\377\377\377R\016O\000\377\377\377\377]\016O\000\377\377\377\377\220\016O\000\"\005\223\031\001\000\000\000\020\226Q", 87u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BF84), "\001\000\000\000\377\377\377\377\300\016O\000\"\005\223\031\001\000\000\000<\226Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BFB0), "\001\000\000\000\377\377\377\377\360\016O\000\"\005\223\031\001\000\000\000h\226Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001BFDC), "\001\000\000\000\377\377\377\377 \017O\000\"\005\223\031\001\000\000\000\224\226Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C008), "\001\000\000\000\377\377\377\377P\017O\000\"\005\223\031\001\000\000\000\300\226Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C034), "\001\000\000\000\377\377\377\377\200\017O\000\"\005\223\031\001\000\000\000\354\226Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C060), "\001\000\000\000\377\377\377\377\260\017O\000\"\005\223\031\001\000\000\000\030\227Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C08C), "\001\000\000\000\377\377\377\377\340\017O\000\377\377\377\377\353\017O\000\"\005\223\031\002\000\000\000D\227Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C0C0), "\001\000\000\000\377\377\377\377 \020O\000\"\005\223\031\001\000\000\000x\227Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C0EC), "\001\000\000\000\377\377\377\377P\020O\000\"\005\223\031\001\000\000\000\244\227Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C118), "\001\000\000\000\377\377\377\377\200\020O\000\"\005\223\031\001\000\000\000\320\227Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C144), "\001\000\000\000\377\377\377\377\300\020O\000\"\005\223\031\001\000\000\000\374\227Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C170), "\001\000\000\000\377\377\377\377\360\020O\000\"\005\223\031\001\000\000\000(\230Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C19C), "\001\000\000\000\377\377\377\377 \021O\000\377\377\377\377+\021O\000\"\005\223\031\002\000\000\000T\230Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C1D0), "\001\000\000\000\377\377\377\377p\021O\000\377\377\377\377~\021O\000\"\005\223\031\002\000\000\000\210\230Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C204), "\001\000\000\000\377\377\377\377\300\021O\000\000\000\000\000\310\021O\000\"\005\223\031\002\000\000\000\274\230Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C238), "\001\000\000\000\377\377\377\377\000\022O\000\"\005\223\031\001\000\000\000\360\230Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C264), "\001\000\000\000\377\377\377\3770\022O\000\000\000\000\0008\022O\000\"\005\223\031\002\000\000\000\034\231Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C298), "\001\000\000\000\377\377\377\377p\022O\000\"\005\223\031\001\000\000\000P\231Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C2C4), "\001\000\000\000\377\377\377\377\240\022O\000\000\000\000\000\250\022O\000\"\005\223\031\002\000\000\000|\231Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C2F8), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C308), "\300\231Q\000\001\000\000\000\310\231Q\000\000\000\000\000\324\025R\000\000\000\000\000\377\377\377\377\000\000\000\000\001\000\000\000\000\000\000\000\377\377\377\377\340\022O\000\000\000\000\000\350\022O\000\"\005\223\031\002\000\000\000\344\231Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C360), "\001\000\000\000\377\377\377\377 \023O\000\"\005\223\031\001\000\000\000\030\232Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C38C), "\001\000\000\000\"\005\223\031\007\000\000\000h\232Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C3B0), "\001\000\000\000\377\377\377\377P\023O\000\377\377\377\377[\023O\000\377\377\377\377f\023O\000\377\377\377\377q\023O\000\377\377\377\377|\023O\000\377\377\377\377\207\023O\000\377\377\377\377\222\023O\000\377\377\377\377\320\023O\000\000\000\000\000\333\023O\000\000\000\000\000\351\023O\000\"\005\223\031\003\000\000\000\240\232Q", 95u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C424), "\001\000\000\000\377\377\377\3770\024O\000\"\005\223\031\001\000\000\000\334\232Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C450), "\001\000\000\000\377\377\377\377`\024O\000\"\005\223\031\001\000\000\000\010\233Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C47C), "\001\000\000\000\377\377\377\377\220\024O\000\377\377\377\377\230\024O\000\"\005\223\031\002\000\000\0004\233Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C4B0), "\001\000\000\000\377\377\377\377\320\024O\000\"\005\223\031\001\000\000\000h\233Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C4DC), "\001\000\000\000\"\005\223\031\010\000\000\000\270\233Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C500), "\001\000\000\000\377\377\377\377\020\025O\000\377\377\377\377\036\025O\000\377\377\377\377,\025O\000\377\377\377\377:\025O\000\377\377\377\377H\025O\000\377\377\377\377V\025O\000\377\377\377\377d\025O\000\377\377\377\377r\025O\000\377\377\377\377\260\025O\000\"\005\223\031\001\000\000\000\370\233Q", 87u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C56C), "\001\000\000\000\377\377\377\377\340\025O\000\377\377\377\377\353\025O\000\"\005\223\031\002\000\000\000$\234Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C5A0), "\001\000\000\000\377\377\377\377 \026O\000\377\377\377\377+\026O\000\"\005\223\031\002\000\000\000X\234Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C5D4), "\001\000\000\000\377\377\377\377p\026O\000\"\005\223\031\001\000\000\000\214\234Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C600), "\001\000\000\000\377\377\377\377\260\026O\000\"\005\223\031\001\000\000\000\270\234Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C62C), "\001\000\000\000\377\377\377\377\360\026O\000\"\005\223\031\001\000\000\000\344\234Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C658), "\001\000\000\000\377\377\377\3770\027O\000\377\377\377\377>\027O\000\377\377\377\377L\027O\000\"\005\223\031\003\000\000\000\020\235Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C694), "\001\000\000\000\377\377\377\377\220\027O\000\"\005\223\031\001\000\000\000L\235Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C6C0), "\001\000\000\000\377\377\377\377\320\027O\000\"\005\223\031\001\000\000\000x\235Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C6EC), "\001\000\000\000\377\377\377\377\000\030O\000\"\005\223\031\001\000\000\000\244\235Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C718), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C728), "\215\363H\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C738), "]\362H\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\"\005\223\031\004\000\000\000\360\235Q\000\002\000\000\0004\236Q", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C77C), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C788), "\001\000\000\000\001\000\000\000\340\235Q\000\002\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000\320\235Q\000\377\377\377\377`\030O\000\000\000\000\000h\030O\000\"\005\223\031\002\000\000\000\\\236Q", 59u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C7D8), "\001\000\000\000\377\377\377\377\240\030O\000\"\005\223\031\001\000\000\000\220\236Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C804), "\001\000\000\000\377\377\377\377\320\030O\000\"\005\223\031\001\000\000\000\274\236Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C830), "\001\000\000\000\377\377\377\377\000\031O\000\"\005\223\031\001\000\000\000\350\236Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C85C), "\001\000\000\000\377\377\377\377P\031O\000\000\000\000\000i\031O\000\"\005\223\031\002\000\000\000\024\237Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C890), "\001\000\000\000\377\377\377\377\240\031O\000\"\005\223\031\001\000\000\000H\237Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C8BC), "\001\000\000\000\377\377\377\377\340\031O\000\"\005\223\031\001\000\000\000t\237Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C8E8), "\001\000\000\000\377\377\377\377 \032O\000\000\000\000\000(\032O\000\001\000\000\000A\032O\000\"\005\223\031\003\000\000\000\240\237Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C924), "\001\000\000\000\377\377\377\377\220\032O\000\000\000\000\000\230\032O\000\"\005\223\031\002\000\000\000\334\237Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C958), "\001\000\000\000\"\005\223\031\020\000\000\0004\240Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001C97C), "\001\000\000\000\377\377\377\377\320\032O\000\000\000\000\000\330\032O\000\001\000\000\000\340\032O\000\002\000\000\000\353\032O\000\003\000\000\000\363\032O\000\004\000\000\000\376\032O\000\005\000\000\000\t\033O\000\006\000\000\000\024\033O\000\007\000\000\000\034\033O\000\006\000\000\000'\033O\000\006\000\000\000/\033O\000\006\000\000\000=\033O\000\006\000\000\000E\033O\000\004\000\000\000S\033O\000\r\000\000\000[\033O\000\004\000\000\000f\033O\000\"\005\223\031\022\000\000\000\330\240Q", 143u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CA20), "\001\000\000\000\377\377\377\377\260\033O\000\000\000\000\000\273\033O\000\001\000\000\000D\034O\000\001\000\000\000O\034O\000\001\000\000\000\306\033O\000\004\000\000\000\321\033O\000\005\000\000\000\334\033O\000\006\000\000\000\347\033O\000\007\000\000\000\362\033O\000\010\000\000\000\375\033O\000\t\000\000\000\010\034O\000\n\000\000\000\020\034O\000\013\000\000\000\033\034O\000\014\000\000\000&\034O\000\r\000\000\0001\034O\000\001\000\000\000<\034O\000\001\000\000\000W\034O\000\001\000\000\000b\034O\000\377\377\377\377\240\034O\000\"\005\223\031\001\000\000\000h\241Q", 167u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CADC), "\001\000\000\000\377\377\377\377\340\034O\000\000\000\000\000\350\034O\000\001\000\000\000\360\034O\000\"\005\223\031\003\000\000\000\224\241Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CB18), "\001\000\000\000\"\005\223\031\010\000\000\000\364\241Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CB3C), "\001\000\000\000\377\377\377\3770\035O\000\377\377\377\377;\035O\000\001\000\000\000C\035O\000\001\000\000\000K\035O\000\001\000\000\000V\035O\000\001\000\000\000^\035O\000\001\000\000\000i\035O\000\377\377\377\377t\035O\000\"\005\223\031\006\000\000\000X\242Q", 79u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CBA0), "\001\000\000\000\377\377\377\377\260\035O\000\377\377\377\377\274\035O\000\001\000\000\000\307\035O\000\002\000\000\000\317\035O\000\001\000\000\000\327\035O\000\004\000\000\000\337\035O\000\"\005\223\031\005\000\000\000\254\242Q", 63u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CBF4), "\001\000\000\000\377\377\377\377 \036O\000\377\377\377\377)\036O\000\001\000\000\0001\036O\000\001\000\000\0009\036O\000\001\000\000\000A\036O\000\"\005\223\031\022\000\000\000\370\242Q", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CC40), "\001\000\000\000\377\377\377\377\200\036O\000\000\000\000\000\210\036O\000\001\000\000\000\220\036O\000\002\000\000\000\230\036O\000\003\000\000\000\243\036O\000\004\000\000\000\256\036O\000\005\000\000\000\271\036O\000\006\000\000\000\301\036O\000\007\000\000\000\314\036O\000\010\000\000\000\327\036O\000\t\000\000\000\337\036O\000\n\000\000\000\352\036O\000\013\000\000\000\365\036O\000\014\000\000\000\000\037O\000\r\000\000\000\010\037O\000\016\000\000\000\023\037O\000\017\000\000\000\033\037O\000\020\000\000\000&\037O\000\"\005\223\031\005\000\000\000\254\243Q", 159u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CCF4), "\001\000\000\000\377\377\377\377`\037O\000\000\000\000\000h\037O\000\000\000\000\000t\037O\000\002\000\000\000\177\037O\000\003\000\000\000\207\037O\000\"\005\223\031\010\000\000\000\370\243Q", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CD40), "\001\000\000\000\377\377\377\377\300\037O\000\000\000\000\000\310\037O\000\000\000\000\000\324\037O\000\002\000\000\000\337\037O\000\003\000\000\000\347\037O\000\004\000\000\000\357\037O\000\004\000\000\000\367\037O\000\006\000\000\000\377\037O\000\"\005\223\031\006\000\000\000\\\244Q", 79u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CDA4), "\001\000\000\000\377\377\377\377@ O\000\000\000\000\000H O\000\000\000\000\000T O\000\002\000\000\000_ O\000\003\000\000\000g O\000\004\000\000\000o O\000\377\377\377\377\260 O\000\"\005\223\031\001\000\000\000\214\244Q", 71u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CE00), "\001\000\000\000\377\377\377\377\340 O\000\"\005\223\031\001\000\000\000\270\244Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CE2C), "\001\000\000\000\377\377\377\377 !O\000\"\005\223\031\001\000\000\000\344\244Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CE58), "\001\000\000\000\377\377\377\377P!O\000\"\005\223\031\001\000\000\000\020\245Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CE84), "\001\000\000\000\377\377\377\377\200!O\000\"\005\223\031\001\000\000\000<\245Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CEB0), "\001\000\000\000\377\377\377\377\300!O\000\"\005\223\031\001\000\000\000h\245Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CEDC), "\001\000\000\000\377\377\377\377\000\"O\000\"\005\223\031\001\000\000\000\224\245Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CF08), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CF18), "\320\245Q\000\001\000\000\000\330\245Q\000\000\000\000\000x\031R\000\000\000\000\000\377\377\377\377\000\000\000\000\001\000\000\000\000\000\000\000\377\377\377\3770\"O\000\"\005\223\031\001\000\000\000\364\245Q", 59u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CF68), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CF78), "\253\335I\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CF94), "\001\000\000\000\001\000\000\000 \246Q\000\"\005\223\031\002\000\000\0000\246Q\000\001\000\000\000@\246Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CFC0), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CFD0), "\203\336I\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001CFEC), "\001\000\000\000\001\000\000\000x\246Q\000\"\005\223\031\002\000\000\000\210\246Q\000\001\000\000\000\230\246Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D018), "\001\000\000\000\377\377\377\377\240\"O\000\"\005\223\031\001\000\000\000\320\246Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D044), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D054), "\271\003J\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D070), "\001\000\000\000\001\000\000\000\374\246Q\000\"\005\223\031\002\000\000\000\014\247Q\000\001\000\000\000\034\247Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D09C), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D0AC), "\344\006J\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D0BC), "/\005J\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\"\005\223\031\004\000\000\000t\247Q\000\002\000\000\000\270\247Q", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D100), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D10C), "\001\000\000\000\001\000\000\000d\247Q\000\002\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000T\247Q\000\377\377\377\377 #O\000\"\005\223\031\001\000\000\000\340\247Q", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D154), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D164), "\261>J\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000\014\250Q\000\377\377\377\377\000\000\000\000\000\000\000\000P#O\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\0000\250Q\000\001\000\000\000\034\250Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D1B4), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D1C4), "\261?J\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000l\250Q\000\377\377\377\377\000\000\000\000\000\000\000\000\200#O\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\220\250Q\000\001\000\000\000|\250Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D214), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D224), "\372@J\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D240), "\001\000\000\000\001\000\000\000\314\250Q\000\"\005\223\031\002\000\000\000\334\250Q\000\001\000\000\000\354\250Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D26C), "\001\000\000\000\377\377\377\377\320#O\000\377\377\377\377\330#O\000\"\005\223\031\002\000\000\000$\251Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D2A0), "\001\000\000\000\377\377\377\377\020$O\000\"\005\223\031\001\000\000\000X\251Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D2CC), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D2DC), "IkJ\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D2F8), "\001\000\000\000\001\000\000\000\204\251Q\000\"\005\223\031\002\000\000\000\224\251Q\000\001\000\000\000\244\251Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D324), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D334), "\337wJ\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D350), "\001\000\000\000\001\000\000\000\334\251Q\000\"\005\223\031\002\000\000\000\354\251Q\000\001\000\000\000\374\251Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D37C), "\001\000\000\000\377\377\377\377\200$O\000\000\000\000\000\213$O\000\001\000\000\000\226$O\000\002\000\000\000\241$O\000\"\005\223\031\004\000\000\0004\252Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D3C0), "\001\000\000\000\377\377\377\377\320$O\000\000\000\000\000\333$O\000\001\000\000\000\346$O\000\002\000\000\000\361$O\000\"\005\223\031\004\000\000\000x\252Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D404), "\001\000\000\000\377\377\377\377 %O\000\"\005\223\031\001\000\000\000\274\252Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D430), "\001\000\000\000\377\377\377\377P%O\000\"\005\223\031\001\000\000\000\350\252Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D45C), "\001\000\000\000\377\377\377\377\200%O\000\"\005\223\031\001\000\000\000\024\253Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D488), "\001\000\000\000\377\377\377\377\260%O\000\"\005\223\031\001\000\000\000@\253Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D4B4), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D4C4), "\262\243J\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D4E0), "\001\000\000\000\001\000\000\000l\253Q\000\"\005\223\031\002\000\000\000|\253Q\000\001\000\000\000\214\253Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D50C), "\001\000\000\000\"\005\223\031\t\000\000\000\350\253Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D530), "\001\000\000\000\377\377\377\377\000&O\000\000\000\000\000\010&O\000\001\000\000\000\026&O\000\002\000\000\000$&O\000\003\000\000\0002&O\000\004\000\000\000@&O\000\005\000\000\000N&O\000\006\000\000\000\\&O\000\000\000\000\000j&O\000@", 77u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D588), "\023\253J\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D5A4), "\001\000\000\000\001\000\000\0000\254Q\000\"\005\223\031\002\000\000\000@\254Q\000\001\000\000\000P\254Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D5D0), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D5E0), "\235\255J\000\002\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000\210\254Q\000\377\377\377\377\260&O\000\377\377\377\377\271&O\000\001\000\000\000\000\000\000\000\001\000\000\000\000\000\000\000\"\005\223\031\004\000\000\000\254\254Q\000\001\000\000\000\230\254Q", 75u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D638), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D648), "]\260J\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D664), "\001\000\000\000\001\000\000\000\360\254Q\000\"\005\223\031\002\000\000\000\000\255Q\000\001\000\000\000\020\255Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D690), "\001\000\000\000\377\377\377\377\000'O\000\"\005\223\031\001\000\000\000H\255Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D6BC), "\001\000\000\000\377\377\377\3770'O\000\000\000\000\0008'O\000\001\000\000\000C'O\000\"\005\223\031\003\000\000\000t\255Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D6F8), "\001\000\000\000\377\377\377\377p'O\000\"\005\223\031\001\000\000\000\260\255Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D724), "\001\000\000\000\"\005\223\031\t\000\000\000\000\256Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D748), "\001\000\000\000\377\377\377\377\367'O\000\377\377\377\377\002(O\000\377\377\377\377\260'O\000\377\377\377\377\273'O\000\003\000\000\000\306'O\000\004\000\000\000\321'O\000\377\377\377\377\331'O\000\006\000\000\000\344'O\000\007\000\000\000\357'O\000\377\377\377\377@(O\000\"\005\223\031\001\000\000\000H\256Q", 95u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D7BC), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D7CC), "%\313J\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D7DC), "\372\311J\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\"\005\223\031\004\000\000\000\224\256Q\000\002\000\000\000\330\256Q", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D820), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D82C), "\001\000\000\000\001\000\000\000\204\256Q\000\002\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000t\256Q\000\377\377\377\377\220(O\000\"\005\223\031\001\000\000\000\000\257Q", 51u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D874), "\001\000\000\000\377\377\377\377\320(O\000\"\005\223\031\001\000\000\000,\257Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D8A0), "\001\000\000\000\"\005\223\031\t\000\000\000|\257Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D8C4), "\001\000\000\000\377\377\377\377\000)O\000\000\000\000\000\010)O\000\000\000\000\000\021)O\000\002\000\000\000\037)O\000\003\000\000\000-)O\000\004\000\000\000;)O\000\005\000\000\000I)O\000\006\000\000\000W)O\000\007\000\000\000e)O\000\377\377\377\377\220)O\000\377\377\377\377\230)O\000\001\000\000\000\243)O\000\377\377\377\377\243)O\000\"\005\223\031\004\000\000\000\304\257Q", 119u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D950), "\001\000\000\000\"\005\223\031\025\000\000\000,\260Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001D974), "\001\000\000\000\377\377\377\377\360)O\000\377\377\377\377\370)O\000\001\000\000\000\000*O\000\002\000\000\000\013*O\000\002\000\000\000\023*O\000\004\000\000\000\036*O\000\002\000\000\000\036*O\000\006\000\000\000&*O\000\007\000\000\000.*O\000\007\000\000\0006*O\000\t\000\000\000>*O\000\007\000\000\000>*O\000\013\000\000\000I*O\000\007\000\000\000W*O\000\007\000\000\000e*O\000\007\000\000\000{*O\000\007\000\000\000s*O\000\007\000\000\000\211*O\000\021\000\000\000\221*O\000\007\000\000\000\221*O\000\023\000\000\000\234*O\000\"\005\223\031\005\000\000\000\370\260Q", 183u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DA40), "\001\000\000\000\377\377\377\377\340*O\000\000\000\000\000\350*O\000\001\000\000\000\363*O\000\001\000\000\000\374*O\000\003\000\000\000\007+O\000\"\005\223\031\010\000\000\000D\261Q", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DA8C), "\001\000\000\000\377\377\377\3770+O\000\377\377\377\377<+O\000\001\000\000\000G+O\000\002\000\000\000O+O\000\003\000\000\000Z+O\000\001\000\000\000b+O\000\005\000\000\000j+O\000\006\000\000\000u+O\000\377\377\377\377\260+O\000\377\377\377\377\271+O\000\"\005\223\031\002\000\000\000\204\261Q", 95u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DB00), "\001\000\000\000\377\377\377\377\340+O\000\"\005\223\031\001\000\000\000\270\261Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DB2C), "\001\000\000\000\377\377\377\377@,O\000\000\000\000\000H,O\000\"\005\223\031\002\000\000\000\344\261Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DB60), "\001\000\000\000\377\377\377\377\200,O\000\000\000\000\000\210,O\000\"\005\223\031\002\000\000\000\030\262Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DB94), "\001\000\000\000\377\377\377\377\260,O\000\377\377\377\377\273,O\000\"\005\223\031\002\000\000\000L\262Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DBC8), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DBD8), "\265\rK\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DBE8), "\212\014K\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\"\005\223\031\004\000\000\000\240\262Q\000\002\000\000\000\344\262Q", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DC2C), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DC38), "\001\000\000\000\001\000\000\000\220\262Q\000\002\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000\200\262Q\000\377\377\377\377\020-O\000\377\377\377\377\033-O\000\"\005\223\031\002\000\000\000\014\263Q", 59u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DC88), "\001\000\000\000\000\000\000\0000\356N\000\000\000\000\000|\263Q\000\377\377\377\377P-O\000\"\005\223\031\001\000\000\000P\263Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DCC4), "\001\000\000\000\002\000\000\000\210\263Q\000\360|Q\000\000\000\000\000$\036R\000\000\000\000\000\377\377\377\377\000\000\000\000\014\000\000\0006\356N\000\377\377\377\377\200-O\000\"\005\223\031\001\000\000\000\244\263Q", 63u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DD18), "\001\000\000\000\377\377\377\377\260-O\000\"\005\223\031\001\000\000\000\320\263Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DD44), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DD54), "\205\034K\000\002\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000\374\263Q\000\"\005\223\031\005\000\000\000D\264Q\000\001\000\000\000\014\264Q", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DD8C), "\001\000\000\000\377\377\377\377\340-O\000\377\377\377\377\350-O\000\001\000\000\000\000\000\000\000\001\000\000\000\000\000\000\000\377\377\377\377\360-O\000@", 45u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DDC4), "\324\036K\000\002\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000l\264Q\000\"\005\223\031\005\000\000\000\264\264Q\000\001\000\000\000|\264Q", 43u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DDFC), "\001\000\000\000\377\377\377\377 .O\000\377\377\377\377(.O\000\001\000\000\000\000\000\000\000\001\000\000\000\000\000\000\000\377\377\377\3770.O\000@", 45u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DE34), "\236%K\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DE50), "\001\000\000\000\001\000\000\000\334\264Q\000\"\005\223\031\002\000\000\000\354\264Q\000\001\000\000\000\374\264Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DE7C), "\001\000\000\000\377\377\377\377\200.O\000\"\005\223\031\001\000\000\0004\265Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DEA8), "\001\000\000\000\377\377\377\377\260.O\000\"\005\223\031\001\000\000\000`\265Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DED4), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DEE4), "e.K\000\002\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000\214\265Q\000\377\377\377\377\340.O\000\377\377\377\377\350.O\000\001\000\000\000\000\000\000\000\001\000\000\000\000\000\000\000\"\005\223\031\004\000\000\000\260\265Q\000\001\000\000\000\234\265Q", 75u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DF3C), "\001\000\000\000\377\377\377\377\020/O\000\000\000\000\000\030/O\000\377\377\377\377\030/O\000\"\005\223\031\003\000\000\000\364\265Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DF78), "\001\000\000\000\377\377\377\377P/O\000\000\000\000\000X/O\000\377\377\377\377X/O\000\"\005\223\031\003\000\000\0000\266Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DFB4), "\001\000\000\000\377\377\377\377\220/O\000\"\005\223\031\001\000\000\000l\266Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001DFE0), "\001\000\000\000\377\377\377\377\300/O\000\"\005\223\031\001\000\000\000\230\266Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E00C), "\001\000\000\000\377\377\377\377\360/O\000\000\000\000\000\r0O\000\001\000\000\000\0310O\000\"\005\223\031\003\000\000\000\304\266Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E048), "\001\000\000\000\377\377\377\377@0O\000\000\000\000\000L0O\000\"\005\223\031\002\000\000\000\000\267Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E07C), "\001\000\000\000\377\377\377\377p0O\000\"\005\223\031\001\000\000\0004\267Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E0A8), "\001\000\000\000\377\377\377\377\2400O\000\377\377\377\377\2500O\000\001\000\000\000\2630O\000\377\377\377\377\2630O\000\"\005\223\031\004\000\000\000`\267Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E0EC), "\001\000\000\000\377\377\377\377\0001O\000\"\005\223\031\001\000\000\000\244\267Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E118), "\001\000\000\000\377\377\377\377@1O\000\377\377\377\377L1O\000\001\000\000\000W1O\000\002\000\000\000_1O\000\"\005\223\031\004\000\000\000\320\267Q", 47u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E15C), "\001\000\000\000\377\377\377\377\2401O\000\"\005\223\031\001\000\000\000\024\270Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E188), "\001\000\000\000\377\377\377\377\3201O\000\000\000\000\000\3551O\000\001\000\000\000\3711O\000\"\005\223\031\003\000\000\000@\270Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E1C4), "\001\000\000\000\377\377\377\377 2O\000\000\000\000\000,2O\000\"\005\223\031\002\000\000\000|\270Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E1F8), "\001\000\000\000\"\005\223\031\007\000\000\000\324\270Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E21C), "\001\000\000\000\377\377\377\377P2O\000\000\000\000\000X2O\000\000\000\000\000a2O\000\002\000\000\000o2O\000\003\000\000\000}2O\000\004\000\000\000\2132O\000\005\000\000\000\2312O\000\"\005\223\031\010\000\000\0000\271Q", 71u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E278), "\001\000\000\000\377\377\377\377\3002O\000\000\000\000\000\3102O\000\001\000\000\000\3202O\000\002\000\000\000\3302O\000\001\000\000\000\3302O\000\000\000\000\000\3302O\000\377\377\377\377\3302O\000\006\000\000\000\3402O\000\"\005\223\031\005\000\000\000\224\271Q", 79u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E2DC), "\001\000\000\000\377\377\377\377 3O\000\000\000\000\000B3O\000\001\000\000\000J3O\000\002\000\000\000U3O\000\003\000\000\000]3O\000\"\005\223\031\022\000\000\000\340\271Q", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E328), "\001\000\000\000\377\377\377\377\2403O\000\000\000\000\000\2533O\000\001\000\000\000\2663O\000\002\000\000\000\3013O\000\003\000\000\000\3143O\000\004\000\000\000\3273O\000\005\000\000\000\3373O\000\006\000\000\000\3473O\000\007\000\000\000\3573O\000\006\000\000\000\3573O\000\005\000\000\000\3573O\000\004\000\000\000\3573O\000\003\000\000\000\3573O\000\002\000\000\000\3573O\000\001\000\000\000\3573O\000\000\000\000\000\3573O\000\017\000\000\000\3673O\000\020\000\000\000\0024O\000\"\005\223\031\022\000\000\000\224\272Q", 159u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E3DC), "\001\000\000\000\377\377\377\377@4O\000\000\000\000\000K4O\000\001\000\000\000V4O\000\002\000\000\000^4O\000\003\000\000\000i4O\000\004\000\000\000t4O\000\005\000\000\000|4O\000\006\000\000\000\2074O\000\007\000\000\000\2174O\000\006\000\000\000\2174O\000\005\000\000\000\2174O\000\004\000\000\000\2174O\000\003\000\000\000\2174O\000\002\000\000\000\2174O\000\001\000\000\000\2174O\000\000\000\000\000\2174O\000\017\000\000\000\2324O\000\020\000\000\000\2454O\000\"\005\223\031\007\000\000\000H\273Q", 159u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E490), "\001\000\000\000\377\377\377\377\3404O\000\000\000\000\000\3504O\000\001\000\000\000\3664O\000\002\000\000\000\0045O\000\003\000\000\000\0225O\000\004\000\000\000 5O\000\001\000\000\000.5O\000\"\005\223\031\010\000\000\000\244\273Q", 71u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E4EC), "\001\000\000\000\377\377\377\377`5O\000\000\000\000\000k5O\000\000\000\000\000v5O\000\000\000\000\000\2015O\000\377\377\377\377\2145O\000\004\000\000\000\2275O\000\004\000\000\000\2425O\000\004\000\000\000\2555O\000\377\377\377\377\3605O\000\377\377\377\377\3705O\000\"\005\223\031\002\000\000\000\344\273Q", 95u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E560), "\001\000\000\000\"\005\223\031\010\000\000\000<\274Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E584), "\001\000\000\000\377\377\377\37706O\000\000\000\000\00086O\000\000\000\000\000A6O\000\002\000\000\000O6O\000\003\000\000\000]6O\000\004\000\000\000k6O\000\005\000\000\000y6O\000\005\000\000\000\2026O\000\377\377\377\377\2606O\000\"\005\223\031\001\000\000\000|\274Q", 87u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E5F0), "\001\000\000\000\377\377\377\377\3406O\000\"\005\223\031\001\000\000\000\250\274Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E61C), "\001\000\000\000\377\377\377\377\0207O\000\377\377\377\377\0337O\000\"\005\223\031\002\000\000\000\324\274Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E650), "\001\000\000\000\377\377\377\377P7O\000\"\005\223\031\001\000\000\000\010\275Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E67C), "\001\000\000\000\377\377\377\377\2007O\000\377\377\377\377\2167O\000\"\005\223\031\002\000\000\0004\275Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E6B0), "\001\000\000\000\377\377\377\377\3007O\000\000\000\000\000\3217O\000\"\005\223\031\002\000\000\000h\275Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E6E4), "\001\000\000\000\377\377\377\377\0008O\000\000\000\000\000\0218O\000\"\005\223\031\002\000\000\000\234\275Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E718), "\001\000\000\000\377\377\377\377@8O\000\"\005\223\031\001\000\000\000\320\275Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E744), "\001\000\000\000\377\377\377\377\2008O\000\"\005\223\031\001\000\000\000\374\275Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E770), "\001\000\000\000\377\377\377\377\2608O\000\"\005\223\031\001\000\000\000(\276Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E79C), "\001\000\000\000\377\377\377\377\3608O\000\000\000\000\000\3708O\000\"\005\223\031\002\000\000\000T\276Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E7D0), "\001\000\000\000\377\377\377\37709O\000\377\377\377\37789O\000\377\377\377\377@9O\000\"\005\223\031\003\000\000\000\210\276Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E80C), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E81C), "\233\277K\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000\304\276Q\000\377\377\377\377\000\000\000\000\000\000\000\000p9O\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\350\276Q\000\001\000\000\000\324\276Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E86C), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E87C), "\364\300K\000\000\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000$\277Q\000\377\377\377\377\000\000\000\000\000\000\000\000\2409O\000\001\000\000\000\2619O\000\377\377\377\377\000\000\000\000\"\005\223\031\004\000\000\000H\277Q\000\001\000\000\0004\277Q", 75u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E8D4), "\001\000\000\000\"\005\223\031\005\000\000\000\260\277Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E8F8), "\001\000\000\000\377\377\377\377#:O\000\000\000\000\000\3409O\000\001\000\000\000\000:O\000\002\000\000\000\014:O\000\000\000\000\000\030:O\000\377\377\377\377p:O\000\000\000\000\000{:O\000\001\000\000\000\206:O\000\"\005\223\031\003\000\000\000\330\277Q", 79u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E95C), "\001\000\000\000\377\377\377\377\300:O\000\"\005\223\031\001\000\000\000\024\300Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E988), "\001\000\000\000\377\377\377\377\360:O\000\"\005\223\031\001\000\000\000@\300Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E9B4), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E9C4), ">\311K\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001E9E0), "\001\000\000\000\001\000\000\000l\300Q\000\"\005\223\031\002\000\000\000|\300Q\000\001\000\000\000\214\300Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EA0C), "\001\000\000\000\377\377\377\377@;O\000\000\000\000\000H;O\000\000\000\000\000V;O\000\"\005\223\031\003\000\000\000\304\300Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EA48), "\001\000\000\000\377\377\377\377\220;O\000\"\005\223\031\001\000\000\000\000\301Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EA74), "\001\000\000\000\377\377\377\377\300;O\000\000\000\000\000\310;O\000\"\005\223\031\002\000\000\000,\301Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EAA8), "\001\000\000\000\377\377\377\377\000<O\000\"\005\223\031\001\000\000\000`\301Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EAD4), "\001\000\000\000\377\377\377\3770<O\000\"\005\223\031\001\000\000\000\214\301Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EB00), "\001\000\000\000\377\377\377\377`<O\000\000\000\000\000h<O\000\"\005\223\031\002\000\000\000\270\301Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EB34), "\001\000\000\000\377\377\377\377\240<O\000\377\377\377\377\250<O\000\"\005\223\031\002\000\000\000\354\301Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EB68), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EB78), "k$L\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000 \302Q\000\377\377\377\377\000\000\000\000\000\000\000\000\340<O\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000D\302Q\000\001\000\000\0000\302Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EBC8), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EBD8), "k%L\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000\200\302Q\000\377\377\377\377\000\000\000\000\000\000\000\000\020=O\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\244\302Q\000\001\000\000\000\220\302Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EC28), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EC38), "\225&L\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EC54), "\001\000\000\000\001\000\000\000\340\302Q\000\"\005\223\031\002\000\000\000\360\302Q\000\001\000\000\000\000\303Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EC80), "\001\000\000\000\377\377\377\377`=O\000\377\377\377\377q=O\000\"\005\223\031\002\000\000\0008\303Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001ECB4), "\001\000\000\000\377\377\377\377\240=O\000\"\005\223\031\001\000\000\000l\303Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001ECE0), "\001\000\000\000\377\377\377\377\320=O\000\000\000\000\000\333=O\000\001\000\000\000\343=O\000\"\005\223\031\003\000\000\000\230\303Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001ED1C), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001ED2C), "\3451L\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000\324\303Q\000\377\377\377\377\000\000\000\000\000\000\000\000\020>O\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\370\303Q\000\001\000\000\000\344\303Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001ED7C), "\001\000\000\000\377\377\377\377@>O\000\"\005\223\031\001\000\000\0004\304Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EDA8), "\001\000\000\000\377\377\377\377p>O\000\"\005\223\031\001\000\000\000`\304Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EDD4), "\001\000\000\000\377\377\377\377\000\000\000\000\"\005\223\031\001\000\000\000\214\304Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EE00), "\001\000\000\000\377\377\377\377\320>O\000\000\000\000\000\330>O\000\"\005\223\031\002\000\000\000\270\304Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EE34), "\001\000\000\000\377\377\377\377\020?O\000\377\377\377\377!?O\000\"\005\223\031\002\000\000\000\354\304Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EE68), "\001\000\000\000\377\377\377\377P?O\000\"\005\223\031\001\000\000\000 \305Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EE94), "\001\000\000\000\377\377\377\377\200?O\000\"\005\223\031\001\000\000\000L\305Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EEC0), "\001\000\000\000\377\377\377\377\260?O\000\000\000\000\000\270?O\000\001\000\000\000\306?O\000\"\005\223\031\003\000\000\000x\305Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EEFC), "\001\000\000\000\377\377\377\377\000@O\000\000\000\000\000\010@O\000\"\005\223\031\002\000\000\000\264\305Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EF30), "\001\000\000\000\377\377\377\377@@O\000\"\005\223\031\001\000\000\000\350\305Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EF5C), "\001\000\000\000\377\377\377\377p@O\000\000\000\000\000x@O\000\001\000\000\000\206@O\000\"\005\223\031\003\000\000\000\024\306Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EF98), "\001\000\000\000\377\377\377\377\260@O\000\377\377\377\377\273@O\000\377\377\377\377\306@O\000\"\005\223\031\003\000\000\000P\306Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EFD4), "\001\000\000\000@", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001EFE4), "\345\240L\000\377\377\377\377\000\000\000\000\377\377\377\377", 16u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F000), "\001\000\000\000\001\000\000\000\214\306Q\000\"\005\223\031\002\000\000\000\234\306Q\000\001\000\000\000\254\306Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F02C), "\001\000\000\000\377\377\377\377 AO\000\"\005\223\031\001\000\000\000\344\306Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F058), "\001\000\000\000\377\377\377\377PAO\000\"\005\223\031\001\000\000\000\020\307Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F084), "\001\000\000\000\377\377\377\377\200AO\000\"\005\223\031\001\000\000\000<\307Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F0B0), "\001\000\000\000\377\377\377\377\260AO\000\000\000\000\000\270AO\000\"\005\223\031\002\000\000\000h\307Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F0E4), "\001\000\000\000\t\000\000\000x\031R\000\000\000\000\000L\013M\000\t\000\000\0008\000R\000\000\000\000\000\301\nM\000\"\005\223\031\010\000\000\000\010\310Q\000\002\000\000\000\340\307Q", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F128), "\001\000\000\000\002\000\000\000\003\000\000\000\004\000\000\000\001\000\000\000\254\307Q\000\005\000\000\000\006\000\000\000\007\000\000\000\001\000\000\000\234\307Q\000\377\377\377\377\360AO\000\000\000\000\000\370AO\000\001\000\000\000\000\000\000\000\002\000\000\000\006BO\000\001\000\000\000\000\000\000\000\001\000\000\000\000\000\000\000\005\000\000\000\021BO\000\001\000\000\000\000\000\000\000\t\000\000\000x\031R\000\000\000\000\000\223\rM\000\t\000\000\0008\000R\000\000\000\000\000\371\014M\000\"\005\223\031\006\000\000\000\264\310Q\000\002\000\000\000\214\310Q", 159u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F1D4), "\001\000\000\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000X\310Q\000\003\000\000\000\004\000\000\000\005\000\000\000\001\000\000\000H\310Q\000\377\377\377\377\000\000\000\000\000\000\000\000@BO\000\377\377\377\377\000\000\000\000\377\377\377\377\000\000\000\000\003\000\000\000KBO\000\377\377\377\377\000\000\000\000\377\377\377\377\200BO\000\000\000\000\000\210BO\000\"\005\223\031\002\000\000\000\344\310Q", 119u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F260), "\001\000\000\000\377\377\377\377\260BO\000\"\005\223\031\001\000\000\000\030\311Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F28C), "\001\000\000\000\377\377\377\377\340BO\000\377\377\377\377\353BO\000\"\005\223\031\002\000\000\000D\311Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F2C0), "\001\000\000\000\377\377\377\377 CO\000\"\005\223\031\001\000\000\000x\311Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F2EC), "\001\000\000\000\"\005\223\031\010\000\000\000\310\311Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F310), "\001\000\000\000\377\377\377\377PCO\000\000\000\000\000[CO\000\001\000\000\000fCO\000\002\000\000\000qCO\000\003\000\000\000\177CO\000\004\000\000\000\215CO\000\004\000\000\000\226CO\000\006\000\000\000\244CO\000\"\005\223\031\007\000\000\000,\312Q", 79u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F374), "\001\000\000\000\377\377\377\377\320CO\000\000\000\000\000\333CO\000\001\000\000\000\346CO\000\002\000\000\000\361CO\000\003\000\000\000\377CO\000\004\000\000\000\rDO\000\005\000\000\000\033DO\000\"\005\223\031\030\000\000\000\210\312Q", 71u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F3D0), "\001\000\000\000\377\377\377\377PDO\000\377\377\377\377[DO\000\377\377\377\377fDO\000\377\377\377\377qDO\000\377\377\377\377|DO\000\377\377\377\377\207DO\000\377\377\377\377\222DO\000\377\377\377\377\235DO\000\377\377\377\377\250DO\000\377\377\377\377\263DO\000\377\377\377\377\276DO\000\377\377\377\377\311DO\000\377\377\377\377\324DO\000\377\377\377\377\337DO\000\377\377\377\377\352DO\000\377\377\377\377\365DO\000\377\377\377\377\000EO\000\377\377\377\377\013EO\000\377\377\377\377\026EO\000\377\377\377\377!EO\000\377\377\377\377,EO\000\377\377\377\3777EO\000\377\377\377\377BEO\000\377\377\377\377MEO\000\377\377\377\377\200EO\000\"\005\223\031\001\000\000\000H\313Q", 215u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F4BC), "\001\000\000\000\377\377\377\377\300EO\000\377\377\377\377\316EO\000\"\005\223\031\002\000\000\000t\313Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F4F0), "\001\000\000\000\"\005\223\031\t\000\000\000\314\313Q", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F514), "\001\000\000\000\377\377\377\377\020FO\000\000\000\000\000\033FO\000\001\000\000\000&FO\000\002\000\000\0001FO\000\003\000\000\000?FO\000\004\000\000\000MFO\000\004\000\000\000VFO\000\006\000\000\000dFO\000\007\000\000\000rFO\000\377\377\377\377\240FO\000\"\005\223\031\001\000\000\000\024\314Q", 95u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F588), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F58C), "\376\377\377\377", 4u); storage[UINT32_C(0x0001F590)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F594), "\310\377\377\377\000\000\000\000\376\377\377\377eVM\000tVM\000\000\000\000\000\004\013\000\000\000\000\000\000P\377\377\377\000\000\000\000\376\377\377\377\raM\000\023aM\000\"\005\223\031\006\000\000\000\240\314Q", 63u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F5E8), "\001\000\000\000\377\377\377\377\320FO\000\000\000\000\000\333FO\000\001\000\000\000\346FO\000\002\000\000\000\361FO\000\002\000\000\000\374FO\000\004\000\000\000\007GO\000@", 53u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F628), "\201uM\000\000\000\000\000\001\000\000\000\002\000\000\000\001\000\000\000\320\314Q\000\377\377\377\377\000\000\000\000\000\000\000\000@GO\000\377\377\377\377\000\000\000\000\"\005\223\031\003\000\000\000\364\314Q\000\001\000\000\000\340\314Q", 67u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F678), "\001\000\000\000\377\377\377\377pGO\000\377\377\377\377xGO\000\"\005\223\031\002\000\000\0000\315Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F6AC), "\001\000\000\000\377\377\377\377\260GO\000\"\005\223\031\001\000\000\000d\315Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F6D8), "\001\000\000\000\377\377\377\377\340GO\000\"\005\223\031\001\000\000\000\220\315Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F704), "\001\000\000\000\377\377\377\377\020HO\000\377\377\377\377\036HO\000\"\005\223\031\002\000\000\000\274\315Q", 31u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F738), "\001\000\000\000\377\377\377\377PHO\000\"\005\223\031\001\000\000\000\360\315Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F764), "\001\000\000\000\377\377\377\377\200HO\000\"\005\223\031\001\000\000\000\034\316Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F790), "\001\000\000\000\377\377\377\377\300HO\000\"\005\223\031\001\000\000\000H\316Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F7BC), "\001\000\000\000\377\377\377\377\000IO\000\"\005\223\031\001\000\000\000t\316Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F7E8), "\001\000\000\000\377\377\377\377@IO\000\"\005\223\031\001\000\000\000\240\316Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F814), "\001\000\000\000\377\377\377\377\200IO\000\"\005\223\031\001\000\000\000\314\316Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F840), "\001\000\000\000\377\377\377\377\300IO\000\"\005\223\031\001\000\000\000\370\316Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F86C), "\001\000\000\000\377\377\377\377\360IO\000\"\005\223\031\001\000\000\000$\317Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F898), "\001\000\000\000\377\377\377\377 JO\000\"\005\223\031\001\000\000\000P\317Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F8C4), "\001\000\000\000\377\377\377\377PJO\000\"\005\223\031\001\000\000\000|\317Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F8F0), "\001\000\000\000\377\377\377\377\200JO\000\"\005\223\031\001\000\000\000\250\317Q", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F91C), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F924), "\376\377\377\377", 4u); storage[UINT32_C(0x0001F928)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F92C), "\314\377\377\377\000\000\000\000\376\377\377\377\000\000\000\000\267\350N", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F944), "\376\377\377\377", 4u); storage[UINT32_C(0x0001F948)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F94C), "\314\377\377\377\000\000\000\000\376\377\377\377K\353N\000t\353N", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F964), "\376\377\377\377", 4u); storage[UINT32_C(0x0001F968)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F96C), "\324\377\377\377\000\000\000\000\376\377\377\377\000\000\000\000\321\353N", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F984), "\376\377\377\377", 4u); storage[UINT32_C(0x0001F988)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F98C), "\320\377\377\377\000\000\000\000\376\377\377\377\000\000\000\0006\354N", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F9A4), "\376\377\377\377", 4u); storage[UINT32_C(0x0001F9A8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F9AC), "\204\377\377\377\000\000\000\000\376\377\377\3778\360N\000L\360N", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F9C4), "\376\377\377\377", 4u); storage[UINT32_C(0x0001F9C8)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0001F9CC), "\330\377\377\377\000\000\000\000\376\377\377\377\253\364N\000\276\364N\000\377\377\377\377\260JO\000\"\005\223\031\001\000\000\000\224\320Q", 39u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FA08), "\001\000\000\000\000\000\000\000\220\366N\000\000\000\000\000\320\320Q\000\001\000\000\000\330\320Q\000\000\000\000\000\304TR\000\000\000\000\000\377\377\377\377\000\000\000\000\020\000\000\000\000\367N\000T\330\021", 59u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FA4C), "\036\331\021\000\370\325\017\000l\322\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FA60), ">\331\021\000\020\320\017\000d\322\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FA74), "J\331\021\000\010\320\017\000\\\330\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FA88), "X\331\021\000\000\326\017\000\260\330\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FA9C), "N\332\021\000T\326\017\000\250\330\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FAB0), "n\332\021\000L\326\017\000\240\322\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FAC4), "F\337\021\000D\320\017\000\200\327\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FAD8), "\266\342\021\000$\325\017\000t\322\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FAEC), "h\343\021\000\030\320\017\000\\\322\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FB00), "\202\343\021\000\000\320\017\000\354\326\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FB14), "\240\343\021\000\220\324\017\000\370\330\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FB28), "\006\344\021\000\234\326\017\000\330\326\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FB3C), "\020\344\021\000|\324\017\000\324\330\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FB50), "\260\344\021\000x\326\017\000\364\326\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FB64), "p\351\021\000\230\324\017\000\250\324\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FB78), "\350\356\021\000L\322\017\000\314\323\021", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FB8C), "\\\374\021\000p\321\017", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FBA8), "r\343\021\000\000\000\000\000\021\000\000\200\000\000\000\000(\331\021\000\000\000\000\000X\343\021\000H\343\021\0006\343\021\000 \343\021\000\006\343\021\000\372\342\021\000\352\342\021\000\336\342\021\000\302\342\021\000\316\342\021\000\000\000\000\000\326\336\021\000\034\375\021\000\000\375\021\000\356\374\021\000\330\374\021\000\272\374\021\000\244\374\021\000\224\374\021\000\204\374\021\000j\374\021\000:\337\021\000(\337\021\000\n\337\021\000x\332\021\000\200\332\021\000\220\332\021\000\250\332\021\000\300\332\021\000\316\332\021\000\340\332\021\000\366\332\021\000\006\333\021\000\032\333\021\000*\333\021\000:\333\021\000L\333\021\000`\333\021\000t\333\021\000\210\333\021\000\244\333\021\000\274\333\021\000\312\333\021\000\340\333\021\000\356\333\021\000\004\334\021\000\022\334\021\000 \334\021\000,\334\021\000:\334\021\000F\334\021\000V\334\021\000h\334\021\000x\334\021\000\212\334\021\000\246\334\021\000\276\334\021\000\316\334\021", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FCA8), "\344\334\021\000\370\334\021\000\020\335\021\000&\335\021\000:\335\021\000L\335\021\000b\335\021\000|\335\021\000\230\335\021\000\254\335\021\000\274\335\021\000\312\335\021\000\326\335\021\000\372\336\021\000\370\335\021\000\016\336\021\000 \336\021\0006\336\021\000N\336\021\000h\336\021\000~\336\021\000\216\336\021\000\232\336\021\000\260\336\021\000\312\336\021\000\342\335\021\000\352\336\021\000\000\000\000\000\034\374\021\000\210\367\021\000\310\367\021\000\216\373\021\000P\373\021\000\336\367\021\000\030\370\021\000N\370\021\000\270\370\021\000\354\370\021\000H\367\021\000\010\367\021\000\326\366\021\000\240\366\021\000\\\366\021\000&\366\021\000\352\365\021\000\252\365\021\000d\365\021\000$\365\021\000\002\365\021\000\304\364\021\000\202\364\021\000\\\364\021\000\020\364\021\000\312\363\021\000\204\363\021\000@\363\021\000\004\363\021\000\310\362\021\000\210\362\021\000n\362\021\000F\362\021\000,\362\021\000\016\362\021\000\320\361\021", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FDA8), "\254\361\021\000\200\361\021\000@\361\021\000\014\361\021\000\342\360\021\000\276\360\021\000\236\360\021\000~\360\021\000\332\373\021\000\006\373\021\000\306\372\021\000\204\372\021\000D\372\021\000\014\372\021\000\242\371\021\000h\371\021\000<\371\021\000\004\371\021\000\000\000\000\000\244\357\021\000\232\357\021\000\214\357\021\000~\357\021\000v\357\021\000l\357\021\000\\\357\021\000N\357\021\0004\357\021\000 \357\021\000\026\357\021\000\016\357\021\000\000\357\021\000\260\357\021\000\276\357\021\000\324\357\021\000\350\357\021\000\364\357\021\000\376\357\021\000\020\360\021\000&\360\021\000\\\360\021\000\266\355\021\000\300\355\021\000\310\355\021\000\320\355\021\000\334\355\021\0008\375\021\000n\360\021\000\254\355\021\000\366\356\021\000\336\356\021\000\324\356\021\000\312\356\021\000\300\356\021\000\264\356\021\000\242\355\021\000\230\355\021\000\216\355\021\000\204\355\021\000z\355\021\000r\355\021\000h\355\021\000^\355\021\000\252\356\021", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FEA8), "\236\356\021\000\224\356\021\000\204\356\021\000v\356\021\000l\356\021\000d\356\021\000D\356\021\000*\356\021\000\014\356\021\000\002\356\021\000\372\355\021\000\362\355\021\000T\355\021\000J\355\021\000@\355\021\0006\355\021\000,\355\021\000\"\355\021\000\030\355\021\000\n\355\021\000\376\354\021\000\346\354\021\000\330\354\021\000\312\354\021\000\302\354\021\000\270\354\021\000\254\354\021\000\244\354\021\000\232\354\021\000\216\354\021\000\202\354\021\000t\354\021\000j\354\021\000^\354\021\000T\354\021\000F\354\021\000<\354\021\0002\354\021\000&\354\021\000\034\354\021\000\024\354\021\000\n\354\021\000\000\354\021\000\364\353\021\000\350\353\021\000\334\353\021\000z\351\021\000\204\351\021\000\214\351\021\000\242\351\021\000\254\351\021\000\266\351\021\000\300\351\021\000\312\351\021\000\324\351\021\000\336\351\021\000\350\351\021\000\010\352\021\000(\352\021\000D\352\021\000N\352\021\000d\352\021\000\206\352\021\000\234\352\021", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0001FFA8), "\244\352\021\000\260\352\021\000\272\352\021\000\302\352\021\000\312\352\021\000\324\352\021\000\334\352\021\000\350\352\021\000\360\352\021\000\372\352\021\000\004\353\021\000\016\353\021\000\030\353\021\000\"\353\021\0000\353\021\000B\353\021\000T\353\021\000d\353\021\000n\353\021\000x\353\021\000\204\353\021\000\216\353\021\000\234\353\021\000\246\353\021\000\256\353\021\000\270\353\021\000\302\353\021\000\312\353\021\000\324\353\021\000\352\355\021\000\000\000\000\000\006\000\000\200\t\000\000\200\002\000\000\200\010\000\000\200\000\000\000\000\220\343\021\000\000\000\000\000j\347\021\0000\347\021\000\006\347\021\000\334\346\021\000\242\346\021\000x\346\021\000D\346\021\000$\346\021\000\006\346\021\000\030\350\021\000\330\345\021\000\300\345\021\000\254\345\021\000\214\347\021\000h\345\021\000F\345\021\000$\345\021\000\002\345\021\000\352\344\021\000\274\344\021\0006\350\021\000`\350\021\000\204\350\021\000\254\350\021\000\312\350\021\000\362\350\021", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000200A8), "\346\347\021\000\312\347\021\000\212\345\021\000\372\347\021\000\024\351\021\0006\351\021\000P\351\021\000\362\345\021\000\000\000\000\000X\340\021\000$\340\021\0004\340\021\000H\340\021\000l\340\021\000|\340\021\000\216\340\021\000T\337\021\000`\337\021\000h\337\021\000z\337\021\000\212\337\021\000\234\337\021\000\256\337\021\000\274\337\021\000\320\337\021\000\344\337\021\000\364\337\021\000\002\340\021\000\246\342\021\000\226\342\021\000\204\342\021\000x\342\021\000j\342\021\000Z\342\021\000D\342\021\0008\342\021\000*\342\021\000\024\342\021\000\004\342\021\000\364\341\021\000\342\341\021\000\320\341\021\000\300\341\021\000\254\341\021\000\236\341\021\000\200\341\021\000p\341\021\000\\\341\021\000J\341\021\000>\341\021\000,\341\021\000\032\341\021\000\014\341\021\000\000\341\021\000\362\340\021\000\336\340\021\000\314\340\021\000\302\340\021\000\256\340\021\000\234\340\021\000\020\340\021\000\000\000\000\000\020\331\021", 251u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000201A8), "\023\000\000\200\020\000\000\200\227\000\000\200\022\000\000\200t\000\000\200\003\000\000\200o\000\000\200\004\000\000\2004\000\000\200\014\000\000\200\013\000\000\200\t\000\000\200s\000\000\200\002\000\000\200\n\000\000\2003\000\000\200\027\000\000\200\025\000\000\200\000\000\000\000\\\332\021\000\000\000\000\000\354\331\021\000\316\331\021\000\270\331\021\000z\331\021\000&\332\021\000\232\331\021\000\000\332\021\000d\331\021\000\000\000\000\000\242\344\021\000z\344\021\000`\344\021\000T\344\021\000>\344\021\000.\344\021\000\036\344\021\000\216\344\021\000\000\000\000\000\366\343\021\000\342\343\021\000\320\343\021\000\304\343\021\000\254\343\021\000\000\000\000\000\224\000timeGetTime\000WINMM.dll\000\000\000DirectInput8Create\000\000DINPUT8.dll\000COMCTL32.dll\000\000WS2_", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000202A8), "32.dll\000\000\316\000D3DXMatrixMultiply\000\000\334\000D3DXMatrixRotationQuaternion\000\000\325\000D3DXMatrixPerspectiveFovRH\000\000\315\000D3DXMatrixLookAtRH\000\000\237\000D3DXGetShaderConstantTable\000\000^\000D3DXCreateTexture\000c\000D3DXCreateTextureFromFileInMemoryEx\000)\000D3DXCreateCubeTextureFromFileInMemory\000d3dx9_26.dll", 254u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000203A8), "\n\000Direct3DCreate9\000d3d9.dll\000\000\262\004Sleep\000\003\002GetLocalTime\000\000\356\000EnterCriticalSection\000\0009\003LeaveCriticalSection\000\000R\000CloseHandle\000\301\004TerminateThread\000\371\004WaitForSingleObject\000\223\002GetTickCount\000\000\231\004SetThreadPriority\000\002\002GetLastError\000\000\265\000CreateThread\000\000\326\004UnmapViewOfFile\000\340\001GetExitCodeThr", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000204A8), "ead\000\300\001GetCurrentProcess\000\304\001GetCurrentThread\000\000\342\002InitializeCriticalSection\000\321\000DeleteCriticalSection\000\272\002GlobalFree\000\000\021\005WideCharToMultiByte\000\263\002GlobalAlloc\000g\003MultiByteToWideChar\000\031\001ExitProcess\000\360\001GetFileSize\000\300\003ReadFile\000\000\210\000CreateFileA\000.\001FindClose\000C\001FindNextFileA\0002\001Find", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000205A8), "FirstFileA\000\000\227\003Process32Next\000\225\003Process32First\000\000\276\000CreateToolhelp32Snapshot\000\000\245\002GetVolumeInformationA\000W\003MapViewOfFile\000\211\000CreateFileMappingA\000\000|\000CreateDirectoryA\000\000\220\004SetThreadAffinityMask\000\337\001GetExitCodeProcess\000\000\300\004TerminateProcess\000\000\244\000CreateProcessA\000\000o\002GetSystemDirec", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000206A8), "toryA\000\247\003QueryPerformanceCounter\000\250\003QueryPerformanceFrequency\000\025\002GetModuleHandleA\000\000\305\002GlobalUnlock\000\000\276\002GlobalLock\000\000%\005WriteFile\000M\005lstrlenA\000\000\301\001GetCurrentProcessId\000\305\001GetCurrentThreadId\000\000\261\003RaiseException\000\000\211\003OutputDebugStringA\000\000#\001FileTimeToDosDateTime\000$\001FileTimeToLo", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000207A8), "calFileTime\000\277\002GlobalMemoryStatus\000\000s\002GetSystemInfo\000G\005lstrcpyA\000\000\023\002GetModuleFileNameA\000\000y\002GetSystemTimeAsFileTime\000>\005lstrcatA\000\000\000\003IsDebuggerPresent\000\361\004VirtualQuery\000\000\243\002GetVersionExA\000\245\004SetUnhandledExceptionFilter\000f\004SetFilePointer\000\000H\003LocalFree\000KERNEL32.dll\000\000e\002Releas", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000208A8), "eDC\000!\001GetDC\000\225\001GetWindowLongA\000\000\024\001GetClientRect\000\303\002SetWindowLongA\000\000\233\000DefWindowProcA\000\000\r\002MessageBeep\000\374\002TranslateMessage\000\000\256\000DispatchMessageA\000\0002\002PeekMessageA\000\000\016\002MessageBoxA\000\332\002ShowCursor\000\000\005\003UnregisterClassA\000\000\246\000DestroyWindow\000~\001GetSystemMetrics\000\000w\002SendMessageA\000\000\020\000Br", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000209A8), "ingWindowToTop\000\000\021\003UpdateWindow\000\000\276\001InvalidateRect\000\000\337\002ShowWindow\000\000m\000CreateWindowExA\000\002\000AdjustWindowRect\000\000\256\002SetRect\0007\002PostQuitMessage\000L\002RegisterClassExA\000\000\350\001LoadCursorA\000\354\001LoadIconA\000\367\000FindWindowA\000\035\000CallWindowProcA\000G\000ClientToScreen\000\000\222\002SetFocus\000\000I\000CloseClipboard", 254u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00020AA8), "\026\001GetClipboardData\000\000&\002OpenClipboard\000\312\001IsClipboardFormatAvailable\000\000'\001GetDlgItem\000\000\314\001IsDialogMessageA\000\000\330\000EnableWindow\000\000\312\002SetWindowTextA\000\000\240\001GetWindowTextA\000\000&\001GetDlgCtrlID\000\000\203\002SetClassLongA\000b\000CreateDialogParamA\000\0004\003wvsprintfA\000\0002\003wsprintfA\000g\000CreateIconIndirect\000\000\242", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00020BA8), "DestroyCursor\000H\000ClipCursor\000\000\210\002SetCursor\000m\002ScreenToClient\000\000 \001GetCursorPos\000\000\212\002SetCursorPos\000\000USER32.dll\000\000\233\002SetPixel\000\000\346\000DeleteObject\000\000\343\000DeleteDC\000\000w\002SelectObject\000\000\312\001GetDIBits\000/\000CreateCompatibleBitmap\000\0000\000CreateCompatibleDC\000\000\r\002GetStockObject\000\000)\000CreateBitmap\000\000\374\001Ge", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00020CA8), "tObjectType\000GDI32.dll\000d\001GetUserNameA\000\000ADVAPI32.dll\000\000\036\001ShellExecuteA\000SHELL32.dll\000F\001OleSetContainedObject\000\031\001OleCreate\000l\000CoUninitialize\000\000\020\000CoCreateInstance\000\000>\000CoInitialize\000\000ole32.dll\000OLEAUT32.dll\000\000\205\000SymInitialize\000\237\000SymSetOptions\000U\000SymGetLineFromAddr\000\000 \000StackW", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00020DA8), "alk\000P\000SymFunctionTableAccess\000\000a\000SymGetModuleBase\000\000\035\000MiniDumpWriteDump\000H\000SymFromAddr\000dbghelp.dll\000{\000?SI_GetInterface@@YAPAVCSoundInterface@@XZ\000\000d\000?Play@CSound@@UAEHH@Z\000\245\000?SetPlayTimepos@CSound@@QAEXM@Z\000^\000?IsSoundPlaying@CSound@@QBEHXZ\000\000K\000?GetPlayTimepos@CSou", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00020EA8), "nd@@QBEMXZ\000\000\247\000?SetPosition@CSound@@QAEHMMMH@Z\000\254\000?SetVelocity@CSound@@QAEHMMMH@Z\000\001\000??0CSound@@QAE@XZ\000\265\000?Stop@CSound@@UAEXXZ\000\000t\000?Rewind@CSound@@UAEHXZ\000\000\020\000??1CSound@@QAE@XZ\000\257\000?SetVolume@CSound@@QAEHM@Z\000\000a\000?LoadSound@CSound@@QAEHPBDK@Z\000\220\000?SetAllParameters@CSou", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00020FA8), "nd@@QAEHPBU_DS3DBUFFER@@H@Z\000\271\000?UpdateSettings@CSoundInterface@@QAEHXZ\000\237\000?SetOrientation@CSoundListener@@QAEHABU_D3DVECTOR@@0H@Z\000\256\000?SetVelocity@CSoundListener@@QAEHMMMH@Z\000\251\000?SetPosition@CSoundListener@@QAEHMMMH@Z\000H\000?GetOrientation@CSoundListener@@QBEXPAU_D3", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000210A8), "DVECTOR@@0@Z\000\000\177\000?SI_SetHardwareMixing@@YAX_N@Z\000\000w\000?SI_CreateInterface@@YAPAVCSoundInterface@@PAUHWND__@@HKK@Z\000\200\000?SI_SetLogFile@@YAXPBD@Z\000\000v\000?SI_Close@@YAXXZ\000\000\202\000?SI_SetStreamVolume@@YAXH@Z\000}\000?SI_GetStreamVolume@@YAHXZ\000\000\230\000?SetDecodeSignal@CSoundStream@@QAEXM", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000211A8), "@Z\000\000\214\000?SeekToTime@CSoundStream@@QAEHM@Z\000\244\000?SetPlaySignal@CSoundStream@@QAEXM@Z\000\000\266\000?Stop@CSoundStream@@QAEXXZ\000\000`\000?IsStreamPlaying@CSoundStream@@QBEHXZ\000f\000?PlayEx@CSoundStream@@QAEHMH@Z\000\000\203\000?SI_StreamCreateFile@@YAKPBDK@Z\000\204\000?SI_StreamFree@@YAXK@Z\000\000z\000?SI_GetHar", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000212A8), "dwareMixing@@YA_NXZ\000Sound.dll\000\351\001_close\000\000\342\003_read\000\345\000?_open@@YAHPBDHH@Z\000\000/\005_write\000\000,\003_lseek\000\000\317\005memcpy\000\000\323\005memset\000\000\357\005sprintf\000\345\001_chmod\000\000\363\005sscanf\000\000\"\000??0exception@std@@QAE@ABQBD@Z\000\r\001?what@exception@std@@UBEPBDXZ\000]\000??1exception@std@@UAE@XZ\000\000\321\005memmove\000!\001_CxxThrowExc", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000213A8), "eption\000\000$\000??0exception@std@@QAE@ABV01@@Z\000\000:\001__CxxFrameHandler3\000\000\275\005ldiv\000\000!\006vfprintf\000\000\203\005fprintf\000\223\005ftell\000\221\005fseek\000v\005fclose\000\000\201\005fopen\000\020\004_snprintf\000\341\005rand\000\000\036\002_errno\000\000\033\001_CIsqrt\000\022\001_CIcos\000\000\031\001_CIsin\000\000\030\001_CIpow\000\0009\002_findclose\000\000A\002_findnext64i32\000\000=\002_findfirst64i32\000!\003_local", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000214A8), "time64\000\000q\004_time64\000\004\006strncpy\000\377\005strftime\000\000\367\005strchr\000\0006\002_filelength\000\304\005malloc\000\000\213\005free\000\000\033\006tolower\000\003\006strncmp\000\336\005qsort\000\343\005realloc\000\362\005srand\000\330\003_purecall\000A\004_stricmp\000\000'\006vsprintf\000\000_\005asctime\000\226\005fwrite\000\000\211\005fread\000\344\005remove\000\000\375\005strerror\000\000\272\001_access\000\315\005memchr\000\000\277\004_vswprintf\000\000\n\006strstr", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000215AA), "\021\001_CIatan2\000\000\024\001_CIexp\000\000\021\002_difftime64\000\306\003_mktime64\000j\002_futime64\000\010\006strrchr\000\206\005fputs\000T\004_strtime\000\000\307\003_msize\000\000s\005exit\000\000\261\004_vsnprintf\000\000\251\004_vscprintf\000\000\355\000?_sopen@@YAHPBDHHH@Z\000\000%\003_locking\000\000_\002_fstat64i32\000\346\001_chsize\000\345\005rename\000\000\314\001_atoi64\000\233\005getenv\000\000\300\003_mkdir\000\000$\004_spawnl\000\034\001_CItan", 254u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000216AA), "\016\001_CIacos\000\020\001_CIatan\000\177\005floor\000y\005fflush\000\000\"\002_execl\000\000\213\004_unlink\000\243\005isalpha\000\017\001_CIasin\000\034\006toupper\000\242\005isalnum\000f\005atoi\000\000e\005atof\000\000\220\004_utime64\000\0007\004_stat64i32\000\000|\005fgets\000w\005feof\000\000z\005fgetc\000\014\006strtok\000\000\025\000??0bad_cast@std@@QAE@PBD@Z\000\000Y\000??1bad_cast@std@@UAE@XZ\000\024\000??0bad_cast@std@@QAE@ABV", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000217AA), "01@@Z\000\205\005fputc\000\037\006ungetc\000\000$\003_lock_file\000\000\216\004_unlock_file\000\000\353\005setvbuf\000\320\005memcpy_s\000\000{\005fgetpos\000Y\002_fseeki64\000\222\005fsetpos\000\245\005isdigit\000k\005calloc\000\000\327\005printf\000\000MSVCR100.dll\000\000\215\004_unlock\000[\001__dllonexit\000#\003_lock\000\311\003_onexit\000\002\001?terminate@@YAXXZ\000!\002_except_handler4_common\000\305\001_amsg_exit\000\000c\001", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000218AA), "__getmainargs\000\334\001_cexit\000\000*\002_exit\000-\001_XcptFilter\000\322\002_ismbblead\000\000\274\001_acmdln\000\260\002_initterm\000\261\002_initterm_e\000\354\001_configthreadlocale\000\242\001__setusermatherr\000\000\353\001_commode\000\000E\002_fmode\000\000\237\001__set_app_type\000\000\373\001_crt_debugger_hook\000\000\356\000?_type_info_dtor_internal_method@type_info@@QAEXXZ\000\000\270\002", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000219AA), "_invoke_watson\000\000\357\001_controlfp_s\000\000\216\002?_Xout_of_range@std@@YAXPBD@Z\000\214\002?_Xlength_error@std@@YAXPBD@Z\000\232\000??1_Container_base12@std@@QAE@XZ\000\000\236\001?_Decref@facet@locale@std@@QAEPAV123@XZ\000\322\001?_Getgloballocale@locale@std@@CAPAV_Locimp@12@XZ\000\000\366\001?_Init@?$basic_streambuf@DU?", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00021AAA), "$char_traits@D@std@@@std@@IAEXXZ\000\000\221\002?always_noconv@codecvt_base@std@@QBE_NXZ\000\000\363\001?_Incref@facet@locale@std@@QAEXXZ\000\260\001?_Getcat@?$codecvt@DDH@std@@SAIPAPBVfacet@locale@2@PBV42@@Z\000\357\001?_Id_cnt@id@locale@std@@0HA\000\236\000??1_Lockit@std@@QAE@XZ\000\000\377\003?id@?$codecvt@DDH@std@", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00021BAA), "@2V0locale@2@A\000\000`\000??0_Lockit@std@@QAE@H@Z\000*\002?_Ipfx@?$basic_istream@DU?$char_traits@D@std@@@std@@QAE_N_N@Z\000\201\000??1?$basic_streambuf@DU?$char_traits@D@std@@@std@@UAE@XZ\000\000&\000??0?$basic_streambuf@DU?$char_traits@D@std@@@std@@IAE@XZ\000\000\254\005?showmanyc@?$basic_streambuf", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00021CAA), "@DU?$char_traits@D@std@@@std@@MAE_JXZ\0005\006?xsgetn@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAE_JPAD_J@Z\0008\006?xsputn@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAE_JPBD_J@Z\000\354\003?getloc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@QBE?AVlocale@2@XZ\000\000\250\001", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00021DAA), "?_Fiopen@std@@YAPAU_iobuf@@PBDHH@Z\000\000\221\003?flush@?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEAAV12@XZ\000S\002?_Osfx@?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEXXZ\000\000\r\006?uncaught_exception@std@@YA_NXZ\000\234\005?setstate@?$basic_ios@DU?$char_traits@D@std@@@std@@QAEXH", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00021EAA), "_N@Z\000\000\310\005?sputn@?$basic_streambuf@DU?$char_traits@D@std@@@std@@QAE_JPBD_J@Z\000\000\305\005?sputc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@QAEHD@Z\000\231\002?clear@?$basic_ios@DU?$char_traits@D@std@@@std@@QAEXH_N@Z\000\346\004?out@?$codecvt@DDH@std@@QBEHAAHPBD1AAPBDPAD3AAPAD@Z\000\221\005", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00021FAA), "?setg@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IAEXPAD00@Z\000\0000\004?in@?$codecvt@DDH@std@@QBEHAAHPBD1AAPBDPAD3AAPAD@Z\000\000\025\006?unshift@?$codecvt@DDH@std@@QBEHAAHPAD1AAPAD@Z\000\000\277\005?snextc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@QAEHXZ\000k\005?sbumpc@?$basic_stre", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000220AA), "ambuf@DU?$char_traits@D@std@@@std@@QAEHXZ\000\246\005?sgetc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@QAEHXZ\000\000\232\001?_BADOFF@std@@3_JB\000\000~\000??1?$basic_ostream@DU?$char_traits@D@std@@@std@@UAE@XZ\000\000u\000??1?$basic_ios@DU?$char_traits@D@std@@@std@@UAE@XZ\000\000\034\000??0?$basic_ost", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000221AA), "ream@DU?$char_traits@D@std@@@std@@QAE@PAV?$basic_streambuf@DU?$char_traits@D@std@@@1@_N@Z\000<\001??_7?$basic_ios@DU?$char_traits@D@std@@@std@@6B@\000\000`\001??_7ios_base@std@@6B@\000E\001??_7?$basic_ostream@DU?$char_traits@D@std@@@std@@6B@\000\000)\002?_Ios_base_dtor@ios_base@std@@CA", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000222AA), "XPAV12@@Z\000{\000??1?$basic_istream@DU?$char_traits@D@std@@@std@@UAE@XZ\000\000\021\000??0?$basic_istream@DU?$char_traits@D@std@@@std@@QAE@PAV?$basic_streambuf@DU?$char_traits@D@std@@@1@_N@Z\000B\001??_7?$basic_istream@DU?$char_traits@D@std@@@std@@6B@\000\0007\002?_Lock@?$basic_streambuf", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000223AA), "@DU?$char_traits@D@std@@@std@@UAEXXZ\000\000\202\002?_Unlock@?$basic_streambuf@DU?$char_traits@D@std@@@std@@UAEXXZ\000\000\n\006?uflow@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAEHXZ\000\000\214\005?setbuf@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAEPAV12@PAD_J@Z\000\347\005?sync@?$basi", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000224AA), "c_streambuf@DU?$char_traits@D@std@@@std@@MAEHXZ\000,\004?imbue@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAEXABVlocale@2@@Z\000\000Y\002?_Pninc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IAEPADXZ\000\t\001??6?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEAAV01@I@Z\000\000MS", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000225AA), "VCP100.dll\000\000\316\004TryEnterCriticalSection\000\352\000EncodePointer\000\312\000DecodePointer\000\354\002InterlockedExchange\000\351\002InterlockedCompareExchange\000\000\323\002HeapSetInformation\000\000c\002GetStartupInfoW\000\323\004UnhandledExceptionFilter\000\000\004\003IsProcessorFeaturePresent\000K\004_strnicmp", 229u);
}
} // namespace


extern "C" void sfera_rdata_bind_storage(uint8_t* storage) { g_sfera_rdata_semantic_storage = storage; if (storage) { sfera_initialize_rdata_storage(storage); } }
extern "C" uint32_t sfera_rdata_semantic_address(uint32_t source_va) { if (!g_sfera_rdata_semantic_storage) { return 0u; } const uint32_t offset = source_va - SFERA_RDATA_SEMANTIC_BEGIN; return offset < SFERA_RDATA_SEMANTIC_SIZE ? (uint32_t)(uintptr_t)(g_sfera_rdata_semantic_storage + offset) : 0u; }
extern "C" uint32_t sfera_rdata_mutable_semantic_address(uint32_t source_va) { return sfera_rdata_semantic_address(source_va); }
extern "C" uint32_t sfera_rdata_source_rva(uint32_t address) { if (!g_sfera_rdata_semantic_storage) { return UINT32_MAX; } const uint32_t begin = (uint32_t)(uintptr_t)g_sfera_rdata_semantic_storage; const uint32_t offset = address - begin; return offset < SFERA_RDATA_SEMANTIC_SIZE ? (SFERA_RDATA_SEMANTIC_BEGIN - UINT32_C(0x00400000)) + offset : UINT32_MAX; }

/* ===== Initial source-derived bytes ===== */
extern "C" void sfera_initialize_data_storage(uint8_t* storage) {
    if (!storage) { return; }
    memset(storage, 0, UINT32_C(0x00005600));
    sfera_copy_static_bytes(storage, UINT32_C(0x00000000), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000008), ".?AVbad_alloc@std@@", 19u); storage[UINT32_C(0x0000001B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000001C), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000024), ".?AVexception@std@@", 19u); storage[UINT32_C(0x00000037)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000038), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000040), ".?AVCBitmapException@@", 22u); storage[UINT32_C(0x00000056)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000058), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000060), ".?AVEffectListener@@", 20u); storage[UINT32_C(0x00000074)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000078), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000080), ".?AVBloodEffListener@@", 22u); storage[UINT32_C(0x00000096)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000098), "\004\002\001<\000\001\0008\000\000\200:\000\001\0008\004\002\001<\000\001\0008\000\000\200:\000\001\0008\004\002\001<\000\001\0008\000\000\200:\000\001\0008\377\377\377\377\004\002\001<\000\001\0008\000\000\200:\000\001\0008\000\000\000\000\200\032B\000\200\031B\000\200\031B\000 \030B\000 \030B\000 \030B\0000\030B\000@\030B\000@\030B\000p\032B\000\000\032B\000@\030B\000p\032B\000\200\032B\000@\030B\000\340\031B\000\200\032B\000\200\032B\000\340\000R\000\200\032B\000\200\031B\000\200\031B\000P\032B\000p\032B\000p\032B\000p\032B\000p\032B\0000\261C\000\200\032B\000\220\027B\000p\032B\000\340\031B\000\340\031B\000\200\032B\000P\030B\000\200\031B\000\200\031B\000\000\032B\000@\031B\000P\031B\000\360\031B\000p\032B\000\000\032B\000p\031B\000\200\031B\000\200\031B", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000198), "\220\031B\000p\032B\000\360\031B\000\360\031B\000\360\031B\000\260\031B\000\200\032B\000\340\031B\000\360\031B\000\000\032B\000\000\032B\000\020\032B\000\260\037B\000\200\031B\000\200\031B\000P\027B\000`\027B\000\200\027B\000\360\031B\000\360\031B\000\340\031B\000\340\031B\000\340\031B\000\220\027B\000\240\027B\000\260\027B\000\260\027B\000\300\027B\000\340\027B\000\000\030B\000\004\002\001<\000\001\0008\000\000\200:\000\001\0008\004\002\001<\000\001\0008\000\000\200:\000\001\0008\001\000\000\000\004\002\001<\000\001\0008\000\000\200:\000\001\0008", 172u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000025C), "p\027\000\000\204bQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000268), ".?AVIEffectManager@@", 20u); storage[UINT32_C(0x0000027C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000280), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000288), ".?AVCScriptedEffect@@", 21u); storage[UINT32_C(0x0000029D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000002A0), "\377\377\377\377\037\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000002B0), ".?AVCSpiralEffect@@", 19u); storage[UINT32_C(0x000002C3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000002C4), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000002CC), ".?AVCMolEffect@@", 16u); storage[UINT32_C(0x000002DC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000002E0), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000002E8), ".?AVCBladeEffect@@", 18u); storage[UINT32_C(0x000002FA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000002FC), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000304), ".?AVCGazerLakeEffect@@", 22u); storage[UINT32_C(0x0000031A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000031C), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000324), ".?AVCRainEffect@@", 17u); storage[UINT32_C(0x00000335)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000338), "\030-\300\207[\017\310\300K$\376\257b1\016\345\000*\032\325\221\000 \r\313\207\\D\300\230~\0004\027\327\230@\r\312\21653\351\251\0000\023\312\207\001\017\335\205\0000\033\313\202F\t\300\22353\351\251\0000\033\313\202F\t\300\316~.\364\000/\r\330\207\\D\300\230~\0007\037\312\237B\r\327\316~.\364\0000\007\312\200J\007\0000\010\332\234@\031\321\316~.\364\000 \032\330\232[\031\327\22653\351\251\0000\016\326\233C\031\323\316~.\364\000.\032\324\332J\022\300\000-\010\312\202LY\227\316~.\364\000%\037\313\332J\022\300\0001\033\336\207Y\t\226\32253\351\251\000.\r\315\225\\\001\213\205c3\0004\027\327\231H\007\321\316~.\364\0000\n\320\207Y\t\213\205c3\0001\013\327\220C\006\226\32253\351\251\0004\035\334\207L\005\312\215vx\364\264b\000*\020\315\221]\004\304\2245", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000438), "3\351\251\0004\027\327\203@\030\301\316~.\364\000&\006\311\230@\030\300\22253\351\251\000-\021\315\221_\013\301\316~.\364\000 \n\337\231@\004\213\205c3\000*\035\310\332J\022\300\000*\033\301\204C\005\327\20553\351\251\0000\014\317\225A\023\213\205c3\0000\016\320\220J\030\313\22453\351\251\0004\027\327\225B\032\213\205c3\000(\037\317\332J\022\300\0004\027\327\206N\030\213\205c3\000(\037\317\207Y\t\213\205c3\000\"\n\320\306J\034\335\23053\351\251\0001\033\336\207Y\t\213\205c3\000.\r\311\231\\\032\326\22653\351\251\0001\033\312\221[\031\300\222m?\362\251)'\005\335\000'\027\313\221L\036\306\20453\351\251\0002\n\315\225\\\001\213\205c3\000\"\n\320\204[\013\335\23053\351\251\000\0201\354\272k'\344\2565\023\311\211\0004\013\330\201L\006\321\316~.\364\000.\027", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000538), "\313\225A\016\304\323)x\364\264b\0000\016\321\221]\017\213\205c3\000 \023\335\332J\022\300\000 \037\325\227\001\017\335\205\0007\026\334\226N\036\213\205c3\000\000\204bQ", 55u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000574), ".?AVIOutputDevice@@", 19u); storage[UINT32_C(0x00000587)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000588), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000590), ".?AVCOutputLogDevice@@", 22u); storage[UINT32_C(0x000005A6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000005A8), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000005B0), ".?AVCSphereError@@", 18u); storage[UINT32_C(0x000005C2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000005C4), "\024\372O\000\004\372O\000\364\371O\000\344\371O\000\204bQ", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000005DC), ".?AVBaseCache@@", 15u); storage[UINT32_C(0x000005EB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000005EC), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000005F4), ".?AVGrassMapMngr@@", 18u); storage[UINT32_C(0x00000606)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000608), "\004\002\001<\000\001\0008\000\000\200:\000\001\0008\204bQ", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000620), ".?AUBasicHyperTextElement@@", 27u); storage[UINT32_C(0x0000063B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000063C), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000644), ".?AUHyperTextElement_WordWrap@@", 31u); storage[UINT32_C(0x00000663)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000664), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000066C), ".?AUHyperTextElement@@", 22u); storage[UINT32_C(0x00000682)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000684), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000068C), ".?AUHyperTextElementWithParameters@@", 36u); storage[UINT32_C(0x000006B0)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000006B4), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000006BC), ".?AUHyperTextElement_PlainText@@", 32u); storage[UINT32_C(0x000006DC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000006E0), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000006E8), ".?AUHyperTextElement_Link@@", 27u); storage[UINT32_C(0x00000703)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000718), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000734), "\017\000\000\000\000\000\000\000\377\377\377\377\002e\000\000\017\000\000\000\004\002\001<\000\001\0008\000\000\200:\000\001\0008\354h\000\000\000\000\000\000\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\000\000\000\000\037\000\000\000\034\000\000\000\037\000\000\000\036\000\000\000\037\000\000\000\036\000\000\000\037\000\000\000\037\000\000\000\036\000\000\000\037\000\000\000\036\000\000\000\037", 109u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000007AC), "\037\000\000\000;\000\000\000Z\000\000\000x\000\000\000\227\000\000\000\265\000\000\000\324\000\000\000\363\000\000\000\021\001\000\0000\001\000\000N\001\000\000m\001\000\000\300\003\000\000@\002\000\000\003\000\000\000\001\000\000\000\001\000\000\000i\000\000\000\340hC\000G\000\000\000\240iC\000,\000\000\000\300iC\0000\000\000\000\340iC\000I\000\000\000@\261C\0009\000\000\000\000jC\000a\000\000\000\220\261C\000R\000\000\000plC\000S\000\000\0000mC\000C\000\000\000\220mC\000c\000\000\000\200\270C\000r\000\000\000\320\226C\000=\000\000\000 nC\000+\000\000\000 pC\000-\000\000\000ppC\000*\000\000\000\300pC\000/\000\000\000\360\227C\000%\000\000\000 qC\0001\000\000\000p\226C\0002\000\000\000\260\226C\000\360\000\000\000pqC\000\355\000\000\000\360qC\000>\000\000\000prC\000<", 253u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000008AC), "\360rC\000\341\000\000\000psC\000\354\000\000\000\360sC\000\361\000\000\000`\230C\000O\000\000\000\320\230C\000\353\000\000\000\020uC\000\350\000\000\000\020uC\000!\000\000\000\320\233C\000\357\000\000\000@uC\000\363\000\000\000\260uC\000U\000\000\000\320lC\000f\000\000\000\000wC\000\366\000\000\000 vC\000\367\000\000\000\220vC\000\326\000\000\000pyC\000\327\000\000\000\260yC\000b\000\000\000 \263C\000m\000\000\000\300\264C\000g\000\000\000`\226C\000A\000\000\000 kC\000^\000\000\000\320nC\000P\000\000\000`mC\000&\000\000\000\320oC\000H\000\000\000PwC\000.\000\000\000`wC\000:\000\000\000\200wC\000~\000\000\000\240wC\000[\000\000\000\360wC\000]\000\000\000@xC\000`\000\000\000\220xC\000\"\000\000\000\300xC\000t\000\000\000\320mC\000\317", 253u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000009AC), "\360xC\000\323\000\000\0000yC\000;\000\000\000\360yC\000J\000\000\000\260iC\000K\000\000\000`\261C\000(\000\000\000`jC\000)\000\000\000\300jC\000\311\000\000\000\020\272C\000e\000\000\000\220kC\000d\000\000\000\020\266C\000h\000\000\000\220\267C\000l\000\000\000\000lC\000L\000\000\000ptC\000M\000\000\000\300tC\000\000\000\000\0000\226C", 115u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000B10), "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\3770\273C\0000\273C\000\200\273C\000\300\273C\000\360\273C\000\360\274C\000\220\274C\000P\274C\000 \275C\000p\370C\000P\007D\000\240\277C\000\020\301C\000P\301C\000\240\301C\000\340\037D\000\320\301C\0000\302C\000\300\302C\000P\303C\000p\307C\000\300\307C\000\340\307C\000@\310C\000\240\310C\000\240\323C\000\200\311C\000\240\323C\000\240\303C\000\220\324C\000\300\324C\000\020~C\000P\325C\000\300\314C\000\260\325C\000\300\327C\000\220\332C\000\300\333C\000\340\335C\000\020\311C\000\360\346C\000\200\347C\000\220\350C\000\300\350C\000@\351C\000P\354C\000\260\354C\0000\355C\000@\356C\000\360\362C\000\340\363C\000@\364C\000\000\361C\000\200\364C\000P\357C\000\220\357C\000\320\357C\000\020\360C", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000C10), "P\360C\000\220\360C\000\320\360C\0000\365C\000\260\366C\000\340\366C\000\300\354C\000`\352C\000\260\352C\000\340\371C\000\340\353C\000\260\353C\000\320\352C\000 \353C\000P\353C\0000\367C\000 \354C\000`\334C\000\340\334C\000\220\374C\000\260\376C\000\220\377C\000\000\324C\000\260\275C\000\000\000D\000\200\361C\000\260\362C\0000\000D\000\300\346C\000\220\000D\000\360\000D\000P\001D\000\200\001D\000\020\345C\000\260\001D\000`\002D\000\320\002D\000\260\331C\000 \377C\0000\003D\000\260\003D\000\340\364C\000\020\004D\000\340\004D\000\200\005D\000 ?D\000\220\034D\000@\370C\000\200\275C\000\340\034D\000\260\375C\000`\035D\000\320\035D\000\200\036D\000@!D\0000 D\000 \"D\000\240#D\000@\350C\000@mD\000p%D\000\240%D\000\260\260C\000\340\372C", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000D10), "\320\267B\000\000\006D\000\260\351C\000 \274C\000 \342C\000p\372C\000\260>D\0000\261D\000\320\267B\000\240\006D\000\360\236D\000\320\267B\0000\300C\000 \332C\000\260\326C\000`\335C\000\360%D\000`&D\000\320&D\000@'D\000\240'D\000\020(D\000\200(D\000\000)D\000\200)D\000pwD\000`+D\000p+D\000\200+D\000\220+D\000\240+D\000@,D\000\200-D\000\220-D\000\240-D\000\260-D\000\300-D\000\200.D\000p/D\000 IA\000@ @\000P0D", 167u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000F28), "\001\000\000\000\000\000\000\000\001\000\000\000\002\000\000\000\003\000\000\000\001\000\000\000\004\000\000\000\005\000\000\000\006\000\000\000\004\000\000\000\005\000\000\000\003", 45u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000F58), "logs\\server.log", 15u); storage[UINT32_C(0x00000F67)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00000FC0), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000FCC), "\001\000\000\000\001\000\000\000\000\000\000\000\001\000\000\000\001", 17u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00000FEC), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001004), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001020), "\001\000\000\000\001\000\000\000\001\000\000\000\001", 13u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001044), "\001\000\000\000\004\002\001<\000\001\0008\000\000\200:\000\001\0008", 20u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000106C), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001088), "\017\000\000\000\000\000\000\000\315\314\314;\204bQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000109C), ".?AVCItem@@", 11u); storage[UINT32_C(0x000010A7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000010A8), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000010B0), ".?AVCCommonItem@@", 17u); storage[UINT32_C(0x000010C1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000010C4), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000010CC), ".?AV?$CItemList@VCCommonItem@@@@", 32u); storage[UINT32_C(0x000010EC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000010F0), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000010F8), ".?AV?$CItemList@V?$CItemList@VCCommonItem@@@@@@", 47u); storage[UINT32_C(0x00001127)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001128), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001130), ".?AV?$CBaseManager@V?$CItemList@VCCommonItem@@@@VCCommonItem@@@@", 64u); storage[UINT32_C(0x00001170)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001174), "\001\000\000\000\001\000\000\000,\001\000\000\377\377\377\377\004\002\001<\000\001\0008\000\000\200:\000\001\0008\204bQ", 35u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000119C), ".?AVCLightEffect@@", 18u); storage[UINT32_C(0x000011AE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000011B0), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000011B4), "SphereWclName", 13u); storage[UINT32_C(0x000011C1)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000011C2), "\001\000 \000\000\000\001\000\000\000\001\000\000\000\000\000\340@\376\324x?\376\324x?\270\036\205?h\221", 32u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000011E2), "m?0u", 4u); storage[UINT32_C(0x000011E6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000011E8), "0u\000\000\210\023\000\000\210\023\000\000\377\377\377\377\001\000\000\000\377\377\377\377\000\000\240C\000\000pC\000\000\300?\377\377\377\377\350(P\000\334(P\000\320(P\000\304(P\000\270(P", 59u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001224), "B`%?", 4u); storage[UINT32_C(0x00001228)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000122A), "\200?\001\000\000\000\256G\301?\024\256\207?\244p\275?\377\377\377\377\001\000\000\000\232\231\231?\000\000\000\000\000\000\000\000\001\000\000\000\001\000\000\000\260(P\000\250(P\000\240(P\000\230(P\000\220(P\000\210(P\000\200(P\000x(P\000p(P\000\000\000\000\000\001\000\000\000\003\000\000\000\005\000\000\000\004\000\000\000\002\000\000\000\312fX\243\024(\327e]\310g_\321a@\320o\010\206z^\240\037_\310n[\335\025^\325`_\244\024+8\000\000\000\345Wm\000\000\000\310B\000\000HB\001\000\000\000\001\000\000\000\232\231", 168u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000012D2), "Y?qwertyuiopasdfghjklzxcvbnm", 28u); storage[UINT32_C(0x000012EE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000012F0), "QWERTYUIOPASDFGHJKLZXCVBNM", 26u); storage[UINT32_C(0x0000130A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000130E), "\200;\377\377\377\377\377\377\377\377\001\000\000\000\377\377\377\377\001\000\000\000\001\000\000\000\377\377\377\377\001\000\000\000\000\000\000\000\001\000\000\000\000\000\000\000\377\377\377\377\377\377\377\377\000\000\000\000\001\000\000\000\000\000\000\000\000\300\371\304\000\000\330\302\000\200\362C\000\000pB\000\200\312C\000\000\027C\000\000\243\304\000\000pB\000\260\"E\000\000\032C\000\340\242D\000\000pB\000\340\353D\000\000\032C\000\200\311\303\000\0004B\000\220\017E\000\000\031C\000 \026\305\000\000pB\000\260(\305\000\200\310C\000\220\002E\000\000pB\000\240\353D\000\000\310C\000\360ME\000\000pB", 178u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000013DC), "\001\000\000\000\001\000\000\000\001\000\000\000\001\000\000\000\001", 17u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000013F8), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001414), "\001\000\000\000\000\000\000\000\001\000\000\000\001\000\000\000\001", 17u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001430), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001440), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000144C), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000145C), "\001", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001468), "\001\000\000\000\001\000\000\000\001\000\000\000\001\000\000\000\001\000\000\000\000\000\000\000\001\000\000\000@\000\000\000\024\256\307@\244p\r@\244p\r@\024\256\307@R\270n@\217\302\225?33\263@\315\314\344@\000\000\000\000\000\000\000\000\001\000\000\000\001\000\000\000\001\000\000\000\000\000\000\000\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\000\000\000\000\001\000\000\000\002\000\000\000\002\000\000\000\002\000\000\000\002\000\000\000\002\000\000\000\001\000\000\000\000\000\000\000\377\377\377\377\376\377\377\377\376\377\377\377\376\377\377\377\376\377\377\377\376\377\377\377\000\000\310C\000\000\000\000\377\377\377\377\377\377\377\377\000\000\000\000\001\000\000\000\001\000\000\000\001\000\000\000\000\000\000\000\377\377\377\377\376\377\377\377\376\377\377\377\376\377\377\377\376\377\377\377\377\377\377\377\000\000\000\000\001\000\000\000\002\000\000\000\002\000\000\000\002\000\000\000\002\000\000\000\002\000\000\000\001", 253u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000156C), "\377\377\377\377\376\377\377\377\004\002\001<\000\001\0008\000\000\200:\000\001\0008", 24u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001598), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000015B4), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000015BE), "\\B\000\000\024C\000\000jC\000\000\030C\000\000>C\000\000aC\204bQ", 25u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000015DC), ".?AVRestartGame@@", 17u); storage[UINT32_C(0x000015ED)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000015F0), "\320\007\000\000\254EP\000\264EP\000\004\002\001<\000\001\0008\000\000\200:\000\001\0008\000\000\000\000hFP\000dFP\000`FP\000\\FP\000XFP\000TFP\000PFP\000LFP\000HFP\000DFP\000@FP\000<FP\0008FP\0004FP\0000FP\000\363\345\373\340\356\375\377\350\376\374\372\000,FP\000(FP\000XFP\000$FP\000 FP\000\034FP\000\030FP\000\024FP\000\020FP\000\014FP\000\010FP\000\004FP\000\000FP\000\374EP\0008FP\000\370EP\000\364EP\000\360EP\0004FP\000\354EP\000\350EP\000\345e\363y\352k\343r\3473\365x\350u\3560o\360p\361c\340a\362mE\305\323YK\312\307X\325O\316\320PC\321A\300", 230u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000016D8), "qwertyuiopasdfghjklzxcvbnm", 26u); storage[UINT32_C(0x000016F2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000016F4), "QWERTYUIOPASDFGHJKLZXCVBNM", 26u); storage[UINT32_C(0x0000170E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001710), "\004\002\001<\000\001\0008\000\000\200:\000\001\0008\004\002\001<\000\001\0008\000\000\200:\000\001\0008\204bQ", 35u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001738), ".?AVNatureRainListener@@", 24u); storage[UINT32_C(0x00001750)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001754), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000175C), ".?AVLightingListener@@", 22u); storage[UINT32_C(0x00001772)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001774), "$KP\000\344\371O\000\004\002\001<\000\001\0008\000\000\200:\000\001\0008\004\002\001<\000\001\0008\000\000\200:\000\001\0008K\r\357`\260\232p\000K\r\357`\311\232p\016\003\000\000\000\000\000\000\000\001\000\000\000\003\000\000\000\005\000\000\000\004\000\000\000\002\000\000\000\004\002\001<\000\001\0008\000\000\200:\000\001\0008", 100u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000017F0), "\377\377\377\377", 4u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001808), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001824), "\017\000\000\000\000\000\000\000\004\002\001<\000\001\0008\000\000\200:\000\001\0008", 24u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001854), "\200\000\000\000\204bQ", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001860), ".?AVCSoundFX@@", 14u); storage[UINT32_C(0x0000186E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001870), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001878), ".?AVCSound@@", 12u); storage[UINT32_C(0x00001884)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001888), "\001\000\000\000\001\000\000\000@B\017\000\377\377\377\377\004\002\001<\000\001\0008\000\000\200:\000\001\0008\001", 33u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000018B4), "\005\000\000\000\001\000\000\000\010\000\000\000\005\000\000\000\005\000\000\000\001\000\000\000\004\000\000\000\000\000\000\000\003\000\000\000\010\000\000\000\007\000\000\000\t\000\000\000\t\000\000\000\000\000\000\000\003\000\000\000\005\000\000\000\005\000\000\000\006\000\000\000\006\000\000\000\001\000\000\000\006\000\000\000\004\000\000\000\003\000\000\000\000\000\000\000\006\000\000\000\010\000\000\000\010\000\000\000\007\000\000\000\001\000\000\000\010\000\000\000\007\000\000\000\005\000\000\000\003\000\000\000\000\000\000\000\007\000\000\000\010\000\000\000\005\000\000\000\002\000\000\000\010\000\000\000\002\000\000\000\004\000\000\000\003\000\000\000\000\000\000\000\003\000\000\000\001\000\000\000\001\000\000\000\t\000\000\000\004\000\000\000\001\000\000\000\204bQ", 199u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001980), ".?AVCWebBrowserException@@", 26u); storage[UINT32_C(0x0000199A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000019A0), "\\\217B>q=\212>{\024\256>\000\000\000?\303\365(?H\341", 22u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000019B6), ":?)\\O?Wrong format of \"Landscape\\zoning.cfg\"", 44u); storage[UINT32_C(0x000019E2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000019E4), "\004\002\001<\000\001\0008\000\000\200:\000\001\0008\204bQ", 19u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000019FC), ".?AVButtonCtrl@SphereUI@@", 25u); storage[UINT32_C(0x00001A15)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001A18), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001A20), ".?AVWindow@SphereUI@@", 21u); storage[UINT32_C(0x00001A35)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001A4C), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001A68), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001A78), ".?AVCheckBox@SphereUI@@", 23u); storage[UINT32_C(0x00001A8F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001AA4), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001AC0), "\017\000\000\000\000\000\000\000PlP\000DlP\000<lP\000\3702P\000\204bQ", 27u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001AE0), ".?AVCDescriptionWindow@SphereUI@@", 33u); storage[UINT32_C(0x00001B01)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B04), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B0C), ".?AVCUncopyable@@", 17u); storage[UINT32_C(0x00001B1D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B34), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B50), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B60), ".?AVEditCtrl@SphereUI@@", 23u); storage[UINT32_C(0x00001B77)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001B8C), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001BA8), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001BB8), ".?AVFilterListCtrl@SphereUI@@", 29u); storage[UINT32_C(0x00001BD5)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001BD8), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001BE0), ".?AVListCtrl@SphereUI@@", 23u); storage[UINT32_C(0x00001BF7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C0C), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C28), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C38), ".?AVFontPicker@SphereUI@@", 25u); storage[UINT32_C(0x00001C51)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C68), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001C84), "\017\000\000\000\000\000\000\000\250rP\000hrP", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001CA8), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001CC4), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001CD4), ".?AVHyperTextChatListControl@SphereUI@@", 39u); storage[UINT32_C(0x00001CFB)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001D10), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001D2C), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001D3C), ".?AVHyperTextCtrl@SphereUI@@", 28u); storage[UINT32_C(0x00001D58)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001D70), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001D8C), "\017\000\000\000\000\000\000\000huP\000hrP\000\001\000\000\000\002\000\000\000\003\000\000\000\376\377\377\377\001\000\000\000\377\377\377\377\376\377\377\377\375\377\377\377\002\000\000\000\377\377\377\377\000\000\000\000\376\377\377\377\002\000\000\000\000\000\000\000\377\377\377\377\376\377\377\377\002\000\000\000\377\377\377\377\000\000\000\000\001", 93u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001E00), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001E1C), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001E2C), ".?AVbad_cast@std@@", 18u); storage[UINT32_C(0x00001E3E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001E40), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001E48), ".?AV?$basic_filebuf@DU?$char_traits@D@std@@@std@@", 49u); storage[UINT32_C(0x00001E79)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001E7C), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001E84), ".?AV?$basic_streambuf@DU?$char_traits@D@std@@@std@@", 51u); storage[UINT32_C(0x00001EB7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001EB8), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001EC0), ".?AV?$basic_ofstream@DU?$char_traits@D@std@@@std@@", 50u); storage[UINT32_C(0x00001EF2)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001EF4), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001EFC), ".?AV?$basic_ostream@DU?$char_traits@D@std@@@std@@", 49u); storage[UINT32_C(0x00001F2D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F30), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F38), ".?AV?$basic_ios@DU?$char_traits@D@std@@@std@@", 45u); storage[UINT32_C(0x00001F65)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F68), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F70), ".?AVios_base@std@@", 18u); storage[UINT32_C(0x00001F82)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F84), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001F8C), ".?AV?$_Iosb@H@std@@", 19u); storage[UINT32_C(0x00001F9F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001FA0), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001FA8), ".?AV?$basic_ifstream@DU?$char_traits@D@std@@@std@@", 50u); storage[UINT32_C(0x00001FDA)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00001FDC), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00001FE4), ".?AV?$basic_istream@DU?$char_traits@D@std@@@std@@", 49u); storage[UINT32_C(0x00002015)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002018), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002020), ".?AVHyperTextEditControl@SphereUI@@", 35u); storage[UINT32_C(0x00002043)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002044), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000204C), ".?AVImageCtrl@SphereUI@@", 24u); storage[UINT32_C(0x00002064)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000207C), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002098), "\017\000\000\000\000\000\000\000\377\000\000\000\001\001\000\000\001\000\000\000\001\000\000\000xxP\000\001\000\000\000\001", 33u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000020D0), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000020EC), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000020F8), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002100), ".?AV?$basic_stringbuf@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@", 68u); storage[UINT32_C(0x00002144)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002148), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002150), ".?AV?$basic_ostringstream@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@", 72u); storage[UINT32_C(0x00002198)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000219C), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000021A4), ".?AVListItemCtrl@SphereUI@@", 27u); storage[UINT32_C(0x000021BF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000021D4), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000021F0), "\017\000\000\000\000\000\000\000\033\000\000\000\001\000\000\000p\000\000\000;\000\000\000q\000\000\000<\000\000\000r\000\000\000=\000\000\000s\000\000\000>\000\000\000t\000\000\000?\000\000\000u\000\000\000@\000\000\000v\000\000\000A\000\000\000w\000\000\000B\000\000\000x\000\000\000C\000\000\000y\000\000\000D\000\000\000z\000\000\000W\000\000\000{\000\000\000X\000\000\000\221\000\000\000F\000\000\000\023\000\000\000\305\000\000\000\010\000\000\000\016\000\000\000 \000\000\0009\000\000\000#\000\000\000\317\000\000\000$\000\000\000\307\000\000\000%\000\000\000\313\000\000\000&\000\000\000\310\000\000\000'\000\000\000\315\000\000\000(\000\000\000\320\000\000\000-\000\000\000\322\000\000\000.\000\000\000\323\000\000\000\r\000\000\000\034\000\000\000\024\000\000\000:\000\000\000`\000\000\000R\000\000\000a\000\000\000O\000\000\000b\000\000\000P\000\000\000c\000\000\000Q", 253u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000022F0), "d\000\000\000K\000\000\000e\000\000\000L\000\000\000f\000\000\000M\000\000\000g\000\000\000G\000\000\000h\000\000\000H\000\000\000i\000\000\000I\000\000\000j\000\000\0007\000\000\000k\000\000\000N\000\000\000\220\000\000\000E\000\000\000m\000\000\000J\000\000\000o\000\000\000\265\000\000\000n\000\000\000S\000\000\000!\000\000\000\311\000\000\000\"\000\000\000\321\000\000\000\300\000\000\000)\000\000\0001\000\000\000\002\000\000\0002\000\000\000\003\000\000\0003\000\000\000\004\000\000\0004\000\000\000\005\000\000\0005\000\000\000\006\000\000\0006\000\000\000\007\000\000\0007\000\000\000\010\000\000\0008\000\000\000\t\000\000\0009\000\000\000\n\000\000\0000\000\000\000\013\000\000\000\275\000\000\000\014\000\000\000\273\000\000\000\r\000\000\000\334\000\000\000+\000\000\000Q\000\000\000\020\000\000\000W\000\000\000\021\000\000\000E\000\000\000\022\000\000\000R\000\000\000\023", 253u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000023F0), "T\000\000\000\024\000\000\000Y\000\000\000\025\000\000\000U\000\000\000\026\000\000\000I\000\000\000\027\000\000\000O\000\000\000\030\000\000\000P\000\000\000\031\000\000\000\333\000\000\000\032\000\000\000\335\000\000\000\033\000\000\000A\000\000\000\036\000\000\000S\000\000\000\037\000\000\000D\000\000\000 \000\000\000F\000\000\000!\000\000\000G\000\000\000\"\000\000\000H\000\000\000#\000\000\000J\000\000\000$\000\000\000K\000\000\000%\000\000\000L\000\000\000&\000\000\000\272\000\000\000'\000\000\000\336\000\000\000(\000\000\000Z\000\000\000,\000\000\000X\000\000\000-\000\000\000C\000\000\000.\000\000\000V\000\000\000/\000\000\000B\000\000\0000\000\000\000N\000\000\0001\000\000\000M\000\000\0002\000\000\000\274\000\000\0003\000\000\000\276\000\000\0004\000\000\000\277\000\000\0005\000\000\000\t\000\000\000\017\000\000\000\021\000\000\000\035\000\000\000\020\000\000\000*", 253u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000024F0), "\364~P\000\033\000\000\000\360~P\000p\000\000\000\354~P\000q\000\000\000\350~P\000r\000\000\000\344~P\000s\000\000\000\340~P\000t\000\000\000\334~P\000u\000\000\000\330~P\000v\000\000\000\324~P\000w\000\000\000\320~P\000x\000\000\000\314~P\000y\000\000\000\310~P\000z\000\000\000\304~P\000{\000\000\000\270~P\000\221\000\000\000\260~P\000\023\000\000\000\244~P\000\010\000\000\000\234~P\000 \000\000\000\230~P\000#\000\000\000\220~P\000$\000\000\000\210~P\000%\000\000\000\204~P\000&\000\000\000@tP\000'\000\000\000|~P\000(\000\000\000t~P\000-\000\000\000l~P\000.\000\000\000d~P\000\r\000\000\000X~P\000\024\000\000\000P~P\000`\000\000\000H~P\000a\000\000\000@~P\000b\000\000\0008~P\000c\000\000\0000~P\000d", 253u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000025F0), "(~P\000e\000\000\000 ~P\000f\000\000\000\030~P\000g\000\000\000\020~P\000h\000\000\000\010~P\000i\000\000\000\374}P\000j\000\000\000\360}P\000k\000\000\000\350}P\000\220\000\000\000\334}P\000m\000\000\000\320}P\000o\000\000\000\304}P\000n\000\000\000\274}P\000!\000\000\000\260}P\000\"\000\000\000\254}P\000\300\000\000\000\250}P\0001\000\000\000\244}P\0002\000\000\000\240}P\0003\000\000\000\234}P\0004\000\000\000\230}P\0005\000\000\000\224}P\0006\000\000\000\220}P\0007\000\000\000\214}P\0008\000\000\000\210}P\0009\000\000\000\204}P\0000\000\000\000\200}P\000\275\000\000\000|}P\000\273\000\000\000\370XP\000\334\000\000\000x}P\000Q\000\000\000t}P\000W\000\000\000p}P\000E\000\000\000l}P\000R\000\000\000h}P\000T", 253u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000026F0), "d}P\000Y\000\000\000`}P\000U\000\000\000\\}P\000I\000\000\000X}P\000O\000\000\000T}P\000P\000\000\000P}P\000\333\000\000\000L}P\000\335\000\000\000H}P\000A\000\000\000D}P\000S\000\000\000@}P\000D\000\000\000<}P\000F\000\000\0008}P\000G\000\000\0004}P\000H\000\000\0000}P\000J\000\000\000,}P\000K\000\000\000(}P\000L\000\000\000$}P\000\272\000\000\000 }P\000\336\000\000\000\034}P\000Z\000\000\000\030}P\000X\000\000\000\024}P\000C\000\000\000\020}P\000V\000\000\000\014}P\000B\000\000\000\010}P\000N\000\000\000\004}P\000M\000\000\000\034rP\000\274\000\000\0004_P\000\276\000\000\000\000}P\000\277\000\000\000\374|P\000\t\000\000\000\364|P\000\021\000\000\000\354|P\000\020", 245u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000027FC), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002818), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002828), ".?AVCMenuListControl@SphereUI@@", 31u); storage[UINT32_C(0x00002847)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000285C), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002878), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002894), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000028B0), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000028CC), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000028DC), ".?AVMiniHelpCtrl@SphereUI@@", 27u); storage[UINT32_C(0x000028F7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000028F8), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002900), ".?AVToolTipCtrl@SphereUI@@", 26u); storage[UINT32_C(0x0000291A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002930), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000294C), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000295C), ".?AVCMinimapControl@SphereUI@@", 30u); storage[UINT32_C(0x0000297A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002990), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000029AC), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000029BC), ".?AVProgressBar@SphereUI@@", 26u); storage[UINT32_C(0x000029D6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000029EC), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002A08), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002A18), ".?AVRadioButtonCtrl@SphereUI@@", 30u); storage[UINT32_C(0x00002A36)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002A4C), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002A68), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002A78), ".?AVRichEditCtrl@SphereUI@@", 27u); storage[UINT32_C(0x00002A93)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002AA8), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002AC4), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002AD4), ".?AVScrollBar@SphereUI@@", 24u); storage[UINT32_C(0x00002AEC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002B04), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002B20), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002B30), ".?AVSliderCtrl@SphereUI@@", 25u); storage[UINT32_C(0x00002B49)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002B60), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002B7C), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002B8C), ".?AVSlotCtrl@SphereUI@@", 23u); storage[UINT32_C(0x00002BA3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002BB8), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002BD4), "\017\000\000\000\000\000\000\000\377\377\377\377", 12u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002BF4), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002C10), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002C20), ".?AVSpinButton@SphereUI@@", 25u); storage[UINT32_C(0x00002C39)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002C50), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002C6C), "\017\000\000\000\000\000\000\000\377\377\377\377\204bQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002C80), ".?AVTextCtrl@SphereUI@@", 23u); storage[UINT32_C(0x00002C97)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002CAC), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002CC8), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002CE4), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D00), "\017\000\000\000\000\000\000\000\204bQ", 11u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D10), ".?AVCWebBrowserControl@SphereUI@@", 33u); storage[UINT32_C(0x00002D31)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D48), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D64), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D80), "\017", 1u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002D9C), "\017\000\000\000\000\000\000\000\001\000\000\000\204bQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002DB0), ".?AVCCursor@@", 13u); storage[UINT32_C(0x00002DBD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002DC0), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002DC8), ".?AVCHardwareCursor@@", 21u); storage[UINT32_C(0x00002DDD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002DE0), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002DE8), ".?AVCSoftwareCursor@@", 21u); storage[UINT32_C(0x00002DFD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002E00), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002E08), ".?AVUnmanagedResourceBase@@", 27u); storage[UINT32_C(0x00002E23)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002E24), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002E2C), ".?AV?$BaseVect@PAVUnmanagedResourceBase@@@@", 43u); storage[UINT32_C(0x00002E57)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002E58), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002E60), ".?AVUnmanagedResourceVB@@", 25u); storage[UINT32_C(0x00002E79)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002E7C), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002E84), ".?AVUnmanagedResourceIB@@", 25u); storage[UINT32_C(0x00002E9D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002EA0), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002EA8), ".?AVUnmanagedResourceTexture@@", 30u); storage[UINT32_C(0x00002EC6)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002EC8), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002ED0), ".?AV?$Vect@PAVUnmanagedResourceBase@@@@", 39u); storage[UINT32_C(0x00002EF7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002EF8), "\004\002\001<\000\001\0008\000\000\200:\000\001", 14u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F07), "81.1.3", 6u); storage[UINT32_C(0x00002F0D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F10), "1.1.3", 5u); storage[UINT32_C(0x00002F15)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F18), "1.1.3", 5u); storage[UINT32_C(0x00002F1D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F20), "unknown compression method", 26u); storage[UINT32_C(0x00002F3A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F3C), "invalid window size", 19u); storage[UINT32_C(0x00002F4F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F50), "incorrect header check", 22u); storage[UINT32_C(0x00002F66)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F68), "need dictionary", 15u); storage[UINT32_C(0x00002F77)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F78), "incorrect data check", 20u); storage[UINT32_C(0x00002F8C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F90), "\224/R", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F94), "1.1.3", 5u); storage[UINT32_C(0x00002F99)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002F9C), "invalid block type", 18u); storage[UINT32_C(0x00002FAE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002FB0), "invalid stored block lengths", 28u); storage[UINT32_C(0x00002FCC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002FD0), "too many length or distance symbols", 35u); storage[UINT32_C(0x00002FF3)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00002FF4), "invalid bit length repeat", 25u); storage[UINT32_C(0x0000300D)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003010), "80R\000H0R\000@\317\364\004T0R\000`0R\000p0R\000|0R\000\2200R\000\2400R\000D\317\364\004", 40u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003038), "need dictionary", 15u); storage[UINT32_C(0x00003047)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003048), "stream end", 10u); storage[UINT32_C(0x00003052)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003054), "file error", 10u); storage[UINT32_C(0x0000305E)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003060), "stream error", 12u); storage[UINT32_C(0x0000306C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003070), "data error", 10u); storage[UINT32_C(0x0000307A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000307C), "insufficient memory", 19u); storage[UINT32_C(0x0000308F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003090), "buffer error", 12u); storage[UINT32_C(0x0000309C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000030A0), "incompatible version", 20u); storage[UINT32_C(0x000030B4)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000030B8), "1.1.3", 5u); storage[UINT32_C(0x000030BD)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000030C0), "\250\252P\000P\251P\000\001\001\000\000\036\001\000\000\017\000\000\000\000\000\000\000(\257P\000\310\251P\000\000\000\000\000\036\000\000\000\017", 41u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000030F4), "@\252P\000\000\000\000\000\023\000\000\000\007", 13u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003104), "invalid literal/length code", 27u); storage[UINT32_C(0x0000311F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003120), "invalid distance code", 21u); storage[UINT32_C(0x00003135)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00003138), "\t\000\000\000\005\000\000\000`\007\000\000\000\001\000\000\000\010\000\000P\000\000\000\000\010\000\000\020\000\000\000T\010\000\000s\000\000\000R\007\000\000\037\000\000\000\000\010\000\000p\000\000\000\000\010\000\0000\000\000\000\000\t\000\000\300\000\000\000P\007\000\000\n\000\000\000\000\010\000\000`\000\000\000\000\010\000\000 \000\000\000\000\t\000\000\240\000\000\000\000\010\000\000\000\000\000\000\000\010\000\000\200\000\000\000\000\010\000\000@\000\000\000\000\t\000\000\340\000\000\000P\007\000\000\006\000\000\000\000\010\000\000X\000\000\000\000\010\000\000\030\000\000\000\000\t\000\000\220\000\000\000S\007\000\000;\000\000\000\000\010\000\000x\000\000\000\000\010\000\0008\000\000\000\000\t\000\000\320\000\000\000Q\007\000\000\021\000\000\000\000\010\000\000h\000\000\000\000\010\000\000(\000\000\000\000\t\000\000\260\000\000\000\000\010\000\000\010\000\000\000\000\010\000\000\210\000\000\000\000\010\000\000H", 253u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003239), "\t\000\000\360\000\000\000P\007\000\000\004\000\000\000\000\010\000\000T\000\000\000\000\010\000\000\024\000\000\000U\010\000\000\343\000\000\000S\007\000\000+\000\000\000\000\010\000\000t\000\000\000\000\010\000\0004\000\000\000\000\t\000\000\310\000\000\000Q\007\000\000\r\000\000\000\000\010\000\000d\000\000\000\000\010\000\000$\000\000\000\000\t\000\000\250\000\000\000\000\010\000\000\004\000\000\000\000\010\000\000\204\000\000\000\000\010\000\000D\000\000\000\000\t\000\000\350\000\000\000P\007\000\000\010\000\000\000\000\010\000\000\\\000\000\000\000\010\000\000\034\000\000\000\000\t\000\000\230\000\000\000T\007\000\000S\000\000\000\000\010\000\000|\000\000\000\000\010\000\000<\000\000\000\000\t\000\000\330\000\000\000R\007\000\000\027\000\000\000\000\010\000\000l\000\000\000\000\010\000\000,\000\000\000\000\t\000\000\270\000\000\000\000\010\000\000\014\000\000\000\000\010\000\000\214\000\000\000\000\010\000\000L", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003339), "\t\000\000\370\000\000\000P\007\000\000\003\000\000\000\000\010\000\000R\000\000\000\000\010\000\000\022\000\000\000U\010\000\000\243\000\000\000S\007\000\000#\000\000\000\000\010\000\000r\000\000\000\000\010\000\0002\000\000\000\000\t\000\000\304\000\000\000Q\007\000\000\013\000\000\000\000\010\000\000b\000\000\000\000\010\000\000\"\000\000\000\000\t\000\000\244\000\000\000\000\010\000\000\002\000\000\000\000\010\000\000\202\000\000\000\000\010\000\000B\000\000\000\000\t\000\000\344\000\000\000P\007\000\000\007\000\000\000\000\010\000\000Z\000\000\000\000\010\000\000\032\000\000\000\000\t\000\000\224\000\000\000T\007\000\000C\000\000\000\000\010\000\000z\000\000\000\000\010\000\000:\000\000\000\000\t\000\000\324\000\000\000R\007\000\000\023\000\000\000\000\010\000\000j\000\000\000\000\010\000\000*\000\000\000\000\t\000\000\264\000\000\000\000\010\000\000\n\000\000\000\000\010\000\000\212\000\000\000\000\010\000\000J", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003439), "\t\000\000\364\000\000\000P\007\000\000\005\000\000\000\000\010\000\000V\000\000\000\000\010\000\000\026\000\000\000\300\010\000\000\000\000\000\000S\007\000\0003\000\000\000\000\010\000\000v\000\000\000\000\010\000\0006\000\000\000\000\t\000\000\314\000\000\000Q\007\000\000\017\000\000\000\000\010\000\000f\000\000\000\000\010\000\000&\000\000\000\000\t\000\000\254\000\000\000\000\010\000\000\006\000\000\000\000\010\000\000\206\000\000\000\000\010\000\000F\000\000\000\000\t\000\000\354\000\000\000P\007\000\000\t\000\000\000\000\010\000\000^\000\000\000\000\010\000\000\036\000\000\000\000\t\000\000\234\000\000\000T\007\000\000c\000\000\000\000\010\000\000~\000\000\000\000\010\000\000>\000\000\000\000\t\000\000\334\000\000\000R\007\000\000\033\000\000\000\000\010\000\000n\000\000\000\000\010\000\000.\000\000\000\000\t\000\000\274\000\000\000\000\010\000\000\016\000\000\000\000\010\000\000\216\000\000\000\000\010\000\000N", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003539), "\t\000\000\374\000\000\000`\007\000\000\000\001\000\000\000\010\000\000Q\000\000\000\000\010\000\000\021\000\000\000U\010\000\000\203\000\000\000R\007\000\000\037\000\000\000\000\010\000\000q\000\000\000\000\010\000\0001\000\000\000\000\t\000\000\302\000\000\000P\007\000\000\n\000\000\000\000\010\000\000a\000\000\000\000\010\000\000!\000\000\000\000\t\000\000\242\000\000\000\000\010\000\000\001\000\000\000\000\010\000\000\201\000\000\000\000\010\000\000A\000\000\000\000\t\000\000\342\000\000\000P\007\000\000\006\000\000\000\000\010\000\000Y\000\000\000\000\010\000\000\031\000\000\000\000\t\000\000\222\000\000\000S\007\000\000;\000\000\000\000\010\000\000y\000\000\000\000\010\000\0009\000\000\000\000\t\000\000\322\000\000\000Q\007\000\000\021\000\000\000\000\010\000\000i\000\000\000\000\010\000\000)\000\000\000\000\t\000\000\262\000\000\000\000\010\000\000\t\000\000\000\000\010\000\000\211\000\000\000\000\010\000\000I", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003639), "\t\000\000\362\000\000\000P\007\000\000\004\000\000\000\000\010\000\000U\000\000\000\000\010\000\000\025\000\000\000P\010\000\000\002\001\000\000S\007\000\000+\000\000\000\000\010\000\000u\000\000\000\000\010\000\0005\000\000\000\000\t\000\000\312\000\000\000Q\007\000\000\r\000\000\000\000\010\000\000e\000\000\000\000\010\000\000%\000\000\000\000\t\000\000\252\000\000\000\000\010\000\000\005\000\000\000\000\010\000\000\205\000\000\000\000\010\000\000E\000\000\000\000\t\000\000\352\000\000\000P\007\000\000\010\000\000\000\000\010\000\000]\000\000\000\000\010\000\000\035\000\000\000\000\t\000\000\232\000\000\000T\007\000\000S\000\000\000\000\010\000\000}\000\000\000\000\010\000\000=\000\000\000\000\t\000\000\332\000\000\000R\007\000\000\027\000\000\000\000\010\000\000m\000\000\000\000\010\000\000-\000\000\000\000\t\000\000\272\000\000\000\000\010\000\000\r\000\000\000\000\010\000\000\215\000\000\000\000\010\000\000M", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003739), "\t\000\000\372\000\000\000P\007\000\000\003\000\000\000\000\010\000\000S\000\000\000\000\010\000\000\023\000\000\000U\010\000\000\303\000\000\000S\007\000\000#\000\000\000\000\010\000\000s\000\000\000\000\010\000\0003\000\000\000\000\t\000\000\306\000\000\000Q\007\000\000\013\000\000\000\000\010\000\000c\000\000\000\000\010\000\000#\000\000\000\000\t\000\000\246\000\000\000\000\010\000\000\003\000\000\000\000\010\000\000\203\000\000\000\000\010\000\000C\000\000\000\000\t\000\000\346\000\000\000P\007\000\000\007\000\000\000\000\010\000\000[\000\000\000\000\010\000\000\033\000\000\000\000\t\000\000\226\000\000\000T\007\000\000C\000\000\000\000\010\000\000{\000\000\000\000\010\000\000;\000\000\000\000\t\000\000\326\000\000\000R\007\000\000\023\000\000\000\000\010\000\000k\000\000\000\000\010\000\000+\000\000\000\000\t\000\000\266\000\000\000\000\010\000\000\013\000\000\000\000\010\000\000\213\000\000\000\000\010\000\000K", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003839), "\t\000\000\366\000\000\000P\007\000\000\005\000\000\000\000\010\000\000W\000\000\000\000\010\000\000\027\000\000\000\300\010\000\000\000\000\000\000S\007\000\0003\000\000\000\000\010\000\000w\000\000\000\000\010\000\0007\000\000\000\000\t\000\000\316\000\000\000Q\007\000\000\017\000\000\000\000\010\000\000g\000\000\000\000\010\000\000'\000\000\000\000\t\000\000\256\000\000\000\000\010\000\000\007\000\000\000\000\010\000\000\207\000\000\000\000\010\000\000G\000\000\000\000\t\000\000\356\000\000\000P\007\000\000\t\000\000\000\000\010\000\000_\000\000\000\000\010\000\000\037\000\000\000\000\t\000\000\236\000\000\000T\007\000\000c\000\000\000\000\010\000\000\177\000\000\000\000\010\000\000?\000\000\000\000\t\000\000\336\000\000\000R\007\000\000\033\000\000\000\000\010\000\000o\000\000\000\000\010\000\000/\000\000\000\000\t\000\000\276\000\000\000\000\010\000\000\017\000\000\000\000\010\000\000\217\000\000\000\000\010\000\000O", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003939), "\t\000\000\376\000\000\000`\007\000\000\000\001\000\000\000\010\000\000P\000\000\000\000\010\000\000\020\000\000\000T\010\000\000s\000\000\000R\007\000\000\037\000\000\000\000\010\000\000p\000\000\000\000\010\000\0000\000\000\000\000\t\000\000\301\000\000\000P\007\000\000\n\000\000\000\000\010\000\000`\000\000\000\000\010\000\000 \000\000\000\000\t\000\000\241\000\000\000\000\010\000\000\000\000\000\000\000\010\000\000\200\000\000\000\000\010\000\000@\000\000\000\000\t\000\000\341\000\000\000P\007\000\000\006\000\000\000\000\010\000\000X\000\000\000\000\010\000\000\030\000\000\000\000\t\000\000\221\000\000\000S\007\000\000;\000\000\000\000\010\000\000x\000\000\000\000\010\000\0008\000\000\000\000\t\000\000\321\000\000\000Q\007\000\000\021\000\000\000\000\010\000\000h\000\000\000\000\010\000\000(\000\000\000\000\t\000\000\261\000\000\000\000\010\000\000\010\000\000\000\000\010\000\000\210\000\000\000\000\010\000\000H", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003A39), "\t\000\000\361\000\000\000P\007\000\000\004\000\000\000\000\010\000\000T\000\000\000\000\010\000\000\024\000\000\000U\010\000\000\343\000\000\000S\007\000\000+\000\000\000\000\010\000\000t\000\000\000\000\010\000\0004\000\000\000\000\t\000\000\311\000\000\000Q\007\000\000\r\000\000\000\000\010\000\000d\000\000\000\000\010\000\000$\000\000\000\000\t\000\000\251\000\000\000\000\010\000\000\004\000\000\000\000\010\000\000\204\000\000\000\000\010\000\000D\000\000\000\000\t\000\000\351\000\000\000P\007\000\000\010\000\000\000\000\010\000\000\\\000\000\000\000\010\000\000\034\000\000\000\000\t\000\000\231\000\000\000T\007\000\000S\000\000\000\000\010\000\000|\000\000\000\000\010\000\000<\000\000\000\000\t\000\000\331\000\000\000R\007\000\000\027\000\000\000\000\010\000\000l\000\000\000\000\010\000\000,\000\000\000\000\t\000\000\271\000\000\000\000\010\000\000\014\000\000\000\000\010\000\000\214\000\000\000\000\010\000\000L", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003B39), "\t\000\000\371\000\000\000P\007\000\000\003\000\000\000\000\010\000\000R\000\000\000\000\010\000\000\022\000\000\000U\010\000\000\243\000\000\000S\007\000\000#\000\000\000\000\010\000\000r\000\000\000\000\010\000\0002\000\000\000\000\t\000\000\305\000\000\000Q\007\000\000\013\000\000\000\000\010\000\000b\000\000\000\000\010\000\000\"\000\000\000\000\t\000\000\245\000\000\000\000\010\000\000\002\000\000\000\000\010\000\000\202\000\000\000\000\010\000\000B\000\000\000\000\t\000\000\345\000\000\000P\007\000\000\007\000\000\000\000\010\000\000Z\000\000\000\000\010\000\000\032\000\000\000\000\t\000\000\225\000\000\000T\007\000\000C\000\000\000\000\010\000\000z\000\000\000\000\010\000\000:\000\000\000\000\t\000\000\325\000\000\000R\007\000\000\023\000\000\000\000\010\000\000j\000\000\000\000\010\000\000*\000\000\000\000\t\000\000\265\000\000\000\000\010\000\000\n\000\000\000\000\010\000\000\212\000\000\000\000\010\000\000J", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003C39), "\t\000\000\365\000\000\000P\007\000\000\005\000\000\000\000\010\000\000V\000\000\000\000\010\000\000\026\000\000\000\300\010\000\000\000\000\000\000S\007\000\0003\000\000\000\000\010\000\000v\000\000\000\000\010\000\0006\000\000\000\000\t\000\000\315\000\000\000Q\007\000\000\017\000\000\000\000\010\000\000f\000\000\000\000\010\000\000&\000\000\000\000\t\000\000\255\000\000\000\000\010\000\000\006\000\000\000\000\010\000\000\206\000\000\000\000\010\000\000F\000\000\000\000\t\000\000\355\000\000\000P\007\000\000\t\000\000\000\000\010\000\000^\000\000\000\000\010\000\000\036\000\000\000\000\t\000\000\235\000\000\000T\007\000\000c\000\000\000\000\010\000\000~\000\000\000\000\010\000\000>\000\000\000\000\t\000\000\335\000\000\000R\007\000\000\033\000\000\000\000\010\000\000n\000\000\000\000\010\000\000.\000\000\000\000\t\000\000\275\000\000\000\000\010\000\000\016\000\000\000\000\010\000\000\216\000\000\000\000\010\000\000N", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003D39), "\t\000\000\375\000\000\000`\007\000\000\000\001\000\000\000\010\000\000Q\000\000\000\000\010\000\000\021\000\000\000U\010\000\000\203\000\000\000R\007\000\000\037\000\000\000\000\010\000\000q\000\000\000\000\010\000\0001\000\000\000\000\t\000\000\303\000\000\000P\007\000\000\n\000\000\000\000\010\000\000a\000\000\000\000\010\000\000!\000\000\000\000\t\000\000\243\000\000\000\000\010\000\000\001\000\000\000\000\010\000\000\201\000\000\000\000\010\000\000A\000\000\000\000\t\000\000\343\000\000\000P\007\000\000\006\000\000\000\000\010\000\000Y\000\000\000\000\010\000\000\031\000\000\000\000\t\000\000\223\000\000\000S\007\000\000;\000\000\000\000\010\000\000y\000\000\000\000\010\000\0009\000\000\000\000\t\000\000\323\000\000\000Q\007\000\000\021\000\000\000\000\010\000\000i\000\000\000\000\010\000\000)\000\000\000\000\t\000\000\263\000\000\000\000\010\000\000\t\000\000\000\000\010\000\000\211\000\000\000\000\010\000\000I", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003E39), "\t\000\000\363\000\000\000P\007\000\000\004\000\000\000\000\010\000\000U\000\000\000\000\010\000\000\025\000\000\000P\010\000\000\002\001\000\000S\007\000\000+\000\000\000\000\010\000\000u\000\000\000\000\010\000\0005\000\000\000\000\t\000\000\313\000\000\000Q\007\000\000\r\000\000\000\000\010\000\000e\000\000\000\000\010\000\000%\000\000\000\000\t\000\000\253\000\000\000\000\010\000\000\005\000\000\000\000\010\000\000\205\000\000\000\000\010\000\000E\000\000\000\000\t\000\000\353\000\000\000P\007\000\000\010\000\000\000\000\010\000\000]\000\000\000\000\010\000\000\035\000\000\000\000\t\000\000\233\000\000\000T\007\000\000S\000\000\000\000\010\000\000}\000\000\000\000\010\000\000=\000\000\000\000\t\000\000\333\000\000\000R\007\000\000\027\000\000\000\000\010\000\000m\000\000\000\000\010\000\000-\000\000\000\000\t\000\000\273\000\000\000\000\010\000\000\r\000\000\000\000\010\000\000\215\000\000\000\000\010\000\000M", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00003F39), "\t\000\000\373\000\000\000P\007\000\000\003\000\000\000\000\010\000\000S\000\000\000\000\010\000\000\023\000\000\000U\010\000\000\303\000\000\000S\007\000\000#\000\000\000\000\010\000\000s\000\000\000\000\010\000\0003\000\000\000\000\t\000\000\307\000\000\000Q\007\000\000\013\000\000\000\000\010\000\000c\000\000\000\000\010\000\000#\000\000\000\000\t\000\000\247\000\000\000\000\010\000\000\003\000\000\000\000\010\000\000\203\000\000\000\000\010\000\000C\000\000\000\000\t\000\000\347\000\000\000P\007\000\000\007\000\000\000\000\010\000\000[\000\000\000\000\010\000\000\033\000\000\000\000\t\000\000\227\000\000\000T\007\000\000C\000\000\000\000\010\000\000{\000\000\000\000\010\000\000;\000\000\000\000\t\000\000\327\000\000\000R\007\000\000\023\000\000\000\000\010\000\000k\000\000\000\000\010\000\000+\000\000\000\000\t\000\000\267\000\000\000\000\010\000\000\013\000\000\000\000\010\000\000\213\000\000\000\000\010\000\000K", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00004039), "\t\000\000\367\000\000\000P\007\000\000\005\000\000\000\000\010\000\000W\000\000\000\000\010\000\000\027\000\000\000\300\010\000\000\000\000\000\000S\007\000\0003\000\000\000\000\010\000\000w\000\000\000\000\010\000\0007\000\000\000\000\t\000\000\317\000\000\000Q\007\000\000\017\000\000\000\000\010\000\000g\000\000\000\000\010\000\000'\000\000\000\000\t\000\000\257\000\000\000\000\010\000\000\007\000\000\000\000\010\000\000\207\000\000\000\000\010\000\000G\000\000\000\000\t\000\000\357\000\000\000P\007\000\000\t\000\000\000\000\010\000\000_\000\000\000\000\010\000\000\037\000\000\000\000\t\000\000\237\000\000\000T\007\000\000c\000\000\000\000\010\000\000\177\000\000\000\000\010\000\000?\000\000\000\000\t\000\000\337\000\000\000R\007\000\000\033\000\000\000\000\010\000\000o\000\000\000\000\010\000\000/\000\000\000\000\t\000\000\277\000\000\000\000\010\000\000\017\000\000\000\000\010\000\000\217\000\000\000\000\010\000\000O", 252u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00004139), "\t\000\000\377\000\000\000P\005\000\000\001\000\000\000W\005\000\000\001\001\000\000S\005\000\000\021\000\000\000[\005\000\000\001\020\000\000Q\005\000\000\005\000\000\000Y\005\000\000\001\004\000\000U\005\000\000A\000\000\000]\005\000\000\001@\000\000P\005\000\000\003\000\000\000X\005\000\000\001\002\000\000T\005\000\000!\000\000\000\\\005\000\000\001 \000\000R\005\000\000\t\000\000\000Z\005\000\000\001\010\000\000V\005\000\000\201\000\000\000\300\005\000\000\001`\000\000P\005\000\000\002\000\000\000W\005\000\000\201\001\000\000S\005\000\000\031\000\000\000[\005\000\000\001\030\000\000Q\005\000\000\007\000\000\000Y\005\000\000\001\006\000\000U\005\000\000a\000\000\000]\005\000\000\001`\000\000P\005\000\000\004\000\000\000X\005\000\000\001\003\000\000T\005\000\0001\000\000\000\\\005\000\000\0010\000\000R\005\000\000\r\000\000\000Z\005\000\000\001\014\000\000V\005\000\000\301\000\000\000\300", 256u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00004239), "\005\000\000\001`", 5u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00004240), "oversubscribed dynamic bit lengths tree", 39u); storage[UINT32_C(0x00004267)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004268), "incomplete dynamic bit lengths tree", 35u); storage[UINT32_C(0x0000428B)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000428C), "oversubscribed literal/length tree", 34u); storage[UINT32_C(0x000042AE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000042B0), "incomplete literal/length tree", 30u); storage[UINT32_C(0x000042CE)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000042D0), "oversubscribed distance tree", 28u); storage[UINT32_C(0x000042EC)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000042F0), "incomplete distance tree", 24u); storage[UINT32_C(0x00004308)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000430C), "empty distance tree with lengths", 32u); storage[UINT32_C(0x0000432C)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00004334), "\001\000\000\000\003\000\000\000\007\000\000\000\017\000\000\000\037\000\000\000?\000\000\000\177\000\000\000\377\000\000\000\377\001\000\000\377\003\000\000\377\007\000\000\377\017\000\000\377\037\000\000\377?\000\000\377\177\000\000\377\377", 62u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00004374), "invalid distance code", 21u); storage[UINT32_C(0x00004389)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000438C), "invalid literal/length code", 27u); storage[UINT32_C(0x000043A7)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000043A8), "\\\272P\000\000\000\000\000\003\377\377\000\000\000\000\000L\272P\000\004\000\000\000\003\377\377\000\000\000\000\000<\272P\000\010\000\000\000\003\377\377\200\000\000\000\000\000\000\000\000\014\000\000\000\014\377\377", 59u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000043EC), "\r\000\000\000\014\377\377", 7u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000043FC), "\016\000\000\000\014\377\377\200\000\000\000\000\000\000\000\000\017\000\000\000\014\377\377\200\000\000\000\000,\272P\000\000\000\000\000\014\000\000\200\000\000\000\000,\272P\000\001\000\000\000\014\001\000\200\000\000\000\000,\272P\000\002\000\000\000\014\002\000\200\000\000\000\000,\272P\000\003\000\000\000\014\003\000\200\000\000\000\000,\272P\000\004\000\000\000\014\004\000\200\000\000\000\000,\272P\000\005\000\000\000\014\005\000\200\000\000\000\000,\272P\000\006\000\000\000\014\006\000\200\000\000\000\000,\272P\000\007\000\000\000\014\007\000\200\000\000\000\000,\272P\000\010\000\000\000\014\010\000\200\000\000\000\000,\272P\000\t\000\000\000\014\t\000\200\000\000\000\000,\272P\000\n\000\000\000\014\n\000\200\000\000\000\000,\272P\000\013\000\000\000\014\013\000\200\000\000\000\000,\272P\000\014\000\000\000\014\014\000\200\000\000\000\000,\272P\000\r\000\000\000\014\r\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000044FC), "\016\000\000\000\014\016\000\200\000\000\000\000,\272P\000\017\000\000\000\014\017\000\200\000\000\000\000,\272P\000\020\000\000\000\014\020\000\200\000\000\000\000,\272P\000\021\000\000\000\014\021\000\200\000\000\000\000,\272P\000\022\000\000\000\014\022\000\200\000\000\000\000,\272P\000\023\000\000\000\014\023\000\200\000\000\000\000,\272P\000\024\000\000\000\014\024\000\200\000\000\000\000,\272P\000\025\000\000\000\014\025\000\200\000\000\000\000,\272P\000\026\000\000\000\014\026\000\200\000\000\000\000,\272P\000\027\000\000\000\014\027\000\200\000\000\000\000,\272P\000\030\000\000\000\014\030\000\200\000\000\000\000,\272P\000\031\000\000\000\014\031\000\200\000\000\000\000,\272P\000\032\000\000\000\014\032\000\200\000\000\000\000,\272P\000\033\000\000\000\014\033\000\200\000\000\000\000,\272P\000\034\000\000\000\014\034\000\200\000\000\000\000,\272P\000\035\000\000\000\014\035\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000045FC), "\036\000\000\000\014\036\000\200\000\000\000\000,\272P\000\037\000\000\000\014\037\000\200\000\000\000\000,\272P\000 \000\000\000\014 \000\200\000\000\000\000,\272P\000!\000\000\000\014!\000\200\000\000\000\000,\272P\000\"\000\000\000\014\"\000\200\000\000\000\000,\272P\000#\000\000\000\014#\000\200\000\000\000\000,\272P\000$\000\000\000\014$\000\200\000\000\000\000,\272P\000%\000\000\000\014%\000\200\000\000\000\000,\272P\000&\000\000\000\014&\000\200\000\000\000\000,\272P\000'\000\000\000\014'\000\200\000\000\000\000,\272P\000(\000\000\000\014(\000\200\000\000\000\000,\272P\000)\000\000\000\014)\000\200\000\000\000\000,\272P\000*\000\000\000\014*\000\200\000\000\000\000,\272P\000+\000\000\000\014+\000\200\000\000\000\000,\272P\000,\000\000\000\014,\000\200\000\000\000\000,\272P\000-\000\000\000\014-\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000046FC), ".\000\000\000\014.\000\200\000\000\000\000,\272P\000/\000\000\000\014/\000\200\000\000\000\000,\272P\0000\000\000\000\0140\000\200\000\000\000\000,\272P\0001\000\000\000\0141\000\200\000\000\000\000,\272P\0002\000\000\000\0142\000\200\000\000\000\000,\272P\0003\000\000\000\0143\000\200\000\000\000\000,\272P\0004\000\000\000\0144\000\200\000\000\000\000,\272P\0005\000\000\000\0145\000\200\000\000\000\000,\272P\0006\000\000\000\0146\000\200\000\000\000\000,\272P\0007\000\000\000\0147\000\200\000\000\000\000,\272P\0008\000\000\000\0148\000\200\000\000\000\000,\272P\0009\000\000\000\0149\000\200\000\000\000\000,\272P\000:\000\000\000\014:\000\200\000\000\000\000,\272P\000;\000\000\000\014;\000\200\000\000\000\000,\272P\000<\000\000\000\014<\000\200\000\000\000\000,\272P\000=\000\000\000\014=\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000047FC), ">\000\000\000\014>\000\200\000\000\000\000,\272P\000?\000\000\000\014?\000\200\000\000\000\000,\272P\000@\000\000\000\014@\000\200\000\000\000\000,\272P\000A\000\000\000\014A\000\200\000\000\000\000,\272P\000B\000\000\000\014B\000\200\000\000\000\000,\272P\000C\000\000\000\014C\000\200\000\000\000\000,\272P\000D\000\000\000\014D\000\200\000\000\000\000,\272P\000E\000\000\000\014E\000\200\000\000\000\000,\272P\000F\000\000\000\014F\000\200\000\000\000\000,\272P\000G\000\000\000\014G\000\200\000\000\000\000,\272P\000H\000\000\000\014H\000\200\000\000\000\000,\272P\000I\000\000\000\014I\000\200\000\000\000\000,\272P\000J\000\000\000\014J\000\200\000\000\000\000,\272P\000K\000\000\000\014K\000\200\000\000\000\000,\272P\000L\000\000\000\014L\000\200\000\000\000\000,\272P\000M\000\000\000\014M\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000048FC), "N\000\000\000\014N\000\200\000\000\000\000,\272P\000O\000\000\000\014O\000\200\000\000\000\000,\272P\000P\000\000\000\014P\000\200\000\000\000\000,\272P\000Q\000\000\000\014Q\000\200\000\000\000\000,\272P\000R\000\000\000\014R\000\200\000\000\000\000,\272P\000S\000\000\000\014S\000\200\000\000\000\000,\272P\000T\000\000\000\014T\000\200\000\000\000\000,\272P\000U\000\000\000\014U\000\200\000\000\000\000,\272P\000V\000\000\000\014V\000\200\000\000\000\000,\272P\000W\000\000\000\014W\000\200\000\000\000\000,\272P\000X\000\000\000\014X\000\200\000\000\000\000,\272P\000Y\000\000\000\014Y\000\200\000\000\000\000,\272P\000Z\000\000\000\014Z\000\200\000\000\000\000,\272P\000[\000\000\000\014[\000\200\000\000\000\000,\272P\000\\\000\000\000\014\\\000\200\000\000\000\000,\272P\000]\000\000\000\014]\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000049FC), "^\000\000\000\014^\000\200\000\000\000\000,\272P\000_\000\000\000\014_\000\200\000\000\000\000,\272P\000`\000\000\000\014`\000\200\000\000\000\000,\272P\000a\000\000\000\014a\000\200\000\000\000\000,\272P\000b\000\000\000\014b\000\200\000\000\000\000,\272P\000c\000\000\000\014c\000\200\000\000\000\000,\272P\000d\000\000\000\014d\000\200\000\000\000\000,\272P\000e\000\000\000\014e\000\200\000\000\000\000,\272P\000f\000\000\000\014f\000\200\000\000\000\000,\272P\000g\000\000\000\014g\000\200\000\000\000\000,\272P\000h\000\000\000\014h\000\200\000\000\000\000,\272P\000i\000\000\000\014i\000\200\000\000\000\000,\272P\000j\000\000\000\014j\000\200\000\000\000\000,\272P\000k\000\000\000\014k\000\200\000\000\000\000,\272P\000l\000\000\000\014l\000\200\000\000\000\000,\272P\000m\000\000\000\014m\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00004AFC), "n\000\000\000\014n\000\200\000\000\000\000,\272P\000o\000\000\000\014o\000\200\000\000\000\000,\272P\000p\000\000\000\014p\000\200\000\000\000\000,\272P\000q\000\000\000\014q\000\200\000\000\000\000,\272P\000r\000\000\000\014r\000\200\000\000\000\000,\272P\000s\000\000\000\014s\000\200\000\000\000\000,\272P\000t\000\000\000\014t\000\200\000\000\000\000,\272P\000u\000\000\000\014u\000\200\000\000\000\000,\272P\000v\000\000\000\014v\000\200\000\000\000\000,\272P\000w\000\000\000\014w\000\200\000\000\000\000,\272P\000x\000\000\000\014x\000\200\000\000\000\000,\272P\000y\000\000\000\014y\000\200\000\000\000\000,\272P\000z\000\000\000\014z\000\200\000\000\000\000,\272P\000{\000\000\000\014{\000\200\000\000\000\000,\272P\000|\000\000\000\014|\000\200\000\000\000\000,\272P\000}\000\000\000\014}\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00004BFC), "~\000\000\000\014~\000\200\000\000\000\000,\272P\000\177\000\000\000\014\177\000\200\000\000\000\000,\272P\000\200\000\000\000\014\200\000\200\000\000\000\000,\272P\000\201\000\000\000\014\201\000\200\000\000\000\000,\272P\000\202\000\000\000\014\202\000\200\000\000\000\000,\272P\000\203\000\000\000\014\203\000\200\000\000\000\000,\272P\000\204\000\000\000\014\204\000\200\000\000\000\000,\272P\000\205\000\000\000\014\205\000\200\000\000\000\000,\272P\000\206\000\000\000\014\206\000\200\000\000\000\000,\272P\000\207\000\000\000\014\207\000\200\000\000\000\000,\272P\000\210\000\000\000\014\210\000\200\000\000\000\000,\272P\000\211\000\000\000\014\211\000\200\000\000\000\000,\272P\000\212\000\000\000\014\212\000\200\000\000\000\000,\272P\000\213\000\000\000\014\213\000\200\000\000\000\000,\272P\000\214\000\000\000\014\214\000\200\000\000\000\000,\272P\000\215\000\000\000\014\215\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00004CFC), "\216\000\000\000\014\216\000\200\000\000\000\000,\272P\000\217\000\000\000\014\217\000\200\000\000\000\000,\272P\000\220\000\000\000\014\220\000\200\000\000\000\000,\272P\000\221\000\000\000\014\221\000\200\000\000\000\000,\272P\000\222\000\000\000\014\222\000\200\000\000\000\000,\272P\000\223\000\000\000\014\223\000\200\000\000\000\000,\272P\000\224\000\000\000\014\224\000\200\000\000\000\000,\272P\000\225\000\000\000\014\225\000\200\000\000\000\000,\272P\000\226\000\000\000\014\226\000\200\000\000\000\000,\272P\000\227\000\000\000\014\227\000\200\000\000\000\000,\272P\000\230\000\000\000\014\230\000\200\000\000\000\000,\272P\000\231\000\000\000\014\231\000\200\000\000\000\000,\272P\000\232\000\000\000\014\232\000\200\000\000\000\000,\272P\000\233\000\000\000\014\233\000\200\000\000\000\000,\272P\000\234\000\000\000\014\234\000\200\000\000\000\000,\272P\000\235\000\000\000\014\235\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00004DFC), "\236\000\000\000\014\236\000\200\000\000\000\000,\272P\000\237\000\000\000\014\237\000\200\000\000\000\000,\272P\000\240\000\000\000\014\240\000\200\000\000\000\000,\272P\000\241\000\000\000\014\241\000\200\000\000\000\000,\272P\000\242\000\000\000\014\242\000\200\000\000\000\000,\272P\000\243\000\000\000\014\243\000\200\000\000\000\000,\272P\000\244\000\000\000\014\244\000\200\000\000\000\000,\272P\000\245\000\000\000\014\245\000\200\000\000\000\000,\272P\000\246\000\000\000\014\246\000\200\000\000\000\000,\272P\000\247\000\000\000\014\247\000\200\000\000\000\000,\272P\000\250\000\000\000\014\250\000\200\000\000\000\000,\272P\000\251\000\000\000\014\251\000\200\000\000\000\000,\272P\000\252\000\000\000\014\252\000\200\000\000\000\000,\272P\000\253\000\000\000\014\253\000\200\000\000\000\000,\272P\000\254\000\000\000\014\254\000\200\000\000\000\000,\272P\000\255\000\000\000\014\255\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00004EFC), "\256\000\000\000\014\256\000\200\000\000\000\000,\272P\000\257\000\000\000\014\257\000\200\000\000\000\000,\272P\000\260\000\000\000\014\260\000\200\000\000\000\000,\272P\000\261\000\000\000\014\261\000\200\000\000\000\000,\272P\000\262\000\000\000\014\262\000\200\000\000\000\000,\272P\000\263\000\000\000\014\263\000\200\000\000\000\000,\272P\000\264\000\000\000\014\264\000\200\000\000\000\000,\272P\000\265\000\000\000\014\265\000\200\000\000\000\000,\272P\000\266\000\000\000\014\266\000\200\000\000\000\000,\272P\000\267\000\000\000\014\267\000\200\000\000\000\000,\272P\000\270\000\000\000\014\270\000\200\000\000\000\000,\272P\000\271\000\000\000\014\271\000\200\000\000\000\000,\272P\000\272\000\000\000\014\272\000\200\000\000\000\000,\272P\000\273\000\000\000\014\273\000\200\000\000\000\000,\272P\000\274\000\000\000\014\274\000\200\000\000\000\000,\272P\000\275\000\000\000\014\275\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00004FFC), "\276\000\000\000\014\276\000\200\000\000\000\000,\272P\000\277\000\000\000\014\277\000\200\000\000\000\000,\272P\000\300\000\000\000\014\300\000\200\000\000\000\000,\272P\000\301\000\000\000\014\301\000\200\000\000\000\000,\272P\000\302\000\000\000\014\302\000\200\000\000\000\000,\272P\000\303\000\000\000\014\303\000\200\000\000\000\000,\272P\000\304\000\000\000\014\304\000\200\000\000\000\000,\272P\000\305\000\000\000\014\305\000\200\000\000\000\000,\272P\000\306\000\000\000\014\306\000\200\000\000\000\000,\272P\000\307\000\000\000\014\307\000\200\000\000\000\000,\272P\000\310\000\000\000\014\310\000\200\000\000\000\000,\272P\000\311\000\000\000\014\311\000\200\000\000\000\000,\272P\000\312\000\000\000\014\312\000\200\000\000\000\000,\272P\000\313\000\000\000\014\313\000\200\000\000\000\000,\272P\000\314\000\000\000\014\314\000\200\000\000\000\000,\272P\000\315\000\000\000\014\315\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000050FC), "\316\000\000\000\014\316\000\200\000\000\000\000,\272P\000\317\000\000\000\014\317\000\200\000\000\000\000,\272P\000\320\000\000\000\014\320\000\200\000\000\000\000,\272P\000\321\000\000\000\014\321\000\200\000\000\000\000,\272P\000\322\000\000\000\014\322\000\200\000\000\000\000,\272P\000\323\000\000\000\014\323\000\200\000\000\000\000,\272P\000\324\000\000\000\014\324\000\200\000\000\000\000,\272P\000\325\000\000\000\014\325\000\200\000\000\000\000,\272P\000\326\000\000\000\014\326\000\200\000\000\000\000,\272P\000\327\000\000\000\014\327\000\200\000\000\000\000,\272P\000\330\000\000\000\014\330\000\200\000\000\000\000,\272P\000\331\000\000\000\014\331\000\200\000\000\000\000,\272P\000\332\000\000\000\014\332\000\200\000\000\000\000,\272P\000\333\000\000\000\014\333\000\200\000\000\000\000,\272P\000\334\000\000\000\014\334\000\200\000\000\000\000,\272P\000\335\000\000\000\014\335\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000051FC), "\336\000\000\000\014\336\000\200\000\000\000\000,\272P\000\337\000\000\000\014\337\000\200\000\000\000\000,\272P\000\340\000\000\000\014\340\000\200\000\000\000\000,\272P\000\341\000\000\000\014\341\000\200\000\000\000\000,\272P\000\342\000\000\000\014\342\000\200\000\000\000\000,\272P\000\343\000\000\000\014\343\000\200\000\000\000\000,\272P\000\344\000\000\000\014\344\000\200\000\000\000\000,\272P\000\345\000\000\000\014\345\000\200\000\000\000\000,\272P\000\346\000\000\000\014\346\000\200\000\000\000\000,\272P\000\347\000\000\000\014\347\000\200\000\000\000\000,\272P\000\350\000\000\000\014\350\000\200\000\000\000\000,\272P\000\351\000\000\000\014\351\000\200\000\000\000\000,\272P\000\352\000\000\000\014\352\000\200\000\000\000\000,\272P\000\353\000\000\000\014\353\000\200\000\000\000\000,\272P\000\354\000\000\000\014\354\000\200\000\000\000\000,\272P\000\355\000\000\000\014\355\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000052FC), "\356\000\000\000\014\356\000\200\000\000\000\000,\272P\000\357\000\000\000\014\357\000\200\000\000\000\000,\272P\000\360\000\000\000\014\360\000\200\000\000\000\000,\272P\000\361\000\000\000\014\361\000\200\000\000\000\000,\272P\000\362\000\000\000\014\362\000\200\000\000\000\000,\272P\000\363\000\000\000\014\363\000\200\000\000\000\000,\272P\000\364\000\000\000\014\364\000\200\000\000\000\000,\272P\000\365\000\000\000\014\365\000\200\000\000\000\000,\272P\000\366\000\000\000\014\366\000\200\000\000\000\000,\272P\000\367\000\000\000\014\367\000\200\000\000\000\000,\272P\000\370\000\000\000\014\370\000\200\000\000\000\000,\272P\000\371\000\000\000\014\371\000\200\000\000\000\000,\272P\000\372\000\000\000\014\372\000\200\000\000\000\000,\272P\000\373\000\000\000\014\373\000\200\000\000\000\000,\272P\000\374\000\000\000\014\374\000\200\000\000\000\000,\272P\000\375\000\000\000\014\375\000\200\000\000\000\000,\272P", 255u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000053FC), "\376\000\000\000\014\376\000\200\000\000\000\000,\272P\000\377\000\000\000\014\377\000\200\000\000\000\000\030[Q\000\374ZQ\000\340ZQ\000\304ZQ\000\250ZQ\000\214ZQ\000\000\312\232;\000\312\232;h\233P\000\377\377\000\000\000\312\232;\000\312\232;\001\000\000\0000\277N\000\\]Q\000\204bQ", 91u);
    sfera_copy_static_bytes(storage, UINT32_C(0x0000545C), ".?AVBaseAllocator@@", 19u); storage[UINT32_C(0x0000546F)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x00005470), "\204bQ", 3u);
    sfera_copy_static_bytes(storage, UINT32_C(0x00005478), ".?AVStdAllocator@@", 18u); storage[UINT32_C(0x0000548A)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x0000548C), "\270_Q\000N\346@\273\261\031\277D\204bQ", 15u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000054A0), ".?AVtype_info@@", 15u); storage[UINT32_C(0x000054AF)] = 0u;
    sfera_copy_static_bytes(storage, UINT32_C(0x000054B0), "\377\377\377\377\377\377\377\377\376\377\377\377\001\000\000\000\300\366N\000\204bQ", 23u);
    sfera_copy_static_bytes(storage, UINT32_C(0x000054CC), ".?AV_com_error@@", 16u); storage[UINT32_C(0x000054DC)] = 0u;
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
uint32_t sfera_zlib_bl_order(uint32_t index) {
    switch (index) {
        case 0u: return 16u;
        case 1u: return 17u;
        case 2u: return 18u;
        case 3u: return 0u;
        case 4u: return 8u;
        case 5u: return 7u;
        case 6u: return 9u;
        case 7u: return 6u;
        case 8u: return 10u;
        case 9u: return 5u;
        case 10u: return 11u;
        case 11u: return 4u;
        case 12u: return 12u;
        case 13u: return 3u;
        case 14u: return 13u;
        case 15u: return 2u;
        case 16u: return 14u;
        case 17u: return 1u;
        case 18u: return 15u;
        default: return 0u;
    }
}

uint32_t sfera_zlib_length_extra_bits(uint32_t code) {
    if (code < 8u || code >= 28u) { return 0u; }
    return (code - 4u) >> 2u;
}

uint32_t sfera_zlib_distance_extra_bits(uint32_t code) {
    if (code < 4u) { return 0u; }
    if (code >= 30u) { return 0u; }
    return (code >> 1u) - 1u;
}

uint32_t sfera_zlib_base_length(uint32_t code) {
    if (code < 8u) { return code; }
    if (code >= 28u) { return 0u; }
    const uint32_t extra = sfera_zlib_length_extra_bits(code);
    const uint32_t group_begin = 4u * extra + 4u;
    return (1u << (extra + 2u)) + ((code - group_begin) << extra);
}

uint32_t sfera_zlib_base_distance(uint32_t code) {
    if (code < 4u) { return code; }
    if (code >= 30u) { return 0u; }
    const uint32_t extra = sfera_zlib_distance_extra_bits(code);
    return (1u << (extra + 1u)) + ((code & 1u) << extra);
}

uint32_t sfera_zlib_length_code(uint32_t length_minus_three) {
    if (length_minus_three >= 255u) { return 28u; }
    for (uint32_t code = 0u; code != 28u; ++code) {
        const uint32_t base = sfera_zlib_base_length(code);
        const uint32_t span = 1u << sfera_zlib_length_extra_bits(code);
        if (length_minus_three >= base && length_minus_three < base + span) { return code; }
    }
    return 28u;
}

uint32_t sfera_zlib_distance_code(uint32_t distance_minus_one) {
    for (uint32_t code = 0u; code != 30u; ++code) {
        const uint32_t base = sfera_zlib_base_distance(code);
        const uint32_t span = 1u << sfera_zlib_distance_extra_bits(code);
        if (distance_minus_one >= base && distance_minus_one < base + span) { return code; }
    }
    return 29u;
}


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
    if (kind == SferaZlibTreeKind::Literal) { return symbol >= 257u ? sfera_zlib_length_extra_bits(symbol - 257u) : 0u; }
    if (kind == SferaZlibTreeKind::Distance) { return sfera_zlib_distance_extra_bits(symbol); }
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
    while (last_rank >= 3 && state->bit_length_tree[sfera_zlib_bl_order(static_cast<uint32_t>(last_rank))].length == 0u) { --last_rank; }
    state->optimal_length += static_cast<uint32_t>(3 * (last_rank + 1) + 14);
    return last_rank;
}

void sfera_zlib_send_all_trees(uint32_t state_address, uint32_t literal_codes, uint32_t distance_codes, uint32_t bit_length_codes) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    sfera_zlib_send_bits(state_address, literal_codes - 257u, 5u);
    sfera_zlib_send_bits(state_address, distance_codes - 1u, 5u);
    sfera_zlib_send_bits(state_address, bit_length_codes - 4u, 4u);
    for (uint32_t rank = 0u; rank != bit_length_codes; ++rank) { sfera_zlib_send_bits(state_address, state->bit_length_tree[sfera_zlib_bl_order(rank)].length, 3u); }
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
        const uint32_t length_code = sfera_zlib_length_code(literal_or_length);
        sfera_zlib_send_tree_code(state_address, literal_tree_address, length_code + 257u, false);
        const uint32_t length_extra = sfera_zlib_length_extra_bits(length_code);
        if (length_extra != 0u) { sfera_zlib_send_bits(state_address, literal_or_length - sfera_zlib_base_length(length_code), length_extra); }
        --distance;
        const uint32_t distance_code = sfera_zlib_distance_code(distance);
        sfera_zlib_send_tree_code(state_address, distance_tree_address, distance_code, true);
        const uint32_t distance_extra = sfera_zlib_distance_extra_bits(distance_code);
        if (distance_extra != 0u) { sfera_zlib_send_bits(state_address, distance - sfera_zlib_base_distance(distance_code), distance_extra); }
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
        const uint32_t distance_code = sfera_zlib_distance_code(distance - 1u);
        const uint32_t length_code = sfera_zlib_length_code(literal_or_length);
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



static const char kSferaZlibStreamError[] = "stream error";
static const char kSferaZlibBufferError[] = "buffer error";

static uint32_t sfera_zlib_text_pointer(const char* text) { return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(text)); }

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
    if (stream->next_out == 0u || (stream->next_in == 0u && stream->avail_in != 0u) || (state->prefix.status == 666 && flush != 4)) { stream->msg = sfera_zlib_text_pointer(kSferaZlibStreamError); return static_cast<uint32_t>(-2); }
    if (stream->avail_out == 0u) { stream->msg = sfera_zlib_text_pointer(kSferaZlibBufferError); return static_cast<uint32_t>(-5); }
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
    else if (stream->avail_in == 0u && flush <= previous_flush && flush != 4) { stream->msg = sfera_zlib_text_pointer(kSferaZlibBufferError); return static_cast<uint32_t>(-5); }
    if (state->prefix.status == 666 && stream->avail_in != 0u) { stream->msg = sfera_zlib_text_pointer(kSferaZlibBufferError); return static_cast<uint32_t>(-5); }
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
    *sfera_zlib_pointer<uint32_t>(literal_bits_address) = 9u;
    *sfera_zlib_pointer<uint32_t>(distance_bits_address) = 5u;
    *sfera_zlib_pointer<uint32_t>(literal_root_address) = SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00523140));
    *sfera_zlib_pointer<uint32_t>(distance_root_address) = SFERA_DATA_CANONICAL_ADDR(UINT32_C(0x00524140));
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
                        const uint32_t extra = index < 29u ? sfera_zlib_length_extra_bits(index) : 112u;
                        entry.operation = static_cast<uint8_t>(extra + 80u);
                        entry.base = index < 28u ? sfera_zlib_base_length(index) + 3u : (index == 28u ? 258u : 0u);
                    } else if (simple_count == 0u && code_count <= 30u && index < 30u) {
                        entry.operation = static_cast<uint8_t>(sfera_zlib_distance_extra_bits(index) + 80u);
                        entry.base = sfera_zlib_base_distance(index) + 1u;
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
