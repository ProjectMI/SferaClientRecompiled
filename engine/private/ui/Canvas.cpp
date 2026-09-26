#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <iterator>
#include <string_view>
#include <utility>
#include <variant>

#include "diagnostics/Diagnostics.h"
#include "environment/Environment.h"
#include "graphics/d3d9/Device.h"
#include "input/Cursors.h"
#include "math/Color.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "render/SceneRenderer.h"
#include "render/TextureAccess.h"
#include "render/VertexFormats.h"
#include "text/Fonts.h"
#include "text/Text.h"
#include "ui/Canvas.h"
#include "ui/Rendering.h"
#include "ui/WidgetSupport.h"

void GameUiElement::fitAxis(int &begin, int &end, int maximum)
{
    if (end > maximum)
    {
        begin += maximum - end;
        end = maximum;
    }
    if (begin < 0)
    {
        end -= begin;
        begin = 0;
    }
}

void GameUiElement::layoutText(std::string_view text, const GameUiWindow &window, int x, int y)
{
    if (text.empty() || window.font >= g_sfera_font_runtime.faces.size())
        SferaEngineDiagnostics::fail("Invalid text or font");
    GameUiElementText layout;
    layout.bytes = text;
    layout.bytes.push_back('\n');
    layout.font = window.font;
    layout.font_scale = window.fontScale;
    std::array<int, 300> widths{};
    int maximumWidth = 0;
    std::size_t begin = 0;
    for (std::size_t offset = 0; offset < layout.bytes.size(); ++offset)
    {
        auto &width = widths[layout.lines.size()];
        if (layout.bytes[offset] == '\n')
        {
            width *= layout.font_scale;
            maximumWidth = std::max(maximumWidth, width);
            layout.lines.push_back({begin});
            if (layout.lines.size() == widths.size())
                SferaEngineDiagnostics::fail("MNO_LINES_IN_TEXT exceeded");
            begin = offset + 1;
        }
        else
        {
            if (width > 0)
                width += g_sfera_font_runtime.faces[layout.font].code_base;
            const auto character = SferaText::byteValue(layout.bytes[offset]);
            width += g_sfera_font_runtime.faces[layout.font].widths[g_sfera_font_runtime.glyphs[character].defined ? character : 124u];
        }
    }
    if (layout.lines.empty() || maximumWidth == 0)
        SferaEngineDiagnostics::fail("Empty text created");
    color = window.textColor;
    alpha = 255;
    const auto textWidth = maximumWidth + 2;
    const int textHeight = g_sfera_font_runtime.textHeight(layout.font, layout.font_scale, SphereUIDetail::checkedInt(layout.lines.size(), "Text layout line count exceeds int"));
    SferaCanvasHost::setTextExtent(textWidth, textHeight);
    const auto style = window.textStyle;
    left = x;
    top = y;
    if (style & GameUiWindowcenterHorizontal)
        left -= textWidth / 2;
    if (style & GameUiWindowalignBottom)
        top -= textHeight;
    else if (style & GameUiWindowcenterVertical)
        top -= textHeight / 2;
    right = left + textWidth - 1;
    bottom = top + textHeight - 1;

    if (style & GameUiWindowfitHorizontal)
        fitAxis(left, right, window.contentRight - window.contentLeft);
    if (style & GameUiWindowfitVertical)
        fitAxis(top, bottom, window.contentBottom - window.contentTop);
    for (int line = 0; line < layout.lines.size(); ++line)
    {
        layout.lines[line].x = window.contentLeft + left + ((style & GameUiWindowcenterLines) ? (textWidth - widths[line]) / 2 : 0);
        layout.lines[line].y = window.contentTop + top + (line * g_sfera_font_runtime.faces[layout.font].cell_step - g_sfera_font_runtime.faces[layout.font].origin) * layout.font_scale;
    }
    content = std::move(layout);
}

SferaScreenVertex SferaCanvasRenderer::sprite_quad[4]{};

void SferaCanvasRenderer::interfaceQuad(SferaScreenVertex *vertices, float left, float top, float right, float bottom, std::uint32_t color, const float *uv, float z, float reciprocal,
                                        bool clearSpecular)
{
    for (std::size_t corner = 0; corner < 4; ++corner)
    {
        const bool onRight = corner == 1 || corner == 2, onBottom = corner >= 2;
        auto &vertex = vertices[corner];
        vertex = {onRight ? right : left,
                  onBottom ? bottom : top,
                  z,
                  reciprocal,
                  color,
                  clearSpecular ? 0u : vertex.specular,
                  uv ? uv[corner * 2] : (onRight ? 1.0f : 0.0f),
                  uv ? uv[corner * 2 + 1] : (onBottom ? 1.0f : 0.0f)};
    }
}

void SferaCanvasRenderer::interfaceNamedQuad(int left, int top, int width, int height, std::string_view name, std::uint32_t color, std::uint32_t alpha, float depth, const float *uv, bool worldSpace)
{
    if (width == 0 || height == 0)
        return;
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    const auto texture = SferaTextureAccess::find(name);
    device.checkResult(device.native_device->SetTexture(0, SferaTextureAccess::resource(texture)), "SetTexture");
    if (alpha != 255 || SferaTextureAccess::hasAlpha(texture))
        device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
    float z, reciprocal;
    if (!SphereUIRenderSupport::interfaceDepth(depth, z, reciprocal))
        return;
    auto *vertices = SceneSky::sun_quad;
    const float x = left - 0.5f, y = top - 0.5f;
    SferaCanvasRenderer::interfaceQuad(vertices, x, y, x + width, y + height, color, uv, z, reciprocal, true);
    device.checkResult(device.native_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE), "SetRenderState");
    device.checkResult(device.native_device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1), "SetFVF");
    if (worldSpace)
        device.drawVertices(D3DPT_TRIANGLEFAN, 14, vertices, 4, nullptr, 0, sizeof(SferaScreenVertex));
    else
        device.checkResult(device.native_device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertices, sizeof(SferaScreenVertex)), "DrawPrimitiveUP");
    device.last_hresult = device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}

HRESULT SferaCanvasRenderer::drawSpriteQuad(std::uint32_t color, const float *uv, float left, float top, float right, float bottom)
{
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    auto *vertices = SferaCanvasRenderer::sprite_quad;
    SferaCanvasRenderer::interfaceQuad(vertices, left - 0.5f, top - 0.5f, right - 0.5f, bottom - 0.5f, color, uv, 0.0f, 1.0f, false);
    return device.checkResult(device.native_device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertices, sizeof(SferaScreenVertex)), "DrawPrimitiveUP");
}

HRESULT SferaCanvasRenderer::drawSpriteTexture(std::uint32_t color, int texture, float left, float top, float right, float bottom, const float *uv, bool)
{
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    if (texture <= 0)
        device.checkResult(device.native_device->SetTexture(0, nullptr), "SetTexture");
    else
        SphereRenderSceneRenderer::bindTexture(texture);
    return drawSpriteQuad(color, uv, left, top, right, bottom);
}

void SferaCanvasRenderer::drawTexture(int left, int top, int width, int height, std::string_view name, std::uint32_t alpha, float depth, const float *uv)
{
    SferaCanvasRenderer::interfaceNamedQuad(left, top, width, height, name, SferaColor::rgba(255u, 255u, 255u, alpha).argb(), alpha, depth, uv, true);
}

void SferaCanvasRenderer::tintTexture(int left, int top, int width, int height, std::string_view name, std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint32_t alpha, const float *uv)
{
    SferaCanvasRenderer::interfaceNamedQuad(left, top, width, height, name, SferaColor::rgba(red, green, blue, alpha).argb(), alpha, 0.0f, uv, false);
}

void SferaCanvasRenderer::drawOverlay(std::uint32_t alpha)
{
    if (alpha == 0)
        return;
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    auto *vertices = SceneSky::sun_quad;
    SferaCanvasRenderer::interfaceQuad(vertices, 0.0f, 0.0f, SferaNumeric::real32(g_sfera_graphics_runtime.display_width), SferaNumeric::real32(g_sfera_graphics_runtime.display_height),
                                       SferaColor::rgba(255u, 255u, 255u, alpha).argb(), nullptr, 0.0f, 1.0f, true);
    device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
    device.checkResult(device.native_device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1), "SetFVF");
    device.drawVertices(D3DPT_TRIANGLEFAN, 14, vertices, 4, nullptr, 0, sizeof(SferaScreenVertex));
    device.last_hresult = device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}

void SferaCanvasRenderer::setRenderState()
{
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    device.checkResult(device.native_device->SetVertexShader(nullptr), "SetVertexShader");
    device.checkResult(device.native_device->SetPixelShader(nullptr), "SetPixelShader");
    device.checkResult(device.native_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE), "SetRenderState");
    for (auto state : {D3DRS_ZENABLE, D3DRS_ZWRITEENABLE, D3DRS_LIGHTING, D3DRS_FOGENABLE})
        device.checkResult(device.native_device->SetRenderState(state, FALSE), "SetRenderState");
    device.checkResult(device.native_device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1), "SetFVF");
    device.setColorOperation(0, D3DTOP_MODULATE, D3DTA_TEXTURE, D3DTA_DIFFUSE);
    device.setAlphaOperation(0, D3DTOP_MODULATE, D3DTA_TEXTURE, D3DTA_DIFFUSE);
    for (auto state : {D3DSAMP_ADDRESSU, D3DSAMP_ADDRESSV})
        device.checkResult(device.native_device->SetSamplerState(0, state, D3DTADDRESS_CLAMP), "SetSamplerState");
}

void SferaCanvasRenderer::restoreRenderState()
{
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    for (auto state : {D3DSAMP_ADDRESSU, D3DSAMP_ADDRESSV})
        device.checkResult(device.native_device->SetSamplerState(0, state, D3DTADDRESS_WRAP), "SetSamplerState");
    for (auto state : {D3DRS_LIGHTING, D3DRS_FOGENABLE, D3DRS_ZWRITEENABLE, D3DRS_ZENABLE})
        device.checkResult(device.native_device->SetRenderState(state, TRUE), "SetRenderState");
    device.checkResult(device.native_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW), "SetRenderState");
}

void SferaCanvasRenderer::drawAtlasText(std::string_view text, int x, int y, std::uint32_t color, int scale, int font, float depth)
{
    SphereUIRenderSupport::uiDrawAtlasText(text, x, y, color, font, scale,
                                           {SphereUIInterfaceRenderer::clip_rectangle.left, SphereUIInterfaceRenderer::clip_rectangle.top, SphereUIInterfaceRenderer::clip_rectangle.right,
                                            SphereUIInterfaceRenderer::clip_rectangle.bottom},
                                           depth, true);
}

void SferaCanvasRenderer::drawElement(const GameUiElement &element, int scrollX, int scrollY, int x, int y, std::uint32_t alpha, float depth)
{
    if (const auto *sprite = std::get_if<GameUiElementSprite>(&element.content))
    {
        const int element_alpha = element.alpha, distance_alpha = alpha;
        const auto opacity = element_alpha * distance_alpha / 255;
        SferaCanvasRenderer::drawTexture(sprite->left - scrollX + x, sprite->top - scrollY + y, sprite->width, sprite->height, sprite->texture, opacity, depth, nullptr);
    }
    else
    {
        const auto &text = std::get<GameUiElementText>(element.content);
        const int text_alpha = SferaColor::fromArgb(element.color).alpha(), distance_alpha = alpha;
        const auto opacity = text_alpha * distance_alpha / 255;
        const auto color = SferaColor::fromArgb(element.color).withAlpha(opacity).argb();
        for (const auto &line : text.lines)
            SferaCanvasRenderer::drawAtlasText(std::string_view(text.bytes).substr(line.offset), line.x - scrollX + x, line.y - scrollY + y, color, text.font_scale, text.font, depth);
    }
}

void SferaCanvasRenderer::beginWindow(const GameUiWindow &window)
{
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    const D3DVIEWPORT9 viewport{SferaNumeric::word(window.contentLeft),
                                SferaNumeric::word(window.contentTop),
                                SferaNumeric::word(window.contentRight - window.contentLeft + 1),
                                SferaNumeric::word(window.contentBottom - window.contentTop + 1),
                                0,
                                1};
    device.last_hresult = device.native_device->SetViewport(&viewport);
    SphereUIInterfaceRenderer::clip_rectangle = {window.contentLeft, window.contentTop, window.contentRight, window.contentBottom};
}

void SferaCanvasRenderer::endWindow()
{
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    const D3DVIEWPORT9 fullViewport{0u, 0u, SferaNumeric::word(g_sfera_graphics_runtime.display_width), SferaNumeric::word(g_sfera_graphics_runtime.display_height), 0.0f, 1.0f};
    device.last_hresult = device.native_device->SetViewport(&fullViewport);
}

void GameUiWindow::clampAxis(float &scroll, int limit, int &position)
{
    if (scroll < 0.0f)
    {
        const double precise_position = position;
        position = SferaNumeric::truncateInt(precise_position + scroll);
        scroll = 0.0f;
    }
    const float maximum = SferaNumeric::real32(limit);
    if (scroll > maximum)
    {
        const double precise_scroll = scroll;
        position = SferaNumeric::truncateInt(precise_scroll - maximum + position);
        scroll = maximum;
    }
}

std::uint32_t GameUiWindow::attach(std::uint32_t control)
{
    const auto slot = std::find(controls.begin(), controls.end(), UINT32_MAX);
    if (slot != controls.end())
    {
        *slot = control;
        return SphereUIDetail::wireWord(slot - controls.begin());
    }
    if (controls.size() >= 7000)
        SferaEngineDiagnostics::fail("MNO_CONTROLS_IN_WINDOW exceed");
    controls.push_back(control);
    return SphereUIDetail::wireWord(controls.size() - 1u);
}

void GameUiWindow::detach(std::uint32_t slot)
{
    if (slot >= std::size(controls))
        SferaEngineDiagnostics::fail("Window control slot is outside the control table");
    if (controls[slot] == UINT32_MAX)
        SferaEngineDiagnostics::fail("internal error 86557243");
    controls[slot] = UINT32_MAX;
}

void GameUiWindow::recalculateSize()
{
    int maximumRight = 0, maximumBottom = 0;
    for (auto handle : controls)
    {
        if (handle == UINT32_MAX)
            continue;
        const auto *item = SferaCanvasHost::control(handle);
        if (!item)
            SferaEngineDiagnostics::fail("internal error 47581837");
        maximumRight = std::max(maximumRight, item->right);
        maximumBottom = std::max(maximumBottom, item->bottom);
    }
    width = std::max(maximumRight + 1, contentRight - contentLeft + 1);
    height = std::max(maximumBottom + 1, contentBottom - contentTop + 1);
}

bool GameUiWindow::takeInput(std::uint32_t &control, std::uint32_t &message)
{
    if (events.empty())
        return false;
    const auto event = events.front();
    events.pop_front();
    control = event.control;
    message = event.message;
    return true;
}

SferaCursorPosition GameUiWindow::contentPosition(SferaCursorPosition point) const
{
    if (point.x < contentLeft || point.x >= contentRight || point.y < contentTop || point.y >= contentBottom)
        return {-1, -1};
    return {point.x - contentLeft + SferaNumeric::truncateInt(scrollX), point.y - contentTop + SferaNumeric::truncateInt(scrollY)};
}

void GameUiWindow::scrollBy(float dx, float dy, SferaCursorPosition &cursor)
{
    scrollX -= dx;
    scrollY -= dy;

    clampAxis(scrollX, width - (contentRight - contentLeft + 1), cursor.x);
    clampAxis(scrollY, height - (contentBottom - contentTop + 1), cursor.y);
}
