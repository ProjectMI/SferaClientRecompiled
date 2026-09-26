#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>
#include <vector>

#include "math/Vector.h"

struct TerrainBounds;
struct TerrainCell;
struct TerrainSurfaceGroup;
struct TerrainTriangle;
struct TerrainVertex;
struct TerrainWater;

struct TerrainVertex
{
    SferaVec3F position;
    SferaVec3F normal;
    float textureU;
    float textureV;
    float detailU;
    float detailV;
};

struct TerrainTriangle
{
    std::uint16_t indices[3];
    std::uint16_t material;
    std::uint32_t attributes[2];
    SferaVec3F normal;
};

struct TerrainCell
{
    int x = 0;
    int z = 0;
    std::vector<TerrainTriangle> triangles;
    std::uint16_t baseMicrotexture = 0;
    std::vector<std::uint16_t> layers;
    std::vector<std::uint8_t> masks;
};

struct TerrainSurfaceGroup
{
    std::size_t vertexCount;
    std::size_t firstVertex;
    std::size_t firstIndex;
    std::size_t colored_vertex_offset;
    std::uint32_t light_mask;
    bool distant;
};

struct TerrainWater
{
    float height;
    std::size_t material;
};

struct TerrainBounds
{
    SferaVec3F corners[8];
    int scaledBounds[6];
    void lowerMinimum(float height);
};

struct TerrainTextureImage;

struct TerrainTextureImage
{
    static constexpr std::size_t width = 256;
    static constexpr std::size_t height = 256;
    std::array<std::uint8_t, 32> metadata{};
    std::array<std::uint16_t, width * height> pixels{};
    static std::unique_ptr<TerrainTextureImage> decode(std::span<const std::uint8_t> bytes);
};

class SferaBinaryReader;
struct TerrainGroupBuilder;
class TerrainPatch;
struct TerrainPatchGroup;

class TerrainPatch
{
  public:
    std::vector<TerrainVertex> vertices;
    std::array<TerrainCell, 144> cells{};
    std::array<TerrainSurfaceGroup, 144> surfaceGroups{};
    std::vector<TerrainVertex> groupedVertices;
    std::vector<std::uint16_t> groupedIndices;
    std::array<TerrainWater, 144> waters{};
    TerrainBounds bounds{};
    std::array<TerrainBounds, 4> quarterBounds{};
    std::array<TerrainBounds, 16> groupBounds{};
    std::array<TerrainBounds, 144> cellBounds{};
    std::uint32_t flags = 0;
    std::array<std::vector<std::size_t>, 4> cornerIndices;
    std::array<bool, 4> cornerSmoothed{};
    std::array<std::vector<std::vector<std::size_t>>, 4> edgeGroups;

    void partitionEdges();
    void rebuildSurfaceGroups();
    void updateBounds();
    bool validateEdge(const TerrainPatch &other, std::size_t side, std::size_t otherSide) const;
    bool smoothEdge(TerrainPatch &other, std::size_t side, std::size_t otherSide);
    void smoothCorner(TerrainPatch *diagonal, TerrainPatch *vertical, TerrainPatch *horizontal, std::size_t corner, std::size_t diagonalCorner, std::size_t verticalCorner,
                      std::size_t horizontalCorner);
    void readGeometry(std::span<const std::uint8_t> bytes, std::span<const std::uint8_t> masks, std::span<const std::uint8_t> waterData, std::span<const std::uint16_t, 65536> microtextureRemap,
                      std::uint16_t baseMicrotexture);

  private:
    static void terrainSmoothNormals(const std::vector<TerrainVertex *> &vertices);

  private:
    static auto nearEdgeBoundary(float value, float boundary)
    {
        return value > boundary - 0.01f && value < boundary + 0.01f;
    }
    static auto appendCornerVertices(std::vector<TerrainVertex *> &group, TerrainPatch *patch, std::size_t index);
    static auto readGeometryReal(SferaBinaryReader &input);
    static auto readGeometryVector(SferaBinaryReader &input);
    static auto remapMicrotexture(std::span<const std::uint16_t, 65536> microtextureRemap, std::uint16_t code);
    static float edgeGroupCoordinate(const TerrainPatchGroup &group);
};

struct TerrainPatchGroup
{
    float coordinate;
    std::vector<std::size_t> indices;
};

struct TerrainGroupBuilder
{
    std::vector<TerrainVertex> vertices;
    std::vector<std::uint16_t> indices;
    std::array<TerrainSurfaceGroup, 144> groups;
    void append(const TerrainPatch &patch, const TerrainCell &cell);
};

struct SferaVec3F;

// Resource residency and game map catalog lookup are implemented by core.
class SferaTerrainSource
{
  public:
    static TerrainPatch &patch(int mapIndex, bool refresh = true);
    static TerrainPatch &spatialPatch(int mapIndex);
    static const TerrainTextureImage &image(int mapIndex);
    static int texture(int mapIndex);
    static int microtexture(std::size_t material);
    static TerrainTextureImage *microtextureImage(std::size_t material);
    static void prepareColorMap();
    static std::uint32_t plantingType(float x, float z);
    static SferaVec3F anchor();
};
