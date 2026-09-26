#pragma once

#include <cstddef>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include "text/Parsing.h"

class SferaSimpleParser;
struct SferaVec3F;

class SferaSimpleParser
{
  public:
    bool load(const std::string &filename);
    void assign(std::string source);
    bool findBlock(std::string_view name, SferaParserRange *output, const SferaParserRange *search, std::ptrdiff_t occurrence);
    std::ptrdiff_t countBlocks(std::string_view name, const SferaParserRange *search);
    bool findValue(std::string_view name, const SferaParserRange *search);
    void setScanRange(const SferaParserRange *range)
    {
        scan_ = boundedRange(range);
    }
    void clearScanRange()
    {
        scan_ = {};
    }
    bool nextValue(std::string_view name);
    void setBlockRange(const SferaParserRange *range)
    {
        block_ = boundedRange(range);
    }
    void clearBlockRange()
    {
        block_ = {};
    }
    bool nextBlock(std::string_view name, SferaParserRange *output);
    void getBlockRange(SferaParserRange *output) const
    {
        *output = block_;
    }
    void getScanRange(SferaParserRange *output) const
    {
        *output = scan_;
    }
    std::string_view lineAt(std::ptrdiff_t index) const;
    const std::string &valueText() const
    {
        return token_;
    }
    std::size_t tokenCount() const;
    std::string_view tokenAt(std::size_t index) const;
    bool tryReadFloat(std::size_t index, float &output) const;
    bool tryReadInt(std::size_t index, int &output) const;
    bool readFloatSequence(std::size_t index, std::span<float> output) const;
    bool readIntSequence(std::size_t index, std::span<int> output) const;
    bool readVector(std::size_t index, SferaVec3F &output) const;
    float readFloat(std::size_t index) const;
    int readInt(std::size_t index) const;
    bool readString(std::size_t index, std::string &output) const;
    bool readQuotedString(std::size_t index, std::string &output) const;
    bool readBool(std::size_t index) const;

  private:
    static constexpr std::size_t maximumValueLength = 1023;
    std::string source_;
    std::vector<std::size_t> lines_;
    std::string token_;
    SferaParserRange scan_{};
    SferaParserRange block_{};
    SferaParserRange boundedRange(const SferaParserRange *range) const;
    static std::string_view firstToken(std::string_view line);
    std::ptrdiff_t findClosingBrace(std::ptrdiff_t begin, std::ptrdiff_t end) const;
    std::ptrdiff_t parseBlockAt(std::string_view first, std::ptrdiff_t line, std::ptrdiff_t end, SferaParserRange *output);
    bool findValueFrom(std::string_view name, std::ptrdiff_t &line, std::ptrdiff_t end);
    std::size_t tokenStart(std::size_t index) const;

  private:
    static bool simple_parser_whitespace(std::string_view text, std::size_t index = 0)
    {
        // Preserve the original signed code-unit comparison used by this grammar.
        return text[index] <= ' ';
    }
};
