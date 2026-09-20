#pragma once

#include "sfera_sound.h"

#include <array>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <limits>
#include <list>
#include <memory>
#include <optional>
#include <vector>
#include <string>

class CSound;
class CSoundStream;

struct SferaSoundSource {
    std::string filename;
    bool silence = false;
    float silence_duration = 0.0f;
};

struct SferaSoundTimeGroup {
    float begin = 0.0f;
    float end = 0.0f;
    std::size_t source_begin = 0u;
    std::size_t source_end = 0u;
};

class CSoundEffect {
public:
    struct Definition {
        std::vector<SferaSoundSource> sources;
        std::vector<SferaSoundTimeGroup> time_groups;
        std::uint32_t effect_number{}, flags{};
        SferaVec3F offset{}, region_radius{};
        float mix_duration = 1.0f;
        int cache_lifetime = 4;
        SferaSound3DParameters parameters{};
    };
    std::shared_ptr<const Definition> definition;
    bool silence_active = false, distance_paused = false;
    std::uint64_t silence_started_at{}, transition_started_at{};
    float silence_duration{}, saved_play_time{};
    SferaVec3F region_offset{}, last_position{};
    std::optional<std::size_t> last_source_index;
    std::shared_ptr<CSound> active_sound;
    SferaSound3DParameters sound_parameters{};

    static std::shared_ptr<const Definition> loadDefinition(SferaSimpleParser& parser, const SferaParserRange& range);
    explicit CSoundEffect(std::shared_ptr<const Definition> source);
    ~CSoundEffect();
    CSoundEffect(const CSoundEffect&) = delete;
    CSoundEffect& operator=(const CSoundEffect&) = delete;
    void reset();
    float startTime() const;
    void start(const SferaVec3F* frame, bool after_start_time);
    void update(const SferaVec3F* frame, float age);
    void stop();
    bool isComplete() const;
};

class CSoundManager {
public:
    struct CachedSound {
        std::shared_ptr<CSound> sound;
        std::chrono::steady_clock::time_point idle_since{};
        bool idle_started = false;
    };
    void setVolume(int percent);
    void update();
    void clear();

    std::vector<std::unique_ptr<CSound>> sounds;
    std::vector<CachedSound> cache;
    float volume = 1.0f;
    bool enabled = false;
};

class SoundEffectRegistry {
public:
    std::shared_ptr<const CSoundEffect::Definition> find(std::uint32_t id) const;
    bool load();
private:
    std::vector<std::shared_ptr<const CSoundEffect::Definition>> definitions;
};

enum class SoundEventType : std::uint8_t { none, seek, wait, stop, playlist, end };

struct SoundEventRecord {
    SoundEventType type = SoundEventType::end;
    std::size_t argument = 0u;
    float signal = -1.0f;
};

struct SferaSoundTiming {
    float seek_time = 0.0f;
    float signal = 0.0f;
};

struct SferaSoundEventList {
    void parseGroup(std::size_t group, const char* text);
    std::vector<std::vector<SoundEventRecord>> groups;
    std::size_t item_index = 0u;
    std::size_t group_index = 0u;
};

struct SferaSoundPlaybackState {
    SferaSoundPlaybackState();
    ~SferaSoundPlaybackState();

    static float parseTime(const char* text);
    bool load(const char* filename);
    bool start();
    void stop();
    void clear();
    void update();
    SoundEventRecord nextEvent() noexcept;
    bool queueEvent(SoundEventRecord event, float signal) noexcept;
    std::optional<SoundEventRecord> popEvent() noexcept;

    std::deque<SoundEventRecord> event_queue;
    std::vector<SferaSoundTiming> timings;
    bool playing;
    std::size_t wait_seconds;
    std::uint64_t wait_started_at;
    float play_signal;
    std::vector<SferaSoundEventList> playlists;
    SferaSoundEventList* current_list;
    std::size_t playlist_index;
    CSoundStream* stream;
    std::string source;
    bool finished;
    bool stopped;
    int volume_scale;
    bool force_stop;
};

struct SferaSoundRuntime {
    std::unique_ptr<SoundEffectRegistry> effect_manager;
    std::unique_ptr<CSoundManager> sound_manager;
    std::list<std::unique_ptr<SferaSoundPlaybackState>> tracks;
    std::array<char, 512> requested_track{};
    SferaSoundPlaybackState* current_track = nullptr;

    SferaSoundPlaybackState* loadTrack(const char* filename);
    bool deleteTrack(SferaSoundPlaybackState* track);
    void clearTracks();
    bool updateTracks();
    void requestTrack(const char* filename);
    CSoundManager* ensureManager();
    bool initialize();
    void update();
    void shutdown();
    void loadDefinitions();
    void clearDefinitions();
    bool interfaceAvailable() const;
    std::unique_ptr<CSoundEffect> createEffect(std::uint32_t effect_id);
    std::uint32_t soundVolume() const;
    int musicVolume() const;
    bool hardwareMixing() const;
    void setSoundVolume(std::uint32_t value);
    void setMusicVolume(std::uint32_t value);
    void adjustMusicVolume(int delta);
    void refreshMusicVolume();
    void setHardwareMixing(bool enabled);
    void playUiSound(const char* filename);
};

extern SferaSoundRuntime g_sfera_sound_runtime;
