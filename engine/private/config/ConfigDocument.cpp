#include <charconv>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <utility>
#include <variant>
#include <vector>

#include "config/ConfigDocument.h"
#include "numeric/Numeric.h"
#include "text/Text.h"

SphereRenderConfigDocumentParser::SphereRenderConfigDocumentParser(std::string_view source) : source_(source)
{
}

SphereRenderConfigDocument SphereRenderConfigDocumentParser::document(bool nested)
{
    SphereRenderConfigDocument result;
    while (skipSpace())
    {
        if (peek() == '}')
        {
            if (!nested)
                fail(36);
            ++position_;
            return result;
        }
        SphereRenderConfigDocumentValue value;
        value.name = identifier();
        if (result.find(value.name) != nullptr)
            throw std::runtime_error("openCfg: duplicate name: " + value.name);
        require("<", 5);
        const bool array = peek() == 'a' || peek() == 'A';
        if (array)
            ++position_;
        const auto type = peek();
        if (type != '\0')
            ++position_;
        require(">", 8, false);
        require("=", 10);
        if (!skipSpace())
            fail(11);
        switch (type)
        {
        case 'i':
        case 'I':
            value.type = array ? SphereRenderConfigDocumentType::IntegerArray : SphereRenderConfigDocumentType::Integer;
            if (array)
            {
                std::vector<int> items;
                do
                {
                    items.push_back(integer());
                } while (separator());
                value.data = std::move(items);
            }
            else
                value.data = integer();
            break;
        case 'f':
        case 'F':
            value.type = array ? SphereRenderConfigDocumentType::FloatArray : SphereRenderConfigDocumentType::Float;
            if (array)
            {
                std::vector<float> items;
                do
                {
                    items.push_back(real());
                } while (separator());
                value.data = std::move(items);
            }
            else
                value.data = real();
            break;
        case 't':
        case 'T':
            value.type = array ? SphereRenderConfigDocumentType::TextArray : SphereRenderConfigDocumentType::Text;
            if (array)
            {
                std::vector<std::string> items;
                do
                {
                    items.push_back(text());
                } while (separator());
                value.data = std::move(items);
            }
            else
                value.data = text();
            break;
        case 'u':
        case 'U':
            if (array)
                fail(7);
            value.type = SphereRenderConfigDocumentType::Binary;
            value.data = binary();
            break;
        case 's':
        case 'S':
        {
            value.type = array ? SphereRenderConfigDocumentType::ObjectArray : SphereRenderConfigDocumentType::Object;
            std::vector<SphereRenderConfigDocument> items;
            do
            {
                require("{", array ? 35 : 33);
                items.push_back(document(true));
            } while (array && separator());
            value.data = std::move(items);
            break;
        }
        default:
            fail(6);
        }
        result.values_.push_back(std::move(value));
    }
    if (nested)
        fail(1);
    return result;
}

bool SphereRenderConfigDocumentParser::skipSpace()
{
    while (position_ < source_.size())
    {
        if (source_[position_] == '\0')
            return false;
        if (source_[position_] == '/' && position_ + 1 < source_.size() && source_[position_ + 1] == '/')
        {
            position_ += 2;
            while (position_ < source_.size() && source_[position_] != '\n' && source_[position_] != '\0')
                ++position_;
            continue;
        }
        if (source_[position_] == '\n')
            ++line_;
        else if (source_[position_] != ' ' && source_[position_] != '\r')
            return true;
        ++position_;
    }
    return false;
}

void SphereRenderConfigDocumentParser::require(std::string_view token, int error, bool skip)
{
    if (skip)
        skipSpace();
    if (!source_.substr(position_).starts_with(token))
        fail(error);
    position_ += token.size();
}

bool SphereRenderConfigDocumentParser::separator()
{
    skipSpace();
    if (peek() != ',')
        return false;
    ++position_;
    if (!skipSpace())
        fail(17);
    return true;
}

std::string SphereRenderConfigDocumentParser::identifier()
{
    if (!isIdentifierLetter(peek()))
        fail(2);
    const auto begin = position_++;
    while (isIdentifierLetter(peek()) || (peek() >= '0' && peek() <= '9'))
        ++position_;
    if (position_ - begin > 250)
        fail(3);
    return std::string(source_.substr(begin, position_ - begin));
}

int SphereRenderConfigDocumentParser::integer()
{
    const auto begin = position_;
    if (peek() == '-')
        ++position_;
    const auto digits = position_;
    while (peek() >= '0' && peek() <= '9')
        ++position_;
    if (digits == position_)
        fail(13);
    int value = 0;
    const auto parsed = std::from_chars(source_.data() + begin, source_.data() + position_, value);
    if (parsed.ec != std::errc{})
        fail(14);
    return value;
}

float SphereRenderConfigDocumentParser::real()
{
    const auto begin = position_;
    if (peek() == '-')
        ++position_;
    while ((peek() >= '0' && peek() <= '9') || peek() == '.')
        ++position_;
    float value = 0.0f;
    const auto parsed = std::from_chars(source_.data() + begin, source_.data() + position_, value);
    if (parsed.ec != std::errc{} || parsed.ptr != source_.data() + position_)
        fail(18);
    return value;
}

std::string SphereRenderConfigDocumentParser::text()
{
    require("\"", 23);
    const auto begin = position_;
    while (peek() != '"')
    {
        if (peek() == '\0')
            fail(24);
        ++position_;
    }
    std::string value(source_.substr(begin, position_ - begin));
    ++position_;
    return value;
}

std::vector<std::uint8_t> SphereRenderConfigDocumentParser::binary()
{
    if (peek() < '0' || peek() > '9')
        fail(28);
    const std::size_t length = integer();
    require(":", 30, false);
    if (!skipSpace() && length != 0)
        fail(31);
    const auto encoded_length = (length / 7) * 8 + ((length % 7) * 8 + 6) / 7;
    if (encoded_length > source_.size() - position_)
        fail(39);
    const auto encoded = source_.substr(position_, encoded_length);
    std::vector<std::uint8_t> bytes(length);
    for (std::size_t index = 0; index < length; ++index)
    {
        const auto first = index + index / 7;
        const unsigned shift = index % 7;
        if (encoded[first] == '\0' || encoded[first + 1] == '\0')
            fail(39);
        const auto low = SferaText::byteValue(encoded[first]) - '0';
        const auto high = SferaText::byteValue(encoded[first + 1]) - '0';
        bytes[index] = SferaNumeric::lowByte(SferaNumeric::lowWord((low >> shift) | (high << (7 - shift))));
    }
    position_ += encoded_length;
    return bytes;
}

[[noreturn]] void SphereRenderConfigDocumentParser::fail(int code) const
{
    throw std::runtime_error("parse_error: " + std::to_string(code) + ". Line " + std::to_string(line_));
}

SphereRenderConfigDocument SphereRenderConfigDocument::parse(std::string_view source)
{
    return SphereRenderConfigDocumentParser(source).document();
}

const SphereRenderConfigDocumentValue *SphereRenderConfigDocument::find(std::string_view name) const
{
    for (const auto &value : values_)
        if (SferaText::asciiEqual(value.name, name))
            return &value;
    return nullptr;
}

std::optional<int> SphereRenderConfigDocument::integer(std::string_view name) const
{
    const auto *value = find(name);
    if (value == nullptr)
        return std::nullopt;
    if (value->type != SphereRenderConfigDocumentType::Integer)
        throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<int>(value->data);
}

std::optional<float> SphereRenderConfigDocument::real(std::string_view name) const
{
    const auto *value = find(name);
    if (value == nullptr)
        return std::nullopt;
    if (value->type != SphereRenderConfigDocumentType::Float)
        throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<float>(value->data);
}

std::optional<std::string_view> SphereRenderConfigDocument::text(std::string_view name) const
{
    const auto *value = find(name);
    if (value == nullptr)
        return std::nullopt;
    if (value->type != SphereRenderConfigDocumentType::Text)
        throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::string>(value->data);
}

std::optional<std::size_t> SphereRenderConfigDocument::arraySize(std::string_view name) const
{
    const auto *value = find(name);
    if (value == nullptr)
        return std::nullopt;
    switch (value->type)
    {
    case SphereRenderConfigDocumentType::IntegerArray:
        return std::get<std::vector<int>>(value->data).size();
    case SphereRenderConfigDocumentType::FloatArray:
        return std::get<std::vector<float>>(value->data).size();
    case SphereRenderConfigDocumentType::TextArray:
        return std::get<std::vector<std::string>>(value->data).size();
    case SphereRenderConfigDocumentType::ObjectArray:
        return std::get<std::vector<SphereRenderConfigDocument>>(value->data).size();
    default:
        throw std::runtime_error("getCfg: get size for non array. Name: " + value->name);
    }
}

std::optional<int> SphereRenderConfigDocument::integerAt(std::string_view name, std::size_t index) const
{
    const auto *value = find(name);
    if (value == nullptr)
        return std::nullopt;
    if (value->type != SphereRenderConfigDocumentType::IntegerArray)
        throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::vector<int>>(value->data).at(index);
}

std::optional<float> SphereRenderConfigDocument::realAt(std::string_view name, std::size_t index) const
{
    const auto *value = find(name);
    if (value == nullptr)
        return std::nullopt;
    if (value->type != SphereRenderConfigDocumentType::FloatArray)
        throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::vector<float>>(value->data).at(index);
}

std::optional<std::string_view> SphereRenderConfigDocument::textAt(std::string_view name, std::size_t index) const
{
    const auto *value = find(name);
    if (value == nullptr)
        return std::nullopt;
    if (value->type != SphereRenderConfigDocumentType::TextArray)
        throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::vector<std::string>>(value->data).at(index);
}

const SphereRenderConfigDocument *SphereRenderConfigDocument::object(std::string_view name) const
{
    const auto *value = find(name);
    if (value == nullptr)
        return nullptr;
    if (value->type != SphereRenderConfigDocumentType::Object)
        throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return &std::get<std::vector<SphereRenderConfigDocument>>(value->data).front();
}

const SphereRenderConfigDocument *SphereRenderConfigDocument::objectAt(std::string_view name, std::size_t index) const
{
    const auto *value = find(name);
    if (value == nullptr)
        return nullptr;
    if (value->type != SphereRenderConfigDocumentType::ObjectArray)
        throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return &std::get<std::vector<SphereRenderConfigDocument>>(value->data).at(index);
}

std::span<const std::uint8_t> SphereRenderConfigDocument::binary(std::string_view name) const
{
    const auto *value = find(name);
    if (value == nullptr)
        return {};
    if (value->type != SphereRenderConfigDocumentType::Binary)
        throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::vector<std::uint8_t>>(value->data);
}

std::uint8_t SphereRenderConfigDocument::transformStorageByte(std::uint8_t byte)
{
    return SferaNumeric::lowByte(SferaNumeric::lowWord(byte ^ storageKey));
}

SphereRenderConfigDocumentStorageMode SphereRenderConfigDocument::storage_mode_ = SphereRenderConfigDocumentStorageMode::Plain;
