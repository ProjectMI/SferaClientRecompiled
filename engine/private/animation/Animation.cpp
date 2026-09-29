#include <array>
#include <cstddef>
#include <optional>
#include <vector>

#include "animation/Animation.h"
#include "diagnostics/Diagnostics.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "render/Model.h"

SferaMatrix4x4F SphereRenderCharacterSkeleton::characterPoseMatrix(const SphereRenderCharacterPose &pose)
{
    const auto basis = SferaQuaternionF{pose.rotation.w, pose.rotation.x, pose.rotation.y, pose.rotation.z}.rotationMatrix();
    auto result = SferaMatrix4x4F::identity();
    for (std::size_t row = 0u; row < 3u; ++row)
    {
        for (std::size_t column = 0u; column < 3u; ++column)
        {
            result.m[row][column] = basis.m[column][row];
        }
    }
    result.m[3][0] = pose.translation.x;
    result.m[3][1] = pose.translation.y;
    result.m[3][2] = pose.translation.z;
    return result;
}

void SphereRenderCharacterSkeleton::calculate(std::size_t firstFrame, std::optional<std::size_t> upperFrame, std::size_t bone, const SferaMatrix4x4F &parent,
                                              SphereRenderCharacterSkeletonRegion region, SferaMatrix4x4F *output) const
{
    if (upperFrame && region == SphereRenderCharacterSkeletonRegion::Whole)
    {
        if (names[bone].starts_with('u'))
            region = SphereRenderCharacterSkeletonRegion::UpperBody;
        else if (names[bone].starts_with('d'))
            region = SphereRenderCharacterSkeletonRegion::LowerBody;
    }
    const auto frame = upperFrame && region == SphereRenderCharacterSkeletonRegion::UpperBody ? *upperFrame : firstFrame;
    output[bone] = (SphereRenderCharacterSkeleton::characterPoseMatrix(poses[frame * parents.size() + bone])).multiplied((parent));
    for (const auto child : children[bone])
        calculate(firstFrame, upperFrame, child, output[bone], region, output);
}

std::size_t SphereRenderCharacterSkeleton::absoluteFrame(int animation, int frame) const
{
    if (animation < 0 || std::cmp_greater_equal(animation, animation_lengths.size()) || frame < 0 || std::cmp_greater_equal(frame, animation_lengths[animation]))
        return 0;
    std::size_t absolute = frame;
    for (int index = 0; index < animation; ++index)
        absolute += animation_lengths[index];
    return absolute;
}

SphereRenderModelKeyframe SphereRenderModelPose::keyframe(const SphereRenderModel &model, const SphereRenderBoneAnimation &animation, std::size_t frame)
{
    if (!animation.animated)
        return model.keyframes[animation.pose_index];
    const auto &sample = model.animation_frames[animation.pose_index + frame];
    const auto &first = model.keyframes[sample.keyframe];
    if (sample.interpolation == 255u)
        return first;
    const auto &second = model.keyframes[sample.keyframe + 1u];
    const float weight = sample.interpolation / 256.0f;
    return {first.translation + (second.translation - first.translation) * weight, first.rotation.interpolated(second.rotation, weight)};
}

void SphereRenderModelPose::updateBone(const SferaMatrix4x4F &parent, std::size_t bone_index)
{
    auto *model = SphereRenderModelPose::active_model;
    if (model == nullptr || bone_index >= model->bones.size())
        SferaEngineDiagnostics::fail("Model animation: wrong bone index");
    const auto &bone = model->bones[bone_index];
    auto pose = keyframe(*model, bone.animation(), SphereRenderModelPose::primary_frame);
    if (bone.animation().animated && SphereRenderModelPose::secondary_enabled && !bone.animation().suppress_secondary_animation)
    {
        const auto second = keyframe(*model, bone.animation(), SphereRenderModelPose::secondary_frame);
        const float weight = SphereRenderModelPose::blend;
        pose = {pose.translation + (second.translation - pose.translation) * weight, pose.rotation.interpolated(second.rotation, weight)};
    }
    auto local = SferaMatrix4x4F::identity();
    const auto rotation = pose.rotation.rotationMatrix();
    for (std::size_t row = 0u; row < 3u; ++row)
        for (std::size_t column = 0u; column < 3u; ++column)
            local.m[row][column] = rotation.m[column][row];
    local.m[0][3] = pose.translation.x;
    local.m[1][3] = pose.translation.y;
    local.m[2][3] = pose.translation.z;
    const auto transform = parent.multiplied(local);
    auto &matrices = SphereRenderModelPose::bone_transforms;
    if (matrices.size() <= bone_index)
        matrices.resize(bone_index + 1u);
    matrices[bone_index] = transform;
    const auto slot = bone.animation().attachment_slot;
    SferaVec3F *position = slot == 100u   ? &SphereRenderModelPose::translation
                           : slot == 101u ? &SphereRenderModelPose::attachment_101_position
                           : slot == 102u ? &SphereRenderModelPose::attachment_102_position
                                          : nullptr;
    if (position != nullptr)
    {
        position->x = transform.m[0][3];
        position->y = transform.m[1][3];
        position->z = transform.m[2][3];
    }
    if (slot < 5u)
    {
        auto &attachments = SphereRenderModelPose::attachment_transforms;
        attachments[slot] = transform;
    }
    for (std::size_t child = 0u; child < bone.child_count; ++child)
        updateBone(transform, model->child_bones[bone.first_child + child]);
}

std::size_t SphereRenderModelPose::frameOffset(const SphereRenderModel &model, int animation, int frame, bool secondary)
{
    if (model.animation_lengths.empty())
    {
        missingAnimation(model.name, animation, frame);
    }
    if (animation < 0 || animation >= model.animation_lengths.size())
    {
        SphereRenderModelPose::poseWarning(secondary ? "CalcCharacterNeck: wrong animation 2" : "CalcCharacterNeck: wrong animation");
        animation = 0;
        frame = 0;
    }
    std::size_t offset = 0u;
    for (int index = 0; index < animation; ++index)
        offset += model.animation_lengths[index];
    if (frame < 0 || frame >= model.animation_lengths[animation])
    {
        SphereRenderModelPose::poseWarning(secondary ? "CalcCharacterNeck: wrong frame 2" : "CalcCharacterNeck: wrong frame");
        frame = 0;
    }
    return offset + frame;
}

bool SphereRenderModelPose::inverted_fade_pass{};

bool SphereRenderModelPose::secondary_enabled{};

std::size_t SphereRenderModelPose::primary_frame{};

SferaVec3F SphereRenderModelPose::scale{};

SferaVec3F SphereRenderModelPose::translation{};

SferaVec3F SphereRenderModelPose::attachment_102_position{};

SferaVec3F SphereRenderModelPose::attachment_101_position{};

SphereRenderModel *SphereRenderModelPose::active_model{};

float SphereRenderModelPose::blend{};

std::size_t SphereRenderModelPose::secondary_frame{};

SferaMatrix4x4F SphereRenderModelPose::coordinate_basis{};

SferaMatrix4x4F SphereRenderModelPose::current_frame{};

std::vector<SferaMatrix4x4F> SphereRenderModelPose::bone_transforms;

std::array<SferaMatrix4x4F, 5> SphereRenderModelPose::attachment_transforms{};
