#pragma once

#include "semantic_classes.h"
#include "lifted_abi.h"
#include <windows.h>
#include <bit>
#include <cstddef>
#include <cstdint>

inline uint32_t sfera_f32_bits(float value) { return std::bit_cast<uint32_t>(value); }

namespace SphereUI { struct SavedWindowPosition; struct LocalizedTextEntry; struct DisplayMode; }
struct SferaScreenVertex;
struct IDirect3DBaseTexture9;
struct SferaDirectPlayAddressNative;
struct IDirect3D9;
struct IDirect3DDevice9;
struct IDirect3DBaseTexture9;
namespace SphereUI { struct UiSprite; }
struct SferaDirectPlayClientNative;




namespace {

const uint32_t kDynamicIndexScratchCount = 3000;
const uint32_t kErrorMessageCapacity = 0x3EC;
const uint32_t kFontLookupClassCount = 5;
const uint32_t kFontLookupGlyphCount = 256;
const uint32_t kLandscapeMapRecordCount = 6400;
const uint32_t kNetworkProbeSampleCount = 20;
const uint32_t kProfileSlotCount = 100;
const uint32_t kRenderBlendLutStorageSize = 0x4001;
const uint32_t kRenderQuantizationTableSize = 3072;
const uint32_t kRenderSampleCount = 120;
const uint32_t kTextureCacheEntryCount = 50;
const uint32_t kStackReserve = 0x00100000;
}

const char* sfera_cursor_texture_name(uint32_t slot);

inline uint32_t g_sfera_log_first_write = 1u;

struct SferaItemArray {
    void** block_vector_begin;
    void** block_vector_end;
    void** block_vector_capacity_end;
    uint32_t free_capacity;
    void** free_items;
    uint32_t free_count;
    uint32_t growth_count;

    bool grow(std::uint32_t item_size);
    void* take();
    void put(void* item);
    void clear();
};
struct SferaDirectPlayCaps32 {
    uint32_t words[12];
};
struct SferaDpnCapsRuntime {
    uint32_t size;
    uint32_t flags;
    uint32_t connect_timeout_ms;
    uint32_t connect_retries;
    uint32_t timeout_until_keepalive_ms;
};
struct SferaDpnBufferDescRuntime {
    uint32_t buffer_size;
    void* buffer_data;
};
struct SferaDpnConnectionInfoRuntime {
    uint32_t size;
    uint32_t round_trip_latency_ms;
    uint32_t throughput_bps;
    uint32_t peak_throughput_bps;
    uint32_t bytes_sent_guaranteed;
    uint32_t packets_sent_guaranteed;
    uint32_t bytes_sent_non_guaranteed;
    uint32_t packets_sent_non_guaranteed;
    uint32_t bytes_retried;
    uint32_t packets_retried;
    uint32_t bytes_dropped;
    uint32_t packets_dropped;
    uint32_t messages_transmitted_high_priority;
    uint32_t messages_timed_out_high_priority;
    uint32_t messages_transmitted_normal_priority;
    uint32_t messages_timed_out_normal_priority;
    uint32_t messages_transmitted_low_priority;
    uint32_t messages_timed_out_low_priority;
    uint32_t bytes_received_guaranteed;
    uint32_t packets_received_guaranteed;
    uint32_t bytes_received_non_guaranteed;
    uint32_t packets_received_non_guaranteed;
    uint32_t messages_received;
};
struct SferaU64Words {
    uint32_t low;
    uint32_t high;
};
using SferaCounter64Words = SferaU64Words;
struct SferaNetworkTransportRuntime {
    uint32_t mode;
    uint8_t transport_flag;
    uint8_t receive_busy;
    uint8_t receive_corrupted;
    uint8_t reserved_07;
    SferaDirectPlayAddressNative* primary_address;
    SferaDirectPlayAddressNative* secondary_address;
    uint32_t sent_packet_count;
    SferaCounter64Words sent_bytes;
    uint32_t received_packet_count;
    uint32_t receive_read_index;
    SferaCounter64Words received_bytes;
    uint32_t receive_write_index;
    uint32_t reserved_30;
};
struct SferaDirectPlayRuntime {
    SferaDirectPlayClientNative* peer;
    SferaDpnCapsRuntime caps;
    CRITICAL_SECTION critical_section;
    SferaDpnBufferDescRuntime send_buffer;
    DWORD send_async_handle;
    SferaDpnConnectionInfoRuntime connection_info;
    SferaNetworkTransportRuntime transport;
};
inline constexpr std::size_t kSferaNetworkMessageSlotCount = 3048u;
struct SferaNetworkMessageSlot {
    DWORD message;
    DWORD sender;
    DWORD buffer_handle;
    uint8_t data[400];
    DWORD data_size;
    uint8_t reserved[8];
};
struct SferaNetworkRuntime {
    uint32_t initialization_result;
    uint32_t server_port;
    uint32_t local_port_candidate;
    uint32_t connection_slot;
    uint32_t pending_slot;
    uint32_t active_slot;
    uint32_t shutdown_state;
    uint8_t timeout_marker_pending;
    uint8_t net_log_has_error;
    uint8_t network_error_active;
    uint8_t initialized;
    uint32_t bytes_sent_delta;
    uint32_t bytes_retried_delta;
    uint32_t bytes_received_delta;
    uint32_t error_budget;
    SferaDirectPlayCaps32 directplay_caps;
    DWORD message_call_scratch;
    SferaNetworkMessageSlot message_slots[kSferaNetworkMessageSlotCount];
};
struct SferaNetworkConnectionCheckerRuntime {
    uint32_t instance;
};
struct SferaNetworkSendRuntime { CRITICAL_SECTION critical_section; };
struct SferaInterpreterScratchRuntime {
    uint32_t diagnostic_step_counter;
    uint32_t network_poll_counter;
    uint32_t item_lookup_result;
};

struct WorldObject;


struct SferaLightRecord {
    SferaEffectVec3F position;
    float color[4];
    float radius;
    SferaEffectVec3F bounds_min;
    SferaEffectVec3F bounds_max;
    std::uint32_t reserved;

    void update(const SferaEffectVec3F& new_position, const float* new_color, float new_radius);
};

struct SferaLightRuntime {
    SferaBoundCheckArray<SferaLightRecord*> handles;
    SferaBoundCheckArray<SferaLightRecord*> visible_handles;
    SferaBoundCheckArray<std::uint32_t> active_handles;
    uint32_t render_candidate_indices[30];
    uint32_t render_candidate_active[30];

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
struct SferaAutoBoundsArray {
    uint32_t data;
    uint32_t capacity;
    uint32_t maximum;
    uint32_t growth;
    uint32_t element_size;
    char debug_file[32];
    uint32_t debug_line;
};
struct SferaLandscapeRuntime {
    SferaBoundCheckArray<TerrainRegion> file_records;
};
struct SferaCollisionRuntime {
    SferaBoundCheckArray<float> candidate_handles;
    SferaBoundCheckArray<std::uint32_t> near_result_handles;
    SferaAutoBoundsArray contact_objects;
};
struct SferaSceneArrayRuntime {
    SferaBoundCheckArray<std::byte> cloud_records;
    SferaBoundCheckArray<std::byte> render_pass_slots;
    SferaBoundCheckArray<SferaVec3F> clip_vectors;
    SferaBoundCheckArray<SferaVec3F> scene_points;
    SferaBoundCheckArray<SphereRender::SceneSortEntry> object_positions;
    SferaBoundCheckArray<SferaMatrix4x4F> model_matrices;
    SferaBoundCheckArray<std::byte> world_cell_records;
    SferaBoundCheckArray<const TerrainCell*> object_sort_keys;
    SferaBoundCheckArray<float> object_draw_indices;
    SferaBoundCheckArray<std::uint32_t*> object_visibility_indices;
    SferaBoundCheckArray<SferaVec3F> clip_points;
    SferaBoundCheckArray<SferaMatrix4x4F> character_matrices;
    SferaBoundCheckArray<TerrainPatch*> object_sort_indices;
    SferaBoundCheckArray<std::uint32_t> clip_indices;
};
struct SferaSceneBuildRuntime {
    uint32_t object_count;
    uint16_t landscape_debug_pixels[256 * 256];
};

struct SferaTreeMapHeader {
    uint8_t comparator;
    uint8_t reserved[3];
    uint32_t sentinel;
    uint32_t size;
};
struct SferaModelMaterialLookupRuntime {
    uint32_t refresh_tick;
};
struct SferaIntrusiveListHeader {
    SferaActiveEffect* first;
    SferaActiveEffect* last;
};
struct SferaEffectListenerNodeRuntime {
    uint32_t left;
    uint32_t parent;
    uint32_t right;
    uint32_t effect_id;
    uint32_t listener;
    uint8_t color;
    uint8_t is_nil;
    uint8_t reserved_16[2];
};
using SferaListStackRuntime = SferaIntrusiveListHeader;
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
#if defined(_M_IX86)
#endif

struct SferaNatureRuntime { SferaNatureManager* manager; };
SferaNatureManager* sfera_nature_manager();
void sfera_initialize_nature_manager();
void sfera_shutdown_nature_manager();

struct SferaWarningLogRuntime {
    uint8_t object[0x5320];
};
struct SferaControlOptionsRuntime {
    uint32_t active_slot;
    uint32_t configured_bindings[64];
    uint32_t working_bindings[64];
};
struct SferaSpriteRuntime {
    uint32_t render_mode;
    char texture_token[0x110];
};
struct SferaCrashRuntime {
    uint8_t report_pending;
};
using SferaDynGreenRuntime = SferaU64Words;
struct SferaExecutionMonitorRuntime {
    uint32_t thread_handle;
    uint8_t reserved_04[8];
    uint16_t stop_requested;
    char log_path[0x36];
    CRITICAL_SECTION critical_section;
    uint32_t current_value_a;
    uint32_t current_value_b;
};
struct SferaErrorLogRuntime {
    union { uint8_t object[24]; IOutputDevice* outputs[2]; };
    uint8_t index_table[0x80];
};
struct SferaFrameRuntime {
    float fps;
    uint32_t fps_sample_count;
    SferaU64Words fps_anchor;
    uint32_t frame_sample_count;
    SferaU64Words frame_anchor;
    SferaU64Words frame_state_anchor;
    uint32_t frame_state;
    uint32_t primary_toggle;
    uint32_t secondary_toggle;
    GrassMapMngr color_lookup_object;
    uint32_t color_lookup_flags;
    uint32_t warning_header_written;
};
struct SferaHighResolutionClockRuntime {
    SferaU64Words elapsed_counter;
    SferaU64Words epoch_microseconds;
    SferaU64Words performance_frequency;
    uint32_t frequency_shift;
    uint32_t initialized;
    SferaU64Words counter_anchor;
};
struct SferaProfilerRuntime {
    void begin(std::size_t index);
    void end(std::size_t index);
    SferaU64Words accumulated_ticks[kProfileSlotCount];
    uint8_t active[kProfileSlotCount];
    uint32_t frame_count;
    SferaU64Words start_time_us[kProfileSlotCount];
    uint32_t call_count[kProfileSlotCount];
    uint32_t frame_time_total;
    SferaU64Words report_clock_snapshot;
    uint32_t report_percent[10];
};
struct SferaCrc32Runtime {
    uint32_t table[256];
    uint32_t current;
};
struct SferaAsciiLowerRuntime {
    uint8_t table[256];
};
struct SferaStringUtilityRuntime {
    uint32_t case_tables_initialized;
    uint8_t lowercase[256];
    uint8_t uppercase[256];
    char format_buffer[512];
};
struct SferaNetworkProbeSample {
    SferaU64Words timestamp;
    uint32_t probe_result;
    uint32_t context_a;
    uint32_t context_b;
    uint32_t context_c;
};
struct SferaNetworkProbeRuntime {
    uint32_t sample_count;
    uint8_t stop_requested;
    char host[64];
    uint32_t context_a;
    uint32_t context_b;
    uint32_t snapshot_count;
    uint32_t thread_handle;
    CRITICAL_SECTION critical_section;
    SferaNetworkProbeSample samples[kNetworkProbeSampleCount];
    uint32_t context_c;
    SferaNetworkProbeSample snapshot[kNetworkProbeSampleCount];
};
struct SferaConfigParseScratchRuntime {
    uint8_t token[256];
};
struct SferaMusicRuntime {
    char requested_path[512];
    SferaSoundPlaybackState* current_stream;
};
struct SferaMainCommandStateRuntime {
    uint8_t command_enabled;
    uint8_t lighting_enabled;
    uint8_t reserved_002[6];
    uint32_t render_samples[120];
    float sky_blend_factor;
    uint32_t lighting_state;
    uint32_t light_update_counter;
    uint32_t default_cursor_token[2];
    uint8_t reserved_1fc[0x0C];
    uint32_t draw_selection_state;
    uint32_t render_channel_mask;
    uint32_t object_reference_count;
    uint32_t command_state;
    uint32_t escape_without_query;
    uint32_t window_count;
    uint32_t viewport_state;
    uint32_t interface_state;
    uint32_t near_collision_count;
};

struct SferaMainInputStateRuntime {
    uint32_t input_state;
    uint8_t reserved_004[8];
    uint32_t input_mode;
    float motion_accumulator;
    uint32_t input_state_02;
    uint32_t input_state_03;
    uint32_t input_enabled;
    float camera_step;
    uint8_t reserved_028[4];
    SferaMouseInputState mouse;
    float motion_x;
    float motion_y;
    uint32_t input_state_04;
    uint32_t active_input_handle;
    uint32_t input_state_05;
    uint8_t reserved_050[8];
    SphereWorld::GrassCell* landscape_texture_base;
    uint8_t landscape_texture_lut[256][2];
    uint32_t landscape_state;
};

struct SferaMainViewStateRuntime {
    float projection_samples[125];
    uint32_t projection_sample_count;
    uint32_t view_state;
    float view_coefficients[6];
    uint32_t view_flags;
    uint32_t view_mode;
    uint32_t view_accumulator;
    float projection_scale;
};

struct SferaInterpolationAxisState {
    uint32_t count;
    float samples[19];
};

struct SferaMainUiStateRuntime {
    uint32_t ui_state;
    char gamexp_sid[32];
    uint32_t ui_state_02;
    SphereWorld::GrassCell* ui_state_03;
    uint32_t ui_state_04;
    uint8_t reserved_030[8];
    float scene_factor;
    float scene_scale;
    uint32_t ui_state_05;
    HINSTANCE active_ui_object;
    SferaFrustumF clip_frustum;
    uint32_t ui_state_06;
    uint32_t ui_state_07;
    uint32_t ui_state_08;
    uint8_t reserved_0b4[4];
    SferaInterpolationAxisState interpolation_axes[3];
    uint32_t reserved_1a8;
    uint32_t ui_state_09;

    bool effectVisible(const IEffect& effect, const SferaEffectVec3F& position) const;
};



struct SferaClientConfigRuntime {
    uint8_t reserved_008;
    uint8_t flag_01;
    uint8_t flag_02;
    uint8_t flag_03;
    uint32_t state_03;
    uint32_t state_09;
    uint32_t state_10;
    float scalar_01;
    uint32_t state_11;
    uint32_t state_12;
    uint32_t state_13;
    uint32_t state_14;
    uint32_t state_15;
    uint32_t state_16;
    uint8_t reserved_048[4];
    uint32_t state_17;
    uint32_t state_18;
    uint8_t reserved_054[0x0C];
    uint32_t debug_config_enabled;
    uint8_t reserved_064[4];
    uint32_t state_19;
    uint32_t state_20;
    uint32_t state_21;
    uint32_t state_22;
    uint32_t state_23;
    uint8_t reserved_07c[5];
    uint8_t connect_type_enabled;
    uint8_t gamexp_sid_present;
    uint8_t reserved_083;
    uint32_t state_24;
    uint8_t reserved_088[4];
    uint32_t state_25;
    uint32_t state_26;
    uint32_t state_27;
    uint8_t reserved_098[8];
    uint32_t state_28;
    uint32_t state_29;
    uint32_t text_length_01;
    char text_01[0x10];
    uint8_t reserved_0bc[0x10];
    uint32_t text_capacity_01;
    uint32_t state_30;
    uint32_t text_length_02;
    char text_02[0x10];
    uint8_t reserved_0f4[0x10];
    uint32_t text_capacity_02;
    uint32_t auto_grass_object;
};


struct SferaClientMainScalarRuntime {
    uint32_t counter_01;
    uint32_t state_01;
    std::uint16_t* state_02;
    uint32_t state_03;
    uint32_t state_04;
    uint32_t counter_02;
    uint32_t counter_03;
    uint32_t mode_01;
    uint32_t mode_02;
    uint32_t state_05;
    uint32_t state_06;
    uint32_t state_07;
    uint32_t state_11;
    uint32_t state_12;
    uint32_t state_13;
    uint32_t state_14;
    uint32_t state_15;
    uint32_t state_16;
    uint32_t state_17;
    uint32_t state_18;
    uint32_t state_19;
    uint32_t state_20;
    uint32_t state_21;
    uint32_t state_22;
    uint32_t state_23;
    uint32_t state_24;
    uint32_t state_25;
    uint32_t state_26;
    uint32_t state_27;
    uint32_t state_28;
    uint32_t state_29;
    uint32_t state_30;
    uint32_t state_31;
    uint32_t state_32;
    uint32_t state_33;
    uint32_t counter_04;
};
struct SferaInterScalarRuntime {
    uint32_t state_01;
    uint32_t state_02;
    QuickFile* quick_files;
    uint32_t mode_01;
    CHash16* registered_object_index;
    uint32_t mode_03;
    uint32_t state_04;
    uint32_t mode_04;
    uint32_t state_05;
    uint32_t state_06;
    uint32_t state_07;
};


struct SferaInterfaceRuntime {
    uint32_t cursor_kind;
    uint8_t primary_gate;
    uint8_t secondary_gate;
    uint32_t cross_enabled;
    uint32_t sounds_enabled;
    uint32_t description_auto_popup;
    uint32_t invite_messages;
    union { uint32_t description_window; SphereUI::CDescriptionWindow* description_control; };
    uint32_t previous_input_modifiers;
    SferaBoundCheckArray<GameUiWindow*> windows;
    SferaBoundCheckArray<WorldGuiControl*> window_handle_table;
};
using SferaStdAllocator = StdAllocator;
namespace SphereUI::Memory { struct AllocationHeader; struct AllocationRecord; struct AllocationSource; }

using SferaCursorTextureRegistryRuntime = SferaTreeMapHeader;
struct SferaBrowserWindowRuntime {
    uint8_t class_registered;
    uint8_t reserved_01[3];
    WNDPROC original_window_proc;
};
struct SferaCrashReportRuntime {
    char report_text[0x2000];
    uint32_t report_length;
    uint32_t reserved_2004;
    char error_log_path[0x104];
    uint32_t previous_exception_filter;
    uint32_t process_handle;
    uint32_t error_log_handle;
};
struct SferaFileRuntime { std::uint32_t crash_report_instance; };
union SferaFloatWord {
    float f32;
    uint32_t u32;
};
struct SferaVec3Word {
    SferaFloatWord x;
    SferaFloatWord y;
    SferaFloatWord z;
};
struct SferaSceneVectorRuntime {
    SferaVec3Word render_scale;
    SferaVec3Word transform_scratch;
    SferaVec3Word frame_102_position;
    SferaVec3Word frame_101_position;
    SferaVec3Word object_position_delta;
};
struct SferaSpatialBoundsRuntime {
    SferaVec3Word minimum;
    SferaVec3Word maximum;
};
struct SferaViewSpatialRuntime {
    SferaVec3Word basis[4];
    uint8_t alternate_projection;
    uint8_t reserved_31[3];
    SferaVec3Word position_offset;
    SferaVec3Word scale;
    SferaVec3Word world_anchor;
    SferaVec3Word view_axis;
};
using SferaLandscapeSampleSeries = SferaInterpolationAxisState;
struct SferaLandscapeInterpolationRuntime {
    uint32_t subdivision_count;
    SferaLandscapeSampleSeries axes[3];
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
    uint8_t initialized;
};
struct SferaUiParseScratchRuntime {
    char token_buffer[0x4000];
    char auxiliary_text[0x4000];
    char input_text[0x4000];
};
struct SferaCriticalDiagnosticsRuntime {
    char allocation_context[128];
    uint32_t processing_depth;
    uint32_t serial_number;
    uint32_t reserved_stack_dump_handler;
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
template <std::size_t N, typename Member>
inline uint32_t sfera_screen_vertex_address(SferaScreenVertex (&vertices)[N], std::size_t index, Member SferaScreenVertex::* member) {
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&(vertices[index].*member)));
}

template <std::size_t N, typename Member>
inline uint32_t sfera_screen_vertex_field_end_address(SferaScreenVertex (&vertices)[N], Member SferaScreenVertex::* member) {
    return sfera_screen_vertex_address(vertices, 0u, member) + static_cast<uint32_t>(sizeof(vertices));
}
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
    uint32_t saved_lods_enabled;
    SferaFloatWord saved_lod_distance;
    SferaFloatWord saved_fog_distance;
    uint32_t saved_music_volume;
    char option_labels[7][0x200];
};
struct SferaVector32 {
    uint32_t begin;
    uint32_t end;
    uint32_t capacity_end;
};
struct SferaOptionsDialogRuntime {
    union { uint32_t graphics_snapshot[7]; char graphics_unknown_label[28]; };
    uint32_t audio_settings;
    char widget_key_name[0x80];
    uint32_t pending_graphics_value;
    uint32_t comparison_graphics_value;
    uint32_t widget_keys_initialized;
    uint32_t reflection_quality;
    union { struct { SferaVector32 chat_list_fonts; uint32_t reserved_18c; }; SphereUI::UiIndexVector saved_chat_fonts; };
    union { struct { SferaVector32 chat_edit_fonts; uint32_t reserved_19c; }; SphereUI::UiIndexVector edited_chat_fonts; };
};
struct SferaWindowRuntime {
    uint32_t reserved_004;
    uint32_t render_state_word;
    uint32_t reserved_00c;
    uint32_t clip_vector_count;
    SferaFloatWord distance_scratch;
    CRITICAL_SECTION timing_critical_section;
    uint8_t reserved_030[0x78];
    PathZones* path_zones = nullptr;
    uint32_t reserved_0ac;
    uint32_t input_state;
    uint32_t active_window_index;
    uint32_t windowed;
    union { uint32_t main_window; HWND main_window_handle; };
    uint32_t reserved_0c0;
    std::array<std::uint32_t, 2>* landscape_grid_records;
    uint32_t landscape_grid_count;
    uint32_t runtime_debug_enabled;
    uint32_t reserved_0d0;
    uint32_t scene_record_count;
    char diagnostic_message[0x800];
    uint32_t reserved_8d8;
};
struct SferaInputDeviceRuntime {
    uint32_t process_value;
    uint32_t input_generation;
    uint32_t reserved_008;
    SferaFloatWord minimum_lod_distance;
    SferaFloatWord lod_distance;
    uint32_t keyboard_state_code;
    uint32_t reserved_01c;
    SferaFloatWord frame_interval;
    uint32_t render_state;
    uint32_t shared_object;
};
struct SferaScreenClipRuntime {
    uint32_t left;
    uint32_t top;
    uint32_t right;
    uint32_t bottom;
};
struct SferaWorldRenderRuntime {
    SphereRender::Model* active_model;
    SphereWorld::DynamicVegetation* world_spatial_index;
    uint32_t feature_toggle;
    uint32_t scene_active;
};
struct SferaWorldLoadRuntime {
    uint32_t render_shadows;
    uint32_t active_tool_context;
    uint32_t live_object_count;
    uint32_t packed_variant;
    uint32_t loading_work_total;
    std::unique_ptr<SnowField> snow_path_object;
};
using SferaWorldBoundsRuntime = SferaSpatialBoundsRuntime;
struct SferaRenderLookupEntry {
    uint32_t resource;
    uint32_t mask;
};
struct SferaRenderLookupRuntime {
    uint32_t initialized;
    uint32_t alpha_component;
    SferaRenderLookupEntry entries[256];
};
struct SferaLandscapeRenderRuntime {
    uint32_t grid_buffer_bytes;
    SferaFloatWord view_offset_x;
    SferaFloatWord view_offset_y;
    uint32_t rotation_step;
    uint32_t source_record_count;
    uint32_t source_section_base;
};
struct SferaProcessRuntime {
    char executable_path[64];
    uint32_t packed_layout_bytes;
    uint32_t packed_record_count;
};
struct SferaClientProcessRuntime {
    uint32_t ui_bridge;
    uint32_t shutdown_requested;
    char locale[10];
    Contours* client_object;
    char log_message[0x390];
};
struct SferaMainRenderRuntime {
    uint32_t world_object_count;
    uint32_t secondary_render_pass;
    uint32_t grass_depth_mode;
};
struct SferaMicrotextureRecord {
    uint16_t lookup_key;
    uint16_t reserved_02;
    uint32_t name;
    std::uint8_t* resource;
};
struct SferaSceneControlRuntime {
    uint32_t packed_section_base;
    uint32_t timing_anchor;
    SferaFloatWord camera_x;
    SferaFloatWord camera_y;
    SferaFloatWord environment_parameter;
    uint32_t active_context;
    uint32_t context_count;
    uint32_t context_queue[30];
    uint32_t microtexture_count;
    SferaMicrotextureRecord microtextures[100];
};
struct SferaMainAuxRuntime {
    SkyEnvironment* secondary_world_manager;
    uint32_t color_component;
    uint32_t resource_word;
};
struct SferaLandscapeMapRecord {
    char material_name[20];
    uint8_t tile_x;
    uint8_t tile_y;
};
struct SferaLandscapeMapRuntime {
    uint32_t material_remap;
    uint32_t show_fps;
    SferaLandscapeMapRecord records[kLandscapeMapRecordCount];
};
struct SferaSkyRuntime {
    SferaFloatWord horizon_scale;
    uint16_t indices[594];
};
struct SferaTextureCacheEntry {
    const TerrainCell* owner;
    uint8_t kind;
    uint8_t reserved_05[3];
    IDirect3DTexture9* resource;
    uint32_t use_count;
};
struct SferaTextureCacheRuntime {
    uint32_t active_index;
    uint32_t upload_serial;
    uint32_t reserved_08;
    uint32_t render_gate;
    uint32_t reserved_10;
    uint32_t cache_enabled;
    SferaTextureCacheEntry entries[kTextureCacheEntryCount];
};
struct SferaErrorMessageScratchRuntime {
    char fatal_message[kErrorMessageCapacity];
    char formatted_message[kErrorMessageCapacity];
};
struct SferaGrassMapRuntime {
    uint32_t alternating_update_phase;
    GrassMapMngr manager;
    uint32_t init_guard;
    SferaU64Words last_frame_timestamp;
};
struct SferaPhysicsRuntime {
    char damage_text[20];
    float response_curve[100];
};
struct SferaViewGeometryRuntime {
    SferaVec3F reference_points[5];
    SferaIntBounds3 projected_bounds;
    SferaIntBounds3 clipping_bounds;
};
struct SferaTerrainNeighborRuntime {
    uint32_t cells[8];
};
struct SferaLandscapePatchLookupRuntime {
    uint32_t visible_count;
    uint32_t active_count;
    SferaFloatWord parameter;
    SferaVec3Word primary_vector;
    SferaVec3Word secondary_vector;
    TerrainRegion* patch_records[6400];
};
struct SferaDebugWindowRuntime {
    uint32_t spider_window;
};
struct SferaViewMotionRuntime {
    SferaFloatWord motion_terms[5];
    SferaVec3Word reference_point;
    SferaVec3Word projected_a;
    SferaVec3Word projected_b;
    uint32_t update_serial;
    uint32_t mode_value;
    uint32_t initialized;
};
struct SferaRenderSampleRuntime {
    SferaFloatWord blend_weights[7];
    uint32_t material_base;
    uint32_t record_base;
    SferaFloatWord material_code;
    SferaFloatWord phase;
    float samples[kRenderSampleCount];
};
struct SferaTerrainDiagnosticRuntime {
    char normalize_code[12];
};
struct SferaWorldSlotRecord {
    uint32_t object_handle;
    uint8_t reserved_004[0x0C];
    uint32_t state;
    uint32_t linked_handle;
    uint8_t reserved_018[0x0C];
    uint32_t primary_state;
    uint32_t primary_flags;
    uint8_t primary_payload[0x190];
    uint32_t secondary_state;
    uint32_t secondary_flags;
    uint8_t secondary_payload[0x190];
    uint32_t record_state;
    uint8_t reserved_358[0x40];
};
struct SferaWorldSlotTableRuntime {
    SferaWorldSlotRecord slots[401];
    uint32_t active_limit;
};
struct SferaConfigTextRuntime {
    static constexpr std::size_t text_capacity = 2458176u;
    union { uint8_t owned_text[text_capacity]; char text_storage[text_capacity]; };
    union { uint32_t current_text; char* text_buffer; };
    uint32_t text_length;
    char format_scratch[512];
    char parser_path[1024];
};
struct SferaStaticRenderLookupRuntime {
    float normalized_levels[7];
    float command_samples[kRenderSampleCount];
    float view_phase;
    uint16_t packed_format_code;
    uint16_t reserved_1e;
    uint32_t sample_state;
    uint32_t sample_flags[kRenderSampleCount];
    uint8_t glyph_presence[kFontLookupGlyphCount];
    uint8_t quantization_a[kRenderQuantizationTableSize];
    uint8_t quantization_b[kRenderQuantizationTableSize];
    float projection_scale;
    uint8_t blend_lut[kRenderBlendLutStorageSize];
    uint8_t color_remap_a[256];
    uint8_t color_remap_b[256];
    uint8_t color_remap_c[256];
    uint8_t legacy_crc_low_table[256];
};
struct SferaSpatialIndexRuntime {
    std::map<std::pair<std::int32_t, std::int32_t>, SphereWorld::SpatialLeaf> quadtree_cells;
    uint32_t quadtree_state;
};
struct SferaStartupCommandLineRuntime {
    char text[0x160];
    uint32_t parser_state;
};
struct SferaCollisionScratchRuntime {
    uint8_t debug_vertices[0x70];
    SferaLightRecord light_candidates[30];
    uint16_t dynamic_indices_aux[kDynamicIndexScratchCount];
};
struct SferaMbcStaticRuntime {
    uint32_t profile_fallback;
    uint32_t stack_default_values[256];
    SferaU64Words startup_time;
    uint32_t init_marker;
    uint8_t init_flag;
    uint8_t service_flag;
    uint8_t reserved[2];
};
struct SferaMapGeneratorRuntime {
    uint8_t storage[0x68];
};
struct SferaAlphaMaterialRuntime {
    int32_t selected_slot;
    uint8_t option_a;
    uint8_t option_b;
    uint8_t option_c;
    uint8_t reserved_07;
    float alpha[4];
};
struct SferaClientArrayRuntime {
    SferaAutoBoundsArray e7_records;
    SferaAutoBoundsArray e8_indices;
    SferaAutoBoundsArray e9_indices;
    SferaAutoBoundsArray eb_records;
    SferaAutoBoundsArray ed_indices;
    SferaAutoBoundsArray line_102_indices;
    SferaAutoBoundsArray line_105_records;
    SferaAutoBoundsArray line_6b1_indices;
    SferaAutoBoundsArray line_6b3_indices;
    SferaAutoBoundsArray line_6b4_indices;
    SferaAutoBoundsArray line_6b5_records;
    SferaBoundCheckArray<std::byte> line_124d_records;
    SferaBoundCheckArray<std::byte> line_24de_records;
    SferaBoundCheckArray<std::byte> line_24e0_records;
    SferaBoundCheckArray<std::byte> line_24e2_records;
};
struct SferaRecoveredStaticRuntime {
    uint32_t network_bytes_sent_snapshot;
    uint32_t network_bytes_retried_snapshot;
    uint32_t network_bytes_received_snapshot;
    uint32_t simulation_tick;
    uint32_t vertical_sync_enabled;
    uint32_t memory_warning_as_error;
    uint32_t mbc_stack_table_cursor;
    uint32_t server_number;
    uint32_t loadcount_guard;
    SferaVec3Word mbc_vector_scratch;
    uint8_t mbc_service_object[0x4010];
    float inverse_40;
    SferaBoundCheckArray<std::uint32_t> legacy_light_arrays[3];
    uint32_t view_transition_counter;
    uint32_t view_direction_state;
    uint32_t scene_mode;
    uint32_t scene_counter;
    CRITICAL_SECTION scene_lock;
    uint32_t input_state_a;
    float cursor_accumulator;
    uint32_t input_state_b;
    uint32_t render_gate;
    uint32_t text_size_height;
    uint32_t client_state_01;
    uint32_t client_state_02;
    uint32_t client_state_03;
    float ui_cell_width;
    float clip_depth;
    uint32_t client_state_04;
    uint32_t client_state_05;
    uint32_t client_state_06;
    uint32_t graphics_state;
    uint32_t font_renderer_state;
    uint32_t render_state_07;
    SphereRender::CharacterModels* render_state_08;
    uint32_t render_state_09;
    uint32_t render_state_10;
    uint32_t scene_state_07;
    EnvironmentZones* scene_state_08;
    uint32_t scene_state_09;
    uint32_t interaction_enabled;
    uint32_t interaction_input_flags;
    float animation_phase;
    uint32_t animation_result_b;
    SferaAutoBoundsArray primary_auto_array;
    SferaVec3Word flare_clip_vector;
    SferaAutoBoundsArray secondary_auto_array;
    SferaAutoBoundsArray tertiary_auto_array;
    uint32_t ui_counter_a;
    uint32_t ui_counter_b;
};
struct SferaPendingKeyRuntime {
    uint32_t count;
    uint32_t key_codes[30];
};
struct SferaRelaunchRuntime {
    char argument[0x84];
};

struct SferaEffectManager {
    uint32_t deferred_lifecycle;
    uint32_t render_cycle;
    uint32_t active_resource_count;
    uint32_t detail_setting;
    uint32_t effects_enabled;
    uint32_t render_slot_count;
    std::uint16_t* particle_random_table;
    SferaEffectMeshResource* particle_resource_head;
    IEffect* effect_definition_head;
    uint32_t initialized;
    std::vector<std::uint16_t> render_order;
    uint32_t active_effect_count;
    SferaIntrusiveListHeader active_effects;
    uint32_t generation;
    uint32_t last_processed_generation;
    uint32_t flare_transition;
    uint32_t flare_enabled;
    uint32_t flare_alpha;
    SferaVec3F viewer_position;
    SferaBoundCheckArray<SferaEffectRenderSlot> render_slots;
    std::array<SferaEffectListenerEntry, 16> effect_listeners{};
    std::uint32_t listener_count = 0;

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
    bool setEffectParameters(std::uint32_t source_handle, const SferaEffectParameter* parameters, std::uint32_t count);
    void updateActiveEffects();
    void updateActiveEffect(SferaActiveEffect& item, std::uint16_t state_flags, float viewer_distance);
};

inline SferaItemArray g_sfera_effect_items{.growth_count = 6000u};
inline SferaItemArray g_sfera_sound_effect_items{.growth_count = 128u};
inline SferaServerWall g_sfera_server_wall{.texture_id = UINT32_MAX};
inline SferaNetworkRuntime g_sfera_network_runtime{.initialization_result = UINT32_MAX, .server_port = 25858u, .local_port_candidate = 26860u, .connection_slot = UINT32_MAX, .pending_slot = UINT32_MAX, .active_slot = UINT32_MAX, .shutdown_state = UINT32_MAX};
inline SferaDirectPlayRuntime g_sfera_directplay_runtime;
inline SferaNetworkConnectionCheckerRuntime g_sfera_network_connection_checker;
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
inline SferaUiParseScratchRuntime g_sfera_ui_parse_scratch_runtime;
inline SferaCriticalDiagnosticsRuntime g_sfera_critical_diagnostics_runtime;
inline SferaTerrainNeighborRuntime g_sfera_terrain_neighbor_runtime;
inline SferaLandscapePatchLookupRuntime g_sfera_landscape_patch_lookup_runtime;
inline SferaDebugWindowRuntime g_sfera_debug_window_runtime;
inline SferaViewMotionRuntime g_sfera_view_motion_runtime;
inline SferaRenderSampleRuntime g_sfera_render_sample_runtime;
inline SferaSceneVectorRuntime g_sfera_scene_vector_runtime;
inline SferaVec3Word g_sfera_flare_projection;
inline SferaTerrainDiagnosticRuntime g_sfera_terrain_diagnostic_runtime;
inline SferaWorldSlotTableRuntime g_sfera_world_slot_table_runtime;
inline SferaConfigTextRuntime g_sfera_config_text_runtime;
inline SferaStaticRenderLookupRuntime g_sfera_static_render_lookup_runtime;
inline SferaMbcStaticRuntime g_sfera_mbc_static_runtime;
inline SferaMapGeneratorRuntime g_sfera_map_generator_runtime;
inline SferaAlphaMaterialRuntime g_sfera_alpha_material_runtime;
inline SferaClientArrayRuntime g_sfera_client_array_runtime;
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
inline uint16_t g_sfera_dynamic_index_scratch[kDynamicIndexScratchCount];
inline SferaNatureRuntime g_sfera_nature_runtime;
inline SferaSoundRuntime g_sfera_sound_runtime;
inline SferaWarningLogRuntime g_sfera_warning_log_runtime;
inline SferaControlOptionsRuntime g_sfera_control_options{.active_slot = UINT32_MAX};
inline SferaSpriteRuntime g_sfera_sprite_runtime{.render_mode = UINT32_MAX};
inline SferaCrashRuntime g_sfera_crash_runtime{.report_pending = 1u};
inline SferaDynGreenRuntime g_sfera_dyn_green_runtime;
inline SferaExecutionMonitorRuntime g_sfera_execution_monitor_runtime;
inline SferaErrorLogRuntime g_sfera_error_log_runtime;
inline SferaLogRuntime g_sfera_log_runtime;
inline SferaFrameRuntime g_sfera_frame_runtime;
inline SferaHighResolutionClockRuntime g_sfera_high_resolution_clock_runtime;
inline SferaProfilerRuntime g_sfera_profiler_runtime;
inline SferaCrc32Runtime g_sfera_crc32_runtime;
inline SferaStringLookupRuntime g_sfera_string_lookup_runtime;
inline SferaAsciiLowerRuntime g_sfera_ascii_lower_runtime;
inline SferaStringUtilityRuntime g_sfera_string_utility_runtime;
inline SferaNetworkProbeRuntime g_sfera_network_probe_runtime;
inline SferaConfigParseScratchRuntime g_sfera_config_parse_scratch_runtime;
inline SferaMusicRuntime g_sfera_music_runtime;
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
inline SferaMemoryRuntime g_sfera_memory_runtime{.allocation_source_name = "Unknown", .tracker_primary = 1000000000u, .tracker_floor = 1000000000u, .tracker_ceiling = 1000000000u};
inline SferaMemorySourceHashRuntime g_sfera_memory_source_hash_runtime;
inline SferaAllocationHashRuntime g_sfera_allocation_hash_runtime;
inline SferaDiagnosticLogObjectRuntime g_sfera_log_memory_object;
inline SferaDiagnosticLogObjectRuntime g_sfera_log_warnings_object;
inline SferaDiagnosticLogObjectRuntime g_sfera_log_errors_object;
inline uint8_t g_sfera_diagnostic_log_byte;
inline SferaCursorTextureRegistryRuntime g_sfera_cursor_texture_registry;
inline uint32_t g_sfera_cursor_texture_registry_guard;
inline SferaD3D9SemanticStateRuntime g_sfera_d3d9_semantic_state;
inline SferaBrowserWindowRuntime g_sfera_browser_window_runtime;
inline SferaCrtStartupRuntime g_sfera_crt_startup_runtime;
inline SferaCrashReportRuntime g_sfera_crash_report_runtime;
inline SferaBloodEffectRuntime* g_sfera_blood_effect_instance;
inline SferaFileRuntime g_sfera_file_runtime;
inline SferaEffectManager g_sfera_effect_manager{.deferred_lifecycle = 1u, .render_cycle = 31u, .last_processed_generation = UINT32_MAX};
inline SferaMbcRuntime g_sfera_mbc_runtime_storage;
inline SferaMbcRuntime* g_sfera_mbc_runtime = &g_sfera_mbc_runtime_storage;
inline SferaMbcInterpreterStorage g_sfera_mbc_interpreter_storage;
inline SferaMbcModuleMemoryStats g_sfera_mbc_module_memory_stats[4000];
inline char g_sfera_array_error_buffer[256];
inline constexpr char g_sfera_server_parser_whitespace[] = "\t\n\r ";
inline constexpr char g_sfera_menu_list_missing_parameter_message[] = "%s(): MenuList control must have '%s' parameter in file '%s', lines: [%d, %d]";
inline constexpr char g_sfera_menu_not_enough_arguments_message[] = "%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]";
inline constexpr char g_sfera_menu_sprite_not_found_message[] = "%s(): failed to find sprite '%s'";

inline uint32_t sfera_calendar_days_in_month(uint32_t month) {
    if (month < 1u || month > 12u) {
        return 0u;
    }
    return 30u + ((month + (month > 7u ? 1u : 0u)) & 1u) - (month == 2u ? 2u : 0u);
}

inline uint32_t sfera_calendar_days_before_month(uint32_t month) {
    if (month < 1u || month > 13u) {
        return 0u;
    }
    uint32_t days = 0u;
    for (uint32_t current = 1u; current < month; ++current) {
        days += sfera_calendar_days_in_month(current);
    }
    return days;
}


