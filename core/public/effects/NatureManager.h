#pragma once

#include <array>
#include <cstdint>

#include "effects/ActiveEffect.h"
#include "effects/ParticleEffects.h"

class IEffect;
class LightingListener;
class NatureRainListener;

class NatureRainListener final : public IEffectListener
{
  public:
    NatureRainListener() = default;
    bool onEffectAttached(IEffect &effect, SferaActiveEffect &item, float distance) override;
    bool onEffectDetached(IEffect &effect, SferaActiveEffect &item) override;
    void onEffectChanged(std::uint32_t age_ticks, IEffect &effect, SferaActiveEffect &item) override;
};

class LightingListener final : public IEffectListener
{
  public:
    LightingListener() = default;
    bool onEffectAttached(IEffect &effect, SferaActiveEffect &item, float distance) override;
    bool onEffectDetached(IEffect &effect, SferaActiveEffect &item) override;
    void onEffectChanged(std::uint32_t age_ticks, IEffect &effect, SferaActiveEffect &item) override;
};

class CRainEffect;
class CScriptedEffect;
class SferaNatureAccess;
struct SferaNatureManager;

struct SferaNatureManager
{
    NatureRainListener rain_listener;
    LightingListener lighting_listener;
    CRainEffect *rain_effect = nullptr;
    float rain_intensity = 0.5f;
    float rain_scale = 0.0f;
    CScriptedEffect *lighting_effect = nullptr;
    float lighting_level = 0.5f;
    SferaActiveEffect *rain_effect_handle = nullptr;
    SferaActiveEffect *lighting_effect_handle = nullptr;
    std::array<SferaActiveEffect *, 3> ambient_rain_handles{};

    static void updateRain();
    static void updateLightning();
    bool initialize();
    void shutdown();
    void forgetEffect(const SferaActiveEffect &item);
    bool attachRainEffect(IEffect &effect);
    void detachRainEffect();
    bool attachLightingEffect(IEffect &effect);
    void detachLightingEffect()
    {
        lighting_effect = nullptr;
    }
    void onLightingEffectChanged(IEffect &effect, SferaActiveEffect &item);
    void startRain();
    void stopRain();
    void startLighting();
    void stopLighting()
    {
        remove_nature_effect_handle(lighting_effect_handle);
    }
    void setRainIntensity(float value);
    void setLightingLevel(float value);
    void updateAmbientRainEffects();

  private:
    static void updateNatureWeather(float value, bool &enabled, void (SferaNatureManager::*start)(), void (SferaNatureManager::*stop)(), void (SferaNatureManager::*apply)(float));
    static void remove_nature_effect_handle(SferaActiveEffect *&handle);
};

class SferaNatureAccess
{
  public:
    static SferaNatureManager *manager();
};

struct SferaBloodEffectListener : SferaBloodEffectRuntime, IEffectListener
{
    bool onEffectAttached(IEffect &effect, SferaActiveEffect &item, float distance) override
    {
        return distance <= 15.0f;
    }
    bool onEffectDetached(IEffect &effect, SferaActiveEffect &item) override
    {
        return true;
    }
    void onEffectChanged(std::uint32_t age_ticks, IEffect &effect, SferaActiveEffect &item) override;
};
