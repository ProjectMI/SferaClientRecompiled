#pragma once

#include <algorithm>
#include <bit>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <ios>
#include <istream>
#include <span>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

class SferaBinary;

class SferaBinary
{
  public:
    template <class T, std::size_t Extent> static std::span<T> range(std::span<T, Extent> bytes, std::size_t offset, std::size_t count)
    {
        if (offset > bytes.size() || count > bytes.size() - offset)
            throw std::out_of_range("Binary range exceeds its buffer");
        return bytes.subspan(offset, count);
    }
    static inline void copy(std::span<std::uint8_t> destination, std::span<const std::uint8_t> source)
    {
        if (source.size() > destination.size())
            throw std::out_of_range("Binary destination is too small");
        if (!source.empty())
            std::memmove(destination.data(), source.data(), source.size());
    }
    static inline bool read(std::istream &stream, std::span<std::uint8_t> destination)
    {
        if (!std::in_range<std::streamsize>(destination.size()))
            throw std::length_error("Binary read is too large");
        if (destination.empty())
            return true;
        std::string input(destination.size(), '\0');
        // Preserve untouched bytes even when the stream buffer writes a prefix and throws.
        // gcount() alone cannot describe that partial write on every exception path.
        std::memcpy(input.data(), destination.data(), destination.size());

        try
        {
            stream.read(input.data(), static_cast<std::streamsize>(input.size()));
        }
        catch (...)
        {
            commitRead(destination, input);
            throw;
        }
        commitRead(destination, input);
        return !stream.fail();
    }
    template <class T, class Byte>
        requires(std::is_integral_v<T> && !std::is_same_v<T, bool> && (std::is_same_v<Byte, std::uint8_t> || std::is_same_v<Byte, std::byte>))
    static T readLittleEndian(const Byte *bytes) noexcept
    {
        std::make_unsigned_t<T> value = 0;
        for (std::size_t index = sizeof(T); index != 0; --index)
        {
            if constexpr (sizeof(T) > 1)
                value <<= 8;
            if constexpr (std::is_same_v<Byte, std::byte>)
                value |= std::to_integer<unsigned int>(bytes[index - 1]);
            else
                value |= bytes[index - 1];
        }
        if constexpr (std::is_signed_v<T>)
            return std::bit_cast<T>(value);
        else
            return value;
    }
    static inline float floatFromBits(std::uint32_t bits) noexcept
    {
        float value{};
        std::memcpy(&value, &bits, sizeof(value));
        return value;
    }
    static inline std::uint32_t floatBits(float value) noexcept
    {
        std::uint32_t bits{};
        std::memcpy(&bits, &value, sizeof(bits));
        return bits;
    }
    template <class T, class Byte>
        requires(std::is_integral_v<T> && !std::is_same_v<T, bool> && (std::is_same_v<Byte, std::uint8_t> || std::is_same_v<Byte, std::byte>))
    static void writeLittleEndian(Byte *bytes, T value) noexcept
    {
        // std::make_unsigned_t<Integer> arithmetic preserves the complete two's-complement representation.
        std::make_unsigned_t<T> bits = value;
        for (std::size_t index = 0; index < sizeof(T); ++index)
        {
            if constexpr (std::is_same_v<Byte, std::byte>)
            {
                const std::uint8_t byte = bits & 255u;
                std::memcpy(bytes + index, &byte, 1u);
            }
            else
                bytes[index] = bits & 255u;
            if constexpr (sizeof(T) > 1)
                bits >>= 8;
        }
    }

  private:
    static void commitRead(std::span<std::uint8_t> destination, const std::string &input)
    {
        std::memcpy(destination.data(), input.data(), input.size());
    }
};

class SferaBinaryReadError;
class SferaBinaryReader;

class SferaBinaryReadError : public std::runtime_error
{
  public:
    using std::runtime_error::runtime_error;
};

class SferaBinaryReader
{
  public:
    explicit SferaBinaryReader(std::span<const std::uint8_t> bytes) : bytes_(bytes)
    {
    }
    std::span<const std::uint8_t> take(std::size_t size)
    {
        if (size > bytes_.size())
            throw SferaBinaryReadError("Truncated binary record");
        const auto result = bytes_.first(size);
        bytes_ = bytes_.subspan(size);
        return result;
    }
    std::size_t remaining() const noexcept
    {
        return bytes_.size();
    }
    std::string readTerminated(std::size_t capacity)
    {
        const auto field = bytes_.first(std::min(bytes_.size(), capacity));
        const auto end = std::find(field.begin(), field.end(), std::uint8_t{});
        if (end == field.end())
            throw SferaBinaryReadError("Unterminated binary string");
        const std::size_t count = static_cast<std::size_t>(end - field.begin());
        const auto value = take(count + 1);
        return std::string(value.begin(), value.end() - 1);
    }
    template <class T> T read()
    {
        if constexpr (std::is_same_v<T, float>)
            return SferaBinary::floatFromBits(read<std::uint32_t>());
        else
            return SferaBinary::readLittleEndian<T>(take(sizeof(T)).data());
    }

  private:
    std::span<const std::uint8_t> bytes_;
};
