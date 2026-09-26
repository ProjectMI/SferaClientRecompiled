#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <string_view>

#include "ui/UiRuntime.h"
#include "ui/UiTypes.h"

struct IDirect3DBaseTexture9;

struct SferaScreenVertex;
class SphereUIInterfaceRenderer;
struct SphereUITextExtent;
struct SphereUIUiRect;
struct SphereUIUiViewport;

class SphereUIInterfaceRenderer
{
  public:
    static uint32_t sprite_render_mode;
    static SphereUIUiRect clip_rectangle;
    static SferaScreenVertex glyph_vertices[1200];
    static uint16_t quad_indices[1800];

    static SphereUITextExtent measureText(std::string_view text, int font, bool initialized);
    static std::uint32_t tracking(int font) noexcept;
    static void drawText(std::string_view text, int x, int y, std::uint32_t color, int font, bool initialized, const SphereUIUiRect &clip, bool opaque);
    static void reportError(std::string_view message);
    static void drawTexture(IDirect3DBaseTexture9 *texture, float left, float top, float right, float bottom, std::uint32_t color, float u = 1.0f, float v = 1.0f, bool textured = true);
    static void setSpriteRenderMode(std::uint32_t mode);
    static SphereUIUiViewport viewport();
    static void setViewport(const SphereUIUiViewport &viewport);

  private:
    static void drawFaceText(std::string_view text, int x, int y, std::uint32_t color, int font, const SphereUIUiRect &clip);

  private:
    static void flushFaceText(SferaScreenVertex *vertices, std::size_t &batch_first, std::uint32_t &batch_count, std::uint32_t &index_count);
};

class SphereUIViewportScope;

class SphereUIViewportScope
{
    SphereUIUiViewport saved{};
    bool changed = false;
    bool restore = true;

  public:
    explicit SphereUIViewportScope(const SphereUIUiRect &bounds, bool restore_viewport = true) : restore(restore_viewport)
    {
        const auto screen = SphereUIRuntime::screenSize();
        const auto left = std::max(0, bounds.left), top = std::max(0, bounds.top), right = std::min(screen.width, bounds.right), bottom = std::min(screen.height, bounds.bottom);
        if (right <= left || bottom <= top)
            return;
        saved = SphereUIInterfaceRenderer::viewport();
        SphereUIInterfaceRenderer::setViewport({left, top, right - left, bottom - top, 0.0f, 1.0f});
        changed = true;
    }

    SphereUIViewportScope(const SphereUIViewportScope &) = delete;
    SphereUIViewportScope &operator=(const SphereUIViewportScope &) = delete;

    ~SphereUIViewportScope()
    {
        if (changed && restore)
            SphereUIInterfaceRenderer::setViewport(saved);
    }

    explicit operator bool() const
    {
        return changed;
    }
};

class SferaInterfaceCursor;
struct SferaInterfaceCursorImageLayer;
struct SferaInterfaceCursorTextLayer;

struct SferaInterfaceCursorImageLayer
{
    int x = 0;
    int y = 0;
    int texture = -1;
    int width = 0u;
    int height = 0u;
};

struct SferaInterfaceCursorTextLayer
{
    int x = 0;
    int y = 0;
    std::string text;
    int font = 0u;
    std::uint32_t color = 0u;
};

class SferaInterfaceCursor
{
  public:
    bool system_visible = true;
    bool centered_hotspot = false;
    std::uint8_t kind = 255u;
    SferaInterfaceCursor() = default;
    bool loadTextures();
    void setImage(std::size_t layer, std::optional<std::string_view> texture, int x, int y);
    void setImage(std::size_t, std::nullptr_t, int, int) = delete;
    void setImageSize(std::size_t layer, int width, int height);
    void setText(std::size_t layer, std::string_view text, int x, int y, int font, std::uint32_t color);
    void setKind(std::uint32_t cursor_kind);
    void draw(float x, float y) const;

  private:
    std::array<int, 4> textures{};
    std::array<SferaInterfaceCursorImageLayer, 3> images{};
    std::array<SferaInterfaceCursorTextLayer, 3> labels{};

  private:
    friend struct SferaInterfaceCursorImageLayer;
    friend struct SferaInterfaceCursorTextLayer;
};
