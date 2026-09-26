#pragma once

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <list>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include "audio/Sound.h"
#include "audio/SoundEffects.h"

struct SferaSoundEventList;
struct SferaSoundTiming;
struct SoundEventRecord;

enum class SoundEventType : std::uint8_t
{
    none,
    seek,
    wait,
    stop,
    playlist,
    end
};

struct SoundEventRecord
{
    SoundEventType type = SoundEventType::end;
    std::size_t argument = 0u;
    float signal = -1.0f;
};

struct SferaSoundTiming
{
    float seek_time = 0.0f;
    float signal = 0.0f;
};

struct SferaSoundEventList
{
    void parseGroup(std::size_t group, std::string_view text);
    std::vector<std::vector<SoundEventRecord>> groups;
    std::size_t item_index = 0u;
    std::size_t group_index = 0u;
};

class CSoundStream;
struct SferaParserRange;
class SferaSimpleParser;
struct SferaSoundPlaybackState;

struct SferaSoundPlaybackState
{
    SferaSoundPlaybackState();
    ~SferaSoundPlaybackState()
    {
        clear();
    }

    static float parseTime(std::string_view text);
    bool load(const std::string &filename);
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
    SferaSoundEventList *current_list;
    std::size_t playlist_index;
    CSoundStream *stream;
    std::string source;
    bool finished;
    bool stopped;
    float volume_scale;
    bool force_stop;

  private:
    static std::uint32_t sfera_sound_decode_callback(CSoundStream *sound_stream, void *context) noexcept;
    static std::uint32_t sfera_sound_play_callback(CSoundStream *sound_stream, void *context) noexcept;
    static std::size_t countRecords(SferaSimpleParser &parser, SferaParserRange &block, std::string_view name);
};

class CSoundManager;
struct CSoundManagerCachedSound;
class SferaSoundCacheHelper;

struct CSoundManagerCachedSound
{
    std::shared_ptr<CSound> sound;
    std::chrono::steady_clock::time_point idle_since{};
    bool idle_started = false;
};

class CSoundManager
{
  public:
    void setVolume(int percent);
    void update();
    void clear();

    std::vector<std::unique_ptr<CSound>> sounds;
    std::vector<CSoundManagerCachedSound> cache;
    float volume = 1.0f;
    bool enabled = false;

  private:
    static bool shouldEvict(const std::unique_ptr<CSound> &sound);
};

class SferaSoundCacheHelper
{
  public:
    static void service_semantic_sound_cache();
};

struct SferaSoundRuntime;

struct SferaSoundRuntime
{
    bool volume_refresh_active{};
    float volume_refresh_frames{};
    bool volume_refresh_direction{};

    std::unique_ptr<SoundEffectRegistry> effect_manager;
    std::unique_ptr<CSoundManager> sound_manager;
    std::list<std::unique_ptr<SferaSoundPlaybackState>> tracks;
    std::string requested_track;
    SferaSoundPlaybackState *current_track = nullptr;
    bool listener_position_initialized = false;

    SferaSoundPlaybackState *loadTrack(const std::string &filename);
    bool deleteTrack(SferaSoundPlaybackState *track);
    void clearTracks();
    bool updateTracks();
    void requestTrack(std::optional<std::string_view> filename);
    void requestTrack(std::nullptr_t) = delete;
    CSoundManager *ensureManager();
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
    void playUiSound(const std::string &filename);
};

extern SferaSoundRuntime g_sfera_sound_runtime;
