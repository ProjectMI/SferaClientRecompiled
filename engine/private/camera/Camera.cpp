#include <cmath>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <span>

#include "scene/SceneObject.h"
#include "animation/Animation.h"
#include "camera/Camera.h"
#include "diagnostics/Diagnostics.h"
#include "graphics/d3d9/Device.h"
#include "geometry/Geometry.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "scene/SceneAccess.h"

SphereRenderGameCamera::SphereRenderGameCamera() : tangent_half_fov(SferaNumeric::real32(std::tan(0.5)))
{
}

void SphereRenderGameCamera::setViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height, float aspect)
{
    viewport_x = x;
    viewport_y = y;
    viewport_width = width;
    viewport_height = height;
    aspect_scale = aspect;
    const float width_pixels = SferaNumeric::real32(width), height_pixels = SferaNumeric::real32(height);
    center_x = SferaNumeric::real32(width_pixels * 0.5 + x);
    center_y = SferaNumeric::real32(height_pixels * 0.5 + y);
    pixel_scale_x = SferaNumeric::real32(2.0 / width_pixels);
    pixel_scale_y = SferaNumeric::real32(aspect * (2.0 / height_pixels));
}

void SphereRenderGameCamera::setPerspective(float near_plane, float far_plane, float angle)
{
    if (near_distance == near_plane && far_distance == far_plane && field_of_view == angle)
        return;
    near_distance = near_plane;
    far_distance = far_plane;
    field_of_view = angle;
    const float half_angle = SferaNumeric::real32(angle * 0.5);
    const double radians = half_angle;
    tangent_half_fov = SferaNumeric::real32(std::tan(radians));
    off_axis = false;
    points_current_ = false;
    planes_current_ = false;
}

void SphereRenderGameCamera::setTransform(const SferaMatrix4x4F &matrix)
{
    transform = matrix;
    points_current_ = false;
    planes_current_ = false;
}

void SphereRenderGameCamera::transformPoints(std::span<SferaVec3F> destination, std::span<const SferaVec3F> source) const
{
    for (std::size_t index = 0u; index < source.size(); ++index)
        destination[index] = transform.transformPoint(source[index]);
}

bool SphereRenderGameCamera::project(const SferaVec3F &world, SferaVec3F &screen) const
{
    const auto local = cameraPoint(world);
    const double depth = local.x;
    if (near_distance > depth || far_distance < depth)
        return false;
    screen.x = SferaNumeric::real32(center_x - local.y / (depth * tangent_half_fov * pixel_scale_x));
    screen.y = SferaNumeric::real32(center_y - local.z / (depth * tangent_half_fov * pixel_scale_y));
    const double far_limit = far_distance, maximum = maximum_depth;
    screen.z = SferaNumeric::real32(((depth - near_distance) * far_limit / (depth * (far_limit - near_distance))) * (maximum - minimum_depth) + minimum_depth);
    return true;
}

void SphereRenderGameCamera::buildPoints()
{
    points_[0] = {transform.m[0][3], transform.m[1][3], transform.m[2][3]};
    float left, right, top, bottom;
    if (off_axis)
    {
        const double far_limit = far_distance;
        const float rounded_scale = SferaNumeric::real32(far_limit / window_depth);
        const double scale = rounded_scale, width = window_width, height = window_height;
        left = SferaNumeric::real32(offset_x * scale);
        right = SferaNumeric::real32((width + offset_x) * scale);
        top = SferaNumeric::real32(scale * offset_y);
        bottom = SferaNumeric::real32(scale * (height + offset_y));
    }
    else
    {
        const double far_limit = far_distance;

        left = SferaNumeric::real32(perspectiveEdge(far_limit, center_x, rectangle_.left, pixel_scale_x));
        right = SferaNumeric::real32(perspectiveEdge(far_limit, center_x, rectangle_.right, pixel_scale_x));
        top = SferaNumeric::real32(perspectiveEdge(far_limit, center_y, rectangle_.top, pixel_scale_y));
        bottom = SferaNumeric::real32(perspectiveEdge(far_limit, center_y, rectangle_.bottom, pixel_scale_y));
    }
    points_[1] = {far_distance, left, top};
    points_[2] = {far_distance, right, top};
    points_[3] = {far_distance, right, bottom};
    points_[4] = {far_distance, left, bottom};
    points_[5] = {near_distance, 0.0f, 0.0f};
    transformPoints(std::span(points_).subspan(1u), std::span<const SferaVec3F>(points_).subspan(1u));
    points_current_ = true;
}

SferaPlaneF SphereRenderGameCamera::boundaryPlane(const SferaVec3F &a, const SferaVec3F &b, const SferaVec3F &c)
{
    return SferaPlaneF::fromTriangle(a, b, c);
}

void SphereRenderGameCamera::buildPlanes()
{
    for (std::size_t side = 0u; side < 4u; ++side)
        planes_.planes[side + 1u] = boundaryPlane(points_[0], points_[(side + 3u) % 4u + 1u], points_[side + 1u]);
    planes_.planes[5] = boundaryPlane(points_[4], points_[3], points_[2]);
    const auto &far_normal = planes_.planes[5].normal;
    planes_.planes[0].normal = {-far_normal.x, -far_normal.y, -far_normal.z};
    planes_.planes[0].distance = SferaNumeric::real32(far_normal.dot<double, true>(points_[5]));
    planes_current_ = true;
}

void SphereRenderGameCamera::volume(const SphereRenderCameraRectangle *rectangle, const SferaFrustumF **planes, const SferaVec3F **points)
{
    if (off_axis && rectangle != nullptr)
    {
        if (planes != nullptr)
            *planes = nullptr;
        if (points != nullptr)
            *points = nullptr;
        return;
    }
    const SphereRenderCameraRectangle requested = rectangle == nullptr ? SphereRenderCameraRectangle{viewport_x, viewport_y, viewport_x + viewport_width - 1u, viewport_y + viewport_height - 1u}
                                                                       : *rectangle;
    if (!(requested == rectangle_))
    {
        rectangle_ = requested;
        points_current_ = false;
        planes_current_ = false;
    }
    if (!points_current_)
        buildPoints();
    if (planes != nullptr && !planes_current_)
        buildPlanes();
    if (planes_.planes[0].evaluate(points_[0]) > 0.0)
        for (auto &plane : planes_.planes)
        {
            plane.normal = {-plane.normal.x, -plane.normal.y, -plane.normal.z};
            plane.distance = -plane.distance;
        }
    if (planes != nullptr)
        *planes = &planes_;
    if (points != nullptr)
        *points = points_.data();
}

void SphereRenderGameCamera::setupViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height)
{
    if (width == 0u || height == 0u)
        SferaEngineDiagnostics::fail("Empty camera viewport");
    SferaVec3F forward, up;
    cameraAxes(forward, up);
    const auto *camera = SferaSceneAccess::cameraObject();
    const auto target = camera->position + forward;
    SferaMatrix4x4F view_matrix = SferaMatrix4x4F::identity();
    SferaMatrix4x4F projection_matrix{};
    auto view_z = camera->position - target;
    view_z.normalize();
    auto view_x = up.cross(view_z);
    view_x.normalize();
    const auto view_y = view_z.cross(view_x);
    view_matrix.m[0][0] = view_x.x;
    view_matrix.m[0][1] = view_y.x;
    view_matrix.m[0][2] = view_z.x;
    view_matrix.m[1][0] = view_x.y;
    view_matrix.m[1][1] = view_y.y;
    view_matrix.m[1][2] = view_z.y;
    view_matrix.m[2][0] = view_x.z;
    view_matrix.m[2][1] = view_y.z;
    view_matrix.m[2][2] = view_z.z;
    view_matrix.m[3][0] = SferaNumeric::real32(-view_x.dot(camera->position));
    view_matrix.m[3][1] = SferaNumeric::real32(-view_y.dot(camera->position));
    view_matrix.m[3][2] = SferaNumeric::real32(-view_z.dot(camera->position));
    const float width_value = SferaNumeric::real32(width), height_value = SferaNumeric::real32(height);
    const double rounded_width = width_value, rounded_height = height_value;
    const float aspect = SferaNumeric::real32(rounded_width / height_value);
    const float half_angle = SferaNumeric::real32(g_sfera_camera.field_of_view * 0.5);
    const double radians = half_angle;
    const float tangent = SferaNumeric::real32(std::tan(radians));
    const double rounded_tangent = tangent;
    const float vertical_tangent = SferaNumeric::real32(rounded_tangent / aspect);
    const double vertical_slope = vertical_tangent;
    const float vertical_half_angle = SferaNumeric::real32(std::atan(vertical_slope));
    const float vertical_angle = SferaNumeric::real32(vertical_half_angle * 2.0);
    const float projection_y = 1.0f / std::tan(vertical_angle * 0.5f);
    const float depth_range = g_sfera_camera.near_distance - g_sfera_camera.far_distance;
    projection_matrix = {};
    projection_matrix.m[0][0] = projection_y / aspect;
    projection_matrix.m[1][1] = projection_y;
    projection_matrix.m[2][2] = g_sfera_camera.far_distance / depth_range;
    projection_matrix.m[2][3] = -1.0f;
    projection_matrix.m[3][2] = g_sfera_camera.near_distance * g_sfera_camera.far_distance / depth_range;
    g_sfera_camera.frame_transform = SferaMatrix4x4F::fromEuler(camera->position, camera->rotation);
    g_sfera_camera.setTransform(g_sfera_camera.frame_transform.multiplied(SphereRenderModelPose::coordinate_basis));
    g_sfera_camera.setViewport(x, y, width, height, SferaNumeric::real32(rounded_height / width_value));
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    const D3DVIEWPORT9 viewport{x, y, width, height, 0.0f, 1.0f};
    device.native_device->SetViewport(&viewport);
    const auto identity = SferaMatrix4x4F::identity();
    device.setTransform(D3DTS_WORLD, identity);
    device.setTransform(D3DTS_VIEW, view_matrix);
    device.setTransform(D3DTS_PROJECTION, projection_matrix);
    rebuildVisibleVolume(x, y, x + width - 1u, y + height - 1u);
}

double SphereRenderGameCamera::perspectiveEdge(double far_limit, double center, std::uint32_t pixel, float scale)
{
    const float direction = SferaNumeric::real32((center - pixel) * tangent_half_fov * scale);
    return direction * far_limit;
}

std::int64_t SphereRenderGameCamera::fixedVolumeCoordinate(float value)
{
    return SferaNumeric::truncateInt64(value * 1024.0);
}
