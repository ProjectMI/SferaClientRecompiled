#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <filesystem>
#include <format>
#include <functional>
#include <io.h>
#include <limits>
#include <memory>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <utility>
#include <vector>

#include "binary/Binary.h"
#include "collision/Collision.h"
#include "diagnostics/ClientDiagnostics.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "resources/FileResources.h"
#include "resources/TerrainResources.h"
#include "resources/TextureRepository.h"
#include "spatial/SpatialIndex.h"
#include "terrain/Terrain.h"
#include "terrain/TerrainData.h"
#include "text/Text.h"
#include "vegetation/Vegetation.h"
#include "world/WorldObjects.h"

std::vector<std::uint8_t> SferaTerrainResourceAccess::terrainReadFile(const std::string &path, bool optional)
{
    if (optional)
    {
        const bool previous = g_sfera_files.setErrorReporting(false);
        std::int64_t size;
        try
        {
            size = g_sfera_files.fileSize(path);
        }
        catch (...)
        {
            g_sfera_files.setErrorReporting(previous);
            throw;
        }
        g_sfera_files.setErrorReporting(previous);
        if (size < 0)
            return {};
    }
    return g_sfera_files.readAll(path);
}

TerrainRegion &SferaTerrainResourceAccess::terrainRegionAt(int mapIndex)
{
    return *TerrainAssets::map[mapIndex].region;
}

TerrainPatch &SferaTerrainResourceAccess::terrainPatchAt(int mapIndex, bool refresh)
{
    auto &region = SferaTerrainResourceAccess::terrainRegionAt(mapIndex);
    const auto &record = TerrainAssets::map[mapIndex];
    if (refresh)
        region.touchPatch(record.tile_x, record.tile_y);
    else
        region.loadPatch(record.tile_x, record.tile_y);
    return *region.patch(record.tile_x, record.tile_y);
}

std::array<std::uint16_t, 65536> TerrainAssets::makeMicrotextureRemap()
{
    std::array<std::uint16_t, 65536> values{};
    values.fill(std::numeric_limits<std::uint16_t>::max());
    return values;
}

void TerrainAssets::evictUnused()
{
    for (auto &region : regions)
        for (int row = 0; row < region.rows; ++row)
            for (int column = 0; column < region.columns; ++column)
            {
                if (region.patch(row, column) && --region.slots[row * 10 + column].expiry == 0)
                    region.destroyPatch(row, column);
            }
}

void TerrainAssets::releaseAll()
{
    for (auto &region : regions)
        for (int row = 0; row < region.rows; ++row)
            for (int column = 0; column < region.columns; ++column)
                region.destroyPatch(row, column);
    microtextures.clear();
    microtexture_remap.fill(std::numeric_limits<std::uint16_t>::max());
    g_sfera_graphics_runtime.base_microtexture_id = UINT16_MAX;
}

void TerrainAssets::appendTerrainCatalog(std::deque<TerrainRegion> &regions, const std::string &directory)
{
    std::error_code error;
    const auto root = std::filesystem::path(directory);
    bool found = false;
    for (const auto &entry : std::filesystem::directory_iterator(root, error))
    {
        if (!entry.is_regular_file())
            continue;
        auto extension = entry.path().extension().string();
        SferaText::lowercaseLocale(extension);
        if (extension != ".siz")
            continue;
        found = true;
        if (regions.size() >= 300u)
            throw std::runtime_error("Too many landscape files");
        const auto dimensions = SferaTerrainResourceAccess::terrainReadFile(entry.path().filename().string());
        SferaBinaryReader reader(dimensions);
        TerrainRegion region;
        region.name = entry.path().stem().string();
        region.directory = directory;
        if (region.name.size() >= 30u || region.directory.size() >= 102u)
            throw std::runtime_error("Landscape path is too long");
        region.rows = reader.read<int>();
        region.columns = reader.read<int>();
        if (region.rows < 0 || region.rows > 10 || region.columns < 0 || region.columns > 10)
            throw std::runtime_error("Invalid landscape dimensions");
        regions.push_back(std::move(region));
    }
    if (error || !found)
        WorldDiagnostics::fail("*.siz files not found");
}

void TerrainAssets::appendTerrainMicrotextures(const std::string &pattern, std::vector<TerrainAssetsMicrotexture> &microtextures, std::array<std::uint16_t, 65536> &remap, std::uint16_t &baseIndex)
{
    _finddata64i32_t found{};
    const auto search = _findfirst64i32(pattern.c_str(), &found);
    if (search == -1)
        return;
    try
    {
        do
        {
            if ((found.attrib & _A_SUBDIR) != 0u)
                continue;
            const auto index = microtextures.size();
            if (index >= 100)
                throw std::length_error("Landscape microtexture limit exceeded");
            auto image = TerrainTextureImage::decode(SferaTerrainResourceAccess::terrainReadFile(found.name));
            const auto first = SferaText::asciiFold(found.name[0]);
            const auto second = SferaText::asciiFold(found.name[1]);
            const std::uint16_t key = first | (second << 8);
            const bool base = found.name[2] == '_';
            found.name[base ? 3 : 2] = '\0';
            const auto texture = g_sfera_textures.find(found.name);
            microtextures.push_back({key, texture, std::move(image)});
            remap[key] = SferaNumeric::lowHalf(SferaNumeric::lowWord(index));
            if (base)
                baseIndex = SferaNumeric::lowHalf(SferaNumeric::lowWord(index));
        } while (_findnext64i32(search, &found) == 0);
    }
    catch (...)
    {
        _findclose(search);
        throw;
    }
    _findclose(search);
}

bool TerrainAssets::terrainNamesEqual(std::string_view first, std::string_view second)
{
    return SferaText::compareInsensitive(first, second) == 0;
}

TerrainRegion *TerrainAssets::terrainFindRegion(std::deque<TerrainRegion> &regions, std::string_view name)
{
    for (auto &region : regions)
        if (TerrainAssets::terrainNamesEqual(region.name, name))
            return &region;
    return nullptr;
}

void TerrainAssets::loadMap()
{
    std::deque<TerrainRegion> loadedRegions;
    std::vector<TerrainAssetsMicrotexture> loadedMicrotextures;
    auto remap = std::make_unique<decltype(microtexture_remap)>();
    remap->fill(UINT16_MAX);
    std::uint16_t baseIndex = UINT16_MAX;
    std::vector<std::string> directories{"landscape\\"};
    if (TerrainAssets::high_resolution_assets)
        directories.emplace_back("landscape_hr\\");
    if (TerrainAssets::alternate_ph_assets)
        directories.emplace_back("landscape_ph\\");
    if (TerrainAssets::alternate_rd_assets)
        directories.emplace_back("landscape_rd\\");
    for (const auto &directory : directories)
        TerrainAssets::appendTerrainMicrotextures((directory + "*.mtx"), loadedMicrotextures, *remap, baseIndex);
    if (baseIndex == UINT16_MAX)
    {
        WorldDiagnostics::fail("Base microtexture not found: landscape\\??_.mtx");
    }
    for (const auto &directory : directories)
        TerrainAssets::appendTerrainCatalog(loadedRegions, directory);
    const auto data = SferaTerrainResourceAccess::terrainReadFile("landscape\\map.bin");
    constexpr std::size_t encodedCellSize = 22;
    if (data.size() != map.size() * encodedCellSize)
        throw std::runtime_error("Invalid landscape map file size");
    auto replacement = std::make_unique<decltype(map)>();
    SferaBinaryReader reader(data);
    for (auto &cell : *replacement)
    {
        const auto encodedName = reader.take(20);
        const auto terminator = std::find(encodedName.begin(), encodedName.end(), 0);
        if (terminator == encodedName.end())
            throw std::runtime_error("Unterminated landscape map name");
        const std::string name(encodedName.begin(), terminator);
        cell.tile_x = reader.read<std::uint8_t>();
        cell.tile_y = reader.read<std::uint8_t>();
        cell.region = TerrainAssets::terrainFindRegion(loadedRegions, name);
        if (cell.region == nullptr)
        {
            cell.region = TerrainAssets::terrainFindRegion(loadedRegions, "FILL_EMPT");
            cell.tile_x = cell.tile_y = 0;
        }
        if (cell.region == nullptr)
            WorldDiagnostics::fail("Patch present in map, but not found in landscape. Name: FILL_EMPT");
        if (cell.tile_x >= cell.region->rows || cell.tile_y >= cell.region->columns)
            throw std::runtime_error("Landscape map references an invalid patch");
    }
    releaseAll();
    regions.swap(loadedRegions);
    microtextures.swap(loadedMicrotextures);
    microtexture_remap = *remap;
    g_sfera_graphics_runtime.base_microtexture_id = baseIndex;
    map = *replacement;
    g_sfera_world_spatial.refreshTerrainBindings();
    g_sfera_contacts.clear();
    g_sfera_terrain_renderer.visibleCells.clear();
    g_sfera_terrain_renderer.waterSurfaces.clear();
}

uint32_t TerrainAssets::color_map_ready{};
bool TerrainAssets::high_resolution_assets{};
bool TerrainAssets::alternate_ph_assets{};
bool TerrainAssets::alternate_rd_assets{};

auto TerrainPatchFile::readBounds(SferaBinaryReader &reader, TerrainBounds &output)
{
    for (auto &corner : output.corners)
    {
        corner.x = reader.read<float>();
        corner.y = reader.read<float>();
        corner.z = reader.read<float>();
    }
    for (auto &value : output.scaledBounds)
        value = reader.read<int>();
}

TerrainPatchFile TerrainPatchFile::decode(std::span<const std::uint8_t> bytes)
{
    if (bytes.size() != encodedSize)
        throw std::runtime_error("Invalid landscape header size");
    SferaBinaryReader reader(bytes);

    TerrainPatchFile result{};
    result.format = reader.read<std::uint32_t>();
    result.vertexCount = reader.read<std::uint32_t>();
    reader.take(4); // Stored runtime references belong to the file format, not to the in-memory objects.
    for (auto &cell : result.cells)
    {
        cell.x = reader.read<int>();
        cell.z = reader.read<int>();
        cell.triangleCount = reader.read<int>();
        reader.take(4);
        cell.baseMicrotexture = reader.read<std::uint16_t>();
        reader.take(2);
        cell.layerCount = reader.read<int>();
        for (auto &layer : cell.layers)
            layer = reader.read<std::uint16_t>();
        reader.take(4);
    }
    reader.take(5 * 4);
    readBounds(reader, result.bounds);
    for (auto &item : result.quarterBounds)
        readBounds(reader, item);
    for (auto &item : result.groupBounds)
        readBounds(reader, item);
    for (auto &item : result.cellBounds)
        readBounds(reader, item);
    result.flags = reader.read<std::uint32_t>();
    reader.take(2 * 4 * 4);
    const auto smoothed = reader.take(4);
    std::copy(smoothed.begin(), smoothed.end(), result.cornerSmoothed);
    reader.take(2 * 4 * 4);
    return result;
}

auto TerrainPatch::readGeometryReal(SferaBinaryReader &input)
{
    const auto value = input.read<float>();
    if (!std::isfinite(value))
        throw std::runtime_error("Non-finite landscape geometry");
    return value;
}

auto TerrainPatch::readGeometryVector(SferaBinaryReader &input)
{
    return SferaVec3F{readGeometryReal(input), readGeometryReal(input), readGeometryReal(input)};
}

auto TerrainPatch::remapMicrotexture(std::span<const std::uint16_t, 65536> microtextureRemap, std::uint16_t code)
{
    if (microtextureRemap[code] == std::numeric_limits<std::uint16_t>::max())
        throw std::runtime_error("Landscape references an unknown microtexture");
    return microtextureRemap[code];
}

void TerrainPatch::readGeometry(std::span<const std::uint8_t> bytes, std::span<const std::uint8_t> masks, std::span<const std::uint8_t> waterData,
                                std::span<const std::uint16_t, 65536> microtextureRemap, std::uint16_t baseMicrotexture)
{
    SferaBinaryReader reader(bytes);
    const auto header = TerrainPatchFile::decode(reader.take(TerrainPatchFile::encodedSize));
    if (header.vertexCount > 65536u)
        throw std::runtime_error("Landscape has too many vertices");
    std::size_t maskOffset = 0;
    std::bitset<144> coordinates;
    for (const auto &cell : header.cells)
    {
        if (cell.x < 0 || cell.x >= 12 || cell.z < 0 || cell.z >= 12 || cell.triangleCount < 0 || cell.triangleCount > 1000000 || cell.layerCount < 0 || cell.layerCount > 10)
            throw std::runtime_error("Invalid landscape cell header");
        const auto coordinate = cell.x + cell.z * 12;
        if (coordinates.test(coordinate))
            throw std::runtime_error("Duplicate landscape cell coordinates");
        coordinates.set(coordinate);
        const auto maskBytes = cell.layerCount * 576;
        if (maskOffset >= masks.size() || masks[maskOffset] != cell.layerCount || maskBytes > masks.size() - maskOffset - 1)
            throw std::runtime_error("Number of layer masks is not the same in lnd and msk");
        maskOffset += maskBytes + 1;
    }
    if (!waterData.empty() && waterData.size() != 144 * 8)
        throw std::runtime_error("Invalid landscape water data");

    TerrainPatch loaded;
    SferaBinaryReader vertexReader(reader.take(header.vertexCount * 40u));
    loaded.vertices.resize(header.vertexCount);

    for (auto &vertex : loaded.vertices)
    {
        vertex.position = readGeometryVector(vertexReader);
        vertex.normal = readGeometryVector(vertexReader);
        vertex.textureU = readGeometryReal(vertexReader);
        vertex.textureV = readGeometryReal(vertexReader);
        vertex.detailU = readGeometryReal(vertexReader);
        vertex.detailV = readGeometryReal(vertexReader);
    }
    loaded.waters.fill({1000.0f, 0u});
    if (!waterData.empty())
    {
        SferaBinaryReader waterReader(waterData);
        for (auto &water : loaded.waters)
        {
            water = {waterReader.read<float>(), waterReader.read<std::uint32_t>()};
            if (water.material >= g_sfera_graphics_runtime.water_materials.size() || (water.material != 0 && !std::isfinite(water.height)))
                throw std::runtime_error("Invalid landscape water material or height");
        }
    }
    loaded.bounds = header.bounds;
    std::copy_n(header.quarterBounds, 4, loaded.quarterBounds.begin());
    std::copy_n(header.groupBounds, 16, loaded.groupBounds.begin());
    std::copy_n(header.cellBounds, 144, loaded.cellBounds.begin());
    loaded.flags = header.flags;
    std::copy_n(header.cornerSmoothed, 4, loaded.cornerSmoothed.begin());

    maskOffset = 0;
    for (std::size_t i = 0; i < loaded.cells.size(); ++i)
    {
        const auto &source = header.cells[i];
        auto &cell = loaded.cells[i];
        cell.x = source.x;
        cell.z = source.z;
        SferaBinaryReader triangleReader(reader.take(source.triangleCount * 28u));
        cell.triangles.resize(source.triangleCount);
        for (auto &triangle : cell.triangles)
        {
            for (auto &index : triangle.indices)
            {
                index = triangleReader.read<std::uint16_t>();
                if (index >= loaded.vertices.size())
                    throw std::runtime_error("Landscape triangle vertex is outside the vertex array");
            }
            triangle.material = triangleReader.read<std::uint16_t>();
            for (auto &attribute : triangle.attributes)
                attribute = triangleReader.read<std::uint32_t>();
            triangle.normal = readGeometryVector(triangleReader);
        }
        const auto &water = loaded.waters[cell.x + 12 * cell.z];
        if (water.material)
            loaded.cellBounds[i].lowerMinimum(water.height);
        cell.baseMicrotexture = source.baseMicrotexture ? remapMicrotexture(microtextureRemap, source.baseMicrotexture) : baseMicrotexture;
        cell.layers.reserve(source.layerCount);
        for (int layer = 0; layer < source.layerCount; ++layer)
            cell.layers.push_back(remapMicrotexture(microtextureRemap, source.layers[layer]));
        const auto maskBytes = cell.layers.size() * 576;
        const auto cellMasks = masks.subspan(maskOffset + 1, maskBytes);
        cell.masks.assign(cellMasks.begin(), cellMasks.end());
        maskOffset += maskBytes + 1;
    }
    loaded.updateBounds();
    loaded.partitionEdges();
    *this = std::move(loaded);
}

std::unique_ptr<TerrainTextureImage> TerrainTextureImage::decode(std::span<const std::uint8_t> bytes)
{
    SferaBinaryReader reader(bytes);
    const auto metadata = reader.take(32u);
    SferaBinaryReader pixels(reader.take(width * height * 2u));
    auto image = std::make_unique<TerrainTextureImage>();
    std::copy(metadata.begin(), metadata.end(), image->metadata.begin());
    for (auto &pixel : image->pixels)
        pixel = pixels.read<std::uint16_t>();
    return image;
}

TerrainPatch *TerrainRegion::patch(int row, int column) const
{
    if (row < 0 || row >= rows || column < 0 || column >= columns || row >= 10 || column >= 10)
        return nullptr;
    return slots[row * 10 + column].patch.get();
}

void TerrainRegion::touchPatch(int row, int column)
{
    if (!patch(row, column))
        loadPatch(row, column);
    slots[row * 10 + column].expiry = 1000;
}

bool TerrainRegion::isTerrainCell(const TerrainCell *cell, const TerrainCell &item)
{
    return &item == cell;
}

auto TerrainRegion::belongsToPatch(const TerrainRegionPatchSlot &slot, const TerrainCell *cell)
{
    return std::any_of(slot.patch->cells.begin(), slot.patch->cells.end(), std::bind_front(isTerrainCell, cell));
}

bool TerrainRegion::isVisibleCellInPatch(const TerrainRegionPatchSlot &slot, const TerrainVisibleCell &entry)
{
    return belongsToPatch(slot, entry.cell);
}

void TerrainRegion::destroyPatch(int row, int column)
{
    if (row < 0 || row >= 10 || column < 0 || column >= 10)
        throw std::out_of_range("Landscape patch slot");
    auto &slot = slots[row * 10 + column];
    if (!slot.patch)
        return;

    g_sfera_world_spatial.forgetTerrain(*slot.patch);
    std::erase_if(g_sfera_terrain_renderer.visibleCells, std::bind_front(isVisibleCellInPatch, std::cref(slot)));
    for (auto &entry : TerrainTextureCache::entries)
        if (belongsToPatch(slot, entry.owner))
            entry.owner = nullptr;
    slot.patch.reset();
    slot.texture.reset();
}

auto TerrainRegion::smoothStagedEdge(std::array<std::unique_ptr<TerrainPatch>, 9> &staged, TerrainPatch &patch, std::size_t neighbor, std::size_t side, std::size_t otherSide)
{
    return !staged[neighbor] || patch.smoothEdge(*staged[neighbor], side, otherSide);
}

void TerrainRegion::smoothTerrainNeighborhood(TerrainPatch &current, const std::array<TerrainPatch *, 8> &neighbors, const std::string &name)
{
    std::array<TerrainPatch *, 9> destinations;
    std::copy(neighbors.begin(), neighbors.end(), destinations.begin());
    destinations.back() = &current;
    std::array<std::unique_ptr<TerrainPatch>, 9> staged;
    for (std::size_t index = 0; index < staged.size(); ++index)
    {
        if (destinations[index])
            staged[index] = std::make_unique<TerrainPatch>(*destinations[index]);
    }
    auto &patch = *staged.back();

    bool valid = smoothStagedEdge(staged, patch, 5, 1, 0);
    valid = smoothStagedEdge(staged, patch, 4, 0, 1) && valid;
    valid = smoothStagedEdge(staged, patch, 7, 3, 2) && valid;
    valid = smoothStagedEdge(staged, patch, 6, 2, 3) && valid;
    if (!valid)
        WorldDiagnostics::fail(("Smooth error in " + name + "! Look at lndbug.tga"));
    constexpr std::array<std::array<std::size_t, 6>, 4> corners{{{3, 4, 6, 3, 2, 1}, {2, 4, 7, 2, 3, 0}, {0, 5, 6, 1, 0, 3}, {1, 5, 7, 0, 1, 2}}};
    for (std::size_t index = 0; index < corners.size(); ++index)
    {
        if (patch.cornerSmoothed[index])
            continue;
        const auto &corner = corners[index];
        patch.smoothCorner(staged[corner[0]].get(), staged[corner[1]].get(), staged[corner[2]].get(), index, corner[3], corner[4], corner[5]);
    }
    patch.rebuildSurfaceGroups();
    for (std::size_t index = 0; index < neighbors.size(); ++index)
        if (staged[index])
            staged[index]->rebuildSurfaceGroups();
    for (std::size_t index = 0; index < staged.size(); ++index)
    {
        if (!staged[index])
            continue;
        auto &target = *destinations[index];
        auto &source = *staged[index];
        for (std::size_t vertex = 0; vertex < target.vertices.size(); ++vertex)
            target.vertices[vertex].normal = source.vertices[vertex].normal;
        target.cornerSmoothed = source.cornerSmoothed;
        target.surfaceGroups = source.surfaceGroups;
        target.groupedVertices.swap(source.groupedVertices);
        target.groupedIndices.swap(source.groupedIndices);
    }
}

void TerrainRegion::loadPatch(int row, int column)
{
    if (row < 0 || row >= rows || row >= 10 || column < 0 || column >= columns || column >= 10)
        throw std::out_of_range("Landscape patch coordinates");
    auto &slot = slots[row * 10 + column];
    if (slot.patch)
        return;
    const std::string stem = std::format("{}_{}{}", name, row, column);
    const std::string prefix = directory + stem;
    const auto masks = SferaTerrainResourceAccess::terrainReadFile(prefix + ".msk");
    const auto water = SferaTerrainResourceAccess::terrainReadFile(prefix + ".wtr", true);
    auto texture = TerrainTextureImage::decode(SferaTerrainResourceAccess::terrainReadFile(prefix + ".dds"));
    auto owned = std::make_unique<TerrainPatch>();
    owned->readGeometry(g_sfera_files.readAll((stem + ".lnd")), masks, water, TerrainAssets::microtexture_remap, g_sfera_graphics_runtime.base_microtexture_id);
    const auto textureId = g_sfera_textures.find(stem);
    const std::array<TerrainPatch *, 8> neighbors{patch(row - 1, column - 1), patch(row + 1, column - 1), patch(row + 1, column + 1), patch(row - 1, column + 1),
                                                  patch(row, column + 1),     patch(row, column - 1),     patch(row - 1, column),     patch(row + 1, column)};
    TerrainRegion::smoothTerrainNeighborhood(*owned, neighbors, name);
    slot.patch = std::move(owned);
    slot.texture = std::move(texture);
    slot.texture_id = textureId;
    slot.expiry = 1000;
}

TerrainPatch &SferaTerrainSource::patch(int mapIndex, bool refresh)
{
    return SferaTerrainResourceAccess::terrainPatchAt(mapIndex, refresh);
}

TerrainPatch &SferaTerrainSource::spatialPatch(int mapIndex)
{
    auto &region = SferaTerrainResourceAccess::terrainRegionAt(mapIndex);
    const auto &record = TerrainAssets::map[mapIndex];
    if (!region.patch(record.tile_x, record.tile_y))
    {
        region.loadPatch(record.tile_x, record.tile_y);
    }
    region.slots[record.tile_x * 10 + record.tile_y].expiry = 1000;
    return *region.patch(record.tile_x, record.tile_y);
}

const TerrainTextureImage &SferaTerrainSource::image(int mapIndex)
{
    auto &region = SferaTerrainResourceAccess::terrainRegionAt(mapIndex);
    const auto &record = TerrainAssets::map[mapIndex];
    return *region.slots[record.tile_x * 10 + record.tile_y].texture;
}

int SferaTerrainSource::texture(int mapIndex)
{
    const auto &record = TerrainAssets::map[mapIndex];
    return SferaTerrainResourceAccess::terrainRegionAt(mapIndex).slots[record.tile_x * 10 + record.tile_y].texture_id;
}

int SferaTerrainSource::microtexture(std::size_t material)
{
    return TerrainAssets::microtextures.at(material).texture_id;
}

TerrainTextureImage *SferaTerrainSource::microtextureImage(std::size_t material)
{
    return TerrainAssets::microtextures.at(material).image.get();
}

SferaVec3F SferaTerrainSource::anchor()
{
    return SferaWorldView::terrainAnchor();
}

void SferaTerrainSource::prepareColorMap()
{
    if ((TerrainAssets::color_map_ready & 1u) == 0u)
    {
        TerrainAssets::color_map_ready |= 1u;
        TerrainAssets::color_map.reset();
    }
}

std::uint32_t SferaTerrainSource::plantingType(float x, float z)
{
    return TerrainAssets::color_map.plantingType(x, z);
}
