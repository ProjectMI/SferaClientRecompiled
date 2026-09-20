#pragma once

#include "semantic_classes.h"
#include <windows.h>
#include <bit>
#include <cstddef>
#include <cstdint>

namespace SphereUI { struct SavedWindowPosition; struct LocalizedTextEntry; struct DisplayMode; }
struct IDirect3D9;
struct IDirect3DDevice9;
namespace SphereUI { struct UiSprite; }

namespace {

const std::size_t kFontLookupGlyphCount = 256;

const std::size_t kRenderBlendLutStorageSize = 64 * 64 * 4 + 1;
const std::size_t kRenderQuantizationTableSize = 3072;
const std::size_t kRenderSampleCount = 120;
const std::size_t kTextureCacheEntryCount = 50;
}

const char* sfera_cursor_texture_name(uint32_t slot);



struct SferaNetworkSendRuntime { CRITICAL_SECTION critical_section; };
struct SferaInterpreterScratchRuntime {
    uint32_t network_poll_counter;
};

struct WorldObject;

struct SferaLightRecord {
    SferaVec3F position;
    float color[4];
    float radius;
    SferaVec3F bounds_min;
    SferaVec3F bounds_max;
    float viewer_distance_squared;

    void update(const SferaVec3F& new_position, const float* new_color, float new_radius);
};

struct SferaLightRuntime {
    std::vector<std::unique_ptr<SferaLightRecord>> handles;
    std::vector<SferaLightRecord*> visible_handles;
    std::array<bool, 31> active_lights{};
    std::array<std::uint32_t, 30> render_candidate_indices{};
    std::array<bool, 30> render_candidate_active{};
    std::size_t active_count = 0;
    std::size_t candidate_count = 0;

    SferaLightRecord* record(int handle) const;
    void setActive(std::uint32_t index, bool enabled, std::uint32_t sourceLine);
    void activateMask(std::uint32_t mask);
    void setDirectionalLight(const SferaVec3F& direction, const SferaVec3F& color);
    void invalidateActiveLights();
    void disableActiveLights();
    int create(const SferaVec3F& position, const float* color, float radius);
    void write(int handle, const SferaVec3F& position, const float* color, float radius);
    void release(int handle);
};



struct SferaModelMaterialLookupRuntime {
    std::uint64_t refresh_tick;
};


struct SferaNatureManager {
    NatureRainListener rain_listener;
    LightingListener lighting_listener;
    CRainEffect* rain_effect = nullptr;
    float rain_intensity = 0.5f;
    float rain_scale = 0.0f;
    CScriptedEffect* lighting_effect = nullptr;
    float lighting_level = 0.5f;
    SferaActiveEffect* rain_effect_handle = nullptr;
    SferaActiveEffect* lighting_effect_handle = nullptr;
    std::array<SferaActiveEffect*, 3> ambient_rain_handles{};

    static void updateRain();
    static void updateLightning();
    bool initialize();
    void shutdown();
    void forgetEffect(const SferaActiveEffect& item);
    bool attachRainEffect(IEffect& effect);
    void detachRainEffect();
    bool attachLightingEffect(IEffect& effect);
    void detachLightingEffect();
    void onLightingEffectChanged(IEffect& effect, SferaActiveEffect& item);
    void startRain();
    void stopRain();
    void startLighting();
    void stopLighting();
    void setRainIntensity(float value);
    void setLightingLevel(float value);
    void updateAmbientRainEffects();
};

SferaNatureManager* sfera_nature_manager();

struct SferaControlOptionsRuntime {
    uint32_t active_slot;
    uint32_t configured_bindings[64];
    uint32_t working_bindings[64];
};
struct SferaSpriteRuntime {
    uint32_t render_mode;

};

struct SferaFrameRuntime {
    uint32_t frame_sample_count;
    std::uint64_t frame_anchor;
    bool rain_enabled;
    bool lightning_enabled;
    GrassMapMngr color_lookup_object;
    uint32_t color_lookup_flags;
};
struct SferaHighResolutionClockRuntime {
    std::uint64_t elapsed_counter;
    std::uint64_t epoch_microseconds;
    std::uint64_t performance_frequency;
    uint32_t frequency_shift;
    bool initialized;
    std::uint64_t counter_anchor;
};
struct SferaAsciiLowerRuntime {
    uint8_t table[256];
};

struct SferaMainCommandStateRuntime {

    bool lighting_enabled;

    uint32_t render_samples[120];
    float sky_blend_factor;
    uint32_t lighting_state;
    char default_cursor_name[8];
    uint32_t render_channel_mask;
    uint32_t command_state;

};

struct SferaMainInputStateRuntime {

    float motion_accumulator;
    uint32_t input_state_02;

    bool input_enabled;
    float camera_step;

    SferaMouseInputState mouse;
    float motion_x;
    float motion_y;
    bool main_loop_started;

};

struct SferaMainViewStateRuntime {
    float projection_samples[125];

    float view_coefficients[6];

    uint32_t view_accumulator;
    float projection_scale;
};

struct SferaMainUiStateRuntime {
    uint32_t ui_state_02;

    float scene_scale;
    HINSTANCE active_ui_object;
    SferaFrustumF clip_frustum;

    uint32_t ui_state_08;

    bool effectVisible(const IEffect& effect, const SferaVec3F& position) const;
};

struct SferaClientConfigRuntime {

    bool interpreter_initialized;
    uint8_t flag_02;
    uint8_t flag_03;
    uint32_t state_03;
    uint32_t language;
    bool volume_refresh_active;
    float volume_refresh_frames;
    uint32_t volume_refresh_direction;

    bool resources_loaded;
    bool high_resolution_assets;
    bool alternate_ph_assets;
    bool alternate_rd_assets;


    SferaTcpConnectionContext* tcp_connection;

    bool auto_fog;
    bool effects_enabled;
    uint32_t state_27;


};

struct SferaClientMainScalarRuntime {
    uint32_t state_01;

    uint32_t mode_01;

    std::size_t primary_animation_frame;

};
struct SferaInterScalarRuntime {
    QuickFile* quick_files;
    uint32_t mode_01;

    WorldObject* current_object;
};

struct SferaInterfaceRuntime {
    uint32_t cursor_kind;
    bool primary_gate;
    bool secondary_gate;
    bool cross_enabled;
    bool sounds_enabled;
    bool description_auto_popup;
    bool invite_messages;
    SphereUI::CDescriptionWindow* description_control;
    uint32_t previous_input_modifiers;
};

struct SferaSceneVectorRuntime {
    SferaVec3F render_scale;
    SferaVec3F transform_scratch;
    SferaVec3F frame_102_position;
    SferaVec3F frame_101_position;
};
struct SferaViewSpatialRuntime {
    SferaVec3F basis[4];
    uint8_t alternate_projection;

    SferaVec3F position_offset;
    SferaVec3F scale;
    SferaVec3F world_anchor;
};

struct SferaSceneRenderRuntime {
    SferaScreenVertex textured_quad[4];
    SferaScreenVertex interface_quad[4];
};
struct SferaGraphicsOptionsRuntime {
    uint32_t dialog_state;
    uint32_t graphics_page;
    uint32_t interface_values[9];
    uint32_t graphics_values[13];
    uint32_t saved_interface_values[9];
};
struct SferaSphereOptionsRuntime {
    bool saved_lods_enabled;
    float saved_lod_distance;
    float saved_fog_distance;
    uint32_t saved_music_volume;
    char option_labels[7][512];
};

struct SferaOptionsDialogRuntime {
    uint32_t graphics_snapshot[7];
    char graphics_unknown_label[28];
    uint32_t audio_settings;
    char widget_key_name[128];
    uint32_t comparison_graphics_value;
    bool widget_keys_initialized;
    uint32_t reflection_quality;
    std::vector<std::uint32_t> saved_chat_fonts;
    std::vector<std::uint32_t> edited_chat_fonts;
};
struct SferaWindowRuntime {

    float distance_scratch;
    CRITICAL_SECTION timing_critical_section;
    uint32_t active_window_index;
    bool windowed;
    HWND main_window_handle;

    char diagnostic_message[2048];

};
struct SferaInputDeviceRuntime {
    uint32_t process_value;

    float minimum_lod_distance;
    float lod_distance;

    float frame_interval;
    bool exception_requested;
    std::unique_ptr<SphereUI::ChatFilter> chat_filter;
};
struct SferaScreenClipRuntime {
    int left;
    int top;
    int right;
    int bottom;
};
struct SferaWorldRenderRuntime {
    SphereRender::Model* active_model;
    bool feature_toggle;
    bool scene_active;
};
struct SferaWorldLoadRuntime {
    uint32_t active_tool_context;

    uint32_t loading_work_total;
};
struct SferaRenderLookupEntry {
    uint32_t resource;
    uint32_t mask;
};
struct SferaRenderLookupRuntime {
    bool quit_requested;
    uint32_t alpha_component;
    SferaRenderLookupEntry entries[256];
};
struct SferaLandscapeRenderRuntime {
    float view_offset_x;
    float view_offset_y;
    uint32_t rotation_step;

};
struct SferaClientProcessRuntime {
    uint32_t ui_bridge;
    bool startup_complete;
    char locale[10];
    std::unique_ptr<Contours> client_object;
};
struct SferaMainRenderRuntime {
    uint32_t secondary_render_pass;
    uint32_t grass_depth_mode;
};
struct SferaSceneControlRuntime {

    uint32_t timing_anchor;
    float camera_x;
    float camera_y;
    float environment_parameter;
    uint32_t active_context;
    std::size_t context_count;
    uint32_t context_queue[30];
};
struct SferaMainAuxRuntime {
    std::unique_ptr<SkyEnvironment> secondary_world_manager;
    uint32_t color_component;

};
struct SferaSkyRuntime {
    float horizon_scale;
    uint16_t indices[594];
};
struct SferaTextureCacheEntry {
    const TerrainCell* owner = nullptr;
    uint8_t kind = 0;

    Microsoft::WRL::ComPtr<IDirect3DTexture9> resource;
    uint32_t use_count = 0;
};
struct SferaTextureCacheRuntime {

    uint32_t render_gate;

    bool cache_enabled;
    std::array<SferaTextureCacheEntry, kTextureCacheEntryCount> entries;
};
struct SferaGrassMapRuntime {
    uint32_t alternating_update_phase;
    GrassMapMngr manager;

    std::uint64_t last_frame_timestamp;
};
struct SferaPhysicsRuntime {

    float response_curve[100];
};
struct SferaViewGeometryRuntime {
    SferaVec3F reference_points[5];
    SferaIntBounds3 projected_bounds;
    SferaIntBounds3 clipping_bounds;
};

struct SferaLandscapePatchLookupRuntime {
    SferaVec3F primary_vector;
    SferaVec3F secondary_vector;
};
struct SferaViewMotionRuntime {
    float motion_terms[5];
    SferaVec3F reference_point;
    SferaVec3F projected_a;
    SferaVec3F projected_b;
    uint32_t mode_value;
    bool initialized;
};
struct SferaRenderSampleRuntime {
    float blend_weights[7];
    std::size_t secondary_animation_frame;

    float phase;
    float samples[kRenderSampleCount];
};

struct SferaWorldSlotTableRuntime {
    SferaWorldSlotRecord slots[401];
    std::size_t active_limit;
};

struct SferaStaticRenderLookupRuntime {
    float normalized_levels[7];
    float command_samples[kRenderSampleCount];
    float view_phase;

    uint32_t sample_flags[kRenderSampleCount];
    uint8_t glyph_presence[kFontLookupGlyphCount];
    uint8_t quantization_a[kRenderQuantizationTableSize];
    uint8_t quantization_b[kRenderQuantizationTableSize];
    float projection_scale;
    uint8_t blend_lut[kRenderBlendLutStorageSize];
    uint8_t color_remap_a[256];
    uint8_t color_remap_b[256];
    uint8_t color_remap_c[256];

};
struct SferaCollisionScratchRuntime {
    SferaLightRecord light_candidates[30];

};

struct SferaRecoveredStaticRuntime {
    uint32_t simulation_tick;
    uint32_t server_number;
    uint32_t loadcount_guard;
    float inverse_40;

    uint32_t view_transition_counter;

    CRITICAL_SECTION scene_lock;

    float cursor_accumulator;
    uint32_t render_gate;
    uint32_t text_size_height;


    uint32_t graphics_state;

    std::unique_ptr<SphereRender::CharacterModels> render_state_08;
    uint32_t render_state_09;

    uint32_t scene_state_07;
    std::unique_ptr<EnvironmentZones> scene_state_08;
    uint32_t scene_state_09;
    bool interaction_enabled;
    uint32_t interaction_input_flags;
    float animation_phase;

    SferaVec3F flare_clip_vector;

};
struct SferaPendingKeyRuntime {
    uint32_t count;
    uint32_t key_codes[30];
};
struct SferaEffectManager {
    uint32_t render_cycle{};
    bool effects_enabled{};
    std::size_t render_slot_count{};
    std::array<std::uint16_t, 65536> particle_random_table{};
    std::vector<std::shared_ptr<const SferaEffectMeshResource>> mesh_resources;
    std::vector<std::shared_ptr<IEffect>> definitions;
    bool initialized{};
    std::vector<std::size_t> render_order;
    std::list<std::shared_ptr<SferaActiveEffect>> active_effects;
    std::unique_ptr<SferaNatureManager> nature;
    std::unique_ptr<SferaBloodEffectRuntime> blood;
    bool shutting_down = false;
    bool updating = false;
    uint32_t generation{};
    uint32_t last_processed_generation{};
    enum class FlareTransition { Idle, FadeOut, FadeIn };
    FlareTransition flare_transition{};
    bool flare_enabled{};
    int flare_alpha{};
    SferaVec3F viewer_position{};
    std::vector<SferaEffectRenderSlot> render_slots;
    std::vector<SferaEffectListenerEntry> effect_listeners;

    void reportError(const char* message) const;
    SferaEffectRenderSlot* acquireRenderSlot();
    void finalizeBillboard(SferaEffectRenderSlot& slot, const SferaVec3F& position, float size) const;
    float viewerDistance(const SferaVec3F& position) const;
    float viewerDistance(std::uint32_t source_handle) const;
    void appendDefinition(std::shared_ptr<IEffect> effect);
    std::shared_ptr<IEffect> findDefinition(uint32_t effect_id) const;
    std::shared_ptr<IEffect> findDefinition(const char* script_name) const;
    int32_t findDefinitionId(const char* script_name) const;
    IEffectListener* findListener(uint32_t effect_id) const;
    bool registerListener(std::uint32_t effect_id, IEffectListener& listener);
    void unregisterListener(IEffectListener& listener);
    void clearListeners();
    void registerEffectMeshFile(const char* filename);
    void reportLoadProgress(std::uint32_t progress);
    void initializeBloodEffect();
    void shutdownBloodEffect();
    void loadDefinitions();
    void destroyDefinitions();
    void sortRenderSlots();
    void renderParticles();
    void drawFlare(int x, int y, int size, bool enabled);
    std::uint32_t listenerKey(const SferaActiveEffect* handle) const;
    bool removeActiveEffect(SferaActiveEffect* handle);
    bool initialize();
    void shutdown();
    SferaActiveEffect* createActiveEffect(std::uint32_t effect_id, std::uint32_t source_handle);
    SferaActiveEffect* createActiveEffect(const char* script_name, std::uint32_t source_handle);
    bool removeActiveEffect(SferaActiveEffect& item);
    bool setEffectParameters(std::uint32_t source_handle, std::span<const SferaEffectParameter> parameters);
    void retireEffect(SferaActiveEffect& item);
    void updateActiveEffects();
    void updateActiveEffect(SferaActiveEffect& item, std::uint16_t state_flags, float viewer_distance);
};

inline SferaServerWall g_sfera_server_wall{.texture_id = -1};
inline SferaNetworkRuntime g_sfera_network_runtime{.initialization_result = UINT32_MAX, .server_port = 25858u, .connection_slot = UINT32_MAX, .pending_effect = nullptr, .active_slot = UINT32_MAX};
inline SferaNetworkSendRuntime g_sfera_network_send_runtime;
inline std::unique_ptr<SkyEnvironment> g_sfera_primary_sky_environment;

inline SferaSliceReference32 g_sfera_pop_slice_fallback;
inline SferaSliceReference32 g_sfera_pop_sliceup_fallback;
inline SferaInterpreterScratchRuntime g_sfera_interpreter_scratch_runtime;
inline SferaGraphicsRuntime g_sfera_graphics_runtime{.fog_distance = 100.0f, .saved_fog_distance = 50.0f, .lods_enabled = 1u, .hardware_cursor_enabled = 1u, .environment_factor = 0.8500000238418579f, .base_microtexture_id = UINT32_MAX, .view_scale = 1.0f, .post_effects_enabled = 1u, .rebuild_percent = UINT32_MAX};
inline SferaSceneRenderRuntime g_sfera_scene_render_runtime;
inline SferaMatrix4x4F g_sfera_model_coordinate_matrix;
inline SferaMatrix4x4F g_sfera_character_frame_matrix;
inline SferaScreenVertex g_sfera_sky_screen_vertices[120];
inline SferaScreenVertex g_sfera_landscape_screen_vertices[1200];
inline SferaGraphicsOptionsRuntime g_sfera_graphics_options_runtime;
inline SferaSphereOptionsRuntime g_sfera_sphere_options_runtime;
inline SferaOptionsDialogRuntime g_sfera_options_dialog_runtime;
inline SferaWindowRuntime g_sfera_window_runtime;
inline SferaInputDeviceRuntime g_sfera_input_device_runtime;
inline SferaScreenClipRuntime g_sfera_screen_clip_runtime;
inline SferaWorldRenderRuntime g_sfera_world_render_runtime;
inline SferaWorldLoadRuntime g_sfera_world_load_runtime;
inline SphereWorld::Bounds g_sfera_world_bounds_runtime;
inline SferaRenderLookupRuntime g_sfera_render_lookup_runtime;
inline SferaLandscapeRenderRuntime g_sfera_landscape_render_runtime;
inline SferaClientProcessRuntime g_sfera_client_process_runtime;
inline SferaMainRenderRuntime g_sfera_main_render_runtime;
inline SferaSceneControlRuntime g_sfera_scene_control_runtime;
inline SferaMainAuxRuntime g_sfera_main_aux_runtime;
inline SferaSkyRuntime g_sfera_sky_runtime;
inline SferaTextureCacheRuntime g_sfera_texture_cache_runtime;
inline SferaGrassMapRuntime g_sfera_grass_map_runtime;
inline SferaPhysicsRuntime g_sfera_physics_runtime;
inline SferaViewGeometryRuntime g_sfera_view_geometry_runtime;
inline SferaMatrix4x4F g_sfera_model_transform_scratch_matrix;
inline SkyState g_sfera_sky_interpolation_runtime;
inline SferaLandscapePatchLookupRuntime g_sfera_landscape_patch_lookup_runtime;
inline SferaViewMotionRuntime g_sfera_view_motion_runtime;
inline SferaRenderSampleRuntime g_sfera_render_sample_runtime;
inline SferaSceneVectorRuntime g_sfera_scene_vector_runtime;
inline SferaVec3F g_sfera_flare_projection;
inline SferaWorldSlotTableRuntime g_sfera_world_slot_table_runtime;
inline SferaConfigTextRuntime g_sfera_config_text_runtime;
inline SferaStaticRenderLookupRuntime g_sfera_static_render_lookup_runtime;

inline SferaCollisionScratchRuntime g_sfera_collision_scratch_runtime;
inline SferaRecoveredStaticRuntime g_sfera_recovered_static_runtime;
inline SferaPendingKeyRuntime g_sfera_pending_key_runtime;
inline std::unique_ptr<EnvironmentZones> g_sfera_alternate_environment_zones;
inline SferaViewSpatialRuntime g_sfera_view_spatial_runtime;
inline SphereWorld::Bounds g_sfera_spatial_bounds_runtime;
inline WorldObjects g_sfera_world_objects{.max_occupied_object_handle = UINT32_MAX, .controlled_object_handle = UINT32_MAX};
inline SferaLightRuntime g_sfera_light_runtime;
inline SferaWeatherRuntime g_sfera_weather_runtime;
inline SferaModelMaterialLookupRuntime g_sfera_model_material_lookup_runtime;
inline SferaControlOptionsRuntime g_sfera_control_options{.active_slot = UINT32_MAX};
inline SferaSpriteRuntime g_sfera_sprite_runtime{.render_mode = UINT32_MAX};
inline SferaErrorLogRuntime g_sfera_error_log_runtime;
inline SferaLogRuntime g_sfera_log_runtime;
inline SferaFrameRuntime g_sfera_frame_runtime;
inline SferaHighResolutionClockRuntime g_sfera_high_resolution_clock_runtime;
inline SferaStringLookupRuntime g_sfera_string_lookup_runtime;
inline SferaAsciiLowerRuntime g_sfera_ascii_lower_runtime;
inline uint32_t g_sfera_graphics_display_depth_bits = 32u;
inline SferaMainCommandStateRuntime g_sfera_main_command_state_runtime;
inline SferaMainInputStateRuntime g_sfera_main_input_state_runtime;
inline SferaMainViewStateRuntime g_sfera_main_view_state_runtime;
inline SferaMainUiStateRuntime g_sfera_main_ui_state_runtime;
inline uint16_t g_sfera_screen_quad_indices[1800];
inline SferaClientConfigRuntime g_sfera_client_config_runtime;
inline SferaClientMainScalarRuntime g_sfera_client_main_scalar_runtime;
inline SferaInterScalarRuntime g_sfera_inter_scalar_runtime;
inline SferaInterfaceRuntime g_sfera_interface_runtime{.primary_gate = 1u, .secondary_gate = 1u, .cross_enabled = 1u, .sounds_enabled = 1u, .description_auto_popup = 1u, .invite_messages = 1u};
inline SferaCrtStartupRuntime g_sfera_crt_startup_runtime;
inline SferaEffectManager g_sfera_effect_manager{.render_cycle = 31u, .last_processed_generation = UINT32_MAX};
inline SferaMbcRuntime g_sfera_mbc_runtime;
inline SferaMbcInterpreterStorage g_sfera_mbc_interpreter_storage;

// UI owners must be destroyed while the VM registration tables are still alive.
inline SphereUI::InterfaceManager g_sfera_interface;
