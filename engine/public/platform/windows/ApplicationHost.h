#pragma once

#include <windows.h>
#include <cstdint>

class SferaApplicationHost
{
  public:
    static HWND mainWindow();
    static bool active();
    static float measuredFramesPerSecond();
    static std::uint32_t frameElapsedTicks();
};
