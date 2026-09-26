#include <windows.h>
#include <algorithm>
#include <bit>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <limits>
#include <span>
#include <utility>

#include "binary/Binary.h"
#include "graphics/d3d9/Device.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "render/Textures.h"

void SferaTextureBinding::terrainSetTexture(std::uint32_t stage, IDirect3DBaseTexture9 *texture)
{
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    device.checkResult(device.native_device->SetTexture(stage, texture), "SetTexture");
}

SferaD3D9TextureLoadResult SferaTextureUpload::fromDds(IDirect3DDevice9 *device, std::span<const std::uint8_t> data) noexcept
{
    constexpr std::size_t header_size = 128u;
    constexpr std::uint32_t dds_magic = 0x20534444u;
    constexpr std::uint32_t dds_fourcc = 0x4u;
    constexpr std::uint32_t dds_rgb = 0x40u;
    constexpr std::uint32_t dds_alpha = 0x1u;

    SferaD3D9TextureLoadResult result;
    if (device == nullptr || data.size() < header_size || SferaBinary::readLittleEndian<std::uint32_t>(data.data()) != dds_magic ||
        SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 4u) != 124u || SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 76u) != 32u)
        return result;

    const std::uint32_t height = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 12u);
    const std::uint32_t width = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 16u);
    const std::uint32_t mip_count = (std::max)(1u, SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 28u));
    const std::uint32_t flags = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 80u);
    const std::uint32_t fourcc = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 84u);
    const std::uint32_t bits = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 88u);
    const std::uint32_t red = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 92u);
    const std::uint32_t green = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 96u);
    const std::uint32_t blue = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 100u);
    const std::uint32_t alpha = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 104u);
    if (width == 0u || height == 0u || std::cmp_greater(mip_count, std::bit_width(std::max(width, height))))
        return result;

    D3DFORMAT format = D3DFMT_UNKNOWN;
    std::uint32_t block_bytes = 0u;
    std::uint32_t pixel_bytes = 0u;
    bool rgb24 = false;
    if ((flags & dds_fourcc) != 0u)
    {
        if (std::cmp_equal(fourcc, SferaNumeric::enumBits(D3DFMT_DXT1)))
        {
            format = D3DFMT_DXT1;
            block_bytes = 8u;
        }
        else if (std::cmp_equal(fourcc, SferaNumeric::enumBits(D3DFMT_DXT3)))
        {
            format = D3DFMT_DXT3;
            block_bytes = 16u;
            result.has_alpha = true;
        }
        else if (std::cmp_equal(fourcc, SferaNumeric::enumBits(D3DFMT_DXT5)))
        {
            format = D3DFMT_DXT5;
            block_bytes = 16u;
            result.has_alpha = true;
        }
    }
    else if ((flags & dds_rgb) != 0u && bits == 32u && red == 0x00ff0000u && green == 0x0000ff00u && blue == 0x000000ffu && ((flags & dds_alpha) == 0u || alpha == 0xff000000u))
    {
        format = D3DFMT_A8R8G8B8;
        pixel_bytes = 4u;
        result.has_alpha = (flags & dds_alpha) != 0u && alpha == 0xff000000u;
    }
    else if ((flags & dds_rgb) != 0u && bits == 16u && red == 0x0000f800u && green == 0x000007e0u && blue == 0x0000001fu && alpha == 0u)
    {
        format = D3DFMT_R5G6B5;
        pixel_bytes = 2u;
    }
    else if ((flags & dds_rgb) != 0u && bits == 24u && red == 0x00ff0000u && green == 0x0000ff00u && blue == 0x000000ffu && alpha == 0u)
    {
        format = D3DFMT_A8R8G8B8;
        pixel_bytes = 3u;
        rgb24 = true;
    }
    if (format == D3DFMT_UNKNOWN)
        return result;

    Microsoft::WRL::ComPtr<IDirect3DTexture9> texture;
    result.status = device->CreateTexture(width, height, mip_count, 0u, format, D3DPOOL_MANAGED, texture.GetAddressOf(), nullptr);
    if (FAILED(result.status))
        return result;
    if (!texture)
    {
        result.status = D3DERR_INVALIDCALL;
        return result;
    }

    auto source = data.subspan(header_size);
    std::uint32_t level_width = width;
    std::uint32_t level_height = height;
    for (UINT level = 0; level < mip_count; ++level)
    {
        const std::size_t columns = block_bytes ? (level_width - 1u) / 4u + 1u : level_width;
        const std::size_t rows = block_bytes ? (level_height - 1u) / 4u + 1u : level_height;
        const std::size_t bytes_per_column = block_bytes ? block_bytes : pixel_bytes;
        result.status = D3DERR_INVALIDCALL;
        if (columns > std::numeric_limits<std::size_t>::max() / bytes_per_column)
            return result;
        const std::size_t source_pitch = columns * bytes_per_column;
        if (source_pitch > source.size() / rows)
            return result;
        if (rgb24 && level_width > std::numeric_limits<std::size_t>::max() / 4u)
            return result;
        const std::size_t destination_pitch = rgb24 ? level_width * 4u : source_pitch;

        TextureMapping mapping(texture.Get(), level);
        result.status = mapping.status();
        if (FAILED(result.status))
            return result;
        for (std::size_t row = 0; row < rows; ++row)
        {
            auto destination = mapping.row(row, destination_pitch);
            if (destination.size() != destination_pitch)
            {
                result.status = D3DERR_INVALIDCALL;
                return result;
            }
            const auto *pixels = source.data() + row * source_pitch;
            if (rgb24)
            {
                for (std::size_t column = 0; column < level_width; ++column)
                {
                    std::copy_n(pixels + column * 3u, 3u, destination.data() + column * 4u);
                    destination[column * 4u + 3u] = 0xffu;
                }
            }
            else
            {
                std::copy_n(pixels, source_pitch, destination.data());
            }
        }
        result.status = mapping.unlock();
        if (FAILED(result.status))
            return result;
        source = source.subspan(source_pitch * rows);
        level_width = std::max(1u, level_width / 2u);
        level_height = std::max(1u, level_height / 2u);
    }
    result.status = D3D_OK;
    result.texture = std::move(texture);
    return result;
}
