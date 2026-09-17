#include "sfera_sound.h"
#include "sfera_vorbis.h"

#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <wrl/client.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <io.h>
#include <utility>
#include <vector>

namespace {
using Microsoft::WRL::ComPtr;

template <typename T>
HRESULT queryInterface(IUnknown* source, REFIID interface_id, ComPtr<T>& target) {
    target.Reset();
    if (source == nullptr) return E_POINTER;
    return source->QueryInterface(
        interface_id,
        reinterpret_cast<void**>(target.GetAddressOf()));
}

struct DecodedAudio {
    WAVEFORMATEX format{};
    std::vector<std::uint8_t> pcm;
};

std::unique_ptr<CSoundInterface> g_interface;
bool g_hardware_mixing = false;
int g_stream_volume = 100;

std::uint16_t readU16(const std::uint8_t* value) {
    return static_cast<std::uint16_t>(value[0]) |
        static_cast<std::uint16_t>(static_cast<std::uint16_t>(value[1]) << 8u);
}

std::uint32_t readU32(const std::uint8_t* value) {
    return static_cast<std::uint32_t>(value[0]) |
        (static_cast<std::uint32_t>(value[1]) << 8u) |
        (static_cast<std::uint32_t>(value[2]) << 16u) |
        (static_cast<std::uint32_t>(value[3]) << 24u);
}

bool readBinaryFile(const char* filename, std::vector<std::uint8_t>& bytes) {
    if (filename == nullptr || *filename == '\0') return false;
    FILE* file = nullptr;
    if (::fopen_s(&file, filename, "rb") != 0 || file == nullptr) return false;
    struct FileCloser {
        FILE* file;
        ~FileCloser() { if (file != nullptr) std::fclose(file); }
    } close{file};

    if (::_fseeki64(file, 0, SEEK_END) != 0) return false;
    const std::int64_t file_size = ::_ftelli64(file);
    if (file_size <= 0 || static_cast<std::uint64_t>(file_size) > std::numeric_limits<std::size_t>::max() ||
        ::_fseeki64(file, 0, SEEK_SET) != 0) {
        return false;
    }

    bytes.resize(static_cast<std::size_t>(file_size));
    return std::fread(bytes.data(), 1u, bytes.size(), file) == bytes.size();
}

bool decodePcmWave(const std::vector<std::uint8_t>& bytes, DecodedAudio& output) {
    if (bytes.size() < 12u || std::memcmp(bytes.data(), "RIFF", 4u) != 0 ||
        std::memcmp(bytes.data() + 8u, "WAVE", 4u) != 0) {
        return false;
    }

    WAVEFORMATEX format{};
    bool have_format = false;
    const std::uint8_t* audio_data = nullptr;
    std::size_t audio_size = 0u;
    for (std::size_t offset = 12u; offset + 8u <= bytes.size();) {
        const auto* chunk = bytes.data() + offset;
        const std::size_t chunk_size = readU32(chunk + 4u);
        const std::size_t data_offset = offset + 8u;
        if (data_offset > bytes.size() || chunk_size > bytes.size() - data_offset) return false;
        if (std::memcmp(chunk, "fmt ", 4u) == 0 && chunk_size >= 16u) {
            const auto* value = bytes.data() + data_offset;
            format.wFormatTag = readU16(value);
            format.nChannels = readU16(value + 2u);
            format.nSamplesPerSec = readU32(value + 4u);
            format.nAvgBytesPerSec = readU32(value + 8u);
            format.nBlockAlign = readU16(value + 12u);
            format.wBitsPerSample = readU16(value + 14u);
            format.cbSize = 0u;
            have_format = format.wFormatTag == WAVE_FORMAT_PCM;
        } else if (std::memcmp(chunk, "data", 4u) == 0) {
            audio_data = bytes.data() + data_offset;
            audio_size = chunk_size;
        }
        offset = data_offset + chunk_size + (chunk_size & 1u);
    }

    if (!have_format || audio_data == nullptr || audio_size == 0u || format.nBlockAlign == 0u ||
        format.nAvgBytesPerSec == 0u) {
        return false;
    }
    audio_size -= audio_size % format.nBlockAlign;
    if (audio_size == 0u || audio_size > std::numeric_limits<DWORD>::max()) return false;
    output.format = format;
    output.pcm.assign(audio_data, audio_data + audio_size);
    return true;
}

bool decodeVorbis(const std::vector<std::uint8_t>& bytes, DecodedAudio& output) {
    if (bytes.size() < 4u || std::memcmp(bytes.data(), "OggS", 4u) != 0) return false;

    SferaVorbisPcm decoded;
    if (!sferaDecodeVorbis(bytes.data(), bytes.size(), decoded)) return false;
    if (decoded.channels == 0u || decoded.channels > 2u || decoded.sample_rate == 0u || decoded.samples.empty()) {
        return false;
    }

    const std::uint32_t block_align = static_cast<std::uint32_t>(decoded.channels) * sizeof(std::int16_t);
    const std::uint64_t bytes_per_second = static_cast<std::uint64_t>(decoded.sample_rate) * block_align;
    const std::uint64_t pcm_size = static_cast<std::uint64_t>(decoded.samples.size()) * sizeof(std::int16_t);
    if (block_align > std::numeric_limits<WORD>::max() ||
        bytes_per_second > std::numeric_limits<DWORD>::max() ||
        pcm_size == 0u || pcm_size > std::numeric_limits<DWORD>::max()) {
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
    output.pcm.resize(static_cast<std::size_t>(pcm_size));
    std::memcpy(output.pcm.data(), decoded.samples.data(), output.pcm.size());
    return true;
}

bool decodeAudioFile(const char* filename, DecodedAudio& output) {
    std::vector<std::uint8_t> bytes;
    if (!readBinaryFile(filename, bytes)) return false;
    if (decodePcmWave(bytes, output)) return true;
    return decodeVorbis(bytes, output);
}

DWORD applyMode(int deferred) {
    return deferred == 0 ? DS3D_IMMEDIATE : DS3D_DEFERRED;
}

float normalizedGain(float gain) {
    if (!std::isfinite(gain) || gain <= 0.0f) return 0.0f;
    if (gain > 1.0f) gain *= 0.01f;
    return std::clamp(gain, 0.0f, 1.0f);
}

LONG directSoundVolume(float gain) {
    gain = normalizedGain(gain);
    if (gain <= 0.00001f) return DSBVOLUME_MIN;
    const double units = 2000.0 * std::log10(static_cast<double>(gain));
    return static_cast<LONG>(std::clamp<long>(static_cast<long>(std::lround(units)), DSBVOLUME_MIN, DSBVOLUME_MAX));
}

bool copyToBuffer(IDirectSoundBuffer8* buffer, const std::vector<std::uint8_t>& pcm) {
    if (buffer == nullptr || pcm.empty()) return false;
    void* first = nullptr;
    void* second = nullptr;
    DWORD first_size = 0u;
    DWORD second_size = 0u;
    HRESULT result = buffer->Lock(0u, static_cast<DWORD>(pcm.size()), &first, &first_size, &second, &second_size, DSBLOCK_ENTIREBUFFER);
    if (result == DSERR_BUFFERLOST) {
        if (FAILED(buffer->Restore())) return false;
        result = buffer->Lock(0u, static_cast<DWORD>(pcm.size()), &first, &first_size, &second, &second_size, DSBLOCK_ENTIREBUFFER);
    }
    if (FAILED(result)) return false;
    if (first != nullptr && first_size != 0u) std::memcpy(first, pcm.data(), first_size);
    if (second != nullptr && second_size != 0u) std::memcpy(second, pcm.data() + first_size, second_size);
    buffer->Unlock(first, first_size, second, second_size);
    return true;
}

bool createBuffer(IDirectSound8* device, const DecodedAudio& audio, bool spatial, ComPtr<IDirectSoundBuffer8>& buffer, ComPtr<IDirectSound3DBuffer8>& spatial_buffer) {
    if (device == nullptr || audio.pcm.empty()) return false;
    DSBUFFERDESC description{};
    description.dwSize = sizeof(description);
    description.dwBufferBytes = static_cast<DWORD>(audio.pcm.size());
    description.lpwfxFormat = const_cast<WAVEFORMATEX*>(&audio.format);
    description.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_GETCURRENTPOSITION2 | DSBCAPS_GLOBALFOCUS;
    if (spatial && audio.format.nChannels == 1u) {
        description.dwFlags |= DSBCAPS_CTRL3D | DSBCAPS_MUTE3DATMAXDISTANCE;
    }
    description.dwFlags |= g_hardware_mixing ? DSBCAPS_LOCHARDWARE : DSBCAPS_LOCSOFTWARE;

    ComPtr<IDirectSoundBuffer> base;
    HRESULT result = device->CreateSoundBuffer(&description, &base, nullptr);
    if (FAILED(result) && g_hardware_mixing) {
        description.dwFlags &= ~DSBCAPS_LOCHARDWARE;
        description.dwFlags |= DSBCAPS_LOCSOFTWARE;
        result = device->CreateSoundBuffer(&description, &base, nullptr);
    }
    if (FAILED(result)) return false;
    if (FAILED(queryInterface(base.Get(), IID_IDirectSoundBuffer8, buffer))) return false;
    if (!copyToBuffer(buffer.Get(), audio.pcm)) return false;
    if ((description.dwFlags & DSBCAPS_CTRL3D) != 0u) {
        queryInterface(base.Get(), IID_IDirectSound3DBuffer, spatial_buffer);
    }
    return true;
}

std::uint32_t secondsToBytes(const WAVEFORMATEX& format, float seconds, std::size_t total_bytes) {
    const std::size_t block_align = format.nBlockAlign;
    if (!std::isfinite(seconds) || seconds <= 0.0f || format.nAvgBytesPerSec == 0u ||
        block_align == 0u || total_bytes < block_align) {
        return 0u;
    }

    const std::size_t aligned_size = total_bytes - total_bytes % block_align;
    const std::size_t last_block = aligned_size >= block_align ? aligned_size - block_align : 0u;
    const double raw = static_cast<double>(seconds) * format.nAvgBytesPerSec;
    std::size_t value = static_cast<std::size_t>(std::min<double>(raw, static_cast<double>(last_block)));
    value -= value % block_align;
    return static_cast<std::uint32_t>(std::min<std::size_t>(value, std::numeric_limits<std::uint32_t>::max()));
}

char* duplicateFilename(const char* filename) {
    if (filename == nullptr) return nullptr;
    const std::size_t length = std::strlen(filename) + 1u;
    auto* copy = static_cast<char*>(std::malloc(length));
    if (copy != nullptr) std::memcpy(copy, filename, length);
    return copy;
}
}

struct CSoundListener::Impl {
    ComPtr<IDirectSound3DListener8> native;
    SferaSoundVec3 forward{0.0f, 0.0f, 1.0f};
    SferaSoundVec3 up{0.0f, 1.0f, 0.0f};
};

struct CSoundInterface::Impl {
    ComPtr<IDirectSound8> device;
    ComPtr<IDirectSoundBuffer> primary;
    std::unique_ptr<CSoundListener> listener_owner;
    std::vector<CSoundStream*> streams;
};

struct CSound::Impl {
    DecodedAudio audio;
    ComPtr<IDirectSoundBuffer8> buffer;
    ComPtr<IDirectSound3DBuffer8> spatial;
    float volume = 1.0f;
    float requested_position = 0.0f;
    bool spatial_requested = false;
};

struct CSoundStream::Impl {
    DecodedAudio audio;
    ComPtr<IDirectSoundBuffer8> buffer;
    float decode_signal = -1.0f;
    float play_signal = -1.0f;
    bool was_playing = false;
    bool looped = false;
};

CSoundListener::CSoundListener() : impl_(std::make_unique<Impl>()) {}
CSoundListener::~CSoundListener() = default;

void CSoundListener::GetOrientation(SferaSoundVec3* forward, SferaSoundVec3* up) const {
    if (forward != nullptr) *forward = impl_->forward;
    if (up != nullptr) *up = impl_->up;
}

int CSoundListener::SetPosition(float x, float y, float z, int deferred) {
    position = {x, y, z};
    if (!impl_->native) return 1;
    return SUCCEEDED(impl_->native->SetPosition(x, y, z, applyMode(deferred))) ? 1 : 0;
}

int CSoundListener::SetVelocity(float x, float y, float z, int deferred) {
    if (!impl_->native) return 1;
    return SUCCEEDED(impl_->native->SetVelocity(x, y, z, applyMode(deferred))) ? 1 : 0;
}

int CSoundListener::SetOrientation(const SferaSoundVec3& forward, const SferaSoundVec3& up, int deferred) {
    impl_->forward = forward;
    impl_->up = up;
    if (!impl_->native) return 1;
    return SUCCEEDED(impl_->native->SetOrientation(forward.x, forward.y, forward.z, up.x, up.y, up.z, applyMode(deferred))) ? 1 : 0;
}

CSoundInterface::CSoundInterface() : impl_(std::make_unique<Impl>()) {}
CSoundInterface::~CSoundInterface() = default;

int CSoundInterface::UpdateSettings() {
    for (auto* stream : impl_->streams) {
        if (stream != nullptr) stream->update();
    }
    if (listener != nullptr && listener->impl_->native) {
        listener->impl_->native->CommitDeferredSettings();
    }
    return 1;
}

CSound::CSound() : impl_(std::make_unique<Impl>()) {}
CSound::~CSound() {
    Stop();
    std::free(filename);
    filename = nullptr;
}

int CSound::LoadSound(const char* source_filename, std::uint32_t flags) {
    Stop();
    if (g_interface == nullptr || g_interface->impl_->device == nullptr) return 0;

    DecodedAudio audio;
    if (!decodeAudioFile(source_filename, audio)) return 0;
    const bool spatial = (flags & 1u) != 0u;
    ComPtr<IDirectSoundBuffer8> buffer;
    ComPtr<IDirectSound3DBuffer8> spatial_buffer;
    if (!createBuffer(g_interface->impl_->device.Get(), audio, spatial, buffer, spatial_buffer)) return 0;

    char* copied_filename = duplicateFilename(source_filename);
    if (copied_filename == nullptr) return 0;
    std::free(filename);
    filename = copied_filename;
    impl_->audio = std::move(audio);
    impl_->buffer = std::move(buffer);
    impl_->spatial = std::move(spatial_buffer);
    impl_->spatial_requested = spatial;
    impl_->requested_position = 0.0f;
    duration_seconds = impl_->audio.format.nAvgBytesPerSec == 0u ? 0.0f : static_cast<float>(static_cast<double>(impl_->audio.pcm.size()) / impl_->audio.format.nAvgBytesPerSec);
    SetVolume(impl_->volume);
    playback_finished = true;
    return 1;
}

int CSound::SetAllParameters(const SferaSound3DParameters* parameters, int deferred) {
    if (parameters == nullptr) return 0;
    if (!impl_->spatial) return 1;

    DS3DBUFFER native{};
    native.dwSize = sizeof(native);
    native.vPosition = {parameters->position.x, parameters->position.y, parameters->position.z};
    native.vConeOrientation = {
        parameters->cone_orientation.x,
        parameters->cone_orientation.y,
        parameters->cone_orientation.z};
    native.dwInsideConeAngle = parameters->inside_cone_angle;
    native.dwOutsideConeAngle = parameters->outside_cone_angle;
    native.flMinDistance = parameters->min_distance;
    native.flMaxDistance = parameters->max_distance;
    return SUCCEEDED(impl_->spatial->SetAllParameters(&native, applyMode(deferred))) ? 1 : 0;
}

int CSound::SetVolume(float gain) {
    impl_->volume = normalizedGain(gain);
    if (!impl_->buffer) return 1;
    return SUCCEEDED(impl_->buffer->SetVolume(directSoundVolume(impl_->volume))) ? 1 : 0;
}

int CSound::Rewind() {
    SetPlayTimepos(0.0f);
    return 1;
}

void CSound::Stop() {
    if (impl_->buffer) impl_->buffer->Stop();
    playback_finished = true;
}

int CSound::SetPosition(float x, float y, float z, int deferred) {
    if (!impl_->spatial) return 1;
    return SUCCEEDED(impl_->spatial->SetPosition(x, y, z, applyMode(deferred))) ? 1 : 0;
}

float CSound::GetPlayTimepos() const {
    if (!impl_->buffer || impl_->audio.format.nAvgBytesPerSec == 0u) return impl_->requested_position;
    DWORD play = 0u;
    DWORD write = 0u;
    if (FAILED(impl_->buffer->GetCurrentPosition(&play, &write))) return impl_->requested_position;
    return static_cast<float>(static_cast<double>(play) / impl_->audio.format.nAvgBytesPerSec);
}

int CSound::IsSoundPlaying() const {
    if (!impl_->buffer) return 0;
    DWORD status = 0u;
    return SUCCEEDED(impl_->buffer->GetStatus(&status)) && (status & DSBSTATUS_PLAYING) != 0u ? 1 : 0;
}

void CSound::SetPlayTimepos(float seconds) {
    if (!std::isfinite(seconds)) seconds = 0.0f;
    impl_->requested_position = std::clamp(seconds, 0.0f, duration_seconds);
    if (impl_->buffer) impl_->buffer->SetCurrentPosition(secondsToBytes(impl_->audio.format, impl_->requested_position, impl_->audio.pcm.size()));
}

int CSound::Play(int looped) {
    if (!impl_->buffer) return 0;
    HRESULT result = impl_->buffer->SetCurrentPosition(secondsToBytes(impl_->audio.format, impl_->requested_position, impl_->audio.pcm.size()));
    if (result == DSERR_BUFFERLOST) {
        if (FAILED(impl_->buffer->Restore()) || !copyToBuffer(impl_->buffer.Get(), impl_->audio.pcm)) return 0;
        result = impl_->buffer->SetCurrentPosition(secondsToBytes(impl_->audio.format, impl_->requested_position, impl_->audio.pcm.size()));
    }
    if (FAILED(result)) return 0;
    SetVolume(impl_->volume);
    result = impl_->buffer->Play(0u, 0u, looped != 0 ? DSBPLAY_LOOPING : 0u);
    if (FAILED(result)) return 0;
    playback_finished = false;
    return 1;
}

int CSound::SetVelocity(float x, float y, float z, int deferred) {
    if (!impl_->spatial) return 1;
    return SUCCEEDED(impl_->spatial->SetVelocity(x, y, z, applyMode(deferred))) ? 1 : 0;
}

CSoundStream::CSoundStream() : impl_(std::make_unique<Impl>()) {}
CSoundStream::~CSoundStream() { Stop(); }

void CSoundStream::SetDecodeSignal(float seconds) {
    impl_->decode_signal = seconds;
    decode_event_position = seconds < 0.0f ? UINT32_MAX : secondsToBytes(impl_->audio.format, seconds, impl_->audio.pcm.size());
}

int CSoundStream::SeekToTime(float seconds) {
    if (!impl_->buffer) return 0;
    const auto position = secondsToBytes(impl_->audio.format, seconds, impl_->audio.pcm.size());
    return SUCCEEDED(impl_->buffer->SetCurrentPosition(position)) ? 1 : 0;
}

void CSoundStream::SetPlaySignal(float seconds) {
    impl_->play_signal = seconds;
    play_event_position = seconds < 0.0f ? UINT32_MAX : secondsToBytes(impl_->audio.format, seconds, impl_->audio.pcm.size());
}

void CSoundStream::Stop() {
    if (impl_->buffer) impl_->buffer->Stop();
    impl_->was_playing = false;
}

int CSoundStream::IsStreamPlaying() const {
    if (!impl_->buffer) return 0;
    DWORD status = 0u;
    return SUCCEEDED(impl_->buffer->GetStatus(&status)) && (status & DSBSTATUS_PLAYING) != 0u ? 1 : 0;
}

void CSoundStream::applyVolume() {
    if (!impl_->buffer) return;
    const float local = normalizedGain(stream_gain);
    const float global = std::clamp(g_stream_volume, 0, 100) * 0.01f;
    impl_->buffer->SetVolume(directSoundVolume(local * global));
}

int CSoundStream::PlayEx(float seconds, int looped) {
    if (!impl_->buffer) return 0;
    impl_->looped = looped != 0;
    const auto position = secondsToBytes(impl_->audio.format, seconds, impl_->audio.pcm.size());
    HRESULT result = impl_->buffer->SetCurrentPosition(position);
    if (result == DSERR_BUFFERLOST) {
        if (FAILED(impl_->buffer->Restore()) || !copyToBuffer(impl_->buffer.Get(), impl_->audio.pcm)) return 0;
        result = impl_->buffer->SetCurrentPosition(position);
    }
    if (FAILED(result)) return 0;
    applyVolume();
    result = impl_->buffer->Play(0u, 0u, impl_->looped ? DSBPLAY_LOOPING : 0u);
    impl_->was_playing = SUCCEEDED(result);
    return impl_->was_playing ? 1 : 0;
}

void CSoundStream::update() {
    if (!impl_->buffer || impl_->audio.format.nAvgBytesPerSec == 0u) return;
    DWORD status = 0u;
    if (FAILED(impl_->buffer->GetStatus(&status))) return;
    const bool playing_now = (status & DSBSTATUS_PLAYING) != 0u;

    DWORD play_cursor = 0u;
    DWORD write_cursor = 0u;
    if (playing_now && FAILED(impl_->buffer->GetCurrentPosition(&play_cursor, &write_cursor))) return;
    if (!playing_now && !impl_->was_playing) return;

    const float current_time = playing_now
        ? static_cast<float>(static_cast<double>(play_cursor) / impl_->audio.format.nAvgBytesPerSec)
        : static_cast<float>(static_cast<double>(impl_->audio.pcm.size()) / impl_->audio.format.nAvgBytesPerSec);

    const bool fire_decode = decode_callback != nullptr && decode_event_position != UINT32_MAX && current_time >= impl_->decode_signal;
    const bool fire_play = play_callback != nullptr && play_event_position != UINT32_MAX && current_time >= impl_->play_signal;

    if (fire_decode) {
        decode_event_position = UINT32_MAX;
        decoder_state = 1u;
        decode_callback(this, decode_state);
        decoder_state = 0u;
    }
    if (fire_play) {
        play_event_position = UINT32_MAX;
        play_callback(this, play_state);
    }

    if (!playing_now && impl_->was_playing) {
        const DWORD flags = impl_->looped ? DSBPLAY_LOOPING : 0u;
        if (FAILED(impl_->buffer->Play(0u, 0u, flags))) impl_->was_playing = false;
    }
}

void SI_SetHardwareMixing(bool enabled) {
    g_hardware_mixing = enabled;
}

bool SI_GetHardwareMixing() {
    return g_hardware_mixing;
}

int SI_GetStreamVolume() {
    return g_stream_volume;
}

CSoundInterface* SI_CreateInterface(void* native_window, int, std::uint32_t sample_rate, std::uint32_t) {
    const HWND window = static_cast<HWND>(native_window);
    if (g_interface != nullptr) return g_interface.get();

    auto sound_interface = std::make_unique<CSoundInterface>();
    if (FAILED(::DirectSoundCreate8(nullptr, sound_interface->impl_->device.GetAddressOf(), nullptr))) return nullptr;
    if (FAILED(sound_interface->impl_->device->SetCooperativeLevel(window, DSSCL_PRIORITY))) return nullptr;

    DSBUFFERDESC primary_description{};
    primary_description.dwSize = sizeof(primary_description);
    primary_description.dwFlags = DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRL3D;
    if (FAILED(sound_interface->impl_->device->CreateSoundBuffer(&primary_description, sound_interface->impl_->primary.GetAddressOf(), nullptr))) return nullptr;

    WAVEFORMATEX primary_format{};
    primary_format.wFormatTag = WAVE_FORMAT_PCM;
    primary_format.nChannels = 2u;
    primary_format.nSamplesPerSec = sample_rate == 0u ? 44100u : sample_rate;
    primary_format.wBitsPerSample = 16u;
    primary_format.nBlockAlign = static_cast<WORD>(primary_format.nChannels * primary_format.wBitsPerSample / 8u);
    primary_format.nAvgBytesPerSec = primary_format.nSamplesPerSec * primary_format.nBlockAlign;
    sound_interface->impl_->primary->SetFormat(&primary_format);

    auto listener = std::make_unique<CSoundListener>();
    if (SUCCEEDED(queryInterface(
            sound_interface->impl_->primary.Get(),
            IID_IDirectSound3DListener,
            listener->impl_->native))) {
        listener->impl_->native->SetDistanceFactor(1.0f, DS3D_IMMEDIATE);
        listener->impl_->native->SetDopplerFactor(1.0f, DS3D_IMMEDIATE);
        listener->impl_->native->SetRolloffFactor(1.0f, DS3D_IMMEDIATE);
    }
    sound_interface->listener = listener.get();
    sound_interface->impl_->listener_owner = std::move(listener);
    g_interface = std::move(sound_interface);
    return g_interface.get();
}

CSoundInterface* SI_GetInterface() {
    return g_interface.get();
}

void SI_Close() {
    if (g_interface != nullptr) {
        auto streams = g_interface->impl_->streams;
        g_interface->impl_->streams.clear();
        for (auto* stream : streams) delete stream;
        g_interface.reset();
    }
}

void SI_SetLogFile(const char*) {}

void SI_SetStreamVolume(int percent) {
    g_stream_volume = std::clamp(percent, 0, 100);
    if (g_interface == nullptr) return;
    for (auto* stream : g_interface->impl_->streams) {
        if (stream != nullptr) stream->applyVolume();
    }
}

CSoundStream* SI_StreamCreateFile(const char* filename, std::uint32_t) {
    if (g_interface == nullptr || g_interface->impl_->device == nullptr) return nullptr;
    DecodedAudio audio;
    if (!decodeAudioFile(filename, audio)) return nullptr;

    ComPtr<IDirectSoundBuffer8> buffer;
    ComPtr<IDirectSound3DBuffer8> unused;
    if (!createBuffer(g_interface->impl_->device.Get(), audio, false, buffer, unused)) return nullptr;

    auto stream = std::unique_ptr<CSoundStream>(new CSoundStream());
    stream->impl_->audio = std::move(audio);
    stream->impl_->buffer = std::move(buffer);
    stream->decode_event_position = UINT32_MAX;
    stream->play_event_position = UINT32_MAX;
    stream->applyVolume();
    auto* result = stream.release();
    g_interface->impl_->streams.push_back(result);
    return result;
}

void SI_StreamFree(CSoundStream* stream) {
    if (stream == nullptr) return;
    if (g_interface != nullptr) {
        auto& streams = g_interface->impl_->streams;
        streams.erase(std::remove(streams.begin(), streams.end(), stream), streams.end());
    }
    delete stream;
}
