#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>

struct SferaUiDeflateAlphabet;
struct SferaUiDeflateBits;
class SferaZlibTables;

struct SferaUiDeflateBits
{
    std::span<const std::uint8_t> input;
    std::size_t position = 0u;
    unsigned offset = 0u;
    std::uint32_t read(unsigned count);

    void align();
};

struct SferaUiDeflateAlphabet
{
    std::array<std::uint16_t, 16> counts{};
    std::array<std::uint16_t, 288> symbols{};
    explicit SferaUiDeflateAlphabet(std::span<const std::uint8_t> lengths, bool require_complete = false);

    std::uint32_t decode(SferaUiDeflateBits &bits) const;
};

class SferaZlibTables
{
  public:
    static constexpr std::array<std::uint8_t, 19> codeLengthOrder{16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};
};
