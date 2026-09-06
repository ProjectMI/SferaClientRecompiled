#include "semantic_classes.h"
#include "semantic_static.h"
#include "lifted_functions.h"
#include "import_bridge.h"
#include <algorithm>
#include <array>
#include <bit>
#include <charconv>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
#include <new>
#include <fstream>
#include <filesystem>
#include <iterator>
#include <stdexcept>
#include <limits>
#include <string>
#include <string_view>
#include <span>
#include <vector>
namespace {
    template <class T> T* ptr32(std::uint32_t address) { return reinterpret_cast<T*>(static_cast<std::uintptr_t>(address)); }
    HWND main_window_handle() { return reinterpret_cast<HWND>(static_cast<std::uintptr_t>(g_sfera_window_runtime.main_window)); }
    IDirectInputDevice8A* mouse_input_device() { return SferaAbi::pointer<IDirectInputDevice8A>(g_sfera_direct_input_runtime.mouse_device); }
    void set_system_cursor_visibility(bool visible) { if (visible) { while (::ShowCursor(TRUE) < 0) {} } else { while (::ShowCursor(FALSE) >= 0) {} } }
    bool cursor_uses_center_clip(std::uint32_t kind) { const char* name = kind < 4u ? sfera_cursor_texture_name(kind) : nullptr; return name != nullptr && name[0] != '_'; }
    constexpr std::uint32_t kRgbColorMask = (1u << 24u) - 1u;
    std::uint32_t opacity_alpha(double value) { return static_cast<std::uint32_t>(static_cast<std::int64_t>(std::trunc(value))); }
    void replace_color_alpha(std::uint32_t& color, std::uint32_t alpha) { color = (color & kRgbColorMask) | (alpha << 24u); }
    char* duplicate_managed_string(const char* source) {
        if (source == nullptr || *source == '\0') return nullptr;
        const std::size_t length = std::strlen(source) + 1u;
        auto* result = static_cast<char*>(g_sfera_effect_manager.allocate(length));
        if (result != nullptr) std::memcpy(result, source, length);
        return result;
    }
    bool simple_parser_whitespace(char value) {
        return value <= ' ';
    }
    char* simple_parser_copy_token(const char* source, char* output) {
        char* cursor = output;
        while (!simple_parser_whitespace(*source)) *cursor++ = *source++;
        *cursor = '\0';
        return output;
    }
    void simple_parser_copy_token_bounded(const char* source, char* output, std::size_t capacity) {
        if (capacity == 0u) return;
        std::size_t length = 0u;
        while (length + 1u < capacity && !simple_parser_whitespace(source[length])) {
            output[length] = source[length];
            ++length;
        }
        output[length] = '\0';
    }
}
void SferaSimpleParser::initialize() {
    source_begin = 0u;
    source_end = 0u;
    line_table = 0u;
    line_count = 0u;
}
namespace {
    void simple_parser_copy_rest(const char* source, const char* end, char* output, std::size_t capacity) {
        if (capacity == 0u) return;
        std::size_t n = 0u;
        while (source < end && n + 1u < capacity) output[n++] = *source++;
        output[n] = '\0';
    }

}
const char* SferaSimpleParser::lineAt(std::int32_t index) const {
    if (line_table == 0u || index < 0 || index >= static_cast<std::int32_t>(line_count)) return nullptr;
    return ptr32<const char>(ptr32<const std::uint32_t>(line_table)[index]);
}
void SferaSimpleParser::release() {
    std::free(ptr32<void>(source_begin));
    source_begin = 0u;
    source_end = 0u;
    std::free(ptr32<void>(line_table));
    line_count = 0u;
    line_table = 0u;
}
void SferaSimpleParser::rebuildLineTable() {
    if (source_begin == 0u) return;
    std::free(ptr32<void>(line_table));
    line_table = 0u;
    line_count = 0u;
    for (std::uint32_t cursor = source_begin; cursor < source_end; ++cursor) if (*ptr32<const std::uint8_t>(cursor) == '\r') ++line_count;
    ++line_count;
    const std::uint64_t bytes64 = (static_cast<std::uint64_t>(line_count) + 1u) * 4u;
    const std::uint32_t bytes = bytes64 > std::numeric_limits<std::uint32_t>::max() ? std::numeric_limits<std::uint32_t>::max() : static_cast<std::uint32_t>(bytes64);
    line_table = address32(std::calloc(1u, bytes));
    if (line_table == 0u) {
        line_count = 0u;
        return;
    }
    auto* lines = ptr32<std::uint32_t>(line_table);
    lines[0] = source_begin;
    std::uint32_t line = 1u;
    for (std::uint32_t cursor = source_begin; cursor < source_end; ++cursor) if (*ptr32<std::uint8_t>(cursor) == '\r') {
        *ptr32<std::uint8_t>(cursor) = 0u;
        lines[line++] = cursor + 2u;
    }
    scan_begin = 0;
    scan_end = static_cast<std::int32_t>(line_count);
    block_begin = 0;
    block_end = static_cast<std::int32_t>(line_count);
}
void SferaSimpleParser::load(const char* filename) {
    release();
    if (filename == nullptr || *filename == '\0') return;
    std::ifstream stream;
    for (const std::string& path : g_sfera_files.candidatePaths(filename)) { stream.open(path, std::ios::binary | std::ios::ate); if (stream.is_open()) break; stream.clear(); }
    if (!stream.is_open()) return;
    const std::streampos end_position = stream.tellg();
    if (end_position <= std::streampos(0)) return;
    const std::streamoff file_length = end_position - std::streampos(0);
    if (file_length <= 0 || static_cast<std::uint64_t>(file_length) > std::numeric_limits<std::uint32_t>::max() - 10ull) return;
    const std::uint32_t length = static_cast<std::uint32_t>(file_length);
    source_begin = address32(std::calloc(1u, static_cast<std::size_t>(length) + 10u));
    if (source_begin == 0u) return;
    stream.seekg(0, std::ios::beg);
    stream.read(ptr32<char>(source_begin), static_cast<std::streamsize>(length));
    const std::streamsize read_count = stream.gcount();
    if (read_count <= 0) {
        release();
        return;
    }
    source_end = source_begin + static_cast<std::uint32_t>(read_count);
    *ptr32<std::uint8_t>(source_end) = 0u;
    rebuildLineTable();
}
const char* SferaSimpleParser::firstToken(const char* line) const {
    if (line == nullptr) return nullptr;
    const char* end = line + std::strlen(line);
    const char* cursor = line;
    while (cursor < end && simple_parser_whitespace(*cursor)) ++cursor;
    if (cursor >= end || (cursor[0] == '/' && cursor + 1 < end && cursor[1] == '/')) return nullptr;
    return cursor;
}
std::int32_t SferaSimpleParser::findClosingBrace(std::int32_t begin, std::int32_t end) const {
    if (line_table == 0u) return -1;
    if (end > static_cast<std::int32_t>(line_count)) end = static_cast<std::int32_t>(line_count);
    if (begin < 0) begin = 0;
    std::int32_t depth = 1;
    for (std::int32_t line_index = begin; line_index < end; ++line_index) {
        const char* cursor = firstToken(lineAt(line_index));
        if (cursor == nullptr) continue;
        for (; *cursor != '\0'; ++cursor) {
            if (cursor[0] == '/' && cursor[1] == '/') break;
            if (*cursor == '{') ++depth;
            else if (*cursor == '}' && --depth == 0) return line_index;
        }
    }
    return -1;
}
std::int32_t SferaSimpleParser::parseBlockAt(const char* first_token, std::int32_t line_index, std::int32_t end, SferaParserRange* output_range) {
    if (first_token == nullptr) return -1;
    if (end > static_cast<std::int32_t>(line_count)) end = static_cast<std::int32_t>(line_count);
    if (line_index >= end) return -1;
    const char* line_end = first_token + std::strlen(first_token);
    if (first_token == line_end) return -1;
    const char* cursor = first_token;
    std::size_t n = 0u;
    while (cursor < line_end && !simple_parser_whitespace(*cursor)) {
        if (n + 1u >= sizeof(token)) return -1;
        token[n++] = *cursor++;
    }
    token[n] = '\0';
    std::int32_t open_line = line_index;
    bool found_open = false;
    for (const char* search = cursor; search < line_end; ++search) if (*search == '{') {
        found_open = true;
        break;
    }
    if (!found_open) {
        open_line = line_index + 1;
        while (open_line < end) {
            const char* next = firstToken(lineAt(open_line));
            if (next == nullptr) {
                ++open_line;
                continue;
            }
            if (*next != '{') return -1;
            found_open = true;
            break;
        }
    }
    if (!found_open) return -1;
    const std::int32_t close_line = findClosingBrace(open_line + 1, end);
    if (close_line < 0) return -1;
    if (output_range != nullptr) {
        output_range->begin = open_line + 1;
        output_range->end = close_line + 1;
    }
    return close_line - open_line + 1;
}
bool SferaSimpleParser::findBlock(const char* name, SferaParserRange* output_range, const SferaParserRange* search_range, std::int32_t occurrence) {
    if (name == nullptr || output_range == nullptr || line_table == 0u) return false;
    std::int32_t begin = search_range ? search_range->begin : 0;
    std::int32_t end = search_range ? search_range->end : static_cast<std::int32_t>(line_count);
    if (end > static_cast<std::int32_t>(line_count)) end = static_cast<std::int32_t>(line_count);
    if (begin < 0) begin = 0;
    std::int32_t matched = 0;
    for (std::int32_t line_index = begin; line_index < end;) {
        const char* first = firstToken(lineAt(line_index));
        if (first == nullptr) {
            ++line_index;
            continue;
        }
        if (parseBlockAt(first, line_index, end, output_range) < 0) {
            ++line_index;
            continue;
        }
        if (equalsIgnoreCase(token, name) && ++matched == occurrence) return true;
        line_index = output_range->end;
    }
    return false;
}
std::int32_t SferaSimpleParser::countBlocks(const char* name, const SferaParserRange* search_range) {
    if (name == nullptr || line_table == 0u) return 0;
    std::int32_t begin = search_range ? search_range->begin : 0;
    std::int32_t end = search_range ? search_range->end : static_cast<std::int32_t>(line_count);
    if (end > static_cast<std::int32_t>(line_count)) end = static_cast<std::int32_t>(line_count);
    if (begin < 0) begin = 0;
    std::int32_t count = 0;
    SferaParserRange range{};
    for (std::int32_t line_index = begin; line_index < end;) {
        const char* first = firstToken(lineAt(line_index));
        if (first == nullptr) {
            ++line_index;
            continue;
        }
        if (parseBlockAt(first, line_index, end, &range) < 0) {
            ++line_index;
            continue;
        }
        if (equalsIgnoreCase(token, name)) ++count;
        line_index = range.end;
    }
    return count;
}
bool SferaSimpleParser::findValue(const char* name, const SferaParserRange* search_range) {
    if (name == nullptr || line_table == 0u) return false;
    std::int32_t line_index = search_range ? search_range->begin : 0;
    std::int32_t end = search_range ? search_range->end : static_cast<std::int32_t>(line_count);
    if (end > static_cast<std::int32_t>(line_count)) end = static_cast<std::int32_t>(line_count);
    if (line_index < 0) line_index = 0;
    while (line_index < end) {
        const char* line = lineAt(line_index);
        const char* first = firstToken(line);
        if (first == nullptr) {
            ++line_index;
            continue;
        }
        const std::int32_t block_span = parseBlockAt(first, line_index, end, nullptr);
        if (block_span >= 0) {
            line_index += block_span + 1;
            continue;
        }
        const char* line_end = line + std::strlen(line);
        const char* cursor = first;
        std::size_t n = 0u;
        while (cursor < line_end && !simple_parser_whitespace(*cursor)) {
            if (n + 1u < sizeof(token)) token[n++] = *cursor;
            ++cursor;
        }
        token[n] = '\0';
        if (equalsIgnoreCase(token, name)) {
            simple_parser_copy_rest(cursor, line_end, token, sizeof(token));
            return true;
        }
        ++line_index;
    }
    return false;
}
void SferaSimpleParser::setScanRange(const SferaParserRange* range) {
    if (range == nullptr) {
        scan_begin = 0;
        scan_end = static_cast<std::int32_t>(line_count);
        return;
    }
    scan_begin = range->begin;
    scan_end = range->end;
    if (scan_end > static_cast<std::int32_t>(line_count)) scan_end = static_cast<std::int32_t>(line_count);
    if (scan_begin < 0) scan_begin = 0;
}
void SferaSimpleParser::clearScanRange() {
    scan_begin = 0;
    scan_end = 0;
}
bool SferaSimpleParser::nextValue(const char* name) {
    if (name == nullptr || line_table == 0u || scan_begin >= scan_end) return false;
    std::int32_t line_index = scan_begin;
    while (line_index < scan_end) {
        const char* line = lineAt(line_index);
        const char* first = firstToken(line);
        if (first == nullptr) {
            ++line_index;
            continue;
        }
        const std::int32_t block_span = parseBlockAt(first, line_index, scan_end, nullptr);
        if (block_span >= 0) {
            line_index += block_span + 1;
            continue;
        }
        const char* line_end = line + std::strlen(line);
        const char* cursor = first;
        std::size_t n = 0u;
        while (cursor < line_end && !simple_parser_whitespace(*cursor)) {
            if (n + 1u < sizeof(token)) token[n++] = *cursor;
            ++cursor;
        }
        token[n] = '\0';
        if (equalsIgnoreCase(token, name)) {
            simple_parser_copy_rest(cursor, line_end, token, sizeof(token));
            scan_begin = line_index + 1;
            return true;
        }
        ++line_index;
    }
    return false;
}
std::uint32_t SferaSimpleParser::tokenCount() const {
    const char* cursor = token;
    const char* end = token + std::strlen(token);
    std::uint32_t count = 0u;
    while (cursor < end) {
        while (cursor < end && simple_parser_whitespace(*cursor)) ++cursor;
        if (cursor >= end || (cursor[0] == '/' && cursor[1] == '/')) break;
        ++count;
        while (cursor < end && !simple_parser_whitespace(*cursor)) {
            if (cursor[0] == '/' && cursor[1] == '/') return count;
            ++cursor;
        }
    }
    return count;
}
void SferaSimpleParser::setBlockRange(const SferaParserRange* range) {
    if (range == nullptr) {
        block_begin = 0;
        block_end = static_cast<std::int32_t>(line_count);
        return;
    }
    block_begin = range->begin;
    block_end = range->end;
    if (block_end > static_cast<std::int32_t>(line_count)) block_end = static_cast<std::int32_t>(line_count);
    if (block_begin < 0) block_begin = 0;
}
void SferaSimpleParser::clearBlockRange() {
    block_begin = 0;
    block_end = 0;
}
bool SferaSimpleParser::nextBlock(const char* name, SferaParserRange* output_range) {
    SferaParserRange range{block_begin, block_end};
    if (!findBlock(name, output_range, &range, 1)) return false;
    block_begin = output_range->end;
    return true;
}
void SferaSimpleParser::getBlockRange(SferaParserRange* output_range) const {
    output_range->begin = block_begin;
    output_range->end = block_end;
}
void SferaSimpleParser::getScanRange(SferaParserRange* output_range) const {
    output_range->begin = scan_begin;
    output_range->end = scan_end;
}
const char* SferaSimpleParser::tokenAt(std::uint32_t index) const {
    const char* cursor = token;
    const char* end = token + std::strlen(token);
    std::uint32_t current = 0u;
    while (cursor < end) {
        if (cursor[0] == '/' && cursor[1] == '/') return nullptr;
        while (cursor < end && simple_parser_whitespace(*cursor)) ++cursor;
        if (cursor >= end || (cursor[0] == '/' && cursor[1] == '/')) return nullptr;
        if (current == index) return cursor;
        while (cursor < end && !simple_parser_whitespace(*cursor)) ++cursor;
        ++current;
    }
    return nullptr;
}
bool SferaSimpleParser::tryReadFloat(std::uint32_t index, float& output) const {
    const char* value_text = tokenAt(index);
    if (value_text == nullptr) return false;
    char* parse_end = nullptr;
    const float parsed = std::strtof(value_text, &parse_end);
    if (parse_end == value_text) return false;
    output = parsed;
    return true;
}
bool SferaSimpleParser::tryReadInt(std::uint32_t index, std::int32_t& output) const {
    const char* value_text = tokenAt(index);
    if (value_text == nullptr) return false;
    char* parse_end = nullptr;
    const long parsed = std::strtol(value_text, &parse_end, 10);
    if (parse_end == value_text) return false;
    output = static_cast<std::int32_t>(parsed);
    return true;
}
bool SferaSimpleParser::readFloatSequence(std::uint32_t index, float* output, std::size_t count) const {
    for (std::size_t offset = 0u; offset < count; ++offset) if (!tryReadFloat(index + static_cast<std::uint32_t>(offset), output[offset])) return false;
    return true;
}
bool SferaSimpleParser::readIntSequence(std::uint32_t index, std::int32_t* output, std::size_t count) const {
    for (std::size_t offset = 0u; offset < count; ++offset) if (!tryReadInt(index + static_cast<std::uint32_t>(offset), output[offset])) return false;
    return true;
}
float SferaSimpleParser::readFloat(std::uint32_t index) const {
    if (tokenAt(index) == nullptr) return 0.0f;
    float output = std::bit_cast<float>(index);
    tryReadFloat(index, output);
    return output;
}
std::int32_t SferaSimpleParser::readInt(std::uint32_t index) const {
    if (tokenAt(index) == nullptr) return 0;
    std::int32_t output = static_cast<std::int32_t>(index);
    tryReadInt(index, output);
    return output;
}
char* SferaSimpleParser::readString(std::uint32_t index, char* output) const {
    const char* value_text = tokenAt(index);
    if (value_text == nullptr) return nullptr;
    return simple_parser_copy_token(value_text, output);
}
char* SferaSimpleParser::readStringBounded(std::uint32_t index, char* output, std::size_t capacity) const {
    const char* value_text = tokenAt(index);
    if (value_text == nullptr || output == nullptr || capacity == 0u) return nullptr;
    simple_parser_copy_token_bounded(value_text, output, capacity);
    return output;
}
char* SferaSimpleParser::readQuotedString(std::uint32_t index, char* output) const {
    const char* value_text = tokenAt(index);
    if (value_text == nullptr || *value_text != '"') return nullptr;
    ++value_text;
    char* cursor = output;
    const char* end = token + std::strlen(token);
    while (value_text < end && *value_text != '"') *cursor++ = *value_text++;
    *cursor = '\0';
    return output;
}
bool SferaSimpleParser::readBool(std::uint32_t index) const {
    const char* value_text = tokenAt(index);
    if (value_text == nullptr) return false;
    char parsed[1024]{};
    simple_parser_copy_token_bounded(value_text, parsed, sizeof(parsed));
    if (parsed[0] == '\0') return false;
    if (parsed[0] == '1') return true;
    return equalsIgnoreCase(parsed, "true");
}
bool SferaSimpleParser::equalsIgnoreCase(const char* left, const char* right) {
    if (left == nullptr || right == nullptr) return false;
    while (*left != '\0' && *right != '\0') {
        const auto fold = [](unsigned char value) {
            return value >= 'A' && value <= 'Z' ? static_cast<unsigned char>(value + ('a' - 'A')) : value;
        };
        if (fold(static_cast<unsigned char>(*left)) != fold(static_cast<unsigned char>(*right))) return false;
        ++left;
        ++right;
    }
    return *left == *right;
}
namespace {
    SferaEffectTrack* allocate_effect_track(std::uint32_t key_count) {
        auto* track = static_cast<SferaEffectTrack*>(std::calloc(1u, sizeof(SferaEffectTrack)));
        if (track != nullptr) {
            track->initialize();
            track->allocateKeys(key_count);
        }
        return track;
    }
    bool parse_track_index(SferaSimpleParser* parser, std::int32_t& index) {
        return parser->tryReadInt(0u, index);
    }
    void parse_scalar_key(SferaSimpleParser* parser, std::int32_t& index, SferaEffectTrackKey& key, bool random) {
        if (!parse_track_index(parser, index)) return;
        if (!parser->tryReadFloat(1u, key.time)) return;
        if (!parser->tryReadFloat(2u, key.scalar_min)) return;
        if (random) parser->tryReadFloat(3u, key.scalar_max);
    }
    void parse_vector_key(SferaSimpleParser* parser, std::int32_t& index, SferaEffectTrackKey& key, bool random) {
        if (!parse_track_index(parser, index)) return;
        if (!parser->tryReadFloat(1u, key.time)) return;
        if (!parser->tryReadFloat(2u, key.vector_min[0])) return;
        if (!parser->tryReadFloat(3u, key.vector_min[1])) return;
        if (!parser->tryReadFloat(4u, key.vector_min[2])) return;
        if (!random) return;
        if (!parser->tryReadFloat(5u, key.vector_max[0])) return;
        if (!parser->tryReadFloat(6u, key.vector_max[1])) return;
        parser->tryReadFloat(7u, key.vector_max[2]);
    }
}
void SferaEffectTrack::initialize() {
    keys = 0u;
    key_count = 0u;
    state = 0u;
}
void SferaEffectTrack::release() {
    std::free(ptr32<void>(keys));
    keys = 0u;
    key_count = 0u;
    state = 0u;
}
void SferaEffectTrack::allocateKeys(std::uint32_t count) {
    std::free(ptr32<void>(keys));
    keys = 0u;
    key_count = 0u;
    if (count == 0u) return;
    const std::uint64_t bytes64 = static_cast<std::uint64_t>(count) * sizeof(SferaEffectTrackKey);
    if (bytes64 > static_cast<std::uint64_t>(SIZE_MAX)) return;
    keys = address32(std::calloc(1u, static_cast<std::size_t>(bytes64)));
    if (keys != 0u) key_count = count;
}
void SferaEffectTrack::setKey(std::uint32_t index, const SferaEffectTrackKey& key) {
    std::memmove(ptr32<void>(keys + index * sizeof(SferaEffectTrackKey)), &key, sizeof(key));
}
void SferaEffectTrack::evaluateVector(float age, SferaEffectVec3F& output) const {
    output = {};
    if (keys == 0u || key_count == 0u) return;
    const auto* data = ptr32<const SferaEffectTrackKey>(keys);
    if (key_count == 1u) {
        output = {data[0].vector_min[0], data[0].vector_min[1], data[0].vector_min[2]};
        return;
    }
    const SferaEffectTrackKey& last = data[key_count - 1u];
    if (age >= last.time) {
        output = {last.vector_min[0], last.vector_min[1], last.vector_min[2]};
        return;
    }
    std::uint32_t index = 0u;
    for (std::uint32_t candidate = key_count - 1u; candidate > 0u; --candidate) if (data[candidate].time <= age) {
        index = candidate;
        break;
    }
    const SferaEffectTrackKey& begin = data[index];
    const SferaEffectTrackKey& end = data[index + 1u];
    const float duration = end.time - begin.time;
    float factor = duration == 0.0f ? 0.0f : (age - begin.time) / duration;
    if ((state & 1u) != 0u) factor = (1.0f - std::cos(factor * 3.1415929794311523f)) * 0.5f;
    output.x = begin.vector_min[0] + (end.vector_min[0] - begin.vector_min[0]) * factor;
    output.y = begin.vector_min[1] + (end.vector_min[1] - begin.vector_min[1]) * factor;
    output.z = begin.vector_min[2] + (end.vector_min[2] - begin.vector_min[2]) * factor;
}
void SferaEffectTrack::evaluateScalar(float age, float& output, const std::uint16_t* random_values, std::uint32_t random_offset) const {
    output = 0.0f;
    if (keys == 0u || key_count == 0u) return;
    const auto* data = ptr32<const SferaEffectTrackKey>(keys);
    const auto sample = [&](const SferaEffectTrackKey& key, std::uint32_t index) {
        if ((key.mode & 1u) == 0u || random_values == nullptr) return key.scalar_min;
        const float random = static_cast<float>(random_values[index] + random_offset) * 1.5259021893143654e-05f;
        return key.scalar_min + random * key.scalar_max;
    };
    if (key_count == 1u) {
        output = sample(data[0], 0u);
        return;
    }
    const SferaEffectTrackKey& last = data[key_count - 1u];
    if (age >= last.time) {
        output = sample(last, key_count - 1u);
        return;
    }
    std::uint32_t index = 0u;
    for (std::uint32_t candidate = key_count - 1u; candidate > 0u; --candidate) if (data[candidate].time <= age) {
        index = candidate;
        break;
    }
    const SferaEffectTrackKey& begin = data[index];
    const SferaEffectTrackKey& end = data[index + 1u];
    const float duration = end.time - begin.time;
    const float factor = duration == 0.0f ? 0.0f : (age - begin.time) / duration;
    const float begin_value = sample(begin, index);
    output = begin_value + (sample(end, index + 1u) - begin_value) * factor;
}
SferaEffectTrack* sfera_load_scalar_effect_track(SferaSimpleParser* parser, const SferaParserRange* range) {
    if (!parser->findValue("numkeys", range)) return nullptr;
    const std::int32_t count = parser->readInt(0u);
    if (count <= 0) return nullptr;
    SferaEffectTrack* track = allocate_effect_track(static_cast<std::uint32_t>(count));
    SferaEffectTrackKey key{};
    std::int32_t index = 0;
    parser->setScanRange(range);
    while (parser->nextValue("key")) {
        parse_scalar_key(parser, index, key, false);
        key.mode = 0u;
        track->setKey(static_cast<std::uint32_t>(index), key);
    }
    parser->setScanRange(range);
    while (parser->nextValue("rkey")) {
        parse_scalar_key(parser, index, key, true);
        key.mode = 1u;
        track->setKey(static_cast<std::uint32_t>(index), key);
    }
    parser->clearScanRange();
    return track;
}
SferaEffectTrack* sfera_load_vector_effect_track(SferaSimpleParser* parser, const SferaParserRange* range) {
    if (!parser->findValue("numkeys", range)) return nullptr;
    const std::int32_t count = parser->readInt(0u);
    if (count <= 0) return nullptr;
    SferaEffectTrack* track = allocate_effect_track(static_cast<std::uint32_t>(count));
    SferaEffectTrackKey key{};
    std::int32_t index = 0;
    parser->setScanRange(range);
    while (parser->nextValue("key")) {
        parse_vector_key(parser, index, key, false);
        key.mode = 0u;
        track->setKey(static_cast<std::uint32_t>(index), key);
    }
    parser->setScanRange(range);
    while (parser->nextValue("rkey")) {
        parse_vector_key(parser, index, key, true);
        key.mode = 1u;
        track->setKey(static_cast<std::uint32_t>(index), key);
    }
    parser->setScanRange(range);
    while (parser->nextValue("mrkey")) {
        parse_vector_key(parser, index, key, true);
        key.mode = 2u;
        track->setKey(static_cast<std::uint32_t>(index), key);
    }
    parser->clearScanRange();
    return track;
}
void SferaLightDefinition::initializeDefaults() {
    position_track = 0u;
    color_track = 0u;
    alpha_track = 0u;
    light_index = -1;
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 0.0f;
    color[0] = 255.0f;
    color[1] = 255.0f;
    color[2] = 255.0f;
    color[3] = 255.0f;
    field_2c = 0u;
    field_30 = 0u;
    flags = 0u;
    brightness = 1.0f;
    brightness_delta = 0.0f;
    brightness_frequency = 1u;
    field_5c = 0u;
    attach_mode = 0u;
}
bool SferaLightDefinition::load(SferaSimpleParser& parser, const SferaParserRange& range) {
    SferaParserRange previous_block_range{};
    parser.getBlockRange(&previous_block_range);
    if (parser.findValue("light_pos", &range)) parser.readFloatSequence(0u, &position.x, 3u);
    if (parser.findValue("light_color", &range)) parser.readFloatSequence(0u, color, 4u);
    if (parser.findValue("random_color", &range)) {
        parser.readIntSequence(0u, random_color, 6u);
        flags |= 1u;
    }
    if (parser.findValue("brightness", &range)) {
        parser.readFloatSequence(0u, &brightness, 2u);
        flags |= 2u;
    }
    if (parser.findValue("brightFreq", &range)) brightness_frequency = static_cast<std::uint8_t>(parser.readInt(0u));
    char attach_name[512]{};
    if (parser.findValue("attach", &range) && parser.readStringBounded(0u, attach_name, sizeof(attach_name)) != nullptr) {
        if (SferaSimpleParser::equalsIgnoreCase(attach_name, "ATTACH_LEFTHAND")) attach_mode = 1u;
        else if (SferaSimpleParser::equalsIgnoreCase(attach_name, "ATTACH_RIGHTHAND")) attach_mode = 2u;
        else if (SferaSimpleParser::equalsIgnoreCase(attach_name, "ATTACH_BETWEENHANDS")) attach_mode = 3u;
    }
    SferaParserRange track_range{};
    if (parser.findBlock("color_track", &track_range, &range, 1)) color_track = address32(sfera_load_vector_effect_track(&parser, &track_range));
    if (parser.findBlock("alpha_track", &track_range, &range, 1)) alpha_track = address32(sfera_load_scalar_effect_track(&parser, &track_range));
    if (parser.findBlock("position_track", &track_range, &range, 1)) position_track = address32(sfera_load_vector_effect_track(&parser, &track_range));
    field_30 = 0u;
    parser.setBlockRange(&previous_block_range);
    return true;
}
void SferaLightDefinition::update(const SferaEffectVec3F& base_position, float age, std::uint32_t opacity) {
    if (field_30 == 0u || light_index == -1) {
        g_sfera_light_runtime.release(light_index);
        light_index = g_sfera_light_runtime.create(position, color, 0.0f);
        if (light_index == -1) return;
    }
    field_30 = 1u;
    if (position_track != 0u) ptr32<SferaEffectTrack>(position_track)->evaluateVector(age, position);
    if (color_track != 0u) {
        SferaEffectVec3F sampled{};
        ptr32<SferaEffectTrack>(color_track)->evaluateVector(age, sampled);
        color[0] = sampled.x;
        color[1] = sampled.y;
        color[2] = sampled.z;
    }
    if (alpha_track != 0u) ptr32<SferaEffectTrack>(alpha_track)->evaluateScalar(age, color[3], ptr32<const std::uint16_t>(g_sfera_effect_manager.particle_random_table));
    SferaEffectVec3F world_position{base_position.x + position.x, base_position.y + position.y, base_position.z + position.z};
    if ((flags & 1u) != 0u) {
        constexpr float random_scale = 3.0518509447574615e-05f;
        for (std::uint32_t channel = 0u; channel < 3u; ++channel) color[channel] = static_cast<float>(random_color[channel]) + static_cast<float>(std::rand()) * random_scale * static_cast<float>(random_color[channel + 3u]);
    }
    const float opacity_scale = static_cast<float>(opacity) * 0.00390625f;
    float output_color[4]{color[0] * opacity_scale, color[1] * opacity_scale, color[2] * opacity_scale, color[3] * opacity_scale};
    if ((flags & 2u) != 0u && brightness_frequency != 0u && field_5c % brightness_frequency == 0u) {
        constexpr float random_scale = 3.0518509447574615e-05f;
        const float brightness_scale = brightness + static_cast<float>(std::rand()) * random_scale * brightness_delta;
        output_color[0] *= brightness_scale;
        output_color[1] *= brightness_scale;
        output_color[2] *= brightness_scale;
    }
    ++field_5c;
    g_sfera_light_runtime.write(light_index, world_position, output_color, 0.0f);
}
void SferaLightDefinition::release() {
    if (field_2c == 0u) {
        std::uint32_t* tracks[] = {&position_track, &color_track, &alpha_track};
        for (std::uint32_t* address : tracks) {
            auto* track = ptr32<SferaEffectTrack>(*address);
            if (track != nullptr) {
                track->release();
                g_sfera_effect_manager.free(track);
                *address = 0u;
            }
        }
    }
    g_sfera_light_runtime.release(light_index);
    light_index = -1;
}
namespace {
    template <class T> T* allocate_counted_array(std::uint32_t count) {
        if (count == 0u) return nullptr;
        const std::uint64_t payload = static_cast<std::uint64_t>(count) * sizeof(T);
        if (payload + sizeof(std::uint32_t) > std::numeric_limits<std::uint32_t>::max()) return nullptr;
        auto* allocation = static_cast<std::uint8_t*>(g_sfera_effect_manager.allocate(static_cast<std::size_t>(payload + sizeof(std::uint32_t))));
        if (allocation == nullptr) return nullptr;
        *reinterpret_cast<std::uint32_t*>(allocation) = count;
        auto* data = reinterpret_cast<T*>(allocation + sizeof(std::uint32_t));
        std::memset(data, 0, static_cast<std::size_t>(payload));
        return data;
    }
    template <class T> void free_counted_array(T*& data) {
        if (data == nullptr) return;
        g_sfera_effect_manager.free(reinterpret_cast<std::uint8_t*>(data) - sizeof(std::uint32_t));
        data = nullptr;
    }
    void initialize_scripted_phase(CScriptedEffect& effect) {
        effect.work_phase = 0u;
        effect.phase_ticks_remaining = 0u;
        if (effect.work_time_min == std::numeric_limits<std::uint32_t>::max()) return;
        if ((std::rand() & 1) == 0) effect.work_phase = 1u;
        const std::uint32_t duration = effect.work_phase == 0u ? effect.work_time_max : effect.sleep_time_max;
        if (duration != 0u) effect.phase_ticks_remaining = static_cast<std::uint32_t>(std::rand()) % duration;
    }
    SferaEffectVec3F vec_add(const SferaEffectVec3F& a, const SferaEffectVec3F& b) {
        return {a.x + b.x, a.y + b.y, a.z + b.z};
    }
    SferaEffectVec3F vec_sub(const SferaEffectVec3F& a, const SferaEffectVec3F& b) {
        return {a.x - b.x, a.y - b.y, a.z - b.z};
    }
    SferaEffectVec3F vec_scale(const SferaEffectVec3F& value, float scale) {
        return {value.x * scale, value.y * scale, value.z * scale};
    }
    SferaEffectVec3F vec_cross(const SferaEffectVec3F& a, const SferaEffectVec3F& b) {
        return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
    }
    float vec_length(const SferaEffectVec3F& value) {
        return std::sqrt(value.x * value.x + value.y * value.y + value.z * value.z);
    }
    SferaEffectVec3F vec_normalized(const SferaEffectVec3F& value, const SferaEffectVec3F& fallback = {}) {
        const float length = vec_length(value);
        return length == 0.0f ? fallback : vec_scale(value, 1.0f / length);
    }
    void build_y_up_billboard_axes(const SferaEffectVec3F& view, float right_scale, float up_scale, SferaEffectVec3F& right, SferaEffectVec3F& up) {
        right = {view.z, 0.0f, -view.x};
        float length = vec_length(right);
        right = length <= 0.00001f ? SferaEffectVec3F{1.0f, 0.0f, 0.0f} : vec_scale(right, 1.0f / length);
        up = vec_cross(right, view);
        length = vec_length(up);
        up = length <= 0.00001f ? SferaEffectVec3F{0.0f, 0.0f, 1.0f} : vec_scale(up, 1.0f / length);
        right = vec_scale(right, right_scale);
        up = vec_scale(up, up_scale);
    }
    void set_full_quad_uv(SferaEffectRenderSlot& slot) {
        slot.uv[0][0] = 0.0f; slot.uv[0][1] = 0.0f;
        slot.uv[1][0] = 1.0f; slot.uv[1][1] = 0.0f;
        slot.uv[2][0] = 1.0f; slot.uv[2][1] = 1.0f;
        slot.uv[3][0] = 0.0f; slot.uv[3][1] = 1.0f;
    }
    float random_signed(float scale) {
        constexpr float random_scale = 3.0518509447574615e-05f;
        return static_cast<float>(std::rand() - std::rand()) * random_scale * scale;
    }
    void initialize_quad_slot(SferaEffectRenderSlot& slot, std::int32_t resource_id, std::uint32_t primitive_kind, std::uint32_t alpha) {
        slot.resource_id = resource_id;
        slot.blend_mode = alpha;
        slot.primitive_kind = primitive_kind;
        for (std::uint32_t vertex = 0u; vertex < 4u; ++vertex) {
            slot.color[0][vertex] = 255u;
            slot.color[1][vertex] = 255u;
            slot.color[2][vertex] = 255u;
            slot.color[3][vertex] = alpha;
        }
    }

    bool bloodTriangleOverlaps(const SferaEffectVec3F* triangle, const SferaEffectVec3F& center, float radius) {
        float min_x = triangle[0].x, min_y = triangle[0].y, min_z = triangle[0].z, max_x = min_x, max_y = min_y, max_z = min_z;
        for (std::uint32_t i = 1u; i < 3u; ++i) {
            min_x = std::min(min_x, triangle[i].x); min_y = std::min(min_y, triangle[i].y); min_z = std::min(min_z, triangle[i].z);
            max_x = std::max(max_x, triangle[i].x); max_y = std::max(max_y, triangle[i].y); max_z = std::max(max_z, triangle[i].z);
        }
        return max_x >= center.x - radius && min_x <= center.x + radius && max_z >= center.z - radius && min_z <= center.z + radius && max_y >= center.y - 1.8f && min_y <= center.y + 1.5f;
    }
    std::uint32_t collectBloodSceneTriangles(const SferaEffectVec3F& center, float radius) {
        auto* points = ptr32<SferaEffectVec3F>(g_sfera_scene_array_runtime.scene_points.data);
        if (points == nullptr || g_sfera_scene_array_runtime.scene_points.capacity < 3u) { g_sfera_main_input_state_runtime.active_input_handle = 0u; return 0u; }
        const std::uint32_t capacity_triangles = g_sfera_scene_array_runtime.scene_points.capacity / 3u;
        std::uint32_t source_triangles = g_sfera_main_input_state_runtime.active_input_handle;
        if (source_triangles == 0u || source_triangles > capacity_triangles) source_triangles = capacity_triangles;
        std::uint32_t output = 0u;
        for (std::uint32_t index = 0u; index < source_triangles && output < 30u; ++index) {
            const auto* triangle = points + index * 3u;
            if (!std::isfinite(triangle[0].x) || !std::isfinite(triangle[0].y) || !std::isfinite(triangle[0].z) || !bloodTriangleOverlaps(triangle, center, radius)) continue;
            if (output != index) std::memmove(points + output * 3u, triangle, 3u * sizeof(SferaEffectVec3F));
            ++output;
        }
        g_sfera_main_input_state_runtime.active_input_handle = output;
        return output;
    }
    void createBloodSpot(SferaBloodEffectRuntime& runtime, const SferaEffectVec3F& origin, const SferaEffectVec3F* scene_points, std::uint32_t triangle_count) {
        if (runtime.active_count >= 30u || scene_points == nullptr || triangle_count == 0u) return;
        SferaBloodSpot* spot = nullptr;
        for (auto& candidate : runtime.spots) if (candidate.life == 0.0f) { spot = &candidate; break; }
        if (spot == nullptr) return;
        triangle_count = std::min(triangle_count, 30u);
        spot->life = 1.0f; spot->vertex_count = triangle_count * 3u;
        const float angle = static_cast<float>(std::rand()) * (1.0f / 32768.0f) * 6.2831853071795864769f;
        const float scale = static_cast<float>(std::rand()) * (1.0f / 32768.0f) * 2.0f + 2.0f;
        const float cosine = std::cos(angle), sine = std::sin(angle);
        const float ux = scale * cosine, uz = scale * sine, vx = -scale * sine, vz = scale * cosine;
        for (std::uint32_t index = 0u; index < spot->vertex_count; ++index) {
            const auto& source = scene_points[index]; auto& target = spot->vertices[index];
            target.position = source; target.diffuse_color = 0u; target.specular_color = 0u;
            const float dx = source.x - origin.x, dz = source.z - origin.z;
            target.u = dx * ux + dz * uz + 0.5f; target.v = dx * vx + dz * vz + 0.5f;
        }
        ++runtime.active_count;
    }

}
bool BloodEffListener::onEffectAttached(IEffect&, SferaActiveEffect&, float distance) {
    return distance <= 15.0f;
}
bool BloodEffListener::onEffectDetached(IEffect&, SferaActiveEffect&) {
    return true;
}
void BloodEffListener::onEffectChanged(std::uint32_t age_ticks, IEffect& effect, SferaActiveEffect& item) {
    (void)age_ticks; (void)item;
    auto& runtime = static_cast<SferaBloodEffectRuntime&>(*this);
    if (runtime.active_count >= 30u || effect.effect_kind != 1u) return;
    auto& scripted = static_cast<CScriptedEffect&>(effect);
    if (scripted.particle_system_definition_count == 0u || scripted.particle_system_definitions == nullptr) return;
    auto& particles = scripted.particle_system_definitions[0];
    if (particles.render_slots == nullptr || particles.render_slot_count == 0u) return;
    const std::uint32_t requested = static_cast<std::uint32_t>(std::rand()) % 3u + 4u;
    std::array<SferaEffectVec3F, 6> origins{};
    std::uint32_t selected = 0u; float radius = 0.0f;
    for (std::uint32_t index = 0u; index < particles.render_slot_count && selected < requested; ++index) {
        const auto& slot = particles.render_slots[index];
        if (slot.remaining_lifetime <= 0.0f) continue;
        auto& origin = origins[selected++];
        origin = {slot.render_position.x, effect.position.y - 0.5f, slot.render_position.z};
        const float dx = origin.x - effect.position.x, dy = origin.y - effect.position.y, dz = origin.z - effect.position.z;
        radius = std::max(radius, std::sqrt(dx * dx + dy * dy + dz * dz));
    }
    if (selected != requested) return;
    const std::uint32_t triangle_count = collectBloodSceneTriangles(effect.position, radius + 0.2f);
    if (triangle_count == 0u) return;
    const auto* scene_points = ptr32<const SferaEffectVec3F>(g_sfera_scene_array_runtime.scene_points.data);
    for (std::uint32_t index = 0u; index < selected && runtime.active_count < 30u; ++index) createBloodSpot(runtime, origins[index], scene_points, triangle_count);
}
void SferaEffectMeshResource::release() {
    g_sfera_effect_manager.free(vertices); g_sfera_effect_manager.free(uv); g_sfera_effect_manager.free(face_vertices); g_sfera_effect_manager.free(face_uv);
    g_sfera_effect_manager.free(colors); g_sfera_effect_manager.free(transformed_vertices); g_sfera_effect_manager.free(translated_uv); g_sfera_effect_manager.free(transformed_colors);
    vertices = nullptr; uv = nullptr; face_vertices = nullptr; face_uv = nullptr; colors = nullptr; transformed_vertices = nullptr; translated_uv = nullptr; transformed_colors = nullptr;
}
void IEffect::assignScriptName(const char* name) {
    char* replacement = duplicate_managed_string(name);
    if (script_name != nullptr && borrows_definition_storage == 0u) g_sfera_effect_manager.free(script_name);
    script_name = replacement;
}
void IEffect::initializeBaseState(std::uint32_t kind) {
    script_name = nullptr;
    effect_id = std::numeric_limits<std::uint32_t>::max();
    borrows_definition_storage = 0u;
    deactivated = 0u;
    resources_released = 0u;
    activation_blocked = 0u;
    cycle_length = 0u;
    lifetime_ticks = 0u;
    range_min = -1.0f;
    range_max = -1.0f;
    next = nullptr;
    previous = nullptr;
    effect_kind = kind;
    listener = nullptr;
    spatial_gate_enabled = 0u;
    render_slot_budget = 0u;
}
void CScriptedEffect::initializeScriptedState() {
    initializeBaseState(1u);
    pooled_count = 0u;
    source_definition = nullptr;
    subeffects = nullptr;
    sound_started = 0u;
    update_visible_only = 1u;
    effect_type = 0u;
    sound_effect = nullptr;
    effect_mesh_definition_count = 0u;
    light_definition_count = 0u;
    subeffect_count = 0u;
    particle_system_definition_count = 0u;
    linked_particle_system_count = 0u;
    linked_render_slot_count = 0u;
    phase_ticks_remaining = 0u;
    work_time_min = std::numeric_limits<std::uint32_t>::max();
    work_time_max = 0u;
    sleep_time_min = std::numeric_limits<std::uint32_t>::max();
    sleep_time_max = 0u;
    work_phase = 0u;
    effect_mesh_definitions = nullptr;
    light_definitions = nullptr;
    particle_system_definitions = nullptr;
    linked_render_slots = nullptr;
    linked_particle_systems = nullptr;
}
std::int32_t CScriptedEffect::findEffectMeshDefinitionIndex(const char* name) const {
    if (name == nullptr || effect_mesh_definitions == nullptr) return -1;
    for (std::uint32_t index = 0u; index < effect_mesh_definition_count; ++index) {
        if (SferaSimpleParser::equalsIgnoreCase(effect_mesh_definitions[index].name, name)) return static_cast<std::int32_t>(index);
    }
    return -1;
}
std::int32_t CScriptedEffect::findParticleSystemDefinitionIndex(const char* name) const {
    if (name == nullptr || particle_system_definitions == nullptr) return -1;
    for (std::uint32_t index = 0u; index < particle_system_definition_count; ++index) if (SferaSimpleParser::equalsIgnoreCase(particle_system_definitions[index].name, name)) return static_cast<std::int32_t>(index);
    return -1;
}
bool CScriptedEffect::loadScript(const char* filename) {
    if (filename == nullptr) return false;
    SferaSimpleParser parser{};
    parser.initialize();
    parser.load(filename);
    render_slot_budget = 0u;
    const auto report_load_error = [&](const char* detail) {
        char message[768]{};
        std::snprintf(message, sizeof(message), "CScriptedEffect::LoadScript(%s) -> %s", filename, detail);
        g_sfera_effect_manager.reportError(message);
    };
    const std::int32_t mesh_count = parser.countBlocks("effectmesh_def", nullptr);
    if (mesh_count > 0) {
        effect_mesh_definition_count = static_cast<std::uint32_t>(mesh_count);
        effect_mesh_definitions = allocate_counted_array<SferaEffectMeshDefinition>(effect_mesh_definition_count);
        if (effect_mesh_definitions == nullptr) {
            parser.release();
            return false;
        }
        for (std::uint32_t index = 0u; index < effect_mesh_definition_count; ++index) effect_mesh_definitions[index].initializeDefinition();
        parser.setBlockRange(nullptr);
        SferaParserRange block{};
        std::uint32_t index = 0u;
        while (index < effect_mesh_definition_count && parser.nextBlock("effectmesh_def", &block)) {
            if (!effect_mesh_definitions[index].loadDefinition(filename, parser, block)) report_load_error("Can't load effectmesh_def block");
            else render_slot_budget += effect_mesh_definitions[index].renderSlotCount();
            ++index;
        }
        parser.clearBlockRange();
    }
    const std::int32_t particle_count = parser.countBlocks("psystem_def", nullptr);
    if (particle_count > 0) {
        particle_system_definition_count = static_cast<std::uint32_t>(particle_count);
        particle_system_definitions = allocate_counted_array<SferaParticleSystemDefinition>(particle_system_definition_count);
        if (particle_system_definitions == nullptr) {
            parser.release();
            return false;
        }
        for (std::uint32_t index = 0u; index < particle_system_definition_count; ++index) particle_system_definitions[index].initializeDefinition();
        parser.setBlockRange(nullptr);
        SferaParserRange block{};
        std::uint32_t index = 0u;
        while (index < particle_system_definition_count && parser.nextBlock("psystem_def", &block)) {
            SferaParserRange continuation{};
            parser.getBlockRange(&continuation);
            if (!particle_system_definitions[index].loadDefinition(filename, parser, block)) report_load_error("Can't load psystem_def block");
            else if (particle_system_definitions[index].link_count == 0u) render_slot_budget += particle_system_definitions[index].render_slot_count;
            parser.setBlockRange(&continuation);
            ++index;
        }
        parser.clearBlockRange();
    }
    linked_particle_system_count = 0u;
    linked_render_slot_count = 0u;
    for (std::uint32_t source_index = 0u; source_index < particle_system_definition_count; ++source_index) {
        SferaParticleSystemDefinition& definition = particle_system_definitions[source_index];
        for (std::uint32_t link_index = 0u; link_index < definition.link_count; ++link_index) {
            SferaParticleSystemLink& link = definition.links[link_index];
            const std::int32_t target_index = findParticleSystemDefinitionIndex(link.target_name);
            if (target_index < 0) continue;
            link.target_index = target_index;
            linked_particle_system_count += link.instance_count;
            linked_render_slot_count += particle_system_definitions[target_index].render_slot_count * link.instance_count;
        }
    }
    if (linked_particle_system_count != 0u && linked_render_slot_count != 0u) {
        linked_particle_systems = allocate_counted_array<SferaParticleSystemDefinition>(linked_particle_system_count);
        if (linked_particle_systems == nullptr) {
            parser.release();
            return false;
        }
        for (std::uint32_t index = 0u; index < linked_particle_system_count; ++index) linked_particle_systems[index].initializeDefinition();
        const std::uint64_t render_bytes = static_cast<std::uint64_t>(linked_render_slot_count) * sizeof(SferaParticleRenderSlot);
        if (render_bytes > std::numeric_limits<std::uint32_t>::max()) {
            parser.release();
            return false;
        }
        linked_render_slots = g_sfera_effect_manager.allocate(static_cast<std::uint32_t>(render_bytes));
        if (linked_render_slots == nullptr) {
            parser.release();
            return false;
        }
        render_slot_budget += linked_render_slot_count;
        buildLinkedParticleSystems();
    }
    SferaParserRange effect_range{};
    if (!parser.findBlock("effect_def", &effect_range, nullptr, 1)) {
        parser.release();
        return true;
    }
    char text[1024]{};
    if (parser.findValue("effect_name", &effect_range) && parser.readQuotedString(0u, text) != nullptr) assignScriptName(text);
    if (parser.findValue("effect_number", &effect_range)) effect_id = static_cast<std::uint32_t>(parser.readInt(0u));
    if (parser.findValue("effect_time", &effect_range)) {
        lifetime_ticks = static_cast<std::uint32_t>(parser.readInt(0u));
        cycle_length = lifetime_ticks;
    }
    if (parser.findValue("effect_timelimit", &effect_range)) cycle_length = static_cast<std::uint32_t>(parser.readInt(0u));
    if (parser.findValue("updvisible_only", &effect_range)) {
        update_visible_only = parser.readBool(0u) ? 1u : 0u;
        if (update_visible_only == 0u) g_sfera_effect_manager.reportError("SphereReport::Assertion failed -> File ..\\ShareClientSeverCode\\EffectManager.cpp, Line 2445");
    }
    if (parser.findValue("boundbox", &effect_range)) {
        float bounds[6]{};
        if (parser.readFloatSequence(0u, bounds, 6u)) {
            bounds_max[0] = bounds[0];
            bounds_max[1] = bounds[1];
            bounds_max[2] = bounds[2];
            bounds_min[0] = bounds[3];
            bounds_min[1] = bounds[4];
            bounds_min[2] = bounds[5];
            spatial_gate_enabled = 1u;
        }
    }
    if (parser.findValue("daytime_work", &effect_range)) {
        const float start = parser.readFloat(0u);
        const float end = parser.readFloat(1u);
        const float start_fraction = start == 0.0f ? 0.0f : start / 24.0f;
        const float end_fraction = end == 0.0f ? 0.0f : end / 24.0f;
        range_min = 1.0f - start_fraction;
        range_max = 1.0f - end_fraction;
    }
    if (parser.findValue("worktime", &effect_range)) {
        work_time_min = static_cast<std::uint32_t>(parser.readInt(0u));
        work_time_max = static_cast<std::uint32_t>(parser.readInt(1u));
    }
    if (parser.findValue("sleeptime", &effect_range)) {
        sleep_time_min = static_cast<std::uint32_t>(parser.readInt(0u));
        sleep_time_max = static_cast<std::uint32_t>(parser.readInt(1u));
    }
    SferaParserRange block{};
    if (parser.findBlock("sound_def", &block, &effect_range, 1)) {
        sound_effect = static_cast<CSoundEffect*>(g_sfera_effect_manager.allocate(sizeof(CSoundEffect)));
        if (sound_effect != nullptr) sound_effect->initialize();
        if (sound_effect != nullptr && !sound_effect->loadDefinition(parser, block)) {
            sound_effect->destroy();
            g_sfera_effect_manager.free(sound_effect);
            sound_effect = nullptr;
        }
    }
    const std::int32_t light_count = parser.countBlocks("light_def", &effect_range);
    if (light_count > 0) {
        light_definition_count = static_cast<std::uint32_t>(light_count);
        light_definitions = allocate_counted_array<SferaLightDefinition>(light_definition_count);
        if (light_definitions == nullptr) {
            parser.release();
            return false;
        }
        for (std::uint32_t index = 0u; index < light_definition_count; ++index) light_definitions[index].initializeDefaults();
        parser.setBlockRange(&effect_range);
        std::uint32_t index = 0u;
        while (index < light_definition_count && parser.nextBlock("light_def", &block)) {
            if (!light_definitions[index].load(parser, block)) report_load_error("Can't load light_def block");
            ++index;
        }
        parser.clearBlockRange();
    }
    if (parser.findValue("effftype", &effect_range)) effect_type = static_cast<std::uint32_t>(parser.readInt(0u));
    if (parser.findValue("subeffects_num", &effect_range)) subeffect_count = static_cast<std::uint32_t>(parser.readInt(0u));
    if (subeffect_count != 0u) {
        const std::uint64_t bytes = static_cast<std::uint64_t>(subeffect_count) * sizeof(SferaSubeffectDefinition);
        if (bytes > std::numeric_limits<std::uint32_t>::max()) {
            parser.release();
            return false;
        }
        subeffects = static_cast<SferaSubeffectDefinition*>(g_sfera_effect_manager.allocate(static_cast<std::uint32_t>(bytes)));
        if (subeffects == nullptr) {
            parser.release();
            return false;
        }
        std::memset(subeffects, 0, static_cast<std::size_t>(bytes));
        parser.setScanRange(&effect_range);
        while (parser.nextValue("subeffect")) {
            const std::int32_t raw_index = parser.readInt(0u);
            if (raw_index < 0 || static_cast<std::uint32_t>(raw_index) >= subeffect_count) continue;
            SferaSubeffectDefinition& subeffect = subeffects[raw_index];
            if (parser.readStringBounded(1u, text, sizeof(text)) != nullptr) {
                if (SferaSimpleParser::equalsIgnoreCase(text, "EFF_MESH") && parser.readQuotedString(2u, text) != nullptr) {
                    subeffect.definition_index = static_cast<std::uint16_t>(findEffectMeshDefinitionIndex(text));
                    subeffect.kind = 1u;
                }
                else if (SferaSimpleParser::equalsIgnoreCase(text, "EFF_PSYSTEM") && parser.readQuotedString(2u, text) != nullptr) {
                    subeffect.definition_index = static_cast<std::uint16_t>(findParticleSystemDefinitionIndex(text));
                    subeffect.kind = 0u;
                }
            }
            if (parser.readStringBounded(3u, text, sizeof(text)) != nullptr) {
                if (SferaSimpleParser::equalsIgnoreCase(text, "ATTACH_LEFTHAND")) subeffect.attach_mode = 1u;
                else if (SferaSimpleParser::equalsIgnoreCase(text, "ATTACH_RIGHTHAND")) subeffect.attach_mode = 2u;
                else if (SferaSimpleParser::equalsIgnoreCase(text, "ATTACH_BETWEENHANDS")) subeffect.attach_mode = 3u;
                else if (SferaSimpleParser::equalsIgnoreCase(text, "ATTACH_SWORD")) subeffect.attach_mode = 4u;
            }
        }
        parser.clearScanRange();
    }
    parser.release();
    return true;
}
void CScriptedEffect::buildLinkedParticleSystems() {
    if (linked_particle_system_count == 0u || linked_render_slot_count == 0u || linked_particle_systems == nullptr || linked_render_slots == nullptr || particle_system_definitions == nullptr) return;
    SferaParticleSystemDefinition* expanded = linked_particle_systems;
    auto* render_cursor = static_cast<std::uint8_t*>(linked_render_slots);
    for (std::uint32_t source_index = 0u; source_index < particle_system_definition_count; ++source_index) {
        SferaParticleSystemDefinition& source = particle_system_definitions[source_index];
        for (std::uint32_t link_index = 0u; link_index < source.link_count; ++link_index) {
            SferaParticleSystemLink& link = source.links[link_index];
            if (link.target_index < 0) continue;
            SferaParticleSystemDefinition& target = particle_system_definitions[link.target_index];
            link.runtime_cursor = expanded;
            link.runtime_begin = expanded;
            for (std::uint32_t instance = 0u; instance < link.instance_count; ++instance) {
                std::memcpy(expanded, &target, sizeof(SferaParticleSystemDefinition));
                expanded->runtime_clone = 1u;
                expanded->render_slots = reinterpret_cast<SferaParticleRenderSlot*>(render_cursor);
                const std::size_t render_bytes = static_cast<std::size_t>(target.render_slot_count) * sizeof(SferaParticleRenderSlot);
                if (render_bytes != 0u) std::memcpy(render_cursor, target.render_slots, render_bytes);
                expanded->runtime_random_row = static_cast<std::uint32_t>(std::rand() % 255);
                expanded->runtime_random_seed_0 = static_cast<std::uint32_t>(std::rand());
                expanded->runtime_random_seed_1 = static_cast<std::uint32_t>(std::rand());
                render_cursor += render_bytes;
                ++expanded;
            }
        }
        for (std::uint32_t slot_index = 0u; slot_index < source.render_slot_count; ++slot_index) {
            SferaParticleRenderSlot& slot = source.render_slots[slot_index];
            if (slot.link_index < 0) continue;
            SferaParticleSystemLink& link = source.links[slot.link_index];
            if (link.target_index < 0) continue;
            slot.linked_particle_system = link.runtime_cursor;
            ++link.runtime_cursor;
        }
    }
}
void CScriptedEffect::resetRuntimeState() {
    CScriptedEffect* definition = source_definition;
    if (definition == nullptr) return;
    deactivated = 0u;
    cycle_length = definition->cycle_length;
    lifetime_ticks = definition->lifetime_ticks;
    next = nullptr;
    previous = nullptr;
    range_max = definition->range_max;
    range_min = definition->range_min;
    listener = nullptr;
    activation_blocked = 0u;
    update_visible_only = definition->update_visible_only;
    sound_started = 0u;
    initialize_scripted_phase(*this);
    if (sound_effect != nullptr) sound_effect->resetFrom(*definition->sound_effect);
    if (light_definitions != nullptr && definition->light_definitions != nullptr) {
        for (std::uint32_t index = 0u; index < light_definition_count; ++index) {
            std::memcpy(&light_definitions[index], &definition->light_definitions[index], sizeof(SferaLightDefinition));
            light_definitions[index].field_2c = 1u;
        }
    }
    if (effect_mesh_definitions != nullptr && definition->effect_mesh_definitions != nullptr) {
        for (std::uint32_t index = 0u; index < effect_mesh_definition_count; ++index) effect_mesh_definitions[index].resetClone(definition->effect_mesh_definitions[index]);
    }
    if (particle_system_definitions != nullptr && definition->particle_system_definitions != nullptr) {
        for (std::uint32_t index = 0u; index < particle_system_definition_count; ++index) particle_system_definitions[index].resetClone(definition->particle_system_definitions[index]);
        if (linked_particle_systems != nullptr && linked_particle_system_count != 0u && linked_render_slot_count != 0u) {
            for (std::uint32_t source_index = 0u; source_index < particle_system_definition_count; ++source_index) {
                SferaParticleSystemDefinition& source = particle_system_definitions[source_index];
                for (std::uint32_t link_index = 0u; link_index < source.link_count; ++link_index) {
                    SferaParticleSystemLink& link = source.links[link_index];
                    if (link.target_index < 0 || link.runtime_begin == nullptr) continue;
                    SferaParticleSystemDefinition& target = particle_system_definitions[link.target_index];
                    for (std::uint32_t instance = 0u; instance < link.instance_count; ++instance) link.runtime_begin[instance].resetClone(target);
                }
            }
        }
    }
}
void CSpiralEffect::initializePreset() {
    initializeBaseState(0u);
    effect_id = 0u;
    cycle_length = 400u;
    lifetime_ticks = 400u;
    bounds_min[0] = -0.4f;
    bounds_min[1] = -1.0f;
    bounds_min[2] = -0.4f;
    bounds_max[0] = 0.4f;
    bounds_max[1] = 0.1f;
    bounds_max[2] = 0.4f;
    resource_id = -1;
    spatial_gate_enabled = 1u;
    render_slot_budget = 80u;
}
void CMolEffect::initializePreset() {
    initializeBaseState(0u);
    effect_id = 110u;
    cycle_length = 1u;
    lifetime_ticks = std::numeric_limits<std::uint32_t>::max();
    render_slot_budget = 4u;
    anchor = {};
    texture_phase = 0.0f;
    anchor_initialized = 0u;
    resource_id = -1;
    sound_effect = nullptr;
    sound_started = 0u;
}
void CBladeEffect::initializePreset() {
    initializeBaseState(0u);
    effect_id = 340u;
    cycle_length = 64u;
    lifetime_ticks = 32u;
    render_slot_budget = 4u;
    anchor = {};
    progress = 0.0f;
    anchor_initialized = 0u;
    resource_id = -1;
}
void CGazerLakeEffect::initializePreset(std::uint32_t id, float effect_radius, std::uint32_t count) {
    initializeBaseState(0u);
    field_5c = 0u;
    slot_count = count;
    radius = effect_radius;
    effect_id = id;
    cycle_length = 192u;
    lifetime_ticks = std::numeric_limits<std::uint32_t>::max();
    spatial_gate_enabled = 1u;
    const float extent = effect_radius + 0.1f;
    bounds_min[0] = -extent;
    bounds_min[1] = -0.4f;
    bounds_min[2] = -extent;
    bounds_max[0] = extent;
    bounds_max[1] = 0.1f;
    bounds_max[2] = extent;
    for (auto& slot : slots) {
        slot.effect = nullptr;
        slot.age = -1.0f;
        slot.offset = {};
    }
}
void CRainEffect::initializePreset() {
    initializeBaseState(0u);
    resource_id = -1;
    particles = nullptr;
    spawn_radius = 4.0f;
    spawn_radius_bias = 0.4f;
    spawn_rate = 120.0f;
    spawn_fraction = 0.0f;
    cycle_length = 64u;
    lifetime_ticks = std::numeric_limits<std::uint32_t>::max();
    effect_id = 400u;
    effect_kind = 3u;
    render_slot_budget = 3000u;
}
void CLightEffect::initializePreset() {
    initializeBaseState(0u);
    effect_id = 200u;
    cycle_length = 1u;
    lifetime_ticks = std::numeric_limits<std::uint32_t>::max();
    color[0] = 255.0f;
    color[1] = 255.0f;
    color[2] = 255.0f;
    color[3] = 255.0f;
    field_70 = 0.0f;
    field_74 = 0u;
    field_78 = -1;
    field_7c = 0.0f;
    field_80 = 1u;
    field_84 = 0u;
}
void IEffect::initializeEffect(const SferaEffectInitializeContext&) { std::abort(); }
void IEffect::updateEffect(const SferaEffectUpdateContext&) { std::abort(); }
void IEffect::queryEffectState(const SferaEffectQueryContext&) {
}
bool IEffect::activateEffect(bool) { std::abort(); }
void IEffect::deactivateEffect(bool) { std::abort(); }
void IEffect::renderEffect() { std::abort(); }
IEffect* IEffect::createEffectResources() { std::abort(); }
void IEffect::setParameter(const SferaEffectParameter*, std::uint32_t) { std::abort(); }
void IEffect::resetEffect() {
}
void IEffect::releaseEffect() {
    destroyEffect(true);
}
bool IEffect::isEffectComplete() const {
    return false;
}
void IEffect::destroyEffect(bool free_storage) {
    if (script_name != nullptr && borrows_definition_storage == 0u) g_sfera_effect_manager.free(script_name);
    script_name = nullptr;
    if (free_storage) g_sfera_effect_manager.free(this);
}
void CScriptedEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (subeffects == nullptr) return;
    if (render_slot_budget + g_sfera_effect_manager.render_slot_count >= 10000u && context.visible) return;
    const auto* spatial_frames = static_cast<const SferaEffectVec3F*>(context.spatial_frame);
    if (light_definitions != nullptr && spatial_frames != nullptr) {
        for (std::uint32_t index = 0u; index < light_definition_count; ++index) {
            SferaLightDefinition& definition = light_definitions[index];
            definition.update(spatial_frames[definition.attach_mode], context.age, 255u);
        }
    }
    if (work_time_min != std::numeric_limits<std::uint32_t>::max()) {
        if (phase_ticks_remaining == 0u) {
            constexpr float random_scale = 3.0518509447574615e-05f;
            if (work_phase == 0u) {
                phase_ticks_remaining = work_time_min + static_cast<std::uint32_t>(std::trunc(static_cast<float>(std::rand()) * random_scale * static_cast<float>(work_time_max)));
                work_phase = 1u;
                if (particle_system_definitions != nullptr) {
                    for (std::uint32_t index = 0u; index < particle_system_definition_count; ++index) {
                        SferaParticleSystemDefinition& particle = particle_system_definitions[index];
                        particle.emission_fraction = 0.0f;
                        particle.phase_mode = 1u;
                        particle.runtime_active = 1u;
                        particle.runtime_stop_requested = 0u;
                    }
                }
            } else {
                phase_ticks_remaining = sleep_time_min + static_cast<std::uint32_t>(std::trunc(static_cast<float>(std::rand()) * random_scale * static_cast<float>(sleep_time_min)));
                work_phase = 0u;
                if (particle_system_definitions != nullptr) {
                    for (std::uint32_t index = 0u; index < particle_system_definition_count; ++index) {
                        SferaParticleSystemDefinition& particle = particle_system_definitions[index];
                        particle.emission_fraction = 0.0f;
                        particle.phase_mode = 0u;
                        particle.runtime_stop_requested = 1u;
                    }
                }
            }
        } else {
            --phase_ticks_remaining;
        }
    }
    if (spatial_frames == nullptr || context.world_frame == nullptr) return;
    const auto* world_frames = static_cast<const float (*)[16]>(context.world_frame);
    for (std::uint32_t index = 0u; index < subeffect_count; ++index) {
        const SferaSubeffectDefinition& subeffect = subeffects[index];
        if (subeffect.definition_index == std::numeric_limits<std::uint16_t>::max()) continue;
        const SferaEffectVec3F* spatial_frame = &spatial_frames[subeffect.attach_mode];
        const float* world_frame = world_frames[subeffect.attach_mode];
        if (context.visible) {
            if (subeffect.kind == 1u) {
                if (effect_mesh_definitions == nullptr || subeffect.definition_index >= effect_mesh_definition_count) continue;
                SferaEffectMeshDefinition& definition = effect_mesh_definitions[subeffect.definition_index];
                definition.update(spatial_frame, world_frame, context.age);
                definition.commit();
            } else {
                if (particle_system_definitions == nullptr || subeffect.definition_index >= particle_system_definition_count) continue;
                SferaParticleSystemDefinition& definition = particle_system_definitions[subeffect.definition_index];
                definition.update(spatial_frame, world_frame, context.age);
                definition.commit();
            }
        } else if (subeffect.kind == 0u && particle_system_definitions != nullptr && subeffect.definition_index < particle_system_definition_count) {
            particle_system_definitions[subeffect.definition_index].update(spatial_frame, world_frame, context.age);
        }
    }
}
void CScriptedEffect::updateEffect(const SferaEffectUpdateContext& context) {
    if (sound_effect == nullptr) return;
    if (sound_started == 0u) {
        sound_effect->start(context.frame, sound_effect->startTime() < context.viewer_distance);
        sound_started = 1u;
        return;
    }
    sound_effect->update(context.frame, context.viewer_distance);
}
void CScriptedEffect::queryEffectState(const SferaEffectQueryContext& context) {
    if (light_definitions == nullptr || context.frame == nullptr) return;
    const auto* frames = static_cast<const SferaEffectVec3F*>(context.frame);
    for (std::uint32_t index = 0u; index < light_definition_count; ++index) {
        SferaLightDefinition& definition = light_definitions[index];
        definition.update(frames[definition.attach_mode], context.age, 255u);
    }
}
bool CScriptedEffect::activateEffect(bool visible) {
    return update_visible_only == 0u || visible;
}
void CScriptedEffect::deactivateEffect(bool preserve_resources) {
    if (deactivated != 0u) return;
    if (!preserve_resources) {
        if (light_definitions != nullptr) for (std::uint32_t index = 0u; index < light_definition_count; ++index) {
            g_sfera_light_runtime.release(light_definitions[index].light_index);
            light_definitions[index].light_index = -1;
        }
        if (sound_effect != nullptr) sound_effect->stop();
    }
    resources_released = preserve_resources ? 0u : 1u;
    deactivated = 1u;
}
void CScriptedEffect::renderEffect() {
    if (deactivated == 0u) return;
    if (sound_effect != nullptr && sound_effect->isComplete()) sound_started = 0u;
    deactivated = 0u;
}
IEffect* CScriptedEffect::createEffectResources() {
    if (pooled_count != 0u) {
        --pooled_count;
        auto* effect = ptr32<CScriptedEffect>(pooled_instances[pooled_count]);
        pooled_instances[pooled_count] = 0u;
        if (effect != nullptr) effect->resetRuntimeState();
        return effect;
    }
    auto* memory = static_cast<CScriptedEffect*>(g_sfera_effect_manager.allocate(sizeof(CScriptedEffect)));
    if (memory == nullptr) return nullptr;
    auto* effect = std::construct_at(memory);
    effect->initializeScriptedState();
    effect->borrows_definition_storage = 1u;
    effect->subeffects = subeffects;
    effect->subeffect_count = subeffect_count;
    effect->effect_mesh_definition_count = effect_mesh_definition_count;
    effect->particle_system_definition_count = particle_system_definition_count;
    effect->linked_render_slot_count = linked_render_slot_count;
    effect->linked_particle_system_count = linked_particle_system_count;
    effect->script_name = script_name;
    effect->effect_id = effect_id;
    effect->light_definition_count = light_definition_count;
    effect->cycle_length = cycle_length;
    effect->lifetime_ticks = lifetime_ticks;
    effect->update_visible_only = update_visible_only;
    effect->range_max = range_max;
    effect->range_min = range_min;
    effect->work_time_min = work_time_min;
    effect->work_time_max = work_time_max;
    effect->sleep_time_min = sleep_time_min;
    effect->sleep_time_max = sleep_time_max;
    effect->source_definition = this;
    effect->spatial_gate_enabled = spatial_gate_enabled;
    std::memcpy(effect->bounds_min, bounds_min, sizeof(bounds_min));
    std::memcpy(effect->bounds_max, bounds_max, sizeof(bounds_max));
    effect->effect_type = effect_type;
    initialize_scripted_phase(*effect);
    effect->sound_effect = sound_effect == nullptr ? nullptr : sound_effect->clone();
    if (light_definition_count != 0u) {
        effect->light_definitions = allocate_counted_array<SferaLightDefinition>(light_definition_count);
        if (effect->light_definitions != nullptr) {
            for (std::uint32_t index = 0u; index < light_definition_count; ++index) {
                std::memcpy(&effect->light_definitions[index], &light_definitions[index], sizeof(SferaLightDefinition));
                effect->light_definitions[index].field_2c = 1u;
            }
        }
    }
    if (effect_mesh_definition_count != 0u) {
        effect->effect_mesh_definitions = allocate_counted_array<SferaEffectMeshDefinition>(effect_mesh_definition_count);
        if (effect->effect_mesh_definitions != nullptr) {
            for (std::uint32_t index = 0u; index < effect_mesh_definition_count; ++index) {
                std::memcpy(&effect->effect_mesh_definitions[index], &effect_mesh_definitions[index], sizeof(SferaEffectMeshDefinition));
                effect->effect_mesh_definitions[index].initializeClone();
            }
        }
    }
    if (particle_system_definition_count != 0u) {
        effect->particle_system_definitions = allocate_counted_array<SferaParticleSystemDefinition>(particle_system_definition_count);
        if (effect->particle_system_definitions != nullptr) {
            for (std::uint32_t index = 0u; index < particle_system_definition_count; ++index) {
                SferaParticleSystemDefinition& destination = effect->particle_system_definitions[index];
                const SferaParticleSystemDefinition& source = particle_system_definitions[index];
                std::memcpy(&destination, &source, sizeof(SferaParticleSystemDefinition));
                const std::uint64_t render_bytes = static_cast<std::uint64_t>(source.render_slot_count) * sizeof(SferaParticleRenderSlot);
                destination.render_slots = render_bytes == 0u || render_bytes > std::numeric_limits<std::uint32_t>::max() ? nullptr : static_cast<SferaParticleRenderSlot*>(g_sfera_effect_manager.allocate(static_cast<std::uint32_t>(render_bytes)));
                if (destination.render_slots != nullptr && source.render_slots != nullptr) std::memcpy(destination.render_slots, source.render_slots, static_cast<std::size_t>(render_bytes));
                destination.runtime_clone = 1u;
                destination.initializeClone();
            }
        }
    }
    if (linked_particle_system_count != 0u && linked_render_slot_count != 0u) {
        effect->linked_particle_systems = allocate_counted_array<SferaParticleSystemDefinition>(linked_particle_system_count);
        const std::uint64_t render_bytes = static_cast<std::uint64_t>(linked_render_slot_count) * sizeof(SferaParticleRenderSlot);
        effect->linked_render_slots = render_bytes > std::numeric_limits<std::uint32_t>::max() ? nullptr : g_sfera_effect_manager.allocate(static_cast<std::uint32_t>(render_bytes));
        effect->buildLinkedParticleSystems();
    }
    return effect;
}
void CScriptedEffect::setParameter(const SferaEffectParameter*, std::uint32_t) {
}
void CScriptedEffect::releaseEffect() {
    if (source_definition != nullptr && source_definition->pooled_count < 16u) {
        if (sound_effect != nullptr) sound_effect->stop();
        if (light_definitions != nullptr) for (std::uint32_t index = 0u; index < light_definition_count; ++index) {
            g_sfera_light_runtime.release(light_definitions[index].light_index);
            light_definitions[index].light_index = -1;
        }
        source_definition->pooled_instances[source_definition->pooled_count++] = address32(this);
        return;
    }
    destroyEffect(true);
}
bool CScriptedEffect::isEffectComplete() const {
    return effect_type != 0u;
}
void CScriptedEffect::destroyEffect(bool free_storage) {
    g_sfera_effect_manager.free(linked_render_slots);
    linked_render_slots = nullptr;
    if (linked_particle_systems != nullptr) {
        for (std::uint32_t index = 0u; index < linked_particle_system_count; ++index) {
            linked_particle_systems[index].render_slots = nullptr;
            linked_particle_systems[index].destroyClone();
        }
        free_counted_array(linked_particle_systems);
    }
    if (effect_mesh_definitions != nullptr) {
        for (std::uint32_t index = 0u; index < effect_mesh_definition_count; ++index) effect_mesh_definitions[index].destroyClone();
        free_counted_array(effect_mesh_definitions);
    }
    if (particle_system_definitions != nullptr) {
        for (std::uint32_t index = 0u; index < particle_system_definition_count; ++index) particle_system_definitions[index].destroyClone();
        free_counted_array(particle_system_definitions);
    }
    if (light_definitions != nullptr) {
        for (std::uint32_t index = 0u; index < light_definition_count; ++index) light_definitions[index].release();
        free_counted_array(light_definitions);
    }
    if (sound_effect != nullptr) {
        sound_effect->destroy();
        g_sfera_effect_manager.free(sound_effect);
        sound_effect = nullptr;
    }
    for (std::uint32_t index = 0u; index < pooled_count; ++index) {
        auto* pooled = ptr32<CScriptedEffect>(pooled_instances[index]);
        if (pooled != nullptr) pooled->destroyEffect(true);
        pooled_instances[index] = 0u;
    }
    pooled_count = 0u;
    if (borrows_definition_storage == 0u) g_sfera_effect_manager.free(subeffects);
    subeffects = nullptr;
    IEffect::destroyEffect(free_storage);
}
void CSpiralEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (!context.visible || context.spatial_frame == nullptr) return;
    if (render_slot_budget + g_sfera_effect_manager.render_slot_count >= 10000u) return;
    const auto& base = *static_cast<const SferaEffectVec3F*>(context.spatial_frame);
    float opacity = 1.0f;
    if (context.age > 320.0f) opacity = (400.0f - context.age) / 80.0f;
    constexpr float pi = 3.1415929794311523f;
    const float age_phase = context.age * 0.05f;
    for (std::uint32_t ring = 0u; ring < 2u; ++ring) {
        float progress = 0.0f;
        for (std::uint32_t point = 0u; point < 40u; ++point, progress += 0.025f) {
            SferaEffectRenderSlot* slot = g_sfera_effect_manager.acquireRenderSlot();
            if (slot == nullptr) return;
            slot->resource_id = resource_id;
            slot->blend_mode = 255u;
            slot->primitive_kind = 1u;
            const std::uint32_t red = 51u + static_cast<std::uint32_t>(std::trunc(204.0f * progress));
            const std::uint32_t green = 153u + static_cast<std::uint32_t>(std::trunc(51.0f * progress));
            const std::uint32_t blue = 153u - static_cast<std::uint32_t>(std::trunc(77.0f * progress));
            const std::uint32_t alpha = static_cast<std::uint32_t>(std::trunc((1.0f - progress) * 255.0f * opacity));
            for (std::uint32_t vertex = 0u; vertex < 4u; ++vertex) {
                slot->color[0][vertex] = red;
                slot->color[1][vertex] = green;
                slot->color[2][vertex] = blue;
                slot->color[3][vertex] = alpha;
            }
            const float angle = pi * progress * 1.2f + static_cast<float>(ring) * pi - age_phase;
            SferaEffectVec3F position{base.x - std::sin(angle) * 0.3f, base.y - progress, base.z - std::cos(angle) * 0.3f};
            g_sfera_effect_manager.finalizeBillboard(*slot, position, 0.15f);
        }
    }
}
void CSpiralEffect::updateEffect(const SferaEffectUpdateContext&) {
}
bool CSpiralEffect::activateEffect(bool visible) {
    return visible;
}
void CSpiralEffect::deactivateEffect(bool) {
}
void CSpiralEffect::renderEffect() {
}
IEffect* CSpiralEffect::createEffectResources() {
    auto* memory = static_cast<CSpiralEffect*>(g_sfera_effect_manager.allocate(sizeof(CSpiralEffect)));
    if (memory == nullptr) return nullptr;
    auto* effect = std::construct_at(memory);
    effect->initializePreset();
    effect->assignScriptName("spiral.effect0");
    effect->resource_id = g_sfera_textures.find("fx_flare");
    return effect;
}
void CSpiralEffect::setParameter(const SferaEffectParameter*, std::uint32_t) {
}
void CMolEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (!context.visible || context.spatial_frame == nullptr || render_slot_budget + g_sfera_effect_manager.render_slot_count >= 10000u) return;
    const auto& input = *static_cast<const SferaEffectVec3F*>(context.spatial_frame);
    if (anchor_initialized == 0u) {
        anchor = input;
        anchor_initialized = 1u;
    }
    const SferaEffectVec3F reference = g_sfera_world_objects.referencePosition();
    SferaEffectRenderSlot* slot = g_sfera_effect_manager.acquireRenderSlot();
    if (slot == nullptr) return;
    initialize_quad_slot(*slot, resource_id, 3u, 255u);
    const SferaEffectVec3F start_jitter{random_signed(0.2f), random_signed(0.2f), random_signed(0.2f)};
    const SferaEffectVec3F end_jitter{random_signed(0.2f), random_signed(0.2f), random_signed(0.2f)};
    const SferaEffectVec3F start = vec_add(anchor, start_jitter);
    const SferaEffectVec3F end = vec_add(reference, end_jitter);
    const SferaEffectVec3F direction = vec_sub(end, start);
    texture_phase += 0.05f;
    const float texture_length = vec_length(direction) * 0.3f;
    const SferaEffectVec3F end_width = vec_scale(vec_normalized(vec_cross(direction, vec_sub(end, reference))), 0.8f);
    const SferaEffectVec3F start_width = vec_scale(vec_normalized(vec_cross(direction, vec_sub(start, reference))), 0.8f);
    slot->position[0] = vec_add(end, end_width);
    slot->position[1] = vec_sub(end, end_width);
    slot->position[2] = vec_sub(start, start_width);
    slot->position[3] = vec_add(start, start_width);
    slot->uv[0][0] = 0.0f;
    slot->uv[0][1] = texture_phase;
    slot->uv[1][0] = 1.0f;
    slot->uv[1][1] = texture_phase + texture_length;
    slot->uv[2][0] = 1.0f;
    slot->uv[2][1] = texture_phase + texture_length;
    slot->uv[3][0] = 0.0f;
    slot->uv[3][1] = texture_phase + texture_length;
}
void CMolEffect::updateEffect(const SferaEffectUpdateContext& context) {
    if (sound_effect == nullptr) {
        sound_started = 1u;
        return;
    }
    if (sound_started == 0u) {
        sound_effect->start(context.frame, sound_effect->startTime() < context.viewer_distance);
        sound_started = 1u;
        return;
    }
    sound_effect->update(&anchor, context.viewer_distance);
}
bool CMolEffect::activateEffect(bool visible) {
    return visible;
}
void CMolEffect::deactivateEffect(bool) {
}
void CMolEffect::renderEffect() {
}
IEffect* CMolEffect::createEffectResources() {
    auto* memory = static_cast<CMolEffect*>(g_sfera_effect_manager.allocate(sizeof(CMolEffect)));
    if (memory == nullptr) return nullptr;
    auto* effect = std::construct_at(memory);
    effect->initializePreset();
    effect->assignScriptName("molniya.effect110");
    effect->resource_id = g_sfera_textures.find("fx_light");
    if (effect->resource_id == -1) g_sfera_effect_manager.reportError("CMolEffect::Texture not found 'fx_light'");
    effect->sound_effect = g_sfera_sound_runtime.createEffect(110u);
    return effect;
}
void CMolEffect::setParameter(const SferaEffectParameter*, std::uint32_t) {
}
void CMolEffect::destroyEffect(bool free_storage) { g_sfera_sound_runtime.destroyEffect(sound_effect); sound_effect = nullptr; IEffect::destroyEffect(free_storage); }
void CBladeEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (!context.visible || context.spatial_frame == nullptr || render_slot_budget + g_sfera_effect_manager.render_slot_count >= 10000u) return;
    const auto& input = *static_cast<const SferaEffectVec3F*>(context.spatial_frame);
    if (anchor_initialized == 0u) {
        anchor = input;
        anchor_initialized = 1u;
    }
    const SferaEffectVec3F reference = g_sfera_world_objects.referencePosition();
    SferaEffectRenderSlot* slot = g_sfera_effect_manager.acquireRenderSlot();
    if (slot == nullptr) return;
    progress += 0.05f;
    if (progress > 1.0f) progress = 1.0f;
    std::uint32_t alpha = 255u;
    if (progress > 0.8f) alpha = static_cast<std::uint32_t>(std::trunc((1.0f - progress) * 1275.0f));
    slot->resource_id = resource_id;
    slot->blend_mode = 255u;
    slot->primitive_kind = 3u;
    for (std::uint32_t vertex = 0u; vertex < 4u; ++vertex) {
        slot->color[0][vertex] = 255u;
        slot->color[1][vertex] = 255u;
        slot->color[2][vertex] = 255u;
        slot->color[3][vertex] = alpha;
    }
    const SferaEffectVec3F path = vec_sub(input, anchor);
    const SferaEffectVec3F end = vec_add(anchor, vec_scale(path, progress));
    const SferaEffectVec3F direction = vec_normalized(vec_sub(anchor, end));
    const SferaEffectVec3F back = vec_sub(end, vec_scale(direction, 0.5f));
    const SferaEffectVec3F back_width = vec_scale(vec_normalized(vec_cross(vec_sub(back, reference), vec_sub(back, end))), 0.8f);
    const SferaEffectVec3F end_width = vec_scale(vec_normalized(vec_cross(vec_sub(end, reference), vec_sub(back, end))), 0.8f);
    slot->position[0] = vec_add(back, back_width);
    slot->position[1] = vec_sub(back, back_width);
    slot->position[2] = vec_sub(end, end_width);
    slot->position[3] = vec_add(end, end_width);
    slot->uv[0][0] = 0.0f;
    slot->uv[0][1] = 0.0f;
    slot->uv[1][0] = 1.0f;
    slot->uv[1][1] = progress;
    slot->uv[2][0] = 1.0f;
    slot->uv[2][1] = 1.0f;
    slot->uv[3][0] = 0.0f;
    slot->uv[3][1] = progress;
}
void CBladeEffect::updateEffect(const SferaEffectUpdateContext&) {
}
bool CBladeEffect::activateEffect(bool visible) {
    return visible;
}
void CBladeEffect::deactivateEffect(bool) {
}
void CBladeEffect::renderEffect() {
}
IEffect* CBladeEffect::createEffectResources() {
    auto* memory = static_cast<CBladeEffect*>(g_sfera_effect_manager.allocate(sizeof(CBladeEffect)));
    if (memory == nullptr) return nullptr;
    auto* effect = std::construct_at(memory);
    effect->initializePreset();
    effect->assignScriptName("blade");
    effect->resource_id = g_sfera_textures.find("fx_blade");
    if (effect->resource_id == -1) g_sfera_effect_manager.reportError("CBladeEffect::Texture not found 'fx_blade'");
    return effect;
}
void CBladeEffect::setParameter(const SferaEffectParameter*, std::uint32_t) {
}
void CGazerLakeEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (context.spatial_frame == nullptr) return;
    if (slot_count != 0u && field_5c % slot_count == 0u) {
        for (SferaGazerEffectSlot& slot : slots) {
            if (slot.age != -1.0f) continue;
            constexpr float random_scale = 3.0518509447574615e-05f;
            constexpr float pi = 3.1415929794311523f;
            const float azimuth = static_cast<float>(std::rand()) * random_scale * (2.0f * pi);
            const float elevation = (static_cast<float>(std::rand()) * random_scale - 0.5f) * pi;
            const float elevation_cos = std::cos(elevation);
            slot.offset.x = std::sin(azimuth) * radius * elevation_cos;
            slot.offset.y = 0.0f;
            slot.offset.z = std::cos(azimuth) * radius * elevation_cos;
            slot.age = 0.0f;
            break;
        }
    }
    field_5c += 2u;
    const auto& base = *static_cast<const SferaEffectVec3F*>(context.spatial_frame);
    for (SferaGazerEffectSlot& slot : slots) {
        if (slot.age == -1.0f || slot.effect == nullptr) continue;
        slot.age += 2.0f;
        if (slot.age > 192.0f) {
            slot.age = -1.0f;
            continue;
        }
        SferaEffectVec3F position{base.x + slot.offset.x, base.y + slot.offset.y, base.z + slot.offset.z};
        SferaEffectInitializeContext child_context{&position, 1u, slot.age, context.visible, nullptr};
        slot.effect->initializeEffect(child_context);
    }
}
void CGazerLakeEffect::updateEffect(const SferaEffectUpdateContext&) {
}
bool CGazerLakeEffect::activateEffect(bool visible) {
    return visible;
}
void CGazerLakeEffect::deactivateEffect(bool) {
}
void CGazerLakeEffect::renderEffect() {
}
IEffect* CGazerLakeEffect::createEffectResources() {
    auto* memory = static_cast<CGazerLakeEffect*>(g_sfera_effect_manager.allocate(sizeof(CGazerLakeEffect)));
    if (memory == nullptr) return nullptr;
    auto* effect = std::construct_at(memory);
    effect->initializePreset(effect_id, radius, slot_count);
    effect->assignScriptName("gazer.lake");
    IEffect* source = g_sfera_effect_manager.findDefinition(729u);
    if (source != nullptr) for (auto& slot : effect->slots) {
        slot.effect = source->createEffectResources();
        slot.age = -1.0f;
    }
    return effect;
}
void CGazerLakeEffect::setParameter(const SferaEffectParameter*, std::uint32_t) {
}
void CGazerLakeEffect::destroyEffect(bool free_storage) {
    for (auto& slot : slots) if (slot.effect != nullptr) { slot.effect->destroyEffect(true); slot.effect = nullptr; }
    IEffect::destroyEffect(free_storage);
}
void CRainEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (!context.visible || context.spatial_frame == nullptr || resource_id == -1 || particles == nullptr || render_slot_budget + g_sfera_effect_manager.render_slot_count >= 10000u) return;
    constexpr std::uint32_t particle_count = 3000u;
    constexpr float random_scale = 3.0518509447574615e-05f;
    constexpr float pi = 3.1415929794311523f;
    const float requested = spawn_rate + spawn_fraction;
    std::uint32_t spawn_count = static_cast<std::uint32_t>(std::trunc(requested));
    spawn_fraction = requested - static_cast<float>(spawn_count);
    for (std::uint32_t index = 0u; index < particle_count && spawn_count != 0u; ++index) {
        SferaRainParticle& particle = particles[index];
        if (particle.remaining_life >= 0.0f) continue;
        particle.initial_life = particle.remaining_life = 30.0f + static_cast<float>(std::rand()) * random_scale * 20.0f;
        particle.fall_speed = 0.06f + static_cast<float>(std::rand()) * random_scale * 0.06f;
        particle.half_width = 0.025f + static_cast<float>(std::rand()) * random_scale * 0.025f;
        const float angle = static_cast<float>(std::rand()) * random_scale * (2.0f * pi);
        const float elevation = (static_cast<float>(std::rand()) * random_scale - 0.5f) * pi;
        const float radius = spawn_radius_bias + spawn_radius * std::cos(elevation);
        particle.offset = {std::sin(angle) * radius, 0.0f, std::cos(angle) * radius};
        --spawn_count;
    }
    const auto& base = *static_cast<const SferaEffectVec3F*>(context.spatial_frame);
    for (std::uint32_t index = 0u; index < particle_count; ++index) {
        SferaRainParticle& particle = particles[index];
        if (particle.remaining_life < 0.0f) continue;
        particle.remaining_life -= 2.0f;
        const float fade = 1.0f - particle.remaining_life / particle.initial_life;
        particle.offset.y += particle.fall_speed;
        particle.alpha = fade > 0.1f ? 200u : static_cast<std::uint32_t>(std::trunc(fade * 2000.0f));
        SferaEffectRenderSlot* slot = g_sfera_effect_manager.acquireRenderSlot();
        if (slot == nullptr) return;
        slot->resource_id = resource_id;
        slot->blend_mode = 0u;
        slot->primitive_kind = 1u;
        for (std::uint32_t vertex = 0u; vertex < 4u; ++vertex) {
            slot->color[0][vertex] = 155u;
            slot->color[1][vertex] = 155u;
            slot->color[2][vertex] = 155u;
            slot->color[3][vertex] = particle.alpha;
        }
        SferaEffectVec3F center = vec_add(base, particle.offset);
        center.y -= 4.0f;
        set_full_quad_uv(*slot);
        const SferaEffectVec3F viewer{g_sfera_effect_manager.viewer_position.x, g_sfera_effect_manager.viewer_position.y, g_sfera_effect_manager.viewer_position.z};
        const SferaEffectVec3F to_viewer = vec_sub(center, viewer);
        SferaEffectVec3F right{}, up{};
        build_y_up_billboard_axes(to_viewer, particle.half_width, particle.half_width, right, up);
        const SferaEffectVec3F left_center = vec_sub(center, right);
        const SferaEffectVec3F right_center = vec_add(center, right);
        slot->position[0] = vec_sub(left_center, up);
        slot->position[1] = vec_add(left_center, up);
        slot->position[2] = vec_add(right_center, up);
        slot->position[3] = vec_sub(right_center, up);
    }
}
void CRainEffect::updateEffect(const SferaEffectUpdateContext&) {
}
bool CRainEffect::activateEffect(bool visible) {
    return visible;
}
void CRainEffect::deactivateEffect(bool) {
}
void CRainEffect::renderEffect() {
}
IEffect* CRainEffect::createEffectResources() {
    auto* memory = static_cast<CRainEffect*>(g_sfera_effect_manager.allocate(sizeof(CRainEffect)));
    if (memory == nullptr) return nullptr;
    auto* effect = std::construct_at(memory);
    effect->initializePreset();
    effect->assignScriptName("rain");
    effect->resource_id = g_sfera_textures.find("fx_rain");
    if (effect->resource_id == -1) g_sfera_effect_manager.reportError("CRainEffect::Texture not found 'fx_rain'");
    effect->particles = static_cast<SferaRainParticle*>(g_sfera_effect_manager.allocate(sizeof(SferaRainParticle) * 3000u));
    if (effect->particles != nullptr) for (std::uint32_t index = 0u; index < 3000u; ++index) effect->particles[index].remaining_life = -1.0f;
    return effect;
}
void CRainEffect::setParameter(const SferaEffectParameter*, std::uint32_t) {
}
void CRainEffect::destroyEffect(bool free_storage) { g_sfera_effect_manager.free(particles); particles = nullptr; IEffect::destroyEffect(free_storage); }
void CLightEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (context.spatial_frame == nullptr) return;
    const auto& position = *static_cast<const SferaEffectVec3F*>(context.spatial_frame);
    if (field_74 == 0u) field_78 = g_sfera_light_runtime.create(position, color, field_70);
    if (field_78 == -1) return;
    field_74 = 1u;
    float output_color[4]{color[0], color[1], color[2], color[3]};
    if (field_80 != 0u && field_84 % field_80 == 0u) {
        constexpr float random_scale = 3.0518509447574615e-05f;
        const float jitter = static_cast<float>(std::rand() - std::rand()) * random_scale * field_7c;
        output_color[0] += output_color[0] * jitter;
        output_color[1] += output_color[1] * jitter;
        output_color[2] += output_color[2] * jitter;
    }
    ++field_84;
    g_sfera_light_runtime.write(field_78, position, output_color, field_70);
}
void CLightEffect::updateEffect(const SferaEffectUpdateContext&) {
}
bool CLightEffect::activateEffect(bool visible) {
    if (visible) return true;
    g_sfera_light_runtime.release(field_78);
    field_78 = -1;
    field_74 = 0u;
    return false;
}
void CLightEffect::deactivateEffect(bool) {
    if (deactivated != 0u) return;
    g_sfera_light_runtime.release(field_78);
    field_78 = -1;
    field_74 = 0u;
    deactivated = 1u;
}
void CLightEffect::renderEffect() {
    if (deactivated != 0u) deactivated = 0u;
}
IEffect* CLightEffect::createEffectResources() {
    auto* memory = static_cast<CLightEffect*>(g_sfera_effect_manager.allocate(sizeof(CLightEffect)));
    if (memory == nullptr) return nullptr;
    auto* effect = std::construct_at(memory);
    effect->initializePreset();
    effect->assignScriptName("light_source.eff");
    return effect;
}
void CLightEffect::setParameter(const SferaEffectParameter* parameters, std::uint32_t count) {
    if (parameters == nullptr) return;
    for (std::uint32_t index = 0u; index < count; ++index) {
        const SferaEffectParameter& parameter = parameters[index];
        if (parameter.value == nullptr) continue;
        switch (parameter.id) {
            case 1u: {
                const auto* rgb = static_cast<const std::uint16_t*>(parameter.value);
                color[0] = static_cast<float>(rgb[0]);
                color[1] = static_cast<float>(rgb[1]);
                color[2] = static_cast<float>(rgb[2]);
                break;
            }
            case 2u: field_70 = *static_cast<const float*>(parameter.value);
            break;
            case 3u: field_7c = static_cast<float>(*static_cast<const std::uint8_t*>(parameter.value)) / 100.0f;
            break;
            case 4u: field_80 = *static_cast<const std::uint8_t*>(parameter.value);
            break;
            default: break;
        }
    }
}
void CLightEffect::destroyEffect(bool free_storage) { g_sfera_light_runtime.release(field_78); field_78 = -1; field_74 = 0u; IEffect::destroyEffect(free_storage); }
IOutputDevice::IOutputDevice() { buffer = static_cast<char*>(g_sfera_std_allocator.allocate(0x4000u, 0u)); if (buffer != nullptr) buffer[0] = '\0'; }
IOutputDevice::~IOutputDevice() { g_sfera_std_allocator.deallocate(buffer); buffer = nullptr; }
COutputLogDevice::~COutputLogDevice() { g_sfera_std_allocator.deallocate(filename); filename = nullptr; }
void COutputLogDevice::setFilename(const char* path) {
    g_sfera_std_allocator.deallocate(filename);
    filename = nullptr;
    if (path == nullptr || *path == '\0') return;
    const std::size_t length = std::strlen(path) + 1u;
    filename = static_cast<char*>(g_sfera_std_allocator.allocate(length, 0u));
    if (filename == nullptr) return;
    std::memcpy(filename, path, length);
    FILE* file = nullptr;
    if (fopen_s(&file, filename, "wt") == 0 && file != nullptr) {
        std::time_t now = std::time(nullptr);
        char created_at[32]{};
        if (ctime_s(created_at, sizeof(created_at), &now) != 0) created_at[0] = '\0';
        std::fprintf(file, "Sphere log file\nCreated: %s\n", created_at);
        std::fclose(file);
    }
}
void COutputLogDevice::write(const char* text) { if (filename == nullptr || text == nullptr) return; FILE* file = nullptr; if (fopen_s(&file, filename, "a+t") == 0 && file != nullptr) { std::fprintf(file, "- %s\n", text); std::fclose(file); } }
void CSphereError::write(const char* text) {
    if (g_sfera_view_motion_runtime.initialized != 0u) { set_system_cursor_visibility(true); ::MessageBoxA(main_window_handle(), "Reenter in exit_msg detected!", "Error", MB_OK | MB_ICONERROR); ::ExitProcess(0u); }
    g_sfera_view_motion_runtime.initialized = 1u;
    std::snprintf(g_sfera_error_message_scratch_runtime.fatal_message, sizeof(g_sfera_error_message_scratch_runtime.fatal_message), "ServerN=%d  %s", static_cast<int>(g_sfera_recovered_static_runtime.server_number), text == nullptr ? "" : text);
    set_system_cursor_visibility(true);
    ::MessageBoxA(main_window_handle(), g_sfera_error_message_scratch_runtime.fatal_message, "Error", MB_OK | MB_ICONERROR);
    ::ExitProcess(0u);
}
void GrassMapMngr::loadGrassMap(const std::uint16_t* tile, void* destination) {
    if (tile == nullptr || destination == nullptr) return;
    const std::int32_t x = static_cast<std::int8_t>(*tile & 255u);
    const std::uint32_t y = static_cast<std::uint8_t>(*tile >> 8u);
    char filename[64]{};
    std::snprintf(filename, sizeof(filename), "Landscape\\GrassMap\\GrassMap_%02d_%02u.bin", x, y);
    std::ifstream stream;
    for (const std::string& path : g_sfera_files.candidatePaths(filename, true)) { stream.open(path, std::ios::binary); if (stream.is_open()) break; stream.clear(); }
    if (stream.is_open()) stream.read(static_cast<char*>(destination), 65536);
}
SferaHashMap* SferaHashMap::initialize(std::uint32_t maximum_key_length, bool keys_case_sensitive, std::int32_t initial_capacity, std::uint32_t hash_bucket_count, StdAllocator* storage_allocator) {
    if (initial_capacity < 0 || maximum_key_length == 0u || hash_bucket_count == 0u || (hash_bucket_count & (hash_bucket_count - 1u)) != 0u) return nullptr;
    g_sfera_string_lookup_runtime.initialize();
    if (storage_allocator == nullptr) storage_allocator = &g_sfera_std_allocator;
    allocator = SferaAbi::address(storage_allocator);
    invalid_entry = 0xFFFFu;
    case_sensitive = keys_case_sensitive ? 1u : 0u;
    max_key_length = maximum_key_length;
    bucket_count = hash_bucket_count;
    entry_stride = maximum_key_length + 11u;
    free_entry = 0u;
    result_pointer = 0u;
    field_2c = 0u;
    field_28 = 0u;
    entry_capacity = initial_capacity == 0 ? std::max<std::uint32_t>(((hash_bucket_count * 2u) >> 3u) / entry_stride, 20u) : static_cast<std::uint32_t>(initial_capacity);
    entries = SferaAbi::address(storage_allocator->allocate(static_cast<std::size_t>(entry_stride) * entry_capacity, 0u));
    key_buffer = SferaAbi::address(storage_allocator->allocate(maximum_key_length, 0u));
    buckets = SferaAbi::address(storage_allocator->allocate(static_cast<std::size_t>(hash_bucket_count) * sizeof(std::uint16_t), 0u));
    if (auto* bucket_table = SferaAbi::pointer<std::uint16_t>(buckets)) std::memset(bucket_table, 0xFF, static_cast<std::size_t>(hash_bucket_count) * sizeof(std::uint16_t));
    for (std::uint32_t index = 0u; index < entry_capacity; ++index) { Entry* record = entry(static_cast<std::uint16_t>(index)); if (record == nullptr) break; record->key_length = 0u; record->next = index + 1u < entry_capacity ? static_cast<std::uint16_t>(index + 1u) : invalid_entry; }
    return this;
}
SferaHashMap::Entry* SferaHashMap::entry(std::uint16_t index) {
    auto* storage = SferaAbi::pointer<std::uint8_t>(entries);
    return storage == nullptr || index == invalid_entry ? nullptr : reinterpret_cast<Entry*>(storage + static_cast<std::size_t>(index) * entry_stride);
}
const SferaHashMap::Entry* SferaHashMap::entry(std::uint16_t index) const {
    const auto* storage = SferaAbi::pointer<const std::uint8_t>(entries);
    return storage == nullptr || index == invalid_entry ? nullptr : reinterpret_cast<const Entry*>(storage + static_cast<std::size_t>(index) * entry_stride);
}
std::uint32_t SferaHashMap::findEntry(const char* key, std::uint32_t length, bool normalize_case) {
    if (key == nullptr || length > max_key_length || bucket_count == 0u) return 0xFFFFFFFFu;
    g_sfera_string_lookup_runtime.initialize();
    auto* normalized_key = SferaAbi::pointer<std::uint8_t>(key_buffer);
    auto* bucket_table = SferaAbi::pointer<std::uint16_t>(buckets);
    if (normalized_key == nullptr || bucket_table == nullptr) return 0xFFFFFFFFu;
    hash_value = 0u;
    for (std::uint32_t index = 0u; index < length; ++index) { std::uint8_t byte = static_cast<std::uint8_t>(key[index]); if (normalize_case) byte = g_sfera_string_lookup_runtime.case_fold[byte]; normalized_key[index] = byte; hash_value = static_cast<std::uint16_t>((hash_value >> 1u) + g_sfera_string_lookup_runtime.hash_mix[byte]); }
    hash_value = static_cast<std::uint16_t>(hash_value & static_cast<std::uint16_t>(bucket_count - 1u));
    current_index = bucket_table[hash_value];
    previous_entry = 0u;
    Entry* current = entry(current_index);
    if (current == nullptr) return 0xFFFFFFFFu;
    current_entry = SferaAbi::address(current);
    next_index = current->next;
    while (current->key_length != length || std::memcmp(normalized_key, current->key, length) != 0) {
        if (next_index == invalid_entry) return 0xFFFFFFFFu;
        previous_entry = current_entry;
        current_index = next_index;
        current = entry(current_index);
        if (current == nullptr) return 0xFFFFFFFFu;
        current_entry = SferaAbi::address(current);
        next_index = current->next;
    }
    if (previous_entry != 0u) { Entry* previous = SferaAbi::pointer<Entry>(previous_entry); if (previous != nullptr) previous->next = current->next; current->next = bucket_table[hash_value]; bucket_table[hash_value] = current_index; }
    return current_index;
}
std::uint32_t SferaHashMap::findValue(const char* key) {
    if (key == nullptr) return field_28;
    const std::size_t length = std::strlen(key);
    if (length > max_key_length) return field_28;
    const std::uint32_t index = findEntry(key, static_cast<std::uint32_t>(length), case_sensitive == 0u);
    const Entry* found = index == 0xFFFFFFFFu ? nullptr : entry(static_cast<std::uint16_t>(index));
    return found == nullptr ? field_28 : found->value;
}
bool SferaHashMap::erase(const char* key, std::uint32_t length) {
    if (auto* result = SferaAbi::pointer<std::uint32_t>(result_pointer)) *result = 0u;
    if (key == nullptr) return false;
    bool normalize_case = false;
    if (length == 0u) { length = static_cast<std::uint32_t>(std::strlen(key)); normalize_case = case_sensitive == 0u; }
    if (length > max_key_length || findEntry(key, length, normalize_case) == 0xFFFFFFFFu) return false;
    Entry* current = SferaAbi::pointer<Entry>(current_entry);
    if (current == nullptr) return false;
    current->key_length = 0u;
    if (previous_entry != 0u) { if (Entry* previous = SferaAbi::pointer<Entry>(previous_entry)) previous->next = next_index; } else if (auto* bucket_table = SferaAbi::pointer<std::uint16_t>(buckets)) bucket_table[hash_value] = next_index;
    current->next = free_entry;
    free_entry = current_index;
    return true;
}
std::uint32_t SferaHashMap::insert(const char* key, std::uint32_t length, const std::uint32_t* value) {
    if (auto* result = SferaAbi::pointer<std::uint32_t>(result_pointer)) *result = 0u;
    if (key == nullptr) return 0xFFFFFFFFu;
    bool normalize_case = false;
    if (length == 0u) { length = static_cast<std::uint32_t>(std::strlen(key)); normalize_case = case_sensitive == 0u; }
    if (length > max_key_length || findEntry(key, length, normalize_case) != 0xFFFFFFFFu) return 0xFFFFFFFFu;
    if (free_entry == invalid_entry) {
        if (entry_capacity == invalid_entry) return 0xFFFFFFFFu;
        const std::uint32_t old_capacity = entry_capacity;
        std::uint32_t growth = std::max<std::uint32_t>(entry_capacity / 2u, 10u);
        entry_capacity = std::min<std::uint32_t>(entry_capacity + growth, invalid_entry);
        growth = entry_capacity - old_capacity;
        free_entry = static_cast<std::uint16_t>(old_capacity);
        StdAllocator* storage_allocator = SferaAbi::pointer<StdAllocator>(allocator);
        if (storage_allocator == nullptr) storage_allocator = &g_sfera_std_allocator;
        void* replacement = storage_allocator->reallocate(SferaAbi::pointer<void>(entries), static_cast<std::size_t>(entry_capacity) * entry_stride, 0u);
        if (replacement == nullptr) return 0xFFFFFFFFu;
        entries = SferaAbi::address(replacement);
        for (std::uint32_t offset = 0u; offset < growth; ++offset) { Entry* record = entry(static_cast<std::uint16_t>(old_capacity + offset)); record->key_length = 0u; record->next = offset + 1u < growth ? static_cast<std::uint16_t>(old_capacity + offset + 1u) : invalid_entry; }
    }
    const std::uint16_t inserted_index = free_entry;
    Entry* record = entry(inserted_index);
    const auto* normalized_key = SferaAbi::pointer<const std::uint8_t>(key_buffer);
    auto* bucket_table = SferaAbi::pointer<std::uint16_t>(buckets);
    if (record == nullptr || normalized_key == nullptr || bucket_table == nullptr) return 0xFFFFFFFFu;
    std::memcpy(record->key, normalized_key, length);
    record->key[length] = 0u;
    free_entry = record->next;
    if (value != nullptr) record->value = *value;
    record->key_length = length;
    record->next = bucket_table[hash_value];
    bucket_table[hash_value] = inserted_index;
    return inserted_index;
}
void SferaHashMap::releaseStorage() {
    StdAllocator* storage_allocator = SferaAbi::pointer<StdAllocator>(allocator);
    if (storage_allocator == nullptr) storage_allocator = &g_sfera_std_allocator;
    storage_allocator->deallocate(SferaAbi::pointer<void>(entries));
    storage_allocator->deallocate(SferaAbi::pointer<void>(key_buffer));
    storage_allocator->deallocate(SferaAbi::pointer<void>(buckets));
    entries = 0u;
    key_buffer = 0u;
    buckets = 0u;
}
void CItem::resetItem() {}
void CItem::releaseItem() {}
std::int32_t CItemListCommonItem::initialize(std::int32_t minimum, std::int32_t, std::uint32_t mode, const char* list_name, std::uint32_t parameter) {
    minimum_items = static_cast<std::uint32_t>(minimum);
    capacity = 30u;
    item_count = 0u;
    list_mode = mode;
    item_parameter = parameter;
    diagnostics_mode = 0u;
    std::memset(name, 0, sizeof(name));
    if (list_name != nullptr) std::memcpy(name, list_name, std::min<std::size_t>(std::strlen(list_name), sizeof(name) - 1u));
    auto* index = static_cast<SferaHashMap*>(g_sfera_std_allocator.allocate(sizeof(SferaHashMap), 0u));
    if (index != nullptr) { std::construct_at(index); index->initialize(sizeof(name), true, 0, 256u, nullptr); index->field_28 = 0xFFFFFFFFu; }
    item_index = SferaAbi::address(index);
    auto* storage = static_cast<CCommonItem*>(g_sfera_std_allocator.allocate(static_cast<std::size_t>(capacity) * sizeof(CCommonItem), 0u));
    item_storage = SferaAbi::address(storage);
    if (storage == nullptr) return -14;
    std::memset(storage, 0, static_cast<std::size_t>(capacity) * sizeof(CCommonItem));
    return 0;
}
std::int32_t CBaseManagerCommonItem::initialize(std::int32_t minimum, std::int32_t, std::uint32_t mode, const char* list_name, std::uint32_t parameter) {
    minimum_items = static_cast<std::uint32_t>(minimum);
    capacity = 30u;
    item_count = 0u;
    list_mode = mode;
    item_parameter = parameter;
    diagnostics_mode = 0u;
    std::memset(name, 0, sizeof(name));
    if (list_name != nullptr) std::memcpy(name, list_name, std::min<std::size_t>(std::strlen(list_name), sizeof(name) - 1u));
    auto* index = static_cast<SferaHashMap*>(g_sfera_std_allocator.allocate(sizeof(SferaHashMap), 0u));
    if (index != nullptr) { std::construct_at(index); index->initialize(sizeof(name), true, 0, 256u, nullptr); index->field_28 = 0xFFFFFFFFu; }
    item_index = SferaAbi::address(index);
    auto* storage = static_cast<CItemListCommonItem*>(g_sfera_std_allocator.allocate(static_cast<std::size_t>(capacity) * sizeof(CItemListCommonItem), 0u));
    item_storage = SferaAbi::address(storage);
    if (storage == nullptr) return -14;
    std::memset(storage, 0, static_cast<std::size_t>(capacity) * sizeof(CItemListCommonItem));
    return 0;
}
CCommonItem* CItemListCommonItem::findStoredItem(const CItem* key) {
    if (key == nullptr) return nullptr;
    SferaHashMap* index = SferaAbi::pointer<SferaHashMap>(item_index);
    CCommonItem* storage = SferaAbi::pointer<CCommonItem>(item_storage);
    if (index == nullptr || storage == nullptr) return nullptr;
    const std::uint32_t slot = index->findValue(key->name);
    return slot == 0xFFFFFFFFu || slot >= capacity ? nullptr : storage + slot;
}
CCommonItem* CItemListCommonItem::firstItem() {
    CCommonItem* storage = SferaAbi::pointer<CCommonItem>(item_storage);
    if (storage == nullptr) { iterator_index = -1; return nullptr; }
    for (std::uint32_t index = 0u; index < capacity; ++index) if (storage[index].active == 1u) { iterator_index = static_cast<std::int32_t>(index); return storage + index; }
    iterator_index = -1;
    return nullptr;
}
CCommonItem* CItemListCommonItem::nextItem() {
    CCommonItem* storage = SferaAbi::pointer<CCommonItem>(item_storage);
    if (storage == nullptr || iterator_index < 0) return nullptr;
    for (std::uint32_t index = static_cast<std::uint32_t>(iterator_index) + 1u; index < capacity; ++index) if (storage[index].active == 1u) { iterator_index = static_cast<std::int32_t>(index); return storage + index; }
    return nullptr;
}
std::int32_t CItemListCommonItem::addItem(const CCommonItem* item) {
    if (item == nullptr) return -3;
    if (item_count == capacity) {
        const std::uint32_t growth = std::max<std::uint32_t>(capacity / 4u, 50u);
        auto* storage = static_cast<CCommonItem*>(g_sfera_std_allocator.reallocate(SferaAbi::pointer<void>(item_storage), static_cast<std::size_t>(capacity + growth) * sizeof(CCommonItem), 0u));
        item_storage = SferaAbi::address(storage);
        if (storage == nullptr) return -20;
        std::memset(storage + capacity, 0, static_cast<std::size_t>(growth) * sizeof(CCommonItem));
        capacity += growth;
    }
    SferaHashMap* index = SferaAbi::pointer<SferaHashMap>(item_index);
    CCommonItem* storage = SferaAbi::pointer<CCommonItem>(item_storage);
    if (index == nullptr || storage == nullptr) return -3;
    const std::uint32_t existing_slot = index->findValue(item->name);
    if (existing_slot != 0xFFFFFFFFu) {
        if (existing_slot >= capacity) return -105;
        CCommonItem* destination = storage + existing_slot;
        std::construct_at(destination);
        *destination = *item;
        destination->active = 1u;
        return -105;
    }
    std::uint32_t slot = 0u;
    while (slot < capacity && storage[slot].active != 0u) ++slot;
    if (slot == capacity) return 0;
    if (index->insert(item->name, 0u, &slot) == 0xFFFFFFFFu) return -3;
    CCommonItem* destination = storage + slot;
    std::construct_at(destination);
    *destination = *item;
    destination->active = 1u;
    ++item_count;
    return 0;
}
std::int32_t CItemListCommonItem::removeItem(const CItem* key) {
    if (key == nullptr) return -8;
    SferaHashMap* index = SferaAbi::pointer<SferaHashMap>(item_index);
    CCommonItem* storage = SferaAbi::pointer<CCommonItem>(item_storage);
    if (index == nullptr || storage == nullptr) return -8;
    const std::uint32_t slot = index->findValue(key->name);
    if (slot == 0xFFFFFFFFu || slot >= capacity) return -8;
    if (!index->erase(key->name, 0u)) return -9;
    CCommonItem* removed = storage + slot;
    removed->active = 0u;
    removed->resetItem();
    --item_count;
    return static_cast<std::int32_t>(item_count) < static_cast<std::int32_t>(minimum_items) ? -6 : 0;
}
CItemListCommonItem* CBaseManagerCommonItem::findStoredList(const CItem* key) {
    if (key == nullptr) return nullptr;
    SferaHashMap* index = SferaAbi::pointer<SferaHashMap>(item_index);
    CItemListCommonItem* storage = SferaAbi::pointer<CItemListCommonItem>(item_storage);
    if (index == nullptr || storage == nullptr) return nullptr;
    const std::uint32_t slot = index->findValue(key->name);
    return slot == 0xFFFFFFFFu || slot >= capacity ? nullptr : storage + slot;
}
CCommonItem* CBaseManagerCommonItem::selectItem(CCommonItem* output, const char* list_name, std::int32_t field_ac_filter, std::int32_t field_a8_filter, std::int32_t field_b0_filter) {
    if (output == nullptr) return nullptr;
    CCommonItem empty; empty.name[0] = '\0'; empty.active = 0u;
    CItem key; strncpy_s(key.name, sizeof(key.name), list_name == nullptr ? "" : list_name, _TRUNCATE); key.active = 0u;
    CItemListCommonItem* list = findStoredList(&key);
    CCommonItem* selected = &empty;
    if (list != nullptr && (field_ac_filter != -1 || field_a8_filter != -1 || field_b0_filter != -1)) {
        auto matches = [field_ac_filter, field_a8_filter, field_b0_filter](const CCommonItem& item) { return (field_ac_filter == -1 || item.field_ac == static_cast<std::uint32_t>(field_ac_filter)) && (field_a8_filter == -1 || item.field_a8 == static_cast<std::uint32_t>(field_a8_filter)) && (field_b0_filter == -1 || item.field_b0 == static_cast<std::uint32_t>(field_b0_filter)); };
        std::uint32_t match_count = 0u;
        for (CCommonItem* item = list->firstItem(); item != nullptr; item = list->nextItem()) if (matches(*item)) ++match_count;
        if (match_count != 0u) {
            std::uint32_t target = static_cast<std::uint32_t>(std::rand()) % match_count;
            for (CCommonItem* item = list->firstItem(); item != nullptr; item = list->nextItem()) if (matches(*item) && target-- == 0u) { selected = item; break; }
        }
    }
    std::construct_at(output); *output = *selected; return output;
}
std::int32_t CBaseManagerCommonItem::addList(const CItemListCommonItem* list) {
    if (list == nullptr) return -3;
    if (item_count == capacity) {
        const std::uint32_t growth = std::max<std::uint32_t>(capacity / 4u, 50u);
        auto* storage = static_cast<CItemListCommonItem*>(g_sfera_std_allocator.reallocate(SferaAbi::pointer<void>(item_storage), static_cast<std::size_t>(capacity + growth) * sizeof(CItemListCommonItem), 0u));
        item_storage = SferaAbi::address(storage);
        if (storage == nullptr) return -20;
        std::memset(storage + capacity, 0, static_cast<std::size_t>(growth) * sizeof(CItemListCommonItem));
        capacity += growth;
    }
    SferaHashMap* index = SferaAbi::pointer<SferaHashMap>(item_index);
    CItemListCommonItem* storage = SferaAbi::pointer<CItemListCommonItem>(item_storage);
    if (index == nullptr || storage == nullptr) return -3;
    const std::uint32_t existing_slot = index->findValue(list->name);
    if (existing_slot != 0xFFFFFFFFu) {
        if (existing_slot >= capacity) return -105;
        CItemListCommonItem* destination = storage + existing_slot;
        std::construct_at(destination);
        *destination = *list;
        destination->active = 1u;
        return -105;
    }
    std::uint32_t slot = 0u;
    while (slot < capacity && storage[slot].active != 0u) ++slot;
    if (slot == capacity) return 0;
    if (index->insert(list->name, 0u, &slot) == 0xFFFFFFFFu) return -3;
    CItemListCommonItem* destination = storage + slot;
    std::construct_at(destination);
    *destination = *list;
    destination->active = 1u;
    ++item_count;
    return 0;
}
std::int32_t CBaseManagerCommonItem::removeList(const CItem* key) {
    if (key == nullptr) return -8;
    SferaHashMap* index = SferaAbi::pointer<SferaHashMap>(item_index);
    CItemListCommonItem* storage = SferaAbi::pointer<CItemListCommonItem>(item_storage);
    if (index == nullptr || storage == nullptr) return -8;
    const std::uint32_t slot = index->findValue(key->name);
    if (slot == 0xFFFFFFFFu || slot >= capacity) return -8;
    if (!index->erase(key->name, 0u)) return -9;
    CItemListCommonItem* removed = storage + slot;
    removed->active = 0u;
    removed->resetItem();
    --item_count;
    return static_cast<std::int32_t>(item_count) < static_cast<std::int32_t>(minimum_items) ? -6 : 0;
}
void CItemListCommonItem::resetItem() {
    std::memset(name, 0, sizeof(name));
    g_sfera_std_allocator.deallocate(SferaAbi::pointer<void>(item_storage));
    if (auto* index = SferaAbi::pointer<SferaHashMap>(item_index)) {
        index->releaseStorage();
        g_sfera_std_allocator.deallocate(index);
    }
}
std::int32_t CBaseManagerCommonItem::handleInsert(CItemListCommonItem*, CCommonItem*, CCommonItem*) { return 0; }
std::int32_t CBaseManagerCommonItem::handleRemove(CItemListCommonItem*, CCommonItem*, CCommonItem*) { return 0; }
CItem* CBaseManagerCommonItem::findItem(CItem*) { return nullptr; }
bool NatureRainListener::onEffectAttached(IEffect& effect, SferaActiveEffect&, float) {
    return sfera_nature_manager() != nullptr && sfera_nature_manager()->attachRainEffect(effect);
}
bool NatureRainListener::onEffectDetached(IEffect&, SferaActiveEffect&) {
    if (auto* manager = sfera_nature_manager()) manager->detachRainEffect();
    return true;
}
void NatureRainListener::onEffectChanged(std::uint32_t, IEffect&, SferaActiveEffect&) {
}
bool LightingListener::onEffectAttached(IEffect& effect, SferaActiveEffect&, float) {
    return sfera_nature_manager() != nullptr && sfera_nature_manager()->attachLightingEffect(effect);
}
bool LightingListener::onEffectDetached(IEffect&, SferaActiveEffect&) {
    if (auto* manager = sfera_nature_manager()) manager->detachLightingEffect();
    return true;
}
void LightingListener::onEffectChanged(std::uint32_t, IEffect& effect, SferaActiveEffect& item) {
    if (auto* manager = sfera_nature_manager()) manager->onLightingEffectChanged(effect, item);
}
int CSoundFX::play(int mode) { return reinterpret_cast<CSound*>(this)->CSound::Play(mode); }
void CSoundFX::stop() { reinterpret_cast<CSound*>(this)->CSound::Stop(); }
int CSoundFX::rewind() { return reinterpret_cast<CSound*>(this)->CSound::Rewind(); }
CHardwareCursor::CHardwareCursor() { set_system_cursor_visibility(false); }
CHardwareCursor::~CHardwareCursor() { if (clip_enabled != 0u) ::ClipCursor(nullptr); if (cursor_handle != 0u) ::DestroyCursor(reinterpret_cast<HCURSOR>(static_cast<std::uintptr_t>(cursor_handle))); }
void CHardwareCursor::destroy(bool free_storage) { this->~CHardwareCursor(); if (free_storage) g_sfera_std_allocator.deallocate(this); }
void CHardwareCursor::copyStateFrom(const CCursor* previous) { SferaCursorPosition position{}; if (previous != nullptr) { saved_system_visible = previous->isSystemCursorVisible() ? 1u : 0u; kind = previous->cursorKind(); previous->getPosition(&position); } else { saved_system_visible = 1u; kind = 255u; getPosition(&position); } saved_x = position.x; saved_y = position.y; }
void CHardwareCursor::activate() { setSystemCursorVisible(saved_system_visible != 0u); setCursorKind(kind); setPosition(saved_x, saved_y); }
void CHardwareCursor::deactivate() { set_system_cursor_visibility(false); }
void CHardwareCursor::apply() { ::SetCursor(reinterpret_cast<HCURSOR>(static_cast<std::uintptr_t>(cursor_handle))); }
void CHardwareCursor::updatePosition() {}
SferaCursorPosition* CHardwareCursor::getPosition(SferaCursorPosition* output) const { if (output == nullptr) return nullptr; if (g_sfera_texture_cache_runtime.cache_enabled != 0u) { POINT point{}; ::GetCursorPos(&point); ::ScreenToClient(main_window_handle(), &point); output->x = point.x; output->y = point.y; } else { output->x = static_cast<std::int32_t>(g_sfera_graphics_runtime.display_width / 2u); output->y = static_cast<std::int32_t>(g_sfera_graphics_runtime.display_height / 2u); } return output; }
void CHardwareCursor::setPosition(std::int32_t x, std::int32_t y) { if (g_sfera_texture_cache_runtime.cache_enabled == 0u) return; POINT point{static_cast<LONG>(x), static_cast<LONG>(y)}; ::ClientToScreen(main_window_handle(), &point); ::SetCursorPos(point.x, point.y); }
void CHardwareCursor::show() { const bool enabled = cursor_uses_center_clip(kind); if ((clip_enabled != 0u) == enabled) return; if (enabled && g_sfera_texture_cache_runtime.cache_enabled != 0u) { POINT point{static_cast<LONG>(g_sfera_graphics_runtime.display_width / 2u), static_cast<LONG>(g_sfera_graphics_runtime.display_height / 2u)}; ::ClientToScreen(main_window_handle(), &point); RECT rectangle{point.x, point.y, point.x + 1, point.y + 1}; ::ClipCursor(&rectangle); } else { ::ClipCursor(nullptr); } clip_enabled = enabled ? 1u : 0u; }
bool CHardwareCursor::isInsideViewport() const { SferaCursorPosition position{}; getPosition(&position); return position.x >= 0 && position.x < static_cast<std::int32_t>(g_sfera_graphics_runtime.display_width) && position.y >= 0 && position.y < static_cast<std::int32_t>(g_sfera_graphics_runtime.display_height); }
bool CHardwareCursor::isSystemCursorVisible() const { ::ShowCursor(FALSE); return ::ShowCursor(TRUE) >= 0; }
void CHardwareCursor::setSystemCursorVisible(bool visible) { set_system_cursor_visibility(visible); }
std::uint32_t CHardwareCursor::cursorKind() const { return kind; }
void CHardwareCursor::setCursorKind(std::uint32_t new_kind) {
    kind = new_kind;
    show();
    if (cursor_handle != 0u) { ::DestroyCursor(reinterpret_cast<HCURSOR>(static_cast<std::uintptr_t>(cursor_handle))); cursor_handle = 0u; }
    texture_width = 0u;
    texture_height = 0u;
    const char* name = new_kind < 4u ? sfera_cursor_texture_name(new_kind) : nullptr;
    if (name == nullptr) { apply(); return; }
    char relative_path[128]{};
    std::snprintf(relative_path, sizeof(relative_path), "textures\\cursors\\%s.bmp", name);
    HBITMAP color_bitmap = nullptr;
    for (const std::string& path : g_sfera_files.candidatePaths(relative_path, true)) { color_bitmap = static_cast<HBITMAP>(::LoadImageA(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION)); if (color_bitmap != nullptr) break; }
    if (color_bitmap == nullptr) { ::MessageBoxA(main_window_handle(), "CreateCursor(): failed to load cursor image from file", "Error", MB_OK | MB_ICONERROR); ::ExitProcess(0u); }
    BITMAP bitmap{};
    if (::GetObjectA(color_bitmap, sizeof(bitmap), &bitmap) == 0 || bitmap.bmWidth != 32 || bitmap.bmHeight != 32 || bitmap.bmBitsPixel != 32 || bitmap.bmBits == nullptr) { ::DeleteObject(color_bitmap); ::MessageBoxA(main_window_handle(), "CreateCursor(): invalid cursor image format", "Error", MB_OK | MB_ICONERROR); ::ExitProcess(0u); }
    texture_width = static_cast<std::uint32_t>(bitmap.bmWidth);
    texture_height = static_cast<std::uint32_t>(bitmap.bmHeight);
    const std::size_t mask_stride = (static_cast<std::size_t>(bitmap.bmWidth) + 15u) / 16u * 2u;
    std::vector<std::uint8_t> mask_bits(mask_stride * static_cast<std::size_t>(bitmap.bmHeight), 0u);
    const auto* pixels = static_cast<const std::uint32_t*>(bitmap.bmBits);
    for (LONG y = 0; y < bitmap.bmHeight; ++y) for (LONG x = 0; x < bitmap.bmWidth; ++x) if ((pixels[static_cast<std::size_t>(y) * bitmap.bmWidth + x] & 0xFF000000u) == 0u) mask_bits[static_cast<std::size_t>(y) * mask_stride + static_cast<std::size_t>(x) / 8u] |= static_cast<std::uint8_t>(0x80u >> (x & 7));
    HBITMAP mask_bitmap = ::CreateBitmap(bitmap.bmWidth, bitmap.bmHeight, 1u, 1u, mask_bits.data());
    if (mask_bitmap == nullptr) { ::DeleteObject(color_bitmap); ::MessageBoxA(main_window_handle(), "CreateCursor(): failed to create cursor mask", "Error", MB_OK | MB_ICONERROR); ::ExitProcess(0u); }
    const bool centered = cursor_uses_center_clip(new_kind);
    ICONINFO info{};
    info.fIcon = FALSE;
    info.xHotspot = centered ? texture_width / 2u : 0u;
    info.yHotspot = centered ? texture_height / 2u : 0u;
    info.hbmMask = mask_bitmap;
    info.hbmColor = color_bitmap;
    HCURSOR created = static_cast<HCURSOR>(::CreateIconIndirect(&info));
    ::DeleteObject(mask_bitmap);
    ::DeleteObject(color_bitmap);
    if (created == nullptr) { ::MessageBoxA(main_window_handle(), "CreateCursor(): failed to create cursor", "Error", MB_OK | MB_ICONERROR); ::ExitProcess(0u); }
    cursor_handle = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(created));
    apply();
}
CSoftwareCursor::CSoftwareCursor() { x = static_cast<std::int32_t>(g_sfera_graphics_runtime.display_width / 2u); y = static_cast<std::int32_t>(g_sfera_graphics_runtime.display_height / 2u); }
void CSoftwareCursor::destroy(bool free_storage) { this->~CSoftwareCursor(); if (free_storage) g_sfera_std_allocator.deallocate(this); }
void CSoftwareCursor::copyStateFrom(const CCursor* previous) { if (previous != nullptr) { SferaCursorPosition position{}; saved_system_visible = previous->isSystemCursorVisible() ? 1u : 0u; saved_kind = previous->cursorKind(); previous->getPosition(&position); saved_x = position.x; saved_y = position.y; } else { saved_system_visible = 1u; saved_kind = 255u; saved_x = static_cast<std::int32_t>(g_sfera_graphics_runtime.display_width / 2u); saved_y = static_cast<std::int32_t>(g_sfera_graphics_runtime.display_height / 2u); } }
void CSoftwareCursor::activate() { if (auto* mouse = mouse_input_device()) { mouse->Unacquire(); const HRESULT result = mouse->SetCooperativeLevel(main_window_handle(), DISCL_EXCLUSIVE | DISCL_FOREGROUND); if (FAILED(result)) { ::MessageBoxA(main_window_handle(), "CSoftwareCursor::Activate(): SetCooperativeLevel() failed", "Error", MB_OK | MB_ICONERROR); ::ExitProcess(0u); } mouse->Acquire(); } setSystemCursorVisible(saved_system_visible != 0u); setCursorKind(saved_kind); setPosition(saved_x, saved_y); }
void CSoftwareCursor::deactivate() { if (auto* mouse = mouse_input_device()) { mouse->Unacquire(); const HRESULT result = mouse->SetCooperativeLevel(main_window_handle(), DISCL_NONEXCLUSIVE | DISCL_FOREGROUND); if (FAILED(result)) { ::MessageBoxA(main_window_handle(), "CSoftwareCursor::Deactivate(): SetCooperativeLevel() failed", "Error", MB_OK | MB_ICONERROR); ::ExitProcess(0u); } mouse->Acquire(); } setSystemCursorVisible(true); setCursorKind(255u); }
void CSoftwareCursor::apply() {}
void CSoftwareCursor::updatePosition() { if (active == 0u) return; x += static_cast<std::int32_t>(std::trunc(static_cast<double>(g_sfera_main_input_state_runtime.cursor_x) * 1.5)); y += static_cast<std::int32_t>(std::trunc(static_cast<double>(g_sfera_main_input_state_runtime.cursor_y) * 1.5)); }
SferaCursorPosition* CSoftwareCursor::getPosition(SferaCursorPosition* output) const { if (output == nullptr) return nullptr; output->x = x; output->y = y; return output; }
void CSoftwareCursor::setPosition(std::int32_t new_x, std::int32_t new_y) { x = new_x; y = new_y; }
void CSoftwareCursor::show() { const std::int32_t width = static_cast<std::int32_t>(g_sfera_graphics_runtime.display_width); const std::int32_t height = static_cast<std::int32_t>(g_sfera_graphics_runtime.display_height); auto* mouse = mouse_input_device(); if (active != 0u) { const bool outside = x < 0 || x >= width || y < 0 || y >= height; if (outside || g_sfera_texture_cache_runtime.cache_enabled == 0u) { if (!cursor_uses_center_clip(cursorKind())) { if (mouse != nullptr) mouse->Unacquire(); set_system_cursor_visibility(true); POINT point{x, y}; ::ClientToScreen(main_window_handle(), &point); ::SetCursorPos(point.x, point.y); active = 0u; } } if (width > 0) x = std::clamp(x, 0, width - 1); if (height > 0) y = std::clamp(y, 0, height - 1); return; } POINT point{}; ::GetCursorPos(&point); ::ScreenToClient(main_window_handle(), &point); if (point.x < 0 || point.x >= width || point.y < 0 || point.y >= height || g_sfera_texture_cache_runtime.cache_enabled == 0u) return; x = point.x; y = point.y; set_system_cursor_visibility(false); if (mouse != nullptr) mouse->Acquire(); active = 1u; }
bool CSoftwareCursor::isInsideViewport() const { return active != 0u; }
bool CSoftwareCursor::isSystemCursorVisible() const { const auto* state = g_sfera_interface.cursor.get(); return state != nullptr && state->system_visible != 0u; }
void CSoftwareCursor::setSystemCursorVisible(bool visible) { if (auto* state = g_sfera_interface.cursor.get()) state->system_visible = visible ? 1u : 0u; }
std::uint32_t CSoftwareCursor::cursorKind() const { const auto* state = g_sfera_interface.cursor.get(); return state == nullptr ? 255u : state->kind; }
void CSoftwareCursor::setCursorKind(std::uint32_t new_kind) {
    auto* state = g_sfera_interface.cursor.get();
    if (state != nullptr) state->setKind(new_kind);
    texture_width = 0u;
    texture_height = 0u;
    const char* name = new_kind < 4u ? sfera_cursor_texture_name(new_kind) : nullptr;
    if (name == nullptr) return;
    const std::int32_t index = g_sfera_textures.find(name);
    if (index < 0) return;
    const auto extent = g_sfera_textures.size(static_cast<std::uint32_t>(index));
    texture_width = static_cast<std::uint32_t>(extent.width);
    texture_height = static_cast<std::uint32_t>(extent.height);
}
void* StdAllocator::allocate(std::size_t size, std::uint32_t) {
    if (size == 0u) return nullptr;
    auto* base = static_cast<std::uint8_t*>(std::malloc(size + 8u));
    if (base == nullptr) return nullptr;
    *reinterpret_cast<std::uint32_t*>(base) = 0x61CCC864u;
    *reinterpret_cast<std::uint32_t*>(base + size + 4u) = 0x61CCC864u;
    return base + 4u;
}
void* StdAllocator::reallocate(void* memory, std::size_t size, std::uint32_t flags) {
    if (memory == nullptr) return allocate(size, flags);
    if (size == 0u) { deallocate(memory); return nullptr; }
    auto* base = static_cast<std::uint8_t*>(std::realloc(static_cast<std::uint8_t*>(memory) - 4u, size + 8u));
    if (base == nullptr) return nullptr;
    *reinterpret_cast<std::uint32_t*>(base) = 0x61CCC864u;
    *reinterpret_cast<std::uint32_t*>(base + size + 4u) = 0x61CCC864u;
    return base + 4u;
}
void StdAllocator::deallocate(void* memory) { if (memory == nullptr) return; g_sfera_interface.unbindEventHandler(memory); std::free(static_cast<std::uint8_t*>(memory) - 4u); }

namespace {
std::uint32_t effect_flag(const char* token) {
        if (token == nullptr) return 0u;
        struct Flag {
            const char* name;
            std::uint32_t value;
        };
        static constexpr Flag flags[] = {
        {"PS_ROTATEXYZ", 1u << 0u},
        {"PS_ROTATEX", 1u << 1u},
        {"PS_ROTATEY", 1u << 2u},
        {"PS_ROTATEZ", 1u << 3u},
        {"PS_USEROTSCALE", 1u << 4u},
        {"PS_TRANSLATEONLY", 1u << 5u},
        {"PS_STATICEMITALL", 1u << 6u},
        {"PS_DYNAMICEMITALL", 1u << 7u},
        {"PS_USEMAGNITE", 1u << 8u},
        {"PS_NOHEAVYATTACH", 1u << 10u},
        {"PS_NOFACECAMERA", 1u << 11u},
        {"PS_NOLOCALTIME", 1u << 12u},
        {"PS_NOLIFETIME", 1u << 13u},
        {"PS_USEUVTRANSLATE", 1u << 14u},
        {"PS_USECOLOR", 1u << 15u},
        {"PS_USEDISTORTION", 1u << 16u},
        {"PS_MAGFACTORISLIFE", 1u << 17u},
        {"PS_EMITONPOSCHANGE", 1u << 18u},
        {"PS_RANDOMTEXFRAME", 1u << 19u},
        {"PS_MAGISCHILDPS", 1u << 20u},
        {"PS_MAGFACTORGTIME", 1u << 21u},
        {"PS_EMITCTRLRHW", 1u << 22u},
        {"PS_PARENTALPHA", 1u << 23u},
        {"PS_PARENTLIFETIME", 1u << 24u},
        {"PS_DIRECTVELOCITY", 1u << 25u},
        {"PS_FOLLOWWITHSPIN", 1u << 27u},
        };
        for (const Flag& flag : flags) if (SferaSimpleParser::equalsIgnoreCase(token, flag.name)) return flag.value;
        return 0u;
    }
    void replace_effect_string(char*& target, const char* source) {
        char* replacement = duplicate_managed_string(source);
        g_sfera_effect_manager.free(target);
        target = replacement;
    }
    void release_effect_track(SferaEffectTrack*& track) {
        if (track == nullptr) return;
        track->release();
        g_sfera_effect_manager.free(track);
        track = nullptr;
    }
    SferaEffectMeshResource* find_mesh_resource(const char* name) {
        if (name == nullptr) return nullptr;
        for (auto* resource = ptr32<SferaEffectMeshResource>(g_sfera_effect_manager.particle_resource_head); resource != nullptr; resource = resource->next) if (SferaSimpleParser::equalsIgnoreCase(resource->name, name)) return resource;
        return nullptr;
    }
    void identity_matrix(float* matrix) {
        std::fill_n(matrix, 16u, 0.0f);
        matrix[0] = 1.0f;
        matrix[5] = 1.0f;
        matrix[10] = 1.0f;
        matrix[15] = 1.0f;
    }
    
    void rotation_x(float* matrix, float angle) {
        identity_matrix(matrix);
        const float c = std::cos(angle);
        const float s = std::sin(angle);
        matrix[5] = c;
        matrix[6] = -s;
        matrix[9] = s;
        matrix[10] = c;
    }
    void rotation_y(float* matrix, float angle) {
        identity_matrix(matrix);
        const float c = std::cos(angle);
        const float s = std::sin(angle);
        matrix[0] = c;
        matrix[2] = s;
        matrix[8] = -s;
        matrix[10] = c;
    }
    void rotation_z(float* matrix, float angle) {
        identity_matrix(matrix);
        const float c = std::cos(angle);
        const float s = std::sin(angle);
        matrix[0] = c;
        matrix[1] = -s;
        matrix[4] = s;
        matrix[5] = c;
    }
    void multiply_matrix(float* output, const float* left, const float* right) {
        float result[16]{};
        for (std::uint32_t row = 0u; row < 4u; ++row) for (std::uint32_t column = 0u; column < 4u; ++column) for (std::uint32_t index = 0u; index < 4u; ++index) result[row * 4u + column] += left[row * 4u + index] * right[index * 4u + column];
        std::memcpy(output, result, sizeof(result));
    }
    void rotation_xyz(float* matrix, const SferaEffectVec3F& angles) {
        float x[16]{};
        float y[16]{};
        float z[16]{};
        float xy[16]{};
        rotation_x(x, angles.x);
        rotation_y(y, angles.y);
        rotation_z(z, angles.z);
        multiply_matrix(xy, x, y);
        multiply_matrix(matrix, xy, z);
    }
    SferaEffectVec3F transform_point(const float* matrix, const SferaEffectVec3F& point) {
        return {point.x * matrix[0] + point.y * matrix[1] + point.z * matrix[2] + matrix[3], point.x * matrix[4] + point.y * matrix[5] + point.z * matrix[6] + matrix[7], point.x * matrix[8] + point.y * matrix[9] + point.z * matrix[10] + matrix[11]};
    }
    SferaEffectTrack* create_effect_track(std::uint32_t count) {
        if (count == 0u) return nullptr;
        auto* track = static_cast<SferaEffectTrack*>(g_sfera_effect_manager.allocate(sizeof(SferaEffectTrack)));
        if (track == nullptr) return nullptr;
        track->initialize();
        track->allocateKeys(count);
        if (track->keys == 0u) {
            g_sfera_effect_manager.free(track);
            return nullptr;
        }
        return track;
    }
    SferaEffectTrack* load_mesh_vector_track(SferaSimpleParser& parser, const SferaParserRange& range, bool degrees) {
        if (!parser.findValue("numkeys", &range)) return nullptr;
        const std::int32_t count = parser.readInt(0u);
        if (count <= 0) return nullptr;
        auto* track = create_effect_track(static_cast<std::uint32_t>(count));
        if (track == nullptr) return nullptr;
        parser.setScanRange(&range);
        while (parser.nextValue("key")) {
            const std::int32_t index = parser.readInt(0u);
            if (index < 0 || index >= count) continue;
            SferaEffectTrackKey key{};
            key.time = parser.readFloat(1u);
            key.vector_min[0] = parser.readFloat(2u);
            key.vector_min[1] = parser.readFloat(3u);
            key.vector_min[2] = parser.readFloat(4u);
            if (degrees) {
                constexpr float radians = 0.01745329424738884f;
                key.vector_min[0] *= radians;
                key.vector_min[1] *= radians;
                key.vector_min[2] *= radians;
            }
            track->setKey(static_cast<std::uint32_t>(index), key);
        }
        parser.clearScanRange();
        if (parser.findValue("interpolation", &range) && SferaSimpleParser::equalsIgnoreCase(parser.tokenAt(0u), "I_COSINE")) track->state = 1u;
        return track;
    }
    SferaEffectTrack* load_mesh_color_track(SferaSimpleParser& parser, const SferaParserRange& range) {
        if (!parser.findValue("numkeys", &range)) return nullptr;
        const std::int32_t count = parser.readInt(0u);
        if (count <= 0) return nullptr;
        auto* track = create_effect_track(static_cast<std::uint32_t>(count));
        if (track == nullptr) return nullptr;
        parser.setScanRange(&range);
        while (parser.nextValue("key")) {
            const std::int32_t index = parser.readInt(0u);
            if (index < 0 || index >= count) continue;
            SferaEffectTrackKey key{};
            key.time = parser.readFloat(1u);
            for (std::uint32_t channel = 0u; channel < 4u; ++channel) key.color.channels[channel] = static_cast<std::uint8_t>(parser.readInt(2u + channel));
            track->setKey(static_cast<std::uint32_t>(index), key);
        }
        parser.setScanRange(&range);
        while (parser.nextValue("rkey")) {
            const std::int32_t index = parser.readInt(0u);
            if (index < 0 || index >= count) continue;
            SferaEffectTrackKey key{};
            key.time = parser.readFloat(1u);
            key.mode = 1u;
            for (std::uint32_t channel = 0u; channel < 4u; ++channel) {
                key.color.channels[channel] = static_cast<std::uint8_t>(parser.readInt(2u + channel));
                key.color_random_range.channels[channel] = static_cast<std::uint8_t>(parser.readInt(6u + channel));
            }
            track->setKey(static_cast<std::uint32_t>(index), key);
        }
        parser.clearScanRange();
        return track;
    }
    void evaluate_mesh_color(const SferaEffectTrack& track, float age, SferaEffectColor32& output, const std::uint16_t* random_values, std::uint32_t random_offset_0, std::uint32_t random_offset_1) {
        if (track.keys == 0u || track.key_count == 0u) return;
        const auto* keys = ptr32<const SferaEffectTrackKey>(track.keys);
        auto sample = [&](std::uint32_t index, std::uint32_t random_offset, std::uint8_t* value) {
            for (std::uint32_t channel = 0u; channel < 4u; ++channel) {
                std::int32_t component = keys[index].color.channels[channel];
                if ((keys[index].mode & 1u) != 0u && random_values != nullptr) {
                    const std::uint32_t random_value = random_values[(index + channel) % 256u] + random_offset;
                    const float random = static_cast<float>(random_value) * 1.5259021893143654e-05f;
                    component += static_cast<std::int32_t>(std::trunc(random * keys[index].color_random_range.channels[channel]));
                }
                value[channel] = static_cast<std::uint8_t>(std::min(component, 255));
            }
        };
        if (track.key_count == 1u) {
            sample(0u, random_offset_0, output.channels);
            return;
        }
        const std::uint32_t last = track.key_count - 1u;
        if (age >= keys[last].time) {
            sample(last, random_offset_0, output.channels);
            return;
        }
        std::uint32_t index = 0u;
        for (std::uint32_t candidate = last; candidate > 0u; --candidate) {
            if (keys[candidate].time <= age) {
                index = candidate;
                break;
            }
        }
        std::uint8_t begin[4]{};
        std::uint8_t end[4]{};
        sample(index, random_offset_0, begin);
        sample(index + 1u, random_offset_1, end);
        const float duration = keys[index + 1u].time - keys[index].time;
        const float factor = duration == 0.0f ? 0.0f : (age - keys[index].time) / duration;
        const std::int32_t factor_byte = static_cast<std::int32_t>(std::trunc(factor * 255.0f));
        for (std::uint32_t channel = 0u; channel < 4u; ++channel) {
            const std::int32_t delta = static_cast<std::int32_t>(end[channel]) - begin[channel];
            output.channels[channel] = static_cast<std::uint8_t>(begin[channel] + ((delta * factor_byte) >> 8));
        }
    }
    float particle_random_unit(const std::uint16_t* values, std::uint32_t index, std::uint32_t offset) {
        if (values == nullptr) return static_cast<float>(std::rand()) * 3.0518509447574615e-05f;
        return static_cast<float>(values[index % 256u] + offset) * 1.5259021893143654e-05f;
    }
    SferaEffectVec3F sample_random_vector_key(const SferaEffectTrackKey& key, const std::uint16_t* values, std::uint32_t key_index, std::uint32_t seed0, std::uint32_t seed1) {
        SferaEffectVec3F result{key.vector_min[0], key.vector_min[1], key.vector_min[2]};
        if ((key.mode & 3u) == 0u) return result;
        result.x += particle_random_unit(values, key_index * 3u, seed0) * key.vector_max[0];
        result.y += particle_random_unit(values, key_index * 3u + 1u, seed1) * key.vector_max[1];
        result.z += particle_random_unit(values, key_index * 3u + 2u, seed0 + seed1) * key.vector_max[2];
        return result;
    }
    void evaluate_random_vector(const SferaEffectTrack* track, float age, SferaEffectVec3F& output, const std::uint16_t* values, std::uint32_t seed0, std::uint32_t seed1) {
        output = {};
        if (track == nullptr || track->keys == 0u || track->key_count == 0u) return;
        const auto* keys = ptr32<const SferaEffectTrackKey>(track->keys);
        if (track->key_count == 1u || age >= keys[track->key_count - 1u].time) {
            output = sample_random_vector_key(keys[track->key_count - 1u], values, track->key_count - 1u, seed0, seed1);
            return;
        }
        std::uint32_t index = 0u;
        for (std::uint32_t candidate = track->key_count - 1u; candidate > 0u; --candidate) if (keys[candidate].time <= age) {
            index = candidate;
            break;
        }
        const SferaEffectVec3F begin = sample_random_vector_key(keys[index], values, index, seed0, seed1);
        const SferaEffectVec3F finish = sample_random_vector_key(keys[index + 1u], values, index + 1u, seed0, seed1);
        const float duration = keys[index + 1u].time - keys[index].time;
        float factor = duration == 0.0f ? 0.0f : (age - keys[index].time) / duration;
        if ((track->state & 1u) != 0u) factor = (1.0f - std::cos(factor * 3.1415929794311523f)) * 0.5f;
        output = {begin.x + (finish.x - begin.x) * factor, begin.y + (finish.y - begin.y) * factor, begin.z + (finish.z - begin.z) * factor};
    }
    void release_track_array(SferaEffectTrack**& tracks, std::uint32_t& count) {
        if (tracks != nullptr) for (std::uint32_t index = 0u; index < count; ++index) release_effect_track(tracks[index]);
        g_sfera_effect_manager.free(tracks);
        tracks = nullptr;
        count = 0u;
    }
    template <class T> T* allocate_effect_array(std::uint32_t count) {
        if (count == 0u || static_cast<std::uint64_t>(count) * sizeof(T) > std::numeric_limits<std::uint32_t>::max()) return nullptr;
        return static_cast<T*>(g_sfera_effect_manager.allocate(static_cast<std::size_t>(count) * sizeof(T)));
    }
    void allocate_particle_slots(SferaParticleSystemDefinition& system, std::uint32_t count) {
        g_sfera_effect_manager.free(system.render_slots);
        system.render_slots = allocate_effect_array<SferaParticleRenderSlot>(count);
        system.render_slot_count = system.render_slots == nullptr ? 0u : count;
        system.active_particle_count = 0u;
        for (std::uint32_t index = 0u; index < system.render_slot_count; ++index) {
            auto& slot = system.render_slots[index];
            slot.size_track_index = std::numeric_limits<std::uint16_t>::max();
            slot.color_track_index = std::numeric_limits<std::uint16_t>::max();
            slot.velocity_track_index = std::numeric_limits<std::uint16_t>::max();
            slot.gravity_track_index = std::numeric_limits<std::uint16_t>::max();
            slot.linked_particle_system = nullptr;
            slot.link_index = -1;
        }
    }
    std::uint32_t particle_shape(const char* name) {
        if (SferaSimpleParser::equalsIgnoreCase(name, "EMITSHAPE_LINE")) return 1u;
        if (SferaSimpleParser::equalsIgnoreCase(name, "EMITSHAPE_DISK")) return 2u;
        if (SferaSimpleParser::equalsIgnoreCase(name, "EMITSHAPE_SPHERE")) return 3u;
        if (SferaSimpleParser::equalsIgnoreCase(name, "EMITSHAPE_BOX")) return 4u;
        if (SferaSimpleParser::equalsIgnoreCase(name, "EMITSHAPE_CYLINDER")) return 5u;
        if (SferaSimpleParser::equalsIgnoreCase(name, "EMITSHAPE_RING")) return 6u;
        if (SferaSimpleParser::equalsIgnoreCase(name, "EMITSHAPE_DISK2")) return 7u;
        return 0u;
    }
    void load_track_array(SferaSimpleParser& parser, const SferaParserRange& range, const char* block_name, SferaEffectTrack** tracks, std::uint32_t count, bool color) {
        if (tracks == nullptr || count == 0u || parser.countBlocks(block_name, &range) <= 0) return;
        const bool scalar = SferaSimpleParser::equalsIgnoreCase(block_name, "size_track");
        SferaParserRange block{};
        parser.setBlockRange(&range);
        while (parser.nextBlock(block_name, &block)) {
            std::int32_t index = 0;
            if (parser.findValue("track_num", &block)) index = parser.readInt(0u);
            if (index < 0 || static_cast<std::uint32_t>(index) >= count) continue;
            tracks[index] = scalar ? sfera_load_scalar_effect_track(&parser, &block) : color ? load_mesh_color_track(parser, block) : sfera_load_vector_effect_track(&parser, &block);
        }
        parser.clearBlockRange();
    }
    void evaluate_particle_scalar(const SferaEffectTrack* track, float age, float& output, const std::uint16_t* values, std::uint32_t seed) {
        if (track != nullptr) track->evaluateScalar(age, output, values, seed);
    }
    void apply_particle_rotation(float* transform, std::uint32_t flags, const SferaEffectVec3F& rotation) {
        if ((flags & (1u << 0u)) != 0u) rotation_xyz(transform, rotation);
        else if ((flags & (1u << 2u)) != 0u) rotation_y(transform, rotation.y);
        else if ((flags & (1u << 3u)) != 0u) rotation_z(transform, rotation.z);
        else if ((flags & (1u << 1u)) != 0u) rotation_x(transform, rotation.x);
    }
    void apply_particle_scale(float* transform, const SferaEffectVec3F& scale) {
        transform[0] *= scale.x;
        transform[1] *= scale.x;
        transform[2] *= scale.x;
        transform[4] *= scale.y;
        transform[5] *= scale.y;
        transform[6] *= scale.y;
        transform[8] *= scale.z;
        transform[9] *= scale.z;
        transform[10] *= scale.z;
    }
    SferaEffectVec3F normalized(SferaEffectVec3F value) {
        const float length = vec_length(value);
        if (length > 0.000001f) {
            value.x /= length;
            value.y /= length;
            value.z /= length;
        }
        return value;
    }
    void particle_generate(SferaParticleSystemDefinition& system, std::uint32_t index) {
        if (system.render_slots == nullptr || index >= system.render_slot_count) return;
        auto& slot = system.render_slots[index];
        const auto* table = ptr32<const std::uint16_t>(g_sfera_effect_manager.particle_random_table);
        if (system.lifetime_track != nullptr) slot.total_lifetime = system.lifetime;
        else slot.total_lifetime = system.lifetime + static_cast<float>(std::rand()) * 3.0518509447574615e-05f * system.lifetime_random_factor;
        slot.random_row = static_cast<std::uint32_t>(std::rand() % 254);
        slot.random_seed_0 = static_cast<std::uint16_t>(std::rand());
        slot.random_seed_1 = static_cast<std::uint16_t>(std::rand());
        const std::uint16_t* random_values = table == nullptr ? nullptr : table + (slot.random_row << 8u);
        if (slot.linked_particle_system != nullptr && (slot.linked_particle_system->flags & (1u << 24u)) != 0u && slot.linked_particle_system->render_slots != nullptr) for (std::uint32_t child = 0u; child < slot.linked_particle_system->render_slot_count; ++child) slot.linked_particle_system->render_slots[child].remaining_lifetime = -1.0f;
        if (slot.size_track_index != std::numeric_limits<std::uint16_t>::max() && slot.size_track_index < system.size_track_count) evaluate_particle_scalar(system.size_tracks[slot.size_track_index], 0.0f, slot.size, random_values, slot.random_seed_0);
        if (slot.color_track_index != std::numeric_limits<std::uint16_t>::max() && slot.color_track_index < system.color_track_count && system.color_tracks[slot.color_track_index] != nullptr) evaluate_mesh_color(*system.color_tracks[slot.color_track_index], 0.0f, slot.color, random_values, slot.random_seed_0, slot.random_seed_1);
        slot.remaining_lifetime = slot.total_lifetime;
        slot.position = {};
        slot.texture_frame = (system.flags & (1u << 19u)) != 0u && system.texture_frame_count != 0u ? static_cast<float>(std::rand() % system.texture_frame_count) : 0.0f;
        if (system.random_seed > 0) std::srand(static_cast<unsigned int>(system.random_seed + system.random_factor * static_cast<std::int32_t>(index)));
        constexpr float pi = 3.1415929794311523f;
        constexpr float two_pi = 6.283185958862305f;
        const float random_signed = static_cast<float>(std::rand() - std::rand()) * 3.0518509447574615e-05f;
        switch (system.shape) {
            case 0u: if (system.shape_points != nullptr && system.shape_point_count != 0u) slot.position = system.shape_points[system.random_seed == 0 ? std::min(index, system.shape_point_count - 1u) : static_cast<std::uint32_t>(std::rand()) % system.shape_point_count];
            break;
            case 1u: {
                const float length = vec_length(system.direction);
                const float scalar = system.random_seed == 0 ? length / static_cast<float>(std::max(system.render_slot_count, 1u)) * static_cast<float>(index) - length * 0.5f : length * random_signed * 0.5f;
                slot.position = {system.direction.x * scalar, system.direction.y * scalar, system.direction.z * scalar};
                break;
            }
            case 2u: {
                const float a = static_cast<float>(std::rand()) * 3.0518509447574615e-05f * two_pi;
                const float p = random_signed * pi * 0.5f;
                slot.position = {std::sin(a) * system.radius * std::cos(p), 0.0f, std::cos(a) * system.radius * std::cos(p)};
                break;
            }
            case 3u: {
                const float a = static_cast<float>(std::rand()) * 3.0518509447574615e-05f * two_pi;
                const float p = random_signed * pi * 0.5f;
                slot.position = {std::cos(a) * system.radius * std::cos(p), std::sin(p) * system.radius, std::sin(a) * system.radius * std::cos(p)};
                break;
            }
            case 4u: slot.position = {static_cast<float>(std::rand() - std::rand()) * 3.0518509447574615e-05f * system.width * 0.5f, static_cast<float>(std::rand() - std::rand()) * 3.0518509447574615e-05f * system.radius * 0.5f, static_cast<float>(std::rand() - std::rand()) * 3.0518509447574615e-05f * system.height * 0.5f};
            break;
            case 5u: {
                const float a = static_cast<float>(std::rand()) * 3.0518509447574615e-05f * two_pi;
                const float p = random_signed * pi * 0.5f;
                slot.position = {std::sin(a) * system.radius * std::cos(p), static_cast<float>(std::rand() - std::rand()) * 3.0518509447574615e-05f * system.height * 0.5f, std::cos(a) * system.radius * std::cos(p)};
                break;
            }
            case 6u: {
                const float a = system.random_seed == 0 ? two_pi * static_cast<float>(system.random_factor + static_cast<std::int32_t>(index)) / static_cast<float>(std::max(system.render_slot_count, 1u)) : static_cast<float>(std::rand()) * 3.0518509447574615e-05f * two_pi;
                slot.position = {std::sin(a) * system.radius, static_cast<float>(std::rand()) * 3.0518509447574615e-05f * system.height, std::cos(a) * system.radius};
                break;
            }
            case 7u: {
                const float a = static_cast<float>(std::rand()) * 3.0518509447574615e-05f * two_pi;
                const float p = random_signed * pi * 0.5f;
                const float radial = system.width + system.radius * std::cos(p);
                slot.position = {std::sin(a) * radial, 0.0f, std::cos(a) * radial};
                break;
            }
        }
        if ((system.flags & (1u << 10u)) != 0u) {
            if ((system.flags & (1u << 5u)) != 0u) {
                slot.position.x += system.current_position.x;
                slot.position.y += system.current_position.y;
                slot.position.z += system.current_position.z;
            } else slot.position = transform_point(system.transform, slot.position);
        }
        slot.position.x += system.emitter_position.x;
        slot.position.y += system.emitter_position.y;
        slot.position.z += system.emitter_position.z;
        slot.spawn_position = slot.position;
        if (system.random_seed > 0) std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }
    void particle_emit(SferaParticleSystemDefinition& system, float delta) {
        if (system.render_slots == nullptr || system.render_slot_count == 0u) return;
        const float accumulated = system.emission_count * delta + system.emission_fraction;
        const std::uint32_t requested = accumulated <= 0.0f ? 0u : static_cast<std::uint32_t>(std::floor(accumulated));
        system.emission_fraction = accumulated - static_cast<float>(requested);
        if (requested == 0u) return;
        const SferaEffectVec3F movement{system.current_position.x - system.previous_position.x, system.current_position.y - system.previous_position.y, system.current_position.z - system.previous_position.z};
        float movement_factor = 0.0f;
        const bool position_emit = (system.flags & (1u << 18u)) != 0u && vec_length(movement) > 0.0f;
        const float step = position_emit && accumulated != 0.0f ? 1.0f / accumulated : 0.0f;
        std::uint32_t emitted = 0u;
        for (std::uint32_t index = 0u; index < system.render_slot_count && emitted < requested; ++index) if (system.render_slots[index].remaining_lifetime < 0.0f) {
            particle_generate(system, index);
            if (position_emit) {
                system.render_slots[index].position.x -= movement.x * movement_factor;
                system.render_slots[index].position.y -= movement.y * movement_factor;
                system.render_slots[index].position.z -= movement.z * movement_factor;
                system.render_slots[index].spawn_position = system.render_slots[index].position;
                movement_factor += step;
            }
            ++emitted;
            ++system.active_particle_count;
        }
    }
    void update_particle_children(SferaParticleSystemDefinition& system, float age) {
        if (system.render_slots == nullptr) return;
        for (std::uint32_t index = 0u; index < system.render_slot_count; ++index) {
            auto& slot = system.render_slots[index];
            if (slot.remaining_lifetime < 0.0f) continue;
            if ((system.flags & (1u << 10u)) != 0u) slot.render_position = slot.position;
            else if ((system.flags & (1u << 5u)) != 0u) slot.render_position = {slot.position.x + system.current_position.x, slot.position.y + system.current_position.y, slot.position.z + system.current_position.z};
            else slot.render_position = transform_point(system.transform, slot.position);
            if (slot.linked_particle_system == nullptr) continue;
            if ((slot.linked_particle_system->flags & (1u << 23u)) != 0u) slot.linked_particle_system->power = static_cast<float>(slot.color.alpha) * 0.00392156862745098f * system.power;
            slot.linked_particle_system->update(&slot.render_position, nullptr, age);
        }
    }
}
void SferaEffectMeshDefinition::initializeDefinition() {
    name = nullptr;
    mesh_resource = nullptr;
    flags = 0u;
    rotation_track = nullptr;
    scale_track = nullptr;
    position_track = nullptr;
    ucoord_track = nullptr;
    vcoord_track = nullptr;
    color_track = nullptr;
    u_offset = 0.0f;
    v_offset = 0.0f;
    std::fill_n(color.channels, 4u, 255u);
    self_illumination = 255u;
    runtime_clone = 0u;
    random_row = 0u;
    random_offset = 0u;
    random_state = 0u;
    runtime_position = {};
    identity_matrix(transform);
    texture_name = nullptr;
    texture_id = -1;
    primitive_flags = 0u;
}
bool SferaEffectMeshDefinition::loadDefinition(const char*, SferaSimpleParser& parser, const SferaParserRange& range) {
    SferaParserRange previous{};
    parser.getBlockRange(&previous);
    char text[512]{};
    if (parser.findValue("effectmesh_name", &range)) {
        parser.readQuotedString(0u, text);
        replace_effect_string(name, text);
    }
    if (parser.findValue("effectmesh_ssm", &range)) {
        parser.readQuotedString(0u, text);
        mesh_resource = find_mesh_resource(text);
    }
    if (parser.findValue("effectmesh_flags", &range)) for (std::uint32_t index = 0u; index < parser.tokenCount(); index += 2u) flags |= effect_flag(parser.tokenAt(index));
    if (parser.findValue("self_illumination", &range)) self_illumination = static_cast<std::uint32_t>(parser.readInt(0u));
    if (parser.findValue("color", &range)) for (std::uint32_t channel = 0u; channel < 4u; ++channel) color.channels[channel] = static_cast<std::uint8_t>(parser.readInt(channel));
    SferaParserRange track_range{};
    if (parser.findBlock("rotation_track", &track_range, &range, 1)) rotation_track = load_mesh_vector_track(parser, track_range, true);
    if (parser.findBlock("scale_track", &track_range, &range, 1)) scale_track = load_mesh_vector_track(parser, track_range, false);
    if (parser.findBlock("position_track", &track_range, &range, 1)) position_track = load_mesh_vector_track(parser, track_range, false);
    if (parser.findBlock("color_track", &track_range, &range, 1)) color_track = load_mesh_color_track(parser, track_range);
    if (parser.findBlock("ucoord_track", &track_range, &range, 1)) ucoord_track = sfera_load_scalar_effect_track(&parser, &track_range);
    if (parser.findBlock("vcoord_track", &track_range, &range, 1)) vcoord_track = sfera_load_scalar_effect_track(&parser, &track_range);
    SferaParserRange texture_range{};
    if (parser.findBlock("texture_def", &texture_range, &range, 1)) {
        primitive_flags = 2u;
        if (parser.findValue("blendmode", &texture_range) && SferaSimpleParser::equalsIgnoreCase(parser.tokenAt(0u), "PS_BLENDADD")) primitive_flags |= 1u;
        if (parser.findValue("texture", &texture_range)) {
            parser.readQuotedString(0u, text);
            replace_effect_string(texture_name, text);
        }
    }
    random_row = static_cast<std::uint32_t>(std::rand() % 255);
    random_offset = static_cast<std::uint32_t>(std::rand());
    random_state = static_cast<std::uint32_t>(std::rand());
    if (texture_name != nullptr) texture_id = g_sfera_textures.find(texture_name);
    parser.setBlockRange(&previous);
    return true;
}
std::uint32_t SferaEffectMeshDefinition::renderSlotCount() {
    return mesh_resource == nullptr ? 0u : mesh_resource->face_count;
}
void SferaEffectMeshDefinition::initializeClone() {
    runtime_clone = 1u;
    random_row = static_cast<std::uint32_t>(std::rand() % 255);
    random_offset = static_cast<std::uint32_t>(std::rand());
    random_state = static_cast<std::uint32_t>(std::rand());
    if (texture_name != nullptr) texture_id = g_sfera_textures.find(texture_name);
}
void SferaEffectMeshDefinition::resetClone(const SferaEffectMeshDefinition& source) {
    u_offset = source.u_offset;
    v_offset = source.v_offset;
    color = source.color;
    random_row = static_cast<std::uint32_t>(std::rand() % 255);
    random_offset = static_cast<std::uint32_t>(std::rand());
    random_state = static_cast<std::uint32_t>(std::rand());
    runtime_position = source.runtime_position;
    std::memcpy(transform, source.transform, sizeof(transform));
}
void SferaEffectMeshDefinition::destroyClone() {
    if (runtime_clone != 0u) return;
    g_sfera_effect_manager.free(name);
    name = nullptr;
    g_sfera_effect_manager.free(texture_name);
    texture_name = nullptr;
    release_effect_track(rotation_track);
    release_effect_track(scale_track);
    release_effect_track(position_track);
    release_effect_track(ucoord_track);
    release_effect_track(vcoord_track);
    release_effect_track(color_track);
}
void SferaEffectMeshDefinition::update(const SferaEffectVec3F* spatial_frame, const float* world_frame, float age) {
    if (mesh_resource == nullptr || spatial_frame == nullptr) return;
    runtime_position = *spatial_frame;
    if ((flags & (1u << 5u)) != 0u) {
        if (position_track != nullptr) {
            SferaEffectVec3F offset{};
            position_track->evaluateVector(age, offset);
            runtime_position.x += offset.x;
            runtime_position.y += offset.y;
            runtime_position.z += offset.z;
        }
        if ((flags & (1u << 27u)) != 0u && world_frame != nullptr) std::memcpy(transform, world_frame, sizeof(transform));
    } else {
        identity_matrix(transform);
        bool rotated = false;
        if (rotation_track != nullptr) {
            SferaEffectVec3F rotation{};
            rotation_track->evaluateVector(age, rotation);
            if ((flags & (1u << 0u)) != 0u) rotation_xyz(transform, rotation);
            else if ((flags & (1u << 2u)) != 0u) rotation_y(transform, rotation.y);
            else if ((flags & (1u << 3u)) != 0u) rotation_z(transform, rotation.z);
            else if ((flags & (1u << 1u)) != 0u) rotation_x(transform, rotation.x);
            rotated = (flags & 15u) != 0u;
        }
        if (scale_track != nullptr) {
            SferaEffectVec3F scale{};
            scale_track->evaluateVector(age, scale);
            if (rotated) {
                transform[0] *= scale.x;
                transform[1] *= scale.x;
                transform[2] *= scale.x;
                transform[4] *= scale.y;
                transform[5] *= scale.y;
                transform[6] *= scale.y;
                transform[8] *= scale.z;
                transform[9] *= scale.z;
                transform[10] *= scale.z;
            } else {
                transform[0] = scale.x;
                transform[5] = scale.y;
                transform[10] = scale.z;
            }
        }
        transform[3] = runtime_position.x;
        transform[7] = runtime_position.y;
        transform[11] = runtime_position.z;
        if (position_track != nullptr) {
            SferaEffectVec3F offset{};
            position_track->evaluateVector(age, offset);
            transform[3] += offset.x;
            transform[7] += offset.y;
            transform[11] += offset.z;
        }
        if ((flags & (1u << 27u)) != 0u && world_frame != nullptr) {
            float combined[16]{};
            multiply_matrix(combined, transform, world_frame);
            std::memcpy(transform, combined, sizeof(transform));
        }
    }
    const auto* random_values = ptr32<const std::uint16_t>(g_sfera_effect_manager.particle_random_table + (random_row << 9u));
    if ((flags & (1u << 14u)) != 0u) {
        if (ucoord_track != nullptr) ucoord_track->evaluateScalar(age, u_offset, random_values, random_offset);
        if (vcoord_track != nullptr) vcoord_track->evaluateScalar(age, v_offset, random_values, random_offset);
    }
    if ((flags & (1u << 15u)) != 0u && color_track != nullptr) evaluate_mesh_color(*color_track, age, color, random_values, random_offset, random_state);
}
void SferaEffectMeshDefinition::commit() {
    if (mesh_resource == nullptr || texture_name == nullptr) return;
    if (g_sfera_effect_manager.render_slot_count + mesh_resource->face_count >= g_sfera_effect_manager.render_slots.capacity || g_sfera_effect_manager.render_slots.data == 0u) return;
    if (mesh_resource->transformed_vertices == nullptr && mesh_resource->vertex_count != 0u) return;
    for (std::uint32_t index = 0u; index < mesh_resource->vertex_count; ++index) mesh_resource->transformed_vertices[index] = (flags & (1u << 5u)) != 0u ? SferaEffectVec3F{mesh_resource->vertices[index].x + runtime_position.x, mesh_resource->vertices[index].y + runtime_position.y, mesh_resource->vertices[index].z + runtime_position.z} : transform_point(transform, mesh_resource->vertices[index]);
    const float (*uv_source)[2] = mesh_resource->uv;
    if ((flags & (1u << 14u)) != 0u && mesh_resource->translated_uv != nullptr) {
        for (std::uint32_t index = 0u; index < mesh_resource->uv_count; ++index) {
            mesh_resource->translated_uv[index][0] = mesh_resource->uv[index][0] + u_offset;
            mesh_resource->translated_uv[index][1] = mesh_resource->uv[index][1] + v_offset;
        }
        uv_source = mesh_resource->translated_uv;
    }
    const SferaEffectColor32* color_source = mesh_resource->colors;
    if ((flags & (1u << 15u)) != 0u && mesh_resource->transformed_colors != nullptr) {
        for (std::uint32_t index = 0u; index < mesh_resource->vertex_count; ++index) {
            for (std::uint32_t channel = 0u; channel < 4u; ++channel) mesh_resource->transformed_colors[index].channels[channel] = static_cast<std::uint8_t>((static_cast<std::uint32_t>(mesh_resource->colors[index].channels[channel]) * color.channels[channel]) >> 8u);
        }
        color_source = mesh_resource->transformed_colors;
    }
    auto* slots = ptr32<SferaEffectRenderSlot>(g_sfera_effect_manager.render_slots.data);
    for (std::uint32_t face = 0u; face < mesh_resource->face_count; ++face) {
        auto& slot = slots[g_sfera_effect_manager.render_slot_count++];
        slot.resource_id = texture_id;
        slot.blend_mode = self_illumination;
        slot.primitive_kind = primitive_flags;
        for (std::uint32_t vertex = 0u; vertex < 4u; ++vertex) {
            const std::uint32_t vertex_index = mesh_resource->face_vertices[face][vertex];
            const std::uint32_t uv_index = mesh_resource->face_uv[face][vertex];
            slot.position[vertex] = mesh_resource->transformed_vertices[vertex_index];
            slot.uv[vertex][0] = uv_source[uv_index][0];
            slot.uv[vertex][1] = uv_source[uv_index][1];
            for (std::uint32_t channel = 0u; channel < 4u; ++channel) slot.color[channel][vertex] = color_source[vertex_index].channels[channel];
        }
    }
}
void SferaParticleSystemDefinition::initializeDefinition() {
    std::memset(this, 0, sizeof(*this));
    power = 1.0f;
    first_update = 1u;
    render_basis[0] = {1.0f, 1.0f, 1.0f};
    phase_mode = 1u;
    runtime_active = 1u;
}
bool SferaParticleSystemDefinition::loadDefinition(const char*, SferaSimpleParser& parser, const SferaParserRange& range) {
    SferaParserRange caller_range{};
    parser.getBlockRange(&caller_range);
    SferaParserRange nested{};
    char text[1024]{};
    if (parser.findValue("psystem_name", &range) && parser.readQuotedString(0u, text) != nullptr) replace_effect_string(name, text);
    if (parser.findValue("particles_num", &range)) {
        const std::int32_t count = parser.readInt(0u);
        if (count > 0) allocate_particle_slots(*this, static_cast<std::uint32_t>(count));
    }
    if (parser.findValue("psystem_flags", &range)) for (std::uint32_t index = 0u; index < parser.tokenCount(); index += 2u) flags |= effect_flag(parser.tokenAt(index));
    if (parser.findValue("transform_vec0", &range)) parser.readFloatSequence(0u, &render_basis[0].x, 3u);
    if (parser.findValue("transform_vec1", &range)) parser.readFloatSequence(0u, &render_basis[1].x, 3u);
    if (parser.findValue("transform_vec2", &range)) parser.readFloatSequence(0u, &render_basis[2].x, 3u);
    if (parser.findValue("transform_vec3", &range)) parser.readFloatSequence(0u, &render_basis[3].x, 3u);
    if (parser.findValue("distortion_vec", &range)) parser.readFloatSequence(0u, &distortion.x, 3u);
    if (parser.findValue("self_illumination", &range)) self_illumination = static_cast<std::uint32_t>(parser.readInt(0u));
    if (parser.findValue("power", &range)) power = parser.readFloat(0u);
    SferaParserRange block{};
    if (parser.findBlock("power_track", &block, &range, 1)) power_track = sfera_load_scalar_effect_track(&parser, &block);
    if (parser.findBlock("position_track", &block, &range, 1)) position_track = sfera_load_vector_effect_track(&parser, &block);
    if (parser.findBlock("scale_track", &block, &range, 1)) scale_track = sfera_load_vector_effect_track(&parser, &block);
    if (parser.findBlock("rotation_track", &block, &range, 1)) rotation_track = load_mesh_vector_track(parser, block, true);
    if (parser.findBlock("childs_def", &block, &range, 1)) {
        if (parser.findValue("childs_num", &block)) {
            const std::int32_t count = parser.readInt(0u);
            if (count > 0) {
                link_count = static_cast<std::uint32_t>(count);
                links = allocate_effect_array<SferaParticleSystemLink>(link_count);
                for (std::uint32_t index = 0u; index < link_count; ++index) links[index].target_index = -1;
            }
        }
        parser.setScanRange(&block);
        while (links != nullptr && parser.nextValue("child")) {
            const std::int32_t index = parser.readInt(0u);
            if (index < 0 || static_cast<std::uint32_t>(index) >= link_count) continue;
            if (parser.readQuotedString(1u, text) != nullptr) replace_effect_string(links[index].target_name, text);
        }
        parser.clearScanRange();
    }
    if (parser.findBlock("magnite_def", &block, &range, 1)) {
        if (parser.findBlock("magposition_track", &nested, &block, 1)) magnet_position_track = sfera_load_vector_effect_track(&parser, &nested);
        if (parser.findBlock("magfactor_track", &nested, &block, 1)) magnet_factor_track = sfera_load_vector_effect_track(&parser, &nested);
        if (parser.findValue("magchildps", &block)) {
            magnet_child_index = parser.readInt(0u);
            if (magnet_child_index >= 0 && static_cast<std::uint32_t>(magnet_child_index) < link_count) ++links[magnet_child_index].instance_count;
            else magnet_child_index = -1;
        }
        if (parser.findValue("magfactor", &block)) {
            float source[3]{};
            parser.readFloatSequence(0u, source, 3u);
            magnet_factor = {source[0] == 0.0f ? 0.0f : 1.0f / source[0], source[1] == 0.0f ? 0.0f : 1.0f / source[1], source[2] == 0.0f ? 0.0f : 1.0f / source[2]};
        }
        if (parser.findValue("magpos", &block)) parser.readFloatSequence(0u, &magnet_position.x, 3u);
    }
    if (parser.findBlock("emission_def", &block, &range, 1)) {
        if (parser.findValue("shape", &block) && parser.readStringBounded(0u, text, sizeof(text)) != nullptr) shape = particle_shape(text);
        if (parser.findValue("randseed", &block)) random_seed = parser.readInt(0u);
        if (parser.findValue("randfactor", &block)) random_factor = parser.readInt(0u);
        if (parser.findValue("height", &block)) height = parser.readFloat(0u);
        if (parser.findValue("width", &block)) width = parser.readFloat(0u);
        if (parser.findValue("radius", &block)) radius = parser.readFloat(0u);
        if (parser.findValue("emit_num", &block)) emission_count = parser.readFloat(0u);
        if (parser.findValue("direction", &block)) parser.readFloatSequence(0u, &direction.x, 3u);
        if (parser.findValue("emitter_pos", &block)) parser.readFloatSequence(0u, &emitter_position.x, 3u);
        if (parser.findValue("shape_numpoints", &block)) {
            const std::int32_t count = parser.readInt(0u);
            if (count > 0) {
                shape_point_count = static_cast<std::uint32_t>(count);
                shape_points = allocate_effect_array<SferaEffectVec3F>(shape_point_count);
            }
        }
        parser.setScanRange(&block);
        while (shape_points != nullptr && parser.nextValue("point")) {
            const std::int32_t index = parser.readInt(0u);
            if (index >= 0 && static_cast<std::uint32_t>(index) < shape_point_count) parser.readFloatSequence(1u, &shape_points[index].x, 3u);
        }
        parser.clearScanRange();
        if (parser.findBlock("emission_track", &nested, &block, 1)) emission_track = sfera_load_scalar_effect_track(&parser, &nested);
        if (parser.findBlock("emissionpos_track", &nested, &block, 1)) emission_position_track = sfera_load_vector_effect_track(&parser, &nested);
    }
    if (parser.findBlock("particleborn_def", &block, &range, 1)) {
        if (parser.findValue("lifetime", &block)) lifetime = parser.readFloat(0u);
        if (parser.findValue("lifetime_rf", &block)) lifetime_random_factor = parser.readFloat(0u);
        if (parser.findBlock("lifetime_track", &nested, &block, 1)) lifetime_track = sfera_load_scalar_effect_track(&parser, &nested);
    }
    if (parser.findBlock("particletracks_def", &block, &range, 1)) {
        auto setup_tracks = [&](const char* count_name, std::uint32_t& count, SferaEffectTrack**& tracks) {
            if (!parser.findValue(count_name, &block)) return;
            const std::int32_t parsed = parser.readInt(0u);
            if (parsed <= 0) return;
            count = static_cast<std::uint32_t>(parsed);
            tracks = allocate_effect_array<SferaEffectTrack*>(count);
        };
        setup_tracks("nsize_tracks", size_track_count, size_tracks);
        setup_tracks("ncolor_tracks", color_track_count, color_tracks);
        setup_tracks("nvelocity_tracks", velocity_track_count, velocity_tracks);
        setup_tracks("ngravitation_tracks", gravity_track_count, gravity_tracks);
        if (size_tracks != nullptr) load_track_array(parser, block, "size_track", size_tracks, size_track_count, false);
        if (color_tracks != nullptr) load_track_array(parser, block, "color_track", color_tracks, color_track_count, true);
        if (velocity_tracks != nullptr) load_track_array(parser, block, "velocity_track", velocity_tracks, velocity_track_count, false);
        if (gravity_tracks != nullptr) load_track_array(parser, block, "gravitation_track", gravity_tracks, gravity_track_count, false);
    }
    if (parser.findBlock("texture_def", &block, &range, 1)) {
        if (parser.findValue("numframes", &block)) {
            const std::int32_t count = parser.readInt(0u);
            if (count > 0) {
                texture_frame_count = static_cast<std::uint32_t>(count);
                texture_frames = allocate_effect_array<SferaParticleTextureFrame>(texture_frame_count);
                for (std::uint32_t index = 0u; index < texture_frame_count; ++index) {
                    texture_frames[index].texture_id = -1;
                    const float uv[8]{0.0f,0.0f,1.0f,0.0f,1.0f,1.0f,0.0f,1.0f};
                    std::memcpy(texture_frames[index].uv, uv, sizeof(uv));
                }
            }
        }
        if (parser.findValue("type", &block) && SferaSimpleParser::equalsIgnoreCase(parser.tokenAt(0u), "PS_TANIMCOORD")) flags |= (1u << 9u);
        if (parser.findValue("blendmode", &block) && SferaSimpleParser::equalsIgnoreCase(parser.tokenAt(0u), "PS_BLENDADD")) texture_flags |= 1u;
        if (parser.findValue("animspeed", &block)) texture_animation_speed = parser.readFloat(0u);
        if (texture_frames != nullptr && parser.findValue("texture", &block) && parser.readQuotedString(0u, text) != nullptr) replace_effect_string(texture_frames[0].texture_name, text);
        parser.setScanRange(&block);
        while (texture_frames != nullptr && parser.nextValue("frame")) {
            const std::int32_t index = parser.readInt(0u);
            if (index < 0 || static_cast<std::uint32_t>(index) >= texture_frame_count) continue;
            if ((flags & (1u << 9u)) != 0u) {
                parser.readFloatSequence(1u, texture_frames[index].uv, 8u);
                texture_flags |= 2u;
            } else if (parser.readQuotedString(1u, text) != nullptr) replace_effect_string(texture_frames[index].texture_name, text);
        }
        parser.clearScanRange();
    }
    if (render_slots != nullptr && render_slot_count != 0u && parser.countBlocks("particles_def", &range) > 0) {
        std::vector<std::uint8_t> selected(render_slot_count, 1u);
        SferaParserRange particles{};
        parser.setBlockRange(&range);
        while (parser.nextBlock("particles_def", &particles)) {
            std::fill(selected.begin(), selected.end(), 1u);
            if (parser.findValue("select", &particles)) {
                const char* mode = parser.tokenAt(0u);
                if (SferaSimpleParser::equalsIgnoreCase(mode, "range")) {
                    std::fill(selected.begin(), selected.end(), 0u);
                    std::int32_t begin = parser.readInt(1u), end = parser.readInt(2u);
                    if (begin > end) std::swap(begin, end);
                    begin = std::max(begin, 0);
                    end = std::min(end, static_cast<std::int32_t>(render_slot_count));
                    if (begin < end) std::fill(selected.begin() + begin, selected.begin() + end, 1u);
                }
                else if (SferaSimpleParser::equalsIgnoreCase(mode, "number")) {
                    std::fill(selected.begin(), selected.end(), 0u);
                    for (std::uint32_t token = 1u; token < parser.tokenCount(); ++token) {
                        std::int32_t index = parser.readInt(token);
                        index = std::max(index, 0);
                        index = std::min(index, static_cast<std::int32_t>(render_slot_count) - 1);
                        selected[static_cast<std::uint32_t>(index)] = 1u;
                    }
                }
            }
            auto assign_track = [&](const char* key, auto member, SferaEffectTrack** tracks, std::uint32_t count) {
                if (!parser.findValue(key, &particles) || count == 0u) return;
                const std::int32_t parsed = parser.readInt(0u);
                if (parsed < 0 || static_cast<std::uint32_t>(parsed) >= count || tracks == nullptr) return;
                const std::uint16_t value = tracks[parsed] != nullptr ? static_cast<std::uint16_t>(parsed) : std::numeric_limits<std::uint16_t>::max();
                for (std::uint32_t index = 0u; index < render_slot_count; ++index) if (selected[index] == 1u) render_slots[index].*member = value;
            };
            assign_track("size_track", &SferaParticleRenderSlot::size_track_index, size_tracks, size_track_count);
            assign_track("color_track", &SferaParticleRenderSlot::color_track_index, color_tracks, color_track_count);
            assign_track("velocity_track", &SferaParticleRenderSlot::velocity_track_index, velocity_tracks, velocity_track_count);
            assign_track("gravitation_track", &SferaParticleRenderSlot::gravity_track_index, gravity_tracks, gravity_track_count);
            if (parser.findValue("texture_frame", &particles) && SferaSimpleParser::equalsIgnoreCase(parser.tokenAt(0u), "RANDOM")) flags |= (1u << 19u);
            if (parser.findValue("child_ps", &particles)) {
                const std::int32_t link = parser.readInt(0u);
                for (std::uint32_t index = 0u; index < render_slot_count; ++index) if (selected[index] == 1u) render_slots[index].link_index = link;
            }
        }
        parser.clearBlockRange();
    }
    for (std::uint32_t index = 0u; index < render_slot_count; ++index) if (render_slots[index].link_index >= 0 && static_cast<std::uint32_t>(render_slots[index].link_index) < link_count) ++links[render_slots[index].link_index].instance_count;
    runtime_random_row = static_cast<std::uint32_t>(std::rand() % 254);
    runtime_random_seed_0 = static_cast<std::uint32_t>(std::rand());
    runtime_random_seed_1 = static_cast<std::uint32_t>(std::rand());
    if ((flags & (1u << 6u)) != 0u) {
        const auto* random_values = ptr32<const std::uint16_t>(g_sfera_effect_manager.particle_random_table + (runtime_random_row << 9u));
        evaluate_particle_scalar(lifetime_track, 0.0f, lifetime, random_values, runtime_random_seed_0);
        evaluate_random_vector(emission_position_track, 0.0f, emitter_position, random_values, runtime_random_seed_0, runtime_random_seed_1);
        for (std::uint32_t index = 0u; index < render_slot_count; ++index) particle_generate(*this, index);
    }
    parser.setBlockRange(&caller_range);
    return true;
}
void SferaParticleSystemDefinition::initializeClone() {
    runtime_random_row = static_cast<std::uint32_t>(std::rand() % 255);
    runtime_random_seed_0 = static_cast<std::uint32_t>(std::rand());
    runtime_random_seed_1 = static_cast<std::uint32_t>(std::rand());
    for (std::uint32_t index = 0u; index < texture_frame_count; ++index) if (texture_frames != nullptr && texture_frames[index].texture_name != nullptr) texture_frames[index].texture_id = g_sfera_textures.find(texture_frames[index].texture_name);
}
void SferaParticleSystemDefinition::resetClone(const SferaParticleSystemDefinition& source) {
    emitter_position = source.emitter_position;
    emission_count = source.emission_count;
    active_particle_count = 0u;
    lifetime = source.lifetime;
    emission_fraction = 0.0f;
    flags = source.flags;
    power = source.power;
    magnet_factor = source.magnet_factor;
    magnet_position = source.magnet_position;
    first_update = 1u;
    runtime_stop_requested = 0u;
    phase_mode = 1u;
    runtime_active = 1u;
    std::memcpy(transform, source.transform, sizeof(transform));
    initializeClone();
    if (render_slots == nullptr || source.render_slots == nullptr) return;
    if ((flags & (1u << 6u)) != 0u) for (std::uint32_t index = 0u; index < std::min(render_slot_count, source.render_slot_count); ++index) {
        SferaParticleSystemDefinition* child = render_slots[index].linked_particle_system;
        std::memcpy(&render_slots[index], &source.render_slots[index], sizeof(SferaParticleRenderSlot));
        render_slots[index].linked_particle_system = child;
    }
    else for (std::uint32_t index = 0u; index < render_slot_count; ++index) render_slots[index].remaining_lifetime = -1.0f;
}
void SferaParticleSystemDefinition::destroyClone() {
    if (runtime_clone == 0u) {
        g_sfera_effect_manager.free(name);
        name = nullptr;
        release_effect_track(rotation_track);
        release_effect_track(scale_track);
        release_effect_track(position_track);
        release_effect_track(lifetime_track);
        release_effect_track(magnet_factor_track);
        release_effect_track(magnet_position_track);
        release_effect_track(power_track);
        release_effect_track(emission_track);
        release_effect_track(emission_position_track);
        release_track_array(size_tracks, size_track_count);
        release_track_array(color_tracks, color_track_count);
        release_track_array(velocity_tracks, velocity_track_count);
        release_track_array(gravity_tracks, gravity_track_count);
        g_sfera_effect_manager.free(shape_points);
        shape_points = nullptr;
        shape_point_count = 0u;
        if (texture_frames != nullptr) for (std::uint32_t index = 0u; index < texture_frame_count; ++index) g_sfera_effect_manager.free(texture_frames[index].texture_name);
        g_sfera_effect_manager.free(texture_frames);
        texture_frames = nullptr;
        texture_frame_count = 0u;
        if (links != nullptr) for (std::uint32_t index = 0u; index < link_count; ++index) g_sfera_effect_manager.free(links[index].target_name);
        g_sfera_effect_manager.free(links);
        links = nullptr;
        link_count = 0u;
    }
    g_sfera_effect_manager.free(render_slots);
    render_slots = nullptr;
    render_slot_count = 0u;
    active_particle_count = 0u;
}
void SferaParticleSystemDefinition::update(const SferaEffectVec3F* spatial_frame, const float* world_frame, float age) {
    if (runtime_active == 0u) return;
    const SferaEffectVec3F incoming = spatial_frame == nullptr ? current_position : *spatial_frame;
    if (first_update != 0u) {
        previous_position = incoming;
        previous_origin = current_position;
        first_update = 0u;
    } else previous_position = current_position;
    current_position = incoming;
    const auto* table = ptr32<const std::uint16_t>(g_sfera_effect_manager.particle_random_table);
    const std::uint16_t* random_values = table == nullptr ? nullptr : table + ((runtime_random_row & 255u) << 8u);
    if ((flags & (1u << 5u)) != 0u) {
        if (position_track != nullptr) {
            SferaEffectVec3F offset{};
            position_track->evaluateVector(age, offset);
            current_position.x += offset.x;
            current_position.y += offset.y;
            current_position.z += offset.z;
        }
        if ((flags & (1u << 27u)) != 0u && world_frame != nullptr) std::memcpy(transform, world_frame, sizeof(transform));
    }
    else {
        identity_matrix(transform);
        bool rotated = false;
        if (rotation_track != nullptr) {
            SferaEffectVec3F rotation{};
            rotation_track->evaluateVector(age, rotation);
            apply_particle_rotation(transform, flags, rotation);
            rotated = (flags & 15u) != 0u;
        }
        if (scale_track != nullptr) {
            SferaEffectVec3F scale{};
            scale_track->evaluateVector(age, scale);
            if (rotated || (flags & (1u << 4u)) != 0u) apply_particle_scale(transform, scale);
            else {
                transform[0] = scale.x;
                transform[5] = scale.y;
                transform[10] = scale.z;
            }
        }
        transform[3] = current_position.x;
        transform[7] = current_position.y;
        transform[11] = current_position.z;
        if (position_track != nullptr) {
            SferaEffectVec3F offset{};
            position_track->evaluateVector(age, offset);
            transform[3] += offset.x;
            transform[7] += offset.y;
            transform[11] += offset.z;
        }
        if ((flags & (1u << 27u)) != 0u && world_frame != nullptr) {
            float combined[16]{};
            multiply_matrix(combined, transform, world_frame);
            std::memcpy(transform, combined, sizeof(transform));
        }
    }
    evaluate_particle_scalar(emission_track, age, emission_count, random_values, runtime_random_seed_0);
    if (emission_position_track != nullptr) {
        SferaEffectVec3F value{};
        evaluate_random_vector(emission_position_track, age, value, random_values, runtime_random_seed_0, runtime_random_seed_1);
        if ((flags & (1u << 22u)) != 0u) {
            radius = value.x;
            height = value.y;
            width = value.z;
        } else emitter_position = value;
    }
    evaluate_particle_scalar(lifetime_track, age, lifetime, random_values, runtime_random_seed_0);
    evaluate_particle_scalar(power_track, age, power, random_values, runtime_random_seed_0);
    if ((flags & (1u << 8u)) != 0u) {
        if (magnet_position_track != nullptr) evaluate_random_vector(magnet_position_track, age, magnet_position, random_values, runtime_random_seed_0, runtime_random_seed_1);
        if ((flags & (1u << 21u)) != 0u && magnet_factor_track != nullptr) evaluate_random_vector(magnet_factor_track, age, magnet_factor, random_values, runtime_random_seed_0, runtime_random_seed_1);
    }
    const SferaEffectVec3F direct = (flags & (1u << 25u)) != 0u ? normalized({current_position.x - previous_origin.x, current_position.y - previous_origin.y, current_position.z - previous_origin.z}) : SferaEffectVec3F{1.0f, 1.0f, 1.0f};
    active_particle_count = 0u;
    for (std::uint32_t index = 0u; render_slots != nullptr && index < render_slot_count; ++index) {
        auto& slot = render_slots[index];
        if (slot.remaining_lifetime < 0.0f) continue;
        if ((flags & (1u << 13u)) == 0u) slot.remaining_lifetime -= 2.0f;
        if (slot.remaining_lifetime <= 0.0f) {
            slot.remaining_lifetime = -1.0f;
            continue;
        }
        const float local_time = (flags & (1u << 12u)) != 0u ? age : slot.total_lifetime == 0.0f ? 1.0f : 1.0f - slot.remaining_lifetime / slot.total_lifetime;
        const std::uint16_t* slot_random = table == nullptr ? nullptr : table + ((slot.random_row & 255u) << 8u);
        if (slot.size_track_index != std::numeric_limits<std::uint16_t>::max() && slot.size_track_index < size_track_count) evaluate_particle_scalar(size_tracks[slot.size_track_index], local_time, slot.size, slot_random, slot.random_seed_0);
        if (slot.color_track_index != std::numeric_limits<std::uint16_t>::max() && slot.color_track_index < color_track_count && color_tracks[slot.color_track_index] != nullptr) evaluate_mesh_color(*color_tracks[slot.color_track_index], local_time, slot.color, slot_random, slot.random_seed_0, slot.random_seed_1);
        SferaEffectVec3F motion{};
        if (slot.velocity_track_index != std::numeric_limits<std::uint16_t>::max() && slot.velocity_track_index < velocity_track_count) evaluate_random_vector(velocity_tracks[slot.velocity_track_index], local_time, motion, slot_random, slot.random_seed_0, slot.random_seed_1);
        if (slot.gravity_track_index != std::numeric_limits<std::uint16_t>::max() && slot.gravity_track_index < gravity_track_count) {
            SferaEffectVec3F gravity{};
            evaluate_random_vector(gravity_tracks[slot.gravity_track_index], local_time, gravity, slot_random, slot.random_seed_0, slot.random_seed_1);
            motion.x += gravity.x;
            motion.y += gravity.y;
            motion.z += gravity.z;
        }
        if ((flags & (1u << 8u)) != 0u) {
            SferaEffectVec3F factor = magnet_factor;
            if ((flags & (1u << 21u)) == 0u && magnet_factor_track != nullptr) evaluate_random_vector(magnet_factor_track, local_time, factor, slot_random, slot.random_seed_0, slot.random_seed_1);
            SferaEffectVec3F delta{magnet_position.x - slot.position.x, magnet_position.y - slot.position.y, magnet_position.z - slot.position.z};
            if ((flags & (1u << 17u)) != 0u) {
                const SferaEffectVec3F target{slot.spawn_position.x + (magnet_position.x - slot.spawn_position.x) * local_time, slot.spawn_position.y + (magnet_position.y - slot.spawn_position.y) * local_time, slot.spawn_position.z + (magnet_position.z - slot.spawn_position.z) * local_time};
                delta = {target.x - slot.position.x, target.y - slot.position.y, target.z - slot.position.z};
            }
            motion.x += factor.x * delta.x;
            motion.y += factor.y * delta.y;
            motion.z += factor.z * delta.z;
        }
        if ((flags & (1u << 16u)) != 0u) {
            slot.position.x += static_cast<float>(std::rand() - std::rand()) * 3.0518509447574615e-05f * distortion.x;
            slot.position.y += static_cast<float>(std::rand() - std::rand()) * 3.0518509447574615e-05f * distortion.y;
            slot.position.z += static_cast<float>(std::rand() - std::rand()) * 3.0518509447574615e-05f * distortion.z;
        }
        motion.x *= direct.x;
        motion.y *= direct.y;
        motion.z *= direct.z;
        slot.position.x += motion.x;
        slot.position.y += motion.y;
        slot.position.z += motion.z;
        slot.texture_frame += texture_animation_speed;
        if (texture_frame_count != 0u && slot.texture_frame > static_cast<float>(texture_frame_count - 1u)) slot.texture_frame = 0.0f;
        ++active_particle_count;
    }
    if ((flags & (1u << 7u)) == 0u && phase_mode != 0u) particle_emit(*this, 2.0f);
    if (active_particle_count == 0u && phase_mode == 0u && runtime_stop_requested != 0u) runtime_active = 0u;
    update_particle_children(*this, age);
}
void SferaParticleSystemDefinition::commit() {
    if (runtime_active == 0u || render_slots == nullptr || texture_frames == nullptr || texture_frame_count == 0u) return;
    for (std::uint32_t index = 0u; index < render_slot_count; ++index) if (render_slots[index].remaining_lifetime >= 0.0f && render_slots[index].linked_particle_system != nullptr) render_slots[index].linked_particle_system->commit();
    if (g_sfera_effect_manager.render_slot_count + render_slot_count >= 10000u) return;
    const std::uint32_t opacity = static_cast<std::uint32_t>(std::max(power, 0.0f) * 256.0f);
    if (opacity == 0u) return;
    for (std::uint32_t index = 0u; index < render_slot_count; ++index) {
        const auto& particle = render_slots[index];
        if (particle.remaining_lifetime < 0.0f) continue;
        SferaEffectRenderSlot* slot = g_sfera_effect_manager.acquireRenderSlot();
        if (slot == nullptr) break;
        const std::uint32_t frame = std::min(static_cast<std::uint32_t>(std::max(particle.texture_frame, 0.0f)), texture_frame_count - 1u);
        const auto& texture = texture_frames[frame];
        slot->resource_id = (flags & (1u << 9u)) != 0u ? texture_frames[0].texture_id : texture.texture_id;
        slot->blend_mode = self_illumination;
        slot->primitive_kind = texture_flags;
        const auto& uv = (flags & (1u << 9u)) != 0u ? texture : texture_frames[0];
        for (std::uint32_t vertex = 0u; vertex < 4u; ++vertex) {
            slot->uv[vertex][0] = uv.uv[vertex * 2u];
            slot->uv[vertex][1] = uv.uv[vertex * 2u + 1u];
        }
        for (std::uint32_t vertex = 0u; vertex < 4u; ++vertex) {
            slot->color[0][vertex] = particle.color.red;
            slot->color[1][vertex] = particle.color.green;
            slot->color[2][vertex] = particle.color.blue;
            slot->color[3][vertex] = static_cast<std::uint32_t>(particle.color.alpha) * opacity >> 8u;
        }
        if ((flags & (1u << 11u)) != 0u) for (std::uint32_t vertex = 0u; vertex < 4u; ++vertex) slot->position[vertex] = {particle.render_position.x + render_basis[vertex].x * particle.size, particle.render_position.y + render_basis[vertex].y * particle.size, particle.render_position.z + render_basis[vertex].z * particle.size};
        else {
            const SferaEffectVec3F view{particle.render_position.x - g_sfera_effect_manager.viewer_position.x, particle.render_position.y - g_sfera_effect_manager.viewer_position.y, particle.render_position.z - g_sfera_effect_manager.viewer_position.z};
            SferaEffectVec3F right{}, up{};
            build_y_up_billboard_axes(view, particle.size * render_basis[0].y, particle.size * render_basis[0].x, right, up);
            slot->position[0] = {particle.render_position.x - right.x - up.x, particle.render_position.y - right.y - up.y, particle.render_position.z - right.z - up.z};
            slot->position[1] = {particle.render_position.x - right.x + up.x, particle.render_position.y - right.y + up.y, particle.render_position.z - right.z + up.z};
            slot->position[2] = {particle.render_position.x + right.x + up.x, particle.render_position.y + right.y + up.y, particle.render_position.z + right.z + up.z};
            slot->position[3] = {particle.render_position.x + right.x - up.x, particle.render_position.y + right.y - up.y, particle.render_position.z + right.z - up.z};
        }
    }
}
namespace {
    struct SferaSoundEffectRegistry {
        std::uint32_t definitions;
        std::uint32_t end_or_reserved;
        std::uint32_t count;
    };
    std::uint64_t sound_clock_ticks() {
        return static_cast<std::uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() / 100);
    }
    void store_sound_clock(std::uint32_t& low, std::uint32_t& high) {
        const std::uint64_t value = sound_clock_ticks();
        low = static_cast<std::uint32_t>(value);
        high = static_cast<std::uint32_t>(value >> 32u);
    }
    float sound_elapsed(std::uint32_t low, std::uint32_t high) {
        const std::uint64_t start = static_cast<std::uint64_t>(low) | (static_cast<std::uint64_t>(high) << 32u);
        return static_cast<float>(static_cast<std::int64_t>(sound_clock_ticks() - start)) * 0.0001f;
    }
    std::uint32_t sound_flag(const char* token) {
        if (SferaSimpleParser::equalsIgnoreCase(token, "SF_TYPE_ENVIRONMENT")) return 1u << 0u;
        if (SferaSimpleParser::equalsIgnoreCase(token, "SF_PLAY_RANDOM")) return 1u << 2u;
        if (SferaSimpleParser::equalsIgnoreCase(token, "SF_PLAY_RANDOMMIX")) return 1u << 3u;
        if (SferaSimpleParser::equalsIgnoreCase(token, "SF_PLAY_LOOPED")) return 1u << 4u;
        if (SferaSimpleParser::equalsIgnoreCase(token, "SF_PLAY_USEREGION")) return 1u << 5u;
        if (SferaSimpleParser::equalsIgnoreCase(token, "SF_PLAY_TIMEGROUPS")) return 1u << 6u;
        return 0u;
    }
    struct SemanticSoundCacheEntry {
        CSound* sound;
        std::chrono::steady_clock::time_point idle_since;
        bool idle_started;
    };
    std::vector<SemanticSoundCacheEntry>& semantic_sound_cache() {
        static std::vector<SemanticSoundCacheEntry> cache;
        return cache;
    }
    void destroy_semantic_sound(CSound* sound) {
        if (sound == nullptr) return;
        if (sound->IsSoundPlaying() != 0) sound->CSound::Stop();
        sound->~CSound();
        std::free(sound);
    }
    void service_semantic_sound_cache() {
        auto& cache = semantic_sound_cache();
        const auto now = std::chrono::steady_clock::now();
        for (std::size_t index = 0u; index < cache.size();) {
            auto& entry = cache[index];
            CSound* sound = entry.sound;
            if (sound == nullptr) {
                cache.erase(cache.begin() + static_cast<std::ptrdiff_t>(index));
                continue;
            }
            const bool playing = sound->IsSoundPlaying() != 0;
            sound->playback_finished = playing ? 0u : 1u;
            if (playing || sound->cache_available == 0u) {
                entry.idle_started = false;
                ++index;
                continue;
            }
            const std::int32_t lifetime = sound->cache_lifetime_seconds;
            if (lifetime < 0) {
                ++index;
                continue;
            }
            if (!entry.idle_started) {
                entry.idle_since = now;
                entry.idle_started = true;
            }
            if (lifetime != 0 && std::chrono::duration_cast<std::chrono::seconds>(now - entry.idle_since).count() < lifetime) {
                ++index;
                continue;
            }
            destroy_semantic_sound(sound);
            cache.erase(cache.begin() + static_cast<std::ptrdiff_t>(index));
        }
    }
    void release_active_sound(CSoundEffect& effect) {
        if (effect.active_sound == nullptr) return;
        auto* sound = effect.active_sound;
        if (sound != nullptr) {
            if (sound->playback_finished == 0u && sound->IsSoundPlaying() != 0) sound->CSound::Stop();
            sound->cache_available = 1u;
        }
        effect.active_sound = nullptr;
        service_semantic_sound_cache();
    }
    bool play_sound(CSound& sound, int looped, float position) {
        sound.SetPlayTimepos(position);
        if (sound.CSound::Play(looped) == 0) return false;
        sound.cache_idle_since_low = std::numeric_limits<std::uint32_t>::max();
        sound.cache_idle_since_high = std::numeric_limits<std::uint32_t>::max();
        sound.playback_finished = 0u;
        return true;
    }
    CSound* find_cached_sound(const char* filename) {
        if (filename == nullptr) return nullptr;
        service_semantic_sound_cache();
        for (auto& entry : semantic_sound_cache()) {
            CSound* sound = entry.sound;
            if (sound == nullptr || sound->IsSoundPlaying() != 0 || sound->cache_available == 0u) continue;
            const char* name = sound->filename;
            if (name != nullptr && SferaSimpleParser::equalsIgnoreCase(filename, name)) {
                entry.idle_started = false;
                return sound;
            }
        }
        return nullptr;
    }
    CSound* create_cached_sound(CSoundManager& manager, const char* filename, const SferaSound3DParameters* parameters, std::int32_t cache_lifetime) {
        if (manager.enabled == 0u || filename == nullptr) return nullptr;
        CSound* sound = find_cached_sound(filename);
        if (sound == nullptr) {
            FILE* file = nullptr;
            if (fopen_s(&file, filename, "rb") != 0 || file == nullptr) return nullptr;
            std::fclose(file);
            void* memory = std::calloc(1u, sizeof(CSound));
            if (memory == nullptr) return nullptr;
            sound = ::new (memory) CSound();
            std::construct_at(reinterpret_cast<CSoundFX*>(sound));
            sound->cache_idle_since_low = std::numeric_limits<std::uint32_t>::max();
            sound->cache_idle_since_high = std::numeric_limits<std::uint32_t>::max();
            sound->cache_lifetime_seconds = 0u;
            sound->cache_available = 1u;
            sound->playback_finished = 1u;
            sound->cache_next = nullptr;
            sound->cache_previous = nullptr;
            const unsigned long load_flags = parameters == nullptr ? (1ul << 3u) : ((1ul << 0u) | (1ul << 3u) | (1ul << 5u));
            if (sound->LoadSound(filename, load_flags) == 0) {
                destroy_semantic_sound(sound);
                return nullptr;
            }
            semantic_sound_cache().push_back({sound, {}, false});
        }
        sound->cache_lifetime_seconds = cache_lifetime;
        sound->cache_available = 1u;
        if (parameters != nullptr) sound->SetAllParameters(reinterpret_cast<const DS3DBUFFER*>(parameters), 0);
        sound->SetVolume(manager.volume);
        return sound;
    }
    void release_sound_sources(CSoundEffect& effect) {
        if (effect.sources != nullptr) {
            auto* sources = effect.sources;
            for (std::uint32_t index = 0u; index < effect.source_count; ++index) std::free(sources[index].filename);
            std::free(sources);
        }
        effect.sources = nullptr;
        effect.source_count = 0u;
    }
    bool allocate_sound_sources(CSoundEffect& effect, std::uint32_t count) {
        release_sound_sources(effect);
        if (count == 0u) return true;
        auto* values = static_cast<SferaSoundSource*>(std::calloc(1u, static_cast<std::size_t>(count) * sizeof(SferaSoundSource)));
        if (values == nullptr) return false;
        effect.sources = values;
        effect.source_count = count;
        return true;
    }
    bool allocate_sound_time_groups(CSoundEffect& effect, std::uint32_t count) {
        std::free(effect.time_groups);
        effect.time_groups = nullptr;
        effect.time_group_count = 0u;
        if (count == 0u) return true;
        auto* values = static_cast<SferaSoundTimeGroup*>(std::calloc(1u, static_cast<std::size_t>(count) * sizeof(SferaSoundTimeGroup)));
        if (values == nullptr) return false;
        effect.time_groups = values;
        effect.time_group_count = count;
        return true;
    }
    bool assign_sound_filename(SferaSoundSource& source, const char* filename) {
        std::free(source.filename);
        source.filename = nullptr;
        if (filename == nullptr) return false;
        const std::size_t size = std::strlen(filename) + 1u;
        auto* copy = static_cast<char*>(std::calloc(1u, size));
        if (copy == nullptr) return false;
        std::memcpy(copy, filename, size);
        source.filename = copy;
        return true;
    }
    bool sound_time_matches(float value, const SferaSoundTimeGroup& group) {
        return group.end < group.begin ? value < group.end || value >= group.begin : value >= group.begin && value < group.end;
    }
    std::uint32_t choose_sound_source(CSoundEffect& effect) {
        if ((effect.flags & (1u << 6u)) != 0u && effect.time_groups != nullptr && effect.time_group_count != 0u) {
            auto* groups = effect.time_groups;
            std::uint32_t selected = effect.time_group_count;
            for (std::uint32_t index = 0u; index < effect.time_group_count; ++index) if (sound_time_matches(g_sfera_graphics_runtime.environment_factor, groups[index])) {
                selected = index;
                break;
            }
            if (selected == effect.time_group_count) return 0u;
            const auto& group = groups[selected];
            if ((effect.flags & ((1u << 2u) | (1u << 3u))) != 0u && group.source_end >= group.source_begin && group.source_end - group.source_begin + 1u > 1u) {
                std::uint32_t value = group.source_begin;
                do value = group.source_begin + static_cast<std::uint32_t>(std::rand()) % (group.source_end - group.source_begin + 1u);
                while (value == static_cast<std::uint32_t>(effect.last_source_index));
                return value;
            }
            return group.source_begin;
        }
        if ((effect.flags & ((1u << 2u) | (1u << 3u))) != 0u && effect.source_count > 1u) {
            std::uint32_t value = 0u;
            do value = static_cast<std::uint32_t>(std::rand()) % effect.source_count;
            while (value == static_cast<std::uint32_t>(effect.last_source_index));
            return value;
        }
        return 0u;
    }
    bool sound_distance_gate(CSoundEffect& effect, void* frame, float distance) {
        if ((effect.flags & (1u << 0u)) != 0u) return true;
        if (distance > effect.sound_parameters.max_distance) {
            if (effect.distance_paused == 0u) {
                if (effect.active_sound != nullptr) {
                    auto* sound = effect.active_sound;
                    if ((effect.flags & ((1u << 2u) | (1u << 3u) | (1u << 4u))) == 0u) effect.saved_play_time = sound->GetPlayTimepos();
                    release_active_sound(effect);
                }
                effect.silence_active = 0u;
                effect.distance_paused = 1u;
                store_sound_clock(effect.transition_started_low, effect.transition_started_high);
            }
            return false;
        }
        if (effect.distance_paused == 0u) return true;
        const float elapsed = sound_elapsed(effect.transition_started_low, effect.transition_started_high);
        if ((effect.flags & ((1u << 2u) | (1u << 3u) | (1u << 4u))) == 0u && effect.active_sound != nullptr) {
            auto* sound = effect.active_sound;
            const float resume = effect.saved_play_time + elapsed;
            const float length = sound->duration_seconds;
            if (resume > length) {
                release_active_sound(effect);
                effect.distance_paused = 0u;
                return true;
            }
            play_sound(*sound, 0, resume);
            effect.distance_paused = 0u;
            return true;
        }
        effect.distance_paused = 0u;
        effect.start(frame, false);
        return true;
    }
    CSoundEffect* find_sound_definition(std::uint32_t effect_id) {
        auto* registry = ptr32<SferaSoundEffectRegistry>(g_sfera_sound_runtime.effect_manager);
        if (registry == nullptr || registry->definitions == 0u || registry->count == 0u) return nullptr;
        auto* definitions = ptr32<std::uint32_t>(registry->definitions);
        std::uint32_t left = 0u;
        std::uint32_t right = registry->count;
        while (left < right) {
            const std::uint32_t middle = left + (right - left) / 2u;
            auto* definition = ptr32<CSoundEffect>(definitions[middle]);
            if (definition == nullptr) return nullptr;
            if (definition->effect_number < effect_id) left = middle + 1u;
            else right = middle;
        }
        if (left >= registry->count) return nullptr;
        auto* definition = ptr32<CSoundEffect>(definitions[left]);
        return definition != nullptr && definition->effect_number == effect_id ? definition : nullptr;
    }
    bool grow_sound_effect_pool() {
        auto& pool = g_sfera_sound_effect_items;
        if (pool.growth_count == 0u) return false;
        const std::uint32_t block_count = pool.block_vector_begin == 0u ? 0u : (pool.block_vector_end - pool.block_vector_begin) / sizeof(std::uint32_t);
        const std::size_t payload_size = sizeof(std::uint32_t) + static_cast<std::size_t>(pool.growth_count) * sizeof(CSoundEffect);
        auto* payload = static_cast<std::uint8_t*>(std::calloc(1u, payload_size));
        if (payload == nullptr) return false;
        *reinterpret_cast<std::uint32_t*>(payload) = pool.growth_count;
        auto* objects = reinterpret_cast<CSoundEffect*>(payload + sizeof(std::uint32_t));
        for (std::uint32_t index = 0u; index < pool.growth_count; ++index) objects[index].initialize();
        const std::uint32_t new_capacity = (block_count + 1u) * pool.growth_count;
        auto* new_free = static_cast<std::uint32_t*>(std::calloc(1u, static_cast<std::size_t>(new_capacity) * sizeof(std::uint32_t)));
        auto* new_blocks = static_cast<std::uint32_t*>(std::calloc(1u, static_cast<std::size_t>(block_count + 1u) * sizeof(std::uint32_t)));
        if (new_free == nullptr || new_blocks == nullptr) {
            std::free(new_free);
            std::free(new_blocks);
            std::free(payload);
            return false;
        }
        auto* old_free = ptr32<std::uint32_t>(pool.free_items);
        auto* old_blocks = ptr32<std::uint32_t>(pool.block_vector_begin);
        if (old_free != nullptr && pool.free_count != 0u) std::memcpy(new_free, old_free, static_cast<std::size_t>(pool.free_count) * sizeof(std::uint32_t));
        if (old_blocks != nullptr && block_count != 0u) std::memcpy(new_blocks, old_blocks, static_cast<std::size_t>(block_count) * sizeof(std::uint32_t));
        for (std::uint32_t index = 0u; index < pool.growth_count; ++index) new_free[pool.free_count + index] = address32(&objects[index]);
        new_blocks[block_count] = address32(objects);
        std::free(old_free);
        std::free(old_blocks);
        pool.free_items = address32(new_free);
        pool.free_count += pool.growth_count;
        pool.block_vector_begin = address32(new_blocks);
        pool.block_vector_end = pool.block_vector_begin + (block_count + 1u) * sizeof(std::uint32_t);
        pool.block_vector_capacity_end = pool.block_vector_end;
        return true;
    }
}
void CSoundEffect::initialize() {
    std::memset(this, 0, sizeof(*this));
    mix_duration = 1.0f;
    last_source_index = -1;
    cache_lifetime = 4;
    shared_definition = 0u;
    sound_parameters.structure_size = sizeof(SferaSound3DParameters);
    sound_parameters.inside_cone_angle = 360u;
    sound_parameters.outside_cone_angle = 360u;
    sound_parameters.cone_outside_volume = -1;
    sound_parameters.min_distance = 1.0f;
    sound_parameters.max_distance = 1000000000.0f;
}
bool CSoundEffect::loadDefinition(SferaSimpleParser& parser, const SferaParserRange& range) {
    flags = 0u;
    if (parser.findValue("eff_number", &range)) effect_number = static_cast<std::uint32_t>(parser.readInt(0u));
    SferaParserRange block{};
    char text[1024]{};
    if (parser.findBlock("audio_files", &block, &range, 1)) {
        parser.setScanRange(&block);
        std::uint32_t source_lines = 0u;
        while (parser.nextValue("source")) ++source_lines;
        if (source_lines == 0u || !allocate_sound_sources(*this, source_lines)) {
            parser.clearScanRange();
            return false;
        }
        parser.setScanRange(&block);
        while (parser.nextValue("source")) {
            const std::int32_t index = parser.readInt(0u);
            if (index < 0 || static_cast<std::uint32_t>(index) >= source_count) {
                parser.clearScanRange();
                return false;
            }
            auto& source = sources[index];
            if (parser.readQuotedString(1u, text) == nullptr) {
                parser.clearScanRange();
                return false;
            }
            if (SferaSimpleParser::equalsIgnoreCase(text, "silence")) {
                source.silence = 1u;
                source.silence_duration = parser.readFloat(2u);
            } else if (!assign_sound_filename(source, text)) {
                parser.clearScanRange();
                return false;
            }
        }
        parser.clearScanRange();
    } else if (parser.findValue("audio_file", &range)) {
        if (!allocate_sound_sources(*this, 1u) || parser.readQuotedString(0u, text) == nullptr || !assign_sound_filename(sources[0], text)) return false;
    } else return false;
    if (parser.findBlock("time_groups", &block, &range, 1)) {
        parser.setScanRange(&block);
        std::uint32_t count = 0u;
        while (parser.nextValue("time")) ++count;
        if (!allocate_sound_time_groups(*this, count)) {
            parser.clearScanRange();
            return false;
        }
        parser.setScanRange(&block);
        std::uint32_t index = 0u;
        while (parser.nextValue("time") && index < count) {
            float begin = parser.readFloat(0u);
            float end = parser.readFloat(1u);
            std::int32_t source_begin = parser.readInt(2u);
            std::int32_t source_end = parser.readInt(3u);
            if (source_begin < 0 || source_end < 0 || static_cast<std::uint32_t>(source_begin) >= source_count || static_cast<std::uint32_t>(source_end) >= source_count) {
                parser.clearScanRange();
                return false;
            }
            auto& group = time_groups[index++];
            group.begin = begin == 0.0f ? 1.0f : 1.0f - begin / 24.0f;
            group.end = end == 0.0f ? 1.0f : 1.0f - end / 24.0f;
            group.source_begin = static_cast<std::uint32_t>(std::min(source_begin, source_end));
            group.source_end = static_cast<std::uint32_t>(std::max(source_begin, source_end));
        }
        parser.clearScanRange();
    }
    if (parser.findValue("flags", &range)) for (std::uint32_t index = 0u; index < parser.tokenCount(); index += 2u) flags |= sound_flag(parser.tokenAt(index));
    if (parser.findValue("region_radius", &range)) parser.readFloatSequence(0u, &region_radius.x, 3u);
    bool has_min = false;
    bool has_max = false;
    if (parser.findValue("min_distance", &range)) {
        sound_parameters.min_distance = parser.readFloat(0u);
        has_min = true;
    }
    if (parser.findValue("max_distance", &range)) {
        sound_parameters.max_distance = parser.readFloat(0u);
        has_max = true;
    }
    if (parser.findValue("mix_duration", &range)) mix_duration = parser.readFloat(0u);
    float barrier = 0.03f;
    if (parser.findValue("vol_barier", &range)) {
        barrier = parser.readFloat(0u);
        barrier = barrier == 0.0f ? 0.01f : std::min(barrier / 100.0f, 1.0f);
    }
    if (has_min && !has_max && barrier > 0.0f) sound_parameters.max_distance = sound_parameters.min_distance / barrier;
    else if (has_max && !has_min) sound_parameters.min_distance = sound_parameters.max_distance * barrier;
    if (parser.findValue("offset_vec", &range)) parser.readFloatSequence(0u, &offset.x, 3u);
    if (parser.findValue("cache_lifetime", &range)) cache_lifetime = std::clamp(parser.readInt(0u), 0, 10);
    return true;
}
CSoundEffect* CSoundEffect::clone() const {
    auto* result = static_cast<CSoundEffect*>(g_sfera_effect_manager.allocate(sizeof(CSoundEffect)));
    if (result == nullptr) return nullptr;
    result->initialize();
    result->resetFrom(*this);
    return result;
}
void CSoundEffect::resetFrom(const CSoundEffect& source) {
    active_sound = nullptr;
    last_position = {};
    effect_number = source.effect_number;
    flags = source.flags;
    silence_active = source.silence_active;
    silence_duration = source.silence_duration;
    saved_play_time = source.saved_play_time;
    sources = source.sources;
    source_count = source.source_count;
    time_groups = source.time_groups;
    time_group_count = source.time_group_count;
    distance_paused = source.distance_paused;
    offset = source.offset;
    region_radius = source.region_radius;
    region_offset = source.region_offset;
    mix_duration = source.mix_duration;
    last_source_index = source.last_source_index;
    cache_lifetime = source.cache_lifetime;
    sound_parameters = source.sound_parameters;
    shared_definition = 1u;
}
void CSoundEffect::destroy() {
    if (shared_definition == 0u) {
        release_sound_sources(*this);
        std::free(time_groups);
    }
    release_active_sound(*this);
    silence_active = 0u;
    distance_paused = 0u;
    sources = nullptr;
    source_count = 0u;
    time_groups = nullptr;
    time_group_count = 0u;
    shared_definition = 0u;
}
float CSoundEffect::startTime() const {
    return sound_parameters.max_distance;
}
void CSoundEffect::start(void* frame, bool after_start_time) {
    if (sources == nullptr || source_count == 0u || g_sfera_sound_runtime.manager == 0u) return;
    release_active_sound(*this);
    const std::uint32_t index = std::min(choose_sound_source(*this), source_count - 1u);
    last_source_index = static_cast<std::int32_t>(index);
    const auto& source = sources[index];
    if (source.silence != 0u) {
        silence_active = 1u;
        silence_duration = source.silence_duration;
        store_sound_clock(silence_started_low, silence_started_high);
        return;
    }
    const char* filename = source.filename;
    auto* manager = ptr32<CSoundManager>(g_sfera_sound_runtime.manager);
    if (manager == nullptr || filename == nullptr) return;
    if ((flags & (1u << 5u)) != 0u) {
        auto random_component = [](float radius) {
            return static_cast<float>(std::rand() - std::rand()) * 3.0518509447574615e-05f * radius;
        };
        region_offset = {random_component(region_radius.x), random_component(region_radius.y), random_component(region_radius.z)};
    }
    if (frame != nullptr) {
        const auto& position = *static_cast<const SferaEffectVec3F*>(frame);
        sound_parameters.position = {position.x - offset.x + region_offset.x, position.y - offset.y + region_offset.y, position.z - offset.z + region_offset.z};
        last_position = sound_parameters.position;
    }
    if (after_start_time && (flags & ((1u << 2u) | (1u << 3u) | (1u << 4u))) != 0u) {
        distance_paused = 1u;
        store_sound_clock(transition_started_low, transition_started_high);
        return;
    }
    auto* sound = create_cached_sound(*manager, filename, (flags & (1u << 0u)) != 0u ? nullptr : &sound_parameters, cache_lifetime);
    if (sound != nullptr) {
        active_sound = sound;
        sound->cache_available = 0u;
        if (!after_start_time) play_sound(*sound, static_cast<int>(flags & (1u << 4u)), 0.0f);
    }
    distance_paused = after_start_time ? 1u : 0u;
    if (after_start_time) store_sound_clock(transition_started_low, transition_started_high);
}
void CSoundEffect::update(void* frame, float age) {
    service_semantic_sound_cache();
    if (!sound_distance_gate(*this, frame, age)) return;
    if (silence_active != 0u) {
        const float elapsed = sound_elapsed(silence_started_low, silence_started_high);
        if (elapsed < 0.0f) {
            silence_active = 0u;
            return;
        }
        if ((flags & (1u << 3u)) != 0u && elapsed >= silence_duration - mix_duration) {
            silence_active = 0u;
            start(frame, false);
            return;
        }
        if (elapsed >= silence_duration) silence_active = 0u;
        return;
    }
    if (active_sound == nullptr) return;
    auto* sound = active_sound;
    if (sound == nullptr) {
        active_sound = nullptr;
        return;
    }
    if (sound->IsSoundPlaying() == 0 || sound->playback_finished != 0u) {
        sound->cache_available = 1u;
        active_sound = nullptr;
        service_semantic_sound_cache();
        return;
    }
    if ((flags & (1u << 3u)) != 0u) {
        const float length = sound->duration_seconds;
        if (sound->GetPlayTimepos() >= length - mix_duration) {
            release_active_sound(*this);
            start(frame, false);
            if (active_sound == nullptr) return;
            sound = active_sound;
        }
    }
    if ((flags & (1u << 0u)) != 0u || frame == nullptr || sound == nullptr) return;
    const auto& position = *static_cast<const SferaEffectVec3F*>(frame);
    const SferaEffectVec3F current{position.x - offset.x + region_offset.x, position.y - offset.y + region_offset.y, position.z - offset.z + region_offset.z};
    const SferaEffectVec3F velocity{current.x - last_position.x, current.y - last_position.y, current.z - last_position.z};
    if (velocity.x != 0.0f || velocity.y != 0.0f || velocity.z != 0.0f) {
        last_position = current;
        sound->SetVelocity(velocity.x, velocity.y, velocity.z, 0);
        sound->SetPosition(current.x, current.y, current.z, 0);
    }
}
void CSoundEffect::stop() {
    release_active_sound(*this);
    silence_active = 0u;
    distance_paused = 0u;
}
bool CSoundEffect::isComplete() const {
    if (distance_paused != 0u || silence_active != 0u) return false;
    return active_sound == nullptr || active_sound->playback_finished != 0u;
}

bool SferaSoundRuntime::interfaceAvailable() const {
    return SI_GetInterface() != nullptr;
}

CSoundEffect* SferaSoundRuntime::createEffect(std::uint32_t effect_id) {
    CSoundEffect* definition = find_sound_definition(effect_id);
    if (definition == nullptr) return nullptr;
    if (g_sfera_sound_effect_items.free_count == 0u && !grow_sound_effect_pool()) return nullptr;
    auto* result = static_cast<CSoundEffect*>(g_sfera_sound_effect_items.take());
    if (result == nullptr) return nullptr;
    result->resetFrom(*definition);
    return result;
}

void SferaSoundRuntime::destroyEffect(CSoundEffect* effect) {
    if (effect == nullptr) return;
    effect->stop();
    g_sfera_sound_effect_items.put(effect);
}

// Begin recovered files cluster.
SferaFileManager::~SferaFileManager() { for (const auto& file : open_files) ::_close(file.first); }
void SferaFileManager::setErrorReporting(bool enabled) { error_reporting_enabled = enabled; }
std::vector<std::string> SferaFileManager::candidatePaths(const char* filename, bool search_nested_paths) const {
    if (filename == nullptr) return {};
    std::vector<std::string> candidates{filename};
    if (search_nested_paths || std::strchr(filename, '\\') == nullptr) for (const std::string& directory : search_paths) candidates.push_back(directory + filename);
    return candidates;
}
void SferaFileManager::addSearchPath(const char* directory) {
    if (directory == nullptr || *directory == '\0') return;
    if (search_paths.size() == maximum_search_paths) { CSphereError error; error.write("File manager search path limit exceeded (100 paths)."); return; }
    std::string path(directory);
    if (path.back() != '\\') path.push_back('\\');
    search_paths.push_back(std::move(path));
}
int SferaFileManager::registerDescriptor(int descriptor, const std::string& filename) {
    if (descriptor == -1) return -1;
    if (open_files.size() == maximum_open_files) { ::_close(descriptor); CSphereError error; error.write("File manager open file limit exceeded (100 files)."); return -1; }
    try { open_files.insert_or_assign(descriptor, filename); }
    catch (...) { ::_close(descriptor); throw; }
    return descriptor;
}
int SferaFileManager::open(const char* filename, int flags) {
    for (const std::string& candidate : candidatePaths(filename)) {
        if (candidate.empty()) continue;
        int descriptor = -1;
        if (::_sopen_s(&descriptor, candidate.c_str(), flags | _O_BINARY, _SH_DENYNO, 0) == 0) return registerDescriptor(descriptor, candidate);
    }
    if (error_reporting_enabled) reportError("Unable to open file: ", filename);
    return -1;
}
int SferaFileManager::create(const char* filename) {
    if (filename != nullptr && *filename != '\0') {
        ::_chmod(filename, _S_IREAD | _S_IWRITE);
        int descriptor = -1;
        if (::_sopen_s(&descriptor, filename, _O_RDWR | _O_CREAT | _O_TRUNC | _O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE) == 0) return registerDescriptor(descriptor, filename);
    }
    if (error_reporting_enabled) reportError("Unable to create file: ", filename);
    return -1;
}
const std::string* SferaFileManager::filenameFor(int descriptor, const char* invalid_handle_message) const {
    const auto found = open_files.find(descriptor);
    if (found != open_files.end()) return &found->second;
    CSphereError error;
    error.write(invalid_handle_message);
    return nullptr;
}
int SferaFileManager::read(int descriptor, void* destination, std::uint32_t size) {
    const std::string* filename = filenameFor(descriptor, "Attempt of reading from the file with the wrong handle.");
    if (filename == nullptr) return -1;
    const int transferred = ::_read(descriptor, destination, size);
    if (transferred != -1 && static_cast<std::uint32_t>(transferred) == size) return transferred;
    if (error_reporting_enabled) reportError(transferred == -1 ? "Unable to read file: " : "Unexpected end of file: ", filename->c_str());
    return -1;
}
int SferaFileManager::write(int descriptor, const void* source, std::uint32_t size) {
    const std::string* filename = filenameFor(descriptor, "Attempt of writing to the file with the wrong handle.");
    if (filename == nullptr) return -1;
    const int transferred = ::_write(descriptor, source, size);
    if (transferred != -1 && static_cast<std::uint32_t>(transferred) == size) return transferred;
    if (error_reporting_enabled) reportError(transferred == -1 ? "Unable to write file: " : "Incomplete file write (possibly insufficient disk space): ", filename->c_str());
    return -1;
}
std::int32_t SferaFileManager::seek(int descriptor, std::int32_t offset, int origin) {
    const std::string* filename = filenameFor(descriptor, "Attempt of seeking in the file with the wrong handle.");
    if (filename == nullptr) return -1;
    const long position = ::_lseek(descriptor, offset, origin);
    if (position == -1 && error_reporting_enabled) reportError("Unable to seek in file: ", filename->c_str());
    return static_cast<std::int32_t>(position);
}
int SferaFileManager::close(int descriptor) {
    const std::string* filename = filenameFor(descriptor, "Attempt of closing the file with the wrong handle.");
    if (filename == nullptr) return -1;
    if (::_close(descriptor) == 0) { open_files.erase(descriptor); return 0; }
    if (error_reporting_enabled) reportError("Unable to close file: ", filename->c_str());
    return -1;
}
std::int32_t SferaFileManager::fileSize(const char* filename) {
    const int descriptor = open(filename, _O_RDONLY);
    if (descriptor == -1) return -1;
    const long length = ::_filelength(descriptor);
    close(descriptor);
    return static_cast<std::int32_t>(length);
}
void SferaFileManager::reportError(const char* description, const char* filename) const {
    std::string message(description);
    if (filename != nullptr) message += filename;
    CSphereError error;
    error.write(message.c_str());
}

// End recovered files cluster.

// Begin recovered quickfile cluster.
// CHash16 and QuickFile: recovered hash index and cached script files.
namespace {
    std::uint8_t hash16_fold_byte(std::uint8_t value) {
        if ((value >= 'A' && value <= 'Z') || (value >= 0xC0u && value <= 0xDFu)) return static_cast<std::uint8_t>(value + 0x20u);
        return value == 0xA8u ? 0xB8u : value;
    }
    std::uint16_t hash16_key_hash(const std::uint8_t* key, std::uint32_t length, bool fold_case) {
        static const auto checksum = [] {
            std::array<std::uint16_t, 256> values{};
            std::uint32_t carry = 0u;
            for (std::uint32_t byte = 0u; byte < values.size(); ++byte) {
                std::uint32_t crc = byte;
                for (std::uint32_t bit = 0u; bit < 8u; ++bit) {
                    const bool set = (crc & 1u) != 0u;
                    crc = (crc >> 1u) ^ (set ? 0xEDB88320u : 0u);
                    carry = (carry >> 1u) ^ (set ? 0xEDB88320u : 0u);
                }
                values[byte] = static_cast<std::uint16_t>(carry);
            }
            return values;
        }();
        std::uint16_t value = 0u;
        for (std::uint32_t offset = 0u; offset < length; ++offset) value = static_cast<std::uint16_t>((value >> 1u) + checksum[fold_case ? hash16_fold_byte(key[offset]) : key[offset]]);
        return value;
    }
}

std::uint8_t* CHash16Entry::key() { return reinterpret_cast<std::uint8_t*>(this) + sizeof(CHash16Entry); }
const std::uint8_t* CHash16Entry::key() const { return reinterpret_cast<const std::uint8_t*>(this) + sizeof(CHash16Entry); }
CHash16Entry& CHash16::entry(std::uint16_t index) { return *reinterpret_cast<CHash16Entry*>(reinterpret_cast<std::uint8_t*>(entries) + static_cast<std::size_t>(index) * entry_stride); }

CHash16* CHash16::initialize(std::uint32_t maximum_key_length, std::uint32_t absent_value, std::uint32_t initial_capacity) {
    max_key_length = maximum_key_length;
    missing_value = absent_value;
    entries = nullptr;
    entry_stride = 0u;
    entry_capacity = 0u;
    free_entry = no_entry;
    std::fill(std::begin(buckets), std::end(buckets), no_entry);
    if (maximum_key_length > UINT32_MAX - sizeof(CHash16Entry) || initial_capacity > no_entry) throw std::length_error("CHash16: invalid storage dimensions");
    entry_stride = maximum_key_length + sizeof(CHash16Entry);
    reserve(initial_capacity);
    return this;
}

void CHash16::release() {
    std::free(entries);
    entries = nullptr;
    entry_capacity = 0u;
    free_entry = no_entry;
    std::fill(std::begin(buckets), std::end(buckets), no_entry);
}

std::uint32_t CHash16::find(const void* key, std::uint32_t length, bool fold_case) {
    if (key == nullptr) return missing_value;
    const bool normalize = length == 0u && fold_case;
    if (length == 0u) {
        const std::size_t string_length = std::strlen(static_cast<const char*>(key));
        if (string_length > max_key_length) return missing_value;
        length = static_cast<std::uint32_t>(string_length);
    }
    if (length > max_key_length || entries == nullptr) return missing_value;
    const auto* bytes = static_cast<const std::uint8_t*>(key);
    auto& head = buckets[hash16_key_hash(bytes, length, normalize)];
    std::uint16_t previous = no_entry;
    for (std::uint16_t current = head; current != no_entry; current = entry(current).next) {
        auto& candidate = entry(current);
        bool matches = candidate.length == length;
        for (std::uint32_t offset = 0u; matches && offset < length; ++offset) matches = candidate.key()[offset] == (normalize ? hash16_fold_byte(bytes[offset]) : bytes[offset]);
        if (matches) {
            if (previous != no_entry) {
                entry(previous).next = candidate.next;
                candidate.next = head;
                head = current;
            }
            return candidate.value;
        }
        previous = current;
    }
    return missing_value;
}

void CHash16::reserve(std::uint32_t capacity) {
    if (capacity <= entry_capacity) return;
    if (capacity > no_entry) throw std::length_error("CHash16::register_str: more than 65535 elements");
    if (entry_stride == 0u || capacity > std::numeric_limits<std::size_t>::max() / entry_stride) throw std::length_error("CHash16: storage size overflow");
    auto* replacement = static_cast<CHash16Entry*>(std::realloc(entries, static_cast<std::size_t>(capacity) * entry_stride));
    if (replacement == nullptr) throw std::bad_alloc();
    entries = replacement;
    free_entry = static_cast<std::uint16_t>(entry_capacity);
    for (std::uint32_t slot = entry_capacity; slot < capacity; ++slot) entry(static_cast<std::uint16_t>(slot)).next = slot + 1u < capacity ? static_cast<std::uint16_t>(slot + 1u) : no_entry;
    entry_capacity = capacity;
}

bool CHash16::insert(const void* key, std::uint32_t length, std::uint32_t value, bool fold_case) {
    if (key == nullptr) throw std::invalid_argument("CHash16::register_str: null key");
    if (find(key, length, fold_case) != missing_value) return false;
    const bool normalize = length == 0u && fold_case;
    const std::size_t key_length = length == 0u ? std::strlen(static_cast<const char*>(key)) : length;
    if (key_length > max_key_length) throw std::length_error("CHash16::register_str: maxStrLen exceed");
    length = static_cast<std::uint32_t>(key_length);
    if (free_entry == no_entry) {
        if (entry_capacity == no_entry) throw std::length_error("CHash16::register_str: more than 65535 elements");
        reserve(std::min<std::uint32_t>(no_entry, entry_capacity + std::max<std::uint32_t>(50u, entry_capacity / 6u)));
    }
    const std::uint16_t current = free_entry;
    auto& inserted = entry(current);
    free_entry = inserted.next;
    const auto* bytes = static_cast<const std::uint8_t*>(key);
    for (std::uint32_t offset = 0u; offset < length; ++offset) inserted.key()[offset] = normalize ? hash16_fold_byte(bytes[offset]) : bytes[offset];
    auto& head = buckets[hash16_key_hash(inserted.key(), length, false)];
    inserted.length = length;
    inserted.value = value;
    inserted.next = head;
    head = current;
    return true;
}

QuickFile* QuickFile::initialize(const char* directory) {
    std::fill(std::begin(files), std::end(files), QuickFileEntry{});
    count = 0u;
    index.initialize(32u, UINT32_MAX, 300u);
    if (directory == nullptr || directory[0] == '\0') return this;
    std::error_code error;
    std::filesystem::directory_iterator cursor(std::filesystem::path(directory), error);
    const std::filesystem::directory_iterator end;
    while (!error && cursor != end) {
        const auto path = cursor->path();
        std::string extension = path.extension().string();
        for (char& character : extension) character = static_cast<char>(hash16_fold_byte(static_cast<std::uint8_t>(character)));
        if (extension == ".mbc" && cursor->is_regular_file(error)) load(path.string().c_str(), 0u);
        cursor.increment(error);
    }
    return this;
}

void QuickFile::release() {
    for (std::uint16_t slot = 0u; slot < count; ++slot) {
        std::free(files[slot].data);
        files[slot] = {};
    }
    count = 0u;
    index.release();
}

std::int32_t QuickFile::load(const char* filename, std::uint32_t size) {
    if (filename == nullptr || *filename == '\0') return 2;
#ifdef _WIN32
    std::FILE* file = ::_fsopen(filename, "rb", _SH_DENYNO);
#else
    std::FILE* file = std::fopen(filename, "rb");
#endif
    std::unique_ptr<std::FILE, decltype(&std::fclose)> stream(file, &std::fclose);
    if (!stream) return 2;
    if (count >= file_capacity) return -1;
    if (size == 0u) {
        if (std::fseek(stream.get(), 0, SEEK_END) != 0) return 3;
        const long length = std::ftell(stream.get());
        if (length < 0 || static_cast<unsigned long long>(length) > UINT32_MAX || std::fseek(stream.get(), 0, SEEK_SET) != 0) return 3;
        size = static_cast<std::uint32_t>(length);
    }
    std::unique_ptr<void, decltype(&std::free)> buffer(std::calloc(std::max<std::size_t>(size, 1u), 1u), &std::free);
    if (!buffer) throw std::bad_alloc();
    if (size != 0u && std::fread(buffer.get(), 1u, size, stream.get()) != size && std::ferror(stream.get()) != 0) return 3;
    const std::string path(filename);
    const auto separator = path.find_last_of("/\\");
    const char* basename = filename + (separator == std::string::npos ? 0u : separator + 1u);
    index.insert(basename, 0u, count, true);
    files[count] = {size, static_cast<std::uint8_t*>(buffer.release())};
    ++count;
    return 0;
}

std::uint8_t* QuickFile::find(const char* filename, std::uint32_t* size, std::uint16_t* file_id) {
    const std::uint32_t slot = index.find(filename, 0u, true);
    if (slot == UINT32_MAX || slot >= count) return nullptr;
    if (size != nullptr) *size = files[slot].size;
    if (file_id != nullptr) *file_id = static_cast<std::uint16_t>(slot + 1u);
    return files[slot].data;
}
// End of CHash16 and QuickFile.

// End recovered quickfile cluster.

// Begin recovered filemap cluster.
SferaFileMap::SferaFileMap(const char* path) noexcept : mapped_view(nullptr), file_size(0u), filename{} {
    open(path);
}

SferaFileMap::~SferaFileMap() noexcept {
    close();
}

bool SferaFileMap::isOpen() const noexcept {
    return reinterpret_cast<std::uintptr_t>(mapped_view) > 1u;
}

void SferaFileMap::reportError(const char* format, bool fatal) const noexcept {
    char message[160];
    std::snprintf(message, sizeof(message), format, filename);
    std::fprintf(stderr, "%s\n", message);
    ::OutputDebugStringA(message);
    if (fatal) {
        sfera_client_critical_error(message, 1u);
        ::TerminateProcess(::GetCurrentProcess(), 0u);
    }
}

std::uint32_t SferaFileMap::size() const noexcept {
    if (isOpen()) return file_size;
    reportError(mapped_view == nullptr ? "FileMap::size: file is not opened" : "FileMap::size: open file %s error", false);
    return 0u;
}

const std::byte* SferaFileMap::data() const noexcept {
    if (!isOpen()) reportError(mapped_view == nullptr ? "FileMap::get_ptr: file is not opened" : "FileMap::get_ptr: open file %s error", true);
    return mapped_view;
}

void SferaFileMap::close() noexcept {
    if (!isOpen()) return;
    if (!::UnmapViewOfFile(mapped_view)) reportError("Error unmapping file %s", false);
    mapped_view = nullptr;
}

bool SferaFileMap::open(const char* path) noexcept {
    close();
    const char* separator = std::strrchr(path, '\\');
    const std::string_view basename(separator == nullptr ? path : separator + 1);
    const std::size_t copied = basename.copy(filename, sizeof(filename) - 1u);
    std::fill(filename + copied, std::end(filename), '\0');
    mapped_view = reinterpret_cast<const std::byte*>(std::uintptr_t{1u});
    HANDLE file = ::CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, nullptr);
    if (file == INVALID_HANDLE_VALUE) return false;
    file_size = ::GetFileSize(file, nullptr);
    HANDLE mapping = ::CreateFileMappingA(file, nullptr, PAGE_READONLY, 0u, 0u, nullptr);
    ::CloseHandle(file);
    if (mapping == nullptr) return false;
    const auto* view = static_cast<const std::byte*>(::MapViewOfFile(mapping, FILE_MAP_READ, 0u, 0u, 0u));
    ::CloseHandle(mapping);
    if (view == nullptr) return false;
    mapped_view = view;
    return true;
}

// End recovered filemap cluster.

bool SphereUI::FontFace::load(const char* display_name, const char* filename, const char* texture_name) {
    if (filename == nullptr || texture_name == nullptr) return false;
    std::ifstream stream(filename, std::ios::binary);
    if (!stream) {
        const std::string message = std::string("Can't open font '") + filename + "'";
        if (auto* log = g_sfera_error_log_runtime.outputs[1u]; log != nullptr && log->buffer != nullptr) log->write(message.c_str());
        return false;
    }
    std::array<char, 4> signature{};
    if (!stream.read(signature.data(), signature.size()) || std::string_view(signature.data(), signature.size()) != "SFNT") return false;
    FontFace replacement;
    std::string stored_name, stored_texture;
    if (!std::getline(stream, stored_name, '\0') || stored_name.size() >= 256u || !std::getline(stream, stored_texture, '\0') || stored_texture.size() >= 256u) return false;
    replacement.name = display_name == nullptr ? stored_name : display_name;
    const auto texture_id = g_sfera_textures.find(texture_name);
    if (texture_id == -1) {
        const std::string message = std::string("Can't load texture '") + texture_name + "' for font '" + replacement.name + "'";
        InterfaceRenderer::reportError(message.c_str());
        return false;
    }
    replacement.texture = static_cast<std::uint32_t>(texture_id);
    if (!stream.read(reinterpret_cast<char*>(&replacement.line_height), sizeof(replacement.line_height)) || !stream.read(reinterpret_cast<char*>(&replacement.baseline), sizeof(replacement.baseline))) return false;
    // SFNT stores 224 little-endian, 28-byte metric records for character codes 32 through 255.
    auto printable_glyphs = std::span(replacement.glyphs).subspan(32u);
    if (!stream.read(reinterpret_cast<char*>(printable_glyphs.data()), static_cast<std::streamsize>(printable_glyphs.size_bytes()))) return false;
    for (auto& glyph : printable_glyphs) glyph.bearing_y = static_cast<std::int16_t>(static_cast<std::uint16_t>(glyph.bearing_y) - static_cast<std::uint16_t>(replacement.baseline));
    *this = std::move(replacement);
    return true;
}

SphereUI::FontFactory::FontFactory() = default;
SphereUI::FontFactory::~FontFactory() = default;

void SphereUI::FontFactory::initialize() {
    vertices.resize(1200u);
    std::fill(vertices.begin(), vertices.end(), SferaScreenVertex{});
    quad_indices.resize(2400u);
    vertex_count = 0u;
}

void SphereUI::FontFactory::clear() {
    faces.clear();
    vertices.clear();
    quad_indices.clear();
    vertex_count = 0u;
}

bool SphereUI::FontFactory::load(const char* filename, const char* texture_name) {
    auto loaded = std::make_unique<FontFace>();
    if (!loaded->load(nullptr, filename, texture_name)) return false;
    faces.push_back(std::move(loaded));
    return true;
}

void SphereUI::FontFactory::loadNamedFont(const char* name) {
    if (name == nullptr) return;
    std::string localized_name(name);
    const char* suffix = g_sfera_font_runtime.language_suffix;
    if (*suffix != '\0' && !SferaSimpleParser::equalsIgnoreCase(suffix, "_e")) localized_name += suffix;
    const std::string filename = "Effects\\" + localized_name + ".sfn";
    if (!load(filename.c_str(), localized_name.c_str())) {
        const std::string message = "Can't load font '" + localized_name + "'";
        InterfaceRenderer::reportError(message.c_str());
    }
}

void SphereUI::FontFactory::loadConfiguration() {
    InterfaceConfiguration::open("fonts.cfg");
    if (g_sfera_config_text_runtime.text_length == 0u) {
        InterfaceRenderer::reportError("File 'fonts.cfg' doesn't exist or contains no font configuration.");
        return;
    }
    std::uint32_t count = 0u;
    InterfaceConfiguration::readInteger("NEW_FONTS_NUMBER", count);
    for (std::uint32_t index = 0u; index < count; ++index) {
        const std::string key = "NEW_FONT_" + std::to_string(index);
        const char* text = InterfaceConfiguration::value(key.c_str());
        const std::string_view value(text == nullptr ? "" : text);
        const auto end = value.find('"', 1u);
        if (value.empty() || value.front() != '"' || end == std::string_view::npos) {
            const std::string message = "Missing quoted font name for '" + key + "' in fonts.cfg.";
            InterfaceRenderer::reportError(message.c_str());
            continue;
        }
        std::string name(value.substr(1u, end - 1u));
        std::replace(name.begin(), name.end(), '\r', ' ');
        std::erase(name, '\n');
        loadNamedFont(name.c_str());
    }
}

std::uint32_t SphereUI::FontFactory::count() const noexcept {
    return static_cast<std::uint32_t>(faces.size());
}

const SphereUI::FontFace& SphereUI::FontFactory::face(std::uint32_t font) const {
    if (font < 2u || font - 2u >= faces.size()) throw std::out_of_range("invalid font index");
    return *faces[font - 2u];
}

std::uint32_t SphereUI::InterfaceRenderer::tracking(std::uint32_t font) noexcept {
    return font < 2u ? g_sfera_font_atlas_layout_runtime.code_base[font] : 0u;
}

bool SferaInterfaceCursor::loadTextures() {
    for (std::size_t index = 0u; index < textures.size(); ++index) {
        const char* name = sfera_cursor_texture_name(static_cast<std::uint32_t>(index));
        textures[index] = static_cast<std::uint32_t>(g_sfera_textures.find(name));
        if (textures[index] == UINT32_MAX) SphereUI::InterfaceRenderer::reportError((std::string("Cursor texture '") + name + "' not found").c_str());
    }
    kind = 0u;
    images = {};
    labels = {};
    return true;
}

void SferaInterfaceCursor::setImage(std::size_t layer, const char* texture, std::int32_t x, std::int32_t y) {
    if (layer >= images.size()) return;
    auto& image = images[layer];
    image.x = x;
    image.y = y;
    image.texture = texture == nullptr ? UINT32_MAX : static_cast<std::uint32_t>(g_sfera_textures.find(texture));
    const auto extent = image.texture == UINT32_MAX ? SphereUI::TextExtent{32, 32} : g_sfera_textures.size(image.texture);
    image.width = static_cast<std::uint32_t>(extent.width);
    image.height = static_cast<std::uint32_t>(extent.height);
}

void SferaInterfaceCursor::setImageSize(std::size_t layer, std::uint32_t width, std::uint32_t height) {
    if (layer >= images.size()) return;
    images[layer].width = width;
    images[layer].height = height;
}

void SferaInterfaceCursor::setText(std::size_t layer, const char* text, std::int32_t x, std::int32_t y, std::uint32_t font, std::uint32_t color) {
    if (layer >= labels.size()) return;
    auto& label = labels[layer];
    label.x = x;
    label.y = y;
    label.font = font;
    label.color = color;
    label.text = text == nullptr ? std::string{} : std::string(text, std::min(std::strlen(text), std::size_t{63u}));
}

void SferaInterfaceCursor::setKind(std::uint32_t cursor_kind) {
    if (cursor_kind >= textures.size() && cursor_kind != 255u) return;
    kind = static_cast<std::uint8_t>(cursor_kind);
    centered_hotspot = cursor_kind >= 2u && cursor_kind < textures.size();
}

void SferaInterfaceCursor::draw(float x, float y) const {
    auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device);
    if (!system_visible || device == nullptr) return;
    IDirect3DStateBlock9* captured = nullptr;
    if (FAILED(device->CreateStateBlock(D3DSBT_ALL, &captured))) return;
    const auto restore = [mode = g_sfera_sprite_runtime.render_mode](IDirect3DStateBlock9* state) { state->Apply(); state->Release(); g_sfera_sprite_runtime.render_mode = mode; };
    const std::unique_ptr<IDirect3DStateBlock9, decltype(restore)> state(captured, restore);
    if (centered_hotspot) { x -= 16.0f; y -= 16.0f; }
    device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    if (kind < textures.size() && textures[kind] != 0u) SphereUI::InterfaceRenderer::drawTexture(g_sfera_textures.resource(textures[kind]), x, y, x + 32.0f, y + 32.0f, UINT32_MAX);
    for (const auto& image : images) {
        if (image.texture == UINT32_MAX) continue;
        const float left = x + static_cast<float>(image.x), top = y + static_cast<float>(image.y);
        SphereUI::InterfaceRenderer::drawTexture(g_sfera_textures.resource(image.texture), left, top, left + static_cast<float>(image.width), top + static_cast<float>(image.height), UINT32_MAX);
    }
    device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    const SphereUI::UiRect clip{static_cast<std::int32_t>(g_sfera_screen_clip_runtime.left), static_cast<std::int32_t>(g_sfera_screen_clip_runtime.top), static_cast<std::int32_t>(g_sfera_screen_clip_runtime.right), static_cast<std::int32_t>(g_sfera_screen_clip_runtime.bottom)};
    for (const auto& label : labels) if (!label.text.empty()) SphereUI::InterfaceRenderer::drawText(label.text.c_str(), static_cast<std::int32_t>(static_cast<double>(x) + label.x), static_cast<std::int32_t>(static_cast<double>(y) + label.y), label.color, label.font, true, clip, (label.color >> 24u) == 255u);
}

CCursorManager* CCursorManager::initialized = nullptr;

CCursorManager::~CCursorManager() { initialized = nullptr; }

CCursorManager& CCursorManager::instance() { static CCursorManager manager; initialized = &manager; return manager; }

bool CCursorManager::hasActiveCursor() noexcept { return initialized != nullptr && initialized->active != nullptr; }

CCursor* CCursorManager::currentCursor() const noexcept { return active; }

CCursor* CCursorManager::activeCursor() const {
    if (active == nullptr) { CSphereError error; error.write("CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set"); }
    return active;
}

void CCursorManager::select(std::uint32_t mode) {
    if (mode > 1u) return;
    CCursor* selected = mode == 0u ? static_cast<CCursor*>(&software) : static_cast<CCursor*>(&hardware);
    if (selected == active) return;
    CCursor* previous = active;
    active = selected;
    selected->copyStateFrom(previous);
    if (previous != nullptr) previous->deactivate();
    selected->activate();
}

bool CCursorManager::usesSoftwareCursor() const noexcept { return active == &software; }

SferaCursorPosition CCursorManager::position() const {
    SferaCursorPosition result{};
    if (active != nullptr) active->getPosition(&result);
    return result;
}

SphereUI::CursorGeometry CCursorManager::geometry() const {
    if (active == nullptr) return {};
    SferaCursorPosition position{};
    active->getPosition(&position);
    const auto dimensions = active == &software ? SphereUI::TextExtent{static_cast<std::int32_t>(software.texture_width), static_cast<std::int32_t>(software.texture_height)} : SphereUI::TextExtent{static_cast<std::int32_t>(hardware.texture_width), static_cast<std::int32_t>(hardware.texture_height)};
    const auto kind = active->cursorKind();
    const auto* name = kind < 4u ? sfera_cursor_texture_name(kind) : nullptr;
    return {position.x, position.y, dimensions.width, dimensions.height, name != nullptr && name[0] != '_'};
}

void SphereUI::InterfaceRenderer::drawTexture(IDirect3DBaseTexture9* texture, float left, float top, float right, float bottom, std::uint32_t color, float u, float v, bool textured) {
    auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device);
    if (device == nullptr) return;
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, texture));
    std::array<SpriteVertex, 4> vertices{};
    const float offset = textured ? 0.5f : 0.0f;
    for (std::size_t index = 0u; index < 4u; ++index) {
        auto& vertex = vertices[index];
        vertex.x = (index == 0u || index == 3u ? left : right) - offset;
        vertex.y = (index < 2u ? top : bottom) - offset;
        vertex.z = 0.0f;
        vertex.rhw = 1.0f;
        vertex.color = color;
        if (textured) {
            vertex.u = index == 0u || index == 3u ? 0.0f : u;
            vertex.v = index < 2u ? 0.0f : v;
        }
    }
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1));
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2u, vertices.data(), sizeof(SpriteVertex)));
}

void SphereUI::InterfaceRenderer::reportError(const char* message) {
    for (std::uint32_t index : {1u, 0u}) if (auto* output = g_sfera_error_log_runtime.outputs[index]) {
        if (index == 1u) output->write("*** ERROR ****************************************************:");
        if (output->buffer != nullptr) output->write(message);
    }
}

void SphereUI::InterfaceRenderer::setSpriteRenderMode(std::uint32_t mode) {
    if (mode == g_sfera_sprite_runtime.render_mode) return;
    if (auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device); device != nullptr && mode <= 2u) {
        device->SetRenderState(D3DRS_ALPHABLENDENABLE, mode == 0u ? FALSE : TRUE);
        if (mode != 0u) { device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA); device->SetRenderState(D3DRS_DESTBLEND, mode == 2u ? D3DBLEND_ONE : D3DBLEND_INVSRCALPHA); }
    }
    g_sfera_sprite_runtime.render_mode = mode;
}


namespace {
void replaceSpriteText(char*& destination, const char* text) {
    char* replacement = nullptr;
    if (text != nullptr) {
        const auto size = std::strlen(text) + 1u;
        replacement = static_cast<char*>(SphereUI::Runtime::allocate(size));
        if (replacement == nullptr) throw std::bad_alloc();
        std::copy_n(text, size, replacement);
    }
    SphereUI::Runtime::deallocate(destination);
    destination = replacement;
}

}

void SphereUI::UiSprite::initialize() {
    *this = {};
    for (auto& vertex : vertices) {
        vertex.rhw = 1.0f;
        vertex.color = std::numeric_limits<std::uint32_t>::max();
    }
}

void SphereUI::UiSprite::release() {
    if (parts != nullptr) {
        for (std::uint32_t index = 0u; index < part_count; ++index) Runtime::deallocate(parts[index].texture_name);
        Runtime::deallocate(parts);
    }
    Runtime::deallocate(name);
    name = nullptr;
    parts = nullptr;
    part_count = 0u;
}

void SphereUI::UiSprite::copyFrom(const UiSprite& source) {
    if (this == &source) return;
    UiSprite copy = source;
    copy.name = nullptr;
    copy.parts = nullptr;
    copy.part_count = 0u;
    copy.reference_count = 0u;
    try {
        replaceSpriteText(copy.name, source.name);
        if (source.part_count != 0u) {
            if (source.part_count > std::numeric_limits<std::uint32_t>::max() / sizeof(SpritePart)) throw std::length_error("sprite parts too long");
            auto* values = static_cast<SpritePart*>(Runtime::allocate(source.part_count * sizeof(SpritePart)));
            if (values == nullptr) throw std::bad_alloc();
            std::fill_n(values, source.part_count, SpritePart{});
            copy.parts = values;
            copy.part_count = source.part_count;
            for (std::uint32_t index = 0u; index < source.part_count; ++index) {
                values[index] = source.parts[index];
                values[index].texture_name = nullptr;
                replaceSpriteText(values[index].texture_name, source.parts[index].texture_name);
            }
        }
    } catch (...) {
        copy.release();
        throw;
    }
    release();
    *this = copy;
}

void SphereUI::UiSprite::resizeParts(std::uint32_t count) {
    if (part_count == count) return;
    if (count > std::numeric_limits<std::uint32_t>::max() / sizeof(SphereUI::SpritePart)) throw std::length_error("sprite parts too long");
    auto* replacement = count == 0u ? nullptr : static_cast<SphereUI::SpritePart*>(SphereUI::Runtime::allocate(count * sizeof(SphereUI::SpritePart)));
    if (count != 0u && replacement == nullptr) throw std::bad_alloc();
    if (replacement != nullptr) std::fill_n(replacement, count, SphereUI::SpritePart{});
    auto* original = parts;
    for (std::uint32_t index = 0u; index < part_count; ++index) SphereUI::Runtime::deallocate(original[index].texture_name);
    SphereUI::Runtime::deallocate(original);
    parts = replacement;
    part_count = count;
}

void SphereUI::SpritePart::setTexture(const char* image_name, const std::uint32_t* texture_rectangle, const std::uint32_t* sprite_rectangle) {
    replaceSpriteText(texture_name, image_name);
    texture = static_cast<std::uint32_t>(g_sfera_textures.find(image_name));
    if (texture == std::numeric_limits<std::uint32_t>::max()) {
        const auto message = std::string("Sprite::Texture not found '") + (image_name == nullptr ? "" : image_name) + "'";
        SphereUI::InterfaceRenderer::reportError(message.c_str());
    }
    const auto extent = g_sfera_textures.size(texture);
    const auto texture_width = static_cast<std::uint32_t>(extent.width), texture_height = static_cast<std::uint32_t>(extent.height);
    const auto coordinate = [](std::uint32_t value, std::uint32_t maximum) {
        return maximum == 0u ? 0.0f : static_cast<float>(static_cast<double>(value) / maximum);
    };
    const float left = texture_rectangle == nullptr ? 0.0f : coordinate(texture_rectangle[0], texture_width), top = texture_rectangle == nullptr ? 0.0f : coordinate(texture_rectangle[1], texture_height), right = texture_rectangle == nullptr ? 1.0f : coordinate(texture_rectangle[2], texture_width), bottom = texture_rectangle == nullptr ? 1.0f : coordinate(texture_rectangle[3], texture_height);
    for (std::size_t index = 0u; index < 4u; ++index) {
        u[index] = index == 0u || index == 3u ? left : right;
        v[index] = index < 2u ? top : bottom;
    }
    this->left = sprite_rectangle == nullptr ? 0u : sprite_rectangle[0];
    this->top = sprite_rectangle == nullptr ? 0u : sprite_rectangle[1];
    width = sprite_rectangle == nullptr ? texture_width : sprite_rectangle[2];
    height = sprite_rectangle == nullptr ? texture_height : sprite_rectangle[3];
    flags = g_sfera_textures.hasAlpha(texture) ? 1u : 0u;
}

void SphereUI::UiSprite::setColors(std::uint32_t color) {
    for (auto& vertex : vertices) vertex.color = color;
}

namespace {
    void uiSpriteLoadDiagnostic(const char* filename, const SferaParserRange& range, const char* message) {
        char buffer[1024]{};
        std::snprintf(buffer, sizeof(buffer), "Sprite::Load(%s,%d,%d) -> %s", filename == nullptr ? "" : filename, range.begin, range.end, message);
        SphereUI::InterfaceRenderer::reportError(buffer);
    }
}

void SphereUI::UiSprite::setImage(const char* name) {
    replaceSpriteText(this->name, name);
    resizeParts(1u);
    auto& part = *parts;
    part.setTexture(name, nullptr, nullptr);
    setColors(std::numeric_limits<std::uint32_t>::max());
    width = part.width;
    height = part.height;
}

bool SphereUI::UiSprite::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    char text[1024]{};
    if (parser.findValue("name", &range) && parser.readQuotedString(0u, text) != nullptr) replaceSpriteText(name, text);
    else uiSpriteLoadDiagnostic(filename, range, "Name not specified.");
    if (parser.findValue("size", &range)) {
        width = static_cast<std::uint32_t>(parser.readInt(0u));
        height = static_cast<std::uint32_t>(parser.readInt(1u));
    } else uiSpriteLoadDiagnostic(filename, range, "Size not specified.");
    struct ScanScope {
        SferaSimpleParser& parser;
        SferaParserRange saved{};
        explicit ScanScope(SferaSimpleParser& source) : parser(source) { parser.getScanRange(&saved); }

        ~ScanScope() { parser.setScanRange(&saved); }
    } scan(parser);
    std::uint32_t count = 0u;
    parser.setScanRange(&range);
    while (parser.nextValue("texture")) ++count;
    if (count == 0u) uiSpriteLoadDiagnostic(filename, range, "At least one texture must be specified.");
    resizeParts(count);
    std::uint32_t index = 0u;
    parser.setScanRange(&range);
    while (parser.nextValue("texture")) {
        if (parser.readQuotedString(0u, text) == nullptr) continue;
        std::int32_t rectangles[8]{};
        if (!parser.readIntSequence(1u, rectangles, 8u)) uiSpriteLoadDiagnostic(filename, range, "Incorrect number of args in 'texture'.");
        std::uint32_t coordinates[8]{};
        std::transform(std::begin(rectangles), std::end(rectangles), std::begin(coordinates), [](std::int32_t coordinate) { return static_cast<std::uint32_t>(coordinate); });
        parts[index++].setTexture(text, coordinates, coordinates + 4u);
    }
    parser.setScanRange(&range);
    while (parser.nextValue("tcoords")) {
        std::int32_t values[9]{};
        if (!parser.readIntSequence(0u, values, 9u)) uiSpriteLoadDiagnostic(filename, range, "Incorrect number of args in 'tcoords'.");
        const auto part_index = static_cast<std::uint32_t>(values[0]);
        if (part_index >= count || parts[part_index].texture == std::numeric_limits<std::uint32_t>::max()) continue;
        const auto size = g_sfera_textures.size(parts[part_index].texture);
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex) {
            parts[part_index].u[vertex] = size.width == 0 ? 0.0f : static_cast<float>(static_cast<double>(static_cast<std::uint32_t>(values[vertex * 2u + 1u])) / static_cast<std::uint32_t>(size.width));
            parts[part_index].v[vertex] = size.height == 0 ? 0.0f : static_cast<float>(static_cast<double>(static_cast<std::uint32_t>(values[vertex * 2u + 2u])) / static_cast<std::uint32_t>(size.height));
        }
    }
    return true;
}

void SphereUI::UiSprite::releaseReference() {
    if (reference_count != 0u) {
        --reference_count;
        return;
    }
    destroy();
}


SphereUI::UiViewport SphereUI::InterfaceRenderer::viewport() {
    D3DVIEWPORT9 value{};
    if (auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device)) (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->GetViewport(&value));
    return {value.X, value.Y, value.Width, value.Height, value.MinZ, value.MaxZ};
}

void SphereUI::InterfaceRenderer::setViewport(const UiViewport& value) {
    if (auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device)) {
        const D3DVIEWPORT9 viewport{value.x, value.y, value.width, value.height, value.minimum_z, value.maximum_z};
        device->SetViewport(&viewport);
    }
}

void SphereUI::UiSprite::setQuad(const SpritePart& part, float left, float top, float right, float bottom) {
    for (std::size_t index = 0u; index < 4u; ++index) {
        auto& vertex = vertices[index];
        vertex.x = index == 0u || index == 3u ? left : right;
        vertex.y = index < 2u ? top : bottom;
        vertex.u = part.u[index];
        vertex.v = part.v[index];
    }
}

void SphereUI::UiSprite::drawParts(float left, float top, float right, float bottom, bool natural) {
    if (part_count == 0u && !natural) return;
    auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device);
    if (device == nullptr) return;
    device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    if (part_count == 0u) return;
    const float scale_x = natural ? 1.0f : (right - left) / static_cast<float>(width), scale_y = natural ? 1.0f : (bottom - top) / static_cast<float>(height);
    left -= 0.5f;
    top -= 0.5f;
    std::uint32_t previous_texture = std::numeric_limits<std::uint32_t>::max();
    for (std::uint32_t index = 0u; index < part_count; ++index) {
        const auto& part = parts[index];
        if (part.texture != previous_texture) {
            g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, g_sfera_textures.resource(part.texture));
            previous_texture = part.texture;
        }
        const auto position = [natural](std::uint32_t value, float scale) {
            const auto result = static_cast<float>(value) * scale;
            return natural ? result : std::floor(result);
        };
        setQuad(part, left + position(part.left, scale_x), top + position(part.top, scale_y), left + (natural ? static_cast<float>(part.width) : position(part.width, scale_x)), top + (natural ? static_cast<float>(part.height) : position(part.height, scale_y)));
        (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1));
        (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2u, vertices, sizeof(SphereUI::SpriteVertex)));
    }
}

void SphereUI::UiSprite::drawRotated(float left, float top, float right, float bottom, float rotation) {
    if (part_count == 0u) return;
    const auto& part = *parts;
    auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device);
    if (device == nullptr) return;
    const auto sine = static_cast<float>(std::sin(static_cast<double>(rotation))), cosine = static_cast<float>(std::cos(static_cast<double>(rotation)));
    const float width = right - left, height = bottom - top, center_x = (left + right) * 0.5f - 0.5f, center_y = (top + bottom) * 0.5f - 0.5f;
    setQuad(part, -width * 0.5f, -height * 0.5f, width * 0.5f, height * 0.5f);
    for (auto& vertex : vertices) {
        const float local_x = vertex.x, local_y = vertex.y;
        vertex.x = center_x + local_x * cosine - local_y * sine;
        vertex.y = center_y + local_x * sine + local_y * cosine;
    }
    g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, g_sfera_textures.resource(part.texture));
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2u, vertices, sizeof(SphereUI::SpriteVertex)));
}

void SphereUI::UiSprite::draw(float left, float top, float right, float bottom, std::uint32_t color, float rotation) {
    setColors(color);
    if (rotation == 0.0f) drawParts(left, top, right, bottom, false);
    else drawRotated(left, top, right, bottom, rotation);
}

void SphereUI::UiSprite::drawNatural(float left, float top, std::uint32_t color) {
    setColors(color);
    drawParts(left, top, left + width, top + height, true);
}


const char* SphereUI::InterfaceManager::localizedPath(const char* filename) {
    if (filename == nullptr || g_sfera_font_runtime.language_suffix[0] == '\0') return filename;
    resolved_ui_path = filename;
    const auto extension = resolved_ui_path.rfind('.');
    resolved_ui_path.insert(extension == std::string::npos ? resolved_ui_path.size() : extension, g_sfera_font_runtime.language_suffix);
    return resolved_ui_path.c_str();
}

SphereUI::UiSprite* SphereUI::InterfaceManager::sharedSprite(const char* name) {
    if (name == nullptr) return nullptr;
    const auto found = std::find_if(sprites.begin(), sprites.end(), [name](const UiSprite& sprite) { return SferaSimpleParser::equalsIgnoreCase(sprite.name, name); });
    return found == sprites.end() ? nullptr : &*found;
}

SphereUI::UiSprite* SphereUI::InterfaceManager::acquireSprite(const char* name) {
    if (name == nullptr) return nullptr;
    if (auto* sprite = sharedSprite(name)) {
        ++sprite->reference_count;
        return sprite;
    }
    if (g_sfera_textures.find(name) == -1) return nullptr;
    auto* sprite = UiSprite::create();
    if (sprite == nullptr) throw std::bad_alloc();
    try {
        sprite->setImage(name);
    } catch (...) {
        sprite->destroy();
        throw;
    }
    return sprite;
}

void SphereUI::InterfaceManager::loadSprites(const char* filename) {
    clearSprites();
    SferaSimpleParser parser{};
    parser.load(filename);
    parser.setBlockRange(nullptr);
    SferaParserRange range{};
    while (parser.nextBlock("sprite", &range)) {
        auto& sprite = sprites.emplace_back();
        sprite.initialize();
        sprite.loadUi(filename, parser, range);
    }
}

void SphereUI::InterfaceManager::clearSprites() {
    for (auto& sprite : sprites) sprite.release();
    sprites.clear();
}

bool SphereUI::InterfaceManager::loadWindowTemplates(const char* filename) {
    SferaSimpleParser parser{};
    parser.load(filename);
    parser.setBlockRange(nullptr);
    SferaParserRange range{};
    while (parser.nextBlock("windowUI", &range)) {
        auto* window = Runtime::makeControl(0u);
        if (window == nullptr) throw std::bad_alloc();
        try {
            if (!window->loadUi(filename, parser, range)) {
                window->destroy(true);
                continue;
            }
            if (window->getResourceName()[0] == '\0') {
                const auto message = std::string("Window name is missing in ") + (filename == nullptr ? "" : filename) + " at lines " + std::to_string(range.begin) + "-" + std::to_string(range.end);
                CSphereError error;
                error.write(message.c_str());
            }
            window_templates.push_back(window);
        } catch (...) {
            window->destroy(true);
            throw;
        }
    }
    return true;
}

SphereUI::Window* SphereUI::InterfaceManager::templateWindow(const char* name) const {
    if (name == nullptr) return nullptr;
    const auto found = std::find_if(window_templates.begin(), window_templates.end(), [name](const Window* window) { return window != nullptr && SferaSimpleParser::equalsIgnoreCase(window->getResourceName(), name); });
    return found == window_templates.end() ? nullptr : *found;
}

void SphereUI::InterfaceManager::clearWindowTemplates() {
    for (auto* window : window_templates) if (window != nullptr) window->destroy(true);
    window_templates.clear();
}

void SphereUI::InterfaceManager::loadHyperTexts() {
    const std::string suffix = std::string(g_sfera_font_runtime.language_suffix) + ".hts";
    std::error_code error;
    for (std::filesystem::directory_iterator entry("Language", error), end; !error && entry != end; entry.increment(error)) {
        if (entry->is_directory(error)) continue;
        const auto basename = entry->path().filename().string();
        if (basename.size() < suffix.size() || !SferaSimpleParser::equalsIgnoreCase(basename.c_str() + basename.size() - suffix.size(), suffix.c_str())) continue;
        auto document = std::make_unique<HyperTextDocument>();
        if (!document->load(entry->path().string().c_str())) continue;
        auto name = entry->path().string();
        if (g_sfera_font_runtime.language_suffix[0] != '\0') if (const auto language = name.rfind('_'); language != std::string::npos) name.replace(language, std::string::npos, ".hts");
        document->setName(name.c_str());
        hypertext_documents.push_back(std::move(document));
    }
}

SphereUI::HyperTextDocument* SphereUI::InterfaceManager::findHyperText(const char* name) const {
    if (name == nullptr) return nullptr;
    const auto found = std::find_if(hypertext_documents.begin(), hypertext_documents.end(), [name](const auto& document) { return document != nullptr && SferaSimpleParser::equalsIgnoreCase(document->name.c_str(), name); });
    return found == hypertext_documents.end() ? nullptr : found->get();
}

void SphereUI::InterfaceManager::clearHyperTexts() {
    hypertext_documents.clear();
}

bool SphereUI::InterfaceManager::loadLocalizedStrings() {
    localized_strings.push_back({"null", "NULL"});
    SferaSimpleParser parser{};
    parser.load(localizedPath("Language\\strings.ui"));
    SferaParserRange range{};
    if (!parser.findBlock("stringsUI", &range, nullptr, 1)) return true;
    parser.setScanRange(&range);
    while (parser.nextValue("string")) {
        char key[sizeof(parser.token)]{};
        char value[sizeof(parser.token)]{};
        if (parser.readStringBounded(0u, key, sizeof(key)) != nullptr && parser.readQuotedString(1u, value) != nullptr) localized_strings.push_back({key, value});
    }
    return true;
}

std::string_view SphereUI::InterfaceManager::localizedValue(const char* key) const {
    const auto found = std::find_if(localized_strings.begin(), localized_strings.end(), [key](const LocalizedTextEntry& entry) { return key != nullptr && SferaSimpleParser::equalsIgnoreCase(entry.key.c_str(), key); });
    if (found != localized_strings.end()) return found->value;
    if (!localized_strings.empty()) return localized_strings.front().value;
    return {};
}

const char* SphereUI::InterfaceManager::localizedText(const char* key) const {
    return localized_strings.empty() ? (key == nullptr ? "" : key) : localizedValue(key).data();
}

void SphereUI::InterfaceManager::clearLocalizedStrings() {
    localized_strings.clear();
}

SphereUI::SavedWindowPosition* SphereUI::InterfaceManager::savedPosition(const char* name, bool create) {
    if (name == nullptr) return nullptr;
    const auto found = std::find_if(saved_positions.begin(), saved_positions.end(), [name](const SavedWindowPosition& position) { return position.name == name; });
    if (found != saved_positions.end()) return &*found;
    return create ? &saved_positions.emplace_back(SavedWindowPosition{name}) : nullptr;
}

bool SphereUI::InterfaceManager::findSavedPosition(const char* name, SferaCursorPosition& position) {
    const auto* saved = savedPosition(name, false);
    if (saved == nullptr) return false;
    position = {saved->x, saved->y};
    return true;
}

void SphereUI::InterfaceManager::saveWindowPosition(Window& window) {
    auto* saved = savedPosition(window.getName(), true);
    if (saved != nullptr) window.getAbsolutePosition(saved->x, saved->y);
}

std::uint32_t SphereUI::InterfaceManager::savedPositionsSize() const {
    if (saved_positions.empty()) return 0u;
    std::size_t size = 4u;
    for (const auto& position : saved_positions) {
        if (size > std::numeric_limits<std::uint32_t>::max() - 9u || position.name.size() > std::numeric_limits<std::uint32_t>::max() - 9u - size) throw std::length_error("Saved window positions exceed the file size limit");
        size += position.name.size() + 9u;
    }
    return static_cast<std::uint32_t>(size);
}

void SphereUI::InterfaceManager::writeSavedPositions(std::span<std::byte> destination) const {
    if (destination.empty()) return;
    if (destination.size() < std::max<std::size_t>(4u, savedPositionsSize())) throw std::length_error("Saved window positions do not fit in the destination");
    std::memcpy(destination.data(), "UIV1", 4u);
    destination = destination.subspan(4u);
    for (const auto& position : saved_positions) {
        std::memcpy(destination.data(), position.name.c_str(), position.name.size() + 1u);
        destination = destination.subspan(position.name.size() + 1u);
        const float coordinates[] = {static_cast<float>(static_cast<double>(position.x) / g_sfera_graphics_runtime.display_width), static_cast<float>(static_cast<double>(position.y) / g_sfera_graphics_runtime.display_height)};
        std::memcpy(destination.data(), coordinates, sizeof(coordinates));
        destination = destination.subspan(sizeof(coordinates));
    }
}

void SphereUI::InterfaceManager::readSavedPositions(std::span<const std::byte> source) {
    saved_positions.clear();
    if (source.size() < 4u || std::memcmp(source.data(), "UIV1", 4u) != 0) return;
    source = source.subspan(4u);
    while (!source.empty()) {
        const auto end = std::find(source.begin(), source.end(), std::byte{});
        if (end == source.end()) return;
        const auto name_size = static_cast<std::size_t>(end - source.begin());
        if (source.size() - name_size - 1u < sizeof(float) * 2u) return;
        SavedWindowPosition position{std::string(reinterpret_cast<const char*>(source.data()), name_size)};
        source = source.subspan(name_size + 1u);
        float coordinates[2]{};
        std::memcpy(coordinates, source.data(), sizeof(coordinates));
        source = source.subspan(sizeof(coordinates));
        const double x = static_cast<double>(coordinates[0]) * g_sfera_graphics_runtime.display_width;
        const double y = static_cast<double>(coordinates[1]) * g_sfera_graphics_runtime.display_height;
        if (!std::isfinite(x) || !std::isfinite(y) || x < std::numeric_limits<std::int32_t>::min() || x > std::numeric_limits<std::int32_t>::max() || y < std::numeric_limits<std::int32_t>::min() || y > std::numeric_limits<std::int32_t>::max()) return;
        position.x = static_cast<std::int32_t>(x);
        position.y = static_cast<std::int32_t>(y);
        saved_positions.push_back(std::move(position));
    }
}

namespace {
    using SphereUI::HyperDocumentNode;
    using SphereUI::HyperTextCommand;
    using SphereUI::HyperTextImageAlignment;
    struct HyperDocumentFragment {
        HyperDocumentNode node{};
        std::string text;
    };
    struct HyperDocumentRow {
        std::vector<HyperDocumentFragment> fragments;
        std::int32_t width = 0;
        std::int32_t height = 0;
        std::int32_t baseline = 0;
        std::uint32_t initial_color = 0xFFFFFFFFu;
        bool paragraph_end = false;
    };
    template<class T> T* hyperAllocate() {
        auto* value = static_cast<T*>(SphereUI::Runtime::allocate(sizeof(T)));
        if (value == nullptr) throw std::bad_alloc();
        return std::construct_at(value);
    }

    std::string_view hyperTrim(std::string_view text) {
        const auto first = text.find_first_not_of(" \t\r\n");
        if (first == std::string_view::npos) return {};
        const auto last = text.find_last_not_of(" \t\r\n");
        return text.substr(first, last - first + 1u);
    }

    bool hyperEquals(std::string_view text, const char* expected) {
        return SferaSimpleParser::equalsIgnoreCase(std::string(text).c_str(), expected);
    }

    std::string hyperUnescape(std::string_view text) {
        std::string result;
        result.reserve(text.size());
        for (std::size_t index = 0u; index < text.size(); ++index) {
            char character = text[index];
            if (character == '\\') {
                if (++index == text.size()) break;
                character = text[index];
                if (character == '[') character = '<';
                else if (character == ']') character = '>';
            }
            result += character;
        }
        return result;
    }

    std::size_t hyperTagEnd(std::string_view text, std::size_t first) {
        return text.find('>', first);
    }

    bool hyperLinkParameters(std::string_view parameters, std::string& target, std::uint32_t& kind) {
        auto value = hyperTrim(parameters);
        if (value.empty() || value.front() != '=') return false;
        value = hyperTrim(value.substr(1u));
        if (value.size() < 2u || value.front() != '"') return false;
        std::size_t end = 1u;
        for (; end < value.size(); ++end) {
            if (value[end] == '\\' && end + 1u < value.size()) ++end;
            else if (value[end] == '"') break;
        }
        if (end == value.size()) return false;
        value = value.substr(1u, end - 1u);
        target.assign(value);
        const auto colon = value.find(':');
        const auto scheme = value.substr(0u, colon);
        kind = hyperEquals(scheme, "hts") ? 0u : hyperEquals(scheme, "item") ? 1u : hyperEquals(scheme, "player") ? 2u : hyperEquals(scheme, "mailto") ? 3u : 4u;
        if (kind == 1u || kind == 2u) target = hyperUnescape(target);
        return true;
    }

    HyperTextElement* hyperPlainElement(std::string_view text, bool wrap = false) {
        HyperTextElement* value = wrap ? static_cast<HyperTextElement*>(hyperAllocate<HyperTextElement_WordWrap>()) : hyperAllocate<HyperTextElement_PlainText>();
        value->type = wrap ? 3u : 4u;
        try {
            value->text.assign(std::string(text).c_str());
        } catch (...) {
            value->release();
            throw;
        }
        return value;
    }

    void hyperAppendElement(SphereUI::UiDeque<HyperTextElement*>& elements, HyperTextElement* element) {
        try {
            elements.pushBack(element);
        } catch (...) {
            element->release();
            throw;
        }
    }

    void hyperTakeElements(SphereUI::UiDeque<HyperTextElement*>& destination, SphereUI::UiDeque<HyperTextElement*>& source) {
        SphereUI::HyperTextParser::releaseElements(destination);
        destination = source;
        source = {};
        if (destination.proxy != nullptr) destination.proxy->owner = &destination;
    }

    SphereUI::TextExtent hyperTextExtent(std::string_view text, std::uint32_t font) {
        auto result = SphereUI::InterfaceRenderer::measureText(std::string(text).c_str(), font, true);
        if (text.empty()) result.width = 0;
        else if (font < 2u) result.width = std::max(0, result.width - 2);
        return result;
    }

    std::size_t hyperWordEnd(std::string_view text, std::size_t first, bool controls = false) {
        const auto separator = [controls](char character) {
            return character == ' ' || (controls && (character == '\t' || character == '\r' || character == '\n'));
        };
        auto end = first;
        while (end < text.size() && separator(text[end])) ++end;
        while (end < text.size() && !separator(text[end])) ++end;
        return end;
    }


}

SphereUI::HyperTextCommand SphereUI::HyperTextParser::command(std::string_view name) {
    if (hyperEquals(name, "br")) return HyperTextCommand::lineBreak;
    if (hyperEquals(name, "cl")) return HyperTextCommand::color;
    if (hyperEquals(name, "l")) return HyperTextCommand::linkStart;
    if (hyperEquals(name, "/l") || hyperEquals(name, "\\l")) return HyperTextCommand::linkEnd;
    if (hyperEquals(name, "sp")) return HyperTextCommand::preserveSpaces;
    if (hyperEquals(name, "tab")) return HyperTextCommand::tab;
    if (hyperEquals(name, "img")) return HyperTextCommand::image;
    if (hyperEquals(name, "t")) return HyperTextCommand::tooltipStart;
    if (hyperEquals(name, "/t") || hyperEquals(name, "\\t")) return HyperTextCommand::tooltipEnd;
    return HyperTextCommand::unknown;
}

bool SphereUI::HyperTextParser::parseCommand(std::string_view tag, HyperDocumentNode& node, std::string& argument) {
    const auto equals = tag.find('=');
    std::string name;
    for (char character : hyperTrim(tag.substr(0, equals))) if (character != ' ') name += character;
    node.command = command(name);
    if (node.command == HyperTextCommand::unknown) return false;
    auto value = equals == std::string_view::npos ? std::string_view{} : hyperTrim(tag.substr(equals + 1));
    if (!value.empty() && value.front() == '"') {
        value.remove_prefix(1);
        value = value.substr(0, value.find('"'));
    }
    argument.assign(value);
    if (node.command == HyperTextCommand::color) node.color = static_cast<std::uint32_t>(std::strtoul(argument.c_str(), nullptr, 16)) | 0xFF000000u;
    else if (node.command == HyperTextCommand::image) parseImage(argument, node);
    return true;
}

void SphereUI::HyperTextParser::parseImage(std::string_view argument, HyperDocumentNode& node) {
    std::vector<std::string> fields;
    while (!argument.empty()) {
        const auto comma = argument.find(',');
        const auto field = hyperTrim(argument.substr(0, comma));
        if (!field.empty()) fields.emplace_back(field);
        if (comma == std::string_view::npos) break;
        argument.remove_prefix(comma + 1);
    }
    if (fields.empty()) return;
    node.sprite = {g_sfera_interface.acquireSprite(fields.front().c_str()), [](UiSprite* sprite) { if (sprite != nullptr) sprite->releaseReference(); }};
    if (node.sprite == nullptr) return;
    if (fields.size() > 1 && hyperEquals(fields[1], "BOT")) node.image_alignment = HyperTextImageAlignment::bottom;
    else if (fields.size() > 1 && hyperEquals(fields[1], "MID")) node.image_alignment = HyperTextImageAlignment::middle;
    const auto padding = [&](std::size_t index) { return static_cast<std::uint8_t>(std::strtol(fields[index].c_str(), nullptr, 10)); };
    std::int32_t right = 0, bottom = 0;
    if (fields.size() == 4 || fields.size() >= 6) {
        node.image_x = padding(2);
        node.image_y = padding(3);
    }
    if (fields.size() >= 6) {
        right = padding(4);
        bottom = padding(5);
    }
    node.image_width = node.sprite->width + node.image_x + right;
    node.image_height = node.sprite->height + node.image_y + bottom;
}

SphereUI::HyperTextDocument::HyperTextDocument(std::string_view text, std::int32_t width, std::uint32_t format, std::uint32_t font) {
    if (!text.empty()) {
        parse(text);
        layout(width, format, font);
    }
}

void SphereUI::HyperTextDocument::setName(const char* value) {
    name = value == nullptr ? "" : value;
}

bool SphereUI::HyperTextDocument::load(const char* filename) {
    SferaSimpleParser parser{};
    parser.initialize();
    try {
        parser.load(filename);
        SferaParserRange range{};
        const bool found = parser.findBlock("hypertext", &range, nullptr, 1);
        if (found) load(parser, range);
        parser.release();
        return found;
    } catch (...) {
        parser.release();
        throw;
    }
}

void SphereUI::HyperTextDocument::load(const SferaSimpleParser& parser, const SferaParserRange& range) {
    std::string input;
    for (auto index = range.begin; index < range.end - 1; ++index) if (const char* line = parser.lineAt(index)) {
        while (*line == ' ') ++line;
        input += line;
        input += ' ';
    }
    parse(input);
}

void SphereUI::HyperTextDocument::parse(std::string_view input) {
    std::vector<HyperDocumentNode> parsed(1);
    std::vector<HyperTextRegion> parsed_links, parsed_tooltips;
    input = input.substr(0, input.find('\0'));
    for (std::size_t index = 0; index < input.size();) {
        if (input[index] != '<') {
            if (input[index] != '\n') parsed.back().text += input[index];
            ++index;
            continue;
        }
        const auto end = input.find('>', index + 1);
        if (end == std::string_view::npos) {
            parsed.back().text.append(input.substr(index));
            break;
        }
        HyperDocumentNode node;
        std::string argument;
        if (!HyperTextParser::parseCommand(input.substr(index + 1, end - index - 1), node, argument)) {
            parsed.back().text += input[index++];
            continue;
        }
        if (node.command == HyperTextCommand::linkStart || node.command == HyperTextCommand::tooltipStart) {
            HyperTextRegion region;
            const auto* target = node.command == HyperTextCommand::tooltipStart && !argument.empty() && argument.front() == '#' ? g_sfera_interface.localizedText(argument.c_str() + 1) : argument.c_str();
            region.target = target == nullptr ? "" : target;
            auto& regions = node.command == HyperTextCommand::linkStart ? parsed_links : parsed_tooltips;
            node.region_index = regions.size();
            regions.push_back(std::move(region));
        }
        parsed.push_back(std::move(node));
        index = end + 1;
    }
    nodes = std::move(parsed);
    links = std::move(parsed_links);
    tooltips = std::move(parsed_tooltips);
    lines.clear();
    line_height = 0;
}

SphereUI::HyperTextDocument* SphereUI::HyperTextDocument::clone(std::int32_t width, std::uint32_t format, std::uint32_t font) const {
    if (nodes.empty()) return nullptr;
    auto document = std::make_unique<HyperTextDocument>(*this);
    document->resetRegions();
    document->layout(width, format, font);
    return document.release();
}

void SphereUI::HyperTextDocument::layout(std::int32_t width, std::uint32_t format, std::uint32_t font) {
    width = std::max(width, 1);
    const auto tracking = InterfaceRenderer::tracking(font);
    const auto space = hyperTextExtent(" ", font);
    line_height = std::max(space.height, 1);
    this->font = font;
    std::vector<HyperDocumentFragment> originals;
    for (const auto& node : nodes) originals.push_back({node, node.text});
    std::vector<HyperDocumentRow> rows(1u);
    rows.back().height = line_height;
    const auto new_row = [&](bool paragraph) {
        rows.back().paragraph_end = paragraph;
        rows.emplace_back();
        rows.back().height = line_height;
    };
    for (const auto& original : originals) {
        auto node = original.node;
        if (node.command == HyperTextCommand::lineBreak) new_row(true);
        if (node.command == HyperTextCommand::tab) node.spacing = std::max(space.width, 0) * 4;
        auto& row = rows.back();
        if (node.command == HyperTextCommand::image) {
            row.width += node.image_width;
            row.height = std::max<std::int32_t>(row.height, node.image_height);
            const auto shift = std::max(0, node.image_height - line_height);
            row.baseline = std::max(row.baseline, node.image_alignment == HyperTextImageAlignment::bottom ? shift : node.image_alignment == HyperTextImageAlignment::middle ? shift / 2 : 0);
        } else if (node.command == HyperTextCommand::tab) row.width += node.spacing;
        row.fragments.push_back({node, {}});
        auto text = std::string_view(original.text);
        std::size_t start = 0u;
        while (start < text.size()) {
            const auto remaining = text.substr(start);
            const auto full_extent = hyperTextExtent(remaining, font);
            if (rows.back().width + full_extent.width <= width) {
                auto& current = rows.back();
                if (current.fragments.empty()) current.fragments.push_back({{}, {}});
                current.fragments.back().text.append(remaining);
                current.width += full_extent.width;
                break;
            }
            const auto end = hyperWordEnd(text, start);
            const auto word = text.substr(start, end - start);
            const auto extent = hyperTextExtent(word, font);
            auto visible = word;
            if (rows.back().width != 0 && rows.back().width + extent.width > width) {
                new_row(false);
                if (start != 0u && !visible.empty() && visible.front() == ' ') {
                    ++start;
                    visible.remove_prefix(1u);
                }
                if (hyperTextExtent(text.substr(start), font).width <= width) continue;
            }
            if (!visible.empty()) {
                auto& current = rows.back();
                if (current.fragments.empty() || current.fragments.back().node.command == HyperTextCommand::horizontalSpace) current.fragments.push_back({{}, {}});
                auto& fragment = current.fragments.back();
                fragment.text.append(visible);
                current.width += hyperTextExtent(visible, font).width + tracking;
            }
            start = end;
        }
    }
    if (originals.empty()) rows.clear();
    for (auto& row : rows) {
        for (auto& fragment : row.fragments) if (!fragment.text.empty()) {
            if (fragment.node.command != HyperTextCommand::preserveSpaces) {
                const auto first = fragment.text.find_first_not_of(' ');
                fragment.text.erase(0u, first == std::string::npos ? fragment.text.size() : first);
            }
            break;
        }
        for (auto fragment = row.fragments.rbegin(); fragment != row.fragments.rend(); ++fragment) if (!fragment->text.empty()) {
            const auto last = fragment->text.find_last_not_of(' ');
            fragment->text.resize(last == std::string::npos ? 0u : last + 1u);
            break;
        }
        row.width = 0;
        for (auto& fragment : row.fragments) {
            fragment.node.width = hyperTextExtent(fragment.text, font).width;
            row.width += fragment.node.width;
            if (fragment.node.command == HyperTextCommand::tab || fragment.node.command == HyperTextCommand::horizontalSpace) row.width += fragment.node.spacing;
            else if (fragment.node.command == HyperTextCommand::image) row.width += fragment.node.image_width;
        }
    }
    std::vector<HyperDocumentRow> final_rows;
    final_rows.reserve(rows.size());
    std::uint32_t color = 0xFFFFFFFFu;
    for (std::size_t index = 0u; index < rows.size(); ++index) {
        auto& row = rows[index];
        HyperDocumentRow result{};
        result.height = row.height;
        result.baseline = row.baseline;
        result.initial_color = color;
        const auto spare = std::max(0, width - row.width);
        if (format == 1u || format == 2u) {
            HyperDocumentNode padding{};
            padding.command = HyperTextCommand::horizontalSpace;
            padding.spacing = format == 1u ? spare : spare / 2;
            result.fragments.push_back({padding, {}});
        }
        std::size_t gaps = 0u;
        if (format == 3u && !row.paragraph_end) for (const auto& fragment : row.fragments) for (std::size_t character = 0u; character < fragment.text.size(); ++character) if (fragment.text[character] == ' ' && character != 0u && fragment.text[character - 1u] != ' ') ++gaps;
        std::size_t used_gaps = 0u;
        std::int32_t distributed = 0;
        for (auto& fragment : row.fragments) {
            if (fragment.node.command == HyperTextCommand::color) color = fragment.node.color;
            if (gaps == 0u) {
                result.fragments.push_back(std::move(fragment));
                continue;
            }
            std::size_t start = 0u;
            bool command = true;
            while (start < fragment.text.size()) {
                const auto word = fragment.text.find_first_not_of(' ', start);
                auto end = word == std::string::npos ? fragment.text.size() : fragment.text.find(' ', word);
                if (end == std::string::npos) end = fragment.text.size();
                else {
                    while (end < fragment.text.size() && fragment.text[end] == ' ') ++end;
                }
                auto node = command ? fragment.node : HyperDocumentNode{};
                command = false;
                const auto text = fragment.text.substr(start, end - start);
                node.width = hyperTextExtent(text, font).width + (end < fragment.text.size() ? tracking : 0);
                result.fragments.push_back({node, text});
                if (!text.empty() && text.back() == ' ' && text.find_first_not_of(' ') != std::string::npos) {
                    const auto added = ++used_gaps == gaps ? spare - distributed : spare / static_cast<std::int32_t>(gaps);
                    HyperDocumentNode padding{};
                    padding.command = HyperTextCommand::horizontalSpace;
                    padding.spacing = added;
                    distributed += added;
                    result.fragments.push_back({padding, {}});
                }
                start = end;
            }
            if (command) result.fragments.push_back(std::move(fragment));
        }
        final_rows.push_back(std::move(result));
    }
    std::vector<HyperDocumentLine> replacement;
    replacement.reserve(final_rows.size());
    for (auto& row : final_rows) {
        HyperDocumentLine line;
        line.height = row.height;
        line.baseline = row.baseline;
        line.initial_color = row.initial_color;
        line.nodes.reserve(row.fragments.size());
        for (auto& fragment : row.fragments) {
            fragment.node.text = std::move(fragment.text);
            line.nodes.push_back(std::move(fragment.node));
        }
        replacement.push_back(std::move(line));
    }
    lines = std::move(replacement);
}

bool SphereUI::HyperTextRegion::contains(std::int32_t x, std::int32_t y) const {
    if (!visible) return false;
    return std::any_of(rectangles.begin(), rectangles.end(), [=](const UiRect& bounds) { return x >= bounds.left && x < bounds.right && y >= bounds.top && y < bounds.bottom; });
}

void SphereUI::HyperTextRegion::addRectangle(const UiRect& rectangle, const UiRect& clip) {
    const UiRect bounds{std::max(rectangle.left, clip.left), std::max(rectangle.top, clip.top), std::min(rectangle.right, clip.right), std::min(rectangle.bottom, clip.bottom)};
    if (bounds.right <= bounds.left || bounds.bottom <= bounds.top) return;
    rectangles.push_back(bounds);
    visible = true;
}

std::int32_t SphereUI::HyperTextDocument::totalHeight() const {
    std::int64_t height = 0;
    for (const auto& line : lines) height += line.height;
    return static_cast<std::int32_t>(std::clamp<std::int64_t>(height, 0, std::numeric_limits<std::int32_t>::max()));
}

void SphereUI::HyperTextDocument::resetRegions() {
    for (auto* group : {&links, &tooltips}) for (auto& region : *group) {
        region.visible = false;
        region.hovered = false;
        region.rectangles.clear();
    }
}

SphereUI::UiRect SphereUI::HyperTextDocument::linkRectangle(std::int32_t left, std::int32_t right, std::int32_t y, std::int32_t baseline) const {
    const auto inset = font < 2u ? 2 : 0;
    const auto bottom_inset = font == 0u ? 2 : font == 1u ? 3 : 0;
    return {left, y + baseline + inset, right + inset, y + baseline * 2 + line_height + bottom_inset};
}

void SphereUI::HyperTextDocument::draw(std::int32_t left, std::int32_t top, std::int32_t clip_offset, std::int32_t clip_height, std::uint32_t alpha) {
    const auto viewport = SphereUI::InterfaceRenderer::viewport();
    const UiRect clip{static_cast<std::int32_t>(viewport.x), std::max(top, static_cast<std::int32_t>(viewport.y)), static_cast<std::int32_t>(viewport.x + viewport.width), std::min(top + std::max(clip_height, 0), static_cast<std::int32_t>(viewport.y + viewport.height))};
    for (auto* group : {&links, &tooltips}) for (auto& region : *group) {
        region.rectangles.clear();
        region.visible = false;
    }
    const auto opacity = std::min(alpha, 255u) << 24u;
    auto y = top + clip_offset;
    HyperTextRegion* link = nullptr;
    HyperTextRegion* tooltip = nullptr;
    for (const auto& line : lines) {
        auto x = left, link_left = left, tooltip_left = left;
        auto color = line.initial_color;
        const auto baseline = line.baseline;
        for (const auto& node : line.nodes) {
            if (node.command == HyperTextCommand::color) color = node.color;
            else if (node.command == HyperTextCommand::linkStart) {
                link = node.region_index < links.size() ? &links[node.region_index] : nullptr;
                link_left = x;
            } else if (node.command == HyperTextCommand::linkEnd) {
                if (link != nullptr) link->addRectangle(linkRectangle(link_left, x, y, baseline), clip);
                link = nullptr;
            } else if (node.command == HyperTextCommand::tooltipStart) {
                tooltip = node.region_index < tooltips.size() ? &tooltips[node.region_index] : nullptr;
                tooltip_left = x;
            } else if (node.command == HyperTextCommand::tooltipEnd) {
                if (tooltip != nullptr) tooltip->addRectangle({tooltip_left, y, x, y + line.height}, clip);
                tooltip = nullptr;
            } else if (node.command == HyperTextCommand::horizontalSpace || node.command == HyperTextCommand::tab) {
                x += node.spacing;
                if (link != nullptr && link_left == left) link_left = x;
                if (tooltip != nullptr && tooltip_left == left) tooltip_left = x;
            } else if (node.command == HyperTextCommand::image) {
                if (node.sprite != nullptr && y + line.height > clip.top && y < clip.bottom) node.sprite->drawNatural(static_cast<float>(x + node.image_x), static_cast<float>(y + node.image_y), opacity | 0xFFFFFFu);
                x += node.image_width;
            }
            if (!node.text.empty() && y + line.height > clip.top && y < clip.bottom) {
                const auto text_color = link == nullptr ? color : link->hovered ? hover_color : link_color;
                SphereUI::InterfaceRenderer::drawText(node.text.c_str(), x, y + baseline, opacity | (text_color & 0xFFFFFFu), font, true, clip, alpha == 255u);
            }
            x += node.width;
        }
        if (link != nullptr) link->addRectangle(linkRectangle(link_left, x, y, baseline), clip);
        if (tooltip != nullptr) tooltip->addRectangle({tooltip_left, y, x, y + line.height}, clip);
        y += line.height;
        if (y >= clip.bottom) break;
    }
}

void SphereUI::HyperTextParser::parseElements(const UiString& text, UiDeque<HyperTextElement*>& elements, UiString& plain) {
    UiDeque<HyperTextElement*> parsed{};
    UiString visible{};
    std::string output, pending, parameters, target;
    std::uint32_t kind = 4u;
    bool link = false;
    const std::string input(text.data(), text.length);
    const auto flush = [&](bool linked) {
        if (pending.empty()) return;
        const auto decoded = hyperUnescape(pending);
        if (!decoded.empty()) {
            if (linked) {
                auto* value = hyperAllocate<HyperTextElement_Link>();
                value->type = 5u;
                value->link_kind = kind;
                try {
                    value->text.assign(decoded.c_str());
                    value->parameters.assign(parameters.c_str());
                    value->target.assign(target.c_str());
                } catch (...) {
                    value->release();
                    throw;
                }
                hyperAppendElement(parsed, value);
            } else hyperAppendElement(parsed, hyperPlainElement(decoded));
            output += decoded;
        }
        pending.clear();
    };
    try {
        parsed.initialize();
        for (std::size_t index = 0u; index < input.size();) {
            if (input[index] != '<') {
                pending += input[index++];
                continue;
            }
            const auto end = hyperTagEnd(input, index + 1u);
            if (end == std::string::npos || end == index + 1u) {
                pending.append(input, index, std::string::npos);
                break;
            }
            const auto tag = hyperTrim(std::string_view(input).substr(index + 1u, end - index - 1u));
            const auto name_end = tag.find_first_of(" =\t\r\n");
            const auto name = tag.substr(0u, name_end);
            if (hyperEquals(name, "l")) {
                std::string new_target;
                std::uint32_t new_kind = 4u;
                const auto remainder = name_end == std::string_view::npos ? std::string_view{} : hyperTrim(tag.substr(name_end));
                if (hyperLinkParameters(remainder, new_target, new_kind)) {
                    flush(false);
                    parameters.assign(remainder);
                    target = std::move(new_target);
                    kind = new_kind;
                    link = true;
                } else flush(false);
            } else if (hyperEquals(name, "/l") || hyperEquals(name, "\\l")) {
                flush(link);
                link = false;
            } else flush(false);
            index = end + 1u;
        }
        if (!link) flush(false);
        visible.assign(output.c_str());
    } catch (...) {
        HyperTextParser::releaseElements(parsed);
        visible.release();
        throw;
    }
    hyperTakeElements(elements, parsed);
    plain.release();
    plain = visible;
}

void SphereUI::HyperTextChatListItem::layout(std::int32_t width, std::uint32_t font) {
    width = std::max(width, 1);
    UiDeque<HyperTextElement*> output{};
    UiArray<UiIndexRange> replacement_rows{};
    std::int32_t x = 0;
    std::uint32_t first = 0u;
    const auto wrap = [&](std::string_view separator) {
        if (output.count > first) replacement_rows.append({first, output.count - 1u});
        hyperAppendElement(output, hyperPlainElement(separator, true));
        first = output.count;
        x = 0;
    };
    const auto append = [&](HyperTextElement* element) {
        if (auto* geometry = element->geometry()) {
            const auto extent = hyperTextExtent(std::string_view(element->text.data(), element->text.length), font);
            *geometry = {x, 0, extent.width, extent.height};
            x += extent.width;
        }
        hyperAppendElement(output, element);
    };
    try {
        output.initialize();
        for (std::uint32_t index = 0u; index < elements.count; ++index) {
            const auto* element = elements.at(index);
            if (element == nullptr) continue;
            if (element->type == 3u) {
                if (element->text.length != 0u) wrap(std::string_view(element->text.data(), element->text.length));
                continue;
            }
            if (element->type == 5u) {
                const auto extent = hyperTextExtent(std::string_view(element->text.data(), element->text.length), font);
                if (x != 0 && x + extent.width > width) wrap({});
                append(element->clone());
                continue;
            }
            if (element->type != 4u) continue;
            const std::string_view text(element->text.data(), element->text.length);
            std::string pending;
            const auto flush = [&]() {
                if (!pending.empty()) {
                    append(hyperPlainElement(pending));
                    pending.clear();
                }
            };
            for (std::size_t position = 0u; position < text.size();) {
                const auto end = hyperWordEnd(text, position, true);
                const auto token = text.substr(position, end - position);
                const auto combined = pending + std::string(token);
                if (x + hyperTextExtent(combined, font).width <= width || (x == 0 && pending.empty())) pending = combined;
                else {
                    flush();
                    auto visible = token;
                    const auto leading = visible.find_first_not_of(" \t\r\n");
                    const auto spaces = leading == std::string_view::npos ? visible.size() : leading;
                    wrap(visible.substr(0u, spaces));
                    visible.remove_prefix(spaces);
                    pending.assign(visible);
                }
                position = end;
            }
            flush();
        }
        if (output.count > first) replacement_rows.append({first, output.count - 1u});
    } catch (...) {
        HyperTextParser::releaseElements(output);
        replacement_rows.release();
        throw;
    }
    hyperTakeElements(elements, output);
    rows.release();
    rows = replacement_rows;
}

void SphereUI::HyperTextParser::releaseElements(UiDeque<HyperTextElement*>& elements) {
    for (std::uint32_t index = 0u; index < elements.count; ++index) if (auto* element = elements.at(index)) element->release();
    elements.release();
}


SphereUI::InterfaceManager::~InterfaceManager() { shutdown(); }

bool SphereUI::InterfaceManager::prepareResources() {
    if (initialized) return false;
    g_sfera_fonts.initialize();
    InterfaceConfiguration::open("control.cfg");
    g_sfera_interface_runtime.cross_enabled = 1u;
    InterfaceConfiguration::readInteger("EN_CROSS", g_sfera_interface_runtime.cross_enabled);
    InterfaceConfiguration::readInteger("INTFS_SOUNDS", g_sfera_interface_runtime.sounds_enabled);
    if (!cursor) {
        cursor = std::make_unique<SferaInterfaceCursor>();
        cursor->loadTextures();
    }
    g_sfera_fonts.loadConfiguration();
    cursor->setKind(255u);
    setCursorKind(255u, 0, 0);
    setCursorImage(nullptr, 0, 0);
    loadLocalizedStrings();
    loadWindowTemplates("Effects\\loadscreen.ui");
    loadSprites("Effects\\sprites.ui");
    return true;
}

void SphereUI::InterfaceManager::finishInitialization() { drag_drop_active = false; initialized = true; }

bool SphereUI::InterfaceManager::shutdown() {
    const bool was_initialized = initialized;
    clearWindows();
    if (tooltip != nullptr) { tooltip->destroy(true); tooltip = nullptr; }
    clearWindowTemplates();
    clearHyperTexts();
    g_sfera_fonts.clear();
    clearLocalizedStrings();
    events.clear();
    cursor.reset();
    cursor_name.clear();
    g_sfera_interface_runtime.cursor_kind = 255u;
    clearSprites();
    event_handlers.clear();
    initialized = false;
    drag_drop_active = false;
    return was_initialized;
}

void SphereUI::InterfaceManager::clearWindows() {
    help_window = nullptr;
    load_screen = nullptr;
    g_sfera_interface_runtime.description_control = nullptr;
    while (!windows.empty()) {
        Window* window = windows.front();
        windows.pop_front();
        if (window != nullptr) window->destroy(true);
    }
}

void SphereUI::InterfaceManager::queueEvent(const WindowEvent& event) {
    if (events.size() >= 64u) events.clear();
    events.push_back(event);
}

bool SphereUI::InterfaceManager::pollEvent(WindowEvent& event) {
    if (events.empty()) return false;
    event = events.front();
    events.pop_front();
    return true;
}

SphereUI::Window* SphereUI::InterfaceManager::findWindow(const char* name, bool exact) const {
    if (name == nullptr) return nullptr;
    const auto found = std::find_if(windows.begin(), windows.end(), [name, exact](const Window* window) { return window != nullptr && (exact ? std::strcmp(window->getResourceName(), name) == 0 : SferaSimpleParser::equalsIgnoreCase(window->getResourceName(), name)); });
    return found == windows.end() ? nullptr : *found;
}

SphereUI::Window* SphereUI::InterfaceManager::windowUnderCursor() const {
    SferaCursorPosition position{};
    CCursorManager::instance().activeCursor()->getPosition(&position);
    const auto found = std::find_if(windows.rbegin(), windows.rend(), [&position](const Window* window) { return window != nullptr && window->hidden == 0u && window->hit_transparent == 0u && window->containsPoint(position.x, position.y); });
    return found == windows.rend() ? nullptr : *found;
}

bool SphereUI::InterfaceManager::hasEscapeWindow() const {
    return std::any_of(windows.begin(), windows.end(), [](const Window* window) { return window != nullptr && window->hidden == 0u && (window->behavior_flags & WindowStyle::handleEscape) != 0u; });
}

void SphereUI::InterfaceManager::addTopLevelWindow(Window& window) {
    if (std::find(windows.begin(), windows.end(), &window) == windows.end()) windows.push_back(&window);
}

void SphereUI::InterfaceManager::raiseWindow(Window& window) {
    const auto found = std::find(windows.begin(), windows.end(), &window);
    if (found != windows.end()) windows.splice(windows.end(), windows, found);
}

void SphereUI::InterfaceManager::lowerWindow(Window& window) {
    const auto found = std::find(windows.begin(), windows.end(), &window);
    if (found != windows.end()) windows.splice(windows.begin(), windows, found);
}

void SphereUI::InterfaceManager::collectCoveredWindows(Window& window) {
    if (g_sfera_interface_runtime.cross_enabled == 0u) return;
    UiRect bounds{};
    window.getAbsolutePosition(bounds.left, bounds.top);
    bounds.right = bounds.left + window.width;
    bounds.bottom = bounds.top + window.height;
    const auto area = static_cast<std::int64_t>(window.width) * window.height;
    if (area <= 0) return;
    for (auto current = windows.rbegin(); current != windows.rend(); ++current) {
        Window* other = *current;
        if (other == nullptr || other == &window || other->hidden != 0u || other->animation_active != 0u || other->animation_state != 0u || (other->behavior_flags & WindowStyle::preventOverlap) != 0u) continue;
        UiRect other_bounds{};
        other->getAbsolutePosition(other_bounds.left, other_bounds.top);
        other_bounds.right = other_bounds.left + other->width;
        other_bounds.bottom = other_bounds.top + other->height;
        if (other_bounds.right < bounds.left || bounds.right < other_bounds.left || other_bounds.bottom < bounds.top || bounds.bottom < other_bounds.top) continue;
        const bool contains_window = other_bounds.left < bounds.left && other_bounds.right > bounds.right && other_bounds.top < bounds.top && other_bounds.bottom > bounds.bottom;
        if (contains_window) { window.addModalReference(*other); continue; }
        const bool contained_window = other_bounds.left > bounds.left && other_bounds.right < bounds.right && other_bounds.top > bounds.top && other_bounds.bottom < bounds.bottom;
        std::int32_t covered_width = other->width;
        std::int32_t covered_height = other->height;
        if (!contained_window) {
            if (other_bounds.left < bounds.left) covered_width = std::min(bounds.right, other_bounds.right) - bounds.left;
            else if (other_bounds.left > bounds.left) covered_width = bounds.right - other_bounds.left;
            if (other_bounds.top < bounds.top) covered_height = std::min(bounds.bottom, other_bounds.bottom) - bounds.top;
            else if (other_bounds.top > bounds.top) covered_height = bounds.bottom - other_bounds.top;
        }
        const auto covered_area = static_cast<std::int64_t>(covered_width) * covered_height;
        if (static_cast<float>(static_cast<double>(covered_area) / area) > 0.3f) window.addModalReference(*other);
    }
}

SphereUI::Window* SphereUI::InterfaceManager::openWindow(const char* name, std::int32_t x, std::int32_t y, std::uint32_t flags) {
    if (name == nullptr) return nullptr;
    std::string template_name(name);
    if (const auto separator = template_name.rfind(':'); separator != std::string::npos) template_name.resize(separator);
    Window* original = templateWindow(template_name.c_str());
    if (original == nullptr) return nullptr;
    Window* window = original->clone();
    if (window == nullptr) { InterfaceRenderer::reportError("Cannot clone the requested window template."); return nullptr; }
    try {
        window->setName(name);
        if ((flags & explicitPosition) != 0u) window->setPosition(x, y);
        else {
            const SavedWindowPosition* saved = savedPosition(name, false);
            const bool valid_position = saved != nullptr && (saved->x < static_cast<std::int32_t>(g_sfera_graphics_runtime.display_width) - 15 || saved->y < static_cast<std::int32_t>(g_sfera_graphics_runtime.display_height) - 15);
            if (valid_position && window->save_last_position != 0u && findWindow(name, true) == nullptr) window->setPosition(saved->x, saved->y);
            else {
                if ((flags & centerOnScreen) != 0u) window->alignment_flags = 0x24u;
                window->alignToScreen(false);
            }
        }
        if ((flags & preserveVisibility) == 0u) window->hidden = 0u;
        if (window->hidden == 0u && (flags & skipOpeningAnimation) == 0u) window->startAnimation(1u);
        window->input_enabled = 1u;
        collectCoveredWindows(*window);
        if (auto* head = window->reference_sentinel) for (auto* node = head->next; node != head; node = node->next) if (node->value != nullptr) node->value->handleMessage(UiMessage::beginModal, SferaAbi::address(window), 0u);
        addTopLevelWindow(*window);
    } catch (...) { window->destroy(true); throw; }
    return window;
}

void SphereUI::InterfaceManager::closeWindow(Window* window, bool animated) {
    if (window == nullptr) return;
    if (window->control_id != 0u) InterfaceRenderer::reportError("Cannot close a child control through the interface manager.");
    window->beginClose(animated);
}

void SphereUI::InterfaceManager::showHelpPage(const char* name) {
    if (name == nullptr) { closeWindow(help_window); help_window = nullptr; return; }
    if (findHyperText(name) == nullptr) return;
    if (help_window == nullptr) {
        help_window = openWindow("help");
        bindEventHandler(help_window, WindowEventHandler::help);
    } else raiseWindow(*help_window);
    if (help_window == nullptr) return;
    auto* control = dynamic_cast<HyperTextCtrl*>(help_window->controlAt(3u));
    if (control == nullptr) return;
    if (control->document != nullptr && SferaSimpleParser::equalsIgnoreCase(control->document->name.c_str(), name)) return;
    sendMessage(help_window->controlAt(2u), UiMessage::setEnabled, control->history.count != 0u ? 1u : 0u, 0u);
    control->queuePage(name, true);
}

void SphereUI::InterfaceManager::setTooltipText(const char* text) {
    if (text == nullptr) { if (tooltip != nullptr && !tooltip_disabled) tooltip->reset(); return; }
    if (tooltip == nullptr) tooltip = static_cast<ToolTipCtrl*>(Runtime::makeControl(9u));
    if (tooltip == nullptr) return;
    tooltip->handleMessage(UiMessage::setTooltipLine, 0u, SferaAbi::address(text));
    SferaCursorPosition position{};
    CCursorManager::instance().activeCursor()->getPosition(&position);
    tooltip->showAt(position.x, position.y);
}

void SphereUI::InterfaceManager::setCursorKind(std::uint32_t kind, std::int32_t x, std::int32_t y) {
    if (!cursor) return;
    const char* texture = nullptr;
    if (kind == 64u || kind == 65u) { texture = "curseye"; kind = 64u; }
    else if (kind == 66u || kind == 67u) texture = "cursman";
    else if (kind != 255u) return;
    else { x = 0; y = 0; }
    cursor->setImage(0u, texture, x, y);
    g_sfera_interface_runtime.cursor_kind = kind;
}

void SphereUI::InterfaceManager::setCursorImage(const char* texture, std::int32_t x, std::int32_t y) {
    if (!cursor) return;
    if (texture == nullptr) { x = 0; y = 0; }
    cursor->setImage(1u, texture, x, y);
    cursor_name = texture == nullptr ? "" : texture;
}

std::uint32_t SphereUI::InterfaceManager::sendMessage(Window* window, std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    if (message == 10u) { drag_drop_active = true; return 1u; }
    if (message == 14u) { showHelpPage(SferaAbi::pointer<const char>(first)); return 1u; }
    if (message < UiMessage::close) InterfaceRenderer::reportError("Unknown interface manager message.");
    return isRegistered(window) ? window->handleMessage(message, first, second) : 0u;
}

void SphereUI::InterfaceManager::draw() {
    const auto saved_clip = g_sfera_screen_clip_runtime;
    InterfaceRenderer::setSpriteRenderMode(1u);
    try {
        if (g_sfera_interface_runtime.primary_gate != 0u) {
            for (Window* window : windows) window->draw();
            for (Window* window : windows) window->drawToolTips();
        }
        if (tooltip != nullptr && !tooltip_disabled) tooltip->draw();
        if (cursor && cursor->system_visible) {
            g_sfera_screen_clip_runtime.left = 0;
            g_sfera_screen_clip_runtime.top = 0;
            g_sfera_screen_clip_runtime.right = g_sfera_graphics_runtime.display_width;
            g_sfera_screen_clip_runtime.bottom = g_sfera_graphics_runtime.display_height;
            CCursor* active = CCursorManager::instance().activeCursor();
            SferaCursorPosition position{};
            active->getPosition(&position);
            if (active->isInsideViewport()) cursor->draw(static_cast<float>(position.x), static_cast<float>(position.y));
        }
    } catch (...) { g_sfera_screen_clip_runtime = saved_clip; InterfaceRenderer::setSpriteRenderMode(0u); throw; }
    g_sfera_screen_clip_runtime = saved_clip;
    InterfaceRenderer::setSpriteRenderMode(0u);
}

void SphereUI::InterfaceManager::showLoadingScreen(bool visible, std::int32_t width, std::int32_t height, bool english) {
    if (!visible) { closeWindow(load_screen); load_screen = nullptr; return; }
    if (load_screen == nullptr) {
        load_screen = openWindow("loadscreen", 0, 0, skipOpeningAnimation);
        if (load_screen == nullptr) return;
        lowerWindow(*load_screen);
    }
    load_screen->setPosition(0, 0);
    load_screen->handleMessage(UiMessage::setSize, 0u, 0u);
    const std::int32_t image_width = std::min(width, 1024);
    const std::int32_t image_height = std::min(height, 768);
    const std::int32_t left = width > 1024 ? (width - 1024) / 2 : 0;
    const std::int32_t top = height > 768 ? (height - 768) / 2 : 0;
    sendMessage(load_screen->controlAt(2u), UiMessage::setPosition, left, top);
    sendMessage(load_screen->controlAt(2u), UiMessage::setSize, image_width, image_height);
    sendMessage(load_screen->controlAt(1u), UiMessage::setPosition, 0u, 0u);
    sendMessage(load_screen->controlAt(1u), UiMessage::setSize, width, height);
    sendMessage(load_screen->controlAt(2u), UiMessage::setImageName, SferaAbi::address(english ? "english_sphere1" : "russian_sphere1"), 0u);
    const std::int32_t progress_left = left + static_cast<std::int32_t>(image_width * 0.3701171875);
    const std::int32_t progress_top = top + static_cast<std::int32_t>(image_height * 0.83203125);
    const std::int32_t progress_width = static_cast<std::int32_t>(image_width * 0.2490234375);
    const std::int32_t progress_height = static_cast<std::int32_t>(image_height * 0.0247395833);
    for (const auto index : {3u, 4u}) {
        sendMessage(load_screen->controlAt(index), UiMessage::setPosition, progress_left, progress_top);
        sendMessage(load_screen->controlAt(index), UiMessage::setSize, progress_width, progress_height);
    }
    sendMessage(load_screen->controlAt(3u), UiMessage::setProgressValue, 100u, 0u);
    sendMessage(load_screen->controlAt(5u), UiMessage::setPosition, left + 375, top + 520);
    sendMessage(load_screen->controlAt(5u), UiMessage::setSize, 620u, 90u);
}

void SphereUI::InterfaceManager::setLoadingProgress(std::int32_t percent) {
    if (load_screen != nullptr) sendMessage(load_screen->controlAt(3u), UiMessage::setProgressValue, static_cast<std::uint32_t>(std::clamp(percent, 0, 100)), 0u);
}

void SphereUI::InterfaceManager::update(std::uint8_t key, std::uint8_t character, std::uint32_t mouse_buttons, std::int32_t wheel_delta) {
    const auto& keyboard = g_sfera_direct_input_runtime.keyboard_state;
    if (key == VK_F12 && keyboard[DIK_LCONTROL] != 0u) g_sfera_interface_runtime.primary_gate = g_sfera_interface_runtime.primary_gate == 0u;
    else if (key == VK_F1) showHelpPage("Language\\helpindex.hts");
    if (g_sfera_interface_runtime.primary_gate == 0u) return;
    if (g_sfera_client_process_runtime.ui_bridge != 0u && g_sfera_main_command_state_runtime.command_state != 0u && capture_control_binding) {
        const WindowEvent event{nullptr, 0u, UiMessage::controlBindingCaptured, g_sfera_main_command_state_runtime.command_state, 0u, 0u, 0u};
        Runtime::invokeEventHandler(WindowEventHandler::control_options, nullptr, event);
        g_sfera_main_command_state_runtime.command_state = 0u;
    }
    if (auto* description = g_sfera_interface_runtime.description_control) description->update();
    SferaCursorPosition position{};
    CCursorManager::instance().activeCursor()->getPosition(&position);
    WindowInput input{position.x, position.y, wheel_delta, 0u, mouse_buttons, key, character, {}, 0u};
    const auto previous_buttons = g_sfera_interface_runtime.previous_input_modifiers;
    const auto changed_buttons = mouse_buttons ^ previous_buttons;
    input.mouse_flags = (changed_buttons & mouse_buttons & 3u) | ((changed_buttons & previous_buttons & 3u) << 2u);
    g_sfera_interface_runtime.previous_input_modifiers = mouse_buttons;
    if (keyboard[DIK_LSHIFT] != 0u) input.key_modifiers |= 1u;
    if (keyboard[DIK_RSHIFT] != 0u) input.key_modifiers |= 2u;
    if (keyboard[DIK_LCONTROL] != 0u) input.key_modifiers |= 4u;
    if (g_sfera_direct_input_runtime.modifier_08 != 0u) input.key_modifiers |= 8u;
    if (keyboard[DIK_LMENU] != 0u) input.key_modifiers |= 16u;
    if (g_sfera_direct_input_runtime.modifier_20 != 0u) input.key_modifiers |= 32u;
    const std::vector<Window*> closing_candidates(windows.begin(), windows.end());
    for (Window* window : closing_candidates) {
        if (!isRegistered(window) || window->animation_state == 0u) continue;
        std::vector<Window*> references;
        if (auto* head = window->reference_sentinel) for (auto* node = head->next; node != head; node = node->next) references.push_back(node->value);
        for (Window* reference : references) {
            if (!isRegistered(reference) || reference->animation_active != 0u || std::find(windows.begin(), windows.end(), reference) == windows.end()) continue;
            reference->handleMessage(UiMessage::endModal, 0u, 0u);
        }
        if (!isRegistered(window)) continue;
        if (window->control_id != 0u) { InterfaceRenderer::reportError("Cannot destroy a child control through the interface manager."); continue; }
        windows.remove(window);
        window->destroy(true);
    }
    Window* target = nullptr;
    for (auto window = windows.rbegin(); window != windows.rend(); ++window) if (isRegistered(*window) && (*window)->hidden == 0u && ((*window)->dragging != 0u || (*window)->containsPoint(position.x, position.y))) {
        target = *window;
        break;
    }
    if (auto* description = g_sfera_interface_runtime.description_control; description != nullptr && description->hidden == 0u) {
        for (auto window = windows.rbegin(); window != windows.rend(); ++window) if (isRegistered(*window) && (*window)->dragging != 0u) {
            target = *window;
            break;
        }
    }
    if ((input.mouse_flags & MouseInput::leftPress) != 0u && target != nullptr && target->can_go_top != 0u && target->hit_transparent == 0u && target->hidden == 0u) raiseWindow(*target);
    if (auto* description = g_sfera_interface_runtime.description_control; description != nullptr && description->hidden == 0u) raiseWindow(*description);
    bool completed_drag = false;
    if (drag_drop_active) {
        for (Window* window : windows) {
            if (!isRegistered(window) || window->can_drag_drop == 0u) continue;
            const bool entered = window == target;
            if (entered == ((window->text_state & 2u) != 0u)) continue;
            window->queueEvent({window, 0u, entered ? UiMessage::dragEnter : UiMessage::dragLeave, 0u, 0u, 0u, 0u});
            if (entered) window->text_state |= 2u;
            else window->text_state &= ~2u;
        }
        if ((input.mouse_flags & MouseInput::leftRelease) != 0u) {
            const bool accepted = isRegistered(target) && target->can_drag_drop != 0u && target->hitTest(position.x, position.y);
            if (!accepted) queueEvent({nullptr, 0u, UiMessage::dropToScene, static_cast<std::uint32_t>(position.x), static_cast<std::uint32_t>(position.y), 0u, 0u});
            for (Window* window : windows) {
                if (!isRegistered(window) || (window->text_state & 2u) == 0u) continue;
                window->queueEvent({window, 0u, UiMessage::dragLeave, 0u, 0u, 0u, 0u});
                window->text_state &= ~2u;
            }
            completed_drag = true;
        }
    }
    if (input.key_code == VK_ESCAPE) {
        const auto window = std::find_if(windows.rbegin(), windows.rend(), [this](const Window* candidate) { return isRegistered(candidate) && candidate->hidden == 0u && (candidate->behavior_flags & WindowStyle::handleEscape) != 0u; });
        if (window != windows.rend()) (*window)->queueEvent({*window, 0u, UiMessage::close, 0u, 0u, 0u, 0u});
    }
    Runtime::setTextInputActive(false);
    input.mouse_x = input.mouse_y = 0;
    const std::vector<Window*> input_order(windows.rbegin(), windows.rend());
    for (Window* window : input_order) {
        if (!isRegistered(window)) continue;
        if (window == target) { input.mouse_x = position.x; input.mouse_y = position.y; }
        if (window->input_enabled != 0u && window->hidden == 0u) window->handleInput(input);
        input.mouse_x = input.mouse_y = 0;
        if (!isRegistered(window)) continue;
        if (window->animation_active != 0u) window->updateAnimation();
        if (isRegistered(window) && hasEventHandler(window)) window->processEvents();
    }
    if (tooltip != nullptr && !tooltip_disabled) tooltip->handleInput(input);
    if (completed_drag) drag_drop_active = false;
}

void SphereUI::InterfaceManager::registerWindow(Window& window) { registered_windows.insert(&window); }
void SphereUI::InterfaceManager::unregisterWindow(Window& window) {
    registered_windows.erase(&window);
    windows.remove(&window);
    if (help_window == &window) help_window = nullptr;
    if (load_screen == &window) load_screen = nullptr;
    if (tooltip == &window) tooltip = nullptr;
    if (g_sfera_interface_runtime.description_control == &window) g_sfera_interface_runtime.description_control = nullptr;
}
bool SphereUI::InterfaceManager::isRegistered(const Window* window) const { return window != nullptr && registered_windows.contains(const_cast<Window*>(window)); }
void SphereUI::InterfaceManager::bindEventHandler(Window* window, WindowEventHandler handler) {
    if (window == nullptr) return;
    if (handler == WindowEventHandler::none) event_handlers.erase(window);
    else event_handlers.insert_or_assign(window, handler);
}
void SphereUI::InterfaceManager::copyEventHandler(Window* destination, const Window* source) {
    if (destination == nullptr || destination == source) return;
    const auto binding = event_handlers.find(source);
    bindEventHandler(destination, binding == event_handlers.end() ? WindowEventHandler::none : binding->second);
}
bool SphereUI::InterfaceManager::hasEventHandler(const Window* window) const { return window != nullptr && event_handlers.contains(window); }
void SphereUI::InterfaceManager::dispatchEvent(Window* window, const WindowEvent& event) {
    const auto binding = event_handlers.find(window);
    Runtime::invokeEventHandler(binding == event_handlers.end() ? WindowEventHandler::none : binding->second, window, event);
}
void SphereUI::InterfaceManager::unbindEventHandler(const void* window) { event_handlers.erase(static_cast<const Window*>(window)); }

void SphereUI::UiSprite::setDescription(const ImageDescription& description) {
    replaceSpriteText(name, description.name);
    resizeParts(1u);
    const auto flags = description.image.flags;
    const auto* rectangle = (flags & 2u) != 0u ? description.image.rectangle : nullptr;
    const char* texture_name = (flags & 4u) != 0u ? description.image.texture_name : description.name;
    auto& part = *parts;
    part.setTexture(texture_name, rectangle, rectangle);
    setColors(std::numeric_limits<std::uint32_t>::max());
    width = (flags & 1u) != 0u ? description.image.width : part.width;
    height = (flags & 1u) != 0u ? description.image.height : part.height;
}


SphereUI::UiSprite* SphereUI::UiSprite::create() {
    auto* storage = static_cast<UiSprite*>(Runtime::allocate(sizeof(UiSprite)));
    if (storage == nullptr) return nullptr;
    auto* sprite = std::construct_at(storage);
    sprite->initialize();
    return sprite;
}

void SphereUI::UiSprite::destroy() {
    release();
    std::destroy_at(this);
    Runtime::deallocate(this);
}

SphereUI::UiSprite* SphereUI::UiSprite::clone() const {
    const auto result = create();
    if (result == nullptr) throw std::bad_alloc();
    try {
        result->copyFrom(*this);
    } catch (...) {
        result->destroy();
        throw;
    }
    return result;
}


namespace SphereUI::detail {
    void copyText(std::span<char> destination, const char* source);
    std::int32_t addCoordinate(std::int32_t left, std::int32_t right);
    std::int32_t subtractCoordinate(std::int32_t left, std::int32_t right);
}


namespace {
    struct UiDeflateBits {
        std::span<const std::uint8_t> input;
        std::size_t position = 0u;
        unsigned offset = 0u;
        std::uint32_t read(unsigned count) {
            std::uint32_t result = 0u;
            for (unsigned bit = 0u; bit < count; ++bit) {
                if (position == input.size()) throw std::runtime_error("Truncated UI configuration stream");
                result |= ((input[position] >> offset) & 1u) << bit;
                if (++offset == 8u) {
                    offset = 0u;
                    ++position;
                }
            }
            return result;
        }

        void align() {
            if (offset != 0u) {
                offset = 0u;
                ++position;
            }
        }
    };

    struct UiDeflateAlphabet {
        std::array<std::uint16_t, 16> counts{};
        std::array<std::uint16_t, 288> symbols{};
        explicit UiDeflateAlphabet(std::span<const std::uint8_t> lengths, bool require_complete = false) {
            for (const auto length : lengths) {
                if (length > 15u) throw std::runtime_error("Invalid UI Huffman length");
                ++counts[length];
            }
            int available = 1;
            for (unsigned length = 1u; length < 16u; ++length) {
                available = available * 2 - counts[length];
                if (available < 0) throw std::runtime_error("Oversubscribed UI Huffman alphabet");
            }
            if (available != 0 && (require_complete || *std::max_element(lengths.begin(), lengths.end()) > 1u)) throw std::runtime_error("Incomplete UI Huffman alphabet");
            std::array<std::uint16_t, 16> offsets{};
            for (unsigned length = 1u; length < 15u; ++length) offsets[length + 1u] = offsets[length] + counts[length];
            for (std::uint16_t symbol = 0u; symbol < lengths.size(); ++symbol) if (lengths[symbol] != 0u) symbols[offsets[lengths[symbol]]++] = symbol;
        }

        std::uint32_t decode(UiDeflateBits& bits) const {
            unsigned code = 0u, first = 0u, index = 0u;
            for (unsigned length = 1u; length < 16u; ++length) {
                code = (code << 1u) | bits.read(1u);
                if (code >= first && code - first < counts[length]) return symbols[index + code - first];
                index += counts[length];
                first = (first + counts[length]) << 1u;
            }
            throw std::runtime_error("Invalid UI Huffman code");
        }
    };

    std::vector<std::uint8_t> uiInflateConfig(std::span<const std::uint8_t> input, std::size_t limit) {
        if (input.size() < 6u || (input[0] & 15u) != 8u || (input[0] >> 4u) > 7u || ((input[0] * 256u + input[1]) % 31u) != 0u || (input[1] & 32u) != 0u) throw std::runtime_error("Invalid UI configuration zlib header");
        UiDeflateBits bits{input.subspan(2u)};
        std::vector<std::uint8_t> output;
        bool last = false;
        const auto append = [&](std::uint8_t value) {
            if (output.size() == limit) throw std::length_error("UI configuration too large");
            output.push_back(value);
        };
        do {
            last = bits.read(1u) != 0u;
            const auto kind = bits.read(2u);
            if (kind == 0u) {
                bits.align();
                const auto length = bits.read(16u), complement = bits.read(16u);
                if ((length ^ complement) != 65535u) throw std::runtime_error("Invalid UI stored block length");
                for (unsigned index = 0u; index < length; ++index) append(static_cast<std::uint8_t>(bits.read(8u)));
                continue;
            }
            if (kind == 3u) throw std::runtime_error("Invalid UI deflate block");
            std::array<std::uint8_t, 288> literal_lengths{};
            std::array<std::uint8_t, 32> distance_lengths{};
            if (kind == 1u) {
                for (unsigned index = 0u; index < literal_lengths.size(); ++index) literal_lengths[index] = static_cast<std::uint8_t>(index < 144u ? 8u : index < 256u ? 9u : index < 280u ? 7u : 8u);
                distance_lengths.fill(5u);
            } else {
                const auto literals = bits.read(5u) + 257u, distances = bits.read(5u) + 1u, codes = bits.read(4u) + 4u;
                if (literals > 286u) throw std::runtime_error("Invalid UI literal alphabet");
                constexpr unsigned order[] = {16u, 17u, 18u, 0u, 8u, 7u, 9u, 6u, 10u, 5u, 11u, 4u, 12u, 3u, 13u, 2u, 14u, 1u, 15u};
                std::array<std::uint8_t, 19> code_lengths{};
                for (unsigned index = 0u; index < codes; ++index) code_lengths[order[index]] = static_cast<std::uint8_t>(bits.read(3u));
                UiDeflateAlphabet alphabet{code_lengths, true};
                std::vector<std::uint8_t> lengths;
                lengths.reserve(literals + distances);
                while (lengths.size() < literals + distances) {
                    const auto code = alphabet.decode(bits);
                    if (code < 16u) lengths.push_back(static_cast<std::uint8_t>(code));
                    else {
                        if (code == 16u && lengths.empty()) throw std::runtime_error("UI Huffman repeat without predecessor");
                        const auto count = code == 16u ? bits.read(2u) + 3u : code == 17u ? bits.read(3u) + 3u : bits.read(7u) + 11u;
                        if (count > literals + distances - lengths.size()) throw std::runtime_error("UI Huffman repeat overflow");
                        lengths.insert(lengths.end(), count, code == 16u ? lengths.back() : 0u);
                    }
                }
                std::copy_n(lengths.begin(), literals, literal_lengths.begin());
                std::copy_n(lengths.begin() + literals, distances, distance_lengths.begin());
            }
            if (literal_lengths[256] == 0u) throw std::runtime_error("UI deflate block has no terminator");
            UiDeflateAlphabet literals{literal_lengths}, distances{distance_lengths};
            constexpr unsigned length_base[] = {3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 13u, 15u, 17u, 19u, 23u, 27u, 31u, 35u, 43u, 51u, 59u, 67u, 83u, 99u, 115u, 131u, 163u, 195u, 227u, 258u};
            constexpr unsigned distance_base[] = {1u, 2u, 3u, 4u, 5u, 7u, 9u, 13u, 17u, 25u, 33u, 49u, 65u, 97u, 129u, 193u, 257u, 385u, 513u, 769u, 1025u, 1537u, 2049u, 3073u, 4097u, 6145u, 8193u, 12289u, 16385u, 24577u};
            for (;;) {
                const auto symbol = literals.decode(bits);
                if (symbol == 256u) break;
                if (symbol < 256u) {
                    append(static_cast<std::uint8_t>(symbol));
                    continue;
                }
                if (symbol > 285u) throw std::runtime_error("Invalid UI length symbol");
                const auto slot = symbol - 257u, length = length_base[slot] + bits.read(slot < 8u || slot == 28u ? 0u : (slot - 4u) / 4u);
                const auto distance_symbol = distances.decode(bits);
                if (distance_symbol >= 30u) throw std::runtime_error("Invalid UI distance symbol");
                const auto distance = distance_base[distance_symbol] + bits.read(distance_symbol < 4u ? 0u : distance_symbol / 2u - 1u);
                if (distance > output.size()) throw std::runtime_error("UI deflate distance before buffer");
                for (unsigned index = 0u; index < length; ++index) append(output[output.size() - distance]);
            }
        } while (!last);
        bits.align();
        std::uint32_t checksum = 0u;
        for (unsigned index = 0u; index < 4u; ++index) checksum = (checksum << 8u) | bits.read(8u);
        std::uint32_t first = 1u, second = 0u;
        for (const auto value : output) {
            first = (first + value) % 65521u;
            second = (second + first) % 65521u;
        }
        if (checksum != ((second << 16u) | first)) throw std::runtime_error("UI configuration checksum mismatch");
        return output;
    }

    std::string_view uiConfigText() {
        const auto& config = g_sfera_config_text_runtime;
        return config.text_buffer == nullptr ? std::string_view{} : std::string_view(config.text_buffer, std::min<std::size_t>(config.text_length, sizeof(config.owned_text) - 1u));
    }

    std::size_t uiConfigValueOffset(std::string_view text, std::string_view key) {
        for (std::size_t line = 0u; line < text.size();) {
            const auto token_end = text.find_first_of(" \t\r\0", line, 4u);
            const auto end = token_end == std::string_view::npos ? text.size() : token_end;
            if (text.substr(line, end - line) == key) {
                const auto value = text.find_first_not_of(" \t", end);
                return value == std::string_view::npos ? text.size() : value;
            }
            const auto newline = text.find('\n', end);
            if (newline == std::string_view::npos) break;
            line = newline + 1u;
        }
        return std::string_view::npos;
    }

    void uiStoreConfigText(std::string_view text) {
        auto& config = g_sfera_config_text_runtime;
        if (text.size() >= sizeof(config.owned_text)) throw std::length_error("UI configuration too large");
        if (!text.empty()) std::memmove(config.owned_text, text.data(), text.size());
        config.owned_text[text.size()] = 0u;
        config.text_buffer = config.text_storage;
        config.text_length = static_cast<std::uint32_t>(text.size());
    }
}


const char* SphereUI::InterfaceConfiguration::value(const char* key) {
    if (key == nullptr) return nullptr;
    const auto text = uiConfigText();
    const auto offset = uiConfigValueOffset(text, key);
    return offset == std::string_view::npos ? nullptr : text.data() + offset;
}

void SphereUI::InterfaceConfiguration::open(const char* filename) {
    auto& config = g_sfera_config_text_runtime;
    detail::copyText(config.parser_path, filename);
    uiStoreConfigText("");
    std::ifstream stream(config.parser_path, std::ios::binary);
    if (!stream) return;
    stream.read(config.text_storage, sizeof(config.owned_text) - 1u);
    config.text_length = static_cast<std::uint32_t>(stream.gcount());
    config.owned_text[config.text_length] = 0u;
    if (config.text_length < 14u || std::memcmp(config.owned_text, "SPHR", 4u) != 0) return;
    try {
        const auto key = config.owned_text[8];
        for (const auto offset : {9u, 17u, 20u}) if (offset < config.text_length) config.owned_text[offset] ^= key;
        const auto decoded = uiInflateConfig(std::span<const std::uint8_t>(config.owned_text + 8u, config.text_length - 8u), sizeof(config.owned_text) - 1u);
        uiStoreConfigText(std::string_view(reinterpret_cast<const char*>(decoded.data()), decoded.size()));
    } catch (const std::runtime_error&) {
        uiStoreConfigText("");
        config.parser_path[0] = '\0';
    } catch (const std::length_error&) {
        uiStoreConfigText("");
        config.parser_path[0] = '\0';
    }
}

void SphereUI::InterfaceConfiguration::readInteger(const char* key, std::uint32_t& value) {
    const auto* text = InterfaceConfiguration::value(key);
    if (text == nullptr) return;
    std::int32_t parsed = 0;
    if (::sscanf_s(text, "%d", &parsed) == 1) value = static_cast<std::uint32_t>(parsed);
}

void SphereUI::InterfaceConfiguration::writeInteger(const char* key, std::uint32_t value) {
    if (key == nullptr) return;
    std::string text(uiConfigText());
    const auto offset = uiConfigValueOffset(text, key);
    const auto number = std::to_string(static_cast<std::int32_t>(value));
    if (offset == std::string_view::npos) {
        if (!text.empty()) text += "\r\n";
        text += key;
        text += '\t';
        text += number;
    } else {
        const bool quoted = offset < text.size() && text[offset] == '"';
        const auto begin = offset + (quoted ? 1u : 0u);
        const auto end = text.find_first_of(quoted ? "\"\r\0" : "\r\0", begin, quoted ? 3u : 2u);
        text.replace(begin, (end == std::string::npos ? text.size() : end) - begin, number);
    }
    uiStoreConfigText(text);
}

void SphereUI::InterfaceConfiguration::save() {
    auto& config = g_sfera_config_text_runtime;
    if (config.parser_path[0] == '\0') return;
    ::_chmod(config.parser_path, _S_IREAD | _S_IWRITE);
    std::ofstream stream(config.parser_path, std::ios::binary | std::ios::trunc);
    const auto text = uiConfigText();
    if (stream) stream.write(text.data(), text.size());
}

namespace {
    std::uint8_t uiAtlasGlyph(std::uint8_t character) {
        return g_sfera_font_runtime.glyphs[character].defined != 0u ? character : static_cast<std::uint8_t>('|');
    }

    void uiFontQuad(SferaScreenVertex* vertices, float left, float top, float right, float bottom, std::uint32_t color, float u0, float v0, float u1, float v1, bool clockwise) {
        for (std::uint32_t index = 0u; index < 4u; ++index) {
            const auto corner = clockwise || index < 2u ? index : 5u - index;
            const bool on_right = corner == 1u || corner == 2u, on_bottom = corner >= 2u;
            vertices[index] = {on_right ? right : left, on_bottom ? bottom : top, 0.0f, 1.0f, color, clockwise ? vertices[index].specular : 0u, on_right ? u1 : u0, on_bottom ? v1 : v0};
        }
    }

    void uiFontTriangles(std::uint16_t* indices, std::uint32_t first, bool clockwise) {
        constexpr std::uint16_t atlas[] = {0u, 1u, 2u, 0u, 2u, 3u};
        constexpr std::uint16_t face[] = {2u, 0u, 3u, 1u, 3u, 0u};
        const auto* order = clockwise ? atlas : face;
        for (std::uint32_t index = 0u; index < 6u; ++index) indices[index] = static_cast<std::uint16_t>(first + order[index]);
    }

    void uiSubmitFont(const SferaScreenVertex* vertices, std::uint32_t vertex_count, const std::uint16_t* indices, std::uint32_t index_count) {
        if (vertex_count == 0u) return;
        if (auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device)) (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0u, vertex_count, index_count / 3u, indices, D3DFMT_INDEX16, vertices, sizeof(SferaScreenVertex)));
    }

    void uiDrawAtlasText(const char* text, std::int32_t x, std::int32_t y, std::uint32_t color, std::uint32_t font, bool initialized, const SphereUI::UiRect& clip) {
        auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device);
        if (device == nullptr) return;
        const auto top = SphereUI::detail::subtractCoordinate(SphereUI::detail::subtractCoordinate(y, 2), static_cast<std::int32_t>(g_sfera_font_atlas_layout_runtime.origin[font]));
        const auto size = initialized ? 30 : 0;
        if (top > clip.bottom || SphereUI::detail::addCoordinate(top, size) <= clip.top) return;
        IDirect3DBaseTexture9* texture = nullptr;
        std::uint32_t vertex_count = 0u, index_count = 0u;
        const auto flush = [&]() {
            if (vertex_count == 0u) return;
            (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, texture));
            (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE));
            (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1));
            (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetRenderState(D3DRS_LIGHTING, FALSE));
            (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetRenderState(D3DRS_CLIPPING, FALSE));
            uiSubmitFont(g_sfera_landscape_screen_vertices, vertex_count, g_sfera_screen_quad_indices, index_count);
            vertex_count = 0u;
            index_count = 0u;
        };
        for (const auto* cursor = reinterpret_cast<const unsigned char*>(text); *cursor != 0u && *cursor != '\n'; ++cursor) {
            const auto character = uiAtlasGlyph(*cursor);
            if (x <= clip.right && SphereUI::detail::addCoordinate(x, size) > clip.left) {
                const auto& glyph = g_sfera_font_runtime.glyphs[character];
                const auto next_texture = g_sfera_static_render_lookup_runtime.atlas_textures[glyph.texture_index][font];
                if ((texture != nullptr && texture != next_texture) || vertex_count + 4u > std::size(g_sfera_landscape_screen_vertices)) flush();
                texture = next_texture;
                const auto left = static_cast<float>(x) - 0.5f, upper = static_cast<float>(top) - 0.5f;
                uiFontQuad(g_sfera_landscape_screen_vertices + vertex_count, left, upper, left + size, upper + size, color, glyph.u, glyph.v, glyph.u + 30.0f / 256.0f, glyph.v + 30.0f / 256.0f, true);
                uiFontTriangles(g_sfera_screen_quad_indices + index_count, vertex_count, true);
                vertex_count += 4u;
                index_count += 6u;
            }
            if (initialized) x = SphereUI::detail::addCoordinate(x, static_cast<std::int32_t>(g_sfera_static_render_lookup_runtime.glyph_metrics[character][font] + g_sfera_font_atlas_layout_runtime.code_base[font]));
        }
        flush();
        (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE));
    }
}


void SphereUI::InterfaceRenderer::drawFaceText(const char* text, std::int32_t x, std::int32_t y, std::uint32_t color, std::uint32_t font, const SphereUI::UiRect& clip) {
    const auto& face = g_sfera_fonts.face(font);
    if (y > clip.bottom || SphereUI::detail::addCoordinate(y, face.line_height) <= clip.top || (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device) == nullptr) return;
    auto* texture = g_sfera_textures.resource(face.texture);
    if (auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device)) (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, texture));
    const auto* glyphs = face.glyphs.data();
    auto& factory = g_sfera_fonts;
    auto* vertices = factory.vertices.data();
    if (factory.vertices.empty()) throw std::runtime_error("font vertex buffer is unavailable");
    if (factory.vertex_count >= 1200u) factory.vertex_count = 0u;
    std::uint32_t batch_first = factory.vertex_count, batch_count = 0u, index_count = 0u;
    const float origin = static_cast<float>(x) - 0.5f;
    float left = origin, top = static_cast<float>(y) - 0.5f;
    const auto flush = [&]() {
        uiSubmitFont(vertices + batch_first, batch_count, factory.quad_indices.data(), index_count);
        batch_count = 0u;
        index_count = 0u;
        batch_first = factory.vertex_count;
    };
    for (const auto* cursor = reinterpret_cast<const unsigned char*>(text); *cursor != 0u; ++cursor) {
        const auto character = *cursor;
        if (character == '\n') {
            left = origin;
            top += face.line_height;
            continue;
        }
        if (character < 32u) continue;
        const auto& glyph = glyphs[character];
        if (character == ' ' || left + glyph.width <= static_cast<float>(clip.left)) {
            left += glyph.advance;
            continue;
        }
        if (left > static_cast<float>(clip.right)) break;
        const auto glyph_left = left + glyph.bearing_x, glyph_top = top - glyph.bearing_y;
        uiFontQuad(vertices + factory.vertex_count, glyph_left, glyph_top, glyph_left + glyph.width, glyph_top + glyph.height, color, glyph.u0, glyph.v0, glyph.u1, glyph.v1, false);
        uiFontTriangles(factory.quad_indices.data() + index_count, batch_count, false);
        factory.vertex_count += 4u;
        batch_count += 4u;
        index_count += 6u;
        if (factory.vertex_count > 1194u) {
            flush();
            factory.vertex_count = 0u;
            batch_first = 0u;
        }
        left += glyph.advance;
    }
    flush();
}

SphereUI::TextExtent SphereUI::InterfaceRenderer::measureText(const char* text, std::uint32_t font, bool initialized) {
    const auto* cursor = reinterpret_cast<const unsigned char*>(text == nullptr ? "" : text);
    std::uint32_t width = 0u, line_width = 0u, extra_height = 0u;
    if (font >= 2u) {
        const auto& face = g_sfera_fonts.face(font);
        const auto* glyphs = face.glyphs.data();
        for (; *cursor != 0u; ++cursor) {
            if (*cursor == '\n') {
                width = std::max(width, line_width);
                line_width = 0u;
                extra_height += static_cast<std::uint32_t>(face.line_height);
            } else {
                constexpr std::uint8_t lowercase_yo = 184u, lowercase_e = 229u, uppercase_yo = 168u, uppercase_e = 197u;
                const auto character = *cursor == lowercase_yo ? lowercase_e : *cursor == uppercase_yo ? uppercase_e : *cursor;
                line_width += static_cast<std::uint32_t>(glyphs[character].advance);
            }
        }
        return {static_cast<std::int32_t>(std::max(width, line_width)), static_cast<std::int32_t>(extra_height + static_cast<std::uint32_t>(face.line_height))};
    }
    std::uint32_t lines = 1u;
    const auto& layout = g_sfera_font_atlas_layout_runtime;
    for (; *cursor != 0u; ++cursor) {
        if (*cursor == '\n') {
            const auto completed_width = initialized ? line_width : 0u;
            if (static_cast<std::int32_t>(completed_width) > static_cast<std::int32_t>(width)) width = completed_width;
            if (++lines == 300u) throw std::length_error("too many lines in font measurement");
            line_width = 0u;
        } else {
            if (static_cast<std::int32_t>(line_width) > 0) line_width += layout.code_base[font];
            line_width += g_sfera_static_render_lookup_runtime.glyph_metrics[uiAtlasGlyph(*cursor)][font];
        }
    }
    if (static_cast<std::int32_t>(line_width) > static_cast<std::int32_t>(width)) width = line_width;
    const auto height = initialized ? (lines - 1u) * layout.cell_step[font] - layout.origin[font] + layout.span[font] + 2u : 0u;
    return {static_cast<std::int32_t>(width + 2u), static_cast<std::int32_t>(height + (font == 1u ? 2u : 0u))};
}

void SphereUI::InterfaceRenderer::drawText(const char* text, std::int32_t x, std::int32_t y, std::uint32_t color, std::uint32_t font, bool initialized, const UiRect& clip, bool opaque) {
    g_sfera_screen_clip_runtime.left = clip.left;
    g_sfera_screen_clip_runtime.top = clip.top;
    g_sfera_screen_clip_runtime.right = clip.right;
    g_sfera_screen_clip_runtime.bottom = clip.bottom;
    const bool disable_blending = opaque && font < 2u;
    if (disable_blending) SphereUI::InterfaceRenderer::setSpriteRenderMode(0u);
    if (font < 2u) uiDrawAtlasText(text == nullptr ? "" : text, x, y, color, font, initialized, clip);
    else drawFaceText(text == nullptr ? "" : text, x, y, color, font, clip);
    if (disable_blending) SphereUI::InterfaceRenderer::setSpriteRenderMode(1u);
}

SferaVec3F SferaVec3F::operator+(const SferaVec3F& other) const { return {static_cast<float>(double(x) + other.x), static_cast<float>(double(y) + other.y), static_cast<float>(double(z) + other.z)}; }
SferaVec3F SferaVec3F::operator-(const SferaVec3F& other) const { return {static_cast<float>(double(x) - other.x), static_cast<float>(double(y) - other.y), static_cast<float>(double(z) - other.z)}; }
SferaVec3F SferaVec3F::operator*(float factor) const { return {static_cast<float>(double(x) * factor), static_cast<float>(double(y) * factor), static_cast<float>(double(z) * factor)}; }
double SferaVec3F::dot(const SferaVec3F& other) const { return double(x) * other.x + double(y) * other.y + double(z) * other.z; }
SferaVec3F SferaVec3F::cross(const SferaVec3F& other) const { return {static_cast<float>(double(y) * other.z - double(z) * other.y), static_cast<float>(double(z) * other.x - double(x) * other.z), static_cast<float>(double(x) * other.y - double(y) * other.x)}; }
float SferaVec3F::component(std::size_t axis) const { return axis == 0 ? x : axis == 1 ? y : z; }
void SferaVec3F::setComponent(std::size_t axis, float value) { if (axis == 0) x = value; else if (axis == 1) y = value; else z = value; }

void SferaVec3F::rotatePair(float& first, float& second, float angle) {
    const float cosine = static_cast<float>(std::cos(double(angle)));
    const float sine = static_cast<float>(std::sin(double(angle)));
    const float rotatedFirst = static_cast<float>(double(first) * cosine - double(second) * sine);
    second = static_cast<float>(double(first) * sine + double(second) * cosine);
    first = rotatedFirst;
}

SferaMatrix3x3F SferaQuaternionF::rotationMatrix() const {
    const float xx = static_cast<float>(2.0 * x * x), xy = static_cast<float>(2.0 * x * y), xz = static_cast<float>(2.0 * x * z);
    const float yy = static_cast<float>(2.0 * y * y), yz = static_cast<float>(2.0 * y * z), zz = static_cast<float>(2.0 * z * z);
    const float wx = static_cast<float>(2.0 * w * x), wy = static_cast<float>(2.0 * w * y), wz = static_cast<float>(2.0 * w * z);
    SferaMatrix3x3F result{};
    result.m[0][0] = static_cast<float>(1.0 - yy - zz);
    result.m[0][1] = static_cast<float>(double(xy) - wz);
    result.m[0][2] = static_cast<float>(double(wy) + xz);
    result.m[1][0] = static_cast<float>(double(xy) + wz);
    result.m[1][1] = static_cast<float>(1.0 - xx - zz);
    result.m[1][2] = static_cast<float>(double(yz) - wx);
    result.m[2][0] = static_cast<float>(double(xz) - wy);
    result.m[2][1] = static_cast<float>(double(wx) + yz);
    result.m[2][2] = static_cast<float>(1.0 - xx - yy);
    return result;
}

SferaQuaternionF SferaQuaternionF::interpolated(const SferaQuaternionF& other, float factor) const {
    const float cosine = static_cast<float>(double(x) * other.x + double(y) * other.y + double(z) * other.z + double(w) * other.w);
    SferaQuaternionF target = other;
    float firstWeight;
    float secondWeight;
    if (!(1.0 + cosine > 0.00001)) {
        target = {z, -y, x, -w};
        firstWeight = static_cast<float>(std::sin((1.0 - factor) * 1.5707965));
        secondWeight = static_cast<float>(std::sin(double(factor) * 1.5707965));
    } else if (1.0 - cosine > double(0.00001f)) {
        const float angle = static_cast<float>(std::acos(double(cosine)));
        const float sine = static_cast<float>(std::sin(double(angle)));
        firstWeight = static_cast<float>(std::sin((1.0 - factor) * angle) / sine);
        const float secondAngle = static_cast<float>(double(angle) * factor);
        const float secondSine = static_cast<float>(std::sin(double(secondAngle)));
        secondWeight = static_cast<float>(double(secondSine) / sine);
    } else {
        firstWeight = static_cast<float>(1.0 - factor);
        secondWeight = factor;
    }
    return {static_cast<float>(double(w) * firstWeight + double(target.w) * secondWeight), static_cast<float>(double(x) * firstWeight + double(target.x) * secondWeight), static_cast<float>(double(y) * firstWeight + double(target.y) * secondWeight), static_cast<float>(double(z) * firstWeight + double(target.z) * secondWeight)};
}

SferaMatrix4x4F SferaMatrix4x4F::identity() {
    SferaMatrix4x4F result{};
    for (std::size_t axis = 0; axis < 4; ++axis) result.m[axis][axis] = 1.0f;
    return result;
}

SferaMatrix4x4F SferaMatrix4x4F::fromEuler(const SferaVec3F& translation, const SferaVec3F& angles) {
    const double cx = static_cast<float>(std::cos(double(angles.x))), sx = static_cast<float>(std::sin(double(angles.x)));
    const double cy = static_cast<float>(std::cos(double(angles.y))), sy = static_cast<float>(std::sin(double(angles.y)));
    const double cz = static_cast<float>(std::cos(double(angles.z))), sz = static_cast<float>(std::sin(double(angles.z)));
    SferaMatrix4x4F result = identity();
    result.m[0][0] = static_cast<float>(cz * cx - sy * sx * sz);
    result.m[0][1] = static_cast<float>(-sz * cy);
    result.m[0][2] = static_cast<float>(-sx * cz - sy * cx * sz);
    result.m[1][0] = static_cast<float>(sz * cx + cz * sy * sx);
    result.m[1][1] = static_cast<float>(cz * cy);
    result.m[1][2] = static_cast<float>(cz * sy * cx - sz * sx);
    result.m[2][0] = static_cast<float>(cy * sx);
    result.m[2][1] = static_cast<float>(-sy);
    result.m[2][2] = static_cast<float>(cy * cx);
    result.m[0][3] = translation.x;
    result.m[1][3] = translation.y;
    result.m[2][3] = translation.z;
    return result;
}

SferaMatrix4x4F SferaMatrix4x4F::fromQuaternion(const SferaQuaternionF& rotation, const SferaVec3F& translation) {
    SferaMatrix4x4F result = identity();
    const auto basis = rotation.rotationMatrix();
    for (std::size_t row = 0; row < 3; ++row) for (std::size_t column = 0; column < 3; ++column) result.m[row][column] = basis.m[row][column];
    result.m[0][3] = translation.x;
    result.m[1][3] = translation.y;
    result.m[2][3] = translation.z;
    return result;
}

SferaVec3F SferaMatrix4x4F::transformPoint(const SferaVec3F& point) const {
    SferaVec3F result;
    for (std::size_t row = 0; row < 3; ++row) result.setComponent(row, static_cast<float>(double(m[row][0]) * point.x + double(m[row][1]) * point.y + double(m[row][2]) * point.z + m[row][3]));
    return result;
}

SferaVec3F SferaMatrix4x4F::inverseTransformPoint(const SferaVec3F& point) const {
    const SferaVec3F relative = point - SferaVec3F{m[0][3], m[1][3], m[2][3]};
    SferaVec3F result;
    for (std::size_t column = 0; column < 3; ++column) result.setComponent(column, static_cast<float>(double(m[0][column]) * relative.x + double(m[1][column]) * relative.y + double(m[2][column]) * relative.z));
    return result;
}

SferaMatrix4x4F SferaMatrix4x4F::multiplied(const SferaMatrix4x4F& other) const {
    SferaMatrix4x4F result{};
    for (std::size_t row = 0; row < 4; ++row) {
        for (std::size_t column = 0; column < 4; ++column) {
            double value = 0.0;
            for (std::size_t axis = 0; axis < 4; ++axis) value += double(m[row][axis]) * other.m[axis][column];
            result.m[row][column] = static_cast<float>(value);
        }
    }
    return result;
}

SferaMatrix4x4F SferaMatrix4x4F::transposed() const {
    SferaMatrix4x4F result;
    for (std::size_t row = 0; row < 4; ++row) for (std::size_t column = 0; column < 4; ++column) result.m[row][column] = m[column][row];
    return result;
}

void SferaMatrix4x4F::scaleAxes(const SferaVec3F& scale) {
    for (std::size_t row = 0; row < 3; ++row) for (std::size_t column = 0; column < 3; ++column) m[row][column] = static_cast<float>(double(m[row][column]) * scale.component(row));
}

SferaBoundsCornersRuntime SferaBoundsCornersRuntime::fromExtents(const SferaVec3F& minimum, const SferaVec3F& maximum) {
    return {{{minimum.x, minimum.y, minimum.z}, {maximum.x, minimum.y, minimum.z}, {maximum.x, maximum.y, minimum.z}, {minimum.x, maximum.y, minimum.z}, {minimum.x, maximum.y, maximum.z}, {minimum.x, minimum.y, maximum.z}, {maximum.x, minimum.y, maximum.z}, {maximum.x, maximum.y, maximum.z}}};
}

void SferaBoundsCornersRuntime::getExtents(SferaVec3F& minimum, SferaVec3F& maximum) const {
    minimum = maximum = corners[0];
    for (std::size_t index = 1; index < 8; ++index) {
        for (std::size_t axis = 0; axis < 3; ++axis) {
            const float coordinate = corners[index].component(axis);
            if (coordinate < minimum.component(axis)) minimum.setComponent(axis, coordinate);
            else if (coordinate > maximum.component(axis)) maximum.setComponent(axis, coordinate);
        }
    }
}

double SferaPlaneF::evaluate(const SferaVec3F& point) const { return normal.dot(point) + distance; }

int SferaPlaneF::intersectLine(const SferaVec3F& start, const SferaVec3F& end, SferaVec3F& intersection) const {
    const SferaVec3F direction = end - start;
    const float denominator = static_cast<float>(normal.dot(direction));
    if (std::abs(denominator) <= std::numeric_limits<float>::min()) return 0;
    const float startProjection = static_cast<float>(normal.dot(start));
    const float startDistance = static_cast<float>(double(startProjection) + distance);
    const float parameter = static_cast<float>(double(startDistance) / denominator);
    for (std::size_t axis = 0; axis < 3; ++axis) intersection.setComponent(axis, static_cast<float>(double(start.component(axis)) - double(direction.component(axis)) * parameter));
    return (startDistance < 0.0f ? -2 : 1) + (denominator > 0.0f ? 1 : 0);
}

bool SferaVec3F::containsConvexPolygonPoint(std::span<const SferaVec3F* const> vertices, const SferaVec3F& point) const {
    if (vertices.empty()) return true;
    std::size_t dominant = std::abs(y) > std::abs(x) ? 1 : 0;
    if (std::abs(z) > std::abs(component(dominant))) dominant = 2;
    const std::size_t first = (dominant + 1) % 3;
    const std::size_t second = (dominant + 2) % 3;
    const SferaVec3F* previous = vertices.back();
    for (const SferaVec3F* current : vertices) {
        const double side = (double(previous->component(second)) - current->component(second)) * (double(point.component(first)) - previous->component(first)) + (double(current->component(first)) - previous->component(first)) * (double(point.component(second)) - previous->component(second));
        if (side * component(dominant) < 0.0) return false;
        previous = current;
    }
    return true;
}

int SferaFrustumF::classifyPoints(std::span<const SferaVec3F> points) const {
    bool intersects = false;
    for (const auto& plane : planes) {
        std::size_t outside = 0;
        for (const auto& point : points) if (plane.evaluate(point) < 0.0) ++outside;
        if (outside == points.size()) return 0;
        intersects = intersects || outside != 0;
    }
    return intersects ? 1 : 2;
}

void SferaPolygon3F::clipToAxis(std::size_t axis, float boundary, bool keepGreater) {
    if (vertices.empty()) return;
    std::vector<SferaVec3F> clipped;
    clipped.reserve(vertices.size() + 1);
    SferaVec3F previous = vertices.back();
    bool previousInside = keepGreater ? previous.component(axis) >= boundary : previous.component(axis) <= boundary;
    for (const auto& current : vertices) {
        const bool currentInside = keepGreater ? current.component(axis) >= boundary : current.component(axis) <= boundary;
        if (previousInside != currentInside) {
            const float factor = std::clamp(static_cast<float>((double(boundary) - previous.component(axis)) / (double(current.component(axis)) - previous.component(axis))), 0.0f, 1.0f);
            SferaVec3F intersection;
            for (std::size_t coordinate = 0; coordinate < 3; ++coordinate) intersection.setComponent(coordinate, static_cast<float>((double(current.component(coordinate)) - previous.component(coordinate)) * factor + previous.component(coordinate)));
            intersection.setComponent(axis, boundary);
            clipped.push_back(intersection);
        }
        if (currentInside) clipped.push_back(current);
        previous = current;
        previousInside = currentInside;
    }
    vertices = std::move(clipped);
}

bool SferaPolygon3F::clipTriangleToBounds(const SferaVec3F& first, const SferaVec3F& second, const SferaVec3F& third, const SferaVec3F& minimum, const SferaVec3F& maximum) {
    vertices = {first, second, third};
    for (std::size_t axis = 0; axis < 3 && !vertices.empty(); ++axis) {
        clipToAxis(axis, minimum.component(axis), true);
        clipToAxis(axis, maximum.component(axis), false);
    }
    return !vertices.empty();
}

SferaViewProjectionScratchRuntime SferaViewProjectionScratchRuntime::translated(const SferaVec3F& offset) const {
    SferaViewProjectionScratchRuntime result;
    for (std::size_t index = 0; index < 8; ++index) result.corners[index] = corners[index] + offset;
    const auto fixedX = static_cast<std::uint32_t>(static_cast<std::int64_t>(std::nearbyint(static_cast<float>(double(offset.x) * 1024.0))));
    const auto fixedY = static_cast<std::uint32_t>(static_cast<std::int64_t>(std::nearbyint(static_cast<float>(double(offset.y) * 1024.0))));
    const auto fixedZ = static_cast<std::uint32_t>(static_cast<std::int64_t>(std::nearbyint(static_cast<float>(double(offset.z) * 1024.0))));
    result.clipping_bounds = {clipping_bounds.min_x + fixedX, clipping_bounds.max_x + fixedX, clipping_bounds.min_y + fixedY, clipping_bounds.max_y + fixedY, clipping_bounds.min_z + fixedZ, clipping_bounds.max_z + fixedZ};
    return result;
}


std::vector<std::uint8_t> SferaFileManager::readAll(const char* filename) {
    const int descriptor = open(filename, 0);
    if (descriptor < 0) throw std::runtime_error(std::string("Unable to open file: ") + filename);
    try {
        const auto length = seek(descriptor, 0, SEEK_END);
        if (length < 0 || seek(descriptor, 0, SEEK_SET) != 0) throw std::runtime_error(std::string("Unable to measure file: ") + filename);
        std::vector<std::uint8_t> bytes(static_cast<std::size_t>(length));
        if (length != 0 && read(descriptor, bytes.data(), static_cast<std::uint32_t>(length)) != length) throw std::runtime_error(std::string("Incomplete file read: ") + filename);
        close(descriptor);
        return bytes;
    } catch (...) {
        close(descriptor);
        throw;
    }
}

SphereRender::ConfigDocument::StorageMode SphereRender::ConfigDocument::storage_mode_ = StorageMode::Plain;

class SphereRender::ConfigDocument::Parser {
public:
    explicit Parser(std::string_view source) : source_(source) {}
    ConfigDocument document(bool nested = false) {
        ConfigDocument result;
        while (skipSpace()) {
            if (peek() == '}') {
                if (!nested) fail(36);
                ++position_;
                return result;
            }
            Value value;
            value.name = identifier();
            if (result.find(value.name) != nullptr) throw std::runtime_error("openCfg: duplicate name: " + value.name);
            require('<', 5);
            const bool array = peek() == 'a' || peek() == 'A';
            if (array) ++position_;
            const char type = peek();
            if (type != '\0') ++position_;
            require('>', 8, false);
            require('=', 10);
            if (!skipSpace()) fail(11);
            switch (type) {
            case 'i': case 'I':
                value.type = array ? Type::IntegerArray : Type::Integer;
                if (array) {
                    std::vector<std::int32_t> items;
                    do { items.push_back(integer()); } while (separator());
                    value.data = std::move(items);
                } else value.data = integer();
                break;
            case 'f': case 'F':
                value.type = array ? Type::FloatArray : Type::Float;
                if (array) {
                    std::vector<float> items;
                    do { items.push_back(real()); } while (separator());
                    value.data = std::move(items);
                } else value.data = real();
                break;
            case 't': case 'T':
                value.type = array ? Type::TextArray : Type::Text;
                if (array) {
                    std::vector<std::string> items;
                    do { items.push_back(text()); } while (separator());
                    value.data = std::move(items);
                } else value.data = text();
                break;
            case 'u': case 'U':
                if (array) fail(7);
                value.type = Type::Binary;
                value.data = binary();
                break;
            case 's': case 'S': {
                value.type = array ? Type::ObjectArray : Type::Object;
                std::vector<ConfigDocument> items;
                do {
                    require('{', array ? 35 : 33);
                    items.push_back(document(true));
                } while (array && separator());
                value.data = std::move(items);
                break;
            }
            default: fail(6);
            }
            result.values_.push_back(std::move(value));
        }
        if (nested) fail(1);
        return result;
    }
private:
    char peek() const { return position_ < source_.size() ? source_[position_] : '\0'; }
    bool skipSpace() {
        while (position_ < source_.size()) {
            if (source_[position_] == '\0') return false;
            if (source_[position_] == '/' && position_ + 1 < source_.size() && source_[position_ + 1] == '/') {
                position_ += 2;
                while (position_ < source_.size() && source_[position_] != '\n' && source_[position_] != '\0') ++position_;
                continue;
            }
            if (source_[position_] == '\n') ++line_;
            else if (source_[position_] != ' ' && source_[position_] != '\r') return true;
            ++position_;
        }
        return false;
    }
    void require(char character, int error, bool skip = true) {
        if (skip) skipSpace();
        if (peek() != character) fail(error);
        ++position_;
    }
    bool separator() {
        skipSpace();
        if (peek() != ',') return false;
        ++position_;
        if (!skipSpace()) fail(17);
        return true;
    }
    std::string identifier() {
        const auto letter = [](char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_'; };
        if (!letter(peek())) fail(2);
        const auto begin = position_++;
        while (letter(peek()) || (peek() >= '0' && peek() <= '9')) ++position_;
        if (position_ - begin > 250) fail(3);
        return std::string(source_.substr(begin, position_ - begin));
    }
    std::int32_t integer() {
        const auto begin = position_;
        if (peek() == '-') ++position_;
        const auto digits = position_;
        while (peek() >= '0' && peek() <= '9') ++position_;
        if (digits == position_) fail(13);
        std::int32_t value = 0;
        const auto parsed = std::from_chars(source_.data() + begin, source_.data() + position_, value);
        if (parsed.ec != std::errc{}) fail(14);
        return value;
    }
    float real() {
        const auto begin = position_;
        if (peek() == '-') ++position_;
        while ((peek() >= '0' && peek() <= '9') || peek() == '.') ++position_;
        float value = 0.0f;
        const auto parsed = std::from_chars(source_.data() + begin, source_.data() + position_, value);
        if (parsed.ec != std::errc{} || parsed.ptr != source_.data() + position_) fail(18);
        return value;
    }
    std::string text() {
        require('"', 23);
        const auto begin = position_;
        while (peek() != '"') {
            if (peek() == '\0') fail(24);
            ++position_;
        }
        std::string value(source_.substr(begin, position_ - begin));
        ++position_;
        return value;
    }
    std::vector<std::uint8_t> binary() {
        if (peek() < '0' || peek() > '9') fail(28);
        const auto length = static_cast<std::size_t>(integer());
        require(':', 30, false);
        if (!skipSpace() && length != 0) fail(31);
        const auto encoded_length = (length / 7) * 8 + ((length % 7) * 8 + 6) / 7;
        if (encoded_length > source_.size() - position_) fail(39);
        const auto encoded = source_.substr(position_, encoded_length);
        std::vector<std::uint8_t> bytes(length);
        for (std::size_t index = 0; index < length; ++index) {
            const auto first = index + index / 7;
            const auto shift = static_cast<unsigned>(index % 7);
            if (encoded[first] == '\0' || encoded[first + 1] == '\0') fail(39);
            const auto low = static_cast<unsigned char>(encoded[first]) - static_cast<unsigned>('0');
            const auto high = static_cast<unsigned char>(encoded[first + 1]) - static_cast<unsigned>('0');
            bytes[index] = static_cast<std::uint8_t>((low >> shift) | (high << (7 - shift)));
        }
        position_ += encoded_length;
        return bytes;
    }
    [[noreturn]] void fail(int code) const { throw std::runtime_error("parse_error: " + std::to_string(code) + ". Line " + std::to_string(line_)); }
    std::string_view source_;
    std::size_t position_ = 0;
    std::size_t line_ = 1;
};

SphereRender::ConfigDocument SphereRender::ConfigDocument::parse(std::string_view source) { return Parser(source).document(); }

SphereRender::ConfigDocument SphereRender::ConfigDocument::open(const char* path) {
    try {
        auto bytes = g_sfera_files.readAll(path);
        if (bytes.empty()) throw std::runtime_error(std::string("openCfg: wrong format of Cfg ") + path);
        const bool encoded = bytes.front() == 0xC6u || bytes.front() == 0xEBu || bytes.front() == 0xE4u;
        if (!encoded && bytes.front() != '\r' && bytes.front() != ' ' && bytes.front() != '/') throw std::runtime_error(std::string("openCfg: wrong format of Cfg ") + path);
        if (encoded) for (auto& byte : bytes) byte ^= 0xCBu;
        const bool rewrite = (encoded && storage_mode_ == StorageMode::Plain) || (!encoded && storage_mode_ == StorageMode::Encoded);
        if (rewrite) {
            auto stored = bytes;
            if (storage_mode_ == StorageMode::Encoded) for (auto& byte : stored) byte ^= 0xCBu;
            const int descriptor = g_sfera_files.create(path);
            if (descriptor < 0) throw std::runtime_error(std::string("Unable to create Cfg ") + path);
            try {
                if (g_sfera_files.write(descriptor, stored.data(), static_cast<std::uint32_t>(stored.size())) != static_cast<int>(stored.size())) throw std::runtime_error(std::string("Incomplete Cfg write: ") + path);
                g_sfera_files.close(descriptor);
            } catch (...) { g_sfera_files.close(descriptor); throw; }
        }
        return parse(std::string_view(reinterpret_cast<const char*>(bytes.data()), bytes.size()));
    } catch (const std::exception& exception) {
        CSphereError error;
        error.write(exception.what());
        throw;
    }
}

void SphereRender::ConfigDocument::setStorageMode(StorageMode mode) { storage_mode_ = mode; }
const SphereRender::ConfigDocument::Value* SphereRender::ConfigDocument::find(std::string_view name) const {
    const std::string query(name);
    for (const auto& value : values_) if (SferaSimpleParser::equalsIgnoreCase(value.name.c_str(), query.c_str())) return &value;
    return nullptr;
}
std::optional<std::int32_t> SphereRender::ConfigDocument::integer(std::string_view name) const {
    const auto* value = find(name);
    if (value == nullptr) return std::nullopt;
    if (value->type != Type::Integer) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::int32_t>(value->data);
}
std::optional<float> SphereRender::ConfigDocument::real(std::string_view name) const {
    const auto* value = find(name);
    if (value == nullptr) return std::nullopt;
    if (value->type != Type::Float) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<float>(value->data);
}
const char* SphereRender::ConfigDocument::text(std::string_view name) const {
    const auto* value = find(name);
    if (value == nullptr) return nullptr;
    if (value->type != Type::Text) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::string>(value->data).c_str();
}
std::optional<std::size_t> SphereRender::ConfigDocument::arraySize(std::string_view name) const {
    const auto* value = find(name);
    if (value == nullptr) return std::nullopt;
    switch (value->type) {
    case Type::IntegerArray: return std::get<std::vector<std::int32_t>>(value->data).size();
    case Type::FloatArray: return std::get<std::vector<float>>(value->data).size();
    case Type::TextArray: return std::get<std::vector<std::string>>(value->data).size();
    case Type::ObjectArray: return std::get<std::vector<ConfigDocument>>(value->data).size();
    default: throw std::runtime_error("getCfg: get size for non array. Name: " + value->name);
    }
}
std::optional<std::int32_t> SphereRender::ConfigDocument::integerAt(std::string_view name, std::size_t index) const {
    const auto* value = find(name);
    if (value == nullptr) return std::nullopt;
    if (value->type != Type::IntegerArray) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::vector<std::int32_t>>(value->data).at(index);
}
std::optional<float> SphereRender::ConfigDocument::realAt(std::string_view name, std::size_t index) const {
    const auto* value = find(name);
    if (value == nullptr) return std::nullopt;
    if (value->type != Type::FloatArray) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::vector<float>>(value->data).at(index);
}
const char* SphereRender::ConfigDocument::textAt(std::string_view name, std::size_t index) const {
    const auto* value = find(name);
    if (value == nullptr) return nullptr;
    if (value->type != Type::TextArray) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::vector<std::string>>(value->data).at(index).c_str();
}
const SphereRender::ConfigDocument* SphereRender::ConfigDocument::object(std::string_view name) const {
    const auto* value = find(name);
    if (value == nullptr) return nullptr;
    if (value->type != Type::Object) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return &std::get<std::vector<ConfigDocument>>(value->data).front();
}
const SphereRender::ConfigDocument* SphereRender::ConfigDocument::objectAt(std::string_view name, std::size_t index) const {
    const auto* value = find(name);
    if (value == nullptr) return nullptr;
    if (value->type != Type::ObjectArray) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return &std::get<std::vector<ConfigDocument>>(value->data).at(index);
}
std::span<const std::uint8_t> SphereRender::ConfigDocument::binary(std::string_view name) const {
    const auto* value = find(name);
    if (value == nullptr) return {};
    if (value->type != Type::Binary) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::vector<std::uint8_t>>(value->data);
}
const std::vector<SphereRender::ConfigDocument::Value>& SphereRender::ConfigDocument::values() const { return values_; }

void SphereRender::ModelParameters::load(const char* path) {
    if (initialized_) { CSphereError error; error.write("CObjParamManager::Open: object already initialized"); }
    try {
        const auto bytes = g_sfera_files.readAll(path);
        parse(std::string_view(reinterpret_cast<const char*>(bytes.data()), bytes.size()));
    } catch (const std::exception& exception) { CSphereError error; error.write(exception.what()); throw; }
}
void SphereRender::ModelParameters::parse(std::string_view source) {
    source = source.substr(0, source.find('\0'));
    std::vector<Object> parsed;
    while (!source.empty() && source.front() != '\0') {
        const auto end = source.find_first_of("\r\n\0", 0, 3);
        auto line = source.substr(0, end);
        source = end == std::string_view::npos ? std::string_view{} : source.substr(end + 1);
        if (line.empty() || line.front() == ' ') continue;
        const auto separator = line.find(' ');
        if (separator == std::string_view::npos) throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
        Object object;
        object.name = line.substr(0, separator);
        line.remove_prefix(separator + 1);
        while (!line.empty()) {
            while (!line.empty() && line.front() == ' ') line.remove_prefix(1);
            if (line.empty()) throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
            const auto comma = line.find(',');
            auto item = line.substr(0, comma);
            line = comma == std::string_view::npos ? std::string_view{} : line.substr(comma + 1);
            const auto name_end = item.find_first_of(" =");
            Parameter parameter;
            parameter.name = item.substr(0, name_end);
            if (parameter.name.empty()) throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
            if (name_end != std::string_view::npos) {
                item.remove_prefix(name_end);
                while (!item.empty() && item.front() == ' ') item.remove_prefix(1);
                if (!item.empty()) {
                    if (item.front() != '=') throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
                    item.remove_prefix(1);
                    while (!item.empty() && item.front() == ' ') item.remove_prefix(1);
                    parameter.value = std::string(item);
                }
            }
            object.parameters.push_back(std::move(parameter));
        }
        parsed.push_back(std::move(object));
    }
    objects_ = std::move(parsed);
    initialized_ = true;
}
void SphereRender::ModelParameters::clear() { objects_.clear(); initialized_ = false; }
const SphereRender::ModelParameters::Object* SphereRender::ModelParameters::findObject(std::string_view name) const {
    const std::string query(name);
    for (const auto& object : objects_) if (SferaSimpleParser::equalsIgnoreCase(object.name.c_str(), query.c_str())) return &object;
    return nullptr;
}
const SphereRender::ModelParameters::Parameter* SphereRender::ModelParameters::findParameter(std::string_view model, std::string_view parameter) const {
    const auto* object = findObject(model);
    if (object == nullptr) return nullptr;
    const std::string query(parameter);
    for (const auto& value : object->parameters) if (SferaSimpleParser::equalsIgnoreCase(value.name.c_str(), query.c_str())) return &value;
    return nullptr;
}
bool SphereRender::ModelParameters::contains(std::string_view model, std::string_view parameter) const { return findParameter(model, parameter) != nullptr; }
bool SphereRender::ModelParameters::hasModel(std::string_view model) const { return findObject(model) != nullptr; }
std::optional<std::string_view> SphereRender::ModelParameters::stringValue(std::string_view model, std::string_view parameter) const {
    const auto* value = findParameter(model, parameter);
    if (value == nullptr) return std::nullopt;
    if (!value->value) throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
    return *value->value;
}
std::optional<float> SphereRender::ModelParameters::floatValue(std::string_view model, std::string_view parameter) const {
    const auto source = stringValue(model, parameter);
    if (!source) return std::nullopt;
    float value = 0.0f;
    const char* begin = source->data();
    const char* end = source->data() + source->size();
    while (begin < end && std::isspace(static_cast<unsigned char>(*begin)) != 0) ++begin;
    if (begin < end && *begin == '+') ++begin;
    if (std::from_chars(begin, end, value).ec != std::errc{}) throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
    return value;
}
std::optional<std::int32_t> SphereRender::ModelParameters::intValue(std::string_view model, std::string_view parameter) const {
    const auto source = stringValue(model, parameter);
    if (!source) return std::nullopt;
    std::int32_t value = 0;
    const char* begin = source->data();
    const char* end = source->data() + source->size();
    while (begin < end && std::isspace(static_cast<unsigned char>(*begin)) != 0) ++begin;
    if (begin < end && *begin == '+') ++begin;
    if (std::from_chars(begin, end, value).ec != std::errc{}) throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
    return value;
}

std::uint32_t SphereRender::Material::randomColor(const std::array<float, 3>& variation) {
    std::uint32_t color = 0;
    for (float amount : variation) {
        std::uint32_t channel = 255;
        if (amount > 1e-6) {
            const auto random = ::rand();
            const auto range = static_cast<std::int32_t>(std::floor(static_cast<double>(amount) * 255.0 + 0.5));
            if (range > 0) channel -= static_cast<std::uint32_t>(random % range);
        }
        color = (color << 8) | channel;
    }
    return color;
}
void SphereRender::MaterialLibrary::clear() { materials_.clear(); default_index_.reset(); }
const SphereRender::Material* SphereRender::MaterialLibrary::find(std::string_view name) const {
    const std::string query(name);
    for (const auto& material : materials_) if (SferaSimpleParser::equalsIgnoreCase(material.name.c_str(), query.c_str())) return &material;
    return nullptr;
}
std::optional<std::uint16_t> SphereRender::MaterialLibrary::findIndex(std::string_view name) const {
    const std::string query(name);
    for (std::size_t index = 0; index < materials_.size(); ++index) if (SferaSimpleParser::equalsIgnoreCase(materials_[index].name.c_str(), query.c_str())) return static_cast<std::uint16_t>(index);
    return std::nullopt;
}
std::optional<std::uint16_t> SphereRender::MaterialLibrary::indexOf(const Material& material) const {
    for (std::size_t index = 0; index < materials_.size(); ++index) if (&materials_[index] == &material) return static_cast<std::uint16_t>(index);
    return std::nullopt;
}
const SphereRender::Material* SphereRender::MaterialLibrary::at(std::size_t index) const { return index < materials_.size() ? &materials_[index] : nullptr; }
const SphereRender::Material* SphereRender::MaterialLibrary::defaultMaterial() const { return default_index_ ? &materials_[*default_index_] : nullptr; }
std::size_t SphereRender::MaterialLibrary::size() const { return materials_.size(); }

void SphereRender::MaterialLibrary::load(const char* binary_path, const char* configuration_path) {
    try {
        ConfigDocument::setStorageMode(ConfigDocument::StorageMode::Plain);
        const auto configuration = ConfigDocument::open(configuration_path);
        const auto count_configured = configuration.arraySize("materials").value_or(0);
        const auto bytes = g_sfera_files.readAll(binary_path);
        std::size_t cursor = 0;
        const auto take = [&](std::size_t length) {
            if (length > bytes.size() - cursor) throw std::runtime_error("MaterialLibrary: truncated material file");
            const auto result = std::span<const std::uint8_t>(bytes).subspan(cursor, length);
            cursor += length;
            return result;
        };
        const auto integer = [&] {
            const auto data = take(4);
            return static_cast<std::uint32_t>(data[0]) | (static_cast<std::uint32_t>(data[1]) << 8) | (static_cast<std::uint32_t>(data[2]) << 16) | (static_cast<std::uint32_t>(data[3]) << 24);
        };
        const auto name = [&] {
            const auto data = take(36);
            const auto end = std::find(data.begin(), data.end(), std::uint8_t{});
            if (end == data.end()) throw std::runtime_error("MaterialLibrary: unterminated material or texture name");
            return std::string(data.begin(), end);
        };
        const auto count = integer();
        if (count > 65536 || count > (bytes.size() - cursor) / 654) throw std::runtime_error("MaterialLibrary: invalid material count");
        std::vector<Material> materials;
        materials.reserve(count);
        std::optional<std::uint16_t> default_index = count == 0 ? std::nullopt : std::optional<std::uint16_t>(0);
        for (std::uint32_t index = 0; index < count; ++index) {
            Material material;
            material.name = name();
            if (SferaSimpleParser::equalsIgnoreCase(material.name.c_str(), "default")) default_index = static_cast<std::uint16_t>(index);
            const auto texture_count = integer();
            if (texture_count > 16) throw std::runtime_error("MaterialLibrary: invalid texture count");
            material.textures.reserve(texture_count);
            for (std::uint32_t texture = 0; texture < 16; ++texture) {
                if (texture >= texture_count) { take(36); continue; }
                auto texture_name = name();
                if (texture_name.size() < 2) throw std::runtime_error("MaterialLibrary: invalid texture name");
                texture_name.resize(texture_name.size() - 2);
                material.textures.push_back(g_sfera_textures.find(texture_name.c_str()));
            }
            for (auto& channel : material.color) channel = std::bit_cast<float>(integer());
            take(22);
            for (std::size_t configured = 0; configured < count_configured; ++configured) {
                const auto* record = configuration.objectAt("materials", configured);
                if (record == nullptr) throw std::runtime_error("Can't go into material struct " + std::to_string(configured));
                const auto* configured_name = record->text("name");
                if (configured_name == nullptr) throw std::runtime_error("Field name is absent in material " + std::to_string(configured));
                if (!SferaSimpleParser::equalsIgnoreCase(configured_name, material.name.c_str())) continue;
                const auto red = record->realAt("rgbRand", 0);
                if (red) {
                    const auto green = record->realAt("rgbRand", 1);
                    const auto blue = record->realAt("rgbRand", 2);
                    if (!green || !blue) throw std::runtime_error("Wrong format of rgbRand in material struct " + std::to_string(configured));
                    material.colorVariation = {*red, *green, *blue};
                    material.hasColorVariation = true;
                }
                break;
            }
            materials.push_back(std::move(material));
        }
        materials_ = std::move(materials);
        default_index_ = default_index;
    } catch (const std::exception& exception) { CSphereError error; error.write(exception.what()); throw; }
}


SphereRender::Model::~Model() {
    std::free(cached_vegetation_vertices);
}

std::unique_ptr<SphereRender::Model> SphereRender::Model::load(const char* model_name, const char* directory, const ModelParameters& parameters, const MaterialLibrary& materials) {
    try {
        if (model_name == nullptr || directory == nullptr) throw std::invalid_argument("Model path is missing");
        const std::string path = std::string(directory) + model_name + ".mdl";
        const std::vector<std::uint8_t> bytes = g_sfera_files.readAll(path.c_str());
        return decode(model_name, bytes, parameters, materials);
    } catch (const std::exception& exception) {
        CSphereError error;
        error.write(exception.what());
        throw;
    }
}

std::unique_ptr<SphereRender::Model> SphereRender::Model::decode(std::string_view model_name, std::span<const std::uint8_t> bytes, const ModelParameters& parameters, const MaterialLibrary& materials) {
    const auto fail = [&](std::string_view reason) -> void { throw std::runtime_error("Cannot load model '" + std::string(model_name) + "': " + std::string(reason)); };
    if (model_name.size() >= sizeof(name)) fail("model name is too long");
    if (bytes.size() < 258u) fail("truncated MDL header");
    const auto byte = [&](std::size_t offset) -> std::uint8_t { if (offset >= bytes.size()) fail("truncated MDL field"); return bytes[offset]; };
    const auto word = [&](std::size_t offset) -> std::uint16_t { return static_cast<std::uint16_t>(byte(offset) | static_cast<std::uint16_t>(byte(offset + 1u)) << 8u); };
    const auto integer = [&](std::size_t offset) -> std::uint32_t { return word(offset) | static_cast<std::uint32_t>(word(offset + 2u)) << 16u; };
    const auto real = [&](std::size_t offset) -> float { const float value = std::bit_cast<float>(integer(offset)); if (!std::isfinite(value)) fail("non-finite MDL coordinate"); return value; };
    const auto point = [&](std::size_t offset) -> SferaVec3F { return {real(offset), real(offset + 4u), real(offset + 8u)}; };
    const std::uint32_t source_vertex_count = word(4u);
    const std::uint32_t source_face_count = word(6u);
    const std::uint32_t source_submesh_count = word(8u);
    const std::uint32_t source_material_count = byte(10u);
    const std::uint32_t material_name_bytes = word(11u);
    const std::uint32_t source_bone_count = byte(13u);
    const std::uint32_t child_bone_count = byte(14u);
    const std::uint32_t keyframe_count = word(16u);
    const std::uint32_t animation_frame_count = word(18u);
    const std::uint8_t source_animation_count = byte(20u);
    const std::uint8_t source_has_colors = byte(23u);
    const std::uint32_t vertex_color_count = word(24u);
    const std::uint32_t source_collision_kind = integer(26u);
    const std::uint32_t source_collision_group_count = integer(250u);
    const std::uint32_t collision_triangle_count = integer(254u);
    std::size_t cursor = 258u;
    const auto section = [&](std::size_t count, std::size_t width) -> std::size_t { if (count > (bytes.size() - cursor) / width) fail("truncated MDL section"); const std::size_t begin = cursor; cursor += count * width; return begin; };
    const std::size_t source_material_names = section(material_name_bytes, 1u);
    const std::size_t source_vertices = section(source_vertex_count, 32u);
    const std::size_t source_faces = section(source_face_count, 10u);
    const std::size_t source_submeshes = section(source_submesh_count, 15u);
    const std::size_t source_bones = section(source_bone_count, 39u);
    const std::size_t source_children = section(child_bone_count, 1u);
    const std::size_t source_keyframes = source_animation_count != 0u ? section(keyframe_count, 28u) : cursor;
    const std::size_t source_animation_frames = source_animation_count != 0u ? section(animation_frame_count, 3u) : cursor;
    const std::size_t source_animation_lengths = source_animation_count != 0u ? section(source_animation_count, 2u) : cursor;
    const std::size_t source_colors = source_has_colors == 1u ? section(vertex_color_count, 4u) : cursor;
    const std::size_t source_face_colors = source_has_colors == 1u ? section(source_face_count, 6u) : cursor;
    const std::size_t source_bone_bounds = source_animation_count == 0u ? section(source_bone_count, 24u) : cursor;
    const std::size_t source_collision_groups = source_collision_kind == 2u ? section(source_collision_group_count, 12u) : cursor;
    const std::size_t source_collision_triangles = source_collision_kind == 2u ? section(collision_triangle_count, 80u) : cursor;
    if (cursor != bytes.size()) fail("MDL section sizes do not match the file size");

    auto model = std::make_unique<Model>();
    std::copy(model_name.begin(), model_name.end(), model->name);
    model->vertex_count = source_vertex_count;
    model->face_count = source_face_count;
    model->submesh_count = source_submesh_count;
    model->bone_count = source_bone_count;
    model->material_count = source_material_count;
    model->render_flags = byte(15u);
    model->animation_count = source_animation_count;
    model->frame_count = word(21u);
    model->has_vertex_colors = source_has_colors;
    model->collision_kind = source_collision_kind;
    model->minimum = point(30u);
    model->maximum = point(42u);
    for (std::size_t index = 0u; index < 8u; ++index) {
        model->oriented_corners.corners[index] = point(54u + index * 12u);
        model->collision_corners.corners[index] = point(150u + index * 12u);
    }
    model->radius = real(246u);
    model->collision_group_count = source_collision_group_count;
    model->casts_static_shadow = model->radius > 2.0f && model->animation_count == 0u;
    model->lod_distance = parameters.floatValue(model_name, "lod_f").value_or(1000.0f);
    model->lod_power = parameters.floatValue(model_name, "lod_pow").value_or(-1.0f);
    model->shadow_fade = parameters.floatValue(model_name, "shad_f").value_or(0.5f);
    model->shadow_scale = parameters.floatValue(model_name, "shad_s").value_or(2.0f);
    model->shadow_spread = parameters.floatValue(model_name, "shad_sp").value_or(0.8500000238418579f);
    model->trace_distance = parameters.floatValue(model_name, "trace").value_or(-1.0f);
    if (const auto alpha = parameters.floatValue(model_name, "land_shade_affect_K")) {
        const double rounded = std::floor(static_cast<float>(static_cast<double>(*alpha) * 255.0 + 0.5));
        if (!std::isfinite(rounded) || rounded < static_cast<double>(INT32_MIN) || rounded > static_cast<double>(INT32_MAX)) fail("invalid landscape shadow coefficient");
        model->landscape_shadow_alpha = static_cast<std::uint32_t>(std::min(static_cast<std::int32_t>(rounded), 255));
    }

    model->material_storage_ = std::make_unique<std::uint16_t[]>(source_material_count);
    model->material_indices = model->material_storage_.get();
    cursor = source_material_names;
    for (std::size_t index = 0u; index < source_material_count; ++index) {
        if (cursor == source_vertices) fail("missing material name");
        const std::size_t length = byte(cursor++);
        if (length > source_vertices - cursor) fail("material name exceeds its section");
        std::string material_name;
        material_name.reserve(length);
        for (std::size_t character = 0u; character < length && byte(cursor + character) != 0u; ++character) material_name.push_back(static_cast<char>(byte(cursor + character)));
        const auto material = materials.findIndex(material_name);
        if (!material) fail("material is absent from the material library: " + material_name);
        model->material_indices[index] = *material;
        cursor += length;
    }

    model->vertex_storage_ = std::make_unique<ModelVertex[]>(source_vertex_count);
    model->vertices = model->vertex_storage_.get();
    for (std::size_t index = 0u; index < source_vertex_count; ++index) {
        const std::size_t offset = source_vertices + index * 32u;
        model->vertices[index].position = point(offset);
        model->vertices[index].normal = point(offset + 12u);
        model->vertices[index].u = real(offset + 24u);
        model->vertices[index].v = real(offset + 28u);
    }
    model->face_storage_ = std::make_unique<ModelFace[]>(source_face_count);
    model->faces = model->face_storage_.get();
    for (std::size_t index = 0u; index < source_face_count; ++index) {
        const std::size_t offset = source_faces + index * 10u;
        for (std::size_t vertex = 0u; vertex < 3u; ++vertex) model->faces[index].vertices[vertex] = word(offset + vertex * 2u);
        model->faces[index].attributes = integer(offset + 6u);
    }
    model->submesh_storage_ = std::make_unique<Submesh[]>(source_submesh_count);
    model->submeshes = model->submesh_storage_.get();
    for (std::size_t index = 0u; index < source_submesh_count; ++index) {
        const std::size_t offset = source_submeshes + index * 15u;
        Submesh& submesh = model->submeshes[index];
        submesh.bone_and_flags = byte(offset);
        const std::size_t material = byte(offset + 1u);
        if (material >= source_material_count) fail("invalid submesh material");
        submesh.material_index = model->material_indices[material];
        submesh.first_face = word(offset + 2u);
        submesh.face_count = word(offset + 4u);
        submesh.first_vertex = word(offset + 6u);
        submesh.vertex_count = word(offset + 8u);
        submesh.flags = byte(offset + 10u);
        submesh.export_metadata[0] = word(offset + 11u);
        submesh.export_metadata[1] = word(offset + 13u);
        if (static_cast<std::size_t>(submesh.first_face) + submesh.face_count > source_face_count || static_cast<std::size_t>(submesh.first_vertex) + submesh.vertex_count > source_vertex_count) fail("submesh range exceeds its geometry");
        if (submesh.boneIndex() >= source_bone_count) fail("invalid submesh bone");
        for (std::size_t face = submesh.first_face; face < static_cast<std::size_t>(submesh.first_face) + submesh.face_count; ++face) for (std::uint16_t vertex : model->faces[face].vertices) if (vertex >= submesh.vertex_count) fail("face vertex exceeds its submesh");
        const Material* material_data = materials.at(submesh.material_index);
        if (material_data == nullptr) fail("invalid material index");
        if (material_data->hasColorVariation) model->color_variation = material_data->colorVariation;
    }
    model->bone_storage_ = std::make_unique<Bone[]>(source_bone_count);
    model->bones = model->bone_storage_.get();
    for (std::size_t index = 0u; index < source_bone_count; ++index) {
        const std::size_t offset = source_bones + index * 39u;
        Bone& bone = model->bones[index];
        std::size_t length = 0u;
        while (length < sizeof(bone.name) && byte(offset + length) != 0u) ++length;
        if (length == sizeof(bone.name)) fail("unterminated bone name");
        for (std::size_t character = 0u; character < length; ++character) bone.name[character] = static_cast<char>(byte(offset + character));
        bone.geometry_kind = byte(offset + 32u);
        bone.child_count = byte(offset + 33u);
        bone.first_child = byte(offset + 34u);
        if (static_cast<std::size_t>(bone.first_child) + bone.child_count > child_bone_count) fail("bone children exceed the child table");
        if (source_animation_count != 0u) {
            std::construct_at(&bone.animation);
            bone.animation.animated = byte(offset + 35u);
            bone.animation.pose_index = word(offset + 36u);
            bone.animation.suppress_secondary_animation = byte(offset + 38u);
            if (bone.animation.pose_index >= (bone.animation.animated != 0u ? animation_frame_count : keyframe_count)) fail("invalid bone animation offset");
            const std::string_view name = bone.name;
            const auto equal = [&](const char* value) { return SferaSimpleParser::equalsIgnoreCase(bone.name, value); };
            if (equal("back_swo")) bone.animation.attachment_slot = 0u;
            else if (equal("back_ara")) bone.animation.attachment_slot = 1u;
            else if (equal("back_axe")) bone.animation.attachment_slot = 2u;
            else if (equal("back_spe")) bone.animation.attachment_slot = 3u;
            else if (equal("back_cam")) bone.animation.attachment_slot = 4u;
            else if (equal("finl_m1o1") || equal("fingl_m1o1")) bone.animation.attachment_slot = 100u;
            else if (equal("finr_m1o1") || equal("fingr_m1o1")) bone.animation.attachment_slot = 101u;
            else if (equal("neck_m1o1")) bone.animation.attachment_slot = 102u;
            else if (name.size() >= 4u && SferaSimpleParser::equalsIgnoreCase(std::string(name.substr(0u, 4u)).c_str(), "head")) bone.animation.attachment_slot = 103u;
        } else {
            const std::size_t bounds_offset = source_bone_bounds + index * 24u;
            bone.bounds.minimum = point(bounds_offset);
            bone.bounds.maximum = point(bounds_offset + 12u);
            bone.bounds.corners = SferaBoundsCornersRuntime::fromExtents(bone.bounds.minimum, bone.bounds.maximum);
            bone.bounds.center = (bone.bounds.minimum + bone.bounds.maximum) * 0.5f;
            const SferaVec3F diagonal = bone.bounds.maximum - bone.bounds.minimum;
            bone.bounds.diagonal_length = std::sqrt(static_cast<float>(diagonal.dot(diagonal)));
        }
    }
    model->child_bone_storage_ = std::make_unique<std::uint8_t[]>(child_bone_count);
    model->child_bones = model->child_bone_storage_.get();
    for (std::size_t index = 0u; index < child_bone_count; ++index) {
        model->child_bones[index] = byte(source_children + index);
        if (model->child_bones[index] >= source_bone_count) fail("invalid child bone");
    }
    if (source_animation_count != 0u) {
        model->keyframe_storage_ = std::make_unique<ModelKeyframe[]>(keyframe_count);
        model->keyframes = model->keyframe_storage_.get();
        for (std::size_t index = 0u; index < keyframe_count; ++index) {
            const std::size_t offset = source_keyframes + index * 28u;
            model->keyframes[index].translation = point(offset);
            model->keyframes[index].rotation = {real(offset + 12u), real(offset + 16u), real(offset + 20u), real(offset + 24u)};
        }
        model->animation_frame_storage_ = std::make_unique<AnimationFrame[]>(animation_frame_count);
        model->animation_frames = model->animation_frame_storage_.get();
        for (std::size_t index = 0u; index < animation_frame_count; ++index) {
            AnimationFrame& frame = model->animation_frames[index];
            frame.keyframe = word(source_animation_frames + index * 3u);
            frame.interpolation = byte(source_animation_frames + index * 3u + 2u);
            if (frame.keyframe >= keyframe_count || (frame.interpolation != 255u && static_cast<std::size_t>(frame.keyframe) + 1u >= keyframe_count)) fail("invalid animation keyframe");
        }
        model->animation_length_storage_ = std::make_unique<std::uint16_t[]>(source_animation_count);
        model->animation_lengths = model->animation_length_storage_.get();
        std::size_t sequence_begin = 0u;
        std::size_t required_frames = 0u;
        for (std::size_t index = 0u; index < source_animation_count; ++index) {
            const std::uint16_t length = word(source_animation_lengths + index * 2u);
            model->animation_lengths[index] = length;
            required_frames = std::max(required_frames, sequence_begin + std::max<std::size_t>(length, 1u));
            sequence_begin += length;
        }
        for (std::size_t index = 0u; index < source_bone_count; ++index) if (model->bones[index].animation.animated != 0u && static_cast<std::size_t>(model->bones[index].animation.pose_index) + required_frames > animation_frame_count) fail("bone animation sequences exceed the frame table");
    }
    if (source_has_colors == 1u) {
        model->vertex_color_storage_ = std::make_unique<std::uint32_t[]>(vertex_color_count);
        model->vertex_colors = model->vertex_color_storage_.get();
        for (std::size_t index = 0u; index < vertex_color_count; ++index) model->vertex_colors[index] = integer(source_colors + index * 4u);
        model->face_color_storage_ = std::make_unique<FaceColorIndices[]>(source_face_count);
        model->face_colors = model->face_color_storage_.get();
        for (std::size_t index = 0u; index < source_face_count; ++index) for (std::size_t vertex = 0u; vertex < 3u; ++vertex) {
            const std::uint16_t color = word(source_face_colors + index * 6u + vertex * 2u);
            if (color >= vertex_color_count) fail("invalid face color index");
            model->face_colors[index].vertices[vertex] = color;
        }
    }
    if (source_collision_kind == 2u) {
        model->collision_group_storage_ = std::make_unique<ModelCollisionGroup[]>(source_collision_group_count);
        model->collision_groups = model->collision_group_storage_.get();
        for (std::size_t index = 0u; index < source_collision_group_count; ++index) {
            ModelCollisionGroup& group = model->collision_groups[index];
            group.bone = integer(source_collision_groups + index * 12u);
            group.triangle_count = integer(source_collision_groups + index * 12u + 4u);
            group.first_triangle = integer(source_collision_groups + index * 12u + 8u);
            if (group.bone >= source_bone_count || static_cast<std::uint64_t>(group.first_triangle) + group.triangle_count > collision_triangle_count) fail("invalid collision group");
        }
        model->collision_triangle_storage_ = std::make_unique<ModelCollisionTriangle[]>(collision_triangle_count);
        model->collision_triangles = model->collision_triangle_storage_.get();
        for (std::size_t index = 0u; index < collision_triangle_count; ++index) {
            const std::size_t offset = source_collision_triangles + index * 80u;
            ModelCollisionTriangle& triangle = model->collision_triangles[index];
            triangle.minimum = point(offset);
            triangle.maximum = point(offset + 12u);
            for (std::size_t vertex = 0u; vertex < 3u; ++vertex) triangle.vertices[vertex] = point(offset + 24u + vertex * 12u);
            triangle.normal = point(offset + 60u);
            triangle.plane_distance = real(offset + 72u);
            triangle.collision_flags = integer(offset + 76u);
        }
    }
    model->recoverBounds();
    if (model->minimum_size < 0.05000000074505806f) fail("object size is below MIN_OBJECT_SIZE");
    model->assignMaterials(materials);
    model->prepareVegetation(parameters);
    return model;
}

void SphereRender::Model::recoverBounds() {
    const SferaVec3F first_axis = oriented_corners.corners[5] - oriented_corners.corners[0];
    const SferaVec3F second_axis = oriented_corners.corners[0] - oriented_corners.corners[3];
    float rotated_first_x = first_axis.x;
    float rotated_first_y = first_axis.y;
    float rotated_second_y = second_axis.y;
    float z_angle = 0.0f;
    if (static_cast<double>(second_axis.x) * second_axis.x + static_cast<double>(second_axis.y) * second_axis.y > 1.0e-6) {
        z_angle = static_cast<float>(4.7123894691467285 - static_cast<float>(std::atan2(static_cast<double>(second_axis.y), static_cast<double>(second_axis.x))));
        const float cosine = static_cast<float>(std::cos(static_cast<double>(z_angle)));
        const float sine = static_cast<float>(std::sin(static_cast<double>(z_angle)));
        rotated_first_x = static_cast<float>(static_cast<double>(first_axis.x) * cosine - static_cast<double>(sine) * first_axis.y);
        rotated_first_y = static_cast<float>(static_cast<double>(first_axis.y) * cosine + static_cast<double>(first_axis.x) * sine);
        rotated_second_y = static_cast<float>(static_cast<double>(second_axis.x) * sine + static_cast<double>(cosine) * second_axis.y);
    }
    const float y_angle = static_cast<float>(4.7123894691467285 - static_cast<float>(std::atan2(static_cast<double>(rotated_second_y), static_cast<double>(second_axis.z))));
    const float cosine = static_cast<float>(std::cos(static_cast<double>(y_angle)));
    const float sine = static_cast<float>(std::sin(static_cast<double>(y_angle)));
    const float rotated_first_z = static_cast<float>(static_cast<double>(cosine) * first_axis.z - static_cast<double>(sine) * rotated_first_y);
    const float x_angle = static_cast<float>(1.5707964897155762 - static_cast<float>(std::atan2(static_cast<double>(rotated_first_z), static_cast<double>(rotated_first_x))));
    bounds_transform = SferaMatrix4x4F::fromEuler(oriented_corners.corners[0], {-x_angle, -y_angle, -z_angle});
    oriented_size = bounds_transform.inverseTransformPoint(oriented_corners.corners[7]);
    const SferaVec3F extents = collision_kind == 0u ? maximum - minimum : oriented_size;
    minimum_size = std::min({extents.x, extents.y, extents.z});
}

void SphereRender::Model::assignMaterials(const MaterialLibrary& materials) {
    for (std::size_t index = 0u; index < submesh_count; ++index) {
        const Submesh& submesh = submeshes[index];
        const Material* material = materials.at(submesh.material_index);
        const std::string_view bone_name = bones[submesh.boneIndex()].name;
        for (std::size_t vertex = submesh.first_vertex; vertex < static_cast<std::size_t>(submesh.first_vertex) + submesh.vertex_count; ++vertex) {
            vertices[vertex].material = material;
            if (bone_name.starts_with("_u")) vertices[vertex].normal = {0.0f, -1.0f, 0.0f};
            else if (bone_name.starts_with("_s")) {
                const SferaVec3F radial{vertices[vertex].position.x, 0.0f, vertices[vertex].position.z};
                const float length = std::sqrt(static_cast<float>(radial.dot(radial)));
                vertices[vertex].normal = length < 0.00001f ? SferaVec3F{} : radial * (1.0f / length);
            }
        }
    }
}

void SphereRender::Model::prepareGrass(bool synchronized, float ground_y) {
    std::vector<std::int32_t> components(vertex_count, -1);
    std::int32_t component = 0;
    for (std::size_t submesh_index = 0u; submesh_index < submesh_count; ++submesh_index) {
        const Submesh& submesh = submeshes[submesh_index];
        std::vector<bool> visited(submesh.face_count, false);
        const auto mark = [&](std::size_t face) { visited[face] = true; for (std::uint16_t vertex : faces[submesh.first_face + face].vertices) components[submesh.first_vertex + vertex] = component; };
        for (std::size_t seed = 0u; seed < submesh.face_count; ++seed) {
            if (visited[seed]) continue;
            mark(seed);
            bool changed = true;
            while (changed) {
                changed = false;
                for (std::size_t face = seed + 1u; face < submesh.face_count; ++face) {
                    if (visited[face]) continue;
                    const ModelFace& candidate = faces[submesh.first_face + face];
                    if (std::any_of(std::begin(candidate.vertices), std::end(candidate.vertices), [&](std::uint16_t vertex) { return components[submesh.first_vertex + vertex] == component; })) { mark(face); changed = true; }
                }
            }
            ++component;
        }
    }
    grass_storage_ = std::make_unique<GrassInfluence[]>(vertex_count);
    grass_influences = grass_storage_.get();
    tree_storage_.reset();
    const std::uint16_t shared_phase = static_cast<std::uint16_t>(std::rand());
    for (std::size_t index = 0u; index < vertex_count; ++index) {
        GrassInfluence& influence = grass_influences[index];
        const SferaVec3F& position = vertices[index].position;
        if (static_cast<double>(position.y) - ground_y > 0.0) continue;
        if (components[index] < 0) throw std::runtime_error(std::string("Vegetation vertex has no face in model '") + name + "'");
        std::optional<std::size_t> nearest;
        float nearest_squared = 0.0f;
        const auto search = [&](bool same_component) {
            for (std::size_t candidate = 0u; candidate < vertex_count; ++candidate) {
                if (same_component && components[candidate] != components[index]) continue;
                if (!(static_cast<double>(vertices[candidate].position.y) - ground_y > 0.0)) continue;
                const SferaVec3F difference = position - vertices[candidate].position;
                const float squared = static_cast<float>(difference.dot(difference));
                if (!nearest || nearest_squared > squared) { nearest = candidate; nearest_squared = squared; }
            }
        };
        search(true);
        if (!nearest) search(false);
        if (!nearest) throw std::runtime_error(std::string("Vegetation has no ground anchor in model '") + name + "'");
        const float distance = std::sqrt(nearest_squared);
        const float alignment = static_cast<float>(std::fabs((static_cast<double>(position.y) - vertices[*nearest].position.y) / distance));
        if (alignment < 0.7070000171661377f) influence.anchor_vertex = GrassInfluence::Horizontal;
        else { influence.anchor_vertex = static_cast<std::uint16_t>(*nearest); influence.distance = distance; }
        influence.phase = synchronized ? shared_phase : static_cast<std::uint16_t>(std::rand());
        influence.share_phase = synchronized && index != 0u ? 1u : 0u;
    }
}

void SphereRender::Model::prepareTree(float dead_radius, float phase_multiplier) {
    tree_storage_ = std::make_unique<TreeInfluence[]>(vertex_count);
    tree_influences = tree_storage_.get();
    grass_storage_.reset();
    float maximum_radius_squared = 0.0f;
    for (std::size_t index = 0u; index < vertex_count; ++index) {
        const SferaVec3F& position = vertices[index].position;
        maximum_radius_squared = std::max(maximum_radius_squared, static_cast<float>(static_cast<double>(position.x) * position.x + static_cast<double>(position.z) * position.z));
    }
    const float maximum_radius = std::sqrt(maximum_radius_squared);
    float amplitude_scale = static_cast<float>(1.0 / (static_cast<double>(maximum_radius) - dead_radius));
    if (radius < 7.0f) amplitude_scale = static_cast<float>(static_cast<double>(amplitude_scale) * 0.4000000059604645);
    const float dead_radius_squared = static_cast<float>(static_cast<double>(dead_radius) * dead_radius);
    for (std::size_t index = 0u; index < vertex_count; ++index) {
        const SferaVec3F& position = vertices[index].position;
        const float distance_squared = static_cast<float>(static_cast<double>(position.x) * position.x + static_cast<double>(position.z) * position.z);
        tree_influences[index].amplitude = dead_radius_squared > distance_squared ? 0.0f : static_cast<float>((static_cast<double>(std::sqrt(distance_squared)) - dead_radius) * amplitude_scale);
        const double phase = std::trunc((static_cast<double>(position.y) + position.x + position.z) * phase_multiplier);
        if (!std::isfinite(phase) || phase < static_cast<double>(INT32_MIN) || phase > static_cast<double>(INT32_MAX)) throw std::runtime_error(std::string("Invalid vegetation phase in model '") + name + "'");
        tree_influences[index].phase = static_cast<std::uint16_t>(static_cast<std::int32_t>(phase));
    }
}

void SphereRender::Model::prepareVegetation(const ModelParameters& parameters) {
    vegetation_kind = static_cast<VegetationKind>(parameters.intValue(name, "dg_type").value_or(-1));
    const float ground_y = parameters.floatValue(name, "ground_y").value_or(0.0f);
    if (vegetation_kind == VegetationKind::Grass || vegetation_kind == VegetationKind::SynchronizedGrass || vegetation_kind == VegetationKind::InteractiveGrass) prepareGrass(vegetation_kind == VegetationKind::SynchronizedGrass, ground_y);
    if (vegetation_kind == VegetationKind::InteractiveGrass) {
        bending_storage_ = std::make_unique<GrassBendingBasis[]>(vertex_count);
        grass_bending = bending_storage_.get();
        for (std::size_t index = 0u; index < vertex_count; ++index) {
            GrassBendingBasis& basis = grass_bending[index];
            basis.anchor = {vertices[index].position.x, -0.15000000596046448f, vertices[index].position.z};
            const GrassInfluence& influence = grass_influences[index];
            if (influence.anchor_vertex >= 65000u) continue;
            const SferaVec3F direction = vertices[index].position - vertices[influence.anchor_vertex].position;
            const SferaVec3F first_axis = SferaVec3F{0.0f, 0.0f, 1.0f}.cross(direction);
            const SferaVec3F second_axis = direction.cross({1.0f, 0.0f, 0.0f});
            const float first_length = std::sqrt(static_cast<float>(first_axis.dot(first_axis)));
            const float second_length = std::sqrt(static_cast<float>(second_axis.dot(second_axis)));
            basis.first_axis = first_axis * (influence.distance / first_length);
            basis.second_axis = second_axis * (influence.distance / second_length);
        }
    }
    if (vegetation_kind == VegetationKind::Tree) {
        const auto dead_radius = parameters.floatValue(name, "deadRadius");
        const auto phase_multiplier = parameters.floatValue(name, "phaseMul");
        if (!dead_radius || !phase_multiplier) throw std::runtime_error(std::string("Missing deadRadius or phaseMul for tree model '") + name + "'");
        prepareTree(*dead_radius, *phase_multiplier);
    }
}

void SphereRender::Model::initializeGrassGeometry(std::uint32_t vertices_needed, std::uint32_t faces_needed, float height) {
    if (vertices != nullptr || faces != nullptr || bones != nullptr) throw std::logic_error("Grass geometry is already initialized");
    std::copy_n("AutoGrass", 10u, name);
    vertex_count = vertices_needed;
    face_count = faces_needed;
    bone_count = 1u;
    vertex_storage_ = std::make_unique<ModelVertex[]>(vertex_count);
    face_storage_ = std::make_unique<ModelFace[]>(face_count);
    bone_storage_ = std::make_unique<Bone[]>(bone_count);
    grass_storage_ = std::make_unique<GrassInfluence[]>(vertex_count);
    bending_storage_ = std::make_unique<GrassBendingBasis[]>(vertex_count);
    vertices = vertex_storage_.get();
    faces = face_storage_.get();
    bones = bone_storage_.get();
    grass_influences = grass_storage_.get();
    grass_bending = bending_storage_.get();
    vegetation_kind = VegetationKind::Grass;
    radius = std::sqrt(141.12777709960938f);
    std::copy_n("_u_grass", 9u, bones[0].name);
    bones[0].geometry_kind = 1u;
    bones[0].bounds.minimum = {-5.0f, -height, -5.0f};
    bones[0].bounds.maximum = {5.0f, 0.0f, 5.0f};
    bones[0].bounds.corners = SferaBoundsCornersRuntime::fromExtents(bones[0].bounds.minimum, bones[0].bounds.maximum);
    bones[0].bounds.center = {0.0f, -0.699999988079071f, 0.0f};
    bones[0].bounds.diagonal_length = 8.0f;
    minimum = bones[0].bounds.minimum;
    maximum = bones[0].bounds.maximum;
    collision_corners = bones[0].bounds.corners;
    lod_distance = 0.5f;
    lod_power = 0.0f;
    trace_distance = 0.0f;
}

void SphereRender::Model::finishGrassGeometry(std::span<const Submesh> groups) {
    auto storage = std::make_unique<Submesh[]>(groups.size());
    std::copy(groups.begin(), groups.end(), storage.get());
    submesh_count = static_cast<std::uint32_t>(groups.size());
    submesh_storage_ = std::move(storage);
    submeshes = submesh_storage_.get();
    shadow_fade = 0.0f;
    shadow_scale = 1.0f;
    shadow_spread = 1.0f;
    material_count = 0u;
    casts_static_shadow = 0u;
    render_flags = 0u;
    animation_count = 0u;
    collision_kind = 3u;
}


namespace {
    std::string resourceNameKey(std::string_view value) {
        std::string result(value);
        for (auto& character : result) {
            const auto byte = static_cast<std::uint8_t>(character);
            if ((byte >= 'A' && byte <= 'Z') || (byte >= 0xC0u && byte <= 0xDFu)) character = static_cast<char>(byte + 0x20u);
            else if (byte == 0xA8u) character = static_cast<char>(0xB8u);
        }
        return result;
    }
}

namespace {
    struct DdsPixelFormat {
        std::uint32_t size;
        std::uint32_t flags;
        std::uint32_t encoding;
        std::uint32_t bit_count;
        std::uint32_t channel_masks[4];
    };

    struct DdsHeader {
        char signature[4];
        std::uint32_t size;
        std::uint32_t flags;
        std::uint32_t height;
        std::uint32_t width;
        std::uint32_t pitch;
        std::uint32_t depth;
        std::uint32_t mip_count;
        std::uint32_t reserved[11];
        DdsPixelFormat format;
        std::uint32_t capabilities;
        std::uint32_t extended_capabilities;
        std::uint32_t reserved_capabilities[2];
        std::uint32_t reserved_tail;
    };
}

void SphereRender::TextureRepository::initialize() {
    clear();
    initialized = true;
}

void SphereRender::TextureRepository::addFolder(const char* directory) {
    if (directory == nullptr) return;
    const std::filesystem::path folder(directory);
    std::error_code error;
    for (std::filesystem::directory_iterator iterator(folder, error), end; !error && iterator != end; iterator.increment(error)) {
        if (!iterator->is_regular_file(error) || error || resourceNameKey(iterator->path().extension().string()) != ".dds") continue;
        auto name = iterator->path().filename().string();
        name.resize(name.find('.'));
        if (name.empty()) continue;
        const auto index = static_cast<std::uint32_t>(entries.size());
        Entry entry;
        entry.name = name;
        entry.filename = iterator->path();
        entries.push_back(std::move(entry));
        names.insert_or_assign(resourceNameKey(name), index);
    }
}

void SphereRender::TextureRepository::finishRegistration() {
    default_texture = static_cast<std::uint32_t>(find("default"));
}

void SphereRender::TextureRepository::clear() {
    entries.clear();
    names.clear();
    default_texture = UINT32_MAX;
    initialized = false;
}

std::int32_t SphereRender::TextureRepository::find(const char* name) const {
    // The existing texture lookup contract uses entry zero for an unknown name.
    if (!initialized || name == nullptr || *name == '\0') return 0;
    const auto found = names.find(resourceNameKey(name));
    return found == names.end() ? 0 : static_cast<std::int32_t>(found->second);
}

SphereRender::TextureRepository::Entry* SphereRender::TextureRepository::resolve(std::uint32_t index) {
    if (index >= entries.size()) index = default_texture;
    return index < entries.size() ? &entries[index] : nullptr;
}

IDirect3DBaseTexture9* SphereRender::TextureRepository::resource(std::uint32_t index) {
    auto* entry = resolve(index);
    if (entry == nullptr) return nullptr;
    if (entry->texture != nullptr) return entry->texture.get();
    const auto bytes = g_sfera_files.readAll(entry->filename.string().c_str());
    load(*entry, bytes);
    return entry->texture.get();
}

SphereUI::TextExtent SphereRender::TextureRepository::size(std::uint32_t index) {
    auto* texture = resource(index);
    if (texture == nullptr) return {};
    D3DSURFACE_DESC description{};
    const auto result = texture->GetType() == D3DRTYPE_CUBETEXTURE ? static_cast<IDirect3DCubeTexture9*>(texture)->GetLevelDesc(0u, &description) : static_cast<IDirect3DTexture9*>(texture)->GetLevelDesc(0u, &description);
    return SUCCEEDED(result) ? SphereUI::TextExtent{static_cast<std::int32_t>(description.Width), static_cast<std::int32_t>(description.Height)} : SphereUI::TextExtent{};
}

bool SphereRender::TextureRepository::hasAlpha(std::uint32_t index) {
    resource(index);
    const auto* entry = resolve(index);
    return entry != nullptr && entry->has_alpha;
}

void SphereRender::ModelRepository::initialize() {
    clear();
    parameters.load("models\\mdlparam.txt");
}

void SphereRender::ModelRepository::addFolder(const char* directory) {
    if (directory == nullptr) return;
    const std::filesystem::path folder(directory);
    std::error_code error;
    for (std::filesystem::directory_iterator iterator(folder, error), end; !error && iterator != end; iterator.increment(error)) {
        if (!iterator->is_regular_file(error) || error || resourceNameKey(iterator->path().extension().string()) != ".mdl") continue;
        const auto name = iterator->path().stem().string();
        const auto index = static_cast<std::uint32_t>(entries.size());
        entries.push_back({name, directory, nullptr, {}});
        names.try_emplace(resourceNameKey(name), index);
    }
}

void SphereRender::ModelRepository::finishRegistration() {
    if (entries.size() >= 5000u) throw std::length_error("Model repository exceeds the model ID range");
}

std::int32_t SphereRender::ModelRepository::find(const char* name) const {
    if (name == nullptr) return -1;
    const auto found = names.find(resourceNameKey(name));
    return found == names.end() ? -1 : static_cast<std::int32_t>(found->second);
}

SphereRender::Model* SphereRender::ModelRepository::model(std::uint32_t index) {
    if (index >= entries.size()) throw std::out_of_range("Model repository: invalid model ID");
    auto& entry = entries[index];
    entry.last_used = std::chrono::steady_clock::now();
    if (entry.model == nullptr) entry.model = Model::load(entry.name.c_str(), entry.directory.c_str(), parameters, g_sfera_materials);
    if (++requests_since_scan > 100000u) {
        requests_since_scan = 0u;
        evictUnused();
    }
    return entry.model.get();
}

void SphereRender::ModelRepository::releaseModels() {
    for (auto& entry : entries) entry.model.reset();
}

void SphereRender::ModelRepository::evictUnused(std::chrono::steady_clock::time_point now) {
    if (entries.empty()) return;
    auto& entry = entries[scan_index];
    if (entry.model != nullptr && now - entry.last_used > std::chrono::minutes(15)) entry.model.reset();
    scan_index = (scan_index + 1u) % entries.size();
}

void SphereRender::ModelRepository::clear() {
    entries.clear();
    names.clear();
    request_counts.clear();
    parameters.clear();
    requests_since_scan = 0u;
    scan_index = 0u;
}

void SphereRender::ModelRepository::recordRequest(std::string_view name) {
    ++request_counts[std::string(name)];
}

void SphereRender::ModelRepository::writeRequestStatistics() const {
    if (request_counts.empty()) return;
    auto& log = g_sfera_log_runtime.files[0];
    std::FILE* output = log.open();
    if (output == nullptr) return;
    for (const auto& [name, count] : request_counts) std::fprintf(output, "%s\t%d\n", name.c_str(), static_cast<std::int32_t>(count));
    std::fclose(output);
    log.has_written = 1u;
}

void SphereRender::TextureRepository::load(Entry& entry, std::span<const std::uint8_t> bytes) {
    if (g_sfera_graphics_runtime.d3d_runtime == nullptr) return;
    auto& runtime = *g_sfera_graphics_runtime.d3d_runtime;
    auto* device = runtime.native_device;
    if (device == nullptr || bytes.size() < sizeof(DdsHeader) || bytes.size() > UINT32_MAX) return;
    DdsHeader header{};
    std::memcpy(&header, bytes.data(), sizeof(header));
    if (std::memcmp(header.signature, "DDS ", sizeof(header.signature)) != 0) return;
    const bool cube = (header.extended_capabilities & 0x200u) != 0u;
    entry.has_alpha = cube || header.format.encoding != static_cast<std::uint32_t>(D3DFMT_DXT1);
    HRESULT result;
    if (cube) {
        IDirect3DCubeTexture9* texture = nullptr;
        result = ::D3DXCreateCubeTextureFromFileInMemory(device, bytes.data(), static_cast<UINT>(bytes.size()), &texture);
        if (SUCCEEDED(result)) entry.texture.reset(texture);
    } else {
        IDirect3DTexture9* texture = nullptr;
        constexpr UINT from_file = UINT32_MAX - 2u;
        result = ::D3DXCreateTextureFromFileInMemoryEx(device, bytes.data(), static_cast<UINT>(bytes.size()), 0u, 0u, from_file, 0u, static_cast<D3DFORMAT>(from_file), D3DPOOL_MANAGED, UINT32_MAX, UINT32_MAX, 0u, nullptr, nullptr, &texture);
        if (SUCCEEDED(result)) entry.texture.reset(texture);
    }
    runtime.last_hresult = result;
}


std::uint64_t CShaderMgr::instanceCode(std::string_view filename, bool pixel) {
    std::uint64_t code = pixel ? 0x80u : 0u;
    std::size_t position = 0u;
    for (unsigned pin = 0u; ; ++pin) {
        if (pin == 8u) throw std::invalid_argument("Too many shader pins: " + std::string(filename));
        if (position + 1u >= filename.size()) throw std::invalid_argument("Incomplete shader pin: " + std::string(filename));
        const char tens = filename[position];
        const char units = filename[position + 1u];
        if (tens < '0' || tens > '9' || units < '0' || units > '9') throw std::invalid_argument("Invalid shader pin: " + std::string(filename));
        const auto value = static_cast<std::uint64_t>((tens - '0') * 10 + units - '0');
        code |= value << (pin * 8u);
        position += 2u;
        if (position == filename.size() || filename[position] != '_') return code;
        ++position;
    }
}

std::array<float, 512> CShaderMgr::makeWaveSamples() {
    std::array<float, 10> phases{};
    std::array<float, 10> amplitudes{};
    for (std::size_t harmonic = 0; harmonic < phases.size(); ++harmonic) {
        phases[harmonic] = static_cast<float>(static_cast<double>(std::rand()) / RAND_MAX * 6.2831854820251465);
        amplitudes[harmonic] = static_cast<float>(static_cast<double>(std::rand()) / RAND_MAX + 1.0);
    }
    std::array<float, 512> samples{};
    float peak = 0.0f;
    for (std::size_t sample = 0; sample < samples.size(); ++sample) {
        const float angle = static_cast<float>(sample * 0.012271846644580364);
        for (std::size_t harmonic = 0; harmonic < phases.size(); ++harmonic) {
            const float phase = static_cast<float>((harmonic + 1u) * angle + phases[harmonic]);
            samples[sample] += static_cast<float>(std::sin(phase)) * amplitudes[harmonic];
        }
        peak = std::max(peak, std::abs(samples[sample]));
    }
    if (peak > 0.0f) for (float& sample : samples) sample *= 1.0f / peak;
    return samples;
}

std::array<CShaderMgr::TexelOffset, 16> CShaderMgr::makeDownsampleOffsets(float width, float height) {
    if (width <= 0.0f || height <= 0.0f) throw std::invalid_argument("Shader sampling dimensions must be positive");
    std::array<TexelOffset, 16> offsets{};
    for (unsigned column = 0u; column < 4u; ++column) {
        for (unsigned row = 0u; row < 4u; ++row) offsets[column * 4u + row] = {(1.5f - column) / width, (row - 1.5f) / height};
    }
    return offsets;
}

CShaderMgr::WaterParameters CShaderMgr::waterParameters(float environment, float height) {
    WaterParameters result;
    float reflection_scale = 0.5f;
    if (environment >= 0.34f && environment <= 0.66f) {
        result.specular = 0.35f;
    } else if (environment <= 0.19f || environment >= 0.81f) {
        result.gradient = 1.0f;
        result.specular = 0.15f;
        reflection_scale = 0.3f;
    } else if (environment < 0.34f) {
        const float transition = (environment - 0.19f) / 0.15f;
        result.gradient = 1.0f - transition;
        result.specular = 0.15f + transition * 0.2f;
    } else {
        const float transition = (environment - 0.66f) / 0.15f;
        result.gradient = transition;
        result.specular = 0.35f - transition * 0.2f;
    }
    if (height < 0.0f) result.reflection = static_cast<float>(std::pow(-height, static_cast<double>(0.3f))) * reflection_scale;
    return result;
}

void CShaderMgr::loadFolder(const char* directory, bool pixel) {
    std::error_code error;
    std::filesystem::directory_iterator files(directory, error);
    if (error) return;
    for (const auto& file : files) {
        if (!file.is_regular_file()) continue;
        std::string extension = file.path().extension().string();
        std::transform(extension.begin(), extension.end(), extension.begin(), [](unsigned char character) { return static_cast<char>(std::tolower(character)); });
        if (extension != (pixel ? ".psc" : ".vsc")) continue;
        const std::string filename = file.path().filename().string();
        const std::uint64_t code = instanceCode(filename, pixel);
        auto inserted = variants.try_emplace(code);
        if (!inserted.second) throw std::runtime_error("Duplicate shader pin combination: " + filename);
        inserted.first->second.filename = filename;
    }
}

CShaderMgr::CShaderMgr(CD3D9Device& owner, const char* vertex_path, const char* pixel_path) : vertex_directory(vertex_path), pixel_directory(pixel_path), device(owner) {
    try {
        loadFolder(vertex_directory.c_str(), false);
        loadFolder(pixel_directory.c_str(), true);
        wave_samples = makeWaveSamples();
        downsample_offsets = makeDownsampleOffsets(static_cast<float>(g_sfera_graphics_runtime.display_width), static_cast<float>(g_sfera_graphics_runtime.display_height));
    } catch (const std::exception& error) {
        CSphereError{}.write(error.what());
    }
}

CShaderMgr::Variant::~Variant() {
    if (constants) constants->Release();
    if (pixel_shader) pixel_shader->Release();
}

CShaderMgr::Variant& CShaderMgr::loadVariant(std::uint64_t code) {
    auto found = variants.find(code);
    if (found == variants.end()) {
        CSphereError{}.write(("Unexpected shader pin combination: " + std::to_string(code)).c_str());
        throw std::out_of_range("Shader variant does not exist");
    }
    Variant& variant = found->second;
    if (variant.pixel_shader) return variant;
    const std::string filename = (std::filesystem::path(pixel_directory) / variant.filename).string();
    SferaFileMap file(filename.c_str());
    if (!file.isOpen() || file.size() < sizeof(DWORD) || file.size() % sizeof(DWORD) != 0u) {
        CSphereError{}.write(("Invalid compiled shader: " + filename).c_str());
        throw std::runtime_error("Compiled shader could not be read");
    }
    const DWORD* bytecode = reinterpret_cast<const DWORD*>(file.data());
    device.checkResult(device.native_device->CreatePixelShader(bytecode, &variant.pixel_shader), "CreatePixelShader");
    const HRESULT result = D3DXGetShaderConstantTable(bytecode, &variant.constants);
    device.last_hresult = result;
    if (result != S_OK) CSphereError{}.write(("Cannot read shader constants: " + filename).c_str());
    return variant;
}

void CShaderMgr::Variant::setConstant(CD3D9Device& owner, const char* name, const void* data, std::uint32_t bytes) {
    const char* handle = constants->GetConstantByName(nullptr, name);
    if (!handle) CSphereError{}.write((std::string("Shader constant does not exist: ") + name).c_str());
    const HRESULT result = constants->SetValue(owner.native_device, handle, data, bytes);
    owner.last_hresult = result;
    if (result != S_OK) CSphereError{}.write((std::string("Cannot set shader constant: ") + name).c_str());
}

void CShaderMgr::setPixelShader(std::uint32_t group) {
    if (group == 10u || group == 11u) return;
    if (group > 13u) {
        CSphereError{}.write(("Unknown pixel shader group: " + std::to_string(group)).c_str());
        return;
    }
    std::uint64_t code = 0x80u | group;
    if (group == 0u) {
        code |= static_cast<std::uint64_t>(static_cast<std::uint8_t>(g_sfera_alpha_material_runtime.option_c)) << 8u;
        code |= static_cast<std::uint64_t>(static_cast<std::uint8_t>(g_sfera_alpha_material_runtime.option_a)) << 16u;
        code |= static_cast<std::uint64_t>(g_sfera_alpha_material_runtime.selected_slot != -1) << 24u;
        code |= static_cast<std::uint64_t>(static_cast<std::uint8_t>(g_sfera_alpha_material_runtime.option_b)) << 32u;
    }
    Variant& variant = loadVariant(code);
    device.checkResult(device.native_device->SetPixelShader(variant.pixel_shader), "SetPixelShader");
    if (group == 3u) variant.setConstant(device, "gAlpha", &g_sfera_alpha_material_runtime.alpha[0], sizeof(float));
    if (group == 6u) variant.setConstant(device, "gTexelCoordsDownFilter", downsample_offsets.data(), static_cast<std::uint32_t>(sizeof(downsample_offsets)));
    if (group == 1u) {
        const WaterParameters water = waterParameters(g_sfera_graphics_runtime.environment_factor, g_sfera_view_spatial_runtime.position_offset.y.f32);
        variant.setConstant(device, "gWaterGradientCoefficient", &water.gradient, sizeof(float));
        variant.setConstant(device, "gWaterSpecular", &water.specular, sizeof(float));
        variant.setConstant(device, "gWaterReflectCoefficient", &water.reflection, sizeof(float));
    }
}

CPostEffectsMgr::CPostEffectsMgr(CD3D9Device& owner) : device(owner) {
    const D3DVERTEXELEMENT9 elements[] = {
        {0, 0, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITIONT, 0},
        {0, 16, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0},
        {0, 24, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 1},
        D3DDECL_END()
    };
    device.checkResult(device.native_device->CreateVertexDeclaration(elements, &vertex_declaration), "CreateVertexDeclaration");
}

CPostEffectsMgr::~CPostEffectsMgr() {
    releaseResources();
    if (vertex_declaration) vertex_declaration->Release();
}

void CPostEffectsMgr::restoreResources() {
    if (!enabled) return;
    device.checkResult(device.native_device->TestCooperativeLevel(), "TestCooperativeLevel");
    device.checkResult(device.native_device->CreateTexture(g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height, 1u, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &scene_texture, nullptr), "CreateTexture(scene)");
    device.checkResult(device.native_device->CreateTexture(128u, 128u, 1u, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &temporary_texture, nullptr), "CreateTexture(blur temporary)");
    device.checkResult(device.native_device->CreateTexture(128u, 128u, 1u, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &blur_texture, nullptr), "CreateTexture(blur)");
}

void CPostEffectsMgr::releaseResources() {
    if (blur_texture) blur_texture->Release();
    if (temporary_texture) temporary_texture->Release();
    if (scene_texture) scene_texture->Release();
    if (captured_backbuffer) captured_backbuffer->Release();
    blur_texture = nullptr;
    temporary_texture = nullptr;
    scene_texture = nullptr;
    captured_backbuffer = nullptr;
}

void CPostEffectsMgr::setEnabled(bool value) {
    if (enabled == value) return;
    enabled = value;
    if (enabled) restoreResources();
    else releaseResources();
}

void CPostEffectsMgr::beginCapture() {
    if (!enabled) return;
    device.checkResult(device.native_device->GetRenderTarget(0u, &captured_backbuffer), "GetRenderTarget");
    IDirect3DSurface9* surface = nullptr;
    device.checkResult(scene_texture->GetSurfaceLevel(0u, &surface), "GetSurfaceLevel(scene)");
    device.checkResult(device.native_device->SetRenderTarget(0u, surface), "SetRenderTarget(scene)");
    surface->Release();
}

void CPostEffectsMgr::configureRenderState() {
    device.checkResult(device.native_device->SetRenderState(D3DRS_ZENABLE, FALSE), "SetRenderState(ZENABLE)");
    device.checkResult(device.native_device->SetRenderState(D3DRS_ZWRITEENABLE, FALSE), "SetRenderState(ZWRITEENABLE)");
    for (DWORD sampler = 0u; sampler < 2u; ++sampler) {
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP), "SetSamplerState(ADDRESSU)");
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP), "SetSamplerState(ADDRESSV)");
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_MINFILTER, D3DTEXF_LINEAR), "SetSamplerState(MINFILTER)");
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR), "SetSamplerState(MAGFILTER)");
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_MIPFILTER, D3DTEXF_NONE), "SetSamplerState(MIPFILTER)");
    }
    device.checkResult(device.native_device->SetVertexShader(nullptr), "SetVertexShader");
    device.checkResult(device.native_device->SetVertexDeclaration(vertex_declaration), "SetVertexDeclaration");
}

void CPostEffectsMgr::drawQuad(std::uint32_t width, std::uint32_t height) {
    const float right = static_cast<float>(width) - 0.5f;
    const float bottom = static_cast<float>(height) - 0.5f;
    const ScreenVertex vertices[] = {
        {-0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f},
        {-0.5f, bottom, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f},
        {right, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f},
        {right, bottom, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f}
    };
    device.checkResult(device.native_device->Clear(0u, nullptr, D3DCLEAR_TARGET, 0xff000000u, 1.0f, 0u), "Clear");
    device.checkResult(device.native_device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2u, vertices, sizeof(ScreenVertex)), "DrawPrimitiveUP(post effects)");
}

void CPostEffectsMgr::renderToTexture(IDirect3DTexture9* target) {
    IDirect3DSurface9* surface = nullptr;
    D3DSURFACE_DESC description{};
    device.checkResult(target->GetSurfaceLevel(0u, &surface), "GetSurfaceLevel");
    device.checkResult(surface->GetDesc(&description), "GetDesc");
    device.checkResult(device.native_device->SetRenderTarget(0u, surface), "SetRenderTarget");
    surface->Release();
    drawQuad(description.Width, description.Height);
}

void CPostEffectsMgr::blur() {
    device.checkResult(device.native_device->SetTexture(0u, scene_texture), "SetTexture(scene)");
    device.shaders->setPixelShader(6u);
    renderToTexture(blur_texture);
    device.checkResult(device.native_device->SetTexture(0u, blur_texture), "SetTexture(blur)");
    device.shaders->setPixelShader(7u);
    renderToTexture(temporary_texture);
    device.checkResult(device.native_device->SetTexture(0u, temporary_texture), "SetTexture(blur temporary)");
    device.shaders->setPixelShader(8u);
    renderToTexture(blur_texture);
}

void CPostEffectsMgr::compose() {
    if (!enabled) return;
    configureRenderState();
    blur();
    device.checkResult(device.native_device->SetRenderTarget(0u, captured_backbuffer), "SetRenderTarget(backbuffer)");
    captured_backbuffer->Release();
    captured_backbuffer = nullptr;
    device.checkResult(device.native_device->SetTexture(0u, scene_texture), "SetTexture(scene)");
    device.checkResult(device.native_device->SetTexture(1u, blur_texture), "SetTexture(blur)");
    device.shaders->setPixelShader(9u);
    drawQuad(g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height);
    for (DWORD sampler = 0u; sampler < 2u; ++sampler) {
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP), "SetSamplerState(ADDRESSU)");
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP), "SetSamplerState(ADDRESSV)");
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_MINFILTER, device.min_filter), "SetSamplerState(MINFILTER)");
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_MAGFILTER, device.mag_filter), "SetSamplerState(MAGFILTER)");
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_MIPFILTER, device.mip_filter), "SetSamplerState(MIPFILTER)");
    }
    device.checkResult(device.native_device->SetRenderState(D3DRS_ZENABLE, TRUE), "SetRenderState(ZENABLE)");
    device.checkResult(device.native_device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE), "SetRenderState(ZWRITEENABLE)");
}


CD3D9Device::CD3D9Device() : vertices32(*this, 32u, D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1), vertices28(*this, 28u, D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1), indices_primary(*this), indices_secondary(*this) {
    api = Direct3DCreate9(D3D_SDK_VERSION);
    if (api == nullptr) { CSphereError error; error.write("CD3D9Device::CD3D9Device() => Direct3DCreate9() failed."); }
}

CD3D9Device::~CD3D9Device() {
    post_effects.reset();
    shaders.reset();
    reflection_target.reset();
    minimap_target.reset();
    vertices32.buffer.reset();
    vertices28.buffer.reset();
    indices_primary.buffer.reset();
    indices_secondary.buffer.reset();
    for (auto* resource : unmanaged_resources) { resource->releaseResource(); resource->device = nullptr; }
    unmanaged_resources.clear();
    if (sync_query != nullptr) sync_query->Release();
    if (native_device != nullptr) native_device->Release();
    if (api != nullptr) api->Release();
}

HRESULT CD3D9Device::checkResult(HRESULT result, const char* operation) {
    last_hresult = result;
    if (FAILED(result)) {
        char message[512];
        std::snprintf(message, sizeof(message), "%s failed (HRESULT 0x%08X)", operation, static_cast<unsigned int>(result));
        CSphereError error;
        error.write(message);
    }
    return result;
}

void CD3D9Device::enumerateDisplayModes(bool windowed) {
    if (api == nullptr) throw std::runtime_error("Graphics interface is unavailable");
    display_modes.clear();
    for (const D3DFORMAT format : {D3DFMT_R5G6B5, D3DFMT_X8R8G8B8}) {
        const std::uint32_t depth_bits = format == D3DFMT_X8R8G8B8 ? 32u : 16u;
        const UINT count = api->GetAdapterModeCount(D3DADAPTER_DEFAULT, format);
        for (UINT index = 0u; index < count; ++index) {
            D3DDISPLAYMODE mode{};
            api->EnumAdapterModes(D3DADAPTER_DEFAULT, format, index, &mode);
            if (mode.Width < 800u || mode.Height < 600u) continue;
            if (windowed && mode.Height >= g_sfera_recovered_static_runtime.scene_state_07) continue;
            if (!supportsDisplayMode(mode.Width, mode.Height, depth_bits)) display_modes.push_back({mode.Width, mode.Height, depth_bits});
        }
    }
    if (display_modes.empty()) { CSphereError error; error.write("Found ZERO video modes!"); }
}

bool CD3D9Device::supportsDisplayMode(std::uint32_t width, std::uint32_t height, std::uint32_t depth_bits) const {
    return std::any_of(display_modes.begin(), display_modes.end(), [=](const SphereUI::DisplayMode& mode) { return mode.width == width && mode.height == height && mode.depth == depth_bits; });
}

void CD3D9Device::selectBackBufferFormat(const D3DDISPLAYMODE& display, bool windowed, D3DFORMAT& format) {
    last_hresult = api->CheckDeviceType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, windowed ? display.Format : format, format, windowed);
    if (SUCCEEDED(last_hresult)) return;
    format = D3DFMT_A8R8G8B8;
    for (D3DFORMAT candidate : {D3DFMT_A8R8G8B8, D3DFMT_R8G8B8, D3DFMT_A8R3G3B2, D3DFMT_X1R5G5B5, D3DFMT_A1R5G5B5, D3DFMT_X4R4G4B4}) {
        last_hresult = api->CheckDeviceType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, windowed ? display.Format : candidate, candidate, windowed);
        if (SUCCEEDED(last_hresult)) { format = candidate; return; }
    }
    checkResult(last_hresult, windowed ? "CheckDeviceType(windowed)" : "CheckDeviceType(fullscreen)");
}

void CD3D9Device::selectDepthFormat(D3DFORMAT adapter_format, D3DFORMAT& format) {
    format = D3DFMT_D32;
    for (D3DFORMAT candidate : {D3DFMT_D32, D3DFMT_D24S8, D3DFMT_D24X8, D3DFMT_D24X4S4, D3DFMT_D16_LOCKABLE, D3DFMT_D16, D3DFMT_D15S1}) {
        if (SUCCEEDED(api->CheckDeviceFormat(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, adapter_format, D3DUSAGE_DEPTHSTENCIL, D3DRTYPE_SURFACE, candidate))) { format = candidate; return; }
    }
}

void CD3D9Device::initialize(HWND window, std::uint32_t width, std::uint32_t height, std::uint32_t depth_bits, bool windowed) {
    if (depth_bits != 16u && depth_bits != 32u) { depth_bits = 32u; g_sfera_graphics_display_depth_bits = depth_bits; }
    width = std::max(width, 800u);
    height = std::max(height, 600u);
    enumerateDisplayModes(windowed);
    if (!supportsDisplayMode(width, height, g_sfera_graphics_display_depth_bits)) {
        width = static_cast<std::uint32_t>(::GetSystemMetrics(SM_CXSCREEN));
        height = static_cast<std::uint32_t>(::GetSystemMetrics(SM_CYSCREEN));
        g_sfera_graphics_runtime.display_width = width;
        g_sfera_graphics_runtime.display_height = height;
    }
    D3DDISPLAYMODE display{};
    checkResult(api->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &display), "GetAdapterDisplayMode");
    D3DFORMAT back_buffer = depth_bits == 32u ? D3DFMT_X8R8G8B8 : D3DFMT_R5G6B5;
    selectBackBufferFormat(display, windowed, back_buffer);
    capabilities = {};
    api->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &capabilities);
    DWORD behavior = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
    if ((capabilities.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) != 0u) behavior = D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_FPU_PRESERVE | ((capabilities.DevCaps & D3DDEVCAPS_PUREDEVICE) != 0u ? D3DCREATE_PUREDEVICE : 0u);
    supports_post_effects = capabilities.VertexShaderVersion >= D3DVS_VERSION(2, 0) && capabilities.PixelShaderVersion >= D3DPS_VERSION(2, 0);
    D3DFORMAT depth_format{};
    selectDepthFormat(back_buffer, depth_format);
    presentation = {};
    presentation.BackBufferWidth = width;
    presentation.BackBufferHeight = height;
    presentation.BackBufferFormat = back_buffer;
    presentation.BackBufferCount = 1u;
    presentation.MultiSampleType = D3DMULTISAMPLE_NONE;
    presentation.SwapEffect = D3DSWAPEFFECT_DISCARD;
    presentation.hDeviceWindow = window;
    presentation.Windowed = windowed;
    presentation.EnableAutoDepthStencil = TRUE;
    presentation.AutoDepthStencilFormat = depth_format;
    presentation.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
    presentation.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
    checkResult(api->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window, behavior, &presentation, &native_device), "CreateDevice");
    initializeRenderState();
}

void CD3D9Device::applyFiltering() {
    min_filter = D3DTEXF_ANISOTROPIC;
    mag_filter = D3DTEXF_LINEAR;
    mip_filter = D3DTEXF_LINEAR;
    for (DWORD stage = 0u; stage < 4u; ++stage) {
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_MINFILTER, min_filter), "SetSamplerState(MINFILTER)");
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_MAGFILTER, mag_filter), "SetSamplerState(MAGFILTER)");
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_MIPFILTER, mip_filter), "SetSamplerState(MIPFILTER)");
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_MAXANISOTROPY, 4u), "SetSamplerState(MAXANISOTROPY)");
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP), "SetSamplerState(ADDRESSU)");
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP), "SetSamplerState(ADDRESSV)");
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_ADDRESSW, D3DTADDRESS_WRAP), "SetSamplerState(ADDRESSW)");
    }
}

void CD3D9Device::initializeRenderState() {
    checkResult(native_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW), "SetRenderState(CULLMODE)");
    checkResult(native_device->SetRenderState(D3DRS_ZENABLE, TRUE), "SetRenderState(ZENABLE)");
    checkResult(native_device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE), "SetRenderState(ZWRITEENABLE)");
    checkResult(native_device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL), "SetRenderState(ALPHAFUNC)");
    checkResult(native_device->SetRenderState(D3DRS_ALPHAREF, 1u), "SetRenderState(ALPHAREF)");
    checkResult(native_device->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE), "SetRenderState(ALPHATESTENABLE)");
    checkResult(native_device->SetRenderState(D3DRS_FOGENABLE, FALSE), "SetRenderState(FOGENABLE)");
    checkResult(native_device->SetRenderState(D3DRS_LIGHTING, FALSE), "SetRenderState(LIGHTING)");
    applyFiltering();
    const D3DVIEWPORT9 viewport{0u, 0u, presentation.BackBufferWidth, presentation.BackBufferHeight, 0.0f, 1.0f};
    checkResult(native_device->SetViewport(&viewport), "SetViewport");
    checkResult(native_device->SetRenderState(D3DRS_FOGTABLEMODE, D3DFOG_NONE), "SetRenderState(FOGTABLEMODE)");
    checkResult(native_device->SetRenderState(D3DRS_FOGVERTEXMODE, D3DFOG_LINEAR), "SetRenderState(FOGVERTEXMODE)");
    checkResult(native_device->SetRenderState(D3DRS_RANGEFOGENABLE, TRUE), "SetRenderState(RANGEFOGENABLE)");
    checkResult(native_device->SetRenderState(D3DRS_FOGSTART, 80u), "SetRenderState(FOGSTART)");
    checkResult(native_device->SetRenderState(D3DRS_FOGEND, 150u), "SetRenderState(FOGEND)");
    checkResult(native_device->SetRenderState(D3DRS_LIGHTING, TRUE), "SetRenderState(LIGHTING)");
    setWhiteMaterial(1.0f);
}

void CD3D9Device::setTransform(D3DTRANSFORMSTATETYPE kind, const D3DMATRIX& matrix) {
    const HRESULT result = native_device->SetTransform(kind, &matrix);
    last_hresult = result;
    if (kind == D3DTS_WORLD) world_transform = matrix;
    checkResult(result, "SetTransform");
}

void CD3D9Device::setAlphaBlending(D3DBLEND source, D3DBLEND destination) {
    native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    native_device->SetRenderState(D3DRS_SRCBLEND, source);
    native_device->SetRenderState(D3DRS_DESTBLEND, destination);
}

void CD3D9Device::setColorOperation(std::uint32_t stage, D3DTEXTUREOP operation, std::uint32_t first, std::uint32_t second) {
    native_device->SetTextureStageState(stage, D3DTSS_COLOROP, operation);
    native_device->SetTextureStageState(stage, D3DTSS_COLORARG1, first);
    native_device->SetTextureStageState(stage, D3DTSS_COLORARG2, second);
}

void CD3D9Device::setAlphaOperation(std::uint32_t stage, D3DTEXTUREOP operation, std::uint32_t first, std::uint32_t second) {
    native_device->SetTextureStageState(stage, D3DTSS_ALPHAOP, operation);
    native_device->SetTextureStageState(stage, D3DTSS_ALPHAARG1, first);
    native_device->SetTextureStageState(stage, D3DTSS_ALPHAARG2, second);
}

void CD3D9Device::setWhiteMaterial(float alpha) {
    D3DMATERIAL9 material{};
    material.Diffuse = {1.0f, 1.0f, 1.0f, alpha};
    material.Ambient = {1.0f, 1.0f, 1.0f, 0.0f};
    checkResult(native_device->SetMaterial(&material), "SetMaterial");
}

void CD3D9Device::drawBuffer(IDirect3DVertexBuffer9* vertices, D3DPRIMITIVETYPE topology, std::uint32_t flags, std::int32_t base_vertex, std::uint32_t vertex_count, IDirect3DIndexBuffer9* indices, std::uint32_t index_count, std::uint32_t start_index, std::uint32_t stride) {
    if (native_device == nullptr) return;
    checkResult(native_device->SetRenderState(D3DRS_CULLMODE, (flags & two_sided) != 0u ? D3DCULL_NONE : D3DCULL_CW), "SetRenderState(CULLMODE)");
    checkResult(native_device->SetRenderState(D3DRS_LIGHTING, (flags & lighting) != 0u), "SetRenderState(LIGHTING)");
    checkResult(native_device->SetRenderState(D3DRS_CLIPPING, (flags & disable_clipping) == 0u), "SetRenderState(CLIPPING)");
    D3DVERTEXBUFFER_DESC description{};
    vertices->GetDesc(&description);
    checkResult(native_device->SetFVF(description.FVF), "SetFVF");
    checkResult(native_device->SetStreamSource(0u, vertices, 0u, stride), "SetStreamSource");
    if (index_count != 0u) {
        if (indices == nullptr && indices_primary.buffer != nullptr) indices = indices_primary.buffer->native_buffer;
        checkResult(native_device->SetIndices(indices), "SetIndices");
        checkResult(native_device->DrawIndexedPrimitive(topology, base_vertex, 0u, vertex_count, start_index, index_count / 3u), "DrawIndexedPrimitive");
    } else {
        checkResult(native_device->DrawPrimitive(topology, static_cast<UINT>(base_vertex), vertex_count / 3u), "DrawPrimitive");
    }
}

void CD3D9Device::drawVertices(D3DPRIMITIVETYPE topology, std::uint32_t flags, const void* vertices, std::uint32_t vertex_count, const std::uint16_t* indices, std::uint32_t index_count, std::uint32_t stride) {
    if (native_device == nullptr) return;
    checkResult(native_device->SetRenderState(D3DRS_LIGHTING, (flags & lighting) != 0u), "SetRenderState(LIGHTING)");
    checkResult(native_device->SetRenderState(D3DRS_CULLMODE, (flags & two_sided) != 0u ? D3DCULL_NONE : D3DCULL_CW), "SetRenderState(CULLMODE)");
    checkResult(native_device->SetRenderState(D3DRS_CLIPPING, (flags & disable_clipping) == 0u), "SetRenderState(CLIPPING)");
    if (index_count != 0u) {
        checkResult(native_device->DrawIndexedPrimitiveUP(topology, 0u, vertex_count, index_count / 3u, indices, D3DFMT_INDEX16, vertices, stride), "DrawIndexedPrimitiveUP");
    } else if (topology == D3DPT_TRIANGLEFAN) {
        if (static_cast<std::int32_t>(vertex_count) > 2) checkResult(native_device->DrawPrimitiveUP(topology, vertex_count - 2u, vertices, stride), "DrawPrimitiveUP");
    } else {
        checkResult(native_device->DrawPrimitiveUP(topology, static_cast<std::int32_t>(vertex_count) / 3, vertices, stride), "DrawPrimitiveUP");
    }
}

void CD3D9Device::releaseResources() {
    if (sync_query != nullptr) { sync_query->Release(); sync_query = nullptr; }
    if (post_effects != nullptr) post_effects->releaseResources();
    for (auto* resource : unmanaged_resources) resource->releaseResource();
}

void CD3D9Device::restoreResources() {
    initializeRenderState();
    last_hresult = native_device->CreateQuery(D3DQUERYTYPE_EVENT, &sync_query);
    if (last_hresult != S_OK) {
        g_sfera_log_runtime.files[0].write("Render err: cant create query:");
        g_sfera_log_runtime.files[0].write(static_cast<std::int32_t>(last_hresult));
    }
    if (post_effects != nullptr) post_effects->restoreResources();
    for (auto* resource : unmanaged_resources) resource->restoreResource();
    vertices32.position = vertices28.position = indices_primary.position = indices_secondary.position = 0u;
    vertices32.capacity = vertices28.capacity = indices_primary.capacity = indices_secondary.capacity = 0u;
    g_sfera_light_runtime.invalidateActiveLights();
    g_sfera_light_runtime.disableActiveLights();
}

void CD3D9Device::waitForGpu() {
    if (sync_query == nullptr || sync_query->Issue(D3DISSUE_END) == D3DERR_DEVICELOST) return;
    while (sync_query->GetData(nullptr, 0u, D3DGETDATA_FLUSH) == S_FALSE) ::Sleep(0u);
}

UnmanagedResourceTexture& CD3D9Device::minimapTexture() {
    if (minimap_target == nullptr) minimap_target = std::make_unique<UnmanagedResourceTexture>(*this, 256u, 256u, 1u, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT);
    return *minimap_target;
}

bool CD3D9Device::beginScene() {
    last_hresult = native_device->TestCooperativeLevel();
    if (last_hresult == D3DERR_DEVICELOST) return false;
    if (last_hresult == D3DERR_DEVICENOTRESET) {
        releaseResources();
        checkResult(native_device->Reset(&presentation), "Reset");
        restoreResources();
    } else {
        checkResult(last_hresult, "TestCooperativeLevel");
    }
    checkResult(native_device->BeginScene(), "BeginScene");
    return true;
}

UnmanagedResourceBase::UnmanagedResourceBase(CD3D9Device& owner, D3DPOOL pool) : device(&owner), registered(pool != D3DPOOL_MANAGED) {
    if (registered) owner.unmanaged_resources.push_back(this);
}

UnmanagedResourceBase::~UnmanagedResourceBase() {
    if (registered && device != nullptr) std::erase(device->unmanaged_resources, this);
}

UnmanagedResourceVB::UnmanagedResourceVB(CD3D9Device& device, std::uint32_t length, std::uint32_t usage, std::uint32_t fvf, D3DPOOL pool) : UnmanagedResourceBase(device, pool), length(length), usage(usage), fvf(fvf), pool(pool) { restoreResource(); device.checkResult(device.last_hresult, "CreateVertexBuffer"); }
UnmanagedResourceVB::~UnmanagedResourceVB() { releaseResource(); }
void UnmanagedResourceVB::releaseResource() { if (native_buffer != nullptr) { native_buffer->Release(); native_buffer = nullptr; } }
void UnmanagedResourceVB::restoreResource() {
    if (native_buffer == nullptr && device != nullptr && device->native_device != nullptr) device->last_hresult = device->native_device->CreateVertexBuffer(length, usage, fvf, pool, &native_buffer, nullptr);
}

UnmanagedResourceIB::UnmanagedResourceIB(CD3D9Device& device, std::uint32_t length, std::uint32_t usage, D3DFORMAT format, D3DPOOL pool) : UnmanagedResourceBase(device, pool), length(length), usage(usage), format(format), pool(pool) { restoreResource(); device.checkResult(device.last_hresult, "CreateIndexBuffer"); }
UnmanagedResourceIB::~UnmanagedResourceIB() { releaseResource(); }
void UnmanagedResourceIB::releaseResource() { if (native_buffer != nullptr) { native_buffer->Release(); native_buffer = nullptr; } }
void UnmanagedResourceIB::restoreResource() {
    if (native_buffer == nullptr && device != nullptr && device->native_device != nullptr) device->last_hresult = device->native_device->CreateIndexBuffer(length, usage, format, pool, &native_buffer, nullptr);
}

UnmanagedResourceTexture::UnmanagedResourceTexture(CD3D9Device& device, std::uint32_t width, std::uint32_t height, std::uint32_t levels, std::uint32_t usage, D3DFORMAT format, D3DPOOL pool) : UnmanagedResourceBase(device, pool), width(width), height(height), levels(levels), usage(usage), format(format), pool(pool) { restoreResource(); device.checkResult(device.last_hresult, "D3DXCreateTexture"); restore_marker = false; }
UnmanagedResourceTexture::~UnmanagedResourceTexture() { releaseResource(); }
void UnmanagedResourceTexture::releaseResource() { if (native_texture != nullptr) { native_texture->Release(); native_texture = nullptr; } }
void UnmanagedResourceTexture::restoreResource() {
    if (native_texture == nullptr && device != nullptr && device->native_device != nullptr) device->last_hresult = D3DXCreateTexture(device->native_device, width, height, levels, usage, format, pool, &native_texture);
    if (pool != D3DPOOL_MANAGED) restore_marker = true;
}

DynamicVertexStream::DynamicVertexStream(CD3D9Device& device, std::uint32_t stride, std::uint32_t fvf) : device(device), stride(stride), fvf(fvf) {}
std::byte* DynamicVertexStream::lock(std::int32_t count) {
    if (count < 0) return nullptr;
    const auto requested = static_cast<std::uint32_t>(count);
    if (requested > capacity) {
        buffer.reset();
        capacity = requested + requested / 4u;
        buffer = std::make_unique<UnmanagedResourceVB>(device, capacity * stride, D3DUSAGE_DYNAMIC, fvf, D3DPOOL_DEFAULT);
        position = 0u;
    }
    if (buffer == nullptr) return nullptr;
    DWORD flags = D3DLOCK_NOOVERWRITE;
    if (static_cast<std::int32_t>(capacity - position) < count) { flags = D3DLOCK_DISCARD; position = 0u; }
    void* data = nullptr;
    device.checkResult(buffer->native_buffer->Lock(0u, 0u, &data, flags), "VertexBuffer::Lock");
    return static_cast<std::byte*>(data) + position * stride;
}

DynamicIndexStream::DynamicIndexStream(CD3D9Device& device) : device(device) {}
std::uint16_t* DynamicIndexStream::lock(std::int32_t count) {
    if (count < 0) return nullptr;
    const auto requested = static_cast<std::uint32_t>(count);
    if (requested > capacity) {
        buffer.reset();
        capacity = requested + requested / 4u;
        buffer = std::make_unique<UnmanagedResourceIB>(device, capacity * sizeof(std::uint16_t), D3DUSAGE_DYNAMIC, D3DFMT_INDEX16, D3DPOOL_DEFAULT);
        position = 0u;
    }
    if (buffer == nullptr) return nullptr;
    DWORD flags = D3DLOCK_NOOVERWRITE;
    if (static_cast<std::int32_t>(capacity - position) < count) { flags = D3DLOCK_DISCARD; position = 0u; }
    void* data = nullptr;
    device.checkResult(buffer->native_buffer->Lock(0u, 0u, &data, flags), "IndexBuffer::Lock");
    return static_cast<std::uint16_t*>(data) + position;
}

void SferaLightRuntime::invalidateActiveLights() {
    if (auto* values = active_handles.dataAs<std::uint32_t>(); values != nullptr) std::fill_n(values, std::min(active_handles.capacity, 31u), 0u);
    g_sfera_main_command_state_runtime.light_update_counter = 0u;
}

void SferaLightRuntime::disableActiveLights() {
    auto* owner = g_sfera_graphics_runtime.d3d_runtime.get();
    for (std::uint32_t index = 1u; index < 31u; ++index) {
        auto* active = active_handles.element<std::uint32_t>(index);
        if (active == nullptr || *active == 0u) continue;
        --g_sfera_main_command_state_runtime.light_update_counter;
        *active = 0u;
        owner->checkResult(owner->native_device->LightEnable(index, FALSE), "LightEnable");
    }
}


std::FILE* SferaLogFileRuntime::open() const {
    std::FILE* file = nullptr;
    const bool named = path.text[0] != '\0';
    const char* mode = named && truncate_on_first_write == 1u && has_written == 0u ? "wt" : "at";
#if defined(_MSC_VER)
    if (fopen_s(&file, named ? path.text : "ErrorTest.log", mode) != 0) return nullptr;
#else
    file = std::fopen(named ? path.text : "ErrorTest.log", mode);
#endif
    return file;
}

void SferaLogFileRuntime::write(const char* text) {
    if (std::FILE* file = open()) {
        std::fputs(text, file);
        std::fflush(file);
        std::fclose(file);
        has_written = 1u;
    }
}

void SferaLogFileRuntime::write(std::int32_t number) {
    const std::string line = std::to_string(number) + '\n';
    write(line.c_str());
}

void SferaGraphicsRuntime::initializeWater() {
    d3d_runtime->reflection_target = std::make_unique<UnmanagedResourceTexture>(*d3d_runtime, 256u, 256u, 1u, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT);
    water_materials[1] = {1u, 1u, 0.7f, 0.4f, 0.15f, 0.12f};
    water_materials[2] = {2u, 2u, 0.6f, 0.2f, 0.2f, 0.02f};
    water_materials[3] = {1u, 2u, 0.6f, 0.33f, 0.23f, 0.08f};
    water_materials[4] = {2u, 2u, 0.7f, 0.35f, 0.2f, 0.06f};
    water_materials[5] = {3u, 3u, 0.8f, 0.5f, 0.1f, 0.08f};
    water_materials[6] = {4u, 4u, 1.0f, 0.45f, 0.0f, 0.04f};
    water_materials[7] = {3u, 3u, 0.6f, 0.4f, 0.1f, 0.04f};
}

void SferaGraphicsRuntime::initialize() {
    d3d_runtime = std::make_unique<CD3D9Device>();
    auto& device = *d3d_runtime;
    device.initialize(reinterpret_cast<HWND>(static_cast<std::uintptr_t>(g_sfera_window_runtime.main_window)), display_width, display_height, g_sfera_graphics_display_depth_bits, g_sfera_window_runtime.windowed != 0u);
    if (device.supports_post_effects) {
        device.post_effects = std::make_unique<CPostEffectsMgr>(device);
        device.post_effects->setEnabled(true);
    }
    g_sfera_textures.initialize();
    g_sfera_files.setErrorReporting(false);
    const bool debug_assets = g_sfera_files.fileSize("__debug.mbc") != -1;
    g_sfera_files.setErrorReporting(true);
    if (debug_assets) g_sfera_textures.addFolder("debug\\pics\\");
    g_sfera_textures.addFolder("landscape\\");
    if (g_sfera_client_config_runtime.state_20 != 0u) g_sfera_textures.addFolder("landscape_hr\\");
    if (g_sfera_client_config_runtime.state_21 != 0u) g_sfera_textures.addFolder("landscape_ph\\");
    if (g_sfera_client_config_runtime.state_22 != 0u) g_sfera_textures.addFolder("landscape_rd\\");
    g_sfera_textures.addFolder("models\\textures\\");
    if (g_sfera_client_config_runtime.state_20 != 0u) g_sfera_textures.addFolder("models_hr\\textures\\");
    if (g_sfera_client_config_runtime.state_21 != 0u) g_sfera_textures.addFolder("models_ph\\textures\\");
    if (g_sfera_client_config_runtime.state_22 != 0u) g_sfera_textures.addFolder("models_rd\\textures\\");
    g_sfera_textures.addFolder("textures\\");
    g_sfera_textures.addFolder("textures\\fx\\");
    g_sfera_textures.addFolder("textures\\emblems\\");
    g_sfera_textures.addFolder("xadd\\");
    g_sfera_textures.addFolder("players\\");
    g_sfera_textures.finishRegistration();
    device.checkResult(device.native_device->SetRenderState(D3DRS_LIGHTING, TRUE), "SetRenderState(LIGHTING)");
    device.checkResult(device.native_device->SetRenderState(D3DRS_SPECULARENABLE, FALSE), "SetRenderState(SPECULARENABLE)");
    device.setWhiteMaterial(1.0f);
    device.checkResult(device.native_device->SetRenderState(D3DRS_FOGVERTEXMODE, D3DFOG_LINEAR), "SetRenderState(FOGVERTEXMODE)");
    device.checkResult(device.native_device->SetRenderState(D3DRS_RANGEFOGENABLE, TRUE), "SetRenderState(RANGEFOGENABLE)");
    device.checkResult(device.native_device->SetRenderState(D3DRS_FOGSTART, std::bit_cast<DWORD>(50.0f)), "SetRenderState(FOGSTART)");
    device.checkResult(device.native_device->SetRenderState(D3DRS_FOGEND, std::bit_cast<DWORD>(100.0f)), "SetRenderState(FOGEND)");
    device.vertices32.capacity = 30000u;
    device.vertices32.buffer = std::make_unique<UnmanagedResourceVB>(device, device.vertices32.capacity * 32u, D3DUSAGE_DYNAMIC, D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1, D3DPOOL_DEFAULT);
    device.vertices28.capacity = 30000u;
    device.vertices28.buffer = std::make_unique<UnmanagedResourceVB>(device, device.vertices28.capacity * 28u, D3DUSAGE_DYNAMIC, D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1, D3DPOOL_DEFAULT);
    device.indices_primary.capacity = 5000u;
    device.indices_primary.buffer = std::make_unique<UnmanagedResourceIB>(device, device.indices_primary.capacity * 2u, D3DUSAGE_DYNAMIC, D3DFMT_INDEX16, D3DPOOL_DEFAULT);
    device.indices_secondary.capacity = 5000u;
    device.indices_secondary.buffer = std::make_unique<UnmanagedResourceIB>(device, device.indices_secondary.capacity * 2u, D3DUSAGE_DYNAMIC, D3DFMT_INDEX16, D3DPOOL_DEFAULT);
    device.last_hresult = device.native_device->CreateQuery(D3DQUERYTYPE_EVENT, &device.sync_query);
    if (device.last_hresult != S_OK) {
        g_sfera_log_runtime.files[0].write("Render err: cant create query:");
        g_sfera_log_runtime.files[0].write(static_cast<std::int32_t>(device.last_hresult));
    }
    device.checkResult(device.native_device->Clear(0u, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xFF000000u, 1.0f, 0u), "Clear");
    initializeWater();
    device.shaders = std::make_unique<CShaderMgr>(device, "Shaders\\Vertex\\", "Shaders\\Pixel\\");
}

