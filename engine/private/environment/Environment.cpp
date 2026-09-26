#include <windows.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <d3d9.h>
#include <iterator>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "camera/Camera.h"
#include "diagnostics/Diagnostics.h"
#include "graphics/d3d9/Device.h"
#include "environment/Environment.h"
#include "geometry/Geometry.h"
#include "math/Color.h"
#include "math/MathFunctions.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "render/SceneRenderer.h"
#include "render/TextureAccess.h"
#include "render/VertexFormats.h"
#include "text/Text.h"
#include "vegetation/Vegetation.h"

float EnvironmentZone::weight(float x, float z) const
{
    const double origin_x = originX, origin_z = originZ;
    const float left = SferaNumeric::real32(x - (origin_x + minimumX));
    if (left < 0.0f)
        return 0.0f;
    const float top = SferaNumeric::real32(z - (origin_z + minimumZ));
    if (top < 0.0f)
        return 0.0f;
    const float right = SferaNumeric::real32(origin_x + maximumX - x);
    if (right < 0.0f)
        return 0.0f;
    const float bottom = SferaNumeric::real32(origin_z + maximumZ - z);
    if (bottom < 0.0f)
        return 0.0f;
    const float distance = std::min(std::min(left, top), std::min(right, bottom));
    return borderFade <= distance ? 1.0f : distance / borderFade;
}

void EnvironmentZones::interval(double time, int &first, int &second, float &fraction)
{
    constexpr float positions[]{0.0f, 0.19f, 0.27f, 0.34f, 0.50f, 0.66f, 0.73f, 0.81f, 1.0f};
    first = second = 0;
    fraction = 0.0f;
    for (int index = 0; index < 8; ++index)
    {
        if (positions[index] <= time && positions[index + 1] >= time)
        {
            first = index;
            second = (index + 1) % 8;
            const double end = positions[index + 1];
            fraction = SferaNumeric::real32((time - positions[index]) / (end - positions[index]));
            return;
        }
    }
}

void EnvironmentZone::sample(int first, int second, float fraction, EnvironmentLighting &output) const
{
    output.fogParameters = fogParameters;
    output.fogColor = SferaMath::interpolate(fogColors[first], fogColors[second], fraction);
    output.ambientColor = SferaMath::interpolate(ambientColors[first], ambientColors[second], fraction);
    output.sunColor = SferaMath::interpolate(sunColors[first], sunColors[second], fraction);
}

void EnvironmentZones::calculate(bool useDefault, float x, float z, float time, const SkyEnvironment &sky, EnvironmentLighting &output)
{
    if (zones.empty())
    {
        SferaEngineDiagnostics::fatal("Error in ZoningMgr::calc_params() : zonesParams is Empty");
        return;
    }
    int first, second;
    float fraction;
    interval(time, first, second, fraction);
    SferaVec3F sun{}, ambient{};
    sky.lighting(time, sun, ambient);

    std::vector<std::pair<std::size_t, float>> influences;
    if (!useDefault)
        for (std::size_t index = 0; index < zones.size(); ++index)
        {
            const auto amount = zones[index].weight(x, z);
            if (amount >= 0.009999999776482582f)
            {
                influences.emplace_back(index, amount);
                if (amount > 0.9900000095367432f)
                    break;
            }
        }
    if (influences.empty())
    {
        sampleZone(first, second, fraction, sun, ambient, zones.size() - 1, output);
        return;
    }
    sampleZone(first, second, fraction, sun, ambient, influences.back().first, output);
    for (std::size_t index = influences.size() - 1; index > 0; --index)
    {
        EnvironmentLighting foreground{};
        const auto [zone, amount] = influences[index - 1];
        sampleZone(first, second, fraction, sun, ambient, zone, foreground);
        output.fogParameters = SferaMath::interpolate(output.fogParameters, foreground.fogParameters, amount);
        output.fogColor = SferaMath::interpolate(output.fogColor, foreground.fogColor, amount);
        output.ambientColor = SferaMath::interpolate(output.ambientColor, foreground.ambientColor, amount);
        output.sunColor = SferaMath::interpolate(output.sunColor, foreground.sunColor, amount);
    }
}

void EnvironmentZones::sampleZone(int first, int second, float fraction, const SferaVec3F &sun, const SferaVec3F &ambient, std::size_t index, EnvironmentLighting &target) const
{
    if (index + 1 != zones.size())
    {
        zones[index].sample(first, second, fraction, target);
        return;
    }
    auto background = zones[index];
    background.sunColors.fill(sun);
    background.ambientColors.fill(ambient);
    background.sample(first, second, fraction, target);
}

void SkyEnvironment::interval(double time, int &first, int &second, float &fraction) const
{
    second = 1;
    while (second < states.size() && states[second].time < time)
        ++second;
    if (second == states.size())
        SferaEngineDiagnostics::fail("n2 >= SKY_STATES_NUM");
    first = second - 1;
    const double end = states[second].time;
    fraction = SferaNumeric::real32((time - states[first].time) / (end - states[first].time));
}

void SkyEnvironment::sample(float time, SkyState &output) const
{
    int first, second;
    float fraction;
    interval(time, first, second, fraction);
    const auto &start = states[first];
    const auto &finish = states[second];

    interpolateGradient(output.primary, start.primary, finish.primary, fraction);
    output.reference = SferaMath::interpolate(start.reference, finish.reference, fraction);
    interpolateGradient(output.secondary, start.secondary, finish.secondary, fraction);
    output.sunPhase = SferaMath::interpolate(start.sunPhase, finish.sunPhase, fraction);
    output.sunColor = SferaMath::interpolate(start.sunColor, finish.sunColor, fraction);
    output.ambientColor = SferaMath::interpolate(start.ambientColor, finish.ambientColor, fraction);
}

void SkyEnvironment::interpolateGradient(std::span<SkyStateGradientKey> outputKeys, std::span<const SkyStateGradientKey> firstKeys, std::span<const SkyStateGradientKey> secondKeys, float fraction)
{
    for (std::size_t index = 0; index < outputKeys.size(); ++index)
    {
        outputKeys[index] = {SferaMath::interpolate(firstKeys[index].color, secondKeys[index].color, fraction),
                             SferaMath::interpolate(firstKeys[index].position, secondKeys[index].position, fraction)};
    }
}

void SkyEnvironment::sunDirection(float time, SferaVec3F &output) const
{
    int first, second;
    float fraction;
    interval(time, first, second, fraction);
    float phase = SferaMath::interpolate(states[first].sunPhase, states[second].sunPhase, fraction);
    const float sunrise = states[sunriseState].sunPhase;
    const float sunset = states[sunsetState].sunPhase;
    const double sunset_phase = sunset;
    if (!(phase > sunrise && phase < sunset))
    {
        float relative = phase - sunset;
        if (relative < 0.0f)
            relative += 1.0f;
        phase = SferaNumeric::real32(relative * (sunset_phase - sunrise) / (1.0 + sunrise - sunset) + sunrise);
    }
    const float angle = SferaNumeric::real32(phase * 3.1415929794311523 * 2.0);
    const auto [sine, cosine] = SferaMath::rotationTerms(angle);
    output.x = SferaNumeric::real32(-sine);
    output.y = SferaNumeric::real32(cosine);
    output.z = 0.0f;
}

void SkyEnvironment::lighting(float time, SferaVec3F &sun, SferaVec3F &ambient) const
{
    int first, second;
    float fraction;
    interval(time, first, second, fraction);
    sun = SferaMath::interpolate(states[first].sunColor, states[second].sunColor, fraction);
    ambient = SferaMath::interpolate(states[first].ambientColor, states[second].ambientColor, fraction);
}

std::uint32_t SceneSky::skyChannel(float value)
{
    return std::min(SferaNumeric::truncateInt(value), 255) & 255u;
}

template <std::size_t Count> SferaVec4F SceneSky::skyPeriodicSample(const std::array<SkyStateGradientKey, Count> &keys, double position)
{
    std::size_t first, second;
    float amount;
    if (position < keys[0].position)
    {
        first = Count - 1;
        second = 0;
        const float tail = SferaNumeric::real32(1.0 - keys[first].position);
        const double start = keys[0].position;
        amount = SferaNumeric::real32((position + tail) / (start + tail));
    }
    else if (position > keys[Count - 1].position)
    {
        first = Count - 1;
        second = 0;
        amount = SferaNumeric::real32((position - keys[first].position) / (1.0 + keys[0].position - keys[first].position));
    }
    else
    {
        second = 1;
        while (keys[second].position < position)
            ++second;
        first = second - 1;
        const double end = keys[second].position;
        amount = SferaNumeric::real32((position - keys[first].position) / (end - keys[first].position));
    }
    return SferaMath::interpolate(keys[first].color, keys[second].color, amount);
}

void SceneSky::skySubmit(std::size_t count)
{
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    device.checkResult(device.native_device->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0u, 120u, SferaNumeric::lowWord(count / 3u), SceneSky::indices, D3DFMT_INDEX16, SceneSky::vertices,
                                                                    sizeof(SferaScreenVertex)),
                       "DrawIndexedPrimitiveUP");
}

void SceneSky::rotateUv(double x, double y, double angle, float &u, float &v)
{
    const auto [sine, cosine] = SferaMath::rotationTerms(angle);
    const auto centerX = screen_center_x, centerY = screen_center_y;
    const double horizontal = x - centerX, vertical = y - centerY;
    u = SferaNumeric::real32((centerX + horizontal * cosine - vertical * sine) * 0.00390625 + texture_phase_u);
    v = SferaNumeric::real32((horizontal * sine + vertical * cosine + centerY) * 0.00390625 + texture_phase_v);
}

std::size_t SceneSky::buildLayerGeometry(const SceneSkyLayer &layer, double opacity)
{
    for (std::size_t index = 0; index < 120; ++index)
    {
        const double inclination = elevation_samples[index];
        const float alpha = SferaNumeric::real32(inclination < 1.059999942779541f    ? 255.0
                                                 : inclination > 1.4800000190734863f ? 0.0
                                                                                     : 255.0 - (inclination - 1.059999942779541) / (1.4800000190734863 - 1.059999942779541) * 255.0);
        const float faded = SferaNumeric::real32(alpha * opacity);
        const std::int64_t rounded_alpha = SferaNumeric::truncateInt64(std::nearbyint(faded));
        layer_alpha[index] = SferaNumeric::lowWord(rounded_alpha);
        const float sine = SferaNumeric::real32(std::sin(inclination));
        const float projection = SferaNumeric::real32(inclination * layer.projectionWarp);
        const double projected_angle = projection;
        const float cosine = SferaNumeric::real32(std::cos(projected_angle));
        const double numerator = sine;
        const float rounded_radius = SferaNumeric::real32(numerator / cosine * layer.uvScale);
        const double radius = rounded_radius;
        const auto [azimuth_sine, azimuth_cosine] = SferaMath::rotationTerms(azimuth_samples[index]);
        const float offsetX = layer.trackOffset ? cloud_offset_x : 0.0f;
        const float offsetY = layer.trackOffset ? cloud_offset_y : 0.0f;
        auto &vertex = vertices[index];
        vertex.u = SferaNumeric::real32(azimuth_cosine * radius + offsetX + 0.5);
        vertex.v = SferaNumeric::real32(azimuth_sine * radius + offsetY + 0.5);
    }
    std::size_t count = 0;
    for (std::uint16_t row = 0; row < 9; ++row)
    {
        for (std::uint16_t column = 0; column < 11; ++column)
        {
            const std::uint16_t index = row * 12 + column;
            if (sample_visible[index] || sample_visible[index + 1] || sample_visible[index + 12])
            {
                indices[count++] = index;
                indices[count++] = index + 1;
                indices[count++] = index + 12;
            }
            if (sample_visible[index + 1] || sample_visible[index + 12] || sample_visible[index + 13])
            {
                indices[count++] = index + 1;
                indices[count++] = index + 13;
                indices[count++] = index + 12;
            }
        }
    }
    return count;
}

void SceneSky::layerColor(const SceneSkyLayer &layer, SferaVec3F &output)
{
    int first;
    int second;
    float amount;
    SceneSky::environment->interval(g_sfera_graphics_runtime.environment_factor, first, second, amount);
    output = {SferaMath::interpolate(layer.colors[first].x, layer.colors[second].x, amount), SferaMath::interpolate(layer.colors[first].y, layer.colors[second].y, amount),
              SferaMath::interpolate(layer.colors[first].z, layer.colors[second].z, amount)};
}

void SceneSky::drawColorLayer(std::string_view texture, const SferaVec3F &color, std::size_t index_count)
{
    if (texture.empty())
        return;
    for (std::size_t index = 0; index < 120; ++index)
    {
        const float additional = SferaNumeric::real32(glow_samples[index] * 255.0);
        const auto illuminated = color + SferaVec3F{additional, additional, additional};
        auto &vertex = vertices[index];
        vertex.diffuse = SferaColor::rgba(SceneSky::skyChannel(illuminated.x), SceneSky::skyChannel(illuminated.y), SceneSky::skyChannel(illuminated.z), layer_alpha[index]).argb();
        vertex.specular = 0u;
    }
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_ONE);
    if (texture != "auto")
        SphereRenderSceneRenderer::bindTexture(SferaTextureAccess::find(texture));
    SceneSky::skySubmit(index_count);
    device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}

void SceneSky::drawMaskLayer(std::string_view texture, std::size_t index_count)
{
    if (texture.empty())
        return;
    for (std::size_t index = 0; index < 120; ++index)
    {
        const auto color = SceneSky::layer_alpha[index] & 255u;
        SceneSky::vertices[index].diffuse = D3DCOLOR_XRGB(color, color, color);
        SceneSky::vertices[index].specular = D3DCOLOR_ARGB(0, 255u - color, 255u - color, 255u - color);
    }
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    device.setAlphaBlending(D3DBLEND_ZERO, D3DBLEND_SRCCOLOR);
    device.checkResult(device.native_device->SetRenderState(D3DRS_SPECULARENABLE, TRUE), "SetRenderState");
    SphereRenderSceneRenderer::bindTexture(SferaTextureAccess::find(texture));
    SceneSky::skySubmit(index_count);
    device.checkResult(device.native_device->SetRenderState(D3DRS_SPECULARENABLE, FALSE), "SetRenderState");
    device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}

void SceneSky::drawLayers(const SceneSkyLayers &layers)
{
    if (layers.primary.texture.empty() && layers.secondary.texture.empty())
        return;
    const auto &source = layers.primary.texture.empty() ? layers.secondary : layers.primary;
    const auto index_count = buildLayerGeometry(source, layers.opacity);
    drawMaskLayer(layers.secondary.texture, index_count);
    if (!layers.primary.texture.empty())
    {
        SferaVec3F color;
        layerColor(layers.primary, color);
        drawColorLayer(layers.primary.texture, color, index_count);
    }
}

void SceneSky::orbit(float &x, float &y, std::uint32_t orbit)
{
    const int frequency = orbit + 1u;
    const float angle = SferaNumeric::real32(animation_phase * 3.1415929794311523 * 2.0 * frequency);
    const auto [sine, cosine] = SferaMath::rotationTerms(angle);
    const float offsetX = SferaNumeric::real32(cosine * 0.019999999552965164), offsetY = SferaNumeric::real32(sine * 0.019999999552965164);
    const double originalX = x, originalY = y;
    x = SferaNumeric::real32(originalX + offsetX);
    y = SferaNumeric::real32(originalY + offsetY);
}

float SceneSky::horizonFog(float elevation, double amount)
{
    const float position = SferaNumeric::real32(elevation < 0.0f ? 0.0 : elevation > 0.4000000059604645 ? 1.0 : elevation / 0.4000000059604645);
    return SferaNumeric::real32(position * amount);
}

void SceneSky::sampleDirection(bool refresh, const SferaVec3F &direction)
{
    if (SphereRenderSceneRenderer::interior_scene == 1u)
    {
        sample_color = 0u;
        return;
    }
    const double x = direction.x, y = direction.y, z = direction.z;
    const float azimuth = SferaNumeric::real32(std::atan2(z, x));
    const auto [sine, cosine] = SferaMath::rotationTerms(-azimuth);
    const float horizontal = SferaNumeric::real32(cosine * x - sine * z);
    const float elevation_angle = SferaNumeric::real32(std::atan2(y, horizontal));
    const float elevation = SferaNumeric::real32(elevation_angle + 1.5707964897155762);
    sample_azimuth = azimuth;
    sample_elevation = elevation;
    const float latitude = SferaNumeric::real32(elevation * 0.31830985316916194);
    const float longitude_angle = SferaNumeric::real32(std::atan2(y, x));
    float longitude = SferaNumeric::real32(longitude_angle - 1.5707964897155762);
    if (longitude < 0.0f)
        longitude += 6.283185958862305;
    longitude = SferaNumeric::real32(longitude * 0.15915492658458097);
    if (refresh)
    {
        const auto *source = SphereWorldVegetation::alternatePatterns() ? high_resolution_environment.get() : environment.get();
        source->sample(g_sfera_graphics_runtime.environment_factor, interpolated);
    }
    auto color = SceneSky::skyPeriodicSample(interpolated.primary, longitude);
    const float length = direction.length<double, float>();
    const float inverse = SferaNumeric::real32(1.0 / length);
    const float reference_projection = SferaNumeric::real32((-0.30000001192092896 * y - 0.9539999961853027 * std::fabs(z)) * inverse);
    const double reference_value = reference_projection;
    const float reference = SferaNumeric::real32(reference_value * reference_value);
    color = SferaMath::interpolate(color, interpolated.reference, reference);
    float glow = SferaNumeric::real32(direction.dot(SphereRenderSceneRenderer::sun_direction) * inverse);
    if (glow < 0.0f)
        glow = 0.0f;
    else
        for (int square = 0; square < 6; ++square)
        {
            const double value = glow;
            glow = SferaNumeric::real32(value * value);
        }
    sun_glow = glow;
    const auto overlay = SceneSky::skyPeriodicSample(interpolated.secondary, latitude);
    const float amount = SferaNumeric::real32(overlay.w / 255.0);
    const float fog = horizonFog(latitude, SphereRenderSceneRenderer::environment.fogParameters.x);
    // Alpha is composed separately; RGB follows the same two interpolation stages.
    auto rgb = SferaMath::interpolate(SferaVec3F{color.x, color.y, color.z}, {overlay.x, overlay.y, overlay.z}, amount);
    rgb = SferaMath::interpolate(rgb, SphereRenderSceneRenderer::environment.fogColor, fog);
    const double color_opacity = color.w;
    const float combined_opacity = SferaNumeric::real32(overlay.w + color_opacity);
    const float opacity = SferaNumeric::real32(combined_opacity + fog * 255.0);

    inverse_opacity = 255u - roundedColorChannel(opacity);
    sample_color = SferaColor::rgba(roundedColorChannel(rgb.x), roundedColorChannel(rgb.y), roundedColorChannel(rgb.z), 0u).argb();
}

void SceneSky::skyWrap(float &value, double period)
{
    while (value < 0.0f)
        value = SferaNumeric::real32(value + period);
    while (value >= period)
        value = SferaNumeric::real32(value - period);
}

double SceneSky::drawStars()
{
    const bool secondary = SphereRenderSceneRenderer::secondary_pass != 0u;
    const auto width = g_sfera_graphics_runtime.display_width;
    const auto height = g_sfera_graphics_runtime.display_height;
    const float roundedCellWidth = SferaNumeric::real32(secondary ? 25.600000381469727 : width / 10.0);
    const float roundedCellHeight = SferaNumeric::real32(secondary ? 32.0 : height * 0.125);
    const double cellWidth = roundedCellWidth, cellHeight = roundedCellHeight;
    screen_center_x = SferaNumeric::real32(width * 0.5);
    screen_center_y = SferaNumeric::real32(height * 0.5);
    const auto *corners = g_sfera_camera.frame_corners;
    const auto horizontal = corners[2] - corners[1], vertical = corners[4] - corners[1];
    if (!secondary)
    {
        const auto halfHorizontal = horizontal * 0.5f;
        const auto midpoint = corners[1] + (halfHorizontal + vertical * 0.5f);
        const auto center = corners[0] + (midpoint - corners[0]) * 0.10000000149011612f;
        const auto offset = center + halfHorizontal * 0.009999999776482582f;
        SferaVec3F centerScreen{}, offsetScreen{}, previousCenter{}, previousOffset{};
        g_sfera_camera.project(center, centerScreen);
        g_sfera_camera.project(offset, offsetScreen);
        const bool centerValid = g_sfera_camera.project(projected_center, previousCenter);
        const bool offsetValid = g_sfera_camera.project(projected_offset, previousOffset);
        projected_center = center;
        projected_offset = offset;
        if (centerValid && offsetValid)
        {
            auto rotation = g_sfera_camera.frame_transform;
            rotation.m[0][3] = rotation.m[1][3] = rotation.m[2][3] = 0.0f;
            const auto translation = rotation.inverseTransformPoint(corners[0] - previous_origin);
            previous_origin = corners[0];
            const auto distance = center - corners[0];
            const double radius = distance.length<double, float>();
            const float halfField = SferaNumeric::real32(g_sfera_camera.field_of_view * 0.5);
            const double halfAngle = halfField;
            const float tangent = SferaNumeric::real32(std::tan(halfAngle));
            const float roundedSpan = SferaNumeric::real32(tangent * radius);
            const double span = roundedSpan;
            const float shiftX = SferaNumeric::real32(translation.x / span * screen_center_x);
            const float shiftY = SferaNumeric::real32(translation.y / span * screen_center_y * 1.3333300352096558);
            const double previousX = previousCenter.x, previousY = previousCenter.y;
            const double deltaX = previousX - centerScreen.x + shiftX;
            const double deltaY = previousY - centerScreen.y + shiftY;
            motion.primary.x = SferaNumeric::real32(motion.primary.x + deltaX);
            motion.primary.y = SferaNumeric::real32(motion.primary.y + deltaY);
            horizontal_motion = SferaNumeric::real32(horizontal_motion + deltaX);
            vertical_motion = SferaNumeric::real32(vertical_motion + deltaY);
            const float width_pixels = SferaNumeric::real32(width);
            motion.secondary.x = SferaNumeric::real32(motion.secondary.x + deltaX * 256.0 / width_pixels);
            motion.secondary.y = SferaNumeric::real32(motion.secondary.y - deltaY * 256.0 / width_pixels);
            float uShift = SferaNumeric::real32(deltaX * 0.00390625), vShift = SferaNumeric::real32(deltaY * 0.00390625);
            SferaVec3F::rotatePair(uShift, vShift, motion.angle);
            const double uDelta = uShift, vDelta = vShift;
            texture_phase_u = SferaNumeric::real32(texture_phase_u - uDelta);
            texture_phase_v = SferaNumeric::real32(texture_phase_v - vDelta);
            const auto rotationDelta = previousOffset - previousCenter;
            const double rotationY = rotationDelta.y, rotationX = rotationDelta.x;
            const float roundedAngle = SferaNumeric::real32(std::atan2(rotationY, rotationX));
            const double angle = roundedAngle;
            motion.angle = SferaNumeric::real32(motion.angle - angle);
            SceneSky::skyWrap(motion.primary.x, cellWidth);
            SceneSky::skyWrap(motion.primary.y, cellHeight);
            SceneSky::skyWrap(motion.secondary.x, 25.600000381469727f);
            SceneSky::skyWrap(motion.secondary.y, 32.0f);
            SceneSky::skyWrap(texture_phase_u, 1.0f);
            SceneSky::skyWrap(texture_phase_v, 1.0f);
            SceneSky::skyWrap(motion.angle, 6.283185958862305f);
            motion.primary.x = SferaNumeric::real32(motion.primary.x - cellWidth);
            motion.primary.y = SferaNumeric::real32(motion.primary.y - cellHeight);
            motion.secondary.x -= 25.600000381469727;
            motion.secondary.y -= 32.0;
        }
        else
        {
            texture_phase_u = SferaNumeric::real32(std::rand() / 32767.0);
            texture_phase_v = SferaNumeric::real32(std::rand() / 32767.0);
            motion.angle = SferaNumeric::real32(std::rand() / 32767.0);
        }
    }
    const auto offset = secondary ? motion.secondary : motion.primary;
    const float gridX = SferaNumeric::real32(offset.x / cellWidth), gridY = SferaNumeric::real32(offset.y / cellHeight);
    for (int row = 0; row < 10; ++row)
    {
        for (int column = 0; column < 12; ++column)
        {
            const auto index = row * 12 + column;
            auto &vertex = vertices[index];
            vertex.x = SferaNumeric::real32(cellWidth * column + offset.x);
            vertex.y = SferaNumeric::real32(cellHeight * row + offset.y);
            vertex.z = 0.0f;
            vertex.rhw = 1.0f;
            rotateUv(vertex.x, vertex.y, motion.angle, vertex.u, vertex.v);
            const double columnValue = column, rowValue = row;
            const float columnPosition = SferaNumeric::real32(columnValue + gridX), rowPosition = SferaNumeric::real32(rowValue + gridY);
            const auto horizontalPart = (horizontal * columnPosition) * 0.10000000149011612f;
            SferaVec3F verticalPart;
            if (secondary)
            {
                const float factor = SferaNumeric::real32((rowValue + gridY) * 0.125 * 0.75 + 0.125);
                verticalPart = vertical * factor;
            }
            else
                verticalPart = (vertical * rowPosition) * 0.125f;
            sampleDirection(row == 0 && column == 0, corners[1] + (horizontalPart + verticalPart) - corners[0]);
            azimuth_samples[index] = sample_azimuth;
            elevation_samples[index] = sample_elevation;
            vertex.specular = sample_color;
            vertex.diffuse = D3DCOLOR_XRGB(inverse_opacity, inverse_opacity, inverse_opacity);
            glow_samples[index] = sun_glow;
            sample_visible[index] = sample_elevation < 1.5099999904632568f ? 1u : 0u;
        }
    }
    std::size_t count = 0;
    for (std::uint16_t row = 0; row < 9; ++row)
    {
        for (std::uint16_t column = 0; column < 11; ++column)
        {
            const std::uint16_t index = row * 12 + column;
            indices[count++] = index;
            indices[count++] = index + 1;
            indices[count++] = index + 12;
            indices[count++] = index + 1;
            indices[count++] = index + 13;
            indices[count++] = index + 12;
        }
    }
    SphereRenderSceneRenderer::bindTexture(SferaTextureAccess::find(secondary ? "black" : "stars"));
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    device.checkResult(device.native_device->SetRenderState(D3DRS_SPECULARENABLE, TRUE), "SetRenderState");
    device.checkResult(device.native_device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1), "SetFVF");
    device.drawVertices(D3DPT_TRIANGLELIST, 14u, vertices, 120u, indices, 594u, sizeof(SferaScreenVertex));
    device.checkResult(device.native_device->SetRenderState(D3DRS_SPECULARENABLE, FALSE), "SetRenderState");
    return motion.angle;
}

void SceneSky::drawSunMoon(float rotation)
{
    const auto time = g_sfera_graphics_runtime.environment_factor;
    const bool moon = !(time > 0.1899999976158142f && time < 0.8299999833106995f);
    const auto *corners = g_sfera_camera.frame_corners;
    const auto normal = (corners[1] - corners[2]).cross(corners[3] - corners[2]).normalized(1);
    SferaPlaneF plane{normal, 0.0f};
    plane.distance = SferaNumeric::real32(-normal.dot(corners[1]));
    SceneSky::flare_visible = 0u;
    SferaVec3F intersection{};
    const auto direction = SphereRenderSceneRenderer::sun_direction;
    if (plane.intersectLine(corners[0], corners[0] + direction, intersection) != 1)
        return;
    intersection = corners[0] + (intersection - corners[0]) * 0.8999999761581421f;
    SferaVec3F projected{};
    if (!g_sfera_camera.project(intersection, projected))
        return;
    SceneSky::flare_world_position = intersection;
    SceneSky::flare_screen_position = projected;
    const double scale = (moon ? 64.0 : 150.0) / 640.0;
    const auto width = g_sfera_graphics_runtime.display_width;
    const auto height = g_sfera_graphics_runtime.display_height;
    const float size = SferaNumeric::real32(scale * (SphereRenderSceneRenderer::secondary_pass != 0u ? 256.0 : width));
    const float half = SferaNumeric::real32(size * 0.5);
    auto &quadVertices = SceneSky::sun_quad;
    for (std::size_t index = 0; index < 4; ++index)
    {
        auto &vertex = quadVertices[index];
        vertex.x = index == 0u || index == 3u ? -half : half;
        vertex.y = index < 2u ? -half : half;
        vertex.u = index == 1u || index == 2u ? 1.0f : 0.0f;
        vertex.v = index >= 2u ? 1.0f : 0.0f;
    }
    float minimumX = quadVertices[0].x;
    float maximumX = quadVertices[0].x;
    float minimumY = quadVertices[0].y;
    float maximumY = quadVertices[0].y;
    const double projectedX = projected.x, projectedY = projected.y;
    for (std::uint32_t index = 0; index < 4u; ++index)
    {
        auto &vertex = quadVertices[index];
        SferaVec3F::rotatePair(vertex.x, vertex.y, -rotation);
        vertex.x = SferaNumeric::real32(vertex.x + projectedX);
        vertex.y = SferaNumeric::real32(vertex.y + projectedY);
        minimumX = std::min(minimumX, vertex.x);
        maximumX = std::max(maximumX, vertex.x);
        minimumY = std::min(minimumY, vertex.y);
        maximumY = std::max(maximumY, vertex.y);
        if (!moon)
            orbit(vertex.u, vertex.v, index);
        const float inverseWidth = SferaNumeric::real32(1.0 / width);
        const float inverseHeight = SferaNumeric::real32(1.0 / height);
        const auto horizontal = ((corners[2] - corners[1]) * vertex.x) * inverseWidth;
        const auto vertical = ((corners[4] - corners[1]) * vertex.y) * inverseHeight;
        sampleDirection(false, corners[1] + (horizontal + vertical) - corners[0]);
        const double directionX = direction.x;
        const float angle = SferaNumeric::real32(std::atan2(directionX, direction.y));
        const float absolute = std::fabs(angle);
        const float elevation = SferaNumeric::real32(1.0 - absolute / 3.1415929794311523);
        const float fog = SferaNumeric::real32(horizonFog(elevation, SphereRenderSceneRenderer::environment.fogParameters.x) * 255.0);
        vertex.specular = 0u;
        vertex.diffuse = SferaColor::rgba(255u, 255u, 255u, UINT32_MAX - SferaNumeric::truncatedWord(fog)).argb();
        vertex.z = 0.0f;
        vertex.rhw = 1.0f;
    }
    if (!(width > minimumX && maximumX > 0.0f && height > minimumY && maximumY > 0.0f))
        return;
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    device.setAlphaBlending(D3DBLEND_SRCALPHA, moon ? D3DBLEND_INVSRCALPHA : D3DBLEND_ONE);
    SphereRenderSceneRenderer::bindTexture(SferaTextureAccess::find(moon ? "moon" : "sun"));
    if (!moon)
        SceneSky::flare_visible = 1u;
    device.checkResult(device.native_device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1), "SetFVF");
    device.drawVertices(D3DPT_TRIANGLEFAN, 14u, quadVertices, 4u, nullptr, 0u, sizeof(SferaScreenVertex));
    device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}

int SceneSky::roundedColorChannel(float value)
{
    const int channel = SferaNumeric::truncateInt(std::nearbyint(value));
    return std::min(channel, 255);
}

const WeatherScenario &WeatherScenarios::at(std::size_t sequenceIndex) const
{
    if (sequenceIndex >= sequence.size() || sequence[sequenceIndex] >= scenarios.size())
        SferaEngineDiagnostics::fail("wScenarioArr[curSN] >= wScenariosNum");
    return scenarios[sequence[sequenceIndex]];
}

void WeatherScenarios::locate(int time, std::size_t &sequenceIndex, int &startTime, int &localTime) const
{
    if (totalDuration == 0)
        SferaEngineDiagnostics::fail("Weather sequence has zero duration");
    const auto cyclicTime = time % totalDuration;
    int end = 0;
    for (std::size_t index = 0u; index < sequence.size(); ++index)
    {
        const auto &scenario = at(index);
        end += scenario.duration;
        if (cyclicTime < end)
        {
            sequenceIndex = index;
            localTime = scenario.duration - end + cyclicTime;
            startTime = time - localTime;
            return;
        }
    }
}

int WeatherScenarios::advance(std::size_t &sequenceIndex, std::size_t &keyframe) const
{
    const auto &scenario = at(sequenceIndex);
    const auto time = scenario.keyframes[keyframe].time;
    if (++keyframe != scenario.keyframes.size())
        return scenario.keyframes[keyframe].time - time;
    keyframe = 0u;
    if (++sequenceIndex == sequence.size())
        sequenceIndex = 0u;
    return scenario.duration - time + at(sequenceIndex).keyframes.front().time;
}

int WeatherScenarios::retreat(std::size_t &sequenceIndex, std::size_t &keyframe) const
{
    const auto time = at(sequenceIndex).keyframes[keyframe].time;
    if (keyframe != 0u)
        return time - at(sequenceIndex).keyframes[--keyframe].time;
    sequenceIndex = sequenceIndex == 0u ? sequence.size() - 1u : sequenceIndex - 1u;
    const auto &scenario = at(sequenceIndex);
    keyframe = scenario.keyframes.size() - 1u;
    return scenario.duration - scenario.keyframes[keyframe].time + time;
}

double WeatherScenarios::nextValue(std::size_t sequenceIndex, int time, std::size_t property, int &distance) const
{
    const auto &scenario = at(sequenceIndex);
    std::size_t keyframe = 0u;
    while (keyframe < scenario.keyframes.size() && scenario.keyframes[keyframe].time < time)
        ++keyframe;
    if (keyframe == scenario.keyframes.size())
    {
        distance = scenario.duration - time;
        if (++sequenceIndex == sequence.size())
            sequenceIndex = 0u;
        keyframe = 0u;
        distance += at(sequenceIndex).keyframes.front().time;
    }
    else
        distance = scenario.keyframes[keyframe].time - time;
    const auto initialSequence = sequenceIndex, initialFrame = keyframe;
    for (;;)
    {
        const auto value = at(sequenceIndex).keyframes[keyframe].properties[property];
        if (value >= 0.0f)
            return value;
        distance += advance(sequenceIndex, keyframe);
        if (sequenceIndex == initialSequence && keyframe == initialFrame)
            SferaEngineDiagnostics::fail("Weather property has no keyframe value");
    }
}

double WeatherScenarios::previousValue(std::size_t sequenceIndex, int time, std::size_t property, int &distance) const
{
    const auto &scenario = at(sequenceIndex);
    std::size_t keyframe = scenario.keyframes.size();
    while (keyframe != 0u && scenario.keyframes[keyframe - 1u].time > time)
        --keyframe;
    if (keyframe == 0u)
    {
        sequenceIndex = sequenceIndex == 0u ? sequence.size() - 1u : sequenceIndex - 1u;
        keyframe = at(sequenceIndex).keyframes.size() - 1u;
        distance = time + at(sequenceIndex).duration - at(sequenceIndex).keyframes[keyframe].time;
    }
    else
    {
        --keyframe;
        distance = time - scenario.keyframes[keyframe].time;
    }
    const auto initialSequence = sequenceIndex, initialFrame = keyframe;
    for (;;)
    {
        const auto value = at(sequenceIndex).keyframes[keyframe].properties[property];
        if (value >= 0.0f)
            return value;
        distance += retreat(sequenceIndex, keyframe);
        if (sequenceIndex == initialSequence && keyframe == initialFrame)
            SferaEngineDiagnostics::fail("Weather property has no keyframe value");
    }
}

void WeatherScenarios::copyTexture(std::string_view name, SceneSkyLayer &output) const
{
    if (name.empty())
    {
        output = {};
        return;
    }
    for (std::size_t index = 0u; index < textures.size(); ++index)
        if (SferaText::asciiEqual(textures[index].texture, name))
        {
            output = textures[index];
            return;
        }
    SferaEngineDiagnostics::warning((std::string("Sky texture name absent in params. ") + std::string(name)));
}

WeatherSkyPair WeatherScenarios::selectSky(int time, float dayTime) const
{
    std::size_t index = 0u;
    int start = 0, local = 0;
    locate(time, index, start, local);
    const auto &scenario = at(index);
    const double precise_local = local;
    const float fraction = SferaNumeric::real32(precise_local / scenario.duration);
    if (fraction >= 1.0f)
        SferaEngineDiagnostics::fail("internal error 98742756");
    const WeatherSkyPair *selected = nullptr;
    if ((!scenario.sky.primary.empty() || !scenario.sky.secondary.empty()) && scenario.skyStart <= fraction && scenario.skyEnd >= fraction)
        selected = &scenario.sky;
    else
    {
        std::vector<const WeatherSkyPair *> available;
        for (std::size_t pair = 0u; pair < pairs.size(); ++pair)
        {
            const auto &sky = pairs[pair];
            const auto &name = !sky.primary.empty() ? sky.primary : sky.secondary;
            if (name.empty())
            {
                available.push_back(&sky);
                continue;
            }
            const SceneSkyLayer *layer = nullptr;
            for (std::size_t texture = 0u; texture < textures.size(); ++texture)
                if (SferaText::asciiEqual(textures[texture].texture, name))
                {
                    layer = &textures[texture];
                    break;
                }
            if (layer == nullptr)
            {
                SferaEngineDiagnostics::warning((std::string("Sky texture name present in para, but absent in params. ") + std::string(name)));
                continue;
            }
            if (layer->minimumTime <= dayTime && layer->maximumTime >= dayTime)
                available.push_back(&sky);
        }
        if (!available.empty())
        {
            const auto count = std::ssize(available);
            selected = available[(start % count + count) % count];
        }
    }
    return selected == nullptr ? WeatherSkyPair{} : *selected;
}

void WeatherScenarios::update(int time, float dayTime, WeatherState &output, bool alternateClouds)
{
    if (time <= lastUpdate)
        return;
    lastUpdate = time;
    std::size_t sequenceIndex = 0u;
    int startTime = 0, localTime = 0;
    locate(time, sequenceIndex, startTime, localTime);
    constexpr std::array<float WeatherState::*, 4> destinations{&WeatherState::rain, &WeatherState::lightning, &WeatherState::wind, &WeatherState::cloud};
    for (std::size_t index = 0; index < destinations.size(); ++index)
    {
        const auto property = index;
        int previousDistance = 0, nextDistance = 0;
        const float previous = SferaNumeric::real32(previousValue(sequenceIndex, localTime, property, previousDistance));
        float value = previous;
        if (previousDistance != 0)
        {
            const float next = SferaNumeric::real32(nextValue(sequenceIndex, localTime, property, nextDistance));
            const double precise_previous = previous;
            const double precise_next_distance = nextDistance;
            value = SferaNumeric::real32((next - precise_previous) * previousDistance / (previousDistance + precise_next_distance) + previous);
        }
        output.*destinations[index] = value;
    }
    const auto selected = selectSky(time, dayTime);
    output.sky.opacity = 0.0f;
    if (!selected.primary.empty() || !selected.secondary.empty())
    {
        constexpr int transitionSteps = 81;
        constexpr double dayStep = 0.00017361111531499773;

        const auto nextChange = distanceToChange(time, dayTime, selected, 1, transitionSteps, dayStep);
        const auto previousChange = distanceToChange(time, dayTime, selected, -1, transitionSteps, dayStep);
        windDirection(previousChange == 1, startTime, output.windX, output.windZ);
        const double precise_transition_steps = transitionSteps;
        output.sky.opacity = SferaNumeric::real32(std::min(nextChange, previousChange) / precise_transition_steps);
    }
    copyTexture(selected.primary, output.sky.primary);
    copyTexture(selected.secondary, output.sky.secondary);
    if (alternateClouds)
    {
        copyTexture("clouds8", output.clouds.primary);
        copyTexture("clouds8a", output.clouds.secondary);
        output.clouds.opacity = 1.0f;
    }
}

int WeatherScenarios::distanceToChange(int time, float dayTime, const WeatherSkyPair &selected, int direction, int transitionSteps, double dayStep) const
{
    for (int distance = 1; distance < transitionSteps; ++distance)
    {
        const int sampleTime = SferaNumeric::signedWord(SferaNumeric::word(time) + SferaNumeric::word(direction * distance));
        const float sampleDay = SferaNumeric::real32(dayTime + (direction * distance) * dayStep);
        if (selected != selectSky(sampleTime, sampleDay))
            return distance;
    }
    return transitionSteps;
}

void WeatherScenarios::windDirection(bool refresh, int seed, float &x, float &z)
{
    auto &state = g_sfera_weather_runtime;
    if (refresh || (state.direction_sin_component == 0.0f && state.direction_cos_component == 0.0f))
    {
        const auto direction = (seed >> 1) & 7;
        const auto intensity = ((seed >> 4) & 3) + 1;
        const float angle = SferaNumeric::real32(direction * 0.7853982448577881);
        const float speed = SferaNumeric::real32((intensity * 0.25) * 0.00019999999494757503);
        const auto [sine, cosine] = SferaMath::rotationTerms(angle);
        state.direction_sin_component = SferaNumeric::real32(cosine * speed);
        state.direction_cos_component = SferaNumeric::real32(sine * speed);
    }
    x = state.direction_sin_component;
    z = state.direction_cos_component;
}

uint32_t SceneSky::layer_alpha[120]{};
float SceneSky::sample_elevation{};
float SceneSky::horizontal_motion{};
float SceneSky::azimuth_samples[125]{};
float SceneSky::screen_center_y{};
float SceneSky::sample_azimuth{};
SferaScreenVertex SceneSky::sun_quad[4]{};
uint32_t SceneSky::inverse_opacity{};
float SceneSky::cloud_offset_y{};
float SceneSky::cloud_offset_x{};
float SceneSky::sun_glow{};
uint16_t SceneSky::indices[594]{};
SceneSkyMotion SceneSky::motion{};
SferaVec3F SceneSky::previous_origin{};
SferaVec3F SceneSky::projected_offset{};
SferaVec3F SceneSky::projected_center{};
float SceneSky::texture_phase_v{};
float SceneSky::glow_samples[120]{};
float SceneSky::elevation_samples[120]{};
float SceneSky::texture_phase_u{};
bool SceneSky::sample_visible[120]{};
float SceneSky::screen_center_x{};
float SceneSky::vertical_motion{};
uint32_t SceneSky::sample_color{};
uint32_t SceneSky::flare_visible{};
float SceneSky::animation_phase{};
SferaVec3F SceneSky::flare_world_position{};
SferaScreenVertex SceneSky::vertices[120]{};
SferaVec3F SceneSky::flare_screen_position{};
SkyState SceneSky::interpolated{};
