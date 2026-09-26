#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

#include "geometry/Geometry.h"
#include "math/Matrix.h"
#include "math/Vector.h"

struct SphereRenderCharacterPose;
struct SphereRenderCharacterSkeleton;

struct SphereRenderCharacterPose
{
    SferaVec4F rotation;
    SferaVec3F translation;
};

enum class SphereRenderCharacterSkeletonRegion
{
    Whole,
    UpperBody,
    LowerBody
};

struct SphereRenderCharacterSkeleton
{
    std::vector<std::optional<std::size_t>> parents;
    std::vector<std::string> names;
    std::vector<std::vector<std::size_t>> children;
    std::vector<SphereRenderCharacterPose> poses;
    std::vector<int> animation_lengths;
    std::array<std::size_t, 7> attachments{};
    std::vector<SferaMatrix4x4F> initial_pose;
    void calculate(std::size_t firstFrame, std::optional<std::size_t> upperFrame, std::size_t bone, const SferaMatrix4x4F &parent, SphereRenderCharacterSkeletonRegion region,
                   SferaMatrix4x4F *output) const;
    std::size_t absoluteFrame(int animation, int frame) const;

  private:
    static SferaMatrix4x4F characterPoseMatrix(const SphereRenderCharacterPose &pose);
};

struct SphereRenderAnimationFrame;
struct SphereRenderBone;
struct SphereRenderBoneAnimation;
struct SphereRenderBoneBounds;
struct SphereRenderModelKeyframe;

struct SphereRenderBoneBounds
{
    SferaBoundsCornersRuntime corners{};
    SferaVec3F minimum{};
    SferaVec3F maximum{};
    SferaVec3F center{};
    float diagonal_length = 0.0f;
};

struct SphereRenderBoneAnimation
{
    bool suppress_secondary_animation = false;
    bool animated = false;
    std::size_t pose_index = 0u;
    std::uint8_t attachment_slot = 255u;
};

struct SphereRenderBone
{
    std::string name;
    bool has_geometry = true;
    std::size_t child_count = 0u;
    std::size_t first_child = 0u;
    std::variant<SphereRenderBoneBounds, SphereRenderBoneAnimation> data;

    SphereRenderBoneBounds &bounds()
    {
        return std::get<SphereRenderBoneBounds>(data);
    }
    const SphereRenderBoneBounds &bounds() const
    {
        return std::get<SphereRenderBoneBounds>(data);
    }
    SphereRenderBoneAnimation &animation()
    {
        return std::get<SphereRenderBoneAnimation>(data);
    }
    const SphereRenderBoneAnimation &animation() const
    {
        return std::get<SphereRenderBoneAnimation>(data);
    }
};

struct SphereRenderModelKeyframe
{
    SferaVec3F translation{};
    SferaQuaternionF rotation{};
};

struct SphereRenderAnimationFrame
{
    std::size_t keyframe = 0u;
    std::uint8_t interpolation = 255u;
};

struct ExtendedWorldObject;
struct SferaVec3F;
class SphereRenderModel;
class SphereRenderModelPose;

class SphereRenderModelPose
{
  public:
    static bool inverted_fade_pass;
    static bool secondary_enabled;
    static std::size_t primary_frame;
    static SferaVec3F scale;
    static SferaVec3F translation;
    static SferaVec3F attachment_102_position;
    static SferaVec3F attachment_101_position;
    static SphereRenderModel *active_model;
    static float blend;
    static std::size_t secondary_frame;
    static SferaMatrix4x4F coordinate_basis;
    static SferaMatrix4x4F current_frame;

    static std::vector<SferaMatrix4x4F> bone_transforms;
    static std::array<SferaMatrix4x4F, 5> attachment_transforms;
    static void updateBone(const SferaMatrix4x4F &parent, std::size_t bone_index);
    static int animationLength(std::uint32_t handle, int animation);
    static int *animation(std::uint32_t handle);
    static int *frame(std::uint32_t handle);
    static float *interpolation(std::uint32_t handle);
    static int *secondaryFrame(std::uint32_t handle);
    static int *secondaryAnimation(std::uint32_t handle);
    static SferaVec3F *neckPosition(SferaVec3F &output);

  private:
    static SphereRenderModelKeyframe keyframe(const SphereRenderModel &model, const SphereRenderBoneAnimation &animation, std::size_t frame);
    static ExtendedWorldObject *queryObject(std::uint32_t handle, std::string_view operation);
    static std::size_t frameOffset(const SphereRenderModel &model, int animation, int frame, bool secondary);

  private:
    static void poseWarning(std::string_view message);
    [[noreturn]] static void missingAnimation(std::string_view modelName, int animation, int frame);
};
