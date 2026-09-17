#pragma once

#include "semantic_classes.h"
#include <windows.h>
#include <bit>
#include <cstddef>
#include <cstdint>

namespace SphereUI { struct SavedWindowPosition; struct LocalizedTextEntry; struct DisplayMode; }
struct SferaScreenVertex;
struct IDirect3DBaseTexture9;
struct IDirect3D9;
struct IDirect3DDevice9;
struct IDirect3DBaseTexture9;
namespace SphereUI { struct UiSprite; }

namespace {

const std::size_t kDynamicIndexScratchCount = 3000;
const std::size_t kErrorMessageCapacity = 1004;
const std::size_t kFontLookupClassCount = 5;
const std::size_t kFontLookupGlyphCount = 256;
const std::size_t kLandscapeMapRecordCount = 6400;

const std::size_t kProfileSlotCount = 100;
const std::size_t kRenderBlendLutStorageSize = 64 * 64 * 4 + 1;
const std::size_t kRenderQuantizationTableSize = 3072;
const std::size_t kRenderSampleCount = 120;
const std::size_t kTextureCacheEntryCount = 50;
}

const char* sfera_cursor_texture_name(uint32_t slot);

struct SferaItemArray {
    void** block_vector_begin;
    void** block_vector_end;
    void** block_vector_capacity_end;
    std::size_t free_capacity;
    void** free_items;
    std::size_t free_count;
    std::size_t growth_count;

    bool grow(std::size_t item_size);
    void* take();
    void put(void* item);
    void clear();
};

struct SferaNetworkSendRuntime { CRITICAL_SECTION critical_section; };
struct SferaInterpreterScratchRuntime {
    uint32_t diagnostic_step_counter;
    uint32_t network_poll_counter;
    CItemListCommonItem* item_lookup_result;
};

struct WorldObject;

struct SferaLightRecord {
    SferaEffectVec3F position;
    float color[4];
    float radius;
    SferaEffectVec3F bounds_min;
    SferaEffectVec3F bounds_max;
    float viewer_distance_squared;

    void update(const SferaEffectVec3F& new_position, const float* new_color, float new_radius);
};

struct SferaLightRuntime {
    SferaBoundCheckArray<SferaLightRecord*> handles;
    SferaBoundCheckArray<SferaLightRecord*> visible_handles;
    std::array<bool, 31> active_lights{};
    std::array<std::uint32_t, 30> render_candidate_indices{};
    std::array<bool, 30> render_candidate_active{};
    std::size_t active_count = 0;
    std::size_t candidate_count = 0;

    SferaLightRecord* record(std::int32_t handle) const;
    void setActive(std::uint32_t index, bool enabled, std::uint32_t sourceLine);
    void activateMask(std::uint32_t mask);
    void setDirectionalLight(const SferaVec3F& direction, const SferaVec3F& color);
    void invalidateActiveLights();
    void disableActiveLights();
    std::int32_t create(const SferaEffectVec3F& position, const float* color, float radius);
    void write(std::int32_t handle, const SferaEffectVec3F& position, const float* color, float radius);
    void release(std::int32_t handle);
};

struct SferaLandscapeRuntime {
    SferaBoundCheckArray<TerrainRegion> file_records;
};
struct SferaCollisionRuntime {
    SferaBoundCheckArray<float> candidate_handles;
    SferaBoundCheckArray<std::uint32_t> near_result_handles;

};
struct SferaSceneArrayRuntime {

    SferaBoundCheckArray<float> render_pass_slots;
    SferaBoundCheckArray<SferaVec3F> clip_vectors;
    SferaBoundCheckArray<SferaVec3F> scene_points;
    SferaBoundCheckArray<SphereRender::SceneSortEntry> object_positions;
    SferaBoundCheckArray<SferaMatrix4x4F> model_matrices;

    SferaBoundCheckArray<const TerrainCell*> object_sort_keys;
    SferaBoundCheckArray<float> object_draw_indices;
    SferaBoundCheckArray<std::uint32_t*> object_visibility_indices;
    SferaBoundCheckArray<SferaVec3F> clip_points;
    SferaBoundCheckArray<SferaMatrix4x4F> character_matrices;
    SferaBoundCheckArray<TerrainPatch*> object_sort_indices;
    SferaBoundCheckArray<std::uint32_t> clip_indices;
};
struct SferaSceneBuildRuntime {
    std::size_t object_count;
    uint16_t landscape_debug_pixels[256 * 256];
};

struct SferaModelMaterialLookupRuntime {
    std::uint64_t refresh_tick;
};
struct SferaIntrusiveListHeader {
    SferaActiveEffect* first;
    SferaActiveEffect* last;
};

void sfera_effect_list_append(SferaIntrusiveListHeader& list, SferaActiveEffect& item);
void sfera_effect_list_remove(SferaIntrusiveListHeader& list, SferaActiveEffect& item);
struct SferaNatureManager {
    NatureRainListener rain_listener;
    LightingListener lighting_listener;
    IEffect* rain_effect;
    float rain_intensity;
    float rain_scale;
    IEffect* lighting_effect;
    float lighting_level;
    SferaActiveEffect* rain_effect_handle;
    SferaActiveEffect* lighting_effect_handle;
    SferaActiveEffect* ambient_rain_handles[3];

    static void updateRain();
    static void updateLightning();
    void initialize();
    void shutdown();
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

struct SferaNatureRuntime { SferaNatureManager* manager; };
SferaNatureManager* sfera_nature_manager();
void sfera_initialize_nature_manager();
void sfera_shutdown_nature_manager();

struct SferaControlOptionsRuntime {
    uint32_t active_slot;
    uint32_t configured_bindings[64];
    uint32_t working_bindings[64];
};
struct SferaSpriteRuntime {
    uint32_t render_mode;

};

struct SferaFrameRuntime {
    float fps;
    uint32_t fps_sample_count;
    std::uint64_t fps_anchor;
    uint32_t frame_sample_count;
    std::uint64_t frame_anchor;
    std::uint64_t frame_state_anchor;
    uint32_t frame_state;
    bool rain_enabled;
    bool lightning_enabled;
    GrassMapMngr color_lookup_object;
    uint32_t color_lookup_flags;
    uint32_t warning_header_written;
};
struct SferaHighResolutionClockRuntime {
    std::uint64_t elapsed_counter;
    std::uint64_t epoch_microseconds;
    std::uint64_t performance_frequency;
    uint32_t frequency_shift;
    bool initialized;
    std::uint64_t counter_anchor;
};
struct SferaProfilerRuntime {
    void writeReport();
    void updateFramePercentages();
    void begin(std::size_t index);
    void end(std::size_t index);
    std::uint64_t accumulated_ticks[kProfileSlotCount];
    bool active[kProfileSlotCount];
    std::size_t frame_count;
    std::uint64_t start_time_us[kProfileSlotCount];
    std::size_t call_count[kProfileSlotCount];
    uint32_t frame_time_total;
    std::uint64_t report_clock_snapshot;
    uint32_t report_percent[10];
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
    uint32_t draw_selection_state;
    uint32_t render_channel_mask;
    uint32_t object_reference_count;
    uint32_t command_state;
    bool escape_without_query;
    uint32_t window_count;

    uint32_t near_collision_count;
};

struct SferaMainInputStateRuntime {
    uint32_t input_state;

    SferaDebugExchange* debug_exchange;
    float motion_accumulator;
    uint32_t input_state_02;

    bool input_enabled;
    float camera_step;

    SferaMouseInputState mouse;
    float motion_x;
    float motion_y;
    bool main_loop_started;
    uint32_t active_input_handle;

    SphereWorld::GrassCell* landscape_texture_base;
    uint8_t landscape_texture_lut[256][2];
    uint32_t landscape_state;
};

struct SferaMainViewStateRuntime {
    float projection_samples[125];
    std::size_t projection_sample_count;

    float view_coefficients[6];

    uint32_t view_mode;
    uint32_t view_accumulator;
    float projection_scale;
};

struct SferaMainUiStateRuntime {
    uint32_t ui_state;
    char gamexp_sid[32];
    uint32_t ui_state_02;
    SphereWorld::GrassCell* ui_state_03;
    uint32_t ui_state_04;

    float scene_factor;
    float scene_scale;
    uint32_t ui_state_05;
    HINSTANCE active_ui_object;
    SferaFrustumF clip_frustum;

    uint32_t ui_state_07;
    uint32_t ui_state_08;

    bool effectVisible(const IEffect& effect, const SferaEffectVec3F& position) const;
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
    std::array<std::uint32_t, 8> render_options;
    bool debug_config_enabled;

    bool resources_loaded;
    bool high_resolution_assets;
    bool alternate_ph_assets;
    bool alternate_rd_assets;
    uint32_t refresh_rate;

    bool gamexp_sid_present;

    SferaTcpConnectionContext* tcp_connection;

    bool auto_fog;
    bool effects_enabled;
    uint32_t state_27;

    uint32_t state_28;

};

struct SferaClientMainScalarRuntime {
    uint32_t counter_01;
    uint32_t state_01;
    std::uint16_t* state_02;
    uint32_t state_03;
    uint32_t state_04;

    uint32_t mode_01;
    uint32_t mode_02;

    std::size_t primary_animation_frame;
    uint32_t state_07;

    uint32_t state_27;
    uint32_t state_28;

    uint32_t counter_04;
};
struct SferaInterScalarRuntime {
    uint32_t state_01;
    uint32_t state_02;
    QuickFile* quick_files;
    uint32_t mode_01;

    WorldObject* current_object;
    uint32_t state_04;
    SferaUpdateDownloadContext* update_download;
    SferaCheckFilesContext* file_checker;
    uint32_t state_06;
    uint32_t state_07;
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
    SferaBoundCheckArray<GameUiWindow*> windows;
    SferaBoundCheckArray<WorldGuiControl*> window_handle_table;
};
using SferaStdAllocator = StdAllocator;
namespace SphereUI::Memory { struct AllocationHeader; struct AllocationRecord; struct AllocationSource; }

struct SferaSceneVectorRuntime {
    SferaVec3F render_scale;
    SferaVec3F transform_scratch;
    SferaVec3F frame_102_position;
    SferaVec3F frame_101_position;
    SferaVec3F object_position_delta;
};
struct SferaSpatialBoundsRuntime {
    SferaVec3F minimum;
    SferaVec3F maximum;
};
struct SferaViewSpatialRuntime {
    SferaVec3F basis[4];
    uint8_t alternate_projection;

    SferaVec3F position_offset;
    SferaVec3F scale;
    SferaVec3F world_anchor;
    SferaVec3F view_axis;
};
struct SferaLandscapeInterpolationRuntime {
    std::size_t subdivision_count;

};
struct SferaD3D9SemanticStateRuntime {
    SferaMatrix4x4F view_matrix;
    SferaMatrix4x4F projection_matrix;
};
struct SferaSkyInterpolationRuntime {
    SferaVec4F primary_samples[10];
    float primary_key_positions[10];
    SferaVec4F primary_reference;
    SferaVec4F secondary_samples[6];
    float secondary_key_positions[6];
};
struct SferaColorExpansionRuntime {
    uint32_t five_bit_to_eight_bit[32];
    bool initialized;
};

struct SferaCriticalDiagnosticsRuntime {
    char allocation_context[128];

    uint32_t serial_number;

    SferaDiagnosticLogObjectRuntime* log_chain_head;
};
struct SferaScreenVertex {
    float x;
    float y;
    float z;
    float rhw;
    uint32_t diffuse;
    uint32_t specular;
    float u;
    float v;
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
    uint32_t pending_graphics_value;
    uint32_t comparison_graphics_value;
    bool widget_keys_initialized;
    uint32_t reflection_quality;
    SphereUI::UiIndexVector saved_chat_fonts;
    SphereUI::UiIndexVector edited_chat_fonts;
};
struct SferaWindowRuntime {

    uint32_t render_state_word;

    uint32_t clip_vector_count;
    float distance_scratch;
    CRITICAL_SECTION timing_critical_section;
    PathZones* path_zones = nullptr;

    uint32_t input_state;
    uint32_t active_window_index;
    bool windowed;
    HWND main_window_handle;

    std::array<std::uint32_t, 2>* landscape_grid_records;
    std::size_t landscape_grid_count;
    bool runtime_debug_enabled;

    char diagnostic_message[2048];

};
struct SferaInputDeviceRuntime {
    uint32_t process_value;
    uint32_t input_generation;

    float minimum_lod_distance;
    float lod_distance;

    float frame_interval;
    bool exception_requested;
    SphereUI::ChatFilter* chat_filter;
};
struct SferaScreenClipRuntime {
    int left;
    int top;
    int right;
    int bottom;
};
struct SferaWorldRenderRuntime {
    SphereRender::Model* active_model;
    SphereWorld::DynamicVegetation* world_spatial_index;
    bool feature_toggle;
    bool scene_active;
};
struct SferaWorldLoadRuntime {
    bool render_shadows;
    uint32_t active_tool_context;
    std::size_t live_object_count;

    uint32_t loading_work_total;
    std::unique_ptr<SnowField> snow_path_object;
};
using SferaWorldBoundsRuntime = SferaSpatialBoundsRuntime;
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
    std::size_t grid_buffer_bytes;
    float view_offset_x;
    float view_offset_y;
    uint32_t rotation_step;

};
struct SferaProcessRuntime {
    char executable_path[64];

};
struct SferaClientProcessRuntime {
    uint32_t ui_bridge;
    bool startup_complete;
    char locale[10];
    Contours* client_object;
    char log_message[912];
};
struct SferaMainRenderRuntime {
    std::size_t world_object_count;
    uint32_t secondary_render_pass;
    uint32_t grass_depth_mode;
};
struct SferaMicrotextureRecord {
    uint16_t lookup_key;

    uint32_t name;
    TerrainTextureImage* resource;
};
struct SferaSceneControlRuntime {

    uint32_t timing_anchor;
    float camera_x;
    float camera_y;
    float environment_parameter;
    uint32_t active_context;
    std::size_t context_count;
    uint32_t context_queue[30];
    std::size_t microtexture_count;
    SferaMicrotextureRecord microtextures[100];
};
struct SferaMainAuxRuntime {
    SkyEnvironment* secondary_world_manager;
    uint32_t color_component;

};
struct SferaLandscapeMapRecord {
    char material_name[20];
    uint8_t tile_x;
    uint8_t tile_y;
};
struct SferaLandscapeMapRuntime {

    bool show_fps;
    SferaLandscapeMapRecord records[kLandscapeMapRecordCount];
};
struct SferaSkyRuntime {
    float horizon_scale;
    uint16_t indices[594];
};
struct SferaTextureCacheEntry {
    const TerrainCell* owner;
    uint8_t kind;

    IDirect3DTexture9* resource;
    uint32_t use_count;
};
struct SferaTextureCacheRuntime {

    uint32_t upload_serial;

    uint32_t render_gate;

    bool cache_enabled;
    SferaTextureCacheEntry entries[kTextureCacheEntryCount];
};
struct SferaErrorMessageScratchRuntime {
    char fatal_message[kErrorMessageCapacity];

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
    std::size_t visible_count;
    std::size_t active_count;
    float parameter;
    SferaVec3F primary_vector;
    SferaVec3F secondary_vector;
    TerrainRegion* patch_records[6400];
};
struct SferaDebugWindowRuntime {
    HWND spider_window;
};
struct SferaViewMotionRuntime {
    float motion_terms[5];
    SferaVec3F reference_point;
    SferaVec3F projected_a;
    SferaVec3F projected_b;
    uint32_t update_serial;
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
struct SferaSpatialIndexRuntime {
    std::map<std::pair<std::int32_t, std::int32_t>, SphereWorld::SpatialLeaf> quadtree_cells;

};
struct SferaStartupCommandLineRuntime {
    char text[352];
    uint32_t show_command;
};
struct SferaCollisionScratchRuntime {
    SferaLightRecord light_candidates[30];

};
struct SferaMbcStaticRuntime {
    uint32_t profile_fallback;
    uint32_t stack_default_values[256];
    std::uint64_t startup_time;
    uint32_t init_marker;
    uint8_t init_flag;
    uint8_t service_flag;

};
struct SferaAlphaMaterialRuntime {
    int32_t selected_slot;
    uint8_t option_a;
    uint8_t option_b;
    uint8_t option_c;

    float alpha[4];
};

struct SferaRecoveredStaticRuntime {
    uint32_t simulation_tick;
    bool vertical_sync_enabled;
    uint32_t memory_warning_as_error;
    uint32_t mbc_stack_table_cursor;
    uint32_t server_number;
    uint32_t loadcount_guard;
    SferaVec3F mbc_vector_scratch;
    SferaDebugScriptArrays debug_script_arrays;
    float inverse_40;

    uint32_t view_transition_counter;
    uint32_t view_direction_state;
    uint32_t scene_mode;

    CRITICAL_SECTION scene_lock;

    float cursor_accumulator;
    uint32_t input_state_b;
    uint32_t render_gate;
    uint32_t text_size_height;

    uint32_t client_state_02;
    uint32_t client_state_03;
    float ui_cell_width;
    float clip_depth;

    uint32_t client_state_05;

    uint32_t graphics_state;
    uint32_t font_renderer_state;

    SphereRender::CharacterModels* render_state_08;
    uint32_t render_state_09;

    uint32_t scene_state_07;
    EnvironmentZones* scene_state_08;
    uint32_t scene_state_09;
    bool interaction_enabled;
    uint32_t interaction_input_flags;
    float animation_phase;
    uint32_t animation_result_b;

    SferaVec3F flare_clip_vector;

};
struct SferaPendingKeyRuntime {
    uint32_t count;
    uint32_t key_codes[30];
};
struct SferaRelaunchRuntime {
    char argument[132];
};

struct SferaEffectManager {
    bool deferred_lifecycle;
    uint32_t render_cycle;
    std::size_t active_resource_count;
    uint32_t detail_setting;
    bool effects_enabled;
    std::size_t render_slot_count;
    std::uint16_t* particle_random_table;
    SferaEffectMeshResource* particle_resource_head;
    IEffect* effect_definition_head;
    bool initialized;
    std::vector<std::size_t> render_order;
    std::size_t active_effect_count;
    SferaIntrusiveListHeader active_effects;
    uint32_t generation;
    uint32_t last_processed_generation;
    enum class FlareTransition { Idle, FadeOut, FadeIn };
    FlareTransition flare_transition;
    bool flare_enabled;
    int flare_alpha;
    SferaVec3F viewer_position;
    SferaBoundCheckArray<SferaEffectRenderSlot> render_slots;
    std::array<SferaEffectListenerEntry, 16> effect_listeners{};
    std::size_t listener_count = 0;

    void* allocate(std::size_t size) const;
    void free(void* pointer) const;
    void reportError(const char* message) const;
    SferaEffectRenderSlot* acquireRenderSlot();
    void finalizeBillboard(SferaEffectRenderSlot& slot, const SferaEffectVec3F& position, float size) const;
    float viewerDistance(const SferaEffectVec3F& position) const;
    float viewerDistance(std::uint32_t source_handle) const;
    void appendDefinition(IEffect* effect);
    IEffect* findDefinition(uint32_t effect_id) const;
    IEffect* findDefinition(const char* script_name) const;
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
    void removeActiveEffect(SferaActiveEffect* handle);
    bool initialize();
    void shutdown();
    SferaActiveEffect* createActiveEffect(std::uint32_t effect_id, std::uint32_t source_handle);
    SferaActiveEffect* createActiveEffect(const char* script_name, std::uint32_t source_handle);
    void removeActiveEffect(SferaActiveEffect& item);
    bool setEffectParameters(std::uint32_t source_handle, const SferaEffectParameter* parameters, std::size_t count);
    void updateActiveEffects();
    void updateActiveEffect(SferaActiveEffect& item, std::uint16_t state_flags, float viewer_distance);
};

inline SferaItemArray g_sfera_effect_items{.growth_count = 6000u};
inline SferaItemArray g_sfera_sound_effect_items{.growth_count = 128u};
inline SferaServerWall g_sfera_server_wall{.texture_id = -1};
inline SferaNetworkRuntime g_sfera_network_runtime{.initialization_result = UINT32_MAX, .server_port = 25858u, .connection_slot = UINT32_MAX, .pending_effect = nullptr, .active_slot = UINT32_MAX, .shutdown_state = UINT32_MAX};
inline SferaNetworkSendRuntime g_sfera_network_send_runtime;
inline SkyEnvironment* g_sfera_primary_sky_environment;

inline SferaSliceReference32 g_sfera_pop_slice_fallback;
inline SferaSliceReference32 g_sfera_pop_sliceup_fallback;
inline SferaInterpreterScratchRuntime g_sfera_interpreter_scratch_runtime;
inline SferaGraphicsRuntime g_sfera_graphics_runtime{.fog_distance = 100.0f, .saved_fog_distance = 50.0f, .lods_enabled = 1u, .hardware_cursor_enabled = 1u, .environment_factor = 0.8500000238418579f, .render_mode_enabled = 1u, .base_microtexture_id = UINT32_MAX, .view_parameter = 0.6460000276565552f, .view_scale = 1.0f, .post_effects_enabled = 1u, .rebuild_percent = UINT32_MAX, .runtime_counter = 2000u};
inline SferaSceneRenderRuntime g_sfera_scene_render_runtime;
inline SferaMatrix4x4F g_sfera_model_coordinate_matrix;
inline SferaMatrix4x4F g_sfera_character_frame_matrix;
inline SferaMatrix4x4F g_sfera_character_rotation_matrix;
inline SferaScreenVertex g_sfera_sky_screen_vertices[120];
inline SferaScreenVertex g_sfera_landscape_screen_vertices[1200];
inline SferaBoundCheckArray<std::uint32_t> g_sfera_character_index_map;
inline SferaGraphicsOptionsRuntime g_sfera_graphics_options_runtime;
inline SferaSphereOptionsRuntime g_sfera_sphere_options_runtime;
inline SferaOptionsDialogRuntime g_sfera_options_dialog_runtime;
inline SferaWindowRuntime g_sfera_window_runtime;
inline SferaInputDeviceRuntime g_sfera_input_device_runtime;
inline SferaScreenClipRuntime g_sfera_screen_clip_runtime;
inline SferaWorldRenderRuntime g_sfera_world_render_runtime;
inline SferaWorldLoadRuntime g_sfera_world_load_runtime;
inline SferaWorldBoundsRuntime g_sfera_world_bounds_runtime;
inline SferaRenderLookupRuntime g_sfera_render_lookup_runtime;
inline SferaLandscapeRenderRuntime g_sfera_landscape_render_runtime;
inline SferaProcessRuntime g_sfera_process_runtime;
inline SferaClientProcessRuntime g_sfera_client_process_runtime;
inline SferaMainRenderRuntime g_sfera_main_render_runtime;
inline SferaSceneControlRuntime g_sfera_scene_control_runtime;
inline SferaMainAuxRuntime g_sfera_main_aux_runtime;
inline SferaLandscapeMapRuntime g_sfera_landscape_map_runtime;
inline SferaSkyRuntime g_sfera_sky_runtime;
inline SferaTextureCacheRuntime g_sfera_texture_cache_runtime;
inline SferaErrorMessageScratchRuntime g_sfera_error_message_scratch_runtime;
inline SferaGrassMapRuntime g_sfera_grass_map_runtime;
inline SferaPhysicsRuntime g_sfera_physics_runtime;
inline SferaViewGeometryRuntime g_sfera_view_geometry_runtime;
inline SferaViewProjectionScratchRuntime g_sfera_view_projection_scratch_runtime;
inline SferaMatrix4x4F g_sfera_model_transform_scratch_matrix;
inline SferaSkyInterpolationRuntime g_sfera_sky_interpolation_runtime;
inline SferaColorExpansionRuntime g_sfera_color_expansion_runtime;
inline SferaCriticalDiagnosticsRuntime g_sfera_critical_diagnostics_runtime;
inline SferaLandscapePatchLookupRuntime g_sfera_landscape_patch_lookup_runtime;
inline SferaDebugWindowRuntime g_sfera_debug_window_runtime;
inline SferaViewMotionRuntime g_sfera_view_motion_runtime;
inline SferaRenderSampleRuntime g_sfera_render_sample_runtime;
inline SferaSceneVectorRuntime g_sfera_scene_vector_runtime;
inline SferaVec3F g_sfera_flare_projection;
inline SferaWorldSlotTableRuntime g_sfera_world_slot_table_runtime;
inline SferaConfigTextRuntime g_sfera_config_text_runtime;
inline SferaStaticRenderLookupRuntime g_sfera_static_render_lookup_runtime;
inline SferaMbcStaticRuntime g_sfera_mbc_static_runtime;
inline SferaMapGeneratorRuntime g_sfera_map_generator_runtime;
inline SferaAlphaMaterialRuntime g_sfera_alpha_material_runtime;

inline SferaSpatialIndexRuntime g_sfera_spatial_index_runtime;
inline SferaStartupCommandLineRuntime g_sfera_startup_command_line_runtime;
inline SferaCollisionScratchRuntime g_sfera_collision_scratch_runtime;
inline SferaRecoveredStaticRuntime g_sfera_recovered_static_runtime;
inline SferaPendingKeyRuntime g_sfera_pending_key_runtime;
inline SferaRelaunchRuntime g_sfera_relaunch_runtime;
inline EnvironmentZones* g_sfera_alternate_environment_zones;
inline SferaViewSpatialRuntime g_sfera_view_spatial_runtime;
inline SferaSpatialBoundsRuntime g_sfera_spatial_bounds_runtime;
inline WorldObjects g_sfera_world_objects{.max_occupied_object_handle = UINT32_MAX, .controlled_object_handle = UINT32_MAX, .contour_mode = UINT32_MAX};
inline SferaLightRuntime g_sfera_light_runtime;
inline SferaLandscapeRuntime g_sfera_landscape_runtime;
inline SferaLandscapeInterpolationRuntime g_sfera_landscape_interpolation_runtime;
inline SferaCollisionRuntime g_sfera_collision_runtime;
inline SferaSceneArrayRuntime g_sfera_scene_array_runtime;
inline SferaSceneBuildRuntime g_sfera_scene_build_runtime;
inline SferaWeatherRuntime g_sfera_weather_runtime;
inline SferaModelMaterialLookupRuntime g_sfera_model_material_lookup_runtime;
inline SferaNatureRuntime g_sfera_nature_runtime;
inline SferaWarningLogRuntime g_sfera_warning_log_runtime;
inline SferaControlOptionsRuntime g_sfera_control_options{.active_slot = UINT32_MAX};
inline SferaSpriteRuntime g_sfera_sprite_runtime{.render_mode = UINT32_MAX};
inline SferaExecutionMonitorRuntime g_sfera_execution_monitor_runtime;
inline SferaErrorLogRuntime g_sfera_error_log_runtime;
inline SferaLogRuntime g_sfera_log_runtime;
inline SferaFrameRuntime g_sfera_frame_runtime;
inline SferaHighResolutionClockRuntime g_sfera_high_resolution_clock_runtime;
inline SferaProfilerRuntime g_sfera_profiler_runtime;
inline SferaCrc32Runtime g_sfera_crc32_runtime;
inline SferaStringLookupRuntime g_sfera_string_lookup_runtime;
inline SferaAsciiLowerRuntime g_sfera_ascii_lower_runtime;
inline SferaNetworkProbeRuntime g_sfera_network_probe_runtime;
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
inline SferaStdAllocator g_sfera_std_allocator;
inline SferaMemoryRuntime g_sfera_memory_runtime{.allocation_source_name = "Unknown", .tracker_primary = std::numeric_limits<std::size_t>::max(), .tracker_floor = std::numeric_limits<std::size_t>::max(), .tracker_ceiling = std::numeric_limits<std::size_t>::max()};
inline SferaMemorySourceHashRuntime g_sfera_memory_source_hash_runtime;
inline SferaAllocationHashRuntime g_sfera_allocation_hash_runtime;
inline SferaDiagnosticLogObjectRuntime g_sfera_log_memory_object;
inline SferaDiagnosticLogObjectRuntime g_sfera_log_warnings_object;
inline SferaDiagnosticLogObjectRuntime g_sfera_log_errors_object;
inline SferaD3D9SemanticStateRuntime g_sfera_d3d9_semantic_state;
inline SferaCrtStartupRuntime g_sfera_crt_startup_runtime;
inline SferaCrashReportRuntime g_sfera_crash_report_runtime;
inline SferaBloodEffectRuntime* g_sfera_blood_effect_instance;
inline SferaFileRuntime g_sfera_file_runtime;
inline SferaEffectManager g_sfera_effect_manager{.deferred_lifecycle = 1u, .render_cycle = 31u, .last_processed_generation = UINT32_MAX};
inline SferaMbcRuntime g_sfera_mbc_runtime_storage;
inline SferaMbcRuntime* g_sfera_mbc_runtime = &g_sfera_mbc_runtime_storage;
inline SferaMbcInterpreterStorage g_sfera_mbc_interpreter_storage;
inline SferaMbcModuleMemoryStats g_sfera_mbc_module_memory_stats[4000];
