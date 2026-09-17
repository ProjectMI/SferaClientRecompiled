#include "sfera_vorbis.h"

#include <climits>
#include <cstdlib>
#include <cstring>
#include <limits>

#define STB_VORBIS_NO_PUSHDATA_API
#define STB_VORBIS_NO_STDIO
#define STB_VORBIS_MAX_CHANNELS 2
#include "third_party/stb_vorbis.c"

bool sferaDecodeVorbis(const std::uint8_t* data, std::size_t size, SferaVorbisPcm& output) noexcept {
    output = {};
    if (data == nullptr || size == 0u || size > static_cast<std::size_t>(INT_MAX)) return false;

    int channels = 0;
    int sample_rate = 0;
    short* samples = nullptr;
    const int frames = stb_vorbis_decode_memory(
        data,
        static_cast<int>(size),
        &channels,
        &sample_rate,
        &samples);

    if (frames <= 0 || samples == nullptr || channels <= 0 || channels > 2 || sample_rate <= 0) {
        std::free(samples);
        return false;
    }

    const std::size_t frame_count = static_cast<std::size_t>(frames);
    const std::size_t channel_count = static_cast<std::size_t>(channels);
    if (frame_count > std::numeric_limits<std::size_t>::max() / channel_count) {
        std::free(samples);
        return false;
    }

    const std::size_t sample_count = frame_count * channel_count;
    try {
        output.samples.assign(samples, samples + sample_count);
    } catch (...) {
        std::free(samples);
        return false;
    }
    std::free(samples);

    output.channels = static_cast<std::uint16_t>(channels);
    output.sample_rate = static_cast<std::uint32_t>(sample_rate);
    return true;
}
