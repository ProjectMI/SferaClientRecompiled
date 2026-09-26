#pragma once

#include <windows.h>
#include <array>
#include <cstddef>
#include <cstdint>
#include <d3d9types.h>
#include <memory>
#include <vector>

struct EnvironmentLighting;
class EnvironmentZones;
class SphereRenderCharacterModels;
struct SphereRenderPositionNormalUvVertex;

class CD3D9Device;
template <class Element> class DynamicStream;
template <class Element> class DynamicStreamMapping;
class IEffect;
struct SferaFrustumF;
struct SferaIntBounds3;
struct SferaLightRecord;
struct SferaMatrix4x4F;
struct SferaVec3F;
struct SphereRenderMaterial;
class SphereRenderModel;
class SphereRenderSceneRenderer;
struct SphereRenderSceneRendererPassRestore;
struct SphereRenderSceneSortEntry;
struct SphereRenderSferaRenderLookupEntry;
struct SphereRenderSubmesh;
struct WorldObject;

struct SphereRenderSferaRenderLookupEntry
{
    uint32_t resource;
    uint32_t mask;
};

struct SphereRenderSceneSortEntry
{
    std::uint32_t object;
    std::size_t key;
    float distance;
};

class SphereRenderSceneRenderer
{
  public:
    static EnvironmentLighting environment;
    static SferaVec3F sun_direction;
    static bool interior_scene;
    static uint32_t visible_character_parts;
    static uint32_t terrain_texture;
    static float reflection_distance;
    static float view_distance;
    static SferaFrustumF frustum;
    static uint32_t shadow_projection_opacity;
    static uint32_t model_visibility;
    static float reflection_height;
    static bool use_default_environment;
    static SphereRenderSferaRenderLookupEntry bone_visibility[256];
    static int texture_animation_frame;
    static uint32_t secondary_pass;
    static SferaIntBounds3 projected_terrain_bounds;
    static SferaIntBounds3 clipped_terrain_bounds;
    static uint8_t color_remap[256];
    static uint32_t fog_adaptation_delay;
    static std::unique_ptr<SphereRenderCharacterModels> characters;
    static std::unique_ptr<EnvironmentZones> environment_zones;
    static std::unique_ptr<EnvironmentZones> alternate_environment_zones;

    static bool effectVisible(const IEffect &effect, const SferaVec3F &position);
    static std::vector<SphereRenderSceneSortEntry> object_order;

    static bool bindTexture(int texture);
    static void textureSize(int texture, std::uint32_t *dimensions);
    static void setAmbientColor();
    static void setMaterialColor(int red, int green, int blue);
    static void setObjectMaterial(WorldObject &object, std::uint32_t shade, const std::array<float, 3> &variation);
    static std::uint32_t terrainShade(std::uint32_t shade, float x, float z);
    static void buildColorRemap(double exponent, double floor);
    static void modelFade(float distance, float power, float &fade, float &remaining);
    static std::uint32_t materialVariant(std::uint32_t first, std::uint32_t second, std::uint32_t third)
    {
        return 4u * first + 2u * second + third;
    }
    static bool hasMaterialVariant(std::uint32_t object, int variant);
    static void setMaterialVariant(std::uint32_t object, int variant);
    static std::uint32_t setOpacity(std::uint32_t opacity)
    {
        return SphereRenderSceneRenderer::shadow_projection_opacity = opacity & 255u;
    }
    static void adaptFog();
    static void raiseDistantObject(std::uint32_t object);
    static void collectLights();
    static void activateObjectLights(std::uint32_t object);
    static void classifyBone(std::size_t bone);
    static void drawModel(std::uint32_t handle);
    static void drawObject(std::uint32_t handle);
    static void drawObjects(bool updateVegetation);
    static CD3D9Device &sceneDevice();
    static void sceneRenderState(D3DRENDERSTATETYPE state, DWORD value);
    static std::uint32_t sceneColor(const SferaVec3F &color);

  private:
    static bool sceneBoundsOverlap(const SferaVec3F &minimum, const SferaVec3F &maximum, const SferaLightRecord &light);
    static std::size_t sceneAnimationFrame(SphereRenderModel &model, int animation, int frame);
    static void sceneWorldTransform(const SferaMatrix4x4F &world);
    static std::uint32_t sceneClassifyModel(const SphereRenderModel &model, const SferaMatrix4x4F &world);
    static float sceneUpdateFade(WorldObject &object, bool animated);
    static void sceneScaleSun(float amount);
    static void sceneDirectionalLight();
    static void sceneDisableLights(std::uint32_t sourceLine);
    static void sceneSelectLights(std::uint32_t mask);
    static void sceneMaterialAmbient(const SphereRenderMaterial &material);
    static DynamicStreamMapping<SphereRenderPositionNormalUvVertex> sceneModelVertices(const SphereRenderModel &model, const SphereRenderSubmesh &part, const SferaVec3F *pulledCamera,
                                                                                       bool vegetation);
    static void sceneDrawSubmesh(const SphereRenderModel &model, const SphereRenderSubmesh &part, const DynamicStreamMapping<SphereRenderPositionNormalUvVertex> &vertices,
                                 DynamicStream<std::uint16_t> &indices, std::uint32_t flags);

  private:
    static float lightDistanceKey(const SferaLightRecord *light);
    static std::size_t objectOrderKey(const SphereRenderSceneSortEntry &entry);
    static std::uint32_t ambientChannel(double material, float ambient);
};

struct SphereRenderSceneRendererPassRestore
{
    std::uint32_t previous;
    ~SphereRenderSceneRendererPassRestore();
};
