#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "ui/Window.h"

struct SphereUIUiSprite;

struct SferaCursorPosition;
class SphereUICDescriptionWindow;
struct SphereUIWindowCloneContext;
struct SphereUIWindowEvent;

class SphereUICDescriptionWindow : public SphereUIWindow
{
  public:
    SphereUICDescriptionWindow *asDescriptionWindow() noexcept override
    {
        return this;
    }
    const SphereUICDescriptionWindow *asDescriptionWindow() const noexcept override
    {
        return this;
    }

    const SphereUIWindow *displayed_source{};
    const SphereUIWindow *pending_source{};
    std::uint32_t show_deadline{};
    std::uint32_t hide_deadline{};
    std::shared_ptr<const SphereUIUiSprite> caption_sprite{};
    std::shared_ptr<const SphereUIUiSprite> bottom_sprite{};
    std::shared_ptr<const SphereUIUiSprite> left_sprite{};
    std::shared_ptr<const SphereUIUiSprite> right_sprite{};
    int frame_height{};
    bool pinned{};
    SphereUICDescriptionWindow();
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;

    static SphereUICDescriptionWindow *instance();
    void close();
    void update();
    void handleEvent(const SphereUIWindowEvent &event);
    SferaCursorPosition *calculatePosition(SferaCursorPosition *output) const;
    void showDescription(std::string_view text, const SphereUIWindow *source, std::uint32_t duration, bool pin);
    void requestDescription(std::string_view text, bool force, const SphereUIWindow *source);
    void draw() override;
    ~SphereUICDescriptionWindow() override;

  private:
    explicit SphereUICDescriptionWindow(std::in_place_t)
    {
    }

  private:
    static void drawChild(SphereUIWindow &child)
    {
        child.draw();
    }
    static void selectFirstChild(SphereUIWindow *&content, SphereUIWindow &child)
    {
        if (content == nullptr)
            content = &child;
    }
    static int placeAxis(int position, int extent, int limit, int size, bool centered);

  private:
    static bool descriptionAutoPopup();
    static void setDescriptionWindow(SphereUICDescriptionWindow *window);
};

struct SferaParserRange;
class SferaSimpleParser;
class SphereUIToolTipCtrl;

class SphereUIToolTipCtrl : public SphereUIWindow
{
  public:
    SphereUIToolTipCtrl *asToolTipCtrl() noexcept override
    {
        return this;
    }
    const SphereUIToolTipCtrl *asToolTipCtrl() const noexcept override
    {
        return this;
    }
    int screen_x{};
    int screen_y{};
    bool hover_pending{};

    std::uint64_t hover_started{};
    float fade_opacity{};

    std::uint64_t fade_started{};
    std::uint32_t background_color{};
    int tooltip_width{};
    int tooltip_height{};
    bool dismissed{};

    std::vector<std::string> lines{};
    int line_height{};
    int margin_left{};
    int margin_top{};
    int margin_right{};
    int margin_bottom{};
    SphereUIToolTipCtrl();

    void reset();
    void showAt(int x, int y);
    void updateFade();
    void updateLayout();
    void appendLine(std::string_view line_text)
    {
        lines.emplace_back(line_text);
        updateLayout();
    }
    void setLine(std::uint32_t index, std::optional<std::string_view> text);
    void setLine(std::uint32_t, std::nullptr_t) = delete;
    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;

  private:
    static void copyCloneState(SphereUIToolTipCtrl &destination, const SphereUIToolTipCtrl &source, SphereUIWindowCloneContext &);
};
