#include <windows.h>
#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <format>
#include <iterator>
#include <memory>
#include <span>
#include <string>
#include <utility>

#include "animation/Animation.h"
#include "application/ClientApplication.h"
#include "binary/Binary.h"
#include "camera/Camera.h"
#include "collision/Collision.h"
#include "config/InterfaceConfiguration.h"
#include "diagnostics/ClientDiagnostics.h"
#include "diagnostics/Diagnostics.h"
#include "effects/EffectManager.h"
#include "effects/NatureManager.h"
#include "environment/Environment.h"
#include "gameplay/ActorMotion.h"
#include "geometry/Geometry.h"
#include "graphics/d3d9/Device.h"
#include "lighting/LightRuntime.h"
#include "math/MathFunctions.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/CharacterRenderer.h"
#include "render/GameRendering.h"
#include "render/GraphicsRuntime.h"
#include "render/Material.h"
#include "render/Model.h"
#include "render/SceneRenderer.h"
#include "runtime/Clock.h"
#include "scene/SceneObject.h"
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"
#include "shadows/Shadows.h"
#include "terrain/Terrain.h"
#include "text/Text.h"
#include "ui/ScriptInterface.h"
#include "vegetation/Vegetation.h"
#include "world/ServerGeometry.h"
#include "world/WorldObjects.h"

bool SphereRenderGameCamera::projectObjectTop(std::uint32_t handle, SferaVec3F &output, float height_factor) const
{
    const auto *object = g_sfera_world_objects.object(handle);
    if (object == nullptr)
    {
        WorldDiagnostics::message.clear();
        WorldDiagnostics::appendScriptContext("Project_TopCharToScreen: wrong handle");
        WorldDiagnostics::flushScriptContext();
        return false;
    }
    const auto *model = g_sfera_world_objects.model(*object);
    const auto *camera = g_sfera_world_objects.object(1u);
    if (model == nullptr || camera == nullptr)
        return false;
    SferaVec3F top = object->position;
    const double height = top.y;
    top.y = SferaNumeric::real32(height + (model->collision_kind == SphereRenderCollisionKind::AxisAlignedBounds ? model->minimum.y : model->oriented_corners.corners[0].y));
    auto offset = top - camera->position;
    offset.y = 0.0f;
    const float squared = SferaNumeric::real32(SferaMath::planarSquared(offset.z, offset.x));
    const float scale = SferaNumeric::real32(0.10000000149011612 / squared);
    offset = offset * scale;
    const auto base = object->position - offset;
    if (top.y < camera->position.y)
        offset = {-offset.x, -offset.y, -offset.z};
    top = top + offset;
    SferaVec3F projected_top{}, projected_base{};
    const bool top_visible = project(top, projected_top);
    if (height_factor == 1.0f)
    {
        output = projected_top;
        return top_visible;
    }
    const bool base_visible = project(base, projected_base);
    if (!top_visible || !base_visible)
        return false;
    output = projected_base + (projected_top - projected_base) * height_factor;
    return true;
}

void SphereRenderGameCamera::cameraAxes(SferaVec3F &forward, SferaVec3F &up)
{
    g_sfera_world_objects.recalculateBasis(1u);
    const auto *camera = g_sfera_world_objects.extendedObject(1u);
    if (camera == nullptr)
        WorldDiagnostics::fail("Camera object is missing");
    forward = camera->orientation_basis[0];
    up = camera->orientation_basis[1];
}

void SphereRenderGameCamera::rebuildVisibleVolume(std::uint32_t left, std::uint32_t top, std::uint32_t right, std::uint32_t bottom)
{
    const SphereRenderCameraRectangle rectangle{left, top, right, bottom};
    const SferaFrustumF *frustum = nullptr;
    const SferaVec3F *points = nullptr;
    g_sfera_camera.volume(&rectangle, &frustum, &points);
    if (frustum == nullptr || points == nullptr)
        return;
    SphereRenderSceneRenderer::frustum = *frustum;
    std::copy_n(points, 5u, g_sfera_camera.frame_corners);
    SferaVec3F minimum = points[0], maximum = points[0];
    for (std::size_t index = 1u; index < 5u; ++index)
        for (std::size_t axis = 0u; axis < 3u; ++axis)
        {
            minimum.setComponent(axis, std::min(minimum.component(axis), points[index].component(axis)));
            maximum.setComponent(axis, std::max(maximum.component(axis), points[index].component(axis)));
        }

    SphereRenderSceneRenderer::projected_terrain_bounds = {fixedVolumeCoordinate(minimum.x), fixedVolumeCoordinate(maximum.x), fixedVolumeCoordinate(minimum.y),
                                                           fixedVolumeCoordinate(maximum.y), fixedVolumeCoordinate(minimum.z), fixedVolumeCoordinate(maximum.z)};
    SphereRenderSceneRenderer::collectLights();
}

bool SferaGameCameraPolicy::character_selection_active()
{
    const auto &runtime = g_sfera_mbc_runtime;
    int process_index = runtime.process_chain_first;
    std::size_t visited = 0;
    while (process_index >= 0 && visited++ < std::size(runtime.processes))
    {
        if (static_cast<std::size_t>(process_index) >= std::size(runtime.processes))
            break;
        const auto &process = runtime.processes[process_index];
        if (process.chain_prev_index < 0)
            break;
        const auto active = std::find_if(process.programs.begin(), process.programs.end(), &SferaGameCameraPolicy::activeCharacterSelection);
        if (active != process.programs.end())
            return true;
        if (process_index == runtime.process_chain_last)
            break;
        const int next = process.chain_next_index;
        if (next < 0 || next == process_index)
            break;
        process_index = next;
    }
    return false;
}

float SferaGameCameraPolicy::scene_field_of_view(double width, double height)
{
    if (SferaGameCameraPolicy::character_selection_active())
        return SferaMath::fittedFieldOfView(width, height);
    return SferaMath::fittedFieldOfView(width, height, g_sfera_graphics_runtime.field_of_view_degrees);
}

bool SferaGameCameraPolicy::activeCharacterSelection(const ScriptProgramDiagnostic &program)
{
    return program.state > 0 && program.name == "SelChar";
}

SferaVec3F &SferaGameSceneRenderer::observerPosition(SferaVec3F &output)
{
    const auto *camera = g_sfera_world_objects.object(1u);
    if (camera == nullptr)
    {
        WorldDiagnostics::fail(
            std::format("Scene observer: camera object 1 is missing (controlled={}, mode={})", g_sfera_world_objects.controlled_object_handle, g_sfera_camera.controlled_observer_mode));
    }
    const auto *controlled = g_sfera_camera.controlled_observer_mode != 0u ? g_sfera_world_objects.controlledObject() : nullptr;
    output = (controlled != nullptr ? controlled : camera)->position;
    return output;
}

void SferaGameSceneRenderer::setupEnvironment(std::uint32_t mode, bool useDefault, float time)
{
    SphereRenderSceneRenderer::environment = {};
    SphereRenderSceneRenderer::sun_direction = {};
    g_sfera_terrain_renderer.patch_origin.x = 0.0f;
    SferaVec3F position{};
    observerPosition(position);
    SphereRenderSceneRenderer::interior_scene = !useDefault && position.y > 1000.0f;
    float fieldOfView;
    if (mode == 2u)
        fieldOfView = 0.03490658950558778f;
    else
    {
        if (g_sfera_graphics_runtime.display_width <= 0 || g_sfera_graphics_runtime.display_height <= 0)
            WorldDiagnostics::fail("Invalid display size for camera projection");
        fieldOfView = SferaGameCameraPolicy::scene_field_of_view(g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height);
    }
    const float nearPlane = mode == 2u ? 997.0f : 0.10000000149011612f;
    float farPlane;
    if (SphereRenderSceneRenderer::interior_scene)
    {
        farPlane = mode == 2u ? 1005.0f : 80.0f;
        SphereRenderSceneRenderer::environment.fogParameters.y = SferaNumeric::real32(farPlane - 20.0);
        SphereRenderSceneRenderer::environment.fogParameters.z = farPlane;
        SphereRenderSceneRenderer::environment.sunColor = {59.0f, 37.0f, 12.0f};
        SphereRenderSceneRenderer::environment.ambientColor = {19.0f, 47.0f, 71.0f};
        const float length = SferaNumeric::real32(std::sqrt(14.0));
        SphereRenderSceneRenderer::sun_direction.x = SferaNumeric::real32(1.0 / length);
        SphereRenderSceneRenderer::sun_direction.y = SferaNumeric::real32(-3.0 / length);
        SphereRenderSceneRenderer::sun_direction.z = SferaNumeric::real32(2.0 / length);
    }
    else
    {
        const float halfAngle = SferaNumeric::real32(fieldOfView * 0.5);
        const double radians = halfAngle;
        const float cosine = SferaNumeric::real32(std::cos(radians));
        const double directionScale = cosine;
        farPlane = SferaNumeric::real32(directionScale * SphereRenderSceneRenderer::view_distance);
        const bool alternate = SphereWorldVegetation::alternatePatterns();
        const auto *sky = (alternate && SceneSky::high_resolution_environment) ? SceneSky::high_resolution_environment.get() : SceneSky::environment.get();
        auto *zones = (alternate && SphereRenderSceneRenderer::alternate_environment_zones) ? SphereRenderSceneRenderer::alternate_environment_zones.get()
                                                                                            : SphereRenderSceneRenderer::environment_zones.get();
        if (sky == nullptr || zones == nullptr)
            WorldDiagnostics::fail("Environment assets are not loaded");
        sky->sunDirection(time, SphereRenderSceneRenderer::sun_direction);
        zones->calculate(useDefault, position.x, position.z, time, *sky, SphereRenderSceneRenderer::environment);
    }
    if (SphereRenderSceneRenderer::environment.fogParameters.z > farPlane)
    {
        SphereRenderSceneRenderer::environment.fogParameters.z = farPlane;
        if (SphereRenderSceneRenderer::environment.fogParameters.y + 20.0 > SphereRenderSceneRenderer::environment.fogParameters.z)
        {
            const float nearFog = SferaNumeric::real32(SphereRenderSceneRenderer::environment.fogParameters.z - 20.0);
            SphereRenderSceneRenderer::environment.fogParameters.y = std::max(0.0f, nearFog);
        }
    }
    g_sfera_camera.setPerspective(nearPlane, farPlane, fieldOfView);
}

void SferaGameSceneRenderer::drawFrame()
{
    if (!SferaClientApplication::application_active)
    {
        if (!SferaClientApplication::windowed)
            return;
        ::Sleep(100u);
    }
    const auto timestamp = WorldClock::nowTicks();
    auto &previous = g_sfera_vegetation.last_frame_ticks;
    SferaClientApplication::frame_elapsed_ticks = SferaNumeric::lowWord(timestamp) - SferaNumeric::lowWord(previous);
    previous = timestamp;
    SphereRenderSceneRenderer::view_distance = g_sfera_graphics_runtime.auto_fog ? g_sfera_graphics_runtime.saved_fog_distance : g_sfera_graphics_runtime.fog_distance;
    if (SphereRenderSceneRenderer::interior_scene != 0u)
        drawMinimap();
    setupEnvironment(0u, SphereRenderSceneRenderer::use_default_environment, g_sfera_graphics_runtime.environment_factor);
    if (g_sfera_graphics_runtime.reflection_quality > 0u)
        drawReflection();
    auto &device = SphereRenderSceneRenderer::sceneDevice();
    SceneScope scene(device);
    if (scene)
    {
        const bool postEffects = device.supports_post_effects && g_sfera_graphics_runtime.post_effects_enabled;
        if (postEffects)
        {
            device.post_effects->setEnabled(true);
            device.post_effects->beginCapture();
        }
        {
            SphereRenderGameCameraFrame camera(0u, false, 0.0f);
            drawPass(0u);
            GameInterface::setRenderState();
            SphereRenderSceneRenderer::sceneRenderState(D3DRS_ZENABLE, TRUE);
            SphereRenderSceneRenderer::sceneRenderState(D3DRS_ZWRITEENABLE, TRUE);
            GameInterface::drawAll();
            SphereRenderSceneRenderer::sceneRenderState(D3DRS_ZENABLE, FALSE);
            SphereRenderSceneRenderer::sceneRenderState(D3DRS_ZWRITEENABLE, FALSE);
            if (postEffects)
                device.post_effects->compose();
            GameInterface::drawFullscreenOverlay();
            GameInterface::drawFrame();
        }
        scene.finish();
        device.waitForGpu();
        device.present();
    }
    if (SphereRenderSceneRenderer::characters)
        SphereRenderSceneRenderer::characters->updateLodDistance();
}

SphereRenderGameCameraFrame::SphereRenderGameCameraFrame(std::uint32_t mode, bool reflection, float water_height)
{
    auto *camera = g_sfera_world_objects.extendedObject(1u);
    if (camera == nullptr)
        WorldDiagnostics::fail("Camera object is missing");
    auto *controlled = g_sfera_world_objects.controlledObject();
    if (g_sfera_camera.controlled_observer_mode != 0u && controlled != nullptr)
    {
        SferaVec3F neck;
        SphereRenderModelPose::neckPosition(neck);
        const float heading = controlled->rotation.x;
        camera->position = {controlled->position.x, neck.y - 0.10000000149011612f, controlled->position.z};
        g_sfera_world_objects.recalculateBasis(1u);
        const float lean = camera->orientation_basis[0].y * 0.30000001192092896f;
        controlled_handle_ = g_sfera_world_objects.controlled_object_handle;
        controlled_position_ = controlled->position;
        controlled->position.x = (controlled->position.x - neck.x) + controlled->position.x;
        controlled->position.z = (controlled->position.z - neck.z) + controlled->position.z;
        if (lean > 0.0f)
        {
            controlled->position.x = controlled->position.x + std::sin(heading) * lean;
            controlled->position.z = controlled->position.z - std::cos(heading) * lean;
        }
        else
            camera->position.y = SferaNumeric::real32(camera->position.y - lean * 0.20000000298023224);
    }

    if (reflection)
    {
        saveCameraState(camera);
        const double precise_water_height = water_height;
        camera->position.y = SferaNumeric::real32((water_height + precise_water_height) - camera->position.y);
        g_sfera_world_objects.reflectReferenceOrientation();
    }
    if (mode == 2u)
    {
        saveCameraState(camera);
        if (controlled != nullptr)
            camera->position = controlled->position;
        camera->position.y = SferaNumeric::real32(camera->position.y - 1000.0);
        camera->rotation = {-4.7123894691467285f, 1.5707964897155762f, -1.5707964897155762f};
        g_sfera_world_objects.recalculateBasis(1u);
    }
}

SphereRenderGameCameraFrame::~SphereRenderGameCameraFrame() noexcept
{
    if (auto *controlled = g_sfera_world_objects.object(controlled_handle_))
        controlled->position = controlled_position_;
    if (restore_camera_)
        if (auto *camera = g_sfera_world_objects.object(1u))
        {
            camera->position = camera_position_;
            camera->rotation = camera_rotation_;
            g_sfera_world_objects.recalculateBasis(1u);
        }
}

void SphereRenderGameCameraFrame::saveCameraState(const ExtendedWorldObject *camera)
{
    camera_position_ = camera->position;
    camera_rotation_ = camera->rotation;
    restore_camera_ = true;
}

void SferaGameSceneRenderer::sceneUnderwaterOverlay()
{
    const auto handle = g_sfera_world_objects.controlled_object_handle;
    std::uint32_t materialIndex = 0u;
    if (handle == UINT32_MAX || g_sfera_motion.surfaceInteraction(handle, &materialIndex) != 5u)
        return;
    const auto width = g_sfera_graphics_runtime.display_width;
    const auto height = g_sfera_graphics_runtime.display_height;
    constexpr double textureScale = 0.20000000298023224;
    auto &x = SceneSky::horizontal_motion;
    auto &y = SceneSky::vertical_motion;
    if (x < 0.0f)
        x = SferaNumeric::real32(x + width / textureScale);
    if (x > width / textureScale)
        x = SferaNumeric::real32(x - width / textureScale);
    if (y < 0.0f)
        y = SferaNumeric::real32(y + height / textureScale);
    if (y > height / textureScale)
        y = SferaNumeric::real32(y - height / textureScale);
    const float width_pixels = SferaNumeric::real32(width), height_pixels = SferaNumeric::real32(height);
    const double offset_x = x, offset_y = y;
    const float u = SferaNumeric::real32(-offset_x / width_pixels * textureScale);
    const float v = SferaNumeric::real32(-offset_y / height_pixels * textureScale);
    const float right = SferaNumeric::real32(u + textureScale);
    const float bottom = SferaNumeric::real32(v + textureScale);
    const float uv[] = {u, v, right, v, right, bottom, u, bottom};
    const auto &material = g_sfera_graphics_runtime.water_materials.at(materialIndex);
    std::string texture = "ww1_00";
    const auto animation = SphereRenderSceneRenderer::texture_animation_frame / 2;
    texture[2] = std::bit_cast<char>(SferaNumeric::lowByte(material.primary_animation + '0'));
    texture[4] = std::bit_cast<char>(SferaNumeric::lowByte(animation / 10 + '0'));
    texture[5] = std::bit_cast<char>(SferaNumeric::lowByte(animation % 10 + '0'));
    const auto heightFactor = std::fabs(SphereRenderSceneRenderer::sun_direction.y);
    const auto sun = SphereRenderSceneRenderer::environment.sunColor;
    const auto ambient = SphereRenderSceneRenderer::environment.ambientColor;
    GameInterface::tintTexture(0, 0, width, height, texture, SferaNumeric::lowByte(underwaterChannel(heightFactor, sun.x, ambient.x)),
                               SferaNumeric::lowByte(underwaterChannel(heightFactor, sun.y, ambient.y)), SferaNumeric::lowByte(underwaterChannel(heightFactor, sun.z, ambient.z)),
                               SferaNumeric::word(SferaNumeric::truncateInt(material.primary_opacity * 255.0)), uv);
}

void SferaGameSceneRenderer::drawPass(std::uint32_t mode)
{
    auto &device = SphereRenderSceneRenderer::sceneDevice();
    const auto width = mode == 1u || mode == 2u ? 256u : g_sfera_graphics_runtime.display_width;
    const auto height = mode == 1u || mode == 2u ? 256u : g_sfera_graphics_runtime.display_height;
    SphereRenderGameCamera::setupViewport(0u, 0u, width, height);
    device.checkResult(device.native_device->Clear(0u, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0u), "Clear");
    const float fogStart = mode == 2u ? g_sfera_camera.far_distance - 1.0f : SphereRenderSceneRenderer::environment.fogParameters.y;
    const float fogEnd = mode == 2u ? g_sfera_camera.far_distance : SphereRenderSceneRenderer::environment.fogParameters.z;
    SphereRenderSceneRenderer::sceneRenderState(D3DRS_FOGSTART, SferaBinary::floatBits(fogStart));
    SphereRenderSceneRenderer::sceneRenderState(D3DRS_FOGEND, SferaBinary::floatBits(fogEnd));
    SphereRenderSceneRenderer::setAmbientColor();
    if (mode == 0u)
    {
        SferaNatureManager::updateRain();
        SferaNatureManager::updateLightning();
    }
    SphereRenderSceneRenderer::sceneRenderState(D3DRS_FOGENABLE, FALSE);
    if ((SphereRenderSceneRenderer::interior_scene == 0u && SferaClientApplication::resources_loaded) || mode == 1u)
    {
        const float rotation = SferaNumeric::real32(SceneSky::drawStars());
        SceneSky::drawSunMoon(rotation);
        if (SphereWorldVegetation::alternatePatterns())
            SceneSky::drawLayers(g_sfera_weather_runtime.current.clouds);
        SceneSky::drawLayers(g_sfera_weather_runtime.current.sky);
    }
    else
        GameInterface::drawTexture(0, 0, g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height, "black", 255u, 0.0f, nullptr);
    device.checkResult(device.native_device->Clear(0u, nullptr, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0u), "Clear");
    SphereRenderSceneRenderer::sceneRenderState(D3DRS_FOGENABLE, TRUE);
    g_sfera_terrain_renderer.drawLandscape();
    SphereRenderSceneRenderer::sceneRenderState(D3DRS_FOGCOLOR, SphereRenderSceneRenderer::sceneColor(SphereRenderSceneRenderer::environment.fogColor));
    SphereRenderSceneRenderer::drawObjects(mode != 1u);
    if (mode != 0u)
        return;
    SphereRenderSceneRenderer::setAmbientColor();
    g_sfera_light_runtime.setDirectionalLight(SphereRenderSceneRenderer::sun_direction * -1.0f, SphereRenderSceneRenderer::environment.sunColor);
    g_sfera_terrain_renderer.drawWater();
    if (g_sfera_effect_manager.blood != nullptr)
        g_sfera_effect_manager.blood->render();
    SphereRenderSceneRenderer::sceneRenderState(D3DRS_FOGENABLE, FALSE);
    g_sfera_server_wall.generateEffects();
    g_sfera_effect_manager.renderParticles();
    g_sfera_effect_manager.drawFlare(SferaNumeric::truncateInt(SceneSky::flare_screen_position.x), SferaNumeric::truncateInt(SceneSky::flare_screen_position.y), 220, SceneSky::flare_visible != 0u);
    SferaGameSceneRenderer::sceneUnderwaterOverlay();
}

void SferaGameSceneRenderer::drawMinimap()
{
    setupEnvironment(2u, SphereRenderSceneRenderer::use_default_environment, g_sfera_graphics_runtime.environment_factor);
    auto &device = SphereRenderSceneRenderer::sceneDevice();
    SceneScope scene(device);
    if (!scene)
        return;
    {
        RenderStateScope state(device);
        RenderTargetScope target(device, *device.minimapTexture().native_texture.Get());
        SphereRenderGameCameraFrame camera(2u, false, 0.0f);
        drawPass(2u);
    }
    scene.finish();
}

void SferaGameSceneRenderer::drawReflection()
{
    if (SphereRenderSceneRenderer::interior_scene != 0u)
        return;
    SphereRenderSceneRenderer::reflection_height = 100000.0f;
    SphereRenderSceneRenderer::reflection_distance = 1000000.0f;
    g_sfera_terrain_renderer.gatherReflectiveWater();
    const float waterHeight = SphereRenderSceneRenderer::reflection_height;
    if (waterHeight > 99999.0f)
        return;
    auto &device = SphereRenderSceneRenderer::sceneDevice();
    SceneScope scene(device);
    if (!scene || !device.reflection_target || !device.reflection_target->native_texture)
        return;
    {
        RenderStateScope state(device);
        SphereRenderSceneRendererPassRestore pass{std::exchange(SphereRenderSceneRenderer::secondary_pass, 1u)};
        const float plane[] = {0.0f, -1.0f, 0.0f, waterHeight};
        device.checkResult(device.native_device->SetClipPlane(0u, plane), "SetClipPlane");
        SphereRenderSceneRenderer::sceneRenderState(D3DRS_CLIPPLANEENABLE, 1u);
        RenderTargetScope target(device, *device.reflection_target->native_texture.Get());
        SphereRenderGameCameraFrame camera(1u, true, waterHeight);
        drawPass(1u);
    }
    scene.finish();
}

int SferaGameSceneRenderer::underwaterChannel(float heightFactor, double light, float base)
{
    const int value = SferaNumeric::truncateInt(heightFactor * light + base);
    return std::min(255, value);
}

void ShadowMap::initialize(std::uint32_t default_quality)
{
    std::uint32_t value = default_quality;
    SphereUIInterfaceConfiguration::open("config.cfg");
    value = SphereUIInterfaceConfiguration::readInteger("SHAD", value);
    if (g_sfera_shadows == nullptr)
    {
        g_sfera_shadows = std::make_unique<ShadowMap>();
        g_sfera_shadows->createTextures();
        g_sfera_shadows->quality = SferaNumeric::lowByte(value);
    }
}

void CShaderMgr::setPixelShader(std::uint32_t group)
{
    if (group == 10u || group == 11u)
        return;
    if (group > 13u)
    {
        SferaEngineDiagnostics::fatal(("Unknown pixel shader group: " + std::to_string(group)));
        return;
    }

    std::pair<bool, std::array<std::uint8_t, 8>> code{true, {SferaNumeric::lowByte(group)}};
    if (group == 0u)
        code.second[3] = 1u;

    CShaderMgrVariant &variant = loadVariant(code);
    device.checkResult(device.native_device->SetPixelShader(variant.pixel_shader.Get()), "SetPixelShader");

    if (group == 3u)
        setFloatConstant(variant.alpha_register, 0.0f);
    if (group == 6u && variant.down_filter_register)
    {
        device.checkResult(device.native_device->SetPixelShaderConstantF(*variant.down_filter_register, downsample_offsets.data(), SferaNumeric::lowWord(downsample_offsets.size() / 4)),
                           "SetPixelShaderConstantF");
    }
    if (group == 1u)
    {
        const CShaderMgrWaterParameters water = waterParameters(g_sfera_graphics_runtime.environment_factor, SphereRenderSceneRenderer::sun_direction.y);
        setFloatConstant(variant.water_gradient_register, water.gradient);
        setFloatConstant(variant.water_specular_register, water.specular);
        setFloatConstant(variant.water_reflection_register, water.reflection);
    }
}

const SphereRenderCharacterAppearance &SphereRenderCharacterModels::appearance(const ExtendedWorldObject &object) const
{
    const auto index = -1 - object.render_cache_handle;
    if (index < 0 || index >= 400)
        WorldDiagnostics::fail("Invalid character instance");
    return instances[index].appearance;
}

int SphereRenderCharacterModels::partAnimationLength(const ExtendedWorldObject &object, int animation) const
{
    const auto &skeleton = skeletons[appearance(object).sex];
    return animation < 0 || std::cmp_greater_equal(animation, skeleton.animation_lengths.size()) ? -1 : skeleton.animation_lengths[animation];
}

std::uint32_t *SphereRenderCharacterModels::parameter(std::span<std::uint32_t> values, int index)
{
    if (index < 0 || index >= values.size())
        WorldDiagnostics::fail("Character parameter index is out of bounds");
    return &values[index];
}

ExtendedWorldObject *SphereRenderCharacterModels::checkedExtended(WorldObject *object)
{
    if (object == nullptr)
        return nullptr;
    if (auto *extended = object->extended())
        return extended;
    const auto *model = g_sfera_world_objects.model(*object);
    const auto message = std::string("Try to get extended from superstatic: ") + (model == nullptr ? "<none>" : model->name);
    WorldDiagnostics::fail(message);
}

void SphereRenderCharacterModels::setAppearance(int handle, const SphereRenderCharacterAppearance &value)
{
    if (handle < 0)
    {
        g_sfera_log_runtime.write("Wrong handle: set_char_param\n");
        return;
    }
    auto *object = checkedExtended(g_sfera_world_objects.object(handle));
    if (object == nullptr)
    {
        g_sfera_log_runtime.write("Wrong handle: set_char_param\n");
        return;
    }
    if (value.sex < 0 || std::cmp_greater_equal(value.sex, skeletons.size()))
        WorldDiagnostics::fail("Invalid character sex");
    if (object->render_cache_handle > 0)
        WorldDiagnostics::fail("Character model has a non-character render cache");
    if (object->render_cache_handle >= 0)
    {
        auto slot = std::find_if(std::begin(instances), std::end(instances), &SphereRenderCharacterModels::unusedCharacterSlot);
        if (slot == std::end(instances))
            WorldDiagnostics::fail("Character model instance limit reached");
        slot->owner = object;
        object->render_cache_handle = -1 - SferaNumeric::signedWord(SferaNumeric::lowWord(slot - instances.begin()));
    }
    auto &current = instances[-1 - object->render_cache_handle].appearance;
    if (value.parts[12] != 0u)
    {
        std::string name = "ms";
        name.append(SferaText::fromBytes(std::span(value.parts).subspan(12u, 1u)));
        g_sfera_world_objects.linkModel(handle, name, 3u);
    }
    else if (current.parts[12] != 0u)
        g_sfera_world_objects.unlink(handle, 3u);
    current = value;
}

bool SphereRenderCharacterModels::getAppearance(int handle, SphereRenderCharacterAppearance &value) const
{
    if (handle < 0)
    {
        g_sfera_log_runtime.write("Wrong handle: get_char_param\n");
        return false;
    }
    const auto *object = checkedExtended(g_sfera_world_objects.object(handle));
    if (object == nullptr || object->render_cache_handle >= 0)
        return false;
    value = appearance(*object);
    return true;
}

void SphereRenderCharacterModels::updateEffectFrames(ExtendedWorldObject &object, const SphereRenderCharacterSkeleton &skeleton, std::span<SferaMatrix4x4F> pose, const SferaMatrix4x4F &world) const
{
    auto &first = pose[skeleton.attachments[4]];
    first = (skeleton.initial_pose[skeleton.attachments[4]]).multiplied((first));
    object.effect_frame_position_a = world.transformPoint({first.m[3][0], first.m[3][1], first.m[3][2]});
    first.m[3][0] = first.m[3][1] = first.m[3][2] = 0.0f;
    auto firstFrame = (world).multiplied((first));
    firstFrame.m[0][3] = firstFrame.m[1][3] = firstFrame.m[2][3] = 0.0f;
    object.effect_frame_transform_a = firstFrame;
    auto &second = pose[skeleton.attachments[5]];
    second = (skeleton.initial_pose[skeleton.attachments[5]]).multiplied((second));
    object.effect_frame_position_b = world.transformPoint({second.m[3][0], second.m[3][1], second.m[3][2]});
    auto &attached = pose[skeleton.attachments[0]];
    object.effect_frame_position_c = world.transformPoint({attached.m[3][0], attached.m[3][1], attached.m[3][2]});
    attached.m[3][0] = attached.m[3][1] = attached.m[3][2] = 0.0f;
    attached = attached.transposed();
    auto attachmentFrame = (world).multiplied((attached));
    attachmentFrame.m[0][3] = attachmentFrame.m[1][3] = attachmentFrame.m[2][3] = 0.0f;
    object.effect_frame_transform_b = attachmentFrame;
    object.effect_frame_transform_c = attachmentFrame;
}
