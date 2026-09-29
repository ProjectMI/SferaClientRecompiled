#pragma once

#include <bit>
#include "script/MbcValue.h"

namespace SferaNative
{
inline SferaMbcValue integer(std::uint32_t bits, std::size_t width = 4)
{
    return {SferaMbcValueTypeInteger, width, {UINT32_MAX, 1, 1}, {bits, 0, 0}};
}
inline SferaMbcValue real(float value, std::size_t width = 4)
{
    return {SferaMbcValueTypeReal, width, {UINT32_MAX, 1, 1}, {std::bit_cast<std::uint32_t>(value), 0, 0}};
}
}
