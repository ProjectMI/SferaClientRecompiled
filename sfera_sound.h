#pragma once

#include <cstdint>
#include <memory>

struct SferaSoundVec3 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

struct SferaSound3DParameters {
    SferaSoundVec3 position{};
    SferaSoundVec3 cone_orientation{0.0f, 0.0f, -1.0f};
    std::uint32_t inside_cone_angle = 360u;
    std::uint32_t outside_cone_angle = 360u;
    float min_distance = 1.0f;
    float max_distance = 1000000000.0f;
};

class CSoundInterface;
class CSoundStream;
using SferaSoundStreamCallback = std::uint32_t (*)(CSoundStream* stream, void* state) noexcept;

class CSoundListener {
public:
    CSoundListener();
    ~CSoundListener();

    CSoundListener(const CSoundListener&) = delete;
    CSoundListener& operator=(const CSoundListener&) = delete;

    void GetOrientation(SferaSoundVec3* forward, SferaSoundVec3* up) const;
    int SetPosition(float x, float y, float z, int deferred);
    int SetVelocity(float x, float y, float z, int deferred);
    int SetOrientation(const SferaSoundVec3& forward, const SferaSoundVec3& up, int deferred);

    SferaSoundVec3 position{};

private:
    struct Impl;
    std::unique_ptr<Impl> impl_;
    friend class CSoundInterface;
    friend CSoundInterface* SI_CreateInterface(void*, int, std::uint32_t, std::uint32_t);
};

class CSoundInterface {
public:
    CSoundInterface();
    ~CSoundInterface();

    CSoundInterface(const CSoundInterface&) = delete;
    CSoundInterface& operator=(const CSoundInterface&) = delete;

    int UpdateSettings();
    CSoundListener* listener = nullptr;

private:
    struct Impl;
    std::unique_ptr<Impl> impl_;
    friend CSoundInterface* SI_CreateInterface(void*, int, std::uint32_t, std::uint32_t);
    friend void SI_Close();
    friend class CSound;
    friend class CSoundStream;
    friend CSoundStream* SI_StreamCreateFile(const char*, std::uint32_t);
    friend void SI_StreamFree(CSoundStream*);
    friend void SI_SetStreamVolume(int);
};

class CSound {
public:
    CSound();
    ~CSound();

    CSound(const CSound&) = delete;
    CSound& operator=(const CSound&) = delete;

    int SetAllParameters(const SferaSound3DParameters* parameters, int deferred);
    int LoadSound(const char* filename, std::uint32_t flags);
    int SetVolume(float gain);
    int Rewind();
    void Stop();
    int SetPosition(float x, float y, float z, int deferred);
    float GetPlayTimepos() const;
    int IsSoundPlaying() const;
    void SetPlayTimepos(float seconds);
    int Play(int looped);
    int SetVelocity(float x, float y, float z, int deferred);

    char* filename = nullptr;
    float duration_seconds = 0.0f;
    std::int32_t cache_lifetime_seconds = 0;
    std::uint64_t cache_idle_since = UINT64_MAX;
    bool cache_available = true;
    bool playback_finished = true;
    CSound* cache_next = nullptr;
    CSound* cache_previous = nullptr;

private:
    struct Impl;
    std::unique_ptr<Impl> impl_;
};

class CSoundStream {
public:
    ~CSoundStream();

    CSoundStream(const CSoundStream&) = delete;
    CSoundStream& operator=(const CSoundStream&) = delete;

    void SetDecodeSignal(float seconds);
    int SeekToTime(float seconds);
    void SetPlaySignal(float seconds);
    void Stop();
    int IsStreamPlaying() const;
    int PlayEx(float seconds, int looped);
    std::uint32_t decoder_state = 0u;
    SferaSoundStreamCallback decode_callback = nullptr;
    void* decode_state = nullptr;
    std::uint32_t decode_event_position = UINT32_MAX;
    SferaSoundStreamCallback play_callback = nullptr;
    void* play_state = nullptr;
    std::uint32_t play_event_position = UINT32_MAX;
    float stream_gain = 1.0f;

private:
    CSoundStream();
    struct Impl;
    std::unique_ptr<Impl> impl_;

    void update();
    void applyVolume();

    friend class CSoundInterface;
    friend CSoundStream* SI_StreamCreateFile(const char*, std::uint32_t);
    friend void SI_StreamFree(CSoundStream*);
    friend void SI_SetStreamVolume(int);
};

void SI_SetHardwareMixing(bool enabled);
bool SI_GetHardwareMixing();
int SI_GetStreamVolume();
CSoundInterface* SI_CreateInterface(void* native_window, int device_index, std::uint32_t sample_rate, std::uint32_t flags);
CSoundInterface* SI_GetInterface();
void SI_Close();
void SI_SetLogFile(const char* filename);
void SI_SetStreamVolume(int percent);
CSoundStream* SI_StreamCreateFile(const char* filename, std::uint32_t flags);
void SI_StreamFree(CSoundStream* stream);
