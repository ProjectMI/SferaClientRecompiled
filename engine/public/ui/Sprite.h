#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

#include "ui/UiTypes.h"

struct SferaScreenVertex;

struct SferaParserRange;
class SferaSimpleParser;
struct SphereUIImageDescription;
struct SphereUISpritePart;
struct SphereUIUiSprite;

struct SphereUISpritePart
{
    std::string texture_name;
    int texture{};
    float u[4]{};
    float v[4]{};
    SphereUIUiRect rectangle{};
    void setTexture(std::string_view texture_name, const SphereUIUiRect *texture_rectangle, const SphereUIUiRect *sprite_rectangle);
};

struct SphereUIUiSprite
{
    std::string name;
    int width{};
    int height{};
    std::vector<SphereUISpritePart> parts;
    void drawNatural(float left, float top, std::uint32_t color) const
    {
        drawParts(left, top, left + width, top + height, color, true);
    }
    void draw(float left, float top, float right, float bottom, std::uint32_t color, float rotation = 0.0f) const;
    void setImage(std::string_view name);
    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range);
    void resetParts(std::size_t count)
    {
        if (parts.size() != count)
            parts = std::vector<SphereUISpritePart>(count);
    }
    void setDescription(const struct SphereUIImageDescription &description);

  private:
    void drawParts(float left, float top, float right, float bottom, std::uint32_t color, bool natural) const;
    void drawRotated(float left, float top, float right, float bottom, std::uint32_t color, double rotation) const;

  private:
    static void uiSpriteLoadDiagnostic(const std::string &filename, const SferaParserRange &range, std::string_view message);
    static std::array<SferaScreenVertex, 4> spriteQuad(const SphereUISpritePart &part, float left, float top, float right, float bottom, std::uint32_t color);

  private:
    static float spritePosition(bool natural, int value, float scale);
};
