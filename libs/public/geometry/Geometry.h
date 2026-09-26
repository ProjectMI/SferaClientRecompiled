#pragma once

#include <cstddef>
#include <cstdint>
#include <span>
#include <vector>

#include "math/Vector.h"

struct SferaBoundsCornersRuntime;
struct SferaIntBounds3;

struct SferaBoundsCornersRuntime
{
    SferaVec3F corners[8];

    static SferaBoundsCornersRuntime fromExtents(const SferaVec3F &minimum, const SferaVec3F &maximum)
    {
        return {{{minimum.x, minimum.y, minimum.z},
                 {maximum.x, minimum.y, minimum.z},
                 {maximum.x, maximum.y, minimum.z},
                 {minimum.x, maximum.y, minimum.z},
                 {minimum.x, maximum.y, maximum.z},
                 {minimum.x, minimum.y, maximum.z},
                 {maximum.x, minimum.y, maximum.z},
                 {maximum.x, maximum.y, maximum.z}}};
    }
    static SferaBoundsCornersRuntime empty();
    void getExtents(SferaVec3F &minimum, SferaVec3F &maximum) const;
};

struct SferaIntBounds3
{
    std::int64_t min_x;
    std::int64_t max_x;
    std::int64_t min_y;
    std::int64_t max_y;
    std::int64_t min_z;
    std::int64_t max_z;
};

struct SferaPlaneF;

struct SferaPlaneF
{
    SferaVec3F normal;
    float distance;

    static SferaPlaneF throughPoint(const SferaVec3F &normal, const SferaVec3F &point);
    static SferaPlaneF fromTriangle(const SferaVec3F &first, const SferaVec3F &second, const SferaVec3F &third);
    double evaluate(const SferaVec3F &point) const
    {
        return normal.dot(point) + distance;
    }
    int intersectLine(const SferaVec3F &start, const SferaVec3F &end, SferaVec3F &intersection) const;
};

struct SferaFrustumF;

struct SferaFrustumF
{
    SferaPlaneF planes[6];

    int classifyPoints(std::span<const SferaVec3F> points) const;
};

class SferaPolygon3F;

class SferaPolygon3F
{
  public:
    std::vector<SferaVec3F> vertices;

    void clipToAxis(std::size_t axis, float boundary, bool keepGreater);
    bool clipTriangleToBounds(const SferaVec3F &first, const SferaVec3F &second, const SferaVec3F &third, const SferaVec3F &minimum, const SferaVec3F &maximum);
};

extern SferaPolygon3F g_sfera_clipped_polygon;

struct SferaViewProjectionScratchRuntime;

struct SferaViewProjectionScratchRuntime
{
    SferaVec3F corners[8];
    SferaIntBounds3 clipping_bounds;

    SferaViewProjectionScratchRuntime translated(const SferaVec3F &offset) const;
};
