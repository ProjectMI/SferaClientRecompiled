#pragma once

#include <windows.h>
#include <mmreg.h>
#include <dsound.h>

#include <condition_variable>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <memory>
#include <mutex>
#include <span>
#include <stop_token>
#include <thread>
#include <vector>

#include "audio/AudioDecoder.h"
#include "audio/Sound.h"
#include "math/Vector.h"
#include "platform/WindowsCom.h"

struct SferaStreamDecodeState;
struct SferaStreamDecodeTask;
class SferaStreamDecodeWorker;

enum class SferaStreamDecodeStatus : std::uint8_t
{
    pending,
    ready,
    failed
};

struct SferaStreamDecodeState
{
    std::mutex mutex;
    SferaStreamDecodeStatus status = SferaStreamDecodeStatus::pending;
    SferaDecodedAudio audio;
    ComPtr<IDirectSoundBuffer8> buffer;
};

struct SferaStreamDecodeTask
{
    std::string filename;
    ComPtr<IDirectSound8> device;
    bool hardware_mixing = false;
    std::weak_ptr<SferaStreamDecodeState> state;
};

class SferaStreamDecodeWorker
{
  public:
    SferaStreamDecodeWorker() : worker_(&SferaStreamDecodeWorker::runWorker, this)
    {
    }

    ~SferaStreamDecodeWorker()
    {
        worker_.request_stop();
        condition_.notify_all();
    }

    std::shared_ptr<SferaStreamDecodeState> enqueue(std::string filename, ComPtr<IDirectSound8> device, bool hardware_mixing);

  private:
    static void runWorker(std::stop_token stop, SferaStreamDecodeWorker *worker)
    {
        worker->run(stop);
    }

    bool hasTasks() const
    {
        return !tasks_.empty();
    }

    void run(std::stop_token stop);

    std::mutex mutex_;
    std::condition_variable_any condition_;
    std::deque<SferaStreamDecodeTask> tasks_;
    std::jthread worker_;
};

struct SferaDecodedAudio;
class SferaSoundBackend;
class SferaSoundBufferMapping;

class SferaSoundBackend
{
  public:
    template <typename T> static HRESULT queryInterface(IUnknown *source, REFIID interface_id, ComPtr<T> &target)
    {
        target.Reset();
        if (source == nullptr)
            return E_POINTER;
        return source->QueryInterface(interface_id, reinterpret_cast<void **>(target.GetAddressOf()));
    }
    static DWORD applyMode(int deferred)
    {
        return deferred == 0 ? DS3D_IMMEDIATE : DS3D_DEFERRED;
    }
    static float normalizedGain(float gain);
    static LONG directSoundVolume(float gain);
    static bool createBuffer(IDirectSound8 *device, const SferaDecodedAudio &audio, bool spatial, bool hardware_mixing, ComPtr<IDirectSoundBuffer8> &buffer,
                             ComPtr<IDirectSound3DBuffer8> &spatial_buffer);
    static std::uint32_t secondsToBytes(const WAVEFORMATEX &format, float seconds, std::size_t total_bytes);
    static bool copyToBuffer(IDirectSoundBuffer8 *buffer, const std::vector<std::uint8_t> &pcm);
};

class SferaSoundBufferMapping
{
  public:
    explicit SferaSoundBufferMapping(IDirectSoundBuffer8 &buffer, DWORD bytes);
    SferaSoundBufferMapping(const SferaSoundBufferMapping &) = delete;
    SferaSoundBufferMapping &operator=(const SferaSoundBufferMapping &) = delete;
    ~SferaSoundBufferMapping()
    {
        close();
    }
    bool copy(std::span<const std::uint8_t> source) const noexcept;
    bool close() noexcept;

  private:
    HRESULT lock(DWORD bytes) noexcept
    {
        first_ = second_ = nullptr;
        first_size_ = second_size_ = 0;
        return buffer_->Lock(0, bytes, &first_, &first_size_, &second_, &second_size_, DSBLOCK_ENTIREBUFFER);
    }
    IDirectSoundBuffer8 *buffer_;
    void *first_ = nullptr;
    void *second_ = nullptr;
    DWORD first_size_ = 0;
    DWORD second_size_ = 0;
    bool locked_ = false;
};

struct CSoundImpl;
struct CSoundInterfaceImpl;
struct CSoundListenerImpl;
struct CSoundStreamImpl;

struct CSoundListenerImpl
{
    ComPtr<IDirectSound3DListener8> native;
    SferaVec3F forward{0.0f, 0.0f, 1.0f};
    SferaVec3F up{0.0f, 1.0f, 0.0f};
};

struct CSoundInterfaceImpl
{
    ComPtr<IDirectSound8> device;
    ComPtr<IDirectSoundBuffer> primary;
    std::unique_ptr<CSoundListener> listener_owner;
    // Registry ownership; update snapshots keep callbacks alive across unregister.
    std::vector<std::shared_ptr<CSoundStream>> streams;
};

struct CSoundImpl
{
    SferaDecodedAudio audio;
    ComPtr<IDirectSoundBuffer8> buffer;
    ComPtr<IDirectSound3DBuffer8> spatial;
    float volume = 1.0f;
    float requested_position = 0.0f;
    bool spatial_requested = false;
};

struct CSoundStreamImpl
{
    SferaDecodedAudio audio;
    ComPtr<IDirectSoundBuffer8> buffer;
    std::shared_ptr<SferaStreamDecodeState> decode_job;
    float decode_signal = -1.0f;
    float play_signal = -1.0f;
    bool was_playing = false;
    bool looped = false;
    bool registered = true;
    bool decode_failed = false;
};
