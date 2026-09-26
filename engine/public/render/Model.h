#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

#include "animation/Animation.h"
#include "collision/Collision.h"
#include "geometry/Geometry.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "vegetation/VegetationGeometry.h"

struct SphereRenderFaceColorIndices;
struct SphereRenderMaterial;
struct SphereRenderModelFace;
struct SphereRenderModelVertex;
struct SphereRenderSubmesh;

struct SphereRenderModelVertex
{
    SferaVec3F position{};
    SferaVec3F normal{};
    float u = 0.0f;
    float v = 0.0f;
    const SphereRenderMaterial *material = nullptr;
};

struct SphereRenderModelFace
{
    std::uint16_t vertices[3]{};
};

struct SphereRenderSubmesh
{
    std::size_t bone_index = 0u;
    bool inverted_fade = false;
    const SphereRenderMaterial *material = nullptr;
    std::size_t first_face = 0u;
    std::size_t face_count = 0u;
    std::size_t first_vertex = 0u;
    std::size_t vertex_count = 0u;
};

struct SphereRenderFaceColorIndices
{
    std::uint16_t vertices[3]{};
};

class SphereRenderMaterialLibrary;
class SphereRenderModel;
class SphereRenderModelParameters;

class SphereRenderModel
{
  public:
    std::string name;
    std::vector<SphereRenderModelVertex> vertices;
    std::vector<SphereRenderModelFace> faces;
    std::vector<SphereRenderSubmesh> submeshes;
    std::vector<SphereRenderBone> bones;
    std::size_t root_bone = 0;
    std::vector<const SphereRenderMaterial *> materials;
    std::vector<std::size_t> child_bones;
    std::size_t frame_count = 0u;
    std::vector<SphereRenderModelKeyframe> keyframes;
    std::vector<SphereRenderAnimationFrame> animation_frames;
    std::vector<int> animation_lengths;
    bool has_vertex_colors = false;
    std::vector<std::uint32_t> vertex_colors;
    std::vector<SphereRenderFaceColorIndices> face_colors;
    SphereRenderCollisionKind collision_kind = SphereRenderCollisionKind::AxisAlignedBounds;
    SferaVec3F minimum{};
    SferaVec3F maximum{};
    SferaBoundsCornersRuntime oriented_corners{};
    SferaBoundsCornersRuntime collision_corners{};
    SferaMatrix4x4F bounds_transform{};
    SferaVec3F oriented_size{};
    float radius = 0.0f;
    float minimum_size = 0.0f;
    std::vector<SphereRenderModelCollisionGroup> collision_groups;
    std::vector<SphereRenderModelCollisionTriangle> collision_triangles;
    float lod_distance = 1000.0f;
    float lod_power = -1.0f;
    float shadow_fade = 0.5f;
    float shadow_scale = 2.0f;
    float shadow_spread = 0.85f;
    bool casts_static_shadow = false;
    SphereRenderVegetationKind vegetation_kind = SphereRenderVegetationKind::None;

    std::variant<std::monostate, SphereRenderModelGrassData, std::vector<SphereRenderTreeInfluence>> vegetation;
    std::vector<SphereRenderVegetationVertex> cached_vegetation_vertices;

    SphereRenderModelGrassData *grass() noexcept
    {
        return std::get_if<SphereRenderModelGrassData>(&vegetation);
    }
    const SphereRenderModelGrassData *grass() const noexcept
    {
        return std::get_if<SphereRenderModelGrassData>(&vegetation);
    }
    std::vector<SphereRenderTreeInfluence> *tree() noexcept
    {
        return std::get_if<std::vector<SphereRenderTreeInfluence>>(&vegetation);
    }
    const std::vector<SphereRenderTreeInfluence> *tree() const noexcept
    {
        return std::get_if<std::vector<SphereRenderTreeInfluence>>(&vegetation);
    }
    std::array<float, 3> color_variation{};
    std::uint32_t landscape_shadow_alpha = 0u;

    // Raw material links in geometry borrow from these immutable catalogues.
    std::vector<std::shared_ptr<const std::vector<SphereRenderMaterial>>> material_lifetimes;
    SphereRenderModel() = default;
    SphereRenderModel(const SphereRenderModel &) = delete;
    SphereRenderModel &operator=(const SphereRenderModel &) = delete;
    static std::unique_ptr<SphereRenderModel> load(std::string_view model_name, std::string_view directory, const SphereRenderModelParameters &parameters,
                                                   const SphereRenderMaterialLibrary &materials);
    static std::unique_ptr<SphereRenderModel> decode(std::string_view model_name, std::span<const std::uint8_t> bytes, const SphereRenderModelParameters &parameters,
                                                     const SphereRenderMaterialLibrary &materials);
    double relativeLod(double distance) const noexcept
    {
        return radius / distance * lod_distance;
    }
    void prepareGrass(bool synchronized, double ground_y);
    void prepareTree(double dead_radius, double phase_multiplier);
    void prepareVegetation(const SphereRenderModelParameters &parameters);
    void initializeGrassGeometry(std::size_t vertices_needed, std::size_t faces_needed, float height);
    void finishGrassGeometry(std::span<const SphereRenderSubmesh> groups);

  private:
    void recoverBounds();
    void assignMaterials();

  private:
    friend struct SphereRenderModelGrassData;

  private:
    static void failDecode(std::string_view model_name, std::string_view reason);
    static std::uint8_t readModelByte(std::string_view model_name, std::span<const std::uint8_t> bytes, std::size_t offset);
    static std::uint16_t readModelWord(std::string_view model_name, std::span<const std::uint8_t> bytes, std::size_t offset);
    static std::uint32_t readModelInteger(std::span<const std::uint8_t> bytes, std::size_t offset);
    static float readModelReal(std::string_view model_name, std::span<const std::uint8_t> bytes, std::size_t offset);
    static SferaVec3F readModelPoint(std::string_view model_name, std::span<const std::uint8_t> bytes, std::size_t offset);
    static std::size_t takeModelSection(std::string_view model_name, std::span<const std::uint8_t> bytes, std::size_t &cursor, std::size_t count, std::size_t width);
    static void visitDecodedBone(std::string_view model_name, const SphereRenderModel &model, std::vector<std::uint8_t> &visitation, std::size_t index);
    void markGrassFace(std::vector<bool> &visited, std::vector<int> &components, const SphereRenderSubmesh &submesh, int component, std::size_t face);
    static bool isGrassComponentVertex(const std::vector<int> &components, const SphereRenderSubmesh &submesh, int component, std::uint16_t vertex);
    void searchGrassAnchor(const std::vector<int> &components, std::size_t index, double ground_y, std::optional<std::size_t> &nearest, float &nearest_squared, bool same_component);
};
