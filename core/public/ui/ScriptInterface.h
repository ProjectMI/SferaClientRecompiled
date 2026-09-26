#pragma once

#include <windows.h>
#include <algorithm>
#include <cstdint>
#include <memory>
#include <optional>
#include <string_view>
#include <utility>
#include <vector>

#include "diagnostics/ClientDiagnostics.h"
#include "numeric/Numeric.h"
#include "ui/Canvas.h"
#include "ui/Window.h"

class GameInterface;
struct GameUiElement;
struct SferaCursorPosition;
struct SferaScreenVertex;

enum class GameInterfaceWindowOrder
{
    Draw,
    HitTest
};

class GameInterface
{
  public:
    static int loading_completed;
    static uint32_t active_window;
    static int loading_total;
    static uint32_t loading_guard;

    static std::vector<std::unique_ptr<GameUiWindow>> windows;
    inline static constexpr std::string_view nativeWindowClassName = "SphereWclName";
    static void registerNativeWindowClass();
    static void createNativeWindow();
    static GameUiWindow *window(std::uint32_t handle, std::string_view operation = {});
    static std::uint32_t createWindow(int left, int top, int right, int bottom, std::uint32_t layer, std::uint32_t opacity);
    static void destroyWindow(std::uint32_t handle);
    static GameUiHit hitTest(SferaCursorPosition point);
    static void updateInput();
    static int fontHeight(int font, int scale);
    static int glyphWidth(std::uint32_t character, int font);
    static int textHeight(int font, int scale, int lines);
    static int lineOffset(int font, int scale, int line);
    static void drawAtlasText(std::string_view text, int x, int y, std::uint32_t color, int scale, int font, float depth);
    static HRESULT drawSpriteQuad(std::uint32_t color, const float *uv, float left, float top, float right, float bottom);
    static HRESULT drawSpriteTexture(std::uint32_t color, int texture, float left, float top, float right, float bottom, const float *uv, bool reserved = false);
    static void drawTexture(int left, int top, int width, int height, std::string_view name, std::uint32_t alpha, float depth, const float *uv);
    static void tintTexture(int left, int top, int width, int height, std::string_view name, std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint32_t alpha, const float *uv);
    static void drawFullscreenOverlay();
    static void setRenderState();
    static void restoreRenderState();
    static void drawFrame();

    static std::vector<std::uint32_t> orderedWindows(GameInterfaceWindowOrder order);
    static void drawAll();
    static void drawWindow(std::uint32_t window);
    static void updateLoadingProgress(int increment);
    static void finishLoading();

  private:
    static LRESULT CALLBACK main_window_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept;
    static void interfaceWindowBorder(const GameUiWindow &window);
    static void interfaceElement(const GameUiElement &element, int scrollX, int scrollY);
    static std::int32_t windowOrderKey(GameInterfaceWindowOrder order, std::uint32_t handle);
    static bool isWindowSlotUsed(const std::unique_ptr<GameUiWindow> &item);
};

class WorldGuiControlSupport;

class WorldGuiControlSupport
{
  public:
    template <class T> static std::uint32_t vacantGuiSlot(const std::vector<std::unique_ptr<T>> &slots);
    static void eraseGuiControl(std::uint32_t handle, const GameUiElement &item);
};

template <class T> std::uint32_t WorldGuiControlSupport::vacantGuiSlot(const std::vector<std::unique_ptr<T>> &slots)
{
    const auto slot = std::find(slots.begin(), slots.end(), nullptr);
    if (slot == slots.end())
        WorldDiagnostics::fail("Array bounds exceeded");
    return SferaNumeric::lowWord(slot - slots.begin());
}

struct GameUiWindow;
class WorldGuiControls;

class WorldGuiControls
{
  public:
    static uint32_t text_height;
    static uint32_t text_width;

    static std::vector<std::unique_ptr<GameUiElement>> elements;
    static std::uint32_t createText(int x, int y, std::string_view text, std::uint32_t window);
    static std::uint32_t createSprite(int x, int y, int width, int height, std::string_view texture, std::uint32_t window, std::uint32_t alpha);
    static void setAppearance(std::uint32_t handle, std::uint32_t alpha, std::optional<std::uint32_t> color = std::nullopt);
    static void destroyAllText();
    static GameUiElement *control(std::uint32_t handle);
    static void detachFromWindow(std::uint32_t window, std::uint32_t slot);
    static void destroySprite(std::uint32_t handle);
    static void destroyText(std::uint32_t handle);
    static void removeForObject(std::uint32_t handle);

  private:
    template <class Build> static std::uint32_t createGuiControl(std::uint32_t windowHandle, std::string_view operation, Build &&build);
    static bool buildText(int x, int y, std::string_view text, GameUiElement &item, const GameUiWindow &window);
    static bool buildSprite(int x, int y, int width, int height, std::string_view texture, std::uint32_t alpha, GameUiElement &item, const GameUiWindow &window);
};

template <class Build> std::uint32_t WorldGuiControls::createGuiControl(std::uint32_t windowHandle, std::string_view operation, Build &&build)
{
    auto *window = GameInterface::window(windowHandle, operation);
    if (!window)
    {
        windowHandle = 0;
        window = GameInterface::window(windowHandle);
    }
    if (!window)
        WorldDiagnostics::fail("create_control: root window is unavailable");
    const std::uint32_t handle = WorldGuiControlSupport::vacantGuiSlot(WorldGuiControls::elements);
    auto item = std::make_unique<GameUiElement>();
    item->windowHandle = windowHandle;
    const bool keep = build(*item, *window);
    item->windowSlot = window->attach(handle);
    WorldGuiControls::elements[handle] = std::move(item);
    if (!keep)
    {
        WorldGuiControlSupport::eraseGuiControl(handle, *WorldGuiControls::elements[handle]);
        return UINT32_MAX;
    }
    window->recalculateSize();
    return handle;
}

class SphereUICMinimapControl;
struct SphereUIWindowCloneContext;

class SphereUICMinimapControl : public SphereUIWindow
{
  public:
    SphereUICMinimapControl();

    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    void draw() override;

  private:
    static void cloneProperties(SphereUICMinimapControl &target, const SphereUICMinimapControl &source, SphereUIWindowCloneContext &);

  private:
    static bool playerHeading(float &heading);
};
