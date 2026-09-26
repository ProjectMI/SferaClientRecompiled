#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <string_view>
#include <unordered_set>
#include <vector>

#include "scene/SceneObject.h"
#include "world/ServerGeometry.h"

struct SferaActiveEffect;

struct ExtendedWorldObject;
struct SferaEffectFrames;
struct SferaMbcProcessRecord;
struct SferaVec3F;
class SphereRenderModel;
struct WorldDestructionGuard;
class WorldObjects;

class WorldObjects
{
  public:
    std::uint64_t material_refresh_tick{};
    std::unique_ptr<Contours> contours{};

    uint32_t max_occupied_object_handle;
    uint32_t controlled_object_handle;
    std::vector<std::unique_ptr<WorldObject>> object_handles;
    std::uint32_t next_object_handle = 0;
    std::unordered_set<std::uint32_t> destroying_handles;
    bool clearing = false;
    bool clear_requested = false;
    std::vector<std::uint32_t> extended_object_handles;
    std::size_t extended_object_count;

    WorldObject *effectObject(std::uint32_t handle) const
    {
        return handle < object_handles.size() ? object_handles[handle].get() : nullptr;
    }
    SferaVec3F referencePosition() const
    {
        return objectPosition(1u);
    }
    SferaVec3F objectPosition(std::uint32_t handle) const;
    bool attachEffect(std::uint32_t handle, SferaActiveEffect &item);
    void detachEffect(std::uint32_t handle, SferaActiveEffect &item);
    SferaActiveEffect *firstEffect(std::uint32_t handle) const;
    SferaEffectFrames buildEffectFrames(std::uint32_t handle) const;
    WorldObject *object(std::uint32_t handle, std::optional<std::string_view> operation = std::nullopt) const;
    WorldObject *object(std::uint32_t, std::nullptr_t) const = delete;
    ExtendedWorldObject *extendedObject(std::uint32_t handle) const;
    WorldObject *controlledObject() const;
    static SferaMbcProcessRecord *boundProcess(const WorldObject &object);
    SphereRenderModel *model(const WorldObject &object) const;
    std::uint32_t create(std::string_view name, SferaMbcProcessRecord *process, std::uint32_t kind, bool dynamic);
    void destroy(std::uint32_t handle);
    void destroyAll();
    void clear();
    void removeSpatialIndex(std::uint32_t handle);
    void updateSpatialIndex(std::uint32_t handle);
    void updateExtendedSpatialIndices();
    void rotate(std::uint32_t handle, const SferaVec3F &delta);
    void approachHeading(std::uint32_t handle, float target);
    void moveLocal(std::uint32_t handle, const SferaVec3F &displacement);
    void alignReferenceOrientation();
    void reflectReferenceOrientation();
    void recalculateBasis(std::uint32_t handle);
    void appendCommand(std::uint32_t handle, std::string_view command);
    bool actorActive(std::uint32_t handle) const;
    void activateTrap(const WorldObject &obstacle);
    void addExtended(std::uint32_t handle);
    void removeExtended(std::uint32_t handle);
    void unlink(std::uint32_t parent, std::uint32_t slot);
    ExtendedWorldObject *linkModel(std::uint32_t parent, std::string_view name, std::uint32_t slot);

  private:
    static bool worldSamePoint(const SferaVec3F &first, const SferaVec3F &second)
    {
        return first.x == second.x && first.y == second.y && first.z == second.z;
    }
    static SferaVec3F worldRotateVector(SferaVec3F value, const SferaVec3F &rotation);
    static SferaVec3F worldAnglesFromBasis(SferaVec3F forward, SferaVec3F up);
    static int worldAngleDifference(float target, float current);

  private:
    static auto encodeOrientationAngle(float value) -> int;
    static auto rememberSpatialPosition(ExtendedWorldObject *extended, const WorldObject *item);
    static auto lowerSpatialCell(float coordinate);
    static auto upperSpatialCell(float coordinate);
    static auto wasSpatialCellCovered(bool registered, const WorldObject *item, int x, int z)
    {
        return registered && x >= item->grid_min_x && x <= item->grid_max_x && z >= item->grid_min_y && z <= item->grid_max_y;
    }
    static bool isSmallOrientation(int value);
    static bool equalTrapCharacter(std::uint8_t first, std::uint8_t second);
    static bool isActiveEffect(const SferaActiveEffect *effect, const std::shared_ptr<SferaActiveEffect> &item)
    {
        return item.get() == effect;
    }
};

struct WorldDestructionGuard
{
    std::unordered_set<std::uint32_t> &active;
    std::uint32_t handle;
    ~WorldDestructionGuard()
    {
        active.erase(handle);
    }
};

extern WorldObjects g_sfera_world_objects;

class SferaWorldView;

class SferaWorldView
{
  public:
    static SferaVec3F terrainAnchor();
};
