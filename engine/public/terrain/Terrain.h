#pragma once

#include <windows.h>
#include <array>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <span>
#include <vector>
#include <wrl/client.h>

#include "geometry/Geometry.h"
#include "math/Vector.h"

struct SphereRenderPositionColorUvVertex;
struct SphereRenderPositionNormalUvVertex;

struct SferaPlaneF;
struct SferaVec3F;
struct TerrainCell;
class TerrainPatch;
class TerrainQueries;
struct TerrainQueriesLocation;

struct TerrainQueriesLocation
{
    int patchX;
    int patchZ;
    int cellX;
    int cellZ;
    int mapIndex;
    bool valid() const
    {
        return patchX >= -40 && patchX < 40 && patchZ >= -40 && patchZ < 40;
    }
    int cellIndex() const;
};

class TerrainQueries
{
  public:
    static TerrainQueriesLocation locate(float worldX, float worldZ);
    static void sampleColor(float worldX, float worldZ, std::uint32_t &red, std::uint32_t &green, std::uint32_t &blue);
    static bool surface(float worldX, float worldZ, float &height, SferaPlaneF &plane);
    static std::uint8_t placementOrientation(float worldX, float worldZ, SferaVec3F &angles, float &height, SferaPlaneF &plane);
    static bool clearViewToFlare(const TerrainPatch &patch, const TerrainCell &cell);

  private:
    friend struct TerrainQueriesLocation;

  private:
    static SferaPlaneF terrainPlane(const SferaVec3F &normal, const SferaVec3F &point);

  private:
    static constexpr std::array<std::uint32_t, 32> buildFiveBitToEightBit();
};

class CD3D9Device;
template <class Element> class DynamicStreamMapping;
struct SferaViewProjectionScratchRuntime;
struct TerrainBounds;
class TerrainRenderer;
struct TerrainSurfaceGroup;
struct TerrainVisibleCell;
struct TerrainWaterSurface;

struct TerrainVisibleCell
{
    TerrainCell *cell;
    SferaBoundsCornersRuntime bounds;
};

struct TerrainWaterSurface
{
    int x;
    int z;
    float height;
    std::uint32_t lightMask;
    std::size_t material;
    SferaBoundsCornersRuntime bounds;
};

class TerrainRenderer
{
  public:
    SferaVec3F patch_origin{};
    std::vector<TerrainVisibleCell> visibleCells;
    std::vector<TerrainWaterSurface> waterSurfaces;
    static bool visibleBounds(const TerrainBounds &source, const SferaVec3F &anchor, SferaViewProjectionScratchRuntime &translated);
    bool gatherCells(TerrainPatch &patch);
    void findReflectiveWater(TerrainPatch &patch);
    void gatherReflectiveWater()
    {
        visitPatches(false);
    }
    void prepareAndDraw(TerrainPatch &patch);
    void drawCells(TerrainPatch &patch, std::size_t first, std::size_t last);
    void drawLandscape();
    void drawWater();

  private:
    void visitPatches(bool draw);

  private:
    static int terrainPatchCoordinate(double value);
    static void terrainSetState(D3DRENDERSTATETYPE state, DWORD value);
    static void terrainSubmitIndices(CD3D9Device &device, std::span<const std::uint16_t> indices, IDirect3DVertexBuffer9 *vertices, bool lit, std::size_t baseVertex, std::size_t vertexCount);

  private:
    static bool farFromCorner(const SferaVec3F &position, const SferaVec3F &corner);
    static void appendCellIndices(const TerrainPatch &patch, std::vector<std::uint16_t> &indices, std::uint16_t &batchVertices, const TerrainCell &cell, const TerrainSurfaceGroup &group);
    static void flushBaseCells(CD3D9Device &device, std::vector<std::uint16_t> &indices, DynamicStreamMapping<SphereRenderPositionColorUvVertex> &coloredVertices, std::size_t coloredBase,
                               std::size_t &batchStart, std::uint16_t &batchVertices, std::uint16_t material);
    static void flushLitCells(CD3D9Device &device, std::vector<std::uint16_t> &indices, DynamicStreamMapping<SphereRenderPositionNormalUvVertex> &litVertices, std::size_t litBase,
                              std::size_t &batchStart, std::uint16_t &batchVertices, std::uint32_t mask);
    static std::size_t waterBatchKey(const TerrainWaterSurface &surface);
    static void waterTextureStage(CD3D9Device &device, D3DTEXTURESTAGESTATETYPE state, DWORD value);
    static void waterDirectionalLight();
    static void waterAnimationTexture(int rotationStep, int animationId);
    static void drawWaterBatch(CD3D9Device &device, const std::vector<SphereRenderPositionNormalUvVertex> &vertices, const std::vector<std::uint16_t> &indices, float opacity);
};

extern TerrainRenderer g_sfera_terrain_renderer;

class TerrainTextureCache;
struct TerrainTextureEntry;
struct TerrainTextureImage;

struct TerrainTextureEntry
{
    const TerrainCell *owner = nullptr;
    int kind = 0;

    Microsoft::WRL::ComPtr<IDirect3DTexture9> resource;
    uint32_t use_count = 0;
};

class TerrainTextureCache
{
  public:
    static std::array<TerrainTextureEntry, 50> entries;
    static uint8_t quantization_x[3072];
    static uint8_t quantization_y[3072];
    static uint8_t blend_lut[16385];

    static void initialize();
    static void bindLayer(const TerrainCell &cell, int layer);
    static void release();
    static void blendLayer(const TerrainCell &cell, int layer, TerrainTextureImage &texture);

  private:
    static bool matchesTextureLayer(const TerrainCell *owner, int layer, const TerrainTextureEntry &candidate)
    {
        return candidate.owner == owner && candidate.kind == layer;
    }
    static bool lessUsedTexture(const TerrainTextureEntry &first, const TerrainTextureEntry &second)
    {
        return first.use_count < second.use_count;
    }
};
