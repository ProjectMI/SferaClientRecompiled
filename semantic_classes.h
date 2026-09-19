#pragma once

#include <winsock2.h>
#include <d3d9.h>
#include <mmsystem.h>
#include <cstdio>
#include <cstdarg>
#include <atomic>
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
struct SferaIntrusiveListHeader;
class StdAllocator;
struct SferaMbcProcessRecord;
struct SferaScriptContainer;

namespace SferaBinary {
    template<class T> requires (std::is_integral_v<T> && !std::is_same_v<T, bool>)
    T readLittleEndian(const std::uint8_t* bytes) noexcept {
        using Unsigned = std::make_unsigned_t<T>;
        Unsigned value = 0;
        for (std::size_t index = 0; index < sizeof(T); ++index) value |= static_cast<Unsigned>(static_cast<Unsigned>(bytes[index]) << (index * 8));
        return std::bit_cast<T>(value);
    }
    template<class T> requires (std::is_integral_v<T> && !std::is_same_v<T, bool>)
    void writeLittleEndian(std::uint8_t* bytes, T value) noexcept {
        const auto bits = std::bit_cast<std::make_unsigned_t<T>>(value);
        for (std::size_t index = 0; index < sizeof(T); ++index) bytes[index] = static_cast<std::uint8_t>(bits >> (index * 8));
    }
}

struct SferaVec3F {
    float x;
    float y;
    float z;

    SferaVec3F operator+(const SferaVec3F& other) const;
    SferaVec3F operator-(const SferaVec3F& other) const;
    SferaVec3F operator*(float factor) const;
    double dot(const SferaVec3F& other) const;
    SferaVec3F normalized(std::int32_t diagnosticCode = 0) const;
    void normalize();
    SferaVec3F cross(const SferaVec3F& other) const;
    float component(std::size_t axis) const;
    void setComponent(std::size_t axis, float value);
    static void rotatePair(float& first, float& second, float angle);
    bool containsConvexPolygonPoint(std::span<const SferaVec3F* const> vertices, const SferaVec3F& point) const;
};

class SferaAngle8 {
public:
    explicit SferaAngle8(float radians);
    float distanceTo(SferaAngle8 other) const;
private:
    std::uint8_t steps;
};

struct SferaVec4F {
    float x;
    float y;
    float z;
    float w;
};

struct SferaMatrix3x3F {
    float m[3][3];
};

struct SferaQuaternionF {
    float w;
    float x;
    float y;
    float z;

    SferaMatrix3x3F rotationMatrix() const;
    SferaQuaternionF interpolated(const SferaQuaternionF& other, float factor) const;
};

struct SferaMatrix4x4F {
    enum class Axis { x, y, z };
    float m[4][4];

    static SferaMatrix4x4F identity();
    static SferaMatrix4x4F fromAxisRotation(Axis axis, float angle);
    static SferaMatrix4x4F fromRollPitchYaw(float roll, float pitch, float yaw);
    static SferaMatrix4x4F fromEuler(const SferaVec3F& translation, const SferaVec3F& angles);
    static SferaMatrix4x4F fromQuaternion(const SferaQuaternionF& rotation, const SferaVec3F& translation = {});
    SferaVec3F transformPoint(const SferaVec3F& point) const;
    SferaVec3F inverseTransformPoint(const SferaVec3F& point) const;
    SferaMatrix4x4F multiplied(const SferaMatrix4x4F& other) const;
    SferaMatrix4x4F transposed() const;
    void scaleAxes(const SferaVec3F& scale);
};

struct SferaBoundsCornersRuntime {
    SferaVec3F corners[8];

    static SferaBoundsCornersRuntime fromExtents(const SferaVec3F& minimum, const SferaVec3F& maximum);
    static SferaBoundsCornersRuntime empty();
    void getExtents(SferaVec3F& minimum, SferaVec3F& maximum) const;
};

struct SferaPlaneF {
    SferaVec3F normal;
    float distance;

    double evaluate(const SferaVec3F& point) const;
    int intersectLine(const SferaVec3F& start, const SferaVec3F& end, SferaVec3F& intersection) const;
};

struct SferaFrustumF {
    SferaPlaneF planes[6];

    int classifyPoints(std::span<const SferaVec3F> points) const;
};

class SferaPolygon3F {
public:
    std::vector<SferaVec3F> vertices;

    void clipToAxis(std::size_t axis, float boundary, bool keepGreater);
    bool clipTriangleToBounds(const SferaVec3F& first, const SferaVec3F& second, const SferaVec3F& third, const SferaVec3F& minimum, const SferaVec3F& maximum);
};

inline SferaPolygon3F g_sfera_clipped_polygon;

struct SferaIntBounds3 {
    std::int64_t min_x;
    std::int64_t max_x;
    std::int64_t min_y;
    std::int64_t max_y;
    std::int64_t min_z;
    std::int64_t max_z;
};

struct SferaViewProjectionScratchRuntime {
    SferaVec3F corners[8];
    SferaIntBounds3 clipping_bounds;

    SferaViewProjectionScratchRuntime translated(const SferaVec3F& offset) const;
};

struct SferaParserRange {
    std::ptrdiff_t begin;
    std::ptrdiff_t end;
};

class SferaSimpleParser {
public:
    ~SferaSimpleParser() { release(); }
    char* source_begin = nullptr;
    char* source_end = nullptr;
    char** line_table = nullptr;
    std::ptrdiff_t line_count = 0u;
    char token[1024];
    std::ptrdiff_t scan_begin;
    std::ptrdiff_t scan_end;
    std::ptrdiff_t block_begin;
    std::ptrdiff_t block_end;

    void initialize();
    void release();
    void rebuildLineTable();
    void load(const char* filename);
    const char* firstToken(const char* line) const;
    const char* lineAt(std::ptrdiff_t index) const;
    std::ptrdiff_t findClosingBrace(std::ptrdiff_t begin, std::ptrdiff_t end) const;
    std::ptrdiff_t parseBlockAt(const char* first_token, std::ptrdiff_t line_index, std::ptrdiff_t end, SferaParserRange* output_range);
    bool findBlock(const char* name, SferaParserRange* output_range, const SferaParserRange* search_range, std::ptrdiff_t occurrence);
    std::ptrdiff_t countBlocks(const char* name, const SferaParserRange* search_range);
    bool findValue(const char* name, const SferaParserRange* search_range);
    void setScanRange(const SferaParserRange* range);
    void clearScanRange();
    bool nextValue(const char* name);
    std::size_t tokenCount() const;
    void setBlockRange(const SferaParserRange* range);
    void clearBlockRange();
    bool nextBlock(const char* name, SferaParserRange* output_range);
    void getBlockRange(SferaParserRange* output_range) const;
    void getScanRange(SferaParserRange* output_range) const;
    const char* tokenAt(std::size_t index) const;
    bool tryReadFloat(std::size_t index, float& output) const;
    bool tryReadInt(std::size_t index, int& output) const;
    bool readFloatSequence(std::size_t index, float* output, std::size_t count) const;
    bool readIntSequence(std::size_t index, int* output, std::size_t count) const;
    float readFloat(std::size_t index) const;
    int readInt(std::size_t index) const;
    char* readString(std::size_t index, char* output) const;
    char* readStringBounded(std::size_t index, char* output, std::size_t capacity) const;
    char* readQuotedString(std::size_t index, char* output) const;
    bool readBool(std::size_t index) const;
    static bool equalsIgnoreCase(const char* left, const char* right);
};

using SferaEffectVec3F = SferaVec3F;

#include "sfera_sound_runtime.h"

struct SferaEffectRenderSlot {
    SferaEffectVec3F position[4];
    std::uint32_t color[4][4];
    float uv[4][2];
    std::int32_t resource_id;
    int self_illumination;
    bool additive;
    bool custom_uv;
};

struct SferaRainParticle {
    SferaEffectVec3F offset;
    float fall_speed;
    std::uint32_t alpha;
    float remaining_life;
    float initial_life;
    float half_width;
};

struct SferaEffectParameter {
    std::uint32_t id;

    const void* value;
};

class SferaEffectTrack;
struct SferaParticleSystemDefinition;

struct SferaEffectMeshResource {
    char name[32]{};
    std::vector<SferaEffectVec3F> vertices;
    std::vector<std::array<float, 2>> uv;
    std::vector<std::array<std::size_t, 4>> face_vertices;
    std::vector<std::array<std::size_t, 4>> face_uv;
    std::vector<SferaColor> colors;
    std::vector<SferaEffectVec3F> transformed_vertices;
    std::vector<std::array<float, 2>> translated_uv;
    std::vector<SferaColor> transformed_colors;
    SferaEffectMeshResource* previous = nullptr;
    SferaEffectMeshResource* next = nullptr;
};

struct SferaEffectMeshDefinition {
    char* name;
    SferaEffectMeshResource* mesh_resource;
    std::uint32_t flags;
    SferaEffectTrack* rotation_track;
    SferaEffectTrack* scale_track;
    SferaEffectTrack* position_track;
    SferaEffectTrack* ucoord_track;
    SferaEffectTrack* vcoord_track;
    SferaEffectTrack* color_track;
    float u_offset;
    float v_offset;
    SferaColor color;
    int self_illumination;
    bool runtime_clone;
    std::uint32_t random_row;
    std::uint32_t random_offset;
    std::uint32_t random_state;
    SferaEffectVec3F runtime_position;
    float transform[16];
    char* texture_name;
    std::int32_t texture_id;
    bool additive;
    bool custom_uv;

    void initializeDefinition();
    bool loadDefinition(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range);
    std::size_t renderSlotCount();
    void initializeClone();
    void resetClone(const SferaEffectMeshDefinition& source);
    void destroyClone();
    void update(const SferaEffectVec3F* spatial_frame, const float* world_frame, float age);
    void commit();
};

struct SferaParticleRenderSlot {
    SferaEffectVec3F spawn_position;
    SferaEffectVec3F position;
    SferaEffectVec3F render_position;
    SferaColor color;
    float remaining_lifetime;
    float total_lifetime;
    float size;
    std::uint32_t random_row;
    std::uint16_t random_seed_0;
    std::uint16_t random_seed_1;
    SferaEffectTrack* size_track;
    SferaEffectTrack* color_track;
    SferaEffectTrack* velocity_track;
    SferaEffectTrack* gravity_track;
    float texture_frame;
    SferaParticleSystemDefinition* linked_particle_system;
    std::int32_t link_index;
};

struct SferaParticleSystemLink {
    char* target_name;
    std::size_t instance_count;
    SferaParticleSystemDefinition* runtime_cursor;
    SferaParticleSystemDefinition* runtime_begin;
    std::int32_t target_index;
};

struct SferaParticleTextureFrame {
    char* texture_name;
    std::int32_t texture_id;
    float uv[8];
};

struct SferaParticleSystemDefinition {
    enum class Shape { Points, Line, Disk, Sphere, Box, Cylinder, Ring, Annulus };
    char* name;
    SferaParticleRenderSlot* render_slots;
    Shape shape;
    float radius;
    float height;
    float width;
    std::int32_t random_seed;
    std::int32_t random_factor;
    SferaEffectVec3F direction;
    SferaEffectVec3F* shape_points;
    std::size_t shape_point_count;
    SferaEffectVec3F emitter_position;
    SferaEffectTrack* emission_track;
    SferaEffectTrack* emission_position_track;
    float emission_count;
    std::uint32_t flags;
    SferaEffectTrack* rotation_track;
    SferaEffectTrack* scale_track;
    SferaEffectTrack* position_track;
    std::size_t render_slot_count;
    std::size_t active_particle_count;
    SferaEffectTrack* lifetime_track;
    float lifetime_random_factor;
    float lifetime;
    float emission_fraction;
    bool emitting;
    SferaEffectTrack* power_track;
    float power;
    SferaEffectTrack* magnet_factor_track;
    SferaEffectTrack* magnet_position_track;
    std::int32_t magnet_child_index;
    SferaEffectVec3F magnet_factor;
    SferaEffectVec3F magnet_position;
    SferaEffectVec3F distortion;
    SferaEffectVec3F current_position;
    SferaEffectVec3F previous_position;
    SferaEffectVec3F previous_origin;
    bool first_update;
    std::uint32_t runtime_random_row;
    std::uint32_t runtime_random_seed_0;
    std::uint32_t runtime_random_seed_1;
    int self_illumination;
    bool additive;
    bool custom_uv;
    SferaEffectVec3F render_basis[4];
    float transform[16];
    std::size_t size_track_count;
    std::size_t color_track_count;
    std::size_t velocity_track_count;
    std::size_t gravity_track_count;
    SferaEffectTrack** size_tracks;
    SferaEffectTrack** color_tracks;
    SferaEffectTrack** velocity_tracks;
    SferaEffectTrack** gravity_tracks;
    SferaParticleTextureFrame* texture_frames;
    std::size_t texture_frame_count;
    float texture_animation_speed;
    SferaParticleSystemLink* links;
    std::size_t link_count;
    bool runtime_active;
    bool runtime_stop_requested;
    bool runtime_clone;

    void initializeDefinition();
    bool loadDefinition(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range);
    void initializeClone();
    void resetClone(const SferaParticleSystemDefinition& source);
    void destroyClone();
    void update(const SferaEffectVec3F* spatial_frame, const float* world_frame, float age);
    void commit();
};

struct SferaSubeffectDefinition {
    enum class Kind { ParticleSystem, Mesh };
    std::ptrdiff_t definition_index;
    Kind kind;
    std::uint8_t attach_mode;
};

class IEffect;

struct SferaActiveEffect {
    std::uint16_t position_source;
    std::uint16_t state_flags;
    std::uint32_t source_handle;
    std::uint32_t age_ticks;
    SferaEffectVec3F position;

    IEffect* effect;
    CSoundEffect* resource;
    bool sound_started;
    std::uint32_t listener_key;
    float viewer_distance;
    SferaActiveEffect* next;
    SferaActiveEffect* previous;
    SferaIntrusiveListHeader* owner_list;
};

class SferaLightDefinition {
public:
    SferaEffectTrack* position_track;
    SferaEffectTrack* color_track;
    SferaEffectTrack* alpha_track;
    std::int32_t light_index;
    SferaEffectVec3F position;
    float color[4];
    bool shared_tracks;
    bool registered;
    bool randomize_color;
    bool vary_brightness;
    std::int32_t random_color[6];
    float brightness;
    float brightness_delta;
    std::uint8_t brightness_frequency;

    std::uint64_t brightness_tick;
    std::uint8_t attach_mode;

    void initializeDefaults();
    bool load(SferaSimpleParser& parser, const SferaParserRange& range);
    void update(const SferaEffectVec3F& base_position, float age, std::uint32_t opacity);
    void release();
};

struct SferaEffectTrackKey {
    float time;
    enum class Mode { Fixed, Random, MirroredRandom };
    Mode mode;
    float scalar_min;
    float scalar_max;
    SferaColor color;
    SferaColor color_random_range;
    float vector_min[3];
    float vector_max[3];
};

class SferaEffectTrack {
public:
    SferaEffectTrackKey* keys;
    std::size_t key_count;
    bool cosine_interpolation;

    void initialize();
    void release();
    void allocateKeys(std::size_t count);
    void setKey(std::size_t index, const SferaEffectTrackKey& key);
    void evaluateVector(float age, SferaEffectVec3F& output) const;
    void evaluateScalar(float age, float& output, const std::uint16_t* random_values = nullptr, std::uint32_t random_offset = 0u) const;
};

SferaEffectTrack* sfera_load_scalar_effect_track(SferaSimpleParser* parser, const SferaParserRange* range);
SferaEffectTrack* sfera_load_vector_effect_track(SferaSimpleParser* parser, const SferaParserRange* range);

struct SferaEffectUpdateContext {
    const SferaEffectVec3F* frame;
    float viewer_distance;
};

struct SferaEffectQueryContext {
    const SferaEffectVec3F* frame;
    float age;
};

struct SferaEffectSpatialFrames {
    SferaEffectVec3F frames[5];
};

struct SferaEffectWorldFrames {
    float frames[5][16];
};

struct SferaEffectInitializeContext {
    const SferaEffectVec3F* spatial_frame;
    std::uint32_t mode;
    float age;
    bool visible;
    const float (*world_frame)[16];
};

class IEffectListener {
public:
    std::uint32_t change_tick;
    virtual bool onEffectAttached(IEffect& effect, SferaActiveEffect& item, float distance) = 0;
    virtual bool onEffectDetached(IEffect& effect, SferaActiveEffect& item) = 0;
    virtual void onEffectChanged(std::uint32_t age_ticks, IEffect& effect, SferaActiveEffect& item) = 0;
};

struct SferaEffectListenerEntry { std::uint32_t effect_id; IEffectListener* listener; };

class BloodEffListener : public IEffectListener {
public:
    BloodEffListener() = default;
    bool onEffectAttached(IEffect& effect, SferaActiveEffect& item, float distance) override;
    bool onEffectDetached(IEffect& effect, SferaActiveEffect& item) override;
    void onEffectChanged(std::uint32_t age_ticks, IEffect& effect, SferaActiveEffect& item) override;
};

struct SferaBloodVertex {
    SferaEffectVec3F position;
    std::uint32_t diffuse_color;
    std::uint32_t specular_color;
    float u;
    float v;
};

struct SferaBloodSpot {
    float life;
    std::size_t vertex_count;
    SferaBloodVertex vertices[90];
};

struct SferaBloodEffectRuntime : BloodEffListener {
    void render();
    SferaBloodSpot spots[30];
    std::size_t active_count;
    float phase;
    int texture_id;
};

class IEffect {
public:
    enum class Kind { Preset, Scripted, Rain = 3 };
    char* script_name;
    std::uint32_t effect_id;
    bool borrows_definition_storage;
    bool deactivated;
    bool resources_released;
    bool activation_blocked;
    std::uint32_t cycle_length;
    std::uint32_t lifetime_ticks;
    float range_min;
    float range_max;
    IEffect* next;
    IEffect* previous;
    Kind effect_kind;
    SferaEffectVec3F position;
    IEffectListener* listener;
    float bounds_min[3];
    float bounds_max[3];
    bool spatial_gate_enabled;
    std::size_t render_slot_budget;

    IEffect() = default;
    void initializeBaseState(Kind kind);
    void assignScriptName(const char* name);
    virtual void initializeEffect(const SferaEffectInitializeContext& context);
    virtual void updateEffect(const SferaEffectUpdateContext& context);
    virtual void queryEffectState(const SferaEffectQueryContext& context);
    virtual bool activateEffect(bool visible);
    virtual void deactivateEffect(bool preserve_resources);
    virtual void renderEffect();
    virtual IEffect* createEffectResources();
    virtual void setParameter(const SferaEffectParameter* parameters, std::size_t count);
    virtual void resetEffect();
    virtual void releaseEffect();
    virtual bool isEffectComplete() const;
    virtual void destroyEffect(bool free_storage);
};

class CScriptedEffect : public IEffect {
public:
    CScriptedEffect* pooled_instances[16];
    std::size_t pooled_count;
    CScriptedEffect* source_definition;
    SferaSubeffectDefinition* subeffects;
    bool sound_started;
    bool update_visible_only;
    bool completes_immediately;
    CSoundEffect* sound_effect;
    std::size_t effect_mesh_definition_count;
    std::size_t light_definition_count;
    std::size_t subeffect_count;
    std::size_t particle_system_definition_count;
    std::size_t linked_particle_system_count;
    std::size_t linked_render_slot_count;
    std::uint32_t phase_ticks_remaining;
    std::uint32_t work_time_min;
    std::uint32_t work_time_max;
    std::uint32_t sleep_time_min;
    std::uint32_t sleep_time_max;
    bool work_phase_active;
    SferaEffectMeshDefinition* effect_mesh_definitions;
    SferaLightDefinition* light_definitions;
    SferaParticleSystemDefinition* particle_system_definitions;
    SferaParticleRenderSlot* linked_render_slots;
    SferaParticleSystemDefinition* linked_particle_systems;

    CScriptedEffect() = default;
    void initializeScriptedState();
    bool loadScript(const char* filename);
    std::ptrdiff_t findEffectMeshDefinitionIndex(const char* name) const;
    std::ptrdiff_t findParticleSystemDefinitionIndex(const char* name) const;
    void buildLinkedParticleSystems();
    void resetRuntimeState();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    void queryEffectState(const SferaEffectQueryContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    IEffect* createEffectResources() override;
    void setParameter(const SferaEffectParameter* parameters, std::size_t count) override;
    void releaseEffect() override;
    bool isEffectComplete() const override;
    void destroyEffect(bool free_storage) override;
};

class CSpiralEffect : public IEffect {
public:
    std::int32_t resource_id;
    CSpiralEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    IEffect* createEffectResources() override;
    void setParameter(const SferaEffectParameter* parameters, std::size_t count) override;
};

class CMolEffect : public IEffect {
public:
    SferaEffectVec3F anchor;
    float texture_phase;
    bool anchor_initialized;
    std::int32_t resource_id;
    CSoundEffect* sound_effect;
    bool sound_started;
    CMolEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    IEffect* createEffectResources() override;
    void setParameter(const SferaEffectParameter* parameters, std::size_t count) override;
    void destroyEffect(bool free_storage) override;
};

class CBladeEffect : public IEffect {
public:
    SferaEffectVec3F anchor;
    float progress;
    bool anchor_initialized;
    std::int32_t resource_id;
    CBladeEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    IEffect* createEffectResources() override;
    void setParameter(const SferaEffectParameter* parameters, std::size_t count) override;
};

struct SferaGazerEffectSlot {
    IEffect* effect;
    float age;
    SferaEffectVec3F offset;
};

class CGazerLakeEffect : public IEffect {
public:
    std::uint32_t field_5c;
    std::size_t slot_count;
    float radius;
    SferaGazerEffectSlot slots[16];
    CGazerLakeEffect() = default;
    void initializePreset(std::uint32_t id, float effect_radius, std::size_t count);
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    IEffect* createEffectResources() override;
    void setParameter(const SferaEffectParameter* parameters, std::size_t count) override;
    void destroyEffect(bool free_storage) override;
};

class CRainEffect : public IEffect {
public:
    std::int32_t resource_id;
    SferaRainParticle* particles;
    float spawn_radius;
    float spawn_radius_bias;
    float spawn_rate;
    float spawn_fraction;
    CRainEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    IEffect* createEffectResources() override;
    void setParameter(const SferaEffectParameter* parameters, std::size_t count) override;
    void destroyEffect(bool free_storage) override;
};

class CLightEffect : public IEffect {
public:
    float color[4];
    float radius;
    bool registered;
    std::int32_t light_index;
    float brightness_jitter;
    std::uint8_t brightness_frequency;

    std::uint64_t brightness_tick;
    CLightEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    IEffect* createEffectResources() override;
    void setParameter(const SferaEffectParameter* parameters, std::size_t count) override;
    void destroyEffect(bool free_storage) override;
};

class IOutputDevice {
public:
    static constexpr std::size_t buffer_capacity = 16u * 1024u;
    char* buffer = nullptr;
    IOutputDevice();
    ~IOutputDevice();
    virtual void write(const char* text) = 0;
};

class COutputLogDevice : public IOutputDevice {
public:
    char* filename = nullptr;
    COutputLogDevice() = default;
    ~COutputLogDevice();
    void setFilename(const char* path);
    void write(const char* text) override;
};

class CSphereError : public IOutputDevice {
public:
    CSphereError() = default;
    void write(const char* text) override;
};

class GrassMapMngr {
public:
    GrassMapMngr() = default;
    virtual void loadGrassMap(std::int32_t column, std::int32_t row, std::span<std::uint8_t> destination);
    std::uint32_t grassType(float x, float z);
    std::uint32_t plantingType(float x, float z);
    GrassMapMngr* reset();
private:
    struct Tile { std::pair<std::int32_t, std::int32_t> key{}; std::uint32_t timestamp = 0; std::array<std::uint8_t, 65536> bytes{}; };
    std::uint8_t sample(float x, float z);
    std::unique_ptr<std::array<Tile, 10>> tiles_;
    std::uint32_t timestamp_ = 0;
};

class CItem {
public:
    char name[150]{};
    bool active = false;
    float position_x = 0.0f;
    float position_y = 0.0f;
    float position_z = 0.0f;
    CItem() = default;
    void setName(const char* text);
    virtual void resetItem();
    virtual void releaseItem();
};

class CCommonItem : public CItem {
public:
    int field_a8 = 0;
    int field_ac = 0;
    int field_b0 = 0;

    std::uint32_t field_b8 = 0;
    std::uint8_t payload[256]{};
    CCommonItem() = default;
};

class CItemListCommonItem : public CItem {
public:
    std::size_t minimum_items = 0;
    std::size_t capacity = 0;
    std::size_t item_count = 0;
    std::uint32_t list_mode = 0;
    std::uint32_t item_parameter = 0;

    std::ptrdiff_t iterator_index = 0;
    std::unordered_map<std::string, std::size_t> item_index;
    std::vector<CCommonItem> item_storage;
    CItemListCommonItem() {}
    std::int32_t initialize(std::int32_t minimum, std::int32_t, std::uint32_t mode, const char* list_name, std::uint32_t parameter);
    CCommonItem* findStoredItem(const CItem* key);
    CCommonItem* firstItem();
    CCommonItem* nextItem();
    std::int32_t addItem(const CCommonItem* item);
    std::int32_t removeItem(const CItem* key);
    void resetItem() override;
};

class CBaseManagerCommonItem : public CItemListCommonItem {
public:
    std::vector<CItemListCommonItem> list_storage;
    std::uint32_t field_d8 = 0;
    CBaseManagerCommonItem() {}
    std::int32_t createList(std::int32_t minimum, std::int32_t reserve, std::uint32_t mode, const char* listName, std::uint32_t parameter);
    std::int32_t deleteList(const char* listName);
    std::int32_t insertListItem(const CItem& listKey, const CCommonItem& value);
    std::int32_t deleteListItem(const CItem& listKey, const CItem& itemKey);
    std::int32_t moveListItem(const CItem& listKey, const CItem& itemKey, float x, float y, float z, bool publish);
    void resetItem() override;
    std::int32_t initialize(std::int32_t minimum, std::int32_t, std::uint32_t mode, const char* list_name, std::uint32_t parameter);
    CItemListCommonItem* findStoredList(const CItem* key);
    CCommonItem* selectItem(CCommonItem* output, const char* list_name, std::int32_t field_ac_filter, std::int32_t field_a8_filter, std::int32_t field_b0_filter);
    std::int32_t addList(const CItemListCommonItem* list);
    std::int32_t removeList(const CItem* key);
    virtual std::int32_t handleInsert(CItemListCommonItem* list, CCommonItem* item, CCommonItem* related_item);
    virtual std::int32_t handleRemove(CItemListCommonItem* list, CCommonItem* item, CCommonItem* related_item);
    virtual CItem* findItem(CItem* key);
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

struct SferaCursorPosition { std::int32_t x; std::int32_t y; };
class SferaInterfaceCursor {
public:
    struct ImageLayer {
        std::int32_t x = 0;
        std::int32_t y = 0;
        int texture = -1;
        int width = 0u;
        int height = 0u;
    };
    struct TextLayer {
        std::int32_t x = 0;
        std::int32_t y = 0;
        std::string text;
        int font = 0u;
        std::uint32_t color = 0u;
    };
    bool system_visible = true;
    bool centered_hotspot = false;
    std::uint8_t kind = 255u;
    SferaInterfaceCursor() = default;
    bool loadTextures();
    void setImage(std::size_t layer, const char* texture, std::int32_t x, std::int32_t y);
    void setImageSize(std::size_t layer, int width, int height);
    void setText(std::size_t layer, const char* text, std::int32_t x, std::int32_t y, int font, std::uint32_t color);
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
    virtual void destroy(bool free_storage) = 0;
    virtual void copyStateFrom(const CCursor* previous) = 0;
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual void apply() = 0;
    virtual void updatePosition() = 0;
    virtual SferaCursorPosition* getPosition(SferaCursorPosition* output) const = 0;
    virtual void setPosition(std::int32_t x, std::int32_t y) = 0;
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
    HCURSOR cursor_handle = nullptr;
    bool clip_enabled = false;
    bool saved_system_visible = 0u;
    std::uint32_t kind = 255u;
    std::int32_t saved_x = 0;
    std::int32_t saved_y = 0;
    CHardwareCursor();
    ~CHardwareCursor();
    void destroy(bool free_storage) override;
    void copyStateFrom(const CCursor* previous) override;
    void activate() override;
    void deactivate() override;
    void apply() override;
    void updatePosition() override;
    SferaCursorPosition* getPosition(SferaCursorPosition* output) const override;
    void setPosition(std::int32_t x, std::int32_t y) override;
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
    std::int32_t x = 0;
    std::int32_t y = 0;
    bool active = 0u;
    bool saved_system_visible = 0u;
    std::uint32_t saved_kind = 255u;
    std::int32_t saved_x = 0;
    std::int32_t saved_y = 0;
    CSoftwareCursor();
    void destroy(bool free_storage) override;
    void copyStateFrom(const CCursor* previous) override;
    void activate() override;
    void deactivate() override;
    void apply() override;
    void updatePosition() override;
    SferaCursorPosition* getPosition(SferaCursorPosition* output) const override;
    void setPosition(std::int32_t x, std::int32_t y) override;
    void show() override;
    bool isInsideViewport() const override;
    bool isSystemCursorVisible() const override;
    void setSystemCursorVisible(bool visible) override;
    std::uint32_t cursorKind() const override;
    void setCursorKind(std::uint32_t kind) override;
};

// Include <d3d9.h> in semantic_classes.h. Replace the old unmanaged resource classes with this block.
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

class UnmanagedResourceVB final : public UnmanagedResourceBase {
public:
    IDirect3DVertexBuffer9* native_buffer = nullptr;
    std::size_t length;
    DWORD usage;
    DWORD fvf;
    D3DPOOL pool;
    UnmanagedResourceVB(CD3D9Device& device, std::size_t length, DWORD usage, DWORD fvf, D3DPOOL pool);
    ~UnmanagedResourceVB() override;
    void restoreResource() override;
    void releaseResource() override;
};

class UnmanagedResourceIB final : public UnmanagedResourceBase {
public:
    IDirect3DIndexBuffer9* native_buffer = nullptr;
    std::size_t length;
    DWORD usage;
    D3DFORMAT format;
    D3DPOOL pool;
    UnmanagedResourceIB(CD3D9Device& device, std::size_t length, DWORD usage, D3DFORMAT format, D3DPOOL pool);
    ~UnmanagedResourceIB() override;
    void restoreResource() override;
    void releaseResource() override;
};

class UnmanagedResourceTexture final : public UnmanagedResourceBase {
public:
    IDirect3DTexture9* native_texture = nullptr;
    std::uint32_t width;
    std::uint32_t height;
    std::uint32_t levels;
    std::uint32_t usage;
    D3DFORMAT format;
    D3DPOOL pool;
    bool restore_marker = false;
    UnmanagedResourceTexture(CD3D9Device& device, std::uint32_t width, std::uint32_t height, std::uint32_t levels, std::uint32_t usage, D3DFORMAT format, D3DPOOL pool);
    ~UnmanagedResourceTexture() override;
    void restoreResource() override;
    void releaseResource() override;
};

class DynamicVertexStream {
public:
    std::unique_ptr<UnmanagedResourceVB> buffer;
    std::size_t capacity = 0u;
    std::size_t position = 0u;
    DynamicVertexStream(CD3D9Device& device, std::size_t stride, DWORD fvf);
    template<class Vertex> Vertex* lock(std::size_t count);
private:
    CD3D9Device& device;
    std::size_t stride;
    DWORD fvf;
};

class DynamicIndexStream {
public:
    std::unique_ptr<UnmanagedResourceIB> buffer;
    std::size_t capacity = 0u;
    std::size_t position = 0u;
    explicit DynamicIndexStream(CD3D9Device& device);
    std::uint16_t* lock(std::size_t count);
private:
    CD3D9Device& device;
};

class CD3D9Device {
public:
    enum DrawFlag : std::uint32_t { disable_clipping = 1u, two_sided = 4u, lighting = 16u };
    IDirect3D9* api = nullptr;
    IDirect3DDevice9* native_device = nullptr;
    D3DPRESENT_PARAMETERS presentation{};
    D3DCAPS9 capabilities{};
    HRESULT last_hresult = S_OK;
    D3DMATRIX world_transform{};
    IDirect3DQuery9* sync_query = nullptr;
    bool supports_post_effects = false;
    std::vector<SphereUI::DisplayMode> display_modes;
    std::unique_ptr<CShaderMgr> shaders;
    std::unique_ptr<CPostEffectsMgr> post_effects;
    std::unique_ptr<UnmanagedResourceTexture> reflection_target;
    std::unique_ptr<UnmanagedResourceTexture> minimap_target;
    DynamicVertexStream vertices32;
    DynamicVertexStream vertices28;
    DynamicIndexStream indices_primary;
    DynamicIndexStream indices_secondary;
    D3DTEXTUREFILTERTYPE min_filter = D3DTEXF_ANISOTROPIC;
    D3DTEXTUREFILTERTYPE mag_filter = D3DTEXF_LINEAR;
    D3DTEXTUREFILTERTYPE mip_filter = D3DTEXF_LINEAR;
    CD3D9Device();
    ~CD3D9Device();
    CD3D9Device(const CD3D9Device&) = delete;
    CD3D9Device& operator=(const CD3D9Device&) = delete;
    HRESULT checkResult(HRESULT result, const char* operation);
    void initialize(HWND window, std::uint32_t width, std::uint32_t height, std::uint32_t depth_bits, bool windowed);
    void enumerateDisplayModes(bool windowed);
    bool supportsDisplayMode(std::uint32_t width, std::uint32_t height, std::uint32_t depth_bits) const;
    void selectBackBufferFormat(const D3DDISPLAYMODE& display, bool windowed, D3DFORMAT& format);
    void selectDepthFormat(D3DFORMAT adapter_format, D3DFORMAT& format);
    void initializeRenderState();
    void applyFiltering();
    void setTransform(D3DTRANSFORMSTATETYPE kind, const D3DMATRIX& matrix);
    void setAlphaBlending(D3DBLEND source, D3DBLEND destination);
    void setColorOperation(std::uint32_t stage, D3DTEXTUREOP operation, std::uint32_t first, std::uint32_t second);
    void setAlphaOperation(std::uint32_t stage, D3DTEXTUREOP operation, std::uint32_t first, std::uint32_t second);
    void setWhiteMaterial(float alpha);
    void drawBuffer(IDirect3DVertexBuffer9* vertices, D3DPRIMITIVETYPE topology, std::uint32_t flags, std::ptrdiff_t base_vertex, std::size_t vertex_count, IDirect3DIndexBuffer9* indices, std::size_t index_count, std::size_t start_index, std::size_t stride);
    void drawVertices(D3DPRIMITIVETYPE topology, std::uint32_t flags, const void* vertices, std::size_t vertex_count, const std::uint16_t* indices, std::size_t index_count, std::size_t stride);
    bool beginScene();
    void releaseResources();
    void restoreResources();
    void waitForGpu();
    UnmanagedResourceTexture& minimapTexture();
private:
    friend class UnmanagedResourceBase;
    std::vector<UnmanagedResourceBase*> unmanaged_resources;
};

class StdAllocator {
public:
    StdAllocator() = default;
    virtual void* allocate(std::size_t size, std::uint32_t flags);
    virtual void* reallocate(void* memory, std::size_t size, std::uint32_t flags);
    virtual void deallocate(void* memory);
};

// Begin recovered files cluster.
class SferaFileManager {
public:
    SferaFileManager() = default;
    ~SferaFileManager();
    SferaFileManager(const SferaFileManager&) = delete;
    SferaFileManager& operator=(const SferaFileManager&) = delete;
    void setErrorReporting(bool enabled);
    int open(const char* filename, int flags);
    int create(const char* filename);
    int transformEnvelope(const char* destination, const char* source, bool compress);
    std::ptrdiff_t read(int descriptor, void* destination, std::size_t size);
    std::ptrdiff_t write(int descriptor, const void* source, std::size_t size);
    std::int64_t seek(int descriptor, std::int64_t offset, int origin);
    int close(int descriptor);
    std::int64_t fileSize(const char* filename);
    std::vector<std::uint8_t> readAll(const char* filename);
    void keepTail(const char* filename, std::size_t size);
    void addSearchPath(const char* directory);
    std::vector<std::string> candidatePaths(const char* filename, bool search_nested_paths = false) const;
private:
    static constexpr std::size_t maximum_open_files = 100u;
    static constexpr std::size_t maximum_search_paths = 100u;
    void reportError(const char* description, const char* filename) const;
    bool error_reporting_enabled = false;
    std::vector<std::string> search_paths;
    std::unordered_map<int, std::string> open_files;
    int registerDescriptor(int descriptor, const std::string& filename);
    const std::string* filenameFor(int descriptor, const char* invalid_handle_message) const;
};

inline SferaFileManager g_sfera_files;

// End recovered files cluster.

// Begin recovered quickfile cluster.
struct QuickFileEntry {
    std::vector<std::uint8_t> bytes;
    std::uint16_t module_id;
};

class QuickFile {
public:
    static constexpr std::size_t file_capacity = 400;
    QuickFile* initialize(const char* directory);
    void release();
    int load(const char* filename, std::size_t size);
    const QuickFileEntry* find(std::string_view filename) const;
private:
    static constexpr std::size_t maximum_filename_length = 32;
    std::vector<QuickFileEntry> files;
    std::unordered_map<std::string, std::size_t> index;
    static std::string filenameKey(std::string_view filename);
};

// End recovered quickfile cluster.

// Begin recovered filemap cluster.
class SferaFileMap {
public:
    const std::byte* mapped_view;
    std::size_t file_size;
    char filename[32];

    explicit SferaFileMap(const char* path) noexcept;
    SferaFileMap(const SferaFileMap&) = delete;
    SferaFileMap& operator=(const SferaFileMap&) = delete;
    ~SferaFileMap() noexcept;
    bool open(const char* path) noexcept;
    void close() noexcept;
    bool isOpen() const noexcept;
    std::size_t size() const noexcept;
    const std::byte* data() const noexcept;

private:
    void reportError(const char* format) const noexcept;
};

// End recovered filemap cluster.

namespace SphereUI {
    struct CursorGeometry {
        std::int32_t x;
        std::int32_t y;
        std::int32_t width;
        std::int32_t height;
        bool centered;
    };
}

class CCursorManager {
public:
    static CCursorManager& instance();
    static bool hasActiveCursor() noexcept;
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
        static FontGlyph decode(const std::uint8_t* bytes) {
            FontGlyph glyph;
            glyph.width = SferaBinary::readLittleEndian<std::uint16_t>(bytes);
            glyph.height = SferaBinary::readLittleEndian<std::uint16_t>(bytes + 2);
            glyph.bearing_x = SferaBinary::readLittleEndian<std::int16_t>(bytes + 4);
            glyph.bearing_y = SferaBinary::readLittleEndian<std::int16_t>(bytes + 6);
            glyph.advance = SferaBinary::readLittleEndian<std::int16_t>(bytes + 8);
            glyph.u0 = std::bit_cast<float>(SferaBinary::readLittleEndian<std::uint32_t>(bytes + 12));
            glyph.v0 = std::bit_cast<float>(SferaBinary::readLittleEndian<std::uint32_t>(bytes + 16));
            glyph.u1 = std::bit_cast<float>(SferaBinary::readLittleEndian<std::uint32_t>(bytes + 20));
            glyph.v1 = std::bit_cast<float>(SferaBinary::readLittleEndian<std::uint32_t>(bytes + 24));
            return glyph;
        }
    };

    class FontFace {
    public:
        int texture = -1;
        std::array<FontGlyph, 256> glyphs{};
        std::string name;
        std::int32_t line_height = 0;
        std::int32_t baseline = 0;
        bool load(const char* display_name, const char* filename, const char* texture_name);
    };

    class InterfaceRenderer {
    public:
        static TextExtent measureText(const char* text, int font, bool initialized);
        static std::uint32_t tracking(int font) noexcept;
        static void drawText(const char* text, std::int32_t x, std::int32_t y, std::uint32_t color, int font, bool initialized, const UiRect& clip, bool opaque);
        static void reportError(const char* message);
        static void drawTexture(IDirect3DBaseTexture9* texture, float left, float top, float right, float bottom, std::uint32_t color, float u = 1.0f, float v = 1.0f, bool textured = true);
        static void setSpriteRenderMode(std::uint32_t mode);
        static UiViewport viewport();
        static void setViewport(const UiViewport& viewport);

    private:
        static void drawFaceText(const char* text, std::int32_t x, std::int32_t y, std::uint32_t color, int font, const UiRect& clip);
    };

    class InterfaceConfiguration {
    public:
        static const char* value(const char* key);
        static void open(const char* filename);
        static int readInteger(const char* key, int fallback);
        static void writeInteger(const char* key, int value);
        static void save();
    };

    class FontFactory {
    public:
        FontFactory();
        ~FontFactory();
        FontFactory(const FontFactory&) = delete;
        FontFactory& operator=(const FontFactory&) = delete;
        void initialize();
        void clear();
        bool load(const char* filename, const char* texture_name);
        void loadNamedFont(const char* name);
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

inline SphereUI::FontFactory g_sfera_fonts;

namespace SphereUI {
    enum class HyperTextCommand { text, lineBreak, color, linkStart, linkEnd, preserveSpaces, horizontalSpace, tab, image, tooltipStart, tooltipEnd, unknown };
    enum class HyperTextImageAlignment { top, bottom, middle };

    struct HyperTextRegion {
        std::string target;
        std::vector<UiRect> rectangles;
        bool visible = false;
        bool hovered = false;
        bool contains(std::int32_t x, std::int32_t y) const;
        void addRectangle(const UiRect& rectangle, const UiRect& clip);
    };

    struct HyperDocumentNode {
        HyperTextCommand command = HyperTextCommand::text;
        std::string text;
        std::uint32_t color = D3DCOLOR_ARGB(255, 255, 255, 255);
        std::size_t region_index = 0;
        std::int32_t spacing = 0;
        std::int32_t width = 0;
        HyperTextImageAlignment image_alignment = HyperTextImageAlignment::top;
        std::int32_t image_width = 0;
        std::int32_t image_height = 0;
        std::int32_t image_x = 0;
        std::int32_t image_y = 0;
        std::shared_ptr<UiSprite> sprite;
    };

    struct HyperDocumentLine {
        std::vector<HyperDocumentNode> nodes;
        std::int32_t height = 0;
        std::int32_t baseline = 0;
        std::uint32_t initial_color = D3DCOLOR_ARGB(255, 255, 255, 255);
    };

    class HyperTextDocument {
    public:
        std::string name;
        std::vector<HyperTextRegion> links;
        std::vector<HyperTextRegion> tooltips;
        std::int32_t line_height = 0;
        int font = 0;
        std::uint32_t link_color = D3DCOLOR_ARGB(255, 80, 160, 160);
        std::uint32_t hover_color = D3DCOLOR_ARGB(255, 255, 255, 0);
        HyperTextDocument() = default;
        HyperTextDocument(std::string_view text, std::int32_t width, std::uint32_t format, int font);
        void setName(const char* value);
        bool load(const char* filename);
        void load(const SferaSimpleParser& parser, const SferaParserRange& range);
        void parse(std::string_view input);
        HyperTextDocument* clone(std::int32_t width, std::uint32_t format, int font) const;
        void layout(std::int32_t width, std::uint32_t format, int font);
        void draw(std::int32_t left, std::int32_t top, std::int32_t clip_offset, std::int32_t clip_height, std::uint32_t alpha);
        std::int32_t totalHeight() const;
        void resetRegions();
    private:
        std::vector<HyperDocumentNode> nodes;
        std::vector<HyperDocumentLine> lines;
        UiRect linkRectangle(std::int32_t left, std::int32_t right, std::int32_t y, std::int32_t baseline) const;
    };

    class HyperTextParser {
    public:
        static UiString* plainText(UiString& output, const UiString& input);
        static UiString* buildLink(UiString& output, UiString& scheme, UiString& target, UiString& caption);
        static bool extractPlayerPrefix(UiString& input, UiString* output, UiString* plain);
        static bool removePlayerPrefix(UiString& input, UiString* output, UiString* plain);
        static bool eraseRange(UiString& input, std::size_t first, std::size_t last, UiString* output, UiString* plain);
        static HyperTextCommand command(std::string_view name);
        static bool parseCommand(std::string_view tag, HyperDocumentNode& node, std::string& argument);
        static void parseImage(std::string_view argument, HyperDocumentNode& node);
        static void parseElements(const UiString& text, UiDeque<HyperTextElement*>& elements, UiString& plain);
        static void releaseElements(UiDeque<HyperTextElement*>& elements);
    };
}

namespace SphereUI {
// Types in namespace SphereUI, before InterfaceManager.
struct SavedWindowPosition {
    std::string name;
    std::int32_t x = 0;
    std::int32_t y = 0;
};

struct LocalizedTextEntry {
    std::string key;
    std::string value;
};

class InterfaceManager {
public:
    std::vector<Window*> window_templates;
    std::vector<std::unique_ptr<HyperTextDocument>> hypertext_documents;
    std::deque<UiSprite> sprites;
    std::vector<LocalizedTextEntry> localized_strings;
    std::list<SavedWindowPosition> saved_positions;
    std::string resolved_ui_path;
    const char* localizedPath(const char* filename);
    UiSprite* sharedSprite(const char* name);
    UiSprite* acquireSprite(const char* name);
    void loadSprites(const char* filename);
    void clearSprites();
    bool loadWindowTemplates(const char* filename);
    Window* templateWindow(const char* name) const;
    void clearWindowTemplates();
    void loadHyperTexts();
    HyperTextDocument* findHyperText(const char* name) const;
    void clearHyperTexts();
    bool loadLocalizedStrings();
    std::string_view localizedValue(const char* key) const;
    const char* localizedText(const char* key) const;
    void clearLocalizedStrings();
    SavedWindowPosition* savedPosition(const char* name, bool create);
    bool findSavedPosition(const char* name, SferaCursorPosition& position);
    void saveWindowPosition(Window& window);
    std::size_t savedPositionsSize() const;
    void writeSavedPositions(std::span<std::byte> destination) const;
    void readSavedPositions(std::span<const std::byte> source);
    enum OpenFlag : std::uint32_t { explicitPosition = 1u, preserveVisibility = 2u, skipOpeningAnimation = 4u, centerOnScreen = 8u };
    bool initialized = false;
    bool drag_drop_active = false;
    bool capture_control_binding = false;
    bool tooltip_disabled = false;
    std::list<Window*> windows;
    std::deque<WindowEvent> events;
    std::unordered_set<Window*> registered_windows;
    std::unordered_map<const Window*, WindowEventHandler> event_handlers;
    std::unique_ptr<SferaInterfaceCursor> cursor;
    Window* help_window = nullptr;
    Window* load_screen = nullptr;
    ToolTipCtrl* tooltip = nullptr;
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
    Window* findWindow(const char* name, bool exact = false) const;
    Window* windowUnderCursor() const;
    bool hasEscapeWindow() const;
    void addTopLevelWindow(Window& window);
    void raiseWindow(Window& window);
    void lowerWindow(Window& window);
    void collectCoveredWindows(Window& window);
    Window* openWindow(const char* name, std::int32_t x = 0, std::int32_t y = 0, std::uint32_t flags = 0u);
    void closeWindow(Window* window, bool animated = true);
    void showHelpPage(const char* name);
    void setTooltipText(const char* text);
    void setCursorKind(std::uint32_t kind, std::int32_t x, std::int32_t y);
    void setCursorImage(const char* texture, std::int32_t x, std::int32_t y);
    void update(std::uint8_t key = 0u, std::uint8_t character = 0u, std::uint32_t mouse_buttons = 0u, std::int32_t wheel_delta = 0);
    void draw();
    std::uint32_t sendMessage(Window* window, SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second);
    void showLoadingScreen(bool visible, std::int32_t width, std::int32_t height, bool english);
    void setLoadingProgress(std::int32_t percent);
    void registerWindow(Window& window);
    void unregisterWindow(Window& window);
    bool isRegistered(const Window* window) const;
    void bindEventHandler(Window* window, WindowEventHandler handler);
    void copyEventHandler(Window* destination, const Window* source);
    bool hasEventHandler(const Window* window) const;
    void dispatchEvent(Window* window, const WindowEvent& event);
    void unbindEventHandler(const void* window);

};
}
inline SphereUI::InterfaceManager g_sfera_interface;

namespace SphereUI {
    struct ImageDescriptionParameters {
        char texture_name[64];
        int width;
        int height;
        UiRect rectangle;
        std::uint32_t flags;
    };

    struct ImageDescription {
        char name[64];
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
        std::variant<std::int32_t, float, std::string, std::vector<std::uint8_t>, std::vector<std::int32_t>, std::vector<float>, std::vector<std::string>, std::vector<ConfigDocument>> data;
    };
    static ConfigDocument parse(std::string_view source);
    static ConfigDocument open(const char* path);
    static void setStorageMode(StorageMode mode);
    const Value* find(std::string_view name) const;
    std::optional<std::int32_t> integer(std::string_view name) const;
    std::optional<float> real(std::string_view name) const;
    const char* text(std::string_view name) const;
    std::optional<std::size_t> arraySize(std::string_view name) const;
    std::optional<std::int32_t> integerAt(std::string_view name, std::size_t index) const;
    std::optional<float> realAt(std::string_view name, std::size_t index) const;
    const char* textAt(std::string_view name, std::size_t index) const;
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
    void load(const char* path);
    void parse(std::string_view source);
    void clear();
    bool contains(std::string_view model, std::string_view parameter) const;
    bool hasModel(std::string_view model) const;
    std::optional<float> floatValue(std::string_view model, std::string_view parameter) const;
    std::optional<std::int32_t> intValue(std::string_view model, std::string_view parameter) const;
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
    std::vector<std::int32_t> textures;
    std::array<float, 4> color{};
    std::array<float, 3> colorVariation{};
    bool hasColorVariation = false;
    static std::uint32_t randomColor(const std::array<float, 3>& variation);
};

class MaterialLibrary {
public:
    void load(const char* binary_path, const char* configuration_path = "Models\\Materials.cfg");
    void clear();
    const Material* find(std::string_view name) const;
    const Material* at(std::size_t index) const;
    const Material* defaultMaterial() const;
    std::size_t size() const;
private:
    std::vector<Material> materials_;
    std::optional<std::size_t> default_index_;
};

}
inline SphereRender::MaterialLibrary g_sfera_materials;

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
    char name[32]{};
    bool has_geometry = true;
    std::size_t child_count = 0u;
    std::size_t first_child = 0u;
    union { BoneBounds bounds{}; BoneAnimation animation; };
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

enum class VegetationKind : std::int32_t { None = -1, Grass = 0, SynchronizedGrass = 1, InteractiveGrass = 2, Tree = 3 };

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
    char name[32]{};
    std::size_t vertex_count = 0u;
    ModelVertex* vertices = nullptr;
    std::size_t face_count = 0u;
    ModelFace* faces = nullptr;
    std::size_t submesh_count = 0u;
    Submesh* submeshes = nullptr;
    std::size_t bone_count = 0u;
    Bone* bones = nullptr;
    std::size_t root_bone = 0;
    std::vector<const Material*> materials;
    std::size_t* child_bones = nullptr;
    std::size_t animation_count = 0u;
    std::size_t frame_count = 0u;
    ModelKeyframe* keyframes = nullptr;
    AnimationFrame* animation_frames = nullptr;
    std::size_t* animation_lengths = nullptr;
    bool has_vertex_colors = false;
    std::uint32_t* vertex_colors = nullptr;
    FaceColorIndices* face_colors = nullptr;
    CollisionKind collision_kind = CollisionKind::AxisAlignedBounds;
    SferaVec3F minimum{};
    SferaVec3F maximum{};
    SferaBoundsCornersRuntime oriented_corners{};
    SferaBoundsCornersRuntime collision_corners{};
    SferaMatrix4x4F bounds_transform{};
    SferaVec3F oriented_size{};
    float radius = 0.0f;
    float minimum_size = 0.0f;
    std::size_t collision_group_count = 0u;
    ModelCollisionGroup* collision_groups = nullptr;
    ModelCollisionTriangle* collision_triangles = nullptr;
    float lod_distance = 1000.0f;
    float lod_power = -1.0f;
    float shadow_fade = 0.5f;
    float shadow_scale = 2.0f;
    float shadow_spread = 0.85f;
    bool casts_static_shadow = false;
    float trace_distance = -1.0f;
    VegetationKind vegetation_kind = VegetationKind::None;
    union { GrassInfluence* grass_influences = nullptr; TreeInfluence* tree_influences; };
    GrassBendingBasis* grass_bending = nullptr;
    VegetationVertex* cached_vegetation_vertices = nullptr;
    std::array<float, 3> color_variation{};
    std::uint32_t landscape_shadow_alpha = 0u;

    Model() = default;
    ~Model();
    Model(const Model&) = delete;
    Model& operator=(const Model&) = delete;
    static std::unique_ptr<Model> load(const char* model_name, const char* directory, const ModelParameters& parameters, const MaterialLibrary& materials);
    static std::unique_ptr<Model> decode(std::string_view model_name, std::span<const std::uint8_t> bytes, const ModelParameters& parameters, const MaterialLibrary& materials);
    void prepareGrass(bool synchronized, float ground_y);
    void prepareTree(float dead_radius, float phase_multiplier);
    void prepareVegetation(const ModelParameters& parameters);
    void initializeGrassGeometry(std::size_t vertices_needed, std::size_t faces_needed, float height);
    void finishGrassGeometry(std::span<const Submesh> groups);

private:
    void recoverBounds();
    void assignMaterials();
    std::unique_ptr<ModelVertex[]> vertex_storage_;
    std::unique_ptr<ModelFace[]> face_storage_;
    std::unique_ptr<Submesh[]> submesh_storage_;
    std::unique_ptr<Bone[]> bone_storage_;
    std::unique_ptr<std::size_t[]> child_bone_storage_;
    std::unique_ptr<ModelKeyframe[]> keyframe_storage_;
    std::unique_ptr<AnimationFrame[]> animation_frame_storage_;
    std::unique_ptr<std::size_t[]> animation_length_storage_;
    std::unique_ptr<std::uint32_t[]> vertex_color_storage_;
    std::unique_ptr<FaceColorIndices[]> face_color_storage_;
    std::unique_ptr<ModelCollisionGroup[]> collision_group_storage_;
    std::unique_ptr<ModelCollisionTriangle[]> collision_triangle_storage_;
    std::unique_ptr<GrassInfluence[]> grass_storage_;
    std::unique_ptr<TreeInfluence[]> tree_storage_;
    std::unique_ptr<GrassBendingBasis[]> bending_storage_;
};

}

namespace SphereRender {
    struct SceneSortEntry;
    class TextureRepository {
    public:
        struct Entry {
            std::string name;
            std::filesystem::path filename;
            std::unique_ptr<IDirect3DBaseTexture9, void(*)(IDirect3DBaseTexture9*)> texture{nullptr, [](IDirect3DBaseTexture9* value) { value->Release(); }};
            bool has_alpha = false;
        };
        void initialize();
        void addFolder(const char* directory);
        void finishRegistration();
        void clear();
        int find(const char* name) const;
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
            std::unique_ptr<Model> model;
            std::chrono::steady_clock::time_point last_used;
        };
        void initialize();
        void addFolder(const char* directory);
        void finishRegistration();
        int find(const char* name) const;
        Model* model(int index);
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

inline SphereRender::TextureRepository g_sfera_textures;
inline SphereRender::ModelRepository g_sfera_models;

class CD3D9Device;

class CShaderMgr {
public:
    struct WaterParameters { float gradient = 0.0f; float specular = 0.0f; float reflection = 0.0f; };
    struct Variant {
        std::string filename;
        IDirect3DPixelShader9* pixel_shader = nullptr;
        int alpha_register = -1;
        int down_filter_register = -1;
        int water_gradient_register = -1;
        int water_specular_register = -1;
        int water_reflection_register = -1;
        Variant() = default;
        ~Variant();
        Variant(const Variant&) = delete;
        Variant& operator=(const Variant&) = delete;
    };
    std::map<std::pair<bool, std::array<std::uint8_t, 8>>, Variant> variants;
    std::string vertex_directory;
    std::string pixel_directory;
    std::array<float, 512> wave_samples;
    std::array<SferaVec4F, 16> downsample_offsets;
    CShaderMgr(CD3D9Device& device, const char* vertex_directory, const char* pixel_directory);
    CShaderMgr(const CShaderMgr&) = delete;
    CShaderMgr& operator=(const CShaderMgr&) = delete;
    static std::pair<bool, std::array<std::uint8_t, 8>> instanceCode(std::string_view filename, bool pixel);
    static std::array<float, 512> makeWaveSamples();
    static std::array<SferaVec4F, 16> makeDownsampleOffsets(float width, float height);
    static WaterParameters waterParameters(float environment, float height);
    void loadFolder(const char* directory, bool pixel);
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
    void compose();
private:
    struct ScreenVertex { float x; float y; float z; float rhw; float u; float v; float u2; float v2; };
    CD3D9Device& device;
    IDirect3DSurface9* captured_backbuffer = nullptr;
    IDirect3DTexture9* scene_texture = nullptr;
    IDirect3DTexture9* blur_texture = nullptr;
    IDirect3DTexture9* temporary_texture = nullptr;
    IDirect3DVertexDeclaration9* vertex_declaration = nullptr;
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
    float fog_distance;
    float saved_fog_distance;
    bool lods_enabled;
    bool hardware_cursor_enabled;
    float environment_factor;
    uint32_t base_microtexture_id;
    float view_parameter;
    float view_scale;
    bool post_effects_enabled;
    uint32_t rebuild_percent;
    uint32_t runtime_counter;
    float base_render_factor;
    int display_width;
    int display_height;
    std::unique_ptr<CD3D9Device> d3d_runtime;
    std::array<WaterMaterial, 10> water_materials{};
    void initialize();
    void initializeWater();
};
struct SferaLogPath { char text[52]; };

struct SferaStringLookupRuntime {
    uint8_t case_fold[256];
    bool initialized;
    std::array<char32_t, 256> unicode_cp1251{};
    std::array<std::uint8_t, 256> lowercase_cp1251{};
    void initialize();
    const char* findInsensitive(const char* text, const char* needle);
    static const char* fileName(const char* path);
    static void encodeUri(char* destination, const char* source, std::size_t capacity);
    static bool matchesWildcard(const char* text, const char* pattern);
    static std::uint32_t copyString(char* destination, const char* source, std::int32_t capacity);
};

struct SferaLogFileRuntime {
    SferaLogPath path;
    uint32_t size_limit;
    void write(const char* text);
    void write(std::int32_t number);
};
struct SferaLogRuntime {
    void initialize();
    SferaLogFileRuntime files[1];
    void writeFormatted(const char* format, std::va_list arguments);
};

struct SferaLandscapeMapRecord;
struct SferaViewProjectionScratchRuntime;




struct SferaConfigTextRuntime {
    enum class Operation : std::int32_t { Write = 13, Read = 14, Load = 15, Save = 16, Clear = 17, UseText = 30, ReadCommands = 54, SaveCompressed = 55, CopyText = 56, Length = 57, SetFilename = 62 };
    bool load(const char* filename);
    bool save(bool compressed = false) const;
    bool writeValue(std::string_view key, std::string_view value, bool quoted);
    static std::string encodeBinary(std::span<const std::uint8_t> input);
    static constexpr std::size_t text_capacity = 2458176u;
    char text_storage[text_capacity];
    char* text_buffer;
    std::size_t text_length;
    char parser_path[1024];
    std::size_t copyText(const char* source, std::size_t length, char* path);
    void useText(char* source, char* path);
    void clear(char* path, const char* filename);
    char* find(const char* key) const;
    bool readInteger(const char* key, std::int32_t& value) const;
    bool readFloat(const char* key, float& value) const;
    bool readString(const char* key, char* destination, std::size_t capacity) const;
    bool readBinary(const char* key, std::uint8_t* destination, std::size_t capacity) const;
    std::size_t copyTo(char* destination, std::size_t capacity) const;
    static bool writeFile(const char* path, const void* data, std::size_t size);
};

struct SferaErrorLogRuntime {
    IOutputDevice* outputs[2]{};
    CSphereError* owned_error = nullptr;
    COutputLogDevice* owned_log = nullptr;
    bool enabled = false;
    char user_name[128]{};
    void initialize(IOutputDevice* error = nullptr, IOutputDevice* log = nullptr);
    void clear();
};



struct SferaCrtStartupRuntime {
    bool initialized = false;
    static void initialize();
    static void releaseContainers();
    static const char* commandLineArguments(const char* commandLine);
};

class WorldMemory {
public:
    static void* allocate(std::size_t size, bool zeroed = true);
    static void* reallocate(void* memory, std::size_t size);
    static void release(void* memory);
    static std::size_t payloadSize(void* memory);
};
class WorldDiagnostics {
public:
    static constexpr std::uint32_t codeBaseMismatch = 1u << 7u;
    static void appendScriptContext(const char* text);
    static void flushScriptContext();
    static std::uint32_t inspectInstruction(std::uint16_t& module, std::uint32_t& offset, std::uint8_t* bytes, std::uint32_t& count);
    static void describeScript(bool includeTime);
    static void appendCallStack(char* output);
    static const char* scriptContext();
    static void report(const char* message);
    static void warning(const char* message);
    [[noreturn]] static void fail(const char* message);
};
class WorldClock {
public:
    static void initialize();
    static std::uint64_t microseconds();
    static std::uint64_t nowTicks();
    static std::uint32_t calendarTicks();
};
template<class T> struct SferaBoundCheckArray {
    T* data;
    std::size_t capacity;

    T* element(std::size_t index) const noexcept { return data && index < capacity ? &data[index] : nullptr; }
    void reserve(std::size_t count) {
        if (count <= capacity) return;
        if (count > std::size_t{std::numeric_limits<std::ptrdiff_t>::max()} / sizeof(T)) throw std::bad_alloc();
        auto* replacement = static_cast<T*>(WorldMemory::allocate(count * sizeof(T)));
        if (capacity) std::memcpy(replacement, data, capacity * sizeof(T));
        std::fill_n(replacement + capacity, count - capacity, T{});
        WorldMemory::release(data);
        data = replacement;
        capacity = count;
    }
    void initialize(std::size_t count) { reserve(count); }
    void clear() {
        WorldMemory::release(data);
        data = nullptr;
        capacity = 0u;
    }
    std::size_t firstVacant() const {
        if (!data) WorldDiagnostics::fail("Handle table is not initialized");
        const auto* empty = std::find(data, data + capacity, T{});
        if (empty == data + capacity) WorldDiagnostics::fail("Handle table is full");
        return static_cast<std::size_t>(empty - data);
    }
};
struct WorldObject {
    bool owns_model;

    union { int model_id; SphereRender::Model* generated_model; };
    SferaVec3F position;
    SferaVec3F rotation;
    uint32_t spatial_membership;
    int32_t grid_min_x;
    int32_t grid_max_x;
    int32_t grid_min_y;
    int32_t grid_max_y;
    float render_fade;
    uint32_t render_group;
    SferaMatrix4x4F world_transform;
    SferaVec3F bounds_minimum;
    SferaVec3F bounds_maximum;
    SferaVec3F bounds_corners[8];
    uint32_t visibility_mark;
    uint32_t linked_objects[5];
    SferaActiveEffect* attached_effects[10];
    uint32_t lighting_color;
    bool extended_pose_available;
    bool visible;
};
struct ExtendedWorldObject : WorldObject {
    static constexpr std::size_t unregistered = std::numeric_limits<std::size_t>::max();
    std::size_t extended_object_index = unregistered;
    uint8_t motion_state;
    bool render_enabled;
    bool steep_slope;
    int32_t render_cache_handle;
    float scale;
    SferaVec3F orientation_basis[3];
    int32_t animation;
    int32_t frame;
    float interpolation;
    int32_t frame_secondary;
    int32_t animation_secondary;
    uint32_t parent_object_handle;
    uint32_t parent_link_slot;
    SferaMbcProcessRecord* process_handle;
    SferaVec3F effect_frame_position_a;
    SferaVec3F effect_frame_position_b;
    float effect_frame_transform_a[16];
    float effect_frame_transform_b[16];
    SferaVec3F effect_frame_position_c;
    float effect_frame_transform_c[16];
    bool simulation_enabled;
    bool full_rate_simulation;
    bool gravity_enabled;

    bool airborne;
    SferaVec3F commanded_velocity;
    SferaVec3F physical_velocity;
    float angular_velocity;

    bool movement_blocked;
    bool avoidance_enabled;

    SferaVec3F avoidance_direction;
    float avoidance_depth;
    SferaVec3F previous_spatial_position;
    SferaVec3F previous_spatial_rotation;
    SferaVec3F previous_basis_rotation;
    SferaVec3F previous_bounds_position;
    SferaVec3F previous_bounds_rotation;
    std::uint32_t last_simulation_tick;
};

class WorldObjects {
public:
    uint32_t max_occupied_object_handle;
    uint32_t controlled_object_handle;
    uint32_t contour_mode;
    SferaBoundCheckArray<WorldObject*> object_handles;
    SferaBoundCheckArray<std::uint32_t> extended_object_handles;
    std::size_t extended_object_count;

    WorldObject* effectObject(std::uint32_t handle) const;
    SferaEffectVec3F referencePosition() const;
    SferaEffectVec3F objectPosition(std::uint32_t handle) const;
    bool attachEffect(std::uint32_t handle, SferaActiveEffect& item);
    void detachEffect(std::uint32_t handle, SferaActiveEffect& item);
    SferaActiveEffect* firstEffect(std::uint32_t handle) const;
    bool buildEffectFrames(std::uint32_t handle, SferaEffectSpatialFrames& spatial_frames, SferaEffectWorldFrames& world_frames) const;
    WorldObject* object(std::uint32_t handle, const char* operation = nullptr) const;
    ExtendedWorldObject* extendedObject(std::uint32_t handle) const;
    SphereRender::Model* model(const WorldObject& object) const;
    std::uint32_t create(const char* name, SferaMbcProcessRecord* process, std::uint32_t kind, bool dynamic);
    void destroy(std::uint32_t handle);
    void destroyAll();
    void removeSpatialIndex(std::uint32_t handle);
    void updateSpatialIndex(std::uint32_t handle);
    void updateExtendedSpatialIndices();
    void rotate(std::uint32_t handle, const SferaVec3F& delta);
    void approachHeading(std::uint32_t handle, float target);
    void moveLocal(std::uint32_t handle, const SferaVec3F& displacement);
    void alignReferenceOrientation();
    void reflectReferenceOrientation();
    void recalculateBasis(std::uint32_t handle);
    void appendCommand(std::uint32_t handle, const char* command);
    bool actorActive(std::uint32_t handle) const;
    void activateTrap(const WorldObject& obstacle);
    void addExtended(std::uint32_t handle);
    void removeExtended(std::uint32_t handle);
    void unlink(std::uint32_t parent, std::uint32_t slot);
    ExtendedWorldObject* linkModel(std::uint32_t parent, const char* name, std::uint32_t slot);
};

// Runtime terrain storage is independent of the encoded landscape headers.
struct TerrainVertex { SferaVec3F position; SferaVec3F normal; float textureU; float textureV; float detailU; float detailV; };
struct TerrainTriangle { std::uint16_t indices[3]; std::uint16_t material; std::uint32_t attributes[2]; SferaVec3F normal; };
struct TerrainCell { std::int32_t x; std::int32_t z; std::size_t triangleCount; TerrainTriangle* triangles; std::uint16_t baseMicrotexture;  std::size_t layerCount; std::uint16_t layers[10]; std::uint8_t* masks; };
struct TerrainSurfaceGroup { std::size_t vertexCount; std::size_t firstVertex; std::size_t firstIndex; std::size_t colored_vertex_offset; std::uint32_t light_mask; bool distant;  };
struct TerrainWater { float height; std::size_t material; };
struct TerrainBounds { SferaVec3F corners[8]; std::int32_t scaledBounds[6]; void lowerMinimum(float height); };
class TerrainPatch {
public:
    std::size_t vertexCount = 0; TerrainVertex* vertices = nullptr; TerrainCell cells[144]{}; TerrainSurfaceGroup* surfaceGroups = nullptr; TerrainSurfaceGroup* renderGroups = nullptr; TerrainVertex* groupedVertices = nullptr; std::uint16_t* groupedIndices = nullptr; TerrainWater* waters = nullptr; TerrainBounds bounds{}; TerrainBounds quarterBounds[4]{}; TerrainBounds groupBounds[16]{}; TerrainBounds cellBounds[144]{}; std::uint32_t flags = 0; std::array<std::vector<std::size_t>, 4> cornerIndices; bool cornerSmoothed[4]{}; std::array<std::vector<std::vector<std::size_t>>, 4> edgeGroups;
    ~TerrainPatch() { releaseResources(); }
    void releaseResources();
    void partitionEdges();
    void rebuildSurfaceGroups();
    void rebuildSurfaceGroup(const TerrainCell& cell);
    void updateBounds();
    bool validateEdge(const TerrainPatch& other, std::size_t side, std::size_t otherSide, int row, int column) const;
    bool smoothEdge(TerrainPatch& other, std::size_t side, std::size_t otherSide, int row, int column);
    void smoothCorner(TerrainPatch* diagonal, TerrainPatch* vertical, TerrainPatch* horizontal, std::size_t corner, std::size_t diagonalCorner, std::size_t verticalCorner, std::size_t horizontalCorner);
    void readGeometry(int descriptor, const std::vector<std::uint8_t>& masks, const std::vector<std::uint8_t>& waterData, const std::uint16_t* microtextureRemap, std::uint16_t baseMicrotexture);
};
struct TerrainTextureImage {
    static constexpr std::size_t width = 256;
    static constexpr std::size_t height = 256;
    std::array<std::uint8_t, 32> metadata;
    std::array<std::uint16_t, width * height> pixels;
};
class TerrainRegion {
public:
    char name[30]; char directory[102]; std::int32_t rows; std::int32_t columns; TerrainPatch* patches[100]; int textureIds[100]; TerrainTextureImage* textures[100]; std::uint32_t expiry[100];
    TerrainPatch* patch(int row, int column) const;
    void loadPatch(int row, int column);
    void touchPatch(int row, int column);
    void destroyPatch(int row, int column);
    void smoothPatch(int row, int column);
};
struct SferaLandscapeMapRecord;
class TerrainAssets {
public:
    static TerrainRegion* regions();
    static void loadMap();
    static void loadCatalog(const char* directory);
    static void evictUnused();
    static void releaseAll();
};

// Terrain contour records retain the contours.bin field order.
struct Contour {
    std::int32_t type = 0;
    std::int32_t vertex_count = 0;
    float min_x = 1000000.0f;
    float max_x = -1000000.0f;
    float min_z = 1000000.0f;
    float max_z = -1000000.0f;
    std::array<float, 64> x{};
    std::array<float, 64> z{};
    std::array<std::int32_t, 64> neighbour_contour{};
    std::array<std::int32_t, 64> neighbour_edge{};
    void updateBounds();
    bool contains(float point_x, float point_z) const;
};

class Contours {
public:
    std::vector<Contour> records;
    explicit Contours(std::int32_t first_server_type = 2000, std::int32_t last_server_type = 2999);
    void clear();
    void load();
    void loadBytes(std::span<const std::uint8_t> bytes);
    void typeRange(std::int32_t first, std::int32_t last, std::int32_t& start, std::int32_t& count) const;
    bool sameEdge(std::int32_t first_contour, std::int32_t first_edge, std::int32_t second_contour, std::int32_t second_edge) const;
    void setServerMap(const std::int32_t* types, const std::int32_t* servers, std::int32_t count);
    std::int32_t serverByType(std::int32_t type) const;
    void buildServerMask(std::int32_t server);
    std::int32_t typeAt(float x, float z, std::int32_t first_type, std::int32_t last_type) const;
    std::int32_t serverAt(float x, float z) const;
    bool nearServer(float x, float z, std::int32_t server);
    void connectEdges();
    std::vector<std::array<float, 4>> serverBoundaries();
    void rebuildServerWall();
    void rasterizeServers();
private:
    std::int32_t first_server_type;
    std::int32_t last_server_type;
    std::vector<std::pair<std::int32_t, std::int32_t>> server_map;
    std::array<std::uint8_t, 160 * 160> server_grid{};
    std::array<std::uint8_t, 160 * 160> server_mask{};
    bool grid_initialized = false;
    std::int32_t mask_server = -1;
    bool isServerContour(const Contour& contour) const;
    void invalidateGrid();
};

struct SferaServerWallEffectRecord {
    SferaEffectVec3F positions[4]{};
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
    void setSegments(const float* coordinates, std::size_t count);
    void prepareGeometry();
    void generateEffects();
    void generateEffects(const WorldObject& observer, float field_of_view, const SferaFrustumF& frustum);
    void updateEffectRendering();
    static bool intersectPlane(const SferaPlaneF& plane, const SferaVec3F& start, const SferaVec3F& end, SferaVec3F& output);
    static std::uint32_t classifyVisibility(const SferaFrustumF& frustum, const SferaVec3F* points, std::int32_t count);
    static std::int32_t intersectXZ(const SferaVec3F& first, const SferaVec3F& second, const SferaVec3F& other_first, const SferaVec3F& other_second, SferaVec3F& output);
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
    static SpatialLeaf* leafAt(std::int32_t cell_x, std::int32_t cell_z);
    static void insert(std::uint32_t handle, std::int32_t cell_x, std::int32_t cell_z);
    static void remove(std::uint32_t handle, std::int32_t cell_x, std::int32_t cell_z);
    static bool typesInteract(std::uint32_t combined_type);
    void gatherCell(std::int32_t cell_x, std::int32_t cell_z, bool include_terrain);
    void gatherObject(std::uint32_t handle);
    void gatherObjects(const SferaVec3F& center, float radius);
    void gatherTerrain(const SferaVec3F& center, float radius);
    std::uint32_t gatherShadowTriangles(const Bounds& bounds, const SferaVec3F& center, float radius, const SferaVec3F& origin, const SferaVec3F& direction);
    const std::vector<std::uint32_t>& objects() const { return objects_; }
    const std::vector<TerrainCandidate>& terrain() const { return terrain_; }
    const std::vector<SferaVec3F>& shadowVertices() const { return shadow_vertices_; }
private:
    std::vector<std::uint32_t> objects_;
    std::vector<TerrainCandidate> terrain_;
    std::vector<SferaVec3F> shadow_vertices_;
    void clearCandidates();
    void finishCandidates();
    void addTerrain(TerrainRegion& region, int row, int column, int cell, float origin_x, float origin_z);
};
class ContactQuery {
public:
    static bool projectionsOverlap(const SferaBoundsCornersRuntime& first, const SferaBoundsCornersRuntime& second, const SferaVec3F& axis);
    static bool boxesOverlap(const SferaBoundsCornersRuntime& first, const SferaBoundsCornersRuntime& second);
    static int intersectTriangle(const SferaVec3F& start, const SferaVec3F& end, const SphereRender::ModelCollisionTriangle& triangle, SferaVec3F& intersection);
    static void sortTriangles(std::span<SphereRender::ModelCollisionTriangle> triangles);
    static void updateBounds(std::uint32_t handle);
    static bool lineOfSight(std::uint32_t handle);
    void appendBoxNormals(const SferaBoundsCornersRuntime& corners);
    void gather(std::uint32_t handle);
    std::uint32_t test(std::uint32_t handle, std::uint32_t mode, bool reuse_cache);
    std::uint32_t testMovement(std::uint32_t handle, bool reuse_cache);
    void setIgnoredObjects(std::span<const std::uint32_t> handles);
    std::span<const NearContact> nearContacts() const { return contacts_; }
private:
    std::vector<NearContact> contacts_;
    static void publishNormal(const SferaVec3F& normal);
    static void publishDirection(const SphereRender::ModelCollisionTriangle& triangle);
    static bool trianglesHitBox(const SphereRender::Model& model, const SferaMatrix4x4F& transform, const Bounds& query_bounds, const Bounds& local_bounds, const SferaMatrix4x4F* box_transform, const SferaMatrix4x4F* box_basis);
};
}
inline SphereWorld::WorldSpatialIndex g_sfera_world_spatial;
inline SphereWorld::ContactQuery g_sfera_contacts;

namespace SphereWorld {

struct GrassCell {
    std::uint32_t object_handle = 0;
    std::size_t source_count = 0;
    std::array<SphereRender::Model*, 36> source_models{};
};

struct GrassInstance {
    SphereRender::Model* model = nullptr;
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
    void addGrass(std::uint32_t id, const std::array<const char*, 10>& variants);
    const GrassPattern& grass(std::uint32_t id) const;
private:
    std::vector<GrassPattern> grass_patterns_;
};

class DynamicVegetation {
public:
    DynamicVegetation(GrassCell* cells, std::uint32_t side);
    ~DynamicVegetation();
    void initializeNoise();
    void initializeWind();
    void setReference(const SferaVec3F& position);
    void setDepthMode(std::uint32_t mode);
    void addInfluence(float x, float z, float radius, std::uint32_t id);
    void updateWind(const SferaVec3F& reference, float elapsed);
    void deformGrass(SphereRender::Model& model, const SferaVec3F& position);
    void deformInteractiveGrass(SphereRender::Model& model);
    void deformTree(SphereRender::Model& model);
    void collectModels(std::span<const SphereRender::SceneSortEntry> records);
    void acquire();
    void update();
    void wait();
    std::uint32_t recalculate();
    std::span<const SphereRender::VegetationVertex> output() const { return output_; }
    const std::array<float, 1024>& noise() const { return noise_; }
private:
    struct Influence { std::uint32_t id = UINT32_MAX; float x = 0; float z = 0; float radius_squared = 0; float minimum_x = 0; float minimum_z = 0; float maximum_x = 0; float maximum_z = 0; float flattening = 0.5f; std::int64_t timestamp = 0; };
    struct Gust { bool active = false; float x = 0; float z = 0; float radius = 0; float radius_squared = 0; float speed = 0; };
    SferaVec3F bendingPosition(const SphereRender::Model& model, std::size_t vertex, float first, float second) const;
    void saveCache(SphereRender::Model& model);
    GrassCell* cells_ = nullptr;
    std::uint32_t side_ = 0;
    std::uint32_t depth_mode_ = 0;
    HANDLE worker_ = nullptr;
    std::array<CRITICAL_SECTION, 4> locks_{};
    std::array<Influence, 5> influences_{};
    std::array<Influence, 5> active_influences_{};
    std::array<Gust, 6> gusts_{};
    std::array<float, 1024> noise_{};
    std::vector<SphereRender::VegetationVertex> output_;
    std::vector<SphereRender::Model*> models_;
    SferaVec3F reference_{};
    SferaVec3F wind_{};
    float wind_strength_ = 0;
    float phase_ = 0;
    float phase_speed_ = 0;
    float bend_x_ = 0;
    float bend_z_ = 0;
    bool alternating_lock_ = false;
    static std::int64_t last_update_;
};

class Vegetation {
public:
    void initialize();
    void updateGrassView();
    void createCell(std::int32_t x, std::int32_t z, GrassCell& cell);
    void updateCells();
    void destroyOwnedModel(std::uint32_t& handle);
    static bool alternatePatterns();
    VegetationPatterns patterns;
private:
    std::array<GrassInstance, 36> placements_{};
};

}

inline SphereWorld::Vegetation g_sfera_vegetation;

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
struct TerrainWaterSurface { std::int32_t x; std::int32_t z; float height; std::uint32_t lightMask; std::size_t material; SferaBoundsCornersRuntime bounds; };
class TerrainRenderer {
public:
    std::vector<TerrainVisibleCell> visibleCells;
    std::vector<TerrainWaterSurface> waterSurfaces;
    static bool visibleBounds(const TerrainBounds& source, const SferaVec3F& anchor, SferaViewProjectionScratchRuntime& translated);
    bool gatherCells(TerrainPatch& patch);
    void findReflectiveWater(TerrainPatch& patch);
    void gatherReflectiveWater();
    void prepareAndDraw(TerrainPatch& patch);
    void drawCells(TerrainPatch& patch, int first, int last);
    void drawLandscape();
    void sortWater(int first, int last);
    void drawWater();
private:
    void visitPatches(bool draw);
};
inline TerrainRenderer g_sfera_terrain_renderer;
class TerrainTextureCache {
public:
    static void initialize();
    static void bindLayer(const TerrainCell& cell, int layer);
    static void release();
    static void loadMicrotextures(const char* pattern);
    static void blendLayer(const TerrainCell& cell, int layer, TerrainTextureImage& texture);
};

namespace SphereWorld {
class Motion {
public:
    void initializeResponseCurve();
    double responseValue(std::int32_t index) const noexcept;
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
inline SphereWorld::Motion g_sfera_motion;

struct WorldGuiControl { std::uint32_t kind; std::uint32_t windowHandle; std::uint32_t windowSlot; std::int32_t left; std::int32_t top; std::int32_t right; std::int32_t bottom; std::uint32_t objectHandle; std::uint32_t alignment; float opacity; std::uint32_t color; };
struct WorldGuiText : WorldGuiControl { std::size_t lineCount; std::int32_t lineX[300]; std::int32_t lineY[300]; char* lines[300]; };
class WorldGuiControls {
public:
    static std::uint32_t createText(std::int32_t x, std::int32_t y, const char* text, std::uint32_t window);
    static std::uint32_t createSprite(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, const char* texture, std::uint32_t window, std::uint32_t alpha);
    static void setAppearance(std::uint32_t handle, std::uint32_t alpha, std::optional<std::uint32_t> color = std::nullopt);
    static void destroyAllText();
    static WorldGuiControl* control(std::uint32_t handle);
    static void detachFromWindow(std::uint32_t window, std::uint32_t slot);
    static void destroySprite(std::uint32_t handle);
    static void destroyText(std::uint32_t handle);
    static void removeForObject(std::uint32_t handle);
};
namespace SphereRender {
class ModelPose {
public:
    static void updateBone(const SferaMatrix4x4F& parent, std::size_t bone_index);
    static std::int32_t animationLength(std::uint32_t handle, std::int32_t animation);
    static std::int32_t* animation(std::uint32_t handle);
    static std::int32_t* frame(std::uint32_t handle);
    static float* interpolation(std::uint32_t handle);
    static std::int32_t* secondaryFrame(std::uint32_t handle);
    static std::int32_t* secondaryAnimation(std::uint32_t handle);
    static SferaVec3F* neckPosition(SferaVec3F& output);
private:
    static ModelKeyframe keyframe(const Model& model, const BoneAnimation& animation, std::size_t frame);
    static ExtendedWorldObject* queryObject(std::uint32_t handle, const char* operation);
    static std::size_t frameOffset(const Model& model, std::int32_t animation, std::int32_t frame, bool secondary);
};
}

namespace SphereRender {
struct CharacterPose { SferaVec4F rotation; SferaVec3F translation; };
struct CharacterSkeleton {
    enum class Region { Whole, UpperBody, LowerBody };
    std::vector<std::optional<std::size_t>> parents;
    std::vector<std::array<char, 30>> names;
    std::vector<CharacterPose> poses;
    std::vector<std::size_t> animation_lengths;
    std::array<std::size_t, 7> attachments{};
    std::vector<SferaMatrix4x4F> initial_pose;
    void calculate(std::size_t frame, std::size_t bone, const SferaMatrix4x4F& parent, SferaMatrix4x4F* output) const;
    void calculateSplit(std::size_t firstFrame, std::size_t secondFrame, std::size_t bone, const SferaMatrix4x4F& parent, Region region, SferaMatrix4x4F* output) const;
    std::size_t absoluteFrame(std::int32_t animation, std::int32_t frame) const;
};
struct CharacterVertex { SferaVec3F position; SferaVec3F normal; float u; float v; std::size_t first_bone; std::size_t second_bone; float weight; };
struct CharacterSkinnedVertex { SferaVec3F position; SferaVec3F normal; float u; float v; };
struct CharacterGeometry { std::vector<CharacterVertex> vertices; std::vector<std::uint16_t> indices; };
struct CharacterAsset { char name[32]{}; std::size_t directory = 0; std::unique_ptr<CharacterGeometry> geometry; };
struct CharacterPart { CharacterAsset* asset = nullptr; int textures[20]{}; };
struct CharacterAppearance { std::int32_t sex; std::uint8_t parts[16]; };
struct CharacterSlot { ExtendedWorldObject* owner; CharacterAppearance appearance; };
class CharacterModels {
public:
    float maximum_distance;
    float minimum_distance;
    SferaMatrix4x4F root_transform;
    SferaVec3F bounds[8];
    CharacterSkeleton skeletons[2];
    char directories[100][200];
    std::vector<CharacterAsset> assets;
    std::vector<CharacterPart> parts;
    std::array<std::array<std::array<const CharacterPart*, 256>, 26>, 2> part_indices{};
    CharacterSlot instances[400];
    std::int32_t small_helm[21];
    std::uint64_t last_lod_update;
    std::size_t rendered_count;
    float lod_start;
    float lod_end;

    CharacterModels* load(const char* const* folders, std::size_t count);
    void clear();
    void initializeBounds();
    std::int32_t classify(const SferaMatrix4x4F& world) const;
    void setDistances(float minimum, float range);
    void updateLodDistance();
    double visibility(const WorldObject& object) const;
    void setAppearance(std::int32_t handle, const CharacterAppearance& appearance);
    bool getAppearance(std::int32_t handle, CharacterAppearance& appearance) const;
    std::int32_t partAnimationLength(const ExtendedWorldObject& object, std::int32_t animation) const;
    std::int32_t usesSmallHelm(std::int32_t sex, std::int32_t code) const;
    void loadSkeleton(const char* path, CharacterSkeleton& skeleton);
    void preload(CharacterAsset& asset, const CharacterSkeleton& skeleton);
    void animate(const CharacterSkeleton& skeleton, std::int32_t animation, std::int32_t frame, std::int32_t secondaryAnimation, std::int32_t secondaryFrame, float interpolation, SferaMatrix4x4F* output, bool attachmentsOnly) const;
    SferaVec3F neckPosition(const ExtendedWorldObject& object) const;
    void drawPart(std::int32_t sex, std::int32_t kind, std::uint8_t model, std::int32_t visibility, const CharacterSkeleton& skeleton, const SferaMatrix4x4F* pose, bool cull, std::int32_t transparent, std::int32_t textureCode, std::uint32_t passes);
    void drawLowDetail(std::uint32_t handle);
    void draw(std::uint32_t handle, std::uint32_t color);
    static HRESULT setMaterial(float opacity, float detail, const SferaVec3F& color);
    static std::int32_t textureVariants(bool female, char part);
    static std::uint32_t* parameter(SferaBoundCheckArray<std::uint32_t>& array, std::int32_t index);
    static ExtendedWorldObject* checkedExtended(WorldObject* object);
private:
    const CharacterAppearance& appearance(const ExtendedWorldObject& object) const;
    void updateEffectFrames(ExtendedWorldObject& object, const CharacterSkeleton& skeleton, std::span<SferaMatrix4x4F> pose, const SferaMatrix4x4F& world) const;
};
}

namespace SphereRender {
struct CameraRectangle { std::int32_t left = 0, top = 0, right = 0, bottom = 0; bool operator==(const CameraRectangle&) const = default; };
class GameCamera {
public:
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
    static void rebuildVisibleVolume(std::int32_t left, std::int32_t top, std::int32_t right, std::int32_t bottom);
    static void beginFrame(std::uint32_t mode, bool reflection, float water_height);
    static void endFrame(std::uint32_t mode, bool reflection);
private:
    CameraRectangle rectangle_{};
    std::array<SferaVec3F, 6> points_{};
    SferaFrustumF planes_{};
    bool points_current_ = false, planes_current_ = false;
    SferaVec3F saved_camera_position_{}, saved_camera_rotation_{}, saved_controlled_position_{};
    void buildPoints();
    void buildPlanes();
    static SferaPlaneF boundaryPlane(const SferaVec3F& first, const SferaVec3F& second, const SferaVec3F& third);
};
}
inline SphereRender::GameCamera g_sfera_camera;

struct SferaViewSpatialRuntime;
namespace SphereRender {
struct SceneSortEntry { std::uint32_t object; std::size_t key; float distance; };
class SceneRenderer {
public:
    static void waitForGpu();
    static bool bindTexture(std::int32_t texture);
    static void textureSize(std::int32_t texture, std::uint32_t* dimensions);
    static void setAmbientColor();
    static void setMaterialColor(std::int32_t red, std::int32_t green, std::int32_t blue);
    static void setObjectMaterial(WorldObject& object, std::uint32_t shade, const std::array<float, 3>& variation);
    static std::uint32_t terrainShade(std::uint32_t shade, float x, float z);
    static void buildColorRemap(double exponent, double floor);
    static void modelFade(float distance, float power, float& fade, float& remaining);
    static std::uint32_t materialVariant(std::uint32_t first, std::uint32_t second, std::uint32_t third);
    static bool hasMaterialVariant(std::uint32_t object, std::int32_t variant);
    static void setMaterialVariant(std::uint32_t object, std::int32_t variant);
    static std::uint32_t setOpacity(std::uint32_t opacity);
    static void adaptFog();
    static void raiseDistantObject(std::uint32_t object);
    static void sortObjects(std::int32_t first, std::int32_t last);
    static void sortLights(std::int32_t first, std::int32_t last);
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
    static void setupEnvironment(std::uint32_t mode, bool useDefault, float time, SferaViewSpatialRuntime& output);
};
}

struct SceneSkyLayer { char texture[20]; float projectionWarp; float uvScale; std::size_t trackOffset; float minimumTime; float maximumTime; SferaVec3F colors[11]; };
struct SceneSkyLayers { SceneSkyLayer primary; SceneSkyLayer secondary; float opacity; };
class SceneSky {
public:
    static void rotateUv(float x, float y, float angle, float& u, float& v);
    static std::size_t buildLayerGeometry(const SceneSkyLayer& layer, float opacity);
    static void layerColor(const SceneSkyLayer& layer, SferaVec3F& output);
    static void drawColorLayer(const char* texture, const SferaVec3F& color, std::size_t indices);
    static void drawMaskLayer(const char* texture, std::size_t indices);
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
    ~ShadowMap();
    void createTextures();
    void setDirection(const SferaVec3F& value, float opacity);
    void selectObjectLight(const WorldObject& object);
    float projectionExtension(const WorldObject& object) const;
    bool prepareModel(WorldObject& object, const SferaVec3F* position, float opacity, std::uint8_t detail);
    bool prepareGeometry(WorldObject& object, const SferaVec3F* position, float opacity, std::uint8_t detail, float scale, float spot_scale);
    void projectModel(const SphereRender::Model& model, std::size_t submesh, const SferaMatrix4x4F* world = nullptr);
    template<class Vertex> void projectVertices(const Vertex* vertices, std::size_t vertex_count, const std::uint16_t* indices, std::size_t index_count);
    void draw(const SferaVec3F* vertices, std::size_t triangle_count);
    void save();
    void restore();
    static void initialize(std::uint32_t default_quality);
    static void shutdown();
    static void prepareObject(std::uint32_t handle, ExtendedWorldObject& object, float width, float spot_scale, float& extension);
    static void drawObject(ExtendedWorldObject& object, float width, float extension);
private:
    std::array<IDirect3DTexture9*, 3> textures{};
    std::int32_t spot_texture = -1;
    std::uint32_t raster_color = 0u;
    std::uint32_t spot_color = UINT32_MAX;
    ShadowRasterizer rasterizer;
    std::vector<ShadowPoint> projected_points;
    std::array<std::uint16_t, 1002> face_indices{};
    std::array<SferaBloodVertex, 501> spot_vertices{};
    D3DSURFACE_DESC surface{};
    D3DLOCKED_RECT locked{};
    SferaVec3F saved_direction{};
    float saved_fade = 0.0f;
    SferaMatrix4x4F saved_basis{};
};
inline std::unique_ptr<ShadowMap> g_sfera_shadows;

struct SkyState {
    SferaVec4F primaryColors[10];
    float primaryPositions[10];
    SferaVec4F reference;
    SferaVec4F secondaryColors[6];
    float secondaryPositions[6];
    float time;
    float sunPhase;
    SferaVec3F sunColor;

    SferaVec3F ambientColor;

};
class SkyEnvironment {
public:
    SkyState states[11];
    std::int32_t sunsetState;
    std::int32_t sunriseState;
    SkyEnvironment* load(const char* filename);
    void interval(float time, std::int32_t& first, std::int32_t& second, float& fraction) const;
    void sample(float time, SkyState& output) const;
    void sunDirection(float time, SferaVec3F& output) const;
    void lighting(float time, SferaVec3F& sun, SferaVec3F& ambient) const;
};


struct EnvironmentLighting { SferaVec3F fogParameters; SferaVec3F fogColor; SferaVec3F ambientColor; SferaVec3F sunColor; };
struct EnvironmentZone {
    float originX, originZ, minimumX, maximumX, minimumZ, maximumZ, borderFade;
    SferaVec3F fogParameters;
    SferaVec3F fogColors[8];
    SferaVec3F ambientColors[8];
    SferaVec3F sunColors[8];
    float weight(float x, float z) const;
    void sample(std::int32_t first, std::int32_t second, float fraction, EnvironmentLighting& output) const;
};
class EnvironmentZones {
public:
    static void interval(float time, std::int32_t& first, std::int32_t& second, float& fraction);
    void load(const char* filename);
    void setDefaultLighting(const SferaVec3F& sun, const SferaVec3F& ambient);
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

struct WeatherSkyPair { char primary[20]; char secondary[20]; };
struct WeatherKeyframe { std::int32_t time; std::array<float, 4> properties; };
struct WeatherScenario { std::int32_t duration; WeatherSkyPair sky; float skyStart; float skyEnd; std::size_t keyframeCount; std::array<WeatherKeyframe, 10> keyframes; };
class WeatherScenarios {
public:
    enum class Property { rain, lightning, wind, cloud };
    std::array<SceneSkyLayer, 30> textures;
    std::size_t textureCount;
    std::array<WeatherSkyPair, 30> pairs;
    std::size_t pairCount;
    std::array<WeatherScenario, 100> scenarios;
    std::size_t scenarioCount;
    std::array<std::uint16_t, 200> sequence;
    std::size_t sequenceCount;
    std::int32_t totalDuration;
    std::int32_t lastUpdate;
    WeatherScenarios* load(const char* filename);
    void update(std::int32_t time, float dayTime, WeatherState& output, bool alternateClouds);
    void locate(std::int32_t time, std::size_t& sequenceIndex, std::int32_t& startTime, std::int32_t& localTime) const;
    std::int32_t advance(std::size_t& sequenceIndex, std::size_t& keyframe) const;
    std::int32_t retreat(std::size_t& sequenceIndex, std::size_t& keyframe) const;
    double nextValue(std::size_t sequenceIndex, std::int32_t time, Property property, std::int32_t& distance) const;
    double previousValue(std::size_t sequenceIndex, std::int32_t time, Property property, std::int32_t& distance) const;
    void selectSky(std::int32_t time, float dayTime, char* primary, char* secondary) const;
    void copyTexture(const char* name, SceneSkyLayer& output) const;
    static void windDirection(bool refresh, std::int32_t seed, float& x, float& z);
private:
    const WeatherScenario& at(std::size_t sequenceIndex) const;
};

struct SferaWeatherRuntime {
    float direction_cos_component = 0.0f;
    float direction_sin_component = 0.0f;
    WeatherScenarios* standard = nullptr;
    WeatherScenarios* highres = nullptr;
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
    std::int32_t left, right, top, bottom;
    std::int32_t contentLeft, contentRight, contentTop, contentBottom;
    std::int32_t width, height;
    float scrollX, scrollY;
    std::uint32_t layer;
    std::size_t controlCount;
    std::uint32_t controls[7000];
    std::uint32_t order;
    std::uint32_t textColor = 0u;
    std::uint32_t textStyle = 0u;
    int font = 0u;
    std::uint32_t fontScale = 1u;
    std::uint32_t eventControls[10]{};
    std::uint32_t eventMessages[10]{};
    std::size_t eventCount = 0u;
    std::uint32_t attach(std::uint32_t control);
    void detach(std::uint32_t slot);
    void recalculateSize();
    void enqueueInput(std::uint32_t control, std::uint32_t message);
    bool takeInput(std::uint32_t& control, std::uint32_t& message);
    SferaCursorPosition contentPosition(SferaCursorPosition point) const;
    void scrollBy(float dx, float dy, SferaCursorPosition& cursor);
};
struct GameUiHit { std::uint32_t window = 0u; std::uint32_t control = UINT32_MAX; bool border = false; };
struct GameUiElement : WorldGuiText {
    static constexpr std::uint32_t textKind = 0u, spriteKind = 1u;
    ~GameUiElement();
    void layoutText(const char* text, const GameUiWindow& window, std::int32_t x, std::int32_t y);
    std::uint32_t fontScale;
    int font;
    std::int32_t spriteLeft, spriteTop, spriteWidth, spriteHeight;
    char texture[40];
    std::uint32_t alpha;
};

class GameInterface {
public:
    inline static constexpr const char* nativeWindowClassName = "SphereWclName";
    static void registerNativeWindowClass();
    static void createNativeWindow();
    static GameUiWindow* window(std::uint32_t handle, const char* operation = nullptr);
    static std::uint32_t createWindow(std::int32_t left, std::int32_t top, std::int32_t right, std::int32_t bottom, std::uint32_t layer, std::uint32_t opacity);
    static void destroyWindow(std::uint32_t handle);
    static GameUiHit hitTest(SferaCursorPosition point);
    static void updateInput();
    static std::uint32_t fontHeight(int font, std::uint32_t scale);
    static std::uint32_t glyphWidth(std::uint32_t character, int font);
    static std::uint32_t textHeight(int font, std::uint32_t scale, std::uint32_t lines);
    static std::uint32_t lineOffset(int font, std::uint32_t scale, std::uint32_t line);
    static void drawAtlasText(const char* text, std::int32_t x, std::int32_t y, std::uint32_t color, std::int32_t scale, int font, float depth);
    static HRESULT drawSpriteQuad(std::uint32_t color, const float* uv, float left, float top, float right, float bottom);
    static HRESULT drawSpriteTexture(std::uint32_t color, std::int32_t texture, float left, float top, float right, float bottom, const float* uv, bool reserved = false);
    static void drawTexture(std::int32_t left, std::int32_t top, std::int32_t width, std::int32_t height, const char* name, std::uint32_t alpha, float depth, const float* uv);
    static void tintTexture(std::int32_t left, std::int32_t top, std::int32_t width, std::int32_t height, const char* name, std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint32_t alpha, const float* uv);
    static void drawFullscreenOverlay();
    static void setRenderState();
    static void restoreRenderState();
    static void drawFrame();
    static void drawAll();
    static void drawWindow(std::int32_t window);
    static void updateLoadingProgress(std::uint32_t increment);
    static void finishLoading();
};


struct SferaFontGlyphRuntime {
    uint32_t texture_index;
    float u;
    float v;
    bool defined;
};
struct SferaFontAtlasLayoutRuntime {
    uint32_t span[5];
    uint32_t origin[5];
    uint32_t cell_step[5];
    uint32_t resource_count[5];
    uint32_t code_base[5];
};
class GameFontAtlas {
public:
    char language_suffix[8]{};
    SferaFontGlyphRuntime glyphs[256]{};
    SferaFontAtlasLayoutRuntime layout{};
    std::uint32_t metrics[256][5]{};
    IDirect3DTexture9* textures[256][5]{};
    GameFontAtlas() = default;
    GameFontAtlas(const GameFontAtlas&) = delete;
    GameFontAtlas& operator=(const GameFontAtlas&) = delete;
    ~GameFontAtlas();
    void clear() noexcept;
    void load(int font, const char* filename, std::int32_t outline, std::uint32_t spacing, std::uint32_t emptyWidth);
};

inline GameFontAtlas g_sfera_font_runtime;

inline CBaseManagerCommonItem g_sfera_player_lists;

struct IDirectInput8A;
struct IDirectInputDevice8A;

struct SferaMouseInputState {
    std::int32_t dx = 0;
    std::int32_t dy = 0;
    std::uint32_t buttons = 0;
    std::int32_t wheel = 0;
};

class SferaInputDevices {
public:
    static constexpr std::uint8_t pressedMask = 1u << (std::numeric_limits<std::uint8_t>::digits - 1);
    SferaInputDevices() = default;
    SferaInputDevices(const SferaInputDevices&) = delete;
    SferaInputDevices& operator=(const SferaInputDevices&) = delete;
    ~SferaInputDevices() { release(); }
    IDirectInput8A* direct_input = nullptr;
    IDirectInputDevice8A* mouse_device = nullptr;
    IDirectInputDevice8A* keyboard_device = nullptr;
    std::uint8_t keyboard_state[256]{};
    std::uint8_t view_adjust_state = 0;
    std::uint8_t modifier_08 = 0;
    std::uint8_t modifier_20 = 0;
    void initialize(HWND window);
    void release() noexcept;
    void pollKeyboard();
    std::uint32_t takeKeyPress();
    SferaMouseInputState pollMouse();
};

inline SferaInputDevices g_sfera_direct_input_runtime;

struct SferaSliceReference32 {
    // Byte offsets in script memory; end is inclusive and begin == 0 means unbounded.
    std::uint32_t base;
    std::uint32_t begin;
    std::uint32_t end;
    bool contains(std::uint32_t length = 1, bool allowNull = false) const;
    void diagnoseRange(std::uint32_t length);
};

struct SferaMbcValue {
    enum Type : std::uint8_t { Byte = 0, BytePointer = 1, Integer = 16, IntegerPointer = 17, Real = 32, RealPointer = 33, Address = 48 };
    Type type;
    std::size_t width;
    SferaSliceReference32 source;
    SferaSliceReference32 value;
    bool isPointer() const;
    static std::size_t storageSize(Type valueType);
    std::size_t elementSize() const;
    std::int32_t integer() const;
    float real() const;
    std::int32_t asInteger() const;
    float asReal() const;
    void setReal(float number);
    void detach();
    SferaSliceReference32& asSlice();
    void storeAs(Type destinationType, void* destination) const;
    static std::int32_t truncate(double number);
    static std::int64_t truncateReal(double number);
};

struct ScriptProgramDiagnostic {
    char name[32];
    std::uint32_t declaration_offset;
    std::uint32_t entry_offset;
    std::uint32_t stop_offset;
    std::int8_t state;
    std::uint8_t priority;

    std::uint32_t local_memory_offset;
    std::uint32_t return_offsets[20];
    std::uint8_t callDepth;

    std::uint32_t instruction_offset;

    bool executing;

    std::int32_t caller_program;
    std::uint16_t previous_program;
    std::uint16_t next_program;

};

struct SferaMbcExecutionContext {
    ScriptProgramDiagnostic* program_table_base;
    std::uint8_t* instruction_cursor;
    std::uint8_t* bytecode_base;
    std::uint8_t* process_memory_base;
    uint32_t process_index;
    std::int32_t program_index;
    uint32_t process_id;
    SferaMbcProcessRecord* active_process;
};


struct SferaMbcNamedVectorRecord {
    std::uint32_t* value_data;
    uint32_t size;

    char* name_text;
};

struct SferaMbcFunctionRecord {
    char name[32];
    std::uint32_t declaration_offset;
    std::uint32_t entry_offset;
    std::int32_t program_index;
    bool allow_reentry;

};

struct SferaMbcQueuedCommand {
    char name[32];
    char argument_types[16];
    std::uint8_t argument_data[512];
    SferaMbcQueuedCommand* next;
};

struct SferaWorldSlotRecord {
    static constexpr std::size_t packetPayloadCapacity = 400;
    uint32_t object_handle;
    uint32_t state;
    uint32_t linked_handle;
    uint32_t primary_state;
    uint32_t reliable_bit_count;
    uint8_t reliable_payload[packetPayloadCapacity];
    uint32_t reliable_process;
    uint32_t unreliable_bit_count;
    uint8_t unreliable_payload[packetPayloadCapacity];
    uint32_t unreliable_process;
    std::int32_t origin[3];
};

struct SferaMbcRegionRecord {
    static constexpr SferaMbcRegionRecord undefined() {
        SferaMbcRegionRecord result{};
        std::fill(std::begin(result.formats), std::end(result.formats), std::int8_t{-1});
        result.field_count = -1;
        result.flags = -1;
        result.program_index = UINT16_MAX;
        return result;
    }
    std::int8_t formats[28];
    std::int32_t field_count;
    std::int8_t flags;

    std::uint16_t program_index;
};

struct SferaMbcModuleRecord {
    char name[32];
    SferaMbcRegionRecord regions[62];
};

struct SferaMbcModuleImage {
    static constexpr std::size_t functionSlotCount = 80;
    std::uint32_t header_word = 0;
    std::uint32_t module_tag = 0;
    std::span<const std::uint8_t> bytecode;
    std::span<const std::uint8_t> memory;
    std::vector<ScriptProgramDiagnostic> programs;
    std::vector<SferaMbcFunctionRecord> functions;
    std::array<std::uint16_t, functionSlotCount> function_map;
    std::span<const std::uint8_t> region_definitions;
    std::array<std::uint32_t, 3> exported_offsets{};
    std::array<std::vector<std::uint32_t>, 3> relocations;
    bool read(std::span<const std::uint8_t> data, bool linking);
};

struct SferaMbcRegionPacket {
    SferaMbcRegionPacket* next;
    std::uint8_t* data;
    std::uint32_t timestamp;
    std::int32_t origin[3];
};

class SferaMbcBitStream {
    static constexpr unsigned coordinateMagnitudeBits = 11;
    static constexpr std::uint32_t coordinateSignBit = 1u << coordinateMagnitudeBits;
    static constexpr std::uint32_t coordinateMagnitudeMask = coordinateSignBit - 1u;
    std::span<const std::uint8_t> data_;
    std::uint8_t* output_ = nullptr;
    std::size_t position_ = 0;
    bool valid_ = true;
public:
    explicit SferaMbcBitStream(std::span<const std::uint8_t> data, std::size_t position = 0) : data_(data), position_(position) {}
    explicit SferaMbcBitStream(std::span<std::uint8_t> data, std::size_t position = 0) : data_(data), output_(data.data()), position_(position) {}
    bool valid() const { return valid_; }
    std::size_t position() const { return position_; }
    std::size_t remaining() const { return position_ <= data_.size() * 8 ? data_.size() * 8 - position_ : 0; }
    std::uint32_t read(unsigned width);
    void write(std::uint32_t value, unsigned width);
    void append(std::span<const std::uint8_t> data, std::size_t bits);
    bool skipRegion(const SferaMbcRegionRecord& region);
    std::uint32_t readField(std::int8_t format, std::span<const std::int32_t, 3> origin);
    bool writeField(std::int8_t format, std::uint32_t value, std::span<const std::int32_t, 3> origin);
    static std::uint32_t encodeCoordinate(std::int32_t origin, float coordinate);
    static float decodeCoordinate(std::int32_t origin, std::uint32_t code);
};

using SferaMbcModuleIds = std::array<std::uint16_t, 8>;
struct SferaMbcBytecodeKey {
    SferaMbcModuleIds modules;
    std::uint32_t memory_size;
    bool operator<(const SferaMbcBytecodeKey& other) const noexcept { return modules == other.modules ? memory_size < other.memory_size : modules < other.modules; }
};

struct SferaMbcProcessRecord {
    enum Flags : std::uint32_t { unloadAfterExecution = 1u << 2, markedForUnload = 1u << 5 };
    enum class ResourceKind { worldObject, file, fileSearch, dynamicArray, textControl, spriteControl, gameWindow, interfaceWindow, container };
    struct CleanupEntry { std::uint32_t handle; ResourceKind kind; };
    void registerResource(std::uint32_t handle, ResourceKind kind);
    void unregisterResource(std::uint32_t handle, ResourceKind kind);
    void linkProgram(std::uint32_t index);
    bool activateProgram(std::int32_t index);
    bool activateProgram(const char* name);
    void appendCommand(std::string_view command);
    std::uint32_t growMemory(std::uint32_t size);
    SferaMbcFunctionRecord* findFunction(std::string_view name);
    void discardQueuedCommand();
    void readRegions(std::span<const std::uint8_t> definitions, std::uint32_t firstProgram);
    void releaseResources();
    void queueRegion(std::size_t region, std::uint32_t timestamp, std::span<const std::int32_t, 3> origin, std::span<const std::uint8_t> payload, std::size_t firstBit, std::size_t bitCount, bool ordered);
    char name[32];
    SferaMbcModuleIds linked_modules;
    uint32_t field_040;
    uint32_t module_tag;
    std::uint8_t* bytecode_base;
    uint32_t bytecode_size;
    std::uint8_t* process_memory_base;
    uint32_t process_memory_size;
    std::size_t program_count;
    ScriptProgramDiagnostic* program_table_base;

    std::size_t auxiliary_record_count;
    SferaMbcFunctionRecord* functions;
    int32_t chain_prev_index;
    int32_t chain_next_index;
    uint16_t program_map_a[4];
    uint16_t program_map_b[4];
    uint32_t field_084;
    uint32_t field_088;
    uint32_t field_08c;
    uint32_t field_090;
    uint32_t flags;
    std::int16_t subscriber_count;
    std::uint16_t subscriber_capacity;
    struct Subscriber { std::uint16_t slot; std::uint8_t metadata[10]; };
    Subscriber* subscribers;
    CleanupEntry* cleanup_entries;
    std::size_t cleanup_entry_count;
    std::size_t cleanup_capacity;
    char* owned_block_b;
    uint32_t process_id;
    bool programs_queued;
    bool execution_linked;
    SferaMbcQueuedCommand* queued_commands;
    uint32_t field_0c0;
    std::uint16_t* function_map;
    int32_t execution_prev_index;
    int32_t execution_next_index;
    SferaMbcRegionRecord* regions;
    uint32_t field_0d4;
    int32_t field_0d8;
    std::uint32_t region_timestamps[63];
    SferaMbcRegionPacket* received_regions[63];
    uint16_t code_range_ids[8];
    uint32_t code_range_begin[8];
    uint32_t code_range_size[8];
    uint32_t code_range_memory_offset[8];
    uint16_t code_range_count;

};

struct SferaMbcValueStackStorage {

    SferaMbcValue entries[256];
};
struct SferaMbcInterpreterStorage {
    uint32_t send_field_data[4088];
    SferaMbcValueStackStorage value_stack;
    SferaMbcModuleRecord module_records[4096];
};

struct SferaMbcRuntime {
    enum class HaltState { Running, Requested, Dispatched };
    using ResourceKind = SferaMbcProcessRecord::ResourceKind;
    enum class WindowOperation : std::uint32_t { Create = 0, Destroy = 1, DisplayWidth = 2, DisplayHeight = 3, TextHeight = 4, FontHeight = 5, LineOffset = 6, TakeInput = 7, HitTest = 8, Visible = 9, Bounds = 10, TextSize = 11, GlyphWidth = 12, Scrollable = 13, CursorPosition = 14, SystemCursorVisible = 15, SystemCursorKind = 16, CursorKind = 17, CursorImage = 18, CursorText = 19, Open = 20, Close = 21, PollEvent = 22, SetText = 23, ControlAt = 24, SendMessage = 25, GetText = 26, SystemEvent = 27, WindowUnderCursor = 28, ItemAt = 29, SavedPositionsSize = 30, ReadSavedPositions = 31, WriteSavedPositions = 32, Position = 33, Size = 34, Description = 35, Tooltip = 36, Options = 37, EscapeWindow = 38, LegacyCreateDialog = 39, LegacyDestroyDialog = 40, LegacyPollDialogEvent = 41, LegacySendDialogMessage = 42, LegacyDialogItem = 43, LegacySetDialogText = 44, LegacyGetDialogText = 45, Shutdown = 46, LegacyPumpMessages = 47, ActiveWindow = 55, LoadingProgress = 78, FinishLoading = 79 };
    enum class Builtin : std::uint8_t { Fail = 0, FailAlternate = 1, Exit = 2, LoadProcess = 16, UnloadProcess = 17, LinkProcess = 18, Connect = 30, Disconnect = 31, FormatText = 67, NamedFormattedLog = 91, System = 103, DiscardInteger = 120, Reserved122 = 122, BoundedFormatText = 123, FormattedLog = 126, Reserved130 = 130, Reserved133 = 133, CallFunction = 20, CallMainFunction = 21, Distance = 81, ScanText = 9, ScriptLog = 38, ParseText = 128, ChatUtility = 129, Window = 10, Send = 26, Receive = 33, Configuration = 117, CreateFile = 40, OpenFile = 41, CloseFile = 42, ReadFile = 44, WriteFile = 43, ReadLine = 124, LockFile = 116, SeekFile = 65, FileSize = 66, FileTime = 70, ResizeFile = 71, SetFileTime = 72, RemoveFile = 69, RenameFile = 68, SetAnimation = 87, SetFrame = 88, AnimationLength = 89, SetInterpolation = 90, MouseMotion = 98, ThisProcessName = 104, ProcessName = 107, ModuleName = 109, FindModule = 110, FontSettings = 118, DestroyObject = 60, DestroyText = 62, DestroySprite = 105, ObjectProcess = 84, SetRenderEnabled = 99, CreateObject = 47, SetPosition = 48, MoveWorld = 49, CommandVelocity = 92, VerticalVelocity = 93, AngularVelocity = 94, Airborne = 97, ObjectBasis = 100, ObjectPosition = 101, ObjectRotation = 102, EditorPick = 131, AllocateMemory = 15, AllocateDynamic = 113, FreeDynamic = 112, SetNamedValue = 114, NamedValue = 115, RebaseSlice = 121, CopyProcessMemory = 77, CopyProcessString = 108, Text = 61, TextColor = 63, Sprite = 73, Effect = 111, MovementContact = 83, FileChecksum = 74, MemoryChecksum = 163, CompareMemory = 147, PlayerLists = 132, FindProcess = 28, Sin = 3, Cos = 4, Exp = 125, ArcTangent = 7, AbsoluteInteger = 6, AbsoluteReal = 5, SimulationTick = 8, RandomReal = 106, PackColor = 11, ScaleColor = 134, SquareRoot = 12, SceneContext = 13, KeyboardState = 14, ProcessModule = 19, ActiveTag = 22, ArgumentCount = 23, CurrentModule = 24, CurrentProcess = 39, ZeroResult = 25, ZeroResultAlternate = 27, TickDifference = 80, ProfileValue = 29, ProcessFlag = 32, CopyString = 34, CopyStringCount = 136, AppendString = 35, FindString = 95, FindStringInsensitive = 135, StringLength = 36, CompareStrings = 37, CompareStringsInsensitive = 75, CompareStringsCount = 76, CompareStringsCountInsensitive = 137, DiscardArgument = 86, IntegerValue = 45, RealValue = 46, NextDefaultValue = 64, CallerProcess = 127, CopyMemory = 78, MoveMemory = 96, FillMemory = 79, StopInterpreter = 82, NetworkInitialization = 85, InvalidResult = 119, BitAnd = 138, BitOr = 139, BitXor = 140, BitNot = 141, ShiftLeft = 142, ShiftRight = 143, ClearBit = 144, SetBit = 145, TestBit = 146, WriteByte = 148, WriteShort = 149, WriteThreeBytes = 150, WriteWord = 151, WriteReal = 152, WriteString = 153, ReadByte = 154, ReadShort = 155, ReadThreeBytes = 156, ReadWord = 157, ReadReal = 158, ReadString = 159, LowerBoundInteger = 160, ContainerCommand = 161, ContainerManagement = 162, PositionX = 54, PositionY = 55, PositionZ = 56, RotationX = 57, RotationY = 58, RotationZ = 59, SetRotation = 52, MoveLocal = 50, MoveForward = 51, Rotate = 53 };
    enum class Instruction : std::uint8_t {
        Yield = '|', EndProgram = '#', InvokeBuiltin = 'f', ReturnFunction = 'r', BindParameters = 'O', DispatchCommand = 201, LoadVariable = 105, JumpIfFalse = 73, JumpIfFalseShort = 75, ArrayElement = 97, SliceElement = 98, PointerElement = 109, FieldValue = 100, FieldSlice = 104, CallLocal = 99,         Jump = 'G', JumpShort = 'J', ArgumentCount = ',', ResetStack = '0', LiteralWord = '9', LiteralShort = '(', LiteralByte = ')', StringLiteral = 'A', SliceVariable = 'e', SliceLiteral = 'l', StartProgram = 'R', CallProgram = 'U', StopProgram = 'S', PauseProgram = 'P', ResumeProgram = 'C', ReturnLocal = 't', Assign = '=', Dereference = '^', AddressOf = '&', Add = '+', Subtract = '-', Multiply = '*', Divide = '/', Remainder = '%', Equal = 240, NotEqual = 237, Greater = '>', Less = '<', GreaterEqual = 225, LessEqual = 236, ShortCircuitOr = 'L', ShortCircuitAnd = 'M', IntegerResult = 235, IntegerResultAlternate = 232, Negate = 241, LogicalNot = '!', PreIncrement = 239, PreDecrement = 243, PostIncrement = 246, PostDecrement = 247, Halt = 'H', IntegerToReal = '.', PreviousIntegerToReal = ':', Swap = '~', PointerAdd = '[', PointerSubtract = ']', RealToInteger = '`', PreviousRealToInteger = '"', PointerPreIncrement = 207, PointerPreDecrement = 211, PointerPostIncrement = 214, PointerPostDecrement = 215, IntegerPair = ';', EnterFrame = '1', LeaveFrame = '2', UnlinkedFunction = 'g'
    };
    // Script words remain 32-bit; mapped addresses never contain truncated native pointers.
    static constexpr std::uint32_t mappedAddressBegin = 1u << 31;
    struct MemoryRegion { const std::uint8_t* data; std::size_t size; SferaMbcProcessRecord* process; const void* owner; };
    using NativeResource = std::variant<SphereUI::Window*, SferaActiveEffect*, SferaScriptContainer*, std::intptr_t>;
    std::map<std::uint32_t, MemoryRegion> mapped_memory;
    std::unordered_map<std::uint32_t, NativeResource> native_resources;
    std::unordered_map<NativeResource, std::uint32_t> native_resource_ids;
    std::uint32_t next_native_handle = 1;
    std::uint8_t* memoryAt(std::uint32_t address, std::size_t size = 1, SferaMbcProcessRecord* process = nullptr) const;
    char* textAt(std::uint32_t address) const;
    std::uint32_t mapMemory(const void* data, std::size_t size, const void* owner = nullptr);
    std::uint32_t mapProcessMemory(SferaMbcProcessRecord& process);
    SferaSliceReference32 rebaseSlice(SferaSliceReference32 slice, SferaMbcProcessRecord& source);
    void forgetMemory(const void* owner);
    std::uint32_t addMemoryRegion(MemoryRegion region);
    template<class T> std::uint32_t nativeHandle(T value) {
        if constexpr (std::is_pointer_v<T>) { if (value == nullptr) return 0; }
        else if (value == -1) return UINT32_MAX;
        const NativeResource resource{value};
        if (const auto existing = native_resource_ids.find(resource); existing != native_resource_ids.end()) return existing->second;
        if (next_native_handle >= static_cast<std::uint32_t>(INT32_MAX)) throw std::length_error("Script resource handles exhausted");
        const auto handle = next_native_handle++;
        native_resources.emplace(handle, resource);
        try { native_resource_ids.emplace(resource, handle); } catch (...) { native_resources.erase(handle); throw; }
        return handle;
    }
    template<class T> T nativeResource(std::uint32_t handle) const {
        if (const auto entry = native_resources.find(handle); entry != native_resources.end()) if (const auto* value = std::get_if<T>(&entry->second)) return *value;
        if constexpr (std::is_pointer_v<T>) return nullptr; else return -1;
    }
    void forgetNativeResource(const NativeResource& resource);

    std::int32_t popInteger();
    SferaSliceReference32& popSlice();
    std::int32_t nextInteger();
    float nextReal();
    SferaSliceReference32& nextSliceReference(const char* diagnostic = "popsliceupref(): stack underflow");
    SferaSliceReference32 nextSlice();
    void pushInteger(std::uint32_t value);
    void pushReal(float value);
    void pushSlice(const SferaSliceReference32& value, SferaMbcValue::Type type);
    void pushReference(SferaMbcValue::Type type, const SferaSliceReference32& reference, bool load);
    SferaMbcProcessRecord* findProcess(std::uint32_t id);
    std::uint32_t loadProcess(std::string_view name, std::uint32_t requestedIndex);
    std::uint32_t linkProcess(std::string_view name);
    std::uint32_t unloadProcess(std::uint32_t index);
    void registerBytecode(std::uint8_t* bytecode, const SferaMbcModuleIds& modules, std::uint32_t memorySize);
    void resetBytecodeCache();
    std::uint8_t* findBytecode(const SferaMbcModuleIds& modules, std::uint32_t memorySize);
    SferaMbcNamedVectorRecord* findNamedVector(const char* name);
    std::uint32_t namedValue(const char* name, std::int32_t index = 0);
    void setNamedValue(const char* name, std::uint32_t value, std::int32_t index = 0);
    bool reportError(const char* message);
    bool reportError(const char* prefix, const char* suffix);
    void enqueueProcess(std::int32_t index, SferaMbcProcessRecord& process);
    void dequeueProcess(SferaMbcProcessRecord& process);
    bool executeInstruction(Instruction instruction);
    bool executeBuiltin(Builtin builtin);
    template<class T> T readOperand() { T result; std::memcpy(&result, instruction_cursor, sizeof(result)); instruction_cursor += sizeof(result); return result; }
    template<class T> T readMemory(std::uint32_t offset) const { T result; std::memcpy(&result, memoryAt(offset, sizeof(result)), sizeof(result)); return result; }
    template<class T> void writeMemory(std::uint32_t offset, const T& value) { std::memcpy(memoryAt(offset, sizeof(value)), &value, sizeof(value)); }
    void reportInvalidInstruction();
    void exportSlice(SferaSliceReference32& destination, const void* data, std::size_t size, const void* owner);
    void initialize();
    void tick();
    void reloadQuickFiles();
    void systemCommand();
    void buildRegion();
    std::string formatArguments(const char* pattern, std::size_t limit = std::numeric_limits<std::size_t>::max());
    void formatText(bool bounded);
    void writeFormattedLog(bool named);
    void receiveRegion();
    void sendRegion(std::int32_t slotIndex, std::uint32_t region, std::uint32_t flags);
    void bindParameters();
    void pushCommandArguments(const SferaMbcQueuedCommand& command);
    void dispatchQueuedCommand();
    void callFunction(bool mainProcess);
    void returnFromFunction();
    void calculateDistance();
    void scanText();
    void chatUtility();
    void parseText();
    void windowCommand();
    void writeScriptLog();
    char* nextText(bool allowNull = false);
    void pushText(const char* text);
    void copyText(const SferaSliceReference32& destination, const char* text);

    int32_t execution_chain_tail;
    int32_t execution_chain_head;
    std::size_t execution_chain_count;
    int32_t process_chain_first;
    int32_t process_chain_last;
    ScriptProgramDiagnostic* program_table_base;
    std::uint8_t* instruction_cursor;
    SferaMbcNamedVectorRecord* current_named_vector;
    char diagnostic_context[1512];
    std::int32_t argument_count;
    std::size_t argument_end;
    uint32_t process_index;
    std::uint8_t* current_instruction_address;
    uint32_t active_tag;
    _finddata64i32_t script_find_data;
    char text_buffer[10000];
    std::size_t call_frame_depth;
    SferaMbcProcessRecord processes[65536];
    uint32_t process_search_cursor;
    uint32_t instruction_step_count;
    std::int32_t program_index;
    std::int32_t pending_program_index;
    std::size_t dispatch_process_count;
    std::size_t execution_context_depth;
    std::uint8_t* bytecode_base;
    SferaMbcExecutionContext execution_context_stack[100];
    std::size_t argument_cursor;
    std::size_t frame_stack_base[22];
    HaltState halt_state;
    uint8_t send_field_width[4096];
    ScriptProgramDiagnostic* active_program_record;
    std::size_t value_stack_size;
    SferaMbcProcessRecord* active_process;
    std::map<SferaMbcBytecodeKey, std::uint8_t*> bytecode_cache;
    std::uint8_t* process_memory_base;
    std::size_t send_field_count;
    bool execution_failed;
    Instruction current_opcode;

    SferaMbcNamedVectorRecord named_vectors[1000];
    std::size_t named_vector_count;
};

struct SferaDataContainerHeader {
    enum class Kind : std::uint32_t { List = 1, Vector, Set, Map, HashMap };
    enum class ValueType : std::uint32_t { Integer = 1, Real, Byte, String, Binary };
    Kind kind;
    bool iteration_active;

};

struct SferaScriptContainer {
    using Kind = SferaDataContainerHeader::Kind;
    using ValueType = SferaDataContainerHeader::ValueType;
    using Binary = std::vector<std::uint8_t>;
    enum class Command : std::int32_t { Write = 0, Erase = 1, Read = 2, First = 3, Next = 4, IteratorState = 5, Clear = 9, Append = 10, Prepend = 11 };
    enum class Lifecycle : std::int32_t { Create = 1, Destroy, Kind, ValueType, KeyType };
    template<class C, bool HashStorage = false> struct Content {
        using Value = typename C::value_type;
        static constexpr bool Hashed = HashStorage;
        static constexpr bool Mapped = Hashed || requires { typename C::mapped_type; };
        static constexpr bool Indexed = !Mapped && requires(C& values) { values[0]; };
        static constexpr bool Unique = requires { typename C::key_type; };
        C values;
        std::conditional_t<Indexed, std::size_t, typename C::iterator> cursor{};
        std::conditional_t<Hashed, std::vector<std::pair<typename C::iterator, typename C::iterator>>, std::monostate> buckets;
        Content();
        template<class K> std::size_t bucketIndex(const K& key) const requires Hashed;
        template<class K> typename C::iterator find(const K& key) requires Hashed;
        template<class K, class V> void assign(K&& key, V&& value) requires Hashed;
        void erase(typename C::iterator position) requires Hashed;
        void rehash(std::size_t count) requires Hashed;
    };
    SferaDataContainerHeader header;
    ValueType value_type;
    ValueType key_type;
    std::variant<Content<std::list<std::int32_t>>, Content<std::list<float>>, Content<std::list<std::string>>, Content<std::list<Binary>>, Content<std::vector<std::int32_t>>, Content<std::vector<float>>, Content<std::vector<std::uint8_t>>, Content<std::vector<std::string>>, Content<std::vector<Binary>>, Content<std::set<std::int32_t>>, Content<std::set<std::string>>, Content<std::map<std::int32_t, std::int32_t>>, Content<std::map<std::int32_t, float>>, Content<std::map<std::int32_t, std::string>>, Content<std::map<std::int32_t, Binary>>, Content<std::map<std::string, std::int32_t>>, Content<std::map<std::string, float>>, Content<std::map<std::string, std::string>>, Content<std::map<std::string, Binary>>, Content<std::list<std::pair<const std::int32_t, std::int32_t>>, true>, Content<std::list<std::pair<const std::int32_t, float>>, true>, Content<std::list<std::pair<const std::int32_t, std::string>>, true>, Content<std::list<std::pair<const std::int32_t, Binary>>, true>, Content<std::list<std::pair<const std::string, std::int32_t>>, true>, Content<std::list<std::pair<const std::string, float>>, true>, Content<std::list<std::pair<const std::string, std::string>>, true>, Content<std::list<std::pair<const std::string, Binary>>, true>, Content<std::list<std::pair<const Binary, std::int32_t>>, true>, Content<std::list<std::pair<const Binary, float>>, true>, Content<std::list<std::pair<const Binary, std::string>>, true>, Content<std::list<std::pair<const Binary, Binary>>, true>> content;
    template<class C, bool Hashed> SferaScriptContainer(Kind kind, ValueType type, std::in_place_type_t<Content<C, Hashed>>, ValueType keyType) : header{kind, false}, value_type(type), key_type(keyType), content(std::in_place_type<Content<C, Hashed>>) {}
    SferaScriptContainer(const SferaScriptContainer&) = delete;
    SferaScriptContainer& operator=(const SferaScriptContainer&) = delete;
    static SferaScriptContainer* create(Kind kind, ValueType type, ValueType keyType = ValueType::Integer);
    void execute(SferaMbcRuntime& runtime);
    void destroy();
};

struct SferaNetworkTransportRuntime {
    std::uint32_t client_mode;
    bool connection_lost;
    bool receive_busy;
    bool receive_corrupted;
    std::uint64_t sent_bytes;
    std::uint64_t received_bytes;
    std::uint32_t receive_read_index;
    std::uint32_t receive_write_index;
};

struct SferaNetworkConnectionInfoRuntime {
    std::uint32_t round_trip_latency_ms;
    std::uint32_t throughput_bps;
};

inline constexpr std::size_t kSferaNetworkMessageSlotCount = 3048u;
struct SferaNetworkMessageSlot {
    std::uint8_t data[400];
    std::uint32_t data_size;
};

inline constexpr std::size_t kTcpReceiveBufferCapacity = 60000u;

enum class TcpMessage : std::uint16_t {
    connection_limit = 100u,
    handshake = 200u,
    payload = 300u,
    client_mode = 400u,
    keepalive = 500u,
    sequence_reset = 600u,
    packet_counter = 700u
};

struct SferaTcpConnectionContext {
    struct WorkerThread { HANDLE handle; DWORD id; };
    SferaTcpConnectionContext();
    ~SferaTcpConnectionContext();
    int initialize(const char* hostname, std::uint16_t port);
    void shutdown() noexcept;
    static constexpr std::uint32_t sendCapacity = 80000;
    bool queuePacket(std::uint32_t payloadSize, TcpMessage message, const void* payload) noexcept;
    void sendPending() noexcept;
    std::uint8_t receive_buffer[kTcpReceiveBufferCapacity];
    std::uint32_t receive_size;

    SOCKET socket;
    std::uint32_t remote_id;
    WorkerThread workers[3];
    std::uint8_t stop_requested;

    std::uint32_t received_bytes_window;
    std::uint32_t sent_bytes_window;
    std::uint32_t sent_bytes_per_second;
    std::uint32_t received_bytes_per_second;
    std::uint8_t* send_buffer;
    std::uint32_t send_size;
    std::uint8_t initialized;
    std::uint8_t connected;

    std::uint32_t round_trip_ms;
    DWORD keepalive_started_at;
    std::uint8_t keepalive_answered;

    std::uint16_t sequence;
    std::uint16_t checksum_seed;

    std::uint32_t packet_counter;
};

struct SferaTcpIncomingHeader {
    static constexpr std::uint32_t encodedSize = 4;
    std::uint16_t size;
    std::uint16_t message;
    static SferaTcpIncomingHeader decode(const std::uint8_t* bytes) noexcept { return {SferaBinary::readLittleEndian<std::uint16_t>(bytes), SferaBinary::readLittleEndian<std::uint16_t>(bytes + 2)}; }
};

struct SferaTcpHandshakePacket {
    static constexpr std::uint32_t encodedSize = SferaTcpIncomingHeader::encodedSize + 6;
    std::uint32_t remote_id;
    std::uint16_t checksum_seed;
    static SferaTcpHandshakePacket decode(const std::uint8_t* bytes) noexcept { const auto* payload = bytes + SferaTcpIncomingHeader::encodedSize; return {SferaBinary::readLittleEndian<std::uint32_t>(payload), SferaBinary::readLittleEndian<std::uint16_t>(payload + 4)}; }
};

struct SferaTcpOutgoingHeader {
    static constexpr std::uint32_t encodedSize = 8;
    static constexpr std::uint32_t checksumOffset = 2;
    static constexpr std::uint32_t checksumPayloadOffset = 4;
    std::uint16_t size;
    std::uint16_t checksum;
    std::uint16_t sequence;
    std::uint16_t message;
    void encode(std::uint8_t* bytes) const noexcept {
        SferaBinary::writeLittleEndian(bytes, size);
        SferaBinary::writeLittleEndian(bytes + checksumOffset, checksum);
        SferaBinary::writeLittleEndian(bytes + checksumPayloadOffset, sequence);
        SferaBinary::writeLittleEndian(bytes + 6, message);
    }
};

struct SferaNetworkRuntime {
    uint32_t initialization_result;
    uint32_t server_port;
    uint32_t connection_slot;
    SferaActiveEffect* pending_effect;
    uint32_t active_slot;
    uint32_t shutdown_state;
    uint8_t initialized;
    uint32_t bytes_sent_delta;
    uint32_t bytes_retried_delta;
    uint32_t bytes_received_delta;
    SferaNetworkTransportRuntime transport;
    SferaNetworkConnectionInfoRuntime connection_info;
    CRITICAL_SECTION receive_critical_section;
    SferaNetworkMessageSlot message_slots[kSferaNetworkMessageSlotCount];
    int initialize(const char* hostname, std::uint32_t mode);
    void shutdown();
    void receiveMessages();
    void receiveMessage(SferaNetworkMessageSlot& message);
    void receiveEvents(std::span<const std::uint8_t> payload);
    bool sendPacket(std::uint32_t flags, std::span<const std::uint8_t> payload);
    static std::int32_t tickDifference(std::uint32_t current, std::uint32_t previous);
    static void encodePayload(std::uint8_t* data, std::int32_t length);
    void updateTcpStatistics();
};

class SferaGameCalendar {
    struct Field { unsigned shift; unsigned width; std::uint32_t bias; constexpr std::uint32_t mask() const { return (1u << width) - 1u; } };
    static constexpr std::array<Field, 6> fields{{{0, 2, 0}, {2, 6, 0}, {8, 5, 0}, {13, 5, 0}, {18, 4, 0}, {22, 10, 7800}}};
    static constexpr const Field& field(std::int32_t index) { return fields[index >= 1 && index <= 5 ? index - 1 : 5]; }
public:
    enum Component : std::int32_t { Quarter = 1, Minute, Hour, Day, Month, Year };
    static constexpr std::uint32_t firstYear = 7800;
    static constexpr std::uint32_t quartersPerMinute = 4, minutesPerHour = 60, hoursPerDay = 24, daysPerYear = 365;
    static constexpr std::uint32_t quartersPerHour = quartersPerMinute * minutesPerHour, quartersPerDay = quartersPerHour * hoursPerDay, quartersPerYear = quartersPerDay * daysPerYear;
    static constexpr std::array<std::uint32_t, 13> monthStarts{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    static constexpr std::uint32_t daysInMonth(std::uint32_t month) { return month >= 1 && month <= 12 ? monthStarts[month] - monthStarts[month - 1] : 0; }
    static constexpr std::uint32_t daysBeforeMonth(std::uint32_t month) { return month >= 1 && month <= 13 ? monthStarts[month - 1] : 0; }
    static constexpr std::uint32_t pack(std::uint32_t year, std::uint32_t month, std::uint32_t day, std::uint32_t hour, std::uint32_t minute, std::uint32_t quarter = 0) { return ((year - firstYear) << field(Year).shift) | (month << field(Month).shift) | ((day & field(Day).mask()) << field(Day).shift) | (hour << field(Hour).shift) | (minute << field(Minute).shift) | quarter; }
    static std::uint32_t fromUnixTime(std::int64_t timestamp);
    static std::uint32_t advance(std::uint32_t calendar);
    static std::uint32_t component(std::uint32_t calendar, std::int32_t index);
    static std::uint32_t withComponent(std::uint32_t calendar, std::int32_t index, std::uint32_t value);
    static std::uint32_t ticks(std::uint32_t calendar);
};



class SferaClientApplication {
public:
    static int run(HINSTANCE instance);
    static void loadResources();
    static void shutdown();
    [[noreturn]] static void terminateWithError(const char* message);
    [[noreturn]] static void arrayBoundsError(std::int32_t index);
private:
    static void configureResourceDirectory();
    static void resetWorld();
    static void renderFrame();
    bool initialize();
    bool runStartupScripts();
    void runMainLoop();
    bool updateSimulation();
    std::int32_t advanceClock();
    std::uint32_t previous_tick_ = 0;
    std::int32_t tick_remainder_ = 0;
    std::uint32_t object_update_ticks_ = 0;
    std::uint32_t effect_update_ticks_ = 0;
    std::uint32_t maintenance_ticks_ = 0;
};
