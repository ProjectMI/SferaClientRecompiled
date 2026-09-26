#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <span>
#include <stdexcept>
#include <string_view>

#include "text/Text.h"

class SferaTextBuffer;

class SferaTextBuffer
{
  public:
    explicit SferaTextBuffer(std::span<std::uint8_t> bytes) noexcept : bytes_(bytes)
    {
    }
    std::size_t size() const noexcept
    {
        return bytes_.size();
    }
    bool empty() const noexcept
    {
        return bytes_.empty();
    }
    SferaTextBuffer limited(std::size_t capacity) const noexcept
    {
        return SferaTextBuffer(bytes_.first(std::min(size(), capacity)));
    }
    std::size_t length() const
    {
        return SferaText::length(bytes_);
    }
    std::size_t write(std::string_view source) const
    {
        if (empty())
            return 0;
        const auto count = std::min(source.size(), size() - 1);
        if (count != 0)
            std::memmove(bytes_.data(), source.data(), count);
        bytes_[count] = 0;
        return count;
    }
    void assign(std::string_view source) const
    {
        if (source.size() >= size())
            throw std::out_of_range("Text destination is too small");
        write(source);
    }
    void append(std::string_view source) const
    {
        const auto count = length();
        SferaTextBuffer(bytes_.subspan(count)).assign(source);
    }
    // Bounded formatting leaves untouched padding except for the final sentinel.
    std::size_t writeBounded(std::string_view source, std::size_t capacity) const
    {
        if (capacity == 0)
            return 0;
        if (capacity > size())
            throw std::out_of_range("Bounded text destination is too small");
        const auto copied = limited(capacity).write(source);
        bytes_[capacity - 1] = 0;
        return copied;
    }
    // MBC bounded copies write count bytes of payload/padding and one final NUL.
    std::size_t writePadded(std::string_view source, std::size_t count) const
    {
        if (count >= size())
            throw std::out_of_range("Padded text destination is too small");
        const auto copied = limited(count + 1).write(source);
        std::ranges::fill(bytes_.subspan(copied, count + 1 - copied), std::uint8_t{});
        return copied;
    }

  private:
    std::span<std::uint8_t> bytes_;
};
