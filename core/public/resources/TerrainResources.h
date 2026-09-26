#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include "terrain/TerrainData.h"

struct TerrainCell;
class TerrainRegion;
struct TerrainRegionPatchSlot;
struct TerrainVisibleCell;

struct TerrainRegionPatchSlot
{
    std::unique_ptr<TerrainPatch> patch;
    std::unique_ptr<TerrainTextureImage> texture;
    int texture_id = 0;
    std::uint32_t expiry = 0;
};

class TerrainRegion
{
  public:
    std::string name;
    std::string directory;
    int rows = 0;
    int columns = 0;
    std::array<TerrainRegionPatchSlot, 100> slots;

    TerrainPatch *patch(int row, int column) const;
    void loadPatch(int row, int column);
    void touchPatch(int row, int column);
    void destroyPatch(int row, int column);

  private:
    friend struct TerrainRegionPatchSlot;

  private:
    static void smoothTerrainNeighborhood(TerrainPatch &current, const std::array<TerrainPatch *, 8> &neighbors, const std::string &name);

  private:
    static auto belongsToPatch(const TerrainRegionPatchSlot &slot, const TerrainCell *cell);
    static auto smoothStagedEdge(std::array<std::unique_ptr<TerrainPatch>, 9> &staged, TerrainPatch &patch, std::size_t neighbor, std::size_t side, std::size_t otherSide);
    static bool isTerrainCell(const TerrainCell *cell, const TerrainCell &item);
    static bool isVisibleCellInPatch(const TerrainRegionPatchSlot &slot, const TerrainVisibleCell &entry);
};

class GrassMapMngr;
class TerrainAssets;
struct TerrainAssetsMapCell;
struct TerrainAssetsMicrotexture;

struct TerrainAssetsMapCell
{
    TerrainRegion *region;
    std::uint8_t tile_x, tile_y;
};

struct TerrainAssetsMicrotexture
{
    std::uint16_t lookup_key;
    int texture_id;
    std::unique_ptr<TerrainTextureImage> image;
};

class TerrainAssets
{
  public:
    static GrassMapMngr color_map;
    static uint32_t color_map_ready;
    static bool high_resolution_assets;
    static bool alternate_ph_assets;
    static bool alternate_rd_assets;

    static std::vector<TerrainAssetsMicrotexture> microtextures;
    static std::array<TerrainAssetsMapCell, 6400> map;
    static std::deque<TerrainRegion> regions;
    static std::array<std::uint16_t, 65536> microtexture_remap;
    static void loadMap();
    static void evictUnused();
    static void releaseAll();

  private:
    friend struct TerrainAssetsMapCell;
    friend struct TerrainAssetsMicrotexture;

  private:
    static void appendTerrainCatalog(std::deque<TerrainRegion> &regions, const std::string &directory);
    static void appendTerrainMicrotextures(const std::string &pattern, std::vector<TerrainAssetsMicrotexture> &microtextures, std::array<std::uint16_t, 65536> &remap, std::uint16_t &baseIndex);
    static bool terrainNamesEqual(std::string_view first, std::string_view second);
    static TerrainRegion *terrainFindRegion(std::deque<TerrainRegion> &regions, std::string_view name);

  private:
    static std::array<std::uint16_t, 65536> makeMicrotextureRemap();
};

class SferaTerrainResourceAccess;
class TerrainPatch;

class SferaTerrainResourceAccess
{
  public:
    static std::vector<std::uint8_t> terrainReadFile(const std::string &path, bool optional = false);
    static TerrainRegion &terrainRegionAt(int mapIndex);
    static TerrainPatch &terrainPatchAt(int mapIndex, bool refresh = true);
};

class SferaBinaryReader;
struct TerrainPatchFile;
struct TerrainPatchFileCell;

struct TerrainPatchFileCell
{
    int x;
    int z;
    int triangleCount;
    std::uint16_t baseMicrotexture;
    int layerCount;
    std::uint16_t layers[10];
};

struct TerrainPatchFile
{
    static constexpr std::size_t encodedBoundsSize = 8 * 3 * 4 + 6 * 4;
    static constexpr std::size_t encodedSize = 12 + 144 * 48 + 5 * 4 + (1 + 4 + 16 + 144) * encodedBoundsSize + 4 + 4 * 4 * 4 + 4;
    std::uint32_t format;
    std::uint32_t vertexCount;
    TerrainPatchFileCell cells[144];
    TerrainBounds bounds;
    TerrainBounds quarterBounds[4];
    TerrainBounds groupBounds[16];
    TerrainBounds cellBounds[144];
    std::uint32_t flags;
    std::uint8_t cornerSmoothed[4];
    static TerrainPatchFile decode(std::span<const std::uint8_t> bytes);

  private:
    static auto readBounds(SferaBinaryReader &reader, TerrainBounds &output);
};
