#pragma once

#include <cmath>

#include "math/Vector.h"
#include "numeric/Numeric.h"

class SferaMath;
struct SferaMathRotationTerms;

struct SferaMathRotationTerms
{
    double sine;
    double cosine;
};

class SferaMath
{
  public:
    static inline double planarSquared(double first, double second)
    {
        return first * first + second * second;
    }
    static SferaVec3F anglesFromBasis(SferaVec3F forward, SferaVec3F up);
    static inline float fittedFieldOfView(double width, double height, double reference_degrees = 68.75493541569878)
    {
        constexpr double degrees_to_half_radians = 0.008726646259971648;
        const double half_angle = reference_degrees * degrees_to_half_radians;
        const float tangent = SferaNumeric::real32(std::tan(half_angle));
        const float aspect = SferaNumeric::real32(height / width);
        const float adjusted = SferaNumeric::real32(tangent / (aspect / 0.75));
        const double slope = adjusted;
        const float angle = SferaNumeric::real32(std::atan(slope));
        const double rounded_angle = angle;
        return SferaNumeric::real32(rounded_angle + angle);
    }
    static inline float interpolate(float first, double second, float fraction)
    {
        return SferaNumeric::real32((second - first) * fraction + first);
    }

    static inline SferaMathRotationTerms rotationTerms(double angle)
    {
        // Rotation formulas historically use single-rounded trigonometric values.
        const float sine = SferaNumeric::real32(std::sin(angle));
        const float cosine = SferaNumeric::real32(std::cos(angle));
        return {sine, cosine};
    }
    static inline SferaVec3F interpolate(const SferaVec3F &a, const SferaVec3F &b, float fraction)
    {
        return {interpolate(a.x, b.x, fraction), interpolate(a.y, b.y, fraction), interpolate(a.z, b.z, fraction)};
    }
    static inline SferaVec4F interpolate(const SferaVec4F &a, const SferaVec4F &b, float fraction)
    {
        return {interpolate(a.x, b.x, fraction), interpolate(a.y, b.y, fraction), interpolate(a.z, b.z, fraction), interpolate(a.w, b.w, fraction)};
    }
};
