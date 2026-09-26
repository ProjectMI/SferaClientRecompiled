#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <string_view>

class SphereUIWindow;
enum class SphereUIUiControlKind;


class SphereUICDescriptionWindow;
class SphereUIRuntime;
struct SphereUITextExtent;

class SphereUIRuntime
{
  public:
    static std::uint32_t milliseconds();
    static bool keyDown(std::uint32_t key);

    static SphereUICDescriptionWindow *descriptionWindow();

    static SphereUITextExtent screenSize();
    static std::unique_ptr<SphereUIWindow> makeControl(SphereUIUiControlKind kind);

    static void playClickSound();

    static std::uint64_t clockTicks();
    static double elapsedSeconds(std::uint64_t started);

    static void setTextInputActive(bool active);
    static std::string_view keyName(std::uint32_t key);
    static std::uint32_t scanCode(std::uint32_t virtualKey);
    static std::uint32_t virtualKey(std::uint32_t scanCode);
    static void setSystemCursorVisible(bool visible);

  private:
  public:
    static void playUiSound(const std::string &filename);

  private:
  private:
    static std::array<std::string, 256> createKeyNames();
};
