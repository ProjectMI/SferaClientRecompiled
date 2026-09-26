#pragma once

#include <windows.h>
#include <cstddef>
#include <cstdint>
#include <mmreg.h>
#include <string>
#include <vector>

struct SferaDecodedAudio;
class SferaSoundAudioDecoder;
struct SferaVorbisPcm;

struct SferaVorbisPcm
{
    std::uint16_t channels = 0u;
    std::uint32_t sample_rate = 0u;
    std::vector<std::int16_t> samples;
};

class SferaSoundAudioDecoder
{
  public:
    static bool decodeAudioFile(const std::string &filename, SferaDecodedAudio &output);

  private:
    static std::uint16_t readU16(const std::uint8_t *value);
    static std::uint32_t readU32(const std::uint8_t *value);
    static bool readBinaryFile(const std::string &filename, std::vector<std::uint8_t> &bytes);
    static bool decodePcmWave(const std::vector<std::uint8_t> &bytes, SferaDecodedAudio &output);
    static bool decodeVorbis(const std::vector<std::uint8_t> &bytes, SferaDecodedAudio &output);
    static bool decodeVorbisMemory(const std::uint8_t *data, std::size_t size, SferaVorbisPcm &output) noexcept;
};

struct SferaDecodedAudio
{
    WAVEFORMATEX format{};
    std::vector<std::uint8_t> pcm;
};
