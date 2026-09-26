#include <windows.h>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <format>
#include <memory>
#include <string_view>

#include "input/MouseInput.h"
#include "math/Color.h"
#include "numeric/Numeric.h"
#include "text/Fonts.h"
#include "text/Text.h"
#include "ui/Rendering.h"
#include "ui/Sprite.h"
#include "ui/UiHost.h"
#include "ui/UiRuntime.h"
#include "ui/UiTypes.h"
#include "ui/WidgetSupport.h"
#include "ui/Window.h"
#include "ui/widgets/Controls.h"

std::uint32_t SphereUIButtonCtrl::keyCode(std::string_view name)
{
    if (name.empty())
        return 0u;
    for (std::uint32_t code = 0u; code <= 255u; ++code)
        if (const auto candidate = SphereUIRuntime::keyName(code); !candidate.empty() && SferaText::asciiEqual(name, candidate))
            return code;
    return 0u;
}

std::unique_ptr<SphereUIWindow> SphereUIButtonCtrl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIButtonCtrl::copyCloneState);
}

std::uint32_t SphereUIButtonCtrl::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    if (message == SphereUIUiMessage::activateButton)
    {
        click();
        return 1u;
    }
    return SphereUIWindow::handleMessage(message, first, second);
}

void SphereUIButtonCtrl::draw()
{
    if (hidden || (behavior_flags & SphereUIWindowStyle::skipDrawing) != 0u)
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    if ((button_flags & ButtonStyle::stateImages) != 0u)
    {
        const std::shared_ptr<const SphereUIUiSprite> images[] = {idle_image, pressed_image, hover_image};
        const auto image = disabled ? disabled_image : images[std::min(visual_state, 2u)];
        if (image != nullptr)
            image->draw(SferaNumeric::real32(bounds.left), SferaNumeric::real32(bounds.top), SferaNumeric::real32(bounds.right), SferaNumeric::real32(bounds.bottom),
                        SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    }
    if (text.size() != 0u)
        SphereUIWidgetSupport::alignedLabel(*this, disabled ? disabled_color : visual_state == 0u ? text_color : hover_color);
}

void SphereUIButtonCtrl::handleInput(const SphereUIWindowInput &input)
{
    if (hidden || disabled)
        return;
    const auto key = LOWORD(hotkey);
    const auto modifiers = HIWORD(hotkey);
    if (input.key_code != 0u && input.key_code == key && (modifiers == 0u || (input.key_modifiers & modifiers) != 0u))
        click();
    if (containsPoint(input.mouse_x, input.mouse_y))
    {
        if (visual_state == 0u)
            visual_state = 2u;
        if ((input.mouse_flags & SphereUIMouseInput::leftPress) != 0u)
        {
            visual_state = 1u;
            pressed = true;
        }
        bool repeat = false;
        if ((button_flags & ButtonStyle::repeatWhilePressed) != 0u && pressed && (input.mouse_buttons & 1u) != 0u)
        {
            const float elapsed = SferaNumeric::real32(SphereUIRuntime::elapsedSeconds(repeat_started_at));
            if (repeat_interval < elapsed)
            {
                visual_state = 1u;
                repeat = true;
                repeat_started_at = SphereUIRuntime::clockTicks();
            }
        }
        if ((input.mouse_flags & SphereUIMouseInput::leftRelease) != 0u && visual_state == 1u)
        {
            visual_state = 2u;
            pressed = false;
            if ((button_flags & ButtonStyle::repeatWhilePressed) == 0u)
            {
                SphereUIRuntime::playClickSound();
                click();
                return;
            }
        }
        if (repeat)
            click();
    }
    else
    {
        if (visual_state != 0u && ((button_flags & ButtonStyle::releaseOutside) != 0u || visual_state == 2u || (input.mouse_buttons & 1u) == 0u))
            visual_state = 0u;
        if (pressed && (input.mouse_buttons & 1u) == 0u)
            pressed = false;
    }
}

void SphereUIButtonCtrl::click()
{
    if (auto *owner = parent)
    {
        SphereUIWindowEvent event{this, control_id, SphereUIUiMessage::leftClick, 0u, 0u};
        owner->queueEvent(event);
        if ((button_flags & ButtonStyle::sendClose) != 0u)
        {
            event.message = SphereUIUiMessage::close;
            owner->queueEvent(event);
        }
    }
    if ((button_flags & ButtonStyle::showHelp) != 0u)
        SphereUIHost::showHelpPage(getHelp());
}

SphereUIButtonCtrl::SphereUIButtonCtrl()
{
    repeat_interval = 0.05f;
    hover_color = UiColor::white;
    hidden = false;
    control_kind = SphereUIUiControlKind::button;
    text_alignment = TextAlignment::center;
}

void SphereUIButtonCtrl::copyCloneState(SphereUIButtonCtrl &target, const SphereUIButtonCtrl &source, SphereUIWindowCloneContext &)
{
    SphereUIWidgetSupport::copyProperties(target, source, &SphereUIButtonCtrl::visual_state, &SphereUIButtonCtrl::idle_image, &SphereUIButtonCtrl::pressed_image, &SphereUIButtonCtrl::hover_image,
                                          &SphereUIButtonCtrl::button_flags, &SphereUIButtonCtrl::hotkey, &SphereUIButtonCtrl::repeat_started_at, &SphereUIButtonCtrl::pressed,
                                          &SphereUIButtonCtrl::repeat_interval, &SphereUIButtonCtrl::hover_color, &SphereUIButtonCtrl::disabled_image);
}

void SphereUICheckBox::copyCheckState(const SphereUICheckBox &source)
{
    if (this == &source)
        return;
    SphereUIWidgetSupport::copyProperties(*this, source, &SphereUICheckBox::unchecked_image, &SphereUICheckBox::checked_image, &SphereUICheckBox::unchecked_hover_image,
                                          &SphereUICheckBox::checked_hover_image, &SphereUICheckBox::checked, &SphereUICheckBox::hovered, &SphereUICheckBox::image_x, &SphereUICheckBox::image_y,
                                          &SphereUICheckBox::button_flags, &SphereUICheckBox::label_x, &SphereUICheckBox::label_y, &SphereUICheckBox::hover_color);
}

std::unique_ptr<SphereUIWindow> SphereUICheckBox::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUICheckBox::copyCloneState);
}

std::uint32_t SphereUICheckBox::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::setChecked:
        checked = first != 0u;
        return 1u;
    case SphereUIUiMessage::activateButton:
        playClickSound();
        return 1u;
    case SphereUIUiMessage::setEnabled:
        if (first == 0u)
            checked = false;
        break;
    default:
        break;
    }
    return SphereUIWindow::handleMessage(message, first, second);
}

void SphereUICheckBox::draw()
{
    if (hidden || (behavior_flags & SphereUIWindowStyle::skipDrawing) != 0u)
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    auto image = checked ? checked_image : unchecked_image;
    if (hovered)
    {
        const auto hover = checked ? checked_hover_image : unchecked_hover_image;
        if (hover != 0u)
            image = hover;
    }
    if (image != nullptr)
        image->drawNatural(SferaNumeric::real32(SphereUIDetail::addCoordinate(bounds.left, image_x)), SferaNumeric::real32(SphereUIDetail::addCoordinate(bounds.top, image_y)),
                           SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    int dx = label_x;
    int dy = label_y;
    if ((button_flags & ButtonStyle::centerText) != 0u)
    {
        const auto extent = SphereUIInterfaceRenderer::measureText(getText(), font, font_initialized);
        if (extent.width < width)
            dx = (width - extent.width) / 2;
        if (extent.height < height)
            dy = (height - extent.height) / 2;
    }
    SphereUIWidgetSupport::renderLabel(*this, getText(), SphereUIDetail::addCoordinate(bounds.left, dx), SphereUIDetail::addCoordinate(bounds.top, dy),
                                       disabled  ? disabled_color
                                       : hovered ? hover_color
                                                 : text_color,
                                       bounds);
}

void SphereUICheckBox::handleInput(const SphereUIWindowInput &input)
{
    hovered = containsPoint(input.mouse_x, input.mouse_y) ? 1u : 0u;
    if (hovered && (input.mouse_flags & SphereUIMouseInput::leftPress) != 0u)
        playClickSound();
}

void SphereUICheckBox::playClickSound()
{
    checked = !checked;
    if (auto *owner = parent)
        owner->queueEvent({this, control_id, SphereUIUiMessage::leftClick, 0u, 0u});
    SphereUIRuntime::playClickSound();
}

std::unique_ptr<SphereUIWindow> SphereUIRadioButtonCtrl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIRadioButtonCtrl::copyCloneState);
}

void SphereUIRadioButtonCtrl::playClickSound()
{
    if (!checked)
        if (auto *owner = parent)
            owner->dispatchMessage(group, SphereUIUiMessage::setChecked, 0u, 0u, SphereUIUiControlKind::radioButton);
    checked = false;
    SphereUICheckBox::playClickSound();
}

SphereUICheckBox::SphereUICheckBox()
{
    hover_color = UiColor::white;
    hidden = false;
    control_kind = SphereUIUiControlKind::checkBox;
}

SphereUIRadioButtonCtrl::SphereUIRadioButtonCtrl()
{
    control_kind = SphereUIUiControlKind::radioButton;
}

std::unique_ptr<SphereUIWindow> SphereUIImageCtrl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIImageCtrl::copyCloneState);
}

std::uint32_t SphereUIImageCtrl::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::setImageAlpha:
        base_alpha = std::min<std::uint32_t>(first, 255u);
        setOpacity(opacity);
        return 1u;
    default:
        return SphereUIWindow::handleMessage(message, first, second);
    }
}

void SphereUIImageCtrl::draw()
{
    if (hidden || resource_reference == nullptr)
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    resource_reference->draw(SferaNumeric::real32(bounds.left), SferaNumeric::real32(bounds.top), SferaNumeric::real32(bounds.right), SferaNumeric::real32(bounds.bottom),
                             SferaColor::rgba(255u, 255u, 255u, alpha).argb(), rotated ? rotation_radians : 0.0f);
}

void SphereUIImageCtrl::handleInput(const SphereUIWindowInput &input)
{
    if (image_style == 0u)
        return;
    const bool inside = containsPoint(input.mouse_x, input.mouse_y);
    if ((image_style & 2u) != 0u && inside != (interaction_active))
    {
        SphereUIWidgetSupport::notifyParent(*this, inside ? SphereUIUiMessage::pointerEnter : SphereUIUiMessage::pointerLeave);
        interaction_active = inside;
    }
    if (inside && (image_style & 1u) != 0u && (input.mouse_flags & SphereUIMouseInput::leftPress) != 0u)
    {
        int left = 0;
        int top = 0;
        getAbsolutePosition(left, top);
        SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::leftClick, input.mouse_x - left, input.mouse_y - top);
        SphereUIRuntime::playClickSound();
    }
}

void SphereUIImageCtrl::setOpacity(float new_opacity)
{
    const std::uint32_t new_alpha = SphereUIWidgetSupport::opacity_alpha(base_alpha * new_opacity);
    alpha = new_alpha;
    SphereUIWidgetSupport::replace_color_alpha(text_color, new_alpha);
    SphereUIWidgetSupport::replace_color_alpha(disabled_color, new_alpha);
    opacity = new_opacity;
}

SphereUIImageCtrl::SphereUIImageCtrl()
{
    base_alpha = 255u;
    opacity = 1.0f;
    hidden = false;
    control_kind = SphereUIUiControlKind::image;
}

void SphereUIImageCtrl::copyCloneState(SphereUIImageCtrl &target, const SphereUIImageCtrl &source, SphereUIWindowCloneContext &)
{
    SphereUIWidgetSupport::copyProperties(target, source, &SphereUIImageCtrl::image_style, &SphereUIImageCtrl::interaction_active, &SphereUIImageCtrl::fallback_image, &SphereUIImageCtrl::rotated,
                                          &SphereUIImageCtrl::rotation_radians, &SphereUIImageCtrl::base_alpha, &SphereUIImageCtrl::opacity);
}

void SphereUIProgressBar::initializeProgressState()
{
    minimum = 0;
    maximum = 100;
    current = 0;
    progress_ratio = 0.0f;
    display_mode = 0u;
    status_text.clear();
    status_x = 0;
    status_y = 0;
}

void SphereUIProgressBar::setProgressValue(int value)
{
    if (current == value)
        return;
    current = std::clamp(value, minimum, maximum);
    refreshProgressDisplay();
}

void SphereUIProgressBar::setProgressRange(int new_minimum, int new_maximum)
{
    minimum = new_minimum;
    maximum = new_maximum;
    current = minimum;
    if (minimum >= maximum)
        maximum = SphereUIDetail::addCoordinate(minimum, 1);
    refreshProgressDisplay();
}

void SphereUIProgressBar::refreshProgressDisplay()
{
    const int range = SphereUIDetail::subtractCoordinate(maximum, minimum);
    const float position = SferaNumeric::real32(current), extent = SferaNumeric::real32(range);
    progress_ratio = range == 0 ? 0.0f : std::min(std::fabs(position / extent), 1.0f);
    SphereUIWidgetSupport::updateStatusText(status_text, display_mode, progress_ratio * 100.0f, current, range);
}

std::unique_ptr<SphereUIWindow> SphereUIProgressBar::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIProgressBar::copyCloneState);
}

std::uint32_t SphereUIProgressBar::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    if (message < SphereUIUiMessage::setProgressValue || message > SphereUIUiMessage::getProgressValue)
        return SphereUIWindow::handleMessage(message, first, second);
    switch (message)
    {
    case SphereUIUiMessage::setProgressValue:
        setProgressValue(SphereUIDetail::signedWord(first));
        return 1u;
    case SphereUIUiMessage::setProgressRange:
        setProgressRange(SphereUIDetail::signedWord(first), SphereUIDetail::signedWord(second));
        return 1u;
    default:
        return 0u;
    }
}

void SphereUIProgressBar::draw()
{
    if (hidden || (behavior_flags & SphereUIWindowStyle::skipDrawing) != 0u)
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    if (progress_ratio > 0.0f && resource_reference != nullptr)
        resource_reference->draw(SferaNumeric::real32(bounds.left), SferaNumeric::real32(bounds.top), bounds.left + width * progress_ratio, SferaNumeric::real32(bounds.bottom),
                                 SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    if (display_mode != 0u)
    {
        const auto left = SphereUIDetail::addCoordinate(bounds.left, status_x);
        const auto top = SphereUIDetail::addCoordinate(bounds.top, status_y);
        SphereUIWidgetSupport::renderLabel(*this, status_text, left, top, text_color, {left, top, SphereUIDetail::addCoordinate(left, 100), SphereUIDetail::addCoordinate(top, 100)});
    }
}

SphereUIProgressBar::SphereUIProgressBar()
{
    initializeProgressState();
    hidden = false;
    control_kind = SphereUIUiControlKind::progressBar;
}

void SphereUIProgressBar::copyCloneState(SphereUIProgressBar &target, const SphereUIProgressBar &source, SphereUIWindowCloneContext &)
{
    SphereUIWidgetSupport::copyProperties(target, source, &SphereUIProgressBar::minimum, &SphereUIProgressBar::maximum, &SphereUIProgressBar::current, &SphereUIProgressBar::progress_ratio,
                                          &SphereUIProgressBar::display_mode, &SphereUIProgressBar::status_text, &SphereUIProgressBar::status_x, &SphereUIProgressBar::status_y);
}

bool SphereUIScrollBar::moveScroll(SphereUIScrollBar &control, bool increase, int amount)
{
    const auto limit = increase ? control.maximum : control.minimum;
    if (control.current == limit)
        return false;
    control.current = increase ? std::min(SphereUIDetail::addCoordinate(control.current, amount), limit) : std::max(SphereUIDetail::subtractCoordinate(control.current, amount), limit);
    control.updateControlState();
    return true;
}

void SphereUIScrollBar::enableNavigationButtons(SphereUIScrollBar &control)
{
    for (auto address : {control.decrease_button.get(), control.increase_button.get()})
        if (auto *button = address)
            button->handleMessage(SphereUIUiMessage::setEnabled, control.minimum != control.maximum ? 1u : 0u, 0u);
}

std::unique_ptr<SphereUIWindow> SphereUIScrollBar::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, SphereUIWidgetSupport::copyScrollFields);
}

std::uint32_t SphereUIScrollBar::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::setScrollValue:
        current = std::min(std::max(SphereUIDetail::signedWord(first), minimum), maximum);
        updateControlState();
        return 1u;
    case SphereUIUiMessage::setScrollRange:
        minimum = current = first;
        maximum = second;
        SphereUIScrollBar::enableNavigationButtons(*this);
        updateControlState();
        return 1u;
    case SphereUIUiMessage::increaseScroll:
    case SphereUIUiMessage::decreaseScroll:
        if (SphereUIScrollBar::moveScroll(*this, message == SphereUIUiMessage::increaseScroll, step))
            loadControlParameters();
        return 1u;
    default:
        return SphereUIWindow::handleMessage(message, first, second);
    }
}

void SphereUIScrollBar::draw()
{
    if (hidden || (behavior_flags & SphereUIWindowStyle::skipDrawing) != 0u)
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    const auto color = SferaColor::rgba(255u, 255u, 255u, alpha).argb();
    if (resource_reference != nullptr)
        resource_reference->draw(SferaNumeric::real32(bounds.left), SferaNumeric::real32(bounds.top), SferaNumeric::real32(bounds.right), SferaNumeric::real32(bounds.bottom), color);
    if (maximum > minimum)
    {
        const auto left = SphereUIDetail::addCoordinate(bounds.left, thumb_x);
        const auto top = SphereUIDetail::addCoordinate(bounds.top, thumb_y);
        if (scroll_resource != nullptr)
            scroll_resource->draw(SferaNumeric::real32(left), SferaNumeric::real32(top), SferaNumeric::real32(SphereUIDetail::addCoordinate(left, thumb_width)),
                                  SferaNumeric::real32(SphereUIDetail::addCoordinate(top, thumb_height)), color);
    }
    SphereUIWidgetSupport::drawChild(decrease_button.get(), alpha);
    SphereUIWidgetSupport::drawChild(increase_button.get(), alpha);
}

void SphereUIScrollBar::handleInput(const SphereUIWindowInput &input)
{
    SphereUIWidgetSupport::inputChild(decrease_button.get(), input);
    SphereUIWidgetSupport::inputChild(increase_button.get(), input);
    bool changed = false;
    SphereUIWindowEvent event{};
    while (pollEvent(event))
        if (event.message == SphereUIUiMessage::leftClick && (event.control_id == 1u || event.control_id == 2u))
            if (SphereUIScrollBar::moveScroll(*this, event.control_id == 2u, step))
            {
                changed = true;
                SphereUIScrollBar::playScrollSound(false);
            }
    if (input.wheel_delta != 0)
        if (auto *owner = parent)
            if (SphereUIWidgetSupport::contains(SphereUIWidgetSupport::windowBounds(*owner), input.mouse_x, input.mouse_y))
            {
                if (current != minimum && current != maximum)
                    SphereUIScrollBar::playScrollSound(false);
                current = SphereUIDetail::signedWord(SphereUIDetail::wireWord(current) - SphereUIDetail::wireWord(step) * SphereUIDetail::wireWord(input.wheel_delta));
                current = std::max(std::min(current, maximum), minimum);
                updateControlState();
                changed = true;
            }
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    const auto thumb_left = SphereUIDetail::addCoordinate(bounds.left, thumb_x);
    const auto thumb_top = SphereUIDetail::addCoordinate(bounds.top, thumb_y);
    if ((input.mouse_flags & SphereUIMouseInput::leftPress) != 0u && !dragging_thumb)
    {
        if (SphereUIWidgetSupport::contains({thumb_left, thumb_top, SphereUIDetail::addCoordinate(thumb_left, thumb_width), SphereUIDetail::addCoordinate(thumb_top, thumb_height)}, input.mouse_x,
                                            input.mouse_y))
            dragging_thumb = true;
        if (SphereUIWidgetSupport::contains(bounds, input.mouse_x, input.mouse_y))
            page_click_active = true;
    }
    if ((input.mouse_buttons & 1u) == 0u)
        dragging_thumb = page_click_active = false;
    const bool horizontal = (orientation_flags & 1u) != 0u;
    const auto span = SphereUIDetail::subtractCoordinate(maximum, minimum);
    if (dragging_thumb)
    {
        const int dimension = horizontal ? width : height;
        const auto relative = std::max(SphereUIDetail::subtractCoordinate(horizontal ? input.mouse_x : input.mouse_y, horizontal ? bounds.left : bounds.top), 0);
        const auto position = std::min(relative, dimension);
        const double numerator = position, denominator = dimension;
        const float fraction = dimension == 0 ? 0.0f : SferaNumeric::real32(numerator / denominator);
        const double scaled = fraction * span;
        const int value = SferaNumeric::truncateInt(scaled);
        if (current != value)
        {
            current = value;
            updateControlState();
            changed = true;
        }
    }
    if (!changed && (input.key_code == VK_PRIOR || input.key_code == VK_NEXT))
        if (SphereUIScrollBar::moveScroll(*this, input.key_code == VK_NEXT, page_step))
        {
            SphereUIScrollBar::playScrollSound(true);
            changed = true;
        }
    if (changed)
    {
        if (parent != nullptr)
            loadControlParameters();
        return;
    }
    if (dragging_thumb || !page_click_active || (input.mouse_buttons & 1u) == 0u)
        return;

    const float elapsed = SferaNumeric::real32(SphereUIRuntime::elapsedSeconds(repeat_started_at));
    if (!(elapsed > 0.1f))
        return;
    repeat_started_at = SphereUIRuntime::clockTicks();
    const SphereUIUiRect track{SphereUIDetail::addCoordinate(bounds.left, track_left), SphereUIDetail::addCoordinate(bounds.top, track_top),
                               SphereUIDetail::subtractCoordinate(bounds.right, track_right), SphereUIDetail::subtractCoordinate(bounds.bottom, track_bottom)};
    if (!SphereUIWidgetSupport::contains(track, input.mouse_x, input.mouse_y))
        return;
    const int dimension = horizontal ? SphereUIDetail::subtractCoordinate(track.right, track.left) : SphereUIDetail::subtractCoordinate(track.bottom, track.top);
    if (dimension == 0)
        return;
    const auto position = SphereUIDetail::subtractCoordinate(horizontal ? input.mouse_x : input.mouse_y, horizontal ? track.left : track.top);
    const double numerator = position, denominator = dimension;
    const float fraction = SferaNumeric::real32(numerator / denominator);
    const double scaled = fraction * span;
    const int target = SferaNumeric::truncateInt(scaled);
    if (current == target)
        return;
    const auto cursor = horizontal ? input.mouse_x : input.mouse_y;
    const auto thumb_start = horizontal ? thumb_left : thumb_top;
    const auto thumb_end = SphereUIDetail::addCoordinate(thumb_start, horizontal ? thumb_width : thumb_height);
    if (cursor < thumb_start)
        current = std::max(SphereUIDetail::subtractCoordinate(current, page_step), target);
    else if (cursor > thumb_end)
        current = std::min(SphereUIDetail::addCoordinate(current, page_step), target);
    else
        return;
    updateControlState();
    if (parent != nullptr)
        loadControlParameters();
}

void SphereUIScrollBar::updateControlState()
{
    const auto span = SphereUIDetail::subtractCoordinate(maximum, minimum);
    const double precise_current = current;
    normalized_position = span == 0 ? 0.0f : SferaNumeric::real32(std::clamp(precise_current / span, 0.0, 1.0));
    const auto available_width = SphereUIDetail::subtractCoordinate(SphereUIDetail::subtractCoordinate(width, track_left), track_right);
    const auto available_height = SphereUIDetail::subtractCoordinate(SphereUIDetail::subtractCoordinate(height, track_top), track_bottom);
    const auto horizontal_space = SphereUIDetail::subtractCoordinate(available_width, thumb_width);
    const auto vertical_space = SphereUIDetail::subtractCoordinate(available_height, thumb_height);
    const double horizontal_distance = horizontal_space, vertical_distance = vertical_space;
    thumb_x = SphereUIDetail::addCoordinate(track_left, (orientation_flags & 1u) != 0u ? SferaNumeric::truncateInt(horizontal_distance * normalized_position) : horizontal_space / 2);
    thumb_y = SphereUIDetail::addCoordinate(track_top, (orientation_flags & 1u) != 0u ? vertical_space / 2 : SferaNumeric::truncateInt(vertical_distance * normalized_position));
}

void SphereUIScrollBar::loadControlParameters()
{
    auto *owner = parent;
    if (owner == nullptr)
        return;
    const auto message = (orientation_flags & 1u) != 0u ? SphereUIUiMessage::horizontalScroll : SphereUIUiMessage::verticalScroll;
    owner->handleMessage(message, SphereUIDetail::wireWord(current), control_id);
    if (notify_changes)
        owner->queueEvent({this, control_id, message, SphereUIDetail::wireWord(current), 0u});
}

SphereUIScrollBar::SphereUIScrollBar()
{
    maximum = 100;
    step = 1;
    page_step = 20;
    dragging_thumb = explicit_step = notify_changes = page_click_active = hidden = false;
    control_kind = SphereUIUiControlKind::scrollBar;
}

void SphereUIScrollBar::setParameters(const SphereUIScrollParameters &parameters)
{
    if ((parameters.mask & ScrollField::range) != 0u)
    {
        minimum = parameters.minimum;
        maximum = parameters.maximum;
        SphereUIScrollBar::enableNavigationButtons(*this);
    }
    if ((parameters.mask & ScrollField::position) != 0u)
        current = std::min(std::max(parameters.current, minimum), maximum);
    if ((parameters.mask & ScrollField::page) != 0u)
        page_step = parameters.page_step;
    if ((parameters.mask & ScrollField::step) != 0u && !explicit_step)
        step = parameters.step;
    updateControlState();
}

void SphereUIScrollBar::getParameters(SphereUIScrollParameters &parameters) const
{
    parameters.minimum = minimum;
    parameters.maximum = maximum;
    parameters.page_step = page_step;
    parameters.current = current;
    parameters.step = step;
}

std::unique_ptr<SphereUIWindow> SphereUISliderCtrl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUISliderCtrl::copyCloneState);
}

void SphereUISliderCtrl::draw()
{
    if (hidden)
        return;
    SphereUIScrollBar::draw();
    if (display_mode != 0u)
    {
        const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
        const auto left = SphereUIDetail::addCoordinate(bounds.left, status_x);
        const auto top = SphereUIDetail::addCoordinate(bounds.top, status_y);
        SphereUIWidgetSupport::renderLabel(*this, value_text, left, top, text_color, {left, top, SphereUIDetail::addCoordinate(left, 100), SphereUIDetail::addCoordinate(top, 100)});
    }
}

void SphereUISliderCtrl::updateControlState()
{
    SphereUIScrollBar::updateControlState();
    SphereUIWidgetSupport::updateStatusText(value_text, display_mode, normalized_position * 100.0, current, SphereUIDetail::subtractCoordinate(maximum, minimum));
}

void SphereUISliderCtrl::loadControlParameters()
{
    if (auto *owner = parent)
        owner->queueEvent({this, control_id, SphereUIUiMessage::sliderValueChanged, SphereUIDetail::wireWord(current), 0u});
}

SphereUISliderCtrl::SphereUISliderCtrl()
{
    control_kind = SphereUIUiControlKind::slider;
    orientation_flags = 1u;
}

void SphereUISliderCtrl::copyCloneState(SphereUISliderCtrl &destination, const SphereUISliderCtrl &source, SphereUIWindowCloneContext &context)
{
    SphereUIWidgetSupport::copyScrollFields(destination, source, context);
    destination.value_text = source.value_text;
    destination.display_mode = source.display_mode;
    destination.status_x = source.status_x;
    destination.status_y = source.status_y;
}

void SphereUISpinButton::copySpinFields(SphereUISpinButton &destination, const SphereUISpinButton &source, SphereUIWindowCloneContext &context)
{
    SphereUIWidgetSupport::copyProperties(destination, source, &SphereUISpinButton::minimum, &SphereUISpinButton::maximum, &SphereUISpinButton::current, &SphereUISpinButton::previous,
                                          &SphereUISpinButton::step, &SphereUISpinButton::body_index, &SphereUISpinButton::status_valid, &SphereUISpinButton::notify_changes,
                                          &SphereUISpinButton::update_enabled);
    SphereUIWidgetSupport::cloneNavigationButtons(destination, source, context);
}

void SphereUISpinButton::setRange(int new_minimum, int new_maximum)
{
    minimum = new_minimum;
    maximum = new_maximum;
    status_valid = false;
}

void SphereUISpinButton::setCurrentValue(int value)
{
    current = value;
    status_valid = false;
    update_enabled = false;
}

std::unique_ptr<SphereUIWindow> SphereUISpinButton::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, SphereUISpinButton::copySpinFields);
}

std::uint32_t SphereUISpinButton::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::setSpinValue:
        setCurrentValue(SphereUIDetail::signedWord(first));
        return 1u;
    case SphereUIUiMessage::setSpinRange:
        setRange(SphereUIDetail::signedWord(first), SphereUIDetail::signedWord(second));
        return 1u;
    case SphereUIUiMessage::updateSpinStatus:
        updateStatus();
        return 1u;
    case SphereUIUiMessage::setSpinStep:
        setStep(SphereUIDetail::signedWord(first));
        return 1u;
    default:
        break;
    }
    if (message == SphereUIUiMessage::setEnabled || message == SphereUIUiMessage::setHidden)
    {
        if (auto *window = decrease_button.get())
            window->handleMessage(message, first, second);
        if (auto *window = increase_button.get())
            window->handleMessage(message, first, second);
    }
    return SphereUIWindow::handleMessage(message, first, second);
}

void SphereUISpinButton::draw()
{
    if (hidden)
        return;
    SphereUIWidgetSupport::drawChild(decrease_button.get(), alpha);
    SphereUIWidgetSupport::drawChild(increase_button.get(), alpha);
}

void SphereUISpinButton::handleInput(const SphereUIWindowInput &input)
{
    if (hidden)
        return;
    if (!disabled)
    {
        if (auto *window = increase_button.get())
            window->handleMessage(SphereUIUiMessage::setEnabled, current != maximum, 0u);
        if (auto *window = decrease_button.get())
            window->handleMessage(SphereUIUiMessage::setEnabled, current != minimum, 0u);
    }
    SphereUIWidgetSupport::inputChild(decrease_button.get(), input);
    SphereUIWidgetSupport::inputChild(increase_button.get(), input);
    SphereUIWindowEvent event{};
    while (pollEvent(event))
    {
        if (event.message != SphereUIUiMessage::leftClick)
            continue;
        if (event.control_id == 1u && current >= SphereUIDetail::addCoordinate(minimum, step))
        {
            current = SphereUIDetail::subtractCoordinate(current, step);
            status_valid = false;
        }
        if (event.control_id == 2u && current <= SphereUIDetail::subtractCoordinate(maximum, step))
        {
            current = SphereUIDetail::addCoordinate(current, step);
            status_valid = false;
        }
    }
    if (!status_valid)
        updateStatus();
}

void SphereUISpinButton::updateStatus()
{
    auto *owner = parent;
    if (owner == nullptr)
        return;
    SphereUIWindow *body = body_index == invalidIndex ? nullptr : owner->controlAt(body_index);
    if (current < minimum)
        current = minimum;
    if (current > maximum)
        current = maximum;
    if (current != previous)
    {
        if (auto *window = body)
        {
            auto value = std::format("{}", current);
            window->setText(value);
        }
        if (notify_changes && update_enabled)
            owner->queueEvent({this, control_id, SphereUIUiMessage::spinValueChanged, SphereUIDetail::wireWord(current), 0u});
        previous = current;
    }
    status_valid = true;
    update_enabled = true;
}

SphereUISpinButton::SphereUISpinButton()
{
    maximum = 100;
    previous = -1;
    step = 1;
    body_index = invalidIndex;
    status_valid = notify_changes = hidden = false;
    update_enabled = true;
    control_kind = SphereUIUiControlKind::spinButton;
}

std::unique_ptr<SphereUIWindow> SphereUITextCtrl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUITextCtrl::copyCloneState);
}

void SphereUITextCtrl::draw()
{
    if (!hidden && text.size() != 0u)
        SphereUIWidgetSupport::alignedLabel(*this, text_color);
}

void SphereUITextCtrl::handleInput(const SphereUIWindowInput &input)
{
    if ((text_style & 1u) != 0u && (input.mouse_flags & SphereUIMouseInput::leftPress) != 0u && containsPoint(input.mouse_x, input.mouse_y))
        SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::leftClick);
}

SphereUITextCtrl::SphereUITextCtrl()
{
    hidden = false;
    control_kind = SphereUIUiControlKind::text;
}

std::unique_ptr<SphereUIWindow> SphereUIFontPicker::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIFontPicker::copyCloneState);
}

std::uint32_t SphereUIFontPicker::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    if (message == SphereUIUiMessage::setSelectedFont)
    {
        setFont(first);
        return 1u;
    }
    return SphereUIWindow::handleMessage(message, first, second);
}

void SphereUIFontPicker::draw()
{
    if (hidden || (behavior_flags & SphereUIWindowStyle::skipDrawing) != 0u)
        return;
    SphereUIWidgetSupport::drawChild(selector.get(), alpha);
    SphereUIWidgetSupport::drawChild(preview.get(), alpha);
}

void SphereUIFontPicker::handleInput(const SphereUIWindowInput &input)
{
    if (hidden)
        return;
    SphereUIWidgetSupport::inputChild(selector.get(), input);
    SphereUIWidgetSupport::inputChild(preview.get(), input);
    SphereUIWindowEvent event{};
    while (pollEvent(event))
    {
        if (event.message != SphereUIUiMessage::spinValueChanged)
            continue;
        if (auto *window = preview.get())
        {
            const auto font_id = event.first + 2u;
            window->setFont(font_id);
            if (auto *owner = parent)
                owner->queueEvent({this, control_id, SphereUIUiMessage::selectedFontChanged, font_id, 0u});
        }
    }
}

void SphereUIFontPicker::setFont(int font_id)
{
    if (auto *spin = selector.get())
        spin->setCurrentValue(font_id - 2);
    if (auto *window = preview.get())
        window->setFont(font_id);
    SphereUIWindow::setFont(font_id);
}

int SphereUIFontPicker::getFont() const
{
    if (const auto *selector_control = selector.get())
        return selector_control->currentValue() + 2;
    if (const auto *preview_control = preview.get())
        return preview_control->getFont();
    return SphereUIWindow::getFont();
}

SphereUIFontPicker::SphereUIFontPicker()
{
    hidden = false;
    control_kind = SphereUIUiControlKind::fontPicker;
}

void SphereUIFontPicker::copyCloneState(SphereUIFontPicker &destination, const SphereUIFontPicker &source, SphereUIWindowCloneContext &context)
{
    SphereUIWidgetSupport::cloneOwned(destination.selector, source.selector, destination, context);
    SphereUIWidgetSupport::cloneOwned(destination.preview, source.preview, destination, context);
    if (auto *selector = destination.selector.get())
    {
        selector->setRange(0, g_sfera_fonts.count() - 1);
        selector->setStep(1);
        if (auto *preview = destination.preview.get())
            selector->setCurrentValue(preview->getFont() - 2);
    }
}
