#pragma once

#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <span>
#include <string_view>

#include "numeric/Numeric.h"

struct SferaVec3F;

struct SferaVec3F
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    SferaVec3F operator+(const SferaVec3F &other) const;
    SferaVec3F operator-(const SferaVec3F &other) const;
    SferaVec3F operator*(float factor) const;
    SferaVec3F subtractScaled(const SferaVec3F &direction, float factor) const;
    template <class Accumulator = double, bool YFirst = false> Accumulator dot(const SferaVec3F &other) const
    {
        const std::array<Accumulator, 3> components{x, y, z};
        if constexpr (YFirst)
            return components[1] * other.y + components[0] * other.x + components[2] * other.z;
        else
            return components[0] * other.x + components[1] * other.y + components[2] * other.z;
    }
    template <class Accumulator = double, class Root = double, bool YFirst = false> float length() const
    {
        const float squared = SferaNumeric::real32(dot<Accumulator, YFirst>(*this));
        const Root radicand = squared;
        return SferaNumeric::real32(std::sqrt(radicand));
    }
    // A zero threshold, precision and divide-vs-reciprocal are observable in old effects.
    template <class Accumulator = double, class Root = double, bool Divide = false, bool PropagateNaN = false> SferaVec3F unit(float threshold, const SferaVec3F &fallback) const
    {
        const float magnitude = length<Accumulator, Root>();
        if (magnitude <= threshold || (!PropagateNaN && std::isnan(magnitude)))
            return fallback;
        if constexpr (Divide)
            return {x / magnitude, y / magnitude, z / magnitude};
        else
            return *this * (1.0f / magnitude);
    }
    static void setNormalizationFailureHandler(void (*handler)(std::string_view)) noexcept
    {
        normalizationFailureHandler_ = handler;
    }
    SferaVec3F normalized(std::size_t diagnosticCode = 0) const;
    void normalize();
    template <class Accumulator = double> SferaVec3F cross(const SferaVec3F &other) const
    {
        const std::array<Accumulator, 3> components{x, y, z};
        SferaVec3F result;
        result.x = SferaNumeric::real32(components[1] * other.z - components[2] * other.y);
        result.y = SferaNumeric::real32(components[2] * other.x - components[0] * other.z);
        result.z = SferaNumeric::real32(components[0] * other.y - components[1] * other.x);
        return result;
    }
    float component(std::size_t axis) const
    {
        return axis == 0 ? x : axis == 1 ? y : z;
    }
    void setComponent(std::size_t axis, float value)
    {
        if (axis == 0)
            x = value;
        else if (axis == 1)
            y = value;
        else
            z = value;
    }
    static void rotatePair(float &first, float &second, float angle);
    bool containsConvexPolygonPoint(std::span<const SferaVec3F *const> vertices, const SferaVec3F &point) const;

  private:
    static void (*normalizationFailureHandler_)(std::string_view);
    [[noreturn]] static void failNormalization(std::string_view message);
    template <class Operation> static SferaVec3F transformComponents(const SferaVec3F &source, Operation operation);

    static double addComponent(const SferaVec3F &other, double value, std::size_t axis)
    {
        return value + other.component(axis);
    }
    static double subtractComponent(const SferaVec3F &other, double value, std::size_t axis)
    {
        return value - other.component(axis);
    }
    static double scaleComponent(float factor, double value, std::size_t)
    {
        return value * factor;
    }
    static double subtractScaledComponent(const SferaVec3F &direction, float factor, double origin, std::size_t axis)
    {
        const double delta = direction.component(axis);
        return origin - delta * factor;
    }
    static std::array<double, 2> projectPolygonPoint(const SferaVec3F &value, std::size_t first, std::size_t second)
    {
        return {value.component(first), value.component(second)};
    }
};

struct SferaVec4F;

struct SferaVec4F
{
    float x;
    float y;
    float z;
    float w;
};

struct SferaMatrix3x3F;
struct SferaQuaternionF;

struct SferaQuaternionF
{
    float w;
    float x;
    float y;
    float z;

    SferaMatrix3x3F rotationMatrix() const;
    SferaQuaternionF interpolated(const SferaQuaternionF &other, float factor) const;
};

class SferaAngle8;

class SferaAngle8
{
  public:
    explicit SferaAngle8(float radians);
    float distanceTo(SferaAngle8 other) const;

  private:
    std::uint8_t steps;
};
