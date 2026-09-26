#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>

class SferaMbcBitStream;
class SferaMbcFieldHelper;
struct SferaMbcRegionRecord;

class SferaMbcBitStream
{
    static constexpr std::array<unsigned, 4> variableIntegerWidths{3, 7, 14, 31};
    static constexpr unsigned coordinateMagnitudeBits = 11;
    static constexpr std::uint32_t coordinateSignBit = 1u << coordinateMagnitudeBits;
    static constexpr std::uint32_t coordinateMagnitudeMask = coordinateSignBit - 1u;
    std::span<const std::uint8_t> data_;
    std::uint8_t *output_ = nullptr;
    std::size_t position_ = 0;
    bool valid_ = true;

  public:
    explicit SferaMbcBitStream(std::span<const std::uint8_t> data, std::size_t position = 0) : data_(data), position_(position)
    {
    }
    explicit SferaMbcBitStream(std::span<std::uint8_t> data, std::size_t position = 0) : data_(data), output_(data.data()), position_(position)
    {
    }
    bool valid() const
    {
        return valid_;
    }
    std::size_t position() const
    {
        return position_;
    }
    std::size_t remaining() const
    {
        return position_ <= data_.size() * 8 ? data_.size() * 8 - position_ : 0;
    }
    std::uint32_t read(unsigned width);
    void write(std::uint32_t value, unsigned width);
    void append(std::span<const std::uint8_t> data, std::size_t bits);
    bool skipRegion(const SferaMbcRegionRecord &region);
    std::uint32_t readField(std::int8_t format, std::span<const int, 3> origin);
    bool writeField(std::int8_t format, std::uint32_t value, std::span<const int, 3> origin);
    static std::uint32_t encodeCoordinate(int origin, float coordinate);
    static float decodeCoordinate(int origin, std::uint32_t code);
};

class SferaMbcFieldHelper
{
  public:
    static std::uint32_t mbc_array_count(std::uint32_t encodedCount, std::int8_t countFormat, std::int8_t elementFormat, std::size_t remainingBits);

  private:
    static unsigned mbc_field_minimum_bits(std::int8_t format);
};
