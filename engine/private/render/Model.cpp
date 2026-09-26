#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <iterator>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "animation/Animation.h"
#include "collision/Collision.h"
#include "geometry/Geometry.h"
#include "math/MathFunctions.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/Material.h"
#include "render/Model.h"
#include "scene/SceneObject.h"
#include "vegetation/VegetationGeometry.h"

WorldObject::WorldObject() noexcept : model_source(WorldObjectModelReference{})
{
}
WorldObject::~WorldObject() = default;

std::uint32_t SphereRenderMaterial::randomColor(const std::array<float, 3> &variation)
{
    std::uint32_t color = 0;
    for (float amount : variation)
    {
        std::uint32_t channel = 255;
        if (amount > 1e-6)
        {
            const auto random = ::rand();
            const int range = SferaNumeric::truncateInt(std::floor(amount * 255.0 + 0.5));
            if (range > 0)
                channel -= random % range;
        }
        color = (color << 8) | channel;
    }
    return color;
}

void SphereRenderModel::recoverBounds()
{
    const auto first_axis = oriented_corners.corners[5] - oriented_corners.corners[0];
    const auto second_axis = oriented_corners.corners[0] - oriented_corners.corners[3];
    bounds_transform = SferaMatrix4x4F::fromEuler(oriented_corners.corners[0], SferaMath::anglesFromBasis(first_axis, second_axis));
    oriented_size = bounds_transform.inverseTransformPoint(oriented_corners.corners[7]);
    const auto extents = collision_kind == SphereRenderCollisionKind::AxisAlignedBounds ? maximum - minimum : oriented_size;
    minimum_size = std::min({extents.x, extents.y, extents.z});
}

void SphereRenderModel::assignMaterials()
{
    for (std::size_t index = 0u; index < submeshes.size(); ++index)
    {
        const SphereRenderSubmesh &submesh = submeshes[index];
        const SphereRenderMaterial *material = submesh.material;
        const std::string_view bone_name = bones[submesh.bone_index].name;
        for (std::size_t vertex = submesh.first_vertex; vertex < submesh.first_vertex + submesh.vertex_count; ++vertex)
        {
            vertices[vertex].material = material;
            if (bone_name.starts_with("_u"))
                vertices[vertex].normal = {0.0f, -1.0f, 0.0f};
            else if (bone_name.starts_with("_s"))
            {
                const SferaVec3F radial{vertices[vertex].position.x, 0.0f, vertices[vertex].position.z};
                const float length = radial.length<double, float>();
                vertices[vertex].normal = length < 0.00001f ? SferaVec3F{} : radial * (1.0f / length);
            }
        }
    }
}

void SphereRenderModel::prepareGrass(bool synchronized, double ground_y)
{
    std::vector<int> components(vertices.size(), -1);
    int component = 0;
    for (std::size_t submesh_index = 0u; submesh_index < submeshes.size(); ++submesh_index)
    {
        const SphereRenderSubmesh &submesh = submeshes[submesh_index];
        std::vector<bool> visited(submesh.face_count, false);

        for (std::size_t seed = 0u; seed < submesh.face_count; ++seed)
        {
            if (visited[seed])
                continue;
            markGrassFace(visited, components, submesh, component, seed);
            bool changed = true;
            while (changed)
            {
                changed = false;
                for (std::size_t face = seed + 1u; face < submesh.face_count; ++face)
                {
                    if (visited[face])
                        continue;
                    const SphereRenderModelFace &candidate = faces[submesh.first_face + face];
                    if (std::any_of(std::begin(candidate.vertices), std::end(candidate.vertices),
                                    std::bind(&SphereRenderModel::isGrassComponentVertex, std::cref(components), std::cref(submesh), component, std::placeholders::_1)))
                    {
                        markGrassFace(visited, components, submesh, component, face);
                        changed = true;
                    }
                }
            }
            ++component;
        }
    }
    SphereRenderModelGrassData grass_data;
    grass_data.influences.resize(vertices.size());
    const std::uint16_t shared_phase = SferaNumeric::lowHalf(SferaNumeric::lowWord(std::rand()));
    for (std::size_t index = 0u; index < vertices.size(); ++index)
    {
        SphereRenderGrassInfluence &influence = grass_data.influences[index];
        const SferaVec3F &position = vertices[index].position;
        if (position.y - ground_y > 0.0)
            continue;
        if (components[index] < 0)
            throw std::runtime_error(std::string("Vegetation vertex has no face in model '") + name + "'");
        std::optional<std::size_t> nearest;
        float nearest_squared = 0.0f;

        searchGrassAnchor(components, index, ground_y, nearest, nearest_squared, true);
        if (!nearest)
            searchGrassAnchor(components, index, ground_y, nearest, nearest_squared, false);
        if (!nearest)
            throw std::runtime_error(std::string("Vegetation has no ground anchor in model '") + name + "'");
        const float distance = std::sqrt(nearest_squared);
        const double anchor_height = vertices[*nearest].position.y;
        const float alignment = SferaNumeric::real32(std::fabs((position.y - anchor_height) / distance));
        if (alignment < 0.7070000171661377f)
            influence.anchor_kind = SphereRenderGrassInfluenceAnchor::Horizontal;
        else
        {
            influence.anchor_kind = SphereRenderGrassInfluenceAnchor::Vertex;
            influence.anchor_vertex = *nearest;
            influence.distance = distance;
        }
        influence.phase = synchronized ? shared_phase : SferaNumeric::lowHalf(SferaNumeric::lowWord(std::rand()));
        influence.share_phase = synchronized && index != 0u;
    }
    vegetation = std::move(grass_data);
}

void SphereRenderModel::prepareTree(double dead_radius, double phase_multiplier)
{
    std::vector<SphereRenderTreeInfluence> influences(vertices.size());
    float maximum_radius_squared = 0.0f;
    for (const auto &vertex : vertices)
    {
        const float squared = SferaNumeric::real32(SferaMath::planarSquared(vertex.position.x, vertex.position.z));
        maximum_radius_squared = std::max(maximum_radius_squared, squared);
    }
    const float maximum_radius = std::sqrt(maximum_radius_squared);
    float amplitude_scale = SferaNumeric::real32(1.0 / (maximum_radius - dead_radius));
    if (radius < 7.0f)
        amplitude_scale *= 0.4000000059604645;
    const float dead_radius_squared = SferaNumeric::real32(dead_radius * dead_radius);
    for (std::size_t index = 0; index < vertices.size(); ++index)
    {
        const auto &position = vertices[index].position;
        const float distance_squared = SferaNumeric::real32(SferaMath::planarSquared(position.x, position.z));
        if (dead_radius_squared > distance_squared)
            influences[index].amplitude = 0.0f;
        else
        {
            const double distance = std::sqrt(distance_squared);
            influences[index].amplitude = SferaNumeric::real32((distance - dead_radius) * amplitude_scale);
        }
        const double height = position.y;
        const double phase = std::trunc((height + position.x + position.z) * phase_multiplier);
        if (!std::isfinite(phase) || phase < INT32_MIN || phase > INT32_MAX)
            throw std::runtime_error(std::string("Invalid vegetation phase in model '") + name + "'");
        const int whole_phase = SferaNumeric::truncateInt(phase);
        influences[index].phase = SferaNumeric::lowHalf(SferaNumeric::lowWord(whole_phase));
    }
    vegetation = std::move(influences);
}

void SphereRenderModel::initializeGrassGeometry(std::size_t vertices_needed, std::size_t faces_needed, float height)
{
    if (!vertices.empty() || !faces.empty() || !bones.empty())
        throw std::logic_error("Grass geometry is already initialized");
    std::vector<SphereRenderModelVertex> new_vertices(vertices_needed);
    std::vector<SphereRenderModelFace> new_faces(faces_needed);
    std::vector<SphereRenderBone> new_bones(1u);
    SphereRenderModelGrassData grass_data;
    grass_data.influences.resize(vertices_needed);
    grass_data.bending.resize(vertices_needed);
    new_bones.front().name = "_u_grass";
    name = "AutoGrass";
    vertices = std::move(new_vertices);
    faces = std::move(new_faces);
    bones = std::move(new_bones);
    vegetation = std::move(grass_data);
    vegetation_kind = SphereRenderVegetationKind::Grass;
    radius = std::sqrt(141.12777709960938f);
    bones[0].has_geometry = true;
    bones[0].bounds().minimum = {-5.0f, -height, -5.0f};
    bones[0].bounds().maximum = {5.0f, 0.0f, 5.0f};
    bones[0].bounds().corners = SferaBoundsCornersRuntime::fromExtents(bones[0].bounds().minimum, bones[0].bounds().maximum);
    bones[0].bounds().center = {0.0f, -0.699999988079071f, 0.0f};
    bones[0].bounds().diagonal_length = 8.0f;
    minimum = bones[0].bounds().minimum;
    maximum = bones[0].bounds().maximum;
    collision_corners = bones[0].bounds().corners;
    lod_distance = 0.5f;
    lod_power = 0.0f;
}

void SphereRenderModel::finishGrassGeometry(std::span<const SphereRenderSubmesh> groups)
{
    std::vector<SphereRenderSubmesh> replacement(groups.begin(), groups.end());
    submeshes.swap(replacement);
    shadow_fade = 0.0f;
    shadow_scale = 1.0f;
    shadow_spread = 1.0f;
    materials.clear();
    casts_static_shadow = false;
    root_bone = 0;
    animation_lengths.clear();
    collision_kind = SphereRenderCollisionKind::None;
}

void SphereRenderModel::markGrassFace(std::vector<bool> &visited, std::vector<int> &components, const SphereRenderSubmesh &submesh, int component, std::size_t face)
{
    visited[face] = true;
    for (std::uint16_t vertex : faces[submesh.first_face + face].vertices)
        components[submesh.first_vertex + vertex] = component;
}

bool SphereRenderModel::isGrassComponentVertex(const std::vector<int> &components, const SphereRenderSubmesh &submesh, int component, std::uint16_t vertex)
{
    return components[submesh.first_vertex + vertex] == component;
}

void SphereRenderModel::searchGrassAnchor(const std::vector<int> &components, std::size_t index, double ground_y, std::optional<std::size_t> &nearest, float &nearest_squared, bool same_component)
{
    const auto &position = vertices[index].position;
    for (std::size_t candidate = 0u; candidate < vertices.size(); ++candidate)
    {
        if (same_component && components[candidate] != components[index])
            continue;
        if (!(vertices[candidate].position.y - ground_y > 0.0))
            continue;
        const SferaVec3F difference = position - vertices[candidate].position;
        const float squared = SferaNumeric::real32(difference.dot(difference));
        if (!nearest || nearest_squared > squared)
        {
            nearest = candidate;
            nearest_squared = squared;
        }
    }
}
