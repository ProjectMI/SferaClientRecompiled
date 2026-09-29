#include <windows.h>
#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <string_view>

#include "numeric/Numeric.h"
#include "text/Text.h"

const std::array<char32_t, 256> &SferaText::unicodeCp1251()
{
    // Win32 remains authoritative for undefined code-page bytes; initialization is thread-safe.
    static const auto table = makeUnicodeTable();
    return table;
}

const std::array<std::uint8_t, 256> &SferaText::lowercaseCp1251()
{
    static const auto table = makeLowercaseTable();
    return table;
}

std::size_t SferaText::findInsensitive(std::string_view text, std::string_view needle)
{
    if (needle.empty())
        return std::string_view::npos;
    const auto found = std::search(text.begin(), text.end(), needle.begin(), needle.end(), &SferaText::equalAsciiByte);
    return found == text.end() ? std::string_view::npos : found - text.begin();
}

template <class Fold> int SferaText::compareText(std::string_view first, std::string_view second, Fold fold)
{
    const auto count = std::min(first.size(), second.size());
    for (std::size_t index = 0; index < count; ++index)
    {
        const auto difference = fold(SferaText::byteValue(first[index])) - fold(SferaText::byteValue(second[index]));
        if (difference != 0)
            return difference;
    }
    if (first.size() == second.size())
        return 0;
    return first.size() > count ? fold(SferaText::byteValue(first[count])) : -fold(SferaText::byteValue(second[count]));
}

int SferaText::compare(std::string_view first, std::string_view second)
{
    return compareText(first, second, &SferaText::unchangedByte);
}

int SferaText::compareInsensitive(std::string_view first, std::string_view second)
{
    return compareText(first, second, &SferaText::lowercaseByte);
}

std::string SferaText::encodeUri(std::string_view source, std::size_t capacity)
{
    if (capacity == 0)
        return {};
    constexpr std::string_view digits = "0123456789ABCDEF";
    std::string result;
    result.reserve(std::min(source.size(), capacity - 1));
    for (std::size_t index = 0; index < source.size(); ++index)
    {
        const auto value = SferaText::byteValue(source[index]);
        if (value == 0 || result.size() == capacity)
            break;
        const bool ordinary = (value >= 'a' && value <= 'z') || (value >= 'A' && value <= 'Z') || (value >= '0' && value <= '9') || value == '-' || value == '_' || value == '.' || value == '~';
        if (ordinary)
            result.append(source.substr(index, 1u));
        else
        {
            if (capacity - result.size() < 3)
                break;
            result.push_back('%');
            result.push_back(digits[value / 16]);
            result.push_back(digits[value % 16]);
        }
    }
    if (result.size() == capacity)
        result.pop_back();
    return result;
}

bool SferaText::matchesWildcard(std::string_view text, std::string_view pattern)
{
    std::size_t position = 0, token = 0, candidate = 0;
    auto star = std::string_view::npos;
    while (position < text.size())
    {
        if (token < pattern.size() && pattern[token] == '*')
        {
            star = ++token;
            candidate = position;
        }
        else if (token < pattern.size() && (pattern[token] == '?' || pattern[token] == text[position]))
        {
            ++token;
            ++position;
        }
        else if (star != std::string_view::npos)
        {
            token = star;
            position = ++candidate;
        }
        else
            return false;
    }
    while (token < pattern.size() && pattern[token] == '*')
        ++token;
    return token == pattern.size();
}

std::array<char32_t, 256> SferaText::makeUnicodeTable()
{
    std::array<char32_t, 256> result{};
    std::string input(1u, '\0');
    for (std::size_t byte = 0; byte < result.size(); ++byte)
    {
        std::as_writable_bytes(std::span(input)).front() = std::byte{SferaNumeric::lowByte(byte)};
        wchar_t character = 0;
        if (::MultiByteToWideChar(1251u, 0u, input.data(), 1, &character, 1) != 1)
            character = SferaNumeric::lowHalf(SferaNumeric::lowWord(byte));
        result[byte] = character;
    }
    return result;
}

std::array<std::uint8_t, 256> SferaText::makeLowercaseTable()
{
    const auto &unicode = unicodeCp1251();
    std::array<std::uint8_t, 256> result{};
    for (std::size_t byte = 0; byte < result.size(); ++byte)
    {
        auto character = unicode[byte];
        if (character >= U'A' && character <= U'Z')
            character += U'a' - U'A';
        else if (character >= U'\u0410' && character <= U'\u042f')
            character += U'\u0430' - U'\u0410';
        else if (character == U'\u0401')
            character = U'\u0451';
        const auto found = std::find(unicode.begin(), unicode.end(), character);
        result[byte] = SferaNumeric::lowByte(found == unicode.end() ? byte : found - unicode.begin());
    }
    return result;
}
