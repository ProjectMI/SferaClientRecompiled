#include <algorithm>
#include <array>
#include <charconv>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iterator>
#include <limits>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

#include "binary/Binary.h"
#include "numeric/Numeric.h"
#include "script/MbcBitStream.h"
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"
#include "script/MbcValue.h"
#include "text/HyperText.h"
#include "text/Text.h"
#include "text/TextBuffer.h"

void SferaMbcRuntime::writeScriptLog()
{
    if (argument_cursor >= argument_end)
    {
        reportError("Too few parameters");
        return;
    }
    const auto type = g_sfera_mbc_runtime.values[argument_cursor].type;
    const bool textValue = (type & 15u) != 0;
    const bool realValue = !textValue && type == SferaMbcValueTypeReal;
    const auto integer = realValue ? 0 : nextInteger();
    if (realValue)
        nextReal();
    if (execution_failed)
        return;
    if (textValue)
        (void)textAt(integer);
    if (argument_count == 2)
        nextInteger();
}

auto SferaMbcRuntime::formatArgumentsInvalid()
{
    reportError("Invalid format arguments");
}

auto SferaMbcRuntime::formatArgumentsWord(std::size_t &next, const std::vector<std::variant<int, double, SferaSliceReference32>> &arguments) -> std::uint32_t
{
    if (next >= arguments.size())
    {
        formatArgumentsInvalid();
        return 0;
    }
    const auto &value = arguments[next++];
    if (const auto *integer = std::get_if<int>(&value))
        return SferaNumeric::word(*integer);
    if (const auto *pointer = std::get_if<SferaSliceReference32>(&value))
        return pointer->base;
    formatArgumentsInvalid();
    return 0;
}

auto SferaMbcRuntime::formatArgumentsPointer(std::size_t &next, const std::vector<std::variant<int, double, SferaSliceReference32>> &arguments) -> SferaSliceReference32
{
    if (next >= arguments.size())
    {
        formatArgumentsInvalid();
        return {};
    }
    const auto &value = arguments[next++];
    if (const auto *slice = std::get_if<SferaSliceReference32>(&value))
        return *slice;
    if (const auto *integer = std::get_if<int>(&value))
        return {SferaNumeric::word(*integer), 0, 0};
    formatArgumentsInvalid();
    return {};
}

auto SferaMbcRuntime::formatArgumentsAppend(std::size_t limit, std::string &result, const std::string &specifier, auto value)
{
    const auto required = std::snprintf(nullptr, 0, specifier.c_str(), value);
    if (required < 0)
    {
        formatArgumentsInvalid();
        return;
    }
    const std::size_t required_size = required;
    const auto count = std::min(required_size, limit - result.size());
    if (count == 0)
        return;
    const auto offset = result.size();
    result.resize(offset + count + 1);
    std::snprintf(result.data() + offset, count + 1, specifier.c_str(), value);
    result.resize(offset + count);
}

auto SferaMbcRuntime::formatArgumentsCharacterAt(std::string_view pattern, std::size_t position)
{
    return position < pattern.size() ? pattern[position] : '\0';
}

std::string SferaMbcRuntime::formatArguments(std::string_view pattern, std::size_t limit)
{
    std::vector<std::variant<int, double, SferaSliceReference32>> arguments;
    while (argument_count > 0)
    {
        if (argument_cursor >= argument_end)
        {
            reportError("Too few parameters");
            break;
        }
        const auto &argument = g_sfera_mbc_runtime.values[argument_cursor];
        if (argument.isPointer())
        {
            arguments.emplace_back(argument.value);
            ++argument_cursor;
        }
        else if (argument.type == SferaMbcValueTypeByte || argument.type == SferaMbcValueTypeInteger)
            arguments.emplace_back(nextInteger());
        else
        {
            const double value = nextReal();
            arguments.emplace_back(value);
        }
        --argument_count;
    }
    ++value_stack_size;
    if (execution_failed)
        return {};
    std::string result;
    std::size_t next = 0;

    for (std::size_t cursor = 0; cursor < pattern.size() && !execution_failed;)
    {
        if (formatArgumentsCharacterAt(pattern, cursor) != '%')
        {
            if (result.size() < limit)
                result.push_back(formatArgumentsCharacterAt(pattern, cursor));
            ++cursor;
            continue;
        }
        ++cursor;
        if (formatArgumentsCharacterAt(pattern, cursor) == '%')
        {
            if (result.size() < limit)
                result.push_back('%');
            ++cursor;
            continue;
        }
        std::string specifier = "%";
        while (formatArgumentsCharacterAt(pattern, cursor) != '\0' && std::string_view("-+ #0").find(formatArgumentsCharacterAt(pattern, cursor)) != std::string_view::npos)
            specifier.push_back(formatArgumentsCharacterAt(pattern, cursor++));
        if (formatArgumentsCharacterAt(pattern, cursor) == '*')
        {
            ++cursor;
            const int width = formatArgumentsWord(next, arguments);
            if (width < 0)
                specifier.push_back('-');
            specifier += std::to_string(SferaNumeric::magnitude(width));
        }
        else
            while (formatArgumentsCharacterAt(pattern, cursor) >= '0' && formatArgumentsCharacterAt(pattern, cursor) <= '9')
                specifier.push_back(formatArgumentsCharacterAt(pattern, cursor++));
        std::optional<std::size_t> precision;
        if (formatArgumentsCharacterAt(pattern, cursor) == '.')
        {
            ++cursor;
            if (formatArgumentsCharacterAt(pattern, cursor) == '*')
            {
                ++cursor;
                const int value = formatArgumentsWord(next, arguments);
                if (value >= 0)
                {
                    precision = value;
                    specifier += "." + std::to_string(value);
                }
            }
            else
            {
                specifier.push_back('.');
                const auto first = cursor;
                while (formatArgumentsCharacterAt(pattern, cursor) >= '0' && formatArgumentsCharacterAt(pattern, cursor) <= '9')
                    specifier.push_back(formatArgumentsCharacterAt(pattern, cursor++));
                std::size_t value = 0;
                if (cursor != first && std::from_chars(pattern.data() + first, pattern.data() + cursor, value).ec != std::errc{})
                {
                    formatArgumentsInvalid();
                    break;
                }
                precision = value;
            }
        }
        std::string length;
        if (formatArgumentsCharacterAt(pattern, cursor) == 'h' || formatArgumentsCharacterAt(pattern, cursor) == 'l')
        {
            length.push_back(formatArgumentsCharacterAt(pattern, cursor++));
            if (formatArgumentsCharacterAt(pattern, cursor) == length.front())
                length.push_back(formatArgumentsCharacterAt(pattern, cursor++));
        }
        else if (formatArgumentsCharacterAt(pattern, cursor) == 'I')
        {
            ++cursor;
            if (formatArgumentsCharacterAt(pattern, cursor) == '6' && formatArgumentsCharacterAt(pattern, cursor + 1) == '4')
            {
                length = "ll";
                cursor += 2;
            }
            else if (formatArgumentsCharacterAt(pattern, cursor) == '3' && formatArgumentsCharacterAt(pattern, cursor + 1) == '2')
                cursor += 2;
        }
        else if (formatArgumentsCharacterAt(pattern, cursor) != '\0' && std::string_view("jztLw").find(formatArgumentsCharacterAt(pattern, cursor)) != std::string_view::npos)
            length.push_back(formatArgumentsCharacterAt(pattern, cursor++));
        if (formatArgumentsCharacterAt(pattern, cursor) == '\0')
        {
            formatArgumentsInvalid();
            break;
        }
        const auto conversion = formatArgumentsCharacterAt(pattern, cursor++);
        if (std::string_view("diuoxX").find(conversion) != std::string_view::npos)
        {
            const bool wide = length == "ll" || length == "j";
            const auto low = formatArgumentsWord(next, arguments);
            std::uint64_t bits = low;
            if (wide)
            {
                const std::uint64_t high = formatArgumentsWord(next, arguments);
                bits |= high << 32;
            }
            if (execution_failed)
                break;
            if (wide)
            {
                specifier += "ll";
                specifier.push_back(conversion);
                if (conversion == 'd' || conversion == 'i')
                    formatArgumentsAppend(limit, result, specifier, SferaNumeric::signedWord(bits));
                else
                    formatArgumentsAppend(limit, result, specifier, bits);
            }
            else
            {
                if (length == "h" || length == "hh")
                    specifier += length;
                specifier.push_back(conversion);
                if (conversion == 'd' || conversion == 'i')
                    formatArgumentsAppend(limit, result, specifier, SferaNumeric::signedWord(low));
                else
                    formatArgumentsAppend(limit, result, specifier, low);
            }
        }
        else if (std::string_view("aAeEfFgG").find(conversion) != std::string_view::npos)
        {
            if (next >= arguments.size() || !std::holds_alternative<double>(arguments[next]))
            {
                formatArgumentsInvalid();
                break;
            }
            specifier.push_back(conversion);
            formatArgumentsAppend(limit, result, specifier, std::get<double>(arguments[next++]));
        }
        else if (conversion == 's' || conversion == 'S')
        {
            const auto reference = formatArgumentsPointer(next, arguments);
            const auto address = reference.base;
            if (execution_failed)
                break;
            if (length == "l" || length == "w" || (conversion == 'S' && length != "h"))
            {
                specifier += "ls";
                std::wstring value;
                if (address != 0)
                {
                    const auto bytes = memoryRange(reference.base);
                    SferaBinaryReader reader(bytes);
                    while (!precision || value.size() < *precision)
                    {
                        const auto character = reader.read<std::uint16_t>();
                        if (character == 0)
                            break;
                        value.push_back(character);
                    }
                }
                else
                    value = L"(null)";
                formatArgumentsAppend(limit, result, specifier, value.c_str());
            }
            else
            {
                specifier.push_back('s');
                const auto text = address != 0 ? (precision ? textIn(reference, *precision) : textIn(reference)) : std::string("(null)");
                // textIn checked either the terminator or the same precision passed to the CRT.
                formatArgumentsAppend(limit, result, specifier, text.empty() ? "" : text.data());
            }
        }
        else if (conversion == 'c' || conversion == 'C')
        {
            if (length == "l" || length == "w" || (conversion == 'C' && length != "h"))
                specifier.push_back('l');
            specifier.push_back('c');
            const auto character = formatArgumentsWord(next, arguments);
            if (!execution_failed)
                formatArgumentsAppend(limit, result, specifier, SferaNumeric::signedWord(character));
        }
        else if (conversion == 'p')
        {
            specifier.push_back('p');
            const auto address = formatArgumentsWord(next, arguments);
            if (!execution_failed)
                formatArgumentsAppend(limit, result, specifier, address != 0 ? static_cast<const void *>(memoryAt(address, 1)) : nullptr);
        }
        else
            formatArgumentsInvalid();
    }
    return result;
}

void SferaMbcRuntime::formatText(bool bounded)
{
    const std::uint32_t required = bounded ? 3 : 2;
    if (std::cmp_less(argument_count, required))
    {
        reportError(bounded ? "Wrong number of parameters: ffsnprintf" : "Wrong number of parameters: ffsprintf");
        return;
    }
    const auto destination = nextAddress();
    const auto capacity = bounded ? nextWord() : UINT32_MAX;
    const auto pattern = nextAddress();
    if (execution_failed)
        return;
    argument_count -= required;
    std::optional<SferaTextBuffer> output;
    std::size_t limit = 0;
    if (capacity != 0)
    {
        output.emplace(textBufferAt(destination.base));
        if (bounded && capacity > output->size())
            throw std::out_of_range("Formatted script string exceeds destination");
        limit = bounded ? capacity - 1 : output->size();
    }
    const auto value = formatArguments(textIn(pattern), limit);
    if (execution_failed || !output)
        return;
    if (bounded)
        output->writeBounded(value, capacity);
    else
        output->assign(value);
}

void SferaMbcRuntime::writeFormattedLog(bool named)
{
    if (argument_count >= 1 && argument_cursor < argument_end)
    {
        const auto type = g_sfera_mbc_runtime.values[argument_cursor].type;
        if (type == SferaMbcValueTypeByte || type == SferaMbcValueTypeInteger)
        {
            nextInteger();
            --argument_count;
        }
    }
    if (argument_count < (named ? 2 : 1))
    {
        reportError(named ? "Invalid parameter list: ffflogf()" : "Invalid parameter list: fflogf()");
        return;
    }
    if (named)
    {
        const auto filename = nextInteger();
        --argument_count;
        if (!execution_failed)
            (void)textAt(filename);
    }
    const auto patternOffset = nextInteger();
    --argument_count;
    const auto pattern = textAt(patternOffset);
    if (execution_failed)
        return;
    (void)formatArguments(pattern, named ? std::numeric_limits<std::size_t>::max() : 4095u);
}

auto SferaMbcRuntime::parseTextDigit(std::uint8_t value)
{
    return value >= '0' && value <= '9';
}

auto SferaMbcRuntime::parseTextLetter(std::uint8_t value)
{
    return (value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z') || value == '_';
}

auto SferaMbcRuntime::parseTextSpace(std::uint8_t value)
{
    return value == ' ' || value == '\t';
}

void SferaMbcRuntime::parseText()
{
    const auto operation = nextInteger();
    if (operation < 0 || operation > 7)
    {
        reportError("ffparse(). Invalid parsing type");
        return;
    }
    const auto destination = operation < 2 ? nextSlice() : SferaSliceReference32{};
    const auto source = nextSlice();
    const auto limit = nextSlice();
    if (execution_failed)
        return;
    if (source.base == 0 || (operation < 2 && destination.base == 0))
    {
        reportError("poppointerup(): unexpected NULL-pointer fetched");
        return;
    }
    const auto text = textIn(source);
    const auto end = limit.base != 0 && limit.base >= source.base ? std::min<std::size_t>(text.size(), limit.base - source.base) : text.size();
    std::size_t cursor = 0;
    std::optional<std::size_t> result;

    if (cursor < end)
    {
        if (operation < 2)
        {
            const bool negative = text[cursor] == '-';
            if (negative)
                ++cursor;
            if (cursor < end && parseTextDigit(text[cursor]))
            {
                if (!destination.contains(sizeof(std::uint32_t)))
                {
                    auto invalid = destination;
                    invalid.diagnoseRange(sizeof(std::uint32_t));
                    return;
                }
                if (operation == 0)
                {
                    std::uint32_t value = 0;
                    do
                    {
                        value = value * 10u + SferaText::byteValue(text[cursor++]) - '0';
                    } while (cursor < end && parseTextDigit(text[cursor]));
                    writeMemory(destination.base, negative ? 0u - value : value);
                }
                else
                {
                    float value = 0.0f;
                    do
                    {
                        value = SferaNumeric::real32(value * 10.0 + (text[cursor++] - '0'));
                    } while (cursor < end && parseTextDigit(text[cursor]));
                    if (cursor < end && text[cursor] == '.')
                    {
                        ++cursor;
                        float scale = 0.1f;
                        while (cursor < end && parseTextDigit(text[cursor]))
                        {
                            const double digit_value = text[cursor++] - '0';
                            value = SferaNumeric::real32(digit_value * scale + value);
                            scale = SferaNumeric::real32(scale / 10.0);
                        }
                    }
                    writeMemory(destination.base, negative ? -value : value);
                }
                result = cursor;
            }
        }
        else if (operation == 2 && SferaText::byteValue(text[cursor]) > ' ')
        {
            do
            {
                ++cursor;
            } while (cursor < end && SferaText::byteValue(text[cursor]) > ' ');
            result = cursor;
        }
        else if (operation == 3 && text[cursor] == '"')
        {
            ++cursor;
            while (cursor < end && text[cursor] != '\r' && text[cursor] != '\n' && text[cursor] != '"')
                ++cursor;
            if (cursor < end && text[cursor] == '"')
                result = cursor + 1;
        }
        else if (operation == 4 && parseTextLetter(text[cursor]))
        {
            do
            {
                ++cursor;
            } while (cursor < end && (parseTextLetter(text[cursor]) || parseTextDigit(text[cursor])));
            result = cursor;
        }
        else if (operation == 5 && parseTextSpace(text[cursor]))
        {
            do
            {
                ++cursor;
            } while (cursor < end && parseTextSpace(text[cursor]));
            result = cursor;
        }
        else if (operation >= 6)
        {
            while (cursor < end && (operation == 6 ? parseTextSpace(text[cursor]) : text[cursor] != '\r' && text[cursor] != '\n'))
                ++cursor;
            if (cursor < end && text[cursor] == '\r')
            {
                ++cursor;
                if (cursor < end && text[cursor] == '\n')
                    result = cursor + 1;
            }
        }
    }
    if (!result)
        pushSlice({}, SferaMbcValueTypeBytePointer);
    else
    {
        // Return an address in the original script region, never in the decoded text copy.
        const auto remaining = text.size() - *result;
        const auto address = mapMemory(memoryAt(source.base, text.size() + 1) + *result, remaining + 1);
        pushSlice({address, address, address + SferaNumeric::lowWord(remaining)}, SferaMbcValueTypeBytePointer);
    }
}

void SferaMbcRuntime::chatUtility()
{
    const auto operation = nextInteger();
    if (operation < 0 || operation > 4)
    {
        reportError("ffchat_utility(). Invalid Chat utility function type");
        return;
    }
    std::string input{}, output{}, plain{};
    const auto source = nextText();
    if (execution_failed)
        return;
    input.assign(source);
    if (operation == 0)
    {
        std::string target{}, caption{};
        target.assign(nextText());
        caption.assign(nextText());
        const auto destination = nextSlice();
        if (execution_failed)
            return;
        output = SphereUIHyperTextParser::buildLink(input, target, caption);
        copyText(destination, output);
    }
    else if (operation == 1)
    {
        const auto destination = nextSlice();
        if (execution_failed)
            return;
        output = SphereUIHyperTextParser::plainText(input);
        copyText(destination, output);
    }
    else
    {
        std::uint32_t first = 0, last = 0;
        if (operation == 4)
        {
            first = nextInteger();
            last = nextInteger();
        }
        const auto plainDestination = nextSlice();
        const auto markupDestination = nextSlice();
        if (execution_failed)
            return;
        bool success;
        if (operation == 2)
            success = SphereUIHyperTextParser::extractPlayerPrefix(input, &output, &plain);
        else if (operation == 3)
            success = SphereUIHyperTextParser::removePlayerPrefix(input, &output, &plain);
        else
            success = SphereUIHyperTextParser::eraseRange(input, first, last, &output, &plain);
        if (!success)
        {
            pushInteger(UINT32_MAX);
            return;
        }
        if (plainDestination.base != 0)
            copyText(plainDestination, plain);
        if (markupDestination.base != 0)
            copyText(markupDestination, output);
    }
    pushInteger(0);
}

template <class Value> void SferaMbcRuntime::scanTextStoreNumber(const Value &value, const SferaSliceReference32 &reference, std::size_t characters)
{
    if constexpr (!std::is_same_v<std::remove_cvref_t<decltype(value)>, std::monostate>)
    {
        const auto bytes = sliceBytes(reference, sizeof(value));
        std::memcpy(bytes.data(), &value, sizeof(value));
    }
}

template <class Value> void SferaMbcRuntime::scanTextStoreText(const Value &value, const SferaSliceReference32 &reference, std::size_t characters)
{
    if constexpr (std::is_same_v<std::remove_cvref_t<decltype(value)>, std::string> || std::is_same_v<std::remove_cvref_t<decltype(value)>, std::wstring>)
    {
        const auto end = characters != 0 ? characters : value.find(std::remove_cvref_t<decltype(value.front())>{});
        if (end > value.size() || (characters == 0 && end == value.size()))
            throw std::out_of_range("Invalid scan result length");
        const auto count = characters != 0 ? end : end + 1;
        if constexpr (std::is_same_v<std::remove_cvref_t<decltype(value)>, std::string>)
        {
            const auto bytes = sliceBytes(reference, count);
            if (count != 0)
                std::memmove(bytes.data(), value.data(), count);
        }
        else
        {
            const auto bytes = sliceBytes(reference, count * sizeof(std::uint16_t));
            for (std::size_t character = 0; character < count; ++character)
                SferaBinary::writeLittleEndian<std::uint16_t>(bytes.data() + character * sizeof(std::uint16_t), value[character]);
        }
    }
}

template <bool Text, std::size_t Index, class... Values>
void SferaMbcRuntime::scanTextStoreVariant(const std::variant<Values...> &value, const SferaSliceReference32 &reference, std::size_t characters)
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

template <class T> auto SferaMbcRuntime::scanTextNumber(auto &references, std::size_t &output, auto &numbers, auto &destinations)
{
    auto &reference = references[output];
    if (!reference.contains(sizeof(T)))
    {
        reference.diagnoseRange(sizeof(T));
        execution_failed = true;
        return;
    }
    T value{};
    const auto bytes = sliceBytes(reference, sizeof(T));
    std::memcpy(&value, bytes.data(), sizeof(T));
    numbers[output] = value;
    destinations[output] = &std::get<T>(numbers[output]);
}

auto SferaMbcRuntime::scanTextCharacter(const std::string &pattern, std::size_t position)
{
    return position < pattern.size() ? pattern[position] : '\0';
}

template <std::size_t Index>
auto SferaMbcRuntime::scanTextScan(const std::string &text, const std::string &normalized, const std::array<unsigned, 4> &capacities, const std::array<void *, 4> &destinations,
                                   std::array<int, 4> &completed, auto... arguments) -> int
{
    if constexpr (Index == 4)
        return ::sscanf_s(text.c_str(), normalized.c_str(), arguments...);
    else if (capacities[Index] != 0)
        return scanTextScan<Index + 1>(text, normalized, capacities, destinations, completed, arguments..., destinations[Index], capacities[Index], &completed[Index]);
    else
        return scanTextScan<Index + 1>(text, normalized, capacities, destinations, completed, arguments..., destinations[Index], &completed[Index]);
}

void SferaMbcRuntime::scanText()
{
    const auto source = nextAddress();
    const auto format = nextAddress();
    const auto type = argument_cursor < argument_end ? g_sfera_mbc_runtime.values[argument_cursor].type : SferaMbcValueTypeByte;

    std::array<std::variant<std::monostate, std::int8_t, std::uint8_t, std::int16_t, std::uint16_t, int, std::uint32_t, std::int64_t, std::uint64_t, float, double>, 4> numbers{};
    std::array<void *, 4> destinations{};
    std::array<SferaSliceReference32, 4> references{};
    std::array<unsigned, 4> capacities{};
    std::array<int, 4> completed;
    completed.fill(-1);
    std::array<std::size_t, 4> characterCounts{};
    std::array<std::variant<std::monostate, std::string, std::wstring>, 4> textOutputs{};
    const auto count = std::min(argument_count > 2 ? argument_count - 2 : 1u, 4u);
    for (std::uint32_t index = 0; index < count; ++index)
    {
        references[index] = nextAddress();
    }
    if (execution_failed)
        return;
    if (argument_count < 3 || argument_count > 6 || (argument_count == 3 && type != SferaMbcValueTypeIntegerPointer && type != SferaMbcValueTypeRealPointer && type != SferaMbcValueTypeBytePointer))
    {
        pushInteger(source.base);
        return;
    }
    const auto text = textIn(source);
    if (text.size() > INT_MAX)
    {
        reportError("Scan input is too large");
        return;
    }
    const auto pattern = textIn(format);
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
                reportError("Invalid scan field width");
                return;
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
            reportError("Incomplete scan format");
            return;
        }
        if (!suppressed && output >= count)
        {
            reportError("Too few scan destinations");
            return;
        }
        if (std::string_view("cCsS[").find(conversion) != std::string_view::npos)
        {
            if (!length.empty() && length != "h" && length != "l" && length != "w")
            {
                reportError("Invalid scan text modifier");
                return;
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
                    reportError("Incomplete scan character set");
                    return;
                }
            }
            normalized.append(length);
            normalized.append(pattern.substr(conversionStart, token + 1 - conversionStart));
            if (!suppressed)
            {
                const auto &reference = references[output];
                const auto bytes = sliceBytes(reference);
                const bool wide = length != "h" && (length == "l" || length == "w" || conversion == 'C' || conversion == 'S');
                const auto elementCount = bytes.size() / (wide ? sizeof(std::uint16_t) : 1u);
                if (elementCount == 0 || elementCount > UINT_MAX)
                {
                    reportError("Invalid scan destination range");
                    return;
                }
                capacities[output] = SferaNumeric::lowWord(elementCount);
                if (conversion == 'c' || conversion == 'C')
                    characterCounts[output] = fieldWidth.value_or(1u);
                if (wide)
                {
                    SferaBinaryReader reader(bytes);
                    std::wstring value(elementCount, L'\0');
                    for (auto &unit : value)
                        unit = reader.read<std::uint16_t>();
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
            reportError("Unsupported scan conversion");
            return;
        }
        if (execution_failed)
            return;
        if (!suppressed)
        {
            normalized += "%n";
            ++output;
        }
    }

    const auto result = scanTextScan<0>(text, normalized, capacities, destinations, completed);
    for (std::size_t index = 0; index < output; ++index)
    {
        if (completed[index] < 0)
            continue;
        scanTextStoreVariant<false>(numbers[index], references[index], characterCounts[index]);
        scanTextStoreVariant<true>(textOutputs[index], references[index], characterCounts[index]);
    }
    pushInteger(result);
}

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

// Process ownership, transport, platform input and application lifetime.
