#pragma once

#include <windows.h>
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include "animation/Animation.h"
#include "math/Matrix.h"
#include "math/Vector.h"

struct ExtendedWorldObject;
struct SphereRenderCharacterAppearance;
struct SphereRenderCharacterSlot;

struct SphereRenderCharacterAppearance
{
    int sex;
    std::uint8_t parts[16];
};

struct SphereRenderCharacterSlot
{
    ExtendedWorldObject *owner = nullptr;
    SphereRenderCharacterAppearance appearance{};
};

struct SphereRenderCharacterGeometry;
struct SphereRenderCharacterVertex;

struct SphereRenderCharacterVertex
{
    SferaVec3F position;
    SferaVec3F normal;
    float u;
    float v;
    std::size_t first_bone;
    std::size_t second_bone;
    float weight;
};

struct SphereRenderCharacterGeometry
{
    std::vector<SphereRenderCharacterVertex> vertices;
    std::vector<std::uint16_t> indices;
};

struct SphereRenderCharacterAsset;
struct SphereRenderCharacterPart;

struct SphereRenderCharacterAsset
{
    std::string name;
    std::size_t directory = 0;
    std::unique_ptr<SphereRenderCharacterGeometry> geometry;
};

struct SphereRenderCharacterPart
{
    std::size_t asset = 0;
    std::array<int, 20> textures{};
};

class SphereRenderCharacterModels;
struct WorldObject;

class SphereRenderCharacterModels
{
  public:
    float maximum_distance = 0.0f;
    float minimum_distance = 0.0f;
    SferaMatrix4x4F root_transform = SferaMatrix4x4F::identity();
    std::array<SferaVec3F, 8> bounds{};
    std::array<SphereRenderCharacterSkeleton, 2> skeletons;
    std::vector<std::string> directories;
    std::vector<SphereRenderCharacterAsset> assets;
    std::vector<SphereRenderCharacterPart> parts;
    std::array<std::array<std::array<std::optional<std::size_t>, 256>, 26>, 2> part_indices{};
    std::array<SphereRenderCharacterSlot, 400> instances{};
    std::array<int, 21> small_helm{};
    std::uint64_t last_lod_update = 0;
    std::size_t rendered_count = 0;
    float lod_start = 0.0f;
    float lod_end = 0.0f;

    void load(std::span<const std::string_view> folders);
    void clear();
    void initializeBounds();
    int classify(const SferaMatrix4x4F &world) const;
    void setDistances(double minimum, float range);
    void updateLodDistance();
    float visibility(const WorldObject &object) const;
    void setAppearance(int handle, const SphereRenderCharacterAppearance &appearance);
    bool getAppearance(int handle, SphereRenderCharacterAppearance &appearance) const;
    int partAnimationLength(const ExtendedWorldObject &object, int animation) const;
    int usesSmallHelm(int sex, int code) const;
    void loadSkeleton(const std::string &path, SphereRenderCharacterSkeleton &skeleton);
    void preload(SphereRenderCharacterAsset &asset, const SphereRenderCharacterSkeleton &skeleton);
    void animate(const SphereRenderCharacterSkeleton &skeleton, int animation, int frame, int secondaryAnimation, int secondaryFrame, float interpolation, SferaMatrix4x4F *output,
                 bool attachmentsOnly) const;
    SferaVec3F neckPosition(const ExtendedWorldObject &object) const;
    void drawPart(int sex, int kind, std::uint8_t model, int visibility, const SphereRenderCharacterSkeleton &skeleton, const SferaMatrix4x4F *pose, bool cull, int transparent, int textureCode,
                  std::uint32_t passes);
    void drawLowDetail(std::uint32_t handle);
    void draw(std::uint32_t handle, std::uint32_t color);
    static HRESULT setMaterial(float opacity, float detail, const SferaVec3F &color);
    static int textureVariants(bool female, std::string_view part);
    static std::uint32_t *parameter(std::span<std::uint32_t> values, int index);
    static ExtendedWorldObject *checkedExtended(WorldObject *object);

  private:
    const SphereRenderCharacterAppearance &appearance(const ExtendedWorldObject &object) const;
    void updateEffectFrames(ExtendedWorldObject &object, const SphereRenderCharacterSkeleton &skeleton, std::span<SferaMatrix4x4F> pose, const SferaMatrix4x4F &world) const;

  private:
    template <class T> static T characterRead(std::span<const std::uint8_t> bytes, std::size_t offset);
    static std::span<const std::uint8_t> characterRange(std::span<const std::uint8_t> bytes, std::size_t offset, std::size_t length);
    static void characterDisableLights(std::uint32_t line);

  private:
    static bool unusedCharacterSlot(const SphereRenderCharacterSlot &entry);
    static bool characterAssetNamed(std::string_view name, const SphereRenderCharacterAsset &value);
    void drawAppearancePart(const SphereRenderCharacterAppearance &parameters, int visible, const SphereRenderCharacterSkeleton &skeleton, const std::vector<SferaMatrix4x4F> &pose,
                            const ExtendedWorldObject *object, int kind, std::uint8_t model, int texture = '0', std::uint32_t passes = 3u, bool cull = true);
};
