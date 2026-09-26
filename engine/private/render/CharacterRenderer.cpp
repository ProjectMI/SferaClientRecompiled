#include <windows.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <functional>
#include <iterator>
#include <optional>
#include <vector>

#include "graphics/d3d9/Device.h"
#include "animation/Animation.h"
#include "diagnostics/Diagnostics.h"
#include "environment/Environment.h"
#include "lifetime/Restore.h"
#include "lighting/LightRuntime.h"
#include "math/Color.h"
#include "math/MathFunctions.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/CharacterRenderer.h"
#include "render/GraphicsRuntime.h"
#include "render/SceneRenderer.h"
#include "render/VertexFormats.h"
#include "runtime/Clock.h"
#include "scene/SceneAccess.h"
#include "scene/SceneObject.h"
#include "shadows/Shadows.h"

void SphereRenderCharacterModels::characterDisableLights(std::uint32_t line)
{
    for (std::size_t index = 0; index < g_sfera_light_runtime.candidate_count; ++index)
        if (g_sfera_light_runtime.render_candidate_active[index])
            g_sfera_light_runtime.setActive(g_sfera_light_runtime.render_candidate_indices[index], false, line);
}

void SphereRenderCharacterModels::animate(const SphereRenderCharacterSkeleton &skeleton, int animation, int frame, int secondaryAnimation, int secondaryFrame, float interpolation,
                                          SferaMatrix4x4F *output, bool attachmentsOnly) const
{
    if (animation < 0 || std::cmp_greater_equal(animation, skeleton.animation_lengths.size()) || frame < 0 || std::cmp_greater_equal(frame, skeleton.animation_lengths[animation]))
    {
        animation = 0;
        frame = 0;
    }
    const auto first = skeleton.absoluteFrame(animation, frame);
    const auto second = skeleton.absoluteFrame(secondaryAnimation, secondaryFrame);
    const auto upperFrame = interpolation < 0.01f ? std::nullopt : std::optional(second);
    for (std::size_t bone = 0; bone < skeleton.parents.size(); ++bone)
    {
        if (!skeleton.parents[bone])
            skeleton.calculate(first, upperFrame, bone, root_transform, SphereRenderCharacterSkeletonRegion::Whole, output);
    }
    if (attachmentsOnly && animation == 0 && frame == 0)
        for (std::size_t bone = 0; bone < skeleton.parents.size(); ++bone)
            if (std::find(skeleton.attachments.begin(), skeleton.attachments.begin() + 4, bone) == skeleton.attachments.begin() + 4)
                output[bone] = root_transform;
}

void SphereRenderCharacterModels::initializeBounds()
{
    for (std::size_t index = 0; index < 8; ++index)
        bounds[index] = {index & 2u ? 1.0f : -1.0f, index & 4u ? -2.5f : 0.0f, index & 1u ? 1.0f : -1.0f};
}

int SphereRenderCharacterModels::classify(const SferaMatrix4x4F &world) const
{
    std::array<SferaVec3F, 8> transformed;
    std::transform(std::begin(bounds), std::end(bounds), transformed.begin(), std::bind_front(&SferaMatrix4x4F::transformPoint<double>, std::cref(world)));
    return SphereRenderSceneRenderer::frustum.classifyPoints(transformed);
}

void SphereRenderCharacterModels::setDistances(double minimum, float range)
{
    minimum_distance = SferaNumeric::real32(minimum);
    maximum_distance = SferaNumeric::real32(minimum + range);
    lod_end = SferaNumeric::real32(minimum + range * 0.5);
    lod_start = SferaNumeric::real32(lod_end * 0.699999988079071);
}

void SphereRenderCharacterModels::updateLodDistance()
{
    const auto previous = last_lod_update;
    last_lod_update = WorldClock::nowTicks();
    if (previous == 0u)
        return;
    const std::int64_t elapsed = last_lod_update - previous;
    if (rendered_count < 5u || rendered_count > 10u)
    {
        const bool expand = rendered_count < 5u;
        const float exponent = SferaNumeric::real32(elapsed * (expand ? 9.999999747378752e-05 : 0.00039999998989515007));
        const double power = exponent;
        const float factor = SferaNumeric::real32(std::pow(expand ? 1.100000023841858 : 0.8999999761581421, power));
        lod_end *= factor;
        lod_end = expand ? std::min(lod_end, maximum_distance) : std::max(lod_end, minimum_distance);
    }
    rendered_count = 0u;
    lod_start = SferaNumeric::real32(lod_end * 0.699999988079071);
}

float SphereRenderCharacterModels::visibility(const WorldObject &object) const
{
    const auto delta = object.position - SferaSceneAccess::cameraObject()->position;
    const float squared = SferaNumeric::real32(delta.dot(delta));
    const double squared_distance = squared;
    const float rounded_distance = SferaNumeric::real32(std::sqrt(squared_distance));
    const double end = lod_end;
    const double fade_distance = rounded_distance;
    const float result = SferaNumeric::real32(1.0 - (fade_distance - lod_start) / (end - lod_start));
    return std::clamp(result, 0.0f, 1.0f);
}

SferaVec3F SphereRenderCharacterModels::neckPosition(const ExtendedWorldObject &object) const
{
    const auto world = SferaMatrix4x4F::fromEuler(object.position, object.rotation);
    const auto &skeleton = skeletons[appearance(object).sex];
    std::vector<SferaMatrix4x4F> pose(skeleton.parents.size());
    animate(skeleton, object.animation, object.frame, object.animation_secondary, object.frame_secondary, object.interpolation, pose.data(), true);
    const auto neck = skeleton.attachments[6];
    const auto combined = (skeleton.initial_pose[neck]).multiplied((pose[neck]));
    return world.transformPoint({combined.m[3][0], combined.m[3][1], combined.m[3][2]});
}

HRESULT SphereRenderCharacterModels::setMaterial(float opacity, float detail, const SferaVec3F &color)
{
    const float intensity = SferaNumeric::real32(detail * 0.699999988079071 + 0.30000001192092896);
    D3DMATERIAL9 material{};
    material.Diffuse = {intensity * color.x, intensity * color.y, intensity * color.z, opacity};
    material.Ambient = {material.Diffuse.r, material.Diffuse.g, material.Diffuse.b, 0.0f};
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    return device.checkResult(device.native_device->SetMaterial(&material), "SetMaterial");
}

void SphereRenderCharacterModels::clear()
{
    for (auto &slot : instances)
    {
        if (slot.owner != nullptr)
            slot.owner->render_cache_handle = 0;
        slot = {};
    }
    part_indices = {};
    parts.clear();
    assets.clear();
    directories.clear();
    for (auto &skeleton : skeletons)
        skeleton = {};
}

void SphereRenderCharacterModels::drawPart(int sex, int kind, std::uint8_t model, int visibility, const SphereRenderCharacterSkeleton &skeleton, const SferaMatrix4x4F *pose, bool cull, int,
                                           int textureCode, std::uint32_t passes)
{
    if (sex < 0 || std::cmp_greater_equal(sex, std::size(skeletons)) || kind < 0 || std::cmp_greater_equal(kind, part_indices[sex].size()))
        SferaEngineDiagnostics::fail("Invalid character part selector");
    const auto selected = part_indices[sex][kind][model];
    if (!selected)
        return;
    const auto &part = parts.at(*selected);
    auto &asset = assets.at(part.asset);
    preload(asset, skeleton);
    const auto &geometry = *asset.geometry;
    if (textureCode == 0)
        textureCode = '0';
    if (!((textureCode >= '0' && textureCode <= '9') || (textureCode >= 'a' && textureCode <= 'z')))
        SferaEngineDiagnostics::fail("Invalid character texture code");
    std::vector<SphereRenderPositionNormalUvVertex> skinned(geometry.vertices.size());
    for (std::size_t vertex = 0; vertex < geometry.vertices.size(); ++vertex)
    {
        const auto &input = geometry.vertices[vertex];
        auto &output = skinned[vertex];
        output.u = input.u;
        output.v = input.v;
        const auto first = pose[input.first_bone].transposed();
        output.position = first.transformPoint(input.position);
        auto basis = first;
        basis.m[0][3] = basis.m[1][3] = basis.m[2][3] = 0.0f;
        output.normal = basis.transformPoint(input.normal);
        if (input.weight < 0.9900000095367432)
        {
            const auto second = pose[input.second_bone].transposed();
            const auto position = second.transformPoint(input.position);
            basis = second;
            basis.m[0][3] = basis.m[1][3] = basis.m[2][3] = 0.0f;
            const auto normal = basis.transformPoint(input.normal);
            output.position = SferaMath::interpolate(position, output.position, input.weight);
            output.normal = SferaMath::interpolate(normal, output.normal, input.weight);
        }
    }
    if ((passes & 2u) != 0u)
        g_sfera_shadows->projectVertices(skinned.data(), skinned.size(), geometry.indices.data(), geometry.indices.size());
    if ((passes & 1u) == 0u)
        return;
    const auto variant = textureCode > '9' ? textureCode - 'a' + 10 : textureCode - '0';
    if (std::cmp_greater_equal(variant, std::size(part.textures)))
        SferaEngineDiagnostics::fail("Character texture variant is out of range");
    auto texture = part.textures[variant];
    if (texture == -1)
        texture = part.textures[0];
    if (texture == -1)
        SferaEngineDiagnostics::fail("Character texture is missing");
    SphereRenderSceneRenderer::bindTexture(texture);
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    auto vertexData = device.model_vertices.lock(skinned.size());
    std::copy(skinned.begin(), skinned.end(), vertexData.data());
    vertexData.unlock();
    std::uint32_t flags = visibility == 2 && SphereRenderSceneRenderer::secondary_pass == 0u ? CD3D9Devicedisable_clipping : 0u;
    if (!cull)
        flags |= CD3D9Devicetwo_sided;
    auto indices = device.indices_primary.lock(geometry.indices.size());
    std::copy(geometry.indices.begin(), geometry.indices.end(), indices.data());
    indices.unlock();
    device.drawBuffer(vertexData.buffer(), D3DPT_TRIANGLELIST, flags | CD3D9Devicelighting, vertexData.first(), skinned.size(), indices.buffer(), geometry.indices.size(), indices.first(),
                      sizeof(SphereRenderPositionNormalUvVertex));
}

void SphereRenderCharacterModels::drawLowDetail(std::uint32_t handle)
{
    auto *object = checkedExtended(SferaSceneAccess::object(handle));
    if (!object->render_enabled)
        return;
    const auto world = SferaMatrix4x4F::fromEuler(object->position, object->rotation);
    const auto visible = classify(world);
    if (visible == 0)
        return;
    const auto transform = world.transposed();
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    device.setTransform(D3DTS_WORLD, transform);
    g_sfera_light_runtime.setDirectionalLight({-SphereRenderSceneRenderer::sun_direction.x, -SphereRenderSceneRenderer::sun_direction.y, -SphereRenderSceneRenderer::sun_direction.z},
                                              {SphereRenderSceneRenderer::environment.sunColor.x, SphereRenderSceneRenderer::environment.sunColor.y,
                                               SphereRenderSceneRenderer::environment.sunColor.z});
    SphereRenderSceneRenderer::activateObjectLights(handle);
    SphereRenderSceneRenderer::setAmbientColor();
    const auto &parameters = appearance(*object);
    const auto &skeleton = skeletons[parameters.sex];
    std::vector<SferaMatrix4x4F> pose(skeleton.parents.size());
    animate(skeleton, object->animation, object->frame, object->animation_secondary, object->frame_secondary, object->interpolation, pose.data(), true);
    setMaterial(object->scale, 0.0f, {1.0f, 1.0f, 1.0f});
    if (object->scale != 1.0f)
        device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
    drawPart(parameters.sex, 'd' - 'a', '0', visible, skeleton, pose.data(), true, object->scale != 1.0f, '0', 1u);
    setMaterial(1.0f, 1.0f, {1.0f, 1.0f, 1.0f});
    if (object->scale != 1.0f)
        device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    SphereRenderCharacterModels::characterDisableLights(1208u);
    updateEffectFrames(*object, skeleton, pose, world);
}

void SphereRenderCharacterModels::draw(std::uint32_t handle, std::uint32_t color)
{
    const ShadowMapPass shadowPass(*g_sfera_shadows);
    const SferaRestore projectionOpacity(SphereRenderSceneRenderer::shadow_projection_opacity);
    auto *object = checkedExtended(SferaSceneAccess::object(handle));
    if (!object->render_enabled)
        return;
    const auto world = SferaMatrix4x4F::fromEuler(object->position, object->rotation);
    const auto visible = classify(world);
    if (visible == 0)
        return;
    ++rendered_count;
    const float detail = !g_sfera_graphics_runtime.lods_enabled ? 1.0f : visibility(*object);
    if (detail < 0.001f)
    {
        drawLowDetail(handle);
        return;
    }
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    const auto transform = world.transposed();
    device.setTransform(D3DTS_WORLD, transform);
    g_sfera_light_runtime.setDirectionalLight({-SphereRenderSceneRenderer::sun_direction.x, -SphereRenderSceneRenderer::sun_direction.y, -SphereRenderSceneRenderer::sun_direction.z},
                                              {SphereRenderSceneRenderer::environment.sunColor.x, SphereRenderSceneRenderer::environment.sunColor.y,
                                               SphereRenderSceneRenderer::environment.sunColor.z});
    SphereRenderSceneRenderer::activateObjectLights(handle);
    SphereRenderSceneRenderer::setAmbientColor();
    float shadowFade = 0.0f;
    ShadowMap::prepareObject(handle, *object, 1.0f, 1.0f, shadowFade);
    const auto &parameters = appearance(*object);
    const auto &skeleton = skeletons[parameters.sex];
    std::vector<SferaMatrix4x4F> pose(skeleton.parents.size());
    animate(skeleton, object->animation, object->frame, object->animation_secondary, object->frame_secondary, object->interpolation, pose.data(), true);
    const auto tint = SferaColor::fromArgb(color);
    setMaterial(object->scale, detail, {tint.red() / 255.0f, tint.green() / 255.0f, tint.blue() / 255.0f});
    if (object->scale != 1.0f)
        device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);

    const auto &p = parameters.parts;
    if (p[2] != 0u)
    {
        drawAppearancePart(parameters, visible, skeleton, pose, object, 2, p[2]);
        drawAppearancePart(parameters, visible, skeleton, pose, object, 4, p[2], p[4]);
    }
    else
    {
        drawAppearancePart(parameters, visible, skeleton, pose, object, 21, p[3]);
        drawAppearancePart(parameters, visible, skeleton, pose, object, 11, p[3], p[4]);
    }
    drawAppearancePart(parameters, visible, skeleton, pose, object, 6, p[6]);
    drawAppearancePart(parameters, visible, skeleton, pose, object, 19, p[1]);
    drawAppearancePart(parameters, visible, skeleton, pose, object, 1, p[0]);
    const std::uint32_t headPasses = handle == SferaSceneAccess::controlledHandle() ? 2u : 3u;
    drawAppearancePart(parameters, visible, skeleton, pose, object, 5, p[7], p[8], headPasses);
    if (p[11] != 0u)
        drawAppearancePart(parameters, visible, skeleton, pose, object, 7, p[11], '0', headPasses);
    if (p[11] == 0u || usesSmallHelm(parameters.sex, p[11]) != 0)
    {
        device.checkResult(device.native_device->SetRenderState(D3DRS_ALPHAREF, 128u), "SetRenderState");
        drawAppearancePart(parameters, visible, skeleton, pose, object, p[11] == 0u ? 17 : 16, p[9], p[10], headPasses, false);
        device.checkResult(device.native_device->SetRenderState(D3DRS_ALPHAREF, 1u), "SetRenderState");
    }
    SphereRenderSceneRenderer::setOpacity(true);
    for (std::size_t slot = 0; slot < 5u; ++slot)
        if (object->linked_objects[slot] != 0u && !(slot == 3u && handle == SferaSceneAccess::controlledHandle()))
        {
            auto &matrices = SphereRenderModelPose::attachment_transforms;
            if (slot >= matrices.size())
                SferaEngineDiagnostics::fail("Character attachment matrix is missing");
            matrices[slot] = (world).multiplied((pose[skeleton.attachments[slot]].transposed()));
            SphereRenderSceneRenderer::drawModel(object->linked_objects[slot]);
        }
    SphereRenderSceneRenderer::setOpacity(false);
    setMaterial(1.0f, 1.0f, {1.0f, 1.0f, 1.0f});
    if (object->scale != 1.0f)
        device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    ShadowMap::drawObject(*object, 1.0f, shadowFade);
    SphereRenderCharacterModels::characterDisableLights(1085u);
    updateEffectFrames(*object, skeleton, pose, world);
}

bool SphereRenderCharacterModels::unusedCharacterSlot(const SphereRenderCharacterSlot &entry)
{
    return entry.owner == nullptr;
}

void SphereRenderCharacterModels::drawAppearancePart(const SphereRenderCharacterAppearance &parameters, int visible, const SphereRenderCharacterSkeleton &skeleton,
                                                     const std::vector<SferaMatrix4x4F> &pose, const ExtendedWorldObject *object, int kind, std::uint8_t model, int texture, std::uint32_t passes,
                                                     bool cull)
{
    drawPart(parameters.sex, kind, model, visible, skeleton, pose.data(), cull, object->scale != 1.0f, texture, passes);
}
