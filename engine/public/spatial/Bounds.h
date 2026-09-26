#pragma once

#include "math/Vector.h"

struct SferaBoundsCornersRuntime;
struct SferaMatrix4x4F;
struct SphereWorldBounds;

struct SphereWorldBounds
{
    SferaVec3F minimum{};
    SferaVec3F maximum{};
    bool intersects(const SphereWorldBounds &other) const;
    bool intersectsInterior(const SphereWorldBounds &other) const;
    bool contains(const SphereWorldBounds &other) const;
    bool overlapsTriangle(const SferaVec3F (&vertices)[3]) const;
    SphereWorldBounds expanded(float amount) const;
    SphereWorldBounds inverseTransformed(const SferaMatrix4x4F &transform) const;
    SferaBoundsCornersRuntime corners() const;
};
