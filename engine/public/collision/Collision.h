#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
#include <vector>

#include "geometry/Geometry.h"
#include "math/Vector.h"
#include "spatial/Bounds.h"

struct SferaMatrix4x4F;
class SphereCollisionGeometry;
struct SphereRenderModelCollisionTriangle;
struct SphereWorldTerrainCandidate;
struct TerrainTriangle;

class SphereCollisionGeometry
{
  public:
    static SferaMatrix4x4F rotationOnly(SferaMatrix4x4F value);
    static SphereRenderModelCollisionTriangle worldTriangle(const SphereRenderModelCollisionTriangle &triangle, const SferaMatrix4x4F &transform);
    static SphereRenderModelCollisionTriangle terrainTriangle(const SphereWorldTerrainCandidate &candidate, const TerrainTriangle &face);

  private:
    static void updateTriangleBounds(SphereRenderModelCollisionTriangle &triangle);
};

struct SphereRenderModelCollisionGroup;

enum class SphereRenderCollisionKind : std::uint32_t
{
    AxisAlignedBounds,
    OrientedBounds,
    Triangles,
    None
};

struct SphereRenderModelCollisionGroup
{
    std::size_t bone = 0u;
    std::size_t triangle_count = 0u;
    std::size_t first_triangle = 0u;
};

struct SphereRenderModelCollisionTriangle
{
    SferaVec3F minimum{};
    SferaVec3F maximum{};
    SferaVec3F vertices[3]{};
    SferaVec3F normal{};
    float plane_distance = 0.0f;
    std::uint32_t collision_flags = 0u;
};

class SphereRenderModel;
class SphereWorldContactQuery;
struct SphereWorldNearContact;

struct SphereWorldNearContact
{
    std::uint32_t handle = 0;
    SphereRenderCollisionKind subject_kind = SphereRenderCollisionKind::AxisAlignedBounds;
    SphereRenderCollisionKind geometry_kind = SphereRenderCollisionKind::AxisAlignedBounds;
    SphereWorldBounds bounds;
    SferaBoundsCornersRuntime corners{};
    std::vector<SphereRenderModelCollisionTriangle> triangles;
};

enum class SphereWorldContactQueryMode
{
    Movement,
    Normals,
    Support,
    Material,
    CollectIgnored
};

class SphereWorldContactQuery
{
  public:
    SphereWorldBounds query_bounds{};

    static bool projectionsOverlap(const SferaBoundsCornersRuntime &first, const SferaBoundsCornersRuntime &second, const SferaVec3F &axis);
    static bool boxesOverlap(const SferaBoundsCornersRuntime &first, const SferaBoundsCornersRuntime &second);
    static int intersectTriangle(const SferaVec3F &start, const SferaVec3F &end, const SphereRenderModelCollisionTriangle &triangle, SferaVec3F &intersection);
    static void sortTriangles(std::span<SphereRenderModelCollisionTriangle> triangles);
    static void updateBounds(std::uint32_t handle);
    static bool lineOfSight(std::uint32_t handle);
    void appendBoxNormals(const SferaBoundsCornersRuntime &corners);
    void gather(std::uint32_t handle);

    std::uint32_t test(std::uint32_t handle, SphereWorldContactQueryMode mode, bool reuse_cache, bool honor_ignored = true);
    std::span<const SferaVec3F> normals() const
    {
        return normals_;
    }
    void clearIgnoredObjects()
    {
        ignored_.clear();
    }
    void clear()
    {
        contacts_.clear();
        normals_.clear();
        ignored_.clear();
    }
    SferaVec3F support_normal{};
    std::uint32_t support_direction = 0;
    std::uint32_t surface_material = 0;
    float obstacle_height = 0.0f;
    std::uint32_t testMovement(std::uint32_t handle, bool reuse_cache)
    {
        ignored_.clear();
        return test(handle, SphereWorldContactQueryMode::Movement, reuse_cache);
    }
    void setIgnoredObjects(std::span<const std::uint32_t> handles)
    {
        ignored_.assign(handles.begin(), handles.end());
    }
    std::span<const SphereWorldNearContact> nearContacts() const
    {
        return contacts_;
    }

  private:
    std::vector<SphereWorldNearContact> contacts_;
    std::vector<SferaVec3F> normals_;
    std::vector<std::uint32_t> ignored_;
    void publishNormal(const SferaVec3F &normal)
    {
        normals_.push_back(normal);
    }
    void publishDirection(const SphereRenderModelCollisionTriangle &triangle);
    static bool trianglesHitBox(const SphereRenderModel &model, const SferaMatrix4x4F &transform, const SphereWorldBounds &query_bounds, const SphereWorldBounds &local_bounds,
                                const SferaMatrix4x4F *box_transform, const SferaMatrix4x4F *box_basis);

  private:
    static SphereWorldBounds currentSpatialBounds();
    static void publishWorldBounds(const SphereWorldBounds &value);
    static void publishSpatialBounds(const SphereWorldBounds &value);
    static std::array<SferaVec3F, 3> boxAxes(const SferaBoundsCornersRuntime &box, std::uint32_t diagnostic);
    static bool clippedTriangle(const SphereRenderModelCollisionTriangle &triangle, const SphereWorldBounds &bounds);

  private:
    static float triangleVerticalNormal(const SphereRenderModelCollisionTriangle &triangle);
};

extern SphereWorldContactQuery g_sfera_contacts;

struct Contour;
struct ContourVertex;

struct ContourVertex
{
    float x = 0.0f, z = 0.0f;
    int neighbour_contour = -1, neighbour_edge = -1;
};

struct Contour
{
    int type = 0;

    std::vector<ContourVertex> vertices;
    float min_x = 1000000.0f;
    float max_x = -1000000.0f;
    float min_z = 1000000.0f;
    float max_z = -1000000.0f;
    void updateBounds();
    bool contains(float point_x, float point_z) const;

  private:
    friend struct ContourVertex;
};
