#pragma once

#include <winsock2.h>
#include <d3d9.h>
#include <wrl/client.h>
#include <mmsystem.h>
#include <cstdio>
#include <cstdarg>
#include <atomic>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <bit>
#include <io.h>
#include <iosfwd>
#include <chrono>
#include <filesystem>
#include <map>
#include <set>
#include <iterator>
#include <cmath>

struct IDirect3DTexture9;
struct IDirect3DBaseTexture9;
struct SferaScreenVertex;

#include <array>
#include <algorithm>
#include <cstring>
#include <type_traits>
#include <limits>
#include <memory>
#include <utility>
#include <optional>
#include <variant>
#include <cstddef>
#include <deque>
#include <list>
#include <span>
#include <string_view>
#include <unordered_set>
#include <cstdint>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <vector>

#include "semantic_window.h"

struct SferaTcpConnectionContext;
struct SferaMbcProcessRecord;
struct SferaScriptContainer;
class Contours;
class SkyEnvironment;
class EnvironmentZones;
struct SkyState;
namespace SphereRender { class CharacterModels; }

#include "semantic_types.h"

extern SferaPolygon3F g_sfera_clipped_polygon;

class SferaSimpleParser {
public:
    bool load(const std::string& filename);
    void assign(std::string source);
    bool findBlock(std::string_view name, SferaParserRange* output, const SferaParserRange* search, std::ptrdiff_t occurrence);
    std::ptrdiff_t countBlocks(std::string_view name, const SferaParserRange* search);
    bool findValue(std::string_view name, const SferaParserRange* search);
    void setScanRange(const SferaParserRange* range);
    void clearScanRange() { scan_ = {}; }
    bool nextValue(std::string_view name);
    void setBlockRange(const SferaParserRange* range);
    void clearBlockRange() { block_ = {}; }
    bool nextBlock(std::string_view name, SferaParserRange* output);
    void getBlockRange(SferaParserRange* output) const { *output = block_; }
    void getScanRange(SferaParserRange* output) const { *output = scan_; }
    std::string_view lineAt(std::ptrdiff_t index) const;
    const std::string& valueText() const { return token_; }
    std::size_t tokenCount() const;
    std::string_view tokenAt(std::size_t index) const;
    bool tryReadFloat(std::size_t index, float& output) const;
    bool tryReadInt(std::size_t index, int& output) const;
    bool readFloatSequence(std::size_t index, std::span<float> output) const;
    bool readIntSequence(std::size_t index, std::span<int> output) const;
    bool readVector(std::size_t index, SferaVec3F& output) const;
    float readFloat(std::size_t index) const;
    int readInt(std::size_t index) const;
    bool readString(std::size_t index, std::string& output) const;
    bool readQuotedString(std::size_t index, std::string& output) const;
    bool readBool(std::size_t index) const;

private:
    static constexpr std::size_t maximumValueLength = 1023;
    std::string source_;
    std::vector<std::size_t> lines_;
    std::string token_;
    SferaParserRange scan_{};
    SferaParserRange block_{};
    SferaParserRange boundedRange(const SferaParserRange* range) const;
    static std::string_view firstToken(std::string_view line);
    std::ptrdiff_t findClosingBrace(std::ptrdiff_t begin, std::ptrdiff_t end) const;
    std::ptrdiff_t parseBlockAt(std::string_view first, std::ptrdiff_t line, std::ptrdiff_t end, SferaParserRange* output);
    bool findValueFrom(std::string_view name, std::ptrdiff_t& line, std::ptrdiff_t end);
    std::size_t tokenStart(std::size_t index) const;
};

#include "sfera_sound_runtime.h"

struct SferaEffectRenderSlot {
    SferaVec3F position[4];
    std::uint32_t color[4][4];
    float uv[4][2];
    int resource_id;
    int self_illumination;
    bool additive;
    bool custom_uv;
};

struct SferaRainParticle {
    SferaVec3F offset;
    float fall_speed;
    std::uint32_t alpha;
    float remaining_life;
    float initial_life;
    float half_width;
};

struct SferaEffectParameter {
    struct Color { std::array<std::uint16_t, 3> channels; };
    struct Radius { float value; };
    struct Jitter { std::uint8_t value; };
    struct Frequency { std::uint8_t value; };
    std::variant<std::monostate, Color, Radius, Jitter, Frequency> value;
};

class SferaEffectTrack;
struct SferaParticleSystemInstance;

struct SferaEffectMeshResource {
    struct Face { std::array<std::size_t, 4> vertices{}, uv{}; };
    std::string name;
    std::vector<SferaVec3F> vertices;
    std::vector<std::array<float, 2>> uv;
    std::vector<Face> faces;
    std::vector<SferaColor> colors;
};

struct SferaEffectMeshDefinition {
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

    bool loadDefinition(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range);
    std::size_t renderSlotCount() const;
};

struct SferaEffectMeshInstance {
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
    void update(const SferaVec3F* spatial_frame, const SferaMatrix4x4F* world_frame, float age);
    void commit();
};

struct SferaParticleState {
    SferaVec3F spawn_position{}, position{}, render_position{};
    SferaColor color{};
    float remaining_lifetime{}, total_lifetime{}, size{}, texture_frame{};
    std::uint32_t random_row{};
    std::uint16_t random_seed_0{}, random_seed_1{};
};

struct SferaParticleSettings {
    const SferaEffectTrack* size_track{};
    const SferaEffectTrack* color_track{};
    const SferaEffectTrack* velocity_track{};
    const SferaEffectTrack* gravity_track{};
    int link_index = -1;
    SferaParticleState initial;
};

struct SferaParticleRenderSlot {
    SferaParticleState state;
    const SferaParticleSettings* settings{};
    SferaParticleSystemInstance* linked_particle_system{};
};

struct SferaParticleSystemLink {
    std::string target_name;
    std::size_t instance_count{};
    int target_index = -1;
};

struct SferaParticleTextureFrame {
    std::string texture_name;
    std::array<float, 8> uv{0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f};
};

struct SferaParticleSystemDefinition {
    enum class Shape { Points, Line, Disk, Sphere, Box, Cylinder, Ring, Annulus };
    std::string name;
    std::vector<SferaParticleSettings> particles;
    Shape shape{};
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

    bool loadDefinition(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range);
};

struct SferaParticleSystemInstance {
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
    void update(const SferaVec3F* spatial_frame, const SferaMatrix4x4F* world_frame, float age);
    void commit();
private:
    void restoreSettings();
};

struct SferaSubeffectDefinition {
    enum class Kind { ParticleSystem, Mesh };
    std::ptrdiff_t definition_index{};
    Kind kind{};
    std::uint8_t attach_mode{};
};

class IEffect;

struct SferaActiveEffect {
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

struct SferaLightDefinition {
    std::shared_ptr<const SferaEffectTrack> position_track, color_track, alpha_track;
    SferaVec3F position{};
    std::array<float, 4> color{255.0f, 255.0f, 255.0f, 255.0f};
    bool randomize_color = false, vary_brightness = false;
    std::array<int, 6> random_color{};
    float brightness = 1.0f, brightness_delta{};
    std::uint8_t brightness_frequency = 1, attach_mode{};
    bool load(SferaSimpleParser& parser, const SferaParserRange& range);
};

class SferaLightInstance {
public:
    std::shared_ptr<const SferaLightDefinition> definition;
    SferaVec3F position{};
    std::array<float, 4> color{};
    int light_index = -1;
    std::uint64_t brightness_tick{};
    explicit SferaLightInstance(std::shared_ptr<const SferaLightDefinition> source);
    SferaLightInstance(const SferaLightInstance&) = delete;
    SferaLightInstance& operator=(const SferaLightInstance&) = delete;
    SferaLightInstance(SferaLightInstance&& source) noexcept;
    SferaLightInstance& operator=(SferaLightInstance&&) = delete;
    ~SferaLightInstance();
    void reset();
    void update(const SferaVec3F& base_position, float age, std::uint32_t opacity);
    void stop() noexcept;
};

struct SferaEffectTrackKey {
    enum class Mode { Fixed, Random, MirroredRandom };
    struct Scalar { float minimum{}, range{}; };
    struct Vector { SferaVec3F minimum{}, range{}; };
    struct Color { SferaColor minimum{}, range{}; };
    float time{};
    Mode mode{};
    std::variant<Scalar, Vector, Color> value{Scalar{}};
};

class SferaEffectTrack {
public:
    std::vector<SferaEffectTrackKey> keys;
    bool cosine_interpolation{};

    std::pair<std::size_t, float> interval(float age, bool curved) const;
    void requireRandomCapacity(std::size_t samples) const;

    void evaluateVector(float age, SferaVec3F& output) const;
    void evaluateScalar(float age, float& output, std::span<const std::uint16_t> random_values = {}, std::uint32_t random_offset = 0u) const;
};

std::shared_ptr<const SferaEffectTrack> sfera_load_scalar_effect_track(SferaSimpleParser* parser, const SferaParserRange* range);
std::shared_ptr<const SferaEffectTrack> sfera_load_vector_effect_track(SferaSimpleParser* parser, const SferaParserRange* range);

struct SferaEffectUpdateContext {
    const SferaVec3F* frame;
    float viewer_distance{};
};

struct SferaEffectQueryContext {
    std::span<const SferaVec3F> frames;
    float age{};
};

struct SferaEffectFrames {
    std::array<SferaVec3F, 5> positions{};
    std::array<SferaMatrix4x4F, 5> transforms{};
};

struct SferaEffectInitializeContext {
    std::span<const SferaVec3F> spatial_frames;
    float age{};
    bool visible{};
    std::span<const SferaMatrix4x4F> world_frames;
};

class IEffectListener {
public:
    std::uint32_t change_tick{};
    virtual bool onEffectAttached(IEffect& effect, SferaActiveEffect& item, float distance) = 0;
    virtual bool onEffectDetached(IEffect& effect, SferaActiveEffect& item) = 0;
    virtual void onEffectChanged(std::uint32_t age_ticks, IEffect& effect, SferaActiveEffect& item) = 0;
};

struct SferaEffectListenerEntry { std::uint32_t effect_id; IEffectListener* listener; };

struct SferaBloodSpot {
    float life{};
    std::size_t vertex_count{};
    SphereRender::PositionColorUvVertex vertices[90]{};
};

struct SferaBloodEffectRuntime : IEffectListener {
    bool onEffectAttached(IEffect& effect, SferaActiveEffect& item, float distance) override;
    bool onEffectDetached(IEffect& effect, SferaActiveEffect& item) override;
    void onEffectChanged(std::uint32_t age_ticks, IEffect& effect, SferaActiveEffect& item) override;
    void render();
    SferaBloodSpot spots[30]{};
    std::size_t active_count{};
    float phase{};
    int texture_id{};
};

class IEffect {
public:
    enum class Kind { Preset, Scripted, Rain = 3 };
    std::string script_name{};
    std::uint32_t effect_id{};
    bool deactivated{};
    bool resources_released{};
    bool activation_blocked{};
    std::uint32_t cycle_length{};
    std::uint32_t lifetime_ticks{};
    float range_min{};
    float range_max{};
    Kind effect_kind{};
    SferaVec3F position{};
    IEffectListener* listener{};
    float bounds_min[3]{};
    float bounds_max[3]{};
    bool spatial_gate_enabled{};
    std::size_t render_slot_budget{};

    IEffect() = default;
    void initializeBaseState(Kind kind);
    void assignScriptName(std::string_view name);
    virtual void initializeEffect(const SferaEffectInitializeContext& context);
    virtual void updateEffect(const SferaEffectUpdateContext& context);
    virtual void queryEffectState(const SferaEffectQueryContext& context);
    virtual bool activateEffect(bool visible);
    virtual void deactivateEffect(bool preserve_resources);
    virtual void renderEffect();
    virtual std::unique_ptr<IEffect> createEffectResources() = 0;
    virtual void setParameters(std::span<const SferaEffectParameter> parameters);
    virtual void resetEffect();
    virtual void recycleEffect(std::unique_ptr<IEffect> effect) noexcept;
    virtual bool isEffectComplete() const;
    virtual ~IEffect() = default;
};

class CScriptedEffect : public IEffect {
public:
    struct Definition {
        std::vector<SferaSubeffectDefinition> subeffects;
        std::vector<std::shared_ptr<const SferaEffectMeshDefinition>> meshes;
        std::vector<std::shared_ptr<const SferaLightDefinition>> lights;
        std::vector<std::shared_ptr<const SferaParticleSystemDefinition>> particles;
        std::shared_ptr<const CSoundEffect::Definition> sound;
        bool update_visible_only = true, completes_immediately = false;
        std::uint32_t work_time_min = UINT32_MAX, work_time_max{}, sleep_time_min = UINT32_MAX, sleep_time_max{};
    };
    std::shared_ptr<const Definition> definition;
    std::vector<std::unique_ptr<CScriptedEffect>> pooled_instances;
    std::vector<SferaEffectMeshInstance> meshes;
    std::vector<SferaLightInstance> lights;
    std::vector<std::unique_ptr<SferaParticleSystemInstance>> particle_systems;
    std::unique_ptr<CSoundEffect> sound_effect;
    bool sound_started = false, work_phase_active = false;
    std::uint32_t phase_ticks_remaining{};

    void initializeScriptedState();
    bool loadScript(const std::string& filename);
    void resetRuntimeState();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    void queryEffectState(const SferaEffectQueryContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    std::unique_ptr<IEffect> createEffectResources() override;
    void recycleEffect(std::unique_ptr<IEffect> effect) noexcept override;
    void stopResources() noexcept;
    bool isEffectComplete() const override;
    ~CScriptedEffect() override;
};

class CSpiralEffect : public IEffect {
public:
    int resource_id{};
    CSpiralEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    std::unique_ptr<IEffect> createEffectResources() override;
};

class CMolEffect : public IEffect {
public:
    SferaVec3F anchor{};
    float texture_phase{};
    bool anchor_initialized{};
    int resource_id{};
    std::unique_ptr<CSoundEffect> sound_effect;
    bool sound_started{};
    CMolEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    std::unique_ptr<IEffect> createEffectResources() override;
    ~CMolEffect() override;
};

class CBladeEffect : public IEffect {
public:
    SferaVec3F anchor{};
    float progress{};
    bool anchor_initialized{};
    int resource_id{};
    CBladeEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    std::unique_ptr<IEffect> createEffectResources() override;
};

struct SferaGazerEffectSlot {
    std::unique_ptr<IEffect> effect;
    float age{};
    SferaVec3F offset{};
};

class CGazerLakeEffect : public IEffect {
public:
    std::uint32_t emission_tick{};
    std::size_t emission_period{};
    float radius{};
    std::array<SferaGazerEffectSlot, 16> slots;
    CGazerLakeEffect() = default;
    void initializePreset(std::uint32_t id, float effect_radius, std::size_t count);
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    std::unique_ptr<IEffect> createEffectResources() override;
    ~CGazerLakeEffect() override;
};

class CRainEffect : public IEffect {
public:
    int resource_id{};
    std::vector<SferaRainParticle> particles;
    float spawn_radius{};
    float spawn_radius_bias{};
    float spawn_rate{};
    float spawn_fraction{};
    CRainEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    std::unique_ptr<IEffect> createEffectResources() override;
    ~CRainEffect() override;
};

class CLightEffect : public IEffect {
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
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    std::unique_ptr<IEffect> createEffectResources() override;
    void setParameters(std::span<const SferaEffectParameter> parameters) override;
    ~CLightEffect() override;
};

class IOutputDevice {
public:
    virtual ~IOutputDevice() = default;
    virtual void write(std::string_view text) = 0;
};

class COutputLogDevice : public IOutputDevice {
public:
    std::string filename;
    void setFilename(const std::string& path);
    void write(std::string_view text) override;
};

class CSphereError : public IOutputDevice {
public:
    CSphereError() = default;
    void write(std::string_view text) override;
};

class GrassMapMngr {
public:
    GrassMapMngr() = default;
    virtual void loadGrassMap(int column, int row, std::span<std::uint8_t> destination);
    std::uint32_t grassType(float x, float z);
    std::uint32_t plantingType(float x, float z);
    GrassMapMngr* reset();
private:
    struct Tile { std::pair<int, int> key{}; std::uint64_t timestamp = 0; std::array<std::uint8_t, 65536> bytes{}; };
    std::uint8_t sample(float x, float z);
    std::unique_ptr<std::array<Tile, 10>> tiles_;
    std::uint64_t timestamp_ = 0;
};

struct PlayerListEntry {
    std::string name;
    SferaVec3F position{};
    std::array<int, 3> attributes{};
    std::vector<std::uint8_t> payload;
};

class PlayerList {
public:
    std::string name;
    std::size_t minimum_size{};
    std::uint32_t publish_mode{};
    bool notify_relationships = false;

    PlayerList(std::string name, std::size_t minimum, std::uint32_t mode, bool notify);
    PlayerListEntry* find(std::string_view key);
    PlayerListEntry* first();
    PlayerListEntry* next();
    int insert(PlayerListEntry value);
    int remove(std::string_view key);
    const PlayerListEntry* select(const std::array<int, 3>& filters);
    std::size_t size() const noexcept { return index_.size(); }
private:
    // Slot order is visible through L_FFITEM/L_FNITEM; erasure must leave a hole.
    std::vector<std::unique_ptr<PlayerListEntry>> entries_;
    std::map<std::string, std::size_t, std::less<>> index_;
    std::optional<std::size_t> cursor_ = 0;
    PlayerListEntry* scanFrom(std::size_t begin);
    void finishNotificationScan();
};

class PlayerLists {
public:
    int create(std::string_view name, int minimum, std::uint32_t mode, bool notify);
    int erase(std::string_view name);
    int removeItem(PlayerList& list, std::string_view key);
    PlayerList* find(std::string_view name) const;
    PlayerList* selectList(std::string_view name) { return current_ = find(name); }
    PlayerList* currentList() const noexcept { return current_; }
    void clear() noexcept;
private:
    std::map<std::string, std::unique_ptr<PlayerList>, std::less<>> lists_;
    PlayerList* current_ = nullptr;
};

class NatureRainListener final : public IEffectListener {
public:
    NatureRainListener() = default;
    bool onEffectAttached(IEffect& effect, SferaActiveEffect& item, float distance) override;
    bool onEffectDetached(IEffect& effect, SferaActiveEffect& item) override;
    void onEffectChanged(std::uint32_t age_ticks, IEffect& effect, SferaActiveEffect& item) override;
};

class LightingListener final : public IEffectListener {
public:
    LightingListener() = default;
    bool onEffectAttached(IEffect& effect, SferaActiveEffect& item, float distance) override;
    bool onEffectDetached(IEffect& effect, SferaActiveEffect& item) override;
    void onEffectChanged(std::uint32_t age_ticks, IEffect& effect, SferaActiveEffect& item) override;
};

struct SferaCursorPosition { int x; int y; };
class SferaInterfaceCursor {
public:
    struct ImageLayer {
        int x = 0;
        int y = 0;
        int texture = -1;
        int width = 0u;
        int height = 0u;
    };
    struct TextLayer {
        int x = 0;
        int y = 0;
        std::string text;
        int font = 0u;
        std::uint32_t color = 0u;
    };
    bool system_visible = true;
    bool centered_hotspot = false;
    std::uint8_t kind = 255u;
    SferaInterfaceCursor() = default;
    bool loadTextures();
    void setImage(std::size_t layer, std::optional<std::string_view> texture, int x, int y);
    void setImage(std::size_t, std::nullptr_t, int, int) = delete;
    void setImageSize(std::size_t layer, int width, int height);
    void setText(std::size_t layer, std::string_view text, int x, int y, int font, std::uint32_t color);
    void setKind(std::uint32_t cursor_kind);
    void draw(float x, float y) const;
private:
    std::array<int, 4> textures{};
    std::array<ImageLayer, 3> images{};
    std::array<TextLayer, 3> labels{};
};

class CCursor {
public:
    CCursor() = default;
    virtual ~CCursor() = default;
    virtual void copyStateFrom(const CCursor* previous) = 0;
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual void apply() = 0;
    virtual void updatePosition() = 0;
    virtual SferaCursorPosition* getPosition(SferaCursorPosition* output) const = 0;
    virtual void setPosition(int x, int y) = 0;
    virtual void show() = 0;
    virtual bool isInsideViewport() const = 0;
    virtual bool isSystemCursorVisible() const = 0;
    virtual void setSystemCursorVisible(bool visible) = 0;
    virtual std::uint32_t cursorKind() const = 0;
    virtual void setCursorKind(std::uint32_t kind) = 0;
};

class CHardwareCursor : public CCursor {
public:
    std::uint32_t texture_width = 0u;
    std::uint32_t texture_height = 0u;
    struct CursorDeleter { void operator()(HCURSOR cursor) const noexcept { if (cursor) ::DestroyCursor(cursor); } };
    using CursorOwner = std::unique_ptr<std::remove_pointer_t<HCURSOR>, CursorDeleter>;
    CursorOwner cursor_handle;
    bool clip_enabled = false;
    bool saved_system_visible = 0u;
    std::uint32_t kind = 255u;
    int saved_x = 0;
    int saved_y = 0;
    CHardwareCursor();
    ~CHardwareCursor();
    void copyStateFrom(const CCursor* previous) override;
    void activate() override;
    void deactivate() override;
    void apply() override;
    void updatePosition() override;
    SferaCursorPosition* getPosition(SferaCursorPosition* output) const override;
    void setPosition(int x, int y) override;
    void show() override;
    bool isInsideViewport() const override;
    bool isSystemCursorVisible() const override;
    void setSystemCursorVisible(bool visible) override;
    std::uint32_t cursorKind() const override;
    void setCursorKind(std::uint32_t kind) override;
};

class CSoftwareCursor : public CCursor {
public:
    std::uint32_t texture_width = 0u;
    std::uint32_t texture_height = 0u;
    int x = 0;
    int y = 0;
    bool active = 0u;
    bool saved_system_visible = 0u;
    std::uint32_t saved_kind = 255u;
    int saved_x = 0;
    int saved_y = 0;
    CSoftwareCursor();
    void copyStateFrom(const CCursor* previous) override;
    void activate() override;
    void deactivate() override;
    void apply() override;
    void updatePosition() override;
    SferaCursorPosition* getPosition(SferaCursorPosition* output) const override;
    void setPosition(int x, int y) override;
    void show() override;
    bool isInsideViewport() const override;
    bool isSystemCursorVisible() const override;
    void setSystemCursorVisible(bool visible) override;
    std::uint32_t cursorKind() const override;
    void setCursorKind(std::uint32_t kind) override;
};

class CD3D9Device;
class CShaderMgr;
class CPostEffectsMgr;
namespace SphereUI { struct DisplayMode { std::uint32_t width; std::uint32_t height; std::uint32_t depth; }; }

class UnmanagedResourceBase {
public:
    virtual ~UnmanagedResourceBase();
    virtual void restoreResource() = 0;
    virtual void releaseResource() = 0;
    UnmanagedResourceBase(const UnmanagedResourceBase&) = delete;
    UnmanagedResourceBase& operator=(const UnmanagedResourceBase&) = delete;
protected:
    explicit UnmanagedResourceBase(CD3D9Device& device, D3DPOOL pool);
    CD3D9Device* device;
private:
    friend class CD3D9Device;
    bool registered;
};

class TextureMapping {
public:
    TextureMapping(IDirect3DTexture9* texture, UINT level = 0, DWORD flags = 0) noexcept;
    TextureMapping(TextureMapping&& other) noexcept;
    TextureMapping(const TextureMapping&) = delete;
    TextureMapping& operator=(const TextureMapping&) = delete;
    ~TextureMapping();
    HRESULT status() const noexcept { return status_; }
    const D3DSURFACE_DESC& description() const noexcept { return description_; }
    const D3DLOCKED_RECT& rectangle() const noexcept { return rectangle_; }
    std::span<std::uint8_t> row(std::size_t index, std::size_t bytes) const noexcept;
    HRESULT unlock() noexcept;
    HRESULT copyRows(std::span<const std::byte> source, std::size_t rowBytes, std::size_t rows) noexcept;
private:
    Microsoft::WRL::ComPtr<IDirect3DTexture9> texture_;
    UINT level_;
    D3DSURFACE_DESC description_{};
    D3DLOCKED_RECT rectangle_{};
    HRESULT status_ = D3DERR_INVALIDCALL;
    bool locked_ = false;
};

class RenderTargetScope {
public:
    RenderTargetScope(CD3D9Device& device, IDirect3DTexture9& target);
    RenderTargetScope(RenderTargetScope&& other) noexcept;
    RenderTargetScope(const RenderTargetScope&) = delete;
    RenderTargetScope& operator=(const RenderTargetScope&) = delete;
    ~RenderTargetScope();
    HRESULT restore() noexcept;
private:
    CD3D9Device* device_;
    Microsoft::WRL::ComPtr<IDirect3DSurface9> color_;
    Microsoft::WRL::ComPtr<IDirect3DSurface9> depth_;
    D3DVIEWPORT9 viewport_{};
};

class UnmanagedResourceTexture final : public UnmanagedResourceBase {
public:
    Microsoft::WRL::ComPtr<IDirect3DTexture9> native_texture;
    UnmanagedResourceTexture(CD3D9Device& device, std::uint32_t width, std::uint32_t height,
        std::uint32_t levels, std::uint32_t usage, D3DFORMAT format, D3DPOOL pool);
    void restoreResource() override;
    void releaseResource() override;
private:
    const std::uint32_t width;
    const std::uint32_t height;
    const std::uint32_t levels;
    const std::uint32_t usage;
    const D3DFORMAT format;
    const D3DPOOL pool;
};

template<class Element>
class DynamicStream final : public UnmanagedResourceBase {
    static constexpr bool indexed = std::is_same_v<Element, std::uint16_t>;
public:
    using Buffer = std::conditional_t<indexed, IDirect3DIndexBuffer9, IDirect3DVertexBuffer9>;
    class Mapping {
    public:
        Mapping(Mapping&& other) noexcept;
        Mapping& operator=(Mapping&& other) noexcept;
        Mapping(const Mapping&) = delete;
        Mapping& operator=(const Mapping&) = delete;
        ~Mapping();
        explicit operator bool() const noexcept { return buffer_ != nullptr; }
        Element* data() const noexcept { return data_; }
        Element& operator[](std::size_t index) const { return data_[index]; }
        std::size_t first() const noexcept { return first_; }
        std::size_t size() const noexcept { return count_; }
        Buffer* buffer() const noexcept { return buffer_.Get(); }
        void unlock();
    private:
        friend class DynamicStream;
        Mapping(CD3D9Device& device, Microsoft::WRL::ComPtr<Buffer> buffer,
            std::size_t first, std::size_t count, Element* data);
        CD3D9Device* device_;
        Microsoft::WRL::ComPtr<Buffer> buffer_;
        std::size_t first_;
        std::size_t count_;
        Element* data_;
    };
    explicit DynamicStream(CD3D9Device& device);
    void reserve(std::size_t count);
    Mapping lock(std::size_t count);
    void discard() noexcept { discard_next_ = true; }
    void restoreResource() override;
    void releaseResource() override;
    std::size_t capacity() const noexcept { return capacity_; }
    Buffer* buffer() const noexcept { return buffer_.Get(); }
private:
    Microsoft::WRL::ComPtr<Buffer> buffer_;
    std::size_t capacity_ = 0;
    std::size_t position_ = 0;
    bool discard_next_ = false;
};

class CD3D9Device {
    std::vector<UnmanagedResourceBase*> unmanaged_resources;
public:
    enum DrawFlag : std::uint32_t { disable_clipping = 1u, two_sided = 4u, lighting = 16u };
    Microsoft::WRL::ComPtr<IDirect3D9> api;
    Microsoft::WRL::ComPtr<IDirect3DDevice9> native_device;
    D3DPRESENT_PARAMETERS presentation{};
    D3DCAPS9 capabilities{};
    HRESULT last_hresult = S_OK;
    SferaMatrix4x4F world_transform{};
    Microsoft::WRL::ComPtr<IDirect3DQuery9> sync_query;
    bool supports_post_effects = false;
    std::vector<SphereUI::DisplayMode> display_modes;
    std::unique_ptr<CShaderMgr> shaders;
    std::unique_ptr<CPostEffectsMgr> post_effects;
    std::unique_ptr<UnmanagedResourceTexture> reflection_target;
    std::unique_ptr<UnmanagedResourceTexture> minimap_target;
    DynamicStream<SphereRender::PositionNormalUvVertex> model_vertices;
    DynamicStream<SphereRender::PositionColorUvVertex> colored_vertices;
    DynamicStream<std::uint16_t> indices_primary;
    DynamicStream<std::uint16_t> indices_secondary;
    D3DTEXTUREFILTERTYPE min_filter = D3DTEXF_ANISOTROPIC;
    D3DTEXTUREFILTERTYPE mag_filter = D3DTEXF_LINEAR;
    D3DTEXTUREFILTERTYPE mip_filter = D3DTEXF_LINEAR;
    CD3D9Device();
    ~CD3D9Device();
    CD3D9Device(const CD3D9Device&) = delete;
    CD3D9Device& operator=(const CD3D9Device&) = delete;
    HRESULT checkResult(HRESULT result, std::string_view operation);
    void initialize(HWND window, std::uint32_t width, std::uint32_t height, std::uint32_t depth_bits, bool windowed);
    void enumerateDisplayModes(bool windowed);
    bool supportsDisplayMode(std::uint32_t width, std::uint32_t height, std::uint32_t depth_bits) const;
    void selectBackBufferFormat(const D3DDISPLAYMODE& display, bool windowed, std::uint32_t& width, std::uint32_t& height, D3DFORMAT& format);
    D3DFORMAT selectDepthFormat(D3DFORMAT adapter_format, D3DFORMAT back_buffer_format) const;
    void initializeRenderState();
    void applyFiltering();
    void setTransform(D3DTRANSFORMSTATETYPE kind, const SferaMatrix4x4F& matrix);
    void setAlphaBlending(D3DBLEND source, D3DBLEND destination);
    void setColorOperation(std::uint32_t stage, D3DTEXTUREOP operation, std::uint32_t first, std::uint32_t second);
    void setAlphaOperation(std::uint32_t stage, D3DTEXTUREOP operation, std::uint32_t first, std::uint32_t second);
    void setWhiteMaterial(float alpha);
    void applyDrawState(std::uint32_t flags);
    static UINT primitiveCount(D3DPRIMITIVETYPE topology, UINT elements);
    void drawBuffer(IDirect3DVertexBuffer9* vertices, D3DPRIMITIVETYPE topology, std::uint32_t flags, std::ptrdiff_t base_vertex, std::size_t vertex_count, IDirect3DIndexBuffer9* indices, std::size_t index_count, std::size_t start_index, std::size_t stride);
    void drawVertices(D3DPRIMITIVETYPE topology, std::uint32_t flags, const void* vertices, std::size_t vertex_count, const std::uint16_t* indices, std::size_t index_count, std::size_t stride);
    bool beginScene();
    HRESULT endScene() noexcept;
    bool present();
    bool sceneActive() const noexcept { return scene_open_; }
    void releaseResources();
    void restoreResources();
    void waitForGpu();
    UnmanagedResourceTexture& minimapTexture();
private:
    friend class UnmanagedResourceBase;
    bool scene_open_ = false;
    bool resetting_ = false;
    DWORD owner_thread_ = 0;
};

class SceneScope {
public:
    explicit SceneScope(CD3D9Device& device) : device_(device.beginScene() ? &device : nullptr) {}
    SceneScope(const SceneScope&) = delete;
    SceneScope& operator=(const SceneScope&) = delete;
    ~SceneScope() { if (device_) device_->endScene(); }
    explicit operator bool() const noexcept { return device_ != nullptr; }
    void finish();
private:
    CD3D9Device* device_;
};

// D3D state blocks do not own render targets; pair this with RenderTargetScope
// for off-screen passes. It restores shaders, streams, samplers and render state.
class RenderStateScope {
public:
    enum class FailurePolicy { Throw, Skip };
    explicit RenderStateScope(CD3D9Device& device, FailurePolicy failure = FailurePolicy::Throw);
    explicit operator bool() const noexcept { return state_.Get() != nullptr; }
    RenderStateScope(const RenderStateScope&) = delete;
    RenderStateScope& operator=(const RenderStateScope&) = delete;
    ~RenderStateScope() noexcept;
private:
    CD3D9Device& device_;
    SferaMatrix4x4F world_transform_;
    std::array<bool, 31> active_lights_;
    std::size_t active_light_count_;
    std::uint32_t sprite_render_mode_;
    Microsoft::WRL::ComPtr<IDirect3DStateBlock9> state_;
};

class SferaFileManager {
public:
    SferaFileManager() = default;
    ~SferaFileManager();
    SferaFileManager(const SferaFileManager&) = delete;
    SferaFileManager& operator=(const SferaFileManager&) = delete;
    bool setErrorReporting(bool enabled);
    int open(const std::string& filename, int flags);
    int create(const std::string& filename);
    int transformEnvelope(const std::string& destination, const std::string& source, bool compress);
    std::ptrdiff_t read(int descriptor, std::span<std::byte> destination);
    std::ptrdiff_t write(int descriptor, std::span<const std::byte> source);
    std::int64_t seek(int descriptor, std::int64_t offset, int origin);
    int close(int descriptor);
    std::int64_t fileSize(const std::string& filename);
    std::vector<std::uint8_t> readAll(const std::string& filename);
    static bool writeFile(const std::string& path, std::span<const std::byte> source);
    static std::optional<std::vector<std::uint8_t>> readBounded(const std::string& filename, std::size_t capacity);
    void keepTail(const std::string& filename, std::size_t size);
    void addSearchPath(std::string_view directory);
    std::vector<std::string> candidatePaths(const std::string& filename, bool search_nested_paths = false) const;
    class ScopedFile {
    public:
        ScopedFile(SferaFileManager& owner, int descriptor) noexcept : owner_(owner), descriptor_(descriptor) {}
        ScopedFile(const ScopedFile&) = delete;
        ScopedFile& operator=(const ScopedFile&) = delete;
        ~ScopedFile() noexcept;
        int get() const noexcept { return descriptor_; }
        int close();
    private:
        SferaFileManager& owner_;
        int descriptor_;
    };
private:
    static constexpr std::size_t maximum_open_files = 100u;
    static constexpr std::size_t maximum_search_paths = 100u;
    void reportError(std::string_view description, const std::string& filename) const;
    bool error_reporting_enabled = false;
    std::vector<std::string> search_paths;
    std::unordered_map<int, std::string> open_files;
    int registerDescriptor(int descriptor, const std::string& filename);
    const std::string* filenameFor(int descriptor, std::string_view invalid_handle_message) const;
};

extern SferaFileManager g_sfera_files;

struct QuickFileEntry {
    std::vector<std::uint8_t> bytes;
    std::uint16_t module_id;
};

class QuickFile {
public:
    static constexpr std::size_t file_capacity = 400;
    QuickFile* initialize(const std::string& directory);
    void release();
    int load(const std::string& filename, std::size_t size);
    const QuickFileEntry* find(std::string_view filename) const;
private:
    static constexpr std::size_t maximum_filename_length = 32;
    std::vector<QuickFileEntry> files;
    std::unordered_map<std::string, std::size_t> index;
};

class SferaFileMap {
public:
    explicit SferaFileMap(const std::string& path);
    SferaFileMap(const SferaFileMap&) = delete;
    SferaFileMap& operator=(const SferaFileMap&) = delete;
    ~SferaFileMap() noexcept;
    bool open(const std::string& path);
    void close() noexcept;
    bool isOpen() const noexcept;

    std::span<const std::uint8_t> bytes() const noexcept { return {mapped_view, file_size}; }
private:
    const std::uint8_t* mapped_view = nullptr;
    std::size_t file_size = 0u;
    std::string filename;
    void reportError(std::string_view operation) const noexcept;
};

namespace SphereUI {
    struct CursorGeometry {
        int x;
        int y;
        int width;
        int height;
        bool centered;
    };
}

class CCursorManager {
public:
    static CCursorManager& instance();
    static bool hasActiveCursor() noexcept;
    static void focusChanged(bool focused) noexcept;
    static void shutdown() noexcept;
    CCursor* currentCursor() const noexcept;
    CCursor* activeCursor() const;
    SferaCursorPosition position() const;
    SphereUI::CursorGeometry geometry() const;
    void select(std::uint32_t mode);
    bool usesSoftwareCursor() const noexcept;
private:
    CCursorManager() = default;
    ~CCursorManager();
    CCursorManager(const CCursorManager&) = delete;
    CCursorManager& operator=(const CCursorManager&) = delete;
    CSoftwareCursor software;
    CHardwareCursor hardware;
    CCursor* active = nullptr;
    static CCursorManager* initialized;
};

namespace SphereUI {
    struct FontGlyph {
        std::uint16_t width = 0u;
        std::uint16_t height = 0u;
        std::int16_t bearing_x = 0;
        std::int16_t bearing_y = 0;
        std::int16_t advance = 0;

        float u0 = 0.0f;
        float v0 = 0.0f;
        float u1 = 0.0f;
        float v1 = 0.0f;
        static constexpr std::size_t encodedSize = 28;
        static FontGlyph decode(std::span<const std::uint8_t> bytes) {
            SferaBinary::Reader reader(bytes);
            FontGlyph glyph;
            glyph.width = reader.read<std::uint16_t>();
            glyph.height = reader.read<std::uint16_t>();
            glyph.bearing_x = reader.read<std::int16_t>();
            glyph.bearing_y = reader.read<std::int16_t>();
            glyph.advance = reader.read<std::int16_t>();
            reader.take(2u); // Reserved bytes in the SFNT record.
            glyph.u0 = reader.read<float>();
            glyph.v0 = reader.read<float>();
            glyph.u1 = reader.read<float>();
            glyph.v1 = reader.read<float>();
            return glyph;
        }
    };

    class FontFace {
    public:
        int texture = -1;
        std::array<FontGlyph, 256> glyphs{};
        std::string name;
        int line_height = 0;
        int baseline = 0;
        bool load(std::optional<std::string_view> display_name, const std::string& filename, std::string_view texture_name);
        bool load(std::nullptr_t, const std::string&, std::string_view) = delete;
    };

    class InterfaceRenderer {
    public:
    static uint32_t sprite_render_mode;
    static SphereUI::UiRect clip_rectangle;
    static SferaScreenVertex glyph_vertices[1200];
    static uint16_t quad_indices[1800];

        static TextExtent measureText(std::string_view text, int font, bool initialized);
        static std::uint32_t tracking(int font) noexcept;
        static void drawText(std::string_view text, int x, int y, std::uint32_t color, int font, bool initialized, const UiRect& clip, bool opaque);
        static void reportError(std::string_view message);
        static void drawTexture(IDirect3DBaseTexture9* texture, float left, float top, float right, float bottom, std::uint32_t color, float u = 1.0f, float v = 1.0f, bool textured = true);
        static void setSpriteRenderMode(std::uint32_t mode);
        static UiViewport viewport();
        static void setViewport(const UiViewport& viewport);

    private:
        static void drawFaceText(std::string_view text, int x, int y, std::uint32_t color, int font, const UiRect& clip);
    };

    class InterfaceConfiguration {
    public:
        static std::optional<std::string_view> value(std::string_view key);
        static bool empty() noexcept { return text_.empty(); }
        static void close() noexcept { text_.clear(); filename_.clear(); }
        static void open(const std::string& filename);
        static int readInteger(std::string_view key, int fallback);
        static void writeInteger(std::string_view key, int value);
        static void save();
    private:
        static std::string text_;
        static std::string filename_;
    };

    class FontFactory {
    public:
        FontFactory();
        ~FontFactory();
        FontFactory(const FontFactory&) = delete;
        FontFactory& operator=(const FontFactory&) = delete;
        void initialize();
        void clear();
        bool load(const std::string& filename, std::string_view texture_name);
        void loadNamedFont(std::string_view name);
        void loadConfiguration();
        std::size_t count() const noexcept;
        const FontFace& face(int font) const;
    private:
        friend class InterfaceRenderer;
        std::vector<std::unique_ptr<FontFace>> faces;
        std::vector<SferaScreenVertex> vertices;
        std::vector<std::uint16_t> quad_indices;
        std::size_t vertex_count = 0u;
    };
}

extern SphereUI::FontFactory g_sfera_fonts;

namespace SphereUI {
    enum class HyperTextCommand { text, lineBreak, color, linkStart, linkEnd, preserveSpaces, horizontalSpace, tab, image, tooltipStart, tooltipEnd, unknown };
    enum class HyperTextImageAlignment { top, bottom, middle };

    struct HyperTextRegion {
        std::string target;
        std::vector<UiRect> rectangles;
        bool visible = false;
        bool hovered = false;
        bool contains(int x, int y) const;
        void addRectangle(const UiRect& rectangle, const UiRect& clip);
    };

    struct HyperDocumentNode {
        HyperTextCommand command = HyperTextCommand::text;
        std::string text;
        std::uint32_t color = D3DCOLOR_ARGB(255, 255, 255, 255);
        std::size_t region_index = 0;
        int spacing = 0;
        int width = 0;
        HyperTextImageAlignment image_alignment = HyperTextImageAlignment::top;
        int image_width = 0;
        int image_height = 0;
        int image_x = 0;
        int image_y = 0;
        std::shared_ptr<const UiSprite> sprite;
    };

    struct HyperDocumentLine {
        std::vector<HyperDocumentNode> nodes;
        int height = 0;
        int baseline = 0;
        std::uint32_t initial_color = D3DCOLOR_ARGB(255, 255, 255, 255);
    };

    class HyperTextDocument {
    public:
        std::string name;
        std::vector<HyperTextRegion> links;
        std::vector<HyperTextRegion> tooltips;
        int line_height = 0;
        int font = 0;
        std::uint32_t link_color = D3DCOLOR_ARGB(255, 80, 160, 160);
        std::uint32_t hover_color = D3DCOLOR_ARGB(255, 255, 255, 0);
        HyperTextDocument() = default;
        HyperTextDocument(std::string_view text, int width, std::uint32_t format, int font);
        void setName(std::string_view value);
        bool load(const std::string& filename);
        void load(const SferaSimpleParser& parser, const SferaParserRange& range);
        void parse(std::string_view input);
        std::unique_ptr<HyperTextDocument> clone(int width, std::uint32_t format, int font) const;
        void layout(int width, std::uint32_t format, int font);
        void draw(int left, int top, int clip_offset, int clip_height, std::uint32_t alpha);
        int totalHeight() const;
        void resetRegions();
    private:
        std::vector<HyperDocumentNode> nodes;
        std::vector<HyperDocumentLine> lines;
        UiRect linkRectangle(int left, int right, int y, int baseline) const;
    };

    class HyperTextParser {
    public:
        static std::string plainText(std::string_view input);
        static std::string buildLink(std::string_view scheme, std::string_view target, std::string_view caption);
        static bool extractPlayerPrefix(std::string_view input, std::string* output, std::string* plain);
        static bool removePlayerPrefix(std::string_view input, std::string* output, std::string* plain);
        static bool eraseRange(std::string_view input, std::size_t first, std::size_t last, std::string* output, std::string* plain);
        static HyperTextCommand command(std::string_view name);
        static bool parseCommand(std::string_view tag, HyperDocumentNode& node, std::string& argument);
        static void parseImage(std::string_view argument, HyperDocumentNode& node);
        static void parseElements(std::string_view text, std::vector<HyperTextRun>& elements, std::string& plain);
    };
}

namespace SphereUI {
// Types in namespace SphereUI, before InterfaceManager.
struct SavedWindowPosition {
    std::string name;
    int x = 0;
    int y = 0;
};

struct LocalizedTextEntry {
    std::string key;
    std::string value;
};

struct OptionsSession {
    uint32_t binding_slot = UINT32_MAX;
    uint32_t edited_bindings[64]{};
    uint32_t dialog_kind{};
    uint32_t graphics_page{};
    uint32_t edited_interface[9]{};
    uint32_t edited_graphics[13]{};
    uint32_t saved_interface[9]{};
    bool saved_lods_enabled{};
    float saved_lod_distance{};
    float saved_fog_distance{};
    uint32_t saved_music_volume{};
    std::array<std::string, 7> labels{};
    uint32_t saved_graphics[7]{};
    std::string unknown_graphics_label;
    uint32_t saved_sound_volume{};
    std::string binding_key_name;
    uint32_t comparison_graphics_value{};
    bool binding_dialog_open{};
    std::vector<std::uint32_t> saved_chat_fonts{};
    std::vector<std::uint32_t> edited_chat_fonts{};

};
class ChatFilter;

class InterfaceManager {
public:
    std::string default_cursor_name;
    uint32_t overlay_alpha{};
    uint32_t cursor_kind{};
    bool ui_enabled = true;
    bool saved_ui_enabled = true;
    bool cross_enabled = true;
    bool sounds_enabled = true;
    bool description_auto_popup = true;
    bool invite_messages = true;
    SphereUI::CDescriptionWindow* description_control{};
    uint32_t previous_input_modifiers{};
    std::unique_ptr<SphereUI::ChatFilter> chat_filter{};
    bool world_interaction_enabled{};
    uint32_t world_input_buttons{};
    OptionsSession options{};

    std::vector<std::unique_ptr<Window>> window_templates;
    std::vector<std::unique_ptr<HyperTextDocument>> hypertext_documents;
    std::vector<std::shared_ptr<const UiSprite>> sprites;
    std::vector<LocalizedTextEntry> localized_strings;
    std::list<SavedWindowPosition> saved_positions;
    std::string localizedPath(std::string_view filename);
    std::shared_ptr<const UiSprite> sharedSprite(std::string_view name);
    std::shared_ptr<const UiSprite> acquireSprite(std::string_view name);
    void loadSprites(const std::string& filename);
    void clearSprites();
    bool loadWindowTemplates(const std::string& filename);
    Window* templateWindow(std::string_view name) const;
    void clearWindowTemplates();
    void loadHyperTexts();
    HyperTextDocument* findHyperText(std::string_view name) const;
    void clearHyperTexts();
    bool loadLocalizedStrings();
    std::string_view localizedValue(std::string_view key) const;
    std::string_view localizedText(std::string_view key) const;
    void clearLocalizedStrings();
    SavedWindowPosition* savedPosition(std::string_view name, bool create);
    bool findSavedPosition(std::string_view name, SferaCursorPosition& position);
    void saveWindowPosition(Window& window);
    std::size_t savedPositionsSize() const;
    void writeSavedPositions(std::span<std::byte> destination) const;
    void readSavedPositions(std::span<const std::byte> source);
    enum OpenFlag : std::uint32_t { explicitPosition = 1u, preserveVisibility = 2u, skipOpeningAnimation = 4u, centerOnScreen = 8u };
    bool initialized = false;
    bool drag_drop_active = false;
    bool capture_control_binding = false;
    bool tooltip_disabled = false;
    std::list<std::unique_ptr<Window>> windows;
    std::deque<WindowEvent> events;
    struct WindowPointerHash {
        using is_transparent = void;
        std::size_t operator()(const Window* window) const noexcept { return std::hash<const Window*>{}(window); }
    };
    std::unordered_set<Window*, WindowPointerHash, std::equal_to<>> registered_windows;
    std::uint64_t next_registration_id = 1u;
    std::unordered_map<const Window*, WindowEventHandler> event_handlers;
    std::unique_ptr<SferaInterfaceCursor> cursor;
    Window* help_window = nullptr;
    Window* load_screen = nullptr;
    std::unique_ptr<ToolTipCtrl> tooltip;
    std::string cursor_name;
    InterfaceManager() = default;
    ~InterfaceManager();
    InterfaceManager(const InterfaceManager&) = delete;
    InterfaceManager& operator=(const InterfaceManager&) = delete;
    void loadAllWindowTemplates();
    bool initializeResources();
    void showOptions(bool visible);
    bool prepareResources();
    void finishInitialization();
    bool shutdown();
    void clearWindows();
    void queueEvent(const WindowEvent& event);
    bool pollEvent(WindowEvent& event);
    Window* findWindow(std::string_view name, bool exact = false) const;
    Window* windowUnderCursor() const;
    bool hasEscapeWindow() const;
    Window* addTopLevelWindow(std::unique_ptr<Window> window);
    void raiseWindow(Window& window);
    void lowerWindow(Window& window);
    void collectCoveredWindows(Window& window);
    Window* openWindow(std::string_view name, int x = 0, int y = 0, std::uint32_t flags = 0u);
    void closeWindow(Window* window, bool animated = true);
    void showHelpPage(std::optional<std::string_view> name);
    void showHelpPage(std::nullptr_t) = delete;
    void setTooltipText(std::optional<std::string_view> text);
    void setTooltipText(std::nullptr_t) = delete;
    void setCursorKind(std::uint32_t kind, int x, int y);
    void setCursorImage(std::optional<std::string_view> texture, int x, int y);
    void setCursorImage(std::nullptr_t, int, int) = delete;
    void update(std::uint8_t key = 0u, std::uint8_t character = 0u, std::uint32_t mouse_buttons = 0u, int wheel_delta = 0);
    void draw();
    std::uint32_t sendMessage(Window* window, SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second);
    void showLoadingScreen(bool visible, int width, int height, bool english);
    void setLoadingProgress(int percent);
    void registerWindow(Window& window);
    void unregisterWindow(Window& window);
    bool isRegistered(const Window* window) const;
    bool isRegistered(const Window* window, std::uint64_t registration_id) const;
    void bindEventHandler(Window* window, WindowEventHandler handler);
    void copyEventHandler(Window* destination, const Window* source);
    bool hasEventHandler(const Window* window) const;
    void dispatchEvent(Window* window, const WindowEvent& event);
    void unbindEventHandler(const Window* window);

};
}
extern SphereUI::InterfaceManager g_sfera_interface;

namespace SphereUI {
    struct ImageDescriptionParameters {
        std::string texture_name;
        int width;
        int height;
        UiRect rectangle;
        std::uint32_t flags;
    };

    struct ImageDescription {
        std::string name;
        ImageDescriptionParameters image;
    };
}

namespace SphereRender {

class ConfigDocument {
public:
    enum class Type { Integer, Float, Text, Binary, Object, IntegerArray, FloatArray, TextArray, ObjectArray };
    enum class StorageMode { Plain, Encoded, Preserve };
    struct Value {
        std::string name;
        Type type = Type::Integer;
        std::variant<int, float, std::string, std::vector<std::uint8_t>, std::vector<int>, std::vector<float>, std::vector<std::string>, std::vector<ConfigDocument>> data;
    };
    static ConfigDocument parse(std::string_view source);
    static ConfigDocument open(const std::string& path);
    static void setStorageMode(StorageMode mode);
    const Value* find(std::string_view name) const;
    std::optional<int> integer(std::string_view name) const;
    std::optional<float> real(std::string_view name) const;
    std::optional<std::string_view> text(std::string_view name) const;
    std::optional<std::size_t> arraySize(std::string_view name) const;
    std::optional<int> integerAt(std::string_view name, std::size_t index) const;
    std::optional<float> realAt(std::string_view name, std::size_t index) const;
    std::optional<std::string_view> textAt(std::string_view name, std::size_t index) const;
    const ConfigDocument* object(std::string_view name) const;
    const ConfigDocument* objectAt(std::string_view name, std::size_t index) const;
    std::span<const std::uint8_t> binary(std::string_view name) const;
    const std::vector<Value>& values() const;
private:
    class Parser;
    std::vector<Value> values_;
    static StorageMode storage_mode_;
    static constexpr std::uint8_t storageKey = 203;
};

class ModelParameters {
public:
    void load(const std::string& path);
    void parse(std::string_view source);
    void clear();
    bool contains(std::string_view model, std::string_view parameter) const;
    bool hasModel(std::string_view model) const;
    std::optional<float> floatValue(std::string_view model, std::string_view parameter) const;
    std::optional<int> intValue(std::string_view model, std::string_view parameter) const;
    std::optional<std::string_view> stringValue(std::string_view model, std::string_view parameter) const;
private:
    struct Parameter { std::string name; std::optional<std::string> value; };
    struct Object { std::string name; std::vector<Parameter> parameters; };
    const Object* findObject(std::string_view name) const;
    const Parameter* findParameter(std::string_view model, std::string_view parameter) const;
    std::vector<Object> objects_;
    bool initialized_ = false;
};

struct Material {
    std::string name;
    std::vector<int> textures;
    std::array<float, 4> color{};
    std::array<float, 3> colorVariation{};
    bool hasColorVariation = false;
    static std::uint32_t randomColor(const std::array<float, 3>& variation);
};

class MaterialLibrary {
public:
    void load(const std::string& binary_path, const std::string& configuration_path = "Models\\Materials.cfg");
    void clear();
    const Material* find(std::string_view name) const;
    const Material* at(std::size_t index) const;
    const Material* defaultMaterial() const;
    std::shared_ptr<const std::vector<Material>> snapshot() const noexcept { return materials_; }
    std::size_t size() const;
private:
    std::shared_ptr<const std::vector<Material>> materials_;
    std::optional<std::size_t> default_index_;
};

}
extern SphereRender::MaterialLibrary g_sfera_materials;

namespace SphereRender {

class ModelParameters;
class MaterialLibrary;
struct Material;

enum class CollisionKind { AxisAlignedBounds, OrientedBounds, Triangles, None };

struct ModelVertex {
    SferaVec3F position{};
    SferaVec3F normal{};
    float u = 0.0f;
    float v = 0.0f;
    const Material* material = nullptr;
};

struct ModelFace {
    std::uint16_t vertices[3]{};
};

struct Submesh {
    std::size_t bone_index = 0u;
    bool inverted_fade = false;
    const Material* material = nullptr;
    std::size_t first_face = 0u;
    std::size_t face_count = 0u;
    std::size_t first_vertex = 0u;
    std::size_t vertex_count = 0u;

};

struct BoneBounds {
    SferaBoundsCornersRuntime corners{};
    SferaVec3F minimum{};
    SferaVec3F maximum{};
    SferaVec3F center{};
    float diagonal_length = 0.0f;
};

struct BoneAnimation {
    bool suppress_secondary_animation = false;
    bool animated = false;
    std::size_t pose_index = 0u;
    std::uint8_t attachment_slot = 255u;
};

struct Bone {
    std::string name;
    bool has_geometry = true;
    std::size_t child_count = 0u;
    std::size_t first_child = 0u;
    std::variant<BoneBounds, BoneAnimation> data;

    BoneBounds& bounds() { return std::get<BoneBounds>(data); }
    const BoneBounds& bounds() const { return std::get<BoneBounds>(data); }
    BoneAnimation& animation() { return std::get<BoneAnimation>(data); }
    const BoneAnimation& animation() const { return std::get<BoneAnimation>(data); }
};

struct ModelKeyframe {
    SferaVec3F translation{};
    SferaQuaternionF rotation{};
};

struct AnimationFrame {
    std::size_t keyframe = 0u;
    std::uint8_t interpolation = 255u;
};

struct FaceColorIndices { std::uint16_t vertices[3]{}; };

struct ModelCollisionGroup {
    std::size_t bone = 0u;
    std::size_t triangle_count = 0u;
    std::size_t first_triangle = 0u;
};

struct ModelCollisionTriangle {
    SferaVec3F minimum{};
    SferaVec3F maximum{};
    SferaVec3F vertices[3]{};
    SferaVec3F normal{};
    float plane_distance = 0.0f;
    std::uint32_t collision_flags = 0u;
};

enum class VegetationKind : int { None = -1, Grass = 0, SynchronizedGrass = 1, InteractiveGrass = 2, Tree = 3 };

struct GrassInfluence {
    enum class Anchor { Fixed, Horizontal, Vertex };
    Anchor anchor_kind = Anchor::Fixed;
    std::size_t anchor_vertex = 0;
    std::uint16_t phase = 0;
    bool share_phase = false;
    float distance = 0.0f;
};

struct TreeInfluence {
    float amplitude = 0.0f;
    std::uint16_t phase = 0u;
};

struct GrassBendingBasis {
    SferaVec3F first_axis{};
    SferaVec3F second_axis{};
    SferaVec3F anchor{};
};

struct VegetationVertex { SferaVec3F position{}; SferaVec3F normal{}; };

class Model {
public:
    std::string name;
    std::vector<ModelVertex> vertices;
    std::vector<ModelFace> faces;
    std::vector<Submesh> submeshes;
    std::vector<Bone> bones;
    std::size_t root_bone = 0;
    std::vector<const Material*> materials;
    std::vector<std::size_t> child_bones;
    std::size_t frame_count = 0u;
    std::vector<ModelKeyframe> keyframes;
    std::vector<AnimationFrame> animation_frames;
    std::vector<std::size_t> animation_lengths;
    bool has_vertex_colors = false;
    std::vector<std::uint32_t> vertex_colors;
    std::vector<FaceColorIndices> face_colors;
    CollisionKind collision_kind = CollisionKind::AxisAlignedBounds;
    SferaVec3F minimum{};
    SferaVec3F maximum{};
    SferaBoundsCornersRuntime oriented_corners{};
    SferaBoundsCornersRuntime collision_corners{};
    SferaMatrix4x4F bounds_transform{};
    SferaVec3F oriented_size{};
    float radius = 0.0f;
    float minimum_size = 0.0f;
    std::vector<ModelCollisionGroup> collision_groups;
    std::vector<ModelCollisionTriangle> collision_triangles;
    float lod_distance = 1000.0f;
    float lod_power = -1.0f;
    float shadow_fade = 0.5f;
    float shadow_scale = 2.0f;
    float shadow_spread = 0.85f;
    bool casts_static_shadow = false;
    VegetationKind vegetation_kind = VegetationKind::None;
    struct GrassData {
        std::vector<GrassInfluence> influences;
        std::vector<GrassBendingBasis> bending;
    };
    std::variant<std::monostate, GrassData, std::vector<TreeInfluence>> vegetation;
    std::vector<VegetationVertex> cached_vegetation_vertices;

    GrassData* grass() noexcept { return std::get_if<GrassData>(&vegetation); }
    const GrassData* grass() const noexcept { return std::get_if<GrassData>(&vegetation); }
    std::vector<TreeInfluence>* tree() noexcept { return std::get_if<std::vector<TreeInfluence>>(&vegetation); }
    const std::vector<TreeInfluence>* tree() const noexcept { return std::get_if<std::vector<TreeInfluence>>(&vegetation); }
    std::array<float, 3> color_variation{};
    std::uint32_t landscape_shadow_alpha = 0u;

    // Raw material links in geometry borrow from these immutable catalogues.
    std::vector<std::shared_ptr<const std::vector<Material>>> material_lifetimes;
    Model() = default;
    Model(const Model&) = delete;
    Model& operator=(const Model&) = delete;
    static std::unique_ptr<Model> load(std::string_view model_name, std::string_view directory, const ModelParameters& parameters, const MaterialLibrary& materials);
    static std::unique_ptr<Model> decode(std::string_view model_name, std::span<const std::uint8_t> bytes, const ModelParameters& parameters, const MaterialLibrary& materials);
    void prepareGrass(bool synchronized, float ground_y);
    void prepareTree(float dead_radius, float phase_multiplier);
    void prepareVegetation(const ModelParameters& parameters);
    void initializeGrassGeometry(std::size_t vertices_needed, std::size_t faces_needed, float height);
    void finishGrassGeometry(std::span<const Submesh> groups);

private:
    void recoverBounds();
    void assignMaterials();
};

}

namespace SphereRender {
    struct SferaRenderLookupEntry {
    uint32_t resource;
    uint32_t mask;
};

struct SceneSortEntry;
    class TextureRepository {
    public:
        struct Entry {
            std::string name;
            std::filesystem::path filename;
            Microsoft::WRL::ComPtr<IDirect3DBaseTexture9> texture;
            bool has_alpha = false;
        };
        void initialize();
        void addFolder(const std::string& directory);
        void finishRegistration();
        void clear();
        int find(std::string_view name) const;
        IDirect3DBaseTexture9* resource(int index);
        SphereUI::TextExtent size(int index);
        bool hasAlpha(int index);
        std::size_t count() const { return entries.size(); }
        int defaultTexture() const { return default_texture; }
    private:
        std::vector<Entry> entries;
        std::unordered_map<std::string, int> names;
        int default_texture = -1;
        bool initialized = false;
        Entry* resolve(int index);
        void load(Entry& entry, std::span<const std::uint8_t> bytes);
    };

    class ModelRepository {
    public:
        struct Entry {
            std::string name;
            std::string directory;
            std::shared_ptr<Model> model;
            std::chrono::steady_clock::time_point last_used;
        };
        void initialize();
        void addFolder(const std::string& directory);
        void finishRegistration();
        int find(std::string_view name) const;
        std::shared_ptr<Model> model(int index);
        void releaseModels();
        void evictUnused(std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now());
        void clear();
        std::size_t count() const { return entries.size(); }
        ModelParameters parameters;
    private:
        std::vector<Entry> entries;
        std::unordered_map<std::string, int> names;
        std::size_t requests_since_scan = 0;
        std::size_t scan_index = 0;
    };
}

extern SphereRender::TextureRepository g_sfera_textures;
extern SphereRender::ModelRepository g_sfera_models;

class CD3D9Device;

class CShaderMgr {
public:
    struct WaterParameters { float gradient = 0.0f; float specular = 0.0f; float reflection = 0.0f; };
    struct Variant {
        std::string filename;
        Microsoft::WRL::ComPtr<IDirect3DPixelShader9> pixel_shader;
        int alpha_register = -1;
        int down_filter_register = -1;
        int water_gradient_register = -1;
        int water_specular_register = -1;
        int water_reflection_register = -1;
    };
    std::map<std::pair<bool, std::array<std::uint8_t, 8>>, Variant> variants;
    std::string vertex_directory;
    std::string pixel_directory;
    std::array<float, 512> wave_samples;
    std::array<float, 64> downsample_offsets;
    CShaderMgr(CD3D9Device& device, std::string vertex_directory, std::string pixel_directory);
    CShaderMgr(const CShaderMgr&) = delete;
    CShaderMgr& operator=(const CShaderMgr&) = delete;
    static std::pair<bool, std::array<std::uint8_t, 8>> instanceCode(std::string_view filename, bool pixel);
    static std::array<float, 512> makeWaveSamples();
    static std::array<float, 64> makeDownsampleOffsets(float width, float height);
    static WaterParameters waterParameters(float environment, float height);
    void loadFolder(const std::string& directory, bool pixel);
    void setPixelShader(std::uint32_t group);
private:
    CD3D9Device& device;
    Variant& loadVariant(const std::pair<bool, std::array<std::uint8_t, 8>>& code);
};

class CPostEffectsMgr {
public:
    bool enabled = false;
    explicit CPostEffectsMgr(CD3D9Device& device);
    ~CPostEffectsMgr();
    CPostEffectsMgr(const CPostEffectsMgr&) = delete;
    CPostEffectsMgr& operator=(const CPostEffectsMgr&) = delete;
    void restoreResources();
    void releaseResources();
    void setEnabled(bool value);
    void beginCapture();
    void cancelCapture() noexcept { capture.reset(); }
    void compose();
private:
    struct ScreenVertex { float x; float y; float z; float rhw; float u; float v; float u2; float v2; };
    CD3D9Device& device;
    std::optional<RenderTargetScope> capture;
    Microsoft::WRL::ComPtr<IDirect3DTexture9> scene_texture;
    Microsoft::WRL::ComPtr<IDirect3DTexture9> blur_texture;
    Microsoft::WRL::ComPtr<IDirect3DTexture9> temporary_texture;
    Microsoft::WRL::ComPtr<IDirect3DVertexDeclaration9> vertex_declaration;
    void configureRenderState();

    void drawQuad(std::uint32_t width, std::uint32_t height);
    void renderToTexture(IDirect3DTexture9* target);
    void blur();
};

struct WaterMaterial {
    std::uint32_t primary_animation;
    std::uint32_t secondary_animation;
    float primary_opacity;
    float secondary_opacity;
    float reflection_opacity;
    float wave_amplitude;
};

struct SferaGraphicsRuntime {
    bool auto_fog{};
    uint32_t reflection_quality{};
    float minimum_lod_distance{};
    float lod_distance{};
    uint32_t grass_depth{};
    uint32_t display_depth_bits = 32u;

    float fog_distance;
    float saved_fog_distance;
    bool lods_enabled;
    bool hardware_cursor_enabled;
    float environment_factor;
    uint32_t base_microtexture_id;
    float view_scale;
    bool post_effects_enabled;
    uint32_t rebuild_percent;
    int display_width;
    int display_height;
    std::unique_ptr<CD3D9Device> d3d_runtime;
    std::array<WaterMaterial, 10> water_materials{};
    void initialize();
    void initializeWater();
};

struct SferaLogRuntime {
    std::string path;
    std::uint32_t size_limit = 0;
    void initialize();
    void write(std::string_view text);
    void write(int number);
    void writeTimestamp(std::string_view prefix);
};

struct SferaConfigTextRuntime {
    enum class Operation : int { Write = 13, Read = 14, Load = 15, Save = 16, Clear = 17, UseText = 30, ReadCommands = 54, SaveCompressed = 55, CopyText = 56, Length = 57, SetFilename = 62 };
    static constexpr std::size_t text_capacity = 2458176u;
    static constexpr std::size_t filename_capacity = 1024u;
    bool load(const std::string& filename);
    bool save(bool compressed = false) const;
    bool writeValue(std::string_view key, std::string_view value, bool quoted);
    static std::string encodeBinary(std::span<const std::uint8_t> input);
    std::string filename;
    std::string text() const;
    std::size_t copyText(std::string_view source);
    void useText(std::uint32_t address, std::size_t capacity, SferaMbcProcessRecord* process);
    void clear(std::string path = {}) { storage_.emplace<std::string>(); filename = std::move(path); }
    std::optional<std::string> find(std::string_view key) const;
    bool readInteger(std::string_view key, int& value) const;
    bool readFloat(std::string_view key, float& value) const;
    std::optional<std::string> readString(std::string_view key) const;
    bool readBinary(std::string_view key, std::span<std::uint8_t> destination) const;
    std::size_t copyTo(std::span<std::uint8_t> destination) const;
private:
    struct BorrowedText {
        std::uint32_t address;
        std::size_t capacity;
        SferaMbcProcessRecord* process;
        std::uint64_t process_lifetime;
        std::uint64_t mapping_lifetime;
    };
    std::variant<std::string, BorrowedText> storage_;
    std::span<std::uint8_t> borrowedBytes(const BorrowedText& view) const;
};

struct SferaErrorLogRuntime {
    IOutputDevice* outputs[2]{};
    std::unique_ptr<CSphereError> owned_error;
    std::unique_ptr<COutputLogDevice> owned_log;
    bool enabled = false;
    std::string user_name;
    void initialize(IOutputDevice* error = nullptr, IOutputDevice* log = nullptr);
    void clear();
};

class WorldDiagnostics {
public:
    static std::string message;

    static constexpr std::uint32_t codeBaseMismatch = 1u << 7u;
    static void appendScriptContext(std::string_view text);
    static void flushScriptContext();
    static std::uint32_t inspectInstruction(std::uint16_t& module, std::uint32_t& offset, std::uint8_t* bytes, std::uint32_t& count);
    static void describeScript(bool includeTime);
    static void appendCallStack(std::string& output);
    static std::optional<std::string_view> scriptContext();
    static void report(std::string_view message);
    static void warning(std::string_view message);
    [[noreturn]] static void fail(std::string_view message);
};
class WorldClock {
public:
    // One process-lifetime epoch for UI, simulation, sound and transport.
    // A legacy tick is exactly 100 microseconds (10,000 ticks per second).
    static std::uint64_t microseconds() noexcept;
    static std::uint64_t nowTicks() noexcept { return microseconds() / 100u; }
    static std::uint32_t milliseconds() noexcept { return static_cast<std::uint32_t>(microseconds() / 1000u); }
    static bool deadlineReached(std::uint32_t now, std::uint32_t deadline) noexcept {
        return std::bit_cast<std::int32_t>(now - deadline) >= 0;
    }
    static std::uint32_t calendarTicks();
};
struct ExtendedWorldObject;
struct WorldObject {
    std::uint64_t resource_lifetime = 0;
    virtual ~WorldObject() = default;
    WorldObject() = default;
    WorldObject(const WorldObject&) = delete;
    WorldObject& operator=(const WorldObject&) = delete;
    ExtendedWorldObject* extended() noexcept;
    const ExtendedWorldObject* extended() const noexcept;
    bool ownsModel() const noexcept { return std::holds_alternative<std::unique_ptr<SphereRender::Model>>(model_source); }

    struct ModelReference {
        int id = 0;
        mutable std::shared_ptr<SphereRender::Model> asset;
    };
    std::variant<ModelReference, std::unique_ptr<SphereRender::Model>> model_source{ModelReference{}};
    SferaVec3F position{};
    SferaVec3F rotation{};
    uint32_t spatial_membership{};
    int32_t grid_min_x{};
    int32_t grid_max_x{};
    int32_t grid_min_y{};
    int32_t grid_max_y{};
    float render_fade{};
    uint32_t render_group{};
    SferaMatrix4x4F world_transform{};
    SferaVec3F bounds_minimum{};
    SferaVec3F bounds_maximum{};
    SferaVec3F bounds_corners[8]{};
    uint32_t visibility_mark{};
    uint32_t linked_objects[5]{};
    SferaActiveEffect* attached_effects[10]{};
    uint32_t lighting_color{};
    bool visible{};
};
struct ExtendedWorldObject : WorldObject {
    static constexpr std::size_t unregistered = std::numeric_limits<std::size_t>::max();
    std::size_t extended_object_index = unregistered;
    uint8_t motion_state{};
    bool render_enabled{};
    bool steep_slope{};
    int32_t render_cache_handle{};
    float scale{};
    SferaVec3F orientation_basis[3]{};
    int32_t animation{};
    int32_t frame{};
    float interpolation{};
    int32_t frame_secondary{};
    int32_t animation_secondary{};
    uint32_t parent_object_handle{};
    uint32_t parent_link_slot{};
    SferaMbcProcessRecord* process_handle{};
    SferaVec3F effect_frame_position_a{};
    SferaVec3F effect_frame_position_b{};
    SferaMatrix4x4F effect_frame_transform_a{};
    SferaMatrix4x4F effect_frame_transform_b{};
    SferaVec3F effect_frame_position_c{};
    SferaMatrix4x4F effect_frame_transform_c{};
    bool simulation_enabled{};
    bool full_rate_simulation{};
    bool gravity_enabled{};

    bool airborne{};
    SferaVec3F commanded_velocity{};
    SferaVec3F physical_velocity{};
    float angular_velocity{};

    bool movement_blocked{};
    bool avoidance_enabled{};

    SferaVec3F avoidance_direction{};
    float avoidance_depth{};
    SferaVec3F previous_spatial_position{};
    SferaVec3F previous_spatial_rotation{};
    SferaVec3F previous_basis_rotation{};
    SferaVec3F previous_bounds_position{};
    SferaVec3F previous_bounds_rotation{};
    std::uint32_t last_simulation_tick{};
};

inline ExtendedWorldObject* WorldObject::extended() noexcept { return dynamic_cast<ExtendedWorldObject*>(this); }
inline const ExtendedWorldObject* WorldObject::extended() const noexcept { return dynamic_cast<const ExtendedWorldObject*>(this); }

class WorldObjects {
public:
    std::uint64_t material_refresh_tick{};
    std::unique_ptr<Contours> contours{};

    uint32_t max_occupied_object_handle;
    uint32_t controlled_object_handle;
    std::vector<std::unique_ptr<WorldObject>> object_handles;
    std::uint32_t next_object_handle = 0;
    std::unordered_set<std::uint32_t> destroying_handles;
    bool clearing = false;
    bool clear_requested = false;
    std::vector<std::uint32_t> extended_object_handles;
    std::size_t extended_object_count;

    WorldObject* effectObject(std::uint32_t handle) const;
    SferaVec3F referencePosition() const;
    SferaVec3F objectPosition(std::uint32_t handle) const;
    bool attachEffect(std::uint32_t handle, SferaActiveEffect& item);
    void detachEffect(std::uint32_t handle, SferaActiveEffect& item);
    SferaActiveEffect* firstEffect(std::uint32_t handle) const;
    SferaEffectFrames buildEffectFrames(std::uint32_t handle) const;
    WorldObject* object(std::uint32_t handle, std::optional<std::string_view> operation = std::nullopt) const;
    WorldObject* object(std::uint32_t, std::nullptr_t) const = delete;
    ExtendedWorldObject* extendedObject(std::uint32_t handle) const;
    WorldObject* controlledObject() const;
    SphereRender::Model* model(const WorldObject& object) const;
    std::uint32_t create(std::string_view name, SferaMbcProcessRecord* process, std::uint32_t kind, bool dynamic);
    void destroy(std::uint32_t handle);
    void destroyAll();
    void clear();
    void removeSpatialIndex(std::uint32_t handle);
    void updateSpatialIndex(std::uint32_t handle);
    void updateExtendedSpatialIndices();
    void rotate(std::uint32_t handle, const SferaVec3F& delta);
    void approachHeading(std::uint32_t handle, float target);
    void moveLocal(std::uint32_t handle, const SferaVec3F& displacement);
    void alignReferenceOrientation();
    void reflectReferenceOrientation();
    void recalculateBasis(std::uint32_t handle);
    void appendCommand(std::uint32_t handle, std::string_view command);
    bool actorActive(std::uint32_t handle) const;
    void activateTrap(const WorldObject& obstacle);
    void addExtended(std::uint32_t handle);
    void removeExtended(std::uint32_t handle);
    void unlink(std::uint32_t parent, std::uint32_t slot);
    ExtendedWorldObject* linkModel(std::uint32_t parent, std::string_view name, std::uint32_t slot);
};

// Runtime terrain storage is independent of the encoded landscape headers.
struct TerrainVertex { SferaVec3F position; SferaVec3F normal; float textureU; float textureV; float detailU; float detailV; };
struct TerrainTriangle { std::uint16_t indices[3]; std::uint16_t material; std::uint32_t attributes[2]; SferaVec3F normal; };
struct TerrainCell {
    int x = 0;
    int z = 0;
    std::vector<TerrainTriangle> triangles;
    std::uint16_t baseMicrotexture = 0;
    std::vector<std::uint16_t> layers;
    std::vector<std::uint8_t> masks;
};
struct TerrainSurfaceGroup { std::size_t vertexCount; std::size_t firstVertex; std::size_t firstIndex; std::size_t colored_vertex_offset; std::uint32_t light_mask; bool distant; };
struct TerrainWater { float height; std::size_t material; };
struct TerrainBounds { SferaVec3F corners[8]; int scaledBounds[6]; void lowerMinimum(float height); };
class TerrainPatch {
public:
    std::vector<TerrainVertex> vertices;
    std::array<TerrainCell, 144> cells{};
    std::array<TerrainSurfaceGroup, 144> surfaceGroups{};
    std::vector<TerrainVertex> groupedVertices;
    std::vector<std::uint16_t> groupedIndices;
    std::array<TerrainWater, 144> waters{};
    TerrainBounds bounds{};
    std::array<TerrainBounds, 4> quarterBounds{};
    std::array<TerrainBounds, 16> groupBounds{};
    std::array<TerrainBounds, 144> cellBounds{};
    std::uint32_t flags = 0;
    std::array<std::vector<std::size_t>, 4> cornerIndices;
    std::array<bool, 4> cornerSmoothed{};
    std::array<std::vector<std::vector<std::size_t>>, 4> edgeGroups;

    void partitionEdges();
    void rebuildSurfaceGroups();
    void updateBounds();
    bool validateEdge(const TerrainPatch& other, std::size_t side, std::size_t otherSide) const;
    bool smoothEdge(TerrainPatch& other, std::size_t side, std::size_t otherSide);
    void smoothCorner(TerrainPatch* diagonal, TerrainPatch* vertical, TerrainPatch* horizontal, std::size_t corner, std::size_t diagonalCorner, std::size_t verticalCorner, std::size_t horizontalCorner);
    void readGeometry(std::span<const std::uint8_t> bytes, std::span<const std::uint8_t> masks, std::span<const std::uint8_t> waterData, std::span<const std::uint16_t, 65536> microtextureRemap, std::uint16_t baseMicrotexture);
};
struct TerrainTextureImage {
    static constexpr std::size_t width = 256;
    static constexpr std::size_t height = 256;
    std::array<std::uint8_t, 32> metadata{};
    std::array<std::uint16_t, width * height> pixels{};
    static std::unique_ptr<TerrainTextureImage> decode(std::span<const std::uint8_t> bytes);
};
class TerrainRegion {
public:
    struct PatchSlot {
        std::unique_ptr<TerrainPatch> patch;
        std::unique_ptr<TerrainTextureImage> texture;
        int texture_id = 0;
        std::uint32_t expiry = 0;
    };
    std::string name;
    std::string directory;
    int rows = 0;
    int columns = 0;
    std::array<PatchSlot, 100> slots;

    TerrainPatch* patch(int row, int column) const;
    void loadPatch(int row, int column);
    void touchPatch(int row, int column);
    void destroyPatch(int row, int column);
};
class TerrainAssets {
public:
    static GrassMapMngr color_map;
    static uint32_t color_map_ready;
    static bool high_resolution_assets;
    static bool alternate_ph_assets;
    static bool alternate_rd_assets;

    struct MapCell {
        TerrainRegion* region;
        std::uint8_t tile_x, tile_y;
    };
    struct Microtexture {
        std::uint16_t lookup_key;
        std::uint32_t texture_id;
        std::unique_ptr<TerrainTextureImage> image;
    };
    static std::vector<Microtexture> microtextures;
    static std::array<MapCell, 6400> map;
    static std::deque<TerrainRegion> regions;
    static std::array<std::uint16_t, 65536> microtexture_remap;
    static void loadMap();
    static void evictUnused();
    static void releaseAll();
};

struct Contour {
    int type = 0;
    struct Vertex { float x = 0.0f, z = 0.0f; int neighbour_contour = -1, neighbour_edge = -1; };
    std::vector<Vertex> vertices;
    float min_x = 1000000.0f;
    float max_x = -1000000.0f;
    float min_z = 1000000.0f;
    float max_z = -1000000.0f;
    void updateBounds();
    bool contains(float point_x, float point_z) const;
};

class Contours {
public:
    std::vector<Contour> records;
    explicit Contours(int first_server_type = 2000, int last_server_type = 2999);
    void clear();
    void load();
    void loadBytes(std::span<const std::uint8_t> bytes);
    std::span<const Contour> typeRange(int first, int last) const;
    bool sameEdge(std::size_t first_contour, std::size_t first_edge, std::size_t second_contour, std::size_t second_edge) const;
    void setServerMap(std::span<const int> types, std::span<const int> servers);
    int serverByType(int type) const;
    void buildServerMask(int server);
    int typeAt(float x, float z, int first_type, int last_type) const;
    int serverAt(float x, float z) const;
    bool nearServer(float x, float z, int server);
    void connectEdges();
    std::vector<std::array<float, 4>> serverBoundaries();
    void rebuildServerWall();
    void rasterizeServers();
private:
    int first_server_type;
    int last_server_type;
    std::vector<std::pair<int, int>> server_map;
    std::array<std::uint8_t, 160 * 160> server_grid{};
    std::array<std::uint8_t, 160 * 160> server_mask{};
    bool grid_initialized = false;
    int mask_server = -1;
    bool isServerContour(const Contour& contour) const;
    void invalidateGrid();
};

struct SferaServerWallEffectRecord {
    SferaVec3F positions[4]{};
    float duration = 0.0f;
    float remaining = -1.0f;
    float animation_phase = 0.0f;
};
struct SferaServerWallTextureFrame { float uv[5][2]{}; };
class SferaServerWall {
public:
    std::vector<std::array<SferaVec3F, 2>> segments;
    std::vector<SferaVec3F> normals;
    std::array<SferaServerWallEffectRecord, 100> effects{};
    std::array<SferaServerWallTextureFrame, 16> texture_frames{};
    int texture_id = -1;
    void clear();
    void setSegments(std::span<const std::array<float, 4>> coordinates);
    void prepareGeometry();
    void generateEffects();
    void generateEffects(const WorldObject& observer, float field_of_view, const SferaFrustumF& frustum);
    void updateEffectRendering();
    static bool intersectPlane(const SferaPlaneF& plane, const SferaVec3F& start, const SferaVec3F& end, SferaVec3F& output);
    static std::uint32_t classifyVisibility(const SferaFrustumF& frustum, std::span<const SferaVec3F> points);
    static int intersectXZ(const SferaVec3F& first, const SferaVec3F& second, const SferaVec3F& other_first, const SferaVec3F& other_second, SferaVec3F& output);
};

namespace SphereWorld {
struct Bounds {
    SferaVec3F minimum{};
    SferaVec3F maximum{};
    bool intersects(const Bounds& other) const;
    bool intersectsInterior(const Bounds& other) const;
    bool contains(const Bounds& other) const;
    bool overlapsTriangle(const SferaVec3F (&vertices)[3]) const;
    Bounds expanded(float amount) const;
    Bounds inverseTransformed(const SferaMatrix4x4F& transform) const;
    SferaBoundsCornersRuntime corners() const;
};
struct SpatialLeaf {
    std::vector<std::uint32_t> objects;
    bool contains_landscape = false;
    TerrainRegion* region = nullptr;
    int patch_row = 0;
    int patch_column = 0;
    int quarter = 0;
    int group = 0;
    int cell = 0;
    float origin_x = 0.0f;
    float origin_z = 0.0f;
};
struct TerrainCandidate { TerrainPatch* patch; const TerrainCell* cell; float origin_x; float origin_z; };
struct NearContact {
    std::uint32_t handle = 0;
    SphereRender::CollisionKind subject_kind = SphereRender::CollisionKind::AxisAlignedBounds;
    SphereRender::CollisionKind geometry_kind = SphereRender::CollisionKind::AxisAlignedBounds;
    Bounds bounds;
    SferaBoundsCornersRuntime corners{};
    std::vector<SphereRender::ModelCollisionTriangle> triangles;
};
class WorldSpatialIndex {
public:
    SphereWorld::Bounds query_bounds{};

    SpatialLeaf* leafAt(int cell_x, int cell_z);
    void insert(std::uint32_t handle, int cell_x, int cell_z);
    void remove(std::uint32_t handle, int cell_x, int cell_z);
    static bool typesInteract(std::uint32_t combined_type);
    void gatherCell(int cell_x, int cell_z, bool include_terrain);
    void forgetTerrain(const TerrainPatch& patch);
    void refreshTerrainBindings() noexcept;
    void gatherObject(std::uint32_t handle);
    void gatherObjects(const SferaVec3F& center, float radius);
    void gatherTerrain(const SferaVec3F& center, float radius);
    std::uint32_t gatherShadowTriangles(const Bounds& bounds, const SferaVec3F& center, float radius, const SferaVec3F& origin, const SferaVec3F& direction);
    const std::vector<std::uint32_t>& objects() const { return objects_; }
    const std::vector<TerrainCandidate>& terrain() const { return terrain_; }
    const std::vector<SferaVec3F>& shadowVertices() const { return shadow_vertices_; }
private:
    std::map<std::pair<int, int>, SpatialLeaf> cells_;
    std::vector<std::uint32_t> objects_;
    std::vector<TerrainCandidate> terrain_;
    std::vector<SferaVec3F> shadow_vertices_;
    void clearCandidates();
    void finishCandidates();
    void addTerrain(TerrainRegion& region, int row, int column, int cell, float origin_x, float origin_z);
};
class ContactQuery {
public:
    SphereWorld::Bounds query_bounds{};

    static bool projectionsOverlap(const SferaBoundsCornersRuntime& first, const SferaBoundsCornersRuntime& second, const SferaVec3F& axis);
    static bool boxesOverlap(const SferaBoundsCornersRuntime& first, const SferaBoundsCornersRuntime& second);
    static int intersectTriangle(const SferaVec3F& start, const SferaVec3F& end, const SphereRender::ModelCollisionTriangle& triangle, SferaVec3F& intersection);
    static void sortTriangles(std::span<SphereRender::ModelCollisionTriangle> triangles);
    static void updateBounds(std::uint32_t handle);
    static bool lineOfSight(std::uint32_t handle);
    void appendBoxNormals(const SferaBoundsCornersRuntime& corners);
    void gather(std::uint32_t handle);
    enum class Mode { Movement, Normals, Support, Material, CollectIgnored };
    std::uint32_t test(std::uint32_t handle, Mode mode, bool reuse_cache, bool honor_ignored = true);
    std::span<const SferaVec3F> normals() const { return normals_; }
    void clearIgnoredObjects() { ignored_.clear(); }
    void clear() { contacts_.clear(); normals_.clear(); ignored_.clear(); }
    SferaVec3F support_normal{};
    std::uint32_t support_direction = 0;
    std::uint32_t surface_material = 0;
    float obstacle_height = 0.0f;
    std::uint32_t testMovement(std::uint32_t handle, bool reuse_cache);
    void setIgnoredObjects(std::span<const std::uint32_t> handles);
    std::span<const NearContact> nearContacts() const { return contacts_; }
private:
    std::vector<NearContact> contacts_;
    std::vector<SferaVec3F> normals_;
    std::vector<std::uint32_t> ignored_;
    void publishNormal(const SferaVec3F& normal);
    void publishDirection(const SphereRender::ModelCollisionTriangle& triangle);
    static bool trianglesHitBox(const SphereRender::Model& model, const SferaMatrix4x4F& transform, const Bounds& query_bounds, const Bounds& local_bounds, const SferaMatrix4x4F* box_transform, const SferaMatrix4x4F* box_basis);
};
}
extern SphereWorld::WorldSpatialIndex g_sfera_world_spatial;
extern SphereWorld::ContactQuery g_sfera_contacts;

namespace SphereWorld {

struct GrassCell {
    std::uint32_t object_handle = 0;
};

struct GrassInstance {
    std::shared_ptr<const SphereRender::Model> model;
    SferaVec3F position{};
    SferaVec3F rotation{};
    float vertical_scale = 1;
    SferaVec3F normal{};
};

class GrassGeometry {
public:
    static std::unique_ptr<SphereRender::Model> build(std::span<const GrassInstance> instances, float height);
};

class VegetationPatterns {
public:
    struct GrassPattern { std::uint32_t id; std::array<std::string, 10> variants; };
    void initializeGrass();
    void addGrass(std::uint32_t id, const std::array<std::string_view, 10>& variants);
    const GrassPattern& grass(std::uint32_t id) const;
private:
    std::vector<GrassPattern> grass_patterns_;
};

class DynamicVegetation {
public:
    explicit DynamicVegetation(std::span<GrassCell> cells);
    void initializeNoise();
    void initializeWind();
    void setReference(const SferaVec3F& position);
    void updateWind(const SferaVec3F& reference, float elapsed);
    void deformGrass(SphereRender::Model& model, const SferaVec3F& position);
    void update();
    void recalculate();
    std::span<const SphereRender::VegetationVertex> output() const { return output_; }
    const std::array<float, 1024>& noise() const { return noise_; }
private:
    struct Gust { bool active = false; float x = 0; float z = 0; float radius = 0; float radius_squared = 0; float speed = 0; };
    SferaVec3F bendingPosition(const SphereRender::Model& model, std::size_t vertex, float first, float second) const;
    void saveCache(SphereRender::Model& model);
    std::span<GrassCell> cells_;
    std::array<Gust, 6> gusts_{};
    std::array<float, 1024> noise_{};
    std::vector<SphereRender::VegetationVertex> output_;
    SferaVec3F reference_{};
    SferaVec3F wind_{};
    float wind_strength_ = 0;
    float phase_ = 0;
    float phase_speed_ = 0;
    float bend_x_ = 0;
    float bend_z_ = 0;
    static std::int64_t last_update_;
};

class Vegetation {
private:
    static constexpr std::uint32_t grid_side = 13;
    std::vector<GrassCell> cells_;
    std::vector<GrassCell> previous_;
    std::vector<std::array<bool, 2>> occupancy_;
    int last_cell_x_ = 100000, last_cell_z_ = 100000;
    std::uint32_t update_phase_ = 0, previous_depth_ = 0;
public:
    uint32_t map_update_phase{};
    GrassMapMngr map_cache{};
    std::uint64_t last_frame_ticks{};

    void initialize();
    void clear();
    void updateGrassView();
    void createCell(int x, int z, GrassCell& cell);
    void updateCells();
    void destroyOwnedModel(std::uint32_t& handle);
    static bool alternatePatterns();
    VegetationPatterns patterns;
    std::unique_ptr<DynamicVegetation> animation;
private:
};

}

extern SphereWorld::Vegetation g_sfera_vegetation;

class TerrainQueries {
public:
    struct Location { int patchX; int patchZ; int cellX; int cellZ; int mapIndex; bool valid() const; int cellIndex() const; };
    static Location locate(float worldX, float worldZ);
    static void sampleColor(float worldX, float worldZ, std::uint32_t& red, std::uint32_t& green, std::uint32_t& blue);
    static bool surface(float worldX, float worldZ, float& height, SferaPlaneF& plane);
    static std::uint8_t placementOrientation(float worldX, float worldZ, SferaVec3F& angles, float& height, SferaPlaneF& plane);
    static bool clearViewToFlare(const TerrainPatch& patch, const TerrainCell& cell);
};
struct TerrainVisibleCell { TerrainCell* cell; SferaBoundsCornersRuntime bounds; };
struct TerrainWaterSurface { int x; int z; float height; std::uint32_t lightMask; std::size_t material; SferaBoundsCornersRuntime bounds; };
class TerrainRenderer {
public:
    SferaVec3F patch_origin{};
    std::vector<TerrainVisibleCell> visibleCells;
    std::vector<TerrainWaterSurface> waterSurfaces;
    static bool visibleBounds(const TerrainBounds& source, const SferaVec3F& anchor, SferaViewProjectionScratchRuntime& translated);
    bool gatherCells(TerrainPatch& patch);
    void findReflectiveWater(TerrainPatch& patch);
    void gatherReflectiveWater();
    void prepareAndDraw(TerrainPatch& patch);
    void drawCells(TerrainPatch& patch, int first, int last);
    void drawLandscape();
    void drawWater();
private:
    void visitPatches(bool draw);
};
extern TerrainRenderer g_sfera_terrain_renderer;
struct TerrainTextureEntry {
    const TerrainCell* owner = nullptr;
    uint8_t kind = 0;

    Microsoft::WRL::ComPtr<IDirect3DTexture9> resource;
    uint32_t use_count = 0;
};

class TerrainTextureCache {
public:
    static std::array<TerrainTextureEntry, 50> entries;
    static uint8_t quantization_x[3072];
    static uint8_t quantization_y[3072];
    static uint8_t blend_lut[16385];

    static void initialize();
    static void bindLayer(const TerrainCell& cell, int layer);
    static void release();
    static void blendLayer(const TerrainCell& cell, int layer, TerrainTextureImage& texture);
};

namespace SphereWorld {
class Motion {
public:
    uint32_t control_mode{};
    uint8_t tracking_position_pending{};
    uint8_t moved_since_query{};
    SferaVec3F tracked_position{};
    float response_curve[100]{};
    SferaVec3F acceleration{};
    SferaVec3F displacement{};
    float surface_friction[7]{};
    float material_scale[7]{};
    uint32_t orientation_blocked{};

    void initializeResponseCurve();
    double responseValue(int index) const noexcept;
    std::uint32_t probe(std::uint32_t handle, SferaVec3F displacement, float yaw);
    std::uint32_t probeGround(std::uint32_t handle, SferaVec3F displacement, float yaw, bool controlled = false);
    void moveFree(std::uint32_t handle, bool vertical, float yaw, float elapsed, bool controlled);
    void moveGround(std::uint32_t handle, float yaw, float elapsed, bool controlled);
    void fall(std::uint32_t handle, float elapsed, bool controlled);
    void updateObjects(float elapsed);
    void updateControlled(float elapsed);
    void updateOrientation();
    std::uint32_t surfaceInteraction(std::uint32_t handle, std::uint32_t* material);
    std::uint32_t pick(float* distance, SferaVec3F* direction);
    static bool snapSmallComponents(SferaVec3F& value) noexcept;
private:
    bool avoidContact(std::uint32_t handle, SferaVec3F displacement, float yaw, bool grounded);
    bool slideControlled(std::uint32_t handle, const SferaVec3F& displacement);
    void dampMotion(std::uint32_t handle, float elapsed, bool controlled);
};
}
extern SphereWorld::Motion g_sfera_motion;

struct GameUiElement;
class WorldGuiControls {
public:
    static uint32_t text_height;
    static uint32_t text_width;

    static std::vector<std::unique_ptr<GameUiElement>> elements;
    static std::uint32_t createText(int x, int y, std::string_view text, std::uint32_t window);
    static std::uint32_t createSprite(int x, int y, int width, int height, std::string_view texture, std::uint32_t window, std::uint32_t alpha);
    static void setAppearance(std::uint32_t handle, std::uint32_t alpha, std::optional<std::uint32_t> color = std::nullopt);
    static void destroyAllText();
    static GameUiElement* control(std::uint32_t handle);
    static void detachFromWindow(std::uint32_t window, std::uint32_t slot);
    static void destroySprite(std::uint32_t handle);
    static void destroyText(std::uint32_t handle);
    static void removeForObject(std::uint32_t handle);
};
namespace SphereRender {
class ModelPose {
public:
    static bool inverted_fade_pass;
    static bool secondary_enabled;
    static std::size_t primary_frame;
    static SferaVec3F scale;
    static SferaVec3F translation;
    static SferaVec3F attachment_102_position;
    static SferaVec3F attachment_101_position;
    static SphereRender::Model* active_model;
    static float blend;
    static std::size_t secondary_frame;
    static SferaMatrix4x4F coordinate_basis;
    static SferaMatrix4x4F current_frame;

    static std::vector<SferaMatrix4x4F> bone_transforms;
    static std::array<SferaMatrix4x4F, 5> attachment_transforms;
    static void updateBone(const SferaMatrix4x4F& parent, std::size_t bone_index);
    static int animationLength(std::uint32_t handle, int animation);
    static int* animation(std::uint32_t handle);
    static int* frame(std::uint32_t handle);
    static float* interpolation(std::uint32_t handle);
    static int* secondaryFrame(std::uint32_t handle);
    static int* secondaryAnimation(std::uint32_t handle);
    static SferaVec3F* neckPosition(SferaVec3F& output);
private:
    static ModelKeyframe keyframe(const Model& model, const BoneAnimation& animation, std::size_t frame);
    static ExtendedWorldObject* queryObject(std::uint32_t handle, std::string_view operation);
    static std::size_t frameOffset(const Model& model, int animation, int frame, bool secondary);
};
}

namespace SphereRender {
struct CharacterPose { SferaVec4F rotation; SferaVec3F translation; };
struct CharacterSkeleton {
    enum class Region { Whole, UpperBody, LowerBody };
    std::vector<std::optional<std::size_t>> parents;
    std::vector<std::string> names;
    std::vector<std::vector<std::size_t>> children;
    std::vector<CharacterPose> poses;
    std::vector<std::size_t> animation_lengths;
    std::array<std::size_t, 7> attachments{};
    std::vector<SferaMatrix4x4F> initial_pose;
    void calculate(std::size_t firstFrame, std::optional<std::size_t> upperFrame, std::size_t bone,
        const SferaMatrix4x4F& parent, Region region, SferaMatrix4x4F* output) const;
    std::size_t absoluteFrame(int animation, int frame) const;
};
struct CharacterVertex { SferaVec3F position; SferaVec3F normal; float u; float v; std::size_t first_bone; std::size_t second_bone; float weight; };
struct CharacterGeometry { std::vector<CharacterVertex> vertices; std::vector<std::uint16_t> indices; };
struct CharacterAsset { std::string name; std::size_t directory = 0; std::unique_ptr<CharacterGeometry> geometry; };
struct CharacterPart { std::size_t asset = 0; std::array<int, 20> textures{}; };
struct CharacterAppearance { int sex; std::uint8_t parts[16]; };
struct CharacterSlot { ExtendedWorldObject* owner = nullptr; CharacterAppearance appearance{}; };
class CharacterModels {
public:
    float maximum_distance = 0.0f;
    float minimum_distance = 0.0f;
    SferaMatrix4x4F root_transform = SferaMatrix4x4F::identity();
    std::array<SferaVec3F, 8> bounds{};
    std::array<CharacterSkeleton, 2> skeletons;
    std::vector<std::string> directories;
    std::vector<CharacterAsset> assets;
    std::vector<CharacterPart> parts;
    std::array<std::array<std::array<std::optional<std::size_t>, 256>, 26>, 2> part_indices{};
    std::array<CharacterSlot, 400> instances{};
    std::array<int, 21> small_helm{};
    std::uint64_t last_lod_update = 0;
    std::size_t rendered_count = 0;
    float lod_start = 0.0f;
    float lod_end = 0.0f;

    void load(std::span<const std::string_view> folders);
    void clear();
    void initializeBounds();
    int classify(const SferaMatrix4x4F& world) const;
    void setDistances(float minimum, float range);
    void updateLodDistance();
    double visibility(const WorldObject& object) const;
    void setAppearance(int handle, const CharacterAppearance& appearance);
    bool getAppearance(int handle, CharacterAppearance& appearance) const;
    int partAnimationLength(const ExtendedWorldObject& object, int animation) const;
    int usesSmallHelm(int sex, int code) const;
    void loadSkeleton(const std::string& path, CharacterSkeleton& skeleton);
    void preload(CharacterAsset& asset, const CharacterSkeleton& skeleton);
    void animate(const CharacterSkeleton& skeleton, int animation, int frame, int secondaryAnimation, int secondaryFrame, float interpolation, SferaMatrix4x4F* output, bool attachmentsOnly) const;
    SferaVec3F neckPosition(const ExtendedWorldObject& object) const;
    void drawPart(int sex, int kind, std::uint8_t model, int visibility, const CharacterSkeleton& skeleton, const SferaMatrix4x4F* pose, bool cull, int transparent, int textureCode, std::uint32_t passes);
    void drawLowDetail(std::uint32_t handle);
    void draw(std::uint32_t handle, std::uint32_t color);
    static HRESULT setMaterial(float opacity, float detail, const SferaVec3F& color);
    static int textureVariants(bool female, std::string_view part);
    static std::uint32_t* parameter(std::span<std::uint32_t> values, int index);
    static ExtendedWorldObject* checkedExtended(WorldObject* object);
private:
    const CharacterAppearance& appearance(const ExtendedWorldObject& object) const;
    void updateEffectFrames(ExtendedWorldObject& object, const CharacterSkeleton& skeleton, std::span<SferaMatrix4x4F> pose, const SferaMatrix4x4F& world) const;
};
}

namespace SphereRender {
struct CameraRectangle { int left = 0, top = 0, right = 0, bottom = 0; bool operator==(const CameraRectangle&) const = default; };
class GameCamera {
public:
    uint32_t controlled_observer_mode{};
    SferaVec3F frame_corners[5]{};
    SferaMatrix4x4F frame_transform{};

    GameCamera();
    SferaMatrix4x4F transform = SferaMatrix4x4F::identity();
    float near_distance = 1.0f, far_distance = 100.0f, field_of_view = 1.0f;
    float pixel_scale_x = 0.0f, pixel_scale_y = 0.0f, center_x = 0.0f, center_y = 0.0f;
    float minimum_depth = 0.0f, maximum_depth = 0.9999899864196777f, aspect_scale = 0.75f;
    std::uint32_t viewport_x = 0u, viewport_y = 0u, viewport_width = 640u, viewport_height = 480u;
    float tangent_half_fov = 0.0f;
    float offset_x = 0.0f, offset_y = 0.0f, window_width = 1.0f, window_height = 1.0f, window_depth = 1.0f;
    bool off_axis = false;
    void setViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height, float aspect);
    void setPerspective(float near_plane, float far_plane, float angle);
    void setTransform(const SferaMatrix4x4F& matrix);
    void transformPoints(std::span<SferaVec3F> destination, std::span<const SferaVec3F> source) const;
    SferaVec3F cameraPoint(const SferaVec3F& world) const;
    bool project(const SferaVec3F& world, SferaVec3F& screen) const;
    bool projectObjectTop(std::uint32_t handle, SferaVec3F& output, float height_factor) const;
    void volume(const CameraRectangle* rectangle, const SferaFrustumF** planes, const SferaVec3F** points);
    static void cameraAxes(SferaVec3F& forward, SferaVec3F& up);
    static void setupViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height);
    static void rebuildVisibleVolume(int left, int top, int right, int bottom);
    class Frame {
    public:
        Frame(std::uint32_t mode, bool reflection, float water_height);
        Frame(const Frame&) = delete;
        Frame& operator=(const Frame&) = delete;
        ~Frame() noexcept;
    private:
        std::uint32_t controlled_handle_ = UINT32_MAX;
        SferaVec3F controlled_position_{}, camera_position_{}, camera_rotation_{};
        bool restore_camera_ = false;
    };
private:
    CameraRectangle rectangle_{};
    std::array<SferaVec3F, 6> points_{};
    SferaFrustumF planes_{};
    bool points_current_ = false, planes_current_ = false;

    void buildPoints();
    void buildPlanes();
    static SferaPlaneF boundaryPlane(const SferaVec3F& first, const SferaVec3F& second, const SferaVec3F& third);
};
}
extern SphereRender::GameCamera g_sfera_camera;

struct EnvironmentLighting;
namespace SphereRender {
struct SceneSortEntry { std::uint32_t object; std::size_t key; float distance; };
class SceneRenderer {
public:
    static EnvironmentLighting environment;
    static SferaVec3F sun_direction;
    static bool interior_scene;
    static uint32_t visible_character_parts;
    static uint32_t terrain_texture;
    static float reflection_distance;
    static float view_distance;
    static SferaFrustumF frustum;
    static uint32_t shadow_projection_opacity;
    static uint32_t model_visibility;
    static float reflection_height;
    static bool use_default_environment;
    static SferaRenderLookupEntry bone_visibility[256];
    static uint32_t texture_animation_frame;
    static uint32_t secondary_pass;
    static SferaIntBounds3 projected_terrain_bounds;
    static SferaIntBounds3 clipped_terrain_bounds;
    static uint8_t color_remap[256];
    static uint32_t fog_adaptation_delay;
    static std::unique_ptr<SphereRender::CharacterModels> characters;
    static std::unique_ptr<EnvironmentZones> environment_zones;
    static std::unique_ptr<EnvironmentZones> alternate_environment_zones;

    static bool effectVisible(const IEffect& effect, const SferaVec3F& position);
    static std::vector<SceneSortEntry> object_order;

    static bool bindTexture(int texture);
    static void textureSize(int texture, std::uint32_t* dimensions);
    static void setAmbientColor();
    static void setMaterialColor(int red, int green, int blue);
    static void setObjectMaterial(WorldObject& object, std::uint32_t shade, const std::array<float, 3>& variation);
    static std::uint32_t terrainShade(std::uint32_t shade, float x, float z);
    static void buildColorRemap(double exponent, double floor);
    static void modelFade(float distance, float power, float& fade, float& remaining);
    static std::uint32_t materialVariant(std::uint32_t first, std::uint32_t second, std::uint32_t third);
    static bool hasMaterialVariant(std::uint32_t object, int variant);
    static void setMaterialVariant(std::uint32_t object, int variant);
    static std::uint32_t setOpacity(std::uint32_t opacity);
    static void adaptFog();
    static void raiseDistantObject(std::uint32_t object);
    static void collectLights();
    static void activateObjectLights(std::uint32_t object);
    static void classifyBone(std::size_t bone);
    static void drawModel(std::uint32_t handle);
    static void drawObject(std::uint32_t handle);
    static void drawObjects(bool updateVegetation);
    static void drawPass(std::uint32_t mode);
    static void drawMinimap();
    static void drawReflection();
    static void drawFrame();
    static SferaVec3F& observerPosition(SferaVec3F& output);
    static void setupEnvironment(std::uint32_t mode, bool useDefault, float time);
};
}

struct SceneSkyLayer {
    std::string texture;
    float projectionWarp = 0.0f;
    float uvScale = 0.0f;
    bool trackOffset = false;
    float minimumTime = 0.0f;
    float maximumTime = 0.0f;
    std::array<SferaVec3F, 11> colors{};
};
struct SceneSkyLayers { SceneSkyLayer primary; SceneSkyLayer secondary; float opacity; };
class SceneSky {
public:
    static uint32_t layer_alpha[120];
    static float sample_elevation;
    static float horizontal_motion;
    static float azimuth_samples[125];
    static float screen_center_y;
    static float sample_azimuth;
    static SferaScreenVertex sun_quad[4];
    static uint32_t inverse_opacity;
    static float cloud_offset_y;
    static float cloud_offset_x;
    static float sun_glow;
    static std::unique_ptr<SkyEnvironment> high_resolution_environment;
    static uint16_t indices[594];
    static float motion_terms[5];
    static SferaVec3F previous_origin;
    static SferaVec3F projected_offset;
    static SferaVec3F projected_center;
    static float texture_phase_v;
    static float glow_samples[120];
    static float elevation_samples[120];
    static float texture_phase_u;
    static uint32_t sample_visible[120];
    static float screen_center_x;
    static float vertical_motion;
    static uint32_t sample_color;
    static uint32_t flare_visible;
    static float animation_phase;
    static SferaVec3F flare_world_position;
    static std::unique_ptr<SkyEnvironment> environment;
    static SferaScreenVertex vertices[120];
    static SferaVec3F flare_screen_position;
    static SkyState interpolated;

    static void rotateUv(float x, float y, float angle, float& u, float& v);
    static std::size_t buildLayerGeometry(const SceneSkyLayer& layer, float opacity);
    static void layerColor(const SceneSkyLayer& layer, SferaVec3F& output);
    static void drawColorLayer(std::string_view texture, const SferaVec3F& color, std::size_t indices);
    static void drawMaskLayer(std::string_view texture, std::size_t indices);
    static void drawLayers(const SceneSkyLayers& layers);
    static void orbit(float& x, float& y, std::uint32_t orbit);
    static float horizonFog(float elevation, float amount);
    static void sampleDirection(bool refresh, const SferaVec3F& direction);
    static double drawStars();
    static void drawSunMoon(float rotation);
};

struct ShadowPoint { float x = 0.0f; float y = 0.0f; };
class ShadowRasterizer {
public:
    struct Span { int left = INT32_MAX; int right = INT32_MIN; std::uint32_t color = UINT32_MAX; };
    struct Row { Span active; Span displaced; };
    std::array<Row, 256> rows{};
    bool pending = false;
    void polygon(std::uint32_t color, std::span<const ShadowPoint> points, int width, int height, const D3DLOCKED_RECT& surface);
    void flush(int height, const D3DLOCKED_RECT& surface);
private:
    void flushSpans(int height, const D3DLOCKED_RECT& surface, bool displaced);
};

class ShadowMap {
public:
    std::uint8_t quality = 0u;
    std::uint8_t level = 0u;
    SferaVec3F direction{};
    SferaVec3F origin{};
    float fade = 1.0f;
    bool valid = false;
    SferaMatrix4x4F projection{};
    SferaMatrix4x4F light_basis{};
    ShadowMap() = default;
    ShadowMap(const ShadowMap&) = delete;
    ShadowMap& operator=(const ShadowMap&) = delete;
    void createTextures();
    void setDirection(const SferaVec3F& value, float opacity);
    void selectObjectLight(const WorldObject& object);
    float projectionExtension(const WorldObject& object) const;
    bool prepareModel(WorldObject& object, const SferaVec3F* position, float opacity, std::uint8_t detail);
    bool prepareGeometry(WorldObject& object, const SferaVec3F* position, float opacity, std::uint8_t detail, float scale, float spot_scale);
    void projectModel(const SphereRender::Model& model, std::size_t submesh, const SferaMatrix4x4F* world = nullptr);
    template<class Vertex> void projectVertices(const Vertex* vertices, std::size_t vertex_count, const std::uint16_t* indices, std::size_t index_count);
    void draw(const SferaVec3F* vertices, std::size_t triangle_count);
    // A complete object's projection owns the temporary light state and texture mapping.
    class Pass {
    public:
        explicit Pass(ShadowMap& owner);
        ~Pass() noexcept;
        Pass(const Pass&) = delete;
        Pass& operator=(const Pass&) = delete;
    private:
        ShadowMap& owner_;
        SferaRestore<SferaVec3F> direction_;
        SferaRestore<float> fade_;
        SferaRestore<SferaMatrix4x4F> basis_;
    };
    static void initialize(std::uint32_t default_quality);
    static void shutdown();
    static void prepareObject(std::uint32_t handle, ExtendedWorldObject& object, float width, float spot_scale, float& extension);
    static void drawObject(ExtendedWorldObject& object, float width, float extension);
private:
    std::array<Microsoft::WRL::ComPtr<IDirect3DTexture9>, 3> textures;
    std::optional<TextureMapping> mapping;
    int spot_texture = -1;
    std::uint32_t raster_color = 0u;
    std::uint32_t spot_color = UINT32_MAX;
    ShadowRasterizer rasterizer;
    std::vector<ShadowPoint> projected_points;
    std::array<std::uint16_t, 1002> face_indices{};
    std::array<SphereRender::PositionColorUvVertex, 501> spot_vertices{};
    D3DSURFACE_DESC surface{};

};
extern std::unique_ptr<ShadowMap> g_sfera_shadows;

struct SkyState {
    struct GradientKey { SferaVec4F color{}; float position = 0.0f; };
    std::array<GradientKey, 10> primary{};
    SferaVec4F reference{};
    std::array<GradientKey, 6> secondary{};
    float time = 0.0f;
    float sunPhase = 0.0f;
    SferaVec3F sunColor{};
    SferaVec3F ambientColor{};
};
class SkyEnvironment {
public:
    std::array<SkyState, 11> states{};
    int sunsetState = 0;
    int sunriseState = 0;
    void load(const std::string& filename);
    void interval(float time, int& first, int& second, float& fraction) const;
    void sample(float time, SkyState& output) const;
    void sunDirection(float time, SferaVec3F& output) const;
    void lighting(float time, SferaVec3F& sun, SferaVec3F& ambient) const;
};

struct EnvironmentLighting { SferaVec3F fogParameters; SferaVec3F fogColor; SferaVec3F ambientColor; SferaVec3F sunColor; };
struct EnvironmentZone {
    float originX, originZ, minimumX, maximumX, minimumZ, maximumZ, borderFade;
    SferaVec3F fogParameters;
    std::array<SferaVec3F, 8> fogColors{};
    std::array<SferaVec3F, 8> ambientColors{};
    std::array<SferaVec3F, 8> sunColors{};
    float weight(float x, float z) const;
    void sample(int first, int second, float fraction, EnvironmentLighting& output) const;
};
class EnvironmentZones {
public:
    static void interval(float time, int& first, int& second, float& fraction);
    void load(const std::string& filename);
    void calculate(bool useDefault, float x, float z, float time, const SkyEnvironment& sky, EnvironmentLighting& output);
    std::vector<EnvironmentZone> zones;
};

struct WeatherState {
    float rain = 0.0f;
    float lightning = 0.0f;
    float wind = 0.0f;
    float cloud = 0.0f;
    SceneSkyLayers sky{};
    SceneSkyLayers clouds{};
    float windX = 0.0f;
    float windZ = 0.0f;
};

struct WeatherSkyPair { std::string primary; std::string secondary; bool operator==(const WeatherSkyPair&) const = default; };
struct WeatherKeyframe { int time; std::array<float, 4> properties; };
struct WeatherScenario { int duration = 0; WeatherSkyPair sky; float skyStart = 0.0f; float skyEnd = 0.0f; std::vector<WeatherKeyframe> keyframes; };
class WeatherScenarios {
public:
    enum class Property { rain, lightning, wind, cloud };
    std::vector<SceneSkyLayer> textures;
    std::vector<WeatherSkyPair> pairs;
    std::vector<WeatherScenario> scenarios;
    std::vector<std::uint16_t> sequence;
    int totalDuration = 0;
    int lastUpdate = 0;
    void load(const std::string& filename);
    void update(int time, float dayTime, WeatherState& output, bool alternateClouds);
    void locate(int time, std::size_t& sequenceIndex, int& startTime, int& localTime) const;
    int advance(std::size_t& sequenceIndex, std::size_t& keyframe) const;
    int retreat(std::size_t& sequenceIndex, std::size_t& keyframe) const;
    double nextValue(std::size_t sequenceIndex, int time, Property property, int& distance) const;
    double previousValue(std::size_t sequenceIndex, int time, Property property, int& distance) const;
    WeatherSkyPair selectSky(int time, float dayTime) const;
    void copyTexture(std::string_view name, SceneSkyLayer& output) const;
    static void windDirection(bool refresh, int seed, float& x, float& z);
private:
    const WeatherScenario& at(std::size_t sequenceIndex) const;
};

struct SferaWeatherRuntime {
    float direction_cos_component = 0.0f;
    float direction_sin_component = 0.0f;
    std::unique_ptr<WeatherScenarios> standard;
    std::unique_ptr<WeatherScenarios> highres;
    WeatherState current;
};

namespace SphereUI {
class ChatFilter {
public:
    struct Rule { std::string word; std::uint32_t kind = 0u; std::vector<std::string> exceptions; };
    ChatFilter();
    explicit ChatFilter(std::vector<Rule> entries);
    bool rejects(std::string_view message) const;
    static bool invalidIdentifier(std::string_view name);
    static std::string normalize(std::string_view text, std::size_t alphabet);
private:
    std::vector<Rule> rules;
    bool matchesWord(std::string_view word, std::size_t alphabet) const;
    bool matchesMessage(std::string_view message, std::size_t alphabet) const;
};
}

struct GameUiWindow {
    enum TextStyle : std::uint32_t { centerHorizontal = 1u, centerVertical = 2u, fitHorizontal = 4u, fitVertical = 8u, centerLines = 16u, measureOnly = 32u, alignBottom = 64u };
    bool visible;
    bool scrollable;
    std::uint32_t opacity;
    int left, right, top, bottom;
    int contentLeft, contentRight, contentTop, contentBottom;
    int width, height;
    float scrollX, scrollY;
    std::uint32_t layer;
    std::vector<std::uint32_t> controls;
    std::uint64_t resource_lifetime = 0;
    std::uint32_t order;
    std::uint32_t textColor = 0u;
    std::uint32_t textStyle = 0u;
    int font = 0u;
    std::uint32_t fontScale = 1u;
    struct Event { std::uint32_t control, message; };
    std::deque<Event> events;
    std::uint32_t attach(std::uint32_t control);
    void detach(std::uint32_t slot);
    void recalculateSize();
    void enqueueInput(std::uint32_t control, std::uint32_t message);
    bool takeInput(std::uint32_t& control, std::uint32_t& message);
    SferaCursorPosition contentPosition(SferaCursorPosition point) const;
    void scrollBy(float dx, float dy, SferaCursorPosition& cursor);
};
struct GameUiHit { std::uint32_t window = 0u; std::uint32_t control = UINT32_MAX; bool border = false; };
struct GameUiElement {
    struct Text {
        struct Line { std::size_t offset; int x = 0, y = 0; };
        std::string bytes;
        std::vector<Line> lines;
        std::uint32_t font_scale = 1;
        int font = 0;
    };
    struct Sprite {
        std::string texture;
        int left = 0, top = 0, width = 0, height = 0;
    };
    std::variant<Text, Sprite> content = Text{};
    std::uint32_t windowHandle = 0, windowSlot = UINT32_MAX;
    std::uint32_t objectHandle = UINT32_MAX;
    std::uint64_t resource_lifetime = 0;
    int left = 0, top = 0, right = 0, bottom = 0;
    float height_factor = 1.0f;
    std::uint32_t color = 0, alpha = 255;
    bool isText() const noexcept { return std::holds_alternative<Text>(content); }
    void layoutText(std::string_view text, const GameUiWindow& window, int x, int y);
};

class GameInterface {
public:
    static uint32_t loading_completed;
    static SferaScreenVertex sprite_quad[4];
    static uint32_t active_window;
    static uint32_t loading_total;
    static uint32_t loading_guard;

    static std::vector<std::unique_ptr<GameUiWindow>> windows;
    inline static constexpr std::string_view nativeWindowClassName = "SphereWclName";
    static void registerNativeWindowClass();
    static void createNativeWindow();
    static GameUiWindow* window(std::uint32_t handle, std::string_view operation = {});
    static std::uint32_t createWindow(int left, int top, int right, int bottom, std::uint32_t layer, std::uint32_t opacity);
    static void destroyWindow(std::uint32_t handle);
    static GameUiHit hitTest(SferaCursorPosition point);
    static void updateInput();
    static std::uint32_t fontHeight(int font, std::uint32_t scale);
    static std::uint32_t glyphWidth(std::uint32_t character, int font);
    static std::uint32_t textHeight(int font, std::uint32_t scale, std::uint32_t lines);
    static std::uint32_t lineOffset(int font, std::uint32_t scale, std::uint32_t line);
    static void drawAtlasText(std::string_view text, int x, int y, std::uint32_t color, int scale, int font, float depth);
    static HRESULT drawSpriteQuad(std::uint32_t color, const float* uv, float left, float top, float right, float bottom);
    static HRESULT drawSpriteTexture(std::uint32_t color, int texture, float left, float top, float right, float bottom, const float* uv, bool reserved = false);
    static void drawTexture(int left, int top, int width, int height, std::string_view name, std::uint32_t alpha, float depth, const float* uv);
    static void tintTexture(int left, int top, int width, int height, std::string_view name, std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint32_t alpha, const float* uv);
    static void drawFullscreenOverlay();
    static void setRenderState();
    static void restoreRenderState();
    static void drawFrame();
    enum class WindowOrder { Draw, HitTest };
    static std::vector<int> orderedWindows(WindowOrder order);
    static void drawAll();
    static void drawWindow(int window);
    static void updateLoadingProgress(std::uint32_t increment);
    static void finishLoading();
};

struct SferaFontGlyphRuntime {
    uint32_t texture_index;
    float u;
    float v;
    bool defined;
};
class GameFontAtlas {
public:
    struct Face {
        std::uint32_t span = 0;
        std::uint32_t origin = 0;
        std::uint32_t cell_step = 0;
        std::uint32_t code_base = 0;
        std::array<std::uint32_t, 256> widths{};
        std::vector<Microsoft::WRL::ComPtr<IDirect3DTexture9>> pages;
        IDirect3DTexture9* texture(std::size_t page) const noexcept {
            return page < pages.size() ? pages[page].Get() : nullptr;
        }
    };
    std::string language_suffix;
    // The existing character map is shared by all faces; its reload policy is unchanged.
    SferaFontGlyphRuntime glyphs[256]{};
    std::array<Face, 5> faces;
    GameFontAtlas() = default;
    GameFontAtlas(const GameFontAtlas&) = delete;
    GameFontAtlas& operator=(const GameFontAtlas&) = delete;
    void clear() noexcept;
    void load(int font, const std::string& filename, int outline, std::uint32_t spacing, std::uint32_t emptyWidth);
};

extern GameFontAtlas g_sfera_font_runtime;

extern PlayerLists g_sfera_player_lists;

struct IDirectInput8A;
struct IDirectInputDevice8A;

struct SferaMouseInputState {
    int dx = 0;
    int dy = 0;
    std::uint32_t buttons = 0;
    int wheel = 0;
};

class SferaInputDevices {
public:
    uint32_t key_bindings[64]{};
    uint32_t binding_key{};
    SferaMouseInputState mouse{};
    uint32_t character{};
    uint32_t binding_capture{};
    uint32_t virtual_key{};
    std::deque<std::uint32_t> key_queue;
    uint32_t text_filter{};
    uint8_t allowed_glyphs[256]{};
    uint32_t scan_code{};
    std::deque<std::uint32_t> character_queue;

    static constexpr std::uint8_t pressedMask = 1u << (std::numeric_limits<std::uint8_t>::digits - 1);
    SferaInputDevices();
    SferaInputDevices(const SferaInputDevices&) = delete;
    SferaInputDevices& operator=(const SferaInputDevices&) = delete;
    ~SferaInputDevices();
    Microsoft::WRL::ComPtr<IDirectInput8A> direct_input;
    Microsoft::WRL::ComPtr<IDirectInputDevice8A> mouse_device;
    Microsoft::WRL::ComPtr<IDirectInputDevice8A> keyboard_device;
    std::uint8_t keyboard_state[256]{};
    std::uint8_t view_adjust_state = 0;
    std::uint8_t modifier_08 = 0;
    std::uint8_t modifier_20 = 0;
    void initialize(HWND window);
    void release() noexcept;
    void focusChanged(bool focused) noexcept;
    void pollKeyboard();
    std::uint32_t takeKeyPress();
    SferaMouseInputState pollMouse();
};

extern SferaInputDevices g_sfera_direct_input_runtime;

