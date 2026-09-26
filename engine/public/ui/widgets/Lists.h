#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include "ui/Rendering.h"
#include "ui/Sprite.h"
#include "ui/UiTypes.h"
#include "ui/Window.h"
#include "ui/widgets/Controls.h"

struct SferaParserRange;
class SferaSimpleParser;
class SphereUIListCtrl;
struct SphereUIUiTextRow;
struct SphereUIWindowCloneContext;

struct SphereUIUiTextRow
{
    std::string text;
    std::uint32_t color{};
    int offset{};
};

class SphereUIListCtrl : public SphereUIWindow
{
  public:
    SphereUIListCtrl *asListCtrl() noexcept override
    {
        return this;
    }
    const SphereUIListCtrl *asListCtrl() const noexcept override
    {
        return this;
    }
    std::ptrdiff_t visible_begin{};
    std::ptrdiff_t visible_end{};
    std::vector<SphereUIUiTextRow> rows{};
    std::size_t maximum_items{};
    std::size_t write_index{};
    int maximum_scroll{};
    int line_height{};
    std::ptrdiff_t visible_capacity{};
    int vertical_offset{};
    int cropped_y{};
    bool chatlike{};
    bool format_strings{};
    bool continue_mark{};

    std::unique_ptr<SphereUIScrollBar> scrollbar;
    bool can_select{};

    std::ptrdiff_t selected_index{};
    int selection_border{};
    std::uint32_t selection_color{};
    std::uint32_t selection_line_color{};
    std::uint64_t click_time{};
    bool click_pending{};

    SphereUIListCtrl();

    void copyListState(const SphereUIListCtrl &source, SphereUIWindowCloneContext &context);
    void updateLayout();
    void updateVisibleRange();
    std::size_t physicalIndex(std::size_t logical_index) const;
    void appendLine(std::string_view text, std::uint32_t color);
    void appendFormattedLine(std::string_view text, std::uint32_t color);
    void addText(std::string_view text, std::uint32_t color);
    void appendMessageText(std::string_view text, std::uint32_t color);
    bool setRowText(std::size_t index, std::string_view text);
    std::string_view rowText(std::size_t index) const;
    void clearRows();
    void removeRow(std::size_t logical_index);
    void selectRow(int index)
    {
        if (index >= 0 && index < rows.size())
            selected_index = index;
    }
    void alignRow(std::size_t index, std::uint32_t flags);
    void drawSelection(int x, int y, int row_y, bool restore_viewport);
    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;

  private:
    static std::uint32_t modulatedColor(std::uint32_t color, std::uint32_t alpha);
    template <class Emit> static void wrapTextLine(const SphereUIWindow &window, std::string_view text, bool wrap, Emit emit);

  private:
    static void copyCloneState(SphereUIListCtrl &destination, const SphereUIListCtrl &source, SphereUIWindowCloneContext &context)
    {
        destination.copyListState(source, context);
    }
    void appendWrappedLine(std::uint32_t color, std::string_view line)
    {
        appendLine(line, color);
    }

  private:
    static int measuredTextWidth(const SphereUIWindow &window, std::string_view value);
};

template <class Emit> void SphereUIListCtrl::wrapTextLine(const SphereUIWindow &window, std::string_view text, bool wrap, Emit emit)
{
    auto remaining = text;

    while (wrap && remaining.size() > 1u && measuredTextWidth(window, remaining) > window.width)
    {
        std::size_t fit = 0u, boundary = 0u;
        for (std::size_t index = 1u; index <= remaining.size(); ++index)
        {
            if (measuredTextWidth(window, remaining.substr(0u, index)) > window.width)
                break;
            fit = index;
            if (remaining[index - 1u] == ' ' || remaining[index - 1u] == ':' || remaining[index - 1u] == ';')
                boundary = index;
        }
        const auto count = boundary != 0u ? boundary : std::max(fit, std::size_t{1u});
        emit(remaining.substr(0u, count));
        remaining.remove_prefix(count);
    }
    emit(remaining);
}
inline int SphereUIListCtrl::measuredTextWidth(const SphereUIWindow &window, std::string_view value)
{
    return SphereUIInterfaceRenderer::measureText(value, window.font, true).width - (window.font < 2u ? 2 : 0);
}

class SphereUIFilterListCtrl;
struct SphereUIFilterListCtrlHistoryEntry;

struct SphereUIFilterListCtrlHistoryEntry
{
    std::string text;
    std::uint32_t color{};
    std::uint32_t filter{};
};

class SphereUIFilterListCtrl : public SphereUIListCtrl
{
  public:
    SphereUIFilterListCtrl *asFilterListCtrl() noexcept override
    {
        return this;
    }
    const SphereUIFilterListCtrl *asFilterListCtrl() const noexcept override
    {
        return this;
    }
    std::uint32_t filter_mask{};

    std::vector<SphereUIFilterListCtrlHistoryEntry> history;
    std::size_t history_write{};
    SphereUIFilterListCtrl();

    void clearHistory()
    {
        history.clear();
        history_write = 0u;
    }
    void appendHistory(std::string_view text, std::uint32_t color, std::uint32_t mask);
    void appendFilteredText(std::string_view text, std::uint32_t packed_color);
    void applyFilter(std::uint32_t mask);
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;

  private:
    static void copyCloneState(SphereUIFilterListCtrl &destination, const SphereUIFilterListCtrl &source, SphereUIWindowCloneContext &context);
};

class SphereUIListItemCtrl;

class SphereUIListItemCtrl : public SphereUIWindow
{
  public:
    SphereUIListItemCtrl *asListItemCtrl() noexcept override
    {
        return this;
    }
    const SphereUIListItemCtrl *asListItemCtrl() const noexcept override
    {
        return this;
    }
    std::unique_ptr<SphereUIWindow> item_template;
    std::vector<std::unique_ptr<SphereUIWindow>> items;
    int horizontal_offset{};
    int vertical_offset{};
    std::ptrdiff_t visible_begin{};
    std::ptrdiff_t visible_end{};
    std::ptrdiff_t visible_capacity{};
    int cropped_x{};
    int cropped_y{};
    int maximum_y{};
    int maximum_x{};
    std::unique_ptr<SphereUIScrollBar> vertical_scroll;
    std::unique_ptr<SphereUIScrollBar> horizontal_scroll;
    bool can_select{};

    std::shared_ptr<const SphereUIUiSprite> selection_sprite{};
    std::ptrdiff_t selected_index{};
    bool horizontal{};
    bool user_move{};

    SphereUIListItemCtrl();

    SphereUIWindow *itemAt(std::size_t index) const;
    void addItem();
    void removeItem(std::size_t index);
    void clearItems();
    void updateLayout();
    void updateVisibleRange();
    void copyItemState(const SphereUIListItemCtrl &source, SphereUIWindowCloneContext &context);
    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;
    void setOpacity(float opacity) override;
    bool hitTest(int screen_x, int screen_y) override;
    void dispatchMessage(int target_group, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second, SphereUIUiControlKind target_kind) override;

  private:
    static void copyCloneState(SphereUIListItemCtrl &destination, const SphereUIListItemCtrl &source, SphereUIWindowCloneContext &context)
    {
        destination.copyItemState(source, context);
    }
};

class SphereUISlotCtrl;

class SphereUISlotCtrl : public SphereUIWindow
{
  public:
    SphereUISlotCtrl *asSlotCtrl() noexcept override
    {
        return this;
    }
    const SphereUISlotCtrl *asSlotCtrl() const noexcept override
    {
        return this;
    }
    std::shared_ptr<const SphereUIUiSprite> full_sprite{};
    std::shared_ptr<const SphereUIUiSprite> empty_sprite{};
    std::shared_ptr<const SphereUIUiSprite> border_sprite{};
    std::uint32_t fill_alpha{};
    std::uint32_t fill_color{};
    std::uint32_t border_color{};
    int image_offset_x{};
    int image_offset_y{};
    SphereUIUiSprite item_image{};
    bool show_full_background{};
    bool has_item{};

    std::int64_t press_x{};
    std::int64_t press_y{};
    bool left_pressed{};
    bool right_pressed{};
    bool drag_started{};

    std::string description{};
    int count_offset_x{};
    int count_offset_y{};
    std::uint32_t item_count{};
    std::shared_ptr<const SphereUIUiSprite> top_left_overlay{};
    std::shared_ptr<const SphereUIUiSprite> bottom_right_overlay{};
    std::shared_ptr<const SphereUIUiSprite> bottom_left_overlay{};
    SphereUISlotCtrl();

    void setItem(std::optional<std::string_view> image);
    void setItem(std::nullptr_t) = delete;
    void setItemCount(std::uint32_t count);
    void setOverlay(std::shared_ptr<const SphereUIUiSprite> &destination, std::optional<std::string_view> image);
    void setOverlay(std::shared_ptr<const SphereUIUiSprite> &, std::nullptr_t) = delete;
    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;
    bool hitTest(int screen_x, int screen_y) override;

  private:
    static void cloneProperties(SphereUISlotCtrl &destination, const SphereUISlotCtrl &source, SphereUIWindowCloneContext &);
};

class SphereUICMenuListControl;
struct SphereUIUiMenuItem;

struct SphereUIUiMenuItem
{
    std::string text;
    bool enabled{};
};

class SphereUICMenuListControl : public SphereUIWindow
{
  public:
    SphereUICMenuListControl *asMenuListControl() noexcept override
    {
        return this;
    }
    const SphereUICMenuListControl *asMenuListControl() const noexcept override
    {
        return this;
    }
    std::size_t maximum_items{};
    std::shared_ptr<const SphereUIUiSprite> top_sprite{};
    std::shared_ptr<const SphereUIUiSprite> middle_sprite{};
    std::shared_ptr<const SphereUIUiSprite> hovered_sprite{};
    std::shared_ptr<const SphereUIUiSprite> bottom_sprite{};
    std::uint32_t title_color{};
    std::uint32_t normal_color{};
    std::uint32_t hovered_color{};
    std::uint32_t item_disabled_color{};
    bool show_title{};

    SphereUIUiRect title_margin{};
    std::uint32_t title_format{};
    SphereUIUiRect item_margin{};
    std::uint32_t item_format{};
    SphereUITextExtent top_size{};
    SphereUITextExtent item_size{};
    SphereUITextExtent bottom_size{};
    int parent_screen_x{};
    int parent_screen_y{};
    int parent_width{};
    int parent_height{};
    std::vector<SphereUIUiMenuItem> items{};
    std::size_t hovered_index{};
    SphereUICMenuListControl();

    void addItem(std::string_view text, bool enabled);
    void clearItems();
    void closeMenu();
    void updateParentPosition();
    void keepOnScreen();
    std::size_t itemAtPoint(std::int64_t x, std::int64_t y) const;
    void drawHeader();
    void drawItem(std::size_t index, const std::shared_ptr<const SphereUIUiSprite> &sprite, std::uint32_t color);
    void drawFooter();
    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;

  private:
    static void menuLabel(const SphereUIWindow &window, std::string_view text, const SphereUIUiRect &margins, const SphereUITextExtent &size, std::uint32_t format, std::uint32_t color, int left,
                          int top, const SphereUIUiRect &clip);

  private:
    static void copyCloneState(SphereUICMenuListControl &destination, const SphereUICMenuListControl &source, SphereUIWindowCloneContext &);
    static SphereUITextExtent spriteDimensions(const std::shared_ptr<const SphereUIUiSprite> &sprite);
};
