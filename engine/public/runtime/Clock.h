#pragma once

#include <cstdint>

#include "numeric/Numeric.h"

class WorldClock;

class WorldClock
{
  public:
    // One process-lifetime epoch for UI, simulation, sound and transport.
    // A legacy tick is exactly 100 microseconds (10,000 ticks per second).
    static std::uint64_t microseconds() noexcept;
    static std::uint64_t nowTicks() noexcept
    {
        return microseconds() / 100u;
    }
    static std::uint32_t milliseconds() noexcept
    {
        return SferaNumeric::lowWord(microseconds() / 1000u);
    }
    static bool deadlineReached(std::uint32_t now, std::uint32_t deadline) noexcept
    {
        return SferaNumeric::signedWord(now - deadline) >= 0;
    }
    static std::uint32_t calendarTicks();
};
