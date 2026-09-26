#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
#include <utility>
#include <vector>

#include "collision/Collision.h"
#include "math/Vector.h"

class Contours;
class SferaBinaryReader;

class Contours
{
  public:
    std::vector<Contour> records;
    explicit Contours(int first_server_type = 2000, int last_server_type = 2999);
    void clear();
    void load();
    void loadBytes(std::span<const std::uint8_t> bytes);
    std::span<const Contour> typeRange(int first, int last) const;
    bool sameEdge(std::size_t first_contour, std::size_t first_edge, std::size_t second_contour, std::size_t second_edge) const;
    void setServerMap(std::span<const int> types, std::span<const int> servers);
    int serverByType(int type) const;
    void buildServerMask(std::uint8_t server);
    int typeAt(float x, float z, int first_type, int last_type) const;
    int serverAt(float x, float z) const;
    bool nearServer(float x, float z, int server);
    void connectEdges();
    std::vector<std::array<float, 4>> serverBoundaries();
    void rebuildServerWall();
    void rasterizeServers();

  private:
    int first_server_type;
    int last_server_type;
    std::vector<std::pair<int, int>> server_map;
    std::array<std::uint8_t, 160 * 160> server_grid{};
    std::array<std::uint8_t, 160 * 160> server_mask{};
    bool grid_initialized = false;
    int mask_server = -1;
    bool isServerContour(const Contour &contour) const
    {
        return contour.type >= first_server_type && contour.type <= last_server_type;
    }
    void invalidateGrid();

  private:
    template <class T> static auto readVertexColumn(SferaBinaryReader &reader, Contour &contour, T ContourVertex::*member);
    static auto sameVertex(const Contour &first, const Contour &second, std::size_t a, std::size_t b)
    {
        return first.vertices[a].x == second.vertices[b].x && first.vertices[a].z == second.vertices[b].z;
    }
    static bool reachesContourType(int first, const Contour &contour)
    {
        return contour.type >= first;
    }
    static bool exceedsContourType(int last, const Contour &contour)
    {
        return contour.type > last;
    }
};

struct SferaFrustumF;
struct SferaPlaneF;
class SferaServerWall;
struct SferaServerWallEffectRecord;
struct SferaServerWallLine;
struct SferaServerWallTextureFrame;
struct WorldObject;

struct SferaServerWallEffectRecord
{
    SferaVec3F positions[4]{};
    float duration = 0.0f;
    float remaining = -1.0f;
    float animation_phase = 0.0f;
};

struct SferaServerWallTextureFrame
{
    float uv[5][2]{};
};

class SferaServerWall
{
  public:
    std::vector<std::array<SferaVec3F, 2>> segments;
    std::vector<SferaVec3F> normals;
    std::array<SferaServerWallEffectRecord, 100> effects{};
    std::array<SferaServerWallTextureFrame, 16> texture_frames{};
    int texture_id = -1;
    void clear();
    void setSegments(std::span<const std::array<float, 4>> coordinates);
    void prepareGeometry();
    void generateEffects();
    void generateEffects(const WorldObject &observer, float field_of_view, const SferaFrustumF &frustum);
    void updateEffectRendering();
    static bool intersectPlane(const SferaPlaneF &plane, const SferaVec3F &start, const SferaVec3F &end, SferaVec3F &output);
    static std::uint32_t classifyVisibility(const SferaFrustumF &frustum, std::span<const SferaVec3F> points);
    static int intersectXZ(const SferaVec3F &first, const SferaVec3F &second, const SferaVec3F &other_first, const SferaVec3F &other_second, SferaVec3F &output);

  private:
    static auto distanceToObserver(const WorldObject &observer, const SferaVec3F &point);
    static bool isWallEffectAvailable(const SferaServerWallEffectRecord &effect);
};

struct SferaServerWallLine
{
    float x, z, constant;
    static SferaServerWallLine through(const SferaVec3F &first, const SferaVec3F &second);
    float evaluate(const SferaVec3F &point) const;
};

extern SferaServerWall g_sfera_server_wall;
