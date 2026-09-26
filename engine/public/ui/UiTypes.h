#pragma once

#include <cstddef>
#include <cstdint>
#include <string>

#include "math/Color.h"

struct SphereUITextExtent;
struct SphereUIUiIndexRange;
struct SphereUIUiRect;
struct SphereUIUiViewport;

struct SphereUIUiRect
{
    int left;
    int top;
    int right;
    int bottom;
};

struct SphereUIUiViewport
{
    int x;
    int y;
    int width;
    int height;
    float minimum_z;
    float maximum_z;
};

struct SphereUITextExtent
{
    int width;
    int height;
};

struct SphereUIUiIndexRange
{
    std::size_t first;
    std::size_t last;
};

struct SphereUIImageDescription;
struct SphereUIImageDescriptionParameters;

struct SphereUIImageDescriptionParameters
{
    std::string texture_name;
    int width;
    int height;
    SphereUIUiRect rectangle;
    std::uint32_t flags;
};

struct SphereUIImageDescription
{
    std::string name;
    SphereUIImageDescriptionParameters image;
};

class TextAlignment;

class TextAlignment
{
  public:
    static constexpr std::uint32_t right = 1u << 0u;
    static constexpr std::uint32_t bottom = 1u << 1u;
    static constexpr std::uint32_t horizontalCenter = 1u << 2u;
    static constexpr std::uint32_t verticalCenter = 1u << 3u;
    static constexpr std::uint32_t center = horizontalCenter | verticalCenter;
};

class UiColor;

class UiColor
{
  public:
    static constexpr std::uint32_t white = SferaColor::rgba(255u, 255u, 255u, 255u).argb();
    static constexpr std::uint32_t opaqueBlack = SferaColor::rgba(0u, 0u, 0u, 255u).argb();
    static constexpr std::uint32_t whiteRgb = SferaColor::rgba(255u, 255u, 255u, 0u).argb();
    static constexpr std::uint32_t frameBackground = SferaColor::rgba(40u, 36u, 32u, 0u).argb();
    static constexpr std::uint32_t tooltipBackground = SferaColor::rgba(255u, 255u, 225u, 0u).argb();
    static constexpr std::uint32_t listSelection = SferaColor::rgba(0u, 0u, 0u, 50u).argb();
    static constexpr std::uint32_t slotFill = SferaColor::rgba(20u, 20u, 20u, 0u).argb();
    static constexpr std::uint32_t slotBorder = SferaColor::rgba(158u, 124u, 106u, 255u).argb();
    static constexpr std::uint32_t slotRejected = SferaColor::rgba(130u, 28u, 27u, 0u).argb();
    static constexpr std::uint32_t slotAccepted = SferaColor::rgba(54u, 100u, 37u, 0u).argb();
    static constexpr std::uint32_t hyperLink = SferaColor::rgba(255u, 0u, 0u, 255u).argb();
    static constexpr std::uint32_t hyperLinkHover = SferaColor::rgba(255u, 255u, 0u, 255u).argb();
};
