#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <limits>
#include <memory>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "scene/SceneObject.h"
#include "environment/Environment.h"
#include "math/MathFunctions.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "render/Model.h"
#include "runtime/Clock.h"
#include "scene/SceneAccess.h"
#include "vegetation/Vegetation.h"
#include "vegetation/VegetationGeometry.h"

SphereWorldDynamicVegetation::SphereWorldDynamicVegetation(std::span<SphereWorldGrassCell> cells) : cells_(cells)
{
    initializeNoise();
}

void SphereWorldDynamicVegetation::initializeNoise()
{
    std::array<SphereWorldDynamicVegetationHarmonic, 100> harmonics;
    for (std::size_t index = 0; index < harmonics.size(); ++index)
    {
        auto &harmonic = harmonics[index];
        harmonic.frequency = SferaNumeric::lowWord(index + 1u);
        harmonic.phase = SphereVegetationHelpers::vegetationRandom(6.2831854820251465);
        harmonic.amplitude = SphereVegetationHelpers::vegetationRandom(1, 1);
    }
    float maximum = -1.0f;
    for (std::size_t index = 0; index < noise_.size(); ++index)
    {
        const float angle = SferaNumeric::real32(index * 0.006135923322290182);
        float sum = 0.0f;
        for (const auto &harmonic : harmonics)
        {
            const float rounded_phase = SferaNumeric::real32(harmonic.frequency * angle + harmonic.phase);
            const double phase = rounded_phase;
            const float sine = SferaNumeric::real32(std::sin(phase));
            sum = SferaNumeric::real32(sine * harmonic.amplitude + sum);
        }
        noise_[index] = sum;
        maximum = std::max(maximum, std::fabs(sum));
    }
    const float rounded_scale = SferaNumeric::real32(1.0 / maximum);
    const double scale = rounded_scale;
    for (auto &value : noise_)
        value = SferaNumeric::real32(value * scale);
}

void SphereWorldDynamicVegetation::updateWind(const SferaVec3F &reference, float elapsed)
{
    const double strength = wind_strength_, windX = wind_.x, windZ = wind_.z;
    phase_speed_ = SferaNumeric::real32(strength * 2 + 1);
    bend_x_ = SferaNumeric::real32(windX * strength * 0.30000001192092896);
    bend_z_ = SferaNumeric::real32(windZ * strength * 0.30000001192092896);
    for (auto &gust : gusts_)
    {
        const float dx = gust.x - reference.x, dz = gust.z - reference.z;
        if (!gust.active || SferaMath::planarSquared(dx, dz) > 2600.0)
        {
            gust.active = true;
            gust.speed = SphereVegetationHelpers::vegetationRandom(0.5, 1.5);
            const float transverse = SphereVegetationHelpers::vegetationRandom(40, -20);
            gust.x = SferaNumeric::real32(reference.x - windX * 30 - windZ * transverse);
            gust.z = SferaNumeric::real32(reference.z - windZ * 30 + windX * transverse);
            gust.radius = SphereVegetationHelpers::vegetationRandom(4, 2);
            const double radius = gust.radius;
            gust.radius_squared = SferaNumeric::real32(radius * radius);
        }
        gust.x = SferaNumeric::real32(windX * wind_strength_ * gust.speed * elapsed * 4 + gust.x);
        gust.z = SferaNumeric::real32(windZ * wind_strength_ * gust.speed * elapsed * 4 + gust.z);
    }
}

SferaVec3F SphereWorldDynamicVegetation::bendingPosition(const SphereRenderModel &model, std::size_t vertex, float first, float second) const
{
    const auto &influence = model.grass()->influences[vertex];
    const auto &basis = model.grass()->bending[vertex];
    const auto &anchor = model.vertices[influence.anchor_vertex].position;
    const auto displacement = ((model.vertices[vertex].position - anchor) + basis.first_axis * first) + basis.second_axis * second;
    return (displacement).unit<double, float>(0.0f, SferaVec3F{}) * influence.distance + anchor;
}

void SphereWorldDynamicVegetation::deformGrass(SphereRenderModel &model, const SferaVec3F &position)
{
    if (!model.grass())
        return;
    output_.resize(model.vertices.size());
    const double animation_phase = phase_;
    std::vector<const SphereWorldDynamicVegetationGust *> gusts;
    for (const auto &gust : gusts_)
        if (gust.active && position.x + 8 > gust.x - gust.radius && position.x - 8 < gust.x + gust.radius && position.z + 8 > gust.z - gust.radius && position.z - 8 < gust.z + gust.radius)
            gusts.push_back(&gust);
    const SphereWorldDynamicVegetationGust *selected_gust = nullptr;
    for (std::size_t index = 0; index < model.vertices.size(); ++index)
    {
        const auto &vertex = model.vertices[index];
        const auto &influence = model.grass()->influences[index];
        auto &output = output_[index];
        output = {vertex.position, vertex.normal};
        if (influence.anchor_kind == SphereRenderGrassInfluenceAnchor::Fixed)
            continue;
        if (!influence.share_phase)
        {
            selected_gust = nullptr;
            for (const auto *gust : gusts)
            {
                const float dx = vertex.position.x - (gust->x - position.x), dz = vertex.position.z - (gust->z - position.z);
                if (SferaMath::planarSquared(dx, dz) < gust->radius_squared)
                {
                    selected_gust = gust;
                    break;
                }
            }
        }
        if (influence.anchor_kind == SphereRenderGrassInfluenceAnchor::Horizontal)
        {
            const int step = SferaNumeric::truncateInt(std::trunc(animation_phase * phase_speed_));
            const int phase = step + influence.phase;
            const double noise = noise_[phase & 1023];
            const float factor = SferaNumeric::real32((noise + 1) * 0.5 * (selected_gust ? 0.25 : 0.15000000596046448) * phase_speed_);
            output.position = vertex.position + (model.grass()->bending[index].anchor - vertex.position) * factor;
            if (selected_gust)
                output.normal = output.normal * 0.800000011920929f;
        }
        else
        {
            const int step = SferaNumeric::truncateInt(std::trunc(animation_phase * phase_speed_ * (selected_gust ? -3.0 : 1.0)));
            const int phase = influence.phase + (selected_gust ? -step : step);
            const float first = SferaNumeric::real32(noise_[phase & 1023] * 0.05999999865889549 * phase_speed_ + (selected_gust ? bend_x_ : 0));
            const float second = SferaNumeric::real32(noise_[(phase - 512) & 1023] * 0.05999999865889549 * phase_speed_ * 0.5 + (selected_gust ? bend_z_ : 0));
            output.position = bendingPosition(model, index, first, second);
            if (selected_gust)
                output.normal = output.normal * 0.75f;
        }
        if (!model.cached_vegetation_vertices.empty())
            output.position = model.cached_vegetation_vertices[index].position + (output.position - model.cached_vegetation_vertices[index].position) * 0.15000000596046448f;
    }
}

void SphereWorldDynamicVegetation::saveCache(SphereRenderModel &model)
{
    if (output_.size() != model.vertices.size())
        throw std::logic_error("Vegetation cache does not match model geometry");
    model.cached_vegetation_vertices = output_;
}

void SphereWorldDynamicVegetation::recalculate()
{
    for (const auto &cell : cells_)
    {
        if (cell.object_handle == 0u)
            continue;
        const auto *object = SferaSceneAccess::object(cell.object_handle);
        auto *model = object ? SferaSceneAccess::model(*object) : nullptr;
        if (model == nullptr)
            continue;
        deformGrass(*model, object->position);
        saveCache(*model);
    }
}

void SphereWorldDynamicVegetation::update()
{
    const std::int64_t now = WorldClock::nowTicks();
    const float frame_interval = SferaNumeric::real32((now - last_update_) / 2000.0);
    const float elapsed = std::min(2.0f, frame_interval);
    last_update_ = now;
    const double advance = elapsed;
    phase_ = SferaNumeric::real32(phase_ + advance);
    updateWind(reference_, elapsed);
    recalculate();
}

std::int64_t SphereWorldDynamicVegetation::last_update_ = 0;

auto SphereWorldGrassGeometry::appendGrassSubmesh(std::span<const SphereWorldGrassInstance> instances, std::size_t maximum_group_vertices, std::size_t &next_vertex, std::size_t vertex_count,
                                                  std::size_t &next_face, std::size_t face_count, std::vector<std::vector<bool>> &consumed, const std::unique_ptr<SphereRenderModel> &result,
                                                  const std::vector<std::uint16_t> &phases, std::vector<std::size_t> &instance_indices, std::vector<std::vector<std::size_t>> &vertex_indices,
                                                  std::size_t instance_index, std::size_t submesh_index, SphereRenderSubmesh &group)
{
    const auto &instance = instances[instance_index];
    const auto &model = *instance.model;
    const auto &source = model.submeshes[submesh_index];
    if (source.vertex_count > maximum_group_vertices - group.vertex_count || next_vertex > vertex_count || source.vertex_count > vertex_count - next_vertex || next_face > face_count ||
        source.face_count > face_count - next_face)
        throw std::length_error("Grass submesh exceeds its buffers");
    const auto transform = SferaMatrix4x4F::fromEuler(instance.position, instance.rotation);
    consumed[instance_index][submesh_index] = true;
    for (std::size_t index = 0; index < source.vertex_count; ++index)
    {
        const std::size_t source_index = source.first_vertex + index;
        const std::size_t destination = next_vertex + index;
        result->vertices[destination] = model.vertices[source_index];
        auto &vertex = result->vertices[destination];
        const double source_y = vertex.position.y;
        vertex.position.y = SferaNumeric::real32(source_y * instance.vertical_scale);
        vertex.position = transform.transformPoint(vertex.position);
        vertex.normal = instance.normal;
        auto &influence = result->grass()->influences[destination];
        influence = model.grass()->influences[source_index];
        influence.phase = influence.phase + phases[instance_index];
        const double source_distance = influence.distance;
        influence.distance = SferaNumeric::real32(source_distance * instance.vertical_scale);
        instance_indices[destination] = instance_index;
        vertex_indices[instance_index][source_index] = destination;
        const auto &anchor = model.vertices[source_index].position;
        result->grass()->bending[destination].anchor = transform.transformPoint({anchor.x, -0.15000000596046448f, anchor.z});
    }
    for (std::size_t index = 0; index < source.face_count; ++index)
    {
        auto &face = result->faces[next_face + index];
        face = model.faces[source.first_face + index];
        for (auto &vertex : face.vertices)
            vertex = SferaNumeric::lowHalf(SferaNumeric::lowWord(vertex + next_vertex - group.first_vertex));
    }
    group.face_count += source.face_count;
    group.vertex_count += source.vertex_count;
    next_vertex += source.vertex_count;
    next_face += source.face_count;
}

std::unique_ptr<SphereRenderModel> SphereWorldGrassGeometry::build(std::span<const SphereWorldGrassInstance> instances, float height)
{
    std::size_t vertex_count = 0, face_count = 0;
    std::vector<std::vector<std::size_t>> vertex_indices;
    std::vector<std::vector<bool>> consumed;
    std::vector<std::uint16_t> phases;
    for (const auto &instance : instances)
    {
        if (!instance.model || !instance.model->grass())
        {
            SphereVegetationHelpers::vegetationError(std::string("dg_type parameter not filled in mdlprms.txt for model  ") + (instance.model ? instance.model->name : "<null>"));
            throw std::runtime_error("Missing grass influences");
        }
        for (std::size_t part = 0; part < instance.model->submeshes.size(); ++part)
        {
            const auto &source = instance.model->submeshes[part];
            if (source.first_vertex > instance.model->vertices.size() || source.vertex_count > instance.model->vertices.size() - source.first_vertex ||
                source.first_face > instance.model->faces.size() || source.face_count > instance.model->faces.size() - source.first_face)
                throw std::out_of_range("Grass source submesh range");
            if (source.vertex_count > std::numeric_limits<std::size_t>::max() - vertex_count || source.face_count > std::numeric_limits<std::size_t>::max() - face_count)
                throw std::length_error("Grass geometry is too large");
            vertex_count += source.vertex_count;
            face_count += source.face_count;
        }
        vertex_indices.emplace_back(instance.model->vertices.size(), 0);
        consumed.emplace_back(instance.model->submeshes.size(), false);
    }
    auto result = std::make_unique<SphereRenderModel>();
    result->initializeGrassGeometry(vertex_count, face_count, height);
    for (const auto &instance : instances)
    {
        for (const auto &catalogue : instance.model->material_lifetimes)
        {
            if (std::find(result->material_lifetimes.begin(), result->material_lifetimes.end(), catalogue) == result->material_lifetimes.end())
                result->material_lifetimes.push_back(catalogue);
        }
    }
    for (std::size_t index = 0; index < instances.size(); ++index)
        phases.push_back(SferaNumeric::lowHalf(SferaNumeric::lowWord(std::rand())));
    constexpr std::size_t maximum_group_vertices = std::size_t{std::numeric_limits<std::uint16_t>::max()} + 1;
    std::vector<SphereRenderSubmesh> groups;
    std::vector<std::size_t> instance_indices(vertex_count, 0);
    std::size_t next_vertex = 0, next_face = 0;

    for (std::size_t instance = 0; instance < instances.size(); ++instance)
    {
        for (std::size_t submesh = 0; submesh < instances[instance].model->submeshes.size(); ++submesh)
        {
            if (consumed[instance][submesh])
                continue;
            const auto &source = instances[instance].model->submeshes[submesh];
            SphereRenderSubmesh group;
            group.bone_index = 0u;
            group.inverted_fade = source.inverted_fade;
            group.material = source.material;
            group.first_vertex = next_vertex;
            group.first_face = next_face;
            appendGrassSubmesh(instances, maximum_group_vertices, next_vertex, vertex_count, next_face, face_count, consumed, result, phases, instance_indices, vertex_indices, instance, submesh,
                               group);
            for (std::size_t other = 0; other < instances.size(); ++other)
            {
                for (std::size_t part = 0; part < instances[other].model->submeshes.size(); ++part)
                {
                    const auto &candidate = instances[other].model->submeshes[part];
                    if (!consumed[other][part] && candidate.material == group.material && candidate.inverted_fade == group.inverted_fade &&
                        candidate.vertex_count <= maximum_group_vertices - group.vertex_count)
                        appendGrassSubmesh(instances, maximum_group_vertices, next_vertex, vertex_count, next_face, face_count, consumed, result, phases, instance_indices, vertex_indices, other, part,
                                           group);
                }
            }
            groups.push_back(group);
        }
    }
    for (std::size_t index = 0; index < next_vertex; ++index)
    {
        auto &influence = result->grass()->influences[index];
        if (influence.anchor_kind == SphereRenderGrassInfluenceAnchor::Vertex)
            influence.anchor_vertex = vertex_indices[instance_indices[index]].at(influence.anchor_vertex);
    }
    for (std::size_t index = 0; index < next_vertex; ++index)
    {
        const auto &influence = result->grass()->influences[index];
        if (influence.anchor_kind != SphereRenderGrassInfluenceAnchor::Vertex)
            continue;
        const auto direction = result->vertices[index].position - result->vertices[influence.anchor_vertex].position;
        auto &basis = result->grass()->bending[index];
        basis.first_axis = (SferaVec3F{0, 0, 1}.cross(direction)).unit<double, float>(0.0f, SferaVec3F{}) * influence.distance;
        basis.second_axis = (direction.cross({1, 0, 0})).unit<double, float>(0.0f, SferaVec3F{}) * influence.distance;
    }
    result->finishGrassGeometry(groups);
    return result;
}

std::uint8_t GrassMapMngr::sample(float x, float z)
{
    if (!std::isfinite(x) || !std::isfinite(z) || x < -4002.0f || x > 4002.0f || z < -4002.0f || z > 4002.0f)
        return 0;
    const int column = SferaNumeric::truncateInt(std::trunc((x + 4000.0) * 0.5120000243186951));
    const int row = SferaNumeric::truncateInt(std::trunc((4000.0 - z) * 0.5120000243186951));
    if (column > 4095u || row > 4095u)
        return 0;
    if (!tiles_)
        tiles_ = std::make_unique<std::array<GrassMapMngrTile, 10>>();
    const auto key = std::pair{column / 256, row / 256};
    if (timestamp_ == UINT64_MAX)
    {
        for (auto &tile : *tiles_)
            tile.timestamp = 0;
        timestamp_ = 0;
    }
    ++timestamp_;
    auto found = std::find_if(tiles_->begin(), tiles_->end(), std::bind_front(matchesGrassTile, key));
    if (found == tiles_->end())
    {
        found = std::min_element(tiles_->begin(), tiles_->end(), isOlderGrassTile);
        auto replacement = std::make_unique<GrassMapMngrTile>();
        replacement->key = key;
        loadGrassMap(key.first, key.second, replacement->bytes);
        *found = std::move(*replacement);
    }
    found->timestamp = timestamp_;
    return found->bytes[(row & 255) * 256 + (column & 255)];
}

GrassMapMngr *GrassMapMngr::reset()
{
    tiles_.reset();
    timestamp_ = 0;
    return this;
}

void SphereWorldVegetation::clear()
{
    animation.reset();
    cells_.clear();
    previous_.clear();
    occupancy_.clear();
}

void SphereWorldVegetation::updateCells()
{
    if (++update_phase_ < 5u)
        return;
    update_phase_ = 0;
    const std::uint32_t depth = g_sfera_graphics_runtime.grass_depth;
    const bool enabled = depth != 0 && previous_depth_ == 0;
    const bool disabled = depth == 0 && previous_depth_ != 0;
    previous_depth_ = depth;
    const auto side = grid_side;
    const auto count = side * side;
    auto *cells = cells_.data();
    if (cells_.empty())
        return;
    if (disabled)
        for (std::uint32_t index = 0; index < count; ++index)
            destroyOwnedModel(cells[index].object_handle);
    if (!depth)
        return;
    const auto &position = SferaSceneAccess::cameraObject()->position;
    g_sfera_vegetation.animation->setReference(position);
    if (enabled)
    {
        last_cell_x_ = 1000000;
        last_cell_z_ = 1000000;
    }
    const auto x = SferaNumeric::truncateInt(position.x * 0.11999999731779099 + 100000.0) - 100000;
    const auto z = SferaNumeric::truncateInt(position.z * 0.11999999731779099 + 100000.0) - 100000;
    const auto dx = x - last_cell_x_, dz = z - last_cell_z_;
    if (!dx && !dz)
        return;
    auto *previous = previous_.data();
    auto *occupancy = occupancy_.data();
    std::copy_n(cells, count, previous);
    std::fill_n(occupancy, count, std::array<bool, 2>{});
    if (std::abs(dx) <= 1 && std::abs(dz) <= 1)
    {
        for (int row = 0; row < side; ++row)
        {
            for (int column = 0; column < side; ++column)
            {
                const auto source_x = column + dx, source_z = row + dz;
                if (source_x < 0 || source_z < 0 || source_x >= side || source_z >= side)
                    continue;
                const auto source = source_z * side + source_x, destination = row * side + column;
                cells[destination] = previous[source];
                occupancy[source][0] = 1;
                occupancy[destination][1] = 1;
            }
        }
    }
    for (std::uint32_t index = 0; index < count; ++index)
        if (!occupancy[index][0])
            destroyOwnedModel(previous[index].object_handle);
    const int half = (side - 1u) / 2u;
    for (std::uint32_t row = 0; row < side; ++row)
        for (std::uint32_t column = 0; column < side; ++column)
        {
            const auto index = row * side + column;
            if (!occupancy[index][1])
                createCell(x - half + column, z - half + row, cells[index]);
        }
    last_cell_x_ = x;
    last_cell_z_ = z;
}

void SphereWorldVegetation::updateGrassView()
{
    const double factor = g_sfera_weather_runtime.current.wind;
    const double direction_x = g_sfera_weather_runtime.current.windX, direction_z = g_sfera_weather_runtime.current.windZ;
    float shift_x = 0, shift_z = 0;
    if (factor <= 1)
    {
        shift_x = SferaNumeric::real32(direction_x * factor);
        shift_z = SferaNumeric::real32(direction_z * factor);
    }
    else
    {
        const float squared = SferaNumeric::real32(SferaMath::planarSquared(direction_x, direction_z));
        const float length = std::sqrt(squared);
        if (std::fabs(length) >= 0.000009999999747378752f)
        {
            const float distance = SferaNumeric::real32((factor - 1) * (0.00019999999494757503 - length) + length);
            shift_x = SferaNumeric::real32(direction_x / length * distance);
            shift_z = SferaNumeric::real32(direction_z / length * distance);
        }
    }
    auto &x = SceneSky::cloud_offset_x;
    auto &z = SceneSky::cloud_offset_y;
    x += shift_x;
    z += shift_z;
    if (x >= 1)
        x -= 1;
    if (x < 0)
        x += 1;
    if (z >= 1)
        z -= 1;
    if (z < 0)
        z += 1;
    if (g_sfera_vegetation.animation && g_sfera_graphics_runtime.grass_depth == 2)
        g_sfera_vegetation.animation->initializeWind();
}

float SphereVegetationHelpers::vegetationRandom(double scale, double offset)
{
    return SferaNumeric::real32(std::rand() * scale / 32767.0 + offset);
}

void SphereWorldVegetationPatterns::addGrass(std::uint32_t id, const std::array<std::string_view, 10> &variants)
{
    if (grass_patterns_.size() >= 30u)
    {
        SphereVegetationHelpers::vegetationError("GRASS_PATTERNS_NUM exeeded");
        return;
    }
    SphereWorldVegetationPatternsGrassPattern pattern{id, {}};
    std::copy(variants.begin(), variants.end(), pattern.variants.begin());
    grass_patterns_.push_back(std::move(pattern));
}

const SphereWorldVegetationPatternsGrassPattern &SphereWorldVegetationPatterns::grass(std::uint32_t id) const
{
    const auto found = std::find_if(grass_patterns_.begin(), grass_patterns_.end(), std::bind_front(hasGrassPatternId, id));
    if (found == grass_patterns_.end())
    {
        SphereVegetationHelpers::vegetationError("Grass pattern not found. Type=" + std::to_string(id));
        throw std::out_of_range("Grass pattern");
    }
    return *found;
}
