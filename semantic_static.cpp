#include "semantic_static.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <limits>
#include <memory>
#include <new>
#include <string>
#include <utility>

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
}

void SferaEffectManager::reportError(const char* message) const { if (message != nullptr) std::fprintf(stderr, "%s\n", message); }
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

bool SferaMainUiStateRuntime::effectVisible(const IEffect& effect, const SferaVec3F& position) const {
    const SferaVec3F minimum{position.x + effect.bounds_min[0], position.y + effect.bounds_min[1], position.z + effect.bounds_min[2]};
    const SferaVec3F maximum{position.x + effect.bounds_max[0], position.y + effect.bounds_max[1], position.z + effect.bounds_max[2]};
    for (const auto& plane : clip_frustum.planes) {
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
        return !effect->script_name.empty() && SferaSimpleParser::equalsIgnoreCase(script_name, effect->script_name.c_str());
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
    g_sfera_main_view_state_runtime.view_accumulator += progress;
    const int work = std::max(static_cast<int>(g_sfera_world_load_runtime.loading_work_total) - 80, 1);
    int percent = static_cast<int>(g_sfera_main_view_state_runtime.view_accumulator) * 100 / work;
    percent = std::min(percent, 100);
    if (static_cast<std::uint32_t>(percent) == g_sfera_graphics_runtime.rebuild_percent) return;
    g_sfera_graphics_runtime.rebuild_percent = static_cast<std::uint32_t>(percent);
    auto* device_runtime = g_sfera_graphics_runtime.d3d_runtime.get();
    if (device_runtime == nullptr || !device_runtime->beginScene()) return;
    g_sfera_world_render_runtime.scene_active = true;
    g_sfera_interface.setLoadingProgress(percent);
    device_runtime->checkResult(device_runtime->native_device->EndScene(), "EndScene");
    device_runtime->waitForGpu();
    g_sfera_world_render_runtime.scene_active = false;
    device_runtime->checkResult(device_runtime->native_device->Present(nullptr, nullptr, nullptr, nullptr), "Present");
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
            if (SferaSimpleParser::equalsIgnoreCase(entry.path().extension().string().c_str(), extension)) callback(entry.path());
        }
    };
    enumerate("Effects", ".ssm", [&](const fs::path& path) { const std::string value = path.string(); registerEffectMeshFile(value.c_str()); });
    std::uint32_t total_count = 0u; enumerate("Effects", ".sef", [&](const fs::path&) { ++total_count; }); enumerate("Players", ".sef", [&](const fs::path&) { ++total_count; });
    std::uint32_t loaded_count = 0u;
    const auto load_group = [&](const fs::path& directory) {
        enumerate(directory, ".sef", [&](const fs::path& path) {
            auto effect = std::make_shared<CScriptedEffect>();
            effect->initializeScriptedState();
            try {
                if (effect->loadScript(path.string().c_str())) appendDefinition(std::move(effect));
            } catch (const std::logic_error& error) {
                reportError((path.string() + ": " + error.what()).c_str());
            }
            ++loaded_count; const std::uint32_t progress = total_count == 0u ? 30u : static_cast<std::uint32_t>((static_cast<std::uint64_t>(loaded_count) * 30u) / total_count); reportLoadProgress(progress);
        });
    };
    load_group("Effects"); load_group("Players");
}

void SferaEffectManager::destroyDefinitions() {
    definitions.clear();
    mesh_resources.clear();
}

bool SferaEffectManager::initialize() {
    if (initialized) return true;
    if (shutting_down) return false;
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
    if (shutting_down || active_effects.size() >= kMaximumActiveEffects) return nullptr;
    if (source_handle == 0u) reportError("EffectManager::createActiveEffect: zero source handle");
    std::shared_ptr<SferaActiveEffect> item;
    try {
        item = std::make_shared<SferaActiveEffect>();
        if (effect_id >= kSoundEffectIdBase) {
            if (!g_sfera_sound_runtime.interfaceAvailable()) return nullptr;
            item->resource = g_sfera_sound_runtime.createEffect(effect_id);
            if (item->resource == nullptr) return nullptr;
        } else {
            item->definition = findDefinition(effect_id);
            if (item->definition == nullptr) return nullptr;
            item->effect = item->definition->createEffectResources();
            if (item->effect == nullptr || (effects_enabled && item->effect->isEffectComplete())) return nullptr;
        }
        item->state_flags = kUninitializedEffectState;
        item->source_handle = source_handle;
        item->listener_key = effect_id;
        item->viewer_distance = viewerDistance(source_handle);
        item->position = g_sfera_world_objects.objectPosition(source_handle);
        if (item->effect != nullptr) item->effect->position = item->position;
        if (!g_sfera_world_objects.attachEffect(source_handle, *item)) return nullptr;
        item->active = true;
        active_effects.push_back(item);
        if (item->effect != nullptr) {
            if (auto* listener = findListener(effect_id)) {
                item->effect->listener = listener;
                if (!listener->onEffectAttached(*item->effect, *item, item->viewer_distance)) {
                    removeActiveEffect(item.get());
                    if (item->active) retireEffect(*item);
                    return nullptr;
                }
            }
        }
        return item->active ? item.get() : nullptr;
    } catch (const std::bad_alloc&) {
        if (item != nullptr && item->active) retireEffect(*item);
        return nullptr;
    } catch (...) {
        if (item != nullptr && item->active) retireEffect(*item);
        throw;
    }
}

SferaActiveEffect* SferaEffectManager::createActiveEffect(const char* script_name, std::uint32_t source_handle) {
    const auto definition = findDefinition(script_name);
    return definition != nullptr && static_cast<int>(definition->effect_id) > 0 ? createActiveEffect(definition->effect_id, source_handle) : nullptr;
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
    if (g_sfera_network_runtime.pending_effect == &item) g_sfera_network_runtime.pending_effect = nullptr;
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
        for (auto& frame : frames.transforms) frame = sfera_effect_identity;
    } else {
        frames = g_sfera_world_objects.buildEffectFrames(item.source_handle);
    }
    if (g_sfera_sound_runtime.interfaceAvailable()) effect->updateEffect({&frames.positions[0], viewer_distance});
    if (!item.active || shutting_down) return;
    const bool visible = state_flags == 0u;
    if (!effect->activation_blocked && !effect->activateEffect(visible)) {
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
        const float visibility_distance = g_sfera_view_spatial_runtime.basis[0].z + 10.0f;
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
                    if (!g_sfera_main_ui_state_runtime.effectVisible(*item.effect, position)) item.state_flags |= 2u;
                    else item.state_flags &= static_cast<std::uint16_t>(~2u);
                }
            }
            bool call_update = true;
            if (item.effect != nullptr && item.effect->activation_blocked) {
                if (item.state_flags == 0u) item.effect->activation_blocked = false;
                else if ((item.state_flags & 1u) != 0u) {
                    item.age_ticks += 2u;
                    if (item.effect->lifetime_ticks != kInvalidHandle && item.age_ticks >= item.effect->lifetime_ticks) removeActiveEffect(item);
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
