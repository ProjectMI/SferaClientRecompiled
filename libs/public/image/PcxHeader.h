#pragma once

#include <cstddef>
#include <cstdint>

#include "binary/Binary.h"

struct PcxHeader;

struct PcxHeader
{
    static constexpr std::size_t encodedSize = 128;
    static constexpr std::uint8_t runMarker = 3u << 6;
    std::uint16_t minimum_y;
    std::uint16_t maximum_y;
    static PcxHeader decode(const std::uint8_t *bytes) noexcept
    {
        return {SferaBinary::readLittleEndian<std::uint16_t>(bytes + 6), SferaBinary::readLittleEndian<std::uint16_t>(bytes + 10)};
    }
};
