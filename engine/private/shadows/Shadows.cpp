#include <windows.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <span>
#include <stdexcept>
#include <utility>

#include "binary/Binary.h"
#include "collision/Collision.h"
#include "effects/EffectRendering.h"
#include "graphics/d3d9/Device.h"
#include "lighting/LightRuntime.h"
#include "math/Color.h"
#include "math/MathFunctions.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "render/Model.h"
#include "render/SceneRenderer.h"
#include "render/TextureAccess.h"
#include "render/VertexFormats.h"
#include "scene/SceneAccess.h"
#include "scene/SceneObject.h"
#include "shadows/Shadows.h"
#include "spatial/Bounds.h"
#include "spatial/SpatialIndex.h"

void ShadowMap::createTextures()
{
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    std::array<Microsoft::WRL::ComPtr<IDirect3DTexture9>, 3> replacement;
    for (std::size_t index = 0; index < replacement.size(); ++index)
    {
        const auto extent = 256u >> index;
        device.checkResult(device.native_device->CreateTexture(extent, extent, 1, 0, D3DFMT_R5G6B5, D3DPOOL_MANAGED, replacement[index].GetAddressOf(), nullptr), "CreateTexture(shadow)");
        TextureMapping pixels(replacement[index].Get());
        device.checkResult(pixels.status(), "LockRect(shadow)");
        for (std::size_t row = 0; row < extent; ++row)
        {
            auto bytes = pixels.row(row, extent * sizeof(std::uint16_t));
            if (bytes.size() != extent * sizeof(std::uint16_t))
                throw std::runtime_error("Invalid shadow texture pitch");
            std::fill(bytes.begin(), bytes.end(), std::uint8_t{255});
        }
        device.checkResult(pixels.unlock(), "UnlockRect(shadow)");
    }
    mapping.reset();
    valid = false;
    textures = std::move(replacement);
    spot_texture = SferaTextureAccess::find("shadspot");
}

void ShadowMap::shutdown()
{
    g_sfera_shadows.reset();
}

void ShadowMap::setDirection(const SferaVec3F &value, float opacity)
{
    fade = std::clamp(opacity, 0.0f, 1.0f);
    light_basis = SferaMatrix4x4F::identity();
    if (quality == 3u)
    {
        light_basis.m[1][1] = 0.0f;
        light_basis.m[2][1] = -1.0f;
        light_basis.m[1][2] = -1.0f;
        light_basis.m[2][2] = 0.0f;
        direction = {0.0f, -1.0f, 0.0f};
        return;
    }
    direction = value;
    direction.y = std::min(direction.y, -0.10000000149011612f);
    const float length = direction.length();
    const double x = direction.x, y = direction.y, z = direction.z;
    const float azimuth = SferaNumeric::real32(std::atan2(x, z));
    const float yaw = -azimuth;
    float inclination = 0.0f;
    if (length != 0.0f)
    {
        const float rounded_ratio = SferaNumeric::real32(y / length);
        const double ratio = rounded_ratio;
        inclination = SferaNumeric::real32(std::asin(ratio));
    }
    const float pitch = std::min(inclination, -0.7853982448577881f);
    const auto [sy, cy] = SferaMath::rotationTerms(yaw);
    const auto [sp, cp] = SferaMath::rotationTerms(pitch);
    light_basis.m[0][0] = SferaNumeric::real32(cy);
    light_basis.m[1][0] = SferaNumeric::real32(sp * sy);
    light_basis.m[2][0] = SferaNumeric::real32(-sy * cp);
    light_basis.m[1][1] = SferaNumeric::real32(cp);
    light_basis.m[2][1] = SferaNumeric::real32(sp);
    light_basis.m[0][2] = SferaNumeric::real32(sy);
    light_basis.m[1][2] = SferaNumeric::real32(-sp * cy);
    light_basis.m[2][2] = SferaNumeric::real32(cy * cp);
}

bool ShadowMap::prepareModel(WorldObject &object, const SferaVec3F *position, float opacity, std::uint8_t detail)
{
    const auto *model = SferaSceneAccess::model(object);
    return prepareGeometry(object, position, opacity, detail, model->shadow_scale, model->shadow_spread);
}

bool ShadowMap::prepareGeometry(WorldObject &object, const SferaVec3F *position, float opacity, std::uint8_t detail, float scale, float spot_scale)
{
    SferaVec3F center = position == nullptr ? object.position : *position;
    if (position == nullptr)
        center.y = SferaNumeric::real32(center.y - 0.800000011920929);
    valid = false;
    mapping.reset();
    rasterizer = {};
    origin = direction + center;
    if (quality == 4u)
        return true;
    const std::uint32_t shade = SferaNumeric::truncatedWord(((1.0 - opacity) * (1.0 - fade) + fade) * 255.0);
    if (shade >= 255u)
        return true;
    raster_color = D3DCOLOR_XRGB(shade, shade, shade);
    spot_color = D3DCOLOR_XRGB(~shade, ~shade, ~shade);
    if (quality == 3u)
    {
        if (spot_texture == -1)
            return false;
        projection = {};
        const float factor = SferaNumeric::real32(1.0 / spot_scale);
        projection.m[0][0] = factor;
        projection.m[1][2] = -factor;
        projection.m[2][1] = -factor;
        projection.m[3][3] = 1.0f;
        const double x = center.x, y = center.y, z = center.z;
        projection.m[0][3] = SferaNumeric::real32(-x * factor);
        projection.m[1][3] = SferaNumeric::real32(-z * -factor);
        projection.m[2][3] = SferaNumeric::real32(-y * -factor);
    }
    else
    {
        level = std::min(SferaNumeric::lowByte(SferaNumeric::word(quality + detail)), std::uint8_t{2u});
        auto *texture = textures[level].Get();
        if (!texture)
            return false;
        mapping.emplace(texture);
        if (FAILED(mapping->status()))
        {
            mapping.reset();
            return false;
        }
        surface = mapping->description();
        if (surface.Width == 0 || surface.Height == 0 || surface.Height > rasterizer.rows.size())
        {
            mapping.reset();
            return false;
        }
        for (std::size_t row = 0; row < surface.Height; ++row)
        {
            auto bytes = mapping->row(row, surface.Width * sizeof(std::uint16_t));
            if (bytes.size() != surface.Width * sizeof(std::uint16_t))
            {
                mapping.reset();
                return false;
            }
            std::fill(bytes.begin(), bytes.end(), std::uint8_t{255});
        }
        projection = light_basis;
        projection.scaleAxes({scale, scale, scale});
        const SferaVec3F translation{-center.x, -center.y, -center.z};
        for (std::size_t row = 0; row < 4; ++row)
            projection.m[row][3] = SferaNumeric::real32(projection.projectComponent(row, translation));
    }
    valid = true;
    return true;
}

template <class Vertex> void ShadowMap::projectVertices(const Vertex *vertices, std::size_t vertex_count, const std::uint16_t *indices, std::size_t index_count)
{
    if (quality >= 3u || !valid || textures[level] == nullptr)
        return;
    const auto world = g_sfera_graphics_runtime.d3d_runtime->world_transform.transposed();
    const auto transform = projection.multiplied(world);
    projected_points.resize(vertex_count);
    for (std::uint32_t index = 0u; index < vertex_count; ++index)
    {
        const auto &point = vertices[index].position;

        projected_points[index] = {projectedCoordinate(transform, point, 0u, surface.Width), projectedCoordinate(transform, point, 1u, surface.Height)};
    }
    const auto color = SferaColor::fromArgb(raster_color).rgb565();
    for (std::uint32_t face = 0u; face < index_count; face += 3u)
    {
        std::array<ShadowPoint, 3> points{};
        for (std::size_t corner = 0; corner < points.size(); ++corner)
        {
            const auto &point = projected_points[indices[face + corner]];
            points[corner] = {SferaNumeric::real32(SferaNumeric::truncateInt(point.x)), SferaNumeric::real32(SferaNumeric::truncateInt(point.y))};
        }
        const double first_x = points[1].x, first_y = points[1].y;
        const double second_x = points[2].x, second_y = points[2].y;
        if ((first_x - points[0].x) * (second_y - points[0].y) < (second_x - points[0].x) * (first_y - points[0].y))
            continue;
        rasterizer.polygon(color, points, surface.Width, surface.Height, mapping->rectangle());
    }
}

// CharacterRenderer uses this specialization from a separate translation unit.
template void ShadowMap::projectVertices<SphereRenderPositionNormalUvVertex>(const SphereRenderPositionNormalUvVertex *, std::size_t, const std::uint16_t *, std::size_t);

void ShadowMap::projectModel(const SphereRenderModel &model, std::size_t index, const SferaMatrix4x4F *world)
{
    if (quality >= 3u || !valid || textures[level] == nullptr)
        return;
    if (world != nullptr)
    {
        const auto transposed = world->transposed();
        g_sfera_graphics_runtime.d3d_runtime->setTransform(D3DTS_WORLD, transposed);
    }
    const auto &submesh = model.submeshes[index];
    const auto face_count = std::min(submesh.face_count, std::size_t{334u});
    for (std::size_t face = 0u; face < face_count; ++face)
    {
        const auto &source = model.faces[submesh.first_face + face];
        face_indices[face * 3u] = source.vertices[0];
        face_indices[face * 3u + 1u] = source.vertices[2];
        face_indices[face * 3u + 2u] = source.vertices[1];
    }
    projectVertices(model.vertices.data() + submesh.first_vertex, submesh.vertex_count, face_indices.data(), face_count * 3u);
}

ShadowMapPass::ShadowMapPass(ShadowMap &owner) : owner_(owner), direction_(owner.direction), fade_(owner.fade), basis_(owner.light_basis)
{
    owner_.mapping.reset();
    owner_.valid = false;
}

ShadowMapPass::~ShadowMapPass() noexcept
{
    owner_.mapping.reset();
    owner_.valid = false;
}

void ShadowMap::draw(const SferaVec3F *vertices, std::size_t triangle_count)
{
    if (!std::exchange(valid, false))
        return;
    if (quality < 3u)
    {
        if (!mapping)
            return;
        if (rasterizer.pending)
            rasterizer.flush(surface.Height, mapping->rectangle());
        for (std::size_t row = 0; row < surface.Height; ++row)
        {
            auto bytes = mapping->row(row, surface.Width * sizeof(std::uint16_t));
            if (row == 0 || row + 1 == surface.Height)
                std::fill(bytes.begin(), bytes.end(), std::uint8_t{255});
            else
            {
                std::fill_n(bytes.begin(), sizeof(std::uint16_t), std::uint8_t{255});
                std::fill_n(bytes.end() - sizeof(std::uint16_t), sizeof(std::uint16_t), std::uint8_t{255});
            }
        }
        const HRESULT result = mapping->unlock();
        mapping.reset();
        g_sfera_graphics_runtime.d3d_runtime->checkResult(result, "UnlockRect(shadow)");
    }
    if (triangle_count == 0u)
        return;
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    EffectRendering::samplerState(device, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
    EffectRendering::samplerState(device, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
    EffectRendering::identityWorld(device);
    device.setAlphaBlending(D3DBLEND_ZERO, D3DBLEND_SRCCOLOR);
    EffectRendering::renderState(device, D3DRS_FOGENABLE, FALSE);
    EffectRendering::renderState(device, D3DRS_ZWRITEENABLE, FALSE);
    if (quality == 3u)
    {
        SphereRenderSceneRenderer::bindTexture(spot_texture);
        EffectRendering::renderState(device, D3DRS_DESTBLEND, D3DBLEND_INVSRCCOLOR);
        const auto count = std::min(triangle_count * 3u, spot_vertices.size());
        for (std::size_t index = 0; index < count; ++index)
        {
            const auto point = projection.transformPoint(vertices[index]);
            auto &vertex = spot_vertices[index];
            vertex.position = vertices[index];
            vertex.diffuse = spot_color;
            vertex.specular = 0u;
            vertex.u = SferaNumeric::real32(point.x + 0.5);
            vertex.v = SferaNumeric::real32(point.y + 0.5);
        }
        EffectRendering::renderState(device, D3DRS_CULLMODE, D3DCULL_NONE);
        device.checkResult(device.native_device->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1), "SetFVF");
        device.drawVertices(D3DPT_TRIANGLELIST, 0u, spot_vertices.data(), count, nullptr, 0u, sizeof(SphereRenderPositionColorUvVertex));
    }
    else
    {
        device.checkResult(device.native_device->SetTexture(0u, textures[level].Get()), "SetTexture");
        const auto count = triangle_count * 3u;
        auto output = device.model_vertices.lock(count);
        for (std::uint32_t index = 0u; index < count; ++index)
        {
            const auto point = projection.transformPoint(vertices[index]);
            output[index].position = vertices[index];
            output[index].u = SferaNumeric::real32(point.x + 0.5);
            output[index].v = SferaNumeric::real32(point.y + 0.5);
        }
        output.unlock();
        device.drawBuffer(output.buffer(), D3DPT_TRIANGLELIST, 0u, output.first(), count, nullptr, 0u, 0u, sizeof(SphereRenderPositionNormalUvVertex));
    }
    EffectRendering::samplerState(device, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
    EffectRendering::samplerState(device, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
    device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    EffectRendering::renderState(device, D3DRS_FOGENABLE, TRUE);
    EffectRendering::renderState(device, D3DRS_ZWRITEENABLE, TRUE);
}

void ShadowMap::selectObjectLight(const WorldObject &object)
{
    float closest_distance = 50.0f;
    const SferaLightRecord *closest = nullptr;
    SferaVec3F closest_direction{};
    for (std::size_t index = 0u; index < g_sfera_light_runtime.candidate_count; ++index)
    {
        const auto &light = g_sfera_light_runtime.render_candidates[index];
        if (!g_sfera_light_runtime.render_candidate_active[index] || object.position.y < light.position.y)
            continue;
        const auto difference = light.position - object.position;
        const float distance = (difference).length();
        if (distance != 0.0f && distance < 15.0f && distance < closest_distance)
        {
            closest_distance = distance;
            closest = &light;
            closest_direction = difference;
        }
    }
    if (closest != nullptr)
    {
        const float inverse = SferaNumeric::real32(1.0 / closest_distance);
        closest_direction = closest_direction * inverse;
        float opacity = SferaNumeric::real32(closest_distance / 15.0 + 0.20000000298023224);
        const float environment = g_sfera_graphics_runtime.environment_factor;
        if (SphereRenderSceneRenderer::interior_scene == 0u && environment >= 0.25f && environment <= 0.8299999833106995f)
            opacity = std::max(opacity, g_sfera_graphics_runtime.view_scale);
        setDirection(closest_direction, opacity);
    }
    else if (SphereRenderSceneRenderer::interior_scene != 0u)
        setDirection({0.0f, 1.0f, 0.0f}, 1.0f);
}

float ShadowMap::projectionExtension(const WorldObject &object) const
{
    const double vertical = std::max(std::fabs(direction.y), 0.699999988079071f);
    const float rounded_angle = SferaNumeric::real32(std::acos(vertical));
    const double angle = rounded_angle;
    const float tangent = SferaNumeric::real32(std::tan(angle));
    const double top = object.bounds_maximum.y;
    return SferaNumeric::real32(tangent * (top - object.bounds_minimum.y));
}

void ShadowMap::prepareObject(std::uint32_t handle, ExtendedWorldObject &object, double width, float spot_scale, float &extension)
{
    auto &shadows = *g_sfera_shadows;
    if (shadows.quality >= 4u || object.scale < 0.9900000095367432f)
        return;
    shadows.selectObjectLight(object);
    const float distance = (SferaSceneAccess::cameraObject()->position - object.position).length();
    const float distance_opacity = SferaNumeric::real32(1.0 - (distance - 15.0) / 10.0);
    const float opacity = std::clamp(distance_opacity, 0.0f, 1.0f);
    const auto detail = distance > 7.0f ? 2u : distance > 5.0f ? 1u : 0u;
    SphereWorldContactQuery::updateBounds(handle);
    extension = shadows.projectionExtension(object);
    const float scale = SferaNumeric::real32(1.4900000095367432 / (extension + width));
    shadows.prepareGeometry(object, nullptr, opacity, SferaNumeric::lowByte(detail), scale, spot_scale);
}

void ShadowMap::drawObject(ExtendedWorldObject &object, double width, float extension)
{
    auto &shadows = *g_sfera_shadows;
    if (shadows.quality >= 4u || object.scale < 0.9900000095367432f)
        return;
    const auto offset = SferaVec3F{object.position.x - shadows.origin.x, 0.0f, object.position.z - shadows.origin.z}.normalized() * extension;
    const auto center = object.position + offset * 0.5f;
    const float radius = SferaNumeric::real32((extension + width) * 0.800000011920929);
    const SferaVec3F radius_vector{radius, radius, radius};
    const SphereWorldBounds bounds{center - radius_vector, center + radius_vector};
    g_sfera_world_spatial.gatherShadowTriangles(bounds, center, radius, shadows.origin, shadows.direction);
    const auto &vertices = g_sfera_world_spatial.shadowVertices();
    shadows.draw(vertices.data(), (vertices.size() / 3u));
}

float ShadowMap::projectedCoordinate(const SferaMatrix4x4F &transform, const SferaVec3F &point, std::size_t row, std::uint32_t extent)
{
    return SferaNumeric::real32((transform.projectComponent(row, point) + 0.5) * extent);
}

void ShadowRasterizerEdge::step()
{
    const double increment = slope;
    x = SferaNumeric::real32(x + increment);
}

void ShadowRasterizer::flushSpans(int height, const D3DLOCKED_RECT &surface, bool displaced)
{
    auto *pixels = static_cast<std::uint8_t *>(surface.pBits);
    const std::ptrdiff_t stride = surface.Pitch;
    for (int y = 0; y < height; ++y)
    {
        auto *destination = pixels + y * stride;
        auto &span = displaced ? rows[y].displaced : rows[y].active;
        if (span.left >= span.right)
            continue;
        const std::uint16_t color = span.color & 65535u;
        for (int x = span.left; x <= span.right; ++x)
            SferaBinary::writeLittleEndian(destination + x * 2, color);
        span.left = INT32_MAX;
        span.right = INT32_MIN;
    }
}

void ShadowRasterizer::polygon(std::uint32_t color, std::span<const ShadowPoint> points, int width, int height, const D3DLOCKED_RECT &surface)
{
    if (points.empty())
        return;
    const auto lowest = std::min_element(points.begin(), points.end(), &ShadowRasterizer::lowerPoint);
    const std::size_t first_vertex = lowest - points.begin();
    const int first_row = SferaNumeric::truncateInt(lowest->y);
    int row = std::max(first_row, 0);

    ShadowRasterizerEdge left{first_vertex, row - 1}, right{first_vertex, row - 1};
    std::size_t remaining = points.size();
    bool displaced = false;

    do
    {
        while (left.end <= row && remaining > 0)
            advanceEdge(points, height, remaining, row, left, true);
        while (right.end <= row && remaining > 0)
            advanceEdge(points, height, remaining, row, right, false);
        while (row < left.end && row < right.end)
        {
            const int first = SferaNumeric::truncateInt(left.x), last = SferaNumeric::truncateInt(right.x);
            const int begin = std::max(first, 0), end = std::min(last, width - 1);
            left.step();
            right.step();
            auto &spans = rows[row++];
            if (begin > end)
                continue;
            auto &active = spans.active;
            if (active.left == INT32_MAX)
            {
                active = {begin, end, color};
                pending = true;
                continue;
            }
            if (active.color != color || end < active.left || begin > active.right)
            {
                spans.displaced = active;
                active = {begin, end, color};
                displaced = true;
                continue;
            }
            active.left = std::min(active.left, begin);
            active.right = std::max(active.right, end);
        }
    } while (remaining > 0);
    if (displaced)
        flushSpans(height, surface, true);
}

void ShadowRasterizer::advanceEdge(std::span<const ShadowPoint> points, int height, std::size_t &remaining, int row, ShadowRasterizerEdge &edge, bool backwards)
{
    const auto &previous = points[edge.vertex];
    if (backwards)
        edge.vertex = edge.vertex == 0 ? points.size() - 1 : edge.vertex - 1;
    else if (++edge.vertex == points.size())
        edge.vertex = 0;
    const auto &current = points[edge.vertex];
    const int last_row = SferaNumeric::truncateInt(current.y);
    edge.end = std::min(last_row, height);
    --remaining;
    const double x = current.x, y = current.y;
    edge.slope = SferaNumeric::real32((x - previous.x) / (y - previous.y + 6.018531076210112e-36));
    edge.x = SferaNumeric::real32((row + 0.5 - previous.y) * edge.slope + previous.x);
}
