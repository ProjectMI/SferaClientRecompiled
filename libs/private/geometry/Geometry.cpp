#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <span>
#include <utility>
#include <vector>

#include "geometry/Geometry.h"
#include "math/MathFunctions.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"

SferaBoundsCornersRuntime SferaBoundsCornersRuntime::empty()
{
    constexpr float limit = std::numeric_limits<float>::max();
    return fromExtents({limit, limit, limit}, {-limit, -limit, -limit});
}

void SferaBoundsCornersRuntime::getExtents(SferaVec3F &minimum, SferaVec3F &maximum) const
{
    minimum = maximum = corners[0];
    for (std::size_t index = 1; index < 8; ++index)
    {
        for (std::size_t axis = 0; axis < 3; ++axis)
        {
            const float coordinate = corners[index].component(axis);
            if (coordinate < minimum.component(axis))
                minimum.setComponent(axis, coordinate);
            else if (coordinate > maximum.component(axis))
                maximum.setComponent(axis, coordinate);
        }
    }
}

int SferaFrustumF::classifyPoints(std::span<const SferaVec3F> points) const
{
    bool intersects = false;
    for (const auto &plane : planes)
    {
        std::size_t outside = 0;
        for (const auto &point : points)
            if (plane.evaluate(point) < 0.0)
                ++outside;
        if (outside == points.size())
            return 0;
        intersects = intersects || outside != 0;
    }
    return intersects ? 1 : 2;
}

int SferaPlaneF::intersectLine(const SferaVec3F &start, const SferaVec3F &end, SferaVec3F &intersection) const
{
    const SferaVec3F direction = end - start;
    const float denominator = SferaNumeric::real32(normal.dot(direction));
    if (std::abs(denominator) <= std::numeric_limits<float>::min())
        return 0;
    const float startProjection = SferaNumeric::real32(normal.dot(start));
    const double projection = startProjection;
    const float startDistance = SferaNumeric::real32(projection + distance);
    const double numerator = startDistance;
    const float parameter = SferaNumeric::real32(numerator / denominator);
    intersection = start.subtractScaled(direction, parameter);
    return (startDistance < 0.0f ? -2 : 1) + (denominator > 0.0f ? 1 : 0);
}

SferaPlaneF SferaPlaneF::throughPoint(const SferaVec3F &normal, const SferaVec3F &point)
{
    const std::array<double, 3> components{normal.x, normal.y, normal.z};
    SferaPlaneF result{normal, 0.0f};
    result.distance = SferaNumeric::real32(-components[0] * point.x - components[1] * point.y - components[2] * point.z);
    return result;
}

SferaPlaneF SferaPlaneF::fromTriangle(const SferaVec3F &first, const SferaVec3F &second, const SferaVec3F &third)
{
    const std::array<double, 3> a{first.x, first.y, first.z};
    const std::array<double, 3> b{second.x, second.y, second.z};
    const std::array<double, 3> c{third.x, third.y, third.z};
    SferaVec3F normal;
    normal.x = SferaNumeric::real32((a[2] + b[2]) * (a[1] - b[1]) + (c[1] - a[1]) * (a[2] + c[2]) + (b[1] - c[1]) * (b[2] + c[2]));
    normal.y = SferaNumeric::real32((c[2] - a[2]) * (a[0] + c[0]) + (a[2] - b[2]) * (a[0] + b[0]) + (b[2] - c[2]) * (b[0] + c[0]));
    normal.z = SferaNumeric::real32((c[0] - a[0]) * (c[1] + a[1]) + (a[0] - b[0]) * (a[1] + b[1]) + (b[0] - c[0]) * (c[1] + b[1]));
    normal.normalize();
    return throughPoint(normal, first);
}

void SferaPolygon3F::clipToAxis(std::size_t axis, float boundary, bool keepGreater)
{
    if (vertices.empty())
        return;
    std::vector<SferaVec3F> clipped;
    clipped.reserve(vertices.size() + 1);
    SferaVec3F previous = vertices.back();
    bool previousInside = keepGreater ? previous.component(axis) >= boundary : previous.component(axis) <= boundary;
    for (const auto &current : vertices)
    {
        const bool currentInside = keepGreater ? current.component(axis) >= boundary : current.component(axis) <= boundary;
        if (previousInside != currentInside)
        {
            const double limit = boundary, currentAxis = current.component(axis);
            const float fraction = SferaNumeric::real32((limit - previous.component(axis)) / (currentAxis - previous.component(axis)));
            const float factor = std::clamp(fraction, 0.0f, 1.0f);
            SferaVec3F intersection = SferaMath::interpolate(previous, current, factor);
            intersection.setComponent(axis, boundary);
            clipped.push_back(intersection);
        }
        if (currentInside)
            clipped.push_back(current);
        previous = current;
        previousInside = currentInside;
    }
    vertices = std::move(clipped);
}

bool SferaPolygon3F::clipTriangleToBounds(const SferaVec3F &first, const SferaVec3F &second, const SferaVec3F &third, const SferaVec3F &minimum, const SferaVec3F &maximum)
{
    vertices = {first, second, third};
    for (std::size_t axis = 0; axis < 3 && !vertices.empty(); ++axis)
    {
        clipToAxis(axis, minimum.component(axis), true);
        clipToAxis(axis, maximum.component(axis), false);
    }
    return !vertices.empty();
}

SferaViewProjectionScratchRuntime SferaViewProjectionScratchRuntime::translated(const SferaVec3F &offset) const
{
    SferaViewProjectionScratchRuntime result;
    for (std::size_t index = 0; index < 8; ++index)
        result.corners[index] = corners[index] + offset;
    const SferaVec3F scaled = offset * 1024.0f;
    const std::int64_t fixedX = SferaNumeric::truncateInt64(std::nearbyint(scaled.x));
    const std::int64_t fixedY = SferaNumeric::truncateInt64(std::nearbyint(scaled.y));
    const std::int64_t fixedZ = SferaNumeric::truncateInt64(std::nearbyint(scaled.z));
    result.clipping_bounds = {clipping_bounds.min_x + fixedX, clipping_bounds.max_x + fixedX, clipping_bounds.min_y + fixedY,
                              clipping_bounds.max_y + fixedY, clipping_bounds.min_z + fixedZ, clipping_bounds.max_z + fixedZ};
    return result;
}
