#pragma once

#include <winsock2.h>
#include <windows.h>
#include <tlhelp32.h>
#include <commctrl.h>
#include <dinput.h>
#include <d3d9.h>
#include <mmsystem.h>
#include <dbghelp.h>
#include <shellapi.h>
#include <ole2.h>
#include <oleauto.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <time.h>
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
// Native D3DX9Shader.h interface. Method order is the D3DX9 COM ABI.
struct D3DXVECTOR4;
struct D3DXCONSTANTTABLE_DESC;
struct D3DXCONSTANT_DESC;
using D3DXHANDLE = LPCSTR;
struct ID3DXConstantTable : IUnknown {
    virtual LPVOID STDMETHODCALLTYPE GetBufferPointer() = 0;
    virtual DWORD STDMETHODCALLTYPE GetBufferSize() = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DXCONSTANTTABLE_DESC* description) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetConstantDesc(D3DXHANDLE constant, D3DXCONSTANT_DESC* description, UINT* count) = 0;
    virtual UINT STDMETHODCALLTYPE GetSamplerIndex(D3DXHANDLE constant) = 0;
    virtual D3DXHANDLE STDMETHODCALLTYPE GetConstant(D3DXHANDLE parent, UINT index) = 0;
    virtual D3DXHANDLE STDMETHODCALLTYPE GetConstantByName(D3DXHANDLE parent, LPCSTR name) = 0;
    virtual D3DXHANDLE STDMETHODCALLTYPE GetConstantElement(D3DXHANDLE constant, UINT index) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetDefaults(IDirect3DDevice9* device) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetValue(IDirect3DDevice9* device, D3DXHANDLE constant, LPCVOID data, UINT bytes) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetBool(IDirect3DDevice9* device, D3DXHANDLE constant, BOOL value) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetBoolArray(IDirect3DDevice9* device, D3DXHANDLE constant, const BOOL* values, UINT count) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetInt(IDirect3DDevice9* device, D3DXHANDLE constant, INT value) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetIntArray(IDirect3DDevice9* device, D3DXHANDLE constant, const INT* values, UINT count) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetFloat(IDirect3DDevice9* device, D3DXHANDLE constant, FLOAT value) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetFloatArray(IDirect3DDevice9* device, D3DXHANDLE constant, const FLOAT* values, UINT count) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetVector(IDirect3DDevice9* device, D3DXHANDLE constant, const D3DXVECTOR4* vector) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetVectorArray(IDirect3DDevice9* device, D3DXHANDLE constant, const D3DXVECTOR4* vectors, UINT count) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetMatrix(IDirect3DDevice9* device, D3DXHANDLE constant, const D3DXMATRIX* matrix) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetMatrixArray(IDirect3DDevice9* device, D3DXHANDLE constant, const D3DXMATRIX* matrices, UINT count) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetMatrixPointerArray(IDirect3DDevice9* device, D3DXHANDLE constant, const D3DXMATRIX** matrices, UINT count) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetMatrixTranspose(IDirect3DDevice9* device, D3DXHANDLE constant, const D3DXMATRIX* matrix) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetMatrixTransposeArray(IDirect3DDevice9* device, D3DXHANDLE constant, const D3DXMATRIX* matrices, UINT count) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetMatrixTransposePointerArray(IDirect3DDevice9* device, D3DXHANDLE constant, const D3DXMATRIX** matrices, UINT count) = 0;
};
struct D3DXIMAGE_INFO;
extern "C" {
HRESULT WINAPI D3DXCreateTexture(IDirect3DDevice9*, UINT, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DTexture9**);
HRESULT WINAPI D3DXGetShaderConstantTable(const DWORD*, ID3DXConstantTable**);
D3DXMATRIX* WINAPI D3DXMatrixLookAtRH(D3DXMATRIX*, const D3DXVECTOR3*, const D3DXVECTOR3*, const D3DXVECTOR3*);
D3DXMATRIX* WINAPI D3DXMatrixRotationQuaternion(D3DXMATRIX*, const D3DXQUATERNION*);
HRESULT WINAPI D3DXCreateCubeTextureFromFileInMemory(IDirect3DDevice9*, const void*, UINT, IDirect3DCubeTexture9**);
D3DXMATRIX* WINAPI D3DXMatrixPerspectiveFovRH(D3DXMATRIX*, FLOAT, FLOAT, FLOAT, FLOAT);
HRESULT WINAPI D3DXCreateTextureFromFileInMemoryEx(IDirect3DDevice9*, const void*, UINT, UINT, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, DWORD, DWORD, D3DCOLOR, D3DXIMAGE_INFO*, PALETTEENTRY*, IDirect3DTexture9**);
D3DXMATRIX* WINAPI D3DXMatrixMultiply(D3DXMATRIX*, const D3DXMATRIX*, const D3DXMATRIX*);
}

class CSoundListener { public: std::uint8_t backend_state[8]; D3DVECTOR position; void GetOrientation(D3DVECTOR*, D3DVECTOR*) const; int SetPosition(float, float, float, int); int SetVelocity(float, float, float, int); int SetOrientation(const D3DVECTOR&, const D3DVECTOR&, int); };
class CSoundInterface { public: std::uint8_t backend_state[16]; CSoundListener* listener; int UpdateSettings(); };
class CSound {
public:
    CSound();
    ~CSound();
    int SetAllParameters(const DS3DBUFFER*, int);
    int LoadSound(const char*, unsigned long);
    int SetVolume(float);
    virtual int Rewind();
    virtual void Stop();
    int SetPosition(float, float, float, int);
    float GetPlayTimepos() const;
    int IsSoundPlaying() const;
    void SetPlayTimepos(float);
    virtual int Play(int);
    int SetVelocity(float, float, float, int);

    char* filename;
    std::uint8_t backend_state[72];
    float duration_seconds;
    std::uint32_t backend_duration_state;
    std::int32_t cache_lifetime_seconds;
    std::uint32_t backend_cache_state;
    std::uint32_t cache_idle_since_low;
    std::uint32_t cache_idle_since_high;
    std::uint32_t cache_available;
    std::uint32_t playback_finished;
    CSound* cache_next;
    CSound* cache_previous;
};
struct SferaSoundBackendNative { virtual void unknown_00() = 0; virtual void unknown_04() = 0; virtual void unknown_08() = 0; virtual const WAVEFORMATEX* format() = 0; };
class CSoundStream;
using SferaSoundStreamCallback = std::uint32_t (__fastcall*)(CSoundStream* stream, void* state);
class CSoundStream {
public:
    void SetDecodeSignal(float); int SeekToTime(float); void SetPlaySignal(float); void Stop(); int IsStreamPlaying() const; int PlayEx(float, int);
    const WAVEFORMATEX* Format() const noexcept { return backend ? backend->format() : nullptr; }
    SferaSoundBackendNative* backend;
    std::uint8_t reserved_backend_state[48];
    std::uint32_t playback_position_adjustment;
    std::uint8_t reserved_playback_before_decoder[8];
    std::uint32_t decoder_state;
    std::uint8_t reserved_playback_after_decoder[16];
    SferaSoundStreamCallback decode_callback;
    void* decode_state;
    std::uint32_t decode_event_position;
    SferaSoundStreamCallback play_callback;
    void* play_state;
    std::uint32_t play_event_position;
    float stream_gain;
};
void SI_SetHardwareMixing(bool);
int SI_GetStreamVolume();
CSoundInterface* SI_CreateInterface(HWND, int, unsigned long, unsigned long);
CSoundInterface* SI_GetInterface();
void SI_Close();
void SI_SetLogFile(const char*);
void SI_SetStreamVolume(int);
CSoundStream* SI_StreamCreateFile(const char*, unsigned long);
void SI_StreamFree(CSoundStream*);
#if defined(_MSC_VER) && defined(_M_IX86)
#pragma comment(linker, "/alternatename:?SI_StreamCreateFile@@YAPAVCSoundStream@@PBDK@Z=?SI_StreamCreateFile@@YAKPBDK@Z")
#pragma comment(linker, "/alternatename:?SI_StreamFree@@YAXPAVCSoundStream@@@Z=?SI_StreamFree@@YAXK@Z")
#endif
bool SI_GetHardwareMixing();
