#pragma once

#include <algorithm>
#include <array>
#include <cctype>
#include <cerrno>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <istream>
#include <limits>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>

#include "numeric/Numeric.h"

class SferaText;
struct SferaTextHash;

struct SferaTextHash : std::equal_to<>
{
    std::size_t operator()(std::string_view value) const noexcept
    {
        return std::hash<std::string_view>{}(value);
    }
};

class SferaText
{
  public:
    template <class Mapping> static void transformBytes(std::string &text, Mapping mapping)
    {
        for (auto &byte : std::as_writable_bytes(std::span(text)))
        {
            const std::uint8_t mapped = SferaNumeric::lowByte(mapping(std::to_integer<std::uint8_t>(byte)));
            std::memcpy(&byte, &mapped, sizeof(mapped));
        }
    }
    static inline void lowercaseLocale(std::string &text)
    {
        transformBytes(text, &SferaText::lowercaseByte);
    }

    static inline std::uint8_t byteValue(char value) noexcept
    {
        std::uint8_t result{};
        std::memcpy(&result, &value, sizeof(result));
        return result;
    }
    static constexpr std::uint8_t asciiFold(std::uint8_t byte) noexcept
    {
        if (byte < 'A' || byte > 'Z')
            return byte;
        const std::uint8_t folded = byte + ('a' - 'A');
        return folded;
    }
    static inline bool isSpace(char byte) noexcept
    {
        return std::isspace(byteValue(byte)) != 0;
    }
    static inline bool asciiEqual(std::string_view a, std::string_view b) noexcept
    {
        if (a.size() != b.size())
            return false;
        const auto first = std::as_bytes(std::span(a));
        const auto second = std::as_bytes(std::span(b));
        for (std::size_t i = 0; i < first.size(); ++i)
            if (asciiFold(std::to_integer<std::uint8_t>(first[i])) != asciiFold(std::to_integer<std::uint8_t>(second[i])))
                return false;
        return true;
    }
    static const std::array<char32_t, 256> &unicodeCp1251();
    static const std::array<std::uint8_t, 256> &lowercaseCp1251();
    static std::string resourceKey(std::string_view name)
    {
        std::string result(name);
        transformBytes(result, &SferaText::lowercaseResourceByte);
        return result;
    }
    static std::size_t findInsensitive(std::string_view text, std::string_view needle);
    static std::string_view fileName(std::string_view path)
    {
        const auto separator = path.find_last_of('\\');
        return path.substr(separator == std::string_view::npos ? 0 : separator + 1);
    }
    static std::string encodeUri(std::string_view source, std::size_t capacity = std::numeric_limits<std::size_t>::max());
    static bool matchesWildcard(std::string_view text, std::string_view pattern);
    static int compare(std::string_view first, std::string_view second);
    static int compareInsensitive(std::string_view first, std::string_view second);
    // Byte-backed fields are decoded into owned text. No view aliases binary memory.
    // This preserves every code unit of the client's single-byte encoding, including NUL.
    static inline std::string fromBytes(std::span<const std::byte> bytes)
    {
        std::string text(bytes.size(), '\0');
        if (!bytes.empty())
            std::memcpy(text.data(), bytes.data(), bytes.size());
        return text;
    }
    static inline std::string fromBytes(std::span<const std::uint8_t> bytes)
    {
        return fromBytes(std::as_bytes(bytes));
    }
    static inline std::size_t length(std::span<const std::uint8_t> bytes, std::size_t limit = std::numeric_limits<std::size_t>::max())
    {
        if (limit == 0)
            return 0;
        const auto field = bytes.first(std::min(bytes.size(), limit));
        const auto end = std::find(field.begin(), field.end(), std::uint8_t{});
        if (end == field.end() && limit > bytes.size())
            throw std::out_of_range("Unterminated text buffer");
        return static_cast<std::size_t>(end - field.begin());
    }
    static inline std::string prefix(std::span<const std::uint8_t> bytes, std::size_t limit)
    {
        return fromBytes(bytes.first(length(bytes, limit)));
    }
    static inline std::string terminated(std::span<const std::uint8_t> bytes)
    {
        return prefix(bytes, std::numeric_limits<std::size_t>::max());
    }

    // Mutable text exists only at a binary boundary. Every write reserves a terminator;
    // no raw character pointer or unchecked element access escapes this interface.

    static inline std::optional<std::string> readTerminated(std::istream &stream, std::size_t capacity)
    {
        std::string value;
        for (std::size_t index = 0; index < capacity; ++index)
        {
            const auto input = stream.get();
            if (std::istream::traits_type::eq_int_type(input, std::istream::traits_type::eof()))
                return std::nullopt;
            const auto character = std::istream::traits_type::to_char_type(input);
            if (character == '\0')
                return value;
            value.push_back(character);
        }
        return std::nullopt;
    }

    // Numeric tokens historically used the CRT prefix grammar. Keep that behavior
    // without using exceptions for routine parse failures: effect/UI definitions
    // intentionally probe optional values and missing tokens are not exceptional.
    template <class Number> static bool readNumber(std::string_view text, Number &output)
    {
        static_assert(std::is_same_v<Number, int> || std::is_same_v<Number, float>);
        const std::string input(text);
        char *end = nullptr;
        if constexpr (std::is_same_v<Number, float>)
        {
            const float value = std::strtof(input.c_str(), &end);
            if (end == input.c_str())
                return false;
            output = value;
            return true;
        }
        else
        {
            errno = 0;
            const long value = std::strtol(input.c_str(), &end, 10);
            if (end == input.c_str() || errno == ERANGE || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
                return false;
            output = value;
            return true;
        }
    }
    static inline std::size_t configValueOffset(std::string_view text, std::string_view key)
    {
        for (std::size_t line = 0; line < text.size();)
        {
            auto end = line;
            while (end < text.size() && text[end] != ' ' && text[end] != '\t' && text[end] != '\r' && text[end] != '\0')
                ++end;
            if (text.substr(line, end - line) == key)
            {
                while (end < text.size() && (text[end] == ' ' || text[end] == '\t'))
                    ++end;
                return end;
            }
            while (line < text.size() && text[line] != '\n' && text[line] != '\0')
                ++line;
            if (line == text.size() || text[line] == '\0')
                break;
            ++line;
        }
        return std::string_view::npos;
    }
    static inline bool replaceConfigValue(std::string &text, std::string_view key, std::string_view value, bool quoted, std::size_t capacity)
    {
        const std::string name(key), replacement(value);
        std::string next(text);
        const auto offset = configValueOffset(next, name);
        if (offset != std::string::npos)
        {
            const bool preserveQuotes = offset < next.size() && next[offset] == '"';
            const auto begin = offset + (preserveQuotes ? 1u : 0u);
            const auto end = next.find_first_of(preserveQuotes ? "\"\r\0" : "\r\0", begin, preserveQuotes ? 3u : 2u);
            next.replace(begin, (end == std::string::npos ? next.size() : end) - begin, replacement);
        }
        else
        {
            if (!next.empty())
                next += "\r\n";
            next += name;
            next += '\t';
            if (quoted)
                next += '"';
            next += replacement;
            if (quoted)
                next += '"';
        }
        if (next.size() >= capacity)
            return false;
        text.swap(next);
        return true;
    }

  private:
    static int lowercaseByte(std::uint8_t value)
    {
        return std::tolower(value);
    }
    template <class Fold> static int compareText(std::string_view first, std::string_view second, Fold fold);

    static std::array<char32_t, 256> makeUnicodeTable();
    static std::array<std::uint8_t, 256> makeLowercaseTable();
    static std::uint8_t lowercaseResourceByte(std::uint8_t byte)
    {
        return lowercaseCp1251()[byte];
    }
    static bool equalAsciiByte(std::uint8_t first, std::uint8_t second)
    {
        return asciiFold(first) == asciiFold(second);
    }
    static std::uint8_t unchangedByte(std::uint8_t value)
    {
        return value;
    }
};
