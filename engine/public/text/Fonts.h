#pragma once

#include <windows.h>
#include <array>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <vector>
#include <wrl/client.h>

#include "binary/Binary.h"

struct SferaScreenVertex;

class GameFontAtlas;
struct GameFontAtlasFace;
struct SferaFontGlyphRuntime;

struct SferaFontGlyphRuntime
{
    uint32_t texture_index;
    float u;
    float v;
    bool defined;
};

struct GameFontAtlasFace
{
    int span = 0;
    int origin = 0;
    int cell_step = 0;
    int code_base = 0;
    std::array<int, 256> widths{};
    std::vector<Microsoft::WRL::ComPtr<IDirect3DTexture9>> pages;
    IDirect3DTexture9 *texture(std::size_t page) const noexcept
    {
        return page < pages.size() ? pages[page].Get() : nullptr;
    }
};

class GameFontAtlas
{
  public:
    std::string language_suffix;
    // The existing character map is shared by all faces; its reload policy is unchanged.
    SferaFontGlyphRuntime glyphs[256]{};
    std::array<GameFontAtlasFace, 5> faces;
    GameFontAtlas() = default;
    GameFontAtlas(const GameFontAtlas &) = delete;
    GameFontAtlas &operator=(const GameFontAtlas &) = delete;
    void clear() noexcept
    {
        for (auto &face : faces)
            face.pages.clear();
    }
    int textHeight(int font, int scale, int lines) const
    {
        return ((lines - 1) * faces[font].cell_step + faces[font].span) * scale;
    }
    void load(int font, const std::string &filename, int outline, int spacing, int emptyWidth);

  private:
    friend struct GameFontAtlasFace;

  private:
    static void uploadPage(std::array<std::uint16_t, 256 * 256> &pixels, std::vector<Microsoft::WRL::ComPtr<IDirect3DTexture9>> &pages);
};

extern GameFontAtlas g_sfera_font_runtime;

class SphereUIFontFace;
struct SphereUIFontGlyph;

struct SphereUIFontGlyph
{
    std::uint16_t width = 0u;
    std::uint16_t height = 0u;
    std::int16_t bearing_x = 0;
    std::int16_t bearing_y = 0;
    std::int16_t advance = 0;

    float u0 = 0.0f;
    float v0 = 0.0f;
    float u1 = 0.0f;
    float v1 = 0.0f;
    static constexpr std::size_t encodedSize = 28;
    static SphereUIFontGlyph decode(std::span<const std::uint8_t> bytes)
    {
        SferaBinaryReader reader(bytes);
        SphereUIFontGlyph glyph;
        glyph.width = reader.read<std::uint16_t>();
        glyph.height = reader.read<std::uint16_t>();
        glyph.bearing_x = reader.read<std::int16_t>();
        glyph.bearing_y = reader.read<std::int16_t>();
        glyph.advance = reader.read<std::int16_t>();
        reader.take(2u); // Reserved bytes in the SFNT record.
        glyph.u0 = reader.read<float>();
        glyph.v0 = reader.read<float>();
        glyph.u1 = reader.read<float>();
        glyph.v1 = reader.read<float>();
        return glyph;
    }
};

class SphereUIFontFace
{
  public:
    int texture = -1;
    std::array<SphereUIFontGlyph, 256> glyphs{};
    std::string name;
    int line_height = 0;
    int baseline = 0;
    bool load(std::optional<std::string_view> display_name, const std::string &filename, std::string_view texture_name);
    bool load(std::nullptr_t, const std::string &, std::string_view) = delete;
};

class SphereUIFontFactory;
class SphereUIInterfaceRenderer;

class SphereUIFontFactory
{
  public:
    SphereUIFontFactory();
    ~SphereUIFontFactory();
    SphereUIFontFactory(const SphereUIFontFactory &) = delete;
    SphereUIFontFactory &operator=(const SphereUIFontFactory &) = delete;
    void initialize();
    void clear();
    bool load(const std::string &filename, std::string_view texture_name);
    void loadNamedFont(std::string_view name);
    void loadConfiguration();
    int count() const noexcept;
    const SphereUIFontFace &face(int font) const;

  private:
    friend class SphereUIInterfaceRenderer;
    std::vector<std::unique_ptr<SphereUIFontFace>> faces;
    std::vector<SferaScreenVertex> vertices;
    std::vector<std::uint16_t> quad_indices;
    std::size_t vertex_count = 0u;
};

extern SphereUIFontFactory g_sfera_fonts;

struct SferaScreenVertex;
class SphereUIRenderSupport;
struct SphereUIUiRect;

class SphereUIRenderSupport
{
  public:
    static bool interfaceDepth(float depth, float &z, float &reciprocal);
    static std::uint8_t uiAtlasGlyph(std::uint8_t character);
    static void uiDrawAtlasText(std::string_view text, int x, int top, std::uint32_t color, int font, int scale, const SphereUIUiRect &clip, float depth, bool configureAlpha);
    static void uiFontQuad(SferaScreenVertex *vertices, float left, float top, float right, float bottom, std::uint32_t color, float u0, float v0, float u1, float v1, bool clockwise);
    static void uiFontTriangles(std::uint16_t *indices, std::uint32_t first, bool clockwise);
    static void uiSubmitFont(const SferaScreenVertex *vertices, std::uint32_t vertex_count, const std::uint16_t *indices, std::uint32_t index_count);

  private:
    static void flushAtlasText(IDirect3DDevice9 *device, IDirect3DBaseTexture9 *texture, std::uint32_t &vertex_count, std::uint32_t &index_count);
};
