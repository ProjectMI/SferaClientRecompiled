#pragma once

#include <cstdint>
#include <cstdio>
#include <map>
#include <utility>
#include <vector>

#include "math/Vector.h"
#include "spatial/Bounds.h"

struct SphereRenderModelCollisionTriangle;
struct SphereWorldSpatialLeaf;
struct SphereWorldTerrainCandidate;
class SphereWorldWorldSpatialIndex;
struct TerrainCell;
class TerrainPatch;

struct SphereWorldSpatialLeaf
{
    std::vector<std::uint32_t> objects;
    bool contains_landscape = false;
    int terrain_key = -1;
    int quarter = 0;
    int group = 0;
    int cell = 0;
    float origin_x = 0.0f;
    float origin_z = 0.0f;
};

struct SphereWorldTerrainCandidate
{
    TerrainPatch *patch;
    const TerrainCell *cell;
    float origin_x;
    float origin_z;
};

class SphereWorldWorldSpatialIndex
{
  public:
    SphereWorldBounds query_bounds{};

    SphereWorldSpatialLeaf *leafAt(int cell_x, int cell_z);
    void insert(std::uint32_t handle, int cell_x, int cell_z);
    void remove(std::uint32_t handle, int cell_x, int cell_z);
    static bool typesInteract(std::uint32_t combined_type);
    void gatherCell(int cell_x, int cell_z, bool include_terrain);
    void forgetTerrain(const TerrainPatch &patch);
    void refreshTerrainBindings() noexcept;
    void gatherObject(std::uint32_t handle);
    void gatherObjects(const SferaVec3F &center, float radius);
    void gatherTerrain(const SferaVec3F &center, float radius);
    std::uint32_t gatherShadowTriangles(const SphereWorldBounds &bounds, const SferaVec3F &center, float radius, const SferaVec3F &origin, const SferaVec3F &direction);
    const std::vector<std::uint32_t> &objects() const
    {
        return objects_;
    }
    const std::vector<SphereWorldTerrainCandidate> &terrain() const
    {
        return terrain_;
    }
    const std::vector<SferaVec3F> &shadowVertices() const
    {
        return shadow_vertices_;
    }

  private:
    std::map<std::pair<int, int>, SphereWorldSpatialLeaf> cells_;
    std::vector<std::uint32_t> objects_;
    std::vector<SphereWorldTerrainCandidate> terrain_;
    std::vector<SferaVec3F> shadow_vertices_;
    void clearCandidates()
    {
        objects_.clear();
        terrain_.clear();
    }
    void finishCandidates();
    void addTerrain(int terrain_key, int cell, float origin_x, float origin_z);

  private:
    static int spatialCell(float coordinate, float radius);
    static void bindTerrainCell(SphereWorldSpatialLeaf &leaf, int cell_x, int cell_z);

  private:
    auto appendShadowTriangle(const SphereRenderModelCollisionTriangle &triangle);
    static bool isTerrainCandidateForPatch(const TerrainPatch &patch, const SphereWorldTerrainCandidate &candidate);
};

extern SphereWorldWorldSpatialIndex g_sfera_world_spatial;
