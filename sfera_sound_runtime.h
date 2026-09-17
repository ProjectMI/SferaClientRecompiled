#pragma once

#include "sfera_sound.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <limits>
#include <list>
#include <memory>
#include <optional>
#include <vector>

class CSound;
class CSoundStream;

struct SferaSoundSource {
    char* filename = nullptr;
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
    std::uint32_t effect_number;
    std::uint32_t flags;
    bool silence_active;
    std::uint64_t silence_started_at;
    float silence_duration;
    float saved_play_time;
    std::uint64_t transition_started_at;
    SferaSoundSource* sources;
    std::size_t source_count;
    SferaSoundTimeGroup* time_groups;
    std::size_t time_group_count;
    bool distance_paused;
    SferaEffectVec3F offset;
    SferaEffectVec3F region_radius;
    SferaEffectVec3F region_offset;
    float mix_duration;
    std::optional<std::size_t> last_source_index;
    CSound* active_sound;
    std::int32_t cache_lifetime;
    bool shared_definition;
    SferaSound3DParameters sound_parameters;
    SferaEffectVec3F last_position;

    void initialize();
    bool loadDefinition(SferaSimpleParser& parser, const SferaParserRange& range);
    CSoundEffect* clone() const;
    void resetFrom(const CSoundEffect& source);
    void destroy();
    float startTime() const;
    void start(const SferaEffectVec3F* frame, bool after_start_time);
    void update(const SferaEffectVec3F* frame, float age);
    void stop();
    bool isComplete() const;
};

class CSoundManager {
public:
    void detach(CSound& sound);
    void setVolume(std::int32_t percent);
    void update();
    void clear();

    CSound* first;
    CSound* last;
    float volume;
    bool enabled;
    std::size_t count;
};

class SoundEffectRegistry {
public:
    std::vector<CSoundEffect*> definitions;

    SoundEffectRegistry();
    ~SoundEffectRegistry();
    CSoundEffect* add();
    CSoundEffect* find(std::uint32_t id) const;
    bool load();
    void clear();
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
    char* source;
    bool finished;
    bool stopped;
    int volume_scale;
    bool force_stop;
};

struct SferaSoundRuntime {
    SoundEffectRegistry* effect_manager = nullptr;
    CSoundManager* sound_manager = nullptr;
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
    CSoundEffect* createEffect(std::uint32_t effect_id);
    void destroyEffect(CSoundEffect* effect);
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
