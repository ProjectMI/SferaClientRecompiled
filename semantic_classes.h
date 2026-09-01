#pragma once

#include <cstddef>
#include <cstdint>

struct LiftCpu;
struct SferaIntrusiveListHeader;
class CSound;


struct SferaParserRange {
    std::int32_t begin;
    std::int32_t end;
};

class SferaSimpleParser {
public:
    std::uint32_t source_begin;
    std::uint32_t source_end;
    std::uint32_t line_table;
    std::uint32_t line_count;
    char token[1024];
    std::int32_t scan_begin;
    std::int32_t scan_end;
    std::int32_t block_begin;
    std::int32_t block_end;

    void initialize();
    void release();
    void rebuildLineTable();
    void load(const char* filename);
    const char* firstToken(const char* line) const;
    std::int32_t findClosingBrace(std::int32_t begin, std::int32_t end) const;
    std::int32_t parseBlockAt(const char* first_token, std::int32_t line_index, std::int32_t end, SferaParserRange* output_range);
    bool findBlock(const char* name, SferaParserRange* output_range, const SferaParserRange* search_range, std::int32_t occurrence);
    std::int32_t countBlocks(const char* name, const SferaParserRange* search_range);
    bool findValue(const char* name, const SferaParserRange* search_range);
    void setScanRange(const SferaParserRange* range);
    void clearScanRange();
    bool nextValue(const char* name);
    std::uint32_t tokenCount() const;
    void setBlockRange(const SferaParserRange* range);
    void clearBlockRange();
    bool nextBlock(const char* name, SferaParserRange* output_range);
    void getBlockRange(SferaParserRange* output_range) const;
    void getScanRange(SferaParserRange* output_range) const;
    const char* tokenAt(std::uint32_t index) const;
    bool tryReadFloat(std::uint32_t index, float& output) const;
    bool tryReadInt(std::uint32_t index, std::int32_t& output) const;
    bool readFloatSequence(std::uint32_t index, float* output, std::size_t count) const;
    bool readIntSequence(std::uint32_t index, std::int32_t* output, std::size_t count) const;
    float readFloat(std::uint32_t index) const;
    std::int32_t readInt(std::uint32_t index) const;
    char* readString(std::uint32_t index, char* output) const;
    char* readStringBounded(std::uint32_t index, char* output, std::size_t capacity) const;
    char* readQuotedString(std::uint32_t index, char* output) const;
    bool readBool(std::uint32_t index) const;
    static bool equalsIgnoreCase(const char* left, const char* right);
};


struct SferaEffectVec3F {
    float x;
    float y;
    float z;
};

struct SferaEffectRenderSlot {
    SferaEffectVec3F position[4];
    std::uint32_t color[4][4];
    float uv[4][2];
    std::int32_t resource_id;
    std::uint32_t blend_mode;
    std::uint32_t primitive_kind;
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
    std::uint32_t reserved;
    const void* value;
};

class SferaEffectTrack;
struct SferaParticleSystemDefinition;

struct SferaEffectColor32 {
    union {
        struct {
            std::uint8_t red;
            std::uint8_t green;
            std::uint8_t blue;
            std::uint8_t alpha;
        };
        std::uint8_t channels[4];
    };
};

struct SferaEffectMeshResource {
    char name[32];
    std::uint32_t load_state;
    std::uint32_t face_count;
    std::uint32_t vertex_count;
    std::uint32_t uv_count;
    SferaEffectVec3F* vertices;
    float (*uv)[2];
    std::uint32_t (*face_vertices)[4];
    std::uint32_t (*face_uv)[4];
    SferaEffectColor32* colors;
    SferaEffectVec3F* transformed_vertices;
    float (*translated_uv)[2];
    SferaEffectColor32* transformed_colors;
    SferaEffectMeshResource* previous;
    SferaEffectMeshResource* next;

    void release();
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
    SferaEffectColor32 color;
    std::uint32_t self_illumination;
    std::uint32_t runtime_clone;
    std::uint32_t random_row;
    std::uint32_t random_offset;
    std::uint32_t random_state;
    SferaEffectVec3F runtime_position;
    float transform[16];
    char* texture_name;
    std::int32_t texture_id;
    std::uint32_t primitive_flags;

    void initializeDefinition();
    bool loadDefinition(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range);
    std::uint32_t renderSlotCount();
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
    SferaEffectColor32 color;
    float remaining_lifetime;
    float total_lifetime;
    float size;
    std::uint32_t random_row;
    std::uint16_t random_seed_0;
    std::uint16_t random_seed_1;
    std::uint16_t size_track_index;
    std::uint16_t color_track_index;
    std::uint16_t velocity_track_index;
    std::uint16_t gravity_track_index;
    float texture_frame;
    SferaParticleSystemDefinition* linked_particle_system;
    std::int32_t link_index;
};

struct SferaParticleSystemLink {
    char* target_name;
    std::uint32_t instance_count;
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
    char* name;
    SferaParticleRenderSlot* render_slots;
    std::uint32_t shape;
    float radius;
    float height;
    float width;
    std::int32_t random_seed;
    std::int32_t random_factor;
    SferaEffectVec3F direction;
    SferaEffectVec3F* shape_points;
    std::uint32_t shape_point_count;
    SferaEffectVec3F emitter_position;
    SferaEffectTrack* emission_track;
    SferaEffectTrack* emission_position_track;
    float emission_count;
    std::uint32_t flags;
    SferaEffectTrack* rotation_track;
    SferaEffectTrack* scale_track;
    SferaEffectTrack* position_track;
    std::uint32_t render_slot_count;
    std::uint32_t active_particle_count;
    SferaEffectTrack* lifetime_track;
    float lifetime_random_factor;
    float lifetime;
    float emission_fraction;
    std::uint32_t phase_mode;
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
    std::uint8_t first_update;
    std::uint32_t runtime_random_row;
    std::uint32_t runtime_random_seed_0;
    std::uint32_t runtime_random_seed_1;
    std::uint32_t self_illumination;
    std::uint32_t texture_flags;
    SferaEffectVec3F render_basis[4];
    float transform[16];
    std::uint32_t size_track_count;
    std::uint32_t color_track_count;
    std::uint32_t velocity_track_count;
    std::uint32_t gravity_track_count;
    SferaEffectTrack** size_tracks;
    SferaEffectTrack** color_tracks;
    SferaEffectTrack** velocity_tracks;
    SferaEffectTrack** gravity_tracks;
    SferaParticleTextureFrame* texture_frames;
    std::uint32_t texture_frame_count;
    float texture_animation_speed;
    SferaParticleSystemLink* links;
    std::uint32_t link_count;
    std::uint32_t runtime_active;
    std::uint32_t runtime_stop_requested;
    std::uint32_t runtime_clone;

    void initializeDefinition();
    bool loadDefinition(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range);
    void initializeClone();
    void resetClone(const SferaParticleSystemDefinition& source);
    void destroyClone();
    void update(const SferaEffectVec3F* spatial_frame, const float* world_frame, float age);
    void commit();
};

struct SferaSubeffectDefinition {
    std::uint16_t definition_index;
    std::uint8_t kind;
    std::uint8_t attach_mode;
};

struct SferaSoundSource {
    char* filename;
    std::uint8_t silence;
    float silence_duration;
};

struct SferaSoundTimeGroup {
    float begin;
    float end;
    std::uint32_t source_begin;
    std::uint32_t source_end;
};

struct SferaSound3DParameters {
    std::uint32_t structure_size;
    SferaEffectVec3F position;
    SferaEffectVec3F velocity;
    std::uint32_t inside_cone_angle;
    std::uint32_t outside_cone_angle;
    SferaEffectVec3F cone_orientation;
    std::int32_t cone_outside_volume;
    float min_distance;
    float max_distance;
    std::uint32_t mode;
};

class CSoundEffect {
public:
    std::uint32_t effect_number;
    std::uint32_t flags;
    std::uint32_t silence_active;
    std::uint32_t silence_reserved;
    std::uint32_t silence_started_low;
    std::uint32_t silence_started_high;
    float silence_duration;
    float saved_play_time;
    std::uint32_t transition_started_low;
    std::uint32_t transition_started_high;
    SferaSoundSource* sources;
    std::uint32_t source_count;
    SferaSoundTimeGroup* time_groups;
    std::uint32_t time_group_count;
    std::uint32_t distance_paused;
    SferaEffectVec3F offset;
    SferaEffectVec3F region_radius;
    SferaEffectVec3F region_offset;
    float mix_duration;
    std::int32_t last_source_index;
    CSound* active_sound;
    std::int32_t cache_lifetime;
    std::uint32_t shared_definition;
    SferaSound3DParameters sound_parameters;
    SferaEffectVec3F last_position;

    void initialize();
    bool loadDefinition(SferaSimpleParser& parser, const SferaParserRange& range);
    CSoundEffect* clone() const;
    void resetFrom(const CSoundEffect& source);
    void destroy();
    float startTime() const;
    void start(void* frame, bool after_start_time);
    void update(void* frame, float age);
    void stop();
    bool isComplete() const;
};

class IEffect;

struct SferaActiveEffect {
    std::uint16_t position_source;
    std::uint16_t state_flags;
    std::uint32_t source_handle;
    std::uint32_t age_ticks;
    SferaEffectVec3F position;
    std::uint32_t reserved_update_handler;
    IEffect* effect;
    CSoundEffect* resource;
    std::uint32_t sound_started;
    std::uint32_t listener_key;
    float viewer_distance;
    SferaActiveEffect* next;
    SferaActiveEffect* previous;
    SferaIntrusiveListHeader* owner_list;
};

class SferaLightDefinition {
public:
    std::uint32_t position_track;
    std::uint32_t color_track;
    std::uint32_t alpha_track;
    std::int32_t light_index;
    SferaEffectVec3F position;
    float color[4];
    std::uint32_t field_2c;
    std::uint32_t field_30;
    std::uint32_t flags;
    std::int32_t random_color[6];
    float brightness;
    float brightness_delta;
    std::uint8_t brightness_frequency;
    std::uint8_t reserved_59[3];
    std::uint32_t field_5c;
    std::uint8_t attach_mode;
    std::uint8_t reserved_61[3];

    void initializeDefaults();
    bool load(SferaSimpleParser& parser, const SferaParserRange& range);
    void update(const SferaEffectVec3F& base_position, float age, std::uint32_t opacity);
    void release();
};


struct SferaEffectTrackKey {
    float time;
    std::uint32_t mode;
    float scalar_min;
    float scalar_max;
    SferaEffectColor32 color;
    SferaEffectColor32 color_random_range;
    float vector_min[3];
    float vector_max[3];
};


class SferaEffectTrack {
public:
    std::uint32_t keys;
    std::uint32_t key_count;
    std::uint32_t state;

    void initialize();
    void release();
    void allocateKeys(std::uint32_t count);
    void setKey(std::uint32_t index, const SferaEffectTrackKey& key);
    void evaluateVector(float age, SferaEffectVec3F& output) const;
    void evaluateScalar(float age, float& output, const std::uint16_t* random_values = nullptr, std::uint32_t random_offset = 0u) const;
};


SferaEffectTrack* sfera_load_scalar_effect_track(SferaSimpleParser* parser, const SferaParserRange* range);
SferaEffectTrack* sfera_load_vector_effect_track(SferaSimpleParser* parser, const SferaParserRange* range);

struct SferaEffectUpdateContext {
    void* frame;
    float viewer_distance;
};

struct SferaEffectQueryContext {
    void* frame;
    float age;
};

struct SferaEffectSpatialFrames {
    SferaEffectVec3F frames[5];
};

struct SferaEffectWorldFrames {
    float frames[5][16];
};

struct SferaEffectInitializeContext {
    void* spatial_frame;
    std::uint32_t mode;
    float age;
    bool visible;
    void* world_frame;
};

class IEffectListener {
public:
    std::uint32_t change_tick;
    virtual bool onEffectAttached(IEffect& effect, SferaActiveEffect& item, float distance) = 0;
    virtual bool onEffectDetached(IEffect& effect, SferaActiveEffect& item) = 0;
    virtual void onEffectChanged(std::uint32_t age_ticks, IEffect& effect, SferaActiveEffect& item) = 0;
};

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
    std::uint32_t vertex_count;
    SferaBloodVertex vertices[90];
};

struct SferaBloodEffectRuntime : BloodEffListener {
    SferaBloodSpot spots[30];
    std::uint32_t active_count;
    float phase;
    std::uint32_t texture_id;
};

class IEffect {
public:
    char* script_name;
    std::uint32_t effect_id;
    std::uint8_t borrows_definition_storage;
    std::uint8_t deactivated;
    std::uint8_t resources_released;
    std::uint8_t activation_blocked;
    std::uint32_t cycle_length;
    std::uint32_t lifetime_ticks;
    float range_min;
    float range_max;
    IEffect* next;
    IEffect* previous;
    std::uint32_t effect_kind;
    SferaEffectVec3F position;
    IEffectListener* listener;
    float bounds_min[3];
    float bounds_max[3];
    std::uint8_t spatial_gate_enabled;
    std::uint32_t render_slot_budget;

    IEffect() = default;
    void initializeBaseState(std::uint32_t kind);
    void assignScriptName(const char* name);
    virtual void initializeEffect(const SferaEffectInitializeContext& context);
    virtual void updateEffect(const SferaEffectUpdateContext& context);
    virtual void queryEffectState(const SferaEffectQueryContext& context);
    virtual bool activateEffect(bool visible);
    virtual void deactivateEffect(bool preserve_resources);
    virtual void renderEffect();
    virtual IEffect* createEffectResources();
    virtual void setParameter(const SferaEffectParameter* parameters, std::uint32_t count);
    virtual void resetEffect();
    virtual void releaseEffect();
    virtual bool isEffectComplete() const;
    virtual void destroyEffect(bool free_storage);
};

class CScriptedEffect : public IEffect {
public:
    std::uint32_t pooled_instances[16];
    std::uint32_t pooled_count;
    CScriptedEffect* source_definition;
    SferaSubeffectDefinition* subeffects;
    std::uint32_t sound_started;
    std::uint32_t update_visible_only;
    std::uint32_t effect_type;
    CSoundEffect* sound_effect;
    std::uint32_t effect_mesh_definition_count;
    std::uint32_t light_definition_count;
    std::uint32_t subeffect_count;
    std::uint32_t particle_system_definition_count;
    std::uint32_t linked_particle_system_count;
    std::uint32_t linked_render_slot_count;
    std::uint32_t phase_ticks_remaining;
    std::uint32_t work_time_min;
    std::uint32_t work_time_max;
    std::uint32_t sleep_time_min;
    std::uint32_t sleep_time_max;
    std::uint32_t work_phase;
    SferaEffectMeshDefinition* effect_mesh_definitions;
    SferaLightDefinition* light_definitions;
    SferaParticleSystemDefinition* particle_system_definitions;
    void* linked_render_slots;
    SferaParticleSystemDefinition* linked_particle_systems;

    CScriptedEffect() = default;
    void initializeScriptedState();
    bool loadScript(const char* filename);
    std::int32_t findEffectMeshDefinitionIndex(const char* name) const;
    std::int32_t findParticleSystemDefinitionIndex(const char* name) const;
    void buildLinkedParticleSystems();
    void resetRuntimeState();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    void queryEffectState(const SferaEffectQueryContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    IEffect* createEffectResources() override;
    void setParameter(const SferaEffectParameter* parameters, std::uint32_t count) override;
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
    void setParameter(const SferaEffectParameter* parameters, std::uint32_t count) override;
};

class CMolEffect : public IEffect {
public:
    SferaEffectVec3F anchor;
    float texture_phase;
    std::uint32_t anchor_initialized;
    std::int32_t resource_id;
    CSoundEffect* sound_effect;
    std::uint32_t sound_started;
    CMolEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    IEffect* createEffectResources() override;
    void setParameter(const SferaEffectParameter* parameters, std::uint32_t count) override;
    void destroyEffect(bool free_storage) override;
};

class CBladeEffect : public IEffect {
public:
    SferaEffectVec3F anchor;
    float progress;
    std::uint32_t anchor_initialized;
    std::int32_t resource_id;
    CBladeEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    IEffect* createEffectResources() override;
    void setParameter(const SferaEffectParameter* parameters, std::uint32_t count) override;
};

struct SferaGazerEffectSlot {
    IEffect* effect;
    float age;
    SferaEffectVec3F offset;
};

class CGazerLakeEffect : public IEffect {
public:
    std::uint32_t field_5c;
    std::uint32_t slot_count;
    float radius;
    SferaGazerEffectSlot slots[16];
    CGazerLakeEffect() = default;
    void initializePreset(std::uint32_t id, float effect_radius, std::uint32_t count);
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    IEffect* createEffectResources() override;
    void setParameter(const SferaEffectParameter* parameters, std::uint32_t count) override;
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
    void setParameter(const SferaEffectParameter* parameters, std::uint32_t count) override;
    void destroyEffect(bool free_storage) override;
};

class CLightEffect : public IEffect {
public:
    std::uint32_t field_5c;
    float color[4];
    float field_70;
    std::uint32_t field_74;
    std::int32_t field_78;
    float field_7c;
    std::uint8_t field_80;
    std::uint8_t reserved_81[3];
    std::uint32_t field_84;
    CLightEffect() = default;
    void initializePreset();
    void initializeEffect(const SferaEffectInitializeContext& context) override;
    void updateEffect(const SferaEffectUpdateContext& context) override;
    bool activateEffect(bool visible) override;
    void deactivateEffect(bool preserve_resources) override;
    void renderEffect() override;
    IEffect* createEffectResources() override;
    void setParameter(const SferaEffectParameter* parameters, std::uint32_t count) override;
    void destroyEffect(bool free_storage) override;
};

class IOutputDevice {
public:
    IOutputDevice() = default;
    virtual void write(LiftCpu* cpu);
};

class COutputLogDevice : public IOutputDevice {
public:
    COutputLogDevice() = default;
    void write(LiftCpu* cpu) override;
};

class CSphereError : public IOutputDevice {
public:
    CSphereError() = default;
    void write(LiftCpu* cpu) override;
};

class GrassMapMngr {
public:
    GrassMapMngr() = default;
    virtual void loadGrassMap(LiftCpu* cpu);
};

class HyperTextElement {
public:
    HyperTextElement() = default;
    virtual void elementType(LiftCpu* cpu);
};

class HyperTextElement_WordWrap : public HyperTextElement {
public:
    HyperTextElement_WordWrap() = default;
};

class HyperTextElementWithParameters : public HyperTextElement {
public:
    HyperTextElementWithParameters() = default;
};

class HyperTextElement_PlainText : public HyperTextElement {
public:
    HyperTextElement_PlainText() = default;
};

class HyperTextElement_Link : public HyperTextElementWithParameters {
public:
    HyperTextElement_Link() = default;
};

class CItem {
public:
    CItem() = default;
    virtual void resetItem(LiftCpu* cpu);
    virtual void releaseItem(LiftCpu* cpu);
};

class CCommonItem : public CItem {
public:
    CCommonItem() = default;
};

class CItemListCommonItem : public CItem {
public:
    CItemListCommonItem() = default;
    void resetItem(LiftCpu* cpu) override;
};

class CBaseManagerCommonItem : public CItemListCommonItem {
public:
    CBaseManagerCommonItem() = default;
    virtual void handleInsert(LiftCpu* cpu);
    virtual void handleRemove(LiftCpu* cpu);
    virtual void findItem(LiftCpu* cpu);
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

class CSoundFX {
public:
    CSoundFX() = default;
    virtual void play(LiftCpu* cpu);
    virtual void stop(LiftCpu* cpu);
    virtual void rewind(LiftCpu* cpu);
};

class CCursor {
public:
    CCursor() = default;
    virtual void destroy(LiftCpu* cpu);
    virtual void copyStateFrom(LiftCpu* cpu);
    virtual void activate(LiftCpu* cpu);
    virtual void deactivate(LiftCpu* cpu);
    virtual void apply(LiftCpu* cpu);
    virtual void setVisible(LiftCpu* cpu);
    virtual void getPosition(LiftCpu* cpu);
    virtual void setPosition(LiftCpu* cpu);
    virtual void show(LiftCpu* cpu);
    virtual void isInsideViewport(LiftCpu* cpu);
    virtual void isSystemCursorVisible(LiftCpu* cpu);
    virtual void setSystemCursorVisible(LiftCpu* cpu);
    virtual void cursorKind(LiftCpu* cpu);
    virtual void setCursorKind(LiftCpu* cpu);
};

class CHardwareCursor : public CCursor {
public:
    CHardwareCursor() = default;
    void destroy(LiftCpu* cpu) override;
    void copyStateFrom(LiftCpu* cpu) override;
    void activate(LiftCpu* cpu) override;
    void deactivate(LiftCpu* cpu) override;
    void apply(LiftCpu* cpu) override;
    void setVisible(LiftCpu* cpu) override;
    void getPosition(LiftCpu* cpu) override;
    void setPosition(LiftCpu* cpu) override;
    void show(LiftCpu* cpu) override;
    void isInsideViewport(LiftCpu* cpu) override;
    void isSystemCursorVisible(LiftCpu* cpu) override;
    void setSystemCursorVisible(LiftCpu* cpu) override;
    void cursorKind(LiftCpu* cpu) override;
    void setCursorKind(LiftCpu* cpu) override;
};

class CSoftwareCursor : public CCursor {
public:
    CSoftwareCursor() = default;
    void destroy(LiftCpu* cpu) override;
    void copyStateFrom(LiftCpu* cpu) override;
    void activate(LiftCpu* cpu) override;
    void deactivate(LiftCpu* cpu) override;
    void apply(LiftCpu* cpu) override;
    void setVisible(LiftCpu* cpu) override;
    void getPosition(LiftCpu* cpu) override;
    void setPosition(LiftCpu* cpu) override;
    void show(LiftCpu* cpu) override;
    void isInsideViewport(LiftCpu* cpu) override;
    void isSystemCursorVisible(LiftCpu* cpu) override;
    void setSystemCursorVisible(LiftCpu* cpu) override;
    void cursorKind(LiftCpu* cpu) override;
    void setCursorKind(LiftCpu* cpu) override;
};

class UnmanagedResourceBase {
public:
    UnmanagedResourceBase() = default;
    virtual void restoreResource(LiftCpu* cpu);
    virtual void releaseResource(LiftCpu* cpu);
};

class UnmanagedResourceVB : public UnmanagedResourceBase {
public:
    UnmanagedResourceVB() = default;
    void restoreResource(LiftCpu* cpu) override;
};

class UnmanagedResourceIB : public UnmanagedResourceBase {
public:
    UnmanagedResourceIB() = default;
    void restoreResource(LiftCpu* cpu) override;
};

class UnmanagedResourceTexture : public UnmanagedResourceBase {
public:
    UnmanagedResourceTexture() = default;
    void restoreResource(LiftCpu* cpu) override;
};

class UnmanagedResourceVector {
public:
    UnmanagedResourceVector() = default;
    virtual void reserve(LiftCpu* cpu);
};

class StdAllocator {
public:
    StdAllocator() = default;
    virtual void allocate(LiftCpu* cpu);
    virtual void reallocate(LiftCpu* cpu);
    virtual void deallocate(LiftCpu* cpu);
};

namespace SphereUI {

enum class WindowEventHandler : std::uint8_t { none, description, help, authors, quit, sound_options, control_options, interface_options, graphics_options, options, font_options };

class Window;
void bindEventHandler(Window* window, WindowEventHandler handler);
void copyEventHandler(Window* destination, const Window* source);
bool hasEventHandler(const Window* window);
void dispatchEvent(Window* window, LiftCpu* cpu, std::uint32_t callsite);
void unbindEventHandler(const void* window);

class Window {
public:
    Window() = default;
    virtual void loadUi(LiftCpu* cpu);
    virtual void clone(LiftCpu* cpu);
    virtual void handleMessage(LiftCpu* cpu);
    virtual void setPosition(LiftCpu* cpu);
    virtual void draw(LiftCpu* cpu);
    virtual void handleInput(LiftCpu* cpu);
    virtual void setOpacity(LiftCpu* cpu);
    virtual void hitTest(LiftCpu* cpu);
    virtual void dispatchMessage(LiftCpu* cpu);
    virtual void setFont(LiftCpu* cpu);
    virtual void getFont(LiftCpu* cpu);
    virtual void destroy(LiftCpu* cpu);
};



class ButtonCtrl : public Window {
public:
    ButtonCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class CheckBox : public Window {
public:
    CheckBox() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    virtual void playClickSound(LiftCpu* cpu);
};

class CDescriptionWindow : public Window {
public:
    CDescriptionWindow() = default;
    void draw(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class EditCtrl : public Window {
public:
    EditCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class ListCtrl : public Window {
public:
    ListCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class FilterListCtrl : public ListCtrl {
public:
    FilterListCtrl() = default;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class FontPicker : public Window {
public:
    FontPicker() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void setFont(LiftCpu* cpu) override;
    void getFont(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class HyperTextChatListControl : public Window {
public:
    HyperTextChatListControl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void setFont(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class HyperTextCtrl : public Window {
public:
    HyperTextCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class HyperTextEditControl : public Window {
public:
    HyperTextEditControl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class ImageCtrl : public Window {
public:
    ImageCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void setOpacity(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class ListItemCtrl : public Window {
public:
    ListItemCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void setOpacity(LiftCpu* cpu) override;
    void hitTest(LiftCpu* cpu) override;
    void dispatchMessage(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class CMenuListControl : public Window {
public:
    CMenuListControl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class ToolTipCtrl : public Window {
public:
    ToolTipCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class MiniHelpCtrl : public ToolTipCtrl {
public:
    MiniHelpCtrl() = default;
    void clone(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
};

class CMinimapControl : public Window {
public:
    CMinimapControl() = default;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class ProgressBar : public Window {
public:
    ProgressBar() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
};

class RadioButtonCtrl : public CheckBox {
public:
    RadioButtonCtrl() = default;
    void clone(LiftCpu* cpu) override;
    void playClickSound(LiftCpu* cpu) override;
};

class RichEditCtrl : public Window {
public:
    RichEditCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class ScrollBar : public Window {
public:
    ScrollBar() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
    virtual void updateControlState(LiftCpu* cpu);
    virtual void loadControlParameters(LiftCpu* cpu);
};

class SliderCtrl : public ScrollBar {
public:
    SliderCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void updateControlState(LiftCpu* cpu) override;
    void loadControlParameters(LiftCpu* cpu) override;
};

class SlotCtrl : public Window {
public:
    SlotCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void hitTest(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class SpinButton : public Window {
public:
    SpinButton() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
    virtual void updateStatus(LiftCpu* cpu);
};

class TextCtrl : public Window {
public:
    TextCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
};

class CWebBrowserControl : public Window {
public:
    CWebBrowserControl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

}
