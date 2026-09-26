#pragma once

#include <windows.h>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

struct GameUiElement;
struct GameUiElementSprite;
struct GameUiElementText;
struct GameUiElementTextLine;
struct GameUiWindow;

struct GameUiElementTextLine
{
    std::size_t offset;
    int x = 0, y = 0;
};

struct GameUiElementText
{
    std::string bytes;
    std::vector<GameUiElementTextLine> lines;
    int font_scale = 1;
    int font = 0;

  private:
    friend struct GameUiElementTextLine;
};

struct GameUiElementSprite
{
    std::string texture;
    int left = 0, top = 0, width = 0, height = 0;
};

struct GameUiElement
{
    std::variant<GameUiElementText, GameUiElementSprite> content = GameUiElementText{};
    std::uint32_t windowHandle = 0, windowSlot = UINT32_MAX;
    std::uint32_t objectHandle = UINT32_MAX;
    std::uint64_t resource_lifetime = 0;
    int left = 0, top = 0, right = 0, bottom = 0;
    float height_factor = 1.0f;
    std::uint32_t color = 0, alpha = 255;
    bool isText() const noexcept
    {
        return std::holds_alternative<GameUiElementText>(content);
    }
    void layoutText(std::string_view text, const GameUiWindow &window, int x, int y);

  private:
    friend struct GameUiElementText;
    friend struct GameUiElementSprite;

  private:
    static void fitAxis(int &begin, int &end, int maximum);
};


class SferaCanvasHost
{
  public:
    static GameUiElement *control(std::uint32_t handle);
    static void setTextExtent(int width, int height);
};

struct SferaScreenVertex;

class SferaCanvasRenderer
{
  public:
    static HRESULT drawSpriteQuad(std::uint32_t color, const float *uv, float left, float top, float right, float bottom);
    static HRESULT drawSpriteTexture(std::uint32_t color, int texture, float left, float top, float right, float bottom, const float *uv, bool reserved = false);
    static void drawTexture(int left, int top, int width, int height, std::string_view name, std::uint32_t alpha, float depth, const float *uv);
    static void tintTexture(int left, int top, int width, int height, std::string_view name, std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint32_t alpha, const float *uv);
    static void setRenderState();
    static void restoreRenderState();
    static void drawAtlasText(std::string_view text, int x, int y, std::uint32_t color, int scale, int font, float depth);
    static void drawOverlay(std::uint32_t alpha);
    static void drawElement(const GameUiElement &element, int scrollX, int scrollY, int x, int y, std::uint32_t alpha, float depth);
    static void beginWindow(const GameUiWindow &window);
    static void endWindow();

  private:
    static SferaScreenVertex sprite_quad[4];
    static void interfaceQuad(SferaScreenVertex *vertices, float left, float top, float right, float bottom, std::uint32_t color, const float *uv, float z, float reciprocal, bool clearSpecular);
    static void interfaceNamedQuad(int left, int top, int width, int height, std::string_view name, std::uint32_t color, std::uint32_t alpha, float depth, const float *uv, bool worldSpace);
};

struct GameUiHit;
struct GameUiWindowEvent;
struct SferaCursorPosition;

enum GameUiWindowTextStyle : std::uint32_t
{
    GameUiWindowcenterHorizontal = 1u,
    GameUiWindowcenterVertical = 2u,
    GameUiWindowfitHorizontal = 4u,
    GameUiWindowfitVertical = 8u,
    GameUiWindowcenterLines = 16u,
    GameUiWindowmeasureOnly = 32u,
    GameUiWindowalignBottom = 64u
};

struct GameUiWindowEvent
{
    std::uint32_t control, message;
};

struct GameUiWindow
{
    bool visible;
    bool scrollable;
    std::uint32_t opacity;
    int left, right, top, bottom;
    int contentLeft, contentRight, contentTop, contentBottom;
    int width, height;
    float scrollX, scrollY;
    std::uint32_t layer;
    std::vector<std::uint32_t> controls;
    std::uint64_t resource_lifetime = 0;
    std::uint32_t order;
    std::uint32_t textColor = 0u;
    std::uint32_t textStyle = 0u;
    int font = 0u;
    int fontScale = 1;

    std::deque<GameUiWindowEvent> events;
    std::uint32_t attach(std::uint32_t control);
    void detach(std::uint32_t slot);
    void recalculateSize();
    void enqueueInput(std::uint32_t control, std::uint32_t message)
    {
        if (events.size() < 10)
            events.push_back({control, message});
    }
    bool takeInput(std::uint32_t &control, std::uint32_t &message);
    SferaCursorPosition contentPosition(SferaCursorPosition point) const;
    void scrollBy(float dx, float dy, SferaCursorPosition &cursor);

  private:
    friend struct GameUiWindowEvent;

  private:
    static void clampAxis(float &scroll, int limit, int &position);
};

struct GameUiHit
{
    std::uint32_t window = 0u;
    std::uint32_t control = UINT32_MAX;
    bool border = false;
};
