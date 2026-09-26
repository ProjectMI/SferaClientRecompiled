#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

struct SferaConfigTextRuntime;
struct SferaConfigTextRuntimeBorrowedText;
struct SferaMbcProcessRecord;

enum class SferaConfigTextRuntimeOperation : int
{
    Write = 13,
    Read = 14,
    Load = 15,
    Save = 16,
    Clear = 17,
    UseText = 30,
    ReadCommands = 54,
    SaveCompressed = 55,
    CopyText = 56,
    Length = 57,
    SetFilename = 62
};

struct SferaConfigTextRuntimeBorrowedText
{
    std::uint32_t address;
    std::size_t capacity;
    SferaMbcProcessRecord *process;
    std::uint64_t process_lifetime;
    std::uint64_t mapping_lifetime;
};

struct SferaConfigTextRuntime
{
    static constexpr std::size_t text_capacity = 2458176u;
    static constexpr std::size_t filename_capacity = 1024u;
    bool load(const std::string &filename);
    bool save(bool compressed = false) const;
    bool writeValue(std::string_view key, std::string_view value, bool quoted);
    static std::string encodeBinary(const std::uint8_t *input, std::size_t size);
    std::string filename;
    std::string text() const;
    std::size_t copyText(std::string_view source);
    void useText(std::uint32_t address, std::size_t capacity, SferaMbcProcessRecord *process);
    void clear(std::string path = {})
    {
        storage_.emplace<std::string>();
        filename = std::move(path);
    }
    std::optional<std::string> find(std::string_view key) const;
    bool readInteger(std::string_view key, int &value) const;
    bool readFloat(std::string_view key, float &value) const;
    std::optional<std::string> readString(std::string_view key) const;
    bool readBinary(std::string_view key, std::span<std::uint8_t> destination) const;
    std::size_t copyTo(std::span<std::uint8_t> destination) const;

  private:
    std::variant<std::string, SferaConfigTextRuntimeBorrowedText> storage_;
    std::span<std::uint8_t> borrowedBytes(const SferaConfigTextRuntimeBorrowedText &view) const;

  private:
    friend struct SferaConfigTextRuntimeBorrowedText;

  private:
    static auto appendDecodedBits(std::vector<std::uint8_t> &decoded, std::span<std::uint8_t> destination, unsigned &pending, unsigned &bits, unsigned value, unsigned count);
};

extern SferaConfigTextRuntime g_sfera_config_text_runtime;
