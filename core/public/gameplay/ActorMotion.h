#pragma once

#include <cstddef>
#include <cstdint>

#include "math/Vector.h"

class SphereRenderModel;
class SphereWorldMotion;
struct WorldObject;

class SphereWorldMotion
{
  public:
    uint32_t control_mode{};
    uint8_t tracking_position_pending{};
    uint8_t moved_since_query{};
    SferaVec3F tracked_position{};
    float response_curve[100]{};
    SferaVec3F acceleration{};
    SferaVec3F displacement{};
    float surface_friction[7]{};
    float material_scale[7]{};
    uint32_t orientation_blocked{};

    void initializeResponseCurve();
    float responseValue(int index) const noexcept;
    std::uint32_t probe(std::uint32_t handle, SferaVec3F displacement, float yaw);
    std::uint32_t probeGround(std::uint32_t handle, SferaVec3F displacement, float yaw, bool controlled = false);
    void moveFree(std::uint32_t handle, bool vertical, float yaw, float elapsed, bool controlled);
    void moveGround(std::uint32_t handle, float yaw, float elapsed, bool controlled);
    void fall(std::uint32_t handle, float elapsed, bool controlled);
    void updateObjects(float elapsed);
    void updateControlled(float elapsed);
    void updateOrientation();
    std::uint32_t surfaceInteraction(std::uint32_t handle, std::uint32_t *material);
    std::uint32_t pick(float *distance, SferaVec3F *direction);
    static bool snapSmallComponents(SferaVec3F &value) noexcept;

  private:
    bool avoidContact(std::uint32_t handle, SferaVec3F displacement, float yaw, bool grounded);
    bool slideControlled(std::uint32_t handle, const SferaVec3F &displacement);
    void dampMotion(std::uint32_t handle, float elapsed, bool controlled);

  private:
    static SferaVec3F motionSurfaceNormal();
    static SphereRenderModel *motionModel(const WorldObject &object);
    static SferaVec3F motionContact(std::size_t index);
    static float motionMaterialScale();
    static bool motionHazardBand(float height);
    static SferaVec3F motionPlanarSlide(const SferaVec3F &normal, const SferaVec3F &displacement)
    {
        return ((normal).cross((displacement))).cross((normal));
    }

  private:
    static constexpr double motionNearSupportOffset = 0.03f;
    static constexpr double motionFarSupportOffset = 0.4f;
    static constexpr double motionDeviationThreshold = 0.8f;
    static constexpr double motionGravity = 9.8f;
    static constexpr double motionDamping = 0.4f;
    static constexpr double motionGroundLift = 0.06f;
    static constexpr double motionAngularDamping = 0.78f;
    static constexpr double motionGridScale = 0.12f;
    static constexpr double motionProbeLift = 0.2f;
    static constexpr float motionPickRangeScale = 0.8f;
    static constexpr double motionPickEdgeLift = 0.1f;

  private:
    static auto transformPickPoint(const SphereRenderModel *model, const WorldObject *object, const SferaVec3F &point);
};

extern SphereWorldMotion g_sfera_motion;
