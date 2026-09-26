#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <limits>
#include <span>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "binary/Binary.h"
#include "camera/Camera.h"
#include "collision/Collision.h"
#include "effects/EffectManager.h"
#include "geometry/Geometry.h"
#include "math/MathFunctions.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/SceneRenderer.h"
#include "resources/FileResources.h"
#include "resources/TextureRepository.h"
#include "scene/SceneObject.h"
#include "ui/Rendering.h"
#include "world/ServerGeometry.h"
#include "world/WorldObjects.h"

Contours::Contours(int first, int last) : first_server_type(first), last_server_type(last)
{
}

void Contours::clear()
{
    records.clear();
    server_map.clear();
    invalidateGrid();
}

void Contours::invalidateGrid()
{
    grid_initialized = false;
    mask_server = -1;
}


template <class T> auto Contours::readVertexColumn(SferaBinaryReader &reader, Contour &contour, T ContourVertex::*member)
{
    for (std::size_t index = 0; index < 64; ++index)
    {
        const auto value = reader.read<T>();
        if (index < contour.vertices.size())
            contour.vertices[index].*member = value;
    }
}

void Contours::loadBytes(std::span<const std::uint8_t> bytes)
{
    constexpr std::size_t encodedRecordSize = 24 + 4 * 64 * 4;
    if (bytes.size() < 4)
        throw std::runtime_error("Contours: missing record count");
    SferaBinaryReader reader(bytes);
    const auto count = reader.read<int>();
    if (count < 0 || std::cmp_greater(count, (bytes.size() - 4) / encodedRecordSize))
        throw std::runtime_error("Contours: truncated records");
    std::vector<Contour> loaded(count);
    for (auto &contour : loaded)
    {
        contour.type = reader.read<int>();
        const auto vertexCount = reader.read<int>();
        if (vertexCount < 0 || vertexCount > 64)
            throw std::runtime_error("Contours: invalid vertex count");
        contour.min_x = reader.read<float>();
        contour.max_x = reader.read<float>();
        contour.min_z = reader.read<float>();
        contour.max_z = reader.read<float>();
        contour.vertices.resize(vertexCount);

        readVertexColumn(reader, contour, &ContourVertex::x);
        readVertexColumn(reader, contour, &ContourVertex::z);
        readVertexColumn(reader, contour, &ContourVertex::neighbour_contour);
        readVertexColumn(reader, contour, &ContourVertex::neighbour_edge);
        if (!std::isfinite(contour.min_x) || !std::isfinite(contour.max_x) || !std::isfinite(contour.min_z) || !std::isfinite(contour.max_z))
            throw std::runtime_error("Contours: nonfinite bounds");
        for (const auto &vertex : contour.vertices)
            if (!std::isfinite(vertex.x) || !std::isfinite(vertex.z))
                throw std::runtime_error("Contours: nonfinite vertex");
    }
    records.swap(loaded);
    invalidateGrid();
}

void Contours::load()
{
    loadBytes(g_sfera_files.readAll("landscape\\contours.bin"));
}



std::span<const Contour> Contours::typeRange(int first, int last) const
{
    const auto begin = std::find_if(records.begin(), records.end(), std::bind_front(reachesContourType, first));
    if (begin == records.end() || begin->type > last)
        return {};
    const auto end = std::find_if(begin, records.end(), std::bind_front(exceedsContourType, last));
    return {begin, end};
}


bool Contours::sameEdge(std::size_t first_contour, std::size_t first_edge, std::size_t second_contour, std::size_t second_edge) const
{
    const auto &first = records.at(first_contour);
    const auto &second = records.at(second_contour);
    if (first_edge >= first.vertices.size() || second_edge >= second.vertices.size())
        throw std::out_of_range("Contours: invalid edge");
    const auto first_next = first_edge + 1 == first.vertices.size() ? 0 : first_edge + 1;
    const auto second_next = second_edge + 1 == second.vertices.size() ? 0 : second_edge + 1;

    return (sameVertex(first, second, first_edge, second_edge) && sameVertex(first, second, first_next, second_next)) ||
           (sameVertex(first, second, first_edge, second_next) && sameVertex(first, second, first_next, second_edge));
}

void Contours::setServerMap(std::span<const int> types, std::span<const int> servers)
{
    if (types.empty() || types.size() != servers.size())
        throw std::invalid_argument("Contours: invalid server map");
    std::vector<std::pair<int, int>> replacement;
    replacement.reserve(types.size());
    for (std::size_t i = 0; i < types.size(); ++i)
        replacement.emplace_back(types[i], servers[i]);
    server_map.swap(replacement);
    invalidateGrid();
}

int Contours::serverByType(int type) const
{
    for (const auto &entry : server_map)
        if (entry.first == type)
            return entry.second;
    SphereUIInterfaceRenderer::reportError(("Contours: no server for type " + std::to_string(type)));
    return 0;
}

int Contours::typeAt(float x, float z, int first, int last) const
{
    const auto selected = typeRange(first, last);
    for (auto item = selected.rbegin(); item != selected.rend(); ++item)
    {
        if (item->contains(x, z))
            return item->type;
    }
    return -1;
}

int Contours::serverAt(float x, float z) const
{
    const auto type = typeAt(x, z, first_server_type, last_server_type);
    return type == -1 ? 0 : serverByType(type);
}

void Contours::connectEdges()
{
    if (!std::in_range<int>(records.size()))
        throw std::length_error("Too many server contours");
    for (std::size_t first = 0; first < records.size(); ++first)
    {
        auto &contour = records[first];
        if (!std::in_range<int>(contour.vertices.size()))
            throw std::length_error("Too many contour vertices");
        if (!isServerContour(contour))
            continue;
        for (std::size_t edge = 0; edge < contour.vertices.size(); ++edge)
        {
            contour.vertices[edge].neighbour_contour = contour.vertices[edge].neighbour_edge = -1;
            bool found = false;
            for (std::size_t second = 0; second < records.size() && !found; ++second)
            {
                if (!isServerContour(records[second]))
                    continue;
                for (std::size_t other = 0; other < records[second].vertices.size(); ++other)
                {
                    if ((first == second && edge == other) || !sameEdge(first, edge, second, other))
                        continue;
                    if (!std::in_range<int>(records[second].vertices.size()))
                        throw std::length_error("Too many contour vertices");
                    contour.vertices[edge].neighbour_contour = SferaNumeric::signedWord(SferaNumeric::lowWord(second));
                    contour.vertices[edge].neighbour_edge = SferaNumeric::signedWord(SferaNumeric::lowWord(other));
                    records[second].vertices[other].neighbour_contour = SferaNumeric::signedWord(SferaNumeric::lowWord(first));
                    records[second].vertices[other].neighbour_edge = SferaNumeric::signedWord(SferaNumeric::lowWord(edge));
                    found = true;
                    break;
                }
            }
        }
    }
}

std::vector<std::array<float, 4>> Contours::serverBoundaries()
{
    if (server_map.empty())
        throw std::logic_error("Contours: server map is not configured");
    connectEdges();
    std::size_t directed_count = 0;
    for (std::size_t index = 0; index < records.size(); ++index)
    {
        const auto &contour = records[index];
        if (!isServerContour(contour))
            continue;
        for (std::size_t edge = 0; edge < contour.vertices.size(); ++edge)
        {
            const auto neighbour = contour.vertices[edge].neighbour_contour;
            if (neighbour < 0)
                continue;
            const auto &adjacent = records.at(neighbour);
            if (serverByType(adjacent.type) == serverByType(contour.type))
                continue;
            const auto other = contour.vertices[edge].neighbour_edge;
            if (other < 0 || std::cmp_greater_equal(other, adjacent.vertices.size()) || !std::cmp_equal(adjacent.vertices[other].neighbour_contour, index) ||
                !std::cmp_equal(adjacent.vertices[other].neighbour_edge, edge))
                throw std::logic_error("Wrong connection of server contours");
            ++directed_count;
        }
    }
    if ((directed_count & 1u) != 0u)
        throw std::logic_error("Contours: unmatched server boundary");
    std::vector<std::array<float, 4>> result;
    result.reserve(directed_count / 2u);
    for (auto &contour : records)
    {
        if (!isServerContour(contour))
            continue;
        for (std::size_t edge = 0; edge < contour.vertices.size(); ++edge)
        {
            const auto neighbour = contour.vertices[edge].neighbour_contour;
            if (neighbour < 0)
                continue;
            auto &adjacent = records[neighbour];
            if (serverByType(adjacent.type) == serverByType(contour.type))
                continue;
            const auto next = edge + 1 == contour.vertices.size() ? 0 : edge + 1;
            result.push_back({contour.vertices[edge].x, contour.vertices[edge].z, contour.vertices[next].x, contour.vertices[next].z});
            adjacent.vertices[contour.vertices[edge].neighbour_edge].neighbour_contour = -1;
        }
    }
    return result;
}

void Contours::rasterizeServers()
{
    server_grid.fill(0);
    const Contour *cached = nullptr;
    std::uint8_t cached_server = 0;
    const auto selected = typeRange(first_server_type, last_server_type);
    for (int x = 0; x < 160; ++x)
        for (int z = 0; z < 160; ++z)
        {
            const float point_x = SferaNumeric::real32(-3975 + x * 50), point_z = SferaNumeric::real32(-3975 + z * 50);
            const std::size_t cell = x * 160 + z;
            if (cached != nullptr && cached->contains(point_x, point_z))
            {
                server_grid[cell] = cached_server;
                continue;
            }
            for (const auto &contour : selected)
                if (contour.contains(point_x, point_z))
                {
                    cached = &contour;
                    cached_server = SferaNumeric::lowByte(SferaNumeric::lowWord(serverByType(contour.type)));
                    server_grid[cell] = cached_server;
                    break;
                }
        }
    grid_initialized = true;
    mask_server = -1;
}

void Contours::buildServerMask(std::uint8_t server)
{
    server_mask.fill(0);
    for (int x = 0; x < 160; ++x)
        for (int z = 0; z < 160; ++z)
        {
            if (server_grid[x * 160 + z] != server)
                continue;
            for (auto nx = std::max(0, x - 2); nx <= std::min(159, x + 2); ++nx)
                for (auto nz = std::max(0, z - 2); nz <= std::min(159, z + 2); ++nz)
                    server_mask[nx * 160 + nz] = 1;
        }
    mask_server = server;
}

bool Contours::nearServer(float x, float z, int server)
{
    if (server < 0 || server > 100 || server_map.empty())
        throw std::invalid_argument("Contours: invalid server selection");
    if (!grid_initialized)
        rasterizeServers();
    if (server != mask_server)
        buildServerMask(SferaNumeric::lowByte(SferaNumeric::lowWord(server)));
    const double cell_x = (x + 4000.0) / 50.0, cell_z = (z + 4000.0) / 50.0;
    if (!std::isfinite(cell_x) || !std::isfinite(cell_z) || cell_x <= -1.0 || cell_x >= 160.0 || cell_z <= -1.0 || cell_z >= 160.0)
        return false;
    const int slot = SferaNumeric::truncateInt(cell_x * 160u + cell_z);
    return slot >= 0 && std::cmp_less(slot, server_mask.size()) && server_mask[slot] != 0;
}

void Contours::rebuildServerWall()
{
    const auto boundaries = serverBoundaries();
    g_sfera_server_wall.setSegments(boundaries);
}

SferaServerWallLine SferaServerWallLine::through(const SferaVec3F &first, const SferaVec3F &second)
{
    const double firstX = first.x, firstZ = first.z, secondX = second.x, secondZ = second.z;
    SferaServerWallLine result;
    result.x = SferaNumeric::real32(secondZ - firstZ);
    result.z = SferaNumeric::real32(firstX - secondX);
    result.constant = SferaNumeric::real32(secondX * firstZ - firstX * secondZ);
    return result;
}

float SferaServerWallLine::evaluate(const SferaVec3F &point) const
{
    const double alongX = x, alongZ = z;
    return SferaNumeric::real32(alongX * point.x + alongZ * point.z + constant);
}

void SferaServerWall::clear()
{
    segments.clear();
    normals.clear();
    for (auto &effect : effects)
        effect.remaining = -1.0f;
}

void SferaServerWall::setSegments(std::span<const std::array<float, 4>> coordinates)
{
    clear();
    if (coordinates.empty())
        return;
    segments.reserve(coordinates.size());
    for (const auto &row : coordinates)
        segments.push_back({SferaVec3F{row[0], 1.0f, row[1]}, SferaVec3F{row[2], 1.0f, row[3]}});
    prepareGeometry();
    texture_id = g_sfera_textures.find("fx_swall");
}

void SferaServerWall::prepareGeometry()
{
    normals.clear();
    normals.reserve(segments.size());
    for (const auto &segment : segments)
    {
        const double firstHeight = segment[0].y, secondHeight = segment[1].y;
        const float x = SferaNumeric::real32(firstHeight * segment[1].z - secondHeight * segment[0].z);
        const float z = SferaNumeric::real32(secondHeight * segment[0].x - firstHeight * segment[1].x);
        const SferaVec3F perpendicular{x, 0.0f, z};
        const float length = perpendicular.length();
        const float reciprocal = SferaNumeric::real32(length == 0.0f ? 1.0 : 1.0 / length);
        auto normal = perpendicular * reciprocal;
        normal.y = 0.0f;
        normals.push_back(normal);
    }
    for (auto &effect : effects)
        effect = SferaServerWallEffectRecord{};
    for (std::size_t row = 0; row < 4; ++row)
        for (std::size_t column = 0; column < 4; ++column)
        {
            auto &frame = texture_frames[row * 4 + column];
            const float u = column * 0.25f, v = row * 0.25f;
            frame = {};
            frame.uv[1][0] = frame.uv[4][0] = u;
            frame.uv[2][0] = frame.uv[3][0] = u + 0.25f;
            frame.uv[1][1] = frame.uv[2][1] = v;
            frame.uv[3][1] = frame.uv[4][1] = v + 0.25f;
        }
}

bool SferaServerWall::intersectPlane(const SferaPlaneF &plane, const SferaVec3F &start, const SferaVec3F &end, SferaVec3F &output)
{
    const auto direction = end - start;
    const float denominator = SferaNumeric::real32(plane.normal.dot(direction));
    if (!(denominator < -std::numeric_limits<float>::min()))
        return false;
    const float roundedDistance = SferaNumeric::real32(plane.evaluate(start));
    const double distance = roundedDistance;
    if (!(distance >= 0.0 && distance + denominator < 0.0))
        return false;
    const float ratio = SferaNumeric::real32(distance / denominator);
    output = start.subtractScaled(direction, ratio);
    return true;
}

std::uint32_t SferaServerWall::classifyVisibility(const SferaFrustumF &frustum, std::span<const SferaVec3F> points)
{
    bool intersects = false;
    for (const auto plane_index : {0, 1, 3, 5})
    {
        const auto &plane = frustum.planes[plane_index];
        std::size_t outside = 0;
        for (const auto &point : points)
            if (point.dot<double, true>(plane.normal) + plane.distance < 0.0)
                ++outside;
        if (outside == points.size())
            return 0u;
        intersects = intersects || outside != 0;
    }
    return intersects ? 1u : 2u;
}

int SferaServerWall::intersectXZ(const SferaVec3F &first, const SferaVec3F &second, const SferaVec3F &other_first, const SferaVec3F &other_second, SferaVec3F &output)
{
    const auto a = SferaServerWallLine::through(first, second), b = SferaServerWallLine::through(other_first, other_second);
    for (const auto pair : {std::array{a.evaluate(other_first), a.evaluate(other_second)}, std::array{b.evaluate(first), b.evaluate(second)}})
    {
        if (pair[0] < 0.0f && pair[1] < 0.0f)
            return -1;
        if (pair[0] > 0.0f && pair[1] > 0.0f)
            return 1;
    }
    const double x = a.x, z = a.z, constant = a.constant;
    const float determinant = SferaNumeric::real32(x * b.z - z * b.x);
    if (determinant == 0.0f)
        return -2;
    const float reciprocal = SferaNumeric::real32(1.0 / determinant);
    output.x = SferaNumeric::real32((z * b.constant - constant * b.z) * reciprocal);
    output.y = first.y;
    output.z = SferaNumeric::real32((constant * b.x - x * b.constant) * reciprocal);
    return 0;
}

void SferaServerWall::generateEffects()
{
    const auto *observer = g_sfera_world_objects.object(1u);
    if (observer != nullptr)
        generateEffects(*observer, g_sfera_camera.field_of_view, SphereRenderSceneRenderer::frustum);
}

auto SferaServerWall::distanceToObserver(const WorldObject &observer, const SferaVec3F &point)
{
    auto delta = observer.position - point;
    delta.y = 0.0f;
    // Keep the unrounded square root used when ordering the endpoints.
    const float square = SferaNumeric::real32(delta.dot(delta));
    const double radicand = square;
    return std::sqrt(radicand);
}

bool SferaServerWall::isWallEffectAvailable(const SferaServerWallEffectRecord &effect)
{
    return !(effect.remaining > 0.0f);
}

void SferaServerWall::generateEffects(const WorldObject &observer, float field_of_view, const SferaFrustumF &frustum)
{
    if (segments.empty() || observer.position.y > 1000.0f)
        return;
    const double heading = observer.rotation.x + 1.5707964897155762;
    const float left_angle = SferaNumeric::real32(heading + field_of_view * 0.5), right_angle = SferaNumeric::real32(heading - field_of_view * 0.5);
    const auto left = SferaMath::rotationTerms(left_angle), right = SferaMath::rotationTerms(right_angle);
    auto left_ray = observer.position, right_ray = observer.position;
    left_ray.x = SferaNumeric::real32(left_ray.x + left.cosine * 60.0);
    left_ray.z = SferaNumeric::real32(left_ray.z + left.sine * 60.0);
    right_ray.x = SferaNumeric::real32(right_ray.x + right.cosine * 60.0);
    right_ray.z = SferaNumeric::real32(right_ray.z + right.sine * 60.0);
    if ((std::rand() & 1) == 0)
        return;
    for (std::size_t index = 0; index < segments.size(); ++index)
    {
        if ((std::rand() & 1) == 0)
            continue;
        auto first = segments[index][0], second = segments[index][1];
        first.y = second.y = observer.position.y;
        const auto difference = second - first;
        const auto midpoint = first + difference * 0.5f;
        const float side = SferaNumeric::real32(normals[index].dot(midpoint - observer.position));
        if (side == 0.0f)
            continue;
        SferaVec3F start = first, end = second;
        const auto left_result = intersectXZ(first, second, observer.position, left_ray, side > 0.0f ? end : start);
        const auto right_result = intersectXZ(first, second, observer.position, right_ray, side > 0.0f ? start : end);
        const auto visibility = classifyVisibility(frustum, segments[index]);
        if (left_result != 0 && right_result != 0 && visibility == 0u)
            continue;
        start.y = end.y = observer.position.y;
        if (visibility == 1u)
        {
            const auto original_start = start, original_end = end;
            SferaVec3F intersection;
            if (intersectPlane(frustum.planes[0], original_start, original_end, intersection))
                start = intersection;
            if (intersectPlane(frustum.planes[5], original_start, original_end, intersection))
                end = intersection;
        }
        auto horizontal = end - start;
        horizontal.y = 0.0f;
        const float length = horizontal.length();
        if (length == 0.0f)
            continue;
        const float fraction = SferaNumeric::real32(length > 40.0f ? 40.0 / length : 1.0);
        const float reciprocal = SferaNumeric::real32(1.0 / length);
        auto direction = horizontal * reciprocal;
        direction.y = 0.0f;

        if (distanceToObserver(observer, end) < distanceToObserver(observer, start))
            std::swap(start, end);
        const auto limited_end = start + (end - start) * fraction;
        auto free = std::find_if(effects.begin(), effects.end(), isWallEffectAvailable);
        if (free == effects.end())
            continue;
        float along = SferaNumeric::real32(std::rand() / 32767.0);
        const float height_first = SferaNumeric::real32(std::rand() / 32767.0);
        if (along < 0.10000000149011612)
            along = SferaNumeric::real32(along + 0.10000000149011612);
        if (along > 0.8999999761581421)
            along = SferaNumeric::real32(along - 0.10000000149011612);
        SferaVec3F center{SferaMath::interpolate(start.x, limited_end.x, along), 0.0f, SferaMath::interpolate(start.z, limited_end.z, along)};
        center.y = SferaNumeric::real32((height_first - std::rand() / 32767.0) * 10.0 + (start.y - 2.0));
        const float half_size = SferaNumeric::real32((std::rand() % 8 + 20) * 0.5);
        const auto offset = direction * half_size;
        const auto first_side = center - offset, second_side = center + offset;
        const double firstHeight = first_side.y, secondHeight = second_side.y;
        free->positions[0] = free->positions[1] = first_side;
        free->positions[2] = free->positions[3] = second_side;
        free->positions[0].y = SferaNumeric::real32(firstHeight - half_size);
        free->positions[1].y = SferaNumeric::real32(firstHeight + half_size);
        free->positions[2].y = SferaNumeric::real32(secondHeight + half_size);
        free->positions[3].y = SferaNumeric::real32(secondHeight - half_size);
        free->duration = free->remaining = SferaNumeric::real32(std::rand() % 32 + 50);
        free->animation_phase = SferaNumeric::real32(SferaNumeric::lowWord(std::rand() % texture_frames.size()));
    }
}

void SferaServerWall::updateEffectRendering()
{
    if (segments.empty())
        return;
    for (auto &effect : effects)
    {
        if (effect.remaining <= 0.0f)
            continue;
        if (g_sfera_effect_manager.render_slot_count + 1u >= 10000u)
            break;
        effect.remaining -= 1.0f;
        const float ratio = effect.duration == 0.0f ? 0.0f : effect.remaining / effect.duration;
        const std::uint32_t alpha = SferaNumeric::truncatedWord(std::trunc((0.5f - 0.5f * std::cos(ratio * 6.283185958862305f)) * 100.0f));
        auto *slot = g_sfera_effect_manager.acquireRenderSlot();
        if (slot == nullptr)
            break;
        slot->additive = true;
        slot->custom_uv = true;
        slot->resource_id = texture_id;
        slot->self_illumination = 255u;
        for (std::size_t vertex = 0; vertex < 4; ++vertex)
        {
            slot->position[vertex] = effect.positions[vertex];
            slot->color[0][vertex] = slot->color[1][vertex] = slot->color[2][vertex] = 255u;
            slot->color[3][vertex] = alpha;
        }
        effect.animation_phase += 0.25f;
        const auto frame = SferaNumeric::truncatedWord(effect.animation_phase) % texture_frames.size();
        for (std::size_t vertex = 0; vertex < 4; ++vertex)
        {
            slot->uv[vertex][0] = texture_frames[frame].uv[vertex + 1u][0];
            slot->uv[vertex][1] = texture_frames[frame].uv[vertex + 1u][1];
        }
    }
}
