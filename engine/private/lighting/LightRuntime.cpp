#include <algorithm>
#include <cstdint>
#include <d3d9.h>
#include <iterator>
#include <memory>
#include <new>
#include <string>
#include <utility>

#include "diagnostics/Diagnostics.h"
#include "graphics/d3d9/Device.h"
#include "lighting/LightRuntime.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"

void SferaLightRuntime::disableActiveLights()
{
    for (std::uint32_t index = 1; index < active_lights.size(); ++index)
        setActive(index, false, __LINE__);
}

void SferaLightRuntime::setActive(std::uint32_t index, bool enabled, std::uint32_t sourceLine)
{
    if (index >= active_lights.size())
        SferaEngineDiagnostics::fail("Light slot is outside the device light table");
    auto &active = active_lights[index];
    if (active == enabled)
        return;
    if (enabled && active_count >= 8)
        SferaEngineDiagnostics::fail((std::string("ActivateLight: num of active lights > 8. Source line = ") + std::to_string(sourceLine)));
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    device.checkResult(device.native_device->LightEnable(index, enabled), "LightEnable");
    if (enabled && index != 0u)
        SferaEngineDiagnostics::lightActivated();
    active = enabled;
    if (enabled)
        ++active_count;
    else
        --active_count;
}

void SferaLightRuntime::activateMask(std::uint32_t mask)
{
    for (std::uint32_t index = 1u; index <= 30u; ++index)
        if ((mask & (1u << (index - 1u))) == 0u)
            setActive(index, false, 15290u);
    for (std::uint32_t index = 1u; index <= 30u; ++index)
        if ((mask & (1u << (index - 1u))) != 0u)
            setActive(index, true, 15290u);
}

void SferaLightRuntime::setDirectionalLight(const SferaVec3F &direction, const SferaVec3F &color)
{
    D3DLIGHT9 light{};
    light.Type = D3DLIGHT_DIRECTIONAL;
    light.Diffuse.r = SferaNumeric::real32(color.x / 255.0);
    light.Diffuse.g = SferaNumeric::real32(color.y / 255.0);
    light.Diffuse.b = SferaNumeric::real32(color.z / 255.0);
    light.Diffuse.a = 1.0f;
    light.Specular = {1.0f, 1.0f, 1.0f, 1.0f};
    light.Ambient.a = 1.0f;
    light.Direction = {direction.x, direction.y, direction.z};
    light.Falloff = 1.0f;
    light.Attenuation0 = 1.0f;
    light.Attenuation1 = 1.0f;
    light.Attenuation2 = 1.0f;
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    device.checkResult(device.native_device->SetLight(0u, &light), "SetLight");
    setActive(0u, true, 14675u);
}

void SferaLightRecord::update(const SferaVec3F &new_position, const float *new_color, float new_radius)
{
    position = new_position;
    std::copy_n(new_color, std::size(color), color);
    radius = new_radius == 0.0f ? defaultRadius : new_radius;
}

int SferaLightRuntime::create(const SferaVec3F &position, const float *color, float radius)
{
    if (color == nullptr)
        return -1;
    const auto slot = std::find(handles.begin(), handles.end(), nullptr);
    if (slot == handles.end())
        return -1;
    auto light = std::unique_ptr<SferaLightRecord>(new (std::nothrow) SferaLightRecord{});
    if (light == nullptr)
        return -1;
    light->update(position, color, radius);
    *slot = std::move(light);
    return SferaNumeric::signedWord(SferaNumeric::lowWord(slot - handles.begin()));
}

void SferaLightRuntime::write(int handle, const SferaVec3F &position, const float *color, float radius)
{
    auto *light = record(handle);
    if (light != nullptr && color != nullptr)
        light->update(position, color, radius);
}

void SferaLightRuntime::release(int handle)
{
    auto *light = record(handle);
    if (light == nullptr)
        return;
    if (std::find(visible_handles.begin(), visible_handles.end(), light) != visible_handles.end())
    {
        visible_handles.clear();
        candidate_count = 0;
    }
    handles[handle].reset();
}
