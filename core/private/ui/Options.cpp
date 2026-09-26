#include <windows.h>
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <format>
#include <iterator>
#include <limits>
#include <memory>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "render/CharacterRenderer.h"
#include "application/ClientApplication.h"
#include "audio/GameAudio.h"
#include "compression/Zlib.h"
#include "config/InterfaceConfiguration.h"
#include "effects/EffectManager.h"
#include "graphics/DisplayMode.h"
#include "input/DirectInputDevices.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "render/SceneRenderer.h"
#include "resources/FileResources.h"
#include "script/ConfigText.h"
#include "script/MbcRuntime.h"
#include "shadows/Shadows.h"
#include "text/Text.h"
#include "ui/GameInterfaceManager.h"
#include "ui/UiRuntime.h"
#include "ui/Window.h"
#include "ui/widgets/Controls.h"
#include "ui/widgets/Lists.h"
#include "ui/widgets/Popups.h"
#include "ui/widgets/TextEditors.h"

constexpr std::uint32_t fov_slider_control_id = 0xF001u;

constexpr std::uint32_t fov_label_control_id = 0xF002u;

constexpr std::uint32_t fov_decoration_control_id = 0xF010u;

std::uint32_t SphereUIInterfaceManager::findOptionsMode(const SphereUIDisplayMode &requested)
{
    const auto count = g_sfera_graphics_runtime.d3d_runtime->display_modes.size();
    for (std::size_t index = 0u; index < count; ++index)
    {
        const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index);
        if (mode.width == requested.width && mode.height == requested.height && mode.depth == requested.depth)
            return SferaNumeric::lowWord(index);
    }
    for (std::size_t index = count; index != 0u; --index)
    {
        const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index - 1u);
        if (mode.depth == requested.depth && mode.width <= SferaClientApplication::desktop_width && mode.height <= SferaClientApplication::desktop_height)
            return SferaNumeric::lowWord(index - 1u);
    }
    return SferaNumeric::lowWord(count - 1u);
}

void SphereUIInterfaceManager::setOptionsModeLabel(SphereUIWindow *window, std::uint32_t index)
{
    const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index);
    const auto text = std::to_string(mode.width) + "x" + std::to_string(mode.height) + " " + std::to_string(mode.depth);
    optionText(window, 7u, text);
}

std::string_view SphereUIInterfaceManager::graphicsBooleanLabel(std::uint32_t value)
{
    return value < 2u ? g_sfera_interface.options.labels[5u + value] : g_sfera_interface.options.unknown_graphics_label;
}

void SphereUIInterfaceManager::optionSelection(SphereUIWindow *window, std::uint32_t index, std::uint32_t maximum, std::uint32_t value)
{
    optionMessage(window, index, SphereUIUiMessage::setSpinRange, 0u, maximum);
    optionMessage(window, index, SphereUIUiMessage::setSpinValue, value);
}

void SphereUIInterfaceManager::setupLodOptions(SphereUIWindow *window)
{
    const auto enabled = g_sfera_graphics_runtime.lods_enabled;
    optionToggleLabel(window, 41u, enabled);
    optionSelection(window, 43u, 1u, enabled);
    optionMessage(window, 46u, SphereUIUiMessage::setScrollRange, 0u, enabled ? 14u : 0u);
    if (enabled)
        optionMessage(window, 46u, SphereUIUiMessage::setScrollValue, SferaNumeric::lowWord(SferaNumeric::truncateInt64(g_sfera_graphics_runtime.lod_distance - 12.0)));
}

void SphereUIInterfaceManager::setupFogOptions(SphereUIWindow *window)
{
    const auto automatic = g_sfera_graphics_runtime.auto_fog;
    optionToggleLabel(window, 37u, automatic);
    optionSelection(window, 39u, 1u, automatic);
    optionMessage(window, 28u, SphereUIUiMessage::setScrollRange, 0u, automatic ? 0u : 170u);
    if (!automatic)
        optionMessage(window, 28u, SphereUIUiMessage::setScrollValue, SferaNumeric::lowWord(SferaNumeric::truncateInt64(g_sfera_graphics_runtime.fog_distance - 30.0)));
}

void SphereUIInterfaceManager::updateFovLabel(SphereUIWindow *window)
{
    if (auto *label = optionControl(window, fov_label_control_id))
        label->setText(std::format("FOV: {}", g_sfera_graphics_runtime.field_of_view_degrees));
}

auto SphereUIInterfaceManager::makeNavigationButtonVisible(SphereUIButtonCtrl *button)
{
    if (button == nullptr)
        return;
    button->hidden = false;
    button->disabled = false;
    button->input_enabled = true;
    button->visual_state = 0u;
    if (button->hover_image != nullptr)
        button->idle_image = button->hover_image;
    else if (button->idle_image == nullptr)
        button->idle_image = button->pressed_image;
    if (button->hover_image == nullptr)
        button->hover_image = button->idle_image;
    if (button->pressed_image == nullptr)
        button->pressed_image = button->hover_image;
    if (button->disabled_image == nullptr)
        button->disabled_image = button->idle_image;
}

void SphereUIInterfaceManager::addFovControls(SphereUIWindow *window)
{
    if (window == nullptr || optionControl(window, fov_slider_control_id) != nullptr)
        return;

    auto *scroll_template = optionChild(window, 46u);
    if (scroll_template == nullptr || scroll_template->asScrollBar() == nullptr)
        return;

    auto slider = scroll_template->clone();
    auto *fov_slider = slider->asScrollBar();
    if (fov_slider == nullptr)
        return;
    fov_slider->control_id = fov_slider_control_id;
    fov_slider->step = 1;
    fov_slider->page_step = 5;
    fov_slider->explicit_step = true;
    fov_slider->notify_changes = true;
    fov_slider->hidden = false;
    fov_slider->disabled = false;
    fov_slider->input_enabled = true;

    makeNavigationButtonVisible(fov_slider->decrease_button.get());
    makeNavigationButtonVisible(fov_slider->increase_button.get());

    SphereUIWindow *label_template = nullptr;
    int label_distance = std::numeric_limits<int>::max();
    const int slider_center_y = scroll_template->y + scroll_template->height / 2;
    for (const auto &child : window->children)
    {
        if (child == nullptr || child->control_kind != SphereUIUiControlKind::text || child->x >= scroll_template->x)
            continue;
        const int child_center_y = child->y + child->height / 2;
        const int distance = std::abs(child_center_y - slider_center_y);
        if (distance < label_distance)
        {
            label_distance = distance;
            label_template = child.get();
        }
    }
    if (label_template == nullptr)
        label_template = optionChild(window, 49u);

    std::unique_ptr<SphereUIWindow> label;
    if (label_template != nullptr)
    {
        label = label_template->clone();
    }
    else
    {
        auto fallback = std::make_unique<SphereUITextCtrl>();
        fallback->height = 16;
        fallback->x = std::max(0, fov_slider->x - 90);
        label = std::move(fallback);
    }
    if (label == nullptr)
        return;
    label->control_id = fov_label_control_id;
    label->hidden = false;
    label->disabled = false;
    label->input_enabled = false;
    label->height = std::max(label->height, 16);
    label->width = std::max(60, fov_slider->x - label->x - 4);

    std::vector<std::unique_ptr<SphereUIWindow>> decorations;
    const int template_left = scroll_template->x - 12;
    const int template_right = scroll_template->x + scroll_template->width + 12;
    std::uint32_t decoration_index = 0u;
    for (const auto &child : window->children)
    {
        if (child == nullptr || child.get() == scroll_template || child.get() == label_template)
            continue;
        const bool decorative_kind = child->control_kind == SphereUIUiControlKind::image || (child->control_kind == SphereUIUiControlKind::window && child->resource_reference != nullptr);
        if (!decorative_kind || child->height > scroll_template->height + 12)
            continue;
        const int child_center_y = child->y + child->height / 2;
        if (std::abs(child_center_y - slider_center_y) > std::max(6, scroll_template->height / 2))
            continue;
        if (child->x + child->width < template_left || child->x > template_right)
            continue;

        auto decoration = child->clone();
        if (decoration == nullptr)
            continue;
        decoration->control_id = fov_decoration_control_id + decoration_index++;
        decoration->hidden = false;
        decoration->disabled = false;
        decoration->input_enabled = false;
        decorations.push_back(std::move(decoration));
    }

    auto *primary_button = optionChild(window, 1u);
    auto *secondary_button = optionChild(window, 2u);
    int insertion_y = window->height - 34;
    if (primary_button != nullptr && secondary_button != nullptr)
        insertion_y = std::min(primary_button->y, secondary_button->y);
    else if (primary_button != nullptr)
        insertion_y = primary_button->y;
    else if (secondary_button != nullptr)
        insertion_y = secondary_button->y;

    const int row_height = std::max(label->height, fov_slider->height) + 4;
    int content_bottom = 0;
    for (const auto &child : window->children)
    {
        if (child == nullptr || child.get() == primary_button || child.get() == secondary_button || child->y >= insertion_y)
            continue;
        if (child->control_kind == SphereUIUiControlKind::image || child->control_kind == SphereUIUiControlKind::window)
            continue;
        content_bottom = std::max(content_bottom, child->y + child->height);
    }
    const int available_gap = std::max(0, insertion_y - content_bottom);
    const int layout_shift = std::max(0, row_height - available_gap);
    if (layout_shift != 0)
    {
        for (auto &child : window->children)
        {
            if (child != nullptr && child->y >= insertion_y)
            {
                child->y += layout_shift;
                child->initial_y += layout_shift;
            }
        }
        window->height += layout_shift;
    }
    const int row_y = insertion_y + layout_shift - row_height;

    label->y = row_y + (row_height - label->height) / 2;
    label->initial_x = label->x;
    label->initial_y = label->y;
    fov_slider->y = row_y + (row_height - fov_slider->height) / 2;
    fov_slider->initial_y = fov_slider->y;
    const int decoration_shift_y = fov_slider->y - scroll_template->y;
    for (auto &decoration : decorations)
    {
        decoration->y += decoration_shift_y;
        decoration->initial_y = decoration->y;
        window->appendChild(std::move(decoration));
    }
    fov_slider->handleMessage(SphereUIUiMessage::setScrollRange, 0u, SferaGraphicsRuntime::maximum_field_of_view - SferaGraphicsRuntime::minimum_field_of_view);
    fov_slider->handleMessage(SphereUIUiMessage::setScrollValue, g_sfera_graphics_runtime.field_of_view_degrees - SferaGraphicsRuntime::minimum_field_of_view, 0u);

    window->appendChild(std::move(label));
    window->appendChild(std::move(slider));
    updateFovLabel(window);
}

void SphereUIInterfaceManager::setGraphicsOptionsVisible(bool show)
{
    auto *window = beginOptionsDialog("gfx_options", SphereUIWindowEventHandler::graphics_options, show);
    if (window == nullptr)
        return;
    auto &values = g_sfera_interface.options.edited_graphics;

    auto &graphics = g_sfera_graphics_runtime;
    auto *shadows = g_sfera_shadows.get();
    if (shadows == nullptr)
        throw std::runtime_error("Shadow manager is unavailable");
    if (show)
    {
        g_sfera_interface.options.saved_fog_distance = graphics.fog_distance;
        g_sfera_interface.options.saved_lod_distance = g_sfera_graphics_runtime.lod_distance;
        g_sfera_interface.options.saved_lods_enabled = graphics.lods_enabled;
        g_sfera_interface.options.saved_field_of_view = graphics.field_of_view_degrees;
        values[9] = g_sfera_graphics_runtime.auto_fog;
        values[8] = g_sfera_effect_manager.effects_enabled;
        g_sfera_interface.options.graphics_page = g_sfera_graphics_runtime.reflection_quality;
        constexpr std::string_view label_keys[] = {"UISTR_WT_OPT21", "UISTR_WT_OPT20", "UISTR_WT_OPT19", "UISTR_WT_OPT18", "UISTR_WT_OPT17", "UISTR_WT_OPT17", "UISTR_WT_OPT16"};
        for (std::size_t index = 0u; index < std::size(label_keys); ++index)
            g_sfera_interface.options.labels[index] = g_sfera_interface.localizedText(label_keys[index]);
        g_sfera_interface.options.unknown_graphics_label = g_sfera_interface.localizedText("UISTR_WT_OPT36");
        SphereUIInterfaceConfiguration::open("config.cfg");
        SphereUIDisplayMode mode{SferaNumeric::word(graphics.display_width), SferaNumeric::word(graphics.display_height), g_sfera_graphics_runtime.display_depth_bits};
        mode.width = SphereUIInterfaceConfiguration::readInteger("XRES", mode.width);
        mode.height = SphereUIInterfaceConfiguration::readInteger("YRES", mode.height);
        g_sfera_graphics_runtime.d3d_runtime->enumerateDisplayModes(SferaClientApplication::windowed);
        values[5] = findOptionsMode(mode);
        values[1] = mode.depth;
        values[2] = shadows->quality;
        values[3] = g_sfera_graphics_runtime.grass_depth;
        values[4] = SferaClientApplication::windowed;
        values[6] = graphics.post_effects_enabled;
        values[10] = values[0];
        values[11] = mode.depth;
        g_sfera_interface.options.comparison_graphics_value = values[4];
        optionSelection(window, 15u, SferaNumeric::lowWord(g_sfera_graphics_runtime.d3d_runtime->display_modes.size() - 1u), values[5]);
        optionSelection(window, 17u, 4u, values[2]);
        optionSelection(window, 18u, 2u, values[3]);
        optionMessage(window, 26u, SphereUIUiMessage::setSpinRange, 0u, 1u);
        optionToggleLabel(window, 31u, !g_sfera_effect_manager.effects_enabled);
        optionMessage(window, 26u, SphereUIUiMessage::setSpinValue, !g_sfera_effect_manager.effects_enabled);
        setupLodOptions(window);
        setOptionsModeLabel(window, values[5]);
        optionText(window, 9u, g_sfera_interface.options.labels[values[2]]);
        optionText(window, 10u, graphicsBooleanLabel(values[3]));
        setupFogOptions(window);
        optionSelection(window, 24u, 3u, g_sfera_graphics_runtime.reflection_quality);
        optionText(window, 22u, g_sfera_interface.options.labels[4u - g_sfera_graphics_runtime.reflection_quality]);
        optionMessage(window, 34u, SphereUIUiMessage::setSpinRange, 0u, 1u);
        optionLabel(window, 35u, values[4] != 0u ? "UISTR_WT_OPT61" : "UISTR_WT_OPT62");
        optionMessage(window, 34u, SphereUIUiMessage::setSpinValue, values[4] == 0u);
        const auto *features = graphics.d3d_runtime.get();
        const bool post_supported = features != nullptr && features->supports_post_effects;
        if (!post_supported)
            values[6] = g_sfera_interface.options.saved_graphics[6] = graphics.post_effects_enabled = false;
        optionSelection(window, 51u, post_supported ? 1u : 0u, values[6]);
        optionText(window, 49u, graphicsBooleanLabel(values[6]));
        std::copy_n(values, 7u, g_sfera_interface.options.saved_graphics);
        addFovControls(window);
        return;
    }
    setOptionsVisible(true);
    shadows->quality = SferaNumeric::lowByte(values[2]);
    g_sfera_graphics_runtime.grass_depth = values[3];
    SferaClientApplication::windowed = values[4];
    SphereUIInterfaceConfiguration::open("config.cfg");
    const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(values[5]);
    const std::pair<std::string_view, std::uint32_t> settings[] = {{"XRES", mode.width},
                                                                   {"YRES", mode.height},
                                                                   {"DEPTH", mode.depth},
                                                                   {"GRASS", values[3]},
                                                                   {"WINDOWED", values[4]},
                                                                   {"SHAD", values[2]},
                                                                   {"AUTOFOG", g_sfera_graphics_runtime.auto_fog},
                                                                   {"FOGDIST", SferaNumeric::word(SferaNumeric::truncateInt(graphics.fog_distance))},
                                                                   {"REFLQUAL", g_sfera_graphics_runtime.reflection_quality},
                                                                   {"EFFECTS", g_sfera_effect_manager.effects_enabled},
                                                                   {"LODS", graphics.lods_enabled},
                                                                   {"LOD_DISTANCE", SferaNumeric::word(SferaNumeric::truncateInt(g_sfera_graphics_runtime.minimum_lod_distance))},
                                                                   {"MIN_LOD_DIST", SferaNumeric::word(SferaNumeric::truncateInt(g_sfera_graphics_runtime.lod_distance))},
                                                                   {"POSTEFFECTS", values[6]},
                                                                   {"FOV", graphics.field_of_view_degrees}};
    for (const auto &setting : settings)
        SphereUIInterfaceConfiguration::writeInteger(setting.first, setting.second);

    SphereUIInterfaceConfiguration::save();
    if (values[10] != values[0] || values[11] != values[1] || g_sfera_interface.options.comparison_graphics_value != values[4])
        SferaClientApplication::quit_requested = true;
}

void SphereUIInterfaceManager::handleGraphicsOptionsEvent(SphereUIWindow *window, const SphereUIWindowEvent &event)
{
    auto &values = g_sfera_interface.options.edited_graphics;
    auto &graphics = g_sfera_graphics_runtime;
    if (event.message == SphereUIUiMessage::close)
    {
        setGraphicsOptionsVisible(false);
        return;
    }
    if (event.message == SphereUIUiMessage::leftClick)
    {
        if (event.control_id == 1u)
        {
            std::copy_n(g_sfera_interface.options.saved_graphics, 7u, values);
            auto *lod = SphereRenderSceneRenderer::characters.get();
            if (lod != nullptr)
                lod->setDistances(g_sfera_graphics_runtime.lod_distance, g_sfera_graphics_runtime.minimum_lod_distance);
            setGraphicsOptionsVisible(false);
        }
        else if (event.control_id == 2u)
        {
            graphics.field_of_view_degrees = g_sfera_interface.options.saved_field_of_view;
            setGraphicsOptionsVisible(false);
            graphics.fog_distance = g_sfera_interface.options.saved_fog_distance;
            g_sfera_graphics_runtime.lod_distance = g_sfera_interface.options.saved_lod_distance;
            g_sfera_graphics_runtime.auto_fog = values[9];
            g_sfera_effect_manager.effects_enabled = values[8];
            graphics.lods_enabled = g_sfera_interface.options.saved_lods_enabled;
            g_sfera_graphics_runtime.reflection_quality = g_sfera_interface.options.graphics_page;
        }
        return;
    }
    if (event.message == SphereUIUiMessage::spinValueChanged)
        switch (event.control_id)
        {
        case 15u:
            g_sfera_interface.options.saved_graphics[5] = event.first;
            setOptionsModeLabel(window, event.first);
            break;
        case 17u:
        {
            g_sfera_interface.options.saved_graphics[2] = event.first;
            auto *shadows = g_sfera_shadows.get();
            if (shadows != nullptr)
                shadows->quality = SferaNumeric::lowByte(event.first);
            optionText(window, 9u, g_sfera_interface.options.labels[event.first]);
            break;
        }
        case 18u:
            g_sfera_interface.options.saved_graphics[3] = event.first;
            g_sfera_graphics_runtime.grass_depth = event.first;
            optionText(window, 10u, graphicsBooleanLabel(event.first));
            break;
        case 24u:
            g_sfera_graphics_runtime.reflection_quality = event.first;
            optionText(window, 22u, g_sfera_interface.options.labels[4u - event.first]);
            break;
        case 26u:
            g_sfera_effect_manager.effects_enabled = event.first == 0u;
            optionText(window, 31u, event.first < 2u ? "" : graphicsBooleanLabel(event.first));
            break;
        case 34u:
        {
            g_sfera_interface.options.saved_graphics[4] = event.first != 1u;
            optionLabel(window, 35u, g_sfera_interface.options.saved_graphics[4] == 1u ? "UISTR_WT_OPT61" : "UISTR_WT_OPT62");
            const auto selected = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(g_sfera_interface.options.saved_graphics[5]);
            g_sfera_graphics_runtime.d3d_runtime->enumerateDisplayModes(g_sfera_interface.options.saved_graphics[4] == 1u);
            g_sfera_interface.options.saved_graphics[5] = findOptionsMode(selected);
            optionSelection(window, 15u, SferaNumeric::lowWord(g_sfera_graphics_runtime.d3d_runtime->display_modes.size() - 1u), g_sfera_interface.options.saved_graphics[5]);
            setOptionsModeLabel(window, g_sfera_interface.options.saved_graphics[5]);
            g_sfera_interface.options.saved_graphics[0] = 0u;
            break;
        }
        case 39u:
        {
            const bool automatic = event.first == 1u;
            optionToggleLabel(window, 37u, automatic);
            optionMessage(window, 28u, SphereUIUiMessage::setScrollRange, 0u, automatic ? 0u : 170u);
            if (automatic)
                graphics.saved_fog_distance = graphics.fog_distance;
            else
            {
                graphics.fog_distance = graphics.saved_fog_distance;
                optionMessage(window, 28u, SphereUIUiMessage::setScrollValue, SferaNumeric::lowWord(SferaNumeric::truncateInt64(graphics.fog_distance - 30.0)));
            }
            g_sfera_graphics_runtime.auto_fog = automatic;
            break;
        }
        case 43u:
        {
            const bool enabled = event.first == 1u;
            optionText(window, 41u, enabled ? g_sfera_interface.options.labels[6] : "");
            optionMessage(window, 46u, SphereUIUiMessage::setScrollRange, 0u, enabled ? 14u : 0u);
            if (enabled)
                optionMessage(window, 46u, SphereUIUiMessage::setScrollValue, SferaNumeric::lowWord(SferaNumeric::truncateInt64(g_sfera_graphics_runtime.lod_distance - 12.0)));
            graphics.lods_enabled = enabled;
            break;
        }
        case 51u:
            g_sfera_interface.options.saved_graphics[6] = event.first;
            graphics.post_effects_enabled = event.first;
            optionText(window, 49u, event.first < 2u ? "" : graphicsBooleanLabel(event.first));
            break;
        default:
            break;
        }
    else if (event.message != SphereUIUiMessage::horizontalScroll && event.message != SphereUIUiMessage::sliderValueChanged)
        return;
    if (event.control_id == fov_slider_control_id)
    {
        const auto requested = SferaGraphicsRuntime::minimum_field_of_view + event.first;
        graphics.field_of_view_degrees = std::clamp(requested, SferaGraphicsRuntime::minimum_field_of_view, SferaGraphicsRuntime::maximum_field_of_view);
        updateFovLabel(window);
        return;
    }
    if (event.message != SphereUIUiMessage::horizontalScroll)
        return;
    if (event.control_id == 28u)
        graphics.fog_distance = SferaNumeric::real32(event.first + 30.0);
    else if (event.control_id == 46u)
        g_sfera_graphics_runtime.lod_distance = SferaNumeric::real32(event.first + 12.0);
}

void SphereUIInterfaceManager::showOptions(bool visible)
{
    auto *window = findWindow("options");
    if (visible && window == nullptr)
    {
        window = openWindow("options", 0, 0, 0u);
        if (window != nullptr)
            bindEventHandler(window, SphereUIWindowEventHandler::options);
    }
    else if (!visible && window != nullptr)
        closeWindow(window, true);
}

void SphereUIInterfaceManager::queueInterfaceRefresh()
{
    g_sfera_interface.queueEvent({nullptr, 0u, SphereUIUiMessage::refreshInterface, 0u, 0u});
}

SphereUIWindow *SphereUIInterfaceManager::optionChild(SphereUIWindow *window, std::uint32_t index)
{
    return window == nullptr ? nullptr : window->controlAt(index);
}

SphereUIWindow *SphereUIInterfaceManager::optionControl(SphereUIWindow *window, std::uint32_t control_id)
{
    if (window == nullptr)
        return nullptr;
    for (const auto &child : window->children)
    {
        if (child != nullptr && child->control_id == control_id)
            return child.get();
    }
    return nullptr;
}

void SphereUIInterfaceManager::optionMessage(SphereUIWindow *window, std::uint32_t index, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    if (auto *child = optionChild(window, index))
        child->handleMessage(message, first, second);
}

void SphereUIInterfaceManager::optionText(SphereUIWindow *window, std::uint32_t index, std::string_view text)
{
    if (auto *child = optionChild(window, index))
        child->setText(text);
}

void SphereUIInterfaceManager::optionLabel(SphereUIWindow *window, std::uint32_t index, std::string_view key)
{
    optionText(window, index, g_sfera_interface.localizedText(key));
}

void SphereUIInterfaceManager::optionToggleLabel(SphereUIWindow *window, std::uint32_t index, std::uint32_t value)
{
    optionLabel(window, index, value != 0u ? "UISTR_WT_OPT16" : "UISTR_WT_OPT17");
}

SphereUIWindow *SphereUIInterfaceManager::beginOptionsDialog(std::string_view name, SphereUIWindowEventHandler handler, bool show)
{
    auto *window = g_sfera_interface.findWindow(name);
    if (!show)
    {
        if (window != nullptr)
        {
            g_sfera_interface.closeWindow(window);
        }
        return window;
    }
    if (window != nullptr)
        return nullptr;
    setOptionsVisible(false);
    window = g_sfera_interface.openWindow(name);
    if (window != nullptr)
        g_sfera_interface.bindEventHandler(window, handler);
    return window;
}

void SphereUIInterfaceManager::setOptionsVisible(bool show)
{
    auto *window = g_sfera_interface.findWindow("options");
    if (show)
    {
        if (window == nullptr)
            if (auto *created = g_sfera_interface.openWindow("options"))
                g_sfera_interface.bindEventHandler(created, SphereUIWindowEventHandler::options);
    }
    else if (window != nullptr)
        g_sfera_interface.closeWindow(window);
}

void SphereUIInterfaceManager::handleHelpEvent(SphereUIWindow *window, const SphereUIWindowEvent &event)
{
    if (event.message == SphereUIUiMessage::close)
    {
        g_sfera_interface.showHelpPage(std::nullopt);
        return;
    }
    if (event.message == SphereUIUiMessage::leftClick)
    {
        if (event.control_id == 1u)
            g_sfera_interface.showHelpPage("Language\\helpindex.hts");
        else if (event.control_id == 2u)
            optionMessage(window, 3u, SphereUIUiMessage::previousHyperTextPage);
        return;
    }
    if (event.message != SphereUIUiMessage::hyperTextPageChanged)
        return;
    auto *control = event.source != nullptr ? event.source->asHyperTextCtrl() : nullptr;
    if (control == nullptr)
        return;
    const auto *document = control->document.get();
    if (document != nullptr && SferaText::asciiEqual(document->name, "Language\\helpindex.hts"))
        control->handleMessage(SphereUIUiMessage::clearHyperTextHistory, 0u, 0u);
    optionMessage(window, 2u, SphereUIUiMessage::setEnabled, control->history.size() == 0u ? 0u : 1u);
}

void SphereUIInterfaceManager::invokeEventHandler(SphereUIWindowEventHandler handler, SphereUIWindow *window, const SphereUIWindowEvent &event)
{
    switch (handler)
    {
    case SphereUIWindowEventHandler::none:
        return;
    case SphereUIWindowEventHandler::description:
        if (auto *description = window != nullptr ? window->asDescriptionWindow() : nullptr)
            description->handleEvent(event);
        return;
    case SphereUIWindowEventHandler::help:
        handleHelpEvent(window, event);
        return;
    case SphereUIWindowEventHandler::authors:
        if (event.message == SphereUIUiMessage::close && beginOptionsDialog("authors", handler, false) != nullptr)
            setOptionsVisible(true);
        return;
    case SphereUIWindowEventHandler::quit:
        if (event.message == SphereUIUiMessage::leftClick && event.control_id == 1u)
            SferaClientApplication::quit_requested = true;
        else if (event.message == SphereUIUiMessage::close && beginOptionsDialog("quit", handler, false) != nullptr)
            setOptionsVisible(true);
        return;
    case SphereUIWindowEventHandler::sound_options:
        handleSoundOptionsEvent(window, event);
        return;
    case SphereUIWindowEventHandler::control_options:
        handleControlOptionsEvent(window, event);
        return;
    case SphereUIWindowEventHandler::interface_options:
        handleInterfaceOptionsEvent(window, event);
        return;
    case SphereUIWindowEventHandler::graphics_options:
        handleGraphicsOptionsEvent(window, event);
        return;
    case SphereUIWindowEventHandler::font_options:
        handleFontOptionsEvent(event);
        return;
    case SphereUIWindowEventHandler::options:
        if (event.message == SphereUIUiMessage::close)
            setOptionsVisible(false);
        else if (event.message == SphereUIUiMessage::leftClick)
            switch (event.control_id)
            {
            case 3u:
                setGraphicsOptionsVisible(true);
                break;
            case 4u:
                setSoundOptionsVisible(true);
                break;
            case 5u:
                setControlOptionsVisible(true);
                break;
            case 6u:
                setInterfaceOptionsVisible(true);
                break;
            case 7u:
                beginOptionsDialog("authors", SphereUIWindowEventHandler::authors, true);
                break;
            case 8u:
                beginOptionsDialog("quit", SphereUIWindowEventHandler::quit, true);
                break;
            default:
                break;
            }
        return;
    }
}

// Options transactions and application commands.

constexpr std::uint32_t interfaceControlIds[] = {7u, 8u, 9u, 11u, 12u, 15u, 16u, 19u, 21u};

constexpr std::string_view interfaceSettingKeys[] = {"ISSN", "ISAD", "INSN", "INAW", "IAPM", "MBST", "BALR"};

void SphereUIInterfaceManager::setSoundOptionsVisible(bool show)
{
    auto *window = beginOptionsDialog("sound_options", SphereUIWindowEventHandler::sound_options, show);
    if (window == nullptr)
        return;
    auto &saved_music = g_sfera_interface.options.saved_music_volume;
    auto &saved_sound = g_sfera_interface.options.saved_sound_volume;
    auto &values = g_sfera_interface.options.edited_graphics;
    if (show)
    {
        saved_music = g_sfera_sound_runtime.musicVolume();
        saved_sound = g_sfera_sound_runtime.soundVolume();
        optionMessage(window, 7u, SphereUIUiMessage::setScrollRange, 0u, 100u);
        optionMessage(window, 8u, SphereUIUiMessage::setScrollRange, 0u, 100u);
        optionMessage(window, 7u, SphereUIUiMessage::setScrollValue, saved_music);
        optionMessage(window, 8u, SphereUIUiMessage::setScrollValue, saved_sound);
        values[7] = g_sfera_sound_runtime.hardwareMixing();
        values[12] = values[7];
        optionLabel(window, 9u, values[12] != 0u ? "UISTR_WT_OPT34" : "UISTR_WT_OPT33");
        return;
    }
    g_sfera_sound_runtime.setMusicVolume(saved_music);
    g_sfera_sound_runtime.setSoundVolume(saved_sound);
    setOptionsVisible(true);
    g_sfera_sound_runtime.setHardwareMixing(values[7] != 0u);
    SphereUIInterfaceConfiguration::open("config.cfg");
    SphereUIInterfaceConfiguration::writeInteger("SNDVOL", saved_sound);
    SphereUIInterfaceConfiguration::writeInteger("MUSVOL", saved_music);
    SphereUIInterfaceConfiguration::writeInteger("HWMIX", values[7]);
    SphereUIInterfaceConfiguration::save();
}

std::uint32_t SphereUIInterfaceManager::bindingCount()
{
    const auto count = g_sfera_mbc_runtime.namedValue("SSKS_NUMBER");
    if (count > 63u)
        throw std::out_of_range("Options: at most 63 key bindings are supported");
    return count;
}

std::string_view SphereUIInterfaceManager::bindingName(std::uint32_t key)
{
    const auto name = SphereUIRuntime::keyName(key);
    return name.empty() ? "???" : name;
}

SphereUIWindow *SphereUIInterfaceManager::bindingRow(SphereUIWindow *window, std::uint32_t slot)
{
    auto *list = optionChild(window, 5u);
    return list == nullptr ? nullptr : list->asListItemCtrl() != nullptr ? list->asListItemCtrl()->itemAt(slot) : nullptr;
}

void SphereUIInterfaceManager::refreshBindingLabel(SphereUIWindow *window, std::uint32_t slot)
{
    optionText(bindingRow(window, slot), 3u, bindingName(g_sfera_interface.options.edited_bindings[slot]));
}

void SphereUIInterfaceManager::refreshMouseBindingLabel(SphereUIWindow *window)
{
    optionLabel(window, 4u, g_sfera_interface.options.dialog_kind == 0u ? "UISTR_WT_OPT23" : "UISTR_WT_OPT24");
}

bool SphereUIInterfaceManager::availableBinding(std::uint32_t key)
{
    const auto count = bindingCount();
    for (std::size_t slot = 0u; slot < count; ++slot)
        if (g_sfera_interface.options.edited_bindings[slot] == key)
            return false;
    return key != 0u && key != VK_ESCAPE && key != VK_F1 && key != VK_RETURN && key - '0' > 9u && key != VK_SHIFT && key != VK_CONTROL && key - VK_LEFT > 3u;
}

void SphereUIInterfaceManager::setControlOptionsVisible(bool show)
{
    auto *window = beginOptionsDialog("control_options", SphereUIWindowEventHandler::control_options, show);
    if (window == nullptr)
        return;

    const auto count = bindingCount();
    if (show)
    {
        std::fill(std::begin(g_sfera_direct_input_runtime.key_bindings), std::end(g_sfera_direct_input_runtime.key_bindings), 0u);
        for (std::size_t slot = 0u; slot < std::max(5u, count); ++slot)
        {
            const auto key = g_sfera_mbc_runtime.namedValue("SSKS", SferaNumeric::signedWord(SferaNumeric::lowWord(slot)));
            g_sfera_direct_input_runtime.key_bindings[slot] = slot < 5u ? SphereUIRuntime::virtualKey(key) : key;
        }
        g_sfera_direct_input_runtime.key_bindings[63] = g_sfera_mbc_runtime.namedValue("INMS");
        std::copy(std::begin(g_sfera_direct_input_runtime.key_bindings), std::end(g_sfera_direct_input_runtime.key_bindings), std::begin(g_sfera_interface.options.edited_bindings));
        optionLabel(window, 4u, g_sfera_direct_input_runtime.key_bindings[63] == 0u ? "UISTR_WT_OPT23" : "UISTR_WT_OPT24");
        for (std::size_t slot = 0u; slot < count; ++slot)
        {
            optionMessage(window, 5u, SphereUIUiMessage::appendListItem);
            g_sfera_interface.options.binding_key_name = std::string("UISTR_WT_KEY") + (slot < 9u ? "0" : "") + std::to_string(slot + 1u);
            optionLabel(bindingRow(window, SferaNumeric::lowWord(slot)), 2u, g_sfera_interface.options.binding_key_name);
            refreshBindingLabel(window, SferaNumeric::lowWord(slot));
        }
        g_sfera_interface.options.binding_dialog_open = true;
        return;
    }
    setOptionsVisible(true);
    g_sfera_mbc_runtime.setNamedValue("INMS", g_sfera_direct_input_runtime.key_bindings[63]);
    for (std::size_t slot = 0u; slot < std::max(5u, count); ++slot)
        g_sfera_mbc_runtime.setNamedValue("SSKS", slot < 5u ? SphereUIRuntime::scanCode(g_sfera_direct_input_runtime.key_bindings[slot]) : g_sfera_direct_input_runtime.key_bindings[slot],
                                          SferaNumeric::signedWord(SferaNumeric::lowWord(slot)));
    queueInterfaceRefresh();
    g_sfera_interface.options.binding_dialog_open = false;
}

void SphereUIInterfaceManager::setInterfaceOptionsVisible(bool show)
{
    auto *window = beginOptionsDialog("interface_options", SphereUIWindowEventHandler::interface_options, show);
    if (window == nullptr)
        return;

    if (show)
    {
        for (std::size_t index = 0u; index < 5u; ++index)
            g_sfera_interface.options.saved_interface[index] = index == 2u ? g_sfera_interface.sounds_enabled : g_sfera_mbc_runtime.namedValue(interfaceSettingKeys[index]);
        SphereUIInterfaceConfiguration::open("config.cfg");
        g_sfera_interface.options.saved_interface[5] = SphereUIInterfaceConfiguration::readInteger("MBST", g_sfera_interface.options.saved_interface[5]);
        g_sfera_interface.options.saved_interface[6] = UINT32_MAX;
        g_sfera_interface.options.saved_interface[6] = SphereUIInterfaceConfiguration::readInteger("BALR", g_sfera_interface.options.saved_interface[6]);
        if (SferaNumeric::signedWord(g_sfera_interface.options.saved_interface[6]) < 0)
        {
            g_sfera_interface.options.saved_interface[6] = 1u;
            SphereUIInterfaceConfiguration::writeInteger("BALR", 1u);
            SphereUIInterfaceConfiguration::save();
        }
        g_sfera_interface.options.saved_interface[7] = g_sfera_interface.description_auto_popup;
        g_sfera_interface.options.saved_interface[8] = g_sfera_interface.invite_messages;
        std::copy(std::begin(g_sfera_interface.options.saved_interface), std::end(g_sfera_interface.options.saved_interface), std::begin(g_sfera_interface.options.edited_interface));
        for (std::size_t index = 0u; index < std::size(interfaceControlIds); ++index)
            optionToggleLabel(window, interfaceControlIds[index], g_sfera_interface.options.edited_interface[index]);
        return;
    }
    setOptionsVisible(true);
    for (std::size_t index = 0u; index < std::size(interfaceSettingKeys); ++index)
        g_sfera_mbc_runtime.setNamedValue(interfaceSettingKeys[index], g_sfera_interface.options.saved_interface[index]);
    g_sfera_interface.description_auto_popup = g_sfera_interface.options.saved_interface[7];
    g_sfera_interface.invite_messages = g_sfera_interface.options.saved_interface[8];
    SphereUIInterfaceConfiguration::open("config.cfg");
    SphereUIInterfaceConfiguration::writeInteger("MBST", g_sfera_interface.options.saved_interface[5]);
    SphereUIInterfaceConfiguration::writeInteger("BALR", g_sfera_interface.options.saved_interface[6]);
    SphereUIInterfaceConfiguration::writeInteger("HARDWARE_CURSOR", g_sfera_graphics_runtime.hardware_cursor_enabled);
    SphereUIInterfaceConfiguration::writeInteger("DESCR_AUTO_POPUP", g_sfera_interface.description_auto_popup);
    SphereUIInterfaceConfiguration::writeInteger("INVITE_MESSAGES", g_sfera_interface.invite_messages);
    SphereUIInterfaceConfiguration::save();
    g_sfera_interface.sounds_enabled = g_sfera_interface.options.saved_interface[2];
    queueInterfaceRefresh();
    g_sfera_interface.cross_enabled = g_sfera_interface.options.saved_interface[3];
}

void SphereUIInterfaceManager::resetSavedWindowPositions()
{
    g_sfera_interface.saved_positions.clear();
    for (const auto &window : g_sfera_interface.windows)
        if (window != nullptr && window->save_last_position)
            window->alignToScreen(true);
}

std::vector<std::uint32_t> &SphereUIInterfaceManager::savedChatFonts()
{
    return g_sfera_interface.options.saved_chat_fonts;
}

std::vector<std::uint32_t> &SphereUIInterfaceManager::editedChatFonts()
{
    return g_sfera_interface.options.edited_chat_fonts;
}

void SphereUIInterfaceManager::setFontOptionsVisible(bool show)
{
    auto *window = g_sfera_interface.findWindow("font_options");
    if (show)
    {
        if (window != nullptr)
            return;
        setInterfaceOptionsVisible(false);
        setOptionsVisible(false);
        window = g_sfera_interface.openWindow("font_options");
        if (window == nullptr)
            return;
        g_sfera_interface.bindEventHandler(window, SphereUIWindowEventHandler::font_options);
        auto &saved = savedChatFonts();
        auto &edited = editedChatFonts();
        saved.reserve(2u);
        edited.reserve(2u);
        saved.push_back(4u);
        saved.push_back(4u);
        SphereUIInterfaceConfiguration::open("config.cfg");
        saved.at(0u) = SphereUIInterfaceConfiguration::readInteger("CHAT_LIST_FONT", saved.at(0u));
        saved.at(1u) = SphereUIInterfaceConfiguration::readInteger("CHAT_EDIT_FONT", saved.at(1u));
        for (std::size_t index = 0u; index < 2u; ++index)
        {
            if (auto *control = optionChild(window, SferaNumeric::lowWord(index + 3u)))
                control->setFont(saved.at(index));
        }
        edited = saved;
        return;
    }
    if (window == nullptr)
        return;
    g_sfera_interface.closeWindow(window);
    setInterfaceOptionsVisible(true);
    SphereUIInterfaceConfiguration::open("config.cfg");
    SphereUIInterfaceConfiguration::writeInteger("CHAT_LIST_FONT", savedChatFonts().at(0u));
    SphereUIInterfaceConfiguration::writeInteger("CHAT_EDIT_FONT", savedChatFonts().at(1u));
    SphereUIInterfaceConfiguration::save();
    queueInterfaceRefresh();
}

void SphereUIInterfaceManager::handleSoundOptionsEvent(SphereUIWindow *window, const SphereUIWindowEvent &event)
{
    if (event.message == SphereUIUiMessage::horizontalScroll)
    {
        if (event.control_id == 7u)
            g_sfera_sound_runtime.setMusicVolume(event.first);
        else
            g_sfera_sound_runtime.setSoundVolume(event.first);
        return;
    }
    if (event.message == SphereUIUiMessage::close)
    {
        setSoundOptionsVisible(false);
        return;
    }
    if (event.message != SphereUIUiMessage::leftClick)
        return;
    if (event.control_id == 1u)
    {
        if (const auto *music = optionChild(window, 7u)->asScrollBar())
            g_sfera_interface.options.saved_music_volume = music->current;
        if (const auto *sound = optionChild(window, 8u)->asScrollBar())
            g_sfera_interface.options.saved_sound_volume = sound->current;
        g_sfera_interface.options.edited_graphics[7] = g_sfera_interface.options.edited_graphics[12];
    }
    if (event.control_id == 1u || event.control_id == 2u)
        setSoundOptionsVisible(false);
    else if (event.control_id == 9u)
    {
        auto &mixing = g_sfera_interface.options.edited_graphics[12];
        mixing = mixing == 0u;
        optionLabel(window, 9u, mixing != 0u ? "UISTR_WT_OPT34" : "UISTR_WT_OPT33");
    }
}

void SphereUIInterfaceManager::handleControlOptionsEvent(SphereUIWindow *window, const SphereUIWindowEvent &event)
{
    if (event.message == SphereUIUiMessage::close)
    {
        setControlOptionsVisible(false);
        return;
    }
    if (event.message == SphereUIUiMessage::controlBindingCaptured)
    {
        if (g_sfera_interface.options.binding_slot == UINT32_MAX)
            return;
        g_sfera_direct_input_runtime.binding_capture = 0u;
        g_sfera_interface.capture_control_binding = false;
        g_sfera_direct_input_runtime.binding_key = 0u;
        auto *current = g_sfera_interface.findWindow("control_options");
        if (current == nullptr)
            return;
        if (availableBinding(event.first))
            g_sfera_interface.options.edited_bindings[g_sfera_interface.options.binding_slot] = event.first;
        refreshBindingLabel(current, g_sfera_interface.options.binding_slot);
        return;
    }
    if (event.message == SphereUIUiMessage::listItemEvent && SferaNumeric::enumFromBits<SphereUIUiMessage>(SferaNumeric::lowHalf(event.first)) == SphereUIUiMessage::leftClick &&
        HIWORD(event.second) == 3u)
    {
        g_sfera_interface.options.binding_slot = LOWORD(event.second);
        optionText(bindingRow(window, g_sfera_interface.options.binding_slot), 3u, "");
        g_sfera_direct_input_runtime.binding_capture = 1u;
        g_sfera_interface.capture_control_binding = true;
        g_sfera_direct_input_runtime.binding_key = 0u;
        return;
    }
    if (event.message != SphereUIUiMessage::leftClick)
        return;
    if (event.control_id == 1u)
        std::copy(std::begin(g_sfera_interface.options.edited_bindings), std::end(g_sfera_interface.options.edited_bindings), std::begin(g_sfera_direct_input_runtime.key_bindings));
    if (event.control_id == 1u || event.control_id == 2u)
    {
        setControlOptionsVisible(false);
        return;
    }
    if (event.control_id == 4u)
    {
        auto &mode = g_sfera_interface.options.dialog_kind;
        mode = mode == 0u;
        refreshMouseBindingLabel(window);
    }
    else if (event.control_id == 6u)
    {
        constexpr std::uint32_t defaults[] = {'W', 'S', 'A', 'D', VK_SPACE, VK_OEM_3, VK_OEM_MINUS, VK_TAB, 'R', 'I', 'K', 'H', 'T', 'N', 'P', 'M', 'J', 'O', 'Y', VK_OEM_2};
        g_sfera_interface.options.dialog_kind = 0u;
        std::copy(std::begin(defaults), std::end(defaults), std::begin(g_sfera_interface.options.edited_bindings));
        optionLabel(window, 4u, g_sfera_direct_input_runtime.key_bindings[63] == 0u ? "UISTR_WT_OPT23" : "UISTR_WT_OPT24");
        for (std::size_t slot = 0u, count = bindingCount(); slot < count; ++slot)
            refreshBindingLabel(window, SferaNumeric::lowWord(slot));
    }
}

void SphereUIInterfaceManager::handleInterfaceOptionsEvent(SphereUIWindow *window, const SphereUIWindowEvent &event)
{
    if (event.message == SphereUIUiMessage::close)
    {
        setInterfaceOptionsVisible(false);
        return;
    }
    if (event.message != SphereUIUiMessage::leftClick)
        return;
    if (event.control_id == 1u)
        std::copy(std::begin(g_sfera_interface.options.edited_interface), std::end(g_sfera_interface.options.edited_interface), std::begin(g_sfera_interface.options.saved_interface));
    if (event.control_id == 1u || event.control_id == 2u)
    {
        setInterfaceOptionsVisible(false);
        return;
    }
    if (event.control_id == 6u)
    {
        resetSavedWindowPositions();
        return;
    }
    if (event.control_id == 22u)
    {
        setFontOptionsVisible(true);
        return;
    }
    for (std::size_t index = 0u; index < std::size(interfaceControlIds); ++index)
        if (event.control_id == interfaceControlIds[index])
        {
            auto &value = g_sfera_interface.options.edited_interface[index];
            value = value == 0u;
            if (index == 0u)
                g_sfera_mbc_runtime.setNamedValue(interfaceSettingKeys[index], value);
            if (index == 3u)
                g_sfera_interface.cross_enabled = value;
            optionToggleLabel(window, interfaceControlIds[index], value);
            if (index == 2u)
                g_sfera_interface.sounds_enabled = value;
            else if (index != 3u)
            {
                if (index != 0u && index < std::size(interfaceSettingKeys))
                    g_sfera_mbc_runtime.setNamedValue(interfaceSettingKeys[index], value);
                queueInterfaceRefresh();
            }
            return;
        }
}

void SphereUIInterfaceManager::handleFontOptionsEvent(const SphereUIWindowEvent &event)
{
    if (event.message == SphereUIUiMessage::selectedFontChanged)
    {
        if (event.control_id == 3u || event.control_id == 4u)
            editedChatFonts().at(event.control_id - 3u) = event.first;
        return;
    }
    if (event.message == SphereUIUiMessage::leftClick)
    {
        if (event.control_id == 1u)
            savedChatFonts() = editedChatFonts();
        else if (event.control_id != 2u)
            return;
    }
    else if (event.message != SphereUIUiMessage::close)
        return;
    setFontOptionsVisible(false);
}

std::optional<std::string_view> SphereUIInterfaceConfiguration::value(std::string_view key)
{
    const auto offset = SferaText::configValueOffset(text_, key);
    if (offset == std::string::npos)
        return std::nullopt;
    return std::string_view(text_).substr(offset);
}

void SphereUIInterfaceConfiguration::open(const std::string &filename)
{
    close();
    if (filename.empty())
        return;
    filename_ = filename;
    auto bytes = SferaFileManager::readBounded(filename_, SferaConfigTextRuntime::text_capacity);
    if (!bytes || bytes->empty())
        return;
    try
    {
        if (bytes->size() >= 14 && std::memcmp(bytes->data(), "SPHR", 4) == 0)
        {
            const auto key = (*bytes)[8];
            for (const auto offset : {9u, 17u, 20u})
                if (offset < bytes->size())
                    (*bytes)[offset] ^= key;
            auto decoded = SferaZStream32::decompressUiConfig(std::span<const std::uint8_t>(*bytes).subspan(8), SferaConfigTextRuntime::text_capacity - 1);
            text_.assign(SferaText::fromBytes(decoded));
        }
        else
            text_.assign(SferaText::fromBytes(*bytes));
    }
    catch (const std::exception &)
    {
        close();
    }
}

int SphereUIInterfaceConfiguration::readInteger(std::string_view key, int fallback)
{
    const auto text = value(key);
    int result = fallback;
    return text && SferaText::readNumber(*text, result) ? result : fallback;
}

void SphereUIInterfaceConfiguration::writeInteger(std::string_view key, int value)
{
    if (!SferaText::replaceConfigValue(text_, key, std::to_string(value), false, SferaConfigTextRuntime::text_capacity))
        throw std::length_error("UI configuration too large");
}

void SphereUIInterfaceConfiguration::save()
{
    if (!filename_.empty())
        SferaFileManager::writeFile(filename_, std::as_bytes(std::span(text_)));
}

std::string SphereUIInterfaceConfiguration::text_;

std::string SphereUIInterfaceConfiguration::filename_;
