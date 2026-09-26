#pragma once

#include <array>
#include <cstdint>
#include <memory>

#include "render/Material.h"

class CD3D9Device;
struct SferaGraphicsRuntime;

struct SferaGraphicsRuntime
{
    static constexpr std::uint32_t minimum_field_of_view = 45u;
    static constexpr std::uint32_t maximum_field_of_view = 110u;
    static constexpr std::uint32_t default_field_of_view = 69u;

    bool auto_fog{};
    uint32_t reflection_quality{};
    std::uint32_t field_of_view_degrees = default_field_of_view;
    float minimum_lod_distance{};
    float lod_distance{};
    uint32_t grass_depth{};
    uint32_t display_depth_bits = 32u;

    float fog_distance;
    float saved_fog_distance;
    bool lods_enabled;
    bool hardware_cursor_enabled;
    float environment_factor;
    std::uint16_t base_microtexture_id;
    float view_scale;
    bool post_effects_enabled;
    int rebuild_percent;
    int display_width;
    int display_height;
    std::unique_ptr<CD3D9Device> d3d_runtime;
    std::array<WaterMaterial, 10> water_materials{};
    void initialize();
    void initializeWater();
};

extern SferaGraphicsRuntime g_sfera_graphics_runtime;
