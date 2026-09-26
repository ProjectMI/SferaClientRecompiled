#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "math/Vector.h"

struct SferaLightRecord;
struct SferaLightRuntime;

struct SferaLightRecord
{
    static constexpr float defaultRadius = 10.0f;
    SferaVec3F position;
    float color[4];
    float radius;
    SferaVec3F bounds_min;
    SferaVec3F bounds_max;
    float viewer_distance_squared;

    void update(const SferaVec3F &new_position, const float *new_color, float new_radius);
};

struct SferaLightRuntime
{
    SferaLightRecord render_candidates[30]{};

    std::vector<std::unique_ptr<SferaLightRecord>> handles;
    std::vector<SferaLightRecord *> visible_handles;
    std::array<bool, 31> active_lights{};
    std::array<std::uint32_t, 30> render_candidate_indices{};
    std::array<bool, 30> render_candidate_active{};
    std::size_t active_count = 0;
    std::size_t candidate_count = 0;

    SferaLightRecord *record(int handle) const
    {
        if (handle < 0 || handle >= handles.size())
            return nullptr;
        return handles[handle].get();
    }
    void setActive(std::uint32_t index, bool enabled, std::uint32_t sourceLine);
    void activateMask(std::uint32_t mask);
    void setDirectionalLight(const SferaVec3F &direction, const SferaVec3F &color);
    void invalidateActiveLights()
    {
        active_lights.fill(false);
        active_count = 0;
    }
    void disableActiveLights();
    int create(const SferaVec3F &position, const float *color, float radius);
    void write(int handle, const SferaVec3F &position, const float *color, float radius);
    void release(int handle);
};
extern SferaLightRuntime g_sfera_light_runtime;
