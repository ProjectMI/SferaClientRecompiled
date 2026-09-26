#pragma once

#include <memory>

struct SferaVec3F;
class IEffectVoice
{
  public:
    virtual ~IEffectVoice() = default;
    virtual void reset() = 0;
    virtual float startTime() const = 0;
    virtual void start(const SferaVec3F *frame, bool after_start_time) = 0;
    virtual void update(const SferaVec3F *frame, float age) = 0;
    virtual void stop() = 0;
    virtual bool isComplete() const = 0;
};
class IEffectVoiceDefinition
{
  public:
    virtual ~IEffectVoiceDefinition() = default;
    virtual std::unique_ptr<IEffectVoice> createVoice() const = 0;
};
