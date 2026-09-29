#include "script/MbcBitStream.h"
#include "script/MbcRuntime.h"
#include "binary/Binary.h"
#include "numeric/Numeric.h"

#include <algorithm>
#include <cmath>
#include <iterator>
#include <utility>

unsigned SferaMbcFieldHelper::mbc_field_minimum_bits(std::int8_t format)
{
    const auto value = std::abs(+format);
    if (value <= 32)
        return value;
    if (value == 'g')
        return 6u;
    if (value >= 'i' && value <= 'k')
        return 12u;
    if (value == 'l')
        return 8u;
    return 0u;
}

std::uint32_t SferaMbcFieldHelper::mbc_array_count(std::uint32_t encodedCount, std::int8_t countFormat, std::int8_t elementFormat, std::size_t remainingBits)
{
    if (countFormat != 'f')
        return encodedCount;
    // Some short server regions carry 0x40 even when 64 additional elements cannot be present.
    // Keep the full count when it fits; clear only that bit when the full count is impossible.
    const auto elementBits = SferaMbcFieldHelper::mbc_field_minimum_bits(elementFormat);
    if (elementBits == 0u || encodedCount <= remainingBits / elementBits)
        return encodedCount;
    const auto compactCount = encodedCount & 0x3Fu;
    return compactCount <= remainingBits / elementBits ? compactCount : encodedCount;
}

std::uint32_t SferaMbcBitStream::read(unsigned width)
{
    if (!valid_ || width > 32 || position_ > data_.size() * 8 || width > data_.size() * 8 - position_)
    {
        valid_ = false;
        return 0;
    }
    std::uint32_t value = 0;
    for (unsigned bit = 0; bit < width; ++bit, ++position_)
        value |= ((data_[position_ / 8] >> (position_ % 8)) & 1u) << bit;
    return value;
}

void SferaMbcBitStream::write(std::uint32_t value, unsigned width)
{
    if (!valid_ || output_ == nullptr || width > 32 || position_ > data_.size() * 8 || width > data_.size() * 8 - position_)
    {
        valid_ = false;
        return;
    }
    for (unsigned bit = 0; bit < width; ++bit, ++position_)
    {
        const std::uint8_t mask = 1u << (position_ % 8);
        auto &destination = output_[position_ / 8];
        destination = (destination & ~mask) | (((value >> bit) & 1u) ? mask : 0);
    }
}

void SferaMbcBitStream::append(std::span<const std::uint8_t> data, std::size_t bits)
{
    if (bits > data.size() * 8 || position_ > data_.size() * 8 || bits > data_.size() * 8 - position_)
    {
        valid_ = false;
        return;
    }
    SferaMbcBitStream source(data);
    while (bits != 0 && valid_)
    {
        const unsigned width = SferaNumeric::lowWord(std::min<std::size_t>(bits, 32));
        write(source.read(width), width);
        bits -= width;
    }
}

std::uint32_t SferaMbcBitStream::encodeCoordinate(int origin, float coordinate)
{
    const float reference = SferaNumeric::real32(origin);
    const double coordinate_value = coordinate;
    const float magnitude = SferaNumeric::real32(std::fabs(coordinate_value - reference));
    if (!std::isfinite(magnitude) || magnitude >= 120.0f)
        return UINT32_MAX;
    const float inverse = SferaNumeric::real32(1.0 / (magnitude + 40.0));
    constexpr float minimum_float = 0.0062500000931322575f;
    const double minimum = minimum_float;
    const auto normalized = (inverse - minimum) / (g_sfera_mbc_runtime.inverse_coordinate_scale - minimum);
    return SferaNumeric::truncatedWord(normalized * coordinateMagnitudeMask) | (coordinate < reference ? coordinateSignBit : 0u);
}

float SferaMbcBitStream::decodeCoordinate(int origin, std::uint32_t code)
{
    constexpr float minimum_float = 0.0062500000931322575f;
    const double minimum = minimum_float;
    const double encoded_magnitude = code & coordinateMagnitudeMask;
    const double magnitude_limit = coordinateMagnitudeMask;
    const float inverse = SferaNumeric::real32((g_sfera_mbc_runtime.inverse_coordinate_scale - minimum) * (encoded_magnitude / magnitude_limit) + minimum);
    float distance = SferaNumeric::real32(1.0 / inverse - 40.0);
    if (code & coordinateSignBit)
        distance = -distance;
    const double origin_value = origin;
    return SferaNumeric::real32(origin_value + distance);
}

std::uint32_t SferaMbcBitStream::readField(std::int8_t format, std::span<const int, 3> origin)
{
    if (format <= 32)
    {
        const int signed_width = format < 0 ? -format : format;
        const unsigned width = signed_width;
        const auto value = read(width);
        if (format < 0 && width < 32 && width != 0 && (value & (1u << (width - 1))))
            return value | (UINT32_MAX << width);
        return value;
    }
    if (format == 'g')
    {
        const bool negative = read(1) != 0;
        const auto width = variableIntegerWidths[read(2)];
        const auto magnitude = read(width);
        return negative ? 0u - magnitude : magnitude;
    }
    if (format >= 'i' && format <= 'k')
        return SferaBinary::floatBits(decodeCoordinate(origin[format - 'i'], read(12)));
    if (format == 'l')
        return SferaBinary::floatBits(read(8) * 0.02454369328916073f);
    valid_ = false;
    return 0;
}

bool SferaMbcBitStream::writeField(std::int8_t format, std::uint32_t value, std::span<const int, 3> origin)
{
    if (format <= 32)
    {
        const int signed_width = format < 0 ? -format : format;
        const unsigned width = signed_width;
        write(value, width);
    }
    else if (format == 'g')
    {
        const bool negative = SferaNumeric::signedWord(value) < 0;
        const auto magnitude = negative ? 0u - value : value;
        const int signedMagnitude = magnitude;
        const auto selector = signedMagnitude < 8 ? 0u : signedMagnitude < 128 ? 1u : signedMagnitude < 16384 ? 2u : 3u;
        write(negative, 1);
        write(selector, 2);
        write(magnitude, variableIntegerWidths[selector]);
    }
    else if (format >= 'i' && format <= 'k')
    {
        const auto code = encodeCoordinate(origin[format - 'i'], SferaBinary::floatFromBits(value));
        if (code == UINT32_MAX)
            return false;
        write(code, 12);
    }
    else if (format == 'l')
    {
        auto angle = SferaBinary::floatFromBits(value);
        if (!std::isfinite(angle) || angle < -1000.0f || angle > 1000.0f)
            angle = 0;
        while (angle < 0)
            angle = SferaNumeric::real32(angle + 6.2831854820251465);
        const float scaled = SferaNumeric::real32(angle * 40.7436637878418);
        write(SferaNumeric::truncatedWord(scaled) & 255u, 8);
    }
    return true;
}

bool SferaMbcBitStream::skipRegion(const SferaMbcRegionRecord &region)
{
    if (region.field_count < 0 || std::cmp_greater(region.field_count, std::size(region.formats)))
        return false;
    for (int field = 0; field < region.field_count && valid_; ++field)
    {
        auto format = std::abs(region.formats[field]);
        std::uint32_t count = 1;
        if (format == 'e' || format == 'f')
        {
            const std::int8_t countFormat = SferaNumeric::signedByte(SferaNumeric::lowByte(SferaNumeric::word(format)));
            const auto encodedCount = read(format == 'e' ? 4 : 8);
            if (!valid_ || ++field >= region.field_count)
                return false;
            count = SferaMbcFieldHelper::mbc_array_count(encodedCount, countFormat, region.formats[field], remaining());
            format = std::abs(region.formats[field]);
        }
        for (std::uint32_t element = 0; element < count && valid_; ++element)
        {
            if (format <= 32)
                read(format);
            else if (format >= 'i' && format <= 'k')
                read(12);
            else if (format == 'l')
                read(8);
            else if (format == 'g')
            {
                read(1);
                read(variableIntegerWidths[read(2)]);
            }
            else
                return false;
        }
    }
    return valid_;
}

