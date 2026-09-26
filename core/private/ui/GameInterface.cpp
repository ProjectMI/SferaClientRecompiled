#include <windows.h>
#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <dinput.h>
#include <functional>
#include <memory>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <sys/stat.h>
#include <utility>
#include <vector>

#include "audio/GameAudio.h"
#include "chat/ChatFilter.h"
#include "graphics/d3d9/Device.h"
#include "input/Cursors.h"
#include "input/DirectInputDevices.h"
#include "input/MouseInput.h"
#include "math/Color.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "resources/FileResources.h"
#include "resources/TextureRepository.h"
#include "script/MbcRuntime.h"
#include "text/Fonts.h"
#include "text/HyperText.h"
#include "text/Text.h"
#include "ui/Canvas.h"
#include "ui/GameInterfaceManager.h"
#include "ui/Rendering.h"
#include "ui/ScriptInterface.h"
#include "ui/Sprite.h"
#include "ui/UiHost.h"
#include "ui/UiRuntime.h"
#include "ui/UiTypes.h"
#include "ui/WidgetSupport.h"
#include "ui/Window.h"
#include "ui/widgets/Controls.h"
#include "ui/widgets/Lists.h"
#include "ui/widgets/Popups.h"
#include "ui/widgets/TextEditors.h"

SphereUIInterfaceManager::~SphereUIInterfaceManager()
{
    shutdown();
}

void SphereUIInterfaceManager::finishInitialization()
{
    drag_drop_active = false;
    initialized = true;
}

bool SphereUIInterfaceManager::shutdown()
{
    const bool was_initialized = initialized;
    clearWindows();
    tooltip.reset();
    clearWindowTemplates();
    clearHyperTexts();
    g_sfera_fonts.clear();
    clearLocalizedStrings();
    events.clear();
    cursor.reset();
    cursor_name.clear();
    g_sfera_interface.cursor_kind = 255u;
    clearSprites();
    event_handlers.clear();
    initialized = false;
    drag_drop_active = false;
    return was_initialized;
}

void SphereUIInterfaceManager::clearWindows()
{
    help_window = nullptr;
    load_screen = nullptr;
    g_sfera_interface.description_control = nullptr;
    while (!windows.empty())
    {
        auto window = std::move(windows.front());
        windows.pop_front();
    }
}

void SphereUIInterfaceManager::queueEvent(const SphereUIWindowEvent &event)
{
    SphereUIDetail::enqueueWindowEvent(events, event);
}

bool SphereUIInterfaceManager::pollEvent(SphereUIWindowEvent &event)
{
    if (events.empty())
        return false;
    event = events.front();
    events.pop_front();
    return true;
}

SphereUIWindow *SphereUIInterfaceManager::findWindow(std::string_view name, bool exact) const
{
    if (name.empty())
        return nullptr;
    const auto found = std::find_if(windows.begin(), windows.end(), std::bind_front(&SphereUIInterfaceManager::matchesWindowName, name, exact));
    return found == windows.end() ? nullptr : found->get();
}

SphereUIWindow *SphereUIInterfaceManager::windowUnderCursor() const
{
    SferaCursorPosition position{};
    CCursorManager::instance().activeCursor()->getPosition(&position);
    const auto found = std::find_if(windows.rbegin(), windows.rend(), std::bind_front(&SphereUIInterfaceManager::windowContainsCursor, std::cref(position)));
    return found == windows.rend() ? nullptr : found->get();
}

bool SphereUIInterfaceManager::hasEscapeWindow() const
{
    return std::any_of(windows.begin(), windows.end(), &SphereUIInterfaceManager::handlesEscape);
}

SphereUIWindow *SphereUIInterfaceManager::addTopLevelWindow(std::unique_ptr<SphereUIWindow> window)
{
    if (!window)
        return nullptr;
    auto *result = window.get();
    windows.push_back(std::move(window));
    return result;
}

void SphereUIInterfaceManager::raiseWindow(SphereUIWindow &window)
{
    const auto found = std::find_if(windows.begin(), windows.end(), std::bind_front(&SphereUIInterfaceManager::ownsWindow, &window));
    if (found != windows.end())
        windows.splice(windows.end(), windows, found);
}

void SphereUIInterfaceManager::lowerWindow(SphereUIWindow &window)
{
    const auto found = std::find_if(windows.begin(), windows.end(), std::bind_front(&SphereUIInterfaceManager::ownsWindow, &window));
    if (found != windows.end())
        windows.splice(windows.begin(), windows, found);
}

void SphereUIInterfaceManager::collectCoveredWindows(SphereUIWindow &window)
{
    if (!g_sfera_interface.cross_enabled)
        return;
    SphereUIUiRect bounds{};
    window.getAbsolutePosition(bounds.left, bounds.top);
    bounds.right = bounds.left + window.width;
    bounds.bottom = bounds.top + window.height;
    const std::int64_t width = window.width;
    const std::int64_t area = width * window.height;
    if (area <= 0)
        return;
    for (auto current = windows.rbegin(); current != windows.rend(); ++current)
    {
        SphereUIWindow *other = current->get();
        if (other == nullptr || other == &window || other->hidden || other->isAnimating() || other->close_completed || (other->behavior_flags & SphereUIWindowStyle::preventOverlap) != 0u)
            continue;
        SphereUIUiRect other_bounds{};
        other->getAbsolutePosition(other_bounds.left, other_bounds.top);
        other_bounds.right = other_bounds.left + other->width;
        other_bounds.bottom = other_bounds.top + other->height;
        if (other_bounds.right < bounds.left || bounds.right < other_bounds.left || other_bounds.bottom < bounds.top || bounds.bottom < other_bounds.top)
            continue;
        const bool contains_window = other_bounds.left < bounds.left && other_bounds.right > bounds.right && other_bounds.top < bounds.top && other_bounds.bottom > bounds.bottom;
        if (contains_window)
        {
            window.addModalReference(*other);
            continue;
        }
        const bool contained_window = other_bounds.left > bounds.left && other_bounds.right < bounds.right && other_bounds.top > bounds.top && other_bounds.bottom < bounds.bottom;
        std::int64_t covered_width = other->width;
        int covered_height = other->height;
        if (!contained_window)
        {
            if (other_bounds.left < bounds.left)
                covered_width = std::min(bounds.right, other_bounds.right) - bounds.left;
            else if (other_bounds.left > bounds.left)
                covered_width = bounds.right - other_bounds.left;
            if (other_bounds.top < bounds.top)
                covered_height = std::min(bounds.bottom, other_bounds.bottom) - bounds.top;
            else if (other_bounds.top > bounds.top)
                covered_height = bounds.bottom - other_bounds.top;
        }
        const double covered_area = SphereUIDetail::real64(covered_width * covered_height);
        const float coverage = SferaNumeric::real32(covered_area / SphereUIDetail::real64(area));
        if (coverage > 0.3f)
            window.addModalReference(*other);
    }
}

SphereUIWindow *SphereUIInterfaceManager::openWindow(std::string_view name, int x, int y, std::uint32_t flags)
{
    if (name.empty())
        return nullptr;
    std::string template_name(name);
    if (const auto separator = template_name.rfind(':'); separator != std::string::npos)
        template_name.resize(separator);
    SphereUIWindow *original = templateWindow(template_name);
    if (original == nullptr)
        return nullptr;
    auto window = original->clone();
    if (window == nullptr)
    {
        SphereUIInterfaceRenderer::reportError("Cannot clone the requested window template.");
        return nullptr;
    }
    window->setName(name);
    if ((flags & SphereUIInterfaceManagerexplicitPosition) != 0u)
        window->setPosition(x, y);
    else
    {
        const SphereUISavedWindowPosition *saved = savedPosition(name, false);
        const bool valid_position = saved != nullptr && (saved->x < g_sfera_graphics_runtime.display_width - 15 || saved->y < g_sfera_graphics_runtime.display_height - 15);
        if (valid_position && window->save_last_position && findWindow(name, true) == nullptr)
            window->setPosition(saved->x, saved->y);
        else
        {
            if ((flags & SphereUIInterfaceManagercenterOnScreen) != 0u)
                window->alignment_flags = SphereUIalignCenterX | SphereUIalignCenterY;
            window->alignToScreen(false);
        }
    }
    if ((flags & SphereUIInterfaceManagerpreserveVisibility) == 0u)
        window->hidden = false;
    if (!window->hidden && (flags & SphereUIInterfaceManagerskipOpeningAnimation) == 0u)
        window->startAnimation(SphereUIWindowAnimationPhase::Showing);
    window->input_enabled = true;
    collectCoveredWindows(*window);
    for (auto *reference : window->modal_references)
        if (isRegistered(reference) && !reference->modal_owner)
        {
            reference->modal_owner = window.get();
            reference->handleMessage(SphereUIUiMessage::animateVisibility, 1u, 0u);
        }
    return addTopLevelWindow(std::move(window));
}

void SphereUIInterfaceManager::closeWindow(SphereUIWindow *window, bool animated)
{
    if (window == nullptr)
        return;
    if (window->control_id != 0u)
        SphereUIInterfaceRenderer::reportError("Cannot close a child control through the interface manager.");
    window->beginClose(animated);
}

void SphereUIInterfaceManager::showHelpPage(std::optional<std::string_view> name)
{
    if (!name)
    {
        closeWindow(help_window);
        help_window = nullptr;
        return;
    }
    if (findHyperText(*name) == nullptr)
        return;
    if (help_window == nullptr)
    {
        help_window = openWindow("help");
        bindEventHandler(help_window, SphereUIWindowEventHandler::help);
    }
    else
        raiseWindow(*help_window);
    if (help_window == nullptr)
        return;
    auto *control = help_window->controlAt(3u)->asHyperTextCtrl();
    if (control == nullptr)
        return;
    if (control->document != nullptr && SferaText::asciiEqual(control->document->name, *name))
        return;
    sendMessage(help_window->controlAt(2u), SphereUIUiMessage::setEnabled, control->history.size() != 0u ? 1u : 0u, 0u);
    control->queuePage(*name, true);
}

void SphereUIInterfaceManager::setTooltipText(std::optional<std::string_view> text)
{
    if (!text)
    {
        if (tooltip != nullptr && !tooltip_disabled)
            tooltip->reset();
        return;
    }
    if (!tooltip)
        tooltip = std::make_unique<SphereUIToolTipCtrl>();
    if (tooltip == nullptr)
        return;
    tooltip->setLine(0u, *text);
    SferaCursorPosition position{};
    CCursorManager::instance().activeCursor()->getPosition(&position);
    tooltip->showAt(position.x, position.y);
}

void SphereUIInterfaceManager::setCursorKind(std::uint32_t kind, int x, int y)
{
    if (!cursor)
        return;
    std::optional<std::string_view> texture;
    if (kind == 64u || kind == 65u)
    {
        texture = "curseye";
        kind = 64u;
    }
    else if (kind == 66u || kind == 67u)
        texture = "cursman";
    else if (kind != 255u)
        return;
    else
    {
        x = 0;
        y = 0;
    }
    cursor->setImage(0u, texture, x, y);
    g_sfera_interface.cursor_kind = kind;
}

void SphereUIInterfaceManager::setCursorImage(std::optional<std::string_view> texture, int x, int y)
{
    if (!cursor)
        return;
    if (!texture)
    {
        x = 0;
        y = 0;
    }
    cursor->setImage(1u, texture, x, y);
    cursor_name = texture.value_or(std::string_view{});
}

std::uint32_t SphereUIInterfaceManager::sendMessage(SphereUIWindow *window, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    if (message == SphereUIUiMessage::beginDragDrop)
    {
        drag_drop_active = true;
        return 1u;
    }
    if (message < SphereUIUiMessage::close)
        SphereUIInterfaceRenderer::reportError("Unknown interface manager message.");
    return isRegistered(window) ? window->handleMessage(message, first, second) : 0u;
}

void SphereUIInterfaceManager::draw()
{
    const auto saved_clip = SphereUIInterfaceRenderer::clip_rectangle;
    SphereUIInterfaceRenderer::setSpriteRenderMode(1u);
    try
    {
        if (g_sfera_interface.ui_enabled)
        {
            for (const auto &owner : windows)
                if (auto *window = owner.get())
                    window->draw();
            for (const auto &owner : windows)
                if (auto *window = owner.get())
                    window->drawToolTips();
        }
        if (tooltip != nullptr && !tooltip_disabled)
            tooltip->draw();
        if (cursor && cursor->system_visible)
        {
            SphereUIInterfaceRenderer::clip_rectangle.left = 0;
            SphereUIInterfaceRenderer::clip_rectangle.top = 0;
            SphereUIInterfaceRenderer::clip_rectangle.right = g_sfera_graphics_runtime.display_width;
            SphereUIInterfaceRenderer::clip_rectangle.bottom = g_sfera_graphics_runtime.display_height;
            CCursor *active = CCursorManager::instance().activeCursor();
            SferaCursorPosition position{};
            active->getPosition(&position);
            if (active->isInsideViewport())
                cursor->draw(SferaNumeric::real32(position.x), SferaNumeric::real32(position.y));
        }
    }
    catch (...)
    {
        SphereUIInterfaceRenderer::clip_rectangle = saved_clip;
        SphereUIInterfaceRenderer::setSpriteRenderMode(0u);
        throw;
    }
    SphereUIInterfaceRenderer::clip_rectangle = saved_clip;
    SphereUIInterfaceRenderer::setSpriteRenderMode(0u);
}

void SphereUIInterfaceManager::showLoadingScreen(bool visible, int width, int height, bool english)
{
    if (!visible)
    {
        closeWindow(load_screen);
        load_screen = nullptr;
        return;
    }
    if (load_screen == nullptr)
    {
        load_screen = openWindow("loadscreen", 0, 0, SphereUIInterfaceManagerskipOpeningAnimation);
        if (load_screen == nullptr)
            return;
        lowerWindow(*load_screen);
    }
    load_screen->setPosition(0, 0);
    load_screen->handleMessage(SphereUIUiMessage::setSize, 0u, 0u);
    const int image_width = std::min(width, 1024);
    const int image_height = std::min(height, 768);
    const int left = width > 1024 ? (width - 1024) / 2 : 0;
    const int top = height > 768 ? (height - 768) / 2 : 0;
    sendMessage(load_screen->controlAt(2u), SphereUIUiMessage::setPosition, left, top);
    sendMessage(load_screen->controlAt(2u), SphereUIUiMessage::setSize, image_width, image_height);
    sendMessage(load_screen->controlAt(1u), SphereUIUiMessage::setPosition, 0u, 0u);
    sendMessage(load_screen->controlAt(1u), SphereUIUiMessage::setSize, width, height);
    if (auto *image = load_screen->controlAt(2u)->asImageCtrl())
    {
        SphereUIImageDescription description{};
        description.name = english ? "english_sphere1" : "russian_sphere1";
        image->setImage(&description);
    }
    const int progress_left = left + SferaNumeric::truncateInt(image_width * 0.3701171875);
    const int progress_top = top + SferaNumeric::truncateInt(image_height * 0.83203125);
    const int progress_width = SferaNumeric::truncateInt(image_width * 0.2490234375);
    const int progress_height = SferaNumeric::truncateInt(image_height * 0.0247395833);
    for (const auto index : {3u, 4u})
    {
        sendMessage(load_screen->controlAt(index), SphereUIUiMessage::setPosition, progress_left, progress_top);
        sendMessage(load_screen->controlAt(index), SphereUIUiMessage::setSize, progress_width, progress_height);
    }
    sendMessage(load_screen->controlAt(3u), SphereUIUiMessage::setProgressValue, 100u, 0u);
    sendMessage(load_screen->controlAt(5u), SphereUIUiMessage::setPosition, left + 375, top + 520);
    sendMessage(load_screen->controlAt(5u), SphereUIUiMessage::setSize, 620u, 90u);
}

void SphereUIInterfaceManager::setLoadingProgress(int percent)
{
    if (load_screen != nullptr)
        sendMessage(load_screen->controlAt(3u), SphereUIUiMessage::setProgressValue, std::clamp(percent, 0, 100), 0u);
}

void SphereUIInterfaceManager::update(std::uint8_t key, std::uint8_t character, std::uint32_t mouse_buttons, int wheel_delta)
{
    const auto &keyboard = g_sfera_direct_input_runtime.keyboard_state;
    if (key == VK_F12 && keyboard[DIK_LCONTROL] != 0u)
        g_sfera_interface.ui_enabled = !g_sfera_interface.ui_enabled;
    else if (key == VK_F1)
        showHelpPage("Language\\helpindex.hts");
    if (!g_sfera_interface.ui_enabled)
        return;
    if (g_sfera_direct_input_runtime.binding_capture != 0u && g_sfera_direct_input_runtime.binding_key != 0u && capture_control_binding)
    {
        const SphereUIWindowEvent event{nullptr, 0u, SphereUIUiMessage::controlBindingCaptured, g_sfera_direct_input_runtime.binding_key, 0u};
        SphereUIInterfaceManager::invokeEventHandler(SphereUIWindowEventHandler::control_options, nullptr, event);
        g_sfera_direct_input_runtime.binding_key = 0u;
    }
    if (auto *description = g_sfera_interface.description_control)
        description->update();
    SferaCursorPosition position{};
    CCursorManager::instance().activeCursor()->getPosition(&position);
    SphereUIWindowInput input{position.x, position.y, wheel_delta, 0u, mouse_buttons, key, character, 0u};
    const auto previous_buttons = g_sfera_interface.previous_input_modifiers;
    const auto changed_buttons = mouse_buttons ^ previous_buttons;
    input.mouse_flags = (changed_buttons & mouse_buttons & 3u) | ((changed_buttons & previous_buttons & 3u) << 2u);
    g_sfera_interface.previous_input_modifiers = mouse_buttons;
    if (keyboard[DIK_LSHIFT] != 0u)
        input.key_modifiers |= 1u;
    if (keyboard[DIK_RSHIFT] != 0u)
        input.key_modifiers |= 2u;
    if (keyboard[DIK_LCONTROL] != 0u)
        input.key_modifiers |= 4u;
    if (g_sfera_direct_input_runtime.modifier_08 != 0u)
        input.key_modifiers |= 8u;
    if (keyboard[DIK_LMENU] != 0u)
        input.key_modifiers |= 16u;
    if (g_sfera_direct_input_runtime.modifier_20 != 0u)
        input.key_modifiers |= 32u;
    std::vector<std::pair<SphereUIWindow *, std::uint64_t>> closing_candidates;
    closing_candidates.reserve(windows.size());
    for (const auto &window : windows)
        closing_candidates.emplace_back(window.get(), window->registration_id);
    for (const auto &[window, identity] : closing_candidates)
    {
        if (!isRegistered(window, identity) || !window->close_completed)
            continue;
        std::vector<SphereUIWindow *> references;
        references = window->modal_references;
        for (SphereUIWindow *reference : references)
        {
            if (!isRegistered(reference) || reference->isAnimating() ||
                std::find_if(windows.begin(), windows.end(), std::bind_front(&SphereUIInterfaceManager::ownsWindow, reference)) == windows.end())
                continue;
            reference->handleMessage(SphereUIUiMessage::endModal, 0u, 0u);
        }
        if (!isRegistered(window, identity))
            continue;
        if (window->control_id != 0u)
        {
            SphereUIInterfaceRenderer::reportError("Cannot destroy a child control through the interface manager.");
            continue;
        }
        const auto owned = std::find_if(windows.begin(), windows.end(), std::bind_front(&SphereUIInterfaceManager::ownsWindow, window));
        if (owned != windows.end())
        {
            auto removed = std::move(*owned);
            windows.erase(owned);
        }
    }
    SphereUIWindow *target = nullptr;
    for (auto window = windows.rbegin(); window != windows.rend(); ++window)
        if (isRegistered(window->get()) && (*window)->hidden == 0u && ((*window)->dragging != 0u || (*window)->containsPoint(position.x, position.y)))
        {
            target = window->get();
            break;
        }
    if (auto *description = g_sfera_interface.description_control; description != nullptr && !description->hidden)
    {
        for (auto window = windows.rbegin(); window != windows.rend(); ++window)
            if (isRegistered(window->get()) && (*window)->dragging != 0u)
            {
                target = window->get();
                break;
            }
    }
    if ((input.mouse_flags & SphereUIMouseInput::leftPress) != 0u && target != nullptr && target->can_go_top && !target->hit_transparent && !target->hidden)
        raiseWindow(*target);
    if (auto *description = g_sfera_interface.description_control; description != nullptr && !description->hidden)
        raiseWindow(*description);
    bool completed_drag = false;
    if (drag_drop_active)
    {
        for (const auto &owner : windows)
            if (auto *window = owner.get())
            {
                if (!isRegistered(window) || !window->can_drag_drop)
                    continue;
                const bool entered = window == target;
                if (entered == window->drag_over)
                    continue;
                window->queueEvent({window, 0u, entered ? SphereUIUiMessage::dragEnter : SphereUIUiMessage::dragLeave, 0u, 0u});
                window->drag_over = entered;
            }
        if ((input.mouse_flags & SphereUIMouseInput::leftRelease) != 0u)
        {
            const bool accepted = isRegistered(target) && target->can_drag_drop && target->hitTest(position.x, position.y);
            if (!accepted)
                queueEvent({nullptr, 0u, SphereUIUiMessage::dropToScene, SphereUIDetail::wireWord(position.x), SphereUIDetail::wireWord(position.y)});
            for (const auto &owner : windows)
                if (auto *window = owner.get())
                {
                    if (!isRegistered(window) || !window->drag_over)
                        continue;
                    window->queueEvent({window, 0u, SphereUIUiMessage::dragLeave, 0u, 0u});
                    window->drag_over = false;
                }
            completed_drag = true;
        }
    }
    if (input.key_code == VK_ESCAPE)
    {
        const auto window = std::find_if(windows.rbegin(), windows.rend(), std::bind_front(&SphereUIInterfaceManager::registeredEscapeWindow, this));
        if (window != windows.rend())
            (*window)->queueEvent({window->get(), 0u, SphereUIUiMessage::close, 0u, 0u});
    }
    SphereUIRuntime::setTextInputActive(false);
    input.mouse_x = input.mouse_y = 0;
    std::vector<std::pair<SphereUIWindow *, std::uint64_t>> input_order;
    input_order.reserve(windows.size());
    for (auto window = windows.rbegin(); window != windows.rend(); ++window)
        input_order.emplace_back(window->get(), (*window)->registration_id);
    for (const auto &[window, identity] : input_order)
    {
        if (!isRegistered(window, identity))
            continue;
        if (window == target)
        {
            input.mouse_x = position.x;
            input.mouse_y = position.y;
        }
        if (window->input_enabled && !window->hidden)
            window->handleInput(input);
        input.mouse_x = input.mouse_y = 0;
        if (!isRegistered(window, identity))
            continue;
        if (window->isAnimating())
            window->updateAnimation();
        if (isRegistered(window, identity) && hasEventHandler(window))
            window->processEvents();
    }
    if (tooltip != nullptr && !tooltip_disabled)
        tooltip->handleInput(input);
    if (completed_drag)
        drag_drop_active = false;
}

void SphereUIInterfaceManager::registerWindow(SphereUIWindow &window)
{
    if (registered_windows.contains(&window))
        return;
    if (next_registration_id == 0u)
        throw std::overflow_error("UI registration identity exhausted");
    registered_windows.insert(&window);
    window.registration_id = next_registration_id++;
}

void SphereUIInterfaceManager::unregisterWindow(SphereUIWindow &window)
{
    unbindEventHandler(&window);
    std::erase_if(events, std::bind_front(&SphereUIInterfaceManager::eventFromWindow, &window));
    for (auto *observer : registered_windows)
    {
        std::erase(observer->modal_references, &window);
        std::erase_if(observer->events, std::bind_front(&SphereUIInterfaceManager::eventFromWindow, &window));
        if (observer->parent == &window)
            observer->parent = nullptr;
        if (observer->modal_owner == &window)
            observer->modal_owner = nullptr;
        if (observer->overlay == &window)
            observer->overlay = nullptr;
        if (observer->resource_parent == &window)
            observer->resource_parent = nullptr;
        if (auto *description = observer->asDescriptionWindow(); description && description != &window)
        {
            if (description->displayed_source == &window)
                description->displayed_source = nullptr;
            if (description->pending_source == &window)
                description->pending_source = nullptr;
        }
    }

    registered_windows.erase(&window);
    if (help_window == &window)
        help_window = nullptr;
    if (load_screen == &window)
        load_screen = nullptr;
    if (g_sfera_interface.description_control == &window)
        g_sfera_interface.description_control = nullptr;
}



void SphereUIInterfaceManager::bindEventHandler(SphereUIWindow *window, SphereUIWindowEventHandler handler)
{
    if (window == nullptr)
        return;
    if (handler == SphereUIWindowEventHandler::none)
        event_handlers.erase(window);
    else
        event_handlers.insert_or_assign(window, handler);
}

void SphereUIInterfaceManager::copyEventHandler(SphereUIWindow *destination, const SphereUIWindow *source)
{
    if (destination == nullptr || destination == source)
        return;
    const auto binding = event_handlers.find(source);
    bindEventHandler(destination, binding == event_handlers.end() ? SphereUIWindowEventHandler::none : binding->second);
}


void SphereUIInterfaceManager::dispatchEvent(SphereUIWindow *window, const SphereUIWindowEvent &event)
{
    const auto binding = event_handlers.find(window);
    SphereUIInterfaceManager::invokeEventHandler(binding == event_handlers.end() ? SphereUIWindowEventHandler::none : binding->second, window, event);
}


bool SphereUIInterfaceManager::matchesWindowName(std::string_view name, bool exact, const std::unique_ptr<SphereUIWindow> &window)
{
    return window != nullptr && (exact ? window->getResourceName() == name : SferaText::asciiEqual(window->getResourceName(), name));
}

bool SphereUIInterfaceManager::windowContainsCursor(const SferaCursorPosition &position, const std::unique_ptr<SphereUIWindow> &window)
{
    return window != nullptr && !window->hidden && !window->hit_transparent && window->containsPoint(position.x, position.y);
}

bool SphereUIInterfaceManager::handlesEscape(const std::unique_ptr<SphereUIWindow> &window)
{
    return window != nullptr && !window->hidden && (window->behavior_flags & SphereUIWindowStyle::handleEscape) != 0u;
}


bool SphereUIInterfaceManager::registeredEscapeWindow(const std::unique_ptr<SphereUIWindow> &candidate) const
{
    return isRegistered(candidate.get()) && !candidate->hidden && (candidate->behavior_flags & SphereUIWindowStyle::handleEscape) != 0u;
}

int GameInterface::loading_completed{};

uint32_t GameInterface::active_window{};
int GameInterface::loading_total{};
uint32_t GameInterface::loading_guard{};

void SphereUIHost::registerWindow(SphereUIWindow &window)
{
    g_sfera_interface.registerWindow(window);
}
void SphereUIHost::unregisterWindow(SphereUIWindow &window)
{
    g_sfera_interface.unregisterWindow(window);
}
bool SphereUIHost::isRegistered(const SphereUIWindow *window)
{
    return g_sfera_interface.isRegistered(window);
}
bool SphereUIHost::isRegistered(const SphereUIWindow *window, std::uint64_t identity)
{
    return g_sfera_interface.isRegistered(window, identity);
}
void SphereUIHost::forgetWindowResource(SphereUIWindow *window)
{
    g_sfera_mbc_runtime.forgetNativeResource(window);
}
void SphereUIHost::copyEventHandler(SphereUIWindow *destination, const SphereUIWindow *source)
{
    g_sfera_interface.copyEventHandler(destination, source);
}
void SphereUIHost::unbindEventHandler(const SphereUIWindow *window)
{
    g_sfera_interface.unbindEventHandler(window);
}
bool SphereUIHost::hasEventHandler(const SphereUIWindow *window)
{
    return g_sfera_interface.hasEventHandler(window);
}
void SphereUIHost::dispatchEvent(SphereUIWindow *window, const SphereUIWindowEvent &event)
{
    g_sfera_interface.dispatchEvent(window, event);
}
void SphereUIHost::saveWindowPosition(SphereUIWindow &window)
{
    g_sfera_interface.saveWindowPosition(window);
}
void SphereUIHost::showHelpPage(std::optional<std::string_view> name)
{
    g_sfera_interface.showHelpPage(name);
}
SphereUIHyperTextDocument *SphereUIHost::findHyperText(std::string_view name)
{
    return g_sfera_interface.findHyperText(name);
}
std::shared_ptr<const SphereUIUiSprite> SphereUIHost::acquireSprite(std::string_view name)
{
    return g_sfera_interface.acquireSprite(name);
}
std::string_view SphereUIHost::localizedText(std::string_view key)
{
    return g_sfera_interface.localizedText(key);
}
bool SphereUIHost::dragDropActive()
{
    return g_sfera_interface.drag_drop_active;
}
SferaInterfaceCursor *SphereUIHost::cursor()
{
    return g_sfera_interface.cursor.get();
}
void SphereUIHost::broadcastMessage(int group, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second, SphereUIUiControlKind kind)
{
    for (const auto &window : g_sfera_interface.windows)
    {
        if (window != nullptr)
        {
            window->dispatchMessage(group, message, first, second, kind);
        }
    }
}

GameUiElement *SferaCanvasHost::control(std::uint32_t handle)
{
    return WorldGuiControls::control(handle);
}

void SferaCanvasHost::setTextExtent(int width, int height)
{
    WorldGuiControls::text_width = width;
    WorldGuiControls::text_height = height;
}

bool SphereUICursorSupport::cursor_uses_center_clip(std::uint32_t kind)
{
    const auto name = SferaCursorTextureHelper::name(kind);
    return !name.empty() && name.front() != '_';
}

void CHardwareCursor::setCursorKind(std::uint32_t new_kind)
{
    const auto name = SferaCursorTextureHelper::name(new_kind);
    if (name.empty())
    {
        ::SetCursor(nullptr);
        cursor_handle.reset();
        kind = new_kind;
        texture_width = texture_height = 0u;
        show();
        apply();
        return;
    }
    const std::string relative_path = std::string("textures\\cursors\\") + std::string(name) + ".bmp";
    SphereUIBitmapOwner color;
    for (const auto &path : g_sfera_files.candidatePaths(relative_path, true))
    {
        color.reset(static_cast<HBITMAP>(::LoadImageA(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION)));
        if (color)
            break;
    }
    if (!color)
        throw std::runtime_error("CreateCursor(): failed to load cursor image from file");
    BITMAP bitmap{};
    if (::GetObjectA(color.get(), sizeof(bitmap), &bitmap) == 0 || bitmap.bmWidth != 32 || bitmap.bmHeight != 32 || bitmap.bmBitsPixel != 32 || bitmap.bmBits == nullptr)
        throw std::runtime_error("CreateCursor(): invalid cursor image format");
    const std::size_t mask_stride = (bitmap.bmWidth + 15u) / 16u * 2u;
    std::vector<std::uint8_t> mask_bits(mask_stride * bitmap.bmHeight, 0u);
    const auto *pixels = static_cast<const std::uint32_t *>(bitmap.bmBits);
    for (LONG y = 0; y < bitmap.bmHeight; ++y)
        for (LONG x = 0; x < bitmap.bmWidth; ++x)
            if (SferaColor::fromArgb(pixels[y * bitmap.bmWidth + x]).alpha() == 0u)
                mask_bits[y * mask_stride + x / 8u] |= 1u << (7 - x % 8);
    SphereUIBitmapOwner mask(::CreateBitmap(bitmap.bmWidth, bitmap.bmHeight, 1u, 1u, mask_bits.data()));
    if (!mask)
        throw std::runtime_error("CreateCursor(): failed to create cursor mask");
    const bool centered = SphereUICursorSupport::cursor_uses_center_clip(new_kind);
    ICONINFO info{};
    info.fIcon = FALSE;
    info.xHotspot = centered ? bitmap.bmWidth / 2 : 0u;
    info.yHotspot = centered ? bitmap.bmHeight / 2 : 0u;
    info.hbmMask = mask.get();
    info.hbmColor = color.get();
    CHardwareCursorCursorOwner replacement(static_cast<HCURSOR>(::CreateIconIndirect(&info)));
    if (!replacement)
        throw std::runtime_error("CreateCursor(): failed to create cursor");
    // Select the new cursor before releasing the old handle borrowed by Win32.
    ::SetCursor(replacement.get());
    cursor_handle = std::move(replacement);
    kind = new_kind;
    texture_width = bitmap.bmWidth;
    texture_height = bitmap.bmHeight;
    show();
}

void CSoftwareCursor::setCursorKind(std::uint32_t new_kind)
{
    auto *state = SphereUIHost::cursor();
    if (state != nullptr)
        state->setKind(new_kind);
    texture_width = 0u;
    texture_height = 0u;
    const auto name = SferaCursorTextureHelper::name(new_kind);
    if (name.empty())
        return;
    const int index = g_sfera_textures.find(name);
    if (index < 0)
        return;
    const auto extent = g_sfera_textures.size(index);
    texture_width = extent.width;
    texture_height = extent.height;
}

std::string_view SferaCursorTextureHelper::name(uint32_t slot)
{
    constexpr std::array<std::string_view, 4> names{"_cursor1", "_cursor2", "cursor2", "cursor1"};
    return slot < names.size() ? names[slot] : std::string_view{};
}

bool SphereUICDescriptionWindow::descriptionAutoPopup()
{
    return g_sfera_interface.description_auto_popup;
}

void SphereUICDescriptionWindow::setDescriptionWindow(SphereUICDescriptionWindow *window)
{
    g_sfera_interface.description_control = window;
}

SphereUICDescriptionWindow::SphereUICDescriptionWindow()
{
    auto *original = g_sfera_interface.templateWindow("objdesc2");
    if (original == nullptr)
        throw std::runtime_error("description template objdesc2 is missing");
    SphereUIWindowCloneContext context;
    SphereUIWindow::initializeCopy(*original, context);
    context.finish();
    displayed_source = pending_source = nullptr;
    show_deadline = hide_deadline = 0u;
    constexpr std::string_view names[] = {"window_caption", "window_bottom", "window_left", "window_right"};
    std::shared_ptr<const SphereUIUiSprite> *sprites[] = {&caption_sprite, &bottom_sprite, &left_sprite, &right_sprite};
    for (std::size_t index = 0u; index < 4u; ++index)
    {
        *sprites[index] = findResource(names[index]);
        if (*sprites[index] == 0u)
            throw std::runtime_error(std::string("description sprite is missing: ") + std::string(names[index]));
    }
    SphereUIWindow *content = nullptr;
    SphereUIDetail::forEachChild(*this, std::bind(&SphereUICDescriptionWindow::selectFirstChild, std::ref(content), std::placeholders::_1));
    if (content == nullptr)
        throw std::runtime_error("description content control is missing");
    frame_height = SphereUIDetail::subtractCoordinate(height, content->height);
    g_sfera_interface.bindEventHandler(this, SphereUIWindowEventHandler::description);
    close();
}

SphereUICDescriptionWindow *SphereUICDescriptionWindow::instance()
{
    if (auto *existing = SphereUIRuntime::descriptionWindow())
        return existing;
    auto window = std::make_unique<SphereUICDescriptionWindow>();
    auto *result = window.get();
    g_sfera_interface.addTopLevelWindow(std::move(window));
    SphereUICDescriptionWindow::setDescriptionWindow(result);
    return result;
}

void SphereUIRuntime::playUiSound(const std::string &filename)
{
    g_sfera_sound_runtime.playUiSound(filename);
}

void SphereUIRuntime::playClickSound()
{
    SphereUIRuntime::playUiSound("Sounds\\in_click.wav");
}

SphereUICDescriptionWindow *SphereUIRuntime::descriptionWindow()
{
    return g_sfera_interface.description_control;
}

std::unique_ptr<SphereUIWindow> SphereUIRuntime::makeControl(SphereUIUiControlKind kind)
{
    switch (kind)
    {
    case SphereUIUiControlKind::window:
        return std::make_unique<SphereUIWindow>();
    case SphereUIUiControlKind::button:
        return std::make_unique<SphereUIButtonCtrl>();
    case SphereUIUiControlKind::text:
        return std::make_unique<SphereUITextCtrl>();
    case SphereUIUiControlKind::image:
        return std::make_unique<SphereUIImageCtrl>();
    case SphereUIUiControlKind::progressBar:
        return std::make_unique<SphereUIProgressBar>();
    case SphereUIUiControlKind::scrollBar:
        return std::make_unique<SphereUIScrollBar>();
    case SphereUIUiControlKind::hyperText:
        return std::make_unique<SphereUIHyperTextCtrl>();
    case SphereUIUiControlKind::checkBox:
        return std::make_unique<SphereUICheckBox>();
    case SphereUIUiControlKind::radioButton:
        return std::make_unique<SphereUIRadioButtonCtrl>();
    case SphereUIUiControlKind::tooltip:
        return std::make_unique<SphereUIToolTipCtrl>();
    case SphereUIUiControlKind::textList:
        return std::make_unique<SphereUIListCtrl>();
    case SphereUIUiControlKind::slider:
        return std::make_unique<SphereUISliderCtrl>();
    case SphereUIUiControlKind::listItem:
        return std::make_unique<SphereUIListItemCtrl>();
    case SphereUIUiControlKind::edit:
        return std::make_unique<SphereUIEditCtrl>();
    case SphereUIUiControlKind::slot:
        return std::make_unique<SphereUISlotCtrl>();
    case SphereUIUiControlKind::spinButton:
        return std::make_unique<SphereUISpinButton>();
    case SphereUIUiControlKind::richEdit:
        return std::make_unique<SphereUIRichEditCtrl>();
    case SphereUIUiControlKind::filteredList:
        return std::make_unique<SphereUIFilterListCtrl>();
    case SphereUIUiControlKind::minimap:
        return std::make_unique<SphereUICMinimapControl>();
    case SphereUIUiControlKind::menu:
        return std::make_unique<SphereUICMenuListControl>();
    case SphereUIUiControlKind::hyperTextChat:
        return std::make_unique<SphereUIHyperTextChatListControl>();
    case SphereUIUiControlKind::hyperTextEdit:
        return std::make_unique<SphereUIHyperTextEditControl>();
    case SphereUIUiControlKind::fontPicker:
        return std::make_unique<SphereUIFontPicker>();
    default:
        return nullptr;
    }
}

void GameInterface::finishLoading()
{
    g_sfera_interface.showLoadingScreen(false, g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height, false);
    ::_chmod("loadcount.bin", _S_IREAD | _S_IWRITE);
    SferaFileManagerScopedFile file(g_sfera_files, g_sfera_files.create("loadcount.bin"));
    if (file.get() < 0)
        return;
    const auto work = GameInterface::loading_completed;
    g_sfera_files.write(file.get(), std::as_bytes(std::span(&work, 1)));
    file.close();
}

void GameInterface::updateLoadingProgress(int increment)
{
    auto &work = GameInterface::loading_completed;
    work += increment;
    const auto total = std::max(GameInterface::loading_total - 80, 1);
    const auto progress = std::min(work * 100 / total, 100);
    if (progress == g_sfera_graphics_runtime.rebuild_percent)
        return;
    g_sfera_graphics_runtime.rebuild_percent = progress;
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    SceneScope scene(device);
    if (!scene)
        return;
    g_sfera_interface.setLoadingProgress(progress);
    g_sfera_interface.update(0, 0, 0, 0);
    drawAll();
    scene.finish();
    device.waitForGpu();
    device.present();
}

void SphereUIScrollBar::playScrollSound(bool page)
{
    SphereUIRuntime::playUiSound(page ? "Sounds\\in_page.wav" : "Sounds\\in_line.wav");
}

void SphereUIHyperTextCtrl::playLinkSound()
{
    SphereUIRuntime::playUiSound("Sounds\\in_link.wav");
}

void SphereUIWindow::playWindowSound(bool opening)
{
    SphereUIRuntime::playUiSound(opening ? "Sounds\\in_winopen.wav" : "Sounds\\in_winclose.wav");
}
