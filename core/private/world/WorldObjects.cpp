#include <algorithm>
#include <array>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <format>
#include <functional>
#include <iterator>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <utility>
#include <variant>

#include "animation/Animation.h"
#include "collision/Collision.h"
#include "diagnostics/ClientDiagnostics.h"
#include "effects/ActiveEffect.h"
#include "effects/Effect.h"
#include "effects/EffectManager.h"
#include "gameplay/ActorMotion.h"
#include "math/MathFunctions.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/GameRendering.h"
#include "render/Model.h"
#include "render/SceneRenderer.h"
#include "render/CharacterRenderer.h"
#include "resources/ModelResources.h"
#include "resources/TerrainResources.h"
#include "runtime/Clock.h"
#include "scene/SceneAccess.h"
#include "scene/SceneObject.h"
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"
#include "spatial/SpatialIndex.h"
#include "terrain/Terrain.h"
#include "text/Text.h"
#include "ui/ScriptInterface.h"
#include "world/WorldObjects.h"

void WorldObjects::approachHeading(std::uint32_t handle, float target)
{
    auto *instance = object(handle);
    if (instance == nullptr)
        WorldDiagnostics::fail("SetAngle: wrong handle");
    const auto *appearance = model(*instance);
    if (appearance == nullptr)
        WorldDiagnostics::fail("SetAngle: object has no model");
    constexpr float step = 0.15707965195178986f;
    constexpr double fullTurn = 6.283185958862305;
    float &heading = instance->rotation.x;
    if (appearance->radius < 5.0f || SferaAngle8(heading).distanceTo(SferaAngle8(target)) <= step)
    {
        heading = target;
        return;
    }
    const double current_heading = heading;
    const float clockwise = SferaNumeric::real32(current_heading + step);
    const float counterclockwise = SferaNumeric::real32(current_heading - step);
    if (SferaAngle8(clockwise).distanceTo(SferaAngle8(target)) < SferaAngle8(counterclockwise).distanceTo(SferaAngle8(target)))
        heading = SferaNumeric::real32(clockwise > fullTurn ? clockwise - fullTurn : clockwise);
    else
        heading = SferaNumeric::real32(counterclockwise < 0.0f ? counterclockwise + fullTurn : counterclockwise);
}



SferaVec3F WorldObjects::objectPosition(std::uint32_t handle) const
{
    auto *object = effectObject(handle);
    if (object == nullptr)
        object = effectObject(1u);
    return object == nullptr ? SferaVec3F{} : object->position;
}

bool WorldObjects::attachEffect(std::uint32_t handle, SferaActiveEffect &item)
{
    auto *object = effectObject(handle);
    if (!object || clearing || destroying_handles.contains(handle))
        return false;
    for (auto &effect : object->attached_effects)
        if (!effect)
        {
            effect = &item;
            return true;
        }
    return false;
}

void WorldObjects::detachEffect(std::uint32_t handle, SferaActiveEffect &item)
{
    auto *object = effectObject(handle);
    if (!object)
        return;
    for (auto &effect : object->attached_effects)
        if (effect == &item)
        {
            effect = nullptr;
            return;
        }
}

SferaActiveEffect *WorldObjects::firstEffect(std::uint32_t handle) const
{
    const auto *object = effectObject(handle);
    return object ? object->attached_effects[0] : nullptr;
}

SferaEffectFrames WorldObjects::buildEffectFrames(std::uint32_t handle) const
{
    SferaEffectFrames frames;
    auto *object = effectObject(handle);
    frames.positions[0] = objectPosition(handle);
    if (object != nullptr && object->extended())
    {
        const auto *extended = object->extended();
        frames.positions[1] = extended->effect_frame_position_a;
        frames.positions[2] = extended->effect_frame_position_b;
        frames.positions[4] = extended->effect_frame_position_c;
        frames.transforms[1] = extended->effect_frame_transform_a;
        frames.transforms[2] = extended->effect_frame_transform_b;
        frames.transforms[4] = extended->effect_frame_transform_c;
    }
    else
    {
        const SferaVec3F attachment = object != nullptr ? object->position : referencePosition();
        frames.positions[1] = attachment;
        frames.positions[2] = attachment;
        frames.positions[4] = attachment;
        for (auto index : {1u, 2u, 4u})
            frames.transforms[index] = SferaMatrix4x4F::identity();
    }
    frames.positions[3] = {(frames.positions[1].x + frames.positions[2].x) * 0.5f, (frames.positions[1].y + frames.positions[2].y) * 0.5f, (frames.positions[1].z + frames.positions[2].z) * 0.5f};
    const auto rotation = object != nullptr ? SferaVec3F{object->rotation.x, object->rotation.y, object->rotation.z} : SferaVec3F{};
    const auto orientation = SferaMatrix4x4F::fromEuler({}, rotation);
    frames.transforms[0] = orientation;
    // Between-hands transform remains zero, matching the existing attachment convention.
    return frames;
}


SferaVec3F WorldObjects::worldRotateVector(SferaVec3F value, const SferaVec3F &rotation)
{
    SferaVec3F::rotatePair(value.x, value.z, rotation.x);
    SferaVec3F::rotatePair(value.z, value.y, rotation.y);
    SferaVec3F::rotatePair(value.x, value.y, rotation.z);
    return value;
}

SferaVec3F WorldObjects::worldAnglesFromBasis(SferaVec3F forward, SferaVec3F up)
{
    return SferaMath::anglesFromBasis(forward, up);
}

auto WorldObjects::encodeOrientationAngle(float value) -> int
{
    return SferaNumeric::truncateInt(value * 10430.37835) & 65535;
}

int WorldObjects::worldAngleDifference(float target, float current)
{
    const int destination = encodeOrientationAngle(target), source = encodeOrientationAngle(current);
    int difference = destination - source;
    if (std::abs(difference) >= 32768)
        difference = ((destination + 32768) & 65535) - ((source + 32768) & 65535);
    return difference;
}

WorldObject *WorldObjects::object(std::uint32_t handle, std::optional<std::string_view> operation) const
{
    auto *result = handle < object_handles.size() ? object_handles[handle].get() : nullptr;
    if (result == nullptr && operation)
    {
        WorldDiagnostics::message = std::format("{}: wrong handle", *operation);
        WorldDiagnostics::flushScriptContext();
    }
    return result;
}

ExtendedWorldObject *WorldObjects::extendedObject(std::uint32_t handle) const
{
    auto *result = object(handle);
    if (result == nullptr)
        return nullptr;
    if (!result->extended())
        WorldDiagnostics::fail("Try to get extended from superstatic");
    return result->extended();
}

WorldObject *WorldObjects::controlledObject() const
{
    if (clearing || destroying_handles.contains(controlled_object_handle))
        return nullptr;
    return object(controlled_object_handle);
}

SphereRenderModel *WorldObjects::model(const WorldObject &object) const
{
    if (const auto *reference = std::get_if<WorldObjectModelReference>(&object.model_source))
    {
        if (reference->asset == nullptr)
            reference->asset = g_sfera_models.model(reference->id);
        return reference->asset.get();
    }
    return std::get<std::unique_ptr<SphereRenderModel>>(object.model_source).get();
}

std::uint32_t WorldObjects::create(std::string_view name, SferaMbcProcessRecord *process, std::uint32_t kind, bool dynamic)
{
    if (clearing)
        return UINT32_MAX;
    const auto modelHandle = g_sfera_models.find(name);
    if (modelHandle == SphereRenderModelRepository::invalid_index)
    {
        WorldDiagnostics::warning(std::format("CreateObject: no model with such name: {}", name));
        return UINT32_MAX;
    }
    auto handle = next_object_handle;
    while (handle < object_handles.size() && object(handle) != nullptr)
        ++handle;
    if (handle >= object_handles.size())
        WorldDiagnostics::fail("CreateObject: object handle table is full");
    std::unique_ptr<WorldObject> created;
    if (dynamic)
        created = std::make_unique<ExtendedWorldObject>();
    else
        created = std::make_unique<WorldObject>();
    created->model_source = WorldObjectModelReference{modelHandle, {}};
    created->render_group = kind;
    created->visible = true;
    created->render_fade = -1.0f;
    created->grid_min_x = 1000000;
    if (auto *extended = created->extended())
    {
        extended->scale = 1.0f;
        extended->render_enabled = true;
        extended->airborne = true;
        extended->user_context = process;
        extended->last_simulation_tick = g_sfera_mbc_runtime.simulation_tick;
    }
    object_handles[handle] = std::move(created);
    try
    {
        if (dynamic)
        {
            if (kind != 0u)
                addExtended(handle);
            recalculateBasis(handle);
        }
        else
            updateSpatialIndex(handle);
    }
    catch (...)
    {
        if (dynamic)
            removeExtended(handle);
        object_handles[handle].reset();
        throw;
    }
    if (SferaText::asciiEqual(name, "crt04"))
        object(handle)->render_group = 5u;
    if (max_occupied_object_handle == UINT32_MAX || handle > max_occupied_object_handle)
        max_occupied_object_handle = handle;
    next_object_handle = handle + 1u;
    return handle;
}

void WorldObjects::recalculateBasis(std::uint32_t handle)
{
    auto *item = extendedObject(handle);
    if (item == nullptr)
    {
        WorldDiagnostics::warning("recalk_orts: wrong handle");
        return;
    }
    if (WorldObjects::worldSamePoint(item->previous_basis_rotation, item->rotation))
        return;
    item->previous_basis_rotation = item->rotation;
    item->orientation_basis[0] = WorldObjects::worldRotateVector({0.0f, 0.0f, 1.0f}, item->rotation);
    item->orientation_basis[1] = WorldObjects::worldRotateVector({0.0f, -1.0f, 0.0f}, item->rotation);
    item->orientation_basis[2] = item->orientation_basis[0].cross(item->orientation_basis[1]);
}

void WorldObjects::rotate(std::uint32_t handle, const SferaVec3F &delta)
{
    auto *item = extendedObject(handle);
    if (item == nullptr)
    {
        WorldDiagnostics::warning("rotate_object: wrong handle");
        return;
    }
    item->orientation_basis[0] = WorldObjects::worldRotateVector(WorldObjects::worldRotateVector({0.0f, 0.0f, 1.0f}, delta), item->rotation);
    item->orientation_basis[1] = WorldObjects::worldRotateVector(WorldObjects::worldRotateVector({0.0f, -1.0f, 0.0f}, delta), item->rotation);
    item->orientation_basis[2] = item->orientation_basis[0].cross(item->orientation_basis[1]);
    item->rotation = WorldObjects::worldAnglesFromBasis(item->orientation_basis[0], item->orientation_basis[1]);
}

void WorldObjects::moveLocal(std::uint32_t handle, const SferaVec3F &displacement)
{
    auto *item = extendedObject(handle);
    if (item == nullptr)
    {
        WorldDiagnostics::warning("move_object: wrong handle");
        return;
    }
    recalculateBasis(handle);
    SferaVec3F delta{};
    const double x = displacement.x, y = displacement.y, z = displacement.z;
    for (std::size_t axis = 0; axis < 3; ++axis)
        delta.setComponent(axis,
                           SferaNumeric::real32(item->orientation_basis[0].component(axis) * z - item->orientation_basis[1].component(axis) * y + item->orientation_basis[2].component(axis) * x));
    item->position = item->position + delta;
    if (handle == controlled_object_handle)
    {
        g_sfera_motion.tracked_position.x = item->position.x + 333.0f;
        g_sfera_motion.tracked_position.y = item->position.y + 333.0f;
        g_sfera_motion.tracked_position.z = item->position.z + 333.0f;
    }
}

bool WorldObjects::isSmallOrientation(int value)
{
    return std::abs(value) <= 100;
}

void WorldObjects::alignReferenceOrientation()
{
    auto *item = extendedObject(0u);
    if (item == nullptr)
        return;
    recalculateBasis(0u);
    const SferaVec3F desired{SphereRenderModelPose::scale.x, SphereRenderModelPose::scale.y, SphereRenderModelPose::scale.z};
    const float projection = SferaNumeric::real32(item->orientation_basis[0].dot<double, true>(desired));
    const float alignment = std::abs(projection);
    if (alignment > 0.985)
        return;
    const float speed = SferaNumeric::real32((1.100000023841858 - alignment) * 8.000000093488779e-7);
    const SferaVec3F tangent = item->orientation_basis[0].cross(desired);
    const SferaVec3F up = item->orientation_basis[0].cross(tangent);
    const SferaVec3F target = WorldObjects::worldAnglesFromBasis(item->orientation_basis[0], up);
    const std::array<int, 3> difference{WorldObjects::worldAngleDifference(target.x, item->rotation.x), WorldObjects::worldAngleDifference(target.y, item->rotation.y),
                                        WorldObjects::worldAngleDifference(target.z, item->rotation.z)};
    if (std::all_of(difference.begin(), difference.end(), isSmallOrientation))
        return;
    const double rotation_speed = speed;
    for (std::size_t axis = 0; axis < difference.size(); ++axis)
        item->rotation.setComponent(axis, SferaNumeric::real32(item->rotation.component(axis) + difference[axis] * rotation_speed));
}

void WorldObjects::reflectReferenceOrientation()
{
    auto *item = extendedObject(1u);
    if (item == nullptr)
        return;
    item->orientation_basis[0].y = -item->orientation_basis[0].y;
    item->orientation_basis[1] = item->orientation_basis[2].cross(item->orientation_basis[0]);
    item->rotation = WorldObjects::worldAnglesFromBasis(item->orientation_basis[0], item->orientation_basis[1]);
    item->previous_basis_rotation = item->rotation;
}

void WorldObjects::removeSpatialIndex(std::uint32_t handle)
{
    auto *item = object(handle);
    if (item == nullptr || item->grid_min_x == 1000000)
        return;

    for (int x = item->grid_min_x; x <= item->grid_max_x; ++x)
        for (int z = item->grid_min_y; z <= item->grid_max_y; ++z)
            g_sfera_world_spatial.remove(handle, x, z);
}

auto WorldObjects::rememberSpatialPosition(ExtendedWorldObject *extended, const WorldObject *item)
{
    if (extended)
    {
        extended->previous_spatial_position = item->position;
        extended->previous_spatial_rotation = item->rotation;
    }
}

auto WorldObjects::lowerSpatialCell(float coordinate)
{
    return SferaNumeric::truncateInt((coordinate - 2.0) * 0.11999999731779099 + 100000.0) - 100000;
}

auto WorldObjects::upperSpatialCell(float coordinate)
{
    return SferaNumeric::truncateInt((coordinate + 2.0) * 0.11999999731779099 + 100000.0) - 100000;
}


void WorldObjects::updateSpatialIndex(std::uint32_t handle)
{
    auto *item = object(handle);
    if (item == nullptr)
        return;
    auto *extended = item->extended();
    if (extended && WorldObjects::worldSamePoint(extended->previous_spatial_position, item->position) && WorldObjects::worldSamePoint(extended->previous_spatial_rotation, item->rotation))
        return;

    SphereWorldContactQuery::updateBounds(handle);

    const int minX = lowerSpatialCell(item->bounds_minimum.x), minZ = lowerSpatialCell(item->bounds_minimum.z), maxX = upperSpatialCell(item->bounds_maximum.x),
              maxZ = upperSpatialCell(item->bounds_maximum.z);
    const bool registered = item->grid_min_x != 1000000;
    if (registered && item->grid_min_x == minX && item->grid_min_y == minZ && item->grid_max_x == maxX && item->grid_max_y == maxZ)
    {
        rememberSpatialPosition(extended, item);
        return;
    }

    int insertedX = minX, insertedZ = minZ;
    try
    {
        for (; insertedX <= maxX; ++insertedX)
        {
            for (insertedZ = minZ; insertedZ <= maxZ; ++insertedZ)
            {
                if (!wasSpatialCellCovered(registered, item, insertedX, insertedZ))
                    g_sfera_world_spatial.insert(handle, insertedX, insertedZ);
            }
        }
    }
    catch (...)
    {
        for (int x = minX; x <= insertedX; ++x)
        {
            const int endZ = x == insertedX ? insertedZ - 1 : maxZ;
            for (int z = minZ; z <= endZ; ++z)
                if (!wasSpatialCellCovered(registered, item, x, z))
                    g_sfera_world_spatial.remove(handle, x, z);
        }
        throw;
    }
    if (registered)
    {
        for (int x = item->grid_min_x; x <= item->grid_max_x; ++x)
        {
            for (int z = item->grid_min_y; z <= item->grid_max_y; ++z)
            {
                if (x < minX || x > maxX || z < minZ || z > maxZ)
                    g_sfera_world_spatial.remove(handle, x, z);
            }
        }
    }
    // Reinsert overlapping membership in the same order as the former remove/insert pass.
    for (int x = minX; x <= maxX; ++x)
        for (int z = minZ; z <= maxZ; ++z)
            if (wasSpatialCellCovered(registered, item, x, z))
                g_sfera_world_spatial.insert(handle, x, z);
    rememberSpatialPosition(extended, item);
    item->grid_min_x = minX;
    item->grid_max_x = maxX;
    item->grid_min_y = minZ;
    item->grid_max_y = maxZ;
}

void WorldObjects::updateExtendedSpatialIndices()
{
    auto remaining = extended_object_count;
    const auto *handles = extended_object_handles.data();
    for (std::size_t index = 0u; index < extended_object_handles.size() && remaining != 0u; ++index)
    {
        if (handles[index] == 0u)
            continue;
        const auto handle = handles[index];
        --remaining;
        const auto *item = extendedObject(handle);
        if (item != nullptr && item->render_enabled && item->parent_object_handle == 0u)
            updateSpatialIndex(handle);
    }
}

void WorldObjects::appendCommand(std::uint32_t handle, std::string_view command)
{
    if (auto *item = extendedObject(handle); item != nullptr && boundProcess(*item) != nullptr)
        boundProcess(*item)->appendCommand(command);
}

bool WorldObjects::actorActive(std::uint32_t handle) const
{
    (void)extendedObject(handle);
    return false; // This executable has no subscriber producer.
}

bool WorldObjects::equalTrapCharacter(std::uint8_t first, std::uint8_t second)
{
    return std::tolower(first) == std::tolower(second);
}

void WorldObjects::activateTrap(const WorldObject &obstacle)
{
    const auto *resource = model(obstacle);
    const auto now = WorldClock::nowTicks();
    if (resource == nullptr || now - g_sfera_world_objects.material_refresh_tick <= 10000u)
        return;
    const std::string_view name(resource->name), pattern("trap");
    if (std::search(name.begin(), name.end(), pattern.begin(), pattern.end(), equalTrapCharacter) == name.end())
        return;
    if (auto *controlled = extendedObject(controlled_object_handle); controlled != nullptr && boundProcess(*controlled) != nullptr)
    {
        for (auto *effect : obstacle.attached_effects)
            if (effect)
            {
                const auto id = effect == nullptr ? 0u : effect->listener_key;
                appendCommand(controlled_object_handle, (std::string("trap ") + std::to_string(id)));
                break;
            }
    }
    g_sfera_world_objects.material_refresh_tick = now;
}

void WorldObjects::removeExtended(std::uint32_t handle)
{
    auto *item = extendedObject(handle);
    if (!item)
        return;
    const auto index = item->extended_object_index;
    if (index == ExtendedWorldObject::unregistered)
        return;
    if (index >= extended_object_handles.size())
        WorldDiagnostics::fail("Extended object index is outside the registry");
    extended_object_handles[index] = 0;
    item->extended_object_index = ExtendedWorldObject::unregistered;
    --extended_object_count;
}

void WorldObjects::addExtended(std::uint32_t handle)
{
    auto *item = extendedObject(handle);
    if (!item || item->extended_object_index != ExtendedWorldObject::unregistered)
        return;
    auto *handles = extended_object_handles.data();
    std::size_t index = 0;
    while (index < extended_object_handles.size() && handles[index])
        ++index;
    if (index == extended_object_handles.size())
        WorldDiagnostics::fail("Extended object handle table is full");
    handles[index] = handle;
    item->extended_object_index = index;
    ++extended_object_count;
}

void WorldObjects::unlink(std::uint32_t parentHandle, std::uint32_t slot)
{
    auto *parent = object(parentHandle);
    if (!parent || slot >= 5)
    {
        WorldDiagnostics::warning("Wrong handle: Link_object_to_object");
        return;
    }
    const auto child = parent->linked_objects[slot];
    if (child)
        destroy(child);
    if (auto *survivor = object(parentHandle))
        survivor->linked_objects[slot] = 0;
}


void WorldObjects::destroy(std::uint32_t handle)
{
    {
        if (!destroying_handles.insert(handle).second)
            return;
        WorldDestructionGuard guard{destroying_handles, handle};
        // The script owns the binding. controlledObject() excludes this handle
        // during callbacks without discarding a pending/recreated-object binding.
        auto *owned = object(handle);
        if (!owned)
        {
            WorldDiagnostics::warning("DeleteObject: wrong handle");
            return;
        }
        WorldGuiControls::removeForObject(handle);
        // Callbacks may delete other effects. Retain each active instance until its callback returns.
        for (auto &slot : owned->attached_effects)
        {
            auto *effect = slot;
            if (effect == nullptr)
                continue;
            const auto &active = g_sfera_effect_manager.active_effects;
            const auto found = std::find_if(active.begin(), active.end(), std::bind_front(isActiveEffect, effect));
            if (found == active.end())
            {
                slot = nullptr;
                continue;
            }
            const auto retained = *found;
            if (!g_sfera_effect_manager.removeActiveEffect(effect) && retained->active)
            {
                // A veto may keep the effect alive, but it cannot retain a reusable world slot.
                retained->position = owned->position;
                retained->position_source = 1u;
                retained->source_handle = UINT32_MAX;
            }
            slot = nullptr;
        }
        if (auto *extended = owned->extended())
        {
            if (extended->parent_object_handle == 0)
            {
                removeSpatialIndex(handle);
                for (auto &child : owned->linked_objects)
                {
                    const auto childHandle = std::exchange(child, 0u);
                    if (childHandle != handle && childHandle != 0u && object(childHandle))
                        destroy(childHandle);
                }
            }
            else if (auto *parent = object(extended->parent_object_handle); parent && extended->parent_link_slot < 5)
            {
                if (parent->linked_objects[extended->parent_link_slot] == handle)
                    parent->linked_objects[extended->parent_link_slot] = 0;
            }
            if (extended->render_cache_handle < 0)
            {
                auto *models = SphereRenderSceneRenderer::characters.get();
                const std::uint32_t index = -1 - extended->render_cache_handle;
                if (models && index < std::size(models->instances))
                    models->instances[index].owner = nullptr;
                else
                    WorldDiagnostics::fail("Character instance handle is outside the cache");
            }
            removeExtended(handle);
        }
        else
            removeSpatialIndex(handle);
        if (g_sfera_mbc_runtime.current_object == owned)
            g_sfera_mbc_runtime.current_object = nullptr;
        if (owned->ownsModel() && SphereRenderModelPose::active_model == model(*owned))
            SphereRenderModelPose::active_model = nullptr;
        object_handles.at(handle).reset();
        next_object_handle = std::min(next_object_handle, handle);
        if (handle == max_occupied_object_handle)
        {
            do
            {
                --max_occupied_object_handle;
            } while (max_occupied_object_handle != UINT32_MAX && !object(max_occupied_object_handle));
        }
    }
    if (clear_requested && destroying_handles.empty())
        clear();
}

void WorldObjects::destroyAll()
{
    const auto limit = std::min(std::size_t{500000}, object_handles.size());
    for (std::uint32_t handle = 2; handle < limit; ++handle)
        if (object(handle))
            destroy(handle);
}

void WorldObjects::clear()
{
    if (clearing)
        return;
    if (!destroying_handles.empty())
    {
        clear_requested = true;
        return;
    }
    clearing = true;
    clear_requested = false;
    try
    {
        destroyAll();
        for (std::uint32_t handle = 0; handle < std::min<std::size_t>(2, object_handles.size()); ++handle)
            if (object(handle))
                destroy(handle);
    }
    catch (...)
    {
        clearing = false;
        throw;
    }
    object_handles.clear();
    extended_object_handles.clear();
    extended_object_count = 0;
    next_object_handle = 0;
    max_occupied_object_handle = controlled_object_handle = UINT32_MAX;
    clearing = false;
}

ExtendedWorldObject *WorldObjects::linkModel(std::uint32_t parentHandle, std::string_view name, std::uint32_t slot)
{
    auto *parent = extendedObject(parentHandle);
    if (!parent || slot >= 5)
    {
        WorldDiagnostics::warning("Wrong handle: Link_object_to_object");
        return nullptr;
    }
    if (parent->linked_objects[slot])
        unlink(parentHandle, slot);
    const auto childHandle = create(name, 0, 0, true);
    if (childHandle == UINT32_MAX)
        return nullptr;
    auto *child = extendedObject(childHandle);
    parent = extendedObject(parentHandle);
    if (!parent || !child)
    {
        if (child)
            destroy(childHandle);
        return nullptr;
    }
    parent->linked_objects[slot] = childHandle;
    child->parent_object_handle = parentHandle;
    child->parent_link_slot = slot;
    return child;
}

SferaMbcProcessRecord *WorldObjects::boundProcess(const WorldObject &object)
{
    const auto *extended = object.extended();
    return extended == nullptr ? nullptr : static_cast<SferaMbcProcessRecord *>(extended->user_context);
}

void SphereRenderModelPose::poseWarning(std::string_view message)
{
    WorldDiagnostics::message.clear();
    WorldDiagnostics::appendScriptContext(message);
    WorldDiagnostics::flushScriptContext();
}

ExtendedWorldObject *SphereRenderModelPose::queryObject(std::uint32_t handle, std::string_view operation)
{
    auto *object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr)
        SphereRenderModelPose::poseWarning((std::string(operation) + ": wrong handle"));
    return object;
}

int SphereRenderModelPose::animationLength(std::uint32_t handle, int animation)
{
    auto *object = queryObject(handle, "GetSubAnimLen");
    if (object == nullptr)
        return -1;
    if (object->render_cache_handle < 0)
        return SphereRenderSceneRenderer::characters->partAnimationLength(*object, animation);
    auto *model = g_sfera_world_objects.model(*object);
    if (model == nullptr || model->animation_lengths.size() == 0u)
    {
        SphereRenderModelPose::poseWarning("GetSubAnimLen: model has no animation");
        return -1;
    }
    if (animation < 0)
    {
        SphereRenderModelPose::poseWarning("GetSubAnimLen: negative subanimation number");
        return -1;
    }
    return std::cmp_less(animation, model->animation_lengths.size()) ? model->animation_lengths[animation] : -1;
}

int *SphereRenderModelPose::animation(std::uint32_t handle)
{
    auto *object = queryObject(handle, "GetAnimation");
    return object == nullptr ? nullptr : &object->animation;
}

int *SphereRenderModelPose::frame(std::uint32_t handle)
{
    auto *object = queryObject(handle, "GetFrame");
    return object == nullptr ? nullptr : &object->frame;
}

float *SphereRenderModelPose::interpolation(std::uint32_t handle)
{
    auto *object = queryObject(handle, "GetInterp");
    return object == nullptr ? nullptr : &object->interpolation;
}

int *SphereRenderModelPose::secondaryFrame(std::uint32_t handle)
{
    auto *object = queryObject(handle, "GetFrame2");
    return object == nullptr ? nullptr : &object->frame_secondary;
}

int *SphereRenderModelPose::secondaryAnimation(std::uint32_t handle)
{
    auto *object = queryObject(handle, "GetAnimation2");
    return object == nullptr ? nullptr : &object->animation_secondary;
}

SferaVec3F *SphereRenderModelPose::neckPosition(SferaVec3F &output)
{
    auto *object = g_sfera_world_objects.extendedObject(g_sfera_world_objects.controlled_object_handle);
    if (object == nullptr)
        WorldDiagnostics::fail("CalcCharacterNeck: wrong handle");
    if (object->render_cache_handle < 0)
    {
        output = SphereRenderSceneRenderer::characters->neckPosition(*object);
        return &output;
    }
    auto *model = g_sfera_world_objects.model(*object);
    if (model == nullptr)
        WorldDiagnostics::fail("CalcCharacterNeck: missing model");
    SphereRenderModelPose::active_model = model;
    SphereRenderModelPose::primary_frame = frameOffset(*model, object->animation, object->frame, false);
    SphereRenderModelPose::secondary_enabled = object->interpolation > 0.00001f ? 1u : 0u;
    if (SphereRenderModelPose::secondary_enabled)
    {
        SphereRenderModelPose::blend = object->interpolation;
        SphereRenderModelPose::secondary_frame = frameOffset(*model, object->animation_secondary, object->frame_secondary, true);
    }
    SphereRenderModelPose::current_frame = SferaMatrix4x4F::fromEuler(object->position, object->rotation);
    updateBone(SphereRenderModelPose::current_frame, model->root_bone);
    const auto &position = SphereRenderModelPose::attachment_102_position;
    output = {position.x, position.y, position.z};
    return &output;
}

bool SphereWorldWorldSpatialIndex::typesInteract(std::uint32_t combined_type)
{
    switch (combined_type)
    {
    case 7u:
    case 8u:
    case 9u:
    case 10u:
    case 11u:
    case 14u:
    case 21u:
    case 23u:
    case 24u:
    case 25u:
    case 28u:
    case 32u:
    case 35u:
    case 39u:
        return true;
    default:
        return false;
    }
}

void SphereWorldWorldSpatialIndex::bindTerrainCell(SphereWorldSpatialLeaf &leaf, int cell_x, int cell_z)
{
    const int tile_x = (cell_x + 120000) / 12 - 10000, tile_z = (cell_z + 120000) / 12 - 10000, local_x = (cell_x + 120000) % 12, local_z = (cell_z + 120000) % 12;
    int map_x = tile_x + 40, map_z = 39 - tile_z;
    if (map_x < 0 || map_x >= 80)
        map_x = 0;
    if (map_z < 0 || map_z >= 80)
        map_z = 0;
    const int map_index = map_x * 80 + map_z;
    const auto &record = TerrainAssets::map[map_index];
    leaf.terrain_key = record.region != nullptr ? map_index : -1;
    leaf.quarter = local_x / 6 + local_z / 6 * 2;
    leaf.group = local_x / 3 % 2 + local_z / 3 % 2 * 2;
    leaf.cell = local_x % 3 + local_z % 3 * 3;
    leaf.origin_x = SferaNumeric::real32(tile_x * 100);
    leaf.origin_z = SferaNumeric::real32(tile_z * 100);
    leaf.contains_landscape = true;
}

SferaVec3F SferaWorldView::terrainAnchor()
{
    return {g_sfera_terrain_renderer.patch_origin.x, g_sfera_terrain_renderer.patch_origin.y, g_sfera_terrain_renderer.patch_origin.z};
}

WorldObject *SferaSceneAccess::object(std::uint32_t handle, std::optional<std::string_view> operation)
{
    return g_sfera_world_objects.object(handle, operation);
}

ExtendedWorldObject *SferaSceneAccess::extendedObject(std::uint32_t handle)
{
    return g_sfera_world_objects.extendedObject(handle);
}

WorldObject *SferaSceneAccess::controlledObject()
{
    return g_sfera_world_objects.controlledObject();
}

WorldObject *SferaSceneAccess::cameraObject()
{
    return g_sfera_world_objects.object(cameraHandle());
}

std::uint32_t SferaSceneAccess::cameraHandle()
{
    return 1u;
}

bool SferaSceneAccess::vegetationVisible()
{
    const auto *controlled = g_sfera_world_objects.controlledObject();
    return controlled != nullptr && !(controlled->position.y > 1000.0f);
}

std::uint32_t SferaSceneAccess::controlledHandle()
{
    return g_sfera_world_objects.controlled_object_handle;
}

SphereRenderModel *SferaSceneAccess::model(const WorldObject &object)
{
    return g_sfera_world_objects.model(object);
}

std::size_t SferaSceneAccess::modelCount()
{
    return g_sfera_models.count();
}

SferaVec3F SferaSceneAccess::referencePosition()
{
    return g_sfera_world_objects.referencePosition();
}

void SferaSceneAccess::notifyContact(std::uint32_t subject, const WorldObject &obstacle, SphereRenderCollisionKind shape)
{
    if (shape == SphereRenderCollisionKind::AxisAlignedBounds && subject == g_sfera_world_objects.controlled_object_handle)
    {
        g_sfera_world_objects.activateTrap(obstacle);
    }
}

float SferaSceneAccess::fieldOfView(int width, int height)
{
    return SferaGameCameraPolicy::scene_field_of_view(width, height);
}
