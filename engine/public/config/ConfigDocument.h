#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

class SphereRenderConfigDocument;
class SphereRenderConfigDocumentParser;
struct SphereRenderConfigDocumentValue;

enum class SphereRenderConfigDocumentType
{
    Integer,
    Float,
    Text,
    Binary,
    Object,
    IntegerArray,
    FloatArray,
    TextArray,
    ObjectArray
};

enum class SphereRenderConfigDocumentStorageMode
{
    Plain,
    Encoded,
    Preserve
};

class SphereRenderConfigDocumentParser
{
    char peek() const
    {
        return position_ < source_.size() ? source_[position_] : '\0';
    }

  public:
    explicit SphereRenderConfigDocumentParser(std::string_view source);
    SphereRenderConfigDocument document(bool nested = false);

  private:
    bool skipSpace();
    void require(std::string_view token, int error, bool skip = true);
    bool separator();
    std::string identifier();
    int integer();
    float real();
    std::string text();
    std::vector<std::uint8_t> binary();
    [[noreturn]] void fail(int code) const;
    std::string_view source_;
    std::size_t position_ = 0;
    std::size_t line_ = 1;

  private:
    static bool isIdentifierLetter(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
    }
};

struct SphereRenderConfigDocumentValue
{
    std::string name;
    SphereRenderConfigDocumentType type = SphereRenderConfigDocumentType::Integer;
    std::variant<int, float, std::string, std::vector<std::uint8_t>, std::vector<int>, std::vector<float>, std::vector<std::string>, std::vector<SphereRenderConfigDocument>> data;
};

class SphereRenderConfigDocument
{
  public:
    static SphereRenderConfigDocument parse(std::string_view source);
    static SphereRenderConfigDocument open(const std::string &path);
    static void setStorageMode(SphereRenderConfigDocumentStorageMode mode)
    {
        storage_mode_ = mode;
    }
    const SphereRenderConfigDocumentValue *find(std::string_view name) const;
    std::optional<int> integer(std::string_view name) const;
    std::optional<float> real(std::string_view name) const;
    std::optional<std::string_view> text(std::string_view name) const;
    std::optional<std::size_t> arraySize(std::string_view name) const;
    std::optional<int> integerAt(std::string_view name, std::size_t index) const;
    std::optional<float> realAt(std::string_view name, std::size_t index) const;
    std::optional<std::string_view> textAt(std::string_view name, std::size_t index) const;
    const SphereRenderConfigDocument *object(std::string_view name) const;
    const SphereRenderConfigDocument *objectAt(std::string_view name, std::size_t index) const;
    std::span<const std::uint8_t> binary(std::string_view name) const;
    const std::vector<SphereRenderConfigDocumentValue> &values() const
    {
        return values_;
    }

  private:
    std::vector<SphereRenderConfigDocumentValue> values_;
    static SphereRenderConfigDocumentStorageMode storage_mode_;
    static constexpr std::uint8_t storageKey = 203;

  private:
    friend struct SphereRenderConfigDocumentValue;
    friend class SphereRenderConfigDocumentParser;

  private:
    static bool isLeadingByte(std::uint8_t byte)
    {
        return byte == '\r' || byte == ' ' || byte == '/';
    }
    static std::uint8_t transformStorageByte(std::uint8_t byte);
};
