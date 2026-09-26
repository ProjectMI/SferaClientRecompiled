#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

#include "math/Color.h"
#include "math/Matrix.h"
#include "math/Vector.h"

struct SferaEffectParameter;
struct SferaEffectParameterColor;
struct SferaEffectParameterFrequency;
struct SferaEffectParameterJitter;
struct SferaEffectParameterRadius;

struct SferaEffectParameterColor
{
    std::array<std::uint16_t, 3> channels;
};

struct SferaEffectParameterRadius
{
    float value;
};

struct SferaEffectParameterJitter
{
    std::uint8_t value;
};

struct SferaEffectParameterFrequency
{
    std::uint8_t value;
};

struct SferaEffectParameter
{
    std::variant<std::monostate, SferaEffectParameterColor, SferaEffectParameterRadius, SferaEffectParameterJitter, SferaEffectParameterFrequency> value;

  private:
    friend struct SferaEffectParameterColor;
    friend struct SferaEffectParameterRadius;
    friend struct SferaEffectParameterJitter;
    friend struct SferaEffectParameterFrequency;
};

class CRainEffect;
class CScriptedEffect;
class IEffect;
class IEffectListener;
struct SferaEffectInitializeContext;
struct SferaEffectQueryContext;
struct SferaEffectUpdateContext;

enum class IEffectKind
{
    Preset,
    Scripted,
    Rain = 3
};

class IEffect
{
  public:
    std::string script_name{};
    std::uint32_t effect_id{};
    bool deactivated{};
    bool resources_released{};
    bool activation_blocked{};
    std::uint32_t cycle_length{};
    std::uint32_t lifetime_ticks{};
    float range_min{};
    float range_max{};
    IEffectKind effect_kind{};
    SferaVec3F position{};
    IEffectListener *listener{};
    float bounds_min[3]{};
    float bounds_max[3]{};
    bool spatial_gate_enabled{};
    std::size_t render_slot_budget{};

    IEffect() = default;
    void initializeBaseState(IEffectKind kind);
    void assignScriptName(std::string_view name)
    {
        script_name.assign(name);
    }
    virtual void initializeEffect(const SferaEffectInitializeContext &)
    {
    }
    virtual void updateEffect(const SferaEffectUpdateContext &)
    {
    }
    virtual void queryEffectState(const SferaEffectQueryContext &)
    {
    }
    virtual bool activateEffect(bool visible)
    {
        return visible;
    }
    virtual void deactivateEffect(bool)
    {
    }
    virtual void renderEffect()
    {
    }
    virtual std::unique_ptr<IEffect> createEffectResources() = 0;
    virtual void setParameters(std::span<const SferaEffectParameter>)
    {
    }
    virtual void resetEffect()
    {
    }
    virtual CScriptedEffect *asScriptedEffect() noexcept
    {
        return nullptr;
    }
    virtual const CScriptedEffect *asScriptedEffect() const noexcept
    {
        return nullptr;
    }
    virtual CRainEffect *asRainEffect() noexcept
    {
        return nullptr;
    }
    virtual const CRainEffect *asRainEffect() const noexcept
    {
        return nullptr;
    }
    virtual void recycleEffect(std::unique_ptr<IEffect>) noexcept
    {
    }
    virtual bool isEffectComplete() const
    {
        return false;
    }
    virtual ~IEffect() = default;
};

class SferaEffectTrack;
struct SferaEffectTrackKey;
struct SferaEffectTrackKeyColor;
struct SferaEffectTrackKeyScalar;
struct SferaEffectTrackKeyVector;

enum class SferaEffectTrackKeyMode
{
    Fixed,
    Random,
    MirroredRandom
};

struct SferaEffectTrackKeyScalar
{
    float minimum{}, range{};
};

struct SferaEffectTrackKeyVector
{
    SferaVec3F minimum{}, range{};
};

struct SferaEffectTrackKeyColor
{
    SferaColor minimum{}, range{};
};

struct SferaEffectTrackKey
{
    float time{};
    SferaEffectTrackKeyMode mode{};
    std::variant<SferaEffectTrackKeyScalar, SferaEffectTrackKeyVector, SferaEffectTrackKeyColor> value{SferaEffectTrackKeyScalar{}};

  private:
    friend struct SferaEffectTrackKeyScalar;
    friend struct SferaEffectTrackKeyVector;
    friend struct SferaEffectTrackKeyColor;
};

class SferaEffectTrack
{
  public:
    std::vector<SferaEffectTrackKey> keys;
    bool cosine_interpolation{};

    std::pair<std::size_t, float> interval(float age, bool curved) const;
    void requireRandomCapacity(std::size_t samples) const;

    void evaluateVector(float age, SferaVec3F &output) const;
    void evaluateScalar(float age, float &output, std::span<const std::uint16_t> random_values = {}, std::uint32_t random_offset = 0u) const;

  private:
    static auto sampleScalar(const std::vector<SferaEffectTrackKey> &keys, std::span<const std::uint16_t> random_values, std::uint32_t random_offset, std::size_t index);
};

struct SferaColor;
class SferaEffectAlgorithms;
struct SferaMatrix4x4F;
struct SferaParticleSystemInstance;
struct SferaVec3F;

class SferaEffectAlgorithms
{
  public:
    static void build_y_up_billboard_axes(const SferaVec3F &view, float right_scale, float up_scale, SferaVec3F &right, SferaVec3F &up);
    static void evaluate_mesh_color(const SferaEffectTrack &track, float age, SferaColor &output, const std::uint16_t *random_values, std::uint32_t random_offset_0, std::uint32_t random_offset_1);
    static void evaluate_random_vector(const SferaEffectTrack *track, float age, SferaVec3F &output, const std::uint16_t *values, std::uint32_t seed0, std::uint32_t seed1);
    static void evaluate_particle_scalar(const SferaEffectTrack *track, float age, float &output, const std::uint16_t *values, std::uint32_t seed);
    static void apply_particle_rotation(SferaMatrix4x4F &transform, std::uint32_t flags, const SferaVec3F &rotation);
    static void particle_generate(SferaParticleSystemInstance &system, std::size_t index);

  private:
    static float particle_random_unit(const std::uint16_t *values, std::size_t index, std::uint32_t offset);
    static SferaVec3F sample_random_vector_key(const SferaEffectTrackKey &key, const std::uint16_t *values, std::size_t key_index, std::uint32_t seed0, std::uint32_t seed1);
    static auto sampleMeshColor(const std::vector<SferaEffectTrackKey> &keys, const std::uint16_t *random_values, std::size_t index, std::uint32_t random_offset, std::uint8_t *value);
};

struct SferaEffectFrames;

struct SferaEffectUpdateContext
{
    const SferaVec3F *frame;
    float viewer_distance{};
};

struct SferaEffectQueryContext
{
    std::span<const SferaVec3F> frames;
    float age{};
};

struct SferaEffectFrames
{
    std::array<SferaVec3F, 5> positions{};
    std::array<SferaMatrix4x4F, 5> transforms{};
};

struct SferaEffectInitializeContext
{
    std::span<const SferaVec3F> spatial_frames;
    float age{};
    bool visible{};
    std::span<const SferaMatrix4x4F> world_frames;
};
