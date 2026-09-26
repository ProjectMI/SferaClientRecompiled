#pragma once

#include <windows.h>
#include <array>
#include <cstdint>
#include <deque>
#include <dinput.h>
#include <limits>
#include <string_view>
#include <wrl/client.h>

#include "input/MouseInput.h"

class SferaInputDevices;

class SferaInputDevices
{
  public:
    uint32_t key_bindings[64]{};
    uint32_t binding_key{};
    SferaMouseInputState mouse{};
    uint32_t character{};
    uint32_t binding_capture{};
    uint32_t virtual_key{};
    std::deque<std::uint32_t> key_queue;
    uint32_t text_filter{};
    uint8_t allowed_glyphs[256]{};
    uint32_t scan_code{};
    std::deque<std::uint32_t> character_queue;

    static constexpr std::uint8_t pressedMask = 1u << (std::numeric_limits<std::uint8_t>::digits - 1);
    SferaInputDevices();
    SferaInputDevices(const SferaInputDevices &) = delete;
    SferaInputDevices &operator=(const SferaInputDevices &) = delete;
    ~SferaInputDevices();
    Microsoft::WRL::ComPtr<IDirectInput8A> direct_input;
    Microsoft::WRL::ComPtr<IDirectInputDevice8A> mouse_device;
    Microsoft::WRL::ComPtr<IDirectInputDevice8A> keyboard_device;
    std::uint8_t keyboard_state[256]{};
    std::uint8_t view_adjust_state = 0;
    std::uint8_t modifier_08 = 0;
    std::uint8_t modifier_20 = 0;
    void initialize(HWND window);
    void release() noexcept;
    void focusChanged(bool focused) noexcept;
    void pollKeyboard();
    std::uint32_t takeKeyPress();
    SferaMouseInputState pollMouse();

  private:
    template <class Read, class Acquire> static HRESULT readInputDevice(Read &&read, Acquire &&acquire);

  private:
    static auto requireInputResult(HRESULT result, std::string_view operation);

  private:
    HRESULT readKeyboardState(std::array<std::uint8_t, 256> &state);
    void acquireKeyboard()
    {
        keyboard_device->Acquire();
    }
    static std::uint8_t pressedKeyBits(std::uint8_t value);
    HRESULT readKeyboardEvent(DIDEVICEOBJECTDATA &event, DWORD &count)
    {
        count = 1;
        return keyboard_device->GetDeviceData(sizeof(event), &event, &count, 0);
    }
    HRESULT readMouseState(DIMOUSESTATE &state)
    {
        return mouse_device->GetDeviceState(sizeof(state), &state);
    }
    void acquireMouseInViewport();
};

extern SferaInputDevices g_sfera_direct_input_runtime;

struct SphereUIKeyboardRow;
struct UiKeyBinding;

struct UiKeyBinding
{
    std::string_view name;
    std::uint32_t code;
    std::uint32_t scan;
};

struct SphereUIKeyboardRow
{
    std::string_view keys;
    std::uint32_t first_scan;
};

inline constexpr UiKeyBinding uiKeyBindings[] = {{"ESCAPE", VK_ESCAPE, 1u},
                                                 {"SCRL_LOCK", VK_SCROLL, 70u},
                                                 {"PAUSE", VK_PAUSE, 197u},
                                                 {"BACKSPACE", VK_BACK, 14u},
                                                 {"SPACE", VK_SPACE, 57u},
                                                 {"END", VK_END, 207u},
                                                 {"HOME", VK_HOME, 199u},
                                                 {"LEFT", VK_LEFT, 203u},
                                                 {"UP", VK_UP, 200u},
                                                 {"RIGHT", VK_RIGHT, 205u},
                                                 {"DOWN", VK_DOWN, 208u},
                                                 {"INSERT", VK_INSERT, 210u},
                                                 {"DELETE", VK_DELETE, 211u},
                                                 {"ENTER", VK_RETURN, 28u},
                                                 {"CAPSLOCK", VK_CAPITAL, 58u},
                                                 {"NUMPADMULT", VK_MULTIPLY, 55u},
                                                 {"NUMPADADD", VK_ADD, 78u},
                                                 {"NUMLOCK", VK_NUMLOCK, 69u},
                                                 {"NUMPADSUBT", VK_SUBTRACT, 74u},
                                                 {"NUMPADDIV", VK_DIVIDE, 181u},
                                                 {"NUMPADPNT", VK_DECIMAL, 83u},
                                                 {"PAGEUP", VK_PRIOR, 201u},
                                                 {"PAGEDOWN", VK_NEXT, 209u},
                                                 {"`", VK_OEM_3, 41u},
                                                 {"-", VK_OEM_MINUS, 12u},
                                                 {"=", VK_OEM_PLUS, 13u},
                                                 {"\\", VK_OEM_5, 43u},
                                                 {"[", VK_OEM_4, 26u},
                                                 {"]", VK_OEM_6, 27u},
                                                 {";", VK_OEM_1, 39u},
                                                 {"'", VK_OEM_7, 40u},
                                                 {",", VK_OEM_COMMA, 51u},
                                                 {".", VK_OEM_PERIOD, 52u},
                                                 {"/", VK_OEM_2, 53u},
                                                 {"TAB", VK_TAB, 15u},
                                                 {"CTRL", VK_CONTROL, 29u},
                                                 {"SHIFT", VK_SHIFT, 42u}};
