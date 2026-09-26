#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <functional>
#include <stdexcept>
#include <string>

#include "math/MathFunctions.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"

SferaVec3F SferaMath::anglesFromBasis(SferaVec3F forward, SferaVec3F up)
{
    float roll = 0.0f;
    if (planarSquared(up.x, up.y) > 1.0e-6)
    {
        const double x = up.x, y = up.y;
        const float azimuth = SferaNumeric::real32(std::atan2(y, x));
        roll = SferaNumeric::real32(4.7123894691467285 - azimuth);
        SferaVec3F::rotatePair(forward.x, forward.y, roll);
        SferaVec3F::rotatePair(up.x, up.y, roll);
    }
    const double y = up.y, z = up.z;
    const float elevation = SferaNumeric::real32(std::atan2(y, z));
    const float pitch = SferaNumeric::real32(4.7123894691467285 - elevation);
    const auto [sine, cosine] = rotationTerms(pitch);
    const float projected = SferaNumeric::real32(cosine * forward.z - sine * forward.y);
    const double projectedZ = projected, projectedX = forward.x;
    const float heading = SferaNumeric::real32(std::atan2(projectedZ, projectedX));
    const float yaw = SferaNumeric::real32(1.5707964897155762 - heading);
    return {-yaw, -pitch, -roll};
}

SferaMatrix4x4F SferaMatrix4x4F::fromRollPitchYaw(float roll, float pitch, float yaw)
{
    const auto [sr, cr] = SferaMath::rotationTerms(roll);
    const auto [sp, cp] = SferaMath::rotationTerms(pitch);
    const auto [sy, cy] = SferaMath::rotationTerms(yaw);
    const float pitchRoll = SferaNumeric::real32(sp * sr), yawRoll = SferaNumeric::real32(cy * cr), sineYawRoll = SferaNumeric::real32(sy * cr);
    SferaMatrix4x4F result = identity();
    result.m[0][0] = SferaNumeric::real32(cp * cy);
    result.m[1][0] = SferaNumeric::real32(cp * sy);
    result.m[2][0] = SferaNumeric::real32(-sp);
    result.m[0][1] = SferaNumeric::real32(cy * pitchRoll - sineYawRoll);
    result.m[1][1] = SferaNumeric::real32(sy * pitchRoll + yawRoll);
    result.m[2][1] = SferaNumeric::real32(cp * sr);
    result.m[0][2] = SferaNumeric::real32(sy * sr + yawRoll * sp);
    result.m[1][2] = SferaNumeric::real32(sineYawRoll * sp - sr * cy);
    result.m[2][2] = SferaNumeric::real32(cr * cp);
    return result;
}

SferaMatrix4x4F SferaMatrix4x4F::fromEuler(const SferaVec3F &translation, const SferaVec3F &angles)
{
    const auto [sx, cx] = SferaMath::rotationTerms(angles.x);
    const auto [sy, cy] = SferaMath::rotationTerms(angles.y);
    const auto [sz, cz] = SferaMath::rotationTerms(angles.z);
    SferaMatrix4x4F result = identity();
    result.m[0][0] = SferaNumeric::real32(cz * cx - sy * sx * sz);
    result.m[0][1] = SferaNumeric::real32(-sz * cy);
    result.m[0][2] = SferaNumeric::real32(-sx * cz - sy * cx * sz);
    result.m[1][0] = SferaNumeric::real32(sz * cx + cz * sy * sx);
    result.m[1][1] = SferaNumeric::real32(cz * cy);
    result.m[1][2] = SferaNumeric::real32(cz * sy * cx - sz * sx);
    result.m[2][0] = SferaNumeric::real32(cy * sx);
    result.m[2][1] = SferaNumeric::real32(-sy);
    result.m[2][2] = SferaNumeric::real32(cy * cx);
    result.m[0][3] = translation.x;
    result.m[1][3] = translation.y;
    result.m[2][3] = translation.z;
    return result;
}

SferaMatrix4x4F SferaMatrix4x4F::fromQuaternion(const SferaQuaternionF &rotation, const SferaVec3F &translation)
{
    SferaMatrix4x4F result = identity();
    const auto basis = rotation.rotationMatrix();
    for (std::size_t row = 0; row < 3; ++row)
        for (std::size_t column = 0; column < 3; ++column)
            result.m[row][column] = basis.m[row][column];
    result.m[0][3] = translation.x;
    result.m[1][3] = translation.y;
    result.m[2][3] = translation.z;
    return result;
}

SferaVec3F SferaMatrix4x4F::inverseTransformPoint(const SferaVec3F &point) const
{
    const SferaVec3F relative = point - SferaVec3F{m[0][3], m[1][3], m[2][3]};
    SferaVec3F result;
    for (std::size_t column = 0; column < 3; ++column)
    {
        const SferaVec3F basis{m[0][column], m[1][column], m[2][column]};
        result.setComponent(column, SferaNumeric::real32(basis.dot(relative)));
    }
    return result;
}

void SferaMatrix4x4F::scaleAxes(const SferaVec3F &scale)
{
    for (std::size_t row = 0; row < 3; ++row)
    {
        const double factor = scale.component(row);
        for (std::size_t column = 0; column < 3; ++column)
            m[row][column] = SferaNumeric::real32(m[row][column] * factor);
    }
}

SferaAngle8::SferaAngle8(float radians)
{
    if (!std::isfinite(radians))
        throw std::invalid_argument("A finite angle is required");
    const double wrapped = std::fmod(std::trunc(radians * 40.74365997314453), 256.0);
    steps = SferaNumeric::lowByte(SferaNumeric::truncatedWord(wrapped < 0.0 ? wrapped + 256.0 : wrapped));
}

float SferaAngle8::distanceTo(SferaAngle8 other) const
{
    const int distance = std::abs(steps - other.steps);
    return SferaNumeric::real32(std::min(distance, 256 - distance) * 0.024543695894260174);
}

SferaMatrix3x3F SferaQuaternionF::rotationMatrix() const
{
    const float xx = SferaNumeric::real32(2.0 * x * x), yy = SferaNumeric::real32(2.0 * y * y), zz = SferaNumeric::real32(2.0 * z * z);
    const std::array diagonal{xx, yy, zz};
    const float xy = SferaNumeric::real32(2.0 * x * y), xz = SferaNumeric::real32(2.0 * x * z), yz = SferaNumeric::real32(2.0 * y * z);
    const float wx = SferaNumeric::real32(2.0 * w * x), wy = SferaNumeric::real32(2.0 * w * y), wz = SferaNumeric::real32(2.0 * w * z);
    const std::array<double, 3> mixed{xy, xz, yz};
    SferaMatrix3x3F result{};
    result.m[0][0] = SferaNumeric::real32(1.0 - diagonal[1] - diagonal[2]);
    result.m[0][1] = SferaNumeric::real32(mixed[0] - wz);
    result.m[0][2] = SferaNumeric::real32(wy + mixed[1]);
    result.m[1][0] = SferaNumeric::real32(mixed[0] + wz);
    result.m[1][1] = SferaNumeric::real32(1.0 - diagonal[0] - diagonal[2]);
    result.m[1][2] = SferaNumeric::real32(mixed[2] - wx);
    result.m[2][0] = SferaNumeric::real32(mixed[1] - wy);
    result.m[2][1] = SferaNumeric::real32(wx + mixed[2]);
    result.m[2][2] = SferaNumeric::real32(1.0 - diagonal[0] - diagonal[1]);
    return result;
}

SferaQuaternionF SferaQuaternionF::interpolated(const SferaQuaternionF &other, float factor) const
{
    const std::array<double, 4> source{x, y, z, w};
    const float roundedCosine = SferaNumeric::real32(source[0] * other.x + source[1] * other.y + source[2] * other.z + source[3] * other.w);
    const double cosine = roundedCosine;
    SferaQuaternionF target = other;
    float firstWeight;
    float secondWeight;
    if (!(1.0 + cosine > 0.00001))
    {
        target = {z, -y, x, -w};
        firstWeight = SferaNumeric::real32(std::sin((1.0 - factor) * 1.5707965));
        secondWeight = SferaNumeric::real32(std::sin(factor * 1.5707965));
    }
    else if (1.0 - cosine > 0.00001f)
    {
        const float roundedAngle = SferaNumeric::real32(std::acos(cosine));
        const double angle = roundedAngle;
        const float roundedSine = SferaNumeric::real32(std::sin(angle));
        const double sine = roundedSine;
        firstWeight = SferaNumeric::real32(std::sin((1.0 - factor) * angle) / sine);
        const float secondAngle = SferaNumeric::real32(angle * factor);
        const double phase = secondAngle;
        const float roundedSecondSine = SferaNumeric::real32(std::sin(phase));
        const double secondSine = roundedSecondSine;
        secondWeight = SferaNumeric::real32(secondSine / sine);
    }
    else
    {
        firstWeight = SferaNumeric::real32(1.0 - factor);
        secondWeight = factor;
    }
    const double first = firstWeight, second = secondWeight;
    SferaQuaternionF result;
    result.w = SferaNumeric::real32(source[3] * first + target.w * second);
    result.x = SferaNumeric::real32(source[0] * first + target.x * second);
    result.y = SferaNumeric::real32(source[1] * first + target.y * second);
    result.z = SferaNumeric::real32(source[2] * first + target.z * second);
    return result;
}

SferaVec3F SferaVec3F::normalized(std::size_t diagnosticCode) const
{
    const float magnitude = length();
    if (magnitude < 9.999999747378752e-6f)
    {
        if (diagnosticCode == 0)
            return {};
        failNormalization((std::string("normalize: normal with extra short length found. Code:") + std::to_string(diagnosticCode)));
    }
    return *this * SferaNumeric::real32(1.0 / magnitude);
}

template <class Operation> SferaVec3F SferaVec3F::transformComponents(const SferaVec3F &source, Operation operation)
{
    SferaVec3F result;
    for (std::size_t axis = 0; axis < 3; ++axis)
    {
        const double component = source.component(axis);
        result.setComponent(axis, SferaNumeric::real32(operation(component, axis)));
    }
    return result;
}

SferaVec3F SferaVec3F::operator+(const SferaVec3F &other) const
{
    return SferaVec3F::transformComponents(*this, std::bind_front(&SferaVec3F::addComponent, std::cref(other)));
}

SferaVec3F SferaVec3F::operator-(const SferaVec3F &other) const
{
    return SferaVec3F::transformComponents(*this, std::bind_front(&SferaVec3F::subtractComponent, std::cref(other)));
}

SferaVec3F SferaVec3F::operator*(float factor) const
{
    return SferaVec3F::transformComponents(*this, std::bind_front(&SferaVec3F::scaleComponent, factor));
}

SferaVec3F SferaVec3F::subtractScaled(const SferaVec3F &direction, float factor) const
{
    return SferaVec3F::transformComponents(*this, std::bind_front(&SferaVec3F::subtractScaledComponent, std::cref(direction), factor));
}

void SferaVec3F::rotatePair(float &first, float &second, float angle)
{
    const double radians = angle, originalFirst = first, originalSecond = second;
    const float cosine = SferaNumeric::real32(std::cos(radians)), sine = SferaNumeric::real32(std::sin(radians));
    const float rotatedFirst = SferaNumeric::real32(originalFirst * cosine - originalSecond * sine);
    second = SferaNumeric::real32(originalFirst * sine + originalSecond * cosine);
    first = rotatedFirst;
}

void SferaVec3F::normalize()
{
    const float magnitude = length<double, double, true>();
    if (magnitude == 0.0f)
        return;
    const double divisor = magnitude;
    x = SferaNumeric::real32(x / divisor);
    y = SferaNumeric::real32(y / divisor);
    z = SferaNumeric::real32(z / divisor);
}

bool SferaVec3F::containsConvexPolygonPoint(std::span<const SferaVec3F *const> vertices, const SferaVec3F &point) const
{
    if (vertices.empty())
        return true;
    std::size_t dominant = std::abs(y) > std::abs(x) ? 1 : 0;
    if (std::abs(z) > std::abs(component(dominant)))
        dominant = 2;
    const std::size_t first = (dominant + 1) % 3, second = (dominant + 2) % 3;

    const auto target = projectPolygonPoint(point, first, second);
    auto previous = projectPolygonPoint(*vertices.back(), first, second);
    for (const auto *vertex : vertices)
    {
        const auto current = projectPolygonPoint(*vertex, first, second);
        const double side = (previous[1] - current[1]) * (target[0] - previous[0]) + (current[0] - previous[0]) * (target[1] - previous[1]);
        if (side * component(dominant) < 0.0)
            return false;
        previous = current;
    }
    return true;
}

void (*SferaVec3F::normalizationFailureHandler_)(std::string_view) = nullptr;

void SferaVec3F::failNormalization(std::string_view message)
{
    if (normalizationFailureHandler_ != nullptr)
        normalizationFailureHandler_(message);
    throw std::runtime_error(std::string(message));
}
