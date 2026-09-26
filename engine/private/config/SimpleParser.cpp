#include <algorithm>
#include <cstddef>
#include <iterator>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "config/SimpleParser.h"
#include "math/Vector.h"
#include "text/Parsing.h"
#include "text/Text.h"

void SferaSimpleParser::assign(std::string source)
{
    if (source.size() >= PTRDIFF_MAX)
        throw std::length_error("Parser input too large");
    std::vector<std::size_t> lines{0};
    // CRLF is one separator. LF and lone CR must not hide the remaining declarations.
    for (std::size_t index = 0; index < source.size(); ++index)
    {
        const auto separator = source[index];
        if (separator != '\r' && separator != '\n')
            continue;
        source[index] = '\0';
        if (separator == '\r' && index + 1 < source.size() && source[index + 1] == '\n')
            source[++index] = '\0';
        lines.push_back(index + 1);
    }
    source_ = std::move(source);
    lines_ = std::move(lines);
    token_.clear();
    const std::ptrdiff_t line_count = std::ssize(lines_);
    scan_ = block_ = {0, line_count};
}

SferaParserRange SferaSimpleParser::boundedRange(const SferaParserRange *range) const
{
    const std::ptrdiff_t count = std::ssize(lines_);
    return range == nullptr ? SferaParserRange{0, count} : SferaParserRange{std::max(range->begin, std::ptrdiff_t{0}), std::min(range->end, count)};
}

std::string_view SferaSimpleParser::lineAt(std::ptrdiff_t index) const
{
    if (index < 0 || index >= std::ssize(lines_))
        return {};
    const auto offset = lines_[index];
    const auto end = source_.find('\0', offset);
    return std::string_view(source_).substr(offset, end == std::string::npos ? source_.size() - offset : end - offset);
}

std::string_view SferaSimpleParser::firstToken(std::string_view line)
{
    while (!line.empty() && SferaSimpleParser::simple_parser_whitespace(line))
        line.remove_prefix(1);
    return line.starts_with("//") ? std::string_view{} : line;
}

std::ptrdiff_t SferaSimpleParser::findClosingBrace(std::ptrdiff_t begin, std::ptrdiff_t end) const
{
    std::ptrdiff_t depth = 1;
    for (auto index = begin; index < end; ++index)
    {
        const auto line = firstToken(lineAt(index));
        for (std::size_t at = 0; at < line.size(); ++at)
        {
            if (line.substr(at).starts_with("//"))
                break;
            if (line[at] == '{')
                ++depth;
            else if (line[at] == '}' && --depth == 0)
                return index;
        }
    }
    return -1;
}

std::ptrdiff_t SferaSimpleParser::parseBlockAt(std::string_view first, std::ptrdiff_t line, std::ptrdiff_t end, SferaParserRange *output)
{
    if (first.empty() || line >= end)
        return -1;
    std::size_t length = 0;
    while (length < first.size() && !SferaSimpleParser::simple_parser_whitespace(first, length))
        ++length;
    if (length > maximumValueLength)
        return -1;
    token_.assign(first.substr(0, length));
    auto open = line;
    if (first.find('{', length) == std::string_view::npos)
    {
        for (open = line + 1; open < end; ++open)
        {
            const auto next = firstToken(lineAt(open));
            if (next.empty())
                continue;
            if (next.front() != '{')
                return -1;
            break;
        }
    }
    if (open >= end)
        return -1;
    const auto close = findClosingBrace(open + 1, end);
    if (close < 0)
        return -1;
    if (output != nullptr)
        *output = {open + 1, close + 1};
    return close - open + 1;
}

bool SferaSimpleParser::findBlock(std::string_view name, SferaParserRange *output, const SferaParserRange *search, std::ptrdiff_t occurrence)
{
    if (name.empty() || output == nullptr)
        return false;
    const auto range = boundedRange(search);
    std::ptrdiff_t matched = 0;
    for (auto line = range.begin; line < range.end;)
    {
        const auto first = firstToken(lineAt(line));
        if (first.empty() || parseBlockAt(first, line, range.end, output) < 0)
        {
            ++line;
            continue;
        }
        if (SferaText::asciiEqual(token_, name) && ++matched == occurrence)
            return true;
        line = output->end;
    }
    return false;
}

std::ptrdiff_t SferaSimpleParser::countBlocks(std::string_view name, const SferaParserRange *search)
{
    auto range = boundedRange(search);
    SferaParserRange block{};
    std::ptrdiff_t count = 0;
    while (findBlock(name, &block, &range, 1))
    {
        ++count;
        range.begin = block.end;
    }
    return count;
}

bool SferaSimpleParser::findValueFrom(std::string_view name, std::ptrdiff_t &line, std::ptrdiff_t end)
{
    if (name.empty())
        return false;
    while (line < end)
    {
        const auto first = firstToken(lineAt(line));
        if (first.empty())
        {
            ++line;
            continue;
        }
        SferaParserRange block{};
        if (parseBlockAt(first, line, end, &block) >= 0)
        {
            line = block.end;
            continue;
        }
        std::size_t length = 0;
        while (length < first.size() && !SferaSimpleParser::simple_parser_whitespace(first, length))
            ++length;
        token_.assign(first.substr(0, std::min(length, maximumValueLength)));
        if (SferaText::asciiEqual(token_, name))
        {
            token_.assign(first.substr(length, maximumValueLength));
            ++line;
            return true;
        }
        ++line;
    }
    return false;
}

bool SferaSimpleParser::findValue(std::string_view name, const SferaParserRange *search)
{
    auto range = boundedRange(search);
    return findValueFrom(name, range.begin, range.end);
}

bool SferaSimpleParser::nextValue(std::string_view name)
{
    auto next = scan_.begin;
    if (!findValueFrom(name, next, scan_.end))
        return false;
    scan_.begin = next;
    return true;
}

bool SferaSimpleParser::nextBlock(std::string_view name, SferaParserRange *output)
{
    if (!findBlock(name, output, &block_, 1))
        return false;
    block_.begin = output->end;
    return true;
}

std::size_t SferaSimpleParser::tokenCount() const
{
    std::string_view rest(token_);
    std::size_t count = 0;
    while (!(rest = firstToken(rest)).empty())
    {
        ++count;
        while (!rest.empty() && !SferaSimpleParser::simple_parser_whitespace(rest))
        {
            if (rest.starts_with("//"))
                return count;
            rest.remove_prefix(1);
        }
    }
    return count;
}

std::size_t SferaSimpleParser::tokenStart(std::size_t index) const
{
    std::size_t offset = 0;
    for (std::size_t current = 0; offset < token_.size(); ++current)
    {
        while (offset < token_.size() && SferaSimpleParser::simple_parser_whitespace(token_, offset))
            ++offset;
        if (offset == token_.size() || std::string_view(token_).substr(offset).starts_with("//"))
            break;
        if (current == index)
            return offset;
        while (offset < token_.size() && !SferaSimpleParser::simple_parser_whitespace(token_, offset))
            ++offset;
    }
    return std::string::npos;
}

std::string_view SferaSimpleParser::tokenAt(std::size_t index) const
{
    const auto start = tokenStart(index);
    if (start == std::string::npos)
        return {};
    auto end = start;
    while (end < token_.size() && !SferaSimpleParser::simple_parser_whitespace(token_, end))
        ++end;
    return std::string_view(token_).substr(start, end - start);
}

bool SferaSimpleParser::tryReadFloat(std::size_t index, float &output) const
{
    return SferaText::readNumber(tokenAt(index), output);
}

bool SferaSimpleParser::tryReadInt(std::size_t index, int &output) const
{
    return SferaText::readNumber(tokenAt(index), output);
}

bool SferaSimpleParser::readFloatSequence(std::size_t index, std::span<float> output) const
{
    if (output.size() > SIZE_MAX - index)
        return false;
    for (auto &value : output)
        if (!tryReadFloat(index++, value))
            return false;
    return true;
}

bool SferaSimpleParser::readIntSequence(std::size_t index, std::span<int> output) const
{
    if (output.size() > SIZE_MAX - index)
        return false;
    for (auto &value : output)
        if (!tryReadInt(index++, value))
            return false;
    return true;
}

bool SferaSimpleParser::readVector(std::size_t index, SferaVec3F &output) const
{
    return index <= SIZE_MAX - 2 && tryReadFloat(index, output.x) && tryReadFloat(index + 1, output.y) && tryReadFloat(index + 2, output.z);
}

float SferaSimpleParser::readFloat(std::size_t index) const
{
    float value = 0.0f;
    tryReadFloat(index, value);
    return value;
}

int SferaSimpleParser::readInt(std::size_t index) const
{
    int value = 0;
    tryReadInt(index, value);
    return value;
}

bool SferaSimpleParser::readString(std::size_t index, std::string &output) const
{
    const auto value = tokenAt(index);
    if (value.empty())
        return false;
    output.assign(value);
    return true;
}

bool SferaSimpleParser::readQuotedString(std::size_t index, std::string &output) const
{
    const auto start = tokenStart(index);
    if (start == std::string::npos || token_[start] != '"')
        return false;
    const auto end = token_.find('"', start + 1);
    output.assign(token_, start + 1, end == std::string::npos ? std::string::npos : end - start - 1);
    return true;
}

bool SferaSimpleParser::readBool(std::size_t index) const
{
    const auto value = tokenAt(index);
    return !value.empty() && (value.front() == '1' || SferaText::asciiEqual(value, "true"));
}
