#pragma once

#include <cstdint>

struct SferaMouseInputState;

struct SferaMouseInputState
{
    int dx = 0;
    int dy = 0;
    std::uint32_t buttons = 0;
    int wheel = 0;
};

class SphereUIMouseInput;

class SphereUIMouseInput
{
  public:
    static constexpr std::uint32_t leftPress = 1u << 0u;
    static constexpr std::uint32_t rightPress = 1u << 1u;
    static constexpr std::uint32_t leftRelease = 1u << 2u;
    static constexpr std::uint32_t rightRelease = 1u << 3u;
    static constexpr std::uint32_t anyRelease = leftRelease | rightRelease;
};
