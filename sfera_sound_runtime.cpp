#include "semantic_static.h"
#include "sfera_sound.h"

#include <algorithm>
#include <charconv>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iterator>
#include <limits>
#include <memory>
#include <new>
#include <string>
#include <string_view>
#include <utility>

SferaSoundRuntime g_sfera_sound_runtime;

namespace {
std::uint32_t sfera_sound_decode_callback(CSoundStream* sound_stream, void* state) noexcept {
    auto* playback = static_cast<SferaSoundPlaybackState*>(state);
    if (playback == nullptr) return 0u;

    const auto event = playback->nextEvent();
    if (event.type == SoundEventType::end) {
        if (sound_stream != nullptr) sound_stream->Stop();
        playback->finished = true;
        playback->playing = false;
        return 0u;
    }

    if (playback->force_stop) {
        playback->queueEvent(event, -1.0f);
        if (sound_stream != nullptr) {
            sound_stream->decode_event_position = UINT32_MAX;
            sound_stream->SetPlaySignal(playback->play_signal - 1.0f);
        }
        return 1u;
    }

    if (event.type == SoundEventType::seek && event.argument != 0u) {
        if (sound_stream != nullptr && event.argument <= playback->timings.size()) {
            const auto& timing = playback->timings[event.argument - 1u];
            playback->queueEvent(event, timing.signal);
            sound_stream->SeekToTime(timing.seek_time);
            sound_stream->SetDecodeSignal(timing.signal);
        }
        return 1u;
    }

    if (event.type == SoundEventType::stop ||
        (event.type == SoundEventType::wait && event.argument != 0u)) {
        playback->queueEvent(event, -1.0f);
        if (sound_stream != nullptr) sound_stream->decode_event_position = UINT32_MAX;
    }
    return 1u;
}

std::uint32_t sfera_sound_play_callback(CSoundStream* sound_stream, void* state) noexcept {
    auto* playback = static_cast<SferaSoundPlaybackState*>(state);
    if (playback == nullptr) return 0u;

    const auto queued = playback->popEvent();
    if (!queued.has_value()) {
        if (sound_stream != nullptr) sound_stream->play_event_position = UINT32_MAX;
        return 1u;
    }

    const auto& event = *queued;
    if (event.signal != -1.0f) {
        playback->play_signal = event.signal;
        if (sound_stream != nullptr) sound_stream->SetPlaySignal(event.signal);
    } else if (sound_stream != nullptr) {
        sound_stream->play_event_position = UINT32_MAX;
    }

    if (event.type == SoundEventType::wait && !playback->force_stop) {
        if (sound_stream != nullptr) sound_stream->Stop();
        playback->wait_seconds = event.argument;
        playback->wait_started_at = UINT64_MAX;
        playback->playing = false;
        return 1u;
    }

    if (event.type == SoundEventType::stop || playback->force_stop) {
        if (sound_stream != nullptr) sound_stream->Stop();
        playback->finished = true;
        playback->playing = false;
    }
    return 1u;
}


    std::uint64_t sound_clock_ticks() {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() / 100;
    }
    float sound_elapsed(std::uint64_t start) {
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
            sound->playback_finished = !playing;
            if (playing || !sound->cache_available) {
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
            if (!sound->playback_finished && sound->IsSoundPlaying() != 0) sound->CSound::Stop();
            sound->cache_available = true;
        }
        effect.active_sound = nullptr;
        service_semantic_sound_cache();
    }
    bool play_sound(CSound& sound, int looped, float position) {
        sound.SetPlayTimepos(position);
        if (sound.CSound::Play(looped) == 0) return false;
        sound.cache_idle_since = UINT64_MAX;
        sound.playback_finished = false;
        return true;
    }
    CSound* find_cached_sound(const char* filename) {
        if (filename == nullptr) return nullptr;
        service_semantic_sound_cache();
        for (auto& entry : semantic_sound_cache()) {
            CSound* sound = entry.sound;
            if (sound == nullptr || sound->IsSoundPlaying() != 0 || !sound->cache_available) continue;
            const char* name = sound->filename;
            if (name != nullptr && SferaSimpleParser::equalsIgnoreCase(filename, name)) {
                entry.idle_started = false;
                return sound;
            }
        }
        return nullptr;
    }
    CSound* create_cached_sound(CSoundManager& manager, const char* filename, const SferaSound3DParameters* parameters, std::int32_t cache_lifetime) {
        if (!manager.enabled || filename == nullptr) return nullptr;
        CSound* sound = find_cached_sound(filename);
        if (sound == nullptr) {
            FILE* file = nullptr;
            if (fopen_s(&file, filename, "rb") != 0 || file == nullptr) return nullptr;
            std::fclose(file);
            void* memory = std::calloc(1u, sizeof(CSound));
            if (memory == nullptr) return nullptr;
            sound = ::new (memory) CSound();
            sound->cache_idle_since = UINT64_MAX;
            sound->cache_lifetime_seconds = 0u;
            sound->cache_available = true;
            sound->playback_finished = true;
            sound->cache_next = nullptr;
            sound->cache_previous = nullptr;
            const std::uint32_t load_flags = parameters == nullptr
                ? (1u << 3u)
                : ((1u << 0u) | (1u << 3u) | (1u << 5u));
            if (sound->LoadSound(filename, load_flags) == 0) {
                destroy_semantic_sound(sound);
                return nullptr;
            }
            semantic_sound_cache().push_back({sound, {}, false});
        }
        sound->cache_lifetime_seconds = cache_lifetime;
        sound->cache_available = true;
        if (parameters != nullptr) sound->SetAllParameters(parameters, 0);
        sound->SetVolume(manager.volume);
        return sound;
    }
    void release_sound_sources(CSoundEffect& effect) {
        if (effect.sources != nullptr) {
            auto* sources = effect.sources;
            for (std::size_t index = 0u; index < effect.source_count; ++index) std::free(sources[index].filename);
            std::free(sources);
        }
        effect.sources = nullptr;
        effect.source_count = 0u;
    }
    bool allocate_sound_sources(CSoundEffect& effect, std::size_t count) {
        release_sound_sources(effect);
        if (count == 0u) return true;
        auto* values = static_cast<SferaSoundSource*>(std::calloc(count, sizeof(SferaSoundSource)));
        if (values == nullptr) return false;
        effect.sources = values;
        effect.source_count = count;
        return true;
    }
    bool allocate_sound_time_groups(CSoundEffect& effect, std::size_t count) {
        std::free(effect.time_groups);
        effect.time_groups = nullptr;
        effect.time_group_count = 0u;
        if (count == 0u) return true;
        auto* values = static_cast<SferaSoundTimeGroup*>(std::calloc(count, sizeof(SferaSoundTimeGroup)));
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
    std::size_t choose_sound_source(CSoundEffect& effect) {
        if ((effect.flags & (1u << 6u)) != 0u && effect.time_groups != nullptr && effect.time_group_count != 0u) {
            auto* groups = effect.time_groups;
            std::size_t selected = effect.time_group_count;
            for (std::size_t index = 0u; index < effect.time_group_count; ++index) if (sound_time_matches(g_sfera_graphics_runtime.environment_factor, groups[index])) {
                selected = index;
                break;
            }
            if (selected == effect.time_group_count) return 0u;
            const auto& group = groups[selected];
            if ((effect.flags & ((1u << 2u) | (1u << 3u))) != 0u && group.source_end >= group.source_begin && group.source_end - group.source_begin + 1u > 1u) {
                std::size_t value = group.source_begin;
                do value = group.source_begin + static_cast<std::size_t>(std::rand()) % (group.source_end - group.source_begin + 1u);
                while (effect.last_source_index == value);
                return value;
            }
            return group.source_begin;
        }
        if ((effect.flags & ((1u << 2u) | (1u << 3u))) != 0u && effect.source_count > 1u) {
            std::size_t value = 0u;
            do value = static_cast<std::size_t>(std::rand()) % effect.source_count;
            while (effect.last_source_index == value);
            return value;
        }
        return 0u;
    }
    bool sound_distance_gate(CSoundEffect& effect, const SferaEffectVec3F* frame, float distance) {
        if ((effect.flags & (1u << 0u)) != 0u) return true;
        if (distance > effect.sound_parameters.max_distance) {
            if (!effect.distance_paused) {
                if (effect.active_sound != nullptr) {
                    auto* sound = effect.active_sound;
                    if ((effect.flags & ((1u << 2u) | (1u << 3u) | (1u << 4u))) == 0u) effect.saved_play_time = sound->GetPlayTimepos();
                    release_active_sound(effect);
                }
                effect.silence_active = false;
                effect.distance_paused = true;
                effect.transition_started_at = sound_clock_ticks();
            }
            return false;
        }
        if (!effect.distance_paused) return true;
        const float elapsed = sound_elapsed(effect.transition_started_at);
        if ((effect.flags & ((1u << 2u) | (1u << 3u) | (1u << 4u))) == 0u && effect.active_sound != nullptr) {
            auto* sound = effect.active_sound;
            const float resume = effect.saved_play_time + elapsed;
            const float length = sound->duration_seconds;
            if (resume > length) {
                release_active_sound(effect);
                effect.distance_paused = false;
                return true;
            }
            play_sound(*sound, 0, resume);
            effect.distance_paused = false;
            return true;
        }
        effect.distance_paused = false;
        effect.start(frame, false);
        return true;
    }
    CSoundEffect* find_sound_definition(std::uint32_t effect_id) {
        auto* registry = g_sfera_sound_runtime.effect_manager;
        return registry == nullptr ? nullptr : registry->find(effect_id);
    }
    bool grow_sound_effect_pool() {
        auto& pool = g_sfera_sound_effect_items;
        if (!pool.grow(sizeof(CSoundEffect))) return false;
        auto* objects = static_cast<CSoundEffect*>(pool.block_vector_end[-1]);
        for (std::size_t index = 0; index < pool.growth_count; ++index) std::construct_at(&objects[index])->initialize();
        return true;
    }
}
void CSoundEffect::initialize() {
    *this = {};
    mix_duration = 1.0f;
    cache_lifetime = 4;
    shared_definition = false;
    sound_parameters.inside_cone_angle = 360u;
    sound_parameters.outside_cone_angle = 360u;
    sound_parameters.cone_orientation = {0.0f, 0.0f, -1.0f};
    sound_parameters.min_distance = 1.0f;
    sound_parameters.max_distance = 1000000000.0f;
}
bool CSoundEffect::loadDefinition(SferaSimpleParser& parser, const SferaParserRange& range) {
    flags = 0u;
    if (parser.findValue("eff_number", &range)) effect_number = parser.readInt(0u);
    SferaParserRange block{};
    char text[1024]{};
    if (parser.findBlock("audio_files", &block, &range, 1)) {
        parser.setScanRange(&block);
        std::size_t source_lines = 0u;
        while (parser.nextValue("source")) ++source_lines;
        if (source_lines == 0u || !allocate_sound_sources(*this, source_lines)) {
            parser.clearScanRange();
            return false;
        }
        parser.setScanRange(&block);
        while (parser.nextValue("source")) {
            const std::int32_t index = parser.readInt(0u);
            if (index < 0 || std::cmp_greater_equal(index, source_count)) {
                parser.clearScanRange();
                return false;
            }
            auto& source = sources[index];
            if (parser.readQuotedString(1u, text) == nullptr) {
                parser.clearScanRange();
                return false;
            }
            if (SferaSimpleParser::equalsIgnoreCase(text, "silence")) {
                source.silence = true;
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
        std::size_t count = 0u;
        while (parser.nextValue("time")) ++count;
        if (!allocate_sound_time_groups(*this, count)) {
            parser.clearScanRange();
            return false;
        }
        parser.setScanRange(&block);
        std::size_t index = 0u;
        while (parser.nextValue("time") && index < count) {
            float begin = parser.readFloat(0u);
            float end = parser.readFloat(1u);
            std::int32_t source_begin = parser.readInt(2u);
            std::int32_t source_end = parser.readInt(3u);
            if (source_begin < 0 || source_end < 0 || std::cmp_greater_equal(source_begin, source_count) || std::cmp_greater_equal(source_end, source_count)) {
                parser.clearScanRange();
                return false;
            }
            auto& group = time_groups[index++];
            group.begin = begin == 0.0f ? 1.0f : 1.0f - begin / 24.0f;
            group.end = end == 0.0f ? 1.0f : 1.0f - end / 24.0f;
            group.source_begin = std::min(source_begin, source_end);
            group.source_end = std::max(source_begin, source_end);
        }
        parser.clearScanRange();
    }
    if (parser.findValue("flags", &range)) {
        for (std::size_t index = 0u; index < parser.tokenCount(); index += 2u) {
            flags |= sound_flag(parser.readStringBounded(index, text, sizeof(text)));
        }
    }
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
    if (parser.findValue("cache_lifetime", &range)) cache_lifetime = std::min(parser.readInt(0u), 10);
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
    shared_definition = true;
}
void CSoundEffect::destroy() {
    if (!shared_definition) {
        release_sound_sources(*this);
        std::free(time_groups);
    }
    release_active_sound(*this);
    silence_active = false;
    distance_paused = false;
    sources = nullptr;
    source_count = 0u;
    time_groups = nullptr;
    time_group_count = 0u;
    shared_definition = false;
}
float CSoundEffect::startTime() const {
    return sound_parameters.max_distance;
}
void CSoundEffect::start(const SferaEffectVec3F* frame, bool after_start_time) {
    if (sources == nullptr || source_count == 0u || g_sfera_sound_runtime.sound_manager == nullptr) return;
    release_active_sound(*this);
    const auto index = std::min(choose_sound_source(*this), source_count - 1u);
    last_source_index = index;
    const auto& source = sources[index];
    if (source.silence) {
        silence_active = true;
        silence_duration = source.silence_duration;
        silence_started_at = sound_clock_ticks();
        return;
    }
    const char* filename = source.filename;
    auto* manager = g_sfera_sound_runtime.sound_manager;
    if (manager == nullptr || filename == nullptr) return;
    if ((flags & (1u << 5u)) != 0u) {
        auto random_component = [](float radius) {
            return static_cast<float>(std::rand() - std::rand()) * 3.0518509447574615e-05f * radius;
        };
        region_offset = {random_component(region_radius.x), random_component(region_radius.y), random_component(region_radius.z)};
    }
    if (frame != nullptr) {
        const auto& position = *frame;
        sound_parameters.position = {position.x - offset.x + region_offset.x, position.y - offset.y + region_offset.y, position.z - offset.z + region_offset.z};
        last_position = {sound_parameters.position.x, sound_parameters.position.y, sound_parameters.position.z};
    }
    if (after_start_time && (flags & ((1u << 2u) | (1u << 3u) | (1u << 4u))) != 0u) {
        distance_paused = true;
        transition_started_at = sound_clock_ticks();
        return;
    }
    auto* sound = create_cached_sound(*manager, filename, (flags & (1u << 0u)) != 0u ? nullptr : &sound_parameters, cache_lifetime);
    if (sound != nullptr) {
        active_sound = sound;
        sound->cache_available = false;
        if (!after_start_time) play_sound(*sound, static_cast<int>(flags & (1u << 4u)), 0.0f);
    }
    distance_paused = after_start_time ? 1u : 0u;
    if (after_start_time) transition_started_at = sound_clock_ticks();
}
void CSoundEffect::update(const SferaEffectVec3F* frame, float age) {
    service_semantic_sound_cache();
    if (!sound_distance_gate(*this, frame, age)) return;
    if (silence_active) {
        const float elapsed = sound_elapsed(silence_started_at);
        if (elapsed < 0.0f) {
            silence_active = false;
            return;
        }
        if ((flags & (1u << 3u)) != 0u && elapsed >= silence_duration - mix_duration) {
            silence_active = false;
            start(frame, false);
            return;
        }
        if (elapsed >= silence_duration) silence_active = false;
        return;
    }
    if (active_sound == nullptr) return;
    auto* sound = active_sound;
    if (sound == nullptr) {
        active_sound = nullptr;
        return;
    }
    if (sound->IsSoundPlaying() == 0 || sound->playback_finished) {
        sound->cache_available = true;
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
    const auto& position = *frame;
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
    silence_active = false;
    distance_paused = false;
}
bool CSoundEffect::isComplete() const {
    if (distance_paused || silence_active) return false;
    return active_sound == nullptr || active_sound->playback_finished;
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


SoundEffectRegistry::SoundEffectRegistry() {
    definitions.reserve(100);
}

SoundEffectRegistry::~SoundEffectRegistry() {
    clear();
}

void SoundEffectRegistry::clear() {
    for (auto* effect : definitions) {
        effect->destroy();
        delete effect;
    }
    definitions.clear();
}

CSoundEffect* SoundEffectRegistry::add() {
    auto effect = std::make_unique<CSoundEffect>();
    effect->initialize();
    definitions.push_back(effect.get());
    return effect.release();
}

CSoundEffect* SoundEffectRegistry::find(std::uint32_t id) const {
    const auto found = std::lower_bound(
        definitions.begin(),
        definitions.end(),
        id,
        [](const CSoundEffect* effect, std::uint32_t number) {
            return effect->effect_number < number;
        });
    return found != definitions.end() && (*found)->effect_number == id ? *found : nullptr;
}

bool SoundEffectRegistry::load() {
    WIN32_FIND_DATAA found{};
    HANDLE search = ::FindFirstFileA("Sounds\\*.def", &found);
    if (search != INVALID_HANDLE_VALUE) {
        do {
            if ((found.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0u) continue;

            SferaSimpleParser parser;
            parser.initialize();
            parser.load((std::string("Sounds\\") + found.cFileName).c_str());
            parser.setBlockRange(nullptr);

            SferaParserRange range{};
            while (parser.nextBlock("soundeffect", &range)) {
                SferaParserRange continuation{};
                parser.getBlockRange(&continuation);

                auto* effect = add();
                if (!effect->loadDefinition(parser, range)) {
                    definitions.pop_back();
                    effect->destroy();
                    delete effect;
                }
                parser.setBlockRange(&continuation);
            }
            parser.release();
        } while (::FindNextFileA(search, &found));
        ::FindClose(search);
    }

    std::sort(definitions.begin(), definitions.end(), [](const auto* first, const auto* second) {
        return first->effect_number < second->effect_number;
    });
    return true;
}

void SferaSoundRuntime::loadDefinitions() {
    if (effect_manager != nullptr) return;

    auto* registry = new SoundEffectRegistry;
    effect_manager = registry;
    registry->load();
}

void SferaSoundRuntime::clearDefinitions() {
    delete effect_manager;
    effect_manager = nullptr;
}

bool SferaSoundPlaybackState::queueEvent(
    SoundEventRecord event,
    float signal) noexcept {
    event.signal = signal;
    try {
        event_queue.push_back(event);
        return true;
    } catch (const std::bad_alloc&) {
        return false;
    }
}

std::optional<SoundEventRecord> SferaSoundPlaybackState::popEvent() noexcept {
    if (event_queue.empty()) return std::nullopt;

    const auto event = event_queue.front();
    event_queue.pop_front();
    return event;
}

SoundEventRecord SferaSoundPlaybackState::nextEvent() noexcept {
    for (;;) {
        auto* list = current_list;
        if (list == nullptr || list->group_index >= list->groups.size() ||
            list->item_index >= list->groups[list->group_index].size()) {
            return {};
        }

        const auto& events = list->groups[list->group_index];
        const auto event = events[list->item_index++];
        if (event.type != SoundEventType::playlist) return event;
        if (event.argument == 0u || event.argument > playlists.size()) {
            return {SoundEventType::none};
        }

        current_list = &playlists[event.argument - 1u];
        if (current_list->groups.empty()) return {};
        current_list->item_index = 0u;
        current_list->group_index = static_cast<std::size_t>(std::rand()) % current_list->groups.size();
    }
}

void SferaSoundEventList::parseGroup(std::size_t group, const char* text) {
    if (text == nullptr || *text == '\0') return;

    const std::string_view line(text);
    auto& events = groups.at(group);
    events.assign(std::count(line.begin(), line.end(), ',') + 1u, SoundEventRecord{});

    std::size_t begin = 0u;
    for (std::size_t index = 0u; index < events.size(); ++index) {
        const auto end = line.find(',', begin);
        const auto length = end == std::string_view::npos ? std::string_view::npos : end - begin;
        const std::string token(line.substr(begin, length));

        SoundEventRecord event;
        if (SferaSimpleParser::equalsIgnoreCase(token.c_str(), "STP")) {
            event.type = SoundEventType::stop;
        } else if (!token.empty()) {
            auto digits = std::string_view(token).substr(1u);
            while (!digits.empty() && std::isspace(static_cast<unsigned char>(digits.front()))) {
                digits.remove_prefix(1u);
            }
            if (!digits.empty() && digits.front() == '+') digits.remove_prefix(1u);

            std::size_t argument = 0u;
            const auto result = std::from_chars(digits.data(), digits.data() + digits.size(), argument);
            if (result.ec == std::errc{}) {
                event.argument = argument;
                switch (token[0]) {
                case 'p': event.type = SoundEventType::seek; break;
                case 's': event.type = SoundEventType::wait; break;
                case 'j': event.type = SoundEventType::playlist; break;
                default: break;
                }
            }
        }

        events[index] = event;
        begin = end == std::string_view::npos ? line.size() : end + 1u;
    }
}

SferaSoundPlaybackState::SferaSoundPlaybackState()
    : playing(false),
      wait_seconds(0u),
      wait_started_at(UINT64_MAX),
      play_signal(0.0f),
      current_list(nullptr),
      playlist_index(0u),
      stream(nullptr),
      source(nullptr),
      finished(false),
      stopped(true),
      volume_scale(1),
      force_stop(false) {}

SferaSoundPlaybackState::~SferaSoundPlaybackState() {
    clear();
}

float SferaSoundPlaybackState::parseTime(const char* text) {
    if (text == nullptr) return 0.0f;

    const std::string_view token(text);
    const auto colon = token.find(':');
    const auto prefix_size = std::min<std::size_t>(
        15u,
        colon == std::string_view::npos ? token.size() : colon);
    if (prefix_size >= token.size()) return 0.0f;

    const auto minutes = std::atoi(std::string(token.substr(0u, prefix_size)).c_str());
    const auto seconds = std::atof(text + prefix_size + 1u);
    return static_cast<float>(minutes * 60.0 + seconds);
}

bool SferaSoundPlaybackState::load(const char* filename) {
    SferaSimpleParser parser;
    parser.initialize();
    struct ParserRelease {
        SferaSimpleParser& parser;
        ~ParserRelease() { parser.release(); }
    } release{parser};

    parser.load(filename);
    SferaParserRange track{};
    SferaParserRange block{};
    char text[1024]{};
    if (!parser.findBlock("soundtrack", &track, nullptr, 1) ||
        !parser.findValue("audio_file", &track) ||
        parser.readQuotedString(0u, text) == nullptr) {
        return false;
    }

    auto* filename_copy = new char[std::strlen(text) + 1u];
    std::copy_n(text, std::strlen(text) + 1u, filename_copy);
    delete[] source;
    source = filename_copy;

    if (parser.findValue("volume", &track)) {
        volume_scale = static_cast<int>(std::trunc(parser.readFloat(0u)));
    }

    auto count_records = [&](const char* name) {
        parser.setScanRange(&block);
        std::size_t count = 0u;
        while (parser.nextValue(name)) ++count;
        return count;
    };

    if (!parser.findBlock("samples", &block, &track, 1)) return false;
    const auto sample_count = count_records("sample");
    if (sample_count == 0u) return false;

    timings.assign(sample_count, {});
    parser.setScanRange(&block);
    while (parser.nextValue("sample")) {
        const auto index = parser.readInt(0u);
        if (index <= 0 || std::cmp_greater(index, timings.size())) return false;

        char start[128]{};
        char end[128]{};
        parser.readString(1u, start);
        parser.readString(2u, end);
        timings[static_cast<std::size_t>(index - 1)] = {parseTime(start), parseTime(end)};
    }
    parser.clearScanRange();

    if (!parser.findBlock("patterns", &block, &track, 1)) return false;
    const auto pattern_count = count_records("pattern");
    if (pattern_count == 0u) return false;

    current_list = nullptr;
    playlists.assign(pattern_count, {});
    parser.setScanRange(&block);
    while (parser.nextValue("pattern")) {
        const auto token_count = parser.tokenCount();
        if (token_count == 0u) continue;

        const auto index = parser.readInt(0u);
        if (index <= 0 || std::cmp_greater(index, playlists.size())) return false;

        auto& pattern = playlists[static_cast<std::size_t>(index - 1)];
        pattern.groups.resize(token_count > 2u ? (token_count - 1u) / 2u + 1u : 1u);

        std::size_t group = 0u;
        for (std::size_t token = 1u; token < token_count; token += 2u) {
            if (parser.readString(token, text) != nullptr) pattern.parseGroup(group++, text);
        }
    }
    parser.clearScanRange();

    const int starting_pattern = parser.findValue("start_pattern", &block) ? parser.readInt(0u) : 1;
    if (starting_pattern <= 0 || std::cmp_greater(starting_pattern, playlists.size())) return false;
    playlist_index = static_cast<std::size_t>(starting_pattern - 1);
    return true;
}

bool SferaSoundPlaybackState::start() {
    if (source == nullptr || playlist_index >= playlists.size() ||
        playlists[playlist_index].groups.empty()) {
        current_list = nullptr;
        return false;
    }

    current_list = nullptr;
    if (stream == nullptr) stream = SI_StreamCreateFile(source, 1u);
    if (stream == nullptr) return false;

    stream->decode_callback = &sfera_sound_decode_callback;
    stream->decode_state = this;
    stream->play_callback = &sfera_sound_play_callback;
    stream->play_state = this;
    stream->stream_gain = static_cast<float>(volume_scale);

    playing = false;
    finished = false;
    force_stop = false;
    current_list = &playlists[playlist_index];
    current_list->item_index = 0u;
    current_list->group_index = static_cast<std::size_t>(std::rand()) % current_list->groups.size();
    event_queue.clear();
    stopped = false;
    return true;
}

void SferaSoundPlaybackState::stop() {
    if (stream != nullptr) {
        if (stream->IsStreamPlaying()) stream->Stop();
        stream->decode_event_position = UINT32_MAX;
        stream->play_event_position = UINT32_MAX;
    }
    stopped = true;
    playing = false;
}

void SferaSoundPlaybackState::clear() {
    if (stream != nullptr) SI_StreamFree(stream);
    stream = nullptr;

    delete[] source;
    source = nullptr;
    current_list = nullptr;
    playlists.clear();
    timings.clear();
    event_queue.clear();
    finished = false;
    playing = false;
    wait_seconds = 0u;
    wait_started_at = UINT64_MAX;
    stopped = true;
    playlist_index = 0u;
    force_stop = false;
}

void SferaSoundPlaybackState::update() {
    if (playing || stream == nullptr || stream->decoder_state != 0u || stopped) return;
    if (finished || force_stop) {
        stop();
        return;
    }

    if (wait_seconds != 0u) {
        const auto now = WorldClock::nowTicks();
        if (wait_started_at == UINT64_MAX) {
            wait_started_at = now;
            return;
        }
        if (now >= wait_started_at && (now - wait_started_at) / 10000u >= wait_seconds) {
            wait_seconds = 0u;
            wait_started_at = UINT64_MAX;
        }
        return;
    }

    const auto event = nextEvent();
    if (event.type == SoundEventType::end) {
        stop();
        return;
    }

    if (event.type == SoundEventType::seek && event.argument > 0u && event.argument <= timings.size()) {
        if (stream->IsStreamPlaying()) stream->Stop();
        const auto& timing = timings[event.argument - 1u];
        play_signal = timing.signal;
        stream->SetDecodeSignal(timing.signal);
        stream->SetPlaySignal(play_signal);
        if (stream->PlayEx(timing.seek_time, 0) != 0) playing = true;
        return;
    }

    if (event.type == SoundEventType::wait) {
        if (stream->IsStreamPlaying()) stream->Stop();
        stream->decode_event_position = UINT32_MAX;
        stream->play_event_position = UINT32_MAX;
        wait_seconds = event.argument;
        wait_started_at = UINT64_MAX;
        return;
    }

    if (event.type == SoundEventType::stop) stop();
}

SferaSoundPlaybackState* SferaSoundRuntime::loadTrack(const char* filename) {
    if (!interfaceAvailable()) return nullptr;

    auto track = std::make_unique<SferaSoundPlaybackState>();
    if (!track->load(filename)) return nullptr;

    auto* result = track.get();
    tracks.push_back(std::move(track));
    return result;
}

bool SferaSoundRuntime::deleteTrack(SferaSoundPlaybackState* track) {
    if (track == nullptr) return false;
    if (!track->stopped) track->stop();

    const auto found = std::find_if(tracks.begin(), tracks.end(), [track](const auto& item) {
        return item.get() == track;
    });
    if (found == tracks.end()) return false;

    tracks.erase(found);
    return true;
}

void SferaSoundRuntime::clearTracks() {
    for (auto& track : tracks) {
        if (!track->stopped) track->stop();
    }
    tracks.clear();
    current_track = nullptr;
}

bool SferaSoundRuntime::updateTracks() {
    if (!interfaceAvailable()) return false;

    for (auto& track : tracks) track->update();

    auto* current = current_track;
    if (current == nullptr || !current->stopped) return true;

    deleteTrack(current);
    current_track = nullptr;
    if (requested_track[0] == '\0') return true;

    current = loadTrack(requested_track.data());
    current_track = current;
    if (current != nullptr) current->start();
    requested_track[0] = '\0';
    return true;
}

void SferaSoundRuntime::requestTrack(const char* filename) {
    auto* current = current_track;
    if (filename == nullptr) {
        requested_track[0] = '\0';
        if (current != nullptr && !current->stopped) current->force_stop = true;
        return;
    }

    const std::string path = std::string("Sounds\\Music\\") + filename + ".sst";
    const auto length = std::min(path.size(), requested_track.size() - 1u);
    std::copy_n(path.data(), length, requested_track.data());
    requested_track[length] = '\0';

    if (current != nullptr && !current->stopped) {
        current->force_stop = true;
        return;
    }

    current = loadTrack(requested_track.data());
    current_track = current;
    if (current != nullptr) current->start();
}

void CSoundManager::detach(CSound& sound) {
    if (count != 0u) --count;

    if (sound.cache_previous == nullptr && sound.cache_next == nullptr) {
        first = nullptr;
        last = nullptr;
        return;
    }

    if (last == &sound) {
        last = sound.cache_previous;
        if (last != nullptr) last->cache_next = nullptr;
    } else if (first == &sound) {
        first = sound.cache_next;
        if (first != nullptr) first->cache_previous = nullptr;
    } else {
        sound.cache_previous->cache_next = sound.cache_next;
        sound.cache_next->cache_previous = sound.cache_previous;
    }
    sound.cache_next = nullptr;
    sound.cache_previous = nullptr;
}

void CSoundManager::setVolume(std::int32_t percent) {
    volume = static_cast<float>(std::clamp(percent, 0, 100)) * 0.01f;
    for (auto* sound = first; sound != nullptr; sound = sound->cache_next) {
        sound->SetVolume(volume);
    }
    for (auto& entry : semantic_sound_cache()) {
        if (entry.sound != nullptr) entry.sound->SetVolume(volume);
    }
}

void CSoundManager::update() {
    for (auto* sound = first; sound != nullptr;) {
        auto* next = sound->cache_next;
        if (sound->IsSoundPlaying() == 0) sound->playback_finished = true;

        if (sound->playback_finished && sound->cache_available &&
            sound->cache_lifetime_seconds >= 0) {
            bool expired = sound->cache_lifetime_seconds == 0;
            if (!expired) {
                const auto now = WorldClock::nowTicks();
                if (sound->cache_idle_since == UINT64_MAX) {
                    sound->cache_idle_since = now;
                } else {
                    expired = (now - sound->cache_idle_since) / 10000u >=
                        static_cast<std::uint64_t>(sound->cache_lifetime_seconds);
                }
            }

            if (expired) {
                detach(*sound);
                sound->~CSound();
                WorldMemory::release(sound);
            }
        }
        sound = next;
    }

    service_semantic_sound_cache();
    if (auto* sound_interface = SI_GetInterface()) sound_interface->UpdateSettings();
}

void CSoundManager::clear() {
    for (auto* sound = first; sound != nullptr;) {
        auto* next = sound->cache_next;
        sound->~CSound();
        WorldMemory::release(sound);
        sound = next;
    }
    first = nullptr;
    last = nullptr;
    count = 0u;

    for (auto& entry : semantic_sound_cache()) destroy_semantic_sound(entry.sound);
    semantic_sound_cache().clear();
}

bool SferaSoundRuntime::initialize() {
    SI_SetLogFile(nullptr);
    if (SI_CreateInterface(g_sfera_window_runtime.main_window_handle, -1, 44100u, 0u) == nullptr) {
        return false;
    }

    auto* active_manager = ensureManager();
    if (active_manager != nullptr) {
        active_manager->enabled = interfaceAvailable();
        if (!active_manager->enabled) {
            for (auto* sound = active_manager->first; sound != nullptr; sound = sound->cache_next) {
                sound->Stop();
            }
            active_manager->clear();
        }
    }

    SphereUI::InterfaceConfiguration::open("config.cfg");
    const int sound_volume = SphereUI::InterfaceConfiguration::readInteger("SNDVOL", 100);
    const int music_volume = SphereUI::InterfaceConfiguration::readInteger("MUSVOL", 100);
    const int hardware_mixing = SphereUI::InterfaceConfiguration::readInteger("HWMIX", 0);

    SI_SetHardwareMixing(hardware_mixing != 0);
    loadDefinitions();
    SI_SetStreamVolume(music_volume);
    if (active_manager != nullptr) active_manager->setVolume(sound_volume);
    return true;
}

CSoundManager* SferaSoundRuntime::ensureManager() {
    if (sound_manager != nullptr) return sound_manager;
    if (!interfaceAvailable()) return nullptr;

    void* storage = WorldMemory::allocate(sizeof(CSoundManager));
    if (storage == nullptr) return nullptr;
    sound_manager = ::new (storage) CSoundManager{nullptr, nullptr, 1.0f, false, 0u};
    return sound_manager;
}

void SferaSoundRuntime::update() {
    auto* sound_interface = SI_GetInterface();
    if (sound_interface == nullptr || sound_interface->listener == nullptr) return;

    auto* listener = sound_interface->listener;
    g_sfera_world_objects.recalculateBasis(1u);
    const auto* camera = static_cast<const ExtendedWorldObject*>(g_sfera_world_objects.object(1u));
    if (camera == nullptr) return;

    const SferaVec3F position = camera->position;
    const SferaVec3F velocity{
        position.x - listener->position.x,
        position.y - listener->position.y,
        position.z - listener->position.z};

    SferaSoundVec3 forward{};
    SferaSoundVec3 up{};
    listener->GetOrientation(&forward, &up);
    const SferaSoundVec3 next_forward{
        camera->orientation_basis[0].x,
        camera->orientation_basis[0].y,
        camera->orientation_basis[0].z};
    const SferaSoundVec3 next_up{
        -camera->orientation_basis[1].x,
        -camera->orientation_basis[1].y,
        -camera->orientation_basis[1].z};

    if (velocity.x != 0.0f || velocity.y != 0.0f || velocity.z != 0.0f) {
        listener->SetPosition(position.x, position.y, position.z, 0);
        listener->SetVelocity(velocity.x, velocity.y, velocity.z, 0);
    }
    if (std::memcmp(&forward, &next_forward, sizeof(forward)) != 0 ||
        std::memcmp(&up, &next_up, sizeof(up)) != 0) {
        listener->SetOrientation(next_forward, next_up, 0);
    }

    updateTracks();
    if (sound_manager != nullptr) sound_manager->update();
}

void SferaSoundRuntime::shutdown() {
    clearDefinitions();
    if (sound_manager != nullptr) {
        sound_manager->clear();
        sound_manager->~CSoundManager();
        WorldMemory::release(sound_manager);
        sound_manager = nullptr;
    }
    clearTracks();
    SI_Close();
}

std::uint32_t SferaSoundRuntime::soundVolume() const {
    const auto* manager = sound_manager;
    if (manager == nullptr) return 0u;
    return static_cast<std::uint32_t>(
        std::clamp(static_cast<int>(std::lround(manager->volume * 100.0f)), 0, 100));
}

int SferaSoundRuntime::musicVolume() const {
    return SI_GetStreamVolume();
}

bool SferaSoundRuntime::hardwareMixing() const {
    return SI_GetHardwareMixing();
}

void SferaSoundRuntime::setSoundVolume(std::uint32_t value) {
    if (sound_manager != nullptr) sound_manager->setVolume(static_cast<std::int32_t>(std::min(value, 100u)));
}

void SferaSoundRuntime::setMusicVolume(std::uint32_t value) {
    SI_SetStreamVolume(static_cast<int>(std::min(value, 100u)));
}

void SferaSoundRuntime::adjustMusicVolume(int delta) {
    SI_SetStreamVolume(SI_GetStreamVolume() + delta);
}

void SferaSoundRuntime::refreshMusicVolume() {
    SI_SetStreamVolume(SI_GetStreamVolume());
}

void SferaSoundRuntime::setHardwareMixing(bool enabled) {
    SI_SetHardwareMixing(enabled);
}

void SferaSoundRuntime::playUiSound(const char* filename) {
    auto* manager = sound_manager;
    if (!g_sfera_interface_runtime.sounds_enabled || filename == nullptr || SI_GetInterface() == nullptr || manager == nullptr || !manager->enabled) return;

    CSound* sound = nullptr;
    for (auto* candidate = manager->first; candidate != nullptr; candidate = candidate->cache_next) {
        if (candidate->filename != nullptr && SferaSimpleParser::equalsIgnoreCase(candidate->filename, filename) && candidate->IsSoundPlaying() == 0) {
            if (candidate->cache_available) sound = candidate;
            break;
        }
    }

    if (sound == nullptr) {
        void* storage = WorldMemory::allocate(sizeof(CSound));
        if (storage == nullptr) return;
        try {
            sound = ::new (storage) CSound();
            sound->cache_idle_since = UINT64_MAX;
            sound->cache_lifetime_seconds = 0;
            sound->cache_next = nullptr;
            sound->cache_previous = nullptr;
            sound->cache_available = true;
            sound->playback_finished = true;
            if (sound->LoadSound(filename, 8u) == 0) {
                sound->~CSound();
                WorldMemory::release(sound);
                return;
            }
        } catch (...) {
            WorldMemory::release(storage);
            throw;
        }
        sound->cache_previous = manager->last;
        if (manager->last != nullptr) manager->last->cache_next = sound;
        else manager->first = sound;
        manager->last = sound;
        ++manager->count;
    }

    sound->cache_lifetime_seconds = 4;
    sound->SetVolume(manager->volume);
    sound->SetPlayTimepos(0.0f);
    if (sound->Play(0) != 0) {
        sound->cache_idle_since = UINT64_MAX;
        sound->playback_finished = false;
    }
}
