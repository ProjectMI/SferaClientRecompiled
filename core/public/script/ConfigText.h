#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <stdexcept>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

#include "binary/Binary.h"
#include "text/Text.h"

struct SferaConfigTextRuntime
{
    static constexpr std::size_t text_capacity = 2458176u;
    static constexpr std::size_t filename_capacity = 1024u;
    bool load(const std::string &filename);
    bool save(bool compressed = false) const;
    bool writeValue(std::string_view key, std::string_view value, bool quoted);
    bool writeValue(std::string_view key, std::int32_t value);
    bool writeValue(std::string_view key, float value);
    bool writeValue(std::string_view key, std::span<const std::byte> value, int size);
    bool writeBinary(std::string_view key, std::span<const std::byte> value, int size);
    static std::string encodeBinary(std::span<const std::byte> input);
    std::string filename;
    std::string text() const;
    std::size_t copyText(std::string_view source);
    void useText(std::span<std::byte> source);
    void releaseText() noexcept
    {
        if (auto *source = std::get_if<std::span<std::byte>>(&storage_))
            *source = {};
    }
    void clear(std::string path = {})
    {
        if (path.size() >= filename_capacity)
            throw std::length_error("Configuration filename is too long");
        storage_.emplace<std::string>();
        filename = std::move(path);
    }
    std::optional<std::string> find(std::string_view key) const;
    bool readInteger(std::string_view key, int &value) const;
    bool readFloat(std::string_view key, float &value) const;
    std::optional<std::string> readString(std::string_view key) const;
    bool readBinary(std::string_view key, std::span<std::byte> destination, std::size_t capacity = SIZE_MAX) const;
    std::size_t copyTo(std::span<std::byte> destination, std::size_t capacity = SIZE_MAX) const;
    bool readString(std::string_view key, std::span<std::byte> destination, std::size_t capacity = 10000000) const;
    template <class Number>
        requires (std::is_same_v<Number, int> || std::is_same_v<Number, float>)
    bool readNumber(std::string_view key, std::span<std::byte> destination, std::size_t capacity = 10000000) const
    {
        if (key.starts_with('*'))
            return readBinary(key, destination, capacity);
        const auto output = SferaBinary::range(destination, 0, sizeof(Number));
        Number value;
        std::memcpy(&value, output.data(), sizeof(value));
        const bool found = [this, key, &value]
        {
            if constexpr (std::is_same_v<Number, int>)
                return readInteger(key, value);
            else
                return readFloat(key, value);
        }();
        if (found)
            std::memcpy(output.data(), &value, sizeof(value));
        return found;
    }

  private:
    std::variant<std::string, std::span<std::byte>> storage_;
    static auto appendDecodedBits(std::vector<std::uint8_t> &decoded, std::span<std::byte> destination, unsigned &pending, unsigned &bits, unsigned value, unsigned count);
};

extern SferaConfigTextRuntime g_sfera_config_text_runtime;
