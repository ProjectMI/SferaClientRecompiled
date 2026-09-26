#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <exception>
#include <fstream>
#include <ios>
#include <iterator>
#include <new>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

#include "binary/Binary.h"
#include "compression/Zlib.h"
#include "config/ConfigDocument.h"
#include "config/SimpleParser.h"
#include "diagnostics/ClientDiagnostics.h"
#include "numeric/Numeric.h"
#include "resources/FileResources.h"
#include "script/ConfigText.h"
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"
#include "text/Text.h"

std::size_t SferaConfigTextRuntime::copyText(std::string_view source)
{
    std::string next(source.substr(0, text_capacity - 1));
    const auto count = next.size();
    storage_ = std::move(next);
    filename.clear();
    return count;
}
std::span<std::uint8_t> SferaConfigTextRuntime::borrowedBytes(const SferaConfigTextRuntimeBorrowedText &view) const
{
    if (view.process && (view.process->chain_prev_index < 0 || view.process->lifetime != view.process_lifetime))
        throw std::out_of_range("Configuration source process is no longer alive");
    if (g_sfera_mbc_runtime.memoryLifetime(view.address) != view.mapping_lifetime)
        throw std::out_of_range("Configuration source mapping was replaced");
    auto bytes = g_sfera_mbc_runtime.memoryRange(view.address, view.process);
    if (view.capacity > bytes.size())
        throw std::out_of_range("Configuration source buffer shrank");
    return bytes.first(view.capacity);
}
std::string SferaConfigTextRuntime::text() const
{
    if (const auto *owned = std::get_if<std::string>(&storage_))
        return *owned;
    const auto bytes = borrowedBytes(std::get<SferaConfigTextRuntimeBorrowedText>(storage_));
    return SferaText::terminated(bytes);
}

void SferaConfigTextRuntime::useText(std::uint32_t address, std::size_t capacity, SferaMbcProcessRecord *process)
{
    if (address >= SferaMbcRuntime::mappedAddressBegin)
        process = nullptr;
    SferaConfigTextRuntimeBorrowedText view{address, std::min(capacity, text_capacity), process, process ? process->lifetime : 0, g_sfera_mbc_runtime.memoryLifetime(address)};
    const auto bytes = borrowedBytes(view);
    (void)SferaText::length(bytes);
    storage_ = view;
    filename.clear();
}

std::optional<std::string> SferaConfigTextRuntime::find(std::string_view key) const
{
    if (key.size() >= 4096)
        return std::nullopt;
    const auto input = text();
    const auto offset = SferaText::configValueOffset(input, key);
    return offset == std::string_view::npos ? std::nullopt : std::optional(input.substr(offset));
}

bool SferaConfigTextRuntime::readInteger(std::string_view key, int &value) const
{
    const auto input = find(key);
    return input && SferaText::readNumber(*input, value);
}

bool SferaConfigTextRuntime::readFloat(std::string_view key, float &value) const
{
    const auto input = find(key);
    return input && SferaText::readNumber(*input, value);
}

std::optional<std::string> SferaConfigTextRuntime::readString(std::string_view key) const
{
    const auto input = find(key);
    if (!input || input->empty() || input->front() != '"')
        return std::nullopt;
    std::string result;
    for (const auto character : input->substr(1))
    {
        if (character == '"' || character == '\0')
            break;
        if (character != '\n')
            result.push_back(character == '\r' ? ' ' : character);
    }
    return result;
}

auto SferaConfigTextRuntime::appendDecodedBits(std::vector<std::uint8_t> &decoded, std::span<std::uint8_t> destination, unsigned &pending, unsigned &bits, unsigned value, unsigned count)
{
    const auto required = (bits + count + 7u) / 8u;
    if (decoded.size() > destination.size() || required > destination.size() - decoded.size())
        return false;
    pending |= value << bits;
    bits += count;
    if (bits >= 8u)
    {
        decoded.push_back(SferaNumeric::lowByte(pending));
        pending >>= 8u;
        bits -= 8u;
    }
    return true;
}

bool SferaConfigTextRuntime::readBinary(std::string_view key, std::span<std::uint8_t> destination) const
{
    const auto input = find(key);
    if (!input)
        return false;
    std::vector<std::uint8_t> decoded;
    unsigned pending = 0, bits = 0;

    std::size_t cursor = 0;
    while (cursor < input->size() && (*input)[cursor] != '\0' && (*input)[cursor] != '#')
    {
        const auto value = SferaText::byteValue((*input)[cursor++]);
        if (value < '0' || value > '0' + 63 || !appendDecodedBits(decoded, destination, pending, bits, value - '0', 6u))
            return false;
    }
    if (cursor < input->size() && (*input)[cursor] == '#')
    {
        if (++cursor == input->size())
            return false;
        const auto marker = SferaText::byteValue((*input)[cursor++]);
        if (marker < '0' || marker > '8')
            return false;
        const unsigned count = marker - '0';
        if (count != 0)
        {
            if (cursor == input->size())
                return false;
            const auto value = SferaText::byteValue((*input)[cursor]);
            if (value < '0' || (value - '0') >= (1 << count) || !appendDecodedBits(decoded, destination, pending, bits, value - '0', count))
                return false;
        }
    }
    if (bits != 0)
    {
        if (decoded.size() == destination.size())
            return false;
        const auto mask = (1u << bits) - 1u;
        decoded.push_back(SferaNumeric::lowByte((destination[decoded.size()] & ~mask) | (pending & mask)));
    }
    SferaBinary::copy(destination, decoded);
    return true;
}

std::size_t SferaConfigTextRuntime::copyTo(std::span<std::uint8_t> destination) const
{
    const auto input = text();
    const auto count = std::min(destination.size(), input.size());
    if (count != 0)
        std::memmove(destination.data(), input.data(), count);
    return count;
}

bool SferaConfigTextRuntime::load(const std::string &path)
{
    if (path.empty() || path.size() >= filename_capacity)
        return false;
    const std::string nextPath(path);
    clear(nextPath);
    auto bytes = SferaFileManager::readBounded(nextPath, text_capacity);
    if (!bytes)
        return false;
    try
    {
        if (SferaZStream32::hasEnvelope(*bytes))
        {
            std::vector<std::uint8_t> decoded(text_capacity);
            std::uint32_t count = SferaNumeric::lowWord(decoded.size() - 1u);
            if (SferaZStream32::decompressEnvelope(decoded.data(), count, *bytes) != 0)
            {
                clear();
                return false;
            }
            decoded.resize(count);
            bytes = std::move(decoded);
        }
        storage_ = SferaText::fromBytes(*bytes);
        return true;
    }
    catch (const std::exception &)
    {
        clear();
        return false;
    }
}
bool SferaConfigTextRuntime::save(bool compressed) const
{
    if (filename.empty())
        return false;
    const auto input = text();
    if (!compressed)
        return SferaFileManager::writeFile(filename, std::as_bytes(std::span(input)));
    try
    {
        std::vector<std::uint8_t> encoded(text_capacity);
        std::uint32_t count = SferaNumeric::lowWord(encoded.size() - 1u);
        const std::vector<std::uint8_t> source(input.begin(), input.end());
        if (SferaZStream32::compressEnvelope(encoded.data(), count, source) != 0)
            return false;
        return SferaFileManager::writeFile(filename, std::as_bytes(std::span(encoded).first(count)));
    }
    catch (const std::bad_alloc &)
    {
        return false;
    }
}
std::string SferaConfigTextRuntime::encodeBinary(const std::uint8_t *input, std::size_t size)
{
    constexpr std::string_view alphabet = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmno";
    static_assert(alphabet.size() == 64u);
    std::string result;
    result.reserve(size * CHAR_BIT / 6 + 3);
    std::uint32_t pending = 0;
    std::uint32_t count = 0;
    for (std::size_t index = 0; index < size; ++index)
    {
        pending |= input[index] << count;
        count += CHAR_BIT;
        while (count >= 6)
        {
            result.push_back(alphabet[pending & 63u]);
            pending >>= 6u;
            count -= 6u;
        }
    }
    result.push_back('#');
    result.push_back(alphabet[count]);
    if (count != 0)
        result.push_back(alphabet[pending]);
    return result;
}
bool SferaConfigTextRuntime::writeValue(std::string_view key, std::string_view value, bool quoted)
{
    std::string next(text());
    auto *borrowed = std::get_if<SferaConfigTextRuntimeBorrowedText>(&storage_);
    const auto capacity = borrowed ? std::min(borrowed->capacity, text_capacity) : text_capacity;
    if (!SferaText::replaceConfigValue(next, key, value, quoted, capacity))
        return false;
    if (borrowed)
    {
        const auto bytes = borrowedBytes(*borrowed);
        std::copy(next.begin(), next.end(), bytes.begin());
        bytes[next.size()] = 0;
    }
    else
        std::get<std::string>(storage_).swap(next);
    return true;
}

bool SferaSimpleParser::load(const std::string &filename)
{
    *this = {};
    if (filename.empty())
        return false;
    std::ifstream stream;
    for (const auto &path : g_sfera_files.candidatePaths(filename))
    {
        stream.open(path, std::ios::binary | std::ios::ate);
        if (stream.is_open())
            break;
        stream.clear();
    }
    if (!stream.is_open())
        return false;
    const std::streamoff length = stream.tellg() - std::streampos(0);
    if (length <= 0 || std::cmp_greater_equal(length, PTRDIFF_MAX))
        return false;
    const std::size_t source_size = length;
    std::string source(source_size, '\0');
    stream.seekg(0, std::ios::beg);
    const std::streamsize read_size = source.size();
    stream.read(source.data(), read_size);
    if (stream.gcount() <= 0)
        return false;
    source.resize(stream.gcount());
    assign(std::move(source));
    return true;
}

SphereRenderConfigDocument SphereRenderConfigDocument::open(const std::string &path)
{
    try
    {
        auto bytes = g_sfera_files.readAll(path);
        if (bytes.empty())
            throw std::runtime_error(std::string("openCfg: wrong format of Cfg ") + path);

        const bool encoded = isLeadingByte(transformStorageByte(bytes.front()));
        if (!encoded && !isLeadingByte(bytes.front()))
            throw std::runtime_error(std::string("openCfg: wrong format of Cfg ") + path);
        if (encoded)
            std::transform(bytes.begin(), bytes.end(), bytes.begin(), transformStorageByte);
        const bool rewrite = (encoded && storage_mode_ == SphereRenderConfigDocumentStorageMode::Plain) || (!encoded && storage_mode_ == SphereRenderConfigDocumentStorageMode::Encoded);
        if (rewrite)
        {
            auto stored = bytes;
            if (storage_mode_ == SphereRenderConfigDocumentStorageMode::Encoded)
                std::transform(stored.begin(), stored.end(), stored.begin(), transformStorageByte);
            SferaFileManagerScopedFile file(g_sfera_files, g_sfera_files.create(path));
            if (file.get() < 0)
                throw std::runtime_error(std::string("Unable to create Cfg ") + path);
            if (g_sfera_files.write(file.get(), std::as_bytes(std::span(stored))) != std::ssize(stored))
                throw std::runtime_error(std::string("Incomplete Cfg write: ") + path);
            file.close();
        }
        return parse(SferaText::fromBytes(bytes));
    }
    catch (const std::exception &exception)
    {
        CSphereError error;
        error.write(exception.what());
        throw;
    }
}
