#include "semantic_window.h"
#include "semantic_classes.h"
#include "semantic_static.h"
#include <shellapi.h>
#include <algorithm>
#include <array>
#include <bit>
#include <charconv>
#include <string>
#include <string_view>
#include <span>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <new>
#include <memory>
#include <limits>
#include <stdexcept>
#include <fstream>
#include <iterator>
#include <type_traits>
#include <utility>
#include <climits>
#include <sys/stat.h>
namespace {
    template<class T> struct NamedValue {
        const char* name;
        T value;
    };

    template<class T, class... Members>
    void copyProperties(T& target, const T& source, Members... members) {
        ((target.*members = source.*members), ...);
    }

    constexpr std::uint32_t invalidIndex = UINT32_MAX;
    constexpr int inheritFont = -1;
    constexpr auto anyControlKind = SphereUI::UiControlKind::any;
    constexpr std::uint32_t maximumScrollOffset = INT32_MAX;
    constexpr std::uint32_t missingConfigValue = UINT32_MAX;
    constexpr std::uint32_t dragDropStateMask = 255u;
    using UiControlKind = SphereUI::UiControlKind;

    namespace UiColor {
        constexpr std::uint32_t white = SferaColor::rgba(255u, 255u, 255u, 255u).argb();
        constexpr std::uint32_t opaqueBlack = SferaColor::rgba(0u, 0u, 0u, 255u).argb();
        constexpr std::uint32_t whiteRgb = SferaColor::rgba(255u, 255u, 255u, 0u).argb();
        constexpr std::uint32_t frameBackground = SferaColor::rgba(40u, 36u, 32u, 0u).argb();
        constexpr std::uint32_t tooltipBackground = SferaColor::rgba(255u, 255u, 225u, 0u).argb();
        constexpr std::uint32_t listSelection = SferaColor::rgba(0u, 0u, 0u, 50u).argb();
        constexpr std::uint32_t slotFill = SferaColor::rgba(20u, 20u, 20u, 0u).argb();
        constexpr std::uint32_t slotBorder = SferaColor::rgba(158u, 124u, 106u, 255u).argb();
        constexpr std::uint32_t slotRejected = SferaColor::rgba(130u, 28u, 27u, 0u).argb();
        constexpr std::uint32_t slotAccepted = SferaColor::rgba(54u, 100u, 37u, 0u).argb();
        constexpr std::uint32_t hyperLink = SferaColor::rgba(255u, 0u, 0u, 255u).argb();
        constexpr std::uint32_t hyperLinkHover = SferaColor::rgba(255u, 255u, 0u, 255u).argb();
    }

    using UiMessage = SphereUI::UiMessage;

    namespace ScrollField {
        constexpr std::uint32_t range = 1u << 0u;
        constexpr std::uint32_t page = 1u << 1u;
        constexpr std::uint32_t position = 1u << 2u;
        constexpr std::uint32_t step = 1u << 4u;
        constexpr std::uint32_t all = range | page | position | step;
    }

    namespace WindowStyle = SphereUI::WindowStyle;

    namespace TextAlignment {
        constexpr std::uint32_t right = 1u << 0u;
        constexpr std::uint32_t bottom = 1u << 1u;
        constexpr std::uint32_t horizontalCenter = 1u << 2u;
        constexpr std::uint32_t verticalCenter = 1u << 3u;
        constexpr std::uint32_t center = horizontalCenter | verticalCenter;
    }

    namespace ButtonStyle {
        constexpr std::uint32_t stateImages = 1u << 0u;
        constexpr std::uint32_t releaseOutside = 1u << 1u;
        constexpr std::uint32_t repeatWhilePressed = 1u << 2u;
        constexpr std::uint32_t sendClose = 1u << 3u;
        constexpr std::uint32_t centerText = 1u << 4u;
        constexpr std::uint32_t showHelp = 1u << 5u;
    }

    namespace MouseInput = SphereUI::MouseInput;
}

namespace SphereUI::detail {
    void enqueueWindowEvent(std::deque<WindowEvent>& events, const WindowEvent& event) {
        if (events.size() >= 64u) events.clear();
        events.push_back(event);
    }

    // Copy at most capacity - 1 characters; even a truncated result is NUL-terminated.
    void copyText(std::span<char> destination, const char* source) {
        if (destination.empty()) return;
        std::size_t length = 0u;
        if (source != nullptr) while (length < destination.size() - 1u && source[length] != '\0') ++length;
        if (length != 0u) std::copy_n(source, length, destination.data());
        destination[length] = '\0';
    }

    void serializeHyperTextElements(std::span<const HyperTextRun> elements, std::string& hyper_text, std::string& plain);
    std::string escapeHyperText(std::string_view source);
    SphereUI::UiControlKind controlKind(const char* name);
    SphereUI::WindowAnimation::Kind animationKind(const char* name);
    std::uint32_t alignmentFlag(const char* name);
    int addCoordinate(int left, int right) {
        return static_cast<std::uint32_t>(left) + static_cast<std::uint32_t>(right);
    }

    int subtractCoordinate(int left, int right) {
        return static_cast<std::uint32_t>(left) - static_cast<std::uint32_t>(right);
    }

    template<class Callback> void forEachChild(const Window& window, Callback callback) {
        const auto owner_id = window.registration_id;
        std::vector<std::pair<Window*, std::uint64_t>> snapshot;
        snapshot.reserve(window.children.size());
        for (const auto& child : window.children) if (child) snapshot.emplace_back(child.get(), child->registration_id);
        for (const auto& [child, identity] : snapshot) {
            if (!g_sfera_interface.isRegistered(&window, owner_id)) break;
            if (g_sfera_interface.isRegistered(child, identity)) callback(*child);
        }
    }
}

namespace SphereUI::Runtime {
    void clipboardText(std::string& result);
    static void playWindowSound(bool opening);
    static void openExternalLink(const char* target, bool mail);
    static void playLinkSound();
    static std::uint32_t milliseconds();
    static bool keyDown(std::uint32_t key);
    static bool descriptionAutoPopup();
    CDescriptionWindow* descriptionWindow();
    static void setDescriptionWindow(CDescriptionWindow* window);
    static bool playerHeading(float& heading);

    static TextExtent screenSize();

    std::unique_ptr<Window> makeControl(SphereUI::UiControlKind kind);
    static std::uint32_t keyCode(const char* name);

    void broadcastMessage(Window* root, int group, SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second, SphereUI::UiControlKind kind);
    static int findImage(const char* name);
    static void playClickSound();
    static void playScrollSound(bool page);
    static std::uint64_t clockTicks();
}

namespace SphereUI::Runtime {
    void invokeEventHandler(WindowEventHandler handler, Window* window, const WindowEvent& event);
}

namespace SphereUI::detail {
    namespace {

        template<class T, std::size_t Size> T lookup(const char* name, const NamedValue<T> (&values)[Size], T fallback) {
            for (const auto& entry : values) if (SferaSimpleParser::equalsIgnoreCase(name, entry.name)) return entry.value;
            return fallback;
        }
    }

    SphereUI::UiControlKind controlKind(const char* name) {
        constexpr NamedValue<UiControlKind> values[] = { {
            "BUTTON", UiControlKind::button
        }, {"TEXT", UiControlKind::text}, {"IMAGE", UiControlKind::image}, {"PROGRESS_BAR", UiControlKind::progressBar}, {"SCROLL_BAR", UiControlKind::scrollBar}, {"HYPER_TEXT", UiControlKind::hyperText}, {"CHECKBOX", UiControlKind::checkBox}, {"RADIOBUTTON", UiControlKind::radioButton}, {"TEXTLIST", UiControlKind::textList}, {"SLIDER", UiControlKind::slider}, {"LISTITEM", UiControlKind::listItem}, {"EDIT", UiControlKind::edit}, {"SLOT", UiControlKind::slot}, {"SPINBUTTON", UiControlKind::spinButton}, {"RICHEDIT", UiControlKind::richEdit}, {"FILTERLISTCTRL", UiControlKind::filteredList}, {"MINIMAP", UiControlKind::minimap}, {"MENULISTCTRL", UiControlKind::menu}, {"HTCHATLISTCTRL", UiControlKind::hyperTextChat}, {"HTEDIT", UiControlKind::hyperTextEdit}, {"FONTPICKER", UiControlKind::fontPicker}, {"COLORPICKER", UiControlKind::colorPicker}};
        return lookup(name, values, anyControlKind);
    }

    SphereUI::WindowAnimation::Kind animationKind(const char* name) {
        constexpr NamedValue<SphereUI::WindowAnimation::Kind> values[] = { {
            "ALPHA_IN", WindowAnimation::Kind::FadeIn
        }, {"ALPHA_OUT", WindowAnimation::Kind::FadeOut}, {"MOVE_LEFT", WindowAnimation::Kind::MoveLeft}, {"MOVE_RIGHT", WindowAnimation::Kind::MoveRight}, {"MOVE_TOP", WindowAnimation::Kind::MoveUp}, {"MOVE_BOTTOM", WindowAnimation::Kind::MoveDown}};
        return lookup(name, values, WindowAnimation::Kind::None);
    }

    std::uint32_t alignmentFlag(const char* name) {
        constexpr NamedValue<std::uint32_t> values[] = { {
            "LEFT_X", SphereUI::alignLeft
        }, {"CENTER_X", SphereUI::alignCenterX}, {"RIGHT_X", SphereUI::alignRight}, {"LEFT_Y", SphereUI::alignTop}, {"CENTER_Y", SphereUI::alignCenterY}, {"RIGHT_Y", SphereUI::alignBottom}};
        return lookup(name, values, 0u);
    }
}
SphereUI::Window::Window() {
    hidden = true;
    can_go_top = save_last_position = font_initialized = true;
    text_color = UiColor::white;
    disabled_color = UiColor::opaqueBlack;
    alpha = 255u;
    g_sfera_interface.registerWindow(*this);
}

SphereUI::Window& SphereUI::Window::copyStateFrom(const Window& source) {
    if (this == &source) return *this;
    copyProperties(*this, source,
        &Window::name, &Window::text, &Window::help, &Window::resource_name, &Window::behavior_flags, &Window::width,
        &Window::height, &Window::x, &Window::y, &Window::alignment_flags, &Window::group, &Window::initial_x, &Window::initial_y,
        &Window::hidden, &Window::disabled, &Window::input_enabled);
    template_instance = false;
    copyProperties(*this, source,
        &Window::can_drag_drop, &Window::can_go_top, &Window::save_last_position, &Window::hit_transparent, &Window::control_kind,
        &Window::font, &Window::font_initialized, &Window::text_color, &Window::drag_over, &Window::disabled_color,
        &Window::parent, &Window::modal_owner, &Window::control_id, &Window::alpha, &Window::close_completed,
        &Window::text_offset_x, &Window::text_offset_y);
    tooltip = nullptr;
    copyProperties(*this, source,
        &Window::overlay, &Window::resource_parent, &Window::caption_left, &Window::caption_top, &Window::caption_right,
        &Window::caption_bottom, &Window::dragging, &Window::drag_offset_x, &Window::drag_offset_y, &Window::text_alignment,
        &Window::hide_after_animation, &Window::animation, &Window::resources, &Window::resource_reference,
        &Window::show_animation, &Window::hide_animation, &Window::modal_references, &Window::events);
    g_sfera_interface.copyEventHandler(this, &source);
    return *this;
}

struct SphereUI::Window::CloneContext {
    std::unordered_map<const Window*, Window*> windows;

    Window* resolve(const Window* source) const {
        if (source == nullptr) return nullptr;
        const auto found = windows.find(source);
        if (found != windows.end()) return found->second;
        return g_sfera_interface.isRegistered(source) ? const_cast<Window*>(source) : nullptr;
    }

    void finish() const {
        for (const auto& [source, target] : windows) {
            target->parent = resolve(target->parent);
            target->resource_parent = resolve(target->resource_parent);
            target->modal_owner = resolve(target->modal_owner);
            target->overlay = resolve(target->overlay);
            for (auto*& reference : target->modal_references) reference = resolve(reference);
            std::erase(target->modal_references, nullptr);
            std::erase_if(target->events, [this](WindowEvent& event) {
                const auto* source = event.source;
                event.source = resolve(source);
                return source != nullptr && event.source == nullptr;
            });
            if (auto* description = dynamic_cast<CDescriptionWindow*>(target)) {
                description->displayed_source = resolve(description->displayed_source);
                description->pending_source = resolve(description->pending_source);
            }
        }
        for (const auto& [source, target] : windows) target->template_instance = true;
    }
};

std::unique_ptr<SphereUI::Window> SphereUI::Window::clone() const {
    CloneContext context;
    auto result = cloneInto(context);
    context.finish();
    return result;
}

void SphereUI::Window::initializeCopy(const Window& source, CloneContext& context) {
    if (!context.windows.emplace(&source, this).second) throw std::logic_error("UI clone has duplicate ownership");
    copyStateFrom(source);
    children.clear();
    children.reserve(source.children.size());
    for (const auto& child : source.children) {
        if (child) appendChild(child->cloneInto(context));
        else children.push_back(nullptr);
    }
    tooltip.reset(source.tooltip ? static_cast<ToolTipCtrl*>(source.tooltip->cloneInto(context).release()) : nullptr);
    if (tooltip) tooltip->setParent(this);
}

void SphereUI::Window::appendChild(std::unique_ptr<Window> child) {
    if (!child) return;
    child->setParent(this);
    children.push_back(std::move(child));
}

void SphereUI::Window::appendResource(std::shared_ptr<const UiSprite> resource) {
    if (resource) resources.push_back(std::move(resource));
}

std::shared_ptr<const SphereUI::UiSprite> SphereUI::Window::findResource(const char* name_to_find) const {
    if (resource_parent != nullptr) if (auto resource = resource_parent->findResource(name_to_find)) return resource;
    const auto found = std::find_if(resources.begin(), resources.end(), [name_to_find](const auto& resource) {
        return SferaSimpleParser::equalsIgnoreCase(resource->name.c_str(), name_to_find);
    });
    return found == resources.end() ? nullptr : *found;
}

std::shared_ptr<const SphereUI::UiSprite> SphereUI::Window::getResource(const char* name_to_find) {
    if (auto existing = findResource(name_to_find)) return existing;
    if (Runtime::findImage(name_to_find) == -1) return {};
    auto sprite = std::make_shared<UiSprite>();
    sprite->setImage(name_to_find);
    appendResource(sprite);
    return sprite;
}

SphereUI::Window::~Window() {
    g_sfera_mbc_runtime.forgetNativeResource(this);
    g_sfera_interface.unbindEventHandler(this);
    auto owned_children = std::move(children);
    owned_children.clear();
    tooltip.reset();
    g_sfera_interface.unregisterWindow(*this);
}

HyperTextGeometry* HyperTextRun::geometry() {
    if (auto* bounds = std::get_if<HyperTextGeometry>(&content)) return bounds;
    if (auto* value = link()) return &value->bounds;
    return nullptr;
}

const HyperTextGeometry* HyperTextRun::geometry() const {
    if (const auto* bounds = std::get_if<HyperTextGeometry>(&content)) return bounds;
    if (const auto* value = link()) return &value->bounds;
    return nullptr;
}

const char* HyperTextRun::Link::linkValue() const {
    const auto separator = target.find("://");
    if (separator == std::string::npos) return "";
    auto offset = separator + 3u;
    if (offset < target.size() && target[offset] == '/') ++offset;
    return target.c_str() + offset;
}

void SphereUI::HyperTextChatListItem::initialize(const char* text, std::uint32_t channel_id, std::uint32_t text_color) {
    HyperTextChatListItem replacement;
    replacement.hyper_text = text == nullptr ? "" : text;
    replacement.channel = channel_id;
    replacement.color = text_color;
    HyperTextParser::parseElements(replacement.hyper_text, replacement.elements, replacement.plain_text);
    *this = std::move(replacement);
}

std::string SphereUI::detail::escapeHyperText(std::string_view text) {
        std::string output;
        for (char character : text) {
            if (character == '<') output += "\\[";
            else if (character == '>') output += "\\]";
            else {
                if (character == '"' || character == '\\') output += '\\';
                output += character;
            }
        }
        return output;
    }

void SphereUI::detail::serializeHyperTextElements(std::span<const HyperTextRun> elements, std::string& hyper_text, std::string& plain) {
    std::string raw, visible;
    for (const auto& element : elements) {
        if (element.isWrap()) raw += element.text;
        else {
            if (const auto* link = element.link()) raw += "<l " + link->parameters + ">";
            raw += escapeHyperText(element.text);
            if (element.link() != nullptr) raw += "</l>";
        }
        visible += element.text;
    }
    hyper_text = std::move(raw);
    plain = std::move(visible);
}

void SphereUI::Runtime::setTextInputActive(bool active) {
    g_sfera_texture_cache_runtime.render_gate = active ? 1u : 0u;
}

void SphereUI::Runtime::broadcastMessage(Window* root, int group, SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second, SphereUI::UiControlKind kind) {
    if (root != nullptr) {
        root->dispatchMessage(group, message, first, second, kind);
        return;
    }
    for (const auto& window : g_sfera_interface.windows) if (window != nullptr) window->dispatchMessage(group, message, first, second, kind);
}

namespace {
    struct UiKeyBinding {
        const char* name;
        std::uint32_t code;
        std::uint32_t scan;
    };

    constexpr UiKeyBinding uiKeyBindings[] = { {
        "ESCAPE", VK_ESCAPE, 1u
    }, {"SCRL_LOCK", VK_SCROLL, 70u}, {"PAUSE", VK_PAUSE, 197u}, {"BACKSPACE", VK_BACK, 14u}, {"SPACE", VK_SPACE, 57u}, {"END", VK_END, 207u}, {"HOME", VK_HOME, 199u}, {"LEFT", VK_LEFT, 203u}, {"UP", VK_UP, 200u}, {"RIGHT", VK_RIGHT, 205u}, {"DOWN", VK_DOWN, 208u}, {"INSERT", VK_INSERT, 210u}, {"DELETE", VK_DELETE, 211u}, {"ENTER", VK_RETURN, 28u}, {"CAPSLOCK", VK_CAPITAL, 58u}, {"NUMPADMULT", VK_MULTIPLY, 55u}, {"NUMPADADD", VK_ADD, 78u}, {"NUMLOCK", VK_NUMLOCK, 69u}, {"NUMPADSUBT", VK_SUBTRACT, 74u}, {"NUMPADDIV", VK_DIVIDE, 181u}, {"NUMPADPNT", VK_DECIMAL, 83u}, {"PAGEUP", VK_PRIOR, 201u}, {"PAGEDOWN", VK_NEXT, 209u}, {"`", VK_OEM_3, 41u}, {"-", VK_OEM_MINUS, 12u}, {"=", VK_OEM_PLUS, 13u}, {"\\", VK_OEM_5, 43u}, {"[", VK_OEM_4, 26u}, {"]", VK_OEM_6, 27u}, {";", VK_OEM_1, 39u}, {"'", VK_OEM_7, 40u}, {",", VK_OEM_COMMA, 51u}, {".", VK_OEM_PERIOD, 52u}, {"/", VK_OEM_2, 53u}, {"TAB", VK_TAB, 15u}, {"CTRL", VK_CONTROL, 29u}, {"SHIFT", VK_SHIFT, 42u}};
    const char* uiKeyName(std::uint32_t code) {
        static const auto names = [] {
            std::array<std::array<char, 12>, 256> result{};
            for (const auto& binding : uiKeyBindings) SphereUI::detail::copyText(result[binding.code], binding.name);
            for (std::size_t value = '0'; value <= 'Z'; ++value) if (value <= '9' || value >= 'A') result[value][0] = value;
            for (std::size_t index = 0u; index != 12u; ++index) std::snprintf(result[VK_F1 + index].data(), result[VK_F1 + index].size(), "F%zu", index + 1u);
            for (std::size_t index = 0u; index != 10u; ++index) std::snprintf(result[VK_NUMPAD0 + index].data(), result[VK_NUMPAD0 + index].size(), "NUMPAD%zu", index);
            return result;
        }();
        return code < names.size() && names[code][0] != '\0' ? names[code].data() : nullptr;
    }

    std::uint32_t uiScanCode(std::uint32_t key) {
        if (key >= VK_F1 && key <= VK_F10) return 59u + key - VK_F1;
        if (key == VK_F11 || key == VK_F12) return 87u + key - VK_F11;
        if (key >= '1' && key <= '9') return 2u + key - '1';
        if (key == '0') return 11u;
        if (key == VK_NUMPAD0) return 82u;
        if (key >= VK_NUMPAD1 && key <= VK_NUMPAD9) {
            const auto digit = key - VK_NUMPAD0;
            return 83u - 4u * ((digit + 2u) / 3u) + ((digit - 1u) % 3u);
        }
        struct Row {
            const char* keys;
            std::uint32_t first_scan;
        };

        static constexpr Row rows[] = { {
            "QWERTYUIOP", 16u
        }, {"ASDFGHJKL", 30u}, {"ZXCVBNM", 44u}};
        for (const auto& row : rows) if (const auto* position = std::strchr(row.keys, static_cast<int>(key))) return row.first_scan + static_cast<std::uint32_t>(position - row.keys);
        for (const auto& binding : uiKeyBindings) if (binding.code == key) return binding.scan;
        return 0u;
    }

    std::uint32_t uiVirtualKey(std::uint32_t scan) {
        for (std::size_t key = 0u; key <= 255u; ++key) if (uiScanCode(key) == scan) return key;
        return 0u;
    }

    std::uint32_t soundVolume() {
        return g_sfera_sound_runtime.soundVolume();
    }

    void setSoundVolume(std::uint32_t value) {
        g_sfera_sound_runtime.setSoundVolume(value);
    }

    void setMusicVolume(std::uint32_t value) {
        g_sfera_sound_runtime.setMusicVolume(value);
    }

    void playUiSound(const char* filename) {
        g_sfera_sound_runtime.playUiSound(filename);
    }
}

std::uint64_t SphereUI::Runtime::clockTicks() {
    auto& clock = g_sfera_high_resolution_clock_runtime;
    if (!clock.initialized) {
        LARGE_INTEGER frequency{}, anchor{};
        ::QueryPerformanceFrequency(&frequency);
        std::uint64_t normalized = frequency.QuadPart;
        clock.frequency_shift = 0u;
        while (normalized > 2000000u) {
            normalized >>= 1u;
            ++clock.frequency_shift;
        }
        clock.performance_frequency = normalized;
        ::QueryPerformanceCounter(&anchor);
        clock.counter_anchor = anchor.QuadPart;
        clock.initialized = true;
    }
    LARGE_INTEGER now{};
    ::QueryPerformanceCounter(&now);
    const auto anchor = clock.counter_anchor;
    const std::uint64_t delta = static_cast<std::int64_t>(static_cast<std::uint64_t>(now.QuadPart) - anchor) >> clock.frequency_shift;
    auto elapsed = clock.elapsed_counter + delta;
    clock.counter_anchor = anchor + (delta << clock.frequency_shift);
    const auto frequency = clock.performance_frequency;
    if (frequency == 0u) return 0u;
    auto epoch = clock.epoch_microseconds;
    const auto epoch_ticks = frequency * 1000u;
    if (elapsed > epoch_ticks) {
        const auto epochs = (elapsed - 1u) / epoch_ticks;
        elapsed -= epochs * epoch_ticks;
        epoch += epochs * 1000000000u;
    }
    clock.elapsed_counter = elapsed;
    clock.epoch_microseconds = epoch;
    return (epoch + elapsed * 1000000u / frequency) / 100u;
}

std::uint32_t SphereUI::Runtime::keyCode(const char* name) {
    if (name == nullptr) return 0u;
    for (std::size_t code = 0u; code <= 255u; ++code) if (const auto* candidate = uiKeyName(code); candidate != nullptr && SferaSimpleParser::equalsIgnoreCase(name, candidate)) return code;
    return 0u;
}

void SphereUI::Runtime::playClickSound() {
    playUiSound("Sounds\\in_click.wav");
}

void SphereUI::Runtime::playScrollSound(bool page) {
    playUiSound(page ? "Sounds\\in_page.wav" : "Sounds\\in_line.wav");
}

void SphereUI::Runtime::playLinkSound() {
    playUiSound("Sounds\\in_link.wav");
}

void SphereUI::Runtime::playWindowSound(bool opening) {
    playUiSound(opening ? "Sounds\\in_winopen.wav" : "Sounds\\in_winclose.wav");
}

std::uint32_t SphereUI::Runtime::milliseconds() {
    return ::GetTickCount();
}

bool SphereUI::Runtime::keyDown(std::uint32_t key) {
    return key < 256u && g_sfera_direct_input_runtime.keyboard_state[key] != 0u;
}

bool SphereUI::Runtime::descriptionAutoPopup() {
    return g_sfera_interface_runtime.description_auto_popup;
}

SphereUI::CDescriptionWindow* SphereUI::Runtime::descriptionWindow() {
    return g_sfera_interface_runtime.description_control;
}

void SphereUI::Runtime::setDescriptionWindow(CDescriptionWindow* window) {
    g_sfera_interface_runtime.description_control = window;
}

bool SphereUI::Runtime::playerHeading(float& heading) {
    const auto handle = g_sfera_world_objects.controlled_object_handle;
    if (static_cast<int>(handle) <= 0) return false;
    const auto* object = g_sfera_world_objects.effectObject(handle);
    if (object == nullptr) return false;
    heading = object->rotation.x;
    return true;
}

void SphereUI::Runtime::openExternalLink(const char* target, bool mail) {
    if (target == nullptr) return;
    ::ShellExecuteA(nullptr, "open", mail ? target : "explorer", mail ? nullptr : target, nullptr, SW_SHOWNORMAL);
    ::ShowWindow(g_sfera_window_runtime.main_window_handle, SW_MINIMIZE);
}

void SphereUI::Runtime::clipboardText(std::string& result) {
    result.assign("");
    if (!::IsClipboardFormatAvailable(CF_TEXT) || !::OpenClipboard(nullptr)) return;
    const auto handle = ::GetClipboardData(CF_TEXT);
    const auto* text = handle == nullptr ? nullptr : static_cast<const char*>(::GlobalLock(handle));
    try {
        if (text != nullptr) result.assign(text);
    } catch (...) {
        if (text != nullptr) ::GlobalUnlock(handle);
        ::CloseClipboard();
        throw;
    }
    if (text != nullptr) ::GlobalUnlock(handle);
    ::CloseClipboard();
}

namespace {
    constexpr std::uint32_t uiWhite = SferaColor::rgba(255u, 255u, 255u).argb();
    constexpr std::uint32_t uiInvalidTexture = std::numeric_limits<std::uint32_t>::max();

}

int SphereUI::Runtime::findImage(const char* name) {
    return g_sfera_textures.find(name);
}

SphereUI::TextExtent SphereUI::Runtime::screenSize() {
    return {g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height};
}

namespace SphereUI::Runtime {
    void invokeEventHandler(WindowEventHandler handler, Window* window, const WindowEvent& event);
}

namespace {
    using namespace SphereUI;

    void queueInterfaceRefresh() {
        g_sfera_interface.queueEvent({nullptr, 0u, UiMessage::refreshInterface, 0u, 0u});
    }

    Window* optionChild(Window* window, std::uint32_t index) {
        return window == nullptr ? nullptr : window->controlAt(index);
    }

    void optionMessage(Window* window, std::uint32_t index, SphereUI::UiMessage message, std::uintptr_t first = 0u, std::uintptr_t second = 0u) {
        if (auto* child = optionChild(window, index)) child->handleMessage(message, first, second);
    }

    void optionText(Window* window, std::uint32_t index, const char* text) {
        if (auto* child = optionChild(window, index)) child->setText(text);
    }

    void optionLabel(Window* window, std::uint32_t index, const char* key) {
        optionText(window, index, g_sfera_interface.localizedText(key));
    }

    void optionToggleLabel(Window* window, std::uint32_t index, std::uint32_t value) {
        optionLabel(window, index, value != 0u ? "UISTR_WT_OPT16" : "UISTR_WT_OPT17");
    }

    void setOptionsVisible(bool show);
    void setInterfaceOptionsVisible(bool show);
    void setGraphicsOptionsVisible(bool show);
    void setFontOptionsVisible(bool show);
    Window* beginOptionsDialog(const char* name, WindowEventHandler handler, bool show) {
        auto* window = g_sfera_interface.findWindow(name);
        if (!show) {
            if (window != nullptr) {
                g_sfera_interface.closeWindow(window);
            }
            return window;
        }
        if (window != nullptr) return nullptr;
        setOptionsVisible(false);
        window = g_sfera_interface.openWindow(name);
        if (window != nullptr) g_sfera_interface.bindEventHandler(window, handler);
        return window;
    }

    void setOptionsVisible(bool show) {
        auto* window = g_sfera_interface.findWindow("options");
        if (show) {
            if (window == nullptr) if (auto* created = g_sfera_interface.openWindow("options")) g_sfera_interface.bindEventHandler(created, WindowEventHandler::options);
        } else if (window != nullptr) g_sfera_interface.closeWindow(window);
    }

    void setSoundOptionsVisible(bool show) {
        auto* window = beginOptionsDialog("sound_options", WindowEventHandler::sound_options, show);
        if (window == nullptr) return;
        auto& saved_music = g_sfera_sphere_options_runtime.saved_music_volume;
        auto& saved_sound = g_sfera_options_dialog_runtime.audio_settings;
        auto& values = g_sfera_graphics_options_runtime.graphics_values;
        if (show) {
            saved_music = g_sfera_sound_runtime.musicVolume();
            saved_sound = soundVolume();
            optionMessage(window, 7u, UiMessage::setScrollRange, 0u, 100u);
            optionMessage(window, 8u, UiMessage::setScrollRange, 0u, 100u);
            optionMessage(window, 7u, UiMessage::setScrollValue, saved_music);
            optionMessage(window, 8u, UiMessage::setScrollValue, saved_sound);
            values[7] = g_sfera_sound_runtime.hardwareMixing();
            values[12] = values[7];
            optionLabel(window, 9u, values[12] != 0u ? "UISTR_WT_OPT34" : "UISTR_WT_OPT33");
            return;
        }
        setMusicVolume(saved_music);
        setSoundVolume(saved_sound);
        setOptionsVisible(true);
        g_sfera_sound_runtime.setHardwareMixing(values[7] != 0u);
        InterfaceConfiguration::open("config.cfg");
        InterfaceConfiguration::writeInteger("SNDVOL", saved_sound);
        InterfaceConfiguration::writeInteger("MUSVOL", saved_music);
        InterfaceConfiguration::writeInteger("HWMIX", values[7]);
        InterfaceConfiguration::save();
    }

    std::uint32_t bindingCount() {
        return g_sfera_mbc_runtime.namedValue("SSKS_NUMBER");
    }

    const char* bindingName(std::uint32_t key) {
        const auto* name = uiKeyName(key);
        return name == nullptr ? "???" : name;
    }

    Window* bindingRow(Window* window, std::uint32_t slot) {
        auto* list = optionChild(window, 5u);
        return list == nullptr || list->control_kind != UiControlKind::listItem ? nullptr : static_cast<ListItemCtrl*>(list)->itemAt(slot);
    }

    void refreshBindingLabel(Window* window, std::uint32_t slot) {
        optionText(bindingRow(window, slot), 3u, bindingName(g_sfera_control_options.working_bindings[slot]));
    }

    void refreshMouseBindingLabel(Window* window) {
        optionLabel(window, 4u, g_sfera_graphics_options_runtime.dialog_state == 0u ? "UISTR_WT_OPT23" : "UISTR_WT_OPT24");
    }

    bool availableBinding(std::uint32_t key) {
        const auto count = bindingCount();
        for (std::size_t slot = 0u; slot < count; ++slot) if (g_sfera_control_options.working_bindings[slot] == key) return false;
        return key != 0u && key != VK_ESCAPE && key != VK_F1 && key != VK_RETURN && key - '0' > 9u && key != VK_SHIFT && key != VK_CONTROL && key - VK_LEFT > 3u;
    }

    void setControlOptionsVisible(bool show) {
        auto* window = beginOptionsDialog("control_options", WindowEventHandler::control_options, show);
        if (window == nullptr) return;
        auto& state = g_sfera_control_options;
        const auto count = bindingCount();
        if (show) {
            std::fill(std::begin(state.configured_bindings), std::end(state.configured_bindings), 0u);
            for (std::size_t slot = 0u; slot < std::max(5u, count); ++slot) {
                const auto key = g_sfera_mbc_runtime.namedValue("SSKS", slot);
                state.configured_bindings[slot] = slot < 5u ? uiVirtualKey(key) : key;
            }
            state.configured_bindings[63] = g_sfera_mbc_runtime.namedValue("INMS");
            std::copy(std::begin(state.configured_bindings), std::end(state.configured_bindings), std::begin(state.working_bindings));
            optionLabel(window, 4u, state.configured_bindings[63] == 0u ? "UISTR_WT_OPT23" : "UISTR_WT_OPT24");
            for (std::size_t slot = 0u; slot < count; ++slot) {
                optionMessage(window, 5u, UiMessage::appendListItem);
                std::snprintf(g_sfera_options_dialog_runtime.widget_key_name, sizeof(g_sfera_options_dialog_runtime.widget_key_name), "UISTR_WT_KEY%02zu", slot + 1u);
                optionLabel(bindingRow(window, slot), 2u, g_sfera_options_dialog_runtime.widget_key_name);
                refreshBindingLabel(window, slot);
            }
            g_sfera_options_dialog_runtime.widget_keys_initialized = true;
            return;
        }
        setOptionsVisible(true);
        g_sfera_mbc_runtime.setNamedValue("INMS", state.configured_bindings[63]);
        for (std::size_t slot = 0u; slot < std::max(5u, count); ++slot) g_sfera_mbc_runtime.setNamedValue("SSKS", slot < 5u ? uiScanCode(state.configured_bindings[slot]) : state.configured_bindings[slot], slot);
        queueInterfaceRefresh();
        g_sfera_options_dialog_runtime.widget_keys_initialized = false;
    }

    constexpr std::uint32_t interfaceControlIds[] = {7u, 8u, 9u, 11u, 12u, 15u, 16u, 19u, 21u};
    constexpr const char* interfaceSettingKeys[] = {"ISSN", "ISAD", "INSN", "INAW", "IAPM", "MBST", "BALR"};
    void setInterfaceOptionsVisible(bool show) {
        auto* window = beginOptionsDialog("interface_options", WindowEventHandler::interface_options, show);
        if (window == nullptr) return;
        auto& state = g_sfera_graphics_options_runtime;
        if (show) {
            for (std::size_t index = 0u; index < 5u; ++index) state.saved_interface_values[index] = index == 2u ? g_sfera_interface_runtime.sounds_enabled : g_sfera_mbc_runtime.namedValue(interfaceSettingKeys[index]);
            InterfaceConfiguration::open("config.cfg");
            state.saved_interface_values[5] = InterfaceConfiguration::readInteger("MBST", state.saved_interface_values[5]);
            state.saved_interface_values[6] = missingConfigValue;
            state.saved_interface_values[6] = InterfaceConfiguration::readInteger("BALR", state.saved_interface_values[6]);
            if (static_cast<int>(state.saved_interface_values[6]) < 0) {
                state.saved_interface_values[6] = 1u;
                InterfaceConfiguration::writeInteger("BALR", 1u);
                InterfaceConfiguration::save();
            }
            state.saved_interface_values[7] = g_sfera_interface_runtime.description_auto_popup;
            state.saved_interface_values[8] = g_sfera_interface_runtime.invite_messages;
            std::copy(std::begin(state.saved_interface_values), std::end(state.saved_interface_values), std::begin(state.interface_values));
            for (std::size_t index = 0u; index < std::size(interfaceControlIds); ++index) optionToggleLabel(window, interfaceControlIds[index], state.interface_values[index]);
            return;
        }
        setOptionsVisible(true);
        for (std::size_t index = 0u; index < std::size(interfaceSettingKeys); ++index) g_sfera_mbc_runtime.setNamedValue(interfaceSettingKeys[index], state.saved_interface_values[index]);
        g_sfera_interface_runtime.description_auto_popup = state.saved_interface_values[7];
        g_sfera_interface_runtime.invite_messages = state.saved_interface_values[8];
        InterfaceConfiguration::open("config.cfg");
        InterfaceConfiguration::writeInteger("MBST", state.saved_interface_values[5]);
        InterfaceConfiguration::writeInteger("BALR", state.saved_interface_values[6]);
        InterfaceConfiguration::writeInteger("HARDWARE_CURSOR", g_sfera_graphics_runtime.hardware_cursor_enabled);
        InterfaceConfiguration::writeInteger("DESCR_AUTO_POPUP", g_sfera_interface_runtime.description_auto_popup);
        InterfaceConfiguration::writeInteger("INVITE_MESSAGES", g_sfera_interface_runtime.invite_messages);
        InterfaceConfiguration::save();
        g_sfera_interface_runtime.sounds_enabled = state.saved_interface_values[2];
        queueInterfaceRefresh();
        g_sfera_interface_runtime.cross_enabled = state.saved_interface_values[3];
    }

    void resetSavedWindowPositions() {
        g_sfera_interface.saved_positions.clear();
        for (const auto& window : g_sfera_interface.windows) if (window != nullptr && window->save_last_position) window->alignToScreen(true);
    }

    std::vector<std::uint32_t>& savedChatFonts() {
        return g_sfera_options_dialog_runtime.saved_chat_fonts;
    }

    std::vector<std::uint32_t>& editedChatFonts() {
        return g_sfera_options_dialog_runtime.edited_chat_fonts;
    }

    void setFontOptionsVisible(bool show) {
        auto* window = g_sfera_interface.findWindow("font_options");
        if (show) {
            if (window != nullptr) return;
            setInterfaceOptionsVisible(false);
            setOptionsVisible(false);
            window = g_sfera_interface.openWindow("font_options");
            if (window == nullptr) return;
            g_sfera_interface.bindEventHandler(window, WindowEventHandler::font_options);
            auto& saved = savedChatFonts();
            auto& edited = editedChatFonts();
            saved.reserve(2u);
            edited.reserve(2u);
            saved.push_back(4u);
            saved.push_back(4u);
            InterfaceConfiguration::open("config.cfg");
            saved.at(0u) = InterfaceConfiguration::readInteger("CHAT_LIST_FONT", saved.at(0u));
            saved.at(1u) = InterfaceConfiguration::readInteger("CHAT_EDIT_FONT", saved.at(1u));
            for (std::size_t index = 0u; index < 2u; ++index) if (auto* control = optionChild(window, index + 3u)) control->setFont(saved.at(index));
            edited = saved;
            return;
        }
        if (window == nullptr) return;
        g_sfera_interface.closeWindow(window);
        setInterfaceOptionsVisible(true);
        InterfaceConfiguration::open("config.cfg");
        InterfaceConfiguration::writeInteger("CHAT_LIST_FONT", savedChatFonts().at(0u));
        InterfaceConfiguration::writeInteger("CHAT_EDIT_FONT", savedChatFonts().at(1u));
        InterfaceConfiguration::save();
        queueInterfaceRefresh();
    }
}

namespace {
    using OptionsDisplayMode = SphereUI::DisplayMode;

    std::uint32_t findOptionsMode(const OptionsDisplayMode& requested) {
        const std::uint32_t count = g_sfera_graphics_runtime.d3d_runtime->display_modes.size();
        for (std::size_t index = 0u; index < count; ++index) {
            const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index);
            if (mode.width == requested.width && mode.height == requested.height && mode.depth == requested.depth) return index;
        }
        for (std::size_t index = count; index != 0u; --index) {
            const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index - 1u);
            if (mode.depth == requested.depth && mode.width <= g_sfera_scene_control_runtime.timing_anchor && mode.height <= g_sfera_recovered_static_runtime.scene_state_07) return index - 1u;
        }
        return count - 1u;
    }

    void setOptionsModeLabel(Window* window, std::uint32_t index) {
        const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index);
        const auto text = std::to_string(static_cast<int>(mode.width)) + "x" + std::to_string(static_cast<int>(mode.height)) + " " + std::to_string(static_cast<int>(mode.depth));
        optionText(window, 7u, text.c_str());
    }

    const char* graphicsBooleanLabel(std::uint32_t value) {
        return value < 2u ? g_sfera_sphere_options_runtime.option_labels[5u + value] : g_sfera_options_dialog_runtime.graphics_unknown_label;
    }

    void optionSelection(Window* window, std::uint32_t index, std::uint32_t maximum, std::uint32_t value) {
        optionMessage(window, index, UiMessage::setSpinRange, 0u, maximum);
        optionMessage(window, index, UiMessage::setSpinValue, value);
    }

    void setupLodOptions(Window* window) {
        const auto enabled = g_sfera_graphics_runtime.lods_enabled;
        optionToggleLabel(window, 41u, enabled);
        optionSelection(window, 43u, 1u, enabled);
        optionMessage(window, 46u, UiMessage::setScrollRange, 0u, enabled ? 14u : 0u);
        if (enabled) optionMessage(window, 46u, UiMessage::setScrollValue, static_cast<std::uint32_t>(static_cast<std::int64_t>(std::trunc(g_sfera_input_device_runtime.lod_distance - 12.0))));
    }

    void setupFogOptions(Window* window) {
        const auto automatic = g_sfera_client_config_runtime.auto_fog;
        optionToggleLabel(window, 37u, automatic);
        optionSelection(window, 39u, 1u, automatic);
        optionMessage(window, 28u, UiMessage::setScrollRange, 0u, automatic ? 0u : 170u);
        if (!automatic) optionMessage(window, 28u, UiMessage::setScrollValue, static_cast<std::uint32_t>(static_cast<std::int64_t>(std::trunc(g_sfera_graphics_runtime.fog_distance - 30.0))));
    }

    void setGraphicsOptionsVisible(bool show) {
        auto* window = beginOptionsDialog("gfx_options", WindowEventHandler::graphics_options, show);
        if (window == nullptr) return;
        auto& values = g_sfera_graphics_options_runtime.graphics_values;
        auto& state = g_sfera_options_dialog_runtime;
        auto& graphics = g_sfera_graphics_runtime;
        auto* shadows = g_sfera_shadows.get();
        if (shadows == nullptr) throw std::runtime_error("Shadow manager is unavailable");
        if (show) {
            g_sfera_sphere_options_runtime.saved_fog_distance = graphics.fog_distance;
            g_sfera_sphere_options_runtime.saved_lod_distance = g_sfera_input_device_runtime.lod_distance;
            g_sfera_sphere_options_runtime.saved_lods_enabled = graphics.lods_enabled;
            values[9] = g_sfera_client_config_runtime.auto_fog;
            values[8] = g_sfera_client_config_runtime.effects_enabled;
            g_sfera_graphics_options_runtime.graphics_page = state.reflection_quality;
            constexpr const char* label_keys[] = {"UISTR_WT_OPT21", "UISTR_WT_OPT20", "UISTR_WT_OPT19", "UISTR_WT_OPT18", "UISTR_WT_OPT17", "UISTR_WT_OPT17", "UISTR_WT_OPT16"};
            for (std::size_t index = 0u; index < std::size(label_keys); ++index) detail::copyText(g_sfera_sphere_options_runtime.option_labels[index], g_sfera_interface.localizedText(label_keys[index]));
            detail::copyText(state.graphics_unknown_label, g_sfera_interface.localizedText("UISTR_WT_OPT36"));
            InterfaceConfiguration::open("config.cfg");
            OptionsDisplayMode mode{static_cast<unsigned int>(graphics.display_width), static_cast<unsigned int>(graphics.display_height), g_sfera_graphics_display_depth_bits};
            mode.width = InterfaceConfiguration::readInteger("XRES", mode.width);
            mode.height = InterfaceConfiguration::readInteger("YRES", mode.height);
            g_sfera_graphics_runtime.d3d_runtime->enumerateDisplayModes(g_sfera_window_runtime.windowed);
            values[5] = findOptionsMode(mode);
            values[1] = mode.depth;
            values[2] = shadows->quality;
            values[3] = g_sfera_main_render_runtime.grass_depth_mode;
            values[4] = g_sfera_window_runtime.windowed;
            values[6] = graphics.post_effects_enabled;
            values[10] = values[0];
            values[11] = mode.depth;
            state.comparison_graphics_value = values[4];
            optionSelection(window, 15u, static_cast<std::uint32_t>(g_sfera_graphics_runtime.d3d_runtime->display_modes.size()) - 1u, values[5]);
            optionSelection(window, 17u, 4u, values[2]);
            optionSelection(window, 18u, 2u, values[3]);
            optionMessage(window, 26u, UiMessage::setSpinRange, 0u, 1u);
            optionToggleLabel(window, 31u, !g_sfera_client_config_runtime.effects_enabled);
            optionMessage(window, 26u, UiMessage::setSpinValue, !g_sfera_client_config_runtime.effects_enabled);
            setupLodOptions(window);
            setOptionsModeLabel(window, values[5]);
            optionText(window, 9u, g_sfera_sphere_options_runtime.option_labels[values[2]]);
            optionText(window, 10u, graphicsBooleanLabel(values[3]));
            setupFogOptions(window);
            optionSelection(window, 24u, 3u, state.reflection_quality);
            optionText(window, 22u, g_sfera_sphere_options_runtime.option_labels[4u - state.reflection_quality]);
            optionMessage(window, 34u, UiMessage::setSpinRange, 0u, 1u);
            optionLabel(window, 35u, values[4] != 0u ? "UISTR_WT_OPT61" : "UISTR_WT_OPT62");
            optionMessage(window, 34u, UiMessage::setSpinValue, values[4] == 0u);
            const auto* features = graphics.d3d_runtime.get();
            const bool post_supported = features != nullptr && features->supports_post_effects;
            if (!post_supported) values[6] = state.graphics_snapshot[6] = graphics.post_effects_enabled = false;
            optionSelection(window, 51u, post_supported ? 1u : 0u, values[6]);
            optionText(window, 49u, graphicsBooleanLabel(values[6]));
            std::copy_n(values, 7u, state.graphics_snapshot);
            return;
        }
        setOptionsVisible(true);
        shadows->quality = values[2];
        g_sfera_main_render_runtime.grass_depth_mode = values[3];
        g_sfera_window_runtime.windowed = values[4];
        InterfaceConfiguration::open("config.cfg");
        const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(values[5]);
        const std::pair<const char*, std::uint32_t> settings[] = { {
            "XRES", mode.width
        }, {"YRES", mode.height}, {"DEPTH", mode.depth}, {"GRASS", values[3]}, {"WINDOWED", values[4]}, {"SHAD", values[2]}, {"AUTOFOG", g_sfera_client_config_runtime.auto_fog}, {"FOGDIST", static_cast<std::uint32_t>(static_cast<int>(std::trunc(graphics.fog_distance)))}, {"REFLQUAL", state.reflection_quality}, {"EFFECTS", g_sfera_client_config_runtime.effects_enabled}, {"LODS", graphics.lods_enabled}, {"LOD_DISTANCE", static_cast<std::uint32_t>(static_cast<int>(std::trunc(g_sfera_input_device_runtime.minimum_lod_distance)))}, {"MIN_LOD_DIST", static_cast<std::uint32_t>(static_cast<int>(std::trunc(g_sfera_input_device_runtime.lod_distance)))}, {"POSTEFFECTS", values[6]}};
        for (const auto& setting : settings) InterfaceConfiguration::writeInteger(setting.first, setting.second);
        g_sfera_effect_manager.effects_enabled = g_sfera_client_config_runtime.effects_enabled;
        InterfaceConfiguration::save();
        if (values[10] != values[0] || values[11] != values[1] || state.comparison_graphics_value != values[4])
            g_sfera_render_lookup_runtime.quit_requested = true;
    }

    void handleHelpEvent(Window* window, const WindowEvent& event) {
        if (event.message == UiMessage::close) {
            g_sfera_interface.showHelpPage(nullptr);
            return;
        }
        if (event.message == UiMessage::leftClick) {
            if (event.control_id == 1u) g_sfera_interface.showHelpPage("Language\\helpindex.hts");
            else if (event.control_id == 2u) optionMessage(window, 3u, UiMessage::previousHyperTextPage);
            return;
        }
        if (event.message != UiMessage::hyperTextPageChanged) return;
        auto* control = static_cast<HyperTextCtrl*>(event.source);
        if (control == nullptr) return;
        const auto* document = control->document.get();
        const auto* name = document == nullptr ? nullptr : document->name.c_str();
        if (name != nullptr && SferaSimpleParser::equalsIgnoreCase(name, "Language\\helpindex.hts")) control->handleMessage(UiMessage::clearHyperTextHistory, 0u, 0u);
        optionMessage(window, 2u, UiMessage::setEnabled, control->history.size() == 0u ? 0u : 1u);
    }

    void handleSoundOptionsEvent(Window* window, const WindowEvent& event) {
        if (event.message == UiMessage::horizontalScroll) {
            if (event.control_id == 7u) setMusicVolume(event.first);
            else setSoundVolume(event.first);
            return;
        }
        if (event.message == UiMessage::close) {
            setSoundOptionsVisible(false);
            return;
        }
        if (event.message != UiMessage::leftClick) return;
        if (event.control_id == 1u) {
            optionMessage(window, 7u, UiMessage::getScrollValue, reinterpret_cast<std::uintptr_t>(&g_sfera_sphere_options_runtime.saved_music_volume));
            optionMessage(window, 8u, UiMessage::getScrollValue, reinterpret_cast<std::uintptr_t>(&g_sfera_options_dialog_runtime.audio_settings));
            g_sfera_graphics_options_runtime.graphics_values[7] = g_sfera_graphics_options_runtime.graphics_values[12];
        }
        if (event.control_id == 1u || event.control_id == 2u) setSoundOptionsVisible(false);
        else if (event.control_id == 9u) {
            auto& mixing = g_sfera_graphics_options_runtime.graphics_values[12];
            mixing = mixing == 0u;
            optionLabel(window, 9u, mixing != 0u ? "UISTR_WT_OPT34" : "UISTR_WT_OPT33");
        }
    }

    void handleControlOptionsEvent(Window* window, const WindowEvent& event) {
        auto& state = g_sfera_control_options;
        if (event.message == UiMessage::close) {
            setControlOptionsVisible(false);
            return;
        }
        if (event.message == UiMessage::controlBindingCaptured) {
            if (state.active_slot == invalidIndex) return;
            g_sfera_client_process_runtime.ui_bridge = 0u;
            g_sfera_interface.capture_control_binding = false;
            g_sfera_main_command_state_runtime.command_state = 0u;
            auto* current = g_sfera_interface.findWindow("control_options");
            if (current == nullptr) return;
            if (availableBinding(event.first)) state.working_bindings[state.active_slot] = event.first;
            refreshBindingLabel(current, state.active_slot);
            return;
        }
        if (event.message == UiMessage::listItemEvent && static_cast<UiMessage>(event.first) == UiMessage::leftClick && HIWORD(event.second) == 3u) {
            state.active_slot = LOWORD(event.second);
            optionText(bindingRow(window, state.active_slot), 3u, "");
            g_sfera_client_process_runtime.ui_bridge = 1u;
            g_sfera_interface.capture_control_binding = true;
            g_sfera_main_command_state_runtime.command_state = 0u;
            return;
        }
        if (event.message != UiMessage::leftClick) return;
        if (event.control_id == 1u) std::copy(std::begin(state.working_bindings), std::end(state.working_bindings), std::begin(state.configured_bindings));
        if (event.control_id == 1u || event.control_id == 2u) {
            setControlOptionsVisible(false);
            return;
        }
        if (event.control_id == 4u) {
            auto& mode = g_sfera_graphics_options_runtime.dialog_state;
            mode = mode == 0u;
            refreshMouseBindingLabel(window);
        } else if (event.control_id == 6u) {
            constexpr std::uint32_t defaults[] = {'W', 'S', 'A', 'D', VK_SPACE, VK_OEM_3, VK_OEM_MINUS, VK_TAB, 'R', 'I', 'K', 'H', 'T', 'N', 'P', 'M', 'J', 'O', 'Y', VK_OEM_2};
            g_sfera_graphics_options_runtime.dialog_state = 0u;
            std::copy(std::begin(defaults), std::end(defaults), std::begin(state.working_bindings));
            optionLabel(window, 4u, state.configured_bindings[63] == 0u ? "UISTR_WT_OPT23" : "UISTR_WT_OPT24");
            for (std::size_t slot = 0u, count = bindingCount(); slot < count; ++slot) refreshBindingLabel(window, slot);
        }
    }

    void handleInterfaceOptionsEvent(Window* window, const WindowEvent& event) {
        auto& state = g_sfera_graphics_options_runtime;
        if (event.message == UiMessage::close) {
            setInterfaceOptionsVisible(false);
            return;
        }
        if (event.message != UiMessage::leftClick) return;
        if (event.control_id == 1u) std::copy(std::begin(state.interface_values), std::end(state.interface_values), std::begin(state.saved_interface_values));
        if (event.control_id == 1u || event.control_id == 2u) {
            setInterfaceOptionsVisible(false);
            return;
        }
        if (event.control_id == 6u) {
            resetSavedWindowPositions();
            return;
        }
        if (event.control_id == 22u) {
            setFontOptionsVisible(true);
            return;
        }
        for (std::size_t index = 0u; index < std::size(interfaceControlIds); ++index) if (event.control_id == interfaceControlIds[index]) {
            auto& value = state.interface_values[index];
            value = value == 0u;
            if (index == 0u) g_sfera_mbc_runtime.setNamedValue(interfaceSettingKeys[index], value);
            if (index == 3u) g_sfera_interface_runtime.cross_enabled = value;
            optionToggleLabel(window, interfaceControlIds[index], value);
            if (index == 2u) g_sfera_interface_runtime.sounds_enabled = value;
            else if (index != 3u) {
                if (index != 0u && index < std::size(interfaceSettingKeys)) g_sfera_mbc_runtime.setNamedValue(interfaceSettingKeys[index], value);
                queueInterfaceRefresh();
            }
            return;
        }
    }

    void handleGraphicsOptionsEvent(Window* window, const WindowEvent& event) {
        auto& state = g_sfera_options_dialog_runtime;
        auto& values = g_sfera_graphics_options_runtime.graphics_values;
        auto& graphics = g_sfera_graphics_runtime;
        if (event.message == UiMessage::close) {
            setGraphicsOptionsVisible(false);
            return;
        }
        if (event.message == UiMessage::leftClick) {
            if (event.control_id == 1u) {
                std::copy_n(state.graphics_snapshot, 7u, values);
                auto* lod = g_sfera_recovered_static_runtime.render_state_08.get();
                if (lod != nullptr) lod->setDistances(g_sfera_input_device_runtime.lod_distance, g_sfera_input_device_runtime.minimum_lod_distance);
                setGraphicsOptionsVisible(false);
            } else if (event.control_id == 2u) {
                setGraphicsOptionsVisible(false);
                graphics.fog_distance = g_sfera_sphere_options_runtime.saved_fog_distance;
                g_sfera_input_device_runtime.lod_distance = g_sfera_sphere_options_runtime.saved_lod_distance;
                g_sfera_client_config_runtime.auto_fog = values[9];
                g_sfera_client_config_runtime.effects_enabled = values[8];
                graphics.lods_enabled = g_sfera_sphere_options_runtime.saved_lods_enabled;
                state.reflection_quality = g_sfera_graphics_options_runtime.graphics_page;
            }
            return;
        }
        if (event.message == UiMessage::spinValueChanged) switch (event.control_id) {
            case 15u:
                state.graphics_snapshot[5] = event.first;
                setOptionsModeLabel(window, event.first);
                break;
            case 17u:
                {
                    state.graphics_snapshot[2] = event.first;
                    auto* shadows = g_sfera_shadows.get();
                    if (shadows != nullptr) shadows->quality = event.first;
                    optionText(window, 9u, g_sfera_sphere_options_runtime.option_labels[event.first]);
                    break;
                }
            case 18u:
                state.graphics_snapshot[3] = event.first;
                g_sfera_main_render_runtime.grass_depth_mode = event.first;
                optionText(window, 10u, graphicsBooleanLabel(event.first));
                break;
            case 24u:
                state.reflection_quality = event.first;
                optionText(window, 22u, g_sfera_sphere_options_runtime.option_labels[4u - event.first]);
                break;
            case 26u:
                g_sfera_client_config_runtime.effects_enabled = event.first == 0u;
                optionText(window, 31u, event.first < 2u ? "" : graphicsBooleanLabel(event.first));
                break;
            case 34u:
                {
                    state.graphics_snapshot[4] = event.first != 1u;
                    optionLabel(window, 35u, state.graphics_snapshot[4] == 1u ? "UISTR_WT_OPT61" : "UISTR_WT_OPT62");
                    const auto selected = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(state.graphics_snapshot[5]);
                    g_sfera_graphics_runtime.d3d_runtime->enumerateDisplayModes(state.graphics_snapshot[4] == 1u);
                    state.graphics_snapshot[5] = findOptionsMode(selected);
                    optionSelection(window, 15u, static_cast<std::uint32_t>(g_sfera_graphics_runtime.d3d_runtime->display_modes.size()) - 1u, state.graphics_snapshot[5]);
                    setOptionsModeLabel(window, state.graphics_snapshot[5]);
                    state.graphics_snapshot[0] = 0u;
                    break;
                }
            case 39u:
                {
                    const bool automatic = event.first == 1u;
                    optionToggleLabel(window, 37u, automatic);
                    optionMessage(window, 28u, UiMessage::setScrollRange, 0u, automatic ? 0u : 170u);
                    if (automatic) graphics.saved_fog_distance = graphics.fog_distance;
                    else {
                        graphics.fog_distance = graphics.saved_fog_distance;
                        optionMessage(window, 28u, UiMessage::setScrollValue, static_cast<std::uint32_t>(static_cast<std::int64_t>(std::trunc(graphics.fog_distance - 30.0))));
                    }
                    g_sfera_client_config_runtime.auto_fog = automatic;
                    break;
                }
            case 43u:
                {
                    const bool enabled = event.first == 1u;
                    optionText(window, 41u, enabled ? g_sfera_sphere_options_runtime.option_labels[6] : "");
                    optionMessage(window, 46u, UiMessage::setScrollRange, 0u, enabled ? 14u : 0u);
                    if (enabled) optionMessage(window, 46u, UiMessage::setScrollValue, static_cast<std::uint32_t>(static_cast<std::int64_t>(std::trunc(g_sfera_input_device_runtime.lod_distance - 12.0))));
                    graphics.lods_enabled = enabled;
                    break;
                }
            case 51u:
                state.graphics_snapshot[6] = event.first;
                graphics.post_effects_enabled = event.first;
                optionText(window, 49u, event.first < 2u ? "" : graphicsBooleanLabel(event.first));
                break;
            default:
                break;
        } else if (event.message != UiMessage::horizontalScroll) return;
        if (event.control_id == 28u) graphics.fog_distance = event.first + 30.0;
        else if (event.control_id == 46u) g_sfera_input_device_runtime.lod_distance = event.first + 12.0;
    }

    void handleFontOptionsEvent(const WindowEvent& event) {
        if (event.message == UiMessage::selectedFontChanged) {
            if (event.control_id == 3u || event.control_id == 4u) editedChatFonts().at(event.control_id - 3u) = event.first;
            return;
        }
        if (event.message == UiMessage::leftClick) {
            if (event.control_id == 1u) savedChatFonts() = editedChatFonts();
            else if (event.control_id != 2u) return;
        } else if (event.message != UiMessage::close) return;
        setFontOptionsVisible(false);
    }
}

void SphereUI::Runtime::invokeEventHandler(WindowEventHandler handler, Window* window, const WindowEvent& event) {
    switch (handler) {
        case WindowEventHandler::none:
            return;
        case WindowEventHandler::description:
            if (window != nullptr) static_cast<CDescriptionWindow*>(window)->handleEvent(event);
            return;
        case WindowEventHandler::help:
            handleHelpEvent(window, event);
            return;
        case WindowEventHandler::authors:
            if (event.message == UiMessage::close && beginOptionsDialog("authors", handler, false) != nullptr) setOptionsVisible(true);
            return;
        case WindowEventHandler::quit:
            if (event.message == UiMessage::leftClick && event.control_id == 1u) g_sfera_render_lookup_runtime.quit_requested = true;
            else if (event.message == UiMessage::close && beginOptionsDialog("quit", handler, false) != nullptr) setOptionsVisible(true);
            return;
        case WindowEventHandler::sound_options:
            handleSoundOptionsEvent(window, event);
            return;
        case WindowEventHandler::control_options:
            handleControlOptionsEvent(window, event);
            return;
        case WindowEventHandler::interface_options:
            handleInterfaceOptionsEvent(window, event);
            return;
        case WindowEventHandler::graphics_options:
            handleGraphicsOptionsEvent(window, event);
            return;
        case WindowEventHandler::font_options:
            handleFontOptionsEvent(event);
            return;
        case WindowEventHandler::options:
            if (event.message == UiMessage::close) setOptionsVisible(false);
            else if (event.message == UiMessage::leftClick) switch (event.control_id) {
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
                    beginOptionsDialog("authors", WindowEventHandler::authors, true);
                    break;
                case 8u:
                    beginOptionsDialog("quit", WindowEventHandler::quit, true);
                    break;
                default:
                    break;
            }
            return;
    }
}

namespace {
    constexpr std::string_view numericWhitespace = " \t\n\r\f\v";
    template<class Integer> bool readInteger(std::string_view& input, Integer& output, int base) {
        const auto first = input.find_first_not_of(numericWhitespace);
        if (first == std::string_view::npos) return false;
        auto digits = input.substr(first);
        const bool negative = digits.front() == '-';
        if (negative || digits.front() == '+') digits.remove_prefix(1u);
        const bool hex_prefix = base == 16 && digits.size() >= 2u && digits[0] == '0' && (digits[1] == 'x' || digits[1] == 'X');
        if (hex_prefix) digits.remove_prefix(2u);
        std::uint32_t magnitude = 0u;
        const auto result = std::from_chars(digits.data(), digits.data() + digits.size(), magnitude, base);
        // The legacy hex scanner accepts a bare 0x prefix as zero.
        if (result.ec != std::errc{} && !(hex_prefix && result.ec == std::errc::invalid_argument)) return false;
        const auto limit = static_cast<std::uint32_t>(std::numeric_limits<Integer>::max()) + (std::numeric_limits<Integer>::is_signed && negative ? 1u : 0u);
        if (magnitude > limit) return false;
        output = static_cast<Integer>(negative ? -static_cast<std::int64_t>(magnitude) : static_cast<std::int64_t>(magnitude));
        input.remove_prefix(result.ptr - input.data());
        return true;
    }

    bool readHexColor(const char* text, std::uint32_t& color) {
        std::string_view input(text == nullptr ? "" : text);
        return readInteger(input, color, 16);
    }
    // The legacy message ABI has no destination capacity; callers must reserve strlen(source) + 1 bytes.
    void copyMessageText(char* destination, const char* source) {
        std::copy_n(source, std::char_traits<char>::length(source) + 1u, destination);
    }

    class ViewportScope {
        SphereUI::UiViewport saved{};
        bool changed = false;
        bool restore = true;
    public:
        explicit ViewportScope(const SphereUI::UiRect& bounds, bool restore_viewport = true) : restore(restore_viewport) {
            const auto screen = SphereUI::Runtime::screenSize();
            const auto left = std::max(0, bounds.left), top = std::max(0, bounds.top), right = std::min(screen.width, bounds.right), bottom = std::min(screen.height, bounds.bottom);
            if (right <= left || bottom <= top) return;
            saved = SphereUI::InterfaceRenderer::viewport();
            SphereUI::InterfaceRenderer::setViewport({static_cast<std::uint32_t>(left), static_cast<std::uint32_t>(top), static_cast<std::uint32_t>(right - left), static_cast<std::uint32_t>(bottom - top), 0.0f, 1.0f});
            changed = true;
        }

        ViewportScope(const ViewportScope&) = delete;
        ViewportScope& operator=(const ViewportScope&) = delete;

        ~ViewportScope() {
            if (changed && restore) SphereUI::InterfaceRenderer::setViewport(saved);
        }

        explicit operator bool() const {
            return changed;
        }
    };


    constexpr NamedValue<std::uint32_t> buttonStyles[] = { {
        "LOSTCHECK", ButtonStyle::releaseOutside
    }, {"NOTIFY_LB", ButtonStyle::repeatWhilePressed}, {"SEND_QUIT", ButtonStyle::sendClose}, {"CENTER_TEXT", ButtonStyle::centerText}, {"SEND_HELP", ButtonStyle::showHelp}};
    constexpr NamedValue<std::uint32_t> textAlignments[] = { {
        "RIGHT_X", TextAlignment::right
    }, {"RIGHT_Y", TextAlignment::bottom}, {"CENTER_X", TextAlignment::horizontalCenter}, {"CENTER_Y", TextAlignment::verticalCenter}, {"CENTER", TextAlignment::center}, {"RIGHT", TextAlignment::right | TextAlignment::bottom}};
    constexpr NamedValue<std::uint32_t> imageStyles[] = { {
        "NOTIFY_LB", 1u
    }, {"NOTIFY_FOCUS", 2u}};
    constexpr NamedValue<std::uint32_t> textStyles[] = { {
        "NOTIFY_CLICK", 1u
    }
    };
    class UiReader {
        SferaSimpleParser& parser;
        const SferaParserRange& range;
        SferaParserRange saved_block{};
        std::string buffer;
    public:
        UiReader(SferaSimpleParser& source, const SferaParserRange& scope) : parser(source), range(scope) {
            parser.getBlockRange(&saved_block);
        }

        UiReader(const UiReader&) = delete;
        UiReader& operator=(const UiReader&) = delete;

        ~UiReader() {
            parser.setBlockRange(&saved_block);
        }

        bool block(const char* key, SferaParserRange& result) {
            return parser.findBlock(key, &result, &range, 1);
        }

        bool has(const char* key) {
            return parser.findValue(key, &range);
        }

        const char* token(std::size_t index = 0u, bool quoted = false) {
            const bool present = quoted ? parser.readQuotedString(index, buffer) : parser.readString(index, buffer);
            return present ? buffer.c_str() : nullptr;
        }

        const char* string(const char* key, bool quoted = false) {
            return has(key) ? token(0u, quoted) : nullptr;
        }

        template<class T> void integer(const char* key, T& value) {
            if (has(key)) value = static_cast<T>(parser.readInt(0u));
        }

        void count(const char* key, std::size_t& value) {
            int parsed = 0;
            if (has(key) && parser.tryReadInt(0u, parsed) && parsed >= 0) value = parsed;
        }

        template<class T> void boolean(const char* key, T& value) {
            if (has(key)) value = static_cast<T>(parser.readBool(0u));
        }

        bool pair(const char* key, int& first, int& second) {
            if (!has(key)) return false;
            int values[2]{};
            if (!parser.readIntSequence(0u, values)) return false;
            first = values[0];
            second = values[1];
            return true;
        }

        bool rectangle(const char* key, int& left, int& top, int& right, int& bottom) {
            if (!has(key)) return false;
            int values[4]{};
            if (!parser.readIntSequence(0u, values)) return false;
            left = values[0];
            top = values[1];
            right = values[2];
            bottom = values[3];
            return true;
        }

        void color(const char* key, std::uint32_t& color) {
            if (!has(key)) return;
            int values[3]{};
            if (!parser.readIntSequence(0u, values)) return;
            color = SferaColor::rgba(values[0], values[1], values[2]).argb();
        }

        void rgba(const char* key, std::uint32_t& color) {
            if (!has(key)) return;
            int values[4]{};
            if (!parser.readIntSequence(0u, values)) return;
            color = SferaColor::rgba(values[0], values[1], values[2], values[3]).argb();
        }

        template<std::size_t Size> void flags(const char* key, std::uint32_t& value, const NamedValue<std::uint32_t> (&names)[Size], bool reset = false) {
            if (!has(key)) return;
            if (reset) value = 0u;
            for (std::size_t index = 0u; index < parser.tokenCount(); index += 2u) {
                const char* name = token(index);
                for (const auto& flag : names) if (SferaSimpleParser::equalsIgnoreCase(name, flag.name)) value |= flag.value;
            }
        }

        void sprite(const char* key, SphereUI::Window& window, std::shared_ptr<const SphereUI::UiSprite>& destination) {
            const char* name = string(key, true);
            if (name == nullptr) return;
            auto* owner = window.parent;
            destination = (owner == nullptr ? window : *owner).getResource(name);
        }

        void status(const char* key, std::uint32_t& mode) {
            const char* value = string(key);
            if (value != nullptr) mode = SferaSimpleParser::equalsIgnoreCase(value, "PERCENT") ? 1u : SferaSimpleParser::equalsIgnoreCase(value, "STYLE1") ? 2u : 0u;
        }

        void drawMethod(SphereUI::Window& window, bool own_resources = false) {
            const char* method = string("drawMethod");
            if (SferaSimpleParser::equalsIgnoreCase(method, "NONE")) window.behavior_flags |= WindowStyle::skipDrawing;
            else if (SferaSimpleParser::equalsIgnoreCase(method, "SPRITE")) {
                const char* name = token(1u, true);
                if (name != nullptr) {
                    auto* owner = own_resources ? &window : window.parent;
                    window.resource_reference = (owner == nullptr ? window : *owner).getResource(name);
                }
            }
        }
    };

    SphereUI::UiRect windowBounds(const SphereUI::Window& window) {
        SphereUI::UiRect result{};
        window.getAbsolutePosition(result.left, result.top);
        result.right = SphereUI::detail::addCoordinate(result.left, window.width);
        result.bottom = SphereUI::detail::addCoordinate(result.top, window.height);
        return result;
    }

    void renderLabel(const SphereUI::Window& window, const char* text, int x, int y, std::uint32_t color, const SphereUI::UiRect& clip, int font = inheritFont) {
        if (text == nullptr || *text == '\0') return;
        SphereUI::InterfaceRenderer::drawText(text, x, y, color, font == inheritFont ? window.font : font, window.font_initialized, clip, window.alpha == 255u);
    }

    void alignedLabel(const SphereUI::Window& window, std::uint32_t color) {
        const auto bounds = windowBounds(window);
        int dx = 0;
        int dy = 0;
        if (window.text_alignment != 0u) {
            const auto extent = SphereUI::InterfaceRenderer::measureText(window.getText(), window.font, window.font_initialized);
            if (extent.width < window.width) {
                if ((window.text_alignment & TextAlignment::right) != 0u) dx = window.width - extent.width;
                if ((window.text_alignment & TextAlignment::horizontalCenter) != 0u) dx = (window.width - extent.width) / 2;
            }
            if (extent.height < window.height) {
                if ((window.text_alignment & TextAlignment::bottom) != 0u) dy = window.height - extent.height;
                if ((window.text_alignment & TextAlignment::verticalCenter) != 0u) dy = (window.height - extent.height) / 2;
            }
        }
        renderLabel(window, window.getText(), SphereUI::detail::addCoordinate(bounds.left, dx), SphereUI::detail::addCoordinate(bounds.top, dy), color, bounds);
    }

    template<class Row> void appendCircular(std::vector<Row>& rows, std::size_t maximum, std::size_t& next, Row row) {
        if (maximum == 0u || rows.size() < maximum) rows.push_back(std::move(row));
        else rows.at(next % rows.size()) = std::move(row);
        if (maximum != 0u) next = (next + 1u) % maximum;
    }

    std::uint32_t modulatedColor(std::uint32_t color, std::uint32_t alpha) {
        return SferaColor::fromArgb(color).scaledAlpha(alpha).argb();
    }

    template<class Emit> void wrapTextLine(const SphereUI::Window& window, const char* text, bool wrap, Emit emit) {
        std::string remaining = text == nullptr ? " " : text;
        const auto measuredWidth = [&](const std::string& value) {
            return SphereUI::InterfaceRenderer::measureText(value.c_str(), window.font, true).width - (window.font < 2u ? 2 : 0);
        };
        while (wrap && remaining.size() > 1u && measuredWidth(remaining) > window.width) {
            std::size_t fit = 0u, boundary = 0u;
            for (std::size_t index = 1u; index <= remaining.size(); ++index) {
                if (measuredWidth(remaining.substr(0u, index)) > window.width) break;
                fit = index;
                if (remaining[index - 1u] == ' ' || remaining[index - 1u] == ':' || remaining[index - 1u] == ';') boundary = index;
            }
            const auto count = boundary != 0u ? boundary : std::max(fit, std::size_t{1u});
            emit(remaining.substr(0u, count).c_str());
            remaining.erase(0u, count);
        }
        emit(remaining.c_str());
    }

    void drawChild(SphereUI::Window* address, std::uint32_t alpha);
    void inputChild(SphereUI::Window* address, const SphereUI::WindowInput& input);
    template<class Value> void storeValue(std::uintptr_t address, Value value);
    template<class T, class Copy> std::unique_ptr<SphereUI::Window> cloneControl(const T& source, SphereUI::Window::CloneContext& context, Copy copy) {
        auto result = std::make_unique<T>();
        result->initializeCopy(source, context);
        copy(*result, source, context);
        return result;
    }

    void notifyParent(SphereUI::Window& window, SphereUI::UiMessage message, std::size_t first = 0u, std::size_t second = 0u) {
        if (auto* owner = window.parent) {
            if (first > std::numeric_limits<std::uint32_t>::max() || second > std::numeric_limits<std::uint32_t>::max()) throw std::overflow_error("UI event exceeds an MBC word");
            owner->queueEvent({&window, window.control_id, message, static_cast<std::uint32_t>(first), static_cast<std::uint32_t>(second)});
        }
    }

    template<class T> void cloneOwned(std::unique_ptr<T>& destination, const std::unique_ptr<T>& source, SphereUI::Window& owner, SphereUI::Window::CloneContext& context) {
        std::unique_ptr<T> copy(source ? static_cast<T*>(source->cloneInto(context).release()) : nullptr);
        if (source && !copy) throw std::bad_alloc();
        if (copy) copy->setParent(&owner);
        destination = std::move(copy);
    }

    template<class T> bool loadPart(SphereUI::Window& owner, std::unique_ptr<T>& destination, UiReader& reader, const char* key, const char* filename, SferaSimpleParser& parser, UiControlKind kind, std::uint32_t id) {
        SferaParserRange part{};
        if (!reader.block(key, part)) return false;
        std::unique_ptr<T> control(static_cast<T*>(owner.createControl(filename, parser, part, kind, id).release()));
        if (control) control->setParent(&owner);
        destination = std::move(control);
        return destination != nullptr;
    }

    void readAnimation(UiReader& reader, SferaSimpleParser& parser, const char* key, SphereUI::WindowAnimation& animation) {
        const char* name = reader.string(key);
        if (name == nullptr) return;
        animation.kind = SphereUI::detail::animationKind(name);
        animation.duration = parser.readFloat(1u);
        animation.distance = parser.readFloat(2u);
        animation.offset = parser.readFloat(3u);
        if (animation.duration == 0.0f) animation.duration = 0.25f;
    }

    bool contains(const SphereUI::UiRect& bounds, int x, int y) {
        return x >= bounds.left && x < bounds.right && y >= bounds.top && y < bounds.bottom;
    }

    template<class T> void loadNavigationButtons(T& owner, UiReader& reader, const char* filename, SferaSimpleParser& parser, bool defaults, float interval = 0.0f) {
        const char* names[] = {"leftbutton", "rightbutton"};
        std::unique_ptr<SphereUI::ButtonCtrl>* destinations[] = {&owner.decrease_button, &owner.increase_button};
        for (std::size_t index = 0u; index < 2u; ++index) if (loadPart(owner, *destinations[index], reader, names[index], filename, parser, UiControlKind::button, index + 1u) && defaults) {
            auto* button = destinations[index]->get();
            button->button_flags |= ButtonStyle::releaseOutside | ButtonStyle::repeatWhilePressed;
            if (interval != 0.0f) button->repeat_interval = interval;
        }
    }

    template<class T> void cloneNavigationButtons(T& destination, const T& source, SphereUI::Window::CloneContext& context) {
        cloneOwned(destination.decrease_button, source.decrease_button, destination, context);
        cloneOwned(destination.increase_button, source.increase_button, destination, context);
    }

    void copyScrollFields(SphereUI::ScrollBar& destination, const SphereUI::ScrollBar& source, SphereUI::Window::CloneContext& context) {
        copyProperties(destination, source,
            &SphereUI::ScrollBar::scroll_resource, &SphereUI::ScrollBar::thumb_width, &SphereUI::ScrollBar::thumb_height,
            &SphereUI::ScrollBar::thumb_x, &SphereUI::ScrollBar::thumb_y, &SphereUI::ScrollBar::orientation_flags,
            &SphereUI::ScrollBar::normalized_position, &SphereUI::ScrollBar::minimum, &SphereUI::ScrollBar::maximum,
            &SphereUI::ScrollBar::current, &SphereUI::ScrollBar::step, &SphereUI::ScrollBar::page_step,
            &SphereUI::ScrollBar::dragging_thumb, &SphereUI::ScrollBar::explicit_step, &SphereUI::ScrollBar::notify_changes,
            &SphereUI::ScrollBar::repeat_started_at, &SphereUI::ScrollBar::track_left, &SphereUI::ScrollBar::track_top,
            &SphereUI::ScrollBar::track_right, &SphereUI::ScrollBar::track_bottom, &SphereUI::ScrollBar::page_click_active);
        cloneNavigationButtons(destination, source, context);
    }

    void copySpinFields(SphereUI::SpinButton& destination, const SphereUI::SpinButton& source, SphereUI::Window::CloneContext& context) {
        copyProperties(destination, source,
            &SphereUI::SpinButton::minimum, &SphereUI::SpinButton::maximum, &SphereUI::SpinButton::current,
            &SphereUI::SpinButton::previous, &SphereUI::SpinButton::step, &SphereUI::SpinButton::body_index,
            &SphereUI::SpinButton::status_valid, &SphereUI::SpinButton::notify_changes, &SphereUI::SpinButton::update_enabled);
        cloneNavigationButtons(destination, source, context);
    }

    bool moveScroll(SphereUI::ScrollBar& control, bool increase, int amount) {
        const auto limit = increase ? control.maximum : control.minimum;
        if (control.current == limit) return false;
        control.current = increase ? std::min(SphereUI::detail::addCoordinate(control.current, amount), limit) : std::max(SphereUI::detail::subtractCoordinate(control.current, amount), limit);
        control.updateControlState();
        return true;
    }

    void enableNavigationButtons(SphereUI::ScrollBar& control) {
        for (auto address : {control.decrease_button.get(), control.increase_button.get()}) if (auto* button = address) button->handleMessage(UiMessage::setEnabled, control.minimum != control.maximum ? 1u : 0u, 0u);
    }

    std::uint32_t opacity_alpha(double value) {
        return static_cast<std::int64_t>(std::trunc(value));
    }

    void replace_color_alpha(std::uint32_t& color, std::uint32_t alpha) {
        color = SferaColor::fromArgb(color).withAlpha(alpha).argb();
    }

}

bool SphereUI::Window::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    reader.boolean("hitTransparent", hit_transparent);
    if (const char* value = reader.string("windowName", true)) setResourceName(value);
    SferaParserRange sprites{};
    if (reader.block("spritesDef", sprites)) {
        parser.setBlockRange(&sprites);
        SferaParserRange entry{};
        while (parser.nextBlock("sprite", &entry)) {
            auto sprite = std::make_shared<UiSprite>();
            if (sprite->loadUi(filename, parser, entry)) appendResource(std::move(sprite));
        }
        parser.clearBlockRange();
    }
    resource_reference = nullptr;
    reader.drawMethod(*this, true);
    if (reader.pair("showTitle", text_offset_x, text_offset_y)) behavior_flags |= WindowStyle::showTitle;
    if (reader.has("escapeHandle") && parser.readBool(0u)) behavior_flags |= WindowStyle::handleEscape;
    if (reader.pair("position", x, y)) {
        initial_x = x;
        initial_y = y;
    }
    reader.pair("size", width, height);
    if (const char* value = reader.string("windowText")) setText(g_sfera_interface.localizedText(value));
    if (const char* value = reader.string("windowHelp", true)) setHelp(value);
    reader.boolean("canDragDrop", can_drag_drop);
    reader.boolean("canGoTop", can_go_top);
    if (reader.has("canNotCross") && parser.readBool(0u)) behavior_flags |= WindowStyle::preventOverlap;
    reader.rectangle("rectTitle", caption_left, caption_top, caption_right, caption_bottom);
    reader.boolean("saveLastPosition", save_last_position);
    if (reader.has("font")) {
        font = static_cast<std::uint8_t>(parser.readInt(0u));
        font_initialized = true;
    }
    if (reader.has("alignWin")) for (std::size_t index = 0u; index < parser.tokenCount(); index += 2u) alignment_flags |= detail::alignmentFlag(reader.token(index));
    reader.color("textColor", text_color);
    reader.color("disabledColor", disabled_color);
    readAnimation(reader, parser, "showEffect", show_animation);
    readAnimation(reader, parser, "hideEffect", hide_animation);
    parser.setBlockRange(&range);
    SferaParserRange entry{};
    std::uint32_t next_id = 1u;
    std::uint32_t ordinal = 1u;
    while (parser.nextBlock("control", &entry)) {
        UiReader child_reader(parser, entry);
        const char* name = child_reader.string("classID");
        if (name != nullptr) if (auto child = createControl(filename, parser, entry, detail::controlKind(name), ordinal)) {
            child->control_id = next_id++;
            appendChild(std::move(child));
        }
        ++ordinal;
    }
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::Window::cloneInto(CloneContext& context) const {
    auto result = std::make_unique<Window>();
    result->initializeCopy(*this, context);
    return result;
}

std::uint32_t SphereUI::Window::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    if (message >= UiMessage::setTooltipLine && message <= UiMessage::setTooltipTextColor) {
        auto* tip = tooltip.get();
        if (tip == nullptr) {
            tooltip = std::make_unique<ToolTipCtrl>();
            tip = tooltip.get();
            if (tip == nullptr) return 0u;
            tip->setParent(this);
        }
        return tip->handleMessage(message, first, second);
    }
    const auto hide_tip = [&] {
        if (auto* tip = tooltip.get()) tip->reset();
    };
    switch (message) {
        case UiMessage::setInputEnabled:
            input_enabled = first != 0u;
            break;
        case UiMessage::getInputEnabled:
            storeValue(first, input_enabled);
            break;
        case UiMessage::setTextRgb:
            text_color = SferaColor::fromArgb(first).withAlpha(alpha).argb();
            break;
        case UiMessage::setHidden:
            hidden = first != 0u;
            if (hidden) hide_tip();
            break;
        case UiMessage::getHidden:
            storeValue(first, hidden);
            break;
        case UiMessage::setEnabled:
            disabled = first == 0u;
            if (disabled) hide_tip();
            break;
        case UiMessage::getDisabled:
            storeValue(first, disabled);
            break;
        case UiMessage::setTextAlignment:
            text_alignment = first;
            break;
        case UiMessage::animateVisibility:
            animateVisibility(first != 0u);
            break;
        case UiMessage::setPosition:
            setPosition(static_cast<int>(first), static_cast<int>(second));
            break;
        case UiMessage::getChildUnderCursor:
            {
                const auto position = CCursorManager::instance().position();
                storeValue(first, static_cast<std::uint32_t>(childControlAt(position.x, position.y)));
                break;
            }
        case UiMessage::getModal:
            storeValue(first, modal_owner != nullptr);
            break;
        case UiMessage::endModal:
            if (modal_owner != nullptr) {
                modal_owner = nullptr;
                handleMessage(UiMessage::animateVisibility, 0u, 0u);
            }
            break;
        case UiMessage::beginModal:
            if (modal_owner == nullptr) {
                modal_owner = reinterpret_cast<Window*>(first);
                handleMessage(UiMessage::animateVisibility, 1u, 0u);
            }
            break;
        case UiMessage::setSize:
            width = first;
            height = second;
            break;
        case UiMessage::setFont:
            setFont(first);
            break;
        default:
            break;
    }
    return 1u;
}

void SphereUI::Window::setPosition(int new_x, int new_y) {
    x = new_x;
    y = new_y;
}

void SphereUI::Window::draw() {
    if (hidden) return;
    const auto* owner = parent;
    const auto screen_x = detail::addCoordinate(x, owner == nullptr ? 0 : owner->x);
    const auto screen_y = detail::addCoordinate(y, owner == nullptr ? 0 : owner->y);
    if ((behavior_flags & WindowStyle::skipDrawing) == 0u && resource_reference != nullptr) resource_reference->drawNatural(static_cast<float>(screen_x), static_cast<float>(screen_y), SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    if ((behavior_flags & WindowStyle::showTitle) != 0u && text.size() != 0u) {
        const auto caption_width = detail::subtractCoordinate(caption_right, caption_left);
        const auto caption_height = detail::subtractCoordinate(caption_bottom, caption_top);
        int font_id = font;
        auto top = detail::addCoordinate(detail::addCoordinate(screen_y, text_offset_y), caption_top);
        const auto measured = InterfaceRenderer::measureText(getText(), font_id, font_initialized);
        if (static_cast<std::uint32_t>(measured.width) > static_cast<std::uint32_t>(caption_width)) {
            font_id = 2u;
            const auto smaller = InterfaceRenderer::measureText(getText(), font_id, font_initialized);
            top = detail::addCoordinate(top, static_cast<int>((static_cast<std::uint32_t>(measured.height) - static_cast<std::uint32_t>(smaller.height)) >> 1u));
        }
        const auto left = detail::addCoordinate(detail::addCoordinate(screen_x, text_offset_x), caption_left);
        renderLabel(*this, getText(), left, top, text_color, {left, top, detail::addCoordinate(left, detail::addCoordinate(caption_width, 10)), detail::addCoordinate(top, detail::addCoordinate(caption_height, 10))}, font_id);
    }
    detail::forEachChild(*this, [](Window& child) {
        child.draw();
    });
}

void SphereUI::Window::handleInput(const WindowInput& input) {
    if (!input_enabled) return;
    const auto identity = registration_id;
    if (hide_after_animation && !isAnimating()) {
        hide_after_animation = false;
        handleMessage(UiMessage::setHidden, 1u, 0u);
        return;
    }
    if ((input.mouse_flags & MouseInput::leftPress) != 0u && caption_left != caption_right) {
        int screen_x = 0;
        int screen_y = 0;
        getAbsolutePosition(screen_x, screen_y);
        if (input.mouse_x > detail::addCoordinate(screen_x, caption_left) && input.mouse_x <= detail::addCoordinate(screen_x, caption_right) && input.mouse_y > detail::addCoordinate(screen_y, caption_top) && input.mouse_y <= detail::addCoordinate(screen_y, caption_bottom)) {
            drag_offset_x = detail::subtractCoordinate(screen_x, input.mouse_x);
            drag_offset_y = detail::subtractCoordinate(screen_y, input.mouse_y);
            dragging = true;
        }
    }
    if (dragging) {
        x = detail::addCoordinate(drag_offset_x, input.mouse_x);
        y = detail::addCoordinate(drag_offset_y, input.mouse_y);
        if ((input.mouse_flags & MouseInput::leftRelease) != 0u) {
            dragging = false;
            if (save_last_position) g_sfera_interface.saveWindowPosition(*this);
        }
    }
    detail::forEachChild(*this, [&](Window& child) {
        if (child.disabled) return;
        const auto child_identity = child.registration_id;
        if (auto* tip = child.tooltip.get()) tip->handleInput(input);
        if (g_sfera_interface.isRegistered(&child, child_identity)) child.handleInput(input);
    });
    if (!g_sfera_interface.isRegistered(this, identity)) return;
    if (auto* window = overlay; window != nullptr && !window->hidden) window->handleInput(input);
}

void SphereUI::Window::setOpacity(float opacity) {
    const std::uint32_t new_alpha = opacity_alpha(opacity * 255.0);
    alpha = new_alpha;
    replace_color_alpha(text_color, new_alpha);
    replace_color_alpha(disabled_color, new_alpha);
    detail::forEachChild(*this, [opacity](Window& child) { child.setOpacity(opacity); });
}

bool SphereUI::Window::hitTest(int screen_x, int screen_y) {
    if (hidden) return false;
    for (const auto& child : children) {
        if (child->can_drag_drop && child->containsPoint(screen_x, screen_y) && child->hitTest(screen_x, screen_y)) break;
    }
    return true;
}

void SphereUI::Window::dispatchMessage(int target_group, SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second, SphereUI::UiControlKind target_kind) {
    detail::forEachChild(*this, [&](Window& child) {
        if (target_group != -1 && child.group != target_group) return;
        const auto identity = child.registration_id;
        if (target_kind == anyControlKind || child.control_kind == target_kind) child.handleMessage(message, first, second);
        if (g_sfera_interface.isRegistered(&child, identity) && child.control_kind == UiControlKind::listItem) child.dispatchMessage(target_group, message, first, second, target_kind);
    });
}

void SphereUI::Window::setFont(int font_id) {
    font = font_id;
}

int SphereUI::Window::getFont() const {
    return font;
}

bool SphereUI::ButtonCtrl::loadUi(const char* , SferaSimpleParser& parser, const SferaParserRange& range) {

    UiReader reader(parser, range);
    reader.sprite("checkedImage", *this, pressed_image);
    reader.sprite("focusedImage", *this, hover_image);
    reader.sprite("disabledImage", *this, disabled_image);
    reader.sprite("uncheckedImage", *this, idle_image);
    reader.flags("buttonStyle", button_flags, buttonStyles);
    const char* method = reader.string("drawMethod");
    if (SferaSimpleParser::equalsIgnoreCase(method, "SPRITE")) button_flags |= ButtonStyle::stateImages;
    if (SferaSimpleParser::equalsIgnoreCase(method, "NONE")) behavior_flags |= WindowStyle::skipDrawing;
    if (const char* name = reader.string("hotKey", true)) {
        hotkey = Runtime::keyCode(name);
        std::string_view arguments(parser.valueText());
        const auto first = arguments.find_first_not_of(numericWhitespace);
        const auto end = first == std::string_view::npos ? first : arguments.find_first_of(numericWhitespace, first);
        arguments = end == std::string_view::npos ? std::string_view{} : arguments.substr(end);
        for (std::size_t index = 0u; index < 3u; ++index) {
            int modifier = 0;
            if (!readInteger(arguments, modifier, 10)) break;
            if (modifier == 1 || modifier == 2) hotkey |= static_cast<std::uint32_t>(modifier) << (16u + 2u * index);
        }
    }
    hover_color = text_color;
    reader.color("focuscolor", hover_color);
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::ButtonCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](auto& target, const auto& source, SphereUI::Window::CloneContext& context) {

        copyProperties(target, source,
            &ButtonCtrl::visual_state, &ButtonCtrl::idle_image, &ButtonCtrl::pressed_image, &ButtonCtrl::hover_image,
            &ButtonCtrl::button_flags, &ButtonCtrl::hotkey, &ButtonCtrl::repeat_started_at, &ButtonCtrl::pressed,
            &ButtonCtrl::repeat_interval, &ButtonCtrl::hover_color, &ButtonCtrl::disabled_image);
    });
}

std::uint32_t SphereUI::ButtonCtrl::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    if (message == UiMessage::activateButton) {
        click();
        return 1u;
    }
    return Window::handleMessage(message, first, second);
}

void SphereUI::ButtonCtrl::draw() {
    if (hidden || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    if ((button_flags & ButtonStyle::stateImages) != 0u) {
        const std::shared_ptr<const UiSprite> images[] = {idle_image, pressed_image, hover_image};
        const auto image = disabled ? disabled_image : images[std::min(visual_state, 2u)];
        if (image != nullptr) image->draw(static_cast<float>(bounds.left), static_cast<float>(bounds.top), static_cast<float>(bounds.right), static_cast<float>(bounds.bottom), SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    }
    if (text.size() != 0u) alignedLabel(*this, disabled ? disabled_color : visual_state == 0u ? text_color : hover_color);
}

void SphereUI::ButtonCtrl::handleInput(const WindowInput& input) {
    if (hidden || disabled) return;
    const auto key = LOWORD(hotkey);
    const auto modifiers = HIWORD(hotkey);
    if (input.key_code != 0u && input.key_code == key && (modifiers == 0u || (input.key_modifiers & modifiers) != 0u)) click();
    if (containsPoint(input.mouse_x, input.mouse_y)) {
        if (visual_state == 0u) visual_state = 2u;
        if ((input.mouse_flags & MouseInput::leftPress) != 0u) {
            visual_state = 1u;
            pressed = true;
        }
        bool repeat = false;
        if ((button_flags & ButtonStyle::repeatWhilePressed) != 0u && pressed && (input.mouse_buttons & 1u) != 0u) {
            const float elapsed = static_cast<double>(static_cast<std::int64_t>(Runtime::clockTicks() - repeat_started_at)) / 10000.0;
            if (repeat_interval < elapsed) {
                visual_state = 1u;
                repeat = true;
                repeat_started_at = Runtime::clockTicks();
            }
        }
        if ((input.mouse_flags & MouseInput::leftRelease) != 0u && visual_state == 1u) {
            visual_state = 2u;
            pressed = false;
            if ((button_flags & ButtonStyle::repeatWhilePressed) == 0u) {
                Runtime::playClickSound();
                click();
                return;
            }
        }
        if (repeat) click();
    } else {
        if (visual_state != 0u && ((button_flags & ButtonStyle::releaseOutside) != 0u || visual_state == 2u || (input.mouse_buttons & 1u) == 0u)) visual_state = 0u;
        if (pressed && (input.mouse_buttons & 1u) == 0u) pressed = false;
    }
}


bool SphereUI::CheckBox::loadUi(const char* , SferaSimpleParser& parser, const SferaParserRange& range) {

    UiReader reader(parser, range);
    hover_color = text_color;
    reader.sprite("checkedImage", *this, checked_image);
    reader.sprite("focusedImage", *this, unchecked_hover_image);
    reader.sprite("uncheckedImage", *this, unchecked_image);
    reader.sprite("checkfocusImage", *this, checked_hover_image);
    reader.pair("imageOffset", image_x, image_y);
    reader.pair("textOffset", label_x, label_y);
    reader.color("focuscolor", hover_color);
    reader.flags("buttonStyle", button_flags, buttonStyles);
    return true;
}

void SphereUI::CheckBox::copyCheckState(const CheckBox& source) {
    if (this == &source) return;
    copyProperties(*this, source,
        &CheckBox::unchecked_image, &CheckBox::checked_image, &CheckBox::unchecked_hover_image, &CheckBox::checked_hover_image,
        &CheckBox::checked, &CheckBox::hovered, &CheckBox::image_x, &CheckBox::image_y, &CheckBox::button_flags,
        &CheckBox::label_x, &CheckBox::label_y, &CheckBox::hover_color);
}

std::unique_ptr<SphereUI::Window> SphereUI::CheckBox::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](auto& target, const auto& source, SphereUI::Window::CloneContext& context) {
        target.copyCheckState(source);
    });
}

std::uint32_t SphereUI::CheckBox::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::setChecked:
            checked = first != 0u;
            return 1u;
        case UiMessage::getChecked:
            storeValue(first, checked);
            return 1u;
        case UiMessage::activateButton:
            playClickSound();
            return 1u;
        case UiMessage::setEnabled:
            if (first == 0u) checked = false;
            break;
        default:
            break;
    }
    return Window::handleMessage(message, first, second);
}

void SphereUI::CheckBox::draw() {
    if (hidden || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    auto image = checked ? checked_image : unchecked_image;
    if (hovered) {
        const auto hover = checked ? checked_hover_image : unchecked_hover_image;
        if (hover != 0u) image = hover;
    }
    if (image != nullptr) image->drawNatural(static_cast<float>(detail::addCoordinate(bounds.left, image_x)), static_cast<float>(detail::addCoordinate(bounds.top, image_y)), SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    int dx = label_x;
    int dy = label_y;
    if ((button_flags & ButtonStyle::centerText) != 0u) {
        const auto extent = InterfaceRenderer::measureText(getText(), font, font_initialized);
        if (extent.width < width) dx = (width - extent.width) / 2;
        if (extent.height < height) dy = (height - extent.height) / 2;
    }
    renderLabel(*this, getText(), detail::addCoordinate(bounds.left, dx), detail::addCoordinate(bounds.top, dy), disabled ? disabled_color : hovered ? hover_color : text_color, bounds);
}

void SphereUI::CheckBox::handleInput(const WindowInput& input) {
    hovered = containsPoint(input.mouse_x, input.mouse_y) ? 1u : 0u;
    if (hovered && (input.mouse_flags & MouseInput::leftPress) != 0u) playClickSound();
}

void SphereUI::CheckBox::playClickSound() {
    checked = !checked;
    if (auto* owner = parent) owner->queueEvent({this, control_id, UiMessage::leftClick, 0u, 0u});
    Runtime::playClickSound();
}

void SphereUI::CDescriptionWindow::draw() {
    if (hidden) return;
    const auto caption = caption_sprite;
    const auto lower = bottom_sprite;
    const auto left = left_sprite;
    const auto right = right_sprite;
    if (caption == nullptr || lower == nullptr || left == nullptr || right == nullptr) return;
    const auto bounds = windowBounds(*this);
    const auto color = SferaColor::rgba(255u, 255u, 255u, alpha).argb();
    const float x = bounds.left, y = bounds.top;
    InterfaceRenderer::drawTexture(nullptr, x - 0.5f + left->width, y - 0.5f + caption->height, static_cast<float>(bounds.right) - 0.5f - right->width, static_cast<float>(bounds.bottom) - 0.5f - lower->height, SferaColor::fromArgb(UiColor::frameBackground).withAlpha(alpha * 166u / 255u).argb(), 0.0f, 0.0f, false);
    caption_sprite->drawNatural(x, y, color);
    bottom_sprite->drawNatural(x, static_cast<float>(bounds.bottom) - lower->height, color);
    float offset = caption->height;
    const auto end = static_cast<float>(height) - lower->height;
    const float tile = left->height;
    const auto right_x = static_cast<float>(bounds.right) - right->width;
    if (tile > 0.0f) while (offset + tile <= end) {
        left_sprite->drawNatural(x, y + offset, color);
        right_sprite->drawNatural(right_x, y + offset, color);
        offset += tile;
    }
    if (offset < end) {
        left_sprite->draw(x, y + offset, x + left->width, y + end, color);
        right_sprite->draw(right_x, y + offset, static_cast<float>(bounds.right), y + end, color);
    }
    detail::forEachChild(*this, [](Window& child) {
        child.draw();
    });
}

SphereUI::CDescriptionWindow::~CDescriptionWindow() {
    if (Runtime::descriptionWindow() == this) Runtime::setDescriptionWindow(nullptr);
}

void SphereUI::Window::setInputFocus(bool focused, bool submit_on_blur) {
    if (!focused) {
        if (input_enabled && submit_on_blur) notifyParent(*this, UiMessage::editSubmit);
        input_enabled = false;
        return;
    }
    input_enabled = false;
    for (const auto kind : {UiControlKind::edit, UiControlKind::richEdit, UiControlKind::hyperTextEdit}) Runtime::broadcastMessage(nullptr, -1, UiMessage::setInputEnabled, 0u, 0u, kind);
    input_enabled = true;
}

SphereUI::EditCtrl::EditCtrl() {
    maximum_symbols = 256u;
    cursor_width = 5;
    cursor_color = UiColor::whiteRgb;
    cursor_visible = cursor_uses_text_color = submit_on_blur = true;
    observed_length = invalidIndex;
    hidden = input_enabled = false;
    control_kind = UiControlKind::edit;
}

void SphereUI::EditCtrl::updatePassword() {
    if (password && password_text.size() != text.size()) password_text.assign(std::string(text.size(), '*').c_str());
}

bool SphereUI::EditCtrl::loadUi(const char*, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    reader.count("maxsymbols", maximum_symbols);
    reader.boolean("numeric", numeric);
    reader.boolean("password", password);
    reader.boolean("enteredOnFocus", submit_on_blur);
    if (reader.has("cursorcolor")) {
        reader.color("cursorcolor", cursor_color);
        cursor_color = SferaColor::fromArgb(cursor_color).withAlpha(0u).argb();
        cursor_uses_text_color = false;
    }
    int unused_horizontal_offset = 0;
    reader.pair("cursoroffset", unused_horizontal_offset, cursor_offset_y);
    if (maximum_symbols == 0u) maximum_symbols = 256u;
    cursor_width = InterfaceRenderer::measureText("_", font, true).width + 1;
    input_enabled = false;
    updatePassword();
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::EditCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](EditCtrl& target, const EditCtrl& source, SphereUI::Window::CloneContext& context) {

        copyProperties(target, source,
            &EditCtrl::cursor_offset_y, &EditCtrl::numeric, &EditCtrl::password, &EditCtrl::maximum_symbols,
            &EditCtrl::cursor_width, &EditCtrl::password_text, &EditCtrl::cursor_color, &EditCtrl::blink_started,
            &EditCtrl::cursor_visible, &EditCtrl::cursor_uses_text_color, &EditCtrl::submit_on_blur, &EditCtrl::caret_position,
            &EditCtrl::observed_length);
    });
}

std::uint32_t SphereUI::EditCtrl::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::setInputEnabled:
            setInputFocus(first != 0u, submit_on_blur);
            return 1u;
        case UiMessage::setEditText:
            setText(reinterpret_cast<const char*>(first));
            updatePassword();
            break;
        case UiMessage::getEditText:
            if (auto* output = reinterpret_cast<char*>(first)) {
                const auto length = std::min(text.size(), std::size_t{250});
                std::memcpy(output, getText(), length);
                output[length] = '\0';
            }
            break;
        case UiMessage::getEditFocus:
            return input_enabled;
        case UiMessage::moveEditCaretToEnd:
            caret_position = text.size();
            break;
        default:
            break;
    }
    return Window::handleMessage(message, first, second);
}

void SphereUI::EditCtrl::handleInput(const WindowInput& input) {
    if (input_enabled) Runtime::setTextInputActive(true);
    if (hidden) return;
    if (input_enabled) {
        std::string value(getText());
        caret_position = std::clamp(caret_position, 0, static_cast<int>(value.size()));
        if (input.character >= 32u && value.size() < maximum_symbols && (!numeric || (input.character >= '0' && input.character <= '9'))) {
            value.insert(caret_position, 1u, static_cast<char>(input.character));
            ++caret_position;
        }
        switch (input.key_code) {
            case VK_BACK:
                if (caret_position > 0) {
                    value.erase(--caret_position, 1u);
                }
                break;
            case VK_DELETE:
                if (static_cast<std::size_t>(caret_position) < value.size()) value.erase(caret_position, 1u);
                break;
            case VK_LEFT:
                if (caret_position > 0) --caret_position;
                break;
            case VK_RIGHT:
                if (static_cast<std::size_t>(caret_position) < value.size()) ++caret_position;
                break;
            case VK_HOME:
                caret_position = 0;
                break;
            case VK_END:
                caret_position = value.size();
                break;
            default:
                break;
        }
        if (value != getText()) setText(value.c_str());
        observed_length = text.size();
        updatePassword();
        if (input.key_code == VK_TAB) notifyParent(*this, UiMessage::editTab);
        if (input.key_code == VK_RETURN) {
            notifyParent(*this, UiMessage::editSubmit);
        }
    }
    if ((input.mouse_flags & MouseInput::leftPress) != 0u) {
        if (!containsPoint(input.mouse_x, input.mouse_y)) setInputFocus(false, submit_on_blur);
        else if (!input_enabled) setInputFocus(true);
    }
}

void SphereUI::EditCtrl::draw() {
    if (hidden || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    ViewportScope viewport(bounds);
    if (!viewport) return;
    if (observed_length != text.size()) caret_position = text.size();
    caret_position = std::clamp(caret_position, 0, static_cast<int>(text.size()));
    updatePassword();
    const char* display = password ? password_text.data() : getText();
    const auto extent = InterfaceRenderer::measureText(display, font, font_initialized);
    const auto prefix = std::string(display, caret_position);
    const auto caret_x = InterfaceRenderer::measureText(prefix.c_str(), font, font_initialized).width;
    const auto full_width = detail::addCoordinate(extent.width, cursor_width);
    int dx = 0, dy = extent.height < height ? (height - extent.height) / 2 : 0;
    if (full_width > width) {
        dx = width - full_width;
        if (caret_x < -static_cast<std::int64_t>(dx)) dx = caret_position == 0 ? 0 : cursor_width - caret_x;
    } else {
        if ((text_alignment & TextAlignment::horizontalCenter) != 0u) dx = (width - extent.width) / 2;
        if ((text_alignment & TextAlignment::right) != 0u) dx = width - full_width;
    }
    if ((text_alignment & TextAlignment::bottom) != 0u && extent.height < height) dy = height - extent.height;
    const auto left = detail::addCoordinate(bounds.left, dx), top = detail::addCoordinate(bounds.top, dy);
    renderLabel(*this, display, left, top, text_color, bounds);
    const auto now = Runtime::clockTicks();
    if (blink_started == 0u || now < blink_started) blink_started = now;
    const auto elapsed = now - blink_started;
    if (elapsed > 4000u) cursor_visible = static_cast<std::uint8_t>(((elapsed - 4000u) / 4000u) & 1u);
    if (input_enabled && cursor_visible) {
        if (cursor_uses_text_color) cursor_color = text_color;
        renderLabel(*this, "_", detail::addCoordinate(left, caret_x), detail::addCoordinate(top, cursor_offset_y), SferaColor::fromArgb(cursor_color).withAlpha(alpha).argb(), bounds);
    }
}

SphereUI::EditCtrl::~EditCtrl() {
    Runtime::setTextInputActive(false);
}

bool SphereUI::ListCtrl::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    line_height = InterfaceRenderer::measureText(" ", font, true).height;
    loadPart(*this, scrollbar, reader, "scrollbar", filename, parser, UiControlKind::scrollBar, 1u);
    reader.boolean("formatStrings", format_strings);
    reader.boolean("useContinueMark", continue_mark);
    reader.boolean("canSelect", can_select);
    reader.integer("selectionBorder", selection_border);
    reader.rgba("selectionColor", selection_color);
    reader.rgba("selectionLineColor", selection_line_color);
    if (reader.has("chatlike")) {
        chatlike = parser.readBool(0u) ? 1u : 0u;
        maximum_items = 64u;
    }
    reader.count("maxItems", maximum_items);
    parser.setScanRange(&range);
    while (parser.nextValue("addstring")) {
        std::string key, color_text;
        parser.readString(0u, key);
        parser.readString(1u, color_text);
        std::uint32_t color = 0u;
        if (!key.empty() && readHexColor(color_text.c_str(), color)) addText(g_sfera_interface.localizedText(key.c_str()), color);
    }
    parser.clearScanRange();
    updateLayout();
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::ListCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](ListCtrl& destination, const ListCtrl& source, SphereUI::Window::CloneContext& context) {
        destination.copyListState(source, context);
    });
}

std::uint32_t SphereUI::ListCtrl::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::verticalScroll:
        case UiMessage::setListScroll:
            vertical_offset = first;
            updateVisibleRange();
            return 1u;
        case UiMessage::updateScrollLayout:
            if (first != 0u) updateLayout();
            else if (auto* bar = scrollbar.get()) bar->setParameters({0u, ScrollField::all, 0, 0, 0, 0, 0});
            return 1u;
        case UiMessage::appendListText:
            {
                const bool at_bottom = detail::addCoordinate(vertical_offset, 5) >= maximum_scroll;
                addText(reinterpret_cast<const char*>(first), second);
                if (chatlike && at_bottom) {
                    vertical_offset = maximum_scroll;
                    if (auto* bar = scrollbar.get()) bar->setParameters({0u, ScrollField::position, 0, 0, 0, vertical_offset, 0});
                    updateVisibleRange();
                }
                return 1u;
            }
        case UiMessage::setListText:
            if (first >= rows.size()) return 0u;
            rows.at(first).text.assign(second == 0u ? " " : reinterpret_cast<const char*>(second));
            return 1u;
        case UiMessage::setListColor:
            if (first >= rows.size()) return 0u;
            rows.at(first).color = second;
            return 1u;
        case UiMessage::setListFormatting:
            format_strings = first != 0u ? 1u : 0u;
            return 1u;
        case UiMessage::alignListRow:
            if (first >= rows.size()) return 0u;
            alignRow(first, second);
            return 1u;
        case UiMessage::setListSelection:
            selectRow(static_cast<int>(first));
            return 1u;
        case UiMessage::getListSelection:
            storeValue(first, selected_index);
            return 1u;
        case UiMessage::getListText:
            if (second >= rows.size() || first == 0u) return 0u;
            copyMessageText(reinterpret_cast<char*>(first), rows.at(physicalIndex(second)).text.data());
            return 1u;
        case UiMessage::getListSize:
            storeValue(first, rows.size());
            return 1u;
        case UiMessage::getListColor:
            if (second >= rows.size()) return 0u;
            storeValue(first, rows.at(physicalIndex(second)).color);
            return 1u;
        case UiMessage::clearList:
            clearRows();
            return 1u;
        case UiMessage::removeListRow:
            removeRow(first);
            return 1u;
        case UiMessage::getListScroll:
            storeValue(first, vertical_offset);
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

void SphereUI::ListCtrl::draw() {
    if (hidden || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    if (rows.size() != 0u) {
        ViewportScope viewport(bounds);
        if (viewport) {
            auto row_y = detail::subtractCoordinate(bounds.top, cropped_y);
            if (chatlike && rows.size() < static_cast<std::uint32_t>(std::max(visible_capacity, 0))) row_y = detail::addCoordinate(row_y, detail::subtractCoordinate(height, static_cast<int>(rows.size() * static_cast<std::uint32_t>(line_height))));
            const auto first_y = row_y;
            const auto end = std::min(visible_end, static_cast<int>(rows.size()));
            const auto mark_width = continue_mark ? InterfaceRenderer::measureText("  ...", font, font_initialized).width : 0;
            for (auto index = std::max(visible_begin, 0); index < end; ++index) {
                const auto& row = rows.at(physicalIndex(index));
                auto clip = bounds;
                const auto row_color = SferaColor::fromArgb(row.color).withAlpha(alpha).argb();
                const auto row_x = detail::addCoordinate(bounds.left, row.offset);
                const bool truncated = continue_mark && InterfaceRenderer::measureText(row.text.data(), font, font_initialized).width > width;
                if (truncated) clip.right = detail::subtractCoordinate(clip.right, mark_width);
                InterfaceRenderer::drawText(row.text.data(), row_x, row_y, row_color, font, true, clip, alpha == 255u);
                if (truncated) InterfaceRenderer::drawText("  ...", detail::addCoordinate(bounds.left, detail::addCoordinate(row.offset, detail::subtractCoordinate(width, mark_width))), row_y, row_color, font, true, bounds, alpha == 255u);
                row_y = detail::addCoordinate(row_y, line_height);
            }
            if (selected_index >= visible_begin && selected_index < end) drawSelection(bounds.left, bounds.top, detail::addCoordinate(first_y, static_cast<int>(static_cast<std::uint32_t>(selected_index - visible_begin) * static_cast<std::uint32_t>(line_height))), false);
        }
    }
    drawChild(scrollbar.get(), alpha);
}

void SphereUI::ListCtrl::handleInput(const WindowInput& input) {
    if (hidden) return;
    inputChild(scrollbar.get(), input);
    if (!can_select) {
        selected_index = -1;
        return;
    }
    if (rows.size() == 0u || (input.mouse_flags & MouseInput::leftPress) == 0u || !contains(windowBounds(*this), input.mouse_x, input.mouse_y)) return;
    const auto bounds = windowBounds(*this);
    auto first_y = detail::subtractCoordinate(bounds.top, cropped_y);
    if (chatlike && rows.size() < static_cast<std::uint32_t>(std::max(visible_capacity, 0))) first_y = detail::addCoordinate(first_y, detail::subtractCoordinate(height, static_cast<int>(rows.size() * static_cast<std::uint32_t>(line_height))));
    const auto offset = detail::subtractCoordinate(input.mouse_y, first_y);
    const auto relative = line_height > 0 ? static_cast<std::uint32_t>(offset) / static_cast<std::uint32_t>(line_height) : invalidIndex;
    const auto index = static_cast<std::uint32_t>(visible_begin) + relative;
    const auto selected = index < rows.size() ? static_cast<int>(index) : -1;
    if (selected != selected_index) {
        selected_index = selected;
        notifyParent(*this, UiMessage::listSelectionChanged, static_cast<std::uint32_t>(selected));
    }
    const auto now = Runtime::clockTicks();
    if (!click_pending) {
        click_pending = true;
        click_time = now;
    } else {
        const float elapsed = static_cast<double>(static_cast<std::int64_t>(now - click_time)) / 10000.0;
        if (elapsed < 0.6f && selected_index >= 0) notifyParent(*this, UiMessage::listDoubleClick, static_cast<std::uint32_t>(selected_index));
        click_pending = false;
    }
}


std::unique_ptr<SphereUI::Window> SphereUI::FilterListCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](FilterListCtrl& destination, const FilterListCtrl& source, SphereUI::Window::CloneContext& context) {
        destination.copyListState(source, context);
        destination.filter_mask = source.filter_mask;
        destination.history = source.history;
        destination.history_write = source.history_write;
    });
}

std::uint32_t SphereUI::FilterListCtrl::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::appendFilteredListText:
            if (first != 0u) {
                const auto components = SferaColor::fromArgb(second);
                const auto mask = components.alpha();
                const auto color = components.withAlpha(0u).argb();
                appendHistory(reinterpret_cast<const char*>(first), color, mask);
                if ((filter_mask & mask) != 0u) ListCtrl::handleMessage(UiMessage::appendListText, first, color);
            }
            return 1u;
        case UiMessage::clearFilteredList:
            clearHistory();
            clearRows();
            return 1u;
        case UiMessage::setListFilter:
            applyFilter(first);
            return 1u;
        default:
            return ListCtrl::handleMessage(message, first, second);
    }
}


bool SphereUI::FontPicker::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    loadPart(*this, preview, reader, "text", filename, parser, UiControlKind::text, 2u);
    loadPart(*this, selector, reader, "spinButton", filename, parser, UiControlKind::spinButton, 1u);
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::FontPicker::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](FontPicker& destination, const FontPicker& source, SphereUI::Window::CloneContext& context) {
        cloneOwned(destination.selector, source.selector, destination, context);
        cloneOwned(destination.preview, source.preview, destination, context);
        if (auto* selector = destination.selector.get()) {
            selector->setRange(0, static_cast<int>(g_sfera_fonts.count() - 1u));
            selector->setStep(1);
            if (auto* preview = destination.preview.get()) selector->setCurrentValue(preview->getFont() - 2);
        }
    });
}

std::uint32_t SphereUI::FontPicker::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    if (message == UiMessage::setSelectedFont) {
        setFont(first);
        return 1u;
    }
    if (message == UiMessage::getSelectedFont) {
        if (auto* window = preview.get()) storeValue(first, window->getFont());
        return 1u;
    }
    return Window::handleMessage(message, first, second);
}

void SphereUI::FontPicker::draw() {
    if (hidden || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    drawChild(selector.get(), alpha);
    drawChild(preview.get(), alpha);
}

void SphereUI::FontPicker::handleInput(const WindowInput& input) {
    if (hidden) return;
    inputChild(selector.get(), input);
    inputChild(preview.get(), input);
    WindowEvent event{};
    while (pollEvent(event)) {
        if (event.message != UiMessage::spinValueChanged) continue;
        if (auto* window = preview.get()) {
            const auto font_id = event.first + 2u;
            window->setFont(font_id);
            if (auto* owner = parent) owner->queueEvent({this, control_id, UiMessage::selectedFontChanged, font_id, 0u});
        }
    }
}

void SphereUI::FontPicker::setFont(int font_id) {
    if (auto* spin = selector.get()) spin->setCurrentValue(static_cast<int>(font_id - 2u));
    if (auto* window = preview.get()) window->setFont(font_id);
    Window::setFont(font_id);
}

int SphereUI::FontPicker::getFont() const {
    if (const auto* selector_control = selector.get()) return selector_control->currentValue() + 2;
    if (const auto* preview_control = preview.get()) return preview_control->getFont();
    return Window::getFont();
}


bool SphereUI::ImageCtrl::loadUi(const char* , SferaSimpleParser& parser, const SferaParserRange& range) {

    UiReader reader(parser, range);
    resource_reference = nullptr;
    reader.sprite("image", *this, resource_reference);
    reader.integer("alpha", base_alpha);
    reader.flags("imageStyle", image_style, imageStyles, true);
    if (reader.has("rotate")) handleMessage(UiMessage::setImageRotation, std::bit_cast<std::uint32_t>(parser.readFloat(0u)), 0u);
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::ImageCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](auto& target, const auto& source, SphereUI::Window::CloneContext& context) {

        copyProperties(target, source,
            &ImageCtrl::image_style, &ImageCtrl::interaction_active, &ImageCtrl::fallback_image, &ImageCtrl::rotated,
            &ImageCtrl::rotation_radians, &ImageCtrl::base_alpha, &ImageCtrl::opacity);
    });
}

std::uint32_t SphereUI::ImageCtrl::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::setImageName:
            {
                ImageDescription description{};
                const char* name = reinterpret_cast<const char*>(first);
                if (name == nullptr) setImage(nullptr);
                else {
                    detail::copyText(description.name, name);
                    setImage(&description);
                }
                return 1u;
            }
        case UiMessage::setImageRotation:
            {
                const float degrees = std::bit_cast<float>(static_cast<std::uint32_t>(first));
                rotated = degrees != 0.0f;
                rotation_radians = degrees / 180.0f * 3.1415929794311523f;
                return 1u;
            }
        case UiMessage::setImageDescription:
            setImage(reinterpret_cast<const ImageDescription*>(first));
            return 1u;
        case UiMessage::setImageAlpha:
            base_alpha = std::min<std::uintptr_t>(first, 255u);
            setOpacity(opacity);
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

void SphereUI::ImageCtrl::draw() {
    if (hidden || resource_reference == nullptr) return;
    const auto bounds = windowBounds(*this);
    resource_reference->draw(static_cast<float>(bounds.left), static_cast<float>(bounds.top), static_cast<float>(bounds.right), static_cast<float>(bounds.bottom), SferaColor::rgba(255u, 255u, 255u, alpha).argb(), rotated ? rotation_radians : 0.0f);
}

void SphereUI::ImageCtrl::handleInput(const WindowInput& input) {
    if (image_style == 0u) return;
    const bool inside = containsPoint(input.mouse_x, input.mouse_y);
    if ((image_style & 2u) != 0u && inside != (interaction_active)) {
        notifyParent(*this, inside ? UiMessage::pointerEnter : UiMessage::pointerLeave);
        interaction_active = inside;
    }
    if (inside && (image_style & 1u) != 0u && (input.mouse_flags & MouseInput::leftPress) != 0u) {
        int left = 0;
        int top = 0;
        getAbsolutePosition(left, top);
        notifyParent(*this, UiMessage::leftClick, static_cast<std::uint32_t>(input.mouse_x) - static_cast<std::uint32_t>(left), static_cast<std::uint32_t>(input.mouse_y) - static_cast<std::uint32_t>(top));
        Runtime::playClickSound();
    }
}

void SphereUI::ImageCtrl::setOpacity(float new_opacity) {
    const std::uint32_t new_alpha = opacity_alpha(static_cast<double>(base_alpha) * new_opacity);
    alpha = new_alpha;
    replace_color_alpha(text_color, new_alpha);
    replace_color_alpha(disabled_color, new_alpha);
    opacity = new_opacity;
}


bool SphereUI::ListItemCtrl::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    loadPart(*this, vertical_scroll, reader, "vscrollbar", filename, parser, UiControlKind::scrollBar, 1u);
    if (loadPart(*this, horizontal_scroll, reader, "hscrollbar", filename, parser, UiControlKind::scrollBar, 1u)) horizontal_scroll->orientation_flags |= 1u;
    SferaParserRange part{};
    if (reader.block("itemTemplate", part)) {
        auto original = std::make_unique<Window>();
        original->setParent(parent);
        if (!original->loadUi(filename, parser, part)) throw std::runtime_error("list item template could not be loaded");
        original->setParent(nullptr);
        original->hidden = false;
        original->resource_parent = parent;
        original->input_enabled = true;
        item_template = std::move(original);
    }
    int count = 0;
    reader.integer("createItems", count);
    for (int index = 0; index < count; ++index) addItem();
    reader.sprite("selectSprite", *this, selection_sprite);
    reader.integer("selectedItem", selected_index);
    if (selected_index < 0 || static_cast<std::size_t>(selected_index) >= items.size()) selected_index = -1;
    reader.boolean("canSelectItems", can_select);
    reader.boolean("horizontal", horizontal);
    reader.boolean("userMove", user_move);
    updateLayout();
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::ListItemCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](ListItemCtrl& destination, const ListItemCtrl& source, SphereUI::Window::CloneContext& context) {
        destination.copyItemState(source, context);
    });
}

std::uint32_t SphereUI::ListItemCtrl::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::horizontalScroll:
            horizontal_offset = first;
            updateVisibleRange();
            return 1u;
        case UiMessage::verticalScroll:
            vertical_offset = first;
            updateVisibleRange();
            return 1u;
        case UiMessage::updateScrollLayout:
            if (first != 0u) updateLayout();
            else for (auto address : {vertical_scroll.get(), horizontal_scroll.get()}) if (auto* bar = address) bar->setParameters({0u, ScrollField::all, 0, 0, 0, 0, 0});
            return 1u;
        case UiMessage::appendListItem:
            addItem();
            updateLayout();
            return 1u;
        case UiMessage::getListItemSelection:
            storeValue(first, selected_index);
            return 1u;
        case UiMessage::setListItemSelection:
            selected_index = first < items.size() ? static_cast<int>(first) : -1;
            return 1u;
        case UiMessage::getListItemCount:
            storeValue(first, items.size());
            return 1u;
        case UiMessage::removeListItem:
            if (first < items.size()) {
                removeItem(first);
                updateLayout();
            }
            return 1u;
        case UiMessage::clearListItems:
            clearItems();
            updateLayout();
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

void SphereUI::ListItemCtrl::draw() {
    if (hidden || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    drawChild(vertical_scroll.get(), alpha);
    drawChild(horizontal_scroll.get(), alpha);
    if (item_template == nullptr) return;
    const auto end = std::min(visible_end, static_cast<int>(items.size()));
    {
        ViewportScope viewport(windowBounds(*this));
        if (!viewport) return;
        if (selected_index >= std::max(visible_begin, 0) && selected_index < end) if (auto* item = itemAt(selected_index)) {
            const float left = item->x, top = item->y, right = detail::addCoordinate(item->x, item->width), bottom = detail::addCoordinate(item->y, item->height);
            if (selection_sprite != nullptr) selection_sprite->draw(left, top, right, bottom, SferaColor::rgba(255u, 255u, 255u, alpha).argb());
            else InterfaceRenderer::drawTexture(nullptr, left, top, right, bottom, text_color, 0.0f, 0.0f, false);
        }
        for (auto index = std::max(visible_begin, 0); index < end; ++index) if (auto* item = itemAt(index)) item->draw();
    }
    for (auto index = std::max(visible_begin, 0); index < end; ++index) if (auto* item = itemAt(index)) item->drawToolTips();
}

void SphereUI::ListItemCtrl::handleInput(const WindowInput& input) {
    if (hidden) return;
    inputChild(vertical_scroll.get(), input);
    inputChild(horizontal_scroll.get(), input);
    if (!can_select) selected_index = -1;
    for (std::size_t index = 0u; index < items.size(); ++index) if (auto* item = itemAt(index)) {
        WindowEvent event{};
        while (item->pollEvent(event)) if (auto* owner = parent) owner->queueEvent({this, control_id, UiMessage::listItemEvent, static_cast<std::uint32_t>(event.message), static_cast<std::uint32_t>(MAKELONG(index, event.control_id))});
    }
    const auto bounds = windowBounds(*this);
    const bool inside = contains(bounds, input.mouse_x, input.mouse_y);
    WindowInput forwarded = input;
    if (!inside) forwarded.mouse_x = forwarded.mouse_y = 65535;
    const auto* original = item_template.get();
    if (original == nullptr) return;
    const auto end = std::min(visible_end, static_cast<int>(items.size()));
    auto item_x = detail::subtractCoordinate(bounds.left, cropped_x), item_y = detail::subtractCoordinate(bounds.top, cropped_y);
    for (auto index = std::max(visible_begin, 0); index < end; ++index) if (auto* item = itemAt(index)) {
        if (user_move) item->setParent(this);
        else item->setPosition(item_x, item_y);
        item->handleInput(forwarded);
        if (horizontal) item_x = detail::addCoordinate(item_x, original->width);
        else item_y = detail::addCoordinate(item_y, original->height);
    }
    if (!can_select || !inside || (input.mouse_flags & MouseInput::leftPress) == 0u) return;
    int selected = -1;
    for (auto index = std::max(visible_begin, 0); index < end; ++index) if (auto* item = itemAt(index)) if (contains(windowBounds(*item), input.mouse_x, input.mouse_y)) {
        selected = index;
        break;
    }
    if (selected != selected_index) {
        notifyParent(*this, UiMessage::listItemSelectionChanged, static_cast<std::uint32_t>(selected));
        selected_index = selected;
    }
}

void SphereUI::ListItemCtrl::setOpacity(float opacity) {
    const auto new_alpha = opacity_alpha(opacity * 255.0);
    alpha = new_alpha;
    replace_color_alpha(text_color, new_alpha);
    if (auto* original = item_template.get()) original->setOpacity(opacity);
    for (std::size_t index = 0u; index < items.size(); ++index) if (auto* item = itemAt(index)) item->setOpacity(opacity);
}

bool SphereUI::ListItemCtrl::hitTest(int screen_x, int screen_y) {
    const auto end = std::min(visible_end, static_cast<int>(items.size()));
    if (hidden || visible_begin >= end) return false;
    for (auto index = std::max(visible_begin, 0); index < end; ++index) if (auto* child = itemAt(index)) if (child->can_drag_drop && child->containsPoint(screen_x, screen_y) && child->hitTest(screen_x, screen_y)) break;
    return true;
}

void SphereUI::ListItemCtrl::dispatchMessage(int target_group, SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second, SphereUI::UiControlKind target_kind) {
    for (std::size_t index = 0u; index < items.size(); ++index) if (auto* child = itemAt(index)) child->dispatchMessage(target_group, message, first, second, target_kind);
}


bool SphereUI::ToolTipCtrl::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    reader.integer("font", font);
    reader.color("textColor", text_color);
    reader.color("backcolor", background_color);
    reader.rectangle("margin", margin_left, margin_top, margin_right, margin_bottom);
    parser.setScanRange(&range);
    try {
        while (parser.nextValue("toolstr")) {
            const char* key = reader.token();
            if (key != nullptr) appendLine(g_sfera_interface.localizedText(key));
        }
    } catch (...) {
        parser.clearScanRange();
        throw;
    }
    parser.clearScanRange();
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::ToolTipCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](ToolTipCtrl& destination, const ToolTipCtrl& source, SphereUI::Window::CloneContext& context) {

        copyProperties(destination, source,
            &ToolTipCtrl::screen_x, &ToolTipCtrl::screen_y, &ToolTipCtrl::hover_pending, &ToolTipCtrl::hover_started,
            &ToolTipCtrl::fade_opacity, &ToolTipCtrl::fade_started, &ToolTipCtrl::background_color, &ToolTipCtrl::tooltip_width,
            &ToolTipCtrl::tooltip_height, &ToolTipCtrl::dismissed, &ToolTipCtrl::line_height, &ToolTipCtrl::margin_left,
            &ToolTipCtrl::margin_top, &ToolTipCtrl::margin_right, &ToolTipCtrl::margin_bottom, &ToolTipCtrl::lines);
    });
}

std::uint32_t SphereUI::ToolTipCtrl::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::setTooltipLine:
            setLine(first, reinterpret_cast<const char*>(second));
            return 1u;
        case UiMessage::getTooltipLine:
            if (first != 0u && second < lines.size()) copyMessageText(reinterpret_cast<char*>(first), lines.at(second).data());
            return 1u;
        case UiMessage::appendTooltipLine:
            appendLine(reinterpret_cast<const char*>(first));
            return 1u;
        case UiMessage::setTooltipBackground:
            background_color = first;
            return 1u;
        case UiMessage::setTooltipTextColor:
            text_color = first;
            return 1u;
        default:
            return message >= UiMessage::setTooltipLine && message <= UiMessage::setTooltipTextColor ? 0u : Window::handleMessage(message, first, second);
    }
}

void SphereUI::ToolTipCtrl::draw() {
    if (hidden) return;
    const auto screen = Runtime::screenSize();
    screen_x = std::max(0, std::min(screen_x, detail::subtractCoordinate(screen.width, tooltip_width)));
    screen_y = std::max(0, std::min(screen_y, detail::subtractCoordinate(screen.height, tooltip_height)));
    const auto* owner = parent;
    const std::uint32_t opacity = std::clamp(static_cast<float>(owner == nullptr ? alpha : owner->alpha) * fade_opacity, 0.0f, 255.0f);
    text_color = SferaColor::fromArgb(text_color).withAlpha(opacity).argb();
    const auto right = detail::addCoordinate(screen_x, tooltip_width), bottom = detail::addCoordinate(screen_y, tooltip_height);
    const float leftf = screen_x, topf = screen_y, rightf = right, bottomf = bottom;
    InterfaceRenderer::drawTexture(nullptr, leftf, topf, rightf, bottomf, SferaColor::fromArgb(background_color).withAlpha(SferaColor::fromArgb(background_color).alpha() | opacity).argb(), 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, leftf, topf, rightf, topf + 1.0f, text_color, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, leftf, bottomf - 1.0f, rightf, bottomf, text_color, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, leftf, topf, leftf + 1.0f, bottomf, text_color, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, rightf - 1.0f, topf, rightf, bottomf, text_color, 0.0f, 0.0f, false);
    const auto text_x = detail::addCoordinate(screen_x, margin_left);
    auto text_y = detail::addCoordinate(screen_y, margin_top);
    const UiRect clip{text_x, text_y, detail::addCoordinate(text_x, tooltip_width), detail::addCoordinate(text_y, tooltip_height)};
    for (std::size_t index = 0u; index < lines.size(); ++index) {
        InterfaceRenderer::drawText(lines.at(index).data(), text_x, text_y, text_color, font, true, clip, opacity == 255u);
        text_y = detail::addCoordinate(text_y, line_height);
    }
}

void SphereUI::ToolTipCtrl::handleInput(const WindowInput& input) {
    if (lines.size() == 0u || lines.at(0u).size() == 0u) {
        hidden = true;
        return;
    }
    updateFade();
    auto* owner = parent;
    if (owner == nullptr || owner->hidden) return;
    if ((input.mouse_flags & 3u) != 0u || input.wheel_delta != 0) {
        dismissed = true;
        hidden = true;
    }
    if (hidden && !dismissed) {
        if (!hover_pending || screen_x != input.mouse_x || screen_y != input.mouse_y) hover_pending = false;
        else if (static_cast<float>(static_cast<double>(static_cast<std::int64_t>(Runtime::clockTicks() - hover_started)) / 10000.0) > 0.5f) showAt(input.mouse_x, input.mouse_y);
    }
    if (!contains(windowBounds(*owner), input.mouse_x, input.mouse_y)) {
        reset();
        return;
    }
    if (!hover_pending && hidden) {
        hover_pending = true;
        screen_x = input.mouse_x;
        screen_y = input.mouse_y;
        hover_started = Runtime::clockTicks();
    }
}


std::unique_ptr<SphereUI::Window> SphereUI::CMinimapControl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](CMinimapControl& target, const CMinimapControl& source, SphereUI::Window::CloneContext&) {
        if (source.parent) target.resource_reference = target.getResource("arup");
    });
}

void SphereUI::CMinimapControl::draw() {
    if (hidden) return;
    const auto bounds = windowBounds(*this);
    const float left = bounds.left, top = bounds.top;
    InterfaceRenderer::drawTexture(g_sfera_graphics_runtime.d3d_runtime->minimapTexture().native_texture.Get(), left, top, left + 256.0f, top + 256.0f, SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    float heading = 0.0f;
    if (Runtime::playerHeading(heading) && resource_reference != nullptr) {
        int parent_x = 0, parent_y = 0;
        if (auto* owner = parent) owner->getAbsolutePosition(parent_x, parent_y);
        const float arrow_x = detail::addCoordinate(parent_x, 127), arrow_y = detail::addCoordinate(parent_y, 132);
        resource_reference->draw(arrow_x, arrow_y, arrow_x + 28.0f, arrow_y + 28.0f, UiColor::white, -heading);
    }
}

void SphereUI::ProgressBar::initializeProgressState() {
    minimum = 0;
    maximum = 100;
    current = 0;
    progress_ratio = 0.0f;
    display_mode = 0u;
    status_text.clear();
    status_x = 0;
    status_y = 0;
}

void SphereUI::ProgressBar::setProgressValue(int value) {
    if (current == value) return;
    current = std::clamp(value, minimum, maximum);
    refreshProgressDisplay();
}

void SphereUI::ProgressBar::setProgressRange(int new_minimum, int new_maximum) {
    minimum = new_minimum;
    maximum = new_maximum;
    current = minimum;
    if (minimum >= maximum) maximum = detail::addCoordinate(minimum, 1);
    refreshProgressDisplay();
}

namespace {
    void updateStatusText(std::string& text, std::uint32_t mode, double percent, int current, int range) {
        if (mode == 1u) text = std::to_string(static_cast<int>(std::trunc(percent))) + "%";
        else if (mode == 2u) text = std::to_string(current) + " / " + std::to_string(range);
    }
}

void SphereUI::ProgressBar::refreshProgressDisplay() {
    const int range = detail::subtractCoordinate(maximum, minimum);
    progress_ratio = range == 0 ? 0.0f : std::min(std::fabs(static_cast<float>(current) / static_cast<float>(range)), 1.0f);
    updateStatusText(status_text, display_mode, progress_ratio * 100.0f, current, range);
}

bool SphereUI::ProgressBar::loadUi(const char* , SferaSimpleParser& parser, const SferaParserRange& range) {

    UiReader reader(parser, range);
    reader.drawMethod(*this);
    reader.status("statusShow", display_mode);
    if (reader.pair("range", minimum, maximum)) {
        if (minimum > maximum) std::swap(minimum, maximum);
        if (minimum == maximum) maximum = detail::addCoordinate(maximum, 1);
    }
    reader.integer("progressPos", current);
    if (minimum <= maximum) current = std::clamp(current, minimum, maximum);
    reader.pair("statusPos", status_x, status_y);
    refreshProgressDisplay();
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::ProgressBar::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](auto& target, const auto& source, SphereUI::Window::CloneContext& context) {

        copyProperties(target, source,
            &ProgressBar::minimum, &ProgressBar::maximum, &ProgressBar::current, &ProgressBar::progress_ratio,
            &ProgressBar::display_mode, &ProgressBar::status_text, &ProgressBar::status_x, &ProgressBar::status_y);
    });
}

std::uint32_t SphereUI::ProgressBar::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    if (message < UiMessage::setProgressValue || message > UiMessage::getProgressValue) return Window::handleMessage(message, first, second);
    switch (message) {
        case UiMessage::setProgressValue:
            setProgressValue(static_cast<int>(first));
            return 1u;
        case UiMessage::setProgressRange:
            setProgressRange(static_cast<int>(first), static_cast<int>(second));
            return 1u;
        case UiMessage::getProgressRange:
            storeValue(first, minimum);
            storeValue(second, maximum);
            return 1u;
        case UiMessage::getProgressValue:
            storeValue(first, current);
            return 1u;
        default:
            return 0u;
    }
}

void SphereUI::ProgressBar::draw() {
    if (hidden || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    if (progress_ratio > 0.0f && resource_reference != nullptr) resource_reference->draw(static_cast<float>(bounds.left), static_cast<float>(bounds.top), static_cast<float>(bounds.left) + static_cast<float>(width) * progress_ratio, static_cast<float>(bounds.bottom), SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    if (display_mode != 0u) {
        const auto left = detail::addCoordinate(bounds.left, status_x);
        const auto top = detail::addCoordinate(bounds.top, status_y);
        renderLabel(*this, status_text.c_str(), left, top, text_color, {left, top, detail::addCoordinate(left, 100), detail::addCoordinate(top, 100)});
    }
}

void SphereUI::ProgressBar::handleInput(const WindowInput& ) {

}

std::unique_ptr<SphereUI::Window> SphereUI::RadioButtonCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](auto& target, const auto& source, SphereUI::Window::CloneContext& context) {
        target.copyCheckState(source);
    });
}

void SphereUI::RadioButtonCtrl::playClickSound() {
    if (!checked) if (auto* owner = parent) owner->dispatchMessage(group, UiMessage::setChecked, 0u, 0u, UiControlKind::radioButton);
    checked = false;
    CheckBox::playClickSound();
}

bool SphereUI::ScrollBar::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    if (reader.has("horizontal") && parser.readBool(0u)) orientation_flags = 1u;
    reader.rectangle("bounds", track_left, track_top, track_right, track_bottom);
    reader.boolean("postMessage", notify_changes);
    reader.drawMethod(*this);
    if (reader.has("scrollSpr")) {
        const char* name = reader.token(0u, true);
        auto* owner = parent;
        scroll_resource = (owner == nullptr ? *this : *owner).getResource(name);
        thumb_width = parser.readInt(1u);
        thumb_height = parser.readInt(2u);
    }
    loadNavigationButtons(*this, reader, filename, parser, true);
    if (reader.has("deltaStep")) {
        step = parser.readInt(0u);
        explicit_step = true;
    }
    updateControlState();
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::ScrollBar::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, copyScrollFields);
}

std::uint32_t SphereUI::ScrollBar::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::setScrollValue:
            current = std::min(std::max(static_cast<int>(first), minimum), maximum);
            updateControlState();
            return 1u;
        case UiMessage::setScrollRange:
            minimum = current = first;
            maximum = second;
            enableNavigationButtons(*this);
            updateControlState();
            return 1u;
        case UiMessage::getScrollRange:
            storeValue(first, minimum);
            storeValue(second, maximum);
            return 1u;
        case UiMessage::setScrollParameters:
            if (auto* parameters = reinterpret_cast<const ScrollParameters*>(first)) setParameters(*parameters);
            return 1u;
        case UiMessage::getScrollParameters:
            if (auto* parameters = reinterpret_cast<ScrollParameters*>(first)) getParameters(*parameters);
            return 1u;
        case UiMessage::increaseScroll:
        case UiMessage::decreaseScroll:
            if (moveScroll(*this, message == UiMessage::increaseScroll, step)) loadControlParameters();
            return 1u;
        case UiMessage::getScrollValue:
            storeValue(first, current);
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

void SphereUI::ScrollBar::draw() {
    if (hidden || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    const auto color = SferaColor::rgba(255u, 255u, 255u, alpha).argb();
    if (resource_reference != nullptr) resource_reference->draw(static_cast<float>(bounds.left), static_cast<float>(bounds.top), static_cast<float>(bounds.right), static_cast<float>(bounds.bottom), color);
    if (maximum > minimum) {
        const auto left = detail::addCoordinate(bounds.left, thumb_x);
        const auto top = detail::addCoordinate(bounds.top, thumb_y);
        if (scroll_resource != nullptr) scroll_resource->draw(static_cast<float>(left), static_cast<float>(top), static_cast<float>(detail::addCoordinate(left, thumb_width)), static_cast<float>(detail::addCoordinate(top, thumb_height)), color);
    }
    drawChild(decrease_button.get(), alpha);
    drawChild(increase_button.get(), alpha);
}

void SphereUI::ScrollBar::handleInput(const WindowInput& input) {
    inputChild(decrease_button.get(), input);
    inputChild(increase_button.get(), input);
    bool changed = false;
    WindowEvent event{};
    while (pollEvent(event)) if (event.message == UiMessage::leftClick && (event.control_id == 1u || event.control_id == 2u)) if (moveScroll(*this, event.control_id == 2u, step)) {
        changed = true;
        Runtime::playScrollSound(false);
    }
    if (input.wheel_delta != 0) if (auto* owner = parent) if (contains(windowBounds(*owner), input.mouse_x, input.mouse_y)) {
        if (current != minimum && current != maximum) Runtime::playScrollSound(false);
        current = static_cast<std::uint32_t>(current) - static_cast<std::uint32_t>(step) * static_cast<std::uint32_t>(input.wheel_delta);
        current = std::max(std::min(current, maximum), minimum);
        updateControlState();
        changed = true;
    }
    const auto bounds = windowBounds(*this);
    const auto thumb_left = detail::addCoordinate(bounds.left, thumb_x);
    const auto thumb_top = detail::addCoordinate(bounds.top, thumb_y);
    if ((input.mouse_flags & MouseInput::leftPress) != 0u && !dragging_thumb) {
        if (contains({thumb_left, thumb_top, detail::addCoordinate(thumb_left, thumb_width), detail::addCoordinate(thumb_top, thumb_height)}, input.mouse_x, input.mouse_y)) dragging_thumb = true;
        if (contains(bounds, input.mouse_x, input.mouse_y)) page_click_active = true;
    }
    if ((input.mouse_buttons & 1u) == 0u) dragging_thumb = page_click_active = false;
    const bool horizontal = (orientation_flags & 1u) != 0u;
    const auto span = detail::subtractCoordinate(maximum, minimum);
    if (dragging_thumb) {
        const std::uint32_t dimension = horizontal ? width : height;
        const auto relative = std::max(detail::subtractCoordinate(horizontal ? input.mouse_x : input.mouse_y, horizontal ? bounds.left : bounds.top), 0);
        const auto position = std::min(static_cast<std::uint32_t>(relative), dimension);
        const auto fraction = dimension == 0u ? 0.0f : static_cast<float>(static_cast<double>(position) / dimension);
        const int value = std::trunc(static_cast<double>(fraction) * span);
        if (current != value) {
            current = value;
            updateControlState();
            changed = true;
        }
    }
    if (!changed && (input.key_code == VK_PRIOR || input.key_code == VK_NEXT)) if (moveScroll(*this, input.key_code == VK_NEXT, page_step)) {
        Runtime::playScrollSound(true);
        changed = true;
    }
    if (changed) {
        if (parent != nullptr) loadControlParameters();
        return;
    }
    if (dragging_thumb || !page_click_active || (input.mouse_buttons & 1u) == 0u) return;

    const float elapsed = static_cast<double>(static_cast<std::int64_t>(Runtime::clockTicks() - repeat_started_at)) / 10000.0;
    if (!(elapsed > 0.1f)) return;
    repeat_started_at = Runtime::clockTicks();
    const UiRect track{detail::addCoordinate(bounds.left, track_left), detail::addCoordinate(bounds.top, track_top), detail::subtractCoordinate(bounds.right, track_right), detail::subtractCoordinate(bounds.bottom, track_bottom)};
    if (!contains(track, input.mouse_x, input.mouse_y)) return;
    const std::uint32_t dimension = horizontal ? detail::subtractCoordinate(track.right, track.left) : detail::subtractCoordinate(track.bottom, track.top);
    if (dimension == 0u) return;
    const auto position = detail::subtractCoordinate(horizontal ? input.mouse_x : input.mouse_y, horizontal ? track.left : track.top);
    const float fraction = static_cast<double>(position) / dimension;
    const int target = std::trunc(static_cast<double>(fraction) * span);
    if (current == target) return;
    const auto cursor = horizontal ? input.mouse_x : input.mouse_y;
    const auto thumb_start = horizontal ? thumb_left : thumb_top;
    const auto thumb_end = detail::addCoordinate(thumb_start, horizontal ? thumb_width : thumb_height);
    if (cursor < thumb_start) current = std::max(detail::subtractCoordinate(current, page_step), target);
    else if (cursor > thumb_end) current = std::min(detail::addCoordinate(current, page_step), target);
    else return;
    updateControlState();
    if (parent != nullptr) loadControlParameters();
}


void SphereUI::ScrollBar::updateControlState() {
    const auto span = detail::subtractCoordinate(maximum, minimum);
    normalized_position = span == 0 ? 0.0f : std::clamp(static_cast<float>(static_cast<double>(current) / span), 0.0f, 1.0f);
    const auto available_width = detail::subtractCoordinate(detail::subtractCoordinate(width, track_left), track_right);
    const auto available_height = detail::subtractCoordinate(detail::subtractCoordinate(height, track_top), track_bottom);
    const auto horizontal_space = detail::subtractCoordinate(available_width, thumb_width);
    const auto vertical_space = detail::subtractCoordinate(available_height, thumb_height);
    thumb_x = detail::addCoordinate(track_left, (orientation_flags & 1u) != 0u ? static_cast<int>(std::trunc(static_cast<double>(horizontal_space) * normalized_position)) : horizontal_space / 2);
    thumb_y = detail::addCoordinate(track_top, (orientation_flags & 1u) != 0u ? vertical_space / 2 : static_cast<int>(std::trunc(static_cast<double>(vertical_space) * normalized_position)));
}

void SphereUI::ScrollBar::loadControlParameters() {
    auto* owner = parent;
    if (owner == nullptr) return;
    const auto message = (orientation_flags & 1u) != 0u ? UiMessage::horizontalScroll : UiMessage::verticalScroll;
    owner->handleMessage(message, static_cast<std::uint32_t>(current), control_id);
    if (notify_changes) owner->queueEvent({this, control_id, message, static_cast<std::uint32_t>(current), 0u});
}

bool SphereUI::SliderCtrl::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    reader.pair("range", minimum, maximum);
    reader.integer("defaultPos", current);
    reader.integer("step", step);
    reader.integer("page", page_step);
    reader.pair("statusPos", status_x, status_y);
    reader.status("statusShow", display_mode);
    return ScrollBar::loadUi(filename, parser, range);
}

std::unique_ptr<SphereUI::Window> SphereUI::SliderCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](SliderCtrl& destination, const SliderCtrl& source, SphereUI::Window::CloneContext& context) {
        copyScrollFields(destination, source, context);
        destination.value_text = source.value_text;
        destination.display_mode = source.display_mode;
        destination.status_x = source.status_x;
        destination.status_y = source.status_y;
    });
}

void SphereUI::SliderCtrl::draw() {
    if (hidden) return;
    ScrollBar::draw();
    if (display_mode != 0u) {
        const auto bounds = windowBounds(*this);
        const auto left = detail::addCoordinate(bounds.left, status_x);
        const auto top = detail::addCoordinate(bounds.top, status_y);
        renderLabel(*this, value_text.c_str(), left, top, text_color, {left, top, detail::addCoordinate(left, 100), detail::addCoordinate(top, 100)});
    }
}

void SphereUI::SliderCtrl::updateControlState() {
    ScrollBar::updateControlState();
    updateStatusText(value_text, display_mode, normalized_position * 100.0, current, detail::subtractCoordinate(maximum, minimum));
}

void SphereUI::SliderCtrl::loadControlParameters() {
    if (auto* owner = parent) owner->queueEvent({this, control_id, UiMessage::sliderValueChanged, static_cast<std::uint32_t>(current), 0u});
}

bool SphereUI::SlotCtrl::hitTest(int , int ) {

    if (hidden) return false;
    if (auto* owner = parent) owner->queueEvent({this, control_id, UiMessage::slotHitTest, 0u, 0u});
    return true;
}

void SphereUI::SpinButton::setRange(int new_minimum, int new_maximum) {
    minimum = new_minimum;
    maximum = new_maximum;
    status_valid = false;
}

void SphereUI::SpinButton::setCurrentValue(int value) {
    current = value;
    status_valid = false;
    update_enabled = false;
}

void SphereUI::SpinButton::setStep(int new_step) {
    step = new_step;
}

int SphereUI::SpinButton::currentValue() const {
    return current;
}

bool SphereUI::SpinButton::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    bool defaults = true;
    reader.boolean("defButtonStyle", defaults);
    loadNavigationButtons(*this, reader, filename, parser, defaults, 0.15f);
    reader.pair("range", minimum, maximum);
    reader.integer("spinPos", current);
    reader.integer("badyCtrlID", body_index);
    reader.boolean("notifyChange", notify_changes);
    status_valid = false;
    step = 1;
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::SpinButton::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, copySpinFields);
}

std::uint32_t SphereUI::SpinButton::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::setSpinValue:
            setCurrentValue(static_cast<int>(first));
            return 1u;
        case UiMessage::setSpinRange:
            setRange(static_cast<int>(first), static_cast<int>(second));
            return 1u;
        case UiMessage::getSpinRange:
            storeValue(first, minimum);
            storeValue(second, maximum);
            return 1u;
        case UiMessage::updateSpinStatus:
            updateStatus();
            return 1u;
        case UiMessage::setSpinStep:
            setStep(static_cast<int>(first));
            return 1u;
        case UiMessage::getSpinStep:
            storeValue(first, step);
            return 1u;
        case UiMessage::getSpinValue:
            storeValue(first, current);
            return 1u;
        default:
            break;
    }
    if (message == UiMessage::setEnabled || message == UiMessage::setHidden) {
        if (auto* window = decrease_button.get()) window->handleMessage(message, first, second);
        if (auto* window = increase_button.get()) window->handleMessage(message, first, second);
    }
    return Window::handleMessage(message, first, second);
}

void SphereUI::SpinButton::draw() {
    if (hidden) return;
    drawChild(decrease_button.get(), alpha);
    drawChild(increase_button.get(), alpha);
}

void SphereUI::SpinButton::handleInput(const WindowInput& input) {
    if (hidden) return;
    if (!disabled) {
        if (auto* window = increase_button.get()) window->handleMessage(UiMessage::setEnabled, current != maximum, 0u);
        if (auto* window = decrease_button.get()) window->handleMessage(UiMessage::setEnabled, current != minimum, 0u);
    }
    inputChild(decrease_button.get(), input);
    inputChild(increase_button.get(), input);
    WindowEvent event{};
    while (pollEvent(event)) {
        if (event.message != UiMessage::leftClick) continue;
        if (event.control_id == 1u && current >= detail::addCoordinate(minimum, step)) {
            current = detail::subtractCoordinate(current, step);
            status_valid = false;
        }
        if (event.control_id == 2u && current <= detail::subtractCoordinate(maximum, step)) {
            current = detail::addCoordinate(current, step);
            status_valid = false;
        }
    }
    if (!status_valid) updateStatus();
}


void SphereUI::SpinButton::updateStatus() {
    auto* owner = parent;
    if (owner == nullptr) return;
    Window* body = body_index == invalidIndex ? nullptr : owner->controlAt(body_index);
    if (current < minimum) current = minimum;
    if (current > maximum) current = maximum;
    if (current != previous) {
        if (auto* window = body) {
            char value[32];
            std::snprintf(value, sizeof(value), "%d", current);
            window->setText(value);
        }
        if (notify_changes && update_enabled) owner->queueEvent({this, control_id, UiMessage::spinValueChanged, static_cast<std::uint32_t>(current), 0u});
        previous = current;
    }
    status_valid = true;
    update_enabled = true;
}

bool SphereUI::TextCtrl::loadUi(const char* , SferaSimpleParser& parser, const SferaParserRange& range) {

    UiReader reader(parser, range);
    if ((width == 0 || height == 0) && text.size() != 0u) {
        const auto extent = InterfaceRenderer::measureText(getText(), font, font_initialized);
        width = extent.width;
        height = extent.height;
    }
    reader.flags("textStyle", text_style, textStyles, true);
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::TextCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](auto& target, const auto& source, SphereUI::Window::CloneContext& context) {
        target.text_style = source.text_style;
    });
}

void SphereUI::TextCtrl::draw() {
    if (!hidden && text.size() != 0u) alignedLabel(*this, text_color);
}

void SphereUI::TextCtrl::handleInput(const WindowInput& input) {
    if ((text_style & 1u) != 0u && (input.mouse_flags & MouseInput::leftPress) != 0u && containsPoint(input.mouse_x, input.mouse_y)) notifyParent(*this, UiMessage::leftClick);
}

void SphereUI::Window::setParent(Window* new_parent) {
    parent = new_parent;
}

void SphereUI::Window::getAbsolutePosition(int& screen_x, int& screen_y) const {
    screen_x = x;
    screen_y = y;
    for (auto* ancestor = parent; ancestor != nullptr; ancestor = ancestor->parent) {
        screen_x = detail::addCoordinate(screen_x, ancestor->x);
        screen_y = detail::addCoordinate(screen_y, ancestor->y);
    }
}

bool SphereUI::Window::containsPoint(int screen_x, int screen_y) const {
    int left = 0;
    int top = 0;
    getAbsolutePosition(left, top);
    return screen_x >= left && screen_x < detail::addCoordinate(left, width) && screen_y >= top && screen_y < detail::addCoordinate(top, height);
}

int SphereUI::Window::childControlAt(int screen_x, int screen_y) const {
    if (hidden) return 0;
    if (!containsPoint(screen_x, screen_y)) return -1;
    for (auto it = children.rbegin(); it != children.rend(); ++it) {
        const auto& child = *it;
        if (!child->hidden && child->containsPoint(screen_x, screen_y)) return child->control_id;
    }
    return 0;
}

void SphereUI::Window::clearEvents() {
    events.clear();
}

void SphereUI::Window::queueEvent(const WindowEvent& event) {
    detail::enqueueWindowEvent(events, event);
}

bool SphereUI::Window::pollEvent(WindowEvent& event) {
    if (events.empty()) return false;
    event = events.front();
    events.pop_front();
    return true;
}

void SphereUI::Window::processEvents() {
    if (!g_sfera_interface.hasEventHandler(this)) return;
    const auto identity = registration_id;
    WindowEvent event{};
    while (g_sfera_interface.isRegistered(this, identity) && pollEvent(event)) g_sfera_interface.dispatchEvent(this, event);
}

namespace {
    void drawChild(SphereUI::Window* address, std::uint32_t alpha) {
        if (auto* child = address) {
            if (child->alpha != alpha) child->setOpacity(static_cast<float>(alpha / 255.0));
            child->draw();
        }
    }

    void inputChild(SphereUI::Window* address, const SphereUI::WindowInput& input) {
        if (auto* child = address) child->handleInput(input);
    }

    template<class Value> void storeValue(std::uintptr_t address, Value value) {
        if (address == 0) return;
        if constexpr (sizeof(Value) > sizeof(std::uint32_t)) {
            if (std::cmp_greater(value, std::numeric_limits<std::uint32_t>::max()) || (std::is_signed_v<Value> && std::cmp_less(value, std::numeric_limits<int>::min()))) throw std::overflow_error("UI result exceeds an MBC word");
        }
        const auto word = value;
        std::memcpy(reinterpret_cast<void*>(address), &word, sizeof(word));
    }
}

const char* SphereUI::Window::getText() const {
    return text.c_str();
}

const char* SphereUI::Window::getHelp() const {
    return help.c_str();
}

void SphereUI::Window::setText(const char* value) {
    text.assign(value == nullptr ? "" : value);
}

void SphereUI::Window::setHelp(const char* value) {
    help.assign(value == nullptr ? "" : value);
}

const char* SphereUI::Window::getName() const {
    return name.c_str();
}

const char* SphereUI::Window::getResourceName() const {
    return resource_name.c_str();
}

void SphereUI::Window::setName(const char* value) {
    name.assign(value == nullptr ? "" : value);
}

void SphereUI::Window::setResourceName(const char* value) {
    resource_name.assign(value == nullptr ? "" : value);
}

void SphereUI::ButtonCtrl::click() {
    if (auto* owner = parent) {
        WindowEvent event{this, control_id, UiMessage::leftClick, 0u, 0u};
        owner->queueEvent(event);
        if ((button_flags & ButtonStyle::sendClose) != 0u) {
            event.message = UiMessage::close;
            owner->queueEvent(event);
        }
    }
    if ((button_flags & ButtonStyle::showHelp) != 0u) g_sfera_interface.showHelpPage(getHelp());
}

void SphereUI::ImageCtrl::setImage(const ImageDescription* description) {
    if (description == nullptr) { resource_reference.reset(); return; }
    if (resource_reference && SferaSimpleParser::equalsIgnoreCase(resource_reference->name.c_str(), description->name)) return;
    auto replacement = parent ? parent->findResource(description->name) : nullptr;
    if (!replacement) replacement = g_sfera_interface.sharedSprite(description->name);
    if (!replacement) {
        auto image = std::make_shared<UiSprite>();
        image->setDescription(*description);
        fallback_image = image;
        replacement = std::move(image);
    }
    resource_reference = std::move(replacement);
}

std::unique_ptr<SphereUI::Window> SphereUI::Window::createControl(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range, SphereUI::UiControlKind kind, std::uint32_t id) {
    if (kind == anyControlKind) return nullptr;
    auto control = Runtime::makeControl(kind);
    if (control == nullptr) return nullptr;
    UiReader reader(parser, range);
    SferaParserRange tip_range{};
    if (reader.block("tooltip", tip_range)) {
        auto tip = std::make_unique<ToolTipCtrl>();
        if (tip != nullptr) {
            tip->setParent(control.get());
            if (tip->loadUi(filename, parser, tip_range)) control->tooltip = std::move(tip);
        }
    }
    reader.pair("position", control->x, control->y);
    reader.pair("size", control->width, control->height);
    reader.color("disabledColor", control->disabled_color);
    if (reader.pair("showTitle", control->text_offset_x, control->text_offset_y)) control->behavior_flags |= WindowStyle::showTitle;
    reader.boolean("disabled", control->disabled);
    reader.boolean("hidden", control->hidden);
    reader.integer("group", control->group);
    if (reader.has("font")) {
        control->font = static_cast<std::uint8_t>(parser.readInt(0u));
        control->font_initialized = true;
    }
    reader.flags("textFormat", control->text_alignment, textAlignments, true);
    reader.color("textColor", control->text_color);
    if (const char* value = reader.string("windowText")) control->setText(g_sfera_interface.localizedText(value));
    if (const char* value = reader.string("windowHelp", true)) control->setHelp(value);
    if (const char* value = reader.string("setWindowText", true)) control->setText(value);
    reader.boolean("canDragDrop", control->can_drag_drop);
    control->parent = parent == nullptr ? this : parent;
    if (!control->loadUi(filename, parser, range)) return nullptr;
    control->control_id = id;
    return control;

}

SphereUI::FontPicker::FontPicker() {
    hidden = false;
    control_kind = UiControlKind::fontPicker;
}

SphereUI::SpinButton::SpinButton() {
    maximum = 100;
    previous = -1;
    step = 1;
    body_index = invalidIndex;
    status_valid = notify_changes = hidden = false;
    update_enabled = true;
    control_kind = UiControlKind::spinButton;
}

SphereUI::ScrollBar::ScrollBar() {
    maximum = 100;
    step = 1;
    page_step = 20;
    dragging_thumb = explicit_step = notify_changes = page_click_active = hidden = false;
    control_kind = UiControlKind::scrollBar;
}

SphereUI::SliderCtrl::SliderCtrl() {
    control_kind = UiControlKind::slider;
    orientation_flags = 1u;
}

void SphereUI::ScrollBar::setParameters(const ScrollParameters& parameters) {
    if ((parameters.mask & ScrollField::range) != 0u) {
        minimum = parameters.minimum;
        maximum = parameters.maximum;
        enableNavigationButtons(*this);
    }
    if ((parameters.mask & ScrollField::position) != 0u) current = std::min(std::max(parameters.current, minimum), maximum);
    if ((parameters.mask & ScrollField::page) != 0u) page_step = parameters.page_step;
    if ((parameters.mask & ScrollField::step) != 0u && !explicit_step) step = parameters.step;
    updateControlState();
}

void SphereUI::ScrollBar::getParameters(ScrollParameters& parameters) const {
    parameters.minimum = minimum;
    parameters.maximum = maximum;
    parameters.page_step = page_step;
    parameters.current = current;
    parameters.step = step;
}

SphereUI::ToolTipCtrl::ToolTipCtrl() {
    background_color = UiColor::tooltipBackground;
    text_color = 0u;
    font = 2u;
    control_kind = UiControlKind::tooltip;
    hidden = true;
    tooltip_width = 52;
    tooltip_height = 12;
    margin_left = 3;
    margin_top = 1;
    margin_right = 2;
    margin_bottom = 1;
}

void SphereUI::ToolTipCtrl::reset() {
    fade_opacity = 0.0f;
    hidden = true;
    hover_pending = dismissed = false;
}

void SphereUI::ToolTipCtrl::showAt(int x, int y) {
    if (fade_opacity == 0.0f) fade_started = Runtime::clockTicks();
    hidden = false;
    screen_x = detail::addCoordinate(x, 10);
    screen_y = detail::addCoordinate(y, 20);
}

void SphereUI::ToolTipCtrl::updateFade() {
    if (hidden || fade_opacity == 1.0f) return;
    const std::int64_t elapsed = Runtime::clockTicks() - fade_started;
    fade_opacity = std::min(static_cast<float>(static_cast<double>(elapsed) / 10000.0) * 4.0f, 1.0f);
}

void SphereUI::ToolTipCtrl::updateLayout() {
    int widest = 0, total = 0;
    line_height = 0;
    for (std::size_t index = 0u; index < lines.size(); ++index) {
        const auto extent = InterfaceRenderer::measureText(lines.at(index).data(), font, true);
        widest = std::max(widest, extent.width);
        total = detail::addCoordinate(total, extent.height);
        line_height = extent.height;
    }
    tooltip_width = detail::addCoordinate(widest, detail::addCoordinate(margin_left, margin_right));
    tooltip_height = detail::addCoordinate(total, detail::addCoordinate(margin_top, margin_bottom));
}

void SphereUI::ToolTipCtrl::appendLine(const char* text) {
    if (text == nullptr) return;
    lines.emplace_back(text == nullptr ? "" : text);
    updateLayout();
}

void SphereUI::ToolTipCtrl::setLine(std::uint32_t index, const char* text) {
    if (index >= lines.size()) {
        appendLine(text);
        return;
    }
    if (text == nullptr) text = "";
    if (std::strcmp(lines.at(index).data(), text) == 0) return;
    lines.at(index).assign(text == nullptr ? "" : text);
    updateLayout();
}

void SphereUI::Window::resetToolTips() {
    if (auto* tip = tooltip.get()) tip->reset();
    detail::forEachChild(*this, [](Window& child) {
        child.resetToolTips();
    });
}

SphereUI::CDescriptionWindow::CDescriptionWindow() {
    auto* original = g_sfera_interface.templateWindow("objdesc2");
    if (original == nullptr) throw std::runtime_error("description template objdesc2 is missing");
    CloneContext context;
    Window::initializeCopy(*original, context);
    context.finish();
    displayed_source = pending_source = nullptr; show_deadline = hide_deadline = 0u;
    const char* names[] = {"window_caption", "window_bottom", "window_left", "window_right"};
    std::shared_ptr<const UiSprite>* sprites[] = {&caption_sprite, &bottom_sprite, &left_sprite, &right_sprite};
    for (std::size_t index = 0u; index < 4u; ++index) {
        *sprites[index] = findResource(names[index]);
        if (*sprites[index] == 0u) throw std::runtime_error(std::string("description sprite is missing: ") + names[index]);
    }
    Window* content = nullptr;
    detail::forEachChild(*this, [&](Window& child) {
        if (content == nullptr) content = &child;
    });
    if (content == nullptr) throw std::runtime_error("description content control is missing");
    frame_height = detail::subtractCoordinate(height, content->height);
    g_sfera_interface.bindEventHandler(this, WindowEventHandler::description);
    close();
}

std::unique_ptr<SphereUI::Window> SphereUI::CDescriptionWindow::cloneInto(CloneContext& context) const {
    auto copy = std::unique_ptr<CDescriptionWindow>(new CDescriptionWindow(std::in_place));
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

SphereUI::CDescriptionWindow* SphereUI::CDescriptionWindow::instance() {
    if (auto* existing = Runtime::descriptionWindow()) return existing;
    auto window = std::make_unique<CDescriptionWindow>();
    auto* result = window.get();
    g_sfera_interface.addTopLevelWindow(std::move(window));
    Runtime::setDescriptionWindow(result);
    return result;
}

void SphereUI::CDescriptionWindow::close() {
    displayed_source = pending_source = nullptr;
    hidden = true;
    resetToolTips();
    input_enabled = false;
}

void SphereUI::CDescriptionWindow::update() {
    if (Runtime::keyDown(42u) || Runtime::keyDown(54u)) return;
    if ((!Runtime::descriptionAutoPopup() && !pinned) || (!hidden && Runtime::milliseconds() >= hide_deadline)) close();
}

void SphereUI::CDescriptionWindow::handleEvent(const WindowEvent& event) {
    if (event.message == UiMessage::close || (event.message == UiMessage::leftClick && event.control_id == 2u)) close();
}

SferaCursorPosition* SphereUI::CDescriptionWindow::calculatePosition(SferaCursorPosition* output) const {
    if (output == nullptr) return nullptr;
    const auto cursor = CCursorManager::instance().geometry();
    const auto screen = Runtime::screenSize();
    const auto axis = [](int position, int extent, int limit, int size, bool centered) {
        const auto before = centered ? size / 2 : 0;
        const auto after = centered ? size / 2 : size;
        const auto start = detail::addCoordinate(position, after);
        if (detail::addCoordinate(start, extent) <= limit) return start;
        const auto reverse = detail::subtractCoordinate(detail::subtractCoordinate(position, extent), before);
        return reverse >= 0 ? reverse : detail::subtractCoordinate(limit, extent);
    };
    output->x = axis(cursor.x, width, screen.width, cursor.width, cursor.centered);
    output->y = axis(cursor.y, height, screen.height, cursor.height, cursor.centered);
    return output;
}

void SphereUI::CDescriptionWindow::showDescription(const char* text, const Window* source, std::uint32_t duration, bool pin) {
    if (text == nullptr) text = "";
    Window* content = nullptr;
    detail::forEachChild(*this, [&](Window& child) {
        if (content == nullptr) content = &child;
    });
    if (content == nullptr) throw std::runtime_error("description content control is missing");
    content->handleMessage(UiMessage::loadHyperTextBuffer, reinterpret_cast<std::uintptr_t>(text), std::strlen(text));
    content->handleMessage(UiMessage::resizeToHyperText, 0u, 0u);
    height = detail::addCoordinate(frame_height, content->height);
    SferaCursorPosition position{};
    calculatePosition(&position);
    setPosition(position.x, position.y);
    displayed_source = pending_source = source;
    hide_deadline = Runtime::milliseconds() + duration;
    pinned = pin ? 1u : 0u;
    hidden = false;
    input_enabled = true;
}

void SphereUI::CDescriptionWindow::requestDescription(const char* text, bool force, const Window* source) {
    if (text == nullptr || text[0] == '\0') return;
    if (force) {
        showDescription(text, source, 250u, false);
        return;
    }
    if (!Runtime::descriptionAutoPopup() || Runtime::keyDown(42u) || Runtime::keyDown(54u)) return;
    if (pending_source != source) {
        pending_source = source;
        show_deadline = Runtime::milliseconds() + 500u;
    }
    if (displayed_source == pending_source) hide_deadline = Runtime::milliseconds() + 250u;
    else if (Runtime::milliseconds() >= show_deadline) showDescription(text, pending_source, 250u, false);
}

SphereUI::ListItemCtrl::ListItemCtrl() {
    selected_index = -1;
    hidden = false;
    control_kind = UiControlKind::listItem;
}

SphereUI::Window* SphereUI::ListItemCtrl::itemAt(std::size_t index) const {
    return index < items.size() ? items.at(index).get() : nullptr;
}

int SphereUI::ListItemCtrl::addItem() {
    if (!item_template) return -1;
    std::unique_ptr<Window> item(item_template->clone());
    if (!item) return -1;
    item->hidden = false;
    items.push_back(std::move(item));
    return static_cast<int>(items.size() - 1u);
}

void SphereUI::ListItemCtrl::clearItems() {
    items.clear();
}

void SphereUI::ListItemCtrl::removeItem(std::size_t index) {
    if (index >= items.size()) return;
    items.erase(items.begin() + index);
    bool changed = index == static_cast<std::uint32_t>(selected_index);
    if (changed) selected_index = -1;
    if (selected_index < 0 || static_cast<std::size_t>(selected_index) >= items.size()) {
        selected_index = items.size() - 1u;
        changed = true;
    }
    if (changed && can_select) notifyParent(*this, UiMessage::listItemSelectionChanged, static_cast<std::uint32_t>(selected_index));
}

void SphereUI::ListItemCtrl::updateVisibleRange() {
    const auto* original = item_template.get();
    if (original == nullptr) return;
    horizontal_offset = std::clamp(horizontal_offset, 0, std::max(maximum_x, 0));
    vertical_offset = std::clamp(vertical_offset, 0, std::max(maximum_y, 0));
    const auto extent = !horizontal ? original->height : original->width;
    const auto offset = !horizontal ? vertical_offset : horizontal_offset;
    const auto fraction = extent > 0 ? static_cast<float>(offset) / static_cast<float>(extent) : 0.0f;
    const auto integral = std::floor(fraction);
    const auto cropped = extent > 0 ? static_cast<int>((fraction - integral) * static_cast<float>(extent)) : 0;
    visible_begin = integral;
    visible_end = std::min(detail::addCoordinate(detail::addCoordinate(visible_begin, visible_capacity), 1), static_cast<int>(items.size()));
    cropped_x = !horizontal ? horizontal_offset : cropped;
    cropped_y = !horizontal ? cropped : vertical_offset;
    if (user_move) {
        cropped_x = cropped_y = visible_begin = 0;
        visible_end = items.size();
    }
}

void SphereUI::ListItemCtrl::updateLayout() {
    const auto* original = item_template.get();
    if (original == nullptr) return;
    const auto extent = !horizontal ? original->height : original->width;
    const auto available = !horizontal ? height : width;
    visible_capacity = extent > 0 ? available / extent + 1 : 0;
    const auto total_width = horizontal ? static_cast<int>(items.size() * static_cast<std::uint32_t>(original->width)) : original->width;
    const auto total_height = !horizontal ? static_cast<int>(items.size() * static_cast<std::uint32_t>(original->height)) : original->height;
    maximum_x = std::max(0, detail::subtractCoordinate(total_width, width));
    maximum_y = std::max(0, detail::subtractCoordinate(total_height, height));
    horizontal_offset = std::clamp(horizontal_offset, 0, maximum_x);
    vertical_offset = std::clamp(vertical_offset, 0, maximum_y);
    if (auto* bar = vertical_scroll.get()) bar->setParameters({0u, ScrollField::all, 0, maximum_y, height, vertical_offset, static_cast<int>(static_cast<std::uint32_t>(original->height) / 10u + 1u)});
    if (auto* bar = horizontal_scroll.get()) bar->setParameters({0u, ScrollField::all, 0, maximum_x, width, horizontal_offset, static_cast<int>(static_cast<std::uint32_t>(maximum_x) / 10u + 1u)});
    updateVisibleRange();
}

void SphereUI::ListItemCtrl::copyItemState(const ListItemCtrl& source, CloneContext& context) {
    if (this == &source) return;
    clearItems();
    copyProperties(*this, source,
        &ListItemCtrl::horizontal_offset, &ListItemCtrl::vertical_offset, &ListItemCtrl::visible_begin, &ListItemCtrl::visible_end,
        &ListItemCtrl::visible_capacity, &ListItemCtrl::cropped_x, &ListItemCtrl::cropped_y, &ListItemCtrl::maximum_x,
        &ListItemCtrl::maximum_y, &ListItemCtrl::can_select, &ListItemCtrl::selection_sprite, &ListItemCtrl::selected_index,
        &ListItemCtrl::horizontal, &ListItemCtrl::user_move);
    cloneOwned(item_template, source.item_template, *this, context);
    if (item_template) item_template->parent = source.item_template->parent;
    items.reserve(source.items.size());
    for (const auto& item : source.items) items.push_back(item ? item->cloneInto(context) : nullptr);
    cloneOwned(vertical_scroll, source.vertical_scroll, *this, context);
    cloneOwned(horizontal_scroll, source.horizontal_scroll, *this, context);
}

void SphereUI::Window::drawToolTips() {
    detail::forEachChild(*this, [](Window& child) {
        if (!child.hidden) if (auto* tip = child.tooltip.get()) tip->draw();
    });
    if (auto* control = overlay) if (!control->hidden) control->draw();
}

SphereUI::ListCtrl::ListCtrl() {
    line_height = 1;
    selected_index = -1;
    selection_border = 3;
    selection_color = UiColor::listSelection;
    hidden = false;
    control_kind = UiControlKind::textList;
}

void SphereUI::ListCtrl::copyListState(const ListCtrl& source, CloneContext& context) {
    if (this == &source) return;
    copyProperties(*this, source,
        &ListCtrl::visible_begin, &ListCtrl::visible_end, &ListCtrl::rows, &ListCtrl::maximum_items, &ListCtrl::write_index,
        &ListCtrl::maximum_scroll, &ListCtrl::line_height, &ListCtrl::visible_capacity, &ListCtrl::vertical_offset,
        &ListCtrl::cropped_y, &ListCtrl::chatlike, &ListCtrl::format_strings, &ListCtrl::continue_mark, &ListCtrl::can_select,
        &ListCtrl::selected_index, &ListCtrl::selection_border, &ListCtrl::selection_color, &ListCtrl::selection_line_color,
        &ListCtrl::click_time, &ListCtrl::click_pending);
    cloneOwned(scrollbar, source.scrollbar, *this, context);
}

std::size_t SphereUI::ListCtrl::physicalIndex(std::size_t logical_index) const {
    const auto count = rows.size();
    if (logical_index >= count) throw std::out_of_range("UI logical row index");
    return maximum_items == 0u ? logical_index : static_cast<std::uint32_t>((static_cast<std::uint64_t>(write_index) + logical_index) % count);
}

void SphereUI::ListCtrl::updateVisibleRange() {
    vertical_offset = std::clamp(vertical_offset, 0, std::max(maximum_scroll, 0));
    const auto fraction = line_height > 0 ? static_cast<float>(vertical_offset) / static_cast<float>(line_height) : 0.0f;
    const auto integral = std::floor(fraction);
    cropped_y = line_height > 0 ? static_cast<int>((fraction - integral) * static_cast<float>(line_height)) : 0;
    visible_begin = integral;
    visible_end = std::min(detail::addCoordinate(detail::addCoordinate(visible_begin, visible_capacity), 1), static_cast<int>(rows.size()));
}

void SphereUI::ListCtrl::updateLayout() {
    visible_capacity = line_height > 0 ? height / line_height + 1 : 0;
    const int extent = rows.size() * static_cast<std::uint32_t>(line_height);
    maximum_scroll = height > extent ? 0 : std::max(0, detail::addCoordinate(detail::subtractCoordinate(extent, height), 1));
    if (auto* bar = scrollbar.get()) bar->setParameters({0u, ScrollField::all, 0, maximum_scroll, height, vertical_offset, line_height});
    updateVisibleRange();
}

void SphereUI::ListCtrl::appendLine(const char* text, std::uint32_t color) {
    if (parent != nullptr && selected_index != -1) {
        selected_index = -1;
        notifyParent(*this, UiMessage::listSelectionChanged, invalidIndex);
    }
    int offset = 0;
    if (text_alignment != 0u && text != nullptr) {
        const auto extent = InterfaceRenderer::measureText(text, font, font_initialized);
        const auto remainder = detail::subtractCoordinate(width, extent.width);
        if ((text_alignment & TextAlignment::right) != 0u) offset = remainder;
        if ((text_alignment & TextAlignment::horizontalCenter) != 0u) offset = std::abs(static_cast<std::int64_t>(remainder)) / 2;
    }
    appendCircular(rows, maximum_items, write_index, UiTextRow{text == nullptr ? " " : text, color, offset});
    updateLayout();
}

void SphereUI::ListCtrl::appendFormattedLine(const char* text, std::uint32_t color) {
    wrapTextLine(*this, text, format_strings, [&](const char* line) {
        appendLine(line, color);
    });
}

void SphereUI::ListCtrl::addText(const char* text, std::uint32_t color) {
    if (text == nullptr) return;
    std::string value(text);
    std::size_t begin = 0u;
    for (;;) {
        const auto end = value.find('\n', begin);
        const auto line = value.substr(begin, end == std::string::npos ? end : end - begin);
        appendFormattedLine(line.c_str(), color);
        if (end == std::string::npos) break;
        begin = end + 1u;
    }
}

void SphereUI::ListCtrl::clearRows() {
    rows.clear();
    selected_index = -1;
    write_index = 0u;
    updateLayout();
}

void SphereUI::ListCtrl::removeRow(std::size_t logical_index) {
    if (logical_index >= rows.size()) return;
    rows.erase(rows.begin() + physicalIndex(logical_index));
    if (maximum_items != 0u) write_index = write_index == 0u ? 0u : write_index - 1u;
    if (parent != nullptr && selected_index != -1) {
        selected_index = -1;
        notifyParent(*this, UiMessage::listSelectionChanged, invalidIndex);
    }
    updateLayout();
}

void SphereUI::ListCtrl::selectRow(int index) {
    if (index >= 0 && static_cast<std::size_t>(index) < rows.size()) selected_index = index;
}

void SphereUI::ListCtrl::alignRow(std::size_t index, std::uint32_t flags) {
    if (index >= rows.size()) return;
    auto& row = rows.at(index);
    if (flags == 0u) row.offset = 0;
    else {
        const auto extent = InterfaceRenderer::measureText(row.text.data(), font, font_initialized);
        const auto remainder = detail::subtractCoordinate(width, extent.width);
        if ((flags & 4u) != 0u) row.offset = static_cast<std::uint32_t>(remainder) / 2u;
        if ((flags & 1u) != 0u) row.offset = remainder;
    }
}

void SphereUI::ListCtrl::drawSelection(int screen_x, int screen_y, int row_y, bool restore_viewport) {
    const UiRect bounds{detail::subtractCoordinate(screen_x, selection_border), screen_y, detail::addCoordinate(detail::addCoordinate(screen_x, width), selection_border), detail::addCoordinate(screen_y, height)};
    ViewportScope viewport(bounds, restore_viewport);
    if (!viewport) return;
    const auto screen = Runtime::screenSize();
    const float left = std::max(bounds.left, 0), right = std::min(bounds.right, screen.width), top = row_y, bottom = detail::addCoordinate(row_y, line_height);
    const auto fill = modulatedColor(selection_color, alpha), line = modulatedColor(selection_line_color, alpha);
    InterfaceRenderer::drawTexture(nullptr, left, top, right, bottom, fill, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, left, top, right, top + 1.0f, line, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, left, bottom, right, bottom + 1.0f, line, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, left, top, left + 1.0f, bottom, line, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, right - 1.0f, top, right, bottom, line, 0.0f, 0.0f, false);
}

SphereUI::FilterListCtrl::FilterListCtrl() {
    filter_mask = 255u;
    control_kind = UiControlKind::filteredList;
}

void SphereUI::FilterListCtrl::clearHistory() {
    history.clear();
    history_write = 0u;
}

void SphereUI::FilterListCtrl::appendHistory(const char* text, std::uint32_t color, std::uint32_t mask) {
    appendCircular(history, maximum_items, history_write, HistoryEntry{text == nullptr ? " " : text, color, mask});
}

void SphereUI::FilterListCtrl::applyFilter(std::uint32_t mask) {
    if (mask == filter_mask) return;
    filter_mask = mask;
    if (history.size() == 0u) return;
    clearRows();
    for (std::size_t index = 0u; index < history.size(); ++index) {
        const auto& row = history.at(index);
        if ((row.filter & mask) != 0u) addText(row.text.data(), row.color);
    }
}

namespace {
    void menuLabel(const SphereUI::Window& window, const char* text, const SphereUI::UiRect& margins, const SphereUI::TextExtent& size, std::uint32_t format, std::uint32_t color, int left, int top, const SphereUI::UiRect& clip) {
        const auto extent = SphereUI::InterfaceRenderer::measureText(text, window.font, true);
        const auto room_x = size.width - margins.left - margins.right - extent.width, room_y = size.height - margins.top - margins.bottom - extent.height;
        const auto dx = (format & 4u) != 0u ? room_x / 2 : (format & 1u) != 0u ? room_x : 0;
        const auto dy = (format & 8u) != 0u ? room_y / 2 : (format & 2u) != 0u ? room_y : 0;
        renderLabel(window, text, left + margins.left + dx, top + margins.top + dy, SferaColor::fromArgb(color).withAlpha(window.alpha).argb(), clip);
    }
}

SphereUI::CMenuListControl::CMenuListControl() {
    maximum_items = hovered_index = 1u;
    control_kind = UiControlKind::menu;
}

bool SphereUI::CMenuListControl::loadUi(const char*, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    reader.sprite("topSprite", *this, top_sprite);
    reader.sprite("middleSprite", *this, middle_sprite);
    reader.sprite("bottomSprite", *this, bottom_sprite);
    if (top_sprite == nullptr || middle_sprite == nullptr || bottom_sprite == nullptr) return false;
    const auto dimensions = [](const std::shared_ptr<const UiSprite>& sprite) {
        return TextExtent{sprite->width, sprite->height};
    };
    top_size = dimensions(top_sprite);
    item_size = dimensions(middle_sprite);
    bottom_size = dimensions(bottom_sprite);
    hovered_sprite = middle_sprite;
    reader.sprite("middleHoveredSprite", *this, hovered_sprite);
    if (!reader.has("normalColor")) return false;
    reader.color("normalColor", normal_color);
    item_disabled_color = hovered_color = title_color = normal_color;
    reader.color("disabledColor", item_disabled_color);
    reader.color("hoveredColor", hovered_color);
    reader.color("titleColor", title_color);
    item_margin = {};
    title_margin = {};
    item_format = title_format = 0u;
    reader.rectangle("listItemTextMargin", item_margin.left, item_margin.top, item_margin.right, item_margin.bottom);
    reader.rectangle("titleTextMargin", title_margin.left, title_margin.top, title_margin.right, title_margin.bottom);
    reader.flags("listItemTextFormat", item_format, textAlignments);
    reader.flags("titleTextFormat", title_format, textAlignments);
    show_title = reader.has("needShowTitle");
    maximum_items = 1u;
    reader.count("maxItems", maximum_items);
    hovered_index = maximum_items;
    height = top_size.height + bottom_size.height;
    font = std::max(font, 2);
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::CMenuListControl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](auto& destination, const auto& source, SphereUI::Window::CloneContext& context) {

        copyProperties(destination, source,
            &CMenuListControl::items, &CMenuListControl::maximum_items, &CMenuListControl::top_sprite,
            &CMenuListControl::middle_sprite, &CMenuListControl::hovered_sprite, &CMenuListControl::bottom_sprite,
            &CMenuListControl::title_color, &CMenuListControl::normal_color, &CMenuListControl::hovered_color,
            &CMenuListControl::item_disabled_color, &CMenuListControl::show_title, &CMenuListControl::title_margin,
            &CMenuListControl::title_format, &CMenuListControl::item_margin, &CMenuListControl::item_format,
            &CMenuListControl::top_size, &CMenuListControl::item_size, &CMenuListControl::bottom_size,
            &CMenuListControl::parent_screen_x, &CMenuListControl::parent_screen_y, &CMenuListControl::parent_width,
            &CMenuListControl::parent_height, &CMenuListControl::hovered_index);
    });
}

void SphereUI::CMenuListControl::updateParentPosition() {
    parent_screen_x = parent_screen_y = parent_width = parent_height = 0;
    if (const auto* owner = parent) {
        owner->getAbsolutePosition(parent_screen_x, parent_screen_y);
        parent_width = owner->width;
        parent_height = owner->height;
    }
}

void SphereUI::CMenuListControl::keepOnScreen() {
    updateParentPosition();
    auto* owner = parent;
    if (owner == nullptr) return;
    const auto screen = Runtime::screenSize();
    const auto next_x = std::max(0, parent_screen_x + parent_width >= screen.width ? parent_screen_x - parent_width : parent_screen_x);
    const auto next_y = std::max(0, parent_screen_y + parent_height >= screen.height ? parent_screen_y - parent_height : parent_screen_y);
    if (next_x != parent_screen_x || next_y != parent_screen_y) {
        owner->handleMessage(UiMessage::setPosition, static_cast<std::uint32_t>(next_x), static_cast<std::uint32_t>(next_y));
        updateParentPosition();
    }
}

void SphereUI::CMenuListControl::addItem(const char* text, bool enabled) {
    if (items.size() >= maximum_items) return;
    items.push_back({text == nullptr ? "" : text, enabled});
    height += item_size.height;
    updateParentPosition();
    if (auto* owner = parent) owner->handleMessage(UiMessage::setSize, static_cast<std::uint32_t>(parent_width), static_cast<std::uint32_t>(parent_height + item_size.height));
}

void SphereUI::CMenuListControl::clearItems() {
    updateParentPosition();
    const auto removed_height = items.size() * static_cast<std::uint32_t>(item_size.height);
    height = top_size.height + bottom_size.height;
    items.clear();
    hovered_index = maximum_items;
    if (auto* owner = parent) owner->handleMessage(UiMessage::setSize, static_cast<std::uint32_t>(parent_width), static_cast<std::uint32_t>(parent_height) - removed_height);
}

void SphereUI::CMenuListControl::closeMenu() {
    notifyParent(*this, UiMessage::close);
}

std::size_t SphereUI::CMenuListControl::itemAtPoint(int point_x, int point_y) const {
    if (item_size.height <= 0) return maximum_items;
    const auto bounds = windowBounds(*this);
    const auto row_y = static_cast<std::int64_t>(point_y) - bounds.top - top_size.height;
    if (point_x < bounds.left || point_x >= bounds.right || row_y < 0) return maximum_items;
    const std::uint64_t index = row_y / item_size.height;
    return index < items.size() ? index : maximum_items;
}

std::uint32_t SphereUI::CMenuListControl::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::clearMenu:
            clearItems();
            break;
        case UiMessage::appendMenuItem:
            addItem(reinterpret_cast<const char*>(first), second != 0u);
            break;
        case UiMessage::activateMenuItem:
            if (first < items.size() && items.at(first).enabled != 0u) notifyParent(*this, UiMessage::menuItemActivated, first, items.size());
            break;
        case UiMessage::setMenuItemEnabled:
            if (first < items.size()) items.at(first).enabled = second != 0u;
            break;
        case UiMessage::setMenuItemText:
            if (first < items.size()) items.at(first).text.assign(second == 0u ? "" : reinterpret_cast<const char*>(second));
            break;
        default:
            return Window::handleMessage(message, first, second);
    }
    return 1u;
}

void SphereUI::CMenuListControl::drawHeader() {
    const auto bounds = windowBounds(*this);
    if (top_sprite != nullptr) top_sprite->drawNatural(static_cast<float>(bounds.left), static_cast<float>(bounds.top), SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    if (show_title) {
        const UiRect clip{bounds.left + title_margin.left, bounds.top + title_margin.top, bounds.right - title_margin.right, bounds.bottom - title_margin.bottom};
        menuLabel(*this, getText(), title_margin, top_size, title_format, title_color, bounds.left, bounds.top, clip);
    }
}

void SphereUI::CMenuListControl::drawItem(std::size_t index, const std::shared_ptr<const UiSprite>& sprite, std::uint32_t color) {
    if (index >= items.size()) return;
    const auto bounds = windowBounds(*this);
    const auto row_top = bounds.top + top_size.height + static_cast<int>(index) * item_size.height;
    if (sprite != nullptr) sprite->drawNatural(static_cast<float>(bounds.left), static_cast<float>(row_top), SferaColor::rgba(255u, 255u, 255u, alpha).argb());
    const auto& item = items.at(index);
    const UiRect clip{bounds.left + item_margin.left, row_top + title_margin.top, bounds.right - item_margin.right, row_top + item_size.height - title_margin.bottom};
    menuLabel(*this, item.text.data(), item_margin, item_size, item_format, item.enabled ? color : item_disabled_color, bounds.left, row_top, clip);
}

void SphereUI::CMenuListControl::drawFooter() {
    const auto bounds = windowBounds(*this);
    if (bottom_sprite != nullptr) bottom_sprite->drawNatural(static_cast<float>(bounds.left), static_cast<float>(bounds.top + top_size.height + static_cast<int>(items.size()) * item_size.height), SferaColor::rgba(255u, 255u, 255u, alpha).argb());
}

void SphereUI::CMenuListControl::draw() {
    if (hidden || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    keepOnScreen();
    ViewportScope viewport(windowBounds(*this));
    if (!viewport) return;
    drawHeader();
    for (std::size_t index = 0u; index < items.size(); ++index) drawItem(index, index == hovered_index ? hovered_sprite : middle_sprite, index == hovered_index ? hovered_color : normal_color);
    drawFooter();
}

void SphereUI::CMenuListControl::handleInput(const WindowInput& input) {
    if (hidden || items.size() == 0u) return;
    const auto position = CCursorManager::instance().position();
    hovered_index = itemAtPoint(position.x, position.y);
    if (hovered_index < items.size() && items.at(hovered_index).enabled != 0u && (input.mouse_flags & MouseInput::leftPress) != 0u) {
        notifyParent(*this, UiMessage::menuItemActivated, hovered_index, items.size());
        closeMenu();
    }
    if (const auto* owner = parent; owner != nullptr && !owner->containsPoint(position.x, position.y) && (input.mouse_flags & 3u) != 0u) closeMenu();
}


SphereUI::SlotCtrl::SlotCtrl() {
    fill_alpha = 128u;
    fill_color = UiColor::slotFill;
    border_color = UiColor::slotBorder;
    count_offset_x = -2;
    count_offset_y = 2;
    font = 2u;
    hidden = false;
    control_kind = UiControlKind::slot;
    can_drag_drop = true;
    text_alignment = TextAlignment::right;
    text_color = UiColor::white;
}

void SphereUI::SlotCtrl::setOverlay(std::shared_ptr<const UiSprite>& destination, const char* image) {
    if (image == nullptr) { destination.reset(); return; }
    auto replacement = std::make_shared<UiSprite>();
    replacement->setImage(image);
    destination = std::move(replacement);
}

void SphereUI::SlotCtrl::setItem(const char* image) {
    if (image == nullptr) {
        show_full_background = true;
        has_item = false;
        setText("");
        description.assign("");
        item_count = 0u;
        setOverlay(top_left_overlay, nullptr);
        setOverlay(bottom_right_overlay, nullptr);
        setOverlay(bottom_left_overlay, nullptr);
        return;
    }
    if (item_image.name != image) item_image.setImage(image);
    show_full_background = false;
    has_item = true;
}

void SphereUI::SlotCtrl::setItemCount(std::uint32_t count) {
    if (count == item_count) return;
    setText(count == 0u ? "" : std::to_string(static_cast<int>(count)).c_str());
    item_count = count;
}

bool SphereUI::SlotCtrl::loadUi(const char*, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    if (parent == nullptr) return false;
    const bool background = reader.has("slotpic") || reader.has("slotFull");
    if (background) {
        reader.sprite(reader.has("slotpic") ? "slotpic" : "slotFull", *this, full_sprite);
        show_full_background = true;
        if (full_sprite == nullptr) return false;
    }
    reader.sprite("slotempty", *this, empty_sprite);
    reader.sprite("slotborder", *this, border_sprite);
    reader.pair("slotpicofs", image_offset_x, image_offset_y);
    reader.pair("textofs", count_offset_x, count_offset_y);
    int number = 0;
    reader.integer("slotnumber", number);
    if (number != 0) setText(std::to_string(number).c_str());
    if (const char* image = reader.string("slotItem", true)) setItem(image);
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::SlotCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](auto& destination, const auto& source, SphereUI::Window::CloneContext& context) {

        copyProperties(destination, source,
            &SlotCtrl::item_image, &SlotCtrl::description, &SlotCtrl::top_left_overlay, &SlotCtrl::bottom_right_overlay,
            &SlotCtrl::bottom_left_overlay, &SlotCtrl::full_sprite, &SlotCtrl::empty_sprite, &SlotCtrl::border_sprite,
            &SlotCtrl::fill_alpha, &SlotCtrl::fill_color, &SlotCtrl::border_color, &SlotCtrl::image_offset_x,
            &SlotCtrl::image_offset_y, &SlotCtrl::show_full_background, &SlotCtrl::has_item, &SlotCtrl::press_x,
            &SlotCtrl::press_y, &SlotCtrl::left_pressed, &SlotCtrl::right_pressed, &SlotCtrl::drag_started,
            &SlotCtrl::count_offset_x, &SlotCtrl::count_offset_y, &SlotCtrl::item_count);
    });
}

std::uint32_t SphereUI::SlotCtrl::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::setSlotItem:
            setItem(reinterpret_cast<const char*>(first));
            break;
        case UiMessage::setSlotHighlight:
            if (first == 0u) {
                fill_alpha = 128u;
                fill_color = UiColor::slotFill;
                border_color = UiColor::slotBorder;
            } else if (first <= 2u) {
                fill_alpha = 140u;
                fill_color = border_color = first == 1u ? UiColor::slotRejected : UiColor::slotAccepted;
            }
            break;
        case UiMessage::setSlotDescription:
            description.assign(first == 0u ? "" : reinterpret_cast<const char*>(first));
            break;
        case UiMessage::setSlotCount:
            setItemCount(first);
            break;
        case UiMessage::setSlotFillColor:
            fill_color = first;
            break;
        case UiMessage::setSlotFillAlpha:
            fill_alpha = first;
            break;
        case UiMessage::setSlotBorderColor:
            border_color = first;
            break;
        case UiMessage::setSlotTopLeftOverlay:
            setOverlay(top_left_overlay, reinterpret_cast<const char*>(first));
            break;
        case UiMessage::setSlotBottomRightOverlay:
            setOverlay(bottom_right_overlay, reinterpret_cast<const char*>(first));
            break;
        case UiMessage::setSlotBottomLeftOverlay:
            setOverlay(bottom_left_overlay, reinterpret_cast<const char*>(first));
            break;
        default:
            return Window::handleMessage(message, first, second);
    }
    return 1u;
}

void SphereUI::SlotCtrl::draw() {
    if (hidden || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    const float left = bounds.left, top = bounds.top;
    const auto white = SferaColor::rgba(255u, 255u, 255u, alpha).argb();
    const auto background_color = SferaColor::fromArgb(fill_color).withAlpha(fill_alpha * alpha / 256u).argb();
    if (auto background = show_full_background && full_sprite != nullptr ? full_sprite : empty_sprite) background->drawNatural(left + image_offset_x, top + image_offset_y, background_color);
    if (has_item) {
        const auto image_width = std::min(std::max(0, width), item_image.width), image_height = std::min(std::max(0, height), item_image.height);
        const auto image_left = left + (width - image_width) / 2, image_top = top + (height - image_height) / 2;
        item_image.draw(image_left, image_top, image_left + image_width, image_top + image_height, white);
    }
    if (top_left_overlay != nullptr) top_left_overlay->drawNatural(left + 1.0f, top, white);
    if (auto sprite = bottom_right_overlay) sprite->drawNatural(left + width - sprite->width - 1.0f, top + height - sprite->height - 1.0f, white);
    if (auto sprite = bottom_left_overlay) {
        const auto dx = image_offset_x == -2 ? 1.0f : 3.0f, dy = image_offset_x == -2 ? 0.0f : image_offset_x == -1 ? 1.0f : 2.0f;
        sprite->drawNatural(left + dx, top + height - sprite->height - dy - 1.0f, white);
    }
    if (text.size() != 0u && (has_item || (behavior_flags & WindowStyle::showTitle) != 0u)) {
        const auto extent = InterfaceRenderer::measureText(getText(), font, font_initialized);
        auto dx = count_offset_x, dy = count_offset_y;
        if (extent.width < width) {
            if ((text_alignment & TextAlignment::right) != 0u) dx += width - extent.width;
            if ((text_alignment & TextAlignment::horizontalCenter) != 0u) dx = count_offset_x + (width - extent.width) / 2;
        }
        if (extent.height < height) {
            if ((text_alignment & TextAlignment::bottom) != 0u) dy += height - extent.height;
            if ((text_alignment & TextAlignment::verticalCenter) != 0u) dy = count_offset_y + (height - extent.height) / 2;
        }
        for (const auto offset : {TextExtent{1, 1}, TextExtent{-1, -1}, TextExtent{-1, 1}, TextExtent{1, -1}}) renderLabel(*this, getText(), bounds.left + dx + offset.width, bounds.top + dy + offset.height, SferaColor::rgba(0u, 0u, 0u, alpha).argb(), bounds);
        renderLabel(*this, getText(), bounds.left + dx, bounds.top + dy, SferaColor::fromArgb((disabled ? disabled_color : text_color)).withAlpha(alpha).argb(), bounds);
    }
    if (border_sprite != nullptr) border_sprite->drawNatural(left + image_offset_x, top + image_offset_y, SferaColor::fromArgb(border_color).withAlpha(alpha).argb());
}

void SphereUI::SlotCtrl::handleInput(const WindowInput& input) {
    if (hidden) return;
    const bool shift = Runtime::keyDown(42u) || Runtime::keyDown(54u);
    if (containsPoint(input.mouse_x, input.mouse_y)) {
        if ((input.mouse_flags & MouseInput::leftPress) != 0u && !left_pressed && !drag_started && !shift) {
            left_pressed = true;
            press_x = input.mouse_x;
            press_y = input.mouse_y;
        }
        if ((input.mouse_flags & MouseInput::rightPress) != 0u) right_pressed = true;
        if (!g_sfera_interface.drag_drop_active) {
            if ((input.mouse_flags & MouseInput::leftRelease) != 0u && !shift && left_pressed) notifyParent(*this, UiMessage::leftClick);
            if ((input.mouse_flags & MouseInput::rightRelease) != 0u && !shift && right_pressed) notifyParent(*this, UiMessage::rightClick);
            if (auto* window = CDescriptionWindow::instance()) window->requestDescription(description.data(), shift && (input.mouse_flags & MouseInput::leftPress) != 0u, this);
        }
    }
    if ((input.mouse_flags & MouseInput::rightRelease) != 0u) right_pressed = false;
    if ((input.mouse_buttons & 1u) == 0u) left_pressed = drag_started = false;
    if (left_pressed && !drag_started && (std::abs(static_cast<std::int64_t>(press_x) - input.mouse_x) > 2 || std::abs(static_cast<std::int64_t>(press_y) - input.mouse_y) > 2)) {
        notifyParent(*this, UiMessage::slotDrag);
        left_pressed = false;
        drag_started = true;
    }
}


SphereUI::RichEditCtrl::RichEditCtrl() {
    cursor_visible = true;
    control_kind = UiControlKind::richEdit;
    hidden = input_enabled = false;
    lines.push_back("");
}

void SphereUI::RichEditCtrl::updateMetrics(int font_id) {
    const auto extent = InterfaceRenderer::measureText("_", font_id, true);
    cursor_width = std::max(0, extent.width);
    line_height = std::max(1, extent.height);
    page_rows = std::max(0, height / line_height - 1);
}

void SphereUI::RichEditCtrl::updateScroll() {
    if (auto* scroll = scrollbar.get()) scroll->setParameters({sizeof(ScrollParameters), ScrollField::all, 0, std::max(0, static_cast<int>(lines.size()) - page_rows - 1), page_rows, first_row, 1});
}

void SphereUI::RichEditCtrl::ensureCaretVisible() {
    if (lines.size() == 0u) lines.push_back("");
    caret_row = std::clamp(caret_row, 0, static_cast<int>(lines.size()) - 1);
    caret_column = std::clamp(caret_column, 0, static_cast<int>(lines.at(caret_row).size()));
    first_row = std::max(0, std::clamp(first_row, caret_row - std::max(0, page_rows), caret_row));
    updateScroll();
}

void SphereUI::RichEditCtrl::moveCaret(std::uint32_t key) {
    ensureCaretVisible();
    const int length = lines.at(caret_row).size();
    switch (key) {
        case VK_LEFT:
            if (caret_column > 0) --caret_column;
            else if (caret_row > 0) caret_column = lines.at(--caret_row).size();
            break;
        case VK_RIGHT:
            if (caret_column < length) ++caret_column;
            else if (caret_row + 1 < static_cast<int>(lines.size())) {
                ++caret_row;
                caret_column = 0;
            }
            break;
        case VK_UP:
            --caret_row;
            break;
        case VK_DOWN:
            ++caret_row;
            break;
        case VK_HOME:
            caret_column = 0;
            break;
        case VK_END:
            caret_column = length;
            break;
        case VK_PRIOR:
            caret_row -= std::max(1, page_rows);
            break;
        case VK_NEXT:
            caret_row += std::max(1, page_rows);
            break;
        default:
            return;
    }
    ensureCaretVisible();
}

void SphereUI::RichEditCtrl::setContent(const char* text) {
    const std::string source = text == nullptr ? "" : text;
    std::vector<std::string> replacement{};
    std::string line;
    int used_width = 0;
    for (unsigned char character : source) {
        const char glyph[] = {static_cast<char>(character), 0};
        const auto extent = InterfaceRenderer::measureText(glyph, font, font_initialized);
        if (character == '\n' || used_width + extent.width + cursor_width > width) {
            replacement.push_back(line.c_str());
            line.clear();
            used_width = 0;
        } else {
            line.push_back(static_cast<char>(character));
            used_width += extent.width;
        }
    }
    if (!line.empty() || replacement.size() == 0u) replacement.push_back(line.c_str());
    lines = std::move(replacement);
    caret_row = static_cast<int>(lines.size()) - 1;
    caret_column = lines.at(caret_row).size();
    ensureCaretVisible();
}

void SphereUI::RichEditCtrl::copyContent(char* destination, std::uint32_t capacity) const {
    if (destination == nullptr || capacity == 0u) return;
    std::size_t copied = 0u;
    for (std::size_t index = 0u; index < lines.size() && copied + 1u < capacity; ++index) {
        const auto& line = lines.at(index);
        const auto count = std::min<std::size_t>(line.size(), capacity - copied - 1u);
        std::memcpy(destination + copied, line.data(), count);
        copied += count;
        if (count < line.size()) break;
        if (copied + 1u < capacity) destination[copied++] = '\n';
    }
    destination[copied] = 0;
}

void SphereUI::RichEditCtrl::insertAt(std::uint32_t column, std::uint8_t character, std::uint32_t row) {
    for (;;) {
        if (row >= lines.size()) {
            const char glyph[] = {static_cast<char>(character), 0};
            lines.push_back(glyph);
            return;
        }
        std::string text = lines.at(row).data();
        text.insert(std::min<std::size_t>(column, text.size()), 1u, static_cast<char>(character));
        if (text.size() < 2u || InterfaceRenderer::measureText(text.c_str(), font, font_initialized).width + cursor_width <= width) {
            lines.at(row).assign(text.c_str());
            return;
        }
        character = text.back();
        text.pop_back();
        lines.at(row).assign(text.c_str());
        ++row;
        column = 0u;
    }
}

void SphereUI::RichEditCtrl::insertCharacter(std::uint8_t character) {
    ensureCaretVisible();
    const auto& row = lines.at(caret_row);
    const char glyph[] = {static_cast<char>(character), 0};
    const auto prospective = InterfaceRenderer::measureText(row.data(), font, font_initialized).width + InterfaceRenderer::measureText(glyph, font, font_initialized).width + cursor_width;
    if (caret_column == static_cast<int>(row.size()) && prospective >= width) {
        insertAt(0u, character, ++caret_row);
        caret_column = 1;
    } else {
        insertAt(static_cast<std::uint32_t>(caret_column), character, static_cast<std::uint32_t>(caret_row));
        ++caret_column;
    }
    ensureCaretVisible();
}

std::uint32_t SphereUI::RichEditCtrl::mergeRows(std::uint32_t destination, std::uint32_t source) {
    if (destination >= lines.size() || source >= lines.size() || destination == source) return 0u;
    std::string text = lines.at(destination).data();
    const std::string following = lines.at(source).data();
    std::uint32_t count = 0u;
    for (char character : following) {
        text.push_back(character);
        if (InterfaceRenderer::measureText(text.c_str(), font, font_initialized).width + cursor_width > width) {
            text.pop_back();
            break;
        }
        ++count;
    }
    lines.at(destination).assign(text.c_str());
    return count;
}

void SphereUI::RichEditCtrl::eraseCharacter(bool backward) {
    ensureCaretVisible();
    std::uint32_t row = caret_row;
    std::string text = lines.at(row).data();
    if (backward && caret_column > 0) {
        text.erase(--caret_column, 1u);
        lines.at(row).assign(text.c_str());
    } else if (!backward && caret_column < static_cast<int>(text.size())) {
        text.erase(caret_column, 1u);
        lines.at(row).assign(text.c_str());
    } else {
        if (backward) {
            if (row == 0u) return;
            --row;
            --caret_row;
            caret_column = lines.at(row).size();
        }
        if (row + 1u >= lines.size()) return;
        const auto transferred = mergeRows(row, row + 1u);
        std::string remainder = lines.at(row + 1u).data();
        remainder.erase(0u, transferred);
        if (remainder.empty()) lines.erase(lines.begin() + row + 1u);
        else lines.at(row + 1u).assign(remainder.c_str());
    }
    ensureCaretVisible();
}

void SphereUI::RichEditCtrl::splitLine() {
    ensureCaretVisible();
    std::string text = lines.at(caret_row).data();
    const auto following = text.substr(caret_column);
    text.resize(caret_column);
    lines.insert(lines.begin() + caret_row + 1, following);
    lines.at(caret_row).assign(text.c_str());
    ++caret_row;
    caret_column = 0;
    ensureCaretVisible();
}

void SphereUI::RichEditCtrl::drawCaret(float left, float top) {
    const auto now = Runtime::clockTicks();
    if (blink_started == 0u || now < blink_started) blink_started = now;
    const auto elapsed = now - blink_started;
    if (elapsed > 4000u) cursor_visible = static_cast<std::uint8_t>(((elapsed - 4000u) / 4000u) & 1u);
    if (!input_enabled || !cursor_visible || caret_row < 0 || caret_row >= static_cast<int>(lines.size())) return;
    const std::string prefix(lines.at(caret_row).data(), std::clamp(caret_column, 0, static_cast<int>(lines.at(caret_row).size())));
    const auto extent = InterfaceRenderer::measureText(prefix.c_str(), font, font_initialized);
    InterfaceRenderer::drawText("_", static_cast<int>(left) + extent.width, static_cast<int>(top), text_color, font, font_initialized, windowBounds(*this), false);
}

bool SphereUI::RichEditCtrl::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    loadPart(*this, scrollbar, reader, "scrollbar", filename, parser, UiControlKind::scrollBar, 1u);
    updateMetrics(font);
    updateScroll();
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::RichEditCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](RichEditCtrl& copy, const RichEditCtrl& source, SphereUI::Window::CloneContext& context) {

        copyProperties(copy, source,
            &RichEditCtrl::lines, &RichEditCtrl::caret_row, &RichEditCtrl::caret_column, &RichEditCtrl::blink_started,
            &RichEditCtrl::cursor_visible, &RichEditCtrl::cursor_width, &RichEditCtrl::line_height, &RichEditCtrl::page_rows,
            &RichEditCtrl::first_row);
        cloneOwned(copy.scrollbar, source.scrollbar, copy, context);
        copy.updateMetrics(source.font);
        copy.updateScroll();
    });
}

std::uint32_t SphereUI::RichEditCtrl::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::setRichEditContent:
            if (first != 0u) setContent(reinterpret_cast<const char*>(first));
            return 1u;
        case UiMessage::getRichEditContent:
            if (first != 0u) copyContent(reinterpret_cast<char*>(first), second);
            return 1u;
        case UiMessage::verticalScroll:
            first_row = std::max(0, static_cast<int>(first));
            return 1u;
        case UiMessage::setInputEnabled:
            setInputFocus(first != 0u);
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

void SphereUI::RichEditCtrl::draw() {
    if (hidden || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    {
        ViewportScope viewport(bounds);
        if (viewport) {
            const auto start = std::clamp(first_row, 0, static_cast<int>(lines.size()));
            const auto finish = std::min(static_cast<int>(lines.size()), start + std::max(0, page_rows) + 1);
            for (auto row = start; row < finish; ++row) InterfaceRenderer::drawText(lines.at(row).data(), bounds.left, bounds.top + (row - start) * line_height, text_color, font, font_initialized, bounds, false);
            if (caret_row >= start && caret_row < finish) drawCaret(static_cast<float>(bounds.left), static_cast<float>(bounds.top + (caret_row - start) * line_height));
        }
    }
    drawChild(scrollbar.get(), alpha);
}

void SphereUI::RichEditCtrl::handleInput(const WindowInput& input) {
    if (input_enabled) Runtime::setTextInputActive(true);
    if (hidden) return;
    if (input_enabled) {
        if (input.character >= 32u) insertCharacter(input.character);
        const auto key = input.key_code;
        if (key == VK_BACK || key == VK_DELETE) eraseCharacter(key == VK_BACK);
        else if (key == VK_RETURN) splitLine();
        else if (key >= VK_PRIOR && key <= VK_DOWN) moveCaret(key);
        if (key == VK_BACK || key == VK_DELETE || key == VK_RETURN || (key >= VK_PRIOR && key <= VK_DOWN)) input.key_code = 0u;
    }
    inputChild(scrollbar.get(), input);
    if ((input.mouse_flags & MouseInput::leftPress) != 0u) setInputFocus(hitTest(input.mouse_x, input.mouse_y));
}

SphereUI::RichEditCtrl::~RichEditCtrl() {
    Runtime::setTextInputActive(false);
}

namespace {

    void copyDocument(std::unique_ptr<SphereUI::HyperTextDocument>& destination, const std::unique_ptr<SphereUI::HyperTextDocument>& source, const SphereUI::Window& owner, std::uint32_t format) {
        destination = source ? source->clone(owner.width - (owner.font < 2 ? 2 : 0), format, owner.font) : nullptr;
    }
}

SphereUI::HyperTextCtrl::HyperTextCtrl() {
    transition_fraction = 1.0f;
    link_color = UiColor::hyperLink;
    hover_color = UiColor::hyperLinkHover;
    tooltip_index = -1;
    hidden = false;
    control_kind = UiControlKind::hyperText;
}

void SphereUI::HyperTextCtrl::copyHyperTextState(const HyperTextCtrl& source, CloneContext& context) {
    if (this == &source) return;
    history = source.history;
    copyDocument(document, source.document, source, source.text_format);
    copyDocument(previous_document, source.previous_document, source, source.text_format);
    scrollbar.reset();
    cloneOwned(scrollbar, source.scrollbar, *this, context);
    copyProperties(*this, source,
        &HyperTextCtrl::text_format, &HyperTextCtrl::pending_page, &HyperTextCtrl::maximum_scroll, &HyperTextCtrl::scroll_position,
        &HyperTextCtrl::first_line_offset, &HyperTextCtrl::clip_offset, &HyperTextCtrl::clip_height,
        &HyperTextCtrl::previous_line_offset, &HyperTextCtrl::previous_clip_offset, &HyperTextCtrl::previous_clip_height,
        &HyperTextCtrl::transition_fraction, &HyperTextCtrl::transition_active, &HyperTextCtrl::transition_started,
        &HyperTextCtrl::link_color, &HyperTextCtrl::hover_color);
    tooltip_index = -1;
    discard_old_text = source.discard_old_text;
}

std::uint32_t SphereUI::HyperTextCtrl::parseTextFormat(const char* name) {
    if (SferaSimpleParser::equalsIgnoreCase(name, "RIGHT")) return 1u;
    if (SferaSimpleParser::equalsIgnoreCase(name, "CENTER")) return 2u;
    if (SferaSimpleParser::equalsIgnoreCase(name, "PARAGRAPH")) return 3u;
    return 0u;
}

void SphereUI::HyperTextCtrl::queuePage(const char* name, bool remember) {
    if (transition_active) return;
    if (name == nullptr || *name == '\0') { pending_page = std::monostate{}; return; }
    PageRequest request{std::string(name, std::min(std::char_traits<char>::length(name), std::size_t{255})), remember};
    pending_page = std::move(request);
}

void SphereUI::HyperTextCtrl::queueBuffer(const char* buffer, std::size_t size) {
    if (transition_active || buffer == nullptr || size == 0u) return;
    std::string bytes(buffer, size);
    pending_page = std::move(bytes);
}

void SphereUI::HyperTextCtrl::updateScroll() {
    auto* page = document.get();
    if (page == nullptr) return;
    scroll_position = std::clamp(scroll_position, 0, std::max(0, maximum_scroll));
    first_line_offset = 0;
    clip_offset = -scroll_position;
    clip_height = height;
    page->resetRegions();
}

void SphereUI::HyperTextCtrl::updateDocument(bool resize_to_content) {
    if (std::holds_alternative<std::monostate>(pending_page)) return;
    const auto page_width = width - (font < 2u ? 2 : 0);
    std::unique_ptr<HyperTextDocument> replacement;
    bool remember = false;
    if (const auto* bytes = std::get_if<std::string>(&pending_page)) {
        replacement = std::make_unique<HyperTextDocument>(*bytes, page_width, text_format, font);
    } else if (const auto* request = std::get_if<PageRequest>(&pending_page)) {
        remember = request->remember;
        if (auto* source = g_sfera_interface.findHyperText(request->name.c_str())) replacement = source->clone(page_width, text_format, font);
    }
    if (replacement != nullptr) {
        auto* current = document.get();
        if (current != nullptr && !discard_old_text && remember && !current->name.empty()) history.push_back(current->name);
        if (current != nullptr) {
            if (discard_old_text) document.reset();
            else {
                previous_document = std::move(document);
                previous_line_offset = first_line_offset;
                previous_clip_offset = clip_offset;
                previous_clip_height = clip_height;
                transition_fraction = 0.0f;
                transition_active = true;
                transition_started = Runtime::clockTicks();
            }
            notifyParent(*this, UiMessage::hyperTextPageChanged);
            if (auto* tip = tooltip.get()) tip->reset();
        }
        document = std::move(replacement);
        document->link_color = link_color;
        document->hover_color = hover_color;
        tooltip_index = -1;
        const auto extent = document->totalHeight();
        if (resize_to_content && extent > 0) height = extent;
        maximum_scroll = std::max(0, extent - height);
        scroll_position = 0;
        updateScroll();
        if (auto* scroll = scrollbar.get()) scroll->setParameters({sizeof(ScrollParameters), ScrollField::all, 0, maximum_scroll, height, 0, document->line_height});
    }
    pending_page = std::monostate{};
}

void SphereUI::HyperTextCtrl::openLink(const char* target) {
    if (target == nullptr) return;
    const std::string value(target);
    const auto separator = value.find(':');
    const auto scheme = value.substr(0u, separator);
    if (SferaSimpleParser::equalsIgnoreCase(scheme.c_str(), "HTS")) {
        if (separator == std::string::npos) return;
        const auto first = value.find_first_not_of('\\', separator + 1u);
        if (first != std::string::npos) queuePage(value.c_str() + first, true);
    } else Runtime::openExternalLink(value.c_str(), SferaSimpleParser::equalsIgnoreCase(scheme.c_str(), "mailto"));
}

bool SphereUI::HyperTextCtrl::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    if (const char* value = reader.string("textFormat")) text_format = parseTextFormat(value);
    if (const char* value = reader.string("hyperText", true)) queuePage(value, false);
    loadPart(*this, scrollbar, reader, "scrollbar", filename, parser, UiControlKind::scrollBar, 1u);
    if (reader.has("linkcolor")) {
        const char* first = reader.token(0u);
        if (first != nullptr) readHexColor(first, link_color);
        const char* second = reader.token(1u);
        if (second != nullptr) readHexColor(second, hover_color);
    }
    if (const char* value = reader.string("flags")) if (SferaSimpleParser::equalsIgnoreCase(value, "DISCARD_OLD_TEXT")) discard_old_text = true;
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::HyperTextCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](HyperTextCtrl& copy, const HyperTextCtrl& source, SphereUI::Window::CloneContext& context) {
        copy.copyHyperTextState(source, context);
        if (copy.tooltip == nullptr) copy.tooltip = std::make_unique<ToolTipCtrl>();
    });
}

std::uint32_t SphereUI::HyperTextCtrl::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::verticalScroll:
            if (document != nullptr) {
                scroll_position = first;
                updateScroll();
            }
            return 1u;
        case UiMessage::previousHyperTextPage:
        case UiMessage::firstHyperTextPage:
            if (history.size() != 0u) {
                if (message == UiMessage::firstHyperTextPage) while (history.size() > 1u) history.pop_back();
                const std::string name = history.at(history.size() - 1u).data();
                history.pop_back();
                queuePage(name.c_str(), false);
            }
            return 1u;
        case UiMessage::loadHyperTextPage:
            queuePage(reinterpret_cast<const char*>(first), second != 0u);
            return 1u;
        case UiMessage::clearHyperTextHistory:
            history.clear();
            return 1u;
        case UiMessage::loadHyperTextBuffer:
            queueBuffer(reinterpret_cast<const char*>(first), second);
            return 1u;
        case UiMessage::resizeToHyperText:
            updateDocument(true);
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

void SphereUI::HyperTextCtrl::draw() {
    if (hidden) return;
    if (auto* tip = tooltip.get()) if (!tip->hidden && tip->alpha != alpha) tip->setOpacity(static_cast<float>(alpha) / 255.0f);
    const auto bounds = windowBounds(*this);
    {
        ViewportScope viewport(bounds);
        if (viewport) {
            const auto fraction = std::clamp(transition_fraction, 0.0f, 1.0f);
            if (auto* page = previous_document.get()) page->draw(bounds.left, bounds.top - previous_line_offset, previous_clip_offset, previous_clip_height, static_cast<std::uint32_t>((1.0f - fraction) * alpha));
            if (auto* page = document.get()) page->draw(bounds.left, bounds.top - first_line_offset, clip_offset, clip_height, static_cast<std::uint32_t>(fraction * alpha));
        }
    }
    drawChild(scrollbar.get(), alpha);
}

void SphereUI::HyperTextCtrl::handleInput(const WindowInput& input) {
    updateDocument(false);
    inputChild(scrollbar.get(), input);
    if (transition_active) {
        const auto now = Runtime::clockTicks();
        const auto elapsed = now >= transition_started ? now - transition_started : 0u;
        transition_fraction = std::clamp(static_cast<float>(static_cast<double>(elapsed) / 5000.0), 0.0f, 1.0f);
        if (elapsed > 5000u) {
            transition_active = false;
            previous_document.reset();
        }
    }
    auto* page = document.get();
    if (page == nullptr) return;
    int hovered = -1;
    for (std::size_t index = 0u; index < page->tooltips.size(); ++index) {
        auto& region = page->tooltips.at(index);
        region.hovered = region.contains(input.mouse_x, input.mouse_y) ? 1u : 0u;
        if (region.hovered && hovered < 0) hovered = index;
    }
    if (hovered != tooltip_index) {
        if (auto* tip = tooltip.get()) {
            tip->reset();
            if (hovered >= 0) {
                tip->setLine(0u, page->tooltips.at(hovered).target.c_str());
                tip->showAt(input.mouse_x, input.mouse_y);
            }
        }
        tooltip_index = hovered;
    }
    for (std::size_t index = 0u; index < page->links.size(); ++index) {
        auto& link = page->links.at(index);
        link.hovered = link.contains(input.mouse_x, input.mouse_y) ? 1u : 0u;
        if (link.hovered && (input.mouse_flags & MouseInput::leftPress) != 0u) {
            openLink(link.target.c_str());
            Runtime::playLinkSound();
        }
    }
}


SphereUI::HyperTextChatListControl::HyperTextChatListControl() {
    control_kind = UiControlKind::hyperTextChat;
    item_link_color = link_color = UiColor::white;
    maximum_items = 256u;
    row_height = 15u;
}

std::unique_ptr<SphereUI::Window> SphereUI::HyperTextChatListControl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](auto& copy, const auto& source, SphereUI::Window::CloneContext& context) {

        copyProperties(copy, source,
            &HyperTextChatListControl::messages, &HyperTextChatListControl::visible_messages, &HyperTextChatListControl::channels,
            &HyperTextChatListControl::selected_link_text, &HyperTextChatListControl::selected_link_value,
            &HyperTextChatListControl::selected_plain_text, &HyperTextChatListControl::selected_hyper_text,
            &HyperTextChatListControl::item_link_color, &HyperTextChatListControl::link_color,
            &HyperTextChatListControl::maximum_items, &HyperTextChatListControl::row_height, &HyperTextChatListControl::page_rows,
            &HyperTextChatListControl::parent_x, &HyperTextChatListControl::parent_y, &HyperTextChatListControl::bottom_message,
            &HyperTextChatListControl::bottom_row, &HyperTextChatListControl::scroll_offset,
            &HyperTextChatListControl::rendered_rows);
        cloneOwned(copy.scrollbar, source.scrollbar, copy, context);
    });
}


bool SphereUI::HyperTextChatListControl::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    if (!reader.has("linkColor")) return false;
    reader.color("linkColor", link_color);
    item_link_color = link_color;
    std::uint32_t unused_player_color = link_color;
    reader.color("playerLinkColor", unused_player_color);
    reader.color("itemLinkColor", item_link_color);
    maximum_items = 256u;
    row_height = 15u;
    reader.count("maxItems", maximum_items);
    reader.integer("rowHeight", row_height);
    maximum_items = std::clamp<std::size_t>(maximum_items, 1u, maximumScrollOffset);
    row_height = std::clamp(row_height, 1u, maximumScrollOffset);
    font = std::max(font, 2);
    SferaParserRange block{};
    if (reader.block("scrollbar", block) && !loadPart(*this, scrollbar, reader, "scrollbar", filename, parser, UiControlKind::scrollBar, 1u)) return false;
    page_rows = static_cast<std::uint32_t>(std::max(height, 0)) / row_height;
    rebuildVisible();
    updateScroll(false);
    return true;
}

void SphereUI::HyperTextChatListControl::rebuildVisible() {
    visible_messages.clear();
    rendered_rows.clear();
    for (std::size_t reverse = messages.size(); reverse != 0u; --reverse) {
        const auto& item = messages.at(reverse - 1u);
        for (std::size_t channel = 0u; channel < channels.size(); ++channel) if (channels.at(channel) == item.channel) {
            visible_messages.push_back(reverse - 1u);
            break;
        }
    }
    if (visible_messages.size() == 0u) bottom_message = bottom_row = scroll_offset = 0u;
}

const char* SphereUI::HyperTextChatListControl::messageText(std::size_t index, bool plain) const {
    if (index >= visible_messages.size()) return "";
    const auto& item = messages.at(visible_messages.at(index));
    return plain ? item.plain_text.data() : item.hyper_text.data();
}

void SphereUI::HyperTextChatListControl::addMessage(const char* text, std::uint32_t channel, std::uint32_t color) {
    HyperTextChatListItem item{};
    item.initialize(text, channel, color);
    item.layout(width, font);
    if (item.rows.empty()) return;
    messages.push_back(std::move(item));
    while (messages.size() > std::max(maximum_items, std::size_t{1})) messages.pop_front();
    bool visible = false;
    for (std::size_t index = 0u; index < channels.size(); ++index) visible |= channels.at(index) == channel;
    if (visible) scroll_offset = 0u;
    rebuildVisible();
    updateScroll(false);
}

void SphereUI::HyperTextChatListControl::addChannel(std::uint32_t channel) {
    for (std::size_t index = 0u; index < channels.size(); ++index) if (channels.at(index) == channel) return;
    channels.push_back(channel);
    scroll_offset = 0u;
    rebuildVisible();
    updateScroll(false);
}

void SphereUI::HyperTextChatListControl::setChannels(const std::uint32_t* values, std::size_t count) {
    if (values == nullptr && count != 0u) return;
    std::vector<std::uint32_t> replacement;
    if (count != 0u) replacement.assign(values, values + count);
    channels = std::move(replacement);
    scroll_offset = 0u;
    rebuildVisible();
    updateScroll(false);
}

void SphereUI::HyperTextChatListControl::clearChannels() {
    channels.clear();
    rebuildVisible();
    updateScroll(true);
}

void SphereUI::HyperTextChatListControl::setFont(int font_id) {
    if (font == font_id) return;
    Window::setFont(font_id);
    for (auto& item : messages) {
        HyperTextChatListItem replacement;
        replacement.initialize(item.hyper_text.c_str(), item.channel, item.color);
        replacement.layout(width, font);
        item = std::move(replacement);
    }
    scroll_offset = 0u;
    rebuildVisible();
    updateScroll(false);
}

void SphereUI::HyperTextChatListControl::updateParentPosition() {
    parent_x = parent_y = 0;
    if (auto* owner = parent) owner->getAbsolutePosition(parent_x, parent_y);
}

bool SphereUI::HyperTextChatListControl::visibleRowRange(std::size_t message, std::size_t drawn, std::size_t rows, std::size_t* first, std::size_t* last) const {
    if (message < bottom_message || rows == 0u || drawn >= page_rows) return false;
    const auto end = message == bottom_message ? std::min(bottom_row, rows - 1u) : rows - 1u;
    const auto available = page_rows - drawn;
    const auto start = end + 1u > available ? end + 1u - available : 0u;
    if (first != nullptr) *first = start;
    if (last != nullptr) *last = end;
    return true;
}

void SphereUI::HyperTextChatListControl::updateScroll(bool reset) {
    page_rows = static_cast<std::uint32_t>(std::max(height, 0)) / std::max(row_height, 1u);
    std::uint64_t total = 0u;
    for (std::size_t index = 0u; index < visible_messages.size(); ++index) total += messages.at(visible_messages.at(index)).rows.size();
    const auto maximum = std::min<std::size_t>(total > page_rows ? total - page_rows : 0u, maximumScrollOffset);
    scroll_offset = reset ? 0u : std::min(scroll_offset, maximum);
    bottom_message = bottom_row = 0u;
    auto skip = scroll_offset;
    for (std::size_t index = 0u; index < visible_messages.size(); ++index) {
        const auto count = messages.at(visible_messages.at(index)).rows.size();
        if (skip < count) {
            bottom_message = index;
            bottom_row = count - skip - 1u;
            break;
        }
        skip -= count;
    }
    if (auto* child = scrollbar.get()) child->setParameters({sizeof(ScrollParameters), ScrollField::all, 0, static_cast<int>(reset ? 0u : maximum), 1, static_cast<int>(reset ? 0u : maximum - scroll_offset), 1});
}

void SphereUI::HyperTextChatListControl::readScroll() {
    if (auto* child = scrollbar.get()) {
        ScrollParameters parameters{};
        child->getParameters(parameters);
        scroll_offset = std::max(parameters.maximum - parameters.current, 0);
        updateScroll(false);
    }
}

void SphereUI::HyperTextChatListControl::drawElement(HyperTextRun& element, int left, int top, std::uint32_t color) {
    auto* geometry = element.geometry();
    if (geometry == nullptr || (!element.isPlain() && element.link() == nullptr)) return;
    geometry->x = left - detail::addCoordinate(parent_x, x);
    geometry->y = top - detail::addCoordinate(parent_y, y);
    if (element.link() != nullptr) {
        const auto kind = element.link()->link_kind;
        if (kind == 1u) color = item_link_color;
        else if (kind == 2u) color = SferaColor::fromArgb(color).scaledRgb(3u, 4u).argb();
        else color = link_color;
    }
    const UiRect clip{left, top, detail::addCoordinate(left, std::max(geometry->width, 1) - 1), detail::addCoordinate(top, std::max(geometry->height, 1) - 1)};
    InterfaceRenderer::drawText(element.text.data(), left, top, SferaColor::fromArgb(color).withAlpha(alpha).argb(), font, true, clip, false);
}

void SphereUI::HyperTextChatListControl::draw() {
    if (hidden || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    updateParentPosition();
    updateScroll(false);
    rendered_rows.clear();
    const auto bounds = windowBounds(*this);
    {
        ViewportScope viewport(bounds);
        for (std::size_t item_index = bottom_message; item_index < visible_messages.size() && rendered_rows.size() < page_rows; ++item_index) {
            auto& item = messages.at(visible_messages.at(item_index));
            std::size_t first = 0u, last = 0u;
            if (!visibleRowRange(item_index, rendered_rows.size(), item.rows.size(), &first, &last)) continue;
            for (std::size_t reverse = last + 1u; reverse > first; --reverse) {
                const auto row = reverse - 1u;
                const auto top = detail::subtractCoordinate(detail::subtractCoordinate(bounds.bottom, 1), static_cast<int>((rendered_rows.size() + 1u) * row_height));
                rendered_rows.push_back({item_index, row});
                auto left = bounds.left;
                const auto range = item.rows.at(row);
                for (std::size_t index = range.first; index <= range.last && index < item.elements.size(); ++index) if (auto* element = &item.elements.at(index)) if (auto* geometry = element->geometry()) {
                    drawElement(*element, left, top, item.color);
                    left = detail::addCoordinate(left, geometry->width);
                }
            }
        }
    }
    drawChild(scrollbar.get(), alpha);
}

void SphereUI::HyperTextChatListControl::handleInput(const WindowInput& input) {
    if (hidden || visible_messages.size() == 0u) return;
    inputChild(scrollbar.get(), input);
    updateParentPosition();
    const auto bounds = windowBounds(*this);
    if (!contains(bounds, input.mouse_x, input.mouse_y) || (input.mouse_flags & MouseInput::anyRelease) == 0u) return;
    const auto row = static_cast<std::uint32_t>(std::max(bounds.bottom - 1 - input.mouse_y, 0)) / std::max(row_height, 1u);
    if (row >= rendered_rows.size()) return;
    const auto rendered = rendered_rows.at(row);
    if (rendered.message_index >= visible_messages.size()) return;
    auto& item = messages.at(visible_messages.at(rendered.message_index));
    if (rendered.row_index >= item.rows.size()) return;
    const auto range = item.rows.at(rendered.row_index);
    for (std::size_t index = range.first; index <= range.last && index < item.elements.size(); ++index) {
        auto* element = &item.elements.at(index);
        if (element == nullptr || element->link() == nullptr) continue;
        auto& link = *element->link();
        const auto& rectangle = link.bounds;
        const auto local_x = input.mouse_x - bounds.left;
        const auto local_y = input.mouse_y - bounds.top;
        if (local_x < rectangle.x || local_y < rectangle.y || local_x >= rectangle.x + rectangle.width || local_y >= rectangle.y + rectangle.height) continue;
        if ((input.mouse_flags & MouseInput::leftRelease) != 0u && (input.key_modifiers & 1u) != 0u) {
            if (auto* description = Runtime::descriptionWindow()) description->showDescription(link.linkValue(), 0u, 250u, false);
        } else if (link.link_kind == 1u && (input.mouse_flags & MouseInput::leftRelease) != 0u) {
            if (auto* description = Runtime::descriptionWindow()) description->showDescription(link.linkValue(), 0u, 5000u, true);
        } else if (link.link_kind == 2u) {
            selected_link_text = element->text;
            selected_link_value.assign(link.linkValue());
            if ((input.mouse_flags & MouseInput::leftRelease) != 0u) notifyParent(*this, UiMessage::chatPlayerLeftClick, 0u, 0u);
            else {
                selected_hyper_text.assign(item.hyper_text.data());
                selected_plain_text.assign(item.plain_text.data());
                notifyParent(*this, UiMessage::chatPlayerRightClick, 0u, 0u);
            }
        }
    }
}

std::uint32_t SphereUI::HyperTextChatListControl::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::verticalScroll:
            readScroll();
            return 1u;
        case UiMessage::appendChatMessage:
            if (first != 0u && second != 0u) {
                const auto* parameters = reinterpret_cast<const std::uint32_t*>(second);
                addMessage(reinterpret_cast<const char*>(first), parameters[0], parameters[1]);
            }
            return 1u;
        case UiMessage::addChatChannel:
            addChannel(first);
            return 1u;
        case UiMessage::setChatChannels:
            setChannels(reinterpret_cast<const std::uint32_t*>(second), first);
            return 1u;
        case UiMessage::clearChatChannels:
            clearChannels();
            return 1u;
        case UiMessage::getChatPlainText:
        case UiMessage::getChatHyperText:
            if (second != 0u) copyMessageText(reinterpret_cast<char*>(second), messageText(first, message == UiMessage::getChatPlainText));
            return 1u;
        case UiMessage::getSelectedChatLink:
            if (first != 0u) copyMessageText(reinterpret_cast<char*>(first), selected_link_text.data());
            if (second != 0u) copyMessageText(reinterpret_cast<char*>(second), selected_link_value.data());
            return 1u;
        case UiMessage::getSelectedChatHyperText:
            if (first != 0u) copyMessageText(reinterpret_cast<char*>(first), selected_hyper_text.data());
            return 1u;
        case UiMessage::getSelectedChatPlainText:
            if (first != 0u) copyMessageText(reinterpret_cast<char*>(first), selected_plain_text.data());
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

namespace {
    void appendPlainRun(std::vector<HyperTextRun>& destination, std::string_view text) {
        if (text.empty()) return;
        if (!destination.empty() && destination.back().isPlain()) destination.back().text.append(text);
        else destination.push_back({std::string(text), HyperTextGeometry{}});
    }

    void appendEditorElement(std::vector<HyperTextRun>& destination, const HyperTextRun& element) {
        if (element.isPlain()) appendPlainRun(destination, element.text);
        else destination.push_back(element);
    }

    void commitEditorElements(SphereUI::HyperTextEditControl& editor, std::vector<HyperTextRun>& replacement) {
        std::string raw, visible;
        SphereUI::detail::serializeHyperTextElements(replacement, raw, visible);
        editor.hyper_text = std::move(raw);
        editor.visible_text = std::move(visible);
        editor.elements = std::move(replacement);
    }

    std::string editorHistoryPath(const SphereUI::HyperTextEditControl& editor) {
        const auto* parent = editor.parent;
        if (parent == nullptr || parent->resource_name.empty()) return {};
        std::string profile;
        SphereUI::HyperTextEditControl::historyProfile(profile);
        return "players\\" + parent->resource_name + "_" + profile + "_hyperTextEdit.log";
    }
}

SphereUI::HyperTextEditControl::HyperTextEditControl() {
    maximum_history = 256u;
    cursor_type = 1u;
    cursor_visible = true;
    cursor_color = plain_color = player_link_color = item_link_color = link_color = UiColor::white;
    maximum_visible_length = 256u;
    maximum_hyper_length = 3072u;
    control_kind = UiControlKind::hyperTextEdit;
    edit_modes.set(PlainText);
}

void SphereUI::HyperTextEditControl::setContent(const char* text, std::uint32_t mode) {
    if (text == nullptr || mode > 1u) return;
    const std::string source(text);
    if (mode == 0u && source == hyper_text.data()) return;
    if (source.size() + (mode == 1u ? hyper_text.size() : 0u) > maximum_hyper_length) return;
    std::string plain;
    std::vector<HyperTextRun> parsed, replacement;
    HyperTextParser::parseElements(source, parsed, plain);
    const auto added_length = plain.size();
    if (mode == 1u && (visible_text.size() > maximum_visible_length || added_length > maximum_visible_length - visible_text.size())) return;
    std::size_t used = 0u;
    const auto append = [&](const std::vector<HyperTextRun>& input) {
        for (const auto& element : input) {
            const auto length = element.text.size();
            if (used >= maximum_visible_length) break;
            if (length > maximum_visible_length - used) {
                appendPlainRun(replacement, std::string_view(element.text.data(), maximum_visible_length - used));
                used = maximum_visible_length;
            } else {
                appendEditorElement(replacement, element);
                used += length;
            }
        }
    };
    if (mode == 1u) append(elements);
    append(parsed);
    commitEditorElements(*this, replacement);
    moveCaret(35u);
}

void SphereUI::HyperTextEditControl::insertPlainText(const char* text) {
    if (text == nullptr || visible_text.size() >= maximum_visible_length) return;
    const std::string insertion(text, std::min<std::size_t>(std::strlen(text), maximum_visible_length - visible_text.size()));
    if (insertion.empty()) return;
    caret_position = std::min(caret_position, visible_text.size());
    std::vector<HyperTextRun> replacement;
    std::size_t position = 0u;
    bool inserted = false;
    for (const auto& element : elements) {
        const auto length = element.text.size();
        if (!inserted && caret_position <= position + length) {
            const auto offset = caret_position - position;
            if (element.link() != nullptr && offset == 0u) {
                appendPlainRun(replacement, insertion);
                replacement.push_back(element);
            } else if (element.link() != nullptr && offset == length) {
                replacement.push_back(element);
                appendPlainRun(replacement, insertion);
            } else {
                std::string value(element.text.data(), length);
                value.insert(offset, insertion);
                appendPlainRun(replacement, value);
            }
            inserted = true;
        } else appendEditorElement(replacement, element);
        position += length;
    }
    if (!inserted) appendPlainRun(replacement, insertion);
    const auto caret = caret_position + insertion.size();
    commitEditorElements(*this, replacement);
    caret_position = caret;
    visible_last = caret_position == 0u ? 0u : caret_position - 1u;
    updateVisibleStart();
    updateVisibleEnd();
}

void SphereUI::HyperTextEditControl::insertCharacter(std::uint8_t character) {
    if (!edit_modes.test(PlainText) || character < 32u || (edit_modes.test(Numeric) && (character < '0' || character > '9'))) return;
    const char text[] = {static_cast<char>(character), 0};
    insertPlainText(text);
}

void SphereUI::HyperTextEditControl::eraseCharacter(bool backspace) {
    caret_position = std::min(caret_position, visible_text.size());
    if ((backspace && caret_position == 0u) || (!backspace && caret_position == visible_text.size())) return;
    const auto target = caret_position - (backspace ? 1u : 0u);
    std::vector<HyperTextRun> replacement;
    std::size_t position = 0u;
    for (const auto& element : elements) {
        const auto length = element.text.size();
        if (target >= position && target < position + length) {
            std::string value(element.text.data(), length);
            value.erase(target - position, 1u);
            appendPlainRun(replacement, value);
        } else appendEditorElement(replacement, element);
        position += length;
    }
    commitEditorElements(*this, replacement);
    caret_position = target;
    visible_first = std::min(visible_first, caret_position);
    updateVisibleEnd();
}

std::size_t SphereUI::HyperTextEditControl::fitText(const char* text, int font, int pixels, bool reverse) {
    const std::string_view value(text == nullptr ? "" : text);
    if (pixels <= 0 || value.empty()) return 0u;
    std::int64_t used = 0;
    for (std::size_t count = 0u; count < value.size(); ++count) {
        const auto index = reverse ? value.size() - count - 1u : count;
        const char glyph[] = {value[index], 0};
        used += InterfaceRenderer::measureText(glyph, font, true).width;
        if (used > pixels) return index;
    }
    return reverse ? 0u : value.size();
}

void SphereUI::HyperTextEditControl::updateVisibleEnd() {
    visible_first = std::min(visible_first, visible_text.size());
    if (visible_text.size() == 0u) {
        visible_last = 0u;
        return;
    }
    const auto length = visible_text.size() - visible_first;
    const auto fit = fitText(visible_text.data() + visible_first, font, std::max(0, width - text_margins.left - text_margins.right), false);
    visible_last = std::min(visible_text.size() - 1u, visible_first + (fit == length ? (length == 0u ? 0u : length - 1u) : fit));
}

void SphereUI::HyperTextEditControl::updateVisibleStart() {
    if (visible_text.size() == 0u) {
        visible_first = visible_last = 0u;
        return;
    }
    visible_last = std::min(visible_last, visible_text.size() - 1u);
    const std::string prefix(visible_text.data(), visible_last + 1u);
    const auto first = fitText(prefix.c_str(), font, std::max(0, width - text_margins.left - text_margins.right), true);
    visible_first = first == 0u ? 0u : first + 1u;
}

void SphereUI::HyperTextEditControl::moveCaret(std::uint32_t key) {
    caret_position = std::min(caret_position, visible_text.size());
    if (key == VK_HOME) {
        caret_position = visible_first = 0u;
        updateVisibleEnd();
    } else if (key == VK_END) {
        caret_position = visible_text.size();
        visible_last = caret_position == 0u ? 0u : caret_position - 1u;
        updateVisibleStart();
    } else if (key == VK_LEFT && caret_position != 0u) {
        --caret_position;
        if (caret_position < visible_first) visible_first = caret_position;
        updateVisibleEnd();
    } else if (key == VK_RIGHT && caret_position < visible_text.size()) {
        ++caret_position;
        if (caret_position > visible_last + 1u) {
            visible_last = caret_position - 1u;
            updateVisibleStart();
        }
        updateVisibleEnd();
    }
}

void SphereUI::HyperTextEditControl::drawElement(const TextExtent& point, HyperTextRun& element, std::uint32_t color, const UiIndexRange& range) {
    if (!element.isPlain() && element.link() == nullptr) return;
    const auto first = std::min(range.first, element.text.size());
    const auto length = range.last == invalidIndex ? element.text.size() - first : std::min(element.text.size() - first, range.last >= first ? range.last - first + 1u : 0u);
    std::string display(element.text.data() + first, length);
    if (element.isPlain() && edit_modes.test(Password)) display.assign(length, '*');
    if (element.link() != nullptr) {
        const auto kind = element.link()->link_kind;
        color = kind == 1u ? item_link_color : kind == 2u ? player_link_color : link_color;
    }
    const auto extent = InterfaceRenderer::measureText(display.c_str(), font, true);
    if (auto* geometry = element.geometry()) *geometry = {point.width, point.height, extent.width, extent.height};
    InterfaceRenderer::drawText(display.c_str(), point.width, point.height, SferaColor::fromArgb(color).withAlpha(alpha).argb(), font, true, windowBounds(*this), false);
}

void SphereUI::HyperTextEditControl::drawCaret() {
    if (cursor_type == 0u) return;
    const auto bounds = windowBounds(*this);
    const auto start = std::min(visible_first, visible_text.size()), caret = std::clamp(caret_position, start, visible_text.size());
    std::string prefix(visible_text.data() + start, caret - start);
    const auto left = bounds.left + text_margins.left + InterfaceRenderer::measureText(prefix.c_str(), font, true).width;
    const auto top = bounds.top + text_margins.top;
    const auto color = SferaColor::fromArgb(cursor_color).withAlpha(alpha).argb();
    if (cursor_type == 2u) InterfaceRenderer::drawText("_", left, top, color, font, true, bounds, false);
    else if (cursor_type == 1u) InterfaceRenderer::drawTexture(nullptr, static_cast<float>(left), static_cast<float>(top + 2), static_cast<float>(left + 1), static_cast<float>(bounds.bottom - text_margins.bottom - 2), color, 0.0f, 0.0f, false);
}

void SphereUI::HyperTextEditControl::draw() {
    if (hidden || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    ViewportScope clip(bounds);
    if (!clip) return;
    const auto now = Runtime::milliseconds();
    if (now - blink_started > 500u) {
        blink_started = now;
        cursor_visible = !cursor_visible ? 1u : 0u;
    }
    caret_position = std::min(caret_position, visible_text.size());
    updateVisibleEnd();
    if (cursor_visible && input_enabled) drawCaret();
    std::size_t position = 0u;
    TextExtent point{bounds.left + text_margins.left, bounds.top + text_margins.top};
    for (auto& element : elements) {
        const auto length = element.text.size();
        if (length != 0u && position + length > visible_first && position <= visible_last) {
            const UiIndexRange range{visible_first > position ? visible_first - position : 0u, std::min(length - 1u, visible_last - position)};
            drawElement(point, element, plain_color, range);
            if (const auto* geometry = element.geometry()) point.width = detail::addCoordinate(point.width, geometry->width);
        }
        position += length;
    }
}

void SphereUI::HyperTextEditControl::historyUp() {
    if (edit_modes.test(Password) || history.size() == 0u) return;
    history_position = std::min(history_position, history.size());
    if (history_position != 0u) --history_position;
    setContent(history.at(history_position).data());
}

void SphereUI::HyperTextEditControl::historyDown() {
    if (edit_modes.test(Password) || history.size() == 0u) return;
    if (history_position < history.size()) ++history_position;
    setContent(history.at(std::min(history_position, history.size() - 1u)).data());
}

void SphereUI::HyperTextEditControl::submitText() {
    notifyParent(*this, UiMessage::hyperEditSubmit);
    if (edit_modes.test(Password) || hyper_text.size() == 0u || maximum_history == 0u) return;
    std::deque<std::string> replacement;
    for (const auto& entry : history) {
        if (std::strcmp(entry.c_str(), hyper_text.c_str()) != 0) replacement.emplace_back(entry.c_str());
    }
    while (replacement.size() >= maximum_history) replacement.pop_front();
    replacement.emplace_back(hyper_text.c_str());
    history = std::move(replacement);
    history_position = history.size();
}

void SphereUI::HyperTextEditControl::pasteClipboard() {
    std::string value;
    Runtime::clipboardText(value);
    for (char& character : value) if (character == '\n' || character == '\r') character = ' ';
    insertPlainText(value.c_str());
}

void SphereUI::HyperTextEditControl::historyProfile(std::string& result) {
    std::ifstream stream("connectn.cfg");
    std::string line, value;
    while (std::getline(stream, line)) {
        if (line.size() < 2u || line[0] != 'M' || line[1] != 'A') continue;
        const auto dot = line.rfind('.');
        if (dot == std::string::npos) continue;
        const auto end = line.find('"', dot + 1u);
        if (end != std::string::npos) value += line.substr(dot + 1u, end - dot - 1u);
    }
    result.assign(value.c_str());
}

void SphereUI::HyperTextEditControl::transformHistory(std::string& result, const std::string& source, bool decode) {
    constexpr std::int8_t primary[] = {1, 2, 3, -2, 1, -1, -2, -3, 2, -1, 0, -2, 2};
    constexpr std::int8_t secondary[] = {0, -1, -2, 2, -1, 0, 1};
    std::string value(source.data(), source.size());
    for (std::size_t index = 0u; index < value.size(); ++index) {
        const auto shift = primary[index % 13u] + secondary[index % 7u];
        value[index] = static_cast<unsigned char>(value[index]) + (decode ? shift : -shift);
    }
    result.assign(value);
}

void SphereUI::HyperTextEditControl::loadHistory() {
    if (edit_modes.test(Password)) return;
    const auto path = editorHistoryPath(*this);
    if (path.empty()) return;
    std::ifstream stream(path, std::ios::binary);
    std::string line;
    while (history.size() < maximum_history && std::getline(stream, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        std::string decoded;
        transformHistory(decoded, line, true);
        history.push_back(std::move(decoded));
    }
    history_position = history.size();
}

void SphereUI::HyperTextEditControl::saveHistory() const {
    if (edit_modes.test(Password) || history.size() == 0u) return;
    const auto path = editorHistoryPath(*this);
    if (path.empty()) return;
    std::ofstream stream(path, std::ios::binary);
    for (std::size_t index = 0u; index < history.size() && stream; ++index) {
        std::string encoded{};
        transformHistory(encoded, history.at(index), false);
        stream.write(encoded.data(), encoded.size());
        stream << "\r\n";
    }
}

std::unique_ptr<SphereUI::Window> SphereUI::HyperTextEditControl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](auto& target, const auto& source, SphereUI::Window::CloneContext& context) {

        copyProperties(target, source,
            &HyperTextEditControl::elements, &HyperTextEditControl::history, &HyperTextEditControl::edit_modes,
            &HyperTextEditControl::visible_text, &HyperTextEditControl::hyper_text, &HyperTextEditControl::history_position,
            &HyperTextEditControl::maximum_history, &HyperTextEditControl::cursor_type, &HyperTextEditControl::caret_position,
            &HyperTextEditControl::blink_started, &HyperTextEditControl::cursor_visible, &HyperTextEditControl::text_margins,
            &HyperTextEditControl::cursor_color, &HyperTextEditControl::plain_color, &HyperTextEditControl::player_link_color,
            &HyperTextEditControl::item_link_color, &HyperTextEditControl::link_color,
            &HyperTextEditControl::maximum_visible_length, &HyperTextEditControl::maximum_hyper_length,
            &HyperTextEditControl::visible_first, &HyperTextEditControl::visible_last);
    });
}

bool SphereUI::HyperTextEditControl::loadUi(const char*, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    if (font < 2u || !reader.has("linkColor")) return false;
    plain_color = cursor_color = UiColor::white;
    reader.color("textColor", plain_color);
    reader.color("cursorColor", cursor_color);
    reader.color("linkColor", link_color);
    player_link_color = item_link_color = link_color;
    reader.color("playerLinkColor", player_link_color);
    reader.color("itemLinkColor", item_link_color);
    maximum_visible_length = maximum_history = 256u;
    maximum_hyper_length = 3072u;
    reader.count("maxVisibleTextLength", maximum_visible_length);
    reader.count("maxHyperTextLength", maximum_hyper_length);
    reader.count("maxHistoryLength", maximum_history);
    cursor_type = 1u;
    if (const char* value = reader.string("cursorType")) cursor_type = SferaSimpleParser::equalsIgnoreCase(value, "none") ? 0u : SferaSimpleParser::equalsIgnoreCase(value, "uline") ? 2u : 1u;
    edit_modes.reset();
    if (reader.has("editMode")) for (std::size_t index = 0u; index < parser.tokenCount(); ++index) {
        const char* value = reader.token(index);
        if (SferaSimpleParser::equalsIgnoreCase(value, "enterPlainText")) edit_modes.set(PlainText);
        else if (SferaSimpleParser::equalsIgnoreCase(value, "numbersOnly")) {
            edit_modes.set(PlainText);
            edit_modes.set(Numeric);
        } else if (SferaSimpleParser::equalsIgnoreCase(value, "password")) {
            edit_modes.set(PlainText);
            edit_modes.set(Password);
        }
    }
    if (edit_modes.none()) edit_modes.set(PlainText);
    text_margins = {};
    reader.rectangle("titleTextMargin", text_margins.left, text_margins.top, text_margins.right, text_margins.bottom);
    loadHistory();
    updateVisibleEnd();
    return true;
}

std::uint32_t SphereUI::HyperTextEditControl::handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) {
    switch (message) {
        case UiMessage::setInputEnabled:
            setInputFocus(first != 0u);
            return 1u;
        case UiMessage::setHyperEditContent:
            if (first != 0u) setContent(reinterpret_cast<const char*>(first), second);
            return 1u;
        case UiMessage::getHyperEditPlainText:
        case UiMessage::getHyperEditHyperText:
            if (first != 0u) copyMessageText(reinterpret_cast<char*>(first), message == UiMessage::getHyperEditPlainText ? visible_text.data() : hyper_text.data());
            return 1u;
        case UiMessage::getHyperEditLengths:
            storeValue(first, visible_text.size());
            storeValue(second, hyper_text.size());
            return 1u;
        case UiMessage::setHyperEditTextColor:
            plain_color = first;
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

void SphereUI::HyperTextEditControl::handleInput(const WindowInput& input) {
    if (hidden) return;
    if (input_enabled) {
        if (input.character >= 32u) insertCharacter(input.character);
        else if (input.character == 0u) {
            const auto key = input.key_code;
            if (key == VK_BACK || key == VK_DELETE) eraseCharacter(key == VK_BACK);
            else if (key == VK_END || key == VK_HOME || key == VK_LEFT || key == VK_RIGHT) moveCaret(key);
            else if (key == VK_UP) historyUp();
            else if (key == VK_DOWN) historyDown();
            else if (key == VK_RETURN) submitText();
            else if (key == VK_INSERT && (input.key_modifiers & 3u) != 0u) pasteClipboard();
            else if (key == VK_OEM_PLUS) insertCharacter('=');
        }
        input.key_code = input.character = 0u;
        Runtime::setTextInputActive(true);
    }
    if ((input.mouse_flags & MouseInput::leftPress) == 0u) return;
    const auto cursor = CCursorManager::instance().geometry();
    const auto bounds = windowBounds(*this);
    if (cursor.x < bounds.left || cursor.x >= bounds.right || cursor.y < bounds.top || cursor.y >= bounds.bottom) {
        setInputFocus(false);
        return;
    }
    if (!input_enabled) setInputFocus(true);
    if (visible_text.size() == 0u) return;
    const auto start = std::min(visible_first, visible_text.size());
    const auto end = std::min(visible_last + 1u, visible_text.size());
    const std::string visible(visible_text.data() + start, end > start ? end - start : 0u);
    caret_position = std::min(visible_text.size(), start + fitText(visible.c_str(), font, cursor.x - bounds.left - text_margins.left, false));
    if ((input.key_modifiers & 1u) == 0u) return;
    std::size_t position = 0u;
    for (const auto& element : elements) {
        if (caret_position >= position && caret_position < position + element.text.size() && element.link() != nullptr) {
            if (auto* description = Runtime::descriptionWindow()) description->showDescription(element.link()->linkValue(), 0u, 250u, false);
            break;
        }
        position += element.text.size();
    }
}

SphereUI::HyperTextEditControl::~HyperTextEditControl() {
    if (template_instance) {
        try { saveHistory(); }
        catch (const std::exception&) { }
    }
    Runtime::setTextInputActive(false);
}

SphereUI::ButtonCtrl::ButtonCtrl() {
    repeat_interval = 0.05f;
    hover_color = UiColor::white;
    hidden = false;
    control_kind = UiControlKind::button;
    text_alignment = TextAlignment::center;
}

SphereUI::CheckBox::CheckBox() {
    hover_color = UiColor::white;
    hidden = false;
    control_kind = UiControlKind::checkBox;
}

SphereUI::RadioButtonCtrl::RadioButtonCtrl() {
    control_kind = UiControlKind::radioButton;
}

SphereUI::TextCtrl::TextCtrl() {
    hidden = false;
    control_kind = UiControlKind::text;
}

SphereUI::ImageCtrl::ImageCtrl() {
    base_alpha = 255u;
    opacity = 1.0f;
    hidden = false;
    control_kind = UiControlKind::image;
}

SphereUI::ProgressBar::ProgressBar() {
    initializeProgressState();
    hidden = false;
    control_kind = UiControlKind::progressBar;
}

SphereUI::CMinimapControl::CMinimapControl() {
    resource_reference = nullptr;
    hidden = false;
    control_kind = UiControlKind::minimap;
}

std::unique_ptr<SphereUI::Window> SphereUI::Runtime::makeControl(SphereUI::UiControlKind kind) {
    switch (kind) {
        case UiControlKind::window:
            return std::make_unique<Window>();
        case UiControlKind::button:
            return std::make_unique<ButtonCtrl>();
        case UiControlKind::text:
            return std::make_unique<TextCtrl>();
        case UiControlKind::image:
            return std::make_unique<ImageCtrl>();
        case UiControlKind::progressBar:
            return std::make_unique<ProgressBar>();
        case UiControlKind::scrollBar:
            return std::make_unique<ScrollBar>();
        case UiControlKind::hyperText:
            return std::make_unique<HyperTextCtrl>();
        case UiControlKind::checkBox:
            return std::make_unique<CheckBox>();
        case UiControlKind::radioButton:
            return std::make_unique<RadioButtonCtrl>();
        case UiControlKind::tooltip:
            return std::make_unique<ToolTipCtrl>();
        case UiControlKind::textList:
            return std::make_unique<ListCtrl>();
        case UiControlKind::slider:
            return std::make_unique<SliderCtrl>();
        case UiControlKind::listItem:
            return std::make_unique<ListItemCtrl>();
        case UiControlKind::edit:
            return std::make_unique<EditCtrl>();
        case UiControlKind::slot:
            return std::make_unique<SlotCtrl>();
        case UiControlKind::spinButton:
            return std::make_unique<SpinButton>();
        case UiControlKind::richEdit:
            return std::make_unique<RichEditCtrl>();
        case UiControlKind::filteredList:
            return std::make_unique<FilterListCtrl>();
        case UiControlKind::minimap:
            return std::make_unique<CMinimapControl>();
        case UiControlKind::menu:
            return std::make_unique<CMenuListControl>();
        case UiControlKind::hyperTextChat:
            return std::make_unique<HyperTextChatListControl>();
        case UiControlKind::hyperTextEdit:
            return std::make_unique<HyperTextEditControl>();
        case UiControlKind::fontPicker:
            return std::make_unique<FontPicker>();
        default:
            return nullptr;
    }
}

void SphereUI::Window::alignToScreen(bool reset_position) {
    if (reset_position) {
        x = initial_x;
        y = initial_y;
    }
    const auto screen = Runtime::screenSize();
    const auto horizontal = static_cast<std::uint32_t>(screen.width) - static_cast<std::uint32_t>(width), vertical = static_cast<std::uint32_t>(screen.height) - static_cast<std::uint32_t>(height);
    if ((alignment_flags & alignRight) != 0u) x = detail::addCoordinate(x, static_cast<int>(horizontal));
    if ((alignment_flags & alignBottom) != 0u) y = detail::addCoordinate(y, static_cast<int>(vertical));
    if ((alignment_flags & alignCenterX) != 0u) x = detail::addCoordinate(x, static_cast<int>(horizontal >> 1u));
    if ((alignment_flags & alignCenterY) != 0u) y = detail::addCoordinate(y, static_cast<int>(vertical >> 1u));
}

void SphereUI::Window::applyAnimation(const AnimationPlayback& playback, float fraction) {
    const auto& effect = playback.effect;
    if (effect.kind == WindowAnimation::Kind::FadeIn || effect.kind == WindowAnimation::Kind::FadeOut) {
        setOpacity(effect.kind == WindowAnimation::Kind::FadeIn ? fraction : 1.0f - fraction);
        return;
    }
    if (effect.kind < WindowAnimation::Kind::MoveLeft || effect.kind > WindowAnimation::Kind::MoveDown) return;
    const double distance = static_cast<double>(effect.distance) * fraction;
    const double value = playback.origin + ((effect.kind == WindowAnimation::Kind::MoveLeft || effect.kind == WindowAnimation::Kind::MoveUp) ? -distance : distance);
    const auto coordinate = !std::isfinite(value) || value < -2147483648.0 || value >= 2147483648.0 ? std::numeric_limits<int>::min() : static_cast<int>(std::trunc(value));
    if (effect.kind <= WindowAnimation::Kind::MoveRight) setPosition(coordinate, y);
    else setPosition(x, coordinate);
}

void SphereUI::Window::startAnimation(WindowAnimation::Phase phase) {
    if (animation) applyAnimation(*animation, 1.0f);
    animation.reset();
    if (phase == WindowAnimation::Phase::Idle || phase > WindowAnimation::Phase::Closing) return;
    if (phase == WindowAnimation::Phase::Showing) setOpacity(1.0f);
    const auto& effect = phase == WindowAnimation::Phase::Showing ? show_animation : hide_animation;
    if (effect.kind == WindowAnimation::Kind::None) return;
    AnimationPlayback playback{effect, Runtime::clockTicks(), 0.0f, phase};
    if (effect.kind >= WindowAnimation::Kind::MoveLeft && effect.kind <= WindowAnimation::Kind::MoveDown) {
        playback.origin = static_cast<double>(effect.kind <= WindowAnimation::Kind::MoveRight ? x : y)
            - ((effect.kind == WindowAnimation::Kind::MoveRight || effect.kind == WindowAnimation::Kind::MoveDown) ? effect.distance : 0.0f) + effect.offset;
    }
    animation = playback;
    Runtime::playWindowSound(phase == WindowAnimation::Phase::Showing);
    updateAnimation();
}

void SphereUI::Window::updateAnimation() {
    if (!animation) return;
    const float elapsed = static_cast<double>(std::bit_cast<std::int64_t>(Runtime::clockTicks() - animation->start_time)) / 10000.0;
    float fraction = elapsed / animation->effect.duration;
    if (!std::isfinite(fraction) || fraction < 0.0f || fraction > 1.0f) fraction = 1.0f;
    applyAnimation(*animation, fraction);
    if (fraction == 1.0f) {
        if (animation->phase == WindowAnimation::Phase::Closing) close_completed = true;
        startAnimation(WindowAnimation::Phase::Idle);
    }
}

void SphereUI::Window::beginClose(bool animated) {
    if (!animated) {
        hidden = close_completed = true;
        input_enabled = false;
        return;
    }
    startAnimation(WindowAnimation::Phase::Closing);
    if (!isAnimating()) close_completed = true;
    input_enabled = false;
}

void SphereUI::Window::animateVisibility(bool hide) {
    if (hide) {
        startAnimation(WindowAnimation::Phase::Hiding);
        hide_after_animation = isAnimating();
        if (!isAnimating()) handleMessage(UiMessage::setHidden, 1u, 0u);
    } else {
        hide_after_animation = false;
        handleMessage(UiMessage::setHidden, 0u, 0u);
        startAnimation(WindowAnimation::Phase::Showing);
    }
}

SphereUI::Window* SphereUI::Window::controlAt(std::size_t index) const {
    if (index == 0u) return const_cast<Window*>(this);
    return index <= children.size() ? children[index - 1u].get() : nullptr;
}

void SphereUI::Window::addModalReference(Window& window) {
    modal_references.push_back(&window);
}
