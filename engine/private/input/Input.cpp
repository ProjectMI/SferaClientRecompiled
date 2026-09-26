#include <windows.h>
#include <algorithm>
#include <array>
#include <cstdint>
#include <dinput.h>
#include <functional>
#include <iterator>
#include <memory>
#include <string_view>
#include <utility>

#include "ui/Rendering.h"
#include "diagnostics/Diagnostics.h"
#include "input/Cursors.h"
#include "input/DirectInputDevices.h"
#include "input/MouseInput.h"
#include "numeric/Numeric.h"
#include "platform/windows/ApplicationHost.h"
#include "render/GraphicsRuntime.h"
#include "ui/UiHost.h"
#include "ui/UiRuntime.h"
#include "ui/UiTypes.h"

CCursorManager::~CCursorManager()
{
    initialized = nullptr;
}

CCursorManager &CCursorManager::instance()
{
    static CCursorManager manager;
    initialized = &manager;
    return manager;
}

void CCursorManager::focusChanged(bool focused) noexcept
{
    if (!focused)
    {
        ::ClipCursor(nullptr);
        if (::GetCapture() == SferaApplicationHost::mainWindow())
            ::ReleaseCapture();
    }
    if (!initialized)
        return;
    if (!focused)
    {
        initialized->hardware.clip_enabled = false;
        initialized->software.active = false;
    }
    else if (initialized->active)
    {
        initialized->active->show();
        initialized->active->apply();
    }
}

void CCursorManager::shutdown() noexcept
{
    focusChanged(false);
    if (!initialized)
        return;
    ::SetCursor(nullptr);
    initialized->hardware.cursor_handle.reset();
    initialized->active = nullptr;
    SphereUIRuntime::setSystemCursorVisible(true);
}

CCursor *CCursorManager::activeCursor() const
{
    if (active == nullptr)
    {
        SferaEngineDiagnostics::fatal("CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set");
    }
    return active;
}

void CCursorManager::select(std::uint32_t mode)
{
    if (mode > 1u)
        return;
    CCursor *selected = &hardware;
    if (mode == 0u)
        selected = &software;
    if (selected == active)
        return;
    CCursor *previous = active;
    active = selected;
    selected->copyStateFrom(previous);
    if (previous != nullptr)
        previous->deactivate();
    selected->activate();
}

SferaCursorPosition CCursorManager::position() const
{
    SferaCursorPosition result{};
    if (active != nullptr)
        active->getPosition(&result);
    return result;
}

SphereUICursorGeometry CCursorManager::geometry() const
{
    if (active == nullptr)
        return {};
    SferaCursorPosition position{};
    active->getPosition(&position);
    const auto dimensions = active == &software ? SphereUITextExtent{software.texture_width, software.texture_height} : SphereUITextExtent{hardware.texture_width, hardware.texture_height};
    const auto kind = active->cursorKind();
    return {position.x, position.y, dimensions.width, dimensions.height, SphereUICursorSupport::cursor_uses_center_clip(kind)};
}

CCursorManager *CCursorManager::initialized = nullptr;

SferaInputDevices::SferaInputDevices() = default;

SferaInputDevices::~SferaInputDevices()
{
    release();
}

auto SferaInputDevices::requireInputResult(HRESULT result, std::string_view operation)
{
    if (FAILED(result))
        SferaEngineDiagnostics::fail(operation);
}

void SferaInputDevices::initialize(HWND window)
{
    release();

    Microsoft::WRL::ComPtr<IDirectInput8A> input;
    Microsoft::WRL::ComPtr<IDirectInputDevice8A> keyboard, mouseInput;
    requireInputResult(::DirectInput8Create(::GetModuleHandleW(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8A, reinterpret_cast<void **>(input.GetAddressOf()), nullptr),
                       "DirectInputCreate failed");
    requireInputResult(input->CreateDevice(GUID_SysKeyboard, keyboard.GetAddressOf(), nullptr), "CreateDevice(keyboard) failed");
    requireInputResult(input->CreateDevice(GUID_SysMouse, mouseInput.GetAddressOf(), nullptr), "CreateDevice(mouse) failed");
    for (auto *device : {keyboard.Get(), mouseInput.Get()})
    {
        requireInputResult(device->SetCooperativeLevel(window, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND), "SetCooperativeLevel failed");
    }
    requireInputResult(keyboard->SetDataFormat(&c_dfDIKeyboard), "SetDataFormat(keyboard) failed");
    requireInputResult(mouseInput->SetDataFormat(&c_dfDIMouse), "SetDataFormat(mouse) failed");
    DIPROPDWORD buffering{};
    buffering.diph.dwSize = SferaNumeric::lowWord(sizeof(buffering));
    buffering.diph.dwHeaderSize = SferaNumeric::lowWord(sizeof(buffering.diph));
    buffering.diph.dwHow = DIPH_DEVICE;
    buffering.dwData = 8u;
    requireInputResult(keyboard->SetProperty(DIPROP_BUFFERSIZE, &buffering.diph), "SetProperty failed");
    keyboard->Acquire();
    mouseInput->Acquire();
    direct_input = std::move(input);
    keyboard_device = std::move(keyboard);
    mouse_device = std::move(mouseInput);
}

void SferaInputDevices::release() noexcept
{
    for (auto *device : {std::addressof(keyboard_device), std::addressof(mouse_device)})
    {
        if (*device)
            (*device)->Unacquire();
        device->Reset();
    }
    direct_input.Reset();
    std::fill(std::begin(keyboard_state), std::end(keyboard_state), std::uint8_t{});
}

template <class Read, class Acquire> HRESULT SferaInputDevices::readInputDevice(Read &&read, Acquire &&acquire)
{
    const HRESULT result = read();
    if (result != DIERR_INPUTLOST && result != DIERR_NOTACQUIRED)
        return result;
    acquire();
    return read();
}

void SferaInputDevices::focusChanged(bool focused) noexcept
{
    std::fill(std::begin(keyboard_state), std::end(keyboard_state), std::uint8_t{});
    view_adjust_state = modifier_08 = modifier_20 = 0;
    for (auto *device : {keyboard_device.Get(), mouse_device.Get()})
    {
        if (!device)
            continue;
        if (focused)
            device->Acquire();
        else
            device->Unacquire();
    }
    if (keyboard_device)
    {
        DWORD count = INFINITE;
        keyboard_device->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), nullptr, &count, 0);
    }
}

void SferaInputDevices::pollKeyboard()
{
    if (keyboard_device == nullptr || !SferaApplicationHost::active())
        return;
    std::array<std::uint8_t, 256> state{};
    const auto result = readInputDevice(std::bind(&SferaInputDevices::readKeyboardState, this, std::ref(state)), std::bind(&SferaInputDevices::acquireKeyboard, this));
    if (FAILED(result))
        return;
    std::transform(state.begin(), state.end(), std::begin(keyboard_state), &SferaInputDevices::pressedKeyBits);
}

std::uint32_t SferaInputDevices::takeKeyPress()
{
    if (keyboard_device == nullptr || !SferaApplicationHost::active())
        return 0;
    for (;;)
    {
        DIDEVICEOBJECTDATA event{};
        DWORD count = 1;
        const auto result = readInputDevice(std::bind(&SferaInputDevices::readKeyboardEvent, this, std::ref(event), std::ref(count)), std::bind(&SferaInputDevices::acquireKeyboard, this));
        if (FAILED(result) || count == 0)
            return 0;
        if ((event.dwData & SferaInputDevices::pressedMask) != 0u)
            return event.dwOfs;
    }
}

SferaMouseInputState SferaInputDevices::pollMouse()
{
    if (mouse_device == nullptr || !SferaApplicationHost::active())
        return {};
    DIMOUSESTATE state{};
    const auto result = readInputDevice(std::bind(&SferaInputDevices::readMouseState, this, std::ref(state)), std::bind(&SferaInputDevices::acquireMouseInViewport, this));
    if (FAILED(result))
        return {};
    const auto primary = ::GetSystemMetrics(SM_SWAPBUTTON) != 0 ? 1u : 0u;
    SferaMouseInputState output{};
    output.dx = state.lX;
    output.dy = state.lY;
    output.buttons = ((state.rgbButtons[primary] & SferaInputDevices::pressedMask) != 0u ? 1u : 0u) | ((state.rgbButtons[1u - primary] & SferaInputDevices::pressedMask) != 0u ? 2u : 0u);
    output.wheel = state.lZ / WHEEL_DELTA;
    return output;
}

HRESULT SferaInputDevices::readKeyboardState(std::array<std::uint8_t, 256> &state)
{
    return keyboard_device->GetDeviceState(SferaNumeric::lowWord(state.size()), state.data());
}

std::uint8_t SferaInputDevices::pressedKeyBits(std::uint8_t value)
{
    return SferaNumeric::lowByte(value & SferaInputDevices::pressedMask);
}

void SferaInputDevices::acquireMouseInViewport()
{
    if (CCursorManager::instance().activeCursor()->isInsideViewport())
        mouse_device->Acquire();
}

void SphereUIBitmapDeleter::operator()(HBITMAP bitmap) const noexcept
{
    if (bitmap)
        ::DeleteObject(bitmap);
}

CHardwareCursor::CHardwareCursor()
{
    SphereUIRuntime::setSystemCursorVisible(false);
}

CHardwareCursor::~CHardwareCursor()
{
    if (clip_enabled)
        ::ClipCursor(nullptr);
    if (::GetCursor() == cursor_handle.get())
        ::SetCursor(nullptr);
}

void CHardwareCursor::copyStateFrom(const CCursor *previous)
{
    SferaCursorPosition position{};
    if (previous != nullptr)
    {
        saved_system_visible = previous->isSystemCursorVisible() ? 1u : 0u;
        kind = previous->cursorKind();
        previous->getPosition(&position);
    }
    else
    {
        saved_system_visible = true;
        kind = 255u;
        getPosition(&position);
    }
    saved_x = position.x;
    saved_y = position.y;
}

void CHardwareCursor::activate()
{
    setSystemCursorVisible(saved_system_visible);
    setCursorKind(kind);
    setPosition(saved_x, saved_y);
}

void CHardwareCursor::deactivate()
{
    if (std::exchange(clip_enabled, false))
        ::ClipCursor(nullptr);
    SphereUIRuntime::setSystemCursorVisible(false);
}

void CHardwareCursor::apply()
{
    ::SetCursor(cursor_handle.get());
}

SferaCursorPosition *CHardwareCursor::getPosition(SferaCursorPosition *output) const
{
    if (output == nullptr)
        return nullptr;
    if (SferaApplicationHost::active())
    {
        POINT point{};
        ::GetCursorPos(&point);
        ::ScreenToClient(SferaApplicationHost::mainWindow(), &point);
        output->x = point.x;
        output->y = point.y;
    }
    else
    {
        output->x = g_sfera_graphics_runtime.display_width / 2;
        output->y = g_sfera_graphics_runtime.display_height / 2;
    }
    return output;
}

void CHardwareCursor::setPosition(int x, int y)
{
    if (!SferaApplicationHost::active())
        return;
    POINT point{x, y};
    ::ClientToScreen(SferaApplicationHost::mainWindow(), &point);
    ::SetCursorPos(point.x, point.y);
}

void CHardwareCursor::show()
{
    const bool enabled = SphereUICursorSupport::cursor_uses_center_clip(kind) && SferaApplicationHost::active();
    if (clip_enabled == enabled)
        return;
    if (enabled)
    {
        POINT point{g_sfera_graphics_runtime.display_width / 2, g_sfera_graphics_runtime.display_height / 2};
        ::ClientToScreen(SferaApplicationHost::mainWindow(), &point);
        const RECT rectangle{point.x, point.y, point.x + 1, point.y + 1};
        clip_enabled = ::ClipCursor(&rectangle) != FALSE;
    }
    else
    {
        ::ClipCursor(nullptr);
        clip_enabled = false;
    }
}

bool CHardwareCursor::isInsideViewport() const
{
    SferaCursorPosition position{};
    getPosition(&position);
    return position.x >= 0 && position.x < g_sfera_graphics_runtime.display_width && position.y >= 0 && position.y < g_sfera_graphics_runtime.display_height;
}

bool CHardwareCursor::isSystemCursorVisible() const
{
    CURSORINFO cursor{};
    cursor.cbSize = SferaNumeric::lowWord(sizeof(cursor));
    return ::GetCursorInfo(&cursor) && (cursor.flags & CURSOR_SHOWING) != 0;
}

void CHardwareCursor::setSystemCursorVisible(bool visible)
{
    SphereUIRuntime::setSystemCursorVisible(visible);
}

CSoftwareCursor::CSoftwareCursor()
{
    x = g_sfera_graphics_runtime.display_width / 2;
    y = g_sfera_graphics_runtime.display_height / 2;
}

void CSoftwareCursor::copyStateFrom(const CCursor *previous)
{
    if (previous != nullptr)
    {
        SferaCursorPosition position{};
        saved_system_visible = previous->isSystemCursorVisible() ? 1u : 0u;
        saved_kind = previous->cursorKind();
        previous->getPosition(&position);
        saved_x = position.x;
        saved_y = position.y;
    }
    else
    {
        saved_system_visible = true;
        saved_kind = 255u;
        saved_x = g_sfera_graphics_runtime.display_width / 2;
        saved_y = g_sfera_graphics_runtime.display_height / 2;
    }
}

void CSoftwareCursor::activate()
{
    if (auto *mouse = g_sfera_direct_input_runtime.mouse_device.Get())
    {
        mouse->Unacquire();
        const HRESULT result = mouse->SetCooperativeLevel(SferaApplicationHost::mainWindow(), DISCL_EXCLUSIVE | DISCL_FOREGROUND);
        if (FAILED(result))
        {
            SferaEngineDiagnostics::fatal("CSoftwareCursor::Activate(): SetCooperativeLevel() failed");
        }
        mouse->Acquire();
    }
    setSystemCursorVisible(saved_system_visible);
    setCursorKind(saved_kind);
    setPosition(saved_x, saved_y);
}

void CSoftwareCursor::deactivate()
{
    if (auto *mouse = g_sfera_direct_input_runtime.mouse_device.Get())
    {
        mouse->Unacquire();
        const HRESULT result = mouse->SetCooperativeLevel(SferaApplicationHost::mainWindow(), DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
        if (FAILED(result))
        {
            SferaEngineDiagnostics::fatal("CSoftwareCursor::Deactivate(): SetCooperativeLevel() failed");
        }
        mouse->Acquire();
    }
    setSystemCursorVisible(true);
    setCursorKind(255u);
}

void CSoftwareCursor::updatePosition()
{
    if (!active)
        return;
    x += SferaNumeric::truncateInt(g_sfera_direct_input_runtime.mouse.dx * 1.5);
    y += SferaNumeric::truncateInt(g_sfera_direct_input_runtime.mouse.dy * 1.5);
}

SferaCursorPosition *CSoftwareCursor::getPosition(SferaCursorPosition *output) const
{
    if (output == nullptr)
        return nullptr;
    output->x = x;
    output->y = y;
    return output;
}

void CSoftwareCursor::show()
{
    const int width = g_sfera_graphics_runtime.display_width;
    const int height = g_sfera_graphics_runtime.display_height;
    auto *mouse = g_sfera_direct_input_runtime.mouse_device.Get();
    if (active)
    {
        const bool outside = x < 0 || x >= width || y < 0 || y >= height;
        if (outside || !SferaApplicationHost::active())
        {
            if (!SphereUICursorSupport::cursor_uses_center_clip(cursorKind()))
            {
                if (mouse != nullptr)
                    mouse->Unacquire();
                SphereUIRuntime::setSystemCursorVisible(true);
                POINT point{x, y};
                ::ClientToScreen(SferaApplicationHost::mainWindow(), &point);
                ::SetCursorPos(point.x, point.y);
                active = false;
            }
        }
        if (width > 0)
            x = std::clamp(x, 0, width - 1);
        if (height > 0)
            y = std::clamp(y, 0, height - 1);
        return;
    }
    POINT point{};
    ::GetCursorPos(&point);
    ::ScreenToClient(SferaApplicationHost::mainWindow(), &point);
    if (point.x < 0 || point.x >= width || point.y < 0 || point.y >= height || !SferaApplicationHost::active())
        return;
    x = point.x;
    y = point.y;
    SphereUIRuntime::setSystemCursorVisible(false);
    if (mouse != nullptr)
        mouse->Acquire();
    active = true;
}

bool CSoftwareCursor::isSystemCursorVisible() const
{
    const auto *state = SphereUIHost::cursor();
    return state != nullptr && state->system_visible;
}

void CSoftwareCursor::setSystemCursorVisible(bool visible)
{
    if (auto *state = SphereUIHost::cursor())
        state->system_visible = visible ? 1u : 0u;
}

std::uint32_t CSoftwareCursor::cursorKind() const
{
    const auto *state = SphereUIHost::cursor();
    return state == nullptr ? 255u : state->kind;
}
