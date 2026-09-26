#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "graphics/d3d9/Device.h"
#include "ui/Sprite.h"
#include "algorithms/StableSort.h"
#include "application/ClientApplication.h"
#include "camera/Camera.h"
#include "diagnostics/ClientDiagnostics.h"
#include "input/Cursors.h"
#include "input/DirectInputDevices.h"
#include "math/Color.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "runtime/Clock.h"
#include "text/Fonts.h"
#include "ui/Canvas.h"
#include "ui/GameInterfaceManager.h"
#include "ui/Rendering.h"
#include "ui/ScriptInterface.h"
#include "ui/UiTypes.h"
#include "ui/WidgetSupport.h"
#include "ui/Window.h"
#include "world/WorldObjects.h"

std::int32_t GameInterface::windowOrderKey(GameInterfaceWindowOrder order, std::uint32_t handle)
{
    const auto &item = *window(handle);
    const std::uint32_t bits = item.layer * 1000u + item.order;
    return SferaNumeric::signedWord(order == GameInterfaceWindowOrder::HitTest ? 0u - bits : bits);
}

bool GameInterface::isWindowSlotUsed(const std::unique_ptr<GameUiWindow> &item)
{
    return item != nullptr;
}
void GameInterface::drawFrame()
{
    setRenderState();
    g_sfera_interface.draw();

    const int elapsed = SferaNumeric::signedWord(SferaNumeric::lowWord(WorldClock::nowTicks()) - SferaNumeric::lowWord(SferaClientApplication::frame_anchor));
    ++SferaClientApplication::frame_samples;
    if (elapsed > 1000)
    {
        SferaClientApplication::measured_fps = SferaNumeric::real32(SferaClientApplication::frame_samples * 10000.0 / elapsed);
        SferaClientApplication::frame_samples = 0;
        const auto now = WorldClock::nowTicks();
        SferaClientApplication::frame_anchor = now;
    }
    restoreRenderState();
}

void GameInterface::interfaceWindowBorder(const GameUiWindow &window)
{
    const auto width = window.contentRight - window.contentLeft + 1, height = window.contentBottom - window.contentTop + 1;
    const float u = width / 256.0f, v = height / 256.0f;
    const float background[] = {0, 0, u, 0, u, v, 0, v};
    GameInterface::drawTexture(window.contentLeft, window.contentTop, width, height, "winfon", window.opacity, 0, background);
    const float cornerUv[] = {0, 6.0f / 256, 6.0f / 256, 6.0f / 256, 6.0f / 256, 12.0f / 256, 0, 12.0f / 256};
    for (std::size_t corner = 0; corner < 4; ++corner)
    {
        float uv[8];
        for (std::size_t vertex = 0; vertex < 4; ++vertex)
        {
            const auto source = (vertex + 4 - corner) % 4;
            uv[vertex * 2] = cornerUv[source * 2];
            uv[vertex * 2 + 1] = cornerUv[source * 2 + 1];
        }
        const bool right = corner == 1 || corner == 2, bottom = corner >= 2;
        GameInterface::drawTexture(right ? window.contentRight + 1 : window.left, bottom ? window.contentBottom + 1 : window.top,
                                   right ? window.right - window.contentRight : window.contentLeft - window.left, bottom ? window.bottom - window.contentBottom : window.contentTop - window.top,
                                   "wf_bord", window.opacity, 0, uv);
    }
    const float horizontal[] = {0, 0, u, 0, u, 6.0f / 256, 0, 6.0f / 256};
    GameInterface::drawTexture(window.contentLeft, window.top, width, window.contentTop - window.top, "wf_bord", window.opacity, 0, horizontal);
    GameInterface::drawTexture(window.contentLeft, window.contentBottom + 1, width, window.bottom - window.contentBottom, "wf_bord", window.opacity, 0, horizontal);
    const float vertical[] = {0, 6.0f / 256, 0, 0, v, 0, v, 6.0f / 256};
    GameInterface::drawTexture(window.left, window.contentTop, window.contentLeft - window.left, height, "wf_bord", window.opacity, 0, vertical);
    GameInterface::drawTexture(window.contentRight + 1, window.contentTop, window.right - window.contentRight, height, "wf_bord", window.opacity, 0, vertical);
}

void GameInterface::interfaceElement(const GameUiElement &element, int scrollX, int scrollY)
{
    int x = 0, y = 0;
    auto alpha = element.alpha;
    float depth = 0;
    if (element.objectHandle != UINT32_MAX)
    {
        SferaVec3F projected;
        if (!g_sfera_camera.projectObjectTop(element.objectHandle, projected, element.height_factor))
            return;
        x = SferaNumeric::truncateInt(projected.x);
        y = SferaNumeric::truncateInt(projected.y);
        const auto &object = *g_sfera_world_objects.object(element.objectHandle);
        const auto &reference = *g_sfera_world_objects.object(1);
        const auto delta = reference.position - object.position;
        const double delta_x = delta.x, delta_y = delta.y, delta_z = delta.z;
        const float squaredDistance = SferaNumeric::real32(delta_x * delta.x + delta_y * delta.y + delta_z * delta.z);
        const double precise_squared_distance = squaredDistance;
        const float distance = SferaNumeric::real32(std::sqrt(precise_squared_distance));
        if (distance > 100.0f)
            return;
        alpha = 255u - SferaNumeric::truncateInt(distance / 100.0 * 255.0);
        depth = SferaNumeric::real32(g_sfera_camera.frame_transform.inverseTransformPoint(object.position).z - 2.0);
        if (g_sfera_camera.near_distance > depth)
        {
            const double near_distance = g_sfera_camera.near_distance;
            constexpr double depth_epsilon = 0.01f;
            depth = SferaNumeric::real32(near_distance + depth_epsilon);
        }
    }
    SferaCanvasRenderer::drawElement(element, scrollX, scrollY, x, y, alpha, depth);
}

void GameInterface::drawWindow(std::uint32_t handle)
{
    auto *window = GameInterface::window(handle);
    if (!window)
    {
        WorldDiagnostics::message.clear();
        WorldDiagnostics::appendScriptContext("draw_window: wrong handle");
        WorldDiagnostics::flushScriptContext();
        return;
    }
    if (handle != 0 && window->opacity != 0)
        GameInterface::interfaceWindowBorder(*window);
    SferaCanvasRenderer::beginWindow(*window);
    const int scrollX = SferaNumeric::truncateInt(window->scrollX);
    const int scrollY = SferaNumeric::truncateInt(window->scrollY);
    for (auto control : window->controls)
    {
        if (control == UINT32_MAX)
            continue;
        auto *value = WorldGuiControls::control(control);
        if (!value)
            WorldDiagnostics::fail("internal error 37185837");
        GameInterface::interfaceElement(*value, scrollX, scrollY);
    }
    SferaCanvasRenderer::endWindow();
}

std::vector<std::uint32_t> GameInterface::orderedWindows(GameInterfaceWindowOrder order)
{
    std::vector<std::uint32_t> result;
    result.reserve(windows.size());
    for (std::uint32_t handle = 0; handle < windows.size(); ++handle)
        if (window(handle))
            result.push_back(handle);
    SferaAlgorithms::stableSort(result, std::bind_front(&GameInterface::windowOrderKey, order));
    return result;
}

void GameInterface::drawAll()
{
    for (std::uint32_t handle : orderedWindows(GameInterfaceWindowOrder::Draw))
        drawWindow(handle);
}

GameUiWindow *GameInterface::window(std::uint32_t handle, std::string_view operation)
{
    const auto &available_windows = GameInterface::windows;
    auto *result = handle < available_windows.size() ? available_windows[handle].get() : nullptr;
    if (!result && !operation.empty())
    {
        WorldDiagnostics::message.clear();
        WorldDiagnostics::appendScriptContext(operation);
        WorldDiagnostics::appendScriptContext(": wrong handle");
        WorldDiagnostics::flushScriptContext();
    }
    return result;
}

std::uint32_t GameInterface::createWindow(int left, int top, int right, int bottom, std::uint32_t layer, std::uint32_t opacity)
{
    const auto handle = WorldGuiControlSupport::vacantGuiSlot(GameInterface::windows);
    auto created = std::make_unique<GameUiWindow>();
    created->visible = true;
    created->scrollable = true;
    created->opacity = opacity;
    created->left = created->contentLeft = left;
    created->right = created->contentRight = right;
    created->top = created->contentTop = top;
    created->bottom = created->contentBottom = bottom;
    created->width = right - left + 1;
    created->height = bottom - top + 1;
    created->layer = layer;
    created->order = SferaNumeric::lowWord(std::count_if(windows.begin(), windows.end(), &GameInterface::isWindowSlotUsed));
    GameInterface::windows.at(handle) = std::move(created);
    return handle;
}

void GameInterface::destroyWindow(std::uint32_t handle)
{
    auto *removed = window(handle, "delete_window");
    if (!removed)
        return;
    for (const auto controlHandle : removed->controls)
    {
        if (controlHandle == UINT32_MAX)
            continue;
        const auto *item = WorldGuiControls::control(controlHandle);
        if (!item)
            WorldDiagnostics::fail("Window contains a missing control");
        WorldGuiControlSupport::eraseGuiControl(controlHandle, *item);
    }
    for (std::uint32_t index = 0; index < GameInterface::windows.size(); ++index)
    {
        auto *other = window(index);
        if (other && other->order > removed->order)
            --other->order;
    }
    if (GameInterface::active_window == handle)
        GameInterface::active_window = UINT32_MAX;
    windows.at(handle).reset();
}

GameUiHit GameInterface::hitTest(SferaCursorPosition point)
{
    GameUiHit hit{};
    for (std::uint32_t handle : orderedWindows(GameInterfaceWindowOrder::HitTest))
    {
        const auto &item = *window(handle);
        if (!item.visible || point.x < item.left || point.x > item.right || point.y < item.top || point.y > item.bottom)
            continue;
        hit.window = handle;
        hit.border = point.x < item.contentLeft || point.x > item.contentRight || point.y < item.contentTop || point.y > item.contentBottom;
        break;
    }
    if (hit.border)
        return hit;
    const auto *owner = window(hit.window);
    if (!owner)
        return hit;
    const float rounded_x = SferaNumeric::real32(point.x);
    const float rounded_y = SferaNumeric::real32(point.y);
    const double x = rounded_x, y = rounded_y;
    for (auto handle : owner->controls)
    {
        if (handle == UINT32_MAX)
            continue;
        const auto *item = WorldGuiControls::control(handle);
        if (!item)
            WorldDiagnostics::fail("Window contains a missing control");
        const double absolute_left = item->left + owner->contentLeft, absolute_right = item->right + owner->contentLeft;
        const double absolute_top = item->top + owner->contentTop, absolute_bottom = item->bottom + owner->contentTop;
        const double left = absolute_left - owner->scrollX, right = absolute_right - owner->scrollX;
        const double top = absolute_top - owner->scrollY, bottom = absolute_bottom - owner->scrollY;
        if (x >= left && x <= right && y >= top && y <= bottom)
        {
            hit.control = handle;
            break;
        }
    }
    return hit;
}

void GameInterface::updateInput()
{
    auto &cursor = *CCursorManager::instance().activeCursor();
    auto &active = GameInterface::active_window;
    const auto buttons = g_sfera_direct_input_runtime.mouse.buttons;
    if (g_sfera_interface.world_interaction_enabled)
    {
        if (active != 0u)
            cursor.updatePosition();
        if (active == UINT32_MAX)
        {
            if (buttons & 2u)
                active = hitTest(CCursorManager::instance().position()).window;
        }
        else if (!(buttons & 2u))
            active = UINT32_MAX;
        else if (active != 0u)
        {
            auto *selected = window(active);
            if (selected && selected->scrollable)
            {
                auto position = CCursorManager::instance().position();
                selected->scrollBy(g_sfera_direct_input_runtime.mouse.dx * 1.5f, g_sfera_direct_input_runtime.mouse.dy * 1.5f, position);
                cursor.setPosition(position.x, position.y);
            }
        }
        cursor.show();
    }
    const auto previous = g_sfera_interface.world_input_buttons;
    if ((buttons & 1u) != (previous & 1u))
    {
        const auto hit = g_sfera_interface.world_interaction_enabled ? hitTest(CCursorManager::instance().position()) : GameUiHit{};
        if (auto *selected = window(hit.window))
            selected->enqueueInput(hit.control, (buttons & 1u) ? 1u : 2u);
    }
    g_sfera_interface.world_input_buttons = buttons;
}

HRESULT GameInterface::drawSpriteQuad(std::uint32_t color, const float *uv, float left, float top, float right, float bottom)
{
    return SferaCanvasRenderer::drawSpriteQuad(color, uv, left, top, right, bottom);
}

HRESULT GameInterface::drawSpriteTexture(std::uint32_t color, int texture, float left, float top, float right, float bottom, const float *uv, bool reserved)
{
    return SferaCanvasRenderer::drawSpriteTexture(color, texture, left, top, right, bottom, uv, reserved);
}

void GameInterface::drawTexture(int left, int top, int width, int height, std::string_view name, std::uint32_t alpha, float depth, const float *uv)
{
    SferaCanvasRenderer::drawTexture(left, top, width, height, name, alpha, depth, uv);
}

void GameInterface::tintTexture(int left, int top, int width, int height, std::string_view name, std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint32_t alpha, const float *uv)
{
    SferaCanvasRenderer::tintTexture(left, top, width, height, name, red, green, blue, alpha, uv);
}

void GameInterface::drawFullscreenOverlay()
{
    SferaCanvasRenderer::drawOverlay(g_sfera_interface.overlay_alpha);
}

int GameInterface::fontHeight(int font, int scale)
{
    return g_sfera_font_runtime.faces[font].span * scale;
}

int GameInterface::glyphWidth(std::uint32_t character, int font)
{
    return g_sfera_font_runtime.faces[font].widths[character] + g_sfera_font_runtime.faces[font].code_base;
}

int GameInterface::textHeight(int font, int scale, int lines)
{
    return g_sfera_font_runtime.textHeight(font, scale, lines);
}

int GameInterface::lineOffset(int font, int scale, int line)
{
    return g_sfera_font_runtime.faces[font].cell_step * scale * line;
}

void GameInterface::setRenderState()
{
    SferaCanvasRenderer::setRenderState();
}

void GameInterface::restoreRenderState()
{
    SferaCanvasRenderer::restoreRenderState();
}

void GameInterface::drawAtlasText(std::string_view text, int x, int y, std::uint32_t color, int scale, int font, float depth)
{
    SferaCanvasRenderer::drawAtlasText(text, x, y, color, scale, font, depth);
}

bool WorldGuiControls::buildText(int x, int y, std::string_view text, GameUiElement &item, const GameUiWindow &window)
{
    item.layoutText(text, window, x, y);
    return (window.textStyle & GameUiWindowmeasureOnly) == 0;
}

bool WorldGuiControls::buildSprite(int x, int y, int width, int height, std::string_view texture, std::uint32_t alpha, GameUiElement &item, const GameUiWindow &window)
{
    if (texture.empty())
        WorldDiagnostics::fail("Sprite texture name is empty");
    const std::string_view name(texture);
    if (name.size() >= 40)
        WorldDiagnostics::fail("Sprite texture name is too long");
    item.content = GameUiElementSprite{std::string(name), window.contentLeft + x, window.contentTop + y, width, height};
    item.left = x;
    item.top = y;
    item.right = x + width - 1;
    item.bottom = y + height - 1;
    item.alpha = alpha;
    return true;
}

GameUiElement *WorldGuiControls::control(std::uint32_t handle)
{
    return handle < elements.size() ? elements[handle].get() : nullptr;
}

void WorldGuiControls::detachFromWindow(std::uint32_t windowHandle, std::uint32_t slot)
{
    auto *owner = GameInterface::window(windowHandle);
    if (!owner)
        WorldDiagnostics::fail("internal error 75248635");
    owner->detach(slot);
}

void WorldGuiControls::destroySprite(std::uint32_t handle)
{
    auto *item = control(handle);
    if (!item)
    {
        WorldDiagnostics::warning("delete_sprite: wrong handle");
        return;
    }
    WorldGuiControlSupport::eraseGuiControl(handle, *item);
}

void WorldGuiControls::destroyText(std::uint32_t handle)
{
    if (handle == UINT32_MAX)
        WorldDiagnostics::fail("Wrong hand was used!");
    auto *item = control(handle);
    if (!item)
        WorldDiagnostics::fail("delete_text: wrong handle");
    WorldGuiControlSupport::eraseGuiControl(handle, *item);
}

void WorldGuiControls::removeForObject(std::uint32_t objectHandle)
{
    for (std::uint32_t handle = 0; handle < elements.size(); ++handle)
    {
        const auto *item = control(handle);
        if (item && item->objectHandle == objectHandle)
            WorldGuiControlSupport::eraseGuiControl(handle, *item);
    }
}

std::uint32_t WorldGuiControls::createText(int x, int y, std::string_view text, std::uint32_t windowHandle)
{
    return WorldGuiControls::createGuiControl(windowHandle, "create_text: wrong window", std::bind_front(&WorldGuiControls::buildText, x, y, text));
}

std::uint32_t WorldGuiControls::createSprite(int x, int y, int width, int height, std::string_view texture, std::uint32_t windowHandle, std::uint32_t alpha)
{
    return WorldGuiControls::createGuiControl(windowHandle, "create_sprite: wrong window", std::bind_front(&WorldGuiControls::buildSprite, x, y, width, height, texture, alpha));
}

void WorldGuiControls::setAppearance(std::uint32_t handle, std::uint32_t alpha, std::optional<std::uint32_t> color)
{
    auto *item = control(handle);
    if (!item)
        WorldDiagnostics::fail(color ? "text_color: wrong handle" : "set_sprite_alpha: wrong handle");
    item->alpha = alpha;
    if (color)
        item->color = *color;
}

void WorldGuiControls::destroyAllText()
{
    for (std::uint32_t handle = 0; handle < WorldGuiControls::elements.size(); ++handle)
    {
        const auto *item = control(handle);
        if (item && item->isText())
            destroyText(handle);
    }
}

uint32_t WorldGuiControls::text_height{};
uint32_t WorldGuiControls::text_width{};

bool SphereUICMinimapControl::playerHeading(float &heading)
{
    const auto handle = g_sfera_world_objects.controlled_object_handle;
    if (SferaNumeric::signedWord(handle) <= 0)
        return false;
    const auto *object = g_sfera_world_objects.effectObject(handle);
    if (object == nullptr)
        return false;
    heading = object->rotation.x;
    return true;
}

std::unique_ptr<SphereUIWindow> SphereUICMinimapControl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUICMinimapControl::cloneProperties);
}

void SphereUICMinimapControl::draw()
{
    if (hidden)
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    const float left = SferaNumeric::real32(bounds.left), top = SferaNumeric::real32(bounds.top);
    SphereUIInterfaceRenderer::drawTexture(g_sfera_graphics_runtime.d3d_runtime->minimapTexture().native_texture.Get(), left, top, left + 256.0f, top + 256.0f,
                                           SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    float heading = 0.0f;
    if (SphereUICMinimapControl::playerHeading(heading) && resource_reference != nullptr)
    {
        int parent_x = 0, parent_y = 0;
        if (auto *owner = parent)
            owner->getAbsolutePosition(parent_x, parent_y);
        const float arrow_x = SferaNumeric::real32(SphereUIDetail::addCoordinate(parent_x, 127));
        const float arrow_y = SferaNumeric::real32(SphereUIDetail::addCoordinate(parent_y, 132));
        resource_reference->draw(arrow_x, arrow_y, arrow_x + 28.0f, arrow_y + 28.0f, UiColor::white, -heading);
    }
}

SphereUICMinimapControl::SphereUICMinimapControl()
{
    resource_reference = nullptr;
    hidden = false;
    control_kind = SphereUIUiControlKind::minimap;
}

void SphereUICMinimapControl::cloneProperties(SphereUICMinimapControl &target, const SphereUICMinimapControl &source, SphereUIWindowCloneContext &)
{
    if (source.parent)
        target.resource_reference = target.getResource("arup");
}
