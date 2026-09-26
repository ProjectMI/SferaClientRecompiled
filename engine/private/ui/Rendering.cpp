#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <stdexcept>
#include <string_view>

#include "graphics/d3d9/Device.h"
#include "math/Color.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "render/TextureAccess.h"
#include "render/VertexFormats.h"
#include "text/Fonts.h"
#include "ui/Rendering.h"
#include "ui/Sprite.h"
#include "ui/UiTypes.h"
#include "ui/WidgetSupport.h"

void SferaInterfaceCursor::setImageSize(std::size_t layer, int width, int height)
{
    if (layer >= images.size())
        return;
    images[layer].width = width;
    images[layer].height = height;
}

void SferaInterfaceCursor::setText(std::size_t layer, std::string_view text, int x, int y, int font, std::uint32_t color)
{
    if (layer >= labels.size())
        return;
    auto &label = labels[layer];
    label.x = x;
    label.y = y;
    label.font = font;
    label.color = color;
    label.text = text;
}

void SferaInterfaceCursor::draw(float x, float y) const
{
    auto *device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get());
    if (!system_visible || device == nullptr)
        return;
    RenderStateScope state(*g_sfera_graphics_runtime.d3d_runtime, RenderStateScopeFailurePolicy::Skip);
    if (!state)
        return;
    if (centered_hotspot)
    {
        x -= 16.0f;
        y -= 16.0f;
    }
    device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    if (kind < textures.size() && textures[kind] != 0)
        SphereUIInterfaceRenderer::drawTexture(SferaTextureAccess::resource(textures[kind]), x, y, x + 32.0f, y + 32.0f, UiColor::white);
    for (const auto &image : images)
    {
        if (image.texture == -1)
            continue;
        const float left = x + image.x, top = y + image.y;
        SphereUIInterfaceRenderer::drawTexture(SferaTextureAccess::resource(image.texture), left, top, left + image.width, top + image.height, UiColor::white);
    }
    device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    const SphereUIUiRect clip{SphereUIInterfaceRenderer::clip_rectangle.left, SphereUIInterfaceRenderer::clip_rectangle.top, SphereUIInterfaceRenderer::clip_rectangle.right,
                              SphereUIInterfaceRenderer::clip_rectangle.bottom};
    const double label_origin_x = x, label_origin_y = y;
    for (const auto &label : labels)
    {
        if (label.text.empty())
            continue;
        SphereUIInterfaceRenderer::drawText(label.text, SferaNumeric::truncateInt(label_origin_x + label.x), SferaNumeric::truncateInt(label_origin_y + label.y), label.color, label.font, true, clip,
                                            SferaColor::fromArgb(label.color).alpha() == 255u);
    }
}

std::array<SferaScreenVertex, 4> SphereUIUiSprite::spriteQuad(const SphereUISpritePart &part, float left, float top, float right, float bottom, std::uint32_t color)
{
    std::array<SferaScreenVertex, 4> vertices{};
    for (std::size_t index = 0u; index < vertices.size(); ++index)
    {
        auto &vertex = vertices[index];
        vertex.x = index == 0u || index == 3u ? left : right;
        vertex.y = index < 2u ? top : bottom;
        vertex.rhw = 1.0f;
        vertex.diffuse = color;
        vertex.u = part.u[index];
        vertex.v = part.v[index];
    }
    return vertices;
}

void SphereUIUiSprite::drawParts(float left, float top, float right, float bottom, std::uint32_t color, bool natural) const
{
    if (parts.size() == 0u && !natural)
        return;
    auto *device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get());
    if (device == nullptr)
        return;
    device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    if (parts.size() == 0u)
        return;
    const float scale_x = natural ? 1.0f : (right - left) / width, scale_y = natural ? 1.0f : (bottom - top) / height;
    left -= 0.5f;
    top -= 0.5f;
    int previous_texture = -1;
    for (std::size_t index = 0u; index < parts.size(); ++index)
    {
        const auto &part = parts[index];
        if (part.texture != previous_texture)
        {
            g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, SferaTextureAccess::resource(part.texture));
            previous_texture = part.texture;
        }

        const auto vertices = SphereUIUiSprite::spriteQuad(part, left + spritePosition(natural, part.rectangle.left, scale_x), top + spritePosition(natural, part.rectangle.top, scale_y),
                                                           left + spritePosition(natural, part.rectangle.right, scale_x), top + spritePosition(natural, part.rectangle.bottom, scale_y), color);
        (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1));
        (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2u, vertices.data(), sizeof(SferaScreenVertex)));
    }
}

void SphereUIUiSprite::drawRotated(float left, float top, float right, float bottom, std::uint32_t color, double rotation) const
{
    if (parts.size() == 0u)
        return;
    const auto &part = parts.front();
    auto *device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get());
    if (device == nullptr)
        return;
    const float sine = SferaNumeric::real32(std::sin(rotation));
    const float cosine = SferaNumeric::real32(std::cos(rotation));
    const float sprite_width = right - left, sprite_height = bottom - top, center_x = (left + right) * 0.5f - 0.5f, center_y = (top + bottom) * 0.5f - 0.5f;
    auto vertices = SphereUIUiSprite::spriteQuad(part, -sprite_width * 0.5f, -sprite_height * 0.5f, sprite_width * 0.5f, sprite_height * 0.5f, color);
    for (auto &vertex : vertices)
    {
        const float local_x = vertex.x, local_y = vertex.y;
        vertex.x = center_x + local_x * cosine - local_y * sine;
        vertex.y = center_y + local_x * sine + local_y * cosine;
    }
    g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, SferaTextureAccess::resource(part.texture));
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2u, vertices.data(), sizeof(SferaScreenVertex)));
}

void SphereUIUiSprite::draw(float left, float top, float right, float bottom, std::uint32_t color, float rotation) const
{
    if (rotation == 0.0f)
        drawParts(left, top, right, bottom, color, false);
    else
        drawRotated(left, top, right, bottom, color, rotation);
}

float SphereUIUiSprite::spritePosition(bool natural, int value, float scale)
{
    const auto result = value * scale;
    return natural ? result : std::floor(result);
}

void SphereUIInterfaceRenderer::flushFaceText(SferaScreenVertex *vertices, std::size_t &batch_first, std::uint32_t &batch_count, std::uint32_t &index_count)
{
    SphereUIRenderSupport::uiSubmitFont(vertices + batch_first, batch_count, g_sfera_fonts.quad_indices.data(), index_count);
    batch_count = 0u;
    index_count = 0u;
    batch_first = g_sfera_fonts.vertex_count;
}

void SphereUIInterfaceRenderer::drawFaceText(std::string_view text, int x, int y, std::uint32_t color, int font, const SphereUIUiRect &clip)
{
    const auto &face = g_sfera_fonts.face(font);
    if (y > clip.bottom || SphereUIDetail::addCoordinate(y, face.line_height) <= clip.top ||
        (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get()) == nullptr)
        return;
    auto *texture = SferaTextureAccess::resource(face.texture);
    if (auto *device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get()))
        (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, texture));
    const auto *glyphs = face.glyphs.data();
    auto &factory = g_sfera_fonts;
    auto *vertices = factory.vertices.data();
    if (factory.vertices.empty())
        throw std::runtime_error("font vertex buffer is unavailable");
    if (factory.vertex_count >= 1200u)
        factory.vertex_count = 0u;
    std::size_t batch_first = factory.vertex_count;
    std::uint32_t batch_count = 0u, index_count = 0u;
    const float origin = x - 0.5f;
    float left = origin, top = y - 0.5f;
    for (const std::uint8_t character : text)
    {
        if (character == '\n')
        {
            left = origin;
            top += face.line_height;
            continue;
        }
        if (character < 32u)
            continue;
        const auto &glyph = glyphs[character];
        if (character == ' ' || left + glyph.width <= clip.left)
        {
            left += glyph.advance;
            continue;
        }
        if (left > clip.right)
            break;
        const auto glyph_left = left + glyph.bearing_x, glyph_top = top - glyph.bearing_y;
        SphereUIRenderSupport::uiFontQuad(vertices + factory.vertex_count, glyph_left, glyph_top, glyph_left + glyph.width, glyph_top + glyph.height, color, glyph.u0, glyph.v0, glyph.u1, glyph.v1,
                                          false);
        SphereUIRenderSupport::uiFontTriangles(factory.quad_indices.data() + index_count, batch_count, false);
        factory.vertex_count += 4u;
        batch_count += 4u;
        index_count += 6u;
        if (factory.vertex_count > 1194u)
        {
            flushFaceText(vertices, batch_first, batch_count, index_count);
            factory.vertex_count = 0u;
            batch_first = 0u;
        }
        left += glyph.advance;
    }
    flushFaceText(vertices, batch_first, batch_count, index_count);
}

SphereUITextExtent SphereUIInterfaceRenderer::measureText(std::string_view text, int font, bool initialized)
{
    std::uint32_t width = 0u, line_width = 0u, extra_height = 0u;
    if (font >= 2u)
    {
        const auto &face = g_sfera_fonts.face(font);
        const auto *glyphs = face.glyphs.data();
        for (const std::uint8_t byte : text)
        {
            if (byte == '\n')
            {
                width = std::max(width, line_width);
                line_width = 0u;
                extra_height += SferaNumeric::word(face.line_height);
            }
            else
            {
                constexpr std::uint8_t lowercase_yo = 184u, lowercase_e = 229u, uppercase_yo = 168u, uppercase_e = 197u;
                const auto character = byte == lowercase_yo ? lowercase_e : byte == uppercase_yo ? uppercase_e : byte;
                const std::int32_t advance = glyphs[character].advance;
                line_width += SferaNumeric::word(advance);
            }
        }
        SphereUITextExtent result{};
        result.width = SferaNumeric::signedWord(std::max(width, line_width));
        result.height = SferaNumeric::signedWord(extra_height + SferaNumeric::word(face.line_height));
        return result;
    }
    std::uint32_t lines = 1u;
    const auto &face = g_sfera_font_runtime.faces[font];
    for (const std::uint8_t byte : text)
    {
        if (byte == '\n')
        {
            const auto completed_width = initialized ? line_width : 0u;
            if (SferaNumeric::signedWord(completed_width) > SferaNumeric::signedWord(width))
                width = completed_width;
            if (++lines == 300u)
                throw std::length_error("too many lines in font measurement");
            line_width = 0u;
        }
        else
        {
            if (SferaNumeric::signedWord(line_width) > 0)
                line_width += SferaNumeric::word(face.code_base);
            line_width += SferaNumeric::word(g_sfera_font_runtime.faces[font].widths[SphereUIRenderSupport::uiAtlasGlyph(byte)]);
        }
    }
    if (SferaNumeric::signedWord(line_width) > SferaNumeric::signedWord(width))
        width = line_width;
    std::uint32_t height = 0u;
    if (initialized)
    {
        height = (lines - 1u) * SferaNumeric::word(face.cell_step);
        height -= SferaNumeric::word(face.origin);
        height += SferaNumeric::word(face.span) + 2u;
    }
    SphereUITextExtent result{};
    result.width = SferaNumeric::signedWord(width + 2u);
    result.height = SferaNumeric::signedWord(height + (font == 1u ? 2u : 0u));
    return result;
}

void SphereUIInterfaceRenderer::drawText(std::string_view text, int x, int y, std::uint32_t color, int font, bool initialized, const SphereUIUiRect &clip, bool opaque)
{
    SphereUIInterfaceRenderer::clip_rectangle.left = clip.left;
    SphereUIInterfaceRenderer::clip_rectangle.top = clip.top;
    SphereUIInterfaceRenderer::clip_rectangle.right = clip.right;
    SphereUIInterfaceRenderer::clip_rectangle.bottom = clip.bottom;
    const bool disable_blending = opaque && font < 2u;
    if (disable_blending)
        SphereUIInterfaceRenderer::setSpriteRenderMode(0u);
    if (font < 2u)
        SphereUIRenderSupport::uiDrawAtlasText(text, x, SphereUIDetail::subtractCoordinate(SphereUIDetail::subtractCoordinate(y, 2), g_sfera_font_runtime.faces[font].origin), color, font,
                                               initialized ? 1 : 0, clip, 0.0f, false);
    else
        drawFaceText(text, x, y, color, font, clip);
    if (disable_blending)
        SphereUIInterfaceRenderer::setSpriteRenderMode(1u);
}

std::uint32_t SphereUIInterfaceRenderer::tracking(int font) noexcept
{
    return font >= 0 && font < 2 ? g_sfera_font_runtime.faces[font].code_base : 0u;
}

void SphereUIInterfaceRenderer::drawTexture(IDirect3DBaseTexture9 *texture, float left, float top, float right, float bottom, std::uint32_t color, float u, float v, bool textured)
{
    auto *device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get());
    if (device == nullptr)
        return;
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, texture));
    std::array<SferaScreenVertex, 4> vertices{};
    const float offset = textured ? 0.5f : 0.0f;
    for (std::size_t index = 0u; index < 4u; ++index)
    {
        auto &vertex = vertices[index];
        vertex.x = (index == 0u || index == 3u ? left : right) - offset;
        vertex.y = (index < 2u ? top : bottom) - offset;
        vertex.z = 0.0f;
        vertex.rhw = 1.0f;
        vertex.diffuse = color;
        if (textured)
        {
            vertex.u = index == 0u || index == 3u ? 0.0f : u;
            vertex.v = index < 2u ? 0.0f : v;
        }
    }
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1));
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2u, vertices.data(), sizeof(SferaScreenVertex)));
}

void SphereUIInterfaceRenderer::setSpriteRenderMode(std::uint32_t mode)
{
    if (mode == SphereUIInterfaceRenderer::sprite_render_mode)
        return;
    if (auto *device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get()); device != nullptr && mode <= 2u)
    {
        device->SetRenderState(D3DRS_ALPHABLENDENABLE, mode == 0u ? FALSE : TRUE);
        if (mode != 0u)
        {
            device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
            device->SetRenderState(D3DRS_DESTBLEND, mode == 2u ? D3DBLEND_ONE : D3DBLEND_INVSRCALPHA);
        }
    }
    SphereUIInterfaceRenderer::sprite_render_mode = mode;
}

SphereUIUiViewport SphereUIInterfaceRenderer::viewport()
{
    D3DVIEWPORT9 value{};
    if (auto *device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get()))
        (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->GetViewport(&value));
    SphereUIUiViewport result{};
    result.x = SphereUIDetail::checkedInt(value.X, "D3D viewport X exceeds UI coordinate range");
    result.y = SphereUIDetail::checkedInt(value.Y, "D3D viewport Y exceeds UI coordinate range");
    result.width = SphereUIDetail::checkedInt(value.Width, "D3D viewport width exceeds UI coordinate range");
    result.height = SphereUIDetail::checkedInt(value.Height, "D3D viewport height exceeds UI coordinate range");
    result.minimum_z = value.MinZ;
    result.maximum_z = value.MaxZ;
    return result;
}

void SphereUIInterfaceRenderer::setViewport(const SphereUIUiViewport &value)
{
    if (value.x < 0 || value.y < 0 || value.width < 0 || value.height < 0)
        throw std::out_of_range("Negative D3D viewport");
    if (auto *device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get()))
    {
        const DWORD x = value.x, y = value.y, width = value.width, height = value.height;
        const D3DVIEWPORT9 viewport{x, y, width, height, value.minimum_z, value.maximum_z};
        device->SetViewport(&viewport);
    }
}

uint32_t SphereUIInterfaceRenderer::sprite_render_mode = UINT32_MAX;

SphereUIUiRect SphereUIInterfaceRenderer::clip_rectangle{};

SferaScreenVertex SphereUIInterfaceRenderer::glyph_vertices[1200]{};

uint16_t SphereUIInterfaceRenderer::quad_indices[1800]{};
