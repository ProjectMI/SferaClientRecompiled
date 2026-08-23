#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef DIRECTINPUT_VERSION
#define DIRECTINPUT_VERSION 0x0800
#endif

#include <winsock2.h>
#include <windows.h>
#include <tlhelp32.h>
#include <commctrl.h>
#include <dinput.h>
#include <d3d9.h>
#include <dbghelp.h>
#include <shellapi.h>
#include <ole2.h>
#include <oleauto.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cerrno>
#include <cwchar>
#include <float.h>
#include <time.h>
#include <cmath>
#include <cstdint>
#include <cstddef>
#include <new>
#include <io.h>
#include <direct.h>
#include <process.h>
#include <fcntl.h>
#include <share.h>
#include <sys/stat.h>
#include <sys/utime.h>
#include <mbctype.h>

struct _DS3DBUFFER;
using DS3DBUFFER = _DS3DBUFFER;
extern "C" __declspec(dllimport) DWORD WINAPI timeGetTime(void);

#ifdef Process32First
#undef Process32First
#endif
#ifdef Process32Next
#undef Process32Next
#endif

template <typename Function> inline uint32_t native_function_address32(Function function) { return static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(function)); }
template <typename Method> inline uint32_t native_method_address32(Method method) { uint32_t address = 0u; std::memcpy(&address, &method, sizeof(address)); return address; }
inline uint32_t native_memchr_address32() { using Function = void* (__cdecl*)(void*, int, std::size_t); return native_function_address32(static_cast<Function>(&::memchr)); }
inline uint32_t native_strchr_address32() { using Function = char* (__cdecl*)(char*, int); return native_function_address32(static_cast<Function>(&::strchr)); }
inline uint32_t native_strrchr_address32() { using Function = char* (__cdecl*)(char*, int); return native_function_address32(static_cast<Function>(&::strrchr)); }
inline uint32_t native_strstr_address32() { using Function = char* (__cdecl*)(char*, const char*); return native_function_address32(static_cast<Function>(&::strstr)); }

struct D3DXMATRIX;
struct D3DXVECTOR3;
struct D3DXQUATERNION;
struct D3DXCONSTANTTABLE;
struct D3DXIMAGE_INFO;
extern "C" HRESULT WINAPI D3DXCreateTexture(IDirect3DDevice9*, UINT, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DTexture9**);
extern "C" HRESULT WINAPI D3DXGetShaderConstantTable(const DWORD*, D3DXCONSTANTTABLE**);
extern "C" D3DXMATRIX* WINAPI D3DXMatrixLookAtRH(D3DXMATRIX*, const D3DXVECTOR3*, const D3DXVECTOR3*, const D3DXVECTOR3*);
extern "C" D3DXMATRIX* WINAPI D3DXMatrixRotationQuaternion(D3DXMATRIX*, const D3DXQUATERNION*);
extern "C" HRESULT WINAPI D3DXCreateCubeTextureFromFileInMemory(IDirect3DDevice9*, const void*, UINT, IDirect3DCubeTexture9**);
extern "C" D3DXMATRIX* WINAPI D3DXMatrixPerspectiveFovRH(D3DXMATRIX*, FLOAT, FLOAT, FLOAT, FLOAT);
extern "C" HRESULT WINAPI D3DXCreateTextureFromFileInMemoryEx(IDirect3DDevice9*, const void*, UINT, UINT, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, DWORD, DWORD, D3DCOLOR, D3DXIMAGE_INFO*, PALETTEENTRY*, IDirect3DTexture9**);
extern "C" D3DXMATRIX* WINAPI D3DXMatrixMultiply(D3DXMATRIX*, const D3DXMATRIX*, const D3DXMATRIX*);

class CSoundListener { public: void GetOrientation(D3DVECTOR*, D3DVECTOR*) const; int SetPosition(float, float, float, int); int SetVelocity(float, float, float, int); int SetOrientation(const D3DVECTOR&, const D3DVECTOR&, int); };
class CSoundInterface { public: int UpdateSettings(); };
class CSound { public: CSound(); ~CSound(); int SetAllParameters(const DS3DBUFFER*, int); int LoadSound(const char*, unsigned long); int SetVolume(float); virtual int Rewind(); virtual void Stop(); int SetPosition(float, float, float, int); float GetPlayTimepos() const; int IsSoundPlaying() const; void SetPlayTimepos(float); virtual int Play(int); int SetVelocity(float, float, float, int); };
class CSoundStream { public: void SetDecodeSignal(float); int SeekToTime(float); void SetPlaySignal(float); void Stop(); int IsStreamPlaying() const; int PlayEx(float, int); };

void SI_SetHardwareMixing(bool);
int SI_GetStreamVolume();
CSoundInterface* SI_CreateInterface(HWND, int, unsigned long, unsigned long);
CSoundInterface* SI_GetInterface();
void SI_Close();
void SI_SetLogFile(const char*);
void SI_SetStreamVolume(int);
unsigned long SI_StreamCreateFile(const char*, unsigned long);
void SI_StreamFree(unsigned long);
bool SI_GetHardwareMixing();
