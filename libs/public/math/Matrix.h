#pragma once

#include <array>
#include <cmath>
#include <cstddef>

#include "math/Vector.h"
#include "numeric/Numeric.h"

struct SferaMatrix3x3F;

struct SferaMatrix3x3F
{
    float m[3][3];
};

struct SferaMatrix4x4F;
struct SferaQuaternionF;

enum class SferaMatrix4x4FAxis
{
    x,
    y,
    z
};

struct SferaMatrix4x4F
{
    float m[4][4];

    static SferaMatrix4x4F identity()
    {
        SferaMatrix4x4F result{};
        for (std::size_t axis = 0; axis < 4; ++axis)
            result.m[axis][axis] = 1.0f;
        return result;
    }
    template <class Trigonometry = double> static SferaMatrix4x4F fromAxisRotation(SferaMatrix4x4FAxis axis, float angle)
    {
        SferaMatrix4x4F result = identity();
        const std::size_t first = axis == SferaMatrix4x4FAxis::x ? 1u : axis == SferaMatrix4x4FAxis::y ? 2u : 0u;
        const std::size_t second = (first + 1u) % 3u;
        const Trigonometry radians = angle;
        const float sine = SferaNumeric::real32(std::sin(radians));
        const float cosine = SferaNumeric::real32(std::cos(radians));
        result.m[first][first] = result.m[second][second] = cosine;
        result.m[first][second] = -sine;
        result.m[second][first] = sine;
        return result;
    }
    static SferaMatrix4x4F fromRollPitchYaw(float roll, float pitch, float yaw);
    static SferaMatrix4x4F fromEuler(const SferaVec3F &translation, const SferaVec3F &angles);
    static SferaMatrix4x4F fromQuaternion(const SferaQuaternionF &rotation, const SferaVec3F &translation = {});
    template <class Accumulator = double> Accumulator projectComponent(std::size_t row, const SferaVec3F &point) const
    {
        const std::array<Accumulator, 3> basis{m[row][0], m[row][1], m[row][2]};
        return basis[0] * point.x + basis[1] * point.y + basis[2] * point.z + m[row][3];
    }
    template <class Accumulator = double> SferaVec3F transformPoint(const SferaVec3F &point) const
    {
        SferaVec3F result{};
        for (std::size_t row = 0; row < 3; ++row)
        {
            result.setComponent(row, SferaNumeric::real32(projectComponent<Accumulator>(row, point)));
        }
        return result;
    }
    SferaVec3F inverseTransformPoint(const SferaVec3F &point) const;
    template <class Accumulator = double> SferaMatrix4x4F multiplied(const SferaMatrix4x4F &other) const
    {
        SferaMatrix4x4F result{};
        for (std::size_t row = 0; row < 4; ++row)
            for (std::size_t column = 0; column < 4; ++column)
            {
                Accumulator value = 0;
                for (std::size_t axis = 0; axis < 4; ++axis)
                {
                    const Accumulator element = m[row][axis];
                    value += element * other.m[axis][column];
                }
                result.m[row][column] = SferaNumeric::real32(value);
            }
        return result;
    }
    static SferaMatrix4x4F fromXyzRotation(const SferaVec3F &angles)
    {
        return fromAxisRotation<float>(SferaMatrix4x4FAxis::x, angles.x)
            .multiplied<float>(fromAxisRotation<float>(SferaMatrix4x4FAxis::y, angles.y))
            .multiplied<float>(fromAxisRotation<float>(SferaMatrix4x4FAxis::z, angles.z));
    }
    SferaMatrix4x4F transposed() const
    {
        SferaMatrix4x4F result;
        for (std::size_t row = 0; row < 4; ++row)
            for (std::size_t column = 0; column < 4; ++column)
                result.m[row][column] = m[column][row];
        return result;
    }
    void scaleAxes(const SferaVec3F &scale);
};
