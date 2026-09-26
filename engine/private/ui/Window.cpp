#include <windows.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <deque>
#include <functional>
#include <limits>
#include <memory>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

#include "ui/widgets/TextEditors.h"
#include "input/Cursors.h"
#include "input/DirectInputDevices.h"
#include "input/MouseInput.h"
#include "math/Color.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "runtime/Clock.h"
#include "text/HyperText.h"
#include "text/Text.h"
#include "ui/Rendering.h"
#include "ui/Sprite.h"
#include "ui/UiHost.h"
#include "ui/UiRuntime.h"
#include "ui/UiTypes.h"
#include "ui/WidgetSupport.h"
#include "ui/Window.h"
#include "ui/widgets/Controls.h"
#include "ui/widgets/Popups.h"

void SphereUIWindow::broadcastMessage(SphereUIWindow *root, int group, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second, SphereUIUiControlKind kind)
{
    if (root != nullptr)
    {
        root->dispatchMessage(group, message, first, second, kind);
        return;
    }
    SphereUIHost::broadcastMessage(group, message, first, second, kind);
}

SphereUIWindow::SphereUIWindow()
{
    hidden = true;
    can_go_top = save_last_position = font_initialized = true;
    text_color = UiColor::white;
    disabled_color = UiColor::opaqueBlack;
    alpha = 255u;
    SphereUIHost::registerWindow(*this);
}

SphereUIWindow &SphereUIWindow::copyStateFrom(const SphereUIWindow &source)
{
    if (this == &source)
        return *this;
    SphereUIWidgetSupport::copyProperties(*this, source, &SphereUIWindow::name, &SphereUIWindow::text, &SphereUIWindow::help, &SphereUIWindow::resource_name, &SphereUIWindow::behavior_flags,
                                          &SphereUIWindow::width, &SphereUIWindow::height, &SphereUIWindow::x, &SphereUIWindow::y, &SphereUIWindow::alignment_flags, &SphereUIWindow::group,
                                          &SphereUIWindow::initial_x, &SphereUIWindow::initial_y, &SphereUIWindow::hidden, &SphereUIWindow::disabled, &SphereUIWindow::input_enabled);
    template_instance = false;
    SphereUIWidgetSupport::copyProperties(*this, source, &SphereUIWindow::can_drag_drop, &SphereUIWindow::can_go_top, &SphereUIWindow::save_last_position, &SphereUIWindow::hit_transparent,
                                          &SphereUIWindow::control_kind, &SphereUIWindow::font, &SphereUIWindow::font_initialized, &SphereUIWindow::text_color, &SphereUIWindow::drag_over,
                                          &SphereUIWindow::disabled_color, &SphereUIWindow::parent, &SphereUIWindow::modal_owner, &SphereUIWindow::control_id, &SphereUIWindow::alpha,
                                          &SphereUIWindow::close_completed, &SphereUIWindow::text_offset_x, &SphereUIWindow::text_offset_y);
    tooltip = nullptr;
    SphereUIWidgetSupport::copyProperties(*this, source, &SphereUIWindow::overlay, &SphereUIWindow::resource_parent, &SphereUIWindow::caption_left, &SphereUIWindow::caption_top,
                                          &SphereUIWindow::caption_right, &SphereUIWindow::caption_bottom, &SphereUIWindow::dragging, &SphereUIWindow::drag_offset_x, &SphereUIWindow::drag_offset_y,
                                          &SphereUIWindow::text_alignment, &SphereUIWindow::hide_after_animation, &SphereUIWindow::animation, &SphereUIWindow::resources,
                                          &SphereUIWindow::resource_reference, &SphereUIWindow::show_animation, &SphereUIWindow::hide_animation, &SphereUIWindow::modal_references,
                                          &SphereUIWindow::events);
    SphereUIHost::copyEventHandler(this, &source);
    return *this;
}

std::unique_ptr<SphereUIWindow> SphereUIWindow::clone() const
{
    SphereUIWindowCloneContext context;
    auto result = cloneInto(context);
    context.finish();
    return result;
}

void SphereUIWindow::initializeCopy(const SphereUIWindow &source, SphereUIWindowCloneContext &context)
{
    if (!context.windows.emplace(&source, this).second)
        throw std::logic_error("UI clone has duplicate ownership");
    copyStateFrom(source);
    children.clear();
    children.reserve(source.children.size());
    for (const auto &child : source.children)
    {
        if (child)
            appendChild(child->cloneInto(context));
        else
            children.push_back(nullptr);
    }
    if (source.tooltip)
    {
        auto copy = source.tooltip->cloneInto(context);
        auto *typed = copy->asToolTipCtrl();
        if (typed == nullptr)
            throw std::logic_error("UI tooltip clone changed type");
        copy.release();
        tooltip.reset(typed);
    }
    else
        tooltip.reset();
    if (tooltip)
        tooltip->setParent(this);
}

void SphereUIWindow::appendChild(std::unique_ptr<SphereUIWindow> child)
{
    if (!child)
        return;
    child->setParent(this);
    children.push_back(std::move(child));
}

void SphereUIWindow::appendResource(std::shared_ptr<const SphereUIUiSprite> resource)
{
    if (resource)
        resources.push_back(std::move(resource));
}

std::shared_ptr<const SphereUIUiSprite> SphereUIWindow::findResource(std::string_view name_to_find) const
{
    if (resource_parent != nullptr)
        if (auto resource = resource_parent->findResource(name_to_find))
            return resource;
    const auto found = std::find_if(resources.begin(), resources.end(), std::bind_front(&SphereUIWindow::resourceNamed, name_to_find));
    return found == resources.end() ? nullptr : *found;
}

SphereUIWindow::~SphereUIWindow()
{
    SphereUIHost::forgetWindowResource(this);
    SphereUIHost::unbindEventHandler(this);
    auto owned_children = std::move(children);
    owned_children.clear();
    tooltip.reset();
    SphereUIHost::unregisterWindow(*this);
}

std::unique_ptr<SphereUIWindow> SphereUIWindow::cloneInto(SphereUIWindowCloneContext &context) const
{
    auto result = std::make_unique<SphereUIWindow>();
    result->initializeCopy(*this, context);
    return result;
}

std::uint32_t SphereUIWindow::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    if (message >= SphereUIUiMessage::setTooltipLine && message <= SphereUIUiMessage::setTooltipTextColor)
    {
        auto *tip = tooltip.get();
        if (tip == nullptr)
        {
            tooltip = std::make_unique<SphereUIToolTipCtrl>();
            tip = tooltip.get();
            if (tip == nullptr)
                return 0u;
            tip->setParent(this);
        }
        return tip->handleMessage(message, first, second);
    }

    switch (message)
    {
    case SphereUIUiMessage::setInputEnabled:
        input_enabled = first != 0u;
        break;
    case SphereUIUiMessage::setTextRgb:
        text_color = SferaColor::fromArgb(first).withAlpha(alpha).argb();
        break;
    case SphereUIUiMessage::setHidden:
        hidden = first != 0u;
        if (hidden)
            hideOwnTooltip();
        break;
    case SphereUIUiMessage::setEnabled:
        disabled = first == 0u;
        if (disabled)
            hideOwnTooltip();
        break;
    case SphereUIUiMessage::setTextAlignment:
        text_alignment = first;
        break;
    case SphereUIUiMessage::animateVisibility:
        animateVisibility(first != 0u);
        break;
    case SphereUIUiMessage::setPosition:
        setPosition(SphereUIDetail::signedWord(first), SphereUIDetail::signedWord(second));
        break;
    case SphereUIUiMessage::endModal:
        if (modal_owner != nullptr)
        {
            modal_owner = nullptr;
            handleMessage(SphereUIUiMessage::animateVisibility, 0u, 0u);
        }
        break;
    case SphereUIUiMessage::setSize:
        width = first;
        height = second;
        break;
    case SphereUIUiMessage::setFont:
        setFont(first);
        break;
    default:
        break;
    }
    return 1u;
}

void SphereUIWindow::draw()
{
    if (hidden)
        return;
    const auto *owner = parent;
    const auto screen_x = SphereUIDetail::addCoordinate(x, owner == nullptr ? 0 : owner->x);
    const auto screen_y = SphereUIDetail::addCoordinate(y, owner == nullptr ? 0 : owner->y);
    if ((behavior_flags & SphereUIWindowStyle::skipDrawing) == 0u && resource_reference != nullptr)
        resource_reference->drawNatural(SferaNumeric::real32(screen_x), SferaNumeric::real32(screen_y), SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    if ((behavior_flags & SphereUIWindowStyle::showTitle) != 0u && text.size() != 0u)
    {
        const auto caption_width = SphereUIDetail::subtractCoordinate(caption_right, caption_left);
        const auto caption_height = SphereUIDetail::subtractCoordinate(caption_bottom, caption_top);
        int font_id = font;
        auto top = SphereUIDetail::addCoordinate(SphereUIDetail::addCoordinate(screen_y, text_offset_y), caption_top);
        const auto measured = SphereUIInterfaceRenderer::measureText(getText(), font_id, font_initialized);
        if (SferaNumeric::word(measured.width) > SferaNumeric::word(caption_width))
        {
            font_id = 2u;
            const auto smaller = SphereUIInterfaceRenderer::measureText(getText(), font_id, font_initialized);
            top = SphereUIDetail::addCoordinate(top, SferaNumeric::signedWord((SferaNumeric::word(measured.height) - SferaNumeric::word(smaller.height)) >> 1u));
        }
        const auto left = SphereUIDetail::addCoordinate(SphereUIDetail::addCoordinate(screen_x, text_offset_x), caption_left);
        SphereUIWidgetSupport::renderLabel(*this, getText(), left, top, text_color,
                                           {left, top, SphereUIDetail::addCoordinate(left, SphereUIDetail::addCoordinate(caption_width, 10)),
                                            SphereUIDetail::addCoordinate(top, SphereUIDetail::addCoordinate(caption_height, 10))},
                                           font_id);
    }
    SphereUIDetail::forEachChild(*this, &SphereUIWindow::drawChildWindow);
}

void SphereUIWindow::handleInput(const SphereUIWindowInput &input)
{
    if (!input_enabled)
        return;
    const auto identity = registration_id;
    if (hide_after_animation && !isAnimating())
    {
        hide_after_animation = false;
        handleMessage(SphereUIUiMessage::setHidden, 1u, 0u);
        return;
    }
    if ((input.mouse_flags & SphereUIMouseInput::leftPress) != 0u && caption_left != caption_right)
    {
        int screen_x = 0;
        int screen_y = 0;
        getAbsolutePosition(screen_x, screen_y);
        if (input.mouse_x > SphereUIDetail::addCoordinate(screen_x, caption_left) && input.mouse_x <= SphereUIDetail::addCoordinate(screen_x, caption_right) &&
            input.mouse_y > SphereUIDetail::addCoordinate(screen_y, caption_top) && input.mouse_y <= SphereUIDetail::addCoordinate(screen_y, caption_bottom))
        {
            drag_offset_x = SphereUIDetail::subtractCoordinate(screen_x, input.mouse_x);
            drag_offset_y = SphereUIDetail::subtractCoordinate(screen_y, input.mouse_y);
            dragging = true;
        }
    }
    if (dragging)
    {
        x = SphereUIDetail::addCoordinate(drag_offset_x, input.mouse_x);
        y = SphereUIDetail::addCoordinate(drag_offset_y, input.mouse_y);
        if ((input.mouse_flags & SphereUIMouseInput::leftRelease) != 0u)
        {
            dragging = false;
            if (save_last_position)
                SphereUIHost::saveWindowPosition(*this);
        }
    }
    SphereUIDetail::forEachChild(*this, std::bind_front(&SphereUIWindow::inputChildWindow, std::cref(input)));
    if (!SphereUIHost::isRegistered(this, identity))
        return;
    if (auto *window = overlay; window != nullptr && !window->hidden)
        window->handleInput(input);
}

void SphereUIWindow::setOpacity(float opacity)
{
    const std::uint32_t new_alpha = SphereUIWidgetSupport::opacity_alpha(opacity * 255.0);
    alpha = new_alpha;
    SphereUIWidgetSupport::replace_color_alpha(text_color, new_alpha);
    SphereUIWidgetSupport::replace_color_alpha(disabled_color, new_alpha);
    SphereUIDetail::forEachChild(*this, std::bind_front(&SphereUIWindow::setChildOpacity, opacity));
}

bool SphereUIWindow::hitTest(int screen_x, int screen_y)
{
    if (hidden)
        return false;
    for (const auto &child : children)
    {
        if (child->can_drag_drop && child->containsPoint(screen_x, screen_y) && child->hitTest(screen_x, screen_y))
            break;
    }
    return true;
}

void SphereUIWindow::dispatchMessage(int target_group, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second, SphereUIUiControlKind target_kind)
{
    SphereUIDetail::forEachChild(*this, std::bind_front(&SphereUIWindow::dispatchChildMessage, target_group, message, first, second, target_kind));
}

void SphereUIWindow::setInputFocus(bool focused, bool submit_on_blur)
{
    if (!focused)
    {
        if (input_enabled && submit_on_blur)
            SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::editSubmit);
        input_enabled = false;
        return;
    }
    input_enabled = false;
    for (const auto kind : {SphereUIUiControlKind::edit, SphereUIUiControlKind::richEdit, SphereUIUiControlKind::hyperTextEdit})
        SphereUIWindow::broadcastMessage(nullptr, -1, SphereUIUiMessage::setInputEnabled, 0u, 0u, kind);
    input_enabled = true;
}

void SphereUIWindow::getAbsolutePosition(int &screen_x, int &screen_y) const
{
    screen_x = x;
    screen_y = y;
    for (auto *ancestor = parent; ancestor != nullptr; ancestor = ancestor->parent)
    {
        screen_x = SphereUIDetail::addCoordinate(screen_x, ancestor->x);
        screen_y = SphereUIDetail::addCoordinate(screen_y, ancestor->y);
    }
}

bool SphereUIWindow::containsPoint(int screen_x, int screen_y) const
{
    int left = 0;
    int top = 0;
    getAbsolutePosition(left, top);
    return screen_x >= left && screen_x < SphereUIDetail::addCoordinate(left, width) && screen_y >= top && screen_y < SphereUIDetail::addCoordinate(top, height);
}

int SphereUIWindow::childControlAt(int screen_x, int screen_y) const
{
    if (hidden)
        return 0;
    if (!containsPoint(screen_x, screen_y))
        return -1;
    for (auto it = children.rbegin(); it != children.rend(); ++it)
    {
        const auto &child = *it;
        if (!child->hidden && child->containsPoint(screen_x, screen_y))
            return child->control_id;
    }
    return 0;
}

void SphereUIWindow::queueEvent(const SphereUIWindowEvent &event)
{
    SphereUIDetail::enqueueWindowEvent(events, event);
}

bool SphereUIWindow::pollEvent(SphereUIWindowEvent &event)
{
    if (events.empty())
        return false;
    event = events.front();
    events.pop_front();
    return true;
}

void SphereUIWindow::processEvents()
{
    if (!SphereUIHost::hasEventHandler(this))
        return;
    const auto identity = registration_id;
    SphereUIWindowEvent event{};
    while (SphereUIHost::isRegistered(this, identity) && pollEvent(event))
        SphereUIHost::dispatchEvent(this, event);
}

void SphereUIWindow::resetToolTips()
{
    if (auto *tip = tooltip.get())
        tip->reset();
    SphereUIDetail::forEachChild(*this, &SphereUIWindow::resetChildToolTips);
}

void SphereUIWindow::drawToolTips()
{
    SphereUIDetail::forEachChild(*this, &SphereUIWindow::drawChildToolTips);
    if (auto *control = overlay)
        if (!control->hidden)
            control->draw();
}

void SphereUIWindow::alignToScreen(bool reset_position)
{
    if (reset_position)
    {
        x = initial_x;
        y = initial_y;
    }
    const auto screen = SphereUIRuntime::screenSize();
    const auto horizontal = SferaNumeric::word(screen.width) - SferaNumeric::word(width), vertical = SferaNumeric::word(screen.height) - SferaNumeric::word(height);
    if ((alignment_flags & SphereUIalignRight) != 0u)
        x = SphereUIDetail::addCoordinate(x, horizontal);
    if ((alignment_flags & SphereUIalignBottom) != 0u)
        y = SphereUIDetail::addCoordinate(y, vertical);
    if ((alignment_flags & SphereUIalignCenterX) != 0u)
        x = SphereUIDetail::addCoordinate(x, horizontal >> 1u);
    if ((alignment_flags & SphereUIalignCenterY) != 0u)
        y = SphereUIDetail::addCoordinate(y, vertical >> 1u);
}

void SphereUIWindow::applyAnimation(const SphereUIWindowAnimationPlayback &playback, float fraction)
{
    const auto &effect = playback.effect;
    if (effect.kind == SphereUIWindowAnimationKind::FadeIn || effect.kind == SphereUIWindowAnimationKind::FadeOut)
    {
        setOpacity(effect.kind == SphereUIWindowAnimationKind::FadeIn ? fraction : 1.0f - fraction);
        return;
    }
    if (effect.kind < SphereUIWindowAnimationKind::MoveLeft || effect.kind > SphereUIWindowAnimationKind::MoveDown)
        return;
    const double precise_distance = effect.distance;
    const double distance = precise_distance * fraction;
    const double value = playback.origin + ((effect.kind == SphereUIWindowAnimationKind::MoveLeft || effect.kind == SphereUIWindowAnimationKind::MoveUp) ? -distance : distance);
    const auto coordinate = !std::isfinite(value) || value < -2147483648.0 || value >= 2147483648.0 ? std::numeric_limits<int>::min() : SferaNumeric::truncateInt(value);
    if (effect.kind <= SphereUIWindowAnimationKind::MoveRight)
        setPosition(coordinate, y);
    else
        setPosition(x, coordinate);
}

void SphereUIWindow::startAnimation(SphereUIWindowAnimationPhase phase)
{
    if (animation)
        applyAnimation(*animation, 1.0f);
    animation.reset();
    if (phase == SphereUIWindowAnimationPhase::Idle || phase > SphereUIWindowAnimationPhase::Closing)
        return;
    if (phase == SphereUIWindowAnimationPhase::Showing)
        setOpacity(1.0f);
    const auto &effect = phase == SphereUIWindowAnimationPhase::Showing ? show_animation : hide_animation;
    if (effect.kind == SphereUIWindowAnimationKind::None)
        return;
    SphereUIWindowAnimationPlayback playback{effect, SphereUIRuntime::clockTicks(), 0.0f, phase};
    if (effect.kind >= SphereUIWindowAnimationKind::MoveLeft && effect.kind <= SphereUIWindowAnimationKind::MoveDown)
    {
        double origin = effect.kind <= SphereUIWindowAnimationKind::MoveRight ? x : y;
        origin -= (effect.kind == SphereUIWindowAnimationKind::MoveRight || effect.kind == SphereUIWindowAnimationKind::MoveDown) ? effect.distance : 0.0f;
        playback.origin = SferaNumeric::real32(origin + effect.offset);
    }
    animation = playback;
    SphereUIWindow::playWindowSound(phase == SphereUIWindowAnimationPhase::Showing);
    updateAnimation();
}

void SphereUIWindow::updateAnimation()
{
    if (!animation)
        return;
    const float elapsed = SferaNumeric::real32(SphereUIRuntime::elapsedSeconds(animation->start_time));
    float fraction = elapsed / animation->effect.duration;
    if (!std::isfinite(fraction) || fraction < 0.0f || fraction > 1.0f)
        fraction = 1.0f;
    applyAnimation(*animation, fraction);
    if (fraction == 1.0f)
    {
        if (animation->phase == SphereUIWindowAnimationPhase::Closing)
            close_completed = true;
        startAnimation(SphereUIWindowAnimationPhase::Idle);
    }
}

void SphereUIWindow::beginClose(bool animated)
{
    if (!animated)
    {
        hidden = close_completed = true;
        input_enabled = false;
        return;
    }
    startAnimation(SphereUIWindowAnimationPhase::Closing);
    if (!isAnimating())
        close_completed = true;
    input_enabled = false;
}

void SphereUIWindow::animateVisibility(bool hide)
{
    if (hide)
    {
        startAnimation(SphereUIWindowAnimationPhase::Hiding);
        hide_after_animation = isAnimating();
        if (!isAnimating())
            handleMessage(SphereUIUiMessage::setHidden, 1u, 0u);
    }
    else
    {
        hide_after_animation = false;
        handleMessage(SphereUIUiMessage::setHidden, 0u, 0u);
        startAnimation(SphereUIWindowAnimationPhase::Showing);
    }
}

void SphereUIWindow::beginModal(SphereUIWindow *owner)
{
    if (modal_owner != nullptr)
        return;
    modal_owner = owner;
    animateVisibility(true);
}

bool SphereUIWindow::resourceNamed(std::string_view name_to_find, const std::shared_ptr<const SphereUIUiSprite> &resource)
{
    return SferaText::asciiEqual(resource->name, name_to_find);
}

void SphereUIWindow::hideOwnTooltip()
{
    if (auto *tip = tooltip.get())
        tip->reset();
}

void SphereUIWindow::inputChildWindow(const SphereUIWindowInput &input, SphereUIWindow &child)
{
    if (child.disabled)
        return;
    const auto child_identity = child.registration_id;
    if (auto *tip = child.tooltip.get())
        tip->handleInput(input);
    if (SphereUIHost::isRegistered(&child, child_identity))
        child.handleInput(input);
}

void SphereUIWindow::dispatchChildMessage(int target_group, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second, SphereUIUiControlKind target_kind, SphereUIWindow &child)
{
    if (target_group != -1 && child.group != target_group)
        return;
    const auto identity = child.registration_id;
    if (target_kind == anyControlKind || child.control_kind == target_kind)
        child.handleMessage(message, first, second);
    if (SphereUIHost::isRegistered(&child, identity) && child.control_kind == SphereUIUiControlKind::listItem)
        child.dispatchMessage(target_group, message, first, second, target_kind);
}

void SphereUIWindow::drawChildToolTips(SphereUIWindow &child)
{
    if (!child.hidden)
        if (auto *tip = child.tooltip.get())
            tip->draw();
}

std::array<std::string, 256> SphereUIRuntime::createKeyNames()
{
    std::array<std::string, 256> result{};
    for (const auto &binding : uiKeyBindings)
        result[binding.code] = binding.name;
    constexpr std::string_view printable = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (std::size_t index = 0; index < printable.size(); ++index)
        result[printable[index]].assign(printable.substr(index, 1u));
    for (std::size_t index = 0u; index != 12u; ++index)
        result[VK_F1 + index] = "F" + std::to_string(index + 1u);
    for (std::size_t index = 0u; index != 10u; ++index)
        result[VK_NUMPAD0 + index] = "NUMPAD" + std::to_string(index);
    return result;
}
std::string_view SphereUIRuntime::keyName(std::uint32_t code)
{
    static const auto names = createKeyNames();
    return code < names.size() ? std::string_view(names[code]) : std::string_view{};
}

std::uint32_t SphereUIRuntime::scanCode(std::uint32_t key)
{
    if (key >= VK_F1 && key <= VK_F10)
        return 59u + key - VK_F1;
    if (key == VK_F11 || key == VK_F12)
        return 87u + key - VK_F11;
    if (key >= '1' && key <= '9')
        return 2u + key - '1';
    if (key == '0')
        return 11u;
    if (key == VK_NUMPAD0)
        return 82u;
    if (key >= VK_NUMPAD1 && key <= VK_NUMPAD9)
    {
        const auto digit = key - VK_NUMPAD0;
        return 83u - 4u * ((digit + 2u) / 3u) + ((digit - 1u) % 3u);
    }

    static constexpr SphereUIKeyboardRow rows[] = {{"QWERTYUIOP", 16u}, {"ASDFGHJKL", 30u}, {"ZXCVBNM", 44u}};
    for (const auto &row : rows)
    {
        const auto position = std::find(row.keys.begin(), row.keys.end(), key);
        if (position != row.keys.end())
            return row.first_scan + SphereUIDetail::wireWord(position - row.keys.begin());
    }
    for (const auto &binding : uiKeyBindings)
        if (binding.code == key)
            return binding.scan;
    return 0u;
}

std::uint32_t SphereUIRuntime::virtualKey(std::uint32_t scan)
{
    for (std::uint32_t key = 0u; key <= 255u; ++key)
        if (SphereUIRuntime::scanCode(key) == scan)
            return key;
    return 0u;
}

void SphereUIRuntime::setSystemCursorVisible(bool visible)
{
    if (visible)
    {
        while (::ShowCursor(TRUE) < 0)
        {
        }
    }
    else
    {
        while (::ShowCursor(FALSE) >= 0)
        {
        }
    }
}

void SphereUIRuntime::setTextInputActive(bool active)
{
    g_sfera_direct_input_runtime.text_filter = active ? 1u : 0u;
}

std::uint64_t SphereUIRuntime::clockTicks()
{
    return WorldClock::nowTicks();
}

double SphereUIRuntime::elapsedSeconds(std::uint64_t started)
{
    const auto raw = clockTicks() - started;
    std::int64_t ticks{};
    std::memcpy(&ticks, &raw, sizeof(ticks));
    const double value = SphereUIDetail::real64(ticks);
    return value / 10000.0;
}

std::uint32_t SphereUIRuntime::milliseconds()
{
    return WorldClock::milliseconds();
}

bool SphereUIRuntime::keyDown(std::uint32_t key)
{
    return key < 256u && g_sfera_direct_input_runtime.keyboard_state[key] != 0u;
}

SphereUITextExtent SphereUIRuntime::screenSize()
{
    return {g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height};
}

bool SphereUIWidgetSupport::readHexColor(std::string_view text, std::uint32_t &color)
{
    auto input = text;
    return SphereUIWidgetSupport::readInteger(input, color, 16);
}

SphereUIUiRect SphereUIWidgetSupport::windowBounds(const SphereUIWindow &window)
{
    SphereUIUiRect result{};
    window.getAbsolutePosition(result.left, result.top);
    result.right = SphereUIDetail::addCoordinate(result.left, window.width);
    result.bottom = SphereUIDetail::addCoordinate(result.top, window.height);
    return result;
}

void SphereUIWidgetSupport::renderLabel(const SphereUIWindow &window, std::string_view text, int x, int y, std::uint32_t color, const SphereUIUiRect &clip, int font)
{
    if (text.empty())
        return;
    SphereUIInterfaceRenderer::drawText(text, x, y, color, font == inheritFont ? window.font : font, window.font_initialized, clip, window.alpha == 255u);
}

void SphereUIWidgetSupport::alignedLabel(const SphereUIWindow &window, std::uint32_t color)
{
    const auto bounds = SphereUIWidgetSupport::windowBounds(window);
    int dx = 0;
    int dy = 0;
    if (window.text_alignment != 0u)
    {
        const auto extent = SphereUIInterfaceRenderer::measureText(window.getText(), window.font, window.font_initialized);
        if (extent.width < window.width)
        {
            if ((window.text_alignment & TextAlignment::right) != 0u)
                dx = window.width - extent.width;
            if ((window.text_alignment & TextAlignment::horizontalCenter) != 0u)
                dx = (window.width - extent.width) / 2;
        }
        if (extent.height < window.height)
        {
            if ((window.text_alignment & TextAlignment::bottom) != 0u)
                dy = window.height - extent.height;
            if ((window.text_alignment & TextAlignment::verticalCenter) != 0u)
                dy = (window.height - extent.height) / 2;
        }
    }
    SphereUIWidgetSupport::renderLabel(window, window.getText(), SphereUIDetail::addCoordinate(bounds.left, dx), SphereUIDetail::addCoordinate(bounds.top, dy), color, bounds);
}

void SphereUIWidgetSupport::notifyParent(SphereUIWindow &window, SphereUIUiMessage message, std::size_t first, std::size_t second)
{
    if (auto *owner = window.parent)
    {
        owner->queueEvent({&window, window.control_id, message, SphereUIDetail::wireWord(first), SphereUIDetail::wireWord(second)});
    }
}

void SphereUIWidgetSupport::copyScrollFields(SphereUIScrollBar &destination, const SphereUIScrollBar &source, SphereUIWindowCloneContext &context)
{
    SphereUIWidgetSupport::copyProperties(destination, source, &SphereUIScrollBar::scroll_resource, &SphereUIScrollBar::thumb_width, &SphereUIScrollBar::thumb_height, &SphereUIScrollBar::thumb_x,
                                          &SphereUIScrollBar::thumb_y, &SphereUIScrollBar::orientation_flags, &SphereUIScrollBar::normalized_position, &SphereUIScrollBar::minimum,
                                          &SphereUIScrollBar::maximum, &SphereUIScrollBar::current, &SphereUIScrollBar::step, &SphereUIScrollBar::page_step, &SphereUIScrollBar::dragging_thumb,
                                          &SphereUIScrollBar::explicit_step, &SphereUIScrollBar::notify_changes, &SphereUIScrollBar::repeat_started_at, &SphereUIScrollBar::track_left,
                                          &SphereUIScrollBar::track_top, &SphereUIScrollBar::track_right, &SphereUIScrollBar::track_bottom, &SphereUIScrollBar::page_click_active);
    SphereUIWidgetSupport::cloneNavigationButtons(destination, source, context);
}

std::uint32_t SphereUIWidgetSupport::opacity_alpha(double value)
{
    return SferaNumeric::truncatedWord(value);
}

void SphereUIWidgetSupport::replace_color_alpha(std::uint32_t &color, std::uint32_t alpha)
{
    color = SferaColor::fromArgb(color).withAlpha(alpha).argb();
}

void SphereUIWidgetSupport::updateStatusText(std::string &text, std::uint32_t mode, double percent, int current, int range)
{
    if (mode == 1u)
        text = std::to_string(SferaNumeric::truncateInt(percent)) + "%";
    else if (mode == 2u)
        text = std::to_string(current) + " / " + std::to_string(range);
}

void SphereUIWidgetSupport::drawChild(SphereUIWindow *address, std::uint32_t alpha)
{
    if (auto *child = address)
    {
        if (child->alpha != alpha)
            child->setOpacity(alpha / 255.0f);
        child->draw();
    }
}

void SphereUIWidgetSupport::inputChild(SphereUIWindow *address, const SphereUIWindowInput &input)
{
    if (auto *child = address)
        child->handleInput(input);
}

float SphereUIWidgetSupport::spriteTextureCoordinate(double pixel, int extent)
{
    return extent == 0 ? 0.0f : SferaNumeric::real32(pixel / extent);
}

SphereUITextExtent SphereUIWidgetSupport::hyperTextExtent(std::string_view text, int font)
{
    auto result = SphereUIInterfaceRenderer::measureText(text, font, true);
    if (text.empty())
        result.width = 0;
    else if (font < 2u)
        result.width = std::max(0, result.width - 2);
    return result;
}

std::size_t SphereUIWidgetSupport::hyperWordEnd(std::string_view text, std::size_t first, bool controls)
{
    auto end = first;
    while (end < text.size() && isWordSeparator(controls, text[end]))
        ++end;
    while (end < text.size() && !isWordSeparator(controls, text[end]))
        ++end;
    return end;
}

void SphereUIDetail::enqueueWindowEvent(std::deque<SphereUIWindowEvent> &events, const SphereUIWindowEvent &event)
{
    if (events.size() >= 64u)
        events.clear();
    events.push_back(event);
}

std::int32_t SphereUIDetail::signedWord(std::uint32_t value) noexcept
{
    return SferaNumeric::signedWord(value);
}

std::string SphereUIDetail::escapeHyperText(std::string_view text)
{
    std::string output;
    for (const auto character : text)
    {
        if (character == '<')
            output += "\\[";
        else if (character == '>')
            output += "\\]";
        else
        {
            if (character == '"' || character == '\\')
                output += '\\';
            output += character;
        }
    }
    return output;
}

void SphereUIDetail::serializeHyperTextElements(std::span<const HyperTextRun> elements, std::string &hyper_text, std::string &plain)
{
    std::string raw, visible;
    for (const auto &element : elements)
    {
        if (element.isWrap())
            raw += element.text;
        else
        {
            if (const auto *link = element.link())
                raw += "<l " + link->parameters + ">";
            raw += escapeHyperText(element.text);
            if (element.link() != nullptr)
                raw += "</l>";
        }
        visible += element.text;
    }
    hyper_text = std::move(raw);
    plain = std::move(visible);
}

void SphereUICDescriptionWindow::draw()
{
    if (hidden)
        return;
    const auto caption = caption_sprite;
    const auto lower = bottom_sprite;
    const auto left = left_sprite;
    const auto right = right_sprite;
    if (caption == nullptr || lower == nullptr || left == nullptr || right == nullptr)
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    const auto color = SferaColor::rgba(255u, 255u, 255u, alpha).argb();
    const float left_x = SferaNumeric::real32(bounds.left), top_y = SferaNumeric::real32(bounds.top);
    SphereUIInterfaceRenderer::drawTexture(nullptr, left_x - 0.5f + left->width, top_y - 0.5f + caption->height, SferaNumeric::real32(bounds.right) - 0.5f - right->width,
                                           SferaNumeric::real32(bounds.bottom) - 0.5f - lower->height, SferaColor::fromArgb(UiColor::frameBackground).withAlpha(alpha * 166u / 255u).argb(), 0.0f, 0.0f,
                                           false);
    caption_sprite->drawNatural(left_x, top_y, color);
    bottom_sprite->drawNatural(left_x, SferaNumeric::real32(bounds.bottom - lower->height), color);
    float offset = SferaNumeric::real32(caption->height);
    const auto end = height - lower->height;
    const float tile = SferaNumeric::real32(left->height);
    const auto right_x = SferaNumeric::real32(bounds.right - right->width);
    if (tile > 0.0f)
        while (offset + tile <= end)
        {
            left_sprite->drawNatural(left_x, top_y + offset, color);
            right_sprite->drawNatural(right_x, top_y + offset, color);
            offset += tile;
        }
    if (offset < end)
    {
        left_sprite->draw(left_x, top_y + offset, left_x + left->width, top_y + end, color);
        right_sprite->draw(right_x, top_y + offset, SferaNumeric::real32(bounds.right), top_y + SferaNumeric::real32(end), color);
    }
    SphereUIDetail::forEachChild(*this, &SphereUICDescriptionWindow::drawChild);
}

SphereUICDescriptionWindow::~SphereUICDescriptionWindow()
{
    if (SphereUIRuntime::descriptionWindow() == this)
        SphereUICDescriptionWindow::setDescriptionWindow(nullptr);
}

std::unique_ptr<SphereUIWindow> SphereUICDescriptionWindow::cloneInto(SphereUIWindowCloneContext &context) const
{
    auto copy = std::unique_ptr<SphereUICDescriptionWindow>(new SphereUICDescriptionWindow(std::in_place));
    copy->initializeCopy(*this, context);
    copy->displayed_source = displayed_source;
    copy->pending_source = pending_source;
    copy->show_deadline = show_deadline;
    copy->hide_deadline = hide_deadline;
    copy->caption_sprite = caption_sprite;
    copy->bottom_sprite = bottom_sprite;
    copy->left_sprite = left_sprite;
    copy->right_sprite = right_sprite;
    copy->frame_height = frame_height;
    copy->pinned = pinned;
    return copy;
}

void SphereUICDescriptionWindow::close()
{
    displayed_source = pending_source = nullptr;
    hidden = true;
    resetToolTips();
    input_enabled = false;
}

void SphereUICDescriptionWindow::update()
{
    if (SphereUIRuntime::keyDown(42u) || SphereUIRuntime::keyDown(54u))
        return;
    if ((!SphereUICDescriptionWindow::descriptionAutoPopup() && !pinned) || (!hidden && WorldClock::deadlineReached(SphereUIRuntime::milliseconds(), hide_deadline)))
        close();
}

void SphereUICDescriptionWindow::handleEvent(const SphereUIWindowEvent &event)
{
    if (event.message == SphereUIUiMessage::close || (event.message == SphereUIUiMessage::leftClick && event.control_id == 2u))
        close();
}

SferaCursorPosition *SphereUICDescriptionWindow::calculatePosition(SferaCursorPosition *output) const
{
    if (output == nullptr)
        return nullptr;
    const auto cursor = CCursorManager::instance().geometry();
    const auto screen = SphereUIRuntime::screenSize();

    output->x = placeAxis(cursor.x, width, screen.width, cursor.width, cursor.centered);
    output->y = placeAxis(cursor.y, height, screen.height, cursor.height, cursor.centered);
    return output;
}

void SphereUICDescriptionWindow::showDescription(std::string_view description_text, const SphereUIWindow *source, std::uint32_t duration, bool pin)
{
    SphereUIWindow *content = nullptr;
    SphereUIDetail::forEachChild(*this, std::bind(&SphereUICDescriptionWindow::selectFirstChild, std::ref(content), std::placeholders::_1));
    if (content == nullptr)
        throw std::runtime_error("description content control is missing");
    if (auto *hypertext = content->asHyperTextCtrl())
    {
        hypertext->queueBuffer(description_text);
        hypertext->handleMessage(SphereUIUiMessage::resizeToHyperText, 0u, 0u);
    }
    height = SphereUIDetail::addCoordinate(frame_height, content->height);
    SferaCursorPosition position{};
    calculatePosition(&position);
    setPosition(position.x, position.y);
    displayed_source = pending_source = source;
    hide_deadline = SphereUIRuntime::milliseconds() + duration;
    pinned = pin ? 1u : 0u;
    hidden = false;
    input_enabled = true;
}

void SphereUICDescriptionWindow::requestDescription(std::string_view description_text, bool force, const SphereUIWindow *source)
{
    if (description_text.empty())
        return;
    if (force)
    {
        showDescription(description_text, source, 250u, false);
        return;
    }
    if (!SphereUICDescriptionWindow::descriptionAutoPopup() || SphereUIRuntime::keyDown(42u) || SphereUIRuntime::keyDown(54u))
        return;
    if (pending_source != source)
    {
        pending_source = source;
        show_deadline = SphereUIRuntime::milliseconds() + 500u;
    }
    if (displayed_source == pending_source)
        hide_deadline = SphereUIRuntime::milliseconds() + 250u;
    else if (WorldClock::deadlineReached(SphereUIRuntime::milliseconds(), show_deadline))
        showDescription(description_text, pending_source, 250u, false);
}

int SphereUICDescriptionWindow::placeAxis(int position, int extent, int limit, int size, bool centered)
{
    const auto before = centered ? size / 2 : 0;
    const auto after = centered ? size / 2 : size;
    const auto start = SphereUIDetail::addCoordinate(position, after);
    if (SphereUIDetail::addCoordinate(start, extent) <= limit)
        return start;
    const auto reverse = SphereUIDetail::subtractCoordinate(SphereUIDetail::subtractCoordinate(position, extent), before);
    return reverse >= 0 ? reverse : SphereUIDetail::subtractCoordinate(limit, extent);
}

std::unique_ptr<SphereUIWindow> SphereUIToolTipCtrl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIToolTipCtrl::copyCloneState);
}

std::uint32_t SphereUIToolTipCtrl::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::setTooltipBackground:
        background_color = first;
        return 1u;
    case SphereUIUiMessage::setTooltipTextColor:
        text_color = first;
        return 1u;
    default:
        return message >= SphereUIUiMessage::setTooltipLine && message <= SphereUIUiMessage::setTooltipTextColor ? 0u : SphereUIWindow::handleMessage(message, first, second);
    }
}

void SphereUIToolTipCtrl::draw()
{
    if (hidden)
        return;
    const auto screen = SphereUIRuntime::screenSize();
    screen_x = std::max(0, std::min(screen_x, SphereUIDetail::subtractCoordinate(screen.width, tooltip_width)));
    screen_y = std::max(0, std::min(screen_y, SphereUIDetail::subtractCoordinate(screen.height, tooltip_height)));
    const auto *owner = parent;
    const std::uint32_t opacity = SferaNumeric::truncatedWord(std::clamp((owner == nullptr ? alpha : owner->alpha) * fade_opacity, 0.0f, 255.0f));
    text_color = SferaColor::fromArgb(text_color).withAlpha(opacity).argb();
    const auto right = SphereUIDetail::addCoordinate(screen_x, tooltip_width), bottom = SphereUIDetail::addCoordinate(screen_y, tooltip_height);
    const float leftf = SferaNumeric::real32(screen_x), topf = SferaNumeric::real32(screen_y);
    const float rightf = SferaNumeric::real32(right), bottomf = SferaNumeric::real32(bottom);
    SphereUIInterfaceRenderer::drawTexture(nullptr, leftf, topf, rightf, bottomf, SferaColor::fromArgb(background_color).withAlpha(SferaColor::fromArgb(background_color).alpha() | opacity).argb(),
                                           0.0f, 0.0f, false);
    SphereUIInterfaceRenderer::drawTexture(nullptr, leftf, topf, rightf, topf + 1.0f, text_color, 0.0f, 0.0f, false);
    SphereUIInterfaceRenderer::drawTexture(nullptr, leftf, bottomf - 1.0f, rightf, bottomf, text_color, 0.0f, 0.0f, false);
    SphereUIInterfaceRenderer::drawTexture(nullptr, leftf, topf, leftf + 1.0f, bottomf, text_color, 0.0f, 0.0f, false);
    SphereUIInterfaceRenderer::drawTexture(nullptr, rightf - 1.0f, topf, rightf, bottomf, text_color, 0.0f, 0.0f, false);
    const auto text_x = SphereUIDetail::addCoordinate(screen_x, margin_left);
    auto text_y = SphereUIDetail::addCoordinate(screen_y, margin_top);
    const SphereUIUiRect clip{text_x, text_y, SphereUIDetail::addCoordinate(text_x, tooltip_width), SphereUIDetail::addCoordinate(text_y, tooltip_height)};
    for (std::size_t index = 0u; index < lines.size(); ++index)
    {
        SphereUIInterfaceRenderer::drawText(lines.at(index), text_x, text_y, text_color, font, true, clip, opacity == 255u);
        text_y = SphereUIDetail::addCoordinate(text_y, line_height);
    }
}

void SphereUIToolTipCtrl::handleInput(const SphereUIWindowInput &input)
{
    if (lines.size() == 0u || lines.at(0u).size() == 0u)
    {
        hidden = true;
        return;
    }
    updateFade();
    auto *owner = parent;
    if (owner == nullptr || owner->hidden)
        return;
    if ((input.mouse_flags & 3u) != 0u || input.wheel_delta != 0)
    {
        dismissed = true;
        hidden = true;
    }
    if (hidden && !dismissed)
    {
        if (!hover_pending || screen_x != input.mouse_x || screen_y != input.mouse_y)
            hover_pending = false;
        else if (SphereUIRuntime::elapsedSeconds(hover_started) > 0.5f)
            showAt(input.mouse_x, input.mouse_y);
    }
    if (!SphereUIWidgetSupport::contains(SphereUIWidgetSupport::windowBounds(*owner), input.mouse_x, input.mouse_y))
    {
        reset();
        return;
    }
    if (!hover_pending && hidden)
    {
        hover_pending = true;
        screen_x = input.mouse_x;
        screen_y = input.mouse_y;
        hover_started = SphereUIRuntime::clockTicks();
    }
}

SphereUIToolTipCtrl::SphereUIToolTipCtrl()
{
    background_color = UiColor::tooltipBackground;
    text_color = 0u;
    font = 2u;
    control_kind = SphereUIUiControlKind::tooltip;
    hidden = true;
    tooltip_width = 52;
    tooltip_height = 12;
    margin_left = 3;
    margin_top = 1;
    margin_right = 2;
    margin_bottom = 1;
}

void SphereUIToolTipCtrl::reset()
{
    fade_opacity = 0.0f;
    hidden = true;
    hover_pending = dismissed = false;
}

void SphereUIToolTipCtrl::showAt(int cursor_x, int cursor_y)
{
    if (fade_opacity == 0.0f)
        fade_started = SphereUIRuntime::clockTicks();
    hidden = false;
    screen_x = SphereUIDetail::addCoordinate(cursor_x, 10);
    screen_y = SphereUIDetail::addCoordinate(cursor_y, 20);
}

void SphereUIToolTipCtrl::updateFade()
{
    if (hidden || fade_opacity == 1.0f)
        return;
    const std::int64_t elapsed = SphereUIRuntime::clockTicks() - fade_started;
    fade_opacity = std::min(elapsed / 10000.0f * 4.0f, 1.0f);
}

void SphereUIToolTipCtrl::updateLayout()
{
    int widest = 0, total = 0;
    line_height = 0;
    for (std::size_t index = 0u; index < lines.size(); ++index)
    {
        const auto extent = SphereUIInterfaceRenderer::measureText(lines.at(index), font, true);
        widest = std::max(widest, extent.width);
        total = SphereUIDetail::addCoordinate(total, extent.height);
        line_height = extent.height;
    }
    tooltip_width = SphereUIDetail::addCoordinate(widest, SphereUIDetail::addCoordinate(margin_left, margin_right));
    tooltip_height = SphereUIDetail::addCoordinate(total, SphereUIDetail::addCoordinate(margin_top, margin_bottom));
}

void SphereUIToolTipCtrl::setLine(std::uint32_t index, std::optional<std::string_view> line_text)
{
    if (index >= lines.size())
    {
        if (line_text)
            appendLine(*line_text);
        return;
    }
    const auto value = line_text.value_or(std::string_view{});
    if (lines.at(index) == value)
        return;
    lines.at(index).assign(value);
    updateLayout();
}

void SphereUIToolTipCtrl::copyCloneState(SphereUIToolTipCtrl &destination, const SphereUIToolTipCtrl &source, SphereUIWindowCloneContext &)
{
    SphereUIWidgetSupport::copyProperties(destination, source, &SphereUIToolTipCtrl::screen_x, &SphereUIToolTipCtrl::screen_y, &SphereUIToolTipCtrl::hover_pending, &SphereUIToolTipCtrl::hover_started,
                                          &SphereUIToolTipCtrl::fade_opacity, &SphereUIToolTipCtrl::fade_started, &SphereUIToolTipCtrl::background_color, &SphereUIToolTipCtrl::tooltip_width,
                                          &SphereUIToolTipCtrl::tooltip_height, &SphereUIToolTipCtrl::dismissed, &SphereUIToolTipCtrl::line_height, &SphereUIToolTipCtrl::margin_left,
                                          &SphereUIToolTipCtrl::margin_top, &SphereUIToolTipCtrl::margin_right, &SphereUIToolTipCtrl::margin_bottom, &SphereUIToolTipCtrl::lines);
}
