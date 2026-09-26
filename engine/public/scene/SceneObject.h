#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <variant>

#include "math/Matrix.h"
#include "math/Vector.h"

class SphereRenderModel;
struct ExtendedWorldObject;
struct SferaActiveEffect;
struct WorldObject;
struct WorldObjectModelReference;

struct WorldObjectModelReference
{
    std::size_t id = 0u;
    mutable std::shared_ptr<SphereRenderModel> asset;
};

struct WorldObject
{
    std::uint64_t resource_lifetime = 0;
    virtual ~WorldObject();
    WorldObject() noexcept;
    WorldObject(const WorldObject &) = delete;
    WorldObject &operator=(const WorldObject &) = delete;
    virtual ExtendedWorldObject *extended() noexcept
    {
        return nullptr;
    }
    virtual const ExtendedWorldObject *extended() const noexcept
    {
        return nullptr;
    }
    bool ownsModel() const noexcept
    {
        return std::holds_alternative<std::unique_ptr<SphereRenderModel>>(model_source);
    }

    std::variant<WorldObjectModelReference, std::unique_ptr<SphereRenderModel>> model_source;
    SferaVec3F position{};
    SferaVec3F rotation{};
    uint32_t spatial_membership{};
    int32_t grid_min_x{};
    int32_t grid_max_x{};
    int32_t grid_min_y{};
    int32_t grid_max_y{};
    float render_fade{};
    uint32_t render_group{};
    SferaMatrix4x4F world_transform{};
    SferaVec3F bounds_minimum{};
    SferaVec3F bounds_maximum{};
    SferaVec3F bounds_corners[8]{};
    uint32_t visibility_mark{};
    uint32_t linked_objects[5]{};
    SferaActiveEffect *attached_effects[10]{};
    uint32_t lighting_color{};
    bool visible{};

  private:
    friend struct WorldObjectModelReference;
};


struct ExtendedWorldObject : WorldObject
{
    ExtendedWorldObject *extended() noexcept override
    {
        return this;
    }
    const ExtendedWorldObject *extended() const noexcept override
    {
        return this;
    }
    static constexpr std::size_t unregistered = std::numeric_limits<std::size_t>::max();
    std::size_t extended_object_index = unregistered;
    uint8_t motion_state{};
    bool render_enabled{};
    bool steep_slope{};
    int32_t render_cache_handle{};
    float scale{};
    SferaVec3F orientation_basis[3]{};
    int32_t animation{};
    int32_t frame{};
    float interpolation{};
    int32_t frame_secondary{};
    int32_t animation_secondary{};
    uint32_t parent_object_handle{};
    uint32_t parent_link_slot{};
    void *user_context{};
    SferaVec3F effect_frame_position_a{};
    SferaVec3F effect_frame_position_b{};
    SferaMatrix4x4F effect_frame_transform_a{};
    SferaMatrix4x4F effect_frame_transform_b{};
    SferaVec3F effect_frame_position_c{};
    SferaMatrix4x4F effect_frame_transform_c{};
    bool simulation_enabled{};
    bool full_rate_simulation{};
    bool gravity_enabled{};

    bool airborne{};
    SferaVec3F commanded_velocity{};
    SferaVec3F physical_velocity{};
    float angular_velocity{};

    bool movement_blocked{};
    bool avoidance_enabled{};

    SferaVec3F avoidance_direction{};
    float avoidance_depth{};
    SferaVec3F previous_spatial_position{};
    SferaVec3F previous_spatial_rotation{};
    SferaVec3F previous_basis_rotation{};
    SferaVec3F previous_bounds_position{};
    SferaVec3F previous_bounds_rotation{};
    std::uint32_t last_simulation_tick{};
};
