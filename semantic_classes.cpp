#include "semantic_classes.h"
#include "zlib.h"
#include "semantic_static.h"
#include <commctrl.h>
#include <dinput.h>
#include <objbase.h>

#include <algorithm>
#include <array>
#include <bit>
#include <charconv>
#include <climits>
#include <fcntl.h>
#include <float.h>
#include <mbctype.h>
#include <cerrno>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <io.h>
#include <share.h>
#include <sys/stat.h>
#include <sys/locking.h>
#include <sys/utime.h>
#include <memory>
#include <new>
#include <fstream>
#include <filesystem>
#include <iterator>
#include <stdexcept>
#include <system_error>
#include <limits>
#include <string>
#include <string_view>
#include <span>
#include <vector>
#include <utility>
#include <tuple>
#include <ws2tcpip.h>
namespace {

    bool character_selection_active() {
        const auto& runtime = g_sfera_mbc_runtime;
        int process_index = runtime.process_chain_first;
        std::size_t visited = 0;
        while (process_index >= 0 && visited++ < std::size(runtime.processes)) {
            if (static_cast<std::size_t>(process_index) >= std::size(runtime.processes)) break;
            const auto& process = runtime.processes[process_index];
            if (process.chain_prev_index < 0) break;
            const auto active = std::find_if(process.programs.begin(), process.programs.end(), [](const auto& program) {
                return program.state > 0 && program.name == "SelChar";
            });
            if (active != process.programs.end()) return true;
            if (process_index == runtime.process_chain_last) break;
            const int next = process.chain_next_index;
            if (next < 0 || next == process_index) break;
            process_index = next;
        }
        return false;
    }

    float scene_field_of_view(double width, double height) {
        if (character_selection_active()) return SferaMath::fittedFieldOfView(width, height);
        return SferaMath::fittedFieldOfView(width, height, g_sfera_graphics_runtime.field_of_view_degrees);
    }

    bool simple_parser_whitespace(std::string_view text, std::size_t index = 0) {
        // Preserve the original signed code-unit comparison used by this grammar.
        return text[index] <= ' ';
    }

}
bool SferaSimpleParser::load(const std::string& filename) {
    *this = {};
    if (filename.empty()) return false;
    std::ifstream stream;
    for (const auto& path : g_sfera_files.candidatePaths(filename)) {
        stream.open(path, std::ios::binary | std::ios::ate);
        if (stream.is_open()) break;
        stream.clear();
    }
    if (!stream.is_open()) return false;
    const std::streamoff length = stream.tellg() - std::streampos(0);
    if (length <= 0 || std::cmp_greater_equal(length, PTRDIFF_MAX)) return false;
    const std::size_t source_size = length;
    std::string source(source_size, '\0');
    stream.seekg(0, std::ios::beg);
    const std::streamsize read_size = source.size();
    stream.read(source.data(), read_size);
    if (stream.gcount() <= 0) return false;
    source.resize(stream.gcount());
    assign(std::move(source));
    return true;
}

void SferaSimpleParser::assign(std::string source) {
    if (source.size() >= PTRDIFF_MAX) throw std::length_error("Parser input too large");
    std::vector<std::size_t> lines{0};
    // CRLF is one separator. LF and lone CR must not hide the remaining declarations.
    for (std::size_t index = 0; index < source.size(); ++index) {
        const auto separator = source[index];
        if (separator != '\r' && separator != '\n') continue;
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

SferaParserRange SferaSimpleParser::boundedRange(const SferaParserRange* range) const {
    const std::ptrdiff_t count = std::ssize(lines_);
    return range == nullptr ? SferaParserRange{0, count} : SferaParserRange{std::max(range->begin, std::ptrdiff_t{0}), std::min(range->end, count)};
}

std::string_view SferaSimpleParser::lineAt(std::ptrdiff_t index) const {
    if (index < 0 || index >= lines_.size()) return {};
    const auto offset = lines_[index];
    const auto end = source_.find('\0', offset);
    return std::string_view(source_).substr(offset, end == std::string::npos ? source_.size() - offset : end - offset);
}

std::string_view SferaSimpleParser::firstToken(std::string_view line) {
    while (!line.empty() && simple_parser_whitespace(line)) line.remove_prefix(1);
    return line.starts_with("//") ? std::string_view{} : line;
}

std::ptrdiff_t SferaSimpleParser::findClosingBrace(std::ptrdiff_t begin, std::ptrdiff_t end) const {
    std::ptrdiff_t depth = 1;
    for (auto index = begin; index < end; ++index) {
        const auto line = firstToken(lineAt(index));
        for (std::size_t at = 0; at < line.size(); ++at) {
            if (line.substr(at).starts_with("//")) break;
            if (line[at] == '{') ++depth;
            else if (line[at] == '}' && --depth == 0) return index;
        }
    }
    return -1;
}

std::ptrdiff_t SferaSimpleParser::parseBlockAt(std::string_view first, std::ptrdiff_t line, std::ptrdiff_t end, SferaParserRange* output) {
    if (first.empty() || line >= end) return -1;
    std::size_t length = 0;
    while (length < first.size() && !simple_parser_whitespace(first, length)) ++length;
    if (length > maximumValueLength) return -1;
    token_.assign(first.substr(0, length));
    auto open = line;
    if (first.find('{', length) == std::string_view::npos) {
        for (open = line + 1; open < end; ++open) {
            const auto next = firstToken(lineAt(open));
            if (next.empty()) continue;
            if (next.front() != '{') return -1;
            break;
        }
    }
    if (open >= end) return -1;
    const auto close = findClosingBrace(open + 1, end);
    if (close < 0) return -1;
    if (output != nullptr) *output = {open + 1, close + 1};
    return close - open + 1;
}

bool SferaSimpleParser::findBlock(std::string_view name, SferaParserRange* output, const SferaParserRange* search, std::ptrdiff_t occurrence) {
    if (name.empty() || output == nullptr) return false;
    const auto range = boundedRange(search);
    std::ptrdiff_t matched = 0;
    for (auto line = range.begin; line < range.end;) {
        const auto first = firstToken(lineAt(line));
        if (first.empty() || parseBlockAt(first, line, range.end, output) < 0) { ++line; continue; }
        if (SferaText::asciiEqual(token_, name) && ++matched == occurrence) return true;
        line = output->end;
    }
    return false;
}

std::ptrdiff_t SferaSimpleParser::countBlocks(std::string_view name, const SferaParserRange* search) {
    auto range = boundedRange(search);
    SferaParserRange block{};
    std::ptrdiff_t count = 0;
    while (findBlock(name, &block, &range, 1)) { ++count; range.begin = block.end; }
    return count;
}

bool SferaSimpleParser::findValueFrom(std::string_view name, std::ptrdiff_t& line, std::ptrdiff_t end) {
    if (name.empty()) return false;
    while (line < end) {
        const auto first = firstToken(lineAt(line));
        if (first.empty()) { ++line; continue; }
        SferaParserRange block{};
        if (parseBlockAt(first, line, end, &block) >= 0) {
            line = block.end;
            continue;
        }
        std::size_t length = 0;
        while (length < first.size() && !simple_parser_whitespace(first, length)) ++length;
        token_.assign(first.substr(0, std::min(length, maximumValueLength)));
        if (SferaText::asciiEqual(token_, name)) {
            token_.assign(first.substr(length, maximumValueLength));
            ++line;
            return true;
        }
        ++line;
    }
    return false;
}

bool SferaSimpleParser::findValue(std::string_view name, const SferaParserRange* search) {
    auto range = boundedRange(search);
    return findValueFrom(name, range.begin, range.end);
}
void SferaSimpleParser::setScanRange(const SferaParserRange* range) { scan_ = boundedRange(range); }
void SferaSimpleParser::setBlockRange(const SferaParserRange* range) { block_ = boundedRange(range); }
bool SferaSimpleParser::nextValue(std::string_view name) {
    auto next = scan_.begin;
    if (!findValueFrom(name, next, scan_.end)) return false;
    scan_.begin = next;
    return true;
}
bool SferaSimpleParser::nextBlock(std::string_view name, SferaParserRange* output) {
    if (!findBlock(name, output, &block_, 1)) return false;
    block_.begin = output->end;
    return true;
}

std::size_t SferaSimpleParser::tokenCount() const {
    std::string_view rest(token_);
    std::size_t count = 0;
    while (!(rest = firstToken(rest)).empty()) {
        ++count;
        while (!rest.empty() && !simple_parser_whitespace(rest)) {
            if (rest.starts_with("//")) return count;
            rest.remove_prefix(1);
        }
    }
    return count;
}

std::size_t SferaSimpleParser::tokenStart(std::size_t index) const {
    std::size_t offset = 0;
    for (std::size_t current = 0; offset < token_.size(); ++current) {
        while (offset < token_.size() && simple_parser_whitespace(token_, offset)) ++offset;
        if (offset == token_.size() || std::string_view(token_).substr(offset).starts_with("//")) break;
        if (current == index) return offset;
        while (offset < token_.size() && !simple_parser_whitespace(token_, offset)) ++offset;
    }
    return std::string::npos;
}
std::string_view SferaSimpleParser::tokenAt(std::size_t index) const {
    const auto start = tokenStart(index);
    if (start == std::string::npos) return {};
    auto end = start;
    while (end < token_.size() && !simple_parser_whitespace(token_, end)) ++end;
    return std::string_view(token_).substr(start, end - start);
}

bool SferaSimpleParser::tryReadFloat(std::size_t index, float& output) const {
    return SferaText::readNumber(tokenAt(index), output);
}
bool SferaSimpleParser::tryReadInt(std::size_t index, int& output) const {
    return SferaText::readNumber(tokenAt(index), output);
}
bool SferaSimpleParser::readFloatSequence(std::size_t index, std::span<float> output) const {
    if (output.size() > SIZE_MAX - index) return false;
    for (auto& value : output) if (!tryReadFloat(index++, value)) return false;
    return true;
}
bool SferaSimpleParser::readIntSequence(std::size_t index, std::span<int> output) const {
    if (output.size() > SIZE_MAX - index) return false;
    for (auto& value : output) if (!tryReadInt(index++, value)) return false;
    return true;
}
bool SferaSimpleParser::readVector(std::size_t index, SferaVec3F& output) const {
    return index <= SIZE_MAX - 2 && tryReadFloat(index, output.x) && tryReadFloat(index + 1, output.y) && tryReadFloat(index + 2, output.z);
}
float SferaSimpleParser::readFloat(std::size_t index) const { float value = 0.0f; tryReadFloat(index, value); return value; }
int SferaSimpleParser::readInt(std::size_t index) const { int value = 0; tryReadInt(index, value); return value; }
bool SferaSimpleParser::readString(std::size_t index, std::string& output) const {
    const auto value = tokenAt(index);
    if (value.empty()) return false;
    output.assign(value);
    return true;
}
bool SferaSimpleParser::readQuotedString(std::size_t index, std::string& output) const {
    const auto start = tokenStart(index);
    if (start == std::string::npos || token_[start] != '"') return false;
    const auto end = token_.find('"', start + 1);
    output.assign(token_, start + 1, end == std::string::npos ? std::string::npos : end - start - 1);
    return true;
}
bool SferaSimpleParser::readBool(std::size_t index) const {
    const auto value = tokenAt(index);
    return !value.empty() && (value.front() == '1' || SferaText::asciiEqual(value, "true"));
}

std::pair<std::size_t, float> SferaEffectTrack::interval(float age, bool curved) const {
    if (keys.empty()) return {0, 0.0f};
    if (keys.size() == 1 || age >= keys.back().time) return {keys.size() - 1, 0.0f};
    std::size_t index = 0;
    for (std::size_t candidate = keys.size() - 1; candidate > 0; --candidate) {
        if (keys[candidate].time <= age) { index = candidate; break; }
    }
    const float duration = keys[index + 1].time - keys[index].time;
    float factor = duration == 0.0f ? 0.0f : (age - keys[index].time) / duration;
    if (curved && cosine_interpolation) factor = (1.0f - std::cos(factor * 3.1415929794311523f)) * 0.5f;
    return {index, factor};
}

void SferaEffectTrack::evaluateVector(float age, SferaVec3F& output) const {
    output = {};
    if (keys.empty()) return;
    const auto [index, factor] = interval(age, true);
    const auto& begin = std::get<SferaEffectTrackKey::Vector>(keys[index].value);
    output = begin.minimum;
    if (index + 1 == keys.size()) return;
    const auto& end = std::get<SferaEffectTrackKey::Vector>(keys[index + 1].value);
    output.x += (end.minimum.x - begin.minimum.x) * factor;
    output.y += (end.minimum.y - begin.minimum.y) * factor;
    output.z += (end.minimum.z - begin.minimum.z) * factor;
}
void SferaEffectTrack::evaluateScalar(float age, float& output, std::span<const std::uint16_t> random_values, std::uint32_t random_offset) const {
    output = 0.0f;
    if (keys.empty()) return;
    const auto sample = [&](std::size_t index) {
        const auto& key = keys[index];
        const auto& value = std::get<SferaEffectTrackKey::Scalar>(key.value);
        if (key.mode != SferaEffectTrackKey::Mode::Random || random_values.empty() || index >= random_values.size()) return value.minimum;
        const float random = (random_values[index] + random_offset) * 1.5259021893143654e-05f;
        return value.minimum + random * value.range;
    };
    const auto [index, factor] = interval(age, false);
    output = sample(index);
    if (index + 1 != keys.size()) output += (sample(index + 1) - output) * factor;
}
void SferaEffectTrack::requireRandomCapacity(std::size_t) const {
    // Legacy SEF loading never rejected a definition because a random track was
    // longer than the shared random row. evaluateScalar() now degrades to the
    // fixed minimum when a sample is outside the available row instead.
}
namespace {
    int effect_integer(SferaSimpleParser& parser, std::size_t index) { return parser.readInt(index); }
    float effect_real(SferaSimpleParser& parser, std::size_t index) { return parser.readFloat(index); }
    void effect_vector(SferaSimpleParser& parser, std::size_t index, SferaVec3F& output) { (void)parser.readVector(index, output); }
    template<class T> void effect_sequence(SferaSimpleParser& parser, std::size_t index, std::span<T> output) {
        if constexpr (std::is_floating_point_v<T>) (void)parser.readFloatSequence(index, output);
        else (void)parser.readIntSequence(index, output);
    }
    template<class InitializeKey, class ParseKey>
    std::shared_ptr<SferaEffectTrack> load_effect_track(SferaSimpleParser& parser, const SferaParserRange& range, std::size_t mode_count,
                                                        InitializeKey initialize, ParseKey parse) {
        if (!parser.findValue("numkeys", &range)) return nullptr;
        const int count = parser.readInt(0u);
        if (count <= 0) return nullptr;
        auto track = std::make_shared<SferaEffectTrack>();
        const std::size_t key_count = count;
        track->keys.resize(key_count);
        for (auto& key : track->keys) initialize(key);
        constexpr std::array modes{
            std::pair{"key", SferaEffectTrackKey::Mode::Fixed},
            std::pair{"rkey", SferaEffectTrackKey::Mode::Random},
            std::pair{"mrkey", SferaEffectTrackKey::Mode::MirroredRandom}
        };
        for (const auto& [token, mode] : std::span(modes).first(mode_count)) {
            parser.setScanRange(&range);
            while (parser.nextValue(token)) {
                const int index = parser.readInt(0u);
                if (index < 0 || index >= count) continue;
                SferaEffectTrackKey key{};
                key.mode = mode;
                initialize(key);
                key.time = parser.readFloat(1u);
                parse(key);
                const std::size_t key_index = index;
                track->keys[key_index] = std::move(key);
            }
        }
        parser.clearScanRange();
        return track;
    }
}
std::shared_ptr<const SferaEffectTrack> sfera_load_scalar_effect_track(SferaSimpleParser* parser, const SferaParserRange* range) {
    if (parser == nullptr || range == nullptr) return nullptr;
    return load_effect_track(*parser, *range, 2,
        [](SferaEffectTrackKey& key) { key.value.emplace<SferaEffectTrackKey::Scalar>(); },
        [&](SferaEffectTrackKey& key) {
            auto& value = std::get<SferaEffectTrackKey::Scalar>(key.value);
            value.minimum = parser->readFloat(2u);
            if (key.mode != SferaEffectTrackKey::Mode::Fixed) value.range = parser->readFloat(3u);
        });
}
std::shared_ptr<const SferaEffectTrack> sfera_load_vector_effect_track(SferaSimpleParser* parser, const SferaParserRange* range) {
    if (parser == nullptr || range == nullptr) return nullptr;
    return load_effect_track(*parser, *range, 3,
        [](SferaEffectTrackKey& key) { key.value.emplace<SferaEffectTrackKey::Vector>(); },
        [&](SferaEffectTrackKey& key) {
            auto& value = std::get<SferaEffectTrackKey::Vector>(key.value);
            effect_vector(*parser, 2u, value.minimum);
            if (key.mode != SferaEffectTrackKey::Mode::Fixed) effect_vector(*parser, 5u, value.range);
        });
}
SferaLightInstance::SferaLightInstance(std::shared_ptr<const SferaLightDefinition> source)
    : definition(std::move(source)) {
    if (definition == nullptr) throw std::invalid_argument("Missing light definition");
    reset();
}
SferaLightInstance::SferaLightInstance(SferaLightInstance&& source) noexcept
    : definition(std::move(source.definition)), position(source.position), color(source.color),
      light_index(std::exchange(source.light_index, -1)), brightness_tick(source.brightness_tick) {}
SferaLightInstance::~SferaLightInstance() { stop(); }
void SferaLightInstance::reset() {
    stop();
    position = definition->position;
    color = definition->color;
    brightness_tick = 0;
}
bool SferaLightDefinition::load(SferaSimpleParser& parser, const SferaParserRange& range) {
    SferaParserRange previous_block_range{};
    parser.getBlockRange(&previous_block_range);
    if (parser.findValue("light_pos", &range)) effect_vector(parser, 0u, position);
    if (parser.findValue("light_color", &range)) effect_sequence<float>(parser, 0u, color);
    if (parser.findValue("random_color", &range)) {
        effect_sequence<int>(parser, 0u, random_color);
        randomize_color = true;
    }
    if (parser.findValue("brightness", &range)) {
        brightness = effect_real(parser, 0);
        if (parser.tokenCount() > 1) brightness_delta = effect_real(parser, 1);
        vary_brightness = true;
    }
    if (parser.findValue("brightFreq", &range)) brightness_frequency = effect_integer(parser, 0u);
    std::string attach_name;
    if (parser.findValue("attach", &range) && parser.readString(0u, attach_name)) {
        if (SferaText::asciiEqual(attach_name, "ATTACH_LEFTHAND")) attach_mode = 1u;
        else if (SferaText::asciiEqual(attach_name, "ATTACH_RIGHTHAND")) attach_mode = 2u;
        else if (SferaText::asciiEqual(attach_name, "ATTACH_BETWEENHANDS")) attach_mode = 3u;
    }
    SferaParserRange track_range{};
    if (parser.findBlock("color_track", &track_range, &range, 1)) color_track = sfera_load_vector_effect_track(&parser, &track_range);
    if (parser.findBlock("alpha_track", &track_range, &range, 1)) alpha_track = sfera_load_scalar_effect_track(&parser, &track_range);
    if (parser.findBlock("position_track", &track_range, &range, 1)) position_track = sfera_load_vector_effect_track(&parser, &track_range);
    if (alpha_track != nullptr) alpha_track->requireRandomCapacity(65536);
    parser.setBlockRange(&previous_block_range);
    return true;
}
void SferaLightInstance::update(const SferaVec3F& base_position, float age, std::uint32_t opacity) {
    if (light_index == -1) {
        g_sfera_light_runtime.release(light_index);
        light_index = g_sfera_light_runtime.create(position, color.data(), 0.0f);
        if (light_index == -1) return;
    }
    if (definition->position_track != nullptr) definition->position_track->evaluateVector(age, position);
    if (definition->color_track != nullptr) {
        SferaVec3F sampled{};
        definition->color_track->evaluateVector(age, sampled);
        color[0] = sampled.x;
        color[1] = sampled.y;
        color[2] = sampled.z;
    }
    if (definition->alpha_track != nullptr) definition->alpha_track->evaluateScalar(age, color[3], g_sfera_effect_manager.particle_random_table);
    SferaVec3F world_position{base_position.x + position.x, base_position.y + position.y, base_position.z + position.z};
    if (definition->randomize_color) {
        constexpr float random_scale = 3.0518509447574615e-05f;
        for (std::size_t channel = 0u; channel < 3u; ++channel) color[channel] = definition->random_color[channel] + std::rand() * random_scale * definition->random_color[channel + 3u];
    }
    const float opacity_scale = opacity * 0.00390625f;
    float output_color[4]{color[0] * opacity_scale, color[1] * opacity_scale, color[2] * opacity_scale, color[3] * opacity_scale};
    if (definition->vary_brightness && definition->brightness_frequency != 0u && brightness_tick % definition->brightness_frequency == 0u) {
        constexpr float random_scale = 3.0518509447574615e-05f;
        const float brightness_scale = definition->brightness + std::rand() * random_scale * definition->brightness_delta;
        output_color[0] *= brightness_scale;
        output_color[1] *= brightness_scale;
        output_color[2] *= brightness_scale;
    }
    ++brightness_tick;
    g_sfera_light_runtime.write(light_index, world_position, output_color, 0.0f);
}
void SferaLightInstance::stop() noexcept {
    g_sfera_light_runtime.release(light_index);
    light_index = -1;
}
namespace {

    void prepare_particle_definition(const std::shared_ptr<SferaParticleSystemDefinition>& definition);

    void initialize_scripted_phase(CScriptedEffect& effect) {
        effect.work_phase_active = false;
        effect.phase_ticks_remaining = 0u;
        if (effect.definition == nullptr) return;
        if (effect.definition->work_time_min == std::numeric_limits<std::uint32_t>::max()) return;
        if ((std::rand() & 1) == 0) effect.work_phase_active = true;
        const std::uint32_t duration = !effect.work_phase_active ? effect.definition->work_time_max : effect.definition->sleep_time_max;
        if (duration != 0u) effect.phase_ticks_remaining = std::rand() % duration;
    }

    void build_y_up_billboard_axes(const SferaVec3F& view, float right_scale, float up_scale, SferaVec3F& right, SferaVec3F& up) {
        right = {view.z, 0.0f, -view.x};
        float length = (right).length<float, float>();
        right = length <= 0.00001f ? SferaVec3F{1.0f, 0.0f, 0.0f} : ((right) * (1.0f / length));
        up = (right).cross<float>((view));
        length = (up).length<float, float>();
        up = length <= 0.00001f ? SferaVec3F{0.0f, 0.0f, 1.0f} : ((up) * (1.0f / length));
        right = ((right) * (right_scale));
        up = ((up) * (up_scale));
    }
    void set_full_quad_uv(SferaEffectRenderSlot& slot) {
        slot.uv[0][0] = 0.0f; slot.uv[0][1] = 0.0f;
        slot.uv[1][0] = 1.0f; slot.uv[1][1] = 0.0f;
        slot.uv[2][0] = 1.0f; slot.uv[2][1] = 1.0f;
        slot.uv[3][0] = 0.0f; slot.uv[3][1] = 1.0f;
    }
    float random_signed(float scale) {
        constexpr float random_scale = 3.0518509447574615e-05f;
        return (std::rand() - std::rand()) * random_scale * scale;
    }
    void initialize_quad_slot(SferaEffectRenderSlot& slot, int resource_id, bool additive, bool custom_uv, int alpha) {
        slot.resource_id = resource_id;
        slot.self_illumination = alpha;
        slot.additive = additive;
        slot.custom_uv = custom_uv;
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex) {
            slot.color[0][vertex] = 255u;
            slot.color[1][vertex] = 255u;
            slot.color[2][vertex] = 255u;
            slot.color[3][vertex] = alpha;
        }
    }

    bool bloodTriangleOverlaps(const SferaVec3F* triangle, const SferaVec3F& center, float radius) {
        float min_x = triangle[0].x, min_y = triangle[0].y, min_z = triangle[0].z, max_x = min_x, max_y = min_y, max_z = min_z;
        for (std::size_t i = 1u; i < 3u; ++i) {
            min_x = std::min(min_x, triangle[i].x); min_y = std::min(min_y, triangle[i].y); min_z = std::min(min_z, triangle[i].z);
            max_x = std::max(max_x, triangle[i].x); max_y = std::max(max_y, triangle[i].y); max_z = std::max(max_z, triangle[i].z);
        }
        return max_x >= center.x - radius && min_x <= center.x + radius && max_z >= center.z - radius && min_z <= center.z + radius && max_y >= center.y - 1.8f && min_y <= center.y + 1.5f;
    }
    std::vector<SferaVec3F> collectBloodSceneTriangles(const SferaVec3F& center, float radius) {
        const auto& points = g_sfera_world_spatial.shadowVertices();
        std::vector<SferaVec3F> selected;
        selected.reserve(std::min<std::size_t>(points.size(), 90));
        for (std::size_t offset = 0; offset + 2 < points.size() && selected.size() < 90; offset += 3) {
            const auto* triangle = points.data() + offset;
            if (!std::isfinite(triangle[0].x) || !std::isfinite(triangle[0].y) || !std::isfinite(triangle[0].z) || !bloodTriangleOverlaps(triangle, center, radius)) continue;
            selected.insert(selected.end(), triangle, triangle + 3);
        }
        return selected;
    }
    void createBloodSpot(SferaBloodEffectRuntime& runtime, const SferaVec3F& origin, std::span<const SferaVec3F> points) {
        if (runtime.active_count >= 30u || points.size() < 3) return;
        SferaBloodSpot* spot = nullptr;
        for (auto& candidate : runtime.spots) if (candidate.life == 0.0f) { spot = &candidate; break; }
        if (spot == nullptr) return;
        const auto triangle_count = std::min<std::size_t>(points.size() / 3, 30);
        spot->life = 1.0f; spot->vertex_count = triangle_count * 3u;
        const float angle = std::rand() * (1.0f / 32768.0f) * 6.2831853071795864769f;
        const float scale = std::rand() * (1.0f / 32768.0f) * 2.0f + 2.0f;
        const float cosine = std::cos(angle), sine = std::sin(angle);
        const float ux = scale * cosine, uz = scale * sine, vx = -scale * sine, vz = scale * cosine;
        for (std::size_t index = 0u; index < spot->vertex_count; ++index) {
            const auto& source = points[index]; auto& target = spot->vertices[index];
            target.position = source; target.diffuse = 0u; target.specular = 0u;
            const float dx = source.x - origin.x, dz = source.z - origin.z;
            target.u = dx * ux + dz * uz + 0.5f; target.v = dx * vx + dz * vz + 0.5f;
        }
        ++runtime.active_count;
    }

}
bool SferaBloodEffectRuntime::onEffectAttached(IEffect&, SferaActiveEffect&, float distance) {
    return distance <= 15.0f;
}
bool SferaBloodEffectRuntime::onEffectDetached(IEffect&, SferaActiveEffect&) {
    return true;
}
void SferaBloodEffectRuntime::onEffectChanged(std::uint32_t , IEffect& effect, SferaActiveEffect& ) {

    auto& runtime = *this;
    if (runtime.active_count >= 30u) return;
    auto* scripted = effect.asScriptedEffect();
    if (scripted == nullptr || scripted->particle_systems.empty()) return;
    auto& particles = *scripted->particle_systems[0];
    if (particles.render_slots.empty()) return;
    const std::uint32_t requested = std::rand() % 3u + 4u;
    std::array<SferaVec3F, 6> origins{};
    std::uint32_t selected = 0u; float radius = 0.0f;
    for (std::size_t index = 0u; index < particles.render_slots.size() && selected < requested; ++index) {
        const auto& slot = particles.render_slots[index];
        if (slot.state.remaining_lifetime <= 0.0f) continue;
        auto& origin = origins[selected++];
        origin = {slot.state.render_position.x, effect.position.y - 0.5f, slot.state.render_position.z};
        const float dx = origin.x - effect.position.x, dy = origin.y - effect.position.y, dz = origin.z - effect.position.z;
        radius = std::max(radius, std::sqrt(dx * dx + dy * dy + dz * dz));
    }
    if (selected != requested) return;
    const auto points = collectBloodSceneTriangles(effect.position, radius + 0.2f);
    for (std::size_t index = 0; index < selected && runtime.active_count < 30; ++index) createBloodSpot(runtime, origins[index], points);
}
void IEffect::assignScriptName(std::string_view name) { script_name.assign(name); }
void IEffect::initializeBaseState(Kind kind) {
    script_name.clear();
    effect_id = std::numeric_limits<std::uint32_t>::max();
    deactivated = false;
    resources_released = false;
    activation_blocked = false;
    cycle_length = 0u;
    lifetime_ticks = 0u;
    range_min = -1.0f;
    range_max = -1.0f;
    effect_kind = kind;
    listener = nullptr;
    spatial_gate_enabled = false;
    render_slot_budget = 0u;
}
void CScriptedEffect::initializeScriptedState() {
    initializeBaseState(Kind::Scripted);
}

bool CScriptedEffect::loadScript(const std::string& filename) {
    if (filename.empty() || !meshes.empty() || !lights.empty() || !particle_systems.empty()) return false;
    SferaSimpleParser parser;
    if (!parser.load(filename)) {
        g_sfera_effect_manager.reportError((std::string("Cannot read effect script: ") + filename));
        return false;
    }
    try {
        CScriptedEffect parsed;
        parsed.initializeScriptedState();
        auto data = std::make_shared<Definition>();
        std::vector<std::shared_ptr<SferaParticleSystemDefinition>> particles;
        const auto find_index = [](const auto& definitions, std::string_view name) -> std::ptrdiff_t {
            const auto found = std::find_if(definitions.begin(), definitions.end(), [&](const auto& value) {
                return SferaText::asciiEqual(value->name, name);
            });
            return found == definitions.end() ? -1 : found - definitions.begin();
        };
        const auto load_blocks = [&](std::string_view name, const SferaParserRange* scope, auto load) {
            parser.setBlockRange(scope);
            SferaParserRange block;
            while (parser.nextBlock(name, &block)) {
                SferaParserRange continuation;
                parser.getBlockRange(&continuation);
                load(block);
                parser.setBlockRange(&continuation);
            }
            parser.clearBlockRange();
        };
        // The renderer has a 10k per-frame submission pool, but SEF definitions can
        // legitimately describe a larger *potential* child-particle graph.  Keep a
        // separate allocation-safety ceiling here; actual frame pressure is handled
        // by SferaParticleSystemInstance::commit().
        constexpr std::size_t kExpandedParticleSlotSafetyLimit = 65536u;
        constexpr std::size_t kParticleInstanceSafetyLimit = 10000u;
        const auto add_budget = [&](std::size_t slots) {
            if (slots > kExpandedParticleSlotSafetyLimit - parsed.render_slot_budget)
                throw std::length_error("Effect definition exceeds expanded particle safety budget");
            parsed.render_slot_budget += slots;
        };
        load_blocks("effectmesh_def", nullptr, [&](const SferaParserRange& block) {
            auto mesh = std::make_shared<SferaEffectMeshDefinition>();
            if (!mesh->loadDefinition(filename, parser, block))
                g_sfera_effect_manager.reportError((std::string("CScriptedEffect::LoadScript(") + filename + "): Can't load effectmesh_def block"));
            add_budget(mesh->renderSlotCount());
            data->meshes.push_back(std::move(mesh));
        });
        load_blocks("psystem_def", nullptr, [&](const SferaParserRange& block) {
            auto particle = std::make_shared<SferaParticleSystemDefinition>();
            if (!particle->loadDefinition(filename, parser, block))
                g_sfera_effect_manager.reportError((std::string("CScriptedEffect::LoadScript(") + filename + "): Can't load psystem_def block"));
            prepare_particle_definition(particle);
            particles.push_back(std::move(particle));
        });
        for (auto& particle : particles) for (auto& link : particle->links) {
            link.target_index = find_index(particles, link.target_name);
            // The legacy loader left unresolved child names detached.  Keep the
            // definition and let the corresponding particle slots run without a child.
            // Old prototype expansion consumed one seed triplet per direct child.
            // Keep that global CRT sequence without retaining a mutable prototype graph.
            for (std::size_t child = 0; link.target_index >= 0 && child < link.instance_count; ++child) {
                for (int draw = 0; draw < 3; ++draw) (void)std::rand();
            }
        }
        // Compute expanded sizes from leaves, rejecting cycles before allocating instances.
        std::vector<std::size_t> remaining(particles.size()), budget(particles.size()), nodes(particles.size(), 1), depth(particles.size(), 1);
        std::vector<std::vector<std::pair<std::size_t, std::size_t>>> parents(particles.size());
        std::vector<std::size_t> ready;
        for (std::size_t index = 0; index < particles.size(); ++index) {
            budget[index] = particles[index]->particles.size();
            for (const auto& link : particles[index]->links) if (link.instance_count != 0 && link.target_index >= 0 && link.target_index < particles.size()) {
                const std::size_t target_index = link.target_index;
                parents[target_index].push_back({index, link.instance_count});
                ++remaining[index];
            }
            if (remaining[index] == 0) ready.push_back(index);
        }
        for (std::size_t cursor = 0; cursor < ready.size(); ++cursor) {
            const auto child = ready[cursor];
            for (const auto [parent, count] : parents[child]) {
                if ((budget[child] != 0 && count > (kExpandedParticleSlotSafetyLimit - budget[parent]) / budget[child]) ||
                    count > (kParticleInstanceSafetyLimit - nodes[parent]) / nodes[child]) {
                    throw std::length_error("Expanded particle graph exceeds its budget");
                }
                budget[parent] += budget[child] * count;
                nodes[parent] += nodes[child] * count;
                depth[parent] = std::max(depth[parent], depth[child] + 1);
                if (depth[parent] > 64) throw std::length_error("Particle graph nesting exceeds 64");
                if (--remaining[parent] == 0) ready.push_back(parent);
            }
        }
        if (ready.size() != particles.size()) throw std::invalid_argument("Cyclic particle graph");
        std::size_t instance_count = 0;
        for (std::size_t index = 0; index < particles.size(); ++index) {
            add_budget(budget[index]);
            if (nodes[index] > kParticleInstanceSafetyLimit - instance_count)
                throw std::length_error("Particle instance budget exceeded");
            instance_count += nodes[index];
            data->particles.push_back(std::move(particles[index]));
        }
        SferaParserRange range;
        if (parser.findBlock("effect_def", &range, nullptr, 1)) {
            std::string text;
            if (parser.findValue("effect_name", &range) && parser.readQuotedString(0, text)) parsed.assignScriptName(text);
            if (parser.findValue("effect_number", &range)) parsed.effect_id = effect_integer(parser, 0);
            if (parser.findValue("effect_time", &range)) parsed.cycle_length = parsed.lifetime_ticks = effect_integer(parser, 0);
            if (parser.findValue("effect_timelimit", &range)) parsed.cycle_length = effect_integer(parser, 0);
            if (parser.findValue("updvisible_only", &range)) data->update_visible_only = parser.readBool(0);
            if (parser.findValue("boundbox", &range)) {
                std::array<float, 6> bounds{};
                if (parser.readFloatSequence(0, bounds)) {
                    for (std::size_t axis = 0; axis < 3; ++axis) {
                        parsed.bounds_max[axis] = bounds[axis];
                        parsed.bounds_min[axis] = bounds[axis + 3];
                    }
                    parsed.spatial_gate_enabled = true;
                }
            }
            if (parser.findValue("daytime_work", &range)) {
                parsed.range_min = 1.0f - effect_real(parser, 0) / 24.0f;
                parsed.range_max = 1.0f - effect_real(parser, 1) / 24.0f;
            }
            if (parser.findValue("worktime", &range)) { data->work_time_min = effect_integer(parser, 0); data->work_time_max = effect_integer(parser, 1); }
            if (parser.findValue("sleeptime", &range)) { data->sleep_time_min = effect_integer(parser, 0); data->sleep_time_max = effect_integer(parser, 1); }
            if (parser.findValue("effftype", &range)) data->completes_immediately = effect_integer(parser, 0) != 0;
            SferaParserRange block;
            if (parser.findBlock("sound_def", &block, &range, 1)) data->sound = CSoundEffect::loadDefinition(parser, block);
            load_blocks("light_def", &range, [&](const SferaParserRange& light_range) {
                auto light = std::make_shared<SferaLightDefinition>();
                if (!light->load(parser, light_range))
                    g_sfera_effect_manager.reportError((std::string("CScriptedEffect::LoadScript(") + filename + "): Can't load light_def block"));
                data->lights.push_back(std::move(light));
            });
            if (parser.findValue("subeffects_num", &range)) {
                const int count = parser.readInt(0u);
                if (count > 0) data->subeffects.resize(count);
            }
            parser.setScanRange(&range);
            while (parser.nextValue("subeffect")) {
                const int index = parser.readInt(0u);
                if (index < 0 || index >= data->subeffects.size()) continue;
                auto& subeffect = data->subeffects[index];
                const auto kind = parser.tokenAt(1);
                if (parser.readQuotedString(2, text)) {
                    if (SferaText::asciiEqual(kind, "EFF_MESH")) {
                        subeffect.kind = SferaSubeffectDefinition::Kind::Mesh;
                        subeffect.definition_index = find_index(data->meshes, text);
                    } else if (SferaText::asciiEqual(kind, "EFF_PSYSTEM")) {
                        subeffect.kind = SferaSubeffectDefinition::Kind::ParticleSystem;
                        subeffect.definition_index = find_index(data->particles, text);
                    }
                }
                constexpr std::array attachments{"ATTACH_LEFTHAND", "ATTACH_RIGHTHAND", "ATTACH_BETWEENHANDS", "ATTACH_SWORD"};
                for (std::size_t attachment = 0; attachment < attachments.size(); ++attachment) {
                    if (SferaText::asciiEqual(parser.tokenAt(3), attachments[attachment])) subeffect.attach_mode = attachment + 1u;
                }
            }
            parser.clearScanRange();
        }
        IEffect::operator=(std::move(parsed));
        definition = std::move(data);
        pooled_instances.clear();
        return true;
    } catch (const std::exception& error) {
        const auto message = std::string("CScriptedEffect::LoadScript(") + filename + "): " + error.what();
        g_sfera_effect_manager.reportError(message);
        return false;
    }
}

void CScriptedEffect::resetRuntimeState() {
    if (definition == nullptr) return;
    deactivated = resources_released = activation_blocked = sound_started = false;
    listener = nullptr;
    initialize_scripted_phase(*this);
    if (sound_effect != nullptr && definition->sound != nullptr) sound_effect->reset();
    for (auto& light : lights) light.reset();
    for (auto& mesh : meshes) mesh.reset();
    for (auto& particle : particle_systems) particle->reset();
    const auto reset_children = [&](const auto& self, SferaParticleSystemInstance& parent) -> void {
        for (auto& child : parent.children) child->reset();
        for (auto& child : parent.children) self(self, *child);
    };
    for (auto& particle : particle_systems) reset_children(reset_children, *particle);
}
void CSpiralEffect::initializePreset() {
    initializeBaseState(Kind::Preset);
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
    spatial_gate_enabled = true;
    render_slot_budget = 80u;
}
void CMolEffect::initializePreset() {
    initializeBaseState(Kind::Preset);
    effect_id = 110u;
    cycle_length = 1u;
    lifetime_ticks = std::numeric_limits<std::uint32_t>::max();
    render_slot_budget = 4u;
    anchor = {};
    texture_phase = 0.0f;
    anchor_initialized = false;
    resource_id = -1;
    sound_effect = nullptr;
    sound_started = false;
}
void CBladeEffect::initializePreset() {
    initializeBaseState(Kind::Preset);
    effect_id = 340u;
    cycle_length = 64u;
    lifetime_ticks = 32u;
    render_slot_budget = 4u;
    anchor = {};
    progress = 0.0f;
    anchor_initialized = false;
    resource_id = -1;
}
void CGazerLakeEffect::initializePreset(std::uint32_t id, float effect_radius, std::size_t count) {
    initializeBaseState(Kind::Preset);
    emission_tick = 0u;
    emission_period = count;
    radius = effect_radius;
    effect_id = id;
    cycle_length = 192u;
    lifetime_ticks = std::numeric_limits<std::uint32_t>::max();
    spatial_gate_enabled = true;
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
    initializeBaseState(Kind::Preset);
    resource_id = -1;
    particles.clear();
    spawn_radius = 4.0f;
    spawn_radius_bias = 0.4f;
    spawn_rate = 120.0f;
    spawn_fraction = 0.0f;
    cycle_length = 64u;
    lifetime_ticks = std::numeric_limits<std::uint32_t>::max();
    effect_id = 400u;
    effect_kind = Kind::Rain;
    render_slot_budget = 3000u;
}
void CLightEffect::initializePreset() {
    initializeBaseState(Kind::Preset);
    effect_id = 200u;
    cycle_length = 1u;
    lifetime_ticks = std::numeric_limits<std::uint32_t>::max();
    color[0] = 255.0f;
    color[1] = 255.0f;
    color[2] = 255.0f;
    color[3] = 255.0f;
    radius = 0.0f;
    registered = false;
    light_index = -1;
    brightness_jitter = 0.0f;
    brightness_frequency = 1u;
    brightness_tick = 0u;
}
void IEffect::initializeEffect(const SferaEffectInitializeContext&) {}
void IEffect::updateEffect(const SferaEffectUpdateContext&) {}
void IEffect::queryEffectState(const SferaEffectQueryContext&) {
}
bool IEffect::activateEffect(bool visible) { return visible; }
void IEffect::deactivateEffect(bool) {}
void IEffect::renderEffect() {}

void IEffect::setParameters(std::span<const SferaEffectParameter>) {}
void IEffect::recycleEffect(std::unique_ptr<IEffect>) noexcept {}
void IEffect::resetEffect() {
}

bool IEffect::isEffectComplete() const {
    return false;
}

void CScriptedEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (definition == nullptr) return;
    const auto capacity = g_sfera_effect_manager.render_slots.size();
    const auto used = g_sfera_effect_manager.render_slot_count;
    if (context.visible && used >= capacity) {
        if (g_sfera_effect_manager.diagnostics.enabled) ++g_sfera_effect_manager.diagnostics.budget_rejected;
        return;
    }
    const auto spatial_frames = context.spatial_frames;
    if (!lights.empty() && !spatial_frames.empty()) {
        for (std::size_t index = 0u; index < lights.size(); ++index) {
            auto& light = lights[index];
            if (light.definition->attach_mode < spatial_frames.size()) light.update(spatial_frames[light.definition->attach_mode], context.age, 255u);
        }
    }
    if (definition->work_time_min != std::numeric_limits<std::uint32_t>::max()) {
        if (phase_ticks_remaining == 0u) {
            constexpr float random_scale = 3.0518509447574615e-05f;
            if (!work_phase_active) {
                phase_ticks_remaining = definition->work_time_min + SferaNumeric::truncateInt(std::rand() * random_scale * definition->work_time_max);
                work_phase_active = true;
                if (!particle_systems.empty()) {
                    for (std::size_t index = 0u; index < particle_systems.size(); ++index) {
                        auto& particle = *particle_systems[index];
                        particle.emission_fraction = 0.0f;
                        particle.emitting = true;
                        particle.runtime_active = true;
                        particle.runtime_stop_requested = false;
                    }
                }
            } else {
                phase_ticks_remaining = definition->sleep_time_min + SferaNumeric::truncateInt(std::rand() * random_scale * definition->sleep_time_min);
                work_phase_active = false;
                if (!particle_systems.empty()) {
                    for (std::size_t index = 0u; index < particle_systems.size(); ++index) {
                        auto& particle = *particle_systems[index];
                        particle.emission_fraction = 0.0f;
                        particle.emitting = false;
                        particle.runtime_stop_requested = true;
                    }
                }
            }
        } else {
            --phase_ticks_remaining;
        }
    }
    if (spatial_frames.empty() || context.world_frames.empty()) return;
    const auto world_frames = context.world_frames;
    for (std::size_t index = 0u; index < definition->subeffects.size(); ++index) {
        const SferaSubeffectDefinition& subeffect = definition->subeffects[index];
        if (subeffect.definition_index < 0 || subeffect.attach_mode >= spatial_frames.size() || subeffect.attach_mode >= world_frames.size()) continue;
        const SferaVec3F* spatial_frame = &spatial_frames[subeffect.attach_mode];
        const SferaMatrix4x4F* world_frame = &world_frames[subeffect.attach_mode];
        if (context.visible) {
            if (subeffect.kind == SferaSubeffectDefinition::Kind::Mesh) {
                if (meshes.empty() || subeffect.definition_index >= meshes.size()) continue;
                auto& mesh = meshes[subeffect.definition_index];
                mesh.update(spatial_frame, world_frame, context.age);
                mesh.commit();
            } else {
                if (particle_systems.empty() || subeffect.definition_index >= particle_systems.size()) continue;
                auto& particle = *particle_systems[subeffect.definition_index];
                particle.update(spatial_frame, world_frame, context.age);
                particle.commit();
            }
        } else if (subeffect.kind == SferaSubeffectDefinition::Kind::ParticleSystem && !particle_systems.empty() && subeffect.definition_index < particle_systems.size()) {
            particle_systems[subeffect.definition_index]->update(spatial_frame, world_frame, context.age);
        }
    }
}
void CScriptedEffect::updateEffect(const SferaEffectUpdateContext& context) {
    if (sound_effect == nullptr) return;
    if (!sound_started) {
        sound_effect->start(context.frame, sound_effect->startTime() < context.viewer_distance);
        sound_started = true;
        return;
    }
    sound_effect->update(context.frame, context.viewer_distance);
}
void CScriptedEffect::queryEffectState(const SferaEffectQueryContext& context) {
    for (auto& light : lights) {
        if (light.definition->attach_mode < context.frames.size()) light.update(context.frames[light.definition->attach_mode], context.age, 255u);
    }
}
bool CScriptedEffect::activateEffect(bool visible) {
    return definition != nullptr && (!definition->update_visible_only || visible);
}
void CScriptedEffect::deactivateEffect(bool preserve_resources) {
    if (deactivated) return;
    if (!preserve_resources) stopResources();
    resources_released = preserve_resources ? 0u : 1u;
    deactivated = true;
}
void CScriptedEffect::renderEffect() {
    if (!deactivated) return;
    if (sound_effect != nullptr && sound_effect->isComplete()) sound_started = false;
    deactivated = false;
}
std::unique_ptr<IEffect> CScriptedEffect::createEffectResources() {
    if (definition == nullptr) return nullptr;
    if (!pooled_instances.empty()) {
        auto effect = std::move(pooled_instances.back());
        pooled_instances.pop_back();
        effect->IEffect::operator=(*this);
        effect->resetRuntimeState();
        return effect;
    }
    auto effect = std::make_unique<CScriptedEffect>();
    effect->IEffect::operator=(*this);
    effect->definition = definition;
    initialize_scripted_phase(*effect);
    effect->sound_effect = definition->sound == nullptr ? nullptr : std::make_unique<CSoundEffect>(definition->sound);
    effect->lights.reserve(definition->lights.size());
    for (const auto& light : definition->lights) effect->lights.emplace_back(light);
    effect->meshes.reserve(definition->meshes.size());
    for (const auto& mesh : definition->meshes) effect->meshes.emplace_back(mesh);
    for (const auto& particle : definition->particles) {
        auto instance = std::make_unique<SferaParticleSystemInstance>(particle);
        instance->initializeClone();
        effect->particle_systems.push_back(std::move(instance));
    }
    const auto build_children = [&](const auto& self, SferaParticleSystemInstance& parent) -> void {
        for (std::size_t link_index = 0; link_index < parent.definition->links.size(); ++link_index) {
            const auto& link = parent.definition->links[link_index];
            if (link.instance_count == 0 || link.target_index < 0 || link.target_index >= definition->particles.size()) continue;
            const auto begin = parent.children.size();
            for (std::size_t child = 0; child < link.instance_count; ++child) {
                auto instance = std::make_unique<SferaParticleSystemInstance>(definition->particles.at(link.target_index));
                instance->initializeClone();
                parent.children.push_back(std::move(instance));
            }
            std::size_t cursor = begin;
            for (auto& slot : parent.render_slots) if (std::cmp_equal(slot.settings->link_index, link_index)) {
                if (cursor >= parent.children.size()) throw std::logic_error("Particle link count mismatch");
                slot.linked_particle_system = parent.children[cursor++].get();
            }
        }
        for (auto& child : parent.children) self(self, *child);
    };
    for (auto& particle : effect->particle_systems) build_children(build_children, *particle);
    return effect;
}

void CScriptedEffect::recycleEffect(std::unique_ptr<IEffect> effect) noexcept {
    auto* instance = effect != nullptr ? effect->asScriptedEffect() : nullptr;
    if (instance == nullptr || instance->definition != definition || pooled_instances.size() >= 16) return;
    instance->stopResources();
    std::unique_ptr<CScriptedEffect> reusable(instance);
    effect.release();
    try { pooled_instances.push_back(std::move(reusable)); }
    catch (const std::bad_alloc&) { }
}
bool CScriptedEffect::isEffectComplete() const {
    return definition != nullptr && definition->completes_immediately;
}
CScriptedEffect::~CScriptedEffect() { stopResources(); }

void CScriptedEffect::stopResources() noexcept {
    if (sound_effect != nullptr) sound_effect->stop();
    for (auto& light : lights) light.stop();
}
void CSpiralEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (!context.visible || context.spatial_frames.empty()) return;
    if (render_slot_budget + g_sfera_effect_manager.render_slot_count >= 10000u) return;
    const auto& base = context.spatial_frames.front();
    float opacity = 1.0f;
    if (context.age > 320.0f) opacity = (400.0f - context.age) / 80.0f;
    constexpr float pi = 3.1415929794311523f;
    const float age_phase = context.age * 0.05f;
    for (std::size_t ring = 0u; ring < 2u; ++ring) {
        float progress = 0.0f;
        for (std::size_t point = 0u; point < 40u; ++point, progress += 0.025f) {
            SferaEffectRenderSlot* slot = g_sfera_effect_manager.acquireRenderSlot();
            if (slot == nullptr) return;
            slot->resource_id = resource_id;
            slot->self_illumination = 255u;
            slot->additive = true;
            slot->custom_uv = false;
            const std::uint32_t red = 51u + SferaNumeric::truncateInt(204.0f * progress);
            const std::uint32_t green = 153u + SferaNumeric::truncateInt(51.0f * progress);
            const std::uint32_t blue = 153u - SferaNumeric::truncateInt(77.0f * progress);
            const std::uint32_t alpha = std::trunc((1.0f - progress) * 255.0f * opacity);
            for (std::size_t vertex = 0u; vertex < 4u; ++vertex) {
                slot->color[0][vertex] = red;
                slot->color[1][vertex] = green;
                slot->color[2][vertex] = blue;
                slot->color[3][vertex] = alpha;
            }
            const float angle = pi * progress * 1.2f + ring * pi - age_phase;
            SferaVec3F position{base.x - std::sin(angle) * 0.3f, base.y - progress, base.z - std::cos(angle) * 0.3f};
            g_sfera_effect_manager.finalizeBillboard(*slot, position, 0.15f);
        }
    }
}

std::unique_ptr<IEffect> CSpiralEffect::createEffectResources() {
    auto effect = std::make_unique<CSpiralEffect>();
    effect->initializePreset();
    effect->assignScriptName("spiral.effect0");
    effect->resource_id = g_sfera_textures.find("fx_flare");
    return effect;
}

void CMolEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (!context.visible || context.spatial_frames.empty() || render_slot_budget + g_sfera_effect_manager.render_slot_count >= 10000u) return;
    const auto& input = context.spatial_frames.front();
    if (!anchor_initialized) {
        anchor = input;
        anchor_initialized = true;
    }
    const SferaVec3F reference = g_sfera_world_objects.referencePosition();
    SferaEffectRenderSlot* slot = g_sfera_effect_manager.acquireRenderSlot();
    if (slot == nullptr) return;
    initialize_quad_slot(*slot, resource_id, true, true, 255);
    const SferaVec3F start_jitter{random_signed(0.2f), random_signed(0.2f), random_signed(0.2f)};
    const SferaVec3F end_jitter{random_signed(0.2f), random_signed(0.2f), random_signed(0.2f)};
    const SferaVec3F start = ((anchor) + (start_jitter));
    const SferaVec3F end = ((reference) + (end_jitter));
    const SferaVec3F direction = ((end) - (start));
    texture_phase += 0.05f;
    const float texture_length = (direction).length<float, float>() * 0.3f;
    const SferaVec3F end_width = ((((direction).cross<float>((((end) - (reference))))).unit<float, float, false, true>(0.0f, SferaVec3F{})) * (0.8f));
    const SferaVec3F start_width = ((((direction).cross<float>((((start) - (reference))))).unit<float, float, false, true>(0.0f, SferaVec3F{})) * (0.8f));
    slot->position[0] = ((end) + (end_width));
    slot->position[1] = ((end) - (end_width));
    slot->position[2] = ((start) - (start_width));
    slot->position[3] = ((start) + (start_width));
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
        sound_started = true;
        return;
    }
    if (!sound_started) {
        sound_effect->start(context.frame, sound_effect->startTime() < context.viewer_distance);
        sound_started = true;
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
std::unique_ptr<IEffect> CMolEffect::createEffectResources() {
    auto effect = std::make_unique<CMolEffect>();
    effect->initializePreset();
    effect->assignScriptName("molniya.effect110");
    effect->resource_id = g_sfera_textures.find("fx_light");
    if (effect->resource_id == -1) g_sfera_effect_manager.reportError("CMolEffect::Texture not found 'fx_light'");
    effect->sound_effect = g_sfera_sound_runtime.createEffect(110u);
    return effect;
}

CMolEffect::~CMolEffect() = default;
void CBladeEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (!context.visible || context.spatial_frames.empty() || render_slot_budget + g_sfera_effect_manager.render_slot_count >= 10000u) return;
    const auto& input = context.spatial_frames.front();
    if (!anchor_initialized) {
        anchor = input;
        anchor_initialized = true;
    }
    const SferaVec3F reference = g_sfera_world_objects.referencePosition();
    SferaEffectRenderSlot* slot = g_sfera_effect_manager.acquireRenderSlot();
    if (slot == nullptr) return;
    progress += 0.05f;
    if (progress > 1.0f) progress = 1.0f;
    std::uint32_t alpha = 255u;
    if (progress > 0.8f) alpha = std::trunc((1.0f - progress) * 1275.0f);
    slot->resource_id = resource_id;
    slot->self_illumination = 255u;
    slot->additive = true;
    slot->custom_uv = true;
    for (std::size_t vertex = 0u; vertex < 4u; ++vertex) {
        slot->color[0][vertex] = 255u;
        slot->color[1][vertex] = 255u;
        slot->color[2][vertex] = 255u;
        slot->color[3][vertex] = alpha;
    }
    const SferaVec3F path = ((input) - (anchor));
    const SferaVec3F end = ((anchor) + (((path) * (progress))));
    const SferaVec3F direction = (((anchor) - (end))).unit<float, float, false, true>(0.0f, SferaVec3F{});
    const SferaVec3F back = ((end) - (((direction) * (0.5f))));
    const SferaVec3F back_width = ((((((back) - (reference))).cross<float>((((back) - (end))))).unit<float, float, false, true>(0.0f, SferaVec3F{})) * (0.8f));
    const SferaVec3F end_width = ((((((end) - (reference))).cross<float>((((back) - (end))))).unit<float, float, false, true>(0.0f, SferaVec3F{})) * (0.8f));
    slot->position[0] = ((back) + (back_width));
    slot->position[1] = ((back) - (back_width));
    slot->position[2] = ((end) - (end_width));
    slot->position[3] = ((end) + (end_width));
    slot->uv[0][0] = 0.0f;
    slot->uv[0][1] = 0.0f;
    slot->uv[1][0] = 1.0f;
    slot->uv[1][1] = progress;
    slot->uv[2][0] = 1.0f;
    slot->uv[2][1] = 1.0f;
    slot->uv[3][0] = 0.0f;
    slot->uv[3][1] = progress;
}

std::unique_ptr<IEffect> CBladeEffect::createEffectResources() {
    auto effect = std::make_unique<CBladeEffect>();
    effect->initializePreset();
    effect->assignScriptName("blade");
    effect->resource_id = g_sfera_textures.find("fx_blade");
    if (effect->resource_id == -1) g_sfera_effect_manager.reportError("CBladeEffect::Texture not found 'fx_blade'");
    return effect;
}

void CGazerLakeEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (context.spatial_frames.empty()) return;
    if (emission_period != 0u && emission_tick % emission_period == 0u) {
        for (SferaGazerEffectSlot& slot : slots) {
            if (slot.age != -1.0f) continue;
            constexpr float random_scale = 3.0518509447574615e-05f;
            constexpr float pi = 3.1415929794311523f;
            const float azimuth = std::rand() * random_scale * (2.0f * pi);
            const float elevation = (std::rand() * random_scale - 0.5f) * pi;
            const float elevation_cos = std::cos(elevation);
            slot.offset.x = std::sin(azimuth) * radius * elevation_cos;
            slot.offset.y = 0.0f;
            slot.offset.z = std::cos(azimuth) * radius * elevation_cos;
            slot.age = 0.0f;
            break;
        }
    }
    emission_tick += 2u;
    const auto& base = context.spatial_frames.front();
    for (SferaGazerEffectSlot& slot : slots) {
        if (slot.age == -1.0f || slot.effect == nullptr) continue;
        slot.age += 2.0f;
        if (slot.age > 192.0f) {
            slot.age = -1.0f;
            continue;
        }
        SferaVec3F position{base.x + slot.offset.x, base.y + slot.offset.y, base.z + slot.offset.z};
        SferaEffectInitializeContext child_context{{&position, 1}, slot.age, context.visible, {}};
        slot.effect->initializeEffect(child_context);
    }
}

std::unique_ptr<IEffect> CGazerLakeEffect::createEffectResources() {
    auto effect = std::make_unique<CGazerLakeEffect>();
    effect->initializePreset(effect_id, radius, emission_period);
    effect->assignScriptName("gazer.lake");
    auto source = g_sfera_effect_manager.findDefinition(729u);
    if (source != nullptr) for (auto& slot : effect->slots) {
        slot.effect = source->createEffectResources();
        slot.age = -1.0f;
    }
    return effect;
}

CGazerLakeEffect::~CGazerLakeEffect() = default;
void CRainEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (!context.visible || context.spatial_frames.empty() || resource_id == -1 || particles.empty() || render_slot_budget + g_sfera_effect_manager.render_slot_count >= 10000u) return;
    constexpr std::uint32_t particle_count = 3000u;
    constexpr float random_scale = 3.0518509447574615e-05f;
    constexpr float pi = 3.1415929794311523f;
    const float requested = spawn_rate + spawn_fraction;
    std::uint32_t spawn_count = std::trunc(requested);
    spawn_fraction = requested - spawn_count;
    for (std::size_t index = 0u; index < particle_count && spawn_count != 0u; ++index) {
        SferaRainParticle& particle = particles[index];
        if (particle.remaining_life >= 0.0f) continue;
        particle.initial_life = particle.remaining_life = 30.0f + std::rand() * random_scale * 20.0f;
        particle.fall_speed = 0.06f + std::rand() * random_scale * 0.06f;
        particle.half_width = 0.025f + std::rand() * random_scale * 0.025f;
        const float angle = std::rand() * random_scale * (2.0f * pi);
        const float elevation = (std::rand() * random_scale - 0.5f) * pi;
        const float radius = spawn_radius_bias + spawn_radius * std::cos(elevation);
        particle.offset = {std::sin(angle) * radius, 0.0f, std::cos(angle) * radius};
        --spawn_count;
    }
    const auto& base = context.spatial_frames.front();
    for (std::size_t index = 0u; index < particle_count; ++index) {
        SferaRainParticle& particle = particles[index];
        if (particle.remaining_life < 0.0f) continue;
        particle.remaining_life -= 2.0f;
        const float fade = 1.0f - particle.remaining_life / particle.initial_life;
        particle.offset.y += particle.fall_speed;
        particle.alpha = fade > 0.1f ? 200u : SferaNumeric::truncateInt(fade * 2000.0f);
        SferaEffectRenderSlot* slot = g_sfera_effect_manager.acquireRenderSlot();
        if (slot == nullptr) return;
        slot->resource_id = resource_id;
        slot->self_illumination = 0u;
        slot->additive = true;
            slot->custom_uv = false;
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex) {
            slot->color[0][vertex] = 155u;
            slot->color[1][vertex] = 155u;
            slot->color[2][vertex] = 155u;
            slot->color[3][vertex] = particle.alpha;
        }
        SferaVec3F center = ((base) + (particle.offset));
        center.y -= 4.0f;
        set_full_quad_uv(*slot);
        const SferaVec3F viewer{g_sfera_effect_manager.viewer_position.x, g_sfera_effect_manager.viewer_position.y, g_sfera_effect_manager.viewer_position.z};
        const SferaVec3F to_viewer = ((center) - (viewer));
        SferaVec3F right{}, up{};
        build_y_up_billboard_axes(to_viewer, particle.half_width, particle.half_width, right, up);
        const SferaVec3F left_center = ((center) - (right));
        const SferaVec3F right_center = ((center) + (right));
        slot->position[0] = ((left_center) - (up));
        slot->position[1] = ((left_center) + (up));
        slot->position[2] = ((right_center) + (up));
        slot->position[3] = ((right_center) - (up));
    }
}

std::unique_ptr<IEffect> CRainEffect::createEffectResources() {
    auto effect = std::make_unique<CRainEffect>();
    effect->initializePreset();
    effect->assignScriptName("rain");
    effect->resource_id = g_sfera_textures.find("fx_rain");
    if (effect->resource_id == -1) g_sfera_effect_manager.reportError("CRainEffect::Texture not found 'fx_rain'");
    effect->particles.resize(3000u);
    for (auto& particle : effect->particles) particle.remaining_life = -1.0f;
    return effect;
}

CRainEffect::~CRainEffect() = default;
void CLightEffect::initializeEffect(const SferaEffectInitializeContext& context) {
    if (context.spatial_frames.empty()) return;
    const auto& position = context.spatial_frames.front();
    if (!registered) light_index = g_sfera_light_runtime.create(position, color, radius);
    if (light_index == -1) return;
    registered = true;
    float output_color[4]{color[0], color[1], color[2], color[3]};
    if (brightness_frequency != 0u && brightness_tick % brightness_frequency == 0u) {
        constexpr float random_scale = 3.0518509447574615e-05f;
        const float jitter = (std::rand() - std::rand()) * random_scale * brightness_jitter;
        output_color[0] += output_color[0] * jitter;
        output_color[1] += output_color[1] * jitter;
        output_color[2] += output_color[2] * jitter;
    }
    ++brightness_tick;
    g_sfera_light_runtime.write(light_index, position, output_color, radius);
}

bool CLightEffect::activateEffect(bool visible) {
    if (visible) return true;
    g_sfera_light_runtime.release(light_index);
    light_index = -1;
    registered = false;
    return false;
}
void CLightEffect::deactivateEffect(bool) {
    if (deactivated) return;
    g_sfera_light_runtime.release(light_index);
    light_index = -1;
    registered = false;
    deactivated = true;
}
void CLightEffect::renderEffect() {
    if (deactivated) deactivated = false;
}
std::unique_ptr<IEffect> CLightEffect::createEffectResources() {
    auto effect = std::make_unique<CLightEffect>();
    effect->initializePreset();
    effect->assignScriptName("light_source.eff");
    return effect;
}
void CLightEffect::setParameters(std::span<const SferaEffectParameter> parameters) {
    for (const auto& parameter : parameters) std::visit([&](const auto& value) {
        using T = std::decay_t<decltype(value)>;
        if constexpr (std::is_same_v<T, SferaEffectParameter::Color>) {
            for (std::size_t channel = 0; channel < value.channels.size(); ++channel) color[channel] = value.channels[channel];
        } else if constexpr (std::is_same_v<T, SferaEffectParameter::Radius>) radius = value.value;
        else if constexpr (std::is_same_v<T, SferaEffectParameter::Jitter>) brightness_jitter = value.value / 100.0f;
        else if constexpr (std::is_same_v<T, SferaEffectParameter::Frequency>) brightness_frequency = value.value;
    }, parameter.value);
}
CLightEffect::~CLightEffect() { g_sfera_light_runtime.release(light_index); }

void GrassMapMngr::loadGrassMap(int column, int row, std::span<std::uint8_t> destination) {
    if (destination.empty()) return;
    auto filename = std::format("Landscape\\GrassMap\\GrassMap_{:02d}_{:02d}.bin", column, row);
    std::ifstream stream;
    for (const std::string& path : g_sfera_files.candidatePaths(filename, true)) { stream.open(path, std::ios::binary); if (stream.is_open()) break; stream.clear(); }
    if (stream.is_open()) SferaBinary::read(stream, destination);
}
PlayerList::PlayerList(std::string list_name, std::size_t minimum, std::uint32_t mode, bool notify)
    : name(std::move(list_name)), minimum_size(minimum), publish_mode(mode), notify_relationships(notify), entries_(30) {}

PlayerListEntry* PlayerList::find(std::string_view key) {
    const auto found = index_.find(key);
    return found == index_.end() ? nullptr : entries_[found->second].get();
}

PlayerListEntry* PlayerList::scanFrom(std::size_t begin) {
    for (std::size_t slot = begin; slot < entries_.size(); ++slot) if (entries_[slot] != nullptr) {
        cursor_ = slot;
        return entries_[slot].get();
    }
    return nullptr;
}

PlayerListEntry* PlayerList::first() {
    cursor_.reset();
    return scanFrom(0);
}

PlayerListEntry* PlayerList::next() {
    return cursor_.has_value() ? scanFrom(*cursor_ + 1) : nullptr;
}

void PlayerList::finishNotificationScan() {
    // The removed notification hooks were no-ops, but their traversal exhausted this cursor.
    const auto last = std::find_if(entries_.rbegin(), entries_.rend(), [](const auto& entry) { return entry != nullptr; });
    if (last == entries_.rend()) cursor_.reset();
    else cursor_ = std::distance(last, entries_.rend()) - 1;
}

int PlayerList::insert(PlayerListEntry value) {
    if (value.payload.size() > 256) return -3;
    const auto found = index_.find(value.name);
    if (found != index_.end()) {
        *entries_[found->second] = std::move(value);
        if (notify_relationships) finishNotificationScan();
        return -105;
    }
    try {
        auto entry = std::make_unique<PlayerListEntry>(std::move(value));
        const auto vacant = std::find(entries_.begin(), entries_.end(), nullptr);
        const std::size_t slot = vacant - entries_.begin();
        if (vacant == entries_.end()) entries_.push_back(nullptr);
        index_.emplace(entry->name, slot);
        entries_[slot] = std::move(entry);
        if (notify_relationships) finishNotificationScan();
        return 0;
    } catch (const std::bad_alloc&) { return -20; }
    catch (const std::length_error&) { return -20; }
}

int PlayerList::remove(std::string_view key) {
    const auto found = index_.find(key);
    if (found == index_.end()) return notify_relationships ? -10 : -8;
    if (notify_relationships) finishNotificationScan();
    const auto slot = found->second;
    index_.erase(found);
    entries_[slot].reset();
    return size() < minimum_size ? -6 : 0;
}

const PlayerListEntry* PlayerList::select(const std::array<int, 3>& filters) {
    if (std::all_of(filters.begin(), filters.end(), [](auto filter) { return filter == -1; })) return nullptr;
    const auto matches = [&](const PlayerListEntry& entry) {
        for (std::size_t index = 0; index < filters.size(); ++index) {
            if (filters[index] != -1 && filters[index] != entry.attributes[index]) return false;
        }
        return true;
    };
    std::size_t count = 0;
    for (auto* entry = first(); entry != nullptr; entry = next()) if (matches(*entry)) ++count;
    if (count == 0) return nullptr;
    auto target = std::rand() % count;
    for (auto* entry = first(); entry != nullptr; entry = next()) if (matches(*entry) && target-- == 0) return entry;
    return nullptr;
}

PlayerList* PlayerLists::find(std::string_view name) const {
    const auto found = lists_.find(name);
    return found == lists_.end() ? nullptr : found->second.get();
}

int PlayerLists::create(std::string_view name, int minimum, std::uint32_t mode, bool notify) {
    if (find(name) != nullptr) return -101;
    std::unique_ptr<PlayerList> list;
    try { list = std::make_unique<PlayerList>(std::string(name), std::max(minimum, 0), mode, notify); }
    catch (const std::bad_alloc&) { return -14; }
    try { lists_.emplace(list->name, std::move(list)); }
    catch (const std::bad_alloc&) { return -20; }
    return 0;
}

int PlayerLists::erase(std::string_view name) {
    const auto found = lists_.find(name);
    if (found == lists_.end()) return -8;
    if (current_ == found->second.get()) current_ = nullptr;
    lists_.erase(found);
    return 0;
}

int PlayerLists::removeItem(PlayerList& list, std::string_view key) {
    const auto result = list.remove(key);
    if (result == -6) erase(list.name);
    return result;
}

void PlayerLists::clear() noexcept {
    current_ = nullptr;
    lists_.clear();
}

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

namespace {
std::uint32_t effect_flag(std::string_view token) {
        if (token.empty()) return 0u;
        struct Flag {
            std::string_view name;
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
        for (const Flag& flag : flags) if (SferaText::asciiEqual(token, flag.name)) return flag.value;
        return 0u;
    }

    std::shared_ptr<const SferaEffectMeshResource> find_mesh_resource(std::string_view name) {
        if (name.empty()) return nullptr;
        const auto& resources = g_sfera_effect_manager.mesh_resources;
        const auto found = std::find_if(resources.begin(), resources.end(), [&](const auto& resource) {
            return SferaText::asciiEqual(resource->name, name);
        });
        return found == resources.end() ? nullptr : *found;
    }

    std::shared_ptr<const SferaEffectTrack> load_mesh_vector_track(SferaSimpleParser& parser, const SferaParserRange& range, bool degrees) {
        auto track = load_effect_track(parser, range, 1,
            [](SferaEffectTrackKey& key) { key.value.emplace<SferaEffectTrackKey::Vector>(); },
            [&](SferaEffectTrackKey& key) {
                auto& value = std::get<SferaEffectTrackKey::Vector>(key.value);
                effect_vector(parser, 2u, value.minimum);
                if (degrees) {
                    value.minimum.x *= 0.01745329424738884f;
                    value.minimum.y *= 0.01745329424738884f;
                    value.minimum.z *= 0.01745329424738884f;
                }
            });
        if (track != nullptr && parser.findValue("interpolation", &range) && SferaText::asciiEqual(parser.tokenAt(0u), "I_COSINE")) track->cosine_interpolation = true;
        return track;
    }
    std::shared_ptr<const SferaEffectTrack> load_mesh_color_track(SferaSimpleParser& parser, const SferaParserRange& range) {
        return load_effect_track(parser, range, 2,
            [](SferaEffectTrackKey& key) { key.value.emplace<SferaEffectTrackKey::Color>(); },
            [&](SferaEffectTrackKey& key) {
                auto& color = std::get<SferaEffectTrackKey::Color>(key.value);
                for (std::size_t channel = 0; channel < 4; ++channel) {
                    color.minimum.channels[channel] = SferaNumeric::word(parser.readInt(2u + channel)) & 0xffu;
                    if (key.mode != SferaEffectTrackKey::Mode::Fixed)
                        color.range.channels[channel] = SferaNumeric::word(parser.readInt(6u + channel)) & 0xffu;
                }
            });
    }
    void evaluate_mesh_color(const SferaEffectTrack& track, float age, SferaColor& output, const std::uint16_t* random_values, std::uint32_t random_offset_0, std::uint32_t random_offset_1) {
        if (track.keys.empty()) return;
        const auto& keys = track.keys;
        auto sample = [&](std::size_t index, std::uint32_t random_offset, std::uint8_t* value) {
            const auto& color = std::get<SferaEffectTrackKey::Color>(keys[index].value);
            for (std::size_t channel = 0u; channel < 4u; ++channel) {
                int component = color.minimum.channels[channel];
                if (keys[index].mode == SferaEffectTrackKey::Mode::Random && random_values != nullptr) {
                    const std::uint32_t random_value = random_values[(index + channel) % 256u] + random_offset;
                    const float random = random_value * 1.5259021893143654e-05f;
                    component += SferaNumeric::truncateInt(random * color.range.channels[channel]);
                }
                value[channel] = std::min(component, 255);
            }
        };
        const auto [index, factor] = track.interval(age, false);
        if (index + 1 == keys.size()) {
            sample(index, random_offset_0, output.channels.data());
            return;
        }
        std::uint8_t begin[4]{};
        std::uint8_t end[4]{};
        sample(index, random_offset_0, begin);
        sample(index + 1u, random_offset_1, end);
        const int factor_byte = std::trunc(factor * 255.0f);
        for (std::size_t channel = 0u; channel < 4u; ++channel) {
            const int delta = end[channel] - begin[channel];
            output.channels[channel] = begin[channel] + ((delta * factor_byte) >> 8);
        }
    }
    float particle_random_unit(const std::uint16_t* values, std::size_t index, std::uint32_t offset) {
        if (values == nullptr) return std::rand() * 3.0518509447574615e-05f;
        return (values[index % 256u] + offset) * 1.5259021893143654e-05f;
    }
    SferaVec3F sample_random_vector_key(const SferaEffectTrackKey& key, const std::uint16_t* values, std::size_t key_index, std::uint32_t seed0, std::uint32_t seed1) {
        const auto& value = std::get<SferaEffectTrackKey::Vector>(key.value);
        SferaVec3F result = value.minimum;
        if (key.mode == SferaEffectTrackKey::Mode::Fixed) return result;
        result.x += particle_random_unit(values, key_index * 3u, seed0) * value.range.x;
        result.y += particle_random_unit(values, key_index * 3u + 1u, seed1) * value.range.y;
        result.z += particle_random_unit(values, key_index * 3u + 2u, seed0 + seed1) * value.range.z;
        return result;
    }
    void evaluate_random_vector(const SferaEffectTrack* track, float age, SferaVec3F& output, const std::uint16_t* values, std::uint32_t seed0, std::uint32_t seed1) {
        output = {};
        if (track == nullptr || track->keys.empty()) return;
        const auto [index, factor] = track->interval(age, true);
        const auto begin = sample_random_vector_key(track->keys[index], values, index, seed0, seed1);
        output = begin;
        if (index + 1 == track->keys.size()) return;
        const auto finish = sample_random_vector_key(track->keys[index + 1], values, index + 1, seed0, seed1);
        output = {begin.x + (finish.x - begin.x) * factor, begin.y + (finish.y - begin.y) * factor, begin.z + (finish.z - begin.z) * factor};
    }
    SferaVec3F reciprocal_magnet_factor(const SferaVec3F& source) {
        const auto reciprocal = [](float value) { return value == 0.0f ? 0.0f : 1.0f / value; };
        return {reciprocal(source.x), reciprocal(source.y), reciprocal(source.z)};
    }
    void evaluate_magnet_factor(const SferaEffectTrack* track, float age, SferaVec3F& output,
                                const std::uint16_t* values, std::uint32_t seed0, std::uint32_t seed1) {
        SferaVec3F encoded{};
        evaluate_random_vector(track, age, encoded, values, seed0, seed1);
        output = reciprocal_magnet_factor(encoded);
    }

    SferaParticleSystemDefinition::Shape particle_shape(std::string_view name) {
        if (SferaText::asciiEqual(name, "EMITSHAPE_LINE")) return SferaParticleSystemDefinition::Shape::Line;
        if (SferaText::asciiEqual(name, "EMITSHAPE_DISK")) return SferaParticleSystemDefinition::Shape::Disk;
        if (SferaText::asciiEqual(name, "EMITSHAPE_SPHERE")) return SferaParticleSystemDefinition::Shape::Sphere;
        if (SferaText::asciiEqual(name, "EMITSHAPE_BOX")) return SferaParticleSystemDefinition::Shape::Box;
        if (SferaText::asciiEqual(name, "EMITSHAPE_CYLINDER")) return SferaParticleSystemDefinition::Shape::Cylinder;
        if (SferaText::asciiEqual(name, "EMITSHAPE_RING")) return SferaParticleSystemDefinition::Shape::Ring;
        if (SferaText::asciiEqual(name, "EMITSHAPE_DISK2")) return SferaParticleSystemDefinition::Shape::Annulus;
        return SferaParticleSystemDefinition::Shape::Points;
    }
    void load_track_array(SferaSimpleParser& parser, const SferaParserRange& range, std::string_view block_name, std::vector<std::shared_ptr<const SferaEffectTrack>>& tracks, bool color) {
        if (tracks.empty() || parser.countBlocks(block_name, &range) <= 0) return;
        const bool scalar = SferaText::asciiEqual(block_name, "size_track");
        SferaParserRange block{};
        parser.setBlockRange(&range);
        while (parser.nextBlock(block_name, &block)) {
            int index = 0;
            if (parser.findValue("track_num", &block)) index = parser.readInt(0u);
            if (index < 0 || index >= tracks.size()) continue;
            tracks[index] = scalar ? sfera_load_scalar_effect_track(&parser, &block) : color ? load_mesh_color_track(parser, block) : sfera_load_vector_effect_track(&parser, &block);
        }
        parser.clearBlockRange();
    }
    void evaluate_particle_scalar(const SferaEffectTrack* track, float age, float& output, const std::uint16_t* values, std::uint32_t seed) {
        if (track != nullptr) track->evaluateScalar(age, output, values == nullptr ? std::span<const std::uint16_t>{} : std::span<const std::uint16_t>{values, 256}, seed);
    }
    void apply_particle_rotation(SferaMatrix4x4F& transform, std::uint32_t flags, const SferaVec3F& rotation) {
        if ((flags & (1u << 0u)) != 0u) transform = SferaMatrix4x4F::fromXyzRotation(rotation);
        else if ((flags & (1u << 2u)) != 0u) transform = SferaMatrix4x4F::fromAxisRotation<float>(SferaMatrix4x4F::Axis::y, rotation.y);
        else if ((flags & (1u << 3u)) != 0u) transform = SferaMatrix4x4F::fromAxisRotation<float>(SferaMatrix4x4F::Axis::z, rotation.z);
        else if ((flags & (1u << 1u)) != 0u) transform = SferaMatrix4x4F::fromAxisRotation<float>(SferaMatrix4x4F::Axis::x, rotation.x);
    }

    void particle_generate(SferaParticleSystemInstance& system, std::size_t index) {
        if (system.render_slots.empty() || index >= system.render_slots.size()) return;
        auto& slot = system.render_slots[index];
        const auto* table = g_sfera_effect_manager.particle_random_table.data();
        if (system.definition->lifetime_track != nullptr) slot.state.total_lifetime = system.lifetime;
        else slot.state.total_lifetime = system.lifetime + std::rand() * 3.0518509447574615e-05f * system.definition->lifetime_random_factor;
        slot.state.random_row = std::rand() % 254;
        slot.state.random_seed_0 = std::rand();
        slot.state.random_seed_1 = std::rand();
        const std::uint16_t* random_values = table == nullptr ? nullptr : table + (slot.state.random_row << 8u);
        if (slot.linked_particle_system != nullptr && (slot.linked_particle_system->definition->flags & (1u << 24u)) != 0u && !slot.linked_particle_system->render_slots.empty()) for (std::size_t child = 0u; child < slot.linked_particle_system->render_slots.size(); ++child) slot.linked_particle_system->render_slots[child].state.remaining_lifetime = -1.0f;
        if (slot.settings->size_track != nullptr) evaluate_particle_scalar(slot.settings->size_track, 0.0f, slot.state.size, random_values, slot.state.random_seed_0);
        if (slot.settings->color_track != nullptr) evaluate_mesh_color(*slot.settings->color_track, 0.0f, slot.state.color, random_values, slot.state.random_seed_0, slot.state.random_seed_1);
        slot.state.remaining_lifetime = slot.state.total_lifetime;
        slot.state.position = {};
        slot.state.texture_frame = (system.definition->flags & (1u << 19u)) != 0u && system.definition->texture_frames.size() != 0u ? (std::rand() % system.definition->texture_frames.size()) : 0.0f;
        if (!std::in_range<std::int32_t>(index)) throw std::length_error("Particle slot index exceeds 32-bit range");
        const std::int32_t slot_index = index;
        if (system.definition->random_seed > 0) {
            const std::int32_t seed_value = system.definition->random_seed + system.definition->random_factor * slot_index;
            std::srand(SferaNumeric::word(seed_value));
        }
        constexpr float pi = 3.1415929794311523f;
        constexpr float two_pi = 6.283185958862305f;
        const float random_signed = (std::rand() - std::rand()) * 3.0518509447574615e-05f;
        switch (system.definition->shape) {
            case SferaParticleSystemDefinition::Shape::Points: if (!system.definition->shape_points.empty()) slot.state.position = system.definition->shape_points[system.definition->random_seed == 0 ? std::min(index, system.definition->shape_points.size() - 1u) : std::rand() % system.definition->shape_points.size()];
            break;
            case SferaParticleSystemDefinition::Shape::Line: {
                const float length = (system.definition->direction).length<float, float>();
                const float scalar = system.definition->random_seed == 0 ? length / std::max(system.render_slots.size(), std::size_t{1}) * index - length * 0.5f : length * random_signed * 0.5f;
                slot.state.position = {system.definition->direction.x * scalar, system.definition->direction.y * scalar, system.definition->direction.z * scalar};
                break;
            }
            case SferaParticleSystemDefinition::Shape::Disk: {
                const float a = std::rand() * 3.0518509447574615e-05f * two_pi;
                const float p = random_signed * pi * 0.5f;
                slot.state.position = {std::sin(a) * system.radius * std::cos(p), 0.0f, std::cos(a) * system.radius * std::cos(p)};
                break;
            }
            case SferaParticleSystemDefinition::Shape::Sphere: {
                const float a = std::rand() * 3.0518509447574615e-05f * two_pi;
                const float p = random_signed * pi * 0.5f;
                slot.state.position = {std::cos(a) * system.radius * std::cos(p), std::sin(p) * system.radius, std::sin(a) * system.radius * std::cos(p)};
                break;
            }
            case SferaParticleSystemDefinition::Shape::Box: slot.state.position = {(std::rand() - std::rand()) * 3.0518509447574615e-05f * system.width * 0.5f, (std::rand() - std::rand()) * 3.0518509447574615e-05f * system.radius * 0.5f, (std::rand() - std::rand()) * 3.0518509447574615e-05f * system.height * 0.5f};
            break;
            case SferaParticleSystemDefinition::Shape::Cylinder: {
                const float a = std::rand() * 3.0518509447574615e-05f * two_pi;
                const float p = random_signed * pi * 0.5f;
                slot.state.position = {std::sin(a) * system.radius * std::cos(p), (std::rand() - std::rand()) * 3.0518509447574615e-05f * system.height * 0.5f, std::cos(a) * system.radius * std::cos(p)};
                break;
            }
            case SferaParticleSystemDefinition::Shape::Ring: {
                const float a = system.definition->random_seed == 0 ? two_pi * (system.definition->random_factor + slot_index) / std::max(system.render_slots.size(), std::size_t{1}) : std::rand() * 3.0518509447574615e-05f * two_pi;
                slot.state.position = {std::sin(a) * system.radius, std::rand() * 3.0518509447574615e-05f * system.height, std::cos(a) * system.radius};
                break;
            }
            case SferaParticleSystemDefinition::Shape::Annulus: {
                const float a = std::rand() * 3.0518509447574615e-05f * two_pi;
                const float p = random_signed * pi * 0.5f;
                const float radial = system.width + system.radius * std::cos(p);
                slot.state.position = {std::sin(a) * radial, 0.0f, std::cos(a) * radial};
                break;
            }
        }
        if ((system.definition->flags & (1u << 10u)) != 0u) {
            if ((system.definition->flags & (1u << 5u)) != 0u) {
                slot.state.position.x += system.current_position.x;
                slot.state.position.y += system.current_position.y;
                slot.state.position.z += system.current_position.z;
            } else slot.state.position = (system.transform).transformPoint<float>(slot.state.position);
        }
        slot.state.position.x += system.emitter_position.x;
        slot.state.position.y += system.emitter_position.y;
        slot.state.position.z += system.emitter_position.z;
        slot.state.spawn_position = slot.state.position;
        if (system.definition->random_seed > 0) { const std::uint64_t time_seed = std::time(nullptr); std::srand(time_seed & UINT32_MAX); }
    }
    void prepare_particle_definition(const std::shared_ptr<SferaParticleSystemDefinition>& definition) {
        SferaParticleSystemInstance initial(definition);
        initial.runtime_random_row = std::rand() % 254;
        initial.runtime_random_seed_0 = std::rand();
        initial.runtime_random_seed_1 = std::rand();
        if ((definition->flags & (1u << 6u)) != 0u) {
            const auto* random_values = g_sfera_effect_manager.particle_random_table.data() + initial.runtime_random_row * 256u;
            evaluate_particle_scalar(definition->lifetime_track.get(), 0.0f, initial.lifetime, random_values, initial.runtime_random_seed_0);
            evaluate_random_vector(definition->emission_position_track.get(), 0.0f, initial.emitter_position, random_values, initial.runtime_random_seed_0, initial.runtime_random_seed_1);
            for (std::size_t index = 0; index < initial.render_slots.size(); ++index) particle_generate(initial, index);
            definition->lifetime = initial.lifetime;
            definition->emitter_position = initial.emitter_position;
            for (std::size_t index = 0; index < initial.render_slots.size(); ++index) definition->particles[index].initial = initial.render_slots[index].state;
        }
    }
    void particle_emit(SferaParticleSystemInstance& system, float delta) {
        if (system.render_slots.empty()) return;
        const float accumulated = system.emission_count * delta + system.emission_fraction;
        const std::uint32_t requested = accumulated <= 0.0f ? 0u : SferaNumeric::truncateInt(std::floor(accumulated));
        system.emission_fraction = accumulated - requested;
        if (requested == 0u) return;
        const SferaVec3F movement{system.current_position.x - system.previous_position.x, system.current_position.y - system.previous_position.y, system.current_position.z - system.previous_position.z};
        float movement_factor = 0.0f;
        const bool position_emit = (system.definition->flags & (1u << 18u)) != 0u && (movement).length<float, float>() > 0.0f;
        const float step = position_emit && accumulated != 0.0f ? 1.0f / accumulated : 0.0f;
        std::uint32_t emitted = 0u;
        for (std::size_t index = 0u; index < system.render_slots.size() && emitted < requested; ++index) if (system.render_slots[index].state.remaining_lifetime < 0.0f) {
            particle_generate(system, index);
            if (position_emit) {
                system.render_slots[index].state.position.x -= movement.x * movement_factor;
                system.render_slots[index].state.position.y -= movement.y * movement_factor;
                system.render_slots[index].state.position.z -= movement.z * movement_factor;
                system.render_slots[index].state.spawn_position = system.render_slots[index].state.position;
                movement_factor += step;
            }
            ++emitted;
            ++system.active_particle_count;
        }
    }
    void update_particle_children(SferaParticleSystemInstance& system, float age) {
        if (system.render_slots.empty()) return;
        for (std::size_t index = 0u; index < system.render_slots.size(); ++index) {
            auto& slot = system.render_slots[index];
            if (slot.state.remaining_lifetime < 0.0f) continue;
            if ((system.definition->flags & (1u << 10u)) != 0u) slot.state.render_position = slot.state.position;
            else if ((system.definition->flags & (1u << 5u)) != 0u) slot.state.render_position = {slot.state.position.x + system.current_position.x, slot.state.position.y + system.current_position.y, slot.state.position.z + system.current_position.z};
            else slot.state.render_position = (system.transform).transformPoint<float>(slot.state.position);
            if (slot.linked_particle_system == nullptr) continue;
            if ((slot.linked_particle_system->definition->flags & (1u << 23u)) != 0u) slot.linked_particle_system->power = slot.state.color.alpha() * 0.00392156862745098f * system.power;
            slot.linked_particle_system->update(&slot.state.render_position, nullptr, age);
        }
    }
}

bool SferaEffectMeshDefinition::loadDefinition(const std::string&, SferaSimpleParser& parser, const SferaParserRange& range) {
    SferaParserRange previous{};
    parser.getBlockRange(&previous);
    std::string text;
    if (parser.findValue("effectmesh_name", &range)) {
        parser.readQuotedString(0u, text);
        name = text;
    }
    if (parser.findValue("effectmesh_ssm", &range)) {
        parser.readQuotedString(0u, text);
        mesh_resource = find_mesh_resource(text);
    }
    if (parser.findValue("effectmesh_flags", &range)) for (std::size_t index = 0u; index < parser.tokenCount(); index += 2u) flags |= effect_flag(parser.tokenAt(index));
    if (parser.findValue("self_illumination", &range)) self_illumination = effect_integer(parser, 0u);
    if (parser.findValue("color", &range)) for (std::size_t channel = 0u; channel < 4u; ++channel) color.channels[channel] = effect_integer(parser, channel);
    SferaParserRange track_range{};
    if (parser.findBlock("rotation_track", &track_range, &range, 1)) rotation_track = load_mesh_vector_track(parser, track_range, true);
    if (parser.findBlock("scale_track", &track_range, &range, 1)) scale_track = load_mesh_vector_track(parser, track_range, false);
    if (parser.findBlock("position_track", &track_range, &range, 1)) position_track = load_mesh_vector_track(parser, track_range, false);
    if (parser.findBlock("color_track", &track_range, &range, 1)) color_track = load_mesh_color_track(parser, track_range);
    if (parser.findBlock("ucoord_track", &track_range, &range, 1)) ucoord_track = sfera_load_scalar_effect_track(&parser, &track_range);
    if (parser.findBlock("vcoord_track", &track_range, &range, 1)) vcoord_track = sfera_load_scalar_effect_track(&parser, &track_range);
    SferaParserRange texture_range{};
    if (parser.findBlock("texture_def", &texture_range, &range, 1)) {
        custom_uv = true;
        if (parser.findValue("blendmode", &texture_range) && SferaText::asciiEqual(parser.tokenAt(0u), "PS_BLENDADD")) additive = true;
        if (parser.findValue("texture", &texture_range)) {
            parser.readQuotedString(0u, text);
            texture_name = text;
        }
    }
    // Preserve the three CRT draws formerly used by the discarded prototype seed.
    for (int draw = 0; draw < 3; ++draw) (void)std::rand();
    parser.setBlockRange(&previous);
    return true;
}
std::size_t SferaEffectMeshDefinition::renderSlotCount() const {
    return mesh_resource == nullptr ? 0u : mesh_resource->faces.size();
}
SferaEffectMeshInstance::SferaEffectMeshInstance(std::shared_ptr<const SferaEffectMeshDefinition> source)
    : definition(std::move(source)) {
    if (definition == nullptr) throw std::invalid_argument("Missing mesh definition");
    reset();
}
void SferaEffectMeshInstance::reset() {
    u_offset = v_offset = 0.0f;
    color = definition->color;
    runtime_position = {};
    transform = SferaMatrix4x4F::identity();
    random_row = std::rand() % 255;
    random_offset = std::rand();
    random_state = std::rand();
    texture_id = definition->texture_name.empty() ? -1 : g_sfera_textures.find(definition->texture_name);
}

void SferaEffectMeshInstance::update(const SferaVec3F* spatial_frame, const SferaMatrix4x4F* world_frame, float age) {
    if (definition->mesh_resource == nullptr || spatial_frame == nullptr) return;
    runtime_position = *spatial_frame;
    if ((definition->flags & (1u << 5u)) != 0u) {
        if (definition->position_track != nullptr) {
            SferaVec3F offset{};
            definition->position_track->evaluateVector(age, offset);
            runtime_position.x += offset.x;
            runtime_position.y += offset.y;
            runtime_position.z += offset.z;
        }
        if ((definition->flags & (1u << 27u)) != 0u && world_frame != nullptr) transform = *world_frame;
    } else {
        transform = SferaMatrix4x4F::identity();
        bool rotated = false;
        if (definition->rotation_track != nullptr) {
            SferaVec3F rotation{};
            definition->rotation_track->evaluateVector(age, rotation);
            apply_particle_rotation(transform, definition->flags, rotation);
            rotated = (definition->flags & 15u) != 0u;
        }
        if (definition->scale_track != nullptr) {
            SferaVec3F scale{};
            definition->scale_track->evaluateVector(age, scale);
            if (rotated) {
                transform.scaleAxes(scale);
            } else {
                transform.m[0][0] = scale.x;
                transform.m[1][1] = scale.y;
                transform.m[2][2] = scale.z;
            }
        }
        transform.m[0][3] = runtime_position.x;
        transform.m[1][3] = runtime_position.y;
        transform.m[2][3] = runtime_position.z;
        if (definition->position_track != nullptr) {
            SferaVec3F offset{};
            definition->position_track->evaluateVector(age, offset);
            transform.m[0][3] += offset.x;
            transform.m[1][3] += offset.y;
            transform.m[2][3] += offset.z;
        }
        if ((definition->flags & (1u << 27u)) != 0u && world_frame != nullptr) {
            SferaMatrix4x4F combined{};
            combined = (transform).multiplied<float>(*world_frame);
            transform = combined;
        }
    }
    const auto* random_values = g_sfera_effect_manager.particle_random_table.data() + random_row * 256u;
    if ((definition->flags & (1u << 14u)) != 0u) {
        if (definition->ucoord_track != nullptr) definition->ucoord_track->evaluateScalar(age, u_offset, {random_values, 256}, random_offset);
        if (definition->vcoord_track != nullptr) definition->vcoord_track->evaluateScalar(age, v_offset, {random_values, 256}, random_offset);
    }
    if ((definition->flags & (1u << 15u)) != 0u && definition->color_track != nullptr) evaluate_mesh_color(*definition->color_track, age, color, random_values, random_offset, random_state);
}
void SferaEffectMeshInstance::commit() {
    if (definition->mesh_resource == nullptr || definition->texture_name.empty()) return;
    if (g_sfera_effect_manager.render_slot_count > g_sfera_effect_manager.render_slots.size() || definition->mesh_resource->faces.size() > g_sfera_effect_manager.render_slots.size() - g_sfera_effect_manager.render_slot_count || g_sfera_effect_manager.render_slots.empty()) return;
    transformed_vertices.resize(definition->mesh_resource->vertices.size());
    transformed_colors.resize(definition->mesh_resource->colors.size());
    translated_uv.resize(definition->mesh_resource->uv.size());
    for (std::size_t index = 0u; index < definition->mesh_resource->vertices.size(); ++index) transformed_vertices[index] = (definition->flags & (1u << 5u)) != 0u ? SferaVec3F{definition->mesh_resource->vertices[index].x + runtime_position.x, definition->mesh_resource->vertices[index].y + runtime_position.y, definition->mesh_resource->vertices[index].z + runtime_position.z} : (transform).transformPoint<float>(definition->mesh_resource->vertices[index]);
    const auto* uv_source = definition->mesh_resource->uv.data();
    if ((definition->flags & (1u << 14u)) != 0u && !translated_uv.empty()) {
        for (std::size_t index = 0u; index < definition->mesh_resource->uv.size(); ++index) {
            translated_uv[index][0] = definition->mesh_resource->uv[index][0] + u_offset;
            translated_uv[index][1] = definition->mesh_resource->uv[index][1] + v_offset;
        }
        uv_source = translated_uv.data();
    }
    const SferaColor* color_source = definition->mesh_resource->colors.data();
    if ((definition->flags & (1u << 15u)) != 0u && !transformed_colors.empty()) {
        for (std::size_t index = 0u; index < definition->mesh_resource->vertices.size(); ++index) {
            for (std::size_t channel = 0u; channel < 4u; ++channel) transformed_colors[index].channels[channel] = (definition->mesh_resource->colors[index].channels[channel] * color.channels[channel]) >> 8u;
        }
        color_source = transformed_colors.data();
    }
    auto* slots = g_sfera_effect_manager.render_slots.data();
    for (std::size_t face = 0u; face < definition->mesh_resource->faces.size(); ++face) {
        auto& slot = slots[g_sfera_effect_manager.render_slot_count++];
        slot.resource_id = texture_id;
        slot.self_illumination = definition->self_illumination;
        slot.additive = definition->additive;
        slot.custom_uv = definition->custom_uv;
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex) {
            const auto vertex_index = definition->mesh_resource->faces[face].vertices[vertex];
            const auto uv_index = definition->mesh_resource->faces[face].uv[vertex];
            slot.position[vertex] = transformed_vertices[vertex_index];
            slot.uv[vertex][0] = uv_source[uv_index][0];
            slot.uv[vertex][1] = uv_source[uv_index][1];
            for (std::size_t channel = 0u; channel < 4u; ++channel) slot.color[channel][vertex] = color_source[vertex_index].channels[channel];
        }
    }
}

bool SferaParticleSystemDefinition::loadDefinition(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    SferaParserRange caller_range{};
    parser.getBlockRange(&caller_range);
    SferaParserRange nested{};
    std::string text;
    if (parser.findValue("psystem_name", &range) && parser.readQuotedString(0u, text)) name = text;
    if (parser.findValue("particles_num", &range)) {
        const int count = parser.readInt(0u);
        if (count > 0) particles.resize(count);
    }
    if (parser.findValue("psystem_flags", &range)) for (std::size_t index = 0u; index < parser.tokenCount(); index += 2u) flags |= effect_flag(parser.tokenAt(index));
    if (parser.findValue("transform_vec0", &range)) effect_vector(parser, 0u, render_basis[0]);
    if (parser.findValue("transform_vec1", &range)) effect_vector(parser, 0u, render_basis[1]);
    if (parser.findValue("transform_vec2", &range)) effect_vector(parser, 0u, render_basis[2]);
    if (parser.findValue("transform_vec3", &range)) effect_vector(parser, 0u, render_basis[3]);
    if (parser.findValue("distortion_vec", &range)) effect_vector(parser, 0u, distortion);
    if (parser.findValue("self_illumination", &range)) self_illumination = effect_integer(parser, 0u);
    if (parser.findValue("power", &range)) power = effect_real(parser, 0u);
    SferaParserRange block{};
    if (parser.findBlock("power_track", &block, &range, 1)) power_track = sfera_load_scalar_effect_track(&parser, &block);
    if (parser.findBlock("position_track", &block, &range, 1)) position_track = sfera_load_vector_effect_track(&parser, &block);
    if (parser.findBlock("scale_track", &block, &range, 1)) scale_track = sfera_load_vector_effect_track(&parser, &block);
    if (parser.findBlock("rotation_track", &block, &range, 1)) rotation_track = load_mesh_vector_track(parser, block, true);
    if (parser.findBlock("childs_def", &block, &range, 1)) {
        if (parser.findValue("childs_num", &block)) {
            const int count = parser.readInt(0u);
            if (count > 0) {
                links.resize(count);
                for (auto& link : links) link.target_index = -1;
            }
        }
        parser.setScanRange(&block);
        while (!links.empty() && parser.nextValue("child")) {
            const int index = parser.readInt(0u);
            if (index < 0 || index >= links.size()) continue;
            if (parser.readQuotedString(1u, text)) links[index].target_name = text;
        }
        parser.clearScanRange();
    }
    if (parser.findBlock("magnite_def", &block, &range, 1)) {
        if (parser.findBlock("magposition_track", &nested, &block, 1)) magnet_position_track = sfera_load_vector_effect_track(&parser, &nested);
        if (parser.findBlock("magfactor_track", &nested, &block, 1)) magnet_factor_track = sfera_load_vector_effect_track(&parser, &nested);
        if (parser.findValue("magchildps", &block)) {
            magnet_child_index = effect_integer(parser, 0u);
            if (magnet_child_index >= 0 && magnet_child_index < links.size()) ++links[magnet_child_index].instance_count;
            else magnet_child_index = -1;
        }
        if (parser.findValue("magfactor", &block)) {
            float source[3]{};
            effect_sequence<float>(parser, 0u, source);
            magnet_factor = {source[0] == 0.0f ? 0.0f : 1.0f / source[0], source[1] == 0.0f ? 0.0f : 1.0f / source[1], source[2] == 0.0f ? 0.0f : 1.0f / source[2]};
        }
        if (parser.findValue("magpos", &block)) effect_vector(parser, 0u, magnet_position);
    }
    if (parser.findBlock("emission_def", &block, &range, 1)) {
        if (parser.findValue("shape", &block) && parser.readString(0u, text)) shape = particle_shape(text);
        if (parser.findValue("randseed", &block)) random_seed = effect_integer(parser, 0u);
        if (parser.findValue("randfactor", &block)) random_factor = effect_integer(parser, 0u);
        if (parser.findValue("height", &block)) height = effect_real(parser, 0u);
        if (parser.findValue("width", &block)) width = effect_real(parser, 0u);
        if (parser.findValue("radius", &block)) radius = effect_real(parser, 0u);
        if (parser.findValue("emit_num", &block)) emission_count = effect_real(parser, 0u);
        if (parser.findValue("direction", &block)) effect_vector(parser, 0u, direction);
        if (parser.findValue("emitter_pos", &block)) effect_vector(parser, 0u, emitter_position);
        if (parser.findValue("shape_numpoints", &block)) {
            const int count = parser.readInt(0u);
            if (count > 0) shape_points.resize(count);
        }
        parser.setScanRange(&block);
        while (!shape_points.empty() && parser.nextValue("point")) {
            const int index = parser.readInt(0u);
            if (index < 0 || index >= shape_points.size()) continue;
            effect_vector(parser, 1u, shape_points[index]);
        }
        parser.clearScanRange();
        if (parser.findBlock("emission_track", &nested, &block, 1)) emission_track = sfera_load_scalar_effect_track(&parser, &nested);
        if (parser.findBlock("emissionpos_track", &nested, &block, 1)) emission_position_track = sfera_load_vector_effect_track(&parser, &nested);
    }
    if (parser.findBlock("particleborn_def", &block, &range, 1)) {
        if (parser.findValue("lifetime", &block)) lifetime = effect_real(parser, 0u);
        if (parser.findValue("lifetime_rf", &block)) lifetime_random_factor = effect_real(parser, 0u);
        if (parser.findBlock("lifetime_track", &nested, &block, 1)) lifetime_track = sfera_load_scalar_effect_track(&parser, &nested);
    }
    if (parser.findBlock("particletracks_def", &block, &range, 1)) {
        const auto setup_tracks = [&](std::string_view count_name, auto& tracks) {
            if (!parser.findValue(count_name, &block)) return;
            const int count = parser.readInt(0u);
            if (count > 0) tracks.resize(count);
        };
        setup_tracks("nsize_tracks", size_tracks);
        setup_tracks("ncolor_tracks", color_tracks);
        setup_tracks("nvelocity_tracks", velocity_tracks);
        setup_tracks("ngravitation_tracks", gravity_tracks);
        if (!size_tracks.empty()) load_track_array(parser, block, "size_track", size_tracks, false);
        if (!color_tracks.empty()) load_track_array(parser, block, "color_track", color_tracks, true);
        if (!velocity_tracks.empty()) load_track_array(parser, block, "velocity_track", velocity_tracks, false);
        if (!gravity_tracks.empty()) load_track_array(parser, block, "gravitation_track", gravity_tracks, false);
    }
    if (parser.findBlock("texture_def", &block, &range, 1)) {
        if (parser.findValue("numframes", &block)) {
            const int count = parser.readInt(0u);
            if (count > 0) texture_frames.resize(count);
        }
        if (parser.findValue("type", &block) && SferaText::asciiEqual(parser.tokenAt(0u), "PS_TANIMCOORD")) flags |= (1u << 9u);
        if (parser.findValue("blendmode", &block) && SferaText::asciiEqual(parser.tokenAt(0u), "PS_BLENDADD")) additive = true;
        if (parser.findValue("animspeed", &block)) texture_animation_speed = effect_real(parser, 0u);
        if (!texture_frames.empty() && parser.findValue("texture", &block) && parser.readQuotedString(0u, text)) texture_frames[0].texture_name = text;
        parser.setScanRange(&block);
        while (!texture_frames.empty() && parser.nextValue("frame")) {
            const int index = parser.readInt(0u);
            if (index < 0 || index >= texture_frames.size()) continue;
            auto& frame = texture_frames[index];
            if ((flags & (1u << 9u)) != 0u) {
                effect_sequence<float>(parser, 1u, frame.uv);
                custom_uv = true;
            } else if (parser.readQuotedString(1u, text)) {
                frame.texture_name = text;
            }
        }
        parser.clearScanRange();
    }
    if (!particles.empty() && parser.countBlocks("particles_def", &range) > 0) {
        std::vector<std::uint8_t> selected(particles.size(), 1u);
        SferaParserRange particle_range{};
        parser.setBlockRange(&range);
        while (parser.nextBlock("particles_def", &particle_range)) {
            std::fill(selected.begin(), selected.end(), 1u);
            if (parser.findValue("select", &particle_range)) {
                const auto mode = parser.tokenAt(0u);
                if (SferaText::asciiEqual(mode, "range")) {
                    std::fill(selected.begin(), selected.end(), 0u);
                    int begin = effect_integer(parser, 1u), end = effect_integer(parser, 2u);
                    if (begin > end) std::swap(begin, end);
                    begin = std::max(begin, 0);
                    end = std::min<std::ptrdiff_t>(end, std::ssize(particles));
                    if (begin < end) std::fill(selected.begin() + begin, selected.begin() + end, 1u);
                }
                else if (SferaText::asciiEqual(mode, "number")) {
                    std::fill(selected.begin(), selected.end(), 0u);
                    for (std::size_t token = 1u; token < parser.tokenCount(); ++token) {
                        int index = effect_integer(parser, token);
                        index = std::max(index, 0);
                        index = std::min<std::ptrdiff_t>(index, std::ssize(particles) - 1);
                        selected[index] = 1u;
                    }
                }
            }
            const auto assign_track = [&](std::string_view key, auto member, const auto& tracks) {
                if (!parser.findValue(key, &particle_range) || tracks.empty()) return;
                const int parsed = parser.readInt(0u);
                if (parsed < 0 || std::cmp_greater_equal(parsed, tracks.size())) return;
                const auto* value = tracks[parsed].get();
                for (std::size_t index = 0; index < particles.size(); ++index) if (selected[index] == 1u) particles[index].*member = value;
            };
            assign_track("size_track", &SferaParticleSettings::size_track, size_tracks);
            assign_track("color_track", &SferaParticleSettings::color_track, color_tracks);
            assign_track("velocity_track", &SferaParticleSettings::velocity_track, velocity_tracks);
            assign_track("gravitation_track", &SferaParticleSettings::gravity_track, gravity_tracks);
            if (parser.findValue("texture_frame", &particle_range) && SferaText::asciiEqual(parser.tokenAt(0u), "RANDOM")) flags |= (1u << 19u);
            if (parser.findValue("child_ps", &particle_range)) {
                const int link = effect_integer(parser, 0u);
                // Match the legacy loader: store the raw link index.  -1 means no
                // child; any other unresolved/out-of-range value simply never binds.
                for (std::size_t index = 0u; index < this->particles.size(); ++index)
                    if (selected[index] == 1u) this->particles[index].link_index = link;
            }
        }
        parser.clearBlockRange();
    }
    for (std::size_t index = 0u; index < particles.size(); ++index) if (particles[index].link_index >= 0 && particles[index].link_index < links.size()) ++links[particles[index].link_index].instance_count;
    parser.setBlockRange(&caller_range);
    return true;
}
SferaParticleSystemInstance::SferaParticleSystemInstance(std::shared_ptr<const SferaParticleSystemDefinition> source)
    : definition(std::move(source)) {
    if (definition == nullptr) throw std::invalid_argument("Missing particle definition");
    restoreSettings();
    render_slots.reserve(definition->particles.size());
    for (const auto& particle : definition->particles) render_slots.push_back({particle.initial, &particle, nullptr});
}
void SferaParticleSystemInstance::restoreSettings() {
    radius = definition->radius;
    height = definition->height;
    width = definition->width;
    emitter_position = definition->emitter_position;
    emission_count = definition->emission_count;
    lifetime = definition->lifetime;
    power = definition->power;
    magnet_factor = definition->magnet_factor;
    magnet_position = definition->magnet_position;
}
void SferaParticleSystemInstance::initializeClone() {
    runtime_random_row = std::rand() % 255;
    runtime_random_seed_0 = std::rand();
    runtime_random_seed_1 = std::rand();
    texture_ids.clear();
    texture_ids.reserve(definition->texture_frames.size());
    for (const auto& frame : definition->texture_frames) texture_ids.push_back(frame.texture_name.empty() ? -1 : g_sfera_textures.find(frame.texture_name));
}
void SferaParticleSystemInstance::reset() {
    restoreSettings();
    active_particle_count = 0;
    emission_fraction = 0.0f;
    current_position = previous_position = previous_origin = {};
    transform = {};
    first_update = emitting = runtime_active = true;
    runtime_stop_requested = false;
    initializeClone();
    for (auto& slot : render_slots) {
        slot.state = slot.settings->initial;
        if ((definition->flags & (1u << 6u)) == 0u) slot.state.remaining_lifetime = -1.0f;
    }
}

void SferaParticleSystemInstance::update(const SferaVec3F* spatial_frame, const SferaMatrix4x4F* world_frame, float age) {
    if (!runtime_active) return;
    const SferaVec3F incoming = spatial_frame == nullptr ? current_position : *spatial_frame;
    if (first_update) {
        previous_position = incoming;
        previous_origin = current_position;
        first_update = false;
    } else previous_position = current_position;
    current_position = incoming;
    const auto* table = g_sfera_effect_manager.particle_random_table.data();
    const std::uint16_t* random_values = table == nullptr ? nullptr : table + ((runtime_random_row & 255u) << 8u);
    if ((definition->flags & (1u << 5u)) != 0u) {
        if (definition->position_track != nullptr) {
            SferaVec3F offset{};
            definition->position_track->evaluateVector(age, offset);
            current_position.x += offset.x;
            current_position.y += offset.y;
            current_position.z += offset.z;
        }
        if ((definition->flags & (1u << 27u)) != 0u && world_frame != nullptr) transform = *world_frame;
    }
    else {
        transform = SferaMatrix4x4F::identity();
        bool rotated = false;
        if (definition->rotation_track != nullptr) {
            SferaVec3F rotation{};
            definition->rotation_track->evaluateVector(age, rotation);
            apply_particle_rotation(transform, definition->flags, rotation);
            rotated = (definition->flags & 15u) != 0u;
        }
        if (definition->scale_track != nullptr) {
            SferaVec3F scale{};
            definition->scale_track->evaluateVector(age, scale);
            if (rotated || (definition->flags & (1u << 4u)) != 0u) (transform).scaleAxes(scale);
            else {
                transform.m[0][0] = scale.x;
                transform.m[1][1] = scale.y;
                transform.m[2][2] = scale.z;
            }
        }
        transform.m[0][3] = current_position.x;
        transform.m[1][3] = current_position.y;
        transform.m[2][3] = current_position.z;
        if (definition->position_track != nullptr) {
            SferaVec3F offset{};
            definition->position_track->evaluateVector(age, offset);
            transform.m[0][3] += offset.x;
            transform.m[1][3] += offset.y;
            transform.m[2][3] += offset.z;
        }
        if ((definition->flags & (1u << 27u)) != 0u && world_frame != nullptr) {
            SferaMatrix4x4F combined{};
            combined = (transform).multiplied<float>(*world_frame);
            transform = combined;
        }
    }
    evaluate_particle_scalar(definition->emission_track.get(), age, emission_count, random_values, runtime_random_seed_0);
    if (definition->emission_position_track != nullptr) {
        SferaVec3F value{};
        evaluate_random_vector(definition->emission_position_track.get(), age, value, random_values, runtime_random_seed_0, runtime_random_seed_1);
        if ((definition->flags & (1u << 22u)) != 0u) {
            radius = value.x;
            height = value.y;
            width = value.z;
        } else emitter_position = value;
    }
    evaluate_particle_scalar(definition->lifetime_track.get(), age, lifetime, random_values, runtime_random_seed_0);
    evaluate_particle_scalar(definition->power_track.get(), age, power, random_values, runtime_random_seed_0);
    if ((definition->flags & (1u << 8u)) != 0u) {
        if (definition->magnet_position_track != nullptr) evaluate_random_vector(definition->magnet_position_track.get(), age, magnet_position, random_values, runtime_random_seed_0, runtime_random_seed_1);
        if ((definition->flags & (1u << 21u)) != 0u && definition->magnet_factor_track != nullptr)
            evaluate_magnet_factor(definition->magnet_factor_track.get(), age, magnet_factor, random_values, runtime_random_seed_0, runtime_random_seed_1);
    }
    SferaVec3F effective_magnet_position = magnet_position;
    if ((definition->flags & (1u << 10u)) != 0u) {
        if ((definition->flags & (1u << 5u)) != 0u) {
            effective_magnet_position.x += current_position.x;
            effective_magnet_position.y += current_position.y;
            effective_magnet_position.z += current_position.z;
        } else {
            effective_magnet_position = (transform).transformPoint<float>(magnet_position);
        }
    }
    const SferaVec3F direct = (definition->flags & (1u << 25u)) != 0u ? SferaVec3F{current_position.x - previous_origin.x, current_position.y - previous_origin.y, current_position.z - previous_origin.z}.unit<float, float, true>(0.000001f, SferaVec3F{current_position.x - previous_origin.x, current_position.y - previous_origin.y, current_position.z - previous_origin.z}) : SferaVec3F{1.0f, 1.0f, 1.0f};
    active_particle_count = 0u;
    for (std::size_t index = 0u; !render_slots.empty() && index < render_slots.size(); ++index) {
        auto& slot = render_slots[index];
        if (slot.state.remaining_lifetime < 0.0f) continue;
        if ((definition->flags & (1u << 13u)) == 0u) slot.state.remaining_lifetime -= 2.0f;
        if (slot.state.remaining_lifetime <= 0.0f) {
            slot.state.remaining_lifetime = -1.0f;
            continue;
        }
        const float local_time = (definition->flags & (1u << 12u)) != 0u ? age : slot.state.total_lifetime == 0.0f ? 1.0f : 1.0f - slot.state.remaining_lifetime / slot.state.total_lifetime;
        const std::uint16_t* slot_random = table == nullptr ? nullptr : table + ((slot.state.random_row & 255u) << 8u);
        if (slot.settings->size_track != nullptr) evaluate_particle_scalar(slot.settings->size_track, local_time, slot.state.size, slot_random, slot.state.random_seed_0);
        if (slot.settings->color_track != nullptr) evaluate_mesh_color(*slot.settings->color_track, local_time, slot.state.color, slot_random, slot.state.random_seed_0, slot.state.random_seed_1);
        SferaVec3F motion{};
        if (slot.settings->velocity_track != nullptr) evaluate_random_vector(slot.settings->velocity_track, local_time, motion, slot_random, slot.state.random_seed_0, slot.state.random_seed_1);
        if (slot.settings->gravity_track != nullptr) {
            SferaVec3F gravity{};
            evaluate_random_vector(slot.settings->gravity_track, local_time, gravity, slot_random, slot.state.random_seed_0, slot.state.random_seed_1);
            motion.x += gravity.x;
            motion.y += gravity.y;
            motion.z += gravity.z;
        }
        if ((definition->flags & (1u << 8u)) != 0u) {
            SferaVec3F factor = magnet_factor;
            if ((definition->flags & (1u << 21u)) == 0u && definition->magnet_factor_track != nullptr)
                evaluate_magnet_factor(definition->magnet_factor_track.get(), local_time, factor, slot_random, slot.state.random_seed_0, slot.state.random_seed_1);
            SferaVec3F delta{effective_magnet_position.x - slot.state.position.x, effective_magnet_position.y - slot.state.position.y, effective_magnet_position.z - slot.state.position.z};
            if ((definition->flags & (1u << 17u)) != 0u) {
                const SferaVec3F target{
                    slot.state.spawn_position.x + (effective_magnet_position.x - slot.state.spawn_position.x) * local_time,
                    slot.state.spawn_position.y + (effective_magnet_position.y - slot.state.spawn_position.y) * local_time,
                    slot.state.spawn_position.z + (effective_magnet_position.z - slot.state.spawn_position.z) * local_time
                };
                delta = {target.x - slot.state.position.x, target.y - slot.state.position.y, target.z - slot.state.position.z};
            }
            motion.x += factor.x * delta.x;
            motion.y += factor.y * delta.y;
            motion.z += factor.z * delta.z;
        }
        if ((definition->flags & (1u << 16u)) != 0u) {
            slot.state.position.x += (std::rand() - std::rand()) * 3.0518509447574615e-05f * definition->distortion.x;
            slot.state.position.y += (std::rand() - std::rand()) * 3.0518509447574615e-05f * definition->distortion.y;
            slot.state.position.z += (std::rand() - std::rand()) * 3.0518509447574615e-05f * definition->distortion.z;
        }
        motion.x *= direct.x;
        motion.y *= direct.y;
        motion.z *= direct.z;
        slot.state.position.x += motion.x;
        slot.state.position.y += motion.y;
        slot.state.position.z += motion.z;
        slot.state.texture_frame += definition->texture_animation_speed;
        if (definition->texture_frames.size() != 0u && slot.state.texture_frame > (definition->texture_frames.size() - 1u)) slot.state.texture_frame = 0.0f;
        ++active_particle_count;
    }
    if ((definition->flags & (1u << 7u)) == 0u && emitting) particle_emit(*this, 2.0f);
    if (active_particle_count == 0u && !emitting && runtime_stop_requested) runtime_active = false;
    update_particle_children(*this, age);
}
void SferaParticleSystemInstance::commit() {
    if (!runtime_active || render_slots.empty() || definition->texture_frames.empty()) return;
    for (std::size_t index = 0u; index < render_slots.size(); ++index) if (render_slots[index].state.remaining_lifetime >= 0.0f && render_slots[index].linked_particle_system != nullptr) render_slots[index].linked_particle_system->commit();
    const auto capacity = g_sfera_effect_manager.render_slots.size();
    const auto used = g_sfera_effect_manager.render_slot_count;
    if (used > capacity || render_slots.size() > capacity - used) return;
    const std::uint32_t opacity = std::max(power, 0.0f) * 256.0f;
    if (opacity == 0u) return;
    for (std::size_t index = 0u; index < render_slots.size(); ++index) {
        const auto& particle = render_slots[index];
        if (particle.state.remaining_lifetime < 0.0f) continue;
        SferaEffectRenderSlot* slot = g_sfera_effect_manager.acquireRenderSlot();
        if (slot == nullptr) break;
        const std::size_t frame = particle.state.texture_frame >= definition->texture_frames.size() ? definition->texture_frames.size() - 1u : SferaNumeric::truncatedWord(std::max(particle.state.texture_frame, 0.0f));
        const auto& texture = definition->texture_frames[frame];
        slot->resource_id = (definition->flags & (1u << 9u)) != 0u ? texture_ids[0] : texture_ids[frame];
        slot->self_illumination = definition->self_illumination;
        slot->additive = definition->additive;
        slot->custom_uv = definition->custom_uv;
        const auto& uv = (definition->flags & (1u << 9u)) != 0u ? texture : definition->texture_frames[0];
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex) {
            slot->uv[vertex][0] = uv.uv[vertex * 2u];
            slot->uv[vertex][1] = uv.uv[vertex * 2u + 1u];
        }
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex) {
            slot->color[0][vertex] = particle.state.color.red();
            slot->color[1][vertex] = particle.state.color.green();
            slot->color[2][vertex] = particle.state.color.blue();
            slot->color[3][vertex] = particle.state.color.alpha() * opacity >> 8u;
        }
        if ((definition->flags & (1u << 11u)) != 0u) for (std::size_t vertex = 0u; vertex < 4u; ++vertex) slot->position[vertex] = {particle.state.render_position.x + definition->render_basis[vertex].x * particle.state.size, particle.state.render_position.y + definition->render_basis[vertex].y * particle.state.size, particle.state.render_position.z + definition->render_basis[vertex].z * particle.state.size};
        else {
            const SferaVec3F view{particle.state.render_position.x - g_sfera_effect_manager.viewer_position.x, particle.state.render_position.y - g_sfera_effect_manager.viewer_position.y, particle.state.render_position.z - g_sfera_effect_manager.viewer_position.z};
            SferaVec3F right{}, up{};
            build_y_up_billboard_axes(view, particle.state.size * definition->render_basis[0].y, particle.state.size * definition->render_basis[0].x, right, up);
            slot->position[0] = {particle.state.render_position.x - right.x - up.x, particle.state.render_position.y - right.y - up.y, particle.state.render_position.z - right.z - up.z};
            slot->position[1] = {particle.state.render_position.x - right.x + up.x, particle.state.render_position.y - right.y + up.y, particle.state.render_position.z - right.z + up.z};
            slot->position[2] = {particle.state.render_position.x + right.x + up.x, particle.state.render_position.y + right.y + up.y, particle.state.render_position.z + right.z + up.z};
            slot->position[3] = {particle.state.render_position.x + right.x - up.x, particle.state.render_position.y + right.y - up.y, particle.state.render_position.z + right.z - up.z};
        }
    }
}
SferaFileManager::~SferaFileManager() { for (const auto& file : open_files) ::_close(file.first); }
SferaFileManager::ScopedFile::~ScopedFile() noexcept {
    if (descriptor_ < 0) return;
    const auto found = owner_.open_files.find(descriptor_);
    if (found == owner_.open_files.end()) return;
    ::_close(descriptor_);
    owner_.open_files.erase(found);
}

int SferaFileManager::ScopedFile::close() {
    const auto descriptor = std::exchange(descriptor_, -1);
    return descriptor < 0 ? 0 : owner_.close(descriptor);
}

bool SferaFileManager::setErrorReporting(bool enabled) { return std::exchange(error_reporting_enabled, enabled); }
std::vector<std::string> SferaFileManager::candidatePaths(const std::string& filename, bool search_nested_paths) const {
    std::vector<std::string> candidates{filename};
    if (search_nested_paths || filename.find('\\') == std::string::npos)
        for (const std::string& directory : search_paths) candidates.push_back(directory + filename);
    return candidates;
}
void SferaFileManager::addSearchPath(std::string_view directory) {
    if (directory.empty()) return;
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
int SferaFileManager::open(const std::string& filename, int flags) {
    for (const std::string& candidate : candidatePaths(filename)) {
        if (candidate.empty()) continue;
        int descriptor = -1;
        if (::_sopen_s(&descriptor, candidate.c_str(), flags | _O_BINARY, _SH_DENYNO, 0) == 0) return registerDescriptor(descriptor, candidate);
    }
    if (error_reporting_enabled) reportError("Unable to open file: ", filename);
    return -1;
}
int SferaFileManager::create(const std::string& filename) {
    if (!filename.empty()) {
        ::_chmod(filename.c_str(), _S_IREAD | _S_IWRITE);
        int descriptor = -1;
        if (::_sopen_s(&descriptor, filename.c_str(), _O_RDWR | _O_CREAT | _O_TRUNC | _O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE) == 0) return registerDescriptor(descriptor, filename);
    }
    if (error_reporting_enabled) reportError("Unable to create file: ", filename);
    return -1;
}
const std::string* SferaFileManager::filenameFor(int descriptor, std::string_view invalid_handle_message) const {
    const auto found = open_files.find(descriptor);
    if (found != open_files.end()) return &found->second;
    CSphereError error;
    error.write(invalid_handle_message);
    return nullptr;
}
namespace {
    template<class Byte, class Transfer> std::ptrdiff_t transferFileBytes(int descriptor, std::span<Byte> buffer, Transfer transfer) {
        const auto size = buffer.size();
        if (!std::in_range<std::ptrdiff_t>(size)) { errno = EINVAL; return -1; }
        std::size_t completed = 0;
        while (completed < size) {
            const unsigned int chunk = std::min(size - completed, std::size_t{std::numeric_limits<int>::max()});
            const int transferred = transfer(descriptor, buffer.data() + completed, chunk);
            if (transferred < 0) return -1;
            completed += transferred;
            if (transferred != chunk) break;
        }
        return completed;
    }
}
std::ptrdiff_t SferaFileManager::read(int descriptor, std::span<std::byte> destination) {
    const std::string* filename = filenameFor(descriptor, "Attempt of reading from the file with the wrong handle.");
    if (filename == nullptr) return -1;
    const auto transferred = transferFileBytes(descriptor, destination, ::_read);
    if (std::cmp_equal(transferred, destination.size())) return transferred;
    if (error_reporting_enabled) reportError(transferred == -1 ? "Unable to read file: " : "Unexpected end of file: ", *filename);
    return -1;
}
std::ptrdiff_t SferaFileManager::write(int descriptor, std::span<const std::byte> source) {
    const std::string* filename = filenameFor(descriptor, "Attempt of writing to the file with the wrong handle.");
    if (filename == nullptr) return -1;
    const auto transferred = transferFileBytes(descriptor, source, ::_write);
    if (std::cmp_equal(transferred, source.size())) return transferred;
    if (error_reporting_enabled) reportError(transferred == -1 ? "Unable to write file: " : "Incomplete file write (possibly insufficient disk space): ", *filename);
    return -1;
}
std::int64_t SferaFileManager::seek(int descriptor, std::int64_t offset, int origin) {
    const std::string* filename = filenameFor(descriptor, "Attempt of seeking in the file with the wrong handle.");
    if (filename == nullptr) return -1;
    const auto position = ::_lseeki64(descriptor, offset, origin);
    if (position == -1 && error_reporting_enabled) reportError("Unable to seek in file: ", *filename);
    return position;
}
int SferaFileManager::close(int descriptor) {
    const std::string* filename = filenameFor(descriptor, "Attempt of closing the file with the wrong handle.");
    if (filename == nullptr) return -1;
    if (::_close(descriptor) == 0) { open_files.erase(descriptor); return 0; }
    if (error_reporting_enabled) reportError("Unable to close file: ", *filename);
    return -1;
}
std::int64_t SferaFileManager::fileSize(const std::string& filename) {
    ScopedFile file(*this, open(filename, _O_RDONLY));
    return file.get() < 0 ? -1 : ::_filelengthi64(file.get());
}
std::optional<std::vector<std::uint8_t>> SferaFileManager::readBounded(const std::string& filename, std::size_t capacity) {
    if (filename.empty()) return std::nullopt;
    std::unique_ptr<std::FILE, decltype(&std::fclose)> file(::_fsopen(filename.c_str(), "rb", _SH_DENYNO), &std::fclose);
    if (!file) return std::nullopt;
    const auto length = ::_filelengthi64(::_fileno(file.get()));
    if (length < 0 || std::cmp_greater_equal(length, capacity)) return std::nullopt;
    std::vector<std::uint8_t> bytes(length);
    if (!bytes.empty() && std::fread(bytes.data(), 1, bytes.size(), file.get()) != bytes.size()) return std::nullopt;
    return bytes;
}

void SferaFileManager::reportError(std::string_view description, const std::string& filename) const {
    std::string message(description);
    message += filename;
    CSphereError error;
    error.write(message);
}


QuickFile* QuickFile::initialize(const std::string& directory) {
    release();
    files.reserve(file_capacity);
    index.reserve(file_capacity);
    if (directory.empty()) return this;
    std::error_code error;
    std::filesystem::directory_iterator cursor(std::filesystem::path(directory), error);
    const std::filesystem::directory_iterator end;
    while (!error && cursor != end) {
        const auto path = cursor->path();
        if (SferaText::resourceKey(path.extension().string()) == ".mbc" && cursor->is_regular_file(error)) load(path.string(), 0);
        cursor.increment(error);
    }
    return this;
}

void QuickFile::release() {
    index.clear();
    std::vector<QuickFileEntry>().swap(files);
}

int QuickFile::load(const std::string& filename, std::size_t size) {
    if (filename.empty()) return 2;
    std::unique_ptr<std::FILE, decltype(&std::fclose)> stream(::_fsopen(filename.c_str(), "rb", _SH_DENYNO), &std::fclose);
    if (!stream) return 2;
    if (files.size() >= file_capacity) return -1;
    if (size == 0) {
        const auto length = ::_filelengthi64(::_fileno(stream.get()));
        if (!std::in_range<std::size_t>(length)) return 3;
        size = length;
    }
    QuickFileEntry loaded{std::vector<std::uint8_t>(size), files.size() + 1};
    if (size != 0 && std::fread(loaded.bytes.data(), 1, size, stream.get()) != size) return 3;
    const std::string_view path(filename);
    const auto separator = path.find_last_of("/\\");
    const auto basename = path.substr(separator == std::string_view::npos ? 0 : separator + 1);
    if (basename.size() > maximum_filename_length) throw std::length_error("QuickFile: module filename is too long");
    auto key = SferaText::resourceKey(basename);
    files.push_back(std::move(loaded));
    try { index.try_emplace(std::move(key), files.size() - 1); }
    catch (...) { files.pop_back(); throw; }
    return 0;
}

const QuickFileEntry* QuickFile::find(std::string_view filename) const {
    if (filename.size() > maximum_filename_length) return nullptr;
    const auto found = index.find(SferaText::resourceKey(filename));
    return found == index.end() ? nullptr : &files[found->second];
}

SferaFileMap::SferaFileMap(const std::string& path) {
    open(path);
}

SferaFileMap::~SferaFileMap() noexcept {
    close();
}

bool SferaFileMap::isOpen() const noexcept {
    return mapped_view != nullptr;
}

void SferaFileMap::reportError(std::string_view operation) const noexcept {
    try {
        const auto message = std::format("{} {}", operation, filename);
        std::fprintf(stderr, "%s\n", message.c_str());
        ::OutputDebugStringA(message.c_str());
    } catch (...) {
        ::OutputDebugStringA("File mapping cleanup failed");
    }
}

void SferaFileMap::close() noexcept {
    if (mapped_view && !::UnmapViewOfFile(mapped_view)) reportError("Error unmapping file");
    mapped_view = nullptr;
    file_size = 0u;
    filename.clear();
}

bool SferaFileMap::open(const std::string& path) {
    close();
    if (path.empty()) return false;
    const auto separator = path.find_last_of('\\');
    filename = path.substr(separator == std::string::npos ? 0u : separator + 1u);
    using NativeHandle = std::unique_ptr<std::remove_pointer_t<HANDLE>, decltype(&::CloseHandle)>;
    HANDLE opened = ::CreateFileA(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, nullptr);
    NativeHandle file(opened == INVALID_HANDLE_VALUE ? nullptr : opened, &::CloseHandle);
    if (!file) return false;
    LARGE_INTEGER length{};
    if (!::GetFileSizeEx(file.get(), &length) || length.QuadPart <= 0 || std::cmp_greater(length.QuadPart, std::numeric_limits<std::size_t>::max())) return false;
    NativeHandle mapping(::CreateFileMappingA(file.get(), nullptr, PAGE_READONLY, 0u, 0u, nullptr), &::CloseHandle);
    file.reset();
    if (!mapping) return false;
    const auto* view = static_cast<const std::uint8_t*>(::MapViewOfFile(mapping.get(), FILE_MAP_READ, 0u, 0u, 0u));
    if (view == nullptr) return false;
    mapped_view = view;
    file_size = length.QuadPart;
    return true;
}

namespace {
    template<class Operation> SferaVec3F transformComponents(const SferaVec3F& source, Operation operation) {
        SferaVec3F result;
        for (std::size_t axis = 0; axis < 3; ++axis) {
            const double component = source.component(axis);
            result.setComponent(axis, operation(component, axis));
        }
        return result;
    }
}

SferaVec3F SferaVec3F::operator+(const SferaVec3F& other) const {
    return transformComponents(*this, [&](double value, std::size_t axis) { return value + other.component(axis); });
}
SferaVec3F SferaVec3F::operator-(const SferaVec3F& other) const {
    return transformComponents(*this, [&](double value, std::size_t axis) { return value - other.component(axis); });
}
SferaVec3F SferaVec3F::operator*(float factor) const {
    return transformComponents(*this, [factor](double value, std::size_t) { return value * factor; });
}

SferaVec3F SferaVec3F::subtractScaled(const SferaVec3F& direction, float factor) const {
    return transformComponents(*this, [&](double origin, std::size_t axis) {
        const double delta = direction.component(axis);
        return origin - delta * factor;
    });
}

float SferaVec3F::component(std::size_t axis) const { return axis == 0 ? x : axis == 1 ? y : z; }
void SferaVec3F::setComponent(std::size_t axis, float value) { if (axis == 0) x = value; else if (axis == 1) y = value; else z = value; }

void SferaVec3F::rotatePair(float& first, float& second, float angle) {
    const double radians = angle, originalFirst = first, originalSecond = second;
    const float cosine = std::cos(radians), sine = std::sin(radians);
    const float rotatedFirst = originalFirst * cosine - originalSecond * sine;
    second = originalFirst * sine + originalSecond * cosine;
    first = rotatedFirst;
}

void SferaVec3F::normalize() {
    const float magnitude = length<double, double, true>();
    if (magnitude == 0.0f) return;
    const double divisor = magnitude;
    x /= divisor;
    y /= divisor;
    z /= divisor;
}

SferaAngle8::SferaAngle8(float radians) {
    if (!std::isfinite(radians)) throw std::invalid_argument("A finite angle is required");
    const double wrapped = std::fmod(std::trunc(radians * 40.74365997314453), 256.0);
    steps = wrapped < 0.0 ? wrapped + 256.0 : wrapped;
}

float SferaAngle8::distanceTo(SferaAngle8 other) const {
    const int distance = std::abs(steps - other.steps);
    return std::min(distance, 256 - distance) * 0.024543695894260174;
}

SferaMatrix4x4F SferaMatrix4x4F::fromRollPitchYaw(float roll, float pitch, float yaw) {
    const auto [sr, cr] = SferaMath::rotationTerms(roll);
    const auto [sp, cp] = SferaMath::rotationTerms(pitch);
    const auto [sy, cy] = SferaMath::rotationTerms(yaw);
    const float pitchRoll = sp * sr, yawRoll = cy * cr, sineYawRoll = sy * cr;
    SferaMatrix4x4F result = identity();
    result.m[0][0] = cp * cy;
    result.m[1][0] = cp * sy;
    result.m[2][0] = -sp;
    result.m[0][1] = cy * pitchRoll - sineYawRoll;
    result.m[1][1] = sy * pitchRoll + yawRoll;
    result.m[2][1] = cp * sr;
    result.m[0][2] = sy * sr + yawRoll * sp;
    result.m[1][2] = sineYawRoll * sp - sr * cy;
    result.m[2][2] = cr * cp;
    return result;
}

SferaBoundsCornersRuntime SferaBoundsCornersRuntime::empty() {
    constexpr float limit = std::numeric_limits<float>::max();
    return fromExtents({limit, limit, limit}, {-limit, -limit, -limit});
}

void WorldObjects::approachHeading(std::uint32_t handle, float target) {
    auto* instance = object(handle);
    if (instance == nullptr) WorldDiagnostics::fail("SetAngle: wrong handle");
    const auto* appearance = model(*instance);
    if (appearance == nullptr) WorldDiagnostics::fail("SetAngle: object has no model");
    constexpr float step = 0.15707965195178986f;
    constexpr double fullTurn = 6.283185958862305;
    float& heading = instance->rotation.x;
    if (appearance->radius < 5.0f || SferaAngle8(heading).distanceTo(SferaAngle8(target)) <= step) { heading = target; return; }
    const double current_heading = heading;
    const float clockwise = current_heading + step;
    const float counterclockwise = current_heading - step;
    if (SferaAngle8(clockwise).distanceTo(SferaAngle8(target)) < SferaAngle8(counterclockwise).distanceTo(SferaAngle8(target)))
        heading = clockwise > fullTurn ? clockwise - fullTurn : clockwise;
    else heading = counterclockwise < 0.0f ? counterclockwise + fullTurn : counterclockwise;
}

SferaMatrix3x3F SferaQuaternionF::rotationMatrix() const {
    const float xx = 2.0 * x * x, yy = 2.0 * y * y, zz = 2.0 * z * z;
    const std::array diagonal{xx, yy, zz};
    const float xy = 2.0 * x * y, xz = 2.0 * x * z, yz = 2.0 * y * z;
    const float wx = 2.0 * w * x, wy = 2.0 * w * y, wz = 2.0 * w * z;
    const std::array<double, 3> mixed{xy, xz, yz};
    SferaMatrix3x3F result{};
    result.m[0][0] = 1.0 - diagonal[1] - diagonal[2];
    result.m[0][1] = mixed[0] - wz;
    result.m[0][2] = wy + mixed[1];
    result.m[1][0] = mixed[0] + wz;
    result.m[1][1] = 1.0 - diagonal[0] - diagonal[2];
    result.m[1][2] = mixed[2] - wx;
    result.m[2][0] = mixed[1] - wy;
    result.m[2][1] = wx + mixed[2];
    result.m[2][2] = 1.0 - diagonal[0] - diagonal[1];
    return result;
}

SferaQuaternionF SferaQuaternionF::interpolated(const SferaQuaternionF& other, float factor) const {
    const std::array<double, 4> source{x, y, z, w};
    const float roundedCosine = source[0] * other.x + source[1] * other.y + source[2] * other.z + source[3] * other.w;
    const double cosine = roundedCosine;
    SferaQuaternionF target = other;
    float firstWeight;
    float secondWeight;
    if (!(1.0 + cosine > 0.00001)) {
        target = {z, -y, x, -w};
        firstWeight = std::sin((1.0 - factor) * 1.5707965);
        secondWeight = std::sin(factor * 1.5707965);
    } else if (1.0 - cosine > 0.00001f) {
        const float roundedAngle = std::acos(cosine);
        const double angle = roundedAngle;
        const float roundedSine = std::sin(angle);
        const double sine = roundedSine;
        firstWeight = std::sin((1.0 - factor) * angle) / sine;
        const float secondAngle = angle * factor;
        const double phase = secondAngle;
        const float roundedSecondSine = std::sin(phase);
        const double secondSine = roundedSecondSine;
        secondWeight = secondSine / sine;
    } else {
        firstWeight = 1.0 - factor;
        secondWeight = factor;
    }
    const double first = firstWeight, second = secondWeight;
    SferaQuaternionF result;
    result.w = source[3] * first + target.w * second;
    result.x = source[0] * first + target.x * second;
    result.y = source[1] * first + target.y * second;
    result.z = source[2] * first + target.z * second;
    return result;
}

SferaMatrix4x4F SferaMatrix4x4F::identity() {
    SferaMatrix4x4F result{};
    for (std::size_t axis = 0; axis < 4; ++axis) result.m[axis][axis] = 1.0f;
    return result;
}

SferaMatrix4x4F SferaMatrix4x4F::fromEuler(const SferaVec3F& translation, const SferaVec3F& angles) {
    const auto [sx, cx] = SferaMath::rotationTerms(angles.x);
    const auto [sy, cy] = SferaMath::rotationTerms(angles.y);
    const auto [sz, cz] = SferaMath::rotationTerms(angles.z);
    SferaMatrix4x4F result = identity();
    result.m[0][0] = cz * cx - sy * sx * sz;
    result.m[0][1] = -sz * cy;
    result.m[0][2] = -sx * cz - sy * cx * sz;
    result.m[1][0] = sz * cx + cz * sy * sx;
    result.m[1][1] = cz * cy;
    result.m[1][2] = cz * sy * cx - sz * sx;
    result.m[2][0] = cy * sx;
    result.m[2][1] = -sy;
    result.m[2][2] = cy * cx;
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

SferaVec3F SferaMatrix4x4F::inverseTransformPoint(const SferaVec3F& point) const {
    const SferaVec3F relative = point - SferaVec3F{m[0][3], m[1][3], m[2][3]};
    SferaVec3F result;
    for (std::size_t column = 0; column < 3; ++column) {
        const SferaVec3F basis{m[0][column], m[1][column], m[2][column]};
        result.setComponent(column, basis.dot(relative));
    }
    return result;
}

SferaMatrix4x4F SferaMatrix4x4F::transposed() const {
    SferaMatrix4x4F result;
    for (std::size_t row = 0; row < 4; ++row) for (std::size_t column = 0; column < 4; ++column) result.m[row][column] = m[column][row];
    return result;
}

void SferaMatrix4x4F::scaleAxes(const SferaVec3F& scale) {
    for (std::size_t row = 0; row < 3; ++row) {
        const double factor = scale.component(row);
        for (std::size_t column = 0; column < 3; ++column) m[row][column] *= factor;
    }
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
    const float denominator = normal.dot(direction);
    if (std::abs(denominator) <= std::numeric_limits<float>::min()) return 0;
    const float startProjection = normal.dot(start);
    const double projection = startProjection;
    const float startDistance = projection + distance;
    const double numerator = startDistance;
    const float parameter = numerator / denominator;
    intersection = start.subtractScaled(direction, parameter);
    return (startDistance < 0.0f ? -2 : 1) + (denominator > 0.0f ? 1 : 0);
}

bool SferaVec3F::containsConvexPolygonPoint(std::span<const SferaVec3F* const> vertices, const SferaVec3F& point) const {
    if (vertices.empty()) return true;
    std::size_t dominant = std::abs(y) > std::abs(x) ? 1 : 0;
    if (std::abs(z) > std::abs(component(dominant))) dominant = 2;
    const std::size_t first = (dominant + 1) % 3, second = (dominant + 2) % 3;
    const auto project = [&](const SferaVec3F& value) -> std::array<double, 2> {
        return {value.component(first), value.component(second)};
    };
    const auto target = project(point);
    auto previous = project(*vertices.back());
    for (const auto* vertex : vertices) {
        const auto current = project(*vertex);
        const double side = (previous[1] - current[1]) * (target[0] - previous[0]) + (current[0] - previous[0]) * (target[1] - previous[1]);
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
            const double limit = boundary, currentAxis = current.component(axis);
            const float fraction = (limit - previous.component(axis)) / (currentAxis - previous.component(axis));
            const float factor = std::clamp(fraction, 0.0f, 1.0f);
            SferaVec3F intersection = SferaMath::interpolate(previous, current, factor);
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
    const SferaVec3F scaled = offset * 1024.0f;
    const std::int64_t fixedX = std::nearbyint(scaled.x);
    const std::int64_t fixedY = std::nearbyint(scaled.y);
    const std::int64_t fixedZ = std::nearbyint(scaled.z);
    result.clipping_bounds = {clipping_bounds.min_x + fixedX, clipping_bounds.max_x + fixedX, clipping_bounds.min_y + fixedY, clipping_bounds.max_y + fixedY, clipping_bounds.min_z + fixedZ, clipping_bounds.max_z + fixedZ};
    return result;
}

std::vector<std::uint8_t> SferaFileManager::readAll(const std::string& filename) {
    ScopedFile file(*this, open(filename, _O_RDONLY));
    const auto& path = filename;
    if (file.get() < 0) throw std::runtime_error(std::string("Unable to open file: ") + path);
    const auto length = seek(file.get(), 0, SEEK_END);
    if (length < 0 || seek(file.get(), 0, SEEK_SET) != 0) throw std::runtime_error(std::string("Unable to measure file: ") + path);
    if (std::cmp_greater(length, std::numeric_limits<std::ptrdiff_t>::max())) throw std::length_error("File exceeds native buffer capacity");
    std::vector<std::uint8_t> bytes(length);
    if (length != 0 && read(file.get(), std::as_writable_bytes(std::span(bytes))) != length) throw std::runtime_error(std::string("Incomplete file read: ") + path);
    return bytes;
}

SphereRender::ConfigDocument::StorageMode SphereRender::ConfigDocument::storage_mode_ = StorageMode::Plain;

class SphereRender::ConfigDocument::Parser {
    auto peek() const { return position_ < source_.size() ? source_[position_] : '\0'; }
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
            require("<", 5);
            const bool array = peek() == 'a' || peek() == 'A';
            if (array) ++position_;
            const auto type = peek();
            if (type != '\0') ++position_;
            require(">", 8, false);
            require("=", 10);
            if (!skipSpace()) fail(11);
            switch (type) {
            case 'i': case 'I':
                value.type = array ? Type::IntegerArray : Type::Integer;
                if (array) {
                    std::vector<int> items;
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
                    require("{", array ? 35 : 33);
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
    void require(std::string_view token, int error, bool skip = true) {
        if (skip) skipSpace();
        if (!source_.substr(position_).starts_with(token)) fail(error);
        position_ += token.size();
    }
    bool separator() {
        skipSpace();
        if (peek() != ',') return false;
        ++position_;
        if (!skipSpace()) fail(17);
        return true;
    }
    std::string identifier() {
        const auto letter = [](auto c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_'; };
        if (!letter(peek())) fail(2);
        const auto begin = position_++;
        while (letter(peek()) || (peek() >= '0' && peek() <= '9')) ++position_;
        if (position_ - begin > 250) fail(3);
        return std::string(source_.substr(begin, position_ - begin));
    }
    int integer() {
        const auto begin = position_;
        if (peek() == '-') ++position_;
        const auto digits = position_;
        while (peek() >= '0' && peek() <= '9') ++position_;
        if (digits == position_) fail(13);
        int value = 0;
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
        require("\"", 23);
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
        const std::size_t length = integer();
        require(":", 30, false);
        if (!skipSpace() && length != 0) fail(31);
        const auto encoded_length = (length / 7) * 8 + ((length % 7) * 8 + 6) / 7;
        if (encoded_length > source_.size() - position_) fail(39);
        const auto encoded = source_.substr(position_, encoded_length);
        std::vector<std::uint8_t> bytes(length);
        for (std::size_t index = 0; index < length; ++index) {
            const auto first = index + index / 7;
            const unsigned shift = index % 7;
            if (encoded[first] == '\0' || encoded[first + 1] == '\0') fail(39);
            const auto low = SferaText::byteValue(encoded[first]) - '0';
            const auto high = SferaText::byteValue(encoded[first + 1]) - '0';
            bytes[index] = (low >> shift) | (high << (7 - shift));
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

SphereRender::ConfigDocument SphereRender::ConfigDocument::open(const std::string& path) {
    try {
        auto bytes = g_sfera_files.readAll(path);
        if (bytes.empty()) throw std::runtime_error(std::string("openCfg: wrong format of Cfg ") + path);
        constexpr auto leadingByte = [](std::uint8_t byte) { return byte == '\r' || byte == ' ' || byte == '/'; };
        constexpr auto transformByte = [](std::uint8_t byte) { return byte ^ storageKey; };
        const bool encoded = leadingByte(transformByte(bytes.front()));
        if (!encoded && !leadingByte(bytes.front())) throw std::runtime_error(std::string("openCfg: wrong format of Cfg ") + path);
        if (encoded) std::transform(bytes.begin(), bytes.end(), bytes.begin(), transformByte);
        const bool rewrite = (encoded && storage_mode_ == StorageMode::Plain) || (!encoded && storage_mode_ == StorageMode::Encoded);
        if (rewrite) {
            auto stored = bytes;
            if (storage_mode_ == StorageMode::Encoded) std::transform(stored.begin(), stored.end(), stored.begin(), transformByte);
            SferaFileManager::ScopedFile file(g_sfera_files, g_sfera_files.create(path));
            if (file.get() < 0) throw std::runtime_error(std::string("Unable to create Cfg ") + path);
            if (g_sfera_files.write(file.get(), std::as_bytes(std::span(stored))) != std::ssize(stored)) throw std::runtime_error(std::string("Incomplete Cfg write: ") + path);
            file.close();
        }
        return parse(SferaText::fromBytes(bytes));
    } catch (const std::exception& exception) {
        CSphereError error;
        error.write(exception.what());
        throw;
    }
}

void SphereRender::ConfigDocument::setStorageMode(StorageMode mode) { storage_mode_ = mode; }
const SphereRender::ConfigDocument::Value* SphereRender::ConfigDocument::find(std::string_view name) const {
    for (const auto& value : values_) if (SferaText::asciiEqual(value.name, name)) return &value;
    return nullptr;
}
std::optional<int> SphereRender::ConfigDocument::integer(std::string_view name) const {
    const auto* value = find(name);
    if (value == nullptr) return std::nullopt;
    if (value->type != Type::Integer) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<int>(value->data);
}
std::optional<float> SphereRender::ConfigDocument::real(std::string_view name) const {
    const auto* value = find(name);
    if (value == nullptr) return std::nullopt;
    if (value->type != Type::Float) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<float>(value->data);
}
std::optional<std::string_view> SphereRender::ConfigDocument::text(std::string_view name) const {
    const auto* value = find(name);
    if (value == nullptr) return std::nullopt;
    if (value->type != Type::Text) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::string>(value->data);
}
std::optional<std::size_t> SphereRender::ConfigDocument::arraySize(std::string_view name) const {
    const auto* value = find(name);
    if (value == nullptr) return std::nullopt;
    switch (value->type) {
    case Type::IntegerArray: return std::get<std::vector<int>>(value->data).size();
    case Type::FloatArray: return std::get<std::vector<float>>(value->data).size();
    case Type::TextArray: return std::get<std::vector<std::string>>(value->data).size();
    case Type::ObjectArray: return std::get<std::vector<ConfigDocument>>(value->data).size();
    default: throw std::runtime_error("getCfg: get size for non array. Name: " + value->name);
    }
}
std::optional<int> SphereRender::ConfigDocument::integerAt(std::string_view name, std::size_t index) const {
    const auto* value = find(name);
    if (value == nullptr) return std::nullopt;
    if (value->type != Type::IntegerArray) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::vector<int>>(value->data).at(index);
}
std::optional<float> SphereRender::ConfigDocument::realAt(std::string_view name, std::size_t index) const {
    const auto* value = find(name);
    if (value == nullptr) return std::nullopt;
    if (value->type != Type::FloatArray) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::vector<float>>(value->data).at(index);
}
std::optional<std::string_view> SphereRender::ConfigDocument::textAt(std::string_view name, std::size_t index) const {
    const auto* value = find(name);
    if (value == nullptr) return std::nullopt;
    if (value->type != Type::TextArray) throw std::runtime_error("getCfg: wrong type of parameter. Name: " + value->name);
    return std::get<std::vector<std::string>>(value->data).at(index);
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

void SphereRender::ModelParameters::load(const std::string& path) {
    if (initialized_) { CSphereError error; error.write("CObjParamManager::Open: object already initialized"); }
    try {
        const auto bytes = g_sfera_files.readAll(path);
        parse(SferaText::fromBytes(bytes));
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
    for (const auto& object : objects_) if (SferaText::asciiEqual(object.name, name)) return &object;
    return nullptr;
}
const SphereRender::ModelParameters::Parameter* SphereRender::ModelParameters::findParameter(std::string_view model, std::string_view parameter) const {
    const auto* object = findObject(model);
    if (object == nullptr) return nullptr;
    for (const auto& value : object->parameters) if (SferaText::asciiEqual(value.name, parameter)) return &value;
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
namespace {
    template<class Number> std::optional<Number> modelNumber(std::optional<std::string_view> source) {
        if (!source) return std::nullopt;
        auto text = *source;
        while (!text.empty() && SferaText::isSpace(text.front())) text.remove_prefix(1);
        if (text.starts_with('+')) text.remove_prefix(1);
        Number value{};
        if (text.empty() || std::from_chars(text.data(), text.data() + text.size(), value).ec != std::errc{})
            throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
        return value;
    }
}
std::optional<float> SphereRender::ModelParameters::floatValue(std::string_view model, std::string_view parameter) const {
    return modelNumber<float>(stringValue(model, parameter));
}
std::optional<int> SphereRender::ModelParameters::intValue(std::string_view model, std::string_view parameter) const {
    return modelNumber<int>(stringValue(model, parameter));
}

std::uint32_t SphereRender::Material::randomColor(const std::array<float, 3>& variation) {
    std::uint32_t color = 0;
    for (float amount : variation) {
        std::uint32_t channel = 255;
        if (amount > 1e-6) {
            const auto random = ::rand();
            const int range = std::floor(amount * 255.0 + 0.5);
            if (range > 0) channel -= random % range;
        }
        color = (color << 8) | channel;
    }
    return color;
}
void SphereRender::MaterialLibrary::clear() { materials_.reset(); default_index_.reset(); }
const SphereRender::Material* SphereRender::MaterialLibrary::find(std::string_view name) const {
    if (!materials_) return nullptr;
    for (const auto& material : *materials_) if (SferaText::asciiEqual(material.name, name)) return &material;
    return nullptr;
}
const SphereRender::Material* SphereRender::MaterialLibrary::at(std::size_t index) const { return materials_ && index < materials_->size() ? &(*materials_)[index] : nullptr; }
const SphereRender::Material* SphereRender::MaterialLibrary::defaultMaterial() const { return default_index_ ? at(*default_index_) : nullptr; }
std::size_t SphereRender::MaterialLibrary::size() const { return materials_ ? materials_->size() : 0u; }

void SphereRender::MaterialLibrary::load(const std::string& binary_path, const std::string& configuration_path) {
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
            return SferaBinary::readLittleEndian<std::uint32_t>(data.data());
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
        std::optional<std::size_t> default_index = count == 0 ? std::nullopt : std::optional<std::size_t>(0);
        for (std::size_t index = 0; index < count; ++index) {
            Material material;
            material.name = name();
            if (SferaText::asciiEqual(material.name, "default")) default_index = index;
            const auto texture_count = integer();
            if (texture_count > 16) throw std::runtime_error("MaterialLibrary: invalid texture count");
            material.textures.reserve(texture_count);
            for (std::uint32_t texture = 0; texture < 16; ++texture) {
                if (texture >= texture_count) { take(36); continue; }
                auto texture_name = name();
                if (texture_name.size() < 2) throw std::runtime_error("MaterialLibrary: invalid texture name");
                texture_name.resize(texture_name.size() - 2);
                material.textures.push_back(g_sfera_textures.find(texture_name));
            }
            for (auto& channel : material.color) channel = SferaBinary::floatFromBits(integer());
            take(22);
            for (std::size_t configured = 0; configured < count_configured; ++configured) {
                const auto* record = configuration.objectAt("materials", configured);
                if (record == nullptr) throw std::runtime_error("Can't go into material struct " + std::to_string(configured));
                const auto configured_name = record->text("name");
                if (!configured_name) throw std::runtime_error("Field name is absent in material " + std::to_string(configured));
                if (!SferaText::asciiEqual(*configured_name, material.name)) continue;
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
        materials_ = std::make_shared<const std::vector<Material>>(std::move(materials));
        default_index_ = default_index;
    } catch (const std::exception& exception) { CSphereError error; error.write(exception.what()); throw; }
}

std::unique_ptr<SphereRender::Model> SphereRender::Model::load(std::string_view model_name, std::string_view directory, const ModelParameters& parameters, const MaterialLibrary& materials) {
    try {
        const std::string path = std::format("{}{}.mdl", directory, model_name);
        const std::vector<std::uint8_t> bytes = g_sfera_files.readAll(path);
        return decode(model_name, bytes, parameters, materials);
    } catch (const std::exception& exception) {
        CSphereError error;
        error.write(exception.what());
        throw;
    }
}

std::unique_ptr<SphereRender::Model> SphereRender::Model::decode(std::string_view model_name, std::span<const std::uint8_t> bytes, const ModelParameters& parameters, const MaterialLibrary& materials) {
    const auto fail = [&](std::string_view reason) -> void { throw std::runtime_error("Cannot load model '" + std::string(model_name) + "': " + std::string(reason)); };
    if (model_name.size() >= 32u) fail("model name is too long");
    if (bytes.size() < 258u) fail("truncated MDL header");
    const auto byte = [&](std::size_t offset) -> std::uint8_t { if (offset >= bytes.size()) fail("truncated MDL field"); return bytes[offset]; };
    const auto word = [&](std::size_t offset) -> std::uint16_t { return byte(offset) | (byte(offset + 1u) << 8u); };
    const auto integer = [&](std::size_t offset) -> std::uint32_t { return SferaBinary::readLittleEndian<std::uint32_t>(bytes.data() + offset); };
    const auto real = [&](std::size_t offset) -> float { const float value = SferaBinary::floatFromBits(integer(offset)); if (!std::isfinite(value)) fail("non-finite MDL coordinate"); return value; };
    const auto point = [&](std::size_t offset) -> SferaVec3F { return {real(offset), real(offset + 4u), real(offset + 8u)}; };
    const std::size_t source_vertex_count = word(4u);
    const std::size_t source_face_count = word(6u);
    const std::size_t source_submesh_count = word(8u);
    const std::size_t source_material_count = byte(10u);
    const std::size_t material_name_bytes = word(11u);
    const std::size_t source_bone_count = byte(13u);
    const std::size_t child_bone_count = byte(14u);
    const std::size_t keyframe_count = word(16u);
    const std::size_t animation_frame_count = word(18u);
    const std::size_t source_animation_count = byte(20u);
    const std::uint8_t source_has_colors = byte(23u);
    const std::size_t vertex_color_count = word(24u);
    const std::uint32_t source_collision_kind = integer(26u);
    if (source_collision_kind > SferaNumeric::enumBits(CollisionKind::None)) fail("invalid collision kind");
    const std::size_t source_collision_group_count = integer(250u);
    const std::size_t collision_triangle_count = integer(254u);
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
    if (auto catalogue = materials.snapshot()) model->material_lifetimes.push_back(std::move(catalogue));
    model->name = model_name;
    model->root_bone = byte(15u);
    model->frame_count = word(21u);
    model->has_vertex_colors = source_has_colors == 1u;
    model->collision_kind = SferaNumeric::enumFromBits<CollisionKind>(source_collision_kind);
    model->minimum = point(30u);
    model->maximum = point(42u);
    for (std::size_t index = 0u; index < 8u; ++index) {
        model->oriented_corners.corners[index] = point(54u + index * 12u);
        model->collision_corners.corners[index] = point(150u + index * 12u);
    }
    model->radius = real(246u);
    model->casts_static_shadow = model->radius > 2.0f && source_animation_count == 0u;
    model->lod_distance = parameters.floatValue(model_name, "lod_f").value_or(1000.0f);
    model->lod_power = parameters.floatValue(model_name, "lod_pow").value_or(-1.0f);
    model->shadow_fade = parameters.floatValue(model_name, "shad_f").value_or(0.5f);
    model->shadow_scale = parameters.floatValue(model_name, "shad_s").value_or(2.0f);
    model->shadow_spread = parameters.floatValue(model_name, "shad_sp").value_or(0.8500000238418579f);
    if (const auto alpha = parameters.floatValue(model_name, "land_shade_affect_K")) {
        const float rounded = std::floor(*alpha * 255.0f + 0.5f);
        if (!std::isfinite(rounded) || rounded < (INT32_MIN) || rounded > INT32_MAX) fail("invalid landscape shadow coefficient");
        model->landscape_shadow_alpha = std::min(SferaNumeric::truncateInt(rounded), 255);
    }

    model->materials.resize(source_material_count);
    cursor = source_material_names;
    for (std::size_t index = 0u; index < source_material_count; ++index) {
        if (cursor == source_vertices) fail("missing material name");
        const std::size_t length = byte(cursor++);
        if (length > source_vertices - cursor) fail("material name exceeds its section");
        const std::string material_name(SferaText::prefix(std::span(bytes).subspan(cursor, length), length));
        const auto material = materials.find(material_name);
        if (!material) fail("material is absent from the material library: " + material_name);
        model->materials[index] = material;
        cursor += length;
    }

    model->vertices.resize(source_vertex_count);
    for (std::size_t index = 0u; index < source_vertex_count; ++index) {
        const std::size_t offset = source_vertices + index * 32u;
        model->vertices[index].position = point(offset);
        model->vertices[index].normal = point(offset + 12u);
        model->vertices[index].u = real(offset + 24u);
        model->vertices[index].v = real(offset + 28u);
    }
    model->faces.resize(source_face_count);
    for (std::size_t index = 0u; index < source_face_count; ++index) {
        const std::size_t offset = source_faces + index * 10u;
        for (std::size_t vertex = 0u; vertex < 3u; ++vertex) model->faces[index].vertices[vertex] = word(offset + vertex * 2u);
    }
    model->submeshes.resize(source_submesh_count);
    for (std::size_t index = 0u; index < source_submesh_count; ++index) {
        const std::size_t offset = source_submeshes + index * 15u;
        Submesh& submesh = model->submeshes[index];
        submesh.bone_index = byte(offset) % 128u; submesh.inverted_fade = byte(offset) / 128u != 0u;
        const std::size_t material = byte(offset + 1u);
        if (material >= source_material_count) fail("invalid submesh material");
        submesh.material = model->materials[material];
        submesh.first_face = word(offset + 2u);
        submesh.face_count = word(offset + 4u);
        submesh.first_vertex = word(offset + 6u);
        submesh.vertex_count = word(offset + 8u);

        if (submesh.first_face + submesh.face_count > source_face_count || submesh.first_vertex + submesh.vertex_count > source_vertex_count) fail("submesh range exceeds its geometry");
        if (submesh.bone_index >= source_bone_count) fail("invalid submesh bone");
        for (std::size_t face = submesh.first_face; face < submesh.first_face + submesh.face_count; ++face) for (std::uint16_t vertex : model->faces[face].vertices) if (vertex >= submesh.vertex_count) fail("face vertex exceeds its submesh");
        const Material* material_data = submesh.material;
        if (material_data == nullptr) fail("invalid material index");
        if (material_data->hasColorVariation) model->color_variation = material_data->colorVariation;
    }
    model->bones.resize(source_bone_count);
    for (std::size_t index = 0u; index < source_bone_count; ++index) {
        const std::size_t offset = source_bones + index * 39u;
        Bone& bone = model->bones[index];
        const auto boneName = std::span(bytes).subspan(offset, 32u);
        if (std::find(boneName.begin(), boneName.end(), std::uint8_t{}) == boneName.end()) fail("unterminated bone name");
        bone.name.assign(SferaText::prefix(boneName, boneName.size()));
        bone.has_geometry = byte(offset + 32u) != 2u;
        bone.child_count = byte(offset + 33u);
        bone.first_child = byte(offset + 34u);
        if (bone.first_child + bone.child_count > child_bone_count) fail("bone children exceed the child table");
        if (source_animation_count != 0u) {
            bone.data.emplace<BoneAnimation>();
            bone.animation().animated = byte(offset + 35u);
            bone.animation().pose_index = word(offset + 36u);
            bone.animation().suppress_secondary_animation = byte(offset + 38u);
            if (bone.animation().pose_index >= (bone.animation().animated ? animation_frame_count : keyframe_count)) fail("invalid bone animation offset");
            const std::string_view name = bone.name;
            const auto equal = [&](std::string_view value) { return SferaText::asciiEqual(bone.name, value); };
            if (equal("back_swo")) bone.animation().attachment_slot = 0u;
            else if (equal("back_ara")) bone.animation().attachment_slot = 1u;
            else if (equal("back_axe")) bone.animation().attachment_slot = 2u;
            else if (equal("back_spe")) bone.animation().attachment_slot = 3u;
            else if (equal("back_cam")) bone.animation().attachment_slot = 4u;
            else if (equal("finl_m1o1") || equal("fingl_m1o1")) bone.animation().attachment_slot = 100u;
            else if (equal("finr_m1o1") || equal("fingr_m1o1")) bone.animation().attachment_slot = 101u;
            else if (equal("neck_m1o1")) bone.animation().attachment_slot = 102u;
            else if (name.size() >= 4u && SferaText::asciiEqual(std::string(name.substr(0u, 4u)), "head")) bone.animation().attachment_slot = 103u;
        } else {
            const std::size_t bounds_offset = source_bone_bounds + index * 24u;
            bone.bounds().minimum = point(bounds_offset);
            bone.bounds().maximum = point(bounds_offset + 12u);
            bone.bounds().corners = SferaBoundsCornersRuntime::fromExtents(bone.bounds().minimum, bone.bounds().maximum);
            bone.bounds().center = (bone.bounds().minimum + bone.bounds().maximum) * 0.5f;
            const SferaVec3F diagonal = bone.bounds().maximum - bone.bounds().minimum;
            bone.bounds().diagonal_length = diagonal.length<double, float>();
        }
    }
    model->child_bones.resize(child_bone_count);
    for (std::size_t index = 0u; index < child_bone_count; ++index) {
        model->child_bones[index] = byte(source_children + index);
        if (model->child_bones[index] >= source_bone_count) fail("invalid child bone");
    }
    std::vector<std::uint8_t> visitation(source_bone_count);
    const auto visit = [&](auto&& self, std::size_t index) -> void {
        if (visitation[index] == 1) fail("cyclic bone hierarchy");
        if (visitation[index] == 2) return;
        visitation[index] = 1;
        const auto& bone = model->bones[index];
        for (std::size_t child = 0; child < bone.child_count; ++child) self(self, model->child_bones[bone.first_child + child]);
        visitation[index] = 2;
    };
    for (std::size_t index = 0; index < source_bone_count; ++index) visit(visit, index);
    if (source_animation_count != 0u) {
        model->keyframes.resize(keyframe_count);
        for (std::size_t index = 0u; index < keyframe_count; ++index) {
            const std::size_t offset = source_keyframes + index * 28u;
            model->keyframes[index].translation = point(offset);
            model->keyframes[index].rotation = {real(offset + 12u), real(offset + 16u), real(offset + 20u), real(offset + 24u)};
        }
        model->animation_frames.resize(animation_frame_count);
        for (std::size_t index = 0u; index < animation_frame_count; ++index) {
            AnimationFrame& frame = model->animation_frames[index];
            frame.keyframe = word(source_animation_frames + index * 3u);
            frame.interpolation = byte(source_animation_frames + index * 3u + 2u);
            if (frame.keyframe >= keyframe_count || (frame.interpolation != 255u && frame.keyframe + 1u >= keyframe_count)) fail("invalid animation keyframe");
        }
        model->animation_lengths.resize(source_animation_count);
        std::size_t sequence_begin = 0u;
        std::size_t required_frames = 0u;
        for (std::size_t index = 0u; index < source_animation_count; ++index) {
            const std::uint16_t length = word(source_animation_lengths + index * 2u);
            model->animation_lengths[index] = length;
            required_frames = std::max(required_frames, sequence_begin + std::max<std::size_t>(length, 1u));
            sequence_begin += length;
        }
        for (std::size_t index = 0u; index < source_bone_count; ++index) if (model->bones[index].animation().animated != 0u && model->bones[index].animation().pose_index + required_frames > animation_frame_count) fail("bone animation sequences exceed the frame table");
    }
    if (source_has_colors == 1u) {
        model->vertex_colors.resize(vertex_color_count);
        for (std::size_t index = 0u; index < vertex_color_count; ++index) model->vertex_colors[index] = integer(source_colors + index * 4u);
        model->face_colors.resize(source_face_count);
        for (std::size_t index = 0u; index < source_face_count; ++index) for (std::size_t vertex = 0u; vertex < 3u; ++vertex) {
            const std::uint16_t color = word(source_face_colors + index * 6u + vertex * 2u);
            if (color >= vertex_color_count) fail("invalid face color index");
            model->face_colors[index].vertices[vertex] = color;
        }
    }
    if (source_collision_kind == 2u) {
        model->collision_groups.resize(source_collision_group_count);
        for (std::size_t index = 0u; index < source_collision_group_count; ++index) {
            ModelCollisionGroup& group = model->collision_groups[index];
            group.bone = integer(source_collision_groups + index * 12u);
            group.triangle_count = integer(source_collision_groups + index * 12u + 4u);
            group.first_triangle = integer(source_collision_groups + index * 12u + 8u);
            if (group.bone >= source_bone_count || group.first_triangle > collision_triangle_count || group.triangle_count > collision_triangle_count - group.first_triangle) fail("invalid collision group");
        }
        model->collision_triangles.resize(collision_triangle_count);
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
    model->assignMaterials();
    model->prepareVegetation(parameters);
    return model;
}

SferaVec3F SferaMath::anglesFromBasis(SferaVec3F forward, SferaVec3F up) {
    float roll = 0.0f;
    if (planarSquared(up.x, up.y) > 1.0e-6) {
        const double x = up.x, y = up.y;
        const float azimuth = std::atan2(y, x);
        roll = 4.7123894691467285 - azimuth;
        SferaVec3F::rotatePair(forward.x, forward.y, roll);
        SferaVec3F::rotatePair(up.x, up.y, roll);
    }
    const double y = up.y, z = up.z;
    const float elevation = std::atan2(y, z);
    const float pitch = 4.7123894691467285 - elevation;
    const auto [sine, cosine] = rotationTerms(pitch);
    const float projected = cosine * forward.z - sine * forward.y;
    const double projectedZ = projected, projectedX = forward.x;
    const float heading = std::atan2(projectedZ, projectedX);
    const float yaw = 1.5707964897155762 - heading;
    return {-yaw, -pitch, -roll};
}

void SphereRender::Model::recoverBounds() {
    const auto first_axis = oriented_corners.corners[5] - oriented_corners.corners[0];
    const auto second_axis = oriented_corners.corners[0] - oriented_corners.corners[3];
    bounds_transform = SferaMatrix4x4F::fromEuler(oriented_corners.corners[0], SferaMath::anglesFromBasis(first_axis, second_axis));
    oriented_size = bounds_transform.inverseTransformPoint(oriented_corners.corners[7]);
    const auto extents = collision_kind == CollisionKind::AxisAlignedBounds ? maximum - minimum : oriented_size;
    minimum_size = std::min({extents.x, extents.y, extents.z});
}

void SphereRender::Model::assignMaterials() {
    for (std::size_t index = 0u; index < submeshes.size(); ++index) {
        const Submesh& submesh = submeshes[index];
        const Material* material = submesh.material;
        const std::string_view bone_name = bones[submesh.bone_index].name;
        for (std::size_t vertex = submesh.first_vertex; vertex < submesh.first_vertex + submesh.vertex_count; ++vertex) {
            vertices[vertex].material = material;
            if (bone_name.starts_with("_u")) vertices[vertex].normal = {0.0f, -1.0f, 0.0f};
            else if (bone_name.starts_with("_s")) {
                const SferaVec3F radial{vertices[vertex].position.x, 0.0f, vertices[vertex].position.z};
                const float length = radial.length<double, float>();
                vertices[vertex].normal = length < 0.00001f ? SferaVec3F{} : radial * (1.0f / length);
            }
        }
    }
}

void SphereRender::Model::prepareGrass(bool synchronized, double ground_y) {
    std::vector<int> components(vertices.size(), -1);
    int component = 0;
    for (std::size_t submesh_index = 0u; submesh_index < submeshes.size(); ++submesh_index) {
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
    GrassData grass_data;
    grass_data.influences.resize(vertices.size());
    const std::uint16_t shared_phase = std::rand();
    for (std::size_t index = 0u; index < vertices.size(); ++index) {
        GrassInfluence& influence = grass_data.influences[index];
        const SferaVec3F& position = vertices[index].position;
        if (position.y - ground_y > 0.0) continue;
        if (components[index] < 0) throw std::runtime_error(std::string("Vegetation vertex has no face in model '") + name + "'");
        std::optional<std::size_t> nearest;
        float nearest_squared = 0.0f;
        const auto search = [&](bool same_component) {
            for (std::size_t candidate = 0u; candidate < vertices.size(); ++candidate) {
                if (same_component && components[candidate] != components[index]) continue;
                if (!(vertices[candidate].position.y - ground_y > 0.0)) continue;
                const SferaVec3F difference = position - vertices[candidate].position;
                const float squared = difference.dot(difference);
                if (!nearest || nearest_squared > squared) { nearest = candidate; nearest_squared = squared; }
            }
        };
        search(true);
        if (!nearest) search(false);
        if (!nearest) throw std::runtime_error(std::string("Vegetation has no ground anchor in model '") + name + "'");
        const float distance = std::sqrt(nearest_squared);
        const double anchor_height = vertices[*nearest].position.y;
        const float alignment = std::fabs((position.y - anchor_height) / distance);
        if (alignment < 0.7070000171661377f) influence.anchor_kind = GrassInfluence::Anchor::Horizontal;
        else { influence.anchor_kind = GrassInfluence::Anchor::Vertex; influence.anchor_vertex = *nearest; influence.distance = distance; }
        influence.phase = synchronized ? shared_phase : std::rand();
        influence.share_phase = synchronized && index != 0u;
    }
    vegetation = std::move(grass_data);
}

void SphereRender::Model::prepareTree(double dead_radius, double phase_multiplier) {
    std::vector<TreeInfluence> influences(vertices.size());
    float maximum_radius_squared = 0.0f;
    for (const auto& vertex : vertices) {
        const float squared = SferaMath::planarSquared(vertex.position.x, vertex.position.z);
        maximum_radius_squared = std::max(maximum_radius_squared, squared);
    }
    const float maximum_radius = std::sqrt(maximum_radius_squared);
    float amplitude_scale = 1.0 / (maximum_radius - dead_radius);
    if (radius < 7.0f) amplitude_scale *= 0.4000000059604645;
    const float dead_radius_squared = dead_radius * dead_radius;
    for (std::size_t index = 0; index < vertices.size(); ++index) {
        const auto& position = vertices[index].position;
        const float distance_squared = SferaMath::planarSquared(position.x, position.z);
        if (dead_radius_squared > distance_squared) influences[index].amplitude = 0.0f;
        else {
            const double distance = std::sqrt(distance_squared);
            influences[index].amplitude = (distance - dead_radius) * amplitude_scale;
        }
        const double height = position.y;
        const double phase = std::trunc((height + position.x + position.z) * phase_multiplier);
        if (!std::isfinite(phase) || phase < INT32_MIN || phase > INT32_MAX)
            throw std::runtime_error(std::string("Invalid vegetation phase in model '") + name + "'");
        const int whole_phase = phase;
        influences[index].phase = whole_phase;
    }
    vegetation = std::move(influences);
}

void SphereRender::Model::prepareVegetation(const ModelParameters& parameters) {
    vegetation_kind = SferaNumeric::enumFromBits<VegetationKind>(parameters.intValue(name, "dg_type").value_or(-1));
    const float ground_y = parameters.floatValue(name, "ground_y").value_or(0.0f);
    if (vegetation_kind == VegetationKind::Grass || vegetation_kind == VegetationKind::SynchronizedGrass || vegetation_kind == VegetationKind::InteractiveGrass) prepareGrass(vegetation_kind == VegetationKind::SynchronizedGrass, ground_y);
    if (vegetation_kind == VegetationKind::InteractiveGrass) {
        auto& grass_data = *grass();
        grass_data.bending.resize(vertices.size());
        for (std::size_t index = 0u; index < vertices.size(); ++index) {
            GrassBendingBasis& basis = grass_data.bending[index];
            basis.anchor = {vertices[index].position.x, -0.15000000596046448f, vertices[index].position.z};
            const GrassInfluence& influence = grass_data.influences[index];
            if (influence.anchor_kind != GrassInfluence::Anchor::Vertex) continue;
            const SferaVec3F direction = vertices[index].position - vertices[influence.anchor_vertex].position;
            const SferaVec3F first_axis = SferaVec3F{0.0f, 0.0f, 1.0f}.cross(direction);
            const SferaVec3F second_axis = direction.cross({1.0f, 0.0f, 0.0f});
            const float first_length = first_axis.length<double, float>();
            const float second_length = second_axis.length<double, float>();
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

void SphereRender::Model::initializeGrassGeometry(std::size_t vertices_needed, std::size_t faces_needed, float height) {
    if (!vertices.empty() || !faces.empty() || !bones.empty()) throw std::logic_error("Grass geometry is already initialized");
    std::vector<ModelVertex> new_vertices(vertices_needed);
    std::vector<ModelFace> new_faces(faces_needed);
    std::vector<Bone> new_bones(1u);
    GrassData grass_data;
    grass_data.influences.resize(vertices_needed);
    grass_data.bending.resize(vertices_needed);
    new_bones.front().name = "_u_grass";
    name = "AutoGrass";
    vertices = std::move(new_vertices);
    faces = std::move(new_faces);
    bones = std::move(new_bones);
    vegetation = std::move(grass_data);
    vegetation_kind = VegetationKind::Grass;
    radius = std::sqrt(141.12777709960938f);
    bones[0].has_geometry = true;
    bones[0].bounds().minimum = {-5.0f, -height, -5.0f};
    bones[0].bounds().maximum = {5.0f, 0.0f, 5.0f};
    bones[0].bounds().corners = SferaBoundsCornersRuntime::fromExtents(bones[0].bounds().minimum, bones[0].bounds().maximum);
    bones[0].bounds().center = {0.0f, -0.699999988079071f, 0.0f};
    bones[0].bounds().diagonal_length = 8.0f;
    minimum = bones[0].bounds().minimum;
    maximum = bones[0].bounds().maximum;
    collision_corners = bones[0].bounds().corners;
    lod_distance = 0.5f;
    lod_power = 0.0f;
}

void SphereRender::Model::finishGrassGeometry(std::span<const Submesh> groups) {
    std::vector<Submesh> replacement(groups.begin(), groups.end());
    submeshes.swap(replacement);
    shadow_fade = 0.0f;
    shadow_scale = 1.0f;
    shadow_spread = 1.0f;
    materials.clear();
    casts_static_shadow = false;
    root_bone = 0;
    animation_lengths.clear();
    collision_kind = SphereRender::CollisionKind::None;
}

void SphereRender::TextureRepository::initialize() {
    clear();
    initialized = true;
}

void SphereRender::TextureRepository::addFolder(const std::string& directory) {
    if (directory.empty()) return;
    const std::filesystem::path folder(directory);
    std::error_code error;
    for (std::filesystem::directory_iterator iterator(folder, error), end; !error && iterator != end; iterator.increment(error)) {
        if (!iterator->is_regular_file(error) || error || SferaText::resourceKey(iterator->path().extension().string()) != ".dds") continue;
        auto name = iterator->path().filename().string();
        name.resize(name.find('.'));
        if (name.empty()) continue;
        if (entries.size() >= std::size_t{std::numeric_limits<int>::max()}) throw std::length_error("Resource ID range exhausted");
        const int index = SferaNumeric::signedWord(SferaNumeric::lowWord(entries.size()));
        Entry entry;
        entry.name = name;
        entry.filename = iterator->path();
        entries.push_back(std::move(entry));
        names.insert_or_assign(SferaText::resourceKey(name), index);
    }
}

void SphereRender::TextureRepository::finishRegistration() {
    default_texture = find("default");
}

void SphereRender::TextureRepository::clear() {
    entries.clear();
    names.clear();
    default_texture = -1;
    initialized = false;
}

int SphereRender::TextureRepository::find(std::string_view name) const {
    // The existing texture lookup contract uses entry zero for an unknown name.
    if (!initialized || name.empty()) return 0;
    const auto found = names.find(SferaText::resourceKey(name));
    return found == names.end() ? 0 : found->second;
}

SphereRender::TextureRepository::Entry* SphereRender::TextureRepository::resolve(int index) {
    if (index < 0 || index >= entries.size()) index = default_texture;
    return index >= 0 && index < entries.size() ? &entries[index] : nullptr;
}

IDirect3DBaseTexture9* SphereRender::TextureRepository::resource(int index) {
    auto* entry = resolve(index);
    if (entry == nullptr) return nullptr;
    if (entry->texture != nullptr) return entry->texture.Get();
    const auto bytes = g_sfera_files.readAll(entry->filename.string());
    load(*entry, bytes);
    return entry->texture.Get();
}

SphereUI::TextExtent SphereRender::TextureRepository::size(int index) {
    auto* entry = resolve(index);
    if (entry == nullptr || resource(index) == nullptr) return {};
    D3DSURFACE_DESC description{};
    HRESULT result = E_NOINTERFACE;
    if (entry->texture->GetType() == D3DRTYPE_CUBETEXTURE) {
        Microsoft::WRL::ComPtr<IDirect3DCubeTexture9> texture;
        result = entry->texture.As(&texture);
        if (SUCCEEDED(result)) result = texture->GetLevelDesc(0u, &description);
    } else {
        Microsoft::WRL::ComPtr<IDirect3DTexture9> texture;
        result = entry->texture.As(&texture);
        if (SUCCEEDED(result)) result = texture->GetLevelDesc(0u, &description);
    }
    return SUCCEEDED(result) ? SphereUI::TextExtent{SferaNumeric::signedWord(description.Width), SferaNumeric::signedWord(description.Height)} : SphereUI::TextExtent{};
}

bool SphereRender::TextureRepository::hasAlpha(int index) {
    resource(index);
    const auto* entry = resolve(index);
    return entry != nullptr && entry->has_alpha;
}

void SphereRender::ModelRepository::initialize() {
    clear();
    parameters.load("models\\mdlparam.txt");
}

void SphereRender::ModelRepository::addFolder(const std::string& directory) {
    if (directory.empty()) return;
    const std::filesystem::path folder(directory);
    std::error_code error;
    for (std::filesystem::directory_iterator iterator(folder, error), end; !error && iterator != end; iterator.increment(error)) {
        if (!iterator->is_regular_file(error) || error || SferaText::resourceKey(iterator->path().extension().string()) != ".mdl") continue;
        const auto name = iterator->path().stem().string();
        const auto index = entries.size();
        entries.push_back({name, directory, nullptr, {}});
        names.try_emplace(SferaText::resourceKey(name), index);
    }
}

void SphereRender::ModelRepository::finishRegistration() {
    if (entries.size() >= 5000u) throw std::length_error("Model repository exceeds the model ID range");
}

std::size_t SphereRender::ModelRepository::find(std::string_view name) const {
    if (name.empty()) return invalid_index;
    const auto found = names.find(SferaText::resourceKey(name));
    return found == names.end() ? invalid_index : found->second;
}

std::shared_ptr<SphereRender::Model> SphereRender::ModelRepository::model(std::size_t index) {
    if (index >= entries.size()) throw std::out_of_range("Model repository: invalid model ID");
    auto& entry = entries[index];
    entry.last_used = std::chrono::steady_clock::now();
    if (entry.model == nullptr) entry.model = Model::load(entry.name, entry.directory, parameters, g_sfera_materials);
    if (++requests_since_scan > 100000u) {
        requests_since_scan = 0u;
        evictUnused();
    }
    return entry.model;
}

void SphereRender::ModelRepository::releaseModels() {
    for (auto& entry : entries) {
        if (SphereRender::ModelPose::active_model == entry.model.get()) SphereRender::ModelPose::active_model = nullptr;
        entry.model.reset();
    }
}

void SphereRender::ModelRepository::evictUnused(std::chrono::steady_clock::time_point now) {
    if (entries.empty()) return;
    auto& entry = entries[scan_index];
    if (entry.model != nullptr && entry.model.use_count() == 1 && now - entry.last_used > std::chrono::minutes(15)) {
        if (SphereRender::ModelPose::active_model == entry.model.get()) SphereRender::ModelPose::active_model = nullptr;
        entry.model.reset();
    }
    scan_index = (scan_index + 1u) % entries.size();
}

void SphereRender::ModelRepository::clear() {
    releaseModels();
    entries.clear();
    names.clear();
    parameters.clear();
    requests_since_scan = 0u;
    scan_index = 0u;
}

namespace {
    struct SferaD3D9TextureLoadResult {
        HRESULT status = D3DERR_INVALIDCALL;
        Microsoft::WRL::ComPtr<IDirect3DTexture9> texture;
        bool has_alpha = false;
    };

    SferaD3D9TextureLoadResult sfera_create_d3d9_texture_from_dds(
        IDirect3DDevice9* device,
        std::span<const std::uint8_t> data) noexcept {
        constexpr std::size_t header_size = 128u;
        constexpr std::uint32_t dds_magic = 0x20534444u;
        constexpr std::uint32_t dds_fourcc = 0x4u;
        constexpr std::uint32_t dds_rgb = 0x40u;
        constexpr std::uint32_t dds_alpha = 0x1u;

        SferaD3D9TextureLoadResult result;
        if (device == nullptr || data.size() < header_size || SferaBinary::readLittleEndian<std::uint32_t>(data.data()) != dds_magic ||
            SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 4u) != 124u || SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 76u) != 32u) return result;

        const std::uint32_t height = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 12u);
        const std::uint32_t width = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 16u);
        const std::uint32_t mip_count = (std::max)(1u, SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 28u));
        const std::uint32_t flags = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 80u);
        const std::uint32_t fourcc = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 84u);
        const std::uint32_t bits = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 88u);
        const std::uint32_t red = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 92u);
        const std::uint32_t green = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 96u);
        const std::uint32_t blue = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 100u);
        const std::uint32_t alpha = SferaBinary::readLittleEndian<std::uint32_t>(data.data() + 104u);
        if (width == 0u || height == 0u || mip_count > std::bit_width(std::max(width, height))) return result;

        D3DFORMAT format = D3DFMT_UNKNOWN;
        std::uint32_t block_bytes = 0u;
        std::uint32_t pixel_bytes = 0u;
        bool rgb24 = false;
        if ((flags & dds_fourcc) != 0u) {
            if (fourcc == SferaNumeric::enumBits(D3DFMT_DXT1)) {
                format = D3DFMT_DXT1;
                block_bytes = 8u;
            } else if (fourcc == SferaNumeric::enumBits(D3DFMT_DXT3)) {
                format = D3DFMT_DXT3;
                block_bytes = 16u;
                result.has_alpha = true;
            } else if (fourcc == SferaNumeric::enumBits(D3DFMT_DXT5)) {
                format = D3DFMT_DXT5;
                block_bytes = 16u;
                result.has_alpha = true;
            }
        } else if ((flags & dds_rgb) != 0u && bits == 32u && red == 0x00ff0000u &&
            green == 0x0000ff00u && blue == 0x000000ffu && ((flags & dds_alpha) == 0u || alpha == 0xff000000u)) {
            format = D3DFMT_A8R8G8B8;
            pixel_bytes = 4u;
            result.has_alpha = (flags & dds_alpha) != 0u && alpha == 0xff000000u;
        } else if ((flags & dds_rgb) != 0u && bits == 16u && red == 0x0000f800u &&
            green == 0x000007e0u && blue == 0x0000001fu && alpha == 0u) {
            format = D3DFMT_R5G6B5;
            pixel_bytes = 2u;
        } else if ((flags & dds_rgb) != 0u && bits == 24u && red == 0x00ff0000u &&
            green == 0x0000ff00u && blue == 0x000000ffu && alpha == 0u) {
            format = D3DFMT_A8R8G8B8;
            pixel_bytes = 3u;
            rgb24 = true;
        }
        if (format == D3DFMT_UNKNOWN) return result;

        Microsoft::WRL::ComPtr<IDirect3DTexture9> texture;
        result.status = device->CreateTexture(width, height, mip_count, 0u, format, D3DPOOL_MANAGED,
            texture.GetAddressOf(), nullptr);
        if (FAILED(result.status)) return result;
        if (!texture) { result.status = D3DERR_INVALIDCALL; return result; }

        auto source = data.subspan(header_size);
        std::uint32_t level_width = width;
        std::uint32_t level_height = height;
        for (UINT level = 0; level < mip_count; ++level) {
            const std::size_t columns = block_bytes ? (level_width - 1u) / 4u + 1u : level_width;
            const std::size_t rows = block_bytes ? (level_height - 1u) / 4u + 1u : level_height;
            const std::size_t bytes_per_column = block_bytes ? block_bytes : pixel_bytes;
            result.status = D3DERR_INVALIDCALL;
            if (columns > std::numeric_limits<std::size_t>::max() / bytes_per_column) return result;
            const std::size_t source_pitch = columns * bytes_per_column;
            if (source_pitch > source.size() / rows) return result;
            if (rgb24 && level_width > std::numeric_limits<std::size_t>::max() / 4u) return result;
            const std::size_t destination_pitch = rgb24 ? level_width * 4u : source_pitch;

            TextureMapping mapping(texture.Get(), level);
            result.status = mapping.status();
            if (FAILED(result.status)) return result;
            for (std::size_t row = 0; row < rows; ++row) {
                auto destination = mapping.row(row, destination_pitch);
                if (destination.size() != destination_pitch) {
                    result.status = D3DERR_INVALIDCALL;
                    return result;
                }
                const auto* pixels = source.data() + row * source_pitch;
                if (rgb24) {
                    for (std::size_t column = 0; column < level_width; ++column) {
                        std::copy_n(pixels + column * 3u, 3u, destination.data() + column * 4u);
                        destination[column * 4u + 3u] = 0xffu;
                    }
                } else {
                    std::copy_n(pixels, source_pitch, destination.data());
                }
            }
            result.status = mapping.unlock();
            if (FAILED(result.status)) return result;
            source = source.subspan(source_pitch * rows);
            level_width = std::max(1u, level_width / 2u);
            level_height = std::max(1u, level_height / 2u);
        }
        result.status = D3D_OK;
        result.texture = std::move(texture);
        return result;
    }
}

void SphereRender::TextureRepository::load(Entry& entry, std::span<const std::uint8_t> bytes) {
    if (g_sfera_graphics_runtime.d3d_runtime == nullptr) return;
    auto& runtime = *g_sfera_graphics_runtime.d3d_runtime;
    auto loaded = sfera_create_d3d9_texture_from_dds(runtime.native_device.Get(), bytes);
    runtime.last_hresult = loaded.status;
    if (SUCCEEDED(loaded.status)) {
        entry.texture = std::move(loaded.texture);
        entry.has_alpha = loaded.has_alpha;
    }
}

std::pair<bool, std::array<std::uint8_t, 8>> CShaderMgr::instanceCode(std::string_view filename, bool pixel) {
    std::pair<bool, std::array<std::uint8_t, 8>> code{pixel, {}};
    std::size_t position = 0u;
    for (unsigned pin = 0u; ; ++pin) {
        if (pin == 8u) throw std::invalid_argument("Too many shader pins: " + std::string(filename));
        if (position + 1u >= filename.size()) throw std::invalid_argument("Incomplete shader pin: " + std::string(filename));
        const auto tens = filename[position];
        const auto units = filename[position + 1u];
        if (tens < '0' || tens > '9' || units < '0' || units > '9') throw std::invalid_argument("Invalid shader pin: " + std::string(filename));
        code.second[pin] = (tens - '0') * 10 + units - '0';
        position += 2u;
        if (position == filename.size() || filename[position] != '_') return code;
        ++position;
    }
}

std::array<float, 512> CShaderMgr::makeWaveSamples() {
    constexpr double random_range = RAND_MAX;
    std::array<float, 10> phases{};
    std::array<float, 10> amplitudes{};
    for (std::size_t harmonic = 0; harmonic < phases.size(); ++harmonic) {
        phases[harmonic] = std::rand() / random_range * 6.2831854820251465;
        amplitudes[harmonic] = std::rand() / random_range + 1.0;
    }
    std::array<float, 512> samples{};
    float peak = 0.0f;
    for (std::size_t sample = 0; sample < samples.size(); ++sample) {
        const float angle = sample * 0.012271846644580364;
        for (std::size_t harmonic = 0; harmonic < phases.size(); ++harmonic) {
            const float phase = ((harmonic + 1u) * angle + phases[harmonic]);
            samples[sample] += std::sin(phase) * amplitudes[harmonic];
        }
        peak = std::max(peak, std::abs(samples[sample]));
    }
    if (peak > 0.0f) for (float& sample : samples) sample *= 1.0f / peak;
    return samples;
}

std::array<float, 64> CShaderMgr::makeDownsampleOffsets(float width, float height) {
    if (width <= 0.0f || height <= 0.0f) throw std::invalid_argument("Shader sampling dimensions must be positive");
    std::array<float, 64> offsets{};
    for (unsigned column = 0; column < 4; ++column) {
        for (unsigned row = 0; row < 4; ++row) {
            const auto first = (column * 4u + row) * 4u;
            offsets[first] = (1.5f - column) / width;
            offsets[first + 1] = (row - 1.5f) / height;
        }
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
    if (height < 0.0f) {
        constexpr double exponent = 0.3f;
        const float reflected = std::pow(-height, exponent);
        result.reflection = reflected * reflection_scale;
    }
    return result;
}

void CShaderMgr::loadFolder(const std::string& directory, bool pixel) {
    std::error_code error;
    std::filesystem::directory_iterator files(directory, error);
    if (error) return;
    for (const auto& file : files) {
        if (!file.is_regular_file()) continue;
        std::string extension = file.path().extension().string();
        SferaText::lowercaseLocale(extension);
        if (extension != (pixel ? ".psc" : ".vsc")) continue;
        const std::string filename = file.path().filename().string();
        const auto code = instanceCode(filename, pixel);
        auto inserted = variants.try_emplace(code);
        if (!inserted.second) throw std::runtime_error("Duplicate shader pin combination: " + filename);
        inserted.first->second.filename = filename;
    }
}

CShaderMgr::CShaderMgr(CD3D9Device& owner, std::string vertex_path, std::string pixel_path) : vertex_directory(std::move(vertex_path)), pixel_directory(std::move(pixel_path)), device(owner) {
    try {
        loadFolder(vertex_directory, false);
        loadFolder(pixel_directory, true);
        wave_samples = makeWaveSamples();
        downsample_offsets = makeDownsampleOffsets(g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height);
    } catch (const std::exception& error) {
        CSphereError{}.write(error.what());
    }
}

static std::unordered_map<std::string, int, SferaText::Hash, std::equal_to<>> sfera_shader_constants(std::span<const std::uint8_t> code) {
    constexpr std::uint32_t comment_opcode = 0xfffeu;
    constexpr std::uint32_t end_opcode = 0x0000ffffu;
    constexpr std::uint32_t ctab_signature = 0x42415443u;
    std::unordered_map<std::string, int, SferaText::Hash, std::equal_to<>> constants;
    if (code.size() < 8 || code.size() % 4 != 0) throw std::runtime_error("Truncated compiled shader");
    const bool explicit_lengths = ((SferaBinary::readLittleEndian<std::uint32_t>(code.data()) >> 8u) & 0xffu) >= 2u;
    if (!explicit_lengths && SferaBinary::readLittleEndian<std::uint32_t>(code.data() + code.size() - 4) != end_opcode) {
        throw std::runtime_error("Compiled shader has no END instruction");
    }
    auto instructions = code.subspan(4);
    while (instructions.size() >= 4) {
        const auto token = SferaBinary::readLittleEndian<std::uint32_t>(instructions.data());
        if (token == end_opcode) return constants;
        const bool comment = (token & 0xffffu) == comment_opcode;
        const std::size_t words = comment ? (token >> 16u) & 0x7fffu : (token >> 24u) & 0x0fu;
        instructions = instructions.subspan(4);
        if (words > instructions.size() / 4) {
            if (!explicit_lengths && !comment) return constants;
            throw std::runtime_error("Truncated shader instruction");
        }
        const auto payload = instructions.first(words * 4);
        instructions = instructions.subspan(payload.size());
        if (!comment || payload.size() < 4 ||
            SferaBinary::readLittleEndian<std::uint32_t>(payload.data()) != ctab_signature) continue;
        const auto table = payload.subspan(4);
        if (table.size() < 20) throw std::runtime_error("Truncated shader constant table");
        const auto count = SferaBinary::readLittleEndian<std::uint32_t>(table.data() + 12);
        const auto offset = SferaBinary::readLittleEndian<std::uint32_t>(table.data() + 16);
        if (offset > table.size() || count > (table.size() - offset) / 20) {
            throw std::runtime_error("Invalid shader constant range");
        }
        for (std::size_t index = 0; index < count; ++index) {
            const auto entry = table.subspan(offset + index * 20, 20);
            const auto name_offset = SferaBinary::readLittleEndian<std::uint32_t>(entry.data());
            const auto register_set = SferaBinary::readLittleEndian<std::uint16_t>(entry.data() + 4);
            const auto register_index = SferaBinary::readLittleEndian<std::uint16_t>(entry.data() + 6);
            if (register_set != 2) continue;
            if (name_offset >= table.size()) throw std::runtime_error("Invalid shader constant name");
            const auto name = table.subspan(name_offset);
            const auto end = std::find(name.begin(), name.end(), std::uint8_t{0});
            if (end == name.end()) throw std::runtime_error("Unterminated shader constant name");
            constants[std::string(SferaText::fromBytes(name.first(end - name.begin())))] = register_index;
        }
    }
    if (!explicit_lengths) return constants;
    throw std::runtime_error("Compiled shader has no END instruction");
}

CShaderMgr::Variant& CShaderMgr::loadVariant(const std::pair<bool, std::array<std::uint8_t, 8>>& code) {
    auto found = variants.find(code);
    if (found == variants.end()) {
        CSphereError{}.write(("Unexpected shader group: " + std::to_string(code.second.front())));
        throw std::out_of_range("Shader variant does not exist");
    }
    Variant& variant = found->second;
    if (variant.pixel_shader) return variant;

    const std::string filename = (std::filesystem::path(pixel_directory) / variant.filename).string();
    SferaFileMap file(filename);
    const auto mapped = file.bytes();
    if (!file.isOpen() || mapped.size() < sizeof(DWORD) || mapped.size() % sizeof(DWORD) != 0u) {
        CSphereError{}.write(("Invalid compiled shader: " + filename));
        throw std::runtime_error("Compiled shader could not be read");
    }

    const auto bytes = mapped;
    const auto constants = sfera_shader_constants(bytes);
    std::vector<DWORD> words(bytes.size() / sizeof(DWORD));
    SferaBinary::Reader reader(bytes);
    for (auto& word : words) word = reader.read<std::uint32_t>();
    Variant replacement;
    replacement.filename = variant.filename;
    device.checkResult(device.native_device->CreatePixelShader(words.data(),
        replacement.pixel_shader.GetAddressOf()), "CreatePixelShader");
    const auto resolve = [&](std::string_view name) -> std::optional<UINT> {
        const auto iterator = constants.find(name);
        return iterator == constants.end() ? std::nullopt : std::optional<UINT>{iterator->second};
    };
    replacement.alpha_register = resolve("gAlpha");
    replacement.down_filter_register = resolve("gTexelCoordsDownFilter");
    replacement.water_gradient_register = resolve("gWaterGradientCoefficient");
    replacement.water_specular_register = resolve("gWaterSpecular");
    replacement.water_reflection_register = resolve("gWaterReflectCoefficient");
    variant = std::move(replacement);
    return variant;
}

void CShaderMgr::setPixelShader(std::uint32_t group) {
    if (group == 10u || group == 11u) return;
    if (group > 13u) {
        CSphereError{}.write(("Unknown pixel shader group: " + std::to_string(group)));
        return;
    }

    std::pair<bool, std::array<std::uint8_t, 8>> code{true, {SferaNumeric::lowByte(group)}};
    if (group == 0u) code.second[3] = 1u;

    Variant& variant = loadVariant(code);
    device.checkResult(device.native_device->SetPixelShader(variant.pixel_shader.Get()), "SetPixelShader");
    const auto set_float = [&](std::optional<UINT> shader_register, float value) {
        if (!shader_register) return;
        const float data[4] = {value, 0.0f, 0.0f, 0.0f};
        device.checkResult(device.native_device->SetPixelShaderConstantF(
            *shader_register, data, 1u), "SetPixelShaderConstantF");
    };

    if (group == 3u) set_float(variant.alpha_register, 0.0f);
    if (group == 6u && variant.down_filter_register) {
        device.checkResult(device.native_device->SetPixelShaderConstantF(
            *variant.down_filter_register, downsample_offsets.data(),
            (downsample_offsets.size() / 4)), "SetPixelShaderConstantF");
    }
    if (group == 1u) {
        const WaterParameters water = waterParameters(
            g_sfera_graphics_runtime.environment_factor, SphereRender::SceneRenderer::sun_direction.y);
        set_float(variant.water_gradient_register, water.gradient);
        set_float(variant.water_specular_register, water.specular);
        set_float(variant.water_reflection_register, water.reflection);
    }
}

CPostEffectsMgr::CPostEffectsMgr(CD3D9Device& owner) : device(owner) {
    const D3DVERTEXELEMENT9 elements[] = {
        {0, 0, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITIONT, 0},
        {0, 16, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0},
        {0, 24, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 1},
        D3DDECL_END()
    };
    device.checkResult(device.native_device->CreateVertexDeclaration(elements, vertex_declaration.GetAddressOf()), "CreateVertexDeclaration");
}

CPostEffectsMgr::~CPostEffectsMgr() { releaseResources(); }

void CPostEffectsMgr::restoreResources() {
    if (!enabled) return;
    device.checkResult(device.native_device->TestCooperativeLevel(), "TestCooperativeLevel");
    const auto create = [&](std::uint32_t width, std::uint32_t height) {
        Microsoft::WRL::ComPtr<IDirect3DTexture9> texture;
        device.checkResult(device.native_device->CreateTexture(width, height, 1, D3DUSAGE_RENDERTARGET,
            D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, texture.GetAddressOf(), nullptr), "CreateTexture(post effects)");
        return texture;
    };
    auto scene = create(g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height);
    auto temporary = create(128, 128);
    auto blurred = create(128, 128);
    capture.reset();
    scene_texture = std::move(scene);
    temporary_texture = std::move(temporary);
    blur_texture = std::move(blurred);
}

void CPostEffectsMgr::releaseResources() {
    capture.reset();
    blur_texture.Reset();
    temporary_texture.Reset();
    scene_texture.Reset();
}

void CPostEffectsMgr::setEnabled(bool value) {
    if (enabled == value) return;
    enabled = value;
    if (!enabled) { releaseResources(); return; }
    try { restoreResources(); }
    catch (...) { enabled = false; throw; }
}

void CPostEffectsMgr::beginCapture() {
    if (!enabled) return;
    if (capture) throw std::logic_error("Post-effects capture is already active");
    if (!scene_texture) restoreResources();
    capture.emplace(device, *scene_texture.Get());
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
    device.checkResult(device.native_device->SetVertexDeclaration(vertex_declaration.Get()), "SetVertexDeclaration");
}

void CPostEffectsMgr::drawQuad(std::uint32_t width, std::uint32_t height) {
    const float right = width - 0.5f;
    const float bottom = height - 0.5f;
    const ScreenVertex vertices[] = {
        {-0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f},
        {-0.5f, bottom, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f},
        {right, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f},
        {right, bottom, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f}
    };
    device.checkResult(device.native_device->Clear(0u, nullptr, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0u), "Clear");
    device.checkResult(device.native_device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2u, vertices, sizeof(ScreenVertex)), "DrawPrimitiveUP(post effects)");
}

void CPostEffectsMgr::renderToTexture(IDirect3DTexture9* target) {
    D3DSURFACE_DESC description{};
    device.checkResult(target->GetLevelDesc(0, &description), "GetLevelDesc");
    RenderTargetScope selected(device, *target);
    drawQuad(description.Width, description.Height);
}

void CPostEffectsMgr::blur() {
    device.checkResult(device.native_device->SetTexture(0u, scene_texture.Get()), "SetTexture(scene)");
    device.shaders->setPixelShader(6u);
    renderToTexture(blur_texture.Get());
    device.checkResult(device.native_device->SetTexture(0u, blur_texture.Get()), "SetTexture(blur)");
    device.shaders->setPixelShader(7u);
    renderToTexture(temporary_texture.Get());
    device.checkResult(device.native_device->SetTexture(0u, temporary_texture.Get()), "SetTexture(blur temporary)");
    device.shaders->setPixelShader(8u);
    renderToTexture(blur_texture.Get());
}

void CPostEffectsMgr::compose() {
    if (!enabled || !capture) return;
    auto frame = std::move(capture);
    capture.reset();
    RenderStateScope state(device);
    configureRenderState();
    blur();
    device.checkResult(frame->restore(), "RestoreRenderTarget");
    device.checkResult(device.native_device->SetTexture(0, scene_texture.Get()), "SetTexture(scene)");
    device.checkResult(device.native_device->SetTexture(1, blur_texture.Get()), "SetTexture(blur)");
    device.shaders->setPixelShader(9);
    drawQuad(g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height);
}

CD3D9Device::CD3D9Device() : model_vertices(*this), colored_vertices(*this), indices_primary(*this), indices_secondary(*this) {
    api.Attach(Direct3DCreate9(D3D_SDK_VERSION));
    if (api == nullptr) { CSphereError error; error.write("CD3D9Device::CD3D9Device() => Direct3DCreate9() failed."); }
}

CD3D9Device::~CD3D9Device() {
    endScene();
    post_effects.reset();
    shaders.reset();
    reflection_target.reset();
    minimap_target.reset();
    for (auto* resource : unmanaged_resources) { resource->releaseResource(); resource->device = nullptr; }
    unmanaged_resources.clear();
}

HRESULT CD3D9Device::checkResult(HRESULT result, std::string_view operation) {
    last_hresult = result;
    if (FAILED(result)) {
        auto message = std::format("{} failed (HRESULT 0x{:08X})", operation, SferaNumeric::lowWord(result));
        CSphereError error;
        error.write(message);
    }
    return result;
}

void CD3D9Device::enumerateDisplayModes(bool windowed) {
    if (!api) throw std::runtime_error("Graphics interface is unavailable");
    D3DDISPLAYMODE display{};
    checkResult(api->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &display), "GetAdapterDisplayMode");
    display_modes.clear();
    for (const D3DFORMAT format : {D3DFMT_R5G6B5, D3DFMT_X8R8G8B8}) {
        const auto adapter_format = windowed ? display.Format : format;
        if (FAILED(api->CheckDeviceType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, adapter_format, format, windowed)) ||
            selectDepthFormat(adapter_format, format) == D3DFMT_UNKNOWN) continue;
        const std::uint32_t depth_bits = format == D3DFMT_X8R8G8B8 ? 32u : 16u;
        const UINT count = api->GetAdapterModeCount(D3DADAPTER_DEFAULT, format);
        for (UINT index = 0u; index < count; ++index) {
            D3DDISPLAYMODE mode{};
            if (FAILED(api->EnumAdapterModes(D3DADAPTER_DEFAULT, format, index, &mode))) continue;
            if (mode.Width < 800u || mode.Height < 600u) continue;
            if (windowed && mode.Height >= display.Height) continue;
            if (!supportsDisplayMode(mode.Width, mode.Height, depth_bits)) display_modes.push_back({mode.Width, mode.Height, depth_bits});
        }
        // Windowed back buffers are not restricted to enumerated fullscreen sizes.
        if (windowed && !supportsDisplayMode(800u, 600u, depth_bits)) display_modes.push_back({800u, 600u, depth_bits});
    }
    if (display_modes.empty()) throw std::runtime_error("No compatible Direct3D 9 display mode with a depth buffer was found");
}

bool CD3D9Device::supportsDisplayMode(std::uint32_t width, std::uint32_t height, std::uint32_t depth_bits) const {
    return std::any_of(display_modes.begin(), display_modes.end(), [=](const SphereUI::DisplayMode& mode) { return mode.width == width && mode.height == height && mode.depth == depth_bits; });
}

void CD3D9Device::selectBackBufferFormat(const D3DDISPLAYMODE& display, bool windowed,
    std::uint32_t& width, std::uint32_t& height, D3DFORMAT& format) {
    if (windowed) {
        const std::array candidates{format, display.Format, D3DFMT_X8R8G8B8, D3DFMT_R5G6B5};
        for (const auto candidate : candidates) {
            if (SUCCEEDED(api->CheckDeviceType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, display.Format, candidate, TRUE)) &&
                selectDepthFormat(display.Format, candidate) != D3DFMT_UNKNOWN) {
                format = candidate;
                return;
            }
        }
        throw std::runtime_error("No compatible Direct3D 9 windowed back-buffer/depth-stencil combination was found");
    }
    if (display_modes.empty()) throw std::runtime_error("No compatible Direct3D 9 fullscreen mode was found");
    const auto depth_bits = format == D3DFMT_R5G6B5 ? 16u : 32u;
    const auto rank = [=](const SphereUI::DisplayMode& mode) {
        const unsigned size_rank = mode.width == width && mode.height == height ? 0u :
            (mode.width == display.Width && mode.height == display.Height ? 1u : 2u);
        const std::uint64_t dx = mode.width > width ? mode.width - width : width - mode.width;
        const std::uint64_t dy = mode.height > height ? mode.height - height : height - mode.height;
        return std::tuple{size_rank, dx + dy, mode.depth == depth_bits ? 0u : 1u};
    };
    // Keep the requested size first, then the desktop size, then a real nearby mode.
    // A colour-depth fallback must select a mode enumerated for that same format.
    const auto selected = std::min_element(display_modes.begin(), display_modes.end(),
        [&](const auto& left, const auto& right) { return rank(left) < rank(right); });
    width = selected->width;
    height = selected->height;
    format = selected->depth == 16u ? D3DFMT_R5G6B5 : D3DFMT_X8R8G8B8;
}

D3DFORMAT CD3D9Device::selectDepthFormat(D3DFORMAT adapter_format, D3DFORMAT back_buffer_format) const {
    // These buffers are never CPU-locked. Lockable formats cannot use DISCARD_DEPTHSTENCIL.
    for (const auto candidate : {D3DFMT_D32, D3DFMT_D24S8, D3DFMT_D24X8, D3DFMT_D24X4S4, D3DFMT_D16, D3DFMT_D15S1}) {
        if (SUCCEEDED(api->CheckDeviceFormat(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, adapter_format,
                D3DUSAGE_DEPTHSTENCIL, D3DRTYPE_SURFACE, candidate)) &&
            SUCCEEDED(api->CheckDepthStencilMatch(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
                adapter_format, back_buffer_format, candidate))) return candidate;
    }
    return D3DFMT_UNKNOWN;
}

void CD3D9Device::initialize(HWND window, std::uint32_t width, std::uint32_t height, std::uint32_t depth_bits, bool windowed) {
    if (!window || !::IsWindow(window)) throw std::invalid_argument("CreateDevice requires a valid application window");
    owner_thread_ = ::GetCurrentThreadId();
    if (::GetWindowThreadProcessId(window, nullptr) != owner_thread_)
        throw std::logic_error("CreateDevice must run on the application window thread");
    RECT client{};
    if (!::GetClientRect(window, &client) || client.right <= client.left || client.bottom <= client.top)
        throw std::invalid_argument("CreateDevice requires a non-empty application window");
    if (depth_bits != 16u && depth_bits != 32u) depth_bits = 32u;
    width = std::max(width, 800u);
    height = std::max(height, 600u);
    enumerateDisplayModes(windowed);
    D3DDISPLAYMODE display{};
    checkResult(api->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &display), "GetAdapterDisplayMode");
    D3DFORMAT back_buffer = depth_bits == 32u ? D3DFMT_X8R8G8B8 : D3DFMT_R5G6B5;
    selectBackBufferFormat(display, windowed, width, height, back_buffer);
    const auto depth_format = selectDepthFormat(windowed ? display.Format : back_buffer, back_buffer);
    if (depth_format == D3DFMT_UNKNOWN) throw std::runtime_error("No matching Direct3D 9 depth-stencil format was found");
    capabilities = {};
    checkResult(api->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &capabilities), "GetDeviceCaps");
    const bool hardware_vertices = (capabilities.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) != 0u;
    // Viewport/state guards use Get* methods, which are not supported by a pure device.
    DWORD behavior = D3DCREATE_FPU_PRESERVE |
        (hardware_vertices ? D3DCREATE_HARDWARE_VERTEXPROCESSING : D3DCREATE_SOFTWARE_VERTEXPROCESSING);
    D3DPRESENT_PARAMETERS requested{};
    requested.BackBufferWidth = width;
    requested.BackBufferHeight = height;
    requested.BackBufferFormat = back_buffer;
    requested.BackBufferCount = 1u;
    requested.MultiSampleType = D3DMULTISAMPLE_NONE;
    requested.MultiSampleQuality = 0u;
    requested.SwapEffect = D3DSWAPEFFECT_DISCARD;
    requested.hDeviceWindow = window;
    requested.Windowed = windowed ? TRUE : FALSE;
    requested.EnableAutoDepthStencil = TRUE;
    requested.AutoDepthStencilFormat = depth_format;
    requested.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
    requested.FullScreen_RefreshRateInHz = 0u;
    requested.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
    Microsoft::WRL::ComPtr<IDirect3DDevice9> created;
    D3DPRESENT_PARAMETERS accepted{};
    const auto create = [&] {
        accepted = requested; // A failed CreateDevice may also modify presentation parameters.
        return api->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window, behavior,
            &accepted, created.ReleaseAndGetAddressOf());
    };
    const HRESULT first_result = create();
    HRESULT result = first_result;
    if (hardware_vertices && (result == D3DERR_INVALIDCALL || result == D3DERR_NOTAVAILABLE)) {
        behavior = D3DCREATE_FPU_PRESERVE | D3DCREATE_SOFTWARE_VERTEXPROCESSING;
        result = create();
    }
    if (FAILED(result)) {
        auto operation = std::format(
            "CreateDevice [{}x{}, windowed={}, adapterFormat={}, backBuffer={}, depthStencil={}, behavior=0x{:08X}, "
            "flags=0x{:08X}, refresh={}, interval=0x{:08X}, HWND={:p}, firstHRESULT=0x{:08X}]",
            width, height, windowed ? 1u : 0u, SferaNumeric::enumBits(windowed ? display.Format : back_buffer), SferaNumeric::enumBits(back_buffer),
            SferaNumeric::enumBits(depth_format), behavior, requested.Flags,
            requested.FullScreen_RefreshRateInHz, requested.PresentationInterval, static_cast<void*>(window),
            SferaNumeric::lowWord(first_result));
        checkResult(result, operation);
    }
    native_device = std::move(created);
    presentation = accepted;
    g_sfera_graphics_runtime.display_width = presentation.BackBufferWidth;
    g_sfera_graphics_runtime.display_height = presentation.BackBufferHeight;
    g_sfera_graphics_runtime.display_depth_bits = presentation.BackBufferFormat == D3DFMT_R5G6B5 ||
        presentation.BackBufferFormat == D3DFMT_X1R5G5B5 || presentation.BackBufferFormat == D3DFMT_A1R5G5B5 ? 16u : 32u;
    supports_post_effects = capabilities.VertexShaderVersion >= D3DVS_VERSION(2, 0) && capabilities.PixelShaderVersion >= D3DPS_VERSION(2, 0);
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
    const auto identity = SferaMatrix4x4F::identity();
    setTransform(D3DTS_WORLD, identity);
    SphereUI::InterfaceRenderer::sprite_render_mode = UINT32_MAX;
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

void CD3D9Device::setTransform(D3DTRANSFORMSTATETYPE kind, const SferaMatrix4x4F& matrix) {
    D3DMATRIX native{};
    for (std::size_t row = 0; row < 4; ++row) std::copy_n(matrix.m[row], 4, native.m[row]);
    const HRESULT result = native_device->SetTransform(kind, &native);
    last_hresult = result;
    checkResult(result, "SetTransform");
    if (kind == D3DTS_WORLD) world_transform = matrix;
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

UINT CD3D9Device::primitiveCount(D3DPRIMITIVETYPE topology, UINT elements) {
    switch (topology) {
        case D3DPT_POINTLIST: return elements;
        case D3DPT_LINELIST: return elements / 2u;
        case D3DPT_LINESTRIP: return elements > 1u ? elements - 1u : 0u;
        case D3DPT_TRIANGLELIST: return elements / 3u;
        case D3DPT_TRIANGLESTRIP:
        case D3DPT_TRIANGLEFAN: return elements > 2u ? elements - 2u : 0u;
        default: throw std::invalid_argument("Unknown Direct3D primitive topology");
    }
}

void CD3D9Device::applyDrawState(std::uint32_t flags) {
    checkResult(native_device->SetRenderState(D3DRS_CULLMODE, (flags & two_sided) != 0u ? D3DCULL_NONE : D3DCULL_CW), "SetRenderState(CULLMODE)");
    checkResult(native_device->SetRenderState(D3DRS_LIGHTING, (flags & lighting) != 0u), "SetRenderState(LIGHTING)");
    checkResult(native_device->SetRenderState(D3DRS_CLIPPING, (flags & disable_clipping) == 0u), "SetRenderState(CLIPPING)");
}

void CD3D9Device::drawBuffer(IDirect3DVertexBuffer9* vertices, D3DPRIMITIVETYPE topology, std::uint32_t flags, std::ptrdiff_t base_vertex, std::size_t vertex_count, IDirect3DIndexBuffer9* indices, std::size_t index_count, std::size_t start_index, std::size_t stride) {
    if (!native_device) return;
    if (vertex_count > UINT_MAX || index_count > UINT_MAX || stride > UINT_MAX || start_index > UINT_MAX ||
        !std::in_range<INT>(base_vertex) || (index_count == 0 && base_vertex < 0))
        throw std::length_error("Draw range exceeds the Direct3D API limits");
    const UINT primitives = primitiveCount(topology, (index_count ? index_count : vertex_count));
    if (primitives == 0) return;
    if (!vertices || vertex_count == 0 || stride == 0) throw std::invalid_argument("Empty Direct3D vertex buffer range");
    applyDrawState(flags);
    D3DVERTEXBUFFER_DESC description{};
    checkResult(vertices->GetDesc(&description), "GetDesc(vertex buffer)");
    checkResult(native_device->SetFVF(description.FVF), "SetFVF");
    checkResult(native_device->SetStreamSource(0u, vertices, 0u, stride), "SetStreamSource");
    if (index_count) {
        if (!indices) indices = indices_primary.buffer();
        if (!indices) throw std::invalid_argument("Empty Direct3D index buffer");
        checkResult(native_device->SetIndices(indices), "SetIndices");
        checkResult(native_device->DrawIndexedPrimitive(topology, base_vertex, 0u,
            vertex_count, start_index, primitives), "DrawIndexedPrimitive");
    } else {
        checkResult(native_device->DrawPrimitive(topology, base_vertex, primitives), "DrawPrimitive");
    }
}

void CD3D9Device::drawVertices(D3DPRIMITIVETYPE topology, std::uint32_t flags, const void* vertices, std::size_t vertex_count, const std::uint16_t* indices, std::size_t index_count, std::size_t stride) {
    if (!native_device) return;
    if (vertex_count > UINT_MAX || index_count > UINT_MAX || stride > UINT_MAX)
        throw std::length_error("Draw range exceeds the Direct3D API limits");
    const UINT primitives = primitiveCount(topology, (index_count ? index_count : vertex_count));
    if (primitives == 0) return;
    if (!vertices || vertex_count == 0 || stride == 0 || (index_count && !indices))
        throw std::invalid_argument("Empty Direct3D draw range");
    applyDrawState(flags);
    if (index_count) {
        checkResult(native_device->DrawIndexedPrimitiveUP(topology, 0u, vertex_count, primitives,
            indices, D3DFMT_INDEX16, vertices, stride), "DrawIndexedPrimitiveUP");
    } else {
        checkResult(native_device->DrawPrimitiveUP(topology, primitives, vertices, stride), "DrawPrimitiveUP");
    }
}

void CD3D9Device::releaseResources() {
    sync_query.Reset();
    if (post_effects != nullptr) post_effects->releaseResources();
    for (auto* resource : unmanaged_resources) resource->releaseResource();
}

void CD3D9Device::restoreResources() {
    initializeRenderState();
    last_hresult = native_device->CreateQuery(D3DQUERYTYPE_EVENT, sync_query.ReleaseAndGetAddressOf());
    if (last_hresult != S_OK) {
        g_sfera_log_runtime.write("Render err: cant create query:");
        g_sfera_log_runtime.write(SferaNumeric::signedWord(last_hresult));
    }
    if (post_effects != nullptr) post_effects->restoreResources();
    for (auto* resource : unmanaged_resources) resource->restoreResource();
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
    if (!native_device || scene_open_ || resetting_) return false;
    if (owner_thread_ != ::GetCurrentThreadId()) throw std::logic_error("Direct3D used from a non-owner thread");
    last_hresult = native_device->TestCooperativeLevel();
    if (last_hresult == D3DERR_DEVICELOST) return false;
    if (last_hresult == D3DERR_DEVICENOTRESET) {
        struct ResetGuard { bool& value; ~ResetGuard() { value = false; } } guard{resetting_};
        resetting_ = true;
        releaseResources();
        auto requested = presentation; // Reset is allowed to modify its argument.
        last_hresult = native_device->Reset(&requested);
        if (last_hresult == D3DERR_DEVICELOST || last_hresult == D3DERR_DEVICENOTRESET) return false;
        checkResult(last_hresult, "Reset");
        try { restoreResources(); }
        catch (...) { releaseResources(); throw; }
    } else {
        checkResult(last_hresult, "TestCooperativeLevel");
    }
    last_hresult = native_device->BeginScene();
    if (last_hresult == D3DERR_DEVICELOST) return false;
    checkResult(last_hresult, "BeginScene");
    scene_open_ = true;
    return true;
}

HRESULT CD3D9Device::endScene() noexcept {
    if (!std::exchange(scene_open_, false) || !native_device) return S_OK;
    if (post_effects) post_effects->cancelCapture();
    return last_hresult = native_device->EndScene();
}

bool CD3D9Device::present() {
    if (!native_device || scene_open_ || resetting_) return false;
    last_hresult = native_device->Present(nullptr, nullptr, nullptr, nullptr);
    if (last_hresult == D3DERR_DEVICELOST || last_hresult == D3DERR_DEVICENOTRESET) return false;
    return SUCCEEDED(checkResult(last_hresult, "Present"));
}

void SceneScope::finish() {
    auto* device = std::exchange(device_, nullptr);
    if (!device) return;
    const auto result = device->endScene();
    if (result != D3DERR_DEVICELOST) device->checkResult(result, "EndScene");
}

RenderStateScope::RenderStateScope(CD3D9Device& device, FailurePolicy failure)
    : device_(device), world_transform_(device.world_transform),
      active_lights_(g_sfera_light_runtime.active_lights),
      active_light_count_(g_sfera_light_runtime.active_count),
      sprite_render_mode_(SphereUI::InterfaceRenderer::sprite_render_mode) {
    device.last_hresult = device.native_device->CreateStateBlock(D3DSBT_ALL, state_.GetAddressOf());
    if (failure == FailurePolicy::Throw) device.checkResult(device.last_hresult, "CreateStateBlock");
}
RenderStateScope::~RenderStateScope() noexcept {
    if (!state_) return;
    const HRESULT result = state_->Apply();
    if (SUCCEEDED(result)) {
        // CPU caches must describe the same state that the block restored on the GPU.
        // Invalidating only the light cache would leave enabled GPU slots invisible
        // to disableActiveLights; retaining the pass matrix breaks shadow projection.
        device_.world_transform = world_transform_;
        g_sfera_light_runtime.active_lights = active_lights_;
        g_sfera_light_runtime.active_count = active_light_count_;
        SphereUI::InterfaceRenderer::sprite_render_mode = sprite_render_mode_;
    } else {
        device_.last_hresult = result;
        g_sfera_light_runtime.invalidateActiveLights();
        SphereUI::InterfaceRenderer::sprite_render_mode = UINT32_MAX;
    }
}

UnmanagedResourceBase::UnmanagedResourceBase(CD3D9Device& owner, D3DPOOL pool) : device(&owner), registered(pool != D3DPOOL_MANAGED) {
    if (registered) owner.unmanaged_resources.push_back(this);
}

UnmanagedResourceBase::~UnmanagedResourceBase() {
    if (registered && device != nullptr) std::erase(device->unmanaged_resources, this);
}

TextureMapping::TextureMapping(IDirect3DTexture9* texture, UINT level, DWORD flags) noexcept
    : texture_(texture), level_(level) {
    if (!texture_) return;
    status_ = texture_->GetLevelDesc(level_, &description_);
    if (FAILED(status_)) return;
    status_ = texture_->LockRect(level_, &rectangle_, nullptr, flags);
    locked_ = SUCCEEDED(status_);
    if (locked_ && !rectangle_.pBits) {
        unlock();
        status_ = D3DERR_INVALIDCALL;
    }
}

TextureMapping::TextureMapping(TextureMapping&& other) noexcept
    : texture_(std::move(other.texture_)), level_(other.level_), description_(other.description_),
      rectangle_(std::exchange(other.rectangle_, {})), status_(other.status_), locked_(std::exchange(other.locked_, false)) {}
TextureMapping::~TextureMapping() { unlock(); }

HRESULT TextureMapping::unlock() noexcept {
    rectangle_ = {};
    return texture_ && std::exchange(locked_, false) ? texture_->UnlockRect(level_) : S_OK;
}

std::span<std::uint8_t> TextureMapping::row(std::size_t index, std::size_t bytes) const noexcept {
    const std::int64_t pitch = rectangle_.Pitch;
    const std::uint64_t magnitude = pitch < 0 ? -pitch : pitch;
    if (!texture_ || !locked_ || !rectangle_.pBits || index >= description_.Height ||
        bytes > magnitude || (magnitude != 0 && index > std::numeric_limits<std::ptrdiff_t>::max() / magnitude)) return {};
    const std::ptrdiff_t row_index = index;
    const std::ptrdiff_t offset = row_index * pitch;
    return {static_cast<std::uint8_t*>(rectangle_.pBits) + offset, bytes};
}

HRESULT TextureMapping::copyRows(std::span<const std::byte> source, std::size_t rowBytes, std::size_t rows) noexcept {
    if (rows == 0 || rowBytes == 0) return S_OK;
    if (rowBytes > source.size() / rows || rows > description_.Height) return D3DERR_INVALIDCALL;
    for (std::size_t index = 0; index < rows; ++index) {
        const auto destination = row(index, rowBytes);
        if (destination.size() != rowBytes) return D3DERR_INVALIDCALL;
        std::memcpy(destination.data(), source.data() + index * rowBytes, rowBytes);
    }
    return S_OK;
}

RenderTargetScope::RenderTargetScope(CD3D9Device& device, IDirect3DTexture9& target) : device_(&device) {
    auto* native = device.native_device.Get();
    if (!native) throw std::logic_error("Render target has no Direct3D device");
    device.checkResult(native->GetRenderTarget(0, color_.GetAddressOf()), "GetRenderTarget");
    const HRESULT depthStatus = native->GetDepthStencilSurface(depth_.GetAddressOf());
    if (depthStatus != D3DERR_NOTFOUND) device.checkResult(depthStatus, "GetDepthStencilSurface");
    device.checkResult(native->GetViewport(&viewport_), "GetViewport");
    Microsoft::WRL::ComPtr<IDirect3DSurface9> surface;
    device.checkResult(target.GetSurfaceLevel(0, surface.GetAddressOf()), "GetSurfaceLevel");
    const HRESULT status = native->SetRenderTarget(0, surface.Get());
    if (FAILED(status)) restore();
    device.checkResult(status, "SetRenderTarget");
}

RenderTargetScope::RenderTargetScope(RenderTargetScope&& other) noexcept
    : device_(std::exchange(other.device_, nullptr)), color_(std::move(other.color_)),
      depth_(std::move(other.depth_)), viewport_(other.viewport_) {}

RenderTargetScope::~RenderTargetScope() { restore(); }

HRESULT RenderTargetScope::restore() noexcept {
    auto* owner = std::exchange(device_, nullptr);
    if (!owner || !owner->native_device) return S_OK;
    auto* native = owner->native_device.Get();
    HRESULT result = native->SetRenderTarget(0, color_.Get());
    const auto record = [&](HRESULT status) { if (SUCCEEDED(result) && FAILED(status)) result = status; };
    record(native->SetDepthStencilSurface(depth_.Get()));
    record(native->SetViewport(&viewport_));
    return result;
}

UnmanagedResourceTexture::UnmanagedResourceTexture(CD3D9Device& owner, std::uint32_t width,
    std::uint32_t height, std::uint32_t levels, std::uint32_t usage, D3DFORMAT format, D3DPOOL pool)
    : UnmanagedResourceBase(owner, pool), width(width), height(height), levels(levels),
      usage(usage), format(format), pool(pool) {
    restoreResource();
}

void UnmanagedResourceTexture::releaseResource() { native_texture.Reset(); }

void UnmanagedResourceTexture::restoreResource() {
    if (native_texture || !device || !device->native_device) return;
    Microsoft::WRL::ComPtr<IDirect3DTexture9> replacement;
    device->checkResult(device->native_device->CreateTexture(width, height, levels, usage, format,
        pool, replacement.GetAddressOf(), nullptr), "CreateTexture");
    native_texture = std::move(replacement);
}

template<class Element>
DynamicStream<Element>::DynamicStream(CD3D9Device& owner) : UnmanagedResourceBase(owner, D3DPOOL_DEFAULT) {}

template<class Element>
DynamicStream<Element>::Mapping::Mapping(CD3D9Device& device, Microsoft::WRL::ComPtr<Buffer> buffer,
    std::size_t first, std::size_t count, Element* data)
    : device_(&device), buffer_(std::move(buffer)), first_(first), count_(count), data_(data) {}

template<class Element>
DynamicStream<Element>::Mapping::Mapping(Mapping&& other) noexcept
    : device_(std::exchange(other.device_, nullptr)), buffer_(std::move(other.buffer_)),
      first_(other.first_), count_(other.count_), data_(std::exchange(other.data_, nullptr)) {}

template<class Element>
typename DynamicStream<Element>::Mapping& DynamicStream<Element>::Mapping::operator=(Mapping&& other) noexcept {
    if (this == std::addressof(other)) return *this;
    if (buffer_ && data_) buffer_->Unlock();
    buffer_ = std::move(other.buffer_);
    device_ = other.device_;
    first_ = other.first_;
    count_ = other.count_;
    data_ = std::exchange(other.data_, nullptr);
    return *this;
}

template<class Element>
DynamicStream<Element>::Mapping::~Mapping() {
    if (buffer_ && data_) buffer_->Unlock();
}

template<class Element>
void DynamicStream<Element>::Mapping::unlock() {
    if (!buffer_ || !std::exchange(data_, nullptr)) return;
    device_->checkResult(buffer_->Unlock(), indexed ? "IndexBuffer::Unlock" : "VertexBuffer::Unlock");
}

template<class Element>
void DynamicStream<Element>::reserve(std::size_t count) {
    if (count <= capacity_ && buffer_) return;
    count = std::max(count, capacity_);
    if (count == 0) return;
    constexpr auto limit = std::numeric_limits<UINT>::max() / sizeof(Element);
    if (count > limit) throw std::length_error("Direct3D stream exceeds the API size limit");
    if (!device || !device->native_device) throw std::logic_error("Direct3D stream has no device");
    Microsoft::WRL::ComPtr<Buffer> replacement;
    const UINT bytes = SferaNumeric::lowWord(count * sizeof(Element));
    if constexpr (indexed) {
        device->checkResult(device->native_device->CreateIndexBuffer(bytes, D3DUSAGE_DYNAMIC,
            D3DFMT_INDEX16, D3DPOOL_DEFAULT, replacement.GetAddressOf(), nullptr), "CreateIndexBuffer");
    } else {
        constexpr DWORD fvf = std::is_same_v<Element, SphereRender::PositionNormalUvVertex>
            ? D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1
            : D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1;
        device->checkResult(device->native_device->CreateVertexBuffer(bytes, D3DUSAGE_DYNAMIC,
            fvf, D3DPOOL_DEFAULT, replacement.GetAddressOf(), nullptr), "CreateVertexBuffer");
    }
    buffer_ = std::move(replacement);
    capacity_ = count;
    position_ = 0;
}

template<class Element>
typename DynamicStream<Element>::Mapping DynamicStream<Element>::lock(std::size_t count) {
    if (!device) throw std::logic_error("Direct3D stream has no device");
    constexpr auto limit = std::numeric_limits<UINT>::max() / sizeof(Element);
    if (count > limit) throw std::length_error("Direct3D stream exceeds the API size limit");
    if (count == 0) return Mapping(*device, buffer_, position_, 0, nullptr);
    if (count > capacity_) reserve(count + std::min(count / 4, limit - count));
    else if (!buffer_) restoreResource();
    const bool discard = discard_next_ || position_ > capacity_ || count > capacity_ - position_;
    const std::size_t first = discard ? 0 : position_;
    void* data = nullptr;
    device->checkResult(buffer_->Lock(0, 0, &data, discard ? D3DLOCK_DISCARD : D3DLOCK_NOOVERWRITE),
        indexed ? "IndexBuffer::Lock" : "VertexBuffer::Lock");
    if (!data) {
        buffer_->Unlock();
        throw std::runtime_error("Direct3D returned an empty mapping");
    }
    position_ = first + count;
    discard_next_ = false;
    return Mapping(*device, buffer_, first, count, static_cast<Element*>(data) + first);
}

template<class Element>
void DynamicStream<Element>::releaseResource() {
    buffer_.Reset();
    position_ = 0;
    discard_next_ = true;
}

template<class Element>
void DynamicStream<Element>::restoreResource() { reserve(capacity_); }

template class DynamicStream<SphereRender::PositionNormalUvVertex>;
template class DynamicStream<SphereRender::PositionColorUvVertex>;
template class DynamicStream<std::uint16_t>;

void SferaLightRuntime::invalidateActiveLights() {
    active_lights.fill(false);
    active_count = 0;
}

void SferaLightRuntime::disableActiveLights() {
    for (std::uint32_t index = 1; index < active_lights.size(); ++index) setActive(index, false, __LINE__);
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
    device.initialize(SferaClientApplication::main_window, display_width, display_height, g_sfera_graphics_runtime.display_depth_bits, SferaClientApplication::windowed);
    if (device.supports_post_effects) {
        device.post_effects = std::make_unique<CPostEffectsMgr>(device);
        device.post_effects->setEnabled(true);
    }
    g_sfera_textures.initialize();
    g_sfera_textures.addFolder("landscape\\");
    if (TerrainAssets::high_resolution_assets) g_sfera_textures.addFolder("landscape_hr\\");
    if (TerrainAssets::alternate_ph_assets) g_sfera_textures.addFolder("landscape_ph\\");
    if (TerrainAssets::alternate_rd_assets) g_sfera_textures.addFolder("landscape_rd\\");
    g_sfera_textures.addFolder("models\\textures\\");
    if (TerrainAssets::high_resolution_assets) g_sfera_textures.addFolder("models_hr\\textures\\");
    if (TerrainAssets::alternate_ph_assets) g_sfera_textures.addFolder("models_ph\\textures\\");
    if (TerrainAssets::alternate_rd_assets) g_sfera_textures.addFolder("models_rd\\textures\\");
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
    device.checkResult(device.native_device->SetRenderState(D3DRS_FOGSTART, SferaBinary::floatBits(50.0f)), "SetRenderState(FOGSTART)");
    device.checkResult(device.native_device->SetRenderState(D3DRS_FOGEND, SferaBinary::floatBits(100.0f)), "SetRenderState(FOGEND)");
    device.model_vertices.reserve(30000);
    device.colored_vertices.reserve(30000);
    device.indices_primary.reserve(5000);
    device.indices_secondary.reserve(5000);
    device.last_hresult = device.native_device->CreateQuery(D3DQUERYTYPE_EVENT, device.sync_query.ReleaseAndGetAddressOf());
    if (device.last_hresult != S_OK) {
        g_sfera_log_runtime.write("Render err: cant create query:");
        g_sfera_log_runtime.write(SferaNumeric::signedWord(device.last_hresult));
    }
    device.checkResult(device.native_device->Clear(0u, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0u), "Clear");
    initializeWater();
    device.shaders = std::make_unique<CShaderMgr>(device, "Shaders\\Vertex\\", "Shaders\\Pixel\\");
}

WorldObject* WorldObjects::effectObject(std::uint32_t handle) const {
    return handle < object_handles.size() ? object_handles[handle].get() : nullptr;
}
SferaVec3F WorldObjects::referencePosition() const { return objectPosition(1u); }
SferaVec3F WorldObjects::objectPosition(std::uint32_t handle) const {
    auto* object = effectObject(handle);
    if (object == nullptr) object = effectObject(1u);
    return object == nullptr ? SferaVec3F{} : object->position;
}
bool WorldObjects::attachEffect(std::uint32_t handle, SferaActiveEffect& item) {
    auto* object = effectObject(handle);
    if (!object || clearing || destroying_handles.contains(handle)) return false;
    for (auto& effect : object->attached_effects) if (!effect) { effect = &item; return true; }
    return false;
}
void WorldObjects::detachEffect(std::uint32_t handle, SferaActiveEffect& item) {
    auto* object = effectObject(handle);
    if (!object) return;
    for (auto& effect : object->attached_effects) if (effect == &item) { effect = nullptr; return; }
}
SferaActiveEffect* WorldObjects::firstEffect(std::uint32_t handle) const { const auto* object = effectObject(handle); return object ? object->attached_effects[0] : nullptr; }
SferaEffectFrames WorldObjects::buildEffectFrames(std::uint32_t handle) const {
    SferaEffectFrames frames;
    auto* object = effectObject(handle);
    frames.positions[0] = objectPosition(handle);
    if (object != nullptr && object->extended()) {
        const auto* extended = object->extended();
        frames.positions[1] = extended->effect_frame_position_a; frames.positions[2] = extended->effect_frame_position_b; frames.positions[4] = extended->effect_frame_position_c;
        frames.transforms[1] = extended->effect_frame_transform_a; frames.transforms[2] = extended->effect_frame_transform_b; frames.transforms[4] = extended->effect_frame_transform_c;
    } else {
        const SferaVec3F attachment = object != nullptr ? object->position : referencePosition();
        frames.positions[1] = attachment; frames.positions[2] = attachment; frames.positions[4] = attachment;
        for (auto index : {1u, 2u, 4u}) frames.transforms[index] = SferaMatrix4x4F::identity();
    }
    frames.positions[3] = {(frames.positions[1].x + frames.positions[2].x) * 0.5f, (frames.positions[1].y + frames.positions[2].y) * 0.5f, (frames.positions[1].z + frames.positions[2].z) * 0.5f};
    const auto rotation = object != nullptr ? SferaVec3F{object->rotation.x, object->rotation.y, object->rotation.z} : SferaVec3F{};
    const auto orientation = SferaMatrix4x4F::fromEuler({}, rotation);
    frames.transforms[0] = orientation;
    // Between-hands transform remains zero, matching the existing attachment convention.
    return frames;
}

namespace {
bool worldSamePoint(const SferaVec3F& first, const SferaVec3F& second) { return first.x == second.x && first.y == second.y && first.z == second.z; }
SferaVec3F worldRotateVector(SferaVec3F value, const SferaVec3F& rotation) { SferaVec3F::rotatePair(value.x, value.z, rotation.x); SferaVec3F::rotatePair(value.z, value.y, rotation.y); SferaVec3F::rotatePair(value.x, value.y, rotation.z); return value; }
SferaVec3F worldAnglesFromBasis(SferaVec3F forward, SferaVec3F up) {
    return SferaMath::anglesFromBasis(forward, up);
}
int worldAngleDifference(float target, float current) {
    const auto encode = [](float value) -> int {
        return SferaNumeric::truncateInt(value * 10430.37835) & 65535;
    };
    const int destination = encode(target), source = encode(current);
    int difference = destination - source;
    if (std::abs(difference) >= 32768) difference = ((destination + 32768) & 65535) - ((source + 32768) & 65535);
    return difference;
}
}

SferaVec3F SferaVec3F::normalized(std::size_t diagnosticCode) const {
    const float magnitude = length();
    if (magnitude < 9.999999747378752e-6f) {
        if (diagnosticCode == 0) return {};
        WorldDiagnostics::fail((std::string("normalize: normal with extra short length found. Code:") + std::to_string(diagnosticCode)));
    }
    return *this * (1.0 / magnitude);
}

void WorldDiagnostics::report(std::string_view message) { SphereUI::InterfaceRenderer::reportError(message); }
[[noreturn]] void WorldDiagnostics::fail(std::string_view message) { report(message); throw std::runtime_error(std::string(message.empty() ? std::string_view{"World operation failed"} : message)); }
void WorldDiagnostics::warning(std::string_view message) {
    ::OutputDebugStringA(std::string(message).c_str());
    ::OutputDebugStringA("\n");
}

WorldObject* WorldObjects::object(std::uint32_t handle, std::optional<std::string_view> operation) const {
    auto* result = handle < object_handles.size() ? object_handles[handle].get() : nullptr;
    if (result == nullptr && operation) {
        WorldDiagnostics::message = std::format("{}: wrong handle", *operation);
        WorldDiagnostics::flushScriptContext();
    }
    return result;
}
ExtendedWorldObject* WorldObjects::extendedObject(std::uint32_t handle) const {
    auto* result = object(handle);
    if (result == nullptr) return nullptr;
    if (!result->extended()) WorldDiagnostics::fail("Try to get extended from superstatic");
    return result->extended();
}
WorldObject* WorldObjects::controlledObject() const {
    if (clearing || destroying_handles.contains(controlled_object_handle)) return nullptr;
    return object(controlled_object_handle);
}
SphereRender::Model* WorldObjects::model(const WorldObject& object) const {
    if (const auto* reference = std::get_if<WorldObject::ModelReference>(&object.model_source)) {
        if (reference->asset == nullptr) reference->asset = g_sfera_models.model(reference->id);
        return reference->asset.get();
    }
    return std::get<std::unique_ptr<SphereRender::Model>>(object.model_source).get();
}
std::uint32_t WorldObjects::create(std::string_view name, SferaMbcProcessRecord* process, std::uint32_t kind, bool dynamic) {
    if (clearing) return UINT32_MAX;
    const auto modelHandle = g_sfera_models.find(name);
    if (modelHandle == SphereRender::ModelRepository::invalid_index) {
        WorldDiagnostics::warning(std::format("CreateObject: no model with such name: {}", name));
        return UINT32_MAX;
    }
    auto handle = next_object_handle;
    while (handle < object_handles.size() && object(handle) != nullptr) ++handle;
    if (handle >= object_handles.size()) WorldDiagnostics::fail("CreateObject: object handle table is full");
    std::unique_ptr<WorldObject> created;
    if (dynamic) created = std::make_unique<ExtendedWorldObject>();
    else created = std::make_unique<WorldObject>();
    created->model_source = WorldObject::ModelReference{modelHandle, {}};
    created->render_group = kind;
    created->visible = true;
    created->render_fade = -1.0f;
    created->grid_min_x = 1000000;
    if (auto* extended = created->extended()) {
        extended->scale = 1.0f;
        extended->render_enabled = true;
        extended->airborne = true;
        extended->process_handle = process;
        extended->last_simulation_tick = g_sfera_mbc_runtime.simulation_tick;
    }
    object_handles[handle] = std::move(created);
    try {
        if (dynamic) {
            if (kind != 0u) addExtended(handle);
            recalculateBasis(handle);
        } else updateSpatialIndex(handle);
    } catch (...) {
        if (dynamic) removeExtended(handle);
        object_handles[handle].reset();
        throw;
    }
    if (SferaText::asciiEqual(name, "crt04")) object(handle)->render_group = 5u;
    if (max_occupied_object_handle == UINT32_MAX || handle > max_occupied_object_handle) max_occupied_object_handle = handle;
    next_object_handle = handle + 1u;
    return handle;
}

void WorldObjects::recalculateBasis(std::uint32_t handle) {
    auto* item = extendedObject(handle);
    if (item == nullptr) { WorldDiagnostics::warning("recalk_orts: wrong handle"); return; }
    if (worldSamePoint(item->previous_basis_rotation, item->rotation)) return;
    item->previous_basis_rotation = item->rotation;
    item->orientation_basis[0] = worldRotateVector({0.0f, 0.0f, 1.0f}, item->rotation);
    item->orientation_basis[1] = worldRotateVector({0.0f, -1.0f, 0.0f}, item->rotation);
    item->orientation_basis[2] = item->orientation_basis[0].cross(item->orientation_basis[1]);
}
void WorldObjects::rotate(std::uint32_t handle, const SferaVec3F& delta) {
    auto* item = extendedObject(handle);
    if (item == nullptr) { WorldDiagnostics::warning("rotate_object: wrong handle"); return; }
    item->orientation_basis[0] = worldRotateVector(worldRotateVector({0.0f, 0.0f, 1.0f}, delta), item->rotation);
    item->orientation_basis[1] = worldRotateVector(worldRotateVector({0.0f, -1.0f, 0.0f}, delta), item->rotation);
    item->orientation_basis[2] = item->orientation_basis[0].cross(item->orientation_basis[1]);
    item->rotation = worldAnglesFromBasis(item->orientation_basis[0], item->orientation_basis[1]);
}
void WorldObjects::moveLocal(std::uint32_t handle, const SferaVec3F& displacement) {
    auto* item = extendedObject(handle);
    if (item == nullptr) { WorldDiagnostics::warning("move_object: wrong handle"); return; }
    recalculateBasis(handle);
    SferaVec3F delta{};
    const double x = displacement.x, y = displacement.y, z = displacement.z;
    for (std::size_t axis = 0; axis < 3; ++axis)
        delta.setComponent(axis, item->orientation_basis[0].component(axis) * z - item->orientation_basis[1].component(axis) * y + item->orientation_basis[2].component(axis) * x);
    item->position = item->position + delta;
    if (handle == controlled_object_handle) { g_sfera_motion.tracked_position.x = item->position.x + 333.0f; g_sfera_motion.tracked_position.y = item->position.y + 333.0f; g_sfera_motion.tracked_position.z = item->position.z + 333.0f; }
}
void WorldObjects::alignReferenceOrientation() {
    auto* item = extendedObject(0u);
    if (item == nullptr) return;
    recalculateBasis(0u);
    const SferaVec3F desired{SphereRender::ModelPose::scale.x, SphereRender::ModelPose::scale.y, SphereRender::ModelPose::scale.z};
    const float projection = item->orientation_basis[0].dot<double, true>(desired);
    const float alignment = std::abs(projection);
    if (alignment > 0.985) return;
    const float speed = (1.100000023841858 - alignment) * 8.000000093488779e-7;
    const SferaVec3F tangent = item->orientation_basis[0].cross(desired);
    const SferaVec3F up = item->orientation_basis[0].cross(tangent);
    const SferaVec3F target = worldAnglesFromBasis(item->orientation_basis[0], up);
    const std::array<int, 3> difference{worldAngleDifference(target.x, item->rotation.x), worldAngleDifference(target.y, item->rotation.y), worldAngleDifference(target.z, item->rotation.z)};
    if (std::all_of(difference.begin(), difference.end(), [](int value) { return std::abs(value) <= 100; })) return;
    const double rotation_speed = speed;
    for (std::size_t axis = 0; axis < difference.size(); ++axis)
        item->rotation.setComponent(axis, item->rotation.component(axis) + difference[axis] * rotation_speed);
}
void WorldObjects::reflectReferenceOrientation() {
    auto* item = extendedObject(1u);
    if (item == nullptr) return;
    item->orientation_basis[0].y = -item->orientation_basis[0].y;
    item->orientation_basis[1] = item->orientation_basis[2].cross(item->orientation_basis[0]);
    item->rotation = worldAnglesFromBasis(item->orientation_basis[0], item->orientation_basis[1]);
    item->previous_basis_rotation = item->rotation;
}
void WorldObjects::removeSpatialIndex(std::uint32_t handle) {
    auto* item = object(handle);
    if (item == nullptr || item->grid_min_x == 1000000) return;

    for (int x = item->grid_min_x; x <= item->grid_max_x; ++x) for (int z = item->grid_min_y; z <= item->grid_max_y; ++z) g_sfera_world_spatial.remove(handle, x, z);
}
void WorldObjects::updateSpatialIndex(std::uint32_t handle) {
    auto* item = object(handle);
    if (item == nullptr) return;
    auto* extended = item->extended();
    if (extended && worldSamePoint(extended->previous_spatial_position, item->position) && worldSamePoint(extended->previous_spatial_rotation, item->rotation)) return;
    const auto rememberPosition = [&] {
        if (extended) { extended->previous_spatial_position = item->position; extended->previous_spatial_rotation = item->rotation; }
    };
    SphereWorld::ContactQuery::updateBounds(handle);
    const auto lower = [](float coordinate) { return SferaNumeric::truncateInt((coordinate - 2.0) * 0.11999999731779099 + 100000.0) - 100000; };
    const auto upper = [](float coordinate) { return SferaNumeric::truncateInt((coordinate + 2.0) * 0.11999999731779099 + 100000.0) - 100000; };
    const int minX = lower(item->bounds_minimum.x), minZ = lower(item->bounds_minimum.z), maxX = upper(item->bounds_maximum.x), maxZ = upper(item->bounds_maximum.z);
    const bool registered = item->grid_min_x != 1000000;
    if (registered && item->grid_min_x == minX && item->grid_min_y == minZ && item->grid_max_x == maxX && item->grid_max_y == maxZ) { rememberPosition(); return; }
    const auto wasCovered = [&](int x, int z) {
        return registered && x >= item->grid_min_x && x <= item->grid_max_x && z >= item->grid_min_y && z <= item->grid_max_y;
    };
    int insertedX = minX, insertedZ = minZ;
    try {
        for (; insertedX <= maxX; ++insertedX) {
            for (insertedZ = minZ; insertedZ <= maxZ; ++insertedZ) {
                if (!wasCovered(insertedX, insertedZ)) g_sfera_world_spatial.insert(handle, insertedX, insertedZ);
            }
        }
    } catch (...) {
        for (int x = minX; x <= insertedX; ++x) {
            const int endZ = x == insertedX ? insertedZ - 1 : maxZ;
            for (int z = minZ; z <= endZ; ++z) if (!wasCovered(x, z)) g_sfera_world_spatial.remove(handle, x, z);
        }
        throw;
    }
    if (registered) {
        for (int x = item->grid_min_x; x <= item->grid_max_x; ++x) {
            for (int z = item->grid_min_y; z <= item->grid_max_y; ++z) {
                if (x < minX || x > maxX || z < minZ || z > maxZ) g_sfera_world_spatial.remove(handle, x, z);
            }
        }
    }
    // Reinsert overlapping membership in the same order as the former remove/insert pass.
    for (int x = minX; x <= maxX; ++x) for (int z = minZ; z <= maxZ; ++z) if (wasCovered(x, z)) g_sfera_world_spatial.insert(handle, x, z);
    rememberPosition();
    item->grid_min_x = minX; item->grid_max_x = maxX; item->grid_min_y = minZ; item->grid_max_y = maxZ;
}
void WorldObjects::updateExtendedSpatialIndices() {
    auto remaining = extended_object_count;
    const auto* handles = extended_object_handles.data();
    for (std::size_t index = 0u; index < extended_object_handles.size() && remaining != 0u; ++index) {
        if (handles[index] == 0u) continue;
        const auto handle = handles[index]; --remaining;
        const auto* item = extendedObject(handle);
        if (item != nullptr && item->render_enabled && item->parent_object_handle == 0u) updateSpatialIndex(handle);
    }
}

void SferaMbcProcessRecord::appendCommand(std::string_view command) {
    // The leading CRLF and conservative 127-byte command limit are part of ReadCommands.
    if (command.size() > 123u || physics_commands.size() > 123u - command.size()) return;
    physics_commands += "\r\n";
    physics_commands.append(command);
}
void WorldObjects::appendCommand(std::uint32_t handle, std::string_view command) { if (auto* item = extendedObject(handle); item != nullptr && item->process_handle != nullptr) item->process_handle->appendCommand(command); }
bool WorldObjects::actorActive(std::uint32_t handle) const {
    (void)extendedObject(handle);
    return false; // This executable has no subscriber producer.
}
void WorldObjects::activateTrap(const WorldObject& obstacle) {
    const auto* resource = model(obstacle);
    const auto now = WorldClock::nowTicks();
    if (resource == nullptr || now - g_sfera_world_objects.material_refresh_tick <= 10000u) return;
    const std::string_view name(resource->name), pattern("trap");
    if (std::search(name.begin(), name.end(), pattern.begin(), pattern.end(), [](std::uint8_t first, std::uint8_t second) { return std::tolower(first) == std::tolower(second); }) == name.end()) return;
    if (auto* controlled = extendedObject(controlled_object_handle); controlled != nullptr && controlled->process_handle != nullptr) {
        for (auto* effect : obstacle.attached_effects) if (effect) {
            const auto id = effect == nullptr ? 0u : effect->listener_key;
            appendCommand(controlled_object_handle, (std::string("trap ") + std::to_string(id))); break;
        }
    }
    g_sfera_world_objects.material_refresh_tick = now;
}

std::uint64_t WorldClock::microseconds() noexcept {
    using Clock = std::chrono::steady_clock;
    static const auto epoch = Clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() - epoch).count();
}
std::uint32_t WorldClock::calendarTicks() { return SferaGameCalendar::ticks(g_sfera_mbc_runtime.game_calendar); }

std::uint32_t SferaGameCalendar::ticks(std::uint32_t calendar) {
    const auto days = (component(calendar, Year) - firstYear) * daysPerYear + daysBeforeMonth(component(calendar, Month)) + component(calendar, Day);
    const auto hours = days * hoursPerDay + component(calendar, Hour);
    const auto minutes = hours * minutesPerHour + component(calendar, Minute);
    return minutes * quartersPerMinute + component(calendar, Quarter);
}

void SferaLightRuntime::setActive(std::uint32_t index, bool enabled, std::uint32_t sourceLine) {
    if (index >= active_lights.size()) WorldDiagnostics::fail("Light slot is outside the device light table");
    auto& active = active_lights[index];
    if (active == enabled) return;
    if (enabled && active_count >= 8) WorldDiagnostics::fail((std::string("ActivateLight: num of active lights > 8. Source line = ") + std::to_string(sourceLine)));
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    device.checkResult(device.native_device->LightEnable(index, enabled), "LightEnable");
    if (enabled && index != 0u && g_sfera_effect_manager.diagnostics.enabled)
        ++g_sfera_effect_manager.diagnostics.light_activations;
    active = enabled;
    if (enabled) ++active_count; else --active_count;
}
void SferaLightRuntime::activateMask(std::uint32_t mask) {
    for (std::uint32_t index = 1u; index <= 30u; ++index) if ((mask & (1u << (index - 1u))) == 0u) setActive(index, false, 15290u);
    for (std::uint32_t index = 1u; index <= 30u; ++index) if ((mask & (1u << (index - 1u))) != 0u) setActive(index, true, 15290u);
}
void SferaLightRuntime::setDirectionalLight(const SferaVec3F& direction, const SferaVec3F& color) {
    D3DLIGHT9 light{};
    light.Type = D3DLIGHT_DIRECTIONAL;
    light.Diffuse.r = color.x / 255.0;
    light.Diffuse.g = color.y / 255.0;
    light.Diffuse.b = color.z / 255.0;
    light.Diffuse.a = 1.0f;
    light.Specular = {1.0f, 1.0f, 1.0f, 1.0f}; light.Ambient.a = 1.0f;
    light.Direction = {direction.x, direction.y, direction.z}; light.Falloff = 1.0f; light.Attenuation0 = 1.0f; light.Attenuation1 = 1.0f; light.Attenuation2 = 1.0f;
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    device.checkResult(device.native_device->SetLight(0u, &light), "SetLight");
    setActive(0u, true, 14675u);
}

namespace {
struct TerrainGroupBuilder {
    std::vector<TerrainVertex> vertices;
    std::vector<std::uint16_t> indices;
    std::array<TerrainSurfaceGroup, 144> groups;
    void append(const TerrainPatch& patch, const TerrainCell& cell) {
        if (cell.x < 0 || cell.x >= 12 || cell.z < 0 || cell.z >= 12) throw std::runtime_error("Invalid terrain surface cell");
        std::unordered_map<std::uint16_t, std::uint16_t> remap;
        const auto firstVertex = vertices.size(); const auto firstIndex = indices.size();
        for (std::size_t i = 0; i < cell.triangles.size(); ++i) for (auto index : cell.triangles[i].indices) {
            if (index >= patch.vertices.size()) throw std::runtime_error("Terrain triangle vertex is outside the vertex array");
            auto [entry, inserted] = remap.emplace(index, SferaNumeric::lowHalf(SferaNumeric::lowWord(remap.size())));
            if (inserted) vertices.push_back(patch.vertices[index]);
            indices.push_back(entry->second);
        }
        auto& group = groups[cell.x + 12 * cell.z]; group.vertexCount = remap.size(); group.firstVertex = firstVertex; group.firstIndex = firstIndex;
    }
};
std::vector<std::uint8_t> terrainReadFile(const std::string& path, bool optional = false) {
    if (optional) {
        const bool previous = g_sfera_files.setErrorReporting(false);
        std::int64_t size;
        try { size = g_sfera_files.fileSize(path); }
        catch (...) { g_sfera_files.setErrorReporting(previous); throw; }
        g_sfera_files.setErrorReporting(previous);
        if (size < 0) return {};
    }
    return g_sfera_files.readAll(path);
}

void terrainSmoothNormals(const std::vector<TerrainVertex*>& vertices) {
    std::vector<bool> used(vertices.size());
    for (std::size_t i = 0; i < vertices.size(); ++i) {
        if (used[i]) continue;
        std::vector<std::size_t> group{i}; auto sum = vertices[i]->normal; used[i] = true;
        for (std::size_t j = i + 1; j < vertices.size(); ++j) {
            if (used[j]) continue;
            const auto& a = vertices[i]->position; const auto& b = vertices[j]->position;
            const float compatibility = a.dot<double, true>(b);
            if (compatibility < 0.0f) continue;
            used[j] = true; group.push_back(j); sum.x += vertices[j]->normal.x; sum.y += vertices[j]->normal.y; sum.z += vertices[j]->normal.z;
        }
        const float length = sum.length<double, float, true>(); const float inverse = 1.0f / length;
        sum.x *= inverse; sum.y *= inverse; sum.z *= inverse;
        for (auto index : group) vertices[index]->normal = sum;
    }
}
}
void TerrainBounds::lowerMinimum(float height) { if (corners[2].y <= height) return; for (int index : {2, 3, 6, 7}) corners[index].y = height; scaledBounds[2] = std::trunc(height * 1024.0); }
void TerrainPatch::updateBounds() { for (int group = 0; group < 16; ++group) for (int cell = 0; cell < 9; ++cell) groupBounds[group].lowerMinimum(cellBounds[group * 9 + cell].corners[2].y); for (int quarter = 0; quarter < 4; ++quarter) for (int group = 0; group < 4; ++group) quarterBounds[quarter].lowerMinimum(groupBounds[quarter * 4 + group].corners[2].y); for (const auto& quarter : quarterBounds) bounds.lowerMinimum(quarter.corners[2].y); }
void TerrainPatch::partitionEdges() {
    if (vertices.size() > 65536u) throw std::runtime_error("Invalid landscape vertex count");
    std::vector<bool> membership(vertices.size());
    const auto Near = [](float value, float boundary) { return value > boundary - 0.01f && value < boundary + 0.01f; };
    for (std::size_t corner = 0; corner < 4; ++corner) {
        std::vector<std::size_t> indices; const float x = corner % 2 ? 100.0f : 0.0f; const float z = corner < 2 ? 100.0f : 0.0f;
        for (std::size_t i = 0; i < vertices.size(); ++i) if (Near(vertices[i].position.x, x) && Near(vertices[i].position.z, z)) { indices.push_back(i); membership[i] = true; }
        cornerIndices[corner] = std::move(indices);
    }
    for (std::size_t side = 0; side < 4; ++side) {
        struct Group { float coordinate; std::vector<std::size_t> indices; }; std::vector<Group> groups;
        const bool horizontal = side < 2; const float boundary = side == 0 || side == 3 ? 100.0f : 0.0f;
        for (std::size_t i = 0; i < vertices.size(); ++i) {
            const auto& position = vertices[i].position; if (membership[i] || !Near(horizontal ? position.z : position.x, boundary)) continue;
            membership[i] = true; Group group{horizontal ? position.x : position.z, {i}};
            for (std::size_t j = i + 1; j < vertices.size(); ++j) { const auto& candidate = vertices[j].position; if (membership[j] || candidate.x != position.x || candidate.y != position.y || candidate.z != position.z) continue; membership[j] = true; group.indices.push_back(j); }
            groups.push_back(std::move(group));
        }
        SferaAlgorithms::stableSort(groups, [](const auto& group) { return group.coordinate; });
        auto& edge = edgeGroups[side]; edge.clear(); edge.reserve(groups.size());
        for (auto& group : groups) edge.push_back(std::move(group.indices));
    }
}
void TerrainPatch::rebuildSurfaceGroups() {
    TerrainGroupBuilder builder{{}, {}, surfaceGroups};
    for (const auto& cell : cells) builder.append(*this, cell);
    surfaceGroups = builder.groups;
    groupedVertices = std::move(builder.vertices);
    groupedIndices = std::move(builder.indices);
}
bool TerrainPatch::validateEdge(const TerrainPatch& other, std::size_t side, std::size_t otherSide) const {
    const auto& first = edgeGroups.at(side); const auto& second = other.edgeGroups.at(otherSide); std::vector<bool> matched(second.size()); bool valid = true;
    for (const auto& group : first) { const auto& point = vertices[group.front()].position; bool found = false; for (std::size_t i = 0; i < second.size(); ++i) { const auto& candidate = other.vertices[second[i].front()].position; if (candidate.y == point.y && (side < 2 ? candidate.x == point.x : candidate.z == point.z)) { matched[i] = true; found = true; break; } } if (!found) valid = false; }
    for (std::size_t i = 0; i < second.size(); ++i) if (!matched[i]) { valid = false; }
    return valid;
}
bool TerrainPatch::smoothEdge(TerrainPatch& other, std::size_t side, std::size_t otherSide) { if (!validateEdge(other, side, otherSide)) return false; const auto& first = edgeGroups.at(side); const auto& second = other.edgeGroups.at(otherSide); if (first.size() != second.size()) throw std::runtime_error("Error of smoothing region's edge: numbers of vertex groups are differ"); for (std::size_t i = 0; i < first.size(); ++i) { std::vector<TerrainVertex*> group; for (auto index : first[i]) group.push_back(&vertices[index]); for (auto index : second[i]) group.push_back(&other.vertices[index]); terrainSmoothNormals(group); } return true; }
void TerrainPatch::smoothCorner(TerrainPatch* diagonal, TerrainPatch* vertical, TerrainPatch* horizontal, std::size_t corner, std::size_t diagonalCorner, std::size_t verticalCorner, std::size_t horizontalCorner) { if (!diagonal && !vertical && !horizontal) return; std::vector<TerrainVertex*> group; const auto append = [&group](TerrainPatch* patch, std::size_t index) { if (!patch) return; if (index >= 4) throw std::out_of_range("Landscape corner index"); for (const auto vertex : patch->cornerIndices[index]) { if (vertex >= patch->vertices.size()) throw std::runtime_error("Landscape corner vertex index"); group.push_back(&patch->vertices[vertex]); } }; append(this, corner); append(diagonal, diagonalCorner); append(vertical, verticalCorner); append(horizontal, horizontalCorner); terrainSmoothNormals(group); if (diagonal) diagonal->cornerSmoothed[diagonalCorner] = true; if (vertical) vertical->cornerSmoothed[verticalCorner] = true; if (horizontal) horizontal->cornerSmoothed[horizontalCorner] = true; }
TerrainPatch* TerrainRegion::patch(int row, int column) const {
    if (row < 0 || row >= rows || column < 0 || column >= columns || row >= 10 || column >= 10) return nullptr;
    return slots[row * 10 + column].patch.get();
}
void TerrainRegion::touchPatch(int row, int column) {
    if (!patch(row, column)) loadPatch(row, column);
    slots[row * 10 + column].expiry = 1000;
}
void TerrainRegion::destroyPatch(int row, int column) {
    if (row < 0 || row >= 10 || column < 0 || column >= 10) throw std::out_of_range("Landscape patch slot");
    auto& slot = slots[row * 10 + column];
    if (!slot.patch) return;
    const auto belongs = [&slot](const TerrainCell* cell) {
        return std::any_of(slot.patch->cells.begin(), slot.patch->cells.end(), [cell](const auto& item) { return &item == cell; });
    };
    g_sfera_world_spatial.forgetTerrain(*slot.patch);
    std::erase_if(g_sfera_terrain_renderer.visibleCells, [&](const auto& entry) { return belongs(entry.cell); });
    for (auto& entry : TerrainTextureCache::entries) if (belongs(entry.owner)) entry.owner = nullptr;
    slot.patch.reset();
    slot.texture.reset();
}
void TerrainAssets::evictUnused() {
    for (auto& region : regions) for (int row = 0; row < region.rows; ++row) for (int column = 0; column < region.columns; ++column) {
        if (region.patch(row, column) && --region.slots[row * 10 + column].expiry == 0) region.destroyPatch(row, column);
    }
}
void TerrainAssets::releaseAll() {
    for (auto& region : regions) for (int row = 0; row < region.rows; ++row) for (int column = 0; column < region.columns; ++column) region.destroyPatch(row, column);
    microtextures.clear();
    microtexture_remap.fill(std::numeric_limits<std::uint16_t>::max());
    g_sfera_graphics_runtime.base_microtexture_id = UINT16_MAX;
}
namespace {
struct TerrainPatchFile {
    struct Cell { int x; int z; int triangleCount; std::uint16_t baseMicrotexture; int layerCount; std::uint16_t layers[10]; };
    static constexpr std::size_t encodedBoundsSize = 8 * 3 * 4 + 6 * 4;
    static constexpr std::size_t encodedSize = 12 + 144 * 48 + 5 * 4 + (1 + 4 + 16 + 144) * encodedBoundsSize + 4 + 4 * 4 * 4 + 4;
    std::uint32_t format;
    std::uint32_t vertexCount;
    Cell cells[144];
    TerrainBounds bounds;
    TerrainBounds quarterBounds[4];
    TerrainBounds groupBounds[16];
    TerrainBounds cellBounds[144];
    std::uint32_t flags;
    std::uint8_t cornerSmoothed[4];
    static TerrainPatchFile decode(std::span<const std::uint8_t> bytes) {
        if (bytes.size() != encodedSize) throw std::runtime_error("Invalid landscape header size");
        SferaBinary::Reader reader(bytes);
        const auto bounds = [&reader](TerrainBounds& output) { for (auto& corner : output.corners) { corner.x = reader.read<float>(); corner.y = reader.read<float>(); corner.z = reader.read<float>(); } for (auto& value : output.scaledBounds) value = reader.read<int>(); };
        TerrainPatchFile result{};
        result.format = reader.read<std::uint32_t>();
        result.vertexCount = reader.read<std::uint32_t>();
        reader.take(4); // Stored runtime references belong to the file format, not to the in-memory objects.
        for (auto& cell : result.cells) {
            cell.x = reader.read<int>(); cell.z = reader.read<int>(); cell.triangleCount = reader.read<int>();
            reader.take(4);
            cell.baseMicrotexture = reader.read<std::uint16_t>();
            reader.take(2);
            cell.layerCount = reader.read<int>();
            for (auto& layer : cell.layers) layer = reader.read<std::uint16_t>();
            reader.take(4);
        }
        reader.take(5 * 4);
        bounds(result.bounds);
        for (auto& item : result.quarterBounds) bounds(item);
        for (auto& item : result.groupBounds) bounds(item);
        for (auto& item : result.cellBounds) bounds(item);
        result.flags = reader.read<std::uint32_t>();
        reader.take(2 * 4 * 4);
        const auto smoothed = reader.take(4);
        std::copy(smoothed.begin(), smoothed.end(), result.cornerSmoothed);
        reader.take(2 * 4 * 4);
        return result;
    }
};
}
void TerrainPatch::readGeometry(std::span<const std::uint8_t> bytes, std::span<const std::uint8_t> masks, std::span<const std::uint8_t> waterData, std::span<const std::uint16_t, 65536> microtextureRemap, std::uint16_t baseMicrotexture) {
    SferaBinary::Reader reader(bytes);
    const auto header = TerrainPatchFile::decode(reader.take(TerrainPatchFile::encodedSize));
    if (header.vertexCount > 65536u) throw std::runtime_error("Landscape has too many vertices");
    std::size_t maskOffset = 0;
    std::bitset<144> coordinates;
    for (const auto& cell : header.cells) {
        if (cell.x < 0 || cell.x >= 12 || cell.z < 0 || cell.z >= 12 || cell.triangleCount < 0 || cell.triangleCount > 1000000 || cell.layerCount < 0 || cell.layerCount > 10) throw std::runtime_error("Invalid landscape cell header");
        const auto coordinate = cell.x + cell.z * 12;
        if (coordinates.test(coordinate)) throw std::runtime_error("Duplicate landscape cell coordinates");
        coordinates.set(coordinate);
        const auto maskBytes = cell.layerCount * 576;
        if (maskOffset >= masks.size() || masks[maskOffset] != cell.layerCount || maskBytes > masks.size() - maskOffset - 1) throw std::runtime_error("Number of layer masks is not the same in lnd and msk");
        maskOffset += maskBytes + 1;
    }
    if (!waterData.empty() && waterData.size() != 144 * 8) throw std::runtime_error("Invalid landscape water data");

    TerrainPatch loaded;
    SferaBinary::Reader vertexReader(reader.take(header.vertexCount * 40u));
    loaded.vertices.resize(header.vertexCount);
    const auto real = [](SferaBinary::Reader& input) {
        const auto value = input.read<float>();
        if (!std::isfinite(value)) throw std::runtime_error("Non-finite landscape geometry");
        return value;
    };
    const auto vector = [&](SferaBinary::Reader& input) { return SferaVec3F{real(input), real(input), real(input)}; };
    for (auto& vertex : loaded.vertices) {
        vertex.position = vector(vertexReader);
        vertex.normal = vector(vertexReader);
        vertex.textureU = real(vertexReader);
        vertex.textureV = real(vertexReader);
        vertex.detailU = real(vertexReader);
        vertex.detailV = real(vertexReader);
    }
    loaded.waters.fill({1000.0f, 0u});
    if (!waterData.empty()) {
        SferaBinary::Reader waterReader(waterData);
        for (auto& water : loaded.waters) {
            water = {waterReader.read<float>(), waterReader.read<std::uint32_t>()};
            if (water.material >= g_sfera_graphics_runtime.water_materials.size() || (water.material != 0 && !std::isfinite(water.height))) throw std::runtime_error("Invalid landscape water material or height");
        }
    }
    loaded.bounds = header.bounds;
    std::copy_n(header.quarterBounds, 4, loaded.quarterBounds.begin());
    std::copy_n(header.groupBounds, 16, loaded.groupBounds.begin());
    std::copy_n(header.cellBounds, 144, loaded.cellBounds.begin());
    loaded.flags = header.flags;
    std::copy_n(header.cornerSmoothed, 4, loaded.cornerSmoothed.begin());
    const auto remap = [microtextureRemap](std::uint16_t code) {
        if (microtextureRemap[code] == std::numeric_limits<std::uint16_t>::max()) throw std::runtime_error("Landscape references an unknown microtexture");
        return microtextureRemap[code];
    };
    maskOffset = 0;
    for (std::size_t i = 0; i < loaded.cells.size(); ++i) {
        const auto& source = header.cells[i];
        auto& cell = loaded.cells[i];
        cell.x = source.x;
        cell.z = source.z;
        SferaBinary::Reader triangleReader(reader.take(source.triangleCount * 28u));
        cell.triangles.resize(source.triangleCount);
        for (auto& triangle : cell.triangles) {
            for (auto& index : triangle.indices) {
                index = triangleReader.read<std::uint16_t>();
                if (index >= loaded.vertices.size()) throw std::runtime_error("Landscape triangle vertex is outside the vertex array");
            }
            triangle.material = triangleReader.read<std::uint16_t>();
            for (auto& attribute : triangle.attributes) attribute = triangleReader.read<std::uint32_t>();
            triangle.normal = vector(triangleReader);
        }
        const auto& water = loaded.waters[cell.x + 12 * cell.z];
        if (water.material) loaded.cellBounds[i].lowerMinimum(water.height);
        cell.baseMicrotexture = source.baseMicrotexture ? remap(source.baseMicrotexture) : baseMicrotexture;
        cell.layers.reserve(source.layerCount);
        for (int layer = 0; layer < source.layerCount; ++layer) cell.layers.push_back(remap(source.layers[layer]));
        const auto maskBytes = cell.layers.size() * 576;
        const auto cellMasks = masks.subspan(maskOffset + 1, maskBytes);
        cell.masks.assign(cellMasks.begin(), cellMasks.end());
        maskOffset += maskBytes + 1;
    }
    loaded.updateBounds();
    loaded.partitionEdges();
    *this = std::move(loaded);
}

std::unique_ptr<TerrainTextureImage> TerrainTextureImage::decode(std::span<const std::uint8_t> bytes) {
    SferaBinary::Reader reader(bytes);
    const auto metadata = reader.take(32u);
    SferaBinary::Reader pixels(reader.take(width * height * 2u));
    auto image = std::make_unique<TerrainTextureImage>();
    std::copy(metadata.begin(), metadata.end(), image->metadata.begin());
    for (auto& pixel : image->pixels) pixel = pixels.read<std::uint16_t>();
    return image;
}
namespace {
void smoothTerrainNeighborhood(TerrainPatch& current, const std::array<TerrainPatch*, 8>& neighbors, const std::string& name) {
    std::array<TerrainPatch*, 9> destinations;
    std::copy(neighbors.begin(), neighbors.end(), destinations.begin());
    destinations.back() = &current;
    std::array<std::unique_ptr<TerrainPatch>, 9> staged;
    for (std::size_t index = 0; index < staged.size(); ++index) {
        if (destinations[index]) staged[index] = std::make_unique<TerrainPatch>(*destinations[index]);
    }
    auto& patch = *staged.back();
    const auto smooth = [&](std::size_t neighbor, std::size_t side, std::size_t otherSide) {
        return !staged[neighbor] || patch.smoothEdge(*staged[neighbor], side, otherSide);
    };
    bool valid = smooth(5, 1, 0);
    valid = smooth(4, 0, 1) && valid;
    valid = smooth(7, 3, 2) && valid;
    valid = smooth(6, 2, 3) && valid;
    if (!valid) WorldDiagnostics::fail(("Smooth error in " + name + "! Look at lndbug.tga"));
    constexpr std::array<std::array<std::size_t, 6>, 4> corners{{{3, 4, 6, 3, 2, 1}, {2, 4, 7, 2, 3, 0}, {0, 5, 6, 1, 0, 3}, {1, 5, 7, 0, 1, 2}}};
    for (std::size_t index = 0; index < corners.size(); ++index) {
        if (patch.cornerSmoothed[index]) continue;
        const auto& corner = corners[index];
        patch.smoothCorner(staged[corner[0]].get(), staged[corner[1]].get(), staged[corner[2]].get(), index, corner[3], corner[4], corner[5]);
    }
    patch.rebuildSurfaceGroups();
    for (std::size_t index = 0; index < neighbors.size(); ++index) if (staged[index]) staged[index]->rebuildSurfaceGroups();
    for (std::size_t index = 0; index < staged.size(); ++index) {
        if (!staged[index]) continue;
        auto& target = *destinations[index];
        auto& source = *staged[index];
        for (std::size_t vertex = 0; vertex < target.vertices.size(); ++vertex) target.vertices[vertex].normal = source.vertices[vertex].normal;
        target.cornerSmoothed = source.cornerSmoothed;
        target.surfaceGroups = source.surfaceGroups;
        target.groupedVertices.swap(source.groupedVertices);
        target.groupedIndices.swap(source.groupedIndices);
    }
}
}
void TerrainRegion::loadPatch(int row, int column) {
    if (row < 0 || row >= rows || row >= 10 || column < 0 || column >= columns || column >= 10) throw std::out_of_range("Landscape patch coordinates");
    auto& slot = slots[row * 10 + column];
    if (slot.patch) return;
    const std::string stem = std::format("{}_{}{}", name, row, column);
    const std::string prefix = directory + stem;
    const auto masks = terrainReadFile(prefix + ".msk");
    const auto water = terrainReadFile(prefix + ".wtr", true);
    auto texture = TerrainTextureImage::decode(terrainReadFile(prefix + ".dds"));
    auto owned = std::make_unique<TerrainPatch>();
    owned->readGeometry(g_sfera_files.readAll((stem + ".lnd")), masks, water, TerrainAssets::microtexture_remap, g_sfera_graphics_runtime.base_microtexture_id);
    const auto textureId = g_sfera_textures.find(stem);
    const std::array<TerrainPatch*, 8> neighbors{patch(row - 1, column - 1), patch(row + 1, column - 1), patch(row + 1, column + 1), patch(row - 1, column + 1), patch(row, column + 1), patch(row, column - 1), patch(row - 1, column), patch(row + 1, column)};
    smoothTerrainNeighborhood(*owned, neighbors, name);
    slot.patch = std::move(owned);
    slot.texture = std::move(texture);
    slot.texture_id = textureId;
    slot.expiry = 1000;
}

namespace {
void appendTerrainCatalog(std::deque<TerrainRegion>& regions, const std::string& directory) {
    std::error_code error;
    const auto root = std::filesystem::path(directory);
    bool found = false;
    for (const auto& entry : std::filesystem::directory_iterator(root, error)) {
        if (!entry.is_regular_file()) continue;
        auto extension = entry.path().extension().string();
        SferaText::lowercaseLocale(extension);
        if (extension != ".siz") continue;
        found = true;
        if (regions.size() >= 300u) throw std::runtime_error("Too many landscape files");
        const auto dimensions = terrainReadFile(entry.path().filename().string());
        SferaBinary::Reader reader(dimensions);
        TerrainRegion region;
        region.name = entry.path().stem().string();
        region.directory = directory;
        if (region.name.size() >= 30u || region.directory.size() >= 102u) throw std::runtime_error("Landscape path is too long");
        region.rows = reader.read<int>();
        region.columns = reader.read<int>();
        if (region.rows < 0 || region.rows > 10 || region.columns < 0 || region.columns > 10) throw std::runtime_error("Invalid landscape dimensions");
        regions.push_back(std::move(region));
    }
    if (error || !found) WorldDiagnostics::fail("*.siz files not found");
}
void appendTerrainMicrotextures(const std::string& pattern, std::vector<TerrainAssets::Microtexture>& microtextures, std::array<std::uint16_t, 65536>& remap, std::uint16_t& baseIndex) {
    _finddata64i32_t found{};
    const auto search = _findfirst64i32(pattern.c_str(), &found);
    if (search == -1) return;
    try {
        do {
            if ((found.attrib & _A_SUBDIR) != 0u) continue;
            const auto index = microtextures.size();
            if (index >= 100) throw std::length_error("Landscape microtexture limit exceeded");
            auto image = TerrainTextureImage::decode(terrainReadFile(found.name));
            const auto first = SferaText::asciiFold(found.name[0]);
            const auto second = SferaText::asciiFold(found.name[1]);
            const std::uint16_t key = first | (second << 8);
            const bool base = found.name[2] == '_';
            found.name[base ? 3 : 2] = '\0';
            const auto texture = g_sfera_textures.find(found.name);
            microtextures.push_back({key, texture, std::move(image)});
            remap[key] = index;
            if (base) baseIndex = index;
        } while (_findnext64i32(search, &found) == 0);
    } catch (...) { _findclose(search); throw; }
    _findclose(search);
}
}

namespace {
bool terrainNamesEqual(std::string_view first, std::string_view second) { return SferaText::compareInsensitive(first, second) == 0; }
TerrainRegion* terrainFindRegion(std::deque<TerrainRegion>& regions, std::string_view name) {
    for (auto& region : regions) if (terrainNamesEqual(region.name, name)) return &region;
    return nullptr;
}
}
void TerrainAssets::loadMap() {
    std::deque<TerrainRegion> loadedRegions;
    std::vector<Microtexture> loadedMicrotextures;
    auto remap = std::make_unique<decltype(microtexture_remap)>();
    remap->fill(UINT16_MAX);
    std::uint16_t baseIndex = UINT16_MAX;
    std::vector<std::string> directories{"landscape\\"}; if (TerrainAssets::high_resolution_assets) directories.emplace_back("landscape_hr\\"); if (TerrainAssets::alternate_ph_assets) directories.emplace_back("landscape_ph\\"); if (TerrainAssets::alternate_rd_assets) directories.emplace_back("landscape_rd\\");
    for (const auto& directory : directories) appendTerrainMicrotextures((directory + "*.mtx"), loadedMicrotextures, *remap, baseIndex);
    if (baseIndex == UINT16_MAX) { WorldDiagnostics::fail("Base microtexture not found: landscape\\??_.mtx"); }
    for (const auto& directory : directories) appendTerrainCatalog(loadedRegions, directory);
    const auto data = terrainReadFile("landscape\\map.bin");
    constexpr std::size_t encodedCellSize = 22;
    if (data.size() != map.size() * encodedCellSize) throw std::runtime_error("Invalid landscape map file size");
    auto replacement = std::make_unique<decltype(map)>();
    SferaBinary::Reader reader(data);
    for (auto& cell : *replacement) {
        const auto encodedName = reader.take(20);
        const auto terminator = std::find(encodedName.begin(), encodedName.end(), 0);
        if (terminator == encodedName.end()) throw std::runtime_error("Unterminated landscape map name");
        const std::string name(encodedName.begin(), terminator);
        cell.tile_x = reader.read<std::uint8_t>();
        cell.tile_y = reader.read<std::uint8_t>();
        cell.region = terrainFindRegion(loadedRegions, name);
        if (cell.region == nullptr) {
            cell.region = terrainFindRegion(loadedRegions, "FILL_EMPT");
            cell.tile_x = cell.tile_y = 0;
        }
        if (cell.region == nullptr) WorldDiagnostics::fail("Patch present in map, but not found in landscape. Name: FILL_EMPT");
        if (cell.tile_x >= cell.region->rows || cell.tile_y >= cell.region->columns) throw std::runtime_error("Landscape map references an invalid patch");
    }
    releaseAll();
    regions.swap(loadedRegions);
    microtextures.swap(loadedMicrotextures);
    microtexture_remap = *remap;
    g_sfera_graphics_runtime.base_microtexture_id = baseIndex;
    map = *replacement;
    g_sfera_world_spatial.refreshTerrainBindings();
    g_sfera_contacts.clear();
    g_sfera_terrain_renderer.visibleCells.clear();
    g_sfera_terrain_renderer.waterSurfaces.clear();
}
void Contour::updateBounds() {
    min_x = min_z = 1000000.0f;
    max_x = max_z = -1000000.0f;
    for (const auto& vertex : vertices) {
        min_x = std::min(min_x, vertex.x);
        max_x = std::max(max_x, vertex.x);
        min_z = std::min(min_z, vertex.z);
        max_z = std::max(max_z, vertex.z);
    }
}

bool Contour::contains(float point_x, float point_z) const {
    if (point_x < min_x || point_x > max_x || point_z < min_z || point_z > max_z) return false;
    std::uint32_t crossings = 0;
    for (std::size_t current = 0; current < vertices.size(); ++current) {
        auto left = current, right = current == 0 ? vertices.size() - 1 : current - 1;
        if (vertices[left].x == vertices[right].x) continue;
        if (vertices[right].x < vertices[left].x) std::swap(left, right);
        const double leftX = vertices[left].x, rightX = vertices[right].x;
        if (leftX >= point_x || rightX < point_x) continue;
        const double rightZ = vertices[right].z;
        const float roundedSlope = (rightZ - vertices[left].z) / (rightX - leftX);
        const double slope = roundedSlope;
        const float intercept = vertices[left].z - leftX * slope;
        const float edge_z = slope * point_x + intercept;
        if (edge_z > point_z) ++crossings;
    }
    return (crossings & 1u) != 0;
}

Contours::Contours(int first, int last) : first_server_type(first), last_server_type(last) {}
void Contours::clear() { records.clear(); server_map.clear(); invalidateGrid(); }
void Contours::invalidateGrid() { grid_initialized = false; mask_server = -1; }
bool Contours::isServerContour(const Contour& contour) const { return contour.type >= first_server_type && contour.type <= last_server_type; }
void Contours::loadBytes(std::span<const std::uint8_t> bytes) {
    constexpr std::size_t encodedRecordSize = 24 + 4 * 64 * 4;
    if (bytes.size() < 4) throw std::runtime_error("Contours: missing record count");
    SferaBinary::Reader reader(bytes);
    const auto count = reader.read<int>();
    if (count < 0 || std::cmp_greater(count, (bytes.size() - 4) / encodedRecordSize)) throw std::runtime_error("Contours: truncated records");
    std::vector<Contour> loaded(count);
    for (auto& contour : loaded) {
        contour.type = reader.read<int>();
        const auto vertexCount = reader.read<int>();
        if (vertexCount < 0 || vertexCount > 64) throw std::runtime_error("Contours: invalid vertex count");
        contour.min_x = reader.read<float>(); contour.max_x = reader.read<float>();
        contour.min_z = reader.read<float>(); contour.max_z = reader.read<float>();
        contour.vertices.resize(vertexCount);
        const auto readColumn = [&]<class T>(T Contour::Vertex::* member) {
            for (std::size_t index = 0; index < 64; ++index) {
                const auto value = reader.read<T>();
                if (index < contour.vertices.size()) contour.vertices[index].*member = value;
            }
        };
        readColumn(&Contour::Vertex::x); readColumn(&Contour::Vertex::z);
        readColumn(&Contour::Vertex::neighbour_contour); readColumn(&Contour::Vertex::neighbour_edge);
        if (!std::isfinite(contour.min_x) || !std::isfinite(contour.max_x) || !std::isfinite(contour.min_z) || !std::isfinite(contour.max_z)) throw std::runtime_error("Contours: nonfinite bounds");
        for (const auto& vertex : contour.vertices) if (!std::isfinite(vertex.x) || !std::isfinite(vertex.z)) throw std::runtime_error("Contours: nonfinite vertex");
    }
    records.swap(loaded);
    invalidateGrid();
}

void Contours::load() { loadBytes(g_sfera_files.readAll("landscape\\contours.bin")); }
std::span<const Contour> Contours::typeRange(int first, int last) const {
    const auto begin = std::find_if(records.begin(), records.end(), [first](const Contour& contour) { return contour.type >= first; });
    if (begin == records.end() || begin->type > last) return {};
    const auto end = std::find_if(begin, records.end(), [last](const Contour& contour) { return contour.type > last; });
    return {begin, end};
}

bool Contours::sameEdge(std::size_t first_contour, std::size_t first_edge, std::size_t second_contour, std::size_t second_edge) const {
    const auto& first = records.at(first_contour);
    const auto& second = records.at(second_contour);
    if (first_edge >= first.vertices.size() || second_edge >= second.vertices.size()) throw std::out_of_range("Contours: invalid edge");
    const auto first_next = first_edge + 1 == first.vertices.size() ? 0 : first_edge + 1;
    const auto second_next = second_edge + 1 == second.vertices.size() ? 0 : second_edge + 1;
    const auto equal = [&](std::size_t a, std::size_t b) {
        return first.vertices[a].x == second.vertices[b].x && first.vertices[a].z == second.vertices[b].z;
    };
    return (equal(first_edge, second_edge) && equal(first_next, second_next)) || (equal(first_edge, second_next) && equal(first_next, second_edge));
}

void Contours::setServerMap(std::span<const int> types, std::span<const int> servers) {
    if (types.empty() || types.size() != servers.size()) throw std::invalid_argument("Contours: invalid server map");
    std::vector<std::pair<int, int>> replacement;
    replacement.reserve(types.size());
    for (std::size_t i = 0; i < types.size(); ++i) replacement.emplace_back(types[i], servers[i]);
    server_map.swap(replacement);
    invalidateGrid();
}

int Contours::serverByType(int type) const {
    for (const auto& entry : server_map) if (entry.first == type) return entry.second;
    SphereUI::InterfaceRenderer::reportError(("Contours: no server for type " + std::to_string(type)));
    return 0;
}

int Contours::typeAt(float x, float z, int first, int last) const {
    const auto selected = typeRange(first, last);
    for (auto item = selected.rbegin(); item != selected.rend(); ++item) {
        if (item->contains(x, z)) return item->type;
    }
    return -1;
}
int Contours::serverAt(float x, float z) const { const auto type = typeAt(x, z, first_server_type, last_server_type); return type == -1 ? 0 : serverByType(type); }

void Contours::connectEdges() {
    for (std::size_t first = 0; first < records.size(); ++first) {
        auto& contour = records[first];
        if (!isServerContour(contour)) continue;
        for (std::size_t edge = 0; edge < contour.vertices.size(); ++edge) {
            contour.vertices[edge].neighbour_contour = contour.vertices[edge].neighbour_edge = -1;
            bool found = false;
            for (std::size_t second = 0; second < records.size() && !found; ++second) {
                if (!isServerContour(records[second])) continue;
                for (std::size_t other = 0; other < records[second].vertices.size(); ++other) {
                    if ((first == second && edge == other) || !sameEdge(first, edge, second, other)) continue;
                    contour.vertices[edge].neighbour_contour = second;
                    contour.vertices[edge].neighbour_edge = other;
                    records[second].vertices[other].neighbour_contour = first;
                    records[second].vertices[other].neighbour_edge = edge;
                    found = true;
                    break;
                }
            }
        }
    }
}

std::vector<std::array<float, 4>> Contours::serverBoundaries() {
    if (server_map.empty()) throw std::logic_error("Contours: server map is not configured");
    connectEdges();
    std::size_t directed_count = 0;
    for (std::size_t index = 0; index < records.size(); ++index) {
        const auto& contour = records[index];
        if (!isServerContour(contour)) continue;
        for (std::size_t edge = 0; edge < contour.vertices.size(); ++edge) {
            const auto neighbour = contour.vertices[edge].neighbour_contour;
            if (neighbour < 0) continue;
            const auto& adjacent = records.at(neighbour);
            if (serverByType(adjacent.type) == serverByType(contour.type)) continue;
            const auto other = contour.vertices[edge].neighbour_edge;
            if (other < 0 || std::cmp_greater_equal(other, adjacent.vertices.size()) || !std::cmp_equal(adjacent.vertices[other].neighbour_contour, index) || !std::cmp_equal(adjacent.vertices[other].neighbour_edge, edge)) throw std::logic_error("Wrong connection of server contours");
            ++directed_count;
        }
    }
    if ((directed_count & 1u) != 0u) throw std::logic_error("Contours: unmatched server boundary");
    std::vector<std::array<float, 4>> result;
    result.reserve(directed_count / 2u);
    for (auto& contour : records) {
        if (!isServerContour(contour)) continue;
        for (std::size_t edge = 0; edge < contour.vertices.size(); ++edge) {
            const auto neighbour = contour.vertices[edge].neighbour_contour;
            if (neighbour < 0) continue;
            auto& adjacent = records[neighbour];
            if (serverByType(adjacent.type) == serverByType(contour.type)) continue;
            const auto next = edge + 1 == contour.vertices.size() ? 0 : edge + 1;
            result.push_back({contour.vertices[edge].x, contour.vertices[edge].z, contour.vertices[next].x, contour.vertices[next].z});
            adjacent.vertices[contour.vertices[edge].neighbour_edge].neighbour_contour = -1;
        }
    }
    return result;
}

void Contours::rasterizeServers() {
    server_grid.fill(0);
    const Contour* cached = nullptr;
    std::uint8_t cached_server = 0;
    const auto selected = typeRange(first_server_type, last_server_type);
    for (int x = 0; x < 160; ++x) for (int z = 0; z < 160; ++z) {
        const float point_x = -3975 + x * 50, point_z = -3975 + z * 50;
        const std::size_t cell = x * 160 + z;
        if (cached != nullptr && cached->contains(point_x, point_z)) {
            server_grid[cell] = cached_server;
            continue;
        }
        for (const auto& contour : selected) if (contour.contains(point_x, point_z)) {
            cached = &contour;
            cached_server = serverByType(contour.type);
            server_grid[cell] = cached_server;
            break;
        }
    }
    grid_initialized = true;
    mask_server = -1;
}

void Contours::buildServerMask(std::uint8_t server) {
    server_mask.fill(0);
    for (int x = 0; x < 160; ++x) for (int z = 0; z < 160; ++z) {
        if (server_grid[x * 160 + z] != server) continue;
        for (auto nx = std::max(0, x - 2); nx <= std::min(159, x + 2); ++nx) for (auto nz = std::max(0, z - 2); nz <= std::min(159, z + 2); ++nz) server_mask[nx * 160 + nz] = 1;
    }
    mask_server = server;
}

bool Contours::nearServer(float x, float z, int server) {
    if (server < 0 || server > 100 || server_map.empty()) throw std::invalid_argument("Contours: invalid server selection");
    if (!grid_initialized) rasterizeServers();
    if (server != mask_server) buildServerMask(server);
    const double cell_x = (x + 4000.0) / 50.0, cell_z = (z + 4000.0) / 50.0;
    if (!std::isfinite(cell_x) || !std::isfinite(cell_z) || cell_x <= -1.0 || cell_x >= 160.0 || cell_z <= -1.0 || cell_z >= 160.0) return false;
    return server_mask[cell_x * 160u + cell_z] != 0;
}

void SferaServerWall::clear() {
    segments.clear();
    normals.clear();
    for (auto& effect : effects) effect.remaining = -1.0f;
}

void SferaServerWall::setSegments(std::span<const std::array<float, 4>> coordinates) {
    clear();
    if (coordinates.empty()) return;
    segments.reserve(coordinates.size());
    for (const auto& row : coordinates) segments.push_back({SferaVec3F{row[0], 1.0f, row[1]}, SferaVec3F{row[2], 1.0f, row[3]}});
    prepareGeometry();
    texture_id = g_sfera_textures.find("fx_swall");
}

void SferaServerWall::prepareGeometry() {
    normals.clear();
    normals.reserve(segments.size());
    for (const auto& segment : segments) {
        const double firstHeight = segment[0].y, secondHeight = segment[1].y;
        const float x = firstHeight * segment[1].z - secondHeight * segment[0].z;
        const float z = secondHeight * segment[0].x - firstHeight * segment[1].x;
        const SferaVec3F perpendicular{x, 0.0f, z};
        const float length = perpendicular.length();
        const float reciprocal = length == 0.0f ? 1.0 : 1.0 / length;
        auto normal = perpendicular * reciprocal;
        normal.y = 0.0f;
        normals.push_back(normal);
    }
    for (auto& effect : effects) effect = SferaServerWallEffectRecord{};
    for (std::size_t row = 0; row < 4; ++row) for (std::size_t column = 0; column < 4; ++column) {
        auto& frame = texture_frames[row * 4 + column];
        const float u = column * 0.25f, v = row * 0.25f;
        frame = {};
        frame.uv[1][0] = frame.uv[4][0] = u;
        frame.uv[2][0] = frame.uv[3][0] = u + 0.25f;
        frame.uv[1][1] = frame.uv[2][1] = v;
        frame.uv[3][1] = frame.uv[4][1] = v + 0.25f;
    }
}

bool SferaServerWall::intersectPlane(const SferaPlaneF& plane, const SferaVec3F& start, const SferaVec3F& end, SferaVec3F& output) {
    const auto direction = end - start;
    const float denominator = plane.normal.dot(direction);
    if (!(denominator < -std::numeric_limits<float>::min())) return false;
    const float roundedDistance = plane.evaluate(start);
    const double distance = roundedDistance;
    if (!(distance >= 0.0 && distance + denominator < 0.0)) return false;
    const float ratio = distance / denominator;
    output = start.subtractScaled(direction, ratio);
    return true;
}

std::uint32_t SferaServerWall::classifyVisibility(const SferaFrustumF& frustum, std::span<const SferaVec3F> points) {
    bool intersects = false;
    for (const auto plane_index : {0, 1, 3, 5}) {
        const auto& plane = frustum.planes[plane_index];
        std::size_t outside = 0;
        for (const auto& point : points) if (point.dot<double, true>(plane.normal) + plane.distance < 0.0) ++outside;
        if (outside == points.size()) return 0u;
        intersects = intersects || outside != 0;
    }
    return intersects ? 1u : 2u;
}

int SferaServerWall::intersectXZ(const SferaVec3F& first, const SferaVec3F& second, const SferaVec3F& other_first, const SferaVec3F& other_second, SferaVec3F& output) {
    struct Line {
        float x, z, constant;
        static Line through(const SferaVec3F& first, const SferaVec3F& second) {
            const double firstX = first.x, firstZ = first.z, secondX = second.x, secondZ = second.z;
            Line result;
            result.x = secondZ - firstZ;
            result.z = firstX - secondX;
            result.constant = secondX * firstZ - firstX * secondZ;
            return result;
        }
        float evaluate(const SferaVec3F& point) const {
            const double alongX = x, alongZ = z;
            return alongX * point.x + alongZ * point.z + constant;
        }
    };
    const auto a = Line::through(first, second), b = Line::through(other_first, other_second);
    for (const auto pair : {std::array{a.evaluate(other_first), a.evaluate(other_second)}, std::array{b.evaluate(first), b.evaluate(second)}}) {
        if (pair[0] < 0.0f && pair[1] < 0.0f) return -1;
        if (pair[0] > 0.0f && pair[1] > 0.0f) return 1;
    }
    const double x = a.x, z = a.z, constant = a.constant;
    const float determinant = x * b.z - z * b.x;
    if (determinant == 0.0f) return -2;
    const float reciprocal = 1.0 / determinant;
    output.x = (z * b.constant - constant * b.z) * reciprocal;
    output.y = first.y;
    output.z = (constant * b.x - x * b.constant) * reciprocal;
    return 0;
}

void SferaServerWall::generateEffects() {
    const auto* observer = g_sfera_world_objects.object(1u);
    if (observer != nullptr) generateEffects(*observer, g_sfera_camera.field_of_view, SphereRender::SceneRenderer::frustum);
}

void SferaServerWall::generateEffects(const WorldObject& observer, float field_of_view, const SferaFrustumF& frustum) {
    if (segments.empty() || observer.position.y > 1000.0f) return;
    const double heading = observer.rotation.x + 1.5707964897155762;
    const float left_angle = heading + field_of_view * 0.5, right_angle = heading - field_of_view * 0.5;
    const auto left = SferaMath::rotationTerms(left_angle), right = SferaMath::rotationTerms(right_angle);
    auto left_ray = observer.position, right_ray = observer.position;
    left_ray.x += left.cosine * 60.0;
    left_ray.z += left.sine * 60.0;
    right_ray.x += right.cosine * 60.0;
    right_ray.z += right.sine * 60.0;
    if ((std::rand() & 1) == 0) return;
    for (std::size_t index = 0; index < segments.size(); ++index) {
        if ((std::rand() & 1) == 0) continue;
        auto first = segments[index][0], second = segments[index][1];
        first.y = second.y = observer.position.y;
        const auto difference = second - first;
        const auto midpoint = first + difference * 0.5f;
        const float side = normals[index].dot(midpoint - observer.position);
        if (side == 0.0f) continue;
        SferaVec3F start = first, end = second;
        const auto left_result = intersectXZ(first, second, observer.position, left_ray, side > 0.0f ? end : start);
        const auto right_result = intersectXZ(first, second, observer.position, right_ray, side > 0.0f ? start : end);
        const auto visibility = classifyVisibility(frustum, segments[index]);
        if (left_result != 0 && right_result != 0 && visibility == 0u) continue;
        start.y = end.y = observer.position.y;
        if (visibility == 1u) {
            const auto original_start = start, original_end = end;
            SferaVec3F intersection;
            if (intersectPlane(frustum.planes[0], original_start, original_end, intersection)) start = intersection;
            if (intersectPlane(frustum.planes[5], original_start, original_end, intersection)) end = intersection;
        }
        auto horizontal = end - start;
        horizontal.y = 0.0f;
        const float length = horizontal.length();
        if (length == 0.0f) continue;
        const float fraction = length > 40.0f ? 40.0 / length : 1.0;
        const float reciprocal = 1.0 / length;
        auto direction = horizontal * reciprocal;
        direction.y = 0.0f;
        const auto distanceToObserver = [&](const SferaVec3F& point) {
            auto delta = observer.position - point;
            delta.y = 0.0f;
            // Keep the unrounded square root used when ordering the endpoints.
            const float square = delta.dot(delta);
            const double radicand = square;
            return std::sqrt(radicand);
        };
        if (distanceToObserver(end) < distanceToObserver(start)) std::swap(start, end);
        const auto limited_end = start + (end - start) * fraction;
        auto free = std::find_if(effects.begin(), effects.end(), [](const SferaServerWallEffectRecord& effect) { return !(effect.remaining > 0.0f); });
        if (free == effects.end()) continue;
        float along = std::rand() / 32767.0;
        const float height_first = std::rand() / 32767.0;
        if (along < 0.10000000149011612) along = along + 0.10000000149011612;
        if (along > 0.8999999761581421) along = along - 0.10000000149011612;
        SferaVec3F center{SferaMath::interpolate(start.x, limited_end.x, along), 0.0f, SferaMath::interpolate(start.z, limited_end.z, along)};
        center.y = (height_first - std::rand() / 32767.0) * 10.0 + (start.y - 2.0);
        const float half_size = (std::rand() % 8 + 20) * 0.5;
        const auto offset = direction * half_size;
        const auto first_side = center - offset, second_side = center + offset;
        const double firstHeight = first_side.y, secondHeight = second_side.y;
        free->positions[0] = free->positions[1] = first_side;
        free->positions[2] = free->positions[3] = second_side;
        free->positions[0].y = firstHeight - half_size;
        free->positions[1].y = firstHeight + half_size;
        free->positions[2].y = secondHeight + half_size;
        free->positions[3].y = secondHeight - half_size;
        free->duration = free->remaining = std::rand() % 32 + 50;
        free->animation_phase = std::rand() % texture_frames.size();
    }
}

void SferaServerWall::updateEffectRendering() {
    if (segments.empty()) return;
    for (auto& effect : effects) {
        if (effect.remaining <= 0.0f) continue;
        if (g_sfera_effect_manager.render_slot_count + 1u >= 10000u) break;
        effect.remaining -= 1.0f;
        const float ratio = effect.duration == 0.0f ? 0.0f : effect.remaining / effect.duration;
        const std::uint32_t alpha = std::trunc((0.5f - 0.5f * std::cos(ratio * 6.283185958862305f)) * 100.0f);
        auto* slot = g_sfera_effect_manager.acquireRenderSlot();
        if (slot == nullptr) break;
        slot->additive = true;
        slot->custom_uv = true;
        slot->resource_id = texture_id;
        slot->self_illumination = 255u;
        for (std::size_t vertex = 0; vertex < 4; ++vertex) { slot->position[vertex] = effect.positions[vertex]; slot->color[0][vertex] = slot->color[1][vertex] = slot->color[2][vertex] = 255u; slot->color[3][vertex] = alpha; }
        effect.animation_phase += 0.25f;
        const auto frame = SferaNumeric::truncatedWord(effect.animation_phase) % texture_frames.size();
        for (std::size_t vertex = 0; vertex < 4; ++vertex) { slot->uv[vertex][0] = texture_frames[frame].uv[vertex + 1u][0]; slot->uv[vertex][1] = texture_frames[frame].uv[vertex + 1u][1]; }
    }
}

void Contours::rebuildServerWall() {
    const auto boundaries = serverBoundaries();
    g_sfera_server_wall.setSegments(boundaries);
}

namespace SphereWorld {
namespace {
        Bounds currentSpatialBounds() { return {{g_sfera_world_spatial.query_bounds.minimum.x, g_sfera_world_spatial.query_bounds.minimum.y, g_sfera_world_spatial.query_bounds.minimum.z}, {g_sfera_world_spatial.query_bounds.maximum.x, g_sfera_world_spatial.query_bounds.maximum.y, g_sfera_world_spatial.query_bounds.maximum.z}}; }
    void publishWorldBounds(const Bounds& value) { g_sfera_contacts.query_bounds.minimum = {{value.minimum.x}, {value.minimum.y}, {value.minimum.z}}; g_sfera_contacts.query_bounds.maximum = {{value.maximum.x}, {value.maximum.y}, {value.maximum.z}}; }
    void publishSpatialBounds(const Bounds& value) { g_sfera_world_spatial.query_bounds.minimum = {{value.minimum.x}, {value.minimum.y}, {value.minimum.z}}; g_sfera_world_spatial.query_bounds.maximum = {{value.maximum.x}, {value.maximum.y}, {value.maximum.z}}; }
    int spatialCell(float coordinate, float radius) { const double precise_coordinate = coordinate; return SferaNumeric::truncateInt((precise_coordinate + radius) * 0.11999999731779099 + 100000.0) - 100000; }
    SferaMatrix4x4F rotationOnly(SferaMatrix4x4F value) { value.m[0][3] = value.m[1][3] = value.m[2][3] = 0.0f; return value; }
    std::array<SferaVec3F, 3> boxAxes(const SferaBoundsCornersRuntime& box, std::uint32_t diagnostic) { return {(box.corners[1] - box.corners[0]).normalized(diagnostic), (box.corners[3] - box.corners[0]).normalized(diagnostic + 1u), (box.corners[5] - box.corners[0]).normalized(diagnostic + 2u)}; }
    void updateTriangleBounds(SphereRender::ModelCollisionTriangle& triangle) { triangle.minimum = triangle.maximum = triangle.vertices[0]; for (std::size_t vertex = 1; vertex < 3; ++vertex) { for (std::size_t axis = 0; axis < 3; ++axis) { const float value = triangle.vertices[vertex].component(axis); if (value < triangle.minimum.component(axis)) triangle.minimum.setComponent(axis, value); else if (value > triangle.maximum.component(axis)) triangle.maximum.setComponent(axis, value); } } }
    SphereRender::ModelCollisionTriangle worldTriangle(const SphereRender::ModelCollisionTriangle& triangle, const SferaMatrix4x4F& transform) { auto result = triangle; for (auto& point : result.vertices) point = transform.transformPoint(point); result.normal = rotationOnly(transform).transformPoint(triangle.normal); updateTriangleBounds(result); return result; }
    bool clippedTriangle(const SphereRender::ModelCollisionTriangle& triangle, const Bounds& bounds) { return g_sfera_clipped_polygon.clipTriangleToBounds(triangle.vertices[0], triangle.vertices[1], triangle.vertices[2], bounds.minimum, bounds.maximum); }
    SphereRender::ModelCollisionTriangle terrainTriangle(const TerrainCandidate& candidate, const TerrainTriangle& face) { SphereRender::ModelCollisionTriangle result; for (std::size_t i = 0; i < 3; ++i) { result.vertices[i] = candidate.patch->vertices[face.indices[i]].position; const double x = result.vertices[i].x, z = result.vertices[i].z; result.vertices[i].x = x + candidate.origin_x; result.vertices[i].z = z + candidate.origin_z; } result.normal = face.normal; return result; }

}
bool Bounds::intersects(const Bounds& other) const { return !(maximum.x < other.minimum.x || minimum.x > other.maximum.x || maximum.y < other.minimum.y || minimum.y > other.maximum.y || maximum.z < other.minimum.z || minimum.z > other.maximum.z); }
bool Bounds::intersectsInterior(const Bounds& other) const { return maximum.x > other.minimum.x && minimum.x < other.maximum.x && maximum.y > other.minimum.y && minimum.y < other.maximum.y && maximum.z > other.minimum.z && minimum.z < other.maximum.z; }
bool Bounds::contains(const Bounds& other) const { return !(other.minimum.x < minimum.x || other.minimum.y < minimum.y || other.minimum.z < minimum.z || other.maximum.x > maximum.x || other.maximum.y > maximum.y || other.maximum.z > maximum.z); }
bool Bounds::overlapsTriangle(const SferaVec3F (&vertices)[3]) const { for (std::size_t axis = 0; axis < 3; ++axis) { if (minimum.component(axis) > vertices[0].component(axis) && minimum.component(axis) > vertices[1].component(axis) && minimum.component(axis) > vertices[2].component(axis)) return false; if (maximum.component(axis) < vertices[0].component(axis) && maximum.component(axis) < vertices[1].component(axis) && maximum.component(axis) < vertices[2].component(axis)) return false; } return true; }
Bounds Bounds::expanded(float amount) const { return {minimum - SferaVec3F{amount, amount, amount}, maximum + SferaVec3F{amount, amount, amount}}; }
Bounds Bounds::inverseTransformed(const SferaMatrix4x4F& transform) const { auto points = corners(); for (auto& point : points.corners) point = transform.inverseTransformPoint(point); Bounds result; points.getExtents(result.minimum, result.maximum); return result; }
SferaBoundsCornersRuntime Bounds::corners() const { return SferaBoundsCornersRuntime::fromExtents(minimum, maximum); }
bool ContactQuery::projectionsOverlap(const SferaBoundsCornersRuntime& first, const SferaBoundsCornersRuntime& second, const SferaVec3F& axis) { float minimum[2]{}, maximum[2]{}; const SferaBoundsCornersRuntime* boxes[]{&first, &second}; for (std::size_t box = 0; box < 2; ++box) { for (std::size_t vertex = 0; vertex < 8; ++vertex) { const auto& point = boxes[box]->corners[vertex]; const float projection = point.dot<double, true>(axis); if (vertex == 0) minimum[box] = maximum[box] = projection; else if (projection < minimum[box]) minimum[box] = projection; else if (projection > maximum[box]) maximum[box] = projection; } } return !(minimum[0] > maximum[1] || minimum[1] > maximum[0]); }
bool ContactQuery::boxesOverlap(const SferaBoundsCornersRuntime& first, const SferaBoundsCornersRuntime& second) { std::array<SferaVec3F, 3> first_axes, second_axes; const std::size_t corners[]{1u, 3u, 5u}; for (std::size_t axis = 0; axis < 3; ++axis) { first_axes[axis] = (first.corners[corners[axis]] - first.corners[0]).normalized(6u + axis); if (!projectionsOverlap(first, second, first_axes[axis])) return false; } for (std::size_t axis = 0; axis < 3; ++axis) { second_axes[axis] = (second.corners[corners[axis]] - second.corners[0]).normalized(9u + axis); if (!projectionsOverlap(first, second, second_axes[axis])) return false; } for (const auto& first_axis : first_axes) for (const auto& second_axis : second_axes) if (!projectionsOverlap(first, second, first_axis.cross(second_axis))) return false; return true; }
int ContactQuery::intersectTriangle(const SferaVec3F& start, const SferaVec3F& end, const SphereRender::ModelCollisionTriangle& triangle, SferaVec3F& intersection) { const SferaPlaneF plane{triangle.normal, triangle.plane_distance}; if (plane.intersectLine(start, end, intersection) != 1) return 0; const SferaVec3F* vertices[]{&triangle.vertices[0], &triangle.vertices[1], &triangle.vertices[2]}; return triangle.normal.containsConvexPolygonPoint(vertices, intersection) ? 2 : 1; }
void ContactQuery::sortTriangles(std::span<SphereRender::ModelCollisionTriangle> triangles) {
    SferaAlgorithms::stableSort(triangles, [](const auto& triangle) { return std::fabs(triangle.normal.y); });
}
SpatialLeaf* WorldSpatialIndex::leafAt(int cell_x, int cell_z) {
    auto& cells = cells_;
    const auto found = cells.find({cell_x, cell_z});
    return found == cells.end() ? nullptr : &found->second;
}
bool WorldSpatialIndex::typesInteract(std::uint32_t combined_type) { switch (combined_type) { case 7u: case 8u: case 9u: case 10u: case 11u: case 14u: case 21u: case 23u: case 24u: case 25u: case 28u: case 32u: case 35u: case 39u: return true; default: return false; } }
void WorldSpatialIndex::forgetTerrain(const TerrainPatch& patch) {
    std::erase_if(terrain_, [&patch](const auto& candidate) { return candidate.patch == &patch; });
}
void WorldSpatialIndex::clearCandidates() {
    objects_.clear();
    terrain_.clear();
}
void WorldSpatialIndex::finishCandidates() { for (const auto handle : objects_) g_sfera_world_objects.object(handle)->visibility_mark = 0; }
void WorldSpatialIndex::addTerrain(TerrainRegion& region, int row, int column, int cell, float origin_x, float origin_z) {
    if (!region.patch(row, column)) region.loadPatch(row, column);
    region.slots[row * 10 + column].expiry = 1000;
    auto* patch = region.patch(row, column);
    terrain_.push_back({patch, &patch->cells[cell], origin_x, origin_z});
}
void WorldSpatialIndex::gatherCell(int cell_x, int cell_z, bool include_terrain) {
    auto* cell = leafAt(cell_x, cell_z);
    if (!cell) return;
    for (const auto handle : cell->objects) {
        auto* object = g_sfera_world_objects.object(handle);
        if (object->visibility_mark == 1u) continue;
        objects_.push_back(handle);
        object->visibility_mark = 1u;
    }
    if (cell->contains_landscape && include_terrain) {
        addTerrain(*cell->region, cell->patch_row, cell->patch_column,
            (cell->quarter * 4 + cell->group) * 9 + cell->cell, cell->origin_x, cell->origin_z);
    }
}
void WorldSpatialIndex::gatherObject(std::uint32_t handle) { const auto* object = g_sfera_world_objects.object(handle); clearCandidates(); if (object->grid_min_x == 1000000) return; for (int x = object->grid_min_x; x <= object->grid_max_x; ++x) for (int z = object->grid_min_y; z <= object->grid_max_y; ++z) gatherCell(x, z, object->position.y < 1000.0f); finishCandidates(); }
void WorldSpatialIndex::gatherObjects(const SferaVec3F& center, float radius) { clearCandidates(); const int min_x = spatialCell(center.x, -radius), max_x = spatialCell(center.x, radius), min_z = spatialCell(center.z, -radius), max_z = spatialCell(center.z, radius); for (int x = min_x; x <= max_x; ++x) for (int z = min_z; z <= max_z; ++z) gatherCell(x, z, false); finishCandidates(); }

}
namespace SphereWorld {
namespace {
void bindTerrainCell(SpatialLeaf& leaf, int cell_x, int cell_z) {
    const int tile_x = (cell_x + 120000) / 12 - 10000, tile_z = (cell_z + 120000) / 12 - 10000, local_x = (cell_x + 120000) % 12, local_z = (cell_z + 120000) % 12;
    int map_x = tile_x + 40, map_z = 39 - tile_z;
    if (map_x < 0 || map_x >= 80) map_x = 0;
    if (map_z < 0 || map_z >= 80) map_z = 0;
    const int map_index = map_x * 80 + map_z;
    const auto& record = TerrainAssets::map[map_index];
    leaf.region = TerrainAssets::map[map_index].region; leaf.patch_row = record.tile_x; leaf.patch_column = record.tile_y; leaf.quarter = local_x / 6 + local_z / 6 * 2; leaf.group = local_x / 3 % 2 + local_z / 3 % 2 * 2; leaf.cell = local_x % 3 + local_z % 3 * 3; leaf.origin_x = tile_x * 100; leaf.origin_z = tile_z * 100; leaf.contains_landscape = true;
}
}
void WorldSpatialIndex::insert(std::uint32_t handle, int cell_x, int cell_z) {
    if (cell_x < -512 || cell_x >= 512 || cell_z < -512 || cell_z >= 512) return;
    const auto [position, inserted] = cells_.try_emplace(std::pair{cell_x, cell_z});
    auto& leaf = position->second;
    const auto existing = std::find(leaf.objects.begin(), leaf.objects.end(), handle);
    if (existing != leaf.objects.end()) std::rotate(existing, existing + 1, leaf.objects.end());
    else {
        try { leaf.objects.push_back(handle); }
        catch (...) { if (inserted) cells_.erase(position); throw; }
    }
    bindTerrainCell(leaf, cell_x, cell_z);
}
void WorldSpatialIndex::gatherTerrain(const SferaVec3F& center, float radius) {
    terrain_.clear();
    const int min_x = spatialCell(center.x, -radius), max_x = spatialCell(center.x, radius);
    const int min_z = spatialCell(center.z, -radius), max_z = spatialCell(center.z, radius);
    for (int x = min_x; x <= max_x; ++x) for (int z = min_z; z <= max_z; ++z) {
        SpatialLeaf location;
        bindTerrainCell(location, x, z);
        if (location.region) addTerrain(*location.region, location.patch_row, location.patch_column,
            (location.quarter * 4 + location.group) * 9 + location.cell, location.origin_x, location.origin_z);
    }
}
void WorldSpatialIndex::refreshTerrainBindings() noexcept {
    terrain_.clear();
    shadow_vertices_.clear();
    for (auto& [key, leaf] : cells_) bindTerrainCell(leaf, key.first, key.second);
}
void WorldSpatialIndex::remove(std::uint32_t handle, int cell_x, int cell_z) {
    if (cell_x < -512 || cell_x >= 512 || cell_z < -512 || cell_z >= 512) return;
    auto& cells = cells_;
    const auto found = cells.find({cell_x, cell_z});
    if (found == cells.end()) { WorldDiagnostics::warning("Spatial cell is not registered"); return; }
    auto& leaf = found->second;
    const auto object = std::find(leaf.objects.begin(), leaf.objects.end(), handle);
    if (object == leaf.objects.end()) { WorldDiagnostics::warning("Object is not registered in the spatial cell"); return; }
    leaf.objects.erase(object);
    if (leaf.objects.empty()) cells.erase(found);
}
void ContactQuery::updateBounds(std::uint32_t handle) {
    auto* object = g_sfera_world_objects.object(handle);
    if (object->extended()) { auto* extended = g_sfera_world_objects.extendedObject(handle); if (extended->previous_bounds_position.x == object->position.x && extended->previous_bounds_position.y == object->position.y && extended->previous_bounds_position.z == object->position.z && extended->previous_bounds_rotation.x == object->rotation.x && extended->previous_bounds_rotation.y == object->rotation.y && extended->previous_bounds_rotation.z == object->rotation.z) return; extended->previous_bounds_position = object->position; extended->previous_bounds_rotation = object->rotation; }
    const auto* model = g_sfera_world_objects.model(*object);
    if (model->collision_kind == SphereRender::CollisionKind::AxisAlignedBounds || model->collision_kind == SphereRender::CollisionKind::None) { object->bounds_minimum = model->minimum + object->position; object->bounds_maximum = model->maximum + object->position; return; }
    object->world_transform = SferaMatrix4x4F::fromEuler(object->position, object->rotation);
    SferaBoundsCornersRuntime transformed;
    for (std::size_t i = 0; i < 8; ++i) object->bounds_corners[i] = transformed.corners[i] = object->world_transform.transformPoint(model->oriented_corners.corners[i]);
    transformed.getExtents(object->bounds_minimum, object->bounds_maximum);
}
void ContactQuery::publishNormal(const SferaVec3F& normal) { normals_.push_back(normal); }
void ContactQuery::appendBoxNormals(const SferaBoundsCornersRuntime& corners) { for (const auto& normal : boxAxes(corners, 2u)) { if (std::fabs(normal.y) > 0.800000011920929f) continue; publishNormal(normal); publishNormal(normal * -1.0f); } }
void ContactQuery::publishDirection(const SphereRender::ModelCollisionTriangle& triangle) { support_normal = triangle.normal; support_direction = (triangle.collision_flags >> 8u) & 255u; }
void ContactQuery::setIgnoredObjects(std::span<const std::uint32_t> handles) {
    ignored_.assign(handles.begin(), handles.end());
}
void ContactQuery::gather(std::uint32_t handle) {
    auto* subject = g_sfera_world_objects.object(handle);
    if (!subject) { WorldDiagnostics::report("GreatherNearCldInfo: wrong handle"); return; }
    const auto* subject_model = g_sfera_world_objects.model(*subject);
    const Bounds query_bounds = currentSpatialBounds();
    publishWorldBounds(query_bounds); contacts_.clear();
    g_sfera_world_spatial.gatherObject(handle);
    for (const auto candidate_handle : g_sfera_world_spatial.objects()) {
        auto* object = g_sfera_world_objects.object(candidate_handle);
        const auto* model = g_sfera_world_objects.model(*object);
        if (candidate_handle == handle || (object->extended() && g_sfera_world_objects.extendedObject(candidate_handle)->render_enabled == 0u) || model->collision_kind == SphereRender::CollisionKind::None || !WorldSpatialIndex::typesInteract(subject->render_group * 7u + object->render_group)) continue;
        updateBounds(candidate_handle);
        const Bounds object_bounds{object->bounds_minimum, object->bounds_maximum};
        if (!query_bounds.intersects(object_bounds)) continue;
        NearContact contact; contact.handle = candidate_handle; contact.subject_kind = subject_model->collision_kind; contact.geometry_kind = model->collision_kind; contact.bounds = object_bounds; std::copy_n(object->bounds_corners, 8u, contact.corners.corners);
        if (contact.geometry_kind <= SphereRender::CollisionKind::OrientedBounds) { contacts_.push_back(std::move(contact)); continue; }
        if (contact.subject_kind == SphereRender::CollisionKind::Triangles) { if (model->radius < subject_model->radius) { contact.geometry_kind = SphereRender::CollisionKind::OrientedBounds; contacts_.push_back(std::move(contact)); continue; } contact.subject_kind = SphereRender::CollisionKind::OrientedBounds; }
        const Bounds local_bounds = query_bounds.inverseTransformed(object->world_transform);
        std::vector<std::vector<SphereRender::ModelCollisionTriangle>> groups;
        std::size_t total = 0;
        for (std::size_t group_index = 0; group_index < model->collision_groups.size(); ++group_index) {
            const auto& group = model->collision_groups[group_index];
            const auto& bone = model->bones[group.bone];
            if (const auto* bounds = std::get_if<SphereRender::BoneBounds>(&bone.data); bounds && !local_bounds.intersects({bounds->minimum, bounds->maximum})) continue;
            std::vector<SphereRender::ModelCollisionTriangle> triangles;
            for (std::size_t face = 0; face < group.triangle_count; ++face) { const auto& source = model->collision_triangles[group.first_triangle + face]; if (!local_bounds.intersectsInterior({source.minimum, source.maximum})) continue; auto triangle = worldTriangle(source, object->world_transform); if (!clippedTriangle(triangle, query_bounds)) continue; triangles.push_back(triangle); if (++total >= 2000u) { contacts_.clear(); return; } }
            if (!triangles.empty()) groups.push_back(std::move(triangles));
        }
        if (total == 0) continue;
        std::vector<std::size_t> consumed(groups.size());
        contact.triangles.reserve(total);
        while (contact.triangles.size() < total) { float smallest = 2.0f; std::size_t selected = groups.size(); for (std::size_t group = 0; group < groups.size(); ++group) { if (consumed[group] == groups[group].size()) continue; const float key = std::fabs(groups[group][consumed[group]].normal.y); if (smallest > key) { smallest = key; selected = group; } } if (selected == groups.size()) { WorldDiagnostics::report("Collision normal exceeds unit length"); return; } contact.triangles.push_back(groups[selected][consumed[selected]++]); }
        contacts_.push_back(std::move(contact));
    }
    NearContact landscape; landscape.handle = 1u; landscape.subject_kind = subject_model->collision_kind == SphereRender::CollisionKind::Triangles ? SphereRender::CollisionKind::OrientedBounds : subject_model->collision_kind; landscape.geometry_kind = SphereRender::CollisionKind::Triangles;
    for (const auto& candidate : g_sfera_world_spatial.terrain()) for (std::size_t face = 0; face < candidate.cell->triangles.size(); ++face) { auto triangle = terrainTriangle(candidate, candidate.cell->triangles[face]); if (clippedTriangle(triangle, query_bounds)) landscape.triangles.push_back(triangle); }
    if (!landscape.triangles.empty()) { sortTriangles(landscape.triangles); contacts_.push_back(std::move(landscape)); }
}
}
namespace SphereWorld {
bool ContactQuery::trianglesHitBox(const SphereRender::Model& model, const SferaMatrix4x4F& transform, const Bounds& query_bounds, const Bounds& local_bounds, const SferaMatrix4x4F* box_transform, const SferaMatrix4x4F* box_basis) {
    publishWorldBounds(query_bounds);
    for (std::size_t group_index = 0; group_index < model.collision_groups.size(); ++group_index) {
        const auto& group = model.collision_groups[group_index];
        const auto& bone = model.bones[group.bone];
        if (const auto* bounds = std::get_if<SphereRender::BoneBounds>(&bone.data); bounds && !local_bounds.intersects({bounds->minimum, bounds->maximum})) continue;
        for (std::size_t face = 0; face < group.triangle_count; ++face) { const auto& source = model.collision_triangles[group.first_triangle + face]; if (!local_bounds.intersects({source.minimum, source.maximum})) continue; auto triangle = source; for (auto& point : triangle.vertices) { point = transform.transformPoint(point); if (box_transform) point = box_transform->inverseTransformPoint(point); if (box_basis) point = box_basis->inverseTransformPoint(point); } if (clippedTriangle(triangle, query_bounds)) return true; }
    }
    return false;
}
std::uint32_t ContactQuery::test(std::uint32_t handle, Mode mode, bool reuse_cache, bool honor_ignored) {
    updateBounds(handle);
    auto* subject = g_sfera_world_objects.object(handle);
    const auto* subject_model = g_sfera_world_objects.model(*subject);
    const Bounds subject_bounds{subject->bounds_minimum, subject->bounds_maximum};
    obstacle_height = 1000.0f;
    switch (mode) { case Mode::Movement: case Mode::Normals: normals_.clear(); break; case Mode::Support: support_normal = {{0.0f}, {-1.0f}, {0.0f}}; support_direction = 0; break; case Mode::Material: surface_material = 6; break; case Mode::CollectIgnored: ignored_.clear(); break; default: break; }
    if (!reuse_cache || !currentSpatialBounds().contains(subject_bounds)) { publishSpatialBounds(subject_bounds.expanded(1.2000000476837158f)); gather(handle); }
    publishWorldBounds(subject_bounds);
    for (const auto& contact : contacts_) {
        if (contact.handle != 1u && !subject_bounds.intersects(contact.bounds)) continue;
        if (honor_ignored && mode != Mode::Material && mode != Mode::CollectIgnored && std::find(ignored_.begin(), ignored_.end(), contact.handle) != ignored_.end()) continue;
        if (mode == Mode::Material && contact.geometry_kind != SphereRender::CollisionKind::Triangles) continue;
        auto* candidate = g_sfera_world_objects.object(contact.handle);
        const auto* candidate_model = g_sfera_world_objects.model(*candidate);
        if (contact.subject_kind <= SphereRender::CollisionKind::OrientedBounds && contact.geometry_kind <= SphereRender::CollisionKind::OrientedBounds) {
            bool hit = true;
            if (contact.subject_kind == SphereRender::CollisionKind::AxisAlignedBounds && contact.geometry_kind == SphereRender::CollisionKind::OrientedBounds) hit = boxesOverlap(subject_bounds.corners(), contact.corners);
            if (contact.subject_kind == SphereRender::CollisionKind::OrientedBounds) { SferaBoundsCornersRuntime subject_corners; std::copy_n(subject->bounds_corners, 8u, subject_corners.corners); hit = boxesOverlap(contact.geometry_kind == SphereRender::CollisionKind::AxisAlignedBounds ? contact.bounds.corners() : contact.corners, subject_corners); }
            if (!hit) continue;
            if (mode == Mode::CollectIgnored) { ignored_.push_back(contact.handle); continue; }
            if (contact.subject_kind == SphereRender::CollisionKind::AxisAlignedBounds && contact.geometry_kind == SphereRender::CollisionKind::OrientedBounds && mode == Mode::Normals) appendBoxNormals(contact.corners);
            return contact.handle;
        }
        if (contact.subject_kind <= SphereRender::CollisionKind::OrientedBounds && contact.geometry_kind == SphereRender::CollisionKind::Triangles) {
            const Bounds clip_bounds = contact.subject_kind == SphereRender::CollisionKind::AxisAlignedBounds ? subject_bounds : Bounds{{}, subject_model->oriented_size};
            publishWorldBounds(clip_bounds);
            for (std::size_t position = 0; position < contact.triangles.size(); ++position) {
                const std::size_t index = mode == Mode::Support ? contact.triangles.size() - position - 1u : position;
                const auto& triangle = contact.triangles[index];
                const std::uint32_t material = triangle.collision_flags & 255u;
                if (mode == Mode::Material ? material == 0u || material >= surface_material : material > 0u) continue;
                if (contact.handle != 1u && !subject_bounds.intersects({triangle.minimum, triangle.maximum})) continue;
                auto local_triangle = triangle;
                if (contact.subject_kind == SphereRender::CollisionKind::OrientedBounds) for (auto& point : local_triangle.vertices) point = subject_model->bounds_transform.inverseTransformPoint(subject->world_transform.inverseTransformPoint(point));
                if (!clippedTriangle(local_triangle, clip_bounds)) continue;
                if (mode == Mode::Material) { surface_material = material; if (contact.subject_kind == SphereRender::CollisionKind::AxisAlignedBounds && handle == g_sfera_world_objects.controlled_object_handle) g_sfera_world_objects.activateTrap(*candidate); continue; }
                if (mode == Mode::CollectIgnored) { ignored_.push_back(contact.handle); break; }
                if (mode == Mode::Support) { publishDirection(triangle); return contact.handle; }
                if (mode == Mode::Movement || mode == Mode::Normals) { if (contact.subject_kind == SphereRender::CollisionKind::OrientedBounds) return contact.handle; if (mode == Mode::Normals) { publishNormal(triangle.normal); continue; } if (contact.handle != 1u) { const double top = candidate_model->oriented_corners.corners[2].y; obstacle_height = top - candidate_model->oriented_corners.corners[0].y; } normals_.clear(); publishNormal(triangle.normal); return contact.handle; }
            }
            publishWorldBounds(subject_bounds);
            if (contact.subject_kind == SphereRender::CollisionKind::AxisAlignedBounds && mode == Mode::Normals && !normals_.empty()) return contact.handle;
            continue;
        }
        if (contact.subject_kind == SphereRender::CollisionKind::Triangles && contact.geometry_kind <= SphereRender::CollisionKind::OrientedBounds) {
            Bounds local_bounds;
            auto candidate_corners = contact.geometry_kind == SphereRender::CollisionKind::AxisAlignedBounds ? contact.bounds.corners() : contact.corners;
            for (auto& point : candidate_corners.corners) point = subject->world_transform.inverseTransformPoint(point);
            candidate_corners.getExtents(local_bounds.minimum, local_bounds.maximum);
            const bool oriented = contact.geometry_kind == SphereRender::CollisionKind::OrientedBounds;
            const Bounds clip_bounds = oriented ? Bounds{{}, candidate_model->oriented_size} : contact.bounds;
            const bool hit = trianglesHitBox(*subject_model, subject->world_transform, clip_bounds, local_bounds, oriented ? &candidate->world_transform : nullptr, oriented ? &candidate_model->bounds_transform : nullptr);
            if (hit) { if (mode != Mode::CollectIgnored) return contact.handle; ignored_.push_back(contact.handle); }
            publishWorldBounds(subject_bounds);
        }
    }
    return 0;
}
std::uint32_t ContactQuery::testMovement(std::uint32_t handle, bool reuse_cache) {
    ignored_.clear();
    return test(handle, Mode::Movement, reuse_cache);
}
bool ContactQuery::lineOfSight(std::uint32_t handle) {
    const auto start = g_sfera_world_objects.object(1u)->position;
    const SferaVec3F end{SceneSky::flare_world_position.x, SceneSky::flare_world_position.y, SceneSky::flare_world_position.z};
    const SferaVec3F upper_end = end + SferaVec3F{0.0f, 0.10000000149011612f, 0.0f};
    auto* object = g_sfera_world_objects.object(handle);
    const auto* model = g_sfera_world_objects.model(*object);
    if (model->collision_kind == SphereRender::CollisionKind::None || (object->extended() && g_sfera_world_objects.extendedObject(handle)->parent_object_handle != 0u)) return true;
    updateBounds(handle);
    Bounds bounds{object->bounds_minimum, object->bounds_maximum};
    SphereRender::ModelCollisionTriangle thickness; thickness.vertices[0] = start; thickness.vertices[1] = end; thickness.vertices[2] = upper_end;
    if (model->collision_kind != SphereRender::CollisionKind::AxisAlignedBounds) { bounds = {{}, model->oriented_size}; for (auto& point : thickness.vertices) point = model->bounds_transform.inverseTransformPoint(object->world_transform.inverseTransformPoint(point)); }
    publishWorldBounds(bounds);
    if (!clippedTriangle(thickness, bounds)) return true;
    if (model->collision_kind != SphereRender::CollisionKind::Triangles) return false;
    const auto local_start = object->world_transform.inverseTransformPoint(start), local_end = object->world_transform.inverseTransformPoint(end);
    SferaVec3F intersection;
    for (std::size_t group_index = 0; group_index < model->collision_groups.size(); ++group_index) { const auto& group = model->collision_groups[group_index]; for (std::size_t index = 0; index < group.triangle_count; ++index) if (intersectTriangle(local_start, local_end, model->collision_triangles[group.first_triangle + index], intersection) == 2) return false; }
    return true;
}
std::uint32_t WorldSpatialIndex::gatherShadowTriangles(const Bounds& bounds, const SferaVec3F& center, float radius, const SferaVec3F& origin, const SferaVec3F& direction) {
    shadow_vertices_.clear();
    const auto append = [this](const SphereRender::ModelCollisionTriangle& triangle) { shadow_vertices_.insert(shadow_vertices_.end(), std::begin(triangle.vertices), std::end(triangle.vertices)); };
    gatherTerrain(center, radius);
    bool full = false;
    for (const auto& candidate : terrain_) { for (std::size_t index = 0; index < candidate.cell->triangles.size(); ++index) { const auto triangle = terrainTriangle(candidate, candidate.cell->triangles[index]); if (!bounds.overlapsTriangle(triangle.vertices) || triangle.normal.dot(direction) < 0.0 || triangle.normal.dot(origin - triangle.vertices[0]) < 0.699999988079071) continue; append(triangle); if (shadow_vertices_.size() / 3u == 300u) { full = true; break; } } if (full) break; }
    if (!full) {
        gatherObjects(center, radius);
        for (const auto handle : objects_) {
            auto* object = g_sfera_world_objects.object(handle);
            const auto* model = g_sfera_world_objects.model(*object);
            if (!model->casts_static_shadow) continue;
            ContactQuery::updateBounds(handle);
            const auto local_origin = object->world_transform.inverseTransformPoint(origin);
            const auto local_direction = rotationOnly(object->world_transform).inverseTransformPoint(direction);
            const auto local_bounds = bounds.inverseTransformed(object->world_transform);
            for (std::size_t group_index = 0; group_index < model->collision_groups.size(); ++group_index) { const auto& group = model->collision_groups[group_index]; for (std::size_t index = 0; index < group.triangle_count; ++index) { const auto& triangle = model->collision_triangles[group.first_triangle + index]; if (!local_bounds.intersects({triangle.minimum, triangle.maximum}) || triangle.normal.dot(local_direction) < 0.0 || triangle.normal.dot(local_origin - triangle.vertices[0]) < 0.699999988079071) continue; append(worldTriangle(triangle, object->world_transform)); if (shadow_vertices_.size() / 3u == 300u) { full = true; break; } } if (full) break; }
            if (full) break;
        }
    }
    const auto camera = g_sfera_world_objects.object(1u)->position;
    for (auto& point : shadow_vertices_) point = point + (camera - point) * 0.014999999664723873f;
    return shadow_vertices_.size() / 3u;
}
}

namespace SphereWorld {

namespace {
    float vegetationRandom(double scale, double offset = 0) { return std::rand() * scale / 32767.0 + offset; }
    std::uint32_t vegetationChoice(std::uint32_t count) { return std::rand() * count / 32768u; }
    float vegetationJitter(float center) { return (std::rand() * 0.5 / 32767.0 - 0.25) * 8.33329963684082 + center; }
    void vegetationError(const std::string& message) { WorldDiagnostics::fail(message); }

}

std::unique_ptr<SphereRender::Model> GrassGeometry::build(std::span<const GrassInstance> instances, float height) {
    using namespace SphereRender;
    std::size_t vertex_count = 0, face_count = 0;
    std::vector<std::vector<std::size_t>> vertex_indices;
    std::vector<std::vector<bool>> consumed;
    std::vector<std::uint16_t> phases;
    for (const auto& instance : instances) {
        if (!instance.model || !instance.model->grass()) { vegetationError(std::string("dg_type parameter not filled in mdlprms.txt for model  ") + (instance.model ? instance.model->name : "<null>")); throw std::runtime_error("Missing grass influences"); }
        for (std::size_t part = 0; part < instance.model->submeshes.size(); ++part) {
            const auto& source = instance.model->submeshes[part];
            if (source.first_vertex > instance.model->vertices.size() || source.vertex_count > instance.model->vertices.size() - source.first_vertex || source.first_face > instance.model->faces.size() || source.face_count > instance.model->faces.size() - source.first_face) throw std::out_of_range("Grass source submesh range");
            if (source.vertex_count > std::numeric_limits<std::size_t>::max() - vertex_count || source.face_count > std::numeric_limits<std::size_t>::max() - face_count) throw std::length_error("Grass geometry is too large");
            vertex_count += source.vertex_count;
            face_count += source.face_count;
        }
        vertex_indices.emplace_back(instance.model->vertices.size(), 0);
        consumed.emplace_back(instance.model->submeshes.size(), false);
    }
    auto result = std::make_unique<Model>();
    result->initializeGrassGeometry(vertex_count, face_count, height);
    for (const auto& instance : instances) {
        for (const auto& catalogue : instance.model->material_lifetimes) {
            if (std::find(result->material_lifetimes.begin(), result->material_lifetimes.end(), catalogue) == result->material_lifetimes.end()) result->material_lifetimes.push_back(catalogue);
        }
    }
    for (std::size_t index = 0; index < instances.size(); ++index) phases.push_back(std::rand());
    constexpr std::size_t maximum_group_vertices = std::size_t{std::numeric_limits<std::uint16_t>::max()} + 1;
    std::vector<Submesh> groups;
    std::vector<std::size_t> instance_indices(vertex_count, 0);
    std::size_t next_vertex = 0, next_face = 0;
    const auto append = [&](std::size_t instance_index, std::size_t submesh_index, Submesh& group) {
        const auto& instance = instances[instance_index];
        const auto& model = *instance.model;
        const auto& source = model.submeshes[submesh_index];
        if (source.vertex_count > maximum_group_vertices - group.vertex_count || next_vertex > vertex_count || source.vertex_count > vertex_count - next_vertex || next_face > face_count || source.face_count > face_count - next_face) throw std::length_error("Grass submesh exceeds its buffers");
        const auto transform = SferaMatrix4x4F::fromEuler(instance.position, instance.rotation);
        consumed[instance_index][submesh_index] = true;
        for (std::size_t index = 0; index < source.vertex_count; ++index) {
            const std::size_t source_index = source.first_vertex + index;
            const std::size_t destination = next_vertex + index;
            result->vertices[destination] = model.vertices[source_index];
            auto& vertex = result->vertices[destination];
            const double source_y = vertex.position.y;
            vertex.position.y = source_y * instance.vertical_scale;
            vertex.position = transform.transformPoint(vertex.position);
            vertex.normal = instance.normal;
            auto& influence = result->grass()->influences[destination];
            influence = model.grass()->influences[source_index];
            influence.phase = influence.phase + phases[instance_index];
            const double source_distance = influence.distance;
            influence.distance = source_distance * instance.vertical_scale;
            instance_indices[destination] = instance_index;
            vertex_indices[instance_index][source_index] = destination;
            const auto& anchor = model.vertices[source_index].position;
            result->grass()->bending[destination].anchor = transform.transformPoint({anchor.x, -0.15000000596046448f, anchor.z});
        }
        for (std::size_t index = 0; index < source.face_count; ++index) {
            auto& face = result->faces[next_face + index];
            face = model.faces[source.first_face + index];
            for (auto& vertex : face.vertices) vertex = vertex + next_vertex - group.first_vertex;
        }
        group.face_count += source.face_count;
        group.vertex_count += source.vertex_count;
        next_vertex += source.vertex_count;
        next_face += source.face_count;
    };
    for (std::size_t instance = 0; instance < instances.size(); ++instance) {
        for (std::size_t submesh = 0; submesh < instances[instance].model->submeshes.size(); ++submesh) {
            if (consumed[instance][submesh]) continue;
            const auto& source = instances[instance].model->submeshes[submesh];
            Submesh group;
            group.bone_index = 0u; group.inverted_fade = source.inverted_fade;
            group.material = source.material;
            group.first_vertex = next_vertex;
            group.first_face = next_face;
            append(instance, submesh, group);
            for (std::size_t other = 0; other < instances.size(); ++other) {
                for (std::size_t part = 0; part < instances[other].model->submeshes.size(); ++part) {
                    const auto& candidate = instances[other].model->submeshes[part];
                    if (!consumed[other][part] && candidate.material == group.material && candidate.inverted_fade == group.inverted_fade && candidate.vertex_count <= maximum_group_vertices - group.vertex_count) append(other, part, group);
                }
            }
            groups.push_back(group);
        }
    }
    for (std::size_t index = 0; index < next_vertex; ++index) {
        auto& influence = result->grass()->influences[index];
        if (influence.anchor_kind == GrassInfluence::Anchor::Vertex) influence.anchor_vertex = vertex_indices[instance_indices[index]].at(influence.anchor_vertex);
    }
    for (std::size_t index = 0; index < next_vertex; ++index) {
        const auto& influence = result->grass()->influences[index];
        if (influence.anchor_kind != GrassInfluence::Anchor::Vertex) continue;
        const auto direction = result->vertices[index].position - result->vertices[influence.anchor_vertex].position;
        auto& basis = result->grass()->bending[index];
        basis.first_axis = (SferaVec3F{0, 0, 1}.cross(direction)).unit<double, float>(0.0f, SferaVec3F{}) * influence.distance;
        basis.second_axis = (direction.cross({1, 0, 0})).unit<double, float>(0.0f, SferaVec3F{}) * influence.distance;
    }
    result->finishGrassGeometry(groups);
    return result;
}

void VegetationPatterns::addGrass(std::uint32_t id, const std::array<std::string_view, 10>& variants) {
    if (grass_patterns_.size() >= 30u) { vegetationError("GRASS_PATTERNS_NUM exeeded"); return; }
    GrassPattern pattern{id, {}};
    std::copy(variants.begin(), variants.end(), pattern.variants.begin());
    grass_patterns_.push_back(std::move(pattern));
}

const VegetationPatterns::GrassPattern& VegetationPatterns::grass(std::uint32_t id) const {
    const auto found = std::find_if(grass_patterns_.begin(), grass_patterns_.end(), [id](const auto& pattern) { return pattern.id == id; });
    if (found == grass_patterns_.end()) { vegetationError("Grass pattern not found. Type=" + std::to_string(id)); throw std::out_of_range("Grass pattern"); }
    return *found;
}

}

void SphereWorld::VegetationPatterns::initializeGrass() {
    grass_patterns_.clear();
    addGrass(1u, {"002", "002", "002", "014", "014", "1_21", "1_41", "", "", ""});
    addGrass(2u, {"018", "018", "018", "006", "003", "1_11", "1_31", "", "", ""});
    addGrass(3u, {"003", "003", "003", "009", "004", "1_21", "1_61", "", "", ""});
    addGrass(4u, {"010", "010", "002", "002", "005", "", "", "", "", ""});
    addGrass(5u, {"009", "009", "009", "004", "000", "1_21", "1_41", "1_41", "", ""});
    addGrass(6u, {"016", "016", "016", "004", "011", "1_11", "1_21", "1_31", "", ""});
    addGrass(7u, {"014", "014", "007", "007", "007", "1_41", "1_51", "", "", ""});
    addGrass(8u, {"013", "013", "013", "005", "004", "", "", "", "", ""});
    addGrass(9u, {"007", "007", "003", "003", "013", "", "", "", "", ""});
    addGrass(10u, {"002", "002", "009", "009", "003", "1_11", "1_31", "", "", ""});
    addGrass(11u, {"012", "012", "005", "005", "013", "", "", "", "", ""});
    addGrass(12u, {"012", "012", "012", "004", "009", "1_61", "", "", "", ""});
    addGrass(13u, {"007", "007", "007", "007", "015", "1_11", "1_21", "1_51", "", ""});
    addGrass(14u, {"017", "017", "017", "005", "005", "", "", "", "", ""});
    addGrass(15u, {"001", "001", "001", "001", "007", "", "", "", "", ""});
    addGrass(16u, {"000", "000", "000", "000", "000", "", "", "", "", ""});
    addGrass(17u, {"000", "000", "000", "000", "000", "", "", "", "", ""});
    addGrass(18u, {"000", "000", "000", "000", "000", "", "", "", "", ""});
    addGrass(19u, {"101", "101", "101", "101", "101", "", "", "", "", ""});
    addGrass(20u, {"102", "102", "102", "102", "102", "", "", "", "", ""});
    addGrass(21u, {"100", "100", "100", "101", "101", "", "", "", "", ""});
    addGrass(22u, {"101", "101", "101", "102", "102", "", "", "", "", ""});
    addGrass(23u, {"100", "100", "100", "102", "102", "", "", "", "", ""});
    addGrass(24u, {"100", "100", "100", "101", "102", "", "", "", "", ""});
    addGrass(25u, {"100", "100", "101", "102", "102", "", "", "", "", ""});
    addGrass(26u, {"101", "101", "101", "101", "101", "", "", "", "", ""});
    addGrass(27u, {"102", "102", "102", "102", "102", "", "", "", "", ""});
    addGrass(28u, {"100", "100", "100", "101", "101", "", "", "", "", ""});
    addGrass(29u, {"101", "101", "101", "102", "102", "", "", "", "", ""});
    addGrass(30u, {"100", "100", "100", "102", "102", "", "", "", "", ""});
}

namespace SphereWorld {

DynamicVegetation::DynamicVegetation(std::span<GrassCell> cells) : cells_(cells) {
    initializeNoise();
}

std::int64_t DynamicVegetation::last_update_ = 0;

void DynamicVegetation::initializeNoise() {
    struct Harmonic { double frequency; float phase; double amplitude; };
    std::array<Harmonic, 100> harmonics;
    for (std::size_t index = 0; index < harmonics.size(); ++index) {
        auto& harmonic = harmonics[index];
        harmonic.frequency = index + 1;
        harmonic.phase = vegetationRandom(6.2831854820251465);
        harmonic.amplitude = vegetationRandom(1, 1);
    }
    float maximum = -1.0f;
    for (std::size_t index = 0; index < noise_.size(); ++index) {
        const float angle = index * 0.006135923322290182;
        float sum = 0.0f;
        for (const auto& harmonic : harmonics) {
            const float rounded_phase = harmonic.frequency * angle + harmonic.phase;
            const double phase = rounded_phase;
            const float sine = std::sin(phase);
            sum = sine * harmonic.amplitude + sum;
        }
        noise_[index] = sum;
        maximum = std::max(maximum, std::fabs(sum));
    }
    const float rounded_scale = 1.0 / maximum;
    const double scale = rounded_scale;
    for (auto& value : noise_) value *= scale;
}

void DynamicVegetation::initializeWind() { wind_ = {0.7070000171661377f, 0, 0.7070000171661377f}; wind_strength_ = 0.4000000059604645f; }
void DynamicVegetation::setReference(const SferaVec3F& position) { reference_ = position; }

void DynamicVegetation::updateWind(const SferaVec3F& reference, float elapsed) {
    const double strength = wind_strength_, windX = wind_.x, windZ = wind_.z;
    phase_speed_ = strength * 2 + 1;
    bend_x_ = windX * strength * 0.30000001192092896;
    bend_z_ = windZ * strength * 0.30000001192092896;
    for (auto& gust : gusts_) {
        const float dx = gust.x - reference.x, dz = gust.z - reference.z;
        if (!gust.active || SferaMath::planarSquared(dx, dz) > 2600.0) {
            gust.active = true;
            gust.speed = vegetationRandom(0.5, 1.5);
            const float transverse = vegetationRandom(40, -20);
            gust.x = reference.x - windX * 30 - windZ * transverse;
            gust.z = reference.z - windZ * 30 + windX * transverse;
            gust.radius = vegetationRandom(4, 2);
            const double radius = gust.radius;
            gust.radius_squared = radius * radius;
        }
        gust.x = windX * wind_strength_ * gust.speed * elapsed * 4 + gust.x;
        gust.z = windZ * wind_strength_ * gust.speed * elapsed * 4 + gust.z;
    }
}

SferaVec3F DynamicVegetation::bendingPosition(const SphereRender::Model& model, std::size_t vertex, float first, float second) const {
    const auto& influence = model.grass()->influences[vertex];
    const auto& basis = model.grass()->bending[vertex];
    const auto& anchor = model.vertices[influence.anchor_vertex].position;
    const auto displacement = ((model.vertices[vertex].position - anchor) + basis.first_axis * first) + basis.second_axis * second;
    return (displacement).unit<double, float>(0.0f, SferaVec3F{}) * influence.distance + anchor;
}

void DynamicVegetation::deformGrass(SphereRender::Model& model, const SferaVec3F& position) {
    if (!model.grass()) return;
    output_.resize(model.vertices.size());
    const double animation_phase = phase_;
    std::vector<const Gust*> gusts;
    for (const auto& gust : gusts_) if (gust.active && position.x + 8 > gust.x - gust.radius && position.x - 8 < gust.x + gust.radius && position.z + 8 > gust.z - gust.radius && position.z - 8 < gust.z + gust.radius) gusts.push_back(&gust);
    const Gust* selected_gust = nullptr;
    for (std::size_t index = 0; index < model.vertices.size(); ++index) {
        const auto& vertex = model.vertices[index];
        const auto& influence = model.grass()->influences[index];
        auto& output = output_[index];
        output = {vertex.position, vertex.normal};
        if (influence.anchor_kind == SphereRender::GrassInfluence::Anchor::Fixed) continue;
        if (!influence.share_phase) {
            selected_gust = nullptr;
            for (const auto* gust : gusts) {
                const float dx = vertex.position.x - (gust->x - position.x), dz = vertex.position.z - (gust->z - position.z);
                if (SferaMath::planarSquared(dx, dz) < gust->radius_squared) { selected_gust = gust; break; }
            }
        }
        if (influence.anchor_kind == SphereRender::GrassInfluence::Anchor::Horizontal) {
            const int step = std::trunc(animation_phase * phase_speed_);
            const int phase = step + influence.phase;
            const double noise = noise_[phase & 1023];
            const float factor = (noise + 1) * 0.5 * (selected_gust ? 0.25 : 0.15000000596046448) * phase_speed_;
            output.position = vertex.position + (model.grass()->bending[index].anchor - vertex.position) * factor;
            if (selected_gust) output.normal = output.normal * 0.800000011920929f;
        } else {
            const int step = std::trunc(animation_phase * phase_speed_ * (selected_gust ? -3.0 : 1.0));
            const int phase = influence.phase + (selected_gust ? -step : step);
            const float first = noise_[phase & 1023] * 0.05999999865889549 * phase_speed_ + (selected_gust ? bend_x_ : 0);
            const float second = noise_[(phase - 512) & 1023] * 0.05999999865889549 * phase_speed_ * 0.5 + (selected_gust ? bend_z_ : 0);
            output.position = bendingPosition(model, index, first, second);
            if (selected_gust) output.normal = output.normal * 0.75f;
        }
        if (!model.cached_vegetation_vertices.empty()) output.position = model.cached_vegetation_vertices[index].position + (output.position - model.cached_vegetation_vertices[index].position) * 0.15000000596046448f;
    }
}

void DynamicVegetation::saveCache(SphereRender::Model& model) {
    if (output_.size() != model.vertices.size()) throw std::logic_error("Vegetation cache does not match model geometry");
    model.cached_vegetation_vertices = output_;
}

void DynamicVegetation::recalculate() {
    for (const auto& cell : cells_) {
        if (cell.object_handle == 0u) continue;
        const auto* object = g_sfera_world_objects.object(cell.object_handle);
        auto* model = object ? g_sfera_world_objects.model(*object) : nullptr;
        if (model == nullptr) continue;
        deformGrass(*model, object->position);
        saveCache(*model);
    }
}

void DynamicVegetation::update() {
    const std::int64_t now = WorldClock::nowTicks();
    const float frame_interval = (now - last_update_) / 2000.0;
    const float elapsed = std::min(2.0f, frame_interval);
    last_update_ = now;
    const double advance = elapsed;
    phase_ += advance;
    updateWind(reference_, elapsed);
    recalculate();
}

void Vegetation::initialize() {
    std::vector<GrassCell> cells(grid_side * grid_side), previous(cells.size());
    std::vector<std::array<bool, 2>> occupancy(cells.size());
    VegetationPatterns nextPatterns;
    nextPatterns.initializeGrass();
    auto nextAnimation = std::make_unique<DynamicVegetation>(cells);
    animation.reset();
    cells_ = std::move(cells);
    previous_ = std::move(previous);
    occupancy_ = std::move(occupancy);
    patterns = std::move(nextPatterns);
    animation = std::move(nextAnimation);
    last_cell_x_ = last_cell_z_ = 100000;
}

void Vegetation::clear() {
    animation.reset();
    cells_.clear();
    previous_.clear();
    occupancy_.clear();
}

void Vegetation::destroyOwnedModel(std::uint32_t& handle) {
    if (!handle) return;
    g_sfera_world_objects.destroy(handle);
    handle = 0;
}

bool Vegetation::alternatePatterns() { const auto* reference = g_sfera_world_objects.object(1); return TerrainAssets::high_resolution_assets && reference->position.y > 300 && reference->position.y < 800; }

void Vegetation::createCell(int cell_x, int cell_z, GrassCell& cell) {
    std::array<GrassInstance, 36> placements{};
    const float origin_x = cell_x * 8.33329963684082, origin_z = cell_z * 8.33329963684082;
    const std::array<std::array<float, 2>, 4> samples{{{6.24f, 3.73f}, {2.21f, 1.17f}, {2.21f, 5.60f}, {6.24f, 7.15f}}};
    std::array<std::uint32_t, 3> color{};
    std::array<std::size_t, 36> model_handles{};
    const VegetationPatterns::GrassPattern* last_pattern = nullptr;
    std::size_t count = 0;
    bool scattered = false;
    cell.object_handle = 0;
    for (const auto& sample : samples) {
        const float x = origin_x + sample[0], z = origin_z + sample[1];
        std::array<std::uint32_t, 3> local_color{};
        TerrainQueries::sampleColor(x, z, local_color[0], local_color[1], local_color[2]);
        for (std::size_t channel = 0; channel < 3; ++channel) color[channel] += local_color[channel];
        auto type = g_sfera_vegetation.map_cache.grassType(x, z);
        if (!type) continue;
        if (alternatePatterns()) type += 15;
        last_pattern = &patterns.grass(type);
        SferaVec3F angles{};
        SferaPlaneF plane{};
        float height = 0;
        if (TerrainQueries::placementOrientation(x, z, angles, height, plane) == 1u) {
            const auto name = "grass" + last_pattern->variants[vegetationChoice(5)];
            model_handles[count] = g_sfera_models.find(name);
            placements[count++] = {nullptr, {x, height, z}, angles, 1, plane.normal};
        } else {
            for (std::uint32_t attempt = 0; attempt < 8u; ++attempt) {
                const float dx = vegetationJitter(x);
                const float dz = vegetationJitter(z);
                if (!TerrainQueries::surface(dx, dz, height, plane)) continue;
                scattered = true;
                const auto name = std::format("grass_s0{}", vegetationChoice(4));
                model_handles[count] = g_sfera_models.find(name);
                auto& instance = placements[count++];
                instance.model = nullptr;
                instance.position = {dx, height, dz};
                instance.vertical_scale = vegetationRandom(0.5, 0.6000000238418579);
                const float tilt = 0.3141593337059021 - instance.vertical_scale * 0.1745329648256302;
                instance.rotation.x = vegetationRandom(6.283185958862305);
                instance.rotation.y = vegetationRandom(tilt);
                instance.rotation.z = vegetationRandom(tilt);
                instance.normal = plane.normal;
            }
        }
    }
    for (auto& channel : color) channel /= 4u;
    if (count == 4u && !scattered) {
        const auto attempts = vegetationChoice(20);
        for (std::uint32_t attempt = 0; attempt < attempts; ++attempt) {
            const float x = vegetationRandom(8.33329963684082, origin_x), z = vegetationRandom(8.33329963684082, origin_z);
            SferaPlaneF plane{};
            float height = 0;
            if (!TerrainQueries::surface(x, z, height, plane)) continue;
            const auto& variant = last_pattern->variants[vegetationChoice(5) + 5];
            if (variant.empty()) continue;
            const auto name = "flower" + variant;
            model_handles[count] = g_sfera_models.find(name);
            placements[count++] = {nullptr, {x, height, z}, {vegetationRandom(6.283185958862305), 0, 0}, 1, plane.normal};
        }
    }
    if (!count) return;
    float minimum = placements[0].position.y, maximum = minimum;
    for (std::size_t index = 1; index < count; ++index) { minimum = std::min(minimum, placements[index].position.y); maximum = std::max(maximum, placements[index].position.y); }
    const double precise_maximum = maximum;
    maximum = precise_maximum + 1;
    minimum = minimum - 2.5;
    const SferaVec3F center{origin_x + 4.16664981842041f, maximum, origin_z + 4.16664981842041f};
    for (std::size_t index = 0; index < count; ++index) { placements[index].position = placements[index].position - center; placements[index].model = g_sfera_models.model(model_handles[index]); }
    auto model = GrassGeometry::build(std::span<const GrassInstance>(placements.data(), count), maximum - minimum);
    const auto handle = g_sfera_world_objects.create("grass1_21", 0, 0, false);
    auto* object = g_sfera_world_objects.object(handle);
    if (object == nullptr) return;
    object->model_source = std::move(model);
    object->position = center;
    object->rotation = {};
    object->visible = false;
    object->lighting_color = SferaColor::rgba(SphereRender::SceneRenderer::color_remap[color[0]], SphereRender::SceneRenderer::color_remap[color[1]], SphereRender::SceneRenderer::color_remap[color[2]]).argb();
    try { g_sfera_world_objects.updateSpatialIndex(handle); }
    catch (...) { g_sfera_world_objects.destroy(handle); throw; }
    cell.object_handle = handle;
}

void Vegetation::updateCells() {
    if (++update_phase_ < 5u) return;
    update_phase_ = 0;
    const std::uint32_t depth = g_sfera_graphics_runtime.grass_depth;
    const bool enabled = depth != 0 && previous_depth_ == 0;
    const bool disabled = depth == 0 && previous_depth_ != 0;
    previous_depth_ = depth;
    const auto side = grid_side;
    const auto count = side * side;
    auto* cells = cells_.data();
    if (cells_.empty()) return;
    if (disabled) for (std::uint32_t index = 0; index < count; ++index) destroyOwnedModel(cells[index].object_handle);
    if (!depth) return;
    const auto& position = g_sfera_world_objects.object(1)->position;
    g_sfera_vegetation.animation->setReference(position);
    if (enabled) { last_cell_x_ = 1000000; last_cell_z_ = 1000000; }
    const auto x = SferaNumeric::truncateInt(position.x * 0.11999999731779099 + 100000.0) - 100000;
    const auto z = SferaNumeric::truncateInt(position.z * 0.11999999731779099 + 100000.0) - 100000;
    const auto dx = x - last_cell_x_, dz = z - last_cell_z_;
    if (!dx && !dz) return;
    auto* previous = previous_.data();
    auto* occupancy = occupancy_.data();
    std::copy_n(cells, count, previous);
    std::fill_n(occupancy, count, std::array<bool, 2>{});
    if (std::abs(dx) <= 1 && std::abs(dz) <= 1) {
        for (int row = 0; row < side; ++row) {
            for (int column = 0; column < side; ++column) {
                const auto source_x = column + dx, source_z = row + dz;
                if (source_x < 0 || source_z < 0 || source_x >= side || source_z >= side) continue;
                const auto source = source_z * side + source_x, destination = row * side + column;
                cells[destination] = previous[source];
                occupancy[source][0] = 1;
                occupancy[destination][1] = 1;
            }
        }
    }
    for (std::uint32_t index = 0; index < count; ++index) if (!occupancy[index][0]) destroyOwnedModel(previous[index].object_handle);
    const int half = (side - 1u) / 2u;
    for (std::uint32_t row = 0; row < side; ++row) for (std::uint32_t column = 0; column < side; ++column) { const auto index = row * side + column; if (!occupancy[index][1]) createCell(x - half + column, z - half + row, cells[index]); }
    last_cell_x_ = x;
    last_cell_z_ = z;
}

void Vegetation::updateGrassView() {
    const double factor = g_sfera_weather_runtime.current.wind;
    const double direction_x = g_sfera_weather_runtime.current.windX, direction_z = g_sfera_weather_runtime.current.windZ;
    float shift_x = 0, shift_z = 0;
    if (factor <= 1) { shift_x = direction_x * factor; shift_z = direction_z * factor; }
    else {
        const float squared = SferaMath::planarSquared(direction_x, direction_z);
        const float length = std::sqrt(squared);
        if (std::fabs(length) >= 0.000009999999747378752f) {
            const float distance = (factor - 1) * (0.00019999999494757503 - length) + length;
            shift_x = direction_x / length * distance;
            shift_z = direction_z / length * distance;
        }
    }
    auto& x = SceneSky::cloud_offset_x;
    auto& z = SceneSky::cloud_offset_y;
    x += shift_x;
    z += shift_z;
    if (x >= 1) x -= 1;
    if (x < 0) x += 1;
    if (z >= 1) z -= 1;
    if (z < 0) z += 1;
    if (g_sfera_vegetation.animation && g_sfera_graphics_runtime.grass_depth == 2) g_sfera_vegetation.animation->initializeWind();
}

}

std::uint8_t GrassMapMngr::sample(float x, float z) {
    if (!std::isfinite(x) || !std::isfinite(z) || x < -4002.0f || x > 4002.0f || z < -4002.0f || z > 4002.0f) return 0;
    const int column = std::trunc((x + 4000.0) * 0.5120000243186951);
    const int row = std::trunc((4000.0 - z) * 0.5120000243186951);
    if (column > 4095u || row > 4095u) return 0;
    if (!tiles_) tiles_ = std::make_unique<std::array<Tile, 10>>();
    const auto key = std::pair{column / 256, row / 256};
    if (timestamp_ == UINT64_MAX) { for (auto& tile : *tiles_) tile.timestamp = 0; timestamp_ = 0; }
    ++timestamp_;
    auto found = std::find_if(tiles_->begin(), tiles_->end(), [key](const auto& tile) { return tile.timestamp != 0 && tile.key == key; });
    if (found == tiles_->end()) {
        found = std::min_element(tiles_->begin(), tiles_->end(), [](const auto& left, const auto& right) { return left.timestamp < right.timestamp; });
        auto replacement = std::make_unique<Tile>();
        replacement->key = key;
        loadGrassMap(key.first, key.second, replacement->bytes);
        *found = std::move(*replacement);
    }
    found->timestamp = timestamp_;
    return found->bytes[(row & 255) * 256 + (column & 255)];
}

std::uint32_t GrassMapMngr::grassType(float x, float z) { return sample(x, z) & 15u; }
std::uint32_t GrassMapMngr::plantingType(float x, float z) { return (sample(x, z) >> 4u) & 3u; }
GrassMapMngr* GrassMapMngr::reset() { tiles_.reset(); timestamp_ = 0; return this; }

namespace {
    SferaVec3F terrainAnchor() { return {g_sfera_terrain_renderer.patch_origin.x, g_sfera_terrain_renderer.patch_origin.y, g_sfera_terrain_renderer.patch_origin.z}; }
    TerrainRegion& terrainRegionAt(int mapIndex) { return *TerrainAssets::map[mapIndex].region; }
    TerrainPatch& terrainPatchAt(int mapIndex, bool refresh = true) { auto& region = terrainRegionAt(mapIndex); const auto& record = TerrainAssets::map[mapIndex]; if (refresh) region.touchPatch(record.tile_x, record.tile_y); else region.loadPatch(record.tile_x, record.tile_y); return *region.patch(record.tile_x, record.tile_y); }

    SferaPlaneF terrainPlane(const SferaVec3F& normal, const SferaVec3F& point) { return SferaPlaneF::throughPoint(normal, point); }
    int terrainPatchCoordinate(double value) { return SferaNumeric::truncateInt(value / 100.0 + 1000.0) - 1000; }
    void terrainSetState(D3DRENDERSTATETYPE state, DWORD value) { auto& device = *g_sfera_graphics_runtime.d3d_runtime; device.checkResult(device.native_device->SetRenderState(state, value), "SetRenderState"); }
    void terrainSetTexture(std::uint32_t stage, IDirect3DBaseTexture9* texture) { auto& device = *g_sfera_graphics_runtime.d3d_runtime; device.checkResult(device.native_device->SetTexture(stage, texture), "SetTexture"); }
}
bool TerrainQueries::Location::valid() const { return patchX >= -40 && patchX < 40 && patchZ >= -40 && patchZ < 40; }
int TerrainQueries::Location::cellIndex() const { const int quarter = (cellZ / 6) * 2 + cellX / 6; const int group = (cellZ / 3 % 2) * 2 + cellX / 3 % 2; return (quarter * 4 + group) * 9 + (cellZ % 3) * 3 + cellX % 3; }
TerrainQueries::Location TerrainQueries::locate(float worldX, float worldZ) {
    constexpr double grid_scale = 0.12f;
    const int x = SferaNumeric::truncateInt(worldX * grid_scale + 100000.0) + 20000;
    const int z = SferaNumeric::truncateInt(worldZ * grid_scale + 100000.0) + 20000;
    const int patchX = x / 12 - 10000, patchZ = z / 12 - 10000;
    return {patchX, patchZ, x % 12, z % 12, (patchX + 40) * 80 + 39 - patchZ};
}
void TerrainQueries::sampleColor(float worldX, float worldZ, std::uint32_t& red, std::uint32_t& green, std::uint32_t& blue) {
    static constexpr auto fiveBitToEightBit = [] {
        std::array<std::uint32_t, 32> result{};
        for (std::size_t value = 0; value < result.size(); ++value) {
            result[value] = value * 255u / 31u;
        }
        return result;
    }();
    red = green = blue = 0u;
    const auto location = locate(worldX, worldZ);
    if (!location.valid()) return;
    terrainPatchAt(location.mapIndex);
    auto& region = terrainRegionAt(location.mapIndex);
    const auto& record = TerrainAssets::map[location.mapIndex];
    const double precise_world_x = worldX, precise_world_z = worldZ;
    const float localX = precise_world_x - location.patchX * 100, localZ = precise_world_z - location.patchZ * 100;
    const int pixelX = std::clamp(SferaNumeric::truncateInt(localX / 100.0 * 254.0 + 1.0) + 2, 0, 255), pixelZ = std::clamp(SferaNumeric::truncateInt(localZ / 100.0 * 254.0 + 1.0) + 2, 0, 255);
    const auto& pixels = region.slots[record.tile_x * 10 + record.tile_y].texture->pixels;
    const std::uint16_t color = pixels[pixelZ * 256 + pixelX];
    red = fiveBitToEightBit[color >> 11];
    green = fiveBitToEightBit[(color >> 6) & 31u];
    blue = fiveBitToEightBit[color & 31u];
}
bool TerrainQueries::surface(float worldX, float worldZ, float& height, SferaPlaneF& plane) {
    const auto location = locate(worldX, worldZ);
    if (!location.valid()) return false;
    auto& patch = terrainPatchAt(location.mapIndex, false);
    const auto& cell = patch.cells[location.cellIndex()];
    const double precise_world_x = worldX, precise_world_z = worldZ;
    const float localX = precise_world_x - location.patchX * 100, localZ = precise_world_z - location.patchZ * 100;
    for (std::size_t index = 0; index < cell.triangles.size(); ++index) {
        const auto& triangle = cell.triangles[index];
        const std::array<const SferaVec3F*, 3> points = {&patch.vertices[triangle.indices[0]].position, &patch.vertices[triangle.indices[1]].position, &patch.vertices[triangle.indices[2]].position};
        const auto localPlane = terrainPlane(triangle.normal, *points[0]);
        SferaVec3F intersection;
        if (localPlane.intersectLine({localX, -10000.0f, localZ}, {localX, -9000.0f, localZ}, intersection) != 1 || !triangle.normal.containsConvexPolygonPoint(points, intersection)) continue;
        height = intersection.y;
        plane = localPlane;
        const double point_x = points[0]->x, point_y = points[0]->y, point_z = points[0]->z;
        plane.distance = -(point_x + location.patchX * 100) * triangle.normal.x - point_y * triangle.normal.y - (point_z + location.patchZ * 100) * triangle.normal.z;
        return true;
    }
    return false;
}
std::uint8_t TerrainQueries::placementOrientation(float worldX, float worldZ, SferaVec3F& angles, float& height, SferaPlaneF& plane) {
    if (!surface(worldX, worldZ, height, plane) || std::fabs(plane.normal.y) < 0.75f) return 0u;
    const double radius = 2.45f;
    const float diagonal_root = std::sqrt(2.0);
    const float diagonal = radius / diagonal_root;
    const double x = worldX, z = worldZ;
    const std::array<std::array<double, 2>, 8> samples = {{{x + radius, z}, {x, z + radius}, {x - radius, z}, {x, z - radius},
        {x + diagonal, z + diagonal}, {x - diagonal, z - diagonal}, {x + diagonal, z - diagonal}, {x - diagonal, z + diagonal}}};
    std::array<float, 8> heights;
    SferaPlaneF samplePlane;
    for (std::size_t index = 0; index < samples.size(); ++index) if (!surface(samples[index][0], samples[index][1], heights[index], samplePlane)) return 0u;
    for (std::size_t index = 0; index < samples.size(); ++index) {
        const float predicted = (-samples[index][1] * plane.normal.z - samples[index][0] * plane.normal.x - plane.distance) / plane.normal.y;
        const double actual = heights[index];
        const float difference = actual - predicted;
        if (std::fabs(difference) > 0.5f) return 0u;
    }
    float rotatedY = plane.normal.y;
    const double normalX = plane.normal.x, normalY = plane.normal.y, normalZ = plane.normal.z;
    if (SferaMath::planarSquared(normalX, normalY) > 1e-6) {
        const float azimuth = std::atan2(normalY, normalX);
        angles.z = 4.7123894691467285 - azimuth;
        const auto [sine, cosine] = SferaMath::rotationTerms(angles.z);
        rotatedY = sine * normalX + cosine * normalY;
    } else angles.z = 0.0f;
    const double rotated = rotatedY;
    const float inclination = std::atan2(rotated, normalZ);
    angles.y = 4.7123894691467285 - inclination;
    const double randomAngle = std::rand() * 3.1415929794311523;
    angles.x = (randomAngle + randomAngle) / 32767.0;
    angles.y = -angles.y;
    angles.z = -angles.z;
    return 1u;
}
bool TerrainQueries::clearViewToFlare(const TerrainPatch& patch, const TerrainCell& cell) {
    const auto anchor = terrainAnchor();
    const auto& source = g_sfera_world_objects.object(1)->position;
    const SferaVec3F destination = {SceneSky::flare_world_position.x, SceneSky::flare_world_position.y, SceneSky::flare_world_position.z};
    for (std::size_t index = 0; index < cell.triangles.size(); ++index) {
        const auto& triangle = cell.triangles[index];
        std::array<SferaVec3F, 3> positions;
        for (std::size_t corner = 0; corner < positions.size(); ++corner) {
            const auto& original = patch.vertices[triangle.indices[corner]].position;
            positions[corner] = original + SferaVec3F{anchor.x, 0.0f, anchor.z};
            positions[corner].y = original.y;
        }
        const auto plane = terrainPlane(triangle.normal, positions[0]);
        SferaVec3F intersection;
        const std::array<const SferaVec3F*, 3> points = {&positions[0], &positions[1], &positions[2]};
        if (plane.intersectLine(source, destination, intersection) == 1 && plane.normal.containsConvexPolygonPoint(points, intersection)) return false;
    }
    return true;
}
void TerrainTextureCache::blendLayer(const TerrainCell& cell, int layer, TerrainTextureImage& texture) {
    if (layer < 0 || layer >= cell.layers.size()) throw std::out_of_range("Landscape microtexture layer");
    const auto* mask = cell.masks.data() + layer * 24 * 24;

    for (int y = 0; y < 256; ++y) {
        const int maskRow = TerrainTextureCache::quantization_x[cell.z * 256 + y] * 24;
        const auto* blendRow = TerrainTextureCache::blend_lut + TerrainTextureCache::quantization_y[cell.z * 256 + y] * 256;
        for (int x = 0; x < 256; ++x) {
            const int maskIndex = maskRow + TerrainTextureCache::quantization_x[cell.x * 256 + x];
            const auto* weights = blendRow + TerrainTextureCache::quantization_y[cell.x * 256 + x] * 4;
            const int alpha = std::min(255, (mask[maskIndex] * weights[0] + mask[maskIndex + 1] * weights[1] + mask[maskIndex + 24] * weights[2] + mask[maskIndex + 25] * weights[3]) >> 8);
            auto& pixel = texture.pixels[y * TerrainTextureImage::width + x];
            pixel = SferaColor::fromArgb4444(pixel).withAlpha(alpha).argb4444();
        }
    }
}
void TerrainTextureCache::bindLayer(const TerrainCell& cell, int layer) {
    auto& entries = TerrainTextureCache::entries;
    const auto owner = &cell;
    auto entry = std::find_if(entries.begin(), entries.end(), [&](const auto& candidate) { return candidate.owner == owner && candidate.kind == layer; });
    if (entry != entries.end()) { terrainSetTexture(0u, entry->resource.Get()); entry->use_count = 0u; return; }
    entry = std::max_element(entries.begin(), entries.end(), [](const auto& first, const auto& second) { return first.use_count < second.use_count; });
    entry->owner = nullptr;
    auto* source = TerrainAssets::microtextures.at(cell.layers[layer]).image.get();
    if (source == nullptr) throw std::runtime_error("Missing landscape microtexture");
    blendLayer(cell, layer, *source);
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    TextureMapping mapping(entry->resource.Get(), 0, D3DLOCK_NOSYSLOCK);
    device.checkResult(mapping.status(), "LockRect(terrain)");
    const auto& description = mapping.description();
    if (description.Width != 256 || description.Height != 256) {
        WorldDiagnostics::fail("BeginDraw has returned texture size != 256x256");
    }
    device.checkResult(mapping.copyRows(std::as_bytes(std::span(source->pixels)),
        TerrainTextureImage::width * sizeof(source->pixels[0]), TerrainTextureImage::height), "Upload terrain pixels");
    device.checkResult(mapping.unlock(), "UnlockRect(terrain)");
    entry->owner = owner;
    entry->kind = layer;
    entry->use_count = 0;
    terrainSetTexture(0u, entry->resource.Get());
}
void TerrainTextureCache::release() {
    for (auto& entry : TerrainTextureCache::entries) entry = {};
}

bool TerrainRenderer::visibleBounds(const TerrainBounds& source, const SferaVec3F& anchor, SferaViewProjectionScratchRuntime& translated) {
    SferaViewProjectionScratchRuntime local;
    std::copy(std::begin(source.corners), std::end(source.corners), local.corners);
    local.clipping_bounds = {source.scaledBounds[0], source.scaledBounds[1], source.scaledBounds[2], source.scaledBounds[3], source.scaledBounds[4], source.scaledBounds[5]};
    translated = local.translated(anchor);
    SphereRender::SceneRenderer::clipped_terrain_bounds = translated.clipping_bounds;
    const auto& view = SphereRender::SceneRenderer::projected_terrain_bounds;
    const auto& bounds = translated.clipping_bounds;
    if (view.max_x < bounds.min_x || view.min_x > bounds.max_x || view.max_y < bounds.min_y || view.min_y > bounds.max_y || view.max_z < bounds.min_z || view.min_z > bounds.max_z) return false;
    SferaFrustumF frustum;
    frustum = SphereRender::SceneRenderer::frustum;
    return frustum.classifyPoints(translated.corners) != 0;
}
bool TerrainRenderer::gatherCells(TerrainPatch& patch) {
    const auto anchor = terrainAnchor();
    SferaViewProjectionScratchRuntime translated;
    if (!visibleBounds(patch.bounds, anchor, translated)) return false;
    visibleCells.clear();
    visibleCells.reserve(144u);
    for (int quarter = 0; quarter < 4; ++quarter) {
        if (!visibleBounds(patch.quarterBounds[quarter], anchor, translated)) continue;
        for (int group = 0; group < 4; ++group) {
            const int groupIndex = quarter * 4 + group;
            if (!visibleBounds(patch.groupBounds[groupIndex], anchor, translated)) continue;
            for (int cell = 0; cell < 9; ++cell) {
                const int cellIndex = groupIndex * 9 + cell;
                if (!visibleBounds(patch.cellBounds[cellIndex], anchor, translated)) continue;
                TerrainVisibleCell visible{&patch.cells[cellIndex], {}};
                std::copy(std::begin(translated.corners), std::end(translated.corners), visible.bounds.corners);
                visibleCells.push_back(visible);
            }
        }
    }
    return true;
}
void TerrainRenderer::findReflectiveWater(TerrainPatch& patch) {
    if (!gatherCells(patch)) return;
    const auto& position = g_sfera_world_objects.object(1)->position;
    for (const auto& visible : visibleCells) {
        const auto& water = patch.waters[visible.cell->x + visible.cell->z * 12];
        if (water.material == 0u || !(g_sfera_graphics_runtime.water_materials.at(water.material).reflection_opacity > 0.001f)) continue;
        const float distance = ((position) - (visible.bounds.corners[0])).length();
        if (!(SphereRender::SceneRenderer::reflection_distance > distance)) continue;
        SphereRender::SceneRenderer::reflection_distance = distance;
        SphereRender::SceneRenderer::reflection_height = water.height;
    }
}
void TerrainRenderer::visitPatches(bool draw) {
    const auto& position = g_sfera_world_objects.object(1)->position;
    const double radius = SphereRender::SceneRenderer::view_distance;
    const int firstX = terrainPatchCoordinate(position.x - radius), lastX = terrainPatchCoordinate(position.x + radius);
    const int firstZ = terrainPatchCoordinate(position.z - radius), lastZ = terrainPatchCoordinate(position.z + radius);
    for (int x = firstX; x <= lastX; ++x) for (int z = firstZ; z <= lastZ; ++z) {
        g_sfera_terrain_renderer.patch_origin = {{x * 100.0f}, {0.0f}, {z * 100.0f}};
        if (x < -40 || x >= 40 || z < -40 || z >= 40) continue;
        const int mapIndex = (x + 40) * 80 + 39 - z;
        auto& patch = terrainPatchAt(mapIndex);
        if (draw) { const auto& record = TerrainAssets::map[mapIndex]; SphereRender::SceneRenderer::terrain_texture = terrainRegionAt(mapIndex).slots[record.tile_x * 10 + record.tile_y].texture_id; prepareAndDraw(patch); } else findReflectiveWater(patch);
    }
}
void TerrainRenderer::gatherReflectiveWater() { visitPatches(false); }
void TerrainRenderer::drawLandscape() {
    waterSurfaces.clear();

    g_sfera_light_runtime.setDirectionalLight({-SphereRender::SceneRenderer::sun_direction.x, -SphereRender::SceneRenderer::sun_direction.y, -SphereRender::SceneRenderer::sun_direction.z}, {SphereRender::SceneRenderer::environment.sunColor.x, SphereRender::SceneRenderer::environment.sunColor.y, SphereRender::SceneRenderer::environment.sunColor.z});
    const auto identity = SferaMatrix4x4F::identity();
    g_sfera_graphics_runtime.d3d_runtime->setTransform(D3DTS_WORLD, identity);
    visitPatches(true);
    for (auto& entry : TerrainTextureCache::entries) ++entry.use_count;
}
void TerrainRenderer::prepareAndDraw(TerrainPatch& patch) {
    if (!gatherCells(patch) || visibleCells.empty()) return;
    const auto& position = g_sfera_world_objects.object(1)->position;
    const auto anchor = terrainAnchor();
    const auto* lights = g_sfera_light_runtime.visible_handles.data();
    for (const auto& visible : visibleCells) {
        auto& group = patch.surfaceGroups[visible.cell->x + visible.cell->z * 12];
        const auto& minimum = visible.bounds.corners[2];
        const auto& maximum = visible.bounds.corners[5];
        group.light_mask = 0u; group.distant = false;
        std::uint32_t bit = 1u;
        int count = 0;
        for (std::uint32_t index = 0; index < g_sfera_light_runtime.visible_handles.size(); ++index, bit += bit) { const auto& light = *lights[index]; if (light.bounds_min.x < maximum.x && light.bounds_min.y < maximum.y && light.bounds_min.z < maximum.z && light.bounds_max.x > minimum.x && light.bounds_max.y > minimum.y && light.bounds_max.z > minimum.z) { group.light_mask |= bit; if (++count == 7) break; } }
        if (std::all_of(std::begin(visible.bounds.corners), std::end(visible.bounds.corners), [&](const auto& corner) { return ((position) - (corner)).length() > 50.0f; })) group.distant = true;
        const auto& water = patch.waters[visible.cell->x + visible.cell->z * 12];
        if (water.material != 0u) { const int x = SferaNumeric::truncateInt((anchor.x + 4.0) / 8.333333015441895 + 10000.0) + visible.cell->x - 10000, z = SferaNumeric::truncateInt((anchor.z + 4.0) / 8.333333015441895 + 10000.0) + visible.cell->z - 10000; waterSurfaces.push_back({x, z, water.height, group.light_mask, water.material, visible.bounds}); }
    }

    std::size_t first = 0u;
    std::uint32_t vertices = 0u;
    for (std::size_t index = 0; index < visibleCells.size(); ++index) {
        const auto& cell = *visibleCells[index].cell;
        const auto count = patch.surfaceGroups[cell.x + cell.z * 12].vertexCount;
        vertices += count;
        if (vertices > 30000u) {
            if (index > first) drawCells(patch, first, index - 1u);
            first = index;
            vertices = count;
        }
    }
    if (!visibleCells.empty()) drawCells(patch, first, visibleCells.size() - 1u);
}
namespace {
    void terrainSubmitIndices(CD3D9Device& device, std::span<const std::uint16_t> indices,
        IDirect3DVertexBuffer9* vertices, bool lit, std::size_t baseVertex, std::size_t vertexCount) {
        auto output = device.indices_secondary.lock(indices.size());
        std::copy(indices.begin(), indices.end(), output.data());
        output.unlock();
        device.drawBuffer(vertices, D3DPT_TRIANGLELIST, lit ? CD3D9Device::lighting : 0u,
            baseVertex, vertexCount, output.buffer(), indices.size(), output.first(),
            lit ? sizeof(SphereRender::PositionNormalUvVertex) : sizeof(SphereRender::PositionColorUvVertex));
    }
}
void TerrainRenderer::drawCells(TerrainPatch& patch, std::size_t first, std::size_t last) {
    if (first > last) return;
    if (g_sfera_light_runtime.active_count > 1u) WorldDiagnostics::fail("Activate light error N3");
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    auto litVertices = device.model_vertices.lock(30000);
    auto coloredVertices = device.colored_vertices.lock(30000);
    const auto anchor = terrainAnchor();
    std::size_t vertexCount = 0u;
    for (std::size_t index = first; index <= last; ++index) {
        const auto& cell = *visibleCells.at(index).cell;
        auto& group = patch.surfaceGroups[cell.x + cell.z * 12];
        group.colored_vertex_offset = vertexCount;
        if (vertexCount + group.vertexCount > 30000u) WorldDiagnostics::fail("VB_SIZE exceed!");
        for (std::size_t vertex = 0; vertex < group.vertexCount; ++vertex, ++vertexCount) {
            const auto& source = patch.groupedVertices[group.firstVertex + vertex];
            const auto position = source.position + anchor;
            litVertices[vertexCount] = {position, source.normal, source.textureU, source.textureV};
            coloredVertices[vertexCount] = {position, D3DCOLOR_ARGB(255, 180, 180, 180), D3DCOLOR_ARGB(0, 50, 50, 50), source.detailU, source.detailV};
        }
    }
    litVertices.unlock();
    coloredVertices.unlock();
    const auto litBase = litVertices.first(), coloredBase = coloredVertices.first();
    terrainSetState(D3DRS_FOGCOLOR, D3DCOLOR_ARGB(0, 255, 255, 255));
    std::vector<std::uint16_t> indices;
    std::uint16_t batchVertices = 0u;
    std::size_t batchStart = 0u;
    std::uint16_t material = visibleCells.at(first).cell->baseMicrotexture;
    const auto append = [&](const TerrainCell& cell, const TerrainSurfaceGroup& group) { for (std::size_t index = 0; index < cell.triangles.size() * 3; ++index) indices.push_back(patch.groupedIndices[group.firstIndex + index] + batchVertices); batchVertices += group.vertexCount; };
    const auto flushBase = [&]() { IDirect3DBaseTexture9* texture = g_sfera_textures.resource(TerrainAssets::microtextures.at(material).texture_id); terrainSetTexture(0u, texture); g_sfera_textures.hasAlpha(TerrainAssets::microtextures.at(material).texture_id); terrainSubmitIndices(device, indices, coloredVertices.buffer(), false, coloredBase + batchStart, batchVertices); batchStart += batchVertices; batchVertices = 0u; indices.clear(); };
    for (std::size_t index = first; index <= last; ++index) { const auto& cell = *visibleCells.at(index).cell; const auto& group = patch.surfaceGroups[cell.x + cell.z * 12]; if (cell.baseMicrotexture != material) { flushBase(); material = cell.baseMicrotexture; } append(cell, group); }
    if (!indices.empty()) flushBase();
    terrainSetState(D3DRS_ZWRITEENABLE, FALSE);
    if (SphereRender::SceneRenderer::secondary_pass == 0u) {
        device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
        for (std::size_t index = first; index <= last; ++index) {
            const auto& cell = *visibleCells.at(index).cell;
            const auto& group = patch.surfaceGroups[cell.x + cell.z * 12];
            if (group.distant) continue;
            for (std::size_t layer = 0; layer < cell.layers.size(); ++layer) { TerrainTextureCache::bindLayer(cell, layer); terrainSubmitIndices(device, {patch.groupedIndices.data() + group.firstIndex, cell.triangles.size() * 3u}, coloredVertices.buffer(), false, coloredBase + group.colored_vertex_offset, group.vertexCount); }
        }
    }
    const auto& ambient = SphereRender::SceneRenderer::environment.fogColor;
    const std::uint32_t fogColor = SferaColor::rgba(SferaNumeric::truncatedWord(ambient.x), SferaNumeric::truncatedWord(ambient.y), SferaNumeric::truncatedWord(ambient.z), 0).argb();
    terrainSetState(D3DRS_FOGCOLOR, fogColor);
    device.setAlphaBlending(D3DBLEND_ZERO, D3DBLEND_SRCCOLOR);
    terrainSetTexture(0u, g_sfera_textures.resource(SphereRender::SceneRenderer::terrain_texture));
    g_sfera_textures.hasAlpha(SphereRender::SceneRenderer::terrain_texture);
    indices.clear();
    batchVertices = batchStart = 0u;
    std::uint32_t mask = patch.surfaceGroups[visibleCells.at(first).cell->x + visibleCells.at(first).cell->z * 12].light_mask;
    const auto flushLight = [&]() { g_sfera_light_runtime.activateMask(mask); terrainSubmitIndices(device, indices, litVertices.buffer(), true, litBase + batchStart, batchVertices); batchStart += batchVertices; batchVertices = 0u; indices.clear(); };
    for (std::size_t index = first; index <= last; ++index) {
        const auto& cell = *visibleCells.at(index).cell;
        const auto& group = patch.surfaceGroups[cell.x + cell.z * 12];
        if (SceneSky::flare_visible != 0u) SceneSky::flare_visible = TerrainQueries::clearViewToFlare(patch, cell);
        const auto nextMask = group.light_mask;
        if (nextMask != mask) { flushLight(); mask = nextMask; }
        append(cell, group);
    }
    flushLight();
    device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    terrainSetState(D3DRS_ZWRITEENABLE, TRUE);
    g_sfera_light_runtime.disableActiveLights();
    if (g_sfera_light_runtime.active_count > 1u) WorldDiagnostics::fail("Activate light error N4");
}

void TerrainRenderer::drawWater() {
    if (waterSurfaces.empty()) return;
    // The sum is the legacy batching key, not a lexicographic (mask, material) key.
    SferaAlgorithms::stableSort(waterSurfaces, [](const auto& surface) { return surface.lightMask + surface.material; });
    std::vector<std::pair<std::size_t, std::size_t>> ranges;
    std::size_t first = 0u;
    for (std::size_t index = 1; index < waterSurfaces.size(); ++index) if (waterSurfaces[index].lightMask != waterSurfaces[index - 1].lightMask || waterSurfaces[index].material != waterSurfaces[index - 1].material) { ranges.emplace_back(first, index); first = index; }
    ranges.emplace_back(first, waterSurfaces.size());

    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    const auto identity = SferaMatrix4x4F::identity();
    device.setTransform(D3DTS_WORLD, identity);
    const float fieldOfView = scene_field_of_view(
        g_sfera_graphics_runtime.display_width,
        g_sfera_graphics_runtime.display_height);
    const float halfAngle = fieldOfView * 0.5;
    const double radians = halfAngle;
    const float projectionTangent = std::tan(radians);
    const int rotationStep = SphereRender::SceneRenderer::texture_animation_frame;
    const float phase = rotationStep * 0.19634956121444702;
    const double phaseAngle = phase;
    const float phaseSine = std::sin(phaseAngle);
    SferaMatrix4x4F reflection{};
    reflection.m[0][0] = -0.5 / projectionTangent;
    reflection.m[1][1] = -(phaseSine * 0.003000000026077032 + 0.5 / projectionTangent);
    reflection.m[2][0] = reflection.m[2][1] = 0.5f;
    reflection.m[2][2] = reflection.m[3][3] = 1.0f;
    terrainSetState(D3DRS_FOGENABLE, FALSE);
    device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
    const auto stage = [&](D3DTEXTURESTAGESTATETYPE state, DWORD value) { device.checkResult(device.native_device->SetTextureStageState(0u, state, value), "SetTextureStageState"); };
    const auto directional = [&]() {  g_sfera_light_runtime.setDirectionalLight({-SphereRender::SceneRenderer::sun_direction.x, -SphereRender::SceneRenderer::sun_direction.y, -SphereRender::SceneRenderer::sun_direction.z}, {SphereRender::SceneRenderer::environment.sunColor.x, SphereRender::SceneRenderer::environment.sunColor.y, SphereRender::SceneRenderer::environment.sunColor.z}); };
    const auto animation = [&](int animationId) { const int frame = rotationStep / 2; std::string name = "ww1_00"; name[2] = '0' + animationId; name[4] = '0' + frame / 10; name[5] = '0' + frame % 10; terrainSetTexture(0u, g_sfera_textures.resource(g_sfera_textures.find(name))); g_sfera_textures.hasAlpha(g_sfera_textures.find(name)); };
    for (const auto& range : ranges) {
        const auto& surface = waterSurfaces[range.first];
        if (surface.material == 0u || surface.material >= g_sfera_graphics_runtime.water_materials.size()) WorldDiagnostics::fail("Water material index outside 1..9");
        const auto& material = g_sfera_graphics_runtime.water_materials.at(surface.material);
        std::vector<SphereRender::PositionNormalUvVertex> vertices;
        std::vector<std::uint16_t> indices;
        vertices.reserve((range.second - range.first) * 4u);
        indices.reserve((range.second - range.first) * 6u);
        for (std::size_t index = range.first; index < range.second; ++index) {
            const auto& water = waterSurfaces[index];
            if (vertices.size() > std::numeric_limits<std::uint16_t>::max() - 3u) throw std::length_error("Water batch exceeds 16-bit index range");
            const std::uint16_t base = SferaNumeric::lowHalf(SferaNumeric::lowWord(vertices.size()));
            for (int corner = 0; corner < 4; ++corner) {
                const int dx = corner == 1 || corner == 2 ? 1 : 0, dz = corner >= 2 ? 1 : 0;
                const double phaseX = (water.x + dx) * 3.9269912242889404, phaseZ = (water.z + dz) * 2.3561947345733643;
                const float wavePhase = (phaseZ + phaseX) + rotationStep * 0.19634956121444702;
                const double waveAngle = wavePhase;
                const float waveSine = std::sin(waveAngle);
                auto& vertex = vertices.emplace_back();
                vertex.position.x = (water.x + dx) * 8.333333015441895;
                vertex.position.y = (waveSine + 1.0) * material.wave_amplitude + water.height;
                vertex.position.z = (water.z + dz) * 8.333333015441895;
                vertex.normal = {0.0f, -1.0f, 0.0f};
                vertex.u = dx;
                vertex.v = dz;
            }
            for (const auto corner : {0u, 1u, 3u, 1u, 2u, 3u}) indices.push_back(SferaNumeric::lowHalf(base + corner));
        }

        g_sfera_light_runtime.activateMask(surface.lightMask);
        stage(D3DTSS_TEXCOORDINDEX, 0u);
        stage(D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE);
        device.setTransform(D3DTS_TEXTURE0, identity);
        directional();
        animation(material.primary_animation);
        const auto draw = [&](float opacity) { device.setWhiteMaterial(opacity); device.checkResult(device.native_device->SetFVF(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1), "SetFVF"); device.drawVertices(D3DPT_TRIANGLELIST, CD3D9Device::lighting | CD3D9Device::two_sided, vertices.data(), vertices.size(), indices.data(), indices.size(), sizeof(SphereRender::PositionNormalUvVertex)); };
        draw(material.primary_opacity);
        for (std::size_t index = range.first; index < range.second; ++index) { const auto& water = waterSurfaces[index]; const float u = ((water.x + 10000) % 4) * 0.25f, v = ((water.z + 10000) % 4) * 0.25f; for (int corner = 0; corner < 4; ++corner) { auto& vertex = vertices[(index - range.first) * 4 + corner]; vertex.u = u + (corner == 1 || corner == 2 ? 0.25f : 0.0f); vertex.v = v + (corner >= 2 ? 0.25f : 0.0f); } }
        if (material.primary_animation != material.secondary_animation) animation(material.secondary_animation);
        draw(material.secondary_opacity);
        if (g_sfera_graphics_runtime.reflection_quality > 0u) { stage(D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_CAMERASPACEPOSITION); stage(D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT3 | D3DTTFF_PROJECTED); device.setTransform(D3DTS_TEXTURE0, reflection); g_sfera_light_runtime.setDirectionalLight({0.0f, 1.0f, 0.0f}, {255.0f, 255.0f, 255.0f}); terrainSetTexture(0u, device.reflection_target->native_texture.Get()); draw(material.reflection_opacity); }
    }
    device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    stage(D3DTSS_TEXCOORDINDEX, 0u);
    stage(D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE);
    device.setTransform(D3DTS_TEXTURE0, identity);
    device.setWhiteMaterial(1.0f);
    g_sfera_light_runtime.disableActiveLights();
    directional();
    terrainSetState(D3DRS_FOGENABLE, TRUE);
}

namespace SphereWorld {
namespace {

SferaVec3F motionSurfaceNormal() { return {g_sfera_contacts.support_normal.x, g_sfera_contacts.support_normal.y, g_sfera_contacts.support_normal.z}; }
SphereRender::Model* motionModel(const WorldObject& object) { return g_sfera_world_objects.model(object); }
SferaVec3F motionContact(std::size_t index) {
    const auto& normals = g_sfera_contacts.normals();
    return index < normals.size() ? normals[index] : SferaVec3F{};
}
float motionMaterialScale() { return g_sfera_motion.material_scale[g_sfera_contacts.surface_material]; }
bool motionHazardBand(float height) { for (int lower = -745; lower <= 505; lower += 250) { if (height > lower && height < (lower + 5)) return true; } return false; }
SferaVec3F motionPlanarSlide(const SferaVec3F& normal, const SferaVec3F& displacement) { return ((normal).cross((displacement))).cross((normal)); }
constexpr double motionNearSupportOffset = 0.03f;
constexpr double motionFarSupportOffset = 0.4f;
constexpr double motionDeviationThreshold = 0.8f;
constexpr double motionGravity = 9.8f;
constexpr double motionDamping = 0.4f;
constexpr double motionGroundLift = 0.06f;
constexpr double motionAngularDamping = 0.78f;
constexpr double motionGridScale = 0.12f;
constexpr double motionProbeLift = 0.2f;
constexpr float motionPickRangeScale = 0.8f;
constexpr double motionPickEdgeLift = 0.1f;
}
void Motion::initializeResponseCurve() {
    constexpr double speed_step = 0.01f;
    constexpr double integration_step = 0.005f;
    for (float speed = 0.0f; speed < 14.0f; speed = speed + speed_step) {
        float velocity = -speed;
        float distance = 0.0f;
        float previous_distance;
        do { previous_distance = distance; distance = distance + (velocity * integration_step + 0.000122499996908009); velocity = velocity + 0.04899999985843895; } while (distance < previous_distance);
        const int index = std::trunc(-previous_distance * 10.0);
        if (index >= 0 && index < 100) g_sfera_motion.response_curve[index] = -speed;
    }
}
float Motion::responseValue(int index) const noexcept { return index >= 0 && index < 100 ? g_sfera_motion.response_curve[index] : 0.0f; }
bool Motion::snapSmallComponents(SferaVec3F& value) noexcept { if (std::fabs(value.x) < 0.0001f) value.x = 0.0f; if (std::fabs(value.y) < 0.0001f) value.y = 0.0f; if (std::fabs(value.z) < 0.0001f) value.z = 0.0f; return value.x == 0.0f && value.y == 0.0f && value.z == 0.0f; }
std::uint32_t Motion::probe(std::uint32_t handle, SferaVec3F displacement, float yaw) {
    auto* object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr) return 2u;
    const auto* model = motionModel(*object);
    if (model == nullptr) return 2u;
    const auto steps = SferaNumeric::truncateInt((displacement).length<double, double, true>() / model->minimum_size) + 1;
    displacement = ((displacement) * (1.0f / steps));
    for (int step = 0; step < steps; ++step) {
        const auto position = object->position;
        const float rotation = object->rotation.x;
        object->position = ((object->position) + (displacement));
        const double precise_rotation = rotation;
        object->rotation.x = precise_rotation + yaw;
        if (g_sfera_contacts.test(handle, ContactQuery::Mode::Movement, true) != 0u) { object->position = position; object->rotation.x = rotation; return 2u; }
    }
    return 0u;
}
std::uint32_t Motion::probeGround(std::uint32_t handle, SferaVec3F displacement, float yaw, bool controlled) {
    auto* object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr) return 2u;
    const auto* model = motionModel(*object);
    if (model == nullptr) return 2u;
    const auto steps = SferaNumeric::truncateInt((displacement).length<double, double, true>() / model->minimum_size) + 1;
    displacement = ((displacement) * (1.0f / steps));
    bool obstructed = false;
    SferaVec3F before_step = object->position;
    float before_yaw = object->rotation.x;
    for (int step = 0; step < steps; ++step) {
        before_step = object->position;
        before_yaw = object->rotation.x;
        const double precise_x = object->position.x;
        const double precise_z = object->position.z;
        const double precise_rotation = object->rotation.x;
        object->position.x = precise_x + displacement.x;
        object->position.z = precise_z + displacement.z;
        object->rotation.x = precise_rotation + yaw;
        if (g_sfera_contacts.test(handle, controlled ? ContactQuery::Mode::Normals : ContactQuery::Mode::Movement, true) != 0u) { obstructed = true; break; }
    }
    if (obstructed) {
        const double half_step = (object->render_group == 4u || object->render_group == 5u ? 0.05f : 0.4f) * 0.5;
        object->position.y = object->position.y - half_step;
        if (g_sfera_contacts.test(handle, ContactQuery::Mode::Movement, true) != 0u) {
            object->position.y = object->position.y - half_step;
            if (g_sfera_contacts.test(handle, ContactQuery::Mode::Movement, true) != 0u) { object->position = before_step; object->rotation.x = before_yaw; return 2u; }
        }
    } else {
        const auto position = object->position;
        object->position.y = position.y + motionNearSupportOffset;
        const auto near_support = g_sfera_contacts.test(handle, ContactQuery::Mode::Movement, true);
        object->position = position;
        if (near_support != 0u) return 0u;
        object->position.y = position.y + motionFarSupportOffset;
        const auto far_support = g_sfera_contacts.test(handle, ContactQuery::Mode::Movement, true);
        object->position = position;
        if (far_support == 0u) { object->physical_velocity.y = 0.0f; object->airborne = true; return 1u; }
    }
    float descent = model->minimum_size;
    do {
        descent = descent * 0.25;
        float previous_y;
        do {
            previous_y = object->position.y;
            const double precise_y = previous_y;
            object->position.y = precise_y + descent;
        } while (g_sfera_contacts.test(handle, ContactQuery::Mode::Movement, true) == 0u);
        object->position.y = previous_y;
    } while (descent >= 0.03f);
    return 0u;
}
bool Motion::avoidContact(std::uint32_t handle, SferaVec3F displacement, float yaw, bool grounded) {
    auto* object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr) return false;
    object->avoidance_enabled = true;
    object->avoidance_direction = motionContact(0);
    object->avoidance_depth = g_sfera_contacts.obstacle_height;
    if (g_sfera_contacts.normals().size() == 1u && !(std::fabs(object->avoidance_direction.y) > 0.99f)) {
        const auto away = ((SferaVec3F{object->avoidance_direction.x, 0.0f, object->avoidance_direction.z}.normalized()) * (-1.0));
        const auto tangent = (motionPlanarSlide(away, (displacement).normalized())).normalized();
        const float random = std::rand() / 32767.0f;
        const float deviation = random < 0.8f ? random * 0.125f : (random - motionDeviationThreshold) * 5.0f;
        const auto offset = ((away) * (deviation));
        object->avoidance_direction = SferaVec3F{tangent.x - offset.x, 0.0f, tangent.z - offset.z}.normalized();
        if (grounded && snapSmallComponents(object->avoidance_direction)) return false;
        const auto result = grounded ? probeGround(handle, object->avoidance_direction, yaw) : probe(handle, object->avoidance_direction, yaw);
        if (result != 2u) return false;
        auto fallback = away;
        const auto fallback_result = grounded && snapSmallComponents(fallback) ? 0u : grounded ? probeGround(handle, fallback, yaw) : probe(handle, fallback, yaw);
        if (fallback_result != 2u) { object->avoidance_direction = fallback; return false; }
    }
    const float random_x = (std::rand() / 32767.0) * 2.0 - 1.0;
    const float random_z = (std::rand() / 32767.0) * 2.0 - 1.0;
    object->avoidance_direction = SferaVec3F{random_x, 0.0f, random_z}.normalized();
    return false;
}
void Motion::moveFree(std::uint32_t handle, bool vertical, float yaw, float elapsed, bool controlled) {
    auto* object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr) return;
    auto displacement = ((((object->physical_velocity) + (object->commanded_velocity))) * (elapsed));
    if (!vertical) displacement.y = 0.0f;
    if (controlled) { g_sfera_contacts.test(handle, ContactQuery::Mode::Material, true); displacement = ((displacement) * (motionMaterialScale())); }
    if (probe(handle, displacement, yaw) == 0u) return;
    object->movement_blocked = true;
    object->physical_velocity.x = object->physical_velocity.z = object->angular_velocity = 0.0f;
    if (vertical) object->physical_velocity.y = 0.0f;
    if (!controlled) avoidContact(handle, displacement, yaw, false);
}
void Motion::fall(std::uint32_t handle, float elapsed, bool controlled) {
    auto* object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr) return;
    const auto* model = motionModel(*object);
    if (model == nullptr) return;
    const double precise_elapsed = elapsed;
    const float distance = object->physical_velocity.y * precise_elapsed + precise_elapsed * elapsed * motionGravity * 0.5;
    object->physical_velocity.y = precise_elapsed * motionGravity + object->physical_velocity.y;
    if (object->physical_velocity.y > 30.0f) object->physical_velocity.y = 30.0f;
    if (std::fabs(distance) < 0.003f) return;
    const double minimum_step = model->minimum_size;
    const auto steps = SferaNumeric::truncateInt(std::fabs(distance) / minimum_step) + 1;
    const double precise_distance = distance;
    float step_distance = precise_distance / steps;
    bool blocked = false;
    bool crossed_hazard = false;
    float previous_y = object->position.y;
    for (int step = 0; step < steps; ++step) {
        previous_y = object->position.y;
        const double precise_y = previous_y;
        object->position.y = precise_y + step_distance;
        if (g_sfera_contacts.test(handle, ContactQuery::Mode::Movement, true) != 0u) { blocked = true; break; }
        if (controlled && object->process_handle != nullptr && motionHazardBand(object->position.y)) crossed_hazard = true;
    }
    if (!blocked) {
        if (object->process_handle != nullptr && (controlled ? crossed_hazard : motionHazardBand(object->position.y))) { if (controlled) object->physical_velocity.y = 0.0f; g_sfera_world_objects.appendCommand(handle, "phKILL 1"); object = g_sfera_world_objects.extendedObject(handle); if (object == nullptr) return; }
        if (object->position.y > 8000.0f) { object->position = {(std::rand() * 6.0f / 32767.0f + 77.0f) - 3.0f, 160.0f, (std::rand() * 6.0f / 32767.0f + 95.0f) - 3.0f}; object->physical_velocity.y = 0.0f; }
        return;
    }
    object->position.y = previous_y;
    while (std::fabs(step_distance) >= 0.03f) {
        step_distance = step_distance * 0.25;
        for (;;) {
            previous_y = object->position.y;
            const double precise_y = previous_y;
            object->position.y = precise_y + step_distance;
            if (previous_y == object->position.y || g_sfera_contacts.test(handle, ContactQuery::Mode::Support, true) != 0u) break;
        }
        object->position.y = previous_y;
    }
    if (!(object->physical_velocity.y > 0.0f)) { object->physical_velocity.y = 0.0f; return; }
    if (object->process_handle != nullptr && object->physical_velocity.y > (controlled ? 1.0f : 7.0f)) { std::string command; command = std::format("phDMG {:5.1f}", object->physical_velocity.y); g_sfera_world_objects.appendCommand(handle, command); object = g_sfera_world_objects.extendedObject(handle); if (object == nullptr) return; }
    object->airborne = false;
    const float speed = std::fabs(object->physical_velocity.y);
    const auto normal = motionSurfaceNormal();
    const double precise_speed = speed;
    object->physical_velocity.x = object->physical_velocity.x * motionDamping + std::fabs(normal.y) * (precise_speed * normal.x) * 0.6f;
    object->physical_velocity.z = object->physical_velocity.z * motionDamping + precise_speed * normal.z * std::fabs(normal.y) * 0.6f;
    object->angular_velocity = (0.5 - std::rand() * 0.000030517578125) * object->physical_velocity.y * 0.2f;
    object->physical_velocity.y = 0.0f;
}
bool Motion::slideControlled(std::uint32_t handle, const SferaVec3F& displacement) {
    for (const float clearance : {0.0001f, 0.02f}) {
        for (std::uint32_t index = 0; index < g_sfera_contacts.normals().size(); ++index) {
            const auto contact = motionContact(index);
            if (std::fabs(contact.y) > 0.99f) continue;
            const auto away = ((SferaVec3F{contact.x, 0.0f, contact.z}.normalized(clearance == 0.0001f ? 13 : 14)) * (-1.0));
            auto slide = motionPlanarSlide(away, displacement);
            const auto offset = ((away) * (clearance));
            slide = {slide.x - offset.x, 0.0f, slide.z - offset.z};
            const auto result = probeGround(handle, slide, 0.0f, true);
            if (result == 1u) return true;
            if (result == 0u) break;
        }
    }
    return false;
}
void Motion::dampMotion(std::uint32_t handle, float elapsed, bool controlled) {
    auto* object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr) return;
    const float height = object->position.y;
    object->position.y = height + motionGroundLift;
    g_sfera_contacts.test(handle, ContactQuery::Mode::Support, true);
    object->position.y = height;
    const auto normal = motionSurfaceNormal();
    if (std::fabs(normal.y) < 0.766f) {
        const double precise_normal_y = std::fabs(normal.y);
        const float angle = std::acos(precise_normal_y);
        const double precise_angle = angle;
        const float sine = std::sin(precise_angle);
        const float acceleration = sine * 4.0;
        const auto downhill = ((SferaVec3F{normal.x, 0.0f, normal.z}.normalized()) * (acceleration));
        object->physical_velocity = ((object->physical_velocity) + (((downhill) * (elapsed))));
    }
    const auto direction = controlled ? g_sfera_contacts.support_direction : 0u;
    const float friction = g_sfera_motion.surface_friction[direction];
    const double precise_elapsed = elapsed;
    const float reduction = precise_elapsed * friction;
    if (controlled && direction >= 4u) object->steep_slope = false;
    const float speed = SferaVec3F{object->physical_velocity.x, 0.0f, object->physical_velocity.z}.length<double, double, true>();
    if (speed > reduction && speed > 0.0001f) {
        const double precise_reduction = reduction;
        const double precise_speed = speed;
        const double remaining = speed - precise_reduction;
        object->physical_velocity.x = object->physical_velocity.x / precise_speed * remaining;
        object->physical_velocity.z = object->physical_velocity.z / precise_speed * remaining;
    } else object->physical_velocity.x = object->physical_velocity.z = 0.0f;
    const float exponent = friction * 10.0 * elapsed;
    const double precise_exponent = exponent;
    const float angular_scale = std::pow(motionAngularDamping, precise_exponent);
    const double precise_angular_scale = angular_scale;
    object->angular_velocity = precise_angular_scale * object->angular_velocity;
    if (std::fabs(object->angular_velocity) < 0.0001f) object->angular_velocity = 0.0f;
}
void Motion::moveGround(std::uint32_t handle, float yaw, float elapsed, bool controlled) {
    auto* object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr) return;
    const auto commanded = (SferaVec3F{object->commanded_velocity.x, 0.0f, object->commanded_velocity.z} * (elapsed));
    const auto physical = (SferaVec3F{object->physical_velocity.x, 0.0f, object->physical_velocity.z} * (elapsed));
    const auto overlap = g_sfera_contacts.test(handle, ContactQuery::Mode::Movement, true, false);
    if (overlap > 1u) { const auto* other = g_sfera_world_objects.object(overlap); if (other != nullptr) { auto separation = SferaVec3F{object->position.x - other->position.x, 0.0f, object->position.z - other->position.z}.normalized(); if (separation.x == 0.0f && separation.y == 0.0f && separation.z == 0.0f) separation.x = controlled ? 2.0f : 1.0f; object->physical_velocity = ((separation) * (2.0)); } }
    g_sfera_contacts.test(handle, ContactQuery::Mode::Material, true);
    const float height = object->position.y;
    object->position.y = height + motionGroundLift;
    g_sfera_contacts.test(handle, ContactQuery::Mode::Support, true);
    object->position.y = height;
    const float slope = std::fabs(motionSurfaceNormal().y);
    auto displacement = ((((((commanded) * (slope))) + (physical))) * (motionMaterialScale()));
    object->steep_slope = slope < 0.7f;
    if (controlled || !snapSmallComponents(displacement)) {
        const auto result = probeGround(handle, displacement, yaw, controlled);
        if (result == 1u) return;
        if (result == 2u) { object->movement_blocked = true; object->physical_velocity.x = object->physical_velocity.z = object->angular_velocity = 0.0f; if (controlled ? slideControlled(handle, displacement) : avoidContact(handle, displacement, yaw, true)) return; }
    }
    dampMotion(handle, elapsed, controlled);
}
void Motion::updateObjects(float elapsed) {
    g_sfera_vegetation.map_update_phase ^= 1u;
    const auto object_count = g_sfera_world_objects.extended_object_count;
    std::size_t visited = 0u;
    for (std::size_t slot = 0u; slot < g_sfera_world_objects.extended_object_handles.size() && visited < object_count; ++slot) {
        const auto handle = g_sfera_world_objects.extended_object_handles[slot];
        if (handle == 0u) continue;
        ++visited;
        auto* object = g_sfera_world_objects.extendedObject(handle);
        if (object == nullptr || !object->simulation_enabled || !object->render_enabled || object->parent_object_handle != 0u) continue;
        if (!object->full_rate_simulation && g_sfera_vegetation.map_update_phase == 0u) continue;
        if (object->process_handle != nullptr && !g_sfera_world_objects.actorActive(handle) && g_sfera_mbc_runtime.simulation_tick - object->last_simulation_tick > 120u) continue;
        const float interval = object->full_rate_simulation ? elapsed : elapsed * 2.0f;
        const double precise_interval = interval;
        const float yaw = object->angular_velocity * precise_interval;
        const auto velocity = ((object->physical_velocity) + (object->commanded_velocity));
        if (object->motion_state == 1u && yaw == 0.0f && velocity.x == 0.0f && velocity.y == 0.0f && velocity.z == 0.0f) continue;
        if (!object->gravity_enabled) moveFree(handle, true, yaw, interval, false);
        else if (!object->airborne) moveGround(handle, yaw, interval, false);
        else { moveFree(handle, false, yaw, interval, false); if (g_sfera_world_objects.extendedObject(handle) != nullptr) fall(handle, interval, false); }
    }
}
void Motion::updateControlled(float elapsed) {
    const auto handle = g_sfera_world_objects.controlled_object_handle;
    if (handle == UINT32_MAX) return;
    auto* object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr) return;
    const double precise_elapsed = elapsed;
    float yaw = object->angular_velocity * precise_elapsed;
    if (yaw != 0.0f) {
        const double precise_rotation = object->rotation.x;
        object->rotation.x = precise_rotation + yaw;
        yaw = 0.0f;
    }
    if (g_sfera_motion.tracking_position_pending == 1u) {
        g_sfera_motion.tracked_position.x = g_sfera_motion.tracked_position.x - 333.0;
        g_sfera_motion.tracked_position.y = g_sfera_motion.tracked_position.y - 333.0;
        g_sfera_motion.tracked_position.z = g_sfera_motion.tracked_position.z - 333.0;
        const SferaVec3F camera{g_sfera_motion.tracked_position.x, g_sfera_motion.tracked_position.y, g_sfera_motion.tracked_position.z};
        const auto delta = ((camera) - (object->position));
        if (std::fabs(delta.x) > 0.5f || std::fabs(delta.y) > 0.5f || std::fabs(delta.z) > 0.5f) { g_sfera_motion.moved_since_query = 1u; object->position = camera; }
    }
    g_sfera_contacts.test(handle, ContactQuery::Mode::CollectIgnored, false);
    if (!object->gravity_enabled) moveFree(handle, true, yaw, elapsed, true);
    else if (!object->airborne) moveGround(handle, yaw, elapsed, true);
    else { moveFree(handle, false, yaw, elapsed, true); if (g_sfera_world_objects.extendedObject(handle) != nullptr) fall(handle, elapsed, true); }
    object = g_sfera_world_objects.extendedObject(handle);
    if (object != nullptr) { g_sfera_motion.tracking_position_pending = 1u; g_sfera_motion.tracked_position.x = object->position.x + 333.0; g_sfera_motion.tracked_position.y = object->position.y + 333.0; g_sfera_motion.tracked_position.z = object->position.z + 333.0; }
}
void Motion::updateOrientation() {
    auto* object = g_sfera_world_objects.extendedObject(0u);
    if (object == nullptr) return;
    const auto lateral = ((object->orientation_basis[2]) * (g_sfera_motion.acceleration.x));
    const auto forward = ((object->orientation_basis[0]) * (g_sfera_motion.acceleration.z));
    object->commanded_velocity = ((((forward) + (lateral))) * (192.0));
    object->physical_velocity = {};
    g_sfera_contacts.test(0u, ContactQuery::Mode::CollectIgnored, false);
    moveFree(0u, true, 0.0f, 0.0052083334885537624f, true);
    g_sfera_world_objects.rotate(0u, {g_sfera_motion.displacement.x, g_sfera_motion.displacement.y, 0.0f});
    g_sfera_world_objects.alignReferenceOrientation();

}
std::uint32_t Motion::surfaceInteraction(std::uint32_t handle, std::uint32_t* material) {
    auto* object = g_sfera_world_objects.object(handle);
    const auto* reference = g_sfera_world_objects.object(1u);
    if (object == nullptr || reference == nullptr || (((object->position) - (reference->position))).length<double, double, true>() > 15.0f) return 0u;
    ContactQuery::updateBounds(handle);
    const int x_units = SferaNumeric::truncateInt(object->position.x * motionGridScale + 100000.0) + 20000;
    const int z_units = SferaNumeric::truncateInt(object->position.z * motionGridScale + 100000.0) + 20000;
    const int patch_x = x_units / 12 - 10000;
    const int patch_z = z_units / 12 - 10000;
    const int map_x = patch_x + 40;
    const int map_z = 39 - patch_z;
    if (map_x < 0 || map_x >= 80 || map_z < 0 || map_z >= 80) return 0u;
    const std::size_t map_index = map_x * 80 + map_z;
    auto* region = TerrainAssets::map[map_index].region;
    const auto& tile = TerrainAssets::map[map_index];
    if (region == nullptr) return 0u;
    region->touchPatch(tile.tile_x, tile.tile_y);
    const auto* patch = region->patch(tile.tile_x, tile.tile_y);
    if (patch == nullptr) return 0u;
    const int local_x = x_units % 12;
    const int local_z = z_units % 12;
    const int cell_index = ((local_x / 6 + 2 * (local_z / 6)) * 4 + 2 * ((local_z / 3) % 2) + (local_x / 3) % 2 - local_z / 3) * 3 - local_x / 3 + local_z;
    const auto& cell = patch->cells[local_x + cell_index * 3];
    const auto& water = patch->waters[cell.x + 12 * cell.z];
    if (material != nullptr) *material = UINT32_MAX;
    if (water.material != 0u && !(water.height > object->bounds_maximum.y)) { if (material != nullptr) *material = water.material; const double feet = object->bounds_minimum.y - 0.25; if (water.height > feet) return 4u; if (water.height + 30.0 > feet) return 5u; }
    g_sfera_contacts.clearIgnoredObjects();
    const auto position = object->position;
    object->position.y = position.y + motionProbeLift;
    const auto contact = g_sfera_contacts.test(handle, ContactQuery::Mode::Movement, false);
    object->position = position;
    if (contact == 0u) return 0u;
    if (contact > 1u) { const auto* other = g_sfera_world_objects.object(contact); const auto* model = other == nullptr ? nullptr : motionModel(*other); return model != nullptr && SferaText::compareInsensitive(std::string_view(model->name).substr(0, 4), "tree") == 0 ? 6u : 3u; }
    const float relative_x = position.x - patch_x * 100.0;
    const float relative_z = position.z - patch_z * 100.0;
    const int texture_x = std::trunc(relative_x / 100.0 * 254.0 + 1.0);
    const int texture_z = std::trunc(relative_z / 100.0 * 254.0 + 1.0);
    const auto& texture = region->slots[tile.tile_x * 10 + tile.tile_y].texture->pixels;
    for (int row = texture_z - 2; row <= texture_z + 2; ++row) {
        for (int column = texture_x - 2; column <= texture_x + 2; ++column) { const auto pixel = texture[std::clamp(row, 0, 255) * 256 + std::clamp(column, 0, 255)]; const int green = ((pixel >> 6u) & 31u) * 100 / 105; if ((pixel & 31u) >= green || (pixel >> 11u) > green) return 2u; }
    }
    return 1u;
}
std::uint32_t Motion::pick(float* distance, SferaVec3F* direction) {
    if (!SferaClientApplication::resources_loaded) return UINT32_MAX;
    auto* cursor = CCursorManager::instance().activeCursor();
    if (cursor == nullptr) return UINT32_MAX;
    SferaCursorPosition cursor_position{};
    cursor->getPosition(&cursor_position);
    const auto& points = g_sfera_camera.frame_corners;
    const double display_width = g_sfera_graphics_runtime.display_width;
    const double display_height = g_sfera_graphics_runtime.display_height;
    const float horizontal = cursor_position.x / display_width;
    const float vertical = cursor_position.y / display_height;
    const auto cursor_plane = ((points[1]) + (((((((points[2]) - (points[1]))) * (horizontal))) + (((((points[4]) - (points[1]))) * (vertical))))));
    const auto ray = (((cursor_plane) - (points[0]))).normalized();
    if (ray.x == 0.0f && ray.y == 0.0f && ray.z == 0.0f) return UINT32_MAX;
    if (direction != nullptr) *direction = ray;
    const float range = std::min(SphereRender::SceneRenderer::environment.fogParameters.z * motionPickRangeScale, 50.0f);
    const auto ray_end = ((points[0]) + (((ray) * (range))));
    auto ray_edge = ray_end;
    ray_edge.y = ray_edge.y + motionPickEdgeLift;
    const auto* reference = g_sfera_world_objects.object(1u);
    if (reference == nullptr) return UINT32_MAX;
    g_sfera_world_spatial.gatherObjects(reference->position, range);
    std::uint32_t selected = UINT32_MAX;
    float nearest = 1000000.0f;
    for (const auto handle : g_sfera_world_spatial.objects()) {
        auto* object = g_sfera_world_objects.object(handle);
        if (object == nullptr || handle == 1u || handle == g_sfera_world_objects.controlled_object_handle || !object->visible) continue;
        if (object->extended() && !g_sfera_world_objects.extendedObject(handle)->render_enabled) continue;
        const auto* model = motionModel(*object);
        if (model == nullptr || model->collision_kind == SphereRender::CollisionKind::None) continue;
        ContactQuery::updateBounds(handle);
        auto origin = points[0];
        auto end = ray_end;
        auto edge = ray_edge;
        auto minimum = object->bounds_minimum;
        auto maximum = object->bounds_maximum;
        if (model->collision_kind != SphereRender::CollisionKind::AxisAlignedBounds) { minimum = {}; maximum = model->oriented_size; const auto transform = [&](const SferaVec3F& point) { return model->bounds_transform.inverseTransformPoint(object->world_transform.inverseTransformPoint(point)); }; origin = transform(origin); end = transform(end); edge = transform(edge); }
        g_sfera_contacts.query_bounds.minimum = {minimum.x, minimum.y, minimum.z};
        g_sfera_contacts.query_bounds.maximum = {maximum.x, maximum.y, maximum.z};
        if (!g_sfera_clipped_polygon.clipTriangleToBounds(origin, end, edge, minimum, maximum)) continue;
        float candidate_distance = 1000000.0f;
        for (const auto& vertex : g_sfera_clipped_polygon.vertices) candidate_distance = std::min(candidate_distance, (((vertex) - (origin))).length<double, double, true>());
        if (!(nearest > candidate_distance)) continue;
        if (model->collision_kind != SphereRender::CollisionKind::Triangles) { nearest = candidate_distance; selected = handle; continue; }
        origin = object->world_transform.inverseTransformPoint(points[0]);
        end = object->world_transform.inverseTransformPoint(ray_end);
        for (std::size_t group_index = 0; group_index < model->collision_groups.size(); ++group_index) {
            const auto& group = model->collision_groups[group_index];
            for (std::size_t index = 0; index < group.triangle_count; ++index) { const auto& triangle = model->collision_triangles[group.first_triangle + index]; if ((triangle.collision_flags & 255u) != 0u) continue; SferaVec3F hit{}; if (ContactQuery::intersectTriangle(origin, end, triangle, hit) != 2) continue; const float hit_distance = (((hit) - (origin))).length<double, double, true>(); if (nearest > hit_distance) { nearest = hit_distance; selected = handle; } }
        }
    }
    if (distance != nullptr) *distance = nearest;
    return selected;
}
}

void WorldObjects::removeExtended(std::uint32_t handle) { auto* item = extendedObject(handle); if (!item) return; const auto index = item->extended_object_index; if (index == ExtendedWorldObject::unregistered) return; if (index >= extended_object_handles.size()) WorldDiagnostics::fail("Extended object index is outside the registry"); extended_object_handles[index] = 0; item->extended_object_index = ExtendedWorldObject::unregistered; --extended_object_count; }
void WorldObjects::addExtended(std::uint32_t handle) { auto* item = extendedObject(handle); if (!item || item->extended_object_index != ExtendedWorldObject::unregistered) return; auto* handles = extended_object_handles.data(); std::size_t index = 0; while (index < extended_object_handles.size() && handles[index]) ++index; if (index == extended_object_handles.size()) WorldDiagnostics::fail("Extended object handle table is full"); handles[index] = handle; item->extended_object_index = index; ++extended_object_count; }
void WorldObjects::unlink(std::uint32_t parentHandle, std::uint32_t slot) { auto* parent = object(parentHandle); if (!parent || slot >= 5) { WorldDiagnostics::warning("Wrong handle: Link_object_to_object"); return; } const auto child = parent->linked_objects[slot]; if (child) destroy(child); if (auto* survivor = object(parentHandle)) survivor->linked_objects[slot] = 0; }
namespace { struct WorldDestructionGuard { std::unordered_set<std::uint32_t>& active; std::uint32_t handle; ~WorldDestructionGuard() { active.erase(handle); } }; }
void WorldObjects::destroy(std::uint32_t handle) {
    {
        if (!destroying_handles.insert(handle).second) return;
        WorldDestructionGuard guard{destroying_handles, handle};
        // The script owns the binding. controlledObject() excludes this handle
        // during callbacks without discarding a pending/recreated-object binding.
        auto* owned = object(handle);
        if (!owned) { WorldDiagnostics::warning("DeleteObject: wrong handle"); return; }
        WorldGuiControls::removeForObject(handle);
        // Callbacks may delete other effects. Retain each active instance until its callback returns.
        for (auto& slot : owned->attached_effects) {
            auto* effect = slot;
            if (effect == nullptr) continue;
            const auto& active = g_sfera_effect_manager.active_effects;
            const auto found = std::find_if(active.begin(), active.end(), [&](const auto& item) { return item.get() == effect; });
            if (found == active.end()) { slot = nullptr; continue; }
            const auto retained = *found;
            if (!g_sfera_effect_manager.removeActiveEffect(effect) && retained->active) {
                // A veto may keep the effect alive, but it cannot retain a reusable world slot.
                retained->position = owned->position;
                retained->position_source = 1u;
                retained->source_handle = UINT32_MAX;
            }
            slot = nullptr;
        }
        if (auto* extended = owned->extended()) {
            if (extended->parent_object_handle == 0) {
                removeSpatialIndex(handle);
                for (auto& child : owned->linked_objects) {
                    const auto childHandle = std::exchange(child, 0u);
                    if (childHandle != handle && childHandle != 0u && object(childHandle)) destroy(childHandle);
                }
            } else if (auto* parent = object(extended->parent_object_handle); parent && extended->parent_link_slot < 5) {
                if (parent->linked_objects[extended->parent_link_slot] == handle) parent->linked_objects[extended->parent_link_slot] = 0;
            }
            if (extended->render_cache_handle < 0) {
                auto* models = SphereRender::SceneRenderer::characters.get();
                const std::uint32_t index = -1 - extended->render_cache_handle;
                if (models && index < std::size(models->instances)) models->instances[index].owner = nullptr;
                else WorldDiagnostics::fail("Character instance handle is outside the cache");
            }
            removeExtended(handle);
        } else removeSpatialIndex(handle);
        if (g_sfera_mbc_runtime.current_object == owned) g_sfera_mbc_runtime.current_object = nullptr;
        if (owned->ownsModel() && SphereRender::ModelPose::active_model == model(*owned)) SphereRender::ModelPose::active_model = nullptr;
        object_handles.at(handle).reset();
        next_object_handle = std::min(next_object_handle, handle);
        if (handle == max_occupied_object_handle) {
            do { --max_occupied_object_handle; } while (max_occupied_object_handle != UINT32_MAX && !object(max_occupied_object_handle));
        }
    }
    if (clear_requested && destroying_handles.empty()) clear();
}
void WorldObjects::destroyAll() { const auto limit = std::min<std::uint32_t>(500000, object_handles.size()); for (std::uint32_t handle = 2; handle < limit; ++handle) if (object(handle)) destroy(handle); }
void WorldObjects::clear() {
    if (clearing) return;
    if (!destroying_handles.empty()) { clear_requested = true; return; }
    clearing = true;
    clear_requested = false;
    try {
        destroyAll();
        for (std::uint32_t handle = 0; handle < std::min<std::size_t>(2, object_handles.size()); ++handle) if (object(handle)) destroy(handle);
    } catch (...) {
        clearing = false;
        throw;
    }
    object_handles.clear();
    extended_object_handles.clear();
    extended_object_count = 0;
    next_object_handle = 0;
    max_occupied_object_handle = controlled_object_handle = UINT32_MAX;
    clearing = false;
}
ExtendedWorldObject* WorldObjects::linkModel(std::uint32_t parentHandle, std::string_view name, std::uint32_t slot) { auto* parent = extendedObject(parentHandle); if (!parent || slot >= 5) { WorldDiagnostics::warning("Wrong handle: Link_object_to_object"); return nullptr; } if (parent->linked_objects[slot]) unlink(parentHandle, slot); const auto childHandle = create(name, 0, 0, true); if (childHandle == UINT32_MAX) return nullptr; auto* child = extendedObject(childHandle); parent = extendedObject(parentHandle); if (!parent || !child) { if (child) destroy(childHandle); return nullptr; } parent->linked_objects[slot] = childHandle; child->parent_object_handle = parentHandle; child->parent_link_slot = slot; return child; }

namespace SphereRender {
namespace { void poseWarning(std::string_view message) { WorldDiagnostics::message.clear(); WorldDiagnostics::appendScriptContext(message); WorldDiagnostics::flushScriptContext(); } }
ModelKeyframe ModelPose::keyframe(const Model& model, const BoneAnimation& animation, std::size_t frame) {
    if (!animation.animated) return model.keyframes[animation.pose_index];
    const auto& sample = model.animation_frames[animation.pose_index + frame];
    const auto& first = model.keyframes[sample.keyframe];
    if (sample.interpolation == 255u) return first;
    const auto& second = model.keyframes[sample.keyframe + 1u];
    const float weight = sample.interpolation / 256.0f;
    return {first.translation + (second.translation - first.translation) * weight, first.rotation.interpolated(second.rotation, weight)};
}

void ModelPose::updateBone(const SferaMatrix4x4F& parent, std::size_t bone_index) {
    auto* model = SphereRender::ModelPose::active_model;
    if (model == nullptr || bone_index >= model->bones.size()) WorldDiagnostics::fail("Model animation: wrong bone index");
    const auto& bone = model->bones[bone_index];
    auto pose = keyframe(*model, bone.animation(), SphereRender::ModelPose::primary_frame);
    if (bone.animation().animated && SphereRender::ModelPose::secondary_enabled && !bone.animation().suppress_secondary_animation) {
        const auto second = keyframe(*model, bone.animation(), SphereRender::ModelPose::secondary_frame);
        const float weight = SphereRender::ModelPose::blend;
        pose = {pose.translation + (second.translation - pose.translation) * weight, pose.rotation.interpolated(second.rotation, weight)};
    }
    auto local = SferaMatrix4x4F::identity();
    const auto rotation = pose.rotation.rotationMatrix();
    for (std::size_t row = 0u; row < 3u; ++row) for (std::size_t column = 0u; column < 3u; ++column) local.m[row][column] = rotation.m[column][row];
    local.m[0][3] = pose.translation.x; local.m[1][3] = pose.translation.y; local.m[2][3] = pose.translation.z;
    const auto transform = parent.multiplied(local);
    auto& matrices = SphereRender::ModelPose::bone_transforms;
    if (matrices.size() <= bone_index) matrices.resize(bone_index + 1u);
    matrices[bone_index] = transform;
    const auto slot = bone.animation().attachment_slot;
    SferaVec3F* position = slot == 100u ? &SphereRender::ModelPose::translation : slot == 101u ? &SphereRender::ModelPose::attachment_101_position : slot == 102u ? &SphereRender::ModelPose::attachment_102_position : nullptr;
    if (position != nullptr) { position->x = transform.m[0][3]; position->y = transform.m[1][3]; position->z = transform.m[2][3]; }
    if (slot < 5u) { auto& attachments = SphereRender::ModelPose::attachment_transforms; attachments[slot] = transform; }
    for (std::size_t child = 0u; child < bone.child_count; ++child) updateBone(transform, model->child_bones[bone.first_child + child]);
}

ExtendedWorldObject* ModelPose::queryObject(std::uint32_t handle, std::string_view operation) {
    auto* object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr) poseWarning((std::string(operation) + ": wrong handle"));
    return object;
}

int ModelPose::animationLength(std::uint32_t handle, int animation) {
    auto* object = queryObject(handle, "GetSubAnimLen");
    if (object == nullptr) return -1;
    if (object->render_cache_handle < 0) return SphereRender::SceneRenderer::characters->partAnimationLength(*object, animation);
    auto* model = g_sfera_world_objects.model(*object);
    if (model == nullptr || model->animation_lengths.size() == 0u) { poseWarning("GetSubAnimLen: model has no animation"); return -1; }
    if (animation < 0) { poseWarning("GetSubAnimLen: negative subanimation number"); return -1; }
    return std::cmp_less(animation, model->animation_lengths.size()) ? model->animation_lengths[animation] : -1;
}

int* ModelPose::animation(std::uint32_t handle) { auto* object = queryObject(handle, "GetAnimation"); return object == nullptr ? nullptr : &object->animation; }
int* ModelPose::frame(std::uint32_t handle) { auto* object = queryObject(handle, "GetFrame"); return object == nullptr ? nullptr : &object->frame; }
float* ModelPose::interpolation(std::uint32_t handle) { auto* object = queryObject(handle, "GetInterp"); return object == nullptr ? nullptr : &object->interpolation; }
int* ModelPose::secondaryFrame(std::uint32_t handle) { auto* object = queryObject(handle, "GetFrame2"); return object == nullptr ? nullptr : &object->frame_secondary; }
int* ModelPose::secondaryAnimation(std::uint32_t handle) { auto* object = queryObject(handle, "GetAnimation2"); return object == nullptr ? nullptr : &object->animation_secondary; }

std::size_t ModelPose::frameOffset(const Model& model, int animation, int frame, bool secondary) {
    if (model.animation_lengths.empty()) {
        auto message = std::format("CalcCharacterNeck: model has no animation (model='{}', controlled={}, animation={}, frame={})",
            model.name, g_sfera_world_objects.controlled_object_handle, animation, frame);
        const auto& scriptError = g_sfera_mbc_runtime.first_execution_error;
        if (!scriptError.empty()) message += "\nFirst script error in this session:\n" + scriptError;
        g_sfera_log_runtime.write(message);
        WorldDiagnostics::fail(message);
    }
    if (animation < 0 || animation >= model.animation_lengths.size()) { poseWarning(secondary ? "CalcCharacterNeck: wrong animation 2" : "CalcCharacterNeck: wrong animation"); animation = 0; frame = 0; }
    std::size_t offset = 0u;
    for (int index = 0; index < animation; ++index) offset += model.animation_lengths[index];
    if (frame < 0 || frame >= model.animation_lengths[animation]) { poseWarning(secondary ? "CalcCharacterNeck: wrong frame 2" : "CalcCharacterNeck: wrong frame"); frame = 0; }
    return offset + frame;
}

SferaVec3F* ModelPose::neckPosition(SferaVec3F& output) {
    auto* object = g_sfera_world_objects.extendedObject(g_sfera_world_objects.controlled_object_handle);
    if (object == nullptr) WorldDiagnostics::fail("CalcCharacterNeck: wrong handle");
    if (object->render_cache_handle < 0) { output = SphereRender::SceneRenderer::characters->neckPosition(*object); return &output; }
    auto* model = g_sfera_world_objects.model(*object);
    if (model == nullptr) WorldDiagnostics::fail("CalcCharacterNeck: missing model");
    SphereRender::ModelPose::active_model = model;
    SphereRender::ModelPose::primary_frame = frameOffset(*model, object->animation, object->frame, false);
    SphereRender::ModelPose::secondary_enabled = object->interpolation > 0.00001f ? 1u : 0u;
    if (SphereRender::ModelPose::secondary_enabled) { SphereRender::ModelPose::blend = object->interpolation; SphereRender::ModelPose::secondary_frame = frameOffset(*model, object->animation_secondary, object->frame_secondary, true); }
    SphereRender::ModelPose::current_frame = SferaMatrix4x4F::fromEuler(object->position, object->rotation);
    updateBone(SphereRender::ModelPose::current_frame, model->root_bone);
    const auto& position = SphereRender::ModelPose::attachment_102_position;
    output = {position.x, position.y, position.z};
    return &output;
}
}

namespace SphereRender {
namespace {

SferaMatrix4x4F characterPoseMatrix(const CharacterPose& pose) {
    const auto basis = SferaQuaternionF{
        pose.rotation.w, pose.rotation.x, pose.rotation.y, pose.rotation.z}.rotationMatrix();
    auto result = SferaMatrix4x4F::identity();
    for (std::size_t row = 0u; row < 3u; ++row) {
        for (std::size_t column = 0u; column < 3u; ++column) {
            result.m[row][column] = basis.m[column][row];
        }
    }
    result.m[3][0] = pose.translation.x;
    result.m[3][1] = pose.translation.y;
    result.m[3][2] = pose.translation.z;
    return result;
}
template<class T> T characterRead(std::span<const std::uint8_t> bytes, std::size_t offset) {
    if (offset > bytes.size() || sizeof(T) > bytes.size() - offset) WorldDiagnostics::fail("Truncated character model");
    const auto value = SferaBinary::Reader(bytes.subspan(offset, sizeof(T))).read<T>();
    if constexpr (std::is_floating_point_v<T>) if (!std::isfinite(value)) WorldDiagnostics::fail("Nonfinite character coordinate");
    return value;
}
std::span<const std::uint8_t> characterRange(std::span<const std::uint8_t> bytes, std::size_t offset, std::size_t length) { if (offset > bytes.size() || length > bytes.size() - offset) WorldDiagnostics::fail("Truncated character model"); return bytes.subspan(offset, length); }
void characterDisableLights(std::uint32_t line) { for (std::size_t index = 0; index < g_sfera_light_runtime.candidate_count; ++index) if (g_sfera_light_runtime.render_candidate_active[index]) g_sfera_light_runtime.setActive(g_sfera_light_runtime.render_candidate_indices[index], false, line); }
}
void CharacterSkeleton::calculate(std::size_t firstFrame, std::optional<std::size_t> upperFrame, std::size_t bone,
    const SferaMatrix4x4F& parent, Region region, SferaMatrix4x4F* output) const {
    if (upperFrame && region == Region::Whole) {
        if (names[bone].starts_with('u')) region = Region::UpperBody;
        else if (names[bone].starts_with('d')) region = Region::LowerBody;
    }
    const auto frame = upperFrame && region == Region::UpperBody ? *upperFrame : firstFrame;
    output[bone] = (characterPoseMatrix(poses[frame * parents.size() + bone])).multiplied((parent));
    for (const auto child : children[bone]) calculate(firstFrame, upperFrame, child, output[bone], region, output);
}
std::size_t CharacterSkeleton::absoluteFrame(int animation, int frame) const {
    if (animation < 0 || std::cmp_greater_equal(animation, animation_lengths.size()) || frame < 0 || std::cmp_greater_equal(frame, animation_lengths[animation])) return 0;
    std::size_t absolute = frame;
    for (int index = 0; index < animation; ++index) absolute += animation_lengths[index];
    return absolute;
}
void CharacterModels::animate(const CharacterSkeleton& skeleton, int animation, int frame, int secondaryAnimation, int secondaryFrame, float interpolation, SferaMatrix4x4F* output, bool attachmentsOnly) const {
    if (animation < 0 || std::cmp_greater_equal(animation, skeleton.animation_lengths.size()) || frame < 0 || std::cmp_greater_equal(frame, skeleton.animation_lengths[animation])) { animation = 0; frame = 0; }
    const auto first = skeleton.absoluteFrame(animation, frame);
    const auto second = skeleton.absoluteFrame(secondaryAnimation, secondaryFrame);
    const auto upperFrame = interpolation < 0.01f ? std::nullopt : std::optional(second);
    for (std::size_t bone = 0; bone < skeleton.parents.size(); ++bone) {
        if (!skeleton.parents[bone]) skeleton.calculate(first, upperFrame, bone, root_transform, CharacterSkeleton::Region::Whole, output);
    }
    if (attachmentsOnly && animation == 0 && frame == 0) for (std::size_t bone = 0; bone < skeleton.parents.size(); ++bone) if (std::find(skeleton.attachments.begin(), skeleton.attachments.begin() + 4, bone) == skeleton.attachments.begin() + 4) output[bone] = root_transform;
}
void CharacterModels::initializeBounds() { for (std::size_t index = 0; index < 8; ++index) bounds[index] = {index & 2u ? 1.0f : -1.0f, index & 4u ? -2.5f : 0.0f, index & 1u ? 1.0f : -1.0f}; }
int CharacterModels::classify(const SferaMatrix4x4F& world) const { std::array<SferaVec3F, 8> transformed; std::transform(std::begin(bounds), std::end(bounds), transformed.begin(), [&](const auto& point) { return world.transformPoint(point); }); return SphereRender::SceneRenderer::frustum.classifyPoints(transformed); }
void CharacterModels::setDistances(double minimum, float range) { minimum_distance = minimum; maximum_distance = minimum + range; lod_end = minimum + range * 0.5; lod_start = lod_end * 0.699999988079071; }
void CharacterModels::updateLodDistance() { const auto previous = last_lod_update; last_lod_update = WorldClock::nowTicks(); if (previous == 0u) return; const std::int64_t elapsed = last_lod_update - previous; if (rendered_count < 5u || rendered_count > 10u) { const bool expand = rendered_count < 5u; const float exponent = elapsed * (expand ? 9.999999747378752e-05 : 0.00039999998989515007); const double power = exponent; const float factor = std::pow(expand ? 1.100000023841858 : 0.8999999761581421, power); lod_end *= factor; lod_end = expand ? std::min(lod_end, maximum_distance) : std::max(lod_end, minimum_distance); } rendered_count = 0u; lod_start = lod_end * 0.699999988079071; }
float CharacterModels::visibility(const WorldObject& object) const {
    const auto delta = object.position - g_sfera_world_objects.object(1u)->position;
    const float squared = delta.dot(delta);
    const double squared_distance = squared;
    const float rounded_distance = std::sqrt(squared_distance);
    const double end = lod_end;
    const double fade_distance = rounded_distance;
    const float result = 1.0 - (fade_distance - lod_start) / (end - lod_start);
    return std::clamp(result, 0.0f, 1.0f);
}
const CharacterAppearance& CharacterModels::appearance(const ExtendedWorldObject& object) const { const auto index = -1 - object.render_cache_handle; if (index < 0 || index >= 400) WorldDiagnostics::fail("Invalid character instance"); return instances[index].appearance; }
int CharacterModels::partAnimationLength(const ExtendedWorldObject& object, int animation) const { const auto& skeleton = skeletons[appearance(object).sex]; return animation < 0 || std::cmp_greater_equal(animation, skeleton.animation_lengths.size()) ? -1 : skeleton.animation_lengths[animation]; }
int CharacterModels::usesSmallHelm(int sex, int code) const {
    if (sex == 0) return 0;
    const auto index = code > '9' ? code - 'a' + 10 : code - '0';
    if (index < 0 || std::cmp_greater_equal(index, small_helm.size())) WorldDiagnostics::fail("Invalid character helm code");
    return small_helm[index];
}
std::uint32_t* CharacterModels::parameter(std::span<std::uint32_t> values, int index) {
    if (index < 0 || index >= values.size()) WorldDiagnostics::fail("Character parameter index is out of bounds");
    return &values[index];
}
ExtendedWorldObject* CharacterModels::checkedExtended(WorldObject* object) { if (object == nullptr) return nullptr; if (auto* extended = object->extended()) return extended; const auto* model = g_sfera_world_objects.model(*object); const auto message = std::string("Try to get extended from superstatic: ") + (model == nullptr ? "<none>" : model->name); WorldDiagnostics::fail(message); }
void CharacterModels::setAppearance(int handle, const CharacterAppearance& value) {
    if (handle < 0) { g_sfera_log_runtime.write("Wrong handle: set_char_param\n"); return; }
    auto* object = checkedExtended(g_sfera_world_objects.object(handle));
    if (object == nullptr) { g_sfera_log_runtime.write("Wrong handle: set_char_param\n"); return; }
    if (value.sex < 0 || std::cmp_greater_equal(value.sex, skeletons.size())) WorldDiagnostics::fail("Invalid character sex");
    if (object->render_cache_handle > 0) WorldDiagnostics::fail("Character model has a non-character render cache");
    if (object->render_cache_handle >= 0) { auto slot = std::find_if(std::begin(instances), std::end(instances), [](const auto& entry) { return entry.owner == nullptr; }); if (slot == std::end(instances)) WorldDiagnostics::fail("Character model instance limit reached"); slot->owner = object; object->render_cache_handle = -1 - (slot - instances.begin()); }
    auto& current = instances[-1 - object->render_cache_handle].appearance;
    if (value.parts[12] != 0u) {
        std::string name = "ms";
        name.append(SferaText::fromBytes(std::span(value.parts).subspan(12u, 1u)));
        g_sfera_world_objects.linkModel(handle, name, 3u);
    } else if (current.parts[12] != 0u) g_sfera_world_objects.unlink(handle, 3u);
    current = value;
}
bool CharacterModels::getAppearance(int handle, CharacterAppearance& value) const { if (handle < 0) { g_sfera_log_runtime.write("Wrong handle: get_char_param\n"); return false; } const auto* object = checkedExtended(g_sfera_world_objects.object(handle)); if (object == nullptr || object->render_cache_handle >= 0) return false; value = appearance(*object); return true; }
SferaVec3F CharacterModels::neckPosition(const ExtendedWorldObject& object) const { const auto world = SferaMatrix4x4F::fromEuler(object.position, object.rotation); const auto& skeleton = skeletons[appearance(object).sex]; std::vector<SferaMatrix4x4F> pose(skeleton.parents.size()); animate(skeleton, object.animation, object.frame, object.animation_secondary, object.frame_secondary, object.interpolation, pose.data(), true); const auto neck = skeleton.attachments[6]; const auto combined = (skeleton.initial_pose[neck]).multiplied((pose[neck])); return world.transformPoint({combined.m[3][0], combined.m[3][1], combined.m[3][2]}); }
HRESULT CharacterModels::setMaterial(float opacity, float detail, const SferaVec3F& color) { const float intensity = detail * 0.699999988079071 + 0.30000001192092896; D3DMATERIAL9 material{}; material.Diffuse = {intensity * color.x, intensity * color.y, intensity * color.z, opacity}; material.Ambient = {material.Diffuse.r, material.Diffuse.g, material.Diffuse.b, 0.0f}; auto& device = *g_sfera_graphics_runtime.d3d_runtime; return device.checkResult(device.native_device->SetMaterial(&material), "SetMaterial"); }
int CharacterModels::textureVariants(bool female, std::string_view part) {
    if (part.size() != 1u) throw std::invalid_argument("Texture part must contain one code unit");
    const std::string prefix = std::string("models\\textures\\") + (female ? "w" : "m") + std::string(part);
    g_sfera_files.setErrorReporting(false);
    int count = 0;
    for (;;) {
        // The legacy resource suffix is one encoded byte, including wraparound above 255.
        const std::array<std::uint8_t, 1> suffix{{SferaNumeric::lowByte(SferaNumeric::word(count <= 9 ? '0' + count : 'a' + count - 10))}};
        const auto path = prefix + SferaText::fromBytes(suffix) + "0.dds";
        if (g_sfera_files.fileSize(path) == -1) break;
        ++count;
    }
    g_sfera_files.setErrorReporting(true);
    return count;
}
void CharacterModels::loadSkeleton(const std::string& path, CharacterSkeleton& skeleton) {
    const auto bytes = g_sfera_files.readAll(path);
    const auto data = std::span<const std::uint8_t>(bytes);
    const auto encoded_bones = characterRead<int>(data, 0);
    const auto encoded_frames = characterRead<int>(data, 4);
    if (encoded_bones <= 0 || encoded_frames <= 0) WorldDiagnostics::fail("Invalid character skeleton size");
    const std::size_t bones = encoded_bones, frames = encoded_frames;
    constexpr std::size_t encoded_pose_size = 28;
    if (frames > data.size() / encoded_pose_size / bones) WorldDiagnostics::fail("Truncated character skeleton poses");
    const auto pose_size = bones * frames * encoded_pose_size;
    if (data.size() < 12u || pose_size > data.size() - 12u || bones > (data.size() - 12u - pose_size) / 34u)
        WorldDiagnostics::fail("Truncated character skeleton poses");
    std::size_t offset = 8;
    const auto parent_bytes = characterRange(data, offset, bones * 4); offset += parent_bytes.size();
    const auto name_bytes = characterRange(data, offset, bones * 30); offset += name_bytes.size();
    const auto pose_bytes = characterRange(data, offset, bones * frames * encoded_pose_size); offset += pose_bytes.size();
    const auto encoded_animations = characterRead<int>(data, offset); offset += 4;
    if (encoded_animations <= 0 || std::cmp_greater(encoded_animations, (data.size() - offset) / 4)) WorldDiagnostics::fail("Invalid character animation count");
    const auto animation_bytes = characterRange(data, offset, encoded_animations * 4u);
    CharacterSkeleton replacement;
    replacement.parents.resize(bones); replacement.names.resize(bones); replacement.children.resize(bones); replacement.poses.resize(bones * frames); replacement.animation_lengths.resize(encoded_animations); replacement.initial_pose.resize(bones);
    for (std::size_t bone = 0; bone < bones; ++bone) {
        const auto parent = characterRead<int>(parent_bytes, bone * 4);
        if (parent < -1 || std::cmp_greater_equal(parent, bones) || std::cmp_equal(parent, bone)) WorldDiagnostics::fail("Invalid skeleton parent");
        if (parent >= 0) {
            replacement.parents[bone] = parent;
            replacement.children[parent].push_back(bone);
        }
        const auto encoded_name = name_bytes.subspan(bone * 30, 30);
        const auto terminator = std::find(encoded_name.begin(), encoded_name.end(), 0);
        if (terminator == encoded_name.end()) WorldDiagnostics::fail("Unterminated skeleton bone name");
        auto& name = replacement.names[bone];
        name.assign(encoded_name.begin(), terminator);
        if (name.starts_with('_')) {
            const int slot = name[1] - '0';
            if (slot < 0 || std::cmp_greater_equal(slot, replacement.attachments.size())) WorldDiagnostics::fail("Invalid character attachment name");
            replacement.attachments[slot] = bone;
        }
    }
    // Acyclic parent chains are required before recursive pose evaluation.
    std::vector<std::uint8_t> visited(bones, 0);
    for (std::size_t bone = 0; bone < bones; ++bone) {
        std::optional<std::size_t> current = bone;
        while (current && visited[*current] == 0) { visited[*current] = 1; current = replacement.parents[*current]; }
        if (current && visited[*current] == 1) WorldDiagnostics::fail("Cyclic character skeleton");
        current = bone;
        while (current && visited[*current] == 1) { visited[*current] = 2; current = replacement.parents[*current]; }
    }
    for (std::size_t index = 0; index < replacement.poses.size(); ++index) {
        auto& pose = replacement.poses[index]; const std::size_t start = index * encoded_pose_size;
        pose.rotation = {characterRead<float>(pose_bytes, start), characterRead<float>(pose_bytes, start + 4), characterRead<float>(pose_bytes, start + 8), characterRead<float>(pose_bytes, start + 12)};
        pose.translation = {characterRead<float>(pose_bytes, start + 16), characterRead<float>(pose_bytes, start + 20), characterRead<float>(pose_bytes, start + 24)};
    }
    std::size_t used_frames = 0;
    for (std::size_t index = 0; index < replacement.animation_lengths.size(); ++index) {
        const auto length = characterRead<int>(animation_bytes, index * 4);
        if (length < 0 || std::cmp_greater(length, frames - used_frames)) WorldDiagnostics::fail("Character animation exceeds its pose data");
        replacement.animation_lengths[index] = length; used_frames += length;
    }
    animate(replacement, 0, 0, 0, 0, 0.0f, replacement.initial_pose.data(), false);
    skeleton = std::move(replacement);
}
void CharacterModels::preload(CharacterAsset& asset, const CharacterSkeleton& skeleton) {
    if (asset.geometry != nullptr) return;
    const auto path = directories.at(asset.directory) + asset.name + ".chr";
    const auto bytes = g_sfera_files.readAll(path);
    const auto data = std::span<const std::uint8_t>(bytes);
    if (data.size() < 4 || std::memcmp(data.data(), "sch0", 4) != 0) WorldDiagnostics::fail("preload_model: wrong file format");
    std::span<const std::uint8_t> vertexBytes, indexBytes, structureBytes, boneBytes;
    const auto count = characterRead<int>(data, 8);
    if (count < 0 || std::cmp_greater(count, (data.size() - 12) / 12)) WorldDiagnostics::fail("Invalid character block count");
    for (std::size_t block = 0; block < count; ++block) {
        const auto offset = 12u + block * 12u;
        const auto kind = characterRead<std::uint32_t>(data, offset);
        const auto chunk = characterRange(data, characterRead<std::uint32_t>(data, offset + 4), characterRead<std::uint32_t>(data, offset + 8));
        if (kind == 1) vertexBytes = chunk;
        else if (kind == 2) indexBytes = chunk;
        else if (kind == 6) structureBytes = chunk;
        else if (kind == 7) boneBytes = chunk;
    }
    constexpr std::size_t encoded_vertex_size = 40;
    if (vertexBytes.size() % encoded_vertex_size != 0) WorldDiagnostics::fail("Invalid character vertex block");
    auto geometry = std::make_unique<CharacterGeometry>();
    geometry->vertices.resize(vertexBytes.size() / encoded_vertex_size);
    for (std::size_t index = 0; index < geometry->vertices.size(); ++index) {
        auto& vertex = geometry->vertices[index];
        const std::size_t start = index * encoded_vertex_size;
        vertex.position = {characterRead<float>(vertexBytes, start), characterRead<float>(vertexBytes, start + 4), characterRead<float>(vertexBytes, start + 8)};
        vertex.normal = {characterRead<float>(vertexBytes, start + 12), characterRead<float>(vertexBytes, start + 16), characterRead<float>(vertexBytes, start + 20)};
        vertex.u = characterRead<float>(vertexBytes, start + 24);
        vertex.v = characterRead<float>(vertexBytes, start + 28);
        vertex.first_bone = vertexBytes[start + 32];
        vertex.second_bone = vertexBytes[start + 33];
        vertex.weight = characterRead<float>(vertexBytes, start + 36);
    }
    const auto groupOffset = characterRead<std::uint32_t>(structureBytes, 4);
    const auto group = characterRange(structureBytes, groupOffset, 10);
    const auto triangleCount = characterRead<std::uint32_t>(group, 6);
    if (triangleCount > indexBytes.size() / 6) WorldDiagnostics::fail("Truncated character indices");
    SferaBinary::Reader indexReader(characterRange(indexBytes, 0, triangleCount * 6));
    geometry->indices.resize(triangleCount * 3);
    for (auto& index : geometry->indices) index = indexReader.read<std::uint16_t>();
    const auto boneCount = characterRead<int>(boneBytes, 0);
    if (boneCount < 0 || std::cmp_greater(boneCount, (boneBytes.size() - 4) / 2)) WorldDiagnostics::fail("Invalid character bone names");
    std::vector<std::size_t> remap(boneCount);
    std::size_t offset = 4;
    for (int bone = 0; bone < boneCount; ++bone) {
        const auto length = characterRead<std::int8_t>(boneBytes, offset++);
        if (length <= 0) WorldDiagnostics::fail("Invalid character bone name length");
        const auto name = characterRange(boneBytes, offset, length);
        if (name.back() != 0) WorldDiagnostics::fail("Unterminated character bone name");
        const auto boneName = SferaText::fromBytes(name).substr(0, std::find(name.begin(), name.end(), 0) - name.begin());
        std::size_t match = 0;
        while (match < skeleton.parents.size() && SferaText::compareInsensitive(boneName, skeleton.names[match]) != 0) ++match;
        if (match == skeleton.parents.size()) WorldDiagnostics::fail("Match for bone name not found");
        remap[bone] = match;
        offset += length;
    }
    for (auto& vertex : geometry->vertices) {
        const auto first = vertex.first_bone;
        const auto second = vertex.second_bone;
        if (first >= remap.size() || second >= remap.size()) WorldDiagnostics::fail("Invalid character vertex bone");
        vertex.first_bone = remap[first];
        vertex.second_bone = remap[second];
    }
    for (const auto index : geometry->indices) if (index >= geometry->vertices.size()) WorldDiagnostics::fail("Character face references a missing vertex");
    asset.geometry = std::move(geometry);
}
void CharacterModels::clear() {
    for (auto& slot : instances) {
        if (slot.owner != nullptr) slot.owner->render_cache_handle = 0;
        slot = {};
    }
    part_indices = {};
    parts.clear();
    assets.clear();
    directories.clear();
    for (auto& skeleton : skeletons) skeleton = {};
}
void CharacterModels::load(std::span<const std::string_view> folders) {
    if (folders.size() >= 100) WorldDiagnostics::fail("Character model directory limit exceeded");
    auto replacement = std::make_unique<CharacterModels>();
    replacement->initializeBounds();
    replacement->loadSkeleton("xadd\\man.skl", replacement->skeletons[0]);
    replacement->loadSkeleton("xadd\\woman.skl", replacement->skeletons[1]);
    for (const auto path : folders) {
        if (path.size() >= 200) WorldDiagnostics::fail("Character model directory name too long");
        const auto directory = replacement->directories.size();
        replacement->directories.emplace_back(path);
        _finddata64i32_t entry{};
        const auto handle = ::_findfirst64i32((std::string(path) + "*.chr").c_str(), &entry);
        if (handle == -1) continue;
        struct SearchScope {
            std::intptr_t handle;
            ~SearchScope() { ::_findclose(handle); }
        } search{handle};
        do {
            if ((entry.attrib & _A_SUBDIR) != 0u) continue;
            std::string name(entry.name);
            if (name.size() < 5u || name.size() >= 32u) WorldDiagnostics::fail("Invalid character model filename");
            name.resize(name.find_last_of('.'));
            SferaText::transformBytes(name, SferaText::asciiFold);
            replacement->assets.push_back({std::move(name), directory, {}});
        } while (::_findnext64i32(handle, &entry) == 0);
    }
    ConfigDocument::setStorageMode(ConfigDocument::StorageMode::Plain);
    auto configuration = ConfigDocument::open("xadd\\subobjs.dat");
    const auto countParts = configuration.arraySize("subobjs");
    if (!countParts || *countParts == 0u) WorldDiagnostics::fail("wrong format of subobjs.dat");
    replacement->parts.resize(*countParts);
    for (std::size_t index = 0; index < *countParts; ++index) {
        const auto* record = configuration.objectAt("subobjs", index);
        const auto code = record == nullptr ? std::nullopt : record->text("s");
        const auto name = record == nullptr ? std::nullopt : record->text("m");
        if (!code || !name) WorldDiagnostics::fail("wrong format of subobjs.dat");
        const auto asset = std::find_if(replacement->assets.begin(), replacement->assets.end(), [&](const auto& value) { return value.name == *name; });
        if (asset == replacement->assets.end()) WorldDiagnostics::fail(std::format("char model not found. name={}", *name));
        auto& part = replacement->parts[index];
        part.asset = asset - replacement->assets.begin();
        part.textures.fill(-1);
        const auto textures = record->arraySize("t");
        if (!textures || *textures == 0u || *textures > part.textures.size()) WorldDiagnostics::fail("wrong format of subobjs.dat");
        for (std::size_t texture = 0; texture < *textures; ++texture) {
            const auto textureName = record->textAt("t", texture);
            if (!textureName) WorldDiagnostics::fail("wrong format of subobjs.dat");
            part.textures[texture] = g_sfera_textures.find(*textureName);
            if (part.textures[texture] == -1) WorldDiagnostics::fail(std::format("texture for char model not found. name={}", *textureName));
        }
        if (code->size() != 3u || ((*code)[0] != 'm' && (*code)[0] != 'w') || (*code)[1] < 'a' || (*code)[1] > 'z') WorldDiagnostics::fail("wrong format of subobjs.dat");
        replacement->part_indices[(*code)[0] == 'w'][(*code)[1] - 'a'][SferaText::byteValue((*code)[2])] = index;
    }
    const auto helms = configuration.arraySize("womanhelmsmall");
    if (!helms || *helms == 0u || *helms > replacement->small_helm.size()) WorldDiagnostics::fail("wrong format of subobjs.dat");
    for (std::size_t index = 0; index < *helms; ++index) {
        const auto value = configuration.integerAt("womanhelmsmall", index);
        if (!value) WorldDiagnostics::fail("wrong format of subobjs.dat");
        replacement->small_helm[index] = *value;
    }
    clear();
    *this = std::move(*replacement);
}
void CharacterModels::drawPart(int sex, int kind, std::uint8_t model, int visibility, const CharacterSkeleton& skeleton, const SferaMatrix4x4F* pose, bool cull, int transparent, int textureCode, std::uint32_t passes) {
    if (sex < 0 || std::cmp_greater_equal(sex, std::size(skeletons)) || kind < 0 || std::cmp_greater_equal(kind, part_indices[sex].size())) WorldDiagnostics::fail("Invalid character part selector"); const auto selected = part_indices[sex][kind][model];
    if (!selected) return;
    const auto& part = parts.at(*selected);
    auto& asset = assets.at(part.asset);
    preload(asset, skeleton);
    const auto& geometry = *asset.geometry;
    if (textureCode == 0) textureCode = '0'; if (!((textureCode >= '0' && textureCode <= '9') || (textureCode >= 'a' && textureCode <= 'z'))) WorldDiagnostics::fail("Invalid character texture code");
    std::vector<SphereRender::PositionNormalUvVertex> skinned(geometry.vertices.size());
    for (std::size_t vertex = 0; vertex < geometry.vertices.size(); ++vertex) {
        const auto& input = geometry.vertices[vertex]; auto& output = skinned[vertex]; output.u = input.u; output.v = input.v;
        const auto first = pose[input.first_bone].transposed(); output.position = first.transformPoint(input.position); auto basis = first; basis.m[0][3] = basis.m[1][3] = basis.m[2][3] = 0.0f; output.normal = basis.transformPoint(input.normal);
        if (input.weight < 0.9900000095367432) { const auto second = pose[input.second_bone].transposed(); const auto position = second.transformPoint(input.position); basis = second; basis.m[0][3] = basis.m[1][3] = basis.m[2][3] = 0.0f; const auto normal = basis.transformPoint(input.normal); output.position = SferaMath::interpolate(position, output.position, input.weight); output.normal = SferaMath::interpolate(normal, output.normal, input.weight); }
    }
    if ((passes & 2u) != 0u) g_sfera_shadows->projectVertices(skinned.data(), skinned.size(), geometry.indices.data(), geometry.indices.size());
    if ((passes & 1u) == 0u) return;
    const auto variant = textureCode > '9' ? textureCode - 'a' + 10 : textureCode - '0'; if (std::cmp_greater_equal(variant, std::size(part.textures))) WorldDiagnostics::fail("Character texture variant is out of range"); auto texture = part.textures[variant]; if (texture == -1) texture = part.textures[0]; if (texture == -1) WorldDiagnostics::fail("Character texture is missing"); SceneRenderer::bindTexture(texture);
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    auto vertexData = device.model_vertices.lock(skinned.size());
    std::copy(skinned.begin(), skinned.end(), vertexData.data());
    vertexData.unlock();
    std::uint32_t flags = visibility == 2 && SphereRender::SceneRenderer::secondary_pass == 0u ? CD3D9Device::disable_clipping : 0u; if (!cull) flags |= CD3D9Device::two_sided;
    auto indices = device.indices_primary.lock(geometry.indices.size());
    std::copy(geometry.indices.begin(), geometry.indices.end(), indices.data());
    indices.unlock();
    device.drawBuffer(vertexData.buffer(), D3DPT_TRIANGLELIST, flags | CD3D9Device::lighting,
        vertexData.first(), skinned.size(), indices.buffer(), geometry.indices.size(), indices.first(),
        sizeof(SphereRender::PositionNormalUvVertex));
}
void CharacterModels::updateEffectFrames(ExtendedWorldObject& object, const CharacterSkeleton& skeleton, std::span<SferaMatrix4x4F> pose, const SferaMatrix4x4F& world) const {
    auto& first = pose[skeleton.attachments[4]]; first = (skeleton.initial_pose[skeleton.attachments[4]]).multiplied((first)); object.effect_frame_position_a = world.transformPoint({first.m[3][0], first.m[3][1], first.m[3][2]}); first.m[3][0] = first.m[3][1] = first.m[3][2] = 0.0f; auto firstFrame = (world).multiplied((first)); firstFrame.m[0][3] = firstFrame.m[1][3] = firstFrame.m[2][3] = 0.0f; object.effect_frame_transform_a = firstFrame;
    auto& second = pose[skeleton.attachments[5]]; second = (skeleton.initial_pose[skeleton.attachments[5]]).multiplied((second)); object.effect_frame_position_b = world.transformPoint({second.m[3][0], second.m[3][1], second.m[3][2]});
    auto& attached = pose[skeleton.attachments[0]]; object.effect_frame_position_c = world.transformPoint({attached.m[3][0], attached.m[3][1], attached.m[3][2]}); attached.m[3][0] = attached.m[3][1] = attached.m[3][2] = 0.0f; attached = attached.transposed(); auto attachmentFrame = (world).multiplied((attached)); attachmentFrame.m[0][3] = attachmentFrame.m[1][3] = attachmentFrame.m[2][3] = 0.0f; object.effect_frame_transform_b = attachmentFrame; object.effect_frame_transform_c = attachmentFrame;
}
void CharacterModels::drawLowDetail(std::uint32_t handle) {
    auto* object = checkedExtended(g_sfera_world_objects.object(handle)); if (!object->render_enabled) return;
    const auto world = SferaMatrix4x4F::fromEuler(object->position, object->rotation); const auto visible = classify(world); if (visible == 0) return; const auto transform = world.transposed(); auto& device = *g_sfera_graphics_runtime.d3d_runtime; device.setTransform(D3DTS_WORLD, transform);
     g_sfera_light_runtime.setDirectionalLight({-SphereRender::SceneRenderer::sun_direction.x, -SphereRender::SceneRenderer::sun_direction.y, -SphereRender::SceneRenderer::sun_direction.z}, {SphereRender::SceneRenderer::environment.sunColor.x, SphereRender::SceneRenderer::environment.sunColor.y, SphereRender::SceneRenderer::environment.sunColor.z}); SceneRenderer::activateObjectLights(handle); SceneRenderer::setAmbientColor();
    const auto& parameters = appearance(*object); const auto& skeleton = skeletons[parameters.sex]; std::vector<SferaMatrix4x4F> pose(skeleton.parents.size()); animate(skeleton, object->animation, object->frame, object->animation_secondary, object->frame_secondary, object->interpolation, pose.data(), true);
    setMaterial(object->scale, 0.0f, {1.0f, 1.0f, 1.0f}); if (object->scale != 1.0f) device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA); drawPart(parameters.sex, 'd' - 'a', '0', visible, skeleton, pose.data(), true, object->scale != 1.0f, '0', 1u); setMaterial(1.0f, 1.0f, {1.0f, 1.0f, 1.0f}); if (object->scale != 1.0f) device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE); characterDisableLights(1208u); updateEffectFrames(*object, skeleton, pose, world);
}
void CharacterModels::draw(std::uint32_t handle, std::uint32_t color) {
    const ShadowMap::Pass shadowPass(*g_sfera_shadows);
    const SferaRestore projectionOpacity(SceneRenderer::shadow_projection_opacity);
    auto* object = checkedExtended(g_sfera_world_objects.object(handle)); if (!object->render_enabled) return; const auto world = SferaMatrix4x4F::fromEuler(object->position, object->rotation); const auto visible = classify(world); if (visible == 0) return; ++rendered_count;
    const float detail = !g_sfera_graphics_runtime.lods_enabled ? 1.0f : visibility(*object); if (detail < 0.001f) { drawLowDetail(handle); return; }
    auto& device = *g_sfera_graphics_runtime.d3d_runtime; const auto transform = world.transposed(); device.setTransform(D3DTS_WORLD, transform);  g_sfera_light_runtime.setDirectionalLight({-SphereRender::SceneRenderer::sun_direction.x, -SphereRender::SceneRenderer::sun_direction.y, -SphereRender::SceneRenderer::sun_direction.z}, {SphereRender::SceneRenderer::environment.sunColor.x, SphereRender::SceneRenderer::environment.sunColor.y, SphereRender::SceneRenderer::environment.sunColor.z}); SceneRenderer::activateObjectLights(handle); SceneRenderer::setAmbientColor();
    float shadowFade = 0.0f; ShadowMap::prepareObject(handle, *object, 1.0f, 1.0f, shadowFade);
    const auto& parameters = appearance(*object); const auto& skeleton = skeletons[parameters.sex]; std::vector<SferaMatrix4x4F> pose(skeleton.parents.size()); animate(skeleton, object->animation, object->frame, object->animation_secondary, object->frame_secondary, object->interpolation, pose.data(), true);
    const auto tint = SferaColor::fromArgb(color);
    setMaterial(object->scale, detail, {tint.red() / 255.0f, tint.green() / 255.0f, tint.blue() / 255.0f}); if (object->scale != 1.0f) device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
    const auto drawComponent = [&](int kind, std::uint8_t model, int texture = '0', std::uint32_t passes = 3u, bool cull = true) { drawPart(parameters.sex, kind, model, visible, skeleton, pose.data(), cull, object->scale != 1.0f, texture, passes); };
    const auto& p = parameters.parts; if (p[2] != 0u) { drawComponent(2, p[2]); drawComponent(4, p[2], p[4]); } else { drawComponent(21, p[3]); drawComponent(11, p[3], p[4]); } drawComponent(6, p[6]); drawComponent(19, p[1]); drawComponent(1, p[0]);
    const std::uint32_t headPasses = handle == g_sfera_world_objects.controlled_object_handle ? 2u : 3u; drawComponent(5, p[7], p[8], headPasses); if (p[11] != 0u) drawComponent(7, p[11], '0', headPasses);
    if (p[11] == 0u || usesSmallHelm(parameters.sex, p[11]) != 0) { device.checkResult(device.native_device->SetRenderState(D3DRS_ALPHAREF, 128u), "SetRenderState"); drawComponent(p[11] == 0u ? 17 : 16, p[9], p[10], headPasses, false); device.checkResult(device.native_device->SetRenderState(D3DRS_ALPHAREF, 1u), "SetRenderState"); }
    SceneRenderer::setOpacity(true);
    for (std::size_t slot = 0; slot < 5u; ++slot) if (object->linked_objects[slot] != 0u && !(slot == 3u && handle == g_sfera_world_objects.controlled_object_handle)) { auto& matrices = SphereRender::ModelPose::attachment_transforms; if (slot >= matrices.size()) WorldDiagnostics::fail("Character attachment matrix is missing"); matrices[slot] = (world).multiplied((pose[skeleton.attachments[slot]].transposed())); SceneRenderer::drawModel(object->linked_objects[slot]); }
    SceneRenderer::setOpacity(false); setMaterial(1.0f, 1.0f, {1.0f, 1.0f, 1.0f}); if (object->scale != 1.0f) device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE); ShadowMap::drawObject(*object, 1.0f, shadowFade); characterDisableLights(1085u); updateEffectFrames(*object, skeleton, pose, world);
}
}

SferaPlaneF SferaPlaneF::throughPoint(const SferaVec3F& normal, const SferaVec3F& point) {
    const std::array<double, 3> components{normal.x, normal.y, normal.z};
    SferaPlaneF result{normal, 0.0f};
    result.distance = -components[0] * point.x - components[1] * point.y - components[2] * point.z;
    return result;
}

SferaPlaneF SferaPlaneF::fromTriangle(const SferaVec3F& first, const SferaVec3F& second, const SferaVec3F& third) {
    const std::array<double, 3> a{first.x, first.y, first.z};
    const std::array<double, 3> b{second.x, second.y, second.z};
    const std::array<double, 3> c{third.x, third.y, third.z};
    SferaVec3F normal;
    normal.x = (a[2] + b[2]) * (a[1] - b[1]) + (c[1] - a[1]) * (a[2] + c[2]) + (b[1] - c[1]) * (b[2] + c[2]);
    normal.y = (c[2] - a[2]) * (a[0] + c[0]) + (a[2] - b[2]) * (a[0] + b[0]) + (b[2] - c[2]) * (b[0] + c[0]);
    normal.z = (c[0] - a[0]) * (c[1] + a[1]) + (a[0] - b[0]) * (a[1] + b[1]) + (b[0] - c[0]) * (c[1] + b[1]);
    normal.normalize();
    return throughPoint(normal, first);
}

namespace SphereRender {
GameCamera::GameCamera() : tangent_half_fov(std::tan(0.5)) {}
void GameCamera::setViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height, float aspect) {
    viewport_x = x;
    viewport_y = y;
    viewport_width = width;
    viewport_height = height;
    aspect_scale = aspect;
    const float width_pixels = width, height_pixels = height;
    center_x = width_pixels * 0.5 + x;
    center_y = height_pixels * 0.5 + y;
    pixel_scale_x = 2.0 / width_pixels;
    pixel_scale_y = aspect * (2.0 / height_pixels);
}

void GameCamera::setPerspective(float near_plane, float far_plane, float angle) {
    if (near_distance == near_plane && far_distance == far_plane && field_of_view == angle) return;
    near_distance = near_plane;
    far_distance = far_plane;
    field_of_view = angle;
    const float half_angle = angle * 0.5;
    const double radians = half_angle;
    tangent_half_fov = std::tan(radians);
    off_axis = false;
    points_current_ = false;
    planes_current_ = false;
}

void GameCamera::setTransform(const SferaMatrix4x4F& matrix) { transform = matrix; points_current_ = false; planes_current_ = false; }
void GameCamera::transformPoints(std::span<SferaVec3F> destination, std::span<const SferaVec3F> source) const { for (std::size_t index = 0u; index < source.size(); ++index) destination[index] = transform.transformPoint(source[index]); }
SferaVec3F GameCamera::cameraPoint(const SferaVec3F& world) const { return transform.inverseTransformPoint(world); }

bool GameCamera::project(const SferaVec3F& world, SferaVec3F& screen) const {
    const auto local = cameraPoint(world);
    const double depth = local.x;
    if (near_distance > depth || far_distance < depth) return false;
    screen.x = center_x - local.y / (depth * tangent_half_fov * pixel_scale_x);
    screen.y = center_y - local.z / (depth * tangent_half_fov * pixel_scale_y);
    const double far_limit = far_distance, maximum = maximum_depth;
    screen.z = ((depth - near_distance) * far_limit / (depth * (far_limit - near_distance))) * (maximum - minimum_depth) + minimum_depth;
    return true;
}

void GameCamera::buildPoints() {
    points_[0] = {transform.m[0][3], transform.m[1][3], transform.m[2][3]};
    float left, right, top, bottom;
    if (off_axis) {
        const double far_limit = far_distance;
        const float rounded_scale = far_limit / window_depth;
        const double scale = rounded_scale, width = window_width, height = window_height;
        left = offset_x * scale;
        right = (width + offset_x) * scale;
        top = scale * offset_y;
        bottom = scale * (height + offset_y);
    } else {
        const double far_limit = far_distance;
        const auto edge = [&](double center, std::uint32_t pixel, float scale) {
            const float direction = (center - pixel) * tangent_half_fov * scale;
            return direction * far_limit;
        };
        left = edge(center_x, rectangle_.left, pixel_scale_x); right = edge(center_x, rectangle_.right, pixel_scale_x); top = edge(center_y, rectangle_.top, pixel_scale_y); bottom = edge(center_y, rectangle_.bottom, pixel_scale_y);
    }
    points_[1] = {far_distance, left, top}; points_[2] = {far_distance, right, top}; points_[3] = {far_distance, right, bottom}; points_[4] = {far_distance, left, bottom}; points_[5] = {near_distance, 0.0f, 0.0f};
    transformPoints(std::span(points_).subspan(1u), std::span<const SferaVec3F>(points_).subspan(1u));
    points_current_ = true;
}



SferaPlaneF GameCamera::boundaryPlane(const SferaVec3F& a, const SferaVec3F& b, const SferaVec3F& c) {
    return SferaPlaneF::fromTriangle(a, b, c);
}

void GameCamera::buildPlanes() {
    for (std::size_t side = 0u; side < 4u; ++side) planes_.planes[side + 1u] = boundaryPlane(points_[0], points_[(side + 3u) % 4u + 1u], points_[side + 1u]);
    planes_.planes[5] = boundaryPlane(points_[4], points_[3], points_[2]);
    const auto& far_normal = planes_.planes[5].normal;
    planes_.planes[0].normal = {-far_normal.x, -far_normal.y, -far_normal.z};
    planes_.planes[0].distance = far_normal.dot<double, true>(points_[5]);
    planes_current_ = true;
}

void GameCamera::volume(const CameraRectangle* rectangle, const SferaFrustumF** planes, const SferaVec3F** points) {
    if (off_axis && rectangle != nullptr) { if (planes != nullptr) *planes = nullptr; if (points != nullptr) *points = nullptr; return; }
    const CameraRectangle requested = rectangle == nullptr ? CameraRectangle{viewport_x, viewport_y, viewport_x + viewport_width - 1u, viewport_y + viewport_height - 1u} : *rectangle;
    if (!(requested == rectangle_)) { rectangle_ = requested; points_current_ = false; planes_current_ = false; }
    if (!points_current_) buildPoints();
    if (planes != nullptr && !planes_current_) buildPlanes();
    if (planes_.planes[0].evaluate(points_[0]) > 0.0) for (auto& plane : planes_.planes) { plane.normal = {-plane.normal.x, -plane.normal.y, -plane.normal.z}; plane.distance = -plane.distance; }
    if (planes != nullptr) *planes = &planes_;
    if (points != nullptr) *points = points_.data();
}

bool GameCamera::projectObjectTop(std::uint32_t handle, SferaVec3F& output, float height_factor) const {
    const auto* object = g_sfera_world_objects.object(handle);
    if (object == nullptr) { WorldDiagnostics::message.clear(); WorldDiagnostics::appendScriptContext("Project_TopCharToScreen: wrong handle"); WorldDiagnostics::flushScriptContext(); return false; }
    const auto* model = g_sfera_world_objects.model(*object);
    const auto* camera = g_sfera_world_objects.object(1u);
    if (model == nullptr || camera == nullptr) return false;
    SferaVec3F top = object->position;
    const double height = top.y;
    top.y = height + (model->collision_kind == SphereRender::CollisionKind::AxisAlignedBounds ? model->minimum.y : model->oriented_corners.corners[0].y);
    auto offset = top - camera->position;
    offset.y = 0.0f;
    const float squared = SferaMath::planarSquared(offset.z, offset.x);
    const float scale = 0.10000000149011612 / squared;
    offset = offset * scale;
    const auto base = object->position - offset;
    if (top.y < camera->position.y) offset = {-offset.x, -offset.y, -offset.z};
    top = top + offset;
    SferaVec3F projected_top{}, projected_base{};
    const bool top_visible = project(top, projected_top);
    if (height_factor == 1.0f) { output = projected_top; return top_visible; }
    const bool base_visible = project(base, projected_base);
    if (!top_visible || !base_visible) return false;
    output = projected_base + (projected_top - projected_base) * height_factor;
    return true;
}

void GameCamera::cameraAxes(SferaVec3F& forward, SferaVec3F& up) {
    g_sfera_world_objects.recalculateBasis(1u);
    const auto* camera = g_sfera_world_objects.extendedObject(1u);
    if (camera == nullptr) WorldDiagnostics::fail("Camera object is missing");
    forward = camera->orientation_basis[0]; up = camera->orientation_basis[1];
}

void GameCamera::rebuildVisibleVolume(std::uint32_t left, std::uint32_t top, std::uint32_t right, std::uint32_t bottom) {
    const CameraRectangle rectangle{left, top, right, bottom};
    const SferaFrustumF* frustum = nullptr; const SferaVec3F* points = nullptr;
    g_sfera_camera.volume(&rectangle, &frustum, &points);
    if (frustum == nullptr || points == nullptr) return;
    SphereRender::SceneRenderer::frustum = *frustum;
    std::copy_n(points, 5u, g_sfera_camera.frame_corners);
    SferaVec3F minimum = points[0], maximum = points[0];
    for (std::size_t index = 1u; index < 5u; ++index) for (std::size_t axis = 0u; axis < 3u; ++axis) { minimum.setComponent(axis, std::min(minimum.component(axis), points[index].component(axis))); maximum.setComponent(axis, std::max(maximum.component(axis), points[index].component(axis))); }
    const auto fixed = [](float value) { return SferaNumeric::truncateInt64(value * 1024.0); };
    SphereRender::SceneRenderer::projected_terrain_bounds = {fixed(minimum.x), fixed(maximum.x), fixed(minimum.y), fixed(maximum.y), fixed(minimum.z), fixed(maximum.z)};
    SceneRenderer::collectLights();
}

void GameCamera::setupViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height) {
    if (width == 0u || height == 0u) WorldDiagnostics::fail("Empty camera viewport");
    SferaVec3F forward, up; cameraAxes(forward, up);
    const auto* camera = g_sfera_world_objects.object(1u);
    const auto target = camera->position + forward;
    SferaMatrix4x4F view_matrix = SferaMatrix4x4F::identity();
    SferaMatrix4x4F projection_matrix{};
    auto view_z = camera->position - target;
    view_z.normalize();
    auto view_x = up.cross(view_z);
    view_x.normalize();
    const auto view_y = view_z.cross(view_x);
    view_matrix.m[0][0] = view_x.x;
    view_matrix.m[0][1] = view_y.x;
    view_matrix.m[0][2] = view_z.x;
    view_matrix.m[1][0] = view_x.y;
    view_matrix.m[1][1] = view_y.y;
    view_matrix.m[1][2] = view_z.y;
    view_matrix.m[2][0] = view_x.z;
    view_matrix.m[2][1] = view_y.z;
    view_matrix.m[2][2] = view_z.z;
    view_matrix.m[3][0] = -view_x.dot(camera->position);
    view_matrix.m[3][1] = -view_y.dot(camera->position);
    view_matrix.m[3][2] = -view_z.dot(camera->position);
    const float width_value = width, height_value = height;
    const double rounded_width = width_value, rounded_height = height_value;
    const float aspect = rounded_width / height_value;
    const float half_angle = g_sfera_camera.field_of_view * 0.5;
    const double radians = half_angle;
    const float tangent = std::tan(radians);
    const double rounded_tangent = tangent;
    const float vertical_tangent = rounded_tangent / aspect;
    const double vertical_slope = vertical_tangent;
    const float vertical_half_angle = std::atan(vertical_slope);
    const float vertical_angle = vertical_half_angle * 2.0;
    const float projection_y = 1.0f / std::tan(vertical_angle * 0.5f);
    const float depth_range = g_sfera_camera.near_distance - g_sfera_camera.far_distance;
    projection_matrix = {};
    projection_matrix.m[0][0] = projection_y / aspect;
    projection_matrix.m[1][1] = projection_y;
    projection_matrix.m[2][2] = g_sfera_camera.far_distance / depth_range;
    projection_matrix.m[2][3] = -1.0f;
    projection_matrix.m[3][2] = g_sfera_camera.near_distance * g_sfera_camera.far_distance / depth_range;
    g_sfera_camera.frame_transform = SferaMatrix4x4F::fromEuler(camera->position, camera->rotation);
    g_sfera_camera.setTransform(g_sfera_camera.frame_transform.multiplied(SphereRender::ModelPose::coordinate_basis));
    g_sfera_camera.setViewport(x, y, width, height, rounded_height / width_value);
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    const D3DVIEWPORT9 viewport{x, y, width, height, 0.0f, 1.0f};
    device.native_device->SetViewport(&viewport);
    const auto identity = SferaMatrix4x4F::identity();
    device.setTransform(D3DTS_WORLD, identity); device.setTransform(D3DTS_VIEW, view_matrix); device.setTransform(D3DTS_PROJECTION, projection_matrix);
    rebuildVisibleVolume(x, y, x + width - 1u, y + height - 1u);
}

GameCamera::Frame::Frame(std::uint32_t mode, bool reflection, float water_height) {
    auto* camera = g_sfera_world_objects.extendedObject(1u);
    if (camera == nullptr) WorldDiagnostics::fail("Camera object is missing");
    auto* controlled = g_sfera_world_objects.controlledObject();
    if (g_sfera_camera.controlled_observer_mode != 0u && controlled != nullptr) {
        SferaVec3F neck; ModelPose::neckPosition(neck);
        const float heading = controlled->rotation.x;
        camera->position = {controlled->position.x, neck.y - 0.10000000149011612f, controlled->position.z};
        g_sfera_world_objects.recalculateBasis(1u);
        const float lean = camera->orientation_basis[0].y * 0.30000001192092896f;
        controlled_handle_ = g_sfera_world_objects.controlled_object_handle; controlled_position_ = controlled->position;
        controlled->position.x = (controlled->position.x - neck.x) + controlled->position.x; controlled->position.z = (controlled->position.z - neck.z) + controlled->position.z;
        if (lean > 0.0f) {
            controlled->position.x = controlled->position.x + std::sin(heading) * lean;
            controlled->position.z = controlled->position.z - std::cos(heading) * lean;
        }
        else camera->position.y = camera->position.y - lean * 0.20000000298023224;
    }
    const auto save_camera = [&] { camera_position_ = camera->position; camera_rotation_ = camera->rotation; restore_camera_ = true; };
    if (reflection) {
        save_camera();
        const double precise_water_height = water_height;
        camera->position.y = (water_height + precise_water_height) - camera->position.y;
        g_sfera_world_objects.reflectReferenceOrientation();
    }
    if (mode == 2u) { save_camera(); if (controlled != nullptr) camera->position = controlled->position; camera->position.y = camera->position.y - 1000.0; camera->rotation = {-4.7123894691467285f, 1.5707964897155762f, -1.5707964897155762f}; g_sfera_world_objects.recalculateBasis(1u); }
}

GameCamera::Frame::~Frame() noexcept {
    if (auto* controlled = g_sfera_world_objects.object(controlled_handle_)) controlled->position = controlled_position_;
    if (restore_camera_) if (auto* camera = g_sfera_world_objects.object(1u)) {
        camera->position = camera_position_; camera->rotation = camera_rotation_;
        g_sfera_world_objects.recalculateBasis(1u);
    }
}
}

namespace SphereRender {
namespace {
CD3D9Device& sceneDevice() { return *g_sfera_graphics_runtime.d3d_runtime; }
void sceneRenderState(D3DRENDERSTATETYPE state, DWORD value) { auto& device = sceneDevice(); device.checkResult(device.native_device->SetRenderState(state, value), "SetRenderState"); }
bool sceneBoundsOverlap(const SferaVec3F& minimum, const SferaVec3F& maximum, const SferaLightRecord& light) { return !(minimum.x > light.bounds_max.x || minimum.y > light.bounds_max.y || minimum.z > light.bounds_max.z || maximum.x < light.bounds_min.x || maximum.y < light.bounds_min.y || maximum.z < light.bounds_min.z); }

}

bool SceneRenderer::bindTexture(int texture) { auto& device = sceneDevice(); device.checkResult(device.native_device->SetTexture(0u, g_sfera_textures.resource(texture)), "SetTexture"); return g_sfera_textures.hasAlpha(texture); }
void SceneRenderer::textureSize(int texture, std::uint32_t* dimensions) { const auto size = g_sfera_textures.size(texture); dimensions[0] = SferaNumeric::word(size.width); dimensions[1] = SferaNumeric::word(size.height); }
void SceneRenderer::setAmbientColor() {
    const auto color = SphereRender::SceneRenderer::environment.ambientColor; const std::uint32_t red = SferaNumeric::truncatedWord(color.x); const std::uint32_t green = SferaNumeric::truncatedWord(color.y); const std::uint32_t blue = SferaNumeric::truncatedWord(color.z);
    sceneRenderState(D3DRS_AMBIENT, SferaColor::rgba(red, green, blue).argb());
}
void SceneRenderer::setMaterialColor(int red, int green, int blue) {
    D3DMATERIAL9 material{}; material.Diffuse.r = red / 255.0; material.Diffuse.g = green / 255.0; material.Diffuse.b = blue / 255.0; material.Diffuse.a = 1.0f; material.Ambient = material.Diffuse; material.Specular.a = 1.0f;
    auto& device = sceneDevice(); device.checkResult(device.native_device->SetMaterial(&material), "SetMaterial");
}
std::uint32_t SceneRenderer::terrainShade(std::uint32_t shade, float x, float z) {
    if ((TerrainAssets::color_map_ready & 1u) == 0u) { TerrainAssets::color_map_ready |= 1u; TerrainAssets::color_map.reset(); }
    if (shade == 0u || SphereRender::SceneRenderer::interior_scene == 1u) return 255u;
    const auto planting = TerrainAssets::color_map.plantingType(x, z); const auto terrain = std::array<std::uint32_t, 4>{255u, 200u, 150u, 100u}.at(planting); const int scaled = (255u - terrain) * (255u - shade); return (scaled / 256) + terrain;
}
void SceneRenderer::setObjectMaterial(WorldObject& object, std::uint32_t shade, const std::array<float, 3>& variation) {
    if (object.lighting_color == 0u) object.lighting_color = Material::randomColor(variation);
    const auto intensity = terrainShade(shade, object.position.x, object.position.z); const auto color = object.lighting_color;
    const auto shaded = SferaColor::fromArgb(color).scaledRgb(intensity, 256u);
    setMaterialColor(shaded.red(), shaded.green(), shaded.blue());
}
void SceneRenderer::buildColorRemap(double exponent, double floor) {
    for (int index = 0; index < 256; ++index) { const int value = (std::pow(index / 255.0, exponent) * (1.0 - floor) + floor) * 255.0; const std::uint8_t channel = std::clamp(value, 0, 255); SphereRender::SceneRenderer::color_remap[index] = channel; }
}
void SceneRenderer::modelFade(float distance, float power, float& fade, float& remaining) {
    if (distance <= 0.20000000298023224) { fade = 0.0f; remaining = 1.0f; return; }
    const float end = (power > 0.0f ? 1.0 : 0.0) + 0.20000000298023224;
    if (distance >= end) { fade = 1.0f; remaining = 0.0f; return; }
    const double transition = (distance - 0.20000000298023224) / 0.019999999552965164;
    const float power_base = transition;
    fade = std::pow(power_base, power);
    remaining = 1.0 - transition;
}
std::uint32_t SceneRenderer::materialVariant(std::uint32_t first, std::uint32_t second, std::uint32_t third) { return 4u * first + 2u * second + third; }
bool SceneRenderer::hasMaterialVariant(std::uint32_t object, int variant) {
    const auto* model = g_sfera_world_objects.model(*g_sfera_world_objects.object(object));
    if (model != nullptr) for (const auto* material : model->materials) { if (material == nullptr) throw std::out_of_range("Model material reference"); if (!SferaText::asciiEqual(material->name, "default")) return variant >= 0 && std::cmp_less(variant, material->textures.size()); }
    return false;
}
void SceneRenderer::setMaterialVariant(std::uint32_t object, int variant) { auto* instance = g_sfera_world_objects.extendedObject(object); if (instance != nullptr && instance->render_cache_handle >= 0) instance->render_cache_handle = variant; }
std::uint32_t SceneRenderer::setOpacity(std::uint32_t opacity) { return SphereRender::SceneRenderer::shadow_projection_opacity = opacity & 255u; }
void SceneRenderer::adaptFog() {
    if (!g_sfera_graphics_runtime.auto_fog) return;
    const float speed = SphereRender::SceneRenderer::fog_adaptation_delay > 0u ? 0.019999999552965164f : 0.0010000000474974513f;
    if (SphereRender::SceneRenderer::fog_adaptation_delay > 0u) --SphereRender::SceneRenderer::fog_adaptation_delay;
    auto& fog = g_sfera_graphics_runtime.saved_fog_distance; const auto interval = SferaClientApplication::measured_fps;
    if (interval < 20.0f) {
        const float adjusted = fog * (1.0 - speed);
        fog = std::max(30.0f, adjusted);
    } else if (interval > 28.0f) {
        const float adjusted = fog * (1.0 + speed);
        fog = std::min(200.0f, adjusted);
    }
}
void SceneRenderer::raiseDistantObject(std::uint32_t handle) {
    auto& object = *g_sfera_world_objects.object(handle); const auto delta = object.position - g_sfera_world_objects.object(1u)->position; const float length = delta.length<double, float>(); const float distance_factor = (length - 45.0) / 15.0; const float amount = std::clamp(distance_factor, 0.0f, 1.0f); object.position.y = object.position.y + amount * 1.399999976158142;
}

void SceneRenderer::activateObjectLights(std::uint32_t handle) {
    SphereWorld::ContactQuery::updateBounds(handle); const auto& object = *g_sfera_world_objects.object(handle); const auto& model = *g_sfera_world_objects.model(object); const std::size_t maximum = model.animation_lengths.size() == 0u && model.bones.size() > 2u && model.radius > 15.0f ? 30u : 7u;
    auto& count = g_sfera_light_runtime.candidate_count; count = 0u; auto** visible = g_sfera_light_runtime.visible_handles.data();
    for (std::uint32_t index = 0; index < g_sfera_light_runtime.visible_handles.size() && count < maximum; ++index) {
        const auto& light = *visible[index]; if (!sceneBoundsOverlap(object.bounds_minimum, object.bounds_maximum, light)) continue;
        g_sfera_light_runtime.render_candidates[count] = light; g_sfera_light_runtime.render_candidate_indices[count] = index + 1u; g_sfera_light_runtime.render_candidate_active[count] = false; ++count;
    }
    if (count > 7u) return;
    for (std::size_t index = 0; index < count; ++index) { g_sfera_light_runtime.render_candidate_active[index] = true; g_sfera_light_runtime.setActive(g_sfera_light_runtime.render_candidate_indices[index], true, 14846u); }
}
void SceneRenderer::classifyBone(std::size_t index) {
    const auto& model = *SphereRender::ModelPose::active_model; const auto& bone = model.bones[index]; auto& result = SphereRender::SceneRenderer::bone_visibility[index];
    if (bone.has_geometry) {
        if (model.bones.size() == 2u) { result.resource = SphereRender::SceneRenderer::model_visibility; result.mask = (1u << (g_sfera_light_runtime.candidate_count & 31u)) - 1u; }
        else {
            std::array<SferaVec3F, 8> corners; for (std::size_t vertex = 0; vertex < corners.size(); ++vertex) corners[vertex] = SphereRender::ModelPose::current_frame.transformPoint(bone.bounds().corners.corners[vertex]);
            result.resource = SphereRender::SceneRenderer::frustum.classifyPoints(corners);
            if (result.resource != 0u) { result.mask = 0u; std::uint32_t selected = 0u; for (std::size_t light = 0; light < g_sfera_light_runtime.candidate_count && selected < 7u; ++light) if (sceneBoundsOverlap(bone.bounds().minimum, bone.bounds().maximum, g_sfera_light_runtime.render_candidates[light])) result.mask |= 1u << selected++; }
        }
    }
    for (std::size_t child = 0; child < bone.child_count; ++child) classifyBone(model.child_bones[bone.first_child + child]);
}
void SceneRenderer::collectLights() {
    auto& visible = g_sfera_light_runtime.visible_handles;
    visible.clear();
    const auto* frustum = &SphereRender::SceneRenderer::frustum; const auto& first = frustum->planes[0];
    if (first.normal.x == 0.0f && first.normal.y == 0.0f && first.normal.z == 0.0f && first.distance == 0.0f) return;
    const auto camera = g_sfera_world_objects.object(1u)->position;
    const auto& handles = g_sfera_light_runtime.handles;
    visible.reserve(handles.size());
    for (std::size_t index = 0; index < handles.size(); ++index) {
        auto* light = handles[index].get(); if (light == nullptr) continue; const SferaVec3F radius{light->radius, light->radius, light->radius}; light->bounds_min = light->position - radius; light->bounds_max = light->position + radius; const auto corners = SferaBoundsCornersRuntime::fromExtents(light->bounds_min, light->bounds_max);
        if (frustum->classifyPoints(corners.corners) == 0) continue;
        visible.push_back(light); const auto delta = camera - light->position; const float distance = delta.dot(delta); light->viewer_distance_squared = distance;
    }
    SferaAlgorithms::stableSort(visible, [](const auto* light) { return std::fabs(light->viewer_distance_squared); });
    if (visible.size() > 30u) visible.resize(30u); auto& device = sceneDevice(); D3DLIGHT9 light{}; light.Type = D3DLIGHT_POINT; light.Diffuse.a = 1.0f; light.Specular = {1.0f, 1.0f, 1.0f, 1.0f}; light.Ambient.a = 1.0f; light.Falloff = 1.0f; light.Attenuation2 = 1.0f;
    for (std::uint32_t index = 0; index < visible.size(); ++index) { const auto& source = *visible[index]; light.Diffuse.r = source.color[0] * 0.003921568859368563; light.Diffuse.g = source.color[1] * 0.003921568859368563; light.Diffuse.b = source.color[2] * 0.003921568859368563; light.Position = {source.position.x, source.position.y, source.position.z}; light.Range = source.radius; device.checkResult(device.native_device->SetLight(index + 1u, &light), "SetLight"); g_sfera_light_runtime.setActive(index + 1u, false, 14800u); }
}
}
namespace {
std::uint32_t skyChannel(float value) { return std::min(SferaNumeric::truncateInt(value), 255) & 255u; }

template<std::size_t Count> SferaVec4F skyPeriodicSample(const std::array<SkyState::GradientKey, Count>& keys, double position) {
    std::size_t first, second;
    float amount;
    if (position < keys[0].position) {
        first = Count - 1;
        second = 0;
        const float tail = 1.0 - keys[first].position;
        const double start = keys[0].position;
        amount = (position + tail) / (start + tail);
    } else if (position > keys[Count - 1].position) {
        first = Count - 1;
        second = 0;
        amount = (position - keys[first].position) / (1.0 + keys[0].position - keys[first].position);
    } else {
        second = 1;
        while (keys[second].position < position) ++second;
        first = second - 1;
        const double end = keys[second].position;
        amount = (position - keys[first].position) / (end - keys[first].position);
    }
    return SferaMath::interpolate(keys[first].color, keys[second].color, amount);
}
void skySubmit(std::uint32_t count) { auto& device = *g_sfera_graphics_runtime.d3d_runtime; device.checkResult(device.native_device->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0u, 120u, count / 3u, SceneSky::indices, D3DFMT_INDEX16, SceneSky::vertices, sizeof(SferaScreenVertex)), "DrawIndexedPrimitiveUP"); }
}
void SceneSky::rotateUv(double x, double y, double angle, float& u, float& v) {
    const auto [sine, cosine] = SferaMath::rotationTerms(angle);
    const auto centerX = screen_center_x, centerY = screen_center_y;
    const double horizontal = x - centerX, vertical = y - centerY;
    u = (centerX + horizontal * cosine - vertical * sine) * 0.00390625 + texture_phase_u;
    v = (horizontal * sine + vertical * cosine + centerY) * 0.00390625 + texture_phase_v;
}
std::size_t SceneSky::buildLayerGeometry(const SceneSkyLayer& layer, double opacity) {
    for (std::size_t index = 0; index < 120; ++index) {
        const double inclination = elevation_samples[index];
        const float alpha = inclination < 1.059999942779541f ? 255.0 : inclination > 1.4800000190734863f ? 0.0
            : 255.0 - (inclination - 1.059999942779541) / (1.4800000190734863 - 1.059999942779541) * 255.0;
        const float faded = alpha * opacity;
        const std::int64_t rounded_alpha = std::nearbyint(faded);
        layer_alpha[index] = rounded_alpha;
        const float sine = std::sin(inclination);
        const float projection = inclination * layer.projectionWarp;
        const double projected_angle = projection;
        const float cosine = std::cos(projected_angle);
        const double numerator = sine;
        const float rounded_radius = numerator / cosine * layer.uvScale;
        const double radius = rounded_radius;
        const auto [azimuth_sine, azimuth_cosine] = SferaMath::rotationTerms(azimuth_samples[index]);
        const float offsetX = layer.trackOffset ? cloud_offset_x : 0.0f;
        const float offsetY = layer.trackOffset ? cloud_offset_y : 0.0f;
        auto& vertex = vertices[index];
        vertex.u = azimuth_cosine * radius + offsetX + 0.5;
        vertex.v = azimuth_sine * radius + offsetY + 0.5;
    }
    std::size_t count = 0;
    for (std::uint16_t row = 0; row < 9; ++row) {
        for (std::uint16_t column = 0; column < 11; ++column) {
            const std::uint16_t index = row * 12 + column;
            if (sample_visible[index] || sample_visible[index + 1] || sample_visible[index + 12]) {
                indices[count++] = index;
                indices[count++] = index + 1;
                indices[count++] = index + 12;
            }
            if (sample_visible[index + 1] || sample_visible[index + 12] || sample_visible[index + 13]) {
                indices[count++] = index + 1;
                indices[count++] = index + 13;
                indices[count++] = index + 12;
            }
        }
    }
    return count;
}
void SceneSky::layerColor(const SceneSkyLayer& layer, SferaVec3F& output) { int first; int second; float amount; SceneSky::environment->interval(g_sfera_graphics_runtime.environment_factor, first, second, amount); output = {SferaMath::interpolate(layer.colors[first].x, layer.colors[second].x, amount), SferaMath::interpolate(layer.colors[first].y, layer.colors[second].y, amount), SferaMath::interpolate(layer.colors[first].z, layer.colors[second].z, amount)}; }
void SceneSky::drawColorLayer(std::string_view texture, const SferaVec3F& color, std::size_t indices) {
    if (texture.empty()) return;
    for (std::size_t index = 0; index < 120; ++index) {
        const float additional = glow_samples[index] * 255.0;
        const auto illuminated = color + SferaVec3F{additional, additional, additional};
        auto& vertex = vertices[index];
        vertex.diffuse = SferaColor::rgba(skyChannel(illuminated.x), skyChannel(illuminated.y), skyChannel(illuminated.z), layer_alpha[index]).argb();
        vertex.specular = 0u;
    }
    auto& device = *g_sfera_graphics_runtime.d3d_runtime; device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_ONE); if (texture != "auto") SphereRender::SceneRenderer::bindTexture(g_sfera_textures.find(texture)); skySubmit(indices); device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}
void SceneSky::drawMaskLayer(std::string_view texture, std::size_t indices) {
    if (texture.empty()) return;
    for (std::size_t index = 0; index < 120; ++index) { const auto color = SceneSky::layer_alpha[index] & 255u; SceneSky::vertices[index].diffuse = D3DCOLOR_XRGB(color, color, color); SceneSky::vertices[index].specular = D3DCOLOR_ARGB(0, 255u - color, 255u - color, 255u - color); }
    auto& device = *g_sfera_graphics_runtime.d3d_runtime; device.setAlphaBlending(D3DBLEND_ZERO, D3DBLEND_SRCCOLOR); device.checkResult(device.native_device->SetRenderState(D3DRS_SPECULARENABLE, TRUE), "SetRenderState"); SphereRender::SceneRenderer::bindTexture(g_sfera_textures.find(texture)); skySubmit(indices); device.checkResult(device.native_device->SetRenderState(D3DRS_SPECULARENABLE, FALSE), "SetRenderState"); device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}
void SceneSky::drawLayers(const SceneSkyLayers& layers) {
    if (layers.primary.texture.empty() && layers.secondary.texture.empty()) return;
    const auto& source = layers.primary.texture.empty() ? layers.secondary : layers.primary; const auto indices = buildLayerGeometry(source, layers.opacity); drawMaskLayer(layers.secondary.texture, indices); if (!layers.primary.texture.empty()) { SferaVec3F color; layerColor(layers.primary, color); drawColorLayer(layers.primary.texture, color, indices); }
}
void SceneSky::orbit(float& x, float& y, std::uint32_t orbit) {
    const int frequency = orbit + 1u;
    const float angle = animation_phase * 3.1415929794311523 * 2.0 * frequency;
    const auto [sine, cosine] = SferaMath::rotationTerms(angle);
    const float offsetX = cosine * 0.019999999552965164, offsetY = sine * 0.019999999552965164;
    const double originalX = x, originalY = y;
    x = originalX + offsetX;
    y = originalY + offsetY;
}
float SceneSky::horizonFog(float elevation, double amount) {
    const float position = elevation < 0.0f ? 0.0 : elevation > 0.4000000059604645 ? 1.0 : elevation / 0.4000000059604645;
    return position * amount;
}
void SceneSky::sampleDirection(bool refresh, const SferaVec3F& direction) {
    if (SphereRender::SceneRenderer::interior_scene == 1u) { sample_color = 0u; return; }
    const double x = direction.x, y = direction.y, z = direction.z;
    const float azimuth = std::atan2(z, x);
    const auto [sine, cosine] = SferaMath::rotationTerms(-azimuth);
    const float horizontal = cosine * x - sine * z;
    const float elevation_angle = std::atan2(y, horizontal);
    const float elevation = elevation_angle + 1.5707964897155762;
    sample_azimuth = azimuth;
    sample_elevation = elevation;
    const float latitude = elevation * 0.31830985316916194;
    const float longitude_angle = std::atan2(y, x);
    float longitude = longitude_angle - 1.5707964897155762;
    if (longitude < 0.0f) longitude += 6.283185958862305;
    longitude *= 0.15915492658458097;
    if (refresh) {
        const auto* source = SphereWorld::Vegetation::alternatePatterns() ? high_resolution_environment.get() : environment.get();
        source->sample(g_sfera_graphics_runtime.environment_factor, interpolated);
    }
    auto color = skyPeriodicSample(interpolated.primary, longitude);
    const float length = direction.length<double, float>();
    const float inverse = 1.0 / length;
    const float reference_projection = (-0.30000001192092896 * y - 0.9539999961853027 * std::fabs(z)) * inverse;
    const double reference_value = reference_projection;
    const float reference = reference_value * reference_value;
    color = SferaMath::interpolate(color, interpolated.reference, reference);
    float glow = direction.dot(SphereRender::SceneRenderer::sun_direction) * inverse;
    if (glow < 0.0f) glow = 0.0f;
    else for (int square = 0; square < 6; ++square) {
        const double value = glow;
        glow = value * value;
    }
    sun_glow = glow;
    const auto overlay = skyPeriodicSample(interpolated.secondary, latitude);
    const float amount = overlay.w / 255.0;
    const float fog = horizonFog(latitude, SphereRender::SceneRenderer::environment.fogParameters.x);
    // Alpha is composed separately; RGB follows the same two interpolation stages.
    auto rgb = SferaMath::interpolate(SferaVec3F{color.x, color.y, color.z}, {overlay.x, overlay.y, overlay.z}, amount);
    rgb = SferaMath::interpolate(rgb, SphereRender::SceneRenderer::environment.fogColor, fog);
    const double color_opacity = color.w;
    const float combined_opacity = overlay.w + color_opacity;
    const float opacity = combined_opacity + fog * 255.0;
    const auto rounded = [](float value) {
        const int channel = std::nearbyint(value);
        return std::min(channel, 255);
    };
    inverse_opacity = 255u - rounded(opacity);
    sample_color = SferaColor::rgba(rounded(rgb.x), rounded(rgb.y), rounded(rgb.z), 0u).argb();
}
namespace {

void skyWrap(float& value, double period) {
    while (value < 0.0f) value += period;
    while (value >= period) value -= period;
}
}
double SceneSky::drawStars() {
    const bool secondary = SphereRender::SceneRenderer::secondary_pass != 0u;
    const auto width = g_sfera_graphics_runtime.display_width;
    const auto height = g_sfera_graphics_runtime.display_height;
    const float roundedCellWidth = secondary ? 25.600000381469727 : width / 10.0;
    const float roundedCellHeight = secondary ? 32.0 : height * 0.125;
    const double cellWidth = roundedCellWidth, cellHeight = roundedCellHeight;
    screen_center_x = width * 0.5;
    screen_center_y = height * 0.5;
    const auto* corners = g_sfera_camera.frame_corners;
    const auto horizontal = corners[2] - corners[1], vertical = corners[4] - corners[1];
    if (!secondary) {
        const auto halfHorizontal = horizontal * 0.5f;
        const auto midpoint = corners[1] + (halfHorizontal + vertical * 0.5f);
        const auto center = corners[0] + (midpoint - corners[0]) * 0.10000000149011612f;
        const auto offset = center + halfHorizontal * 0.009999999776482582f;
        SferaVec3F centerScreen{}, offsetScreen{}, previousCenter{}, previousOffset{};
        g_sfera_camera.project(center, centerScreen);
        g_sfera_camera.project(offset, offsetScreen);
        const bool centerValid = g_sfera_camera.project(projected_center, previousCenter);
        const bool offsetValid = g_sfera_camera.project(projected_offset, previousOffset);
        projected_center = center;
        projected_offset = offset;
        if (centerValid && offsetValid) {
            auto rotation = g_sfera_camera.frame_transform;
            rotation.m[0][3] = rotation.m[1][3] = rotation.m[2][3] = 0.0f;
            const auto translation = rotation.inverseTransformPoint(corners[0] - previous_origin);
            previous_origin = corners[0];
            const auto distance = center - corners[0];
            const double radius = distance.length<double, float>();
            const float halfField = g_sfera_camera.field_of_view * 0.5;
            const double halfAngle = halfField;
            const float tangent = std::tan(halfAngle);
            const float roundedSpan = tangent * radius;
            const double span = roundedSpan;
            const float shiftX = translation.x / span * screen_center_x;
            const float shiftY = translation.y / span * screen_center_y * 1.3333300352096558;
            const double previousX = previousCenter.x, previousY = previousCenter.y;
            const double deltaX = previousX - centerScreen.x + shiftX;
            const double deltaY = previousY - centerScreen.y + shiftY;
            motion.primary.x += deltaX;
            motion.primary.y += deltaY;
            horizontal_motion += deltaX;
            vertical_motion += deltaY;
            const float width_pixels = width;
            motion.secondary.x += deltaX * 256.0 / width_pixels;
            motion.secondary.y -= deltaY * 256.0 / width_pixels;
            float uShift = deltaX * 0.00390625, vShift = deltaY * 0.00390625;
            SferaVec3F::rotatePair(uShift, vShift, motion.angle);
            const double uDelta = uShift, vDelta = vShift;
            texture_phase_u -= uDelta;
            texture_phase_v -= vDelta;
            const auto rotationDelta = previousOffset - previousCenter;
            const double rotationY = rotationDelta.y, rotationX = rotationDelta.x;
            const float roundedAngle = std::atan2(rotationY, rotationX);
            const double angle = roundedAngle;
            motion.angle -= angle;
            skyWrap(motion.primary.x, cellWidth);
            skyWrap(motion.primary.y, cellHeight);
            skyWrap(motion.secondary.x, 25.600000381469727f);
            skyWrap(motion.secondary.y, 32.0f);
            skyWrap(texture_phase_u, 1.0f);
            skyWrap(texture_phase_v, 1.0f);
            skyWrap(motion.angle, 6.283185958862305f);
            motion.primary.x -= cellWidth;
            motion.primary.y -= cellHeight;
            motion.secondary.x -= 25.600000381469727;
            motion.secondary.y -= 32.0;
        } else {
            texture_phase_u = std::rand() / 32767.0;
            texture_phase_v = std::rand() / 32767.0;
            motion.angle = std::rand() / 32767.0;
        }
    }
    const auto offset = secondary ? motion.secondary : motion.primary;
    const float gridX = offset.x / cellWidth, gridY = offset.y / cellHeight;
    for (int row = 0; row < 10; ++row) {
        for (int column = 0; column < 12; ++column) {
            const auto index = row * 12 + column;
            auto& vertex = vertices[index];
            vertex.x = cellWidth * column + offset.x;
            vertex.y = cellHeight * row + offset.y;
            vertex.z = 0.0f;
            vertex.rhw = 1.0f;
            rotateUv(vertex.x, vertex.y, motion.angle, vertex.u, vertex.v);
            const double columnValue = column, rowValue = row;
            const float columnPosition = columnValue + gridX, rowPosition = rowValue + gridY;
            const auto horizontalPart = (horizontal * columnPosition) * 0.10000000149011612f;
            SferaVec3F verticalPart;
            if (secondary) {
                const float factor = (rowValue + gridY) * 0.125 * 0.75 + 0.125;
                verticalPart = vertical * factor;
            } else verticalPart = (vertical * rowPosition) * 0.125f;
            sampleDirection(row == 0 && column == 0, corners[1] + (horizontalPart + verticalPart) - corners[0]);
            azimuth_samples[index] = sample_azimuth;
            elevation_samples[index] = sample_elevation;
            vertex.specular = sample_color;
            vertex.diffuse = D3DCOLOR_XRGB(inverse_opacity, inverse_opacity, inverse_opacity);
            glow_samples[index] = sun_glow;
            sample_visible[index] = sample_elevation < 1.5099999904632568f ? 1u : 0u;
        }
    }
    std::size_t count = 0;
    for (std::uint16_t row = 0; row < 9; ++row) {
        for (std::uint16_t column = 0; column < 11; ++column) {
            const std::uint16_t index = row * 12 + column;
            indices[count++] = index;
            indices[count++] = index + 1;
            indices[count++] = index + 12;
            indices[count++] = index + 1;
            indices[count++] = index + 13;
            indices[count++] = index + 12;
        }
    }
    SphereRender::SceneRenderer::bindTexture(g_sfera_textures.find(secondary ? "black" : "stars"));
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    device.checkResult(device.native_device->SetRenderState(D3DRS_SPECULARENABLE, TRUE), "SetRenderState");
    device.checkResult(device.native_device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1), "SetFVF");
    device.drawVertices(D3DPT_TRIANGLELIST, 14u, vertices, 120u, indices, 594u, sizeof(SferaScreenVertex));
    device.checkResult(device.native_device->SetRenderState(D3DRS_SPECULARENABLE, FALSE), "SetRenderState");
    return motion.angle;
}
void SceneSky::drawSunMoon(float rotation) {
    const auto time = g_sfera_graphics_runtime.environment_factor; const bool moon = !(time > 0.1899999976158142f && time < 0.8299999833106995f); const auto* corners = g_sfera_camera.frame_corners; const auto normal = (corners[1] - corners[2]).cross(corners[3] - corners[2]).normalized(1); SferaPlaneF plane{normal, 0.0f}; plane.distance = -normal.dot(corners[1]); SceneSky::flare_visible = 0u; SferaVec3F intersection{}; const auto direction = SphereRender::SceneRenderer::sun_direction;
    if (plane.intersectLine(corners[0], corners[0] + direction, intersection) != 1) return;
    intersection = corners[0] + (intersection - corners[0]) * 0.8999999761581421f; SferaVec3F projected{}; if (!g_sfera_camera.project(intersection, projected)) return; SceneSky::flare_world_position = intersection; SceneSky::flare_screen_position = projected;
    const double scale = (moon ? 64.0 : 150.0) / 640.0; const auto width = g_sfera_graphics_runtime.display_width; const auto height = g_sfera_graphics_runtime.display_height; const float size = scale * (SphereRender::SceneRenderer::secondary_pass != 0u ? 256.0 : width); const float half = size * 0.5; auto& vertices = SceneSky::sun_quad;
    for (std::size_t index = 0; index < 4; ++index) { auto& vertex = vertices[index]; vertex.x = index == 0u || index == 3u ? -half : half; vertex.y = index < 2u ? -half : half; vertex.u = index == 1u || index == 2u ? 1.0f : 0.0f; vertex.v = index >= 2u ? 1.0f : 0.0f; }
    float minimumX = vertices[0].x; float maximumX = vertices[0].x; float minimumY = vertices[0].y; float maximumY = vertices[0].y; const double projectedX = projected.x, projectedY = projected.y;
    for (std::uint32_t index = 0; index < 4u; ++index) {
        auto& vertex = vertices[index]; SferaVec3F::rotatePair(vertex.x, vertex.y, -rotation); vertex.x += projectedX; vertex.y += projectedY; minimumX = std::min(minimumX, vertex.x); maximumX = std::max(maximumX, vertex.x); minimumY = std::min(minimumY, vertex.y); maximumY = std::max(maximumY, vertex.y); if (!moon) orbit(vertex.u, vertex.v, index);
        const float inverseWidth = 1.0 / width; const float inverseHeight = 1.0 / height; const auto horizontal = ((corners[2] - corners[1]) * vertex.x) * inverseWidth; const auto vertical = ((corners[4] - corners[1]) * vertex.y) * inverseHeight; sampleDirection(false, corners[1] + (horizontal + vertical) - corners[0]); const double directionX = direction.x; const float angle = std::atan2(directionX, direction.y); const float absolute = std::fabs(angle); const float elevation = 1.0 - absolute / 3.1415929794311523; const float fog = horizonFog(elevation, SphereRender::SceneRenderer::environment.fogParameters.x) * 255.0; vertex.specular = 0u; vertex.diffuse = SferaColor::rgba(255u, 255u, 255u, UINT32_MAX - SferaNumeric::truncatedWord(fog)).argb(); vertex.z = 0.0f; vertex.rhw = 1.0f;
    }
    if (!(width > minimumX && maximumX > 0.0f && height > minimumY && maximumY > 0.0f)) return;
    auto& device = *g_sfera_graphics_runtime.d3d_runtime; device.setAlphaBlending(D3DBLEND_SRCALPHA, moon ? D3DBLEND_INVSRCALPHA : D3DBLEND_ONE); SphereRender::SceneRenderer::bindTexture(g_sfera_textures.find(moon ? "moon" : "sun")); if (!moon) SceneSky::flare_visible = 1u; device.checkResult(device.native_device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1), "SetFVF"); device.drawVertices(D3DPT_TRIANGLEFAN, 14u, vertices, 4u, nullptr, 0u, sizeof(SferaScreenVertex)); device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}
namespace SphereRender {
SferaVec3F& SceneRenderer::observerPosition(SferaVec3F& output) {
    const auto* camera = g_sfera_world_objects.object(1u);
    if (camera == nullptr) {
        WorldDiagnostics::fail(std::format("Scene observer: camera object 1 is missing (controlled={}, mode={})",
            g_sfera_world_objects.controlled_object_handle, g_sfera_camera.controlled_observer_mode));
    }
    const auto* controlled = g_sfera_camera.controlled_observer_mode != 0u ? g_sfera_world_objects.controlledObject() : nullptr;
    output = (controlled != nullptr ? controlled : camera)->position;
    return output;
}
void SceneRenderer::setupEnvironment(std::uint32_t mode, bool useDefault, float time) {
    environment = {};
    sun_direction = {};
    g_sfera_terrain_renderer.patch_origin.x = 0.0f;
    SferaVec3F position{};
    observerPosition(position);
    interior_scene = !useDefault && position.y > 1000.0f;
    float fieldOfView;
    if (mode == 2u) fieldOfView = 0.03490658950558778f;
    else {
        if (g_sfera_graphics_runtime.display_width <= 0 || g_sfera_graphics_runtime.display_height <= 0)
            WorldDiagnostics::fail("Invalid display size for camera projection");
        fieldOfView = scene_field_of_view(
            g_sfera_graphics_runtime.display_width,
            g_sfera_graphics_runtime.display_height);
    }
    const float nearPlane = mode == 2u ? 997.0f : 0.10000000149011612f;
    float farPlane;
    if (interior_scene) {
        farPlane = mode == 2u ? 1005.0f : 80.0f;
        environment.fogParameters.y = farPlane - 20.0;
        environment.fogParameters.z = farPlane;
        environment.sunColor = {59.0f, 37.0f, 12.0f};
        environment.ambientColor = {19.0f, 47.0f, 71.0f};
        const float length = std::sqrt(14.0);
        sun_direction.x = 1.0 / length;
        sun_direction.y = -3.0 / length;
        sun_direction.z = 2.0 / length;
    } else {
        const float halfAngle = fieldOfView * 0.5;
        const double radians = halfAngle;
        const float cosine = std::cos(radians);
        const double directionScale = cosine;
        farPlane = directionScale * view_distance;
        const bool alternate = SphereWorld::Vegetation::alternatePatterns();
        const auto* sky = (alternate && SceneSky::high_resolution_environment) ? SceneSky::high_resolution_environment.get() : SceneSky::environment.get();
        auto* zones = (alternate && alternate_environment_zones) ? alternate_environment_zones.get() : environment_zones.get();
        if (sky == nullptr || zones == nullptr) WorldDiagnostics::fail("Environment assets are not loaded");
        sky->sunDirection(time, sun_direction);
        zones->calculate(useDefault, position.x, position.z, time, *sky, environment);
    }
    if (environment.fogParameters.z > farPlane) {
        environment.fogParameters.z = farPlane;
        if (environment.fogParameters.y + 20.0 > environment.fogParameters.z) {
            const float nearFog = environment.fogParameters.z - 20.0;
            environment.fogParameters.y = std::max(0.0f, nearFog);
        }
    }
    g_sfera_camera.setPerspective(nearPlane, farPlane, fieldOfView);
}
namespace {
std::size_t sceneAnimationFrame(Model& model, int animation, int frame) { if (animation < 0 || animation >= model.animation_lengths.size()) { animation = 0; frame = 0; } std::size_t absolute = 0u; for (int index = 0; index < animation; ++index) absolute += model.animation_lengths[index]; if (frame < 0 || frame >= model.animation_lengths[animation]) frame = 0; return absolute + frame; }
}
void SceneRenderer::drawObjects(bool updateVegetation) {
    if (g_sfera_shadows && SphereRender::SceneRenderer::interior_scene == 0u) { const auto sun = SphereRender::SceneRenderer::sun_direction; auto& fade = g_sfera_graphics_runtime.view_scale; fade = 0.0f; if (sun.y < 0.4000000059604645f) { const float offset = sun.y - 0.4000000059604645; fade = std::fabs(offset) / 1.399999976158142; } const float half = fade * 0.5; fade = 1.0 - half; g_sfera_shadows->setDirection(sun, fade); }
    const SferaRestore grassMode(g_sfera_graphics_runtime.grass_depth);
    const auto* controlled = g_sfera_world_objects.controlledObject();
    if (controlled == nullptr || controlled->position.y > 1000.0f) g_sfera_graphics_runtime.grass_depth = 0u;
    auto* vegetation = g_sfera_vegetation.animation.get(); if (updateVegetation) g_sfera_vegetation.updateCells();
    const auto center = g_sfera_world_objects.object(1u)->position; g_sfera_world_spatial.gatherObjects(center, SphereRender::SceneRenderer::view_distance); const auto& candidates = g_sfera_world_spatial.objects();
    const auto count = candidates.size();
    auto& positions = SphereRender::SceneRenderer::object_order;
    positions.resize(count);
    auto* entries = positions.data();
    for (std::uint32_t index = 0u; index < count; ++index) { const auto handle = candidates[index]; const auto& object = *g_sfera_world_objects.object(handle); const auto delta = object.position - center; entries[index] = {handle, object.ownsModel() ? g_sfera_models.count() + handle : std::get<WorldObject::ModelReference>(object.model_source).id, delta.length<double, float>()}; }
    SferaAlgorithms::stableSort(std::span{object_order}.first(count), [](const auto& entry) { return entry.key; }); sceneDevice().model_vertices.discard();
    if (SphereRender::SceneRenderer::secondary_pass == 0u || g_sfera_graphics_runtime.reflection_quality > 1u) for (std::uint32_t index = 0u; index < count; ++index) {
        const auto handle = entries[index].object; if (handle == 1u) continue; auto& object = *g_sfera_world_objects.object(handle); if (object.extended() && !object.extended()->render_enabled) continue; const auto* model = g_sfera_world_objects.model(object); if (model->animation_lengths.size() != 0u) continue;
        if (object.ownsModel()) { const SferaRestore height(object.position.y); raiseDistantObject(handle); if (updateVegetation) drawModel(handle); } else drawModel(handle);
    }
    if (updateVegetation && g_sfera_graphics_runtime.grass_depth == 2u) vegetation->update();
    if (SphereRender::SceneRenderer::secondary_pass == 0u || g_sfera_graphics_runtime.reflection_quality > 2u) for (std::uint32_t index = 0u; index < count; ++index) {
        const auto handle = entries[index].object; if (handle == 1u) continue; auto* base = g_sfera_world_objects.object(handle); if (!base->extended()) continue; auto& object = *CharacterModels::checkedExtended(base); auto& model = *g_sfera_world_objects.model(object); if (model.animation_lengths.size() == 0u || !object.render_enabled) continue;
        if (object.render_cache_handle >= 0) { SphereRender::ModelPose::primary_frame = sceneAnimationFrame(model, object.animation, object.frame); SphereRender::ModelPose::secondary_enabled = false; if (object.interpolation > 0.009999999776482582f) { SphereRender::ModelPose::secondary_enabled = true; SphereRender::ModelPose::blend = object.interpolation; SphereRender::ModelPose::secondary_frame = sceneAnimationFrame(model, object.animation_secondary, object.frame_secondary); } }
        if (object.render_cache_handle >= 0) drawObject(handle); else { const auto shade = terrainShade(model.landscape_shadow_alpha, object.position.x, object.position.z); SphereRender::SceneRenderer::characters->draw(handle, SferaColor::rgba(shade, shade, shade, 0).argb()); }
    }
}
namespace {
std::uint32_t sceneColor(const SferaVec3F& color) { return SferaColor::rgba(SferaNumeric::truncatedWord(color.x), SferaNumeric::truncatedWord(color.y), SferaNumeric::truncatedWord(color.z), 0u).argb(); }
void sceneUnderwaterOverlay() {
    const auto handle = g_sfera_world_objects.controlled_object_handle; std::uint32_t materialIndex = 0u; if (handle == UINT32_MAX || g_sfera_motion.surfaceInteraction(handle, &materialIndex) != 5u) return; const auto width = g_sfera_graphics_runtime.display_width; const auto height = g_sfera_graphics_runtime.display_height; constexpr double textureScale = 0.20000000298023224; auto& x = SceneSky::horizontal_motion; auto& y = SceneSky::vertical_motion;
    if (x < 0.0f) x = x + width / textureScale; if (x > width / textureScale) x = x - width / textureScale; if (y < 0.0f) y = y + height / textureScale; if (y > height / textureScale) y = y - height / textureScale; const float width_pixels = width, height_pixels = height; const double offset_x = x, offset_y = y; const float u = -offset_x / width_pixels * textureScale; const float v = -offset_y / height_pixels * textureScale; const float right = u + textureScale; const float bottom = v + textureScale; const float uv[] = {u, v, right, v, right, bottom, u, bottom}; const auto& material = g_sfera_graphics_runtime.water_materials.at(materialIndex);
    std::string texture = "ww1_00"; const auto animation = SphereRender::SceneRenderer::texture_animation_frame / 2; texture[2] = material.primary_animation + '0'; texture[4] = animation / 10 + '0'; texture[5] = animation % 10 + '0'; const auto heightFactor = std::fabs(SphereRender::SceneRenderer::sun_direction.y); const auto sun = SphereRender::SceneRenderer::environment.sunColor; const auto ambient = SphereRender::SceneRenderer::environment.ambientColor; const auto channel = [heightFactor](double light, float base) { const int value = heightFactor * light + base; return std::min(255, value); };
    GameInterface::tintTexture(0, 0, width, height, texture, channel(sun.x, ambient.x), channel(sun.y, ambient.y), channel(sun.z, ambient.z), SferaNumeric::word(SferaNumeric::truncateInt(material.primary_opacity * 255.0)), uv);
}
}
void SceneRenderer::drawPass(std::uint32_t mode) {
    auto& device = sceneDevice(); const auto width = mode == 1u || mode == 2u ? 256u : g_sfera_graphics_runtime.display_width; const auto height = mode == 1u || mode == 2u ? 256u : g_sfera_graphics_runtime.display_height; GameCamera::setupViewport(0u, 0u, width, height); device.checkResult(device.native_device->Clear(0u, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0u), "Clear");
    const float fogStart = mode == 2u ? g_sfera_camera.far_distance - 1.0f : SphereRender::SceneRenderer::environment.fogParameters.y; const float fogEnd = mode == 2u ? g_sfera_camera.far_distance : SphereRender::SceneRenderer::environment.fogParameters.z; sceneRenderState(D3DRS_FOGSTART, SferaBinary::floatBits(fogStart)); sceneRenderState(D3DRS_FOGEND, SferaBinary::floatBits(fogEnd)); setAmbientColor(); if (mode == 0u) { SferaNatureManager::updateRain(); SferaNatureManager::updateLightning(); } sceneRenderState(D3DRS_FOGENABLE, FALSE);
    if ((SphereRender::SceneRenderer::interior_scene == 0u && SferaClientApplication::resources_loaded) || mode == 1u) { const float rotation = SceneSky::drawStars(); SceneSky::drawSunMoon(rotation); if (SphereWorld::Vegetation::alternatePatterns()) SceneSky::drawLayers(g_sfera_weather_runtime.current.clouds); SceneSky::drawLayers(g_sfera_weather_runtime.current.sky); } else GameInterface::drawTexture(0, 0, g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height, "black", 255u, 0.0f, nullptr);
    device.checkResult(device.native_device->Clear(0u, nullptr, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0u), "Clear"); sceneRenderState(D3DRS_FOGENABLE, TRUE); g_sfera_terrain_renderer.drawLandscape(); sceneRenderState(D3DRS_FOGCOLOR, sceneColor(SphereRender::SceneRenderer::environment.fogColor)); drawObjects(mode != 1u); if (mode != 0u) return;
    setAmbientColor(); g_sfera_light_runtime.setDirectionalLight(SphereRender::SceneRenderer::sun_direction * -1.0f, SphereRender::SceneRenderer::environment.sunColor); g_sfera_terrain_renderer.drawWater(); if (g_sfera_effect_manager.blood != nullptr) g_sfera_effect_manager.blood->render(); sceneRenderState(D3DRS_FOGENABLE, FALSE); g_sfera_server_wall.generateEffects(); g_sfera_effect_manager.renderParticles(); g_sfera_effect_manager.drawFlare(SferaNumeric::truncateInt(SceneSky::flare_screen_position.x), SferaNumeric::truncateInt(SceneSky::flare_screen_position.y), 220, SceneSky::flare_visible != 0u); sceneUnderwaterOverlay();
}
}
namespace SphereRender {
void SceneRenderer::drawMinimap() {
    setupEnvironment(2u, SphereRender::SceneRenderer::use_default_environment, g_sfera_graphics_runtime.environment_factor);
    auto& device = sceneDevice();
    SceneScope scene(device);
    if (!scene) return;
    {
        RenderStateScope state(device);
        RenderTargetScope target(device, *device.minimapTexture().native_texture.Get());
        GameCamera::Frame camera(2u, false, 0.0f);
        drawPass(2u);
    }
    scene.finish();
}
void SceneRenderer::drawReflection() {
    if (SphereRender::SceneRenderer::interior_scene != 0u) return;
    SphereRender::SceneRenderer::reflection_height = 100000.0f;
    SphereRender::SceneRenderer::reflection_distance = 1000000.0f;
    g_sfera_terrain_renderer.gatherReflectiveWater();
    const float waterHeight = SphereRender::SceneRenderer::reflection_height;
    if (waterHeight > 99999.0f) return;
    auto& device = sceneDevice();
    SceneScope scene(device);
    if (!scene || !device.reflection_target || !device.reflection_target->native_texture) return;
    {
        RenderStateScope state(device);
        struct PassRestore {
            std::uint32_t previous;
            ~PassRestore() { SphereRender::SceneRenderer::secondary_pass = previous; }
        } pass{std::exchange(SphereRender::SceneRenderer::secondary_pass, 1u)};
        const float plane[] = {0.0f, -1.0f, 0.0f, waterHeight};
        device.checkResult(device.native_device->SetClipPlane(0u, plane), "SetClipPlane");
        sceneRenderState(D3DRS_CLIPPLANEENABLE, 1u);
        RenderTargetScope target(device, *device.reflection_target->native_texture.Get());
        GameCamera::Frame camera(1u, true, waterHeight);
        drawPass(1u);
    }
    scene.finish();
}
void SceneRenderer::drawFrame() {
    if (!SferaClientApplication::application_active) { if (!SferaClientApplication::windowed) return; ::Sleep(100u); }
    const auto timestamp = WorldClock::nowTicks();
    auto& previous = g_sfera_vegetation.last_frame_ticks;
    SferaClientApplication::frame_elapsed_ticks = SferaNumeric::lowWord(timestamp) - SferaNumeric::lowWord(previous);
    previous = timestamp;
    SphereRender::SceneRenderer::view_distance = g_sfera_graphics_runtime.auto_fog ? g_sfera_graphics_runtime.saved_fog_distance : g_sfera_graphics_runtime.fog_distance;
    if (SphereRender::SceneRenderer::interior_scene != 0u) drawMinimap();
    setupEnvironment(0u, SphereRender::SceneRenderer::use_default_environment, g_sfera_graphics_runtime.environment_factor);
    if (g_sfera_graphics_runtime.reflection_quality > 0u) drawReflection();
    auto& device = sceneDevice();
    SceneScope scene(device);
    if (scene) {
        const bool postEffects = device.supports_post_effects && g_sfera_graphics_runtime.post_effects_enabled;
        if (postEffects) { device.post_effects->setEnabled(true); device.post_effects->beginCapture(); }
        {
            GameCamera::Frame camera(0u, false, 0.0f);
            drawPass(0u);
            GameInterface::setRenderState();
            sceneRenderState(D3DRS_ZENABLE, TRUE); sceneRenderState(D3DRS_ZWRITEENABLE, TRUE);
            GameInterface::drawAll();
            sceneRenderState(D3DRS_ZENABLE, FALSE); sceneRenderState(D3DRS_ZWRITEENABLE, FALSE);
            if (postEffects) device.post_effects->compose();
            GameInterface::drawFullscreenOverlay(); GameInterface::drawFrame();
        }
        scene.finish();
        device.waitForGpu();
        device.present();
    }
    if (SphereRender::SceneRenderer::characters) SphereRender::SceneRenderer::characters->updateLodDistance();
}
}
namespace SphereRender {
namespace {
void sceneWorldTransform(const SferaMatrix4x4F& world) { const auto transform = world.transposed(); sceneDevice().setTransform(D3DTS_WORLD, transform); }
std::uint32_t sceneClassifyModel(const Model& model, const SferaMatrix4x4F& world) { std::array<SferaVec3F, 8> corners; for (std::size_t index = 0u; index < corners.size(); ++index) corners[index] = world.transformPoint(model.collision_corners.corners[index]); return SphereRender::SceneRenderer::frustum.classifyPoints(corners); }

float sceneUpdateFade(WorldObject& object, bool animated) { if (object.render_fade == -1.0f) object.render_fade = 1.0f; else { const double speed = animated && object.render_fade < 0.009999999776482582 ? 7.999999797903001e-05 : 0.0007999999797903001; const float amount = SferaNumeric::signedWord(SferaClientApplication::frame_elapsed_ticks) * speed; object.render_fade = amount < 1.0f ? SferaMath::interpolate(object.render_fade, 1.0, amount) : 1.0f; } return object.render_fade; }
void sceneScaleSun(float amount) {
    auto& sun = SphereRender::SceneRenderer::environment.sunColor;
    sun = sun * amount;
}
void sceneDirectionalLight() { g_sfera_light_runtime.setDirectionalLight(SphereRender::SceneRenderer::sun_direction * -1.0f, SphereRender::SceneRenderer::environment.sunColor); }
void sceneDisableLights(std::uint32_t sourceLine) { for (std::size_t index = 0u; index < g_sfera_light_runtime.candidate_count; ++index) if (g_sfera_light_runtime.render_candidate_active[index]) g_sfera_light_runtime.setActive(g_sfera_light_runtime.render_candidate_indices[index], false, sourceLine); }
void sceneSelectLights(std::uint32_t mask) { for (std::size_t index = 0; index < g_sfera_light_runtime.candidate_count; ++index) { const bool enabled = (mask & (std::uint32_t{1} << index)) != 0; auto& active = g_sfera_light_runtime.render_candidate_active[index]; if (active == enabled) continue; g_sfera_light_runtime.setActive(g_sfera_light_runtime.render_candidate_indices[index], enabled, __LINE__); active = enabled; } }
void sceneMaterialAmbient(const Material& material) { const auto& ambient = SphereRender::SceneRenderer::environment.ambientColor; const auto channel = [](double material, float ambient) { const int value = material + ambient; return std::min(255, value) & 255u; }; sceneRenderState(D3DRS_AMBIENT, SferaColor::rgba(channel(material.color[0], ambient.x), channel(material.color[1], ambient.y), channel(material.color[2], ambient.z)).argb()); }
DynamicStream<SphereRender::PositionNormalUvVertex>::Mapping sceneModelVertices(const Model& model, const Submesh& part, const SferaVec3F* pulledCamera, bool vegetation) {
    auto vertices = sceneDevice().model_vertices.lock(part.vertex_count);
    for (std::size_t index = 0u; index < part.vertex_count; ++index) { const auto absolute = part.first_vertex + index; const auto& source = model.vertices[absolute]; auto& vertex = vertices[index]; vertex = {source.position, source.normal, source.u, source.v}; if (vegetation && !model.cached_vegetation_vertices.empty()) { const auto& cached = model.cached_vegetation_vertices[absolute]; vertex.position = cached.position; if (model.vegetation_kind == VegetationKind::Grass) vertex.normal = cached.normal; } else if (pulledCamera) vertex.position = vertex.position + (*pulledCamera - vertex.position) * 0.009999999776482582f; }
    vertices.unlock();
    return vertices;
}
void sceneDrawSubmesh(const Model& model, const Submesh& part,
    const DynamicStream<SphereRender::PositionNormalUvVertex>::Mapping& vertices,
    DynamicStream<std::uint16_t>& indices, std::uint32_t flags) {
    if (part.face_count > 1000u) WorldDiagnostics::fail("MNO_INDICES_IN_PRIMITIVE exceed");
    const auto count = part.face_count * 3u;
    auto output = indices.lock(count);
    for (std::size_t face = 0; face < part.face_count; ++face) {
        const auto& source = model.faces[part.first_face + face].vertices;
        std::copy(std::begin(source), std::end(source), output.data() + face * 3u);
    }
    output.unlock();
    sceneDevice().drawBuffer(vertices.buffer(), D3DPT_TRIANGLELIST, flags, vertices.first(),
        part.vertex_count, output.buffer(), count, output.first(), sizeof(SphereRender::PositionNormalUvVertex));
}
}
void SceneRenderer::drawModel(std::uint32_t handle) {
    if (SceneSky::flare_visible != 0u) SceneSky::flare_visible = SphereWorld::ContactQuery::lineOfSight(handle); auto& object = *g_sfera_world_objects.object(handle); auto& model = *g_sfera_world_objects.model(object); SphereRender::ModelPose::active_model = &model; if (object.extended() && !object.extended()->render_enabled) return; const bool linked = object.extended() && object.extended()->parent_object_handle != 0u;
    SphereRender::ModelPose::current_frame = linked ? SphereRender::ModelPose::attachment_transforms.at(object.extended()->parent_link_slot) : SferaMatrix4x4F::fromEuler(object.position, object.rotation); SphereRender::SceneRenderer::model_visibility = sceneClassifyModel(model, SphereRender::ModelPose::current_frame); if (SphereRender::SceneRenderer::model_visibility == 0u) return; const auto camera = SphereRender::ModelPose::current_frame.inverseTransformPoint(g_sfera_world_objects.object(1u)->position); SferaRestore sunColor(SphereRender::SceneRenderer::environment.sunColor);
    if (!linked) { sceneScaleSun(sceneUpdateFade(object, false)); sceneDirectionalLight(); activateObjectLights(handle); for (std::size_t index = 0u; index < g_sfera_light_runtime.candidate_count; ++index) { auto& light = g_sfera_light_runtime.render_candidates[index]; light.position = SphereRender::ModelPose::current_frame.inverseTransformPoint(light.position); const SferaVec3F radius{light.radius, light.radius, light.radius}; light.bounds_min = light.position - radius; light.bounds_max = light.position + radius; } }
    classifyBone(model.root_bone); sceneWorldTransform(SphereRender::ModelPose::current_frame); const auto distance = ((object.position) - (g_sfera_camera.frame_corners[0])).length<double, float>(); float fade = 0.0f, remaining = 0.0f; modelFade(model.relativeLod(distance), model.lod_power, fade, remaining); if (object.lighting_color == 0u) { const auto tint = SferaColor::fromArgb(Material::randomColor(model.color_variation)); object.lighting_color = tint.withAlpha(tint.alpha() | terrainShade(model.landscape_shadow_alpha, object.position.x, object.position.z)).argb(); } std::uint32_t lastTexture = 0u;
    for (std::size_t index = 0u; index < model.submeshes.size(); ++index) {
        const auto& part = model.submeshes[index]; const auto& visible = SphereRender::SceneRenderer::bone_visibility[part.bone_index]; if (visible.resource == 0u) continue; const float opacity = part.inverted_fade ? remaining : fade; const bool fading = opacity > 9.99999993922529e-09 && 1.0 - opacity > 9.99999993922529e-09; if (opacity < 9.99999993922529e-09) continue;
        if (SphereRender::SceneRenderer::shadow_projection_opacity != 0u) g_sfera_shadows->projectModel(model, index, &SphereRender::ModelPose::current_frame); const auto& bone = model.bones[part.bone_index]; const bool pulled = bone.name.starts_with("_z"); const bool alphaTest = (bone.name.starts_with("_s") || bone.name.starts_with("_u") || bone.name.starts_with("_c")); const auto* material = part.material; if (!material) throw std::out_of_range("Model material index"); sceneMaterialAmbient(*material);
        const auto lighting = SferaColor::fromArgb(object.lighting_color); const auto shade = lighting.alpha(); if (material->hasColorVariation || object.ownsModel()) { const auto shaded = lighting.scaledRgb(shade, 256u); setMaterialColor(shaded.red(), shaded.green(), shaded.blue()); } else setMaterialColor(shade, shade, shade); sceneSelectLights(visible.mask); const std::uint32_t texture = material->textures.at(0u); if (texture != lastTexture) { bindTexture(texture); lastTexture = texture; }
        auto vertices = sceneModelVertices(model, part, pulled ? &camera : nullptr, true); std::uint32_t flags = CD3D9Device::lighting | (SphereRender::SceneRenderer::secondary_pass == 0u && visible.resource == 2u ? 1u : 0u) | (alphaTest ? 4u : 0u); if (fading) sceneRenderState(D3DRS_ALPHAREF, SferaNumeric::truncatedWord((1.0 - opacity) * 127.0) + 128u); else if (alphaTest) sceneRenderState(D3DRS_ALPHAREF, 128u); sceneDrawSubmesh(model, part, vertices, sceneDevice().indices_primary, flags); if (fading || alphaTest) sceneRenderState(D3DRS_ALPHAREF, 1u);
    }
    setMaterialColor(255, 255, 255); if (!linked) { sunColor.restore(); sceneDisableLights(__LINE__); }
}
}
namespace SphereRender {
void SceneRenderer::drawObject(std::uint32_t handle) {
    const ShadowMap::Pass shadowPass(*g_sfera_shadows);
    const SferaRestore projectionOpacity(shadow_projection_opacity);
    if (SceneSky::flare_visible != 0u && handle != g_sfera_world_objects.controlled_object_handle) SceneSky::flare_visible = SphereWorld::ContactQuery::lineOfSight(handle); auto& object = *CharacterModels::checkedExtended(g_sfera_world_objects.object(handle)); auto& model = *g_sfera_world_objects.model(object); SphereRender::ModelPose::active_model = &model; if (!object.render_enabled) return;
    SphereRender::ModelPose::current_frame = SferaMatrix4x4F::fromEuler(object.position, object.rotation); SphereRender::SceneRenderer::model_visibility = sceneClassifyModel(model, SphereRender::ModelPose::current_frame); if (SphereRender::SceneRenderer::model_visibility == 0u) return; const auto distance = ((object.position) - (g_sfera_camera.frame_corners[0])).length<double, float>(); SphereRender::ModelPose::inverted_fade_pass = model.relativeLod(distance) < 0.20000000298023224;
    SferaRestore sunColor(SphereRender::SceneRenderer::environment.sunColor); SferaRestore sunDirection(SphereRender::SceneRenderer::sun_direction); const float fade = sceneUpdateFade(object, true); sceneScaleSun(fade); if (fade < 0.009999999776482582) { auto& direction = SphereRender::SceneRenderer::sun_direction; direction.x = 1.0f; direction.y = 0.0f; direction.z = 0.0f; const float fallback_angle = object.rotation.x + 1.1693706972350526; SferaVec3F::rotatePair(direction.x, direction.z, fallback_angle); const float fallback = 45.0 - fade * 4500.0; auto& color = SphereRender::SceneRenderer::environment.sunColor; color.x = fallback; color.y = fallback; color.z = fallback; }
    sceneDirectionalLight(); activateObjectLights(handle); const bool shadow = handle != g_sfera_world_objects.controlled_object_handle && g_sfera_shadows->quality < 4u && object.scale == 1.0f; if (shadow) g_sfera_shadows->selectObjectLight(object); ModelPose::updateBone(SphereRender::ModelPose::current_frame, model.root_bone); object.effect_frame_position_a = SphereRender::ModelPose::translation; object.effect_frame_position_b = SphereRender::ModelPose::attachment_101_position;
    float extension = 0.0f; const float originalShadowScale = model.shadow_scale;
    const SferaRestore shadowScale(model.shadow_scale);
    if (shadow) { const auto shadowDistance = ((g_sfera_world_objects.object(1u)->position) - (object.position)).length<double, float>(); const bool distant = shadowDistance > 15.0f; const float offset = shadowDistance - 15.0; const float fade_opacity = 1.0 - offset / 30.0; const float opacity = distant ? std::max(0.0f, fade_opacity) : 1.0f; SphereWorld::ContactQuery::updateBounds(handle); extension = g_sfera_shadows->projectionExtension(object); const double original_scale = originalShadowScale; model.shadow_scale = 1.4900000095367432 / (original_scale + extension); g_sfera_shadows->prepareModel(object, nullptr, opacity, distant ? 1u : 0u); }
    auto& device = sceneDevice(); if (object.scale != 1.0f) { device.setWhiteMaterial(object.scale); device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA); } setObjectMaterial(object, model.landscape_shadow_alpha, model.color_variation); std::uint32_t lastTexture = 0u;
    for (std::size_t index = 0u; index < model.submeshes.size(); ++index) {
        const auto& part = model.submeshes[index]; const auto bone = part.bone_index; if (part.inverted_fade != (SphereRender::ModelPose::inverted_fade_pass)) continue; const auto slot = model.bones[bone].animation().attachment_slot; if (handle == g_sfera_world_objects.controlled_object_handle && (slot == 102u || slot == 103u)) continue;
        sceneWorldTransform(SphereRender::ModelPose::bone_transforms.at(bone)); g_sfera_shadows->projectModel(model, index); const auto* material = part.material; if (!material) throw std::out_of_range("Model material index"); sceneMaterialAmbient(*material); const std::uint32_t texture = material->textures.at(object.render_cache_handle); if (texture != lastTexture) { bindTexture(texture); lastTexture = texture; } auto vertices = sceneModelVertices(model, part, nullptr, false); const auto flags = CD3D9Device::lighting | (SphereRender::SceneRenderer::secondary_pass == 0u && SphereRender::SceneRenderer::model_visibility == 2u ? 1u : 0u); sceneDrawSubmesh(model, part, vertices, device.indices_secondary, flags);
    }
    setMaterialColor(255, 255, 255); if (object.scale != 1.0f) { D3DMATERIAL9 reset{}; reset.Diffuse = {1.0f, 1.0f, 1.0f, 1.0f}; reset.Ambient = {1.0f, 1.0f, 1.0f, 0.0f}; device.checkResult(device.native_device->SetMaterial(&reset), "SetMaterial"); device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE); }
    setOpacity(1u); for (const auto linked : object.linked_objects) if (linked != 0u) drawModel(linked); sunColor.restore(); sunDirection.restore(); setOpacity(0u); if (shadow) { ShadowMap::drawObject(object, originalShadowScale, extension); } sceneDisableLights(__LINE__);
}
}

namespace EffectRendering {
    int ambientBrightness() {
        const auto& light = SphereRender::SceneRenderer::environment.ambientColor;
        return light.y * 0.44999998807907104 + light.x * 0.3100000023841858 + light.z * 0.23999999463558197;
    }
    void renderState(CD3D9Device& device, D3DRENDERSTATETYPE state, DWORD value) { device.checkResult(device.native_device->SetRenderState(state, value), "SetRenderState"); }
    void samplerState(CD3D9Device& device, D3DSAMPLERSTATETYPE state, DWORD value) { device.checkResult(device.native_device->SetSamplerState(0u, state, value), "SetSamplerState"); }
    void identityWorld(CD3D9Device& device) { const auto identity = SferaMatrix4x4F::identity(); device.setTransform(D3DTS_WORLD, identity); }
    int visibilityAlpha(const SferaVec3F& position) {
        const auto& matrix = g_sfera_camera.frame_transform;
        const SferaVec3F origin{matrix.m[0][3], matrix.m[1][3], matrix.m[2][3]};
        const SferaVec3F direction{matrix.m[0][2], matrix.m[1][2], matrix.m[2][2]};
        const float distance = (position - origin).dot(direction);
        const auto& limits = SphereRender::SceneRenderer::environment.fogParameters;
        if (distance < limits.y) return 255;
        if (distance > limits.z) return 0;
        const double far_limit = limits.z;
        return (far_limit - distance) * 255.0 / (far_limit - limits.y);
    }
    struct ParticleBatch { std::size_t first_index; std::size_t index_count; bool additive; int texture; };
}
IEffectListener* SferaEffectManager::findListener(uint32_t effect_id) const {
    const auto found = std::find_if(effect_listeners.begin(), effect_listeners.end(), [&](const auto& entry) { return entry.effect_id == effect_id; });
    return found == effect_listeners.end() ? nullptr : found->listener;
}

bool SferaEffectManager::registerListener(std::uint32_t effect_id, IEffectListener& listener) {
    if (auto* current = findListener(effect_id)) {
        if (current == &listener) return true;
        reportError("EM_RegisterEffectListener::Multiple listeners not implemented.");
        return false;
    }
    if (effect_listeners.size() >= 16) return false;
    effect_listeners.push_back({effect_id, &listener});
    return true;
}

void SferaEffectManager::unregisterListener(IEffectListener& listener) {
    std::erase_if(effect_listeners, [&](const auto& entry) { return entry.listener == &listener; });
    for (const auto& item : active_effects) if (item->effect != nullptr && item->effect->listener == &listener) item->effect->listener = nullptr;
}

void SferaEffectManager::clearListeners() {
    for (const auto& item : active_effects) if (item->effect != nullptr) item->effect->listener = nullptr;
    effect_listeners.clear();
}

void SferaEffectManager::sortRenderSlots() {
    if (render_slots.empty()) { render_order.clear(); return; }
    if (render_slot_count > render_slots.size()) throw std::out_of_range("Effect render slot count");
    render_order.resize(render_slot_count);
    for (std::size_t index = 0; index < render_slot_count; ++index) render_order[index] = index;
    const auto* slots = render_slots.data();
    std::stable_sort(render_order.begin(), render_order.end(), [&](std::size_t left, std::size_t right) { const auto& a = slots[left]; const auto& b = slots[right]; return a.additive != b.additive ? a.additive < b.additive : a.resource_id < b.resource_id; });
}
std::uint32_t SferaEffectManager::listenerKey(const SferaActiveEffect* handle) const {
    const auto found = std::find_if(active_effects.begin(), active_effects.end(), [&](const auto& item) { return item.get() == handle; });
    return found == active_effects.end() ? 0u : (*found)->listener_key;
}

void SferaEffectManager::renderParticles() {
    using namespace EffectRendering;
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    ++generation;
    if (diagnostics.enabled) ++diagnostics.render_calls;
    if (render_slot_count == 0u) return;
    auto* slots = render_slots.data();
    const int ambient = ambientBrightness() + 20;
    std::vector<std::uint16_t> indices;
    std::vector<ParticleBatch> batches;
    indices.reserve(30000u);
    batches.reserve(render_slot_count);
    auto vertices = device.colored_vertices.lock(std::max(device.colored_vertices.capacity(), std::size_t{8}));
    std::size_t vertex_count = 0u;
    int bound_texture = -1;
    std::optional<bool> active_blend;
    identityWorld(device);
    renderState(device, D3DRS_ZWRITEENABLE, FALSE);
    const auto flush = [&] {
        vertices.unlock();
        for (const auto& batch : batches) {
            if (active_blend != batch.additive) { active_blend = batch.additive; device.setAlphaBlending(D3DBLEND_SRCALPHA, !batch.additive ? D3DBLEND_INVSRCALPHA : D3DBLEND_ONE); }
            if (bound_texture != batch.texture) { bound_texture = batch.texture; if (bound_texture != -1) SphereRender::SceneRenderer::bindTexture(bound_texture); }
            if (batch.index_count == 0u) continue;
            auto output = device.indices_secondary.lock(batch.index_count);
            std::copy_n(indices.data() + batch.first_index, batch.index_count, output.data());
            output.unlock();
            device.drawBuffer(vertices.buffer(), D3DPT_TRIANGLELIST, 6u, vertices.first(), vertex_count,
                output.buffer(), batch.index_count, output.first(), sizeof(SphereRender::PositionColorUvVertex));
            if (diagnostics.enabled) diagnostics.submitted_quads += batch.index_count / 6u;
        }
        vertex_count = 0u;
        indices.clear();
        batches.clear();
    };
    for (std::size_t slot_index = 0u; slot_index < render_slot_count; ++slot_index) {
        auto& slot = slots[render_order[slot_index]];
        const auto additive = slot.additive;
        if (batches.empty() || batches.back().texture != slot.resource_id || batches.back().additive != additive) batches.push_back({indices.size(), 0u, additive, slot.resource_id});
        const int brightness = std::clamp(std::int64_t{slot.self_illumination} + ambient, std::int64_t{std::numeric_limits<int>::min()}, std::int64_t{255});
        if (!slot.custom_uv) { slot.uv[0][0] = 0.0f; slot.uv[0][1] = 0.0f; slot.uv[1][0] = 1.0f; slot.uv[1][1] = 0.0f; slot.uv[2][0] = 1.0f; slot.uv[2][1] = 1.0f; slot.uv[3][0] = 0.0f; slot.uv[3][1] = 1.0f; }
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex) {
            const auto scale = [&](std::size_t channel, int factor) { return slot.color[channel][vertex] * factor / 255; };
            auto& output = vertices[vertex_count + vertex];
            output.position = slot.position[vertex];
            output.diffuse = SferaColor::rgba(scale(0u, brightness), scale(1u, brightness), scale(2u, brightness), scale(3u, visibilityAlpha(output.position))).argb();
            if (diagnostics.enabled && (output.diffuse >> 24u) != 0u) ++diagnostics.alpha_vertices;
            output.specular = 0u;
            output.u = slot.uv[vertex][0];
            output.v = slot.uv[vertex][1];
        }
        for (std::uint16_t corner : {0u, 1u, 2u, 2u, 3u, 0u}) indices.push_back(SferaNumeric::lowHalf(SferaNumeric::lowWord(vertex_count + corner)));
        batches.back().index_count += 6u;
        vertex_count += 4u;
        if (vertex_count > vertices.size() - 8 || indices.size() > 29994u) {
            flush();
            vertices = device.colored_vertices.lock(device.colored_vertices.capacity());
        }
    }
    flush();
    device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    renderState(device, D3DRS_ZWRITEENABLE, TRUE);
}
void SferaBloodEffectRuntime::render() {
    using namespace EffectRendering;
    if (active_count == 0u) { phase = 0.0f; return; }
    for (auto& spot : spots) if (spot.life != 0.0f) { const double precise_life = spot.life; spot.life = precise_life - phase; if (spot.life < 0.0f) { spot.life = 0.0f; spot.vertex_count = 0u; --active_count; } }
    phase = 0.0f;
    const int brightness = ambientBrightness() + 100;
    const auto red = (brightness * 155 / 255) & 255u;
    const auto other = (brightness * 20 / 255) & 255u;
    if (active_count == 0u) return;
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    SphereRender::SceneRenderer::bindTexture(texture_id);
    identityWorld(device);
    renderState(device, D3DRS_RANGEFOGENABLE, FALSE);
    renderState(device, D3DRS_ZWRITEENABLE, FALSE);
    device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
    samplerState(device, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
    samplerState(device, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
    auto output = device.colored_vertices.lock(3000);
    std::size_t vertex_count = 0u;
    for (const auto& spot : spots) if (spot.life != 0.0f) {
        if (vertex_count + spot.vertex_count > 3000u) { vertex_count = 3000u; break; }
        const auto color = SferaColor::rgba(red, other, other, SferaNumeric::truncatedWord(spot.life * 255.0)).argb();
        for (std::size_t vertex = 0u; vertex < spot.vertex_count; ++vertex) { output[vertex_count] = spot.vertices[vertex]; output[vertex_count].diffuse = color; output[vertex_count].specular = 0u; ++vertex_count; }
    }
    output.unlock();
    device.drawBuffer(output.buffer(), D3DPT_TRIANGLELIST, 0u, output.first(), vertex_count,
        nullptr, 0u, 0u, sizeof(SphereRender::PositionColorUvVertex));
    renderState(device, D3DRS_RANGEFOGENABLE, TRUE);
    renderState(device, D3DRS_ZWRITEENABLE, TRUE);
    samplerState(device, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
}
void SferaEffectManager::drawFlare(int x, int y, int size, bool enabled) {
    if (flare_enabled != enabled) { flare_enabled = enabled; flare_transition = enabled ? FlareTransition::FadeIn : FlareTransition::FadeOut; }
    if (!enabled && flare_alpha == 0u) return;
    const auto texture = g_sfera_textures.find("fx_flare");
    const double logical_width = size * 640, logical_height = size * 480;
    const int width = logical_width / g_sfera_graphics_runtime.display_width;
    const int height = logical_height / g_sfera_graphics_runtime.display_height;
    const int left = x - (width >> 1);
    const int top = y - (height >> 1);
    const float environment = g_sfera_graphics_runtime.environment_factor;
    std::uint32_t intensity = 0u;
    if (environment < 0.3499999940395355f) intensity = std::min(SferaNumeric::truncatedWord((0.3499999940395355 - environment) * 2550.0), 255u);
    if (environment > 0.699999988079071f) intensity = std::min(SferaNumeric::truncatedWord((environment - 0.699999988079071) * 2550.0), 255u);
    if (environment < 0.1899999976158142f || environment > 0.8299999833106995f) intensity = 0u;
    const std::uint32_t alpha = flare_alpha * intensity >> 8u;
    if (alpha == 0u) return;
    const float uv[8]{0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f};
    SphereUI::InterfaceRenderer::setSpriteRenderMode(2u);
    GameInterface::drawSpriteTexture(D3DCOLOR_ARGB(alpha, 255, 100, 15), texture, left, top, (left + width), (top + height), uv, true);
    SphereUI::InterfaceRenderer::setSpriteRenderMode(0u);
}

void ShadowRasterizer::flushSpans(int height, const D3DLOCKED_RECT& surface, bool displaced) {
    auto* pixels = static_cast<std::uint8_t*>(surface.pBits);
    const std::ptrdiff_t stride = surface.Pitch;
    for (int y = 0; y < height; ++y) {
        auto* destination = pixels + y * stride;
        auto& span = displaced ? rows[y].displaced : rows[y].active;
        if (span.left >= span.right) continue;
        const std::uint16_t color = span.color & 65535u;
        for (int x = span.left; x <= span.right; ++x) SferaBinary::writeLittleEndian(destination + x * 2, color);
        span.left = INT32_MAX;
        span.right = INT32_MIN;
    }
}
void ShadowRasterizer::flush(int height, const D3DLOCKED_RECT& surface) { flushSpans(height, surface, false); pending = false; }
void ShadowRasterizer::polygon(std::uint32_t color, std::span<const ShadowPoint> points, int width, int height, const D3DLOCKED_RECT& surface) {
    if (points.empty()) return;
    const auto lowest = std::min_element(points.begin(), points.end(), [](const auto& a, const auto& b) { return a.y < b.y; });
    const std::size_t first_vertex = lowest - points.begin();
    const int first_row = lowest->y;
    int row = std::max(first_row, 0);
    struct Edge {
        std::size_t vertex;
        int end;
        float slope = 0.0f;
        float x = 0.0f;
        void step() { const double increment = slope; x += increment; }
    };
    Edge left{first_vertex, row - 1}, right{first_vertex, row - 1};
    std::size_t remaining = points.size();
    bool displaced = false;
    const auto advance = [&](Edge& edge, bool backwards) {
        const auto& previous = points[edge.vertex];
        if (backwards) edge.vertex = edge.vertex == 0 ? points.size() - 1 : edge.vertex - 1;
        else if (++edge.vertex == points.size()) edge.vertex = 0;
        const auto& current = points[edge.vertex];
        const int last_row = current.y;
        edge.end = std::min(last_row, height);
        --remaining;
        const double x = current.x, y = current.y;
        edge.slope = (x - previous.x) / (y - previous.y + 6.018531076210112e-36);
        edge.x = (row + 0.5 - previous.y) * edge.slope + previous.x;
    };
    do {
        while (left.end <= row && remaining > 0) advance(left, true);
        while (right.end <= row && remaining > 0) advance(right, false);
        while (row < left.end && row < right.end) {
            const int first = left.x, last = right.x;
            const int begin = std::max(first, 0), end = std::min(last, width - 1);
            left.step();
            right.step();
            auto& spans = rows[row++];
            if (begin > end) continue;
            auto& active = spans.active;
            if (active.left == INT32_MAX) { active = {begin, end, color}; pending = true; continue; }
            if (active.color != color || end < active.left || begin > active.right) {
                spans.displaced = active;
                active = {begin, end, color};
                displaced = true;
                continue;
            }
            active.left = std::min(active.left, begin);
            active.right = std::max(active.right, end);
        }
    } while (remaining > 0);
    if (displaced) flushSpans(height, surface, true);
}

void ShadowMap::createTextures() {
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    std::array<Microsoft::WRL::ComPtr<IDirect3DTexture9>, 3> replacement;
    for (std::size_t index = 0; index < replacement.size(); ++index) {
        const auto extent = 256u >> index;
        device.checkResult(device.native_device->CreateTexture(extent, extent, 1, 0, D3DFMT_R5G6B5,
            D3DPOOL_MANAGED, replacement[index].GetAddressOf(), nullptr), "CreateTexture(shadow)");
        TextureMapping pixels(replacement[index].Get());
        device.checkResult(pixels.status(), "LockRect(shadow)");
        for (std::size_t row = 0; row < extent; ++row) {
            auto bytes = pixels.row(row, extent * sizeof(std::uint16_t));
            if (bytes.size() != extent * sizeof(std::uint16_t)) throw std::runtime_error("Invalid shadow texture pitch");
            std::fill(bytes.begin(), bytes.end(), std::uint8_t{255});
        }
        device.checkResult(pixels.unlock(), "UnlockRect(shadow)");
    }
    mapping.reset();
    valid = false;
    textures = std::move(replacement);
    spot_texture = g_sfera_textures.find("shadspot");
}

void ShadowMap::initialize(std::uint32_t default_quality) {
    std::uint32_t value = default_quality;
    SphereUI::InterfaceConfiguration::open("config.cfg");
    value = SphereUI::InterfaceConfiguration::readInteger("SHAD", value);
    if (g_sfera_shadows == nullptr) { g_sfera_shadows = std::make_unique<ShadowMap>(); g_sfera_shadows->createTextures(); g_sfera_shadows->quality = value; }
}
void ShadowMap::shutdown() { g_sfera_shadows.reset(); }
void ShadowMap::setDirection(const SferaVec3F& value, float opacity) {
    fade = std::clamp(opacity, 0.0f, 1.0f);
    light_basis = SferaMatrix4x4F::identity();
    if (quality == 3u) {
        light_basis.m[1][1] = 0.0f;
        light_basis.m[2][1] = -1.0f;
        light_basis.m[1][2] = -1.0f;
        light_basis.m[2][2] = 0.0f;
        direction = {0.0f, -1.0f, 0.0f};
        return;
    }
    direction = value;
    direction.y = std::min(direction.y, -0.10000000149011612f);
    const float length = direction.length();
    const double x = direction.x, y = direction.y, z = direction.z;
    const float azimuth = std::atan2(x, z);
    const float yaw = -azimuth;
    float inclination = 0.0f;
    if (length != 0.0f) {
        const float rounded_ratio = y / length;
        const double ratio = rounded_ratio;
        inclination = std::asin(ratio);
    }
    const float pitch = std::min(inclination, -0.7853982448577881f);
    const auto [sy, cy] = SferaMath::rotationTerms(yaw);
    const auto [sp, cp] = SferaMath::rotationTerms(pitch);
    light_basis.m[0][0] = cy;
    light_basis.m[1][0] = sp * sy;
    light_basis.m[2][0] = -sy * cp;
    light_basis.m[1][1] = cp;
    light_basis.m[2][1] = sp;
    light_basis.m[0][2] = sy;
    light_basis.m[1][2] = -sp * cy;
    light_basis.m[2][2] = cy * cp;
}
bool ShadowMap::prepareModel(WorldObject& object, const SferaVec3F* position, float opacity, std::uint8_t detail) { const auto* model = g_sfera_world_objects.model(object); return prepareGeometry(object, position, opacity, detail, model->shadow_scale, model->shadow_spread); }
bool ShadowMap::prepareGeometry(WorldObject& object, const SferaVec3F* position, float opacity, std::uint8_t detail, float scale, float spot_scale) {
    SferaVec3F center = position == nullptr ? object.position : *position;
    if (position == nullptr) center.y = center.y - 0.800000011920929;
    valid = false;
    mapping.reset();
    rasterizer = {};
    origin = direction + center;
    if (quality == 4u) return true;
    const std::uint32_t shade = SferaNumeric::truncatedWord(((1.0 - opacity) * (1.0 - fade) + fade) * 255.0);
    if (shade >= 255u) return true;
    raster_color = D3DCOLOR_XRGB(shade, shade, shade);
    spot_color = D3DCOLOR_XRGB(~shade, ~shade, ~shade);
    if (quality == 3u) {
        if (spot_texture == -1) return false;
        projection = {};
        const float factor = 1.0 / spot_scale;
        projection.m[0][0] = factor;
        projection.m[1][2] = -factor;
        projection.m[2][1] = -factor;
        projection.m[3][3] = 1.0f;
        const double x = center.x, y = center.y, z = center.z;
        projection.m[0][3] = -x * factor;
        projection.m[1][3] = -z * -factor;
        projection.m[2][3] = -y * -factor;
    } else {
        level = std::min(SferaNumeric::lowByte(SferaNumeric::word(quality + detail)), std::uint8_t{2u});
        auto* texture = textures[level].Get();
        if (!texture) return false;
        mapping.emplace(texture);
        if (FAILED(mapping->status())) { mapping.reset(); return false; }
        surface = mapping->description();
        if (surface.Width == 0 || surface.Height == 0 || surface.Height > rasterizer.rows.size()) {
            mapping.reset();
            return false;
        }
        for (std::size_t row = 0; row < surface.Height; ++row) {
            auto bytes = mapping->row(row, surface.Width * sizeof(std::uint16_t));
            if (bytes.size() != surface.Width * sizeof(std::uint16_t)) {
                mapping.reset();
                return false;
            }
            std::fill(bytes.begin(), bytes.end(), std::uint8_t{255});
        }
        projection = light_basis;
        projection.scaleAxes({scale, scale, scale});
        const SferaVec3F translation{-center.x, -center.y, -center.z};
        for (std::size_t row = 0; row < 4; ++row) projection.m[row][3] = projection.projectComponent(row, translation);
    }
    valid = true;
    return true;
}
template<class Vertex> void ShadowMap::projectVertices(const Vertex* vertices, std::size_t vertex_count, const std::uint16_t* indices, std::size_t index_count) {
    if (quality >= 3u || !valid || textures[level] == nullptr) return;
    const auto world = g_sfera_graphics_runtime.d3d_runtime->world_transform.transposed();
    const auto transform = projection.multiplied(world);
    projected_points.resize(vertex_count);
    for (std::uint32_t index = 0u; index < vertex_count; ++index) {
        const auto& point = vertices[index].position;
        const auto coordinate = [&](std::size_t row, std::uint32_t extent) -> float {
            return (transform.projectComponent(row, point) + 0.5) * extent;
        };
        projected_points[index] = {coordinate(0u, surface.Width), coordinate(1u, surface.Height)};
    }
    const auto color = SferaColor::fromArgb(raster_color).rgb565();
    for (std::uint32_t face = 0u; face < index_count; face += 3u) {
        std::array<ShadowPoint, 3> points{};
        for (std::size_t corner = 0; corner < points.size(); ++corner) {
            const auto& point = projected_points[indices[face + corner]];
            const int x = point.x, y = point.y;
            points[corner].x = x;
            points[corner].y = y;
        }
        const double first_x = points[1].x, first_y = points[1].y;
        const double second_x = points[2].x, second_y = points[2].y;
        if ((first_x - points[0].x) * (second_y - points[0].y) < (second_x - points[0].x) * (first_y - points[0].y)) continue;
        rasterizer.polygon(color, points, surface.Width, surface.Height, mapping->rectangle());
    }
}
void ShadowMap::projectModel(const SphereRender::Model& model, std::size_t index, const SferaMatrix4x4F* world) {
    if (quality >= 3u || !valid || textures[level] == nullptr) return;
    if (world != nullptr) { const auto transposed = world->transposed(); g_sfera_graphics_runtime.d3d_runtime->setTransform(D3DTS_WORLD, transposed); }
    const auto& submesh = model.submeshes[index];
    const auto face_count = std::min(submesh.face_count, std::size_t{334u});
    for (std::size_t face = 0u; face < face_count; ++face) { const auto& source = model.faces[submesh.first_face + face]; face_indices[face * 3u] = source.vertices[0]; face_indices[face * 3u + 1u] = source.vertices[2]; face_indices[face * 3u + 2u] = source.vertices[1]; }
    projectVertices(model.vertices.data() + submesh.first_vertex, submesh.vertex_count, face_indices.data(), face_count * 3u);
}

ShadowMap::Pass::Pass(ShadowMap& owner)
    : owner_(owner), direction_(owner.direction), fade_(owner.fade), basis_(owner.light_basis) {
    owner_.mapping.reset();
    owner_.valid = false;
}
ShadowMap::Pass::~Pass() noexcept {
    owner_.mapping.reset();
    owner_.valid = false;
}
void ShadowMap::draw(const SferaVec3F* vertices, std::size_t triangle_count) {
    using namespace EffectRendering;
    if (!std::exchange(valid, false)) return;
    if (quality < 3u) {
        if (!mapping) return;
        if (rasterizer.pending) rasterizer.flush(surface.Height, mapping->rectangle());
        for (std::size_t row = 0; row < surface.Height; ++row) {
            auto bytes = mapping->row(row, surface.Width * sizeof(std::uint16_t));
            if (row == 0 || row + 1 == surface.Height) std::fill(bytes.begin(), bytes.end(), std::uint8_t{255});
            else {
                std::fill_n(bytes.begin(), sizeof(std::uint16_t), std::uint8_t{255});
                std::fill_n(bytes.end() - sizeof(std::uint16_t), sizeof(std::uint16_t), std::uint8_t{255});
            }
        }
        const HRESULT result = mapping->unlock();
        mapping.reset();
        g_sfera_graphics_runtime.d3d_runtime->checkResult(result, "UnlockRect(shadow)");
    }
    if (triangle_count == 0u) return;
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    samplerState(device, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
    samplerState(device, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
    identityWorld(device);
    device.setAlphaBlending(D3DBLEND_ZERO, D3DBLEND_SRCCOLOR);
    renderState(device, D3DRS_FOGENABLE, FALSE);
    renderState(device, D3DRS_ZWRITEENABLE, FALSE);
    if (quality == 3u) {
        SphereRender::SceneRenderer::bindTexture(spot_texture);
        renderState(device, D3DRS_DESTBLEND, D3DBLEND_INVSRCCOLOR);
        const auto count = std::min(triangle_count * 3u, spot_vertices.size());
        for (std::size_t index = 0; index < count; ++index) {
            const auto point = projection.transformPoint(vertices[index]);
            auto& vertex = spot_vertices[index];
            vertex.position = vertices[index];
            vertex.diffuse = spot_color;
            vertex.specular = 0u;
            vertex.u = point.x + 0.5;
            vertex.v = point.y + 0.5;
        }
        renderState(device, D3DRS_CULLMODE, D3DCULL_NONE);
        device.checkResult(device.native_device->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1), "SetFVF");
        device.drawVertices(D3DPT_TRIANGLELIST, 0u, spot_vertices.data(), count, nullptr, 0u, sizeof(SphereRender::PositionColorUvVertex));
    } else {
        device.checkResult(device.native_device->SetTexture(0u, textures[level].Get()), "SetTexture");
        const auto count = triangle_count * 3u;
        auto output = device.model_vertices.lock(count);
        for (std::uint32_t index = 0u; index < count; ++index) { const auto point = projection.transformPoint(vertices[index]); output[index].position = vertices[index]; output[index].u = point.x + 0.5; output[index].v = point.y + 0.5; }
        output.unlock();
        device.drawBuffer(output.buffer(), D3DPT_TRIANGLELIST, 0u, output.first(), count,
            nullptr, 0u, 0u, sizeof(SphereRender::PositionNormalUvVertex));
    }
    samplerState(device, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
    samplerState(device, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
    device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    renderState(device, D3DRS_FOGENABLE, TRUE);
    renderState(device, D3DRS_ZWRITEENABLE, TRUE);
}
void ShadowMap::selectObjectLight(const WorldObject& object) {
    float closest_distance = 50.0f;
    const SferaLightRecord* closest = nullptr;
    SferaVec3F closest_direction{};
    for (std::size_t index = 0u; index < g_sfera_light_runtime.candidate_count; ++index) {
        const auto& light = g_sfera_light_runtime.render_candidates[index];
        if (!g_sfera_light_runtime.render_candidate_active[index] || object.position.y < light.position.y) continue;
        const auto difference = light.position - object.position;
        const float distance = (difference).length();
        if (distance != 0.0f && distance < 15.0f && distance < closest_distance) { closest_distance = distance; closest = &light; closest_direction = difference; }
    }
    if (closest != nullptr) {
        const float inverse = 1.0 / closest_distance;
        closest_direction = closest_direction * inverse;
        float opacity = closest_distance / 15.0 + 0.20000000298023224;
        const float environment = g_sfera_graphics_runtime.environment_factor;
        if (SphereRender::SceneRenderer::interior_scene == 0u && environment >= 0.25f && environment <= 0.8299999833106995f) opacity = std::max(opacity, g_sfera_graphics_runtime.view_scale);
        setDirection(closest_direction, opacity);
    } else if (SphereRender::SceneRenderer::interior_scene != 0u) setDirection({0.0f, 1.0f, 0.0f}, 1.0f);
}
float ShadowMap::projectionExtension(const WorldObject& object) const {
    const double vertical = std::max(std::fabs(direction.y), 0.699999988079071f);
    const float rounded_angle = std::acos(vertical);
    const double angle = rounded_angle;
    const float tangent = std::tan(angle);
    const double top = object.bounds_maximum.y;
    return tangent * (top - object.bounds_minimum.y);
}
void ShadowMap::prepareObject(std::uint32_t handle, ExtendedWorldObject& object, double width, float spot_scale, float& extension) {
    auto& shadows = *g_sfera_shadows;
    if (shadows.quality >= 4u || object.scale < 0.9900000095367432f) return;
    shadows.selectObjectLight(object);
    const float distance = (g_sfera_world_objects.object(1u)->position - object.position).length();
    const float distance_opacity = 1.0 - (distance - 15.0) / 10.0;
    const float opacity = std::clamp(distance_opacity, 0.0f, 1.0f);
    const auto detail = distance > 7.0f ? 2u : distance > 5.0f ? 1u : 0u;
    SphereWorld::ContactQuery::updateBounds(handle);
    extension = shadows.projectionExtension(object);
    const float scale = 1.4900000095367432 / (extension + width);
    shadows.prepareGeometry(object, nullptr, opacity, detail, scale, spot_scale);
}
void ShadowMap::drawObject(ExtendedWorldObject& object, double width, float extension) {
    auto& shadows = *g_sfera_shadows;
    if (shadows.quality >= 4u || object.scale < 0.9900000095367432f) return;
    const auto offset = SferaVec3F{object.position.x - shadows.origin.x, 0.0f, object.position.z - shadows.origin.z}.normalized() * extension;
    const auto center = object.position + offset * 0.5f;
    const float radius = (extension + width) * 0.800000011920929;
    const SferaVec3F radius_vector{radius, radius, radius};
    const SphereWorld::Bounds bounds{center - radius_vector, center + radius_vector};
    g_sfera_world_spatial.gatherShadowTriangles(bounds, center, radius, shadows.origin, shadows.direction);
    const auto& vertices = g_sfera_world_spatial.shadowVertices();
    shadows.draw(vertices.data(), (vertices.size() / 3u));
}

namespace {

    void skyConfigurationError(const std::string& section) { CSphereError error; error.write(("Illegal format of Sky.txt, line: " + section)); }
}
void SkyEnvironment::load(const std::string& filename) {
    SkyEnvironment replacement;
    SphereRender::ModelParameters parameters;
    parameters.load(filename);
    auto integer = [&](const std::string& section, std::string_view key) { const auto value = parameters.intValue(section, key); if (!value) skyConfigurationError(section); return value.value_or(0); };
    auto scalar = [&](const std::string& section, std::string_view key) { const auto value = parameters.floatValue(section, key); if (!value) skyConfigurationError(section); return value.value_or(0.0f); };
    const auto channels = [&](const std::string& section, std::string_view prefix) {
        SferaVec3F result{};
        constexpr std::array<std::string_view, 3> names{"r", "g", "b"};
        for (std::size_t channel = 0; channel < names.size(); ++channel)
            result.setComponent(channel, integer(section, std::string(prefix) + std::string(names[channel])));
        return result;
    };
    const auto color = [&](const std::string& section) {
        const auto rgb = channels(section, {});
        const float alpha = integer(section, "a");
        return SferaVec4F{rgb.x, rgb.y, rgb.z, alpha};
    };
    for (std::size_t index = 0; index < 11; ++index) {
        const std::string suffix(std::string_view("0123456789a").substr(index, 1u));
        if (!parameters.hasModel("c" + suffix)) continue;
        if (!parameters.contains("c" + suffix, "r")) skyConfigurationError("c" + suffix);
        auto& state = replacement.states[index];
        auto samples = [&](std::string_view prefix, auto& keys) {
            for (std::size_t sample = 0; sample < keys.size(); ++sample) {
                std::string section = std::string(prefix) + suffix;
                section += std::to_string(sample);
                keys[sample] = {color(section), scalar(section, "p")};
            }
        };
        samples("a", state.primary);
        samples("b", state.secondary);
        state.reference = color("c" + suffix);
        const std::string section = "d" + suffix;
        state.time = scalar(section, "time");
        state.sunPhase = scalar(section, "sun");
        state.sunColor = channels(section, "s");
        state.ambientColor = channels(section, "a");
    }
    replacement.sunsetState = integer("SunsetStateN", "n");
    replacement.sunriseState = integer("SunriseStateN", "n");
    for (const auto state : {replacement.sunsetState, replacement.sunriseState}) {
        if (state < 0 || state >= replacement.states.size()) skyConfigurationError("Sun state index");
    }
    *this = std::move(replacement);
}
void SkyEnvironment::interval(double time, int& first, int& second, float& fraction) const {
    second = 1;
    while (second < states.size() && states[second].time < time) ++second;
    if (second == states.size()) WorldDiagnostics::fail("n2 >= SKY_STATES_NUM");
    first = second - 1;
    const double end = states[second].time;
    fraction = (time - states[first].time) / (end - states[first].time);
}
void SkyEnvironment::sample(float time, SkyState& output) const {
    int first, second;
    float fraction;
    interval(time, first, second, fraction);
    const auto& start = states[first];
    const auto& finish = states[second];
    auto samples = [&](auto& outputKeys, const auto& firstKeys, const auto& secondKeys) {
        for (std::size_t index = 0; index < outputKeys.size(); ++index) {
            outputKeys[index] = {SferaMath::interpolate(firstKeys[index].color, secondKeys[index].color, fraction),
                SferaMath::interpolate(firstKeys[index].position, secondKeys[index].position, fraction)};
        }
    };
    samples(output.primary, start.primary, finish.primary);
    output.reference = SferaMath::interpolate(start.reference, finish.reference, fraction);
    samples(output.secondary, start.secondary, finish.secondary);
    output.sunPhase = SferaMath::interpolate(start.sunPhase, finish.sunPhase, fraction);
    output.sunColor = SferaMath::interpolate(start.sunColor, finish.sunColor, fraction);
    output.ambientColor = SferaMath::interpolate(start.ambientColor, finish.ambientColor, fraction);
}
void SkyEnvironment::sunDirection(float time, SferaVec3F& output) const {
    int first, second;
    float fraction;
    interval(time, first, second, fraction);
    float phase = SferaMath::interpolate(states[first].sunPhase, states[second].sunPhase, fraction);
    const float sunrise = states[sunriseState].sunPhase;
    const float sunset = states[sunsetState].sunPhase;
    const double sunset_phase = sunset;
    if (!(phase > sunrise && phase < sunset)) { float relative = phase - sunset; if (relative < 0.0f) relative += 1.0f; phase = relative * (sunset_phase - sunrise) / (1.0 + sunrise - sunset) + sunrise; }
    const float angle = phase * 3.1415929794311523 * 2.0;
    const auto [sine, cosine] = SferaMath::rotationTerms(angle);
    output.x = -sine;
    output.y = cosine;
    output.z = 0.0f;
}
void SkyEnvironment::lighting(float time, SferaVec3F& sun, SferaVec3F& ambient) const { int first, second; float fraction; interval(time, first, second, fraction); sun = SferaMath::interpolate(states[first].sunColor, states[second].sunColor, fraction); ambient = SferaMath::interpolate(states[first].ambientColor, states[second].ambientColor, fraction); }
namespace {
    void updateNatureWeather(float value, bool& enabled, void (SferaNatureManager::*start)(), void (SferaNatureManager::*stop)(), void (SferaNatureManager::*apply)(float)) { auto* nature = sfera_nature_manager(); if (value > 0.0010000000474974513f && SphereRender::SceneRenderer::interior_scene == 0u) { if (!enabled) { if (nature != nullptr) (nature->*start)(); enabled = true; } if (nature != nullptr) (nature->*apply)(value); } else if (enabled) { if (nature != nullptr) (nature->*stop)(); enabled = false; } }
}
void SferaNatureManager::updateRain() { updateNatureWeather(g_sfera_weather_runtime.current.rain, g_sfera_effect_manager.rain_enabled, &SferaNatureManager::startRain, &SferaNatureManager::stopRain, &SferaNatureManager::setRainIntensity); }
void SferaNatureManager::updateLightning() { updateNatureWeather(g_sfera_weather_runtime.current.lightning, g_sfera_effect_manager.lightning_enabled, &SferaNatureManager::startLighting, &SferaNatureManager::stopLighting, &SferaNatureManager::setLightingLevel); }

float EnvironmentZone::weight(float x, float z) const {
    const double origin_x = originX, origin_z = originZ;
    const float left = x - (origin_x + minimumX);
    if (left < 0.0f) return 0.0f;
    const float top = z - (origin_z + minimumZ);
    if (top < 0.0f) return 0.0f;
    const float right = origin_x + maximumX - x;
    if (right < 0.0f) return 0.0f;
    const float bottom = origin_z + maximumZ - z;
    if (bottom < 0.0f) return 0.0f;
    const float distance = std::min(std::min(left, top), std::min(right, bottom));
    return borderFade <= distance ? 1.0f : distance / borderFade;
}

void EnvironmentZones::interval(double time, int& first, int& second, float& fraction) {
    constexpr float positions[]{0.0f, 0.19f, 0.27f, 0.34f, 0.50f, 0.66f, 0.73f, 0.81f, 1.0f};
    first = second = 0;
    fraction = 0.0f;
    for (int index = 0; index < 8; ++index) {
        if (positions[index] <= time && positions[index + 1] >= time) {
            first = index;
            second = (index + 1) % 8;
            const double end = positions[index + 1];
            fraction = (time - positions[index]) / (end - positions[index]);
            return;
        }
    }
}
void EnvironmentZone::sample(int first, int second, float fraction, EnvironmentLighting& output) const { output.fogParameters = fogParameters; output.fogColor = SferaMath::interpolate(fogColors[first], fogColors[second], fraction); output.ambientColor = SferaMath::interpolate(ambientColors[first], ambientColors[second], fraction); output.sunColor = SferaMath::interpolate(sunColors[first], sunColors[second], fraction); }
void EnvironmentZones::calculate(bool useDefault, float x, float z, float time, const SkyEnvironment& sky, EnvironmentLighting& output) {
    if (zones.empty()) { CSphereError error; error.write("Error in ZoningMgr::calc_params() : zonesParams is Empty"); return; }
    int first, second;
    float fraction;
    interval(time, first, second, fraction);
    SferaVec3F sun{}, ambient{};
    sky.lighting(time, sun, ambient);
    const auto sample = [&](std::size_t index, EnvironmentLighting& target) {
        if (index + 1 != zones.size()) { zones[index].sample(first, second, fraction, target); return; }
        auto background = zones[index];
        background.sunColors.fill(sun);
        background.ambientColors.fill(ambient);
        background.sample(first, second, fraction, target);
    };
    std::vector<std::pair<std::size_t, float>> influences;
    if (!useDefault) for (std::size_t index = 0; index < zones.size(); ++index) { const auto amount = zones[index].weight(x, z); if (amount >= 0.009999999776482582f) { influences.emplace_back(index, amount); if (amount > 0.9900000095367432f) break; } }
    if (influences.empty()) { sample(zones.size() - 1, output); return; }
    sample(influences.back().first, output);
    for (std::size_t index = influences.size() - 1; index > 0; --index) { EnvironmentLighting foreground{}; const auto [zone, amount] = influences[index - 1]; sample(zone, foreground); output.fogParameters = SferaMath::interpolate(output.fogParameters, foreground.fogParameters, amount); output.fogColor = SferaMath::interpolate(output.fogColor, foreground.fogColor, amount); output.ambientColor = SferaMath::interpolate(output.ambientColor, foreground.ambientColor, amount); output.sunColor = SferaMath::interpolate(output.sunColor, foreground.sunColor, amount); }
}
void EnvironmentZones::load(const std::string& filename) {
    SphereRender::ConfigDocument::setStorageMode(SphereRender::ConfigDocument::StorageMode::Plain);
    const auto document = SphereRender::ConfigDocument::open(filename);
    const auto count = document.arraySize("zonesParams").value_or(0);
    std::vector<EnvironmentZone> replacement;
    replacement.reserve(count);
    auto fail = [](std::size_t zone, std::string_view field) { CSphereError error; error.write(std::format("Wrong format of \"Landscape\\zoning.cfg\" : zonesParams[{}] : {}", zone, field)); };
    for (std::size_t index = 0; index < count; ++index) {
        auto* configuration = document.objectAt("zonesParams", index);
        if (configuration == nullptr) { fail(index, "zoneParamsCfg is NULL"); continue; }
        EnvironmentZone zone{};
        auto scalar = [&](std::string_view name) { const auto value = configuration->real(name); if (!value) fail(index, name); return value.value_or(0.0f); };
        zone.originX = scalar("xPatchMin"); zone.originZ = scalar("zPatchMin"); zone.minimumX = scalar("xMin"); zone.maximumX = scalar("xMax"); zone.minimumZ = scalar("zMin"); zone.maximumZ = scalar("zMax"); zone.borderFade = scalar("borderFadeDist");
        zone.fogParameters = {scalar("skyFogAlpha"), scalar("fogNear"), scalar("fogFar")};
        if (configuration->arraySize("dayColors").value_or(0) != 8) fail(index, "wrong size of dayColors");
        for (std::size_t day = 0; day < 8; ++day) {
            auto* colors = configuration->objectAt("dayColors", day);
            if (colors == nullptr) { fail(index, "dayColorCfg is NULL"); continue; }
            auto color = [&](std::string_view name) { auto component = [&](std::size_t axis) { const auto value = colors->realAt(name, axis); if (!value) fail(index, std::string(name) + "[" + std::to_string(day) + "]"); return value.value_or(0.0f); }; return SferaVec3F{component(0), component(1), component(2)}; };
            zone.fogColors[day] = color("fogColor"); zone.ambientColors[day] = color("ambientColor"); zone.sunColors[day] = color("sunColor");
        }
        replacement.push_back(zone);
    }
    zones = std::move(replacement);
}

namespace {
    std::string weatherIndex(std::string_view prefix, std::size_t index, std::size_t digits = 2u) {
        const auto number = std::to_string(index);
        return std::string(prefix) + std::string(number.size() < digits ? digits - number.size() : 0u, '0') + number;
    }
    [[noreturn]] void weatherFormatError(std::string_view model, std::string_view parameter) { WorldDiagnostics::fail((std::string("wrong format of weather.txt\n") + std::string(model) + ", " + std::string(parameter))); }
    std::string weatherName(std::string_view name) {
        if (name.size() >= 20) weatherFormatError(name, "texture name too long");
        return std::string(name);
    }
}

void WeatherScenarios::load(const std::string& filename) {
    WeatherScenarios replacement;
    SphereRender::ModelParameters parameters;
    parameters.load(filename);
    const auto number = [&](std::string_view model, std::string_view key) { const auto value = parameters.floatValue(model, key); if (!value) weatherFormatError(model, key); return *value; };
    const auto integer = [&](std::string_view model, std::string_view key) { const auto value = parameters.intValue(model, key); if (!value) weatherFormatError(model, key); return *value; };
    const auto text = [&](std::string_view model, std::string_view key) { const auto value = parameters.stringValue(model, key); if (!value) weatherFormatError(model, key); return *value; };
    const auto skyNames = [&](std::string_view model) {
        const auto name = [&](std::string_view key) {
            auto result = weatherName(text(model, key));
            if (SferaText::asciiEqual(result, "none")) result.clear();
            return result;
        };
        return WeatherSkyPair{name("nsky1"), name("nsky2")};
    };
    constexpr std::string_view durationJitter = "05185514038799035566164306887187530785282430311941";
    for (std::size_t index = 0; index < 100; ++index) {
        const auto model = weatherIndex("s", index);
        if (!parameters.hasModel(model)) break;
        WeatherScenario scenario;
        const auto duration = 1LL * integer(model, "stime") + durationJitter[index % durationJitter.size()] - '0';
        if (duration <= 0 || duration > INT32_MAX) weatherFormatError(model, "stime");
        scenario.duration = duration;
        scenario.sky = skyNames(model);
        scenario.skyStart = number(model, "tsky1");
        scenario.skyEnd = number(model, "tsky2");
        for (std::size_t frameIndex = 0; frameIndex < 10; ++frameIndex) {
            const auto key = model + "_" + std::to_string(frameIndex);
            if (!parameters.hasModel(key)) break;
            const auto time = std::trunc((scenario.duration - 0.009999999776482582) * number(key, "t"));
            if (!std::isfinite(time) || time < 0 || time >= scenario.duration) weatherFormatError(key, "t");
            WeatherKeyframe frame{SferaNumeric::truncateInt(time), {number(key, "r"), number(key, "fl1"), number(key, "fl2"), number(key, "cs")}};
            if (!scenario.keyframes.empty() && frame.time < scenario.keyframes.back().time) weatherFormatError(key, "keyframe order");
            scenario.keyframes.push_back(frame);
        }
        if (scenario.keyframes.empty()) weatherFormatError(model, "missing keyframes");
        replacement.scenarios.push_back(std::move(scenario));
    }
    for (std::size_t index = 0; index < 30; ++index) {
        const auto model = weatherIndex("t", index);
        if (!parameters.hasModel(model)) break;
        SceneSkyLayer texture;
        texture.texture = weatherName(text(model, "ntex"));
        texture.projectionWarp = number(model, "sc1");
        texture.uvScale = number(model, "sc2");
        texture.trackOffset = integer(model, "scrll") != 0;
        texture.minimumTime = number(model, "time1");
        texture.maximumTime = number(model, "time2");
        for (std::size_t sample = 0; sample < texture.colors.size(); ++sample) {
            texture.colors[sample] = {number(model + "c", weatherIndex("r", sample)), number(model + "c", weatherIndex("g", sample)), number(model + "c", weatherIndex("b", sample))};
        }
        replacement.textures.push_back(std::move(texture));
    }
    for (std::size_t item = 0; item < 200; ++item) {
        const auto model = weatherIndex("q", item, 3);
        if (!parameters.hasModel(model)) break;
        const auto index = integer(model, "s");
        if (index < 0 || index >= replacement.scenarios.size()) weatherFormatError(model, "s");
        const auto duration = replacement.scenarios[index].duration;
        if (duration > INT32_MAX - replacement.totalDuration) weatherFormatError(model, "total duration overflow");
        replacement.sequence.push_back(index);
        replacement.totalDuration += duration;
    }
    if (replacement.sequence.empty()) weatherFormatError(filename, "missing sequence");
    for (std::size_t index = 0; index < 30; ++index) {
        const auto model = weatherIndex("c", index);
        if (!parameters.hasModel(model)) break;
        replacement.pairs.push_back(skyNames(model));
    }
    *this = std::move(replacement);
}

const WeatherScenario& WeatherScenarios::at(std::size_t sequenceIndex) const {
    if (sequenceIndex >= sequence.size() || sequence[sequenceIndex] >= scenarios.size()) WorldDiagnostics::fail("wScenarioArr[curSN] >= wScenariosNum");
    return scenarios[sequence[sequenceIndex]];
}

void WeatherScenarios::locate(int time, std::size_t& sequenceIndex, int& startTime, int& localTime) const {
    if (totalDuration == 0) WorldDiagnostics::fail("Weather sequence has zero duration");
    const auto cyclicTime = time % totalDuration;
    int end = 0;
    for (std::size_t index = 0u; index < sequence.size(); ++index) {
        const auto& scenario = at(index);
        end += scenario.duration;
        if (cyclicTime < end) { sequenceIndex = index; localTime = scenario.duration - end + cyclicTime; startTime = time - localTime; return; }
    }
}

int WeatherScenarios::advance(std::size_t& sequenceIndex, std::size_t& keyframe) const {
    const auto& scenario = at(sequenceIndex);
    const auto time = scenario.keyframes[keyframe].time;
    if (++keyframe != scenario.keyframes.size()) return scenario.keyframes[keyframe].time - time;
    keyframe = 0u;
    if (++sequenceIndex == sequence.size()) sequenceIndex = 0u;
    return scenario.duration - time + at(sequenceIndex).keyframes.front().time;
}

int WeatherScenarios::retreat(std::size_t& sequenceIndex, std::size_t& keyframe) const {
    const auto time = at(sequenceIndex).keyframes[keyframe].time;
    if (keyframe != 0u) return time - at(sequenceIndex).keyframes[--keyframe].time;
    sequenceIndex = sequenceIndex == 0u ? sequence.size() - 1u : sequenceIndex - 1u;
    const auto& scenario = at(sequenceIndex);
    keyframe = scenario.keyframes.size() - 1u;
    return scenario.duration - scenario.keyframes[keyframe].time + time;
}

double WeatherScenarios::nextValue(std::size_t sequenceIndex, int time, std::size_t property, int& distance) const {
    const auto& scenario = at(sequenceIndex);
    std::size_t keyframe = 0u;
    while (keyframe < scenario.keyframes.size() && scenario.keyframes[keyframe].time < time) ++keyframe;
    if (keyframe == scenario.keyframes.size()) { distance = scenario.duration - time; if (++sequenceIndex == sequence.size()) sequenceIndex = 0u; keyframe = 0u; distance += at(sequenceIndex).keyframes.front().time; }
    else distance = scenario.keyframes[keyframe].time - time;
    const auto initialSequence = sequenceIndex, initialFrame = keyframe;
    for (;;) {
        const auto value = at(sequenceIndex).keyframes[keyframe].properties[property];
        if (value >= 0.0f) return value;
        distance += advance(sequenceIndex, keyframe);
        if (sequenceIndex == initialSequence && keyframe == initialFrame) WorldDiagnostics::fail("Weather property has no keyframe value");
    }
}

double WeatherScenarios::previousValue(std::size_t sequenceIndex, int time, std::size_t property, int& distance) const {
    const auto& scenario = at(sequenceIndex);
    std::size_t keyframe = scenario.keyframes.size();
    while (keyframe != 0u && scenario.keyframes[keyframe - 1u].time > time) --keyframe;
    if (keyframe == 0u) {
        sequenceIndex = sequenceIndex == 0u ? sequence.size() - 1u : sequenceIndex - 1u;
        keyframe = at(sequenceIndex).keyframes.size() - 1u;
        distance = time + at(sequenceIndex).duration - at(sequenceIndex).keyframes[keyframe].time;
    } else {
        --keyframe;
        distance = time - scenario.keyframes[keyframe].time;
    }
    const auto initialSequence = sequenceIndex, initialFrame = keyframe;
    for (;;) {
        const auto value = at(sequenceIndex).keyframes[keyframe].properties[property];
        if (value >= 0.0f) return value;
        distance += retreat(sequenceIndex, keyframe);
        if (sequenceIndex == initialSequence && keyframe == initialFrame) WorldDiagnostics::fail("Weather property has no keyframe value");
    }
}

void WeatherScenarios::copyTexture(std::string_view name, SceneSkyLayer& output) const {
    if (name.empty()) { output = {}; return; }
    for (std::size_t index = 0u; index < textures.size(); ++index) if (SferaText::asciiEqual(textures[index].texture, name)) { output = textures[index]; return; }
    WorldDiagnostics::warning((std::string("Sky texture name absent in params. ") + std::string(name)));
}

WeatherSkyPair WeatherScenarios::selectSky(int time, float dayTime) const {
    std::size_t index = 0u;
    int start = 0, local = 0;
    locate(time, index, start, local);
    const auto& scenario = at(index);
    const double precise_local = local;
    const float fraction = precise_local / scenario.duration;
    if (fraction >= 1.0f) WorldDiagnostics::fail("internal error 98742756");
    const WeatherSkyPair* selected = nullptr;
    if ((!scenario.sky.primary.empty() || !scenario.sky.secondary.empty()) && scenario.skyStart <= fraction && scenario.skyEnd >= fraction) selected = &scenario.sky;
    else {
        std::vector<const WeatherSkyPair*> available;
        for (std::size_t pair = 0u; pair < pairs.size(); ++pair) {
            const auto& sky = pairs[pair];
            const auto& name = !sky.primary.empty() ? sky.primary : sky.secondary;
            if (name.empty()) { available.push_back(&sky); continue; }
            const SceneSkyLayer* layer = nullptr;
            for (std::size_t texture = 0u; texture < textures.size(); ++texture) if (SferaText::asciiEqual(textures[texture].texture, name)) { layer = &textures[texture]; break; }
            if (layer == nullptr) { WorldDiagnostics::warning((std::string("Sky texture name present in para, but absent in params. ") + std::string(name))); continue; }
            if (layer->minimumTime <= dayTime && layer->maximumTime >= dayTime) available.push_back(&sky);
        }
        if (!available.empty()) { const auto count = std::ssize(available); selected = available[(start % count + count) % count]; }
    }
    return selected == nullptr ? WeatherSkyPair{} : *selected;
}

void WeatherScenarios::update(int time, float dayTime, WeatherState& output, bool alternateClouds) {
    if (time <= lastUpdate) return;
    lastUpdate = time;
    std::size_t sequenceIndex = 0u;
    int startTime = 0, localTime = 0;
    locate(time, sequenceIndex, startTime, localTime);
    constexpr std::array<float WeatherState::*, 4> destinations{&WeatherState::rain, &WeatherState::lightning, &WeatherState::wind, &WeatherState::cloud};
    for (std::size_t index = 0; index < destinations.size(); ++index) {
        const auto property = index;
        int previousDistance = 0, nextDistance = 0;
        const float previous = previousValue(sequenceIndex, localTime, property, previousDistance);
        float value = previous;
        if (previousDistance != 0) {
            const float next = nextValue(sequenceIndex, localTime, property, nextDistance);
            const double precise_previous = previous;
            const double precise_next_distance = nextDistance;
            value = (next - precise_previous) * previousDistance / (previousDistance + precise_next_distance) + previous;
        }
        output.*destinations[index] = value;
    }
    const auto selected = selectSky(time, dayTime);
    output.sky.opacity = 0.0f;
    if (!selected.primary.empty() || !selected.secondary.empty()) {
        constexpr int transitionSteps = 81;
        constexpr double dayStep = 0.00017361111531499773;
        const auto distanceToChange = [&](int direction) {
            for (int distance = 1; distance < transitionSteps; ++distance) {
                const int sampleTime = SferaNumeric::signedWord(SferaNumeric::word(time) + SferaNumeric::word(direction * distance));
                const float sampleDay = dayTime + (direction * distance) * dayStep;
                if (selected != selectSky(sampleTime, sampleDay)) return distance;
            }
            return transitionSteps;
        };
        const auto nextChange = distanceToChange(1);
        const auto previousChange = distanceToChange(-1);
        windDirection(previousChange == 1, startTime, output.windX, output.windZ);
        const double precise_transition_steps = transitionSteps;
    output.sky.opacity = std::min(nextChange, previousChange) / precise_transition_steps;
    }
    copyTexture(selected.primary, output.sky.primary);
    copyTexture(selected.secondary, output.sky.secondary);
    if (alternateClouds) {
        copyTexture("clouds8", output.clouds.primary);
        copyTexture("clouds8a", output.clouds.secondary);
        output.clouds.opacity = 1.0f;
    }
}

void WeatherScenarios::windDirection(bool refresh, int seed, float& x, float& z) {
    auto& state = g_sfera_weather_runtime;
    if (refresh || (state.direction_sin_component == 0.0f && state.direction_cos_component == 0.0f)) {
        const auto direction = (seed >> 1) & 7;
        const auto intensity = ((seed >> 4) & 3) + 1;
        const float angle = direction * 0.7853982448577881;
        const float speed = (intensity * 0.25) * 0.00019999999494757503;
        const auto [sine, cosine] = SferaMath::rotationTerms(angle);
        state.direction_sin_component = cosine * speed;
        state.direction_cos_component = sine * speed;
    }
    x = state.direction_sin_component;
    z = state.direction_cos_component;
}

// Full writes and closure are shared by UI and VM configuration codecs.
bool SferaFileManager::writeFile(const std::string& path, std::span<const std::byte> source) {
    if (path.empty()) return false;
    ::_chmod(path.c_str(), _S_IREAD | _S_IWRITE);
    std::unique_ptr<FILE, decltype(&std::fclose)> stream(::_fsopen(path.c_str(), "wb", _SH_DENYNO), &std::fclose);
    if (!stream) return false;
    const auto written = transferFileBytes(::_fileno(stream.get()), source, ::_write);
    const bool closed = std::fclose(stream.release()) == 0;
    return std::cmp_equal(written, source.size()) && closed;
}
