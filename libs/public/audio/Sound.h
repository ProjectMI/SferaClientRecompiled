#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <string_view>

#include "math/Vector.h"

struct HWND__;

struct SferaSound3DParameters;

struct SferaSound3DParameters
{
    SferaVec3F position{};
    SferaVec3F cone_orientation{0.0f, 0.0f, -1.0f};
    std::uint32_t inside_cone_angle = 360u;
    std::uint32_t outside_cone_angle = 360u;
    float min_distance = 1.0f;
    float max_distance = 1000000000.0f;
};

class CSound;

struct CSoundImpl;

class CSound
{
  public:
    CSound();
    ~CSound();

    CSound(const CSound &) = delete;
    CSound &operator=(const CSound &) = delete;

    int SetAllParameters(const SferaSound3DParameters *parameters, int deferred);
    int LoadSound(const std::string &filename, std::uint32_t flags);
    int SetVolume(float gain);
    int Rewind();
    void Stop();
    int SetPosition(float x, float y, float z, int deferred);
    float GetPlayTimepos() const;
    int IsSoundPlaying() const;
    void SetPlayTimepos(float seconds);
    int Play(bool looped);
    int SetVelocity(float x, float y, float z, int deferred);

    std::string filename;
    float duration_seconds = 0.0f;
    int cache_lifetime_seconds = 0;
    std::uint64_t cache_idle_since = UINT64_MAX;
    bool cache_available = true;
    bool playback_finished = true;

  private:
    std::unique_ptr<CSoundImpl> impl_;
};

class CSoundInterface;
class CSoundListener;
struct CSoundListenerImpl;

class CSoundListener
{
  public:
    CSoundListener();
    ~CSoundListener();

    CSoundListener(const CSoundListener &) = delete;
    CSoundListener &operator=(const CSoundListener &) = delete;

    void GetOrientation(SferaVec3F *forward, SferaVec3F *up) const;
    int SetPosition(float x, float y, float z, int deferred);
    int SetVelocity(float x, float y, float z, int deferred);
    int SetOrientation(const SferaVec3F &forward, const SferaVec3F &up, int deferred);

    SferaVec3F position{};

  private:
    std::unique_ptr<CSoundListenerImpl> impl_;
    friend class CSoundInterface;
    friend CSoundInterface *SI_CreateInterface(HWND__ *, int, std::uint32_t, std::uint32_t);
};

class CSoundStream;
struct CSoundStreamImpl;
class SferaStreamDecodeWorker;

using SferaSoundStreamCallback = std::uint32_t (*)(CSoundStream *stream, void *state) noexcept;

class CSoundStream
{
  public:
    ~CSoundStream();

    CSoundStream(const CSoundStream &) = delete;
    CSoundStream &operator=(const CSoundStream &) = delete;

    void SetDecodeSignal(float seconds);
    int SeekToTime(float seconds);
    void SetPlaySignal(float seconds);
    void Stop();
    int IsStreamPlaying() const;
    int ReadyState();
    int PlayEx(float seconds, int looped);
    std::uint32_t decoder_state = 0u;
    SferaSoundStreamCallback decode_callback = nullptr;
    void *decode_state = nullptr;
    std::uint32_t decode_event_position = UINT32_MAX;
    SferaSoundStreamCallback play_callback = nullptr;
    void *play_state = nullptr;
    std::uint32_t play_event_position = UINT32_MAX;
    float stream_gain = 1.0f;

  private:
    CSoundStream();
    std::unique_ptr<CSoundStreamImpl> impl_;

    static SferaStreamDecodeWorker &streamDecodeWorker();
    void update();
    void applyVolume();

    friend class CSoundInterface;
    friend CSoundStream *SI_StreamCreateFile(const std::string &, std::uint32_t);
    friend void SI_StreamFree(CSoundStream *);
    friend void SI_Close();
    friend void SI_SetStreamVolume(int);
};


struct CSoundInterfaceImpl;

class CSoundInterface
{
  public:
    CSoundInterface();
    ~CSoundInterface();

    CSoundInterface(const CSoundInterface &) = delete;
    CSoundInterface &operator=(const CSoundInterface &) = delete;

    int UpdateSettings();
    CSoundListener *listener = nullptr;

  private:
    std::unique_ptr<CSoundInterfaceImpl> impl_;
    friend CSoundInterface *SI_CreateInterface(HWND__ *, int, std::uint32_t, std::uint32_t);
    friend void SI_Close();
    friend class CSound;
    friend class CSoundStream;
    friend CSoundStream *SI_StreamCreateFile(const std::string &, std::uint32_t);
    friend void SI_StreamFree(CSoundStream *);
    friend void SI_SetStreamVolume(int);
};

void SI_SetHardwareMixing(bool enabled);
bool SI_GetHardwareMixing();
int SI_GetStreamVolume();
CSoundInterface *SI_CreateInterface(HWND__ *native_window, int device_index, std::uint32_t sample_rate, std::uint32_t flags);
CSoundInterface *SI_GetInterface();
void SI_Close();
void SI_SetLogFile(std::optional<std::string_view> filename);
void SI_SetLogFile(std::nullptr_t) = delete;
void SI_SetStreamVolume(int percent);
CSoundStream *SI_StreamCreateFile(const std::string &filename, std::uint32_t flags);
void SI_StreamFree(CSoundStream *stream);
// Use std::nullopt when no log file is requested.
