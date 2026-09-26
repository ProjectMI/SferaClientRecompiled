#pragma once

#include <array>
#include <cstdint>
#include <span>

#include "geometry/Geometry.h"
#include "math/Matrix.h"
#include "math/Vector.h"

struct SferaPlaneF;
struct SphereRenderCameraRectangle;
class SphereRenderGameCamera;
class SphereRenderGameCameraFrame;

struct SphereRenderCameraRectangle
{
    std::uint32_t left = 0, top = 0, right = 0, bottom = 0;
    bool operator==(const SphereRenderCameraRectangle &) const = default;
};

class SphereRenderGameCamera
{
  public:
    uint32_t controlled_observer_mode{};
    SferaVec3F frame_corners[5]{};
    SferaMatrix4x4F frame_transform{};

    SphereRenderGameCamera();
    SferaMatrix4x4F transform = SferaMatrix4x4F::identity();
    float near_distance = 1.0f, far_distance = 100.0f, field_of_view = 1.0f;
    float pixel_scale_x = 0.0f, pixel_scale_y = 0.0f, center_x = 0.0f, center_y = 0.0f;
    float minimum_depth = 0.0f, maximum_depth = 0.9999899864196777f, aspect_scale = 0.75f;
    std::uint32_t viewport_x = 0u, viewport_y = 0u, viewport_width = 640u, viewport_height = 480u;
    float tangent_half_fov = 0.0f;
    float offset_x = 0.0f, offset_y = 0.0f, window_width = 1.0f, window_height = 1.0f, window_depth = 1.0f;
    bool off_axis = false;
    void setViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height, float aspect);
    void setPerspective(float near_plane, float far_plane, float angle);
    void setTransform(const SferaMatrix4x4F &matrix);
    void transformPoints(std::span<SferaVec3F> destination, std::span<const SferaVec3F> source) const;
    SferaVec3F cameraPoint(const SferaVec3F &world) const
    {
        return transform.inverseTransformPoint(world);
    }
    bool project(const SferaVec3F &world, SferaVec3F &screen) const;
    bool projectObjectTop(std::uint32_t handle, SferaVec3F &output, float height_factor) const;
    void volume(const SphereRenderCameraRectangle *rectangle, const SferaFrustumF **planes, const SferaVec3F **points);
    static void cameraAxes(SferaVec3F &forward, SferaVec3F &up);
    static void setupViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height);
    static void rebuildVisibleVolume(std::uint32_t left, std::uint32_t top, std::uint32_t right, std::uint32_t bottom);

  private:
    SphereRenderCameraRectangle rectangle_{};
    std::array<SferaVec3F, 6> points_{};
    SferaFrustumF planes_{};
    bool points_current_ = false, planes_current_ = false;

    void buildPoints();
    void buildPlanes();
    static SferaPlaneF boundaryPlane(const SferaVec3F &first, const SferaVec3F &second, const SferaVec3F &third);

  private:
    friend class SphereRenderGameCameraFrame;

  private:
    double perspectiveEdge(double far_limit, double center, std::uint32_t pixel, float scale);
    static std::int64_t fixedVolumeCoordinate(float value);
};

extern SphereRenderGameCamera g_sfera_camera;
