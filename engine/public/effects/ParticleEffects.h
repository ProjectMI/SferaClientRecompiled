#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include "audio/EffectVoice.h"
#include "effects/Effect.h"
#include "math/Color.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "render/VertexFormats.h"

struct SferaParserRange;
struct SferaParticleRenderSlot;
struct SferaParticleSettings;
struct SferaParticleState;
struct SferaParticleSystemDefinition;
struct SferaParticleSystemInstance;
struct SferaParticleSystemLink;
struct SferaParticleTextureFrame;
class SferaSimpleParser;

struct SferaParticleState
{
    SferaVec3F spawn_position{}, position{}, render_position{};
    SferaColor color{};
    float remaining_lifetime{}, total_lifetime{}, size{}, texture_frame{};
    std::uint32_t random_row{};
    std::uint16_t random_seed_0{}, random_seed_1{};
};

struct SferaParticleSettings
{
    const SferaEffectTrack *size_track{};
    const SferaEffectTrack *color_track{};
    const SferaEffectTrack *velocity_track{};
    const SferaEffectTrack *gravity_track{};
    int link_index = -1;
    SferaParticleState initial;
};

struct SferaParticleRenderSlot
{
    SferaParticleState state;
    const SferaParticleSettings *settings{};
    SferaParticleSystemInstance *linked_particle_system{};
};

struct SferaParticleSystemLink
{
    std::string target_name;
    std::size_t instance_count{};
    int target_index = -1;
};

struct SferaParticleTextureFrame
{
    std::string texture_name;
    std::array<float, 8> uv{0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f};
};

enum class SferaParticleSystemDefinitionShape
{
    Points,
    Line,
    Disk,
    Sphere,
    Box,
    Cylinder,
    Ring,
    Annulus
};

struct SferaParticleSystemDefinition
{
    std::string name;
    std::vector<SferaParticleSettings> particles;
    SferaParticleSystemDefinitionShape shape{};
    float radius{}, height{}, width{};
    int random_seed{}, random_factor{};
    SferaVec3F direction{};
    std::vector<SferaVec3F> shape_points;
    SferaVec3F emitter_position{};
    std::shared_ptr<const SferaEffectTrack> emission_track, emission_position_track;
    float emission_count{};
    std::uint32_t flags{};
    std::shared_ptr<const SferaEffectTrack> rotation_track, scale_track, position_track;
    std::shared_ptr<const SferaEffectTrack> lifetime_track;
    float lifetime_random_factor{}, lifetime{};
    std::shared_ptr<const SferaEffectTrack> power_track;
    float power = 1.0f;
    std::shared_ptr<const SferaEffectTrack> magnet_factor_track, magnet_position_track;
    int magnet_child_index = -1;
    SferaVec3F magnet_factor{}, magnet_position{}, distortion{};
    int self_illumination{};
    bool additive = false, custom_uv = false;
    std::array<SferaVec3F, 4> render_basis{{{1.0f, 1.0f, 1.0f}, {}, {}, {}}};
    std::vector<std::shared_ptr<const SferaEffectTrack>> size_tracks, color_tracks, velocity_tracks, gravity_tracks;
    std::vector<SferaParticleTextureFrame> texture_frames;
    float texture_animation_speed{};
    std::vector<SferaParticleSystemLink> links;

    bool loadDefinition(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range);

  private:
    static SferaParticleSystemDefinitionShape particle_shape(std::string_view name);
    static void load_track_array(SferaSimpleParser &parser, const SferaParserRange &range, std::string_view block_name, std::vector<std::shared_ptr<const SferaEffectTrack>> &tracks, bool color);

  private:
    static auto setupTracks(SferaSimpleParser &parser, const SferaParserRange &block, std::string_view count_name, auto &tracks);
    auto assignTrack(SferaSimpleParser &parser, const SferaParserRange &particle_range, const std::vector<std::uint8_t> &selected, std::string_view key, auto member, const auto &tracks);
};

struct SferaParticleSystemInstance
{
    std::shared_ptr<const SferaParticleSystemDefinition> definition;
    std::vector<SferaParticleRenderSlot> render_slots;
    std::vector<std::unique_ptr<SferaParticleSystemInstance>> children;
    std::vector<int> texture_ids;
    std::size_t active_particle_count{};
    float radius{}, height{}, width{}, emission_count{}, lifetime{}, power{}, emission_fraction{};
    SferaVec3F emitter_position{}, magnet_factor{}, magnet_position{};
    SferaVec3F current_position{}, previous_position{}, previous_origin{};
    SferaMatrix4x4F transform{};
    std::uint32_t runtime_random_row{}, runtime_random_seed_0{}, runtime_random_seed_1{};
    bool first_update = true, emitting = true, runtime_active = true, runtime_stop_requested = false;

    explicit SferaParticleSystemInstance(std::shared_ptr<const SferaParticleSystemDefinition> source);
    void initializeClone();
    void reset();
    void update(const SferaVec3F *spatial_frame, const SferaMatrix4x4F *world_frame, float age);
    void commit();

  private:
    void restoreSettings();

  private:
    static auto safeReciprocal(float value)
    {
        return value == 0.0f ? 0.0f : 1.0f / value;
    }
    static SferaVec3F reciprocal_magnet_factor(const SferaVec3F &source)
    {
        return {safeReciprocal(source.x), safeReciprocal(source.y), safeReciprocal(source.z)};
    }
    static void evaluate_magnet_factor(const SferaEffectTrack *track, float age, SferaVec3F &output, const std::uint16_t *values, std::uint32_t seed0, std::uint32_t seed1);
    static void particle_emit(SferaParticleSystemInstance &system, float delta);
    static void update_particle_children(SferaParticleSystemInstance &system, float age);
};

class CRainEffect;
struct SferaEffectInitializeContext;
struct SferaEffectRenderSlot;
struct SferaRainParticle;

struct SferaRainParticle
{
    SferaVec3F offset;
    float fall_speed;
    std::uint32_t alpha;
    float remaining_life;
    float initial_life;
    float half_width;
};

class CRainEffect : public IEffect
{
  public:
    CRainEffect *asRainEffect() noexcept override
    {
        return this;
    }
    const CRainEffect *asRainEffect() const noexcept override
    {
        return this;
    }
    int resource_id{};
    std::vector<SferaRainParticle> particles;
    float spawn_radius{};
    float spawn_radius_bias{};
    float spawn_rate{};
    float spawn_fraction{};
    CRainEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext &context) override;
    std::unique_ptr<IEffect> createEffectResources() override;
    ~CRainEffect() override;

  private:
    static void set_full_quad_uv(SferaEffectRenderSlot &slot);
};

class CBladeEffect;
class CGazerLakeEffect;
class CMolEffect;
class CSpiralEffect;
struct SferaEffectUpdateContext;
struct SferaGazerEffectSlot;

class CSpiralEffect : public IEffect
{
  public:
    int resource_id{};
    CSpiralEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext &context) override;
    std::unique_ptr<IEffect> createEffectResources() override;
};

class CMolEffect : public IEffect
{
  public:
    SferaVec3F anchor{};
    float texture_phase{};
    bool anchor_initialized{};
    int resource_id{};
    std::unique_ptr<IEffectVoice> sound_effect;
    bool sound_started{};
    CMolEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext &context) override;
    void updateEffect(const SferaEffectUpdateContext &context) override;
    bool activateEffect(bool visible) override
    {
        return visible;
    }
    void deactivateEffect(bool) override
    {
    }
    void renderEffect() override
    {
    }
    std::unique_ptr<IEffect> createEffectResources() override;
    ~CMolEffect() override;

  private:
    static void initialize_quad_slot(SferaEffectRenderSlot &slot, int resource_id, bool additive, bool custom_uv, int alpha);

  private:
    static float random_signed(float scale);
};

class CBladeEffect : public IEffect
{
  public:
    SferaVec3F anchor{};
    float progress{};
    bool anchor_initialized{};
    int resource_id{};
    CBladeEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext &context) override;
    std::unique_ptr<IEffect> createEffectResources() override;
};

struct SferaGazerEffectSlot
{
    std::unique_ptr<IEffect> effect;
    float age{};
    SferaVec3F offset{};
};

class CGazerLakeEffect : public IEffect
{
  public:
    std::uint32_t emission_tick{};
    std::size_t emission_period{};
    float radius{};
    std::array<SferaGazerEffectSlot, 16> slots;
    CGazerLakeEffect() = default;
    void initializePreset(std::uint32_t id, float effect_radius, std::size_t count);
    void initializeEffect(const SferaEffectInitializeContext &context) override;
    std::unique_ptr<IEffect> createEffectResources() override;
    ~CGazerLakeEffect() override;
};

class IEffect;
struct SferaBloodEffectRuntime;
struct SferaBloodSpot;

struct SferaBloodSpot
{
    float life{};
    std::size_t vertex_count{};
    SphereRenderPositionColorUvVertex vertices[90]{};
};

struct SferaBloodEffectRuntime
{
    void render();
    void createSpots(const SferaVec3F &center, float radius, std::span<const SferaVec3F> origins);
    SferaBloodSpot spots[30]{};
    std::size_t active_count{};
    float phase{};
    int texture_id{};

  private:
    static bool bloodTriangleOverlaps(const SferaVec3F *triangle, const SferaVec3F &center, float radius);
    static std::vector<SferaVec3F> collectBloodSceneTriangles(const SferaVec3F &center, float radius);
    static void createBloodSpot(SferaBloodEffectRuntime &runtime, const SferaVec3F &origin, std::span<const SferaVec3F> points);
};
