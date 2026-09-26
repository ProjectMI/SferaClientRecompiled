#include <windows.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <d3d9.h>
#include <functional>
#include <iterator>
#include <limits>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

#include "scene/SceneObject.h"
#include "algorithms/StableSort.h"
#include "diagnostics/Diagnostics.h"
#include "environment/Environment.h"
#include "geometry/Geometry.h"
#include "graphics/d3d9/Device.h"
#include "input/DirectInputDevices.h"
#include "lighting/LightRuntime.h"
#include "math/Color.h"
#include "math/MathFunctions.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "render/SceneRenderer.h"
#include "render/TextureAccess.h"
#include "render/Textures.h"
#include "render/VertexFormats.h"
#include "scene/SceneAccess.h"
#include "terrain/Terrain.h"
#include "terrain/TerrainData.h"
#include "text/Text.h"

void TerrainBounds::lowerMinimum(float height)
{
    if (corners[2].y <= height)
        return;
    for (int index : {2, 3, 6, 7})
        corners[index].y = height;
    scaledBounds[2] = SferaNumeric::truncateInt(std::trunc(height * 1024.0));
}

void TerrainGroupBuilder::append(const TerrainPatch &patch, const TerrainCell &cell)
{
    if (cell.x < 0 || cell.x >= 12 || cell.z < 0 || cell.z >= 12)
        throw std::runtime_error("Invalid terrain surface cell");
    std::unordered_map<std::uint16_t, std::uint16_t> remap;
    const auto firstVertex = vertices.size();
    const auto firstIndex = indices.size();
    for (std::size_t i = 0; i < cell.triangles.size(); ++i)
        for (auto index : cell.triangles[i].indices)
        {
            if (index >= patch.vertices.size())
                throw std::runtime_error("Terrain triangle vertex is outside the vertex array");
            auto [entry, inserted] = remap.emplace(index, SferaNumeric::lowHalf(SferaNumeric::lowWord(remap.size())));
            if (inserted)
                vertices.push_back(patch.vertices[index]);
            indices.push_back(entry->second);
        }
    auto &group = groups[cell.x + 12 * cell.z];
    group.vertexCount = remap.size();
    group.firstVertex = firstVertex;
    group.firstIndex = firstIndex;
}

void TerrainPatch::terrainSmoothNormals(const std::vector<TerrainVertex *> &vertices)
{
    std::vector<bool> used(vertices.size());
    for (std::size_t i = 0; i < vertices.size(); ++i)
    {
        if (used[i])
            continue;
        std::vector<std::size_t> group{i};
        auto sum = vertices[i]->normal;
        used[i] = true;
        for (std::size_t j = i + 1; j < vertices.size(); ++j)
        {
            if (used[j])
                continue;
            const auto &a = vertices[i]->position;
            const auto &b = vertices[j]->position;
            const float compatibility = SferaNumeric::real32(a.dot<double, true>(b));
            if (compatibility < 0.0f)
                continue;
            used[j] = true;
            group.push_back(j);
            sum.x += vertices[j]->normal.x;
            sum.y += vertices[j]->normal.y;
            sum.z += vertices[j]->normal.z;
        }
        const float length = sum.length<double, float, true>();
        const float inverse = 1.0f / length;
        sum.x *= inverse;
        sum.y *= inverse;
        sum.z *= inverse;
        for (auto index : group)
            vertices[index]->normal = sum;
    }
}

void TerrainPatch::updateBounds()
{
    for (int group = 0; group < 16; ++group)
        for (int cell = 0; cell < 9; ++cell)
            groupBounds[group].lowerMinimum(cellBounds[group * 9 + cell].corners[2].y);
    for (int quarter = 0; quarter < 4; ++quarter)
        for (int group = 0; group < 4; ++group)
            quarterBounds[quarter].lowerMinimum(groupBounds[quarter * 4 + group].corners[2].y);
    for (const auto &quarter : quarterBounds)
        bounds.lowerMinimum(quarter.corners[2].y);
}

void TerrainPatch::partitionEdges()
{
    if (vertices.size() > 65536u)
        throw std::runtime_error("Invalid landscape vertex count");
    std::vector<bool> membership(vertices.size());

    for (std::size_t corner = 0; corner < 4; ++corner)
    {
        std::vector<std::size_t> indices;
        const float x = corner % 2 ? 100.0f : 0.0f;
        const float z = corner < 2 ? 100.0f : 0.0f;
        for (std::size_t i = 0; i < vertices.size(); ++i)
            if (nearEdgeBoundary(vertices[i].position.x, x) && nearEdgeBoundary(vertices[i].position.z, z))
            {
                indices.push_back(i);
                membership[i] = true;
            }
        cornerIndices[corner] = std::move(indices);
    }
    for (std::size_t side = 0; side < 4; ++side)
    {
        std::vector<TerrainPatchGroup> groups;
        const bool horizontal = side < 2;
        const float boundary = side == 0 || side == 3 ? 100.0f : 0.0f;
        for (std::size_t i = 0; i < vertices.size(); ++i)
        {
            const auto &position = vertices[i].position;
            if (membership[i] || !nearEdgeBoundary(horizontal ? position.z : position.x, boundary))
                continue;
            membership[i] = true;
            TerrainPatchGroup group{horizontal ? position.x : position.z, {i}};
            for (std::size_t j = i + 1; j < vertices.size(); ++j)
            {
                const auto &candidate = vertices[j].position;
                if (membership[j] || candidate.x != position.x || candidate.y != position.y || candidate.z != position.z)
                    continue;
                membership[j] = true;
                group.indices.push_back(j);
            }
            groups.push_back(std::move(group));
        }
        SferaAlgorithms::stableSort(groups, edgeGroupCoordinate);
        auto &edge = edgeGroups[side];
        edge.clear();
        edge.reserve(groups.size());
        for (auto &group : groups)
            edge.push_back(std::move(group.indices));
    }
}

void TerrainPatch::rebuildSurfaceGroups()
{
    TerrainGroupBuilder builder{{}, {}, surfaceGroups};
    for (const auto &cell : cells)
        builder.append(*this, cell);
    surfaceGroups = builder.groups;
    groupedVertices = std::move(builder.vertices);
    groupedIndices = std::move(builder.indices);
}

bool TerrainPatch::validateEdge(const TerrainPatch &other, std::size_t side, std::size_t otherSide) const
{
    const auto &first = edgeGroups.at(side);
    const auto &second = other.edgeGroups.at(otherSide);
    std::vector<bool> matched(second.size());
    bool valid = true;
    for (const auto &group : first)
    {
        const auto &point = vertices[group.front()].position;
        bool found = false;
        for (std::size_t i = 0; i < second.size(); ++i)
        {
            const auto &candidate = other.vertices[second[i].front()].position;
            if (candidate.y == point.y && (side < 2 ? candidate.x == point.x : candidate.z == point.z))
            {
                matched[i] = true;
                found = true;
                break;
            }
        }
        if (!found)
            valid = false;
    }
    for (std::size_t i = 0; i < second.size(); ++i)
        if (!matched[i])
        {
            valid = false;
        }
    return valid;
}

bool TerrainPatch::smoothEdge(TerrainPatch &other, std::size_t side, std::size_t otherSide)
{
    if (!validateEdge(other, side, otherSide))
        return false;
    const auto &first = edgeGroups.at(side);
    const auto &second = other.edgeGroups.at(otherSide);
    if (first.size() != second.size())
        throw std::runtime_error("Error of smoothing region's edge: numbers of vertex groups are differ");
    for (std::size_t i = 0; i < first.size(); ++i)
    {
        std::vector<TerrainVertex *> group;
        for (auto index : first[i])
            group.push_back(&vertices[index]);
        for (auto index : second[i])
            group.push_back(&other.vertices[index]);
        TerrainPatch::terrainSmoothNormals(group);
    }
    return true;
}

auto TerrainPatch::appendCornerVertices(std::vector<TerrainVertex *> &group, TerrainPatch *patch, std::size_t index)
{
    if (!patch)
        return;
    if (index >= 4)
        throw std::out_of_range("Landscape corner index");
    for (const auto vertex : patch->cornerIndices[index])
    {
        if (vertex >= patch->vertices.size())
            throw std::runtime_error("Landscape corner vertex index");
        group.push_back(&patch->vertices[vertex]);
    }
}

void TerrainPatch::smoothCorner(TerrainPatch *diagonal, TerrainPatch *vertical, TerrainPatch *horizontal, std::size_t corner, std::size_t diagonalCorner, std::size_t verticalCorner,
                                std::size_t horizontalCorner)
{
    if (!diagonal && !vertical && !horizontal)
        return;
    std::vector<TerrainVertex *> group;
    appendCornerVertices(group, this, corner);
    appendCornerVertices(group, diagonal, diagonalCorner);
    appendCornerVertices(group, vertical, verticalCorner);
    appendCornerVertices(group, horizontal, horizontalCorner);
    TerrainPatch::terrainSmoothNormals(group);
    if (diagonal)
        diagonal->cornerSmoothed[diagonalCorner] = true;
    if (vertical)
        vertical->cornerSmoothed[verticalCorner] = true;
    if (horizontal)
        horizontal->cornerSmoothed[horizontalCorner] = true;
}

float TerrainPatch::edgeGroupCoordinate(const TerrainPatchGroup &group)
{
    return group.coordinate;
}

SferaPlaneF TerrainQueries::terrainPlane(const SferaVec3F &normal, const SferaVec3F &point)
{
    return SferaPlaneF::throughPoint(normal, point);
}

int TerrainQueriesLocation::cellIndex() const
{
    const int quarter = (cellZ / 6) * 2 + cellX / 6;
    const int group = (cellZ / 3 % 2) * 2 + cellX / 3 % 2;
    return (quarter * 4 + group) * 9 + (cellZ % 3) * 3 + cellX % 3;
}

TerrainQueriesLocation TerrainQueries::locate(float worldX, float worldZ)
{
    constexpr double grid_scale = 0.12f;
    const int x = SferaNumeric::truncateInt(worldX * grid_scale + 100000.0) + 20000;
    const int z = SferaNumeric::truncateInt(worldZ * grid_scale + 100000.0) + 20000;
    const int patchX = x / 12 - 10000, patchZ = z / 12 - 10000;
    return {patchX, patchZ, x % 12, z % 12, (patchX + 40) * 80 + 39 - patchZ};
}

constexpr std::array<std::uint32_t, 32> TerrainQueries::buildFiveBitToEightBit()
{
    std::array<std::uint32_t, 32> result{};
    for (std::uint32_t value = 0; value < result.size(); ++value)
    {
        result[value] = value * 255u / 31u;
    }
    return result;
}

void TerrainQueries::sampleColor(float worldX, float worldZ, std::uint32_t &red, std::uint32_t &green, std::uint32_t &blue)
{
    static constexpr auto fiveBitToEightBit = buildFiveBitToEightBit();
    red = green = blue = 0u;
    const auto location = locate(worldX, worldZ);
    if (!location.valid())
        return;
    SferaTerrainSource::patch(location.mapIndex);
    const double precise_world_x = worldX, precise_world_z = worldZ;
    const float localX = SferaNumeric::real32(precise_world_x - location.patchX * 100), localZ = SferaNumeric::real32(precise_world_z - location.patchZ * 100);
    const int pixelX = std::clamp(SferaNumeric::truncateInt(localX / 100.0 * 254.0 + 1.0) + 2, 0, 255), pixelZ = std::clamp(SferaNumeric::truncateInt(localZ / 100.0 * 254.0 + 1.0) + 2, 0, 255);
    const auto &pixels = SferaTerrainSource::image(location.mapIndex).pixels;
    const std::uint16_t color = pixels[pixelZ * 256 + pixelX];
    red = fiveBitToEightBit[color >> 11];
    green = fiveBitToEightBit[(color >> 6) & 31u];
    blue = fiveBitToEightBit[color & 31u];
}

bool TerrainQueries::surface(float worldX, float worldZ, float &height, SferaPlaneF &plane)
{
    const auto location = locate(worldX, worldZ);
    if (!location.valid())
        return false;
    auto &patch = SferaTerrainSource::patch(location.mapIndex, false);
    const auto &cell = patch.cells[location.cellIndex()];
    const double precise_world_x = worldX, precise_world_z = worldZ;
    const float localX = SferaNumeric::real32(precise_world_x - location.patchX * 100), localZ = SferaNumeric::real32(precise_world_z - location.patchZ * 100);
    for (std::size_t index = 0; index < cell.triangles.size(); ++index)
    {
        const auto &triangle = cell.triangles[index];
        const std::array<const SferaVec3F *, 3> points = {&patch.vertices[triangle.indices[0]].position, &patch.vertices[triangle.indices[1]].position, &patch.vertices[triangle.indices[2]].position};
        const auto localPlane = TerrainQueries::terrainPlane(triangle.normal, *points[0]);
        SferaVec3F intersection;
        if (localPlane.intersectLine({localX, -10000.0f, localZ}, {localX, -9000.0f, localZ}, intersection) != 1 || !triangle.normal.containsConvexPolygonPoint(points, intersection))
            continue;
        height = intersection.y;
        plane = localPlane;
        const double point_x = points[0]->x, point_y = points[0]->y, point_z = points[0]->z;
        plane.distance = SferaNumeric::real32(-(point_x + location.patchX * 100) * triangle.normal.x - point_y * triangle.normal.y - (point_z + location.patchZ * 100) * triangle.normal.z);
        return true;
    }
    return false;
}

std::uint8_t TerrainQueries::placementOrientation(float worldX, float worldZ, SferaVec3F &angles, float &height, SferaPlaneF &plane)
{
    if (!surface(worldX, worldZ, height, plane) || std::fabs(plane.normal.y) < 0.75f)
        return 0u;
    const double radius = 2.45f;
    const float diagonal_root = SferaNumeric::real32(std::sqrt(2.0));
    const float diagonal = SferaNumeric::real32(radius / diagonal_root);
    const double x = worldX, z = worldZ;
    const std::array<std::array<double, 2>, 8> samples = {
        {{x + radius, z}, {x, z + radius}, {x - radius, z}, {x, z - radius}, {x + diagonal, z + diagonal}, {x - diagonal, z - diagonal}, {x + diagonal, z - diagonal}, {x - diagonal, z + diagonal}}};
    std::array<float, 8> heights;
    SferaPlaneF samplePlane;
    for (std::size_t index = 0; index < samples.size(); ++index)
        if (!surface(SferaNumeric::real32(samples[index][0]), SferaNumeric::real32(samples[index][1]), heights[index], samplePlane))
            return 0u;
    for (std::size_t index = 0; index < samples.size(); ++index)
    {
        const float predicted = SferaNumeric::real32((-samples[index][1] * plane.normal.z - samples[index][0] * plane.normal.x - plane.distance) / plane.normal.y);
        const double actual = heights[index];
        const float difference = SferaNumeric::real32(actual - predicted);
        if (std::fabs(difference) > 0.5f)
            return 0u;
    }
    float rotatedY = plane.normal.y;
    const double normalX = plane.normal.x, normalY = plane.normal.y, normalZ = plane.normal.z;
    if (SferaMath::planarSquared(normalX, normalY) > 1e-6)
    {
        const float azimuth = SferaNumeric::real32(std::atan2(normalY, normalX));
        angles.z = SferaNumeric::real32(4.7123894691467285 - azimuth);
        const auto [sine, cosine] = SferaMath::rotationTerms(angles.z);
        rotatedY = SferaNumeric::real32(sine * normalX + cosine * normalY);
    }
    else
        angles.z = 0.0f;
    const double rotated = rotatedY;
    const float inclination = SferaNumeric::real32(std::atan2(rotated, normalZ));
    angles.y = SferaNumeric::real32(4.7123894691467285 - inclination);
    const double randomAngle = std::rand() * 3.1415929794311523;
    angles.x = SferaNumeric::real32((randomAngle + randomAngle) / 32767.0);
    angles.y = -angles.y;
    angles.z = -angles.z;
    return 1u;
}

bool TerrainQueries::clearViewToFlare(const TerrainPatch &patch, const TerrainCell &cell)
{
    const auto anchor = SferaTerrainSource::anchor();
    const auto &source = SferaSceneAccess::cameraObject()->position;
    const SferaVec3F destination = {SceneSky::flare_world_position.x, SceneSky::flare_world_position.y, SceneSky::flare_world_position.z};
    for (std::size_t index = 0; index < cell.triangles.size(); ++index)
    {
        const auto &triangle = cell.triangles[index];
        std::array<SferaVec3F, 3> positions;
        for (std::size_t corner = 0; corner < positions.size(); ++corner)
        {
            const auto &original = patch.vertices[triangle.indices[corner]].position;
            positions[corner] = original + SferaVec3F{anchor.x, 0.0f, anchor.z};
            positions[corner].y = original.y;
        }
        const auto plane = TerrainQueries::terrainPlane(triangle.normal, positions[0]);
        SferaVec3F intersection;
        const std::array<const SferaVec3F *, 3> points = {&positions[0], &positions[1], &positions[2]};
        if (plane.intersectLine(source, destination, intersection) == 1 && plane.normal.containsConvexPolygonPoint(points, intersection))
            return false;
    }
    return true;
}

int TerrainRenderer::terrainPatchCoordinate(double value)
{
    return SferaNumeric::truncateInt(value / 100.0 + 1000.0) - 1000;
}

void TerrainRenderer::terrainSetState(D3DRENDERSTATETYPE state, DWORD value)
{
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    device.checkResult(device.native_device->SetRenderState(state, value), "SetRenderState");
}

bool TerrainRenderer::visibleBounds(const TerrainBounds &source, const SferaVec3F &anchor, SferaViewProjectionScratchRuntime &translated)
{
    SferaViewProjectionScratchRuntime local;
    std::copy(std::begin(source.corners), std::end(source.corners), local.corners);
    local.clipping_bounds = {source.scaledBounds[0], source.scaledBounds[1], source.scaledBounds[2], source.scaledBounds[3], source.scaledBounds[4], source.scaledBounds[5]};
    translated = local.translated(anchor);
    SphereRenderSceneRenderer::clipped_terrain_bounds = translated.clipping_bounds;
    const auto &view = SphereRenderSceneRenderer::projected_terrain_bounds;
    const auto &bounds = translated.clipping_bounds;
    if (view.max_x < bounds.min_x || view.min_x > bounds.max_x || view.max_y < bounds.min_y || view.min_y > bounds.max_y || view.max_z < bounds.min_z || view.min_z > bounds.max_z)
        return false;
    SferaFrustumF frustum;
    frustum = SphereRenderSceneRenderer::frustum;
    return frustum.classifyPoints(translated.corners) != 0;
}

bool TerrainRenderer::gatherCells(TerrainPatch &patch)
{
    const auto anchor = SferaTerrainSource::anchor();
    SferaViewProjectionScratchRuntime translated;
    if (!visibleBounds(patch.bounds, anchor, translated))
        return false;
    visibleCells.clear();
    visibleCells.reserve(144u);
    for (int quarter = 0; quarter < 4; ++quarter)
    {
        if (!visibleBounds(patch.quarterBounds[quarter], anchor, translated))
            continue;
        for (int group = 0; group < 4; ++group)
        {
            const int groupIndex = quarter * 4 + group;
            if (!visibleBounds(patch.groupBounds[groupIndex], anchor, translated))
                continue;
            for (int cell = 0; cell < 9; ++cell)
            {
                const int cellIndex = groupIndex * 9 + cell;
                if (!visibleBounds(patch.cellBounds[cellIndex], anchor, translated))
                    continue;
                TerrainVisibleCell visible{&patch.cells[cellIndex], {}};
                std::copy(std::begin(translated.corners), std::end(translated.corners), visible.bounds.corners);
                visibleCells.push_back(visible);
            }
        }
    }
    return true;
}

void TerrainRenderer::findReflectiveWater(TerrainPatch &patch)
{
    if (!gatherCells(patch))
        return;
    const auto &position = SferaSceneAccess::cameraObject()->position;
    for (const auto &visible : visibleCells)
    {
        const auto &water = patch.waters[visible.cell->x + visible.cell->z * 12];
        if (water.material == 0u || !(g_sfera_graphics_runtime.water_materials.at(water.material).reflection_opacity > 0.001f))
            continue;
        const float distance = ((position) - (visible.bounds.corners[0])).length();
        if (!(SphereRenderSceneRenderer::reflection_distance > distance))
            continue;
        SphereRenderSceneRenderer::reflection_distance = distance;
        SphereRenderSceneRenderer::reflection_height = water.height;
    }
}

void TerrainRenderer::visitPatches(bool draw)
{
    const auto &position = SferaSceneAccess::cameraObject()->position;
    const double radius = SphereRenderSceneRenderer::view_distance;
    const int firstX = TerrainRenderer::terrainPatchCoordinate(position.x - radius), lastX = TerrainRenderer::terrainPatchCoordinate(position.x + radius);
    const int firstZ = TerrainRenderer::terrainPatchCoordinate(position.z - radius), lastZ = TerrainRenderer::terrainPatchCoordinate(position.z + radius);
    for (int x = firstX; x <= lastX; ++x)
        for (int z = firstZ; z <= lastZ; ++z)
        {
            g_sfera_terrain_renderer.patch_origin = {{x * 100.0f}, {0.0f}, {z * 100.0f}};
            if (x < -40 || x >= 40 || z < -40 || z >= 40)
                continue;
            const int mapIndex = (x + 40) * 80 + 39 - z;
            auto &patch = SferaTerrainSource::patch(mapIndex);
            if (draw)
            {
                SphereRenderSceneRenderer::terrain_texture = SferaTerrainSource::texture(mapIndex);
                prepareAndDraw(patch);
            }
            else
                findReflectiveWater(patch);
        }
}

void TerrainRenderer::drawLandscape()
{
    waterSurfaces.clear();

    g_sfera_light_runtime.setDirectionalLight({-SphereRenderSceneRenderer::sun_direction.x, -SphereRenderSceneRenderer::sun_direction.y, -SphereRenderSceneRenderer::sun_direction.z},
                                              {SphereRenderSceneRenderer::environment.sunColor.x, SphereRenderSceneRenderer::environment.sunColor.y,
                                               SphereRenderSceneRenderer::environment.sunColor.z});
    const auto identity = SferaMatrix4x4F::identity();
    g_sfera_graphics_runtime.d3d_runtime->setTransform(D3DTS_WORLD, identity);
    visitPatches(true);
    for (auto &entry : TerrainTextureCache::entries)
        ++entry.use_count;
}

void TerrainRenderer::prepareAndDraw(TerrainPatch &patch)
{
    if (!gatherCells(patch) || visibleCells.empty())
        return;
    const auto &position = SferaSceneAccess::cameraObject()->position;
    const auto anchor = SferaTerrainSource::anchor();
    const auto *lights = g_sfera_light_runtime.visible_handles.data();
    for (const auto &visible : visibleCells)
    {
        auto &group = patch.surfaceGroups[visible.cell->x + visible.cell->z * 12];
        const auto &minimum = visible.bounds.corners[2];
        const auto &maximum = visible.bounds.corners[5];
        group.light_mask = 0u;
        group.distant = false;
        std::uint32_t bit = 1u;
        int count = 0;
        for (std::uint32_t index = 0; index < g_sfera_light_runtime.visible_handles.size(); ++index, bit += bit)
        {
            const auto &light = *lights[index];
            if (light.bounds_min.x < maximum.x && light.bounds_min.y < maximum.y && light.bounds_min.z < maximum.z && light.bounds_max.x > minimum.x && light.bounds_max.y > minimum.y &&
                light.bounds_max.z > minimum.z)
            {
                group.light_mask |= bit;
                if (++count == 7)
                    break;
            }
        }
        if (std::all_of(std::begin(visible.bounds.corners), std::end(visible.bounds.corners), std::bind_front(&TerrainRenderer::farFromCorner, std::cref(position))))
            group.distant = true;
        const auto &water = patch.waters[visible.cell->x + visible.cell->z * 12];
        if (water.material != 0u)
        {
            const int x = SferaNumeric::truncateInt((anchor.x + 4.0) / 8.333333015441895 + 10000.0) + visible.cell->x - 10000,
                      z = SferaNumeric::truncateInt((anchor.z + 4.0) / 8.333333015441895 + 10000.0) + visible.cell->z - 10000;
            waterSurfaces.push_back({x, z, water.height, group.light_mask, water.material, visible.bounds});
        }
    }

    std::size_t first = 0u;
    std::uint32_t vertices = 0u;
    for (std::size_t index = 0; index < visibleCells.size(); ++index)
    {
        const auto &cell = *visibleCells[index].cell;
        const auto count = patch.surfaceGroups[cell.x + cell.z * 12].vertexCount;
        vertices += SferaNumeric::lowWord(count);
        if (vertices > 30000u)
        {
            if (index > first)
                drawCells(patch, first, index - 1u);
            first = index;
            vertices = SferaNumeric::lowWord(count);
        }
    }
    if (!visibleCells.empty())
        drawCells(patch, first, visibleCells.size() - 1u);
}

void TerrainRenderer::terrainSubmitIndices(CD3D9Device &device, std::span<const std::uint16_t> indices, IDirect3DVertexBuffer9 *vertices, bool lit, std::size_t baseVertex, std::size_t vertexCount)
{
    auto output = device.indices_secondary.lock(indices.size());
    std::copy(indices.begin(), indices.end(), output.data());
    output.unlock();
    device.drawBuffer(vertices, D3DPT_TRIANGLELIST, lit ? CD3D9Devicelighting : 0u, baseVertex, vertexCount, output.buffer(), indices.size(), output.first(),
                      lit ? sizeof(SphereRenderPositionNormalUvVertex) : sizeof(SphereRenderPositionColorUvVertex));
}

void TerrainRenderer::drawCells(TerrainPatch &patch, std::size_t first, std::size_t last)
{
    if (first > last)
        return;
    if (g_sfera_light_runtime.active_count > 1u)
        SferaEngineDiagnostics::fail("Activate light error N3");
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    auto litVertices = device.model_vertices.lock(30000);
    auto coloredVertices = device.colored_vertices.lock(30000);
    const auto anchor = SferaTerrainSource::anchor();
    std::size_t vertexCount = 0u;
    for (std::size_t index = first; index <= last; ++index)
    {
        const auto &cell = *visibleCells.at(index).cell;
        auto &group = patch.surfaceGroups[cell.x + cell.z * 12];
        group.colored_vertex_offset = vertexCount;
        if (vertexCount + group.vertexCount > 30000u)
            SferaEngineDiagnostics::fail("VB_SIZE exceed!");
        for (std::size_t vertex = 0; vertex < group.vertexCount; ++vertex, ++vertexCount)
        {
            const auto &source = patch.groupedVertices[group.firstVertex + vertex];
            const auto position = source.position + anchor;
            litVertices[vertexCount] = {position, source.normal, source.textureU, source.textureV};
            coloredVertices[vertexCount] = {position, D3DCOLOR_ARGB(255, 180, 180, 180), D3DCOLOR_ARGB(0, 50, 50, 50), source.detailU, source.detailV};
        }
    }
    litVertices.unlock();
    coloredVertices.unlock();
    const auto litBase = litVertices.first(), coloredBase = coloredVertices.first();
    TerrainRenderer::terrainSetState(D3DRS_FOGCOLOR, D3DCOLOR_ARGB(0, 255, 255, 255));
    std::vector<std::uint16_t> indices;
    std::uint16_t batchVertices = 0u;
    std::size_t batchStart = 0u;
    std::uint16_t material = visibleCells.at(first).cell->baseMicrotexture;

    for (std::size_t index = first; index <= last; ++index)
    {
        const auto &cell = *visibleCells.at(index).cell;
        const auto &group = patch.surfaceGroups[cell.x + cell.z * 12];
        if (cell.baseMicrotexture != material)
        {
            flushBaseCells(device, indices, coloredVertices, coloredBase, batchStart, batchVertices, material);
            material = cell.baseMicrotexture;
        }
        appendCellIndices(patch, indices, batchVertices, cell, group);
    }
    if (!indices.empty())
        flushBaseCells(device, indices, coloredVertices, coloredBase, batchStart, batchVertices, material);
    TerrainRenderer::terrainSetState(D3DRS_ZWRITEENABLE, FALSE);
    if (SphereRenderSceneRenderer::secondary_pass == 0u)
    {
        device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
        for (std::size_t index = first; index <= last; ++index)
        {
            const auto &cell = *visibleCells.at(index).cell;
            const auto &group = patch.surfaceGroups[cell.x + cell.z * 12];
            if (group.distant)
                continue;
            for (std::size_t layer = 0; layer < cell.layers.size(); ++layer)
            {
                if (!std::in_range<int>(layer))
                    throw std::length_error("Too many terrain texture layers");
                TerrainTextureCache::bindLayer(cell, SferaNumeric::signedWord(SferaNumeric::lowWord(layer)));
                TerrainRenderer::terrainSubmitIndices(device, {patch.groupedIndices.data() + group.firstIndex, cell.triangles.size() * 3u}, coloredVertices.buffer(), false,
                                                      coloredBase + group.colored_vertex_offset, group.vertexCount);
            }
        }
    }
    const auto &ambient = SphereRenderSceneRenderer::environment.fogColor;
    const std::uint32_t fogColor = SferaColor::rgba(SferaNumeric::truncatedWord(ambient.x), SferaNumeric::truncatedWord(ambient.y), SferaNumeric::truncatedWord(ambient.z), 0).argb();
    TerrainRenderer::terrainSetState(D3DRS_FOGCOLOR, fogColor);
    device.setAlphaBlending(D3DBLEND_ZERO, D3DBLEND_SRCCOLOR);
    SferaTextureBinding::terrainSetTexture(0u, SferaTextureAccess::resource(SphereRenderSceneRenderer::terrain_texture));
    SferaTextureAccess::hasAlpha(SphereRenderSceneRenderer::terrain_texture);
    indices.clear();
    batchStart = 0u;
    batchVertices = 0u;
    std::uint32_t mask = patch.surfaceGroups[visibleCells.at(first).cell->x + visibleCells.at(first).cell->z * 12].light_mask;

    for (std::size_t index = first; index <= last; ++index)
    {
        const auto &cell = *visibleCells.at(index).cell;
        const auto &group = patch.surfaceGroups[cell.x + cell.z * 12];
        if (SceneSky::flare_visible != 0u)
            SceneSky::flare_visible = TerrainQueries::clearViewToFlare(patch, cell);
        const auto nextMask = group.light_mask;
        if (nextMask != mask)
        {
            flushLitCells(device, indices, litVertices, litBase, batchStart, batchVertices, mask);
            mask = nextMask;
        }
        appendCellIndices(patch, indices, batchVertices, cell, group);
    }
    flushLitCells(device, indices, litVertices, litBase, batchStart, batchVertices, mask);
    device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    TerrainRenderer::terrainSetState(D3DRS_ZWRITEENABLE, TRUE);
    g_sfera_light_runtime.disableActiveLights();
    if (g_sfera_light_runtime.active_count > 1u)
        SferaEngineDiagnostics::fail("Activate light error N4");
}

void TerrainRenderer::drawWater()
{
    if (waterSurfaces.empty())
        return;
    // The sum is the legacy batching key, not a lexicographic (mask, material) key.
    SferaAlgorithms::stableSort(waterSurfaces, &TerrainRenderer::waterBatchKey);
    std::vector<std::pair<std::size_t, std::size_t>> ranges;
    std::size_t first = 0u;
    for (std::size_t index = 1; index < waterSurfaces.size(); ++index)
        if (waterSurfaces[index].lightMask != waterSurfaces[index - 1].lightMask || waterSurfaces[index].material != waterSurfaces[index - 1].material)
        {
            ranges.emplace_back(first, index);
            first = index;
        }
    ranges.emplace_back(first, waterSurfaces.size());

    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    const auto identity = SferaMatrix4x4F::identity();
    device.setTransform(D3DTS_WORLD, identity);
    const float fieldOfView = SferaSceneAccess::fieldOfView(g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height);
    const float halfAngle = SferaNumeric::real32(fieldOfView * 0.5);
    const double radians = halfAngle;
    const float projectionTangent = SferaNumeric::real32(std::tan(radians));
    const int rotationStep = SphereRenderSceneRenderer::texture_animation_frame;
    const float phase = SferaNumeric::real32(rotationStep * 0.19634956121444702);
    const double phaseAngle = phase;
    const float phaseSine = SferaNumeric::real32(std::sin(phaseAngle));
    SferaMatrix4x4F reflection{};
    reflection.m[0][0] = SferaNumeric::real32(-0.5 / projectionTangent);
    reflection.m[1][1] = SferaNumeric::real32(-(phaseSine * 0.003000000026077032 + 0.5 / projectionTangent));
    reflection.m[2][0] = reflection.m[2][1] = 0.5f;
    reflection.m[2][2] = reflection.m[3][3] = 1.0f;
    TerrainRenderer::terrainSetState(D3DRS_FOGENABLE, FALSE);
    device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);

    for (const auto &range : ranges)
    {
        const auto &surface = waterSurfaces[range.first];
        if (surface.material == 0u || surface.material >= g_sfera_graphics_runtime.water_materials.size())
            SferaEngineDiagnostics::fail("Water material index outside 1..9");
        const auto &material = g_sfera_graphics_runtime.water_materials.at(surface.material);
        std::vector<SphereRenderPositionNormalUvVertex> vertices;
        std::vector<std::uint16_t> indices;
        vertices.reserve((range.second - range.first) * 4u);
        indices.reserve((range.second - range.first) * 6u);
        for (std::size_t index = range.first; index < range.second; ++index)
        {
            const auto &water = waterSurfaces[index];
            if (vertices.size() > std::numeric_limits<std::uint16_t>::max() - 3u)
                throw std::length_error("Water batch exceeds 16-bit index range");
            const std::uint16_t base = SferaNumeric::lowHalf(SferaNumeric::lowWord(vertices.size()));
            for (int corner = 0; corner < 4; ++corner)
            {
                const int dx = corner == 1 || corner == 2 ? 1 : 0, dz = corner >= 2 ? 1 : 0;
                const double phaseX = (water.x + dx) * 3.9269912242889404, phaseZ = (water.z + dz) * 2.3561947345733643;
                const float wavePhase = SferaNumeric::real32((phaseZ + phaseX) + rotationStep * 0.19634956121444702);
                const double waveAngle = wavePhase;
                const float waveSine = SferaNumeric::real32(std::sin(waveAngle));
                auto &vertex = vertices.emplace_back();
                vertex.position.x = SferaNumeric::real32((water.x + dx) * 8.333333015441895);
                vertex.position.y = SferaNumeric::real32((waveSine + 1.0) * material.wave_amplitude + water.height);
                vertex.position.z = SferaNumeric::real32((water.z + dz) * 8.333333015441895);
                vertex.normal = {0.0f, -1.0f, 0.0f};
                vertex.u = SferaNumeric::real32(dx);
                vertex.v = SferaNumeric::real32(dz);
            }
            for (const auto corner : {0u, 1u, 3u, 1u, 2u, 3u})
                indices.push_back(SferaNumeric::lowHalf(base + corner));
        }

        g_sfera_light_runtime.activateMask(surface.lightMask);
        waterTextureStage(device, D3DTSS_TEXCOORDINDEX, 0u);
        waterTextureStage(device, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE);
        device.setTransform(D3DTS_TEXTURE0, identity);
        waterDirectionalLight();
        waterAnimationTexture(rotationStep, material.primary_animation);

        drawWaterBatch(device, vertices, indices, material.primary_opacity);
        for (std::size_t index = range.first; index < range.second; ++index)
        {
            const auto &water = waterSurfaces[index];
            const float u = ((water.x + 10000) % 4) * 0.25f, v = ((water.z + 10000) % 4) * 0.25f;
            for (int corner = 0; corner < 4; ++corner)
            {
                auto &vertex = vertices[(index - range.first) * 4 + corner];
                vertex.u = u + (corner == 1 || corner == 2 ? 0.25f : 0.0f);
                vertex.v = v + (corner >= 2 ? 0.25f : 0.0f);
            }
        }
        if (material.primary_animation != material.secondary_animation)
            waterAnimationTexture(rotationStep, material.secondary_animation);
        drawWaterBatch(device, vertices, indices, material.secondary_opacity);
        if (g_sfera_graphics_runtime.reflection_quality > 0u)
        {
            waterTextureStage(device, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_CAMERASPACEPOSITION);
            waterTextureStage(device, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT3 | D3DTTFF_PROJECTED);
            device.setTransform(D3DTS_TEXTURE0, reflection);
            g_sfera_light_runtime.setDirectionalLight({0.0f, 1.0f, 0.0f}, {255.0f, 255.0f, 255.0f});
            SferaTextureBinding::terrainSetTexture(0u, device.reflection_target->native_texture.Get());
            drawWaterBatch(device, vertices, indices, material.reflection_opacity);
        }
    }
    device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    waterTextureStage(device, D3DTSS_TEXCOORDINDEX, 0u);
    waterTextureStage(device, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE);
    device.setTransform(D3DTS_TEXTURE0, identity);
    device.setWhiteMaterial(1.0f);
    g_sfera_light_runtime.disableActiveLights();
    waterDirectionalLight();
    TerrainRenderer::terrainSetState(D3DRS_FOGENABLE, TRUE);
}

bool TerrainRenderer::farFromCorner(const SferaVec3F &position, const SferaVec3F &corner)
{
    return ((position) - (corner)).length() > 50.0f;
}

void TerrainRenderer::appendCellIndices(const TerrainPatch &patch, std::vector<std::uint16_t> &indices, std::uint16_t &batchVertices, const TerrainCell &cell, const TerrainSurfaceGroup &group)
{
    for (std::size_t index = 0; index < cell.triangles.size() * 3; ++index)
        indices.push_back(patch.groupedIndices[group.firstIndex + index] + batchVertices);
    batchVertices += SferaNumeric::lowHalf(SferaNumeric::lowWord(group.vertexCount));
}

void TerrainRenderer::flushBaseCells(CD3D9Device &device, std::vector<std::uint16_t> &indices, DynamicStreamMapping<SphereRenderPositionColorUvVertex> &coloredVertices, std::size_t coloredBase,
                                     std::size_t &batchStart, std::uint16_t &batchVertices, std::uint16_t material)
{
    IDirect3DBaseTexture9 *texture = SferaTextureAccess::resource(SferaTerrainSource::microtexture(material));
    SferaTextureBinding::terrainSetTexture(0u, texture);
    SferaTextureAccess::hasAlpha(SferaTerrainSource::microtexture(material));
    TerrainRenderer::terrainSubmitIndices(device, indices, coloredVertices.buffer(), false, coloredBase + batchStart, batchVertices);
    batchStart += batchVertices;
    batchVertices = 0u;
    indices.clear();
}

void TerrainRenderer::flushLitCells(CD3D9Device &device, std::vector<std::uint16_t> &indices, DynamicStreamMapping<SphereRenderPositionNormalUvVertex> &litVertices, std::size_t litBase,
                                    std::size_t &batchStart, std::uint16_t &batchVertices, std::uint32_t mask)
{
    g_sfera_light_runtime.activateMask(mask);
    TerrainRenderer::terrainSubmitIndices(device, indices, litVertices.buffer(), true, litBase + batchStart, batchVertices);
    batchStart += batchVertices;
    batchVertices = 0u;
    indices.clear();
}

std::size_t TerrainRenderer::waterBatchKey(const TerrainWaterSurface &surface)
{
    return surface.lightMask + surface.material;
}

void TerrainRenderer::waterTextureStage(CD3D9Device &device, D3DTEXTURESTAGESTATETYPE state, DWORD value)
{
    device.checkResult(device.native_device->SetTextureStageState(0u, state, value), "SetTextureStageState");
}

void TerrainRenderer::waterDirectionalLight()
{
    g_sfera_light_runtime.setDirectionalLight({-SphereRenderSceneRenderer::sun_direction.x, -SphereRenderSceneRenderer::sun_direction.y, -SphereRenderSceneRenderer::sun_direction.z},
                                              {SphereRenderSceneRenderer::environment.sunColor.x, SphereRenderSceneRenderer::environment.sunColor.y,
                                               SphereRenderSceneRenderer::environment.sunColor.z});
}

void TerrainRenderer::waterAnimationTexture(int rotationStep, int animationId)
{
    const int frame = rotationStep / 2;
    std::string name = "ww1_00";
    name[2] = static_cast<char>('0' + animationId);
    name[4] = static_cast<char>('0' + frame / 10);
    name[5] = static_cast<char>('0' + frame % 10);
    SferaTextureBinding::terrainSetTexture(0u, SferaTextureAccess::resource(SferaTextureAccess::find(name)));
    SferaTextureAccess::hasAlpha(SferaTextureAccess::find(name));
}

void TerrainRenderer::drawWaterBatch(CD3D9Device &device, const std::vector<SphereRenderPositionNormalUvVertex> &vertices, const std::vector<std::uint16_t> &indices, float opacity)
{
    device.setWhiteMaterial(opacity);
    device.checkResult(device.native_device->SetFVF(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1), "SetFVF");
    device.drawVertices(D3DPT_TRIANGLELIST, CD3D9Devicelighting | CD3D9Devicetwo_sided, vertices.data(), vertices.size(), indices.data(), indices.size(), sizeof(SphereRenderPositionNormalUvVertex));
}

void TerrainTextureCache::initialize()
{
    std::array<float, 12> passes{};
    for (std::uint32_t row = 0; row < 12; ++row)
    {
        const float position = SferaNumeric::real32((row * 254) / 12.0 + 1.0 - 1.0 / 24.0);
        const auto bucket = SferaNumeric::truncateInt(position + 0.5) - 1;
        const double precise_position = position;
        passes[row] = SferaNumeric::real32(precise_position - bucket);
    }
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    decltype(entries) replacement{};
    for (auto &entry : replacement)
    {
        device.checkResult(device.native_device->CreateTexture(256u, 256u, 1u, 0u, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, entry.resource.GetAddressOf(), nullptr), "CreateTexture");
        if (entry.resource == nullptr)
            SferaEngineDiagnostics::fatal("CreateTexture for landscape cash failed");
    }
    TerrainTextureCache::entries = std::move(replacement);

    for (std::uint32_t row = 0; row < 12; ++row)
    {
        float position = passes[row];
        for (std::uint32_t column = 0; column < 256; ++column)
        {
            const auto bucket = SferaNumeric::truncateInt(position + 0.5) - 1;
            const double precise_position = position;
            const float fraction = SferaNumeric::real32(precise_position - bucket - 0.5);
            TerrainTextureCache::quantization_x[row * 256 + column] = SferaNumeric::lowByte(bucket);
            TerrainTextureCache::quantization_y[row * 256 + column] = SferaNumeric::lowByte(SferaNumeric::truncatedWord(fraction * 64.0 + 0.5));
            const double precise_position_next = position;
            constexpr double position_step = 1.0f / 12.0f;
            position = SferaNumeric::real32(precise_position_next + position_step);
        }
    }
    for (std::size_t row = 0; row < 64; ++row)
    {
        const float y = row / 64.0f;
        for (std::size_t column = 0; column < 64; ++column)
        {
            const float x = column / 64.0f;
            const float weights[]{(1.0f - x) * (1.0f - y), x * (1.0f - y), (1.0f - x) * y, x * y};
            for (std::size_t channel = 0; channel < std::size(weights); ++channel)
                TerrainTextureCache::blend_lut[(row * 64 + column) * 4 + channel] = SferaNumeric::lowByte(SferaNumeric::truncatedWord(weights[channel] * 255.0));
        }
    }
    std::fill(std::begin(g_sfera_direct_input_runtime.allowed_glyphs), std::end(g_sfera_direct_input_runtime.allowed_glyphs), std::uint8_t{});
    for (const auto glyph : std::string_view("!\"#$%&'(."))
        g_sfera_direct_input_runtime.allowed_glyphs[SferaText::byteValue(glyph)] = 1;
    g_sfera_direct_input_runtime.allowed_glyphs[UINT8_MAX] = 1;
}

void TerrainTextureCache::blendLayer(const TerrainCell &cell, int layer, TerrainTextureImage &texture)
{
    if (layer < 0 || layer >= cell.layers.size())
        throw std::out_of_range("Landscape microtexture layer");
    const auto *mask = cell.masks.data() + layer * 24 * 24;

    for (int y = 0; y < 256; ++y)
    {
        const int maskRow = TerrainTextureCache::quantization_x[cell.z * 256 + y] * 24;
        const auto *blendRow = TerrainTextureCache::blend_lut + TerrainTextureCache::quantization_y[cell.z * 256 + y] * 256;
        for (int x = 0; x < 256; ++x)
        {
            const int maskIndex = maskRow + TerrainTextureCache::quantization_x[cell.x * 256 + x];
            const auto *weights = blendRow + TerrainTextureCache::quantization_y[cell.x * 256 + x] * 4;
            const int alpha = std::min(255, (mask[maskIndex] * weights[0] + mask[maskIndex + 1] * weights[1] + mask[maskIndex + 24] * weights[2] + mask[maskIndex + 25] * weights[3]) >> 8);
            auto &pixel = texture.pixels[y * TerrainTextureImage::width + x];
            pixel = SferaColor::fromArgb4444(pixel).withAlpha(alpha).argb4444();
        }
    }
}

void TerrainTextureCache::bindLayer(const TerrainCell &cell, int layer)
{
    auto &cache = TerrainTextureCache::entries;
    const auto owner = &cell;
    auto entry = std::find_if(cache.begin(), cache.end(), std::bind_front(matchesTextureLayer, owner, layer));
    if (entry != cache.end())
    {
        SferaTextureBinding::terrainSetTexture(0u, entry->resource.Get());
        entry->use_count = 0u;
        return;
    }
    entry = std::max_element(cache.begin(), cache.end(), lessUsedTexture);
    entry->owner = nullptr;
    auto *source = SferaTerrainSource::microtextureImage(cell.layers[layer]);
    if (source == nullptr)
        throw std::runtime_error("Missing landscape microtexture");
    blendLayer(cell, layer, *source);
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    TextureMapping mapping(entry->resource.Get(), 0, D3DLOCK_NOSYSLOCK);
    device.checkResult(mapping.status(), "LockRect(terrain)");
    const auto &description = mapping.description();
    if (description.Width != 256 || description.Height != 256)
    {
        SferaEngineDiagnostics::fail("BeginDraw has returned texture size != 256x256");
    }
    device.checkResult(mapping.copyRows(std::as_bytes(std::span(source->pixels)), TerrainTextureImage::width * sizeof(source->pixels[0]), TerrainTextureImage::height), "Upload terrain pixels");
    device.checkResult(mapping.unlock(), "UnlockRect(terrain)");
    entry->owner = owner;
    entry->kind = layer;
    entry->use_count = 0;
    SferaTextureBinding::terrainSetTexture(0u, entry->resource.Get());
}

void TerrainTextureCache::release()
{
    for (auto &entry : TerrainTextureCache::entries)
        entry = {};
}

uint8_t TerrainTextureCache::quantization_x[3072]{};
uint8_t TerrainTextureCache::quantization_y[3072]{};
uint8_t TerrainTextureCache::blend_lut[16385]{};
