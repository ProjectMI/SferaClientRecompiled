#pragma once

#include <windows.h>
#include <cstdint>
#include <d3d9.h>
#include <span>
#include <wrl/client.h>

class SferaTextureBinding;

class SferaTextureBinding
{
  public:
    static void terrainSetTexture(std::uint32_t stage, IDirect3DBaseTexture9 *texture);
};

struct SferaD3D9TextureLoadResult;

struct SferaD3D9TextureLoadResult
{
    HRESULT status = D3DERR_INVALIDCALL;
    Microsoft::WRL::ComPtr<IDirect3DTexture9> texture;
    bool has_alpha = false;
};

class SferaTextureUpload
{
  public:
    static SferaD3D9TextureLoadResult fromDds(IDirect3DDevice9 *device, std::span<const std::uint8_t> data) noexcept;
};
