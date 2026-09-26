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
#include "effects/ParticleEffects.h"
#include "math/Color.h"
#include "math/Matrix.h"
#include "math/Vector.h"

struct SferaEffectMeshDefinition;
struct SferaEffectMeshInstance;
struct SferaEffectMeshResource;
struct SferaEffectMeshResourceFace;
struct SferaParserRange;
class SferaSimpleParser;

struct SferaEffectMeshResourceFace
{
    std::array<std::size_t, 4> vertices{}, uv{};
};

struct SferaEffectMeshResource
{
    std::string name;
    std::vector<SferaVec3F> vertices;
    std::vector<std::array<float, 2>> uv;
    std::vector<SferaEffectMeshResourceFace> faces;
    std::vector<SferaColor> colors;

  private:
    friend struct SferaEffectMeshResourceFace;
};

struct SferaEffectMeshDefinition
{
    std::string name;
    std::shared_ptr<const SferaEffectMeshResource> mesh_resource;
    std::uint32_t flags{};
    std::shared_ptr<const SferaEffectTrack> rotation_track, scale_track, position_track;
    std::shared_ptr<const SferaEffectTrack> ucoord_track, vcoord_track, color_track;
    SferaColor color = SferaColor::rgba(255u, 255u, 255u);
    int self_illumination = 255;
    std::string texture_name;
    bool additive = false;
    bool custom_uv = false;

    bool loadDefinition(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range);
    std::size_t renderSlotCount() const;

  private:
    static std::shared_ptr<const SferaEffectMeshResource> find_mesh_resource(std::string_view name);

  private:
    static bool meshResourceNamed(std::string_view name, const std::shared_ptr<const SferaEffectMeshResource> &resource);
};

struct SferaEffectMeshInstance
{
    std::shared_ptr<const SferaEffectMeshDefinition> definition;
    std::vector<SferaVec3F> transformed_vertices;
    std::vector<std::array<float, 2>> translated_uv;
    std::vector<SferaColor> transformed_colors;
    float u_offset{}, v_offset{};
    SferaColor color{};
    std::uint32_t random_row{}, random_offset{}, random_state{};
    SferaVec3F runtime_position{};
    SferaMatrix4x4F transform{};
    int texture_id = -1;

    explicit SferaEffectMeshInstance(std::shared_ptr<const SferaEffectMeshDefinition> source);
    void reset();
    void update(const SferaVec3F *spatial_frame, const SferaMatrix4x4F *world_frame, float age);
    void commit();
};

class CLightEffect;
struct SferaEffectInitializeContext;
struct SferaLightDefinition;
class SferaLightInstance;

struct SferaLightDefinition
{
    std::shared_ptr<const SferaEffectTrack> position_track, color_track, alpha_track;
    SferaVec3F position{};
    std::array<float, 4> color{255.0f, 255.0f, 255.0f, 255.0f};
    bool randomize_color = false, vary_brightness = false;
    std::array<int, 6> random_color{};
    float brightness = 1.0f, brightness_delta{};
    std::uint8_t brightness_frequency = 1, attach_mode{};
    bool load(SferaSimpleParser &parser, const SferaParserRange &range);
};

class SferaLightInstance
{
  public:
    std::shared_ptr<const SferaLightDefinition> definition;
    SferaVec3F position{};
    std::array<float, 4> color{};
    int light_index = -1;
    std::uint64_t brightness_tick{};
    explicit SferaLightInstance(std::shared_ptr<const SferaLightDefinition> source);
    SferaLightInstance(const SferaLightInstance &) = delete;
    SferaLightInstance &operator=(const SferaLightInstance &) = delete;
    SferaLightInstance(SferaLightInstance &&source) noexcept;
    SferaLightInstance &operator=(SferaLightInstance &&) = delete;
    ~SferaLightInstance();
    void reset();
    void update(const SferaVec3F &base_position, float age, std::uint32_t opacity);
    void stop() noexcept;
};

class CLightEffect : public IEffect
{
  public:
    float color[4]{};
    float radius{};
    bool registered{};
    int light_index = -1;
    float brightness_jitter{};
    std::uint8_t brightness_frequency{};

    std::uint64_t brightness_tick{};
    CLightEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext &context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override
    {
        if (deactivated)
            deactivated = false;
    }
    std::unique_ptr<IEffect> createEffectResources() override;
    void setParameters(std::span<const SferaEffectParameter> parameters) override;
    ~CLightEffect() override;

  private:
    void applyParameterValue(const auto &value);
    template <std::size_t Index = 0> void dispatchParameter(const SferaEffectParameter &parameter);
};

class CScriptedEffect;
struct CScriptedEffectDefinition;
struct SferaEffectQueryContext;
struct SferaEffectUpdateContext;
struct SferaSubeffectDefinition;

enum class SferaSubeffectDefinitionKind
{
    ParticleSystem,
    Mesh
};

struct SferaSubeffectDefinition
{
    std::ptrdiff_t definition_index{};
    SferaSubeffectDefinitionKind kind{};
    std::size_t attach_mode{};
};

struct CScriptedEffectDefinition
{
    std::vector<SferaSubeffectDefinition> subeffects;
    std::vector<std::shared_ptr<const SferaEffectMeshDefinition>> meshes;
    std::vector<std::shared_ptr<const SferaLightDefinition>> lights;
    std::vector<std::shared_ptr<const SferaParticleSystemDefinition>> particles;
    std::shared_ptr<const IEffectVoiceDefinition> sound;
    bool update_visible_only = true, completes_immediately = false;
    std::uint32_t work_time_min = UINT32_MAX, work_time_max{}, sleep_time_min = UINT32_MAX, sleep_time_max{};
};

class CScriptedEffect : public IEffect
{
  public:
    CScriptedEffect *asScriptedEffect() noexcept override
    {
        return this;
    }
    const CScriptedEffect *asScriptedEffect() const noexcept override
    {
        return this;
    }

    std::shared_ptr<const CScriptedEffectDefinition> definition;
    std::vector<std::unique_ptr<CScriptedEffect>> pooled_instances;
    std::vector<SferaEffectMeshInstance> meshes;
    std::vector<SferaLightInstance> lights;
    std::vector<std::unique_ptr<SferaParticleSystemInstance>> particle_systems;
    std::unique_ptr<IEffectVoice> sound_effect;
    bool sound_started = false, work_phase_active = false;
    std::uint32_t phase_ticks_remaining{};

    void initializeScriptedState()
    {
        initializeBaseState(IEffectKind::Scripted);
    }
    bool loadScript(const std::string &filename);
    void resetRuntimeState();
    void initializeEffect(const SferaEffectInitializeContext &context) override;
    void updateEffect(const SferaEffectUpdateContext &context) override;
    void queryEffectState(const SferaEffectQueryContext &context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    std::unique_ptr<IEffect> createEffectResources() override;
    void recycleEffect(std::unique_ptr<IEffect> effect) noexcept override;
    void stopResources() noexcept;
    bool isEffectComplete() const override;
    ~CScriptedEffect() override;

  private:
    friend struct CScriptedEffectDefinition;

  private:
    static void initialize_scripted_phase(CScriptedEffect &effect);
    static void prepare_particle_definition(const std::shared_ptr<SferaParticleSystemDefinition> &definition);

  private:
    static auto findDefinitionIndex(const auto &definitions, std::string_view name) -> int;
    static auto loadDefinitionBlocks(SferaSimpleParser &parser, std::string_view name, const SferaParserRange *scope, auto load);
    static auto addRenderSlotBudget(CScriptedEffect &parsed, std::size_t kExpandedParticleSlotSafetyLimit, std::size_t slots);
    static auto resetParticleChildren(SferaParticleSystemInstance &parent) -> void;
    auto buildParticleChildren(SferaParticleSystemInstance &parent) -> void;
    static void loadMeshDefinitionBlock(const std::string &filename, SferaSimpleParser &parser, CScriptedEffect &parsed, std::size_t kExpandedParticleSlotSafetyLimit,
                                        const std::shared_ptr<CScriptedEffectDefinition> &data, const SferaParserRange &block);
    static void loadParticleDefinitionBlock(const std::string &filename, SferaSimpleParser &parser, std::vector<std::shared_ptr<SferaParticleSystemDefinition>> &particles,
                                            const SferaParserRange &block);
    static void loadLightDefinitionBlock(const std::string &filename, SferaSimpleParser &parser, const std::shared_ptr<CScriptedEffectDefinition> &data, const SferaParserRange &light_range);
};
