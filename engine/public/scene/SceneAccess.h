#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <string_view>

enum class SphereRenderCollisionKind : std::uint32_t;

struct WorldObject;
struct ExtendedWorldObject;
struct SferaVec3F;
class SphereRenderModel;

// The application supplies scene ownership and gameplay notifications.
// Geometry, animation and rendering only use the engine objects returned here.
class SferaSceneAccess
{
  public:
    static WorldObject *object(std::uint32_t handle, std::optional<std::string_view> operation = std::nullopt);
    static ExtendedWorldObject *extendedObject(std::uint32_t handle);
    static WorldObject *controlledObject();
    static WorldObject *cameraObject();
    static std::uint32_t cameraHandle();
    static bool vegetationVisible();
    static std::uint32_t controlledHandle();
    static SphereRenderModel *model(const WorldObject &object);
    static std::size_t modelCount();
    static SferaVec3F referencePosition();
    static float fieldOfView(int width, int height);
    static void notifyContact(std::uint32_t subject, const WorldObject &obstacle, SphereRenderCollisionKind shape);
};
