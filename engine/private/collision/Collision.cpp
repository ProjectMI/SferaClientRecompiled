#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <span>
#include <utility>
#include <variant>
#include <vector>

#include "scene/SceneObject.h"
#include "algorithms/StableSort.h"
#include "animation/Animation.h"
#include "collision/Collision.h"
#include "diagnostics/Diagnostics.h"
#include "environment/Environment.h"
#include "geometry/Geometry.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/Model.h"
#include "scene/SceneAccess.h"
#include "spatial/Bounds.h"
#include "spatial/SpatialIndex.h"
#include "terrain/TerrainData.h"

SferaMatrix4x4F SphereCollisionGeometry::rotationOnly(SferaMatrix4x4F value)
{
    value.m[0][3] = value.m[1][3] = value.m[2][3] = 0.0f;
    return value;
}

void SphereCollisionGeometry::updateTriangleBounds(SphereRenderModelCollisionTriangle &triangle)
{
    triangle.minimum = triangle.maximum = triangle.vertices[0];
    for (std::size_t vertex = 1; vertex < 3; ++vertex)
    {
        for (std::size_t axis = 0; axis < 3; ++axis)
        {
            const float value = triangle.vertices[vertex].component(axis);
            if (value < triangle.minimum.component(axis))
                triangle.minimum.setComponent(axis, value);
            else if (value > triangle.maximum.component(axis))
                triangle.maximum.setComponent(axis, value);
        }
    }
}

SphereRenderModelCollisionTriangle SphereCollisionGeometry::worldTriangle(const SphereRenderModelCollisionTriangle &triangle, const SferaMatrix4x4F &transform)
{
    auto result = triangle;
    for (auto &point : result.vertices)
        point = transform.transformPoint(point);
    result.normal = SphereCollisionGeometry::rotationOnly(transform).transformPoint(triangle.normal);
    SphereCollisionGeometry::updateTriangleBounds(result);
    return result;
}

SphereRenderModelCollisionTriangle SphereCollisionGeometry::terrainTriangle(const SphereWorldTerrainCandidate &candidate, const TerrainTriangle &face)
{
    SphereRenderModelCollisionTriangle result;
    for (std::size_t i = 0; i < 3; ++i)
    {
        result.vertices[i] = candidate.patch->vertices[face.indices[i]].position;
        const double x = result.vertices[i].x, z = result.vertices[i].z;
        result.vertices[i].x = SferaNumeric::real32(x + candidate.origin_x);
        result.vertices[i].z = SferaNumeric::real32(z + candidate.origin_z);
    }
    result.normal = face.normal;
    return result;
}

SphereWorldBounds SphereWorldContactQuery::currentSpatialBounds()
{
    return {{g_sfera_world_spatial.query_bounds.minimum.x, g_sfera_world_spatial.query_bounds.minimum.y, g_sfera_world_spatial.query_bounds.minimum.z},
            {g_sfera_world_spatial.query_bounds.maximum.x, g_sfera_world_spatial.query_bounds.maximum.y, g_sfera_world_spatial.query_bounds.maximum.z}};
}

void SphereWorldContactQuery::publishWorldBounds(const SphereWorldBounds &value)
{
    g_sfera_contacts.query_bounds.minimum = {{value.minimum.x}, {value.minimum.y}, {value.minimum.z}};
    g_sfera_contacts.query_bounds.maximum = {{value.maximum.x}, {value.maximum.y}, {value.maximum.z}};
}

void SphereWorldContactQuery::publishSpatialBounds(const SphereWorldBounds &value)
{
    g_sfera_world_spatial.query_bounds.minimum = {{value.minimum.x}, {value.minimum.y}, {value.minimum.z}};
    g_sfera_world_spatial.query_bounds.maximum = {{value.maximum.x}, {value.maximum.y}, {value.maximum.z}};
}

std::array<SferaVec3F, 3> SphereWorldContactQuery::boxAxes(const SferaBoundsCornersRuntime &box, std::uint32_t diagnostic)
{
    return {(box.corners[1] - box.corners[0]).normalized(diagnostic), (box.corners[3] - box.corners[0]).normalized(diagnostic + 1u), (box.corners[5] - box.corners[0]).normalized(diagnostic + 2u)};
}

bool SphereWorldContactQuery::clippedTriangle(const SphereRenderModelCollisionTriangle &triangle, const SphereWorldBounds &bounds)
{
    return g_sfera_clipped_polygon.clipTriangleToBounds(triangle.vertices[0], triangle.vertices[1], triangle.vertices[2], bounds.minimum, bounds.maximum);
}

bool SphereWorldContactQuery::projectionsOverlap(const SferaBoundsCornersRuntime &first, const SferaBoundsCornersRuntime &second, const SferaVec3F &axis)
{
    float minimum[2]{}, maximum[2]{};
    const SferaBoundsCornersRuntime *boxes[]{&first, &second};
    for (std::size_t box = 0; box < 2; ++box)
    {
        for (std::size_t vertex = 0; vertex < 8; ++vertex)
        {
            const auto &point = boxes[box]->corners[vertex];
            const float projection = SferaNumeric::real32(point.dot<double, true>(axis));
            if (vertex == 0)
                minimum[box] = maximum[box] = projection;
            else if (projection < minimum[box])
                minimum[box] = projection;
            else if (projection > maximum[box])
                maximum[box] = projection;
        }
    }
    return !(minimum[0] > maximum[1] || minimum[1] > maximum[0]);
}

bool SphereWorldContactQuery::boxesOverlap(const SferaBoundsCornersRuntime &first, const SferaBoundsCornersRuntime &second)
{
    std::array<SferaVec3F, 3> first_axes, second_axes;
    const std::size_t corners[]{1u, 3u, 5u};
    for (std::size_t axis = 0; axis < 3; ++axis)
    {
        first_axes[axis] = (first.corners[corners[axis]] - first.corners[0]).normalized(6u + axis);
        if (!projectionsOverlap(first, second, first_axes[axis]))
            return false;
    }
    for (std::size_t axis = 0; axis < 3; ++axis)
    {
        second_axes[axis] = (second.corners[corners[axis]] - second.corners[0]).normalized(9u + axis);
        if (!projectionsOverlap(first, second, second_axes[axis]))
            return false;
    }
    for (const auto &first_axis : first_axes)
        for (const auto &second_axis : second_axes)
            if (!projectionsOverlap(first, second, first_axis.cross(second_axis)))
                return false;
    return true;
}

int SphereWorldContactQuery::intersectTriangle(const SferaVec3F &start, const SferaVec3F &end, const SphereRenderModelCollisionTriangle &triangle, SferaVec3F &intersection)
{
    const SferaPlaneF plane{triangle.normal, triangle.plane_distance};
    if (plane.intersectLine(start, end, intersection) != 1)
        return 0;
    const SferaVec3F *vertices[]{&triangle.vertices[0], &triangle.vertices[1], &triangle.vertices[2]};
    return triangle.normal.containsConvexPolygonPoint(vertices, intersection) ? 2 : 1;
}

float SphereWorldContactQuery::triangleVerticalNormal(const SphereRenderModelCollisionTriangle &triangle)
{
    return std::fabs(triangle.normal.y);
}

void SphereWorldContactQuery::sortTriangles(std::span<SphereRenderModelCollisionTriangle> triangles)
{
    SferaAlgorithms::stableSort(triangles, triangleVerticalNormal);
}

void SphereWorldContactQuery::updateBounds(std::uint32_t handle)
{
    auto *object = SferaSceneAccess::object(handle);
    if (object->extended())
    {
        auto *extended = SferaSceneAccess::extendedObject(handle);
        if (extended->previous_bounds_position.x == object->position.x && extended->previous_bounds_position.y == object->position.y && extended->previous_bounds_position.z == object->position.z &&
            extended->previous_bounds_rotation.x == object->rotation.x && extended->previous_bounds_rotation.y == object->rotation.y && extended->previous_bounds_rotation.z == object->rotation.z)
            return;
        extended->previous_bounds_position = object->position;
        extended->previous_bounds_rotation = object->rotation;
    }
    const auto *model = SferaSceneAccess::model(*object);
    if (model->collision_kind == SphereRenderCollisionKind::AxisAlignedBounds || model->collision_kind == SphereRenderCollisionKind::None)
    {
        object->bounds_minimum = model->minimum + object->position;
        object->bounds_maximum = model->maximum + object->position;
        return;
    }
    object->world_transform = SferaMatrix4x4F::fromEuler(object->position, object->rotation);
    SferaBoundsCornersRuntime transformed;
    for (std::size_t i = 0; i < 8; ++i)
        object->bounds_corners[i] = transformed.corners[i] = object->world_transform.transformPoint(model->oriented_corners.corners[i]);
    transformed.getExtents(object->bounds_minimum, object->bounds_maximum);
}

void SphereWorldContactQuery::appendBoxNormals(const SferaBoundsCornersRuntime &corners)
{
    for (const auto &normal : SphereWorldContactQuery::boxAxes(corners, 2u))
    {
        if (std::fabs(normal.y) > 0.800000011920929f)
            continue;
        publishNormal(normal);
        publishNormal(normal * -1.0f);
    }
}

void SphereWorldContactQuery::publishDirection(const SphereRenderModelCollisionTriangle &triangle)
{
    support_normal = triangle.normal;
    support_direction = (triangle.collision_flags >> 8u) & 255u;
}

void SphereWorldContactQuery::gather(std::uint32_t handle)
{
    auto *subject = SferaSceneAccess::object(handle);
    if (!subject)
    {
        SferaEngineDiagnostics::report("GreatherNearCldInfo: wrong handle");
        return;
    }
    const auto *subject_model = SferaSceneAccess::model(*subject);
    const SphereWorldBounds gathered_bounds = SphereWorldContactQuery::currentSpatialBounds();
    SphereWorldContactQuery::publishWorldBounds(gathered_bounds);
    contacts_.clear();
    g_sfera_world_spatial.gatherObject(handle);
    for (const auto candidate_handle : g_sfera_world_spatial.objects())
    {
        auto *object = SferaSceneAccess::object(candidate_handle);
        const auto *model = SferaSceneAccess::model(*object);
        if (candidate_handle == handle || (object->extended() && SferaSceneAccess::extendedObject(candidate_handle)->render_enabled == 0u) ||
            model->collision_kind == SphereRenderCollisionKind::None || !SphereWorldWorldSpatialIndex::typesInteract(subject->render_group * 7u + object->render_group))
            continue;
        updateBounds(candidate_handle);
        const SphereWorldBounds object_bounds{object->bounds_minimum, object->bounds_maximum};
        if (!gathered_bounds.intersects(object_bounds))
            continue;
        SphereWorldNearContact contact;
        contact.handle = candidate_handle;
        contact.subject_kind = subject_model->collision_kind;
        contact.geometry_kind = model->collision_kind;
        contact.bounds = object_bounds;
        std::copy_n(object->bounds_corners, 8u, contact.corners.corners);
        if (contact.geometry_kind <= SphereRenderCollisionKind::OrientedBounds)
        {
            contacts_.push_back(std::move(contact));
            continue;
        }
        if (contact.subject_kind == SphereRenderCollisionKind::Triangles)
        {
            if (model->radius < subject_model->radius)
            {
                contact.geometry_kind = SphereRenderCollisionKind::OrientedBounds;
                contacts_.push_back(std::move(contact));
                continue;
            }
            contact.subject_kind = SphereRenderCollisionKind::OrientedBounds;
        }
        const SphereWorldBounds local_bounds = gathered_bounds.inverseTransformed(object->world_transform);
        std::vector<std::vector<SphereRenderModelCollisionTriangle>> groups;
        std::size_t total = 0;
        for (std::size_t group_index = 0; group_index < model->collision_groups.size(); ++group_index)
        {
            const auto &group = model->collision_groups[group_index];
            const auto &bone = model->bones[group.bone];
            if (const auto *bounds = std::get_if<SphereRenderBoneBounds>(&bone.data); bounds && !local_bounds.intersects({bounds->minimum, bounds->maximum}))
                continue;
            std::vector<SphereRenderModelCollisionTriangle> triangles;
            for (std::size_t face = 0; face < group.triangle_count; ++face)
            {
                const auto &source = model->collision_triangles[group.first_triangle + face];
                if (!local_bounds.intersectsInterior({source.minimum, source.maximum}))
                    continue;
                auto triangle = SphereCollisionGeometry::worldTriangle(source, object->world_transform);
                if (!SphereWorldContactQuery::clippedTriangle(triangle, gathered_bounds))
                    continue;
                triangles.push_back(triangle);
                if (++total >= 2000u)
                {
                    contacts_.clear();
                    return;
                }
            }
            if (!triangles.empty())
                groups.push_back(std::move(triangles));
        }
        if (total == 0)
            continue;
        std::vector<std::size_t> consumed(groups.size());
        contact.triangles.reserve(total);
        while (contact.triangles.size() < total)
        {
            float smallest = 2.0f;
            std::size_t selected = groups.size();
            for (std::size_t group = 0; group < groups.size(); ++group)
            {
                if (consumed[group] == groups[group].size())
                    continue;
                const float key = std::fabs(groups[group][consumed[group]].normal.y);
                if (smallest > key)
                {
                    smallest = key;
                    selected = group;
                }
            }
            if (selected == groups.size())
            {
                SferaEngineDiagnostics::report("Collision normal exceeds unit length");
                return;
            }
            contact.triangles.push_back(groups[selected][consumed[selected]++]);
        }
        contacts_.push_back(std::move(contact));
    }
    SphereWorldNearContact landscape;
    landscape.handle = 1u;
    landscape.subject_kind = subject_model->collision_kind == SphereRenderCollisionKind::Triangles ? SphereRenderCollisionKind::OrientedBounds : subject_model->collision_kind;
    landscape.geometry_kind = SphereRenderCollisionKind::Triangles;
    for (const auto &candidate : g_sfera_world_spatial.terrain())
        for (std::size_t face = 0; face < candidate.cell->triangles.size(); ++face)
        {
            auto triangle = SphereCollisionGeometry::terrainTriangle(candidate, candidate.cell->triangles[face]);
            if (SphereWorldContactQuery::clippedTriangle(triangle, gathered_bounds))
                landscape.triangles.push_back(triangle);
        }
    if (!landscape.triangles.empty())
    {
        sortTriangles(landscape.triangles);
        contacts_.push_back(std::move(landscape));
    }
}

bool SphereWorldContactQuery::trianglesHitBox(const SphereRenderModel &model, const SferaMatrix4x4F &transform, const SphereWorldBounds &query_bounds, const SphereWorldBounds &local_bounds,
                                              const SferaMatrix4x4F *box_transform, const SferaMatrix4x4F *box_basis)
{
    SphereWorldContactQuery::publishWorldBounds(query_bounds);
    for (std::size_t group_index = 0; group_index < model.collision_groups.size(); ++group_index)
    {
        const auto &group = model.collision_groups[group_index];
        const auto &bone = model.bones[group.bone];
        if (const auto *bounds = std::get_if<SphereRenderBoneBounds>(&bone.data); bounds && !local_bounds.intersects({bounds->minimum, bounds->maximum}))
            continue;
        for (std::size_t face = 0; face < group.triangle_count; ++face)
        {
            const auto &source = model.collision_triangles[group.first_triangle + face];
            if (!local_bounds.intersects({source.minimum, source.maximum}))
                continue;
            auto triangle = source;
            for (auto &point : triangle.vertices)
            {
                point = transform.transformPoint(point);
                if (box_transform)
                    point = box_transform->inverseTransformPoint(point);
                if (box_basis)
                    point = box_basis->inverseTransformPoint(point);
            }
            if (SphereWorldContactQuery::clippedTriangle(triangle, query_bounds))
                return true;
        }
    }
    return false;
}

std::uint32_t SphereWorldContactQuery::test(std::uint32_t handle, SphereWorldContactQueryMode mode, bool reuse_cache, bool honor_ignored)
{
    updateBounds(handle);
    auto *subject = SferaSceneAccess::object(handle);
    const auto *subject_model = SferaSceneAccess::model(*subject);
    const SphereWorldBounds subject_bounds{subject->bounds_minimum, subject->bounds_maximum};
    obstacle_height = 1000.0f;
    switch (mode)
    {
    case SphereWorldContactQueryMode::Movement:
    case SphereWorldContactQueryMode::Normals:
        normals_.clear();
        break;
    case SphereWorldContactQueryMode::Support:
        support_normal = {{0.0f}, {-1.0f}, {0.0f}};
        support_direction = 0;
        break;
    case SphereWorldContactQueryMode::Material:
        surface_material = 6;
        break;
    case SphereWorldContactQueryMode::CollectIgnored:
        ignored_.clear();
        break;
    default:
        break;
    }
    if (!reuse_cache || !SphereWorldContactQuery::currentSpatialBounds().contains(subject_bounds))
    {
        SphereWorldContactQuery::publishSpatialBounds(subject_bounds.expanded(1.2000000476837158f));
        gather(handle);
    }
    SphereWorldContactQuery::publishWorldBounds(subject_bounds);
    for (const auto &contact : contacts_)
    {
        if (contact.handle != 1u && !subject_bounds.intersects(contact.bounds))
            continue;
        if (honor_ignored && mode != SphereWorldContactQueryMode::Material && mode != SphereWorldContactQueryMode::CollectIgnored &&
            std::find(ignored_.begin(), ignored_.end(), contact.handle) != ignored_.end())
            continue;
        if (mode == SphereWorldContactQueryMode::Material && contact.geometry_kind != SphereRenderCollisionKind::Triangles)
            continue;
        auto *candidate = SferaSceneAccess::object(contact.handle);
        const auto *candidate_model = SferaSceneAccess::model(*candidate);
        if (contact.subject_kind <= SphereRenderCollisionKind::OrientedBounds && contact.geometry_kind <= SphereRenderCollisionKind::OrientedBounds)
        {
            bool hit = true;
            if (contact.subject_kind == SphereRenderCollisionKind::AxisAlignedBounds && contact.geometry_kind == SphereRenderCollisionKind::OrientedBounds)
                hit = boxesOverlap(subject_bounds.corners(), contact.corners);
            if (contact.subject_kind == SphereRenderCollisionKind::OrientedBounds)
            {
                SferaBoundsCornersRuntime subject_corners;
                std::copy_n(subject->bounds_corners, 8u, subject_corners.corners);
                hit = boxesOverlap(contact.geometry_kind == SphereRenderCollisionKind::AxisAlignedBounds ? contact.bounds.corners() : contact.corners, subject_corners);
            }
            if (!hit)
                continue;
            if (mode == SphereWorldContactQueryMode::CollectIgnored)
            {
                ignored_.push_back(contact.handle);
                continue;
            }
            if (contact.subject_kind == SphereRenderCollisionKind::AxisAlignedBounds && contact.geometry_kind == SphereRenderCollisionKind::OrientedBounds &&
                mode == SphereWorldContactQueryMode::Normals)
                appendBoxNormals(contact.corners);
            return contact.handle;
        }
        if (contact.subject_kind <= SphereRenderCollisionKind::OrientedBounds && contact.geometry_kind == SphereRenderCollisionKind::Triangles)
        {
            const SphereWorldBounds clip_bounds = contact.subject_kind == SphereRenderCollisionKind::AxisAlignedBounds ? subject_bounds : SphereWorldBounds{{}, subject_model->oriented_size};
            SphereWorldContactQuery::publishWorldBounds(clip_bounds);
            for (std::size_t position = 0; position < contact.triangles.size(); ++position)
            {
                const std::size_t index = mode == SphereWorldContactQueryMode::Support ? contact.triangles.size() - position - 1u : position;
                const auto &triangle = contact.triangles[index];
                const std::uint32_t material = triangle.collision_flags & 255u;
                if (mode == SphereWorldContactQueryMode::Material ? material == 0u || material >= surface_material : material > 0u)
                    continue;
                if (contact.handle != 1u && !subject_bounds.intersects({triangle.minimum, triangle.maximum}))
                    continue;
                auto local_triangle = triangle;
                if (contact.subject_kind == SphereRenderCollisionKind::OrientedBounds)
                    for (auto &point : local_triangle.vertices)
                        point = subject_model->bounds_transform.inverseTransformPoint(subject->world_transform.inverseTransformPoint(point));
                if (!SphereWorldContactQuery::clippedTriangle(local_triangle, clip_bounds))
                    continue;
                if (mode == SphereWorldContactQueryMode::Material)
                {
                    surface_material = material;
                    SferaSceneAccess::notifyContact(handle, *candidate, contact.subject_kind);
                    continue;
                }
                if (mode == SphereWorldContactQueryMode::CollectIgnored)
                {
                    ignored_.push_back(contact.handle);
                    break;
                }
                if (mode == SphereWorldContactQueryMode::Support)
                {
                    publishDirection(triangle);
                    return contact.handle;
                }
                if (mode == SphereWorldContactQueryMode::Movement || mode == SphereWorldContactQueryMode::Normals)
                {
                    if (contact.subject_kind == SphereRenderCollisionKind::OrientedBounds)
                        return contact.handle;
                    if (mode == SphereWorldContactQueryMode::Normals)
                    {
                        publishNormal(triangle.normal);
                        continue;
                    }
                    if (contact.handle != 1u)
                    {
                        const double top = candidate_model->oriented_corners.corners[2].y;
                        obstacle_height = SferaNumeric::real32(top - candidate_model->oriented_corners.corners[0].y);
                    }
                    normals_.clear();
                    publishNormal(triangle.normal);
                    return contact.handle;
                }
            }
            SphereWorldContactQuery::publishWorldBounds(subject_bounds);
            if (contact.subject_kind == SphereRenderCollisionKind::AxisAlignedBounds && mode == SphereWorldContactQueryMode::Normals && !normals_.empty())
                return contact.handle;
            continue;
        }
        if (contact.subject_kind == SphereRenderCollisionKind::Triangles && contact.geometry_kind <= SphereRenderCollisionKind::OrientedBounds)
        {
            SphereWorldBounds local_bounds;
            auto candidate_corners = contact.geometry_kind == SphereRenderCollisionKind::AxisAlignedBounds ? contact.bounds.corners() : contact.corners;
            for (auto &point : candidate_corners.corners)
                point = subject->world_transform.inverseTransformPoint(point);
            candidate_corners.getExtents(local_bounds.minimum, local_bounds.maximum);
            const bool oriented = contact.geometry_kind == SphereRenderCollisionKind::OrientedBounds;
            const SphereWorldBounds clip_bounds = oriented ? SphereWorldBounds{{}, candidate_model->oriented_size} : contact.bounds;
            const bool hit = trianglesHitBox(*subject_model, subject->world_transform, clip_bounds, local_bounds, oriented ? &candidate->world_transform : nullptr,
                                             oriented ? &candidate_model->bounds_transform : nullptr);
            if (hit)
            {
                if (mode != SphereWorldContactQueryMode::CollectIgnored)
                    return contact.handle;
                ignored_.push_back(contact.handle);
            }
            SphereWorldContactQuery::publishWorldBounds(subject_bounds);
        }
    }
    return 0;
}

bool SphereWorldContactQuery::lineOfSight(std::uint32_t handle)
{
    const auto start = SferaSceneAccess::cameraObject()->position;
    const SferaVec3F end{SceneSky::flare_world_position.x, SceneSky::flare_world_position.y, SceneSky::flare_world_position.z};
    const SferaVec3F upper_end = end + SferaVec3F{0.0f, 0.10000000149011612f, 0.0f};
    auto *object = SferaSceneAccess::object(handle);
    const auto *model = SferaSceneAccess::model(*object);
    if (model->collision_kind == SphereRenderCollisionKind::None || (object->extended() && SferaSceneAccess::extendedObject(handle)->parent_object_handle != 0u))
        return true;
    updateBounds(handle);
    SphereWorldBounds bounds{object->bounds_minimum, object->bounds_maximum};
    SphereRenderModelCollisionTriangle thickness;
    thickness.vertices[0] = start;
    thickness.vertices[1] = end;
    thickness.vertices[2] = upper_end;
    if (model->collision_kind != SphereRenderCollisionKind::AxisAlignedBounds)
    {
        bounds = {{}, model->oriented_size};
        for (auto &point : thickness.vertices)
            point = model->bounds_transform.inverseTransformPoint(object->world_transform.inverseTransformPoint(point));
    }
    SphereWorldContactQuery::publishWorldBounds(bounds);
    if (!SphereWorldContactQuery::clippedTriangle(thickness, bounds))
        return true;
    if (model->collision_kind != SphereRenderCollisionKind::Triangles)
        return false;
    const auto local_start = object->world_transform.inverseTransformPoint(start), local_end = object->world_transform.inverseTransformPoint(end);
    SferaVec3F intersection;
    for (std::size_t group_index = 0; group_index < model->collision_groups.size(); ++group_index)
    {
        const auto &group = model->collision_groups[group_index];
        for (std::size_t index = 0; index < group.triangle_count; ++index)
            if (intersectTriangle(local_start, local_end, model->collision_triangles[group.first_triangle + index], intersection) == 2)
                return false;
    }
    return true;
}

void Contour::updateBounds()
{
    min_x = min_z = 1000000.0f;
    max_x = max_z = -1000000.0f;
    for (const auto &vertex : vertices)
    {
        min_x = std::min(min_x, vertex.x);
        max_x = std::max(max_x, vertex.x);
        min_z = std::min(min_z, vertex.z);
        max_z = std::max(max_z, vertex.z);
    }
}

bool Contour::contains(float point_x, float point_z) const
{
    if (point_x < min_x || point_x > max_x || point_z < min_z || point_z > max_z)
        return false;
    std::uint32_t crossings = 0;
    for (std::size_t current = 0; current < vertices.size(); ++current)
    {
        auto left = current, right = current == 0 ? vertices.size() - 1 : current - 1;
        if (vertices[left].x == vertices[right].x)
            continue;
        if (vertices[right].x < vertices[left].x)
            std::swap(left, right);
        const double leftX = vertices[left].x, rightX = vertices[right].x;
        if (leftX >= point_x || rightX < point_x)
            continue;
        const double rightZ = vertices[right].z;
        const float roundedSlope = SferaNumeric::real32((rightZ - vertices[left].z) / (rightX - leftX));
        const double slope = roundedSlope;
        const float intercept = SferaNumeric::real32(vertices[left].z - leftX * slope);
        const float edge_z = SferaNumeric::real32(slope * point_x + intercept);
        if (edge_z > point_z)
            ++crossings;
    }
    return (crossings & 1u) != 0;
}
