#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iterator>
#include <utility>

#include "scene/SceneObject.h"
#include "collision/Collision.h"
#include "diagnostics/Diagnostics.h"
#include "geometry/Geometry.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/Model.h"
#include "scene/SceneAccess.h"
#include "spatial/Bounds.h"
#include "spatial/SpatialIndex.h"
#include "terrain/TerrainData.h"

bool SphereWorldBounds::intersects(const SphereWorldBounds &other) const
{
    return !(maximum.x < other.minimum.x || minimum.x > other.maximum.x || maximum.y < other.minimum.y || minimum.y > other.maximum.y || maximum.z < other.minimum.z || minimum.z > other.maximum.z);
}

bool SphereWorldBounds::intersectsInterior(const SphereWorldBounds &other) const
{
    return maximum.x > other.minimum.x && minimum.x < other.maximum.x && maximum.y > other.minimum.y && minimum.y < other.maximum.y && maximum.z > other.minimum.z && minimum.z < other.maximum.z;
}

bool SphereWorldBounds::contains(const SphereWorldBounds &other) const
{
    return !(other.minimum.x < minimum.x || other.minimum.y < minimum.y || other.minimum.z < minimum.z || other.maximum.x > maximum.x || other.maximum.y > maximum.y || other.maximum.z > maximum.z);
}

bool SphereWorldBounds::overlapsTriangle(const SferaVec3F (&vertices)[3]) const
{
    for (std::size_t axis = 0; axis < 3; ++axis)
    {
        if (minimum.component(axis) > vertices[0].component(axis) && minimum.component(axis) > vertices[1].component(axis) && minimum.component(axis) > vertices[2].component(axis))
            return false;
        if (maximum.component(axis) < vertices[0].component(axis) && maximum.component(axis) < vertices[1].component(axis) && maximum.component(axis) < vertices[2].component(axis))
            return false;
    }
    return true;
}

SphereWorldBounds SphereWorldBounds::expanded(float amount) const
{
    return {minimum - SferaVec3F{amount, amount, amount}, maximum + SferaVec3F{amount, amount, amount}};
}

SphereWorldBounds SphereWorldBounds::inverseTransformed(const SferaMatrix4x4F &transform) const
{
    auto points = corners();
    for (auto &point : points.corners)
        point = transform.inverseTransformPoint(point);
    SphereWorldBounds result;
    points.getExtents(result.minimum, result.maximum);
    return result;
}

SferaBoundsCornersRuntime SphereWorldBounds::corners() const
{
    return SferaBoundsCornersRuntime::fromExtents(minimum, maximum);
}

int SphereWorldWorldSpatialIndex::spatialCell(float coordinate, float radius)
{
    const double precise_coordinate = coordinate;
    return SferaNumeric::truncateInt((precise_coordinate + radius) * 0.11999999731779099 + 100000.0) - 100000;
}

SphereWorldSpatialLeaf *SphereWorldWorldSpatialIndex::leafAt(int cell_x, int cell_z)
{
    auto &cells = cells_;
    const auto found = cells.find({cell_x, cell_z});
    return found == cells.end() ? nullptr : &found->second;
}

bool SphereWorldWorldSpatialIndex::isTerrainCandidateForPatch(const TerrainPatch &patch, const SphereWorldTerrainCandidate &candidate)
{
    return candidate.patch == &patch;
}

void SphereWorldWorldSpatialIndex::forgetTerrain(const TerrainPatch &patch)
{
    std::erase_if(terrain_, std::bind_front(isTerrainCandidateForPatch, std::cref(patch)));
}

void SphereWorldWorldSpatialIndex::finishCandidates()
{
    for (const auto handle : objects_)
        SferaSceneAccess::object(handle)->visibility_mark = 0;
}

void SphereWorldWorldSpatialIndex::addTerrain(int terrain_key, int cell, float origin_x, float origin_z)
{
    auto *patch = &SferaTerrainSource::spatialPatch(terrain_key);
    terrain_.push_back({patch, &patch->cells[cell], origin_x, origin_z});
}

void SphereWorldWorldSpatialIndex::gatherCell(int cell_x, int cell_z, bool include_terrain)
{
    auto *cell = leafAt(cell_x, cell_z);
    if (!cell)
        return;
    for (const auto handle : cell->objects)
    {
        auto *object = SferaSceneAccess::object(handle);
        if (object->visibility_mark == 1u)
            continue;
        objects_.push_back(handle);
        object->visibility_mark = 1u;
    }
    if (cell->contains_landscape && include_terrain)
    {
        addTerrain(cell->terrain_key, (cell->quarter * 4 + cell->group) * 9 + cell->cell, cell->origin_x, cell->origin_z);
    }
}

void SphereWorldWorldSpatialIndex::gatherObject(std::uint32_t handle)
{
    const auto *object = SferaSceneAccess::object(handle);
    clearCandidates();
    if (object->grid_min_x == 1000000)
        return;
    for (int x = object->grid_min_x; x <= object->grid_max_x; ++x)
        for (int z = object->grid_min_y; z <= object->grid_max_y; ++z)
            gatherCell(x, z, object->position.y < 1000.0f);
    finishCandidates();
}

void SphereWorldWorldSpatialIndex::gatherObjects(const SferaVec3F &center, float radius)
{
    clearCandidates();
    const int min_x = SphereWorldWorldSpatialIndex::spatialCell(center.x, -radius), max_x = SphereWorldWorldSpatialIndex::spatialCell(center.x, radius),
              min_z = SphereWorldWorldSpatialIndex::spatialCell(center.z, -radius), max_z = SphereWorldWorldSpatialIndex::spatialCell(center.z, radius);
    for (int x = min_x; x <= max_x; ++x)
        for (int z = min_z; z <= max_z; ++z)
            gatherCell(x, z, false);
    finishCandidates();
}

void SphereWorldWorldSpatialIndex::insert(std::uint32_t handle, int cell_x, int cell_z)
{
    if (cell_x < -512 || cell_x >= 512 || cell_z < -512 || cell_z >= 512)
        return;
    const auto [position, inserted] = cells_.try_emplace(std::pair{cell_x, cell_z});
    auto &leaf = position->second;
    const auto existing = std::find(leaf.objects.begin(), leaf.objects.end(), handle);
    if (existing != leaf.objects.end())
        std::rotate(existing, existing + 1, leaf.objects.end());
    else
    {
        try
        {
            leaf.objects.push_back(handle);
        }
        catch (...)
        {
            if (inserted)
                cells_.erase(position);
            throw;
        }
    }
    SphereWorldWorldSpatialIndex::bindTerrainCell(leaf, cell_x, cell_z);
}

void SphereWorldWorldSpatialIndex::gatherTerrain(const SferaVec3F &center, float radius)
{
    terrain_.clear();
    const int min_x = SphereWorldWorldSpatialIndex::spatialCell(center.x, -radius), max_x = SphereWorldWorldSpatialIndex::spatialCell(center.x, radius);
    const int min_z = SphereWorldWorldSpatialIndex::spatialCell(center.z, -radius), max_z = SphereWorldWorldSpatialIndex::spatialCell(center.z, radius);
    for (int x = min_x; x <= max_x; ++x)
        for (int z = min_z; z <= max_z; ++z)
        {
            SphereWorldSpatialLeaf location;
            SphereWorldWorldSpatialIndex::bindTerrainCell(location, x, z);
            if (location.terrain_key >= 0)
                addTerrain(location.terrain_key, (location.quarter * 4 + location.group) * 9 + location.cell, location.origin_x, location.origin_z);
        }
}

void SphereWorldWorldSpatialIndex::refreshTerrainBindings() noexcept
{
    terrain_.clear();
    shadow_vertices_.clear();
    for (auto &[key, leaf] : cells_)
        SphereWorldWorldSpatialIndex::bindTerrainCell(leaf, key.first, key.second);
}

void SphereWorldWorldSpatialIndex::remove(std::uint32_t handle, int cell_x, int cell_z)
{
    if (cell_x < -512 || cell_x >= 512 || cell_z < -512 || cell_z >= 512)
        return;
    auto &cells = cells_;
    const auto found = cells.find({cell_x, cell_z});
    if (found == cells.end())
    {
        SferaEngineDiagnostics::warning("Spatial cell is not registered");
        return;
    }
    auto &leaf = found->second;
    const auto object = std::find(leaf.objects.begin(), leaf.objects.end(), handle);
    if (object == leaf.objects.end())
    {
        SferaEngineDiagnostics::warning("Object is not registered in the spatial cell");
        return;
    }
    leaf.objects.erase(object);
    if (leaf.objects.empty())
        cells.erase(found);
}

auto SphereWorldWorldSpatialIndex::appendShadowTriangle(const SphereRenderModelCollisionTriangle &triangle)
{
    shadow_vertices_.insert(shadow_vertices_.end(), std::begin(triangle.vertices), std::end(triangle.vertices));
}

std::uint32_t SphereWorldWorldSpatialIndex::gatherShadowTriangles(const SphereWorldBounds &bounds, const SferaVec3F &center, float radius, const SferaVec3F &origin, const SferaVec3F &direction)
{
    shadow_vertices_.clear();

    gatherTerrain(center, radius);
    bool full = false;
    for (const auto &candidate : terrain_)
    {
        for (std::size_t index = 0; index < candidate.cell->triangles.size(); ++index)
        {
            const auto triangle = SphereCollisionGeometry::terrainTriangle(candidate, candidate.cell->triangles[index]);
            if (!bounds.overlapsTriangle(triangle.vertices) || triangle.normal.dot(direction) < 0.0 || triangle.normal.dot(origin - triangle.vertices[0]) < 0.699999988079071)
                continue;
            appendShadowTriangle(triangle);
            if (shadow_vertices_.size() / 3u == 300u)
            {
                full = true;
                break;
            }
        }
        if (full)
            break;
    }
    if (!full)
    {
        gatherObjects(center, radius);
        for (const auto handle : objects_)
        {
            auto *object = SferaSceneAccess::object(handle);
            const auto *model = SferaSceneAccess::model(*object);
            if (!model->casts_static_shadow)
                continue;
            SphereWorldContactQuery::updateBounds(handle);
            const auto local_origin = object->world_transform.inverseTransformPoint(origin);
            const auto local_direction = SphereCollisionGeometry::rotationOnly(object->world_transform).inverseTransformPoint(direction);
            const auto local_bounds = bounds.inverseTransformed(object->world_transform);
            for (std::size_t group_index = 0; group_index < model->collision_groups.size(); ++group_index)
            {
                const auto &group = model->collision_groups[group_index];
                for (std::size_t index = 0; index < group.triangle_count; ++index)
                {
                    const auto &triangle = model->collision_triangles[group.first_triangle + index];
                    if (!local_bounds.intersects({triangle.minimum, triangle.maximum}) || triangle.normal.dot(local_direction) < 0.0 ||
                        triangle.normal.dot(local_origin - triangle.vertices[0]) < 0.699999988079071)
                        continue;
                    appendShadowTriangle(SphereCollisionGeometry::worldTriangle(triangle, object->world_transform));
                    if (shadow_vertices_.size() / 3u == 300u)
                    {
                        full = true;
                        break;
                    }
                }
                if (full)
                    break;
            }
            if (full)
                break;
        }
    }
    const auto camera = SferaSceneAccess::cameraObject()->position;
    for (auto &point : shadow_vertices_)
        point = point + (camera - point) * 0.014999999664723873f;
    return SferaNumeric::lowWord(shadow_vertices_.size() / 3u);
}
