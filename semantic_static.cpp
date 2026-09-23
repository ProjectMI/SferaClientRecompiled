#include "semantic_classes.h"
#include "zlib.h"
#include "semantic_static.h"
#include <commctrl.h>
#include <dinput.h>
#include <objbase.h>

#include <algorithm>
#include <array>
#include <bit>
#include <charconv>
#include <climits>
#include <fcntl.h>
#include <float.h>
#include <mbctype.h>
#include <cerrno>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <io.h>
#include <share.h>
#include <sys/stat.h>
#include <sys/locking.h>
#include <sys/utime.h>
#include <memory>
#include <new>
#include <fstream>
#include <filesystem>
#include <iterator>
#include <stdexcept>
#include <system_error>
#include <limits>
#include <string>
#include <string_view>
#include <span>
#include <vector>
#include <utility>
#include <ws2tcpip.h>
std::string SphereUI::InterfaceConfiguration::text_;
std::string SphereUI::InterfaceConfiguration::filename_;

EnvironmentLighting SphereRender::SceneRenderer::environment{};
SferaVec3F SphereRender::SceneRenderer::sun_direction{};
bool SphereRender::SceneRenderer::interior_scene{};

uint32_t SphereUI::InterfaceRenderer::sprite_render_mode = UINT32_MAX;
SphereUI::UiRect SphereUI::InterfaceRenderer::clip_rectangle{};
SferaScreenVertex SphereUI::InterfaceRenderer::glyph_vertices[1200]{};
uint16_t SphereUI::InterfaceRenderer::quad_indices[1800]{};
uint32_t SferaClientApplication::frame_samples{};
std::uint64_t SferaClientApplication::frame_anchor{};
uint32_t SferaClientApplication::frame_elapsed_ticks{};
bool SferaClientApplication::main_loop_started{};
HINSTANCE SferaClientApplication::instance_handle{};
bool SferaClientApplication::interpreter_initialized{};
uint32_t SferaClientApplication::language{};
bool SferaClientApplication::resources_loaded{};
bool SferaClientApplication::windowed{};
HWND SferaClientApplication::main_window{};
float SferaClientApplication::measured_fps{};
bool SferaClientApplication::interrupted{};
bool SferaClientApplication::quit_requested{};
bool SferaClientApplication::startup_complete{};
char SferaClientApplication::locale[10]{};
uint32_t SferaClientApplication::desktop_width{};
bool SferaClientApplication::application_active{};
SferaClientApplication::Lifecycle SferaClientApplication::lifecycle = SferaClientApplication::Lifecycle::Dormant;
bool SferaClientApplication::com_initialized = false;
bool SferaClientApplication::window_class_registered = false;
bool SferaClientApplication::fatal_error_in_progress{};
uint32_t SferaClientApplication::server_number{};
uint32_t SferaClientApplication::desktop_height{};
bool SferaClientApplication::storage_initialized{};
GrassMapMngr TerrainAssets::color_map{};
uint32_t TerrainAssets::color_map_ready{};
bool TerrainAssets::high_resolution_assets{};
bool TerrainAssets::alternate_ph_assets{};
bool TerrainAssets::alternate_rd_assets{};
bool SphereRender::ModelPose::inverted_fade_pass{};
bool SphereRender::ModelPose::secondary_enabled{};
std::size_t SphereRender::ModelPose::primary_frame{};
SferaVec3F SphereRender::ModelPose::scale{};
SferaVec3F SphereRender::ModelPose::translation{};
SferaVec3F SphereRender::ModelPose::attachment_102_position{};
SferaVec3F SphereRender::ModelPose::attachment_101_position{};
SphereRender::Model* SphereRender::ModelPose::active_model{};
float SphereRender::ModelPose::blend{};
std::size_t SphereRender::ModelPose::secondary_frame{};
SferaMatrix4x4F SphereRender::ModelPose::coordinate_basis{};
SferaMatrix4x4F SphereRender::ModelPose::current_frame{};
uint32_t SceneSky::layer_alpha[120]{};
float SceneSky::sample_elevation{};
float SceneSky::horizontal_motion{};
float SceneSky::azimuth_samples[125]{};
float SceneSky::screen_center_y{};
float SceneSky::sample_azimuth{};
SferaScreenVertex SceneSky::sun_quad[4]{};
uint32_t SceneSky::inverse_opacity{};
float SceneSky::cloud_offset_y{};
float SceneSky::cloud_offset_x{};
float SceneSky::sun_glow{};
std::unique_ptr<SkyEnvironment> SceneSky::high_resolution_environment{};
uint16_t SceneSky::indices[594]{};
float SceneSky::motion_terms[5]{};
SferaVec3F SceneSky::previous_origin{};
SferaVec3F SceneSky::projected_offset{};
SferaVec3F SceneSky::projected_center{};
float SceneSky::texture_phase_v{};
float SceneSky::glow_samples[120]{};
float SceneSky::elevation_samples[120]{};
float SceneSky::texture_phase_u{};
uint32_t SceneSky::sample_visible[120]{};
float SceneSky::screen_center_x{};
float SceneSky::vertical_motion{};
uint32_t SceneSky::sample_color{};
uint32_t SceneSky::flare_visible{};
float SceneSky::animation_phase{};
SferaVec3F SceneSky::flare_world_position{};
std::unique_ptr<SkyEnvironment> SceneSky::environment{};
SferaScreenVertex SceneSky::vertices[120]{};
SferaVec3F SceneSky::flare_screen_position{};
SkyState SceneSky::interpolated{};
uint32_t SphereRender::SceneRenderer::visible_character_parts{};
uint32_t SphereRender::SceneRenderer::terrain_texture{};
float SphereRender::SceneRenderer::reflection_distance{};
float SphereRender::SceneRenderer::view_distance{};
SferaFrustumF SphereRender::SceneRenderer::frustum{};
uint32_t SphereRender::SceneRenderer::shadow_projection_opacity{};
uint32_t SphereRender::SceneRenderer::model_visibility{};
float SphereRender::SceneRenderer::reflection_height{};
bool SphereRender::SceneRenderer::use_default_environment{};
SphereRender::SferaRenderLookupEntry SphereRender::SceneRenderer::bone_visibility[256]{};
uint32_t SphereRender::SceneRenderer::texture_animation_frame{};
uint32_t SphereRender::SceneRenderer::secondary_pass{};
SferaIntBounds3 SphereRender::SceneRenderer::projected_terrain_bounds{};
SferaIntBounds3 SphereRender::SceneRenderer::clipped_terrain_bounds{};
uint8_t SphereRender::SceneRenderer::color_remap[256]{};
uint32_t SphereRender::SceneRenderer::fog_adaptation_delay{};
std::unique_ptr<SphereRender::CharacterModels> SphereRender::SceneRenderer::characters{};
std::unique_ptr<EnvironmentZones> SphereRender::SceneRenderer::environment_zones{};
std::unique_ptr<EnvironmentZones> SphereRender::SceneRenderer::alternate_environment_zones{};
uint32_t GameInterface::loading_completed{};
SferaScreenVertex GameInterface::sprite_quad[4]{};
uint32_t GameInterface::active_window{};
uint32_t GameInterface::loading_total{};
uint32_t GameInterface::loading_guard{};
char WorldDiagnostics::message[2048]{};
uint32_t WorldGuiControls::text_height{};
uint32_t WorldGuiControls::text_width{};
std::array<TerrainTextureEntry, 50> TerrainTextureCache::entries{};
uint8_t TerrainTextureCache::quantization_x[3072]{};
uint8_t TerrainTextureCache::quantization_y[3072]{};
uint8_t TerrainTextureCache::blend_lut[16385]{};


const char* sfera_cursor_texture_name(uint32_t slot) {
    const char* name = nullptr;
    switch (slot) {
        case 0u: name = "_cursor1"; break;
        case 1u: name = "_cursor2"; break;
        case 2u: name = "cursor2"; break;
        case 3u: name = "cursor1"; break;
        default: return nullptr;
    }
    return name;
}

namespace {
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
constexpr float kDefaultLightRadius = 10.0f;
constexpr std::array kEffectFailureNames{
    "stopping", "active_limit", "sound_unavailable", "missing_definition", "factory",
    "filtered_type", "source_or_attachment", "listener", "allocation"
};
static_assert(kEffectFailureNames.size() == static_cast<std::size_t>(SferaEffectManager::CreateFailure::Count));
}

void SferaEffectManager::reportError(const char* message) const {
    if (message == nullptr) return;
    std::fprintf(stderr, "%s\n", message);
    ::OutputDebugStringA(message);
    ::OutputDebugStringA("\n");
    // Effect loading can continue after an error; preserve the reason in the existing client log.
    g_sfera_log_runtime.write("Effects: ");
    g_sfera_log_runtime.write(message);
    g_sfera_log_runtime.write("\n");
}
void SferaEffectManager::traceFailure(CreateFailure failure, std::uint32_t effect,
    std::uint32_t source, const char* name) noexcept {
    if (!diagnostics.enabled) return;
    const auto index = static_cast<std::size_t>(failure);
    if (index >= diagnostics.failures.size()) return;
    ++diagnostics.failures[index];
    if (diagnostics.details_written >= 24u) return;
    ++diagnostics.details_written;
    try {
        char message[512]{};
        std::snprintf(message, sizeof(message),
            "EffectDiag reject=%s id=%u source=%u name=%.128s filter=%u definitions=%zu active=%zu\n",
            kEffectFailureNames[index], effect, source, name ? name : "-",
            unsigned(effects_enabled), definitions.size(), active_effects.size());
        g_sfera_log_runtime.write(message);
    } catch (...) {
        // A diagnostic failure must not change the effect creation result.
    }
}

void SferaEffectManager::traceEffect(const char* event, const SferaActiveEffect& item) noexcept {
    if (!diagnostics.enabled || !item.effect) return;
    try {
        const auto& effect = *item.effect;
        const auto position = item.position_source == 0
            ? g_sfera_world_objects.objectPosition(item.source_handle) : item.position;
        char message[768]{};
        std::snprintf(message, sizeof(message),
            "EffectDiag %s id=%u source=%u name=%.96s age=%u lifetime=%u cycle=%u "
            "flags=%u blocked=%u deactivated=%u distance=%.3f position=%.3f,%.3f,%.3f\n",
            event, item.listener_key, item.source_handle, effect.script_name.c_str(), item.age_ticks,
            effect.lifetime_ticks, effect.cycle_length, unsigned(item.state_flags), unsigned(effect.activation_blocked),
            unsigned(effect.deactivated), double(item.viewer_distance),
            double(position.x), double(position.y), double(position.z));
        g_sfera_log_runtime.write(message);
    } catch (...) {
        // Recording a snapshot cannot affect the lifetime of the observed item.
    }
}

void SferaEffectManager::writeDiagnostics() noexcept {
    if (!diagnostics.enabled || !initialized) return;
    const auto now = WorldClock::nowTicks();
    if (diagnostics.samples != 0 && now - diagnostics.last_sample < 50000u) return;
    diagnostics.last_sample = now;
    ++diagnostics.samples;
    try {
        std::size_t particleDefinitions = 0, lightDefinitions = 0;
        for (const auto& definition : definitions) {
            const auto* scripted = dynamic_cast<const CScriptedEffect*>(definition.get());
            if (scripted && scripted->definition) {
                if (!scripted->definition->particles.empty()) ++particleDefinitions;
                if (!scripted->definition->lights.empty()) ++lightDefinitions;
            }
        }
        const auto liveLights = std::count_if(g_sfera_light_runtime.handles.begin(),
            g_sfera_light_runtime.handles.end(), [](const auto& light) { return bool(light); });
        const auto& fog = SphereRender::SceneRenderer::environment.fogParameters;
        char message[2048]{};
        std::snprintf(message, sizeof(message),
            "EffectDiag sample=%llu ticks=%llu defs=%zu particle_defs=%zu light_defs=%zu "
            "vm=%llu requests=%llu created=%llu active=%zu updates=%llu "
            "far=%llu frustum=%llu activation=%llu daytime=%llu budget=%llu expired=%llu "
            "render=%llu slots=%zu submitted_quads=%llu alpha_vertices=%llu "
            "lights=%zu visible_lights=%zu light_enables=%llu fog=%.3f,%.3f filter=%u\n",
            static_cast<unsigned long long>(diagnostics.samples), static_cast<unsigned long long>(now),
            definitions.size(), particleDefinitions, lightDefinitions,
            static_cast<unsigned long long>(diagnostics.vm_requests),
            static_cast<unsigned long long>(diagnostics.create_requests),
            static_cast<unsigned long long>(diagnostics.created), active_effects.size(),
            static_cast<unsigned long long>(diagnostics.updates),
            static_cast<unsigned long long>(diagnostics.distance_culled),
            static_cast<unsigned long long>(diagnostics.frustum_culled),
            static_cast<unsigned long long>(diagnostics.activation_rejected),
            static_cast<unsigned long long>(diagnostics.daytime_rejected),
            static_cast<unsigned long long>(diagnostics.budget_rejected),
            static_cast<unsigned long long>(diagnostics.expired),
            static_cast<unsigned long long>(diagnostics.render_calls), render_slot_count,
            static_cast<unsigned long long>(diagnostics.submitted_quads),
            static_cast<unsigned long long>(diagnostics.alpha_vertices), static_cast<std::size_t>(liveLights),
            g_sfera_light_runtime.visible_handles.size(),
            static_cast<unsigned long long>(diagnostics.light_activations),
            double(fog.y), double(fog.z), unsigned(effects_enabled));
        g_sfera_log_runtime.write(message);
        for (std::size_t index = 0; index < diagnostics.failures.size(); ++index) {
            if (diagnostics.failures[index] == 0) continue;
            std::snprintf(message, sizeof(message), "EffectDiag failures %s=%llu\n",
                kEffectFailureNames[index], static_cast<unsigned long long>(diagnostics.failures[index]));
            g_sfera_log_runtime.write(message);
        }
        std::size_t printed = 0;
        for (const auto& item : active_effects) {
            if (!item->effect) continue;
            traceEffect("live", *item);
            if (++printed == 3) break;
        }
    } catch (...) {
        // Diagnostics never control rendering, resource lifetime or VM execution.
    }
}

SferaEffectRenderSlot* SferaEffectManager::acquireRenderSlot() {
    if (render_slot_count >= render_slots.size()) return nullptr;
    return &render_slots[render_slot_count++];
}
void SferaEffectManager::finalizeBillboard(SferaEffectRenderSlot& slot, const SferaVec3F& position, float size) const {
    const SferaVec3F viewer{viewer_position.x, viewer_position.y, viewer_position.z};
    const SferaVec3F view{position.x - viewer.x, position.y - viewer.y, position.z - viewer.z};
    SferaVec3F right{view.y, -view.x, 0.0f};
    float length = std::sqrt(right.x * right.x + right.y * right.y + right.z * right.z);
    if (length > 0.00001f) { right.x /= length; right.y /= length; right.z /= length; }
    SferaVec3F up{right.y * view.z - right.z * view.y, right.z * view.x - right.x * view.z, right.x * view.y - right.y * view.x};
    length = std::sqrt(up.x * up.x + up.y * up.y + up.z * up.z);
    if (length > 0.00001f) { up.x /= length; up.y /= length; up.z /= length; }
    right.x *= size; right.y *= size; right.z *= size; up.x *= size; up.y *= size; up.z *= size;
    slot.position[0] = {position.x - right.x - up.x, position.y - right.y - up.y, position.z - right.z - up.z};
    slot.position[1] = {position.x - right.x + up.x, position.y - right.y + up.y, position.z - right.z + up.z};
    slot.position[2] = {position.x + right.x + up.x, position.y + right.y + up.y, position.z + right.z + up.z};
    slot.position[3] = {position.x + right.x - up.x, position.y + right.y - up.y, position.z + right.z - up.z};
}
float SferaEffectManager::viewerDistance(const SferaVec3F& position) const {
    const float dx = viewer_position.x - position.x;
    const float dy = viewer_position.y - position.y;
    const float dz = viewer_position.z - position.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}
float SferaEffectManager::viewerDistance(std::uint32_t source_handle) const { return viewerDistance(g_sfera_world_objects.objectPosition(source_handle)); }

bool SphereRender::SceneRenderer::effectVisible(const IEffect& effect, const SferaVec3F& position) {
    const SferaVec3F minimum{position.x + effect.bounds_min[0], position.y + effect.bounds_min[1], position.z + effect.bounds_min[2]};
    const SferaVec3F maximum{position.x + effect.bounds_max[0], position.y + effect.bounds_max[1], position.z + effect.bounds_max[2]};
    for (const auto& plane : frustum.planes) {
        bool all_outside = true;
        for (std::uint32_t corner = 0u; corner < 8u; ++corner) {
            const float x = (corner & 1u) != 0u ? maximum.x : minimum.x, y = (corner & 2u) != 0u ? maximum.y : minimum.y, z = (corner & 4u) != 0u ? maximum.z : minimum.z;
            if (x * plane.normal.x + y * plane.normal.y + z * plane.normal.z + plane.distance >= 0.0f) { all_outside = false; break; }
        }
        if (all_outside) return false;
    }
    return true;
}

void SferaLightRecord::update(const SferaVec3F& new_position, const float* new_color, float new_radius) {
    position = new_position;
    std::copy_n(new_color, std::size(color), color);
    radius = new_radius == 0.0f ? kDefaultLightRadius : new_radius;
}

SferaLightRecord* SferaLightRuntime::record(int handle) const {
    if (handle < 0 || static_cast<std::size_t>(handle) >= handles.size()) return nullptr;
    return handles[static_cast<std::size_t>(handle)].get();
}
int SferaLightRuntime::create(const SferaVec3F& position, const float* color, float radius) {
    if (color == nullptr) return -1;
    const auto slot = std::find(handles.begin(), handles.end(), nullptr);
    if (slot == handles.end()) return -1;
    auto light = std::unique_ptr<SferaLightRecord>(new (std::nothrow) SferaLightRecord{});
    if (light == nullptr) return -1;
    light->update(position, color, radius);
    *slot = std::move(light);
    return static_cast<int>(slot - handles.begin());
}
void SferaLightRuntime::write(int handle, const SferaVec3F& position, const float* color, float radius) {
    auto* light = record(handle);
    if (light != nullptr && color != nullptr) light->update(position, color, radius);
}
void SferaLightRuntime::release(int handle) {
    auto* light = record(handle);
    if (light == nullptr) return;
    if (std::find(visible_handles.begin(), visible_handles.end(), light) != visible_handles.end()) {
        visible_handles.clear();
        candidate_count = 0;
    }
    handles[static_cast<std::size_t>(handle)].reset();
}

void SferaEffectManager::appendDefinition(std::shared_ptr<IEffect> effect) {
    if (effect != nullptr) definitions.push_back(std::move(effect));
}

std::shared_ptr<IEffect> SferaEffectManager::findDefinition(uint32_t effect_id) const {
    const auto found = std::find_if(definitions.begin(), definitions.end(), [&](const auto& effect) { return effect->effect_id == effect_id; });
    return found == definitions.end() ? nullptr : *found;
}

std::shared_ptr<IEffect> SferaEffectManager::findDefinition(const char* script_name) const {
    if (script_name == nullptr) return nullptr;
    const auto found = std::find_if(definitions.begin(), definitions.end(), [&](const auto& effect) {
        return !effect->script_name.empty() && SferaText::asciiEqual(script_name, effect->script_name.c_str());
    });
    return found == definitions.end() ? nullptr : *found;
}

int32_t SferaEffectManager::findDefinitionId(const char* script_name) const {
    const auto effect = findDefinition(script_name);
    return effect != nullptr ? static_cast<int32_t>(effect->effect_id) : -1;
}

namespace {

void initialize_particle_random_table(SferaEffectManager& manager) {
    const auto seed = static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count());
    std::srand(seed);
    for (auto& value : manager.particle_random_table) value = static_cast<std::uint16_t>(std::rand());
    std::srand(static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count()));
}
template<class T, class Initializer>
void append_fixed_effect(SferaEffectManager& manager, Initializer initialize) {
    auto effect = std::make_shared<T>();
    initialize(*effect);
    manager.appendDefinition(std::move(effect));
}
}

SferaNatureManager* sfera_nature_manager() { return g_sfera_effect_manager.nature.get(); }

namespace {
void remove_nature_effect_handle(SferaActiveEffect*& handle) {
    if (handle != nullptr) g_sfera_effect_manager.removeActiveEffect(handle);
}
}

bool SferaNatureManager::initialize() {
    rain_listener.change_tick = lighting_listener.change_tick = kInvalidHandle;
    if (!g_sfera_effect_manager.registerListener(kRainEffectId, rain_listener)) return false;
    try {
        if (g_sfera_effect_manager.registerListener(kLightingEffectId, lighting_listener)) return true;
    } catch (...) {
        g_sfera_effect_manager.unregisterListener(rain_listener);
        throw;
    }
    g_sfera_effect_manager.unregisterListener(rain_listener);
    return false;
}

void SferaNatureManager::shutdown() {
    stopRain();
    stopLighting();
    g_sfera_effect_manager.unregisterListener(rain_listener);
    g_sfera_effect_manager.unregisterListener(lighting_listener);
    rain_effect = nullptr;
    lighting_effect = nullptr;
}

void SferaNatureManager::forgetEffect(const SferaActiveEffect& item) {
    if (rain_effect_handle == &item) rain_effect_handle = nullptr;
    if (lighting_effect_handle == &item) lighting_effect_handle = nullptr;
    for (auto& handle : ambient_rain_handles) if (handle == &item) handle = nullptr;
    if (rain_effect == item.effect.get()) rain_effect = nullptr;
    if (lighting_effect == item.effect.get()) lighting_effect = nullptr;
}

bool SferaNatureManager::attachRainEffect(IEffect& effect) {
    if (rain_effect != nullptr) return false;
    auto* rain = dynamic_cast<CRainEffect*>(&effect);
    if (rain == nullptr) { g_sfera_effect_manager.reportError("Unknown effect classID for rain."); return false; }
    if (effect.script_name != "rain") g_sfera_effect_manager.reportError("Unknown effect manager for 'rain' not found.");
    rain_effect = rain;
    rain_scale = 60.0f;
    rain->spawn_rate = rain_intensity * rain_scale;
    updateAmbientRainEffects();
    return true;
}

void SferaNatureManager::detachRainEffect() { for (auto& handle : ambient_rain_handles) remove_nature_effect_handle(handle); rain_effect = nullptr; }

bool SferaNatureManager::attachLightingEffect(IEffect& effect) {
    if (lighting_effect != nullptr) return false;
    auto* scripted = dynamic_cast<CScriptedEffect*>(&effect);
    if (scripted == nullptr) { g_sfera_effect_manager.reportError("Unknown effect classID for lighting."); return false; }
    lighting_effect = scripted;
    if (g_sfera_world_objects.controlled_object_handle != kInvalidHandle) { effect.cycle_length = static_cast<std::uint32_t>(std::trunc((1.0f - lighting_level) * 640.0f + 320.0f)); effect.lifetime_ticks = kInvalidHandle; }
    lighting_listener.change_tick = 1u; return true;
}

void SferaNatureManager::detachLightingEffect() { lighting_effect = nullptr; }

void SferaNatureManager::onLightingEffectChanged(IEffect& effect, SferaActiveEffect& item) {
    if (effect.effect_kind != IEffect::Kind::Scripted) return;
    auto& scripted = static_cast<CScriptedEffect&>(effect);
    if (scripted.lights.empty() || scripted.particle_systems.empty()) return;
    auto& particle = *scripted.particle_systems[0]; if (particle.render_slots.empty()) return;
    const SferaVec3F source = g_sfera_world_objects.objectPosition(item.source_handle); const SferaVec3F emitter = particle.render_slots[0].state.position; auto& light = scripted.lights[0]; light.position = {emitter.x - source.x, emitter.y - source.y, emitter.z - source.z};
    const float distance = std::sqrt(light.position.x * light.position.x + light.position.y * light.position.y + light.position.z * light.position.z); g_sfera_effect_manager.createActiveEffect(distance < 15.0f ? kLightingSoundNearId : kLightingSoundFarId, item.source_handle);
}

void SferaNatureManager::startRain() { if (rain_effect_handle == nullptr && g_sfera_world_objects.controlled_object_handle != kInvalidHandle) rain_effect_handle = g_sfera_effect_manager.createActiveEffect(kRainEffectId, g_sfera_world_objects.controlled_object_handle); }
void SferaNatureManager::stopRain() { remove_nature_effect_handle(rain_effect_handle); for (auto& handle : ambient_rain_handles) remove_nature_effect_handle(handle); }
void SferaNatureManager::startLighting() { if (lighting_effect_handle == nullptr && g_sfera_world_objects.controlled_object_handle != kInvalidHandle) lighting_effect_handle = g_sfera_effect_manager.createActiveEffect(kLightingEffectId, g_sfera_world_objects.controlled_object_handle); }
void SferaNatureManager::stopLighting() { remove_nature_effect_handle(lighting_effect_handle); }

void SferaNatureManager::setRainIntensity(float value) { if (rain_effect == nullptr || g_sfera_world_objects.controlled_object_handle == kInvalidHandle) return; rain_intensity = value; rain_effect->spawn_rate = rain_intensity * rain_scale; updateAmbientRainEffects(); }
void SferaNatureManager::setLightingLevel(float value) { if (lighting_effect == nullptr || g_sfera_world_objects.controlled_object_handle == kInvalidHandle) return; lighting_level = value; lighting_effect->cycle_length = static_cast<std::uint32_t>(std::trunc((1.0f - lighting_level) * 640.0f + 320.0f)); lighting_effect->lifetime_ticks = kInvalidHandle; }

void SferaNatureManager::updateAmbientRainEffects() {
    const auto source = g_sfera_world_objects.controlled_object_handle;
    if (source == kInvalidHandle) return;
    const std::size_t channels = rain_intensity == 0.0f ? 0 : rain_intensity <= 0.4f ? 1 : rain_intensity <= 0.8f ? 2 : 3;
    for (std::size_t index = 0; index < ambient_rain_handles.size(); ++index) {
        auto& handle = ambient_rain_handles[index];
        if (index >= channels) remove_nature_effect_handle(handle);
        else if (handle == nullptr) handle = g_sfera_effect_manager.createActiveEffect(kAmbientRainSoundId, source);
    }
}

void SferaEffectManager::registerEffectMeshFile(const char* filename) {
    if (filename == nullptr) return;
    std::ifstream stream;
    for (const auto& path : g_sfera_files.candidatePaths(filename)) {
        stream.open(path, std::ios::binary);
        if (stream.is_open()) break;
        stream.clear();
    }
    if (!stream.is_open()) return;
    stream.seekg(0, std::ios::end);
    const auto file_size = stream.tellg();
    std::vector<std::uint8_t> bytes;
    if (file_size < 0 || std::cmp_greater(static_cast<std::uint64_t>(file_size), std::numeric_limits<std::streamsize>::max())
        || static_cast<std::uint64_t>(file_size) > bytes.max_size()) return;
    bytes.resize(static_cast<std::size_t>(file_size));
    stream.seekg(0, std::ios::beg);
    if (!bytes.empty() && !stream.read(reinterpret_cast<char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()))) return;
    std::vector<std::shared_ptr<const SferaEffectMeshResource>> loaded;
    try {
        SferaBinary::Reader reader(bytes);
        const auto magic = reader.take(4);
        if (!std::equal(magic.begin(), magic.end(), "SSM1") || reader.read<std::uint32_t>() != 1) return;
        const auto mesh_count = reader.read<std::uint32_t>();
        reader.read<std::uint32_t>(); // Reserved file word.
        if (mesh_count > (bytes.size() - 16) / 52) return;
        loaded.reserve(mesh_count);
        const auto read_real = [](SferaBinary::Reader& input) {
            const float value = input.read<float>();
            if (!std::isfinite(value)) throw std::runtime_error("Nonfinite effect mesh coordinate");
            return value;
        };
        for (std::size_t mesh_index = 0; mesh_index < mesh_count; ++mesh_index) {
            auto mesh = std::make_shared<SferaEffectMeshResource>();
            const auto name = reader.take(32).first(31);
            mesh->name.assign(name.begin(), std::find(name.begin(), name.end(), 0));
            const auto vertex_count = reader.read<std::uint32_t>();
            const auto skipped_vertex_count = reader.read<std::uint32_t>();
            const auto uv_count = reader.read<std::uint32_t>();
            const auto face_count = reader.read<std::uint32_t>();
            reader.read<std::uint32_t>(); // Historical unused count, not an extra section.
            const auto payload_size = std::uint64_t{vertex_count} * 16 + std::uint64_t{skipped_vertex_count} * 12
                                    + std::uint64_t{uv_count} * 8 + std::uint64_t{face_count} * 32;
            if (payload_size > bytes.size()) return;
            // Establish the complete byte range before allocating any decoded arrays.
            SferaBinary::Reader payload(reader.take(static_cast<std::size_t>(payload_size)));
            mesh->vertices.resize(vertex_count);
            mesh->colors.resize(vertex_count);
            mesh->uv.resize(uv_count);
            mesh->faces.resize(face_count);
            for (auto& vertex : mesh->vertices) vertex = {read_real(payload), read_real(payload), read_real(payload)};
            payload.take(static_cast<std::size_t>(skipped_vertex_count) * 12);
            const auto read_indices = [&](auto member, std::size_t limit) {
                for (auto& face : mesh->faces) for (auto& index : face.*member) {
                    const auto value = payload.read<std::uint32_t>();
                    if (value >= limit) throw std::runtime_error("Invalid effect mesh index");
                    index = value;
                }
            };
            read_indices(&SferaEffectMeshResource::Face::vertices, mesh->vertices.size());
            for (auto& color : mesh->colors) {
                const auto channels = payload.take(4);
                std::copy(channels.begin(), channels.end(), color.channels.begin());
            }
            for (auto& uv : mesh->uv) for (auto& coordinate : uv) coordinate = read_real(payload);
            read_indices(&SferaEffectMeshResource::Face::uv, mesh->uv.size());
            loaded.push_back(std::move(mesh));
        }
    } catch (const std::runtime_error&) {
        return;
    }
    if (loaded.size() > mesh_resources.max_size() - mesh_resources.size()) throw std::length_error("Too many effect meshes");
    mesh_resources.reserve(mesh_resources.size() + loaded.size());
    mesh_resources.insert(mesh_resources.end(), std::make_move_iterator(loaded.begin()), std::make_move_iterator(loaded.end()));
}

void SferaEffectManager::reportLoadProgress(std::uint32_t progress) {
    GameInterface::loading_completed += progress;
    const int work = std::max(static_cast<int>(GameInterface::loading_total) - 80, 1);
    int percent = static_cast<int>(GameInterface::loading_completed) * 100 / work;
    percent = std::min(percent, 100);
    if (static_cast<std::uint32_t>(percent) == g_sfera_graphics_runtime.rebuild_percent) return;
    g_sfera_graphics_runtime.rebuild_percent = static_cast<std::uint32_t>(percent);
    auto* device_runtime = g_sfera_graphics_runtime.d3d_runtime.get();
    if (!device_runtime) return;
    SceneScope scene(*device_runtime);
    if (!scene) return;
    g_sfera_interface.setLoadingProgress(percent);
    scene.finish();
    device_runtime->waitForGpu();
    device_runtime->present();
}

void SferaEffectManager::initializeBloodEffect() {
    if (blood != nullptr) return;
    auto runtime = std::make_unique<SferaBloodEffectRuntime>();
    runtime->change_tick = 64u;
    runtime->texture_id = g_sfera_textures.find("fx_bspot");
    if (registerListener(kBloodEffectId, *runtime)) blood = std::move(runtime);
}
void SferaEffectManager::shutdownBloodEffect() {
    if (blood == nullptr) return;
    unregisterListener(*blood);
    blood.reset();
}

void SferaEffectManager::loadDefinitions() {
    namespace fs = std::filesystem;
    std::error_code error;
    const auto enumerate = [&](const fs::path& directory, const char* extension, auto&& callback) {
        if (!fs::exists(directory, error)) return;
        for (const auto& entry : fs::directory_iterator(directory, error)) {
            if (error || !entry.is_regular_file(error)) continue;
            if (SferaText::asciiEqual(entry.path().extension().string().c_str(), extension)) callback(entry.path());
        }
    };
    enumerate("Effects", ".ssm", [&](const fs::path& path) { const std::string value = path.string(); registerEffectMeshFile(value.c_str()); });
    std::uint32_t total_count = 0u; enumerate("Effects", ".sef", [&](const fs::path&) { ++total_count; }); enumerate("Players", ".sef", [&](const fs::path&) { ++total_count; });
    const auto initial_count = definitions.size();
    std::uint32_t processed_count = 0u;
    const auto load_group = [&](const fs::path& directory) {
        enumerate(directory, ".sef", [&](const fs::path& path) {
            auto effect = std::make_shared<CScriptedEffect>();
            effect->initializeScriptedState();
            try {
                if (effect->loadScript(path.string().c_str())) appendDefinition(std::move(effect));
            } catch (const std::logic_error& error) {
                reportError((path.string() + ": " + error.what()).c_str());
            }
            ++processed_count;
            const auto progress = total_count == 0u ? 30u : static_cast<std::uint32_t>(std::uint64_t{processed_count} * 30u / total_count);
            reportLoadProgress(progress);
        });
    };
    load_group("Effects"); load_group("Players");
    const auto loaded_count = definitions.size() - initial_count;
    const auto status = "Effects: loaded " + std::to_string(loaded_count) + " of " + std::to_string(total_count)
        + " SEF files from " + fs::current_path(error).string() + "\n";
    ::OutputDebugStringA(status.c_str());
    g_sfera_log_runtime.write(status.c_str());
    if (total_count == 0) reportError("No SEF files found in Effects or Players.");
}

void SferaEffectManager::destroyDefinitions() {
    definitions.clear();
    mesh_resources.clear();
}

bool SferaEffectManager::initialize() {
    if (initialized) return true;
    if (shutting_down) return false;
    const bool traceEnabled = diagnostics.enabled;
    diagnostics = {};
    diagnostics.enabled = traceEnabled;
    try {
        effect_listeners.reserve(16);
        initialize_particle_random_table(*this);
        loadDefinitions();
        render_order.reserve(kMaximumRenderSlots);
        initializeBloodEffect();
        auto next_nature = std::make_unique<SferaNatureManager>();
        if (!next_nature->initialize()) {
            shutdown();
            return false;
        }
        nature = std::move(next_nature);
        append_fixed_effect<CLightEffect>(*this, [](CLightEffect& effect) { effect.initializePreset(); effect.assignScriptName("light_source.eff"); });
        append_fixed_effect<CSpiralEffect>(*this, [](CSpiralEffect& effect) { effect.initializePreset(); effect.assignScriptName("spiral.effect0"); });
        append_fixed_effect<CMolEffect>(*this, [](CMolEffect& effect) { effect.initializePreset(); effect.assignScriptName("molniya.effect110"); });
        append_fixed_effect<CBladeEffect>(*this, [](CBladeEffect& effect) { effect.initializePreset(); effect.assignScriptName("blade"); });
        append_fixed_effect<CRainEffect>(*this, [](CRainEffect& effect) { effect.initializePreset(); effect.assignScriptName("rain"); });
        constexpr std::array lake_ids{kLakeEffectIdNear, kLakeEffectIdMiddle, kLakeEffectIdFar};
        for (std::size_t index = 0; index < lake_ids.size(); ++index) {
            append_fixed_effect<CGazerLakeEffect>(*this, [&](CGazerLakeEffect& effect) {
                effect.initializePreset(lake_ids[index], 5.0f * static_cast<float>(index + 1), kFixedLakeFlags);
                effect.assignScriptName("gazer.lake");
            });
        }
        render_slot_count = 0u;
        initialized = true;
        return true;
    } catch (...) {
        shutdown();
        throw;
    }
}

void SferaEffectManager::shutdown() {
    if (shutting_down) return;
    shutting_down = true;
    initialized = false;
    shutdownBloodEffect();
    clearListeners();
    if (nature != nullptr) nature->shutdown();
    // Final shutdown cannot be vetoed. Each active handle is invalidated before its storage is released.
    while (!active_effects.empty()) {
        const auto item = active_effects.front();
        retireEffect(*item);
    }
    nature.reset();
    destroyDefinitions();
    render_order.clear();
    render_slot_count = 0;
    shutting_down = false;
}

SferaActiveEffect* SferaEffectManager::createActiveEffect(std::uint32_t effect_id, std::uint32_t source_handle) {
    if (diagnostics.enabled) ++diagnostics.create_requests;
    if (shutting_down) { traceFailure(CreateFailure::Stopping, effect_id, source_handle); return nullptr; }
    if (active_effects.size() >= kMaximumActiveEffects) { traceFailure(CreateFailure::Capacity, effect_id, source_handle); return nullptr; }
    if (source_handle == 0u) reportError("EffectManager::createActiveEffect: zero source handle");
    std::shared_ptr<SferaActiveEffect> item;
    try {
        item = std::make_shared<SferaActiveEffect>();
        if (effect_id >= kSoundEffectIdBase) {
            if (!g_sfera_sound_runtime.interfaceAvailable()) { traceFailure(CreateFailure::SoundUnavailable, effect_id, source_handle); return nullptr; }
            item->resource = g_sfera_sound_runtime.createEffect(effect_id);
            if (item->resource == nullptr) { traceFailure(CreateFailure::Factory, effect_id, source_handle); return nullptr; }
        } else {
            item->definition = findDefinition(effect_id);
            if (item->definition == nullptr) { traceFailure(CreateFailure::MissingDefinition, effect_id, source_handle); return nullptr; }
            item->effect = item->definition->createEffectResources();
            if (item->effect == nullptr) { traceFailure(CreateFailure::Factory, effect_id, source_handle); return nullptr; }
            if (effects_enabled && item->effect->isEffectComplete()) { traceFailure(CreateFailure::FilteredType, effect_id, source_handle); return nullptr; }
        }
        item->state_flags = kUninitializedEffectState;
        item->source_handle = source_handle;
        item->listener_key = effect_id;
        item->viewer_distance = viewerDistance(source_handle);
        item->position = g_sfera_world_objects.objectPosition(source_handle);
        if (item->effect != nullptr) item->effect->position = item->position;
        if (!g_sfera_world_objects.attachEffect(source_handle, *item)) { traceFailure(CreateFailure::InvalidSource, effect_id, source_handle); return nullptr; }
        item->active = true;
        active_effects.push_back(item);
        if (item->effect != nullptr) {
            if (auto* listener = findListener(effect_id)) {
                item->effect->listener = listener;
                if (!listener->onEffectAttached(*item->effect, *item, item->viewer_distance)) {
                    traceFailure(CreateFailure::Listener, effect_id, source_handle);
                    removeActiveEffect(item.get());
                    if (item->active) retireEffect(*item);
                    return nullptr;
                }
            }
        }
        if (item->active && diagnostics.enabled) {
            ++diagnostics.created;
            if (diagnostics.details_written < 24u) {
                ++diagnostics.details_written;
                traceEffect("created", *item);
            }
        }
        return item->active ? item.get() : nullptr;
    } catch (const std::bad_alloc&) {
        traceFailure(CreateFailure::Allocation, effect_id, source_handle);
        if (item != nullptr && item->active) retireEffect(*item);
        return nullptr;
    } catch (...) {
        if (item != nullptr && item->active) retireEffect(*item);
        throw;
    }
}

SferaActiveEffect* SferaEffectManager::createActiveEffect(const char* script_name, std::uint32_t source_handle) {
    const auto definition = findDefinition(script_name);
    if (definition != nullptr && static_cast<int>(definition->effect_id) > 0) return createActiveEffect(definition->effect_id, source_handle);
    if (diagnostics.enabled) ++diagnostics.create_requests;
    traceFailure(CreateFailure::MissingDefinition, definition ? definition->effect_id : UINT32_MAX, source_handle, script_name);
    return nullptr;
}

bool SferaEffectManager::removeActiveEffect(SferaActiveEffect& item) { return removeActiveEffect(&item); }

bool SferaEffectManager::removeActiveEffect(SferaActiveEffect* handle) {
    const auto found = std::find_if(active_effects.begin(), active_effects.end(), [&](const auto& item) { return item.get() == handle; });
    if (found == active_effects.end()) return false;
    const auto item = *found;
    if (item->removing) return false;
    item->removing = true;
    try {
        if (item->effect != nullptr) {
            auto* listener = item->effect->listener != nullptr ? item->effect->listener : findListener(item->listener_key);
            if (listener != nullptr && !listener->onEffectDetached(*item->effect, *item)) {
                item->removing = false;
                return !item->active;
            }
        }
    } catch (...) {
        item->removing = false;
        throw;
    }
    retireEffect(*item);
    return true;
}

void SferaEffectManager::retireEffect(SferaActiveEffect& item) {
    if (!item.active) return;
    item.active = false;
    g_sfera_mbc_runtime.forgetNativeResource(&item);
    if (g_sfera_effect_manager.pending_effect == &item) g_sfera_effect_manager.pending_effect = nullptr;
    if (nature != nullptr) nature->forgetEffect(item);
    if (item.position_source == 0u) g_sfera_world_objects.detachEffect(item.source_handle, item);
    if (item.effect != nullptr) item.effect->listener = nullptr;
    if (item.resource != nullptr) item.resource->stop();
    item.age_ticks = item.listener_key = kInvalidHandle;
    std::erase_if(active_effects, [&](const auto& current) { return current.get() == &item; });
}

SferaActiveEffect::~SferaActiveEffect() {
    if (definition != nullptr && effect != nullptr) definition->recycleEffect(std::move(effect));
}

bool SferaEffectManager::setEffectParameters(std::uint32_t source_handle, std::span<const SferaEffectParameter> parameters) {
    auto* item = g_sfera_world_objects.firstEffect(source_handle);
    if (item == nullptr || item->effect == nullptr) return false;
    item->effect->setParameters(parameters);
    return true;
}

void SferaEffectManager::updateActiveEffect(SferaActiveEffect& item, std::uint16_t state_flags, float viewer_distance) {
    if (!item.active || shutting_down) return;
    if (item.resource != nullptr && item.effect == nullptr) {
        if (!g_sfera_sound_runtime.interfaceAvailable()) {
            removeActiveEffect(item);
            return;
        }
        const auto frame = item.position_source == 1u ? item.position : g_sfera_world_objects.objectPosition(item.source_handle);
        if (!item.sound_started) {
            item.resource->start(&frame, item.resource->startTime() < viewer_distance);
            item.sound_started = true;
        } else {
            item.resource->update(&frame, viewer_distance);
        }
        if (item.resource->isComplete()) removeActiveEffect(item);
        return;
    }
    auto* effect = item.effect.get();
    if (effect == nullptr) {
        removeActiveEffect(item);
        return;
    }
    item.age_ticks += item.listener_key >= kBloodEffectId && item.listener_key <= kBloodEffectIdLast ? 1u : 2u;
    if (effect->lifetime_ticks != kInvalidHandle && item.age_ticks >= effect->lifetime_ticks) {
        if (diagnostics.enabled) {
            ++diagnostics.expired;
            if (diagnostics.details_written < 24u) {
                ++diagnostics.details_written;
                traceEffect("expired", item);
            }
        }
        removeActiveEffect(item);
        return;
    }
    if (effect->listener != nullptr && item.age_ticks == effect->listener->change_tick) effect->listener->onEffectChanged(item.age_ticks, *effect, item);
    if (!item.active || shutting_down) return;
    if (item.listener_key == kBloodEffectId && effect->listener != nullptr) effect->listener->onEffectChanged(item.age_ticks, *effect, item);
    if (!item.active || shutting_down) return;
    SferaEffectFrames frames;
    if (item.position_source == 1u) {
        for (auto& frame : frames.positions) frame = item.position;
        for (auto& frame : frames.transforms) frame = SferaMatrix4x4F::identity();
    } else {
        frames = g_sfera_world_objects.buildEffectFrames(item.source_handle);
    }
    if (g_sfera_sound_runtime.interfaceAvailable()) effect->updateEffect({&frames.positions[0], viewer_distance});
    if (!item.active || shutting_down) return;
    const bool visible = state_flags == 0u;
    if (!effect->activation_blocked && !effect->activateEffect(visible)) {
        if (diagnostics.enabled) ++diagnostics.activation_rejected;
        if (!effect->deactivated) effect->deactivateEffect(((state_flags >> 1u) & 1u) != 0u);
        effect->activation_blocked = true;
        return;
    }
    if (effect->range_min != -1.0f) {
        const float environment = g_sfera_graphics_runtime.environment_factor;
        const bool outside = effect->range_max < effect->range_min
            ? environment > effect->range_min || environment < effect->range_max
            : environment > effect->range_min && environment < effect->range_max;
        if (outside) {
            if (diagnostics.enabled) ++diagnostics.daytime_rejected;
            if (!effect->deactivated) effect->deactivateEffect(false);
            return;
        }
    }
    if (effect->cycle_length != 0u && item.age_ticks >= effect->cycle_length) item.age_ticks %= effect->cycle_length;
    if ((state_flags & 2u) != 0u) {
        if (effect->resources_released) effect->renderEffect();
        effect->queryEffectState({frames.positions, static_cast<float>(item.age_ticks)});
        return;
    }
    if (effect->deactivated) effect->renderEffect();
    effect->initializeEffect({frames.positions, static_cast<float>(item.age_ticks), visible, frames.transforms});
}

void SferaEffectManager::updateActiveEffects() {
    if (updating || shutting_down) return;
    updating = true;
    if (diagnostics.enabled) ++diagnostics.updates;
    try {
        viewer_position = g_sfera_world_objects.referencePosition();
        if (flare_transition != FlareTransition::Idle) {
            int alpha = flare_alpha + (flare_transition == FlareTransition::FadeOut ? -kFlareAlphaStep : kFlareAlphaStep);
            if (alpha < 0) {
                alpha = 0;
                flare_transition = FlareTransition::Idle;
            } else if (alpha > kMaximumAlpha) {
                alpha = kMaximumAlpha;
                flare_transition = FlareTransition::Idle;
            }
            flare_alpha = alpha;
        }
        render_slot_count = 0u;
        bool refresh_visibility = false;
        if (++render_cycle == kVisibilityRefreshPeriod) {
            render_cycle = 0u;
            refresh_visibility = true;
        }
        const float visibility_distance = SphereRender::SceneRenderer::environment.fogParameters.z + 10.0f;
        // Callbacks can remove any item. Retain its storage until this update completes.
        const std::vector<std::shared_ptr<SferaActiveEffect>> snapshot(active_effects.begin(), active_effects.end());
        for (const auto& owner : snapshot) {
            auto& item = *owner;
            if (!item.active) continue;
            if (refresh_visibility || item.state_flags == kUninitializedEffectState) {
                item.state_flags = 0u;
                const auto position = item.position_source == 0u ? g_sfera_world_objects.objectPosition(item.source_handle) : item.position;
                item.viewer_distance = viewerDistance(position);
                if (visibility_distance < item.viewer_distance) item.state_flags |= 1u;
                if (item.effect != nullptr && last_processed_generation != generation && (item.state_flags & 1u) == 0u && item.effect->spatial_gate_enabled) {
                    if (!SphereRender::SceneRenderer::effectVisible(*item.effect, position)) item.state_flags |= 2u;
                    else item.state_flags &= static_cast<std::uint16_t>(~2u);
                }
            }
            if (diagnostics.enabled) {
                if ((item.state_flags & 1u) != 0u) ++diagnostics.distance_culled;
                if ((item.state_flags & 2u) != 0u) ++diagnostics.frustum_culled;
            }
            bool call_update = true;
            if (item.effect != nullptr && item.effect->activation_blocked) {
                if (item.state_flags == 0u) item.effect->activation_blocked = false;
                else if ((item.state_flags & 1u) != 0u) {
                    item.age_ticks += 2u;
                    if (item.effect->lifetime_ticks != kInvalidHandle && item.age_ticks >= item.effect->lifetime_ticks) {
                        if (diagnostics.enabled) ++diagnostics.expired;
                        removeActiveEffect(item);
                    }
                    call_update = false;
                }
            }
            if (call_update && item.active) updateActiveEffect(item, item.state_flags, item.viewer_distance);
        }
        g_sfera_server_wall.updateEffectRendering();
        if (blood != nullptr) blood->phase += 0.005f;
        sortRenderSlots();
        last_processed_generation = generation;
    } catch (...) {
        updating = false;
        throw;
    }
    updating = false;
}

// Process-wide services: constructed here in dependency order, released by the application.
SferaMbcRuntime g_sfera_mbc_runtime;
SferaFileManager g_sfera_files;
SferaErrorLogRuntime g_sfera_error_log_runtime;
SferaLogRuntime g_sfera_log_runtime;
SferaGraphicsRuntime g_sfera_graphics_runtime{.fog_distance = 100.0f, .saved_fog_distance = 50.0f, .lods_enabled = 1u, .hardware_cursor_enabled = 1u, .environment_factor = 0.8500000238418579f, .base_microtexture_id = UINT32_MAX, .view_scale = 1.0f, .post_effects_enabled = 1u, .rebuild_percent = UINT32_MAX};
SferaPolygon3F g_sfera_clipped_polygon;
SphereUI::FontFactory g_sfera_fonts;
SphereRender::MaterialLibrary g_sfera_materials;
SphereRender::TextureRepository g_sfera_textures;
SphereRender::ModelRepository g_sfera_models;
SphereWorld::WorldSpatialIndex g_sfera_world_spatial;
SphereWorld::ContactQuery g_sfera_contacts;
SphereWorld::Vegetation g_sfera_vegetation;
TerrainRenderer g_sfera_terrain_renderer;
SphereWorld::Motion g_sfera_motion;
SphereRender::GameCamera g_sfera_camera;
std::unique_ptr<ShadowMap> g_sfera_shadows;
GameFontAtlas g_sfera_font_runtime;
PlayerLists g_sfera_player_lists;
SferaInputDevices g_sfera_direct_input_runtime;
SferaServerWall g_sfera_server_wall{.texture_id = -1};
SferaConfigTextRuntime g_sfera_config_text_runtime;
WorldObjects g_sfera_world_objects{.max_occupied_object_handle = UINT32_MAX, .controlled_object_handle = UINT32_MAX};
SferaLightRuntime g_sfera_light_runtime;
SferaWeatherRuntime g_sfera_weather_runtime;

SferaEffectManager g_sfera_effect_manager{.render_cycle = 31u, .last_processed_generation = UINT32_MAX};
std::vector<TerrainAssets::Microtexture> TerrainAssets::microtextures;
std::array<TerrainAssets::MapCell, 6400> TerrainAssets::map{};
std::deque<TerrainRegion> TerrainAssets::regions;
std::vector<std::unique_ptr<GameUiElement>> WorldGuiControls::elements;
std::vector<SferaMatrix4x4F> SphereRender::ModelPose::bone_transforms;
std::array<SferaMatrix4x4F, 5> SphereRender::ModelPose::attachment_transforms{};
std::vector<SphereRender::SceneSortEntry> SphereRender::SceneRenderer::object_order;
std::vector<std::unique_ptr<GameUiWindow>> GameInterface::windows;
std::array<std::uint16_t, 65536> TerrainAssets::microtexture_remap = [] {
        std::array<std::uint16_t, 65536> values{};
        values.fill(std::numeric_limits<std::uint16_t>::max());
        return values;
    }();
SferaSoundRuntime g_sfera_sound_runtime;
SphereUI::InterfaceManager g_sfera_interface;
SferaNetworkRuntime g_sfera_network_runtime;

// Process ownership, transport, platform input and application lifetime.
namespace {
auto openLogFile(const std::string& path, const char* mode) {
        FILE* file = nullptr;
        if (fopen_s(&file, path.c_str(), mode) != 0) file = nullptr;
        return std::unique_ptr<FILE, decltype(&std::fclose)>(file, &std::fclose);
    }
unsigned mbc_field_minimum_bits(std::int8_t format) {
        const auto value = std::abs(static_cast<int>(format));
        if (value <= 32) return static_cast<unsigned>(value);
        if (value == 'g') return 6u;
        if (value >= 'i' && value <= 'k') return 12u;
        if (value == 'l') return 8u;
        return 0u;
    }
std::uint32_t mbc_array_count(std::uint32_t encodedCount, std::int8_t countFormat, std::int8_t elementFormat, std::size_t remainingBits) {
        if (countFormat != 'f') return encodedCount;
        // Some short server regions carry 0x40 even when 64 additional elements cannot be present.
        // Keep the full count when it fits; clear only that bit when the full count is impossible.
        const auto elementBits = mbc_field_minimum_bits(elementFormat);
        if (elementBits == 0u || encodedCount <= remainingBits / elementBits) return encodedCount;
        const auto compactCount = encodedCount & 0x3Fu;
        return compactCount <= remainingBits / elementBits ? compactCount : encodedCount;
    }
void dispatch_application_messages() {
        MSG message{};
        while (::PeekMessageA(&message, nullptr, 0, 0, PM_REMOVE)) {
            if (message.message == WM_QUIT) {
                SferaClientApplication::quit_requested = true;
                return;
            }
            ::TranslateMessage(&message);
            ::DispatchMessageA(&message);
        }
    }
void reset_pending_network_regions() noexcept {
        for (auto& slot : g_sfera_mbc_runtime.world_slots) {
            slot.reliable_bit_count = 0u;
            slot.unreliable_bit_count = 0u;
            slot.reliable_process = UINT32_MAX;
            slot.unreliable_process = UINT32_MAX;
            std::fill(std::begin(slot.reliable_payload), std::end(slot.reliable_payload), std::uint8_t{});
            std::fill(std::begin(slot.unreliable_payload), std::end(slot.unreliable_payload), std::uint8_t{});
        }
    }
}
void COutputLogDevice::setFilename(const char* path) {
    filename = path == nullptr ? "" : path;
    if (filename.empty()) return;
    auto file = openLogFile(filename, "wt");
    if (!file) return;
    const auto now = std::time(nullptr);
    char created_at[32]{};
    if (ctime_s(created_at, sizeof(created_at), &now) != 0) created_at[0] = '\0';
    std::fprintf(file.get(), "Sphere log file\nCreated: %s\n", created_at);
}
void COutputLogDevice::write(const char* text) {
    if (filename.empty() || text == nullptr) return;
    auto file = openLogFile(filename, "a+t");
    if (file) std::fprintf(file.get(), "- %s\n", text);
}
void CSphereError::write(const char* text) {
    SferaClientApplication::terminateWithError(text);
}
void SferaLogRuntime::write(const char* text) {
    if (path.empty() || text == nullptr) return;
    auto file = openLogFile(path, "at");
    if (!file) return;
    std::fputs(text, file.get());
    std::fflush(file.get());
}
void SferaLogRuntime::write(int number) {
    const std::string line = std::to_string(number) + '\n';
    write(line.c_str());
}
SferaInputDevices::SferaInputDevices() = default;
SferaInputDevices::~SferaInputDevices() { release(); }

void SferaInputDevices::initialize(HWND window) {
    release();
    const auto require = [](HRESULT result, const char* operation) { if (FAILED(result)) WorldDiagnostics::fail(operation); };
    Microsoft::WRL::ComPtr<IDirectInput8A> input;
    Microsoft::WRL::ComPtr<IDirectInputDevice8A> keyboard, mouse;
    require(::DirectInput8Create(::GetModuleHandleW(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8A,
        reinterpret_cast<void**>(input.GetAddressOf()), nullptr), "DirectInputCreate failed");
    require(input->CreateDevice(GUID_SysKeyboard, keyboard.GetAddressOf(), nullptr), "CreateDevice(keyboard) failed");
    require(input->CreateDevice(GUID_SysMouse, mouse.GetAddressOf(), nullptr), "CreateDevice(mouse) failed");
    for (auto* device : {keyboard.Get(), mouse.Get()}) {
        require(device->SetCooperativeLevel(window, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND), "SetCooperativeLevel failed");
    }
    require(keyboard->SetDataFormat(&c_dfDIKeyboard), "SetDataFormat(keyboard) failed");
    require(mouse->SetDataFormat(&c_dfDIMouse), "SetDataFormat(mouse) failed");
    DIPROPDWORD buffering{{sizeof(DIPROPDWORD), sizeof(DIPROPHEADER), 0, DIPH_DEVICE}, 8};
    require(keyboard->SetProperty(DIPROP_BUFFERSIZE, &buffering.diph), "SetProperty failed");
    keyboard->Acquire();
    mouse->Acquire();
    direct_input = std::move(input);
    keyboard_device = std::move(keyboard);
    mouse_device = std::move(mouse);
}

void SferaInputDevices::release() noexcept {
    for (auto* device : {std::addressof(keyboard_device), std::addressof(mouse_device)}) {
        if (*device) (*device)->Unacquire();
        device->Reset();
    }
    direct_input.Reset();
    std::fill(std::begin(keyboard_state), std::end(keyboard_state), 0u);
}

namespace {
    template<class Read, class Acquire>
    HRESULT readInputDevice(Read&& read, Acquire&& acquire) {
        const HRESULT result = read();
        if (result != DIERR_INPUTLOST && result != DIERR_NOTACQUIRED) return result;
        acquire();
        return read();
    }
}

void SferaInputDevices::focusChanged(bool focused) noexcept {
    std::fill(std::begin(keyboard_state), std::end(keyboard_state), 0u);
    view_adjust_state = modifier_08 = modifier_20 = 0;
    for (auto* device : {keyboard_device.Get(), mouse_device.Get()}) {
        if (!device) continue;
        if (focused) device->Acquire();
        else device->Unacquire();
    }
    if (keyboard_device) {
        DWORD count = INFINITE;
        keyboard_device->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), nullptr, &count, 0);
    }
}

void SferaInputDevices::pollKeyboard() {
    if (keyboard_device == nullptr || !SferaClientApplication::application_active) return;
    std::array<std::uint8_t, 256> state{};
    const auto result = readInputDevice(
        [&] { return keyboard_device->GetDeviceState(static_cast<DWORD>(state.size()), state.data()); },
        [&] { keyboard_device->Acquire(); });
    if (FAILED(result)) return;
    std::transform(state.begin(), state.end(), std::begin(keyboard_state), [](std::uint8_t value) { return value & SferaInputDevices::pressedMask; });
}

std::uint32_t SferaInputDevices::takeKeyPress() {
    if (keyboard_device == nullptr || !SferaClientApplication::application_active) return 0;
    for (;;) {
        DIDEVICEOBJECTDATA event{};
        DWORD count = 1;
        const auto result = readInputDevice(
            [&] { count = 1; return keyboard_device->GetDeviceData(sizeof(event), &event, &count, 0); },
            [&] { keyboard_device->Acquire(); });
        if (FAILED(result) || count == 0) return 0;
        if ((event.dwData & SferaInputDevices::pressedMask) != 0u) return event.dwOfs;
    }
}

SferaMouseInputState SferaInputDevices::pollMouse() {
    if (mouse_device == nullptr || !SferaClientApplication::application_active) return {};
    DIMOUSESTATE state{};
    const auto result = readInputDevice(
        [&] { return mouse_device->GetDeviceState(sizeof(state), &state); },
        [&] { if (CCursorManager::instance().activeCursor()->isInsideViewport()) mouse_device->Acquire(); });
    if (FAILED(result)) return {};
    const auto primary = ::GetSystemMetrics(SM_SWAPBUTTON) != 0 ? 1u : 0u;
    const auto buttons = ((state.rgbButtons[primary] & SferaInputDevices::pressedMask) != 0u ? 1u : 0u) | ((state.rgbButtons[1u - primary] & SferaInputDevices::pressedMask) != 0u ? 2u : 0u);
    return {state.lX, state.lY, buttons, state.lZ / WHEEL_DELTA};
}

namespace {
    template<std::size_t Size> void appendDiagnosticText(char (&destination)[Size], std::string_view text) {
        const auto end = std::find(destination, destination + Size, '\0');
        const std::size_t used = end - destination;
        if (used >= Size) { destination[Size - 1] = '\0'; return; }
        const auto copied = text.copy(destination + used, Size - used - 1);
        destination[used + copied] = '\0';
    }

}

void WorldDiagnostics::appendScriptContext(const char* text) {
    if (text) appendDiagnosticText(WorldDiagnostics::message, text);
}

void WorldDiagnostics::flushScriptContext() {
    if (const auto* context = scriptContext()) {
        appendScriptContext("\n");
        appendScriptContext(context);
    }
    warning(WorldDiagnostics::message);
    appendScriptContext("\n\n");
}

std::uint32_t WorldDiagnostics::inspectInstruction(std::uint16_t& module, std::uint32_t& offset, std::uint8_t* bytes, std::uint32_t& count) {
    module = std::numeric_limits<std::int16_t>::max();
    offset = 0u;
    const auto& vm = g_sfera_mbc_runtime;
    if (vm.process_index >= std::size(vm.processes)) { count = 0u; return 1u; }
    const auto& process = vm.processes[vm.process_index];
    const auto mismatch = vm.bytecode_base != process.codeData() ? codeBaseMismatch : 0u;
    const std::less<const std::uint8_t*> before;
    if (!process.codeData() || !vm.current_instruction_address || before(vm.current_instruction_address, process.codeData()) || !before(vm.current_instruction_address, process.codeData() + process.codeSize())) { count = 0u; return mismatch | 3u; }
    const std::uint32_t relative = vm.current_instruction_address - process.codeData();
    if (bytes) { count = std::min(count, process.codeSize() - relative); std::copy_n(vm.current_instruction_address, count, bytes); }
    const auto ranges = std::min<std::size_t>(process.code_range_count, std::size(process.code_range_ids));
    for (std::size_t index = 0; index < ranges; ++index) {
        const auto begin = process.code_range_begin[index];
        if (relative >= begin && relative - begin < process.code_range_size[index]) { module = process.code_range_ids[index]; offset = relative - begin; return mismatch; }
    }
    return mismatch | (process.code_range_count == std::size(process.code_range_ids) ? 2u : 3u);
}

void WorldDiagnostics::describeScript(bool includeTime) {
    auto& vm = g_sfera_mbc_runtime;
    auto& output = vm.diagnostic_context;
    output[0] = '\0';
    if (includeTime) {
        const auto now = std::time(nullptr);
        std::tm local{};
#ifdef _WIN32
        localtime_s(&local, &now);
#else
        localtime_r(&now, &local);
#endif
        std::strftime(output, sizeof(output), "%H:%M:%S ", &local);
    }
    std::uint16_t module;
    std::uint32_t offset, count = 16;
    std::uint8_t bytes[16];
    const auto status = inspectInstruction(module, offset, bytes, count);
    if ((status & ~codeBaseMismatch) == 1) { appendDiagnosticText(output, "PrcName,CodeOffs: unknown. (wrong pos)"); return; }
    if ((status & ~codeBaseMismatch) == 2) { appendDiagnosticText(output, "PrcName,CodeOffs: unknown. (modulesNum == MAX_MODULES_IN_PRC)"); return; }
    if ((status & ~codeBaseMismatch) == 3) { appendDiagnosticText(output, "PrcName,CodeOffs: unknown. (Offset not found)"); return; }
    char text[256];
    if (status & codeBaseMismatch) std::snprintf(text, sizeof(text), "Warn!!! pos = %d, sBaseCodePtr = %p, Prc[pos].baseCodePtr = %p. ", static_cast<int>(vm.process_index), static_cast<const void*>(vm.bytecode_base), static_cast<const void*>(vm.processes[vm.process_index].codeData()));
    else std::snprintf(text, sizeof(text), "module:%d, code:%d. ", module, static_cast<int>(offset));
    appendDiagnosticText(output, text);
    for (std::uint32_t index = 0; index < count; ++index) {
        std::snprintf(text, sizeof(text), "%x ", bytes[index]);
        appendDiagnosticText(output, text);
    }
    appendDiagnosticText(output, "\n");
}

void WorldDiagnostics::appendCallStack(char* output) {
    const auto& vm = g_sfera_mbc_runtime;
    std::string text;
    for (auto index = static_cast<int>(vm.execution_context_depth) - 1; index >= 0; --index) {
        const auto& context = vm.execution_context_stack[index];
        if (static_cast<int>(context.process_index) < 0) { text += "\nCall from C++\n"; continue; }
        if (context.process_index >= std::size(vm.processes)) { text += "\nInvalid call context\n"; break; }
        const auto& process = vm.processes[context.process_index];
        if (context.process_id != process.process_id) { text += "\nError in prc call stack\n"; break; }
        if (context.process_lifetime != process.lifetime || context.program_index < 0 || static_cast<std::size_t>(context.program_index) >= process.programs.size()) { text += "\nExpired call context\n"; break; }
        const auto& program = process.programs[context.program_index];
        text += "\nPrevious prc: "; text += process.name; text += "\nProgram: "; text += program.name; text += '\n';
    }
    if (output == vm.diagnostic_context) appendDiagnosticText(g_sfera_mbc_runtime.diagnostic_context, text);
    else std::memcpy(output + std::strlen(output), text.c_str(), text.size() + 1);
}

const char* WorldDiagnostics::scriptContext() {
    if (static_cast<int>(g_sfera_mbc_runtime.dispatch_slot) < 0) return nullptr;
    auto& vm = g_sfera_mbc_runtime;
    describeScript(true);
    const auto& program = vm.program_table_base[vm.program_index];
    char message[1024];
    std::snprintf(message, sizeof(message), "MBC-file: %s\nProgram: %s\nCall's depth: %d\nAddress: 0x%08X\n", vm.processes[vm.process_index].name, program.name, program.callDepth, static_cast<std::uint32_t>(vm.current_instruction_address - vm.bytecode_base) + 32u);
    appendDiagnosticText(vm.diagnostic_context, message);
    appendCallStack(vm.diagnostic_context);
    return vm.diagnostic_context;
}

namespace {
    constexpr WPARAM kSystemCommandMask = 0xFFF0u;

LRESULT CALLBACK main_window_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
    try {
    switch (message) {
    case WM_ACTIVATEAPP:
        SferaClientApplication::application_active = wparam != 0;
        g_sfera_direct_input_runtime.focusChanged(wparam != 0);
        CCursorManager::focusChanged(wparam != 0);
        if (wparam == 0) {
            g_sfera_direct_input_runtime.mouse = {};
            g_sfera_direct_input_runtime.character_queue.clear();
            g_sfera_direct_input_runtime.key_queue.clear();
            g_sfera_direct_input_runtime.virtual_key = 0;
            g_sfera_direct_input_runtime.character = 0;
            g_sfera_interface.drag_drop_active = false;
        }
        g_sfera_sound_runtime.refreshMusicVolume();
        g_sfera_sound_runtime.volume_refresh_frames = 0.0;
        g_sfera_sound_runtime.volume_refresh_active = true;
        return 0;
    case WM_CAPTURECHANGED:
    case WM_CANCELMODE:
        g_sfera_interface.drag_drop_active = false;
        if (::GetCapture() == window) ::ReleaseCapture();
        return 0;
    case WM_QUERYENDSESSION:
        ::PostQuitMessage(0);
        return 0;
    case WM_CLOSE:
        ::PostQuitMessage(0);
        return 0;
    case WM_SETCURSOR:
        if (CCursorManager::hasActiveCursor()) {
            return TRUE;
        }
        return 0;
    case WM_KEYDOWN:
        if (g_sfera_direct_input_runtime.binding_capture != 0u) {
            g_sfera_direct_input_runtime.binding_key = static_cast<std::uint32_t>(wparam);
            return 0;
        }
        if (g_sfera_direct_input_runtime.text_filter != 0u) {
            const std::uint32_t key = static_cast<std::uint32_t>(wparam);
            if (key < 256u && g_sfera_font_runtime.glyphs[key].defined != 0u && g_sfera_direct_input_runtime.allowed_glyphs[key] == 0u) {
                return 0;
            }
        }
        if (g_sfera_direct_input_runtime.key_queue.size() < 30u) {
            g_sfera_direct_input_runtime.key_queue.push_back(static_cast<std::uint32_t>(wparam));
        }
        return 0;
    case WM_CHAR: {
        const std::uint32_t ch = static_cast<std::uint32_t>(wparam);
        if (ch < 256u && g_sfera_font_runtime.glyphs[ch].defined == 1u && g_sfera_direct_input_runtime.character_queue.size() < 30u) {
            g_sfera_direct_input_runtime.character_queue.push_back(ch);
        }
        return 0;
    }
    case WM_SYSCOMMAND: {
        const WPARAM command = wparam & kSystemCommandMask;
        if (command == SC_SCREENSAVE || command == SC_MONITORPOWER) {
            return 0;
        }
        return ::DefWindowProcA(window, message, wparam, lparam);
    }
    default: return ::DefWindowProcA(window, message, wparam, lparam);
    }
    } catch (...) {
        SferaClientApplication::interrupted = true;
        return 0;
    }
}
}

void GameInterface::registerNativeWindowClass() {
    WNDCLASSEXA windowClass{};
    windowClass.cbSize = sizeof(windowClass);
    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpfnWndProc = &main_window_proc;
    windowClass.hInstance = SferaClientApplication::instance_handle;
    windowClass.hIcon = ::LoadIconA(windowClass.hInstance, MAKEINTRESOURCEA(113));
    windowClass.hCursor = ::LoadCursorW(nullptr, IDC_ARROW);
    windowClass.hbrBackground = reinterpret_cast<HBRUSH>(::GetStockObject(BLACK_BRUSH));
    windowClass.lpszClassName = nativeWindowClassName;
    windowClass.hIconSm = windowClass.hIcon;
    if (::RegisterClassExA(&windowClass) == 0) WorldDiagnostics::fail("RegisterClassEx() failed! => init_main_window_class()");
    SferaClientApplication::window_class_registered = true;
}

void GameInterface::createNativeWindow() {
    const auto desktopWidth = ::GetSystemMetrics(SM_CXSCREEN);
    const auto desktopHeight = ::GetSystemMetrics(SM_CYSCREEN);
    SferaClientApplication::desktop_width = desktopWidth;
    SferaClientApplication::desktop_height = desktopHeight;
    auto& graphics = g_sfera_graphics_runtime;
    graphics.display_width = static_cast<std::uint32_t>(std::max(800, graphics.display_width));
    graphics.display_height = static_cast<std::uint32_t>(std::max(600, graphics.display_height));
    auto width = graphics.display_width;
    auto height = graphics.display_height;
    DWORD style = WS_POPUP;
    int left = 0, top = 0;
    if (SferaClientApplication::windowed) {
        const DWORD windowedStyle = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
        RECT rectangle{0, 0, width, height};
        if (!::AdjustWindowRect(&rectangle, windowedStyle, FALSE)) WorldDiagnostics::fail("AdjustWindowRect() failed! => init_main_window()");
        const auto outerHeight = rectangle.bottom - rectangle.top;
        if (outerHeight >= desktopHeight) SferaClientApplication::windowed = false;
        else {
            style = windowedStyle;
            width = rectangle.right - rectangle.left;
            height = outerHeight;
            left = (desktopWidth - width) / 2;
            top = (desktopHeight - height) / 2;
        }
    }
    const auto instance = SferaClientApplication::instance_handle;
    const auto window = ::CreateWindowExA(0, nativeWindowClassName, "Sphere", style, left, top, width, height, nullptr, nullptr, instance, nullptr);
    SferaClientApplication::main_window = window;
    if (window == nullptr) WorldDiagnostics::fail("CreateWindowEx() failed! => init_main_window()");
    ::ShowWindow(window, SW_SHOWNORMAL);
    ::InvalidateRect(window, nullptr, TRUE);
    ::UpdateWindow(window);
    ::BringWindowToTop(window);
}

void SferaClientApplication::releaseStorage() noexcept {
    if (lifecycle == Lifecycle::Running) shutdown();
    g_sfera_contacts.clear();
    if (!SferaClientApplication::storage_initialized) return;
    SferaClientApplication::storage_initialized = false;
    try { g_sfera_world_objects.clear(); g_sfera_vegetation.clear(); } catch (...) { ::OutputDebugStringA("World storage cleanup failed"); }
    SphereUI::InterfaceConfiguration::close();
    g_sfera_interface.options.edited_chat_fonts.clear();
    g_sfera_interface.options.saved_chat_fonts.clear();
    SphereRender::SceneRenderer::object_order.clear();
    SphereRender::ModelPose::attachment_transforms.fill({});
    SphereRender::ModelPose::bone_transforms.clear();
    g_sfera_light_runtime.invalidateActiveLights();
    g_sfera_light_runtime.visible_handles.clear();
    g_sfera_light_runtime.handles.clear();
    WorldGuiControls::elements.clear();
    GameInterface::windows.clear();
    GameInterface::active_window = UINT32_MAX;
    try { TerrainAssets::releaseAll(); } catch (...) { ::OutputDebugStringA("Terrain storage cleanup failed"); }
    g_sfera_world_spatial = {};
    TerrainAssets::regions.clear();
    TerrainAssets::map.fill({});

    g_sfera_effect_manager.render_slots.clear();
    g_sfera_error_log_runtime.clear();
}

const std::array<char32_t, 256>& SferaText::unicodeCp1251() {
    // Win32 remains authoritative for undefined code-page bytes; initialization is thread-safe.
    static const auto table = [] {
        std::array<char32_t, 256> result{};
        for (std::size_t byte = 0; byte < result.size(); ++byte) {
            const char input = static_cast<char>(byte); wchar_t character = 0;
            if (::MultiByteToWideChar(1251u, 0u, &input, 1, &character, 1) != 1) character = static_cast<wchar_t>(byte);
            result[byte] = character;
        }
        return result;
    }();
    return table;
}
const std::array<std::uint8_t, 256>& SferaText::lowercaseCp1251() {
    static const auto table = [] {
        const auto& unicode = unicodeCp1251();
        std::array<std::uint8_t, 256> result{};
        for (std::size_t byte = 0; byte < result.size(); ++byte) {
            auto character = unicode[byte];
            if (character >= U'A' && character <= U'Z') character += U'a' - U'A';
            else if (character >= U'\u0410' && character <= U'\u042f') character += U'\u0430' - U'\u0410';
            else if (character == U'\u0401') character = U'\u0451';
            const auto found = std::find(unicode.begin(), unicode.end(), character);
            result[byte] = found == unicode.end() ? static_cast<std::uint8_t>(byte) : static_cast<std::uint8_t>(found - unicode.begin());
        }
        return result;
    }();
    return table;
}
std::string SferaText::resourceKey(std::string_view name) {
    std::string result(name);
    const auto& lowercase = lowercaseCp1251();
    for (char& byte : result) byte = static_cast<char>(lowercase[static_cast<std::uint8_t>(byte)]);
    return result;
}

const char* SferaText::findInsensitive(const char* text, const char* needle) {
    if (!text || !needle || !*needle) return nullptr;
    const std::string_view source(text), pattern(needle);
    const auto found = std::search(source.begin(), source.end(), pattern.begin(), pattern.end(),
        [](unsigned char a, unsigned char b) { return asciiFold(a) == asciiFold(b); });
    return found == source.end() ? nullptr : text + (found - source.begin());
}

const char* SferaText::fileName(const char* path) {
    if (path == nullptr) return "";
    const auto* separator = std::strrchr(path, '\\');
    return separator == nullptr ? path : separator + 1;
}

std::uint8_t* SferaMbcRuntime::memoryAt(std::uint32_t address, std::size_t size, SferaMbcProcessRecord* process) const {
    if (address < mappedAddressBegin) {
        auto* source = process != nullptr ? process : active_process;
        if (source == nullptr || source->memory.data() == nullptr || address > source->memory.size() || size > source->memory.size() - address) throw std::out_of_range("Script memory access outside process memory");
        return source->memory.data() + address;
    }
    auto entry = mapped_memory.upper_bound(address);
    if (entry == mapped_memory.begin()) throw std::out_of_range("Unknown script memory address");
    --entry;
    const auto& region = entry->second;
    const std::size_t offset = address - entry->first;
    if (offset > region.size || size > region.size - offset) throw std::out_of_range("Script memory access outside mapped region");
    if (region.process != nullptr) {
        if (region.process->memory.data() == nullptr || offset > region.process->memory.size() || size > region.process->memory.size() - offset) throw std::out_of_range("Script process memory is no longer available");
        return region.process->memory.data() + offset;
    }
    return const_cast<std::uint8_t*>(region.data) + offset;
}

std::span<std::uint8_t> SferaMbcRuntime::memoryRange(std::uint32_t address, SferaMbcProcessRecord* process) const {
    if (address < mappedAddressBegin) {
        const auto* source = process ? process : active_process;
        if (!source || address > source->memory.size()) throw std::out_of_range("Invalid process memory range");
        return {memoryAt(address, 0, process), source->memory.size() - address};
    }
    auto entry = mapped_memory.upper_bound(address);
    if (entry == mapped_memory.begin()) throw std::out_of_range("Unknown mapped memory range");
    --entry;
    const auto offset = std::size_t(address - entry->first);
    const auto& region = entry->second;
    const auto size = region.process ? std::min(region.size, region.process->memory.size()) : region.size;
    if (offset > size) throw std::out_of_range("Invalid mapped memory range");
    return {memoryAt(address, size - offset), size - offset};
}
std::uint64_t SferaMbcRuntime::memoryLifetime(std::uint32_t address) const {
    if (address < mappedAddressBegin) return 0;
    auto entry = mapped_memory.upper_bound(address);
    if (entry == mapped_memory.begin()) throw std::out_of_range("Unknown mapped memory lifetime");
    --entry;
    if (address - entry->first >= entry->second.size) throw std::out_of_range("Invalid mapped memory lifetime");
    return entry->second.lifetime;
}
std::span<std::uint8_t> SferaMbcRuntime::sliceBytes(const SferaSliceReference32& slice) const {
    auto bytes = memoryRange(slice.base);
    if (slice.begin != 0) {
        if (slice.base < slice.begin || slice.base > slice.end) throw std::out_of_range("Invalid bounded script slice");
        const auto count = std::uint64_t(slice.end) - slice.base + 1;
        if (count < bytes.size()) bytes = bytes.first(static_cast<std::size_t>(count));
    }
    return bytes;
}

char* SferaMbcRuntime::textAt(std::uint32_t address) const {
    const auto bytes = memoryRange(address);
    if (std::find(bytes.begin(), bytes.end(), 0) == bytes.end()) throw std::out_of_range("Unterminated script string");
    return reinterpret_cast<char*>(bytes.data());
}

std::uint32_t SferaMbcRuntime::addMemoryRegion(MemoryRegion region) {
    region.size = std::max<std::size_t>(region.size, 1);
    if (region.size >= mappedAddressBegin) throw std::length_error("Mapped script region too large");
    std::uint64_t candidate = mappedAddressBegin;
    for (const auto& [address, existing] : mapped_memory) {
        if (candidate + region.size < address) break;
        candidate = std::uint64_t(address) + existing.size + 1;
    }
    if (candidate + region.size > UINT32_MAX - 3u) throw std::length_error("Script address space exhausted");
    const std::uint32_t address = candidate;
    if (next_memory_lifetime == 0) throw std::overflow_error("Memory mapping lifetime exhausted");
    region.lifetime = next_memory_lifetime++;
    mapped_memory.emplace(address, region);
    return address;
}

std::uint32_t SferaMbcRuntime::mapMemory(const void* data, std::size_t size, const void* owner) {
    if (data == nullptr) return 0;
    const auto address = reinterpret_cast<std::uintptr_t>(data);
    if (active_process != nullptr && active_process->memory.data() != nullptr) {
        const auto base = reinterpret_cast<std::uintptr_t>(active_process->memory.data());
        if (address >= base && address - base <= active_process->memory.size() && size <= active_process->memory.size() - (address - base)) return address - base;
    }
    for (const auto& [mapped, region] : mapped_memory) {
        const auto* source = region.process != nullptr ? region.process->memory.data() : region.data;
        const auto base = reinterpret_cast<std::uintptr_t>(source);
        if (source != nullptr && address >= base && address - base <= region.size && size <= region.size - (address - base)) return mapped + static_cast<std::uint32_t>(address - base);
    }
    return addMemoryRegion({static_cast<const std::uint8_t*>(data), size, nullptr, owner});
}

std::uint32_t SferaMbcRuntime::mapProcessMemory(SferaMbcProcessRecord& process) {
    if (&process == active_process) return 0;
    for (const auto& [address, region] : mapped_memory) if (region.process == &process && region.size >= process.memory.size()) return address;
    return addMemoryRegion({nullptr, process.memory.size(), &process, &process});
}

SferaSliceReference32 SferaMbcRuntime::rebaseSlice(SferaSliceReference32 slice, SferaMbcProcessRecord& source) {
    if (slice.base == 0 || slice.base >= mappedAddressBegin || &source == active_process) return slice;
    if (slice.base > source.memory.size() || (slice.begin != 0 && (slice.begin > source.memory.size() || slice.end >= source.memory.size()))) throw std::out_of_range("Invalid cross-process script slice");
    const auto base = mapProcessMemory(source);
    slice.base += base;
    if (slice.begin != 0) { slice.begin += base; slice.end += base; }
    return slice;
}

void SferaMbcRuntime::forgetMemory(const void* owner) { if (owner != nullptr) std::erase_if(mapped_memory, [owner](const auto& entry) { return entry.second.owner == owner; }); }

void SferaMbcRuntime::forgetNativeResource(const NativeResource& resource) {
    const auto entry = native_resource_ids.find(resource);
    if (entry == native_resource_ids.end()) return;
    native_resources.erase(entry->second);
    native_resource_ids.erase(entry);
}

bool SferaSliceReference32::contains(std::uint32_t length, bool allowNull) const { return (allowNull || (base >= 4 && base < UINT32_MAX - 3)) && (begin == 0 || (base >= begin && base <= end && (length == 0 || length - 1 <= end - base))); }
void SferaSliceReference32::diagnoseRange(std::uint32_t length) {
    WorldDiagnostics::describeScript(true);
    char message[2048];
    if (length == 0) std::snprintf(message, sizeof(message), "%s\n Slice out of range! ptr = %d, begin = %d, end = %d", g_sfera_mbc_runtime.diagnostic_context, static_cast<int>(base), static_cast<int>(begin), static_cast<int>(end + 1));
    else std::snprintf(message, sizeof(message), "%s\n Slice out of range! ptr = %d, ptr+offset = %d, begin = %d, end = %d", g_sfera_mbc_runtime.diagnostic_context, static_cast<int>(base), static_cast<int>(base + length), static_cast<int>(begin), static_cast<int>(end + 1));
    WorldDiagnostics::warning(message);
    // The interpreter diagnoses and extends the recorded bounds; it does not clamp the pointer.
    if (base == 0 || begin == 0 || (base >= begin && base <= end)) return;
    if (static_cast<int>(base) < static_cast<int>(begin)) begin = base;
    else if (static_cast<int>(base + length - 1) > static_cast<int>(end)) end = base + length - 1;
}
bool SferaMbcValue::isPointer() const { return type % 16 != 0; }
int SferaMbcValue::integer() const { return std::bit_cast<int>(value.base); }
float SferaMbcValue::real() const { return std::bit_cast<float>(value.base); }
int SferaMbcValue::truncate(double number) {
    if (!std::isfinite(number) || double(number) < double(INT32_MIN) || double(number) >= double(INT32_MAX) + 1.0) return INT32_MIN;
    return number;
}
int SferaMbcValue::asInteger() const {
    switch (static_cast<std::uint8_t>(type)) {
        case Byte: return static_cast<std::int8_t>(value.base);
        case Real: return truncate(real());
        default: return integer();
    }
}
float SferaMbcValue::asReal() const { return static_cast<std::uint8_t>(type) == Real ? real() : static_cast<float>(asInteger()); }
void SferaMbcValue::setReal(float number) { value.base = std::bit_cast<std::uint32_t>(number); }
void SferaMbcValue::detach() { source = {UINT32_MAX, 1, 1}; }
SferaSliceReference32& SferaMbcValue::asSlice() { if (!isPointer()) value.begin = value.end = 0; return value; }

bool SferaMbcRuntime::reportError(const char* message) {
    WorldDiagnostics::scriptContext();
    auto& log = g_sfera_log_runtime;
    log.write("\n---exit_inter start---\nMBINTER MESSAGE:");
    log.write(message);
    log.write("\n");
    log.write(diagnostic_context);
    log.write("---exit_inter end-----\n");
    execution_failed = true;
    if (process_index == 0) { CSphereError output; output.write(diagnostic_context); }
    return processes[0].activateProgram("EError");
}
bool SferaMbcRuntime::reportError(const char* prefix, const char* suffix) { const auto message = std::string(prefix) + suffix; return reportError(message.c_str()); }
int SferaMbcRuntime::popInteger() {
    if (call_frame_depth >= std::size(frame_stack_base) || value_stack_size <= frame_stack_base[call_frame_depth]) { reportError("popint(): stack underflow"); return 0; }
    return g_sfera_mbc_runtime.values[--value_stack_size].asInteger();
}
SferaSliceReference32& SferaMbcRuntime::popSlice() {
    if (call_frame_depth >= std::size(frame_stack_base) || value_stack_size <= frame_stack_base[call_frame_depth]) { reportError("popsliceref(): stack underflow"); g_sfera_mbc_runtime.slice_fallback = {}; return g_sfera_mbc_runtime.slice_fallback; }
    return g_sfera_mbc_runtime.values[--value_stack_size].asSlice();
}
int SferaMbcRuntime::nextInteger() {
    if (argument_cursor >= argument_end) { reportError("Too few parameters"); return 0; }
    return g_sfera_mbc_runtime.values[argument_cursor++].asInteger();
}
float SferaMbcRuntime::nextReal() {
    if (argument_cursor >= argument_end) { reportError("Too few parameters"); return 0; }
    return g_sfera_mbc_runtime.values[argument_cursor++].asReal();
}
SferaSliceReference32& SferaMbcRuntime::nextSliceReference(const char* diagnostic) {
    if (argument_cursor >= argument_end) { reportError(diagnostic); g_sfera_mbc_runtime.sliceup_fallback = {}; return g_sfera_mbc_runtime.sliceup_fallback; }
    return g_sfera_mbc_runtime.values[argument_cursor++].asSlice();
}
SferaSliceReference32 SferaMbcRuntime::nextSlice() { return nextSliceReference("popsliceup(): stack underflow"); }
void SferaMbcRuntime::pushInteger(std::uint32_t number) {
    if (value_stack_size >= std::size(g_sfera_mbc_runtime.values)) { reportError("Stack overflow"); return; }
    auto& slot = g_sfera_mbc_runtime.values[value_stack_size++];
    slot.type = SferaMbcValue::Integer;
    slot.value.base = number;
    slot.detach();
}
void SferaMbcRuntime::pushReal(float number) {
    if (value_stack_size >= std::size(g_sfera_mbc_runtime.values)) { reportError("Stack overflow"); return; }
    auto& slot = g_sfera_mbc_runtime.values[value_stack_size++];
    slot.type = SferaMbcValue::Real;
    slot.setReal(number);
    slot.detach();
}
void SferaMbcRuntime::pushSlice(const SferaSliceReference32& value, SferaMbcValue::Type type) {
    if (value_stack_size >= std::size(g_sfera_mbc_runtime.values)) { reportError("Stack overflow"); return; }
    auto& slot = g_sfera_mbc_runtime.values[value_stack_size++];
    slot.type = type;
    slot.value = value;
    slot.detach();
}

void SferaMbcRuntime::enqueueProcess(int index, SferaMbcProcessRecord& process) {
    if (process.execution_linked || index < 0) return;
    ++execution_chain_count;
    process.execution_linked = true;
    process.execution_prev_index = -1;
    if (execution_chain_tail < 0) {
        if (execution_chain_head >= 0) g_sfera_log_runtime.write("internal error 34096874309");
        execution_chain_head = execution_chain_tail = index;
        process.execution_next_index = -1;
    } else {
        if (execution_chain_head < 0) { reportError("internal error 04975350934760"); return; }
        processes[execution_chain_head].execution_prev_index = index;
        process.execution_next_index = execution_chain_head;
        execution_chain_head = index;
    }
}
void SferaMbcRuntime::dequeueProcess(SferaMbcProcessRecord& process) {
    if (!process.execution_linked) return;
    --execution_chain_count;
    process.execution_linked = false;
    if (process.execution_next_index != -1) processes[process.execution_next_index].execution_prev_index = process.execution_prev_index;
    else execution_chain_tail = process.execution_prev_index;
    if (process.execution_prev_index != -1) processes[process.execution_prev_index].execution_next_index = process.execution_next_index;
    else execution_chain_head = process.execution_next_index;
}
void SferaMbcProcessRecord::linkProgram(std::uint32_t index) {
    auto& program = programs.data()[index];
    const std::int16_t previous = program_map_b[program.priority];
    if (previous < 0) { program_map_a[program.priority] = index; program.previous_program = index; }
    else { programs.data()[previous].next_program = index; program.previous_program = previous; }
    program_map_b[program.priority] = index;
    program.next_program = index;
    programs_queued = true;
    g_sfera_mbc_runtime.enqueueProcess(static_cast<int>(process_id), *this);
}
bool SferaMbcProcessRecord::activateProgram(int index) {
    if (index < 0 || static_cast<std::uint32_t>(index) >= programs.size() || programs.data() == nullptr) return false;
    auto& program = programs.data()[index];
    if (program.state != 1) { linkProgram(static_cast<std::uint32_t>(index)); program.instruction_offset = program.entry_offset; }
    program.state = 1;
    programs_queued = true;
    return true;
}
bool SferaMbcProcessRecord::activateProgram(const char* name) {
    if (programs.data() == nullptr || name == nullptr) return false;
    for (std::uint32_t index = 0; index < programs.size(); ++index) {
        if (std::strcmp(programs.data()[index].name, name) != 0) continue;
        activateProgram(static_cast<int>(index));
        g_sfera_mbc_runtime.enqueueProcess(static_cast<int>(process_id), *this);
        return true;
    }
    return false;
}

bool SferaMbcRuntime::executeInstruction(Instruction instruction) {
    auto& stack = g_sfera_mbc_runtime.values;
    switch (instruction) {
        case Instruction::InvokeBuiltin: {
            const auto function = readOperand<Builtin>();
            argument_end = value_stack_size; value_stack_size -= argument_count; argument_cursor = value_stack_size;
            if (!executeBuiltin(function)) throw std::runtime_error("unsupported MBInter bytecode opcode");
            break;
        }
        case Instruction::ReturnFunction: returnFromFunction(); break;
        case Instruction::BindParameters: bindParameters(); break;
        case Instruction::DispatchCommand: break; // No queued-command producer in this executable; retain opcode 201 as a no-op.
        case Instruction::LoadVariable: {
            const auto type = readOperand<SferaMbcValue::Type>();
            const auto offset = readOperand<std::uint32_t>();
            const auto width = type == SferaMbcValue::Byte ? sizeof(std::int8_t) : type == SferaMbcValue::Integer || type == SferaMbcValue::Real ? sizeof(std::uint32_t) : sizeof(SferaSliceReference32);
            pushReference(type, {offset, offset, offset + static_cast<std::uint32_t>(width) - 1}, true);
            if (type == SferaMbcValue::Address) stack[value_stack_size - 1].value = readMemory<SferaSliceReference32>(offset);
            break;
        }
        case Instruction::JumpIfFalse: case Instruction::JumpIfFalseShort: {
            const auto condition = popInteger();
            const auto width = instruction == Instruction::JumpIfFalse ? sizeof(int) : sizeof(std::int16_t);
            if (condition) instruction_cursor += width;
            else { const auto offset = instruction == Instruction::JumpIfFalse ? readOperand<int>() : readOperand<std::int16_t>(); instruction_cursor += std::ptrdiff_t(offset) - static_cast<std::ptrdiff_t>(width); }
            break;
        }
        case Instruction::ArrayElement: case Instruction::SliceElement: {
            const auto type = readOperand<SferaMbcValue::Type>();
            const auto stride = readOperand<std::uint16_t>();
            SferaSliceReference32* source = instruction == Instruction::SliceElement ? &popSlice() : nullptr;
            auto index = popInteger();
            const auto offset = source ? 0u : readOperand<std::uint32_t>();
            const auto width = source ? 0u : readOperand<std::uint32_t>();
            const auto signedCount = readOperand<int>();
            const auto count = signedCount < 0 ? 0u - static_cast<std::uint32_t>(signedCount) : static_cast<std::uint32_t>(signedCount);
            if (index < 0 || index >= static_cast<int>(count)) {
                WorldDiagnostics::describeScript(true);
                char message[2048];
                std::snprintf(message, sizeof(message), source ? "%s\nArray2 boundary error: array size = %d, index = %d" : "%s\nArray boundary error: array size = %d, index = %d", diagnostic_context, static_cast<int>(count), index);
                WorldDiagnostics::warning(message);
                if (source) index = index >= 0 && static_cast<int>(count - 1) < 0 ? 0 : static_cast<int>(count - 1);
                else index = index < 0 ? 0 : static_cast<int>(count - 1);
            }
            const auto displacement = static_cast<std::uint32_t>(stride) * static_cast<std::uint32_t>(index);
            if (source) { source->base += displacement; pushReference(type, *source, signedCount < 0); }
            else { const auto element = offset + displacement; pushReference(type, {element, element, element + width - 1}, signedCount < 0); }
            break;
        }
        case Instruction::PointerElement: case Instruction::FieldValue: case Instruction::FieldSlice: {
            const auto type = readOperand<SferaMbcValue::Type>();
            const auto stride = instruction == Instruction::PointerElement ? readOperand<std::uint16_t>() : 0;
            auto& source = popSlice();
            source.base += instruction == Instruction::PointerElement ? static_cast<std::uint32_t>(stride) * static_cast<std::uint32_t>(popInteger()) : readOperand<std::uint16_t>();
            if (source.begin != 0 && (source.base < source.begin || source.base > source.end)) source.diagnoseRange(0);
            const auto offset = source.base;
            if (instruction == Instruction::PointerElement) pushReference(type, source, true);
            else if (instruction == Instruction::FieldSlice) {
                const auto length = readOperand<std::uint32_t>();
                auto& slot = stack[value_stack_size++];
                slot.type = type; slot.width = sizeof(slot.value); slot.value = {offset, offset, offset + length - 1}; slot.detach();
            } else {
                const auto width = type == SferaMbcValue::Address ? readOperand<std::uint32_t>() : type == SferaMbcValue::Byte ? sizeof(std::int8_t) : type == SferaMbcValue::Integer || type == SferaMbcValue::Real ? sizeof(std::uint32_t) : sizeof(SferaSliceReference32);
                pushReference(type, {offset, offset, offset + static_cast<std::uint32_t>(width) - 1}, true);
            }
            break;
        }
        case Instruction::CallLocal: {
            auto& program = program_table_base[program_index];
            if (program.callDepth >= std::size(program.return_offsets)) { reportError("Return stack overflow"); break; }
            active_program_record->return_offsets[program.callDepth++] = static_cast<int>(instruction_cursor - bytecode_base + sizeof(int));
            const auto offset = readOperand<int>();
            instruction_cursor += std::ptrdiff_t(offset) - static_cast<std::ptrdiff_t>(sizeof(offset));
            argument_end = value_stack_size;
            value_stack_size -= argument_count;
            argument_cursor = value_stack_size;
            break;
        }

        case Instruction::Jump: { const auto offset = readOperand<int>(); instruction_cursor += std::ptrdiff_t(offset) - static_cast<std::ptrdiff_t>(sizeof(offset)); break; }
        case Instruction::JumpShort: { const auto offset = readOperand<std::int16_t>(); instruction_cursor += std::ptrdiff_t(offset) - static_cast<std::ptrdiff_t>(sizeof(offset)); break; }
        case Instruction::ArgumentCount: argument_count = readOperand<std::uint8_t>(); break;
        case Instruction::ResetStack: value_stack_size = frame_stack_base[call_frame_depth]; break;
        case Instruction::LiteralWord: case Instruction::LiteralShort: case Instruction::LiteralByte: {
            const auto type = readOperand<SferaMbcValue::Type>();
            std::uint32_t value;
            if (instruction == Instruction::LiteralWord) value = readOperand<std::uint32_t>();
            else if (instruction == Instruction::LiteralShort) value = readOperand<std::uint16_t>();
            else value = readOperand<std::int8_t>();
            if (value_stack_size == std::size(stack)) { reportError("Stack overflow"); break; }
            auto& slot = stack[value_stack_size++];
            slot.type = type; slot.width = sizeof(value); slot.value.base = value; slot.detach();
            break;
        }
        case Instruction::StringLiteral: case Instruction::SliceVariable: case Instruction::SliceLiteral: {
            const auto type = instruction == Instruction::StringLiteral ? SferaMbcValue::BytePointer : readOperand<SferaMbcValue::Type>();
            const auto offset = readOperand<std::uint32_t>();
            const auto length = instruction == Instruction::StringLiteral ? readOperand<std::uint16_t>() : readOperand<std::uint32_t>();
            if (value_stack_size == std::size(stack)) { reportError("Stack overflow"); break; }
            auto& slot = stack[value_stack_size++];
            slot.type = type; slot.width = sizeof(slot.value); slot.value = {offset, offset, offset + length - 1};
            if (instruction == Instruction::SliceVariable) slot.source = slot.value; else slot.detach();
            break;
        }
        case Instruction::StartProgram: case Instruction::CallProgram: case Instruction::StopProgram: case Instruction::PauseProgram: case Instruction::ResumeProgram: {
            const auto index = readOperand<std::int16_t>();
            auto& program = program_table_base[index];
            if (instruction == Instruction::StopProgram) { program.instruction_offset = program.stop_offset; break; }
            if (instruction == Instruction::PauseProgram) { program.state = 0; break; }
            if (instruction != Instruction::ResumeProgram) { program.instruction_offset = program.entry_offset; program.caller_program = instruction == Instruction::CallProgram ? program_index : -1; }
            if (program.state < 0) active_process->linkProgram(static_cast<std::uint32_t>(index));
            program.state = 1;
            break;
        }
        case Instruction::ReturnLocal: {
            auto& program = *active_program_record;
            instruction_cursor = program.callDepth == 0 ? bytecode_base - 1 : bytecode_base + program.return_offsets[--program.callDepth];
            break;
        }
        case Instruction::Assign: {
            const auto& right = stack[--value_stack_size];
            auto& left = stack[value_stack_size - 1];
            if (!left.source.contains(left.width)) left.source.diagnoseRange(left.width);
            if (left.width == 1) { const std::uint8_t value = right.value.base; left.value.base = value; writeMemory(left.source.base, value); }
            else if (!left.isPointer()) { left.value.base = right.value.base; writeMemory(left.source.base, right.value.base); }
            else { left.value = right.value; writeMemory(left.source.base, right.value); }
            break;
        }
        case Instruction::Dereference: {
            auto& slot = stack[value_stack_size - 1];
            slot.source = slot.value;
            if (!slot.value.contains(1, true)) slot.value.diagnoseRange(0);
            const auto offset = slot.value.base;
            slot.type = static_cast<SferaMbcValue::Type>(slot.type - 1);
            if (slot.type == SferaMbcValue::Byte) { slot.value.base = readMemory<std::int8_t>(offset); slot.type = SferaMbcValue::Integer; slot.width = sizeof(std::int8_t); }
            else if (!slot.isPointer()) { slot.value.base = readMemory<std::uint32_t>(offset); slot.width = sizeof(std::uint32_t); }
            else { slot.value = readMemory<SferaSliceReference32>(offset); slot.width = sizeof(slot.value); }
            break;
        }
        case Instruction::AddressOf: { auto& slot = stack[value_stack_size - 1]; slot.value = slot.source; slot.detach(); slot.type = static_cast<SferaMbcValue::Type>(slot.type + 1); slot.width = sizeof(slot.value); break; }
        case Instruction::Add: case Instruction::Subtract: case Instruction::Multiply: case Instruction::Divide: case Instruction::Remainder: {
            auto& left = stack[value_stack_size - 2];
            const auto& right = stack[value_stack_size - 1];
            if (left.type == SferaMbcValue::Integer || instruction == Instruction::Remainder) {
                const auto divisor = right.integer();
                if ((instruction == Instruction::Divide || instruction == Instruction::Remainder) && divisor == 0) { reportError("Division by zero"); break; }
                switch (instruction) {
                    case Instruction::Add: left.value.base += right.value.base; break;
                    case Instruction::Subtract: left.value.base -= right.value.base; break;
                    case Instruction::Multiply: left.value.base *= right.value.base; break;
                    case Instruction::Divide: left.value.base = std::int64_t(left.integer()) / divisor; break;
                    default: left.value.base = std::int64_t(left.integer()) % divisor; break;
                }
            } else {
                const double first = left.real(), second = right.real();
                double result;
                switch (instruction) {
                    case Instruction::Add: result = first + second; break;
                    case Instruction::Subtract: result = first - second; break;
                    case Instruction::Multiply: result = first * second; break;
                    default: result = first / second; break;
                }
                left.setReal(static_cast<float>(result));
            }
            --value_stack_size; left.detach();
            break;
        }
        case Instruction::Equal: case Instruction::NotEqual: case Instruction::Greater: case Instruction::Less: case Instruction::GreaterEqual: case Instruction::LessEqual: {
            auto& left = stack[value_stack_size - 2];
            const auto& right = stack[value_stack_size - 1];
            const double first = left.type == SferaMbcValue::Real ? double(left.real()) : double(left.integer());
            const double second = left.type == SferaMbcValue::Real ? double(right.real()) : double(right.integer());
            bool result;
            switch (instruction) {
                case Instruction::Equal: result = first == second; break;
                case Instruction::NotEqual: result = first != second; break;
                case Instruction::Greater: result = first > second; break;
                case Instruction::Less: result = first < second; break;
                case Instruction::GreaterEqual: result = first >= second; break;
                default: result = first <= second; break;
            }
            --value_stack_size; left.detach(); left.type = SferaMbcValue::Integer; left.value.base = result;
            break;
        }
        case Instruction::ShortCircuitOr: case Instruction::ShortCircuitAnd: {
            auto& slot = stack[value_stack_size - 1];
            const bool branch = (slot.value.base != 0) == (instruction == Instruction::ShortCircuitOr);
            const auto offset = readOperand<std::int16_t>();
            if (branch) { slot.type = SferaMbcValue::Integer; slot.detach(); instruction_cursor += std::ptrdiff_t(offset) - static_cast<std::ptrdiff_t>(sizeof(offset)); }
            else --value_stack_size;
            break;
        }
        case Instruction::IntegerResult: case Instruction::IntegerResultAlternate: { auto& slot = stack[value_stack_size - 1]; slot.type = SferaMbcValue::Integer; slot.detach(); break; }
        case Instruction::PreIncrement: case Instruction::PreDecrement: case Instruction::PostIncrement: case Instruction::PostDecrement: {
            auto& slot = stack[value_stack_size - 1];
            const bool increment = instruction == Instruction::PreIncrement || instruction == Instruction::PostIncrement;
            const bool prefix = instruction == Instruction::PreIncrement || instruction == Instruction::PreDecrement;
            if (slot.type == SferaMbcValue::Integer || slot.type == SferaMbcValue::Byte) {
                const auto value = slot.value.base + (increment ? 1 : UINT32_MAX);
                if (slot.width == 1) writeMemory(slot.source.base, static_cast<std::uint8_t>(value)); else writeMemory(slot.source.base, value);
                if (prefix) slot.value.base = value;
            } else {
                const float value = double(slot.real()) + (increment ? 1.0 : -1.0);
                if (instruction == Instruction::PostDecrement) {
                    // Preserve the stable interpreter's floating postfix result and second decrement.
                    slot.setReal(value);
                    writeMemory(slot.source.base, static_cast<float>(double(value) - 1.0));
                } else { writeMemory(slot.source.base, value); if (prefix) slot.setReal(value); }
            }
            break;
        }
        case Instruction::PointerPreIncrement: case Instruction::PointerPreDecrement: case Instruction::PointerPostIncrement: case Instruction::PointerPostDecrement: {
            const auto stride = readOperand<std::uint16_t>();
            auto& slot = stack[value_stack_size - 1];
            const bool increment = instruction == Instruction::PointerPreIncrement || instruction == Instruction::PointerPostIncrement;
            const auto value = increment ? slot.value.base + stride : slot.value.base - stride;
            writeMemory(slot.source.base, value);
            if (instruction == Instruction::PointerPreIncrement || instruction == Instruction::PointerPreDecrement) slot.value.base = value;
            break;
        }
        case Instruction::IntegerToReal: case Instruction::PreviousIntegerToReal: case Instruction::RealToInteger: case Instruction::PreviousRealToInteger: {
            const bool previous = instruction == Instruction::PreviousIntegerToReal || instruction == Instruction::PreviousRealToInteger;
            auto& slot = stack[value_stack_size - (previous ? 2 : 1)];
            if (instruction == Instruction::IntegerToReal || instruction == Instruction::PreviousIntegerToReal) { slot.setReal(static_cast<float>(slot.integer())); slot.type = SferaMbcValue::Real; }
            else { slot.value.base = SferaMbcValue::truncate(slot.real()); slot.type = SferaMbcValue::Integer; }
            break;
        }
        case Instruction::Swap: std::swap(stack[value_stack_size - 2], stack[value_stack_size - 1]); break;
        case Instruction::PointerAdd: case Instruction::PointerSubtract: {
            const auto stride = readOperand<std::uint16_t>();
            const auto index = stack[--value_stack_size].value.base;
            auto& slot = stack[value_stack_size - 1];
            if (instruction == Instruction::PointerAdd) slot.value.base += index * stride; else slot.value.base -= index * stride;
            slot.detach();
            break;
        }
        case Instruction::IntegerPair: stack[value_stack_size - 1].type = stack[value_stack_size - 2].type = SferaMbcValue::Integer; break;
        case Instruction::Negate: case Instruction::LogicalNot: {
            if (call_frame_depth >= std::size(frame_stack_base) || value_stack_size <= frame_stack_base[call_frame_depth]) { --value_stack_size; reportError(instruction == Instruction::Negate ? "fo27(): stack underflow" : "fo31(): stack underflow"); break; }
            auto& slot = stack[value_stack_size - 1];
            if (instruction == Instruction::LogicalNot) { slot.value.base = slot.value.base == 0; slot.type = SferaMbcValue::Integer; }
            else if (slot.type == SferaMbcValue::Integer) slot.value.base = 0u - slot.value.base;
            else slot.setReal(-slot.real());
            slot.detach();
            break;
        }
        case Instruction::EnterFrame:
            if (++call_frame_depth >= 20) reportError("Stack of stacks overflow");
            if (call_frame_depth < std::size(frame_stack_base)) frame_stack_base[call_frame_depth] = value_stack_size;
            break;
        case Instruction::LeaveFrame: if (static_cast<int>(--call_frame_depth) < 0) reportError("Stack of stacks devastation"); break;
        case Instruction::UnlinkedFunction: reportError("Unlinked function was called"); break;
        case Instruction::Halt: execution_failed = true; break;
        default: return false;
    }
    return true;
}

void SferaMbcRuntime::reportInvalidInstruction() { const char opcode[] = {static_cast<char>(*--instruction_cursor), 0}; reportError("Unknown script code: ", opcode); }

std::uint32_t SferaText::copyString(char* destination, const char* source, int capacity) {
    const std::uint32_t length = std::strlen(source) + 1;
    if (capacity > 0 && length > static_cast<std::uint32_t>(capacity)) {
        std::memcpy(destination, source, capacity - 1);
        destination[capacity - 1] = '\0';
        if (g_sfera_mbc_runtime.dispatch_slot >= 0) {
            std::snprintf(g_sfera_mbc_runtime.diagnostic_context, sizeof(g_sfera_mbc_runtime.diagnostic_context), "MBINTER MESSAGE: Wrong string to copy: '%s', strlen: %d\n", source, static_cast<int>(std::strlen(source)));
            g_sfera_log_runtime.write(g_sfera_mbc_runtime.diagnostic_context);
        }
        return capacity;
    }
    std::memcpy(destination, source, length);
    return length;
}

bool SferaMbcRuntime::executeBuiltin(Builtin builtin) {
    switch (builtin) {
        case Builtin::Fail: case Builtin::FailAlternate: { char message[256]{}; std::snprintf(message, sizeof(message), "MBInter:\n %f", nextReal()); SferaClientApplication::terminateWithError(message); }
        case Builtin::Exit: {
            if (argument_count == 0) throw SferaClientApplication::ExitRequested{};
            if (argument_count > 1) g_sfera_mbc_runtime.dispatch_slot = UINT32_MAX;
            const auto message = nextSliceReference().base; SferaClientApplication::terminateWithError(textAt(message));
        }
        case Builtin::LoadProcess: {
            const auto name = nextSliceReference().base; const auto index = argument_count > 1 ? static_cast<std::uint32_t>(nextInteger()) : UINT32_MAX; if (execution_failed) break;
            if (name == 0) ::OutputDebugStringA("NULL-pointer dereferencing: ffprc_load\n");
            active_tag = loadProcess(textAt(name), index); pushInteger(active_tag); break;
        }
        case Builtin::UnloadProcess: {
            const std::uint32_t requested = nextInteger(); const auto* process = findProcess(requested); const auto index = process == nullptr ? UINT32_MAX : requested; if (execution_failed) break;
            if (index == process_index) active_tag = UINT32_MAX;
            else active_tag = unloadProcess(index);
            pushInteger(active_tag); break;
        }
        case Builtin::LinkProcess: { const auto name = nextSliceReference().base; if (name == 0) ::OutputDebugStringA("NULL-pointer dereferencing: ffprc_link\n"); active_tag = linkProcess(textAt(name)); pushInteger(active_tag); break; }
        case Builtin::Connect: { const auto host = nextSliceReference().base; nextSliceReference(); const auto mode = argument_count > 2 ? static_cast<std::uint32_t>(nextInteger()) : 3u; pushInteger(g_sfera_network_runtime.initialize(textAt(host), mode)); break; }
        case Builtin::Disconnect: g_sfera_network_runtime.shutdown(); break;
        case Builtin::Send: buildRegion(); break;
        case Builtin::FormatText: case Builtin::BoundedFormatText: formatText(builtin == Builtin::BoundedFormatText); break;
        case Builtin::FormattedLog: case Builtin::NamedFormattedLog: writeFormattedLog(builtin == Builtin::NamedFormattedLog); break;
        case Builtin::System: systemCommand(); break;
        case Builtin::DiscardInteger: nextInteger(); break;
        case Builtin::Reserved122: case Builtin::Reserved130: case Builtin::Reserved133: break;
        case Builtin::Receive: receiveRegion(); break;
        case Builtin::Window: windowCommand(); break;
        case Builtin::ScriptLog: writeScriptLog(); break;
        case Builtin::ParseText: parseText(); break;
        case Builtin::ChatUtility: chatUtility(); break;
        case Builtin::CallFunction: case Builtin::CallMainFunction: callFunction(builtin == Builtin::CallMainFunction); break;
        case Builtin::Distance: calculateDistance(); break;
        case Builtin::ScanText: scanText(); break;
        case Builtin::Configuration: {
            auto& config = g_sfera_config_text_runtime;
            const auto operation = static_cast<SferaConfigTextRuntime::Operation>(nextInteger());
            switch (operation) {
                case SferaConfigTextRuntime::Operation::Write: {
                    const auto keyOffset = nextInteger();
                    if (execution_failed) break;
                    const std::string key(textAt(keyOffset));
                    if (argument_cursor >= argument_end) { reportError("Too few parameters"); break; }
                    const auto type = static_cast<std::uint8_t>(g_sfera_mbc_runtime.values[argument_cursor].type);
                    std::string value;
                    bool quoted = false;
                    if (!key.empty() && key.front() == '*') {
                        const auto offset = nextInteger();
                        const auto size = nextInteger();
                        if (execution_failed) break;
                        if (size < 0 || static_cast<std::uint32_t>(size) > (SferaConfigTextRuntime::text_capacity - 4) * 3 / 4) { reportError("cfg_set: invalid binary size"); break; }
                        value = SferaConfigTextRuntime::encodeBinary({memoryAt(offset, static_cast<std::size_t>(size)), static_cast<std::size_t>(size)});
                    } else if (type == SferaMbcValue::Byte || type == SferaMbcValue::Integer) {
                        value = std::to_string(nextInteger());
                    } else if (type == SferaMbcValue::Real) {
                        char formatted[128];
                        std::snprintf(formatted, sizeof(formatted), "%f", nextReal());
                        value = formatted;
                    } else if (type == SferaMbcValue::BytePointer) {
                        const auto offset = nextInteger();
                        if (execution_failed) break;
                        value = textAt(offset);
                        quoted = true;
                    } else { reportError("cfg_set: unsupported value type"); break; }
                    if (!execution_failed) pushInteger(config.writeValue(key, value, quoted) ? 0u : UINT32_MAX);
                    break;
                }
                case SferaConfigTextRuntime::Operation::Read: {
                    const auto keyReference = nextSliceReference();
                    if (execution_failed) break;
                    const auto* key = textAt(keyReference.base);
                    if (argument_cursor >= argument_end) { reportError("Too few parameters"); break; }
                    const auto type = g_sfera_mbc_runtime.values[argument_cursor].type;
                    const auto destination = nextSliceReference();
                    const auto capacity = argument_count == 4 ? static_cast<std::uint32_t>(nextInteger()) : 10000000u;
                    if (execution_failed) break;
                    bool result = false;
                    if (*key == '*') {
                        auto bytes = sliceBytes(destination); result = config.readBinary(key, bytes.data(), std::min<std::size_t>(capacity, bytes.size()));
                    }
                    else if (type == SferaMbcValue::IntegerPointer) {
                        auto value = readMemory<int>(destination.base);
                        result = config.readInteger(key, value);
                        if (result) writeMemory(destination.base, value);
                    } else if (type == SferaMbcValue::RealPointer) {
                        auto value = readMemory<float>(destination.base);
                        result = config.readFloat(key, value);
                        if (result) writeMemory(destination.base, value);
                    } else if (type == SferaMbcValue::BytePointer) {
                        auto bytes = sliceBytes(destination); result = config.readString(key, reinterpret_cast<char*>(bytes.data()), std::min<std::size_t>(capacity, bytes.size()));
                    }
                    else {
                        const auto message = std::string("wrong parameter in cfg_get, '") + key + "'\n";
                        ::OutputDebugStringA(message.c_str());
                    }
                    pushInteger(result ? 0u : UINT32_MAX);
                    break;
                }
                case SferaConfigTextRuntime::Operation::Load:
                case SferaConfigTextRuntime::Operation::Clear:
                case SferaConfigTextRuntime::Operation::UseText:
                case SferaConfigTextRuntime::Operation::SetFilename: {
                    const auto reference = nextSliceReference();
                    if (reference.base == 0) reportError("poppointerup(): unexpected NULL-pointer fetched");
                    if (execution_failed) break;
                    auto* text = textAt(reference.base);
                    if (operation == SferaConfigTextRuntime::Operation::UseText) { config.useText(reference.base, sliceBytes(reference).size(), active_process); pushInteger(0); }
                    else if (operation == SferaConfigTextRuntime::Operation::Load) pushInteger(config.load(text) ? 0u : UINT32_MAX);
                    else {
                        const auto length = std::strlen(text);
                        if (length >= SferaConfigTextRuntime::filename_capacity) { reportError("cfg: filename is too long"); break; }
                        if (operation == SferaConfigTextRuntime::Operation::Clear) config.clear(text);
                        else config.filename.assign(text, length);
                    }
                    break;
                }
                case SferaConfigTextRuntime::Operation::Save:
                case SferaConfigTextRuntime::Operation::SaveCompressed:
                    pushInteger(config.save(operation == SferaConfigTextRuntime::Operation::SaveCompressed) ? 0u : UINT32_MAX);
                    break;
                case SferaConfigTextRuntime::Operation::ReadCommands: {
                    if (active_process->physics_commands.empty()) { pushInteger(UINT32_MAX); break; }
                    auto commands = std::exchange(active_process->physics_commands, {});
                    g_sfera_config_text_runtime.copyText(commands);
                    pushInteger(0);
                    break;
                }
                case SferaConfigTextRuntime::Operation::CopyText: {
                    const auto destination = nextSliceReference();
                    if (destination.base == 0) reportError("poppointerup(): unexpected NULL-pointer fetched");
                    const std::uint32_t capacity = nextInteger();
                    if (!execution_failed) pushInteger(static_cast<std::uint32_t>(config.copyTo(reinterpret_cast<char*>(sliceBytes(destination).data()), std::min<std::size_t>(capacity, sliceBytes(destination).size()))));
                    break;
                }
                case SferaConfigTextRuntime::Operation::Length: if (std::in_range<std::uint32_t>(config.text().size())) pushInteger(static_cast<std::uint32_t>(config.text().size())); else reportError("cfg: text is too long for MBC"); break;
                default: break;
            }
            return true;
        }
        case Builtin::CreateFile: case Builtin::OpenFile: {
            const auto name = nextInteger();
            if (name == 0) WorldDiagnostics::warning(builtin == Builtin::CreateFile ? "NULL-pointer dereferencing: ffcreate\n" : "NULL-pointer dereferencing: ffopen\n");
            if (builtin == Builtin::CreateFile && execution_failed) break;
            const auto* path = textAt(name);
            ::_chmod(path, _S_IREAD | _S_IWRITE);
            if (execution_failed) break;
            int flags = _O_BINARY | _O_RDWR;
            int sharing = _SH_DENYNO;
            if (builtin == Builtin::CreateFile) flags |= _O_CREAT | (argument_count == 2 ? 0 : _O_TRUNC);
            else if (argument_count > 1 && nextInteger() == 1) flags = _O_BINARY | _O_RDONLY;
            int file = -1;
            ::_sopen_s(&file, path, flags, sharing, _S_IREAD | _S_IWRITE);
            if (file >= 0) {
                try { active_process->registerResource(file, ResourceKind::file); }
                catch (...) { ::_close(file); throw; }
            }
            pushInteger(file);
            break;
        }
        case Builtin::CloseFile: {
            const auto file = nextInteger();
            if (!execution_failed && file >= 0) { ::_close(file); active_process->unregisterResource(file, ResourceKind::file); }
            break;
        }
        case Builtin::ReadFile: case Builtin::WriteFile: {
            const auto file = nextInteger();
            if (builtin == Builtin::ReadFile && execution_failed) break;
            auto& buffer = nextSliceReference();
            const std::uint32_t size = nextInteger();
            if (builtin == Builtin::WriteFile && execution_failed) break;
            if (!buffer.contains(size)) buffer.diagnoseRange(size);
            auto* data = memoryAt(buffer.base);
            const auto result = builtin == Builtin::ReadFile ? ::_read(file, data, size) : file < 0 ? 0 : ::_write(file, data, size);
            pushInteger(result);
            break;
        }
        case Builtin::ReadLine: {
            const auto file = nextInteger();
            if (execution_failed) break;
            const auto destination = nextInteger();
            if (destination == 0) WorldDiagnostics::warning("NULL-pointer dereferencing: ffread\n");
            const auto capacity = nextInteger();
            auto* output = memoryAt(destination);
            int size = 0;
            while (size < capacity) {
                std::uint8_t character;
                if (::_read(file, &character, sizeof(character)) != 1) break;
                if (character == '\n' || character == '\0') { output[size] = '\0'; break; }
                output[size++] = character;
            }
            pushInteger(size);
            break;
        }
        case Builtin::LockFile: {
            const auto file = nextInteger();
            const auto unlock = nextInteger();
            const auto size = nextInteger();
            if (!execution_failed) pushInteger(::_locking(file, unlock ? _LK_UNLCK : _LK_NBLCK, size));
            break;
        }
        case Builtin::SeekFile: {
            const auto file = nextInteger();
            const auto offset = nextInteger();
            const auto origin = nextInteger();
            if (!execution_failed) pushInteger(::_lseek(file, offset, origin == 1 ? SEEK_SET : origin == 2 ? SEEK_CUR : SEEK_END));
            break;
        }
        case Builtin::FileSize: { const auto file = nextInteger(); if (!execution_failed) pushInteger(::_filelength(file)); break; }
        case Builtin::FileTime: {
            const auto file = nextInteger();
            if (!execution_failed) { struct _stat64i32 status{}; ::_fstat64i32(file, &status); pushInteger(static_cast<std::uint32_t>(status.st_mtime)); }
            break;
        }
        case Builtin::ResizeFile: { const auto file = nextInteger(); const auto size = nextInteger(); if (!execution_failed) ::_chsize_s(file, size); break; }
        case Builtin::SetFileTime: {
            const auto file = nextInteger();
            const auto time = nextInteger();
            if (!execution_failed) { __utimbuf64 times{time, time}; ::_futime64(file, &times); }
            break;
        }
        case Builtin::RemoveFile: { const auto name = nextInteger(); if (!execution_failed) pushInteger(std::remove(textAt(name))); break; }
        case Builtin::RenameFile: { const auto source = nextInteger(); const auto destination = nextInteger(); if (!execution_failed) pushInteger(std::rename(textAt(source), textAt(destination))); break; }
        case Builtin::SetAnimation: case Builtin::SetFrame: {
            const auto handle = nextInteger();
            const auto value = nextInteger();
            const bool secondary = argument_count > 2 && nextInteger() != 0;
            if (argument_count <= 2 && execution_failed) break;
            auto* field = builtin == Builtin::SetAnimation ? (secondary ? SphereRender::ModelPose::secondaryAnimation(handle) : SphereRender::ModelPose::animation(handle)) : (secondary ? SphereRender::ModelPose::secondaryFrame(handle) : SphereRender::ModelPose::frame(handle));
            if (field != nullptr) *field = value;
            break;
        }
        case Builtin::AnimationLength: { const auto handle = nextInteger(); const auto animation = nextInteger(); if (!execution_failed) pushInteger(SphereRender::ModelPose::animationLength(handle, animation)); break; }
        case Builtin::SetInterpolation: { const auto handle = nextInteger(); const auto value = nextReal(); if (!execution_failed) { auto* field = SphereRender::ModelPose::interpolation(handle); if (field != nullptr) *field = value; } break; }
        case Builtin::MouseMotion: {
            const auto x = nextInteger();
            const auto y = nextInteger();
            if (!execution_failed) pushInteger(x == -2 && y == -2 ? g_sfera_direct_input_runtime.mouse.wheel : x == -1 ? g_sfera_direct_input_runtime.mouse.dx : y == -1 ? g_sfera_direct_input_runtime.mouse.dy : 0);
            break;
        }
        case Builtin::ThisProcessName: case Builtin::ProcessName: case Builtin::ModuleName: {
            const auto id = builtin == Builtin::ThisProcessName ? process_index : static_cast<std::uint32_t>(nextInteger());
            const auto destination = nextInteger();
            if (destination == 0 && builtin != Builtin::ModuleName) WorldDiagnostics::warning(builtin == Builtin::ThisProcessName ? "NULL-pointer dereferencing: thisname\n" : "NULL-pointer dereferencing: prc_name\n");
            if (execution_failed) break;
            const char* name = nullptr;
            if (builtin == Builtin::ThisProcessName) name = active_process->name;
            else if (builtin == Builtin::ProcessName && id < std::size(processes) && processes[id].chain_prev_index >= 0) name = processes[id].name;
            else if (builtin == Builtin::ModuleName && id < std::size(g_sfera_mbc_runtime.modules)) name = g_sfera_mbc_runtime.modules[id].name;
            if (name != nullptr) std::copy_n(name, std::strlen(name) + 1, textAt(destination));
            if (builtin != Builtin::ThisProcessName) pushInteger(name != nullptr && (builtin != Builtin::ModuleName || *name != '\0') ? 0 : UINT32_MAX);
            break;
        }
        case Builtin::FindModule: {
            const auto name = nextInteger();
            if (execution_failed) break;
            const auto& modules = g_sfera_mbc_runtime.modules;
            const auto found = std::find_if(std::begin(modules), std::end(modules), [&](const auto& module) { return module.name[0] != '\0' && ::_stricmp(module.name, textAt(name)) == 0; });
            pushInteger(found == std::end(modules) ? UINT32_MAX : static_cast<std::uint32_t>(found - std::begin(modules)));
            break;
        }
        case Builtin::FontSettings: {
            const auto& suffix = g_sfera_font_runtime.language_suffix;
            const auto offset = mapMemory(suffix, suffix != nullptr ? std::strlen(suffix) + 1 : 0);
            pushSlice({offset, offset, offset + static_cast<std::uint32_t>(sizeof(suffix)) - 1}, SferaMbcValue::BytePointer);
            break;
        }
        case Builtin::DestroyObject: case Builtin::DestroyText: case Builtin::DestroySprite: {
            const auto handle = nextInteger();
            if (execution_failed) break;
            if (builtin == Builtin::DestroyObject) { if (handle != -1) g_sfera_world_objects.destroy(handle); }
            else if (handle >= 0) { if (builtin == Builtin::DestroyText) WorldGuiControls::destroyText(handle); else WorldGuiControls::destroySprite(handle); }
            active_process->unregisterResource(handle, builtin == Builtin::DestroyObject ? ResourceKind::worldObject : builtin == Builtin::DestroyText ? ResourceKind::textControl : ResourceKind::spriteControl);
            break;
        }
        case Builtin::ObjectProcess: {
            const auto handle = nextInteger();
            if (execution_failed) break;
            const auto* object = handle >= 0 ? g_sfera_world_objects.object(handle, "GetProcess") : nullptr;
            const auto* owner = object != nullptr && object->extended() ? object->extended()->process_handle : nullptr;
            pushInteger(owner != nullptr ? owner->process_id : UINT32_MAX);
            break;
        }
        case Builtin::SetRenderEnabled: {
            const auto handle = nextInteger();
            if (handle < 0) break;
            const auto enabled = nextInteger();
            if (!execution_failed) SphereRender::CharacterModels::checkedExtended(g_sfera_world_objects.object(handle, "GetObjectPointer"))->render_enabled = enabled != 0;
            break;
        }
        case Builtin::CreateObject: {
            const auto name = nextInteger();
            const std::uint32_t kind = nextInteger();
            const auto independent = argument_count > 2 ? nextInteger() : 0;
            if (execution_failed) break;
            static constexpr std::array<std::uint32_t, 11> factories{0, 1, 2, 3, 1, 4, 5, 6, 4, 5, 3};
            const auto factory = kind < factories.size() ? factories[kind] : 0;
            const auto* filename = textAt(name);
            const auto handle = g_sfera_world_objects.create(filename, independent == 1 ? nullptr : active_process, factory, independent != 1);
            pushInteger(handle);
            if (static_cast<int>(handle) < 0) { reportError((std::string("Error creating object: ") + filename).c_str()); execution_failed = false; break; }
            auto* object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
            if (object->extended()) {
                auto& extended = *object->extended();
                extended.simulation_enabled = kind == 10;
                extended.full_rate_simulation = (kind >= 1 && kind <= 4) || kind == 10;
                extended.gravity_enabled = kind == 2 || kind == 3 || kind == 5 || kind == 6 || kind == 10;

            }
            try { active_process->registerResource(handle, ResourceKind::worldObject); }
            catch (...) { g_sfera_world_objects.destroy(handle); throw; }
            break;
        }
        case Builtin::SetPosition: case Builtin::MoveWorld: {
            const auto handle = nextInteger();
            if (handle < 0) break;
            SferaVec3F position; position.x = nextReal(); position.y = nextReal(); position.z = nextReal();
            auto* object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
            if (object == nullptr) { active_tag = UINT32_MAX; break; }
            if (execution_failed) break;
            if (builtin == Builtin::SetPosition) object->position = position;
            else object->position = object->position + position;
            if (static_cast<std::uint32_t>(handle) == g_sfera_world_objects.controlled_object_handle) {
                g_sfera_motion.tracked_position.x = object->position.x + 333.0f;
                g_sfera_motion.tracked_position.y = object->position.y + 333.0f;
                g_sfera_motion.tracked_position.z = object->position.z + 333.0f;
            }
            if (builtin == Builtin::SetPosition && argument_count >= 5) {
                g_sfera_world_objects.updateSpatialIndex(handle);
                if (argument_count == 6) { nextInteger(); object->spatial_membership = nextInteger(); }
            }
            break;
        }
        case Builtin::CommandVelocity: {
            const auto handle = nextInteger();
            if (handle < 0) break;
            const auto x = nextReal();
            const auto second = nextReal();
            auto* object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
            if (object == nullptr) { active_tag = UINT32_MAX; break; }
            if (execution_failed) break;
            auto* extended = SphereRender::CharacterModels::checkedExtended(object);
            extended->commanded_velocity.x = x;
            if (argument_count == 4) { const auto z = nextReal(); extended->commanded_velocity.y = second; extended->commanded_velocity.z = z; }
            else extended->commanded_velocity.z = second;
            break;
        }
        case Builtin::VerticalVelocity: case Builtin::AngularVelocity: {
            const auto handle = nextInteger();
            if (handle < 0) break;
            float value = 0;
            if (builtin == Builtin::AngularVelocity) value = nextReal();
            auto* object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
            if (object == nullptr) { active_tag = UINT32_MAX; break; }
            if (builtin == Builtin::VerticalVelocity) value = argument_count == 3 ? static_cast<float>(g_sfera_motion.responseValue(nextInteger())) : nextReal();
            if (!execution_failed) {
                auto* extended = SphereRender::CharacterModels::checkedExtended(object);
                if (builtin == Builtin::VerticalVelocity) extended->physical_velocity.y = value;
                else extended->angular_velocity = value;
            }
            break;
        }
        case Builtin::Airborne: {
            const auto handle = nextInteger();
            if (handle < 0) { pushInteger(0); break; }
            auto* object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
            if (object == nullptr) { active_tag = UINT32_MAX; break; }
            if (execution_failed) break;
            const auto command = nextInteger();
            auto* extended = SphereRender::CharacterModels::checkedExtended(object);
            if (command == -1) pushInteger(extended->airborne);
            else { extended->airborne = true; pushInteger(0); }
            break;
        }
        case Builtin::ObjectBasis: case Builtin::ObjectPosition: case Builtin::ObjectRotation: {
            const auto handle = nextInteger();
            if (handle < 0) break;
            auto* object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
            if (object == nullptr) { active_tag = UINT32_MAX; break; }
            if (builtin == Builtin::ObjectPosition) {
                auto& destination = nextSliceReference();
                if (execution_failed) break;
                if (!destination.contains(sizeof(SferaVec3F))) destination.diagnoseRange(sizeof(SferaVec3F));
                writeMemory(destination.base, object->position);
            } else {
                if (builtin == Builtin::ObjectBasis && g_sfera_mbc_runtime.values[argument_cursor].type != SferaMbcValue::RealPointer) { WorldDiagnostics::warning("g_norm: wrong type of parameter (must be float pointer)\n"); execution_failed = true; }
                const auto destination = nextInteger();
                if (execution_failed) break;
                if (builtin == Builtin::ObjectBasis) {
                    const auto* extended = SphereRender::CharacterModels::checkedExtended(object);
                    g_sfera_world_objects.recalculateBasis(handle);
                    if (destination == 0) WorldDiagnostics::warning("NULL-pointer dereferencing: ffg_norm\n");
                    writeMemory(destination, extended->orientation_basis[0]);
                } else {
                    if (destination == 0) WorldDiagnostics::warning("NULL-pointer dereferencing: ffg_abg\n");
                    writeMemory(destination, object->rotation);
                }
            }
            break;
        }
        case Builtin::EditorPick: {
            if (nextInteger() != 0) break;
            const auto distance = nextInteger();
            const auto position = nextInteger();
            if (!execution_failed) {
                if (distance != 0) writeMemory(distance, 0.0f);
                if (position != 0) writeMemory(position, SferaVec3F{});
                pushInteger(UINT32_MAX);
            }
            break;
        }

        case Builtin::AllocateMemory: {
            const auto size = nextInteger();
            if (execution_failed) break;
            if (size <= 0) pushInteger(0);
            else { const auto offset = active_process->growMemory(static_cast<std::uint32_t>(size)); pushSlice({offset, offset, offset + static_cast<std::uint32_t>(size) - 1}, SferaMbcValue::BytePointer); }
            break;
        }
        case Builtin::AllocateDynamic: case Builtin::FreeDynamic: {
            const auto reference = nextSliceReference();
            const auto size = builtin == Builtin::AllocateDynamic ? nextInteger() : 0;
            if (execution_failed) break;
            if (!reference.contains(sizeof(SferaSliceReference32))) { reportError("Dynamic array reference outside slice"); break; }
            // Validate the entire lvalue before creating or destroying any allocation.
            auto* destination = memoryAt(reference.base, sizeof(SferaSliceReference32));
            SferaSliceReference32 previous{};
            std::memcpy(&previous, destination, sizeof(previous));
            if (builtin == Builtin::AllocateDynamic) {
                const auto offset = size > 0 ? allocateDynamic(static_cast<std::size_t>(size)) : 0u;
                try { if (offset != 0) active_process->registerResource(reference.base, ResourceKind::dynamicArray); }
                catch (...) { releaseDynamic(offset); throw; }
                const SferaSliceReference32 replacement{offset, offset, offset == 0 ? 0u : offset + static_cast<std::uint32_t>(size) - 1u};
                std::memcpy(destination, &replacement, sizeof(replacement));
                // Replacement is transactional; an old owned allocation cannot leak.
                if (previous.base != 0) releaseDynamic(previous.base);
                if (offset == 0) active_process->unregisterResource(reference.base, ResourceKind::dynamicArray);
            } else if (previous.base != 0) {
                if (!releaseDynamic(previous.base)) { reportError("Dynamic array does not own this address"); break; }
                const SferaSliceReference32 empty{};
                std::memcpy(destination, &empty, sizeof(empty));
                active_process->unregisterResource(reference.base, ResourceKind::dynamicArray);
            }
            break;
        }
        case Builtin::SetNamedValue: case Builtin::NamedValue: {
            const auto name = nextInteger();
            const auto value = builtin == Builtin::SetNamedValue ? nextInteger() : 0;
            const auto index = argument_count > (builtin == Builtin::SetNamedValue ? 2u : 1u) ? nextInteger() : 0;
            const auto* text = textAt(name);
            if (builtin == Builtin::SetNamedValue) setNamedValue(text, static_cast<std::uint32_t>(value), index);
            else pushInteger(namedValue(text, index));
            break;
        }
        case Builtin::RebaseSlice: {
            auto process = UINT32_MAX;
            const auto store = argument_count == 1;
            if (store) { if (execution_context_depth != 0 && program_table_base[program_index].callDepth == 0) process = execution_context_stack[execution_context_depth - 1].process_id; }
            else process = nextInteger();
            auto slice = nextSlice();
            if (execution_failed) break;
            auto* owner = findProcess(process);
            if (owner == nullptr) { if (store) pushInteger(UINT32_MAX); else { active_tag = UINT32_MAX; pushSlice({}, SferaMbcValue::BytePointer); } break; }
            slice = rebaseSlice(slice, *owner);
            if (store) { writeMemory(g_sfera_mbc_runtime.values[argument_cursor - 1].source.base, slice); pushInteger(0); }
            else pushSlice(slice, SferaMbcValue::BytePointer);
            break;
        }
        case Builtin::CopyProcessMemory: case Builtin::CopyProcessString: {
            const std::uint32_t destinationProcess = nextInteger();
            auto& destination = nextSliceReference();
            if (destination.base == 0) { ::OutputDebugStringA("NULL-pointer dereferencing: ffmempcpy\n"); break; }
            const std::uint32_t sourceProcess = nextInteger();
            const auto& source = nextSliceReference();
            const auto count = builtin == Builtin::CopyProcessMemory || argument_count == 5 ? nextInteger() : 0;
            if (builtin == Builtin::CopyProcessMemory && !destination.contains(static_cast<std::uint32_t>(count))) destination.diagnoseRange(static_cast<std::uint32_t>(count));
            if (execution_failed) break;
            auto* target = findProcess(destinationProcess);
            auto* origin = findProcess(sourceProcess);
            if (target == nullptr || origin == nullptr) { active_tag = UINT32_MAX; pushInteger(UINT32_MAX); break; }
            auto* output = memoryAt(destination.base, 1, target);
            const auto* input = memoryAt(source.base, 1, origin);
            if (builtin == Builtin::CopyProcessMemory) std::memcpy(output, input, static_cast<std::uint32_t>(count));
            else { const auto copied = SferaText::copyString(reinterpret_cast<char*>(output), reinterpret_cast<const char*>(input), count); if (!destination.contains(copied, true)) destination.diagnoseRange(copied); }
            break;
        }

        case Builtin::Text: {
            const auto create = g_sfera_mbc_runtime.values[argument_cursor].type == SferaMbcValue::BytePointer;
            const auto first = nextInteger();
            if (!create) {
                const auto color = nextInteger();
                const auto style = nextInteger();
                const auto font = nextInteger();
                const auto scale = SferaMbcValue::truncate(nextReal());
                if (execution_failed) break;
                auto* window = GameInterface::window(static_cast<std::uint32_t>(first), "GetWindowPointer");
                if (window == nullptr) { reportError("Wrong parameters for 'text' function"); break; }
                window->textColor = color; window->textStyle = style; window->font = font; window->fontScale = scale;
                break;
            }
            const auto parent = nextInteger();
            const auto x = nextInteger();
            const auto y = nextInteger();
            if (argument_count >= 8) {
                auto* window = GameInterface::window(static_cast<std::uint32_t>(parent), "GetWindowPointer");
                if (window == nullptr) { reportError("Wrong parameters for 'text' function"); break; }
                window->textColor = nextInteger(); window->textStyle = nextInteger(); window->font = nextInteger(); window->fontScale = SferaMbcValue::truncate(nextReal());
            }
            if (argument_count == 9) nextInteger();
            if (execution_failed) break;
            const auto* text = textAt(first);
            const auto length = std::strlen(text);
            if (length >= std::size(text_buffer)) { reportError("Script text exceeds text buffer capacity"); break; }
            std::copy_n(text, length + 1, text_buffer);
            if (length == 0) { text_buffer[0] = '?'; text_buffer[1] = '\0'; }
            const auto handle = WorldGuiControls::createText(x, y, text_buffer, static_cast<std::uint32_t>(parent));
            pushInteger(handle);
            if (handle != UINT32_MAX) {
                try { active_process->registerResource(handle, ResourceKind::textControl); }
                catch (...) { WorldGuiControls::destroyText(handle); throw; }
            }
            break;
        }
        case Builtin::TextColor: {
            const auto handle = nextInteger();
            const auto color = nextInteger();
            if (argument_count == 3) { const auto alpha = nextInteger(); if (!execution_failed) WorldGuiControls::setAppearance(handle, alpha, color); }
            else if (!execution_failed) { auto* control = WorldGuiControls::control(handle); if (control == nullptr) WorldDiagnostics::fail("text_color: wrong handle"); control->color = color; }
            break;
        }
        case Builtin::Sprite: {
            const auto texture = nextInteger();
            const auto parent = nextInteger();
            if (argument_count == 2) { WorldGuiControls::setAppearance(texture, parent); pushInteger(0); break; }
            const auto x = nextInteger();
            const auto y = nextInteger();
            const auto width = nextInteger();
            const auto height = nextInteger();
            const auto alpha = argument_count > 6 ? nextInteger() : std::numeric_limits<std::uint8_t>::max();
            if (argument_count > 7) nextInteger();
            if (argument_count > 8) nextInteger();
            if (argument_count > 9) { nextInteger(); nextInteger(); }
            if (execution_failed) break;
            const auto handle = WorldGuiControls::createSprite(x, y, width, height, textAt(texture), parent, alpha);
            if (handle < 0) reportError("Error creating sprite");
            else {
                try { active_process->registerResource(handle, ResourceKind::spriteControl); }
                catch (...) { WorldGuiControls::destroySprite(handle); throw; }
                pushInteger(handle);
            }
            break;
        }
        case Builtin::Effect: {
            if (g_sfera_effect_manager.diagnostics.enabled) ++g_sfera_effect_manager.diagnostics.vm_requests;
            const auto handle = nextInteger();
            const auto effect = nextInteger();
            const auto parameter = argument_count >= 3 ? nextInteger() : 0;
            if (argument_count == 4) nextInteger();
            if (execution_failed) break;
            SferaActiveEffect* created = nullptr;
            if (argument_count == 4) {
                if (handle == 0) reportError("Effect attached to zero handle!", "");
                created = g_sfera_effect_manager.createActiveEffect(textAt(effect), handle);
            } else {
                if (handle <= 0) { char message[256]; std::snprintf(message, sizeof(message), "Wrong Handler for Effect %s\n", active_process->name); ::OutputDebugStringA(message); pushInteger(UINT32_MAX); break; }
                if (argument_count >= 3 && parameter != 0) {
                    SferaEffectParameter value;
                    switch (effect) {
                        case 1: {
                            const auto* bytes = memoryAt(static_cast<std::uint32_t>(parameter), 6);
                            SferaEffectParameter::Color rgb;
                            for (std::size_t channel = 0; channel < rgb.channels.size(); ++channel) rgb.channels[channel] = SferaBinary::readLittleEndian<std::uint16_t>(bytes + channel * 2);
                            value.value = rgb;
                            break;
                        }
                        case 2: value.value = SferaEffectParameter::Radius{readMemory<float>(static_cast<std::uint32_t>(parameter))}; break;
                        case 3: value.value = SferaEffectParameter::Jitter{readMemory<std::uint8_t>(static_cast<std::uint32_t>(parameter))}; break;
                        case 4: value.value = SferaEffectParameter::Frequency{readMemory<std::uint8_t>(static_cast<std::uint32_t>(parameter))}; break;
                        default: break;
                    }
                    if (!execution_failed) pushInteger(g_sfera_effect_manager.setEffectParameters(handle, {&value, 1}));
                    break;
                }
                if (argument_count >= 3 && static_cast<std::uint32_t>(handle) == g_sfera_world_objects.controlled_object_handle) { pushInteger(UINT32_MAX); break; }
                created = g_sfera_effect_manager.createActiveEffect(static_cast<std::uint32_t>(effect), handle);
            }
            if (created == nullptr) { pushInteger(UINT32_MAX); break; }
            try { pushInteger(nativeHandle(created)); }
            catch (...) {
                auto& manager = g_sfera_effect_manager;
                const auto found = std::find_if(manager.active_effects.begin(), manager.active_effects.end(), [&](const auto& item) { return item.get() == created; });
                if (found != manager.active_effects.end()) {
                    const auto rollback = *found;
                    try { manager.removeActiveEffect(rollback.get()); } catch (...) {}
                    manager.retireEffect(*rollback);
                }
                throw;
            }
            break;
        }
        case Builtin::MovementContact: {
            const auto handle = nextInteger();
            if (handle < 0) { pushInteger(0); break; }
            std::uint32_t result = 0, direction = 0, depth = 0;
            if (argument_count == 5) { result = nextInteger(); direction = nextInteger(); depth = nextInteger(); nextInteger(); }
            if (execution_failed) break;
            if (argument_count <= 1) { pushInteger(g_sfera_contacts.testMovement(handle, false)); break; }
            auto* object = g_sfera_world_objects.object(handle, "GetObjectPointer");
            g_sfera_mbc_runtime.current_object = object;
            if (object == nullptr) { active_tag = UINT32_MAX; break; }
            auto* extended = SphereRender::CharacterModels::checkedExtended(object);
            pushInteger(extended->movement_blocked ? 0 : UINT32_MAX);
            extended->movement_blocked = false;
            if (argument_count == 5) {
                writeMemory(result, std::uint32_t(extended->avoidance_enabled));
                if (extended->avoidance_enabled) { if (direction != 0) writeMemory(direction, extended->avoidance_direction); if (depth != 0) writeMemory(depth, extended->avoidance_depth); }
            }
            break;
        }
        case Builtin::FileChecksum: {
            nextInteger();
            if (!execution_failed) pushInteger(0);
            break;
        }
        case Builtin::MemoryChecksum: {
            nextInteger();
            auto& slice = nextSliceReference();
            const std::uint32_t size = nextInteger();
            if (execution_failed) break;
            if (!slice.contains(size)) slice.diagnoseRange(size);
            pushInteger(0);
            break;
        }
        case Builtin::CompareMemory: {
            const auto left = nextSliceReference().base;
            if (left == 0) reportError("poppointerup(): unexpected NULL-pointer fetched");
            const auto right = nextSliceReference().base;
            if (right == 0) reportError("poppointerup(): unexpected NULL-pointer fetched");
            const std::uint32_t size = nextInteger();
            if (!execution_failed) { const auto result = std::memcmp(memoryAt(left), memoryAt(right), size); pushInteger((result > 0) - (result < 0)); }
            break;
        }
        case Builtin::PlayerLists: {
            const auto command = nextInteger();
            if (command < 1 || command > 11) break;
            auto& manager = g_sfera_player_lists;
            const auto text = [&](int offset) { return textAt(offset); };
            const auto name = [&](int offset) { const auto* value = text(offset); return std::string_view(value, ::strnlen(value, 149)); };
            const auto lookup = [&](int offset) { return manager.find(name(offset)); };
            const auto copyName = [&](std::uint32_t address, std::string_view value) {
                auto* output = memoryAt(address, value.size() + 1);
                std::copy(value.begin(), value.end(), output);
                output[value.size()] = 0;
            };
            switch (command) {
                case 1: {
                    const auto listName = nextInteger(); const auto minimum = nextInteger(); nextInteger(); const auto mode = nextInteger(); const auto parameter = nextInteger();
                    if (!execution_failed) pushInteger(manager.create(name(listName), minimum, mode, parameter != 0));
                    break;
                }
                case 2: { const auto listName = nextInteger(); if (!execution_failed) pushInteger(manager.erase(name(listName))); break; }
                case 3: {
                    const auto listName = nextInteger(); const auto itemName = nextInteger(); const auto a = nextInteger(); const auto b = nextInteger(); const auto c = nextInteger(); const auto size = std::clamp(nextInteger(), 0, 256); const auto data = nextInteger();
                    if (execution_failed) break;
                    auto* list = lookup(listName);
                    if (list == nullptr) { pushInteger(-1); break; }
                    PlayerListEntry item;
                    item.name = name(itemName);
                    item.attributes = {a, b, c};
                    if (size != 0) {
                        const auto* bytes = memoryAt(data, static_cast<std::size_t>(size));
                        item.payload.assign(bytes, bytes + size);
                    }
                    pushInteger(list->insert(std::move(item)));
                    break;
                }
                case 4: {
                    const auto listName = nextInteger(); const auto itemName = nextInteger();
                    if (execution_failed) break;
                    auto* list = lookup(listName);
                    if (list == nullptr) { pushInteger(-1); break; }
                    pushInteger(manager.removeItem(*list, name(itemName)));
                    break;
                }
                case 5: case 6: case 7: {
                    const auto first = nextInteger();
                    const auto second = command == 6 ? 0 : nextInteger();
                    const char* operation = command == 5 ? "L_FFITEM" : command == 6 ? "L_FNITEM" : "L_FINDITEM";
                    std::array<int, 4> fields;
                    for (std::size_t index = 0; index < fields.size(); ++index) {
                        fields[index] = nextInteger();
                        if (fields[index] == 0 && !(command == 7 && index == 3)) { char message[128]; std::snprintf(message, sizeof(message), "NULL-pointer dereferencing: list, %s, %u\n", operation, static_cast<unsigned>(index + 1)); WorldDiagnostics::warning(message); }
                    }
                    const auto payload = nextInteger();
                    if (execution_failed) break;
                    auto* current = command == 6 ? manager.currentList() : manager.selectList(name(first));
                    const auto nameOutput = command == 6 ? first : second;
                    if (current == nullptr) { if (command != 7) *text(nameOutput) = '\0'; pushInteger(-1); break; }
                    auto* item = command == 7 ? current->find(name(second)) : command == 5 ? current->first() : current->next();
                    if (item == nullptr) { if (command != 7) *text(nameOutput) = '\0'; pushInteger(-2); break; }
                    if (command != 7) copyName(nameOutput, item->name);
                    writeMemory(fields[0], item->attributes[0]); writeMemory(fields[1], item->attributes[1]); writeMemory(fields[2], item->attributes[2]);
                    if (command != 7) writeMemory(fields[3], static_cast<std::uint32_t>(item->payload.size()));
                    if (payload != 0 && !item->payload.empty()) std::copy(item->payload.begin(), item->payload.end(), memoryAt(payload, item->payload.size()));
                    if (command == 7) { if (fields[3] == 0) WorldDiagnostics::warning("NULL-pointer dereferencing: list, L_FINDITEM, 4\n"); writeMemory(fields[3], static_cast<std::uint32_t>(item->payload.size())); }
                    pushInteger(0);
                    break;
                }
                case 8: {
                    const auto listName = nextInteger(); const auto output = nextInteger(); const auto a = nextInteger(); const auto b = nextInteger(); const auto c = nextInteger();
                    if (execution_failed) break;
                    auto* list = lookup(listName);
                    const auto* item = list == nullptr ? nullptr : list->select({a, b, c});
                    copyName(output, item == nullptr ? std::string_view{} : item->name);
                    pushInteger(item == nullptr || item->name.empty() ? -1 : 0);
                    break;
                }
                case 9: {
                    const auto listName = nextInteger(); const auto itemName = nextInteger(); const float x = nextReal(); const float y = nextReal(); const float z = nextReal();
                    if (execution_failed) break;
                    auto* list = lookup(listName);
                    if (list == nullptr) { pushInteger(-1); break; }
                    auto* item = list->find(name(itemName));
                    if (item == nullptr) { pushInteger(-1); break; }
                    item->position = {x, y, z};
                    pushInteger(list->publish_mode == 1 ? 0 : -1);
                    break;
                }
                case 10: {
                    const auto listName = nextInteger(); const auto itemName = nextInteger();
                    std::array<int, 3> outputs;
                    for (std::size_t index = 0; index < outputs.size(); ++index) { outputs[index] = nextInteger(); if (outputs[index] == 0) { char message[128]; std::snprintf(message, sizeof(message), "NULL-pointer dereferencing: list, L_FINDITEM, %u\n", static_cast<unsigned>(index + 1)); WorldDiagnostics::warning(message); } }
                    if (execution_failed) break;
                    auto* list = manager.selectList(name(listName));
                    if (list == nullptr) { pushInteger(-2); break; }
                    const auto* item = list->find(name(itemName));
                    if (item == nullptr) { pushInteger(-1); break; }
                    writeMemory(outputs[0], item->position.x); writeMemory(outputs[1], item->position.y); writeMemory(outputs[2], item->position.z); pushInteger(0);
                    break;
                }
                case 11: pushInteger(0); break;
            }
            break;
        }
        case Builtin::FindProcess: {
            const bool byName = g_sfera_mbc_runtime.values[argument_cursor].type == SferaMbcValue::BytePointer;
            const char* name = nullptr;
            std::uint32_t module = 0;
            if (byName) { const auto slice = nextSliceReference(); if (slice.base == 0) WorldDiagnostics::warning("NULL-pointer dereferencing: ffprc_id\n"); name = textAt(slice.base); }
            else module = nextInteger();
            auto index = process_chain_first;
            if (argument_count > 1) {
                const std::uint32_t previous = nextInteger();
                if (previous >= std::size(processes) || processes[previous].chain_next_index == previous) { pushInteger(-1); break; }
                index = processes[previous].chain_next_index;
            }
            if (execution_failed) break;
            int result = -1;
            for (std::size_t visited = 0; visited < std::size(processes) && index >= 0 && static_cast<std::size_t>(index) < std::size(processes); ++visited) {
                const auto& process = processes[index];
                if (process.chain_prev_index == -1) break;
                if (byName ? std::strcmp(name, process.name) == 0 : module == 0 || process.module_tag == module) { result = process.process_id; break; }
                if (process.chain_next_index == index) break;
                index = process.chain_next_index;
            }
            pushInteger(result);
            break;
        }

        case Builtin::Sin: case Builtin::Cos: case Builtin::Exp: case Builtin::AbsoluteReal: case Builtin::SquareRoot: case Builtin::RealValue: {
            const double value = nextReal();
            double result = value;
            if (builtin == Builtin::Sin) result = std::sin(value);
            else if (builtin == Builtin::Cos) result = std::cos(value);
            else if (builtin == Builtin::Exp) result = std::exp(value);
            else if (builtin == Builtin::AbsoluteReal || builtin == Builtin::SquareRoot) { result = value < 0.0 ? -value : value; if (builtin == Builtin::SquareRoot) result = std::sqrt(result); }
            pushReal(static_cast<float>(result));
            break;
        }
        case Builtin::ArcTangent: { const double y = nextReal(); const double x = nextReal(); pushReal(static_cast<float>(std::atan2(y, x))); break; }
        case Builtin::AbsoluteInteger: case Builtin::IntegerValue: { const auto value = nextInteger(); pushInteger(builtin == Builtin::AbsoluteInteger && value < 0 ? 0u - static_cast<std::uint32_t>(value) : static_cast<std::uint32_t>(value)); break; }
        case Builtin::RandomReal: pushReal(static_cast<float>(static_cast<double>(std::rand()) / 32768.0)); break;
        case Builtin::SimulationTick: pushInteger(g_sfera_mbc_runtime.simulation_tick); break;
        case Builtin::PackColor: { const auto red = nextInteger(); const auto green = nextInteger(); const auto blue = nextInteger(); pushInteger(D3DCOLOR_XRGB(red, green, blue)); break; }
        case Builtin::ScaleColor: {
            const auto color = SferaColor::fromArgb(static_cast<std::uint32_t>(nextInteger()));
            const double factor = nextReal();
            const std::uint8_t red = SferaMbcValue::truncate(static_cast<double>(color.red()) * factor);
            const std::uint8_t green = SferaMbcValue::truncate(static_cast<double>(color.green()) * factor);
            const std::uint8_t blue = SferaMbcValue::truncate(static_cast<double>(color.blue()) * factor);
            pushInteger(D3DCOLOR_XRGB(red, green, blue));
            break;
        }
        case Builtin::SceneContext: {
            if (argument_count == 0) pushInteger(g_sfera_direct_input_runtime.virtual_key);
            const auto kind = nextInteger();
            pushInteger(kind == 0 ? g_sfera_direct_input_runtime.virtual_key : kind == 1 ? g_sfera_direct_input_runtime.character : g_sfera_direct_input_runtime.scan_code);
            break;
        }
        case Builtin::KeyboardState: { const std::uint32_t key = nextInteger(); pushInteger(SferaClientApplication::application_active && key < std::size(g_sfera_direct_input_runtime.keyboard_state) ? static_cast<std::int8_t>(g_sfera_direct_input_runtime.keyboard_state[key]) : 0); break; }
        case Builtin::ProcessModule: {
            const std::uint32_t index = nextInteger();
            const bool valid = index < std::size(processes) && processes[index].process_id == index && processes[index].chain_prev_index >= 0;
            if (!execution_failed) pushInteger(valid ? processes[index].module_tag : UINT32_MAX);
            break;
        }
        case Builtin::ActiveTag: pushInteger(active_tag); break;
        case Builtin::ArgumentCount: pushInteger(argument_count); break;
        case Builtin::CurrentModule: pushInteger(processes[process_index].module_tag); break;
        case Builtin::CurrentProcess: pushInteger(processes[process_index].process_id); break;
        case Builtin::ZeroResult: case Builtin::ZeroResultAlternate: pushInteger(0); break;
        case Builtin::TickDifference: {
            const std::uint32_t first = nextInteger();
            const std::uint32_t second = nextInteger();
            pushInteger(static_cast<std::uint32_t>(SferaNetworkRuntime::tickDifference(first, second)));
            break;
        }
        case Builtin::ProfileValue:
            nextInteger();
            if (!execution_failed) pushInteger(0);
            break;
        case Builtin::ProcessFlag: pushInteger(active_process->flags & SferaMbcProcessRecord::unloadAfterExecution); break;
        case Builtin::NextDefaultValue:
            pushInteger(0);
            break;
        case Builtin::CallerProcess: pushInteger(static_cast<int>(execution_context_depth) > 0 ? execution_context_stack[execution_context_depth - 1].process_id : UINT32_MAX); break;
        case Builtin::DiscardArgument: { const auto& argument = g_sfera_mbc_runtime.values[argument_cursor]; if (!argument.isPointer() && argument.type == SferaMbcValue::Real) nextReal(); else nextInteger(); break; }
        case Builtin::StopInterpreter: {
            if (argument_count != 1) halt_state = SferaMbcRuntime::HaltState::Requested;
            else { const auto mode = nextInteger(); if (mode == 0) halt_state = SferaMbcRuntime::HaltState::Requested; else if (mode == 1 || mode == -1) SferaClientApplication::quit_requested = true; }
            break;
        }
        case Builtin::NetworkInitialization: pushInteger(g_sfera_network_runtime.initialization_result); break;
        case Builtin::InvalidResult: pushInteger(UINT32_MAX); break;
        case Builtin::BitAnd: case Builtin::BitOr: case Builtin::BitXor: case Builtin::BitNot: case Builtin::ShiftLeft: case Builtin::ShiftRight: case Builtin::ClearBit: case Builtin::SetBit: case Builtin::TestBit: {
            std::uint32_t result = nextInteger();
            const auto argument = builtin == Builtin::BitNot ? 0u : static_cast<std::uint32_t>(nextInteger());
            const auto shift = argument % std::numeric_limits<std::uint32_t>::digits;
            if (builtin == Builtin::BitAnd) result &= argument;
            else if (builtin == Builtin::BitOr) result |= argument;
            else if (builtin == Builtin::BitXor) result ^= argument;
            else if (builtin == Builtin::BitNot) result = ~result;
            else if (builtin == Builtin::ShiftLeft) result <<= shift;
            else if (builtin == Builtin::ShiftRight) result = std::bit_cast<int>(result) >> shift;
            else if (builtin == Builtin::ClearBit) result &= ~(1u << shift);
            else if (builtin == Builtin::SetBit) result |= 1u << shift;
            else result = std::bit_cast<int>(result & (1u << shift)) >> shift;
            pushInteger(result);
            break;
        }
        case Builtin::CopyString: case Builtin::CopyStringCount: case Builtin::AppendString: {
            auto& destination = nextSliceReference();
            auto& source = nextSliceReference();
            const auto count = builtin == Builtin::CopyStringCount ? nextInteger() : 0;
            if (!source.contains()) { source.diagnoseRange(0); ++value_stack_size; break; }
            auto* output = textAt(destination.base);
            const auto* input = textAt(source.base);
            std::uint32_t length = 0;
            if (builtin == Builtin::AppendString) {
                if (!destination.contains()) destination.diagnoseRange(0);
                const auto prefix = std::strlen(output);
                length = prefix + std::strlen(input) + 1;
                if (!destination.contains(length)) destination.diagnoseRange(length);
                if (argument_count > 2 && static_cast<int>(length) > nextInteger()) { WorldDiagnostics::warning("Size mismatch: ffstrcat\n"); ++value_stack_size; break; }
                if (execution_failed) break;
                std::memmove(output + prefix, input, length - prefix);
            } else {
                const auto capacity = builtin == Builtin::CopyString && argument_count == 3 ? nextInteger() : 0;
                if (execution_failed) break;
                if (builtin == Builtin::CopyString) length = SferaText::copyString(output, input, capacity);
                else {
                    if (count < 0) { reportError("Negative string length"); break; }
                    std::size_t copied = 0;
                    while (copied < static_cast<std::uint32_t>(count) && input[copied] != '\0') ++copied;
                    std::memcpy(output, input, copied);
                    std::memset(output + copied, 0, static_cast<std::uint32_t>(count) - copied + 1);
                    length = copied + 1;
                }
                if (!destination.contains(length)) destination.diagnoseRange(length);
            }
            ++value_stack_size;
            break;
        }
        case Builtin::FindString: case Builtin::FindStringInsensitive: {
            auto& haystack = nextSliceReference();
            const auto needle = nextSliceReference();
            if (execution_failed) break;
            const auto* text = textAt(haystack.base);
            const auto* match = textAt(needle.base);
            const auto* found = builtin == Builtin::FindString ? std::strstr(text, match) : SferaText::findInsensitive(text, match);
            if (found == nullptr) pushSlice({}, SferaMbcValue::BytePointer);
            else { haystack.base += static_cast<std::uint32_t>(found - text); pushSlice(haystack, SferaMbcValue::BytePointer); }
            break;
        }
        case Builtin::StringLength: {
            const auto slice = nextSliceReference();
            if (slice.base == 0) WorldDiagnostics::warning("ffstrlen(): NULL-pointer dereferencing\n");
            const auto* text = textAt(slice.base);
            std::uint32_t length = 0;
            if (argument_count > 1) {
                const auto limit = nextInteger();
                while (static_cast<int>(length) < limit && text[length] != '\0') ++length;
                if (static_cast<int>(length) == limit) { char message[128]; std::snprintf(message, sizeof(message), "ffstrlen(): end of string was not found in buffer of size %d\n", limit); WorldDiagnostics::warning(message); }
            } else length = std::strlen(text);
            pushInteger(length);
            break;
        }
        case Builtin::CompareStrings: case Builtin::CompareStringsInsensitive: case Builtin::CompareStringsCount: case Builtin::CompareStringsCountInsensitive: {
            const auto first = nextInteger();
            const auto second = nextInteger();
            const auto* left = textAt(first);
            const auto* right = textAt(second);
            int result;
            if (builtin == Builtin::CompareStrings) { const auto comparison = std::strcmp(left, right); result = (comparison > 0) - (comparison < 0); }
            else if (builtin == Builtin::CompareStringsInsensitive) result = ::_stricmp(left, right);
            else { const std::uint32_t count = nextInteger(); result = builtin == Builtin::CompareStringsCount ? std::strncmp(left, right, count) : ::_strnicmp(left, right, count); }
            pushInteger(result);
            break;
        }
        case Builtin::CopyMemory: case Builtin::MoveMemory: case Builtin::FillMemory: {
            auto& destination = nextSliceReference();
            const auto source = builtin == Builtin::FillMemory ? SferaSliceReference32{static_cast<std::uint32_t>(nextInteger()), 0, 0} : nextSliceReference();
            const std::uint32_t count = nextInteger();
            if (execution_failed) break;
            if (count && (!destination.contains(count))) destination.diagnoseRange(count);
            auto* output = memoryAt(destination.base);
            if (builtin == Builtin::FillMemory) std::memset(output, static_cast<std::uint8_t>(source.base), count);
            else { const auto* input = memoryAt(source.base); if (builtin == Builtin::MoveMemory) std::memmove(output, input, count); else std::memcpy(output, input, count); }
            break;
        }
        case Builtin::WriteByte: case Builtin::WriteShort: case Builtin::WriteThreeBytes: case Builtin::WriteWord: case Builtin::WriteReal: {
            auto destination = nextSliceReference();
            const auto value = builtin == Builtin::WriteReal ? std::bit_cast<std::uint32_t>(nextReal()) : static_cast<std::uint32_t>(nextInteger());
            const std::size_t width = builtin == Builtin::WriteByte ? 1 : builtin == Builtin::WriteShort ? 2 : builtin == Builtin::WriteThreeBytes ? 3 : sizeof(std::uint32_t);
            if (execution_failed) break;
            if (!destination.contains(width)) destination.diagnoseRange(width);
            else { std::memcpy(memoryAt(destination.base), &value, width); destination.base += width; }
            pushSlice(destination, SferaMbcValue::BytePointer);
            break;
        }
        case Builtin::ReadByte: case Builtin::ReadShort: case Builtin::ReadThreeBytes: case Builtin::ReadWord: case Builtin::ReadReal: {
            auto source = nextSliceReference();
            auto& destination = nextSliceReference();
            const std::size_t width = builtin == Builtin::ReadByte ? 1 : builtin == Builtin::ReadShort ? 2 : builtin == Builtin::ReadThreeBytes ? 3 : sizeof(std::uint32_t);
            if (execution_failed) break;
            if (!source.contains(width)) { source.diagnoseRange(width); if (builtin == Builtin::ReadReal) break; }
            else if (!destination.contains(width)) { destination.diagnoseRange(width); if (builtin == Builtin::ReadReal) break; }
            else {
                if (builtin == Builtin::ReadShort || builtin == Builtin::ReadThreeBytes) writeMemory(destination.base, std::uint32_t{});
                std::memcpy(memoryAt(destination.base), memoryAt(source.base), width);
                source.base += width;
            }
            pushSlice(source, SferaMbcValue::BytePointer);
            break;
        }
        case Builtin::WriteString: case Builtin::ReadString: {
            auto cursor = nextSliceReference();
            auto& argument = nextSliceReference();
            const bool writing = builtin == Builtin::WriteString;
            auto& source = writing ? argument : cursor;
            auto& destination = writing ? cursor : argument;
            if (!source.contains()) { source.diagnoseRange(0); break; }
            if (execution_failed) break;
            const auto* input = textAt(source.base);
            const std::uint32_t length = std::strlen(input) + 1;
            std::memcpy(memoryAt(destination.base), input, length);
            if (!cursor.contains(length)) cursor.diagnoseRange(length);
            else cursor.base += length;
            pushSlice(cursor, SferaMbcValue::BytePointer);
            break;
        }
        case Builtin::LowerBoundInteger: {
            auto values = nextSlice();
            const auto count = nextInteger();
            const auto key = nextInteger();
            if (execution_failed) break;
            const auto length = static_cast<std::uint32_t>(count) * sizeof(int);
            if (!values.contains(length)) values.diagnoseRange(length);
            if (count < 0) { pushInteger(UINT32_MAX); break; }
            int begin = 0, end = count - 1;
            while (begin < end) { const auto middle = begin + (end - begin) / 2; if (readMemory<int>(values.base + middle * sizeof(int)) < key) begin = middle + 1; else end = middle; }
            pushInteger(begin);
            break;
        }
        case Builtin::PositionX: case Builtin::PositionY: case Builtin::PositionZ: case Builtin::RotationX: case Builtin::RotationY: case Builtin::RotationZ: {
            const auto handle = nextInteger();
            const bool position = builtin <= Builtin::PositionZ;
            const auto* object = g_sfera_world_objects.object(handle, position ? "GetPos" : "GetAngles");
            if (object == nullptr) { pushReal(0.0f); break; }
            const std::size_t axis = builtin == Builtin::PositionX || builtin == Builtin::RotationX ? 0 : builtin == Builtin::PositionY || builtin == Builtin::RotationY ? 1 : 2;
            if (!position || !execution_failed) pushReal((position ? object->position : object->rotation).component(axis));
            break;
        }
        case Builtin::SetRotation: case Builtin::MoveLocal: case Builtin::MoveForward: case Builtin::Rotate: {
            const auto handle = nextInteger();
            if (builtin == Builtin::SetRotation && handle < 0) break;
            SferaVec3F value{};
            if (builtin == Builtin::MoveForward) value.z = nextReal();
            else { value.x = nextReal(); value.y = nextReal(); value.z = nextReal(); }
            if (builtin == Builtin::SetRotation) { auto* object = g_sfera_world_objects.object(handle, "GetObjectPointer"); if (object == nullptr) active_tag = UINT32_MAX; else if (!execution_failed) object->rotation = value; }
            else if (!execution_failed) { if (builtin == Builtin::Rotate) g_sfera_world_objects.rotate(handle, value); else g_sfera_world_objects.moveLocal(handle, value); }
            break;
        }
        case Builtin::ContainerCommand: {
            auto* container = nativeResource<SferaScriptContainer*>(static_cast<std::uint32_t>(nextInteger()));
            if (container == nullptr) pushInteger(UINT32_MAX);
            else if (container->header.kind >= SferaDataContainerHeader::Kind::List && container->header.kind <= SferaDataContainerHeader::Kind::HashMap) container->execute(*this);
            break;
        }
        case Builtin::ContainerManagement: {
            using Kind = SferaScriptContainer::Kind;
            using ValueType = SferaScriptContainer::ValueType;
            using Lifecycle = SferaScriptContainer::Lifecycle;
            const auto command = static_cast<Lifecycle>(nextInteger());
            if (command == Lifecycle::Create) {
                const auto kind = static_cast<Kind>(nextInteger());
                if (kind < Kind::List || kind > Kind::HashMap) { pushInteger(0); break; }
                const auto keyType = kind == Kind::Map || kind == Kind::HashMap ? static_cast<ValueType>(nextInteger()) : ValueType::Integer;
                const auto valueType = static_cast<ValueType>(nextInteger());
                auto container = SferaScriptContainer::create(kind, valueType, keyType);
                std::uint32_t handle = 0;
                if (container) {
                    auto* pointer = container.get();
                    try {
                        handle = nativeHandle(pointer);
                        containers.emplace(handle, std::move(container));
                        active_process->registerResource(handle, ResourceKind::container);
                    } catch (...) {
                        forgetNativeResource(pointer);
                        containers.erase(handle);
                        throw;
                    }
                }
                pushInteger(handle);
                break;
            }
            if (command < Lifecycle::Destroy || command > Lifecycle::KeyType) { pushInteger(UINT32_MAX); break; }
            const std::uint32_t handle = nextInteger();
            if (command == Lifecycle::Destroy) active_process->unregisterResource(handle, ResourceKind::container);
            auto* container = nativeResource<SferaScriptContainer*>(handle);
            if (container == nullptr) { pushInteger(UINT32_MAX); break; }
            const auto kind = container->header.kind;
            switch (command) {
                case Lifecycle::Destroy:
                    if (kind >= Kind::List && kind <= Kind::HashMap) { destroyContainer(handle); pushInteger(0); }
                    else pushInteger(UINT32_MAX);
                    break;
                case Lifecycle::Kind: pushInteger(static_cast<std::uint32_t>(kind)); break;
                case Lifecycle::ValueType: pushInteger(kind == Kind::List || kind == Kind::Vector || kind == Kind::Map || kind == Kind::HashMap ? static_cast<std::uint32_t>(container->value_type) : UINT32_MAX); break;
                case Lifecycle::KeyType: pushInteger(kind == Kind::Set ? static_cast<std::uint32_t>(container->value_type) : kind == Kind::Map || kind == Kind::HashMap ? static_cast<std::uint32_t>(container->key_type) : UINT32_MAX); break;
                default: break;
            }
            break;
        }
        default: return false;
    }
    return true;
}

template<class C, bool Hashed>
SferaScriptContainer::Content<C, Hashed>::Content() {
    if constexpr (Hashed) buckets.assign(8, {values.end(), values.end()});
}

template<class C, bool Hashed>
template<class K>
std::size_t SferaScriptContainer::Content<C, Hashed>::bucketIndex(const K& key) const requires Hashed {
    std::uint32_t hash;
    if constexpr (std::is_integral_v<K>) {
        // The script container uses the Park-Miller reduction, including signed keys.
        constexpr int quotient = 127773, multiplier = 16807, remainder = 2836, modulus = 2147483647;
        const auto reduced = (key % quotient) * multiplier - (key / quotient) * remainder;
        hash = static_cast<std::uint32_t>(reduced < 0 ? reduced + modulus : reduced);
    } else {
        // Its byte hash is FNV-1 with signed octets; FNV-1a changes script iteration order.
        constexpr std::uint32_t offsetBasis = 2166136261u, prime = 16777619u;
        hash = offsetBasis;
        const std::size_t step = std::is_same_v<K, std::string> ? key.size() / 10 + 1 : 1;
        for (std::size_t index = 0; index < key.size(); index += step) hash = (hash * prime) ^ static_cast<std::uint32_t>(static_cast<std::int8_t>(key[index]));
    }
    return hash % buckets.size();
}

template<class C, bool Hashed>
template<class K>
typename C::iterator SferaScriptContainer::Content<C, Hashed>::find(const K& key) requires Hashed {
    const auto& [first, last] = buckets[bucketIndex(key)];
    if (first == values.end()) return values.end();
    const auto end = std::next(last);
    const auto found = std::find_if(first, end, [&](const Value& value) { return value.first == key; });
    return found == end ? values.end() : found;
}

template<class C, bool Hashed>
void SferaScriptContainer::Content<C, Hashed>::rehash(std::size_t count) requires Hashed {
    decltype(buckets) replacement(count, {values.end(), values.end()});
    C pending;
    buckets.swap(replacement);
    pending.splice(pending.end(), values);
    while (!pending.empty()) {
        const auto node = pending.begin();
        auto& [first, last] = buckets[bucketIndex(node->first)];
        if (first == values.end()) last = node;
        values.splice(first, pending, node);
        first = node;
    }
}

template<class C, bool Hashed>
template<class K, class V>
void SferaScriptContainer::Content<C, Hashed>::assign(K&& key, V&& value) requires Hashed {
    const auto found = find(key);
    if (found != values.end()) { found->second = std::forward<V>(value); return; }
    auto& [first, last] = buckets[bucketIndex(key)];
    const auto node = values.emplace(first, std::forward<K>(key), std::forward<V>(value));
    if (first == values.end()) last = node;
    first = node;
    if (static_cast<float>(static_cast<double>(values.size()) / buckets.size()) <= 1.0f) return;
    auto count = buckets.size();
    for (unsigned step = 0; step < 3; ++step) {
        if (count > buckets.max_size() / 2) throw std::length_error("Script hash container is too large");
        count *= 2;
    }
    rehash(count);
}

template<class C, bool Hashed>
void SferaScriptContainer::Content<C, Hashed>::erase(typename C::iterator position) requires Hashed {
    auto& [first, last] = buckets[bucketIndex(position->first)];
    if (first == last) first = last = values.end();
    else if (position == first) first = std::next(position);
    else if (position == last) last = std::prev(position);
    values.erase(position);
}

std::unique_ptr<SferaScriptContainer> SferaScriptContainer::create(Kind kind, ValueType type, ValueType keyType) {
    const auto construct = [&]<class C, bool Hashed = false>() -> std::unique_ptr<SferaScriptContainer> {
        return std::make_unique<SferaScriptContainer>(kind, type, std::in_place_type<Content<C, Hashed>>, keyType);
    };
    const auto select = [&]<class T>() -> std::unique_ptr<SferaScriptContainer> {
        if constexpr (!std::is_same_v<T, std::uint8_t>) if (kind == Kind::Map) {
            if (keyType == ValueType::Integer) return construct.template operator()<std::map<int, T>>();
            if (keyType == ValueType::String) return construct.template operator()<std::map<std::string, T>>();
            return nullptr;
        }
        if constexpr (!std::is_same_v<T, std::uint8_t>) if (kind == Kind::HashMap) {
            if (keyType == ValueType::Integer) return construct.template operator()<std::list<std::pair<const int, T>>, true>();
            if (keyType == ValueType::String) return construct.template operator()<std::list<std::pair<const std::string, T>>, true>();
            if (keyType == ValueType::Binary) return construct.template operator()<std::list<std::pair<const Binary, T>>, true>();
            return nullptr;
        }
        if constexpr (!std::is_same_v<T, std::uint8_t>) if (kind == Kind::List) return construct.template operator()<std::list<T>>();
        if (kind == Kind::Vector) return construct.template operator()<std::vector<T>>();
        if constexpr (std::is_same_v<T, int> || std::is_same_v<T, std::string>) if (kind == Kind::Set) return construct.template operator()<std::set<T>>();
        return nullptr;
    };
    switch (type) {
        case ValueType::Integer: return select.template operator()<int>();
        case ValueType::Real: return select.template operator()<float>();
        case ValueType::Byte: return select.template operator()<std::uint8_t>();
        case ValueType::String: return select.template operator()<std::string>();
        case ValueType::Binary: return select.template operator()<Binary>();
        default: return nullptr;
    }
}

std::uint32_t SferaMbcRuntime::allocateDynamic(std::size_t size) {
    if (size == 0 || size >= mappedAddressBegin) throw std::length_error("Invalid dynamic array size");
    auto block = std::make_unique<std::vector<std::uint8_t>>(size);
    const auto* owner = block.get();
    const auto address = mapMemory(block->data(), block->size(), owner);
    try { dynamic_blocks.emplace(address, std::move(block)); }
    catch (...) { forgetMemory(owner); throw; }
    return address;
}

bool SferaMbcRuntime::releaseDynamic(std::uint32_t address) noexcept {
    const auto found = dynamic_blocks.find(address);
    if (found == dynamic_blocks.end()) return false;
    forgetMemory(found->second.get());
    dynamic_blocks.erase(found);
    return true;
}

void SferaMbcRuntime::destroyContainer(std::uint32_t handle) noexcept {
    const auto found = containers.find(handle);
    if (found == containers.end()) return;
    auto* container = found->second.get();
    forgetMemory(container);
    forgetNativeResource(container);
    containers.erase(found);
}

void SferaMbcRuntime::exportSlice(SferaSliceReference32& destination, const void* data, std::size_t size, const void* owner) {
    if (!destination.contains(sizeof(SferaSliceReference32))) destination.diagnoseRange(sizeof(SferaSliceReference32));
    if (size >= mappedAddressBegin) throw std::length_error("Script container value too large");
    const auto offset = mapMemory(data, size, owner);
    writeMemory(destination.base, SferaSliceReference32{offset, offset, offset + static_cast<std::uint32_t>(size) - 1});
}

void SferaScriptContainer::execute(SferaMbcRuntime& runtime) {
    const auto command = static_cast<Command>(runtime.nextInteger());
    std::visit([&](auto& state) {
        using State = std::remove_reference_t<decltype(state)>;
        using Value = typename State::Value;
        auto& values = state.values;
        const auto forgetValue = [&](const auto& value) {
            using T = std::remove_cvref_t<decltype(value)>;
            if constexpr (std::is_same_v<T, std::string> || std::is_same_v<T, Binary>) std::erase_if(runtime.mapped_memory, [&](const auto& entry) { return entry.second.owner == this && static_cast<const void*>(entry.second.data) == value.data(); });
        };
        const auto read = [&]<class T>() -> T {
            if constexpr (std::is_same_v<T, float>) return runtime.nextReal();
            else if constexpr (std::is_integral_v<T>) return static_cast<T>(runtime.nextInteger());
            else {
                auto& source = runtime.nextSliceReference();
                if constexpr (std::is_same_v<T, std::string>) return std::string(runtime.textAt(source.base));
                else {
                    const std::uint32_t length = runtime.nextInteger();
                    if (!source.contains(length)) source.diagnoseRange(length);
                    const auto* begin = runtime.memoryAt(source.base);
                    T result(begin, begin + length);
                    if (result.empty()) result.reserve(1);
                    return result;
                }
            }
        };
        const auto write = [&](SferaSliceReference32& destination, const auto& value) {
            using T = std::remove_cvref_t<decltype(value)>;
            if constexpr (std::is_arithmetic_v<T>) runtime.writeMemory(destination.base, value);
            else runtime.exportSlice(destination, value.data(), value.size() + (std::is_same_v<T, std::string> ? 1 : 0), this);
        };
        if constexpr (State::Mapped) {
            using Key = std::remove_const_t<typename Value::first_type>;
            using Mapped = typename Value::second_type;
            if (command == Command::IteratorState) { runtime.pushInteger(!header.iteration_active); return; }
            if (command == Command::First || command == Command::Next) {
                auto& keyDestination = runtime.nextSliceReference();
                auto& valueDestination = runtime.nextSliceReference();
                if (runtime.execution_failed) return;
                if (command == Command::First) { state.cursor = values.begin(); header.iteration_active = state.cursor != values.end(); }
                else if (header.iteration_active) { ++state.cursor; header.iteration_active = state.cursor != values.end(); }
                if (!header.iteration_active) { runtime.pushInteger(UINT32_MAX); return; }
                write(keyDestination, state.cursor->first);
                write(valueDestination, state.cursor->second);
                runtime.pushInteger(0);
                return;
            }
            if (command == Command::Clear) { runtime.forgetMemory(this); values.clear(); if constexpr (State::Hashed) state.buckets.assign(8, {values.end(), values.end()}); state.cursor = values.end(); header.iteration_active = false; runtime.pushInteger(0); return; }
            if (command >= Command::Write && command <= Command::Read) {
                auto key = read.template operator()<Key>();
                if (command == Command::Write) {
                    auto value = read.template operator()<Mapped>();
                    if (runtime.execution_failed) return;
                    const auto previous = [&] { if constexpr (State::Hashed) return state.find(key); else return values.find(key); }();
                    if (previous != values.end()) forgetValue(previous->second);
                    if constexpr (State::Hashed) state.assign(std::move(key), std::move(value));
                    else values.insert_or_assign(std::move(key), std::move(value));
                } else if (command == Command::Erase) {
                    if (runtime.execution_failed) return;
                    // The script API cancels iteration even when the erased key is absent.
                    header.iteration_active = false;
                    const auto found = [&] { if constexpr (State::Hashed) return state.find(key); else return values.find(key); }();
                    if (found != values.end()) { forgetValue(found->first); forgetValue(found->second); if constexpr (State::Hashed) state.erase(found); else values.erase(found); }
                    state.cursor = values.end();
                } else {
                    auto& destination = runtime.nextSliceReference();
                    if (runtime.execution_failed) return;
                    const auto found = [&] { if constexpr (State::Hashed) return state.find(key); else return values.find(key); }();
                    if (found == values.end()) { runtime.pushInteger(UINT32_MAX); return; }
                    write(destination, found->second);
                }
                runtime.pushInteger(0);
                return;
            }
            runtime.pushInteger(UINT32_MAX);
        } else {
            const auto at = [&](int index) {
                auto iterator = values.begin();
                if (index < 0 || static_cast<std::size_t>(index) >= values.size()) return values.end();
                std::advance(iterator, index);
                return iterator;
            };
            const auto current = [&]() {
                if constexpr (State::Indexed) return state.cursor < values.size() ? values.begin() + state.cursor : values.end();
                else return state.cursor;
            };
            const auto erase = [&](auto iterator) {
                forgetValue(*iterator);
                if constexpr (State::Indexed) {
                    const auto begin = reinterpret_cast<std::uintptr_t>(&*iterator);
                    const auto end = reinterpret_cast<std::uintptr_t>(values.data() + values.size());
                    std::erase_if(runtime.mapped_memory, [&](const auto& entry) { const auto address = reinterpret_cast<std::uintptr_t>(entry.second.data); return entry.second.owner == this && address >= begin && address < end; });
                    values.erase(iterator);
                    if (header.iteration_active && state.cursor >= values.size()) header.iteration_active = false;
                } else {
                    if (header.iteration_active && state.cursor == iterator) { ++state.cursor; header.iteration_active = state.cursor != values.end(); }
                    values.erase(iterator);
                }
            };
            if (command == Command::IteratorState) { runtime.pushInteger(State::Unique ? header.iteration_active : !header.iteration_active); return; }
            if (command == Command::First || command == Command::Next) {
                auto& destination = runtime.nextSliceReference();
                if (runtime.execution_failed) return;
                if (command == Command::First) {
                    if constexpr (State::Indexed) state.cursor = 0;
                    else state.cursor = values.begin();
                    header.iteration_active = !values.empty();
                } else if (header.iteration_active) {
                    ++state.cursor;
                    header.iteration_active = current() != values.end();
                }
                if (!header.iteration_active) { runtime.pushInteger(UINT32_MAX); return; }
                write(destination, *current());
                runtime.pushInteger(0);
                return;
            }
            if constexpr (State::Unique) {
                if (command == Command::Clear) { runtime.forgetMemory(this); values.clear(); state.cursor = values.end(); header.iteration_active = false; runtime.pushInteger(0); return; }
                if (command >= Command::Write && command <= Command::Read) {
                    const auto value = read.template operator()<Value>();
                    if (runtime.execution_failed) return;
                    if (command == Command::Write) values.insert(value);
                    else {
                        const auto found = values.find(value);
                        if (command == Command::Read) { runtime.pushInteger(found != values.end()); return; }
                        if (found != values.end()) erase(found);
                    }
                    runtime.pushInteger(0);
                    return;
                }
            } else {
                if (command == Command::Append || (!State::Indexed && command == Command::Prepend)) {
                    auto value = read.template operator()<Value>();
                    if (runtime.execution_failed) return;
                    if constexpr (!State::Indexed) { if (command == Command::Prepend) values.push_front(std::move(value)); else values.push_back(std::move(value)); }
                    else { if (values.size() == values.capacity()) runtime.forgetMemory(this); values.push_back(std::move(value)); }
                    runtime.pushInteger(0);
                    return;
                }
                if (command >= Command::Write && command <= Command::Read) {
                    const auto index = runtime.nextInteger();
                    if (command == Command::Write) {
                        auto value = read.template operator()<Value>();
                        if (runtime.execution_failed) return;
                        const auto found = at(index);
                        if (found == values.end()) { runtime.pushInteger(UINT32_MAX); return; }
                        forgetValue(*found);
                        *found = std::move(value);
                    } else if (command == Command::Erase) {
                        if (runtime.execution_failed) return;
                        const auto found = at(index);
                        if (found == values.end()) { runtime.pushInteger(UINT32_MAX); return; }
                        erase(found);
                    } else {
                        auto& destination = runtime.nextSliceReference();
                        if (runtime.execution_failed) return;
                        const auto found = at(index);
                        if (found == values.end()) { runtime.pushInteger(UINT32_MAX); return; }
                        write(destination, *found);
                    }
                    runtime.pushInteger(0);
                    return;
                }
            }
            runtime.pushInteger(UINT32_MAX);
        }
    }, content);
}

namespace {
    std::uint64_t* resourceLifetime(std::uint32_t handle, SferaMbcProcessRecord::ResourceKind kind) {
        using Kind = SferaMbcProcessRecord::ResourceKind;
        if (kind == Kind::gameWindow) { if (auto* item = GameInterface::window(handle)) return &item->resource_lifetime; }
        else if (kind == Kind::worldObject) { if (auto* item = g_sfera_world_objects.object(handle)) return &item->resource_lifetime; }
        else if (kind == Kind::textControl || kind == Kind::spriteControl) {
            if (auto* item = WorldGuiControls::control(handle)) return &item->resource_lifetime;
        }
        return nullptr;
    }

    bool resourceIsCurrent(const SferaMbcProcessRecord::CleanupEntry& entry) {
        if (entry.resource_lifetime == 0) return true;
        const auto* lifetime = resourceLifetime(entry.handle, entry.kind);
        return lifetime && *lifetime == entry.resource_lifetime;
    }
}

void SferaMbcProcessRecord::registerResource(std::uint32_t handle, ResourceKind kind) {
    auto* lifetime = resourceLifetime(handle, kind);
    static std::uint64_t nextLifetime = 1;
    if (lifetime && *lifetime == 0 && nextLifetime == 0) throw std::overflow_error("Resource lifetime IDs exhausted");
    const auto id = lifetime ? (*lifetime != 0 ? *lifetime : nextLifetime) : 0;
    cleanup_entries.push_back({handle, kind, id});
    if (lifetime && *lifetime == 0) { *lifetime = id; ++nextLifetime; }
}

void SferaMbcProcessRecord::unregisterResource(std::uint32_t handle, ResourceKind kind) {
    const auto found = std::find_if(cleanup_entries.begin(), cleanup_entries.end(), [&](const CleanupEntry& entry) {
        return entry.handle == handle && entry.kind == kind;
    });
    if (found != cleanup_entries.end()) cleanup_entries.erase(found);
}

std::size_t SferaConfigTextRuntime::copyText(std::string_view source) {
    std::string next(source.substr(0, text_capacity - 1));
    const auto count = next.size();
    storage_ = std::move(next); filename.clear();
    return count;
}
std::span<char> SferaConfigTextRuntime::borrowedBytes(const BorrowedText& view) const {
    if (view.process && (view.process->chain_prev_index < 0 || view.process->lifetime != view.process_lifetime))
        throw std::out_of_range("Configuration source process is no longer alive");
    if (g_sfera_mbc_runtime.memoryLifetime(view.address) != view.mapping_lifetime)
        throw std::out_of_range("Configuration source mapping was replaced");
    auto bytes = g_sfera_mbc_runtime.memoryRange(view.address, view.process);
    if (view.capacity > bytes.size()) throw std::out_of_range("Configuration source buffer shrank");
    return {reinterpret_cast<char*>(bytes.data()), view.capacity};
}
std::string_view SferaConfigTextRuntime::text() const {
    if (const auto* owned = std::get_if<std::string>(&storage_)) return *owned;
    const auto bytes = borrowedBytes(std::get<BorrowedText>(storage_));
    const auto end = std::find(bytes.begin(), bytes.end(), '\0');
    if (end == bytes.end()) throw std::out_of_range("Unterminated borrowed configuration");
    return {bytes.data(), static_cast<std::size_t>(end - bytes.begin())};
}

void SferaConfigTextRuntime::useText(std::uint32_t address, std::size_t capacity, SferaMbcProcessRecord* process) {
    if (address >= SferaMbcRuntime::mappedAddressBegin) process = nullptr;
    BorrowedText view{address, std::min(capacity, text_capacity), process, process ? process->lifetime : 0,
                      g_sfera_mbc_runtime.memoryLifetime(address)};
    const auto bytes = borrowedBytes(view);
    if (std::find(bytes.begin(), bytes.end(), '\0') == bytes.end()) throw std::out_of_range("Unterminated configuration source");
    storage_ = view; filename.clear();
}

std::optional<std::string_view> SferaConfigTextRuntime::find(std::string_view key) const {
    if (key.size() >= 4096) return std::nullopt;
    const auto input = text();
    const auto offset = SferaText::configValueOffset(input, key);
    return offset == std::string_view::npos ? std::nullopt : std::optional(input.substr(offset));
}

bool SferaConfigTextRuntime::readInteger(std::string_view key, int& value) const {
    const auto input = find(key);
    return input && SferaText::readNumber(*input, value);
}

bool SferaConfigTextRuntime::readFloat(std::string_view key, float& value) const {
    const auto input = find(key);
    return input && SferaText::readNumber(*input, value);
}

bool SferaConfigTextRuntime::readString(std::string_view key, char* destination, std::size_t capacity) const {
    const auto input = find(key);
    if (!input || input->empty() || input->front() != '"' || !destination || capacity == 0) return false;
    std::size_t written = 0;
    destination[0] = 0;
    for (char character : input->substr(1)) {
        if (character == '"' || character == '\0') { destination[written] = 0; return true; }
        if (character == '\n') continue;
        if (written + 1 >= capacity) { destination[written] = 0; return false; }
        destination[written++] = character == '\r' ? ' ' : character;
    }
    destination[written] = 0;
    return true;
}

bool SferaConfigTextRuntime::readBinary(std::string_view key, std::uint8_t* destination, std::size_t capacity) const {
    const auto input = find(key);
    if (!input) return false;
    std::size_t output_byte = 0;
    unsigned output_bit = 0;
    const auto append = [&](unsigned value, unsigned count) {
        if (!destination || output_byte >= capacity || (count > CHAR_BIT - output_bit && capacity - output_byte < 2)) return false;
        for (unsigned bit = 0; bit < count; ++bit) {
            const unsigned mask = 1u << output_bit;
            auto& byte = destination[output_byte];
            byte = static_cast<std::uint8_t>((byte & ~mask) | (((value >> bit) & 1u) << output_bit));
            if (++output_bit == CHAR_BIT) { output_bit = 0; ++output_byte; }
        }
        return true;
    };
    std::size_t cursor = 0;
    while (cursor < input->size() && (*input)[cursor] != '\0' && (*input)[cursor] != '#')
        if (!append(static_cast<unsigned char>((*input)[cursor++]) - '0', 6)) return false;
    if (cursor < input->size() && (*input)[cursor] == '#') {
        if (++cursor == input->size()) return false;
        const int count = static_cast<signed char>((*input)[cursor++]) - '0';
        if (count > 0 && (count > CHAR_BIT || cursor == input->size() || (*input)[cursor] == '\0' ||
            !append(static_cast<unsigned char>((*input)[cursor]) - '0', static_cast<unsigned>(count)))) return false;
    }
    return true;
}

std::size_t SferaConfigTextRuntime::copyTo(char* destination, std::size_t capacity) const {
    const auto input = text();
    const auto count = std::min(capacity, input.size());
    if (count != 0) { if (!destination) throw std::invalid_argument("Null configuration destination"); std::memmove(destination, input.data(), count); }
    return count;
}


void SferaErrorLogRuntime::initialize(IOutputDevice* error, IOutputDevice* log) {
    auto nextError = error == nullptr ? std::make_unique<CSphereError>() : nullptr;
    auto nextLog = log == nullptr ? std::make_unique<COutputLogDevice>() : nullptr;
    if (nextLog) nextLog->setFilename("sphere.log");
    if (error != nullptr && error == owned_error.get()) nextError = std::move(owned_error);
    if (log != nullptr && log == owned_log.get()) nextLog = std::move(owned_log);
    clear();
    owned_error = std::move(nextError);
    owned_log = std::move(nextLog);
    outputs[0] = owned_error ? owned_error.get() : error;
    outputs[1] = owned_log ? owned_log.get() : log;
    enabled = true;
}

void SferaErrorLogRuntime::clear() {
    outputs[0] = outputs[1] = nullptr;
    enabled = false;
    owned_log.reset();
    owned_error.reset();
}

void SferaFileManager::keepTail(const char* filename, std::size_t size) {
    const auto length = fileSize(filename);
    if (length < 0 || std::cmp_less_equal(length, size) || size > std::size_t{std::numeric_limits<std::ptrdiff_t>::max()}) return;
    std::vector<std::uint8_t> tail(size);
    ScopedFile file(*this, open(filename, _O_RDWR));
    if (file.get() < 0) return;
    if (seek(file.get(), -static_cast<std::int64_t>(size), SEEK_END) < 0 || read(file.get(), tail.data(), size) != static_cast<std::ptrdiff_t>(size)) return;
    if (seek(file.get(), 0, SEEK_SET) >= 0 && write(file.get(), tail.data(), size) == static_cast<std::ptrdiff_t>(size)) ::_chsize_s(file.get(), size);
}

const char* SferaClientApplication::commandLineArguments(const char* commandLine) {
    if (commandLine == nullptr) return "";
    bool quoted = false;
    auto* cursor = reinterpret_cast<const unsigned char*>(commandLine);
    while (*cursor != '\0' && (*cursor > ' ' || quoted)) {
        if (*cursor == '"') quoted = !quoted;
        if (::_ismbblead(*cursor) && cursor[1] != '\0') ++cursor;
        ++cursor;
    }
    while (*cursor != '\0' && *cursor <= ' ') ++cursor;
    return reinterpret_cast<const char*>(cursor);
}

void SferaClientApplication::initializeStorage() {
    if (SferaClientApplication::storage_initialized) return;
    unsigned int control = 0u;
    if (::_controlfp_s(&control, _PC_53, _MCW_PC) != 0) throw std::runtime_error("Cannot initialize floating-point precision");
    ::HeapSetInformation(nullptr, HeapEnableTerminationOnCorruption, nullptr, 0u);
    SferaClientApplication::storage_initialized = true;
    g_sfera_effect_manager.clearListeners();
    g_sfera_error_log_runtime.initialize();
    g_sfera_config_text_runtime.clear();
    g_sfera_mbc_runtime.inverse_coordinate_scale = 1.0f / 40.0f;
    g_sfera_camera = SphereRender::GameCamera{};
    g_sfera_effect_manager.render_slots.resize(10000u);

    WorldGuiControls::elements.resize(7000u);
    g_sfera_world_objects.object_handles.resize(500000u);
    g_sfera_world_objects.extended_object_handles.resize(30000u);
    GameInterface::windows.resize(100u);
    g_sfera_light_runtime.handles.resize(1000u);
    g_sfera_light_runtime.visible_handles.reserve(1000u);
    g_sfera_light_runtime.invalidateActiveLights();
    SphereRender::ModelPose::bone_transforms.resize(256u);
    SphereRender::ModelPose::attachment_transforms.fill({});
    SphereRender::SceneRenderer::object_order.reserve(10000u);
}

void SferaMbcRuntime::pushReference(SferaMbcValue::Type type, const SferaSliceReference32& reference, bool load) {
    const auto source = reference;
    auto& slot = g_sfera_mbc_runtime.values[value_stack_size++];
    slot.source = source;
    slot.type = type;
    if (!load || type == SferaMbcValue::Address) { slot.value = source; slot.width = sizeof(source); }
    else if (type == SferaMbcValue::Byte) { slot.value.base = readMemory<std::int8_t>(source.base); slot.type = SferaMbcValue::Integer; slot.width = sizeof(std::int8_t); }
    else if (type == SferaMbcValue::Integer || type == SferaMbcValue::Real) { slot.value.base = readMemory<std::uint32_t>(source.base); slot.width = sizeof(std::uint32_t); }
    else { slot.value = readMemory<SferaSliceReference32>(source.base); slot.width = sizeof(source); }
}

std::uint32_t SferaMbcProcessRecord::growMemory(std::uint32_t size) {
    constexpr std::uint32_t maximumRequest = 4000000;
    constexpr auto limit = SferaMbcRuntime::mappedAddressBegin;
    if (size > maximumRequest || memory.size() > limit - 4u) return UINT32_MAX;
    const auto aligned = (memory.size() + 3u) & ~std::size_t{3};
    if (size >= limit - aligned) return UINT32_MAX;
    memory.resize(aligned + size, 0);
    // Process mappings resolve the owner at access time, so existing addresses remain valid.
    auto& runtime = g_sfera_mbc_runtime;
    if (runtime.active_process == this) runtime.process_memory_base = memory.data();
    return static_cast<std::uint32_t>(aligned);
}

SferaMbcProcessRecord* SferaMbcRuntime::findProcess(std::uint32_t id) {
    if (id >= std::size(processes)) return nullptr;
    auto& process = processes[id];
    return process.process_id == id && process.chain_prev_index >= 0 ? &process : nullptr;
}

std::uint32_t SferaMbcRuntime::namedValue(const char* name, int index) {
    if (name == nullptr) return 0;
    const auto found = named_vectors.find(name);
    if (found == named_vectors.end()) return 0;
    const auto& values = found->second;
    if (index < 0) return static_cast<std::uint32_t>(values.size());
    const auto offset = static_cast<std::size_t>(index);
    return offset < values.size() ? values[offset] : 0;
}

void SferaMbcRuntime::setNamedValue(const char* name, std::uint32_t value, int index) {
    if (name == nullptr || index < 0) return;
    auto found = named_vectors.find(name);
    if (found == named_vectors.end()) {
        if (named_vectors.size() >= 1000u) return;
        found = named_vectors.try_emplace(name).first;
    }
    auto& values = found->second;
    const auto offset = static_cast<std::size_t>(index);
    const auto required = offset + 1u;
    if (required > values.max_size()) throw std::length_error("Named values exceed array capacity");
    if (required > values.size()) values.resize(required);
    values[offset] = value;
}

std::size_t SferaMbcValue::storageSize(Type valueType) {
    return valueType == Byte ? sizeof(std::int8_t) : valueType % Integer == 0 ? sizeof(std::uint32_t) : sizeof(SferaSliceReference32);
}

std::size_t SferaMbcValue::elementSize() const {
    return storageSize(static_cast<Type>(type - 1));
}

void SferaText::encodeUri(char* destination, const char* source, std::size_t capacity) {
    if (destination == nullptr || capacity == 0) return;
    constexpr char digits[] = "0123456789ABCDEF";
    std::size_t used = 0;
    while (used < capacity) {
        const unsigned char value = *source;
        if (value == 0) { destination[used++] = '\0'; break; }
        const bool ordinary = (value >= 'a' && value <= 'z') || (value >= 'A' && value <= 'Z') || (value >= '0' && value <= '9') || value == '-' || value == '_' || value == '.' || value == '~';
        if (ordinary) destination[used++] = value;
        else {
            if (capacity - used < 3) break;
            destination[used++] = '%';
            destination[used++] = digits[value / 16];
            destination[used++] = digits[value % 16];
        }
        ++source;
    }
    destination[std::min(used, capacity - 1)] = '\0';
}

std::shared_ptr<const std::vector<std::uint8_t>> SferaMbcRuntime::cacheBytecode(
    std::shared_ptr<const std::vector<std::uint8_t>> code, const SferaMbcModuleIds& modules, std::uint32_t memorySize) {
    return bytecode_cache.try_emplace(SferaMbcBytecodeKey{modules, memorySize}, std::move(code)).first->second;
}

std::shared_ptr<const std::vector<std::uint8_t>> SferaMbcRuntime::findBytecode(
    const SferaMbcModuleIds& modules, std::uint32_t memorySize) const {
    const auto found = bytecode_cache.find(SferaMbcBytecodeKey{modules, memorySize});
    return found == bytecode_cache.end() ? nullptr : found->second;
}

void SferaLogRuntime::writeFormatted(const char* format, std::va_list arguments) {
    char message[912]{};
    std::vsnprintf(message, sizeof(message), format, arguments);
    write(message);
}

void SferaNetworkRuntime::updateTcpStatistics() {
    connection_info = connection ? connection->statistics() : SferaNetworkStatistics{};
}

bool SferaText::matchesWildcard(const char* text, const char* pattern) {
    const char* star = nullptr;
    const char* candidate = nullptr;
    while (*text != '\0') {
        if (*pattern == '*') { star = ++pattern; candidate = text; }
        else if (*pattern == '?' || *pattern == *text) { ++pattern; ++text; }
        else if (star != nullptr) { pattern = star; text = ++candidate; }
        else return false;
    }
    while (*pattern == '*') ++pattern;
    return *pattern == '\0';
}

int SferaNetworkRuntime::tickDifference(std::uint32_t current, std::uint32_t previous) {
    constexpr int maximumDistance = 14400;
    constexpr std::uint32_t period = 32768;
    const auto difference = current - previous;
    const auto signedDifference = std::bit_cast<int>(difference);
    const auto magnitude = signedDifference < 0 ? std::uint32_t{0} - difference : difference;
    if (std::bit_cast<int>(magnitude) <= maximumDistance) return signedDifference;
    return std::bit_cast<int>(signedDifference < 0 ? difference + period : difference - period);
}

void SferaNetworkRuntime::encodePayload(std::uint8_t* data, int length) {
    constexpr std::array<std::uint8_t, 9> protocolKey{75, 13, 239, 96, 201, 154, 112, 14, 3};
    std::uint8_t feedback = 0;
    for (int index = 0; index < length; ++index) {
        const auto value = data[index];
        data[index] = value ^ protocolKey[index % protocolKey.size()] ^ feedback;
        feedback = 2u * feedback + static_cast<std::uint8_t>(index) * value;
    }
}

void SferaMbcRuntime::resetBytecodeCache() { bytecode_cache.clear(); }

bool SferaConfigTextRuntime::load(const char* path) {
    if (!path || std::strlen(path) >= filename_capacity) return false;
    const std::string nextPath(path);
    clear(nextPath);
    auto bytes = SferaFileManager::readBounded(nextPath.c_str(), text_capacity);
    if (!bytes) return false;
    try {
        if (SferaZStream32::hasEnvelope(*bytes)) {
            std::vector<std::uint8_t> decoded(text_capacity);
            std::uint32_t count = static_cast<std::uint32_t>(decoded.size() - 1);
            if (SferaZStream32::decompressEnvelope(decoded.data(), count, *bytes) != 0) { clear(); return false; }
            decoded.resize(count); bytes = std::move(decoded);
        }
        storage_ = bytes->empty() ? std::string{} : std::string(reinterpret_cast<const char*>(bytes->data()), bytes->size());
        return true;
    } catch (const std::exception&) { clear(); return false; }
}
bool SferaConfigTextRuntime::save(bool compressed) const {
    if (filename.empty()) return false;
    const auto input = text();
    if (!compressed) return SferaFileManager::writeFile(filename.c_str(), input.data(), input.size());
    try {
        std::vector<std::uint8_t> encoded(text_capacity);
        std::uint32_t count = static_cast<std::uint32_t>(encoded.size() - 1);
        if (SferaZStream32::compressEnvelope(encoded.data(), count,
            {reinterpret_cast<const std::uint8_t*>(input.data()), input.size()}) != 0) return false;
        return SferaFileManager::writeFile(filename.c_str(), encoded.data(), count);
    } catch (const std::bad_alloc&) { return false; }
}
std::string SferaConfigTextRuntime::encodeBinary(std::span<const std::uint8_t> input) {
    std::string result;
    result.reserve(input.size() * CHAR_BIT / 6 + 3);
    std::uint32_t pending = 0;
    std::uint32_t count = 0;
    for (const auto byte : input) {
        pending |= static_cast<std::uint32_t>(byte) << count;
        count += CHAR_BIT;
        while (count >= 6) {
            result.push_back(static_cast<char>('0' + (pending & 63u)));
            pending >>= 6u;
            count -= 6u;
        }
    }
    result.push_back('#');
    result.push_back(static_cast<char>('0' + count));
    if (count != 0) result.push_back(static_cast<char>('0' + pending));
    return result;
}
bool SferaConfigTextRuntime::writeValue(std::string_view key, std::string_view value, bool quoted) {
    std::string next(text());
    auto* borrowed = std::get_if<BorrowedText>(&storage_);
    const auto capacity = borrowed ? std::min(borrowed->capacity, text_capacity) : text_capacity;
    if (!SferaText::replaceConfigValue(next, key, value, quoted, capacity)) return false;
    if (borrowed) {
        const auto bytes = borrowedBytes(*borrowed);
        std::copy(next.begin(), next.end(), bytes.begin()); bytes[next.size()] = 0;
    } else std::get<std::string>(storage_).swap(next);
    return true;
}

void SferaMbcValue::storeAs(Type destinationType, void* destination) const {
    const auto sourceType = type;
    const auto integerValue = sourceType == Real ? truncate(real()) : integer();
    switch (destinationType) {
        case Byte: { const std::uint8_t number = integerValue; std::memcpy(destination, &number, sizeof(number)); break; }
        case Integer: std::memcpy(destination, &integerValue, sizeof(integerValue)); break;
        case Real: { const auto number = sourceType == Real ? real() : static_cast<float>(integer()); std::memcpy(destination, &number, sizeof(number)); break; }
        default: {
            const auto reference = sourceType == Byte || sourceType == Integer || sourceType == Real ? SferaSliceReference32{static_cast<std::uint32_t>(integerValue), 0, 0} : value;
            std::memcpy(destination, &reference, sizeof(reference));
            break;
        }
    }
}

void SferaMbcRuntime::bindParameters() {
    const auto declaration = readOperand<std::int8_t>();
    const int capacity = declaration < 0 ? -declaration : declaration;
    if (argument_count < 0 || (declaration >= 0 && argument_count != capacity) || argument_count > capacity) {
        std::snprintf(text_buffer, sizeof(text_buffer), "Wrong number of parameters (must be %d, present %d)", int(declaration), argument_count);
        reportError(text_buffer);
        return;
    }
    const auto supplied = std::min(capacity, argument_count);
    const auto& stack = g_sfera_mbc_runtime.values;
    if (argument_cursor > std::size(stack) || supplied > std::size(stack) - argument_cursor) { reportError("Parameter stack overflow"); return; }
    for (int index = 0; index < capacity; ++index) {
        const auto type = readOperand<SferaMbcValue::Type>();
        const auto offset = readOperand<std::uint32_t>();
        if (index < supplied) stack[argument_cursor + index].storeAs(type, memoryAt(offset));
        else { const SferaMbcValue zero{}; zero.storeAs(type, memoryAt(offset)); }
    }
}

SferaMbcFunctionRecord* SferaMbcProcessRecord::findFunction(std::string_view name) {
    if (functions.empty()) return nullptr;
    for (std::uint32_t index = 0; index < functions.size(); ++index) if (functions[index].program_index >= 0 && name == std::string_view(functions[index].name, std::find(std::begin(functions[index].name), std::end(functions[index].name), '\0') - std::begin(functions[index].name))) return &functions[index];
    return nullptr;
}

void SferaMbcRuntime::callFunction(bool mainProcess) {
    const auto required = mainProcess ? 1u : 2u;
    argument_count -= required;
    const auto fail = [this]() { active_tag = UINT32_MAX; pushInteger(UINT32_MAX); };
    if (argument_count < 0) { fail(); return; }
    const auto targetIndex = mainProcess ? 0u : static_cast<std::uint32_t>(nextInteger());
    auto* target = mainProcess ? &processes[0] : targetIndex == 0 ? nullptr : findProcess(targetIndex);
    if (target == nullptr || target->functions.empty()) { fail(); return; }
    if (argument_cursor >= argument_end) { reportError("Too few parameters"); fail(); return; }
    SferaMbcFunctionRecord* function = nullptr;
    if (g_sfera_mbc_runtime.values[argument_cursor].type == SferaMbcValue::BytePointer) {
        const auto name = nextSlice();
        const auto* text = textAt(name.base);
        function = target->findFunction(std::string_view(text, std::find(text, text + 31, '\0') - text));
    } else {
        const std::uint32_t tag = nextInteger();
        if (tag < SferaMbcModuleImage::functionSlotCount) {
            const auto index = target->function_map[tag];
            if (index != UINT16_MAX && index < target->functions.size()) function = &target->functions[index];
        }
    }
    if (function == nullptr || function->program_index < 0 || static_cast<std::uint32_t>(function->program_index) >= target->programs.size()) { fail(); return; }
    if (execution_context_depth >= std::size(execution_context_stack)) { reportError("Execution context stack overflow"); fail(); return; }
    execution_context_stack[execution_context_depth++] = {
        process_index, program_index, static_cast<std::uint32_t>(instruction_cursor - bytecode_base),
        processes[process_index].process_id, processes[process_index].lifetime};
    active_program_record = &program_table_base[program_index];
    active_program_record->instruction_offset = instruction_cursor - bytecode_base;
    auto& targetProgram = target->programs.data()[function->program_index];
    if (targetProgram.executing && !function->allow_reentry) { char message[256]; std::snprintf(message, sizeof(message), "Double \"func\" call, prob. stack corruption: %s (prc %d, tag %d), called from (prc %d, tag %d).\n", function->name, static_cast<int>(targetIndex), static_cast<int>(target->module_tag), static_cast<int>(process_index), static_cast<int>(active_process->module_tag)); WorldDiagnostics::warning(message); }
    bytecode_base = target->codeData();
    program_table_base = target->programs.data();
    process_memory_base = target->memory.data();
    instruction_cursor = bytecode_base + function->entry_offset;
    program_index = static_cast<std::uint32_t>(function->program_index);
    active_program_record = &targetProgram;
    targetProgram.callDepth = 0;
    targetProgram.executing = true;
    active_process = target;
    process_index = targetIndex;
    active_tag = 0;
}

void SferaMbcRuntime::returnFromFunction() {
    if (active_program_record->callDepth != 0) {
        const auto offset = std::bit_cast<std::int32_t>(active_program_record->return_offsets[--active_program_record->callDepth]);
        if (offset != -1) {
            if (offset < 0 || active_process == nullptr || static_cast<std::uint32_t>(offset) >= active_process->codeSize()) {
                reportError("Invalid function continuation"); return;
            }
            instruction_cursor = bytecode_base + offset;
            return;
        }
    }
    if (execution_context_depth == 0) { reportError("fo12(): return stack underflow"); return; }
    active_program_record->executing = false;
    while (execution_context_depth != 0) {
        const auto context = execution_context_stack[--execution_context_depth];
        if (context.process_index >= std::size(processes)) continue;
        auto& process = processes[context.process_index];
        if (process.chain_prev_index < 0 || process.process_id != context.process_id || process.lifetime != context.process_lifetime) continue;
        if (context.program_index < 0 || static_cast<std::size_t>(context.program_index) >= process.programs.size() || context.instruction_offset >= process.codeSize()) continue;
        process_index = context.process_index;
        program_index = context.program_index;
        active_process = &process;
        bytecode_base = process.codeData();
        instruction_cursor = bytecode_base + context.instruction_offset;
        process_memory_base = process.memory.data();
        program_table_base = process.programs.data();
        active_program_record = &process.programs[program_index];
        return;
    }
    reportError("Return to defunct process");
}

void SferaMbcRuntime::calculateDistance() {
    std::array<double, 3> delta{};
    if (argument_count == 2) {
        auto first = nextSlice();
        auto second = nextSlice();
        if (!first.contains(sizeof(SferaVec3F))) first.diagnoseRange(sizeof(SferaVec3F));
        if (!second.contains(sizeof(SferaVec3F))) second.diagnoseRange(sizeof(SferaVec3F));
        if (execution_failed) return;
        const auto a = readMemory<SferaVec3F>(first.base);
        const auto b = readMemory<SferaVec3F>(second.base);
        delta = {double(a.x) - b.x, double(a.y) - b.y, double(a.z) - b.z};
    } else {
        const auto dimensions = argument_count == 4 || argument_count == 5 ? 2u : 3u;
        std::array<float, 3> first{}, second{};
        for (std::uint32_t index = 0; index < dimensions; ++index) first[index] = nextReal();
        for (std::uint32_t index = 0; index < dimensions; ++index) second[index] = nextReal();
        for (std::uint32_t index = 0; index < dimensions; ++index) delta[index] = double(first[index]) - second[index];
    }
    const float square = delta[1] * delta[1] + delta[0] * delta[0] + delta[2] * delta[2];
    pushReal(argument_count == 2 || argument_count == 4 || argument_count == 6 ? std::sqrt(square) : square);
}

void SferaMbcRuntime::scanText() {
    const std::uint32_t source = nextInteger();
    const std::uint32_t format = nextInteger();
    const auto type = argument_cursor < argument_end ? g_sfera_mbc_runtime.values[argument_cursor].type : SferaMbcValue::Byte;
    using Number = std::variant<std::monostate, std::int8_t, std::uint8_t, std::int16_t, std::uint16_t, int, std::uint32_t, std::int64_t, std::uint64_t, float, double>;
    std::array<Number, 4> numbers{};
    std::array<void*, 4> destinations{};
    std::array<SferaSliceReference32, 4> references{};
    std::array<unsigned, 4> capacities{};
    const auto count = std::min(argument_count > 2 ? argument_count - 2 : 1u, 4u);
    for (std::uint32_t index = 0; index < count; ++index) {
        if (argument_cursor < argument_end) references[index] = g_sfera_mbc_runtime.values[argument_cursor].value;
        references[index].base = nextInteger();
    }
    if (execution_failed) return;
    if (argument_count < 3 || argument_count > 6 || (argument_count == 3 && type != SferaMbcValue::IntegerPointer && type != SferaMbcValue::RealPointer && type != SferaMbcValue::BytePointer)) { pushInteger(source); return; }
    const auto* text = textAt(source);
    const auto* pattern = textAt(format);
    std::string normalized;
    std::size_t output = 0;
    const auto number = [&]<class T>() {
        auto& reference = references[output];
        if (!reference.contains(sizeof(T))) { reference.diagnoseRange(sizeof(T)); execution_failed = true; return; }
        numbers[output] = readMemory<T>(reference.base);
        destinations[output] = &std::get<T>(numbers[output]);
    };
    for (const char* token = pattern; *token != '\0'; ++token) {
        if (*token != '%') { normalized += *token; continue; }
        const char* start = token++;
        if (*token == '%') { normalized += "%%"; continue; }
        const bool suppressed = *token == '*';
        if (suppressed) ++token;
        while (*token >= '0' && *token <= '9') ++token;
        normalized.append(start, token);
        const char* lengthStart = token;
        while (*token != '\0' && std::strchr("hljztLwI", *token) != nullptr) if (*token++ == 'I') while (*token >= '0' && *token <= '9') ++token;
        const std::string_view length(lengthStart, token);
        const char conversion = *token;
        if (conversion == '\0') { reportError("Incomplete scan format"); return; }
        if (!suppressed && output >= count) { reportError("Too few scan destinations"); return; }
        if (std::strchr("cCsS[", conversion) != nullptr) {
            const char* conversionStart = token;
            if (conversion == '[') {
                if (token[1] == '^') ++token;
                if (token[1] == ']') ++token;
                do { ++token; } while (*token != '\0' && *token != ']');
                if (*token == '\0') { reportError("Incomplete scan character set"); return; }
            }
            normalized.append(length);
            normalized.append(conversionStart, token + 1);
            if (!suppressed) {
                const auto& reference = references[output];
                std::size_t bytes = 0;
                if (reference.begin != 0 && reference.base >= reference.begin && reference.base <= reference.end) bytes = std::size_t(reference.end) - reference.base + 1;
                else if (reference.begin == 0 && active_process != nullptr && reference.base < active_process->memory.size()) bytes = active_process->memory.size() - reference.base;
                if (bytes == 0 || bytes > UINT_MAX) { reportError("Invalid scan destination range"); return; }
                destinations[output] = memoryAt(reference.base, bytes);
                const bool wide = length != "h" && (length == "l" || length == "w" || conversion == 'C' || conversion == 'S');
                capacities[output] = static_cast<unsigned>(bytes / (wide ? sizeof(wchar_t) : 1));
                if (capacities[output] == 0) { reportError("Invalid scan destination range"); return; }
            }
        } else if (std::strchr("diouxXnp", conversion) != nullptr) {
            // Script integers and addresses remain 32-bit even for native-size scanf modifiers.
            const bool signedValue = conversion == 'd' || conversion == 'i' || conversion == 'n';
            const bool wide = conversion != 'p' && (length == "ll" || length == "I64" || length == "j");
            const bool byte = conversion != 'p' && length == "hh";
            const bool half = conversion != 'p' && length == "h";
            if (wide) normalized += "ll";
            else if (byte) normalized += "hh";
            else if (half) normalized += 'h';
            normalized += conversion == 'p' ? 'x' : conversion;
            if (!suppressed) {
                if (signedValue) {
                    if (wide) number.template operator()<std::int64_t>();
                    else if (byte) number.template operator()<std::int8_t>();
                    else if (half) number.template operator()<std::int16_t>();
                    else number.template operator()<int>();
                } else {
                    if (wide) number.template operator()<std::uint64_t>();
                    else if (byte) number.template operator()<std::uint8_t>();
                    else if (half) number.template operator()<std::uint16_t>();
                    else number.template operator()<std::uint32_t>();
                }
            }
        } else if (std::strchr("aAeEfFgG", conversion) != nullptr) {
            const bool wide = length == "l" || length == "L";
            if (wide) normalized += 'l';
            normalized += conversion;
            if (!suppressed) { if (wide) number.template operator()<double>(); else number.template operator()<float>(); }
        } else { reportError("Unsupported scan conversion"); return; }
        if (execution_failed) return;
        if (!suppressed) ++output;
    }
    const auto scan = [&]<std::size_t Index>(auto&& self, auto... arguments) -> int {
        if constexpr (Index == 4) return ::sscanf_s(text, normalized.c_str(), arguments...);
        else if (capacities[Index] != 0) return self.template operator()<Index + 1>(self, arguments..., destinations[Index], capacities[Index]);
        else return self.template operator()<Index + 1>(self, arguments..., destinations[Index]);
    };
    const auto result = scan.template operator()<0>(scan);
    for (std::size_t index = 0; index < output; ++index) std::visit([&](const auto& value) { if constexpr (!std::is_same_v<std::remove_cvref_t<decltype(value)>, std::monostate>) writeMemory(references[index].base, value); }, numbers[index]);
    pushInteger(static_cast<std::uint32_t>(result));
}

char* SferaMbcRuntime::nextText(bool allowNull) {
    const auto slice = nextSlice();
    if (slice.base == 0) { if (!allowNull) reportError("poppointerup(): unexpected NULL-pointer fetched"); return nullptr; }
    return textAt(slice.base);
}

void SferaMbcRuntime::pushText(const char* text) {
    const auto offset = mapMemory(text, text != nullptr ? std::strlen(text) + 1 : 0);
    pushSlice({offset, text == nullptr ? 0u : offset, text == nullptr ? 0u : offset + static_cast<std::uint32_t>(std::strlen(text))}, SferaMbcValue::BytePointer);
}

void SferaMbcRuntime::copyText(const SferaSliceReference32& destination, const char* text) {
    const auto length = std::strlen(text) + 1;
    if (length > UINT32_MAX || !destination.contains(static_cast<std::uint32_t>(length))) { auto invalid = destination; invalid.diagnoseRange(static_cast<std::uint32_t>(std::min<std::size_t>(length, UINT32_MAX))); return; }
    std::copy_n(text, length, textAt(destination.base));
}

void SferaMbcRuntime::parseText() {
    const auto operation = nextInteger();
    if (operation < 0 || operation > 7) { reportError("ffparse(). Invalid parsing type"); return; }
    char* destination = operation < 2 ? nextText() : nullptr;
    const char* cursor = nextText();
    const char* limit = nextText(true);
    if (execution_failed) return;
    const char* result = reinterpret_cast<const char*>(process_memory_base);
    const auto digit = [](unsigned char value) { return value >= '0' && value <= '9'; };
    const auto letter = [](unsigned char value) { return (value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z') || value == '_'; };
    const auto space = [](unsigned char value) { return value == ' ' || value == '\t'; };
    if (cursor != limit) {
        if (operation < 2) {
            const bool negative = *cursor == '-';
            if (negative) ++cursor;
            if (cursor != limit && digit(*cursor)) {
                if (operation == 0) {
                    std::uint32_t value = 0;
                    do { value = value * 10u + static_cast<unsigned char>(*cursor++) - '0'; } while (cursor != limit && digit(*cursor));
                    if (negative) value = 0u - value;
                    std::memcpy(destination, &value, sizeof(value));
                } else {
                    float value = 0.0f;
                    do { value = double(value) * 10.0 + (*cursor++ - '0'); } while (cursor != limit && digit(*cursor));
                    if (cursor != limit && *cursor == '.') {
                        ++cursor;
                        float scale = 0.1f;
                        while (cursor != limit && digit(*cursor)) { value = double(*cursor++ - '0') * scale + value; scale = double(scale) / 10.0; }
                    }
                    if (negative) value = -value;
                    std::memcpy(destination, &value, sizeof(value));
                }
                result = cursor;
            }
        } else if (operation == 2 && static_cast<unsigned char>(*cursor) > ' ') {
            do { ++cursor; } while (cursor != limit && static_cast<unsigned char>(*cursor) > ' ');
            result = cursor;
        } else if (operation == 3 && *cursor == '"') {
            ++cursor;
            while (cursor != limit && *cursor != '\0' && *cursor != '\r' && *cursor != '\n' && *cursor != '"') ++cursor;
            if (cursor != limit && *cursor == '"') result = cursor + 1;
        } else if (operation == 4 && letter(*cursor)) {
            do { ++cursor; } while (cursor != limit && (letter(*cursor) || digit(*cursor)));
            result = cursor;
        } else if (operation == 5 && space(*cursor)) {
            do { ++cursor; } while (cursor != limit && space(*cursor));
            result = cursor;
        } else if (operation >= 6) {
            while (cursor != limit && (operation == 6 ? space(*cursor) : *cursor != '\0' && *cursor != '\r' && *cursor != '\n')) ++cursor;
            if (cursor != limit && *cursor == '\r') { ++cursor; if (cursor != limit && *cursor == '\n') result = cursor + 1; }
        }
    }
    pushText(result);
}

void SferaMbcRuntime::chatUtility() {
    const auto operation = nextInteger();
    if (operation < 0 || operation > 4) { reportError("ffchat_utility(). Invalid Chat utility function type"); return; }
    std::string input{}, output{}, plain{};
    const auto* source = nextText();
    if (execution_failed) return;
    input.assign(source);
    if (operation == 0) {
        std::string target{}, caption{};
        target.assign(nextText());
        caption.assign(nextText());
        const auto destination = nextSlice();
        if (execution_failed) return;
        output = SphereUI::HyperTextParser::buildLink(input, target, caption);
        copyText(destination, output.data());
    } else if (operation == 1) {
        const auto destination = nextSlice();
        if (execution_failed) return;
        output = SphereUI::HyperTextParser::plainText(input);
        copyText(destination, output.data());
    } else {
        std::uint32_t first = 0, last = 0;
        if (operation == 4) { first = nextInteger(); last = nextInteger(); }
        const auto plainDestination = nextSlice();
        const auto markupDestination = nextSlice();
        if (execution_failed) return;
        bool success;
        if (operation == 2) success = SphereUI::HyperTextParser::extractPlayerPrefix(input, &output, &plain);
        else if (operation == 3) success = SphereUI::HyperTextParser::removePlayerPrefix(input, &output, &plain);
        else success = SphereUI::HyperTextParser::eraseRange(input, first, last, &output, &plain);
        if (!success) { pushInteger(UINT32_MAX); return; }
        if (plainDestination.base != 0) copyText(plainDestination, plain.data());
        if (markupDestination.base != 0) copyText(markupDestination, output.data());
    }
    pushInteger(0);
}


namespace {
struct MbcScrollParameters32 {
    std::uint32_t size;
    std::uint32_t mask;
    std::int32_t minimum;
    std::int32_t maximum;
    std::int32_t page_step;
    std::int32_t current;
    std::int32_t step;
};
static_assert(sizeof(MbcScrollParameters32) == 28u);
static_assert(sizeof(SphereUI::ScrollParameters) == sizeof(MbcScrollParameters32));

struct MbcUiRect32 {
    std::int32_t left;
    std::int32_t top;
    std::int32_t right;
    std::int32_t bottom;
};
struct MbcImageDescriptionParameters32 {
    char texture_name[64];
    std::int32_t width;
    std::int32_t height;
    MbcUiRect32 rectangle;
    std::uint32_t flags;
};
struct MbcImageDescription32 {
    char name[64];
    MbcImageDescriptionParameters32 image;
};
static_assert(sizeof(MbcImageDescription32) == 156u);
static_assert(sizeof(SphereUI::ImageDescription) == sizeof(MbcImageDescription32));

class MbcUiMessageCodec {
    SferaMbcRuntime& runtime_;
    std::uint32_t flags_;

    static std::string_view cString(const char* text) {
        return text == nullptr ? std::string_view{} : std::string_view{text};
    }

    std::string_view text(std::uint32_t address) const {
        return address == 0u ? std::string_view{} : cString(runtime_.textAt(address));
    }

    std::span<std::uint8_t> bytes(std::uint32_t address, std::size_t size) const {
        if (address == 0u) return {};
        return {runtime_.memoryAt(address, size), size};
    }

    std::vector<std::uint32_t> words(std::uint32_t address, std::size_t count) const {
        if (count == 0u) return {};
        if (address == 0u) return {};
        if (count > std::numeric_limits<std::size_t>::max() / sizeof(std::uint32_t)) throw std::length_error("UI word array is too large");
        const auto source = bytes(address, count * sizeof(std::uint32_t));
        std::vector<std::uint32_t> result(count);
        std::memcpy(result.data(), source.data(), source.size());
        return result;
    }

    template<class T> T read(std::uint32_t address) const {
        T result{};
        if (address == 0u) return result;
        std::memcpy(&result, runtime_.memoryAt(address, sizeof(result)), sizeof(result));
        return result;
    }

    template<class T> void write(std::uint32_t address, const T& value) const {
        if (address != 0u) runtime_.writeMemory(address, value);
    }

    void writeBool(std::uint32_t address, bool value) const {
        write(address, static_cast<std::uint8_t>(value ? 1u : 0u));
    }

    void writeSize(std::uint32_t address, std::size_t value) const {
        if (!std::in_range<std::uint32_t>(value)) {
            runtime_.reportError("UI result exceeds an MBC word");
            return;
        }
        write(address, static_cast<std::uint32_t>(value));
    }

    void writeText(std::uint32_t address, std::string_view value, std::size_t explicit_capacity = std::numeric_limits<std::size_t>::max(), std::size_t content_limit = std::numeric_limits<std::size_t>::max()) const {
        if (address == 0u || explicit_capacity == 0u) return;
        auto destination = runtime_.memoryRange(address);
        const auto capacity = std::min(destination.size(), explicit_capacity);
        if (capacity == 0u) return;
        const auto count = std::min({value.size(), content_limit, capacity - 1u});
        if (count != 0u) std::memcpy(destination.data(), value.data(), count);
        destination[count] = 0u;
    }

    SphereUI::ToolTipCtrl* tooltip(SphereUI::Window* window) const {
        if (window == nullptr) return nullptr;
        if (!window->tooltip) {
            window->tooltip = std::make_unique<SphereUI::ToolTipCtrl>();
            window->tooltip->setParent(window);
        }
        return window->tooltip.get();
    }

    SphereUI::ImageDescription imageDescription(std::uint32_t address) const {
        const auto wire = read<MbcImageDescription32>(address);
        SphereUI::ImageDescription result{};
        std::memcpy(result.name, wire.name, sizeof(result.name));
        std::memcpy(result.image.texture_name, wire.image.texture_name, sizeof(result.image.texture_name));
        result.name[sizeof(result.name) - 1u] = '\0';
        result.image.texture_name[sizeof(result.image.texture_name) - 1u] = '\0';
        result.image.width = wire.image.width;
        result.image.height = wire.image.height;
        result.image.rectangle = {wire.image.rectangle.left, wire.image.rectangle.top, wire.image.rectangle.right, wire.image.rectangle.bottom};
        result.image.flags = wire.image.flags;
        return result;
    }

public:
    MbcUiMessageCodec(SferaMbcRuntime& runtime, std::uint32_t flags) : runtime_(runtime), flags_(flags) {}

    std::uint32_t dispatch(SphereUI::Window* window, SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) const {
        using SphereUI::UiMessage;

        if (message == UiMessage::showHelpPage) {
            g_sfera_interface.showHelpPage(first == 0u ? nullptr : runtime_.textAt(first));
            return 1u;
        }
        if (message == UiMessage::beginModal) {
            if (window != nullptr) window->beginModal(runtime_.nativeResource<SphereUI::Window*>(first));
            return 1u;
        }

        switch (message) {
            case UiMessage::getInputEnabled:
                if (window != nullptr) writeBool(first, window->input_enabled);
                return 1u;
            case UiMessage::getHidden:
                if (window != nullptr) writeBool(first, window->hidden);
                return 1u;
            case UiMessage::getDisabled:
                if (window != nullptr) writeBool(first, window->disabled);
                return 1u;
            case UiMessage::getChildUnderCursor:
                if (window != nullptr) {
                    const auto position = CCursorManager::instance().position();
                    write(first, static_cast<std::uint32_t>(window->childControlAt(position.x, position.y)));
                }
                return 1u;
            case UiMessage::getModal:
                if (window != nullptr) writeBool(first, window->modal_owner != nullptr);
                return 1u;
            case UiMessage::getChecked:
                if (const auto* control = dynamic_cast<const SphereUI::CheckBox*>(window)) writeBool(first, control->checked);
                return 1u;
            case UiMessage::setEditText:
                if (auto* control = dynamic_cast<SphereUI::EditCtrl*>(window)) control->setEditText(text(first));
                return 1u;
            case UiMessage::getEditText:
                if (const auto* control = dynamic_cast<const SphereUI::EditCtrl*>(window)) writeText(first, control->text, std::numeric_limits<std::size_t>::max(), 250u);
                return 1u;
            case UiMessage::appendListText:
                if (auto* control = dynamic_cast<SphereUI::ListCtrl*>(window); control != nullptr && first != 0u) control->appendMessageText(text(first), second);
                return 1u;
            case UiMessage::setListText:
                if (auto* control = dynamic_cast<SphereUI::ListCtrl*>(window)) control->setRowText(first, second == 0u ? std::string_view{" "} : text(second));
                return 1u;
            case UiMessage::getListSelection:
                if (const auto* control = dynamic_cast<const SphereUI::ListCtrl*>(window)) write(first, static_cast<std::int32_t>(control->selected_index));
                return 1u;
            case UiMessage::getListText:
                if (const auto* control = dynamic_cast<const SphereUI::ListCtrl*>(window); control != nullptr && second < control->rows.size()) writeText(first, control->rowText(second));
                return 1u;
            case UiMessage::getListSize:
                if (const auto* control = dynamic_cast<const SphereUI::ListCtrl*>(window)) writeSize(first, control->rows.size());
                return 1u;
            case UiMessage::getListColor:
                if (const auto* control = dynamic_cast<const SphereUI::ListCtrl*>(window); control != nullptr && second < control->rows.size()) write(first, control->rows.at(control->physicalIndex(second)).color);
                return 1u;
            case UiMessage::getListScroll:
                if (const auto* control = dynamic_cast<const SphereUI::ListCtrl*>(window)) write(first, static_cast<std::int32_t>(control->vertical_offset));
                return 1u;
            case UiMessage::appendFilteredListText:
                if (auto* control = dynamic_cast<SphereUI::FilterListCtrl*>(window); control != nullptr && first != 0u) control->appendFilteredText(text(first), second);
                return 1u;
            case UiMessage::getSelectedFont:
                if (const auto* control = dynamic_cast<const SphereUI::FontPicker*>(window)) write(first, static_cast<std::int32_t>(control->getFont()));
                return 1u;
            case UiMessage::setImageName:
                if (auto* control = dynamic_cast<SphereUI::ImageCtrl*>(window)) {
                    if (first == 0u) control->setImage(nullptr);
                    else control->setImageName(text(first));
                }
                return 1u;
            case UiMessage::setImageRotation:
                if (auto* control = dynamic_cast<SphereUI::ImageCtrl*>(window)) control->setRotationDegrees(std::bit_cast<float>(first));
                return 1u;
            case UiMessage::setImageDescription:
                if (auto* control = dynamic_cast<SphereUI::ImageCtrl*>(window)) {
                    if (first == 0u) control->setImage(nullptr);
                    else { const auto description = imageDescription(first); control->setImage(&description); }
                }
                return 1u;
            case UiMessage::getListItemSelection:
                if (const auto* control = dynamic_cast<const SphereUI::ListItemCtrl*>(window)) write(first, static_cast<std::int32_t>(control->selected_index));
                return 1u;
            case UiMessage::getListItemCount:
                if (const auto* control = dynamic_cast<const SphereUI::ListItemCtrl*>(window)) writeSize(first, control->items.size());
                return 1u;
            case UiMessage::setTooltipLine:
                if (auto* control = tooltip(window)) control->setLine(first, second == 0u ? nullptr : runtime_.textAt(second));
                return 1u;
            case UiMessage::getTooltipLine:
                if (const auto* control = tooltip(window); control != nullptr && second < control->lines.size()) writeText(first, control->lines.at(second));
                return 1u;
            case UiMessage::appendTooltipLine:
                if (auto* control = tooltip(window)) control->appendLine(first == 0u ? nullptr : runtime_.textAt(first));
                return 1u;
            case UiMessage::getProgressRange:
                if (const auto* control = dynamic_cast<const SphereUI::ProgressBar*>(window)) { write(first, static_cast<std::int32_t>(control->minimum)); write(second, static_cast<std::int32_t>(control->maximum)); }
                return 1u;
            case UiMessage::getProgressValue:
                if (const auto* control = dynamic_cast<const SphereUI::ProgressBar*>(window)) write(first, static_cast<std::int32_t>(control->current));
                return 1u;
            case UiMessage::getScrollRange:
                if (const auto* control = dynamic_cast<const SphereUI::ScrollBar*>(window)) { write(first, static_cast<std::int32_t>(control->minimum)); write(second, static_cast<std::int32_t>(control->maximum)); }
                return 1u;
            case UiMessage::setScrollParameters:
                if (auto* control = dynamic_cast<SphereUI::ScrollBar*>(window); control != nullptr && first != 0u) {
                    const auto wire = read<MbcScrollParameters32>(first);
                    control->setParameters({wire.size, wire.mask, wire.minimum, wire.maximum, wire.page_step, wire.current, wire.step});
                }
                return 1u;
            case UiMessage::getScrollParameters:
                if (const auto* control = dynamic_cast<const SphereUI::ScrollBar*>(window); control != nullptr && first != 0u) {
                    auto wire = read<MbcScrollParameters32>(first);
                    SphereUI::ScrollParameters parameters{wire.size, wire.mask, wire.minimum, wire.maximum, wire.page_step, wire.current, wire.step};
                    control->getParameters(parameters);
                    wire.minimum = parameters.minimum;
                    wire.maximum = parameters.maximum;
                    wire.page_step = parameters.page_step;
                    wire.current = parameters.current;
                    wire.step = parameters.step;
                    write(first, wire);
                }
                return 1u;
            case UiMessage::getScrollValue:
                if (const auto* control = dynamic_cast<const SphereUI::ScrollBar*>(window)) write(first, static_cast<std::int32_t>(control->current));
                return 1u;
            case UiMessage::getSpinRange:
                if (const auto* control = dynamic_cast<const SphereUI::SpinButton*>(window)) { write(first, static_cast<std::int32_t>(control->minimum)); write(second, static_cast<std::int32_t>(control->maximum)); }
                return 1u;
            case UiMessage::getSpinStep:
                if (const auto* control = dynamic_cast<const SphereUI::SpinButton*>(window)) write(first, static_cast<std::int32_t>(control->step));
                return 1u;
            case UiMessage::getSpinValue:
                if (const auto* control = dynamic_cast<const SphereUI::SpinButton*>(window)) write(first, static_cast<std::int32_t>(control->current));
                return 1u;
            case UiMessage::appendMenuItem:
                if (auto* control = dynamic_cast<SphereUI::CMenuListControl*>(window)) control->addItem(first == 0u ? nullptr : runtime_.textAt(first), second != 0u);
                return 1u;
            case UiMessage::setMenuItemText:
                if (auto* control = dynamic_cast<SphereUI::CMenuListControl*>(window); control != nullptr && first < control->items.size()) control->items.at(first).text.assign(second == 0u ? "" : runtime_.textAt(second));
                return 1u;
            case UiMessage::setSlotItem:
                if (auto* control = dynamic_cast<SphereUI::SlotCtrl*>(window)) control->setItem(first == 0u ? nullptr : runtime_.textAt(first));
                return 1u;
            case UiMessage::setSlotDescription:
                if (auto* control = dynamic_cast<SphereUI::SlotCtrl*>(window)) control->description.assign(first == 0u ? "" : runtime_.textAt(first));
                return 1u;
            case UiMessage::setSlotTopLeftOverlay:
            case UiMessage::setSlotBottomRightOverlay:
            case UiMessage::setSlotBottomLeftOverlay:
                if (auto* control = dynamic_cast<SphereUI::SlotCtrl*>(window)) {
                    auto& target = message == UiMessage::setSlotTopLeftOverlay ? control->top_left_overlay : message == UiMessage::setSlotBottomRightOverlay ? control->bottom_right_overlay : control->bottom_left_overlay;
                    control->setOverlay(target, first == 0u ? nullptr : runtime_.textAt(first));
                }
                return 1u;
            case UiMessage::setRichEditContent:
                if (auto* control = dynamic_cast<SphereUI::RichEditCtrl*>(window); control != nullptr && first != 0u) control->setContent(runtime_.textAt(first));
                return 1u;
            case UiMessage::getRichEditContent:
                if (const auto* control = dynamic_cast<const SphereUI::RichEditCtrl*>(window); control != nullptr && first != 0u && second != 0u) {
                    auto destination = runtime_.memoryRange(first);
                    const auto capacity = std::min<std::size_t>(destination.size(), second);
                    control->copyContent(std::span<char>(reinterpret_cast<char*>(destination.data()), capacity));
                }
                return 1u;
            case UiMessage::loadHyperTextPage:
                if (auto* control = dynamic_cast<SphereUI::HyperTextCtrl*>(window)) control->queuePage(text(first), second != 0u);
                return 1u;
            case UiMessage::loadHyperTextBuffer:
                if (auto* control = dynamic_cast<SphereUI::HyperTextCtrl*>(window); control != nullptr && first != 0u && second != 0u) {
                    const auto source = bytes(first, second);
                    control->queueBuffer(std::string_view(reinterpret_cast<const char*>(source.data()), source.size()));
                }
                return 1u;
            case UiMessage::appendChatMessage:
                if (auto* control = dynamic_cast<SphereUI::HyperTextChatListControl*>(window); control != nullptr && first != 0u && second != 0u) {
                    const auto parameters = words(second, 2u);
                    control->addMessage(runtime_.textAt(first), parameters[0], parameters[1]);
                }
                return 1u;
            case UiMessage::setChatChannels:
                if (auto* control = dynamic_cast<SphereUI::HyperTextChatListControl*>(window)) {
                    if (first == 0u) control->setChannels(std::span<const std::uint32_t>{});
                    else if (second != 0u) { const auto values = words(second, first); control->setChannels(std::span<const std::uint32_t>(values)); }
                }
                return 1u;
            case UiMessage::getChatPlainText:
            case UiMessage::getChatHyperText:
                if (const auto* control = dynamic_cast<const SphereUI::HyperTextChatListControl*>(window)) writeText(second, control->messageText(first, message == UiMessage::getChatPlainText));
                return 1u;
            case UiMessage::getSelectedChatLink:
                if (const auto* control = dynamic_cast<const SphereUI::HyperTextChatListControl*>(window)) { writeText(first, control->selected_link_text); writeText(second, control->selected_link_value); }
                return 1u;
            case UiMessage::getSelectedChatHyperText:
                if (const auto* control = dynamic_cast<const SphereUI::HyperTextChatListControl*>(window)) writeText(first, control->selected_hyper_text);
                return 1u;
            case UiMessage::getSelectedChatPlainText:
                if (const auto* control = dynamic_cast<const SphereUI::HyperTextChatListControl*>(window)) writeText(first, control->selected_plain_text);
                return 1u;
            case UiMessage::setHyperEditContent:
                if (auto* control = dynamic_cast<SphereUI::HyperTextEditControl*>(window); control != nullptr && first != 0u) control->setContent(runtime_.textAt(first), second);
                return 1u;
            case UiMessage::getHyperEditPlainText:
                if (const auto* control = dynamic_cast<const SphereUI::HyperTextEditControl*>(window)) writeText(first, control->visible_text);
                return 1u;
            case UiMessage::getHyperEditHyperText:
                if (const auto* control = dynamic_cast<const SphereUI::HyperTextEditControl*>(window)) writeText(first, control->hyper_text);
                return 1u;
            case UiMessage::getHyperEditLengths:
                if (const auto* control = dynamic_cast<const SphereUI::HyperTextEditControl*>(window)) { writeSize(first, control->visible_text.size()); writeSize(second, control->hyper_text.size()); }
                return 1u;
            default:
                break;
        }

        if ((flags_ & 3u) != 0u) {
            runtime_.reportError("Unsupported pointer-bearing UI message");
            return 0u;
        }
        return g_sfera_interface.sendMessage(window, message, first, second);
    }
};
}

void SferaMbcRuntime::windowCommand() {
    const auto operation = static_cast<WindowOperation>(nextInteger());
    std::array<std::int32_t, 6> arguments{};
    const auto read = [this, &arguments](std::size_t count) { for (std::size_t index = 0; index < count; ++index) arguments[index] = nextInteger(); return !execution_failed; };
    const auto inputText = [this](std::int32_t offset) { return textAt(static_cast<std::uint32_t>(offset)); };
    const auto warnNull = [operation](std::int32_t offset, std::uint32_t argument) { if (offset == 0) { char message[128]; std::snprintf(message, sizeof(message), "NULL-pointer dereferencing: window, command %u, argument %u\n", static_cast<std::uint32_t>(operation), argument); WorldDiagnostics::warning(message); } };
    switch (operation) {
        case WindowOperation::Create: {
            if (!read(6)) return;
            const auto handle = GameInterface::createWindow(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5]);
            pushInteger(handle);
            if (static_cast<int>(handle) < 0) reportError("Error creating window");
            else {
                try { active_process->registerResource(handle, ResourceKind::gameWindow); }
                catch (...) { GameInterface::destroyWindow(handle); throw; }
            }
            break;
        }
        case WindowOperation::Destroy: case WindowOperation::Close: {
            if (!read(1)) return;
            const std::uint32_t handle = arguments[0];
            auto resource = ResourceKind::gameWindow;
            if (operation == WindowOperation::Destroy) GameInterface::destroyWindow(handle);
            else { resource = ResourceKind::interfaceWindow; g_sfera_interface.closeWindow(nativeResource<SphereUI::Window*>(handle), true); }
            active_process->unregisterResource(handle, resource);
            break;
        }
        case WindowOperation::DisplayWidth: pushInteger(g_sfera_graphics_runtime.display_width); break;
        case WindowOperation::DisplayHeight: pushInteger(g_sfera_graphics_runtime.display_height); break;
        case WindowOperation::TextHeight: case WindowOperation::FontHeight: case WindowOperation::LineOffset:
            if (!read(operation == WindowOperation::FontHeight ? 2 : 3)) return;
            if (operation == WindowOperation::TextHeight) pushInteger(GameInterface::textHeight(arguments[0], arguments[1], arguments[2]));
            else if (operation == WindowOperation::FontHeight) pushInteger(GameInterface::fontHeight(arguments[0], arguments[1]));
            else pushInteger(GameInterface::lineOffset(arguments[0], arguments[1], arguments[2]));
            break;
        case WindowOperation::TakeInput: {
            if (!read(3)) return;
            warnNull(arguments[1], 1); warnNull(arguments[2], 2);
            std::uint32_t control = UINT32_MAX, message = 0;
            if (auto* window = GameInterface::window(arguments[0], "GetWindowPointer")) window->takeInput(control, message);
            writeMemory(arguments[1], control); writeMemory(arguments[2], message <= 2 ? message : 0u);
            break;
        }
        case WindowOperation::HitTest: {
            if (!read(2)) return;
            warnNull(arguments[0], 1); warnNull(arguments[1], 2);
            const auto hit = GameInterface::hitTest(CCursorManager::instance().position());
            writeMemory(arguments[0], hit.window); writeMemory(arguments[1], hit.control);
            break;
        }
        case WindowOperation::Visible: case WindowOperation::Scrollable:
            if (!read(2)) return;
            if (auto* window = GameInterface::window(arguments[0], "GetWindowPointer")) { if (operation == WindowOperation::Visible) window->visible = arguments[1] == 1; else window->scrollable = arguments[1] == 1; }
            break;
        case WindowOperation::Bounds:
            if (!read(5)) return;
            if (auto* window = GameInterface::window(arguments[0], "GetWindowPointer")) { window->left = window->contentLeft + arguments[1]; window->right = window->contentRight + arguments[3]; window->top = window->contentTop + arguments[2]; window->bottom = window->contentBottom + arguments[4]; }
            break;
        case WindowOperation::TextSize:
            if (!read(2)) return;
            warnNull(arguments[0], 1); warnNull(arguments[1], 2);
            writeMemory(arguments[0], WorldGuiControls::text_width); writeMemory(arguments[1], WorldGuiControls::text_height);
            break;
        case WindowOperation::GlyphWidth:
            if (!read(2)) return;
            pushInteger(GameInterface::glyphWidth(arguments[0] < 0 ? arguments[0] + 256 : arguments[0], arguments[1]));
            break;
        case WindowOperation::CursorPosition: {
            if (!read(3)) return;
            warnNull(arguments[1], 1); warnNull(arguments[2], 2);
            const auto* window = GameInterface::window(arguments[0]);
            const auto point = window ? window->contentPosition(CCursorManager::instance().position()) : SferaCursorPosition{-1, -1};
            writeMemory(arguments[1], point.x); writeMemory(arguments[2], point.y);
            break;
        }
        case WindowOperation::SystemCursorVisible: {
            auto* cursor = CCursorManager::instance().activeCursor();
            if (argument_count > 1) { if (!read(1)) return; cursor->setSystemCursorVisible(arguments[0] != 0); g_sfera_interface.world_interaction_enabled = arguments[0]; }
            pushInteger(cursor->isSystemCursorVisible());
            break;
        }
        case WindowOperation::SystemCursorKind:
            if (!read(1)) return;
            CCursorManager::instance().activeCursor()->setCursorKind(arguments[0]);
            break;
        case WindowOperation::CursorKind:
            if (!read(argument_count > 2 ? 3 : 1)) return;
            g_sfera_interface.setCursorKind(arguments[0], argument_count > 2 ? arguments[1] : 8, argument_count > 2 ? arguments[2] : -8);
            break;
        case WindowOperation::CursorImage: {
            const bool positioned = argument_count > 3;
            const bool imageMode = argument_count == 3 || argument_count == 5;
            if (!read(1 + (positioned ? 2 : 0) + (imageMode ? 1 : 0))) return;
            const auto mode = imageMode ? arguments[positioned ? 3 : 1] : -1;
            if (arguments[0] != 0 && mode >= 0) {
                if (auto* cursor = g_sfera_interface.cursor.get()) { cursor->setImage(2, inputText(arguments[0]), 8, 32); cursor->setImageSize(2, 16, 16); }
                break;
            }
            g_sfera_interface.setCursorImage(arguments[0] != 0 ? inputText(arguments[0]) : nullptr, arguments[0] != 0 ? positioned ? arguments[1] : 8 : 0, arguments[0] != 0 ? positioned ? arguments[2] : 16 : 0);
            if (auto* cursor = g_sfera_interface.cursor.get()) cursor->setImage(2, nullptr, 0, 0);
            break;
        }
        case WindowOperation::CursorText:
            if (!read(argument_count > 3 ? 4 : 2)) return;
            if (auto* cursor = g_sfera_interface.cursor.get()) cursor->setText(arguments[0], inputText(arguments[1]), argument_count > 3 ? arguments[2] : arguments[0] == 0 ? 6 : arguments[0] == 1 ? 16 : 0, argument_count > 3 ? arguments[3] : arguments[0] == 0 ? 40 : arguments[0] == 1 ? 6 : 0, 1, UINT32_MAX);
            break;
        case WindowOperation::Open: {
            if (!g_sfera_interface.initialized) { pushInteger(0); return; }
            if (!read(4)) return;
            auto* window = g_sfera_interface.openWindow(inputText(arguments[0]), arguments[1], arguments[2], arguments[3]);
            const auto handle = nativeHandle(window);
            pushInteger(handle);
            if (window) active_process->registerResource(handle, ResourceKind::interfaceWindow);
            break;
        }
        case WindowOperation::PollEvent: {
            const auto count = argument_count == 6 ? 5u : argument_count >= 5 ? 4u : 3u;
            if (!read(count)) return;
            for (std::uint32_t index = 1; index < count; ++index) warnNull(arguments[index], index);
            SphereUI::WindowEvent event{};
            auto* window = nativeResource<SphereUI::Window*>(static_cast<std::uint32_t>(arguments[0]));
            if (!window || !window->pollEvent(event)) { pushInteger(0); return; }
            writeMemory(arguments[1], event.control_id);
            writeMemory(arguments[2], event.message);
            if (argument_count == 5) {
                if (event.message == SphereUI::UiMessage::listItemEvent) {
                    writeMemory(arguments[1], HIWORD(event.second));
                    writeMemory(arguments[2], event.first);
                    writeMemory(arguments[3], LOWORD(event.second));
                } else writeMemory(arguments[3], UINT32_MAX);
            } else if (argument_count == 6) {
                writeMemory(arguments[3], event.first);
                writeMemory(arguments[4], event.second);
            }
            pushInteger(1);
            break;
        }
        case WindowOperation::SetText:
            if (!read(2)) return;
            if (auto* window = nativeResource<SphereUI::Window*>(static_cast<std::uint32_t>(arguments[0]))) window->setText(inputText(arguments[1]));
            pushInteger(0);
            break;
        case WindowOperation::ControlAt: case WindowOperation::ItemAt: {
            if (!read(2)) return;
            auto* window = nativeResource<SphereUI::Window*>(static_cast<std::uint32_t>(arguments[0]));
            SphereUI::Window* result = nullptr;
            if (window) { if (operation == WindowOperation::ControlAt) result = window->controlAt(arguments[1]); else if (window->control_kind == SphereUI::UiControlKind::listItem) result = static_cast<SphereUI::ListItemCtrl*>(window)->itemAt(arguments[1]); }
            pushInteger(nativeHandle(result));
            break;
        }
        case WindowOperation::SendMessage: {
            if (!read(5)) return;
            MbcUiMessageCodec codec(*this, static_cast<std::uint32_t>(arguments[4]));
            codec.dispatch(
                nativeResource<SphereUI::Window*>(static_cast<std::uint32_t>(arguments[0])),
                static_cast<SphereUI::UiMessage>(arguments[1]),
                static_cast<std::uint32_t>(arguments[2]),
                static_cast<std::uint32_t>(arguments[3]));
            pushInteger(0);
            break;
        }
        case WindowOperation::GetText: {
            if (!read(3)) return;
            warnNull(arguments[1], 1);
            const auto requested_capacity = static_cast<std::size_t>(std::max(arguments[2], 1));
            const auto content_capacity = requested_capacity - 1u;
            if (arguments[1] != 0) {
                auto destination = memoryRange(static_cast<std::uint32_t>(arguments[1]));
                const auto* window = nativeResource<SphereUI::Window*>(static_cast<std::uint32_t>(arguments[0]));
                if (window != nullptr && content_capacity != 0u && !destination.empty()) {
                    const auto capacity = std::min(destination.size(), requested_capacity);
                    const std::string_view value{window->text};
                    const auto length = std::min(value.size(), capacity - 1u);
                    if (length != 0u) std::memcpy(destination.data(), value.data(), length);
                    destination[length] = 0u;
                }
            }
            pushInteger(0);
            break;
        }
        case WindowOperation::SystemEvent: {
            if (!read(1)) return;
            warnNull(arguments[0], 1);
            SphereUI::WindowEvent event{};
            pushInteger(g_sfera_interface.pollEvent(event));
            writeMemory(arguments[0], event.message);
            break;
        }
        case WindowOperation::WindowUnderCursor: pushInteger(nativeHandle(g_sfera_interface.windowUnderCursor())); break;
        case WindowOperation::SavedPositionsSize: { const auto size = g_sfera_interface.savedPositionsSize(); if (!std::in_range<std::uint32_t>(size)) { reportError("Saved window positions exceed the MBC buffer limit"); break; } pushInteger(static_cast<std::uint32_t>(size)); break; }
        case WindowOperation::ReadSavedPositions:
            if (!read(2)) return;
            {
                const auto size = static_cast<std::size_t>(static_cast<std::uint32_t>(arguments[1]));
                const auto* data = memoryAt(static_cast<std::uint32_t>(arguments[0]), size);
                g_sfera_interface.readSavedPositions(std::span<const std::byte>(reinterpret_cast<const std::byte*>(data), size));
            }
            break;
        case WindowOperation::WriteSavedPositions: {
            if (!read(1)) return;
            const auto size = g_sfera_interface.savedPositionsSize();
            if (!std::in_range<std::uint32_t>(size)) { reportError("Saved window positions exceed the MBC buffer limit"); break; }
            g_sfera_interface.writeSavedPositions(std::span<std::byte>(reinterpret_cast<std::byte*>(memoryAt(static_cast<std::uint32_t>(arguments[0]), size)), size));
            break;
        }
        case WindowOperation::Position: case WindowOperation::Size: {
            if (!read(3)) return;
            if (operation == WindowOperation::Position) { warnNull(arguments[1], 1); warnNull(arguments[2], 2); }
            const auto* window = nativeResource<SphereUI::Window*>(static_cast<std::uint32_t>(arguments[0]));
            writeMemory(arguments[1], window ? operation == WindowOperation::Position ? window->x : window->width : 0);
            writeMemory(arguments[2], window ? operation == WindowOperation::Position ? window->y : window->height : 0);
            break;
        }
        case WindowOperation::Description:
            if (!read(2)) return;
            SphereUI::CDescriptionWindow::instance()->showDescription(inputText(arguments[0]), 0, 250, false);
            break;
        case WindowOperation::Tooltip:
            if (!read(1)) return;
            g_sfera_interface.setTooltipText(arguments[0] == 0 ? nullptr : inputText(arguments[0]));
            break;
        case WindowOperation::Options:
            if (!SferaClientApplication::resources_loaded) { pushInteger(0); return; }
            if (argument_count > 1) pushInteger(g_sfera_interface.findWindow("options") != nullptr ? 1 : UINT32_MAX);
            else { g_sfera_interface.showOptions(g_sfera_interface.findWindow("options") == nullptr); pushInteger(1); }
            break;
        case WindowOperation::EscapeWindow: pushInteger(!SferaClientApplication::resources_loaded ? 0 : g_sfera_interface.hasEscapeWindow() ? 1 : UINT32_MAX); break;
        case WindowOperation::LegacyCreateDialog:
            if (!read(2)) return;
            pushInteger(0);
            break;
        case WindowOperation::LegacyDestroyDialog:
            if (!read(1)) return;
            break;
        case WindowOperation::LegacyPollDialogEvent: {
            const auto count = argument_count == 6 ? 5u : argument_count >= 5 ? 4u : 3u;
            if (!read(count)) return;
            for (std::size_t index = 1; index < count; ++index) {
                if (arguments[index] != 0) writeMemory(arguments[index], std::uint32_t{0});
            }
            pushInteger(0);
            break;
        }
        case WindowOperation::LegacySendDialogMessage:
            if (!read(5)) return;
            pushInteger(0);
            break;
        case WindowOperation::LegacyDialogItem:
            if (!read(2)) return;
            pushInteger(0);
            break;
        case WindowOperation::LegacySetDialogText:
            if (!read(2)) return;
            pushInteger(0);
            break;
        case WindowOperation::LegacyGetDialogText:
            if (!read(3)) return;
            if (arguments[1] != 0 && arguments[2] > 0) *memoryAt(static_cast<std::uint32_t>(arguments[1]), 1u) = 0u;
            pushInteger(0);
            break;
        case WindowOperation::Shutdown:
            if (argument_count > 1) { if (!read(1)) return; pushInteger(SferaClientApplication::main_loop_started); }
            else SferaClientApplication::startup_complete = true;
            break;
        case WindowOperation::LegacyPumpMessages: break;
        case WindowOperation::ActiveWindow: pushInteger(GameInterface::active_window); break;
        case WindowOperation::LoadingProgress: if (GameInterface::loading_guard == 0) GameInterface::updateLoadingProgress(80); break;
        case WindowOperation::FinishLoading: GameInterface::finishLoading(); GameInterface::loading_guard = 1; break;
        default: break;
    }
}

void SferaMbcRuntime::writeScriptLog() {
    if (argument_cursor >= argument_end) { reportError("Too few parameters"); return; }
    const auto type = g_sfera_mbc_runtime.values[argument_cursor].type;
    const bool textValue = (type & 15u) != 0;
    const bool realValue = !textValue && type == SferaMbcValue::Real;
    const auto integer = realValue ? 0 : nextInteger();
    if (realValue) nextReal();
    if (execution_failed) return;
    if (textValue) (void)textAt(integer);
    if (argument_count == 2) nextInteger();
}

void SferaNetworkRuntime::enqueueMessage(std::span<const std::uint8_t> payload) noexcept {
    try {
        std::lock_guard lock(receive_mutex);
        // Preserve drop-new at the protocol limit, but never confuse full with empty.
        if (payload.size() > 400u || messages.size() >= kSferaNetworkMessageSlotCount) {
            ++dropped_messages;
            return;
        }
        messages.emplace_back(payload.begin(), payload.end());
        received_bytes.fetch_add(payload.size());
    } catch (...) {
        connection_lost = true;
        initialization_result = UINT32_MAX;
    }
}

void SferaTcpConnectionContext::fail() noexcept {
    connected_ = false;
    owner_.connection_lost = true;
    owner_.initialization_result = UINT32_MAX;
    receive_ready_.notify_all();
}

SferaNetworkStatistics SferaTcpConnectionContext::statistics() const {
    std::lock_guard lock(statistics_mutex_);
    return statistics_;
}

bool SferaTcpConnectionContext::acceptPacket(std::span<const std::uint8_t> packet, std::stop_token stop) {
    const auto header = SferaTcpIncomingHeader::decode(packet.data());
    switch (static_cast<TcpMessage>(header.message)) {
    case TcpMessage::connection_limit:
        fail();
        return false;
    case TcpMessage::handshake: {
        if (packet.size() < SferaTcpHandshakePacket::encodedSize) { fail(); return false; }
        const auto handshake = SferaTcpHandshakePacket::decode(packet.data());
        if (handshake.remote_id == 0) { fail(); return false; }
        {
            std::lock_guard lock(send_mutex_);
            checksum_seed_ = handshake.checksum_seed;
            sequence_ = static_cast<std::uint16_t>(std::rand() % 1000 + 1);
            std::array<std::uint8_t, 4> mode{};
            SferaBinary::writeLittleEndian(mode.data(), owner_.client_mode);
            if (!queuePacket(static_cast<std::uint32_t>(mode.size()), TcpMessage::client_mode, mode.data())) return false;
        }
        const auto started = WorldClock::milliseconds();
        for (;;) {
            if (stop.stop_requested() || !connected_) return false;
            sendPending();
            { std::lock_guard lock(send_mutex_); if (outgoing_.empty()) break; }
            if (WorldClock::milliseconds() - started >= 15000u) { fail(); return false; }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        handshake_complete_ = true;
        owner_.initialization_result = 1u;
        receive_ready_.notify_all();
        return true;
    }
    case TcpMessage::keepalive: {
        std::lock_guard lock(statistics_mutex_);
        statistics_.round_trip_latency_ms = (WorldClock::milliseconds() - keepalive_started_at_) / 3u;
        keepalive_answered_ = true;
        return true;
    }
    case TcpMessage::payload: {
        std::lock_guard lock(receive_mutex_);
        // The old staging buffer dropped complete packets that did not fit.
        if (packet.size() > kTcpReceiveBufferCapacity - incoming_bytes_) return true;
        incoming_.emplace_back(packet.begin() + SferaTcpIncomingHeader::encodedSize, packet.end());
        incoming_bytes_ += packet.size();
        receive_ready_.notify_one();
        return true;
    }
    default:
        return true; // Unknown framed messages were consumed without dispatch.
    }
}

void SferaTcpConnectionContext::receive(std::stop_token stop) noexcept {
    try {
        std::vector<std::uint8_t> bytes;
        bytes.reserve(kTcpReceiveBufferCapacity);
        std::array<std::uint8_t, 8192> chunk{};
        std::size_t first = 0;
        auto stats_tick = WorldClock::milliseconds();
        const auto handshake_started = stats_tick;
        while (!stop.stop_requested() && connected_) {
            const auto now = WorldClock::milliseconds();
            if (!handshake_complete_ && now - handshake_started >= 15000u) { fail(); break; }
            fd_set readable{};
            FD_SET(socket_.value, &readable);
            timeval timeout{0, 10000};
            const int selected = ::select(0, &readable, nullptr, nullptr, &timeout);
            if (selected == SOCKET_ERROR) { if (!stop.stop_requested()) fail(); break; }
            if (selected > 0) {
                const auto available = kTcpReceiveBufferCapacity - (bytes.size() - first);
                if (available == 0) { fail(); break; }
                const int count = ::recv(socket_.value, reinterpret_cast<char*>(chunk.data()),
                    static_cast<int>(std::min(available, chunk.size())), 0);
                if (count == 0) { if (!stop.stop_requested()) fail(); break; }
                if (count == SOCKET_ERROR) {
                    const auto error = ::WSAGetLastError();
                    if (error != WSAEWOULDBLOCK && error != WSAEINTR) { if (!stop.stop_requested()) fail(); break; }
                } else {
                    // Compact only when appending would exceed the reserved buffer.
                    if (bytes.size() + static_cast<std::size_t>(count) > kTcpReceiveBufferCapacity && first != 0) {
                        bytes.erase(bytes.begin(), bytes.begin() + static_cast<std::ptrdiff_t>(first));
                        first = 0;
                    }
                    bytes.insert(bytes.end(), chunk.begin(), chunk.begin() + count);
                    { std::lock_guard lock(statistics_mutex_); received_bytes_window_ += static_cast<std::uint32_t>(count); }
                }
            }
            while (bytes.size() - first >= SferaTcpIncomingHeader::encodedSize) {
                const auto header = SferaTcpIncomingHeader::decode(bytes.data() + first);
                if (header.size < SferaTcpIncomingHeader::encodedSize || header.size > kTcpReceiveBufferCapacity) { fail(); break; }
                if (bytes.size() - first < header.size) break;
                if (!acceptPacket(std::span<const std::uint8_t>(bytes).subspan(first, header.size), stop)) break;
                first += header.size;
            }
            if (first == bytes.size()) { bytes.clear(); first = 0; }
            if (now - stats_tick > 1000u) {
                stats_tick = now;
                std::lock_guard lock(statistics_mutex_);
                statistics_.received_bytes_per_second = std::exchange(received_bytes_window_, 0u);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(15));
        }
    } catch (...) { fail(); }
    connected_ = false;
    receive_ready_.notify_all();
}

void SferaTcpConnectionContext::dispatch(std::stop_token stop) noexcept {
    try {
        while (!stop.stop_requested()) {
            std::vector<std::uint8_t> message;
            {
                std::unique_lock lock(receive_mutex_);
                if (!receive_ready_.wait_for(lock, stop, std::chrono::milliseconds(6), [this] {
                    return !connected_ || (handshake_complete_ && !incoming_.empty());
                })) {
                    if (stop.stop_requested()) break;
                    continue;
                }
                if (!connected_) break;
                message = std::move(incoming_.front());
                incoming_.pop_front();
                incoming_bytes_ -= message.size() + SferaTcpIncomingHeader::encodedSize;
            }
            owner_.enqueueMessage(message);
        }
    } catch (...) { fail(); }
}

void SferaTcpConnectionContext::maintain(std::stop_token stop) noexcept {
    try {
        auto stats_tick = WorldClock::milliseconds();
        auto random_tick = stats_tick, keepalive_tick = stats_tick, send_tick = stats_tick;
        auto random_interval = static_cast<std::uint32_t>(std::rand() % 5000 + 2000);
        while (!stop.stop_requested() && connected_) {
            if (!handshake_complete_) { std::this_thread::sleep_for(std::chrono::milliseconds(10)); continue; }
            const auto now = WorldClock::milliseconds();
            if (now - stats_tick > 1000u) {
                stats_tick = now;
                std::lock_guard lock(statistics_mutex_);
                statistics_.sent_bytes_per_second = std::exchange(sent_bytes_window_, 0u);
            }
            if (now - send_tick > 15u) {
                send_tick = now;
                sendPending();
                std::lock_guard lock(send_mutex_);
                if (sequence_ > 50000u) { sequence_ = 1u; queuePacket(0u, TcpMessage::sequence_reset, nullptr); }
            }
            if (now - keepalive_tick > 3000u) {
                keepalive_tick = now;
                {
                    std::lock_guard lock(statistics_mutex_);
                    keepalive_started_at_ = now;
                    if (!keepalive_answered_) statistics_.round_trip_latency_ms += 3000u;
                    keepalive_answered_ = false;
                }
                queuePacket(0u, TcpMessage::keepalive, nullptr);
                sendPending();
            }
            if (now - random_tick > random_interval) {
                random_interval = static_cast<std::uint32_t>(std::rand() % 10000 + 3000);
                random_tick = now;
                std::lock_guard lock(send_mutex_);
                std::array<std::uint8_t, 4> count{};
                SferaBinary::writeLittleEndian(count.data(), packet_counter_);
                queuePacket(static_cast<std::uint32_t>(count.size()), TcpMessage::packet_counter, count.data());
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(4));
        }
    } catch (...) { fail(); }
}

void SferaTcpConnectionContext::sendPending() noexcept {
    try {
        std::lock_guard lock(send_mutex_);
        while (connected_ && !outgoing_.empty()) {
            const auto& packet = outgoing_.front();
            const auto remaining = packet.size() - outgoing_offset_;
            const int sent = ::send(socket_.value, reinterpret_cast<const char*>(packet.data() + outgoing_offset_),
                static_cast<int>(remaining), 0);
            if (sent == SOCKET_ERROR) {
                const auto error = ::WSAGetLastError();
                if (error != WSAEWOULDBLOCK && error != WSAEINTR) fail();
                return;
            }
            if (sent == 0) { fail(); return; }
            outgoing_offset_ += static_cast<std::size_t>(sent);
            outgoing_bytes_ -= static_cast<std::size_t>(sent);
            { std::lock_guard stats_lock(statistics_mutex_); sent_bytes_window_ += static_cast<std::uint32_t>(sent); }
            if (outgoing_offset_ == packet.size()) { outgoing_.pop_front(); outgoing_offset_ = 0; }
        }
    } catch (...) { fail(); }
}

bool SferaTcpConnectionContext::queuePacket(std::uint32_t payloadSize, TcpMessage message, const void* payload) noexcept {
    try {
        std::lock_guard lock(send_mutex_);
        if (!connected_) return false;
        if (payloadSize > UINT16_MAX - SferaTcpOutgoingHeader::encodedSize ||
            payloadSize + SferaTcpOutgoingHeader::encodedSize > sendCapacity - outgoing_bytes_ ||
            (payloadSize != 0 && payload == nullptr)) { fail(); return false; }
        const auto packet_size = payloadSize + SferaTcpOutgoingHeader::encodedSize;
        std::vector<std::uint8_t> packet(packet_size);
        const auto next_sequence = static_cast<std::uint16_t>(sequence_ + std::rand() % 4 + 1);
        SferaTcpOutgoingHeader{static_cast<std::uint16_t>(packet_size), 0u, next_sequence,
            static_cast<std::uint16_t>(message)}.encode(packet.data());
        if (payloadSize != 0) std::memcpy(packet.data() + SferaTcpOutgoingHeader::encodedSize, payload, payloadSize);
        std::uint16_t checksum = 0;
        for (std::size_t i = SferaTcpOutgoingHeader::checksumPayloadOffset; i < packet.size(); ++i)
            checksum = static_cast<std::uint16_t>(checksum + std::bit_cast<std::int8_t>(packet[i]));
        SferaBinary::writeLittleEndian(packet.data() + SferaTcpOutgoingHeader::checksumOffset,
            static_cast<std::uint16_t>(checksum_seed_ ^ checksum));
        outgoing_.push_back(std::move(packet));
        outgoing_bytes_ += packet_size;
        sequence_ = next_sequence;
        ++packet_counter_;
        return true;
    } catch (...) { fail(); return false; }
}

bool SferaNetworkRuntime::sendPacket(std::uint32_t flags, std::span<const std::uint8_t> payload) {
    if (initialization_result != 1u || !connection || !connection->isConnected()) return false;
    if (payload.size() > UINT16_MAX - SferaTcpOutgoingHeader::encodedSize - 1u) return false;
    std::vector<std::uint8_t> message(payload.size() + 1u);
    message[0] = static_cast<std::uint8_t>(flags);
    std::copy(payload.begin(), payload.end(), message.begin() + 1u);
    encodePayload(message.data() + 1u, static_cast<int>(payload.size()));
    if (!connection->queuePacket(static_cast<std::uint32_t>(message.size()), TcpMessage::payload, message.data())) return false;
    sent_bytes.fetch_add(payload.size());
    return true;
}

std::uint32_t SferaMbcBitStream::read(unsigned width) {
    if (!valid_ || width > 32 || position_ > data_.size() * 8 || width > data_.size() * 8 - position_) { valid_ = false; return 0; }
    std::uint32_t value = 0;
    for (unsigned bit = 0; bit < width; ++bit, ++position_) value |= std::uint32_t((data_[position_ / 8] >> (position_ % 8)) & 1u) << bit;
    return value;
}

void SferaMbcBitStream::write(std::uint32_t value, unsigned width) {
    if (!valid_ || output_ == nullptr || width > 32 || position_ > data_.size() * 8 || width > data_.size() * 8 - position_) { valid_ = false; return; }
    for (unsigned bit = 0; bit < width; ++bit, ++position_) {
        const std::uint8_t mask = 1u << (position_ % 8);
        auto& destination = output_[position_ / 8];
        destination = (destination & ~mask) | (((value >> bit) & 1u) ? mask : 0);
    }
}

void SferaMbcBitStream::append(std::span<const std::uint8_t> data, std::size_t bits) {
    if (bits > data.size() * 8 || position_ > data_.size() * 8 || bits > data_.size() * 8 - position_) { valid_ = false; return; }
    SferaMbcBitStream source(data);
    while (bits != 0 && valid_) { const auto width = static_cast<unsigned>(std::min<std::size_t>(bits, 32)); write(source.read(width), width); bits -= width; }
}

std::uint32_t SferaMbcBitStream::encodeCoordinate(int origin, float coordinate) {
    const float reference = origin;
    const auto magnitude = std::fabs(static_cast<float>(double(coordinate) - reference));
    if (!std::isfinite(magnitude) || magnitude >= 120.0f) return UINT32_MAX;
    const float inverse = 1.0 / (double(magnitude) + 40.0);
    const auto minimum = double(0.0062500000931322575f);
    const auto normalized = (double(inverse) - minimum) / (double(g_sfera_mbc_runtime.inverse_coordinate_scale) - minimum);
    return static_cast<std::uint32_t>(std::trunc(normalized * double(coordinateMagnitudeMask))) | (coordinate < reference ? coordinateSignBit : 0u);
}

float SferaMbcBitStream::decodeCoordinate(int origin, std::uint32_t code) {
    const auto minimum = double(0.0062500000931322575f);
    const float inverse = (double(g_sfera_mbc_runtime.inverse_coordinate_scale) - minimum) * (double(code & coordinateMagnitudeMask) / double(coordinateMagnitudeMask)) + minimum;
    float distance = 1.0 / double(inverse) - 40.0;
    if (code & coordinateSignBit) distance = -distance;
    return double(origin) + distance;
}

std::uint32_t SferaMbcBitStream::readField(std::int8_t format, std::span<const int, 3> origin) {
    if (format <= 32) {
        const auto width = static_cast<unsigned>(format < 0 ? -int(format) : format);
        const auto value = read(width);
        if (format < 0 && width < 32 && width != 0 && (value & (1u << (width - 1)))) return value | (UINT32_MAX << width);
        return value;
    }
    if (format == 'g') {
        const bool negative = read(1) != 0;
        const auto width = variableIntegerWidths[read(2)];
        const auto magnitude = read(width);
        return negative ? 0u - magnitude : magnitude;
    }
    if (format >= 'i' && format <= 'k') return std::bit_cast<std::uint32_t>(decodeCoordinate(origin[format - 'i'], read(12)));
    if (format == 'l') return std::bit_cast<std::uint32_t>(static_cast<float>(double(read(8)) * 0.02454369328916073));
    valid_ = false;
    return 0;
}

bool SferaMbcBitStream::writeField(std::int8_t format, std::uint32_t value, std::span<const int, 3> origin) {
    if (format <= 32) write(value, static_cast<unsigned>(format < 0 ? -int(format) : format));
    else if (format == 'g') {
        const bool negative = static_cast<int>(value) < 0;
        const auto magnitude = negative ? 0u - value : value;
        const int signedMagnitude = magnitude;
        const auto selector = signedMagnitude < 8 ? 0u : signedMagnitude < 128 ? 1u : signedMagnitude < 16384 ? 2u : 3u;
        write(negative, 1); write(selector, 2); write(magnitude, variableIntegerWidths[selector]);
    } else if (format >= 'i' && format <= 'k') {
        const auto code = encodeCoordinate(origin[format - 'i'], std::bit_cast<float>(value));
        if (code == UINT32_MAX) return false;
        write(code, 12);
    } else if (format == 'l') {
        auto angle = std::bit_cast<float>(value);
        if (!std::isfinite(angle) || angle < -1000.0f || angle > 1000.0f) angle = 0;
        while (angle < 0) angle = double(angle) + 6.2831854820251465;
        const float scaled = double(angle) * 40.7436637878418;
        write(static_cast<std::uint32_t>(std::trunc(scaled)) & 255u, 8);
    }
    return true;
}

void SferaMbcRuntime::receiveRegion() {
    const auto wrongCount = [this]() { reportError("Wrong number of parameters for 'receive' function"); };
    const auto wrongData = [this]() { reportError("Wrong data for 'receive' function"); };
    if (argument_count == 0) { wrongCount(); return; }
    const std::uint32_t region = nextInteger();
    --argument_count;
    if (execution_failed) return;
    if (region > 61 || active_process == nullptr || active_process->regions.empty()) { reportError("Wrong region for 'receive' function"); return; }
    auto& queue = active_process->received_regions[region];
    if (queue == nullptr || queue->empty()) { pushInteger(UINT32_MAX); return; }
    auto packet = std::move(queue->front());
    queue->pop_front();
    if (queue->empty()) queue.reset();
    SferaMbcBitStream stream{std::span<const std::uint8_t>(packet.data)};
    const auto& description = active_process->regions[region];
    if (description.field_count > static_cast<int>(std::size(description.formats))) { wrongData(); return; }
    const auto nextOutput = [this, &wrongCount]() -> const SferaMbcValue* {
        if (argument_count == 0 || argument_cursor >= argument_end || argument_cursor >= std::size(g_sfera_mbc_runtime.values)) { wrongCount(); return nullptr; }
        --argument_count;
        return &g_sfera_mbc_runtime.values[argument_cursor++];
    };
    const auto store = [this, &wrongData](const SferaMbcValue& target, std::uint32_t value) {
        const auto size = SferaMbcValue::storageSize(target.type);
        if (size > sizeof(value) || target.source.base == UINT32_MAX) { wrongData(); return false; }
        std::memcpy(memoryAt(target.source.base, size), &value, size);
        return true;
    };
    for (int field = 0; field < description.field_count; ++field) {
        const auto format = description.formats[field];
        if (format == 'e' || format == 'f') {
            const auto encodedCount = stream.read(format == 'e' ? 4 : 8);
            if (!stream.valid() || field + 1 >= description.field_count) { wrongData(); return; }
            const auto count = mbc_array_count(encodedCount, format, description.formats[field + 1], stream.remaining());
            const auto* countOutput = nextOutput();
            if (countOutput == nullptr || !store(*countOutput, count)) return;
            const auto* array = nextOutput();
            if (array == nullptr) return;
            if (!array->isPointer()) { wrongData(); return; }
            ++field;
            const auto elementSize = array->elementSize();
            if (elementSize > sizeof(std::uint32_t)) { wrongData(); return; }
            if (count > SIZE_MAX / elementSize) { wrongData(); return; }
            auto* destination = memoryAt(array->value.base, std::size_t(count) * elementSize);
            for (std::uint32_t index = 0; index < count; ++index) {
                const auto value = stream.readField(description.formats[field], packet.origin);
                if (!stream.valid()) { wrongData(); return; }
                std::memcpy(destination, &value, elementSize);
                destination += elementSize;
            }
        } else {
            const auto value = stream.readField(format, packet.origin);
            if (!stream.valid()) { wrongData(); return; }
            const auto* destination = nextOutput();
            if (destination == nullptr || !store(*destination, value)) return;
        }
    }
    if ((description.flags & 1) == 0) active_process->region_timestamps[region] = packet.timestamp;
    pushInteger(packet.timestamp);
}

void SferaMbcRuntime::sendRegion(int slotIndex, std::uint32_t region, std::uint32_t flags) {
    if (slotIndex < 0 || static_cast<std::size_t>(slotIndex) >= std::size(g_sfera_mbc_runtime.world_slots) || active_process == nullptr) return;
    auto& slot = g_sfera_mbc_runtime.world_slots[slotIndex];
    if ((slot.state & 4) || findProcess(slot.linked_handle) == nullptr) return;
    const bool reliable = (flags & 1) != 0;
    auto& bitCount = reliable ? slot.reliable_bit_count : slot.unreliable_bit_count;
    auto& lastProcess = reliable ? slot.reliable_process : slot.unreliable_process;
    auto payload = std::span<std::uint8_t>(reliable ? slot.reliable_payload : slot.unreliable_payload, sizeof(slot.reliable_payload));
    const auto captureOrigin = [this, &slot]() {
        SferaVec3F position;
        std::memcpy(&position, memoryAt(active_process->field_084), sizeof(position));
        slot.origin[0] = SferaMbcValue::truncate(position.x); slot.origin[1] = SferaMbcValue::truncate(position.y); slot.origin[2] = SferaMbcValue::truncate(position.z);
    };
    if (!reliable && bitCount == 0) captureOrigin();
    constexpr std::size_t regionBitLimit = 4096;
    constexpr std::size_t maximumFieldBits = 34;
    std::array<std::uint8_t, (regionBitLimit + maximumFieldBits + 7) / 8> regionBuffer{};
    std::uint32_t regionBits = 0;
    SferaMbcBitStream encoded{std::span<std::uint8_t>(regionBuffer)};
    encoded.write(region + 1, 7);
    bool coordinatesValid = true;
    if (send_field_count > outgoing_fields.size()) { reportError("Too long data for region"); return; }
    for (std::uint32_t field = 0; field < send_field_count; ++field) {
        regionBits = encoded.position();
        if (regionBits >= regionBitLimit) { reportError("Too long data for region"); return; }
        if (!encoded.writeField(static_cast<std::int8_t>(outgoing_fields[field].format), outgoing_fields[field].word, slot.origin)) coordinatesValid = false;
    }
    regionBits = encoded.position();
    if (!coordinatesValid) { regionBits = 0; return; }
    if (!encoded.valid() || bitCount > payload.size() * 8) { reportError("Too long data for region"); return; }
    if (bitCount != 0 && bitCount + regionBits + 37 > 1600) {
        if (!g_sfera_network_runtime.sendPacket(reliable ? 8 : 0, payload.first((bitCount + 7) / 8))) return;
        lastProcess = UINT32_MAX;
        bitCount = 0;
        std::fill(payload.begin(), payload.end(), std::uint8_t{});
        if (!reliable) captureOrigin();
    }
    SferaMbcBitStream output(payload, bitCount);
    if (bitCount == 0) {
        const bool hasOrigin = !reliable && (active_process->flags & 2) == 0;
        output.write(hasOrigin, 1);
        if (hasOrigin) { output.write(static_cast<std::uint32_t>(slot.origin[0]) + 32768u, 16); output.write(static_cast<std::uint32_t>(slot.origin[1]) + 1200u, 13); output.write(static_cast<std::uint32_t>(slot.origin[2]) + 32768u, 16); }
        output.write(static_cast<std::uint32_t>(static_cast<int>(g_sfera_mbc_runtime.simulation_tick) >> 3), 15);
        lastProcess = UINT32_MAX;
    }
    if (lastProcess != active_process->process_id) {
        if (lastProcess != UINT32_MAX) output.write(63, 7);
        output.write(active_process->process_id, 18);
        output.write(active_process->module_tag, 12);
        lastProcess = active_process->process_id;
    }
    output.append(regionBuffer, regionBits);
    bitCount = output.position();
    if (!output.valid()) reportError("Too long data for region");
}

bool SferaMbcModuleImage::read(std::span<const std::uint8_t> data, bool linking) {
    const auto take = [&data](std::size_t size) { if (size > data.size()) throw std::out_of_range("Truncated MBC module"); const auto result = data.first(size); data = data.subspan(size); return result; };
    const auto value = [&take]<class T>() { return SferaBinary::readLittleEndian<T>(take(sizeof(T)).data()); };
    const auto name = [&take, &data](auto& destination) { const auto end = std::find(data.begin(), data.end(), std::uint8_t{}); const std::size_t size = end - data.begin(); if (end == data.end() || size >= std::size(destination)) throw std::out_of_range("Invalid MBC name"); const auto bytes = take(size + 1); std::copy(bytes.begin(), bytes.end(), destination); };
    try {
        const auto signature = take(16);
        const auto version = (int(signature[12]) - '0') * 10 + int(signature[14]) - '0';
        value.operator()<std::uint32_t>(); // Reserved header word remains part of the encoded image.
        module_tag = value.operator()<std::uint32_t>();
        const auto codeSize = value.operator()<std::uint32_t>();
        const auto memorySize = value.operator()<std::uint32_t>();
        if (module_tag >= 4096 || codeSize > UINT32_MAX - 2) return false;
        bytecode = take(codeSize);
        memory = take(memorySize);
        const auto programCount = value.operator()<std::uint32_t>();
        if (programCount > 32766 || programCount > data.size() / 15) return false;
        programs.assign(programCount, {});
        for (auto& program : programs) {
            name(program.name);
            program.entry_offset = value.operator()<std::uint32_t>();
            program.stop_offset = value.operator()<std::uint32_t>();
            program.state = value.operator()<std::int8_t>();
            program.priority = value.operator()<std::uint8_t>();
            (void)value.operator()<std::uint32_t>(); // Reserved local-memory word in the module format.
            program.instruction_offset = program.entry_offset;
            program.caller_program = -1;
            if (program.priority >= 4) return false;
        }
        const auto functionCount = value.operator()<std::uint32_t>();
        if (functionCount > 65535 || functionCount > data.size() / 13) return false;
        functions.assign(functionCount, {});
        for (auto& function : functions) {
            name(function.name);
            function.entry_offset = value.operator()<std::uint32_t>();
            function.program_index = value.operator()<int>();
            function.allow_reentry = value.operator()<std::uint32_t>() != 0;
        }
        // Older modules store only the first 30 function slots.
        function_map.fill(UINT16_MAX);
        const auto mapBytes = take((version <= 22 ? 30 : function_map.size()) * sizeof(std::uint16_t));
        for (std::size_t index = 0; index < mapBytes.size() / sizeof(std::uint16_t); ++index) function_map[index] = SferaBinary::readLittleEndian<std::uint16_t>(mapBytes.data() + index * sizeof(std::uint16_t));
        region_definitions = take(value.operator()<std::uint32_t>());
        position_memory_offset = value.operator()<std::uint32_t>();
        take(2 * sizeof(std::uint32_t)); // Reserved exports; consume without storing runtime mirrors.
        if (linking) for (auto& table : relocations) {
            const auto count = value.operator()<std::uint32_t>();
            if (count > data.size() / sizeof(std::uint32_t)) return false;
            table.resize(count);
            for (auto& offset : table) offset = value.operator()<std::uint32_t>();
        }
        return true;
    } catch (const std::out_of_range&) { return false; }
}

void SferaMbcProcessRecord::readRegions(std::span<const std::uint8_t> definitions, std::uint32_t firstProgram) {
    if (regions.empty()) return;
    std::size_t cursor = 0;
    while (cursor < definitions.size()) {
        if (definitions[cursor] != 127) { ++cursor; continue; }
        if (definitions.size() - cursor < 5) break;
        const auto regionIndex = definitions[cursor + 1];
        const std::int8_t flags = definitions[cursor + 2];
        std::uint16_t program;
        std::memcpy(&program, definitions.data() + cursor + 3, sizeof(program));
        cursor += 5;
        const auto firstField = cursor;
        while (cursor < definitions.size() && definitions[cursor] != 127) ++cursor;
        if (regionIndex >= 62) continue;
        auto& region = regions[regionIndex];
        if (region.flags == -1) {
            region.flags = flags;
            region.field_count = std::min<std::size_t>(cursor - firstField, std::size(region.formats));
            std::copy_n(definitions.data() + firstField, region.field_count, region.formats);
        }
        if (program != UINT16_MAX && region.program_index == UINT16_MAX) region.program_index = firstProgram + program;
    }
}

std::uint32_t SferaMbcRuntime::loadProcess(std::string_view name, std::uint32_t requestedIndex) {
    text_buffer[0] = 0;
    if (name.starts_with('@')) {
        const auto end = name.find('@', 1);
        if (end == std::string_view::npos) return UINT32_MAX;
        std::size_t used = 0;
        for (const char character : name.substr(1, end - 1)) {
            const auto needed = character == ';' ? 2u : 1u;
            if (needed >= sizeof(text_buffer) - used) return UINT32_MAX;
            if (character == ';') { text_buffer[used++] = '\r'; text_buffer[used++] = '\n'; }
            else text_buffer[used++] = character == '\'' ? '"' : character;
        }
        text_buffer[used] = 0;
        name.remove_prefix(end + 1);
    }
    if (name.size() >= 32 || !quick_files) return UINT32_MAX;
    const auto* file = quick_files->find(std::string(name) + ".mbc");
    if (!file || file->bytes.size() < 16) return UINT32_MAX;
    std::uint32_t index = requestedIndex;
    if (index == UINT32_MAX) {
        index = process_search_cursor;
        const auto first = index;
        while (processes[index].chain_prev_index >= 0) {
            index = (index + 1) % std::size(processes);
            if (index == first) return UINT32_MAX;
        }
    } else if (index >= std::size(processes) || processes[index].chain_prev_index >= 0) return UINT32_MAX;
    SferaMbcModuleImage module;
    if (!module.read(file->bytes, false) || module.memory.size() >= mappedAddressBegin ||
        module.bytecode.size() > UINT32_MAX || module.programs.size() > 32767 || module.functions.size() > 65535) return UINT32_MAX;

    // Nothing is published in the slot table or scheduler until all allocations and decoding succeed.
    SferaMbcProcessRecord replacement{};
    replacement.linked_modules.fill(0);
    replacement.linked_modules.front() = file->module_id;
    std::copy(name.begin(), name.end(), replacement.name);
    replacement.name[name.size()] = '\0';
    replacement.module_tag = module.module_tag;
    replacement.bytecode = findBytecode(replacement.linked_modules, static_cast<std::uint32_t>(module.memory.size()));
    if (!replacement.bytecode) {
        auto code = std::make_shared<std::vector<std::uint8_t>>(module.bytecode.begin(), module.bytecode.end());
        replacement.bytecode = cacheBytecode(std::move(code), replacement.linked_modules, static_cast<std::uint32_t>(module.memory.size()));
    }
    replacement.memory.assign(module.memory.begin(), module.memory.end());
    replacement.programs = std::move(module.programs);
    replacement.functions = std::move(module.functions);
    replacement.function_map = module.function_map;
    replacement.regions.assign(62, SferaMbcRegionRecord::undefined());
    replacement.readRegions(module.region_definitions, 0);
    replacement.field_084 = module.position_memory_offset;
    replacement.code_range_ids[0] = static_cast<std::uint16_t>(module.module_tag);
    replacement.code_range_size[0] = replacement.codeSize();
    replacement.code_range_count = 1;
    std::fill(std::begin(replacement.program_map_a), std::end(replacement.program_map_a), UINT16_MAX);
    std::fill(std::begin(replacement.program_map_b), std::end(replacement.program_map_b), UINT16_MAX);
    std::fill(std::begin(replacement.region_timestamps), std::end(replacement.region_timestamps), UINT32_MAX);
    replacement.process_id = index;
    replacement.lifetime = next_process_lifetime++;
    replacement.execution_prev_index = replacement.execution_next_index = static_cast<std::int32_t>(index);
    replacement.chain_prev_index = process_chain_last < 0 ? static_cast<std::int32_t>(index) : process_chain_last;
    replacement.chain_next_index = static_cast<std::int32_t>(index);
    auto& process = processes[index];
    process = std::move(replacement);
    if (process_chain_last >= 0) processes[process_chain_last].chain_next_index = static_cast<std::int32_t>(index);
    else process_chain_first = static_cast<std::int32_t>(index);
    process_chain_last = static_cast<std::int32_t>(index);
    process_search_cursor = (index + 1) % std::size(processes);
    for (std::uint32_t program = 0; program < process.programs.size(); ++program)
        if (process.programs[program].state == 1) process.linkProgram(program);
    if (process.programs_queued) enqueueProcess(static_cast<int>(index), process);
    return process.process_id;
}

std::uint32_t SferaMbcRuntime::linkProcess(std::string_view name) {
    if (name.size() >= 32 || process_index >= std::size(processes) || !quick_files) return UINT32_MAX;
    const auto filename = std::string(name) + ".mbc";
    const auto* file = quick_files->find(filename);
    if (!file || file->bytes.size() < 16) return UINT32_MAX;
    SferaMbcModuleImage module;
    if (!module.read(file->bytes, true)) return UINT32_MAX;
    auto& process = processes[process_index];
    if (process.chain_prev_index < 0 || !process.bytecode) return UINT32_MAX;
    auto modules = process.linked_modules;
    const auto freeModule = std::find(modules.begin(), modules.end(), std::uint16_t{});
    if (freeModule == modules.end()) { reportError("Cannot link a process - increase MAX_LINKED_PRCS! Linked prc: ", filename.c_str()); return UINT32_MAX; }
    const auto codeOffset = process.codeSize();
    if (process.memory.size() > mappedAddressBegin - 4u) return UINT32_MAX;
    const auto memoryOffset = static_cast<std::uint32_t>((process.memory.size() + 3u) & ~std::size_t{3});
    const auto firstProgram = static_cast<std::uint32_t>(process.programs.size());
    const auto firstFunction = static_cast<std::uint32_t>(process.functions.size());
    if (firstProgram > 32767u || firstFunction > 65535u || module.bytecode.size() > UINT32_MAX - codeOffset ||
        module.memory.size() >= mappedAddressBegin - memoryOffset || module.programs.size() > 32767u - firstProgram ||
        module.functions.size() > 65535u - firstFunction) return UINT32_MAX;
    const auto validRelocations = [](const auto& table, std::size_t size, std::size_t width) {
        return std::all_of(table.begin(), table.end(), [=](std::uint32_t offset) { return offset <= size && width <= size - offset; });
    };
    if (!validRelocations(module.relocations[0], module.bytecode.size(), 4) ||
        !validRelocations(module.relocations[1], module.memory.size(), 4) ||
        !validRelocations(module.relocations[2], module.bytecode.size(), 2)) return UINT32_MAX;
    const auto instructionOffset = static_cast<std::uint32_t>(instruction_cursor - process.codeData());
    const auto currentOffset = static_cast<std::uint32_t>(current_instruction_address - process.codeData());
    *freeModule = file->module_id;

    auto memory = process.memory;
    memory.resize(memoryOffset + module.memory.size(), 0);
    std::copy(module.memory.begin(), module.memory.end(), memory.begin() + memoryOffset);
    auto programs = process.programs;
    programs.insert(programs.end(), module.programs.begin(), module.programs.end());
    for (auto index = firstProgram; index < programs.size(); ++index) {
        auto& program = programs[index];
        program.entry_offset += codeOffset;
        program.stop_offset += codeOffset;
        program.instruction_offset = program.entry_offset;
    }
    auto functions = process.functions;
    functions.insert(functions.end(), module.functions.begin(), module.functions.end());
    for (auto index = firstFunction; index < functions.size(); ++index) {
        auto& function = functions[index];
        function.entry_offset += codeOffset;
        if (function.program_index != -1) function.program_index += firstProgram;
    }
    auto functionMap = process.function_map;
    for (std::size_t index = 0; index < functionMap.size(); ++index)
        if (functionMap[index] == UINT16_MAX && module.function_map[index] != UINT16_MAX)
            functionMap[index] = static_cast<std::uint16_t>(module.function_map[index] + firstFunction);
    // Reuse only the region decoder; it writes no scheduler or global state.
    SferaMbcProcessRecord bindings{};
    bindings.regions = process.regions;
    bindings.readRegions(module.region_definitions, firstProgram);
    const auto relocate = []<class T>(std::uint8_t* destination, const auto& table, std::uint32_t increment) {
        for (const auto offset : table) {
            const auto value = SferaBinary::readLittleEndian<T>(destination + offset);
            SferaBinary::writeLittleEndian(destination + offset, static_cast<T>(value + increment));
        }
    };
    relocate.operator()<std::uint32_t>(memory.data() + memoryOffset, module.relocations[1], memoryOffset);
    auto code = findBytecode(modules, memoryOffset);
    if (!code) {
        auto writable = std::make_shared<std::vector<std::uint8_t>>(*process.bytecode);
        writable->insert(writable->end(), module.bytecode.begin(), module.bytecode.end());
        const auto resolve = [&](std::uint32_t first, std::uint32_t last, std::uint32_t targetFirst, std::uint32_t targetLast) {
            for (auto index = first; index < last; ++index) {
                const auto& declaration = functions[index];
                if (declaration.program_index != -1) continue;
                for (auto target = targetFirst; target < targetLast; ++target) {
                    const auto& implementation = functions[target];
                    if (implementation.program_index == -1 || std::strcmp(declaration.name, implementation.name) != 0) continue;
                    if (declaration.entry_offset <= writable->size() && writable->size() - declaration.entry_offset >= 5) {
                        auto* instruction = writable->data() + declaration.entry_offset;
                        *instruction = 'G';
                        SferaBinary::writeLittleEndian(instruction + 1, implementation.entry_offset - declaration.entry_offset - 1u);
                    }
                    break;
                }
            }
        };
        resolve(firstFunction, static_cast<std::uint32_t>(functions.size()), 0, firstFunction);
        resolve(0, firstFunction, firstFunction, static_cast<std::uint32_t>(functions.size()));
        relocate.operator()<std::uint32_t>(writable->data() + codeOffset, module.relocations[0], memoryOffset);
        relocate.operator()<std::uint16_t>(writable->data() + codeOffset, module.relocations[2], firstProgram);
        code = cacheBytecode(std::move(writable), modules, memoryOffset);
    }
    // Commit consists solely of nonthrowing owner moves and scalar updates.
    process.bytecode = std::move(code);
    process.memory.swap(memory);
    process.programs.swap(programs);
    process.functions.swap(functions);
    process.function_map = functionMap;
    process.regions.swap(bindings.regions);
    process.linked_modules = modules;
    if (process.code_range_count < std::size(process.code_range_ids)) {
        const auto range = process.code_range_count++;
        process.code_range_ids[range] = static_cast<std::uint16_t>(module.module_tag);
        process.code_range_begin[range] = codeOffset;
        process.code_range_size[range] = static_cast<std::uint32_t>(module.bytecode.size());
    }
    bytecode_base = process.codeData();
    instruction_cursor = bytecode_base + instructionOffset;
    current_instruction_address = bytecode_base + currentOffset;
    process_memory_base = process.memory.data();
    program_table_base = process.programs.data();
    active_program_record = &process.programs[program_index];
    for (auto index = firstProgram; index < process.programs.size(); ++index)
        if (process.programs[index].state == 1) process.linkProgram(index);
    return 0;
}

void SferaMbcProcessRecord::releaseResources() {
    const auto pending = std::exchange(cleanup_entries, {});
    for (const auto& entry : pending) {
        try {
        if (!resourceIsCurrent(entry)) continue;
        if (entry.kind == ResourceKind::textControl) WorldGuiControls::destroyText(entry.handle);
        else if (entry.kind == ResourceKind::spriteControl) WorldGuiControls::destroySprite(entry.handle);
        } catch (const std::exception& error) { ::OutputDebugStringA(error.what()); }
        catch (...) { ::OutputDebugStringA("Process resource cleanup failed"); }
    }
    for (const auto& entry : pending) {
        try {
        if (!resourceIsCurrent(entry)) continue;
        switch (entry.kind) {
            case ResourceKind::worldObject: g_sfera_world_objects.destroy(entry.handle); break;
            case ResourceKind::file: ::_close(static_cast<int>(entry.handle)); break;
            case ResourceKind::fileSearch: { const auto search = g_sfera_mbc_runtime.nativeResource<std::intptr_t>(entry.handle); if (search != -1) { ::_findclose(search); g_sfera_mbc_runtime.forgetNativeResource(search); } break; }
            case ResourceKind::dynamicArray: {
                std::uint32_t offset{};
                const auto* source = g_sfera_mbc_runtime.memoryAt(entry.handle, sizeof(offset), this);
                if (source == nullptr) break;
                std::memcpy(&offset, source, sizeof(offset));
                g_sfera_mbc_runtime.releaseDynamic(offset);
                break;
            }
            case ResourceKind::gameWindow: GameInterface::destroyWindow(entry.handle); break;
            case ResourceKind::interfaceWindow: g_sfera_interface.closeWindow(g_sfera_mbc_runtime.nativeResource<SphereUI::Window*>(entry.handle), true); break;
            case ResourceKind::container: { auto* container = g_sfera_mbc_runtime.nativeResource<SferaScriptContainer*>(entry.handle); if (container != nullptr && container->header.kind >= SferaDataContainerHeader::Kind::List && container->header.kind <= SferaDataContainerHeader::Kind::HashMap) g_sfera_mbc_runtime.destroyContainer(entry.handle); break; }
            default: break;
        }
        } catch (const std::exception& error) { ::OutputDebugStringA(error.what()); }
        catch (...) { ::OutputDebugStringA("Process resource cleanup failed"); }
    }
}

std::uint32_t SferaMbcRuntime::unloadProcess(std::uint32_t index) {
    if (index >= std::size(processes)) return UINT32_MAX;
    auto& process = processes[index];
    if (process.chain_prev_index < 0) return UINT32_MAX;
    if (index == 0) g_sfera_log_runtime.write("prc_unload _main.mbl\n");
    const auto previous = process.chain_prev_index;
    const auto next = process.chain_next_index;
    if (process_chain_first == static_cast<std::int32_t>(index) && process_chain_last == static_cast<std::int32_t>(index)) {
        process_chain_first = process_chain_last = -1;
    } else if (process_chain_last == static_cast<std::int32_t>(index)) {
        process_chain_last = previous; processes[previous].chain_next_index = previous;
    } else if (process_chain_first == static_cast<std::int32_t>(index)) {
        process_chain_first = next; processes[next].chain_prev_index = next;
    } else {
        processes[next].chain_prev_index = previous; processes[previous].chain_next_index = next;
    }
    dequeueProcess(process);
    process.flags |= SferaMbcProcessRecord::unloadAfterExecution;
    // Mark first to protect against callbacks reentering unload. Resources still see valid memory.
    process.chain_prev_index = -1;
    if (!process.cleanup_entries.empty()) process.releaseResources();
    forgetMemory(&process);
    process.programs.clear(); process.functions.clear(); process.memory.clear();
    process.bytecode.reset(); process.physics_commands.clear(); process.regions.clear();
    process.function_map.fill(UINT16_MAX);
    for (std::size_t region = 0; region < process.received_regions.size(); ++region) {
        process.region_timestamps[region] = UINT32_MAX;
        process.received_regions[region].reset();
    }
    process.process_id = UINT32_MAX;
    // Keep execution_prev_index until the scheduler has advanced past this slot.
    return 0;
}

bool SferaMbcBitStream::skipRegion(const SferaMbcRegionRecord& region) {
    if (region.field_count < 0 || region.field_count > static_cast<int>(std::size(region.formats))) return false;
    for (int field = 0; field < region.field_count && valid_; ++field) {
        auto format = std::abs(int(region.formats[field]));
        std::uint32_t count = 1;
        if (format == 'e' || format == 'f') {
            const auto countFormat = static_cast<std::int8_t>(format);
            const auto encodedCount = read(format == 'e' ? 4 : 8);
            if (!valid_ || ++field >= region.field_count) return false;
            count = mbc_array_count(encodedCount, countFormat, region.formats[field], remaining());
            format = std::abs(int(region.formats[field]));
        }
        for (std::uint32_t element = 0; element < count && valid_; ++element) {
            if (format <= 32) read(format);
            else if (format >= 'i' && format <= 'k') read(12);
            else if (format == 'l') read(8);
            else if (format == 'g') { read(1); read(variableIntegerWidths[read(2)]); }
            else return false;
        }
    }
    return valid_;
}

void SferaMbcProcessRecord::queueRegion(std::size_t region, std::uint32_t timestamp, std::span<const int, 3> origin,
    std::span<const std::uint8_t> payload, std::size_t firstBit, std::size_t bitCount, bool ordered) {
    if (region >= received_regions.size() || payload.size() > SIZE_MAX / 8 || firstBit > payload.size() * 8 || bitCount > payload.size() * 8 - firstBit) return;
    SferaMbcRegionPacket packet;
    packet.timestamp = timestamp;
    std::copy(origin.begin(), origin.end(), packet.origin.begin());
    // Ordered packets have a legacy trailing byte even when the payload ends on a byte boundary.
    const auto byteCount = bitCount / 8 + (ordered || bitCount % 8 != 0 ? 1 : 0);
    packet.data.resize(byteCount);
    SferaMbcBitStream source(payload, firstBit);
    SferaMbcBitStream destination{std::span<std::uint8_t>(packet.data)};
    for (auto remaining = bitCount; remaining != 0;) {
        const auto width = static_cast<unsigned>(std::min<std::size_t>(remaining, 32));
        destination.write(source.read(width), width);
        remaining -= width;
    }
    if (!source.valid() || !destination.valid()) return;
    auto& queue = received_regions[region];
    if (queue == nullptr) {
        auto created = std::make_unique<std::list<SferaMbcRegionPacket>>();
        created->push_back(std::move(packet));
        queue = std::move(created);
        return;
    }
    const auto position = ordered ? std::find_if(queue->begin(), queue->end(), [&](const auto& existing) {
        return SferaNetworkRuntime::tickDifference(timestamp, existing.timestamp) < 0;
    }) : queue->end();
    queue->insert(position, std::move(packet));
}

void SferaNetworkRuntime::receiveEvents(std::span<const std::uint8_t> payload) {
    if (payload.empty()) return;
    auto& runtime = g_sfera_mbc_runtime;
    SferaMbcBitStream stream(payload);
    int origin[3]{};
    if (stream.read(1) != 0) { origin[0] = static_cast<int>(stream.read(16)) - 32768; origin[1] = static_cast<int>(stream.read(13)) - 1200; origin[2] = static_cast<int>(stream.read(16)) - 32768; }
    const auto timestamp = stream.read(15);
    while (stream.valid()) {
        const auto processId = stream.read(18);
        const auto moduleTag = stream.read(12);
        if (!stream.valid()) return;
        auto* process = runtime.findProcess(processId);
        if (moduleTag == 0) {
            if (process != nullptr) {
                runtime.active_process = process;
                if (!process->activateProgram("EKill")) { process->flags |= 4; process->programs_queued = true; runtime.enqueueProcess(static_cast<int>(processId), *process); }
                process->flags |= SferaMbcProcessRecord::markedForUnload;
            }
            const auto next = stream.read(7);
            if (!stream.valid() || next == 0) return;
            if (next == 63) continue;
        }
        if (processId >= std::size(runtime.processes) || moduleTag >= std::size(g_sfera_mbc_runtime.modules)) return;
        if (process == nullptr) {
            process = &runtime.processes[processId];
            if (process->process_id != processId) {
                const auto loaded = runtime.loadProcess(g_sfera_mbc_runtime.modules[moduleTag].name, processId);
                process = runtime.findProcess(loaded);
                if (process == nullptr) return;
            }
            process->flags |= 4;
            process->programs_queued = true;
            runtime.enqueueProcess(static_cast<int>(processId), *process);
        }
        runtime.active_process = process;
        while (stream.valid()) {
            const auto command = stream.read(7);
            if (!stream.valid() || command == 0) return;
            if (command == 63) break;
            const auto regionIndex = command - 1;
            if (regionIndex > 61) { if (process->flags & SferaMbcProcessRecord::unloadAfterExecution) runtime.unloadProcess(processId); return; }
            if (regionIndex == 0 || regionIndex == 61) {
                if (process->chain_prev_index == -1 || (process->flags & SferaMbcProcessRecord::markedForUnload)) {
                    if (process->chain_prev_index != -1) runtime.unloadProcess(processId);
                    if (runtime.loadProcess(g_sfera_mbc_runtime.modules[moduleTag].name, processId) == UINT32_MAX) return;
                }
                process->flags &= ~4u;
                process->programs_queued = true;
                runtime.enqueueProcess(static_cast<int>(processId), *process);
            }
            if (process->regions.empty()) return;
            const auto& region = process->regions[regionIndex];
            if (region.program_index != UINT16_MAX) process->activateProgram(region.program_index);
            if (region.field_count < 0) { if (process->flags & SferaMbcProcessRecord::unloadAfterExecution) runtime.unloadProcess(processId); return; }
            const auto firstBit = stream.position();
            if (!stream.skipRegion(region)) return;
            if (process->flags & SferaMbcProcessRecord::unloadAfterExecution) continue;
            if ((region.flags & 1) == 0 && static_cast<int>(process->region_timestamps[regionIndex]) >= 0 && tickDifference(timestamp, process->region_timestamps[regionIndex]) < 0) continue;
            process->queueRegion(regionIndex, timestamp, origin, payload, firstBit, stream.position() - firstBit, true);
        }
    }
}

void SferaNetworkRuntime::receiveMessage(std::span<const std::uint8_t> message) {
    if (message.size() <= 1u || message.size() > 400u) return;
    receiveEvents(message.subspan(1));
}

void SferaNetworkRuntime::receiveMessages() {
    if (initialization_result != 1u) return;
    // Do not hold a transport lock while scripts run: callbacks may reconnect.
    for (;;) {
        std::vector<std::uint8_t> message;
        {
            std::lock_guard lock(receive_mutex);
            if (messages.empty()) break;
            message = std::move(messages.front());
            messages.pop_front();
        }
        receiveMessage(message);
        if (initialization_result != 1u) break;
    }
}

bool SferaTcpConnectionContext::WinsockSession::start() noexcept {
    if (active) return true;
    WSADATA data{};
    active = ::WSAStartup(MAKEWORD(2, 1), &data) == 0;
    return active;
}
void SferaTcpConnectionContext::WinsockSession::reset() noexcept {
    if (std::exchange(active, false)) ::WSACleanup();
}
void SferaTcpConnectionContext::Socket::reset(SOCKET replacement) noexcept {
    const auto old = std::exchange(value, replacement);
    if (old != INVALID_SOCKET) ::closesocket(old);
}

SferaTcpConnectionContext::SferaTcpConnectionContext(SferaNetworkRuntime& owner) noexcept : owner_(owner) {}
SferaTcpConnectionContext::~SferaTcpConnectionContext() { shutdown(); }

void SferaTcpConnectionContext::shutdown() noexcept {
    connected_ = false;
    for (auto& worker : workers_) worker.request_stop();
    receive_ready_.notify_all();
    // Socket is nonblocking, select has a finite timeout, and no queue lock is
    // held during join. Never close a SOCKET still being used by another thread.
    for (auto& worker : workers_) if (worker.joinable()) worker.join();
    if (socket_.value != INVALID_SOCKET) ::shutdown(socket_.value, SD_BOTH);
    socket_.reset();
    winsock_.reset();
    outgoing_.clear(); outgoing_offset_ = outgoing_bytes_ = 0;
    incoming_.clear(); incoming_bytes_ = 0;
    sequence_ = checksum_seed_ = 0; packet_counter_ = 0;
    handshake_complete_ = false;
    { std::lock_guard lock(statistics_mutex_); statistics_ = {}; received_bytes_window_ = sent_bytes_window_ = 0; }
    keepalive_started_at_ = 0; keepalive_answered_ = false;
}

int SferaTcpConnectionContext::initialize(const char* hostname, std::uint16_t port) {
    shutdown();
    if (hostname == nullptr || *hostname == '\0' || !winsock_.start()) return -1;
    try {
        socket_.reset(::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP));
        if (socket_.value == INVALID_SOCKET) { shutdown(); return -1; }
        const int no_delay = 1;
        (void)::setsockopt(socket_.value, IPPROTO_TCP, TCP_NODELAY,
            reinterpret_cast<const char*>(&no_delay), sizeof(no_delay));
        addrinfo hints{};
        hints.ai_family = AF_INET; hints.ai_socktype = SOCK_STREAM; hints.ai_protocol = IPPROTO_TCP;
        addrinfo* raw = nullptr;
        const auto status = ::getaddrinfo(hostname, nullptr, &hints, &raw);
        std::unique_ptr<addrinfo, decltype(&::freeaddrinfo)> resolved(raw, &::freeaddrinfo);
        if (status != 0 || !resolved) { shutdown(); return -1; }
        auto address = *reinterpret_cast<const sockaddr_in*>(resolved->ai_addr);
        address.sin_port = ::htons(port);
        // Bounded connect, then all worker send/recv calls remain nonblocking.
        u_long nonblocking = 1;
        if (::ioctlsocket(socket_.value, FIONBIO, &nonblocking) != 0) { shutdown(); return -1; }
        if (::connect(socket_.value, reinterpret_cast<const sockaddr*>(&address), sizeof(address)) != 0) {
            if (::WSAGetLastError() != WSAEWOULDBLOCK) { shutdown(); return -1; }
            fd_set writable{}, failed{};
            FD_SET(socket_.value, &writable); FD_SET(socket_.value, &failed);
            timeval timeout{15, 0};
            if (::select(0, nullptr, &writable, &failed, &timeout) <= 0 || FD_ISSET(socket_.value, &failed)) { shutdown(); return -1; }
            int error = 0, size = sizeof(error);
            if (::getsockopt(socket_.value, SOL_SOCKET, SO_ERROR, reinterpret_cast<char*>(&error), &size) != 0 || error != 0) { shutdown(); return -1; }
        }
        connected_ = true;
        workers_[0] = std::jthread([this](std::stop_token stop) { receive(stop); });
        workers_[1] = std::jthread([this](std::stop_token stop) { maintain(stop); });
        workers_[2] = std::jthread([this](std::stop_token stop) { dispatch(stop); });
        return 0;
    } catch (...) { shutdown(); return -1; }
}

SferaNetworkRuntime::~SferaNetworkRuntime() { connection.reset(); }

int SferaNetworkRuntime::initialize(const char* hostname, std::uint32_t mode) {
    if (connection_lost) shutdown();
    const auto result = initialization_result.load();
    if (std::bit_cast<std::int32_t>(result) >= 0) return static_cast<int>(result);
    if (hostname == nullptr) return 0;
    shutdown();
    client_mode = mode;
    connection_lost = false;
    sent_bytes = 0; received_bytes = 0;
    connection_info = {};
    { std::lock_guard lock(receive_mutex); dropped_messages = 0; }
    initialization_result = 0;
    try { connection = std::make_unique<SferaTcpConnectionContext>(*this); }
    catch (...) { initialization_result = UINT32_MAX; return 0; }
    if (connection->initialize(hostname, static_cast<std::uint16_t>(server_port)) != 0) {
        connection.reset();
        initialization_result = UINT32_MAX;
        g_sfera_log_runtime.write("Network initialize error! \n\n");
        return 0;
    }
    return 1;
}

void SferaNetworkRuntime::shutdown() {
    connection.reset(); // stops and joins workers before queue storage is changed
    { std::lock_guard lock(receive_mutex); messages.clear(); }
    initialization_result = UINT32_MAX;
    connection_slot = UINT32_MAX;
    connection_info = {};
    reset_pending_network_regions();
}

std::uint32_t SferaGameCalendar::fromUnixTime(std::int64_t timestamp) {
    using namespace std::chrono;
    constexpr auto unixEpoch = sys_days{year{1970} / January / 1};
    constexpr auto calendarEpoch = sys_days{year{1349} / January / 1};
    constexpr auto epochOffset = duration_cast<seconds>(unixEpoch - calendarEpoch).count();
    constexpr std::int64_t quartersPerRealMinute = 48;
    constexpr std::uint32_t epochYear = 8192;
    const auto total = (timestamp + epochOffset) * quartersPerRealMinute / 60;
    const auto elapsedYears = total / quartersPerYear;
    const auto day = total % quartersPerYear / quartersPerDay;
    const auto time = total % quartersPerDay;
    std::uint32_t month = 1;
    while (month < 12 && day >= daysBeforeMonth(month + 1)) ++month;
    const std::uint32_t date = day - daysBeforeMonth(month) + 1;
    return pack(epochYear + static_cast<std::uint32_t>(elapsedYears), month, date, static_cast<std::uint32_t>(time / quartersPerHour), static_cast<std::uint32_t>(time % quartersPerHour / quartersPerMinute), static_cast<std::uint32_t>(time % quartersPerMinute));
}

std::int64_t SferaMbcValue::truncateReal(double number) {
    return number >= -9223372036854775808.0 && number < 9223372036854775808.0 ? static_cast<std::int64_t>(number) : INT64_MIN;
}

std::uint32_t SferaGameCalendar::component(std::uint32_t calendar, int index) {
    const auto& part = field(index);
    return ((calendar >> part.shift) & part.mask()) + part.bias;
}

std::uint32_t SferaGameCalendar::withComponent(std::uint32_t calendar, int index, std::uint32_t value) {
    const auto& part = field(index);
    return (calendar & ~(part.mask() << part.shift)) | (((value - part.bias) & part.mask()) << part.shift);
}

std::uint32_t SferaGameCalendar::advance(std::uint32_t calendar) {
    const auto quarter = component(calendar, Quarter); calendar = withComponent(calendar, Quarter, quarter + 1);
    if (quarter != 3) return calendar;
    calendar = withComponent(calendar, Minute, component(calendar, Minute) + 1);
    if (component(calendar, Minute) != 60) return calendar;
    calendar = withComponent(calendar, Minute, 0); calendar = withComponent(calendar, Hour, component(calendar, Hour) + 1);
    if (component(calendar, Hour) != 24) return calendar;
    calendar = withComponent(calendar, Hour, 0);
    const auto day = component(calendar, Day), month = component(calendar, Month);
    calendar = withComponent(calendar, Day, day + 1);
    if (day < SferaGameCalendar::daysInMonth(month)) return calendar;
    calendar = withComponent(calendar, Day, 1); calendar = withComponent(calendar, Month, month + 1);
    if (component(calendar, Month) <= 12) return calendar;
    calendar = withComponent(calendar, Month, 1);
    return withComponent(calendar, Year, component(calendar, Year) + 1);
}

int SferaFileManager::transformEnvelope(const char* destination, const char* source, bool compress) {
    struct ReportingScope {
        SferaFileManager& owner;
        bool previous;
        ~ReportingScope() { owner.setErrorReporting(previous); }
    } reporting{*this, setErrorReporting(false)};
    const auto transform = [&]() -> int {
        const auto length = fileSize(source); if (length < 0 || std::cmp_greater(length, std::numeric_limits<std::ptrdiff_t>::max())) return -1;
        std::vector<std::uint8_t> input(static_cast<std::size_t>(length));
        ScopedFile inputFile(*this, open(source, _O_RDONLY)); if (inputFile.get() < 0) return -1;
        struct _stat64i32 information{}; const bool haveTimes = ::_fstat64i32(inputFile.get(), &information) == 0;
        const auto received = read(inputFile.get(), input.data(), length); inputFile.close(); if (received != length) return -1;
        std::vector<std::uint8_t> transformed;
        std::span<const std::uint8_t> output = input;
        std::uint32_t size = 0;
        if (compress) {
            const auto capacity = static_cast<std::uint64_t>(input.size()) * 101 / 100 + 20;
            if (capacity > UINT32_MAX) return -1;
            size = capacity; transformed.resize(size);
            if (SferaZStream32::compressEnvelope(transformed.data(), size, input) != 0) return -1;
            output = std::span<const std::uint8_t>(transformed.data(), size);
        } else if (SferaZStream32::decompressEnvelope(nullptr, size, input) == 0) {
            if (size > UINT32_MAX - 100) return -1;
            transformed.resize(static_cast<std::size_t>(size) + 100);
            if (SferaZStream32::decompressEnvelope(transformed.data(), size, input) != 0) return -1;
            output = std::span<const std::uint8_t>(transformed.data(), size);
        }
        ::_chmod(destination, _S_IREAD | _S_IWRITE);
        ScopedFile outputFile(*this, create(destination)); if (outputFile.get() < 0) return -1;
        const auto written = write(outputFile.get(), output.data(), output.size());
        if (haveTimes) { __utimbuf64 times{information.st_mtime, information.st_mtime}; ::_futime64(outputFile.get(), &times); }
        const auto closed = outputFile.close();
        return written == std::ssize(output) && closed == 0 ? 0 : -1;
    };
    return transform();
}

std::string SferaMbcRuntime::formatArguments(const char* pattern, std::size_t limit) {
    using Argument = std::variant<int, double, const char*>;
    std::vector<Argument> arguments;
    while (argument_count > 0) {
        if (argument_cursor >= argument_end) { reportError("Too few parameters"); break; }
        const auto& argument = g_sfera_mbc_runtime.values[argument_cursor];
        if (argument.isPointer()) { arguments.emplace_back(argument.value.base == 0 ? nullptr : textAt(argument.value.base)); ++argument_cursor; }
        else if (argument.type == SferaMbcValue::Byte || argument.type == SferaMbcValue::Integer) arguments.emplace_back(nextInteger());
        else arguments.emplace_back(static_cast<double>(nextReal()));
        --argument_count;
    }
    ++value_stack_size;
    if (execution_failed || pattern == nullptr) return {};
    std::string result; std::size_t next = 0;
    const auto invalid = [&]() { reportError("Invalid format arguments"); };
    const auto word = [&]() -> std::uint32_t {
        if (next >= arguments.size()) { invalid(); return 0; }
        const auto& value = arguments[next++];
        if (const auto* integer = std::get_if<int>(&value)) return static_cast<std::uint32_t>(*integer);
        if (const auto* pointer = std::get_if<const char*>(&value)) return mapMemory(*pointer, 1);
        invalid(); return 0;
    };
    const auto pointer = [&]() -> const void* {
        if (next >= arguments.size()) { invalid(); return nullptr; }
        const auto& value = arguments[next++];
        if (const auto* text = std::get_if<const char*>(&value)) return *text;
        if (const auto* integer = std::get_if<int>(&value)) return *integer == 0 ? nullptr : memoryAt(static_cast<std::uint32_t>(*integer));
        invalid(); return nullptr;
    };
    const auto append = [&](const std::string& specifier, auto value) {
        const auto required = std::snprintf(nullptr, 0, specifier.c_str(), value);
        if (required < 0) { invalid(); return; }
        const auto count = std::min<std::size_t>(static_cast<std::size_t>(required), limit - result.size());
        if (count == 0) return;
        const auto offset = result.size(); result.resize(offset + count + 1);
        std::snprintf(result.data() + offset, count + 1, specifier.c_str(), value); result.resize(offset + count);
    };
    for (const char* cursor = pattern; *cursor != '\0' && !execution_failed;) {
        if (*cursor != '%') { if (result.size() < limit) result.push_back(*cursor); ++cursor; continue; }
        ++cursor;
        if (*cursor == '%') { if (result.size() < limit) result.push_back('%'); ++cursor; continue; }
        std::string specifier = "%";
        while (*cursor != '\0' && std::strchr("-+ #0", *cursor) != nullptr) specifier.push_back(*cursor++);
        if (*cursor == '*') {
            ++cursor; const int width = word(); if (width < 0) specifier.push_back('-');
            specifier += std::to_string(width < 0 ? -static_cast<std::int64_t>(width) : width);
        } else while (*cursor >= '0' && *cursor <= '9') specifier.push_back(*cursor++);
        if (*cursor == '.') {
            ++cursor;
            if (*cursor == '*') { ++cursor; const int precision = word(); if (precision >= 0) specifier += "." + std::to_string(precision); }
            else { specifier.push_back('.'); while (*cursor >= '0' && *cursor <= '9') specifier.push_back(*cursor++); }
        }
        std::string length;
        if (*cursor == 'h' || *cursor == 'l') { length.push_back(*cursor++); if (*cursor == length.front()) length.push_back(*cursor++); }
        else if (*cursor == 'I') { ++cursor; if (cursor[0] == '6' && cursor[1] == '4') { length = "ll"; cursor += 2; } else if (cursor[0] == '3' && cursor[1] == '2') cursor += 2; }
        else if (*cursor != '\0' && std::strchr("jztLw", *cursor) != nullptr) length.push_back(*cursor++);
        if (*cursor == '\0') { invalid(); break; }
        const auto conversion = *cursor++;
        if (std::strchr("diuoxX", conversion) != nullptr) {
            const bool wide = length == "ll" || length == "j";
            const auto low = word(); const auto bits = wide ? std::uint64_t(low) | (std::uint64_t(word()) << 32) : low;
            if (execution_failed) break;
            if (wide) { specifier += "ll"; specifier.push_back(conversion); if (conversion == 'd' || conversion == 'i') append(specifier, static_cast<long long>(std::bit_cast<std::int64_t>(bits))); else append(specifier, static_cast<unsigned long long>(bits)); }
            else { if (length == "h" || length == "hh") specifier += length; specifier.push_back(conversion); if (conversion == 'd' || conversion == 'i') append(specifier, static_cast<int>(low)); else append(specifier, low); }
        } else if (std::strchr("aAeEfFgG", conversion) != nullptr) {
            if (next >= arguments.size() || !std::holds_alternative<double>(arguments[next])) { invalid(); break; }
            specifier.push_back(conversion); append(specifier, std::get<double>(arguments[next++]));
        } else if (conversion == 's' || conversion == 'S') {
            const auto* string = static_cast<const char*>(pointer()); if (execution_failed) break;
            if (length == "l" || length == "w" || (conversion == 'S' && length != "h")) { specifier += "ls"; append(specifier, reinterpret_cast<const wchar_t*>(string)); }
            else { specifier.push_back('s'); append(specifier, string); }
        } else if (conversion == 'c' || conversion == 'C') {
            if (length == "l" || length == "w" || (conversion == 'C' && length != "h")) specifier.push_back('l');
            specifier.push_back('c'); const auto character = word(); if (!execution_failed) append(specifier, character);
        } else if (conversion == 'p') { specifier.push_back('p'); const auto* address = pointer(); if (!execution_failed) append(specifier, address); }
        else invalid();
    }
    return result;
}

void SferaMbcRuntime::formatText(bool bounded) {
    const std::uint32_t required = bounded ? 3 : 2;
    if (argument_count < static_cast<int>(required)) { reportError(bounded ? "Wrong number of parameters: ffsnprintf" : "Wrong number of parameters: ffsprintf"); return; }
    const std::uint32_t destination = nextInteger(); const auto capacity = bounded ? static_cast<std::uint32_t>(nextInteger()) : UINT32_MAX; const auto pattern = nextInteger();
    if (execution_failed) return;
    argument_count -= required;
    const auto value = formatArguments(textAt(pattern), capacity == 0 ? 0 : capacity - 1);
    if (execution_failed || capacity == 0) return;
    auto* output = textAt(destination);
    std::copy_n(value.c_str(), value.size() + 1, output);
    if (bounded) output[capacity - 1] = '\0';
}

void SferaMbcRuntime::writeFormattedLog(bool named) {
    if (argument_count >= 1 && argument_cursor < argument_end) {
        const auto type = g_sfera_mbc_runtime.values[argument_cursor].type;
        if (type == SferaMbcValue::Byte || type == SferaMbcValue::Integer) { nextInteger(); --argument_count; }
    }
    if (argument_count < (named ? 2 : 1)) { reportError(named ? "Invalid parameter list: ffflogf()" : "Invalid parameter list: fflogf()"); return; }
    if (named) {
        const auto filename = nextInteger();
        --argument_count;
        if (!execution_failed) (void)textAt(filename);
    }
    const auto patternOffset = nextInteger();
    --argument_count;
    const auto* pattern = textAt(patternOffset);
    if (execution_failed) return;
    (void)formatArguments(pattern, named ? std::numeric_limits<std::size_t>::max() : 4095u);
}

void SferaMbcRuntime::systemCommand() {
    const auto operation = nextInteger();
    const auto address = [this](const char* name) { const std::uint32_t offset = nextInteger(); if (offset == 0) ::OutputDebugStringA((std::string("NULL-pointer dereferencing: ffsys, ") + name + "\n").c_str()); return offset; };
    const auto text = [this](std::uint32_t offset) { return textAt(offset); };
    const auto selectedObject = [this]() -> WorldObject* { const auto handle = nextInteger(); if (handle < 0) return nullptr; auto* object = g_sfera_world_objects.object(handle, "GetObjectPointer"); g_sfera_mbc_runtime.current_object = object; if (object == nullptr) active_tag = UINT32_MAX; return object; };
    switch (operation) {
        case 0: {
            const auto handle = nextInteger(); const auto destination = argument_count == 3 ? address("G_GROUND") : 0;
            if (execution_failed) return;
            std::uint32_t surface = 0; pushInteger(g_sfera_motion.surfaceInteraction(handle, &surface));
            if (static_cast<int>(destination) > 0) writeMemory(destination, surface);
            return;
        }
        case 1: case 3: case 38: {
            auto* object = selectedObject(); if (object == nullptr) return;
            const bool enabled = nextInteger() != 0; if (execution_failed) return;
            if (operation == 38) object->visible = enabled;
            else { auto* extended = SphereRender::CharacterModels::checkedExtended(object); if (operation == 1) extended->simulation_enabled = enabled; else extended->gravity_enabled = enabled; }
            return;
        }
        case 2: g_sfera_graphics_runtime.environment_factor = nextReal(); return;
        case 4: g_sfera_world_objects.controlled_object_handle = nextInteger(); if (execution_failed) g_sfera_world_objects.controlled_object_handle = UINT32_MAX; return;
        case 5: g_sfera_mbc_runtime.game_calendar = nextInteger(); return;
        case 6: pushInteger(g_sfera_mbc_runtime.game_calendar); return;
        case 7: {
            float fraction = 0;
            if (argument_count > 1) { const float numerator = nextInteger(); const auto denominator = nextInteger(); fraction = static_cast<double>(numerator) / denominator; }
            const auto calendar = g_sfera_mbc_runtime.game_calendar;
            const auto ticks = (((calendar >> 8) & 31) * 60 + ((calendar >> 2) & 63)) * 4 + (calendar & 3);
            const float factor = 0.9994999766349792 - (static_cast<double>(ticks) + fraction) / 5760.0;
            g_sfera_graphics_runtime.environment_factor = factor < 0 ? 0 : factor;
            return;
        }
        case 8: g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::advance(g_sfera_mbc_runtime.game_calendar); return;
        case 9: pushInteger(SferaGameCalendar::component(g_sfera_mbc_runtime.game_calendar, nextInteger())); return;
        case 10: if (selectedObject() != nullptr) { nextInteger(); nextInteger(); nextInteger(); } return;
        case 11: { const auto value = nextInteger(); if (value < 0) pushInteger(g_sfera_direct_input_runtime.text_filter); else g_sfera_direct_input_runtime.text_filter = value; return; }
        case 12: { const auto destination = address("G_ERRMSG"); if (!execution_failed) std::copy_n(diagnostic_context, std::strlen(diagnostic_context) + 1, text(destination)); return; }
        case 14: pushInteger(g_sfera_direct_input_runtime.text_filter == 0 && g_sfera_direct_input_runtime.binding_capture == 0 && !g_sfera_interface.options.binding_dialog_open); return;
        case 18: {
            const auto object = nextInteger(); const auto handle = nextInteger(); if (execution_failed) return;
            auto* control = WorldGuiControls::control(handle);
            if (!control) { reportError("Wrong GUI control handle"); return; }
            control->objectHandle = object;
            if (argument_count >= 4) control->height_factor = nextReal();
            if (argument_count == 5) nextInteger();
            return;
        }
        case 19: case 20: {
            const auto patternOrHandle = nextInteger(); const auto destination = address(operation == 19 ? "FINDFIRST" : "FINDNEXT"); if (execution_failed) return;
            const auto result = operation == 19 ? ::_findfirst64i32(text(patternOrHandle), &script_find_data) : ::_findnext64i32(nativeResource<std::intptr_t>(static_cast<std::uint32_t>(patternOrHandle)), &script_find_data);
            std::uint32_t value = UINT32_MAX;
            if (result != -1) {
                if (operation == 19) {
                    try {
                        value = nativeHandle(static_cast<std::intptr_t>(result));
                        active_process->registerResource(value, ResourceKind::fileSearch);
                    } catch (...) {
                        forgetNativeResource(static_cast<std::intptr_t>(result));
                        ::_findclose(result);
                        throw;
                    }
                } else value = static_cast<std::uint32_t>(result);
                std::copy_n(script_find_data.name, std::strlen(script_find_data.name) + 1, text(destination));
            } else *text(destination) = '\0';
            pushInteger(value); return;
        }
        case 21: { const auto handle = nextInteger(); if (!execution_failed) { const auto search = nativeResource<std::intptr_t>(static_cast<std::uint32_t>(handle)); if (search != -1) { ::_findclose(search); forgetNativeResource(search); } active_process->unregisterResource(handle, ResourceKind::fileSearch); } return; }
        case 22: instruction_step_count = 0; return;
        case 23: nextInteger(); return;
        case 24: pushInteger(g_sfera_network_runtime.connection_info.round_trip_latency_ms); return;
        case 25: pushInteger(g_sfera_network_runtime.connection_info.throughputBytesPerSecond()); return;
        case 26: pushInteger(g_sfera_network_runtime.connection_info.sent_bytes_per_second); return;
        case 27: pushInteger(g_sfera_network_runtime.connection_info.received_bytes_per_second); return;
        case 28: pushInteger(0u); return;
        case 29: {
            const auto index = nextInteger(); auto* process = findProcess(index); const auto object = nextInteger(); if (execution_failed) return;
            if (process == nullptr) { if (object > 0) g_sfera_world_objects.addExtended(object); pushInteger(UINT32_MAX); }
            else if (process->field_084 == 0) pushInteger(UINT32_MAX);
            else { if (object > 0) g_sfera_world_objects.removeExtended(object); pushInteger(0); }
            return;
        }
        case 32: { const auto object = nextInteger(); const auto distance = nextInteger(); float value = 0; const auto handle = g_sfera_motion.pick(&value, nullptr); if (object) writeMemory(object, handle); if (distance) writeMemory(distance, value); return; }
        case 33: {
            const auto x = address("G_MOUSEXY, 1"); const auto y = address("G_MOUSEXY, 2"); if (execution_failed) return;
            SferaCursorPosition position{}; CCursorManager::instance().activeCursor()->getPosition(&position); writeMemory(x, static_cast<float>(position.x)); writeMemory(y, static_cast<float>(position.y)); return;
        }
        case 34: case 37: pushInteger(g_sfera_direct_input_runtime.mouse.buttons & (operation == 34 ? 1 : 2)); return;
        case 35: { const auto cursor = nextInteger(); const auto mask = nextInteger(); if (execution_failed) return; if (cursor) SferaText::copyString(g_sfera_interface.default_cursor_name, text(cursor), sizeof(g_sfera_interface.default_cursor_name)); SphereRender::SceneRenderer::visible_character_parts = mask; return; }
        case 36: { const auto destination = address("G_CURSDIR"); if (execution_failed) return; float distance = 0; SferaVec3F direction{}; g_sfera_motion.pick(&distance, &direction); writeMemory(destination, direction); return; }
        case 39: { const float x = nextReal(); const float y = nextReal(); if (!execution_failed) CCursorManager::instance().activeCursor()->setPosition(static_cast<int>(x), static_cast<int>(y)); return; }
        case 41: { const auto value = nextInteger(); if (!execution_failed) g_sfera_motion.orientation_blocked = value; return; }
        case 43: {
            auto* process = argument_count == 3 ? findProcess(nextInteger()) : active_process;
            const auto index = nextInteger();
            if (execution_failed) return;
            pushInteger(process != nullptr && index == -1 ? 0u : UINT32_MAX);
            return; // No subscriber producer; preserve both arities and invalid-process result.
        }
        case 44: {
            const int handle = g_sfera_world_objects.controlled_object_handle; if (handle < 0) { pushInteger(0); return; }
            auto* object = g_sfera_world_objects.object(handle, "GetObjectPointer"); g_sfera_mbc_runtime.current_object = object;
            pushInteger(object != nullptr && SphereRender::CharacterModels::checkedExtended(object)->steep_slope == 1); return;
        }
        case 45: { const auto handle = nextInteger(); const auto model = address("LINK_ON"); const auto slot = nextInteger(); if (!execution_failed) g_sfera_world_objects.linkModel(handle, text(model), slot); return; }
        case 46: { const auto handle = nextInteger(); const auto slot = nextInteger(); if (!execution_failed) g_sfera_world_objects.unlink(handle, slot); return; }
        case 47: { const auto value = nextInteger(); if (!execution_failed) g_sfera_motion.control_mode = value; return; }
        case 53: pushInteger(WorldClock::calendarTicks()); return;
        case 57: {
            const auto component = nextInteger(); const auto timestamp = ::_time64(nullptr); tm local{}; ::_localtime64_s(&local, &timestamp);
            switch (component) {
                case 0: pushInteger(local.tm_hour); return;
                case 1: pushInteger(local.tm_mday); return;
                case 2: pushInteger(local.tm_mon); return;
                case 3: pushInteger(local.tm_year); return;
                case 4: pushInteger(local.tm_wday); return;
                case 5: pushInteger(local.tm_min); return;
                case 7: pushInteger(static_cast<std::uint32_t>(WorldClock::nowTicks())); return;
                case 8: { auto* value = reinterpret_cast<tm*>(nextText()); if (value != nullptr) pushInteger(static_cast<std::uint32_t>(::_mktime64(value))); return; }
                case 9: { const auto first = static_cast<__time64_t>(nextInteger()); const auto second = static_cast<__time64_t>(nextInteger()); pushInteger(static_cast<int>(::_difftime64(first, second))); return; }
                default: pushInteger(static_cast<std::uint32_t>(timestamp)); return;
            }
        }
        case 58: { const auto component = nextInteger(); const auto value = nextInteger(); if (!execution_failed) g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::withComponent(g_sfera_mbc_runtime.game_calendar, component, value); return; }
        case 59: { const auto value = nextInteger(); if (!execution_failed) g_sfera_camera.controlled_observer_mode = value; return; }
        case 60: pushInteger(SferaClientApplication::server_number); return;
        case 61: active_process->flags |= SferaMbcProcessRecord::markedForUnload; return;
        case 63: nextInteger(); nextReal(); return;
        case 64: { const auto track = address("PLAY_MUSIC"); if (!execution_failed) g_sfera_sound_runtime.requestTrack(track != 0 && *text(track) != '\0' ? text(track) : nullptr); return; }
        case 65: g_sfera_world_objects.contours->rebuildServerWall(); return;
        case 66: case 67: { const auto destination = address(operation == 66 ? "GZ_PACK, 1" : "GZ_UNPACK, 1"); const auto source = address(operation == 66 ? "GZ_PACK, 2" : "GZ_UNPACK, 2"); if (!execution_failed) pushInteger(g_sfera_files.transformEnvelope(text(destination), text(source), operation == 66)); return; }
        case 68: case 69: nextInteger(); return;
        case 70: { nextInteger(); const auto x = nextInteger(); const auto y = nextInteger(); if (!execution_failed) { if (x != 0) writeMemory(x, std::uint8_t{}); if (y != 0) writeMemory(y, std::uint8_t{}); } return; }
        case 71: nextInteger(); nextInteger(); return;
        case 72: nextInteger(); nextInteger(); return;
        case 73: if (argument_count > 1) { nextInteger(); pushInteger(SferaClientApplication::resources_loaded); } else SferaClientApplication::loadResources(); return;
        case 74: nextInteger(); nextInteger(); nextInteger(); return;
        case 75: {
            const auto detail = nextInteger(); const auto handle = g_sfera_world_objects.controlled_object_handle; if (static_cast<int>(handle) <= 0) return;
            if (detail != 0) { auto* effect = g_sfera_effect_manager.createActiveEffect(300, handle); g_sfera_effect_manager.pending_effect = effect; }
            else if (g_sfera_effect_manager.pending_effect != nullptr) { g_sfera_effect_manager.removeActiveEffect(g_sfera_effect_manager.pending_effect); g_sfera_effect_manager.pending_effect = nullptr; }
            return;
        }
        case 77: ::Sleep(nextInteger()); return;
        case 78: { auto* object = selectedObject(); if (object == nullptr) return; const float scale = nextReal(); if (!execution_failed) SphereRender::CharacterModels::checkedExtended(object)->scale = scale; return; }
        case 79: nextInteger(); nextInteger(); return;
        case 80: {
            const auto handle = nextInteger(); if (handle < 0) { pushInteger(UINT32_MAX); return; } if (execution_failed) return;
            auto variant = nextInteger();
            if (argument_count != 3) { const auto second = nextInteger(); const auto third = nextInteger(); if (execution_failed) return; variant = SphereRender::SceneRenderer::materialVariant(variant, second, third); }
            if (!SphereRender::SceneRenderer::hasMaterialVariant(handle, variant)) { pushInteger(UINT32_MAX); return; }
            SphereRender::SceneRenderer::setMaterialVariant(handle, variant); pushInteger(0); return;
        }
        case 81: { const float x = nextReal(); const float y = nextReal(); const auto first = nextInteger(); const auto last = nextInteger(); pushInteger(g_sfera_world_objects.contours->typeAt(x, y, first, last)); return; }
        case 82: nextInteger(); return;
        case 83: nextInteger(); nextInteger(); nextInteger(); if (!execution_failed) pushInteger(UINT32_MAX); return;
        case 84: { auto* object = selectedObject(); if (object != nullptr && !execution_failed) pushInteger(object->spatial_membership); return; }
        case 85: {
            nextInteger(); nextInteger(); nextInteger();
            if (!execution_failed) pushInteger(0);
            return;
        }
        case 86: pushInteger(101); return;
        case 87: { const auto server = nextInteger(); const float x = nextReal(); const float y = nextReal(); if (!execution_failed) pushInteger(g_sfera_world_objects.contours->nearServer(x, y, server)); return; }
        case 88: { const float x = nextReal(); const float y = nextReal(); if (!execution_failed) pushInteger(g_sfera_world_objects.contours->serverAt(x, y)); return; }
        case 89: { const auto ids = nextInteger(); const auto types = nextInteger(); const auto count = nextInteger(); g_sfera_world_objects.contours->setServerMap(reinterpret_cast<const int*>(text(ids)), reinterpret_cast<const int*>(text(types)), count); return; }
        case 92:
            reloadQuickFiles();
            return;
        case 93: nextInteger(); return;
        case 94: {
            const float first = nextReal(); const float second = nextReal(); if (execution_failed) return;
            constexpr std::array<float, 6> boundaries{-742, -492, -242, 7, 257, 507};
            pushInteger(std::fabs(first - second) <= 70 && std::any_of(boundaries.begin(), boundaries.end(), [first, second](float value) { return second < value && value < first; })); return;
        }
        case 95: nextReal(); nextReal(); if (!execution_failed) pushInteger(0); return;
        case 96: { const auto handle = nextInteger(); const float heading = nextReal(); if (!execution_failed) g_sfera_world_objects.approachHeading(handle, heading); return; }
        case 98: {
            auto* models = SphereRender::SceneRenderer::characters.get(); if (models == nullptr) return;
            const auto handle = nextInteger(); SphereRender::CharacterAppearance appearance{}; appearance.sex = nextInteger();
            std::array<std::uint8_t, 4> values{}; for (auto& value : values) value = nextInteger(); if (execution_failed) return;
            for (const auto index : {0, 1, 2, 4, 5, 6}) appearance.parts[index] = '0';
            appearance.parts[7] = values[0] ? values[0] : '0'; appearance.parts[9] = values[1] ? values[1] : '1'; appearance.parts[10] = values[2] ? values[2] : '0'; appearance.parts[8] = values[3] ? values[3] : '0';
            models->setAppearance(handle, appearance); return;
        }
        case 99: {
            auto* models = SphereRender::SceneRenderer::characters.get(); if (models == nullptr) return;
            const auto handle = nextInteger(); std::array<int, 9> values{}; for (auto& value : values) value = nextInteger(); if (execution_failed) return;
            SphereRender::CharacterAppearance appearance{}; if (!models->getAppearance(handle, appearance)) return;
            if (values[0] > 0) appearance.parts[0] = values[0]; if (values[1] > 0) appearance.parts[1] = values[1];
            if (values[2] == 0 && values[3] == 0) values[2] = '0';
            if (values[2] == 0 || values[2] >= '0') appearance.parts[2] = values[2];
            if (values[3] == 0 || values[3] >= '0') appearance.parts[3] = values[3];
            if (values[4] > 0) appearance.parts[6] = values[4];
            appearance.parts[12] = values[5]; appearance.parts[11] = values[8];
            if (values[6] > 0) appearance.parts[4] = values[6]; if (values[7] > 0) appearance.parts[5] = values[7];
            models->setAppearance(handle, appearance); return;
        }
        case 100: { if (SphereRender::SceneRenderer::characters == nullptr) { pushInteger(0); return; } const auto sex = nextInteger(); const auto part = nextInteger(); if (!execution_failed) pushInteger(part == 0 || part == 1 ? SphereRender::CharacterModels::textureVariants(sex != 0, part == 0 ? 'f' : 'r') : part == 2 || part == 3 ? 4 : 0); return; }
        case 103: { const auto destination = address("G_VERSION"); if (!execution_failed) writeMemory(destination, std::uint32_t{3}); return; }
        case 106: { nextSlice(); nextInteger(); nextInteger(); return; }
        case 107: { const auto enabled = nextInteger() != 0; if (!execution_failed) SphereRender::SceneRenderer::use_default_environment = enabled; return; }
        case 109: nextInteger(); nextInteger(); return;
        case 110: {
            nextInteger();
            const auto count_address = nextInteger();
            nextInteger();
            const auto status_address = nextInteger();
            if (execution_failed) return;
            if (count_address != 0) writeMemory(count_address, int{0});
            if (status_address != 0) writeMemory(status_address, int{1});
            return;
        }
        case 111: return;
        case 112: pushInteger(1); return;
        case 113: { const auto variable = nextInteger(); const auto destination = nextInteger(); if (execution_failed) return; char* value = nullptr; std::size_t length = 0; if (::_dupenv_s(&value, &length, text(variable)) == 0 && value != nullptr) { std::copy_n(value, length, text(destination)); std::free(value); } else *text(destination) = '\0'; return; }
        case 114: pushInteger(0); return;
        case 115: { const auto name = nextInteger(); if (!execution_failed) pushInteger(g_sfera_textures.find(text(name)) != 0); return; }
        case 116: { const auto name = nextInteger(); if (execution_failed) return; const auto definition = g_sfera_effect_manager.findDefinitionId(text(name)); pushInteger(definition == UINT32_MAX ? 0 : definition); return; }
        case 119: { const auto handle = nextInteger(); auto* object = g_sfera_world_objects.object(handle, "GetObjectPointer"); g_sfera_mbc_runtime.current_object = object; pushInteger(object == nullptr ? UINT32_MAX : 0); return; }
        case 120: { nextInteger(); const std::uint32_t effect = nextInteger(); if (!execution_failed) g_sfera_effect_manager.removeActiveEffect(nativeResource<SferaActiveEffect*>(effect)); return; }
        case 121: { const auto source = nextInteger(); const auto destination = nextInteger(); if (!execution_failed) { writeMemory(destination, ::_atoi64(text(source))); pushInteger(0); } return; }
        case 122: { const auto source = nextInteger(); const auto destination = nextInteger(); if (!execution_failed) { const auto value = std::to_string(readMemory<std::uint64_t>(source)); std::copy_n(value.c_str(), value.size() + 1, text(destination)); pushInteger(0); } return; }
        case 123: case 124: case 127: {
            const auto destination = nextInteger(); const std::uint64_t operand = static_cast<std::int64_t>(nextInteger()); if (execution_failed) return;
            auto value = readMemory<std::uint64_t>(destination); value = operation == 123 ? value + operand : operation == 124 ? value - operand : value * operand; writeMemory(destination, value);
            pushInteger(operation == 127 ? static_cast<std::uint32_t>(value) : (value >> 63) != 0 ? static_cast<std::uint32_t>(-2) : 0); return;
        }
        case 125: case 128: {
            const auto firstAddress = nextInteger(); const auto argument = nextInteger(); if (execution_failed) return;
            const auto first = readMemory<std::int64_t>(firstAddress); const auto second = operation == 125 ? static_cast<std::int64_t>(argument) : readMemory<std::int64_t>(argument); pushInteger(first < second ? UINT32_MAX : first > second ? 1 : 0); return;
        }
        case 126: { const auto source = nextInteger(); const float multiplier = nextReal(); if (!execution_failed) pushInteger(readMemory<std::uint32_t>(source) * static_cast<std::uint32_t>(SferaMbcValue::truncateReal(multiplier))); return; }
        case 131: { const auto destination = nextInteger(); if (execution_failed) return; SYSTEMTIME time{}; ::GetLocalTime(&time); char date[32]{}; std::snprintf(date, sizeof(date), "%d-%02d-%02d %02d:%02d:%02d", time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond); std::copy_n(date, std::strlen(date) + 1, text(destination)); pushInteger(0); return; }
        case 132: nextInteger(); pushInteger(0); return;
        case 133: case 134: case 138: pushInteger(0); return;
        case 136: { const auto path = nextInteger(); if (execution_failed) return; _finddata64i32_t information{}; const auto handle = ::_findfirst64i32(text(path), &information); if (handle == -1) pushInteger(errno == ENOENT ? 0 : UINT32_MAX); else { ::_findclose(handle); pushInteger((information.attrib & _A_SUBDIR) != 0); } return; }
        case 140: { const auto name = address("SYS_SET_USER_NAME, 1"); SferaText::copyString(g_sfera_error_log_runtime.user_name, text(name), sizeof(g_sfera_error_log_runtime.user_name)); pushInteger(1); return; }
        case 150: { g_sfera_network_runtime.connection_lost = nextInteger() != 0; pushInteger(0); return; }
        case 152: g_sfera_interface.initializeResources(); return;
        case 206:
            pushInteger(0);
            return;
        case 207: pushInteger(0); return;
        case 212: pushInteger(g_sfera_interface.invite_messages); return;
        case 213: case 214: { auto* window = nativeResource<SphereUI::Window*>(static_cast<std::uint32_t>(nextInteger())); if (window != nullptr) { if (operation == 213) g_sfera_interface.raiseWindow(*window); else g_sfera_interface.lowerWindow(*window); } return; }
        case 215: nextInteger(); if (!execution_failed) pushInteger(0); return;
        case 216: nextInteger(); nextInteger(); if (!execution_failed) pushInteger(0); return;
        case 218: g_sfera_interface.saved_ui_enabled = g_sfera_interface.ui_enabled; g_sfera_interface.ui_enabled = false; return;
        case 219: { const auto message = nextInteger(); if (!execution_failed) pushInteger(g_sfera_interface.chat_filter->rejects(text(message))); return; }
        case 220: { const auto message = nextInteger(); if (!execution_failed) pushInteger(SphereUI::ChatFilter::invalidIdentifier(text(message))); return; }
        case 221: g_sfera_interface.ui_enabled = g_sfera_interface.saved_ui_enabled; return;
        case 224: { const auto handle = nextInteger(); if (handle < 0) return; auto* object = SphereRender::CharacterModels::checkedExtended(g_sfera_world_objects.object(handle, "GetObjectPointer")); if (object == nullptr) return; const SferaVec3F velocity{nextReal(), nextReal(), nextReal()}; if (!execution_failed) object->physical_velocity = velocity; return; }
        case 225: { const __time64_t timestamp = nextInteger(); auto* destination = nextText(); if (destination == nullptr) return; tm local{}; if (::_localtime64_s(&local, &timestamp) == 0) std::memcpy(destination, &local, sizeof(local)); return; }
        case 226: pushInteger(::GetTickCount()); return;
        case 227: {
            const auto x = nextInteger(); const auto y = nextInteger(); const auto z = nextInteger(); const auto result = nextInteger(); if (execution_failed) return;
            const double vx = readMemory<float>(x), vy = readMemory<float>(y), vz = readMemory<float>(z); float length = vx * vx + vy * vy + vz * vz;
            if (length > 0.00001) { length = std::sqrt(static_cast<double>(length)); writeMemory(x, static_cast<float>(static_cast<double>(readMemory<float>(x)) / length)); writeMemory(y, static_cast<float>(static_cast<double>(readMemory<float>(y)) / length)); writeMemory(z, static_cast<float>(static_cast<double>(readMemory<float>(z)) / length)); }
            writeMemory(result, length); pushInteger(0); return;
        }
        case 228: { copyText(nextSliceReference(), ""); pushInteger(0); return; }
        case 229: { const auto source = nextSliceReference(); const auto destination = nextSliceReference(); SferaText::encodeUri(text(destination.base), text(source.base), destination.end - destination.base); pushInteger(0); return; }
        case 230: return;
        case 231: if (!execution_failed) { pushInteger(g_sfera_motion.moved_since_query); g_sfera_motion.moved_since_query = 0; } return;
        case 508: {
            const auto processIndex = nextInteger(); const auto first = nextInteger(); const auto* pattern = nextText(); auto* output = nextText(true);
            if (processIndex < 0 || processIndex >= static_cast<int>(std::size(processes)) || processes[processIndex].functions.empty() || pattern == nullptr || first < 0) { pushInteger(UINT32_MAX); return; }
            const auto& process = processes[processIndex];
            for (std::uint32_t index = first; index < process.functions.size(); ++index) { const auto* name = process.functions[index].name; if (SferaText::matchesWildcard(name, pattern)) { if (output != nullptr) std::copy_n(name, std::strlen(name) + 1, output); pushInteger(index + 1); return; } }
            if (output != nullptr) *output = '\0'; pushInteger(UINT32_MAX); return;
        }
        case 509: g_sfera_network_runtime.connection_slot = nextInteger(); return;
        case 510: pushInteger(g_sfera_network_runtime.connection_slot); return;
        default: return;
    }
}

void SferaMbcRuntime::reloadQuickFiles() {
    auto replacement = std::make_unique<QuickFile>();
    replacement->initialize("mbc\\");
    quick_files = std::move(replacement);
}

void SferaMbcRuntime::shutdown() {
    final_shutdown = true;
    g_sfera_config_text_runtime.clear();
    dispatch_slot = UINT32_MAX;
    g_sfera_network_runtime.shutdown();
    for (std::uint32_t index = 0; index < std::size(processes); ++index)
        if (processes[index].chain_prev_index >= 0) unloadProcess(index);
    while (!containers.empty()) destroyContainer(containers.begin()->first);
    while (!dynamic_blocks.empty()) releaseDynamic(dynamic_blocks.begin()->first);
    mapped_memory.clear(); native_resources.clear(); native_resource_ids.clear();
    bytecode_cache.clear(); quick_files.reset(); named_vectors.clear();
    active_process = nullptr; active_program_record = nullptr;
    program_table_base = nullptr; process_memory_base = nullptr;
    bytecode_base = instruction_cursor = current_instruction_address = nullptr;
    process_chain_first = process_chain_last = execution_chain_head = execution_chain_tail = -1;
    execution_chain_count = execution_context_depth = value_stack_size = call_frame_depth = 0;
    g_sfera_mbc_runtime.dispatch_slot = UINT32_MAX;
}

void SferaMbcRuntime::initialize() {
    std::srand(::timeGetTime());
    g_sfera_player_lists.clear();
    shutdown();
    final_shutdown = false;
    reloadQuickFiles();
    next_native_handle = 1;
    process_search_cursor = 0;
    g_sfera_mbc_runtime.dispatch_slot = UINT32_MAX; g_sfera_mbc_runtime.simulation_tick = 0; g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::pack(7801, 1, 1, 8, 0);
    halt_state = SferaMbcRuntime::HaltState::Running; g_sfera_world_objects.controlled_object_handle = UINT32_MAX;
    g_sfera_config_text_runtime.clear(); g_sfera_direct_input_runtime.text_filter = 0;
    for (std::size_t index = 0; index < 400; ++index) g_sfera_mbc_runtime.world_slots[index].state = 4;
    g_sfera_mbc_runtime.active_world_slot = 400;
    auto& slot = g_sfera_mbc_runtime.world_slots[400]; slot.primary_state = UINT32_MAX; slot.state = 2; slot.object_handle = 1; slot.reliable_bit_count = 0; slot.unreliable_bit_count = 0;
    std::fill(std::begin(slot.reliable_payload), std::end(slot.reliable_payload), 0); std::fill(std::begin(slot.unreliable_payload), std::end(slot.unreliable_payload), 0); slot.reliable_process = UINT32_MAX; slot.unreliable_process = UINT32_MAX;
    for (auto& module : g_sfera_mbc_runtime.modules) module.name[0] = '\0';
    _finddata64i32_t file{}; const auto search = ::_findfirst64i32("mbc\\*.mbc", &file);
    if (search != -1) {
        do {
            if ((file.attrib & _A_SUBDIR) != 0) continue;
            const auto descriptor = g_sfera_files.open(file.name, _O_RDONLY); if (descriptor < 0) continue;
            std::uint32_t tag = UINT32_MAX; g_sfera_files.seek(descriptor, 20, SEEK_SET); const auto read = g_sfera_files.read(descriptor, &tag, sizeof(tag)); g_sfera_files.close(descriptor);
            if (read != sizeof(tag) || tag >= std::size(g_sfera_mbc_runtime.modules)) continue;
            if (tag == 0) ::OutputDebugStringA((std::string("Null tag ") + file.name).c_str());
            auto& name = g_sfera_mbc_runtime.modules[tag].name;
            SferaText::copyString(name, file.name, sizeof(name));
            auto* extension = std::strrchr(name, '.'); const auto* separator = std::strrchr(name, '\\'); if (extension != nullptr && (separator == nullptr || extension > separator)) *extension = '\0';
        } while (::_findnext64i32(search, &file) == 0);
        ::_findclose(search);
    }
    g_sfera_config_text_runtime.load("connectn.cfg");
    int port = 0; if (g_sfera_config_text_runtime.readInteger("PORT", port)) g_sfera_network_runtime.server_port = port;
    if (loadProcess("_main", 0) == UINT32_MAX) SferaClientApplication::terminateWithError("MBInter: Process '_main' not found");
    named_vectors.clear();
    g_sfera_effect_manager.pending_effect = nullptr; g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::fromUnixTime(::_time64(nullptr));
}

void SferaMbcRuntime::tick() {
    auto& log = g_sfera_log_runtime;
    if (static_cast<int>(dispatch_slot) >= 0) return;
    SferaRestore dispatchScope(dispatch_slot);
    ++g_sfera_mbc_runtime.simulation_tick;
    if (static_cast<int>(++g_sfera_network_runtime.statistics_poll_ticks) >= 192) {
        g_sfera_network_runtime.updateTcpStatistics();
        g_sfera_network_runtime.statistics_poll_ticks = 0;
    }
    if (halt_state != SferaMbcRuntime::HaltState::Running) {
        for (auto& process : processes) {
            if (process.chain_prev_index == -1) continue;
            active_process = &process; std::fill(std::begin(process.program_map_a), std::end(process.program_map_a), UINT16_MAX); std::fill(std::begin(process.program_map_b), std::end(process.program_map_b), UINT16_MAX); process.activateProgram("EPHalt");
        }
        halt_state = SferaMbcRuntime::HaltState::Dispatched;
    }
    const int simulationTick = g_sfera_mbc_runtime.simulation_tick;
    const std::size_t priorityLimit = simulationTick % 24 == 0 ? 2 : simulationTick % 8 == 0 ? 1 : 0;
    process_index = execution_chain_tail;
    while (process_index < std::size(processes) && processes[process_index].chain_prev_index >= 0) {
        g_sfera_mbc_runtime.dispatch_slot = process_index; active_process = &processes[process_index]; program_table_base = active_process->programs.data(); bytecode_base = active_process->codeData(); process_memory_base = active_process->memory.data(); execution_context_depth = 0; execution_failed = false;
        bool unload = false;
        for (std::size_t priority = 0; priority <= priorityLimit && !unload; ++priority) {
            program_index = static_cast<std::int16_t>(active_process->program_map_a[priority]);
            while (program_index >= 0) {
                active_program_record = &program_table_base[program_index]; const auto initialProgram = program_index;
                bool finishPriority = false;
                if (active_program_record->state > 0) {
                    value_stack_size = 0; call_frame_depth = 0; instruction_step_count = 0;
                    auto caller = program_index;
                    do { caller = program_table_base[caller].caller_program; } while (caller >= 0 && program_table_base[caller].state > 0);
                    const bool pausedCaller = caller >= 0 && program_table_base[caller].state == 0;
                    if (!pausedCaller) {
                        instruction_cursor = bytecode_base + (caller < 0 ? active_program_record->instruction_offset : active_program_record->stop_offset);
                        while (true) {
                            if (static_cast<int>(instruction_step_count++) > 3500000) {
                                WorldDiagnostics::scriptContext(); log.write("\n---exit_inter start---\nMBINTER MESSAGE:Endless cycle found\n"); log.write(diagnostic_context); log.write("---exit_inter end-----\n"); execution_failed = true;
                                if (process_index == 0) SferaClientApplication::terminateWithError(diagnostic_context);
                                processes[0].activateProgram("EError"); unload = true; break;
                            }
                            current_instruction_address = instruction_cursor; current_opcode = static_cast<Instruction>(*instruction_cursor);
                            if (current_opcode == Instruction::Yield) { ++instruction_cursor; break; }
                            if (current_opcode == Instruction::EndProgram) {
                                active_program_record->callDepth = 0; active_program_record->state = -1; auto pending_program_index = static_cast<std::int16_t>(active_process->program_map_b[priority]);
                                auto& head = active_process->program_map_a[priority]; auto& tail = active_process->program_map_b[priority];
                                if (program_index == static_cast<std::uint32_t>(static_cast<std::int16_t>(tail))) {
                                    if (head == tail) {
                                        head = UINT16_MAX; tail = UINT16_MAX;
                                        if (std::all_of(std::begin(active_process->program_map_a), std::begin(active_process->program_map_a) + 3, [](std::uint16_t index) { return static_cast<std::int16_t>(index) < 0; })) { dequeueProcess(*active_process); active_process->programs_queued = false; }
                                    } else { pending_program_index = static_cast<std::int16_t>(active_program_record->previous_program); tail = pending_program_index; program_table_base[pending_program_index].next_program = tail; }
                                    finishPriority = true;
                                } else if (program_index == head) { head = active_program_record->next_program; program_table_base[head].previous_program = head; }
                                else { program_table_base[active_program_record->next_program].previous_program = active_program_record->previous_program; program_table_base[active_program_record->previous_program].next_program = active_program_record->next_program; }
                                break;
                            }
                            ++instruction_cursor;
                            if (!executeInstruction(current_opcode)) reportInvalidInstruction();
                            if (execution_failed) { unload = true; break; }
                        }
                    }
                    if (!finishPriority && !unload) active_program_record->instruction_offset = instruction_cursor - bytecode_base;
                }
                if (finishPriority || unload) break;
                program_index = static_cast<std::int16_t>(active_program_record->next_program);
                if (initialProgram == static_cast<std::uint32_t>(static_cast<std::int16_t>(active_process->program_map_b[priority]))) break;
            }
        }
        if (unload || (active_process->flags & SferaMbcProcessRecord::unloadAfterExecution) != 0) {
            unloadProcess(process_index); if (process_index == static_cast<std::uint32_t>(process_chain_last)) break;
        }
        const auto previousActive = g_sfera_mbc_runtime.dispatch_slot; process_index = active_process->execution_prev_index;
        if (previousActive == static_cast<std::uint32_t>(execution_chain_head)) break;
    }
    g_sfera_mbc_runtime.dispatch_slot = UINT32_MAX;
    if (halt_state == SferaMbcRuntime::HaltState::Dispatched) { if (!final_shutdown) initialize(); return; }
    if (static_cast<int>(g_sfera_mbc_runtime.simulation_tick) % 3 == 0) {
        g_sfera_network_runtime.receiveMessages();
        for (int index = g_sfera_mbc_runtime.active_world_slot; index >= 0;) {
            auto& slot = g_sfera_mbc_runtime.world_slots[index]; index = slot.primary_state;
            const auto flush = [&](std::uint32_t& bits, auto& payload, std::uint32_t& owner, std::uint32_t flags) {
                if (static_cast<int>(bits) <= 0) return;
                const auto bytes = (bits + 7) >> 3;
                if (!g_sfera_network_runtime.sendPacket(flags, std::span<const std::uint8_t>(payload, bytes))) return;
                bits = 0;
                std::fill(std::begin(payload), std::end(payload), 0);
                owner = UINT32_MAX;
            };
            flush(slot.reliable_bit_count, slot.reliable_payload, slot.reliable_process, 8); flush(slot.unreliable_bit_count, slot.unreliable_payload, slot.unreliable_process, 0);
        }
    }
}

void SferaMbcRuntime::buildRegion() {
    if (argument_count < 1) { reportError("Wrong number of parameters for 'send' function"); return; }
    auto region = nextInteger(); --argument_count;
    if (region == -2 || region == -4 || region == -5 || region == -7) {
        const auto prefix = region; region = nextInteger(); --argument_count;
        if (prefix == -7) { const auto stackSize = value_stack_size, cursor = argument_cursor; nextInteger(); nextSliceReference(); nextInteger(); nextSliceReference(); nextInteger(); if (execution_failed) return; value_stack_size = stackSize; argument_cursor = cursor; }
    } else if (region == -1 || region == -3) return;
    if (region < 0 || region > 61 || active_process->regions.empty()) { reportError("Wrong region for 'send' function"); return; }
    const auto& definition = active_process->regions[region];
    if (definition.flags == -1) { reportError("Wrong flags for 'send' function"); return; }
    send_field_count = 0;
    const auto emit = [&](std::uint32_t value, std::uint8_t width) { if (send_field_count >= outgoing_fields.size()) { reportError("Wrong data for 'send' function"); return false; } outgoing_fields[send_field_count].word = value; outgoing_fields[send_field_count++].format = width; return true; };
    for (int field = 0; field < definition.field_count; ++field) {
        if (argument_cursor >= argument_end || --argument_count < 0) { reportError("Wrong number of parameters for 'send' function"); return; }
        const auto value = g_sfera_mbc_runtime.values[argument_cursor++].value.base;
        const int width = definition.formats[field];
        if ((width >= -32 && width <= 32) || (width >= 103 && width <= 108)) { if (!emit(value, static_cast<std::uint8_t>(std::abs(width)))) return; continue; }
        if (width != 101 && width != 102) { reportError("Wrong data for 'send' function"); return; }
        const auto count = std::clamp(static_cast<int>(value), 0, width == 101 ? 15 : 255);
        if (!emit(count, width == 101 ? 4 : 8)) return;
        if (--argument_count < 0 || ++field >= definition.field_count || argument_cursor >= argument_end) { reportError("Wrong data for 'send' function"); return; }
        const auto elementWidth = std::abs(static_cast<int>(definition.formats[field])); const auto& array = g_sfera_mbc_runtime.values[argument_cursor];
        if (elementWidth > 32 || !array.isPointer()) { reportError("Wrong data for 'send' function"); return; }
        const auto elementSize = array.elementSize(); ++argument_cursor;
        if (elementSize > 4) { reportError("Wrong data for 'send' function"); return; }
        const auto* data = memoryAt(array.value.base);
        for (int index = 0; index < count; ++index) { std::uint32_t item = 0; std::memcpy(&item, data, elementSize); data += elementSize; if (!emit(item, static_cast<std::uint8_t>(elementWidth))) return; }
    }
    sendRegion(400, static_cast<std::uint32_t>(region), static_cast<std::uint32_t>(definition.flags));
}

void SferaClientApplication::configureResourceDirectory() {
    const auto containsClient = [](const std::filesystem::path& directory) { std::error_code error; return std::filesystem::is_regular_file(directory / L"mbc" / L"_main.mbc", error); };
    std::filesystem::path root;
    const DWORD required = ::GetEnvironmentVariableW(L"SFERA_CLIENT_ROOT", nullptr, 0);
    if (required != 0) {
        std::vector<wchar_t> configured(required);
        const DWORD length = ::GetEnvironmentVariableW(L"SFERA_CLIENT_ROOT", configured.data(), required);
        if (length == 0 || length >= required) throw std::runtime_error("Cannot read SFERA_CLIENT_ROOT");
        root = std::filesystem::absolute(std::filesystem::path(configured.data()));
        if (!containsClient(root)) throw std::runtime_error("SFERA_CLIENT_ROOT does not contain mbc\\_main.mbc");
    } else {
        std::vector<wchar_t> executable(512);
        for (;;) {
            const DWORD length = ::GetModuleFileNameW(nullptr, executable.data(), static_cast<DWORD>(executable.size()));
            if (length == 0) throw std::runtime_error("Cannot determine the client executable path");
            if (length + 1 < executable.size()) break;
            if (executable.size() >= 32768) throw std::length_error("Client executable path is too long");
            executable.resize(std::min<std::size_t>(executable.size() * 2, 32768));
        }
        const std::array<std::filesystem::path, 2> starts{std::filesystem::current_path(), std::filesystem::path(executable.data()).parent_path()};
        for (auto candidate : starts) {
            for (unsigned depth = 0; depth < 12 && !candidate.empty(); ++depth) {
                if (containsClient(candidate)) { root = candidate; break; }
                const auto parent = candidate.parent_path();
                if (parent == candidate) break;
                candidate = parent;
            }
            if (!root.empty()) break;
        }
        if (root.empty()) throw std::runtime_error("Unable to locate mbc\\_main.mbc. Set SFERA_CLIENT_ROOT to the client resource directory.");
    }
    if (!::SetCurrentDirectoryW(root.c_str())) throw std::system_error(static_cast<int>(::GetLastError()), std::system_category(), "SetCurrentDirectoryW");
}

int SferaClientApplication::run(HINSTANCE instance) {
    SferaClientApplication application;
    lifecycle = Lifecycle::Running;
    instance_handle = instance;
    quit_requested = interrupted = fatal_error_in_progress = false;
    try {
        configureResourceDirectory();

        SferaClientApplication::initializeStorage();
        ::SetThreadAffinityMask(::GetCurrentThread(), 1);
        const char* arguments = SferaClientApplication::commandLineArguments(::GetCommandLineA());
        if (std::strstr(arguments, "/15FCE220-0246-58ec-3EH2-968B3072ACF8") != nullptr) {
            ::MessageBoxA(nullptr, "\307\340\357\363\361\352 \357\360\356\350\347\342\356\344\350\362\361\377 \357\360\356\343\360\340\354\354\356\351 Sphere.exe.", "\316\370\350\341\352\340 \347\340\357\363\361\352\340.", MB_ICONERROR);
            SferaClientApplication::releaseStorage();
            return 0;
        }
        const auto readArgument = [arguments](const char* name, auto& output, std::size_t limit) {
            std::fill(std::begin(output), std::end(output), '\0');
            const char* value = std::strstr(arguments, name);
            if (value == nullptr) return false;
            value += std::strlen(name);
            value += std::strspn(value, " \t");
            const auto length = std::min({std::strcspn(value, " \t"), limit, std::size(output) - 1});
            std::copy_n(value, length, output);
            return true;
        };
        readArgument("/locale", SferaClientApplication::locale, 9);
        for (const char* directory : {".\\logs", ".\\players"}) ::CreateDirectoryA(directory, nullptr);
        SphereRender::SceneRenderer::buildColorRemap(1.0, static_cast<double>(0.3f));
        SferaClientApplication::instance_handle = instance;
        if (application.initialize()) { resetWorld(); application.runMainLoop(); }
        shutdown();
        SferaClientApplication::releaseStorage();
        return 0;
    } catch (const ExitRequested&) {
        return 0;
    } catch (const std::exception& error) {
        shutdown();
        g_sfera_log_runtime.write(error.what());
        g_sfera_log_runtime.write("\n");
        ::OutputDebugStringA(error.what());
        SphereUI::Runtime::setSystemCursorVisible(true);
        ::MessageBoxA(nullptr, error.what(), "Sphere client error", MB_ICONERROR);
        return 1;
    } catch (...) {
        shutdown();
        ::OutputDebugStringA("Unhandled client exception");
        return 2;
    }
}

void SferaLogRuntime::initialize() {
    path = "Error.log";
    size_limit = 10000000u;
    writeTimestamp("**** Start: ");
}

void SferaLogRuntime::writeTimestamp(const char* prefix) {
    write(prefix);
    const auto timestamp = ::_time64(nullptr);
    tm local{};
    ::_localtime64_s(&local, &timestamp);
    char date[128]{};
    std::strftime(date, sizeof(date), "%A, %d %B %Y", &local);
    write(date);
    write("  ");
    char time[9]{};
    ::_strtime_s(time, sizeof(time));
    write(time);
    write("\n");
}

bool SferaClientApplication::initialize() {

    auto& settings = g_sfera_config_text_runtime;
    const auto readInteger = [&settings]<class T>(const char* name, T& output) { int value = 0; if (!settings.readInteger(name, value)) return false; output = static_cast<T>(value); return true; };
    g_sfera_files.setErrorReporting(true);
    g_sfera_files.addSearchPath("params");
    g_sfera_files.addSearchPath("mbc");
    g_sfera_log_runtime.initialize();
    const auto comResult = ::CoInitialize(nullptr);
    if (FAILED(comResult)) throw std::system_error(static_cast<int>(comResult), std::system_category(), "CoInitialize");
    com_initialized = true;
    settings.load("config.cfg");
    SferaClientApplication::language = 0;
    readInteger("LANG", SferaClientApplication::language);
    if (SferaClientApplication::locale[0] != '\0') {
        constexpr const char* locales[]{"ru", "en", "pt", "it", "de", "es", "fr"};
        SferaClientApplication::language = 1;
        for (std::uint32_t index = 0; index < std::size(locales); ++index) if (std::strncmp(SferaClientApplication::locale, locales[index], 2) == 0) { SferaClientApplication::language = index; break; }
    }
    constexpr const char* suffixes[]{"", "_e", "_p", "_i", "_d", "_spa", "_f"};
    SferaText::copyString(g_sfera_font_runtime.language_suffix, SferaClientApplication::language < std::size(suffixes) ? suffixes[SferaClientApplication::language] : "", sizeof(g_sfera_font_runtime.language_suffix));
    readInteger("AUTOFOG", g_sfera_graphics_runtime.auto_fog);
    settings.readFloat("FOGDIST", g_sfera_graphics_runtime.fog_distance);
    g_sfera_graphics_runtime.reflection_quality = 2;
    readInteger("REFLQUAL", g_sfera_graphics_runtime.reflection_quality);
    readInteger("EFFECTS", g_sfera_effect_manager.effects_enabled);
    readInteger("EFFECTDIAG", g_sfera_effect_manager.diagnostics.enabled);
    readInteger("LODS", g_sfera_graphics_runtime.lods_enabled);
    readInteger("HARDWARE_CURSOR", g_sfera_graphics_runtime.hardware_cursor_enabled);
    readInteger("DESCR_AUTO_POPUP", g_sfera_interface.description_auto_popup);
    readInteger("INVITE_MESSAGES", g_sfera_interface.invite_messages);

    {
        g_sfera_files.setErrorReporting(false);
        SferaFileManager::ScopedFile file(g_sfera_files, g_sfera_files.open("loadcount.bin", _O_RDONLY));
        g_sfera_files.setErrorReporting(true);
        if (file.get() >= 0) g_sfera_files.read(file.get(), &GameInterface::loading_total, sizeof(GameInterface::loading_total));
        else GameInterface::loading_total = 15000;
    }
    ::InitCommonControls();
    if (!runStartupScripts()) return false;
    GameInterface::registerNativeWindowClass();
    g_sfera_graphics_runtime.display_width = 640;
    g_sfera_graphics_runtime.display_height = 480;
    settings.load("config.cfg");
    SferaClientApplication::windowed = false;
    readInteger("WINDOWED", SferaClientApplication::windowed);
    g_sfera_graphics_runtime.display_width = static_cast<std::uint32_t>(::GetSystemMetrics(SM_CXSCREEN));
    g_sfera_graphics_runtime.display_height = static_cast<std::uint32_t>(::GetSystemMetrics(SM_CYSCREEN));
    g_sfera_graphics_runtime.display_depth_bits = 16;
    readInteger("XRES", g_sfera_graphics_runtime.display_width);
    readInteger("YRES", g_sfera_graphics_runtime.display_height);
    readInteger("DEPTH", g_sfera_graphics_runtime.display_depth_bits);
    readInteger("GRASS", g_sfera_graphics_runtime.grass_depth);
    settings.readFloat("LOD_DISTANCE", g_sfera_graphics_runtime.minimum_lod_distance);
    settings.readFloat("MIN_LOD_DIST", g_sfera_graphics_runtime.lod_distance);
    readInteger("POSTEFFECTS", g_sfera_graphics_runtime.post_effects_enabled);
    if (g_sfera_graphics_runtime.minimum_lod_distance == 0.0f) g_sfera_graphics_runtime.minimum_lod_distance = 23.0f;
    if (g_sfera_graphics_runtime.lod_distance == 0.0f) g_sfera_graphics_runtime.lod_distance = 20.0f;
    const std::array<std::pair<const char*, bool*>, 3> landscapes{{{"landscape_hr", &TerrainAssets::high_resolution_assets}, {"landscape_ph", &TerrainAssets::alternate_ph_assets}, {"landscape_rd", &TerrainAssets::alternate_rd_assets}}};
    for (const auto& [path, enabled] : landscapes) { const DWORD attributes = ::GetFileAttributesA(path); *enabled = attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0; }
    GameInterface::createNativeWindow();
    g_sfera_files.addSearchPath("landscape");
    for (const auto& [path, enabled] : landscapes) if (*enabled != 0) g_sfera_files.addSearchPath(path);
    g_sfera_direct_input_runtime.initialize(SferaClientApplication::main_window);
    g_sfera_graphics_runtime.initialize();
    if (!g_sfera_graphics_runtime.d3d_runtime->supports_post_effects) g_sfera_graphics_runtime.post_effects_enabled = false;
    CCursorManager::instance().select(g_sfera_graphics_runtime.hardware_cursor_enabled);
    GameInterface::createWindow(0, 0, g_sfera_graphics_runtime.display_width - 1, g_sfera_graphics_runtime.display_height - 1, 0, 0);
    for (auto& vertex : SphereUI::InterfaceRenderer::glyph_vertices) { vertex.z = 0.0f; vertex.rhw = 1.0f; vertex.specular = 0; }
    ::ShowCursor(FALSE);
    ::ShowCursor(TRUE);
    SphereUI::Runtime::setSystemCursorVisible(false);
    for (std::uint32_t index = 0; index < 2; ++index) {
        char path[64]{};
        std::snprintf(path, sizeof(path), "fonts\\font%u%s.pcx", index + 1, SferaClientApplication::language != 0 && SferaClientApplication::language != 1 ? g_sfera_font_runtime.language_suffix : "");
        g_sfera_font_runtime.load(index, path, 1, 1, index == 0 ? 5 : 3);
    }
    SphereRender::ModelPose::coordinate_basis = {};
    SphereRender::ModelPose::coordinate_basis.m[2][0] = 1.0f;
    SphereRender::ModelPose::coordinate_basis.m[0][1] = -1.0f;
    SphereRender::ModelPose::coordinate_basis.m[1][2] = -1.0f;
    SphereRender::ModelPose::coordinate_basis.m[3][3] = 1.0f;
    for (std::size_t index = 0; index < std::size(g_sfera_motion.material_scale); ++index) g_sfera_motion.material_scale[index] = static_cast<double>(index) / 6.0;
    constexpr float weights[]{2.0f, 0.2f, 0.75f, 1.2f, 2.5f, 3.0f, 4.0f};
    for (std::size_t index = 0; index < std::size(weights); ++index) g_sfera_motion.surface_friction[index] = weights[index];
    TerrainTextureCache::initialize();
    g_sfera_motion.initializeResponseCurve();
    return true;
}

void TerrainTextureCache::initialize() {
    std::array<float, 12> passes{};
    for (std::uint32_t row = 0; row < 12; ++row) {
        const float position = static_cast<double>(row * 254) / 12.0 + 1.0 - 1.0 / 24.0;
        const auto bucket = static_cast<int>(std::trunc(static_cast<double>(position) + 0.5)) - 1;
        passes[row] = static_cast<double>(position) - bucket;
    }
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    decltype(entries) replacement{};
    for (auto& entry : replacement) {
        device.checkResult(device.native_device->CreateTexture(256u, 256u, 1u, 0u, D3DFMT_A4R4G4B4,
            D3DPOOL_MANAGED, entry.resource.GetAddressOf(), nullptr), "CreateTexture");
        if (entry.resource == nullptr) SferaClientApplication::terminateWithError("CreateTexture for landscape cash failed");
    }
    TerrainTextureCache::entries = std::move(replacement);

    for (std::uint32_t row = 0; row < 12; ++row) {
        float position = passes[row];
        for (std::uint32_t column = 0; column < 256; ++column) {
            const auto bucket = static_cast<int>(std::trunc(static_cast<double>(position) + 0.5)) - 1;
            const float fraction = static_cast<double>(position) - bucket - 0.5;
            TerrainTextureCache::quantization_x[row * 256 + column] = bucket;
            TerrainTextureCache::quantization_y[row * 256 + column] = std::trunc(static_cast<double>(fraction) * 64.0 + 0.5);
            position = static_cast<double>(position) + static_cast<double>(1.0f / 12.0f);
        }
    }
    for (std::size_t row = 0; row < 64; ++row) {
        const float y = static_cast<float>(row) / 64.0f;
        for (std::size_t column = 0; column < 64; ++column) {
            const float x = static_cast<float>(column) / 64.0f;
            const float weights[]{(1.0f - x) * (1.0f - y), x * (1.0f - y), (1.0f - x) * y, x * y};
            for (std::size_t channel = 0; channel < std::size(weights); ++channel) TerrainTextureCache::blend_lut[(row * 64 + column) * 4 + channel] = std::trunc(static_cast<double>(weights[channel]) * 255.0);
        }
    }
    std::fill(std::begin(g_sfera_direct_input_runtime.allowed_glyphs), std::end(g_sfera_direct_input_runtime.allowed_glyphs), 0);
    for (const auto glyph : std::string_view("!\"#$%&'(.")) g_sfera_direct_input_runtime.allowed_glyphs[static_cast<std::uint8_t>(glyph)] = 1;
    g_sfera_direct_input_runtime.allowed_glyphs[UINT8_MAX] = 1;
}

void SferaClientApplication::resetWorld() {
    g_sfera_world_objects.destroyAll();
    g_sfera_sound_runtime.initialize();
    ShadowMap::initialize(1);
    WorldGuiControls::destroyAllText();

    SferaText::copyString(g_sfera_interface.default_cursor_name, "cursor1", sizeof(g_sfera_interface.default_cursor_name));
    g_sfera_world_objects.controlled_object_handle = UINT32_MAX;
    g_sfera_interface.world_interaction_enabled = false;
    g_sfera_motion.acceleration = {};
    SphereRender::SceneRenderer::visible_character_parts = UINT8_MAX;
    GameInterface::active_window = UINT32_MAX;
    SphereRender::ModelPose::scale = {};
    SphereRender::ModelPose::scale.y = 1.0f;
    g_sfera_direct_input_runtime.text_filter = 0;
    g_sfera_interface.overlay_alpha = 0;
    for (auto& entry : TerrainTextureCache::entries) { entry.owner = nullptr; entry.use_count = 0; }
    {
        auto zones = std::make_unique<EnvironmentZones>();
        zones->load("Landscape\\zoning.cfg");
        SphereRender::SceneRenderer::environment_zones = std::move(zones);
    }
    {
        auto zones = std::make_unique<EnvironmentZones>();
        zones->load("Landscape\\zoningHaron.cfg");
        SphereRender::SceneRenderer::alternate_environment_zones = std::move(zones);
    }
}

int SferaClientApplication::advanceClock() {
    const std::uint32_t current = WorldClock::nowTicks();
    const auto elapsed = std::bit_cast<int>(std::bit_cast<std::uint32_t>(tick_remainder_) + current - previous_tick_);
    previous_tick_ = current;
    tick_remainder_ = std::min(elapsed, 10000);
    const auto steps = (tick_remainder_ + 26) / 52;
    tick_remainder_ -= steps * 52;
    return steps;
}

bool SferaClientApplication::runStartupScripts() {
    g_sfera_mbc_runtime.initialize();
    SferaClientApplication::interpreter_initialized = true;
    previous_tick_ = WorldClock::nowTicks();
    tick_remainder_ = 0;
    SferaClientApplication::startup_complete = false;
    for (;;) {
        const auto steps = advanceClock();
        for (int index = 0; index < steps; ++index) { g_sfera_mbc_runtime.tick(); if (SferaClientApplication::startup_complete) return true; }
        dispatch_application_messages();
        if (SferaClientApplication::quit_requested) return false;
        ::Sleep(10);
    }
}

void SferaClientApplication::updateSimulation() {
    const auto takeQueued = [](std::deque<std::uint32_t>& queue, std::uint32_t& current) {
        if (queue.empty()) return;
        current = queue.front();
        queue.pop_front();
    };
    takeQueued(g_sfera_direct_input_runtime.character_queue, g_sfera_direct_input_runtime.character);
    takeQueued(g_sfera_direct_input_runtime.key_queue, g_sfera_direct_input_runtime.virtual_key);
    const auto key = g_sfera_direct_input_runtime.takeKeyPress();
    g_sfera_direct_input_runtime.scan_code = key;
    if (SferaClientApplication::interrupted) { SferaClientApplication::interrupted = false; throw std::runtime_error("Client execution interrupted"); }
    g_sfera_direct_input_runtime.pollKeyboard();
    auto& mouse = g_sfera_direct_input_runtime.mouse;
    mouse = g_sfera_direct_input_runtime.pollMouse();
    if ((g_sfera_direct_input_runtime.view_adjust_state & SferaInputDevices::pressedMask) != 0) {
        mouse.dx = 0;
        mouse.dy = 0;
    }
    GameInterface::updateInput();
    g_sfera_interface.update(static_cast<std::uint8_t>(g_sfera_direct_input_runtime.virtual_key), static_cast<std::uint8_t>(g_sfera_direct_input_runtime.character), mouse.buttons, mouse.wheel);
    if (g_sfera_motion.control_mode == 1 && !g_sfera_interface.world_interaction_enabled && g_sfera_motion.orientation_blocked == 0) {
        g_sfera_motion.updateOrientation();
    } else {

        g_sfera_motion.displacement = {};
        g_sfera_motion.acceleration = {};
        g_sfera_direct_input_runtime.pollMouse();
    }
    g_sfera_mbc_runtime.tick();
    if (g_sfera_motion.control_mode == 0) g_sfera_motion.updateControlled(1.0f / 192.0f);
    if (++object_update_ticks_ == 4) {
        object_update_ticks_ = 0;
        g_sfera_motion.updateObjects(1.0f / 48.0f);
    }
    if (++effect_update_ticks_ == 6) {
        SphereRender::SceneRenderer::adaptFog();
        effect_update_ticks_ = 0;
        if (SferaClientApplication::resources_loaded) g_sfera_effect_manager.updateActiveEffects();
    }
    if (++maintenance_ticks_ == 6) {
        maintenance_ticks_ = 0;
        if (++SphereRender::SceneRenderer::texture_animation_frame == 32) SphereRender::SceneRenderer::texture_animation_frame = 0;
        TerrainAssets::evictUnused();
    }
    g_sfera_world_objects.updateExtendedSpatialIndices();
    g_sfera_direct_input_runtime.virtual_key = 0;
    g_sfera_direct_input_runtime.character = 0;
    auto& phase = SceneSky::animation_phase;
    phase = static_cast<double>(phase) + static_cast<double>(0.0005f);
    if (phase > 1.0f) phase = static_cast<double>(phase) - 1.0;
    g_sfera_vegetation.updateGrassView();
}

void SferaClientApplication::renderFrame() {

    if (SferaClientApplication::resources_loaded) {
        bool highResolution = false;
        if (TerrainAssets::high_resolution_assets) {
            const auto* reference = g_sfera_world_objects.object(1);
            if (reference == nullptr) WorldDiagnostics::fail("Weather update: missing reference object");
            highResolution = reference->position.y > 300.0f && reference->position.y < 800.0f;
        }
        auto* weather = highResolution ? g_sfera_weather_runtime.highres.get() : g_sfera_weather_runtime.standard.get();
        if (weather == nullptr) weather = highResolution ? g_sfera_weather_runtime.standard.get() : g_sfera_weather_runtime.highres.get();
        if (weather != nullptr) weather->update(static_cast<int>(WorldClock::calendarTicks()), g_sfera_graphics_runtime.environment_factor, g_sfera_weather_runtime.current, SphereWorld::Vegetation::alternatePatterns());
        if (g_sfera_sound_runtime.volume_refresh_active) {
            const bool increase = static_cast<int>(g_sfera_sound_runtime.volume_refresh_direction) > 0;
            g_sfera_sound_runtime.adjustMusicVolume(increase ? 1 : -1);
            g_sfera_sound_runtime.volume_refresh_direction = increase ? 0 : 1;
            g_sfera_sound_runtime.volume_refresh_frames = static_cast<double>(g_sfera_sound_runtime.volume_refresh_frames) + 1.0;
            if (g_sfera_sound_runtime.volume_refresh_frames > 50.0f) g_sfera_sound_runtime.volume_refresh_active = false;
        }
        SphereRender::SceneRenderer::drawFrame();
        g_sfera_effect_manager.writeDiagnostics();
        return;
    }
    if (!SferaClientApplication::application_active) {
        if (!SferaClientApplication::windowed) return;
        ::Sleep(100);
    }
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    SceneScope scene(device);
    if (!scene) return;
    device.checkResult(device.native_device->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, SferaColor::rgba(0u, 0u, 0u).argb(), 1.0f, 0), "Clear");
    GameInterface::drawFrame();
    scene.finish();
    device.present();
}

void SferaClientApplication::runMainLoop() {
    object_update_ticks_ = effect_update_ticks_ = maintenance_ticks_ = 0;
    SferaClientApplication::main_loop_started = true;
    previous_tick_ = WorldClock::nowTicks();
    tick_remainder_ = 0;
    for (;;) {
        const auto steps = advanceClock();
        if (steps == 0) { const auto delay = (52 - tick_remainder_) / 10; if (delay > 50) ::Sleep(19); else if (delay > 1) ::Sleep(static_cast<DWORD>(delay - 1)); }
        for (int index = 0; index < steps; ++index) updateSimulation();
        renderFrame();
        if (SferaClientApplication::resources_loaded) g_sfera_sound_runtime.update();
        dispatch_application_messages();
        if (SferaClientApplication::quit_requested) return;
    }
}

void SferaClientApplication::loadResources() {

    if (SferaClientApplication::resources_loaded) return;
    g_sfera_interface.showLoadingScreen(true, g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height, SferaClientApplication::language != 0); ::Sleep(50);
    for (int refresh = 0; refresh < 2; ++refresh) { g_sfera_graphics_runtime.rebuild_percent = UINT32_MAX; GameInterface::updateLoadingProgress(0); }
    ::Sleep(50); g_sfera_effect_manager.initialize(); ::Sleep(50); g_sfera_materials.load("models\\materls.mtr"); ::Sleep(50); TerrainAssets::loadMap(); ::Sleep(50);
    const auto loadConfiguration = []<class T>(std::unique_ptr<T>& owner, const char* path) {
        auto replacement = std::make_unique<T>();
        replacement->load(path);
        owner = std::move(replacement);
    };
    loadConfiguration(SceneSky::environment, "sky.txt");
    if (TerrainAssets::high_resolution_assets) loadConfiguration(SceneSky::high_resolution_environment, "landscape_hr\\sky_hr.txt");
    ::Sleep(50); g_sfera_models.initialize(); g_sfera_models.addFolder("models\\");
    if (TerrainAssets::high_resolution_assets) g_sfera_models.addFolder("models_hr\\");
    if (TerrainAssets::alternate_ph_assets) g_sfera_models.addFolder("models_ph\\");
    if (TerrainAssets::alternate_rd_assets) g_sfera_models.addFolder("models_rd\\");
    g_sfera_models.finishRegistration();
    const char* folders[]{"xadd\\"};
    auto characters = std::make_unique<SphereRender::CharacterModels>();
    characters->load(folders);
    characters->setDistances(g_sfera_graphics_runtime.lod_distance, g_sfera_graphics_runtime.minimum_lod_distance);
    if (SphereRender::SceneRenderer::characters) SphereRender::SceneRenderer::characters->clear();
    SphereRender::SceneRenderer::characters = std::move(characters);
    ::Sleep(50);
    auto contours = std::make_unique<Contours>(2000, 2999);
    contours->load();
    g_sfera_world_objects.contours = std::move(contours);
    ::Sleep(50);
    loadConfiguration(g_sfera_weather_runtime.standard, "landscape\\weather.txt");
    if (TerrainAssets::high_resolution_assets) loadConfiguration(g_sfera_weather_runtime.highres, "landscape_hr\\weather_hr.txt");
    ::Sleep(50); g_sfera_world_objects.create("cam_cube", nullptr, 0, true);
    auto* camera = SphereRender::CharacterModels::checkedExtended(g_sfera_world_objects.object(0));
    if (camera == nullptr) terminateWithError("Camera object was not created");
    camera->render_enabled = false; g_sfera_world_objects.create("cam_cube", nullptr, 5, true); g_sfera_vegetation.initialize(); ::Sleep(50);
    g_sfera_interface.chat_filter = std::make_unique<SphereUI::ChatFilter>(); SferaClientApplication::resources_loaded = true;
}

SferaClientApplication::~SferaClientApplication() noexcept {
    shutdown();
    releaseStorage();
}

void SferaClientApplication::shutdown() noexcept {
    if (lifecycle == Lifecycle::Stopping || lifecycle == Lifecycle::Stopped || lifecycle == Lifecycle::Dormant) return;
    lifecycle = Lifecycle::Stopping;
    const auto finish = [](auto&& operation) noexcept {
        try { operation(); }
        catch (const std::exception& error) { ::OutputDebugStringA(error.what()); }
        catch (...) { ::OutputDebugStringA("Resource shutdown failed"); }
    };
    finish([] {
        if (interpreter_initialized && !g_sfera_mbc_runtime.final_shutdown) {
            g_sfera_mbc_runtime.final_shutdown = true;
            g_sfera_mbc_runtime.halt_state = SferaMbcRuntime::HaltState::Requested;
            g_sfera_mbc_runtime.tick();
        }
    });
    finish([] { g_sfera_network_runtime.shutdown(); });
    // Registrations remain alive while process-owned UI/world resources are removed.
    finish([] { g_sfera_mbc_runtime.shutdown(); });
    interpreter_initialized = false;
    finish([] { g_sfera_effect_manager.shutdown(); });
    finish([] { g_sfera_sound_runtime.shutdown(); });
    finish([] { g_sfera_interface.shutdown(); });
    CCursorManager::shutdown();
    finish([] { ShadowMap::shutdown(); });
    g_sfera_vegetation.animation.reset();
    finish([] { g_sfera_world_objects.clear(); });
    finish([] { g_sfera_vegetation.clear(); });
    g_sfera_player_lists.clear();
    g_sfera_models.clear();
    SphereRender::SceneRenderer::characters.reset();
    g_sfera_interface.chat_filter.reset();
    g_sfera_world_objects.contours.reset();
    g_sfera_weather_runtime.highres.reset();
    g_sfera_weather_runtime.standard.reset();
    SceneSky::environment.reset();
    SceneSky::high_resolution_environment.reset();
    SphereRender::SceneRenderer::environment_zones.reset();
    SphereRender::SceneRenderer::alternate_environment_zones.reset();
    g_sfera_direct_input_runtime.release();
    g_sfera_direct_input_runtime.key_queue.clear();
    g_sfera_direct_input_runtime.character_queue.clear();
    g_sfera_font_runtime.clear();
    finish([] { TerrainTextureCache::release(); });
    finish([] { TerrainAssets::releaseAll(); });
    g_sfera_textures.clear();
    g_sfera_graphics_runtime.d3d_runtime.reset();
    if (main_window != nullptr) ::DestroyWindow(std::exchange(main_window, nullptr));
    if (window_class_registered) {
        ::UnregisterClassA(GameInterface::nativeWindowClassName, instance_handle);
        window_class_registered = false;
    }
    if (com_initialized) { ::CoUninitialize(); com_initialized = false; }
    finish([] {
        g_sfera_log_runtime.writeTimestamp("**** Quit: ");
        g_sfera_log_runtime.write("\n");
        if (g_sfera_files.fileSize("Error.log") > static_cast<int>(g_sfera_log_runtime.size_limit))
            g_sfera_files.keepTail("Error.log", g_sfera_log_runtime.size_limit);
    });
    resources_loaded = main_loop_started = application_active = false;
    lifecycle = Lifecycle::Stopped;
}

[[noreturn]] void SferaClientApplication::terminateWithError(const char* message) {
    if (fatal_error_in_progress) throw std::runtime_error(message == nullptr ? "Client error" : message);
    fatal_error_in_progress = true;
    std::string description = "ServerN=" + std::to_string(static_cast<int>(server_number)) + "  " + (message == nullptr ? "" : message);
    if (const auto* context = WorldDiagnostics::scriptContext()) { description += '\n'; description += context; }
    throw std::runtime_error(description);
}

[[noreturn]] void SferaClientApplication::arrayBoundsError(int index) {
    char message[128]{};
    if (index < 0) std::snprintf(message, sizeof(message), "BoundCheckArray error: index less than zero\n");
    else std::snprintf(message, sizeof(message), "BoundCheckArray error: index out of range %d\n", index);
    terminateWithError(message);
}

// Options transactions and application commands.
namespace {
    using namespace SphereUI;

    void queueInterfaceRefresh() {
        g_sfera_interface.queueEvent({nullptr, 0u, UiMessage::refreshInterface, 0u, 0u});
    }

    Window* optionChild(Window* window, std::uint32_t index) {
        return window == nullptr ? nullptr : window->controlAt(index);
    }

    void optionMessage(Window* window, std::uint32_t index, SphereUI::UiMessage message, std::uint32_t first = 0u, std::uint32_t second = 0u) {
        if (auto* child = optionChild(window, index)) child->handleMessage(message, first, second);
    }

    void optionText(Window* window, std::uint32_t index, const char* text) {
        if (auto* child = optionChild(window, index)) child->setText(text);
    }

    void optionLabel(Window* window, std::uint32_t index, const char* key) {
        optionText(window, index, g_sfera_interface.localizedText(key));
    }

    void optionToggleLabel(Window* window, std::uint32_t index, std::uint32_t value) {
        optionLabel(window, index, value != 0u ? "UISTR_WT_OPT16" : "UISTR_WT_OPT17");
    }

    void setOptionsVisible(bool show);
    void setInterfaceOptionsVisible(bool show);
    void setGraphicsOptionsVisible(bool show);
    void setFontOptionsVisible(bool show);
    Window* beginOptionsDialog(const char* name, WindowEventHandler handler, bool show) {
        auto* window = g_sfera_interface.findWindow(name);
        if (!show) {
            if (window != nullptr) {
                g_sfera_interface.closeWindow(window);
            }
            return window;
        }
        if (window != nullptr) return nullptr;
        setOptionsVisible(false);
        window = g_sfera_interface.openWindow(name);
        if (window != nullptr) g_sfera_interface.bindEventHandler(window, handler);
        return window;
    }

    void setOptionsVisible(bool show) {
        auto* window = g_sfera_interface.findWindow("options");
        if (show) {
            if (window == nullptr) if (auto* created = g_sfera_interface.openWindow("options")) g_sfera_interface.bindEventHandler(created, WindowEventHandler::options);
        } else if (window != nullptr) g_sfera_interface.closeWindow(window);
    }

    void setSoundOptionsVisible(bool show) {
        auto* window = beginOptionsDialog("sound_options", WindowEventHandler::sound_options, show);
        if (window == nullptr) return;
        auto& saved_music = g_sfera_interface.options.saved_music_volume;
        auto& saved_sound = g_sfera_interface.options.saved_sound_volume;
        auto& values = g_sfera_interface.options.edited_graphics;
        if (show) {
            saved_music = g_sfera_sound_runtime.musicVolume();
            saved_sound = g_sfera_sound_runtime.soundVolume();
            optionMessage(window, 7u, UiMessage::setScrollRange, 0u, 100u);
            optionMessage(window, 8u, UiMessage::setScrollRange, 0u, 100u);
            optionMessage(window, 7u, UiMessage::setScrollValue, saved_music);
            optionMessage(window, 8u, UiMessage::setScrollValue, saved_sound);
            values[7] = g_sfera_sound_runtime.hardwareMixing();
            values[12] = values[7];
            optionLabel(window, 9u, values[12] != 0u ? "UISTR_WT_OPT34" : "UISTR_WT_OPT33");
            return;
        }
        g_sfera_sound_runtime.setMusicVolume(saved_music);
        g_sfera_sound_runtime.setSoundVolume(saved_sound);
        setOptionsVisible(true);
        g_sfera_sound_runtime.setHardwareMixing(values[7] != 0u);
        InterfaceConfiguration::open("config.cfg");
        InterfaceConfiguration::writeInteger("SNDVOL", saved_sound);
        InterfaceConfiguration::writeInteger("MUSVOL", saved_music);
        InterfaceConfiguration::writeInteger("HWMIX", values[7]);
        InterfaceConfiguration::save();
    }

    std::uint32_t bindingCount() {
        const auto count = g_sfera_mbc_runtime.namedValue("SSKS_NUMBER");
        if (count > 63u) throw std::out_of_range("Options: at most 63 key bindings are supported");
        return count;
    }

    const char* bindingName(std::uint32_t key) {
        const auto* name = SphereUI::Runtime::keyName(key);
        return name == nullptr ? "???" : name;
    }

    Window* bindingRow(Window* window, std::uint32_t slot) {
        auto* list = optionChild(window, 5u);
        return list == nullptr || list->control_kind != UiControlKind::listItem ? nullptr : static_cast<ListItemCtrl*>(list)->itemAt(slot);
    }

    void refreshBindingLabel(Window* window, std::uint32_t slot) {
        optionText(bindingRow(window, slot), 3u, bindingName(g_sfera_interface.options.edited_bindings[slot]));
    }

    void refreshMouseBindingLabel(Window* window) {
        optionLabel(window, 4u, g_sfera_interface.options.dialog_kind == 0u ? "UISTR_WT_OPT23" : "UISTR_WT_OPT24");
    }

    bool availableBinding(std::uint32_t key) {
        const auto count = bindingCount();
        for (std::size_t slot = 0u; slot < count; ++slot) if (g_sfera_interface.options.edited_bindings[slot] == key) return false;
        return key != 0u && key != VK_ESCAPE && key != VK_F1 && key != VK_RETURN && key - '0' > 9u && key != VK_SHIFT && key != VK_CONTROL && key - VK_LEFT > 3u;
    }

    void setControlOptionsVisible(bool show) {
        auto* window = beginOptionsDialog("control_options", WindowEventHandler::control_options, show);
        if (window == nullptr) return;

        const auto count = bindingCount();
        if (show) {
            std::fill(std::begin(g_sfera_direct_input_runtime.key_bindings), std::end(g_sfera_direct_input_runtime.key_bindings), 0u);
            for (std::size_t slot = 0u; slot < std::max(5u, count); ++slot) {
                const auto key = g_sfera_mbc_runtime.namedValue("SSKS", slot);
                g_sfera_direct_input_runtime.key_bindings[slot] = slot < 5u ? SphereUI::Runtime::virtualKey(key) : key;
            }
            g_sfera_direct_input_runtime.key_bindings[63] = g_sfera_mbc_runtime.namedValue("INMS");
            std::copy(std::begin(g_sfera_direct_input_runtime.key_bindings), std::end(g_sfera_direct_input_runtime.key_bindings), std::begin(g_sfera_interface.options.edited_bindings));
            optionLabel(window, 4u, g_sfera_direct_input_runtime.key_bindings[63] == 0u ? "UISTR_WT_OPT23" : "UISTR_WT_OPT24");
            for (std::size_t slot = 0u; slot < count; ++slot) {
                optionMessage(window, 5u, UiMessage::appendListItem);
                std::snprintf(g_sfera_interface.options.binding_key_name, sizeof(g_sfera_interface.options.binding_key_name), "UISTR_WT_KEY%02zu", slot + 1u);
                optionLabel(bindingRow(window, slot), 2u, g_sfera_interface.options.binding_key_name);
                refreshBindingLabel(window, slot);
            }
            g_sfera_interface.options.binding_dialog_open = true;
            return;
        }
        setOptionsVisible(true);
        g_sfera_mbc_runtime.setNamedValue("INMS", g_sfera_direct_input_runtime.key_bindings[63]);
        for (std::size_t slot = 0u; slot < std::max(5u, count); ++slot) g_sfera_mbc_runtime.setNamedValue("SSKS", slot < 5u ? SphereUI::Runtime::scanCode(g_sfera_direct_input_runtime.key_bindings[slot]) : g_sfera_direct_input_runtime.key_bindings[slot], slot);
        queueInterfaceRefresh();
        g_sfera_interface.options.binding_dialog_open = false;
    }

    constexpr std::uint32_t interfaceControlIds[] = {7u, 8u, 9u, 11u, 12u, 15u, 16u, 19u, 21u};
    constexpr const char* interfaceSettingKeys[] = {"ISSN", "ISAD", "INSN", "INAW", "IAPM", "MBST", "BALR"};
    void setInterfaceOptionsVisible(bool show) {
        auto* window = beginOptionsDialog("interface_options", WindowEventHandler::interface_options, show);
        if (window == nullptr) return;

        if (show) {
            for (std::size_t index = 0u; index < 5u; ++index) g_sfera_interface.options.saved_interface[index] = index == 2u ? g_sfera_interface.sounds_enabled : g_sfera_mbc_runtime.namedValue(interfaceSettingKeys[index]);
            InterfaceConfiguration::open("config.cfg");
            g_sfera_interface.options.saved_interface[5] = InterfaceConfiguration::readInteger("MBST", g_sfera_interface.options.saved_interface[5]);
            g_sfera_interface.options.saved_interface[6] = UINT32_MAX;
            g_sfera_interface.options.saved_interface[6] = InterfaceConfiguration::readInteger("BALR", g_sfera_interface.options.saved_interface[6]);
            if (static_cast<int>(g_sfera_interface.options.saved_interface[6]) < 0) {
                g_sfera_interface.options.saved_interface[6] = 1u;
                InterfaceConfiguration::writeInteger("BALR", 1u);
                InterfaceConfiguration::save();
            }
            g_sfera_interface.options.saved_interface[7] = g_sfera_interface.description_auto_popup;
            g_sfera_interface.options.saved_interface[8] = g_sfera_interface.invite_messages;
            std::copy(std::begin(g_sfera_interface.options.saved_interface), std::end(g_sfera_interface.options.saved_interface), std::begin(g_sfera_interface.options.edited_interface));
            for (std::size_t index = 0u; index < std::size(interfaceControlIds); ++index) optionToggleLabel(window, interfaceControlIds[index], g_sfera_interface.options.edited_interface[index]);
            return;
        }
        setOptionsVisible(true);
        for (std::size_t index = 0u; index < std::size(interfaceSettingKeys); ++index) g_sfera_mbc_runtime.setNamedValue(interfaceSettingKeys[index], g_sfera_interface.options.saved_interface[index]);
        g_sfera_interface.description_auto_popup = g_sfera_interface.options.saved_interface[7];
        g_sfera_interface.invite_messages = g_sfera_interface.options.saved_interface[8];
        InterfaceConfiguration::open("config.cfg");
        InterfaceConfiguration::writeInteger("MBST", g_sfera_interface.options.saved_interface[5]);
        InterfaceConfiguration::writeInteger("BALR", g_sfera_interface.options.saved_interface[6]);
        InterfaceConfiguration::writeInteger("HARDWARE_CURSOR", g_sfera_graphics_runtime.hardware_cursor_enabled);
        InterfaceConfiguration::writeInteger("DESCR_AUTO_POPUP", g_sfera_interface.description_auto_popup);
        InterfaceConfiguration::writeInteger("INVITE_MESSAGES", g_sfera_interface.invite_messages);
        InterfaceConfiguration::save();
        g_sfera_interface.sounds_enabled = g_sfera_interface.options.saved_interface[2];
        queueInterfaceRefresh();
        g_sfera_interface.cross_enabled = g_sfera_interface.options.saved_interface[3];
    }

    void resetSavedWindowPositions() {
        g_sfera_interface.saved_positions.clear();
        for (const auto& window : g_sfera_interface.windows) if (window != nullptr && window->save_last_position) window->alignToScreen(true);
    }

    std::vector<std::uint32_t>& savedChatFonts() {
        return g_sfera_interface.options.saved_chat_fonts;
    }

    std::vector<std::uint32_t>& editedChatFonts() {
        return g_sfera_interface.options.edited_chat_fonts;
    }

    void setFontOptionsVisible(bool show) {
        auto* window = g_sfera_interface.findWindow("font_options");
        if (show) {
            if (window != nullptr) return;
            setInterfaceOptionsVisible(false);
            setOptionsVisible(false);
            window = g_sfera_interface.openWindow("font_options");
            if (window == nullptr) return;
            g_sfera_interface.bindEventHandler(window, WindowEventHandler::font_options);
            auto& saved = savedChatFonts();
            auto& edited = editedChatFonts();
            saved.reserve(2u);
            edited.reserve(2u);
            saved.push_back(4u);
            saved.push_back(4u);
            InterfaceConfiguration::open("config.cfg");
            saved.at(0u) = InterfaceConfiguration::readInteger("CHAT_LIST_FONT", saved.at(0u));
            saved.at(1u) = InterfaceConfiguration::readInteger("CHAT_EDIT_FONT", saved.at(1u));
            for (std::size_t index = 0u; index < 2u; ++index) if (auto* control = optionChild(window, index + 3u)) control->setFont(saved.at(index));
            edited = saved;
            return;
        }
        if (window == nullptr) return;
        g_sfera_interface.closeWindow(window);
        setInterfaceOptionsVisible(true);
        InterfaceConfiguration::open("config.cfg");
        InterfaceConfiguration::writeInteger("CHAT_LIST_FONT", savedChatFonts().at(0u));
        InterfaceConfiguration::writeInteger("CHAT_EDIT_FONT", savedChatFonts().at(1u));
        InterfaceConfiguration::save();
        queueInterfaceRefresh();
    }
}

namespace {
    using OptionsDisplayMode = SphereUI::DisplayMode;

    std::uint32_t findOptionsMode(const OptionsDisplayMode& requested) {
        const std::uint32_t count = g_sfera_graphics_runtime.d3d_runtime->display_modes.size();
        for (std::size_t index = 0u; index < count; ++index) {
            const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index);
            if (mode.width == requested.width && mode.height == requested.height && mode.depth == requested.depth) return index;
        }
        for (std::size_t index = count; index != 0u; --index) {
            const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index - 1u);
            if (mode.depth == requested.depth && mode.width <= SferaClientApplication::desktop_width && mode.height <= SferaClientApplication::desktop_height) return index - 1u;
        }
        return count - 1u;
    }

    void setOptionsModeLabel(Window* window, std::uint32_t index) {
        const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index);
        const auto text = std::to_string(static_cast<int>(mode.width)) + "x" + std::to_string(static_cast<int>(mode.height)) + " " + std::to_string(static_cast<int>(mode.depth));
        optionText(window, 7u, text.c_str());
    }

    const char* graphicsBooleanLabel(std::uint32_t value) {
        return value < 2u ? g_sfera_interface.options.labels[5u + value] : g_sfera_interface.options.unknown_graphics_label;
    }

    void optionSelection(Window* window, std::uint32_t index, std::uint32_t maximum, std::uint32_t value) {
        optionMessage(window, index, UiMessage::setSpinRange, 0u, maximum);
        optionMessage(window, index, UiMessage::setSpinValue, value);
    }

    void setupLodOptions(Window* window) {
        const auto enabled = g_sfera_graphics_runtime.lods_enabled;
        optionToggleLabel(window, 41u, enabled);
        optionSelection(window, 43u, 1u, enabled);
        optionMessage(window, 46u, UiMessage::setScrollRange, 0u, enabled ? 14u : 0u);
        if (enabled) optionMessage(window, 46u, UiMessage::setScrollValue, static_cast<std::uint32_t>(static_cast<std::int64_t>(std::trunc(g_sfera_graphics_runtime.lod_distance - 12.0))));
    }

    void setupFogOptions(Window* window) {
        const auto automatic = g_sfera_graphics_runtime.auto_fog;
        optionToggleLabel(window, 37u, automatic);
        optionSelection(window, 39u, 1u, automatic);
        optionMessage(window, 28u, UiMessage::setScrollRange, 0u, automatic ? 0u : 170u);
        if (!automatic) optionMessage(window, 28u, UiMessage::setScrollValue, static_cast<std::uint32_t>(static_cast<std::int64_t>(std::trunc(g_sfera_graphics_runtime.fog_distance - 30.0))));
    }

    void setGraphicsOptionsVisible(bool show) {
        auto* window = beginOptionsDialog("gfx_options", WindowEventHandler::graphics_options, show);
        if (window == nullptr) return;
        auto& values = g_sfera_interface.options.edited_graphics;

        auto& graphics = g_sfera_graphics_runtime;
        auto* shadows = g_sfera_shadows.get();
        if (shadows == nullptr) throw std::runtime_error("Shadow manager is unavailable");
        if (show) {
            g_sfera_interface.options.saved_fog_distance = graphics.fog_distance;
            g_sfera_interface.options.saved_lod_distance = g_sfera_graphics_runtime.lod_distance;
            g_sfera_interface.options.saved_lods_enabled = graphics.lods_enabled;
            values[9] = g_sfera_graphics_runtime.auto_fog;
            values[8] = g_sfera_effect_manager.effects_enabled;
            g_sfera_interface.options.graphics_page = g_sfera_graphics_runtime.reflection_quality;
            constexpr const char* label_keys[] = {"UISTR_WT_OPT21", "UISTR_WT_OPT20", "UISTR_WT_OPT19", "UISTR_WT_OPT18", "UISTR_WT_OPT17", "UISTR_WT_OPT17", "UISTR_WT_OPT16"};
            for (std::size_t index = 0u; index < std::size(label_keys); ++index) SferaText::copy(g_sfera_interface.options.labels[index], g_sfera_interface.localizedText(label_keys[index]));
            SferaText::copy(g_sfera_interface.options.unknown_graphics_label, g_sfera_interface.localizedText("UISTR_WT_OPT36"));
            InterfaceConfiguration::open("config.cfg");
            OptionsDisplayMode mode{static_cast<unsigned int>(graphics.display_width), static_cast<unsigned int>(graphics.display_height), g_sfera_graphics_runtime.display_depth_bits};
            mode.width = InterfaceConfiguration::readInteger("XRES", mode.width);
            mode.height = InterfaceConfiguration::readInteger("YRES", mode.height);
            g_sfera_graphics_runtime.d3d_runtime->enumerateDisplayModes(SferaClientApplication::windowed);
            values[5] = findOptionsMode(mode);
            values[1] = mode.depth;
            values[2] = shadows->quality;
            values[3] = g_sfera_graphics_runtime.grass_depth;
            values[4] = SferaClientApplication::windowed;
            values[6] = graphics.post_effects_enabled;
            values[10] = values[0];
            values[11] = mode.depth;
            g_sfera_interface.options.comparison_graphics_value = values[4];
            optionSelection(window, 15u, static_cast<std::uint32_t>(g_sfera_graphics_runtime.d3d_runtime->display_modes.size()) - 1u, values[5]);
            optionSelection(window, 17u, 4u, values[2]);
            optionSelection(window, 18u, 2u, values[3]);
            optionMessage(window, 26u, UiMessage::setSpinRange, 0u, 1u);
            optionToggleLabel(window, 31u, !g_sfera_effect_manager.effects_enabled);
            optionMessage(window, 26u, UiMessage::setSpinValue, !g_sfera_effect_manager.effects_enabled);
            setupLodOptions(window);
            setOptionsModeLabel(window, values[5]);
            optionText(window, 9u, g_sfera_interface.options.labels[values[2]]);
            optionText(window, 10u, graphicsBooleanLabel(values[3]));
            setupFogOptions(window);
            optionSelection(window, 24u, 3u, g_sfera_graphics_runtime.reflection_quality);
            optionText(window, 22u, g_sfera_interface.options.labels[4u - g_sfera_graphics_runtime.reflection_quality]);
            optionMessage(window, 34u, UiMessage::setSpinRange, 0u, 1u);
            optionLabel(window, 35u, values[4] != 0u ? "UISTR_WT_OPT61" : "UISTR_WT_OPT62");
            optionMessage(window, 34u, UiMessage::setSpinValue, values[4] == 0u);
            const auto* features = graphics.d3d_runtime.get();
            const bool post_supported = features != nullptr && features->supports_post_effects;
            if (!post_supported) values[6] = g_sfera_interface.options.saved_graphics[6] = graphics.post_effects_enabled = false;
            optionSelection(window, 51u, post_supported ? 1u : 0u, values[6]);
            optionText(window, 49u, graphicsBooleanLabel(values[6]));
            std::copy_n(values, 7u, g_sfera_interface.options.saved_graphics);
            return;
        }
        setOptionsVisible(true);
        shadows->quality = values[2];
        g_sfera_graphics_runtime.grass_depth = values[3];
        SferaClientApplication::windowed = values[4];
        InterfaceConfiguration::open("config.cfg");
        const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(values[5]);
        const std::pair<const char*, std::uint32_t> settings[] = { {
            "XRES", mode.width
        }, {"YRES", mode.height}, {"DEPTH", mode.depth}, {"GRASS", values[3]}, {"WINDOWED", values[4]}, {"SHAD", values[2]}, {"AUTOFOG", g_sfera_graphics_runtime.auto_fog}, {"FOGDIST", static_cast<std::uint32_t>(static_cast<int>(std::trunc(graphics.fog_distance)))}, {"REFLQUAL", g_sfera_graphics_runtime.reflection_quality}, {"EFFECTS", g_sfera_effect_manager.effects_enabled}, {"LODS", graphics.lods_enabled}, {"LOD_DISTANCE", static_cast<std::uint32_t>(static_cast<int>(std::trunc(g_sfera_graphics_runtime.minimum_lod_distance)))}, {"MIN_LOD_DIST", static_cast<std::uint32_t>(static_cast<int>(std::trunc(g_sfera_graphics_runtime.lod_distance)))}, {"POSTEFFECTS", values[6]}};
        for (const auto& setting : settings) InterfaceConfiguration::writeInteger(setting.first, setting.second);

        InterfaceConfiguration::save();
        if (values[10] != values[0] || values[11] != values[1] || g_sfera_interface.options.comparison_graphics_value != values[4])
            SferaClientApplication::quit_requested = true;
    }

    void handleHelpEvent(Window* window, const WindowEvent& event) {
        if (event.message == UiMessage::close) {
            g_sfera_interface.showHelpPage(nullptr);
            return;
        }
        if (event.message == UiMessage::leftClick) {
            if (event.control_id == 1u) g_sfera_interface.showHelpPage("Language\\helpindex.hts");
            else if (event.control_id == 2u) optionMessage(window, 3u, UiMessage::previousHyperTextPage);
            return;
        }
        if (event.message != UiMessage::hyperTextPageChanged) return;
        auto* control = static_cast<HyperTextCtrl*>(event.source);
        if (control == nullptr) return;
        const auto* document = control->document.get();
        const auto* name = document == nullptr ? nullptr : document->name.c_str();
        if (name != nullptr && SferaText::asciiEqual(name, "Language\\helpindex.hts")) control->handleMessage(UiMessage::clearHyperTextHistory, 0u, 0u);
        optionMessage(window, 2u, UiMessage::setEnabled, control->history.size() == 0u ? 0u : 1u);
    }

    void handleSoundOptionsEvent(Window* window, const WindowEvent& event) {
        if (event.message == UiMessage::horizontalScroll) {
            if (event.control_id == 7u) g_sfera_sound_runtime.setMusicVolume(event.first);
            else g_sfera_sound_runtime.setSoundVolume(event.first);
            return;
        }
        if (event.message == UiMessage::close) {
            setSoundOptionsVisible(false);
            return;
        }
        if (event.message != UiMessage::leftClick) return;
        if (event.control_id == 1u) {
            if (const auto* music = dynamic_cast<const ScrollBar*>(optionChild(window, 7u))) g_sfera_interface.options.saved_music_volume = music->current;
            if (const auto* sound = dynamic_cast<const ScrollBar*>(optionChild(window, 8u))) g_sfera_interface.options.saved_sound_volume = sound->current;
            g_sfera_interface.options.edited_graphics[7] = g_sfera_interface.options.edited_graphics[12];
        }
        if (event.control_id == 1u || event.control_id == 2u) setSoundOptionsVisible(false);
        else if (event.control_id == 9u) {
            auto& mixing = g_sfera_interface.options.edited_graphics[12];
            mixing = mixing == 0u;
            optionLabel(window, 9u, mixing != 0u ? "UISTR_WT_OPT34" : "UISTR_WT_OPT33");
        }
    }

    void handleControlOptionsEvent(Window* window, const WindowEvent& event) {

        if (event.message == UiMessage::close) {
            setControlOptionsVisible(false);
            return;
        }
        if (event.message == UiMessage::controlBindingCaptured) {
            if (g_sfera_interface.options.binding_slot == UINT32_MAX) return;
            g_sfera_direct_input_runtime.binding_capture = 0u;
            g_sfera_interface.capture_control_binding = false;
            g_sfera_direct_input_runtime.binding_key = 0u;
            auto* current = g_sfera_interface.findWindow("control_options");
            if (current == nullptr) return;
            if (availableBinding(event.first)) g_sfera_interface.options.edited_bindings[g_sfera_interface.options.binding_slot] = event.first;
            refreshBindingLabel(current, g_sfera_interface.options.binding_slot);
            return;
        }
        if (event.message == UiMessage::listItemEvent && static_cast<UiMessage>(event.first) == UiMessage::leftClick && HIWORD(event.second) == 3u) {
            g_sfera_interface.options.binding_slot = LOWORD(event.second);
            optionText(bindingRow(window, g_sfera_interface.options.binding_slot), 3u, "");
            g_sfera_direct_input_runtime.binding_capture = 1u;
            g_sfera_interface.capture_control_binding = true;
            g_sfera_direct_input_runtime.binding_key = 0u;
            return;
        }
        if (event.message != UiMessage::leftClick) return;
        if (event.control_id == 1u) std::copy(std::begin(g_sfera_interface.options.edited_bindings), std::end(g_sfera_interface.options.edited_bindings), std::begin(g_sfera_direct_input_runtime.key_bindings));
        if (event.control_id == 1u || event.control_id == 2u) {
            setControlOptionsVisible(false);
            return;
        }
        if (event.control_id == 4u) {
            auto& mode = g_sfera_interface.options.dialog_kind;
            mode = mode == 0u;
            refreshMouseBindingLabel(window);
        } else if (event.control_id == 6u) {
            constexpr std::uint32_t defaults[] = {'W', 'S', 'A', 'D', VK_SPACE, VK_OEM_3, VK_OEM_MINUS, VK_TAB, 'R', 'I', 'K', 'H', 'T', 'N', 'P', 'M', 'J', 'O', 'Y', VK_OEM_2};
            g_sfera_interface.options.dialog_kind = 0u;
            std::copy(std::begin(defaults), std::end(defaults), std::begin(g_sfera_interface.options.edited_bindings));
            optionLabel(window, 4u, g_sfera_direct_input_runtime.key_bindings[63] == 0u ? "UISTR_WT_OPT23" : "UISTR_WT_OPT24");
            for (std::size_t slot = 0u, count = bindingCount(); slot < count; ++slot) refreshBindingLabel(window, slot);
        }
    }

    void handleInterfaceOptionsEvent(Window* window, const WindowEvent& event) {

        if (event.message == UiMessage::close) {
            setInterfaceOptionsVisible(false);
            return;
        }
        if (event.message != UiMessage::leftClick) return;
        if (event.control_id == 1u) std::copy(std::begin(g_sfera_interface.options.edited_interface), std::end(g_sfera_interface.options.edited_interface), std::begin(g_sfera_interface.options.saved_interface));
        if (event.control_id == 1u || event.control_id == 2u) {
            setInterfaceOptionsVisible(false);
            return;
        }
        if (event.control_id == 6u) {
            resetSavedWindowPositions();
            return;
        }
        if (event.control_id == 22u) {
            setFontOptionsVisible(true);
            return;
        }
        for (std::size_t index = 0u; index < std::size(interfaceControlIds); ++index) if (event.control_id == interfaceControlIds[index]) {
            auto& value = g_sfera_interface.options.edited_interface[index];
            value = value == 0u;
            if (index == 0u) g_sfera_mbc_runtime.setNamedValue(interfaceSettingKeys[index], value);
            if (index == 3u) g_sfera_interface.cross_enabled = value;
            optionToggleLabel(window, interfaceControlIds[index], value);
            if (index == 2u) g_sfera_interface.sounds_enabled = value;
            else if (index != 3u) {
                if (index != 0u && index < std::size(interfaceSettingKeys)) g_sfera_mbc_runtime.setNamedValue(interfaceSettingKeys[index], value);
                queueInterfaceRefresh();
            }
            return;
        }
    }

    void handleGraphicsOptionsEvent(Window* window, const WindowEvent& event) {

        auto& values = g_sfera_interface.options.edited_graphics;
        auto& graphics = g_sfera_graphics_runtime;
        if (event.message == UiMessage::close) {
            setGraphicsOptionsVisible(false);
            return;
        }
        if (event.message == UiMessage::leftClick) {
            if (event.control_id == 1u) {
                std::copy_n(g_sfera_interface.options.saved_graphics, 7u, values);
                auto* lod = SphereRender::SceneRenderer::characters.get();
                if (lod != nullptr) lod->setDistances(g_sfera_graphics_runtime.lod_distance, g_sfera_graphics_runtime.minimum_lod_distance);
                setGraphicsOptionsVisible(false);
            } else if (event.control_id == 2u) {
                setGraphicsOptionsVisible(false);
                graphics.fog_distance = g_sfera_interface.options.saved_fog_distance;
                g_sfera_graphics_runtime.lod_distance = g_sfera_interface.options.saved_lod_distance;
                g_sfera_graphics_runtime.auto_fog = values[9];
                g_sfera_effect_manager.effects_enabled = values[8];
                graphics.lods_enabled = g_sfera_interface.options.saved_lods_enabled;
                g_sfera_graphics_runtime.reflection_quality = g_sfera_interface.options.graphics_page;
            }
            return;
        }
        if (event.message == UiMessage::spinValueChanged) switch (event.control_id) {
            case 15u:
                g_sfera_interface.options.saved_graphics[5] = event.first;
                setOptionsModeLabel(window, event.first);
                break;
            case 17u:
                {
                    g_sfera_interface.options.saved_graphics[2] = event.first;
                    auto* shadows = g_sfera_shadows.get();
                    if (shadows != nullptr) shadows->quality = event.first;
                    optionText(window, 9u, g_sfera_interface.options.labels[event.first]);
                    break;
                }
            case 18u:
                g_sfera_interface.options.saved_graphics[3] = event.first;
                g_sfera_graphics_runtime.grass_depth = event.first;
                optionText(window, 10u, graphicsBooleanLabel(event.first));
                break;
            case 24u:
                g_sfera_graphics_runtime.reflection_quality = event.first;
                optionText(window, 22u, g_sfera_interface.options.labels[4u - event.first]);
                break;
            case 26u:
                g_sfera_effect_manager.effects_enabled = event.first == 0u;
                optionText(window, 31u, event.first < 2u ? "" : graphicsBooleanLabel(event.first));
                break;
            case 34u:
                {
                    g_sfera_interface.options.saved_graphics[4] = event.first != 1u;
                    optionLabel(window, 35u, g_sfera_interface.options.saved_graphics[4] == 1u ? "UISTR_WT_OPT61" : "UISTR_WT_OPT62");
                    const auto selected = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(g_sfera_interface.options.saved_graphics[5]);
                    g_sfera_graphics_runtime.d3d_runtime->enumerateDisplayModes(g_sfera_interface.options.saved_graphics[4] == 1u);
                    g_sfera_interface.options.saved_graphics[5] = findOptionsMode(selected);
                    optionSelection(window, 15u, static_cast<std::uint32_t>(g_sfera_graphics_runtime.d3d_runtime->display_modes.size()) - 1u, g_sfera_interface.options.saved_graphics[5]);
                    setOptionsModeLabel(window, g_sfera_interface.options.saved_graphics[5]);
                    g_sfera_interface.options.saved_graphics[0] = 0u;
                    break;
                }
            case 39u:
                {
                    const bool automatic = event.first == 1u;
                    optionToggleLabel(window, 37u, automatic);
                    optionMessage(window, 28u, UiMessage::setScrollRange, 0u, automatic ? 0u : 170u);
                    if (automatic) graphics.saved_fog_distance = graphics.fog_distance;
                    else {
                        graphics.fog_distance = graphics.saved_fog_distance;
                        optionMessage(window, 28u, UiMessage::setScrollValue, static_cast<std::uint32_t>(static_cast<std::int64_t>(std::trunc(graphics.fog_distance - 30.0))));
                    }
                    g_sfera_graphics_runtime.auto_fog = automatic;
                    break;
                }
            case 43u:
                {
                    const bool enabled = event.first == 1u;
                    optionText(window, 41u, enabled ? g_sfera_interface.options.labels[6] : "");
                    optionMessage(window, 46u, UiMessage::setScrollRange, 0u, enabled ? 14u : 0u);
                    if (enabled) optionMessage(window, 46u, UiMessage::setScrollValue, static_cast<std::uint32_t>(static_cast<std::int64_t>(std::trunc(g_sfera_graphics_runtime.lod_distance - 12.0))));
                    graphics.lods_enabled = enabled;
                    break;
                }
            case 51u:
                g_sfera_interface.options.saved_graphics[6] = event.first;
                graphics.post_effects_enabled = event.first;
                optionText(window, 49u, event.first < 2u ? "" : graphicsBooleanLabel(event.first));
                break;
            default:
                break;
        } else if (event.message != UiMessage::horizontalScroll) return;
        if (event.control_id == 28u) graphics.fog_distance = event.first + 30.0;
        else if (event.control_id == 46u) g_sfera_graphics_runtime.lod_distance = event.first + 12.0;
    }

    void handleFontOptionsEvent(const WindowEvent& event) {
        if (event.message == UiMessage::selectedFontChanged) {
            if (event.control_id == 3u || event.control_id == 4u) editedChatFonts().at(event.control_id - 3u) = event.first;
            return;
        }
        if (event.message == UiMessage::leftClick) {
            if (event.control_id == 1u) savedChatFonts() = editedChatFonts();
            else if (event.control_id != 2u) return;
        } else if (event.message != UiMessage::close) return;
        setFontOptionsVisible(false);
    }
}

void SphereUI::Runtime::invokeEventHandler(WindowEventHandler handler, Window* window, const WindowEvent& event) {
    switch (handler) {
        case WindowEventHandler::none:
            return;
        case WindowEventHandler::description:
            if (window != nullptr) static_cast<CDescriptionWindow*>(window)->handleEvent(event);
            return;
        case WindowEventHandler::help:
            handleHelpEvent(window, event);
            return;
        case WindowEventHandler::authors:
            if (event.message == UiMessage::close && beginOptionsDialog("authors", handler, false) != nullptr) setOptionsVisible(true);
            return;
        case WindowEventHandler::quit:
            if (event.message == UiMessage::leftClick && event.control_id == 1u) SferaClientApplication::quit_requested = true;
            else if (event.message == UiMessage::close && beginOptionsDialog("quit", handler, false) != nullptr) setOptionsVisible(true);
            return;
        case WindowEventHandler::sound_options:
            handleSoundOptionsEvent(window, event);
            return;
        case WindowEventHandler::control_options:
            handleControlOptionsEvent(window, event);
            return;
        case WindowEventHandler::interface_options:
            handleInterfaceOptionsEvent(window, event);
            return;
        case WindowEventHandler::graphics_options:
            handleGraphicsOptionsEvent(window, event);
            return;
        case WindowEventHandler::font_options:
            handleFontOptionsEvent(event);
            return;
        case WindowEventHandler::options:
            if (event.message == UiMessage::close) setOptionsVisible(false);
            else if (event.message == UiMessage::leftClick) switch (event.control_id) {
                case 3u:
                    setGraphicsOptionsVisible(true);
                    break;
                case 4u:
                    setSoundOptionsVisible(true);
                    break;
                case 5u:
                    setControlOptionsVisible(true);
                    break;
                case 6u:
                    setInterfaceOptionsVisible(true);
                    break;
                case 7u:
                    beginOptionsDialog("authors", WindowEventHandler::authors, true);
                    break;
                case 8u:
                    beginOptionsDialog("quit", WindowEventHandler::quit, true);
                    break;
                default:
                    break;
            }
            return;
    }
}

