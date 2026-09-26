#include <windows.h>
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <mmreg.h>
#include <dsound.h>
#include <functional>
#include <limits>
#include <memory>
#include <mutex>
#include <objbase.h>
#include <optional>
#include <span>
#include <stop_token>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "audio/AudioDecoder.h"
#include "audio/DirectSoundBackend.h"
#include "audio/Sound.h"
#include "binary/Binary.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "platform/WindowsCom.h"

std::uint16_t SferaSoundAudioDecoder::readU16(const std::uint8_t *value)
{
    return SferaBinary::readLittleEndian<std::uint16_t>(value);
}

std::uint32_t SferaSoundAudioDecoder::readU32(const std::uint8_t *value)
{
    return SferaBinary::readLittleEndian<std::uint32_t>(value);
}

bool SferaSoundAudioDecoder::readBinaryFile(const std::string &filename, std::vector<std::uint8_t> &bytes)
{
    if (filename.empty())
        return false;
    FILE *file = nullptr;
    if (::fopen_s(&file, filename.c_str(), "rb") != 0 || file == nullptr)
        return false;
    const std::unique_ptr<FILE, decltype(&std::fclose)> close(file, &std::fclose);

    if (::_fseeki64(file, 0, SEEK_END) != 0)
        return false;
    const std::int64_t file_size = ::_ftelli64(file);
    if (file_size <= 0 || !std::in_range<std::size_t>(file_size) || ::_fseeki64(file, 0, SEEK_SET) != 0)
    {
        return false;
    }

    const std::size_t byte_count = file_size;
    bytes.resize(byte_count);
    return std::fread(bytes.data(), 1u, bytes.size(), file) == bytes.size();
}

bool SferaSoundAudioDecoder::decodePcmWave(const std::vector<std::uint8_t> &bytes, SferaDecodedAudio &output)
{
    if (bytes.size() < 12u || std::memcmp(bytes.data(), "RIFF", 4u) != 0 || std::memcmp(bytes.data() + 8u, "WAVE", 4u) != 0)
    {
        return false;
    }

    WAVEFORMATEX format{};
    bool have_format = false;
    const std::uint8_t *audio_data = nullptr;
    std::size_t audio_size = 0u;
    for (std::size_t offset = 12u; offset + 8u <= bytes.size();)
    {
        const auto *chunk = bytes.data() + offset;
        const std::size_t chunk_size = SferaSoundAudioDecoder::readU32(chunk + 4u);
        const std::size_t data_offset = offset + 8u;
        if (data_offset > bytes.size() || chunk_size > bytes.size() - data_offset)
            return false;
        if (std::memcmp(chunk, "fmt ", 4u) == 0 && chunk_size >= 16u)
        {
            const auto *value = bytes.data() + data_offset;
            format.wFormatTag = SferaSoundAudioDecoder::readU16(value);
            format.nChannels = SferaSoundAudioDecoder::readU16(value + 2u);
            format.nSamplesPerSec = SferaSoundAudioDecoder::readU32(value + 4u);
            format.nAvgBytesPerSec = SferaSoundAudioDecoder::readU32(value + 8u);
            format.nBlockAlign = SferaSoundAudioDecoder::readU16(value + 12u);
            format.wBitsPerSample = SferaSoundAudioDecoder::readU16(value + 14u);
            format.cbSize = 0u;
            have_format = format.wFormatTag == WAVE_FORMAT_PCM;
        }
        else if (std::memcmp(chunk, "data", 4u) == 0)
        {
            audio_data = bytes.data() + data_offset;
            audio_size = chunk_size;
        }
        offset = data_offset + chunk_size + (chunk_size & 1u);
    }

    if (!have_format || audio_data == nullptr || audio_size == 0u || format.nBlockAlign == 0u || format.nAvgBytesPerSec == 0u)
    {
        return false;
    }
    audio_size -= audio_size % format.nBlockAlign;
    if (audio_size == 0u || audio_size > std::numeric_limits<DWORD>::max())
        return false;
    output.format = format;
    output.pcm.assign(audio_data, audio_data + audio_size);
    return true;
}

bool SferaSoundAudioDecoder::decodeVorbis(const std::vector<std::uint8_t> &bytes, SferaDecodedAudio &output)
{
    if (bytes.size() < 4u || std::memcmp(bytes.data(), "OggS", 4u) != 0)
        return false;

    SferaVorbisPcm decoded;
    if (!decodeVorbisMemory(bytes.data(), bytes.size(), decoded))
        return false;
    if (decoded.channels == 0u || decoded.channels > 2u || decoded.sample_rate == 0u || decoded.samples.empty())
    {
        return false;
    }

    const std::uint32_t sample_width = sizeof(std::int16_t);
    const std::uint32_t block_align = decoded.channels * sample_width;
    const std::uint64_t sample_rate = decoded.sample_rate;
    const std::uint64_t sample_count = decoded.samples.size();
    const std::uint64_t bytes_per_second = sample_rate * block_align;
    const std::uint64_t pcm_size = sample_count * sample_width;
    if (block_align > std::numeric_limits<WORD>::max() || bytes_per_second > std::numeric_limits<DWORD>::max() || pcm_size == 0u || pcm_size > std::numeric_limits<DWORD>::max())
    {
        return false;
    }

    output.format = {};
    output.format.wFormatTag = WAVE_FORMAT_PCM;
    output.format.nChannels = decoded.channels;
    output.format.nSamplesPerSec = decoded.sample_rate;
    output.format.wBitsPerSample = 16u;
    output.format.nBlockAlign = static_cast<WORD>(block_align);
    output.format.nAvgBytesPerSec = static_cast<DWORD>(bytes_per_second);
    output.format.cbSize = 0u;
    const std::size_t output_size = pcm_size;
    output.pcm.resize(output_size);
    std::memcpy(output.pcm.data(), decoded.samples.data(), output.pcm.size());
    return true;
}

bool SferaSoundAudioDecoder::decodeAudioFile(const std::string &filename, SferaDecodedAudio &output)
{
    std::vector<std::uint8_t> bytes;
    if (!SferaSoundAudioDecoder::readBinaryFile(filename, bytes))
        return false;
    if (SferaSoundAudioDecoder::decodePcmWave(bytes, output))
        return true;
    return SferaSoundAudioDecoder::decodeVorbis(bytes, output);
}

float SferaSoundBackend::normalizedGain(float gain)
{
    if (!std::isfinite(gain) || gain <= 0.0f)
        return 0.0f;
    if (gain > 1.0f)
        gain *= 0.01f;
    return std::clamp(gain, 0.0f, 1.0f);
}

LONG SferaSoundBackend::directSoundVolume(float gain)
{
    gain = SferaSoundBackend::normalizedGain(gain);
    if (gain <= 0.00001f)
        return DSBVOLUME_MIN;
    const double precise_gain = gain;
    const double units = 2000.0 * std::log10(precise_gain);
    return std::clamp<long>(std::lround(units), DSBVOLUME_MIN, DSBVOLUME_MAX);
}

bool SferaSoundBackend::copyToBuffer(IDirectSoundBuffer8 *buffer, const std::vector<std::uint8_t> &pcm)
{
    if (buffer == nullptr || pcm.empty() || pcm.size() > std::numeric_limits<DWORD>::max())
        return false;
    const DWORD buffer_size = SferaNumeric::lowWord(pcm.size());
    SferaSoundBufferMapping mapping(*buffer, buffer_size);
    if (!mapping.copy(pcm))
        return false;
    return mapping.close();
}

bool SferaSoundBackend::createBuffer(IDirectSound8 *device, const SferaDecodedAudio &audio, bool spatial, bool hardware_mixing, ComPtr<IDirectSoundBuffer8> &buffer,
                                     ComPtr<IDirectSound3DBuffer8> &spatial_buffer)
{
    if (device == nullptr || audio.pcm.empty() || audio.pcm.size() > std::numeric_limits<DWORD>::max())
        return false;

    DSBUFFERDESC description{};
    description.dwSize = SferaNumeric::lowWord(sizeof(description));
    description.dwBufferBytes = SferaNumeric::lowWord(audio.pcm.size());
    auto format = audio.format;
    description.lpwfxFormat = &format;
    description.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_GETCURRENTPOSITION2 | DSBCAPS_GLOBALFOCUS;
    if (spatial && audio.format.nChannels == 1u)
    {
        description.dwFlags |= DSBCAPS_CTRL3D | DSBCAPS_MUTE3DATMAXDISTANCE;
    }
    description.dwFlags |= hardware_mixing ? DSBCAPS_LOCHARDWARE : DSBCAPS_LOCSOFTWARE;

    ComPtr<IDirectSoundBuffer> base;
    HRESULT result = device->CreateSoundBuffer(&description, &base, nullptr);
    if (FAILED(result) && hardware_mixing)
    {
        description.dwFlags &= ~DSBCAPS_LOCHARDWARE;
        description.dwFlags |= DSBCAPS_LOCSOFTWARE;
        result = device->CreateSoundBuffer(&description, &base, nullptr);
    }
    if (FAILED(result))
        return false;
    if (FAILED(SferaSoundBackend::queryInterface(base.Get(), IID_IDirectSoundBuffer8, buffer)))
        return false;
    if (!SferaSoundBackend::copyToBuffer(buffer.Get(), audio.pcm))
        return false;
    if ((description.dwFlags & DSBCAPS_CTRL3D) != 0u)
    {
        SferaSoundBackend::queryInterface(base.Get(), IID_IDirectSound3DBuffer, spatial_buffer);
    }
    return true;
}

std::uint32_t SferaSoundBackend::secondsToBytes(const WAVEFORMATEX &format, float seconds, std::size_t total_bytes)
{
    const std::size_t block_align = format.nBlockAlign;
    if (!std::isfinite(seconds) || seconds <= 0.0f || format.nAvgBytesPerSec == 0u || block_align == 0u || total_bytes < block_align)
    {
        return 0u;
    }

    const std::size_t aligned_size = total_bytes - total_bytes % block_align;
    const std::size_t last_block = aligned_size >= block_align ? aligned_size - block_align : 0u;
    const double raw = seconds * 1.0 * format.nAvgBytesPerSec;
    const auto bounded = SferaNumeric::truncateInt64(std::min(raw, static_cast<double>(last_block)));
    std::size_t value = bounded;
    value -= value % block_align;
    return static_cast<std::uint32_t>(std::min<std::size_t>(value, std::numeric_limits<std::uint32_t>::max()));
}

SferaSoundBufferMapping::SferaSoundBufferMapping(IDirectSoundBuffer8 &buffer, DWORD bytes) : buffer_(&buffer)
{
    auto result = lock(bytes);
    if (result == DSERR_BUFFERLOST && SUCCEEDED(buffer_->Restore()))
        result = lock(bytes);
    locked_ = SUCCEEDED(result);
}

bool SferaSoundBufferMapping::copy(std::span<const std::uint8_t> source) const noexcept
{
    if (!locked_ || first_size_ > source.size() || second_size_ != source.size() - first_size_ || (first_size_ && !first_) || (second_size_ && !second_))
        return false;
    if (first_size_)
        std::memcpy(first_, source.data(), first_size_);
    if (second_size_)
        std::memcpy(second_, source.data() + first_size_, second_size_);
    return true;
}

bool SferaSoundBufferMapping::close() noexcept
{
    if (!std::exchange(locked_, false))
        return true;
    return SUCCEEDED(buffer_->Unlock(first_, first_size_, second_, second_size_));
}

static std::unique_ptr<CSoundInterface> g_interface;

static bool g_hardware_mixing = false;

static int g_stream_volume = 100;

CSoundListener::CSoundListener() : impl_(std::make_unique<CSoundListenerImpl>())
{
}
CSoundListener::~CSoundListener() = default;

void CSoundListener::GetOrientation(SferaVec3F *forward, SferaVec3F *up) const
{
    if (forward != nullptr)
        *forward = impl_->forward;
    if (up != nullptr)
        *up = impl_->up;
}

int CSoundListener::SetPosition(float x, float y, float z, int deferred)
{
    position = {x, y, z};
    if (!impl_->native)
        return 1;
    return SUCCEEDED(impl_->native->SetPosition(x, y, z, SferaSoundBackend::applyMode(deferred))) ? 1 : 0;
}

int CSoundListener::SetVelocity(float x, float y, float z, int deferred)
{
    if (!impl_->native)
        return 1;
    return SUCCEEDED(impl_->native->SetVelocity(x, y, z, SferaSoundBackend::applyMode(deferred))) ? 1 : 0;
}

int CSoundListener::SetOrientation(const SferaVec3F &forward, const SferaVec3F &up, int deferred)
{
    impl_->forward = forward;
    impl_->up = up;
    if (!impl_->native)
        return 1;
    return SUCCEEDED(impl_->native->SetOrientation(forward.x, forward.y, forward.z, up.x, up.y, up.z, SferaSoundBackend::applyMode(deferred))) ? 1 : 0;
}

CSoundInterface::CSoundInterface() : impl_(std::make_unique<CSoundInterfaceImpl>())
{
}
CSoundInterface::~CSoundInterface() = default;

int CSoundInterface::UpdateSettings()
{
    const auto streams = impl_->streams;
    // A callback may close the entire interface. Everything used afterwards is a local lease.
    const auto nativeListener = listener ? listener->impl_->native : ComPtr<IDirectSound3DListener8>{};
    for (const auto &stream : streams)
        if (stream->impl_->registered)
            stream->update();
    if (nativeListener)
        nativeListener->CommitDeferredSettings();
    return 1;
}

CSound::CSound() : impl_(std::make_unique<CSoundImpl>())
{
}
CSound::~CSound()
{
    Stop();
}

int CSound::LoadSound(const std::string &source_filename, std::uint32_t flags)
{
    Stop();
    if (g_interface == nullptr || g_interface->impl_->device == nullptr)
        return 0;

    SferaDecodedAudio audio;
    if (!SferaSoundAudioDecoder::decodeAudioFile(source_filename, audio))
        return 0;
    const bool spatial = (flags & 1u) != 0u;
    ComPtr<IDirectSoundBuffer8> buffer;
    ComPtr<IDirectSound3DBuffer8> spatial_buffer;
    if (!SferaSoundBackend::createBuffer(g_interface->impl_->device.Get(), audio, spatial, g_hardware_mixing, buffer, spatial_buffer))
        return 0;

    filename = source_filename;
    impl_->audio = std::move(audio);
    impl_->buffer = std::move(buffer);
    impl_->spatial = std::move(spatial_buffer);
    impl_->spatial_requested = spatial;
    impl_->requested_position = 0.0f;
    duration_seconds = impl_->audio.format.nAvgBytesPerSec == 0u ? 0.0f : static_cast<float>(impl_->audio.pcm.size() * 1.0 / impl_->audio.format.nAvgBytesPerSec);
    SetVolume(impl_->volume);
    playback_finished = true;
    return 1;
}

int CSound::SetAllParameters(const SferaSound3DParameters *parameters, int deferred)
{
    if (parameters == nullptr)
        return 0;
    if (!impl_->spatial)
        return 1;

    DS3DBUFFER native{};
    native.dwSize = SferaNumeric::lowWord(sizeof(native));
    native.vPosition = {parameters->position.x, parameters->position.y, parameters->position.z};
    native.vConeOrientation = {parameters->cone_orientation.x, parameters->cone_orientation.y, parameters->cone_orientation.z};
    native.dwInsideConeAngle = parameters->inside_cone_angle;
    native.dwOutsideConeAngle = parameters->outside_cone_angle;
    native.flMinDistance = parameters->min_distance;
    native.flMaxDistance = parameters->max_distance;
    return SUCCEEDED(impl_->spatial->SetAllParameters(&native, SferaSoundBackend::applyMode(deferred))) ? 1 : 0;
}

int CSound::SetVolume(float gain)
{
    impl_->volume = SferaSoundBackend::normalizedGain(gain);
    if (!impl_->buffer)
        return 1;
    return SUCCEEDED(impl_->buffer->SetVolume(SferaSoundBackend::directSoundVolume(impl_->volume))) ? 1 : 0;
}

int CSound::Rewind()
{
    SetPlayTimepos(0.0f);
    return 1;
}

void CSound::Stop()
{
    if (impl_->buffer)
        impl_->buffer->Stop();
    playback_finished = true;
}

int CSound::SetPosition(float x, float y, float z, int deferred)
{
    if (!impl_->spatial)
        return 1;
    return SUCCEEDED(impl_->spatial->SetPosition(x, y, z, SferaSoundBackend::applyMode(deferred))) ? 1 : 0;
}

float CSound::GetPlayTimepos() const
{
    if (!impl_->buffer || impl_->audio.format.nAvgBytesPerSec == 0u)
        return impl_->requested_position;
    DWORD play = 0u;
    DWORD write = 0u;
    if (FAILED(impl_->buffer->GetCurrentPosition(&play, &write)))
        return impl_->requested_position;
    return static_cast<float>(play * 1.0 / impl_->audio.format.nAvgBytesPerSec);
}

int CSound::IsSoundPlaying() const
{
    if (!impl_->buffer)
        return 0;
    DWORD status = 0u;
    return SUCCEEDED(impl_->buffer->GetStatus(&status)) && (status & DSBSTATUS_PLAYING) != 0u ? 1 : 0;
}

void CSound::SetPlayTimepos(float seconds)
{
    if (!std::isfinite(seconds))
        seconds = 0.0f;
    impl_->requested_position = std::clamp(seconds, 0.0f, duration_seconds);
    if (impl_->buffer)
        impl_->buffer->SetCurrentPosition(SferaSoundBackend::secondsToBytes(impl_->audio.format, impl_->requested_position, impl_->audio.pcm.size()));
}

int CSound::Play(bool looped)
{
    if (!impl_->buffer)
        return 0;
    HRESULT result = impl_->buffer->SetCurrentPosition(SferaSoundBackend::secondsToBytes(impl_->audio.format, impl_->requested_position, impl_->audio.pcm.size()));
    if (result == DSERR_BUFFERLOST)
    {
        if (FAILED(impl_->buffer->Restore()) || !SferaSoundBackend::copyToBuffer(impl_->buffer.Get(), impl_->audio.pcm))
            return 0;
        result = impl_->buffer->SetCurrentPosition(SferaSoundBackend::secondsToBytes(impl_->audio.format, impl_->requested_position, impl_->audio.pcm.size()));
    }
    if (FAILED(result))
        return 0;
    SetVolume(impl_->volume);
    result = impl_->buffer->Play(0u, 0u, looped ? DSBPLAY_LOOPING : 0u);
    if (FAILED(result))
        return 0;
    playback_finished = false;
    return 1;
}

int CSound::SetVelocity(float x, float y, float z, int deferred)
{
    if (!impl_->spatial)
        return 1;
    return SUCCEEDED(impl_->spatial->SetVelocity(x, y, z, SferaSoundBackend::applyMode(deferred))) ? 1 : 0;
}

CSoundStream::CSoundStream() : impl_(std::make_unique<CSoundStreamImpl>())
{
}
CSoundStream::~CSoundStream()
{
    Stop();
}

void CSoundStream::SetDecodeSignal(float seconds)
{
    impl_->decode_signal = seconds;
    decode_event_position = seconds < 0.0f ? UINT32_MAX : SferaSoundBackend::secondsToBytes(impl_->audio.format, seconds, impl_->audio.pcm.size());
}

int CSoundStream::SeekToTime(float seconds)
{
    if (!impl_->buffer)
        return 0;
    const auto position = SferaSoundBackend::secondsToBytes(impl_->audio.format, seconds, impl_->audio.pcm.size());
    return SUCCEEDED(impl_->buffer->SetCurrentPosition(position)) ? 1 : 0;
}

void CSoundStream::SetPlaySignal(float seconds)
{
    impl_->play_signal = seconds;
    play_event_position = seconds < 0.0f ? UINT32_MAX : SferaSoundBackend::secondsToBytes(impl_->audio.format, seconds, impl_->audio.pcm.size());
}

void CSoundStream::Stop()
{
    if (impl_->buffer)
        impl_->buffer->Stop();
    impl_->was_playing = false;
}

int CSoundStream::IsStreamPlaying() const
{
    if (!impl_->buffer)
        return 0;
    DWORD status = 0u;
    return SUCCEEDED(impl_->buffer->GetStatus(&status)) && (status & DSBSTATUS_PLAYING) != 0u ? 1 : 0;
}

int CSoundStream::ReadyState()
{
    if (impl_->buffer)
        return 1;
    if (impl_->decode_failed)
        return -1;

    auto job = impl_->decode_job;
    if (job == nullptr)
        return 0;

    std::lock_guard lock(job->mutex);
    if (job->status == SferaStreamDecodeStatus::pending)
        return 0;
    if (job->status == SferaStreamDecodeStatus::failed || !job->buffer)
    {
        impl_->decode_job.reset();
        impl_->decode_failed = true;
        return -1;
    }

    impl_->audio = std::move(job->audio);
    impl_->buffer = std::move(job->buffer);
    impl_->decode_job.reset();
    applyVolume();
    return 1;
}

void CSoundStream::applyVolume()
{
    if (!impl_->buffer)
        return;
    const float local = SferaSoundBackend::normalizedGain(stream_gain);
    const float global = std::clamp(g_stream_volume, 0, 100) * 0.01f;
    impl_->buffer->SetVolume(SferaSoundBackend::directSoundVolume(local * global));
}

int CSoundStream::PlayEx(float seconds, int looped)
{
    if (!impl_->buffer)
        return 0;
    impl_->looped = looped != 0;
    const auto position = SferaSoundBackend::secondsToBytes(impl_->audio.format, seconds, impl_->audio.pcm.size());
    HRESULT result = impl_->buffer->SetCurrentPosition(position);
    if (result == DSERR_BUFFERLOST)
    {
        if (FAILED(impl_->buffer->Restore()) || !SferaSoundBackend::copyToBuffer(impl_->buffer.Get(), impl_->audio.pcm))
            return 0;
        result = impl_->buffer->SetCurrentPosition(position);
    }
    if (FAILED(result))
        return 0;
    applyVolume();
    result = impl_->buffer->Play(0u, 0u, impl_->looped ? DSBPLAY_LOOPING : 0u);
    impl_->was_playing = SUCCEEDED(result);
    return impl_->was_playing ? 1 : 0;
}

void CSoundStream::update()
{
    if (!impl_->buffer || impl_->audio.format.nAvgBytesPerSec == 0u)
        return;
    DWORD status = 0u;
    if (FAILED(impl_->buffer->GetStatus(&status)))
        return;
    const bool playing_now = (status & DSBSTATUS_PLAYING) != 0u;

    DWORD play_cursor = 0u;
    DWORD write_cursor = 0u;
    if (playing_now && FAILED(impl_->buffer->GetCurrentPosition(&play_cursor, &write_cursor)))
        return;
    if (!playing_now && !impl_->was_playing)
        return;

    const float current_time = static_cast<float>(playing_now ? play_cursor * 1.0 / impl_->audio.format.nAvgBytesPerSec : impl_->audio.pcm.size() * 1.0 / impl_->audio.format.nAvgBytesPerSec);

    const bool fire_decode = decode_callback != nullptr && decode_event_position != UINT32_MAX && current_time >= impl_->decode_signal;
    const bool fire_play = play_callback != nullptr && play_event_position != UINT32_MAX && current_time >= impl_->play_signal;

    if (fire_decode)
    {
        decode_event_position = UINT32_MAX;
        decoder_state = 1u;
        decode_callback(this, decode_state);
        decoder_state = 0u;
        if (!impl_->registered)
            return;
    }
    if (fire_play)
    {
        play_event_position = UINT32_MAX;
        play_callback(this, play_state);
        if (!impl_->registered)
            return;
    }

    if (!playing_now && impl_->was_playing)
    {
        const DWORD flags = impl_->looped ? DSBPLAY_LOOPING : 0u;
        if (FAILED(impl_->buffer->Play(0u, 0u, flags)))
            impl_->was_playing = false;
    }
}

void SI_SetHardwareMixing(bool enabled)
{
    g_hardware_mixing = enabled;
}

bool SI_GetHardwareMixing()
{
    return g_hardware_mixing;
}

int SI_GetStreamVolume()
{
    return g_stream_volume;
}

CSoundInterface *SI_CreateInterface(HWND__ *native_window, int, std::uint32_t sample_rate, std::uint32_t)
{
    const HWND window = native_window;
    if (g_interface != nullptr)
        return g_interface.get();

    auto sound_interface = std::make_unique<CSoundInterface>();
    if (FAILED(::DirectSoundCreate8(nullptr, sound_interface->impl_->device.GetAddressOf(), nullptr)))
        return nullptr;
    if (FAILED(sound_interface->impl_->device->SetCooperativeLevel(window, DSSCL_PRIORITY)))
        return nullptr;

    DSBUFFERDESC primary_description{};
    primary_description.dwSize = SferaNumeric::lowWord(sizeof(primary_description));
    primary_description.dwFlags = DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRL3D;
    if (FAILED(sound_interface->impl_->device->CreateSoundBuffer(&primary_description, sound_interface->impl_->primary.GetAddressOf(), nullptr)))
        return nullptr;

    WAVEFORMATEX primary_format{};
    primary_format.wFormatTag = WAVE_FORMAT_PCM;
    primary_format.nChannels = 2u;
    primary_format.nSamplesPerSec = sample_rate == 0u ? 44100u : sample_rate;
    primary_format.wBitsPerSample = 16u;
    primary_format.nBlockAlign = primary_format.nChannels * primary_format.wBitsPerSample / 8u;
    primary_format.nAvgBytesPerSec = primary_format.nSamplesPerSec * primary_format.nBlockAlign;
    sound_interface->impl_->primary->SetFormat(&primary_format);

    auto listener = std::make_unique<CSoundListener>();
    if (SUCCEEDED(SferaSoundBackend::queryInterface(sound_interface->impl_->primary.Get(), IID_IDirectSound3DListener, listener->impl_->native)))
    {
        listener->impl_->native->SetDistanceFactor(1.0f, DS3D_IMMEDIATE);
        listener->impl_->native->SetDopplerFactor(1.0f, DS3D_IMMEDIATE);
        listener->impl_->native->SetRolloffFactor(1.0f, DS3D_IMMEDIATE);
    }
    sound_interface->listener = listener.get();
    sound_interface->impl_->listener_owner = std::move(listener);
    g_interface = std::move(sound_interface);
    return g_interface.get();
}

CSoundInterface *SI_GetInterface()
{
    return g_interface.get();
}

void SI_Close()
{
    auto owner = std::move(g_interface);
    if (!owner)
        return;
    for (const auto &stream : owner->impl_->streams)
    {
        stream->impl_->registered = false;
        stream->decode_callback = nullptr;
        stream->play_callback = nullptr;
        stream->Stop();
    }
    owner->impl_->streams.clear();
}

void SI_SetLogFile(std::optional<std::string_view>)
{
}

void SI_SetStreamVolume(int percent)
{
    g_stream_volume = std::clamp(percent, 0, 100);
    if (g_interface == nullptr)
        return;
    for (const auto &stream : g_interface->impl_->streams)
    {
        if (stream != nullptr)
            stream->applyVolume();
    }
}

CSoundStream *SI_StreamCreateFile(const std::string &filename, std::uint32_t)
{
    if (filename.empty() || g_interface == nullptr || g_interface->impl_->device == nullptr)
        return nullptr;

    auto stream = std::shared_ptr<CSoundStream>(new CSoundStream());
    stream->impl_->decode_job = CSoundStream::streamDecodeWorker().enqueue(filename, g_interface->impl_->device, g_hardware_mixing);
    stream->decode_event_position = UINT32_MAX;
    stream->play_event_position = UINT32_MAX;
    g_interface->impl_->streams.push_back(stream);
    return stream.get();
}

void SI_StreamFree(CSoundStream *stream)
{
    if (stream == nullptr || !g_interface)
        return;
    auto &streams = g_interface->impl_->streams;
    auto entry = streams.begin();
    while (entry != streams.end() && entry->get() != stream)
    {
        ++entry;
    }
    if (entry == streams.end())
        return;
    (*entry)->impl_->registered = false;
    (*entry)->decode_callback = nullptr;
    (*entry)->play_callback = nullptr;
    (*entry)->Stop();
    streams.erase(entry);
}

SferaStreamDecodeWorker &CSoundStream::streamDecodeWorker()
{
    static SferaStreamDecodeWorker worker;
    return worker;
}

std::shared_ptr<SferaStreamDecodeState> SferaStreamDecodeWorker::enqueue(std::string filename, ComPtr<IDirectSound8> device, bool hardware_mixing)
{
    auto state = std::make_shared<SferaStreamDecodeState>();
    {
        std::lock_guard lock(mutex_);
        tasks_.push_front({std::move(filename), std::move(device), hardware_mixing, state});
    }
    condition_.notify_one();
    return state;
}

void SferaStreamDecodeWorker::run(std::stop_token stop)
{
    const HRESULT com_result = ::CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    for (;;)
    {
        SferaStreamDecodeTask task;
        {
            std::unique_lock lock(mutex_);
            condition_.wait(lock, stop, std::bind(&SferaStreamDecodeWorker::hasTasks, this));
            if (stop.stop_requested())
                break;
            task = std::move(tasks_.front());
            tasks_.pop_front();
        }

        auto state = task.state.lock();
        if (state == nullptr)
            continue;

        SferaDecodedAudio audio;
        const bool decoded = SferaSoundAudioDecoder::decodeAudioFile(task.filename, audio);
        ComPtr<IDirectSoundBuffer8> buffer;
        ComPtr<IDirectSound3DBuffer8> unused;
        const bool created = decoded && state.use_count() > 1u && SferaSoundBackend::createBuffer(task.device.Get(), audio, false, task.hardware_mixing, buffer, unused);

        std::lock_guard state_lock(state->mutex);
        if (created)
        {
            state->audio = std::move(audio);
            state->buffer = std::move(buffer);
            state->status = SferaStreamDecodeStatus::ready;
        }
        else
        {
            state->status = SferaStreamDecodeStatus::failed;
        }
    }
    if (SUCCEEDED(com_result))
        ::CoUninitialize();
}
