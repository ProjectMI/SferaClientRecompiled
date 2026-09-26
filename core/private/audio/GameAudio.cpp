#include <windows.h>
#include <algorithm>
#include <charconv>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <memory>
#include <new>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <utility>
#include <vector>

#include "application/ClientApplication.h"
#include "audio/GameAudio.h"
#include "audio/Sound.h"
#include "audio/SoundEffects.h"
#include "config/InterfaceConfiguration.h"
#include "config/SimpleParser.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "runtime/Clock.h"
#include "scene/SceneObject.h"
#include "text/Parsing.h"
#include "text/Text.h"
#include "ui/GameInterfaceManager.h"
#include "world/WorldObjects.h"

bool SferaSoundRuntime::interfaceAvailable() const
{
    return SI_GetInterface() != nullptr;
}

std::unique_ptr<CSoundEffect> SferaSoundRuntime::createEffect(std::uint32_t effect_id)
{
    auto definition = effect_manager == nullptr ? nullptr : effect_manager->find(effect_id);
    return definition == nullptr ? nullptr : std::make_unique<CSoundEffect>(std::move(definition));
}

void SferaSoundRuntime::loadDefinitions()
{
    if (effect_manager != nullptr)
        return;

    auto registry = std::make_unique<SoundEffectRegistry>();
    if (registry->load())
        effect_manager = std::move(registry);
}

void SferaSoundRuntime::clearDefinitions()
{
    effect_manager.reset();
}

SferaSoundPlaybackState *SferaSoundRuntime::loadTrack(const std::string &filename)
{
    if (!interfaceAvailable())
        return nullptr;

    auto track = std::make_unique<SferaSoundPlaybackState>();
    if (!track->load(filename))
        return nullptr;

    auto *result = track.get();
    tracks.push_back(std::move(track));
    return result;
}

bool SferaSoundRuntime::deleteTrack(SferaSoundPlaybackState *track)
{
    if (track == nullptr)
        return false;
    if (!track->stopped)
        track->stop();

    auto found = tracks.begin();
    while (found != tracks.end() && found->get() != track)
    {
        ++found;
    }
    if (found == tracks.end())
        return false;

    tracks.erase(found);
    return true;
}

void SferaSoundRuntime::clearTracks()
{
    for (auto &track : tracks)
    {
        if (!track->stopped)
            track->stop();
    }
    tracks.clear();
    current_track = nullptr;
}

bool SferaSoundRuntime::updateTracks()
{
    if (!interfaceAvailable())
        return false;

    for (auto &track : tracks)
        track->update();

    auto *current = current_track;
    if (current == nullptr || !current->stopped)
        return true;

    deleteTrack(current);
    current_track = nullptr;
    if (requested_track.empty())
        return true;

    current = loadTrack(requested_track);
    current_track = current;
    if (current != nullptr)
        current->start();
    requested_track.clear();
    return true;
}

void SferaSoundRuntime::requestTrack(std::optional<std::string_view> filename)
{
    auto *current = current_track;
    if (!filename)
    {
        requested_track.clear();
        if (current != nullptr && !current->stopped)
            current->force_stop = true;
        return;
    }

    requested_track = std::string("Sounds\\Music\\") + std::string(*filename) + ".sst";

    if (current != nullptr && !current->stopped)
    {
        current->force_stop = true;
        return;
    }

    current = loadTrack(requested_track);
    current_track = current;
    if (current != nullptr)
        current->start();
}

bool SferaSoundRuntime::initialize()
{
    listener_position_initialized = false;
    SI_SetLogFile(std::nullopt);
    if (SI_CreateInterface(SferaClientApplication::main_window, -1, 44100u, 0u) == nullptr)
    {
        return false;
    }

    auto *active_manager = ensureManager();
    if (active_manager != nullptr)
    {
        active_manager->enabled = interfaceAvailable();
        if (!active_manager->enabled)
        {
            for (const auto &sound : active_manager->sounds)
            {
                sound->Stop();
            }
            active_manager->clear();
        }
    }

    SphereUIInterfaceConfiguration::open("config.cfg");
    const int sound_volume = SphereUIInterfaceConfiguration::readInteger("SNDVOL", 100);
    const int music_volume = SphereUIInterfaceConfiguration::readInteger("MUSVOL", 100);
    const int hardware_mixing = SphereUIInterfaceConfiguration::readInteger("HWMIX", 0);

    SI_SetHardwareMixing(hardware_mixing != 0);
    loadDefinitions();
    SI_SetStreamVolume(music_volume);
    if (active_manager != nullptr)
        active_manager->setVolume(sound_volume);
    return true;
}

CSoundManager *SferaSoundRuntime::ensureManager()
{
    if (sound_manager != nullptr)
        return sound_manager.get();
    if (!interfaceAvailable())
        return nullptr;

    sound_manager = std::make_unique<CSoundManager>();
    return sound_manager.get();
}

void SferaSoundRuntime::update()
{
    auto *sound_interface = SI_GetInterface();
    if (sound_interface == nullptr || sound_interface->listener == nullptr)
    {
        listener_position_initialized = false;
        return;
    }

    auto *listener = sound_interface->listener;
    const auto *camera = g_sfera_world_objects.extendedObject(1u);
    if (camera != nullptr)
    {
        g_sfera_world_objects.recalculateBasis(1u);
        const SferaVec3F position = camera->position;
        const SferaVec3F velocity = listener_position_initialized ? position - listener->position : SferaVec3F{};
        const bool moved = velocity.x != 0.0f || velocity.y != 0.0f || velocity.z != 0.0f;
        if (!listener_position_initialized || moved)
            listener->SetPosition(position.x, position.y, position.z, 0);
        // The initial world position is not motion. A stationary listener must
        // also send zero velocity to replace the previous native sound state.
        listener->SetVelocity(velocity.x, velocity.y, velocity.z, 0);
        listener_position_initialized = true;

        SferaVec3F forward{}, up{};
        listener->GetOrientation(&forward, &up);
        const auto &next_forward = camera->orientation_basis[0];
        const auto next_up = camera->orientation_basis[1] * -1.0f;
        if (std::memcmp(&forward, &next_forward, sizeof(forward)) != 0 || std::memcmp(&up, &next_up, sizeof(up)) != 0)
        {
            listener->SetOrientation(next_forward, next_up, 0);
        }
    }
    else
    {
        listener->SetVelocity(0.0f, 0.0f, 0.0f, 0);
        listener_position_initialized = false;
    }

    updateTracks();
    if (sound_manager != nullptr)
        sound_manager->update();
}

void SferaSoundRuntime::shutdown()
{
    listener_position_initialized = false;
    clearDefinitions();
    if (sound_manager != nullptr)
    {
        sound_manager->clear();
        sound_manager.reset();
    }
    clearTracks();
    SI_Close();
}

std::uint32_t SferaSoundRuntime::soundVolume() const
{
    const auto *manager = sound_manager.get();
    if (manager == nullptr)
        return 0u;
    return std::clamp(std::lround(manager->volume * 100.0f), 0L, 100L);
}

int SferaSoundRuntime::musicVolume() const
{
    return SI_GetStreamVolume();
}

bool SferaSoundRuntime::hardwareMixing() const
{
    return SI_GetHardwareMixing();
}

void SferaSoundRuntime::setSoundVolume(std::uint32_t value)
{
    if (sound_manager != nullptr)
        sound_manager->setVolume(std::min(value, 100u));
}

void SferaSoundRuntime::setMusicVolume(std::uint32_t value)
{
    SI_SetStreamVolume(std::min(value, 100u));
}

void SferaSoundRuntime::adjustMusicVolume(int delta)
{
    SI_SetStreamVolume(SI_GetStreamVolume() + delta);
}

void SferaSoundRuntime::refreshMusicVolume()
{
    SI_SetStreamVolume(SI_GetStreamVolume());
}

void SferaSoundRuntime::setHardwareMixing(bool enabled)
{
    SI_SetHardwareMixing(enabled);
}

void SferaSoundRuntime::playUiSound(const std::string &filename)
{
    auto *manager = sound_manager.get();
    if (!g_sfera_interface.sounds_enabled || filename.empty() || SI_GetInterface() == nullptr || manager == nullptr || !manager->enabled)
        return;

    CSound *sound = nullptr;
    for (const auto &candidate : manager->sounds)
    {
        if (!candidate->filename.empty() && SferaText::asciiEqual(candidate->filename, filename) && candidate->IsSoundPlaying() == 0)
        {
            if (candidate->cache_available)
                sound = candidate.get();
            break;
        }
    }

    if (sound == nullptr)
    {
        auto created = std::make_unique<CSound>();
        created->cache_idle_since = UINT64_MAX;
        created->cache_lifetime_seconds = 0;
        created->cache_available = true;
        created->playback_finished = true;
        if (created->LoadSound(filename, 8u) == 0)
            return;
        sound = created.get();
        manager->sounds.push_back(std::move(created));
    }

    sound->cache_lifetime_seconds = 4;
    sound->SetVolume(manager->volume);
    sound->SetPlayTimepos(0.0f);
    if (sound->Play(0) != 0)
    {
        sound->cache_idle_since = UINT64_MAX;
        sound->playback_finished = false;
    }
}

void SferaSoundEventList::parseGroup(std::size_t group, std::string_view text)
{
    if (text.empty())
        return;

    const std::string_view line(text);
    auto &events = groups.at(group);
    events.assign(std::count(line.begin(), line.end(), ',') + 1u, SoundEventRecord{});

    std::size_t begin = 0u;
    for (std::size_t index = 0u; index < events.size(); ++index)
    {
        const auto end = line.find(',', begin);
        const auto length = end == std::string_view::npos ? std::string_view::npos : end - begin;
        const auto token = line.substr(begin, length);

        SoundEventRecord event;
        if (SferaText::asciiEqual(token, "STP"))
        {
            event.type = SoundEventType::stop;
        }
        else if (!token.empty())
        {
            auto digits = token.substr(1u);
            while (!digits.empty() && SferaText::isSpace(digits.front()))
            {
                digits.remove_prefix(1u);
            }
            if (!digits.empty() && digits.front() == '+')
                digits.remove_prefix(1u);

            std::size_t argument = 0u;
            const auto result = std::from_chars(digits.data(), digits.data() + digits.size(), argument);
            if (result.ec == std::errc{})
            {
                event.argument = argument;
                switch (token[0])
                {
                case 'p':
                    event.type = SoundEventType::seek;
                    break;
                case 's':
                    event.type = SoundEventType::wait;
                    break;
                case 'j':
                    event.type = SoundEventType::playlist;
                    break;
                default:
                    break;
                }
            }
        }

        events[index] = event;
        begin = end == std::string_view::npos ? line.size() : end + 1u;
    }
}

std::uint32_t SferaSoundPlaybackState::sfera_sound_decode_callback(CSoundStream *sound_stream, void *context) noexcept
{
    auto *playback = static_cast<SferaSoundPlaybackState *>(context);
    if (playback == nullptr)
        return 0u;

    const auto event = playback->nextEvent();
    if (event.type == SoundEventType::end)
    {
        if (sound_stream != nullptr)
            sound_stream->Stop();
        playback->finished = true;
        playback->playing = false;
        return 0u;
    }

    if (playback->force_stop)
    {
        playback->queueEvent(event, -1.0f);
        if (sound_stream != nullptr)
        {
            sound_stream->decode_event_position = UINT32_MAX;
            sound_stream->SetPlaySignal(playback->play_signal - 1.0f);
        }
        return 1u;
    }

    if (event.type == SoundEventType::seek && event.argument != 0u)
    {
        if (sound_stream != nullptr && event.argument <= playback->timings.size())
        {
            const auto &timing = playback->timings[event.argument - 1u];
            playback->queueEvent(event, timing.signal);
            sound_stream->SeekToTime(timing.seek_time);
            sound_stream->SetDecodeSignal(timing.signal);
        }
        return 1u;
    }

    if (event.type == SoundEventType::stop || (event.type == SoundEventType::wait && event.argument != 0u))
    {
        playback->queueEvent(event, -1.0f);
        if (sound_stream != nullptr)
            sound_stream->decode_event_position = UINT32_MAX;
    }
    return 1u;
}

std::uint32_t SferaSoundPlaybackState::sfera_sound_play_callback(CSoundStream *sound_stream, void *context) noexcept
{
    auto *playback = static_cast<SferaSoundPlaybackState *>(context);
    if (playback == nullptr)
        return 0u;

    const auto queued = playback->popEvent();
    if (!queued.has_value())
    {
        if (sound_stream != nullptr)
            sound_stream->play_event_position = UINT32_MAX;
        return 1u;
    }

    const auto &event = *queued;
    if (event.signal != -1.0f)
    {
        playback->play_signal = event.signal;
        if (sound_stream != nullptr)
            sound_stream->SetPlaySignal(event.signal);
    }
    else if (sound_stream != nullptr)
    {
        sound_stream->play_event_position = UINT32_MAX;
    }

    if (event.type == SoundEventType::wait && !playback->force_stop)
    {
        if (sound_stream != nullptr)
            sound_stream->Stop();
        playback->wait_seconds = event.argument;
        playback->wait_started_at = UINT64_MAX;
        playback->playing = false;
        return 1u;
    }

    if (event.type == SoundEventType::stop || playback->force_stop)
    {
        if (sound_stream != nullptr)
            sound_stream->Stop();
        playback->finished = true;
        playback->playing = false;
    }
    return 1u;
}

bool SferaSoundPlaybackState::queueEvent(SoundEventRecord event, float signal) noexcept
{
    event.signal = signal;
    try
    {
        event_queue.push_back(event);
        return true;
    }
    catch (const std::bad_alloc &)
    {
        return false;
    }
}

std::optional<SoundEventRecord> SferaSoundPlaybackState::popEvent() noexcept
{
    if (event_queue.empty())
        return std::nullopt;

    const auto event = event_queue.front();
    event_queue.pop_front();
    return event;
}

SoundEventRecord SferaSoundPlaybackState::nextEvent() noexcept
{
    for (;;)
    {
        auto *list = current_list;
        if (list == nullptr || list->group_index >= list->groups.size() || list->item_index >= list->groups[list->group_index].size())
        {
            return {};
        }

        const auto &events = list->groups[list->group_index];
        const auto event = events[list->item_index++];
        if (event.type != SoundEventType::playlist)
            return event;
        if (event.argument == 0u || event.argument > playlists.size())
        {
            return {SoundEventType::none};
        }

        current_list = &playlists[event.argument - 1u];
        if (current_list->groups.empty())
            return {};
        current_list->item_index = 0u;
        current_list->group_index = std::rand() % current_list->groups.size();
    }
}

SferaSoundPlaybackState::SferaSoundPlaybackState()
    : playing(false), wait_seconds(0u), wait_started_at(UINT64_MAX), play_signal(0.0f), current_list(nullptr), playlist_index(0u), stream(nullptr), finished(false), stopped(true), volume_scale(1),
      force_stop(false)
{
}


float SferaSoundPlaybackState::parseTime(std::string_view text)
{
    if (text.empty())
        return 0.0f;

    const std::string_view token(text);
    const auto colon = token.find(':');
    const auto prefix_size = std::min<std::size_t>(15u, colon == std::string_view::npos ? token.size() : colon);
    if (prefix_size >= token.size())
        return 0.0f;

    const auto minutes = std::atoi(std::string(token.substr(0u, prefix_size)).c_str());
    const auto seconds = std::atof(std::string(token.substr(prefix_size + 1u)).c_str());
    return static_cast<float>(minutes * 60.0 + seconds);
}

bool SferaSoundPlaybackState::load(const std::string &filename)
{
    SferaSimpleParser parser;

    parser.load(filename);
    SferaParserRange track{};
    SferaParserRange block{};
    std::string text;
    if (!parser.findBlock("soundtrack", &track, nullptr, 1) || !parser.findValue("audio_file", &track) || !parser.readQuotedString(0u, text))
    {
        return false;
    }

    source = text;

    if (parser.findValue("volume", &track))
    {
        volume_scale = std::trunc(parser.readFloat(0u));
    }

    if (!parser.findBlock("samples", &block, &track, 1))
        return false;
    const auto sample_count = countRecords(parser, block, "sample");
    if (sample_count == 0u)
        return false;

    timings.assign(sample_count, {});
    parser.setScanRange(&block);
    while (parser.nextValue("sample"))
    {
        const auto index = parser.readInt(0u);
        if (index <= 0 || std::cmp_greater(index, timings.size()))
            return false;

        std::string start, end;
        parser.readString(1u, start);
        parser.readString(2u, end);
        timings[index - 1] = {parseTime(start), parseTime(end)};
    }
    parser.clearScanRange();

    if (!parser.findBlock("patterns", &block, &track, 1))
        return false;
    const auto pattern_count = countRecords(parser, block, "pattern");
    if (pattern_count == 0u)
        return false;

    current_list = nullptr;
    playlists.assign(pattern_count, {});
    parser.setScanRange(&block);
    while (parser.nextValue("pattern"))
    {
        const auto token_count = parser.tokenCount();
        if (token_count == 0u)
            continue;

        const auto index = parser.readInt(0u);
        if (index <= 0 || std::cmp_greater(index, playlists.size()))
            return false;

        auto &pattern = playlists[index - 1];
        pattern.groups.resize(token_count > 2u ? (token_count - 1u) / 2u + 1u : 1u);

        std::size_t group = 0u;
        for (std::size_t token = 1u; token < token_count; token += 2u)
        {
            if (parser.readString(token, text))
                pattern.parseGroup(group++, text);
        }
    }
    parser.clearScanRange();

    const int starting_pattern = parser.findValue("start_pattern", &block) ? parser.readInt(0u) : 1;
    if (starting_pattern <= 0 || std::cmp_greater(starting_pattern, playlists.size()))
        return false;
    playlist_index = (starting_pattern - 1);
    return true;
}

bool SferaSoundPlaybackState::start()
{
    if (source.empty() || playlist_index >= playlists.size() || playlists[playlist_index].groups.empty())
    {
        current_list = nullptr;
        return false;
    }

    current_list = nullptr;
    if (stream == nullptr)
        stream = SI_StreamCreateFile(source, 1u);
    if (stream == nullptr)
        return false;

    stream->decode_callback = &SferaSoundPlaybackState::sfera_sound_decode_callback;
    stream->decode_state = this;
    stream->play_callback = &SferaSoundPlaybackState::sfera_sound_play_callback;
    stream->play_state = this;
    stream->stream_gain = volume_scale;

    playing = false;
    finished = false;
    force_stop = false;
    current_list = &playlists[playlist_index];
    current_list->item_index = 0u;
    current_list->group_index = std::rand() % current_list->groups.size();
    event_queue.clear();
    stopped = false;
    return true;
}

void SferaSoundPlaybackState::stop()
{
    if (stream != nullptr)
    {
        if (stream->IsStreamPlaying())
            stream->Stop();
        stream->decode_event_position = UINT32_MAX;
        stream->play_event_position = UINT32_MAX;
    }
    stopped = true;
    playing = false;
}

void SferaSoundPlaybackState::clear()
{
    if (stream != nullptr)
        SI_StreamFree(stream);
    stream = nullptr;

    source.clear();
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

void SferaSoundPlaybackState::update()
{
    if (stream == nullptr || stopped)
        return;

    const int ready_state = stream->ReadyState();
    if (ready_state < 0)
    {
        finished = true;
        stop();
        return;
    }
    if (ready_state == 0 || playing || stream->decoder_state != 0u)
        return;
    if (finished || force_stop)
    {
        stop();
        return;
    }

    if (wait_seconds != 0u)
    {
        const auto now = WorldClock::nowTicks();
        if (wait_started_at == UINT64_MAX)
        {
            wait_started_at = now;
            return;
        }
        if (now >= wait_started_at && (now - wait_started_at) / 10000u >= wait_seconds)
        {
            wait_seconds = 0u;
            wait_started_at = UINT64_MAX;
        }
        return;
    }

    const auto event = nextEvent();
    if (event.type == SoundEventType::end)
    {
        stop();
        return;
    }

    if (event.type == SoundEventType::seek && event.argument > 0u && event.argument <= timings.size())
    {
        if (stream->IsStreamPlaying())
            stream->Stop();
        const auto &timing = timings[event.argument - 1u];
        play_signal = timing.signal;
        stream->SetDecodeSignal(timing.signal);
        stream->SetPlaySignal(play_signal);
        if (stream->PlayEx(timing.seek_time, 0) != 0)
            playing = true;
        return;
    }

    if (event.type == SoundEventType::wait)
    {
        if (stream->IsStreamPlaying())
            stream->Stop();
        stream->decode_event_position = UINT32_MAX;
        stream->play_event_position = UINT32_MAX;
        wait_seconds = event.argument;
        wait_started_at = UINT64_MAX;
        return;
    }

    if (event.type == SoundEventType::stop)
        stop();
}

std::size_t SferaSoundPlaybackState::countRecords(SferaSimpleParser &parser, SferaParserRange &block, std::string_view name)
{
    parser.setScanRange(&block);
    std::size_t count = 0u;
    while (parser.nextValue(name))
        ++count;
    return count;
}

void SferaSoundCacheHelper::service_semantic_sound_cache()
{
    auto *manager = g_sfera_sound_runtime.sound_manager.get();
    if (manager == nullptr)
        return;
    auto &cache = manager->cache;
    const auto now = std::chrono::steady_clock::now();
    for (auto entry = cache.begin(); entry != cache.end();)
    {
        CSound *sound = entry->sound.get();
        if (sound == nullptr)
        {
            entry = cache.erase(entry);
            continue;
        }
        const bool playing = sound->IsSoundPlaying() != 0;
        sound->playback_finished = !playing;
        if (playing || !sound->cache_available)
        {
            entry->idle_started = false;
            ++entry;
            continue;
        }
        const int lifetime = sound->cache_lifetime_seconds;
        if (lifetime < 0)
        {
            ++entry;
            continue;
        }
        if (!entry->idle_started)
        {
            entry->idle_since = now;
            entry->idle_started = true;
        }
        if (lifetime != 0 && std::chrono::duration_cast<std::chrono::seconds>(now - entry->idle_since).count() < lifetime)
        {
            ++entry;
            continue;
        }
        entry = cache.erase(entry);
    }
}
void CSoundManager::setVolume(int percent)
{
    volume = std::clamp(percent, 0, 100) * 0.01f;
    for (const auto &sound : sounds)
    {
        sound->SetVolume(volume);
    }
    for (auto &entry : cache)
    {
        if (entry.sound != nullptr)
            entry.sound->SetVolume(volume);
    }
}

void CSoundManager::update()
{
    std::erase_if(sounds, &CSoundManager::shouldEvict);
    SferaSoundCacheHelper::service_semantic_sound_cache();
    if (auto *sound_interface = SI_GetInterface())
        sound_interface->UpdateSettings();
}

void CSoundManager::clear()
{
    sounds.clear();
    for (auto &entry : cache)
    {
        entry.sound->Stop();
        entry.sound->playback_finished = true;
    }
    cache.clear();
}

bool CSoundManager::shouldEvict(const std::unique_ptr<CSound> &sound)
{
    if (sound->IsSoundPlaying() == 0)
        sound->playback_finished = true;
    if (!sound->playback_finished || !sound->cache_available || sound->cache_lifetime_seconds < 0)
        return false;
    if (sound->cache_lifetime_seconds == 0)
        return true;
    const auto now = WorldClock::nowTicks();
    if (sound->cache_idle_since == UINT64_MAX)
        sound->cache_idle_since = now;
    return (now - sound->cache_idle_since) / 10000u >= sound->cache_lifetime_seconds;
}

float CSoundEffect::sound_elapsed(std::uint64_t start)
{
    return SferaNumeric::signedWord(WorldClock::nowTicks() - start) * 0.0001f;
}
std::uint32_t CSoundEffect::sound_flag(std::string_view token)
{
    if (SferaText::asciiEqual(token, "SF_TYPE_ENVIRONMENT"))
        return 1u << 0u;
    if (SferaText::asciiEqual(token, "SF_PLAY_RANDOM"))
        return 1u << 2u;
    if (SferaText::asciiEqual(token, "SF_PLAY_RANDOMMIX"))
        return 1u << 3u;
    if (SferaText::asciiEqual(token, "SF_PLAY_LOOPED"))
        return 1u << 4u;
    if (SferaText::asciiEqual(token, "SF_PLAY_USEREGION"))
        return 1u << 5u;
    if (SferaText::asciiEqual(token, "SF_PLAY_TIMEGROUPS"))
        return 1u << 6u;
    return 0u;
}
void CSoundEffect::release_active_sound(CSoundEffect &effect)
{
    auto sound = std::move(effect.active_sound);
    if (sound == nullptr)
        return;
    if (!sound->playback_finished && sound->IsSoundPlaying() != 0)
        sound->Stop();
    sound->cache_available = true;
    SferaSoundCacheHelper::service_semantic_sound_cache();
}
bool CSoundEffect::play_sound(CSound &sound, bool looped, float position)
{
    sound.SetPlayTimepos(position);
    if (sound.CSound::Play(looped) == 0)
        return false;
    sound.cache_idle_since = UINT64_MAX;
    sound.playback_finished = false;
    return true;
}
std::shared_ptr<CSound> CSoundEffect::find_cached_sound(CSoundManager &manager, const std::string &filename)
{
    if (filename.empty())
        return nullptr;
    SferaSoundCacheHelper::service_semantic_sound_cache();
    for (auto &entry : manager.cache)
    {
        CSound *sound = entry.sound.get();
        if (sound == nullptr || sound->IsSoundPlaying() != 0 || !sound->cache_available)
            continue;
        if (SferaText::asciiEqual(filename, sound->filename))
        {
            entry.idle_started = false;
            return entry.sound;
        }
    }
    return nullptr;
}
std::shared_ptr<CSound> CSoundEffect::create_cached_sound(CSoundManager &manager, const std::string &filename, const SferaSound3DParameters *parameters, int cache_lifetime)
{
    if (!manager.enabled || filename.empty())
        return nullptr;
    auto sound = CSoundEffect::find_cached_sound(manager, filename);
    if (sound == nullptr)
    {
        FILE *file = nullptr;
        if (fopen_s(&file, filename.c_str(), "rb") != 0 || file == nullptr)
            return nullptr;
        std::fclose(file);
        sound = std::make_shared<CSound>();
        const std::uint32_t load_flags = parameters == nullptr ? (1u << 3u) : ((1u << 0u) | (1u << 3u) | (1u << 5u));
        if (sound->LoadSound(filename, load_flags) == 0)
            return nullptr;
        manager.cache.push_back({sound});
    }
    sound->cache_lifetime_seconds = cache_lifetime;
    sound->cache_available = true;
    if (parameters != nullptr)
        sound->SetAllParameters(parameters, 0);
    sound->SetVolume(manager.volume);
    return sound;
}

std::size_t CSoundEffect::choose_sound_source(CSoundEffect &effect)
{
    if ((effect.definition->flags & (1u << 6u)) != 0u && effect.definition != nullptr && !effect.definition->time_groups.empty())
    {
        const auto &groups = effect.definition->time_groups;
        std::size_t selected = groups.size();
        for (std::size_t index = 0u; index < groups.size(); ++index)
            if (CSoundEffect::sound_time_matches(g_sfera_graphics_runtime.environment_factor, groups[index]))
            {
                selected = index;
                break;
            }
        if (selected == groups.size())
            return 0u;
        const auto &group = groups[selected];
        if ((effect.definition->flags & ((1u << 2u) | (1u << 3u))) != 0u && group.source_end >= group.source_begin && group.source_end - group.source_begin + 1u > 1u)
        {
            std::size_t value = group.source_begin;
            do
                value = group.source_begin + std::rand() % (group.source_end - group.source_begin + 1u);
            while (effect.last_source_index == value);
            return value;
        }
        return group.source_begin;
    }
    if ((effect.definition->flags & ((1u << 2u) | (1u << 3u))) != 0u && effect.definition->sources.size() > 1u)
    {
        std::size_t value = 0u;
        do
            value = std::rand() % effect.definition->sources.size();
        while (effect.last_source_index == value);
        return value;
    }
    return 0u;
}
bool CSoundEffect::sound_distance_gate(CSoundEffect &effect, const SferaVec3F *frame, float distance)
{
    if ((effect.definition->flags & (1u << 0u)) != 0u)
        return true;
    if (distance > effect.sound_parameters.max_distance)
    {
        if (!effect.distance_paused)
        {
            if (effect.active_sound != nullptr)
            {
                auto sound = effect.active_sound;
                if ((effect.definition->flags & ((1u << 2u) | (1u << 3u) | (1u << 4u))) == 0u)
                    effect.saved_play_time = sound->GetPlayTimepos();
                CSoundEffect::release_active_sound(effect);
            }
            effect.silence_active = false;
            effect.distance_paused = true;
            effect.transition_started_at = WorldClock::nowTicks();
        }
        return false;
    }
    if (!effect.distance_paused)
        return true;
    const float elapsed = CSoundEffect::sound_elapsed(effect.transition_started_at);
    if ((effect.definition->flags & ((1u << 2u) | (1u << 3u) | (1u << 4u))) == 0u && effect.active_sound != nullptr)
    {
        auto sound = effect.active_sound;
        const float resume = effect.saved_play_time + elapsed;
        const float length = sound->duration_seconds;
        if (resume > length)
        {
            CSoundEffect::release_active_sound(effect);
            effect.distance_paused = false;
            return true;
        }
        CSoundEffect::play_sound(*sound, 0, resume);
        effect.distance_paused = false;
        return true;
    }
    effect.distance_paused = false;
    effect.start(frame, false);
    return true;
}

CSoundEffect::CSoundEffect(std::shared_ptr<const CSoundEffectDefinition> source) : definition(std::move(source))
{
    if (definition == nullptr)
        throw std::invalid_argument("Missing sound definition");
    sound_parameters = definition->parameters;
}

CSoundEffect::~CSoundEffect()
{
    stop();
}
std::shared_ptr<const CSoundEffectDefinition> CSoundEffect::loadDefinition(SferaSimpleParser &parser, const SferaParserRange &range)
{
    auto data = std::make_shared<CSoundEffectDefinition>();

    data->flags = 0u;
    if (parser.findValue("eff_number", &range))
        data->effect_number = parseInteger(parser, 0u);
    SferaParserRange block{};
    std::string text;
    if (parser.findBlock("audio_files", &block, &range, 1))
    {
        parser.setScanRange(&block);
        std::size_t source_lines = 0u;
        while (parser.nextValue("source"))
            ++source_lines;
        if (source_lines == 0u)
        {
            parser.clearScanRange();
            return nullptr;
        }
        data->sources.resize(source_lines);
        std::vector<bool> assigned(source_lines);
        parser.setScanRange(&block);
        while (parser.nextValue("source"))
        {
            const int index = parseInteger(parser, 0u);
            if (index < 0 || std::cmp_greater_equal(index, data->sources.size()))
            {
                parser.clearScanRange();
                return nullptr;
            }
            auto &source = data->sources[index];
            source = {};
            assigned[index] = true;
            if (!parser.readQuotedString(1u, text))
            {
                parser.clearScanRange();
                return nullptr;
            }
            if (SferaText::asciiEqual(text, "silence"))
            {
                source.silence = true;
                source.silence_duration = parseReal(parser, 2u);
            }
            else
                source.filename = text;
        }
        parser.clearScanRange();
        if (std::find(assigned.begin(), assigned.end(), false) != assigned.end())
            return nullptr;
    }
    else if (parser.findValue("audio_file", &range))
    {
        if (!parser.readQuotedString(0u, text))
            return nullptr;
        data->sources.push_back({text});
    }
    else
        return nullptr;
    if (parser.findBlock("time_groups", &block, &range, 1))
    {
        parser.setScanRange(&block);
        std::size_t count = 0u;
        while (parser.nextValue("time"))
            ++count;
        data->time_groups.resize(count);
        parser.setScanRange(&block);
        std::size_t index = 0u;
        while (parser.nextValue("time") && index < count)
        {
            float begin = parseReal(parser, 0u);
            float end = parseReal(parser, 1u);
            int source_begin = parseInteger(parser, 2u);
            int source_end = parseInteger(parser, 3u);
            if (source_begin < 0 || source_end < 0 || std::cmp_greater_equal(source_begin, data->sources.size()) || std::cmp_greater_equal(source_end, data->sources.size()))
            {
                parser.clearScanRange();
                return nullptr;
            }
            auto &group = data->time_groups[index++];
            group.begin = begin == 0.0f ? 1.0f : 1.0f - begin / 24.0f;
            group.end = end == 0.0f ? 1.0f : 1.0f - end / 24.0f;
            group.source_begin = std::min(source_begin, source_end);
            group.source_end = std::max(source_begin, source_end);
        }
        parser.clearScanRange();
    }
    if (parser.findValue("flags", &range))
    {
        for (std::size_t index = 0u; index < parser.tokenCount(); index += 2u)
        {
            data->flags |= CSoundEffect::sound_flag(parser.tokenAt(index));
        }
    }
    if (parser.findValue("region_radius", &range))
        data->region_radius = parseVector(parser);
    bool has_min = false;
    bool has_max = false;
    if (parser.findValue("min_distance", &range))
    {
        data->parameters.min_distance = parseReal(parser, 0u);
        has_min = true;
    }
    if (parser.findValue("max_distance", &range))
    {
        data->parameters.max_distance = parseReal(parser, 0u);
        has_max = true;
    }
    if (parser.findValue("mix_duration", &range))
        data->mix_duration = parseReal(parser, 0u);
    float barrier = 0.03f;
    if (parser.findValue("vol_barier", &range))
    {
        barrier = parseReal(parser, 0u);
        barrier = barrier == 0.0f ? 0.01f : std::min(barrier / 100.0f, 1.0f);
    }
    if (has_min && !has_max && barrier > 0.0f)
        data->parameters.max_distance = data->parameters.min_distance / barrier;
    else if (has_max && !has_min)
        data->parameters.min_distance = data->parameters.max_distance * barrier;
    if (parser.findValue("offset_vec", &range))
        data->offset = parseVector(parser);
    if (parser.findValue("cache_lifetime", &range))
        data->cache_lifetime = std::min(parseInteger(parser, 0u), 10);
    if (data->parameters.min_distance < 0.0f || data->parameters.max_distance < 0.0f || !std::isfinite(data->parameters.min_distance) || !std::isfinite(data->parameters.max_distance))
        return nullptr;
    for (const auto &source : data->sources)
    {
        if (source.silence ? source.silence_duration < 0.0f : source.filename.empty())
            return nullptr;
    }
    return data;
}
void CSoundEffect::reset()
{
    stop();
    silence_started_at = transition_started_at = 0;
    silence_duration = saved_play_time = 0.0f;
    region_offset = last_position = {};
    last_source_index.reset();
    sound_parameters = definition->parameters;
}

void CSoundEffect::start(const SferaVec3F *frame, bool after_start_time)
{
    if (definition == nullptr || definition->sources.empty() || g_sfera_sound_runtime.sound_manager == nullptr)
        return;
    CSoundEffect::release_active_sound(*this);
    const auto index = std::min(CSoundEffect::choose_sound_source(*this), definition->sources.size() - 1u);
    last_source_index = index;
    const auto &source = definition->sources[index];
    if (source.silence)
    {
        silence_active = true;
        silence_duration = source.silence_duration;
        silence_started_at = WorldClock::nowTicks();
        return;
    }
    const auto &filename = source.filename;
    auto *manager = g_sfera_sound_runtime.sound_manager.get();
    if (manager == nullptr || filename.empty())
        return;
    if ((definition->flags & (1u << 5u)) != 0u)
    {
        region_offset = {randomComponent(definition->region_radius.x), randomComponent(definition->region_radius.y), randomComponent(definition->region_radius.z)};
    }
    if (frame != nullptr)
    {
        const auto &position = *frame;
        sound_parameters.position = {position.x - definition->offset.x + region_offset.x, position.y - definition->offset.y + region_offset.y, position.z - definition->offset.z + region_offset.z};
        last_position = {sound_parameters.position.x, sound_parameters.position.y, sound_parameters.position.z};
    }
    if (after_start_time && (definition->flags & ((1u << 2u) | (1u << 3u) | (1u << 4u))) != 0u)
    {
        distance_paused = true;
        transition_started_at = WorldClock::nowTicks();
        return;
    }
    auto sound = CSoundEffect::create_cached_sound(*manager, filename, (definition->flags & (1u << 0u)) != 0u ? nullptr : &sound_parameters, definition->cache_lifetime);
    if (sound != nullptr)
    {
        active_sound = sound;
        sound->cache_available = false;
        if (!after_start_time)
            CSoundEffect::play_sound(*sound, (definition->flags & (1u << 4u)) != 0u, 0.0f);
    }
    distance_paused = after_start_time ? 1u : 0u;
    if (after_start_time)
        transition_started_at = WorldClock::nowTicks();
}
void CSoundEffect::update(const SferaVec3F *frame, float age)
{
    SferaSoundCacheHelper::service_semantic_sound_cache();
    if (!CSoundEffect::sound_distance_gate(*this, frame, age))
        return;
    if (silence_active)
    {
        const float elapsed = CSoundEffect::sound_elapsed(silence_started_at);
        if (elapsed < 0.0f)
        {
            silence_active = false;
            return;
        }
        if ((definition->flags & (1u << 3u)) != 0u && elapsed >= silence_duration - definition->mix_duration)
        {
            silence_active = false;
            start(frame, false);
            return;
        }
        if (elapsed >= silence_duration)
            silence_active = false;
        return;
    }
    if (active_sound == nullptr)
        return;
    auto sound = active_sound;
    if (sound == nullptr)
    {
        active_sound = nullptr;
        return;
    }
    if (sound->IsSoundPlaying() == 0 || sound->playback_finished)
    {
        sound->cache_available = true;
        active_sound = nullptr;
        SferaSoundCacheHelper::service_semantic_sound_cache();
        return;
    }
    if ((definition->flags & (1u << 3u)) != 0u)
    {
        const float length = sound->duration_seconds;
        if (sound->GetPlayTimepos() >= length - definition->mix_duration)
        {
            CSoundEffect::release_active_sound(*this);
            start(frame, false);
            if (active_sound == nullptr)
                return;
            sound = active_sound;
        }
    }
    if ((definition->flags & (1u << 0u)) != 0u || frame == nullptr || sound == nullptr)
        return;
    const auto &position = *frame;
    const SferaVec3F current{position.x - definition->offset.x + region_offset.x, position.y - definition->offset.y + region_offset.y, position.z - definition->offset.z + region_offset.z};
    const SferaVec3F velocity{current.x - last_position.x, current.y - last_position.y, current.z - last_position.z};
    if (velocity.x != 0.0f || velocity.y != 0.0f || velocity.z != 0.0f)
    {
        last_position = current;
        sound->SetPosition(current.x, current.y, current.z, 0);
    }
    sound->SetVelocity(velocity.x, velocity.y, velocity.z, 0);
}
void CSoundEffect::stop()
{
    CSoundEffect::release_active_sound(*this);
    silence_active = false;
    distance_paused = false;
}
bool CSoundEffect::isComplete() const
{
    if (distance_paused || silence_active)
        return false;
    return active_sound == nullptr || active_sound->playback_finished;
}

int CSoundEffect::parseInteger(SferaSimpleParser &parser, std::size_t index)
{
    int value{};
    if (!parser.tryReadInt(index, value))
        throw std::invalid_argument("Invalid sound integer");
    return value;
}

float CSoundEffect::parseReal(SferaSimpleParser &parser, std::size_t index)
{
    float value{};
    if (!parser.tryReadFloat(index, value) || !std::isfinite(value))
        throw std::invalid_argument("Invalid sound number");
    return value;
}

SferaVec3F CSoundEffect::parseVector(SferaSimpleParser &parser)
{
    return SferaVec3F{parseReal(parser, 0), parseReal(parser, 1), parseReal(parser, 2)};
}

float CSoundEffect::randomComponent(float radius)
{
    return (std::rand() - std::rand()) * 3.0518509447574615e-05f * radius;
}

std::shared_ptr<const CSoundEffectDefinition> SoundEffectRegistry::find(std::uint32_t id) const
{
    const auto found = std::lower_bound(definitions.begin(), definitions.end(), id, &SoundEffectRegistry::lessThanId);
    return found != definitions.end() && (*found)->effect_number == id ? *found : nullptr;
}

bool SoundEffectRegistry::load()
{
    std::vector<std::shared_ptr<const CSoundEffectDefinition>> loaded;
    loaded.reserve(100);
    WIN32_FIND_DATAA found{};
    HANDLE search = ::FindFirstFileA("Sounds\\*.def", &found);
    if (search != INVALID_HANDLE_VALUE)
    {
        SferaSoundDefinitionSearchScope close_search{search};
        try
        {
            do
            {
                if ((found.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0u)
                    continue;
                SferaSimpleParser parser;
                if (!parser.load(std::string("Sounds\\") + found.cFileName))
                    return false;
                parser.setBlockRange(nullptr);
                SferaParserRange range{};
                while (parser.nextBlock("soundeffect", &range))
                {
                    SferaParserRange continuation{};
                    parser.getBlockRange(&continuation);
                    auto definition = CSoundEffect::loadDefinition(parser, range);
                    if (definition == nullptr)
                        return false;
                    loaded.push_back(std::move(definition));
                    parser.setBlockRange(&continuation);
                }
            } while (::FindNextFileA(search, &found));
        }
        catch (const std::exception &)
        {
            return false;
        }
    }
    std::sort(loaded.begin(), loaded.end(), &SoundEffectRegistry::lessById);
    definitions.swap(loaded);
    return true;
}

SferaSoundDefinitionSearchScope::~SferaSoundDefinitionSearchScope()
{
    ::FindClose(handle);
}

bool SoundEffectRegistry::lessThanId(const std::shared_ptr<const CSoundEffectDefinition> &definition, std::uint32_t number)
{
    return definition->effect_number < number;
}

bool SoundEffectRegistry::lessById(const std::shared_ptr<const CSoundEffectDefinition> &first, const std::shared_ptr<const CSoundEffectDefinition> &second)
{
    return first->effect_number < second->effect_number;
}

std::unique_ptr<IEffectVoice> CSoundEffectDefinition::createVoice() const
{
    return std::make_unique<CSoundEffect>(shared_from_this());
}
