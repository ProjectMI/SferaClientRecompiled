#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "math/Vector.h"

struct SphereRenderGrassBendingBasis;
struct SphereRenderGrassInfluence;
struct SphereRenderModelGrassData;
struct SphereRenderTreeInfluence;
struct SphereRenderVegetationVertex;

enum class SphereRenderVegetationKind : int
{
    None = -1,
    Grass = 0,
    SynchronizedGrass = 1,
    InteractiveGrass = 2,
    Tree = 3
};

enum class SphereRenderGrassInfluenceAnchor
{
    Fixed,
    Horizontal,
    Vertex
};

struct SphereRenderGrassInfluence
{
    SphereRenderGrassInfluenceAnchor anchor_kind = SphereRenderGrassInfluenceAnchor::Fixed;
    std::size_t anchor_vertex = 0;
    std::uint16_t phase = 0;
    bool share_phase = false;
    float distance = 0.0f;
};

struct SphereRenderTreeInfluence
{
    float amplitude = 0.0f;
    std::uint16_t phase = 0u;
};

struct SphereRenderGrassBendingBasis
{
    SferaVec3F first_axis{};
    SferaVec3F second_axis{};
    SferaVec3F anchor{};
};

struct SphereRenderVegetationVertex
{
    SferaVec3F position{};
    SferaVec3F normal{};
};

struct SphereRenderModelGrassData
{
    std::vector<SphereRenderGrassInfluence> influences;
    std::vector<SphereRenderGrassBendingBasis> bending;
};
