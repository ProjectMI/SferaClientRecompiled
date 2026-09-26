#pragma once

#include <windows.h>
#include <array>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <memory>
#include <optional>
#include <span>
#include <vector>
#include <wrl/client.h>

#include "graphics/d3d9/Device.h"
#include "lifetime/Restore.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "render/VertexFormats.h"

struct ShadowPoint;
class ShadowRasterizer;
struct ShadowRasterizerEdge;
struct ShadowRasterizerRow;
struct ShadowRasterizerSpan;

struct ShadowPoint
{
    float x = 0.0f;
    float y = 0.0f;
};

struct ShadowRasterizerSpan
{
    int left = INT32_MAX;
    int right = INT32_MIN;
    std::uint32_t color = UINT32_MAX;
};

struct ShadowRasterizerRow
{
    ShadowRasterizerSpan active;
    ShadowRasterizerSpan displaced;
};

class ShadowRasterizer
{
  public:
    std::array<ShadowRasterizerRow, 256> rows{};
    bool pending = false;
    void polygon(std::uint32_t color, std::span<const ShadowPoint> points, int width, int height, const D3DLOCKED_RECT &surface);
    void flush(int height, const D3DLOCKED_RECT &surface)
    {
        flushSpans(height, surface, false);
        pending = false;
    }

  private:
    void flushSpans(int height, const D3DLOCKED_RECT &surface, bool displaced);

  private:
    friend struct ShadowRasterizerSpan;
    friend struct ShadowRasterizerRow;

  private:
    static bool lowerPoint(const ShadowPoint &a, const ShadowPoint &b)
    {
        return a.y < b.y;
    }
    static void advanceEdge(std::span<const ShadowPoint> points, int height, std::size_t &remaining, int row, ShadowRasterizerEdge &edge, bool backwards);
};

struct ShadowRasterizerEdge
{
    std::size_t vertex;
    int end;
    float slope = 0.0f;
    float x = 0.0f;
    void step();
};

struct ExtendedWorldObject;
class ShadowMap;
class ShadowMapPass;
class SphereRenderModel;
struct WorldObject;

class ShadowMapPass
{
  public:
    explicit ShadowMapPass(ShadowMap &owner);
    ~ShadowMapPass() noexcept;
    ShadowMapPass(const ShadowMapPass &) = delete;
    ShadowMapPass &operator=(const ShadowMapPass &) = delete;

  private:
    ShadowMap &owner_;
    SferaRestore<SferaVec3F> direction_;
    SferaRestore<float> fade_;
    SferaRestore<SferaMatrix4x4F> basis_;
};

class ShadowMap
{
  public:
    std::uint8_t quality = 0u;
    std::uint8_t level = 0u;
    SferaVec3F direction{};
    SferaVec3F origin{};
    float fade = 1.0f;
    bool valid = false;
    SferaMatrix4x4F projection{};
    SferaMatrix4x4F light_basis{};
    ShadowMap() = default;
    ShadowMap(const ShadowMap &) = delete;
    ShadowMap &operator=(const ShadowMap &) = delete;
    void createTextures();
    void setDirection(const SferaVec3F &value, float opacity);
    void selectObjectLight(const WorldObject &object);
    float projectionExtension(const WorldObject &object) const;
    bool prepareModel(WorldObject &object, const SferaVec3F *position, float opacity, std::uint8_t detail);
    bool prepareGeometry(WorldObject &object, const SferaVec3F *position, float opacity, std::uint8_t detail, float scale, float spot_scale);
    void projectModel(const SphereRenderModel &model, std::size_t submesh, const SferaMatrix4x4F *world = nullptr);
    template <class Vertex> void projectVertices(const Vertex *vertices, std::size_t vertex_count, const std::uint16_t *indices, std::size_t index_count);
    void draw(const SferaVec3F *vertices, std::size_t triangle_count);
    // A complete object's projection owns the temporary light state and texture mapping.

    static void initialize(std::uint32_t default_quality);
    static void shutdown();
    static void prepareObject(std::uint32_t handle, ExtendedWorldObject &object, double width, float spot_scale, float &extension);
    static void drawObject(ExtendedWorldObject &object, double width, float extension);

  private:
    std::array<Microsoft::WRL::ComPtr<IDirect3DTexture9>, 3> textures;
    std::optional<TextureMapping> mapping;
    int spot_texture = -1;
    std::uint32_t raster_color = 0u;
    std::uint32_t spot_color = UINT32_MAX;
    ShadowRasterizer rasterizer;
    std::vector<ShadowPoint> projected_points;
    std::array<std::uint16_t, 1002> face_indices{};
    std::array<SphereRenderPositionColorUvVertex, 501> spot_vertices{};
    D3DSURFACE_DESC surface{};

  private:
    friend class ShadowMapPass;

  private:
    static float projectedCoordinate(const SferaMatrix4x4F &transform, const SferaVec3F &point, std::size_t row, std::uint32_t extent);
};

extern std::unique_ptr<ShadowMap> g_sfera_shadows;
