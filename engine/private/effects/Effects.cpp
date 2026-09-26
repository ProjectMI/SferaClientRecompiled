#include <windows.h>
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <d3d9.h>
#include <functional>
#include <limits>
#include <memory>
#include <new>
#include <optional>
#include <span>
#include <stdexcept>
#include <string_view>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

#include "camera/Camera.h"
#include "effects/Effect.h"
#include "effects/EffectRendering.h"
#include "effects/ParticleEffects.h"
#include "effects/ScriptedEffects.h"
#include "environment/Environment.h"
#include "graphics/d3d9/Device.h"
#include "lighting/LightRuntime.h"
#include "math/Color.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "render/SceneRenderer.h"
#include "render/TextureAccess.h"
#include "render/VertexFormats.h"
#include "scene/SceneAccess.h"
#include "spatial/SpatialIndex.h"
#include "text/Text.h"
#include "ui/Canvas.h"
#include "ui/Rendering.h"

bool SferaBloodEffectRuntime::bloodTriangleOverlaps(const SferaVec3F *triangle, const SferaVec3F &center, float radius)
{
    float min_x = triangle[0].x, min_y = triangle[0].y, min_z = triangle[0].z, max_x = min_x, max_y = min_y, max_z = min_z;
    for (std::size_t i = 1u; i < 3u; ++i)
    {
        min_x = std::min(min_x, triangle[i].x);
        min_y = std::min(min_y, triangle[i].y);
        min_z = std::min(min_z, triangle[i].z);
        max_x = std::max(max_x, triangle[i].x);
        max_y = std::max(max_y, triangle[i].y);
        max_z = std::max(max_z, triangle[i].z);
    }
    return max_x >= center.x - radius && min_x <= center.x + radius && max_z >= center.z - radius && min_z <= center.z + radius && max_y >= center.y - 1.8f && min_y <= center.y + 1.5f;
}

std::vector<SferaVec3F> SferaBloodEffectRuntime::collectBloodSceneTriangles(const SferaVec3F &center, float radius)
{
    const auto &points = g_sfera_world_spatial.shadowVertices();
    std::vector<SferaVec3F> selected;
    selected.reserve(std::min<std::size_t>(points.size(), 90));
    for (std::size_t offset = 0; offset + 2 < points.size() && selected.size() < 90; offset += 3)
    {
        const auto *triangle = points.data() + offset;
        if (!std::isfinite(triangle[0].x) || !std::isfinite(triangle[0].y) || !std::isfinite(triangle[0].z) || !SferaBloodEffectRuntime::bloodTriangleOverlaps(triangle, center, radius))
            continue;
        selected.insert(selected.end(), triangle, triangle + 3);
    }
    return selected;
}

void SferaBloodEffectRuntime::createBloodSpot(SferaBloodEffectRuntime &runtime, const SferaVec3F &origin, std::span<const SferaVec3F> points)
{
    if (runtime.active_count >= 30u || points.size() < 3)
        return;
    SferaBloodSpot *spot = nullptr;
    for (auto &candidate : runtime.spots)
        if (candidate.life == 0.0f)
        {
            spot = &candidate;
            break;
        }
    if (spot == nullptr)
        return;
    const auto triangle_count = std::min<std::size_t>(points.size() / 3, 30);
    spot->life = 1.0f;
    spot->vertex_count = triangle_count * 3u;
    const float angle = std::rand() * (1.0f / 32768.0f) * 6.2831853071795864769f;
    const float scale = std::rand() * (1.0f / 32768.0f) * 2.0f + 2.0f;
    const float cosine = std::cos(angle), sine = std::sin(angle);
    const float ux = scale * cosine, uz = scale * sine, vx = -scale * sine, vz = scale * cosine;
    for (std::size_t index = 0u; index < spot->vertex_count; ++index)
    {
        const auto &source = points[index];
        auto &target = spot->vertices[index];
        target.position = source;
        target.diffuse = 0u;
        target.specular = 0u;
        const float dx = source.x - origin.x, dz = source.z - origin.z;
        target.u = dx * ux + dz * uz + 0.5f;
        target.v = dx * vx + dz * vz + 0.5f;
    }
    ++runtime.active_count;
}

void SferaBloodEffectRuntime::render()
{
    if (active_count == 0u)
    {
        phase = 0.0f;
        return;
    }
    for (auto &spot : spots)
        if (spot.life != 0.0f)
        {
            const double precise_life = spot.life;
            spot.life = SferaNumeric::real32(precise_life - phase);
            if (spot.life < 0.0f)
            {
                spot.life = 0.0f;
                spot.vertex_count = 0u;
                --active_count;
            }
        }
    phase = 0.0f;
    const int brightness = EffectRendering::ambientBrightness() + 100;
    const auto red = (brightness * 155 / 255) & 255u;
    const auto other = (brightness * 20 / 255) & 255u;
    if (active_count == 0u)
        return;
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    SphereRenderSceneRenderer::bindTexture(texture_id);
    EffectRendering::identityWorld(device);
    EffectRendering::renderState(device, D3DRS_RANGEFOGENABLE, FALSE);
    EffectRendering::renderState(device, D3DRS_ZWRITEENABLE, FALSE);
    device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
    EffectRendering::samplerState(device, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
    EffectRendering::samplerState(device, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
    auto output = device.colored_vertices.lock(3000);
    std::size_t vertex_count = 0u;
    for (const auto &spot : spots)
        if (spot.life != 0.0f)
        {
            if (vertex_count + spot.vertex_count > 3000u)
            {
                vertex_count = 3000u;
                break;
            }
            const auto color = SferaColor::rgba(red, other, other, SferaNumeric::truncatedWord(spot.life * 255.0)).argb();
            for (std::size_t vertex = 0u; vertex < spot.vertex_count; ++vertex)
            {
                output[vertex_count] = spot.vertices[vertex];
                output[vertex_count].diffuse = color;
                output[vertex_count].specular = 0u;
                ++vertex_count;
            }
        }
    output.unlock();
    device.drawBuffer(output.buffer(), D3DPT_TRIANGLELIST, 0u, output.first(), vertex_count, nullptr, 0u, 0u, sizeof(SphereRenderPositionColorUvVertex));
    EffectRendering::renderState(device, D3DRS_RANGEFOGENABLE, TRUE);
    EffectRendering::renderState(device, D3DRS_ZWRITEENABLE, TRUE);
    EffectRendering::samplerState(device, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
}

void SferaBloodEffectRuntime::createSpots(const SferaVec3F &center, float radius, std::span<const SferaVec3F> origins)
{
    const auto points = collectBloodSceneTriangles(center, radius);
    for (const auto &origin : origins)
    {
        if (active_count >= 30u)
            break;
        createBloodSpot(*this, origin, points);
    }
}

void IEffect::initializeBaseState(IEffectKind kind)
{
    script_name.clear();
    effect_id = std::numeric_limits<std::uint32_t>::max();
    deactivated = false;
    resources_released = false;
    activation_blocked = false;
    cycle_length = 0u;
    lifetime_ticks = 0u;
    range_min = -1.0f;
    range_max = -1.0f;
    effect_kind = kind;
    listener = nullptr;
    spatial_gate_enabled = false;
    render_slot_budget = 0u;
}

void SferaEffectAlgorithms::build_y_up_billboard_axes(const SferaVec3F &view, float right_scale, float up_scale, SferaVec3F &right, SferaVec3F &up)
{
    right = {view.z, 0.0f, -view.x};
    float length = (right).length<float, float>();
    right = length <= 0.00001f ? SferaVec3F{1.0f, 0.0f, 0.0f} : ((right) * (1.0f / length));
    up = (right).cross<float>((view));
    length = (up).length<float, float>();
    up = length <= 0.00001f ? SferaVec3F{0.0f, 0.0f, 1.0f} : ((up) * (1.0f / length));
    right = ((right) * (right_scale));
    up = ((up) * (up_scale));
}

auto SferaEffectAlgorithms::sampleMeshColor(const std::vector<SferaEffectTrackKey> &keys, const std::uint16_t *random_values, std::size_t index, std::uint32_t random_offset, std::uint8_t *value)
{
    const auto &color = std::get<SferaEffectTrackKeyColor>(keys[index].value);
    for (std::size_t channel = 0u; channel < 4u; ++channel)
    {
        int component = color.minimum.channels[channel];
        if (keys[index].mode == SferaEffectTrackKeyMode::Random && random_values != nullptr)
        {
            const std::uint32_t random_value = random_values[(index + channel) % 256u] + random_offset;
            const float random = random_value * 1.5259021893143654e-05f;
            component += SferaNumeric::truncateInt(random * color.range.channels[channel]);
        }
        value[channel] = SferaNumeric::lowByte(SferaNumeric::word(std::min(component, 255)));
    }
}

void SferaEffectAlgorithms::evaluate_mesh_color(const SferaEffectTrack &track, float age, SferaColor &output, const std::uint16_t *random_values, std::uint32_t random_offset_0,
                                                std::uint32_t random_offset_1)
{
    if (track.keys.empty())
        return;
    const auto &keys = track.keys;

    const auto [index, factor] = track.interval(age, false);
    if (index + 1 == keys.size())
    {
        sampleMeshColor(keys, random_values, index, random_offset_0, output.channels.data());
        return;
    }
    std::uint8_t begin[4]{};
    std::uint8_t end[4]{};
    sampleMeshColor(keys, random_values, index, random_offset_0, begin);
    sampleMeshColor(keys, random_values, index + 1u, random_offset_1, end);
    const int factor_byte = SferaNumeric::truncateInt(factor * 255.0f);
    for (std::size_t channel = 0u; channel < 4u; ++channel)
    {
        const int delta = end[channel] - begin[channel];
        output.channels[channel] = SferaNumeric::lowByte(SferaNumeric::word(begin[channel] + ((delta * factor_byte) >> 8)));
    }
}

float SferaEffectAlgorithms::particle_random_unit(const std::uint16_t *values, std::size_t index, std::uint32_t offset)
{
    if (values == nullptr)
        return std::rand() * 3.0518509447574615e-05f;
    return (values[index % 256u] + offset) * 1.5259021893143654e-05f;
}

SferaVec3F SferaEffectAlgorithms::sample_random_vector_key(const SferaEffectTrackKey &key, const std::uint16_t *values, std::size_t key_index, std::uint32_t seed0, std::uint32_t seed1)
{
    const auto &value = std::get<SferaEffectTrackKeyVector>(key.value);
    SferaVec3F result = value.minimum;
    if (key.mode == SferaEffectTrackKeyMode::Fixed)
        return result;
    result.x += SferaEffectAlgorithms::particle_random_unit(values, key_index * 3u, seed0) * value.range.x;
    result.y += SferaEffectAlgorithms::particle_random_unit(values, key_index * 3u + 1u, seed1) * value.range.y;
    result.z += SferaEffectAlgorithms::particle_random_unit(values, key_index * 3u + 2u, seed0 + seed1) * value.range.z;
    return result;
}

void SferaEffectAlgorithms::evaluate_random_vector(const SferaEffectTrack *track, float age, SferaVec3F &output, const std::uint16_t *values, std::uint32_t seed0, std::uint32_t seed1)
{
    output = {};
    if (track == nullptr || track->keys.empty())
        return;
    const auto [index, factor] = track->interval(age, true);
    const auto begin = SferaEffectAlgorithms::sample_random_vector_key(track->keys[index], values, index, seed0, seed1);
    output = begin;
    if (index + 1 == track->keys.size())
        return;
    const auto finish = SferaEffectAlgorithms::sample_random_vector_key(track->keys[index + 1], values, index + 1, seed0, seed1);
    output = {begin.x + (finish.x - begin.x) * factor, begin.y + (finish.y - begin.y) * factor, begin.z + (finish.z - begin.z) * factor};
}

void SferaEffectAlgorithms::evaluate_particle_scalar(const SferaEffectTrack *track, float age, float &output, const std::uint16_t *values, std::uint32_t seed)
{
    if (track != nullptr)
        track->evaluateScalar(age, output, values == nullptr ? std::span<const std::uint16_t>{} : std::span<const std::uint16_t>{values, 256}, seed);
}

void SferaEffectAlgorithms::apply_particle_rotation(SferaMatrix4x4F &transform, std::uint32_t flags, const SferaVec3F &rotation)
{
    if ((flags & (1u << 0u)) != 0u)
        transform = SferaMatrix4x4F::fromXyzRotation(rotation);
    else if ((flags & (1u << 2u)) != 0u)
        transform = SferaMatrix4x4F::fromAxisRotation<float>(SferaMatrix4x4FAxis::y, rotation.y);
    else if ((flags & (1u << 3u)) != 0u)
        transform = SferaMatrix4x4F::fromAxisRotation<float>(SferaMatrix4x4FAxis::z, rotation.z);
    else if ((flags & (1u << 1u)) != 0u)
        transform = SferaMatrix4x4F::fromAxisRotation<float>(SferaMatrix4x4FAxis::x, rotation.x);
}

void SferaEffectAlgorithms::particle_generate(SferaParticleSystemInstance &system, std::size_t index)
{
    if (system.render_slots.empty() || index >= system.render_slots.size())
        return;
    auto &slot = system.render_slots[index];
    const auto *table = SferaEffectHost::current().renderState().particle_random_table.data();
    if (system.definition->lifetime_track != nullptr)
        slot.state.total_lifetime = system.lifetime;
    else
        slot.state.total_lifetime = system.lifetime + std::rand() * 3.0518509447574615e-05f * system.definition->lifetime_random_factor;
    slot.state.random_row = std::rand() % 254;
    slot.state.random_seed_0 = SferaNumeric::lowHalf(SferaNumeric::word(std::rand()));
    slot.state.random_seed_1 = SferaNumeric::lowHalf(SferaNumeric::word(std::rand()));
    const std::uint16_t *random_values = table == nullptr ? nullptr : table + (slot.state.random_row << 8u);
    if (slot.linked_particle_system != nullptr && (slot.linked_particle_system->definition->flags & (1u << 24u)) != 0u && !slot.linked_particle_system->render_slots.empty())
        for (std::size_t child = 0u; child < slot.linked_particle_system->render_slots.size(); ++child)
            slot.linked_particle_system->render_slots[child].state.remaining_lifetime = -1.0f;
    if (slot.settings->size_track != nullptr)
        SferaEffectAlgorithms::evaluate_particle_scalar(slot.settings->size_track, 0.0f, slot.state.size, random_values, slot.state.random_seed_0);
    if (slot.settings->color_track != nullptr)
        SferaEffectAlgorithms::evaluate_mesh_color(*slot.settings->color_track, 0.0f, slot.state.color, random_values, slot.state.random_seed_0, slot.state.random_seed_1);
    slot.state.remaining_lifetime = slot.state.total_lifetime;
    slot.state.position = {};
    slot.state.texture_frame = (system.definition->flags & (1u << 19u)) != 0u && system.definition->texture_frames.size() != 0u ? (std::rand() % system.definition->texture_frames.size()) : 0.0f;
    if (!std::in_range<std::int32_t>(index))
        throw std::length_error("Particle slot index exceeds 32-bit range");
    const std::int32_t slot_index = SferaNumeric::signedWord(SferaNumeric::lowWord(index));
    if (system.definition->random_seed > 0)
    {
        const std::int32_t seed_value = system.definition->random_seed + system.definition->random_factor * slot_index;
        std::srand(SferaNumeric::word(seed_value));
    }
    constexpr float pi = 3.1415929794311523f;
    constexpr float two_pi = 6.283185958862305f;
    const float signed_sample = (std::rand() - std::rand()) * 3.0518509447574615e-05f;
    switch (system.definition->shape)
    {
    case SferaParticleSystemDefinitionShape::Points:
        if (!system.definition->shape_points.empty())
            slot.state.position = system.definition->shape_points[system.definition->random_seed == 0 ? std::min(index, system.definition->shape_points.size() - 1u)
                                                                                                      : std::rand() % system.definition->shape_points.size()];
        break;
    case SferaParticleSystemDefinitionShape::Line:
    {
        const float length = (system.definition->direction).length<float, float>();
        const float scalar = system.definition->random_seed == 0 ? length / std::max(system.render_slots.size(), std::size_t{1}) * index - length * 0.5f : length * signed_sample * 0.5f;
        slot.state.position = {system.definition->direction.x * scalar, system.definition->direction.y * scalar, system.definition->direction.z * scalar};
        break;
    }
    case SferaParticleSystemDefinitionShape::Disk:
    {
        const float a = std::rand() * 3.0518509447574615e-05f * two_pi;
        const float p = signed_sample * pi * 0.5f;
        slot.state.position = {std::sin(a) * system.radius * std::cos(p), 0.0f, std::cos(a) * system.radius * std::cos(p)};
        break;
    }
    case SferaParticleSystemDefinitionShape::Sphere:
    {
        const float a = std::rand() * 3.0518509447574615e-05f * two_pi;
        const float p = signed_sample * pi * 0.5f;
        slot.state.position = {std::cos(a) * system.radius * std::cos(p), std::sin(p) * system.radius, std::sin(a) * system.radius * std::cos(p)};
        break;
    }
    case SferaParticleSystemDefinitionShape::Box:
        slot.state.position = {(std::rand() - std::rand()) * 3.0518509447574615e-05f * system.width * 0.5f, (std::rand() - std::rand()) * 3.0518509447574615e-05f * system.radius * 0.5f,
                               (std::rand() - std::rand()) * 3.0518509447574615e-05f * system.height * 0.5f};
        break;
    case SferaParticleSystemDefinitionShape::Cylinder:
    {
        const float a = std::rand() * 3.0518509447574615e-05f * two_pi;
        const float p = signed_sample * pi * 0.5f;
        slot.state.position = {std::sin(a) * system.radius * std::cos(p), (std::rand() - std::rand()) * 3.0518509447574615e-05f * system.height * 0.5f, std::cos(a) * system.radius * std::cos(p)};
        break;
    }
    case SferaParticleSystemDefinitionShape::Ring:
    {
        const float a = system.definition->random_seed == 0 ? two_pi * (system.definition->random_factor + slot_index) / std::max(system.render_slots.size(), std::size_t{1})
                                                            : std::rand() * 3.0518509447574615e-05f * two_pi;
        slot.state.position = {std::sin(a) * system.radius, std::rand() * 3.0518509447574615e-05f * system.height, std::cos(a) * system.radius};
        break;
    }
    case SferaParticleSystemDefinitionShape::Annulus:
    {
        const float a = std::rand() * 3.0518509447574615e-05f * two_pi;
        const float p = signed_sample * pi * 0.5f;
        const float radial = system.width + system.radius * std::cos(p);
        slot.state.position = {std::sin(a) * radial, 0.0f, std::cos(a) * radial};
        break;
    }
    }
    if ((system.definition->flags & (1u << 10u)) != 0u)
    {
        if ((system.definition->flags & (1u << 5u)) != 0u)
        {
            slot.state.position.x += system.current_position.x;
            slot.state.position.y += system.current_position.y;
            slot.state.position.z += system.current_position.z;
        }
        else
            slot.state.position = (system.transform).transformPoint<float>(slot.state.position);
    }
    slot.state.position.x += system.emitter_position.x;
    slot.state.position.y += system.emitter_position.y;
    slot.state.position.z += system.emitter_position.z;
    slot.state.spawn_position = slot.state.position;
    if (system.definition->random_seed > 0)
    {
        const std::uint64_t time_seed = std::time(nullptr);
        std::srand(time_seed & UINT32_MAX);
    }
}

SferaEffectHost *SferaEffectHost::instance = nullptr;
SferaEffectHost &SferaEffectHost::current()
{
    if (instance == nullptr)
        throw std::logic_error("Effect host is not bound");
    return *instance;
}

bool SferaEffectMeshDefinition::meshResourceNamed(std::string_view name, const std::shared_ptr<const SferaEffectMeshResource> &resource)
{
    return SferaText::asciiEqual(resource->name, name);
}

std::size_t SferaEffectMeshDefinition::renderSlotCount() const
{
    return mesh_resource == nullptr ? 0u : mesh_resource->faces.size();
}

SferaEffectMeshInstance::SferaEffectMeshInstance(std::shared_ptr<const SferaEffectMeshDefinition> source) : definition(std::move(source))
{
    if (definition == nullptr)
        throw std::invalid_argument("Missing mesh definition");
    reset();
}

void SferaEffectMeshInstance::reset()
{
    u_offset = v_offset = 0.0f;
    color = definition->color;
    runtime_position = {};
    transform = SferaMatrix4x4F::identity();
    random_row = std::rand() % 255;
    random_offset = std::rand();
    random_state = std::rand();
    texture_id = definition->texture_name.empty() ? -1 : SferaTextureAccess::find(definition->texture_name);
}

void SferaEffectMeshInstance::update(const SferaVec3F *spatial_frame, const SferaMatrix4x4F *world_frame, float age)
{
    if (definition->mesh_resource == nullptr || spatial_frame == nullptr)
        return;
    runtime_position = *spatial_frame;
    if ((definition->flags & (1u << 5u)) != 0u)
    {
        if (definition->position_track != nullptr)
        {
            SferaVec3F offset{};
            definition->position_track->evaluateVector(age, offset);
            runtime_position.x += offset.x;
            runtime_position.y += offset.y;
            runtime_position.z += offset.z;
        }
        if ((definition->flags & (1u << 27u)) != 0u && world_frame != nullptr)
            transform = *world_frame;
    }
    else
    {
        transform = SferaMatrix4x4F::identity();
        bool rotated = false;
        if (definition->rotation_track != nullptr)
        {
            SferaVec3F rotation{};
            definition->rotation_track->evaluateVector(age, rotation);
            SferaEffectAlgorithms::apply_particle_rotation(transform, definition->flags, rotation);
            rotated = (definition->flags & 15u) != 0u;
        }
        if (definition->scale_track != nullptr)
        {
            SferaVec3F scale{};
            definition->scale_track->evaluateVector(age, scale);
            if (rotated)
            {
                transform.scaleAxes(scale);
            }
            else
            {
                transform.m[0][0] = scale.x;
                transform.m[1][1] = scale.y;
                transform.m[2][2] = scale.z;
            }
        }
        transform.m[0][3] = runtime_position.x;
        transform.m[1][3] = runtime_position.y;
        transform.m[2][3] = runtime_position.z;
        if (definition->position_track != nullptr)
        {
            SferaVec3F offset{};
            definition->position_track->evaluateVector(age, offset);
            transform.m[0][3] += offset.x;
            transform.m[1][3] += offset.y;
            transform.m[2][3] += offset.z;
        }
        if ((definition->flags & (1u << 27u)) != 0u && world_frame != nullptr)
        {
            SferaMatrix4x4F combined{};
            combined = (transform).multiplied<float>(*world_frame);
            transform = combined;
        }
    }
    const auto *random_values = SferaEffectHost::current().renderState().particle_random_table.data() + random_row * 256u;
    if ((definition->flags & (1u << 14u)) != 0u)
    {
        if (definition->ucoord_track != nullptr)
            definition->ucoord_track->evaluateScalar(age, u_offset, {random_values, 256}, random_offset);
        if (definition->vcoord_track != nullptr)
            definition->vcoord_track->evaluateScalar(age, v_offset, {random_values, 256}, random_offset);
    }
    if ((definition->flags & (1u << 15u)) != 0u && definition->color_track != nullptr)
        SferaEffectAlgorithms::evaluate_mesh_color(*definition->color_track, age, color, random_values, random_offset, random_state);
}

void SferaEffectMeshInstance::commit()
{
    if (definition->mesh_resource == nullptr || definition->texture_name.empty())
        return;
    if (SferaEffectHost::current().renderState().render_slot_count > SferaEffectHost::current().renderState().render_slots.size() ||
        definition->mesh_resource->faces.size() > SferaEffectHost::current().renderState().render_slots.size() - SferaEffectHost::current().renderState().render_slot_count ||
        SferaEffectHost::current().renderState().render_slots.empty())
        return;
    transformed_vertices.resize(definition->mesh_resource->vertices.size());
    transformed_colors.resize(definition->mesh_resource->colors.size());
    translated_uv.resize(definition->mesh_resource->uv.size());
    for (std::size_t index = 0u; index < definition->mesh_resource->vertices.size(); ++index)
        transformed_vertices[index] = (definition->flags & (1u << 5u)) != 0u
                                          ? SferaVec3F{definition->mesh_resource->vertices[index].x + runtime_position.x, definition->mesh_resource->vertices[index].y + runtime_position.y,
                                                       definition->mesh_resource->vertices[index].z + runtime_position.z}
                                          : (transform).transformPoint<float>(definition->mesh_resource->vertices[index]);
    const auto *uv_source = definition->mesh_resource->uv.data();
    if ((definition->flags & (1u << 14u)) != 0u && !translated_uv.empty())
    {
        for (std::size_t index = 0u; index < definition->mesh_resource->uv.size(); ++index)
        {
            translated_uv[index][0] = definition->mesh_resource->uv[index][0] + u_offset;
            translated_uv[index][1] = definition->mesh_resource->uv[index][1] + v_offset;
        }
        uv_source = translated_uv.data();
    }
    const SferaColor *color_source = definition->mesh_resource->colors.data();
    if ((definition->flags & (1u << 15u)) != 0u && !transformed_colors.empty())
    {
        for (std::size_t index = 0u; index < definition->mesh_resource->vertices.size(); ++index)
        {
            for (std::size_t channel = 0u; channel < 4u; ++channel)
                transformed_colors[index].channels[channel] = (definition->mesh_resource->colors[index].channels[channel] * color.channels[channel]) >> 8u;
        }
        color_source = transformed_colors.data();
    }
    auto *slots = SferaEffectHost::current().renderState().render_slots.data();
    for (std::size_t face = 0u; face < definition->mesh_resource->faces.size(); ++face)
    {
        auto &slot = slots[SferaEffectHost::current().renderState().render_slot_count++];
        slot.resource_id = texture_id;
        slot.self_illumination = definition->self_illumination;
        slot.additive = definition->additive;
        slot.custom_uv = definition->custom_uv;
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex)
        {
            const auto vertex_index = definition->mesh_resource->faces[face].vertices[vertex];
            const auto uv_index = definition->mesh_resource->faces[face].uv[vertex];
            slot.position[vertex] = transformed_vertices[vertex_index];
            slot.uv[vertex][0] = uv_source[uv_index][0];
            slot.uv[vertex][1] = uv_source[uv_index][1];
            for (std::size_t channel = 0u; channel < 4u; ++channel)
                slot.color[channel][vertex] = color_source[vertex_index].channels[channel];
        }
    }
}

int SferaEffectRenderState::visibilityAlpha(const SferaVec3F &position)
{
    const auto &matrix = g_sfera_camera.frame_transform;
    const SferaVec3F origin{matrix.m[0][3], matrix.m[1][3], matrix.m[2][3]};
    const SferaVec3F direction{matrix.m[0][2], matrix.m[1][2], matrix.m[2][2]};
    const float distance = SferaNumeric::real32((position - origin).dot(direction));
    const auto &limits = SphereRenderSceneRenderer::environment.fogParameters;
    if (distance < limits.y)
        return 255;
    if (distance > limits.z)
        return 0;
    const double far_limit = limits.z;
    return SferaNumeric::truncateInt((far_limit - distance) * 255.0 / (far_limit - limits.y));
}

void SferaEffectRenderState::sortRenderSlots()
{
    if (render_slots.empty())
    {
        render_order.clear();
        return;
    }
    if (render_slot_count > render_slots.size())
        throw std::out_of_range("Effect render slot count");
    render_order.resize(render_slot_count);
    for (std::size_t index = 0; index < render_slot_count; ++index)
        render_order[index] = index;
    const auto *slots = render_slots.data();
    std::stable_sort(render_order.begin(), render_order.end(), std::bind(&SferaEffectRenderState::compareRenderSlots, slots, std::placeholders::_1, std::placeholders::_2));
}

void SferaEffectRenderState::renderParticles(SferaEffectRenderStatistics &diagnostics)
{
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    if (diagnostics.enabled)
        ++diagnostics.render_calls;
    if (render_slot_count == 0u)
        return;
    auto *slots = render_slots.data();
    const int ambient = EffectRendering::ambientBrightness() + 20;
    std::vector<std::uint16_t> indices;
    std::vector<EffectRenderingParticleBatch> batches;
    indices.reserve(30000u);
    batches.reserve(render_slot_count);
    auto vertices = device.colored_vertices.lock(std::max(device.colored_vertices.capacity(), std::size_t{8}));
    std::size_t vertex_count = 0u;
    int bound_texture = -1;
    std::optional<bool> active_blend;
    EffectRendering::identityWorld(device);
    EffectRendering::renderState(device, D3DRS_ZWRITEENABLE, FALSE);

    for (std::size_t slot_index = 0u; slot_index < render_slot_count; ++slot_index)
    {
        auto &slot = slots[render_order[slot_index]];
        const auto additive = slot.additive;
        if (batches.empty() || batches.back().texture != slot.resource_id || batches.back().additive != additive)
            batches.push_back({indices.size(), 0u, additive, slot.resource_id});
        const auto brightness = std::clamp(std::int64_t{slot.self_illumination} + ambient, std::int64_t{std::numeric_limits<int>::min()}, std::int64_t{255});
        if (!slot.custom_uv)
        {
            slot.uv[0][0] = 0.0f;
            slot.uv[0][1] = 0.0f;
            slot.uv[1][0] = 1.0f;
            slot.uv[1][1] = 0.0f;
            slot.uv[2][0] = 1.0f;
            slot.uv[2][1] = 1.0f;
            slot.uv[3][0] = 0.0f;
            slot.uv[3][1] = 1.0f;
        }
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex)
        {
            auto &output = vertices[vertex_count + vertex];
            output.position = slot.position[vertex];
            output.diffuse = SferaColor::rgba(scaleParticleColor(slot, vertex, 0u, brightness), scaleParticleColor(slot, vertex, 1u, brightness), scaleParticleColor(slot, vertex, 2u, brightness),
                                              scaleParticleColor(slot, vertex, 3u, SferaEffectRenderState::visibilityAlpha(output.position)))
                                 .argb();
            if (diagnostics.enabled && (output.diffuse >> 24u) != 0u)
                ++diagnostics.alpha_vertices;
            output.specular = 0u;
            output.u = slot.uv[vertex][0];
            output.v = slot.uv[vertex][1];
        }
        for (auto corner : {0u, 1u, 2u, 2u, 3u, 0u})
            indices.push_back(SferaNumeric::lowHalf(SferaNumeric::lowWord(vertex_count + corner)));
        batches.back().index_count += 6u;
        vertex_count += 4u;
        if (vertex_count > vertices.size() - 8 || indices.size() > 29994u)
        {
            flushParticles(diagnostics, device, vertices, batches, indices, active_blend, bound_texture, vertex_count);
            vertices = device.colored_vertices.lock(device.colored_vertices.capacity());
        }
    }
    flushParticles(diagnostics, device, vertices, batches, indices, active_blend, bound_texture, vertex_count);
    device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    EffectRendering::renderState(device, D3DRS_ZWRITEENABLE, TRUE);
}

bool SferaEffectRenderState::compareRenderSlots(const SferaEffectRenderSlot *slots, std::size_t left, std::size_t right)
{
    const auto &a = slots[left];
    const auto &b = slots[right];
    return a.additive != b.additive ? a.additive < b.additive : a.resource_id < b.resource_id;
}

void SferaEffectRenderState::flushParticles(SferaEffectRenderStatistics &diagnostics, CD3D9Device &device, DynamicStreamMapping<SphereRenderPositionColorUvVertex> &vertices,
                                            std::vector<EffectRenderingParticleBatch> &batches, std::vector<std::uint16_t> &indices, std::optional<bool> &active_blend, int &bound_texture,
                                            std::size_t &vertex_count)
{
    vertices.unlock();
    for (const auto &batch : batches)
    {
        if (active_blend != batch.additive)
        {
            active_blend = batch.additive;
            device.setAlphaBlending(D3DBLEND_SRCALPHA, !batch.additive ? D3DBLEND_INVSRCALPHA : D3DBLEND_ONE);
        }
        if (bound_texture != batch.texture)
        {
            bound_texture = batch.texture;
            if (bound_texture != -1)
                SphereRenderSceneRenderer::bindTexture(bound_texture);
        }
        if (batch.index_count == 0u)
            continue;
        auto output = device.indices_secondary.lock(batch.index_count);
        std::copy_n(indices.data() + batch.first_index, batch.index_count, output.data());
        output.unlock();
        device.drawBuffer(vertices.buffer(), D3DPT_TRIANGLELIST, 6u, vertices.first(), vertex_count, output.buffer(), batch.index_count, output.first(), sizeof(SphereRenderPositionColorUvVertex));
        if (diagnostics.enabled)
            diagnostics.submitted_quads += batch.index_count / 6u;
    }
    vertex_count = 0u;
    indices.clear();
    batches.clear();
}

std::uint32_t SferaEffectRenderState::scaleParticleColor(const SferaEffectRenderSlot &slot, std::size_t vertex, std::size_t channel, std::int64_t factor)
{
    return SferaNumeric::lowWord(slot.color[channel][vertex] * factor / 255);
}

void SferaEffectRenderState::finalizeBillboard(SferaEffectRenderSlot &slot, const SferaVec3F &position, float size) const
{
    const SferaVec3F viewer{viewer_position.x, viewer_position.y, viewer_position.z};
    const SferaVec3F view{position.x - viewer.x, position.y - viewer.y, position.z - viewer.z};
    SferaVec3F right{view.y, -view.x, 0.0f};
    float length = std::sqrt(right.x * right.x + right.y * right.y + right.z * right.z);
    if (length > 0.00001f)
    {
        right.x /= length;
        right.y /= length;
        right.z /= length;
    }
    SferaVec3F up{right.y * view.z - right.z * view.y, right.z * view.x - right.x * view.z, right.x * view.y - right.y * view.x};
    length = std::sqrt(up.x * up.x + up.y * up.y + up.z * up.z);
    if (length > 0.00001f)
    {
        up.x /= length;
        up.y /= length;
        up.z /= length;
    }
    right.x *= size;
    right.y *= size;
    right.z *= size;
    up.x *= size;
    up.y *= size;
    up.z *= size;
    slot.position[0] = {position.x - right.x - up.x, position.y - right.y - up.y, position.z - right.z - up.z};
    slot.position[1] = {position.x - right.x + up.x, position.y - right.y + up.y, position.z - right.z + up.z};
    slot.position[2] = {position.x + right.x + up.x, position.y + right.y + up.y, position.z + right.z + up.z};
    slot.position[3] = {position.x + right.x - up.x, position.y + right.y - up.y, position.z + right.z - up.z};
}

float SferaEffectRenderState::viewerDistance(const SferaVec3F &position) const
{
    const float dx = viewer_position.x - position.x;
    const float dy = viewer_position.y - position.y;
    const float dz = viewer_position.z - position.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

int EffectRendering::ambientBrightness()
{
    const auto &light = SphereRenderSceneRenderer::environment.ambientColor;
    return SferaNumeric::truncateInt(light.y * 0.44999998807907104 + light.x * 0.3100000023841858 + light.z * 0.23999999463558197);
}

void EffectRendering::renderState(CD3D9Device &device, D3DRENDERSTATETYPE state, DWORD value)
{
    device.checkResult(device.native_device->SetRenderState(state, value), "SetRenderState");
}

void EffectRendering::samplerState(CD3D9Device &device, D3DSAMPLERSTATETYPE state, DWORD value)
{
    device.checkResult(device.native_device->SetSamplerState(0u, state, value), "SetSamplerState");
}

void EffectRendering::identityWorld(CD3D9Device &device)
{
    const auto identity = SferaMatrix4x4F::identity();
    device.setTransform(D3DTS_WORLD, identity);
}

std::pair<std::size_t, float> SferaEffectTrack::interval(float age, bool curved) const
{
    if (keys.empty())
        return {0, 0.0f};
    if (keys.size() == 1 || age >= keys.back().time)
        return {keys.size() - 1, 0.0f};
    std::size_t index = 0;
    for (std::size_t candidate = keys.size() - 1; candidate > 0; --candidate)
    {
        if (keys[candidate].time <= age)
        {
            index = candidate;
            break;
        }
    }
    const float duration = keys[index + 1].time - keys[index].time;
    float factor = duration == 0.0f ? 0.0f : (age - keys[index].time) / duration;
    if (curved && cosine_interpolation)
        factor = (1.0f - std::cos(factor * 3.1415929794311523f)) * 0.5f;
    return {index, factor};
}

void SferaEffectTrack::evaluateVector(float age, SferaVec3F &output) const
{
    output = {};
    if (keys.empty())
        return;
    const auto [index, factor] = interval(age, true);
    const auto &begin = std::get<SferaEffectTrackKeyVector>(keys[index].value);
    output = begin.minimum;
    if (index + 1 == keys.size())
        return;
    const auto &end = std::get<SferaEffectTrackKeyVector>(keys[index + 1].value);
    output.x += (end.minimum.x - begin.minimum.x) * factor;
    output.y += (end.minimum.y - begin.minimum.y) * factor;
    output.z += (end.minimum.z - begin.minimum.z) * factor;
}

auto SferaEffectTrack::sampleScalar(const std::vector<SferaEffectTrackKey> &keys, std::span<const std::uint16_t> random_values, std::uint32_t random_offset, std::size_t index)
{
    const auto &key = keys[index];
    const auto &value = std::get<SferaEffectTrackKeyScalar>(key.value);
    if (key.mode != SferaEffectTrackKeyMode::Random || random_values.empty() || index >= random_values.size())
        return value.minimum;
    const float random = (random_values[index] + random_offset) * 1.5259021893143654e-05f;
    return value.minimum + random * value.range;
}

void SferaEffectTrack::evaluateScalar(float age, float &output, std::span<const std::uint16_t> random_values, std::uint32_t random_offset) const
{
    output = 0.0f;
    if (keys.empty())
        return;

    const auto [index, factor] = interval(age, false);
    output = sampleScalar(keys, random_values, random_offset, index);
    if (index + 1 != keys.size())
        output += (sampleScalar(keys, random_values, random_offset, index + 1) - output) * factor;
}

void SferaEffectTrack::requireRandomCapacity(std::size_t) const
{
    // Legacy SEF loading never rejected a definition because a random track was
    // longer than the shared random row. evaluateScalar() now degrades to the
    // fixed minimum when a sample is outside the available row instead.
}

void SferaEffectRenderState::drawFlare(int texture, int x, int y, int size, int alpha_level) const
{
    const double logical_width = size * 640, logical_height = size * 480;
    const int width = SferaNumeric::truncateInt(logical_width / g_sfera_graphics_runtime.display_width);
    const int height = SferaNumeric::truncateInt(logical_height / g_sfera_graphics_runtime.display_height);
    const int left = x - (width >> 1);
    const int top = y - (height >> 1);
    const float environment = g_sfera_graphics_runtime.environment_factor;
    std::uint32_t intensity = 0u;
    if (environment < 0.3499999940395355f)
        intensity = std::min(SferaNumeric::truncatedWord((0.3499999940395355 - environment) * 2550.0), 255u);
    if (environment > 0.699999988079071f)
        intensity = std::min(SferaNumeric::truncatedWord((environment - 0.699999988079071) * 2550.0), 255u);
    if (environment < 0.1899999976158142f || environment > 0.8299999833106995f)
        intensity = 0u;
    const std::uint32_t alpha = alpha_level * intensity >> 8u;
    if (alpha == 0u)
        return;
    const float uv[8]{0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f};
    SphereUIInterfaceRenderer::setSpriteRenderMode(2u);
    SferaCanvasRenderer::drawSpriteTexture(D3DCOLOR_ARGB(alpha, 255, 100, 15), texture, SferaNumeric::real32(left), SferaNumeric::real32(top), SferaNumeric::real32(left + width),
                                           SferaNumeric::real32(top + height), uv, true);
    SphereUIInterfaceRenderer::setSpriteRenderMode(0u);
}

SferaLightInstance::SferaLightInstance(std::shared_ptr<const SferaLightDefinition> source) : definition(std::move(source))
{
    if (definition == nullptr)
        throw std::invalid_argument("Missing light definition");
    reset();
}

SferaLightInstance::SferaLightInstance(SferaLightInstance &&source) noexcept
    : definition(std::move(source.definition)), position(source.position), color(source.color), light_index(std::exchange(source.light_index, -1)), brightness_tick(source.brightness_tick)
{
}

SferaLightInstance::~SferaLightInstance()
{
    stop();
}

void SferaLightInstance::reset()
{
    stop();
    position = definition->position;
    color = definition->color;
    brightness_tick = 0;
}

void SferaLightInstance::update(const SferaVec3F &base_position, float age, std::uint32_t opacity)
{
    if (light_index == -1)
    {
        g_sfera_light_runtime.release(light_index);
        light_index = g_sfera_light_runtime.create(position, color.data(), 0.0f);
        if (light_index == -1)
            return;
    }
    if (definition->position_track != nullptr)
        definition->position_track->evaluateVector(age, position);
    if (definition->color_track != nullptr)
    {
        SferaVec3F sampled{};
        definition->color_track->evaluateVector(age, sampled);
        color[0] = sampled.x;
        color[1] = sampled.y;
        color[2] = sampled.z;
    }
    if (definition->alpha_track != nullptr)
        definition->alpha_track->evaluateScalar(age, color[3], SferaEffectHost::current().renderState().particle_random_table);
    SferaVec3F world_position{base_position.x + position.x, base_position.y + position.y, base_position.z + position.z};
    if (definition->randomize_color)
    {
        constexpr float random_scale = 3.0518509447574615e-05f;
        for (std::size_t channel = 0u; channel < 3u; ++channel)
            color[channel] = definition->random_color[channel] + std::rand() * random_scale * definition->random_color[channel + 3u];
    }
    const float opacity_scale = opacity * 0.00390625f;
    float output_color[4]{color[0] * opacity_scale, color[1] * opacity_scale, color[2] * opacity_scale, color[3] * opacity_scale};
    if (definition->vary_brightness && definition->brightness_frequency != 0u && brightness_tick % definition->brightness_frequency == 0u)
    {
        constexpr float random_scale = 3.0518509447574615e-05f;
        const float brightness_scale = definition->brightness + std::rand() * random_scale * definition->brightness_delta;
        output_color[0] *= brightness_scale;
        output_color[1] *= brightness_scale;
        output_color[2] *= brightness_scale;
    }
    ++brightness_tick;
    g_sfera_light_runtime.write(light_index, world_position, output_color, 0.0f);
}

void SferaLightInstance::stop() noexcept
{
    g_sfera_light_runtime.release(light_index);
    light_index = -1;
}

void CLightEffect::initializeEffect(const SferaEffectInitializeContext &context)
{
    if (context.spatial_frames.empty())
        return;
    const auto &light_position = context.spatial_frames.front();
    if (!registered)
        light_index = g_sfera_light_runtime.create(light_position, color, radius);
    if (light_index == -1)
        return;
    registered = true;
    float output_color[4]{color[0], color[1], color[2], color[3]};
    if (brightness_frequency != 0u && brightness_tick % brightness_frequency == 0u)
    {
        constexpr float random_scale = 3.0518509447574615e-05f;
        const float jitter = (std::rand() - std::rand()) * random_scale * brightness_jitter;
        output_color[0] += output_color[0] * jitter;
        output_color[1] += output_color[1] * jitter;
        output_color[2] += output_color[2] * jitter;
    }
    ++brightness_tick;
    g_sfera_light_runtime.write(light_index, light_position, output_color, radius);
}

bool CLightEffect::activateEffect(bool visible)
{
    if (visible)
        return true;
    g_sfera_light_runtime.release(light_index);
    light_index = -1;
    registered = false;
    return false;
}

void CLightEffect::deactivateEffect(bool)
{
    if (deactivated)
        return;
    g_sfera_light_runtime.release(light_index);
    light_index = -1;
    registered = false;
    deactivated = true;
}

std::unique_ptr<IEffect> CLightEffect::createEffectResources()
{
    auto effect = std::make_unique<CLightEffect>();
    effect->initializePreset();
    effect->assignScriptName("light_source.eff");
    return effect;
}

void CLightEffect::applyParameterValue(const auto &value)
{
    if constexpr (std::is_same_v<std::decay_t<decltype(value)>, SferaEffectParameterColor>)
    {
        for (std::size_t channel = 0; channel < value.channels.size(); ++channel)
            color[channel] = value.channels[channel];
    }
    else if constexpr (std::is_same_v<std::decay_t<decltype(value)>, SferaEffectParameterRadius>)
        radius = value.value;
    else if constexpr (std::is_same_v<std::decay_t<decltype(value)>, SferaEffectParameterJitter>)
        brightness_jitter = value.value / 100.0f;
    else if constexpr (std::is_same_v<std::decay_t<decltype(value)>, SferaEffectParameterFrequency>)
        brightness_frequency = value.value;
}

template <std::size_t Index> void CLightEffect::dispatchParameter(const SferaEffectParameter &parameter)
{
    if constexpr (Index < std::variant_size_v<decltype(parameter.value)>)
    {
        if (parameter.value.index() == Index)
            applyParameterValue(std::get<Index>(parameter.value));
        else
            dispatchParameter<Index + 1>(parameter);
    }
    else
    {
        throw std::bad_variant_access();
    }
}

void CLightEffect::setParameters(std::span<const SferaEffectParameter> parameters)
{
    for (const auto &parameter : parameters)
        dispatchParameter(parameter);
}

CLightEffect::~CLightEffect()
{
    g_sfera_light_runtime.release(light_index);
}

void SferaParticleSystemInstance::evaluate_magnet_factor(const SferaEffectTrack *track, float age, SferaVec3F &output, const std::uint16_t *values, std::uint32_t seed0, std::uint32_t seed1)
{
    SferaVec3F encoded{};
    SferaEffectAlgorithms::evaluate_random_vector(track, age, encoded, values, seed0, seed1);
    output = SferaParticleSystemInstance::reciprocal_magnet_factor(encoded);
}

void SferaParticleSystemInstance::particle_emit(SferaParticleSystemInstance &system, float delta)
{
    if (system.render_slots.empty())
        return;
    const float accumulated = system.emission_count * delta + system.emission_fraction;
    const std::uint32_t requested = accumulated <= 0.0f ? 0u : SferaNumeric::truncateInt(std::floor(accumulated));
    system.emission_fraction = accumulated - requested;
    if (requested == 0u)
        return;
    const SferaVec3F movement{system.current_position.x - system.previous_position.x, system.current_position.y - system.previous_position.y, system.current_position.z - system.previous_position.z};
    float movement_factor = 0.0f;
    const bool position_emit = (system.definition->flags & (1u << 18u)) != 0u && (movement).length<float, float>() > 0.0f;
    const float step = position_emit && accumulated != 0.0f ? 1.0f / accumulated : 0.0f;
    std::uint32_t emitted = 0u;
    for (std::size_t index = 0u; index < system.render_slots.size() && emitted < requested; ++index)
        if (system.render_slots[index].state.remaining_lifetime < 0.0f)
        {
            SferaEffectAlgorithms::particle_generate(system, index);
            if (position_emit)
            {
                system.render_slots[index].state.position.x -= movement.x * movement_factor;
                system.render_slots[index].state.position.y -= movement.y * movement_factor;
                system.render_slots[index].state.position.z -= movement.z * movement_factor;
                system.render_slots[index].state.spawn_position = system.render_slots[index].state.position;
                movement_factor += step;
            }
            ++emitted;
            ++system.active_particle_count;
        }
}

void SferaParticleSystemInstance::update_particle_children(SferaParticleSystemInstance &system, float age)
{
    if (system.render_slots.empty())
        return;
    for (std::size_t index = 0u; index < system.render_slots.size(); ++index)
    {
        auto &slot = system.render_slots[index];
        if (slot.state.remaining_lifetime < 0.0f)
            continue;
        if ((system.definition->flags & (1u << 10u)) != 0u)
            slot.state.render_position = slot.state.position;
        else if ((system.definition->flags & (1u << 5u)) != 0u)
            slot.state.render_position = {slot.state.position.x + system.current_position.x, slot.state.position.y + system.current_position.y, slot.state.position.z + system.current_position.z};
        else
            slot.state.render_position = (system.transform).transformPoint<float>(slot.state.position);
        if (slot.linked_particle_system == nullptr)
            continue;
        if ((slot.linked_particle_system->definition->flags & (1u << 23u)) != 0u)
            slot.linked_particle_system->power = slot.state.color.alpha() * 0.00392156862745098f * system.power;
        slot.linked_particle_system->update(&slot.state.render_position, nullptr, age);
    }
}

SferaParticleSystemInstance::SferaParticleSystemInstance(std::shared_ptr<const SferaParticleSystemDefinition> source) : definition(std::move(source))
{
    if (definition == nullptr)
        throw std::invalid_argument("Missing particle definition");
    restoreSettings();
    render_slots.reserve(definition->particles.size());
    for (const auto &particle : definition->particles)
        render_slots.push_back({particle.initial, &particle, nullptr});
}

void SferaParticleSystemInstance::restoreSettings()
{
    radius = definition->radius;
    height = definition->height;
    width = definition->width;
    emitter_position = definition->emitter_position;
    emission_count = definition->emission_count;
    lifetime = definition->lifetime;
    power = definition->power;
    magnet_factor = definition->magnet_factor;
    magnet_position = definition->magnet_position;
}

void SferaParticleSystemInstance::initializeClone()
{
    runtime_random_row = std::rand() % 255;
    runtime_random_seed_0 = std::rand();
    runtime_random_seed_1 = std::rand();
    texture_ids.clear();
    texture_ids.reserve(definition->texture_frames.size());
    for (const auto &frame : definition->texture_frames)
        texture_ids.push_back(frame.texture_name.empty() ? -1 : SferaTextureAccess::find(frame.texture_name));
}

void SferaParticleSystemInstance::reset()
{
    restoreSettings();
    active_particle_count = 0;
    emission_fraction = 0.0f;
    current_position = previous_position = previous_origin = {};
    transform = {};
    first_update = emitting = runtime_active = true;
    runtime_stop_requested = false;
    initializeClone();
    for (auto &slot : render_slots)
    {
        slot.state = slot.settings->initial;
        if ((definition->flags & (1u << 6u)) == 0u)
            slot.state.remaining_lifetime = -1.0f;
    }
}

void SferaParticleSystemInstance::update(const SferaVec3F *spatial_frame, const SferaMatrix4x4F *world_frame, float age)
{
    if (!runtime_active)
        return;
    const SferaVec3F incoming = spatial_frame == nullptr ? current_position : *spatial_frame;
    if (first_update)
    {
        previous_position = incoming;
        previous_origin = current_position;
        first_update = false;
    }
    else
        previous_position = current_position;
    current_position = incoming;
    const auto *table = SferaEffectHost::current().renderState().particle_random_table.data();
    const std::uint16_t *random_values = table == nullptr ? nullptr : table + ((runtime_random_row & 255u) << 8u);
    if ((definition->flags & (1u << 5u)) != 0u)
    {
        if (definition->position_track != nullptr)
        {
            SferaVec3F offset{};
            definition->position_track->evaluateVector(age, offset);
            current_position.x += offset.x;
            current_position.y += offset.y;
            current_position.z += offset.z;
        }
        if ((definition->flags & (1u << 27u)) != 0u && world_frame != nullptr)
            transform = *world_frame;
    }
    else
    {
        transform = SferaMatrix4x4F::identity();
        bool rotated = false;
        if (definition->rotation_track != nullptr)
        {
            SferaVec3F rotation{};
            definition->rotation_track->evaluateVector(age, rotation);
            SferaEffectAlgorithms::apply_particle_rotation(transform, definition->flags, rotation);
            rotated = (definition->flags & 15u) != 0u;
        }
        if (definition->scale_track != nullptr)
        {
            SferaVec3F scale{};
            definition->scale_track->evaluateVector(age, scale);
            if (rotated || (definition->flags & (1u << 4u)) != 0u)
                (transform).scaleAxes(scale);
            else
            {
                transform.m[0][0] = scale.x;
                transform.m[1][1] = scale.y;
                transform.m[2][2] = scale.z;
            }
        }
        transform.m[0][3] = current_position.x;
        transform.m[1][3] = current_position.y;
        transform.m[2][3] = current_position.z;
        if (definition->position_track != nullptr)
        {
            SferaVec3F offset{};
            definition->position_track->evaluateVector(age, offset);
            transform.m[0][3] += offset.x;
            transform.m[1][3] += offset.y;
            transform.m[2][3] += offset.z;
        }
        if ((definition->flags & (1u << 27u)) != 0u && world_frame != nullptr)
        {
            SferaMatrix4x4F combined{};
            combined = (transform).multiplied<float>(*world_frame);
            transform = combined;
        }
    }
    SferaEffectAlgorithms::evaluate_particle_scalar(definition->emission_track.get(), age, emission_count, random_values, runtime_random_seed_0);
    if (definition->emission_position_track != nullptr)
    {
        SferaVec3F value{};
        SferaEffectAlgorithms::evaluate_random_vector(definition->emission_position_track.get(), age, value, random_values, runtime_random_seed_0, runtime_random_seed_1);
        if ((definition->flags & (1u << 22u)) != 0u)
        {
            radius = value.x;
            height = value.y;
            width = value.z;
        }
        else
            emitter_position = value;
    }
    SferaEffectAlgorithms::evaluate_particle_scalar(definition->lifetime_track.get(), age, lifetime, random_values, runtime_random_seed_0);
    SferaEffectAlgorithms::evaluate_particle_scalar(definition->power_track.get(), age, power, random_values, runtime_random_seed_0);
    if ((definition->flags & (1u << 8u)) != 0u)
    {
        if (definition->magnet_position_track != nullptr)
            SferaEffectAlgorithms::evaluate_random_vector(definition->magnet_position_track.get(), age, magnet_position, random_values, runtime_random_seed_0, runtime_random_seed_1);
        if ((definition->flags & (1u << 21u)) != 0u && definition->magnet_factor_track != nullptr)
            SferaParticleSystemInstance::evaluate_magnet_factor(definition->magnet_factor_track.get(), age, magnet_factor, random_values, runtime_random_seed_0, runtime_random_seed_1);
    }
    SferaVec3F effective_magnet_position = magnet_position;
    if ((definition->flags & (1u << 10u)) != 0u)
    {
        if ((definition->flags & (1u << 5u)) != 0u)
        {
            effective_magnet_position.x += current_position.x;
            effective_magnet_position.y += current_position.y;
            effective_magnet_position.z += current_position.z;
        }
        else
        {
            effective_magnet_position = (transform).transformPoint<float>(magnet_position);
        }
    }
    const SferaVec3F direct = (definition->flags & (1u << 25u)) != 0u
                                  ? SferaVec3F{current_position.x - previous_origin.x, current_position.y - previous_origin.y, current_position.z - previous_origin.z}
                                        .unit<float, float, true>(0.000001f,
                                                                  SferaVec3F{current_position.x - previous_origin.x, current_position.y - previous_origin.y, current_position.z - previous_origin.z})
                                  : SferaVec3F{1.0f, 1.0f, 1.0f};
    active_particle_count = 0u;
    for (std::size_t index = 0u; !render_slots.empty() && index < render_slots.size(); ++index)
    {
        auto &slot = render_slots[index];
        if (slot.state.remaining_lifetime < 0.0f)
            continue;
        if ((definition->flags & (1u << 13u)) == 0u)
            slot.state.remaining_lifetime -= 2.0f;
        if (slot.state.remaining_lifetime <= 0.0f)
        {
            slot.state.remaining_lifetime = -1.0f;
            continue;
        }
        const float local_time = (definition->flags & (1u << 12u)) != 0u ? age : slot.state.total_lifetime == 0.0f ? 1.0f : 1.0f - slot.state.remaining_lifetime / slot.state.total_lifetime;
        const std::uint16_t *slot_random = table == nullptr ? nullptr : table + ((slot.state.random_row & 255u) << 8u);
        if (slot.settings->size_track != nullptr)
            SferaEffectAlgorithms::evaluate_particle_scalar(slot.settings->size_track, local_time, slot.state.size, slot_random, slot.state.random_seed_0);
        if (slot.settings->color_track != nullptr)
            SferaEffectAlgorithms::evaluate_mesh_color(*slot.settings->color_track, local_time, slot.state.color, slot_random, slot.state.random_seed_0, slot.state.random_seed_1);
        SferaVec3F motion{};
        if (slot.settings->velocity_track != nullptr)
            SferaEffectAlgorithms::evaluate_random_vector(slot.settings->velocity_track, local_time, motion, slot_random, slot.state.random_seed_0, slot.state.random_seed_1);
        if (slot.settings->gravity_track != nullptr)
        {
            SferaVec3F gravity{};
            SferaEffectAlgorithms::evaluate_random_vector(slot.settings->gravity_track, local_time, gravity, slot_random, slot.state.random_seed_0, slot.state.random_seed_1);
            motion.x += gravity.x;
            motion.y += gravity.y;
            motion.z += gravity.z;
        }
        if ((definition->flags & (1u << 8u)) != 0u)
        {
            SferaVec3F factor = magnet_factor;
            if ((definition->flags & (1u << 21u)) == 0u && definition->magnet_factor_track != nullptr)
                SferaParticleSystemInstance::evaluate_magnet_factor(definition->magnet_factor_track.get(), local_time, factor, slot_random, slot.state.random_seed_0, slot.state.random_seed_1);
            SferaVec3F delta{effective_magnet_position.x - slot.state.position.x, effective_magnet_position.y - slot.state.position.y, effective_magnet_position.z - slot.state.position.z};
            if ((definition->flags & (1u << 17u)) != 0u)
            {
                const SferaVec3F target{slot.state.spawn_position.x + (effective_magnet_position.x - slot.state.spawn_position.x) * local_time,
                                        slot.state.spawn_position.y + (effective_magnet_position.y - slot.state.spawn_position.y) * local_time,
                                        slot.state.spawn_position.z + (effective_magnet_position.z - slot.state.spawn_position.z) * local_time};
                delta = {target.x - slot.state.position.x, target.y - slot.state.position.y, target.z - slot.state.position.z};
            }
            motion.x += factor.x * delta.x;
            motion.y += factor.y * delta.y;
            motion.z += factor.z * delta.z;
        }
        if ((definition->flags & (1u << 16u)) != 0u)
        {
            slot.state.position.x += (std::rand() - std::rand()) * 3.0518509447574615e-05f * definition->distortion.x;
            slot.state.position.y += (std::rand() - std::rand()) * 3.0518509447574615e-05f * definition->distortion.y;
            slot.state.position.z += (std::rand() - std::rand()) * 3.0518509447574615e-05f * definition->distortion.z;
        }
        motion.x *= direct.x;
        motion.y *= direct.y;
        motion.z *= direct.z;
        slot.state.position.x += motion.x;
        slot.state.position.y += motion.y;
        slot.state.position.z += motion.z;
        slot.state.texture_frame += definition->texture_animation_speed;
        if (definition->texture_frames.size() != 0u && slot.state.texture_frame > (definition->texture_frames.size() - 1u))
            slot.state.texture_frame = 0.0f;
        ++active_particle_count;
    }
    if ((definition->flags & (1u << 7u)) == 0u && emitting)
        SferaParticleSystemInstance::particle_emit(*this, 2.0f);
    if (active_particle_count == 0u && !emitting && runtime_stop_requested)
        runtime_active = false;
    SferaParticleSystemInstance::update_particle_children(*this, age);
}

void SferaParticleSystemInstance::commit()
{
    if (!runtime_active || render_slots.empty() || definition->texture_frames.empty())
        return;
    for (std::size_t index = 0u; index < render_slots.size(); ++index)
        if (render_slots[index].state.remaining_lifetime >= 0.0f && render_slots[index].linked_particle_system != nullptr)
            render_slots[index].linked_particle_system->commit();
    const auto capacity = SferaEffectHost::current().renderState().render_slots.size();
    const auto used = SferaEffectHost::current().renderState().render_slot_count;
    if (used > capacity || render_slots.size() > capacity - used)
        return;
    const std::uint32_t opacity = SferaNumeric::truncatedWord(std::max(power, 0.0f) * 256.0f);
    if (opacity == 0u)
        return;
    for (std::size_t index = 0u; index < render_slots.size(); ++index)
    {
        const auto &particle = render_slots[index];
        if (particle.state.remaining_lifetime < 0.0f)
            continue;
        SferaEffectRenderSlot *slot = SferaEffectHost::current().renderState().acquireRenderSlot();
        if (slot == nullptr)
            break;
        const std::size_t frame = particle.state.texture_frame >= definition->texture_frames.size() ? definition->texture_frames.size() - 1u
                                                                                                    : SferaNumeric::truncatedWord(std::max(particle.state.texture_frame, 0.0f));
        const auto &texture = definition->texture_frames[frame];
        slot->resource_id = (definition->flags & (1u << 9u)) != 0u ? texture_ids[0] : texture_ids[frame];
        slot->self_illumination = definition->self_illumination;
        slot->additive = definition->additive;
        slot->custom_uv = definition->custom_uv;
        const auto &uv = (definition->flags & (1u << 9u)) != 0u ? texture : definition->texture_frames[0];
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex)
        {
            slot->uv[vertex][0] = uv.uv[vertex * 2u];
            slot->uv[vertex][1] = uv.uv[vertex * 2u + 1u];
        }
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex)
        {
            slot->color[0][vertex] = particle.state.color.red();
            slot->color[1][vertex] = particle.state.color.green();
            slot->color[2][vertex] = particle.state.color.blue();
            slot->color[3][vertex] = particle.state.color.alpha() * opacity >> 8u;
        }
        if ((definition->flags & (1u << 11u)) != 0u)
            for (std::size_t vertex = 0u; vertex < 4u; ++vertex)
                slot->position[vertex] = {particle.state.render_position.x + definition->render_basis[vertex].x * particle.state.size,
                                          particle.state.render_position.y + definition->render_basis[vertex].y * particle.state.size,
                                          particle.state.render_position.z + definition->render_basis[vertex].z * particle.state.size};
        else
        {
            const SferaVec3F view{particle.state.render_position.x - SferaEffectHost::current().renderState().viewer_position.x,
                                  particle.state.render_position.y - SferaEffectHost::current().renderState().viewer_position.y,
                                  particle.state.render_position.z - SferaEffectHost::current().renderState().viewer_position.z};
            SferaVec3F right{}, up{};
            SferaEffectAlgorithms::build_y_up_billboard_axes(view, particle.state.size * definition->render_basis[0].y, particle.state.size * definition->render_basis[0].x, right, up);
            slot->position[0] = {particle.state.render_position.x - right.x - up.x, particle.state.render_position.y - right.y - up.y, particle.state.render_position.z - right.z - up.z};
            slot->position[1] = {particle.state.render_position.x - right.x + up.x, particle.state.render_position.y - right.y + up.y, particle.state.render_position.z - right.z + up.z};
            slot->position[2] = {particle.state.render_position.x + right.x + up.x, particle.state.render_position.y + right.y + up.y, particle.state.render_position.z + right.z + up.z};
            slot->position[3] = {particle.state.render_position.x + right.x - up.x, particle.state.render_position.y + right.y - up.y, particle.state.render_position.z + right.z - up.z};
        }
    }
}

void CMolEffect::initialize_quad_slot(SferaEffectRenderSlot &slot, int resource_id, bool additive, bool custom_uv, int alpha)
{
    slot.resource_id = resource_id;
    slot.self_illumination = alpha;
    slot.additive = additive;
    slot.custom_uv = custom_uv;
    for (std::size_t vertex = 0u; vertex < 4u; ++vertex)
    {
        slot.color[0][vertex] = 255u;
        slot.color[1][vertex] = 255u;
        slot.color[2][vertex] = 255u;
        slot.color[3][vertex] = alpha;
    }
}

void CSpiralEffect::initializeEffect(const SferaEffectInitializeContext &context)
{
    if (!context.visible || context.spatial_frames.empty())
        return;
    if (render_slot_budget + SferaEffectHost::current().renderState().render_slot_count >= 10000u)
        return;
    const auto &base = context.spatial_frames.front();
    float opacity = 1.0f;
    if (context.age > 320.0f)
        opacity = (400.0f - context.age) / 80.0f;
    constexpr float pi = 3.1415929794311523f;
    const float age_phase = context.age * 0.05f;
    for (std::size_t ring = 0u; ring < 2u; ++ring)
    {
        float progress = 0.0f;
        for (std::size_t point = 0u; point < 40u; ++point, progress += 0.025f)
        {
            SferaEffectRenderSlot *slot = SferaEffectHost::current().renderState().acquireRenderSlot();
            if (slot == nullptr)
                return;
            slot->resource_id = resource_id;
            slot->self_illumination = 255u;
            slot->additive = true;
            slot->custom_uv = false;
            const std::uint32_t red = 51u + SferaNumeric::truncateInt(204.0f * progress);
            const std::uint32_t green = 153u + SferaNumeric::truncateInt(51.0f * progress);
            const std::uint32_t blue = 153u - SferaNumeric::truncateInt(77.0f * progress);
            const std::uint32_t alpha = SferaNumeric::truncatedWord((1.0f - progress) * 255.0f * opacity);
            for (std::size_t vertex = 0u; vertex < 4u; ++vertex)
            {
                slot->color[0][vertex] = red;
                slot->color[1][vertex] = green;
                slot->color[2][vertex] = blue;
                slot->color[3][vertex] = alpha;
            }
            const float angle = pi * progress * 1.2f + ring * pi - age_phase;
            SferaVec3F billboard_position{base.x - std::sin(angle) * 0.3f, base.y - progress, base.z - std::cos(angle) * 0.3f};
            SferaEffectHost::current().renderState().finalizeBillboard(*slot, billboard_position, 0.15f);
        }
    }
}

void CMolEffect::initializeEffect(const SferaEffectInitializeContext &context)
{
    if (!context.visible || context.spatial_frames.empty() || render_slot_budget + SferaEffectHost::current().renderState().render_slot_count >= 10000u)
        return;
    const auto &input = context.spatial_frames.front();
    if (!anchor_initialized)
    {
        anchor = input;
        anchor_initialized = true;
    }
    const SferaVec3F reference = SferaSceneAccess::referencePosition();
    SferaEffectRenderSlot *slot = SferaEffectHost::current().renderState().acquireRenderSlot();
    if (slot == nullptr)
        return;
    CMolEffect::initialize_quad_slot(*slot, resource_id, true, true, 255);
    const SferaVec3F start_jitter{CMolEffect::random_signed(0.2f), CMolEffect::random_signed(0.2f), CMolEffect::random_signed(0.2f)};
    const SferaVec3F end_jitter{CMolEffect::random_signed(0.2f), CMolEffect::random_signed(0.2f), CMolEffect::random_signed(0.2f)};
    const SferaVec3F start = ((anchor) + (start_jitter));
    const SferaVec3F end = ((reference) + (end_jitter));
    const SferaVec3F direction = ((end) - (start));
    texture_phase += 0.05f;
    const float texture_length = (direction).length<float, float>() * 0.3f;
    const SferaVec3F end_width = ((((direction).cross<float>((((end) - (reference))))).unit<float, float, false, true>(0.0f, SferaVec3F{})) * (0.8f));
    const SferaVec3F start_width = ((((direction).cross<float>((((start) - (reference))))).unit<float, float, false, true>(0.0f, SferaVec3F{})) * (0.8f));
    slot->position[0] = ((end) + (end_width));
    slot->position[1] = ((end) - (end_width));
    slot->position[2] = ((start) - (start_width));
    slot->position[3] = ((start) + (start_width));
    slot->uv[0][0] = 0.0f;
    slot->uv[0][1] = texture_phase;
    slot->uv[1][0] = 1.0f;
    slot->uv[1][1] = texture_phase + texture_length;
    slot->uv[2][0] = 1.0f;
    slot->uv[2][1] = texture_phase + texture_length;
    slot->uv[3][0] = 0.0f;
    slot->uv[3][1] = texture_phase + texture_length;
}

void CMolEffect::updateEffect(const SferaEffectUpdateContext &context)
{
    if (sound_effect == nullptr)
    {
        sound_started = true;
        return;
    }
    if (!sound_started)
    {
        sound_effect->start(context.frame, sound_effect->startTime() < context.viewer_distance);
        sound_started = true;
        return;
    }
    sound_effect->update(&anchor, context.viewer_distance);
}

CMolEffect::~CMolEffect() = default;

void CBladeEffect::initializeEffect(const SferaEffectInitializeContext &context)
{
    if (!context.visible || context.spatial_frames.empty() || render_slot_budget + SferaEffectHost::current().renderState().render_slot_count >= 10000u)
        return;
    const auto &input = context.spatial_frames.front();
    if (!anchor_initialized)
    {
        anchor = input;
        anchor_initialized = true;
    }
    const SferaVec3F reference = SferaSceneAccess::referencePosition();
    SferaEffectRenderSlot *slot = SferaEffectHost::current().renderState().acquireRenderSlot();
    if (slot == nullptr)
        return;
    progress += 0.05f;
    if (progress > 1.0f)
        progress = 1.0f;
    std::uint32_t alpha = 255u;
    if (progress > 0.8f)
        alpha = SferaNumeric::truncatedWord((1.0f - progress) * 1275.0f);
    slot->resource_id = resource_id;
    slot->self_illumination = 255u;
    slot->additive = true;
    slot->custom_uv = true;
    for (std::size_t vertex = 0u; vertex < 4u; ++vertex)
    {
        slot->color[0][vertex] = 255u;
        slot->color[1][vertex] = 255u;
        slot->color[2][vertex] = 255u;
        slot->color[3][vertex] = alpha;
    }
    const SferaVec3F path = ((input) - (anchor));
    const SferaVec3F end = ((anchor) + (((path) * (progress))));
    const SferaVec3F direction = (((anchor) - (end))).unit<float, float, false, true>(0.0f, SferaVec3F{});
    const SferaVec3F back = ((end) - (((direction) * (0.5f))));
    const SferaVec3F back_width = ((((((back) - (reference))).cross<float>((((back) - (end))))).unit<float, float, false, true>(0.0f, SferaVec3F{})) * (0.8f));
    const SferaVec3F end_width = ((((((end) - (reference))).cross<float>((((back) - (end))))).unit<float, float, false, true>(0.0f, SferaVec3F{})) * (0.8f));
    slot->position[0] = ((back) + (back_width));
    slot->position[1] = ((back) - (back_width));
    slot->position[2] = ((end) - (end_width));
    slot->position[3] = ((end) + (end_width));
    slot->uv[0][0] = 0.0f;
    slot->uv[0][1] = 0.0f;
    slot->uv[1][0] = 1.0f;
    slot->uv[1][1] = progress;
    slot->uv[2][0] = 1.0f;
    slot->uv[2][1] = 1.0f;
    slot->uv[3][0] = 0.0f;
    slot->uv[3][1] = progress;
}

void CGazerLakeEffect::initializeEffect(const SferaEffectInitializeContext &context)
{
    if (context.spatial_frames.empty())
        return;
    if (emission_period != 0u && emission_tick % emission_period == 0u)
    {
        for (SferaGazerEffectSlot &slot : slots)
        {
            if (slot.age != -1.0f)
                continue;
            constexpr float random_scale = 3.0518509447574615e-05f;
            constexpr float pi = 3.1415929794311523f;
            const float azimuth = std::rand() * random_scale * (2.0f * pi);
            const float elevation = (std::rand() * random_scale - 0.5f) * pi;
            const float elevation_cos = std::cos(elevation);
            slot.offset.x = std::sin(azimuth) * radius * elevation_cos;
            slot.offset.y = 0.0f;
            slot.offset.z = std::cos(azimuth) * radius * elevation_cos;
            slot.age = 0.0f;
            break;
        }
    }
    emission_tick += 2u;
    const auto &base = context.spatial_frames.front();
    for (SferaGazerEffectSlot &slot : slots)
    {
        if (slot.age == -1.0f || slot.effect == nullptr)
            continue;
        slot.age += 2.0f;
        if (slot.age > 192.0f)
        {
            slot.age = -1.0f;
            continue;
        }
        SferaVec3F child_position{base.x + slot.offset.x, base.y + slot.offset.y, base.z + slot.offset.z};
        SferaEffectInitializeContext child_context{{&child_position, 1}, slot.age, context.visible, {}};
        slot.effect->initializeEffect(child_context);
    }
}

CGazerLakeEffect::~CGazerLakeEffect() = default;

float CMolEffect::random_signed(float scale)
{
    constexpr float random_scale = 3.0518509447574615e-05f;
    return (std::rand() - std::rand()) * random_scale * scale;
}

void CRainEffect::set_full_quad_uv(SferaEffectRenderSlot &slot)
{
    slot.uv[0][0] = 0.0f;
    slot.uv[0][1] = 0.0f;
    slot.uv[1][0] = 1.0f;
    slot.uv[1][1] = 0.0f;
    slot.uv[2][0] = 1.0f;
    slot.uv[2][1] = 1.0f;
    slot.uv[3][0] = 0.0f;
    slot.uv[3][1] = 1.0f;
}

void CRainEffect::initializeEffect(const SferaEffectInitializeContext &context)
{
    if (!context.visible || context.spatial_frames.empty() || resource_id == -1 || particles.empty() || render_slot_budget + SferaEffectHost::current().renderState().render_slot_count >= 10000u)
        return;
    constexpr std::uint32_t particle_count = 3000u;
    constexpr float random_scale = 3.0518509447574615e-05f;
    constexpr float pi = 3.1415929794311523f;
    const float requested = spawn_rate + spawn_fraction;
    std::uint32_t spawn_count = SferaNumeric::truncatedWord(requested);
    spawn_fraction = requested - spawn_count;
    for (std::size_t index = 0u; index < particle_count && spawn_count != 0u; ++index)
    {
        SferaRainParticle &particle = particles[index];
        if (particle.remaining_life >= 0.0f)
            continue;
        particle.initial_life = particle.remaining_life = 30.0f + std::rand() * random_scale * 20.0f;
        particle.fall_speed = 0.06f + std::rand() * random_scale * 0.06f;
        particle.half_width = 0.025f + std::rand() * random_scale * 0.025f;
        const float angle = std::rand() * random_scale * (2.0f * pi);
        const float elevation = (std::rand() * random_scale - 0.5f) * pi;
        const float radius = spawn_radius_bias + spawn_radius * std::cos(elevation);
        particle.offset = {std::sin(angle) * radius, 0.0f, std::cos(angle) * radius};
        --spawn_count;
    }
    const auto &base = context.spatial_frames.front();
    for (std::size_t index = 0u; index < particle_count; ++index)
    {
        SferaRainParticle &particle = particles[index];
        if (particle.remaining_life < 0.0f)
            continue;
        particle.remaining_life -= 2.0f;
        const float fade = 1.0f - particle.remaining_life / particle.initial_life;
        particle.offset.y += particle.fall_speed;
        particle.alpha = fade > 0.1f ? 200u : SferaNumeric::truncateInt(fade * 2000.0f);
        SferaEffectRenderSlot *slot = SferaEffectHost::current().renderState().acquireRenderSlot();
        if (slot == nullptr)
            return;
        slot->resource_id = resource_id;
        slot->self_illumination = 0u;
        slot->additive = true;
        slot->custom_uv = false;
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex)
        {
            slot->color[0][vertex] = 155u;
            slot->color[1][vertex] = 155u;
            slot->color[2][vertex] = 155u;
            slot->color[3][vertex] = particle.alpha;
        }
        SferaVec3F center = ((base) + (particle.offset));
        center.y -= 4.0f;
        CRainEffect::set_full_quad_uv(*slot);
        const SferaVec3F viewer{SferaEffectHost::current().renderState().viewer_position.x, SferaEffectHost::current().renderState().viewer_position.y,
                                SferaEffectHost::current().renderState().viewer_position.z};
        const SferaVec3F to_viewer = ((center) - (viewer));
        SferaVec3F right{}, up{};
        SferaEffectAlgorithms::build_y_up_billboard_axes(to_viewer, particle.half_width, particle.half_width, right, up);
        const SferaVec3F left_center = ((center) - (right));
        const SferaVec3F right_center = ((center) + (right));
        slot->position[0] = ((left_center) - (up));
        slot->position[1] = ((left_center) + (up));
        slot->position[2] = ((right_center) + (up));
        slot->position[3] = ((right_center) - (up));
    }
}

CRainEffect::~CRainEffect() = default;

void CScriptedEffect::initialize_scripted_phase(CScriptedEffect &effect)
{
    effect.work_phase_active = false;
    effect.phase_ticks_remaining = 0u;
    if (effect.definition == nullptr)
        return;
    if (effect.definition->work_time_min == std::numeric_limits<std::uint32_t>::max())
        return;
    if ((std::rand() & 1) == 0)
        effect.work_phase_active = true;
    const std::uint32_t duration = !effect.work_phase_active ? effect.definition->work_time_max : effect.definition->sleep_time_max;
    if (duration != 0u)
        effect.phase_ticks_remaining = std::rand() % duration;
}

auto CScriptedEffect::resetParticleChildren(SferaParticleSystemInstance &parent) -> void
{
    for (auto &child : parent.children)
        child->reset();
    for (auto &child : parent.children)
        resetParticleChildren(*child);
}

void CScriptedEffect::resetRuntimeState()
{
    if (definition == nullptr)
        return;
    deactivated = resources_released = activation_blocked = sound_started = false;
    listener = nullptr;
    CScriptedEffect::initialize_scripted_phase(*this);
    if (sound_effect != nullptr && definition->sound != nullptr)
        sound_effect->reset();
    for (auto &light : lights)
        light.reset();
    for (auto &mesh : meshes)
        mesh.reset();
    for (auto &particle : particle_systems)
        particle->reset();

    for (auto &particle : particle_systems)
        resetParticleChildren(*particle);
}

void CScriptedEffect::initializeEffect(const SferaEffectInitializeContext &context)
{
    if (definition == nullptr)
        return;
    const auto capacity = SferaEffectHost::current().renderState().render_slots.size();
    const auto used = SferaEffectHost::current().renderState().render_slot_count;
    if (context.visible && used >= capacity)
    {
        SferaEffectHost::current().rejectRenderBudget();
        return;
    }
    const auto spatial_frames = context.spatial_frames;
    if (!lights.empty() && !spatial_frames.empty())
    {
        for (std::size_t index = 0u; index < lights.size(); ++index)
        {
            auto &light = lights[index];
            if (light.definition->attach_mode < spatial_frames.size())
                light.update(spatial_frames[light.definition->attach_mode], context.age, 255u);
        }
    }
    if (definition->work_time_min != std::numeric_limits<std::uint32_t>::max())
    {
        if (phase_ticks_remaining == 0u)
        {
            constexpr float random_scale = 3.0518509447574615e-05f;
            if (!work_phase_active)
            {
                phase_ticks_remaining = definition->work_time_min + SferaNumeric::truncateInt(std::rand() * random_scale * definition->work_time_max);
                work_phase_active = true;
                if (!particle_systems.empty())
                {
                    for (std::size_t index = 0u; index < particle_systems.size(); ++index)
                    {
                        auto &particle = *particle_systems[index];
                        particle.emission_fraction = 0.0f;
                        particle.emitting = true;
                        particle.runtime_active = true;
                        particle.runtime_stop_requested = false;
                    }
                }
            }
            else
            {
                phase_ticks_remaining = definition->sleep_time_min + SferaNumeric::truncateInt(std::rand() * random_scale * definition->sleep_time_min);
                work_phase_active = false;
                if (!particle_systems.empty())
                {
                    for (std::size_t index = 0u; index < particle_systems.size(); ++index)
                    {
                        auto &particle = *particle_systems[index];
                        particle.emission_fraction = 0.0f;
                        particle.emitting = false;
                        particle.runtime_stop_requested = true;
                    }
                }
            }
        }
        else
        {
            --phase_ticks_remaining;
        }
    }
    if (spatial_frames.empty() || context.world_frames.empty())
        return;
    const auto world_frames = context.world_frames;
    for (std::size_t index = 0u; index < definition->subeffects.size(); ++index)
    {
        const SferaSubeffectDefinition &subeffect = definition->subeffects[index];
        if (subeffect.definition_index < 0 || subeffect.attach_mode >= spatial_frames.size() || subeffect.attach_mode >= world_frames.size())
            continue;
        const SferaVec3F *spatial_frame = &spatial_frames[subeffect.attach_mode];
        const SferaMatrix4x4F *world_frame = &world_frames[subeffect.attach_mode];
        if (context.visible)
        {
            if (subeffect.kind == SferaSubeffectDefinitionKind::Mesh)
            {
                if (meshes.empty() || std::cmp_greater_equal(subeffect.definition_index, meshes.size()))
                    continue;
                auto &mesh = meshes[subeffect.definition_index];
                mesh.update(spatial_frame, world_frame, context.age);
                mesh.commit();
            }
            else
            {
                if (particle_systems.empty() || std::cmp_greater_equal(subeffect.definition_index, particle_systems.size()))
                    continue;
                auto &particle = *particle_systems[subeffect.definition_index];
                particle.update(spatial_frame, world_frame, context.age);
                particle.commit();
            }
        }
        else if (subeffect.kind == SferaSubeffectDefinitionKind::ParticleSystem && !particle_systems.empty() && std::cmp_less(subeffect.definition_index, particle_systems.size()))
        {
            particle_systems[subeffect.definition_index]->update(spatial_frame, world_frame, context.age);
        }
    }
}

void CScriptedEffect::updateEffect(const SferaEffectUpdateContext &context)
{
    if (sound_effect == nullptr)
        return;
    if (!sound_started)
    {
        sound_effect->start(context.frame, sound_effect->startTime() < context.viewer_distance);
        sound_started = true;
        return;
    }
    sound_effect->update(context.frame, context.viewer_distance);
}

void CScriptedEffect::queryEffectState(const SferaEffectQueryContext &context)
{
    for (auto &light : lights)
    {
        if (light.definition->attach_mode < context.frames.size())
            light.update(context.frames[light.definition->attach_mode], context.age, 255u);
    }
}

bool CScriptedEffect::activateEffect(bool visible)
{
    return definition != nullptr && (!definition->update_visible_only || visible);
}

void CScriptedEffect::deactivateEffect(bool preserve_resources)
{
    if (deactivated)
        return;
    if (!preserve_resources)
        stopResources();
    resources_released = preserve_resources ? 0u : 1u;
    deactivated = true;
}

void CScriptedEffect::renderEffect()
{
    if (!deactivated)
        return;
    if (sound_effect != nullptr && sound_effect->isComplete())
        sound_started = false;
    deactivated = false;
}

auto CScriptedEffect::buildParticleChildren(SferaParticleSystemInstance &parent) -> void
{
    for (std::size_t link_index = 0; link_index < parent.definition->links.size(); ++link_index)
    {
        const auto &link = parent.definition->links[link_index];
        if (link.instance_count == 0 || link.target_index < 0 || std::cmp_greater_equal(link.target_index, definition->particles.size()))
            continue;
        const auto begin = parent.children.size();
        for (std::size_t child = 0; child < link.instance_count; ++child)
        {
            auto instance = std::make_unique<SferaParticleSystemInstance>(definition->particles.at(link.target_index));
            instance->initializeClone();
            parent.children.push_back(std::move(instance));
        }
        std::size_t cursor = begin;
        for (auto &slot : parent.render_slots)
            if (std::cmp_equal(slot.settings->link_index, link_index))
            {
                if (cursor >= parent.children.size())
                    throw std::logic_error("Particle link count mismatch");
                slot.linked_particle_system = parent.children[cursor++].get();
            }
    }
    for (auto &child : parent.children)
        buildParticleChildren(*child);
}

std::unique_ptr<IEffect> CScriptedEffect::createEffectResources()
{
    if (definition == nullptr)
        return nullptr;
    if (!pooled_instances.empty())
    {
        auto effect = std::move(pooled_instances.back());
        pooled_instances.pop_back();
        effect->IEffect::operator=(*this);
        effect->resetRuntimeState();
        return effect;
    }
    auto effect = std::make_unique<CScriptedEffect>();
    effect->IEffect::operator=(*this);
    effect->definition = definition;
    CScriptedEffect::initialize_scripted_phase(*effect);
    effect->sound_effect = definition->sound == nullptr ? nullptr : definition->sound->createVoice();
    effect->lights.reserve(definition->lights.size());
    for (const auto &light : definition->lights)
        effect->lights.emplace_back(light);
    effect->meshes.reserve(definition->meshes.size());
    for (const auto &mesh : definition->meshes)
        effect->meshes.emplace_back(mesh);
    for (const auto &particle : definition->particles)
    {
        auto instance = std::make_unique<SferaParticleSystemInstance>(particle);
        instance->initializeClone();
        effect->particle_systems.push_back(std::move(instance));
    }

    for (auto &particle : effect->particle_systems)
        buildParticleChildren(*particle);
    return effect;
}

void CScriptedEffect::recycleEffect(std::unique_ptr<IEffect> effect) noexcept
{
    auto *instance = effect != nullptr ? effect->asScriptedEffect() : nullptr;
    if (instance == nullptr || instance->definition != definition || pooled_instances.size() >= 16)
        return;
    instance->stopResources();
    std::unique_ptr<CScriptedEffect> reusable(instance);
    effect.release();
    try
    {
        pooled_instances.push_back(std::move(reusable));
    }
    catch (const std::bad_alloc &)
    {
    }
}

bool CScriptedEffect::isEffectComplete() const
{
    return definition != nullptr && definition->completes_immediately;
}

CScriptedEffect::~CScriptedEffect()
{
    stopResources();
}

void CScriptedEffect::stopResources() noexcept
{
    if (sound_effect != nullptr)
        sound_effect->stop();
    for (auto &light : lights)
        light.stop();
}

void CScriptedEffect::prepare_particle_definition(const std::shared_ptr<SferaParticleSystemDefinition> &definition)
{
    SferaParticleSystemInstance initial(definition);
    initial.runtime_random_row = std::rand() % 254;
    initial.runtime_random_seed_0 = std::rand();
    initial.runtime_random_seed_1 = std::rand();
    if ((definition->flags & (1u << 6u)) != 0u)
    {
        const auto *random_values = SferaEffectHost::current().renderState().particle_random_table.data() + initial.runtime_random_row * 256u;
        SferaEffectAlgorithms::evaluate_particle_scalar(definition->lifetime_track.get(), 0.0f, initial.lifetime, random_values, initial.runtime_random_seed_0);
        SferaEffectAlgorithms::evaluate_random_vector(definition->emission_position_track.get(), 0.0f, initial.emitter_position, random_values, initial.runtime_random_seed_0,
                                                      initial.runtime_random_seed_1);
        for (std::size_t index = 0; index < initial.render_slots.size(); ++index)
            SferaEffectAlgorithms::particle_generate(initial, index);
        definition->lifetime = initial.lifetime;
        definition->emitter_position = initial.emitter_position;
        for (std::size_t index = 0; index < initial.render_slots.size(); ++index)
            definition->particles[index].initial = initial.render_slots[index].state;
    }
}
