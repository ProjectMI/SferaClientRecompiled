#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "math/Vector.h"
#include "vegetation/VegetationGeometry.h"

class SphereRenderModel;

struct SphereRenderSubmesh;
struct SphereWorldGrassCell;
class SphereWorldGrassGeometry;
struct SphereWorldGrassInstance;

struct SphereWorldGrassCell
{
    std::uint32_t object_handle = 0;
};

struct SphereWorldGrassInstance
{
    std::shared_ptr<const SphereRenderModel> model;
    SferaVec3F position{};
    SferaVec3F rotation{};
    float vertical_scale = 1;
    SferaVec3F normal{};
};

class SphereWorldGrassGeometry
{
  public:
    static std::unique_ptr<SphereRenderModel> build(std::span<const SphereWorldGrassInstance> instances, float height);

  private:
    static auto appendGrassSubmesh(std::span<const SphereWorldGrassInstance> instances, std::size_t maximum_group_vertices, std::size_t &next_vertex, std::size_t vertex_count, std::size_t &next_face,
                                   std::size_t face_count, std::vector<std::vector<bool>> &consumed, const std::unique_ptr<SphereRenderModel> &result, const std::vector<std::uint16_t> &phases,
                                   std::vector<std::size_t> &instance_indices, std::vector<std::vector<std::size_t>> &vertex_indices, std::size_t instance_index, std::size_t submesh_index,
                                   SphereRenderSubmesh &group);
};

class SphereRenderModel;
class SphereWorldDynamicVegetation;
struct SphereWorldDynamicVegetationGust;
struct SphereWorldDynamicVegetationHarmonic;

struct SphereWorldDynamicVegetationGust
{
    bool active = false;
    float x = 0;
    float z = 0;
    float radius = 0;
    float radius_squared = 0;
    float speed = 0;
};

class SphereWorldDynamicVegetation
{
  public:
    explicit SphereWorldDynamicVegetation(std::span<SphereWorldGrassCell> cells);
    void initializeNoise();
    void initializeWind()
    {
        wind_ = {0.7070000171661377f, 0, 0.7070000171661377f};
        wind_strength_ = 0.4000000059604645f;
    }
    void setReference(const SferaVec3F &position)
    {
        reference_ = position;
    }
    void updateWind(const SferaVec3F &reference, float elapsed);
    void deformGrass(SphereRenderModel &model, const SferaVec3F &position);
    void update();
    void recalculate();
    std::span<const SphereRenderVegetationVertex> output() const
    {
        return output_;
    }
    const std::array<float, 1024> &noise() const
    {
        return noise_;
    }

  private:
    SferaVec3F bendingPosition(const SphereRenderModel &model, std::size_t vertex, float first, float second) const;
    void saveCache(SphereRenderModel &model);
    std::span<SphereWorldGrassCell> cells_;
    std::array<SphereWorldDynamicVegetationGust, 6> gusts_{};
    std::array<float, 1024> noise_{};
    std::vector<SphereRenderVegetationVertex> output_;
    SferaVec3F reference_{};
    SferaVec3F wind_{};
    float wind_strength_ = 0;
    float phase_ = 0;
    float phase_speed_ = 0;
    float bend_x_ = 0;
    float bend_z_ = 0;
    static std::int64_t last_update_;

  private:
    friend struct SphereWorldDynamicVegetationGust;
};

struct SphereWorldDynamicVegetationHarmonic
{
    double frequency;
    float phase;
    double amplitude;
};

class GrassMapMngr;
struct GrassMapMngrTile;

struct GrassMapMngrTile
{
    std::pair<int, int> key{};
    std::uint64_t timestamp = 0;
    std::array<std::uint8_t, 65536> bytes{};
};

class GrassMapMngr
{
  public:
    GrassMapMngr() = default;
    virtual void loadGrassMap(int column, int row, std::span<std::uint8_t> destination);
    std::uint32_t grassType(float x, float z)
    {
        return sample(x, z) & 15u;
    }
    std::uint32_t plantingType(float x, float z)
    {
        return (sample(x, z) >> 4u) & 3u;
    }
    GrassMapMngr *reset();

  private:
    std::uint8_t sample(float x, float z);
    std::unique_ptr<std::array<GrassMapMngrTile, 10>> tiles_;
    std::uint64_t timestamp_ = 0;

  private:
    friend struct GrassMapMngrTile;

  private:
    static bool matchesGrassTile(std::pair<int, int> key, const GrassMapMngrTile &tile)
    {
        return tile.timestamp != 0 && tile.key == key;
    }
    static bool isOlderGrassTile(const GrassMapMngrTile &left, const GrassMapMngrTile &right)
    {
        return left.timestamp < right.timestamp;
    }
};

class SphereWorldVegetationPatterns;
struct SphereWorldVegetationPatternsGrassPattern;

struct SphereWorldVegetationPatternsGrassPattern
{
    std::uint32_t id;
    std::array<std::string, 10> variants;
};

class SphereWorldVegetationPatterns
{
  public:
    void initializeGrass();
    void addGrass(std::uint32_t id, const std::array<std::string_view, 10> &variants);
    const SphereWorldVegetationPatternsGrassPattern &grass(std::uint32_t id) const;

  private:
    std::vector<SphereWorldVegetationPatternsGrassPattern> grass_patterns_;

  private:
    friend struct SphereWorldVegetationPatternsGrassPattern;

  private:
    static bool hasGrassPatternId(std::uint32_t id, const SphereWorldVegetationPatternsGrassPattern &pattern)
    {
        return pattern.id == id;
    }
};

class SphereWorldVegetation;

class SphereWorldVegetation
{
  private:
    static constexpr int grid_side = 13;
    std::vector<SphereWorldGrassCell> cells_;
    std::vector<SphereWorldGrassCell> previous_;
    std::vector<std::array<bool, 2>> occupancy_;
    int last_cell_x_ = 100000, last_cell_z_ = 100000;
    std::uint32_t update_phase_ = 0, previous_depth_ = 0;

  public:
    uint32_t map_update_phase{};
    GrassMapMngr map_cache{};
    std::uint64_t last_frame_ticks{};

    void initialize();
    void clear();
    void updateGrassView();
    void createCell(int x, int z, SphereWorldGrassCell &cell);
    void updateCells();
    void destroyOwnedModel(std::uint32_t &handle);
    static bool alternatePatterns();
    SphereWorldVegetationPatterns patterns;
    std::unique_ptr<SphereWorldDynamicVegetation> animation;

  private:
  private:
    static std::uint32_t vegetationChoice(std::uint32_t count);
    static float vegetationJitter(float center);
};

extern SphereWorldVegetation g_sfera_vegetation;

class SphereVegetationHelpers;

class SphereVegetationHelpers
{
  public:
    static float vegetationRandom(double scale, double offset = 0);
    static void vegetationError(const std::string &message);
};
