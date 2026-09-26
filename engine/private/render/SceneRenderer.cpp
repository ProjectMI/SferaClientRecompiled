#include <windows.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <iterator>
#include <memory>
#include <span>
#include <stdexcept>
#include <variant>
#include <vector>

#include "algorithms/StableSort.h"
#include "animation/Animation.h"
#include "camera/Camera.h"
#include "collision/Collision.h"
#include "diagnostics/Diagnostics.h"
#include "effects/Effect.h"
#include "environment/Environment.h"
#include "geometry/Geometry.h"
#include "graphics/d3d9/Device.h"
#include "lifetime/Restore.h"
#include "lighting/LightRuntime.h"
#include "math/Color.h"
#include "math/MathFunctions.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "platform/windows/ApplicationHost.h"
#include "render/CharacterRenderer.h"
#include "render/GraphicsRuntime.h"
#include "render/Material.h"
#include "render/Model.h"
#include "render/SceneRenderer.h"
#include "render/TextureAccess.h"
#include "render/VertexFormats.h"
#include "scene/SceneAccess.h"
#include "scene/SceneObject.h"
#include "shadows/Shadows.h"
#include "spatial/SpatialIndex.h"
#include "terrain/Terrain.h"
#include "terrain/TerrainData.h"
#include "text/Text.h"
#include "vegetation/Vegetation.h"
#include "vegetation/VegetationGeometry.h"

SphereRenderSceneRendererPassRestore::~SphereRenderSceneRendererPassRestore()
{
    SphereRenderSceneRenderer::secondary_pass = previous;
}

CD3D9Device &SphereRenderSceneRenderer::sceneDevice()
{
    return *g_sfera_graphics_runtime.d3d_runtime;
}

void SphereRenderSceneRenderer::sceneRenderState(D3DRENDERSTATETYPE state, DWORD value)
{
    auto &device = SphereRenderSceneRenderer::sceneDevice();
    device.checkResult(device.native_device->SetRenderState(state, value), "SetRenderState");
}

bool SphereRenderSceneRenderer::sceneBoundsOverlap(const SferaVec3F &minimum, const SferaVec3F &maximum, const SferaLightRecord &light)
{
    return !(minimum.x > light.bounds_max.x || minimum.y > light.bounds_max.y || minimum.z > light.bounds_max.z || maximum.x < light.bounds_min.x || maximum.y < light.bounds_min.y ||
             maximum.z < light.bounds_min.z);
}

bool SphereRenderSceneRenderer::bindTexture(int texture)
{
    auto &device = SphereRenderSceneRenderer::sceneDevice();
    device.checkResult(device.native_device->SetTexture(0u, SferaTextureAccess::resource(texture)), "SetTexture");
    return SferaTextureAccess::hasAlpha(texture);
}

void SphereRenderSceneRenderer::textureSize(int texture, std::uint32_t *dimensions)
{
    const auto size = SferaTextureAccess::size(texture);
    dimensions[0] = SferaNumeric::word(size.width);
    dimensions[1] = SferaNumeric::word(size.height);
}

void SphereRenderSceneRenderer::setAmbientColor()
{
    const auto color = SphereRenderSceneRenderer::environment.ambientColor;
    const std::uint32_t red = SferaNumeric::truncatedWord(color.x);
    const std::uint32_t green = SferaNumeric::truncatedWord(color.y);
    const std::uint32_t blue = SferaNumeric::truncatedWord(color.z);
    SphereRenderSceneRenderer::sceneRenderState(D3DRS_AMBIENT, SferaColor::rgba(red, green, blue).argb());
}

void SphereRenderSceneRenderer::setMaterialColor(int red, int green, int blue)
{
    D3DMATERIAL9 material{};
    material.Diffuse.r = SferaNumeric::real32(red / 255.0);
    material.Diffuse.g = SferaNumeric::real32(green / 255.0);
    material.Diffuse.b = SferaNumeric::real32(blue / 255.0);
    material.Diffuse.a = 1.0f;
    material.Ambient = material.Diffuse;
    material.Specular.a = 1.0f;
    auto &device = SphereRenderSceneRenderer::sceneDevice();
    device.checkResult(device.native_device->SetMaterial(&material), "SetMaterial");
}

std::uint32_t SphereRenderSceneRenderer::terrainShade(std::uint32_t shade, float x, float z)
{
    SferaTerrainSource::prepareColorMap();
    if (shade == 0u || SphereRenderSceneRenderer::interior_scene == 1u)
        return 255u;
    const auto planting = SferaTerrainSource::plantingType(x, z);
    const auto terrain = std::array<std::uint32_t, 4>{255u, 200u, 150u, 100u}.at(planting);
    const int scaled = (255u - terrain) * (255u - shade);
    return (scaled / 256) + terrain;
}

void SphereRenderSceneRenderer::setObjectMaterial(WorldObject &object, std::uint32_t shade, const std::array<float, 3> &variation)
{
    if (object.lighting_color == 0u)
        object.lighting_color = SphereRenderMaterial::randomColor(variation);
    const auto intensity = terrainShade(shade, object.position.x, object.position.z);
    const auto color = object.lighting_color;
    const auto shaded = SferaColor::fromArgb(color).scaledRgb(intensity, 256u);
    setMaterialColor(shaded.red(), shaded.green(), shaded.blue());
}

void SphereRenderSceneRenderer::buildColorRemap(double exponent, double floor)
{
    for (int index = 0; index < 256; ++index)
    {
        const int value = SferaNumeric::truncateInt((std::pow(index / 255.0, exponent) * (1.0 - floor) + floor) * 255.0);
        const std::uint8_t channel = SferaNumeric::lowByte(SferaNumeric::word(std::clamp(value, 0, 255)));
        SphereRenderSceneRenderer::color_remap[index] = channel;
    }
}

void SphereRenderSceneRenderer::modelFade(float distance, float power, float &fade, float &remaining)
{
    if (distance <= 0.20000000298023224)
    {
        fade = 0.0f;
        remaining = 1.0f;
        return;
    }
    const float end = SferaNumeric::real32((power > 0.0f ? 1.0 : 0.0) + 0.20000000298023224);
    if (distance >= end)
    {
        fade = 1.0f;
        remaining = 0.0f;
        return;
    }
    const double transition = (distance - 0.20000000298023224) / 0.019999999552965164;
    const float power_base = SferaNumeric::real32(transition);
    fade = std::pow(power_base, power);
    remaining = SferaNumeric::real32(1.0 - transition);
}

bool SphereRenderSceneRenderer::hasMaterialVariant(std::uint32_t object, int variant)
{
    const auto *model = SferaSceneAccess::model(*SferaSceneAccess::object(object));
    if (model != nullptr)
        for (const auto *material : model->materials)
        {
            if (material == nullptr)
                throw std::out_of_range("Model material reference");
            if (!SferaText::asciiEqual(material->name, "default"))
                return variant >= 0 && std::cmp_less(variant, material->textures.size());
        }
    return false;
}

void SphereRenderSceneRenderer::setMaterialVariant(std::uint32_t object, int variant)
{
    auto *instance = SferaSceneAccess::extendedObject(object);
    if (instance != nullptr && instance->render_cache_handle >= 0)
        instance->render_cache_handle = variant;
}

void SphereRenderSceneRenderer::adaptFog()
{
    if (!g_sfera_graphics_runtime.auto_fog)
        return;
    const float speed = SphereRenderSceneRenderer::fog_adaptation_delay > 0u ? 0.019999999552965164f : 0.0010000000474974513f;
    if (SphereRenderSceneRenderer::fog_adaptation_delay > 0u)
        --SphereRenderSceneRenderer::fog_adaptation_delay;
    auto &fog = g_sfera_graphics_runtime.saved_fog_distance;
    const auto interval = SferaApplicationHost::measuredFramesPerSecond();
    if (interval < 20.0f)
    {
        const float adjusted = SferaNumeric::real32(fog * (1.0 - speed));
        fog = std::max(30.0f, adjusted);
    }
    else if (interval > 28.0f)
    {
        const float adjusted = SferaNumeric::real32(fog * (1.0 + speed));
        fog = std::min(200.0f, adjusted);
    }
}

void SphereRenderSceneRenderer::raiseDistantObject(std::uint32_t handle)
{
    auto &object = *SferaSceneAccess::object(handle);
    const auto delta = object.position - SferaSceneAccess::cameraObject()->position;
    const float length = delta.length<double, float>();
    const float distance_factor = SferaNumeric::real32((length - 45.0) / 15.0);
    const float amount = std::clamp(distance_factor, 0.0f, 1.0f);
    object.position.y = SferaNumeric::real32(object.position.y + amount * 1.399999976158142);
}

void SphereRenderSceneRenderer::activateObjectLights(std::uint32_t handle)
{
    SphereWorldContactQuery::updateBounds(handle);
    const auto &object = *SferaSceneAccess::object(handle);
    const auto &model = *SferaSceneAccess::model(object);
    const std::size_t maximum = model.animation_lengths.size() == 0u && model.bones.size() > 2u && model.radius > 15.0f ? 30u : 7u;
    auto &count = g_sfera_light_runtime.candidate_count;
    count = 0u;
    auto **visible = g_sfera_light_runtime.visible_handles.data();
    for (std::uint32_t index = 0; index < g_sfera_light_runtime.visible_handles.size() && count < maximum; ++index)
    {
        const auto &light = *visible[index];
        if (!SphereRenderSceneRenderer::sceneBoundsOverlap(object.bounds_minimum, object.bounds_maximum, light))
            continue;
        g_sfera_light_runtime.render_candidates[count] = light;
        g_sfera_light_runtime.render_candidate_indices[count] = index + 1u;
        g_sfera_light_runtime.render_candidate_active[count] = false;
        ++count;
    }
    if (count > 7u)
        return;
    for (std::size_t index = 0; index < count; ++index)
    {
        g_sfera_light_runtime.render_candidate_active[index] = true;
        g_sfera_light_runtime.setActive(g_sfera_light_runtime.render_candidate_indices[index], true, 14846u);
    }
}

void SphereRenderSceneRenderer::classifyBone(std::size_t index)
{
    const auto &model = *SphereRenderModelPose::active_model;
    const auto &bone = model.bones[index];
    auto &result = SphereRenderSceneRenderer::bone_visibility[index];
    if (bone.has_geometry)
    {
        if (model.bones.size() == 2u)
        {
            result.resource = SphereRenderSceneRenderer::model_visibility;
            result.mask = (1u << (g_sfera_light_runtime.candidate_count & 31u)) - 1u;
        }
        else
        {
            std::array<SferaVec3F, 8> corners;
            for (std::size_t vertex = 0; vertex < corners.size(); ++vertex)
                corners[vertex] = SphereRenderModelPose::current_frame.transformPoint(bone.bounds().corners.corners[vertex]);
            result.resource = SphereRenderSceneRenderer::frustum.classifyPoints(corners);
            if (result.resource != 0u)
            {
                result.mask = 0u;
                std::uint32_t selected = 0u;
                for (std::size_t light = 0; light < g_sfera_light_runtime.candidate_count && selected < 7u; ++light)
                    if (SphereRenderSceneRenderer::sceneBoundsOverlap(bone.bounds().minimum, bone.bounds().maximum, g_sfera_light_runtime.render_candidates[light]))
                        result.mask |= 1u << selected++;
            }
        }
    }
    for (std::size_t child = 0; child < bone.child_count; ++child)
        classifyBone(model.child_bones[bone.first_child + child]);
}

void SphereRenderSceneRenderer::collectLights()
{
    auto &visible = g_sfera_light_runtime.visible_handles;
    visible.clear();
    const auto *view_frustum = &SphereRenderSceneRenderer::frustum;
    const auto &first = view_frustum->planes[0];
    if (first.normal.x == 0.0f && first.normal.y == 0.0f && first.normal.z == 0.0f && first.distance == 0.0f)
        return;
    const auto camera = SferaSceneAccess::cameraObject()->position;
    const auto &handles = g_sfera_light_runtime.handles;
    visible.reserve(handles.size());
    for (std::size_t index = 0; index < handles.size(); ++index)
    {
        auto *light = handles[index].get();
        if (light == nullptr)
            continue;
        const SferaVec3F radius{light->radius, light->radius, light->radius};
        light->bounds_min = light->position - radius;
        light->bounds_max = light->position + radius;
        const auto corners = SferaBoundsCornersRuntime::fromExtents(light->bounds_min, light->bounds_max);
        if (view_frustum->classifyPoints(corners.corners) == 0)
            continue;
        visible.push_back(light);
        const auto delta = camera - light->position;
        const float distance = SferaNumeric::real32(delta.dot(delta));
        light->viewer_distance_squared = distance;
    }
    SferaAlgorithms::stableSort(visible, &SphereRenderSceneRenderer::lightDistanceKey);
    if (visible.size() > 30u)
        visible.resize(30u);
    auto &device = SphereRenderSceneRenderer::sceneDevice();
    D3DLIGHT9 light{};
    light.Type = D3DLIGHT_POINT;
    light.Diffuse.a = 1.0f;
    light.Specular = {1.0f, 1.0f, 1.0f, 1.0f};
    light.Ambient.a = 1.0f;
    light.Falloff = 1.0f;
    light.Attenuation2 = 1.0f;
    for (std::uint32_t index = 0; index < visible.size(); ++index)
    {
        const auto &source = *visible[index];
        light.Diffuse.r = SferaNumeric::real32(source.color[0] * 0.003921568859368563);
        light.Diffuse.g = SferaNumeric::real32(source.color[1] * 0.003921568859368563);
        light.Diffuse.b = SferaNumeric::real32(source.color[2] * 0.003921568859368563);
        light.Position = {source.position.x, source.position.y, source.position.z};
        light.Range = source.radius;
        device.checkResult(device.native_device->SetLight(index + 1u, &light), "SetLight");
        g_sfera_light_runtime.setActive(index + 1u, false, 14800u);
    }
}

std::size_t SphereRenderSceneRenderer::sceneAnimationFrame(SphereRenderModel &model, int animation, int frame)
{
    if (animation < 0 || animation >= model.animation_lengths.size())
    {
        animation = 0;
        frame = 0;
    }
    std::size_t absolute = 0u;
    for (int index = 0; index < animation; ++index)
        absolute += model.animation_lengths[index];
    if (frame < 0 || frame >= model.animation_lengths[animation])
        frame = 0;
    return absolute + frame;
}

void SphereRenderSceneRenderer::drawObjects(bool updateVegetation)
{
    if (g_sfera_shadows && SphereRenderSceneRenderer::interior_scene == 0u)
    {
        const auto sun = SphereRenderSceneRenderer::sun_direction;
        auto &fade = g_sfera_graphics_runtime.view_scale;
        fade = 0.0f;
        if (sun.y < 0.4000000059604645f)
        {
            const float offset = SferaNumeric::real32(sun.y - 0.4000000059604645);
            fade = SferaNumeric::real32(std::fabs(offset) / 1.399999976158142);
        }
        const float half = SferaNumeric::real32(fade * 0.5);
        fade = SferaNumeric::real32(1.0 - half);
        g_sfera_shadows->setDirection(sun, fade);
    }
    const SferaRestore grassMode(g_sfera_graphics_runtime.grass_depth);
    if (!SferaSceneAccess::vegetationVisible())
        g_sfera_graphics_runtime.grass_depth = 0u;
    auto *vegetation = g_sfera_vegetation.animation.get();
    if (updateVegetation)
        g_sfera_vegetation.updateCells();
    const auto center = SferaSceneAccess::cameraObject()->position;
    g_sfera_world_spatial.gatherObjects(center, SphereRenderSceneRenderer::view_distance);
    const auto &candidates = g_sfera_world_spatial.objects();
    const auto count = candidates.size();
    auto &positions = SphereRenderSceneRenderer::object_order;
    positions.resize(count);
    auto *entries = positions.data();
    for (std::uint32_t index = 0u; index < count; ++index)
    {
        const auto handle = candidates[index];
        const auto &object = *SferaSceneAccess::object(handle);
        const auto delta = object.position - center;
        entries[index] = {handle, object.ownsModel() ? SferaSceneAccess::modelCount() + handle : std::get<WorldObjectModelReference>(object.model_source).id, delta.length<double, float>()};
    }
    SferaAlgorithms::stableSort(std::span{object_order}.first(count), &SphereRenderSceneRenderer::objectOrderKey);
    SphereRenderSceneRenderer::sceneDevice().model_vertices.discard();
    if (SphereRenderSceneRenderer::secondary_pass == 0u || g_sfera_graphics_runtime.reflection_quality > 1u)
        for (std::uint32_t index = 0u; index < count; ++index)
        {
            const auto handle = entries[index].object;
            if (handle == SferaSceneAccess::cameraHandle())
                continue;
            auto &object = *SferaSceneAccess::object(handle);
            if (object.extended() && !object.extended()->render_enabled)
                continue;
            const auto *model = SferaSceneAccess::model(object);
            if (model->animation_lengths.size() != 0u)
                continue;
            if (object.ownsModel())
            {
                const SferaRestore height(object.position.y);
                raiseDistantObject(handle);
                if (updateVegetation)
                    drawModel(handle);
            }
            else
                drawModel(handle);
        }
    if (updateVegetation && g_sfera_graphics_runtime.grass_depth == 2u)
        vegetation->update();
    if (SphereRenderSceneRenderer::secondary_pass == 0u || g_sfera_graphics_runtime.reflection_quality > 2u)
        for (std::uint32_t index = 0u; index < count; ++index)
        {
            const auto handle = entries[index].object;
            if (handle == SferaSceneAccess::cameraHandle())
                continue;
            auto *base = SferaSceneAccess::object(handle);
            if (!base->extended())
                continue;
            auto &object = *SphereRenderCharacterModels::checkedExtended(base);
            auto &model = *SferaSceneAccess::model(object);
            if (model.animation_lengths.size() == 0u || !object.render_enabled)
                continue;
            if (object.render_cache_handle >= 0)
            {
                SphereRenderModelPose::primary_frame = SphereRenderSceneRenderer::sceneAnimationFrame(model, object.animation, object.frame);
                SphereRenderModelPose::secondary_enabled = false;
                if (object.interpolation > 0.009999999776482582f)
                {
                    SphereRenderModelPose::secondary_enabled = true;
                    SphereRenderModelPose::blend = object.interpolation;
                    SphereRenderModelPose::secondary_frame = SphereRenderSceneRenderer::sceneAnimationFrame(model, object.animation_secondary, object.frame_secondary);
                }
            }
            if (object.render_cache_handle >= 0)
                drawObject(handle);
            else
            {
                const auto shade = terrainShade(model.landscape_shadow_alpha, object.position.x, object.position.z);
                SphereRenderSceneRenderer::characters->draw(handle, SferaColor::rgba(shade, shade, shade, 0).argb());
            }
        }
}

std::uint32_t SphereRenderSceneRenderer::sceneColor(const SferaVec3F &color)
{
    return SferaColor::rgba(SferaNumeric::truncatedWord(color.x), SferaNumeric::truncatedWord(color.y), SferaNumeric::truncatedWord(color.z), 0u).argb();
}

void SphereRenderSceneRenderer::sceneWorldTransform(const SferaMatrix4x4F &world)
{
    const auto transform = world.transposed();
    SphereRenderSceneRenderer::sceneDevice().setTransform(D3DTS_WORLD, transform);
}

std::uint32_t SphereRenderSceneRenderer::sceneClassifyModel(const SphereRenderModel &model, const SferaMatrix4x4F &world)
{
    std::array<SferaVec3F, 8> corners;
    for (std::size_t index = 0u; index < corners.size(); ++index)
        corners[index] = world.transformPoint(model.collision_corners.corners[index]);
    return SphereRenderSceneRenderer::frustum.classifyPoints(corners);
}

float SphereRenderSceneRenderer::sceneUpdateFade(WorldObject &object, bool animated)
{
    if (object.render_fade == -1.0f)
        object.render_fade = 1.0f;
    else
    {
        const double speed = animated && object.render_fade < 0.009999999776482582 ? 7.999999797903001e-05 : 0.0007999999797903001;
        const float amount = SferaNumeric::real32(SferaNumeric::signedWord(SferaApplicationHost::frameElapsedTicks()) * speed);
        object.render_fade = amount < 1.0f ? SferaMath::interpolate(object.render_fade, 1.0, amount) : 1.0f;
    }
    return object.render_fade;
}

void SphereRenderSceneRenderer::sceneScaleSun(float amount)
{
    auto &sun = SphereRenderSceneRenderer::environment.sunColor;
    sun = sun * amount;
}

void SphereRenderSceneRenderer::sceneDirectionalLight()
{
    g_sfera_light_runtime.setDirectionalLight(SphereRenderSceneRenderer::sun_direction * -1.0f, SphereRenderSceneRenderer::environment.sunColor);
}

void SphereRenderSceneRenderer::sceneDisableLights(std::uint32_t sourceLine)
{
    for (std::size_t index = 0u; index < g_sfera_light_runtime.candidate_count; ++index)
        if (g_sfera_light_runtime.render_candidate_active[index])
            g_sfera_light_runtime.setActive(g_sfera_light_runtime.render_candidate_indices[index], false, sourceLine);
}

void SphereRenderSceneRenderer::sceneSelectLights(std::uint32_t mask)
{
    for (std::size_t index = 0; index < g_sfera_light_runtime.candidate_count; ++index)
    {
        const bool enabled = (mask & (std::uint32_t{1} << index)) != 0;
        auto &active = g_sfera_light_runtime.render_candidate_active[index];
        if (active == enabled)
            continue;
        g_sfera_light_runtime.setActive(g_sfera_light_runtime.render_candidate_indices[index], enabled, __LINE__);
        active = enabled;
    }
}

void SphereRenderSceneRenderer::sceneMaterialAmbient(const SphereRenderMaterial &material)
{
    const auto &ambient = SphereRenderSceneRenderer::environment.ambientColor;
    SphereRenderSceneRenderer::sceneRenderState(D3DRS_AMBIENT, SferaColor::rgba(ambientChannel(material.color[0], ambient.x), ambientChannel(material.color[1], ambient.y),
                                                                                ambientChannel(material.color[2], ambient.z))
                                                                   .argb());
}

DynamicStreamMapping<SphereRenderPositionNormalUvVertex> SphereRenderSceneRenderer::sceneModelVertices(const SphereRenderModel &model, const SphereRenderSubmesh &part, const SferaVec3F *pulledCamera,
                                                                                                       bool vegetation)
{
    auto vertices = SphereRenderSceneRenderer::sceneDevice().model_vertices.lock(part.vertex_count);
    for (std::size_t index = 0u; index < part.vertex_count; ++index)
    {
        const auto absolute = part.first_vertex + index;
        const auto &source = model.vertices[absolute];
        auto &vertex = vertices[index];
        vertex = {source.position, source.normal, source.u, source.v};
        if (vegetation && !model.cached_vegetation_vertices.empty())
        {
            const auto &cached = model.cached_vegetation_vertices[absolute];
            vertex.position = cached.position;
            if (model.vegetation_kind == SphereRenderVegetationKind::Grass)
                vertex.normal = cached.normal;
        }
        else if (pulledCamera)
            vertex.position = vertex.position + (*pulledCamera - vertex.position) * 0.009999999776482582f;
    }
    vertices.unlock();
    return vertices;
}

void SphereRenderSceneRenderer::sceneDrawSubmesh(const SphereRenderModel &model, const SphereRenderSubmesh &part, const DynamicStreamMapping<SphereRenderPositionNormalUvVertex> &vertices,
                                                 DynamicStream<std::uint16_t> &indices, std::uint32_t flags)
{
    if (part.face_count > 1000u)
        SferaEngineDiagnostics::fail("MNO_INDICES_IN_PRIMITIVE exceed");
    const auto count = part.face_count * 3u;
    auto output = indices.lock(count);
    for (std::size_t face = 0; face < part.face_count; ++face)
    {
        const auto &source = model.faces[part.first_face + face].vertices;
        std::copy(std::begin(source), std::end(source), output.data() + face * 3u);
    }
    output.unlock();
    SphereRenderSceneRenderer::sceneDevice().drawBuffer(vertices.buffer(), D3DPT_TRIANGLELIST, flags, vertices.first(), part.vertex_count, output.buffer(), count, output.first(),
                                                        sizeof(SphereRenderPositionNormalUvVertex));
}

void SphereRenderSceneRenderer::drawModel(std::uint32_t handle)
{
    if (SceneSky::flare_visible != 0u)
        SceneSky::flare_visible = SphereWorldContactQuery::lineOfSight(handle);
    auto &object = *SferaSceneAccess::object(handle);
    auto &model = *SferaSceneAccess::model(object);
    SphereRenderModelPose::active_model = &model;
    if (object.extended() && !object.extended()->render_enabled)
        return;
    const bool linked = object.extended() && object.extended()->parent_object_handle != 0u;
    SphereRenderModelPose::current_frame = linked ? SphereRenderModelPose::attachment_transforms.at(object.extended()->parent_link_slot) : SferaMatrix4x4F::fromEuler(object.position, object.rotation);
    SphereRenderSceneRenderer::model_visibility = SphereRenderSceneRenderer::sceneClassifyModel(model, SphereRenderModelPose::current_frame);
    if (SphereRenderSceneRenderer::model_visibility == 0u)
        return;
    const auto camera = SphereRenderModelPose::current_frame.inverseTransformPoint(SferaSceneAccess::cameraObject()->position);
    SferaRestore sunColor(SphereRenderSceneRenderer::environment.sunColor);
    if (!linked)
    {
        SphereRenderSceneRenderer::sceneScaleSun(SphereRenderSceneRenderer::sceneUpdateFade(object, false));
        SphereRenderSceneRenderer::sceneDirectionalLight();
        activateObjectLights(handle);
        for (std::size_t index = 0u; index < g_sfera_light_runtime.candidate_count; ++index)
        {
            auto &light = g_sfera_light_runtime.render_candidates[index];
            light.position = SphereRenderModelPose::current_frame.inverseTransformPoint(light.position);
            const SferaVec3F radius{light.radius, light.radius, light.radius};
            light.bounds_min = light.position - radius;
            light.bounds_max = light.position + radius;
        }
    }
    classifyBone(model.root_bone);
    SphereRenderSceneRenderer::sceneWorldTransform(SphereRenderModelPose::current_frame);
    const auto distance = ((object.position) - (g_sfera_camera.frame_corners[0])).length<double, float>();
    float fade = 0.0f, remaining = 0.0f;
    modelFade(SferaNumeric::real32(model.relativeLod(distance)), model.lod_power, fade, remaining);
    if (object.lighting_color == 0u)
    {
        const auto tint = SferaColor::fromArgb(SphereRenderMaterial::randomColor(model.color_variation));
        object.lighting_color = tint.withAlpha(tint.alpha() | terrainShade(model.landscape_shadow_alpha, object.position.x, object.position.z)).argb();
    }
    std::uint32_t lastTexture = 0u;
    for (std::size_t index = 0u; index < model.submeshes.size(); ++index)
    {
        const auto &part = model.submeshes[index];
        const auto &visible = SphereRenderSceneRenderer::bone_visibility[part.bone_index];
        if (visible.resource == 0u)
            continue;
        const float opacity = part.inverted_fade ? remaining : fade;
        const bool fading = opacity > 9.99999993922529e-09 && 1.0 - opacity > 9.99999993922529e-09;
        if (opacity < 9.99999993922529e-09)
            continue;
        if (SphereRenderSceneRenderer::shadow_projection_opacity != 0u)
            g_sfera_shadows->projectModel(model, index, &SphereRenderModelPose::current_frame);
        const auto &bone = model.bones[part.bone_index];
        const bool pulled = bone.name.starts_with("_z");
        const bool alphaTest = (bone.name.starts_with("_s") || bone.name.starts_with("_u") || bone.name.starts_with("_c"));
        const auto *material = part.material;
        if (!material)
            throw std::out_of_range("Model material index");
        SphereRenderSceneRenderer::sceneMaterialAmbient(*material);
        const auto lighting = SferaColor::fromArgb(object.lighting_color);
        const auto shade = lighting.alpha();
        if (material->hasColorVariation || object.ownsModel())
        {
            const auto shaded = lighting.scaledRgb(shade, 256u);
            setMaterialColor(shaded.red(), shaded.green(), shaded.blue());
        }
        else
            setMaterialColor(shade, shade, shade);
        SphereRenderSceneRenderer::sceneSelectLights(visible.mask);
        const std::uint32_t texture = material->textures.at(0u);
        if (texture != lastTexture)
        {
            bindTexture(texture);
            lastTexture = texture;
        }
        auto vertices = SphereRenderSceneRenderer::sceneModelVertices(model, part, pulled ? &camera : nullptr, true);
        std::uint32_t flags = CD3D9Devicelighting | (SphereRenderSceneRenderer::secondary_pass == 0u && visible.resource == 2u ? 1u : 0u) | (alphaTest ? 4u : 0u);
        if (fading)
            SphereRenderSceneRenderer::sceneRenderState(D3DRS_ALPHAREF, SferaNumeric::truncatedWord((1.0 - opacity) * 127.0) + 128u);
        else if (alphaTest)
            SphereRenderSceneRenderer::sceneRenderState(D3DRS_ALPHAREF, 128u);
        SphereRenderSceneRenderer::sceneDrawSubmesh(model, part, vertices, SphereRenderSceneRenderer::sceneDevice().indices_primary, flags);
        if (fading || alphaTest)
            SphereRenderSceneRenderer::sceneRenderState(D3DRS_ALPHAREF, 1u);
    }
    setMaterialColor(255, 255, 255);
    if (!linked)
    {
        sunColor.restore();
        SphereRenderSceneRenderer::sceneDisableLights(__LINE__);
    }
}

void SphereRenderSceneRenderer::drawObject(std::uint32_t handle)
{
    const ShadowMapPass shadowPass(*g_sfera_shadows);
    const SferaRestore projectionOpacity(shadow_projection_opacity);
    if (SceneSky::flare_visible != 0u && handle != SferaSceneAccess::controlledHandle())
        SceneSky::flare_visible = SphereWorldContactQuery::lineOfSight(handle);
    auto &object = *SphereRenderCharacterModels::checkedExtended(SferaSceneAccess::object(handle));
    auto &model = *SferaSceneAccess::model(object);
    SphereRenderModelPose::active_model = &model;
    if (!object.render_enabled)
        return;
    SphereRenderModelPose::current_frame = SferaMatrix4x4F::fromEuler(object.position, object.rotation);
    SphereRenderSceneRenderer::model_visibility = SphereRenderSceneRenderer::sceneClassifyModel(model, SphereRenderModelPose::current_frame);
    if (SphereRenderSceneRenderer::model_visibility == 0u)
        return;
    const auto distance = ((object.position) - (g_sfera_camera.frame_corners[0])).length<double, float>();
    SphereRenderModelPose::inverted_fade_pass = model.relativeLod(distance) < 0.20000000298023224;
    SferaRestore sunColor(SphereRenderSceneRenderer::environment.sunColor);
    SferaRestore sunDirection(SphereRenderSceneRenderer::sun_direction);
    const float fade = SphereRenderSceneRenderer::sceneUpdateFade(object, true);
    SphereRenderSceneRenderer::sceneScaleSun(fade);
    if (fade < 0.009999999776482582)
    {
        auto &direction = SphereRenderSceneRenderer::sun_direction;
        direction.x = 1.0f;
        direction.y = 0.0f;
        direction.z = 0.0f;
        const float fallback_angle = SferaNumeric::real32(object.rotation.x + 1.1693706972350526);
        SferaVec3F::rotatePair(direction.x, direction.z, fallback_angle);
        const float fallback = SferaNumeric::real32(45.0 - fade * 4500.0);
        auto &color = SphereRenderSceneRenderer::environment.sunColor;
        color.x = fallback;
        color.y = fallback;
        color.z = fallback;
    }
    SphereRenderSceneRenderer::sceneDirectionalLight();
    activateObjectLights(handle);
    const bool shadow = handle != SferaSceneAccess::controlledHandle() && g_sfera_shadows->quality < 4u && object.scale == 1.0f;
    if (shadow)
        g_sfera_shadows->selectObjectLight(object);
    SphereRenderModelPose::updateBone(SphereRenderModelPose::current_frame, model.root_bone);
    object.effect_frame_position_a = SphereRenderModelPose::translation;
    object.effect_frame_position_b = SphereRenderModelPose::attachment_101_position;
    float extension = 0.0f;
    const float originalShadowScale = model.shadow_scale;
    const SferaRestore shadowScale(model.shadow_scale);
    if (shadow)
    {
        const auto shadowDistance = ((SferaSceneAccess::cameraObject()->position) - (object.position)).length<double, float>();
        const bool distant = shadowDistance > 15.0f;
        const float offset = SferaNumeric::real32(shadowDistance - 15.0);
        const float fade_opacity = SferaNumeric::real32(1.0 - offset / 30.0);
        const float opacity = distant ? std::max(0.0f, fade_opacity) : 1.0f;
        SphereWorldContactQuery::updateBounds(handle);
        extension = g_sfera_shadows->projectionExtension(object);
        const double original_scale = originalShadowScale;
        model.shadow_scale = SferaNumeric::real32(1.4900000095367432 / (original_scale + extension));
        g_sfera_shadows->prepareModel(object, nullptr, opacity, distant ? 1u : 0u);
    }
    auto &device = SphereRenderSceneRenderer::sceneDevice();
    if (object.scale != 1.0f)
    {
        device.setWhiteMaterial(object.scale);
        device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
    }
    setObjectMaterial(object, model.landscape_shadow_alpha, model.color_variation);
    std::uint32_t lastTexture = 0u;
    for (std::size_t index = 0u; index < model.submeshes.size(); ++index)
    {
        const auto &part = model.submeshes[index];
        const auto bone = part.bone_index;
        if (part.inverted_fade != (SphereRenderModelPose::inverted_fade_pass))
            continue;
        const auto slot = model.bones[bone].animation().attachment_slot;
        if (handle == SferaSceneAccess::controlledHandle() && (slot == 102u || slot == 103u))
            continue;
        SphereRenderSceneRenderer::sceneWorldTransform(SphereRenderModelPose::bone_transforms.at(bone));
        g_sfera_shadows->projectModel(model, index);
        const auto *material = part.material;
        if (!material)
            throw std::out_of_range("Model material index");
        SphereRenderSceneRenderer::sceneMaterialAmbient(*material);
        const std::uint32_t texture = material->textures.at(object.render_cache_handle);
        if (texture != lastTexture)
        {
            bindTexture(texture);
            lastTexture = texture;
        }
        auto vertices = SphereRenderSceneRenderer::sceneModelVertices(model, part, nullptr, false);
        const auto flags = CD3D9Devicelighting | (SphereRenderSceneRenderer::secondary_pass == 0u && SphereRenderSceneRenderer::model_visibility == 2u ? 1u : 0u);
        SphereRenderSceneRenderer::sceneDrawSubmesh(model, part, vertices, device.indices_secondary, flags);
    }
    setMaterialColor(255, 255, 255);
    if (object.scale != 1.0f)
    {
        D3DMATERIAL9 reset{};
        reset.Diffuse = {1.0f, 1.0f, 1.0f, 1.0f};
        reset.Ambient = {1.0f, 1.0f, 1.0f, 0.0f};
        device.checkResult(device.native_device->SetMaterial(&reset), "SetMaterial");
        device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    }
    setOpacity(1u);
    for (const auto linked : object.linked_objects)
        if (linked != 0u)
            drawModel(linked);
    sunColor.restore();
    sunDirection.restore();
    setOpacity(0u);
    if (shadow)
    {
        ShadowMap::drawObject(object, originalShadowScale, extension);
    }
    SphereRenderSceneRenderer::sceneDisableLights(__LINE__);
}

float SphereRenderSceneRenderer::lightDistanceKey(const SferaLightRecord *light)
{
    return std::fabs(light->viewer_distance_squared);
}

std::size_t SphereRenderSceneRenderer::objectOrderKey(const SphereRenderSceneSortEntry &entry)
{
    return entry.key;
}

std::uint32_t SphereRenderSceneRenderer::ambientChannel(double material, float ambient)
{
    const int value = SferaNumeric::truncateInt(material + ambient);
    return std::min(255, value) & 255u;
}

EnvironmentLighting SphereRenderSceneRenderer::environment{};

SferaVec3F SphereRenderSceneRenderer::sun_direction{};

bool SphereRenderSceneRenderer::interior_scene{};

uint32_t SphereRenderSceneRenderer::visible_character_parts{};

uint32_t SphereRenderSceneRenderer::terrain_texture{};

float SphereRenderSceneRenderer::reflection_distance{};

float SphereRenderSceneRenderer::view_distance{};

SferaFrustumF SphereRenderSceneRenderer::frustum{};

uint32_t SphereRenderSceneRenderer::shadow_projection_opacity{};

uint32_t SphereRenderSceneRenderer::model_visibility{};

float SphereRenderSceneRenderer::reflection_height{};

bool SphereRenderSceneRenderer::use_default_environment{};

SphereRenderSferaRenderLookupEntry SphereRenderSceneRenderer::bone_visibility[256]{};

int SphereRenderSceneRenderer::texture_animation_frame{};

uint32_t SphereRenderSceneRenderer::secondary_pass{};

SferaIntBounds3 SphereRenderSceneRenderer::projected_terrain_bounds{};

SferaIntBounds3 SphereRenderSceneRenderer::clipped_terrain_bounds{};

uint8_t SphereRenderSceneRenderer::color_remap[256]{};

uint32_t SphereRenderSceneRenderer::fog_adaptation_delay{};

std::unique_ptr<SphereRenderCharacterModels> SphereRenderSceneRenderer::characters{};

std::unique_ptr<EnvironmentZones> SphereRenderSceneRenderer::environment_zones{};

std::unique_ptr<EnvironmentZones> SphereRenderSceneRenderer::alternate_environment_zones{};

std::vector<SphereRenderSceneSortEntry> SphereRenderSceneRenderer::object_order;

bool SphereRenderSceneRenderer::effectVisible(const IEffect &effect, const SferaVec3F &position)
{
    const SferaVec3F minimum{position.x + effect.bounds_min[0], position.y + effect.bounds_min[1], position.z + effect.bounds_min[2]};
    const SferaVec3F maximum{position.x + effect.bounds_max[0], position.y + effect.bounds_max[1], position.z + effect.bounds_max[2]};
    for (const auto &plane : frustum.planes)
    {
        bool all_outside = true;
        for (std::uint32_t corner = 0u; corner < 8u; ++corner)
        {
            const float x = (corner & 1u) != 0u ? maximum.x : minimum.x, y = (corner & 2u) != 0u ? maximum.y : minimum.y, z = (corner & 4u) != 0u ? maximum.z : minimum.z;
            if (x * plane.normal.x + y * plane.normal.y + z * plane.normal.z + plane.distance >= 0.0f)
            {
                all_outside = false;
                break;
            }
        }
        if (all_outside)
            return false;
    }
    return true;
}
