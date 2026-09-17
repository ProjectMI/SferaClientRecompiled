#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

struct SferaVorbisPcm {
    std::uint16_t channels = 0u;
    std::uint32_t sample_rate = 0u;
    std::vector<std::int16_t> samples;
};

bool sferaDecodeVorbis(const std::uint8_t* data, std::size_t size, SferaVorbisPcm& output) noexcept;
