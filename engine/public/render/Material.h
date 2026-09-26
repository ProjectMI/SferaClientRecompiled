#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <vector>

struct SphereRenderMaterial;
struct WaterMaterial;

struct SphereRenderMaterial
{
    std::string name;
    std::vector<int> textures;
    std::array<float, 4> color{};
    std::array<float, 3> colorVariation{};
    bool hasColorVariation = false;
    static std::uint32_t randomColor(const std::array<float, 3> &variation);
};

struct WaterMaterial
{
    int primary_animation;
    int secondary_animation;
    float primary_opacity;
    float secondary_opacity;
    float reflection_opacity;
    float wave_amplitude;
};
