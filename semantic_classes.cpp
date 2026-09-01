#include "semantic_classes.h"
#include "semantic_static.h"
#include "lifted_functions.h"
#include "import_bridge.h"
#include <algorithm>
#include <array>
#include <bit>
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
#include <limits>
#include <string>
#include <vector>
namespace {
    template <class T> T* ptr32(std::uint32_t address) { return reinterpret_cast<T*>(static_cast<std::uintptr_t>(address)); }
    using SemanticLiftTarget = void (*)(LiftCpu*, std::uint32_t);
    template <class T> void semantic_dispatch(T* self, LiftCpu* cpu, SemanticLiftTarget target) { cpu->ecx = address32(self); lifted::lift_push32(cpu, lifted::LIFT_RETURN_SENTINEL); target(cpu, lifted::LIFT_RETURN_SENTINEL); }
    struct BoundUiEventHandler { std::uint32_t window; SphereUI::WindowEventHandler handler; };
    std::vector<BoundUiEventHandler>& bound_ui_event_handlers() { static std::vector<BoundUiEventHandler> handlers; return handlers; }
    SemanticLiftTarget ui_event_target(SphereUI::WindowEventHandler handler) { switch (handler) { case SphereUI::WindowEventHandler::description: return lifted::sfera_sub_004A2000; case SphereUI::WindowEventHandler::help: return lifted::sfera_sub_004B9540; case SphereUI::WindowEventHandler::authors: return lifted::sfera_sub_004C9C30; case SphereUI::WindowEventHandler::quit: return lifted::sfera_sub_004C9C40; case SphereUI::WindowEventHandler::sound_options: return lifted::sfera_sub_004CA180; case SphereUI::WindowEventHandler::control_options: return lifted::sfera_sub_004CA530; case SphereUI::WindowEventHandler::interface_options: return lifted::sfera_sub_004CABD0; case SphereUI::WindowEventHandler::graphics_options: return lifted::sfera_sub_004CB950; case SphereUI::WindowEventHandler::options: return lifted::sfera_sub_004CD0D0; case SphereUI::WindowEventHandler::font_options: return lifted::sfera_sub_004CD1F0; case SphereUI::WindowEventHandler::none: return nullptr; } return nullptr; }
    SphereUI::WindowEventHandler bound_ui_event_handler(const SphereUI::Window* window) { const std::uint32_t address = address32(window); for (const auto& binding : bound_ui_event_handlers()) if (binding.window == address) return binding.handler; return SphereUI::WindowEventHandler::none; }
    [[noreturn]] void semantic_abi_abstract_call(void* self, LiftCpu* cpu) { if (cpu != nullptr) cpu->ecx = address32(self); lifted::lift_trap(cpu, cpu ? cpu->eip : 0u, "abstract ABI method called"); }
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
    const char* simple_parser_line(const SferaSimpleParser& parser, std::int32_t index) {
        if (parser.line_table == 0u || index < 0 || index >= static_cast<std::int32_t>(parser.line_count)) return nullptr;
        return ptr32<const char>(ptr32<const std::uint32_t>(parser.line_table)[index]);
    }
    void simple_parser_copy_rest(const char* source, const char* end, char* output, std::size_t capacity) {
        if (capacity == 0u) return;
        std::size_t n = 0u;
        while (source < end && n + 1u < capacity) output[n++] = *source++;
        output[n] = '\0';
    }
    std::ifstream simple_parser_open_file(const char* filename) {
        if (filename == nullptr || *filename == '\0') return {};
        std::ifstream stream(filename, std::ios::binary | std::ios::ate);
        if (stream.is_open() || std::strchr(filename, '\\') != nullptr || g_sfera_file_runtime.search_paths.data == 0u) return stream;
        const auto* paths = ptr32<const std::uint32_t>(g_sfera_file_runtime.search_paths.data);
        const std::uint32_t count = std::min(g_sfera_file_runtime.search_path_count, g_sfera_file_runtime.search_paths.capacity);
        for (std::uint32_t index = 0u; index < count; ++index) {
            const char* prefix = ptr32<const char>(paths[index]);
            if (prefix == nullptr) continue;
            std::string path(prefix);
            path += filename;
            stream = std::ifstream(path, std::ios::binary | std::ios::ate);
            if (stream.is_open()) return stream;
        }
        return {};
    }
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
    std::ifstream stream = simple_parser_open_file(filename);
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
        const char* cursor = firstToken(simple_parser_line(*this, line_index));
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
            const char* next = firstToken(simple_parser_line(*this, open_line));
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
        const char* first = firstToken(simple_parser_line(*this, line_index));
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
        const char* first = firstToken(simple_parser_line(*this, line_index));
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
        const char* line = simple_parser_line(*this, line_index);
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
        const char* line = simple_parser_line(*this, line_index);
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
    char* parsed = reinterpret_cast<char*>(g_sfera_config_parse_scratch_runtime.token);
    simple_parser_copy_token_bounded(value_text, parsed, sizeof(g_sfera_config_parse_scratch_runtime.token));
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
    effect->resource_id = g_sfera_texture_registry_runtime.findTexture("fx_flare");
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
    effect->resource_id = g_sfera_texture_registry_runtime.findTexture("fx_light");
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
    effect->resource_id = g_sfera_texture_registry_runtime.findTexture("fx_blade");
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
        const SferaEffectVec3F viewer{g_sfera_effect_manager.viewer_position.x, g_sfera_effect_manager.viewer_position.y, g_sfera_effect_manager.viewer_position.z};
        const SferaEffectVec3F to_viewer = vec_sub(center, viewer);
        const SferaEffectVec3F right = vec_scale(vec_normalized(vec_cross(to_viewer, {0.0f, 0.0f, -1.0f}), {1.0f, 0.0f, 0.0f}), particle.half_width);
        const SferaEffectVec3F up = vec_scale(vec_normalized(vec_cross(right, to_viewer), {0.0f, 0.0f, 1.0f}), particle.half_width);
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
    effect->resource_id = g_sfera_texture_registry_runtime.findTexture("fx_rain");
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
void IOutputDevice::write(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void COutputLogDevice::write(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0042E3F0); }
void CSphereError::write(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0042E430); }
void GrassMapMngr::loadGrassMap(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_00430AC0); }
void HyperTextElement::elementType(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0041FBB0); }
void CItem::resetItem(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0042B7D0); }
void CItem::releaseItem(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0042B7D0); }
void CItemListCommonItem::resetItem(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_00447DD0); }
void CBaseManagerCommonItem::handleInsert(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0043B130); }
void CBaseManagerCommonItem::handleRemove(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0043B130); }
void CBaseManagerCommonItem::findItem(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004219F0); }
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
void CSoundFX::play(LiftCpu* cpu) {
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<CSound*>(this)->CSound::Play(static_cast<int>(*ptr32<const std::uint32_t>(cpu->esp))));
    cpu->esp += 4u;
}
void CSoundFX::stop(LiftCpu*) {
    reinterpret_cast<CSound*>(this)->CSound::Stop();
}
void CSoundFX::rewind(LiftCpu* cpu) {
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<CSound*>(this)->CSound::Rewind());
}
void CCursor::destroy(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CCursor::copyStateFrom(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CCursor::activate(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CCursor::deactivate(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CCursor::apply(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CCursor::setVisible(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CCursor::getPosition(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CCursor::setPosition(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CCursor::show(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CCursor::isInsideViewport(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CCursor::isSystemCursorVisible(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CCursor::setSystemCursorVisible(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CCursor::cursorKind(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CCursor::setCursorKind(LiftCpu* cpu) { semantic_abi_abstract_call(this, cpu); }
void CHardwareCursor::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D8340); }
void CHardwareCursor::copyStateFrom(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D7C50); }
void CHardwareCursor::activate(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D7CB0); }
void CHardwareCursor::deactivate(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D7CF0); }
void CHardwareCursor::apply(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D7D00); }
void CHardwareCursor::setVisible(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0042B7D0); }
void CHardwareCursor::getPosition(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D7D10); }
void CHardwareCursor::setPosition(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D7D60); }
void CHardwareCursor::show(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D7DA0); }
void CHardwareCursor::isInsideViewport(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D7DD0); }
void CHardwareCursor::isSystemCursorVisible(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D7E10); }
void CHardwareCursor::setSystemCursorVisible(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D7E30); }
void CHardwareCursor::cursorKind(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D7E50); }
void CHardwareCursor::setCursorKind(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D7E60); }
void CSoftwareCursor::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D8340); }
void CSoftwareCursor::copyStateFrom(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D7FB0); }
void CSoftwareCursor::activate(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D8030); }
void CSoftwareCursor::deactivate(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D80A0); }
void CSoftwareCursor::apply(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0042B7D0); }
void CSoftwareCursor::setVisible(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D8100); }
void CSoftwareCursor::getPosition(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D8140); }
void CSoftwareCursor::setPosition(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D8160); }
void CSoftwareCursor::show(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D8180); }
void CSoftwareCursor::isInsideViewport(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D82D0); }
void CSoftwareCursor::isSystemCursorVisible(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D82E0); }
void CSoftwareCursor::setSystemCursorVisible(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D82F0); }
void CSoftwareCursor::cursorKind(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D8300); }
void CSoftwareCursor::setCursorKind(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D8310); }
void UnmanagedResourceBase::restoreResource(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0042B7D0); }
void UnmanagedResourceBase::releaseResource(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D9820); }
void UnmanagedResourceVB::restoreResource(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D9740); }
void UnmanagedResourceIB::restoreResource(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D97B0); }
void UnmanagedResourceTexture::restoreResource(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D9840); }
void UnmanagedResourceVector::reserve(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004DA510); }
void StdAllocator::allocate(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004ED770); }
void StdAllocator::reallocate(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004ED790); }
void StdAllocator::deallocate(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004ED7B0); }
void SphereUI::Window::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D47B0); }
void SphereUI::Window::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D5510); }
void SphereUI::Window::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D2DD0); }
void SphereUI::Window::setPosition(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D19E0); }
void SphereUI::Window::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D25E0); }
void SphereUI::Window::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D28B0); }
void SphereUI::Window::setOpacity(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D2A40); }
void SphereUI::Window::hitTest(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D2B80); }
void SphereUI::Window::dispatchMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D2AE0); }
void SphereUI::Window::setFont(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D1AC0); }
void SphereUI::Window::getFont(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D1B00); }
void SphereUI::Window::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A13C0); }
void SphereUI::bindEventHandler(Window* window, WindowEventHandler handler) { if (window == nullptr) return; auto& bindings = bound_ui_event_handlers(); const std::uint32_t address = address32(window); for (auto& binding : bindings) if (binding.window == address) { binding.handler = handler; return; } if (handler != WindowEventHandler::none) bindings.push_back({address, handler}); }
void SphereUI::copyEventHandler(Window* destination, const Window* source) { if (destination == nullptr || destination == source) return; const WindowEventHandler handler = bound_ui_event_handler(source); unbindEventHandler(destination); if (handler != WindowEventHandler::none) bindEventHandler(destination, handler); }
bool SphereUI::hasEventHandler(const Window* window) { return window != nullptr && bound_ui_event_handler(window) != WindowEventHandler::none; }
void SphereUI::dispatchEvent(Window* window, LiftCpu* cpu, std::uint32_t callsite) { const auto target = ui_event_target(bound_ui_event_handler(window)); if (target == nullptr) return; cpu->ecx = address32(window); lifted::lift_push32(cpu, callsite); target(cpu, callsite); }
void SphereUI::unbindEventHandler(const void* window) { if (window == nullptr) return; auto& bindings = bound_ui_event_handlers(); const std::uint32_t address = address32(window); bindings.erase(std::remove_if(bindings.begin(), bindings.end(), [address](const BoundUiEventHandler& binding) { return binding.window == address; }), bindings.end()); }
void SphereUI::ButtonCtrl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0049EDE0); }
void SphereUI::ButtonCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A0DB0); }
void SphereUI::ButtonCtrl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0049F5A0); }
void SphereUI::ButtonCtrl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0049F230); }
void SphereUI::ButtonCtrl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0049F7A0); }
void SphereUI::ButtonCtrl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0049F1A0); }
void SphereUI::CheckBox::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A0ED0); }
void SphereUI::CheckBox::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A1740); }
void SphereUI::CheckBox::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A12C0); }
void SphereUI::CheckBox::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A13E0); }
void SphereUI::CheckBox::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A1200); }
void SphereUI::CheckBox::playClickSound(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A1350); }
void SphereUI::CDescriptionWindow::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A2280); }
void SphereUI::CDescriptionWindow::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A1DF0); }
void SphereUI::EditCtrl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A3000); }
void SphereUI::EditCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A3C50); }
void SphereUI::EditCtrl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A3990); }
void SphereUI::EditCtrl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A2810); }
void SphereUI::EditCtrl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A3400); }
void SphereUI::EditCtrl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A2FE0); }
void SphereUI::ListCtrl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C0D80); }
void SphereUI::ListCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C04C0); }
void SphereUI::ListCtrl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C08C0); }
void SphereUI::ListCtrl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004BF210); }
void SphereUI::ListCtrl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004BEEF0); }
void SphereUI::ListCtrl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004BFE80); }
void SphereUI::FilterListCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A49E0); }
void SphereUI::FilterListCtrl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A48A0); }
void SphereUI::FilterListCtrl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A44D0); }
void SphereUI::FontPicker::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A5800); }
void SphereUI::FontPicker::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A5B70); }
void SphereUI::FontPicker::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A57A0); }
void SphereUI::FontPicker::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A56E0); }
void SphereUI::FontPicker::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A5600); }
void SphereUI::FontPicker::setFont(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A5990); }
void SphereUI::FontPicker::getFont(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A59F0); }
void SphereUI::FontPicker::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A5A50); }
void SphereUI::HyperTextChatListControl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004A9CC0); }
void SphereUI::HyperTextChatListControl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004AD590); }
void SphereUI::HyperTextChatListControl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004ACE10); }
void SphereUI::HyperTextChatListControl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004AB430); }
void SphereUI::HyperTextChatListControl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004AB7C0); }
void SphereUI::HyperTextChatListControl::setFont(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004AA0D0); }
void SphereUI::HyperTextChatListControl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004AAB30); }
void SphereUI::HyperTextCtrl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004AEEA0); }
void SphereUI::HyperTextCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B1210); }
void SphereUI::HyperTextCtrl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B08B0); }
void SphereUI::HyperTextCtrl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004AF040); }
void SphereUI::HyperTextCtrl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B0590); }
void SphereUI::HyperTextCtrl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B0250); }
void SphereUI::HyperTextEditControl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B6410); }
void SphereUI::HyperTextEditControl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B7720); }
void SphereUI::HyperTextEditControl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B45C0); }
void SphereUI::HyperTextEditControl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B47D0); }
void SphereUI::HyperTextEditControl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B6F30); }
void SphereUI::HyperTextEditControl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B6F10); }
void SphereUI::ImageCtrl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B77F0); }
void SphereUI::ImageCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B80A0); }
void SphereUI::ImageCtrl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B7DC0); }
void SphereUI::ImageCtrl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B7970); }
void SphereUI::ImageCtrl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B7AF0); }
void SphereUI::ImageCtrl::setOpacity(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B7F10); }
void SphereUI::ImageCtrl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004B7F90); }
void SphereUI::ListItemCtrl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004BE3E0); }
void SphereUI::ListItemCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004BE8C0); }
void SphereUI::ListItemCtrl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004BE170); }
void SphereUI::ListItemCtrl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004BD000); }
void SphereUI::ListItemCtrl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004BD340); }
void SphereUI::ListItemCtrl::setOpacity(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004BD880); }
void SphereUI::ListItemCtrl::hitTest(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004BD970); }
void SphereUI::ListItemCtrl::dispatchMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004BDA30); }
void SphereUI::ListItemCtrl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004BE3C0); }
void SphereUI::CMenuListControl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C1B30); }
void SphereUI::CMenuListControl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C2FB0); }
void SphereUI::CMenuListControl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C2A40); }
void SphereUI::CMenuListControl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C1A40); }
void SphereUI::CMenuListControl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C1660); }
void SphereUI::CMenuListControl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C2A20); }
void SphereUI::ToolTipCtrl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D0230); }
void SphereUI::ToolTipCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CFF20); }
void SphereUI::ToolTipCtrl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D0130); }
void SphereUI::ToolTipCtrl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CFA00); }
void SphereUI::ToolTipCtrl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CF7C0); }
void SphereUI::ToolTipCtrl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C3270); }
void SphereUI::MiniHelpCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C3520); }
void SphereUI::MiniHelpCtrl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C3060); }
void SphereUI::CMinimapControl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C3670); }
void SphereUI::CMinimapControl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C3710); }
void SphereUI::CMinimapControl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C3750); }
void SphereUI::CMinimapControl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C3720); }
void SphereUI::ProgressBar::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C3FC0); }
void SphereUI::ProgressBar::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C42B0); }
void SphereUI::ProgressBar::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C3EB0); }
void SphereUI::ProgressBar::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C3C00); }
void SphereUI::ProgressBar::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_0042B0A0); }
void SphereUI::RadioButtonCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C43C0); }
void SphereUI::RadioButtonCtrl::playClickSound(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C4360); }
void SphereUI::RichEditCtrl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C4480); }
void SphereUI::RichEditCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C5E10); }
void SphereUI::RichEditCtrl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C6370); }
void SphereUI::RichEditCtrl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C4D90); }
void SphereUI::RichEditCtrl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C6810); }
void SphereUI::RichEditCtrl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C5990); }
void SphereUI::ScrollBar::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C6B80); }
void SphereUI::ScrollBar::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C7F20); }
void SphereUI::ScrollBar::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C7AB0); }
void SphereUI::ScrollBar::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C6EC0); }
void SphereUI::ScrollBar::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C7120); }
void SphereUI::ScrollBar::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C7DC0); }
void SphereUI::ScrollBar::updateControlState(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C7880); }
void SphereUI::ScrollBar::loadControlParameters(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C7CF0); }
void SphereUI::SliderCtrl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C80C0); }
void SphereUI::SliderCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C8450); }
void SphereUI::SliderCtrl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C82E0); }
void SphereUI::SliderCtrl::updateControlState(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C8270); }
void SphereUI::SliderCtrl::loadControlParameters(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C8060); }
void SphereUI::SlotCtrl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C95F0); }
void SphereUI::SlotCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C99D0); }
void SphereUI::SlotCtrl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C9250); }
void SphereUI::SlotCtrl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C85E0); }
void SphereUI::SlotCtrl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C8D00); }
void SphereUI::SlotCtrl::hitTest(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C8570); }
void SphereUI::SlotCtrl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004C9150); }
void SphereUI::SpinButton::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CD550); }
void SphereUI::SpinButton::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CDE00); }
void SphereUI::SpinButton::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CDA30); }
void SphereUI::SpinButton::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CD760); }
void SphereUI::SpinButton::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CD820); }
void SphereUI::SpinButton::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CDA10); }
void SphereUI::SpinButton::updateStatus(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CDBF0); }
void SphereUI::TextCtrl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CF3E0); }
void SphereUI::TextCtrl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CF670); }
void SphereUI::TextCtrl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CF4C0); }
void SphereUI::TextCtrl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004CF310); }
void SphereUI::CWebBrowserControl::loadUi(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D0E10); }
void SphereUI::CWebBrowserControl::clone(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D0BB0); }
void SphereUI::CWebBrowserControl::handleMessage(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D0EC0); }
void SphereUI::CWebBrowserControl::draw(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D0520); }
void SphereUI::CWebBrowserControl::handleInput(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D0670); }
void SphereUI::CWebBrowserControl::destroy(LiftCpu* cpu) { semantic_dispatch(this, cpu, lifted::sfera_sub_004D09D0); }

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
    if (texture_name != nullptr) texture_id = g_sfera_texture_registry_runtime.findTexture(texture_name);
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
    if (texture_name != nullptr) texture_id = g_sfera_texture_registry_runtime.findTexture(texture_name);
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
    for (std::uint32_t index = 0u; index < texture_frame_count; ++index) if (texture_frames != nullptr && texture_frames[index].texture_name != nullptr) texture_frames[index].texture_id = g_sfera_texture_registry_runtime.findTexture(texture_frames[index].texture_name);
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
            SferaEffectVec3F right{view.z, 0.0f, -view.x};
            float length = vec_length(right);
            if (length <= 0.00001f) right = {1.0f, 0.0f, 0.0f};
            else {
                right.x /= length;
                right.y /= length;
                right.z /= length;
            }
            SferaEffectVec3F up{right.y * view.z - right.z * view.y, right.z * view.x - right.x * view.z, right.x * view.y - right.y * view.x};
            length = vec_length(up);
            if (length <= 0.00001f) up = {0.0f, 0.0f, 1.0f};
            else {
                up.x /= length;
                up.y /= length;
                up.z /= length;
            }
            const float right_scale = particle.size * render_basis[0].y;
            const float up_scale = particle.size * render_basis[0].x;
            right.x *= right_scale;
            right.y *= right_scale;
            right.z *= right_scale;
            up.x *= up_scale;
            up.y *= up_scale;
            up.z *= up_scale;
            slot->position[0] = {particle.render_position.x - right.x - up.x, particle.render_position.y - right.y - up.y, particle.render_position.z - right.z - up.z};
            slot->position[1] = {particle.render_position.x - right.x + up.x, particle.render_position.y - right.y + up.y, particle.render_position.z - right.z + up.z};
            slot->position[2] = {particle.render_position.x + right.x + up.x, particle.render_position.y + right.y + up.y, particle.render_position.z + right.z + up.z};
            slot->position[3] = {particle.render_position.x + right.x - up.x, particle.render_position.y + right.y - up.y, particle.render_position.z + right.z - up.z};
        }
    }
}
namespace {
    struct SferaSoundManagerState {
        std::uint32_t first;
        std::uint32_t last;
        float volume;
        std::uint32_t enabled;
        std::uint32_t count;
    };
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
    CSound* create_cached_sound(SferaSoundManagerState& manager, const char* filename, const SferaSound3DParameters* parameters, std::int32_t cache_lifetime) {
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
    auto* manager = ptr32<SferaSoundManagerState>(g_sfera_sound_runtime.manager);
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
    const std::uint32_t address = g_sfera_sound_effect_items.take();
    auto* result = ptr32<CSoundEffect>(address);
    if (result == nullptr) return nullptr;
    result->resetFrom(*definition);
    return result;
}

void SferaSoundRuntime::destroyEffect(CSoundEffect* effect) {
    if (effect == nullptr) return;
    effect->stop();
    g_sfera_sound_effect_items.put(address32(effect));
}
