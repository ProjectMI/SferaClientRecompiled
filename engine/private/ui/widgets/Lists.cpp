#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iterator>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

#include "input/Cursors.h"
#include "input/MouseInput.h"
#include "math/Color.h"
#include "numeric/Numeric.h"
#include "ui/Rendering.h"
#include "ui/Sprite.h"
#include "ui/UiHost.h"
#include "ui/UiRuntime.h"
#include "ui/UiTypes.h"
#include "ui/WidgetSupport.h"
#include "ui/Window.h"
#include "ui/widgets/Controls.h"
#include "ui/widgets/Lists.h"
#include "ui/widgets/Popups.h"

std::unique_ptr<SphereUIWindow> SphereUIFilterListCtrl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIFilterListCtrl::copyCloneState);
}

std::uint32_t SphereUIFilterListCtrl::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::clearFilteredList:
        clearHistory();
        clearRows();
        return 1u;
    case SphereUIUiMessage::setListFilter:
        applyFilter(first);
        return 1u;
    default:
        return SphereUIListCtrl::handleMessage(message, first, second);
    }
}

SphereUIFilterListCtrl::SphereUIFilterListCtrl()
{
    filter_mask = 255u;
    control_kind = SphereUIUiControlKind::filteredList;
}

void SphereUIFilterListCtrl::appendHistory(std::string_view history_text, std::uint32_t color, std::uint32_t mask)
{
    SphereUIWidgetSupport::appendCircular(history, maximum_items, history_write, SphereUIFilterListCtrlHistoryEntry{std::string(history_text), color, mask});
}

void SphereUIFilterListCtrl::appendFilteredText(std::string_view filtered_text, std::uint32_t packed_color)
{
    const auto components = SferaColor::fromArgb(packed_color);
    const auto mask = components.alpha();
    const auto color = components.withAlpha(0u).argb();
    const std::string value(filtered_text);
    appendHistory(value, color, mask);
    if ((filter_mask & mask) != 0u)
        appendMessageText(filtered_text, color);
}

void SphereUIFilterListCtrl::applyFilter(std::uint32_t mask)
{
    if (mask == filter_mask)
        return;
    filter_mask = mask;
    if (history.size() == 0u)
        return;
    clearRows();
    for (std::size_t index = 0u; index < history.size(); ++index)
    {
        const auto &row = history.at(index);
        if ((row.filter & mask) != 0u)
            addText(row.text, row.color);
    }
}

void SphereUIFilterListCtrl::copyCloneState(SphereUIFilterListCtrl &destination, const SphereUIFilterListCtrl &source, SphereUIWindowCloneContext &context)
{
    destination.copyListState(source, context);
    destination.filter_mask = source.filter_mask;
    destination.history = source.history;
    destination.history_write = source.history_write;
}

std::unique_ptr<SphereUIWindow> SphereUIListItemCtrl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIListItemCtrl::copyCloneState);
}

std::uint32_t SphereUIListItemCtrl::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::horizontalScroll:
        horizontal_offset = first;
        updateVisibleRange();
        return 1u;
    case SphereUIUiMessage::verticalScroll:
        vertical_offset = first;
        updateVisibleRange();
        return 1u;
    case SphereUIUiMessage::updateScrollLayout:
        if (first != 0u)
            updateLayout();
        else
            for (auto address : {vertical_scroll.get(), horizontal_scroll.get()})
                if (auto *bar = address)
                    bar->setParameters({0u, ScrollField::all, 0, 0, 0, 0, 0});
        return 1u;
    case SphereUIUiMessage::appendListItem:
        addItem();
        updateLayout();
        return 1u;
    case SphereUIUiMessage::setListItemSelection:
        selected_index = first < items.size() ? first : -1;
        return 1u;
    case SphereUIUiMessage::removeListItem:
        if (first < items.size())
        {
            removeItem(first);
            updateLayout();
        }
        return 1u;
    case SphereUIUiMessage::clearListItems:
        clearItems();
        updateLayout();
        return 1u;
    default:
        return SphereUIWindow::handleMessage(message, first, second);
    }
}

void SphereUIListItemCtrl::draw()
{
    if (hidden || (behavior_flags & SphereUIWindowStyle::skipDrawing) != 0u)
        return;
    SphereUIWidgetSupport::drawChild(vertical_scroll.get(), alpha);
    SphereUIWidgetSupport::drawChild(horizontal_scroll.get(), alpha);
    if (item_template == nullptr)
        return;
    const auto end = std::min(visible_end, std::ssize(items));
    {
        SphereUIViewportScope viewport(SphereUIWidgetSupport::windowBounds(*this));
        if (!viewport)
            return;
        if (selected_index >= std::max(visible_begin, std::ptrdiff_t{}) && selected_index < end)
            if (auto *item = itemAt(selected_index))
            {
                const float left = SferaNumeric::real32(item->x), top = SferaNumeric::real32(item->y);
                const float right = SferaNumeric::real32(SphereUIDetail::addCoordinate(item->x, item->width));
                const float bottom = SferaNumeric::real32(SphereUIDetail::addCoordinate(item->y, item->height));
                if (selection_sprite != nullptr)
                    selection_sprite->draw(left, top, right, bottom, SferaColor::rgba(255u, 255u, 255u, alpha).argb());
                else
                    SphereUIInterfaceRenderer::drawTexture(nullptr, left, top, right, bottom, text_color, 0.0f, 0.0f, false);
            }
        for (auto index = std::max(visible_begin, std::ptrdiff_t{}); index < end; ++index)
            if (auto *item = itemAt(index))
                item->draw();
    }
    for (auto index = std::max(visible_begin, std::ptrdiff_t{}); index < end; ++index)
        if (auto *item = itemAt(index))
            item->drawToolTips();
}

void SphereUIListItemCtrl::handleInput(const SphereUIWindowInput &input)
{
    if (hidden)
        return;
    SphereUIWidgetSupport::inputChild(vertical_scroll.get(), input);
    SphereUIWidgetSupport::inputChild(horizontal_scroll.get(), input);
    if (!can_select)
        selected_index = -1;
    for (std::size_t index = 0u; index < items.size(); ++index)
        if (auto *item = itemAt(index))
        {
            SphereUIWindowEvent event{};
            while (item->pollEvent(event))
                if (auto *owner = parent)
                    owner->queueEvent({this, control_id, SphereUIUiMessage::listItemEvent, SferaNumeric::enumBits(event.message), SferaNumeric::word(MAKELONG(index, event.control_id))});
        }
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    const bool inside = SphereUIWidgetSupport::contains(bounds, input.mouse_x, input.mouse_y);
    SphereUIWindowInput forwarded = input;
    if (!inside)
        forwarded.mouse_x = forwarded.mouse_y = 65535;
    const auto *original = item_template.get();
    if (original == nullptr)
        return;
    const auto end = std::min(visible_end, std::ssize(items));
    auto item_x = SphereUIDetail::subtractCoordinate(bounds.left, cropped_x), item_y = SphereUIDetail::subtractCoordinate(bounds.top, cropped_y);
    for (auto index = std::max(visible_begin, std::ptrdiff_t{}); index < end; ++index)
        if (auto *item = itemAt(index))
        {
            if (user_move)
                item->setParent(this);
            else
                item->setPosition(item_x, item_y);
            item->handleInput(forwarded);
            if (horizontal)
                item_x = SphereUIDetail::addCoordinate(item_x, original->width);
            else
                item_y = SphereUIDetail::addCoordinate(item_y, original->height);
        }
    if (!can_select || !inside || (input.mouse_flags & SphereUIMouseInput::leftPress) == 0u)
        return;
    std::ptrdiff_t selected = -1;
    for (auto index = std::max(visible_begin, std::ptrdiff_t{}); index < end; ++index)
        if (auto *item = itemAt(index))
            if (SphereUIWidgetSupport::contains(SphereUIWidgetSupport::windowBounds(*item), input.mouse_x, input.mouse_y))
            {
                selected = index;
                break;
            }
    if (selected != selected_index)
    {
        SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::listItemSelectionChanged, SphereUIDetail::wireWord(selected));
        selected_index = selected;
    }
}

void SphereUIListItemCtrl::setOpacity(float opacity)
{
    const auto new_alpha = SphereUIWidgetSupport::opacity_alpha(opacity * 255.0);
    alpha = new_alpha;
    SphereUIWidgetSupport::replace_color_alpha(text_color, new_alpha);
    if (auto *original = item_template.get())
        original->setOpacity(opacity);
    for (std::size_t index = 0u; index < items.size(); ++index)
        if (auto *item = itemAt(index))
            item->setOpacity(opacity);
}

bool SphereUIListItemCtrl::hitTest(int screen_x, int screen_y)
{
    const auto end = std::min(visible_end, std::ssize(items));
    if (hidden || visible_begin >= end)
        return false;
    for (auto index = std::max(visible_begin, std::ptrdiff_t{}); index < end; ++index)
        if (auto *child = itemAt(index))
            if (child->can_drag_drop && child->containsPoint(screen_x, screen_y) && child->hitTest(screen_x, screen_y))
                break;
    return true;
}

void SphereUIListItemCtrl::dispatchMessage(int target_group, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second, SphereUIUiControlKind target_kind)
{
    for (std::size_t index = 0u; index < items.size(); ++index)
        if (auto *child = itemAt(index))
            child->dispatchMessage(target_group, message, first, second, target_kind);
}

SphereUIListItemCtrl::SphereUIListItemCtrl()
{
    selected_index = -1;
    hidden = false;
    control_kind = SphereUIUiControlKind::listItem;
}

SphereUIWindow *SphereUIListItemCtrl::itemAt(std::size_t index) const
{
    return index < items.size() ? items.at(index).get() : nullptr;
}

void SphereUIListItemCtrl::addItem()
{
    if (!item_template)
        return;
    std::unique_ptr<SphereUIWindow> item(item_template->clone());
    if (!item)
        return;
    item->hidden = false;
    items.push_back(std::move(item));
    return;
}

void SphereUIListItemCtrl::clearItems()
{
    items.clear();
}

void SphereUIListItemCtrl::removeItem(std::size_t index)
{
    if (index >= items.size())
        return;
    items.erase(items.begin() + index);
    bool changed = std::cmp_equal(index, selected_index);
    if (changed)
        selected_index = -1;
    if (selected_index < 0 || selected_index >= std::ssize(items))
    {
        selected_index = std::ssize(items) - 1;
        changed = true;
    }
    if (changed && can_select)
        SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::listItemSelectionChanged, SphereUIDetail::wireWord(selected_index));
}

void SphereUIListItemCtrl::updateVisibleRange()
{
    const auto *original = item_template.get();
    if (original == nullptr)
        return;
    horizontal_offset = std::clamp(horizontal_offset, 0, std::max(maximum_x, 0));
    vertical_offset = std::clamp(vertical_offset, 0, std::max(maximum_y, 0));
    const auto extent = !horizontal ? original->height : original->width;
    const auto offset = !horizontal ? vertical_offset : horizontal_offset;
    const auto fraction = extent > 0 ? 1.0f * offset / extent : 0.0f;
    const auto integral = std::floor(fraction);
    const int cropped = extent > 0 ? SferaNumeric::truncateInt((fraction - integral) * extent) : 0;
    visible_begin = SferaNumeric::truncateInt(integral);
    visible_end = std::min(visible_begin + visible_capacity + std::ptrdiff_t{1}, std::ssize(items));
    cropped_x = !horizontal ? horizontal_offset : cropped;
    cropped_y = !horizontal ? cropped : vertical_offset;
    if (user_move)
    {
        cropped_x = cropped_y = 0;
        visible_begin = 0;
        visible_end = std::ssize(items);
    }
}

void SphereUIListItemCtrl::updateLayout()
{
    const auto *original = item_template.get();
    if (original == nullptr)
        return;
    const auto extent = !horizontal ? original->height : original->width;
    const auto available = !horizontal ? height : width;
    visible_capacity = extent > 0 ? available / extent + 1 : 0;
    const auto total_width = horizontal ? SphereUIDetail::multiplyCoordinate(items.size(), original->width) : original->width;
    const auto total_height = !horizontal ? SphereUIDetail::multiplyCoordinate(items.size(), original->height) : original->height;
    maximum_x = std::max(0, SphereUIDetail::subtractCoordinate(total_width, width));
    maximum_y = std::max(0, SphereUIDetail::subtractCoordinate(total_height, height));
    horizontal_offset = std::clamp(horizontal_offset, 0, maximum_x);
    vertical_offset = std::clamp(vertical_offset, 0, maximum_y);
    if (auto *bar = vertical_scroll.get())
        bar->setParameters({0u, ScrollField::all, 0, maximum_y, height, vertical_offset, original->height / 10 + 1});
    if (auto *bar = horizontal_scroll.get())
        bar->setParameters({0u, ScrollField::all, 0, maximum_x, width, horizontal_offset, maximum_x / 10 + 1});
    updateVisibleRange();
}

void SphereUIListItemCtrl::copyItemState(const SphereUIListItemCtrl &source, SphereUIWindowCloneContext &context)
{
    if (this == &source)
        return;
    clearItems();
    SphereUIWidgetSupport::copyProperties(*this, source, &SphereUIListItemCtrl::horizontal_offset, &SphereUIListItemCtrl::vertical_offset, &SphereUIListItemCtrl::visible_begin,
                                          &SphereUIListItemCtrl::visible_end, &SphereUIListItemCtrl::visible_capacity, &SphereUIListItemCtrl::cropped_x, &SphereUIListItemCtrl::cropped_y,
                                          &SphereUIListItemCtrl::maximum_x, &SphereUIListItemCtrl::maximum_y, &SphereUIListItemCtrl::can_select, &SphereUIListItemCtrl::selection_sprite,
                                          &SphereUIListItemCtrl::selected_index, &SphereUIListItemCtrl::horizontal, &SphereUIListItemCtrl::user_move);
    SphereUIWidgetSupport::cloneOwned(item_template, source.item_template, *this, context);
    if (item_template)
        item_template->parent = source.item_template->parent;
    items.reserve(source.items.size());
    for (const auto &item : source.items)
        items.push_back(item ? item->cloneInto(context) : nullptr);
    SphereUIWidgetSupport::cloneOwned(vertical_scroll, source.vertical_scroll, *this, context);
    SphereUIWidgetSupport::cloneOwned(horizontal_scroll, source.horizontal_scroll, *this, context);
}

bool SphereUISlotCtrl::hitTest(int, int)
{
    if (hidden)
        return false;
    if (auto *owner = parent)
        owner->queueEvent({this, control_id, SphereUIUiMessage::slotHitTest, 0u, 0u});
    return true;
}

SphereUISlotCtrl::SphereUISlotCtrl()
{
    fill_alpha = 128u;
    fill_color = UiColor::slotFill;
    border_color = UiColor::slotBorder;
    count_offset_x = -2;
    count_offset_y = 2;
    font = 2u;
    hidden = false;
    control_kind = SphereUIUiControlKind::slot;
    can_drag_drop = true;
    text_alignment = TextAlignment::right;
    text_color = UiColor::white;
}

void SphereUISlotCtrl::setOverlay(std::shared_ptr<const SphereUIUiSprite> &destination, std::optional<std::string_view> image)
{
    if (!image)
    {
        destination.reset();
        return;
    }
    auto replacement = std::make_shared<SphereUIUiSprite>();
    replacement->setImage(*image);
    destination = std::move(replacement);
}

void SphereUISlotCtrl::setItem(std::optional<std::string_view> image)
{
    if (!image)
    {
        show_full_background = true;
        has_item = false;
        setText("");
        description.assign("");
        item_count = 0u;
        setOverlay(top_left_overlay, std::nullopt);
        setOverlay(bottom_right_overlay, std::nullopt);
        setOverlay(bottom_left_overlay, std::nullopt);
        return;
    }
    if (item_image.name != *image)
        item_image.setImage(*image);
    show_full_background = false;
    has_item = true;
}

void SphereUISlotCtrl::setItemCount(std::uint32_t count)
{
    if (count == item_count)
        return;
    setText(count == 0u ? "" : std::to_string(count));
    item_count = count;
}

std::unique_ptr<SphereUIWindow> SphereUISlotCtrl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUISlotCtrl::cloneProperties);
}

std::uint32_t SphereUISlotCtrl::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::setSlotHighlight:
        if (first == 0u)
        {
            fill_alpha = 128u;
            fill_color = UiColor::slotFill;
            border_color = UiColor::slotBorder;
        }
        else if (first <= 2u)
        {
            fill_alpha = 140u;
            fill_color = border_color = first == 1u ? UiColor::slotRejected : UiColor::slotAccepted;
        }
        break;
    case SphereUIUiMessage::setSlotCount:
        setItemCount(first);
        break;
    case SphereUIUiMessage::setSlotFillColor:
        fill_color = first;
        break;
    case SphereUIUiMessage::setSlotFillAlpha:
        fill_alpha = first;
        break;
    case SphereUIUiMessage::setSlotBorderColor:
        border_color = first;
        break;
    default:
        return SphereUIWindow::handleMessage(message, first, second);
    }
    return 1u;
}

void SphereUISlotCtrl::draw()
{
    if (hidden || (behavior_flags & SphereUIWindowStyle::skipDrawing) != 0u)
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    const float left = SferaNumeric::real32(bounds.left), top = SferaNumeric::real32(bounds.top);
    const auto white = SferaColor::rgba(255u, 255u, 255u, alpha).argb();
    const auto background_color = SferaColor::fromArgb(fill_color).withAlpha(fill_alpha * alpha / 256u).argb();
    if (auto background = show_full_background && full_sprite != nullptr ? full_sprite : empty_sprite)
        background->drawNatural(left + image_offset_x, top + image_offset_y, background_color);
    if (has_item)
    {
        const auto image_width = std::min(std::max(0, width), item_image.width), image_height = std::min(std::max(0, height), item_image.height);
        const auto image_left = left + (width - image_width) / 2, image_top = top + (height - image_height) / 2;
        item_image.draw(image_left, image_top, image_left + image_width, image_top + image_height, white);
    }
    if (top_left_overlay != nullptr)
        top_left_overlay->drawNatural(left + 1.0f, top, white);
    if (auto sprite = bottom_right_overlay)
        sprite->drawNatural(left + width - sprite->width - 1.0f, top + height - sprite->height - 1.0f, white);
    if (auto sprite = bottom_left_overlay)
    {
        const auto dx = image_offset_x == -2 ? 1.0f : 3.0f, dy = image_offset_x == -2 ? 0.0f : image_offset_x == -1 ? 1.0f : 2.0f;
        sprite->drawNatural(left + dx, top + height - sprite->height - dy - 1.0f, white);
    }
    if (text.size() != 0u && (has_item || (behavior_flags & SphereUIWindowStyle::showTitle) != 0u))
    {
        const auto extent = SphereUIInterfaceRenderer::measureText(getText(), font, font_initialized);
        auto dx = count_offset_x, dy = count_offset_y;
        if (extent.width < width)
        {
            if ((text_alignment & TextAlignment::right) != 0u)
                dx += width - extent.width;
            if ((text_alignment & TextAlignment::horizontalCenter) != 0u)
                dx = count_offset_x + (width - extent.width) / 2;
        }
        if (extent.height < height)
        {
            if ((text_alignment & TextAlignment::bottom) != 0u)
                dy += height - extent.height;
            if ((text_alignment & TextAlignment::verticalCenter) != 0u)
                dy = count_offset_y + (height - extent.height) / 2;
        }
        for (const auto offset : {SphereUITextExtent{1, 1}, SphereUITextExtent{-1, -1}, SphereUITextExtent{-1, 1}, SphereUITextExtent{1, -1}})
            SphereUIWidgetSupport::renderLabel(*this, getText(), bounds.left + dx + offset.width, bounds.top + dy + offset.height, SferaColor::rgba(0u, 0u, 0u, alpha).argb(), bounds);
        SphereUIWidgetSupport::renderLabel(*this, getText(), bounds.left + dx, bounds.top + dy, SferaColor::fromArgb((disabled ? disabled_color : text_color)).withAlpha(alpha).argb(), bounds);
    }
    if (border_sprite != nullptr)
        border_sprite->drawNatural(left + image_offset_x, top + image_offset_y, SferaColor::fromArgb(border_color).withAlpha(alpha).argb());
}

void SphereUISlotCtrl::handleInput(const SphereUIWindowInput &input)
{
    if (hidden)
        return;
    const bool shift = SphereUIRuntime::keyDown(42u) || SphereUIRuntime::keyDown(54u);
    if (containsPoint(input.mouse_x, input.mouse_y))
    {
        if ((input.mouse_flags & SphereUIMouseInput::leftPress) != 0u && !left_pressed && !drag_started && !shift)
        {
            left_pressed = true;
            press_x = input.mouse_x;
            press_y = input.mouse_y;
        }
        if ((input.mouse_flags & SphereUIMouseInput::rightPress) != 0u)
            right_pressed = true;
        if (!SphereUIHost::dragDropActive())
        {
            if ((input.mouse_flags & SphereUIMouseInput::leftRelease) != 0u && !shift && left_pressed)
                SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::leftClick);
            if ((input.mouse_flags & SphereUIMouseInput::rightRelease) != 0u && !shift && right_pressed)
                SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::rightClick);
            if (auto *window = SphereUICDescriptionWindow::instance())
                window->requestDescription(description.data(), shift && (input.mouse_flags & SphereUIMouseInput::leftPress) != 0u, this);
        }
    }
    if ((input.mouse_flags & SphereUIMouseInput::rightRelease) != 0u)
        right_pressed = false;
    if ((input.mouse_buttons & 1u) == 0u)
        left_pressed = drag_started = false;
    if (left_pressed && !drag_started && (std::abs(press_x - input.mouse_x) > 2 || std::abs(press_y - input.mouse_y) > 2))
    {
        SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::slotDrag);
        left_pressed = false;
        drag_started = true;
    }
}

void SphereUISlotCtrl::cloneProperties(SphereUISlotCtrl &destination, const SphereUISlotCtrl &source, SphereUIWindowCloneContext &)
{
    SphereUIWidgetSupport::copyProperties(destination, source, &SphereUISlotCtrl::item_image, &SphereUISlotCtrl::description, &SphereUISlotCtrl::top_left_overlay,
                                          &SphereUISlotCtrl::bottom_right_overlay, &SphereUISlotCtrl::bottom_left_overlay, &SphereUISlotCtrl::full_sprite, &SphereUISlotCtrl::empty_sprite,
                                          &SphereUISlotCtrl::border_sprite, &SphereUISlotCtrl::fill_alpha, &SphereUISlotCtrl::fill_color, &SphereUISlotCtrl::border_color,
                                          &SphereUISlotCtrl::image_offset_x, &SphereUISlotCtrl::image_offset_y, &SphereUISlotCtrl::show_full_background, &SphereUISlotCtrl::has_item,
                                          &SphereUISlotCtrl::press_x, &SphereUISlotCtrl::press_y, &SphereUISlotCtrl::left_pressed, &SphereUISlotCtrl::right_pressed, &SphereUISlotCtrl::drag_started,
                                          &SphereUISlotCtrl::count_offset_x, &SphereUISlotCtrl::count_offset_y, &SphereUISlotCtrl::item_count);
}

SphereUITextExtent SphereUICMenuListControl::spriteDimensions(const std::shared_ptr<const SphereUIUiSprite> &sprite)
{
    return SphereUITextExtent{sprite->width, sprite->height};
}

void SphereUICMenuListControl::menuLabel(const SphereUIWindow &window, std::string_view text, const SphereUIUiRect &margins, const SphereUITextExtent &size, std::uint32_t format, std::uint32_t color,
                                         int left, int top, const SphereUIUiRect &clip)
{
    const auto extent = SphereUIInterfaceRenderer::measureText(text, window.font, true);
    const auto room_x = size.width - margins.left - margins.right - extent.width, room_y = size.height - margins.top - margins.bottom - extent.height;
    const auto dx = (format & 4u) != 0u ? room_x / 2 : (format & 1u) != 0u ? room_x : 0;
    const auto dy = (format & 8u) != 0u ? room_y / 2 : (format & 2u) != 0u ? room_y : 0;
    SphereUIWidgetSupport::renderLabel(window, text, left + margins.left + dx, top + margins.top + dy, SferaColor::fromArgb(color).withAlpha(window.alpha).argb(), clip);
}

SphereUICMenuListControl::SphereUICMenuListControl()
{
    maximum_items = hovered_index = 1u;
    control_kind = SphereUIUiControlKind::menu;
}

std::unique_ptr<SphereUIWindow> SphereUICMenuListControl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUICMenuListControl::copyCloneState);
}

void SphereUICMenuListControl::updateParentPosition()
{
    parent_screen_x = parent_screen_y = parent_width = parent_height = 0;
    if (const auto *owner = parent)
    {
        owner->getAbsolutePosition(parent_screen_x, parent_screen_y);
        parent_width = owner->width;
        parent_height = owner->height;
    }
}

void SphereUICMenuListControl::keepOnScreen()
{
    updateParentPosition();
    auto *owner = parent;
    if (owner == nullptr)
        return;
    const auto screen = SphereUIRuntime::screenSize();
    const auto next_x = std::max(0, parent_screen_x + parent_width >= screen.width ? parent_screen_x - parent_width : parent_screen_x);
    const auto next_y = std::max(0, parent_screen_y + parent_height >= screen.height ? parent_screen_y - parent_height : parent_screen_y);
    if (next_x != parent_screen_x || next_y != parent_screen_y)
    {
        owner->handleMessage(SphereUIUiMessage::setPosition, SphereUIDetail::wireWord(next_x), SphereUIDetail::wireWord(next_y));
        updateParentPosition();
    }
}

void SphereUICMenuListControl::addItem(std::string_view item_text, bool enabled)
{
    if (items.size() >= maximum_items)
        return;
    items.push_back({std::string(item_text), enabled});
    height += item_size.height;
    updateParentPosition();
    if (auto *owner = parent)
        owner->handleMessage(SphereUIUiMessage::setSize, SphereUIDetail::wireWord(parent_width), SphereUIDetail::wireWord(parent_height + item_size.height));
}

void SphereUICMenuListControl::clearItems()
{
    updateParentPosition();
    const auto removed_height = items.size() * item_size.height;
    height = top_size.height + bottom_size.height;
    items.clear();
    hovered_index = maximum_items;
    if (auto *owner = parent)
        owner->handleMessage(SphereUIUiMessage::setSize, SphereUIDetail::wireWord(parent_width), SferaNumeric::lowWord(parent_height - removed_height));
}

void SphereUICMenuListControl::closeMenu()
{
    SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::close);
}

std::size_t SphereUICMenuListControl::itemAtPoint(std::int64_t point_x, std::int64_t point_y) const
{
    if (item_size.height <= 0)
        return maximum_items;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    const auto row_y = point_y - bounds.top - top_size.height;
    if (point_x < bounds.left || point_x >= bounds.right || row_y < 0)
        return maximum_items;
    const std::uint64_t index = row_y / item_size.height;
    return index < items.size() ? index : maximum_items;
}

std::uint32_t SphereUICMenuListControl::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::clearMenu:
        clearItems();
        break;
    case SphereUIUiMessage::activateMenuItem:
        if (first < items.size() && items.at(first).enabled != 0u)
            SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::menuItemActivated, first, items.size());
        break;
    case SphereUIUiMessage::setMenuItemEnabled:
        if (first < items.size())
            items.at(first).enabled = second != 0u;
        break;
    default:
        return SphereUIWindow::handleMessage(message, first, second);
    }
    return 1u;
}

void SphereUICMenuListControl::drawHeader()
{
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    if (top_sprite != nullptr)
        top_sprite->drawNatural(SferaNumeric::real32(bounds.left), SferaNumeric::real32(bounds.top), SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    if (show_title)
    {
        const SphereUIUiRect clip{bounds.left + title_margin.left, bounds.top + title_margin.top, bounds.right - title_margin.right, bounds.bottom - title_margin.bottom};
        SphereUICMenuListControl::menuLabel(*this, getText(), title_margin, top_size, title_format, title_color, bounds.left, bounds.top, clip);
    }
}

void SphereUICMenuListControl::drawItem(std::size_t index, const std::shared_ptr<const SphereUIUiSprite> &sprite, std::uint32_t color)
{
    if (index >= items.size())
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    const auto row_top = SphereUIDetail::addCoordinate(bounds.top + top_size.height, index * item_size.height);
    if (sprite != nullptr)
        sprite->drawNatural(SferaNumeric::real32(bounds.left), SferaNumeric::real32(row_top), SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    const auto &item = items.at(index);
    const SphereUIUiRect clip{bounds.left + item_margin.left, row_top + title_margin.top, bounds.right - item_margin.right, row_top + item_size.height - title_margin.bottom};
    SphereUICMenuListControl::menuLabel(*this, item.text.data(), item_margin, item_size, item_format, item.enabled ? color : item_disabled_color, bounds.left, row_top, clip);
}

void SphereUICMenuListControl::drawFooter()
{
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    if (bottom_sprite != nullptr)
        bottom_sprite->drawNatural(SferaNumeric::real32(bounds.left), SferaNumeric::real32(bounds.top + top_size.height + std::ssize(items) * item_size.height),
                                   SferaColor::rgba(255u, 255u, 255u, alpha).argb());
}

void SphereUICMenuListControl::draw()
{
    if (hidden || (behavior_flags & SphereUIWindowStyle::skipDrawing) != 0u)
        return;
    keepOnScreen();
    SphereUIViewportScope viewport(SphereUIWidgetSupport::windowBounds(*this));
    if (!viewport)
        return;
    drawHeader();
    for (std::size_t index = 0u; index < items.size(); ++index)
        drawItem(index, index == hovered_index ? hovered_sprite : middle_sprite, index == hovered_index ? hovered_color : normal_color);
    drawFooter();
}

void SphereUICMenuListControl::handleInput(const SphereUIWindowInput &input)
{
    if (hidden || items.size() == 0u)
        return;
    const auto position = CCursorManager::instance().position();
    hovered_index = itemAtPoint(position.x, position.y);
    if (hovered_index < items.size() && items.at(hovered_index).enabled != 0u && (input.mouse_flags & SphereUIMouseInput::leftPress) != 0u)
    {
        SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::menuItemActivated, hovered_index, items.size());
        closeMenu();
    }
    if (const auto *owner = parent; owner != nullptr && !owner->containsPoint(position.x, position.y) && (input.mouse_flags & 3u) != 0u)
        closeMenu();
}

void SphereUICMenuListControl::copyCloneState(SphereUICMenuListControl &destination, const SphereUICMenuListControl &source, SphereUIWindowCloneContext &)
{
    SphereUIWidgetSupport::copyProperties(destination, source, &SphereUICMenuListControl::items, &SphereUICMenuListControl::maximum_items, &SphereUICMenuListControl::top_sprite,
                                          &SphereUICMenuListControl::middle_sprite, &SphereUICMenuListControl::hovered_sprite, &SphereUICMenuListControl::bottom_sprite,
                                          &SphereUICMenuListControl::title_color, &SphereUICMenuListControl::normal_color, &SphereUICMenuListControl::hovered_color,
                                          &SphereUICMenuListControl::item_disabled_color, &SphereUICMenuListControl::show_title, &SphereUICMenuListControl::title_margin,
                                          &SphereUICMenuListControl::title_format, &SphereUICMenuListControl::item_margin, &SphereUICMenuListControl::item_format, &SphereUICMenuListControl::top_size,
                                          &SphereUICMenuListControl::item_size, &SphereUICMenuListControl::bottom_size, &SphereUICMenuListControl::parent_screen_x,
                                          &SphereUICMenuListControl::parent_screen_y, &SphereUICMenuListControl::parent_width, &SphereUICMenuListControl::parent_height,
                                          &SphereUICMenuListControl::hovered_index);
}

std::uint32_t SphereUIListCtrl::modulatedColor(std::uint32_t color, std::uint32_t alpha)
{
    return SferaColor::fromArgb(color).scaledAlpha(alpha).argb();
}

std::unique_ptr<SphereUIWindow> SphereUIListCtrl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIListCtrl::copyCloneState);
}

std::uint32_t SphereUIListCtrl::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::verticalScroll:
    case SphereUIUiMessage::setListScroll:
        vertical_offset = first;
        updateVisibleRange();
        return 1u;
    case SphereUIUiMessage::updateScrollLayout:
        if (first != 0u)
            updateLayout();
        else if (auto *bar = scrollbar.get())
            bar->setParameters({0u, ScrollField::all, 0, 0, 0, 0, 0});
        return 1u;
    case SphereUIUiMessage::setListColor:
        if (first >= rows.size())
            return 0u;
        rows.at(first).color = second;
        return 1u;
    case SphereUIUiMessage::setListFormatting:
        format_strings = first != 0u ? 1u : 0u;
        return 1u;
    case SphereUIUiMessage::alignListRow:
        if (first >= rows.size())
            return 0u;
        alignRow(first, second);
        return 1u;
    case SphereUIUiMessage::setListSelection:
        selectRow(SphereUIDetail::signedWord(first));
        return 1u;
    case SphereUIUiMessage::clearList:
        clearRows();
        return 1u;
    case SphereUIUiMessage::removeListRow:
        removeRow(first);
        return 1u;
    default:
        return SphereUIWindow::handleMessage(message, first, second);
    }
}

void SphereUIListCtrl::draw()
{
    if (hidden || (behavior_flags & SphereUIWindowStyle::skipDrawing) != 0u)
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    if (rows.size() != 0u)
    {
        SphereUIViewportScope viewport(bounds);
        if (viewport)
        {
            auto row_y = SphereUIDetail::subtractCoordinate(bounds.top, cropped_y);
            if (chatlike && std::ssize(rows) < std::max(visible_capacity, std::ptrdiff_t{}))
                row_y = SphereUIDetail::addCoordinate(row_y, SphereUIDetail::subtractCoordinate(height, SphereUIDetail::multiplyCoordinate(rows.size(), line_height)));
            const auto first_y = row_y;
            const auto end = std::min(visible_end, std::ssize(rows));
            const auto mark_width = continue_mark ? SphereUIInterfaceRenderer::measureText("  ...", font, font_initialized).width : 0;
            for (auto index = std::max(visible_begin, std::ptrdiff_t{}); index < end; ++index)
            {
                const auto &row = rows.at(physicalIndex(index));
                auto clip = bounds;
                const auto row_color = SferaColor::fromArgb(row.color).withAlpha(alpha).argb();
                const auto row_x = SphereUIDetail::addCoordinate(bounds.left, row.offset);
                const bool truncated = continue_mark && SphereUIInterfaceRenderer::measureText(row.text, font, font_initialized).width > width;
                if (truncated)
                    clip.right = SphereUIDetail::subtractCoordinate(clip.right, mark_width);
                SphereUIInterfaceRenderer::drawText(row.text, row_x, row_y, row_color, font, true, clip, alpha == 255u);
                if (truncated)
                    SphereUIInterfaceRenderer::drawText("  ...",
                                                        SphereUIDetail::addCoordinate(bounds.left, SphereUIDetail::addCoordinate(row.offset, SphereUIDetail::subtractCoordinate(width, mark_width))),
                                                        row_y, row_color, font, true, bounds, alpha == 255u);
                row_y = SphereUIDetail::addCoordinate(row_y, line_height);
            }
            if (selected_index >= visible_begin && selected_index < end)
                drawSelection(bounds.left, bounds.top, SphereUIDetail::addCoordinate(first_y, SphereUIDetail::multiplyCoordinate(selected_index - visible_begin, line_height)), false);
        }
    }
    SphereUIWidgetSupport::drawChild(scrollbar.get(), alpha);
}

void SphereUIListCtrl::handleInput(const SphereUIWindowInput &input)
{
    if (hidden)
        return;
    SphereUIWidgetSupport::inputChild(scrollbar.get(), input);
    if (!can_select)
    {
        selected_index = -1;
        return;
    }
    if (rows.size() == 0u || (input.mouse_flags & SphereUIMouseInput::leftPress) == 0u || !SphereUIWidgetSupport::contains(SphereUIWidgetSupport::windowBounds(*this), input.mouse_x, input.mouse_y))
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    auto first_y = SphereUIDetail::subtractCoordinate(bounds.top, cropped_y);
    if (chatlike && std::ssize(rows) < std::max(visible_capacity, std::ptrdiff_t{}))
        first_y = SphereUIDetail::addCoordinate(first_y, SphereUIDetail::subtractCoordinate(height, SphereUIDetail::multiplyCoordinate(rows.size(), line_height)));
    const auto offset = SphereUIDetail::subtractCoordinate(input.mouse_y, first_y);
    const auto relative = line_height > 0 && offset >= 0 ? SferaNumeric::word(offset / line_height) : invalidIndex;
    const auto index = visible_begin + relative;
    const std::ptrdiff_t selected = index < std::ssize(rows) ? index : -1;
    if (selected != selected_index)
    {
        selected_index = selected;
        SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::listSelectionChanged, SphereUIDetail::wireWord(selected));
    }
    const auto now = SphereUIRuntime::clockTicks();
    if (!click_pending)
    {
        click_pending = true;
        click_time = now;
    }
    else
    {
        const double elapsed = SphereUIDetail::real64(SferaNumeric::signedWord(now - click_time));
        const auto seconds = elapsed / 10000.0;
        if (seconds < 0.6 && selected_index >= 0)
            SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::listDoubleClick, SphereUIDetail::wireWord(selected_index));
        click_pending = false;
    }
}

SphereUIListCtrl::SphereUIListCtrl()
{
    line_height = 1;
    selected_index = -1;
    selection_border = 3;
    selection_color = UiColor::listSelection;
    hidden = false;
    control_kind = SphereUIUiControlKind::textList;
}

void SphereUIListCtrl::copyListState(const SphereUIListCtrl &source, SphereUIWindowCloneContext &context)
{
    if (this == &source)
        return;
    SphereUIWidgetSupport::copyProperties(*this, source, &SphereUIListCtrl::visible_begin, &SphereUIListCtrl::visible_end, &SphereUIListCtrl::rows, &SphereUIListCtrl::maximum_items,
                                          &SphereUIListCtrl::write_index, &SphereUIListCtrl::maximum_scroll, &SphereUIListCtrl::line_height, &SphereUIListCtrl::visible_capacity,
                                          &SphereUIListCtrl::vertical_offset, &SphereUIListCtrl::cropped_y, &SphereUIListCtrl::chatlike, &SphereUIListCtrl::format_strings,
                                          &SphereUIListCtrl::continue_mark, &SphereUIListCtrl::can_select, &SphereUIListCtrl::selected_index, &SphereUIListCtrl::selection_border,
                                          &SphereUIListCtrl::selection_color, &SphereUIListCtrl::selection_line_color, &SphereUIListCtrl::click_time, &SphereUIListCtrl::click_pending);
    SphereUIWidgetSupport::cloneOwned(scrollbar, source.scrollbar, *this, context);
}

std::size_t SphereUIListCtrl::physicalIndex(std::size_t logical_index) const
{
    const auto count = rows.size();
    if (logical_index >= count)
        throw std::out_of_range("UI logical row index");
    if (maximum_items == 0u)
        return logical_index;
    return write_index >= count - logical_index ? write_index - (count - logical_index) : write_index + logical_index;
}

void SphereUIListCtrl::updateVisibleRange()
{
    vertical_offset = std::clamp(vertical_offset, 0, std::max(maximum_scroll, 0));
    const auto fraction = line_height > 0 ? 1.0f * vertical_offset / line_height : 0.0f;
    const auto integral = std::floor(fraction);
    cropped_y = line_height > 0 ? SferaNumeric::truncateInt((fraction - integral) * line_height) : 0;
    visible_begin = SferaNumeric::truncateInt(integral);
    visible_end = std::min(visible_begin + visible_capacity + std::ptrdiff_t{1}, std::ssize(rows));
}

void SphereUIListCtrl::updateLayout()
{
    visible_capacity = line_height > 0 ? height / line_height + 1 : 0;
    const int extent = SphereUIDetail::multiplyCoordinate(rows.size(), line_height);
    maximum_scroll = height > extent ? 0 : std::max(0, SphereUIDetail::addCoordinate(SphereUIDetail::subtractCoordinate(extent, height), 1));
    if (auto *bar = scrollbar.get())
        bar->setParameters({0u, ScrollField::all, 0, maximum_scroll, height, vertical_offset, line_height});
    updateVisibleRange();
}

void SphereUIListCtrl::appendLine(std::string_view line_text, std::uint32_t color)
{
    if (parent != nullptr && selected_index != -1)
    {
        selected_index = -1;
        SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::listSelectionChanged, invalidIndex);
    }
    int offset = 0;
    if (text_alignment != 0u)
    {
        const auto extent = SphereUIInterfaceRenderer::measureText(line_text, font, font_initialized);
        const auto remainder = SphereUIDetail::subtractCoordinate(width, extent.width);
        if ((text_alignment & TextAlignment::right) != 0u)
            offset = remainder;
        if ((text_alignment & TextAlignment::horizontalCenter) != 0u)
            offset = SphereUIDetail::checkedInt(std::abs(1LL * remainder) / 2, "text offset exceeds int");
    }
    SphereUIWidgetSupport::appendCircular(rows, maximum_items, write_index, SphereUIUiTextRow{std::string(line_text), color, offset});
    updateLayout();
}

void SphereUIListCtrl::appendFormattedLine(std::string_view line_text, std::uint32_t color)
{
    SphereUIListCtrl::wrapTextLine(*this, line_text, format_strings, std::bind_front(&SphereUIListCtrl::appendWrappedLine, this, color));
}

void SphereUIListCtrl::addText(std::string_view line_text, std::uint32_t color)
{
    std::size_t begin = 0u;
    for (;;)
    {
        const auto end = line_text.find('\n', begin);
        appendFormattedLine(line_text.substr(begin, end == std::string_view::npos ? end : end - begin), color);
        if (end == std::string_view::npos)
            break;
        begin = end + 1u;
    }
}

void SphereUIListCtrl::appendMessageText(std::string_view line_text, std::uint32_t color)
{
    const bool at_bottom = SphereUIDetail::addCoordinate(vertical_offset, 5) >= maximum_scroll;
    addText(line_text, color);
    if (chatlike && at_bottom)
    {
        vertical_offset = maximum_scroll;
        if (auto *bar = scrollbar.get())
            bar->setParameters({0u, ScrollField::position, 0, 0, 0, vertical_offset, 0});
        updateVisibleRange();
    }
}

bool SphereUIListCtrl::setRowText(std::size_t index, std::string_view value)
{
    if (index >= rows.size())
        return false;
    rows.at(index).text.assign(value);
    return true;
}

std::string_view SphereUIListCtrl::rowText(std::size_t index) const
{
    if (index >= rows.size())
        return {};
    return rows.at(physicalIndex(index)).text;
}

void SphereUIListCtrl::clearRows()
{
    rows.clear();
    selected_index = -1;
    write_index = 0u;
    updateLayout();
}

void SphereUIListCtrl::removeRow(std::size_t logical_index)
{
    if (logical_index >= rows.size())
        return;
    rows.erase(rows.begin() + physicalIndex(logical_index));
    if (maximum_items != 0u)
        write_index = write_index == 0u ? 0u : write_index - 1u;
    if (parent != nullptr && selected_index != -1)
    {
        selected_index = -1;
        SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::listSelectionChanged, invalidIndex);
    }
    updateLayout();
}

void SphereUIListCtrl::alignRow(std::size_t index, std::uint32_t flags)
{
    if (index >= rows.size())
        return;
    auto &row = rows.at(index);
    if (flags == 0u)
        row.offset = 0;
    else
    {
        const auto extent = SphereUIInterfaceRenderer::measureText(row.text, font, font_initialized);
        const auto remainder = SphereUIDetail::subtractCoordinate(width, extent.width);
        if ((flags & 4u) != 0u)
            row.offset = remainder / 2u;
        if ((flags & 1u) != 0u)
            row.offset = remainder;
    }
}

void SphereUIListCtrl::drawSelection(int screen_x, int screen_y, int row_y, bool restore_viewport)
{
    const SphereUIUiRect bounds{SphereUIDetail::subtractCoordinate(screen_x, selection_border), screen_y,
                                SphereUIDetail::addCoordinate(SphereUIDetail::addCoordinate(screen_x, width), selection_border), SphereUIDetail::addCoordinate(screen_y, height)};
    SphereUIViewportScope viewport(bounds, restore_viewport);
    if (!viewport)
        return;
    const auto screen = SphereUIRuntime::screenSize();
    const float left = SferaNumeric::real32(std::max(bounds.left, 0));
    const float right = SferaNumeric::real32(std::min(bounds.right, screen.width));
    const float top = SferaNumeric::real32(row_y);
    const float bottom = SferaNumeric::real32(SphereUIDetail::addCoordinate(row_y, line_height));
    const auto fill = SphereUIListCtrl::modulatedColor(selection_color, alpha), line = SphereUIListCtrl::modulatedColor(selection_line_color, alpha);
    SphereUIInterfaceRenderer::drawTexture(nullptr, left, top, right, bottom, fill, 0.0f, 0.0f, false);
    SphereUIInterfaceRenderer::drawTexture(nullptr, left, top, right, top + 1.0f, line, 0.0f, 0.0f, false);
    SphereUIInterfaceRenderer::drawTexture(nullptr, left, bottom, right, bottom + 1.0f, line, 0.0f, 0.0f, false);
    SphereUIInterfaceRenderer::drawTexture(nullptr, left, top, left + 1.0f, bottom, line, 0.0f, 0.0f, false);
    SphereUIInterfaceRenderer::drawTexture(nullptr, right - 1.0f, top, right, bottom, line, 0.0f, 0.0f, false);
}
