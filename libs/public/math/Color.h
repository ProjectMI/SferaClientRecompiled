#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

struct SferaColor;

struct SferaColor
{
    std::array<std::uint8_t, 4> channels;
    static constexpr SferaColor rgba(std::uint32_t red, std::uint32_t green, std::uint32_t blue, std::uint32_t alpha = 255u)
    {
        const std::array components{red, green, blue, alpha};
        SferaColor result{};
        for (std::size_t index = 0; index < components.size(); ++index)
            result.channels[index] = static_cast<std::uint8_t>(components[index]);
        return result;
    }
    static constexpr SferaColor fromArgb(std::uint32_t value)
    {
        return rgba(value >> 16u, value >> 8u, value, value >> 24u);
    }
    constexpr std::uint32_t red() const
    {
        return channels[0];
    }
    constexpr std::uint32_t green() const
    {
        return channels[1];
    }
    constexpr std::uint32_t blue() const
    {
        return channels[2];
    }
    constexpr std::uint32_t alpha() const
    {
        return channels[3];
    }
    constexpr std::uint32_t argb() const
    {
        return (alpha() << 24u) | (red() << 16u) | (green() << 8u) | blue();
    }
    constexpr SferaColor withAlpha(std::uint32_t value) const
    {
        return rgba(red(), green(), blue(), value);
    }
    constexpr SferaColor scaledAlpha(std::uint32_t factor, std::uint32_t divisor = 255u) const
    {
        return withAlpha(alpha() * factor / divisor);
    }
    constexpr SferaColor scaledRgb(std::uint32_t factor, std::uint32_t divisor) const
    {
        return rgba(red() * factor / divisor, green() * factor / divisor, blue() * factor / divisor, alpha());
    }
    constexpr std::uint16_t rgb565() const
    {
        return static_cast<std::uint16_t>(((red() >> 3u) << 11u) | ((green() >> 2u) << 5u) | (blue() >> 3u));
    }
    static constexpr SferaColor fromArgb4444(std::uint16_t value)
    {
        return rgba(((value >> 8u) & 15u) * 17u, ((value >> 4u) & 15u) * 17u, (value & 15u) * 17u, (value >> 12u) * 17u);
    }
    constexpr std::uint16_t argb4444() const
    {
        return static_cast<std::uint16_t>(((alpha() >> 4u) << 12u) | ((red() >> 4u) << 8u) | ((green() >> 4u) << 4u) | (blue() >> 4u));
    }
};
