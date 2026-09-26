#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <format>
#include <string>
#include <string_view>
#include <utility>

#include "environment/Environment.h"
#include "application/ClientApplication.h"
#include "camera/Camera.h"
#include "collision/Collision.h"
#include "gameplay/ActorMotion.h"
#include "geometry/Geometry.h"
#include "input/Cursors.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "render/Model.h"
#include "render/SceneRenderer.h"
#include "resources/TerrainResources.h"
#include "scene/SceneObject.h"
#include "script/MbcRuntime.h"
#include "spatial/SpatialIndex.h"
#include "text/Text.h"
#include "vegetation/Vegetation.h"
#include "world/WorldObjects.h"

SferaVec3F SphereWorldMotion::motionSurfaceNormal()
{
    return {g_sfera_contacts.support_normal.x, g_sfera_contacts.support_normal.y, g_sfera_contacts.support_normal.z};
}

SphereRenderModel *SphereWorldMotion::motionModel(const WorldObject &object)
{
    return g_sfera_world_objects.model(object);
}

SferaVec3F SphereWorldMotion::motionContact(std::size_t index)
{
    const auto &normals = g_sfera_contacts.normals();
    return index < normals.size() ? normals[index] : SferaVec3F{};
}

float SphereWorldMotion::motionMaterialScale()
{
    return g_sfera_motion.material_scale[g_sfera_contacts.surface_material];
}

bool SphereWorldMotion::motionHazardBand(float height)
{
    for (int lower = -745; lower <= 505; lower += 250)
    {
        if (height > lower && height < (lower + 5))
            return true;
    }
    return false;
}


void SphereWorldMotion::initializeResponseCurve()
{
    constexpr double speed_step = 0.01f;
    constexpr double integration_step = 0.005f;
    for (float speed = 0.0f; speed < 14.0f; speed = SferaNumeric::real32(speed + speed_step))
    {
        float velocity = -speed;
        float distance = 0.0f;
        float previous_distance;
        do
        {
            previous_distance = distance;
            distance = SferaNumeric::real32(distance + (velocity * integration_step + 0.000122499996908009));
            velocity = SferaNumeric::real32(velocity + 0.04899999985843895);
        } while (distance < previous_distance);
        const int index = SferaNumeric::truncateInt(std::trunc(-previous_distance * 10.0));
        if (index >= 0 && index < 100)
            g_sfera_motion.response_curve[index] = -speed;
    }
}

float SphereWorldMotion::responseValue(int index) const noexcept
{
    return index >= 0 && index < 100 ? g_sfera_motion.response_curve[index] : 0.0f;
}

bool SphereWorldMotion::snapSmallComponents(SferaVec3F &value) noexcept
{
    if (std::fabs(value.x) < 0.0001f)
        value.x = 0.0f;
    if (std::fabs(value.y) < 0.0001f)
        value.y = 0.0f;
    if (std::fabs(value.z) < 0.0001f)
        value.z = 0.0f;
    return value.x == 0.0f && value.y == 0.0f && value.z == 0.0f;
}

std::uint32_t SphereWorldMotion::probe(std::uint32_t handle, SferaVec3F step_displacement, float yaw)
{
    auto *object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr)
        return 2u;
    const auto *model = SphereWorldMotion::motionModel(*object);
    if (model == nullptr)
        return 2u;
    const auto steps = SferaNumeric::truncateInt((step_displacement).length<double, double, true>() / model->minimum_size) + 1;
    step_displacement = ((step_displacement) * (1.0f / steps));
    for (int step = 0; step < steps; ++step)
    {
        const auto position = object->position;
        const float rotation = object->rotation.x;
        object->position = ((object->position) + (step_displacement));
        const double precise_rotation = rotation;
        object->rotation.x = SferaNumeric::real32(precise_rotation + yaw);
        if (g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Movement, true) != 0u)
        {
            object->position = position;
            object->rotation.x = rotation;
            return 2u;
        }
    }
    return 0u;
}

std::uint32_t SphereWorldMotion::probeGround(std::uint32_t handle, SferaVec3F step_displacement, float yaw, bool controlled)
{
    auto *object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr)
        return 2u;
    const auto *model = SphereWorldMotion::motionModel(*object);
    if (model == nullptr)
        return 2u;
    const auto steps = SferaNumeric::truncateInt((step_displacement).length<double, double, true>() / model->minimum_size) + 1;
    step_displacement = ((step_displacement) * (1.0f / steps));
    bool obstructed = false;
    SferaVec3F before_step = object->position;
    float before_yaw = object->rotation.x;
    for (int step = 0; step < steps; ++step)
    {
        before_step = object->position;
        before_yaw = object->rotation.x;
        const double precise_x = object->position.x;
        const double precise_z = object->position.z;
        const double precise_rotation = object->rotation.x;
        object->position.x = SferaNumeric::real32(precise_x + step_displacement.x);
        object->position.z = SferaNumeric::real32(precise_z + step_displacement.z);
        object->rotation.x = SferaNumeric::real32(precise_rotation + yaw);
        if (g_sfera_contacts.test(handle, controlled ? SphereWorldContactQueryMode::Normals : SphereWorldContactQueryMode::Movement, true) != 0u)
        {
            obstructed = true;
            break;
        }
    }
    if (obstructed)
    {
        const double half_step = (object->render_group == 4u || object->render_group == 5u ? 0.05f : 0.4f) * 0.5;
        object->position.y = SferaNumeric::real32(object->position.y - half_step);
        if (g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Movement, true) != 0u)
        {
            object->position.y = SferaNumeric::real32(object->position.y - half_step);
            if (g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Movement, true) != 0u)
            {
                object->position = before_step;
                object->rotation.x = before_yaw;
                return 2u;
            }
        }
    }
    else
    {
        const auto position = object->position;
        object->position.y = SferaNumeric::real32(position.y + motionNearSupportOffset);
        const auto near_support = g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Movement, true);
        object->position = position;
        if (near_support != 0u)
            return 0u;
        object->position.y = SferaNumeric::real32(position.y + motionFarSupportOffset);
        const auto far_support = g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Movement, true);
        object->position = position;
        if (far_support == 0u)
        {
            object->physical_velocity.y = 0.0f;
            object->airborne = true;
            return 1u;
        }
    }
    float descent = model->minimum_size;
    do
    {
        descent = SferaNumeric::real32(descent * 0.25);
        float previous_y;
        do
        {
            previous_y = object->position.y;
            const double precise_y = previous_y;
            object->position.y = SferaNumeric::real32(precise_y + descent);
        } while (g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Movement, true) == 0u);
        object->position.y = previous_y;
    } while (descent >= 0.03f);
    return 0u;
}

bool SphereWorldMotion::avoidContact(std::uint32_t handle, SferaVec3F attempted_displacement, float yaw, bool grounded)
{
    auto *object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr)
        return false;
    object->avoidance_enabled = true;
    object->avoidance_direction = SphereWorldMotion::motionContact(0);
    object->avoidance_depth = g_sfera_contacts.obstacle_height;
    if (g_sfera_contacts.normals().size() == 1u && !(std::fabs(object->avoidance_direction.y) > 0.99f))
    {
        const auto away = ((SferaVec3F{object->avoidance_direction.x, 0.0f, object->avoidance_direction.z}.normalized()) * (-1.0));
        const auto tangent = (SphereWorldMotion::motionPlanarSlide(away, (attempted_displacement).normalized())).normalized();
        const float random = std::rand() / 32767.0f;
        const float deviation = SferaNumeric::real32(random < 0.8f ? random * 0.125f : (random - motionDeviationThreshold) * 5.0f);
        const auto offset = ((away) * (deviation));
        object->avoidance_direction = SferaVec3F{tangent.x - offset.x, 0.0f, tangent.z - offset.z}.normalized();
        if (grounded && snapSmallComponents(object->avoidance_direction))
            return false;
        const auto result = grounded ? probeGround(handle, object->avoidance_direction, yaw) : probe(handle, object->avoidance_direction, yaw);
        if (result != 2u)
            return false;
        auto fallback = away;
        const auto fallback_result = grounded && snapSmallComponents(fallback) ? 0u : grounded ? probeGround(handle, fallback, yaw) : probe(handle, fallback, yaw);
        if (fallback_result != 2u)
        {
            object->avoidance_direction = fallback;
            return false;
        }
    }
    const float random_x = SferaNumeric::real32((std::rand() / 32767.0) * 2.0 - 1.0);
    const float random_z = SferaNumeric::real32((std::rand() / 32767.0) * 2.0 - 1.0);
    object->avoidance_direction = SferaVec3F{random_x, 0.0f, random_z}.normalized();
    return false;
}

void SphereWorldMotion::moveFree(std::uint32_t handle, bool vertical, float yaw, float elapsed, bool controlled)
{
    auto *object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr)
        return;
    auto movement = ((((object->physical_velocity) + (object->commanded_velocity))) * (elapsed));
    if (!vertical)
        movement.y = 0.0f;
    if (controlled)
    {
        g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Material, true);
        movement = ((movement) * (SphereWorldMotion::motionMaterialScale()));
    }
    if (probe(handle, movement, yaw) == 0u)
        return;
    object->movement_blocked = true;
    object->physical_velocity.x = object->physical_velocity.z = object->angular_velocity = 0.0f;
    if (vertical)
        object->physical_velocity.y = 0.0f;
    if (!controlled)
        avoidContact(handle, movement, yaw, false);
}

void SphereWorldMotion::fall(std::uint32_t handle, float elapsed, bool controlled)
{
    auto *object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr)
        return;
    const auto *model = SphereWorldMotion::motionModel(*object);
    if (model == nullptr)
        return;
    const double precise_elapsed = elapsed;
    const float distance = SferaNumeric::real32(object->physical_velocity.y * precise_elapsed + precise_elapsed * elapsed * motionGravity * 0.5);
    object->physical_velocity.y = SferaNumeric::real32(precise_elapsed * motionGravity + object->physical_velocity.y);
    if (object->physical_velocity.y > 30.0f)
        object->physical_velocity.y = 30.0f;
    if (std::fabs(distance) < 0.003f)
        return;
    const double minimum_step = model->minimum_size;
    const auto steps = SferaNumeric::truncateInt(std::fabs(distance) / minimum_step) + 1;
    const double precise_distance = distance;
    float step_distance = SferaNumeric::real32(precise_distance / steps);
    bool blocked = false;
    bool crossed_hazard = false;
    float previous_y = object->position.y;
    for (int step = 0; step < steps; ++step)
    {
        previous_y = object->position.y;
        const double precise_y = previous_y;
        object->position.y = SferaNumeric::real32(precise_y + step_distance);
        if (g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Movement, true) != 0u)
        {
            blocked = true;
            break;
        }
        if (controlled && WorldObjects::boundProcess(*object) != nullptr && SphereWorldMotion::motionHazardBand(object->position.y))
            crossed_hazard = true;
    }
    if (!blocked)
    {
        if (WorldObjects::boundProcess(*object) != nullptr && (controlled ? crossed_hazard : SphereWorldMotion::motionHazardBand(object->position.y)))
        {
            if (controlled)
                object->physical_velocity.y = 0.0f;
            g_sfera_world_objects.appendCommand(handle, "phKILL 1");
            object = g_sfera_world_objects.extendedObject(handle);
            if (object == nullptr)
                return;
        }
        if (object->position.y > 8000.0f)
        {
            object->position = {(std::rand() * 6.0f / 32767.0f + 77.0f) - 3.0f, 160.0f, (std::rand() * 6.0f / 32767.0f + 95.0f) - 3.0f};
            object->physical_velocity.y = 0.0f;
        }
        return;
    }
    object->position.y = previous_y;
    while (std::fabs(step_distance) >= 0.03f)
    {
        step_distance = SferaNumeric::real32(step_distance * 0.25);
        for (;;)
        {
            previous_y = object->position.y;
            const double precise_y = previous_y;
            object->position.y = SferaNumeric::real32(precise_y + step_distance);
            if (previous_y == object->position.y || g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Support, true) != 0u)
                break;
        }
        object->position.y = previous_y;
    }
    if (!(object->physical_velocity.y > 0.0f))
    {
        object->physical_velocity.y = 0.0f;
        return;
    }
    if (WorldObjects::boundProcess(*object) != nullptr && object->physical_velocity.y > (controlled ? 1.0f : 7.0f))
    {
        std::string command;
        command = std::format("phDMG {:5.1f}", object->physical_velocity.y);
        g_sfera_world_objects.appendCommand(handle, command);
        object = g_sfera_world_objects.extendedObject(handle);
        if (object == nullptr)
            return;
    }
    object->airborne = false;
    const float speed = std::fabs(object->physical_velocity.y);
    const auto normal = SphereWorldMotion::motionSurfaceNormal();
    const double precise_speed = speed;
    object->physical_velocity.x = SferaNumeric::real32(object->physical_velocity.x * motionDamping + std::fabs(normal.y) * (precise_speed * normal.x) * 0.6f);
    object->physical_velocity.z = SferaNumeric::real32(object->physical_velocity.z * motionDamping + precise_speed * normal.z * std::fabs(normal.y) * 0.6f);
    object->angular_velocity = SferaNumeric::real32((0.5 - std::rand() * 0.000030517578125) * object->physical_velocity.y * 0.2f);
    object->physical_velocity.y = 0.0f;
}

bool SphereWorldMotion::slideControlled(std::uint32_t handle, const SferaVec3F &attempted_displacement)
{
    for (const float clearance : {0.0001f, 0.02f})
    {
        for (std::uint32_t index = 0; index < g_sfera_contacts.normals().size(); ++index)
        {
            const auto contact = SphereWorldMotion::motionContact(index);
            if (std::fabs(contact.y) > 0.99f)
                continue;
            const auto away = ((SferaVec3F{contact.x, 0.0f, contact.z}.normalized(clearance == 0.0001f ? 13 : 14)) * (-1.0));
            auto slide = SphereWorldMotion::motionPlanarSlide(away, attempted_displacement);
            const auto offset = ((away) * (clearance));
            slide = {slide.x - offset.x, 0.0f, slide.z - offset.z};
            const auto result = probeGround(handle, slide, 0.0f, true);
            if (result == 1u)
                return true;
            if (result == 0u)
                break;
        }
    }
    return false;
}

void SphereWorldMotion::dampMotion(std::uint32_t handle, float elapsed, bool controlled)
{
    auto *object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr)
        return;
    const float height = object->position.y;
    object->position.y = SferaNumeric::real32(height + motionGroundLift);
    g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Support, true);
    object->position.y = height;
    const auto normal = SphereWorldMotion::motionSurfaceNormal();
    if (std::fabs(normal.y) < 0.766f)
    {
        const double precise_normal_y = std::fabs(normal.y);
        const float angle = SferaNumeric::real32(std::acos(precise_normal_y));
        const double precise_angle = angle;
        const float sine = SferaNumeric::real32(std::sin(precise_angle));
        const float slope_acceleration = SferaNumeric::real32(sine * 4.0);
        const auto downhill = ((SferaVec3F{normal.x, 0.0f, normal.z}.normalized()) * (slope_acceleration));
        object->physical_velocity = ((object->physical_velocity) + (((downhill) * (elapsed))));
    }
    const auto direction = controlled ? g_sfera_contacts.support_direction : 0u;
    const float friction = g_sfera_motion.surface_friction[direction];
    const double precise_elapsed = elapsed;
    const float reduction = SferaNumeric::real32(precise_elapsed * friction);
    if (controlled && direction >= 4u)
        object->steep_slope = false;
    const float speed = SferaVec3F{object->physical_velocity.x, 0.0f, object->physical_velocity.z}.length<double, double, true>();
    if (speed > reduction && speed > 0.0001f)
    {
        const double precise_reduction = reduction;
        const double precise_speed = speed;
        const double remaining = speed - precise_reduction;
        object->physical_velocity.x = SferaNumeric::real32(object->physical_velocity.x / precise_speed * remaining);
        object->physical_velocity.z = SferaNumeric::real32(object->physical_velocity.z / precise_speed * remaining);
    }
    else
        object->physical_velocity.x = object->physical_velocity.z = 0.0f;
    const float exponent = SferaNumeric::real32(friction * 10.0 * elapsed);
    const double precise_exponent = exponent;
    const float angular_scale = SferaNumeric::real32(std::pow(motionAngularDamping, precise_exponent));
    const double precise_angular_scale = angular_scale;
    object->angular_velocity = SferaNumeric::real32(precise_angular_scale * object->angular_velocity);
    if (std::fabs(object->angular_velocity) < 0.0001f)
        object->angular_velocity = 0.0f;
}

void SphereWorldMotion::moveGround(std::uint32_t handle, float yaw, float elapsed, bool controlled)
{
    auto *object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr)
        return;
    const auto commanded = (SferaVec3F{object->commanded_velocity.x, 0.0f, object->commanded_velocity.z} * (elapsed));
    const auto physical = (SferaVec3F{object->physical_velocity.x, 0.0f, object->physical_velocity.z} * (elapsed));
    const auto overlap = g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Movement, true, false);
    if (overlap > 1u)
    {
        const auto *other = g_sfera_world_objects.object(overlap);
        if (other != nullptr)
        {
            auto separation = SferaVec3F{object->position.x - other->position.x, 0.0f, object->position.z - other->position.z}.normalized();
            if (separation.x == 0.0f && separation.y == 0.0f && separation.z == 0.0f)
                separation.x = controlled ? 2.0f : 1.0f;
            object->physical_velocity = ((separation) * (2.0));
        }
    }
    g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Material, true);
    const float height = object->position.y;
    object->position.y = SferaNumeric::real32(height + motionGroundLift);
    g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Support, true);
    object->position.y = height;
    const float slope = std::fabs(SphereWorldMotion::motionSurfaceNormal().y);
    auto ground_displacement = ((((((commanded) * (slope))) + (physical))) * (SphereWorldMotion::motionMaterialScale()));
    object->steep_slope = slope < 0.7f;
    if (controlled || !snapSmallComponents(ground_displacement))
    {
        const auto result = probeGround(handle, ground_displacement, yaw, controlled);
        if (result == 1u)
            return;
        if (result == 2u)
        {
            object->movement_blocked = true;
            object->physical_velocity.x = object->physical_velocity.z = object->angular_velocity = 0.0f;
            if (controlled ? slideControlled(handle, ground_displacement) : avoidContact(handle, ground_displacement, yaw, true))
                return;
        }
    }
    dampMotion(handle, elapsed, controlled);
}

void SphereWorldMotion::updateObjects(float elapsed)
{
    g_sfera_vegetation.map_update_phase ^= 1u;
    const auto object_count = g_sfera_world_objects.extended_object_count;
    std::size_t visited = 0u;
    for (std::size_t slot = 0u; slot < g_sfera_world_objects.extended_object_handles.size() && visited < object_count; ++slot)
    {
        const auto handle = g_sfera_world_objects.extended_object_handles[slot];
        if (handle == 0u)
            continue;
        ++visited;
        auto *object = g_sfera_world_objects.extendedObject(handle);
        if (object == nullptr || !object->simulation_enabled || !object->render_enabled || object->parent_object_handle != 0u)
            continue;
        if (!object->full_rate_simulation && g_sfera_vegetation.map_update_phase == 0u)
            continue;
        if (WorldObjects::boundProcess(*object) != nullptr && !g_sfera_world_objects.actorActive(handle) && g_sfera_mbc_runtime.simulation_tick - object->last_simulation_tick > 120u)
            continue;
        const float interval = object->full_rate_simulation ? elapsed : elapsed * 2.0f;
        const double precise_interval = interval;
        const float yaw = SferaNumeric::real32(object->angular_velocity * precise_interval);
        const auto velocity = ((object->physical_velocity) + (object->commanded_velocity));
        if (object->motion_state == 1u && yaw == 0.0f && velocity.x == 0.0f && velocity.y == 0.0f && velocity.z == 0.0f)
            continue;
        if (!object->gravity_enabled)
            moveFree(handle, true, yaw, interval, false);
        else if (!object->airborne)
            moveGround(handle, yaw, interval, false);
        else
        {
            moveFree(handle, false, yaw, interval, false);
            if (g_sfera_world_objects.extendedObject(handle) != nullptr)
                fall(handle, interval, false);
        }
    }
}

void SphereWorldMotion::updateControlled(float elapsed)
{
    const auto handle = g_sfera_world_objects.controlled_object_handle;
    if (handle == UINT32_MAX)
        return;
    auto *object = g_sfera_world_objects.extendedObject(handle);
    if (object == nullptr)
        return;
    const double precise_elapsed = elapsed;
    float yaw = SferaNumeric::real32(object->angular_velocity * precise_elapsed);
    if (yaw != 0.0f)
    {
        const double precise_rotation = object->rotation.x;
        object->rotation.x = SferaNumeric::real32(precise_rotation + yaw);
        yaw = 0.0f;
    }
    if (g_sfera_motion.tracking_position_pending == 1u)
    {
        g_sfera_motion.tracked_position.x = SferaNumeric::real32(g_sfera_motion.tracked_position.x - 333.0);
        g_sfera_motion.tracked_position.y = SferaNumeric::real32(g_sfera_motion.tracked_position.y - 333.0);
        g_sfera_motion.tracked_position.z = SferaNumeric::real32(g_sfera_motion.tracked_position.z - 333.0);
        const SferaVec3F camera{g_sfera_motion.tracked_position.x, g_sfera_motion.tracked_position.y, g_sfera_motion.tracked_position.z};
        const auto delta = ((camera) - (object->position));
        if (std::fabs(delta.x) > 0.5f || std::fabs(delta.y) > 0.5f || std::fabs(delta.z) > 0.5f)
        {
            g_sfera_motion.moved_since_query = 1u;
            object->position = camera;
        }
    }
    g_sfera_contacts.test(handle, SphereWorldContactQueryMode::CollectIgnored, false);
    if (!object->gravity_enabled)
        moveFree(handle, true, yaw, elapsed, true);
    else if (!object->airborne)
        moveGround(handle, yaw, elapsed, true);
    else
    {
        moveFree(handle, false, yaw, elapsed, true);
        if (g_sfera_world_objects.extendedObject(handle) != nullptr)
            fall(handle, elapsed, true);
    }
    object = g_sfera_world_objects.extendedObject(handle);
    if (object != nullptr)
    {
        g_sfera_motion.tracking_position_pending = 1u;
        g_sfera_motion.tracked_position.x = SferaNumeric::real32(object->position.x + 333.0);
        g_sfera_motion.tracked_position.y = SferaNumeric::real32(object->position.y + 333.0);
        g_sfera_motion.tracked_position.z = SferaNumeric::real32(object->position.z + 333.0);
    }
}

void SphereWorldMotion::updateOrientation()
{
    auto *object = g_sfera_world_objects.extendedObject(0u);
    if (object == nullptr)
        return;
    const auto lateral = ((object->orientation_basis[2]) * (g_sfera_motion.acceleration.x));
    const auto forward = ((object->orientation_basis[0]) * (g_sfera_motion.acceleration.z));
    object->commanded_velocity = ((((forward) + (lateral))) * (192.0));
    object->physical_velocity = {};
    g_sfera_contacts.test(0u, SphereWorldContactQueryMode::CollectIgnored, false);
    moveFree(0u, true, 0.0f, 0.0052083334885537624f, true);
    g_sfera_world_objects.rotate(0u, {g_sfera_motion.displacement.x, g_sfera_motion.displacement.y, 0.0f});
    g_sfera_world_objects.alignReferenceOrientation();
}

std::uint32_t SphereWorldMotion::surfaceInteraction(std::uint32_t handle, std::uint32_t *material)
{
    auto *object = g_sfera_world_objects.object(handle);
    const auto *reference = g_sfera_world_objects.object(1u);
    if (object == nullptr || reference == nullptr || (((object->position) - (reference->position))).length<double, double, true>() > 15.0f)
        return 0u;
    SphereWorldContactQuery::updateBounds(handle);
    const int x_units = SferaNumeric::truncateInt(object->position.x * motionGridScale + 100000.0) + 20000;
    const int z_units = SferaNumeric::truncateInt(object->position.z * motionGridScale + 100000.0) + 20000;
    const int patch_x = x_units / 12 - 10000;
    const int patch_z = z_units / 12 - 10000;
    const int map_x = patch_x + 40;
    const int map_z = 39 - patch_z;
    if (map_x < 0 || map_x >= 80 || map_z < 0 || map_z >= 80)
        return 0u;
    const std::size_t map_index = map_x * 80 + map_z;
    auto *region = TerrainAssets::map[map_index].region;
    const auto &tile = TerrainAssets::map[map_index];
    if (region == nullptr)
        return 0u;
    region->touchPatch(tile.tile_x, tile.tile_y);
    const auto *patch = region->patch(tile.tile_x, tile.tile_y);
    if (patch == nullptr)
        return 0u;
    const int local_x = x_units % 12;
    const int local_z = z_units % 12;
    const int cell_index = ((local_x / 6 + 2 * (local_z / 6)) * 4 + 2 * ((local_z / 3) % 2) + (local_x / 3) % 2 - local_z / 3) * 3 - local_x / 3 + local_z;
    const auto &cell = patch->cells[local_x + cell_index * 3];
    const auto &water = patch->waters[cell.x + 12 * cell.z];
    if (material != nullptr)
        *material = UINT32_MAX;
    if (water.material != 0u && !(water.height > object->bounds_maximum.y))
    {
        if (material != nullptr)
            *material = SferaNumeric::lowWord(water.material);
        const double feet = object->bounds_minimum.y - 0.25;
        if (water.height > feet)
            return 4u;
        if (water.height + 30.0 > feet)
            return 5u;
    }
    g_sfera_contacts.clearIgnoredObjects();
    const auto position = object->position;
    object->position.y = SferaNumeric::real32(position.y + motionProbeLift);
    const auto contact = g_sfera_contacts.test(handle, SphereWorldContactQueryMode::Movement, false);
    object->position = position;
    if (contact == 0u)
        return 0u;
    if (contact > 1u)
    {
        const auto *other = g_sfera_world_objects.object(contact);
        const auto *model = other == nullptr ? nullptr : SphereWorldMotion::motionModel(*other);
        return model != nullptr && SferaText::compareInsensitive(std::string_view(model->name).substr(0, 4), "tree") == 0 ? 6u : 3u;
    }
    const float relative_x = SferaNumeric::real32(position.x - patch_x * 100.0);
    const float relative_z = SferaNumeric::real32(position.z - patch_z * 100.0);
    const int texture_x = SferaNumeric::truncateInt(relative_x / 100.0 * 254.0 + 1.0);
    const int texture_z = SferaNumeric::truncateInt(relative_z / 100.0 * 254.0 + 1.0);
    const auto &texture = region->slots[tile.tile_x * 10 + tile.tile_y].texture->pixels;
    for (int row = texture_z - 2; row <= texture_z + 2; ++row)
    {
        for (int column = texture_x - 2; column <= texture_x + 2; ++column)
        {
            const auto pixel = texture[std::clamp(row, 0, 255) * 256 + std::clamp(column, 0, 255)];
            const auto green = ((pixel >> 6u) & 31u) * 100u / 105u;
            if ((pixel & 31u) >= green || std::cmp_greater(pixel >> 11u, green))
                return 2u;
        }
    }
    return 1u;
}

auto SphereWorldMotion::transformPickPoint(const SphereRenderModel *model, const WorldObject *object, const SferaVec3F &point)
{
    return model->bounds_transform.inverseTransformPoint(object->world_transform.inverseTransformPoint(point));
}

std::uint32_t SphereWorldMotion::pick(float *distance, SferaVec3F *direction)
{
    if (!SferaClientApplication::resources_loaded)
        return UINT32_MAX;
    auto *cursor = CCursorManager::instance().activeCursor();
    if (cursor == nullptr)
        return UINT32_MAX;
    SferaCursorPosition cursor_position{};
    cursor->getPosition(&cursor_position);
    const auto &points = g_sfera_camera.frame_corners;
    const double display_width = g_sfera_graphics_runtime.display_width;
    const double display_height = g_sfera_graphics_runtime.display_height;
    const float horizontal = SferaNumeric::real32(cursor_position.x / display_width);
    const float vertical = SferaNumeric::real32(cursor_position.y / display_height);
    const auto cursor_plane = ((points[1]) + (((((((points[2]) - (points[1]))) * (horizontal))) + (((((points[4]) - (points[1]))) * (vertical))))));
    const auto ray = (((cursor_plane) - (points[0]))).normalized();
    if (ray.x == 0.0f && ray.y == 0.0f && ray.z == 0.0f)
        return UINT32_MAX;
    if (direction != nullptr)
        *direction = ray;
    const float range = std::min(SphereRenderSceneRenderer::environment.fogParameters.z * motionPickRangeScale, 50.0f);
    const auto ray_end = ((points[0]) + (((ray) * (range))));
    auto ray_edge = ray_end;
    ray_edge.y = SferaNumeric::real32(ray_edge.y + motionPickEdgeLift);
    const auto *reference = g_sfera_world_objects.object(1u);
    if (reference == nullptr)
        return UINT32_MAX;
    g_sfera_world_spatial.gatherObjects(reference->position, range);
    std::uint32_t selected = UINT32_MAX;
    float nearest = 1000000.0f;
    for (const auto handle : g_sfera_world_spatial.objects())
    {
        auto *object = g_sfera_world_objects.object(handle);
        if (object == nullptr || handle == 1u || handle == g_sfera_world_objects.controlled_object_handle || !object->visible)
            continue;
        if (object->extended() && !g_sfera_world_objects.extendedObject(handle)->render_enabled)
            continue;
        const auto *model = SphereWorldMotion::motionModel(*object);
        if (model == nullptr || model->collision_kind == SphereRenderCollisionKind::None)
            continue;
        SphereWorldContactQuery::updateBounds(handle);
        auto origin = points[0];
        auto end = ray_end;
        auto edge = ray_edge;
        auto minimum = object->bounds_minimum;
        auto maximum = object->bounds_maximum;
        if (model->collision_kind != SphereRenderCollisionKind::AxisAlignedBounds)
        {
            minimum = {};
            maximum = model->oriented_size;
            origin = transformPickPoint(model, object, origin);
            end = transformPickPoint(model, object, end);
            edge = transformPickPoint(model, object, edge);
        }
        g_sfera_contacts.query_bounds.minimum = {minimum.x, minimum.y, minimum.z};
        g_sfera_contacts.query_bounds.maximum = {maximum.x, maximum.y, maximum.z};
        if (!g_sfera_clipped_polygon.clipTriangleToBounds(origin, end, edge, minimum, maximum))
            continue;
        float candidate_distance = 1000000.0f;
        for (const auto &vertex : g_sfera_clipped_polygon.vertices)
            candidate_distance = std::min(candidate_distance, (((vertex) - (origin))).length<double, double, true>());
        if (!(nearest > candidate_distance))
            continue;
        if (model->collision_kind != SphereRenderCollisionKind::Triangles)
        {
            nearest = candidate_distance;
            selected = handle;
            continue;
        }
        origin = object->world_transform.inverseTransformPoint(points[0]);
        end = object->world_transform.inverseTransformPoint(ray_end);
        for (std::size_t group_index = 0; group_index < model->collision_groups.size(); ++group_index)
        {
            const auto &group = model->collision_groups[group_index];
            for (std::size_t index = 0; index < group.triangle_count; ++index)
            {
                const auto &triangle = model->collision_triangles[group.first_triangle + index];
                if ((triangle.collision_flags & 255u) != 0u)
                    continue;
                SferaVec3F hit{};
                if (SphereWorldContactQuery::intersectTriangle(origin, end, triangle, hit) != 2)
                    continue;
                const float hit_distance = (((hit) - (origin))).length<double, double, true>();
                if (nearest > hit_distance)
                {
                    nearest = hit_distance;
                    selected = handle;
                }
            }
        }
    }
    if (distance != nullptr)
        *distance = nearest;
    return selected;
}
