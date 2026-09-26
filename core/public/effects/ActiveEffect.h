#pragma once

#include <cstdint>
#include <memory>

#include "audio/SoundEffects.h"
#include "effects/Effect.h"
#include "math/Vector.h"

class IEffectListener;
struct SferaActiveEffect;
struct SferaEffectListenerEntry;

struct SferaActiveEffect
{
    std::uint16_t position_source{};
    std::uint16_t state_flags{};
    std::uint32_t source_handle{};
    std::uint32_t age_ticks{};
    SferaVec3F position{};

    std::shared_ptr<IEffect> definition;
    std::unique_ptr<IEffect> effect;
    std::unique_ptr<CSoundEffect> resource;
    bool sound_started{};
    std::uint32_t listener_key{};
    float viewer_distance{};
    bool active = false;
    bool removing = false;

    ~SferaActiveEffect();
};

class IEffectListener
{
  public:
    std::uint32_t change_tick{};
    virtual bool onEffectAttached(IEffect &effect, SferaActiveEffect &item, float distance) = 0;
    virtual bool onEffectDetached(IEffect &effect, SferaActiveEffect &item) = 0;
    virtual void onEffectChanged(std::uint32_t age_ticks, IEffect &effect, SferaActiveEffect &item) = 0;
};

struct SferaEffectListenerEntry
{
    std::uint32_t effect_id;
    IEffectListener *listener;
};
