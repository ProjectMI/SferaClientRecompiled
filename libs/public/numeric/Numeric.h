#pragma once

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <limits>
#include <type_traits>

class SferaNumeric;

class SferaNumeric
{
  public:
    template <class Enum>
        requires std::is_enum_v<Enum>
    static constexpr std::underlying_type_t<Enum> enumBits(Enum value) noexcept
    {
        return static_cast<std::underlying_type_t<Enum>>(value);
    }

    template <class Enum>
        requires std::is_enum_v<Enum>
    static inline Enum enumFromBits(std::underlying_type_t<Enum> value) noexcept
    {
        static_assert(sizeof(Enum) == sizeof(value));
        Enum result{};
        std::memcpy(&result, &value, sizeof(result));
        return result;
    }

    static inline std::uint32_t word(std::int32_t value) noexcept
    {
        std::uint32_t result{};
        std::memcpy(&result, &value, sizeof(result));
        return result;
    }

    template <class Integer>
        requires(std::is_integral_v<Integer> && !std::is_same_v<std::remove_cv_t<Integer>, bool>)
    static inline std::uint32_t lowWord(Integer value) noexcept
    {
        std::make_unsigned_t<Integer> bits{};
        if constexpr (std::is_signed_v<Integer>)
            std::memcpy(&bits, &value, sizeof(bits));
        else
            bits = value;
        return static_cast<std::uint32_t>(bits);
    }

    template <class Integer>
        requires(std::is_integral_v<Integer> && sizeof(Integer) <= sizeof(std::uint32_t) && !std::is_same_v<std::remove_cv_t<Integer>, bool>)
    static inline std::int32_t signedWord(Integer value) noexcept
    {
        const std::uint32_t bits = lowWord(value);
        std::int32_t result{};
        std::memcpy(&result, &bits, sizeof(result));
        return result;
    }

    template <class Integer>
        requires(std::is_integral_v<Integer> && sizeof(Integer) > sizeof(std::uint32_t) && sizeof(Integer) <= sizeof(std::uint64_t) && !std::is_same_v<std::remove_cv_t<Integer>, bool>)
    static inline std::int64_t signedWord(Integer value) noexcept
    {
        std::make_unsigned_t<Integer> bits{};
        if constexpr (std::is_signed_v<Integer>)
            std::memcpy(&bits, &value, sizeof(bits));
        else
            bits = value;
        std::int64_t result{};
        std::memcpy(&result, &bits, sizeof(result));
        return result;
    }

    static inline std::uint16_t lowHalf(std::uint32_t value) noexcept
    {
        return static_cast<std::uint16_t>(value);
    }

    template <class Integer>
        requires(std::is_integral_v<Integer> && !std::is_same_v<std::remove_cv_t<Integer>, bool>)
    static constexpr std::uint8_t lowByte(Integer value) noexcept
    {
        return static_cast<std::uint8_t>(value);
    }

    static inline std::uint32_t magnitude(std::int32_t value) noexcept
    {
        const auto bits = word(value);
        return value < 0 ? 0u - bits : bits;
    }

    static inline std::int16_t signedHalf(std::uint16_t value) noexcept
    {
        std::int16_t result{};
        std::memcpy(&result, &value, sizeof(result));
        return result;
    }

    static inline std::int8_t signedByte(std::uint8_t value) noexcept
    {
        std::int8_t result{};
        std::memcpy(&result, &value, sizeof(result));
        return result;
    }

    static inline std::int8_t signedByte(std::byte value) noexcept
    {
        std::int8_t result{};
        std::memcpy(&result, &value, sizeof(result));
        return result;
    }

    static inline int truncateInt(double value) noexcept
    {
        constexpr double minimum = std::numeric_limits<int>::min();
        constexpr double maximum_exclusive = std::numeric_limits<int>::max();
        if (!std::isfinite(value) || value < minimum || value >= maximum_exclusive + 1.0)
            return std::numeric_limits<int>::min();
        return static_cast<int>(value);
    }

    static inline std::int64_t truncateInt64(double value) noexcept
    {
        if (!std::isfinite(value) || value < -9223372036854775808.0 || value >= 9223372036854775808.0)
            return std::numeric_limits<std::int64_t>::min();
        return static_cast<std::int64_t>(value);
    }

    static inline std::uint32_t truncatedWord(double value) noexcept
    {
        return lowWord(truncateInt64(value));
    }

    static inline float real32(double value) noexcept
    {
        if (std::isnan(value))
            return std::numeric_limits<float>::quiet_NaN();
        if (value > std::numeric_limits<float>::max())
            return std::numeric_limits<float>::infinity();
        if (value < -std::numeric_limits<float>::max())
            return -std::numeric_limits<float>::infinity();
        return static_cast<float>(value);
    }

    template <class Integer>
        requires(std::is_integral_v<Integer> && !std::is_same_v<std::remove_cv_t<Integer>, bool>)
    static inline float real32(Integer value) noexcept
    {
        return static_cast<float>(value);
    }
};
