#include "semantic_classes.h"
#include "zlib.h"
#include "semantic_static.h"
#include <commctrl.h>
#include <dinput.h>
#include <objbase.h>

#include <algorithm>
#include <array>
#include <bit>
#include <charconv>
#include <climits>
#include <fcntl.h>
#include <float.h>
#include <mbctype.h>
#include <cerrno>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <io.h>
#include <share.h>
#include <sys/stat.h>
#include <sys/locking.h>
#include <sys/utime.h>
#include <memory>
#include <new>
#include <fstream>
#include <filesystem>
#include <iterator>
#include <stdexcept>
#include <system_error>
#include <limits>
#include <string>
#include <string_view>
#include <span>
#include <vector>
#include <utility>
#include <ws2tcpip.h>
#include <shellapi.h>

namespace {
    template<class T> struct NamedValue {
        std::string_view name;
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

    void serializeHyperTextElements(std::span<const HyperTextRun> elements, std::string& hyper_text, std::string& plain);
    std::string escapeHyperText(std::string_view source);
    SphereUI::UiControlKind controlKind(std::string_view name);
    SphereUI::WindowAnimation::Kind animationKind(std::string_view name);
    std::uint32_t alignmentFlag(std::string_view name);
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
    static void openExternalLink(std::string_view target, bool mail);
    static void playLinkSound();
    static std::uint32_t milliseconds();
    static bool keyDown(std::uint32_t key);
    static bool descriptionAutoPopup();
    CDescriptionWindow* descriptionWindow();
    static void setDescriptionWindow(CDescriptionWindow* window);
    static bool playerHeading(float& heading);

    static TextExtent screenSize();

    std::unique_ptr<Window> makeControl(SphereUI::UiControlKind kind);
    static std::uint32_t keyCode(std::string_view name);

    void broadcastMessage(Window* root, int group, SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second, SphereUI::UiControlKind kind);
    static int findImage(std::string_view name);
    static void playClickSound();
    static void playScrollSound(bool page);
    static std::uint64_t clockTicks();
}

namespace SphereUI::Runtime {
    void invokeEventHandler(WindowEventHandler handler, Window* window, const WindowEvent& event);
}

namespace SphereUI::detail {
    namespace {

        template<class T, std::size_t Size> T lookup(std::string_view name, const NamedValue<T> (&values)[Size], T fallback) {
            for (const auto& entry : values) if (SferaText::asciiEqual(name, entry.name)) return entry.value;
            return fallback;
        }
    }

    SphereUI::UiControlKind controlKind(std::string_view name) {
        constexpr NamedValue<UiControlKind> values[] = { {
            "BUTTON", UiControlKind::button
        }, {"TEXT", UiControlKind::text}, {"IMAGE", UiControlKind::image}, {"PROGRESS_BAR", UiControlKind::progressBar}, {"SCROLL_BAR", UiControlKind::scrollBar}, {"HYPER_TEXT", UiControlKind::hyperText}, {"CHECKBOX", UiControlKind::checkBox}, {"RADIOBUTTON", UiControlKind::radioButton}, {"TEXTLIST", UiControlKind::textList}, {"SLIDER", UiControlKind::slider}, {"LISTITEM", UiControlKind::listItem}, {"EDIT", UiControlKind::edit}, {"SLOT", UiControlKind::slot}, {"SPINBUTTON", UiControlKind::spinButton}, {"RICHEDIT", UiControlKind::richEdit}, {"FILTERLISTCTRL", UiControlKind::filteredList}, {"MINIMAP", UiControlKind::minimap}, {"MENULISTCTRL", UiControlKind::menu}, {"HTCHATLISTCTRL", UiControlKind::hyperTextChat}, {"HTEDIT", UiControlKind::hyperTextEdit}, {"FONTPICKER", UiControlKind::fontPicker}, {"COLORPICKER", UiControlKind::colorPicker}};
        return lookup(name, values, anyControlKind);
    }

    SphereUI::WindowAnimation::Kind animationKind(std::string_view name) {
        constexpr NamedValue<SphereUI::WindowAnimation::Kind> values[] = { {
            "ALPHA_IN", WindowAnimation::Kind::FadeIn
        }, {"ALPHA_OUT", WindowAnimation::Kind::FadeOut}, {"MOVE_LEFT", WindowAnimation::Kind::MoveLeft}, {"MOVE_RIGHT", WindowAnimation::Kind::MoveRight}, {"MOVE_TOP", WindowAnimation::Kind::MoveUp}, {"MOVE_BOTTOM", WindowAnimation::Kind::MoveDown}};
        return lookup(name, values, WindowAnimation::Kind::None);
    }

    std::uint32_t alignmentFlag(std::string_view name) {
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

std::shared_ptr<const SphereUI::UiSprite> SphereUI::Window::findResource(std::string_view name_to_find) const {
    if (resource_parent != nullptr) if (auto resource = resource_parent->findResource(name_to_find)) return resource;
    const auto found = std::find_if(resources.begin(), resources.end(), [name_to_find](const auto& resource) {
        return SferaText::asciiEqual(resource->name, name_to_find);
    });
    return found == resources.end() ? nullptr : *found;
}

std::shared_ptr<const SphereUI::UiSprite> SphereUI::Window::getResource(std::string_view name_to_find) {
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

std::string_view HyperTextRun::Link::linkValue() const {
    const auto separator = target.find("://");
    if (separator == std::string::npos) return "";
    auto offset = separator + 3u;
    if (offset < target.size() && target[offset] == '/') ++offset;
    return std::string_view(target).substr(offset);
}

void SphereUI::HyperTextChatListItem::initialize(std::string_view text, std::uint32_t channel_id, std::uint32_t text_color) {
    HyperTextChatListItem replacement;
    replacement.hyper_text = text;
    replacement.channel = channel_id;
    replacement.color = text_color;
    HyperTextParser::parseElements(replacement.hyper_text, replacement.elements, replacement.plain_text);
    *this = std::move(replacement);
}

std::string SphereUI::detail::escapeHyperText(std::string_view text) {
        std::string output;
        for (const auto character : text) {
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
    g_sfera_direct_input_runtime.text_filter = active ? 1u : 0u;
}

void SphereUI::Runtime::broadcastMessage(Window* root, int group, SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second, SphereUI::UiControlKind kind) {
    if (root != nullptr) {
        root->dispatchMessage(group, message, first, second, kind);
        return;
    }
    for (const auto& window : g_sfera_interface.windows) if (window != nullptr) window->dispatchMessage(group, message, first, second, kind);
}

namespace {
    struct UiKeyBinding {
        std::string_view name;
        std::uint32_t code;
        std::uint32_t scan;
    };

    constexpr UiKeyBinding uiKeyBindings[] = { {
        "ESCAPE", VK_ESCAPE, 1u
    }, {"SCRL_LOCK", VK_SCROLL, 70u}, {"PAUSE", VK_PAUSE, 197u}, {"BACKSPACE", VK_BACK, 14u}, {"SPACE", VK_SPACE, 57u}, {"END", VK_END, 207u}, {"HOME", VK_HOME, 199u}, {"LEFT", VK_LEFT, 203u}, {"UP", VK_UP, 200u}, {"RIGHT", VK_RIGHT, 205u}, {"DOWN", VK_DOWN, 208u}, {"INSERT", VK_INSERT, 210u}, {"DELETE", VK_DELETE, 211u}, {"ENTER", VK_RETURN, 28u}, {"CAPSLOCK", VK_CAPITAL, 58u}, {"NUMPADMULT", VK_MULTIPLY, 55u}, {"NUMPADADD", VK_ADD, 78u}, {"NUMLOCK", VK_NUMLOCK, 69u}, {"NUMPADSUBT", VK_SUBTRACT, 74u}, {"NUMPADDIV", VK_DIVIDE, 181u}, {"NUMPADPNT", VK_DECIMAL, 83u}, {"PAGEUP", VK_PRIOR, 201u}, {"PAGEDOWN", VK_NEXT, 209u}, {"`", VK_OEM_3, 41u}, {"-", VK_OEM_MINUS, 12u}, {"=", VK_OEM_PLUS, 13u}, {"\\", VK_OEM_5, 43u}, {"[", VK_OEM_4, 26u}, {"]", VK_OEM_6, 27u}, {";", VK_OEM_1, 39u}, {"'", VK_OEM_7, 40u}, {",", VK_OEM_COMMA, 51u}, {".", VK_OEM_PERIOD, 52u}, {"/", VK_OEM_2, 53u}, {"TAB", VK_TAB, 15u}, {"CTRL", VK_CONTROL, 29u}, {"SHIFT", VK_SHIFT, 42u}};








    void playUiSound(const std::string& filename) {
        g_sfera_sound_runtime.playUiSound(filename);
    }
}

std::uint64_t SphereUI::Runtime::clockTicks() { return WorldClock::nowTicks(); }

std::uint32_t SphereUI::Runtime::keyCode(std::string_view name) {
    if (name.empty()) return 0u;
    for (std::uint32_t code = 0u; code <= 255u; ++code)
        if (const auto candidate = keyName(code); !candidate.empty() && SferaText::asciiEqual(name, candidate)) return code;
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
    return WorldClock::milliseconds();
}

bool SphereUI::Runtime::keyDown(std::uint32_t key) {
    return key < 256u && g_sfera_direct_input_runtime.keyboard_state[key] != 0u;
}

bool SphereUI::Runtime::descriptionAutoPopup() {
    return g_sfera_interface.description_auto_popup;
}

SphereUI::CDescriptionWindow* SphereUI::Runtime::descriptionWindow() {
    return g_sfera_interface.description_control;
}

void SphereUI::Runtime::setDescriptionWindow(CDescriptionWindow* window) {
    g_sfera_interface.description_control = window;
}

bool SphereUI::Runtime::playerHeading(float& heading) {
    const auto handle = g_sfera_world_objects.controlled_object_handle;
    if (static_cast<int>(handle) <= 0) return false;
    const auto* object = g_sfera_world_objects.effectObject(handle);
    if (object == nullptr) return false;
    heading = object->rotation.x;
    return true;
}

void SphereUI::Runtime::openExternalLink(std::string_view target, bool mail) {
    if (target.empty()) return;
    // ShellExecuteA is a native NUL-terminated API; materialize only at this boundary.
    const std::string native_target(target);
    ::ShellExecuteA(nullptr, "open", mail ? native_target.c_str() : "explorer", mail ? nullptr : native_target.c_str(), nullptr, SW_SHOWNORMAL);
    ::ShowWindow(SferaClientApplication::main_window, SW_MINIMIZE);
}

void SphereUI::Runtime::clipboardText(std::string& result) {
    result.clear();
    if (!::IsClipboardFormatAvailable(CF_TEXT) || !::OpenClipboard(nullptr)) return;
    struct ClipboardGuard {
        ~ClipboardGuard() { ::CloseClipboard(); }
    } clipboard;
    const auto handle = ::GetClipboardData(CF_TEXT);
    if (handle == nullptr) return;
    const auto size = ::GlobalSize(handle);
    if (size == 0) return;
    const auto* data = static_cast<const std::uint8_t*>(::GlobalLock(handle));
    if (data == nullptr) return;
    struct LockGuard {
        HGLOBAL handle;
        ~LockGuard() { ::GlobalUnlock(handle); }
    } lock{handle};
    const std::span<const std::uint8_t> bytes(data, size);
    const auto end = std::find(bytes.begin(), bytes.end(), std::uint8_t{});
    if (end != bytes.end()) result.assign(SferaText::fromBytes(bytes.first(static_cast<std::size_t>(end - bytes.begin()))));
}

namespace {
    constexpr std::uint32_t uiWhite = SferaColor::rgba(255u, 255u, 255u).argb();
    constexpr std::uint32_t uiInvalidTexture = std::numeric_limits<std::uint32_t>::max();

}

int SphereUI::Runtime::findImage(std::string_view name) {
    return g_sfera_textures.find(name);
}

SphereUI::TextExtent SphereUI::Runtime::screenSize() {
    return {g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height};
}

namespace SphereUI::Runtime {
    void invokeEventHandler(WindowEventHandler handler, Window* window, const WindowEvent& event);
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

    bool readHexColor(std::string_view text, std::uint32_t& color) {
        auto input = text;
        return readInteger(input, color, 16);
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
    public:
        UiReader(SferaSimpleParser& source, const SferaParserRange& scope) : parser(source), range(scope) {
            parser.getBlockRange(&saved_block);
        }

        UiReader(const UiReader&) = delete;
        UiReader& operator=(const UiReader&) = delete;

        ~UiReader() {
            parser.setBlockRange(&saved_block);
        }

        bool block(std::string_view key, SferaParserRange& result) {
            return parser.findBlock(key, &result, &range, 1);
        }

        bool has(std::string_view key) {
            return parser.findValue(key, &range);
        }

        std::string token(std::size_t index = 0u, bool quoted = false) {
            std::string result;
            if (quoted) parser.readQuotedString(index, result);
            else parser.readString(index, result);
            return result;
        }

        std::optional<std::string> string(std::string_view key, bool quoted = false) {
            if (!has(key)) return std::nullopt;
            std::string result;
            const bool present = quoted ? parser.readQuotedString(0u, result) : parser.readString(0u, result);
            if (!present) return std::nullopt;
            return result;
        }

        template<class T> void integer(std::string_view key, T& value) {
            if (has(key)) value = static_cast<T>(parser.readInt(0u));
        }

        void count(std::string_view key, std::size_t& value) {
            int parsed = 0;
            if (has(key) && parser.tryReadInt(0u, parsed) && parsed >= 0) value = parsed;
        }

        template<class T> void boolean(std::string_view key, T& value) {
            if (has(key)) value = static_cast<T>(parser.readBool(0u));
        }

        bool pair(std::string_view key, int& first, int& second) {
            if (!has(key)) return false;
            int values[2]{};
            if (!parser.readIntSequence(0u, values)) return false;
            first = values[0];
            second = values[1];
            return true;
        }

        bool rectangle(std::string_view key, int& left, int& top, int& right, int& bottom) {
            if (!has(key)) return false;
            int values[4]{};
            if (!parser.readIntSequence(0u, values)) return false;
            left = values[0];
            top = values[1];
            right = values[2];
            bottom = values[3];
            return true;
        }

        void color(std::string_view key, std::uint32_t& color) {
            if (!has(key)) return;
            int values[3]{};
            if (!parser.readIntSequence(0u, values)) return;
            color = SferaColor::rgba(values[0], values[1], values[2]).argb();
        }

        void rgba(std::string_view key, std::uint32_t& color) {
            if (!has(key)) return;
            int values[4]{};
            if (!parser.readIntSequence(0u, values)) return;
            color = SferaColor::rgba(values[0], values[1], values[2], values[3]).argb();
        }

        template<std::size_t Size> void flags(std::string_view key, std::uint32_t& value, const NamedValue<std::uint32_t> (&names)[Size], bool reset = false) {
            if (!has(key)) return;
            if (reset) value = 0u;
            for (std::size_t index = 0u; index < parser.tokenCount(); index += 2u) {
                const auto name = token(index);
                for (const auto& flag : names) if (SferaText::asciiEqual(name, flag.name)) value |= flag.value;
            }
        }

        void sprite(std::string_view key, SphereUI::Window& window, std::shared_ptr<const SphereUI::UiSprite>& destination) {
            const auto name = string(key, true);
            if (!name) return;
            auto* owner = window.parent;
            destination = (owner == nullptr ? window : *owner).getResource(*name);
        }

        void status(std::string_view key, std::uint32_t& mode) {
            const auto value = string(key);
            if (value) mode = SferaText::asciiEqual(*value, "PERCENT") ? 1u : SferaText::asciiEqual(*value, "STYLE1") ? 2u : 0u;
        }

        void drawMethod(SphereUI::Window& window, bool own_resources = false) {
            const auto method = string("drawMethod");
            if (!method) return;
            if (SferaText::asciiEqual(*method, "NONE")) window.behavior_flags |= WindowStyle::skipDrawing;
            else if (SferaText::asciiEqual(*method, "SPRITE")) {
                const auto name = token(1u, true);
                auto* owner = own_resources ? &window : window.parent;
                window.resource_reference = (owner == nullptr ? window : *owner).getResource(name);
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

    void renderLabel(const SphereUI::Window& window, std::string_view text, int x, int y, std::uint32_t color, const SphereUI::UiRect& clip, int font = inheritFont) {
        if (text.empty()) return;
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

    template<class Emit> void wrapTextLine(const SphereUI::Window& window, std::string_view text, bool wrap, Emit emit) {
        auto remaining = text;
        const auto measuredWidth = [&](std::string_view value) {
            return SphereUI::InterfaceRenderer::measureText(value, window.font, true).width - (window.font < 2u ? 2 : 0);
        };
        while (wrap && remaining.size() > 1u && measuredWidth(remaining) > window.width) {
            std::size_t fit = 0u, boundary = 0u;
            for (std::size_t index = 1u; index <= remaining.size(); ++index) {
                if (measuredWidth(remaining.substr(0u, index)) > window.width) break;
                fit = index;
                if (remaining[index - 1u] == ' ' || remaining[index - 1u] == ':' || remaining[index - 1u] == ';') boundary = index;
            }
            const auto count = boundary != 0u ? boundary : std::max(fit, std::size_t{1u});
            emit(remaining.substr(0u, count));
            remaining.remove_prefix(count);
        }
        emit(remaining);
    }

    void drawChild(SphereUI::Window* address, std::uint32_t alpha);
    void inputChild(SphereUI::Window* address, const SphereUI::WindowInput& input);
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

    template<class T> bool loadPart(SphereUI::Window& owner, std::unique_ptr<T>& destination, UiReader& reader, std::string_view key, const std::string& filename, SferaSimpleParser& parser, UiControlKind kind, std::uint32_t id) {
        SferaParserRange part{};
        if (!reader.block(key, part)) return false;
        std::unique_ptr<T> control(static_cast<T*>(owner.createControl(filename, parser, part, kind, id).release()));
        if (control) control->setParent(&owner);
        destination = std::move(control);
        return destination != nullptr;
    }

    void readAnimation(UiReader& reader, SferaSimpleParser& parser, std::string_view key, SphereUI::WindowAnimation& animation) {
        const auto name = reader.string(key);
        if (!name) return;
        animation.kind = SphereUI::detail::animationKind(*name);
        animation.duration = parser.readFloat(1u);
        animation.distance = parser.readFloat(2u);
        animation.offset = parser.readFloat(3u);
        if (animation.duration == 0.0f) animation.duration = 0.25f;
    }

    bool contains(const SphereUI::UiRect& bounds, int x, int y) {
        return x >= bounds.left && x < bounds.right && y >= bounds.top && y < bounds.bottom;
    }

    template<class T> void loadNavigationButtons(T& owner, UiReader& reader, const std::string& filename, SferaSimpleParser& parser, bool defaults, float interval = 0.0f) {
        constexpr std::string_view names[] = {"leftbutton", "rightbutton"};
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

bool SphereUI::Window::loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    reader.boolean("hitTransparent", hit_transparent);
    if (const auto value = reader.string("windowName", true)) setResourceName(*value);
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
    if (const auto value = reader.string("windowText")) setText(g_sfera_interface.localizedText(*value));
    if (const auto value = reader.string("windowHelp", true)) setHelp(*value);
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
        const auto name = child_reader.string("classID");
        if (name) if (auto child = createControl(filename, parser, entry, detail::controlKind(*name), ordinal)) {
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

std::uint32_t SphereUI::Window::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
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
        case UiMessage::setTextRgb:
            text_color = SferaColor::fromArgb(first).withAlpha(alpha).argb();
            break;
        case UiMessage::setHidden:
            hidden = first != 0u;
            if (hidden) hide_tip();
            break;
        case UiMessage::setEnabled:
            disabled = first == 0u;
            if (disabled) hide_tip();
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
        case UiMessage::endModal:
            if (modal_owner != nullptr) {
                modal_owner = nullptr;
                handleMessage(UiMessage::animateVisibility, 0u, 0u);
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

void SphereUI::Window::dispatchMessage(int target_group, SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second, SphereUI::UiControlKind target_kind) {
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

bool SphereUI::ButtonCtrl::loadUi(const std::string&, SferaSimpleParser& parser, const SferaParserRange& range) {

    UiReader reader(parser, range);
    reader.sprite("checkedImage", *this, pressed_image);
    reader.sprite("focusedImage", *this, hover_image);
    reader.sprite("disabledImage", *this, disabled_image);
    reader.sprite("uncheckedImage", *this, idle_image);
    reader.flags("buttonStyle", button_flags, buttonStyles);
    const auto method = reader.string("drawMethod");
    if (method && SferaText::asciiEqual(*method, "SPRITE")) button_flags |= ButtonStyle::stateImages;
    if (method && SferaText::asciiEqual(*method, "NONE")) behavior_flags |= WindowStyle::skipDrawing;
    if (const auto name = reader.string("hotKey", true)) {
        hotkey = Runtime::keyCode(*name);
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

std::uint32_t SphereUI::ButtonCtrl::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
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

bool SphereUI::CheckBox::loadUi(const std::string&, SferaSimpleParser& parser, const SferaParserRange& range) {

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

std::uint32_t SphereUI::CheckBox::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::setChecked:
            checked = first != 0u;
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
    if (password && password_text.size() != text.size()) password_text.assign(text.size(), '*');
}

bool SphereUI::EditCtrl::loadUi(const std::string&, SferaSimpleParser& parser, const SferaParserRange& range) {
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

void SphereUI::EditCtrl::setEditText(std::string_view value) {
    text.assign(value);
    updatePassword();
}

std::uint32_t SphereUI::EditCtrl::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::setInputEnabled:
            setInputFocus(first != 0u, submit_on_blur);
            return 1u;
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
            value.insert(caret_position, input.text());
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
        if (value != getText()) setText(value);
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
    const std::string_view display = password ? password_text : getText();
    const auto extent = InterfaceRenderer::measureText(display, font, font_initialized);
    const auto prefix = display.substr(0u, static_cast<std::size_t>(caret_position));
    const auto caret_x = InterfaceRenderer::measureText(prefix, font, font_initialized).width;
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

bool SphereUI::ListCtrl::loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) {
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
        if (!key.empty() && readHexColor(color_text, color)) addText(g_sfera_interface.localizedText(key), color);
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

std::uint32_t SphereUI::ListCtrl::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
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
        case UiMessage::clearList:
            clearRows();
            return 1u;
        case UiMessage::removeListRow:
            removeRow(first);
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
                const bool truncated = continue_mark && InterfaceRenderer::measureText(row.text, font, font_initialized).width > width;
                if (truncated) clip.right = detail::subtractCoordinate(clip.right, mark_width);
                InterfaceRenderer::drawText(row.text, row_x, row_y, row_color, font, true, clip, alpha == 255u);
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

std::uint32_t SphereUI::FilterListCtrl::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
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

bool SphereUI::FontPicker::loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) {
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

std::uint32_t SphereUI::FontPicker::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    if (message == UiMessage::setSelectedFont) {
        setFont(first);
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

bool SphereUI::ImageCtrl::loadUi(const std::string&, SferaSimpleParser& parser, const SferaParserRange& range) {

    UiReader reader(parser, range);
    resource_reference = nullptr;
    reader.sprite("image", *this, resource_reference);
    reader.integer("alpha", base_alpha);
    reader.flags("imageStyle", image_style, imageStyles, true);
    if (reader.has("rotate")) setRotationDegrees(parser.readFloat(0u));
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::ImageCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](auto& target, const auto& source, SphereUI::Window::CloneContext& context) {

        copyProperties(target, source,
            &ImageCtrl::image_style, &ImageCtrl::interaction_active, &ImageCtrl::fallback_image, &ImageCtrl::rotated,
            &ImageCtrl::rotation_radians, &ImageCtrl::base_alpha, &ImageCtrl::opacity);
    });
}

std::uint32_t SphereUI::ImageCtrl::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::setImageAlpha:
            base_alpha = std::min<std::uint32_t>(first, 255u);
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

bool SphereUI::ListItemCtrl::loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) {
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

std::uint32_t SphereUI::ListItemCtrl::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
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
        case UiMessage::setListItemSelection:
            selected_index = first < items.size() ? static_cast<int>(first) : -1;
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

void SphereUI::ListItemCtrl::dispatchMessage(int target_group, SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second, SphereUI::UiControlKind target_kind) {
    for (std::size_t index = 0u; index < items.size(); ++index) if (auto* child = itemAt(index)) child->dispatchMessage(target_group, message, first, second, target_kind);
}

bool SphereUI::ToolTipCtrl::loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    reader.integer("font", font);
    reader.color("textColor", text_color);
    reader.color("backcolor", background_color);
    reader.rectangle("margin", margin_left, margin_top, margin_right, margin_bottom);
    parser.setScanRange(&range);
    try {
        while (parser.nextValue("toolstr")) {
            const auto key = reader.token();
            appendLine(g_sfera_interface.localizedText(key));
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

std::uint32_t SphereUI::ToolTipCtrl::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
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
        InterfaceRenderer::drawText(lines.at(index), text_x, text_y, text_color, font, true, clip, opacity == 255u);
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

bool SphereUI::ProgressBar::loadUi(const std::string&, SferaSimpleParser& parser, const SferaParserRange& range) {

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

std::uint32_t SphereUI::ProgressBar::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    if (message < UiMessage::setProgressValue || message > UiMessage::getProgressValue) return Window::handleMessage(message, first, second);
    switch (message) {
        case UiMessage::setProgressValue:
            setProgressValue(static_cast<int>(first));
            return 1u;
        case UiMessage::setProgressRange:
            setProgressRange(static_cast<int>(first), static_cast<int>(second));
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
        renderLabel(*this, status_text, left, top, text_color, {left, top, detail::addCoordinate(left, 100), detail::addCoordinate(top, 100)});
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

bool SphereUI::ScrollBar::loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    if (reader.has("horizontal") && parser.readBool(0u)) orientation_flags = 1u;
    reader.rectangle("bounds", track_left, track_top, track_right, track_bottom);
    reader.boolean("postMessage", notify_changes);
    reader.drawMethod(*this);
    if (reader.has("scrollSpr")) {
        const auto name = reader.token(0u, true);
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

std::uint32_t SphereUI::ScrollBar::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
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
        case UiMessage::increaseScroll:
        case UiMessage::decreaseScroll:
            if (moveScroll(*this, message == UiMessage::increaseScroll, step)) loadControlParameters();
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

bool SphereUI::SliderCtrl::loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) {
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
        renderLabel(*this, value_text, left, top, text_color, {left, top, detail::addCoordinate(left, 100), detail::addCoordinate(top, 100)});
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

bool SphereUI::SpinButton::loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) {
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

std::uint32_t SphereUI::SpinButton::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::setSpinValue:
            setCurrentValue(static_cast<int>(first));
            return 1u;
        case UiMessage::setSpinRange:
            setRange(static_cast<int>(first), static_cast<int>(second));
            return 1u;
        case UiMessage::updateSpinStatus:
            updateStatus();
            return 1u;
        case UiMessage::setSpinStep:
            setStep(static_cast<int>(first));
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
            auto value = std::format("{}", current);
            window->setText(value);
        }
        if (notify_changes && update_enabled) owner->queueEvent({this, control_id, UiMessage::spinValueChanged, static_cast<std::uint32_t>(current), 0u});
        previous = current;
    }
    status_valid = true;
    update_enabled = true;
}

bool SphereUI::TextCtrl::loadUi(const std::string&, SferaSimpleParser& parser, const SferaParserRange& range) {

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


}

const std::string& SphereUI::Window::getText() const {
    return text;
}

const std::string& SphereUI::Window::getHelp() const {
    return help;
}

void SphereUI::Window::setText(std::string_view value) {
    text.assign(value);
}

void SphereUI::Window::setHelp(std::string_view value) {
    help.assign(value);
}

const std::string& SphereUI::Window::getName() const {
    return name;
}

const std::string& SphereUI::Window::getResourceName() const {
    return resource_name;
}

void SphereUI::Window::setName(std::string_view value) {
    name.assign(value);
}

void SphereUI::Window::setResourceName(std::string_view value) {
    resource_name.assign(value);
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

void SphereUI::ImageCtrl::setImageName(std::string_view name) {
    ImageDescription description{};
    description.name.assign(name);
    setImage(&description);
}

void SphereUI::ImageCtrl::setRotationDegrees(float degrees) {
    rotated = degrees != 0.0f;
    rotation_radians = degrees / 180.0f * 3.1415929794311523f;
}

void SphereUI::ImageCtrl::setImage(const ImageDescription* description) {
    if (description == nullptr) { resource_reference.reset(); return; }
    if (resource_reference && SferaText::asciiEqual(resource_reference->name, description->name)) return;
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

std::unique_ptr<SphereUI::Window> SphereUI::Window::createControl(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range, SphereUI::UiControlKind kind, std::uint32_t id) {
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
    if (const auto value = reader.string("windowText")) control->setText(g_sfera_interface.localizedText(*value));
    if (const auto value = reader.string("windowHelp", true)) control->setHelp(*value);
    if (const auto value = reader.string("setWindowText", true)) control->setText(*value);
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
        const auto extent = InterfaceRenderer::measureText(lines.at(index), font, true);
        widest = std::max(widest, extent.width);
        total = detail::addCoordinate(total, extent.height);
        line_height = extent.height;
    }
    tooltip_width = detail::addCoordinate(widest, detail::addCoordinate(margin_left, margin_right));
    tooltip_height = detail::addCoordinate(total, detail::addCoordinate(margin_top, margin_bottom));
}

void SphereUI::ToolTipCtrl::appendLine(std::string_view text) {
    lines.emplace_back(text);
    updateLayout();
}

void SphereUI::ToolTipCtrl::setLine(std::uint32_t index, std::optional<std::string_view> text) {
    if (index >= lines.size()) {
        if (text) appendLine(*text);
        return;
    }
    const auto value = text.value_or(std::string_view{});
    if (lines.at(index) == value) return;
    lines.at(index).assign(value);
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
    constexpr std::string_view names[] = {"window_caption", "window_bottom", "window_left", "window_right"};
    std::shared_ptr<const UiSprite>* sprites[] = {&caption_sprite, &bottom_sprite, &left_sprite, &right_sprite};
    for (std::size_t index = 0u; index < 4u; ++index) {
        *sprites[index] = findResource(names[index]);
        if (*sprites[index] == 0u) throw std::runtime_error(std::string("description sprite is missing: ") + std::string(names[index]));
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
    if ((!Runtime::descriptionAutoPopup() && !pinned) || (!hidden && WorldClock::deadlineReached(Runtime::milliseconds(), hide_deadline))) close();
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

void SphereUI::CDescriptionWindow::showDescription(std::string_view text, const Window* source, std::uint32_t duration, bool pin) {
    Window* content = nullptr;
    detail::forEachChild(*this, [&](Window& child) {
        if (content == nullptr) content = &child;
    });
    if (content == nullptr) throw std::runtime_error("description content control is missing");
    if (auto* hypertext = dynamic_cast<HyperTextCtrl*>(content)) {
        hypertext->queueBuffer(text);
        hypertext->handleMessage(UiMessage::resizeToHyperText, 0u, 0u);
    }
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

void SphereUI::CDescriptionWindow::requestDescription(std::string_view text, bool force, const Window* source) {
    if (text.empty()) return;
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
    else if (WorldClock::deadlineReached(Runtime::milliseconds(), show_deadline)) showDescription(text, pending_source, 250u, false);
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

void SphereUI::ListCtrl::appendLine(std::string_view text, std::uint32_t color) {
    if (parent != nullptr && selected_index != -1) {
        selected_index = -1;
        notifyParent(*this, UiMessage::listSelectionChanged, invalidIndex);
    }
    int offset = 0;
    if (text_alignment != 0u) {
        const auto extent = InterfaceRenderer::measureText(text, font, font_initialized);
        const auto remainder = detail::subtractCoordinate(width, extent.width);
        if ((text_alignment & TextAlignment::right) != 0u) offset = remainder;
        if ((text_alignment & TextAlignment::horizontalCenter) != 0u) offset = std::abs(static_cast<std::int64_t>(remainder)) / 2;
    }
    appendCircular(rows, maximum_items, write_index, UiTextRow{std::string(text), color, offset});
    updateLayout();
}

void SphereUI::ListCtrl::appendFormattedLine(std::string_view text, std::uint32_t color) {
    wrapTextLine(*this, text, format_strings, [&](std::string_view line) {
        appendLine(line, color);
    });
}

void SphereUI::ListCtrl::addText(std::string_view text, std::uint32_t color) {
    std::size_t begin = 0u;
    for (;;) {
        const auto end = text.find('\n', begin);
        appendFormattedLine(text.substr(begin, end == std::string_view::npos ? end : end - begin), color);
        if (end == std::string_view::npos) break;
        begin = end + 1u;
    }
}

void SphereUI::ListCtrl::appendMessageText(std::string_view text, std::uint32_t color) {
    const bool at_bottom = detail::addCoordinate(vertical_offset, 5) >= maximum_scroll;
    addText(text, color);
    if (chatlike && at_bottom) {
        vertical_offset = maximum_scroll;
        if (auto* bar = scrollbar.get()) bar->setParameters({0u, ScrollField::position, 0, 0, 0, vertical_offset, 0});
        updateVisibleRange();
    }
}

bool SphereUI::ListCtrl::setRowText(std::size_t index, std::string_view value) {
    if (index >= rows.size()) return false;
    rows.at(index).text.assign(value);
    return true;
}

std::string_view SphereUI::ListCtrl::rowText(std::size_t index) const {
    if (index >= rows.size()) return {};
    return rows.at(physicalIndex(index)).text;
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
        const auto extent = InterfaceRenderer::measureText(row.text, font, font_initialized);
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

void SphereUI::FilterListCtrl::appendHistory(std::string_view text, std::uint32_t color, std::uint32_t mask) {
    appendCircular(history, maximum_items, history_write, HistoryEntry{std::string(text), color, mask});
}

void SphereUI::FilterListCtrl::appendFilteredText(std::string_view text, std::uint32_t packed_color) {
    const auto components = SferaColor::fromArgb(packed_color);
    const auto mask = components.alpha();
    const auto color = components.withAlpha(0u).argb();
    const std::string value(text);
    appendHistory(value, color, mask);
    if ((filter_mask & mask) != 0u) appendMessageText(text, color);
}

void SphereUI::FilterListCtrl::applyFilter(std::uint32_t mask) {
    if (mask == filter_mask) return;
    filter_mask = mask;
    if (history.size() == 0u) return;
    clearRows();
    for (std::size_t index = 0u; index < history.size(); ++index) {
        const auto& row = history.at(index);
        if ((row.filter & mask) != 0u) addText(row.text, row.color);
    }
}

namespace {
    void menuLabel(const SphereUI::Window& window, std::string_view text, const SphereUI::UiRect& margins, const SphereUI::TextExtent& size, std::uint32_t format, std::uint32_t color, int left, int top, const SphereUI::UiRect& clip) {
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

bool SphereUI::CMenuListControl::loadUi(const std::string&, SferaSimpleParser& parser, const SferaParserRange& range) {
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

void SphereUI::CMenuListControl::addItem(std::string_view text, bool enabled) {
    if (items.size() >= maximum_items) return;
    items.push_back({std::string(text), enabled});
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

std::uint32_t SphereUI::CMenuListControl::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::clearMenu:
            clearItems();
            break;
        case UiMessage::activateMenuItem:
            if (first < items.size() && items.at(first).enabled != 0u) notifyParent(*this, UiMessage::menuItemActivated, first, items.size());
            break;
        case UiMessage::setMenuItemEnabled:
            if (first < items.size()) items.at(first).enabled = second != 0u;
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

void SphereUI::SlotCtrl::setOverlay(std::shared_ptr<const UiSprite>& destination, std::optional<std::string_view> image) {
    if (!image) { destination.reset(); return; }
    auto replacement = std::make_shared<UiSprite>();
    replacement->setImage(*image);
    destination = std::move(replacement);
}

void SphereUI::SlotCtrl::setItem(std::optional<std::string_view> image) {
    if (!image) {
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
    if (item_image.name != *image) item_image.setImage(*image);
    show_full_background = false;
    has_item = true;
}

void SphereUI::SlotCtrl::setItemCount(std::uint32_t count) {
    if (count == item_count) return;
    setText(count == 0u ? "" : std::to_string(static_cast<int>(count)));
    item_count = count;
}

bool SphereUI::SlotCtrl::loadUi(const std::string&, SferaSimpleParser& parser, const SferaParserRange& range) {
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
    if (number != 0) setText(std::to_string(number));
    if (const auto image = reader.string("slotItem", true)) setItem(*image);
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

std::uint32_t SphereUI::SlotCtrl::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
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

void SphereUI::RichEditCtrl::setContent(std::string_view text) {
    const auto source = text;
    std::vector<std::string> replacement{};
    std::string line;
    int used_width = 0;
    for (std::size_t index = 0; index < source.size(); ++index) {
        const auto glyph = source.substr(index, 1u);
        const auto extent = InterfaceRenderer::measureText(glyph, font, font_initialized);
        if (glyph == "\n" || used_width + extent.width + cursor_width > width) {
            replacement.push_back(line);
            line.clear();
            used_width = 0;
        } else {
            line.append(glyph);
            used_width += extent.width;
        }
    }
    if (!line.empty() || replacement.size() == 0u) replacement.push_back(line);
    lines = std::move(replacement);
    caret_row = static_cast<int>(lines.size()) - 1;
    caret_column = lines.at(caret_row).size();
    ensureCaretVisible();
}

std::string SphereUI::RichEditCtrl::content(std::size_t limit) const {
    std::string result;
    for (const auto& line : lines) {
        if (result.size() == limit) break;
        const auto count = std::min(line.size(), limit - result.size());
        result.append(line, 0, count);
        if (count < line.size()) break;
        if (result.size() < limit) result.push_back('\n');
    }
    return result;
}

void SphereUI::RichEditCtrl::insertAt(std::uint32_t column, std::string glyph, std::uint32_t row) {
    if (glyph.size() != 1u) throw std::invalid_argument("Rich edit insertion requires one code unit");
    for (;;) {
        if (row >= lines.size()) {
            lines.push_back(std::move(glyph));
            return;
        }
        std::string text = lines.at(row);
        text.insert(std::min<std::size_t>(column, text.size()), glyph);
        if (text.size() < 2u || InterfaceRenderer::measureText(text, font, font_initialized).width + cursor_width <= width) {
            lines.at(row).assign(text);
            return;
        }
        glyph.assign(text, text.size() - 1u, 1u);
        text.pop_back();
        lines.at(row).assign(text);
        ++row;
        column = 0u;
    }
}

void SphereUI::RichEditCtrl::insertCharacter(std::string_view glyph) {
    if (glyph.size() != 1u) throw std::invalid_argument("Rich edit insertion requires one code unit");
    ensureCaretVisible();
    const auto& row = lines.at(caret_row);
    const auto prospective = InterfaceRenderer::measureText(row, font, font_initialized).width + InterfaceRenderer::measureText(glyph, font, font_initialized).width + cursor_width;
    if (caret_column == static_cast<int>(row.size()) && prospective >= width) {
        insertAt(0u, std::string(glyph), ++caret_row);
        caret_column = 1;
    } else {
        insertAt(static_cast<std::uint32_t>(caret_column), std::string(glyph), static_cast<std::uint32_t>(caret_row));
        ++caret_column;
    }
    ensureCaretVisible();
}

std::uint32_t SphereUI::RichEditCtrl::mergeRows(std::uint32_t destination, std::uint32_t source) {
    if (destination >= lines.size() || source >= lines.size() || destination == source) return 0u;
    std::string text = lines.at(destination).data();
    const std::string following = lines.at(source).data();
    std::uint32_t count = 0u;
    for (const auto character : following) {
        text.push_back(character);
        if (InterfaceRenderer::measureText(text, font, font_initialized).width + cursor_width > width) {
            text.pop_back();
            break;
        }
        ++count;
    }
    lines.at(destination).assign(text);
    return count;
}

void SphereUI::RichEditCtrl::eraseCharacter(bool backward) {
    ensureCaretVisible();
    std::uint32_t row = caret_row;
    std::string text = lines.at(row);
    if (backward && caret_column > 0) {
        text.erase(--caret_column, 1u);
        lines.at(row).assign(text);
    } else if (!backward && caret_column < static_cast<int>(text.size())) {
        text.erase(caret_column, 1u);
        lines.at(row).assign(text);
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
        else lines.at(row + 1u).assign(remainder);
    }
    ensureCaretVisible();
}

void SphereUI::RichEditCtrl::splitLine() {
    ensureCaretVisible();
    std::string text = lines.at(caret_row).data();
    const auto following = text.substr(caret_column);
    text.resize(caret_column);
    lines.insert(lines.begin() + caret_row + 1, following);
    lines.at(caret_row).assign(text);
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
    const auto extent = InterfaceRenderer::measureText(prefix, font, font_initialized);
    InterfaceRenderer::drawText("_", static_cast<int>(left) + extent.width, static_cast<int>(top), text_color, font, font_initialized, windowBounds(*this), false);
}

bool SphereUI::RichEditCtrl::loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) {
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

std::uint32_t SphereUI::RichEditCtrl::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
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
            for (auto row = start; row < finish; ++row) InterfaceRenderer::drawText(lines.at(row), bounds.left, bounds.top + (row - start) * line_height, text_color, font, font_initialized, bounds, false);
            if (caret_row >= start && caret_row < finish) drawCaret(static_cast<float>(bounds.left), static_cast<float>(bounds.top + (caret_row - start) * line_height));
        }
    }
    drawChild(scrollbar.get(), alpha);
}

void SphereUI::RichEditCtrl::handleInput(const WindowInput& input) {
    if (input_enabled) Runtime::setTextInputActive(true);
    if (hidden) return;
    if (input_enabled) {
        if (input.character >= 32u) insertCharacter(input.text());
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

std::uint32_t SphereUI::HyperTextCtrl::parseTextFormat(std::string_view name) {
    if (SferaText::asciiEqual(name, "RIGHT")) return 1u;
    if (SferaText::asciiEqual(name, "CENTER")) return 2u;
    if (SferaText::asciiEqual(name, "PARAGRAPH")) return 3u;
    return 0u;
}

void SphereUI::HyperTextCtrl::queuePage(std::string_view name, bool remember) {
    if (transition_active) return;
    if (name.empty()) { pending_page = std::monostate{}; return; }
    PageRequest request{std::string(name.substr(0u, 255u)), remember};
    pending_page = std::move(request);
}

void SphereUI::HyperTextCtrl::queueBuffer(std::string_view buffer) {
    if (transition_active || buffer.empty()) return;
    pending_page = std::string(buffer);
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
        if (auto* source = g_sfera_interface.findHyperText(request->name)) replacement = source->clone(page_width, text_format, font);
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

void SphereUI::HyperTextCtrl::openLink(std::string_view target) {
    if (target.empty()) return;
    const auto value = target;
    const auto separator = value.find(':');
    const auto scheme = value.substr(0u, separator);
    if (SferaText::asciiEqual(scheme, "HTS")) {
        if (separator == std::string::npos) return;
        const auto first = value.find_first_not_of('\\', separator + 1u);
        if (first != std::string::npos) queuePage(value.substr(first), true);
    } else Runtime::openExternalLink(value, SferaText::asciiEqual(scheme, "mailto"));
}

bool SphereUI::HyperTextCtrl::loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    if (const auto value = reader.string("textFormat")) text_format = parseTextFormat(*value);
    if (const auto value = reader.string("hyperText", true)) queuePage(*value, false);
    loadPart(*this, scrollbar, reader, "scrollbar", filename, parser, UiControlKind::scrollBar, 1u);
    if (reader.has("linkcolor")) {
        const auto first = reader.token(0u);
        readHexColor(first, link_color);
        const auto second = reader.token(1u);
        readHexColor(second, hover_color);
    }
    if (const auto value = reader.string("flags")) if (SferaText::asciiEqual(*value, "DISCARD_OLD_TEXT")) discard_old_text = true;
    return true;
}

std::unique_ptr<SphereUI::Window> SphereUI::HyperTextCtrl::cloneInto(CloneContext& context) const {
    return cloneControl(*this, context, [](HyperTextCtrl& copy, const HyperTextCtrl& source, SphereUI::Window::CloneContext& context) {
        copy.copyHyperTextState(source, context);
        if (copy.tooltip == nullptr) copy.tooltip = std::make_unique<ToolTipCtrl>();
    });
}

std::uint32_t SphereUI::HyperTextCtrl::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
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
                queuePage(name, false);
            }
            return 1u;
        case UiMessage::clearHyperTextHistory:
            history.clear();
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
                tip->setLine(0u, page->tooltips.at(hovered).target);
                tip->showAt(input.mouse_x, input.mouse_y);
            }
        }
        tooltip_index = hovered;
    }
    for (std::size_t index = 0u; index < page->links.size(); ++index) {
        auto& link = page->links.at(index);
        link.hovered = link.contains(input.mouse_x, input.mouse_y) ? 1u : 0u;
        if (link.hovered && (input.mouse_flags & MouseInput::leftPress) != 0u) {
            openLink(link.target);
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

bool SphereUI::HyperTextChatListControl::loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) {
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

std::string_view SphereUI::HyperTextChatListControl::messageText(std::size_t index, bool plain) const {
    if (index >= visible_messages.size()) return "";
    const auto& item = messages.at(visible_messages.at(index));
    return plain ? std::string_view(item.plain_text) : std::string_view(item.hyper_text);
}

void SphereUI::HyperTextChatListControl::addMessage(std::string_view text, std::uint32_t channel, std::uint32_t color) {
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

void SphereUI::HyperTextChatListControl::setChannels(std::span<const std::uint32_t> values) {
    channels.assign(values.begin(), values.end());
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
        replacement.initialize(item.hyper_text, item.channel, item.color);
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
    InterfaceRenderer::drawText(element.text, left, top, SferaColor::fromArgb(color).withAlpha(alpha).argb(), font, true, clip, false);
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

std::uint32_t SphereUI::HyperTextChatListControl::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::verticalScroll:
            readScroll();
            return 1u;
        case UiMessage::addChatChannel:
            addChannel(first);
            return 1u;
        case UiMessage::clearChatChannels:
            clearChannels();
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

void SphereUI::HyperTextEditControl::setContent(std::string_view text, std::uint32_t mode) {
    if (mode > 1u) return;
    const auto source = text;
    if (mode == 0u && source == hyper_text) return;
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
                appendPlainRun(replacement, std::string_view(element.text).substr(0u, maximum_visible_length - used));
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

void SphereUI::HyperTextEditControl::insertPlainText(std::string_view text) {
    if (visible_text.size() >= maximum_visible_length) return;
    const auto insertion = text.substr(0u, maximum_visible_length - visible_text.size());
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
                std::string value(element.text, length);
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

void SphereUI::HyperTextEditControl::insertCharacter(std::string_view glyph) {
    if (glyph.size() != 1u) throw std::invalid_argument("Hypertext insertion requires one code unit");
    if (!edit_modes.test(PlainText) || std::as_bytes(std::span(glyph)).front() < std::byte{32} ||
        (edit_modes.test(Numeric) && (glyph < "0" || glyph > "9"))) return;
    insertPlainText(glyph);
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
            std::string value(element.text, length);
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

std::size_t SphereUI::HyperTextEditControl::fitText(std::string_view text, int font, int pixels, bool reverse) {
    const auto value = text;
    if (pixels <= 0 || value.empty()) return 0u;
    std::int64_t used = 0;
    for (std::size_t count = 0u; count < value.size(); ++count) {
        const auto index = reverse ? value.size() - count - 1u : count;
        used += InterfaceRenderer::measureText(value.substr(index, 1u), font, true).width;
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
    const auto first = fitText(prefix, font, std::max(0, width - text_margins.left - text_margins.right), true);
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
    std::string password;
    std::string_view display = std::string_view(element.text).substr(first, length);
    if (element.isPlain() && edit_modes.test(Password)) {
        password.assign(length, '*');
        display = password;
    }
    if (element.link() != nullptr) {
        const auto kind = element.link()->link_kind;
        color = kind == 1u ? item_link_color : kind == 2u ? player_link_color : link_color;
    }
    const auto extent = InterfaceRenderer::measureText(display, font, true);
    if (auto* geometry = element.geometry()) *geometry = {point.width, point.height, extent.width, extent.height};
    InterfaceRenderer::drawText(display, point.width, point.height, SferaColor::fromArgb(color).withAlpha(alpha).argb(), font, true, windowBounds(*this), false);
}

void SphereUI::HyperTextEditControl::drawCaret() {
    if (cursor_type == 0u) return;
    const auto bounds = windowBounds(*this);
    const auto start = std::min(visible_first, visible_text.size()), caret = std::clamp(caret_position, start, visible_text.size());
    std::string prefix(visible_text.data() + start, caret - start);
    const auto left = bounds.left + text_margins.left + InterfaceRenderer::measureText(prefix, font, true).width;
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
        if (entry != hyper_text) replacement.emplace_back(entry);
    }
    while (replacement.size() >= maximum_history) replacement.pop_front();
    replacement.emplace_back(hyper_text);
    history = std::move(replacement);
    history_position = history.size();
}

void SphereUI::HyperTextEditControl::pasteClipboard() {
    std::string value;
    Runtime::clipboardText(value);
    for (auto& character : value) if (character == '\n' || character == '\r') character = ' ';
    insertPlainText(value);
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
    result.assign(value);
}

void SphereUI::HyperTextEditControl::transformHistory(std::string& result, const std::string& source, bool decode) {
    constexpr std::int8_t primary[] = {1, 2, 3, -2, 1, -1, -2, -3, 2, -1, 0, -2, 2};
    constexpr std::int8_t secondary[] = {0, -1, -2, 2, -1, 0, 1};
    std::string value(source);
    std::size_t index = 0;
    SferaText::transformBytes(value, [&](std::uint8_t byte) {
        const auto shift = primary[index % std::size(primary)] + secondary[index % std::size(secondary)];
        ++index;
        return byte + (decode ? shift : -shift);
    });
    result = std::move(value);
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

bool SphereUI::HyperTextEditControl::loadUi(const std::string&, SferaSimpleParser& parser, const SferaParserRange& range) {
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
    if (const auto value = reader.string("cursorType")) cursor_type = SferaText::asciiEqual(*value, "none") ? 0u : SferaText::asciiEqual(*value, "uline") ? 2u : 1u;
    edit_modes.reset();
    if (reader.has("editMode")) for (std::size_t index = 0u; index < parser.tokenCount(); ++index) {
        const auto value = reader.token(index);
        if (SferaText::asciiEqual(value, "enterPlainText")) edit_modes.set(PlainText);
        else if (SferaText::asciiEqual(value, "numbersOnly")) {
            edit_modes.set(PlainText);
            edit_modes.set(Numeric);
        } else if (SferaText::asciiEqual(value, "password")) {
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

std::uint32_t SphereUI::HyperTextEditControl::handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::setInputEnabled:
            setInputFocus(first != 0u);
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
        if (input.character >= 32u) insertCharacter(input.text());
        else if (input.character == 0u) {
            const auto key = input.key_code;
            if (key == VK_BACK || key == VK_DELETE) eraseCharacter(key == VK_BACK);
            else if (key == VK_END || key == VK_HOME || key == VK_LEFT || key == VK_RIGHT) moveCaret(key);
            else if (key == VK_UP) historyUp();
            else if (key == VK_DOWN) historyDown();
            else if (key == VK_RETURN) submitText();
            else if (key == VK_INSERT && (input.key_modifiers & 3u) != 0u) pasteClipboard();
            else if (key == VK_OEM_PLUS) insertCharacter("=");
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
    caret_position = std::min(visible_text.size(), start + fitText(visible, font, cursor.x - bounds.left - text_margins.left, false));
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

void SphereUI::Window::beginModal(Window* owner) {
    if (modal_owner != nullptr) return;
    modal_owner = owner;
    animateVisibility(true);
}

namespace {
    template<class T> std::size_t vacantGuiSlot(const std::vector<std::unique_ptr<T>>& slots) {
        const auto slot = std::find(slots.begin(), slots.end(), nullptr);
        if (slot == slots.end()) WorldDiagnostics::fail("Array bounds exceeded");
        return static_cast<std::size_t>(slot - slots.begin());
    }

    void eraseGuiControl(std::uint32_t handle, const GameUiElement& item) {
        WorldGuiControls::detachFromWindow(item.windowHandle, item.windowSlot);
        WorldGuiControls::elements.at(handle).reset();
    }

    template<class Build> std::uint32_t createGuiControl(std::uint32_t windowHandle, std::string_view operation, Build&& build) {
        auto* window = GameInterface::window(windowHandle, operation);
        if (!window) { windowHandle = 0; window = GameInterface::window(windowHandle); }
        if (!window) WorldDiagnostics::fail("create_control: root window is unavailable");
        const auto handle = static_cast<std::uint32_t>(vacantGuiSlot(WorldGuiControls::elements));
        auto item = std::make_unique<GameUiElement>();
        item->windowHandle = windowHandle;
        const bool keep = build(*item, *window);
        item->windowSlot = window->attach(handle);
        WorldGuiControls::elements[handle] = std::move(item);
        if (!keep) { eraseGuiControl(handle, *WorldGuiControls::elements[handle]); return UINT32_MAX; }
        window->recalculateSize();
        return handle;
    }
}
GameUiElement* WorldGuiControls::control(std::uint32_t handle) {
    return handle < elements.size() ? elements[handle].get() : nullptr;
}
void WorldGuiControls::detachFromWindow(std::uint32_t windowHandle, std::uint32_t slot) {
    auto* owner = GameInterface::window(windowHandle);
    if (!owner) WorldDiagnostics::fail("internal error 75248635");
    owner->detach(slot);
}
void WorldGuiControls::destroySprite(std::uint32_t handle) {
    auto* item = control(handle);
    if (!item) { WorldDiagnostics::warning("delete_sprite: wrong handle"); return; }
    eraseGuiControl(handle, *item);
}
void WorldGuiControls::destroyText(std::uint32_t handle) {
    if (handle == UINT32_MAX) WorldDiagnostics::fail("Wrong hand was used!");
    auto* item = control(handle);
    if (!item) WorldDiagnostics::fail("delete_text: wrong handle");
    eraseGuiControl(handle, *item);
}
void WorldGuiControls::removeForObject(std::uint32_t objectHandle) {
    for (std::uint32_t handle = 0; handle < elements.size(); ++handle) {
        const auto* item = control(handle);
        if (item && item->objectHandle == objectHandle) eraseGuiControl(handle, *item);
    }
}

// Font codecs, sprite resources, hypertext and both UI render adapters.
namespace {
    struct PcxHeader {
        static constexpr std::size_t encodedSize = 128;
        static constexpr std::uint8_t runMarker = 3u << 6;
        std::uint16_t minimum_y;
        std::uint16_t maximum_y;
        static PcxHeader decode(const std::uint8_t* bytes) noexcept { return {SferaBinary::readLittleEndian<std::uint16_t>(bytes + 6), SferaBinary::readLittleEndian<std::uint16_t>(bytes + 10)}; }
    };

}

bool SphereUI::FontFace::load(std::optional<std::string_view> display_name, const std::string& filename, std::string_view texture_name) {
    if (filename.empty()) return false;
    std::ifstream stream(filename, std::ios::binary);
    if (!stream) {
        const std::string message = std::string("Can't open font '") + filename + "'";
        if (auto* log = g_sfera_error_log_runtime.outputs[1u]; log != nullptr) log->write(message);
        return false;
    }
    std::array<std::uint8_t, 4> signature{};
    if (!SferaBinary::read(stream, signature) || SferaText::fromBytes(signature) != "SFNT") return false;
    FontFace replacement;
    const auto stored_name = SferaText::readTerminated(stream, 256u);
    if (!stored_name) return false;
    const auto stored_texture = SferaText::readTerminated(stream, 256u);
    if (!stored_texture) return false;
    replacement.name = display_name ? *display_name : std::string_view(*stored_name);
    const auto texture_id = g_sfera_textures.find(texture_name);
    if (texture_id == -1) {
        const std::string message = std::string("Can't load texture '") + std::string(texture_name) + "' for font '" + replacement.name + "'";
        InterfaceRenderer::reportError(message);
        return false;
    }
    replacement.texture = static_cast<std::uint32_t>(texture_id);
    std::array<std::uint8_t, 8> metrics{};
    if (!SferaBinary::read(stream, metrics)) return false;
    replacement.line_height = SferaBinary::readLittleEndian<int>(metrics.data());
    replacement.baseline = SferaBinary::readLittleEndian<int>(metrics.data() + 4);
    // SFNT stores 224 little-endian records, including a legacy two-byte gap after advance.
    std::array<std::uint8_t, FontGlyph::encodedSize> record{};
    for (auto& glyph : std::span(replacement.glyphs).subspan(32u)) {
        if (!SferaBinary::read(stream, record)) return false;
        glyph = FontGlyph::decode(record);
        glyph.bearing_y = static_cast<std::uint16_t>(glyph.bearing_y) - static_cast<std::uint16_t>(replacement.baseline);
    }
    *this = std::move(replacement);
    return true;
}

SphereUI::FontFactory::FontFactory() = default;
SphereUI::FontFactory::~FontFactory() = default;

void SphereUI::FontFactory::initialize() {
    vertices.resize(1200u);
    std::fill(vertices.begin(), vertices.end(), SferaScreenVertex{});
    quad_indices.resize(2400u);
    vertex_count = 0u;
}

void SphereUI::FontFactory::clear() {
    faces.clear();
    vertices.clear();
    quad_indices.clear();
    vertex_count = 0u;
}

bool SphereUI::FontFactory::load(const std::string& filename, std::string_view texture_name) {
    auto loaded = std::make_unique<FontFace>();
    if (!loaded->load(std::nullopt, filename, texture_name)) return false;
    faces.push_back(std::move(loaded));
    return true;
}

void SphereUI::FontFactory::loadNamedFont(std::string_view name) {
    if (name.empty()) return;
    std::string localized_name(name);
    const auto& suffix = g_sfera_font_runtime.language_suffix;
    if (!suffix.empty() && !SferaText::asciiEqual(suffix, "_e")) localized_name += suffix;
    const std::string filename = "Effects\\" + localized_name + ".sfn";
    if (!load(filename, localized_name)) {
        const std::string message = "Can't load font '" + localized_name + "'";
        InterfaceRenderer::reportError(message);
    }
}

void SphereUI::FontFactory::loadConfiguration() {
    InterfaceConfiguration::open("fonts.cfg");
    if (InterfaceConfiguration::empty()) {
        InterfaceRenderer::reportError("File 'fonts.cfg' doesn't exist or contains no font configuration.");
        return;
    }
    std::uint32_t count = 0u;
    count = InterfaceConfiguration::readInteger("NEW_FONTS_NUMBER", count);
    for (std::uint32_t index = 0u; index < count; ++index) {
        const std::string key = "NEW_FONT_" + std::to_string(index);
        const auto text = InterfaceConfiguration::value(key);
        const std::string_view value = text.value_or(std::string_view{});
        const auto end = value.find('"', 1u);
        if (value.empty() || value.front() != '"' || end == std::string_view::npos) {
            const std::string message = "Missing quoted font name for '" + key + "' in fonts.cfg.";
            InterfaceRenderer::reportError(message);
            continue;
        }
        std::string name(value.substr(1u, end - 1u));
        std::replace(name.begin(), name.end(), '\r', ' ');
        std::erase(name, '\n');
        loadNamedFont(name);
    }
}

std::size_t SphereUI::FontFactory::count() const noexcept {
    return faces.size();
}

const SphereUI::FontFace& SphereUI::FontFactory::face(int font) const {
    if (font < 2 || std::size_t(font - 2) >= faces.size()) throw std::out_of_range("invalid font index");
    return *faces[font - 2u];
}

std::uint32_t SphereUI::InterfaceRenderer::tracking(int font) noexcept {
    return font >= 0 && font < 2 ? g_sfera_font_runtime.faces[font].code_base : 0u;
}

bool SferaInterfaceCursor::loadTextures() {
    for (std::size_t index = 0u; index < textures.size(); ++index) {
        const auto name = sfera_cursor_texture_name(static_cast<std::uint32_t>(index));
        textures[index] = g_sfera_textures.find(name);
        if (textures[index] == -1) SphereUI::InterfaceRenderer::reportError((std::string("Cursor texture '") + std::string(name) + "' not found"));
    }
    kind = 0u;
    images = {};
    labels = {};
    return true;
}

void SferaInterfaceCursor::setImage(std::size_t layer, std::optional<std::string_view> texture, int x, int y) {
    if (layer >= images.size()) return;
    auto& image = images[layer];
    image.x = x;
    image.y = y;
    image.texture = texture ? g_sfera_textures.find(*texture) : -1;
    const auto extent = image.texture == -1 ? SphereUI::TextExtent{32, 32} : g_sfera_textures.size(image.texture);
    image.width = extent.width;
    image.height = extent.height;
}

void SferaInterfaceCursor::setImageSize(std::size_t layer, int width, int height) {
    if (layer >= images.size()) return;
    images[layer].width = width;
    images[layer].height = height;
}

void SferaInterfaceCursor::setText(std::size_t layer, std::string_view text, int x, int y, int font, std::uint32_t color) {
    if (layer >= labels.size()) return;
    auto& label = labels[layer];
    label.x = x;
    label.y = y;
    label.font = font;
    label.color = color;
    label.text = text;
}

void SferaInterfaceCursor::setKind(std::uint32_t cursor_kind) {
    if (cursor_kind >= textures.size() && cursor_kind != 255u) return;
    kind = cursor_kind;
    centered_hotspot = cursor_kind >= 2u && cursor_kind < textures.size();
}

void SferaInterfaceCursor::draw(float x, float y) const {
    auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get());
    if (!system_visible || device == nullptr) return;
    RenderStateScope state(*g_sfera_graphics_runtime.d3d_runtime, RenderStateScope::FailurePolicy::Skip);
    if (!state) return;
    if (centered_hotspot) { x -= 16.0f; y -= 16.0f; }
    device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    if (kind < textures.size() && textures[kind] != 0u) SphereUI::InterfaceRenderer::drawTexture(g_sfera_textures.resource(textures[kind]), x, y, x + 32.0f, y + 32.0f, -1);
    for (const auto& image : images) {
        if (image.texture == -1) continue;
        const float left = x + static_cast<float>(image.x), top = y + static_cast<float>(image.y);
        SphereUI::InterfaceRenderer::drawTexture(g_sfera_textures.resource(image.texture), left, top, left + static_cast<float>(image.width), top + static_cast<float>(image.height), -1);
    }
    device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    const SphereUI::UiRect clip{SphereUI::InterfaceRenderer::clip_rectangle.left, SphereUI::InterfaceRenderer::clip_rectangle.top, SphereUI::InterfaceRenderer::clip_rectangle.right, SphereUI::InterfaceRenderer::clip_rectangle.bottom};
    for (const auto& label : labels) if (!label.text.empty()) SphereUI::InterfaceRenderer::drawText(label.text, static_cast<int>(static_cast<double>(x) + label.x), static_cast<int>(static_cast<double>(y) + label.y), label.color, label.font, true, clip, SferaColor::fromArgb(label.color).alpha() == 255u);
}

CCursorManager* CCursorManager::initialized = nullptr;

CCursorManager::~CCursorManager() { initialized = nullptr; }

CCursorManager& CCursorManager::instance() { static CCursorManager manager; initialized = &manager; return manager; }

bool CCursorManager::hasActiveCursor() noexcept { return initialized != nullptr && initialized->active != nullptr; }

void CCursorManager::focusChanged(bool focused) noexcept {
    if (!focused) {
        ::ClipCursor(nullptr);
        if (::GetCapture() == SferaClientApplication::main_window) ::ReleaseCapture();
    }
    if (!initialized) return;
    if (!focused) {
        initialized->hardware.clip_enabled = false;
        initialized->software.active = false;
    } else if (initialized->active) {
        initialized->active->show();
        initialized->active->apply();
    }
}

void CCursorManager::shutdown() noexcept {
    focusChanged(false);
    if (!initialized) return;
    ::SetCursor(nullptr);
    initialized->hardware.cursor_handle.reset();
    initialized->active = nullptr;
    SphereUI::Runtime::setSystemCursorVisible(true);
}

CCursor* CCursorManager::currentCursor() const noexcept { return active; }

CCursor* CCursorManager::activeCursor() const {
    if (active == nullptr) { CSphereError error; error.write("CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set"); }
    return active;
}

void CCursorManager::select(std::uint32_t mode) {
    if (mode > 1u) return;
    CCursor* selected = mode == 0u ? static_cast<CCursor*>(&software) : static_cast<CCursor*>(&hardware);
    if (selected == active) return;
    CCursor* previous = active;
    active = selected;
    selected->copyStateFrom(previous);
    if (previous != nullptr) previous->deactivate();
    selected->activate();
}

bool CCursorManager::usesSoftwareCursor() const noexcept { return active == &software; }

SferaCursorPosition CCursorManager::position() const {
    SferaCursorPosition result{};
    if (active != nullptr) active->getPosition(&result);
    return result;
}

SphereUI::CursorGeometry CCursorManager::geometry() const {
    if (active == nullptr) return {};
    SferaCursorPosition position{};
    active->getPosition(&position);
    const auto dimensions = active == &software ? SphereUI::TextExtent{static_cast<int>(software.texture_width), static_cast<int>(software.texture_height)} : SphereUI::TextExtent{static_cast<int>(hardware.texture_width), static_cast<int>(hardware.texture_height)};
    const auto kind = active->cursorKind();
    const auto name = sfera_cursor_texture_name(kind);
    return {position.x, position.y, dimensions.width, dimensions.height, !name.empty() && name.front() != '_'};
}

void SphereUI::InterfaceRenderer::drawTexture(IDirect3DBaseTexture9* texture, float left, float top, float right, float bottom, std::uint32_t color, float u, float v, bool textured) {
    auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get());
    if (device == nullptr) return;
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, texture));
    std::array<SferaScreenVertex, 4> vertices{};
    const float offset = textured ? 0.5f : 0.0f;
    for (std::size_t index = 0u; index < 4u; ++index) {
        auto& vertex = vertices[index];
        vertex.x = (index == 0u || index == 3u ? left : right) - offset;
        vertex.y = (index < 2u ? top : bottom) - offset;
        vertex.z = 0.0f;
        vertex.rhw = 1.0f;
        vertex.diffuse = color;
        if (textured) {
            vertex.u = index == 0u || index == 3u ? 0.0f : u;
            vertex.v = index < 2u ? 0.0f : v;
        }
    }
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1));
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2u, vertices.data(), sizeof(SferaScreenVertex)));
}

void SphereUI::InterfaceRenderer::reportError(std::string_view message) {
    for (std::uint32_t index : {1u, 0u}) if (auto* output = g_sfera_error_log_runtime.outputs[index]) {
        if (index == 1u) output->write("*** ERROR ****************************************************:");
        output->write(message);
    }
}

void SphereUI::InterfaceRenderer::setSpriteRenderMode(std::uint32_t mode) {
    if (mode == SphereUI::InterfaceRenderer::sprite_render_mode) return;
    if (auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get()); device != nullptr && mode <= 2u) {
        device->SetRenderState(D3DRS_ALPHABLENDENABLE, mode == 0u ? FALSE : TRUE);
        if (mode != 0u) { device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA); device->SetRenderState(D3DRS_DESTBLEND, mode == 2u ? D3DBLEND_ONE : D3DBLEND_INVSRCALPHA); }
    }
    SphereUI::InterfaceRenderer::sprite_render_mode = mode;
}

void SphereUI::UiSprite::resetParts(std::size_t count) {
    if (parts.size() != count) parts = std::vector<SpritePart>(count);
}

void SphereUI::SpritePart::setTexture(std::string_view image_name, const UiRect* texture_rectangle, const UiRect* sprite_rectangle) {
    texture_name = image_name;
    texture = g_sfera_textures.find(image_name);
    if (texture < 0) {
        const auto message = std::string("Sprite::Texture not found '") + std::string(image_name) + "'";
        SphereUI::InterfaceRenderer::reportError(message);
    }
    const auto extent = g_sfera_textures.size(texture);
    const auto coordinate = [](int value, int maximum) { return maximum == 0 ? 0.0f : static_cast<float>(static_cast<double>(value) / maximum); };
    const auto source = texture_rectangle == nullptr ? UiRect{0, 0, extent.width, extent.height} : *texture_rectangle;
    const float left = texture_rectangle == nullptr ? 0.0f : coordinate(source.left, extent.width), top = texture_rectangle == nullptr ? 0.0f : coordinate(source.top, extent.height), right = texture_rectangle == nullptr ? 1.0f : coordinate(source.right, extent.width), bottom = texture_rectangle == nullptr ? 1.0f : coordinate(source.bottom, extent.height);
    for (std::size_t index = 0; index < 4; ++index) {
        u[index] = index == 0 || index == 3 ? left : right;
        v[index] = index < 2 ? top : bottom;
    }
    rectangle = sprite_rectangle == nullptr ? UiRect{0, 0, extent.width, extent.height} : *sprite_rectangle;
}

namespace {
    void uiSpriteLoadDiagnostic(const std::string& filename, const SferaParserRange& range, std::string_view message) {
        const auto diagnostic = "Sprite::Load(" + filename + "," + std::to_string(range.begin) + "," + std::to_string(range.end) + ") -> " + std::string(message);
        SphereUI::InterfaceRenderer::reportError(diagnostic);
    }
}

void SphereUI::UiSprite::setImage(std::string_view name) {
    this->name = name;
    resetParts(1u);
    auto& part = parts.front();
    part.setTexture(name, nullptr, nullptr);
    width = part.rectangle.right;
    height = part.rectangle.bottom;
}

bool SphereUI::UiSprite::loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    std::string text;
    if (parser.findValue("name", &range) && parser.readQuotedString(0u, text)) name = text;
    else uiSpriteLoadDiagnostic(filename, range, "Name not specified.");
    if (parser.findValue("size", &range)) {
        width = parser.readInt(0u);
        height = parser.readInt(1u);
    } else uiSpriteLoadDiagnostic(filename, range, "Size not specified.");
    struct ScanScope {
        SferaSimpleParser& parser;
        SferaParserRange saved{};
        explicit ScanScope(SferaSimpleParser& source) : parser(source) { parser.getScanRange(&saved); }

        ~ScanScope() { parser.setScanRange(&saved); }
    } scan(parser);
    std::size_t count = 0u;
    parser.setScanRange(&range);
    while (parser.nextValue("texture")) ++count;
    if (count == 0u) uiSpriteLoadDiagnostic(filename, range, "At least one texture must be specified.");
    resetParts(count);
    std::size_t index = 0u;
    parser.setScanRange(&range);
    while (parser.nextValue("texture")) {
        if (!parser.readQuotedString(0u, text)) continue;
        int rectangles[8]{};
        if (!parser.readIntSequence(1u, rectangles)) uiSpriteLoadDiagnostic(filename, range, "Incorrect number of args in 'texture'.");
        const UiRect source{rectangles[0], rectangles[1], rectangles[2], rectangles[3]};
        const UiRect destination{rectangles[4], rectangles[5], rectangles[6], rectangles[7]};
        parts[index++].setTexture(text, &source, &destination);
    }
    parser.setScanRange(&range);
    while (parser.nextValue("tcoords")) {
        int values[9]{};
        if (!parser.readIntSequence(0u, values)) uiSpriteLoadDiagnostic(filename, range, "Incorrect number of args in 'tcoords'.");
        const int part_index = values[0];
        if (part_index < 0 || std::cmp_greater_equal(part_index, count) || parts[part_index].texture < 0) continue;
        const auto size = g_sfera_textures.size(parts[part_index].texture);
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex) {
            parts[part_index].u[vertex] = size.width == 0 ? 0.0f : static_cast<float>(static_cast<double>(values[vertex * 2u + 1u]) / size.width);
            parts[part_index].v[vertex] = size.height == 0 ? 0.0f : static_cast<float>(static_cast<double>(values[vertex * 2u + 2u]) / size.height);
        }
    }
    return true;
}

SphereUI::UiViewport SphereUI::InterfaceRenderer::viewport() {
    D3DVIEWPORT9 value{};
    if (auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get())) (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->GetViewport(&value));
    return {value.X, value.Y, value.Width, value.Height, value.MinZ, value.MaxZ};
}

void SphereUI::InterfaceRenderer::setViewport(const UiViewport& value) {
    if (auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get())) {
        const D3DVIEWPORT9 viewport{value.x, value.y, value.width, value.height, value.minimum_z, value.maximum_z};
        device->SetViewport(&viewport);
    }
}

namespace {
    std::array<SferaScreenVertex, 4> spriteQuad(const SphereUI::SpritePart& part, float left, float top, float right, float bottom, std::uint32_t color) {
        std::array<SferaScreenVertex, 4> vertices{};
        for (std::size_t index = 0u; index < vertices.size(); ++index) {
            auto& vertex = vertices[index];
            vertex.x = index == 0u || index == 3u ? left : right;
            vertex.y = index < 2u ? top : bottom;
            vertex.rhw = 1.0f;
            vertex.diffuse = color;
            vertex.u = part.u[index];
            vertex.v = part.v[index];
        }
        return vertices;
    }
}

void SphereUI::UiSprite::drawParts(float left, float top, float right, float bottom, std::uint32_t color, bool natural) const {
    if (parts.size() == 0u && !natural) return;
    auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get());
    if (device == nullptr) return;
    device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    if (parts.size() == 0u) return;
    const float scale_x = natural ? 1.0f : (right - left) / static_cast<float>(width), scale_y = natural ? 1.0f : (bottom - top) / static_cast<float>(height);
    left -= 0.5f;
    top -= 0.5f;
    int previous_texture = -1;
    for (std::size_t index = 0u; index < parts.size(); ++index) {
        const auto& part = parts[index];
        if (part.texture != previous_texture) {
            g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, g_sfera_textures.resource(part.texture));
            previous_texture = part.texture;
        }
        const auto position = [natural](int value, float scale) {
            const auto result = static_cast<float>(value) * scale;
            return natural ? result : std::floor(result);
        };
        const auto vertices = spriteQuad(part, left + position(part.rectangle.left, scale_x), top + position(part.rectangle.top, scale_y), left + (natural ? static_cast<float>(part.rectangle.right) : position(part.rectangle.right, scale_x)), top + (natural ? static_cast<float>(part.rectangle.bottom) : position(part.rectangle.bottom, scale_y)), color);
        (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1));
        (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2u, vertices.data(), sizeof(SferaScreenVertex)));
    }
}

void SphereUI::UiSprite::drawRotated(float left, float top, float right, float bottom, std::uint32_t color, float rotation) const {
    if (parts.size() == 0u) return;
    const auto& part = parts.front();
    auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get());
    if (device == nullptr) return;
    const float sine = std::sin(static_cast<double>(rotation)), cosine = std::cos(static_cast<double>(rotation));
    const float width = right - left, height = bottom - top, center_x = (left + right) * 0.5f - 0.5f, center_y = (top + bottom) * 0.5f - 0.5f;
    auto vertices = spriteQuad(part, -width * 0.5f, -height * 0.5f, width * 0.5f, height * 0.5f, color);
    for (auto& vertex : vertices) {
        const float local_x = vertex.x, local_y = vertex.y;
        vertex.x = center_x + local_x * cosine - local_y * sine;
        vertex.y = center_y + local_x * sine + local_y * cosine;
    }
    g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, g_sfera_textures.resource(part.texture));
    (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2u, vertices.data(), sizeof(SferaScreenVertex)));
}

void SphereUI::UiSprite::draw(float left, float top, float right, float bottom, std::uint32_t color, float rotation) const {
    if (rotation == 0.0f) drawParts(left, top, right, bottom, color, false);
    else drawRotated(left, top, right, bottom, color, rotation);
}

void SphereUI::UiSprite::drawNatural(float left, float top, std::uint32_t color) const {
    drawParts(left, top, left + width, top + height, color, true);
}

std::string SphereUI::InterfaceManager::localizedPath(std::string_view filename) {
    std::string resolved(filename);
    const auto& suffix = g_sfera_font_runtime.language_suffix;
    if (!resolved.empty() && !suffix.empty()) {
        const auto extension = resolved.rfind('.');
        resolved.insert(extension == std::string::npos ? resolved.size() : extension, suffix);
    }
    return resolved;
}

std::shared_ptr<const SphereUI::UiSprite> SphereUI::InterfaceManager::sharedSprite(std::string_view name) {
    if (name.empty()) return {};
    const auto found = std::find_if(sprites.begin(), sprites.end(), [name](const auto& sprite) {
        return SferaText::asciiEqual(sprite->name, name);
    });
    return found == sprites.end() ? nullptr : *found;
}

std::shared_ptr<const SphereUI::UiSprite> SphereUI::InterfaceManager::acquireSprite(std::string_view name) {
    if (name.empty()) return {};
    if (auto sprite = sharedSprite(name)) return sprite;
    if (g_sfera_textures.find(name) == -1) return {};
    auto sprite = std::make_shared<UiSprite>();
    sprite->setImage(name);
    return sprite;
}

void SphereUI::InterfaceManager::loadSprites(const std::string& filename) {
    SferaSimpleParser parser{};
    parser.load(filename);
    parser.setBlockRange(nullptr);
    SferaParserRange range{};
    std::vector<std::shared_ptr<const UiSprite>> replacement;
    while (parser.nextBlock("sprite", &range)) {
        auto sprite = std::make_shared<UiSprite>();
        sprite->loadUi(filename, parser, range);
        replacement.push_back(std::move(sprite));
    }
    sprites = std::move(replacement);
}

void SphereUI::InterfaceManager::clearSprites() {
    sprites.clear();
}

bool SphereUI::InterfaceManager::loadWindowTemplates(const std::string& filename) {
    SferaSimpleParser parser{};
    parser.load(filename);
    parser.setBlockRange(nullptr);
    SferaParserRange range{};
    while (parser.nextBlock("windowUI", &range)) {
        auto window = Runtime::makeControl(SphereUI::UiControlKind::window);
        if (window == nullptr) throw std::bad_alloc();
        if (!window->loadUi(filename, parser, range)) continue;
        if (window->getResourceName().empty()) {
            const auto message = std::string("Window name is missing in ") + filename + " at lines " + std::to_string(range.begin) + "-" + std::to_string(range.end);
            CSphereError error;
            error.write(message);
        }
        window_templates.push_back(std::move(window));

    }
    return true;
}

SphereUI::Window* SphereUI::InterfaceManager::templateWindow(std::string_view name) const {
    if (name.empty()) return nullptr;
    const auto found = std::find_if(window_templates.begin(), window_templates.end(), [name](const auto& window) { return window != nullptr && SferaText::asciiEqual(window->getResourceName(), name); });
    return found == window_templates.end() ? nullptr : found->get();
}

void SphereUI::InterfaceManager::clearWindowTemplates() {
    window_templates.clear();
}

void SphereUI::InterfaceManager::loadHyperTexts() {
    const std::string suffix = std::string(g_sfera_font_runtime.language_suffix) + ".hts";
    std::error_code error;
    for (std::filesystem::directory_iterator entry("Language", error), end; !error && entry != end; entry.increment(error)) {
        if (entry->is_directory(error)) continue;
        const auto basename = entry->path().filename().string();
        if (basename.size() < suffix.size() || !SferaText::asciiEqual(std::string_view(basename).substr(basename.size() - suffix.size()), suffix)) continue;
        auto document = std::make_unique<HyperTextDocument>();
        if (!document->load(entry->path().string())) continue;
        auto name = entry->path().string();
        if (!g_sfera_font_runtime.language_suffix.empty()) if (const auto language = name.rfind('_'); language != std::string::npos) name.replace(language, std::string::npos, ".hts");
        document->setName(name);
        hypertext_documents.push_back(std::move(document));
    }
}

SphereUI::HyperTextDocument* SphereUI::InterfaceManager::findHyperText(std::string_view name) const {
    if (name.empty()) return nullptr;
    const auto found = std::find_if(hypertext_documents.begin(), hypertext_documents.end(), [name](const auto& document) { return document != nullptr && SferaText::asciiEqual(document->name, name); });
    return found == hypertext_documents.end() ? nullptr : found->get();
}

void SphereUI::InterfaceManager::clearHyperTexts() {
    hypertext_documents.clear();
}

bool SphereUI::InterfaceManager::loadLocalizedStrings() {
    localized_strings.push_back({"null", "NULL"});
    SferaSimpleParser parser{};
    parser.load(localizedPath("Language\\strings.ui"));
    SferaParserRange range{};
    if (!parser.findBlock("stringsUI", &range, nullptr, 1)) return true;
    parser.setScanRange(&range);
    while (parser.nextValue("string")) {
        std::string key, value;
        if (parser.readString(0u, key) && parser.readQuotedString(1u, value)) localized_strings.push_back({key, value});
    }
    return true;
}

std::string_view SphereUI::InterfaceManager::localizedValue(std::string_view key) const {
    const auto found = std::find_if(localized_strings.begin(), localized_strings.end(), [key](const LocalizedTextEntry& entry) { return SferaText::asciiEqual(entry.key, key); });
    if (found != localized_strings.end()) return found->value;
    if (!localized_strings.empty()) return localized_strings.front().value;
    return {};
}

std::string_view SphereUI::InterfaceManager::localizedText(std::string_view key) const {
    return localized_strings.empty() ? key : localizedValue(key);
}

void SphereUI::InterfaceManager::clearLocalizedStrings() {
    localized_strings.clear();
}

SphereUI::SavedWindowPosition* SphereUI::InterfaceManager::savedPosition(std::string_view name, bool create) {
    if (name.empty()) return nullptr;
    const auto found = std::find_if(saved_positions.begin(), saved_positions.end(), [name](const SavedWindowPosition& position) { return position.name == name; });
    if (found != saved_positions.end()) return &*found;
    return create ? &saved_positions.emplace_back(SavedWindowPosition{std::string(name)}) : nullptr;
}

bool SphereUI::InterfaceManager::findSavedPosition(std::string_view name, SferaCursorPosition& position) {
    const auto* saved = savedPosition(name, false);
    if (saved == nullptr) return false;
    position = {saved->x, saved->y};
    return true;
}

void SphereUI::InterfaceManager::saveWindowPosition(Window& window) {
    auto* saved = savedPosition(window.getName(), true);
    if (saved != nullptr) window.getAbsolutePosition(saved->x, saved->y);
}

std::size_t SphereUI::InterfaceManager::savedPositionsSize() const {
    if (saved_positions.empty()) return 0u;
    std::size_t size = 4u;
    for (const auto& position : saved_positions) {
        if (size > std::numeric_limits<std::size_t>::max() - 9u || position.name.size() > std::numeric_limits<std::size_t>::max() - 9u - size) throw std::length_error("Saved window positions exceed the native buffer size limit");
        size += position.name.size() + 9u;
    }
    return size;
}

void SphereUI::InterfaceManager::writeSavedPositions(std::span<std::byte> destination) const {
    if (destination.empty()) return;
    if (destination.size() < std::max<std::size_t>(4u, savedPositionsSize())) throw std::length_error("Saved window positions do not fit in the destination");
    std::memcpy(destination.data(), "UIV1", 4u);
    destination = destination.subspan(4u);
    for (const auto& position : saved_positions) {
        std::memcpy(destination.data(), position.name.c_str(), position.name.size() + 1u);
        destination = destination.subspan(position.name.size() + 1u);
        const float coordinates[] = {static_cast<float>(static_cast<double>(position.x) / g_sfera_graphics_runtime.display_width), static_cast<float>(static_cast<double>(position.y) / g_sfera_graphics_runtime.display_height)};
        std::memcpy(destination.data(), coordinates, sizeof(coordinates));
        destination = destination.subspan(sizeof(coordinates));
    }
}

void SphereUI::InterfaceManager::readSavedPositions(std::span<const std::byte> source) {
    saved_positions.clear();
    if (source.size() < 4u || std::memcmp(source.data(), "UIV1", 4u) != 0) return;
    source = source.subspan(4u);
    while (!source.empty()) {
        const auto end = std::find(source.begin(), source.end(), std::byte{});
        if (end == source.end()) return;
        const std::size_t name_size = end - source.begin();
        if (source.size() - name_size - 1u < sizeof(float) * 2u) return;
        SavedWindowPosition position{std::string(SferaText::fromBytes(source.first(name_size)))};
        source = source.subspan(name_size + 1u);
        float coordinates[2]{};
        std::memcpy(coordinates, source.data(), sizeof(coordinates));
        source = source.subspan(sizeof(coordinates));
        const double x = static_cast<double>(coordinates[0]) * g_sfera_graphics_runtime.display_width;
        const double y = static_cast<double>(coordinates[1]) * g_sfera_graphics_runtime.display_height;
        if (!std::isfinite(x) || !std::isfinite(y) || x < std::numeric_limits<int>::min() || x > std::numeric_limits<int>::max() || y < std::numeric_limits<int>::min() || y > std::numeric_limits<int>::max()) return;
        position.x = x;
        position.y = y;
        saved_positions.push_back(std::move(position));
    }
}

namespace {
    using SphereUI::HyperDocumentNode;
    using SphereUI::HyperTextCommand;
    using SphereUI::HyperTextImageAlignment;
    struct HyperDocumentFragment {
        HyperDocumentNode node{};
        std::string text;
    };
    struct HyperDocumentRow {
        std::vector<HyperDocumentFragment> fragments;
        int width = 0;
        int height = 0;
        int baseline = 0;
        std::uint32_t initial_color = D3DCOLOR_XRGB(255, 255, 255);
        bool paragraph_end = false;
    };
    std::string_view hyperTrim(std::string_view text) {
        const auto first = text.find_first_not_of(" \t\r\n");
        if (first == std::string_view::npos) return {};
        const auto last = text.find_last_not_of(" \t\r\n");
        return text.substr(first, last - first + 1u);
    }

    bool hyperEquals(std::string_view text, std::string_view expected) {
        return SferaText::asciiEqual(text, expected);
    }

    std::string hyperUnescape(std::string_view text) {
        std::string result;
        result.reserve(text.size());
        for (std::size_t index = 0u; index < text.size(); ++index) {
            auto character = text[index];
            if (character == '\\') {
                if (++index == text.size()) break;
                character = text[index];
                if (character == '[') character = '<';
                else if (character == ']') character = '>';
            }
            result += character;
        }
        return result;
    }

    bool hyperLinkParameters(std::string_view parameters, std::string& target, std::uint32_t& kind) {
        auto value = hyperTrim(parameters);
        if (value.empty() || value.front() != '=') return false;
        value = hyperTrim(value.substr(1u));
        if (value.size() < 2u || value.front() != '"') return false;
        std::size_t end = 1u;
        for (; end < value.size(); ++end) {
            if (value[end] == '\\' && end + 1u < value.size()) ++end;
            else if (value[end] == '"') break;
        }
        if (end == value.size()) return false;
        value = value.substr(1u, end - 1u);
        target.assign(value);
        const auto colon = value.find(':');
        const auto scheme = value.substr(0u, colon);
        kind = hyperEquals(scheme, "hts") ? 0u : hyperEquals(scheme, "item") ? 1u : hyperEquals(scheme, "player") ? 2u : hyperEquals(scheme, "mailto") ? 3u : 4u;
        if (kind == 1u || kind == 2u) target = hyperUnescape(target);
        return true;
    }

    SphereUI::TextExtent hyperTextExtent(std::string_view text, int font) {
        auto result = SphereUI::InterfaceRenderer::measureText(text, font, true);
        if (text.empty()) result.width = 0;
        else if (font < 2u) result.width = std::max(0, result.width - 2);
        return result;
    }

    std::size_t hyperWordEnd(std::string_view text, std::size_t first, bool controls = false) {
        const auto separator = [controls](auto character) {
            return character == ' ' || (controls && (character == '\t' || character == '\r' || character == '\n'));
        };
        auto end = first;
        while (end < text.size() && separator(text[end])) ++end;
        while (end < text.size() && !separator(text[end])) ++end;
        return end;
    }

}

SphereUI::HyperTextCommand SphereUI::HyperTextParser::command(std::string_view name) {
    if (hyperEquals(name, "br")) return HyperTextCommand::lineBreak;
    if (hyperEquals(name, "cl")) return HyperTextCommand::color;
    if (hyperEquals(name, "l")) return HyperTextCommand::linkStart;
    if (hyperEquals(name, "/l") || hyperEquals(name, "\\l")) return HyperTextCommand::linkEnd;
    if (hyperEquals(name, "sp")) return HyperTextCommand::preserveSpaces;
    if (hyperEquals(name, "tab")) return HyperTextCommand::tab;
    if (hyperEquals(name, "img")) return HyperTextCommand::image;
    if (hyperEquals(name, "t")) return HyperTextCommand::tooltipStart;
    if (hyperEquals(name, "/t") || hyperEquals(name, "\\t")) return HyperTextCommand::tooltipEnd;
    return HyperTextCommand::unknown;
}

bool SphereUI::HyperTextParser::parseCommand(std::string_view tag, HyperDocumentNode& node, std::string& argument) {
    const auto equals = tag.find('=');
    std::string name;
    for (const auto character : hyperTrim(tag.substr(0, equals))) if (character != ' ') name += character;
    node.command = command(name);
    if (node.command == HyperTextCommand::unknown) return false;
    auto value = equals == std::string_view::npos ? std::string_view{} : hyperTrim(tag.substr(equals + 1));
    if (!value.empty() && value.front() == '"') {
        value.remove_prefix(1);
        value = value.substr(0, value.find('"'));
    }
    argument.assign(value);
    if (node.command == HyperTextCommand::color) node.color = static_cast<std::uint32_t>(std::strtoul(argument.c_str(), nullptr, 16)) | D3DCOLOR_XRGB(0, 0, 0);
    else if (node.command == HyperTextCommand::image) parseImage(argument, node);
    return true;
}

void SphereUI::HyperTextParser::parseImage(std::string_view argument, HyperDocumentNode& node) {
    std::vector<std::string> fields;
    while (!argument.empty()) {
        const auto comma = argument.find(',');
        const auto field = hyperTrim(argument.substr(0, comma));
        if (!field.empty()) fields.emplace_back(field);
        if (comma == std::string_view::npos) break;
        argument.remove_prefix(comma + 1);
    }
    if (fields.empty()) return;
    node.sprite = g_sfera_interface.acquireSprite(fields.front());
    if (node.sprite == nullptr) return;
    if (fields.size() > 1 && hyperEquals(fields[1], "BOT")) node.image_alignment = HyperTextImageAlignment::bottom;
    else if (fields.size() > 1 && hyperEquals(fields[1], "MID")) node.image_alignment = HyperTextImageAlignment::middle;
    const auto padding = [&](std::size_t index) { return std::strtol(fields[index].c_str(), nullptr, 10); };
    int right = 0, bottom = 0;
    if (fields.size() == 4 || fields.size() >= 6) {
        node.image_x = padding(2);
        node.image_y = padding(3);
    }
    if (fields.size() >= 6) {
        right = padding(4);
        bottom = padding(5);
    }
    node.image_width = node.sprite->width + node.image_x + right;
    node.image_height = node.sprite->height + node.image_y + bottom;
}

SphereUI::HyperTextDocument::HyperTextDocument(std::string_view text, int width, std::uint32_t format, int font) {
    if (!text.empty()) {
        parse(text);
        layout(width, format, font);
    }
}

void SphereUI::HyperTextDocument::setName(std::string_view value) {
    name = value;
}

bool SphereUI::HyperTextDocument::load(const std::string& filename) {
    SferaSimpleParser parser;
    parser.load(filename);
    SferaParserRange range{};
    const bool found = parser.findBlock("hypertext", &range, nullptr, 1);
    if (found) load(parser, range);
    return found;
}

void SphereUI::HyperTextDocument::load(const SferaSimpleParser& parser, const SferaParserRange& range) {
    std::string input;
    for (auto index = range.begin; index < range.end - 1; ++index) {
        auto line = parser.lineAt(index);
        if (line.data() == nullptr) continue;
        const auto first = line.find_first_not_of(' ');
        if (first != std::string_view::npos) input += line.substr(first);
        input += ' ';
    }
    parse(input);
}

void SphereUI::HyperTextDocument::parse(std::string_view input) {
    std::vector<HyperDocumentNode> parsed(1);
    std::vector<HyperTextRegion> parsed_links, parsed_tooltips;
    input = input.substr(0, input.find('\0'));
    for (std::size_t index = 0; index < input.size();) {
        if (input[index] != '<') {
            if (input[index] != '\n') parsed.back().text += input[index];
            ++index;
            continue;
        }
        const auto end = input.find('>', index + 1);
        if (end == std::string_view::npos) {
            parsed.back().text.append(input.substr(index));
            break;
        }
        HyperDocumentNode node;
        std::string argument;
        if (!HyperTextParser::parseCommand(input.substr(index + 1, end - index - 1), node, argument)) {
            parsed.back().text += input[index++];
            continue;
        }
        if (node.command == HyperTextCommand::linkStart || node.command == HyperTextCommand::tooltipStart) {
            HyperTextRegion region;
            const auto target = node.command == HyperTextCommand::tooltipStart && !argument.empty() && argument.front() == '#' ? g_sfera_interface.localizedText(std::string_view(argument).substr(1)) : std::string_view(argument);
            region.target.assign(target);
            auto& regions = node.command == HyperTextCommand::linkStart ? parsed_links : parsed_tooltips;
            node.region_index = regions.size();
            regions.push_back(std::move(region));
        }
        parsed.push_back(std::move(node));
        index = end + 1;
    }
    nodes = std::move(parsed);
    links = std::move(parsed_links);
    tooltips = std::move(parsed_tooltips);
    lines.clear();
    line_height = 0;
}

std::unique_ptr<SphereUI::HyperTextDocument> SphereUI::HyperTextDocument::clone(int width, std::uint32_t format, int font) const {
    if (nodes.empty()) return nullptr;
    auto document = std::make_unique<HyperTextDocument>(*this);
    document->resetRegions();
    document->layout(width, format, font);
    return document;
}

void SphereUI::HyperTextDocument::layout(int width, std::uint32_t format, int font) {
    width = std::max(width, 1);
    const auto tracking = InterfaceRenderer::tracking(font);
    const auto space = hyperTextExtent(" ", font);
    line_height = std::max(space.height, 1);
    this->font = font;
    std::vector<HyperDocumentFragment> originals;
    for (const auto& node : nodes) originals.push_back({node, node.text});
    std::vector<HyperDocumentRow> rows(1u);
    rows.back().height = line_height;
    const auto new_row = [&](bool paragraph) {
        rows.back().paragraph_end = paragraph;
        rows.emplace_back();
        rows.back().height = line_height;
    };
    for (const auto& original : originals) {
        auto node = original.node;
        if (node.command == HyperTextCommand::lineBreak) new_row(true);
        if (node.command == HyperTextCommand::tab) node.spacing = std::max(space.width, 0) * 4;
        auto& row = rows.back();
        if (node.command == HyperTextCommand::image) {
            row.width += node.image_width;
            row.height = std::max<int>(row.height, node.image_height);
            const auto shift = std::max(0, node.image_height - line_height);
            row.baseline = std::max(row.baseline, node.image_alignment == HyperTextImageAlignment::bottom ? shift : node.image_alignment == HyperTextImageAlignment::middle ? shift / 2 : 0);
        } else if (node.command == HyperTextCommand::tab) row.width += node.spacing;
        row.fragments.push_back({node, {}});
        auto text = std::string_view(original.text);
        std::size_t start = 0u;
        while (start < text.size()) {
            const auto remaining = text.substr(start);
            const auto full_extent = hyperTextExtent(remaining, font);
            if (rows.back().width + full_extent.width <= width) {
                auto& current = rows.back();
                if (current.fragments.empty()) current.fragments.push_back({{}, {}});
                current.fragments.back().text.append(remaining);
                current.width += full_extent.width;
                break;
            }
            const auto end = hyperWordEnd(text, start);
            const auto word = text.substr(start, end - start);
            const auto extent = hyperTextExtent(word, font);
            auto visible = word;
            if (rows.back().width != 0 && rows.back().width + extent.width > width) {
                new_row(false);
                if (start != 0u && !visible.empty() && visible.front() == ' ') {
                    ++start;
                    visible.remove_prefix(1u);
                }
                if (hyperTextExtent(text.substr(start), font).width <= width) continue;
            }
            if (!visible.empty()) {
                auto& current = rows.back();
                if (current.fragments.empty() || current.fragments.back().node.command == HyperTextCommand::horizontalSpace) current.fragments.push_back({{}, {}});
                auto& fragment = current.fragments.back();
                fragment.text.append(visible);
                current.width += hyperTextExtent(visible, font).width + tracking;
            }
            start = end;
        }
    }
    if (originals.empty()) rows.clear();
    for (auto& row : rows) {
        for (auto& fragment : row.fragments) if (!fragment.text.empty()) {
            if (fragment.node.command != HyperTextCommand::preserveSpaces) {
                const auto first = fragment.text.find_first_not_of(' ');
                fragment.text.erase(0u, first == std::string::npos ? fragment.text.size() : first);
            }
            break;
        }
        for (auto fragment = row.fragments.rbegin(); fragment != row.fragments.rend(); ++fragment) if (!fragment->text.empty()) {
            const auto last = fragment->text.find_last_not_of(' ');
            fragment->text.resize(last == std::string::npos ? 0u : last + 1u);
            break;
        }
        row.width = 0;
        for (auto& fragment : row.fragments) {
            fragment.node.width = hyperTextExtent(fragment.text, font).width;
            row.width += fragment.node.width;
            if (fragment.node.command == HyperTextCommand::tab || fragment.node.command == HyperTextCommand::horizontalSpace) row.width += fragment.node.spacing;
            else if (fragment.node.command == HyperTextCommand::image) row.width += fragment.node.image_width;
        }
    }
    std::vector<HyperDocumentRow> final_rows;
    final_rows.reserve(rows.size());
    std::uint32_t color = D3DCOLOR_XRGB(255, 255, 255);
    for (std::size_t index = 0u; index < rows.size(); ++index) {
        auto& row = rows[index];
        HyperDocumentRow result{};
        result.height = row.height;
        result.baseline = row.baseline;
        result.initial_color = color;
        const auto spare = std::max(0, width - row.width);
        if (format == 1u || format == 2u) {
            HyperDocumentNode padding{};
            padding.command = HyperTextCommand::horizontalSpace;
            padding.spacing = format == 1u ? spare : spare / 2;
            result.fragments.push_back({padding, {}});
        }
        std::size_t gaps = 0u;
        if (format == 3u && !row.paragraph_end) for (const auto& fragment : row.fragments) for (std::size_t character = 0u; character < fragment.text.size(); ++character) if (fragment.text[character] == ' ' && character != 0u && fragment.text[character - 1u] != ' ') ++gaps;
        std::size_t used_gaps = 0u;
        int distributed = 0;
        for (auto& fragment : row.fragments) {
            if (fragment.node.command == HyperTextCommand::color) color = fragment.node.color;
            if (gaps == 0u) {
                result.fragments.push_back(std::move(fragment));
                continue;
            }
            std::size_t start = 0u;
            bool command = true;
            while (start < fragment.text.size()) {
                const auto word = fragment.text.find_first_not_of(' ', start);
                auto end = word == std::string::npos ? fragment.text.size() : fragment.text.find(' ', word);
                if (end == std::string::npos) end = fragment.text.size();
                else {
                    while (end < fragment.text.size() && fragment.text[end] == ' ') ++end;
                }
                auto node = command ? fragment.node : HyperDocumentNode{};
                command = false;
                const auto text = fragment.text.substr(start, end - start);
                node.width = hyperTextExtent(text, font).width + (end < fragment.text.size() ? tracking : 0);
                result.fragments.push_back({node, text});
                if (!text.empty() && text.back() == ' ' && text.find_first_not_of(' ') != std::string::npos) {
                    const auto added = ++used_gaps == gaps ? spare - distributed : spare / static_cast<int>(gaps);
                    HyperDocumentNode padding{};
                    padding.command = HyperTextCommand::horizontalSpace;
                    padding.spacing = added;
                    distributed += added;
                    result.fragments.push_back({padding, {}});
                }
                start = end;
            }
            if (command) result.fragments.push_back(std::move(fragment));
        }
        final_rows.push_back(std::move(result));
    }
    std::vector<HyperDocumentLine> replacement;
    replacement.reserve(final_rows.size());
    for (auto& row : final_rows) {
        HyperDocumentLine line;
        line.height = row.height;
        line.baseline = row.baseline;
        line.initial_color = row.initial_color;
        line.nodes.reserve(row.fragments.size());
        for (auto& fragment : row.fragments) {
            fragment.node.text = std::move(fragment.text);
            line.nodes.push_back(std::move(fragment.node));
        }
        replacement.push_back(std::move(line));
    }
    lines = std::move(replacement);
}

bool SphereUI::HyperTextRegion::contains(int x, int y) const {
    if (!visible) return false;
    return std::any_of(rectangles.begin(), rectangles.end(), [=](const UiRect& bounds) { return x >= bounds.left && x < bounds.right && y >= bounds.top && y < bounds.bottom; });
}

void SphereUI::HyperTextRegion::addRectangle(const UiRect& rectangle, const UiRect& clip) {
    const UiRect bounds{std::max(rectangle.left, clip.left), std::max(rectangle.top, clip.top), std::min(rectangle.right, clip.right), std::min(rectangle.bottom, clip.bottom)};
    if (bounds.right <= bounds.left || bounds.bottom <= bounds.top) return;
    rectangles.push_back(bounds);
    visible = true;
}

int SphereUI::HyperTextDocument::totalHeight() const {
    std::int64_t height = 0;
    for (const auto& line : lines) height += line.height;
    return std::clamp<std::int64_t>(height, 0, std::numeric_limits<int>::max());
}

void SphereUI::HyperTextDocument::resetRegions() {
    for (auto* group : {&links, &tooltips}) for (auto& region : *group) {
        region.visible = false;
        region.hovered = false;
        region.rectangles.clear();
    }
}

SphereUI::UiRect SphereUI::HyperTextDocument::linkRectangle(int left, int right, int y, int baseline) const {
    const auto inset = font < 2u ? 2 : 0;
    const auto bottom_inset = font == 0u ? 2 : font == 1u ? 3 : 0;
    return {left, y + baseline + inset, right + inset, y + baseline * 2 + line_height + bottom_inset};
}

void SphereUI::HyperTextDocument::draw(int left, int top, int clip_offset, int clip_height, std::uint32_t alpha) {
    const auto viewport = SphereUI::InterfaceRenderer::viewport();
    const UiRect clip{static_cast<int>(viewport.x), std::max(top, static_cast<int>(viewport.y)), static_cast<int>(viewport.x + viewport.width), std::min(top + std::max(clip_height, 0), static_cast<int>(viewport.y + viewport.height))};
    for (auto* group : {&links, &tooltips}) for (auto& region : *group) {
        region.rectangles.clear();
        region.visible = false;
    }
    const auto opacity = std::min(alpha, 255u);
    auto y = top + clip_offset;
    HyperTextRegion* link = nullptr;
    HyperTextRegion* tooltip = nullptr;
    for (const auto& line : lines) {
        auto x = left, link_left = left, tooltip_left = left;
        auto color = line.initial_color;
        const auto baseline = line.baseline;
        for (const auto& node : line.nodes) {
            if (node.command == HyperTextCommand::color) color = node.color;
            else if (node.command == HyperTextCommand::linkStart) {
                link = node.region_index < links.size() ? &links[node.region_index] : nullptr;
                link_left = x;
            } else if (node.command == HyperTextCommand::linkEnd) {
                if (link != nullptr) link->addRectangle(linkRectangle(link_left, x, y, baseline), clip);
                link = nullptr;
            } else if (node.command == HyperTextCommand::tooltipStart) {
                tooltip = node.region_index < tooltips.size() ? &tooltips[node.region_index] : nullptr;
                tooltip_left = x;
            } else if (node.command == HyperTextCommand::tooltipEnd) {
                if (tooltip != nullptr) tooltip->addRectangle({tooltip_left, y, x, y + line.height}, clip);
                tooltip = nullptr;
            } else if (node.command == HyperTextCommand::horizontalSpace || node.command == HyperTextCommand::tab) {
                x += node.spacing;
                if (link != nullptr && link_left == left) link_left = x;
                if (tooltip != nullptr && tooltip_left == left) tooltip_left = x;
            } else if (node.command == HyperTextCommand::image) {
                if (node.sprite != nullptr && y + line.height > clip.top && y < clip.bottom) node.sprite->drawNatural(static_cast<float>(x + node.image_x), static_cast<float>(y + node.image_y), SferaColor::rgba(255u, 255u, 255u, opacity).argb());
                x += node.image_width;
            }
            if (!node.text.empty() && y + line.height > clip.top && y < clip.bottom) {
                const auto text_color = link == nullptr ? color : link->hovered ? hover_color : link_color;
                SphereUI::InterfaceRenderer::drawText(node.text, x, y + baseline, SferaColor::fromArgb(text_color).withAlpha(opacity).argb(), font, true, clip, alpha == 255u);
            }
            x += node.width;
        }
        if (link != nullptr) link->addRectangle(linkRectangle(link_left, x, y, baseline), clip);
        if (tooltip != nullptr) tooltip->addRectangle({tooltip_left, y, x, y + line.height}, clip);
        y += line.height;
        if (y >= clip.bottom) break;
    }
}

void SphereUI::HyperTextParser::parseElements(std::string_view text, std::vector<HyperTextRun>& elements, std::string& plain) {
    std::vector<HyperTextRun> parsed{};
    std::string output, pending, parameters, target;
    std::uint32_t kind = 4u;
    bool link = false;
    const std::string input(text);
    const auto flush = [&](bool linked) {
        if (pending.empty()) return;
        const auto decoded = hyperUnescape(pending);
        if (!decoded.empty()) {
            if (linked) parsed.push_back({decoded, HyperTextRun::Link{{}, parameters, target, kind}});
            else parsed.push_back({decoded, HyperTextGeometry{}});
            output += decoded;
        }
        pending.clear();
    };
    for (std::size_t index = 0u; index < input.size();) {
        if (input[index] != '<') {
            pending += input[index++];
            continue;
        }
        const auto end = input.find('>', index + 1u);
        if (end == std::string::npos || end == index + 1u) {
            pending.append(input, index, std::string::npos);
            break;
        }
        const auto tag = hyperTrim(std::string_view(input).substr(index + 1u, end - index - 1u));
        const auto name_end = tag.find_first_of(" =\t\r\n");
        const auto name = tag.substr(0u, name_end);
        if (hyperEquals(name, "l")) {
            std::string new_target;
            std::uint32_t new_kind = 4u;
            const auto remainder = name_end == std::string_view::npos ? std::string_view{} : hyperTrim(tag.substr(name_end));
            if (hyperLinkParameters(remainder, new_target, new_kind)) {
                flush(false);
                parameters.assign(remainder);
                target = std::move(new_target);
                kind = new_kind;
                link = true;
            } else flush(false);
        } else if (hyperEquals(name, "/l") || hyperEquals(name, "\\l")) {
            flush(link);
            link = false;
        } else flush(false);
        index = end + 1u;
    }
    if (!link) flush(false);
    elements = std::move(parsed);
    plain = std::move(output);
}

void SphereUI::HyperTextChatListItem::layout(int width, int font) {
    width = std::max(width, 1);
    std::vector<HyperTextRun> output{};
    std::vector<UiIndexRange> replacement_rows{};
    int x = 0;
    std::uint32_t first = 0u;
    const auto wrap = [&](std::string_view separator) {
        if (output.size() > first) replacement_rows.push_back({first, output.size() - 1u});
        output.push_back({std::string(separator), std::monostate{}});
        first = output.size();
        x = 0;
    };
    const auto append = [&](HyperTextRun element) {
        if (auto* geometry = element.geometry()) {
            const auto extent = hyperTextExtent(std::string_view(element.text), font);
            *geometry = {x, 0, extent.width, extent.height};
            x += extent.width;
        }
        output.push_back(std::move(element));
    };
    for (const auto& element : elements) {
        if (element.isWrap()) {
            if (element.text.size() != 0u) wrap(std::string_view(element.text));
            continue;
        }
        if (element.link() != nullptr) {
            const auto extent = hyperTextExtent(std::string_view(element.text), font);
            if (x != 0 && x + extent.width > width) wrap({});
            append(element);
            continue;
        }
        if (!element.isPlain()) continue;
        const std::string_view text(element.text);
        std::string pending;
        const auto flush = [&]() {
            if (!pending.empty()) {
                append({pending, HyperTextGeometry{}});
                pending.clear();
            }
        };
        for (std::size_t position = 0u; position < text.size();) {
            const auto end = hyperWordEnd(text, position, true);
            const auto token = text.substr(position, end - position);
            const auto combined = pending + std::string(token);
            if (x + hyperTextExtent(combined, font).width <= width || (x == 0 && pending.empty())) pending = combined;
            else {
                flush();
                auto visible = token;
                const auto leading = visible.find_first_not_of(" \t\r\n");
                const auto spaces = leading == std::string_view::npos ? visible.size() : leading;
                wrap(visible.substr(0u, spaces));
                visible.remove_prefix(spaces);
                pending.assign(visible);
            }
            position = end;
        }
        flush();
    }
    if (output.size() > first) replacement_rows.push_back({first, output.size() - 1u});
    elements = std::move(output);
    rows = std::move(replacement_rows);
}

SphereUI::InterfaceManager::~InterfaceManager() { shutdown(); }

bool SphereUI::InterfaceManager::prepareResources() {
    if (initialized) return false;
    g_sfera_fonts.initialize();
    InterfaceConfiguration::open("control.cfg");
    g_sfera_interface.cross_enabled = true;
    g_sfera_interface.cross_enabled = InterfaceConfiguration::readInteger("EN_CROSS", g_sfera_interface.cross_enabled) != 0;
    g_sfera_interface.sounds_enabled = InterfaceConfiguration::readInteger("INTFS_SOUNDS", g_sfera_interface.sounds_enabled) != 0;
    if (!cursor) {
        cursor = std::make_unique<SferaInterfaceCursor>();
        cursor->loadTextures();
    }
    g_sfera_fonts.loadConfiguration();
    cursor->setKind(255u);
    setCursorKind(255u, 0, 0);
    setCursorImage(std::nullopt, 0, 0);
    loadLocalizedStrings();
    loadWindowTemplates("Effects\\loadscreen.ui");
    loadSprites("Effects\\sprites.ui");
    return true;
}

void SphereUI::InterfaceManager::finishInitialization() { drag_drop_active = false; initialized = true; }

bool SphereUI::InterfaceManager::shutdown() {
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

void SphereUI::InterfaceManager::clearWindows() {
    help_window = nullptr;
    load_screen = nullptr;
    g_sfera_interface.description_control = nullptr;
    while (!windows.empty()) {
        auto window = std::move(windows.front());
        windows.pop_front();
    }
}

void SphereUI::InterfaceManager::queueEvent(const WindowEvent& event) {
    detail::enqueueWindowEvent(events, event);
}

bool SphereUI::InterfaceManager::pollEvent(WindowEvent& event) {
    if (events.empty()) return false;
    event = events.front();
    events.pop_front();
    return true;
}

SphereUI::Window* SphereUI::InterfaceManager::findWindow(std::string_view name, bool exact) const {
    if (name.empty()) return nullptr;
    const auto found = std::find_if(windows.begin(), windows.end(), [name, exact](const auto& window) { return window != nullptr && (exact ? window->getResourceName() == name : SferaText::asciiEqual(window->getResourceName(), name)); });
    return found == windows.end() ? nullptr : found->get();
}

SphereUI::Window* SphereUI::InterfaceManager::windowUnderCursor() const {
    SferaCursorPosition position{};
    CCursorManager::instance().activeCursor()->getPosition(&position);
    const auto found = std::find_if(windows.rbegin(), windows.rend(), [&position](const auto& window) { return window != nullptr && !window->hidden && !window->hit_transparent && window->containsPoint(position.x, position.y); });
    return found == windows.rend() ? nullptr : found->get();
}

bool SphereUI::InterfaceManager::hasEscapeWindow() const {
    return std::any_of(windows.begin(), windows.end(), [](const auto& window) { return window != nullptr && !window->hidden && (window->behavior_flags & WindowStyle::handleEscape) != 0u; });
}

SphereUI::Window* SphereUI::InterfaceManager::addTopLevelWindow(std::unique_ptr<Window> window) {
    if (!window) return nullptr;
    auto* result = window.get();
    windows.push_back(std::move(window));
    return result;
}

void SphereUI::InterfaceManager::raiseWindow(Window& window) {
    const auto found = std::find_if(windows.begin(), windows.end(), [&window](const auto& owner) { return owner.get() == &window; });
    if (found != windows.end()) windows.splice(windows.end(), windows, found);
}

void SphereUI::InterfaceManager::lowerWindow(Window& window) {
    const auto found = std::find_if(windows.begin(), windows.end(), [&window](const auto& owner) { return owner.get() == &window; });
    if (found != windows.end()) windows.splice(windows.begin(), windows, found);
}

void SphereUI::InterfaceManager::collectCoveredWindows(Window& window) {
    if (!g_sfera_interface.cross_enabled) return;
    UiRect bounds{};
    window.getAbsolutePosition(bounds.left, bounds.top);
    bounds.right = bounds.left + window.width;
    bounds.bottom = bounds.top + window.height;
    const auto area = static_cast<std::int64_t>(window.width) * window.height;
    if (area <= 0) return;
    for (auto current = windows.rbegin(); current != windows.rend(); ++current) {
        Window* other = current->get();
        if (other == nullptr || other == &window || other->hidden || other->isAnimating() || other->close_completed || (other->behavior_flags & WindowStyle::preventOverlap) != 0u) continue;
        UiRect other_bounds{};
        other->getAbsolutePosition(other_bounds.left, other_bounds.top);
        other_bounds.right = other_bounds.left + other->width;
        other_bounds.bottom = other_bounds.top + other->height;
        if (other_bounds.right < bounds.left || bounds.right < other_bounds.left || other_bounds.bottom < bounds.top || bounds.bottom < other_bounds.top) continue;
        const bool contains_window = other_bounds.left < bounds.left && other_bounds.right > bounds.right && other_bounds.top < bounds.top && other_bounds.bottom > bounds.bottom;
        if (contains_window) { window.addModalReference(*other); continue; }
        const bool contained_window = other_bounds.left > bounds.left && other_bounds.right < bounds.right && other_bounds.top > bounds.top && other_bounds.bottom < bounds.bottom;
        int covered_width = other->width;
        int covered_height = other->height;
        if (!contained_window) {
            if (other_bounds.left < bounds.left) covered_width = std::min(bounds.right, other_bounds.right) - bounds.left;
            else if (other_bounds.left > bounds.left) covered_width = bounds.right - other_bounds.left;
            if (other_bounds.top < bounds.top) covered_height = std::min(bounds.bottom, other_bounds.bottom) - bounds.top;
            else if (other_bounds.top > bounds.top) covered_height = bounds.bottom - other_bounds.top;
        }
        const auto covered_area = static_cast<std::int64_t>(covered_width) * covered_height;
        if (static_cast<float>(static_cast<double>(covered_area) / area) > 0.3f) window.addModalReference(*other);
    }
}

SphereUI::Window* SphereUI::InterfaceManager::openWindow(std::string_view name, int x, int y, std::uint32_t flags) {
    if (name.empty()) return nullptr;
    std::string template_name(name);
    if (const auto separator = template_name.rfind(':'); separator != std::string::npos) template_name.resize(separator);
    Window* original = templateWindow(template_name);
    if (original == nullptr) return nullptr;
    auto window = original->clone();
    if (window == nullptr) { InterfaceRenderer::reportError("Cannot clone the requested window template."); return nullptr; }
    window->setName(name);
    if ((flags & explicitPosition) != 0u) window->setPosition(x, y);
    else {
        const SavedWindowPosition* saved = savedPosition(name, false);
        const bool valid_position = saved != nullptr && (saved->x < g_sfera_graphics_runtime.display_width - 15 || saved->y < g_sfera_graphics_runtime.display_height - 15);
        if (valid_position && window->save_last_position && findWindow(name, true) == nullptr) window->setPosition(saved->x, saved->y);
        else {
            if ((flags & centerOnScreen) != 0u) window->alignment_flags = SphereUI::alignCenterX | SphereUI::alignCenterY;
            window->alignToScreen(false);
        }
    }
    if ((flags & preserveVisibility) == 0u) window->hidden = false;
    if (!window->hidden && (flags & skipOpeningAnimation) == 0u) window->startAnimation(SphereUI::WindowAnimation::Phase::Showing);
    window->input_enabled = true;
    collectCoveredWindows(*window);
    for (auto* reference : window->modal_references) if (isRegistered(reference) && !reference->modal_owner) { reference->modal_owner = window.get(); reference->handleMessage(UiMessage::animateVisibility, 1u, 0u); }
    return addTopLevelWindow(std::move(window));
}

void SphereUI::InterfaceManager::closeWindow(Window* window, bool animated) {
    if (window == nullptr) return;
    if (window->control_id != 0u) InterfaceRenderer::reportError("Cannot close a child control through the interface manager.");
    window->beginClose(animated);
}

void SphereUI::InterfaceManager::showHelpPage(std::optional<std::string_view> name) {
    if (!name) { closeWindow(help_window); help_window = nullptr; return; }
    if (findHyperText(*name) == nullptr) return;
    if (help_window == nullptr) {
        help_window = openWindow("help");
        bindEventHandler(help_window, WindowEventHandler::help);
    } else raiseWindow(*help_window);
    if (help_window == nullptr) return;
    auto* control = dynamic_cast<HyperTextCtrl*>(help_window->controlAt(3u));
    if (control == nullptr) return;
    if (control->document != nullptr && SferaText::asciiEqual(control->document->name, *name)) return;
    sendMessage(help_window->controlAt(2u), UiMessage::setEnabled, control->history.size() != 0u ? 1u : 0u, 0u);
    control->queuePage(*name, true);
}

void SphereUI::InterfaceManager::setTooltipText(std::optional<std::string_view> text) {
    if (!text) { if (tooltip != nullptr && !tooltip_disabled) tooltip->reset(); return; }
    if (!tooltip) tooltip = std::make_unique<ToolTipCtrl>();
    if (tooltip == nullptr) return;
    tooltip->setLine(0u, *text);
    SferaCursorPosition position{};
    CCursorManager::instance().activeCursor()->getPosition(&position);
    tooltip->showAt(position.x, position.y);
}

void SphereUI::InterfaceManager::setCursorKind(std::uint32_t kind, int x, int y) {
    if (!cursor) return;
    std::optional<std::string_view> texture;
    if (kind == 64u || kind == 65u) { texture = "curseye"; kind = 64u; }
    else if (kind == 66u || kind == 67u) texture = "cursman";
    else if (kind != 255u) return;
    else { x = 0; y = 0; }
    cursor->setImage(0u, texture, x, y);
    g_sfera_interface.cursor_kind = kind;
}

void SphereUI::InterfaceManager::setCursorImage(std::optional<std::string_view> texture, int x, int y) {
    if (!cursor) return;
    if (!texture) { x = 0; y = 0; }
    cursor->setImage(1u, texture, x, y);
    cursor_name = texture.value_or(std::string_view{});
}

std::uint32_t SphereUI::InterfaceManager::sendMessage(Window* window, SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) {
    if (message == UiMessage::beginDragDrop) { drag_drop_active = true; return 1u; }
    if (message < UiMessage::close) InterfaceRenderer::reportError("Unknown interface manager message.");
    return isRegistered(window) ? window->handleMessage(message, first, second) : 0u;
}

void SphereUI::InterfaceManager::draw() {
    const auto saved_clip = SphereUI::InterfaceRenderer::clip_rectangle;
    InterfaceRenderer::setSpriteRenderMode(1u);
    try {
        if (g_sfera_interface.ui_enabled) {
            for (const auto& owner : windows) if (auto* window = owner.get()) window->draw();
            for (const auto& owner : windows) if (auto* window = owner.get()) window->drawToolTips();
        }
        if (tooltip != nullptr && !tooltip_disabled) tooltip->draw();
        if (cursor && cursor->system_visible) {
            SphereUI::InterfaceRenderer::clip_rectangle.left = 0;
            SphereUI::InterfaceRenderer::clip_rectangle.top = 0;
            SphereUI::InterfaceRenderer::clip_rectangle.right = g_sfera_graphics_runtime.display_width;
            SphereUI::InterfaceRenderer::clip_rectangle.bottom = g_sfera_graphics_runtime.display_height;
            CCursor* active = CCursorManager::instance().activeCursor();
            SferaCursorPosition position{};
            active->getPosition(&position);
            if (active->isInsideViewport()) cursor->draw(static_cast<float>(position.x), static_cast<float>(position.y));
        }
    } catch (...) { SphereUI::InterfaceRenderer::clip_rectangle = saved_clip; InterfaceRenderer::setSpriteRenderMode(0u); throw; }
    SphereUI::InterfaceRenderer::clip_rectangle = saved_clip;
    InterfaceRenderer::setSpriteRenderMode(0u);
}

void SphereUI::InterfaceManager::showLoadingScreen(bool visible, int width, int height, bool english) {
    if (!visible) { closeWindow(load_screen); load_screen = nullptr; return; }
    if (load_screen == nullptr) {
        load_screen = openWindow("loadscreen", 0, 0, skipOpeningAnimation);
        if (load_screen == nullptr) return;
        lowerWindow(*load_screen);
    }
    load_screen->setPosition(0, 0);
    load_screen->handleMessage(UiMessage::setSize, 0u, 0u);
    const int image_width = std::min(width, 1024);
    const int image_height = std::min(height, 768);
    const int left = width > 1024 ? (width - 1024) / 2 : 0;
    const int top = height > 768 ? (height - 768) / 2 : 0;
    sendMessage(load_screen->controlAt(2u), UiMessage::setPosition, left, top);
    sendMessage(load_screen->controlAt(2u), UiMessage::setSize, image_width, image_height);
    sendMessage(load_screen->controlAt(1u), UiMessage::setPosition, 0u, 0u);
    sendMessage(load_screen->controlAt(1u), UiMessage::setSize, width, height);
    if (auto* image = dynamic_cast<ImageCtrl*>(load_screen->controlAt(2u))) { ImageDescription description{}; description.name = english ? "english_sphere1" : "russian_sphere1"; image->setImage(&description); }
    const int progress_left = left + static_cast<int>(image_width * 0.3701171875);
    const int progress_top = top + static_cast<int>(image_height * 0.83203125);
    const int progress_width = image_width * 0.2490234375;
    const int progress_height = image_height * 0.0247395833;
    for (const auto index : {3u, 4u}) {
        sendMessage(load_screen->controlAt(index), UiMessage::setPosition, progress_left, progress_top);
        sendMessage(load_screen->controlAt(index), UiMessage::setSize, progress_width, progress_height);
    }
    sendMessage(load_screen->controlAt(3u), UiMessage::setProgressValue, 100u, 0u);
    sendMessage(load_screen->controlAt(5u), UiMessage::setPosition, left + 375, top + 520);
    sendMessage(load_screen->controlAt(5u), UiMessage::setSize, 620u, 90u);
}

void SphereUI::InterfaceManager::setLoadingProgress(int percent) {
    if (load_screen != nullptr) sendMessage(load_screen->controlAt(3u), UiMessage::setProgressValue, static_cast<std::uint32_t>(std::clamp(percent, 0, 100)), 0u);
}

void SphereUI::InterfaceManager::update(std::uint8_t key, std::uint8_t character, std::uint32_t mouse_buttons, int wheel_delta) {
    const auto& keyboard = g_sfera_direct_input_runtime.keyboard_state;
    if (key == VK_F12 && keyboard[DIK_LCONTROL] != 0u) g_sfera_interface.ui_enabled = !g_sfera_interface.ui_enabled;
    else if (key == VK_F1) showHelpPage("Language\\helpindex.hts");
    if (!g_sfera_interface.ui_enabled) return;
    if (g_sfera_direct_input_runtime.binding_capture != 0u && g_sfera_direct_input_runtime.binding_key != 0u && capture_control_binding) {
        const WindowEvent event{nullptr, 0u, UiMessage::controlBindingCaptured, g_sfera_direct_input_runtime.binding_key, 0u};
        Runtime::invokeEventHandler(WindowEventHandler::control_options, nullptr, event);
        g_sfera_direct_input_runtime.binding_key = 0u;
    }
    if (auto* description = g_sfera_interface.description_control) description->update();
    SferaCursorPosition position{};
    CCursorManager::instance().activeCursor()->getPosition(&position);
    WindowInput input{position.x, position.y, wheel_delta, 0u, mouse_buttons, key, character, 0u};
    const auto previous_buttons = g_sfera_interface.previous_input_modifiers;
    const auto changed_buttons = mouse_buttons ^ previous_buttons;
    input.mouse_flags = (changed_buttons & mouse_buttons & 3u) | ((changed_buttons & previous_buttons & 3u) << 2u);
    g_sfera_interface.previous_input_modifiers = mouse_buttons;
    if (keyboard[DIK_LSHIFT] != 0u) input.key_modifiers |= 1u;
    if (keyboard[DIK_RSHIFT] != 0u) input.key_modifiers |= 2u;
    if (keyboard[DIK_LCONTROL] != 0u) input.key_modifiers |= 4u;
    if (g_sfera_direct_input_runtime.modifier_08 != 0u) input.key_modifiers |= 8u;
    if (keyboard[DIK_LMENU] != 0u) input.key_modifiers |= 16u;
    if (g_sfera_direct_input_runtime.modifier_20 != 0u) input.key_modifiers |= 32u;
    std::vector<std::pair<Window*, std::uint64_t>> closing_candidates;
    closing_candidates.reserve(windows.size());
    for (const auto& window : windows) closing_candidates.emplace_back(window.get(), window->registration_id);
    for (const auto& [window, identity] : closing_candidates) {
        if (!isRegistered(window, identity) || !window->close_completed) continue;
        std::vector<Window*> references;
        references = window->modal_references;
        for (Window* reference : references) {
            if (!isRegistered(reference) || reference->isAnimating() || std::find_if(windows.begin(), windows.end(), [reference](const auto& owner) { return owner.get() == reference; }) == windows.end()) continue;
            reference->handleMessage(UiMessage::endModal, 0u, 0u);
        }
        if (!isRegistered(window, identity)) continue;
        if (window->control_id != 0u) { InterfaceRenderer::reportError("Cannot destroy a child control through the interface manager."); continue; }
        const auto owned = std::find_if(windows.begin(), windows.end(), [window](const auto& owner) { return owner.get() == window; });
        if (owned != windows.end()) {
            auto removed = std::move(*owned);
            windows.erase(owned);
        }
    }
    Window* target = nullptr;
    for (auto window = windows.rbegin(); window != windows.rend(); ++window) if (isRegistered(window->get()) && (*window)->hidden == 0u && ((*window)->dragging != 0u || (*window)->containsPoint(position.x, position.y))) {
        target = window->get();
        break;
    }
    if (auto* description = g_sfera_interface.description_control; description != nullptr && !description->hidden) {
        for (auto window = windows.rbegin(); window != windows.rend(); ++window) if (isRegistered(window->get()) && (*window)->dragging != 0u) {
            target = window->get();
            break;
        }
    }
    if ((input.mouse_flags & MouseInput::leftPress) != 0u && target != nullptr && target->can_go_top && !target->hit_transparent && !target->hidden) raiseWindow(*target);
    if (auto* description = g_sfera_interface.description_control; description != nullptr && !description->hidden) raiseWindow(*description);
    bool completed_drag = false;
    if (drag_drop_active) {
        for (const auto& owner : windows) if (auto* window = owner.get()) {
            if (!isRegistered(window) || !window->can_drag_drop) continue;
            const bool entered = window == target;
            if (entered == window->drag_over) continue;
            window->queueEvent({window, 0u, entered ? UiMessage::dragEnter : UiMessage::dragLeave, 0u, 0u});
            window->drag_over = entered;
        }
        if ((input.mouse_flags & MouseInput::leftRelease) != 0u) {
            const bool accepted = isRegistered(target) && target->can_drag_drop && target->hitTest(position.x, position.y);
            if (!accepted) queueEvent({nullptr, 0u, UiMessage::dropToScene, static_cast<std::uint32_t>(position.x), static_cast<std::uint32_t>(position.y)});
            for (const auto& owner : windows) if (auto* window = owner.get()) {
                if (!isRegistered(window) || !window->drag_over) continue;
                window->queueEvent({window, 0u, UiMessage::dragLeave, 0u, 0u});
                window->drag_over = false;
            }
            completed_drag = true;
        }
    }
    if (input.key_code == VK_ESCAPE) {
        const auto window = std::find_if(windows.rbegin(), windows.rend(), [this](const auto& candidate) { return isRegistered(candidate.get()) && !candidate->hidden && (candidate->behavior_flags & WindowStyle::handleEscape) != 0u; });
        if (window != windows.rend()) (*window)->queueEvent({window->get(), 0u, UiMessage::close, 0u, 0u});
    }
    Runtime::setTextInputActive(false);
    input.mouse_x = input.mouse_y = 0;
    std::vector<std::pair<Window*, std::uint64_t>> input_order;
    input_order.reserve(windows.size());
    for (auto window = windows.rbegin(); window != windows.rend(); ++window) input_order.emplace_back(window->get(), (*window)->registration_id);
    for (const auto& [window, identity] : input_order) {
        if (!isRegistered(window, identity)) continue;
        if (window == target) { input.mouse_x = position.x; input.mouse_y = position.y; }
        if (window->input_enabled && !window->hidden) window->handleInput(input);
        input.mouse_x = input.mouse_y = 0;
        if (!isRegistered(window, identity)) continue;
        if (window->isAnimating()) window->updateAnimation();
        if (isRegistered(window, identity) && hasEventHandler(window)) window->processEvents();
    }
    if (tooltip != nullptr && !tooltip_disabled) tooltip->handleInput(input);
    if (completed_drag) drag_drop_active = false;
}

void SphereUI::InterfaceManager::registerWindow(Window& window) {
    if (registered_windows.contains(&window)) return;
    if (next_registration_id == 0u) throw std::overflow_error("UI registration identity exhausted");
    registered_windows.insert(&window);
    window.registration_id = next_registration_id++;
}
void SphereUI::InterfaceManager::unregisterWindow(Window& window) {
    unbindEventHandler(&window);
    std::erase_if(events, [&window](const WindowEvent& event) { return event.source == &window; });
    for (auto* observer : registered_windows) {
        std::erase(observer->modal_references, &window);
        std::erase_if(observer->events, [&window](const WindowEvent& event) { return event.source == &window; });
        if (observer->parent == &window) observer->parent = nullptr;
        if (observer->modal_owner == &window) observer->modal_owner = nullptr;
        if (observer->overlay == &window) observer->overlay = nullptr;
        if (observer->resource_parent == &window) observer->resource_parent = nullptr;
        if (auto* description = dynamic_cast<CDescriptionWindow*>(observer); description && description != &window) {
            if (description->displayed_source == &window) description->displayed_source = nullptr;
            if (description->pending_source == &window) description->pending_source = nullptr;
        }
    }

    registered_windows.erase(&window);
    if (help_window == &window) help_window = nullptr;
    if (load_screen == &window) load_screen = nullptr;
    if (g_sfera_interface.description_control == &window) g_sfera_interface.description_control = nullptr;
}
bool SphereUI::InterfaceManager::isRegistered(const Window* window) const { return window != nullptr && registered_windows.contains(const_cast<Window*>(window)); }
bool SphereUI::InterfaceManager::isRegistered(const Window* window, std::uint64_t registration_id) const {
    return isRegistered(window) && window->registration_id == registration_id;
}
void SphereUI::InterfaceManager::bindEventHandler(Window* window, WindowEventHandler handler) {
    if (window == nullptr) return;
    if (handler == WindowEventHandler::none) event_handlers.erase(window);
    else event_handlers.insert_or_assign(window, handler);
}
void SphereUI::InterfaceManager::copyEventHandler(Window* destination, const Window* source) {
    if (destination == nullptr || destination == source) return;
    const auto binding = event_handlers.find(source);
    bindEventHandler(destination, binding == event_handlers.end() ? WindowEventHandler::none : binding->second);
}
bool SphereUI::InterfaceManager::hasEventHandler(const Window* window) const { return window != nullptr && event_handlers.contains(window); }
void SphereUI::InterfaceManager::dispatchEvent(Window* window, const WindowEvent& event) {
    const auto binding = event_handlers.find(window);
    Runtime::invokeEventHandler(binding == event_handlers.end() ? WindowEventHandler::none : binding->second, window, event);
}
void SphereUI::InterfaceManager::unbindEventHandler(const void* window) { event_handlers.erase(static_cast<const Window*>(window)); }

void SphereUI::UiSprite::setDescription(const ImageDescription& description) {
    name = description.name;
    resetParts(1u);
    const auto flags = description.image.flags;
    const auto* rectangle = (flags & 2u) != 0u ? &description.image.rectangle : nullptr;
    const std::string_view texture_name = (flags & 4u) != 0u ? description.image.texture_name : description.name;
    auto& part = parts.front();
    part.setTexture(texture_name, rectangle, rectangle);
    width = (flags & 1u) != 0u ? description.image.width : part.rectangle.right;
    height = (flags & 1u) != 0u ? description.image.height : part.rectangle.bottom;
}

namespace SphereUI::detail {

    int addCoordinate(int left, int right);
    int subtractCoordinate(int left, int right);
}

std::optional<std::string_view> SphereUI::InterfaceConfiguration::value(std::string_view key) {
    const auto offset = SferaText::configValueOffset(text_, key);
    if (offset == std::string::npos) return std::nullopt;
    return std::string_view(text_).substr(offset);
}

void SphereUI::InterfaceConfiguration::open(const std::string& filename) {
    close();
    if (filename.empty()) return;
    filename_ = filename;
    auto bytes = SferaFileManager::readBounded(filename_, SferaConfigTextRuntime::text_capacity);
    if (!bytes || bytes->empty()) return;
    try {
        if (bytes->size() >= 14 && std::memcmp(bytes->data(), "SPHR", 4) == 0) {
            const auto key = (*bytes)[8];
            for (const auto offset : {9u, 17u, 20u}) if (offset < bytes->size()) (*bytes)[offset] ^= key;
            auto decoded = SferaZStream32::decompressUiConfig(std::span<const std::uint8_t>(*bytes).subspan(8), SferaConfigTextRuntime::text_capacity - 1);
            text_.assign(SferaText::fromBytes(decoded));
        } else text_.assign(SferaText::fromBytes(*bytes));
    } catch (const std::exception&) { close(); }
}

int SphereUI::InterfaceConfiguration::readInteger(std::string_view key, int fallback) {
    const auto text = value(key);
    int result = fallback;
    return text && SferaText::readNumber(*text, result) ? result : fallback;
}

void SphereUI::InterfaceConfiguration::writeInteger(std::string_view key, int value) {
    if (!SferaText::replaceConfigValue(text_, key, std::to_string(value), false, SferaConfigTextRuntime::text_capacity))
        throw std::length_error("UI configuration too large");
}

void SphereUI::InterfaceConfiguration::save() {
    if (!filename_.empty()) SferaFileManager::writeFile(filename_, text_.data(), text_.size());
}

namespace {
    bool interfaceDepth(float depth, float& z, float& reciprocal);

    std::uint8_t uiAtlasGlyph(std::uint8_t character) {
        return g_sfera_font_runtime.glyphs[character].defined != 0u ? character : static_cast<std::uint8_t>('|');
    }

    void uiFontQuad(SferaScreenVertex* vertices, float left, float top, float right, float bottom, std::uint32_t color, float u0, float v0, float u1, float v1, bool clockwise) {
        for (std::uint32_t index = 0u; index < 4u; ++index) {
            const auto corner = clockwise || index < 2u ? index : 5u - index;
            const bool on_right = corner == 1u || corner == 2u, on_bottom = corner >= 2u;
            vertices[index] = {on_right ? right : left, on_bottom ? bottom : top, 0.0f, 1.0f, color, clockwise ? vertices[index].specular : 0u, on_right ? u1 : u0, on_bottom ? v1 : v0};
        }
    }

    void uiFontTriangles(std::uint16_t* indices, std::uint32_t first, bool clockwise) {
        constexpr std::uint16_t atlas[] = {0u, 1u, 2u, 0u, 2u, 3u};
        constexpr std::uint16_t face[] = {2u, 0u, 3u, 1u, 3u, 0u};
        const auto* order = clockwise ? atlas : face;
        for (std::uint32_t index = 0u; index < 6u; ++index) indices[index] = first + order[index];
    }

    void uiSubmitFont(const SferaScreenVertex* vertices, std::uint32_t vertex_count, const std::uint16_t* indices, std::uint32_t index_count) {
        if (vertex_count == 0u) return;
        if (auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get())) (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0u, vertex_count, index_count / 3u, indices, D3DFMT_INDEX16, vertices, sizeof(SferaScreenVertex)));
    }

    void uiDrawAtlasText(std::string_view text, int x, int top, std::uint32_t color, int font, int scale, const SphereUI::UiRect& clip, float depth, bool configureAlpha) {
        auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get());
        if (device == nullptr) return;
        const int size = static_cast<std::uint32_t>(scale) * 30u;
        if (top > clip.bottom || SphereUI::detail::addCoordinate(top, size) <= clip.top) return;
        if (configureAlpha && SferaColor::fromArgb(color).alpha() != 255) g_sfera_graphics_runtime.d3d_runtime->setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
        float z, reciprocal;
        if (!interfaceDepth(depth, z, reciprocal)) return;
        IDirect3DBaseTexture9* texture = nullptr;
        std::uint32_t vertex_count = 0u, index_count = 0u;
        const auto flush = [&]() {
            if (vertex_count == 0u) return;
            (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, texture));
            (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE));
            (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1));
            (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetRenderState(D3DRS_LIGHTING, FALSE));
            (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetRenderState(D3DRS_CLIPPING, FALSE));
            uiSubmitFont(SphereUI::InterfaceRenderer::glyph_vertices, vertex_count, SphereUI::InterfaceRenderer::quad_indices, index_count);
            vertex_count = 0u;
            index_count = 0u;
        };
        for (const std::uint8_t byte : text) {
            if (byte == '\n') break;
            const auto character = uiAtlasGlyph(byte);
            if (x <= clip.right && SphereUI::detail::addCoordinate(x, size) > clip.left) {
                const auto& glyph = g_sfera_font_runtime.glyphs[character];
                const auto next_texture = g_sfera_font_runtime.faces[font].texture(glyph.texture_index);
                if ((texture != nullptr && texture != next_texture) || vertex_count + 4u > std::size(SphereUI::InterfaceRenderer::glyph_vertices)) flush();
                texture = next_texture;
                const auto left = static_cast<float>(x) - 0.5f, upper = static_cast<float>(top) - 0.5f;
                uiFontQuad(SphereUI::InterfaceRenderer::glyph_vertices + vertex_count, left, upper, left + size, upper + size, color, glyph.u, glyph.v, glyph.u + 30.0f / 256.0f, glyph.v + 30.0f / 256.0f, true);
                for (std::uint32_t corner = 0; corner < 4; ++corner) {
                    SphereUI::InterfaceRenderer::glyph_vertices[vertex_count + corner].z = z;
                    SphereUI::InterfaceRenderer::glyph_vertices[vertex_count + corner].rhw = reciprocal;
                }
                uiFontTriangles(SphereUI::InterfaceRenderer::quad_indices + index_count, vertex_count, true);
                vertex_count += 4u;
                index_count += 6u;
            }
            x = SphereUI::detail::addCoordinate(x, static_cast<int>((g_sfera_font_runtime.faces[font].widths[character] + g_sfera_font_runtime.faces[font].code_base) * static_cast<std::uint32_t>(scale)));
        }
        flush();
        (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE));
    }
}

void SphereUI::InterfaceRenderer::drawFaceText(std::string_view text, int x, int y, std::uint32_t color, int font, const SphereUI::UiRect& clip) {
    const auto& face = g_sfera_fonts.face(font);
    if (y > clip.bottom || SphereUI::detail::addCoordinate(y, face.line_height) <= clip.top || (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get()) == nullptr) return;
    auto* texture = g_sfera_textures.resource(face.texture);
    if (auto* device = (g_sfera_graphics_runtime.d3d_runtime == nullptr ? nullptr : g_sfera_graphics_runtime.d3d_runtime->native_device.Get())) (g_sfera_graphics_runtime.d3d_runtime->last_hresult = device->SetTexture(0u, texture));
    const auto* glyphs = face.glyphs.data();
    auto& factory = g_sfera_fonts;
    auto* vertices = factory.vertices.data();
    if (factory.vertices.empty()) throw std::runtime_error("font vertex buffer is unavailable");
    if (factory.vertex_count >= 1200u) factory.vertex_count = 0u;
    std::uint32_t batch_first = factory.vertex_count, batch_count = 0u, index_count = 0u;
    const float origin = static_cast<float>(x) - 0.5f;
    float left = origin, top = static_cast<float>(y) - 0.5f;
    const auto flush = [&]() {
        uiSubmitFont(vertices + batch_first, batch_count, factory.quad_indices.data(), index_count);
        batch_count = 0u;
        index_count = 0u;
        batch_first = factory.vertex_count;
    };
    for (const std::uint8_t character : text) {
        if (character == '\n') {
            left = origin;
            top += face.line_height;
            continue;
        }
        if (character < 32u) continue;
        const auto& glyph = glyphs[character];
        if (character == ' ' || left + glyph.width <= static_cast<float>(clip.left)) {
            left += glyph.advance;
            continue;
        }
        if (left > static_cast<float>(clip.right)) break;
        const auto glyph_left = left + glyph.bearing_x, glyph_top = top - glyph.bearing_y;
        uiFontQuad(vertices + factory.vertex_count, glyph_left, glyph_top, glyph_left + glyph.width, glyph_top + glyph.height, color, glyph.u0, glyph.v0, glyph.u1, glyph.v1, false);
        uiFontTriangles(factory.quad_indices.data() + index_count, batch_count, false);
        factory.vertex_count += 4u;
        batch_count += 4u;
        index_count += 6u;
        if (factory.vertex_count > 1194u) {
            flush();
            factory.vertex_count = 0u;
            batch_first = 0u;
        }
        left += glyph.advance;
    }
    flush();
}

SphereUI::TextExtent SphereUI::InterfaceRenderer::measureText(std::string_view text, int font, bool initialized) {
    std::uint32_t width = 0u, line_width = 0u, extra_height = 0u;
    if (font >= 2u) {
        const auto& face = g_sfera_fonts.face(font);
        const auto* glyphs = face.glyphs.data();
        for (const std::uint8_t byte : text) {
            if (byte == '\n') {
                width = std::max(width, line_width);
                line_width = 0u;
                extra_height += static_cast<std::uint32_t>(face.line_height);
            } else {
                constexpr std::uint8_t lowercase_yo = 184u, lowercase_e = 229u, uppercase_yo = 168u, uppercase_e = 197u;
                const auto character = byte == lowercase_yo ? lowercase_e : byte == uppercase_yo ? uppercase_e : byte;
                line_width += static_cast<std::uint32_t>(glyphs[character].advance);
            }
        }
        return {static_cast<int>(std::max(width, line_width)), static_cast<int>(extra_height + static_cast<std::uint32_t>(face.line_height))};
    }
    std::uint32_t lines = 1u;
    const auto& face = g_sfera_font_runtime.faces[font];
    for (const std::uint8_t byte : text) {
        if (byte == '\n') {
            const auto completed_width = initialized ? line_width : 0u;
            if (static_cast<int>(completed_width) > static_cast<int>(width)) width = completed_width;
            if (++lines == 300u) throw std::length_error("too many lines in font measurement");
            line_width = 0u;
        } else {
            if (static_cast<int>(line_width) > 0) line_width += face.code_base;
            line_width += g_sfera_font_runtime.faces[font].widths[uiAtlasGlyph(byte)];
        }
    }
    if (static_cast<int>(line_width) > static_cast<int>(width)) width = line_width;
    const auto height = initialized ? (lines - 1u) * face.cell_step - face.origin + face.span + 2u : 0u;
    return {static_cast<int>(width + 2u), static_cast<int>(height + (font == 1u ? 2u : 0u))};
}

void SphereUI::InterfaceRenderer::drawText(std::string_view text, int x, int y, std::uint32_t color, int font, bool initialized, const UiRect& clip, bool opaque) {
    SphereUI::InterfaceRenderer::clip_rectangle.left = clip.left;
    SphereUI::InterfaceRenderer::clip_rectangle.top = clip.top;
    SphereUI::InterfaceRenderer::clip_rectangle.right = clip.right;
    SphereUI::InterfaceRenderer::clip_rectangle.bottom = clip.bottom;
    const bool disable_blending = opaque && font < 2u;
    if (disable_blending) SphereUI::InterfaceRenderer::setSpriteRenderMode(0u);
    if (font < 2u) uiDrawAtlasText(text, x, SphereUI::detail::subtractCoordinate(SphereUI::detail::subtractCoordinate(y, 2), static_cast<int>(g_sfera_font_runtime.faces[font].origin)), color, font, initialized ? 1 : 0, clip, 0.0f, false);
    else drawFaceText(text, x, y, color, font, clip);
    if (disable_blending) SphereUI::InterfaceRenderer::setSpriteRenderMode(1u);
}

namespace {
    bool chatRussianVowelOrSign(std::uint8_t value) {

        constexpr std::u32string_view vowels = U"\u0443\u0435\u044b\u0430\u043e\u044d\u044f\u0438\u044e\u044c\u044a";
        return vowels.find(SferaText::unicodeCp1251()[value]) != std::u32string_view::npos;
    }

    bool chatKeyboardAmbiguous(std::uint8_t value) {

        constexpr std::u32string_view aliases = U"\u0435e\u0443y\u043ak\u0433r\u04373\u0445x\u0438u\u043e0o\u0440p\u0441c\u0430a\u0442mE\u0415\u0423YK\u041a\u0417X\u0425O\u041e\u0420PC\u0421A\u0410";
        return aliases.find(SferaText::unicodeCp1251()[value]) != std::u32string_view::npos;
    }

    const std::array<std::array<std::uint8_t, 256>, 2>& chatCharacterMaps() {
        static const auto maps = [] {

            std::array<std::array<std::uint8_t, 256>, 2> result{};
            for (std::size_t character = 0; character < 256; ++character) {
                auto value = SferaText::lowercaseCp1251()[character];
                const auto letter = SferaText::unicodeCp1251()[value];
                if (!((letter >= U'a' && letter <= U'z') || (letter >= U'\u0430' && letter <= U'\u044f') || letter == U'\u0451')) value = ' ';
                result[0][character] = result[1][character] = value;
            }
            for (auto character : {'0', '3', '6'}) result[0][character] = character;
            const auto aliases = [&](std::size_t alphabet, std::string_view group) { for (std::size_t alias = 1; alias < group.size(); ++alias) for (auto& value : result[alphabet]) if (value == static_cast<std::uint8_t>(group[alias])) value = group.front(); };
            for (auto group : {"\345\270e", "\344g", "\3416b", "\363y", "\352k", "\343r", "\3473", "\365x", "\350\351u", "\3560o", "\360p", "\361c", "\340a", "\354m", "\355h"}) aliases(0u, group);
            for (auto group : {"\350\351i", "\363u", "\352k", "\345e\270", "\366c", "\355n", "\343g", "\347z", "\365h", "\344d", "\353l", "\356o", "\360r", "\357p", "\340a", "\342v", "\364f", "\361s", "\354m", "\362t", "\341b"}) aliases(1u, group);
            return result;
        }();
        return maps;
    }

    bool hasPlayerPrefix(std::span<const HyperTextRun> elements) {
        return elements.size() >= 2u && elements[0].link() != nullptr && elements[0].link()->link_kind == 2u
            && elements[1].isPlain() && elements[1].text.starts_with(": ");
    }

    void serializeChatResult(std::span<const HyperTextRun> elements, std::string* raw, std::string* visible) {
        std::string ignored_raw, ignored_visible;
        SphereUI::detail::serializeHyperTextElements(elements, raw != nullptr ? *raw : ignored_raw, visible != nullptr ? *visible : ignored_visible);
    }

}

SphereUI::ChatFilter::ChatFilter() {
    SphereRender::ConfigDocument::setStorageMode(SphereRender::ConfigDocument::StorageMode::Encoded);
    const std::string filename = std::string("xadd\\matbase") + g_sfera_font_runtime.language_suffix + ".dat";
    g_sfera_files.setErrorReporting(false);
    const auto size = g_sfera_files.fileSize(filename);
    g_sfera_files.setErrorReporting(true);
    if (size == -1) return;
    auto configuration = SphereRender::ConfigDocument::open(filename);
    const auto count = configuration.arraySize("words");
    if (!count) { WorldDiagnostics::fail("CMatFilter::CMatFilter: array words absent in matbase.dat"); return; }
    rules.reserve(*count);
    for (std::size_t index = 0u; index < *count; ++index) {
        const auto* item = configuration.objectAt("words", index);
        const auto word = item != nullptr ? item->text("w") : std::nullopt;
        if (!word) { WorldDiagnostics::fail("CMatFilter::CMatFilter: field 'w' absent in one of array's elements"); continue; }
        const auto kind = item->integer("t");
        if (!kind) { WorldDiagnostics::fail("CMatFilter::CMatFilter: field 't' absent in one of array's elements"); continue; }
        Rule rule{std::string(*word), static_cast<std::uint32_t>(*kind)};
        for (std::size_t exception = 0u; exception < item->arraySize("e").value_or(0u); ++exception) {
            if (const auto value = item->textAt("e", exception)) rule.exceptions.emplace_back(*value);
            else WorldDiagnostics::fail("CMatFilter::CMatFilter: error reading exceptions");
        }
        rules.push_back(std::move(rule));
    }
}

SphereUI::ChatFilter::ChatFilter(std::vector<Rule> entries) : rules(std::move(entries)) {}

std::string SphereUI::ChatFilter::normalize(std::string_view text, std::size_t alphabet) {
    std::string result(text);
    const auto& map = chatCharacterMaps()[alphabet != 0u];
    for (auto& value : result) value = map[static_cast<std::uint8_t>(value)];
    return result;
}

bool SphereUI::ChatFilter::matchesWord(std::string_view word, std::size_t alphabet) const {
    for (const auto& rule : rules) {
        const auto pattern = normalize(rule.word, alphabet);
        const auto position = word.find(pattern);
        if (position == std::string_view::npos) continue;
        switch (rule.kind) {
            case 0u: if (word != pattern) continue; break;
            case 1u: break;
            case 2u: if (position != 0u) continue; break;
            case 3u: if (position != 0u && !chatRussianVowelOrSign(static_cast<std::uint8_t>(word[position - 1u]))) continue; break;
            case 4u: if (position != 0u || (word.size() != pattern.size() && !chatRussianVowelOrSign(static_cast<std::uint8_t>(word[pattern.size()])))) continue; break;
            default: continue;
        }
        bool excepted = false;
        for (const auto& exception : rule.exceptions) {
            if (exception.empty()) continue;
            const auto text = normalize(std::string_view(exception).substr(1u), alphabet);
            if (exception.front() == '0' && position >= text.size()) excepted = word.substr(position - text.size(), text.size()) == text;
            else if (exception.front() == '1') excepted = word.substr(position + pattern.size()).starts_with(text);
            if (excepted) break;
        }
        if (!excepted) return true;
    }
    return false;
}

bool SphereUI::ChatFilter::matchesMessage(std::string_view message, std::size_t alphabet) const {
    auto text = normalize(message, alphabet);
    text.erase(std::unique(text.begin(), text.end()), text.end());
    std::vector<std::string_view> words;
    for (std::size_t first = 0u; first < text.size();) {
        first = text.find_first_not_of(' ', first);
        if (first == std::string::npos) break;
        auto last = text.find(' ', first);
        if (last == std::string::npos) last = text.size();
        words.emplace_back(text.data() + first, last - first);
        first = last;
    }
    for (std::size_t first = 0u; first < words.size(); ++first) {
        if (matchesWord(words[first], alphabet)) return true;
        if (words[first].size() > 3u) continue;
        std::string joined(words[first]);
        for (auto next = first + 1u; next < words.size() && words[next].size() <= 3u; ++next) {
            joined += words[next];
            if (matchesWord(joined, alphabet)) return true;
        }
    }
    return false;
}

bool SphereUI::ChatFilter::rejects(std::string_view message) const {
    if (rules.empty()) return false;
    std::string visible(message);
    bool tag = false;
    for (auto& character : visible) {
        const auto value = character;
        if (value == '<') tag = true;
        if (tag) character = ' ';
        if (value == '>') tag = false;
    }
    return matchesMessage(visible, 0u) || matchesMessage(visible, 1u);
}

bool SphereUI::ChatFilter::invalidIdentifier(std::string_view name) {

    std::uint32_t alphabet = 0u;
    for (std::uint8_t character : name) {
        std::uint32_t current = 0u;
        if (character == '-' || character == ' ' || character == '_' || (character >= '0' && character <= '9')) current = 0u;
        else if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) current = 1u;
        else if (const auto letter = SferaText::unicodeCp1251()[character]; (letter >= U'\u0410' && letter <= U'\u044f') || letter == U'\u0401' || letter == U'\u0451') current = 2u;
        else return true;
        if (alphabet == 0u) alphabet = current;
        else if (alphabet != current && chatKeyboardAmbiguous(character)) return true;
    }
    return false;
}

std::string SphereUI::HyperTextParser::plainText(std::string_view input) {
    std::vector<HyperTextRun> elements;
    std::string plain;
    parseElements(input, elements, plain);
    return plain;
}

std::string SphereUI::HyperTextParser::buildLink(std::string_view scheme, std::string_view target, std::string_view caption) {
    return "<l=\"" + std::string(scheme) + "://" + detail::escapeHyperText(target) + "\">" + std::string(caption) + "</l>";
}

bool SphereUI::HyperTextParser::extractPlayerPrefix(std::string_view input, std::string* output, std::string* plain) {
    std::vector<HyperTextRun> elements;
    std::string visible;
    parseElements(input, elements, visible);
    if (!hasPlayerPrefix(elements)) return false;
    serializeChatResult(std::span(elements).first(1u), output, plain);
    return true;
}

bool SphereUI::HyperTextParser::removePlayerPrefix(std::string_view input, std::string* output, std::string* plain) {
    std::vector<HyperTextRun> elements;
    std::string visible;
    parseElements(input, elements, visible);
    if (elements.empty()) return false;
    if (hasPlayerPrefix(elements)) {
        elements[1].text.erase(0u, 2u);
        elements.erase(elements.begin(), elements.begin() + (elements[1].text.empty() ? 2u : 1u));
    }
    serializeChatResult(elements, output, plain);
    return true;
}

bool SphereUI::HyperTextParser::eraseRange(std::string_view input, std::size_t first, std::size_t last, std::string* output, std::string* plain) {
    std::vector<HyperTextRun> elements;
    std::string visible;
    parseElements(input, elements, visible);
    if (elements.empty()) return false;
    const std::uint64_t end = static_cast<std::uint64_t>(last) + 1u;
    std::uint64_t offset = 0u;
    std::vector<HyperTextRun> selected;
    for (const auto& element : elements) {
        const std::uint64_t next = offset + element.text.size();
        const bool overlap = first <= last && offset < end && next > first;
        if (!overlap || offset < first || next > end || (first >= offset && last < next)) {
            auto copy = element;
            if (overlap) {
                const std::size_t begin = first > offset ? first - offset : 0u;
                const std::size_t count = std::min(next, end) - offset - begin;
                copy.text.erase(begin, count);
            }
            selected.push_back(std::move(copy));
        }
        offset = next;
    }
    if (first <= last && first < offset) elements = std::move(selected);
    serializeChatResult(elements, output, plain);
    return true;
}

void SphereUI::InterfaceManager::loadAllWindowTemplates() {
    std::vector<std::filesystem::path> files;
    std::error_code error;
    for (std::filesystem::directory_iterator entry("Effects", error), end; !error && entry != end; entry.increment(error)) if (!entry->is_directory(error) && SferaText::asciiEqual(entry->path().extension().string(), ".ui")) files.push_back(entry->path());
    float completed = 0.0f;
    const float fraction = files.empty() ? 0.0f : static_cast<float>(1.0 / static_cast<double>(files.size()));
    for (const auto& file : files) {
        if (SferaText::asciiEqual(file.filename().string(), "loadscreen.ui")) continue;
        loadWindowTemplates(file.string());
        completed += fraction;
        GameInterface::updateLoadingProgress(static_cast<std::uint32_t>(static_cast<int>(static_cast<double>(completed) * 30.0 + 30.0)));
    }
}

bool SphereUI::InterfaceManager::initializeResources() {
    if (!prepareResources()) return false;
    GameInterface::updateLoadingProgress(15u);
    loadHyperTexts();
    GameInterface::updateLoadingProgress(30u);
    loadAllWindowTemplates();
    finishInitialization();
    return true;
}

void SphereUI::InterfaceManager::showOptions(bool visible) {
    auto* window = findWindow("options");
    if (visible && window == nullptr) { window = openWindow("options", 0, 0, 0u); if (window != nullptr) bindEventHandler(window, WindowEventHandler::options); }
    else if (!visible && window != nullptr) closeWindow(window, true);
}

namespace {
    bool interfaceDepth(float depth, float& z, float& reciprocal) {
        z = 0.0f;
        reciprocal = 1.0f;
        if (!(depth > 0.001f)) return true;
        const double nearPlane = g_sfera_camera.near_distance, farPlane = g_sfera_camera.far_distance;
        if (depth < nearPlane || depth > farPlane) return false;
        z = (farPlane - nearPlane * farPlane / depth) / (farPlane - nearPlane);
        reciprocal = 1.0 / depth;
        return true;
    }

    void interfaceQuad(SferaScreenVertex* vertices, float left, float top, float right, float bottom, std::uint32_t color, const float* uv, float z, float reciprocal, bool clearSpecular) {
        for (std::size_t corner = 0; corner < 4; ++corner) {
            const bool onRight = corner == 1 || corner == 2, onBottom = corner >= 2;
            auto& vertex = vertices[corner];
            vertex = {onRight ? right : left, onBottom ? bottom : top, z, reciprocal, color, clearSpecular ? 0u : vertex.specular, uv ? uv[corner * 2] : (onRight ? 1.0f : 0.0f), uv ? uv[corner * 2 + 1] : (onBottom ? 1.0f : 0.0f)};
        }
    }

    void interfaceNamedQuad(int left, int top, int width, int height, std::string_view name, std::uint32_t color, std::uint32_t alpha, float depth, const float* uv, bool worldSpace) {
        if (width == 0 || height == 0) return;
        auto& device = *g_sfera_graphics_runtime.d3d_runtime;
        const auto texture = g_sfera_textures.find(name);
        device.checkResult(device.native_device->SetTexture(0, g_sfera_textures.resource(texture)), "SetTexture");
        if (alpha != 255 || g_sfera_textures.hasAlpha(texture)) device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
        float z, reciprocal;
        if (!interfaceDepth(depth, z, reciprocal)) return;
        auto* vertices = SceneSky::sun_quad;
        const float x = static_cast<float>(left) - 0.5f, y = static_cast<float>(top) - 0.5f;
        interfaceQuad(vertices, x, y, x + width, y + height, color, uv, z, reciprocal, true);
        device.checkResult(device.native_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE), "SetRenderState");
        device.checkResult(device.native_device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1), "SetFVF");
        if (worldSpace) device.drawVertices(D3DPT_TRIANGLEFAN, 14, vertices, 4, nullptr, 0, sizeof(SferaScreenVertex));
        else device.checkResult(device.native_device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertices, sizeof(SferaScreenVertex)), "DrawPrimitiveUP");
        device.last_hresult = device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    }
}

HRESULT GameInterface::drawSpriteQuad(std::uint32_t color, const float* uv, float left, float top, float right, float bottom) {
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    auto* vertices = GameInterface::sprite_quad;
    interfaceQuad(vertices, left - 0.5f, top - 0.5f, right - 0.5f, bottom - 0.5f, color, uv, 0.0f, 1.0f, false);
    return device.checkResult(device.native_device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertices, sizeof(SferaScreenVertex)), "DrawPrimitiveUP");
}

HRESULT GameInterface::drawSpriteTexture(std::uint32_t color, int texture, float left, float top, float right, float bottom, const float* uv, bool) {
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    if (texture <= 0) device.checkResult(device.native_device->SetTexture(0, nullptr), "SetTexture");
    else SphereRender::SceneRenderer::bindTexture(texture);
    return drawSpriteQuad(color, uv, left, top, right, bottom);
}

void GameInterface::drawTexture(int left, int top, int width, int height, std::string_view name, std::uint32_t alpha, float depth, const float* uv) {
    interfaceNamedQuad(left, top, width, height, name, SferaColor::rgba(255u, 255u, 255u, alpha).argb(), alpha, depth, uv, true);
}

void GameInterface::tintTexture(int left, int top, int width, int height, std::string_view name, std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint32_t alpha, const float* uv) {
    interfaceNamedQuad(left, top, width, height, name, SferaColor::rgba(red, green, blue, alpha).argb(), alpha, 0.0f, uv, false);
}

void GameInterface::drawFullscreenOverlay() {
    const auto alpha = g_sfera_interface.overlay_alpha;
    if (alpha == 0) return;
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    auto* vertices = SceneSky::sun_quad;
    interfaceQuad(vertices, 0.0f, 0.0f, static_cast<float>(g_sfera_graphics_runtime.display_width), static_cast<float>(g_sfera_graphics_runtime.display_height), SferaColor::rgba(255u, 255u, 255u, alpha).argb(), nullptr, 0.0f, 1.0f, true);
    device.setAlphaBlending(D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA);
    device.checkResult(device.native_device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1), "SetFVF");
    device.drawVertices(D3DPT_TRIANGLEFAN, 14, vertices, 4, nullptr, 0, sizeof(SferaScreenVertex));
    device.last_hresult = device.native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}

std::uint32_t GameInterface::fontHeight(int font, std::uint32_t scale) { return g_sfera_font_runtime.faces[font].span * scale; }
std::uint32_t GameInterface::glyphWidth(std::uint32_t character, int font) { return g_sfera_font_runtime.faces[font].widths[character] + g_sfera_font_runtime.faces[font].code_base; }
std::uint32_t GameInterface::textHeight(int font, std::uint32_t scale, std::uint32_t lines) { return ((lines - 1) * g_sfera_font_runtime.faces[font].cell_step + g_sfera_font_runtime.faces[font].span) * scale; }
std::uint32_t GameInterface::lineOffset(int font, std::uint32_t scale, std::uint32_t line) { return g_sfera_font_runtime.faces[font].cell_step * scale * line; }

void GameInterface::setRenderState() {
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    device.checkResult(device.native_device->SetVertexShader(nullptr), "SetVertexShader");
    device.checkResult(device.native_device->SetPixelShader(nullptr), "SetPixelShader");
    device.checkResult(device.native_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE), "SetRenderState");
    for (auto state : {D3DRS_ZENABLE, D3DRS_ZWRITEENABLE, D3DRS_LIGHTING, D3DRS_FOGENABLE}) device.checkResult(device.native_device->SetRenderState(state, FALSE), "SetRenderState");
    device.checkResult(device.native_device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1), "SetFVF");
    device.setColorOperation(0, D3DTOP_MODULATE, D3DTA_TEXTURE, D3DTA_DIFFUSE);
    device.setAlphaOperation(0, D3DTOP_MODULATE, D3DTA_TEXTURE, D3DTA_DIFFUSE);
    for (auto state : {D3DSAMP_ADDRESSU, D3DSAMP_ADDRESSV}) device.checkResult(device.native_device->SetSamplerState(0, state, D3DTADDRESS_CLAMP), "SetSamplerState");
}

void GameInterface::restoreRenderState() {
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    for (auto state : {D3DSAMP_ADDRESSU, D3DSAMP_ADDRESSV}) device.checkResult(device.native_device->SetSamplerState(0, state, D3DTADDRESS_WRAP), "SetSamplerState");
    for (auto state : {D3DRS_LIGHTING, D3DRS_FOGENABLE, D3DRS_ZWRITEENABLE, D3DRS_ZENABLE}) device.checkResult(device.native_device->SetRenderState(state, TRUE), "SetRenderState");
    device.checkResult(device.native_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW), "SetRenderState");
}

void GameInterface::drawFrame() {
    setRenderState();
    g_sfera_interface.draw();

    const int elapsed = static_cast<std::uint32_t>(WorldClock::nowTicks()) - static_cast<std::uint32_t>(SferaClientApplication::frame_anchor);
    ++SferaClientApplication::frame_samples;
    if (elapsed > 1000) {
        SferaClientApplication::measured_fps = static_cast<double>(static_cast<int>(SferaClientApplication::frame_samples)) * 10000.0 / elapsed;
        SferaClientApplication::frame_samples = 0;
        const auto now = WorldClock::nowTicks();
        SferaClientApplication::frame_anchor = now;
    }
    restoreRenderState();
}

void GameInterface::finishLoading() {
    g_sfera_interface.showLoadingScreen(false, g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height, false);
    ::_chmod("loadcount.bin", _S_IREAD | _S_IWRITE);
    SferaFileManager::ScopedFile file(g_sfera_files, g_sfera_files.create("loadcount.bin"));
    if (file.get() < 0) return;
    const auto work = GameInterface::loading_completed;
    g_sfera_files.write(file.get(), &work, sizeof(work));
    file.close();
}

void GameInterface::updateLoadingProgress(std::uint32_t increment) {
    auto& work = GameInterface::loading_completed;
    work = work + static_cast<std::uint64_t>(increment);
    const auto total = std::max(static_cast<int>(GameInterface::loading_total - 80), 1);
    const auto progress = std::min(static_cast<int>(work * 100u) / total, 100);
    if (static_cast<std::uint32_t>(progress) == g_sfera_graphics_runtime.rebuild_percent) return;
    g_sfera_graphics_runtime.rebuild_percent = progress;
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    SceneScope scene(device);
    if (!scene) return;
    g_sfera_interface.setLoadingProgress(progress);
    g_sfera_interface.update(0, 0, 0, 0);
    drawAll();
    scene.finish();
    device.waitForGpu();
    device.present();
}

void GameInterface::drawAtlasText(std::string_view text, int x, int y, std::uint32_t color, int scale, int font, float depth) {

    uiDrawAtlasText(text, x, y, color, font, scale, {SphereUI::InterfaceRenderer::clip_rectangle.left, SphereUI::InterfaceRenderer::clip_rectangle.top, SphereUI::InterfaceRenderer::clip_rectangle.right, SphereUI::InterfaceRenderer::clip_rectangle.bottom}, depth, true);
}

namespace {
    void interfaceWindowBorder(const GameUiWindow& window) {
        const auto width = window.contentRight - window.contentLeft + 1, height = window.contentBottom - window.contentTop + 1;
        const float u = static_cast<float>(width) / 256.0f, v = static_cast<float>(height) / 256.0f;
        const float background[] = {0, 0, u, 0, u, v, 0, v};
        GameInterface::drawTexture(window.contentLeft, window.contentTop, width, height, "winfon", window.opacity, 0, background);
        const float cornerUv[] = {0, 6.0f / 256, 6.0f / 256, 6.0f / 256, 6.0f / 256, 12.0f / 256, 0, 12.0f / 256};
        for (std::size_t corner = 0; corner < 4; ++corner) {
            float uv[8];
            for (std::size_t vertex = 0; vertex < 4; ++vertex) {
                const auto source = (vertex + 4 - corner) % 4;
                uv[vertex * 2] = cornerUv[source * 2];
                uv[vertex * 2 + 1] = cornerUv[source * 2 + 1];
            }
            const bool right = corner == 1 || corner == 2, bottom = corner >= 2;
            GameInterface::drawTexture(right ? window.contentRight + 1 : window.left, bottom ? window.contentBottom + 1 : window.top, right ? window.right - window.contentRight : window.contentLeft - window.left, bottom ? window.bottom - window.contentBottom : window.contentTop - window.top, "wf_bord", window.opacity, 0, uv);
        }
        const float horizontal[] = {0, 0, u, 0, u, 6.0f / 256, 0, 6.0f / 256};
        GameInterface::drawTexture(window.contentLeft, window.top, width, window.contentTop - window.top, "wf_bord", window.opacity, 0, horizontal);
        GameInterface::drawTexture(window.contentLeft, window.contentBottom + 1, width, window.bottom - window.contentBottom, "wf_bord", window.opacity, 0, horizontal);
        const float vertical[] = {0, 6.0f / 256, 0, 0, v, 0, v, 6.0f / 256};
        GameInterface::drawTexture(window.left, window.contentTop, window.contentLeft - window.left, height, "wf_bord", window.opacity, 0, vertical);
        GameInterface::drawTexture(window.contentRight + 1, window.contentTop, window.right - window.contentRight, height, "wf_bord", window.opacity, 0, vertical);
    }

    void interfaceElement(const GameUiElement& element, int scrollX, int scrollY) {
        int x = 0, y = 0;
        auto alpha = element.alpha;
        float depth = 0;
        if (element.objectHandle != UINT32_MAX) {
            SferaVec3F projected;
            if (!g_sfera_camera.projectObjectTop(element.objectHandle, projected, element.height_factor)) return;
            x = projected.x;
            y = projected.y;
            const auto& object = *g_sfera_world_objects.object(element.objectHandle);
            const auto& reference = *g_sfera_world_objects.object(1);
            const auto delta = reference.position - object.position;
            const float squaredDistance = static_cast<double>(delta.x) * delta.x + static_cast<double>(delta.y) * delta.y + static_cast<double>(delta.z) * delta.z;
            const float distance = std::sqrt(static_cast<double>(squaredDistance));
            if (distance > 100.0f) return;
            alpha = 255u - static_cast<std::uint32_t>(static_cast<int>(static_cast<double>(distance) / 100.0 * 255.0));
            depth = static_cast<double>(g_sfera_camera.frame_transform.inverseTransformPoint(object.position).z) - 2.0;
            if (g_sfera_camera.near_distance > depth) depth = static_cast<double>(g_sfera_camera.near_distance) + static_cast<double>(0.01f);
        }
        if (const auto* sprite = std::get_if<GameUiElement::Sprite>(&element.content)) {
            const auto opacity = static_cast<int>(element.alpha * alpha) / 255;
            GameInterface::drawTexture(sprite->left - scrollX + x, sprite->top - scrollY + y, sprite->width, sprite->height, sprite->texture, opacity, depth, nullptr);
        } else {
            const auto& text = std::get<GameUiElement::Text>(element.content);
            const auto opacity = static_cast<int>(SferaColor::fromArgb(element.color).alpha() * alpha) / 255;
            const auto color = SferaColor::fromArgb(element.color).withAlpha(static_cast<std::uint32_t>(opacity)).argb();
            for (const auto& line : text.lines) GameInterface::drawAtlasText(std::string_view(text.bytes).substr(line.offset), line.x - scrollX + x, line.y - scrollY + y, color, text.font_scale, text.font, depth);
        }
    }
}

void GameInterface::drawWindow(int handle) {
    auto* window = GameInterface::window(handle);
    if (!window) {
        WorldDiagnostics::message.clear();
        WorldDiagnostics::appendScriptContext("draw_window: wrong handle");
        WorldDiagnostics::flushScriptContext();
        return;
    }
    if (handle != 0 && window->opacity != 0) interfaceWindowBorder(*window);
    auto& device = *g_sfera_graphics_runtime.d3d_runtime;
    const D3DVIEWPORT9 viewport{static_cast<DWORD>(window->contentLeft), static_cast<DWORD>(window->contentTop), static_cast<DWORD>(window->contentRight - window->contentLeft + 1), static_cast<DWORD>(window->contentBottom - window->contentTop + 1), 0, 1};
    device.last_hresult = device.native_device->SetViewport(&viewport);
    SphereUI::InterfaceRenderer::clip_rectangle = {window->contentLeft, window->contentTop, window->contentRight, window->contentBottom};
    const int scrollX = window->scrollX, scrollY = window->scrollY;
    for (auto control : window->controls) {
        if (control == UINT32_MAX) continue;
        auto* value = WorldGuiControls::control(control);
        if (!value) WorldDiagnostics::fail("internal error 37185837");
        interfaceElement(*value, scrollX, scrollY);
    }
    const D3DVIEWPORT9 fullViewport{0u, 0u, static_cast<DWORD>(g_sfera_graphics_runtime.display_width), static_cast<DWORD>(g_sfera_graphics_runtime.display_height), 0.0f, 1.0f};
    device.last_hresult = device.native_device->SetViewport(&fullViewport);
}

std::vector<int> GameInterface::orderedWindows(WindowOrder order) {
    std::vector<int> result;
    result.reserve(windows.size());
    for (std::uint32_t handle = 0; handle < windows.size(); ++handle)
        if (window(handle)) result.push_back(static_cast<int>(handle));
    SferaAlgorithms::stableSort(result, [order](int handle) {
        const auto& item = *window(handle);
        const std::uint32_t bits = item.layer * 1000u + item.order;
        return std::bit_cast<std::int32_t>(order == WindowOrder::HitTest ? 0u - bits : bits);
    });
    return result;
}

void GameInterface::drawAll() {
    for (int handle : orderedWindows(WindowOrder::Draw)) drawWindow(handle);
}

GameUiWindow* GameInterface::window(std::uint32_t handle, std::string_view operation) {
    const auto& windows = GameInterface::windows;
    auto* result = handle < windows.size() ? windows[handle].get() : nullptr;
    if (!result && !operation.empty()) {
        WorldDiagnostics::message.clear();
        WorldDiagnostics::appendScriptContext(operation);
        WorldDiagnostics::appendScriptContext(": wrong handle");
        WorldDiagnostics::flushScriptContext();
    }
    return result;
}

std::uint32_t GameInterface::createWindow(int left, int top, int right, int bottom, std::uint32_t layer, std::uint32_t opacity) {
    const auto handle = vacantGuiSlot(GameInterface::windows);
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
    created->order = static_cast<std::uint32_t>(std::count_if(windows.begin(), windows.end(), [](const auto& item) { return item != nullptr; }));
    GameInterface::windows.at(handle) = std::move(created);
    return handle;
}

void GameInterface::destroyWindow(std::uint32_t handle) {
    auto* removed = window(handle, "delete_window");
    if (!removed) return;
    for (const auto controlHandle : removed->controls) {
        if (controlHandle == UINT32_MAX) continue;
        const auto* item = WorldGuiControls::control(controlHandle);
        if (!item) WorldDiagnostics::fail("Window contains a missing control");
        eraseGuiControl(controlHandle, *item);
    }
    for (std::uint32_t index = 0; index < GameInterface::windows.size(); ++index) {
        auto* other = window(index);
        if (other && other->order > removed->order) --other->order;
    }
    if (GameInterface::active_window == handle) GameInterface::active_window = UINT32_MAX;
    windows.at(handle).reset();
}

std::uint32_t GameUiWindow::attach(std::uint32_t control) {
    const auto slot = std::find(controls.begin(), controls.end(), UINT32_MAX);
    if (slot != controls.end()) { *slot = control; return static_cast<std::uint32_t>(slot - controls.begin()); }
    if (controls.size() >= 7000) WorldDiagnostics::fail("MNO_CONTROLS_IN_WINDOW exceed");
    controls.push_back(control);
    return static_cast<std::uint32_t>(controls.size() - 1);
}

void GameUiWindow::detach(std::uint32_t slot) {
    if (slot >= std::size(controls)) WorldDiagnostics::fail("Window control slot is outside the control table");
    if (controls[slot] == UINT32_MAX) WorldDiagnostics::fail("internal error 86557243");
    controls[slot] = UINT32_MAX;
}

void GameUiWindow::recalculateSize() {
    int maximumRight = 0, maximumBottom = 0;
    for (auto handle : controls) {
        if (handle == UINT32_MAX) continue;
        const auto* item = WorldGuiControls::control(handle);
        if (!item) WorldDiagnostics::fail("internal error 47581837");
        maximumRight = std::max(maximumRight, item->right);
        maximumBottom = std::max(maximumBottom, item->bottom);
    }
    width = std::max(maximumRight + 1, contentRight - contentLeft + 1);
    height = std::max(maximumBottom + 1, contentBottom - contentTop + 1);
}

void GameUiWindow::enqueueInput(std::uint32_t control, std::uint32_t message) {
    if (events.size() < 10) events.push_back({control, message});
}

bool GameUiWindow::takeInput(std::uint32_t& control, std::uint32_t& message) {
    if (events.empty()) return false;
    const auto event = events.front();
    events.pop_front();
    control = event.control;
    message = event.message;
    return true;
}

SferaCursorPosition GameUiWindow::contentPosition(SferaCursorPosition point) const {
    if (point.x < contentLeft || point.x >= contentRight || point.y < contentTop || point.y >= contentBottom) return {-1, -1};
    return {point.x - contentLeft + static_cast<int>(scrollX), point.y - contentTop + static_cast<int>(scrollY)};
}

void GameUiWindow::scrollBy(float dx, float dy, SferaCursorPosition& cursor) {
    scrollX -= dx;
    scrollY -= dy;
    const auto clampAxis = [](float& scroll, int limit, int& position) {
        if (scroll < 0.0f) { position = static_cast<double>(position) + scroll; scroll = 0.0f; }
        const float maximum = limit;
        if (scroll > maximum) { position = static_cast<double>(scroll) - maximum + position; scroll = maximum; }
    };
    clampAxis(scrollX, width - (contentRight - contentLeft + 1), cursor.x);
    clampAxis(scrollY, height - (contentBottom - contentTop + 1), cursor.y);
}

void GameUiElement::layoutText(std::string_view text, const GameUiWindow& window, int x, int y) {
    if (text.empty() || window.font >= g_sfera_font_runtime.faces.size()) WorldDiagnostics::fail("Invalid text or font");
    Text layout;
    layout.bytes = text;
    layout.bytes.push_back('\n');
    layout.font = window.font;
    layout.font_scale = window.fontScale;
    std::array<int, 300> widths{};
    int maximumWidth = 0;
    std::size_t begin = 0;
    for (std::size_t offset = 0; offset < layout.bytes.size(); ++offset) {
        auto& width = widths[layout.lines.size()];
        if (layout.bytes[offset] == '\n') {
            width *= static_cast<int>(layout.font_scale);
            maximumWidth = std::max(maximumWidth, width);
            layout.lines.push_back({begin});
            if (layout.lines.size() == widths.size()) WorldDiagnostics::fail("MNO_LINES_IN_TEXT exceeded");
            begin = offset + 1;
        } else {
            if (width > 0) width += g_sfera_font_runtime.faces[layout.font].code_base;
            const auto character = static_cast<std::uint8_t>(layout.bytes[offset]);
            width += g_sfera_font_runtime.faces[layout.font].widths[g_sfera_font_runtime.glyphs[character].defined ? character : 124u];
        }
    }
    if (layout.lines.empty() || maximumWidth == 0) WorldDiagnostics::fail("Empty text created");
    color = window.textColor;
    alpha = 255;
    const auto textWidth = maximumWidth + 2;
    const int textHeight = GameInterface::textHeight(layout.font, layout.font_scale, static_cast<std::uint32_t>(layout.lines.size()));
    WorldGuiControls::text_width = textWidth;
    WorldGuiControls::text_height = textHeight;
    const auto style = window.textStyle;
    left = x;
    top = y;
    if (style & GameUiWindow::centerHorizontal) left -= textWidth / 2;
    if (style & GameUiWindow::alignBottom) top -= textHeight;
    else if (style & GameUiWindow::centerVertical) top -= textHeight / 2;
    right = left + textWidth - 1;
    bottom = top + textHeight - 1;
    const auto fitAxis = [](int& begin, int& end, int maximum) {
        if (end > maximum) { begin += maximum - end; end = maximum; }
        if (begin < 0) { end -= begin; begin = 0; }
    };
    if (style & GameUiWindow::fitHorizontal) fitAxis(left, right, window.contentRight - window.contentLeft);
    if (style & GameUiWindow::fitVertical) fitAxis(top, bottom, window.contentBottom - window.contentTop);
    for (std::uint32_t line = 0; line < layout.lines.size(); ++line) {
        layout.lines[line].x = window.contentLeft + left + ((style & GameUiWindow::centerLines) ? (textWidth - widths[line]) / 2 : 0);
        layout.lines[line].y = window.contentTop + top + static_cast<int>((line * g_sfera_font_runtime.faces[layout.font].cell_step - g_sfera_font_runtime.faces[layout.font].origin) * layout.font_scale);
    }
    content = std::move(layout);
}

std::uint32_t WorldGuiControls::createText(int x, int y, std::string_view text, std::uint32_t windowHandle) {
    return createGuiControl(windowHandle, "create_text: wrong window", [&](GameUiElement& item, const GameUiWindow& window) {
        item.layoutText(text, window, x, y);
        return (window.textStyle & GameUiWindow::measureOnly) == 0;
    });
}

std::uint32_t WorldGuiControls::createSprite(int x, int y, int width, int height, std::string_view texture, std::uint32_t windowHandle, std::uint32_t alpha) {
    return createGuiControl(windowHandle, "create_sprite: wrong window", [&](GameUiElement& item, const GameUiWindow& window) {
        if (texture.empty()) WorldDiagnostics::fail("Sprite texture name is empty");
        const std::string_view name(texture);
        if (name.size() >= 40) WorldDiagnostics::fail("Sprite texture name is too long");
        item.content = GameUiElement::Sprite{std::string(name), window.contentLeft + x, window.contentTop + y, width, height};
        item.left = x;
        item.top = y;
        item.right = x + width - 1;
        item.bottom = y + height - 1;
        item.alpha = alpha;
        return true;
    });
}

void WorldGuiControls::setAppearance(std::uint32_t handle, std::uint32_t alpha, std::optional<std::uint32_t> color) {
    auto* item = control(handle);
    if (!item) WorldDiagnostics::fail(color ? "text_color: wrong handle" : "set_sprite_alpha: wrong handle");
    item->alpha = alpha;
    if (color) item->color = *color;
}

void WorldGuiControls::destroyAllText() {
    for (std::uint32_t handle = 0; handle < WorldGuiControls::elements.size(); ++handle) {
        const auto* item = control(handle);
        if (item && item->isText()) destroyText(handle);
    }
}

GameUiHit GameInterface::hitTest(SferaCursorPosition point) {
    GameUiHit hit{};
    for (int handle : orderedWindows(WindowOrder::HitTest)) {
        const auto& item = *window(handle);
        if (!item.visible || point.x < item.left || point.x > item.right || point.y < item.top || point.y > item.bottom) continue;
        hit.window = handle;
        hit.border = point.x < item.contentLeft || point.x > item.contentRight || point.y < item.contentTop || point.y > item.contentBottom;
        break;
    }
    if (hit.border) return hit;
    const auto* owner = window(hit.window);
    if (!owner) return hit;
    const double x = static_cast<float>(point.x), y = static_cast<float>(point.y);
    for (auto handle : owner->controls) {
        if (handle == UINT32_MAX) continue;
        const auto* item = WorldGuiControls::control(handle);
        if (!item) WorldDiagnostics::fail("Window contains a missing control");
        const double left = static_cast<double>(item->left + owner->contentLeft) - owner->scrollX;
        const double right = static_cast<double>(item->right + owner->contentLeft) - owner->scrollX;
        const double top = static_cast<double>(item->top + owner->contentTop) - owner->scrollY;
        const double bottom = static_cast<double>(item->bottom + owner->contentTop) - owner->scrollY;
        if (x >= left && x <= right && y >= top && y <= bottom) { hit.control = handle; break; }
    }
    return hit;
}

void GameInterface::updateInput() {
    auto& cursor = *CCursorManager::instance().activeCursor();
    auto& active = GameInterface::active_window;
    const auto buttons = g_sfera_direct_input_runtime.mouse.buttons;
    if (g_sfera_interface.world_interaction_enabled) {
        if (active != 0u) cursor.updatePosition();
        if (active == UINT32_MAX) {
            if (buttons & 2u) active = hitTest(CCursorManager::instance().position()).window;
        } else if (!(buttons & 2u)) active = UINT32_MAX;
        else if (active != 0u) {
            auto* selected = window(active);
            if (selected && selected->scrollable) {
                auto position = CCursorManager::instance().position();
                selected->scrollBy(static_cast<float>(static_cast<double>(g_sfera_direct_input_runtime.mouse.dx) * 1.5), static_cast<float>(static_cast<double>(g_sfera_direct_input_runtime.mouse.dy) * 1.5), position);
                cursor.setPosition(position.x, position.y);
            }
        }
        cursor.show();
    }
    const auto previous = g_sfera_interface.world_input_buttons;
    if ((buttons & 1u) != (previous & 1u)) {
        const auto hit = g_sfera_interface.world_interaction_enabled ? hitTest(CCursorManager::instance().position()) : GameUiHit{};
        if (auto* selected = window(hit.window)) selected->enqueueInput(hit.control, (buttons & 1u) ? 1u : 2u);
    }
    g_sfera_interface.world_input_buttons = buttons;
}

void GameFontAtlas::clear() noexcept {
    for (auto& face : faces) face.pages.clear();
}

void GameFontAtlas::load(int font, const std::string& filename, int outline, std::uint32_t spacing, std::uint32_t emptyWidth) {
    if (font < 0 || static_cast<std::size_t>(font) >= faces.size() || outline < 0 || outline > 3) WorldDiagnostics::fail("Invalid bitmap font parameters");
    const auto image = g_sfera_files.readAll(filename);
    constexpr std::size_t sourceWidth = 280;
    constexpr std::size_t sourceCell = 26;
    constexpr std::size_t atlasWidth = 256;
    constexpr std::size_t atlasCell = 32;
    constexpr std::size_t paletteBytes = 256 * 3;
    if (image.size() < PcxHeader::encodedSize + paletteBytes) WorldDiagnostics::fail("Truncated font image");
    const auto header = PcxHeader::decode(image.data());
    if (header.maximum_y < header.minimum_y) WorldDiagnostics::fail("Invalid font image height");
    const auto height = std::uint32_t(header.maximum_y) - header.minimum_y + 1;
    const auto palette = image.size() - paletteBytes;
    std::vector<std::uint8_t> mask(sourceWidth * height);
    std::size_t source = PcxHeader::encodedSize;
    for (std::size_t destination = 0; destination < mask.size();) {
        if (source >= palette) WorldDiagnostics::fail("Truncated font image pixels");
        auto color = image[source++];
        std::size_t count = 1;
        if (color > PcxHeader::runMarker) {
            count = color - PcxHeader::runMarker;
            if (source >= palette) WorldDiagnostics::fail("Truncated font image run");
            color = image[source++];
        }
        if (count > mask.size() - destination) WorldDiagnostics::fail("Font image run exceeds its dimensions");
        const auto entry = palette + std::size_t(color) * 3;
        const auto white = image[entry] > 240 && image[entry + 1] > 240 && image[entry + 2] > 240;
        std::fill_n(mask.begin() + destination, count, white ? 1u : 0u);
        destination += count;
    }
    const auto language = SferaClientApplication::language;
    const auto mappingPath = language == 0 || language == 1 ? std::string("fonts\\font.txt") : std::string("fonts\\font") + language_suffix + ".txt";
    const auto mappingBytes = g_sfera_files.readAll(mappingPath);
    const auto mapping = SferaText::fromBytes(mappingBytes);
    std::array<SferaFontGlyphRuntime, 256> placements{};
    std::array<std::uint32_t, 256> widths{};
    std::array<std::uint16_t, atlasWidth * atlasWidth> pixels{};
    std::vector<Microsoft::WRL::ComPtr<IDirect3DTexture9>> pages;
    auto& graphics = *g_sfera_graphics_runtime.d3d_runtime;
    const auto upload = [&]() {
        Microsoft::WRL::ComPtr<IDirect3DTexture9> texture;
        graphics.checkResult(graphics.native_device->CreateTexture(atlasWidth, atlasWidth, 1, 0,
            D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, texture.GetAddressOf(), nullptr), "CreateTexture(font)");
        TextureMapping mapping(texture.Get());
        graphics.checkResult(mapping.status(), "LockRect(font)");
        graphics.checkResult(mapping.copyRows(std::as_bytes(std::span(pixels)), atlasWidth * sizeof(pixels[0]),
            atlasWidth), "Upload font pixels");
        graphics.checkResult(mapping.unlock(), "UnlockRect(font)");
        pages.push_back(std::move(texture));
        pixels.fill(0);
    };
    std::size_t symbols = 0;
    int firstRow = sourceCell;
    int lastRow = -1;
    for (std::size_t position = 0; (position = mapping.find('#', position)) != std::string_view::npos;) {
        auto end = position;
        while (end != 0 && mapping[end - 1] == ' ') --end;
        if (end < 2 || mapping[end - 2] < 'A' || mapping[end - 2] > 'Z' || mapping[end - 1] < '0' || mapping[end - 1] > '9') WorldDiagnostics::fail("wrong format of font1.txt");
        const auto sourceX = 20 + sourceCell * (mapping[end - 1] - '0');
        const auto sourceY = 20 + sourceCell * (mapping[end - 2] - 'A');
        ++position;
        while (position < mapping.size() && mapping[position] == ' ') ++position;
        if (position + 1 >= mapping.size() || mapping[position] != '\'') WorldDiagnostics::fail("wrong format of font1.txt");
        const std::uint8_t character = mapping[position + 1];
        position += 2;
        if (position < mapping.size() && mapping[position] == '\'') ++position;
        if (sourceX + sourceCell > sourceWidth || sourceY + sourceCell > height || symbols >= 256u * 64u) WorldDiagnostics::fail("Font glyph is outside its image");
        std::array<std::uint8_t, atlasCell * atlasCell> glyph{};
        std::array<std::uint8_t, atlasCell * atlasCell> shadow{};
        std::uint32_t rightmost = 0;
        for (std::size_t y = 0; y < sourceCell; ++y) for (std::size_t x = 0; x < sourceCell; ++x) {
            if (mask[(sourceY + y) * sourceWidth + sourceX + x] == 0) continue;
            glyph[(y + 3) * atlasCell + x + 3] = 1;
            rightmost = std::max(rightmost, static_cast<std::uint32_t>(x + 1));
            firstRow = std::min(firstRow, static_cast<int>(y));
            lastRow = std::max(lastRow, static_cast<int>(y));
            for (int dy = 0; dy <= outline; ++dy) for (int dx = 0; dx <= outline; ++dx) {
                const bool corner = (dx == -outline || dx == outline) && (dy == -outline || dy == outline);
                if (outline == 1 || !corner) shadow[(y + 3 + dy) * atlasCell + x + 3 + dx] = 1;
            }
        }
        const auto tileX = symbols % 8 * atlasCell;
        const auto tileY = symbols / 8 % 8 * atlasCell;
        for (std::size_t y = 0; y < atlasCell; ++y) for (std::size_t x = 0; x < atlasCell; ++x) pixels[(tileY + y) * atlasWidth + tileX + x] = glyph[y * atlasCell + x] ? std::numeric_limits<std::uint16_t>::max() : shadow[y * atlasCell + x] ? SferaColor::rgba(0u, 0u, 0u, 240u).argb4444() : 0u;
        widths[character] = rightmost == 0 ? emptyWidth : rightmost;
        placements[character] = {static_cast<std::uint32_t>(symbols / 64), static_cast<float>(tileX + 3 - outline) / atlasWidth, static_cast<float>(tileY + 3 - outline) / atlasWidth, true};
        if (++symbols % 64 == 0) upload();
    }
    if (placements[124].defined == 0) WorldDiagnostics::fail("Symbol for CODE_FOR_UNDIFINED_SYMBOL is not found in font.txt");
    if (lastRow < firstRow) WorldDiagnostics::fail("Font contains no visible glyphs");
    if (symbols % 64 != 0) upload();
    Face replacement;
    replacement.widths = widths;
    replacement.pages = std::move(pages);
    replacement.span = lastRow - firstRow + 3;
    replacement.origin = firstRow;
    replacement.cell_step = 20 - firstRow;
    replacement.code_base = spacing;
    faces[font] = std::move(replacement);
    std::copy(placements.begin(), placements.end(), std::begin(glyphs));
}

std::string_view SphereUI::Runtime::keyName(std::uint32_t code) {
    static const auto names = [] {
        std::array<std::string, 256> result{};
        for (const auto& binding : uiKeyBindings) result[binding.code] = binding.name;
        constexpr std::string_view printable = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (std::size_t index = 0; index < printable.size(); ++index)
            result[printable[index]].assign(printable.substr(index, 1u));
        for (std::size_t index = 0u; index != 12u; ++index) result[VK_F1 + index] = "F" + std::to_string(index + 1u);
        for (std::size_t index = 0u; index != 10u; ++index) result[VK_NUMPAD0 + index] = "NUMPAD" + std::to_string(index);
        return result;
    }();
    return code < names.size() ? std::string_view(names[code]) : std::string_view{};
}
std::uint32_t SphereUI::Runtime::scanCode(std::uint32_t key) {
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
            std::string_view keys;
            std::uint32_t first_scan;
        };

        static constexpr Row rows[] = { {
            "QWERTYUIOP", 16u
        }, {"ASDFGHJKL", 30u}, {"ZXCVBNM", 44u}};
        for (const auto& row : rows) {
            const auto position = std::find(row.keys.begin(), row.keys.end(), key);
            if (position != row.keys.end()) return row.first_scan + static_cast<std::uint32_t>(position - row.keys.begin());
        }
        for (const auto& binding : uiKeyBindings) if (binding.code == key) return binding.scan;
        return 0u;
    }
std::uint32_t SphereUI::Runtime::virtualKey(std::uint32_t scan) {
        for (std::size_t key = 0u; key <= 255u; ++key) if (SphereUI::Runtime::scanCode(key) == scan) return key;
        return 0u;
    }
void SphereUI::Runtime::setSystemCursorVisible(bool visible) { if (visible) { while (::ShowCursor(TRUE) < 0) {} } else { while (::ShowCursor(FALSE) >= 0) {} } }
namespace {
bool cursor_uses_center_clip(std::uint32_t kind) { const auto name = sfera_cursor_texture_name(kind); return !name.empty() && name.front() != '_'; }
}
CHardwareCursor::CHardwareCursor() { SphereUI::Runtime::setSystemCursorVisible(false); }
CHardwareCursor::~CHardwareCursor() {
    if (clip_enabled) ::ClipCursor(nullptr);
    if (::GetCursor() == cursor_handle.get()) ::SetCursor(nullptr);
}
void CHardwareCursor::copyStateFrom(const CCursor* previous) { SferaCursorPosition position{}; if (previous != nullptr) { saved_system_visible = previous->isSystemCursorVisible() ? 1u : 0u; kind = previous->cursorKind(); previous->getPosition(&position); } else { saved_system_visible = true; kind = 255u; getPosition(&position); } saved_x = position.x; saved_y = position.y; }
void CHardwareCursor::activate() { setSystemCursorVisible(saved_system_visible); setCursorKind(kind); setPosition(saved_x, saved_y); }
void CHardwareCursor::deactivate() {
    if (std::exchange(clip_enabled, false)) ::ClipCursor(nullptr);
    SphereUI::Runtime::setSystemCursorVisible(false);
}
void CHardwareCursor::apply() { ::SetCursor(cursor_handle.get()); }
void CHardwareCursor::updatePosition() {}
SferaCursorPosition* CHardwareCursor::getPosition(SferaCursorPosition* output) const { if (output == nullptr) return nullptr; if (SferaClientApplication::application_active) { POINT point{}; ::GetCursorPos(&point); ::ScreenToClient(SferaClientApplication::main_window, &point); output->x = point.x; output->y = point.y; } else { output->x = g_sfera_graphics_runtime.display_width / 2; output->y = g_sfera_graphics_runtime.display_height / 2; } return output; }
void CHardwareCursor::setPosition(int x, int y) { if (!SferaClientApplication::application_active) return; POINT point{static_cast<LONG>(x), static_cast<LONG>(y)}; ::ClientToScreen(SferaClientApplication::main_window, &point); ::SetCursorPos(point.x, point.y); }
void CHardwareCursor::show() {
    const bool enabled = cursor_uses_center_clip(kind) && SferaClientApplication::application_active;
    if (clip_enabled == enabled) return;
    if (enabled) {
        POINT point{static_cast<LONG>(g_sfera_graphics_runtime.display_width / 2u), static_cast<LONG>(g_sfera_graphics_runtime.display_height / 2u)};
        ::ClientToScreen(SferaClientApplication::main_window, &point);
        const RECT rectangle{point.x, point.y, point.x + 1, point.y + 1};
        clip_enabled = ::ClipCursor(&rectangle) != FALSE;
    } else { ::ClipCursor(nullptr); clip_enabled = false; }
}
bool CHardwareCursor::isInsideViewport() const { SferaCursorPosition position{}; getPosition(&position); return position.x >= 0 && position.x < g_sfera_graphics_runtime.display_width && position.y >= 0 && position.y < g_sfera_graphics_runtime.display_height; }
bool CHardwareCursor::isSystemCursorVisible() const {
    CURSORINFO cursor{sizeof(CURSORINFO)};
    return ::GetCursorInfo(&cursor) && (cursor.flags & CURSOR_SHOWING) != 0;
}
void CHardwareCursor::setSystemCursorVisible(bool visible) { SphereUI::Runtime::setSystemCursorVisible(visible); }
std::uint32_t CHardwareCursor::cursorKind() const { return kind; }
void CHardwareCursor::setCursorKind(std::uint32_t new_kind) {
    const auto name = sfera_cursor_texture_name(new_kind);
    if (name.empty()) {
        ::SetCursor(nullptr);
        cursor_handle.reset();
        kind = new_kind; texture_width = texture_height = 0u;
        show(); apply();
        return;
    }
    struct BitmapDeleter { void operator()(HBITMAP bitmap) const noexcept { if (bitmap) ::DeleteObject(bitmap); } };
    using BitmapOwner = std::unique_ptr<std::remove_pointer_t<HBITMAP>, BitmapDeleter>;
    const std::string relative_path = std::string("textures\\cursors\\") + std::string(name) + ".bmp";
    BitmapOwner color;
    for (const auto& path : g_sfera_files.candidatePaths(relative_path, true)) {
        color.reset(static_cast<HBITMAP>(::LoadImageA(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION)));
        if (color) break;
    }
    if (!color) throw std::runtime_error("CreateCursor(): failed to load cursor image from file");
    BITMAP bitmap{};
    if (::GetObjectA(color.get(), sizeof(bitmap), &bitmap) == 0 || bitmap.bmWidth != 32 ||
        bitmap.bmHeight != 32 || bitmap.bmBitsPixel != 32 || bitmap.bmBits == nullptr)
        throw std::runtime_error("CreateCursor(): invalid cursor image format");
    const std::size_t mask_stride = (static_cast<std::size_t>(bitmap.bmWidth) + 15u) / 16u * 2u;
    std::vector<std::uint8_t> mask_bits(mask_stride * static_cast<std::size_t>(bitmap.bmHeight), 0u);
    const auto* pixels = static_cast<const std::uint32_t*>(bitmap.bmBits);
    for (LONG y = 0; y < bitmap.bmHeight; ++y) for (LONG x = 0; x < bitmap.bmWidth; ++x)
        if (SferaColor::fromArgb(pixels[static_cast<std::size_t>(y) * bitmap.bmWidth + x]).alpha() == 0u)
            mask_bits[static_cast<std::size_t>(y) * mask_stride + static_cast<std::size_t>(x) / 8u] |= static_cast<std::uint8_t>(1u << (7 - x % 8));
    BitmapOwner mask(::CreateBitmap(bitmap.bmWidth, bitmap.bmHeight, 1u, 1u, mask_bits.data()));
    if (!mask) throw std::runtime_error("CreateCursor(): failed to create cursor mask");
    const bool centered = cursor_uses_center_clip(new_kind);
    ICONINFO info{};
    info.fIcon = FALSE;
    info.xHotspot = centered ? static_cast<DWORD>(bitmap.bmWidth / 2) : 0u;
    info.yHotspot = centered ? static_cast<DWORD>(bitmap.bmHeight / 2) : 0u;
    info.hbmMask = mask.get(); info.hbmColor = color.get();
    CursorOwner replacement(static_cast<HCURSOR>(::CreateIconIndirect(&info)));
    if (!replacement) throw std::runtime_error("CreateCursor(): failed to create cursor");
    // Select the new cursor before releasing the old handle borrowed by Win32.
    ::SetCursor(replacement.get());
    cursor_handle = std::move(replacement);
    kind = new_kind;
    texture_width = static_cast<std::uint32_t>(bitmap.bmWidth);
    texture_height = static_cast<std::uint32_t>(bitmap.bmHeight);
    show();
}
CSoftwareCursor::CSoftwareCursor() { x = g_sfera_graphics_runtime.display_width / 2; y = g_sfera_graphics_runtime.display_height / 2; }
void CSoftwareCursor::copyStateFrom(const CCursor* previous) { if (previous != nullptr) { SferaCursorPosition position{}; saved_system_visible = previous->isSystemCursorVisible() ? 1u : 0u; saved_kind = previous->cursorKind(); previous->getPosition(&position); saved_x = position.x; saved_y = position.y; } else { saved_system_visible = true; saved_kind = 255u; saved_x = g_sfera_graphics_runtime.display_width / 2; saved_y = g_sfera_graphics_runtime.display_height / 2; } }
void CSoftwareCursor::activate() { if (auto* mouse = g_sfera_direct_input_runtime.mouse_device.Get()) { mouse->Unacquire(); const HRESULT result = mouse->SetCooperativeLevel(SferaClientApplication::main_window, DISCL_EXCLUSIVE | DISCL_FOREGROUND); if (FAILED(result)) { SferaClientApplication::terminateWithError("CSoftwareCursor::Activate(): SetCooperativeLevel() failed"); } mouse->Acquire(); } setSystemCursorVisible(saved_system_visible); setCursorKind(saved_kind); setPosition(saved_x, saved_y); }
void CSoftwareCursor::deactivate() { if (auto* mouse = g_sfera_direct_input_runtime.mouse_device.Get()) { mouse->Unacquire(); const HRESULT result = mouse->SetCooperativeLevel(SferaClientApplication::main_window, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND); if (FAILED(result)) { SferaClientApplication::terminateWithError("CSoftwareCursor::Deactivate(): SetCooperativeLevel() failed"); } mouse->Acquire(); } setSystemCursorVisible(true); setCursorKind(255u); }
void CSoftwareCursor::apply() {}
void CSoftwareCursor::updatePosition() { if (!active) return; x += static_cast<int>(std::trunc(static_cast<double>(g_sfera_direct_input_runtime.mouse.dx) * 1.5)); y += static_cast<int>(std::trunc(static_cast<double>(g_sfera_direct_input_runtime.mouse.dy) * 1.5)); }
SferaCursorPosition* CSoftwareCursor::getPosition(SferaCursorPosition* output) const { if (output == nullptr) return nullptr; output->x = x; output->y = y; return output; }
void CSoftwareCursor::setPosition(int new_x, int new_y) { x = new_x; y = new_y; }
void CSoftwareCursor::show() { const int width = g_sfera_graphics_runtime.display_width; const int height = g_sfera_graphics_runtime.display_height; auto* mouse = g_sfera_direct_input_runtime.mouse_device.Get(); if (active) { const bool outside = x < 0 || x >= width || y < 0 || y >= height; if (outside || !SferaClientApplication::application_active) { if (!cursor_uses_center_clip(cursorKind())) { if (mouse != nullptr) mouse->Unacquire(); SphereUI::Runtime::setSystemCursorVisible(true); POINT point{x, y}; ::ClientToScreen(SferaClientApplication::main_window, &point); ::SetCursorPos(point.x, point.y); active = false; } } if (width > 0) x = std::clamp(x, 0, width - 1); if (height > 0) y = std::clamp(y, 0, height - 1); return; } POINT point{}; ::GetCursorPos(&point); ::ScreenToClient(SferaClientApplication::main_window, &point); if (point.x < 0 || point.x >= width || point.y < 0 || point.y >= height || !SferaClientApplication::application_active) return; x = point.x; y = point.y; SphereUI::Runtime::setSystemCursorVisible(false); if (mouse != nullptr) mouse->Acquire(); active = true; }
bool CSoftwareCursor::isInsideViewport() const { return active; }
bool CSoftwareCursor::isSystemCursorVisible() const { const auto* state = g_sfera_interface.cursor.get(); return state != nullptr && state->system_visible; }
void CSoftwareCursor::setSystemCursorVisible(bool visible) { if (auto* state = g_sfera_interface.cursor.get()) state->system_visible = visible ? 1u : 0u; }
std::uint32_t CSoftwareCursor::cursorKind() const { const auto* state = g_sfera_interface.cursor.get(); return state == nullptr ? 255u : state->kind; }
void CSoftwareCursor::setCursorKind(std::uint32_t new_kind) {
    auto* state = g_sfera_interface.cursor.get();
    if (state != nullptr) state->setKind(new_kind);
    texture_width = 0u;
    texture_height = 0u;
    const auto name = sfera_cursor_texture_name(new_kind);
    if (name.empty()) return;
    const int index = g_sfera_textures.find(name);
    if (index < 0) return;
    const auto extent = g_sfera_textures.size(index);
    texture_width = extent.width;
    texture_height = extent.height;
}

