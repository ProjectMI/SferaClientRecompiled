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
constexpr std::uint16_t kTextureHashEnd = std::numeric_limits<std::uint16_t>::max();
constexpr std::uint32_t kReferenceObjectHandle = 1u;
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
constexpr std::size_t kParticleRandomValueCount = 65536u;
constexpr std::uint32_t kVisibilityRefreshPeriod = 32u;
constexpr int kFlareAlphaStep = 35;
constexpr int kMaximumAlpha = 255;
constexpr float kDefaultLightRadius = 10.0f;
constexpr float kFullCircleRadians = 6.283185958862305f;
void initialize_identity_frame(float* matrix);
}

void* SferaEffectManager::allocate(std::size_t size) const { return size == 0u ? nullptr : std::calloc(1u, size); }
void SferaEffectManager::free(void* pointer) const { std::free(pointer); }
void SferaEffectManager::reportError(const char* message) const { if (message != nullptr) std::fprintf(stderr, "%s\n", message); }
SferaEffectRenderSlot* SferaEffectManager::acquireRenderSlot() {
    if (render_slot_count >= render_slots.capacity || render_slots.data == nullptr) return nullptr;
    return render_slots.element(render_slot_count++);
}
void SferaEffectManager::finalizeBillboard(SferaEffectRenderSlot& slot, const SferaEffectVec3F& position, float size) const {
    const SferaEffectVec3F viewer{viewer_position.x, viewer_position.y, viewer_position.z};
    const SferaEffectVec3F view{position.x - viewer.x, position.y - viewer.y, position.z - viewer.z};
    SferaEffectVec3F right{view.y, -view.x, 0.0f};
    float length = std::sqrt(right.x * right.x + right.y * right.y + right.z * right.z);
    if (length > 0.00001f) { right.x /= length; right.y /= length; right.z /= length; }
    SferaEffectVec3F up{right.y * view.z - right.z * view.y, right.z * view.x - right.x * view.z, right.x * view.y - right.y * view.x};
    length = std::sqrt(up.x * up.x + up.y * up.y + up.z * up.z);
    if (length > 0.00001f) { up.x /= length; up.y /= length; up.z /= length; }
    right.x *= size; right.y *= size; right.z *= size; up.x *= size; up.y *= size; up.z *= size;
    slot.position[0] = {position.x - right.x - up.x, position.y - right.y - up.y, position.z - right.z - up.z};
    slot.position[1] = {position.x - right.x + up.x, position.y - right.y + up.y, position.z - right.z + up.z};
    slot.position[2] = {position.x + right.x + up.x, position.y + right.y + up.y, position.z + right.z + up.z};
    slot.position[3] = {position.x + right.x - up.x, position.y + right.y - up.y, position.z + right.z - up.z};
}
float SferaEffectManager::viewerDistance(const SferaEffectVec3F& position) const {
    const float dx = viewer_position.x - position.x;
    const float dy = viewer_position.y - position.y;
    const float dz = viewer_position.z - position.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}
float SferaEffectManager::viewerDistance(std::uint32_t source_handle) const { return viewerDistance(g_sfera_world_objects.objectPosition(source_handle)); }

bool SferaMainUiStateRuntime::effectVisible(const IEffect& effect, const SferaEffectVec3F& position) const {
    const SferaEffectVec3F minimum{position.x + effect.bounds_min[0], position.y + effect.bounds_min[1], position.z + effect.bounds_min[2]};
    const SferaEffectVec3F maximum{position.x + effect.bounds_max[0], position.y + effect.bounds_max[1], position.z + effect.bounds_max[2]};
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

void SferaLightRecord::update(const SferaEffectVec3F& new_position, const float* new_color, float new_radius) {
    position = new_position;
    std::copy_n(new_color, std::size(color), color);
    radius = new_radius == 0.0f ? kDefaultLightRadius : new_radius;
}

SferaLightRecord* SferaLightRuntime::record(std::int32_t handle) const {
    if (handle < 0 || static_cast<std::uint32_t>(handle) >= handles.capacity) return nullptr;
    auto* table = handles.data;
    return table == nullptr ? nullptr : table[handle];
}
std::int32_t SferaLightRuntime::create(const SferaEffectVec3F& position, const float* color, float radius) {
    auto* table = handles.data;
    if (table == nullptr || color == nullptr) return -1;
    std::uint32_t handle = 0u;
    while (handle < handles.capacity && table[handle] != nullptr) ++handle;
    if (handle >= handles.capacity) return -1;
    auto* light = static_cast<SferaLightRecord*>(g_sfera_effect_manager.allocate(sizeof(SferaLightRecord)));
    if (light == nullptr) return -1;
    light->update(position, color, radius);
    table[handle] = light;
    ++g_sfera_recovered_static_runtime.client_state_02;
    return static_cast<std::int32_t>(handle);
}
void SferaLightRuntime::write(std::int32_t handle, const SferaEffectVec3F& position, const float* color, float radius) {
    auto* light = record(handle);
    if (light != nullptr && color != nullptr) light->update(position, color, radius);
}
void SferaLightRuntime::release(std::int32_t handle) {
    auto* light = record(handle);
    if (light == nullptr) return;
    g_sfera_effect_manager.free(light);
    auto* table = handles.data;
    if (table != nullptr) table[handle] = nullptr;
    if (g_sfera_recovered_static_runtime.client_state_02 != 0u) --g_sfera_recovered_static_runtime.client_state_02;
}

void SferaEffectManager::appendDefinition(IEffect* effect) {
    if (effect == nullptr) return;
    effect->next = nullptr;
    effect->previous = nullptr;
    if (effect_definition_head == nullptr) { effect_definition_head = effect; return; }
    IEffect* tail = effect_definition_head;
    while (tail->next != nullptr) tail = tail->next;
    tail->next = effect;
    effect->previous = tail;
}

IEffect* SferaEffectManager::findDefinition(uint32_t effect_id) const {
    IEffect* effect = effect_definition_head;
    while (effect != nullptr) { if (effect->effect_id == effect_id) return effect; effect = effect->next; }
    return nullptr;
}

IEffect* SferaEffectManager::findDefinition(const char* script_name) const {
    if (script_name == nullptr) return nullptr;
    IEffect* effect = effect_definition_head;
    while (effect != nullptr) { if (effect->script_name != nullptr && SferaSimpleParser::equalsIgnoreCase(script_name, effect->script_name)) return effect; effect = effect->next; }
    return nullptr;
}

int32_t SferaEffectManager::findDefinitionId(const char* script_name) const {
    const IEffect* effect = findDefinition(script_name);
    return effect != nullptr ? static_cast<int32_t>(effect->effect_id) : -1;
}

void sfera_effect_list_append(SferaIntrusiveListHeader& list, SferaActiveEffect& item) {
    item.next = nullptr;
    item.previous = list.last;
    item.owner_list = &list;
    if (list.last) list.last->next = &item; else list.first = &item;
    list.last = &item;
}

void sfera_effect_list_remove(SferaIntrusiveListHeader& list, SferaActiveEffect& item) {
    if (item.owner_list != &list) return;
    if (item.previous) item.previous->next = item.next; else list.first = item.next;
    if (item.next) item.next->previous = item.previous; else list.last = item.previous;
    item.next = item.previous = nullptr;
    item.owner_list = nullptr;
}

bool SferaItemArray::grow(std::size_t item_size) {
    if (growth_count == 0u || item_size == 0u || growth_count > std::numeric_limits<std::size_t>::max() - free_capacity || growth_count > std::numeric_limits<std::size_t>::max() / item_size) return false;
    const std::size_t block_count = block_vector_begin ? block_vector_end - block_vector_begin : 0u;
    const auto new_capacity = free_capacity + growth_count;
    auto* block = static_cast<std::byte*>(std::calloc(growth_count, item_size));
    auto** new_blocks = static_cast<void**>(std::calloc(block_count + 1u, sizeof(void*)));
    auto** new_free = static_cast<void**>(std::calloc(new_capacity, sizeof(void*)));
    if (!block || !new_blocks || !new_free) { std::free(block); std::free(new_blocks); std::free(new_free); return false; }
    if (block_count) std::copy_n(block_vector_begin, block_count, new_blocks);
    if (free_count) std::copy_n(free_items, free_count, new_free);
    for (std::size_t index = 0; index < growth_count; ++index) new_free[free_count + index] = block + std::size_t(index) * item_size;
    new_blocks[block_count] = block;
    std::free(block_vector_begin);
    std::free(free_items);
    block_vector_begin = new_blocks;
    block_vector_end = block_vector_capacity_end = new_blocks + block_count + 1u;
    free_items = new_free;
    free_count += growth_count;
    free_capacity = new_capacity;
    return true;
}

void* SferaItemArray::take() { return free_count ? free_items[--free_count] : nullptr; }
void SferaItemArray::put(void* item) { if (!item) return; if (free_count == free_capacity) throw std::logic_error("Pool free list overflow"); free_items[free_count++] = item; }
void SferaItemArray::clear() {
    for (auto** block = block_vector_begin; block != block_vector_end; ++block) std::free(*block);
    std::free(block_vector_begin);
    std::free(free_items);
    block_vector_begin = block_vector_end = block_vector_capacity_end = free_items = nullptr;
    free_count = free_capacity = 0u;
}

namespace {
void initialize_identity_frame(float* matrix) {
    std::fill_n(matrix, 16u, 0.0f); matrix[0] = 1.0f; matrix[5] = 1.0f; matrix[10] = 1.0f; matrix[15] = 1.0f;
}
void initialize_particle_random_table(SferaEffectManager& manager) {
    if (manager.particle_random_table == nullptr) manager.particle_random_table = static_cast<std::uint16_t*>(std::calloc(1u, kParticleRandomValueCount * sizeof(std::uint16_t)));
    auto* values = manager.particle_random_table; if (values == nullptr) return;
    const auto seed = static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count()); std::srand(seed);
    for (std::size_t index = 0u; index < kParticleRandomValueCount; ++index) values[index] = static_cast<std::uint16_t>(std::rand());
    std::srand(static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count()));
}
template <class T, class Initializer> void append_fixed_effect(SferaEffectManager& manager, Initializer&& initialize) {
    auto* memory = static_cast<T*>(manager.allocate(sizeof(T))); if (memory == nullptr) return; auto* effect = std::construct_at(memory); initialize(*effect); manager.appendDefinition(effect);
}
}

SferaNatureManager* sfera_nature_manager() { return g_sfera_nature_runtime.manager; }

namespace {
void remove_nature_effect_handle(SferaActiveEffect*& handle) {
    if (handle && handle->owner_list) g_sfera_effect_manager.removeActiveEffect(*handle);
    handle = nullptr;
}
}

void SferaNatureManager::initialize() {
    rain_listener.change_tick = kInvalidHandle; lighting_listener.change_tick = kInvalidHandle; rain_effect = nullptr; rain_intensity = 0.5f; rain_scale = 0.0f; lighting_effect = nullptr; lighting_level = 0.5f; rain_effect_handle = lighting_effect_handle = nullptr; for (auto& handle : ambient_rain_handles) handle = nullptr;
    g_sfera_effect_manager.registerListener(kRainEffectId, rain_listener); g_sfera_effect_manager.registerListener(kLightingEffectId, lighting_listener);
}

void SferaNatureManager::shutdown() { g_sfera_effect_manager.unregisterListener(rain_listener); g_sfera_effect_manager.unregisterListener(lighting_listener); }

bool SferaNatureManager::attachRainEffect(IEffect& effect) {
    if (rain_effect != nullptr) return false;
    if (effect.effect_kind != IEffect::Kind::Rain) g_sfera_effect_manager.reportError("Unknown effect classID for rain.");
    if (effect.script_name == nullptr || std::strcmp(effect.script_name, "rain") != 0) g_sfera_effect_manager.reportError("Unknown effect manager for 'rain' not found.");
    rain_effect = &effect; rain_scale = 60.0f; static_cast<CRainEffect&>(effect).spawn_rate = rain_intensity * rain_scale; updateAmbientRainEffects(); return true;
}

void SferaNatureManager::detachRainEffect() { for (auto& handle : ambient_rain_handles) remove_nature_effect_handle(handle); rain_effect = nullptr; }

bool SferaNatureManager::attachLightingEffect(IEffect& effect) {
    if (lighting_effect != nullptr) return false;
    if (effect.effect_kind != IEffect::Kind::Scripted) g_sfera_effect_manager.reportError("Unknown effect classID for lighting.");
    lighting_effect = &effect;
    if (g_sfera_world_objects.controlled_object_handle != kInvalidHandle) { effect.cycle_length = static_cast<std::uint32_t>(std::trunc((1.0f - lighting_level) * 640.0f + 320.0f)); effect.lifetime_ticks = kInvalidHandle; }
    lighting_listener.change_tick = 1u; return true;
}

void SferaNatureManager::detachLightingEffect() { lighting_effect = nullptr; }

void SferaNatureManager::onLightingEffectChanged(IEffect& effect, SferaActiveEffect& item) {
    if (effect.effect_kind != IEffect::Kind::Scripted) return;
    auto& scripted = static_cast<CScriptedEffect&>(effect);
    if (scripted.light_definitions == nullptr || scripted.light_definition_count == 0u || scripted.particle_system_definitions == nullptr || scripted.particle_system_definition_count == 0u) return;
    SferaParticleSystemDefinition& particle = scripted.particle_system_definitions[0]; if (particle.render_slots == nullptr || particle.render_slot_count == 0u) return;
    const SferaEffectVec3F source = g_sfera_world_objects.objectPosition(item.source_handle); const SferaEffectVec3F emitter = particle.render_slots[0].position; SferaLightDefinition& light = scripted.light_definitions[0]; light.position = {emitter.x - source.x, emitter.y - source.y, emitter.z - source.z};
    const float distance = std::sqrt(light.position.x * light.position.x + light.position.y * light.position.y + light.position.z * light.position.z); g_sfera_effect_manager.createActiveEffect(distance < 15.0f ? kLightingSoundNearId : kLightingSoundFarId, item.source_handle);
}

void SferaNatureManager::startRain() { if (g_sfera_world_objects.controlled_object_handle != kInvalidHandle) rain_effect_handle = g_sfera_effect_manager.createActiveEffect(kRainEffectId, g_sfera_world_objects.controlled_object_handle); }
void SferaNatureManager::stopRain() { remove_nature_effect_handle(rain_effect_handle); for (auto& handle : ambient_rain_handles) remove_nature_effect_handle(handle); }
void SferaNatureManager::startLighting() { if (g_sfera_world_objects.controlled_object_handle != kInvalidHandle) lighting_effect_handle = g_sfera_effect_manager.createActiveEffect(kLightingEffectId, g_sfera_world_objects.controlled_object_handle); }
void SferaNatureManager::stopLighting() { remove_nature_effect_handle(lighting_effect_handle); }

void SferaNatureManager::setRainIntensity(float value) { if (rain_effect == nullptr || g_sfera_world_objects.controlled_object_handle == kInvalidHandle) return; rain_intensity = value; static_cast<CRainEffect*>(rain_effect)->spawn_rate = rain_intensity * rain_scale; updateAmbientRainEffects(); }
void SferaNatureManager::setLightingLevel(float value) { if (lighting_effect == nullptr || g_sfera_world_objects.controlled_object_handle == kInvalidHandle) return; lighting_level = value; lighting_effect->cycle_length = static_cast<std::uint32_t>(std::trunc((1.0f - lighting_level) * 640.0f + 320.0f)); lighting_effect->lifetime_ticks = kInvalidHandle; }

void SferaNatureManager::updateAmbientRainEffects() {
    if (g_sfera_world_objects.controlled_object_handle == kInvalidHandle) return;
    const std::uint32_t source = g_sfera_world_objects.controlled_object_handle;
    const auto ensure = [&](SferaActiveEffect*& handle) { if (!handle) handle = g_sfera_effect_manager.createActiveEffect(kAmbientRainSoundId, source); };
    if (rain_intensity == 0.0f) { remove_nature_effect_handle(ambient_rain_handles[0]); remove_nature_effect_handle(ambient_rain_handles[1]); remove_nature_effect_handle(ambient_rain_handles[2]); return; }
    ensure(ambient_rain_handles[0]);
    if (rain_intensity <= 0.4f) { remove_nature_effect_handle(ambient_rain_handles[1]); remove_nature_effect_handle(ambient_rain_handles[2]); return; }
    ensure(ambient_rain_handles[1]);
    if (rain_intensity <= 0.8f) { remove_nature_effect_handle(ambient_rain_handles[2]); return; }
    ensure(ambient_rain_handles[2]);
}

void sfera_initialize_nature_manager() { if (g_sfera_nature_runtime.manager != nullptr) return; auto* manager = static_cast<SferaNatureManager*>(g_sfera_effect_manager.allocate(sizeof(SferaNatureManager))); if (manager == nullptr) return; std::construct_at(manager); manager->initialize(); g_sfera_nature_runtime.manager = manager; }
void sfera_shutdown_nature_manager() { SferaNatureManager* manager = sfera_nature_manager(); if (manager == nullptr) return; manager->shutdown(); std::destroy_at(manager); g_sfera_effect_manager.free(manager); g_sfera_nature_runtime.manager = nullptr; }

void SferaEffectManager::registerEffectMeshFile(const char* filename) {
    if (filename == nullptr) return;
    std::ifstream stream;
    for (const std::string& path : g_sfera_files.candidatePaths(filename)) { stream.open(path, std::ios::binary); if (stream.is_open()) break; stream.clear(); }
    if (!stream.is_open()) return;
    stream.seekg(0, std::ios::end);
    const auto file_size = stream.tellg();
    if (file_size < 0) return;
    stream.seekg(0, std::ios::beg);
    std::uint64_t remaining = static_cast<std::uint64_t>(file_size);
    const auto read_exact = [&](void* output, std::size_t size) {
        if (size > remaining || std::cmp_greater(size, std::numeric_limits<std::streamsize>::max())) return false;
        stream.read(static_cast<char*>(output), static_cast<std::streamsize>(size));
        if (static_cast<std::size_t>(stream.gcount()) != size) return false;
        remaining -= size;
        return true;
    };
    const auto read_word = [&](std::uint32_t& value) { std::array<std::uint8_t, 4> bytes{}; if (!read_exact(bytes.data(), bytes.size())) return false; value = SferaBinary::readLittleEndian<std::uint32_t>(bytes.data()); return true; };
    const auto read_float = [&](float& value) { std::uint32_t bits = 0; if (!read_word(bits)) return false; value = std::bit_cast<float>(bits); return true; };
    std::array<char, 4> magic{};
    std::uint32_t version = 0, mesh_count = 0, reserved = 0;
    if (!read_exact(magic.data(), magic.size()) || !read_word(version) || magic != std::array<char, 4>{'S', 'S', 'M', '1'} || version != 1 || !read_word(mesh_count) || !read_word(reserved)) return;
    for (std::size_t mesh_index = 0; mesh_index < mesh_count; ++mesh_index) {
        auto mesh = std::make_unique<SferaEffectMeshResource>();
        std::uint32_t vertex_count = 0, skipped_vertex_count = 0, uv_count = 0, face_count = 0, ignored_count = 0;
        if (!read_exact(mesh->name, sizeof(mesh->name)) || !read_word(vertex_count) || !read_word(skipped_vertex_count) || !read_word(uv_count) || !read_word(face_count) || !read_word(ignored_count)) return;
        mesh->name[std::size(mesh->name) - 1] = '\0';
        const auto payload_size = std::uint64_t{vertex_count} * 16 + std::uint64_t{skipped_vertex_count} * 12 + std::uint64_t{uv_count} * 8 + std::uint64_t{face_count} * 32;
        if (payload_size > remaining || vertex_count > mesh->vertices.max_size() || uv_count > mesh->uv.max_size() || face_count > mesh->face_vertices.max_size()) return;
        mesh->vertices.resize(vertex_count); mesh->colors.resize(vertex_count); mesh->transformed_vertices.resize(vertex_count); mesh->transformed_colors.resize(vertex_count);
        mesh->uv.resize(uv_count); mesh->translated_uv.resize(uv_count); mesh->face_vertices.resize(face_count); mesh->face_uv.resize(face_count);
        for (auto& vertex : mesh->vertices) if (!read_float(vertex.x) || !read_float(vertex.y) || !read_float(vertex.z)) return;
        const auto skipped_bytes = std::uint64_t{skipped_vertex_count} * 12;
        stream.seekg(static_cast<std::streamoff>(skipped_bytes), std::ios::cur);
        if (!stream) return;
        remaining -= skipped_bytes;
        const auto read_faces = [&](auto& faces, std::size_t limit) { for (auto& face : faces) for (auto& index : face) { std::uint32_t value = 0; if (!read_word(value) || value >= limit) return false; index = value; } return true; };
        if (!read_faces(mesh->face_vertices, mesh->vertices.size())) return;
        for (auto& color : mesh->colors) if (!read_exact(color.channels.data(), color.channels.size())) return;
        for (auto& uv : mesh->uv) for (auto& coordinate : uv) if (!read_float(coordinate)) return;
        if (!read_faces(mesh->face_uv, mesh->uv.size())) return;
        if (particle_resource_head == nullptr) particle_resource_head = mesh.release();
        else { auto* tail = particle_resource_head; while (tail->next != nullptr) tail = tail->next; mesh->previous = tail; tail->next = mesh.release(); }
    }
}

void SferaEffectManager::reportLoadProgress(std::uint32_t progress) {
    g_sfera_main_view_state_runtime.view_accumulator += progress;
    const std::int32_t work = std::max(static_cast<std::int32_t>(g_sfera_world_load_runtime.loading_work_total) - 80, 1);
    std::int32_t percent = static_cast<std::int32_t>(g_sfera_main_view_state_runtime.view_accumulator) * 100 / work;
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
    if (g_sfera_blood_effect_instance != nullptr) return;
    auto* runtime = static_cast<SferaBloodEffectRuntime*>(allocate(sizeof(SferaBloodEffectRuntime)));
    if (runtime == nullptr) return;
    std::construct_at(runtime); runtime->change_tick = 64u; runtime->texture_id = g_sfera_textures.find("fx_bspot");
    registerListener(kBloodEffectId, *runtime); g_sfera_blood_effect_instance = runtime;
}
void SferaEffectManager::shutdownBloodEffect() {
    if (g_sfera_blood_effect_instance == nullptr) return;
    auto* runtime = g_sfera_blood_effect_instance;
    unregisterListener(*runtime); std::destroy_at(runtime); free(runtime); g_sfera_blood_effect_instance = nullptr;
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
            auto* memory = static_cast<CScriptedEffect*>(g_sfera_effect_manager.allocate(sizeof(CScriptedEffect)));
            if (memory != nullptr) { auto* effect = std::construct_at(memory); effect->initializeScriptedState(); const std::string filename = path.string(); if (effect->loadScript(filename.c_str())) appendDefinition(effect); else effect->destroyEffect(true); }
            ++loaded_count; const std::uint32_t progress = total_count == 0u ? 30u : static_cast<std::uint32_t>((static_cast<std::uint64_t>(loaded_count) * 30u) / total_count); reportLoadProgress(progress);
        });
    };
    load_group("Effects"); load_group("Players");
}

void SferaEffectManager::destroyDefinitions() {
    for (IEffect* definition = effect_definition_head; definition != nullptr;) { IEffect* next = definition->next; definition->destroyEffect(true); definition = next; }
    effect_definition_head = nullptr;
    for (SferaEffectMeshResource* resource = particle_resource_head; resource != nullptr;) { SferaEffectMeshResource* next = resource->next; delete resource; resource = next; }
    particle_resource_head = nullptr; g_sfera_effect_manager.free(particle_random_table); particle_random_table = nullptr;
}

bool SferaEffectManager::initialize() {
    if (initialized != 0u) return true;
    if (deferred_lifecycle != 0u) deferred_lifecycle = 0u; else shutdown();
    initialize_particle_random_table(*this); loadDefinitions();
    render_order.reserve(kMaximumRenderSlots);
    initializeBloodEffect(); sfera_initialize_nature_manager();
    append_fixed_effect<CLightEffect>(*this, [](CLightEffect& effect) { effect.initializePreset(); effect.assignScriptName("light_source.eff"); });
    append_fixed_effect<CSpiralEffect>(*this, [](CSpiralEffect& effect) { effect.initializePreset(); effect.assignScriptName("spiral.effect0"); });
    append_fixed_effect<CMolEffect>(*this, [](CMolEffect& effect) { effect.initializePreset(); effect.assignScriptName("molniya.effect110"); });
    append_fixed_effect<CBladeEffect>(*this, [](CBladeEffect& effect) { effect.initializePreset(); effect.assignScriptName("blade"); });
    append_fixed_effect<CRainEffect>(*this, [](CRainEffect& effect) { effect.initializePreset(); effect.assignScriptName("rain"); });
    append_fixed_effect<CGazerLakeEffect>(*this, [](CGazerLakeEffect& effect) { effect.initializePreset(kLakeEffectIdNear, 5.0f, kFixedLakeFlags); effect.assignScriptName("gazer.lake"); });
    append_fixed_effect<CGazerLakeEffect>(*this, [](CGazerLakeEffect& effect) { effect.initializePreset(kLakeEffectIdMiddle, 10.0f, kFixedLakeFlags); effect.assignScriptName("gazer.lake"); });
    append_fixed_effect<CGazerLakeEffect>(*this, [](CGazerLakeEffect& effect) { effect.initializePreset(kLakeEffectIdFar, 15.0f, kFixedLakeFlags); effect.assignScriptName("gazer.lake"); });
    render_slot_count = 0u; initialized = 1u; return true;
}

void SferaEffectManager::shutdown() {
    if (initialized == 0u) return;
    shutdownBloodEffect(); sfera_shutdown_nature_manager();
    for (SferaActiveEffect* item = active_effects.first; item != nullptr;) { SferaActiveEffect* next = item->next; if (item->effect != nullptr) { item->effect->releaseEffect(); item->effect = nullptr; } if (item->resource != nullptr) { g_sfera_sound_runtime.destroyEffect(item->resource); item->resource = nullptr; } item = next; }
    active_effects = {}; active_effect_count = 0u; active_resource_count = 0u; g_sfera_effect_items.clear(); destroyDefinitions(); clearListeners();
    render_order.clear(); initialized = 0u;
}

SferaActiveEffect* SferaEffectManager::createActiveEffect(std::uint32_t effect_id, std::uint32_t source_handle) {
    if (source_handle == 0u) reportError("EffectManager::createActiveEffect: zero source handle");
    if (active_effect_count >= kMaximumActiveEffects) return nullptr;
    IEffect* created_effect = nullptr; CSoundEffect* resource = nullptr;
    if (effect_id >= kSoundEffectIdBase) { if (!g_sfera_sound_runtime.interfaceAvailable()) return nullptr; resource = g_sfera_sound_runtime.createEffect(effect_id); if (resource == nullptr) return nullptr; }
    else { IEffect* definition = findDefinition(effect_id); if (definition == nullptr) return nullptr; created_effect = definition->createEffectResources(); if (created_effect == nullptr) return nullptr; if (effects_enabled != 0u && created_effect->isEffectComplete()) { created_effect->releaseEffect(); return nullptr; } }
    if (g_sfera_effect_items.free_count == 0u && !g_sfera_effect_items.grow(sizeof(SferaActiveEffect))) { if (created_effect != nullptr) created_effect->releaseEffect(); if (resource != nullptr) g_sfera_sound_runtime.destroyEffect(resource); return nullptr; }
    auto* item = static_cast<SferaActiveEffect*>(g_sfera_effect_items.take());
    if (item == nullptr) { if (created_effect != nullptr) created_effect->releaseEffect(); if (resource != nullptr) g_sfera_sound_runtime.destroyEffect(resource); return nullptr; }
    *item = {};
    if (!g_sfera_world_objects.attachEffect(source_handle, *item)) { g_sfera_effect_items.put(item); if (created_effect != nullptr) created_effect->releaseEffect(); if (resource != nullptr) g_sfera_sound_runtime.destroyEffect(resource); return nullptr; }
    item->position_source = 0u; item->state_flags = kUninitializedEffectState; item->source_handle = source_handle; item->age_ticks = 0u; item->effect = created_effect; item->resource = resource; item->listener_key = effect_id; item->viewer_distance = viewerDistance(source_handle); item->position = g_sfera_world_objects.objectPosition(source_handle);
    if (created_effect != nullptr) created_effect->position = item->position;
    ++active_effect_count; if (resource != nullptr) ++active_resource_count; sfera_effect_list_append(active_effects, *item);
    if (created_effect != nullptr) if (IEffectListener* listener = findListener(effect_id); listener != nullptr) { created_effect->listener = listener; if (!listener->onEffectAttached(*created_effect, *item, item->viewer_distance)) { removeActiveEffect(*item); return nullptr; } }
    return item;
}

SferaActiveEffect* SferaEffectManager::createActiveEffect(const char* script_name, std::uint32_t source_handle) { IEffect* definition = findDefinition(script_name); return definition != nullptr && static_cast<std::int32_t>(definition->effect_id) > 0 ? createActiveEffect(definition->effect_id, source_handle) : nullptr; }

void SferaEffectManager::removeActiveEffect(SferaActiveEffect& item) {
    if (active_effect_count == 0u) return;
    if (item.effect != nullptr) { IEffectListener* listener = item.effect->listener != nullptr ? item.effect->listener : findListener(item.listener_key); if (listener != nullptr && !listener->onEffectDetached(*item.effect, item)) return; }
    g_sfera_mbc_runtime->forgetNativeResource(&item);
    if (g_sfera_network_runtime.pending_effect == &item) g_sfera_network_runtime.pending_effect = nullptr;
    if (item.position_source == 0u) g_sfera_world_objects.detachEffect(item.source_handle, item);
    if (item.effect != nullptr) { item.effect->releaseEffect(); item.effect = nullptr; }
    if (item.resource != nullptr) { g_sfera_sound_runtime.destroyEffect(item.resource); item.resource = nullptr; if (active_resource_count != 0u) --active_resource_count; }
    item.age_ticks = kInvalidHandle; item.listener_key = kInvalidHandle; if (active_effect_count != 0u) --active_effect_count; if (item.owner_list != nullptr) sfera_effect_list_remove(*item.owner_list, item); g_sfera_effect_items.put(&item);
}

bool SferaEffectManager::setEffectParameters(std::uint32_t source_handle, const SferaEffectParameter* parameters, std::size_t count) { SferaActiveEffect* item = g_sfera_world_objects.firstEffect(source_handle); if (item == nullptr || item->effect == nullptr) return false; item->effect->setParameter(parameters, count); return true; }

void SferaEffectManager::updateActiveEffect(SferaActiveEffect& item, std::uint16_t state_flags, float viewer_distance) {
    if (item.resource != nullptr && item.effect == nullptr) {
        if (!g_sfera_sound_runtime.interfaceAvailable()) { removeActiveEffect(item); return; }
        SferaEffectVec3F frame = item.position_source == 1u ? item.position : g_sfera_world_objects.objectPosition(item.source_handle);
        if (item.sound_started == 0u) { item.resource->start(&frame, item.resource->startTime() < viewer_distance); item.sound_started = 1u; } else item.resource->update(&frame, viewer_distance);
        if (item.resource->isComplete()) removeActiveEffect(item); return;
    }
    IEffect* effect = item.effect; if (effect == nullptr) { removeActiveEffect(item); return; }
    item.age_ticks += item.listener_key >= kBloodEffectId && item.listener_key <= kBloodEffectIdLast ? 1u : 2u;
    if (effect->lifetime_ticks != kInvalidHandle && item.age_ticks >= effect->lifetime_ticks) { removeActiveEffect(item); return; }
    if (effect->listener != nullptr && item.age_ticks == effect->listener->change_tick) effect->listener->onEffectChanged(item.age_ticks, *effect, item);
    if (item.listener_key == kBloodEffectId && effect->listener != nullptr) effect->listener->onEffectChanged(item.age_ticks, *effect, item);
    SferaEffectSpatialFrames spatial{}; SferaEffectWorldFrames world{};
    if (item.position_source == 1u) { for (auto& frame : spatial.frames) frame = item.position; for (auto& frame : world.frames) initialize_identity_frame(frame); }
    else g_sfera_world_objects.buildEffectFrames(item.source_handle, spatial, world);
    if (g_sfera_sound_runtime.interfaceAvailable()) effect->updateEffect({&spatial.frames[0], viewer_distance});
    const bool visible = state_flags == 0u;
    if (effect->activation_blocked == 0u && !effect->activateEffect(visible)) { if (effect->deactivated == 0u) effect->deactivateEffect(((state_flags >> 1u) & 1u) != 0u); effect->activation_blocked = 1u; return; }
    if (effect->range_min != -1.0f) { const float env = g_sfera_graphics_runtime.environment_factor; bool outside = false; if (effect->range_max < effect->range_min) outside = env > effect->range_min || env < effect->range_max; else outside = env > effect->range_min && env < effect->range_max; if (outside) { if (effect->deactivated == 0u) effect->deactivateEffect(false); return; } }
    if (effect->cycle_length != 0u && item.age_ticks >= effect->cycle_length) item.age_ticks %= effect->cycle_length;
    if ((state_flags & 2u) != 0u) { if (effect->resources_released != 0u) effect->renderEffect(); effect->queryEffectState({&spatial.frames[0], static_cast<float>(item.age_ticks)}); return; }
    if (effect->deactivated != 0u) effect->renderEffect(); effect->initializeEffect({&spatial.frames[0], item.position_source == 1u ? 1u : 5u, static_cast<float>(item.age_ticks), visible, world.frames});
}

void SferaEffectManager::updateActiveEffects() {
    const SferaEffectVec3F viewer = g_sfera_world_objects.referencePosition(); viewer_position = {viewer.x, viewer.y, viewer.z};
    if (flare_transition != FlareTransition::Idle) { int alpha = flare_alpha + (flare_transition == FlareTransition::FadeOut ? -kFlareAlphaStep : kFlareAlphaStep); if (alpha < 0) { alpha = 0; flare_transition = FlareTransition::Idle; } else if (alpha > kMaximumAlpha) { alpha = kMaximumAlpha; flare_transition = FlareTransition::Idle; } flare_alpha = alpha; }
    render_slot_count = 0u; bool refresh_visibility = false; if (++render_cycle == kVisibilityRefreshPeriod) { render_cycle = 0u; refresh_visibility = true; }
    const float visibility_distance = g_sfera_view_spatial_runtime.basis[0].z + 10.0f;
    for (SferaActiveEffect* item = active_effects.first; item != nullptr;) {
        SferaActiveEffect* next = item->next;
        if (refresh_visibility || item->state_flags == kUninitializedEffectState) {
            item->state_flags = 0u; const SferaEffectVec3F position = item->position_source == 0u ? g_sfera_world_objects.objectPosition(item->source_handle) : item->position; item->viewer_distance = viewerDistance(position); if (visibility_distance < item->viewer_distance) item->state_flags |= 1u;
            if (item->effect != nullptr && last_processed_generation != generation && (item->state_flags & 1u) == 0u && item->effect->spatial_gate_enabled != 0u) { if (!g_sfera_main_ui_state_runtime.effectVisible(*item->effect, position)) item->state_flags |= 2u; else item->state_flags &= static_cast<std::uint16_t>(~2u); }
        }
        bool call_update = true;
        if (item->effect != nullptr && item->effect->activation_blocked != 0u) { if (item->state_flags == 0u) item->effect->activation_blocked = 0u; else if ((item->state_flags & 1u) != 0u) { item->age_ticks += 2u; if (item->effect->lifetime_ticks != kInvalidHandle && item->age_ticks >= item->effect->lifetime_ticks) removeActiveEffect(*item); call_update = false; } }
        if (call_update && item->owner_list != nullptr) updateActiveEffect(*item, item->state_flags, item->viewer_distance);
        item = next;
    }
    g_sfera_server_wall.updateEffectRendering(); if (auto* blood = g_sfera_blood_effect_instance; blood != nullptr) blood->phase += 0.005f; sortRenderSlots(); last_processed_generation = generation;
}
