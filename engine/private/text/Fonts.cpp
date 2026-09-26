#include <algorithm>
#include <array>
#include <cstdint>
#include <d3d9.h>
#include <iterator>
#include <span>
#include <stdexcept>
#include <string_view>
#include <utility>
#include <vector>

#include "camera/Camera.h"
#include "graphics/d3d9/Device.h"
#include "math/Color.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "render/VertexFormats.h"
#include "text/Fonts.h"
#include "ui/Rendering.h"
#include "ui/UiTypes.h"
#include "ui/WidgetSupport.h"

void GameFontAtlas::uploadPage(std::array<std::uint16_t, 256 * 256> &pixels, std::vector<Microsoft::WRL::ComPtr<IDirect3DTexture9>> &pages)
{
    auto &graphics = *g_sfera_graphics_runtime.d3d_runtime;

    Microsoft::WRL::ComPtr<IDirect3DTexture9> texture;
    graphics.checkResult(graphics.native_device->CreateTexture(256, 256, 1, 0, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, texture.GetAddressOf(), nullptr), "CreateTexture(font)");
    TextureMapping mapping(texture.Get());
    graphics.checkResult(mapping.status(), "LockRect(font)");
    graphics.checkResult(mapping.copyRows(std::as_bytes(std::span(pixels)), 256 * sizeof(pixels[0]), 256), "Upload font pixels");
    graphics.checkResult(mapping.unlock(), "UnlockRect(font)");
    pages.push_back(std::move(texture));
    pixels.fill(0);
}

SphereUIFontFactory::SphereUIFontFactory() = default;

SphereUIFontFactory::~SphereUIFontFactory() = default;

void SphereUIFontFactory::initialize()
{
    vertices.resize(1200u);
    std::fill(vertices.begin(), vertices.end(), SferaScreenVertex{});
    quad_indices.resize(2400u);
    vertex_count = 0u;
}

void SphereUIFontFactory::clear()
{
    faces.clear();
    vertices.clear();
    quad_indices.clear();
    vertex_count = 0u;
}

int SphereUIFontFactory::count() const noexcept
{
    return SferaNumeric::signedWord(SferaNumeric::lowWord(faces.size()));
}

const SphereUIFontFace &SphereUIFontFactory::face(int font) const
{
    if (font < 2 || (font - 2) >= faces.size())
        throw std::out_of_range("invalid font index");
    return *faces[font - 2u];
}

void SphereUIRenderSupport::flushAtlasText(IDirect3DDevice9 *device, IDirect3DBaseTexture9 *texture, std::uint32_t &vertex_count, std::uint32_t &index_count)
{
    if (vertex_count == 0u)
        return;
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, texture));
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE));
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1));
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetRenderState(D3DRS_LIGHTING, FALSE));
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetRenderState(D3DRS_CLIPPING, FALSE));
    SphereUIRenderSupport::uiSubmitFont(SphereUIInterfaceRenderer::glyph_vertices, vertex_count, SphereUIInterfaceRenderer::quad_indices, index_count);
    vertex_count = 0u;
    index_count = 0u;
}

std::uint8_t SphereUIRenderSupport::uiAtlasGlyph(std::uint8_t character)
{
    return g_sfera_font_runtime.glyphs[character].defined != 0u ? character : '|';
}

void SphereUIRenderSupport::uiFontQuad(SferaScreenVertex *vertices, float left, float top, float right, float bottom, std::uint32_t color, float u0, float v0, float u1, float v1, bool clockwise)
{
    for (std::uint32_t index = 0u; index < 4u; ++index)
    {
        const auto corner = clockwise || index < 2u ? index : 5u - index;
        const bool on_right = corner == 1u || corner == 2u, on_bottom = corner >= 2u;
        vertices[index] = {on_right ? right : left, on_bottom ? bottom : top, 0.0f, 1.0f, color, clockwise ? vertices[index].specular : 0u, on_right ? u1 : u0, on_bottom ? v1 : v0};
    }
}

void SphereUIRenderSupport::uiFontTriangles(std::uint16_t *indices, std::uint32_t first, bool clockwise)
{
    constexpr std::uint16_t atlas[] = {0u, 1u, 2u, 0u, 2u, 3u};
    constexpr std::uint16_t face[] = {2u, 0u, 3u, 1u, 3u, 0u};
    const auto *order = clockwise ? atlas : face;
    for (std::uint32_t index = 0u; index < 6u; ++index)
        indices[index] = SferaNumeric::lowHalf(first + order[index]);
}

void SphereUIRenderSupport::uiSubmitFont(const SferaScreenVertex *vertices, std::uint32_t vertex_count, const std::uint16_t *indices, std::uint32_t index_count)
{
    if (vertex_count == 0u)
        return;
    if (auto *device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get()))
        (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0u, vertex_count, index_count / 3u, indices, D3DFMT_INDEX16, vertices,
                                                                                             sizeof(SferaScreenVertex)));
}

void SphereUIRenderSupport::uiDrawAtlasText(std::string_view text, int x, int top, std::uint32_t color, int font, int scale, const SphereUIUiRect &clip, float depth, bool configureAlpha)
{
    auto *device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get());
    if (device == nullptr)
        return;
    const int size = scale * 30u;
    if (top > clip.bottom || SphereUIDetail::addCoordinate(top, size) <= clip.top)
        return;
    if (configureAlpha && SferaColor::fromArgb(color).alpha() != 255)
        g_sfera_graphics_runtime.d3d_runtime->setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
    float z, reciprocal;
    if (!SphereUIRenderSupport::interfaceDepth(depth, z, reciprocal))
        return;
    IDirect3DBaseTexture9 *texture = nullptr;
    std::uint32_t vertex_count = 0u, index_count = 0u;
    for (const std::uint8_t byte : text)
    {
        if (byte == '\n')
            break;
        const auto character = SphereUIRenderSupport::uiAtlasGlyph(byte);
        if (x <= clip.right && SphereUIDetail::addCoordinate(x, size) > clip.left)
        {
            const auto &glyph = g_sfera_font_runtime.glyphs[character];
            const auto next_texture = g_sfera_font_runtime.faces[font].texture(glyph.texture_index);
            if ((texture != nullptr && texture != next_texture) || vertex_count + 4u > std::size(SphereUIInterfaceRenderer::glyph_vertices))
                flushAtlasText(device, texture, vertex_count, index_count);
            texture = next_texture;
            const auto left = x - 0.5f, upper = top - 0.5f;
            SphereUIRenderSupport::uiFontQuad(SphereUIInterfaceRenderer::glyph_vertices + vertex_count, left, upper, left + size, upper + size, color, glyph.u, glyph.v, glyph.u + 30.0f / 256.0f,
                                              glyph.v + 30.0f / 256.0f, true);
            for (std::uint32_t corner = 0; corner < 4; ++corner)
            {
                SphereUIInterfaceRenderer::glyph_vertices[vertex_count + corner].z = z;
                SphereUIInterfaceRenderer::glyph_vertices[vertex_count + corner].rhw = reciprocal;
            }
            SphereUIRenderSupport::uiFontTriangles(SphereUIInterfaceRenderer::quad_indices + index_count, vertex_count, true);
            vertex_count += 4u;
            index_count += 6u;
        }
        x = SphereUIDetail::addCoordinate(x, (g_sfera_font_runtime.faces[font].widths[character] + g_sfera_font_runtime.faces[font].code_base) * scale);
    }
    flushAtlasText(device, texture, vertex_count, index_count);
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE));
}

bool SphereUIRenderSupport::interfaceDepth(float depth, float &z, float &reciprocal)
{
    z = 0.0f;
    reciprocal = 1.0f;
    if (!(depth > 0.001f))
        return true;
    const double nearPlane = g_sfera_camera.near_distance, farPlane = g_sfera_camera.far_distance;
    if (depth < nearPlane || depth > farPlane)
        return false;
    z = SferaNumeric::real32((farPlane - nearPlane * farPlane / depth) / (farPlane - nearPlane));
    reciprocal = SferaNumeric::real32(1.0 / depth);
    return true;
}
