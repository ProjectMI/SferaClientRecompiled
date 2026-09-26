#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <limits>
#include <list>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <system_error>
#include <vector>

#include "effects/ActiveEffect.h"
#include "effects/Effect.h"
#include "effects/EffectRendering.h"
#include "effects/NatureManager.h"
#include "numeric/Numeric.h"

struct SferaLightRecord;
struct SferaEffectMeshResource;

class CBladeEffect;
class CD3D9Device;
class CGazerLakeEffect;
class CLightEffect;
class CMolEffect;
class CRainEffect;
class CSpiralEffect;
template <class Element> class DynamicStreamMapping;
class SferaBinaryReader;
struct SferaEffectManager;
struct SferaEffectManagerDiagnostics;

enum class SferaEffectManagerCreateFailure : std::size_t
{
    Stopping,
    Capacity,
    SoundUnavailable,
    MissingDefinition,
    Factory,
    FilteredType,
    InvalidSource,
    Listener,
    Allocation,
    Count
};
struct SferaEffectManagerDiagnostics : SferaEffectRenderStatistics
{
    std::uint32_t details_written{};
    std::uint64_t last_sample{}, samples{}, vm_requests{}, create_requests{}, created{};
    std::uint64_t updates{}, distance_culled{}, frustum_culled{}, activation_rejected{};
    std::uint64_t daytime_rejected{}, expired{};
    std::uint64_t light_activations{};
    std::array<std::uint64_t, SferaNumeric::enumBits(SferaEffectManagerCreateFailure::Count)> failures{};
};
enum class SferaEffectManagerFlareTransition
{
    Idle,
    FadeOut,
    FadeIn
};

struct SferaEffectManager : SferaEffectRenderState
{
    SferaEffectManagerDiagnostics diagnostics;

    void traceFailure(SferaEffectManagerCreateFailure failure, std::uint32_t effect, std::uint32_t source, std::optional<std::string_view> name = std::nullopt) noexcept;
    void traceFailure(SferaEffectManagerCreateFailure, std::uint32_t, std::uint32_t, std::nullptr_t) noexcept = delete;
    void traceEffect(std::string_view event, const SferaActiveEffect &item) noexcept;
    void writeDiagnostics() noexcept;
    bool rain_enabled{};
    bool lightning_enabled{};
    SferaActiveEffect *pending_effect{};

    uint32_t render_cycle{};
    bool effects_enabled{};
    std::vector<std::shared_ptr<const SferaEffectMeshResource>> mesh_resources;
    std::vector<std::shared_ptr<IEffect>> definitions;
    bool initialized{};
    std::list<std::shared_ptr<SferaActiveEffect>> active_effects;
    std::unique_ptr<SferaNatureManager> nature;
    std::unique_ptr<SferaBloodEffectListener> blood;
    bool shutting_down = false;
    bool updating = false;
    uint32_t generation{};
    uint32_t last_processed_generation{};

    SferaEffectManagerFlareTransition flare_transition{};
    bool flare_enabled{};
    int flare_alpha{};
    std::vector<SferaEffectListenerEntry> effect_listeners;

    void reportError(std::string_view message) const;
    using SferaEffectRenderState::viewerDistance;
    float viewerDistance(std::uint32_t source_handle) const;
    void appendDefinition(std::shared_ptr<IEffect> effect);
    std::shared_ptr<IEffect> findDefinition(uint32_t effect_id) const;
    std::shared_ptr<IEffect> findDefinition(std::string_view script_name) const;
    std::uint32_t findDefinitionId(std::string_view script_name) const;
    IEffectListener *findListener(uint32_t effect_id) const;
    bool registerListener(std::uint32_t effect_id, IEffectListener &listener);
    void unregisterListener(IEffectListener &listener);
    void clearListeners();
    void registerEffectMeshFile(const std::string &filename);
    void reportLoadProgress(std::uint32_t progress);
    void initializeBloodEffect();
    void shutdownBloodEffect();
    void loadDefinitions();
    void destroyDefinitions();
    void renderParticles();
    void drawFlare(int x, int y, int size, bool enabled);
    std::uint32_t listenerKey(const SferaActiveEffect *handle) const;
    bool removeActiveEffect(SferaActiveEffect *handle);
    bool initialize();
    void shutdown();
    SferaActiveEffect *createActiveEffect(std::uint32_t effect_id, std::uint32_t source_handle);
    SferaActiveEffect *createActiveEffect(std::string_view script_name, std::uint32_t source_handle);
    bool removeActiveEffect(SferaActiveEffect &item)
    {
        return removeActiveEffect(&item);
    }
    bool setEffectParameters(std::uint32_t source_handle, std::span<const SferaEffectParameter> parameters);
    void retireEffect(SferaActiveEffect &item);
    void updateActiveEffects();
    void updateActiveEffect(SferaActiveEffect &item, std::uint16_t state_flags, float viewer_distance);

  private:
    static void initialize_particle_random_table(SferaEffectManager &manager);
    template <class T, class Initializer> static void append_fixed_effect(SferaEffectManager &manager, Initializer initialize);

  private:
  private:
    static auto readMeshCoordinate(SferaBinaryReader &input);
    static auto readMeshIndices(SferaEffectMeshResource &resource, SferaBinaryReader &payload, auto member, std::size_t limit);
    static auto enumerateDefinitionFiles(std::error_code &error, const std::filesystem::path &directory, std::string_view extension, auto &&callback);
    auto loadDefinitionGroup(std::error_code &error, std::uint32_t &processed_count, std::uint32_t total_count, const std::filesystem::path &directory);

  private:
  private:
    static bool lightIsLive(const std::unique_ptr<SferaLightRecord> &light)
    {
        return light != nullptr;
    }
    void loadDefinitionFile(std::uint32_t &processed_count, std::uint32_t total_count, const std::filesystem::path &path);
    void registerDefinitionMesh(const std::filesystem::path &path);
    static void countDefinitionFile(std::uint32_t &total_count, const std::filesystem::path &)
    {
        ++total_count;
    }
    static void initializeLightDefinition(CLightEffect &effect);
    static void initializeSpiralDefinition(CSpiralEffect &effect);
    static void initializeMolDefinition(CMolEffect &effect);
    static void initializeBladeDefinition(CBladeEffect &effect);
    static void initializeRainDefinition(CRainEffect &effect);
    static void initializeLakeDefinition(std::uint32_t effect_id, std::size_t index, CGazerLakeEffect &effect);
};

extern SferaEffectManager g_sfera_effect_manager;

constexpr std::uint32_t kInvalidHandle = std::numeric_limits<std::uint32_t>::max();

constexpr std::uint16_t kUninitializedEffectState = std::numeric_limits<std::uint16_t>::max();

constexpr std::uint32_t kRainEffectId = 400u;

constexpr std::uint32_t kLightingEffectId = 410u;

constexpr std::uint32_t kBloodEffectId = 310u;

constexpr std::uint32_t kBloodEffectIdLast = 312u;

constexpr std::uint32_t kLakeEffectIdNear = 720u;

constexpr std::uint32_t kLakeEffectIdMiddle = 721u;

constexpr std::uint32_t kLakeEffectIdFar = 722u;

constexpr std::uint32_t kFixedLakeFlags = 16u;

constexpr std::uint32_t kSoundEffectIdBase = 5000u;

constexpr std::uint32_t kAmbientRainSoundId = 5050u;

constexpr std::uint32_t kLightingSoundFarId = 5051u;

constexpr std::uint32_t kLightingSoundNearId = 5052u;

constexpr std::size_t kMaximumActiveEffects = 6000u;

constexpr std::size_t kMaximumRenderSlots = 10000u;

constexpr std::uint32_t kVisibilityRefreshPeriod = 32u;

constexpr int kFlareAlphaStep = 35;

constexpr int kMaximumAlpha = 255;

class SferaGameEffectHost final : public SferaEffectHost
{
  public:
    static void bind(SferaEffectManager &manager);
    SferaEffectRenderState &renderState() override;
    void rejectRenderBudget() override;

  private:
    explicit SferaGameEffectHost(SferaEffectManager &manager);
    SferaEffectManager *manager;
};
