#include "semantic_static.h"
#include "import_bridge.h"
#include "runtime.h"

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

void SferaStringLookupRuntime::initialize() {
    if (initialized != 0u) return;
    initialized = 1u;
    std::uint32_t rolling_mix = 0u;
    for (std::uint32_t byte = 0u; byte < 256u; ++byte) {
        std::uint32_t value = byte;
        for (std::uint32_t bit = 0u; bit < 8u; ++bit) { const bool low_bit = (value & 1u) != 0u; value >>= 1u; rolling_mix >>= 1u; if (low_bit) { value ^= 0xEDB88320u; rolling_mix ^= 0xEDB88320u; } }
        hash_mix[byte] = static_cast<std::uint16_t>(rolling_mix);
        case_fold[byte] = static_cast<std::uint8_t>(byte);
    }
    for (std::uint32_t letter = static_cast<std::uint32_t>('A'); letter <= static_cast<std::uint32_t>('Z'); ++letter) case_fold[letter] = static_cast<std::uint8_t>(letter - static_cast<std::uint32_t>('A') + static_cast<std::uint32_t>('a'));
}

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
constexpr std::uint32_t kMaximumActiveEffects = 6000u;
constexpr std::uint32_t kMaximumRenderSlots = 10000u;
constexpr std::uint32_t kParticleRandomValueCount = 65536u;
constexpr std::uint32_t kVisibilityRefreshPeriod = 32u;
constexpr int kFlareAlphaStep = 35;
constexpr int kMaximumAlpha = 255;
constexpr float kDefaultLightRadius = 10.0f;
constexpr float kFullCircleRadians = 6.283185958862305f;
constexpr std::size_t kRenderIndexBufferBytes = 60000u;
constexpr std::size_t kRenderBatchBufferBytes = 32000u;
void initialize_identity_frame(float* matrix);
void buildEffectObjectOrientation(const SferaWorldObjectEffectRuntime* object, float* matrix) {
    if (object == nullptr) { initialize_identity_frame(matrix); return; }
    const auto& rotation = object->rotation;
    const float cx = std::cos(rotation.x), sx = std::sin(rotation.x), cy = std::cos(rotation.y), sy = std::sin(rotation.y), cz = std::cos(rotation.z), sz = std::sin(rotation.z);
    matrix[0] = cx * cz - sx * sy * sz; matrix[1] = -sz * cy; matrix[2] = -sx * cz - sy * cx * sz; matrix[3] = 0.0f;
    matrix[4] = sz * cx + cz * sy * sx; matrix[5] = cz * cy; matrix[6] = cz * sy * cx - sz * sx; matrix[7] = 0.0f;
    matrix[8] = sx * cy; matrix[9] = -sy; matrix[10] = cy * cx; matrix[11] = 0.0f; matrix[12] = 0.0f; matrix[13] = 0.0f; matrix[14] = 0.0f; matrix[15] = 1.0f;
}
struct SferaD3D9DeviceRuntime {
    void* interface_vtable;
    IDirect3DDevice9* device;
    D3DPRESENT_PARAMETERS present_parameters;
};
bool loadingControlIsRegistered(std::uint32_t control) {
    if (control == 0u || (g_sfera_control_reference_registry_guard & 1u) == 0u) return false;
    auto* sentinel = SferaAbi::pointer<SferaControlReferenceNodeRuntime>(g_sfera_control_reference_registry.sentinel);
    if (sentinel == nullptr) return false;
    auto* candidate = sentinel;
    auto* node = SferaAbi::pointer<SferaControlReferenceNodeRuntime>(sentinel->parent);
    while (node != nullptr && node->is_nil == 0u) {
        if (node->control >= control) { candidate = node; node = SferaAbi::pointer<SferaControlReferenceNodeRuntime>(node->left); }
        else node = SferaAbi::pointer<SferaControlReferenceNodeRuntime>(node->right);
    }
    return candidate != sentinel && candidate->control == control;
}
void updateLoadingProgressControl(std::uint32_t percent) {
    auto* load_screen = SferaAbi::pointer<SferaLoadScreenRuntime>(g_sfera_interface_core_runtime.load_screen);
    if (load_screen == nullptr) return;
    auto* node = SferaAbi::pointer<SferaLoadScreenControlNodeRuntime>(load_screen->child_sentinel);
    for (std::uint32_t depth = 0u; depth < 3u && node != nullptr; ++depth) node = SferaAbi::pointer<SferaLoadScreenControlNodeRuntime>(node->next);
    if (node == nullptr || !loadingControlIsRegistered(node->control)) return;
    auto* progress = SferaAbi::pointer<SphereUI::ProgressBar>(node->control);
    if (progress == nullptr) return;
    progress->setProgressValue(static_cast<std::int32_t>(std::min(percent, 100u)));
}
SferaD3D9DeviceRuntime* effectLoadDeviceRuntime() { return SferaAbi::pointer<SferaD3D9DeviceRuntime>(g_sfera_graphics_runtime.d3d9_device_runtime); }
bool beginEffectLoadScene(SferaD3D9DeviceRuntime& runtime) {
    if (runtime.device == nullptr) return false;
    const HRESULT state = runtime.device->TestCooperativeLevel();
    if (state == D3DERR_DEVICELOST) return false;
    if (state == D3DERR_DEVICENOTRESET && FAILED(runtime.device->Reset(&runtime.present_parameters))) return false;
    runtime.device->BeginScene(); return true;
}
void synchronizeEffectLoadQuery() {
    auto* query = SferaAbi::pointer<IDirect3DQuery9>(g_sfera_client_config_runtime.gpu_sync_query);
    if (query == nullptr || query->Issue(D3DISSUE_END) == D3DERR_DEVICELOST) return;
    while (query->GetData(nullptr, 0u, D3DGETDATA_FLUSH) == S_FALSE) ::Sleep(0u);
}
}

void* SferaEffectManager::allocate(std::size_t size) const { return size == 0u ? nullptr : std::calloc(1u, size); }
void SferaEffectManager::free(void* pointer) const { std::free(pointer); }
void SferaEffectManager::reportError(const char* message) const { if (message != nullptr) std::fprintf(stderr, "%s\n", message); }
SferaEffectRenderSlot* SferaEffectManager::acquireRenderSlot() {
    const std::uint32_t index = render_slot_count++;
    if (index >= render_slots.capacity || render_slots.data == 0u) return nullptr;
    return render_slots.element<SferaEffectRenderSlot>(index);
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

SferaWorldObjectEffectRuntime* SferaWorldObjectRuntime::effectObject(std::uint32_t handle) const {
    if (handle >= object_handles.capacity || object_handles.data == 0u) return nullptr;
    const auto* handles = object_handles.dataAs<const std::uint32_t>();
    return handles == nullptr ? nullptr : SferaAbi::pointer<SferaWorldObjectEffectRuntime>(handles[handle]);
}
SferaEffectVec3F SferaWorldObjectRuntime::referencePosition() const { return objectPosition(kReferenceObjectHandle); }
SferaEffectVec3F SferaWorldObjectRuntime::objectPosition(std::uint32_t handle) const {
    auto* object = effectObject(handle);
    if (object == nullptr) object = effectObject(kReferenceObjectHandle);
    return object == nullptr ? SferaEffectVec3F{} : object->position;
}
bool SferaWorldObjectRuntime::attachEffect(std::uint32_t handle, SferaActiveEffect& item) {
    auto* object = effectObject(handle);
    if (object == nullptr) return false;
    for (auto& attached_effect : object->attached_effects) if (attached_effect == kInvalidHandle) { attached_effect = SferaAbi::address(&item); return true; }
    return false;
}
void SferaWorldObjectRuntime::detachEffect(std::uint32_t handle, SferaActiveEffect& item) {
    auto* object = effectObject(handle);
    if (object == nullptr) return;
    const std::uint32_t address = SferaAbi::address(&item);
    for (auto& attached_effect : object->attached_effects) if (attached_effect == address) { attached_effect = kInvalidHandle; return; }
}
SferaActiveEffect* SferaWorldObjectRuntime::firstEffect(std::uint32_t handle) const {
    auto* object = effectObject(handle);
    if (object == nullptr) return nullptr;
    const std::uint32_t address = object->attached_effects[0];
    return address == 0u || address == kInvalidHandle ? nullptr : SferaAbi::pointer<SferaActiveEffect>(address);
}
bool SferaWorldObjectRuntime::buildEffectFrames(std::uint32_t handle, SferaEffectSpatialFrames& spatial_frames, SferaEffectWorldFrames& world_frames) const {
    spatial_frames = {}; world_frames = {};
    auto* object = effectObject(handle);
    spatial_frames.frames[0] = objectPosition(handle);
    if (object != nullptr && object->extended_pose_available != 0u) {
        spatial_frames.frames[1] = object->effect_frame_position_a; spatial_frames.frames[2] = object->effect_frame_position_b; spatial_frames.frames[4] = object->effect_frame_position_c;
        std::copy_n(object->effect_frame_transform_a, 16u, world_frames.frames[1]); std::copy_n(object->effect_frame_transform_b, 16u, world_frames.frames[2]); std::copy_n(object->effect_frame_transform_c, 16u, world_frames.frames[4]);
    } else {
        const SferaEffectVec3F attachment = object != nullptr ? object->position : referencePosition();
        spatial_frames.frames[1] = attachment; spatial_frames.frames[2] = attachment; spatial_frames.frames[4] = attachment;
        initialize_identity_frame(world_frames.frames[1]); initialize_identity_frame(world_frames.frames[2]); initialize_identity_frame(world_frames.frames[4]);
    }
    spatial_frames.frames[3] = {(spatial_frames.frames[1].x + spatial_frames.frames[2].x) * 0.5f, (spatial_frames.frames[1].y + spatial_frames.frames[2].y) * 0.5f, (spatial_frames.frames[1].z + spatial_frames.frames[2].z) * 0.5f};
    buildEffectObjectOrientation(object, world_frames.frames[0]);
    return true;
}

bool SferaMainUiStateRuntime::effectVisible(const IEffect& effect, const SferaEffectVec3F& position) const {
    const SferaEffectVec3F minimum{position.x + effect.bounds_min[0], position.y + effect.bounds_min[1], position.z + effect.bounds_min[2]};
    const SferaEffectVec3F maximum{position.x + effect.bounds_max[0], position.y + effect.bounds_max[1], position.z + effect.bounds_max[2]};
    for (const auto& plane : clip_planes) {
        bool all_outside = true;
        for (std::uint32_t corner = 0u; corner < 8u; ++corner) {
            const float x = (corner & 1u) != 0u ? maximum.x : minimum.x, y = (corner & 2u) != 0u ? maximum.y : minimum.y, z = (corner & 4u) != 0u ? maximum.z : minimum.z;
            if (x * plane[0] + y * plane[1] + z * plane[2] + plane[3] >= 0.0f) { all_outside = false; break; }
        }
        if (all_outside) return false;
    }
    return true;
}
void SferaServerWall::updateEffectRendering() {
    auto* records = SferaAbi::pointer<SferaServerWallEffectRecord>(effect_records);
    auto* frames = SferaAbi::pointer<const SferaServerWallTextureFrame>(texture_frames);
    if (records == nullptr || frames == nullptr || texture_frame_count == 0u) return;
    for (std::uint32_t index = 0u; index < 100u; ++index) {
        auto& record = records[index];
        if (record.remaining <= 0.0f) continue;
        if (g_sfera_effect_manager.render_slot_count + 1u >= kMaximumRenderSlots) break;
        record.remaining -= 1.0f;
        const float phase_ratio = record.duration != 0.0f ? record.remaining / record.duration : 0.0f;
        const std::uint32_t alpha = static_cast<std::uint32_t>(std::trunc((0.5f - 0.5f * std::cos(phase_ratio * kFullCircleRadians)) * 100.0f));
        SferaEffectRenderSlot* slot = g_sfera_effect_manager.acquireRenderSlot();
        if (slot == nullptr) break;
        slot->primitive_kind = 3u; slot->resource_id = static_cast<std::int32_t>(texture_id); slot->blend_mode = 255u;
        for (std::uint32_t vertex = 0u; vertex < 4u; ++vertex) {
            slot->position[vertex] = record.positions[vertex]; slot->color[0][vertex] = 255u; slot->color[1][vertex] = 255u; slot->color[2][vertex] = 255u; slot->color[3][vertex] = alpha;
        }
        record.animation_phase += 0.25f;
        const std::uint32_t frame = static_cast<std::uint32_t>(std::trunc(record.animation_phase)) % texture_frame_count;
        for (std::uint32_t vertex = 0u; vertex < 4u; ++vertex) { slot->uv[vertex][0] = frames[frame].uv[vertex + 1u][0]; slot->uv[vertex][1] = frames[frame].uv[vertex + 1u][1]; }
    }
}

void SferaLightRecord::update(const SferaEffectVec3F& new_position, const float* new_color, float new_radius) {
    position = new_position;
    std::copy_n(new_color, std::size(color), color);
    radius = new_radius == 0.0f ? kDefaultLightRadius : new_radius;
}
std::uint32_t* SferaLightRuntime::handleTable() const { return handles.dataAs<std::uint32_t>(); }
SferaLightRecord* SferaLightRuntime::record(std::int32_t handle) const {
    if (handle < 0 || static_cast<std::uint32_t>(handle) >= handles.capacity) return nullptr;
    auto* table = handleTable();
    return table == nullptr ? nullptr : SferaAbi::pointer<SferaLightRecord>(table[handle]);
}
std::int32_t SferaLightRuntime::create(const SferaEffectVec3F& position, const float* color, float radius) {
    auto* table = handleTable();
    if (table == nullptr || color == nullptr) return -1;
    std::uint32_t handle = 0u;
    while (handle < handles.capacity && table[handle] != 0u) ++handle;
    if (handle >= handles.capacity) return -1;
    auto* light = static_cast<SferaLightRecord*>(g_sfera_effect_manager.allocate(sizeof(SferaLightRecord)));
    if (light == nullptr) return -1;
    light->update(position, color, radius);
    table[handle] = SferaAbi::address(light);
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
    auto* table = handleTable();
    if (table != nullptr) table[handle] = 0u;
    if (g_sfera_recovered_static_runtime.client_state_02 != 0u) --g_sfera_recovered_static_runtime.client_state_02;
}

std::int32_t SferaTextureRegistryRuntime::findTexture(const char* name) const {
    if (name == nullptr || *name == '\0' || initialized == 0u) return 0;
    std::uint16_t hash = 0u;
    for (const char* cursor = name; *cursor != '\0'; ++cursor) {
        const auto byte = static_cast<unsigned char>(*cursor);
        hash = static_cast<std::uint16_t>((hash >> 1u) + hash_mix[byte]);
    }
    const auto* records = SferaAbi::pointer<const SferaTextureRegistryRecord>(g_sfera_texture_set_scalar_runtime.mode_01);
    if (records == nullptr) return 0;
    std::uint16_t index = hash_heads[hash];
    while (index != kTextureHashEnd) {
        const auto& record = records[index];
        if (SferaSimpleParser::equalsIgnoreCase(record.name, name)) return index;
        index = record.next_hash_index;
    }
    return 0;
}

IEffect* sfera_effect_definition(uint32_t address) { return SferaAbi::pointer<IEffect>(address); }
SferaActiveEffect* sfera_active_effect(uint32_t address) { return SferaAbi::pointer<SferaActiveEffect>(address); }

void SferaEffectManager::appendDefinition(IEffect* effect) {
    if (effect == nullptr) return;
    effect->next = nullptr;
    effect->previous = nullptr;
    if (effect_definition_head == 0u) { effect_definition_head = SferaAbi::address(effect); return; }
    IEffect* tail = sfera_effect_definition(effect_definition_head);
    while (tail->next != nullptr) tail = tail->next;
    tail->next = effect;
    effect->previous = tail;
}

IEffect* SferaEffectManager::findDefinition(uint32_t effect_id) const {
    IEffect* effect = sfera_effect_definition(effect_definition_head);
    while (effect != nullptr) { if (effect->effect_id == effect_id) return effect; effect = effect->next; }
    return nullptr;
}

IEffect* SferaEffectManager::findDefinition(const char* script_name) const {
    if (script_name == nullptr) return nullptr;
    IEffect* effect = sfera_effect_definition(effect_definition_head);
    while (effect != nullptr) { if (effect->script_name != nullptr && SferaSimpleParser::equalsIgnoreCase(script_name, effect->script_name)) return effect; effect = effect->next; }
    return nullptr;
}

int32_t SferaEffectManager::findDefinitionId(const char* script_name) const {
    const IEffect* effect = findDefinition(script_name);
    return effect != nullptr ? static_cast<int32_t>(effect->effect_id) : -1;
}

namespace {
struct SferaEffectListenerEntry { std::uint32_t effect_id; IEffectListener* listener; };
SferaEffectListenerEntry g_effect_listener_entries[16]{};
std::uint32_t g_effect_listener_count = 0u;
}

IEffectListener* SferaEffectManager::findListener(uint32_t effect_id) const {
    for (std::uint32_t index = 0u; index < g_effect_listener_count; ++index) if (g_effect_listener_entries[index].effect_id == effect_id) return g_effect_listener_entries[index].listener;
    return nullptr;
}

bool SferaEffectManager::registerListener(std::uint32_t effect_id, IEffectListener& listener) {
    for (std::uint32_t index = 0u; index < g_effect_listener_count; ++index) {
        if (g_effect_listener_entries[index].effect_id != effect_id) continue;
        if (g_effect_listener_entries[index].listener == &listener) return true;
        reportError("EM_RegisterEffectListener::Multiple listeners not implemented.");
        return false;
    }
    if (g_effect_listener_count >= std::size(g_effect_listener_entries)) return false;
    g_effect_listener_entries[g_effect_listener_count++] = {effect_id, &listener};
    effect_listeners.size = g_effect_listener_count;
    return true;
}

void SferaEffectManager::unregisterListener(IEffectListener& listener) {
    for (std::uint32_t index = 0u; index < g_effect_listener_count; ++index) {
        if (g_effect_listener_entries[index].listener != &listener) continue;
        for (std::uint32_t move = index + 1u; move < g_effect_listener_count; ++move) g_effect_listener_entries[move - 1u] = g_effect_listener_entries[move];
        --g_effect_listener_count; g_effect_listener_entries[g_effect_listener_count] = {}; effect_listeners.size = g_effect_listener_count; return;
    }
}

void SferaEffectManager::clearListeners() { for (auto& entry : g_effect_listener_entries) entry = {}; g_effect_listener_count = 0u; effect_listeners = {}; }

void sfera_effect_list_append(SferaIntrusiveListHeader& list, SferaActiveEffect& item) {
    const uint32_t item_address = SferaAbi::address(&item);
    item.next = nullptr;
    item.previous = sfera_active_effect(list.last);
    item.owner_list = &list;
    if (item.previous != nullptr) item.previous->next = &item; else list.first = item_address;
    list.last = item_address;
}

void sfera_effect_list_remove(SferaIntrusiveListHeader& list, SferaActiveEffect& item) {
    const uint32_t item_address = SferaAbi::address(&item);
    if (list.first == 0u || list.last == 0u) return;
    if (list.first == list.last) { list.first = 0u; list.last = 0u; }
    else if (item_address == list.first) { list.first = SferaAbi::address(item.next); if (item.next != nullptr) item.next->previous = nullptr; }
    else if (item_address == list.last) { list.last = SferaAbi::address(item.previous); if (item.previous != nullptr) item.previous->next = nullptr; }
    else { if (item.next != nullptr) item.next->previous = item.previous; if (item.previous != nullptr) item.previous->next = item.next; }
    item.next = nullptr; item.previous = nullptr; item.owner_list = nullptr;
}

bool SferaItemArray::grow(std::uint32_t item_size) {
    if (growth_count == 0u || item_size == 0u) return false;
    const std::uint32_t block_count = block_vector_begin == 0u ? 0u : (block_vector_end - block_vector_begin) / sizeof(std::uint32_t);
    auto* block = static_cast<std::byte*>(std::calloc(growth_count, item_size));
    if (block == nullptr) return false;
    auto* old_blocks = SferaAbi::pointer<std::uint32_t>(block_vector_begin);
    auto* new_blocks = static_cast<std::uint32_t*>(std::realloc(old_blocks, (block_count + 1u) * sizeof(std::uint32_t)));
    if (new_blocks == nullptr) { std::free(block); return false; }
    const std::uint32_t old_free_count = free_count;
    const std::uint32_t new_capacity = old_free_count + growth_count;
    auto* new_free = static_cast<std::uint32_t*>(std::calloc(new_capacity, sizeof(std::uint32_t)));
    if (new_free == nullptr) {
        if (new_blocks != old_blocks) { block_vector_begin = SferaAbi::address(new_blocks); block_vector_end = block_vector_begin + block_count * sizeof(std::uint32_t); block_vector_capacity_end = block_vector_end; }
        std::free(block); return false;
    }
    auto* old_free = SferaAbi::pointer<std::uint32_t>(free_items);
    if (old_free != nullptr && old_free_count != 0u) std::copy_n(old_free, old_free_count, new_free);
    for (std::uint32_t index = 0u; index < growth_count; ++index) new_free[old_free_count + index] = SferaAbi::address(block + static_cast<std::size_t>(index) * item_size);
    std::free(old_free); new_blocks[block_count] = SferaAbi::address(block); free_items = SferaAbi::address(new_free); free_count = new_capacity; block_vector_begin = SferaAbi::address(new_blocks); block_vector_end = block_vector_begin + (block_count + 1u) * sizeof(std::uint32_t); block_vector_capacity_end = block_vector_end; return true;
}

void* SferaItemArray::take() { if (free_count == 0u || free_items == 0u) return nullptr; return SferaAbi::pointer<void>(SferaAbi::pointer<std::uint32_t>(free_items)[--free_count]); }
void SferaItemArray::put(void* item) { if (item == nullptr || free_items == 0u) return; SferaAbi::pointer<std::uint32_t>(free_items)[free_count++] = SferaAbi::address(item); }
void SferaItemArray::clear() {
    auto* blocks = SferaAbi::pointer<std::uint32_t>(block_vector_begin);
    const std::uint32_t block_count = blocks == nullptr ? 0u : (block_vector_end - block_vector_begin) / sizeof(std::uint32_t);
    for (std::uint32_t index = 0u; index < block_count; ++index) std::free(SferaAbi::pointer<void>(blocks[index]));
    std::free(blocks); std::free(SferaAbi::pointer<void>(free_items));
    block_vector_begin = block_vector_end = block_vector_capacity_end = reserved = free_items = free_count = 0u;
}

namespace {
void initialize_identity_frame(float* matrix) {
    std::fill_n(matrix, 16u, 0.0f); matrix[0] = 1.0f; matrix[5] = 1.0f; matrix[10] = 1.0f; matrix[15] = 1.0f;
}
void initialize_particle_random_table(SferaEffectManager& manager) {
    if (manager.particle_random_table == 0u) manager.particle_random_table = SferaAbi::address(std::calloc(1u, static_cast<std::size_t>(kParticleRandomValueCount) * sizeof(std::uint16_t)));
    auto* values = SferaAbi::pointer<std::uint16_t>(manager.particle_random_table); if (values == nullptr) return;
    const auto seed = static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count()); std::srand(seed);
    for (std::uint32_t index = 0u; index < kParticleRandomValueCount; ++index) values[index] = static_cast<std::uint16_t>(std::rand());
    std::srand(static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count()));
}
template <class T, class Initializer> void append_fixed_effect(SferaEffectManager& manager, Initializer&& initialize) {
    auto* memory = static_cast<T*>(manager.allocate(sizeof(T))); if (memory == nullptr) return; auto* effect = std::construct_at(memory); initialize(*effect); manager.appendDefinition(effect);
}
}


SferaNatureManager* sfera_nature_manager() { return SferaAbi::pointer<SferaNatureManager>(g_sfera_nature_runtime.manager); }

namespace {
void remove_nature_effect_handle(std::uint32_t& handle) {
    if (handle == kInvalidHandle) return;
    if (SferaActiveEffect* item = sfera_active_effect(handle); item != nullptr && item->owner_list != nullptr) g_sfera_effect_manager.removeActiveEffect(*item);
    handle = kInvalidHandle;
}
}

void SferaNatureManager::initialize() {
    rain_listener.change_tick = kInvalidHandle; lighting_listener.change_tick = kInvalidHandle; rain_effect = nullptr; rain_intensity = 0.5f; rain_scale = 0.0f; lighting_effect = nullptr; lighting_level = 0.5f; rain_effect_handle = kInvalidHandle; lighting_effect_handle = kInvalidHandle; for (auto& handle : ambient_rain_handles) handle = kInvalidHandle;
    g_sfera_effect_manager.registerListener(kRainEffectId, rain_listener); g_sfera_effect_manager.registerListener(kLightingEffectId, lighting_listener);
}

void SferaNatureManager::shutdown() { g_sfera_effect_manager.unregisterListener(rain_listener); g_sfera_effect_manager.unregisterListener(lighting_listener); }

bool SferaNatureManager::attachRainEffect(IEffect& effect) {
    if (rain_effect != nullptr) return false;
    if (effect.effect_kind != 3u) g_sfera_effect_manager.reportError("Unknown effect classID for rain.");
    if (effect.script_name == nullptr || std::strcmp(effect.script_name, "rain") != 0) g_sfera_effect_manager.reportError("Unknown effect manager for 'rain' not found.");
    rain_effect = &effect; rain_scale = 60.0f; static_cast<CRainEffect&>(effect).spawn_rate = rain_intensity * rain_scale; updateAmbientRainEffects(); return true;
}

void SferaNatureManager::detachRainEffect() { for (auto& handle : ambient_rain_handles) remove_nature_effect_handle(handle); rain_effect = nullptr; }

bool SferaNatureManager::attachLightingEffect(IEffect& effect) {
    if (lighting_effect != nullptr) return false;
    if (effect.effect_kind != 1u) g_sfera_effect_manager.reportError("Unknown effect classID for lighting.");
    lighting_effect = &effect;
    if (g_sfera_world_objects.controlled_object_handle != kInvalidHandle) { effect.cycle_length = static_cast<std::uint32_t>(std::trunc((1.0f - lighting_level) * 640.0f + 320.0f)); effect.lifetime_ticks = kInvalidHandle; }
    lighting_listener.change_tick = 1u; return true;
}

void SferaNatureManager::detachLightingEffect() { lighting_effect = nullptr; }

void SferaNatureManager::onLightingEffectChanged(IEffect& effect, SferaActiveEffect& item) {
    if (effect.effect_kind != 1u) return;
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
    const auto ensure = [&](std::uint32_t& handle) { if (handle == kInvalidHandle) handle = g_sfera_effect_manager.createActiveEffect(kAmbientRainSoundId, source); };
    if (rain_intensity == 0.0f) { remove_nature_effect_handle(ambient_rain_handles[0]); remove_nature_effect_handle(ambient_rain_handles[1]); remove_nature_effect_handle(ambient_rain_handles[2]); return; }
    ensure(ambient_rain_handles[0]);
    if (rain_intensity <= 0.4f) { remove_nature_effect_handle(ambient_rain_handles[1]); remove_nature_effect_handle(ambient_rain_handles[2]); return; }
    ensure(ambient_rain_handles[1]);
    if (rain_intensity <= 0.8f) { remove_nature_effect_handle(ambient_rain_handles[2]); return; }
    ensure(ambient_rain_handles[2]);
}

void sfera_initialize_nature_manager() { if (g_sfera_nature_runtime.manager != 0u) return; auto* manager = static_cast<SferaNatureManager*>(g_sfera_effect_manager.allocate(sizeof(SferaNatureManager))); if (manager == nullptr) return; std::construct_at(manager); manager->initialize(); g_sfera_nature_runtime.manager = SferaAbi::address(manager); }
void sfera_shutdown_nature_manager() { SferaNatureManager* manager = sfera_nature_manager(); if (manager == nullptr) return; manager->shutdown(); std::destroy_at(manager); g_sfera_effect_manager.free(manager); g_sfera_nature_runtime.manager = 0u; }

void SferaEffectManager::registerEffectMeshFile(const char* filename) {
    if (filename == nullptr) return;
    std::ifstream stream(filename, std::ios::binary);
    if (!stream.is_open() && std::strchr(filename, '\\') == nullptr && g_sfera_file_runtime.search_paths.data != 0u) {
        const auto* paths = SferaAbi::pointer<const std::uint32_t>(g_sfera_file_runtime.search_paths.data);
        const std::uint32_t count = std::min(g_sfera_file_runtime.search_path_count, g_sfera_file_runtime.search_paths.capacity);
        for (std::uint32_t index = 0u; index < count && !stream.is_open(); ++index) {
            const char* prefix = SferaAbi::pointer<const char>(paths[index]);
            if (prefix == nullptr) continue;
            std::string path(prefix);
            if (!path.empty() && path.back() != '\\' && path.back() != '/') path.push_back('\\');
            path += filename;
            stream.clear();
            stream.open(path, std::ios::binary);
        }
    }
    if (!stream.is_open()) return;
    auto read_exact = [&](void* output, std::size_t size) {
        stream.read(static_cast<char*>(output), static_cast<std::streamsize>(size));
        return static_cast<std::size_t>(stream.gcount()) == size;
    };
    std::array<char, 4> magic{};
    std::uint32_t version = 0u;
    std::uint32_t mesh_count = 0u;
    std::uint32_t reserved = 0u;
    if (!read_exact(magic.data(), magic.size()) || !read_exact(&version, sizeof(version)) || magic != std::array<char, 4>{'S', 'S', 'M', '1'} || version != 1u || !read_exact(&mesh_count, sizeof(mesh_count)) || !read_exact(&reserved, sizeof(reserved))) return;
    for (std::uint32_t mesh_index = 0u; mesh_index < mesh_count; ++mesh_index) {
        auto* mesh = static_cast<SferaEffectMeshResource*>(allocate(sizeof(SferaEffectMeshResource)));
        if (mesh == nullptr) return;
        std::uint32_t skipped_vertex_count = 0u, ignored_count = 0u;
        bool ok = read_exact(mesh->name, sizeof(mesh->name)) && read_exact(&mesh->vertex_count, sizeof(mesh->vertex_count)) && read_exact(&skipped_vertex_count, sizeof(skipped_vertex_count)) && read_exact(&mesh->uv_count, sizeof(mesh->uv_count)) && read_exact(&mesh->face_count, sizeof(mesh->face_count)) && read_exact(&ignored_count, sizeof(ignored_count));
        if (ok && mesh->vertex_count != 0u) {
            mesh->vertices = static_cast<SferaEffectVec3F*>(allocate(static_cast<std::size_t>(mesh->vertex_count) * sizeof(SferaEffectVec3F)));
            mesh->colors = static_cast<SferaEffectColor32*>(allocate(static_cast<std::size_t>(mesh->vertex_count) * sizeof(SferaEffectColor32)));
            mesh->transformed_vertices = static_cast<SferaEffectVec3F*>(allocate(static_cast<std::size_t>(mesh->vertex_count) * sizeof(SferaEffectVec3F)));
            mesh->transformed_colors = static_cast<SferaEffectColor32*>(allocate(static_cast<std::size_t>(mesh->vertex_count) * sizeof(SferaEffectColor32)));
            ok = mesh->vertices != nullptr && mesh->colors != nullptr && mesh->transformed_vertices != nullptr && mesh->transformed_colors != nullptr;
        }
        if (ok && mesh->uv_count != 0u) {
            mesh->uv = static_cast<float(*)[2]>(allocate(static_cast<std::size_t>(mesh->uv_count) * sizeof(float[2])));
            mesh->translated_uv = static_cast<float(*)[2]>(allocate(static_cast<std::size_t>(mesh->uv_count) * sizeof(float[2])));
            ok = mesh->uv != nullptr && mesh->translated_uv != nullptr;
        }
        if (ok && mesh->face_count != 0u) {
            mesh->face_vertices = static_cast<std::uint32_t(*)[4]>(allocate(static_cast<std::size_t>(mesh->face_count) * sizeof(std::uint32_t[4])));
            mesh->face_uv = static_cast<std::uint32_t(*)[4]>(allocate(static_cast<std::size_t>(mesh->face_count) * sizeof(std::uint32_t[4])));
            ok = mesh->face_vertices != nullptr && mesh->face_uv != nullptr;
        }
        if (ok && mesh->vertex_count != 0u) ok = read_exact(mesh->vertices, static_cast<std::size_t>(mesh->vertex_count) * sizeof(SferaEffectVec3F));
        if (ok && skipped_vertex_count != 0u) {
            stream.seekg(static_cast<std::streamoff>(skipped_vertex_count) * static_cast<std::streamoff>(sizeof(SferaEffectVec3F)), std::ios::cur);
            ok = static_cast<bool>(stream);
        }
        if (ok && mesh->face_count != 0u) ok = read_exact(mesh->face_vertices, static_cast<std::size_t>(mesh->face_count) * sizeof(std::uint32_t[4]));
        if (ok && mesh->vertex_count != 0u) ok = read_exact(mesh->colors, static_cast<std::size_t>(mesh->vertex_count) * sizeof(SferaEffectColor32));
        if (ok && mesh->uv_count != 0u) ok = read_exact(mesh->uv, static_cast<std::size_t>(mesh->uv_count) * sizeof(float[2]));
        if (ok && mesh->face_count != 0u) ok = read_exact(mesh->face_uv, static_cast<std::size_t>(mesh->face_count) * sizeof(std::uint32_t[4]));
        if (!ok) {
            mesh->release();
            free(mesh);
            return;
        }
        mesh->previous = nullptr;
        mesh->next = nullptr;
        auto* head = SferaAbi::pointer<SferaEffectMeshResource>(particle_resource_head);
        if (head == nullptr) particle_resource_head = SferaAbi::address(mesh);
        else {
            auto* tail = head;
            while (tail->next != nullptr) tail = tail->next;
            tail->next = mesh;
            mesh->previous = tail;
        }
    }
}

void SferaEffectManager::reportLoadProgress(std::uint32_t progress) {
    g_sfera_main_view_state_runtime.view_accumulator += progress;
    const std::int32_t work = std::max(static_cast<std::int32_t>(g_sfera_world_load_runtime.loading_work_total) - 80, 1);
    std::int32_t percent = static_cast<std::int32_t>(g_sfera_main_view_state_runtime.view_accumulator) * 100 / work;
    percent = std::min(percent, 100);
    if (static_cast<std::uint32_t>(percent) == g_sfera_graphics_runtime.rebuild_percent) return;
    g_sfera_graphics_runtime.rebuild_percent = static_cast<std::uint32_t>(percent);
    auto* device_runtime = effectLoadDeviceRuntime();
    if (device_runtime == nullptr || !beginEffectLoadScene(*device_runtime)) return;
    g_sfera_world_render_runtime.scene_active = 1u;
    updateLoadingProgressControl(static_cast<std::uint32_t>(percent));
    device_runtime->device->EndScene();
    synchronizeEffectLoadQuery();
    g_sfera_world_render_runtime.scene_active = 0u;
    device_runtime->device->Present(nullptr, nullptr, nullptr, nullptr);
}

void SferaEffectManager::initializeBloodEffect() {
    if (g_sfera_blood_effect_instance != 0u) return;
    auto* runtime = static_cast<SferaBloodEffectRuntime*>(allocate(sizeof(SferaBloodEffectRuntime)));
    if (runtime == nullptr) return;
    std::construct_at(runtime); runtime->change_tick = 64u; runtime->texture_id = static_cast<std::uint32_t>(g_sfera_texture_registry_runtime.findTexture("fx_bspot"));
    registerListener(kBloodEffectId, *runtime); g_sfera_blood_effect_instance = SferaAbi::address(runtime);
}
void SferaEffectManager::shutdownBloodEffect() {
    if (g_sfera_blood_effect_instance == 0u) return;
    auto* runtime = SferaAbi::pointer<SferaBloodEffectRuntime>(g_sfera_blood_effect_instance);
    unregisterListener(*runtime); std::destroy_at(runtime); free(runtime); g_sfera_blood_effect_instance = 0u;
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
    for (IEffect* definition = sfera_effect_definition(effect_definition_head); definition != nullptr;) { IEffect* next = definition->next; definition->destroyEffect(true); definition = next; }
    effect_definition_head = 0u;
    for (SferaEffectMeshResource* resource = SferaAbi::pointer<SferaEffectMeshResource>(particle_resource_head); resource != nullptr;) { SferaEffectMeshResource* next = resource->next; resource->release(); free(resource); resource = next; }
    particle_resource_head = 0u; g_sfera_effect_manager.free(SferaAbi::pointer<void>(particle_random_table)); particle_random_table = 0u;
}

bool SferaEffectManager::initialize() {
    if (initialized != 0u) return true;
    if (deferred_lifecycle != 0u) deferred_lifecycle = 0u; else shutdown();
    initialize_particle_random_table(*this); loadDefinitions();
    render_sort_indices = SferaAbi::address(std::calloc(1u, static_cast<std::size_t>(kMaximumRenderSlots) * sizeof(std::uint16_t))); render_index_buffer = SferaAbi::address(std::calloc(1u, kRenderIndexBufferBytes)); render_batch_buffer = SferaAbi::address(std::calloc(1u, kRenderBatchBufferBytes));
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
    for (SferaActiveEffect* item = sfera_active_effect(active_effects.first); item != nullptr;) { SferaActiveEffect* next = item->next; if (item->effect != nullptr) { item->effect->releaseEffect(); item->effect = nullptr; } if (item->resource != nullptr) { g_sfera_sound_runtime.destroyEffect(item->resource); item->resource = nullptr; } item = next; }
    active_effects = {}; active_effect_count = 0u; active_resource_count = 0u; g_sfera_effect_items.clear(); destroyDefinitions(); clearListeners();
    std::free(SferaAbi::pointer<void>(render_sort_indices)); std::free(SferaAbi::pointer<void>(render_index_buffer)); std::free(SferaAbi::pointer<void>(render_batch_buffer)); render_sort_indices = render_index_buffer = render_batch_buffer = 0u; initialized = 0u;
}

std::uint32_t SferaEffectManager::createActiveEffect(std::uint32_t effect_id, std::uint32_t source_handle) {
    if (source_handle == 0u) reportError("EffectManager::createActiveEffect: zero source handle");
    if (active_effect_count >= kMaximumActiveEffects) return kInvalidHandle;
    IEffect* created_effect = nullptr; CSoundEffect* resource = nullptr;
    if (effect_id >= kSoundEffectIdBase) { if (!g_sfera_sound_runtime.interfaceAvailable()) return kInvalidHandle; resource = g_sfera_sound_runtime.createEffect(effect_id); if (resource == nullptr) return kInvalidHandle; }
    else { IEffect* definition = findDefinition(effect_id); if (definition == nullptr) return kInvalidHandle; created_effect = definition->createEffectResources(); if (created_effect == nullptr) return kInvalidHandle; if (effects_enabled != 0u && created_effect->isEffectComplete()) { created_effect->releaseEffect(); return kInvalidHandle; } }
    if (g_sfera_effect_items.free_count == 0u && !g_sfera_effect_items.grow(sizeof(SferaActiveEffect))) { if (created_effect != nullptr) created_effect->releaseEffect(); if (resource != nullptr) g_sfera_sound_runtime.destroyEffect(resource); return kInvalidHandle; }
    auto* item = static_cast<SferaActiveEffect*>(g_sfera_effect_items.take());
    if (item == nullptr) { if (created_effect != nullptr) created_effect->releaseEffect(); if (resource != nullptr) g_sfera_sound_runtime.destroyEffect(resource); return kInvalidHandle; }
    *item = {};
    if (!g_sfera_world_objects.attachEffect(source_handle, *item)) { g_sfera_effect_items.put(item); if (created_effect != nullptr) created_effect->releaseEffect(); if (resource != nullptr) g_sfera_sound_runtime.destroyEffect(resource); return kInvalidHandle; }
    item->position_source = 0u; item->state_flags = kUninitializedEffectState; item->source_handle = source_handle; item->age_ticks = 0u; item->effect = created_effect; item->resource = resource; item->listener_key = effect_id; item->viewer_distance = viewerDistance(source_handle); item->position = g_sfera_world_objects.objectPosition(source_handle);
    if (created_effect != nullptr) created_effect->position = item->position;
    ++active_effect_count; if (resource != nullptr) ++active_resource_count; sfera_effect_list_append(active_effects, *item);
    if (created_effect != nullptr) if (IEffectListener* listener = findListener(effect_id); listener != nullptr) { created_effect->listener = listener; if (!listener->onEffectAttached(*created_effect, *item, item->viewer_distance)) { removeActiveEffect(*item); return kInvalidHandle; } }
    return SferaAbi::address(item);
}

std::uint32_t SferaEffectManager::createActiveEffect(const char* script_name, std::uint32_t source_handle) { IEffect* definition = findDefinition(script_name); return definition != nullptr && static_cast<std::int32_t>(definition->effect_id) > 0 ? createActiveEffect(definition->effect_id, source_handle) : kInvalidHandle; }

void SferaEffectManager::removeActiveEffect(SferaActiveEffect& item) {
    if (active_effect_count == 0u) return;
    if (item.effect != nullptr) { IEffectListener* listener = item.effect->listener != nullptr ? item.effect->listener : findListener(item.listener_key); if (listener != nullptr && !listener->onEffectDetached(*item.effect, item)) return; }
    if (item.position_source == 0u) g_sfera_world_objects.detachEffect(item.source_handle, item);
    if (item.effect != nullptr) { item.effect->releaseEffect(); item.effect = nullptr; }
    if (item.resource != nullptr) { g_sfera_sound_runtime.destroyEffect(item.resource); item.resource = nullptr; if (active_resource_count != 0u) --active_resource_count; }
    item.age_ticks = kInvalidHandle; item.reserved_update_handler = 0u; item.listener_key = kInvalidHandle; if (active_effect_count != 0u) --active_effect_count; if (item.owner_list != nullptr) sfera_effect_list_remove(*item.owner_list, item); g_sfera_effect_items.put(&item);
}

bool SferaEffectManager::setEffectParameters(std::uint32_t source_handle, const SferaEffectParameter* parameters, std::uint32_t count) { SferaActiveEffect* item = g_sfera_world_objects.firstEffect(source_handle); if (item == nullptr || item->effect == nullptr) return false; item->effect->setParameter(parameters, count); return true; }

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
    if (effect->deactivated != 0u) effect->renderEffect(); effect->initializeEffect({&spatial.frames[0], item.position_source == 1u ? 1u : 5u, static_cast<float>(item.age_ticks), visible, &world.frames[0][0]});
}

void SferaEffectManager::sortRenderSlots() {
    if (render_slot_count == 0u || render_sort_indices == 0u || render_slots.data == 0u) return;
    auto* indices = SferaAbi::pointer<std::uint16_t>(render_sort_indices); auto* slots = render_slots.dataAs<SferaEffectRenderSlot>(); for (std::uint32_t index = 0u; index < render_slot_count; ++index) indices[index] = static_cast<std::uint16_t>(index);
    std::sort(indices, indices + render_slot_count, [&](std::uint16_t left, std::uint16_t right) { const auto& a = slots[left]; const auto& b = slots[right]; const auto af = a.primitive_kind & 1u; const auto bf = b.primitive_kind & 1u; return af != bf ? af < bf : a.resource_id < b.resource_id; });
}

void SferaEffectManager::updateActiveEffects() {
    const SferaEffectVec3F viewer = g_sfera_world_objects.referencePosition(); viewer_position = {viewer.x, viewer.y, viewer.z};
    if (flare_transition != 0u) { int alpha = static_cast<int>(flare_alpha) + (flare_transition == 1u ? -kFlareAlphaStep : kFlareAlphaStep); if (alpha < 0) { alpha = 0; flare_transition = 0u; } else if (alpha > kMaximumAlpha) { alpha = kMaximumAlpha; flare_transition = 0u; } flare_alpha = static_cast<std::uint32_t>(alpha); }
    render_slot_count = 0u; bool refresh_visibility = false; if (++render_cycle == kVisibilityRefreshPeriod) { render_cycle = 0u; refresh_visibility = true; }
    const float visibility_distance = g_sfera_view_spatial_runtime.basis[0].z.f32 + 10.0f;
    for (SferaActiveEffect* item = sfera_active_effect(active_effects.first); item != nullptr;) {
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
    g_sfera_server_wall.updateEffectRendering(); if (auto* blood = SferaAbi::pointer<SferaBloodEffectRuntime>(g_sfera_blood_effect_instance); blood != nullptr) blood->phase += 0.005f; sortRenderSlots(); last_processed_generation = generation;
}
