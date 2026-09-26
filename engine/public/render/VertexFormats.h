#pragma once

#include <cstdint>

#include "math/Vector.h"

struct SferaScreenVertex;
struct SphereRenderPositionColorUvVertex;
struct SphereRenderPositionNormalUvVertex;

struct SferaScreenVertex
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float rhw;
    std::uint32_t diffuse;
    std::uint32_t specular;
    float u;
    float v;
};

struct SphereRenderPositionNormalUvVertex
{
    SferaVec3F position;
    SferaVec3F normal;
    float u;
    float v;
};

struct SphereRenderPositionColorUvVertex
{
    SferaVec3F position;
    std::uint32_t diffuse;
    std::uint32_t specular;
    float u;
    float v;
};
