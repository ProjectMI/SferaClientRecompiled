#include <cstring>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <climits>
#include <windows.h>
#include <algorithm>
#include <array>
#include <charconv>
#include <cstdio>
#include <optional>
#include <system_error>
#include <variant>
#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <string_view>

#include "numeric/Numeric.h"
#include "binary/Binary.h"
#include "text/TextBuffer.h"
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

template <class Value> void SferaText::scanTextStoreNumber(const Value &value, std::span<std::byte> reference, std::size_t characters)
{
    if constexpr (!std::is_same_v<std::remove_cvref_t<decltype(value)>, std::monostate>)
    {
        const auto bytes = SferaBinary::range(reference, 0, sizeof(value));
        std::memcpy(bytes.data(), &value, sizeof(value));
    }
}

template <class Value> void SferaText::scanTextStoreText(const Value &value, std::span<std::byte> reference, std::size_t characters)
{
    if constexpr (std::is_same_v<std::remove_cvref_t<decltype(value)>, std::string> || std::is_same_v<std::remove_cvref_t<decltype(value)>, std::wstring>)
    {
        const auto end = characters != 0 ? characters : value.find(std::remove_cvref_t<decltype(value.front())>{});
        if (end > value.size() || (characters == 0 && end == value.size()))
            throw std::out_of_range("Invalid scan result length");
        const auto count = characters != 0 ? end : end + 1;
        if constexpr (std::is_same_v<std::remove_cvref_t<decltype(value)>, std::string>)
        {
            const auto bytes = SferaBinary::range(reference, 0, count);
            if (count != 0)
                std::memmove(bytes.data(), value.data(), count);
        }
        else
        {
            const auto bytes = SferaBinary::range(reference, 0, count * sizeof(std::uint16_t));
            for (std::size_t character = 0; character < count; ++character)
                SferaBinary::writeLittleEndian<std::uint16_t>(bytes.data() + character * sizeof(std::uint16_t), value[character]);
        }
    }
}

template <bool Text, std::size_t Index, class... Values>
void SferaText::scanTextStoreVariant(const std::variant<Values...> &value, std::span<std::byte> reference, std::size_t characters)
{
    if constexpr (Index < sizeof...(Values))
    {
        if (const auto *selected = std::get_if<Index>(&value))
        {
            if constexpr (Text)
                scanTextStoreText(*selected, reference, characters);
            else
                scanTextStoreNumber(*selected, reference, characters);
            return;
        }
        scanTextStoreVariant<Text, Index + 1>(value, reference, characters);
    }
    else
    {
        throw std::bad_variant_access();
    }
}

template <class T> void SferaText::scanTextNumber(auto &references, std::size_t &output, auto &numbers, auto &destinations)
{
    auto &reference = references[output];
    T value{};
    const auto bytes = SferaBinary::range(reference, 0, sizeof(T));
    std::memcpy(&value, bytes.data(), sizeof(T));
    numbers[output] = value;
    destinations[output] = &std::get<T>(numbers[output]);
}

char SferaText::scanTextCharacter(const std::string &pattern, std::size_t position)
{
    return position < pattern.size() ? pattern[position] : '\0';
}

template <std::size_t Index>
auto SferaText::scanValues(const std::string &text, const std::string &normalized, const std::array<unsigned, 4> &capacities, const std::array<void *, 4> &destinations,
                                   std::array<int, 4> &completed, auto... arguments) -> int
{
    if constexpr (Index == 4)
        return ::sscanf_s(text.c_str(), normalized.c_str(), arguments...);
    else if (capacities[Index] != 0)
        return scanValues<Index + 1>(text, normalized, capacities, destinations, completed, arguments..., destinations[Index], capacities[Index], &completed[Index]);
    else
        return scanValues<Index + 1>(text, normalized, capacities, destinations, completed, arguments..., destinations[Index], &completed[Index]);
}

int SferaText::scan(const std::string &text, const std::string &pattern, std::span<const std::span<std::byte>> references)
{
    if (references.empty() || references.size() > 4)
        throw std::invalid_argument("Invalid scan destination count");
    std::array<std::variant<std::monostate, std::int8_t, std::uint8_t, std::int16_t, std::uint16_t, int, std::uint32_t, std::int64_t, std::uint64_t, float, double>, 4> numbers{};
    std::array<void *, 4> destinations{};
    std::array<unsigned, 4> capacities{};
    std::array<int, 4> completed;
    completed.fill(-1);
    std::array<std::size_t, 4> characterCounts{};
    std::array<std::variant<std::monostate, std::string, std::wstring>, 4> textOutputs{};
    const auto count = references.size();
    if (text.size() > INT_MAX)
    {
        throw std::invalid_argument("Scan input is too large");
    }
    std::string normalized;
    std::size_t output = 0;

    for (std::size_t token = 0; token < pattern.size(); ++token)
    {
        if (scanTextCharacter(pattern, token) != '%')
        {
            normalized += scanTextCharacter(pattern, token);
            continue;
        }
        const auto start = token++;
        if (scanTextCharacter(pattern, token) == '%')
        {
            normalized += "%%";
            continue;
        }
        const bool suppressed = scanTextCharacter(pattern, token) == '*';
        if (suppressed)
            ++token;
        const auto widthStart = token;
        while (scanTextCharacter(pattern, token) >= '0' && scanTextCharacter(pattern, token) <= '9')
            ++token;
        std::optional<unsigned> fieldWidth;
        if (token != widthStart)
        {
            unsigned width = 0;
            if (std::from_chars(pattern.data() + widthStart, pattern.data() + token, width).ec != std::errc{} || width == 0 || width > INT_MAX)
            {
                throw std::invalid_argument("Invalid scan field width");
            }
            fieldWidth = width;
        }
        normalized.append(pattern.substr(start, token - start));
        const auto lengthStart = token;
        while (scanTextCharacter(pattern, token) != '\0' && std::string_view("hljztLwI").find(scanTextCharacter(pattern, token)) != std::string_view::npos)
            if (scanTextCharacter(pattern, token++) == 'I')
                while (scanTextCharacter(pattern, token) >= '0' && scanTextCharacter(pattern, token) <= '9')
                    ++token;
        const auto length = pattern.substr(lengthStart, token - lengthStart);
        const auto conversion = scanTextCharacter(pattern, token);
        if (conversion == '\0')
        {
            throw std::invalid_argument("Incomplete scan format");
        }
        if (!suppressed && output >= count)
        {
            throw std::invalid_argument("Too few scan destinations");
        }
        if (std::string_view("cCsS[").find(conversion) != std::string_view::npos)
        {
            if (!length.empty() && length != "h" && length != "l" && length != "w")
            {
                throw std::invalid_argument("Invalid scan text modifier");
            }
            const auto conversionStart = token;
            if (conversion == '[')
            {
                if (scanTextCharacter(pattern, token + 1) == '^')
                    ++token;
                if (scanTextCharacter(pattern, token + 1) == ']')
                    ++token;
                do
                {
                    ++token;
                } while (scanTextCharacter(pattern, token) != '\0' && scanTextCharacter(pattern, token) != ']');
                if (scanTextCharacter(pattern, token) == '\0')
                {
                    throw std::invalid_argument("Incomplete scan character set");
                }
            }
            normalized.append(length);
            normalized.append(pattern.substr(conversionStart, token + 1 - conversionStart));
            if (!suppressed)
            {
                const auto &reference = references[output];
                const auto bytes = reference;
                const bool wide = length != "h" && (length == "l" || length == "w" || conversion == 'C' || conversion == 'S');
                const auto elementCount = bytes.size() / (wide ? sizeof(std::uint16_t) : 1u);
                if (elementCount == 0 || elementCount > UINT_MAX)
                {
                    throw std::invalid_argument("Invalid scan destination range");
                }
                capacities[output] = SferaNumeric::lowWord(elementCount);
                if (conversion == 'c' || conversion == 'C')
                    characterCounts[output] = fieldWidth.value_or(1u);
                if (wide)
                {
                    std::wstring value(elementCount, L'\0');
                    for (std::size_t i = 0; i < elementCount; ++i)
                    {
                        std::uint16_t unit;
                        std::memcpy(&unit, bytes.data() + i * sizeof(unit), sizeof(unit));
                        value[i] = unit;
                    }
                    textOutputs[output] = std::move(value);
                    destinations[output] = std::get<std::wstring>(textOutputs[output]).data();
                }
                else
                {
                    textOutputs[output] = SferaText::fromBytes(bytes);
                    destinations[output] = std::get<std::string>(textOutputs[output]).data();
                }
            }
        }
        else if (std::string_view("diouxXnp").find(conversion) != std::string_view::npos)
        {
            // Script integers and addresses remain 32-bit even for native-size scanf modifiers.
            const bool signedValue = conversion == 'd' || conversion == 'i' || conversion == 'n';
            const bool wide = conversion != 'p' && (length == "ll" || length == "I64" || length == "j");
            const bool byte = conversion != 'p' && length == "hh";
            const bool half = conversion != 'p' && length == "h";
            if (wide)
                normalized += "ll";
            else if (byte)
                normalized += "hh";
            else if (half)
                normalized += 'h';
            normalized += conversion == 'p' ? 'x' : conversion;
            if (!suppressed)
            {
                if (signedValue)
                {
                    if (wide)
                        scanTextNumber<std::int64_t>(references, output, numbers, destinations);
                    else if (byte)
                        scanTextNumber<std::int8_t>(references, output, numbers, destinations);
                    else if (half)
                        scanTextNumber<std::int16_t>(references, output, numbers, destinations);
                    else
                        scanTextNumber<int>(references, output, numbers, destinations);
                }
                else
                {
                    if (wide)
                        scanTextNumber<std::uint64_t>(references, output, numbers, destinations);
                    else if (byte)
                        scanTextNumber<std::uint8_t>(references, output, numbers, destinations);
                    else if (half)
                        scanTextNumber<std::uint16_t>(references, output, numbers, destinations);
                    else
                        scanTextNumber<std::uint32_t>(references, output, numbers, destinations);
                }
            }
        }
        else if (std::string_view("aAeEfFgG").find(conversion) != std::string_view::npos)
        {
            const bool wide = length == "l" || length == "L";
            if (wide)
                normalized += 'l';
            normalized += conversion;
            if (!suppressed)
            {
                if (wide)
                    scanTextNumber<double>(references, output, numbers, destinations);
                else
                    scanTextNumber<float>(references, output, numbers, destinations);
            }
        }
        else
        {
            throw std::invalid_argument("Unsupported scan conversion");
        }
        if (!suppressed)
        {
            normalized += "%n";
            ++output;
        }
    }

    const auto result = scanValues<0>(text, normalized, capacities, destinations, completed);
    for (std::size_t index = 0; index < output; ++index)
    {
        if (completed[index] < 0)
            continue;
        scanTextStoreVariant<false>(numbers[index], references[index], characterCounts[index]);
        scanTextStoreVariant<true>(textOutputs[index], references[index], characterCounts[index]);
    }
    return result;
}


std::span<std::byte> SferaText::readInteger(std::span<std::byte> source, std::span<std::byte> destination)
{
    const auto text = terminated(source);
    if (text.empty())
        return {};
    const bool negative = text.front() == '-';
    std::size_t cursor = negative ? 1 : 0;
    if (cursor == text.size() || text[cursor] < '0' || text[cursor] > '9')
        return {};
    std::uint32_t value = 0;
    do
    {
        value = value * 10u + byteValue(text[cursor++]) - '0';
    } while (cursor < text.size() && text[cursor] >= '0' && text[cursor] <= '9');
    value = negative ? 0u - value : value;
    const auto output = SferaBinary::range(destination, 0, sizeof(value));
    std::memcpy(output.data(), &value, sizeof(value));
    return source.subspan(cursor, text.size() + 1 - cursor);
}

std::span<std::byte> SferaText::skipSpaces(std::span<std::byte> source)
{
    const auto text = terminated(source);
    const auto first = text.find_first_not_of(" \t");
    const auto cursor = first == std::string_view::npos ? text.size() : first;
    return cursor == 0 ? std::span<std::byte>{} : source.subspan(cursor, text.size() + 1 - cursor);
}

std::span<std::byte> SferaText::skipBlankLine(std::span<std::byte> source)
{
    const auto text = terminated(source);
    const auto first = text.find_first_not_of(" \t");
    const auto cursor = first == std::string_view::npos ? text.size() : first;
    return text.substr(cursor).starts_with("\r\n") ? source.subspan(cursor + 2, text.size() - cursor - 1) : std::span<std::byte>{};
}

std::span<std::byte> SferaText::skipLine(std::span<std::byte> source)
{
    const auto text = terminated(source);
    const auto cursor = text.find_first_of("\r\n");
    return cursor != std::string_view::npos && text.substr(cursor).starts_with("\r\n")
               ? source.subspan(cursor + 2, text.size() - cursor - 1) : std::span<std::byte>{};
}
