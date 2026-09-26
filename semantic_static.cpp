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
int SferaClientApplication::frame_samples{};
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
std::string SferaClientApplication::locale;
uint32_t SferaClientApplication::desktop_width{};
bool SferaClientApplication::application_active{};
SferaClientApplication::Lifecycle SferaClientApplication::lifecycle = SferaClientApplication::Lifecycle::Dormant;
bool SferaClientApplication::com_initialized = false;
bool SferaClientApplication::window_class_registered = false;
bool SferaClientApplication::fatal_error_in_progress{};
int SferaClientApplication::server_number{};
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
SceneSky::Motion SceneSky::motion{};
SferaVec3F SceneSky::previous_origin{};
SferaVec3F SceneSky::projected_offset{};
SferaVec3F SceneSky::projected_center{};
float SceneSky::texture_phase_v{};
float SceneSky::glow_samples[120]{};
float SceneSky::elevation_samples[120]{};
float SceneSky::texture_phase_u{};
bool SceneSky::sample_visible[120]{};
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
int SphereRender::SceneRenderer::texture_animation_frame{};
uint32_t SphereRender::SceneRenderer::secondary_pass{};
SferaIntBounds3 SphereRender::SceneRenderer::projected_terrain_bounds{};
SferaIntBounds3 SphereRender::SceneRenderer::clipped_terrain_bounds{};
uint8_t SphereRender::SceneRenderer::color_remap[256]{};
uint32_t SphereRender::SceneRenderer::fog_adaptation_delay{};
std::unique_ptr<SphereRender::CharacterModels> SphereRender::SceneRenderer::characters{};
std::unique_ptr<EnvironmentZones> SphereRender::SceneRenderer::environment_zones{};
std::unique_ptr<EnvironmentZones> SphereRender::SceneRenderer::alternate_environment_zones{};
int GameInterface::loading_completed{};
SferaScreenVertex GameInterface::sprite_quad[4]{};
uint32_t GameInterface::active_window{};
int GameInterface::loading_total{};
uint32_t GameInterface::loading_guard{};
std::string WorldDiagnostics::message;
uint32_t WorldGuiControls::text_height{};
uint32_t WorldGuiControls::text_width{};
std::array<TerrainTextureEntry, 50> TerrainTextureCache::entries{};
uint8_t TerrainTextureCache::quantization_x[3072]{};
uint8_t TerrainTextureCache::quantization_y[3072]{};
uint8_t TerrainTextureCache::blend_lut[16385]{};


std::string_view sfera_cursor_texture_name(uint32_t slot) {
    constexpr std::array<std::string_view, 4> names{"_cursor1", "_cursor2", "cursor2", "cursor1"};
    return slot < names.size() ? names[slot] : std::string_view{};
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
constexpr std::array<std::string_view, 9> kEffectFailureNames{
    "stopping", "active_limit", "sound_unavailable", "missing_definition", "factory",
    "filtered_type", "source_or_attachment", "listener", "allocation"
};
static_assert(kEffectFailureNames.size() == SferaNumeric::enumBits(SferaEffectManager::CreateFailure::Count));
}

void SferaEffectManager::reportError(std::string_view message) const {
    if (!message.empty()) std::fwrite(message.data(), 1u, message.size(), stderr);
    std::fputc('\n', stderr);
    ::OutputDebugStringA(std::string(message).c_str());
    ::OutputDebugStringA("\n");
    // Effect loading can continue after an error; preserve the reason in the existing client log.
    g_sfera_log_runtime.write("Effects: ");
    g_sfera_log_runtime.write(message);
    g_sfera_log_runtime.write("\n");
}
void SferaEffectManager::traceFailure(CreateFailure failure, std::uint32_t effect,
    std::uint32_t source, std::optional<std::string_view> name) noexcept {
    if (!diagnostics.enabled) return;
    const auto index = SferaNumeric::enumBits(failure);
    if (index >= diagnostics.failures.size()) return;
    ++diagnostics.failures[index];
    if (diagnostics.details_written >= 24u) return;
    ++diagnostics.details_written;
    try {
        auto message = std::format(
            "EffectDiag reject={} id={} source={} name={:.128} filter={} definitions={} active={}\n",
            kEffectFailureNames[index], effect, source, name.value_or("-"), effects_enabled, definitions.size(), active_effects.size());
        g_sfera_log_runtime.write(message);
    } catch (...) {
        // A diagnostic failure must not change the effect creation result.
    }
}

void SferaEffectManager::traceEffect(std::string_view event, const SferaActiveEffect& item) noexcept {
    if (!diagnostics.enabled || !item.effect) return;
    try {
        const auto& effect = *item.effect;
        const auto position = item.position_source == 0
            ? g_sfera_world_objects.objectPosition(item.source_handle) : item.position;
        auto message = std::format(
            "EffectDiag {} id={} source={} name={:.96} age={} lifetime={} cycle={} flags={} blocked={} deactivated={} "
            "distance={:.3f} position={:.3f},{:.3f},{:.3f}\n",
            event, item.listener_key, item.source_handle, effect.script_name, item.age_ticks, effect.lifetime_ticks, effect.cycle_length,
            item.state_flags, effect.activation_blocked, effect.deactivated, item.viewer_distance,
            position.x, position.y, position.z);
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
            const auto* scripted = definition != nullptr ? definition->asScriptedEffect() : nullptr;
            if (scripted && scripted->definition) {
                if (!scripted->definition->particles.empty()) ++particleDefinitions;
                if (!scripted->definition->lights.empty()) ++lightDefinitions;
            }
        }
        const auto liveLights = std::count_if(g_sfera_light_runtime.handles.begin(),
            g_sfera_light_runtime.handles.end(), [](const auto& light) { return light != nullptr; });
        const auto& fog = SphereRender::SceneRenderer::environment.fogParameters;
        auto message = std::format(
            "EffectDiag sample={} ticks={} defs={} particle_defs={} light_defs={} vm={} requests={} created={} "
            "active={} updates={} far={} frustum={} activation={} daytime={} budget={} expired={} render={} slots={} "
            "submitted_quads={} alpha_vertices={} lights={} visible_lights={} light_enables={} fog={:.3f},{:.3f} "
            "filter={}\n",
            diagnostics.samples, now, definitions.size(), particleDefinitions,
            lightDefinitions, diagnostics.vm_requests, diagnostics.create_requests,
            diagnostics.created, active_effects.size(), diagnostics.updates,
            diagnostics.distance_culled, diagnostics.frustum_culled,
            diagnostics.activation_rejected, diagnostics.daytime_rejected,
            diagnostics.budget_rejected, diagnostics.expired,
            diagnostics.render_calls, render_slot_count,
            diagnostics.submitted_quads, diagnostics.alpha_vertices,
            liveLights, g_sfera_light_runtime.visible_handles.size(),
            diagnostics.light_activations, fog.y, fog.z, effects_enabled);
        g_sfera_log_runtime.write(message);
        for (std::size_t index = 0; index < diagnostics.failures.size(); ++index) {
            if (diagnostics.failures[index] == 0) continue;
            message = std::format("EffectDiag failures {}={}\n", kEffectFailureNames[index], diagnostics.failures[index]);
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
    if (handle < 0 || handle >= handles.size()) return nullptr;
    return handles[handle].get();
}
int SferaLightRuntime::create(const SferaVec3F& position, const float* color, float radius) {
    if (color == nullptr) return -1;
    const auto slot = std::find(handles.begin(), handles.end(), nullptr);
    if (slot == handles.end()) return -1;
    auto light = std::unique_ptr<SferaLightRecord>(new (std::nothrow) SferaLightRecord{});
    if (light == nullptr) return -1;
    light->update(position, color, radius);
    *slot = std::move(light);
    return slot - handles.begin();
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
    handles[handle].reset();
}

void SferaEffectManager::appendDefinition(std::shared_ptr<IEffect> effect) {
    if (effect != nullptr) definitions.push_back(std::move(effect));
}

std::shared_ptr<IEffect> SferaEffectManager::findDefinition(uint32_t effect_id) const {
    const auto found = std::find_if(definitions.begin(), definitions.end(), [&](const auto& effect) { return effect->effect_id == effect_id; });
    return found == definitions.end() ? nullptr : *found;
}

std::shared_ptr<IEffect> SferaEffectManager::findDefinition(std::string_view script_name) const {
    const auto found = std::find_if(definitions.begin(), definitions.end(), [&](const auto& effect) {
        return !effect->script_name.empty() && SferaText::asciiEqual(script_name, effect->script_name);
    });
    return found == definitions.end() ? nullptr : *found;
}

std::uint32_t SferaEffectManager::findDefinitionId(std::string_view script_name) const {
    const auto effect = findDefinition(script_name);
    return effect != nullptr ? effect->effect_id : UINT32_MAX;
}

namespace {

void initialize_particle_random_table(SferaEffectManager& manager) {
    const auto seed = SferaNumeric::lowWord(std::chrono::steady_clock::now().time_since_epoch().count());
    std::srand(seed);
    for (auto& value : manager.particle_random_table) value = std::rand();
    std::srand(SferaNumeric::lowWord(std::chrono::steady_clock::now().time_since_epoch().count()));
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
    auto* rain = effect.asRainEffect();
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
    auto* scripted = effect.asScriptedEffect();
    if (scripted == nullptr) { g_sfera_effect_manager.reportError("Unknown effect classID for lighting."); return false; }
    lighting_effect = scripted;
    if (g_sfera_world_objects.controlled_object_handle != kInvalidHandle) { effect.cycle_length = SferaNumeric::truncatedWord((1.0f - lighting_level) * 640.0f + 320.0f); effect.lifetime_ticks = kInvalidHandle; }
    lighting_listener.change_tick = 1u; return true;
}

void SferaNatureManager::detachLightingEffect() { lighting_effect = nullptr; }

void SferaNatureManager::onLightingEffectChanged(IEffect& effect, SferaActiveEffect& item) {
    if (effect.effect_kind != IEffect::Kind::Scripted) return;
    auto* scripted = effect.asScriptedEffect();
    if (scripted == nullptr || scripted->lights.empty() || scripted->particle_systems.empty()) return;
    auto& particle = *scripted->particle_systems[0]; if (particle.render_slots.empty()) return;
    const SferaVec3F source = g_sfera_world_objects.objectPosition(item.source_handle); const SferaVec3F emitter = particle.render_slots[0].state.position; auto& light = scripted->lights[0]; light.position = {emitter.x - source.x, emitter.y - source.y, emitter.z - source.z};
    const float distance = std::sqrt(light.position.x * light.position.x + light.position.y * light.position.y + light.position.z * light.position.z); g_sfera_effect_manager.createActiveEffect(distance < 15.0f ? kLightingSoundNearId : kLightingSoundFarId, item.source_handle);
}

void SferaNatureManager::startRain() { if (rain_effect_handle == nullptr && g_sfera_world_objects.controlled_object_handle != kInvalidHandle) rain_effect_handle = g_sfera_effect_manager.createActiveEffect(kRainEffectId, g_sfera_world_objects.controlled_object_handle); }
void SferaNatureManager::stopRain() { remove_nature_effect_handle(rain_effect_handle); for (auto& handle : ambient_rain_handles) remove_nature_effect_handle(handle); }
void SferaNatureManager::startLighting() { if (lighting_effect_handle == nullptr && g_sfera_world_objects.controlled_object_handle != kInvalidHandle) lighting_effect_handle = g_sfera_effect_manager.createActiveEffect(kLightingEffectId, g_sfera_world_objects.controlled_object_handle); }
void SferaNatureManager::stopLighting() { remove_nature_effect_handle(lighting_effect_handle); }

void SferaNatureManager::setRainIntensity(float value) { if (rain_effect == nullptr || g_sfera_world_objects.controlled_object_handle == kInvalidHandle) return; rain_intensity = value; rain_effect->spawn_rate = rain_intensity * rain_scale; updateAmbientRainEffects(); }
void SferaNatureManager::setLightingLevel(float value) { if (lighting_effect == nullptr || g_sfera_world_objects.controlled_object_handle == kInvalidHandle) return; lighting_level = value; lighting_effect->cycle_length = SferaNumeric::truncatedWord((1.0f - lighting_level) * 640.0f + 320.0f); lighting_effect->lifetime_ticks = kInvalidHandle; }

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

void SferaEffectManager::registerEffectMeshFile(const std::string& filename) {
    std::ifstream stream;
    for (const auto& path : g_sfera_files.candidatePaths(filename)) {
        stream.open(path, std::ios::binary);
        if (stream.is_open()) break;
        stream.clear();
    }
    if (!stream.is_open()) return;
    stream.seekg(0, std::ios::end);
    const std::streamoff file_size = stream.tellg();
    std::vector<std::uint8_t> bytes;
    if (file_size < 0 || std::cmp_greater(file_size, std::numeric_limits<std::streamsize>::max())
        || std::cmp_greater(file_size, bytes.max_size())) return;
    bytes.resize(file_size);
    stream.seekg(0, std::ios::beg);
    if (!bytes.empty() && !SferaBinary::read(stream, bytes)) return;
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
            SferaBinary::Reader payload(reader.take(payload_size));
            mesh->vertices.resize(vertex_count);
            mesh->colors.resize(vertex_count);
            mesh->uv.resize(uv_count);
            mesh->faces.resize(face_count);
            for (auto& vertex : mesh->vertices) vertex = {read_real(payload), read_real(payload), read_real(payload)};
            payload.take(skipped_vertex_count * 12);
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
    const int work = std::max(GameInterface::loading_total - 80, 1);
    int percent = GameInterface::loading_completed * 100 / work;
    percent = std::min(percent, 100);
    if (percent == g_sfera_graphics_runtime.rebuild_percent) return;
    g_sfera_graphics_runtime.rebuild_percent = percent;
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
    const auto enumerate = [&](const fs::path& directory, std::string_view extension, auto&& callback) {
        if (!fs::exists(directory, error)) return;
        for (const auto& entry : std::filesystem::directory_iterator(directory, error)) {
            if (error || !entry.is_regular_file(error)) continue;
            if (SferaText::asciiEqual(entry.path().extension().string(), extension)) callback(entry.path());
        }
    };
    enumerate("Effects", ".ssm", [&](const fs::path& path) { const std::string value = path.string(); registerEffectMeshFile(value); });
    std::uint32_t total_count = 0u; enumerate("Effects", ".sef", [&](const fs::path&) { ++total_count; }); enumerate("Players", ".sef", [&](const fs::path&) { ++total_count; });
    const auto initial_count = definitions.size();
    std::uint32_t processed_count = 0u;
    const auto load_group = [&](const fs::path& directory) {
        enumerate(directory, ".sef", [&](const fs::path& path) {
            auto effect = std::make_shared<CScriptedEffect>();
            effect->initializeScriptedState();
            try {
                if (effect->loadScript(path.string())) appendDefinition(std::move(effect));
            } catch (const std::logic_error& error) {
                reportError(path.string() + ": " + error.what());
            }
            ++processed_count;
            const std::uint32_t progress = total_count == 0u ? 30u : SferaNumeric::lowWord(std::uint64_t{processed_count} * 30u / total_count);
            reportLoadProgress(progress);
        });
    };
    load_group("Effects"); load_group("Players");
    const auto loaded_count = definitions.size() - initial_count;
    const auto status = "Effects: loaded " + std::to_string(loaded_count) + " of " + std::to_string(total_count)
        + " SEF files from " + fs::current_path(error).string() + "\n";
    ::OutputDebugStringA(status.c_str());
    g_sfera_log_runtime.write(status);
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
                effect.initializePreset(lake_ids[index], 5.0f * (index + 1), kFixedLakeFlags);
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

SferaActiveEffect* SferaEffectManager::createActiveEffect(std::string_view script_name, std::uint32_t source_handle) {
    const auto definition = findDefinition(script_name);
    if (definition != nullptr && definition->effect_id > 0u) return createActiveEffect(definition->effect_id, source_handle);
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
        effect->queryEffectState({frames.positions, SferaNumeric::real32(item.age_ticks)});
        return;
    }
    if (effect->deactivated) effect->renderEffect();
    effect->initializeEffect({frames.positions, SferaNumeric::real32(item.age_ticks), visible, frames.transforms});
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
                    else item.state_flags &= 0xFFFDu;
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
SferaGraphicsRuntime g_sfera_graphics_runtime{.fog_distance = 100.0f, .saved_fog_distance = 50.0f, .lods_enabled = 1u, .hardware_cursor_enabled = 1u, .environment_factor = 0.8500000238418579f, .base_microtexture_id = UINT16_MAX, .view_scale = 1.0f, .post_effects_enabled = 1u, .rebuild_percent = -1};
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
auto openLogFile(const std::string& path, const std::string& mode) {
        FILE* file = nullptr;
        if (fopen_s(&file, path.c_str(), mode.c_str()) != 0) file = nullptr;
        return std::unique_ptr<FILE, decltype(&std::fclose)>(file, &std::fclose);
    }
unsigned mbc_field_minimum_bits(std::int8_t format) {
        const auto value = std::abs(+format);
        if (value <= 32) return value;
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
void COutputLogDevice::setFilename(const std::string& path) {
    filename = path;
    if (filename.empty()) return;
    auto file = openLogFile(filename, "wt");
    if (!file) return;
    const auto now = std::time(nullptr);
    std::string created_at(32, '\0');
    if (ctime_s(created_at.data(), created_at.size(), &now) != 0) created_at.clear();
    else created_at.resize(created_at.find('\0'));
    std::fprintf(file.get(), "Sphere log file\nCreated: %s\n", created_at.c_str());
}
void COutputLogDevice::write(std::string_view text) {
    if (filename.empty()) return;
    auto file = openLogFile(filename, "a+t");
    if (!file) return;
    std::fputs("- ", file.get());
    if (!text.empty()) std::fwrite(text.data(), 1u, text.size(), file.get());
    std::fputc('\n', file.get());
}
void CSphereError::write(std::string_view text) {
    SferaClientApplication::terminateWithError(text);
}
void SferaLogRuntime::write(std::string_view text) {
    if (path.empty()) return;
    auto file = openLogFile(path, "at");
    if (!file) return;
    if (!text.empty()) std::fwrite(text.data(), 1u, text.size(), file.get());
    std::fflush(file.get());
}
void SferaLogRuntime::write(int number) {
    const std::string line = std::to_string(number) + '\n';
    write(line);
}
SferaInputDevices::SferaInputDevices() = default;
SferaInputDevices::~SferaInputDevices() { release(); }

void SferaInputDevices::initialize(HWND window) {
    release();
    const auto require = [](HRESULT result, std::string_view operation) { if (FAILED(result)) WorldDiagnostics::fail(operation); };
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
    DIPROPDWORD buffering{};
    buffering.diph.dwSize = SferaNumeric::lowWord(sizeof(buffering));
    buffering.diph.dwHeaderSize = SferaNumeric::lowWord(sizeof(buffering.diph));
    buffering.diph.dwHow = DIPH_DEVICE;
    buffering.dwData = 8u;
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
        [&] { return keyboard_device->GetDeviceState(state.size(), state.data()); },
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
    SferaMouseInputState output{};
    output.dx = state.lX;
    output.dy = state.lY;
    output.buttons = ((state.rgbButtons[primary] & SferaInputDevices::pressedMask) != 0u ? 1u : 0u) | ((state.rgbButtons[1u - primary] & SferaInputDevices::pressedMask) != 0u ? 2u : 0u);
    output.wheel = state.lZ / WHEEL_DELTA;
    return output;
}



void WorldDiagnostics::appendScriptContext(std::string_view text) {
    WorldDiagnostics::message.append(text);
}

void WorldDiagnostics::flushScriptContext() {
    if (const auto context = scriptContext()) {
        appendScriptContext("\n");
        appendScriptContext(*context);
    }
    warning(WorldDiagnostics::message);
    appendScriptContext("\n\n");
}

std::uint32_t WorldDiagnostics::inspectInstruction(std::uint16_t& module, std::uint32_t& offset, std::uint8_t* bytes, std::uint32_t& count) {
    module = std::numeric_limits<std::int16_t>::max();
    offset = 0u;
    const auto& vm = g_sfera_mbc_runtime;
    if (vm.process_index < 0 || std::cmp_greater_equal(vm.process_index, std::size(vm.processes))) { count = 0u; return 1u; }
    const auto& process = vm.processes[vm.process_index];
    const auto mismatch = vm.bytecode_base != process.codeData() ? codeBaseMismatch : 0u;
    const std::less<const std::uint8_t*> before;
    if (!process.codeData() || !vm.current_instruction_address || before(vm.current_instruction_address, process.codeData()) || !before(vm.current_instruction_address, process.codeData() + process.codeSize())) { count = 0u; return mismatch | 3u; }
    const std::uint32_t relative = SferaNumeric::lowWord(vm.current_instruction_address - process.codeData());
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
    output.clear();
    if (includeTime) {
        const auto now = std::time(nullptr);
        std::tm local{};
#ifdef _WIN32
        localtime_s(&local, &now);
#else
        localtime_r(&now, &local);
#endif
        output = std::format("{:02}:{:02}:{:02} ", local.tm_hour, local.tm_min, local.tm_sec);
    }
    std::uint16_t module;
    std::uint32_t offset, count = 16;
    std::uint8_t bytes[16];
    const auto status = inspectInstruction(module, offset, bytes, count);
    if ((status & ~codeBaseMismatch) == 1) { output.append("PrcName,CodeOffs: unknown. (wrong pos)"); return; }
    if ((status & ~codeBaseMismatch) == 2) { output.append("PrcName,CodeOffs: unknown. (modulesNum == MAX_MODULES_IN_PRC)"); return; }
    if ((status & ~codeBaseMismatch) == 3) { output.append("PrcName,CodeOffs: unknown. (Offset not found)"); return; }
    std::string text;
    if (status & codeBaseMismatch) text = std::format(
        "Warn!!! pos = {}, sBaseCodePtr = {:p}, Prc[pos].baseCodePtr = {:p}. ",
        vm.process_index, static_cast<const void*>(vm.bytecode_base),
        static_cast<const void*>(vm.processes[vm.process_index].codeData()));
    else text = std::format("module:{}, code:{}. ", module, offset);
    output.append(text);
    for (std::uint32_t index = 0; index < count; ++index) {
        text = std::format("{:x} ", bytes[index]);
        output.append(text);
    }
    output.append("\n");
}

void WorldDiagnostics::appendCallStack(std::string& output) {
    const auto& vm = g_sfera_mbc_runtime;
    std::string text;
    for (auto index = vm.execution_context_depth - 1; index >= 0; --index) {
        const auto& context = vm.execution_context_stack[index];
        if (context.process_index < 0) { text += "\nCall from C++\n"; continue; }
        if (context.process_index < 0 || std::cmp_greater_equal(context.process_index, std::size(vm.processes))) { text += "\nInvalid call context\n"; break; }
        const auto& process = vm.processes[context.process_index];
        if (context.process_id != process.process_id) { text += "\nError in prc call stack\n"; break; }
        if (context.process_lifetime != process.lifetime || context.program_index < 0 || context.program_index >= process.programs.size()) { text += "\nExpired call context\n"; break; }
        const auto& program = process.programs[context.program_index];
        text += "\nPrevious prc: "; text += process.name; text += "\nProgram: "; text += program.name; text += '\n';
    }
    output.append(text);
}

std::optional<std::string_view> WorldDiagnostics::scriptContext() {
    if (g_sfera_mbc_runtime.dispatch_slot < 0) return std::nullopt;
    auto& vm = g_sfera_mbc_runtime;
    describeScript(true);
    const auto& program = vm.program_table_base[vm.program_index];
    auto message = std::format(
        "MBC-file: {}\nProgram: {}\nCall's depth: {}\nAddress: 0x{:08X}\n",
        vm.processes[vm.process_index].name, program.name, program.callDepth,
        (vm.current_instruction_address - vm.bytecode_base) + 32u);
    vm.diagnostic_context.append(message);
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
            g_sfera_direct_input_runtime.binding_key = SferaNumeric::lowWord(wparam);
            return 0;
        }
        if (g_sfera_direct_input_runtime.text_filter != 0u) {
            const std::uint32_t key = SferaNumeric::lowWord(wparam);
            if (key < 256u && g_sfera_font_runtime.glyphs[key].defined != 0u && g_sfera_direct_input_runtime.allowed_glyphs[key] == 0u) {
                return 0;
            }
        }
        if (g_sfera_direct_input_runtime.key_queue.size() < 30u) {
            g_sfera_direct_input_runtime.key_queue.push_back(SferaNumeric::lowWord(wparam));
        }
        return 0;
    case WM_CHAR: {
        const std::uint32_t ch = SferaNumeric::lowWord(wparam);
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
    windowClass.cbSize = SferaNumeric::lowWord(sizeof(windowClass));
    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpfnWndProc = &main_window_proc;
    windowClass.hInstance = SferaClientApplication::instance_handle;
    windowClass.hIcon = ::LoadIconA(windowClass.hInstance, MAKEINTRESOURCEA(113));
    windowClass.hCursor = ::LoadCursorW(nullptr, IDC_ARROW);
    windowClass.hbrBackground = reinterpret_cast<HBRUSH>(::GetStockObject(BLACK_BRUSH));
    windowClass.lpszClassName = nativeWindowClassName.data();
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
    graphics.display_width = std::max(800, graphics.display_width);
    graphics.display_height = std::max(600, graphics.display_height);
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
    const auto window = ::CreateWindowExA(0, nativeWindowClassName.data(), "Sphere", style, left, top, width, height, nullptr, nullptr, instance, nullptr);
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
        std::string input(1u, '\0');
        for (std::size_t byte = 0; byte < result.size(); ++byte) {
            std::as_writable_bytes(std::span(input)).front() = std::byte{SferaNumeric::lowByte(byte)};
            wchar_t character = 0;
            if (::MultiByteToWideChar(1251u, 0u, input.data(), 1, &character, 1) != 1) character = byte;
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
            result[byte] = found == unicode.end() ? byte : found - unicode.begin();
        }
        return result;
    }();
    return table;
}
std::string SferaText::resourceKey(std::string_view name) {
    std::string result(name);
    const auto& lowercase = lowercaseCp1251();
    transformBytes(result, [&](std::uint8_t byte) { return lowercase[byte]; });
    return result;
}

std::size_t SferaText::findInsensitive(std::string_view text, std::string_view needle) {
    if (needle.empty()) return std::string_view::npos;
    const auto found = std::search(text.begin(), text.end(), needle.begin(), needle.end(),
        [](std::uint8_t first, std::uint8_t second) { return asciiFold(first) == asciiFold(second); });
    return found == text.end() ? std::string_view::npos : found - text.begin();
}

std::string_view SferaText::fileName(std::string_view path) {
    const auto separator = path.find_last_of('\\');
    return path.substr(separator == std::string_view::npos ? 0 : separator + 1);
}

namespace {
    template<class Fold> int compareText(std::string_view first, std::string_view second, Fold fold) {
        const auto count = std::min(first.size(), second.size());
        for (std::size_t index = 0; index < count; ++index) {
            const auto difference = fold(SferaText::byteValue(first[index])) - fold(SferaText::byteValue(second[index]));
            if (difference != 0) return difference;
        }
        if (first.size() == second.size()) return 0;
        return first.size() > count ? fold(SferaText::byteValue(first[count])) : -fold(SferaText::byteValue(second[count]));
    }
}
int SferaText::compare(std::string_view first, std::string_view second) {
    return compareText(first, second, [](std::uint8_t value) { return value; });
}
int SferaText::compareInsensitive(std::string_view first, std::string_view second) {
    return compareText(first, second, [](std::uint8_t value) { return std::tolower(value); });
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
    const auto offset = (address - entry->first);
    const auto& region = entry->second;
    const auto size = region.process ? std::min(region.size, region.process->memory.size()) : region.size;
    if (offset > size) throw std::out_of_range("Invalid mapped memory range");
    return {memoryAt(address, size - offset), size - offset};
}
std::span<std::uint8_t> SferaMbcRuntime::memoryBytes(std::uint32_t address, std::size_t count, SferaMbcProcessRecord* process) const {
    if (count == 0) return {};
    return {memoryAt(address, count, process), count};
}

SferaText::Buffer SferaMbcRuntime::textBufferAt(std::uint32_t address, SferaMbcProcessRecord* process) const {
    return SferaText::Buffer(memoryRange(address, process));
}

std::uint64_t SferaMbcRuntime::memoryLifetime(std::uint32_t address) const {
    if (address < mappedAddressBegin) return 0;
    auto entry = mapped_memory.upper_bound(address);
    if (entry == mapped_memory.begin()) throw std::out_of_range("Unknown mapped memory lifetime");
    --entry;
    if (address - entry->first >= entry->second.size) throw std::out_of_range("Invalid mapped memory lifetime");
    return entry->second.lifetime;
}
std::span<std::uint8_t> SferaMbcRuntime::sliceBytes(const SferaSliceReference32& slice, SferaMbcProcessRecord* process) const {
    auto bytes = memoryRange(slice.base, process);
    if (slice.begin != 0) {
        if (slice.base < slice.begin || slice.base > slice.end) throw std::out_of_range("Invalid bounded script slice");
        const std::uint64_t end = slice.end;
        const auto count = end - slice.base + 1;
        if (count < bytes.size()) bytes = bytes.first(count);
    }
    return bytes;
}

std::span<std::uint8_t> SferaMbcRuntime::sliceBytes(const SferaSliceReference32& slice, std::size_t count, SferaMbcProcessRecord* process) const {
    if (count == 0) return {};
    return SferaBinary::range(sliceBytes(slice, process), 0, count);
}

SferaText::Buffer SferaMbcRuntime::textBuffer(const SferaSliceReference32& slice, SferaMbcProcessRecord* process) const {
    return SferaText::Buffer(sliceBytes(slice, process));
}

std::string SferaMbcRuntime::textIn(const SferaSliceReference32& slice, SferaMbcProcessRecord* process) const {
    // Preserve the MBC string ABI: the declared extent may exclude the NUL or
    // describe an addressed element. The owning memory region is the hard boundary.
    return SferaText::terminated(memoryRange(slice.base, process));
}

std::string SferaMbcRuntime::textIn(const SferaSliceReference32& slice, std::size_t limit, SferaMbcProcessRecord* process) const {
    if (limit == 0) return {};
    return SferaText::prefix(memoryRange(slice.base, process), limit);
}

std::string SferaMbcRuntime::textAt(std::uint32_t address) const {
    return textIn({address, 0, 0});
}
std::string SferaMbcRuntime::textAt(std::uint32_t address, std::size_t limit) const {
    return textIn({address, 0, 0}, limit);
}

std::uint32_t SferaMbcRuntime::addMemoryRegion(MemoryRegion region) {
    region.size = std::max<std::size_t>(region.size, 1);
    if (region.size >= mappedAddressBegin) throw std::length_error("Mapped script region too large");
    std::uint64_t candidate = mappedAddressBegin;
    for (const auto& [address, existing] : mapped_memory) {
        if (candidate + region.size < address) break;
        std::uint64_t candidate_address = address;
        candidate_address += existing.size + 1;
        candidate = candidate_address;
    }
    if (candidate + region.size > UINT32_MAX - 3u) throw std::length_error("Script address space exhausted");
    const std::uint32_t address = SferaNumeric::lowWord(candidate);
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
        if (address >= base && address - base <= active_process->memory.size() && size <= active_process->memory.size() - (address - base)) return SferaNumeric::lowWord(address - base);
    }
    for (const auto& [mapped, region] : mapped_memory) {
        const auto* source = region.process != nullptr ? region.process->memory.data() : region.data;
        const auto base = reinterpret_cast<std::uintptr_t>(source);
        if (source != nullptr && address >= base && address - base <= region.size && size <= region.size - (address - base)) return mapped + SferaNumeric::lowWord(address - base);
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
    std::string message;
    if (length == 0) message = std::format(
        "{}\n Slice out of range! ptr = {}, begin = {}, end = {}",
        g_sfera_mbc_runtime.diagnostic_context, SferaNumeric::signedWord(base), SferaNumeric::signedWord(begin), SferaNumeric::signedWord(end + 1));
    else message = std::format(
        "{}\n Slice out of range! ptr = {}, ptr+offset = {}, begin = {}, end = {}",
        g_sfera_mbc_runtime.diagnostic_context, SferaNumeric::signedWord(base), SferaNumeric::signedWord(base + length), SferaNumeric::signedWord(begin),
        SferaNumeric::signedWord(end + 1));
    WorldDiagnostics::warning(message);
    // The interpreter diagnoses and extends the recorded bounds; it does not clamp the pointer.
    if (base == 0 || begin == 0 || (base >= begin && base <= end)) return;
    if (SferaNumeric::signedWord(base) < SferaNumeric::signedWord(begin)) begin = base;
    else if (SferaNumeric::signedWord(base + length - 1) > SferaNumeric::signedWord(end)) end = base + length - 1;
}
bool SferaMbcValue::isPointer() const { return type % 16 != 0; }
std::int32_t SferaMbcValue::integer() const {
    std::int32_t result{};
    std::memcpy(&result, &value.base, sizeof(result));
    return result;
}
float SferaMbcValue::real() const {
    float result{};
    std::memcpy(&result, &value.base, sizeof(result));
    return result;
}
std::int32_t SferaMbcValue::truncate(double number) {
    constexpr double minimum = INT32_MIN;
    constexpr double maximumExclusive = double{INT32_MAX} + 1.0;
    if (!std::isfinite(number) || number < minimum || number >= maximumExclusive) return INT32_MIN;
    return number;
}
std::int32_t SferaMbcValue::asInteger() const {
    switch (type) {
        case Byte: {
            const std::uint8_t byte = value.base & 0xffu;
            std::int8_t signedByte{};
            std::memcpy(&signedByte, &byte, sizeof(byte));
            return signedByte;
        }
        case Real: return truncate(real());
        default: return integer();
    }
}
std::uint32_t SferaMbcValue::asWord() const {
    const std::int32_t number = asInteger();
    std::uint32_t result{};
    std::memcpy(&result, &number, sizeof(result));
    return result;
}
float SferaMbcValue::asReal() const {
    if (type == Real) return real();
    const std::int32_t number = asInteger();
    return number;
}
void SferaMbcValue::setReal(float number) {
    std::memcpy(&value.base, &number, sizeof(number));
}
void SferaMbcValue::setReal(double number) { setReal(SferaNumeric::real32(number)); }
void SferaMbcValue::detach() { source = {UINT32_MAX, 1, 1}; }
SferaSliceReference32& SferaMbcValue::asSlice() { if (!isPointer()) value.begin = value.end = 0; return value; }

bool SferaMbcRuntime::reportError(std::string_view message) {
    WorldDiagnostics::scriptContext();
    if (first_execution_error.empty()) first_execution_error = std::format("{}\n{}", message, diagnostic_context);
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
bool SferaMbcRuntime::reportError(std::string_view prefix, std::string_view suffix) { return reportError(std::format("{}{}", prefix, suffix)); }
std::int32_t SferaMbcRuntime::popInteger() {
    if (call_frame_depth < 0 || call_frame_depth >= std::ssize(frame_stack_base) || value_stack_size <= frame_stack_base[call_frame_depth]) { reportError("popint(): stack underflow"); return 0; }
    return g_sfera_mbc_runtime.values[--value_stack_size].asInteger();
}
std::uint32_t SferaMbcRuntime::popWord() {
    if (call_frame_depth < 0 || call_frame_depth >= std::ssize(frame_stack_base) || value_stack_size <= frame_stack_base[call_frame_depth]) { reportError("popint(): stack underflow"); return 0u; }
    return g_sfera_mbc_runtime.values[--value_stack_size].asWord();
}
SferaSliceReference32& SferaMbcRuntime::popSlice() {
    if (call_frame_depth < 0 || call_frame_depth >= std::ssize(frame_stack_base) || value_stack_size <= frame_stack_base[call_frame_depth]) { reportError("popsliceref(): stack underflow"); g_sfera_mbc_runtime.slice_fallback = {}; return g_sfera_mbc_runtime.slice_fallback; }
    return g_sfera_mbc_runtime.values[--value_stack_size].asSlice();
}
std::int32_t SferaMbcRuntime::nextInteger() {
    if (argument_cursor >= argument_end) { reportError("Too few parameters"); return 0; }
    return g_sfera_mbc_runtime.values[argument_cursor++].asInteger();
}
std::uint32_t SferaMbcRuntime::nextWord() {
    if (argument_cursor >= argument_end) { reportError("Too few parameters"); return 0u; }
    return g_sfera_mbc_runtime.values[argument_cursor++].asWord();
}
float SferaMbcRuntime::nextReal() {
    if (argument_cursor >= argument_end) { reportError("Too few parameters"); return 0; }
    return g_sfera_mbc_runtime.values[argument_cursor++].asReal();
}
SferaSliceReference32& SferaMbcRuntime::nextSliceReference(std::string_view diagnostic) {
    if (argument_cursor >= argument_end) { reportError(diagnostic); g_sfera_mbc_runtime.sliceup_fallback = {}; return g_sfera_mbc_runtime.sliceup_fallback; }
    return g_sfera_mbc_runtime.values[argument_cursor++].asSlice();
}
SferaSliceReference32 SferaMbcRuntime::nextSlice() { return nextSliceReference("popsliceup(): stack underflow"); }
SferaSliceReference32 SferaMbcRuntime::nextAddress() {
    if (argument_cursor >= argument_end) { reportError("Too few parameters"); return {}; }
    const auto& argument = values[argument_cursor++];
    if (argument.isPointer()) return argument.value;
    return {argument.asWord(), 0, 0};
}
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
void SferaMbcRuntime::pushReal(double number) { pushReal(SferaNumeric::real32(number)); }
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
void SferaMbcProcessRecord::linkProgram(std::size_t index) {
    auto& program = programs.data()[index];
    const std::int16_t previous = program_map_b[program.priority];
    if (previous < 0) { program_map_a[program.priority] = index; program.previous_program = index; }
    else { programs.data()[previous].next_program = index; program.previous_program = previous; }
    program_map_b[program.priority] = index;
    program.next_program = index;
    programs_queued = true;
    g_sfera_mbc_runtime.enqueueProcess(process_id, *this);
}
bool SferaMbcProcessRecord::activateProgram(std::size_t index) {
    if (index >= programs.size() || programs.data() == nullptr) return false;
    auto& program = programs.data()[index];
    if (program.state != 1) { linkProgram(index); program.instruction_offset = program.entry_offset; }
    program.state = 1;
    programs_queued = true;
    return true;
}
bool SferaMbcProcessRecord::activateProgram(std::string_view name) {
    if (programs.empty()) return false;
    for (std::size_t index = 0; index < programs.size(); ++index) {
        if (programs[index].name != name) continue;
        activateProgram(index);
        g_sfera_mbc_runtime.enqueueProcess(process_id, *this);
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
            const std::uint32_t width = type == SferaMbcValue::Byte ? std::uint32_t{sizeof(std::int8_t)} : type == SferaMbcValue::Integer || type == SferaMbcValue::Real ? std::uint32_t{sizeof(std::uint32_t)} : std::uint32_t{sizeof(SferaSliceReference32)};
            pushReference(type, {offset, offset, offset + width - 1u}, true);
            if (type == SferaMbcValue::Address) stack[value_stack_size - 1].value = readMemory<SferaSliceReference32>(offset);
            break;
        }
        case Instruction::JumpIfFalse: case Instruction::JumpIfFalseShort: {
            const auto condition = popInteger();
            const std::ptrdiff_t width = instruction == Instruction::JumpIfFalse ? sizeof(int) : sizeof(std::int16_t);
            if (condition) instruction_cursor += width;
            else { const auto offset = instruction == Instruction::JumpIfFalse ? readOperand<int>() : readOperand<std::int16_t>(); instruction_cursor += offset - width; }
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
            const auto count = signedCount < 0 ? 0u - SferaNumeric::word(signedCount) : SferaNumeric::word(signedCount);
            if (index < 0 || std::cmp_greater_equal(index, count)) {
                WorldDiagnostics::describeScript(true);
                auto message = std::format(
                    "{}\n{} boundary error: array size = {}, index = {}",
                    diagnostic_context, source ? "Array2" : "Array", count, index);
                WorldDiagnostics::warning(message);
                const auto last = SferaNumeric::signedWord(count - 1u);
                if (source) index = index >= 0 && last < 0 ? 0 : last;
                else index = index < 0 ? 0 : last;
            }
            const auto displacement = SferaNumeric::word(stride) * SferaNumeric::word(index);
            if (source) { source->base += displacement; pushReference(type, *source, signedCount < 0); }
            else { const auto element = offset + displacement; pushReference(type, {element, element, element + width - 1}, signedCount < 0); }
            break;
        }
        case Instruction::PointerElement: case Instruction::FieldValue: case Instruction::FieldSlice: {
            const auto type = readOperand<SferaMbcValue::Type>();
            const auto stride = instruction == Instruction::PointerElement ? readOperand<std::uint16_t>() : 0;
            auto& source = popSlice();
            source.base += instruction == Instruction::PointerElement ? SferaNumeric::word(stride) * SferaNumeric::word(popInteger()) : readOperand<std::uint16_t>();
            if (source.begin != 0 && (source.base < source.begin || source.base > source.end)) source.diagnoseRange(0);
            const auto offset = source.base;
            if (instruction == Instruction::PointerElement) pushReference(type, source, true);
            else if (instruction == Instruction::FieldSlice) {
                const auto length = readOperand<std::uint32_t>();
                auto& slot = stack[value_stack_size++];
                slot.type = type; slot.width = sizeof(slot.value); slot.value = {offset, offset, offset + length - 1}; slot.detach();
            } else {
                const std::uint32_t width = type == SferaMbcValue::Address ? readOperand<std::uint32_t>() : type == SferaMbcValue::Byte ? std::uint32_t{sizeof(std::int8_t)} : type == SferaMbcValue::Integer || type == SferaMbcValue::Real ? std::uint32_t{sizeof(std::uint32_t)} : std::uint32_t{sizeof(SferaSliceReference32)};
                pushReference(type, {offset, offset, offset + width - 1u}, true);
            }
            break;
        }
        case Instruction::CallLocal: {
            auto& program = program_table_base[program_index];
            if (program.callDepth >= std::size(program.return_offsets)) { reportError("Return stack overflow"); break; }
            active_program_record->return_offsets[program.callDepth++] = SferaNumeric::signedWord(SferaNumeric::lowWord(instruction_cursor - bytecode_base + sizeof(int)));
            const auto offset = readOperand<int>();
            instruction_cursor += std::ptrdiff_t{offset} - sizeof(offset);
            argument_end = value_stack_size;
            value_stack_size -= argument_count;
            argument_cursor = value_stack_size;
            break;
        }

        case Instruction::Jump: { const std::ptrdiff_t offset = readOperand<int>(); instruction_cursor += offset - sizeof(int); break; }
        case Instruction::JumpShort: { const auto offset = readOperand<std::int16_t>(); std::ptrdiff_t displacement = offset; displacement -= sizeof(offset); instruction_cursor += displacement; break; }
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
            if (program.state < 0) active_process->linkProgram(SferaNumeric::word(index));
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
            slot.type = SferaNumeric::enumFromBits<SferaMbcValue::Type>(SferaNumeric::lowByte(SferaNumeric::enumBits(slot.type) - 1u));
            if (slot.type == SferaMbcValue::Byte) { slot.value.base = readMemory<std::int8_t>(offset); slot.type = SferaMbcValue::Integer; slot.width = sizeof(std::int8_t); }
            else if (!slot.isPointer()) { slot.value.base = readMemory<std::uint32_t>(offset); slot.width = sizeof(std::uint32_t); }
            else { slot.value = readMemory<SferaSliceReference32>(offset); slot.width = sizeof(slot.value); }
            break;
        }
        case Instruction::AddressOf: { auto& slot = stack[value_stack_size - 1]; slot.value = slot.source; slot.detach(); slot.type = SferaNumeric::enumFromBits<SferaMbcValue::Type>(SferaNumeric::lowByte(SferaNumeric::enumBits(slot.type) + 1u)); slot.width = sizeof(slot.value); break; }
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
                    case Instruction::Divide: { const std::int64_t dividend = left.integer(); left.value.base = dividend / divisor; break; }
                    default: { const std::int64_t dividend = left.integer(); left.value.base = dividend % divisor; break; }
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
                left.setReal(result);
            }
            --value_stack_size; left.detach();
            break;
        }
        case Instruction::Equal: case Instruction::NotEqual: case Instruction::Greater: case Instruction::Less: case Instruction::GreaterEqual: case Instruction::LessEqual: {
            auto& left = stack[value_stack_size - 2];
            const auto& right = stack[value_stack_size - 1];
            double first = left.integer();
            double second = right.integer();
            if (left.type == SferaMbcValue::Real) {
                first = left.real();
                second = right.real();
            }
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
            if (branch) { slot.type = SferaMbcValue::Integer; slot.detach(); std::ptrdiff_t displacement = offset; displacement -= sizeof(offset); instruction_cursor += displacement; }
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
                if (slot.width == 1) writeMemory(slot.source.base, SferaNumeric::lowByte(value)); else writeMemory(slot.source.base, value);
                if (prefix) slot.value.base = value;
            } else {
                const double current = slot.real();
                const float value = current + (increment ? 1.0 : -1.0);
                if (instruction == Instruction::PostDecrement) {
                    // Preserve the stable interpreter's floating postfix result and second decrement.
                    slot.setReal(value);
                    writeReal(slot.source.base, value - 1.0);
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
            if (instruction == Instruction::IntegerToReal || instruction == Instruction::PreviousIntegerToReal) { slot.setReal(SferaNumeric::real32(slot.integer())); slot.type = SferaMbcValue::Real; }
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
            if (call_frame_depth < 0 || call_frame_depth >= std::ssize(frame_stack_base) || value_stack_size <= frame_stack_base[call_frame_depth]) { --value_stack_size; reportError(instruction == Instruction::Negate ? "fo27(): stack underflow" : "fo31(): stack underflow"); break; }
            auto& slot = stack[value_stack_size - 1];
            if (instruction == Instruction::LogicalNot) { slot.value.base = slot.value.base == 0; slot.type = SferaMbcValue::Integer; }
            else if (slot.type == SferaMbcValue::Integer) slot.value.base = 0u - slot.value.base;
            else slot.setReal(-slot.real());
            slot.detach();
            break;
        }
        case Instruction::EnterFrame:
            if (++call_frame_depth >= std::ssize(frame_stack_base)) reportError("Stack of stacks overflow");
            if (call_frame_depth >= 0 && call_frame_depth < std::ssize(frame_stack_base)) frame_stack_base[call_frame_depth] = value_stack_size;
            break;
        case Instruction::LeaveFrame: if (--call_frame_depth < 0) reportError("Stack of stacks devastation"); break;
        case Instruction::UnlinkedFunction: reportError("Unlinked function was called"); break;
        case Instruction::Halt: execution_failed = true; break;
        default: return false;
    }
    return true;
}

void SferaMbcRuntime::reportInvalidInstruction() {
    reportError("Unknown script code: ", SferaText::fromBytes(std::span(--instruction_cursor, 1u)));
}

std::uint32_t SferaText::copyString(Buffer destination, std::string_view source, int capacity) {
    const auto limit = capacity > 0 ? std::min<std::size_t>(capacity, destination.size()) : destination.size();
    if (limit == 0) throw std::out_of_range("Empty script string destination");
    if (capacity <= 0 && source.size() >= limit) throw std::out_of_range("Script string destination is too small");
    if (source.size() >= limit) {
        g_sfera_mbc_runtime.diagnostic_context = std::format("MBINTER MESSAGE: Wrong string to copy: '{}', strlen: {}\n", source, source.size());
        g_sfera_log_runtime.write(g_sfera_mbc_runtime.diagnostic_context);
    }
    const auto copied = destination.limited(limit).write(source);
    return (copied + 1);
}

bool SferaMbcRuntime::executeBuiltin(Builtin builtin) {
    switch (builtin) {
        case Builtin::Fail: case Builtin::FailAlternate: { std::string message; message = std::format("MBInter:\n {:f}", nextReal()); SferaClientApplication::terminateWithError(message); }
        case Builtin::Exit: {
            if (argument_count == 0) throw SferaClientApplication::ExitRequested{};
            if (argument_count > 1) g_sfera_mbc_runtime.dispatch_slot = -1;
            const auto message = nextSliceReference().base; SferaClientApplication::terminateWithError(textAt(message));
        }
        case Builtin::LoadProcess: {
            const auto name = nextSliceReference().base; const auto index = argument_count > 1 ? nextWord() : UINT32_MAX; if (execution_failed) break;
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
        case Builtin::Connect: { const auto host = nextSliceReference().base; nextSliceReference(); const auto mode = argument_count > 2 ? nextWord() : 3u; pushInteger(g_sfera_network_runtime.initialize(std::string(textAt(host)), mode)); break; }
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
            const auto operation = SferaNumeric::enumFromBits<SferaConfigTextRuntime::Operation>(nextInteger());
            switch (operation) {
                case SferaConfigTextRuntime::Operation::Write: {
                    const auto keyOffset = nextWord();
                    if (execution_failed) break;
                    const std::string key(textAt(keyOffset));
                    if (argument_cursor >= argument_end) { reportError("Too few parameters"); break; }
                    const auto type = SferaNumeric::enumBits(g_sfera_mbc_runtime.values[argument_cursor].type);
                    std::string value;
                    bool quoted = false;
                    if (!key.empty() && key.front() == '*') {
                        const auto offset = nextWord();
                        const auto size = nextInteger();
                        if (execution_failed) break;
                        if (size < 0 || size > (SferaConfigTextRuntime::text_capacity - 4) * 3 / 4) { reportError("cfg_set: invalid binary size"); break; }
                        value = SferaConfigTextRuntime::encodeBinary(memoryAt(offset, size), size);
                    } else if (type == SferaMbcValue::Byte || type == SferaMbcValue::Integer) {
                        value = std::to_string(nextInteger());
                    } else if (type == SferaMbcValue::Real) {
                        value = std::format("{:f}", nextReal());
                    } else if (type == SferaMbcValue::BytePointer) {
                        const auto offset = nextWord();
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
                    const auto key = textIn(keyReference);
                    if (argument_cursor >= argument_end) { reportError("Too few parameters"); break; }
                    const auto type = g_sfera_mbc_runtime.values[argument_cursor].type;
                    const auto destination = nextSliceReference();
                    const auto capacity = argument_count == 4 ? nextWord() : 10000000u;
                    if (execution_failed) break;
                    bool result = false;
                    if (key.starts_with('*')) {
                        auto bytes = sliceBytes(destination); result = config.readBinary(key, bytes.first(std::min<std::size_t>(capacity, bytes.size())));
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
                        auto output = textBuffer(destination);
                        output = output.limited(capacity);
                        if (const auto value = config.readString(key); value && !output.empty()) {
                            result = output.write(*value) == value->size();
                        }
                    }
                    else {
                        const auto message = std::format("wrong parameter in cfg_get, '{}'\n", key);
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
                    const auto text = textIn(reference);
                    if (operation == SferaConfigTextRuntime::Operation::UseText) { config.useText(reference.base, sliceBytes(reference).size(), active_process); pushInteger(0); }
                    else if (operation == SferaConfigTextRuntime::Operation::Load) pushInteger(config.load(std::string(text)) ? 0u : UINT32_MAX);
                    else {
                        const auto length = text.size();
                        if (length >= SferaConfigTextRuntime::filename_capacity) { reportError("cfg: filename is too long"); break; }
                        if (operation == SferaConfigTextRuntime::Operation::Clear) config.clear(std::string(text));
                        else config.filename.assign(text);
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
                    const std::uint32_t capacity = nextWord();
                    if (!execution_failed) pushInteger(SferaNumeric::lowWord(config.copyTo(sliceBytes(destination).first(std::min<std::size_t>(capacity, sliceBytes(destination).size())))));
                    break;
                }
                case SferaConfigTextRuntime::Operation::Length: if (std::in_range<std::uint32_t>(config.text().size())) pushInteger(SferaNumeric::lowWord(config.text().size())); else reportError("cfg: text is too long for MBC"); break;
                default: break;
            }
            return true;
        }
        case Builtin::CreateFile: case Builtin::OpenFile: {
            const auto name = nextWord();
            if (name == 0) WorldDiagnostics::warning(builtin == Builtin::CreateFile ? "NULL-pointer dereferencing: ffcreate\n" : "NULL-pointer dereferencing: ffopen\n");
            if (builtin == Builtin::CreateFile && execution_failed) break;
            const auto path = textAt(name);
            ::_chmod(path.data(), _S_IREAD | _S_IWRITE);
            if (execution_failed) break;
            int flags = _O_BINARY | _O_RDWR;
            int sharing = _SH_DENYNO;
            if (builtin == Builtin::CreateFile) flags |= _O_CREAT | (argument_count == 2 ? 0 : _O_TRUNC);
            else if (argument_count > 1 && nextInteger() == 1) flags = _O_BINARY | _O_RDONLY;
            int file = -1;
            ::_sopen_s(&file, path.data(), flags, sharing, _S_IREAD | _S_IWRITE);
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
            if (execution_failed) break;
            if (!buffer.contains(size)) buffer.diagnoseRange(size);
            const auto data = memoryBytes(buffer.base, size);
            if (size == 0) { pushInteger(0); break; }
            const auto result = builtin == Builtin::ReadFile ? ::_read(file, data.data(), size) : file < 0 ? 0 : ::_write(file, data.data(), size);
            pushInteger(result);
            break;
        }
        case Builtin::ReadLine: {
            const auto file = nextInteger();
            if (execution_failed) break;
            const auto destination = nextAddress();
            if (destination.base == 0) WorldDiagnostics::warning("NULL-pointer dereferencing: ffread\n");
            const auto capacity = nextInteger();
            if (execution_failed) break;
            if (capacity < 0) { reportError("Negative line buffer capacity"); break; }
            const auto output = memoryBytes(destination.base, capacity);
            int size = 0;
            // ReadLine has a byte-count ABI: a full buffer is not required to end in NUL.
            while (size < capacity) {
                std::uint8_t character;
                if (::_read(file, &character, sizeof(character)) != 1) break;
                if (character == '\n' || character == '\0') { output[size] = 0; break; }
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
            if (!execution_failed) { struct _stat64i32 status{}; ::_fstat64i32(file, &status); pushInteger(SferaNumeric::lowWord(status.st_mtime)); }
            break;
        }
        case Builtin::ResizeFile: { const auto file = nextInteger(); const auto size = nextInteger(); if (!execution_failed) ::_chsize_s(file, size); break; }
        case Builtin::SetFileTime: {
            const auto file = nextInteger();
            const auto time = nextInteger();
            if (!execution_failed) { __utimbuf64 times{time, time}; ::_futime64(file, &times); }
            break;
        }
        case Builtin::RemoveFile: { const auto name = nextInteger(); if (!execution_failed) pushInteger(std::remove(textAt(name).data())); break; }
        case Builtin::RenameFile: { const auto source = nextWord(); const auto destination = nextWord(); if (!execution_failed) pushInteger(std::rename(textAt(source).data(), textAt(destination).data())); break; }
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
            const auto id = builtin == Builtin::ThisProcessName ? process_index : nextWord();
            const auto destination = nextWord();
            if (destination == 0 && builtin != Builtin::ModuleName) WorldDiagnostics::warning(builtin == Builtin::ThisProcessName ? "NULL-pointer dereferencing: thisname\n" : "NULL-pointer dereferencing: prc_name\n");
            if (execution_failed) break;
            std::optional<std::string_view> name;
            if (builtin == Builtin::ThisProcessName) name = active_process->name;
            else if (builtin == Builtin::ProcessName && id < std::size(processes) && processes[id].chain_prev_index >= 0) name = processes[id].name;
            else if (builtin == Builtin::ModuleName && id < std::size(g_sfera_mbc_runtime.modules)) name = g_sfera_mbc_runtime.modules[id].name;
            if (name) copyText({destination, 0, 0}, *name);
            if (builtin != Builtin::ThisProcessName) pushInteger(name && (builtin != Builtin::ModuleName || !name->empty()) ? 0 : UINT32_MAX);
            break;
        }
        case Builtin::FindModule: {
            const auto name = nextInteger();
            if (execution_failed) break;
            const auto& modules = g_sfera_mbc_runtime.modules;
            const auto found = std::find_if(std::begin(modules), std::end(modules), [&](const auto& module) { return !module.name.empty() && SferaText::compareInsensitive(module.name, textAt(name)) == 0; });
            pushInteger(found == std::end(modules) ? UINT32_MAX : SferaNumeric::lowWord(found - std::begin(modules)));
            break;
        }
        case Builtin::FontSettings: {
            const auto& suffix = g_sfera_font_runtime.language_suffix;
            const auto offset = mapMemory(suffix.c_str(), suffix.size() + 1);
            pushSlice({offset, offset, offset + SferaNumeric::lowWord(suffix.size())}, SferaMbcValue::BytePointer);
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
            const auto filename = textAt(name);
            const auto handle = g_sfera_world_objects.create(filename, independent == 1 ? nullptr : active_process, factory, independent != 1);
            pushInteger(handle);
            if (SferaNumeric::signedWord(handle) < 0) { reportError(std::format("Error creating object: {}", filename)); execution_failed = false; break; }
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
            if (handle == g_sfera_world_objects.controlled_object_handle) {
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
            if (builtin == Builtin::VerticalVelocity) value = argument_count == 3 ? g_sfera_motion.responseValue(nextInteger()) : nextReal();
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
            else { const auto offset = active_process->growMemory(size); pushSlice({offset, offset, offset + size - 1}, SferaMbcValue::BytePointer); }
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
                const auto offset = size > 0 ? allocateDynamic(size) : 0u;
                try { if (offset != 0) active_process->registerResource(reference.base, ResourceKind::dynamicArray); }
                catch (...) { releaseDynamic(offset); throw; }
                const SferaSliceReference32 replacement{offset, offset, offset == 0 ? 0u : offset + size - 1u};
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
            const auto value = builtin == Builtin::SetNamedValue ? nextWord() : 0u;
            const auto index = argument_count > (builtin == Builtin::SetNamedValue ? 2u : 1u) ? nextInteger() : 0;
            const auto text = textAt(name);
            if (builtin == Builtin::SetNamedValue) setNamedValue(text, value, index);
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
            if (execution_failed) break;
            auto* target = findProcess(destinationProcess);
            auto* origin = findProcess(sourceProcess);
            if (target == nullptr || origin == nullptr) { active_tag = UINT32_MAX; pushInteger(UINT32_MAX); break; }
            if (builtin == Builtin::CopyProcessMemory) {
                if (count < 0) { reportError("Negative process copy length"); break; }
                const auto input = memoryBytes(source.base, count, origin);
                if (!destination.contains(count)) destination.diagnoseRange(count);
                const auto output = memoryBytes(destination.base, count, target);
                SferaBinary::copy(output, input);
            } else {
                const auto text = textIn(source, origin);
                SferaText::copyString(textBuffer(destination, target), text, count);
            }
            break;
        }

        case Builtin::Text: {
            const auto create = g_sfera_mbc_runtime.values[argument_cursor].type == SferaMbcValue::BytePointer;
            const auto first = nextWord();
            if (!create) {
                const auto color = nextInteger();
                const auto style = nextInteger();
                const auto font = nextInteger();
                const auto scale = SferaMbcValue::truncate(nextReal());
                if (execution_failed) break;
                auto* window = GameInterface::window(first, "GetWindowPointer");
                if (window == nullptr) { reportError("Wrong parameters for 'text' function"); break; }
                window->textColor = color; window->textStyle = style; window->font = font; window->fontScale = scale;
                break;
            }
            const auto parent = nextWord();
            const auto x = nextInteger();
            const auto y = nextInteger();
            if (argument_count >= 8) {
                auto* window = GameInterface::window(parent, "GetWindowPointer");
                if (window == nullptr) { reportError("Wrong parameters for 'text' function"); break; }
                window->textColor = nextInteger(); window->textStyle = nextInteger(); window->font = nextInteger(); window->fontScale = SferaMbcValue::truncate(nextReal());
            }
            if (argument_count == 9) nextInteger();
            if (execution_failed) break;
            const auto text = textAt(first);
            const auto length = text.size();
            if (length >= text_capacity) { reportError("Script text exceeds text buffer capacity"); break; }
            text_buffer = text.empty() ? std::string_view{"?"} : text;
            const auto handle = WorldGuiControls::createText(x, y, text_buffer, parent);
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
            const auto effect = nextWord();
            const auto parameter = argument_count >= 3 ? nextWord() : 0u;
            if (argument_count == 4) nextInteger();
            if (execution_failed) break;
            SferaActiveEffect* created = nullptr;
            if (argument_count == 4) {
                if (handle == 0) reportError("Effect attached to zero handle!", "");
                created = g_sfera_effect_manager.createActiveEffect(textAt(effect), handle);
            } else {
                if (handle <= 0) { std::string message; message = std::format("Wrong Handler for Effect {}\n", active_process->name); ::OutputDebugStringA(message.c_str()); pushInteger(UINT32_MAX); break; }
                if (argument_count >= 3 && parameter != 0) {
                    SferaEffectParameter value;
                    switch (effect) {
                        case 1: {
                            const auto* bytes = memoryAt(parameter, 6);
                            SferaEffectParameter::Color rgb;
                            for (std::size_t channel = 0; channel < rgb.channels.size(); ++channel) rgb.channels[channel] = SferaBinary::readLittleEndian<std::uint16_t>(bytes + channel * 2);
                            value.value = rgb;
                            break;
                        }
                        case 2: value.value = SferaEffectParameter::Radius{readMemory<float>(parameter)}; break;
                        case 3: value.value = SferaEffectParameter::Jitter{readMemory<std::uint8_t>(parameter)}; break;
                        case 4: value.value = SferaEffectParameter::Frequency{readMemory<std::uint8_t>(parameter)}; break;
                        default: break;
                    }
                    if (!execution_failed) pushInteger(g_sfera_effect_manager.setEffectParameters(handle, {&value, 1}));
                    break;
                }
                if (argument_count >= 3 && handle == g_sfera_world_objects.controlled_object_handle) { pushInteger(UINT32_MAX); break; }
                created = g_sfera_effect_manager.createActiveEffect(effect, handle);
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
                const std::uint32_t avoidance_enabled = extended->avoidance_enabled;
                writeMemory(result, avoidance_enabled);
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
            const auto left = nextSlice();
            if (left.base == 0) reportError("poppointerup(): unexpected NULL-pointer fetched");
            const auto right = nextSlice();
            if (right.base == 0) reportError("poppointerup(): unexpected NULL-pointer fetched");
            const std::uint32_t size = nextInteger();
            if (!execution_failed) { const auto result = size == 0 ? 0 : std::memcmp(memoryBytes(left.base, size).data(), memoryBytes(right.base, size).data(), size); pushInteger((result > 0) - (result < 0)); }
            break;
        }
        case Builtin::PlayerLists: {
            const auto command = nextInteger();
            if (command < 1 || command > 11) break;
            auto& manager = g_sfera_player_lists;
            const auto text = [&](int offset) { return textAt(offset); };
            const auto name = [&](int offset) { return textAt(offset, 149); };
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
                        const auto* bytes = memoryAt(data, size);
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
                    const std::string_view operation = command == 5 ? "L_FFITEM" : command == 6 ? "L_FNITEM" : "L_FINDITEM";
                    std::array<int, 4> fields;
                    for (std::size_t index = 0; index < fields.size(); ++index) {
                        fields[index] = nextInteger();
                        if (fields[index] == 0 && !(command == 7 && index == 3)) { std::string message; message = std::format("NULL-pointer dereferencing: list, {}, {}\n", operation, (index + 1)); WorldDiagnostics::warning(message); }
                    }
                    const auto payload = nextInteger();
                    if (execution_failed) break;
                    auto* current = command == 6 ? manager.currentList() : manager.selectList(name(first));
                    const auto nameOutput = command == 6 ? first : second;
                    if (current == nullptr) { if (command != 7) copyName(nameOutput, {}); pushInteger(-1); break; }
                    auto* item = command == 7 ? current->find(name(second)) : command == 5 ? current->first() : current->next();
                    if (item == nullptr) { if (command != 7) copyName(nameOutput, {}); pushInteger(-2); break; }
                    if (command != 7) copyName(nameOutput, item->name);
                    writeMemory(fields[0], item->attributes[0]); writeMemory(fields[1], item->attributes[1]); writeMemory(fields[2], item->attributes[2]);
                    if (command != 7) writeMemory(fields[3], SferaNumeric::lowWord(item->payload.size()));
                    if (payload != 0 && !item->payload.empty()) std::copy(item->payload.begin(), item->payload.end(), memoryAt(payload, item->payload.size()));
                    if (command == 7) { if (fields[3] == 0) WorldDiagnostics::warning("NULL-pointer dereferencing: list, L_FINDITEM, 4\n"); writeMemory(fields[3], SferaNumeric::lowWord(item->payload.size())); }
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
                    for (std::size_t index = 0; index < outputs.size(); ++index) { outputs[index] = nextInteger(); if (outputs[index] == 0) { std::string message; message = std::format("NULL-pointer dereferencing: list, L_FINDITEM, {}\n", (index + 1)); WorldDiagnostics::warning(message); } }
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
            std::string name;
            std::uint32_t module = 0;
            if (byName) { const auto slice = nextSliceReference(); if (slice.base == 0) WorldDiagnostics::warning("NULL-pointer dereferencing: ffprc_id\n"); name = textIn(slice); }
            else module = nextInteger();
            auto index = process_chain_first;
            if (argument_count > 1) {
                const std::uint32_t previous = nextInteger();
                if (previous >= std::size(processes) || processes[previous].chain_next_index == previous) { pushInteger(-1); break; }
                index = processes[previous].chain_next_index;
            }
            if (execution_failed) break;
            int result = -1;
            for (std::size_t visited = 0; visited < std::size(processes) && index >= 0 && index < std::size(processes); ++visited) {
                const auto& process = processes[index];
                if (process.chain_prev_index == -1) break;
                if (byName ? name == process.name : module == 0 || process.module_tag == module) { result = process.process_id; break; }
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
            pushReal(result);
            break;
        }
        case Builtin::ArcTangent: { const double y = nextReal(); const double x = nextReal(); pushReal(std::atan2(y, x)); break; }
        case Builtin::AbsoluteInteger: case Builtin::IntegerValue: {
            const auto value = nextInteger();
            if (builtin == Builtin::AbsoluteInteger && value < 0) pushInteger(0u - SferaNumeric::word(value));
            else pushInteger(value);
            break;
        }
        case Builtin::RandomReal: pushReal(std::rand() / 32768.0f); break;
        case Builtin::SimulationTick: pushInteger(g_sfera_mbc_runtime.simulation_tick); break;
        case Builtin::PackColor: { const auto red = nextInteger(); const auto green = nextInteger(); const auto blue = nextInteger(); pushInteger(D3DCOLOR_XRGB(red, green, blue)); break; }
        case Builtin::ScaleColor: {
            const auto color = SferaColor::fromArgb(nextWord());
            const double factor = nextReal();
            const std::uint8_t red = SferaMbcValue::truncate(color.red() * factor);
            const std::uint8_t green = SferaMbcValue::truncate(color.green() * factor);
            const std::uint8_t blue = SferaMbcValue::truncate(color.blue() * factor);
            pushInteger(D3DCOLOR_XRGB(red, green, blue));
            break;
        }
        case Builtin::SceneContext: {
            if (argument_count == 0) pushInteger(g_sfera_direct_input_runtime.virtual_key);
            const auto kind = nextInteger();
            pushInteger(kind == 0 ? g_sfera_direct_input_runtime.virtual_key : kind == 1 ? g_sfera_direct_input_runtime.character : g_sfera_direct_input_runtime.scan_code);
            break;
        }
        case Builtin::KeyboardState: { const std::uint32_t key = nextInteger(); pushInteger(SferaClientApplication::application_active && key < std::size(g_sfera_direct_input_runtime.keyboard_state) ? SferaNumeric::signedByte(g_sfera_direct_input_runtime.keyboard_state[key]) : 0); break; }
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
            pushInteger(SferaNetworkRuntime::tickDifference(first, second));
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
        case Builtin::CallerProcess: pushInteger(execution_context_depth > 0 ? execution_context_stack[execution_context_depth - 1].process_id : UINT32_MAX); break;
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
            const auto argument = builtin == Builtin::BitNot ? 0u : nextWord();
            const auto shift = argument % std::numeric_limits<std::uint32_t>::digits;
            if (builtin == Builtin::BitAnd) result &= argument;
            else if (builtin == Builtin::BitOr) result |= argument;
            else if (builtin == Builtin::BitXor) result ^= argument;
            else if (builtin == Builtin::BitNot) result = ~result;
            else if (builtin == Builtin::ShiftLeft) result <<= shift;
            else if (builtin == Builtin::ShiftRight) result = SferaNumeric::signedWord(result) >> shift;
            else if (builtin == Builtin::ClearBit) result &= ~(1u << shift);
            else if (builtin == Builtin::SetBit) result |= 1u << shift;
            else result = SferaNumeric::signedWord(result & (1u << shift)) >> shift;
            pushInteger(result);
            break;
        }
        case Builtin::CopyString: case Builtin::CopyStringCount: case Builtin::AppendString: {
            auto& destination = nextSliceReference();
            auto& source = nextSliceReference();
            const auto count = builtin == Builtin::CopyStringCount ? nextInteger() : 0;
            if (!source.contains()) { source.diagnoseRange(0); ++value_stack_size; break; }
            if (count < 0) { reportError("Negative string length"); break; }
            const auto input = builtin == Builtin::CopyStringCount ? textIn(source, count) : textIn(source);
            auto output = textBuffer(destination);
            std::uint32_t length = 0;
            if (builtin == Builtin::AppendString) {
                if (!destination.contains()) { destination.diagnoseRange(0); break; }
                const auto prefix = output.length();
                const auto required = prefix + input.size() + 1;
                if (required > UINT32_MAX || required > output.size()) { destination.diagnoseRange(std::min<std::size_t>(required, UINT32_MAX)); break; }
                length = required;
                if (argument_count > 2 && SferaNumeric::signedWord(length) > nextInteger()) { WorldDiagnostics::warning("Size mismatch: ffstrcat\n"); ++value_stack_size; break; }
                if (execution_failed) break;
                output.append(input);
            } else {
                const auto capacity = builtin == Builtin::CopyString && argument_count == 3 ? nextInteger() : 0;
                if (execution_failed) break;
                if (builtin == Builtin::CopyString) length = SferaText::copyString(output, input, capacity);
                else {
                    const std::size_t required = count + 1u;
                    if (required > output.size()) { destination.diagnoseRange(required); break; }
                    const auto copied = output.writePadded(input, count);
                    length = (copied + 1);
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
            const auto text = textIn(haystack);
            const auto match = textIn(needle);
            const auto found = builtin == Builtin::FindString ? text.find(match) : SferaText::findInsensitive(text, match);
            if (found == std::string_view::npos) pushSlice({}, SferaMbcValue::BytePointer);
            else { haystack.base += found; pushSlice(haystack, SferaMbcValue::BytePointer); }
            break;
        }
        case Builtin::StringLength: {
            const auto slice = nextSliceReference();
            if (slice.base == 0) WorldDiagnostics::warning("ffstrlen(): NULL-pointer dereferencing\n");
            std::uint32_t length = 0;
            if (argument_count > 1) {
                const auto limit = nextInteger();
                if (limit > 0) length = SferaText::length(memoryRange(slice.base), limit);
                if (SferaNumeric::signedWord(length) == limit) WorldDiagnostics::warning(std::format("ffstrlen(): end of string was not found in buffer of size {}\n", limit));
            } else length = SferaText::length(memoryRange(slice.base));
            pushInteger(length);
            break;
        }
        case Builtin::CompareStrings: case Builtin::CompareStringsInsensitive: case Builtin::CompareStringsCount: case Builtin::CompareStringsCountInsensitive: {
            const auto first = nextAddress();
            const auto second = nextAddress();
            const bool optionalInsensitiveCount =
                builtin == Builtin::CompareStringsInsensitive && argument_count >= 3;
            const bool bounded = optionalInsensitiveCount ||
                builtin == Builtin::CompareStringsCount ||
                builtin == Builtin::CompareStringsCountInsensitive;
            const auto count = bounded ? nextWord() : 0u;
            if (execution_failed) break;
            const auto left = bounded ? textIn(first, count) : textIn(first);
            const auto right = bounded ? textIn(second, count) : textIn(second);
            int result = builtin == Builtin::CompareStringsInsensitive || builtin == Builtin::CompareStringsCountInsensitive
                ? SferaText::compareInsensitive(left, right) : SferaText::compare(left, right);
            if (builtin == Builtin::CompareStrings) result = (result > 0) - (result < 0);
            pushInteger(result);
            break;
        }
        case Builtin::CopyMemory: case Builtin::MoveMemory: case Builtin::FillMemory: {
            auto& destination = nextSliceReference();
            const auto source = builtin == Builtin::FillMemory ? SferaSliceReference32{nextWord(), 0, 0} : nextSliceReference();
            const std::uint32_t count = nextInteger();
            if (execution_failed) break;
            if (count != 0 && !destination.contains(count)) destination.diagnoseRange(count);
            const auto output = memoryBytes(destination.base, count);
            if (builtin == Builtin::FillMemory) std::fill(output.begin(), output.end(), SferaNumeric::lowByte(source.base));
            else SferaBinary::copy(output, memoryBytes(source.base, count));
            break;
        }
        case Builtin::WriteByte: case Builtin::WriteShort: case Builtin::WriteThreeBytes: case Builtin::WriteWord: case Builtin::WriteReal: {
            auto destination = nextSliceReference();
            const auto value = builtin == Builtin::WriteReal ? SferaBinary::floatBits(nextReal()) : nextWord();
            const std::size_t width = builtin == Builtin::WriteByte ? 1 : builtin == Builtin::WriteShort ? 2 : builtin == Builtin::WriteThreeBytes ? 3 : sizeof(std::uint32_t);
            if (execution_failed) break;
            if (!destination.contains(width)) destination.diagnoseRange(width);
            else { std::memcpy(sliceBytes(destination, width).data(), &value, width); destination.base += width; }
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
                const auto input = sliceBytes(source, width);
                const auto outputWidth = builtin == Builtin::ReadShort || builtin == Builtin::ReadThreeBytes ? sizeof(std::uint32_t) : width;
                const auto output = memoryBytes(destination.base, outputWidth);
                // Stage the word before clearing a potentially overlapping destination.
                std::uint32_t value = 0;
                std::memcpy(&value, input.data(), width);
                std::memcpy(output.data(), &value, outputWidth);
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
            const auto input = textIn(source);
            if (input.size() >= UINT32_MAX) { reportError("String exceeds the MBC address range"); break; }
            const std::uint32_t length = SferaNumeric::lowWord(input.size() + 1u);
            copyText(destination, input);
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
            const auto length = SferaNumeric::word(count) * sizeof(int);
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
            auto* container = nativeResource<SferaScriptContainer*>(nextWord());
            if (container == nullptr) pushInteger(UINT32_MAX);
            else if (container->header.kind >= SferaDataContainerHeader::Kind::List && container->header.kind <= SferaDataContainerHeader::Kind::HashMap) container->execute(*this);
            break;
        }
        case Builtin::ContainerManagement: {
            using Kind = SferaScriptContainer::Kind;
            using ValueType = SferaScriptContainer::ValueType;
            using Lifecycle = SferaScriptContainer::Lifecycle;
            const auto command = SferaNumeric::enumFromBits<Lifecycle>(nextInteger());
            if (command == Lifecycle::Create) {
                const auto kind = SferaNumeric::enumFromBits<Kind>(SferaNumeric::word(nextInteger()));
                if (kind < Kind::List || kind > Kind::HashMap) { pushInteger(0); break; }
                const auto keyType = kind == Kind::Map || kind == Kind::HashMap ? SferaNumeric::enumFromBits<ValueType>(SferaNumeric::word(nextInteger())) : ValueType::Integer;
                const auto valueType = SferaNumeric::enumFromBits<ValueType>(SferaNumeric::word(nextInteger()));
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
                case Lifecycle::Kind: pushInteger(SferaNumeric::enumBits(kind)); break;
                case Lifecycle::ValueType: pushInteger(kind == Kind::List || kind == Kind::Vector || kind == Kind::Map || kind == Kind::HashMap ? SferaNumeric::enumBits(container->value_type) : UINT32_MAX); break;
                case Lifecycle::KeyType: pushInteger(kind == Kind::Set ? SferaNumeric::enumBits(container->value_type) : kind == Kind::Map || kind == Kind::HashMap ? SferaNumeric::enumBits(container->key_type) : UINT32_MAX); break;
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
        hash = reduced < 0 ? reduced + modulus : reduced;
    } else {
        // Its byte hash is FNV-1 with signed octets; FNV-1a changes script iteration order.
        constexpr std::uint32_t offsetBasis = 2166136261u, prime = 16777619u;
        hash = offsetBasis;
        const std::size_t step = std::is_same_v<K, std::string> ? key.size() / 10 + 1 : 1;
        for (std::size_t index = 0; index < key.size(); index += step) hash = (hash * prime) ^ SferaNumeric::signedByte(SferaText::byteValue(key[index]));
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
    if (values.size() <= buckets.size()) return;
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
    writeMemory(destination.base, SferaSliceReference32{offset, offset, offset + SferaNumeric::lowWord(size) - 1u});
}

void SferaScriptContainer::execute(SferaMbcRuntime& runtime) {
    const auto command = SferaNumeric::enumFromBits<Command>(runtime.nextInteger());
    std::visit([&](auto& state) {
        using State = std::remove_reference_t<decltype(state)>;
        using Value = typename State::Value;
        auto& values = state.values;
        const auto forgetValue = [&](const auto& value) {
            using T = std::remove_cvref_t<decltype(value)>;
            if constexpr (std::is_same_v<T, std::string> || std::is_same_v<T, Binary>) std::erase_if(runtime.mapped_memory, [&](const auto& entry) { return entry.second.owner == this && entry.second.address() == value.data(); });
        };
        const auto read = [&]<class T>() -> T {
            if constexpr (std::is_same_v<T, float>) return runtime.nextReal();
            else if constexpr (std::is_same_v<T, std::uint8_t>) return SferaNumeric::lowByte(SferaNumeric::word(runtime.nextInteger()));
            else if constexpr (std::is_integral_v<T>) return runtime.nextInteger();
            else {
                auto& source = runtime.nextSliceReference();
                if constexpr (std::is_same_v<T, std::string>) return runtime.textIn(source);
                else {
                    const std::uint32_t length = runtime.nextInteger();
                    if (!source.contains(length)) source.diagnoseRange(length);
                    const auto bytes = runtime.memoryBytes(source.base, length);
                    T result(bytes.begin(), bytes.end());
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
                if (index < 0 || std::cmp_greater_equal(index, values.size())) return values.end();
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
                    const void* begin = &*iterator;
                    const void* end = values.data() + values.size();
                    const std::less<const void*> less;
                    std::erase_if(runtime.mapped_memory, [&](const auto& entry) { const void* address = entry.second.data; return entry.second.owner == this && !less(address, begin) && less(address, end); });
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
std::span<std::uint8_t> SferaConfigTextRuntime::borrowedBytes(const BorrowedText& view) const {
    if (view.process && (view.process->chain_prev_index < 0 || view.process->lifetime != view.process_lifetime))
        throw std::out_of_range("Configuration source process is no longer alive");
    if (g_sfera_mbc_runtime.memoryLifetime(view.address) != view.mapping_lifetime)
        throw std::out_of_range("Configuration source mapping was replaced");
    auto bytes = g_sfera_mbc_runtime.memoryRange(view.address, view.process);
    if (view.capacity > bytes.size()) throw std::out_of_range("Configuration source buffer shrank");
    return bytes.first(view.capacity);
}
std::string SferaConfigTextRuntime::text() const {
    if (const auto* owned = std::get_if<std::string>(&storage_)) return *owned;
    const auto bytes = borrowedBytes(std::get<BorrowedText>(storage_));
    return SferaText::terminated(bytes);
}

void SferaConfigTextRuntime::useText(std::uint32_t address, std::size_t capacity, SferaMbcProcessRecord* process) {
    if (address >= SferaMbcRuntime::mappedAddressBegin) process = nullptr;
    BorrowedText view{address, std::min(capacity, text_capacity), process, process ? process->lifetime : 0,
                      g_sfera_mbc_runtime.memoryLifetime(address)};
    const auto bytes = borrowedBytes(view);
    (void)SferaText::length(bytes);
    storage_ = view; filename.clear();
}

std::optional<std::string> SferaConfigTextRuntime::find(std::string_view key) const {
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

std::optional<std::string> SferaConfigTextRuntime::readString(std::string_view key) const {
    const auto input = find(key);
    if (!input || input->empty() || input->front() != '"') return std::nullopt;
    std::string result;
    for (const auto character : input->substr(1)) {
        if (character == '"' || character == '\0') break;
        if (character != '\n') result.push_back(character == '\r' ? ' ' : character);
    }
    return result;
}

bool SferaConfigTextRuntime::readBinary(std::string_view key, std::span<std::uint8_t> destination) const {
    const auto input = find(key);
    if (!input) return false;
    std::vector<std::uint8_t> decoded;
    unsigned pending = 0, bits = 0;
    const auto append = [&](unsigned value, unsigned count) {
        const auto required = (bits + count + 7u) / 8u;
        if (decoded.size() > destination.size() || required > destination.size() - decoded.size()) return false;
        pending |= value << bits;
        bits += count;
        if (bits >= 8u) {
            decoded.push_back(pending & 0xffu);
            pending >>= 8u;
            bits -= 8u;
        }
        return true;
    };
    std::size_t cursor = 0;
    while (cursor < input->size() && (*input)[cursor] != '\0' && (*input)[cursor] != '#') {
        const auto value = SferaText::byteValue((*input)[cursor++]);
        if (value < '0' || value > '0' + 63 || !append(value - '0', 6u)) return false;
    }
    if (cursor < input->size() && (*input)[cursor] == '#') {
        if (++cursor == input->size()) return false;
        const auto marker = SferaText::byteValue((*input)[cursor++]);
        if (marker < '0' || marker > '8') return false;
        const unsigned count = marker - '0';
        if (count != 0) {
            if (cursor == input->size()) return false;
            const auto value = SferaText::byteValue((*input)[cursor]);
            if (value < '0' || (value - '0') >= (1u << count) || !append(value - '0', count)) return false;
        }
    }
    if (bits != 0) {
        if (decoded.size() == destination.size()) return false;
        const auto mask = (1u << bits) - 1u;
        decoded.push_back((destination[decoded.size()] & ~mask) | (pending & mask));
    }
    SferaBinary::copy(destination, decoded);
    return true;
}

std::size_t SferaConfigTextRuntime::copyTo(std::span<std::uint8_t> destination) const {
    const auto input = text();
    const auto count = std::min(destination.size(), input.size());
    if (count != 0) std::memmove(destination.data(), input.data(), count);
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

void SferaFileManager::keepTail(const std::string& filename, std::size_t size) {
    const auto length = fileSize(filename);
    if (length < 0 || std::cmp_less_equal(length, size) || size > std::size_t{std::numeric_limits<std::ptrdiff_t>::max()}) return;
    std::vector<std::uint8_t> tail(size);
    ScopedFile file(*this, open(filename, _O_RDWR));
    if (file.get() < 0) return;
    const std::int64_t tail_offset = size;
    const std::ptrdiff_t tail_size = size;
    if (seek(file.get(), -tail_offset, SEEK_END) < 0 || read(file.get(), std::as_writable_bytes(std::span(tail))) != tail_size) return;
    if (seek(file.get(), 0, SEEK_SET) >= 0 && write(file.get(), std::as_bytes(std::span(tail))) == tail_size) ::_chsize_s(file.get(), size);
}

std::string_view SferaClientApplication::commandLineArguments(std::string_view commandLine) {
    commandLine = commandLine.substr(0, commandLine.find('\0'));
    bool quoted = false;
    std::size_t cursor = 0;
    while (cursor < commandLine.size() && (SferaText::byteValue(commandLine[cursor]) > ' ' || quoted)) {
        if (commandLine[cursor] == '"') quoted = !quoted;
        if (::_ismbblead(SferaText::byteValue(commandLine[cursor])) && cursor + 1 < commandLine.size()) ++cursor;
        ++cursor;
    }
    while (cursor < commandLine.size() && SferaText::byteValue(commandLine[cursor]) <= ' ') ++cursor;
    return commandLine.substr(cursor);
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

std::uint32_t SferaMbcProcessRecord::growMemory(std::size_t size) {
    constexpr std::uint32_t maximumRequest = 4000000;
    constexpr auto limit = SferaMbcRuntime::mappedAddressBegin;
    if (size > maximumRequest || memory.size() > limit - 4u) return UINT32_MAX;
    const auto aligned = (memory.size() + 3u) & ~std::size_t{3};
    if (size >= limit - aligned) return UINT32_MAX;
    memory.resize(aligned + size, 0);
    // Process mappings resolve the owner at access time, so existing addresses remain valid.
    auto& runtime = g_sfera_mbc_runtime;
    if (runtime.active_process == this) runtime.process_memory_base = memory.data();
    return SferaNumeric::lowWord(aligned);
}

SferaMbcProcessRecord* SferaMbcRuntime::findProcess(std::uint32_t id) {
    if (id >= std::size(processes)) return nullptr;
    auto& process = processes[id];
    return process.process_id == id && process.chain_prev_index >= 0 ? &process : nullptr;
}

std::uint32_t SferaMbcRuntime::namedValue(std::string_view name, int index) {
    const auto found = named_vectors.find(name);
    if (found == named_vectors.end()) return 0;
    const auto& values = found->second;
    if (index < 0) return SferaNumeric::lowWord(values.size());
    const std::size_t offset = index;
    return offset < values.size() ? values[offset] : 0;
}

void SferaMbcRuntime::setNamedValue(std::string_view name, std::uint32_t value, int index) {
    if (index < 0) return;
    auto found = named_vectors.find(name);
    if (found == named_vectors.end()) {
        if (named_vectors.size() >= 1000u) return;
        found = named_vectors.try_emplace(std::string(name)).first;
    }
    auto& values = found->second;
    const std::size_t offset = index;
    const auto required = offset + 1u;
    if (required > values.max_size()) throw std::length_error("Named values exceed array capacity");
    if (required > values.size()) values.resize(required);
    values[offset] = value;
}

std::size_t SferaMbcValue::storageSize(Type valueType) {
    return valueType == Byte ? sizeof(std::int8_t) : valueType % Integer == 0 ? sizeof(std::uint32_t) : sizeof(SferaSliceReference32);
}

std::size_t SferaMbcValue::elementSize() const {
    return storageSize(SferaNumeric::enumFromBits<Type>(SferaNumeric::lowByte(SferaNumeric::enumBits(type) - 1u)));
}

std::string SferaText::encodeUri(std::string_view source, std::size_t capacity) {
    if (capacity == 0) return {};
    constexpr std::string_view digits = "0123456789ABCDEF";
    std::string result;
    result.reserve(std::min(source.size(), capacity - 1));
    for (std::size_t index = 0; index < source.size(); ++index) {
        const auto value = SferaText::byteValue(source[index]);
        if (value == 0 || result.size() == capacity) break;
        const bool ordinary = (value >= 'a' && value <= 'z') || (value >= 'A' && value <= 'Z') || (value >= '0' && value <= '9') || value == '-' || value == '_' || value == '.' || value == '~';
        if (ordinary) result.append(source.substr(index, 1u));
        else {
            if (capacity - result.size() < 3) break;
            result.push_back('%');
            result.push_back(digits[value / 16]);
            result.push_back(digits[value % 16]);
        }
    }
    if (result.size() == capacity) result.pop_back();
    return result;
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



void SferaNetworkRuntime::updateTcpStatistics() {
    connection_info = connection ? connection->statistics() : SferaNetworkStatistics{};
}

bool SferaText::matchesWildcard(std::string_view text, std::string_view pattern) {
    std::size_t position = 0, token = 0, candidate = 0;
    auto star = std::string_view::npos;
    while (position < text.size()) {
        if (token < pattern.size() && pattern[token] == '*') { star = ++token; candidate = position; }
        else if (token < pattern.size() && (pattern[token] == '?' || pattern[token] == text[position])) { ++token; ++position; }
        else if (star != std::string_view::npos) { token = star; position = ++candidate; }
        else return false;
    }
    while (token < pattern.size() && pattern[token] == '*') ++token;
    return token == pattern.size();
}

int SferaNetworkRuntime::tickDifference(std::uint32_t current, std::uint32_t previous) {
    constexpr int maximumDistance = 14400;
    constexpr std::uint32_t period = 32768;
    const auto difference = current - previous;
    const auto signedDifference = SferaNumeric::signedWord(difference);
    const auto magnitude = signedDifference < 0 ? std::uint32_t{0} - difference : difference;
    if (SferaNumeric::signedWord(magnitude) <= maximumDistance) return signedDifference;
    return SferaNumeric::signedWord(signedDifference < 0 ? difference + period : difference - period);
}

void SferaNetworkRuntime::encodePayload(std::uint8_t* data, std::size_t length) {
    constexpr std::array<std::uint8_t, 9> protocolKey{75, 13, 239, 96, 201, 154, 112, 14, 3};
    std::uint8_t feedback = 0;
    for (std::size_t index = 0; index < length; ++index) {
        const auto value = data[index];
        data[index] = value ^ protocolKey[index % protocolKey.size()] ^ feedback;
        feedback = 2u * feedback + SferaNumeric::lowByte(SferaNumeric::lowWord(index)) * value;
    }
}

void SferaMbcRuntime::resetBytecodeCache() { bytecode_cache.clear(); }

bool SferaConfigTextRuntime::load(const std::string& path) {
    if (path.empty() || path.size() >= filename_capacity) return false;
    const std::string nextPath(path);
    clear(nextPath);
    auto bytes = SferaFileManager::readBounded(nextPath, text_capacity);
    if (!bytes) return false;
    try {
        if (SferaZStream32::hasEnvelope(*bytes)) {
            std::vector<std::uint8_t> decoded(text_capacity);
            std::uint32_t count = SferaNumeric::lowWord(decoded.size() - 1u);
            if (SferaZStream32::decompressEnvelope(decoded.data(), count, *bytes) != 0) { clear(); return false; }
            decoded.resize(count); bytes = std::move(decoded);
        }
        storage_ = SferaText::fromBytes(*bytes);
        return true;
    } catch (const std::exception&) { clear(); return false; }
}
bool SferaConfigTextRuntime::save(bool compressed) const {
    if (filename.empty()) return false;
    const auto input = text();
    if (!compressed) return SferaFileManager::writeFile(filename, std::as_bytes(std::span(input)));
    try {
        std::vector<std::uint8_t> encoded(text_capacity);
        std::uint32_t count = SferaNumeric::lowWord(encoded.size() - 1u);
        const std::vector<std::uint8_t> source(input.begin(), input.end());
        if (SferaZStream32::compressEnvelope(encoded.data(), count, source) != 0) return false;
        return SferaFileManager::writeFile(filename, std::as_bytes(std::span(encoded).first(count)));
    } catch (const std::bad_alloc&) { return false; }
}
std::string SferaConfigTextRuntime::encodeBinary(const std::uint8_t* input, std::size_t size) {
    constexpr std::string_view alphabet = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmno";
    static_assert(alphabet.size() == 64u);
    std::string result;
    result.reserve(size * CHAR_BIT / 6 + 3);
    std::uint32_t pending = 0;
    std::uint32_t count = 0;
    for (std::size_t index = 0; index < size; ++index) {
        pending |= input[index] << count;
        count += CHAR_BIT;
        while (count >= 6) {
            result.push_back(alphabet[pending & 63u]);
            pending >>= 6u;
            count -= 6u;
        }
    }
    result.push_back('#');
    result.push_back(alphabet[count]);
    if (count != 0) result.push_back(alphabet[pending]);
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

void SferaMbcValue::storeAs(Type destinationType, std::span<std::uint8_t> destination) const {
    const auto required = destinationType == Byte ? sizeof(std::uint8_t)
        : destinationType == Integer || destinationType == Real ? sizeof(std::uint32_t) : sizeof(SferaSliceReference32);
    if (destination.size() < required) throw std::out_of_range("Script parameter destination is too small");
    const auto sourceType = type;
    const auto integerValue = sourceType == Real ? truncate(real()) : integer();
    switch (destinationType) {
        case Byte: { const std::uint8_t number = integerValue; std::memcpy(destination.data(), &number, sizeof(number)); break; }
        case Integer: std::memcpy(destination.data(), &integerValue, sizeof(integerValue)); break;
        case Real: { const float number = sourceType == Real ? real() : integer(); std::memcpy(destination.data(), &number, sizeof(number)); break; }
        default: {
            const auto reference = sourceType == Byte || sourceType == Integer || sourceType == Real ? SferaSliceReference32{SferaNumeric::word(integerValue), 0, 0} : value;
            std::memcpy(destination.data(), &reference, sizeof(reference));
            break;
        }
    }
}

void SferaMbcRuntime::bindParameters() {
    const auto declaration = readOperand<std::int8_t>();
    const int capacity = declaration < 0 ? -declaration : declaration;
    if (argument_count < 0 || (declaration >= 0 && argument_count != capacity) || argument_count > capacity) {
        text_buffer = std::format("Wrong number of parameters (must be {}, present {})", +declaration, argument_count);
        reportError(text_buffer);
        return;
    }
    const auto supplied = std::min(capacity, argument_count);
    const auto& stack = g_sfera_mbc_runtime.values;
    if (argument_cursor > std::size(stack) || supplied > std::size(stack) - argument_cursor) { reportError("Parameter stack overflow"); return; }
    for (int index = 0; index < capacity; ++index) {
        const auto type = readOperand<SferaMbcValue::Type>();
        const auto offset = readOperand<std::uint32_t>();
        if (index < supplied) stack[argument_cursor + index].storeAs(type, memoryRange(offset));
        else { const SferaMbcValue zero{}; zero.storeAs(type, memoryRange(offset)); }
    }
}

SferaMbcFunctionRecord* SferaMbcProcessRecord::findFunction(std::string_view name) {
    if (functions.empty()) return nullptr;
    for (std::uint32_t index = 0; index < functions.size(); ++index) if (functions[index].program_index >= 0 && name == functions[index].name) return &functions[index];
    return nullptr;
}

void SferaMbcRuntime::callFunction(bool mainProcess) {
    const auto required = mainProcess ? 1u : 2u;
    argument_count -= required;
    const auto fail = [this]() { active_tag = UINT32_MAX; pushInteger(UINT32_MAX); };
    if (argument_count < 0) { fail(); return; }
    const auto target_word = mainProcess ? 0u : nextWord();
    auto* target = mainProcess ? &processes[0] : target_word == 0 ? nullptr : findProcess(target_word);
    if (target == nullptr || target->functions.empty()) { fail(); return; }
    if (argument_cursor >= argument_end) { reportError("Too few parameters"); fail(); return; }
    SferaMbcFunctionRecord* function = nullptr;
    if (g_sfera_mbc_runtime.values[argument_cursor].type == SferaMbcValue::BytePointer) {
        const auto name = nextSlice();
        const auto text = textIn(name, 31);
        function = target->findFunction(text);
    } else {
        const std::uint32_t tag = nextInteger();
        if (tag < SferaMbcModuleImage::functionSlotCount) {
            const auto index = target->function_map[tag];
            if (index != UINT16_MAX && index < target->functions.size()) function = &target->functions[index];
        }
    }
    if (function == nullptr || function->program_index < 0 || function->program_index >= target->programs.size()) { fail(); return; }
    if (execution_context_depth >= std::ssize(execution_context_stack)) { reportError("Execution context stack overflow"); fail(); return; }
    execution_context_stack[execution_context_depth++] = {
        process_index, program_index, SferaNumeric::lowWord(instruction_cursor - bytecode_base),
        processes[process_index].process_id, processes[process_index].lifetime};
    active_program_record = &program_table_base[program_index];
    active_program_record->instruction_offset = instruction_cursor - bytecode_base;
    auto& targetProgram = target->programs.data()[function->program_index];
    if (targetProgram.executing && !function->allow_reentry) { std::string message; message = std::format("Double \"func\" call, prob. stack corruption: {} (prc {}, tag {}), called from (prc {}, tag {}).\n", function->name, SferaNumeric::signedWord(target_word), SferaNumeric::signedWord(target->module_tag), process_index, SferaNumeric::signedWord(active_process->module_tag)); WorldDiagnostics::warning(message); }
    bytecode_base = target->codeData();
    program_table_base = target->programs.data();
    process_memory_base = target->memory.data();
    instruction_cursor = bytecode_base + function->entry_offset;
    program_index = function->program_index;
    active_program_record = &targetProgram;
    targetProgram.callDepth = 0;
    targetProgram.executing = true;
    active_process = target;
    process_index = SferaNumeric::signedWord(target_word);
    active_tag = 0;
}

void SferaMbcRuntime::returnFromFunction() {
    if (active_program_record->callDepth != 0) {
        const auto offset = SferaNumeric::signedWord(active_program_record->return_offsets[--active_program_record->callDepth]);
        if (offset != -1) {
            if (offset < 0 || active_process == nullptr || offset >= active_process->codeSize()) {
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
        if (context.process_index < 0 || std::cmp_greater_equal(context.process_index, std::size(processes))) continue;
        auto& process = processes[context.process_index];
        if (process.chain_prev_index < 0 || process.process_id != context.process_id || process.lifetime != context.process_lifetime) continue;
        if (context.program_index < 0 || context.program_index >= process.programs.size() || context.instruction_offset >= process.codeSize()) continue;
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
        const double ax = a.x;
        const double ay = a.y;
        const double az = a.z;
        delta = {ax - b.x, ay - b.y, az - b.z};
    } else {
        const auto dimensions = argument_count == 4 || argument_count == 5 ? 2u : 3u;
        std::array<float, 3> first{}, second{};
        for (std::uint32_t index = 0; index < dimensions; ++index) first[index] = nextReal();
        for (std::uint32_t index = 0; index < dimensions; ++index) second[index] = nextReal();
        for (std::uint32_t index = 0; index < dimensions; ++index) {
            const double value = first[index];
            delta[index] = value - second[index];
        }
    }
    const float square = delta[1] * delta[1] + delta[0] * delta[0] + delta[2] * delta[2];
    pushReal(argument_count == 2 || argument_count == 4 || argument_count == 6 ? std::sqrt(square) : square);
}

void SferaMbcRuntime::scanText() {
    const auto source = nextAddress();
    const auto format = nextAddress();
    const auto type = argument_cursor < argument_end ? g_sfera_mbc_runtime.values[argument_cursor].type : SferaMbcValue::Byte;
    using Number = std::variant<std::monostate, std::int8_t, std::uint8_t, std::int16_t, std::uint16_t, int, std::uint32_t, std::int64_t, std::uint64_t, float, double>;
    std::array<Number, 4> numbers{};
    std::array<void*, 4> destinations{};
    std::array<SferaSliceReference32, 4> references{};
    std::array<unsigned, 4> capacities{};
    std::array<int, 4> completed; completed.fill(-1);
    std::array<std::size_t, 4> characterCounts{};
    std::array<std::variant<std::monostate, std::string, std::wstring>, 4> textOutputs{};
    const auto count = std::min(argument_count > 2 ? argument_count - 2 : 1u, 4u);
    for (std::uint32_t index = 0; index < count; ++index) {
        references[index] = nextAddress();
    }
    if (execution_failed) return;
    if (argument_count < 3 || argument_count > 6 || (argument_count == 3 && type != SferaMbcValue::IntegerPointer && type != SferaMbcValue::RealPointer && type != SferaMbcValue::BytePointer)) { pushInteger(source.base); return; }
    const auto text = textIn(source);
    if (text.size() > INT_MAX) { reportError("Scan input is too large"); return; }
    const auto pattern = textIn(format);
    std::string normalized;
    std::size_t output = 0;
    const auto number = [&]<class T>() {
        auto& reference = references[output];
        if (!reference.contains(sizeof(T))) { reference.diagnoseRange(sizeof(T)); execution_failed = true; return; }
        T value{};
        const auto bytes = sliceBytes(reference, sizeof(T));
        std::memcpy(&value, bytes.data(), sizeof(T));
        numbers[output] = value;
        destinations[output] = &std::get<T>(numbers[output]);
    };
    const auto character = [&](std::size_t position) { return position < pattern.size() ? pattern[position] : '\0'; };
    for (std::size_t token = 0; token < pattern.size(); ++token) {
        if (character(token) != '%') { normalized += character(token); continue; }
        const auto start = token++;
        if (character(token) == '%') { normalized += "%%"; continue; }
        const bool suppressed = character(token) == '*';
        if (suppressed) ++token;
        const auto widthStart = token;
        while (character(token) >= '0' && character(token) <= '9') ++token;
        std::optional<unsigned> fieldWidth;
        if (token != widthStart) {
            unsigned width = 0;
            if (std::from_chars(pattern.data() + widthStart, pattern.data() + token, width).ec != std::errc{} || width == 0 || width > INT_MAX) {
                reportError("Invalid scan field width"); return;
            }
            fieldWidth = width;
        }
        normalized.append(pattern.substr(start, token - start));
        const auto lengthStart = token;
        while (character(token) != '\0' && std::string_view("hljztLwI").find(character(token)) != std::string_view::npos) if (character(token++) == 'I') while (character(token) >= '0' && character(token) <= '9') ++token;
        const auto length = pattern.substr(lengthStart, token - lengthStart);
        const auto conversion = character(token);
        if (conversion == '\0') { reportError("Incomplete scan format"); return; }
        if (!suppressed && output >= count) { reportError("Too few scan destinations"); return; }
        if (std::string_view("cCsS[").find(conversion) != std::string_view::npos) {
            if (!length.empty() && length != "h" && length != "l" && length != "w") { reportError("Invalid scan text modifier"); return; }
            const auto conversionStart = token;
            if (conversion == '[') {
                if (character(token + 1) == '^') ++token;
                if (character(token + 1) == ']') ++token;
                do { ++token; } while (character(token) != '\0' && character(token) != ']');
                if (character(token) == '\0') { reportError("Incomplete scan character set"); return; }
            }
            normalized.append(length);
            normalized.append(pattern.substr(conversionStart, token + 1 - conversionStart));
            if (!suppressed) {
                const auto& reference = references[output];
                const auto bytes = sliceBytes(reference);
                const bool wide = length != "h" && (length == "l" || length == "w" || conversion == 'C' || conversion == 'S');
                const auto count = bytes.size() / (wide ? sizeof(std::uint16_t) : 1u);
                if (count == 0 || count > UINT_MAX) { reportError("Invalid scan destination range"); return; }
                capacities[output] = count;
                if (conversion == 'c' || conversion == 'C') characterCounts[output] = fieldWidth.value_or(1u);
                if (wide) {
                    SferaBinary::Reader reader(bytes);
                    std::wstring value(count, L'\0');
                    for (auto& character : value) character = reader.read<std::uint16_t>();
                    textOutputs[output] = std::move(value);
                    destinations[output] = std::get<std::wstring>(textOutputs[output]).data();
                } else {
                    textOutputs[output] = SferaText::fromBytes(bytes);
                    destinations[output] = std::get<std::string>(textOutputs[output]).data();
                }
            }
        } else if (std::string_view("diouxXnp").find(conversion) != std::string_view::npos) {
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
        } else if (std::string_view("aAeEfFgG").find(conversion) != std::string_view::npos) {
            const bool wide = length == "l" || length == "L";
            if (wide) normalized += 'l';
            normalized += conversion;
            if (!suppressed) { if (wide) number.template operator()<double>(); else number.template operator()<float>(); }
        } else { reportError("Unsupported scan conversion"); return; }
        if (execution_failed) return;
        if (!suppressed) { normalized += "%n"; ++output; }
    }
    const auto scan = [&]<std::size_t Index>(auto&& self, auto... arguments) -> int {
        if constexpr (Index == 4) return ::sscanf_s(text.c_str(), normalized.c_str(), arguments...);
        else if (capacities[Index] != 0) return self.template operator()<Index + 1>(self, arguments..., destinations[Index], capacities[Index], &completed[Index]);
        else return self.template operator()<Index + 1>(self, arguments..., destinations[Index], &completed[Index]);
    };
    const auto result = scan.template operator()<0>(scan);
    for (std::size_t index = 0; index < output; ++index) {
        if (completed[index] < 0) continue;
        std::visit([&](const auto& value) {
            if constexpr (!std::is_same_v<std::remove_cvref_t<decltype(value)>, std::monostate>) {
                const auto bytes = sliceBytes(references[index], sizeof(value));
                std::memcpy(bytes.data(), &value, sizeof(value));
            }
        }, numbers[index]);
        std::visit([&](const auto& value) {
            using T = std::remove_cvref_t<decltype(value)>;
            if constexpr (std::is_same_v<T, std::string> || std::is_same_v<T, std::wstring>) {
                const auto characters = characterCounts[index];
                const auto end = characters != 0 ? characters : value.find(typename T::value_type{});
                if (end > value.size() || (characters == 0 && end == value.size()))
                    throw std::out_of_range("Invalid scan result length");
                const auto count = characters != 0 ? end : end + 1;
                if constexpr (std::is_same_v<T, std::string>) {
                    const auto bytes = sliceBytes(references[index], count);
                    if (count != 0) std::memmove(bytes.data(), value.data(), count);
                } else {
                    const auto bytes = sliceBytes(references[index], count * sizeof(std::uint16_t));
                    for (std::size_t character = 0; character < count; ++character)
                        SferaBinary::writeLittleEndian<std::uint16_t>(bytes.data() + character * sizeof(std::uint16_t), value[character]);
                }
            }
        }, textOutputs[index]);
    }
    pushInteger(result);
}

std::string SferaMbcRuntime::nextText() {
    const auto slice = nextSlice();
    if (slice.base == 0) { reportError("poppointerup(): unexpected NULL-pointer fetched"); return {}; }
    return textIn(slice);
}

void SferaMbcRuntime::copyText(const SferaSliceReference32& destination, std::string_view text) {
    const auto length = text.size() + 1;
    if (length > UINT32_MAX || !destination.contains(length)) {
        auto invalid = destination;
        invalid.diagnoseRange(std::min<std::size_t>(length, UINT32_MAX));
        return;
    }
    auto output = textBuffer(destination);
    if (length > output.size()) throw std::out_of_range("Script string destination is too small");
    output.assign(text);
}

void SferaMbcRuntime::parseText() {
    const auto operation = nextInteger();
    if (operation < 0 || operation > 7) { reportError("ffparse(). Invalid parsing type"); return; }
    const auto destination = operation < 2 ? nextSlice() : SferaSliceReference32{};
    const auto source = nextSlice();
    const auto limit = nextSlice();
    if (execution_failed) return;
    if (source.base == 0 || (operation < 2 && destination.base == 0)) { reportError("poppointerup(): unexpected NULL-pointer fetched"); return; }
    const auto text = textIn(source);
    const auto end = limit.base != 0 && limit.base >= source.base ? std::min<std::size_t>(text.size(), limit.base - source.base) : text.size();
    std::size_t cursor = 0;
    std::optional<std::size_t> result;
    const auto digit = [](std::uint8_t value) { return value >= '0' && value <= '9'; };
    const auto letter = [](std::uint8_t value) { return (value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z') || value == '_'; };
    const auto space = [](std::uint8_t value) { return value == ' ' || value == '\t'; };
    if (cursor < end) {
        if (operation < 2) {
            const bool negative = text[cursor] == '-';
            if (negative) ++cursor;
            if (cursor < end && digit(text[cursor])) {
                if (!destination.contains(sizeof(std::uint32_t))) { auto invalid = destination; invalid.diagnoseRange(sizeof(std::uint32_t)); return; }
                if (operation == 0) {
                    std::uint32_t value = 0;
                    do { value = value * 10u + SferaText::byteValue(text[cursor++]) - '0'; } while (cursor < end && digit(text[cursor]));
                    writeMemory(destination.base, negative ? 0u - value : value);
                } else {
                    float value = 0.0f;
                    do { value = value * 10.0 + (text[cursor++] - '0'); } while (cursor < end && digit(text[cursor]));
                    if (cursor < end && text[cursor] == '.') {
                        ++cursor;
                        float scale = 0.1f;
                        while (cursor < end && digit(text[cursor])) {
                            const double digit_value = text[cursor++] - '0';
                            value = digit_value * scale + value;
                            scale = scale / 10.0;
                        }
                    }
                    writeMemory(destination.base, negative ? -value : value);
                }
                result = cursor;
            }
        } else if (operation == 2 && SferaText::byteValue(text[cursor]) > ' ') {
            do { ++cursor; } while (cursor < end && SferaText::byteValue(text[cursor]) > ' ');
            result = cursor;
        } else if (operation == 3 && text[cursor] == '"') {
            ++cursor;
            while (cursor < end && text[cursor] != '\r' && text[cursor] != '\n' && text[cursor] != '"') ++cursor;
            if (cursor < end && text[cursor] == '"') result = cursor + 1;
        } else if (operation == 4 && letter(text[cursor])) {
            do { ++cursor; } while (cursor < end && (letter(text[cursor]) || digit(text[cursor])));
            result = cursor;
        } else if (operation == 5 && space(text[cursor])) {
            do { ++cursor; } while (cursor < end && space(text[cursor]));
            result = cursor;
        } else if (operation >= 6) {
            while (cursor < end && (operation == 6 ? space(text[cursor]) : text[cursor] != '\r' && text[cursor] != '\n')) ++cursor;
            if (cursor < end && text[cursor] == '\r') { ++cursor; if (cursor < end && text[cursor] == '\n') result = cursor + 1; }
        }
    }
    if (!result) pushSlice({}, SferaMbcValue::BytePointer);
    else {
        // Return an address in the original script region, never in the decoded text copy.
        const auto remaining = text.size() - *result;
        const auto address = mapMemory(memoryAt(source.base, text.size() + 1) + *result, remaining + 1);
        pushSlice({address, address, address + SferaNumeric::lowWord(remaining)}, SferaMbcValue::BytePointer);
    }
}

void SferaMbcRuntime::chatUtility() {
    const auto operation = nextInteger();
    if (operation < 0 || operation > 4) { reportError("ffchat_utility(). Invalid Chat utility function type"); return; }
    std::string input{}, output{}, plain{};
    const auto source = nextText();
    if (execution_failed) return;
    input.assign(source);
    if (operation == 0) {
        std::string target{}, caption{};
        target.assign(nextText());
        caption.assign(nextText());
        const auto destination = nextSlice();
        if (execution_failed) return;
        output = SphereUI::HyperTextParser::buildLink(input, target, caption);
        copyText(destination, output);
    } else if (operation == 1) {
        const auto destination = nextSlice();
        if (execution_failed) return;
        output = SphereUI::HyperTextParser::plainText(input);
        copyText(destination, output);
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
        if (plainDestination.base != 0) copyText(plainDestination, plain);
        if (markupDestination.base != 0) copyText(markupDestination, output);
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

class MbcUiMessageCodec {
    SferaMbcRuntime& runtime_;
    std::uint32_t flags_;

    std::string text(std::uint32_t address) const {
        return address == 0u ? std::string{} : runtime_.textAt(address);
    }

    std::optional<std::string> optionalText(std::uint32_t address) const {
        return address == 0u ? std::nullopt : std::optional<std::string>{text(address)};
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
        write<std::uint8_t>(address, value ? 1u : 0u);
    }

    void writeSize(std::uint32_t address, std::size_t value) const {
        if (!std::in_range<std::uint32_t>(value)) {
            runtime_.reportError("UI result exceeds an MBC word");
            return;
        }
        write(address, SferaNumeric::lowWord(value));
    }

    void writeText(std::uint32_t address, std::string_view value, std::size_t explicit_capacity = std::numeric_limits<std::size_t>::max(), std::size_t content_limit = std::numeric_limits<std::size_t>::max()) const {
        if (address == 0u || explicit_capacity == 0u) return;
        auto destination = runtime_.memoryRange(address);
        const auto capacity = std::min(destination.size(), explicit_capacity);
        if (capacity == 0u) return;
        SferaText::Buffer(destination.first(capacity)).write(value.substr(0, content_limit));
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
        SphereUI::ImageDescription result{};
        if (address == 0u) return result;
        SferaBinary::Reader reader(bytes(address, 156u));
        // The on-wire names have 64 bytes; the final byte has always been reserved for NUL.
        result.name = SferaText::prefix(reader.take(64u), 63u);
        result.image.texture_name = SferaText::prefix(reader.take(64u), 63u);
        result.image.width = reader.read<std::int32_t>();
        result.image.height = reader.read<std::int32_t>();
        result.image.rectangle.left = reader.read<std::int32_t>();
        result.image.rectangle.top = reader.read<std::int32_t>();
        result.image.rectangle.right = reader.read<std::int32_t>();
        result.image.rectangle.bottom = reader.read<std::int32_t>();
        result.image.flags = reader.read<std::uint32_t>();
        return result;
    }

public:
    MbcUiMessageCodec(SferaMbcRuntime& runtime, std::uint32_t flags) : runtime_(runtime), flags_(flags) {}

    std::uint32_t dispatch(SphereUI::Window* window, SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) const {
        using SphereUI::UiMessage;

        if (message == UiMessage::showHelpPage) {
            g_sfera_interface.showHelpPage(optionalText(first));
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
                    write(first, SferaNumeric::word(window->childControlAt(position.x, position.y)));
                }
                return 1u;
            case UiMessage::getModal:
                if (window != nullptr) writeBool(first, window->modal_owner != nullptr);
                return 1u;
            case UiMessage::getChecked:
                if (const auto* control = window != nullptr ? window->asCheckBox() : nullptr) writeBool(first, control->checked);
                return 1u;
            case UiMessage::setEditText:
                if (auto* control = window != nullptr ? window->asEditCtrl() : nullptr) control->setEditText(text(first));
                return 1u;
            case UiMessage::getEditText:
                if (const auto* control = window != nullptr ? window->asEditCtrl() : nullptr) writeText(first, control->text, std::numeric_limits<std::size_t>::max(), 250u);
                return 1u;
            case UiMessage::appendListText:
                if (auto* control = window != nullptr ? window->asListCtrl() : nullptr; control != nullptr && first != 0u) control->appendMessageText(text(first), second);
                return 1u;
            case UiMessage::setListText:
                if (auto* control = window != nullptr ? window->asListCtrl() : nullptr) control->setRowText(first, second == 0u ? std::string_view{" "} : text(second));
                return 1u;
            case UiMessage::getListSelection:
                if (const auto* control = window != nullptr ? window->asListCtrl() : nullptr) write(first, control->selected_index);
                return 1u;
            case UiMessage::getListText:
                if (const auto* control = window != nullptr ? window->asListCtrl() : nullptr; control != nullptr && second < control->rows.size()) writeText(first, control->rowText(second));
                return 1u;
            case UiMessage::getListSize:
                if (const auto* control = window != nullptr ? window->asListCtrl() : nullptr) writeSize(first, control->rows.size());
                return 1u;
            case UiMessage::getListColor:
                if (const auto* control = window != nullptr ? window->asListCtrl() : nullptr; control != nullptr && second < control->rows.size()) write(first, control->rows.at(control->physicalIndex(second)).color);
                return 1u;
            case UiMessage::getListScroll:
                if (const auto* control = window != nullptr ? window->asListCtrl() : nullptr) write(first, control->vertical_offset);
                return 1u;
            case UiMessage::appendFilteredListText:
                if (auto* control = window != nullptr ? window->asFilterListCtrl() : nullptr; control != nullptr && first != 0u) control->appendFilteredText(text(first), second);
                return 1u;
            case UiMessage::getSelectedFont:
                if (const auto* control = window != nullptr ? window->asFontPicker() : nullptr) write(first, control->getFont());
                return 1u;
            case UiMessage::setImageName:
                if (auto* control = window != nullptr ? window->asImageCtrl() : nullptr) {
                    if (first == 0u) control->setImage(nullptr);
                    else control->setImageName(text(first));
                }
                return 1u;
            case UiMessage::setImageRotation:
                if (auto* control = window != nullptr ? window->asImageCtrl() : nullptr) control->setRotationDegrees(SferaBinary::floatFromBits(first));
                return 1u;
            case UiMessage::setImageDescription:
                if (auto* control = window != nullptr ? window->asImageCtrl() : nullptr) {
                    if (first == 0u) control->setImage(nullptr);
                    else { const auto description = imageDescription(first); control->setImage(&description); }
                }
                return 1u;
            case UiMessage::getListItemSelection:
                if (const auto* control = window != nullptr ? window->asListItemCtrl() : nullptr) write(first, control->selected_index);
                return 1u;
            case UiMessage::getListItemCount:
                if (const auto* control = window != nullptr ? window->asListItemCtrl() : nullptr) writeSize(first, control->items.size());
                return 1u;
            case UiMessage::setTooltipLine:
                if (auto* control = tooltip(window)) control->setLine(first, optionalText(second));
                return 1u;
            case UiMessage::getTooltipLine:
                if (const auto* control = tooltip(window); control != nullptr && second < control->lines.size()) writeText(first, control->lines.at(second));
                return 1u;
            case UiMessage::appendTooltipLine:
                if (auto* control = tooltip(window)) control->appendLine(text(first));
                return 1u;
            case UiMessage::getProgressRange:
                if (const auto* control = window != nullptr ? window->asProgressBar() : nullptr) { write(first, control->minimum); write(second, control->maximum); }
                return 1u;
            case UiMessage::getProgressValue:
                if (const auto* control = window != nullptr ? window->asProgressBar() : nullptr) write(first, control->current);
                return 1u;
            case UiMessage::getScrollRange:
                if (const auto* control = window != nullptr ? window->asScrollBar() : nullptr) { write(first, control->minimum); write(second, control->maximum); }
                return 1u;
            case UiMessage::setScrollParameters:
                if (auto* control = window != nullptr ? window->asScrollBar() : nullptr; control != nullptr && first != 0u) {
                    const auto wire = read<MbcScrollParameters32>(first);
                    control->setParameters({wire.size, wire.mask, wire.minimum, wire.maximum, wire.page_step, wire.current, wire.step});
                }
                return 1u;
            case UiMessage::getScrollParameters:
                if (const auto* control = window != nullptr ? window->asScrollBar() : nullptr; control != nullptr && first != 0u) {
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
                if (const auto* control = window != nullptr ? window->asScrollBar() : nullptr) write(first, control->current);
                return 1u;
            case UiMessage::getSpinRange:
                if (const auto* control = window != nullptr ? window->asSpinButton() : nullptr) { write(first, control->minimum); write(second, control->maximum); }
                return 1u;
            case UiMessage::getSpinStep:
                if (const auto* control = window != nullptr ? window->asSpinButton() : nullptr) write(first, control->step);
                return 1u;
            case UiMessage::getSpinValue:
                if (const auto* control = window != nullptr ? window->asSpinButton() : nullptr) write(first, control->current);
                return 1u;
            case UiMessage::appendMenuItem:
                if (auto* control = window != nullptr ? window->asMenuListControl() : nullptr) control->addItem(text(first), second != 0u);
                return 1u;
            case UiMessage::setMenuItemText:
                if (auto* control = window != nullptr ? window->asMenuListControl() : nullptr; control != nullptr && first < control->items.size()) control->items.at(first).text.assign(second == 0u ? std::string_view{} : runtime_.textAt(second));
                return 1u;
            case UiMessage::setSlotItem:
                if (auto* control = window != nullptr ? window->asSlotCtrl() : nullptr) control->setItem(optionalText(first));
                return 1u;
            case UiMessage::setSlotDescription:
                if (auto* control = window != nullptr ? window->asSlotCtrl() : nullptr) control->description.assign(first == 0u ? std::string_view{} : runtime_.textAt(first));
                return 1u;
            case UiMessage::setSlotTopLeftOverlay:
            case UiMessage::setSlotBottomRightOverlay:
            case UiMessage::setSlotBottomLeftOverlay:
                if (auto* control = window != nullptr ? window->asSlotCtrl() : nullptr) {
                    auto& target = message == UiMessage::setSlotTopLeftOverlay ? control->top_left_overlay : message == UiMessage::setSlotBottomRightOverlay ? control->bottom_right_overlay : control->bottom_left_overlay;
                    control->setOverlay(target, optionalText(first));
                }
                return 1u;
            case UiMessage::setRichEditContent:
                if (auto* control = window != nullptr ? window->asRichEditCtrl() : nullptr; control != nullptr && first != 0u) control->setContent(runtime_.textAt(first));
                return 1u;
            case UiMessage::getRichEditContent:
                if (const auto* control = window != nullptr ? window->asRichEditCtrl() : nullptr; control != nullptr && first != 0u && second != 0u) {
                    auto destination = runtime_.memoryRange(first);
                    const auto capacity = std::min<std::size_t>(destination.size(), second);
                    SferaText::Buffer(destination.first(capacity)).write(control->content(capacity == 0 ? 0 : capacity - 1));
                }
                return 1u;
            case UiMessage::loadHyperTextPage:
                if (auto* control = window != nullptr ? window->asHyperTextCtrl() : nullptr) control->queuePage(text(first), second != 0u);
                return 1u;
            case UiMessage::loadHyperTextBuffer:
                if (auto* control = window != nullptr ? window->asHyperTextCtrl() : nullptr; control != nullptr && first != 0u && second != 0u) {
                    const auto source = bytes(first, second);
                    control->queueBuffer(SferaText::fromBytes(source));
                }
                return 1u;
            case UiMessage::appendChatMessage:
                if (auto* control = window != nullptr ? window->asHyperTextChatListControl() : nullptr; control != nullptr && first != 0u && second != 0u) {
                    const auto parameters = words(second, 2u);
                    control->addMessage(runtime_.textAt(first), parameters[0], parameters[1]);
                }
                return 1u;
            case UiMessage::setChatChannels:
                if (auto* control = window != nullptr ? window->asHyperTextChatListControl() : nullptr) {
                    if (first == 0u) control->setChannels(std::span<const std::uint32_t>{});
                    else if (second != 0u) { const auto values = words(second, first); control->setChannels(std::span<const std::uint32_t>(values)); }
                }
                return 1u;
            case UiMessage::getChatPlainText:
            case UiMessage::getChatHyperText:
                if (const auto* control = window != nullptr ? window->asHyperTextChatListControl() : nullptr) writeText(second, control->messageText(first, message == UiMessage::getChatPlainText));
                return 1u;
            case UiMessage::getSelectedChatLink:
                if (const auto* control = window != nullptr ? window->asHyperTextChatListControl() : nullptr) { writeText(first, control->selected_link_text); writeText(second, control->selected_link_value); }
                return 1u;
            case UiMessage::getSelectedChatHyperText:
                if (const auto* control = window != nullptr ? window->asHyperTextChatListControl() : nullptr) writeText(first, control->selected_hyper_text);
                return 1u;
            case UiMessage::getSelectedChatPlainText:
                if (const auto* control = window != nullptr ? window->asHyperTextChatListControl() : nullptr) writeText(first, control->selected_plain_text);
                return 1u;
            case UiMessage::setHyperEditContent:
                if (auto* control = window != nullptr ? window->asHyperTextEditControl() : nullptr; control != nullptr && first != 0u) control->setContent(runtime_.textAt(first), second);
                return 1u;
            case UiMessage::getHyperEditPlainText:
                if (const auto* control = window != nullptr ? window->asHyperTextEditControl() : nullptr) writeText(first, control->visible_text);
                return 1u;
            case UiMessage::getHyperEditHyperText:
                if (const auto* control = window != nullptr ? window->asHyperTextEditControl() : nullptr) writeText(first, control->hyper_text);
                return 1u;
            case UiMessage::getHyperEditLengths:
                if (const auto* control = window != nullptr ? window->asHyperTextEditControl() : nullptr) { writeSize(first, control->visible_text.size()); writeSize(second, control->hyper_text.size()); }
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
    const auto operation = SferaNumeric::enumFromBits<WindowOperation>(SferaNumeric::word(nextInteger()));
    std::array<std::int32_t, 6> arguments{};
    const auto read = [this, &arguments](std::size_t count) { for (std::size_t index = 0; index < count; ++index) arguments[index] = nextInteger(); return !execution_failed; };
    const auto inputText = [this](std::int32_t offset) { return offset == 0 ? std::string{} : textAt(SferaNumeric::word(offset)); };
    const auto optionalInputText = [&inputText](std::int32_t offset) -> std::optional<std::string> { return offset == 0 ? std::nullopt : std::optional<std::string>{inputText(offset)}; };
    const auto warnNull = [operation](std::int32_t offset, std::uint32_t argument) { if (offset == 0) { std::string message; message = std::format("NULL-pointer dereferencing: window, command {}, argument {}\n", SferaNumeric::lowWord(SferaNumeric::enumBits(operation)), argument); WorldDiagnostics::warning(message); } };
    switch (operation) {
        case WindowOperation::Create: {
            if (!read(6)) return;
            const auto handle = GameInterface::createWindow(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5]);
            pushInteger(handle);
            if (SferaNumeric::signedWord(handle) < 0) reportError("Error creating window");
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
            g_sfera_interface.setCursorImage(optionalInputText(arguments[0]), arguments[0] != 0 ? positioned ? arguments[1] : 8 : 0, arguments[0] != 0 ? positioned ? arguments[2] : 16 : 0);
            if (auto* cursor = g_sfera_interface.cursor.get()) cursor->setImage(2, std::nullopt, 0, 0);
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
            auto* window = nativeResource<SphereUI::Window*>(SferaNumeric::word(arguments[0]));
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
            if (auto* window = nativeResource<SphereUI::Window*>(SferaNumeric::word(arguments[0]))) window->setText(inputText(arguments[1]));
            pushInteger(0);
            break;
        case WindowOperation::ControlAt: case WindowOperation::ItemAt: {
            if (!read(2)) return;
            auto* window = nativeResource<SphereUI::Window*>(SferaNumeric::word(arguments[0]));
            SphereUI::Window* result = nullptr;
            if (window) { if (operation == WindowOperation::ControlAt) result = window->controlAt(arguments[1]); else if (auto* list = window->asListItemCtrl()) result = list->itemAt(arguments[1]); }
            pushInteger(nativeHandle(result));
            break;
        }
        case WindowOperation::SendMessage: {
            if (!read(5)) return;
            MbcUiMessageCodec codec(*this, SferaNumeric::word(arguments[4]));
            codec.dispatch(
                nativeResource<SphereUI::Window*>(SferaNumeric::word(arguments[0])),
                SferaNumeric::enumFromBits<SphereUI::UiMessage>(SferaNumeric::word(arguments[1])),
                SferaNumeric::word(arguments[2]),
                SferaNumeric::word(arguments[3]));
            pushInteger(0);
            break;
        }
        case WindowOperation::GetText: {
            if (!read(3)) return;
            warnNull(arguments[1], 1);
            const std::size_t requested_capacity = std::max(arguments[2], 1);
            const auto content_capacity = requested_capacity - 1u;
            if (arguments[1] != 0) {
                auto destination = memoryRange(SferaNumeric::word(arguments[1]));
                const auto* window = nativeResource<SphereUI::Window*>(SferaNumeric::word(arguments[0]));
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
        case WindowOperation::SavedPositionsSize: { const auto size = g_sfera_interface.savedPositionsSize(); if (!std::in_range<std::uint32_t>(size)) { reportError("Saved window positions exceed the MBC buffer limit"); break; } pushInteger(SferaNumeric::lowWord(size)); break; }
        case WindowOperation::ReadSavedPositions:
            if (!read(2)) return;
            {
                const std::uint32_t size = SferaNumeric::word(arguments[1]);
                const auto* data = memoryAt(SferaNumeric::word(arguments[0]), size);
                g_sfera_interface.readSavedPositions(std::as_bytes(std::span(data, size)));
            }
            break;
        case WindowOperation::WriteSavedPositions: {
            if (!read(1)) return;
            const auto size = g_sfera_interface.savedPositionsSize();
            if (!std::in_range<std::uint32_t>(size)) { reportError("Saved window positions exceed the MBC buffer limit"); break; }
            g_sfera_interface.writeSavedPositions(std::as_writable_bytes(std::span(memoryAt(SferaNumeric::word(arguments[0]), size), size)));
            break;
        }
        case WindowOperation::Position: case WindowOperation::Size: {
            if (!read(3)) return;
            if (operation == WindowOperation::Position) { warnNull(arguments[1], 1); warnNull(arguments[2], 2); }
            const auto* window = nativeResource<SphereUI::Window*>(SferaNumeric::word(arguments[0]));
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
            g_sfera_interface.setTooltipText(optionalInputText(arguments[0]));
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
            if (arguments[1] != 0 && arguments[2] > 0) *memoryAt(SferaNumeric::word(arguments[1]), 1u) = 0u;
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

bool SferaTcpConnectionContext::acceptPacket(std::string_view packet, std::stop_token stop) {
    const auto header = SferaTcpIncomingHeader::decode(std::as_bytes(std::span(packet)));
    switch (SferaNumeric::enumFromBits<TcpMessage>(header.message)) {
    case TcpMessage::connection_limit:
        fail();
        return false;
    case TcpMessage::handshake: {
        if (packet.size() < SferaTcpHandshakePacket::encodedSize) { fail(); return false; }
        const auto handshake = SferaTcpHandshakePacket::decode(std::as_bytes(std::span(packet)));
        if (handshake.remote_id == 0) { fail(); return false; }
        {
            std::lock_guard lock(send_mutex_);
            checksum_seed_ = handshake.checksum_seed;
            sequence_ = std::rand() % 1000 + 1;
            std::array<std::uint8_t, 4> mode{};
            SferaBinary::writeLittleEndian(mode.data(), owner_.client_mode);
            if (!queuePacket(mode.size(), TcpMessage::client_mode, mode.data())) return false;
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
        std::string bytes;
        bytes.reserve(kTcpReceiveBufferCapacity);
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
                const int requested = SferaNumeric::signedWord(SferaNumeric::lowWord(std::min<std::size_t>(available, 8192u)));
                if (bytes.size() + requested > kTcpReceiveBufferCapacity && first != 0) {
                    bytes.erase(0, first);
                    first = 0;
                }
                const auto previous_size = bytes.size();
                bytes.resize(previous_size + requested);
                const int count = ::recv(socket_.value, bytes.data() + previous_size, requested, 0);
                const int error = count == SOCKET_ERROR ? ::WSAGetLastError() : 0;
                bytes.resize(previous_size + (count > 0 ? count : 0));
                if (count == 0) { if (!stop.stop_requested()) fail(); break; }
                if (count == SOCKET_ERROR) {
                    if (error != WSAEWOULDBLOCK && error != WSAEINTR) { if (!stop.stop_requested()) fail(); break; }
                } else {
                    std::lock_guard lock(statistics_mutex_);
                    received_bytes_window_ += count;
                }
            }
            while (bytes.size() - first >= SferaTcpIncomingHeader::encodedSize) {
                const auto header = SferaTcpIncomingHeader::decode(std::as_bytes(std::span(bytes)).subspan(first));
                if (header.size < SferaTcpIncomingHeader::encodedSize || header.size > kTcpReceiveBufferCapacity) { fail(); break; }
                if (bytes.size() - first < header.size) break;
                if (!acceptPacket(std::string_view(bytes).substr(first, header.size), stop)) break;
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
        std::uint32_t random_interval = std::rand() % 5000 + 2000;
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
                random_interval = (std::rand() % 10000 + 3000);
                random_tick = now;
                std::lock_guard lock(send_mutex_);
                std::array<std::uint8_t, 4> count{};
                SferaBinary::writeLittleEndian(count.data(), packet_counter_);
                queuePacket(count.size(), TcpMessage::packet_counter, count.data());
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
            if (outgoing_offset_ > packet.size()) throw std::out_of_range("Invalid outgoing packet offset");
            const auto remaining = packet.size() - outgoing_offset_;
            if (remaining == 0u) { fail(); return; }
            const int request = SferaNumeric::signedWord(SferaNumeric::lowWord(std::min<std::size_t>(remaining, INT_MAX)));
            const int sent = ::send(socket_.value, packet.data() + outgoing_offset_, request, 0);
            if (sent == SOCKET_ERROR) {
                const auto error = ::WSAGetLastError();
                if (error != WSAEWOULDBLOCK && error != WSAEINTR) fail();
                return;
            }
            if (sent == 0) { fail(); return; }
            outgoing_offset_ += SferaNumeric::lowWord(sent);
            outgoing_bytes_ -= sent;
            { std::lock_guard stats_lock(statistics_mutex_); sent_bytes_window_ += sent; }
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
        const std::uint16_t packet_size = payloadSize + SferaTcpOutgoingHeader::encodedSize;
        std::string packet(packet_size, '\0');
        const auto wire = std::as_writable_bytes(std::span(packet));
        const std::uint16_t next_sequence = sequence_ + std::rand() % 4 + 1;
        SferaTcpOutgoingHeader{packet_size, 0u, next_sequence, SferaNumeric::enumBits(message)}.encode(wire);
        if (payloadSize != 0) std::memcpy(packet.data() + SferaTcpOutgoingHeader::encodedSize, payload, payloadSize);
        std::uint16_t checksum = 0;
        for (std::size_t i = SferaTcpOutgoingHeader::checksumPayloadOffset; i < packet.size(); ++i)
            checksum = SferaNumeric::lowHalf(SferaNumeric::word(checksum + SferaNumeric::signedByte(wire[i])));
        SferaBinary::writeLittleEndian(wire.data() + SferaTcpOutgoingHeader::checksumOffset,
            SferaNumeric::lowHalf(checksum_seed_ ^ checksum));
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
    message[0] = SferaNumeric::lowByte(flags);
    std::copy(payload.begin(), payload.end(), message.begin() + 1u);
    encodePayload(message.data() + 1u, payload.size());
    if (!connection->queuePacket(message.size(), TcpMessage::payload, message.data())) return false;
    sent_bytes.fetch_add(payload.size());
    return true;
}

std::uint32_t SferaMbcBitStream::read(unsigned width) {
    if (!valid_ || width > 32 || position_ > data_.size() * 8 || width > data_.size() * 8 - position_) { valid_ = false; return 0; }
    std::uint32_t value = 0;
    for (unsigned bit = 0; bit < width; ++bit, ++position_) value |= ((data_[position_ / 8] >> (position_ % 8)) & 1u) << bit;
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
    while (bits != 0 && valid_) { const unsigned width = std::min<std::size_t>(bits, 32); write(source.read(width), width); bits -= width; }
}

std::uint32_t SferaMbcBitStream::encodeCoordinate(int origin, float coordinate) {
    const float reference = origin;
    const double coordinate_value = coordinate;
    const float magnitude = std::fabs(coordinate_value - reference);
    if (!std::isfinite(magnitude) || magnitude >= 120.0f) return UINT32_MAX;
    const float inverse = 1.0 / (magnitude + 40.0);
    constexpr float minimum_float = 0.0062500000931322575f;
    const double minimum = minimum_float;
    const auto normalized = (inverse - minimum) / (g_sfera_mbc_runtime.inverse_coordinate_scale - minimum);
    return SferaNumeric::truncatedWord(normalized * coordinateMagnitudeMask) | (coordinate < reference ? coordinateSignBit : 0u);
}

float SferaMbcBitStream::decodeCoordinate(int origin, std::uint32_t code) {
    constexpr float minimum_float = 0.0062500000931322575f;
    const double minimum = minimum_float;
    const double encoded_magnitude = code & coordinateMagnitudeMask;
    const double magnitude_limit = coordinateMagnitudeMask;
    const float inverse = (g_sfera_mbc_runtime.inverse_coordinate_scale - minimum) * (encoded_magnitude / magnitude_limit) + minimum;
    float distance = 1.0 / inverse - 40.0;
    if (code & coordinateSignBit) distance = -distance;
    const double origin_value = origin;
    return origin_value + distance;
}

std::uint32_t SferaMbcBitStream::readField(std::int8_t format, std::span<const int, 3> origin) {
    if (format <= 32) {
        const int signed_width = format < 0 ? -format : format;
        const unsigned width = signed_width;
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
    if (format >= 'i' && format <= 'k') return SferaBinary::floatBits(decodeCoordinate(origin[format - 'i'], read(12)));
    if (format == 'l') return SferaBinary::floatBits(read(8) * 0.02454369328916073f);
    valid_ = false;
    return 0;
}

bool SferaMbcBitStream::writeField(std::int8_t format, std::uint32_t value, std::span<const int, 3> origin) {
    if (format <= 32) { const int signed_width = format < 0 ? -format : format; const unsigned width = signed_width; write(value, width); }
    else if (format == 'g') {
        const bool negative = SferaNumeric::signedWord(value) < 0;
        const auto magnitude = negative ? 0u - value : value;
        const int signedMagnitude = magnitude;
        const auto selector = signedMagnitude < 8 ? 0u : signedMagnitude < 128 ? 1u : signedMagnitude < 16384 ? 2u : 3u;
        write(negative, 1); write(selector, 2); write(magnitude, variableIntegerWidths[selector]);
    } else if (format >= 'i' && format <= 'k') {
        const auto code = encodeCoordinate(origin[format - 'i'], SferaBinary::floatFromBits(value));
        if (code == UINT32_MAX) return false;
        write(code, 12);
    } else if (format == 'l') {
        auto angle = SferaBinary::floatFromBits(value);
        if (!std::isfinite(angle) || angle < -1000.0f || angle > 1000.0f) angle = 0;
        while (angle < 0) angle = angle + 6.2831854820251465;
        const float scaled = angle * 40.7436637878418;
        write(SferaNumeric::truncatedWord(scaled) & 255u, 8);
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
    if (std::cmp_greater(description.field_count, std::size(description.formats))) { wrongData(); return; }
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
            auto* destination = memoryAt(array->value.base, count * elementSize);
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
    if (slotIndex < 0 || slotIndex >= std::size(g_sfera_mbc_runtime.world_slots) || active_process == nullptr) return;
    auto& slot = g_sfera_mbc_runtime.world_slots[slotIndex];
    if ((slot.state & 4) || findProcess(slot.linked_handle) == nullptr) return;
    const bool reliable = (flags & 1) != 0;
    auto& bitCount = reliable ? slot.reliable_bit_count : slot.unreliable_bit_count;
    auto& lastProcess = reliable ? slot.reliable_process : slot.unreliable_process;
    auto payload = std::span<std::uint8_t>(reliable ? slot.reliable_payload : slot.unreliable_payload, sizeof(slot.reliable_payload));
    const auto captureOrigin = [this, &slot]() {
        SferaVec3F position;
        std::memcpy(&position, memoryAt(active_process->field_084, sizeof(position)), sizeof(position));
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
        if (!encoded.writeField(outgoing_fields[field].format, outgoing_fields[field].word, slot.origin)) coordinatesValid = false;
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
        if (hasOrigin) { output.write(slot.origin[0] + 32768u, 16); output.write(slot.origin[1] + 1200u, 13); output.write(slot.origin[2] + 32768u, 16); }
        output.write(SferaNumeric::word(SferaNumeric::signedWord(g_sfera_mbc_runtime.simulation_tick) >> 3), 15);
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
    SferaBinary::Reader reader(data);
    try {
        const auto signature = reader.take(16);
        const auto version = (signature[12] - '0') * 10 + signature[14] - '0';
        reader.read<std::uint32_t>(); // Reserved header word remains part of the encoded image.
        module_tag = reader.read<std::uint32_t>();
        const auto codeSize = reader.read<std::uint32_t>();
        const auto memorySize = reader.read<std::uint32_t>();
        if (module_tag >= 4096 || codeSize > UINT32_MAX - 2) return false;
        bytecode = reader.take(codeSize);
        memory = reader.take(memorySize);
        const auto programCount = reader.read<std::uint32_t>();
        if (programCount > 32766 || programCount > reader.remaining() / 15) return false;
        programs.assign(programCount, {});
        for (auto& program : programs) {
            program.name = reader.readTerminated(32u);
            program.entry_offset = reader.read<std::uint32_t>();
            program.stop_offset = reader.read<std::uint32_t>();
            program.state = reader.read<std::int8_t>();
            program.priority = reader.read<std::uint8_t>();
            (void)reader.read<std::uint32_t>(); // Reserved local-memory word in the module format.
            program.instruction_offset = program.entry_offset;
            program.caller_program = -1;
            if (program.priority >= 4) return false;
        }
        const auto functionCount = reader.read<std::uint32_t>();
        if (functionCount > 65535 || functionCount > reader.remaining() / 13) return false;
        functions.assign(functionCount, {});
        for (auto& function : functions) {
            function.name = reader.readTerminated(32u);
            function.entry_offset = reader.read<std::uint32_t>();
            function.program_index = reader.read<int>();
            function.allow_reentry = reader.read<std::uint32_t>() != 0;
        }
        // Older modules store only the first 30 function slots.
        function_map.fill(UINT16_MAX);
        const auto mapBytes = reader.take((version <= 22 ? 30 : function_map.size()) * sizeof(std::uint16_t));
        for (std::size_t index = 0; index < mapBytes.size() / sizeof(std::uint16_t); ++index) function_map[index] = SferaBinary::readLittleEndian<std::uint16_t>(mapBytes.data() + index * sizeof(std::uint16_t));
        region_definitions = reader.take(reader.read<std::uint32_t>());
        position_memory_offset = reader.read<std::uint32_t>();
        reader.take(2 * sizeof(std::uint32_t)); // Reserved exports; consume without storing runtime mirrors.
        if (linking) for (auto& table : relocations) {
            const auto count = reader.read<std::uint32_t>();
            if (count > reader.remaining() / sizeof(std::uint32_t)) return false;
            table.resize(count);
            for (auto& offset : table) offset = reader.read<std::uint32_t>();
        }
        return true;
    } catch (const SferaBinary::ReadError&) { return false; }
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
    text_buffer.clear();
    if (name.starts_with('@')) {
        const auto end = name.find('@', 1);
        if (end == std::string_view::npos) return UINT32_MAX;
        for (const auto character : name.substr(1, end - 1)) {
            const auto needed = character == ';' ? 2u : 1u;
            if (needed >= text_capacity - text_buffer.size()) return UINT32_MAX;
            if (character == ';') text_buffer += "\r\n";
            else text_buffer.push_back(character == '\'' ? '"' : character);
        }
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
    replacement.name = name;
    replacement.module_tag = module.module_tag;
    replacement.bytecode = findBytecode(replacement.linked_modules, module.memory.size());
    if (!replacement.bytecode) {
        auto code = std::make_shared<std::vector<std::uint8_t>>(module.bytecode.begin(), module.bytecode.end());
        replacement.bytecode = cacheBytecode(std::move(code), replacement.linked_modules, module.memory.size());
    }
    replacement.memory.assign(module.memory.begin(), module.memory.end());
    replacement.programs = std::move(module.programs);
    replacement.functions = std::move(module.functions);
    replacement.function_map = module.function_map;
    replacement.regions.assign(62, SferaMbcRegionRecord::undefined());
    replacement.readRegions(module.region_definitions, 0);
    replacement.field_084 = module.position_memory_offset;
    replacement.code_range_ids[0] = SferaNumeric::lowHalf(module.module_tag);
    replacement.code_range_size[0] = replacement.codeSize();
    replacement.code_range_count = 1;
    std::fill(std::begin(replacement.program_map_a), std::end(replacement.program_map_a), UINT16_MAX);
    std::fill(std::begin(replacement.program_map_b), std::end(replacement.program_map_b), UINT16_MAX);
    std::fill(std::begin(replacement.region_timestamps), std::end(replacement.region_timestamps), UINT32_MAX);
    replacement.process_id = index;
    replacement.lifetime = next_process_lifetime++;
    replacement.execution_prev_index = replacement.execution_next_index = index;
    replacement.chain_prev_index = process_chain_last < 0 ? index : process_chain_last;
    replacement.chain_next_index = index;
    auto& process = processes[index];
    process = std::move(replacement);
    if (process_chain_last >= 0) processes[process_chain_last].chain_next_index = index;
    else process_chain_first = index;
    process_chain_last = index;
    process_search_cursor = (index + 1) % std::size(processes);
    for (std::uint32_t program = 0; program < process.programs.size(); ++program)
        if (process.programs[program].state == 1) process.linkProgram(program);
    if (process.programs_queued) enqueueProcess(index, process);
    return process.process_id;
}

std::uint32_t SferaMbcRuntime::linkProcess(std::string_view name) {
    if (name.size() >= 32 || process_index < 0 || std::cmp_greater_equal(process_index, std::size(processes)) || !quick_files) return UINT32_MAX;
    const auto filename = std::string(name) + ".mbc";
    const auto* file = quick_files->find(filename);
    if (!file || file->bytes.size() < 16) return UINT32_MAX;
    SferaMbcModuleImage module;
    if (!module.read(file->bytes, true)) return UINT32_MAX;
    auto& process = processes[process_index];
    if (process.chain_prev_index < 0 || !process.bytecode) return UINT32_MAX;
    auto modules = process.linked_modules;
    const auto freeModule = std::find(modules.begin(), modules.end(), std::uint16_t{});
    if (freeModule == modules.end()) { reportError("Cannot link a process - increase MAX_LINKED_PRCS! Linked prc: ", filename); return UINT32_MAX; }
    const auto codeOffset = process.codeSize();
    if (process.memory.size() > mappedAddressBegin - 4u || process.programs.size() > 32767u || process.functions.size() > 65535u) return UINT32_MAX;
    const auto alignedMemoryOffset = (process.memory.size() + 3u) & ~std::size_t{3};
    const auto firstProgramCount = process.programs.size();
    const auto firstFunctionCount = process.functions.size();
    if (module.bytecode.size() > UINT32_MAX - codeOffset || module.memory.size() >= mappedAddressBegin - alignedMemoryOffset ||
        module.programs.size() > 32767u - firstProgramCount || module.functions.size() > 65535u - firstFunctionCount) return UINT32_MAX;
    const std::uint32_t memoryOffset = SferaNumeric::lowWord(alignedMemoryOffset);
    const std::uint32_t firstProgram = SferaNumeric::lowWord(firstProgramCount);
    const std::uint32_t firstFunction = SferaNumeric::lowWord(firstFunctionCount);
    const auto validRelocations = [](const auto& table, std::size_t size, std::size_t width) {
        return std::all_of(table.begin(), table.end(), [=](std::uint32_t offset) { return offset <= size && width <= size - offset; });
    };
    if (!validRelocations(module.relocations[0], module.bytecode.size(), 4) ||
        !validRelocations(module.relocations[1], module.memory.size(), 4) ||
        !validRelocations(module.relocations[2], module.bytecode.size(), 2)) return UINT32_MAX;
    const auto instructionOffset = SferaNumeric::lowWord(instruction_cursor - process.codeData());
    const auto currentOffset = SferaNumeric::lowWord(current_instruction_address - process.codeData());
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
            functionMap[index] = SferaNumeric::lowHalf(module.function_map[index] + firstFunction);
    // Reuse only the region decoder; it writes no scheduler or global state.
    SferaMbcProcessRecord bindings{};
    bindings.regions = process.regions;
    bindings.readRegions(module.region_definitions, firstProgram);
    const auto relocate = []<class T>(std::uint8_t* destination, const auto& table, std::uint32_t increment) {
        for (const auto offset : table) {
            const auto value = SferaBinary::readLittleEndian<T>(destination + offset);
            if constexpr (sizeof(T) == sizeof(std::uint16_t)) SferaBinary::writeLittleEndian(destination + offset, SferaNumeric::lowHalf(value + increment));
            else SferaBinary::writeLittleEndian(destination + offset, SferaNumeric::lowWord(value + increment));
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
                    if (implementation.program_index == -1 || declaration.name != implementation.name) continue;
                    if (declaration.entry_offset <= writable->size() && writable->size() - declaration.entry_offset >= 5) {
                        auto* instruction = writable->data() + declaration.entry_offset;
                        *instruction = 'G';
                        SferaBinary::writeLittleEndian(instruction + 1, implementation.entry_offset - declaration.entry_offset - 1u);
                    }
                    break;
                }
            }
        };
        resolve(firstFunction, functions.size(), 0, firstFunction);
        resolve(0, firstFunction, firstFunction, functions.size());
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
        process.code_range_ids[range] = SferaNumeric::lowHalf(module.module_tag);
        process.code_range_begin[range] = codeOffset;
        process.code_range_size[range] = module.bytecode.size();
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
            case ResourceKind::file: ::_close(SferaNumeric::signedWord(entry.handle)); break;
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
    if (process_chain_first == index && process_chain_last == index) {
        process_chain_first = process_chain_last = -1;
    } else if (process_chain_last == index) {
        process_chain_last = previous; processes[previous].chain_next_index = previous;
    } else if (process_chain_first == index) {
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
    if (region.field_count < 0 || std::cmp_greater(region.field_count, std::size(region.formats))) return false;
    for (int field = 0; field < region.field_count && valid_; ++field) {
        auto format = std::abs(region.formats[field]);
        std::uint32_t count = 1;
        if (format == 'e' || format == 'f') {
            const std::int8_t countFormat = format;
            const auto encodedCount = read(format == 'e' ? 4 : 8);
            if (!valid_ || ++field >= region.field_count) return false;
            count = mbc_array_count(encodedCount, countFormat, region.formats[field], remaining());
            format = std::abs(region.formats[field]);
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
        const unsigned width = std::min<std::size_t>(remaining, 32);
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
    if (stream.read(1) != 0) { origin[0] = stream.read(16) - 32768; origin[1] = stream.read(13) - 1200; origin[2] = stream.read(16) - 32768; }
    const auto timestamp = stream.read(15);
    while (stream.valid()) {
        const auto processId = stream.read(18);
        const auto moduleTag = stream.read(12);
        if (!stream.valid()) return;
        auto* process = runtime.findProcess(processId);
        if (moduleTag == 0) {
            if (process != nullptr) {
                runtime.active_process = process;
                if (!process->activateProgram("EKill")) { process->flags |= 4; process->programs_queued = true; runtime.enqueueProcess(processId, *process); }
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
            runtime.enqueueProcess(processId, *process);
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
                runtime.enqueueProcess(processId, *process);
            }
            if (process->regions.empty()) return;
            const auto& region = process->regions[regionIndex];
            if (region.program_index != UINT16_MAX) process->activateProgram(region.program_index);
            if (region.field_count < 0) { if (process->flags & SferaMbcProcessRecord::unloadAfterExecution) runtime.unloadProcess(processId); return; }
            const auto firstBit = stream.position();
            if (!stream.skipRegion(region)) return;
            if (process->flags & SferaMbcProcessRecord::unloadAfterExecution) continue;
            if ((region.flags & 1) == 0 && SferaNumeric::signedWord(process->region_timestamps[regionIndex]) >= 0 && tickDifference(timestamp, process->region_timestamps[regionIndex]) < 0) continue;
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

int SferaTcpConnectionContext::initialize(const std::string& hostname, std::uint16_t port) {
    shutdown();
    if (hostname.empty() || !winsock_.start()) return -1;
    try {
        socket_.reset(::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP));
        if (socket_.value == INVALID_SOCKET) { shutdown(); return -1; }
        const int no_delay = 1;
        constexpr int option_size = sizeof(no_delay);
        std::string option(option_size, '\0');
        std::memcpy(option.data(), &no_delay, sizeof(no_delay));
        (void)::setsockopt(socket_.value, IPPROTO_TCP, TCP_NODELAY, option.data(), option_size);
        addrinfo hints{};
        hints.ai_family = AF_INET; hints.ai_socktype = SOCK_STREAM; hints.ai_protocol = IPPROTO_TCP;
        hints.ai_flags = AI_NUMERICSERV;
        const auto service = std::to_string(port);
        addrinfo* raw = nullptr;
        const auto status = ::getaddrinfo(hostname.c_str(), service.c_str(), &hints, &raw);
        std::unique_ptr<addrinfo, decltype(&::freeaddrinfo)> resolved(raw, &::freeaddrinfo);
        if (status != 0 || !resolved || !std::in_range<int>(resolved->ai_addrlen)) { shutdown(); return -1; }
        // Bounded connect, then all worker send/recv calls remain nonblocking.
        u_long nonblocking = 1;
        if (::ioctlsocket(socket_.value, FIONBIO, &nonblocking) != 0) { shutdown(); return -1; }
        if (::connect(socket_.value, resolved->ai_addr, resolved->ai_addrlen) != 0) {
            if (::WSAGetLastError() != WSAEWOULDBLOCK) { shutdown(); return -1; }
            fd_set writable{}, failed{};
            FD_SET(socket_.value, &writable); FD_SET(socket_.value, &failed);
            timeval timeout{15, 0};
            if (::select(0, nullptr, &writable, &failed, &timeout) <= 0 || FD_ISSET(socket_.value, &failed)) { shutdown(); return -1; }
            int size = option_size;
            if (::getsockopt(socket_.value, SOL_SOCKET, SO_ERROR, option.data(), &size) != 0 ||
                std::cmp_not_equal(size, sizeof(int))) { shutdown(); return -1; }
            int error = 0;
            std::memcpy(&error, option.data(), sizeof(error));
            if (error != 0) { shutdown(); return -1; }
        }
        connected_ = true;
        workers_[0] = std::jthread([this](std::stop_token stop) { receive(stop); });
        workers_[1] = std::jthread([this](std::stop_token stop) { maintain(stop); });
        workers_[2] = std::jthread([this](std::stop_token stop) { dispatch(stop); });
        return 0;
    } catch (...) { shutdown(); return -1; }
}

SferaNetworkRuntime::~SferaNetworkRuntime() { connection.reset(); }

int SferaNetworkRuntime::initialize(const std::string& hostname, std::uint32_t mode) {
    if (connection_lost) shutdown();
    const auto result = initialization_result.load();
    if (SferaNumeric::signedWord(result) >= 0) return SferaNumeric::signedWord(result);
    if (hostname.empty()) return 0;
    shutdown();
    client_mode = mode;
    connection_lost = false;
    sent_bytes = 0; received_bytes = 0;
    connection_info = {};
    { std::lock_guard lock(receive_mutex); dropped_messages = 0; }
    initialization_result = 0;
    try { connection = std::make_unique<SferaTcpConnectionContext>(*this); }
    catch (...) { initialization_result = UINT32_MAX; return 0; }
    if (connection->initialize(hostname, server_port) != 0) {
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
    return pack(epochYear + SferaNumeric::lowWord(elapsedYears), month, date, SferaNumeric::lowWord(time / quartersPerHour),
        SferaNumeric::lowWord(time % quartersPerHour / quartersPerMinute), SferaNumeric::lowWord(time % quartersPerMinute));
}

std::int64_t SferaMbcValue::truncateReal(double number) {
    return SferaNumeric::truncateInt64(number);
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

int SferaFileManager::transformEnvelope(const std::string& destination, const std::string& source, bool compress) {
    struct ReportingScope {
        SferaFileManager& owner;
        bool previous;
        ~ReportingScope() { owner.setErrorReporting(previous); }
    } reporting{*this, setErrorReporting(false)};
    const auto transform = [&]() -> int {
        const auto length = fileSize(source); if (length < 0 || std::cmp_greater(length, std::numeric_limits<std::ptrdiff_t>::max())) return -1;
        std::vector<std::uint8_t> input(length);
        ScopedFile inputFile(*this, open(source, _O_RDONLY)); if (inputFile.get() < 0) return -1;
        struct _stat64i32 information{}; const bool haveTimes = ::_fstat64i32(inputFile.get(), &information) == 0;
        const auto received = read(inputFile.get(), std::as_writable_bytes(std::span(input))); inputFile.close(); if (received != length) return -1;
        std::vector<std::uint8_t> transformed;
        std::span<const std::uint8_t> output = input;
        std::uint32_t size = 0;
        if (compress) {
            const auto capacity = input.size() * 101ull / 100u + 20u;
            if (capacity > UINT32_MAX) return -1;
            size = capacity; transformed.resize(size);
            if (SferaZStream32::compressEnvelope(transformed.data(), size, input) != 0) return -1;
            output = std::span<const std::uint8_t>(transformed.data(), size);
        } else if (SferaZStream32::decompressEnvelope(nullptr, size, input) == 0) {
            if (size > UINT32_MAX - 100) return -1;
            transformed.resize(size + 100);
            if (SferaZStream32::decompressEnvelope(transformed.data(), size, input) != 0) return -1;
            output = std::span<const std::uint8_t>(transformed.data(), size);
        }
        ::_chmod(destination.c_str(), _S_IREAD | _S_IWRITE);
        ScopedFile outputFile(*this, create(destination)); if (outputFile.get() < 0) return -1;
        const auto written = write(outputFile.get(), std::as_bytes(output));
        if (haveTimes) { __utimbuf64 times{information.st_mtime, information.st_mtime}; ::_futime64(outputFile.get(), &times); }
        const auto closed = outputFile.close();
        return written == std::ssize(output) && closed == 0 ? 0 : -1;
    };
    return transform();
}

std::string SferaMbcRuntime::formatArguments(std::string_view pattern, std::size_t limit) {
    using Argument = std::variant<int, double, SferaSliceReference32>;
    std::vector<Argument> arguments;
    while (argument_count > 0) {
        if (argument_cursor >= argument_end) { reportError("Too few parameters"); break; }
        const auto& argument = g_sfera_mbc_runtime.values[argument_cursor];
        if (argument.isPointer()) { arguments.emplace_back(argument.value); ++argument_cursor; }
        else if (argument.type == SferaMbcValue::Byte || argument.type == SferaMbcValue::Integer) arguments.emplace_back(nextInteger());
        else { const double value = nextReal(); arguments.emplace_back(value); }
        --argument_count;
    }
    ++value_stack_size;
    if (execution_failed) return {};
    std::string result; std::size_t next = 0;
    const auto invalid = [&]() { reportError("Invalid format arguments"); };
    const auto word = [&]() -> std::uint32_t {
        if (next >= arguments.size()) { invalid(); return 0; }
        const auto& value = arguments[next++];
        if (const auto* integer = std::get_if<int>(&value)) return SferaNumeric::word(*integer);
        if (const auto* pointer = std::get_if<SferaSliceReference32>(&value)) return pointer->base;
        invalid(); return 0;
    };
    const auto pointer = [&]() -> SferaSliceReference32 {
        if (next >= arguments.size()) { invalid(); return {}; }
        const auto& value = arguments[next++];
        if (const auto* slice = std::get_if<SferaSliceReference32>(&value)) return *slice;
        if (const auto* integer = std::get_if<int>(&value)) return {SferaNumeric::word(*integer), 0, 0};
        invalid(); return {};
    };
    const auto append = [&](const std::string& specifier, auto value) {
        const auto required = std::snprintf(nullptr, 0, specifier.c_str(), value);
        if (required < 0) { invalid(); return; }
        const std::size_t required_size = required;
        const auto count = std::min(required_size, limit - result.size());
        if (count == 0) return;
        const auto offset = result.size(); result.resize(offset + count + 1);
        std::snprintf(result.data() + offset, count + 1, specifier.c_str(), value); result.resize(offset + count);
    };
    const auto characterAt = [&](std::size_t position) { return position < pattern.size() ? pattern[position] : '\0'; };
    for (std::size_t cursor = 0; cursor < pattern.size() && !execution_failed;) {
        if (characterAt(cursor) != '%') { if (result.size() < limit) result.push_back(characterAt(cursor)); ++cursor; continue; }
        ++cursor;
        if (characterAt(cursor) == '%') { if (result.size() < limit) result.push_back('%'); ++cursor; continue; }
        std::string specifier = "%";
        while (characterAt(cursor) != '\0' && std::string_view("-+ #0").find(characterAt(cursor)) != std::string_view::npos) specifier.push_back(characterAt(cursor++));
        if (characterAt(cursor) == '*') {
            ++cursor; const int width = word(); if (width < 0) specifier.push_back('-');
            specifier += std::to_string(SferaNumeric::magnitude(width));
        } else while (characterAt(cursor) >= '0' && characterAt(cursor) <= '9') specifier.push_back(characterAt(cursor++));
        std::optional<std::size_t> precision;
        if (characterAt(cursor) == '.') {
            ++cursor;
            if (characterAt(cursor) == '*') {
                ++cursor;
                const int value = word();
                if (value >= 0) { precision = value; specifier += "." + std::to_string(value); }
            } else {
                specifier.push_back('.');
                const auto first = cursor;
                while (characterAt(cursor) >= '0' && characterAt(cursor) <= '9') specifier.push_back(characterAt(cursor++));
                std::size_t value = 0;
                if (cursor != first && std::from_chars(pattern.data() + first, pattern.data() + cursor, value).ec != std::errc{}) { invalid(); break; }
                precision = value;
            }
        }
        std::string length;
        if (characterAt(cursor) == 'h' || characterAt(cursor) == 'l') { length.push_back(characterAt(cursor++)); if (characterAt(cursor) == length.front()) length.push_back(characterAt(cursor++)); }
        else if (characterAt(cursor) == 'I') { ++cursor; if (characterAt(cursor) == '6' && characterAt(cursor + 1) == '4') { length = "ll"; cursor += 2; } else if (characterAt(cursor) == '3' && characterAt(cursor + 1) == '2') cursor += 2; }
        else if (characterAt(cursor) != '\0' && std::string_view("jztLw").find(characterAt(cursor)) != std::string_view::npos) length.push_back(characterAt(cursor++));
        if (characterAt(cursor) == '\0') { invalid(); break; }
        const auto conversion = characterAt(cursor++);
        if (std::string_view("diuoxX").find(conversion) != std::string_view::npos) {
            const bool wide = length == "ll" || length == "j";
            const auto low = word();
            std::uint64_t bits = low;
            if (wide) {
                const std::uint64_t high = word();
                bits |= high << 32;
            }
            if (execution_failed) break;
            if (wide) { specifier += "ll"; specifier.push_back(conversion); if (conversion == 'd' || conversion == 'i') append(specifier, SferaNumeric::signedWord(bits)); else append(specifier, bits); }
            else { if (length == "h" || length == "hh") specifier += length; specifier.push_back(conversion); if (conversion == 'd' || conversion == 'i') append(specifier, SferaNumeric::signedWord(low)); else append(specifier, low); }
        } else if (std::string_view("aAeEfFgG").find(conversion) != std::string_view::npos) {
            if (next >= arguments.size() || !std::holds_alternative<double>(arguments[next])) { invalid(); break; }
            specifier.push_back(conversion); append(specifier, std::get<double>(arguments[next++]));
        } else if (conversion == 's' || conversion == 'S') {
            const auto reference = pointer();
            const auto address = reference.base;
            if (execution_failed) break;
            if (length == "l" || length == "w" || (conversion == 'S' && length != "h")) {
                specifier += "ls";
                std::wstring value;
                if (address != 0) {
                    const auto bytes = memoryRange(reference.base);
                    SferaBinary::Reader reader(bytes);
                    while (!precision || value.size() < *precision) {
                        const auto character = reader.read<std::uint16_t>();
                        if (character == 0) break;
                        value.push_back(character);
                    }
                } else value = L"(null)";
                append(specifier, value.c_str());
            } else {
                specifier.push_back('s');
                const auto text = address != 0 ? (precision ? textIn(reference, *precision) : textIn(reference)) : std::string("(null)");
                // textIn checked either the terminator or the same precision passed to the CRT.
                append(specifier, text.empty() ? "" : text.data());
            }
        } else if (conversion == 'c' || conversion == 'C') {
            if (length == "l" || length == "w" || (conversion == 'C' && length != "h")) specifier.push_back('l');
            specifier.push_back('c'); const auto character = word(); if (!execution_failed) append(specifier, SferaNumeric::signedWord(character));
        } else if (conversion == 'p') { specifier.push_back('p'); const auto address = word(); if (!execution_failed) append(specifier, address != 0 ? static_cast<const void*>(memoryAt(address, 1)) : nullptr); }
        else invalid();
    }
    return result;
}

void SferaMbcRuntime::formatText(bool bounded) {
    const std::uint32_t required = bounded ? 3 : 2;
    if (std::cmp_less(argument_count, required)) { reportError(bounded ? "Wrong number of parameters: ffsnprintf" : "Wrong number of parameters: ffsprintf"); return; }
    const auto destination = nextAddress();
    const auto capacity = bounded ? nextWord() : UINT32_MAX;
    const auto pattern = nextAddress();
    if (execution_failed) return;
    argument_count -= required;
    std::optional<SferaText::Buffer> output;
    std::size_t limit = 0;
    if (capacity != 0) {
        output.emplace(textBufferAt(destination.base));
        if (bounded && capacity > output->size()) throw std::out_of_range("Formatted script string exceeds destination");
        limit = bounded ? capacity - 1 : output->size();
    }
    const auto value = formatArguments(textIn(pattern), limit);
    if (execution_failed || !output) return;
    if (bounded) output->writeBounded(value, capacity);
    else output->assign(value);
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
    const auto pattern = textAt(patternOffset);
    if (execution_failed) return;
    (void)formatArguments(pattern, named ? std::numeric_limits<std::size_t>::max() : 4095u);
}

void SferaMbcRuntime::systemCommand() {
    const auto operation = nextInteger();
    const auto address = [this](std::string_view name) { const std::uint32_t offset = nextInteger(); if (offset == 0) ::OutputDebugStringA(std::format("NULL-pointer dereferencing: ffsys, {}\n", name).c_str()); return offset; };
    const auto text = [this](std::uint32_t offset) { return textAt(offset); };
    const auto selectedObject = [this]() -> WorldObject* { const auto handle = nextInteger(); if (handle < 0) return nullptr; auto* object = g_sfera_world_objects.object(handle, "GetObjectPointer"); g_sfera_mbc_runtime.current_object = object; if (object == nullptr) active_tag = UINT32_MAX; return object; };
    switch (operation) {
        case 0: {
            const auto handle = nextInteger(); const auto destination = argument_count == 3 ? address("G_GROUND") : 0;
            if (execution_failed) return;
            std::uint32_t surface = 0; pushInteger(g_sfera_motion.surfaceInteraction(handle, &surface));
            if (SferaNumeric::signedWord(destination) > 0) writeMemory(destination, surface);
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
        case 4: {
            const auto handle = nextInteger();
            // A script can bind a handle before its object is recreated during a transition.
            g_sfera_world_objects.controlled_object_handle = execution_failed ? UINT32_MAX : SferaNumeric::word(handle);
            return;
        }
        case 5: g_sfera_mbc_runtime.game_calendar = nextInteger(); return;
        case 6: pushInteger(g_sfera_mbc_runtime.game_calendar); return;
        case 7: {
            float fraction = 0;
            if (argument_count > 1) {
                const float numerator = nextInteger();
                const auto denominator = nextInteger();
                const double precise_numerator = numerator;
                fraction = precise_numerator / denominator;
            }
            const auto calendar = g_sfera_mbc_runtime.game_calendar;
            const auto ticks = (((calendar >> 8) & 31) * 60 + ((calendar >> 2) & 63)) * 4 + (calendar & 3);
            const double precise_ticks = ticks;
            const float factor = 0.9994999766349792 - (precise_ticks + fraction) / 5760.0;
            g_sfera_graphics_runtime.environment_factor = factor < 0 ? 0 : factor;
            return;
        }
        case 8: g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::advance(g_sfera_mbc_runtime.game_calendar); return;
        case 9: pushInteger(SferaGameCalendar::component(g_sfera_mbc_runtime.game_calendar, nextInteger())); return;
        case 10: if (selectedObject() != nullptr) { nextInteger(); nextInteger(); nextInteger(); } return;
        case 11: { const auto value = nextInteger(); if (value < 0) pushInteger(g_sfera_direct_input_runtime.text_filter); else g_sfera_direct_input_runtime.text_filter = value; return; }
        case 12: { const auto destination = address("G_ERRMSG"); if (!execution_failed) copyText({destination, 0, 0}, diagnostic_context); return; }
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
            const auto patternOrHandle = nextWord(); const auto destination = address(operation == 19 ? "FINDFIRST" : "FINDNEXT"); if (execution_failed) return;
            const auto result = operation == 19 ? ::_findfirst64i32(text(patternOrHandle).data(), &script_find_data) : ::_findnext64i32(nativeResource<std::intptr_t>(patternOrHandle), &script_find_data);
            std::uint32_t value = UINT32_MAX;
            if (result != -1) {
                if (operation == 19) {
                    try {
                        value = nativeHandle(result);
                        active_process->registerResource(value, ResourceKind::fileSearch);
                    } catch (...) {
                        forgetNativeResource(result);
                        ::_findclose(result);
                        throw;
                    }
                } else value = result;
                copyText({destination, 0, 0}, script_find_data.name);
            } else copyText({destination, 0, 0}, {});
            pushInteger(value); return;
        }
        case 21: { const auto handle = nextWord(); if (!execution_failed) { const auto search = nativeResource<std::intptr_t>(handle); if (search != -1) { ::_findclose(search); forgetNativeResource(search); } active_process->unregisterResource(handle, ResourceKind::fileSearch); } return; }
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
            SferaCursorPosition position{}; CCursorManager::instance().activeCursor()->getPosition(&position); writeMemory<float>(x, position.x); writeMemory<float>(y, position.y); return;
        }
        case 34: case 37: pushInteger(g_sfera_direct_input_runtime.mouse.buttons & (operation == 34 ? 1 : 2)); return;
        case 35: { const auto cursor = nextInteger(); const auto mask = nextInteger(); if (execution_failed) return; if (cursor) g_sfera_interface.default_cursor_name = text(cursor); SphereRender::SceneRenderer::visible_character_parts = mask; return; }
        case 36: { const auto destination = address("G_CURSDIR"); if (execution_failed) return; float distance = 0; SferaVec3F direction{}; g_sfera_motion.pick(&distance, &direction); writeMemory(destination, direction); return; }
        case 39: { const float x = nextReal(); const float y = nextReal(); if (!execution_failed) CCursorManager::instance().activeCursor()->setPosition(SferaNumeric::truncateInt(x), SferaNumeric::truncateInt(y)); return; }
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
                case 7: pushInteger(SferaNumeric::lowWord(WorldClock::nowTicks())); return;
                case 8: { const auto source = nextSlice(); if (source.base != 0 && !execution_failed) { auto value = readMemory<tm>(source.base); pushInteger(SferaNumeric::lowWord(::_mktime64(&value))); writeMemory(source.base, value); } return; }
                case 9: { const __time64_t first = nextInteger(); const __time64_t second = nextInteger(); pushInteger(SferaNumeric::truncateInt(::_difftime64(first, second))); return; }
                default: pushInteger(SferaNumeric::lowWord(timestamp)); return;
            }
        }
        case 58: { const auto component = nextInteger(); const auto value = nextInteger(); if (!execution_failed) g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::withComponent(g_sfera_mbc_runtime.game_calendar, component, value); return; }
        case 59: { const auto value = nextInteger(); if (!execution_failed) g_sfera_camera.controlled_observer_mode = value; return; }
        case 60: pushInteger(SferaClientApplication::server_number); return;
        case 61: active_process->flags |= SferaMbcProcessRecord::markedForUnload; return;
        case 63: nextInteger(); nextReal(); return;
        case 64: { const auto track = address("PLAY_MUSIC"); if (!execution_failed) g_sfera_sound_runtime.requestTrack(track != 0 && !text(track).empty() ? std::optional<std::string_view>{text(track)} : std::nullopt); return; }
        case 65: g_sfera_world_objects.contours->rebuildServerWall(); return;
        case 66: case 67: { const auto destination = address(operation == 66 ? "GZ_PACK, 1" : "GZ_UNPACK, 1"); const auto source = address(operation == 66 ? "GZ_PACK, 2" : "GZ_UNPACK, 2"); if (!execution_failed) pushInteger(g_sfera_files.transformEnvelope(std::string(text(destination)), std::string(text(source)), operation == 66)); return; }
        case 68: {
            auto destination = nextSlice();
            if (execution_failed) return;

            constexpr std::size_t map_width = 80u;
            constexpr std::size_t map_height = 80u;
            constexpr std::size_t map_cell_size = 22u;
            constexpr std::size_t map_size = map_width * map_height * map_cell_size;

            if (destination.base == 0u) {
                reportError("NULL landscape map destination");
                return;
            }
            if (!destination.contains(map_size)) {
                destination.diagnoseRange(map_size);
                if (!destination.contains(map_size)) return;
            }

            const auto map_data = g_sfera_files.readAll("landscape\\map.bin");
            if (map_data.size() != map_size) {
                reportError(std::format(
                    "Invalid landscape map size for system 68: expected {}, got {}",
                    map_size, map_data.size()));
                return;
            }

            auto output = memoryBytes(destination.base, map_size);
            for (std::size_t map_x = 0u; map_x < map_width; ++map_x) {
                for (std::size_t map_z = 0u; map_z < map_height; ++map_z) {
                    const auto source_index = map_x * map_height + map_z;
                    const auto destination_index = map_z * map_width + map_x;
                    const auto source_offset = source_index * map_cell_size;
                    const auto destination_offset = destination_index * map_cell_size;
                    std::copy_n(
                        map_data.begin() + static_cast<std::ptrdiff_t>(source_offset),
                        map_cell_size,
                        output.begin() + static_cast<std::ptrdiff_t>(destination_offset));
                }
            }
            return;
        }
        case 69: nextInteger(); return;
        case 70: { nextInteger(); const auto x = nextInteger(); const auto y = nextInteger(); if (!execution_failed) { if (x != 0) writeMemory(x, std::uint8_t{}); if (y != 0) writeMemory(y, std::uint8_t{}); } return; }
        case 71: nextInteger(); nextInteger(); return;
        case 72: nextInteger(); nextInteger(); return;
        case 73: if (argument_count > 1) { nextInteger(); pushInteger(SferaClientApplication::resources_loaded); } else SferaClientApplication::loadResources(); return;
        case 74: nextInteger(); nextInteger(); nextInteger(); return;
        case 75: {
            const auto detail = nextInteger(); const auto handle = g_sfera_world_objects.controlled_object_handle; if (SferaNumeric::signedWord(handle) <= 0) return;
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
        case 89: {
            const auto ids = nextAddress();
            const auto types = nextAddress();
            const auto count = nextInteger();
            if (execution_failed) return;
            if (count <= 0 || count > SIZE_MAX / sizeof(std::int32_t)) {
                reportError("Invalid server map size"); return;
            }
            const auto readArray = [&](const SferaSliceReference32& reference) {
                SferaBinary::Reader reader(memoryBytes(reference.base, count * sizeof(std::int32_t)));
                std::vector<int> values(count);
                for (auto& value : values) value = reader.read<std::int32_t>();
                return values;
            };
            const auto identifiers = readArray(ids);
            const auto serverTypes = readArray(types);
            if (g_sfera_world_objects.contours != nullptr) g_sfera_world_objects.contours->setServerMap(identifiers, serverTypes);
            return;
        }
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
        case 100: { if (SphereRender::SceneRenderer::characters == nullptr) { pushInteger(0); return; } const auto sex = nextInteger(); const auto part = nextInteger(); if (!execution_failed) pushInteger(part == 0 || part == 1 ? SphereRender::CharacterModels::textureVariants(sex != 0, part == 0 ? "f" : "r") : part == 2 || part == 3 ? 4 : 0); return; }
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
        case 113: {
            const auto variable = nextInteger();
            const auto destination = nextWord();
            if (execution_failed) return;
            const auto name = text(variable);
            std::string value;
            std::size_t required = 0;
            if (::getenv_s(&required, nullptr, 0, name.c_str()) == 0 && required != 0) {
                for (unsigned attempt = 0; ; ++attempt) {
                    if (attempt == 8u) throw std::runtime_error("Environment value changed repeatedly while reading");
                    value.resize(required);
                    const auto status = ::getenv_s(&required, value.data(), value.size(), name.c_str());
                    if (status == ERANGE && required > value.size()) continue;
                    if (status != 0 || required == 0) { value.clear(); break; }
                    if (required > value.size() || value[required - 1] != '\0')
                        throw std::out_of_range("Invalid environment value length");
                    value.resize(required - 1);
                    break;
                }
            }
            copyText({destination, 0, 0}, value);
            return;
        }
        case 114: pushInteger(0); return;
        case 115: { const auto name = nextInteger(); if (!execution_failed) pushInteger(g_sfera_textures.find(text(name)) != 0); return; }
        case 116: { const auto name = nextInteger(); if (execution_failed) return; const auto definition = g_sfera_effect_manager.findDefinitionId(text(name)); pushInteger(definition == UINT32_MAX ? 0 : definition); return; }
        case 119: { const auto handle = nextInteger(); auto* object = g_sfera_world_objects.object(handle, "GetObjectPointer"); g_sfera_mbc_runtime.current_object = object; pushInteger(object == nullptr ? UINT32_MAX : 0); return; }
        case 120: { nextInteger(); const std::uint32_t effect = nextInteger(); if (!execution_failed) g_sfera_effect_manager.removeActiveEffect(nativeResource<SferaActiveEffect*>(effect)); return; }
        case 121: { const auto source = nextInteger(); const auto destination = nextInteger(); if (!execution_failed) { writeMemory(destination, ::_atoi64(text(source).data())); pushInteger(0); } return; }
        case 122: { const auto source = nextWord(); const auto destination = nextWord(); if (!execution_failed) { const auto value = std::to_string(readMemory<std::uint64_t>(source)); copyText({destination, 0, 0}, value); pushInteger(0); } return; }
        case 123: case 124: case 127: {
            const auto destination = nextInteger(); const std::int64_t operand = nextInteger(); if (execution_failed) return;
            auto value = readMemory<std::uint64_t>(destination); value = operation == 123 ? value + operand : operation == 124 ? value - operand : value * operand; writeMemory(destination, value);
            pushInteger(operation == 127 ? SferaNumeric::lowWord(value) : (value >> 63) != 0 ? UINT32_MAX - 1u : 0u); return;
        }
        case 125: case 128: {
            const auto firstAddress = nextInteger(); const auto argument = nextInteger(); if (execution_failed) return;
            const auto first = readMemory<std::int64_t>(firstAddress); const std::int64_t second = operation == 125 ? argument : readMemory<std::int64_t>(argument); pushInteger(first < second ? UINT32_MAX : first > second ? 1 : 0); return;
        }
        case 126: { const auto source = nextInteger(); const float multiplier = nextReal(); if (!execution_failed) pushInteger(readMemory<std::uint32_t>(source) * SferaNumeric::lowWord(SferaMbcValue::truncateReal(multiplier))); return; }
        case 131: { const auto destination = nextWord(); if (execution_failed) return; SYSTEMTIME time{}; ::GetLocalTime(&time); std::string date; date = std::format("{}-{:02d}-{:02d} {:02d}:{:02d}:{:02d}", time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond); copyText({destination, 0, 0}, date); pushInteger(0); return; }
        case 132: nextInteger(); pushInteger(0); return;
        case 133: case 134: case 138: pushInteger(0); return;
        case 136: { const auto path = nextInteger(); if (execution_failed) return; _finddata64i32_t information{}; const auto handle = ::_findfirst64i32(text(path).data(), &information); if (handle == -1) pushInteger(errno == ENOENT ? 0 : UINT32_MAX); else { ::_findclose(handle); pushInteger((information.attrib & _A_SUBDIR) != 0); } return; }
        case 140: { const auto name = address("SYS_SET_USER_NAME, 1"); g_sfera_error_log_runtime.user_name = text(name).substr(0, 127); pushInteger(1); return; }
        case 150: { g_sfera_network_runtime.connection_lost = nextInteger() != 0; pushInteger(0); return; }
        case 152: g_sfera_interface.initializeResources(); return;
        case 206:
            pushInteger(0);
            return;
        case 207: pushInteger(0); return;
        case 212: pushInteger(g_sfera_interface.invite_messages); return;
        case 213: case 214: { auto* window = nativeResource<SphereUI::Window*>(nextWord()); if (window != nullptr) { if (operation == 213) g_sfera_interface.raiseWindow(*window); else g_sfera_interface.lowerWindow(*window); } return; }
        case 215: nextInteger(); if (!execution_failed) pushInteger(0); return;
        case 216: nextInteger(); nextInteger(); if (!execution_failed) pushInteger(0); return;
        case 218: g_sfera_interface.saved_ui_enabled = g_sfera_interface.ui_enabled; g_sfera_interface.ui_enabled = false; return;
        case 219: { const auto message = nextInteger(); if (!execution_failed) pushInteger(g_sfera_interface.chat_filter->rejects(text(message))); return; }
        case 220: { const auto message = nextInteger(); if (!execution_failed) pushInteger(SphereUI::ChatFilter::invalidIdentifier(text(message))); return; }
        case 221: g_sfera_interface.ui_enabled = g_sfera_interface.saved_ui_enabled; return;
        case 224: { const auto handle = nextInteger(); if (handle < 0) return; auto* object = SphereRender::CharacterModels::checkedExtended(g_sfera_world_objects.object(handle, "GetObjectPointer")); if (object == nullptr) return; const SferaVec3F velocity{nextReal(), nextReal(), nextReal()}; if (!execution_failed) object->physical_velocity = velocity; return; }
        case 225: { const __time64_t timestamp = nextInteger(); const auto destination = nextSlice(); if (destination.base == 0 || execution_failed) return; tm local{}; if (::_localtime64_s(&local, &timestamp) == 0) writeMemory(destination.base, local); return; }
        case 226: pushInteger(::GetTickCount()); return;
        case 227: {
            const auto x = nextInteger(); const auto y = nextInteger(); const auto z = nextInteger(); const auto result = nextInteger(); if (execution_failed) return;
            const double vx = readMemory<float>(x), vy = readMemory<float>(y), vz = readMemory<float>(z); float length = vx * vx + vy * vy + vz * vz;
            if (length > 0.00001) {
                const double squared_length = length;
                length = std::sqrt(squared_length);
                const double source_x = readMemory<float>(x), source_y = readMemory<float>(y), source_z = readMemory<float>(z);
                writeReal(x, source_x / length);
                writeReal(y, source_y / length);
                writeReal(z, source_z / length);
            }
            writeMemory(result, length); pushInteger(0); return;
        }
        case 228: { copyText(nextSliceReference(), ""); pushInteger(0); return; }
        case 229: { const auto source = nextSliceReference(); const auto destination = nextSliceReference(); const auto capacity = std::min<std::size_t>(textBuffer(destination).size(), destination.end - destination.base); if (capacity != 0) copyText(destination, SferaText::encodeUri(text(source.base), capacity)); pushInteger(0); return; }
        case 230: return;
        case 231: if (!execution_failed) { pushInteger(g_sfera_motion.moved_since_query); g_sfera_motion.moved_since_query = 0; } return;
        case 508: {
            const auto processIndex = nextInteger();
            const auto first = nextInteger();
            const auto pattern = nextText();
            const auto output = nextSlice();
            if (execution_failed || processIndex < 0 || std::cmp_greater_equal(processIndex, std::size(processes)) || processes[processIndex].functions.empty() || first < 0) { pushInteger(UINT32_MAX); return; }
            const auto& process = processes[processIndex];
            for (std::uint32_t index = first; index < process.functions.size(); ++index) {
                const auto& name = process.functions[index].name;
                if (!SferaText::matchesWildcard(name, pattern)) continue;
                if (output.base != 0) copyText(output, name);
                pushInteger(index + 1);
                return;
            }
            if (output.base != 0) copyText(output, {});
            pushInteger(UINT32_MAX);
            return;
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
    dispatch_slot = -1;
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
    g_sfera_mbc_runtime.dispatch_slot = -1;
}

void SferaMbcRuntime::initialize() {
    std::srand(::timeGetTime());
    g_sfera_player_lists.clear();
    shutdown();
    first_execution_error.clear();
    final_shutdown = false;
    reloadQuickFiles();
    next_native_handle = 1;
    process_search_cursor = 0;
    g_sfera_mbc_runtime.dispatch_slot = -1; g_sfera_mbc_runtime.simulation_tick = 0; g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::pack(7801, 1, 1, 8, 0);
    halt_state = SferaMbcRuntime::HaltState::Running; g_sfera_world_objects.controlled_object_handle = UINT32_MAX;
    g_sfera_config_text_runtime.clear(); g_sfera_direct_input_runtime.text_filter = 0;
    for (std::size_t index = 0; index < 400; ++index) g_sfera_mbc_runtime.world_slots[index].state = 4;
    g_sfera_mbc_runtime.active_world_slot = 400;
    auto& slot = g_sfera_mbc_runtime.world_slots[400]; slot.primary_state = UINT32_MAX; slot.state = 2; slot.object_handle = 1; slot.reliable_bit_count = 0; slot.unreliable_bit_count = 0;
    std::fill(std::begin(slot.reliable_payload), std::end(slot.reliable_payload), 0); std::fill(std::begin(slot.unreliable_payload), std::end(slot.unreliable_payload), 0); slot.reliable_process = UINT32_MAX; slot.unreliable_process = UINT32_MAX;
    for (auto& module : g_sfera_mbc_runtime.modules) module.name.clear();
    _finddata64i32_t file{}; const auto search = ::_findfirst64i32("mbc\\*.mbc", &file);
    if (search != -1) {
        do {
            if ((file.attrib & _A_SUBDIR) != 0) continue;
            const auto descriptor = g_sfera_files.open(file.name, _O_RDONLY); if (descriptor < 0) continue;
            std::uint32_t tag = UINT32_MAX; g_sfera_files.seek(descriptor, 20, SEEK_SET); const auto read = g_sfera_files.read(descriptor, std::as_writable_bytes(std::span(&tag, 1))); g_sfera_files.close(descriptor);
            if (read != sizeof(tag) || tag >= std::size(g_sfera_mbc_runtime.modules)) continue;
            if (tag == 0) ::OutputDebugStringA((std::string("Null tag ") + file.name).c_str());
            auto& name = g_sfera_mbc_runtime.modules[tag].name;
            name = std::string_view(file.name).substr(0, 31);
            const auto extension = name.find_last_of('.');
            const auto separator = name.find_last_of('\\');
            if (extension != std::string::npos && (separator == std::string::npos || extension > separator)) name.resize(extension);
        } while (::_findnext64i32(search, &file) == 0);
        ::_findclose(search);
    }
    g_sfera_config_text_runtime.load("connectn.cfg");
    int port = 0; if (g_sfera_config_text_runtime.readInteger("PORT", port)) g_sfera_network_runtime.server_port = SferaNumeric::lowHalf(SferaNumeric::word(port));
    if (loadProcess("_main", 0) == UINT32_MAX) SferaClientApplication::terminateWithError("MBInter: Process '_main' not found");
    named_vectors.clear();
    g_sfera_effect_manager.pending_effect = nullptr; g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::fromUnixTime(::_time64(nullptr));
}

void SferaMbcRuntime::tick() {
    auto& log = g_sfera_log_runtime;
    if (dispatch_slot >= 0) return;
    SferaRestore dispatchScope(dispatch_slot);
    ++g_sfera_mbc_runtime.simulation_tick;
    if (++g_sfera_network_runtime.statistics_poll_ticks >= 192) {
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
    while (process_index >= 0 && std::cmp_less(process_index, std::size(processes)) && processes[process_index].chain_prev_index >= 0) {
        g_sfera_mbc_runtime.dispatch_slot = process_index; active_process = &processes[process_index]; program_table_base = active_process->programs.data(); bytecode_base = active_process->codeData(); process_memory_base = active_process->memory.data(); execution_context_depth = 0; execution_failed = false;
        bool unload = false;
        for (std::size_t priority = 0; priority <= priorityLimit && !unload; ++priority) {
            program_index = SferaNumeric::signedHalf(active_process->program_map_a[priority]);
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
                            if (instruction_step_count++ > 3500000) {
                                WorldDiagnostics::scriptContext(); log.write("\n---exit_inter start---\nMBINTER MESSAGE:Endless cycle found\n"); log.write(diagnostic_context); log.write("---exit_inter end-----\n"); execution_failed = true;
                                if (process_index == 0) SferaClientApplication::terminateWithError(diagnostic_context);
                                processes[0].activateProgram("EError"); unload = true; break;
                            }
                            current_instruction_address = instruction_cursor; current_opcode = SferaNumeric::enumFromBits<Instruction>(*instruction_cursor);
                            if (current_opcode == Instruction::Yield) { ++instruction_cursor; break; }
                            if (current_opcode == Instruction::EndProgram) {
                                active_program_record->callDepth = 0; active_program_record->state = -1; auto pending_program_index = SferaNumeric::signedHalf(active_process->program_map_b[priority]);
                                auto& head = active_process->program_map_a[priority]; auto& tail = active_process->program_map_b[priority];
                                if (program_index == SferaNumeric::word(SferaNumeric::signedHalf(tail))) {
                                    if (head == tail) {
                                        head = UINT16_MAX; tail = UINT16_MAX;
                                        if (std::all_of(std::begin(active_process->program_map_a), std::begin(active_process->program_map_a) + 3, [](std::uint16_t index) { return SferaNumeric::signedHalf(index) < 0; })) { dequeueProcess(*active_process); active_process->programs_queued = false; }
                                    } else { pending_program_index = SferaNumeric::signedHalf(active_program_record->previous_program); tail = pending_program_index; program_table_base[pending_program_index].next_program = tail; }
                                    finishPriority = true;
                                } else if (program_index == head) { head = active_program_record->next_program; program_table_base[head].previous_program = head; }
                                else { program_table_base[active_program_record->next_program].previous_program = active_program_record->previous_program; program_table_base[active_program_record->previous_program].next_program = active_program_record->next_program; }
                                break;
                            }
                            ++instruction_cursor;
                            try {
                                if (!executeInstruction(current_opcode)) reportInvalidInstruction();
                            } catch (const std::out_of_range& error) {
                                reportError(error.what());
                            } catch (const std::length_error& error) {
                                reportError(error.what());
                            } catch (const SferaBinary::ReadError& error) {
                                reportError(error.what());
                            }
                            if (execution_failed) { unload = true; break; }
                        }
                    }
                    if (!finishPriority && !unload) active_program_record->instruction_offset = instruction_cursor - bytecode_base;
                }
                if (finishPriority || unload) break;
                program_index = SferaNumeric::signedHalf(active_program_record->next_program);
                if (initialProgram == SferaNumeric::word(SferaNumeric::signedHalf(active_process->program_map_b[priority]))) break;
            }
        }
        if (unload || (active_process->flags & SferaMbcProcessRecord::unloadAfterExecution) != 0) {
            unloadProcess(process_index); if (process_index == process_chain_last) break;
        }
        const auto previousActive = g_sfera_mbc_runtime.dispatch_slot; process_index = active_process->execution_prev_index;
        if (previousActive == execution_chain_head) break;
    }
    g_sfera_mbc_runtime.dispatch_slot = -1;
    if (halt_state == SferaMbcRuntime::HaltState::Dispatched) { if (!final_shutdown) initialize(); return; }
    if (SferaNumeric::signedWord(g_sfera_mbc_runtime.simulation_tick) % 3 == 0) {
        g_sfera_network_runtime.receiveMessages();
        for (int index = g_sfera_mbc_runtime.active_world_slot; index >= 0;) {
            auto& slot = g_sfera_mbc_runtime.world_slots[index]; index = slot.primary_state;
            const auto flush = [&](std::uint32_t& bits, auto& payload, std::uint32_t& owner, std::uint32_t flags) {
                if (SferaNumeric::signedWord(bits) <= 0) return;
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
    const auto emit = [&](std::uint32_t value, std::int8_t width) { if (send_field_count >= outgoing_fields.size()) { reportError("Wrong data for 'send' function"); return false; } outgoing_fields[send_field_count].word = value; outgoing_fields[send_field_count++].format = width; return true; };
    for (int field = 0; field < definition.field_count; ++field) {
        if (argument_cursor >= argument_end || --argument_count < 0) { reportError("Wrong number of parameters for 'send' function"); return; }
        const auto value = g_sfera_mbc_runtime.values[argument_cursor++].value.base;
        const int width = definition.formats[field];
        if ((width >= -32 && width <= 32) || (width >= 103 && width <= 108)) { if (!emit(value, std::abs(width))) return; continue; }
        if (width != 101 && width != 102) { reportError("Wrong data for 'send' function"); return; }
        const auto count = std::clamp(SferaNumeric::signedWord(value), 0, width == 101 ? 15 : 255);
        if (!emit(count, width == 101 ? 4 : 8)) return;
        if (--argument_count < 0 || ++field >= definition.field_count || argument_cursor >= argument_end) { reportError("Wrong data for 'send' function"); return; }
        const auto elementWidth = std::abs(definition.formats[field]); const auto& array = g_sfera_mbc_runtime.values[argument_cursor];
        if (elementWidth > 32 || !array.isPointer()) { reportError("Wrong data for 'send' function"); return; }
        const auto elementSize = array.elementSize(); ++argument_cursor;
        if (elementSize > 4) { reportError("Wrong data for 'send' function"); return; }
        const auto* data = memoryBytes(array.value.base, count * elementSize).data();
        for (int index = 0; index < count; ++index) { std::uint32_t item = 0; std::memcpy(&item, data, elementSize); data += elementSize; if (!emit(item, elementWidth)) return; }
    }
    sendRegion(400, SferaNumeric::word(region), SferaNumeric::word(definition.flags));
}

void SferaClientApplication::configureResourceDirectory() {
    const auto containsClient = [](const std::filesystem::path& directory) { std::error_code error; return std::filesystem::is_regular_file(directory / L"mbc" / L"_main.mbc", error); };
    std::filesystem::path root;
    const DWORD required = ::GetEnvironmentVariableW(L"SFERA_CLIENT_ROOT", nullptr, 0);
    if (required != 0) {
        std::wstring configured(required, L'\0');
        const DWORD length = ::GetEnvironmentVariableW(L"SFERA_CLIENT_ROOT", configured.data(), required);
        if (length == 0 || length >= required) throw std::runtime_error("Cannot read SFERA_CLIENT_ROOT");
        configured.resize(length);
        root = std::filesystem::absolute(std::filesystem::path(configured));
        if (!containsClient(root)) throw std::runtime_error("SFERA_CLIENT_ROOT does not contain mbc\\_main.mbc");
    } else {
        std::wstring executable(512, L'\0');
        for (;;) {
            const DWORD length = ::GetModuleFileNameW(nullptr, executable.data(), SferaNumeric::lowWord(executable.size()));
            if (length == 0) throw std::runtime_error("Cannot determine the client executable path");
            if (length + 1 < executable.size()) {
                executable.resize(length);
                break;
            }
            if (executable.size() >= 32768) throw std::length_error("Client executable path is too long");
            executable.resize(std::min<std::size_t>(executable.size() * 2, 32768));
        }
        const std::array<std::filesystem::path, 2> starts{std::filesystem::current_path(), std::filesystem::path(executable).parent_path()};
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
    if (!::SetCurrentDirectoryW(root.c_str())) throw std::system_error(SferaNumeric::signedWord(::GetLastError()), std::system_category(), "SetCurrentDirectoryW");
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
        const auto arguments = SferaClientApplication::commandLineArguments(::GetCommandLineA());
        if (arguments.find("/15FCE220-0246-58ec-3EH2-968B3072ACF8") != std::string_view::npos) {
            ::MessageBoxA(nullptr, "\307\340\357\363\361\352 \357\360\356\350\347\342\356\344\350\362\361\377 \357\360\356\343\360\340\354\354\356\351 Sphere.exe.", "\316\370\350\341\352\340 \347\340\357\363\361\352\340.", MB_ICONERROR);
            SferaClientApplication::releaseStorage();
            return 0;
        }
        const auto readArgument = [arguments](std::string_view name, std::string& output, std::size_t limit) {
            output.clear();
            const auto position = arguments.find(name);
            if (position == std::string_view::npos) return false;
            auto value = arguments.substr(position + name.size());
            const auto first = value.find_first_not_of(" \t");
            if (first == std::string_view::npos) return true;
            value.remove_prefix(first);
            output = value.substr(0, std::min(value.find_first_of(" \t"), limit));
            return true;
        };

        readArgument("/locale", SferaClientApplication::locale, 9);
        for (const std::string_view directory : {".\\logs", ".\\players"}) ::CreateDirectoryA(directory.data(), nullptr);
        SphereRender::SceneRenderer::buildColorRemap(1.0, 0.3f);
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

void SferaLogRuntime::writeTimestamp(std::string_view prefix) {
    write(prefix);
    const auto timestamp = ::_time64(nullptr);
    tm local{};
    ::_localtime64_s(&local, &timestamp);
    std::string date(128, '\0');
    date.resize(std::strftime(date.data(), date.size(), "%A, %d %B %Y", &local));
    write(date);
    write("  ");
    std::string time(9, '\0');
    if (::_strtime_s(time.data(), time.size()) != 0) time.clear();
    else time.resize(time.find('\0'));
    write(time);
    write("\n");
}

bool SferaClientApplication::initialize() {

    auto& settings = g_sfera_config_text_runtime;
    const auto readInteger = [&settings]<class T>(std::string_view name, T& output) {
        int value = 0;
        if (!settings.readInteger(name, value)) return false;
        if constexpr (std::is_same_v<T, bool>) output = value != 0;
        else if constexpr (std::is_unsigned_v<T>) output = SferaNumeric::word(value);
        else output = value;
        return true;
    };
    g_sfera_files.setErrorReporting(true);
    g_sfera_files.addSearchPath("params");
    g_sfera_files.addSearchPath("mbc");
    g_sfera_log_runtime.initialize();
    const auto comResult = ::CoInitialize(nullptr);
    if (FAILED(comResult)) throw std::system_error(SferaNumeric::signedWord(comResult), std::system_category(), "CoInitialize");
    com_initialized = true;
    settings.load("config.cfg");
    SferaClientApplication::language = 0;
    readInteger("LANG", SferaClientApplication::language);
    if (!SferaClientApplication::locale.empty()) {
        constexpr std::string_view locales[]{"ru", "en", "pt", "it", "de", "es", "fr"};
        SferaClientApplication::language = 1;
        for (std::uint32_t index = 0; index < std::size(locales); ++index) if (std::string_view(SferaClientApplication::locale).substr(0, 2) == locales[index]) { SferaClientApplication::language = index; break; }
    }
    constexpr std::string_view suffixes[]{"", "_e", "_p", "_i", "_d", "_spa", "_f"};
    g_sfera_font_runtime.language_suffix = SferaClientApplication::language < std::size(suffixes) ? suffixes[SferaClientApplication::language] : "";
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
        if (file.get() >= 0) g_sfera_files.read(file.get(), std::as_writable_bytes(std::span(&GameInterface::loading_total, 1)));
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
    g_sfera_graphics_runtime.display_width = ::GetSystemMetrics(SM_CXSCREEN);
    g_sfera_graphics_runtime.display_height = ::GetSystemMetrics(SM_CYSCREEN);
    g_sfera_graphics_runtime.display_depth_bits = 16;
    readInteger("XRES", g_sfera_graphics_runtime.display_width);
    readInteger("YRES", g_sfera_graphics_runtime.display_height);
    readInteger("DEPTH", g_sfera_graphics_runtime.display_depth_bits);
    readInteger("GRASS", g_sfera_graphics_runtime.grass_depth);
    settings.readFloat("LOD_DISTANCE", g_sfera_graphics_runtime.minimum_lod_distance);
    settings.readFloat("MIN_LOD_DIST", g_sfera_graphics_runtime.lod_distance);
    readInteger("POSTEFFECTS", g_sfera_graphics_runtime.post_effects_enabled);
    {
        int configured_fov = static_cast<int>(SferaGraphicsRuntime::default_field_of_view);
        const bool had_fov = settings.readInteger("FOV", configured_fov);
        const int clamped_fov = std::clamp(
            configured_fov,
            static_cast<int>(SferaGraphicsRuntime::minimum_field_of_view),
            static_cast<int>(SferaGraphicsRuntime::maximum_field_of_view));
        g_sfera_graphics_runtime.field_of_view_degrees = static_cast<std::uint32_t>(clamped_fov);
        if (!had_fov || configured_fov != clamped_fov) {
            settings.writeValue("FOV", std::to_string(clamped_fov), false);
            settings.save();
        }
    }
    if (g_sfera_graphics_runtime.minimum_lod_distance == 0.0f) g_sfera_graphics_runtime.minimum_lod_distance = 23.0f;
    if (g_sfera_graphics_runtime.lod_distance == 0.0f) g_sfera_graphics_runtime.lod_distance = 20.0f;
    const std::array<std::pair<std::string_view, bool*>, 3> landscapes{{{"landscape_hr", &TerrainAssets::high_resolution_assets}, {"landscape_ph", &TerrainAssets::alternate_ph_assets}, {"landscape_rd", &TerrainAssets::alternate_rd_assets}}};
    for (const auto& [path, enabled] : landscapes) { const DWORD attributes = ::GetFileAttributesA(path.data()); *enabled = attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0; }
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
        const std::string path = "fonts\\font" + std::to_string(index + 1) +
            (SferaClientApplication::language != 0 && SferaClientApplication::language != 1 ? g_sfera_font_runtime.language_suffix : "") + ".pcx";
        g_sfera_font_runtime.load(index, path, 1, 1, index == 0 ? 5 : 3);
    }
    SphereRender::ModelPose::coordinate_basis = {};
    SphereRender::ModelPose::coordinate_basis.m[2][0] = 1.0f;
    SphereRender::ModelPose::coordinate_basis.m[0][1] = -1.0f;
    SphereRender::ModelPose::coordinate_basis.m[1][2] = -1.0f;
    SphereRender::ModelPose::coordinate_basis.m[3][3] = 1.0f;
    for (std::size_t index = 0; index < std::size(g_sfera_motion.material_scale); ++index) g_sfera_motion.material_scale[index] = index / 6.0;
    constexpr float weights[]{2.0f, 0.2f, 0.75f, 1.2f, 2.5f, 3.0f, 4.0f};
    for (std::size_t index = 0; index < std::size(weights); ++index) g_sfera_motion.surface_friction[index] = weights[index];
    TerrainTextureCache::initialize();
    g_sfera_motion.initializeResponseCurve();
    return true;
}

void TerrainTextureCache::initialize() {
    std::array<float, 12> passes{};
    for (std::uint32_t row = 0; row < 12; ++row) {
        const float position = (row * 254) / 12.0 + 1.0 - 1.0 / 24.0;
        const auto bucket = SferaNumeric::truncateInt(position + 0.5) - 1;
        const double precise_position = position;
        passes[row] = precise_position - bucket;
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
            const auto bucket = SferaNumeric::truncateInt(position + 0.5) - 1;
            const double precise_position = position;
            const float fraction = precise_position - bucket - 0.5;
            TerrainTextureCache::quantization_x[row * 256 + column] = bucket;
            TerrainTextureCache::quantization_y[row * 256 + column] = std::trunc(fraction * 64.0 + 0.5);
            const double precise_position_next = position;
            constexpr double position_step = 1.0f / 12.0f;
            position = precise_position_next + position_step;
        }
    }
    for (std::size_t row = 0; row < 64; ++row) {
        const float y = row / 64.0f;
        for (std::size_t column = 0; column < 64; ++column) {
            const float x = column / 64.0f;
            const float weights[]{(1.0f - x) * (1.0f - y), x * (1.0f - y), (1.0f - x) * y, x * y};
            for (std::size_t channel = 0; channel < std::size(weights); ++channel) TerrainTextureCache::blend_lut[(row * 64 + column) * 4 + channel] = std::trunc(weights[channel] * 255.0);
        }
    }
    std::fill(std::begin(g_sfera_direct_input_runtime.allowed_glyphs), std::end(g_sfera_direct_input_runtime.allowed_glyphs), 0);
    for (const auto glyph : std::string_view("!\"#$%&'(.")) g_sfera_direct_input_runtime.allowed_glyphs[SferaText::byteValue(glyph)] = 1;
    g_sfera_direct_input_runtime.allowed_glyphs[UINT8_MAX] = 1;
}

void SferaClientApplication::resetWorld() {
    g_sfera_world_objects.destroyAll();
    g_sfera_sound_runtime.initialize();
    ShadowMap::initialize(1);
    WorldGuiControls::destroyAllText();

    g_sfera_interface.default_cursor_name = "cursor1";
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
    const auto elapsed = SferaNumeric::signedWord(SferaNumeric::word(tick_remainder_) + current - previous_tick_);
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
    g_sfera_interface.update(SferaNumeric::lowByte(g_sfera_direct_input_runtime.virtual_key), g_sfera_direct_input_runtime.character, mouse.buttons, mouse.wheel);
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
    const double precise_phase = phase;
    constexpr double phase_step = 0.0005f;
    phase = precise_phase + phase_step;
    if (phase > 1.0f) phase = phase - 1.0;
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
        if (weather != nullptr) weather->update(SferaNumeric::signedWord(WorldClock::calendarTicks()), g_sfera_graphics_runtime.environment_factor, g_sfera_weather_runtime.current, SphereWorld::Vegetation::alternatePatterns());
        if (g_sfera_sound_runtime.volume_refresh_active) {
            const bool increase = g_sfera_sound_runtime.volume_refresh_direction;
            g_sfera_sound_runtime.adjustMusicVolume(increase ? 1 : -1);
            g_sfera_sound_runtime.volume_refresh_direction = !increase;
            g_sfera_sound_runtime.volume_refresh_frames = g_sfera_sound_runtime.volume_refresh_frames + 1.0;
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
        if (steps == 0) { const auto delay = (52 - tick_remainder_) / 10; if (delay > 50) ::Sleep(19); else if (delay > 1) ::Sleep(delay - 1); }
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
    for (int refresh = 0; refresh < 2; ++refresh) { g_sfera_graphics_runtime.rebuild_percent = -1; GameInterface::updateLoadingProgress(0); }
    ::Sleep(50); g_sfera_effect_manager.initialize(); ::Sleep(50); g_sfera_materials.load("models\\materls.mtr"); ::Sleep(50); TerrainAssets::loadMap(); ::Sleep(50);
    const auto loadConfiguration = []<class T>(std::unique_ptr<T>& owner, const std::string& path) {
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
    constexpr std::string_view folders[]{"xadd\\"};
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
    ::Sleep(50);
    for (std::uint32_t expectedHandle = 0u; expectedHandle < 2u; ++expectedHandle) {
        const auto handle = g_sfera_world_objects.create("cam_cube", nullptr, expectedHandle == 0u ? 0u : 5u, true);
        if (handle != expectedHandle) {
            terminateWithError(std::format("Camera initialization: expected handle {}, got {}", expectedHandle, handle));
        }
        auto* camera = g_sfera_world_objects.extendedObject(handle);
        if (camera == nullptr) terminateWithError(std::format("Camera object {} was not created", handle));
        if (expectedHandle == 0u) camera->render_enabled = false;
    }
    g_sfera_vegetation.initialize();
    ::Sleep(50);
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
        ::UnregisterClassA(GameInterface::nativeWindowClassName.data(), instance_handle);
        window_class_registered = false;
    }
    if (com_initialized) { ::CoUninitialize(); com_initialized = false; }
    finish([] {
        g_sfera_log_runtime.writeTimestamp("**** Quit: ");
        g_sfera_log_runtime.write("\n");
        if (std::cmp_greater(g_sfera_files.fileSize("Error.log"), g_sfera_log_runtime.size_limit))
            g_sfera_files.keepTail("Error.log", g_sfera_log_runtime.size_limit);
    });
    resources_loaded = main_loop_started = application_active = false;
    lifecycle = Lifecycle::Stopped;
}

[[noreturn]] void SferaClientApplication::terminateWithError(std::string_view message) {
    if (fatal_error_in_progress) throw std::runtime_error(message.empty() ? std::string("Client error") : std::string(message));
    fatal_error_in_progress = true;
    std::string description = "ServerN=" + std::to_string(server_number) + "  " + std::string(message);
    if (const auto context = WorldDiagnostics::scriptContext()) { description += '\n'; description += *context; }
    throw std::runtime_error(description);
}

[[noreturn]] void SferaClientApplication::arrayBoundsError(int index) {
    std::string message;
    if (index < 0) message = std::format("BoundCheckArray error: index less than zero\n");
    else message = std::format("BoundCheckArray error: index out of range {}\n", index);
    terminateWithError(message);
}

// Options transactions and application commands.
namespace {
    using namespace SphereUI;

    void queueInterfaceRefresh() {
        g_sfera_interface.queueEvent({nullptr, 0u, UiMessage::refreshInterface, 0u, 0u});
    }

    constexpr std::uint32_t fov_slider_control_id = 0xF001u;
    constexpr std::uint32_t fov_label_control_id = 0xF002u;
    constexpr std::uint32_t fov_decoration_control_id = 0xF010u;

    Window* optionChild(Window* window, std::uint32_t index) {
        return window == nullptr ? nullptr : window->controlAt(index);
    }

    Window* optionControl(Window* window, std::uint32_t control_id) {
        if (window == nullptr) return nullptr;
        const auto found = std::find_if(window->children.begin(), window->children.end(), [control_id](const auto& child) {
            return child != nullptr && child->control_id == control_id;
        });
        return found == window->children.end() ? nullptr : found->get();
    }

    void optionMessage(Window* window, std::uint32_t index, SphereUI::UiMessage message, std::uint32_t first = 0u, std::uint32_t second = 0u) {
        if (auto* child = optionChild(window, index)) child->handleMessage(message, first, second);
    }

    void optionText(Window* window, std::uint32_t index, std::string_view text) {
        if (auto* child = optionChild(window, index)) child->setText(text);
    }

    void optionLabel(Window* window, std::uint32_t index, std::string_view key) {
        optionText(window, index, g_sfera_interface.localizedText(key));
    }

    void optionToggleLabel(Window* window, std::uint32_t index, std::uint32_t value) {
        optionLabel(window, index, value != 0u ? "UISTR_WT_OPT16" : "UISTR_WT_OPT17");
    }

    void setOptionsVisible(bool show);
    void setInterfaceOptionsVisible(bool show);
    void setGraphicsOptionsVisible(bool show);
    void setFontOptionsVisible(bool show);
    Window* beginOptionsDialog(std::string_view name, WindowEventHandler handler, bool show) {
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

    std::string_view bindingName(std::uint32_t key) {
        const auto name = SphereUI::Runtime::keyName(key);
        return name.empty() ? "???" : name;
    }

    Window* bindingRow(Window* window, std::uint32_t slot) {
        auto* list = optionChild(window, 5u);
        return list == nullptr ? nullptr : list->asListItemCtrl() != nullptr ? list->asListItemCtrl()->itemAt(slot) : nullptr;
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
                g_sfera_interface.options.binding_key_name = std::string("UISTR_WT_KEY") + (slot < 9u ? "0" : "") + std::to_string(slot + 1u);
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
    constexpr std::string_view interfaceSettingKeys[] = {"ISSN", "ISAD", "INSN", "INAW", "IAPM", "MBST", "BALR"};
    void setInterfaceOptionsVisible(bool show) {
        auto* window = beginOptionsDialog("interface_options", WindowEventHandler::interface_options, show);
        if (window == nullptr) return;

        if (show) {
            for (std::size_t index = 0u; index < 5u; ++index) g_sfera_interface.options.saved_interface[index] = index == 2u ? g_sfera_interface.sounds_enabled : g_sfera_mbc_runtime.namedValue(interfaceSettingKeys[index]);
            InterfaceConfiguration::open("config.cfg");
            g_sfera_interface.options.saved_interface[5] = InterfaceConfiguration::readInteger("MBST", g_sfera_interface.options.saved_interface[5]);
            g_sfera_interface.options.saved_interface[6] = UINT32_MAX;
            g_sfera_interface.options.saved_interface[6] = InterfaceConfiguration::readInteger("BALR", g_sfera_interface.options.saved_interface[6]);
            if (SferaNumeric::signedWord(g_sfera_interface.options.saved_interface[6]) < 0) {
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
        const auto count = g_sfera_graphics_runtime.d3d_runtime->display_modes.size();
        for (std::size_t index = 0u; index < count; ++index) {
            const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index);
            if (mode.width == requested.width && mode.height == requested.height && mode.depth == requested.depth) return SferaNumeric::lowWord(index);
        }
        for (std::size_t index = count; index != 0u; --index) {
            const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index - 1u);
            if (mode.depth == requested.depth && mode.width <= SferaClientApplication::desktop_width && mode.height <= SferaClientApplication::desktop_height) return SferaNumeric::lowWord(index - 1u);
        }
        return SferaNumeric::lowWord(count - 1u);
    }

    void setOptionsModeLabel(Window* window, std::uint32_t index) {
        const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index);
        const auto text = std::to_string(mode.width) + "x" + std::to_string(mode.height) + " " + std::to_string(mode.depth);
        optionText(window, 7u, text);
    }

    std::string_view graphicsBooleanLabel(std::uint32_t value) {
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
        if (enabled) optionMessage(window, 46u, UiMessage::setScrollValue, SferaNumeric::lowWord(SferaNumeric::truncateInt64(g_sfera_graphics_runtime.lod_distance - 12.0)));
    }

    void setupFogOptions(Window* window) {
        const auto automatic = g_sfera_graphics_runtime.auto_fog;
        optionToggleLabel(window, 37u, automatic);
        optionSelection(window, 39u, 1u, automatic);
        optionMessage(window, 28u, UiMessage::setScrollRange, 0u, automatic ? 0u : 170u);
        if (!automatic) optionMessage(window, 28u, UiMessage::setScrollValue, SferaNumeric::lowWord(SferaNumeric::truncateInt64(g_sfera_graphics_runtime.fog_distance - 30.0)));
    }

    void updateFovLabel(Window* window) {
        if (auto* label = optionControl(window, fov_label_control_id))
            label->setText(std::format("FOV: {}", g_sfera_graphics_runtime.field_of_view_degrees));
    }

    void addFovControls(Window* window) {
        if (window == nullptr || optionControl(window, fov_slider_control_id) != nullptr) return;

        auto* scroll_template = optionChild(window, 46u);
        if (scroll_template == nullptr || scroll_template->asScrollBar() == nullptr) return;

        auto slider = scroll_template->clone();
        auto* fov_slider = slider->asScrollBar();
        if (fov_slider == nullptr) return;
        fov_slider->control_id = fov_slider_control_id;
        fov_slider->step = 1;
        fov_slider->page_step = 5;
        fov_slider->explicit_step = true;
        fov_slider->notify_changes = true;
        fov_slider->hidden = false;
        fov_slider->disabled = false;
        fov_slider->input_enabled = true;

        const auto makeNavigationButtonVisible = [](ButtonCtrl* button) {
            if (button == nullptr) return;
            button->hidden = false;
            button->disabled = false;
            button->input_enabled = true;
            button->visual_state = 0u;
            if (button->hover_image != nullptr) button->idle_image = button->hover_image;
            else if (button->idle_image == nullptr) button->idle_image = button->pressed_image;
            if (button->hover_image == nullptr) button->hover_image = button->idle_image;
            if (button->pressed_image == nullptr) button->pressed_image = button->hover_image;
            if (button->disabled_image == nullptr) button->disabled_image = button->idle_image;
        };
        makeNavigationButtonVisible(fov_slider->decrease_button.get());
        makeNavigationButtonVisible(fov_slider->increase_button.get());

        Window* label_template = nullptr;
        int label_distance = std::numeric_limits<int>::max();
        const int slider_center_y = scroll_template->y + scroll_template->height / 2;
        for (const auto& child : window->children) {
            if (child == nullptr || child->control_kind != UiControlKind::text || child->x >= scroll_template->x) continue;
            const int child_center_y = child->y + child->height / 2;
            const int distance = std::abs(child_center_y - slider_center_y);
            if (distance < label_distance) {
                label_distance = distance;
                label_template = child.get();
            }
        }
        if (label_template == nullptr) label_template = optionChild(window, 49u);

        std::unique_ptr<Window> label;
        if (label_template != nullptr) {
            label = label_template->clone();
        } else {
            auto fallback = std::make_unique<TextCtrl>();
            fallback->height = 16;
            fallback->x = std::max(0, fov_slider->x - 90);
            label = std::move(fallback);
        }
        if (label == nullptr) return;
        label->control_id = fov_label_control_id;
        label->hidden = false;
        label->disabled = false;
        label->input_enabled = false;
        label->height = std::max(label->height, 16);
        label->width = std::max(60, fov_slider->x - label->x - 4);

        std::vector<std::unique_ptr<Window>> decorations;
        const int template_left = scroll_template->x - 12;
        const int template_right = scroll_template->x + scroll_template->width + 12;
        std::uint32_t decoration_index = 0u;
        for (const auto& child : window->children) {
            if (child == nullptr || child.get() == scroll_template || child.get() == label_template) continue;
            const bool decorative_kind = child->control_kind == UiControlKind::image ||
                (child->control_kind == UiControlKind::window && child->resource_reference != nullptr);
            if (!decorative_kind || child->height > scroll_template->height + 12) continue;
            const int child_center_y = child->y + child->height / 2;
            if (std::abs(child_center_y - slider_center_y) > std::max(6, scroll_template->height / 2)) continue;
            if (child->x + child->width < template_left || child->x > template_right) continue;

            auto decoration = child->clone();
            if (decoration == nullptr) continue;
            decoration->control_id = fov_decoration_control_id + decoration_index++;
            decoration->hidden = false;
            decoration->disabled = false;
            decoration->input_enabled = false;
            decorations.push_back(std::move(decoration));
        }

        auto* primary_button = optionChild(window, 1u);
        auto* secondary_button = optionChild(window, 2u);
        int insertion_y = window->height - 34;
        if (primary_button != nullptr && secondary_button != nullptr) insertion_y = std::min(primary_button->y, secondary_button->y);
        else if (primary_button != nullptr) insertion_y = primary_button->y;
        else if (secondary_button != nullptr) insertion_y = secondary_button->y;

        const int row_height = std::max(label->height, fov_slider->height) + 4;
        int content_bottom = 0;
        for (const auto& child : window->children) {
            if (child == nullptr || child.get() == primary_button || child.get() == secondary_button || child->y >= insertion_y) continue;
            if (child->control_kind == UiControlKind::image || child->control_kind == UiControlKind::window) continue;
            content_bottom = std::max(content_bottom, child->y + child->height);
        }
        const int available_gap = std::max(0, insertion_y - content_bottom);
        const int layout_shift = std::max(0, row_height - available_gap);
        if (layout_shift != 0) {
            for (auto& child : window->children) {
                if (child != nullptr && child->y >= insertion_y) {
                    child->y += layout_shift;
                    child->initial_y += layout_shift;
                }
            }
            window->height += layout_shift;
        }
        const int row_y = insertion_y + layout_shift - row_height;

        label->y = row_y + (row_height - label->height) / 2;
        label->initial_x = label->x;
        label->initial_y = label->y;
        fov_slider->y = row_y + (row_height - fov_slider->height) / 2;
        fov_slider->initial_y = fov_slider->y;
        const int decoration_shift_y = fov_slider->y - scroll_template->y;
        for (auto& decoration : decorations) {
            decoration->y += decoration_shift_y;
            decoration->initial_y = decoration->y;
            window->appendChild(std::move(decoration));
        }
        fov_slider->handleMessage(
            UiMessage::setScrollRange,
            0u,
            SferaGraphicsRuntime::maximum_field_of_view - SferaGraphicsRuntime::minimum_field_of_view);
        fov_slider->handleMessage(
            UiMessage::setScrollValue,
            g_sfera_graphics_runtime.field_of_view_degrees - SferaGraphicsRuntime::minimum_field_of_view,
            0u);

        window->appendChild(std::move(label));
        window->appendChild(std::move(slider));
        updateFovLabel(window);
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
            g_sfera_interface.options.saved_field_of_view = graphics.field_of_view_degrees;
            values[9] = g_sfera_graphics_runtime.auto_fog;
            values[8] = g_sfera_effect_manager.effects_enabled;
            g_sfera_interface.options.graphics_page = g_sfera_graphics_runtime.reflection_quality;
            constexpr std::string_view label_keys[] = {"UISTR_WT_OPT21", "UISTR_WT_OPT20", "UISTR_WT_OPT19", "UISTR_WT_OPT18", "UISTR_WT_OPT17", "UISTR_WT_OPT17", "UISTR_WT_OPT16"};
            for (std::size_t index = 0u; index < std::size(label_keys); ++index) g_sfera_interface.options.labels[index] = g_sfera_interface.localizedText(label_keys[index]);
            g_sfera_interface.options.unknown_graphics_label = g_sfera_interface.localizedText("UISTR_WT_OPT36");
            InterfaceConfiguration::open("config.cfg");
            OptionsDisplayMode mode{SferaNumeric::word(graphics.display_width), SferaNumeric::word(graphics.display_height), g_sfera_graphics_runtime.display_depth_bits};
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
            optionSelection(window, 15u, g_sfera_graphics_runtime.d3d_runtime->display_modes.size() - 1u, values[5]);
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
            addFovControls(window);
            return;
        }
        setOptionsVisible(true);
        shadows->quality = values[2];
        g_sfera_graphics_runtime.grass_depth = values[3];
        SferaClientApplication::windowed = values[4];
        InterfaceConfiguration::open("config.cfg");
        const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(values[5]);
        const std::pair<std::string_view, std::uint32_t> settings[] = { {
            "XRES", mode.width
        }, {"YRES", mode.height}, {"DEPTH", mode.depth}, {"GRASS", values[3]}, {"WINDOWED", values[4]}, {"SHAD", values[2]}, {"AUTOFOG", g_sfera_graphics_runtime.auto_fog}, {"FOGDIST", SferaNumeric::word(SferaNumeric::truncateInt(graphics.fog_distance))}, {"REFLQUAL", g_sfera_graphics_runtime.reflection_quality}, {"EFFECTS", g_sfera_effect_manager.effects_enabled}, {"LODS", graphics.lods_enabled}, {"LOD_DISTANCE", SferaNumeric::word(SferaNumeric::truncateInt(g_sfera_graphics_runtime.minimum_lod_distance))}, {"MIN_LOD_DIST", SferaNumeric::word(SferaNumeric::truncateInt(g_sfera_graphics_runtime.lod_distance))}, {"POSTEFFECTS", values[6]}, {"FOV", graphics.field_of_view_degrees}};
        for (const auto& setting : settings) InterfaceConfiguration::writeInteger(setting.first, setting.second);

        InterfaceConfiguration::save();
        if (values[10] != values[0] || values[11] != values[1] || g_sfera_interface.options.comparison_graphics_value != values[4])
            SferaClientApplication::quit_requested = true;
    }

    void handleHelpEvent(Window* window, const WindowEvent& event) {
        if (event.message == UiMessage::close) {
            g_sfera_interface.showHelpPage(std::nullopt);
            return;
        }
        if (event.message == UiMessage::leftClick) {
            if (event.control_id == 1u) g_sfera_interface.showHelpPage("Language\\helpindex.hts");
            else if (event.control_id == 2u) optionMessage(window, 3u, UiMessage::previousHyperTextPage);
            return;
        }
        if (event.message != UiMessage::hyperTextPageChanged) return;
        auto* control = event.source != nullptr ? event.source->asHyperTextCtrl() : nullptr;
        if (control == nullptr) return;
        const auto* document = control->document.get();
        if (document != nullptr && SferaText::asciiEqual(document->name, "Language\\helpindex.hts")) control->handleMessage(UiMessage::clearHyperTextHistory, 0u, 0u);
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
            if (const auto* music = optionChild(window, 7u)->asScrollBar()) g_sfera_interface.options.saved_music_volume = music->current;
            if (const auto* sound = optionChild(window, 8u)->asScrollBar()) g_sfera_interface.options.saved_sound_volume = sound->current;
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
        if (event.message == UiMessage::listItemEvent && SferaNumeric::enumFromBits<UiMessage>(SferaNumeric::lowHalf(event.first)) == UiMessage::leftClick && HIWORD(event.second) == 3u) {
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
                graphics.field_of_view_degrees = g_sfera_interface.options.saved_field_of_view;
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
                    optionSelection(window, 15u, g_sfera_graphics_runtime.d3d_runtime->display_modes.size() - 1u, g_sfera_interface.options.saved_graphics[5]);
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
                        optionMessage(window, 28u, UiMessage::setScrollValue, SferaNumeric::lowWord(SferaNumeric::truncateInt64(graphics.fog_distance - 30.0)));
                    }
                    g_sfera_graphics_runtime.auto_fog = automatic;
                    break;
                }
            case 43u:
                {
                    const bool enabled = event.first == 1u;
                    optionText(window, 41u, enabled ? g_sfera_interface.options.labels[6] : "");
                    optionMessage(window, 46u, UiMessage::setScrollRange, 0u, enabled ? 14u : 0u);
                    if (enabled) optionMessage(window, 46u, UiMessage::setScrollValue, SferaNumeric::lowWord(SferaNumeric::truncateInt64(g_sfera_graphics_runtime.lod_distance - 12.0)));
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
        } else if (event.message != UiMessage::horizontalScroll && event.message != UiMessage::sliderValueChanged) return;
        if (event.control_id == fov_slider_control_id) {
            const auto requested = SferaGraphicsRuntime::minimum_field_of_view + event.first;
            graphics.field_of_view_degrees = std::clamp(
                requested,
                SferaGraphicsRuntime::minimum_field_of_view,
                SferaGraphicsRuntime::maximum_field_of_view);
            updateFovLabel(window);
            return;
        }
        if (event.message != UiMessage::horizontalScroll) return;
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
            if (auto* description = window != nullptr ? window->asDescriptionWindow() : nullptr) description->handleEvent(event);
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

