#include "semantic_window.h"
#include "semantic_classes.h"
#include "native_callbacks.h"
#include "semantic_static.h"
#include "import_bridge.h"
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
#include <exdisp.h>
#include <sys/stat.h>
namespace {
    constexpr std::uint32_t invalidIndex = 4294967295u;
    constexpr std::uint32_t inheritFont = 4294967295u;
    constexpr std::uint32_t anyControlKind = 2147483647u;
    constexpr std::uint32_t maximumScrollOffset = 2147483647u;
    constexpr std::uint32_t missingConfigValue = 4294967295u;
    constexpr std::uint32_t noSoundIdleTimestamp = 4294967295u;
    constexpr std::uint32_t packedFieldMask = 65535u;
    constexpr std::uint32_t dragDropStateMask = 255u;
    constexpr std::uint32_t alphaProductHighByteMask = 65280u;
    constexpr std::uint32_t kRgbColorMask = 16777215u;
    namespace UiControlKind = SphereUI::UiControlKind;

    namespace UiColor {
        constexpr std::uint32_t white = 0xffffffffu;
        constexpr std::uint32_t opaqueBlack = 0xff000000u;
        constexpr std::uint32_t whiteRgb = 0x00ffffffu;
        constexpr std::uint32_t alphaMask = 0xff000000u;
        constexpr std::uint32_t frameBackground = 0x00282420u;
        constexpr std::uint32_t tooltipBackground = 0x00ffffe1u;
        constexpr std::uint32_t listSelection = 0x32000000u;
        constexpr std::uint32_t slotFill = 0x00141414u;
        constexpr std::uint32_t slotBorder = 0xff9e7c6au;
        constexpr std::uint32_t slotRejected = 0x00821c1bu;
        constexpr std::uint32_t slotAccepted = 0x00366425u;
        constexpr std::uint32_t hyperLink = 0xffff0000u;
        constexpr std::uint32_t hyperLinkHover = 0xffffff00u;
    }

    namespace UiMessage = SphereUI::UiMessage;

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

namespace SphereUI {
    struct BrowserSurface {
        UnmanagedResourceTexture* texture_resource;
        std::int32_t width;
        std::int32_t height;
        std::int32_t texture_size;
        HDC device_context;
        HBITMAP bitmap;
        HGDIOBJ previous_bitmap;
    };

    struct BrowserSession {
        UiString url;
        HWND host_window;
        HWND document_window;
        std::uint8_t subclassed;
        std::uint8_t reserved[3];
        std::int32_t mouse_x;
        std::int32_t mouse_y;
        std::int32_t width;
        std::int32_t height;
        std::uint32_t buttons;
    };
}

namespace SphereUI::detail {
    // Copy at most capacity - 1 characters; even a truncated result is NUL-terminated.
    void copyText(std::span<char> destination, const char* source) {
        if (destination.empty()) return;
        std::size_t length = 0u;
        if (source != nullptr) while (length < destination.size() - 1u && source[length] != '\0') ++length;
        if (length != 0u) std::copy_n(source, length, destination.data());
        destination[length] = '\0';
    }

    void serializeHyperTextElements(const UiDeque<HyperTextElement*>& elements, UiString& hyper_text, UiString& plain);
    void escapeHyperText(UiString& output, const UiString& source);
    template<class Character> static Character* stringData(Character* storage, std::uint32_t capacity);
    static void assignString(char (&storage)[16], std::uint32_t& length, std::uint32_t& capacity, std::string_view value);
    static void releaseString(char (&storage)[16], std::uint32_t& length, std::uint32_t& capacity);
    template<class T> static void appendNode(UiListNode<T>*& sentinel, std::uint32_t& count, T value);
    template<class T> static void clearNodes(UiListNode<T>* sentinel);
    template<class T> static void copyNodes(UiListNode<T>*& destination, std::uint32_t& count, UiListNode<T>* source);
    std::uint32_t controlKind(const char* name);
    std::uint32_t animationKind(const char* name);
    std::uint32_t alignmentFlag(const char* name);
    std::int32_t addCoordinate(std::int32_t left, std::int32_t right) {
        return static_cast<std::int32_t>(static_cast<std::uint32_t>(left) + static_cast<std::uint32_t>(right));
    }

    std::int32_t subtractCoordinate(std::int32_t left, std::int32_t right) {
        return static_cast<std::int32_t>(static_cast<std::uint32_t>(left) - static_cast<std::uint32_t>(right));
    }

    template <class Callback> static void forEachChild(const Window& window, Callback callback) {
        auto* sentinel = window.child_sentinel;
        if (sentinel == nullptr) return;
        for (auto* node = sentinel->next; node != nullptr && node != sentinel; node = node->next) if (auto* child = node->value) callback(*child);
    }
}

namespace SphereUI::Runtime {
    void clipboardText(UiString& result);
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

    Window* makeControl(std::uint32_t kind);
    static std::uint32_t keyCode(const char* name);
    static BrowserSurface* createBrowserSurface(std::int32_t width, std::int32_t height);
    static void destroyBrowserSurface(BrowserSurface* surface);
    static BrowserSession* createBrowserSession(const char* url, std::int32_t width, std::int32_t height);
    static void destroyBrowserSession(BrowserSession* session);
    static void browserNavigate(BrowserSession& session, const char* url);
    static void browserRefresh(BrowserSession& session);
    static void browserLocation(BrowserSession& session, char* buffer, std::uint32_t capacity);
    static void browserMouse(BrowserSession& session, std::uint32_t message, std::int32_t x, std::int32_t y, std::int32_t wheel = 0);
    static void browserPaint(BrowserSession& session, BrowserSurface& surface);
    static void focusMainWindow();

    void broadcastMessage(Window* root, std::int32_t group, std::uint32_t message, std::uint32_t first, std::uint32_t second, std::uint32_t kind);
    void* allocate(std::size_t size);
    static std::int32_t findImage(const char* name);
    void deallocate(void* memory);
    static void playClickSound();
    static void playScrollSound(bool page);
    static std::uint64_t clockTicks();
}

namespace SphereUI::Runtime {
    void invokeEventHandler(WindowEventHandler handler, Window* window, const WindowEvent& event);
}

namespace SphereUI::detail {
    template<class Character> Character* stringData(Character* storage, std::uint32_t capacity) {
        if (capacity < 16u) return storage;
        Character* text = nullptr;
        std::memcpy(&text, storage, sizeof(text));
        return text;
    }

    void assignString(char (&storage)[16], std::uint32_t& length, std::uint32_t& capacity, std::string_view value) {
        if (value.size() > std::numeric_limits<std::uint32_t>::max() - 1u) throw std::length_error("UI string too long");
        if (capacity < 15u) capacity = 15u;
        auto* destination = stringData(storage, capacity);
        if (value.size() > capacity) {
            const auto new_capacity = static_cast<std::uint32_t>(value.size()) | 15u;
            auto* memory = static_cast<char*>(Runtime::allocate(static_cast<std::size_t>(new_capacity) + 1u));
            if (memory == nullptr) throw std::bad_alloc();
            if (!value.empty()) std::memcpy(memory, value.data(), value.size());
            memory[value.size()] = '\0';
            if (capacity >= 16u) Runtime::deallocate(destination);
            std::memcpy(storage, &memory, sizeof(memory));
            capacity = new_capacity;
        } else {
            if (!value.empty()) std::memmove(destination, value.data(), value.size());
            destination[value.size()] = '\0';
        }
        length = static_cast<std::uint32_t>(value.size());
    }

    void releaseString(char (&storage)[16], std::uint32_t& length, std::uint32_t& capacity) {
        if (capacity >= 16u) Runtime::deallocate(stringData(storage, capacity));
        storage[0] = '\0';
        length = 0u;
        capacity = 15u;
    }

    template<class T> void appendNode(UiListNode<T>*& sentinel, std::uint32_t& count, T value) {
        if (count >= std::numeric_limits<std::uint32_t>::max() / sizeof(T) - 1u) throw std::length_error("UI list too long");
        if (sentinel == nullptr) {
            sentinel = static_cast<UiListNode<T>*>(Runtime::allocate(sizeof(UiListNode<T>)));
            if (sentinel == nullptr) throw std::bad_alloc();
            *sentinel = {sentinel, sentinel, {}};
        }
        auto* node = static_cast<UiListNode<T>*>(Runtime::allocate(sizeof(UiListNode<T>)));
        if (node == nullptr) throw std::bad_alloc();
        *node = {sentinel, sentinel->previous, value};
        sentinel->previous->next = node;
        sentinel->previous = node;
        ++count;
    }

    template<class T> void clearNodes(UiListNode<T>* sentinel) {
        if (sentinel == nullptr) return;
        auto* node = sentinel->next;
        while (node != nullptr && node != sentinel) {
            auto* next = node->next;
            Runtime::deallocate(node);
            node = next;
        }
        sentinel->next = sentinel->previous = sentinel;
    }

    template<class T> void copyNodes(UiListNode<T>*& destination, std::uint32_t& count, UiListNode<T>* source) {
        if (destination == source) return;
        clearNodes(destination);
        count = 0u;
        if (source != nullptr) for (auto* node = source->next; node != nullptr && node != source; node = node->next) appendNode(destination, count, node->value);
    }

    namespace {
        struct NamedValue {
            const char* name;
            std::uint32_t value;
        };

        template<std::size_t Size> std::uint32_t lookup(const char* name, const NamedValue (&values)[Size], std::uint32_t fallback) {
            for (const auto& entry : values) if (SferaSimpleParser::equalsIgnoreCase(name, entry.name)) return entry.value;
            return fallback;
        }
    }

    std::uint32_t controlKind(const char* name) {
        constexpr NamedValue values[] = { {
            "BUTTON", UiControlKind::button
        }, {"TEXT", UiControlKind::text}, {"IMAGE", UiControlKind::image}, {"PROGRESS_BAR", UiControlKind::progressBar}, {"SCROLL_BAR", UiControlKind::scrollBar}, {"HYPER_TEXT", UiControlKind::hyperText}, {"CHECKBOX", UiControlKind::checkBox}, {"RADIOBUTTON", UiControlKind::radioButton}, {"TEXTLIST", UiControlKind::textList}, {"SLIDER", UiControlKind::slider}, {"LISTITEM", UiControlKind::listItem}, {"EDIT", UiControlKind::edit}, {"SLOT", UiControlKind::slot}, {"SPINBUTTON", UiControlKind::spinButton}, {"RICHEDIT", UiControlKind::richEdit}, {"FILTERLISTCTRL", UiControlKind::filteredList}, {"WEBBROWSER", UiControlKind::webBrowser}, {"MINIMAP", UiControlKind::minimap}, {"MENULISTCTRL", UiControlKind::menu}, {"HTCHATLISTCTRL", UiControlKind::hyperTextChat}, {"HTEDIT", UiControlKind::hyperTextEdit}, {"FONTPICKER", UiControlKind::fontPicker}, {"COLORPICKER", UiControlKind::colorPicker}};
        return lookup(name, values, anyControlKind);
    }

    std::uint32_t animationKind(const char* name) {
        constexpr NamedValue values[] = { {
            "ALPHA_IN", 1u
        }, {"ALPHA_OUT", 2u}, {"MOVE_LEFT", 3u}, {"MOVE_RIGHT", 4u}, {"MOVE_TOP", 5u}, {"MOVE_BOTTOM", 6u}};
        return lookup(name, values, 0u);
    }

    std::uint32_t alignmentFlag(const char* name) {
        constexpr NamedValue values[] = { {
            "LEFT_X", 2u
        }, {"CENTER_X", 4u}, {"RIGHT_X", 8u}, {"LEFT_Y", 16u}, {"CENTER_Y", 32u}, {"RIGHT_Y", 64u}};
        return lookup(name, values, 0u);
    }
}
// Empty C++ constructors remain vtable-only ABI operations.
void SphereUI::Window::initialize() {
    std::fill(std::begin(name), std::end(name), 0);
    name_length = {};
    name_capacity = {};
    name_storage_context = {};
    behavior_flags = {};
    width = {};
    height = {};
    x = {};
    y = {};
    alignment_flags = {};
    group = {};
    initial_x = {};
    initial_y = {};
    hidden = {};
    disabled = {};
    input_enabled = {};
    is_reference = {};
    can_drag_drop = {};
    can_go_top = {};
    save_last_position = {};
    hit_transparent = {};
    control_kind = {};
    std::fill(std::begin(text), std::end(text), 0);
    text_length = {};
    text_capacity = {};
    text_storage_context = {};
    std::fill(std::begin(help), std::end(help), 0);
    help_length = {};
    help_capacity = {};
    help_storage_context = {};
    font = {};
    font_initialized = {};
    font_attributes = {};
    text_color = {};
    text_state = {};
    disabled_color = {};
    parent = {};
    child_sentinel = {};
    child_count = {};
    child_storage_context = {};
    reference_sentinel = {};
    reference_count = {};
    reference_storage_context = {};
    modal_owner = {};
    event_proxy = {};
    event_slots = {};
    event_capacity = {};
    event_head = {};
    event_size = {};
    event_storage_context = {};
    pending_event_count = {};
    control_id = {};
    alpha = {};
    animation_active = {};
    animation_state = {};
    animation_reserved = {};
    text_offset_x = {};
    text_offset_y = {};
    tooltip = {};
    overlay = {};
    resource_parent = {};
    event_handler_token = {};
    caption_left = {};
    caption_top = {};
    caption_right = {};
    caption_bottom = {};
    dragging = {};
    std::fill(std::begin(drag_reserved), std::end(drag_reserved), 0);
    drag_offset_x = {};
    drag_offset_y = {};
    input_mask = {};
    hide_after_animation = {};
    std::fill(std::begin(hide_reserved), std::end(hide_reserved), 0);
    show_animation = {};
    hide_animation = {};
    active_animation = {};
    resource_list = {};
    std::fill(std::begin(resource_name), std::end(resource_name), 0);
    resource_name_length = {};
    resource_name_capacity = {};
    resource_name_storage_context = {};
    resource_reference = {};
    name_capacity = text_capacity = help_capacity = resource_name_capacity = 15u;
    hidden = 1u;
    can_go_top = save_last_position = font_initialized = 1u;
    text_color = UiColor::white;
    disabled_color = UiColor::opaqueBlack;
    alpha = 255u;
    auto initialize_list = [](SferaWindowChildNode*& destination) {
        auto* sentinel = static_cast<SferaWindowChildNode*>(Runtime::allocate(sizeof(SferaWindowChildNode)));
        if (sentinel == nullptr) throw std::bad_alloc();
        destination = sentinel;
        *sentinel = {destination, destination, 0u};
    };
    initialize_list(child_sentinel);
    initialize_list(reference_sentinel);
    auto* proxy = static_cast<UiContainerProxy*>(Runtime::allocate(sizeof(UiContainerProxy)));
    if (proxy == nullptr) throw std::bad_alloc();
    event_proxy = proxy;
    proxy->owner = &event_proxy;
    proxy->first_iterator = nullptr;
    g_sfera_interface.unbindEventHandler(this);
    g_sfera_interface.registerWindow(*this);
}
// Owning containers copy their contents, not their allocations.
SphereUI::Window& SphereUI::Window::copyStateFrom(const Window& source) {
    return copyStateFrom(source, true);
}

SphereUI::Window& SphereUI::Window::copyStateFrom(const Window& source, bool copy_children) {
    if (this == &source) return *this;
    setName(detail::stringData(source.name, source.name_capacity));
    setText(source.getText());
    setHelp(source.getHelp());
    setResourceName(detail::stringData(source.resource_name, source.resource_name_capacity));
    behavior_flags = source.behavior_flags;
    width = source.width;
    height = source.height;
    x = source.x;
    y = source.y;
    alignment_flags = source.alignment_flags;
    group = source.group;
    initial_x = source.initial_x;
    initial_y = source.initial_y;
    hidden = source.hidden;
    disabled = source.disabled;
    input_enabled = source.input_enabled;
    is_reference = copy_children ? source.is_reference : 1u;
    can_drag_drop = source.can_drag_drop;
    can_go_top = source.can_go_top;
    save_last_position = source.save_last_position;
    hit_transparent = source.hit_transparent;
    control_kind = source.control_kind;
    font = source.font;
    font_initialized = source.font_initialized;
    text_color = source.text_color;
    text_state = source.text_state;
    disabled_color = source.disabled_color;
    parent = source.parent;
    modal_owner = source.modal_owner;
    control_id = source.control_id;
    alpha = source.alpha;
    animation_active = source.animation_active;
    animation_state = source.animation_state;
    text_offset_x = source.text_offset_x;
    text_offset_y = source.text_offset_y;
    tooltip = copy_children ? source.tooltip : 0u;
    overlay = source.overlay;
    resource_parent = source.resource_parent;
    event_handler_token = source.event_handler_token;
    caption_left = source.caption_left;
    caption_top = source.caption_top;
    caption_right = source.caption_right;
    caption_bottom = source.caption_bottom;
    dragging = source.dragging;
    drag_offset_x = source.drag_offset_x;
    drag_offset_y = source.drag_offset_y;
    input_mask = source.input_mask;
    hide_after_animation = source.hide_after_animation;
    active_animation = source.active_animation == &source.show_animation ? &show_animation : source.active_animation == &source.hide_animation ? &hide_animation : source.active_animation;
    resource_list = source.resource_list;
    resource_reference = source.resource_reference;
    show_animation = source.show_animation;
    hide_animation = source.hide_animation;
    if (copy_children) detail::copyNodes(child_sentinel, child_count, source.child_sentinel);
    detail::copyNodes(reference_sentinel, reference_count, source.reference_sentinel);
    clearEvents();
    const auto* slots = source.event_slots;
    for (std::uint32_t index = 0u; index < source.event_size; ++index) queueEvent(*slots[(source.event_head + index) % source.event_capacity]);
    pending_event_count = source.pending_event_count;
    g_sfera_interface.copyEventHandler(this, &source);
    return *this;
}

void SphereUI::Window::initializeCopy(const Window& source) {
    initialize();
    is_reference = 1u;
    try {
        copyStateFrom(source, false);
        is_reference = 1u;
        tooltip = 0u;
        if (source.active_animation == &source.show_animation) active_animation = &show_animation;
        if (source.active_animation == &source.hide_animation) active_animation = &hide_animation;
        detail::forEachChild(source, [&](Window& child) {
            if (auto* copy = child.clone()) {
                try {
                    appendChild(copy);
                } catch (...) {
                    copy->destroy(true);
                    throw;
                }
                copy->setParent(this);
            }
        });
        if (auto* original_tip = source.tooltip) if (auto* copy = original_tip->clone()) {
            tooltip = copy;
            copy->setParent(this);
        }
    } catch (...) {
        is_reference = 1u;
        throw;
    }
}

void SphereUI::Window::appendChild(Window* child) {
    detail::appendNode(child_sentinel, child_count, child);
}

void SphereUI::Window::appendResource(UiSprite* resource) {
    auto* resources = resource_list;
    if (resources == nullptr) {
        resources = static_cast<WindowResourceList*>(Runtime::allocate(sizeof(WindowResourceList)));
        if (resources == nullptr) throw std::bad_alloc();
        *resources = {};
        resource_list = resources;
    }
    detail::appendNode(resources->sentinel, resources->count, resource);
}

SphereUI::UiSprite* SphereUI::Window::findResource(const char* name_to_find) const {
    if (auto* ancestor = resource_parent) if (const auto resource = ancestor->findResource(name_to_find)) return resource;
    auto* resources = resource_list;
    if (resources == nullptr) return 0u;
    auto* sentinel = resources->sentinel;
    if (sentinel != nullptr) for (auto* node = sentinel->next; node != nullptr && node != sentinel; node = node->next) if (SferaSimpleParser::equalsIgnoreCase((node->value == nullptr ? nullptr : node->value->name), name_to_find)) return node->value;
    return 0u;
}

SphereUI::UiSprite* SphereUI::Window::getResource(const char* name_to_find) {
    if (const auto existing = findResource(name_to_find)) return existing;
    if (Runtime::findImage(name_to_find) == -1) return 0u;
    const auto sprite = UiSprite::create();
    if (sprite == 0u) return 0u;
    try {
        sprite->setImage(name_to_find);
        appendResource(sprite);
    } catch (...) {
        sprite->destroy();
        throw;
    }
    return sprite;
}

void SphereUI::Window::release() {
    if (is_reference == 0u) if (auto* resources = resource_list) {
        auto* sentinel = resources->sentinel;
        if (sentinel != nullptr) for (auto* node = sentinel->next; node != nullptr && node != sentinel; node = node->next) if (node->value != nullptr) node->value->destroy();
        detail::clearNodes(resources->sentinel);
        Runtime::deallocate(sentinel);
        Runtime::deallocate(resources);
        resource_list = 0u;
    }
    detail::forEachChild(*this, [](Window& child) {
        child.destroy(true);
    });
    detail::clearNodes(child_sentinel);
    child_count = 0u;
    if (auto* tip = tooltip) {
        tip->destroy(true);
        tooltip = 0u;
    }
    g_sfera_interface.unregisterWindow(*this);
    g_sfera_interface.unbindEventHandler(this);
    detail::releaseString(resource_name, resource_name_length, resource_name_capacity);
    if (auto* slots = event_slots) {
        for (std::uint32_t index = event_capacity; index != 0u; --index) Runtime::deallocate(slots[index - 1u]);
        Runtime::deallocate(slots);
    }
    event_slots = nullptr;
    event_capacity = 0u;
    clearEvents();
    Runtime::deallocate(event_proxy);
    event_proxy = 0u;
    detail::clearNodes(reference_sentinel);
    Runtime::deallocate(reference_sentinel);
    reference_sentinel = nullptr;
    reference_count = 0u;
    Runtime::deallocate(child_sentinel);
    child_sentinel = 0u;
    detail::releaseString(help, help_length, help_capacity);
    detail::releaseString(text, text_length, text_capacity);
    detail::releaseString(name, name_length, name_capacity);
}

namespace {
    template<class T> void reserveArray(T*& begin, T*& end, T*& capacity, std::uint32_t requested) {
        using namespace SphereUI;
        const auto maximum = static_cast<std::uint32_t>(std::numeric_limits<std::uint32_t>::max() / sizeof(T));
        if (requested > maximum) throw std::length_error("UI array too long");
        const auto available = begin == nullptr ? 0u : static_cast<std::uint32_t>(capacity - begin);
        if (requested <= available) return;
        const auto count = begin == nullptr ? 0u : static_cast<std::uint32_t>(end - begin);
        const auto grown = available > maximum - available / 2u ? maximum : available + available / 2u;
        const auto new_capacity = std::max(grown, requested);
        auto* memory = static_cast<T*>(Runtime::allocate(new_capacity * sizeof(T)));
        if (memory == nullptr) throw std::bad_alloc();
        if (count != 0u) std::copy_n(begin, count, memory);
        Runtime::deallocate(begin);
        begin = memory;
        end = memory + count;
        capacity = memory + new_capacity;
    }
}

template<class T> std::uint32_t SphereUI::UiVector<T>::size() const {
    return begin == nullptr ? 0u : static_cast<std::uint32_t>(end - begin);
}

template<class T> T& SphereUI::UiVector<T>::at(std::uint32_t index) {
    if (index >= size()) throw std::out_of_range("UI vector index");
    return begin[index];
}

template<class T> const T& SphereUI::UiVector<T>::at(std::uint32_t index) const {
    if (index >= size()) throw std::out_of_range("UI vector index");
    return begin[index];
}

template<class T> void SphereUI::UiVector<T>::reserve(std::uint32_t count) {
    reserveArray(begin, end, capacity, count);
}

template<class T> void SphereUI::UiVector<T>::append(const T& value) {
    const T copy = value;
    reserve(size() + 1u);
    *end++ = copy;
}

template<class T> void SphereUI::UiVector<T>::erase(std::uint32_t index) {
    const auto count = size();
    if (index >= count) return;
    std::move(begin + index + 1u, end, begin + index);
    --end;
}

template<class T> void SphereUI::UiVector<T>::clear() {
    end = begin;
}

template<class T> void SphereUI::UiVector<T>::release() {
    Runtime::deallocate(begin);
    begin = end = capacity = nullptr;
}

template<class T> void SphereUI::UiVector<T>::copyFrom(const UiVector& source) {
    if (this == &source) return;
    const auto count = source.size();
    reserve(count);
    if (count != 0u) std::copy_n(source.begin, count, begin);
    end = begin == nullptr ? nullptr : begin + count;
}

template struct SphereUI::UiVector<std::uint32_t>;
template struct SphereUI::UiVector<SphereUI::Window*>;
const char* SphereUI::UiString::data() const {
    return detail::stringData(storage, capacity);
}

void SphereUI::UiString::assign(const char* text) {
    detail::assignString(storage, length, capacity, text == nullptr ? "" : text);
}

void SphereUI::UiString::release() {
    detail::releaseString(storage, length, capacity);
}

std::uint32_t SphereUI::UiStringVector::size() const {
    return begin == nullptr ? 0u : static_cast<std::uint32_t>(end - begin);
}

SphereUI::UiString& SphereUI::UiStringVector::at(std::uint32_t index) {
    if (index >= size()) throw std::out_of_range("UI string index");
    return begin[index];
}

const SphereUI::UiString& SphereUI::UiStringVector::at(std::uint32_t index) const {
    if (index >= size()) throw std::out_of_range("UI string index");
    return begin[index];
}

void SphereUI::UiStringVector::append(const char* text) {
    insert(size(), text);
}

void SphereUI::UiStringVector::insert(std::uint32_t index, const char* text) {
    if (index > size()) throw std::out_of_range("UI string insertion");
    UiString value{};
    value.capacity = 15u;
    value.assign(text);
    try {
        const auto count = size();
        reserveArray(begin, end, capacity, count + 1u);
        std::move_backward(begin + index, end, end + 1u);
        begin[index] = value;
        ++end;
    } catch (...) {
        value.release();
        throw;
    }
}

void SphereUI::UiStringVector::erase(std::uint32_t index) {
    at(index).release();
    std::move(begin + index + 1u, end, begin + index);
    *--end = {};
}

void SphereUI::UiStringVector::clear() {
    const auto count = size();
    for (std::uint32_t index = 0u; index < count; ++index) at(index).release();
    end = begin;
}

void SphereUI::UiStringVector::release() {
    clear();
    Runtime::deallocate(begin);
    begin = end = capacity = nullptr;
}

void SphereUI::UiStringVector::copyFrom(const UiStringVector& source) {
    if (this == &source) return;
    UiStringVector copy{};
    try {
        for (std::uint32_t index = 0u; index < source.size(); ++index) copy.append(source.at(index).data());
    } catch (...) {
        copy.release();
        throw;
    }
    release();
    begin = copy.begin;
    end = copy.end;
    capacity = copy.capacity;
}

std::uint32_t SphereUI::UiTextRows::size() const {
    return begin == nullptr ? 0u : static_cast<std::uint32_t>(end - begin);
}

SphereUI::UiTextRow& SphereUI::UiTextRows::at(std::uint32_t index) {
    if (index >= size()) throw std::out_of_range("UI text row index");
    return begin[index];
}

const SphereUI::UiTextRow& SphereUI::UiTextRows::at(std::uint32_t index) const {
    if (index >= size()) throw std::out_of_range("UI text row index");
    return begin[index];
}

void SphereUI::UiTextRows::append(const char* text, std::uint32_t color, std::int32_t offset) {
    UiTextRow row{};
    row.text.capacity = 15u;
    row.text.assign(text);
    row.color = color;
    row.offset = offset;
    try {
        reserveArray(begin, end, capacity, size() + 1u);
        *end++ = row;
    } catch (...) {
        row.text.release();
        throw;
    }
}

void SphereUI::UiTextRows::erase(std::uint32_t index) {
    if (index >= size()) return;
    begin[index].text.release();
    std::move(begin + index + 1u, end, begin + index);
    --end;
}

void SphereUI::UiTextRows::clear() {
    for (std::uint32_t index = 0u; index < size(); ++index) at(index).text.release();
    end = begin;
}

void SphereUI::UiTextRows::release() {
    clear();
    Runtime::deallocate(begin);
    begin = end = capacity = nullptr;
}

void SphereUI::UiTextRows::copyFrom(const UiTextRows& source) {
    if (this == &source) return;
    UiTextRows copy{};
    try {
        for (std::uint32_t index = 0u; index < source.size(); ++index) {
            const auto& row = source.at(index);
            copy.append(row.text.data(), row.color, row.offset);
        }
    } catch (...) {
        copy.release();
        throw;
    }
    release();
    begin = copy.begin;
    end = copy.end;
    capacity = copy.capacity;
}

template<class T> std::uint32_t SphereUI::UiStringRecords<T>::size() const {
    return begin == nullptr ? 0u : static_cast<std::uint32_t>(end - begin);
}

template<class T> T& SphereUI::UiStringRecords<T>::at(std::uint32_t index) {
    if (index >= size()) throw std::out_of_range("UI record index");
    return begin[index];
}

template<class T> const T& SphereUI::UiStringRecords<T>::at(std::uint32_t index) const {
    if (index >= size()) throw std::out_of_range("UI record index");
    return begin[index];
}

template<class T> void SphereUI::UiStringRecords<T>::append(const T& value) {
    T copy = value;
    copy.text = {};
    copy.text.capacity = 15u;
    copy.text.assign(value.text.data());
    try {
        reserveArray(begin, end, capacity, size() + 1u);
        *end++ = copy;
    } catch (...) {
        copy.text.release();
        throw;
    }
}

template<class T> void SphereUI::UiStringRecords<T>::clear() {
    for (std::uint32_t index = 0u; index < size(); ++index) at(index).text.release();
    end = begin;
}

template<class T> void SphereUI::UiStringRecords<T>::release() {
    clear();
    Runtime::deallocate(begin);
    begin = end = capacity = nullptr;
}

template<class T> void SphereUI::UiStringRecords<T>::copyFrom(const UiStringRecords& source) {
    if (this == &source) return;
    UiStringRecords copy{};
    try {
        for (std::uint32_t index = 0u; index < source.size(); ++index) copy.append(source.at(index));
    } catch (...) {
        copy.release();
        throw;
    }
    release();
    begin = copy.begin;
    end = copy.end;
    capacity = copy.capacity;
}

template struct SphereUI::UiStringRecords<SphereUI::UiMenuItem>;
namespace {
    template<class T> constexpr std::uint32_t dequeBlockSize() {
        return sizeof(T) <= 1u ? 16u : sizeof(T) <= 2u ? 8u : sizeof(T) <= 4u ? 4u : sizeof(T) <= 8u ? 2u : 1u;
    }

    template<class T> void releaseDequeValue(T& value) {
        if constexpr (std::is_same_v<T, SphereUI::UiString> || std::is_same_v<T, SphereUI::HyperTextChatListItem>) value.release();
    }

    template<class T> T copyDequeValue(const T& value) {
        if constexpr (std::is_same_v<T, SphereUI::UiString>) {
            T copy{};
            copy.capacity = 15u;
            copy.assign(value.data());
            return copy;
        } else if constexpr (std::is_same_v<T, SphereUI::HyperTextChatListItem>) {
            T copy{};
            copy.copyFrom(value);
            return copy;
        } else return value;
    }

    template<class T> void growDeque(SphereUI::UiDeque<T>& deque) {
        constexpr std::uint32_t maximum_map_size = 134217728u;
        const auto old_size = deque.map_size;
        if (old_size >= maximum_map_size) throw std::length_error("UI deque too long");
        const auto new_size = old_size == 0u ? 8u : old_size * 2u;
        auto* replacement = static_cast<T**>(SphereUI::Runtime::allocate(new_size * sizeof(T*)));
        if (replacement == nullptr) throw std::bad_alloc();
        std::fill_n(replacement, new_size, nullptr);
        const auto first = deque.offset / dequeBlockSize<T>();
        for (std::uint32_t index = 0u; index < old_size; ++index) replacement[index] = deque.map[(first + index) & (old_size - 1u)];
        SphereUI::Runtime::deallocate(deque.map);
        deque.map = replacement;
        deque.map_size = new_size;
        deque.offset %= dequeBlockSize<T>();
    }
}

template<class T> void SphereUI::UiDeque<T>::initialize() {
    if (proxy != nullptr) return;
    proxy = static_cast<UiContainerProxy*>(Runtime::allocate(sizeof(UiContainerProxy)));
    if (proxy == nullptr) throw std::bad_alloc();
    *proxy = {this, nullptr};
}

template<class T> T& SphereUI::UiDeque<T>::at(std::uint32_t index) {
    if (index >= count) throw std::out_of_range("UI deque index");
    const auto position = offset + index;
    auto* block = map[(position / dequeBlockSize<T>()) & (map_size - 1u)];
    return block[position % dequeBlockSize<T>()];
}

template<class T> const T& SphereUI::UiDeque<T>::at(std::uint32_t index) const {
    return const_cast<UiDeque*>(this)->at(index);
}

template<class T> void SphereUI::UiDeque<T>::pushBack(const T& value) {
    T copy = copyDequeValue(value);
    try {
        initialize();
        if (static_cast<std::uint64_t>(offset % dequeBlockSize<T>()) + count + 1u > static_cast<std::uint64_t>(map_size) * dequeBlockSize<T>()) growDeque(*this);
        const auto position = offset + count;
        auto*& block = map[(position / dequeBlockSize<T>()) & (map_size - 1u)];
        if (block == nullptr) {
            block = static_cast<T*>(Runtime::allocate(dequeBlockSize<T>() * sizeof(T)));
            if (block == nullptr) throw std::bad_alloc();
            std::fill_n(block, dequeBlockSize<T>(), T{});
        }
        auto& destination = block[position % dequeBlockSize<T>()];
        destination = copy;
        if constexpr (std::is_same_v<T, HyperTextChatListItem>) if (destination.elements.proxy != nullptr) destination.elements.proxy->owner = &destination.elements;
        ++count;
    } catch (...) {
        releaseDequeValue(copy);
        throw;
    }
}

template<class T> void SphereUI::UiDeque<T>::popBack() {
    if (count == 0u) return;
    auto& value = at(count - 1u);
    releaseDequeValue(value);
    value = {};
    --count;
    if (count == 0u) offset = 0u;
}

template<class T> void SphereUI::UiDeque<T>::popFront() {
    if (count == 0u) return;
    auto& value = at(0u);
    releaseDequeValue(value);
    value = {};
    --count;
    offset = count == 0u ? 0u : (offset + 1u) & (map_size * dequeBlockSize<T>() - 1u);
}

template<class T> void SphereUI::UiDeque<T>::clear() {
    while (count != 0u) popBack();
}

template<class T> void SphereUI::UiDeque<T>::release() {
    clear();
    if (map != nullptr) for (std::uint32_t index = 0u; index < map_size; ++index) Runtime::deallocate(map[index]);
    Runtime::deallocate(map);
    Runtime::deallocate(proxy);
    proxy = nullptr;
    map = nullptr;
    map_size = offset = count = 0u;
}

template<class T> void SphereUI::UiDeque<T>::copyFrom(const UiDeque& source) {
    if (this == &source) return;
    UiDeque copy{};
    try {
        copy.initialize();
        for (std::uint32_t index = 0u; index < source.count; ++index) copy.pushBack(source.at(index));
    } catch (...) {
        copy.release();
        throw;
    }
    release();
    *this = copy;
    proxy->owner = this;
}

template struct SphereUI::UiDeque<SphereUI::UiString>;
template struct SphereUI::UiDeque<HyperTextElement*>;
void SphereUI::UiStringDeque::append(const char* text) {
    UiString value{};
    value.capacity = 15u;
    value.assign(text);
    try {
        pushBack(value);
    } catch (...) {
        value.release();
        throw;
    }
    value.release();
}

template struct SphereUI::UiDeque<SphereUI::HyperTextChatListItem>;
template<class T> void SphereUI::UiArray<T>::append(const T& value) {
    const T copy = value;
    const auto count = size();
    constexpr auto maximum = (std::numeric_limits<std::uint32_t>::max() / 4u) / sizeof(T);
    if (count >= maximum) throw std::length_error("UI array too long");
    if (end == capacity) {
        const auto next = std::max<std::uint32_t>(8u, count + count / 2u + 1u);
        auto* storage = static_cast<T*>(Runtime::allocate(next * sizeof(T)));
        if (storage == nullptr) throw std::bad_alloc();
        if (count != 0u) std::copy_n(begin, count, storage);
        Runtime::deallocate(begin);
        begin = storage;
        end = storage + count;
        capacity = storage + next;
    }
    *end++ = copy;
}

template<class T> void SphereUI::UiArray<T>::release() {
    Runtime::deallocate(begin);
    begin = end = capacity = nullptr;
}

template<class T> void SphereUI::UiArray<T>::copyFrom(const UiArray& source) {
    if (this == &source) return;
    UiArray copy{};
    try {
        for (std::uint32_t index = 0u; index < source.size(); ++index) copy.append(source.at(index));
    } catch (...) {
        copy.release();
        throw;
    }
    release();
    *this = copy;
}

template struct SphereUI::UiArray<SphereUI::UiIndexRange>;
HyperTextGeometry* HyperTextElement::geometry() {
    if (type == 4u) return &static_cast<HyperTextElement_PlainText*>(this)->bounds;
    if (type == 2u || type == 5u) return &static_cast<HyperTextElementWithParameters*>(this)->bounds;
    return nullptr;
}

const HyperTextGeometry* HyperTextElement::geometry() const {
    return const_cast<HyperTextElement*>(this)->geometry();
}

const char* HyperTextElement_Link::linkValue() const {
    const char* value = std::strstr(target.data(), "://");
    if (value == nullptr) return "";
    value += 3;
    if (*value == '/') ++value;
    return value;
}

void HyperTextElement::release() {
    if (type == 5u) static_cast<HyperTextElement_Link*>(this)->target.release();
    if (type == 2u || type == 5u) static_cast<HyperTextElementWithParameters*>(this)->parameters.release();
    text.release();
    SphereUI::Runtime::deallocate(this);
}

HyperTextElement* HyperTextElement::clone() const {
    HyperTextElement* result = nullptr;
    const auto create = []<class T>() {
        auto* memory = SphereUI::Runtime::allocate(sizeof(T));
        if (memory == nullptr) throw std::bad_alloc();
        std::memset(memory, 0, sizeof(T));
        return std::construct_at(static_cast<T*>(memory));
    };
    switch (type) {
        case 2u:
            result = create.operator()<HyperTextElementWithParameters>();
            break;
        case 3u:
            result = create.operator()<HyperTextElement_WordWrap>();
            break;
        case 4u:
            result = create.operator()<HyperTextElement_PlainText>();
            break;
        case 5u:
            result = create.operator()<HyperTextElement_Link>();
            break;
        default:
            result = create.operator()<HyperTextElement>();
            break;
    }
    result->type = type;
    try {
        result->text.assign(text.data());
        if (const auto* bounds = geometry()) *result->geometry() = *bounds;
        if (type == 2u || type == 5u) static_cast<HyperTextElementWithParameters*>(result)->parameters.assign(static_cast<const HyperTextElementWithParameters*>(this)->parameters.data());
        if (type == 5u) {
            auto* link = static_cast<HyperTextElement_Link*>(result);
            const auto* source = static_cast<const HyperTextElement_Link*>(this);
            link->target.assign(source->target.data());
            link->link_kind = source->link_kind;
        }
    } catch (...) {
        result->release();
        throw;
    }
    return result;
}

void SphereUI::HyperTextChatListItem::initialize(const char* text, std::uint32_t channel_id, std::uint32_t text_color) {
    hyper_text.assign(text == nullptr ? "" : text);
    channel = channel_id;
    color = text_color;
    elements.initialize();
    HyperTextParser::parseElements(hyper_text, elements, plain_text);
}

void SphereUI::HyperTextChatListItem::release() {
    for (std::uint32_t index = 0u; index < elements.count; ++index) if (auto* element = elements.at(index)) element->release();
    elements.release();
    rows.release();
    plain_text.release();
    hyper_text.release();
}

void SphereUI::HyperTextChatListItem::copyFrom(const HyperTextChatListItem& source) {
    if (this == &source) return;
    HyperTextChatListItem copy{};
    try {
        copy.hyper_text.assign(source.hyper_text.data());
        copy.plain_text.assign(source.plain_text.data());
        copy.channel = source.channel;
        copy.color = source.color;
        copy.rows.copyFrom(source.rows);
        copy.elements.initialize();
        for (std::uint32_t index = 0u; index < source.elements.count; ++index) {
            auto* original = source.elements.at(index);
            auto* element = original == nullptr ? nullptr : original->clone();
            try {
                copy.elements.pushBack(element);
            } catch (...) {
                if (element != nullptr) element->release();
                throw;
            }
        }
    } catch (...) {
        copy.release();
        throw;
    }
    release();
    *this = copy;
    elements.proxy->owner = &elements;
}

uint32_t HyperTextElement::elementType() const {
    return type;
}

void HyperTextElement::initializeText(std::uint32_t kind, const char* value) {
    type = kind;
    text = {};
    text.assign(value == nullptr ? "" : value);
}

namespace {
    using SphereUI::UiIntegerSetNode;
    void releaseIntegerBranch(UiIntegerSetNode* node, const UiIntegerSetNode* sentinel) {
        if (node == nullptr || node == sentinel) return;
        releaseIntegerBranch(node->left, sentinel);
        releaseIntegerBranch(node->right, sentinel);
        SphereUI::Runtime::deallocate(node);
    }

    UiIntegerSetNode*& integerChild(UiIntegerSetNode& node, bool right) {
        return right ? node.right : node.left;
    }

    void rotateIntegerTree(SphereUI::UiIntegerSet& tree, UiIntegerSetNode* node, bool right) {
        auto* pivot = integerChild(*node, !right);
        integerChild(*node, !right) = integerChild(*pivot, right);
        if (integerChild(*pivot, right) != tree.sentinel) integerChild(*pivot, right)->parent = node;
        pivot->parent = node->parent;
        auto* parent = node->parent;
        if (parent == tree.sentinel) parent->parent = pivot;
        else integerChild(*parent, node == parent->right) = pivot;
        integerChild(*pivot, right) = node;
        node->parent = pivot;
    }

    std::string escapedHyperText(std::string_view text) {
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
}

void SphereUI::UiIntegerSet::initialize() {
    if (sentinel != nullptr) return;
    auto* head = static_cast<UiIntegerSetNode*>(Runtime::allocate(sizeof(UiIntegerSetNode)));
    if (head == nullptr) throw std::bad_alloc();
    sentinel = head;
    *head = {head, head, head, 0u, 1u, 1u, {0u, 0u}};
    count = 0u;
}

bool SphereUI::UiIntegerSet::contains(std::uint32_t value) const {
    if (sentinel == nullptr) return false;
    auto* node = sentinel->parent;
    while (node != sentinel) {
        if (node->value == value) return true;
        node = value < node->value ? node->left : node->right;
    }
    return false;
}

void SphereUI::UiIntegerSet::insert(std::uint32_t value) {
    initialize();
    auto* head = sentinel;
    auto* parent = head;
    auto* node = head->parent;
    while (node != head) {
        parent = node;
        if (node->value == value) return;
        node = value < node->value ? node->left : node->right;
    }
    node = static_cast<UiIntegerSetNode*>(Runtime::allocate(sizeof(UiIntegerSetNode)));
    if (node == nullptr) throw std::bad_alloc();
    *node = {head, parent, head, value, 0u, 0u, {0u, 0u}};
    if (parent == head) head->parent = head->left = head->right = node;
    else {
        integerChild(*parent, value > parent->value) = node;
        if (value < head->left->value) head->left = node;
        if (value > head->right->value) head->right = node;
    }
    ++count;
    while (node->parent->black == 0u) {
        parent = node->parent;
        auto* grandparent = parent->parent;
        const bool right = parent == grandparent->right;
        auto* uncle = integerChild(*grandparent, !right);
        if (uncle->black == 0u) {
            parent->black = uncle->black = 1u;
            grandparent->black = 0u;
            node = grandparent;
        } else {
            if (node == integerChild(*parent, !right)) {
                node = parent;
                rotateIntegerTree(*this, node, right);
                parent = node->parent;
                grandparent = parent->parent;
            }
            parent->black = 1u;
            grandparent->black = 0u;
            rotateIntegerTree(*this, grandparent, !right);
        }
    }
    head->parent->black = 1u;
}

void SphereUI::UiIntegerSet::clear() {
    if (sentinel != nullptr) {
        releaseIntegerBranch(sentinel->parent, sentinel);
        sentinel->left = sentinel->parent = sentinel->right = sentinel;
    }
    count = 0u;
}

void SphereUI::UiIntegerSet::release() {
    clear();
    Runtime::deallocate(sentinel);
    sentinel = nullptr;
    proxy = nullptr;
    context = 0u;
}

void SphereUI::UiIntegerSet::copyFrom(const UiIntegerSet& source) {
    if (this == &source) return;
    UiIntegerSet copy{};
    try {
        copy.initialize();
        if (source.sentinel != nullptr) {
            const auto visit = [&](auto&& self, const UiIntegerSetNode* node) -> void {
                if (node == source.sentinel) return;
                self(self, node->left);
                copy.insert(node->value);
                self(self, node->right);
            };
            visit(visit, source.sentinel->parent);
        }
    } catch (...) {
        copy.release();
        throw;
    }
    release();
    *this = copy;
}

void SphereUI::detail::escapeHyperText(UiString& output, const UiString& source) {
    const auto value = escapedHyperText(std::string_view(source.data(), source.length));
    assignString(output.storage, output.length, output.capacity, value);
}

void SphereUI::detail::serializeHyperTextElements(const UiDeque<HyperTextElement*>& elements, UiString& hyper_text, UiString& plain) {
    std::string raw, visible;
    for (std::uint32_t index = 0u; index < elements.count; ++index) if (const auto* element = elements.at(index)) {
        const std::string_view text(element->text.data(), element->text.length);
        if (element->type == 3u) {
            raw += text;
            visible += text;
        } else if (element->type == 4u || element->type == 5u) {
            if (element->type == 5u) {
                raw += "<l ";
                raw += static_cast<const HyperTextElement_Link*>(element)->parameters.data();
                raw += '>';
            }
            raw += escapedHyperText(text);
            if (element->type == 5u) raw += "</l>";
            visible += text;
        }
    }
    assignString(hyper_text.storage, hyper_text.length, hyper_text.capacity, raw);
    assignString(plain.storage, plain.length, plain.capacity, visible);
}

void SphereUI::Runtime::setTextInputActive(bool active) {
    g_sfera_texture_cache_runtime.render_gate = active ? 1u : 0u;
}

void SphereUI::Runtime::broadcastMessage(Window* root, std::int32_t group, std::uint32_t message, std::uint32_t first, std::uint32_t second, std::uint32_t kind) {
    if (root != nullptr) {
        root->dispatchMessage(group, message, first, second, kind);
        return;
    }
    for (auto* window : g_sfera_interface.windows) if (window != nullptr) window->dispatchMessage(group, message, first, second, kind);
}

void* SphereUI::Runtime::allocate(std::size_t size) { return WorldMemory::allocate(size); }
void SphereUI::Runtime::deallocate(void* memory) { WorldMemory::release(memory); }

namespace {
    

    

    

    

    

    
}











namespace SphereUI {
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
            for (std::uint32_t value = '0'; value <= 'Z'; ++value) if (value <= '9' || value >= 'A') result[value][0] = static_cast<char>(value);
            for (std::uint32_t index = 0u; index != 12u; ++index) std::snprintf(result[VK_F1 + index].data(), result[VK_F1 + index].size(), "F%u", index + 1u);
            for (std::uint32_t index = 0u; index != 10u; ++index) std::snprintf(result[VK_NUMPAD0 + index].data(), result[VK_NUMPAD0 + index].size(), "NUMPAD%u", index);
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
        for (std::uint32_t key = 0u; key <= 255u; ++key) if (uiScanCode(key) == scan) return key;
        return 0u;
    }


    std::uint64_t uiCounterValue(const SferaU64Words& words) {
        return (static_cast<std::uint64_t>(words.high) << 32u) | words.low;
    }

    void setUiCounterValue(SferaU64Words& words, std::uint64_t value) {
        words.low = static_cast<std::uint32_t>(value);
        words.high = static_cast<std::uint32_t>(value >> 32u);
    }












    SferaMbcNamedVectorRecord* findNamedUiValues(const char* name) {
        if (name == nullptr || g_sfera_mbc_runtime == nullptr) return nullptr;
        for (std::uint32_t index = 0u; index < g_sfera_mbc_runtime->named_vector_count; ++index) {
            auto& record = g_sfera_mbc_runtime->named_vectors[index];
            g_sfera_mbc_runtime->current_named_vector = &record;
            if (const auto* existing = record.name_text; existing != nullptr && std::strcmp(existing, name) == 0) return &record;
        }
        g_sfera_mbc_runtime->current_named_vector = g_sfera_mbc_runtime->named_vectors + g_sfera_mbc_runtime->named_vector_count;
        return nullptr;
    }

    std::uint32_t namedValue(const char* name, std::int32_t index = 0) {
        auto* record = findNamedUiValues(name);
        if (record == nullptr) return 0u;
        if (index < 0) return record->size;
        return static_cast<std::uint32_t>(index) < record->size ? record->value_data[index] : 0u;
    }

    void setNamedValue(const char* name, std::uint32_t value, std::int32_t index = 0) {
        if (name == nullptr || g_sfera_mbc_runtime == nullptr || index < 0) return;
        auto* record = findNamedUiValues(name);
        if (record == nullptr) {
            if (g_sfera_mbc_runtime->named_vector_count >= std::size(g_sfera_mbc_runtime->named_vectors)) return;
            const auto length = std::strlen(name) + 1u;
            auto* stored_name = static_cast<char*>(SphereUI::Runtime::allocate(length));
            if (stored_name == nullptr) throw std::bad_alloc();
            std::memcpy(stored_name, name, length);
            record = &g_sfera_mbc_runtime->named_vectors[g_sfera_mbc_runtime->named_vector_count++];
            *record = {};
            record->name_text = stored_name;
            g_sfera_mbc_runtime->current_named_vector = record;
        }
        const auto required = index + 1u;
        if (required > record->size) {
            if (required > std::numeric_limits<std::uint32_t>::max() / sizeof(std::uint32_t)) throw std::length_error("named UI values exceed array capacity");
            auto* values = static_cast<std::uint32_t*>(SphereUI::Runtime::allocate(required * sizeof(std::uint32_t)));
            if (values == nullptr) throw std::bad_alloc();
            if (record->size != 0u) std::memcpy(values, record->value_data, record->size * sizeof(std::uint32_t));
            SphereUI::Runtime::deallocate(record->value_data);
            record->value_data = values;
            record->size = required;
        }
        record->value_data[index] = value;
    }

    std::uint32_t soundVolume() {
        const auto* manager = g_sfera_sound_runtime.sound_manager;
        return manager == nullptr ? 0u : static_cast<std::uint32_t>(static_cast<std::int32_t>(std::trunc(manager->volume * 100.0)));
    }

    void setSoundVolume(std::uint32_t value) {
        auto* manager = g_sfera_sound_runtime.sound_manager;
        if (manager == nullptr) return;
        manager->volume = static_cast<float>(std::clamp(static_cast<std::int32_t>(value), 0, 100) / 100.0);
        for (auto* sound = manager->first; sound != nullptr; sound = sound->cache_next) sound->SetVolume(manager->volume);
    }

    void setMusicVolume(std::uint32_t value) {
        SI_SetStreamVolume(static_cast<int>(value));
    }

    void playUiSound(const char* filename) {
        auto* manager = g_sfera_sound_runtime.sound_manager;
        if (g_sfera_interface_runtime.sounds_enabled == 0u || filename == nullptr || SI_GetInterface() == nullptr || manager == nullptr || manager->enabled == 0u) return;
        CSound* sound = nullptr;
        for (auto* candidate = manager->first; candidate != nullptr; candidate = candidate->cache_next) if (SferaSimpleParser::equalsIgnoreCase(candidate->filename, filename) && candidate->IsSoundPlaying() == 0) {
            if (candidate->cache_available != 0u) sound = candidate;
            break;
        }
        if (sound == nullptr) {
            FILE* source = nullptr;
            if (fopen_s(&source, filename, "rb") != 0 || source == nullptr) return;
            std::fclose(source);
            void* storage = SphereUI::Runtime::allocate(sizeof(CSound));
            if (storage == nullptr) return;
            try {
                sound = ::new (storage) CSound();
                std::construct_at(reinterpret_cast<CSoundFX*>(sound));
                sound->cache_idle_since_low = sound->cache_idle_since_high = noSoundIdleTimestamp;
                sound->cache_lifetime_seconds = 0;
                sound->cache_next = sound->cache_previous = nullptr;
                sound->cache_available = sound->playback_finished = 1u;
                if (sound->LoadSound(filename, 8ul) == 0) {
                    sound->~CSound();
                    SphereUI::Runtime::deallocate(sound);
                    return;
                }
            } catch (...) {
                SphereUI::Runtime::deallocate(storage);
                throw;
            }
            sound->cache_previous = manager->last;
            if (manager->last != nullptr) manager->last->cache_next = sound;
            else manager->first = sound;
            manager->last = sound;
            ++manager->count;
        }
        sound->cache_lifetime_seconds = 4;
        sound->SetVolume(manager->volume);
        sound->SetPlayTimepos(0.0f);
        if (sound->CSound::Play(0) != 0) {
            sound->cache_idle_since_low = sound->cache_idle_since_high = noSoundIdleTimestamp;
            sound->playback_finished = 0u;
        }
    }
}

std::uint64_t SphereUI::Runtime::clockTicks() {
    auto& clock = g_sfera_high_resolution_clock_runtime;
    if (clock.initialized == 0u) {
        LARGE_INTEGER frequency{}, anchor{};
        ::QueryPerformanceFrequency(&frequency);
        auto normalized = static_cast<std::uint64_t>(frequency.QuadPart);
        clock.frequency_shift = 0u;
        while (normalized > 2000000u) {
            normalized >>= 1u;
            ++clock.frequency_shift;
        }
        setUiCounterValue(clock.performance_frequency, normalized);
        ::QueryPerformanceCounter(&anchor);
        setUiCounterValue(clock.counter_anchor, static_cast<std::uint64_t>(anchor.QuadPart));
        clock.initialized = 1u;
    }
    LARGE_INTEGER now{};
    ::QueryPerformanceCounter(&now);
    const auto anchor = uiCounterValue(clock.counter_anchor);
    const auto delta = static_cast<std::uint64_t>(static_cast<std::int64_t>(static_cast<std::uint64_t>(now.QuadPart) - anchor) >> clock.frequency_shift);
    auto elapsed = uiCounterValue(clock.elapsed_counter) + delta;
    setUiCounterValue(clock.counter_anchor, anchor + (delta << clock.frequency_shift));
    const auto frequency = uiCounterValue(clock.performance_frequency);
    if (frequency == 0u) return 0u;
    auto epoch = uiCounterValue(clock.epoch_microseconds);
    const auto epoch_ticks = frequency * 1000u;
    if (elapsed > epoch_ticks) {
        const auto epochs = (elapsed - 1u) / epoch_ticks;
        elapsed -= epochs * epoch_ticks;
        epoch += epochs * 1000000000u;
    }
    setUiCounterValue(clock.elapsed_counter, elapsed);
    setUiCounterValue(clock.epoch_microseconds, epoch);
    return (epoch + elapsed * 1000000u / frequency) / 100u;
}




std::uint32_t SphereUI::Runtime::keyCode(const char* name) {
    if (name == nullptr) return 0u;
    for (std::uint32_t code = 0u; code <= 255u; ++code) if (const auto* candidate = uiKeyName(code); candidate != nullptr && SferaSimpleParser::equalsIgnoreCase(name, candidate)) return code;
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
    return g_sfera_interface_runtime.description_auto_popup != 0u;
}

SphereUI::CDescriptionWindow* SphereUI::Runtime::descriptionWindow() {
    return g_sfera_interface_runtime.description_control;
}

void SphereUI::Runtime::setDescriptionWindow(CDescriptionWindow* window) {
    g_sfera_interface_runtime.description_control = window;
}


bool SphereUI::Runtime::playerHeading(float& heading) {
    const auto handle = g_sfera_world_objects.controlled_object_handle;
    if (static_cast<std::int32_t>(handle) <= 0) return false;
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

void SphereUI::Runtime::clipboardText(UiString& result) {
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



    SferaBrowserHost* uiBrowserHost(const SphereUI::BrowserSession& session) {
        const HWND window = session.host_window;
        return window == nullptr ? nullptr : reinterpret_cast<SferaBrowserHost*>(::GetWindowLongPtrA(window, GWLP_USERDATA));
    }

    IWebBrowser2* uiBrowserInterface(IOleObject* object) {
        IWebBrowser2* browser = nullptr;
        if (object != nullptr) object->QueryInterface(__uuidof(IWebBrowser2), reinterpret_cast<void**>(&browser));
        return browser;
    }

    void uiUploadBrowserSurface(SphereUI::BrowserSurface& surface) {
        const auto* resource = surface.texture_resource;
        auto* texture = resource == nullptr ? nullptr : resource->native_texture;
        if (texture == nullptr) return;
        D3DSURFACE_DESC description{};
        if (FAILED(texture->GetLevelDesc(0u, &description)) || description.Width != static_cast<UINT>(surface.texture_size) || description.Height != static_cast<UINT>(surface.texture_size)) return;
        D3DLOCKED_RECT locked{};
        if (FAILED(texture->LockRect(0u, &locked, nullptr, D3DLOCK_NOSYSLOCK))) return;
        if (locked.pBits != nullptr) {
            BITMAPINFO bitmap_info{};
            bitmap_info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
            bitmap_info.bmiHeader.biWidth = surface.width;
            bitmap_info.bmiHeader.biHeight = -surface.height;
            bitmap_info.bmiHeader.biPlanes = 1u;
            bitmap_info.bmiHeader.biBitCount = 32u;
            bitmap_info.bmiHeader.biCompression = BI_RGB;
            bitmap_info.bmiHeader.biSizeImage = static_cast<DWORD>(surface.width) * surface.height * 4u;
            const HDC context = surface.device_context;
            const auto bitmap = surface.bitmap;
            ::SelectObject(context, surface.previous_bitmap);
            auto* destination = static_cast<std::byte*>(locked.pBits);
            for (std::int32_t row = surface.height; row-- > 0;) {
                ::GetDIBits(context, bitmap, static_cast<UINT>(row), 1u, destination, &bitmap_info, DIB_RGB_COLORS);
                destination += locked.Pitch;
            }
            ::SelectObject(context, bitmap);
        }
        texture->UnlockRect(0u);
    }

    std::uint32_t uiBrowserNoiseChannel() {
        return std::rand() * 255u / RAND_MAX;
    }

    void uiInitializeBrowserBitmap(SphereUI::BrowserSurface& surface) {
        const HDC context = surface.device_context;
        for (std::int32_t row = 0; row < surface.height; ++row) for (std::int32_t column = 0; column < surface.width; ++column) {
            const auto blue = uiBrowserNoiseChannel(), green = uiBrowserNoiseChannel(), red = uiBrowserNoiseChannel();
            ::SetPixel(context, column, row, RGB(red, green, blue));
        }
    }

    HWND uiBrowserDocumentWindow(SphereUI::BrowserSession& session) {
        if (session.document_window == nullptr) session.document_window = sfera_browser_document_window(session.host_window);
        const HWND document = session.document_window;
        if (document != nullptr && session.subclassed == 0u) {
            const auto previous = reinterpret_cast<WNDPROC>(::SetWindowLongPtrA(document, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&sfera_browser_subclass_proc)));
            if (previous != nullptr) {
                g_sfera_browser_window_runtime.original_window_proc = previous;
                session.subclassed = 1u;
            }
        }
        return document;
    }
}

HRESULT SferaBrowserHost::navigate(const char* url) noexcept {
    if (url == nullptr) return E_INVALIDARG;
    auto* browser = uiBrowserInterface(object_);
    if (browser == nullptr) return E_NOINTERFACE;
    const int length = ::MultiByteToWideChar(CP_ACP, 0u, url, -1, nullptr, 0);
    VARIANT location{};
    location.vt = VT_BSTR;
    location.bstrVal = length > 0 ? ::SysAllocStringLen(nullptr, static_cast<UINT>(length - 1)) : nullptr;
    HRESULT result = E_OUTOFMEMORY;
    if (location.bstrVal != nullptr && ::MultiByteToWideChar(CP_ACP, 0u, url, -1, location.bstrVal, length) != 0) result = browser->Navigate2(&location, nullptr, nullptr, nullptr, nullptr);
    ::VariantClear(&location);
    browser->Release();
    return result;
}

void SferaBrowserHost::location(char* buffer, std::uint32_t capacity) noexcept {
    if (buffer == nullptr || capacity == 0u) return;
    buffer[0] = '\0';
    auto* browser = uiBrowserInterface(object_);
    if (browser == nullptr) return;
    BSTR address = nullptr;
    if (SUCCEEDED(browser->get_LocationURL(&address)) && address != nullptr) ::WideCharToMultiByte(CP_ACP, 0u, address, -1, buffer, static_cast<int>(std::min<std::uint32_t>(capacity, INT_MAX)), nullptr, nullptr);
    ::SysFreeString(address);
    browser->Release();
    buffer[capacity - 1u] = '\0';
}

SphereUI::BrowserSurface* SphereUI::Runtime::createBrowserSurface(std::int32_t width, std::int32_t height) {
    if (width <= 0 || height <= 0) throw std::invalid_argument("Browser surface dimensions must be positive");
    auto* surface = static_cast<BrowserSurface*>(allocate(sizeof(BrowserSurface)));
    if (surface == nullptr) throw std::bad_alloc();
    *surface = {};
    surface->width = std::min(width, 1024);
    surface->height = std::min(height, 1024);
    surface->texture_size = 32;
    HDC screen = nullptr;
    try {
        while (surface->texture_size < std::max(width, height)) {
            if (surface->texture_size > INT_MAX / 2) throw std::length_error("Browser texture is too large");
            surface->texture_size *= 2;
        }
        screen = ::GetDC(nullptr);
        if (screen == nullptr) throw std::runtime_error("Unable to acquire browser screen context");
        surface->device_context = ::CreateCompatibleDC(screen);
        if (surface->device_context == nullptr) throw std::runtime_error("Unable to create browser device context");
        surface->bitmap = ::CreateCompatibleBitmap(screen, surface->width, surface->height);
        if (surface->bitmap == nullptr) throw std::runtime_error("Unable to create browser bitmap");
        ::ReleaseDC(nullptr, screen);
        screen = nullptr;
        auto* texture = new UnmanagedResourceTexture(*g_sfera_graphics_runtime.d3d_runtime, static_cast<std::uint32_t>(surface->texture_size), static_cast<std::uint32_t>(surface->texture_size), 1u, D3DUSAGE_DYNAMIC, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT);
        surface->texture_resource = texture;
        
        const auto previous = ::SelectObject(surface->device_context, surface->bitmap);
        if (previous == nullptr || previous == HGDI_ERROR) throw std::runtime_error("Unable to select browser bitmap");
        surface->previous_bitmap = previous;
        uiInitializeBrowserBitmap(*surface);
        uiUploadBrowserSurface(*surface);
    } catch (...) {
        if (screen != nullptr) ::ReleaseDC(nullptr, screen);
        destroyBrowserSurface(surface);
        throw;
    }
    return surface;
}

void SphereUI::Runtime::destroyBrowserSurface(BrowserSurface* surface) {
    if (surface == nullptr) return;
    const HDC context = surface->device_context;
    if (context != nullptr) {
        if (surface->previous_bitmap != nullptr) ::SelectObject(context, surface->previous_bitmap);
        ::DeleteDC(context);
    }
    if (surface->bitmap != nullptr) ::DeleteObject(surface->bitmap);
    if (surface->texture_resource != nullptr) {
        delete surface->texture_resource;
        
    }
    deallocate(surface);
}

SphereUI::BrowserSession* SphereUI::Runtime::createBrowserSession(const char* url, std::int32_t width, std::int32_t height) {
    auto* session = static_cast<BrowserSession*>(allocate(sizeof(BrowserSession)));
    if (session == nullptr) throw std::bad_alloc();
    *session = {};
    session->url.capacity = 15u;
    session->width = width;
    session->height = height;
    try {
        const HINSTANCE instance = ::GetModuleHandleA(nullptr);
        if (g_sfera_browser_window_runtime.class_registered == 0u) {
            WNDCLASSEXA window_class{};
            window_class.cbSize = sizeof(window_class);
            window_class.lpfnWndProc = &sfera_browser_host_window_proc;
            window_class.hInstance = instance;
            window_class.lpszClassName = "Browser Example";
            if (::RegisterClassExA(&window_class) == 0u && ::GetLastError() != ERROR_CLASS_ALREADY_EXISTS) throw std::runtime_error("Unable to register browser window class");
            g_sfera_browser_window_runtime.class_registered = 1u;
        }
        session->host_window = ::CreateWindowExA(0u, "Browser Example", "", WS_CHILD, 0, 0, width, height, g_sfera_window_runtime.main_window_handle, nullptr, instance, nullptr);
        if (session->host_window == nullptr) throw std::runtime_error("Unable to create browser host window");
        browserNavigate(*session, url == nullptr ? "" : url);
    } catch (...) {
        destroyBrowserSession(session);
        throw;
    }
    return session;
}

void SphereUI::Runtime::destroyBrowserSession(BrowserSession* session) {
    if (session == nullptr) return;
    focusMainWindow();
    if (session->host_window != nullptr) ::DestroyWindow(session->host_window);
    session->url.release();
    deallocate(session);
}

void SphereUI::Runtime::browserNavigate(BrowserSession& session, const char* url) {
    if (url == nullptr) return;
    session.url.assign(url);
    if (auto* host = uiBrowserHost(session)) host->navigate(session.url.data());
}

void SphereUI::Runtime::browserRefresh(BrowserSession& session) {
    sfera_browser_refresh(session.host_window);
}

void SphereUI::Runtime::browserLocation(BrowserSession& session, char* buffer, std::uint32_t capacity) {
    if (buffer == nullptr || capacity == 0u) return;
    buffer[0] = '\0';
    if (auto* host = uiBrowserHost(session)) host->location(buffer, capacity);
    buffer[capacity - 1u] = '\0';
}

void SphereUI::Runtime::browserMouse(BrowserSession& session, std::uint32_t message, std::int32_t x, std::int32_t y, std::int32_t wheel) {
    WPARAM buttons = 0u;
    switch (message) {
        case WM_MOUSEMOVE:
            if (session.mouse_x == x && session.mouse_y == y) return;
            break;
        case WM_LBUTTONDOWN:
            session.buttons |= MK_LBUTTON;
            buttons = session.buttons;
            break;
        case WM_LBUTTONUP:
            session.buttons &= ~static_cast<std::uint32_t>(MK_LBUTTON);
            buttons = session.buttons;
            break;
        case WM_MOUSEWHEEL:
            buttons = static_cast<WPARAM>(((static_cast<std::uint32_t>(wheel) * WHEEL_DELTA) & std::numeric_limits<std::uint16_t>::max()) << 16u);
            break;
        default:
            return;
    }
    session.mouse_x = x;
    session.mouse_y = y;
    POINT position{x, y};
    if (message == WM_MOUSEWHEEL) ::ClientToScreen(g_sfera_window_runtime.main_window_handle, &position);
    const HWND document = uiBrowserDocumentWindow(session);
    if (document == nullptr) return;
    const LPARAM coordinates = static_cast<LPARAM>((static_cast<std::uint32_t>(position.x) & std::numeric_limits<std::uint16_t>::max()) | ((static_cast<std::uint32_t>(position.y) & std::numeric_limits<std::uint16_t>::max()) << 16u));
    if (g_sfera_browser_window_runtime.original_window_proc != nullptr) ::CallWindowProcA(g_sfera_browser_window_runtime.original_window_proc, document, message, buttons, coordinates);
    else ::SendMessageA(document, message, buttons, coordinates);
}

void SphereUI::Runtime::browserPaint(BrowserSession& session, BrowserSurface& surface) {
    sfera_browser_draw(session.host_window, surface.device_context, session.width, session.height);
    uiUploadBrowserSurface(surface);
}

void SphereUI::Runtime::focusMainWindow() {
    ::SetFocus(g_sfera_window_runtime.main_window_handle);
}

namespace {
    constexpr std::uint32_t uiColor(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255u) {
        return (static_cast<std::uint32_t>(alpha) << 24u) | (red << 16u) | (green << 8u) | blue;
    }

    constexpr std::uint32_t uiWhite = uiColor(255u, 255u, 255u);
    constexpr std::uint32_t uiRgbMask = uiColor(255u, 255u, 255u, 0u);
    constexpr std::uint32_t uiOpaqueAlpha = uiColor(0u, 0u, 0u);
    constexpr std::uint32_t uiInvalidTexture = std::numeric_limits<std::uint32_t>::max();


    

    















    





}

std::int32_t SphereUI::Runtime::findImage(const char* name) {
    return g_sfera_textures.find(name);
}


SphereUI::TextExtent SphereUI::Runtime::screenSize() {
    return {static_cast<std::int32_t>(g_sfera_graphics_runtime.display_width), static_cast<std::int32_t>(g_sfera_graphics_runtime.display_height)};
}









namespace {

    

    

    

    

    

}







namespace SphereUI {

    struct OptionsShadowSettings {
        std::uint8_t reserved[160];
        std::uint8_t quality;
    };

    struct OptionsLodSettings {
        float maximum_distance;
        float minimum_distance;
        std::uint8_t reserved[29996];
        float near_threshold;
        float far_threshold;
    };
}

namespace SphereUI::Runtime {
    void invokeEventHandler(WindowEventHandler handler, Window* window, const WindowEvent& event);
}

namespace {
    using namespace SphereUI;
    void appendWindowEvent(WindowEvent**& slots, std::uint32_t& capacity, std::uint32_t& head, std::uint32_t& size, std::uint32_t& pending, const WindowEvent& event) {
        if (pending >= 64u) {
            size = 0u;
            head = 0u;
            pending = 0u;
        }
        if (size + 1u >= capacity) {
            const auto growth = std::max(8u, capacity / 2u);
            if (capacity > std::numeric_limits<std::uint32_t>::max() / sizeof(WindowEvent) - growth) throw std::length_error("Window event queue too long");
            const auto next_capacity = capacity + growth;
            auto* replacement = static_cast<WindowEvent**>(Runtime::allocate(next_capacity * sizeof(WindowEvent*)));
            if (replacement == nullptr) throw std::bad_alloc();
            std::fill_n(replacement, next_capacity, nullptr);
            auto* previous = slots;
            for (std::uint32_t index = 0u; index < capacity; ++index) replacement[index] = previous[(head + index) % capacity];
            Runtime::deallocate(previous);
            slots = replacement;
            capacity = next_capacity;
            head = 0u;
        }
        auto*& queued = slots[(head + size) % capacity];
        if (queued == nullptr) {
            queued = static_cast<WindowEvent*>(Runtime::allocate(sizeof(WindowEvent)));
            if (queued == nullptr) throw std::bad_alloc();
        }
        *queued = event;
        ++size;
        ++pending;
    }

    void queueInterfaceRefresh() {
        g_sfera_interface.queueEvent({nullptr, 0u, 16u, 0u, 0u, 0u, 0u});
    }

    Window* optionChild(Window* window, std::uint32_t index) {
        if (window == nullptr || index == 0u) return window;
        auto* sentinel = window->child_sentinel;
        if (sentinel == nullptr) return nullptr;
        auto* node = sentinel->next;
        for (std::uint32_t current = 1u; current < index && node != nullptr && node != sentinel; ++current) node = node->next;
        return node == nullptr || node == sentinel ? nullptr : node->value;
    }

    void optionMessage(Window* window, std::uint32_t index, std::uint32_t message, std::uint32_t first = 0u, std::uint32_t second = 0u) {
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
            saved_music = SI_GetStreamVolume();
            saved_sound = soundVolume();
            optionMessage(window, 7u, UiMessage::setScrollRange, 0u, 100u);
            optionMessage(window, 8u, UiMessage::setScrollRange, 0u, 100u);
            optionMessage(window, 7u, UiMessage::setScrollValue, saved_music);
            optionMessage(window, 8u, UiMessage::setScrollValue, saved_sound);
            values[7] = SI_GetHardwareMixing();
            values[12] = values[7];
            optionLabel(window, 9u, values[12] != 0u ? "UISTR_WT_OPT34" : "UISTR_WT_OPT33");
            return;
        }
        setMusicVolume(saved_music);
        setSoundVolume(saved_sound);
        setOptionsVisible(true);
        SI_SetHardwareMixing(values[7] != 0u);
        InterfaceConfiguration::open("config.cfg");
        InterfaceConfiguration::writeInteger("SNDVOL", saved_sound);
        InterfaceConfiguration::writeInteger("MUSVOL", saved_music);
        InterfaceConfiguration::writeInteger("HWMIX", values[7]);
        InterfaceConfiguration::save();
    }

    std::uint32_t bindingCount() {
        return namedValue("SSKS_NUMBER");
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
        for (std::uint32_t slot = 0u; slot < count; ++slot) if (g_sfera_control_options.working_bindings[slot] == key) return false;
        return key != 0u && key != VK_ESCAPE && key != VK_F1 && key != VK_RETURN && key - '0' > 9u && key != VK_SHIFT && key != VK_CONTROL && key - VK_LEFT > 3u;
    }

    void setControlOptionsVisible(bool show) {
        auto* window = beginOptionsDialog("control_options", WindowEventHandler::control_options, show);
        if (window == nullptr) return;
        auto& state = g_sfera_control_options;
        const auto count = bindingCount();
        if (show) {
            std::fill(std::begin(state.configured_bindings), std::end(state.configured_bindings), 0u);
            for (std::uint32_t slot = 0u; slot < std::max(5u, count); ++slot) {
                const auto key = namedValue("SSKS", slot);
                state.configured_bindings[slot] = slot < 5u ? uiVirtualKey(key) : key;
            }
            state.configured_bindings[63] = namedValue("INMS");
            std::copy(std::begin(state.configured_bindings), std::end(state.configured_bindings), std::begin(state.working_bindings));
            optionLabel(window, 4u, state.configured_bindings[63] == 0u ? "UISTR_WT_OPT23" : "UISTR_WT_OPT24");
            for (std::uint32_t slot = 0u; slot < count; ++slot) {
                optionMessage(window, 5u, UiMessage::appendListItem);
                std::snprintf(g_sfera_options_dialog_runtime.widget_key_name, sizeof(g_sfera_options_dialog_runtime.widget_key_name), "UISTR_WT_KEY%02u", slot + 1u);
                optionLabel(bindingRow(window, slot), 2u, g_sfera_options_dialog_runtime.widget_key_name);
                refreshBindingLabel(window, slot);
            }
            g_sfera_options_dialog_runtime.widget_keys_initialized = 1u;
            return;
        }
        setOptionsVisible(true);
        setNamedValue("INMS", state.configured_bindings[63]);
        for (std::uint32_t slot = 0u; slot < std::max(5u, count); ++slot) setNamedValue("SSKS", slot < 5u ? uiScanCode(state.configured_bindings[slot]) : state.configured_bindings[slot], slot);
        queueInterfaceRefresh();
        g_sfera_options_dialog_runtime.widget_keys_initialized = 0u;
    }

    constexpr std::uint32_t interfaceControlIds[] = {7u, 8u, 9u, 11u, 12u, 15u, 16u, 19u, 21u};
    constexpr const char* interfaceSettingKeys[] = {"ISSN", "ISAD", "INSN", "INAW", "IAPM", "MBST", "BALR"};
    void setInterfaceOptionsVisible(bool show) {
        auto* window = beginOptionsDialog("interface_options", WindowEventHandler::interface_options, show);
        if (window == nullptr) return;
        auto& state = g_sfera_graphics_options_runtime;
        if (show) {
            for (std::uint32_t index = 0u; index < 5u; ++index) state.saved_interface_values[index] = index == 2u ? g_sfera_interface_runtime.sounds_enabled : namedValue(interfaceSettingKeys[index]);
            InterfaceConfiguration::open("config.cfg");
            InterfaceConfiguration::readInteger("MBST", state.saved_interface_values[5]);
            state.saved_interface_values[6] = missingConfigValue;
            InterfaceConfiguration::readInteger("BALR", state.saved_interface_values[6]);
            if (static_cast<std::int32_t>(state.saved_interface_values[6]) < 0) {
                state.saved_interface_values[6] = 1u;
                InterfaceConfiguration::writeInteger("BALR", 1u);
                InterfaceConfiguration::save();
            }
            state.saved_interface_values[7] = g_sfera_interface_runtime.description_auto_popup;
            state.saved_interface_values[8] = g_sfera_interface_runtime.invite_messages;
            std::copy(std::begin(state.saved_interface_values), std::end(state.saved_interface_values), std::begin(state.interface_values));
            for (std::uint32_t index = 0u; index < std::size(interfaceControlIds); ++index) optionToggleLabel(window, interfaceControlIds[index], state.interface_values[index]);
            return;
        }
        setOptionsVisible(true);
        for (std::uint32_t index = 0u; index < std::size(interfaceSettingKeys); ++index) setNamedValue(interfaceSettingKeys[index], state.saved_interface_values[index]);
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
        for (auto* window : g_sfera_interface.windows) if (window != nullptr && window->save_last_position != 0u) window->alignToScreen(true);
    }

    UiIndexVector& savedChatFonts() {
        return g_sfera_options_dialog_runtime.saved_chat_fonts;
    }

    UiIndexVector& editedChatFonts() {
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
            saved.append(4u);
            saved.append(4u);
            InterfaceConfiguration::open("config.cfg");
            InterfaceConfiguration::readInteger("CHAT_LIST_FONT", saved.at(0u));
            InterfaceConfiguration::readInteger("CHAT_EDIT_FONT", saved.at(1u));
            for (std::uint32_t index = 0u; index < 2u; ++index) if (auto* control = optionChild(window, index + 3u)) control->setFont(saved.at(index));
            edited.copyFrom(saved);
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
    using SphereUI::OptionsShadowSettings;
    using SphereUI::OptionsLodSettings;



    std::uint32_t findOptionsMode(const OptionsDisplayMode& requested) {
        const auto count = static_cast<std::uint32_t>(g_sfera_graphics_runtime.d3d_runtime->display_modes.size());
        for (std::uint32_t index = 0u; index < count; ++index) {
            const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index);
            if (mode.width == requested.width && mode.height == requested.height && mode.depth == requested.depth) return index;
        }
        for (std::uint32_t index = count; index != 0u; --index) {
            const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index - 1u);
            if (mode.depth == requested.depth && mode.width <= g_sfera_scene_control_runtime.timing_anchor && mode.height <= g_sfera_recovered_static_runtime.scene_state_07) return index - 1u;
        }
        return count - 1u;
    }

    void setOptionsModeLabel(Window* window, std::uint32_t index) {
        const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(index);
        const auto text = std::to_string(static_cast<std::int32_t>(mode.width)) + "x" + std::to_string(static_cast<std::int32_t>(mode.height)) + " " + std::to_string(static_cast<std::int32_t>(mode.depth));
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
        const auto enabled = g_sfera_graphics_runtime.lods_enabled != 0u;
        optionToggleLabel(window, 41u, enabled);
        optionSelection(window, 43u, 1u, enabled);
        optionMessage(window, 46u, UiMessage::setScrollRange, 0u, enabled ? 14u : 0u);
        if (enabled) optionMessage(window, 46u, UiMessage::setScrollValue, static_cast<std::uint32_t>(static_cast<std::int64_t>(std::trunc(g_sfera_input_device_runtime.lod_distance.f32 - 12.0))));
    }

    void setupFogOptions(Window* window) {
        const auto automatic = g_sfera_client_config_runtime.state_25 != 0u;
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
        auto* shadows = g_sfera_shadow_runtime.settings;
        if (shadows == nullptr) throw std::runtime_error("Shadow manager is unavailable");
        if (show) {
            g_sfera_sphere_options_runtime.saved_fog_distance.f32 = graphics.fog_distance;
            g_sfera_sphere_options_runtime.saved_lod_distance.f32 = g_sfera_input_device_runtime.lod_distance.f32;
            g_sfera_sphere_options_runtime.saved_lods_enabled = graphics.lods_enabled;
            values[9] = g_sfera_client_config_runtime.state_25;
            values[8] = g_sfera_client_config_runtime.state_26;
            g_sfera_graphics_options_runtime.graphics_page = state.reflection_quality;
            constexpr const char* label_keys[] = {"UISTR_WT_OPT21", "UISTR_WT_OPT20", "UISTR_WT_OPT19", "UISTR_WT_OPT18", "UISTR_WT_OPT17", "UISTR_WT_OPT17", "UISTR_WT_OPT16"};
            for (std::uint32_t index = 0u; index < std::size(label_keys); ++index) detail::copyText(g_sfera_sphere_options_runtime.option_labels[index], g_sfera_interface.localizedText(label_keys[index]));
            detail::copyText(state.graphics_unknown_label, g_sfera_interface.localizedText("UISTR_WT_OPT36"));
            InterfaceConfiguration::open("config.cfg");
            OptionsDisplayMode mode{graphics.display_width, graphics.display_height, g_sfera_graphics_display_depth_bits};
            InterfaceConfiguration::readInteger("XRES", mode.width);
            InterfaceConfiguration::readInteger("YRES", mode.height);
            g_sfera_graphics_runtime.d3d_runtime->enumerateDisplayModes(g_sfera_window_runtime.windowed == 1u);
            values[5] = findOptionsMode(mode);
            values[1] = mode.depth;
            values[2] = shadows->quality;
            values[3] = g_sfera_main_render_runtime.grass_depth_mode;
            values[4] = g_sfera_window_runtime.windowed;
            values[6] = graphics.post_effects_enabled;
            values[10] = values[0];
            values[11] = mode.depth;
            state.pending_graphics_value = values[5];
            state.comparison_graphics_value = values[4];
            optionSelection(window, 15u, static_cast<std::uint32_t>(g_sfera_graphics_runtime.d3d_runtime->display_modes.size()) - 1u, values[5]);
            optionSelection(window, 17u, 4u, values[2]);
            optionSelection(window, 18u, 2u, values[3]);
            optionMessage(window, 26u, UiMessage::setSpinRange, 0u, 1u);
            optionToggleLabel(window, 31u, g_sfera_client_config_runtime.state_26 == 0u);
            optionMessage(window, 26u, UiMessage::setSpinValue, g_sfera_client_config_runtime.state_26 == 0u);
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
            if (!post_supported) values[6] = state.graphics_snapshot[6] = graphics.post_effects_enabled = 0u;
            optionSelection(window, 51u, post_supported ? 1u : 0u, values[6]);
            optionText(window, 49u, graphicsBooleanLabel(values[6]));
            std::copy_n(values, 7u, state.graphics_snapshot);
            return;
        }
        setOptionsVisible(true);
        shadows->quality = static_cast<std::uint8_t>(values[2]);
        g_sfera_main_render_runtime.grass_depth_mode = values[3];
        g_sfera_window_runtime.windowed = values[4];
        InterfaceConfiguration::open("config.cfg");
        const auto mode = g_sfera_graphics_runtime.d3d_runtime->display_modes.at(values[5]);
        const std::pair<const char*, std::uint32_t> settings[] = { {
            "XRES", mode.width
        }, {"YRES", mode.height}, {"DEPTH", mode.depth}, {"GRASS", values[3]}, {"WINDOWED", values[4]}, {"SHAD", values[2]}, {"AUTOFOG", g_sfera_client_config_runtime.state_25}, {"FOGDIST", static_cast<std::uint32_t>(static_cast<std::int32_t>(std::trunc(graphics.fog_distance)))}, {"REFLQUAL", state.reflection_quality}, {"EFFECTS", g_sfera_client_config_runtime.state_26}, {"LODS", graphics.lods_enabled}, {"LOD_DISTANCE", static_cast<std::uint32_t>(static_cast<std::int32_t>(std::trunc(g_sfera_input_device_runtime.minimum_lod_distance.f32)))}, {"MIN_LOD_DIST", static_cast<std::uint32_t>(static_cast<std::int32_t>(std::trunc(g_sfera_input_device_runtime.lod_distance.f32)))}, {"POSTEFFECTS", values[6]}};
        for (const auto& setting : settings) InterfaceConfiguration::writeInteger(setting.first, setting.second);
        g_sfera_effect_manager.effects_enabled = g_sfera_client_config_runtime.state_26;
        InterfaceConfiguration::save();
        if (values[10] != values[0] || values[11] != values[1] || state.comparison_graphics_value != values[4]) {
            detail::copyText(g_sfera_process_runtime.executable_path, "sphere.exe");
            g_sfera_relaunch_runtime.argument[0] = '\0';
            g_sfera_render_lookup_runtime.initialized = 1u;
        }
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
        const auto* document = control->document;
        const auto* name = document == nullptr ? nullptr : document->name.c_str();
        if (name != nullptr && SferaSimpleParser::equalsIgnoreCase(name, "Language\\helpindex.hts")) control->handleMessage(UiMessage::clearHyperTextHistory, 0u, 0u);
        optionMessage(window, 2u, UiMessage::setEnabled, control->history.count == 0u ? 0u : 1u);
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
            optionMessage(window, 7u, UiMessage::getScrollValue, static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_sphere_options_runtime.saved_music_volume)));
            optionMessage(window, 8u, UiMessage::getScrollValue, static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_options_dialog_runtime.audio_settings)));
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
        if (event.message == 15u) {
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
        if (event.message == UiMessage::listItemEvent && event.first == UiMessage::leftClick && (event.second >> 16u) == 3u) {
            state.active_slot = event.second & packedFieldMask;
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
            for (std::uint32_t slot = 0u, count = bindingCount(); slot < count; ++slot) refreshBindingLabel(window, slot);
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
        for (std::uint32_t index = 0u; index < std::size(interfaceControlIds); ++index) if (event.control_id == interfaceControlIds[index]) {
            auto& value = state.interface_values[index];
            value = value == 0u;
            if (index == 0u) setNamedValue(interfaceSettingKeys[index], value);
            if (index == 3u) g_sfera_interface_runtime.cross_enabled = value;
            optionToggleLabel(window, interfaceControlIds[index], value);
            if (index == 2u) g_sfera_interface_runtime.sounds_enabled = value;
            else if (index != 3u) {
                if (index != 0u && index < std::size(interfaceSettingKeys)) setNamedValue(interfaceSettingKeys[index], value);
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
                auto* lod = g_sfera_recovered_static_runtime.lod_settings;
                if (lod != nullptr) {
                    const double minimum = g_sfera_input_device_runtime.lod_distance.f32, distance = g_sfera_input_device_runtime.minimum_lod_distance.f32;
                    lod->minimum_distance = static_cast<float>(minimum);
                    lod->maximum_distance = static_cast<float>(minimum + distance);
                    lod->far_threshold = static_cast<float>(minimum + distance * 0.5);
                    lod->near_threshold = static_cast<float>(lod->far_threshold * 0.699999988079071);
                }
                setGraphicsOptionsVisible(false);
            } else if (event.control_id == 2u) {
                setGraphicsOptionsVisible(false);
                graphics.fog_distance = g_sfera_sphere_options_runtime.saved_fog_distance.f32;
                g_sfera_input_device_runtime.lod_distance.f32 = g_sfera_sphere_options_runtime.saved_lod_distance.f32;
                g_sfera_client_config_runtime.state_25 = values[9];
                g_sfera_client_config_runtime.state_26 = values[8];
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
                    auto* shadows = g_sfera_shadow_runtime.settings;
                    if (shadows != nullptr) shadows->quality = static_cast<std::uint8_t>(event.first);
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
                g_sfera_client_config_runtime.state_26 = event.first == 0u;
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
                    g_sfera_client_config_runtime.state_25 = automatic;
                    break;
                }
            case 43u:
                {
                    const bool enabled = event.first == 1u;
                    optionText(window, 41u, enabled ? g_sfera_sphere_options_runtime.option_labels[6] : "");
                    optionMessage(window, 46u, UiMessage::setScrollRange, 0u, enabled ? 14u : 0u);
                    if (enabled) optionMessage(window, 46u, UiMessage::setScrollValue, static_cast<std::uint32_t>(static_cast<std::int64_t>(std::trunc(g_sfera_input_device_runtime.lod_distance.f32 - 12.0))));
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
        if (event.control_id == 28u) graphics.fog_distance = static_cast<float>(event.first + 30.0);
        else if (event.control_id == 46u) g_sfera_input_device_runtime.lod_distance.f32 = static_cast<float>(event.first + 12.0);
    }

    void handleFontOptionsEvent(const WindowEvent& event) {
        if (event.message == UiMessage::selectedFontChanged) {
            if (event.control_id == 3u || event.control_id == 4u) editedChatFonts().at(event.control_id - 3u) = event.first;
            return;
        }
        if (event.message == UiMessage::leftClick) {
            if (event.control_id == 1u) savedChatFonts().copyFrom(editedChatFonts());
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
            if (event.message == UiMessage::leftClick && event.control_id == 1u) g_sfera_render_lookup_runtime.initialized = 1u;
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

    template<class T> T* createInitialized() {
        void* storage = SphereUI::Runtime::allocate(sizeof(T));
        if (storage == nullptr) return nullptr;
        std::memset(storage, 0, sizeof(T));
        auto* result = std::construct_at(static_cast<T*>(storage));
        try {
            result->initialize();
        } catch (...) {
            result->destroy(false);
            SphereUI::Runtime::deallocate(result);
            throw;
        }
        return result;
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

        ~ViewportScope() {
            if (changed && restore) SphereUI::InterfaceRenderer::setViewport(saved);
        }

        explicit operator bool() const {
            return changed;
        }
    };

    struct NamedFlag {
        const char* name;
        std::uint32_t value;
    };

    constexpr NamedFlag buttonStyles[] = { {
        "LOSTCHECK", ButtonStyle::releaseOutside
    }, {"NOTIFY_LB", ButtonStyle::repeatWhilePressed}, {"SEND_QUIT", ButtonStyle::sendClose}, {"CENTER_TEXT", ButtonStyle::centerText}, {"SEND_HELP", ButtonStyle::showHelp}};
    constexpr NamedFlag textAlignments[] = { {
        "RIGHT_X", TextAlignment::right
    }, {"RIGHT_Y", TextAlignment::bottom}, {"CENTER_X", TextAlignment::horizontalCenter}, {"CENTER_Y", TextAlignment::verticalCenter}, {"CENTER", TextAlignment::center}, {"RIGHT", TextAlignment::right | TextAlignment::bottom}};
    constexpr NamedFlag imageStyles[] = { {
        "NOTIFY_LB", 1u
    }, {"NOTIFY_FOCUS", 2u}};
    constexpr NamedFlag textStyles[] = { {
        "NOTIFY_CLICK", 1u
    }
    };
    class UiReader {
        SferaSimpleParser& parser;
        const SferaParserRange& range;
        SferaParserRange saved_block{};
        char buffer[1024]{};
    public:
        UiReader(SferaSimpleParser& source, const SferaParserRange& scope) : parser(source), range(scope) {
            parser.getBlockRange(&saved_block);
        }

        ~UiReader() {
            parser.setBlockRange(&saved_block);
        }

        bool block(const char* key, SferaParserRange& result) {
            return parser.findBlock(key, &result, &range, 1);
        }

        bool has(const char* key) {
            return parser.findValue(key, &range);
        }

        const char* token(std::uint32_t index = 0u, bool quoted = false) {
            return quoted ? parser.readQuotedString(index, buffer) : parser.readStringBounded(index, buffer, sizeof(buffer));
        }

        const char* string(const char* key, bool quoted = false) {
            return has(key) ? token(0u, quoted) : nullptr;
        }

        template<class T> void integer(const char* key, T& value) {
            if (has(key)) value = static_cast<T>(parser.readInt(0u));
        }

        template<class T> void boolean(const char* key, T& value) {
            if (has(key)) value = static_cast<T>(parser.readBool(0u));
        }

        bool pair(const char* key, std::int32_t& first, std::int32_t& second) {
            if (!has(key)) return false;
            std::int32_t values[2]{};
            if (!parser.readIntSequence(0u, values, 2u)) return false;
            first = values[0];
            second = values[1];
            return true;
        }

        bool rectangle(const char* key, std::int32_t& left, std::int32_t& top, std::int32_t& right, std::int32_t& bottom) {
            if (!has(key)) return false;
            std::int32_t values[4]{};
            if (!parser.readIntSequence(0u, values, 4u)) return false;
            left = values[0];
            top = values[1];
            right = values[2];
            bottom = values[3];
            return true;
        }

        void color(const char* key, std::uint32_t& color) {
            if (!has(key)) return;
            std::int32_t values[3]{};
            if (!parser.readIntSequence(0u, values, 3u)) return;
            color = UiColor::opaqueBlack | ((values[0] & 255u) << 16u) | ((values[1] & 255u) << 8u) | (values[2] & 255u);
        }

        void rgba(const char* key, std::uint32_t& color) {
            if (!has(key)) return;
            std::int32_t values[4]{};
            if (!parser.readIntSequence(0u, values, 4u)) return;
            color = ((values[3] & 255u) << 24u) | ((values[0] & 255u) << 16u) | ((values[1] & 255u) << 8u) | (values[2] & 255u);
        }

        template<std::size_t Size> void flags(const char* key, std::uint32_t& value, const NamedFlag (&names)[Size], bool reset = false) {
            if (!has(key)) return;
            if (reset) value = 0u;
            for (std::uint32_t index = 0u; index < parser.tokenCount(); index += 2u) {
                const char* name = token(index);
                for (const auto& flag : names) if (SferaSimpleParser::equalsIgnoreCase(name, flag.name)) value |= flag.value;
            }
        }

        void sprite(const char* key, SphereUI::Window& window, SphereUI::UiSprite*& destination) {
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

    void renderLabel(const SphereUI::Window& window, const char* text, std::int32_t x, std::int32_t y, std::uint32_t color, const SphereUI::UiRect& clip, std::uint32_t font = inheritFont) {
        if (text == nullptr || *text == '\0') return;
        SphereUI::InterfaceRenderer::drawText(text, x, y, color, font == inheritFont ? window.font : font, window.font_initialized != 0u, clip, window.alpha == 255u);
    }

    void alignedLabel(const SphereUI::Window& window, std::uint32_t color) {
        const auto bounds = windowBounds(window);
        std::int32_t dx = 0;
        std::int32_t dy = 0;
        if (window.input_mask != 0u) {
            const auto extent = SphereUI::InterfaceRenderer::measureText(window.getText(), window.font, window.font_initialized != 0u);
            if (extent.width < window.width) {
                if ((window.input_mask & TextAlignment::right) != 0u) dx = window.width - extent.width;
                if ((window.input_mask & TextAlignment::horizontalCenter) != 0u) dx = (window.width - extent.width) / 2;
            }
            if (extent.height < window.height) {
                if ((window.input_mask & TextAlignment::bottom) != 0u) dy = window.height - extent.height;
                if ((window.input_mask & TextAlignment::verticalCenter) != 0u) dy = (window.height - extent.height) / 2;
            }
        }
        renderLabel(window, window.getText(), SphereUI::detail::addCoordinate(bounds.left, dx), SphereUI::detail::addCoordinate(bounds.top, dy), color, bounds);
    }

    void appendCircular(SphereUI::UiTextRows& rows, std::uint32_t maximum, std::uint32_t& next, const char* text, std::uint32_t color, std::int32_t offset) {
        if (maximum == 0u || rows.size() < maximum) rows.append(text == nullptr ? " " : text, color, offset);
        else {
            auto& row = rows.at(next % rows.size());
            row.text.assign(text == nullptr ? " " : text);
            row.color = color;
            row.offset = offset;
        }
        if (maximum != 0u) next = (next + 1u) % maximum;
    }

    std::uint32_t modulatedColor(std::uint32_t color, std::uint32_t alpha) {
        return (((color >> 24u) * alpha / 255u) << 24u) | (color & kRgbColorMask);
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
    void storeValue(std::uint32_t address, std::uint32_t value);
    template<class T, class Copy> SphereUI::Window* cloneControl(const T& source, Copy copy) {
        void* storage = SphereUI::Runtime::allocate(sizeof(T));
        if (storage == nullptr) return nullptr;
        std::memset(storage, 0, sizeof(T));
        auto* result = std::construct_at(static_cast<T*>(storage));
        try {
            result->initializeCopy(source);
            copy(*result, source);
        } catch (...) {
            result->destroy(false);
            SphereUI::Runtime::deallocate(result);
            throw;
        }
        return result;
    }

    void notifyParent(SphereUI::Window& window, std::uint32_t message, std::uint32_t first = 0u, std::uint32_t second = 0u) {
        if (auto* owner = window.parent) owner->queueEvent({&window, window.control_id, message, first, second, 0u, 0u});
    }

    template<class T> void destroyOwned(T*& address) {
        auto* control = address;
        address = nullptr;
        if (control != nullptr) control->destroy(true);
    }

    template<class T> void cloneOwned(T*& destination, T* source, SphereUI::Window& owner) {
        auto* original = source;
        auto* copy = original != nullptr ? static_cast<T*>(original->clone()) : nullptr;
        if (original != nullptr && copy == nullptr) throw std::bad_alloc();
        destroyOwned(destination);
        destination = copy;
        if (copy != nullptr) copy->setParent(&owner);
    }

    template<class T> bool loadPart(SphereUI::Window& owner, T*& destination, UiReader& reader, const char* key, const char* filename, SferaSimpleParser& parser, std::uint32_t kind, std::uint32_t id) {
        SferaParserRange part{};
        if (!reader.block(key, part)) return false;
        auto* control = static_cast<T*>(owner.createControl(filename, parser, part, kind, id));
        destroyOwned(destination);
        destination = control;
        if (control != nullptr) control->setParent(&owner);
        return control != nullptr;
    }

    void readAnimation(UiReader& reader, SferaSimpleParser& parser, const char* key, SphereUI::WindowAnimation& animation) {
        const char* name = reader.string(key);
        if (name == nullptr) return;
        animation.kind = static_cast<std::uint8_t>(SphereUI::detail::animationKind(name));
        animation.duration = parser.readFloat(1u);
        animation.distance = parser.readFloat(2u);
        animation.offset = parser.readFloat(3u);
        if (animation.duration == 0.0f) animation.duration = 0.25f;
    }

    bool contains(const SphereUI::UiRect& bounds, std::int32_t x, std::int32_t y) {
        return x >= bounds.left && x < bounds.right && y >= bounds.top && y < bounds.bottom;
    }

    template<class T> void loadNavigationButtons(T& owner, UiReader& reader, const char* filename, SferaSimpleParser& parser, bool defaults, float interval = 0.0f) {
        const char* names[] = {"leftbutton", "rightbutton"};
        SphereUI::ButtonCtrl** destinations[] = {&owner.decrease_button, &owner.increase_button};
        for (std::uint32_t index = 0u; index < 2u; ++index) if (loadPart(owner, *destinations[index], reader, names[index], filename, parser, UiControlKind::button, index + 1u) && defaults) {
            auto* button = *destinations[index];
            button->button_flags |= ButtonStyle::releaseOutside | ButtonStyle::repeatWhilePressed;
            if (interval != 0.0f) button->repeat_interval = interval;
        }
    }

    template<class T> void cloneNavigationButtons(T& destination, const T& source) {
        cloneOwned(destination.decrease_button, source.decrease_button, destination);
        cloneOwned(destination.increase_button, source.increase_button, destination);
    }

    void copyScrollFields(SphereUI::ScrollBar& destination, const SphereUI::ScrollBar& source) {
        destination.scroll_resource = source.scroll_resource;
        destination.thumb_width = source.thumb_width;
        destination.thumb_height = source.thumb_height;
        destination.thumb_x = source.thumb_x;
        destination.thumb_y = source.thumb_y;
        destination.orientation_flags = source.orientation_flags;
        destination.normalized_position = source.normalized_position;
        destination.minimum = source.minimum;
        destination.maximum = source.maximum;
        destination.current = source.current;
        destination.step = source.step;
        destination.page_step = source.page_step;
        destination.dragging_thumb = source.dragging_thumb;
        destination.explicit_step = source.explicit_step;
        destination.notify_changes = source.notify_changes;
        destination.repeat_time_low = source.repeat_time_low;
        destination.repeat_time_high = source.repeat_time_high;
        destination.track_left = source.track_left;
        destination.track_top = source.track_top;
        destination.track_right = source.track_right;
        destination.track_bottom = source.track_bottom;
        destination.page_click_active = source.page_click_active;
        cloneNavigationButtons(destination, source);
    }

    void copySpinFields(SphereUI::SpinButton& destination, const SphereUI::SpinButton& source) {
        destination.minimum = source.minimum;
        destination.maximum = source.maximum;
        destination.current = source.current;
        destination.previous = source.previous;
        destination.step = source.step;
        destination.body = source.body;
        destination.body_index = source.body_index;
        destination.status_valid = source.status_valid;
        destination.notify_changes = source.notify_changes;
        destination.update_enabled = source.update_enabled;
        cloneNavigationButtons(destination, source);
    }

    bool moveScroll(SphereUI::ScrollBar& control, bool increase, std::int32_t amount) {
        const auto limit = increase ? control.maximum : control.minimum;
        if (control.current == limit) return false;
        control.current = increase ? std::min(SphereUI::detail::addCoordinate(control.current, amount), limit) : std::max(SphereUI::detail::subtractCoordinate(control.current, amount), limit);
        control.updateControlState();
        return true;
    }

    void enableNavigationButtons(SphereUI::ScrollBar& control) {
        for (auto address : {control.decrease_button, control.increase_button}) if (auto* button = address) button->handleMessage(UiMessage::setEnabled, control.minimum != control.maximum ? 1u : 0u, 0u);
    }

    std::uint32_t opacity_alpha(double value) {
        return static_cast<std::uint32_t>(static_cast<std::int64_t>(std::trunc(value)));
    }

    void replace_color_alpha(std::uint32_t& color, std::uint32_t alpha) {
        color = (color & kRgbColorMask) | (alpha << 24u);
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
            const auto sprite = UiSprite::create();
            if (sprite == 0u) continue;
            try {
                if (sprite->loadUi(filename, parser, entry)) appendResource(sprite);
                else sprite->destroy();
            } catch (...) {
                sprite->destroy();
                throw;
            }
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
        font_initialized = 1u;
    }
    if (reader.has("alignWin")) for (std::uint32_t index = 0u; index < parser.tokenCount(); index += 2u) alignment_flags |= detail::alignmentFlag(reader.token(index));
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
        if (name != nullptr) if (auto* child = createControl(filename, parser, entry, detail::controlKind(name), ordinal)) {
            try {
                appendChild(child);
            } catch (...) {
                child->destroy(true);
                throw;
            }
            child->control_id = next_id++;
        }
        ++ordinal;
    }
    return true;
}

SphereUI::Window* SphereUI::Window::clone() {
    void* storage = Runtime::allocate(sizeof(Window));
    if (storage == nullptr) return nullptr;
    auto* result = std::construct_at(static_cast<Window*>(storage));
    try {
        result->initializeCopy(*this);
    } catch (...) {
        result->release();
        Runtime::deallocate(result);
        throw;
    }
    return result;
}

std::uint32_t SphereUI::Window::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    if (message >= 3001u && message <= 3500u) {
        auto* tip = tooltip;
        if (tip == nullptr) {
            tip = Runtime::makeControl(UiControlKind::tooltip);
            if (tip == nullptr) return 0u;
            tip->setParent(this);
            tooltip = tip;
        }
        return tip->handleMessage(message, first, second);
    }
    const auto hide_tip = [&] {
        if (auto* tip = tooltip) static_cast<ToolTipCtrl*>(tip)->reset();
    };
    switch (message) {
        case UiMessage::setInputEnabled:
            input_enabled = first != 0u;
            break;
        case UiMessage::getInputEnabled:
            storeValue(first, input_enabled);
            break;
        case UiMessage::setTextRgb:
            text_color = (first & kRgbColorMask) | (alpha << 24u);
            break;
        case UiMessage::setHidden:
            hidden = first != 0u;
            if (hidden != 0u) hide_tip();
            break;
        case UiMessage::getHidden:
            storeValue(first, hidden);
            break;
        case UiMessage::setEnabled:
            disabled = first == 0u;
            if (disabled != 0u) hide_tip();
            break;
        case UiMessage::getDisabled:
            storeValue(first, disabled);
            break;
        case UiMessage::setTextAlignment:
            input_mask = first;
            break;
        case UiMessage::animateVisibility:
            animateVisibility(first != 0u);
            break;
        case UiMessage::setPosition:
            setPosition(static_cast<std::int32_t>(first), static_cast<std::int32_t>(second));
            break;
        case UiMessage::getChildUnderCursor:
            {
                const auto position = CCursorManager::instance().position();
                storeValue(first, static_cast<std::uint32_t>(childControlAt(position.x, position.y)));
                break;
            }
        case UiMessage::getModal:
            storeValue(first, modal_owner != 0u);
            break;
        case UiMessage::endModal:
            if (modal_owner != 0u) {
                modal_owner = 0u;
                handleMessage(UiMessage::animateVisibility, 0u, 0u);
            }
            break;
        case UiMessage::beginModal:
            if (modal_owner == 0u) {
                modal_owner = first;
                handleMessage(UiMessage::animateVisibility, 1u, 0u);
            }
            break;
        case UiMessage::setSize:
            width = static_cast<std::int32_t>(first);
            height = static_cast<std::int32_t>(second);
            break;
        case UiMessage::setFont:
            setFont(first);
            break;
        default:
            break;
    }
    return 1u;
}

void SphereUI::Window::setPosition(std::int32_t new_x, std::int32_t new_y) {
    x = new_x;
    y = new_y;
}

void SphereUI::Window::draw() {
    if (hidden != 0u) return;
    const auto* owner = parent;
    const auto screen_x = detail::addCoordinate(x, owner == nullptr ? 0 : owner->x);
    const auto screen_y = detail::addCoordinate(y, owner == nullptr ? 0 : owner->y);
    if ((behavior_flags & WindowStyle::skipDrawing) == 0u && resource_reference != nullptr) resource_reference->drawNatural(static_cast<float>(screen_x), static_cast<float>(screen_y), (alpha << 24u) | kRgbColorMask);
    if ((behavior_flags & WindowStyle::showTitle) != 0u && text_length != 0u) {
        const auto caption_width = detail::subtractCoordinate(caption_right, caption_left);
        const auto caption_height = detail::subtractCoordinate(caption_bottom, caption_top);
        std::uint32_t font_id = font;
        auto top = detail::addCoordinate(detail::addCoordinate(screen_y, text_offset_y), caption_top);
        const auto measured = InterfaceRenderer::measureText(getText(), font_id, font_initialized != 0u);
        if (static_cast<std::uint32_t>(measured.width) > static_cast<std::uint32_t>(caption_width)) {
            font_id = 2u;
            const auto smaller = InterfaceRenderer::measureText(getText(), font_id, font_initialized != 0u);
            top = detail::addCoordinate(top, static_cast<std::int32_t>((static_cast<std::uint32_t>(measured.height) - static_cast<std::uint32_t>(smaller.height)) >> 1u));
        }
        const auto left = detail::addCoordinate(detail::addCoordinate(screen_x, text_offset_x), caption_left);
        renderLabel(*this, getText(), left, top, text_color, {left, top, detail::addCoordinate(left, detail::addCoordinate(caption_width, 10)), detail::addCoordinate(top, detail::addCoordinate(caption_height, 10))}, font_id);
    }
    detail::forEachChild(*this, [](Window& child) {
        child.draw();
    });
}

void SphereUI::Window::handleInput(const WindowInput& input) {
    if (input_enabled == 0u) return;
    if (hide_after_animation != 0u && animation_active == 0u) {
        hide_after_animation = 0u;
        handleMessage(UiMessage::setHidden, 1u, 0u);
        return;
    }
    if ((input.mouse_flags & MouseInput::leftPress) != 0u && caption_left != caption_right) {
        std::int32_t screen_x = 0;
        std::int32_t screen_y = 0;
        getAbsolutePosition(screen_x, screen_y);
        if (input.mouse_x > detail::addCoordinate(screen_x, caption_left) && input.mouse_x <= detail::addCoordinate(screen_x, caption_right) && input.mouse_y > detail::addCoordinate(screen_y, caption_top) && input.mouse_y <= detail::addCoordinate(screen_y, caption_bottom)) {
            drag_offset_x = detail::subtractCoordinate(screen_x, input.mouse_x);
            drag_offset_y = detail::subtractCoordinate(screen_y, input.mouse_y);
            dragging = 1u;
        }
    }
    if (dragging != 0u) {
        x = detail::addCoordinate(drag_offset_x, input.mouse_x);
        y = detail::addCoordinate(drag_offset_y, input.mouse_y);
        if ((input.mouse_flags & MouseInput::leftRelease) != 0u) {
            dragging = 0u;
            if (save_last_position != 0u) g_sfera_interface.saveWindowPosition(*this);
        }
    }
    detail::forEachChild(*this, [&](Window& child) {
        if (child.disabled != 0u) return;
        if (auto* tip = child.tooltip) tip->handleInput(input);
        child.handleInput(input);
    });
    if (auto* window = overlay; window != nullptr && window->hidden == 0u) window->handleInput(input);
}

void SphereUI::Window::setOpacity(float opacity) {
    const std::uint32_t new_alpha = opacity_alpha(opacity * 255.0);
    alpha = new_alpha;
    replace_color_alpha(text_color, new_alpha);
    replace_color_alpha(disabled_color, new_alpha);
    auto* sentinel = child_sentinel;
    if (sentinel == nullptr) return;
    for (auto* node = sentinel->next; node != sentinel; node = node->next) if (auto* child = node->value) child->setOpacity(opacity);
}

bool SphereUI::Window::hitTest(std::int32_t screen_x, std::int32_t screen_y) {
    if (hidden != 0u) return false;
    auto* sentinel = child_sentinel;
    if (sentinel == nullptr) return true;
    for (auto* node = sentinel->next; node != nullptr && node != sentinel; node = node->next) {
        auto* child = node->value;
        if (child != nullptr && child->can_drag_drop != 0u && child->containsPoint(screen_x, screen_y) && child->hitTest(screen_x, screen_y)) break;
    }
    return true;
}

void SphereUI::Window::dispatchMessage(std::int32_t target_group, std::uint32_t message, std::uint32_t first, std::uint32_t second, std::uint32_t target_kind) {
    detail::forEachChild(*this, [&](Window& child) {
        if (target_group != -1 && child.group != target_group) return;
        if (target_kind == anyControlKind || child.control_kind == target_kind) child.handleMessage(message, first, second);
        if (child.control_kind == UiControlKind::listItem) child.dispatchMessage(target_group, message, first, second, target_kind);
    });
}

void SphereUI::Window::setFont(std::uint32_t font_id) {
    font = static_cast<std::uint8_t>(font_id);
}

std::uint32_t SphereUI::Window::getFont() const {
    return font;
}

void SphereUI::Window::destroy(bool free_storage) {
    std::construct_at(this);
    release();
    if (free_storage) Runtime::deallocate(this);
}

bool SphereUI::ButtonCtrl::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    (void)filename;
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
        std::string_view arguments(parser.token);
        const auto first = arguments.find_first_not_of(numericWhitespace);
        const auto end = first == std::string_view::npos ? first : arguments.find_first_of(numericWhitespace, first);
        arguments = end == std::string_view::npos ? std::string_view{} : arguments.substr(end);
        for (std::uint32_t index = 0u; index < 3u; ++index) {
            std::int32_t modifier = 0;
            if (!readInteger(arguments, modifier, 10)) break;
            if (modifier == 1 || modifier == 2) hotkey |= static_cast<std::uint32_t>(modifier) << (16u + 2u * index);
        }
    }
    hover_color = text_color;
    reader.color("focuscolor", hover_color);
    return true;
}

void SphereUI::ButtonCtrl::copyButtonState(const ButtonCtrl& source) {
    if (this == &source) return;
    visual_state = source.visual_state;
    idle_image = source.idle_image;
    pressed_image = source.pressed_image;
    hover_image = source.hover_image;
    button_flags = source.button_flags;
    hotkey = source.hotkey;
    repeat_time_low = source.repeat_time_low;
    repeat_time_high = source.repeat_time_high;
    pressed = source.pressed;
    repeat_interval = source.repeat_interval;
    hover_color = source.hover_color;
    disabled_image = source.disabled_image;
}

SphereUI::Window* SphereUI::ButtonCtrl::clone() {
    return cloneControl(*this, [](auto& target, const auto& source) {
        target.copyButtonState(source);
    });
}

std::uint32_t SphereUI::ButtonCtrl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    if (message == UiMessage::activateButton) {
        click();
        return 1u;
    }
    return Window::handleMessage(message, first, second);
}

void SphereUI::ButtonCtrl::draw() {
    if (hidden != 0u || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    if ((button_flags & ButtonStyle::stateImages) != 0u) {
        UiSprite* const images[] = {idle_image, pressed_image, hover_image};
        const auto image = disabled != 0u ? disabled_image : images[std::min(visual_state, 2u)];
        if (image != nullptr) image->draw(static_cast<float>(bounds.left), static_cast<float>(bounds.top), static_cast<float>(bounds.right), static_cast<float>(bounds.bottom), (alpha << 24u) | kRgbColorMask);
    }
    if (text_length != 0u) alignedLabel(*this, disabled != 0u ? disabled_color : visual_state == 0u ? text_color : hover_color);
}

void SphereUI::ButtonCtrl::handleInput(const WindowInput& input) {
    if (hidden != 0u || disabled != 0u) return;
    const auto key = hotkey & packedFieldMask;
    const auto modifiers = hotkey >> 16u;
    if (input.key_code != 0u && input.key_code == key && (modifiers == 0u || (input.key_modifiers & modifiers) != 0u)) click();
    if (containsPoint(input.mouse_x, input.mouse_y)) {
        if (visual_state == 0u) visual_state = 2u;
        if ((input.mouse_flags & MouseInput::leftPress) != 0u) {
            visual_state = 1u;
            pressed = 1u;
        }
        bool repeat = false;
        if ((button_flags & ButtonStyle::repeatWhilePressed) != 0u && pressed != 0u && (input.mouse_buttons & 1u) != 0u) {
            const auto previous_time = (static_cast<std::uint64_t>(repeat_time_high) << 32u) | repeat_time_low;
            const auto elapsed = static_cast<float>(static_cast<double>(static_cast<std::int64_t>(Runtime::clockTicks() - previous_time)) / 10000.0);
            if (repeat_interval < elapsed) {
                visual_state = 1u;
                repeat = true;
                const auto time = Runtime::clockTicks();
                repeat_time_low = static_cast<std::uint32_t>(time);
                repeat_time_high = static_cast<std::uint32_t>(time >> 32u);
            }
        }
        if ((input.mouse_flags & MouseInput::leftRelease) != 0u && visual_state == 1u) {
            visual_state = 2u;
            pressed = 0u;
            if ((button_flags & ButtonStyle::repeatWhilePressed) == 0u) {
                Runtime::playClickSound();
                click();
                return;
            }
        }
        if (repeat) click();
    } else {
        if (visual_state != 0u && ((button_flags & ButtonStyle::releaseOutside) != 0u || visual_state == 2u || (input.mouse_buttons & 1u) == 0u)) visual_state = 0u;
        if (pressed != 0u && (input.mouse_buttons & 1u) == 0u) pressed = 0u;
    }
}

void SphereUI::ButtonCtrl::destroy(bool free_storage) {
    release();
    if (free_storage) Runtime::deallocate(this);
}

bool SphereUI::CheckBox::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    (void)filename;
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
    unchecked_image = source.unchecked_image;
    checked_image = source.checked_image;
    unchecked_hover_image = source.unchecked_hover_image;
    checked_hover_image = source.checked_hover_image;
    checked = source.checked;
    hovered = source.hovered;
    image_x = source.image_x;
    image_y = source.image_y;
    button_flags = source.button_flags;
    label_x = source.label_x;
    label_y = source.label_y;
    hover_color = source.hover_color;
}

SphereUI::Window* SphereUI::CheckBox::clone() {
    return cloneControl(*this, [](auto& target, const auto& source) {
        target.copyCheckState(source);
    });
}

std::uint32_t SphereUI::CheckBox::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::setChecked:
            checked = first != 0u;
            return 1u;
        case UiMessage::getChecked:
            if (auto* output = reinterpret_cast<std::uint32_t*>(first)) *output = checked;
            return 1u;
        case UiMessage::activateButton:
            playClickSound();
            return 1u;
        case UiMessage::setEnabled:
            if (first == 0u) checked = 0u;
            break;
        default:
            break;
    }
    return Window::handleMessage(message, first, second);
}

void SphereUI::CheckBox::draw() {
    if (hidden != 0u || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    auto image = checked != 0u ? checked_image : unchecked_image;
    if (hovered != 0u) {
        const auto hover = checked != 0u ? checked_hover_image : unchecked_hover_image;
        if (hover != 0u) image = hover;
    }
    if (image != nullptr) image->drawNatural(static_cast<float>(detail::addCoordinate(bounds.left, image_x)), static_cast<float>(detail::addCoordinate(bounds.top, image_y)), (alpha << 24u) | kRgbColorMask);
    std::int32_t dx = label_x;
    std::int32_t dy = label_y;
    if ((button_flags & ButtonStyle::centerText) != 0u) {
        const auto extent = InterfaceRenderer::measureText(getText(), font, font_initialized != 0u);
        if (extent.width < width) dx = (width - extent.width) / 2;
        if (extent.height < height) dy = (height - extent.height) / 2;
    }
    renderLabel(*this, getText(), detail::addCoordinate(bounds.left, dx), detail::addCoordinate(bounds.top, dy), disabled != 0u ? disabled_color : hovered != 0u ? hover_color : text_color, bounds);
}

void SphereUI::CheckBox::handleInput(const WindowInput& input) {
    hovered = containsPoint(input.mouse_x, input.mouse_y) ? 1u : 0u;
    if (hovered != 0u && (input.mouse_flags & MouseInput::leftPress) != 0u) playClickSound();
}

void SphereUI::CheckBox::playClickSound() {
    checked = checked == 0u;
    if (auto* owner = parent) owner->queueEvent({this, control_id, UiMessage::leftClick, 0u, 0u, 0u, 0u});
    Runtime::playClickSound();
}

void SphereUI::CDescriptionWindow::draw() {
    if (hidden != 0u) return;
    const auto* caption = caption_sprite;
    const auto* lower = bottom_sprite;
    const auto* left = left_sprite;
    const auto* right = right_sprite;
    if (caption == nullptr || lower == nullptr || left == nullptr || right == nullptr) return;
    const auto bounds = windowBounds(*this);
    const auto color = (alpha << 24u) | UiColor::whiteRgb;
    const auto x = static_cast<float>(bounds.left), y = static_cast<float>(bounds.top);
    InterfaceRenderer::drawTexture(nullptr, x - 0.5f + left->width, y - 0.5f + caption->height, static_cast<float>(bounds.right) - 0.5f - right->width, static_cast<float>(bounds.bottom) - 0.5f - lower->height, ((alpha * 166u / 255u) << 24u) | UiColor::frameBackground, 0.0f, 0.0f, false);
    caption_sprite->drawNatural(x, y, color);
    bottom_sprite->drawNatural(x, static_cast<float>(bounds.bottom) - lower->height, color);
    float offset = static_cast<float>(caption->height);
    const auto end = static_cast<float>(height) - lower->height;
    const auto tile = static_cast<float>(left->height);
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

void SphereUI::CDescriptionWindow::destroy(bool free_storage) {
    Runtime::setDescriptionWindow(nullptr);
    Window::destroy(free_storage);
}

void SphereUI::Window::setInputFocus(bool focused, bool submit_on_blur) {
    if (!focused) {
        if (input_enabled != 0u && submit_on_blur) notifyParent(*this, UiMessage::editSubmit);
        input_enabled = 0u;
        return;
    }
    input_enabled = 0u;
    for (const auto kind : {13u, 17u, 23u}) Runtime::broadcastMessage(nullptr, -1, UiMessage::setInputEnabled, 0u, 0u, kind);
    input_enabled = 1u;
}

void SphereUI::EditCtrl::initialize() {
    Window::initialize();
    cursor_x = cursor_y = cursor_offset_x = cursor_offset_y = 0;
    numeric = password = 0u;
    edit_reserved = 0u;
    maximum_symbols = 256u;
    cursor_width = 5;
    password_text = {};
    password_text.capacity = 15u;
    cursor_color = UiColor::whiteRgb;
    cursor_alignment = 0u;
    blink_started = 0u;
    cursor_visible = cursor_uses_text_color = submit_on_blur = 1u;
    cursor_reserved = 0u;
    caret_position = 0;
    observed_length = invalidIndex;
    history_count = history_position = 0u;
    std::memset(history, 0, sizeof(history));
    hidden = input_enabled = 0u;
    control_kind = UiControlKind::edit;
}

void SphereUI::EditCtrl::updatePassword() {
    if (password != 0u && password_text.length != text_length) password_text.assign(std::string(text_length, '*').c_str());
}

void SphereUI::EditCtrl::loadHistory() {
    const auto* owner = parent;
    if (owner == nullptr) return;
    const char* name = detail::stringData(owner->resource_name, owner->resource_name_capacity);
    if (name == nullptr || *name == '\0') return;
    std::ifstream stream(std::string("players\\") + name + ".txt");
    std::string line;
    while (history_count < 99u && std::getline(stream, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        const auto length = std::min(line.size(), std::size_t{252u});
        std::memcpy(history[history_count], line.data(), length);
        history[history_count++][length] = '\0';
    }
    history_position = history_count;
}

void SphereUI::EditCtrl::saveHistory() const {
    if (is_reference != 0u) return;
    const auto* owner = parent;
    if (owner == nullptr) return;
    const char* name = detail::stringData(owner->resource_name, owner->resource_name_capacity);
    if (name == nullptr || std::strcmp(name, "testui") != 0) return;
    std::ofstream stream(std::string("players\\") + name + ".txt");
    for (std::uint32_t index = 0u; index < std::min(history_count, 99u); ++index) stream << history[index] << '\n';
}

void SphereUI::EditCtrl::rememberText() {
    const std::string value(getText(), std::min(text_length, 250u));
    history_count = std::min(history_count, 99u);
    for (std::uint32_t index = 0u; index < history_count; ++index) if (value == history[index]) {
        std::memmove(history[index], history[index + 1u], static_cast<std::size_t>(history_count - index - 1u) * sizeof(history[0]));
        --history_count;
        break;
    }
    if (history_count == 99u) {
        std::memmove(history[0], history[1], 98u * sizeof(history[0]));
        --history_count;
    }
    std::memcpy(history[history_count], value.c_str(), value.size() + 1u);
    ++history_count;
    history_position = history_count;
    history[history_count][0] = '\0';
}

bool SphereUI::EditCtrl::loadUi(const char*, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    reader.integer("maxsymbols", maximum_symbols);
    reader.boolean("numeric", numeric);
    reader.boolean("password", password);
    reader.boolean("enteredOnFocus", submit_on_blur);
    if (reader.has("cursorcolor")) {
        reader.color("cursorcolor", cursor_color);
        cursor_color &= kRgbColorMask;
        cursor_uses_text_color = 0u;
    }
    reader.pair("cursoroffset", cursor_offset_x, cursor_offset_y);
    if (maximum_symbols == 0u) maximum_symbols = 256u;
    cursor_width = InterfaceRenderer::measureText("_", font, true).width + 1;
    input_enabled = 0u;
    loadHistory();
    updatePassword();
    return true;
}

void SphereUI::EditCtrl::copyEditState(const EditCtrl& source) {
    cursor_x = source.cursor_x;
    cursor_y = source.cursor_y;
    cursor_offset_x = source.cursor_offset_x;
    cursor_offset_y = source.cursor_offset_y;
    numeric = source.numeric;
    password = source.password;
    maximum_symbols = source.maximum_symbols;
    cursor_width = source.cursor_width;
    password_text.assign(source.password_text.data());
    cursor_color = source.cursor_color;
    blink_started = source.blink_started;
    cursor_visible = source.cursor_visible;
    cursor_uses_text_color = source.cursor_uses_text_color;
    submit_on_blur = source.submit_on_blur;
    caret_position = source.caret_position;
    observed_length = source.observed_length;
    history_count = source.history_count;
    history_position = source.history_position;
    std::memcpy(history, source.history, sizeof(history));
}

SphereUI::Window* SphereUI::EditCtrl::clone() {
    return cloneControl(*this, [](EditCtrl& target, const EditCtrl& source) {
        target.copyEditState(source);
    });
}

std::uint32_t SphereUI::EditCtrl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::setInputEnabled:
            setInputFocus(first != 0u, submit_on_blur != 0u);
            return 1u;
        case UiMessage::setEditText:
            setText(reinterpret_cast<const char*>(first));
            updatePassword();
            break;
        case UiMessage::getEditText:
            if (auto* output = reinterpret_cast<char*>(first)) {
                const auto length = std::min(text_length, 250u);
                std::memcpy(output, getText(), length);
                output[length] = '\0';
            }
            break;
        case UiMessage::getEditFocus:
            return input_enabled;
        case UiMessage::moveEditCaretToEnd:
            caret_position = static_cast<std::int32_t>(text_length);
            break;
        default:
            break;
    }
    return Window::handleMessage(message, first, second);
}

void SphereUI::EditCtrl::handleInput(const WindowInput& input) {
    if (input_enabled != 0u) Runtime::setTextInputActive(true);
    if (hidden != 0u) return;
    if (input_enabled != 0u) {
        std::string value(getText());
        caret_position = std::clamp(caret_position, 0, static_cast<std::int32_t>(value.size()));
        if (input.character >= 32u && value.size() < maximum_symbols && (numeric == 0u || (input.character >= '0' && input.character <= '9'))) {
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
                caret_position = static_cast<std::int32_t>(value.size());
                break;
            default:
                break;
        }
        if (value != getText()) setText(value.c_str());
        observed_length = text_length;
        updatePassword();
        history_count = std::min(history_count, 99u);
        history_position = std::min(history_position, history_count);
        if ((input.key_code == VK_UP && history_position > 0u) || (input.key_code == VK_DOWN && history_position < history_count)) {
            history_position = input.key_code == VK_UP ? history_position - 1u : history_position + 1u;
            setText(history[history_position]);
            caret_position = static_cast<std::int32_t>(text_length);
            observed_length = text_length;
            updatePassword();
        }
        if (input.key_code == VK_TAB) notifyParent(*this, UiMessage::editTab);
        if (input.key_code == VK_RETURN) {
            notifyParent(*this, UiMessage::editSubmit);
            rememberText();
        }
    }
    if ((input.mouse_flags & MouseInput::leftPress) != 0u) {
        if (!containsPoint(input.mouse_x, input.mouse_y)) setInputFocus(false, submit_on_blur != 0u);
        else if (input_enabled == 0u) setInputFocus(true);
    }
}

void SphereUI::EditCtrl::draw() {
    if (hidden != 0u || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    ViewportScope viewport(bounds);
    if (!viewport) return;
    if (observed_length != text_length) caret_position = static_cast<std::int32_t>(text_length);
    caret_position = std::clamp(caret_position, 0, static_cast<std::int32_t>(text_length));
    updatePassword();
    const char* display = password != 0u ? password_text.data() : getText();
    const auto extent = InterfaceRenderer::measureText(display, font, font_initialized != 0u);
    const auto prefix = std::string(display, caret_position);
    const auto caret_x = InterfaceRenderer::measureText(prefix.c_str(), font, font_initialized != 0u).width;
    const auto full_width = detail::addCoordinate(extent.width, cursor_width);
    std::int32_t dx = 0, dy = extent.height < height ? (height - extent.height) / 2 : 0;
    if (full_width > width) {
        dx = width - full_width;
        if (caret_x < -static_cast<std::int64_t>(dx)) dx = caret_position == 0 ? 0 : cursor_width - caret_x;
    } else {
        if ((input_mask & TextAlignment::horizontalCenter) != 0u) dx = (width - extent.width) / 2;
        if ((input_mask & TextAlignment::right) != 0u) dx = width - full_width;
    }
    if ((input_mask & TextAlignment::bottom) != 0u && extent.height < height) dy = height - extent.height;
    const auto left = detail::addCoordinate(bounds.left, dx), top = detail::addCoordinate(bounds.top, dy);
    renderLabel(*this, display, left, top, text_color, bounds);
    const auto now = Runtime::clockTicks();
    if (blink_started == 0u || now < blink_started) blink_started = now;
    const auto elapsed = now - blink_started;
    if (elapsed > 4000u) cursor_visible = static_cast<std::uint8_t>(((elapsed - 4000u) / 4000u) & 1u);
    if (input_enabled != 0u && cursor_visible != 0u) {
        if (cursor_uses_text_color != 0u) cursor_color = text_color;
        renderLabel(*this, "_", detail::addCoordinate(left, caret_x), detail::addCoordinate(top, cursor_offset_y), (cursor_color & kRgbColorMask) | (alpha << 24u), bounds);
    }
}

void SphereUI::EditCtrl::destroy(bool free_storage) {
    saveHistory();
    password_text.release();
    Runtime::setTextInputActive(false);
    Window::destroy(free_storage);
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
    reader.integer("maxItems", maximum_items);
    parser.setScanRange(&range);
    while (parser.nextValue("addstring")) {
        char key[1024]{}, color_text[1024]{};
        parser.readStringBounded(0u, key, sizeof(key));
        parser.readStringBounded(1u, color_text, sizeof(color_text));
        std::uint32_t color = 0u;
        if (key[0] != '\0' && readHexColor(color_text, color)) addText(g_sfera_interface.localizedText(key), color);
    }
    parser.clearScanRange();
    updateLayout();
    return true;
}

SphereUI::Window* SphereUI::ListCtrl::clone() {
    return cloneControl(*this, [](ListCtrl& destination, const ListCtrl& source) {
        destination.copyListState(source);
    });
}

std::uint32_t SphereUI::ListCtrl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::verticalScroll:
        case UiMessage::setListScroll:
            vertical_offset = static_cast<std::int32_t>(first);
            updateVisibleRange();
            return 1u;
        case UiMessage::updateScrollLayout:
            if (first != 0u) updateLayout();
            else if (auto* bar = scrollbar) bar->setParameters({0u, ScrollField::all, 0, 0, 0, 0, 0});
            return 1u;
        case UiMessage::appendListText:
            {
                const bool at_bottom = detail::addCoordinate(vertical_offset, 5) >= maximum_scroll;
                addText(reinterpret_cast<const char*>(first), second);
                if (chatlike != 0u && at_bottom) {
                    vertical_offset = maximum_scroll;
                    if (auto* bar = scrollbar) bar->setParameters({0u, ScrollField::position, 0, 0, 0, vertical_offset, 0});
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
            selectRow(static_cast<std::int32_t>(first));
            return 1u;
        case UiMessage::getListSelection:
            storeValue(first, static_cast<std::uint32_t>(selected_index));
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
            storeValue(first, static_cast<std::uint32_t>(vertical_offset));
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

void SphereUI::ListCtrl::draw() {
    if (hidden != 0u || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    if (rows.size() != 0u) {
        ViewportScope viewport(bounds);
        if (viewport) {
            auto row_y = detail::subtractCoordinate(bounds.top, cropped_y);
            if (chatlike != 0u && rows.size() < static_cast<std::uint32_t>(std::max(visible_capacity, 0))) row_y = detail::addCoordinate(row_y, detail::subtractCoordinate(height, static_cast<std::int32_t>(rows.size() * static_cast<std::uint32_t>(line_height))));
            const auto first_y = row_y;
            const auto end = std::min(visible_end, static_cast<std::int32_t>(rows.size()));
            const auto mark_width = continue_mark != 0u ? InterfaceRenderer::measureText("  ...", font, font_initialized != 0u).width : 0;
            for (auto index = std::max(visible_begin, 0); index < end; ++index) {
                const auto& row = rows.at(physicalIndex(static_cast<std::uint32_t>(index)));
                auto clip = bounds;
                const auto row_color = (alpha << 24u) | (row.color & kRgbColorMask);
                const auto row_x = detail::addCoordinate(bounds.left, row.offset);
                const bool truncated = continue_mark != 0u && InterfaceRenderer::measureText(row.text.data(), font, font_initialized != 0u).width > width;
                if (truncated) clip.right = detail::subtractCoordinate(clip.right, mark_width);
                InterfaceRenderer::drawText(row.text.data(), row_x, row_y, row_color, font, true, clip, alpha == 255u);
                if (truncated) InterfaceRenderer::drawText("  ...", detail::addCoordinate(bounds.left, detail::addCoordinate(row.offset, detail::subtractCoordinate(width, mark_width))), row_y, row_color, font, true, bounds, alpha == 255u);
                row_y = detail::addCoordinate(row_y, line_height);
            }
            if (selected_index >= visible_begin && selected_index < end) drawSelection(bounds.left, bounds.top, detail::addCoordinate(first_y, static_cast<std::int32_t>(static_cast<std::uint32_t>(selected_index - visible_begin) * static_cast<std::uint32_t>(line_height))), false);
        }
    }
    drawChild(scrollbar, alpha);
}

void SphereUI::ListCtrl::handleInput(const WindowInput& input) {
    if (hidden != 0u) return;
    inputChild(scrollbar, input);
    if (can_select == 0u) {
        selected_index = -1;
        return;
    }
    if (rows.size() == 0u || (input.mouse_flags & MouseInput::leftPress) == 0u || !contains(windowBounds(*this), input.mouse_x, input.mouse_y)) return;
    const auto bounds = windowBounds(*this);
    auto first_y = detail::subtractCoordinate(bounds.top, cropped_y);
    if (chatlike != 0u && rows.size() < static_cast<std::uint32_t>(std::max(visible_capacity, 0))) first_y = detail::addCoordinate(first_y, detail::subtractCoordinate(height, static_cast<std::int32_t>(rows.size() * static_cast<std::uint32_t>(line_height))));
    const auto offset = detail::subtractCoordinate(input.mouse_y, first_y);
    const auto relative = line_height > 0 ? static_cast<std::uint32_t>(offset) / static_cast<std::uint32_t>(line_height) : invalidIndex;
    const auto index = static_cast<std::uint32_t>(visible_begin) + relative;
    const auto selected = index < rows.size() ? static_cast<std::int32_t>(index) : -1;
    if (selected != selected_index) {
        selected_index = selected;
        notifyParent(*this, UiMessage::listSelectionChanged, static_cast<std::uint32_t>(selected));
    }
    const auto now = Runtime::clockTicks();
    if (click_pending == 0u) {
        click_pending = 1u;
        click_time = now;
    } else {
        const auto elapsed = static_cast<float>(static_cast<double>(static_cast<std::int64_t>(now - click_time)) / 10000.0);
        if (elapsed < 0.6f && selected_index >= 0) notifyParent(*this, UiMessage::listDoubleClick, static_cast<std::uint32_t>(selected_index));
        click_pending = 0u;
    }
}

void SphereUI::ListCtrl::destroy(bool free_storage) {
    destroyOwned(scrollbar);
    rows.release();
    Window::destroy(free_storage);
}

SphereUI::Window* SphereUI::FilterListCtrl::clone() {
    return cloneControl(*this, [](FilterListCtrl& destination, const FilterListCtrl& source) {
        destination.copyListState(source);
        destination.filter_mask = source.filter_mask;
        destination.history.copyFrom(source.history);
        destination.history_write = source.history_write;
    });
}

std::uint32_t SphereUI::FilterListCtrl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::appendFilteredListText:
            if (first != 0u) {
                const auto mask = second >> 24u, color = second & kRgbColorMask;
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

void SphereUI::FilterListCtrl::destroy(bool free_storage) {
    history.release();
    ListCtrl::destroy(free_storage);
}

bool SphereUI::FontPicker::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    loadPart(*this, preview, reader, "text", filename, parser, UiControlKind::text, 2u);
    loadPart(*this, selector, reader, "spinButton", filename, parser, UiControlKind::spinButton, 1u);
    return true;
}

SphereUI::Window* SphereUI::FontPicker::clone() {
    return cloneControl(*this, [](FontPicker& destination, const FontPicker& source) {
        cloneOwned(destination.selector, source.selector, destination);
        cloneOwned(destination.preview, source.preview, destination);
        if (auto* selector = destination.selector) {
            selector->setRange(0, static_cast<std::int32_t>(g_sfera_fonts.count() - 1u));
            selector->setStep(1);
            if (auto* preview = destination.preview) selector->setCurrentValue(static_cast<std::int32_t>(preview->getFont() - 2u));
        }
    });
}

std::uint32_t SphereUI::FontPicker::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    if (message == UiMessage::setSelectedFont) {
        setFont(first);
        return 1u;
    }
    if (message == UiMessage::getSelectedFont) {
        if (auto* window = preview) storeValue(first, window->getFont());
        return 1u;
    }
    return Window::handleMessage(message, first, second);
}

void SphereUI::FontPicker::draw() {
    if (hidden != 0u || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    drawChild(selector, alpha);
    drawChild(preview, alpha);
}

void SphereUI::FontPicker::handleInput(const WindowInput& input) {
    if (hidden != 0u) return;
    inputChild(selector, input);
    inputChild(preview, input);
    WindowEvent event{};
    while (pollEvent(event)) {
        if (event.message != UiMessage::spinValueChanged) continue;
        if (auto* window = preview) {
            const auto font_id = event.first + 2u;
            window->setFont(font_id);
            if (auto* owner = parent) owner->queueEvent({this, control_id, UiMessage::selectedFontChanged, font_id, 0u, 0u, 0u});
        }
    }
}

void SphereUI::FontPicker::setFont(std::uint32_t font_id) {
    if (auto* spin = selector) spin->setCurrentValue(static_cast<std::int32_t>(font_id - 2u));
    if (auto* window = preview) window->setFont(font_id);
    Window::setFont(font_id);
}

std::uint32_t SphereUI::FontPicker::getFont() const {
    if (const auto* selector_control = selector) return static_cast<std::uint32_t>(selector_control->currentValue() + 2);
    if (const auto* preview_control = preview) return preview_control->getFont();
    return Window::getFont();
}

void SphereUI::FontPicker::destroy(bool free_storage) {
    destroyOwned(selector);
    destroyOwned(preview);
    Window::destroy(free_storage);
}

bool SphereUI::ImageCtrl::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    (void)filename;
    UiReader reader(parser, range);
    resource_reference = nullptr;
    reader.sprite("image", *this, resource_reference);
    reader.integer("alpha", base_alpha);
    reader.flags("imageStyle", image_style, imageStyles, true);
    if (reader.has("rotate")) handleMessage(UiMessage::setImageRotation, std::bit_cast<std::uint32_t>(parser.readFloat(0u)), 0u);
    return true;
}

void SphereUI::ImageCtrl::copyImageState(const ImageCtrl& source) {
    if (this == &source) return;
    image_style = source.image_style;
    interaction_active = source.interaction_active;
    const auto image = (source.fallback_image == nullptr ? nullptr : source.fallback_image->clone());
    if (fallback_image != nullptr) fallback_image->destroy();
    fallback_image = image;
    if (source.resource_reference == source.fallback_image) resource_reference = fallback_image;
    rotated = source.rotated;
    rotation_radians = source.rotation_radians;
    base_alpha = source.base_alpha;
    opacity = source.opacity;
}

SphereUI::Window* SphereUI::ImageCtrl::clone() {
    return cloneControl(*this, [](auto& target, const auto& source) {
        target.copyImageState(source);
    });
}

std::uint32_t SphereUI::ImageCtrl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
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
                const float degrees = std::bit_cast<float>(first);
                rotated = degrees != 0.0f;
                rotation_radians = degrees / 180.0f * 3.1415929794311523f;
                return 1u;
            }
        case UiMessage::setImageDescription:
            setImage(reinterpret_cast<const ImageDescription*>(first));
            return 1u;
        case UiMessage::setImageAlpha:
            base_alpha = std::min(first, 255u);
            setOpacity(opacity);
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

void SphereUI::ImageCtrl::draw() {
    if (hidden != 0u || resource_reference == nullptr) return;
    const auto bounds = windowBounds(*this);
    resource_reference->draw(static_cast<float>(bounds.left), static_cast<float>(bounds.top), static_cast<float>(bounds.right), static_cast<float>(bounds.bottom), (alpha << 24u) | kRgbColorMask, rotated != 0u ? rotation_radians : 0.0f);
}

void SphereUI::ImageCtrl::handleInput(const WindowInput& input) {
    if (image_style == 0u) return;
    const bool inside = containsPoint(input.mouse_x, input.mouse_y);
    if ((image_style & 2u) != 0u && inside != (interaction_active != 0u)) {
        notifyParent(*this, inside ? UiMessage::pointerEnter : UiMessage::pointerLeave);
        interaction_active = inside;
    }
    if (inside && (image_style & 1u) != 0u && (input.mouse_flags & MouseInput::leftPress) != 0u) {
        std::int32_t left = 0;
        std::int32_t top = 0;
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

void SphereUI::ImageCtrl::destroy(bool free_storage) {
    if (fallback_image != nullptr) {
        fallback_image->destroy();
        fallback_image = nullptr;
    }
    release();
    if (free_storage) Runtime::deallocate(this);
}

bool SphereUI::ListItemCtrl::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    loadPart(*this, vertical_scroll, reader, "vscrollbar", filename, parser, UiControlKind::scrollBar, 1u);
    if (loadPart(*this, horizontal_scroll, reader, "hscrollbar", filename, parser, UiControlKind::scrollBar, 1u)) horizontal_scroll->orientation_flags |= 1u;
    SferaParserRange part{};
    if (reader.block("itemTemplate", part)) {
        auto* original = createInitialized<Window>();
        if (original == nullptr) throw std::bad_alloc();
        try {
            original->setParent(parent);
            if (!original->loadUi(filename, parser, part)) throw std::runtime_error("list item template could not be loaded");
            original->setParent(nullptr);
            original->hidden = 0u;
            original->resource_parent = parent;
            original->input_enabled = 1u;
        } catch (...) {
            original->destroy(true);
            throw;
        }
        destroyOwned(item_template);
        item_template = original;
    }
    std::int32_t count = 0;
    reader.integer("createItems", count);
    for (std::int32_t index = 0; index < count; ++index) addItem();
    reader.sprite("selectSprite", *this, selection_sprite);
    reader.integer("selectedItem", selected_index);
    if (static_cast<std::uint32_t>(selected_index) >= items.size()) selected_index = -1;
    reader.boolean("canSelectItems", can_select);
    reader.boolean("horizontal", horizontal);
    reader.boolean("userMove", user_move);
    updateLayout();
    return true;
}

SphereUI::Window* SphereUI::ListItemCtrl::clone() {
    return cloneControl(*this, [](ListItemCtrl& destination, const ListItemCtrl& source) {
        destination.copyItemState(source);
    });
}

std::uint32_t SphereUI::ListItemCtrl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::horizontalScroll:
            horizontal_offset = static_cast<std::int32_t>(first);
            updateVisibleRange();
            return 1u;
        case UiMessage::verticalScroll:
            vertical_offset = static_cast<std::int32_t>(first);
            updateVisibleRange();
            return 1u;
        case UiMessage::updateScrollLayout:
            if (first != 0u) updateLayout();
            else for (auto address : {vertical_scroll, horizontal_scroll}) if (auto* bar = address) bar->setParameters({0u, ScrollField::all, 0, 0, 0, 0, 0});
            return 1u;
        case UiMessage::appendListItem:
            addItem();
            updateLayout();
            return 1u;
        case UiMessage::getListItemSelection:
            storeValue(first, static_cast<std::uint32_t>(selected_index));
            return 1u;
        case UiMessage::setListItemSelection:
            selected_index = first < items.size() ? static_cast<std::int32_t>(first) : -1;
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
    if (hidden != 0u || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    drawChild(vertical_scroll, alpha);
    drawChild(horizontal_scroll, alpha);
    if (item_template == nullptr) return;
    const auto end = std::min(visible_end, static_cast<std::int32_t>(items.size()));
    {
        ViewportScope viewport(windowBounds(*this));
        if (!viewport) return;
        if (selected_index >= std::max(visible_begin, 0) && selected_index < end) if (auto* item = itemAt(static_cast<std::uint32_t>(selected_index))) {
            const auto left = static_cast<float>(item->x), top = static_cast<float>(item->y), right = static_cast<float>(detail::addCoordinate(item->x, item->width)), bottom = static_cast<float>(detail::addCoordinate(item->y, item->height));
            if (selection_sprite != nullptr) selection_sprite->draw(left, top, right, bottom, (alpha << 24u) | UiColor::whiteRgb);
            else InterfaceRenderer::drawTexture(nullptr, left, top, right, bottom, text_color, 0.0f, 0.0f, false);
        }
        for (auto index = std::max(visible_begin, 0); index < end; ++index) if (auto* item = itemAt(static_cast<std::uint32_t>(index))) item->draw();
    }
    for (auto index = std::max(visible_begin, 0); index < end; ++index) if (auto* item = itemAt(static_cast<std::uint32_t>(index))) item->drawToolTips();
}

void SphereUI::ListItemCtrl::handleInput(const WindowInput& input) {
    if (hidden != 0u) return;
    inputChild(vertical_scroll, input);
    inputChild(horizontal_scroll, input);
    if (can_select == 0u) selected_index = -1;
    for (std::uint32_t index = 0u; index < items.size(); ++index) if (auto* item = itemAt(index)) {
        WindowEvent event{};
        while (item->pollEvent(event)) if (auto* owner = parent) owner->queueEvent({this, control_id, UiMessage::listItemEvent, event.message, ((event.control_id & packedFieldMask) << 16u) | (index & packedFieldMask), event.first, event.second});
    }
    const auto bounds = windowBounds(*this);
    const bool inside = contains(bounds, input.mouse_x, input.mouse_y);
    WindowInput forwarded = input;
    if (!inside) forwarded.mouse_x = forwarded.mouse_y = 65535;
    const auto* original = item_template;
    if (original == nullptr) return;
    const auto end = std::min(visible_end, static_cast<std::int32_t>(items.size()));
    auto item_x = detail::subtractCoordinate(bounds.left, cropped_x), item_y = detail::subtractCoordinate(bounds.top, cropped_y);
    for (auto index = std::max(visible_begin, 0); index < end; ++index) if (auto* item = itemAt(static_cast<std::uint32_t>(index))) {
        if (user_move != 0u) item->setParent(this);
        else item->setPosition(item_x, item_y);
        item->handleInput(forwarded);
        if (horizontal != 0u) item_x = detail::addCoordinate(item_x, original->width);
        else item_y = detail::addCoordinate(item_y, original->height);
    }
    if (can_select == 0u || !inside || (input.mouse_flags & MouseInput::leftPress) == 0u) return;
    std::int32_t selected = -1;
    for (auto index = std::max(visible_begin, 0); index < end; ++index) if (auto* item = itemAt(static_cast<std::uint32_t>(index))) if (contains(windowBounds(*item), input.mouse_x, input.mouse_y)) {
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
    if (auto* original = item_template) original->setOpacity(opacity);
    for (std::uint32_t index = 0u; index < items.size(); ++index) if (auto* item = itemAt(index)) item->setOpacity(opacity);
}

bool SphereUI::ListItemCtrl::hitTest(std::int32_t screen_x, std::int32_t screen_y) {
    const auto end = std::min(visible_end, static_cast<std::int32_t>(items.size()));
    if (hidden != 0u || visible_begin >= end) return false;
    for (auto index = std::max(visible_begin, 0); index < end; ++index) if (auto* child = itemAt(static_cast<std::uint32_t>(index))) if (child->can_drag_drop != 0u && child->containsPoint(screen_x, screen_y) && child->hitTest(screen_x, screen_y)) break;
    return true;
}

void SphereUI::ListItemCtrl::dispatchMessage(std::int32_t target_group, std::uint32_t message, std::uint32_t first, std::uint32_t second, std::uint32_t target_kind) {
    for (std::uint32_t index = 0u; index < items.size(); ++index) if (auto* child = itemAt(index)) child->dispatchMessage(target_group, message, first, second, target_kind);
}

void SphereUI::ListItemCtrl::destroy(bool free_storage) {
    destroyOwned(item_template);
    clearItems();
    destroyOwned(vertical_scroll);
    destroyOwned(horizontal_scroll);
    items.release();
    Window::destroy(free_storage);
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

SphereUI::Window* SphereUI::ToolTipCtrl::clone() {
    return cloneControl(*this, [](ToolTipCtrl& destination, const ToolTipCtrl& source) {
        destination.copyTipState(source);
    });
}

std::uint32_t SphereUI::ToolTipCtrl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
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
            return message >= 3001u && message <= 3500u ? 0u : Window::handleMessage(message, first, second);
    }
}

void SphereUI::ToolTipCtrl::draw() {
    if (hidden != 0u) return;
    const auto screen = Runtime::screenSize();
    screen_x = std::max(0, std::min(screen_x, detail::subtractCoordinate(screen.width, tooltip_width)));
    screen_y = std::max(0, std::min(screen_y, detail::subtractCoordinate(screen.height, tooltip_height)));
    const auto* owner = parent;
    const auto opacity = static_cast<std::uint32_t>(std::clamp(static_cast<float>(owner == nullptr ? alpha : owner->alpha) * fade_opacity, 0.0f, 255.0f));
    text_color = (text_color & kRgbColorMask) | (opacity << 24u);
    const auto right = detail::addCoordinate(screen_x, tooltip_width), bottom = detail::addCoordinate(screen_y, tooltip_height);
    const auto leftf = static_cast<float>(screen_x), topf = static_cast<float>(screen_y), rightf = static_cast<float>(right), bottomf = static_cast<float>(bottom);
    InterfaceRenderer::drawTexture(nullptr, leftf, topf, rightf, bottomf, background_color | (opacity << 24u), 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, leftf, topf, rightf, topf + 1.0f, text_color, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, leftf, bottomf - 1.0f, rightf, bottomf, text_color, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, leftf, topf, leftf + 1.0f, bottomf, text_color, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, rightf - 1.0f, topf, rightf, bottomf, text_color, 0.0f, 0.0f, false);
    const auto text_x = detail::addCoordinate(screen_x, margin_left);
    auto text_y = detail::addCoordinate(screen_y, margin_top);
    const UiRect clip{text_x, text_y, detail::addCoordinate(text_x, tooltip_width), detail::addCoordinate(text_y, tooltip_height)};
    for (std::uint32_t index = 0u; index < lines.size(); ++index) {
        InterfaceRenderer::drawText(lines.at(index).data(), text_x, text_y, text_color, font, true, clip, opacity == 255u);
        text_y = detail::addCoordinate(text_y, line_height);
    }
}

void SphereUI::ToolTipCtrl::handleInput(const WindowInput& input) {
    if (lines.size() == 0u || lines.at(0u).length == 0u) {
        hidden = 1u;
        return;
    }
    updateFade();
    auto* owner = parent;
    if (owner == nullptr || owner->hidden != 0u) return;
    if ((input.mouse_flags & 3u) != 0u || input.wheel_delta != 0) {
        dismissed = 1u;
        hidden = 1u;
    }
    if (hidden != 0u && dismissed == 0u) {
        if (hover_pending == 0u || screen_x != input.mouse_x || screen_y != input.mouse_y) hover_pending = 0u;
        else if (static_cast<float>(static_cast<double>(static_cast<std::int64_t>(Runtime::clockTicks() - hover_started)) / 10000.0) > 0.5f) showAt(input.mouse_x, input.mouse_y);
    }
    if (!contains(windowBounds(*owner), input.mouse_x, input.mouse_y)) {
        reset();
        return;
    }
    if (hover_pending == 0u && hidden != 0u) {
        hover_pending = 1u;
        screen_x = input.mouse_x;
        screen_y = input.mouse_y;
        hover_started = Runtime::clockTicks();
    }
}

void SphereUI::ToolTipCtrl::destroy(bool free_storage) {
    lines.release();
    Window::destroy(free_storage);
}

SphereUI::Window* SphereUI::MiniHelpCtrl::clone() {
    return cloneControl(*this, [](MiniHelpCtrl& destination, const MiniHelpCtrl& source) {
        destination.copyTipState(source);
    });
}

void SphereUI::MiniHelpCtrl::handleInput(const WindowInput& input) {
    updateFade();
}

SphereUI::Window* SphereUI::CMinimapControl::clone() {
    if (auto* owner = parent) resource_reference = owner->getResource("arup");
    return cloneControl(*this, [](CMinimapControl&, const CMinimapControl&) {
    });
}

std::uint32_t SphereUI::CMinimapControl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    return Window::handleMessage(message, first, second);
}

void SphereUI::CMinimapControl::draw() {
    if (hidden != 0u) return;
    const auto bounds = windowBounds(*this);
    const auto left = static_cast<float>(bounds.left), top = static_cast<float>(bounds.top);
    InterfaceRenderer::drawTexture(g_sfera_graphics_runtime.d3d_runtime->minimapTexture().native_texture, left, top, left + 256.0f, top + 256.0f, (alpha << 24u) | UiColor::whiteRgb);
    float heading = 0.0f;
    if (Runtime::playerHeading(heading) && resource_reference != nullptr) {
        std::int32_t parent_x = 0, parent_y = 0;
        if (auto* owner = parent) owner->getAbsolutePosition(parent_x, parent_y);
        const auto arrow_x = static_cast<float>(detail::addCoordinate(parent_x, 127)), arrow_y = static_cast<float>(detail::addCoordinate(parent_y, 132));
        resource_reference->draw(arrow_x, arrow_y, arrow_x + 28.0f, arrow_y + 28.0f, UiColor::white, -heading);
    }
}

void SphereUI::CMinimapControl::destroy(bool free_storage) {
    Window::destroy(free_storage);
}

void SphereUI::ProgressBar::initializeProgressState() {
    minimum = 0;
    maximum = 100;
    current = 0;
    progress_ratio = 0.0f;
    display_mode = 0u;
    status_text[0] = '\0';
    status_x = 0;
    status_y = 0;
}

void SphereUI::ProgressBar::setProgressValue(std::int32_t value) {
    if (current == value) return;
    current = std::clamp(value, minimum, maximum);
    refreshProgressDisplay();
}

void SphereUI::ProgressBar::setProgressRange(std::int32_t new_minimum, std::int32_t new_maximum) {
    minimum = new_minimum;
    maximum = new_maximum;
    current = minimum;
    if (minimum >= maximum) maximum = detail::addCoordinate(minimum, 1);
    refreshProgressDisplay();
}

void SphereUI::ProgressBar::copyProgressState(const ProgressBar& source) {
    minimum = source.minimum;
    maximum = source.maximum;
    current = source.current;
    progress_ratio = source.progress_ratio;
    display_mode = source.display_mode;
    std::memcpy(status_text, source.status_text, sizeof(status_text));
    status_x = source.status_x;
    status_y = source.status_y;
}

void SphereUI::ProgressBar::refreshProgressDisplay() {
    const std::int32_t range = detail::subtractCoordinate(maximum, minimum);
    progress_ratio = range == 0 ? 0.0f : std::min(std::fabs(static_cast<float>(current) / static_cast<float>(range)), 1.0f);
    if (display_mode == 1u) std::snprintf(status_text, sizeof(status_text), "%d%%", static_cast<int>(std::trunc(progress_ratio * 100.0f)));
    else if (display_mode == 2u) std::snprintf(status_text, sizeof(status_text), "%d / %d", current, range);
}

bool SphereUI::ProgressBar::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    (void)filename;
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

SphereUI::Window* SphereUI::ProgressBar::clone() {
    return cloneControl(*this, [](auto& target, const auto& source) {
        target.copyProgressState(source);
    });
}

std::uint32_t SphereUI::ProgressBar::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    if (message < 2001u || message > 2010u) return Window::handleMessage(message, first, second);
    switch (message) {
        case UiMessage::setProgressValue:
            setProgressValue(static_cast<std::int32_t>(first));
            return 1u;
        case UiMessage::setProgressRange:
            setProgressRange(static_cast<std::int32_t>(first), static_cast<std::int32_t>(second));
            return 1u;
        case UiMessage::getProgressRange:
            if (auto* output = reinterpret_cast<std::int32_t*>(first)) *output = minimum;
            if (auto* output = reinterpret_cast<std::int32_t*>(second)) *output = maximum;
            return 1u;
        case UiMessage::getProgressValue:
            if (auto* output = reinterpret_cast<std::int32_t*>(first)) *output = current;
            return 1u;
        default:
            return 0u;
    }
}

void SphereUI::ProgressBar::draw() {
    if (hidden != 0u || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    if (progress_ratio > 0.0f && resource_reference != nullptr) resource_reference->draw(static_cast<float>(bounds.left), static_cast<float>(bounds.top), static_cast<float>(bounds.left) + static_cast<float>(width) * progress_ratio, static_cast<float>(bounds.bottom), (alpha << 24u) | kRgbColorMask);
    if (display_mode != 0u) {
        const auto left = detail::addCoordinate(bounds.left, status_x);
        const auto top = detail::addCoordinate(bounds.top, status_y);
        renderLabel(*this, status_text, left, top, text_color, {left, top, detail::addCoordinate(left, 100), detail::addCoordinate(top, 100)});
    }
}

void SphereUI::ProgressBar::handleInput(const WindowInput& input) {
    (void)input;
}

SphereUI::Window* SphereUI::RadioButtonCtrl::clone() {
    return cloneControl(*this, [](auto& target, const auto& source) {
        target.copyCheckState(source);
    });
}

void SphereUI::RadioButtonCtrl::playClickSound() {
    if (checked == 0u) if (auto* owner = parent) owner->dispatchMessage(group, UiMessage::setChecked, 0u, 0u, UiControlKind::radioButton);
    checked = 0u;
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
        explicit_step = 1u;
    }
    updateControlState();
    return true;
}

SphereUI::Window* SphereUI::ScrollBar::clone() {
    return cloneControl(*this, copyScrollFields);
}

std::uint32_t SphereUI::ScrollBar::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::setScrollValue:
            current = std::min(std::max(static_cast<std::int32_t>(first), minimum), maximum);
            updateControlState();
            return 1u;
        case UiMessage::setScrollRange:
            minimum = current = static_cast<std::int32_t>(first);
            maximum = static_cast<std::int32_t>(second);
            enableNavigationButtons(*this);
            updateControlState();
            return 1u;
        case UiMessage::getScrollRange:
            storeValue(first, static_cast<std::uint32_t>(minimum));
            storeValue(second, static_cast<std::uint32_t>(maximum));
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
            storeValue(first, static_cast<std::uint32_t>(current));
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

void SphereUI::ScrollBar::draw() {
    if (hidden != 0u || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    const auto color = (alpha << 24u) | kRgbColorMask;
    if (resource_reference != nullptr) resource_reference->draw(static_cast<float>(bounds.left), static_cast<float>(bounds.top), static_cast<float>(bounds.right), static_cast<float>(bounds.bottom), color);
    if (maximum > minimum) {
        const auto left = detail::addCoordinate(bounds.left, thumb_x);
        const auto top = detail::addCoordinate(bounds.top, thumb_y);
        if (scroll_resource != nullptr) scroll_resource->draw(static_cast<float>(left), static_cast<float>(top), static_cast<float>(detail::addCoordinate(left, thumb_width)), static_cast<float>(detail::addCoordinate(top, thumb_height)), color);
    }
    drawChild(decrease_button, alpha);
    drawChild(increase_button, alpha);
}

void SphereUI::ScrollBar::handleInput(const WindowInput& input) {
    inputChild(decrease_button, input);
    inputChild(increase_button, input);
    bool changed = false;
    WindowEvent event{};
    while (pollEvent(event)) if (event.message == UiMessage::leftClick && (event.control_id == 1u || event.control_id == 2u)) if (moveScroll(*this, event.control_id == 2u, step)) {
        changed = true;
        Runtime::playScrollSound(false);
    }
    if (input.wheel_delta != 0) if (auto* owner = parent) if (contains(windowBounds(*owner), input.mouse_x, input.mouse_y)) {
        if (current != minimum && current != maximum) Runtime::playScrollSound(false);
        current = static_cast<std::int32_t>(static_cast<std::uint32_t>(current) - static_cast<std::uint32_t>(step) * static_cast<std::uint32_t>(input.wheel_delta));
        current = std::max(std::min(current, maximum), minimum);
        updateControlState();
        changed = true;
    }
    const auto bounds = windowBounds(*this);
    const auto thumb_left = detail::addCoordinate(bounds.left, thumb_x);
    const auto thumb_top = detail::addCoordinate(bounds.top, thumb_y);
    if ((input.mouse_flags & MouseInput::leftPress) != 0u && dragging_thumb == 0u) {
        if (contains({thumb_left, thumb_top, detail::addCoordinate(thumb_left, thumb_width), detail::addCoordinate(thumb_top, thumb_height)}, input.mouse_x, input.mouse_y)) dragging_thumb = 1u;
        if (contains(bounds, input.mouse_x, input.mouse_y)) page_click_active = 1u;
    }
    if ((input.mouse_buttons & 1u) == 0u) dragging_thumb = page_click_active = 0u;
    const bool horizontal = (orientation_flags & 1u) != 0u;
    const auto span = detail::subtractCoordinate(maximum, minimum);
    if (dragging_thumb != 0u) {
        const auto dimension = static_cast<std::uint32_t>(horizontal ? width : height);
        const auto relative = std::max(detail::subtractCoordinate(horizontal ? input.mouse_x : input.mouse_y, horizontal ? bounds.left : bounds.top), 0);
        const auto position = std::min(static_cast<std::uint32_t>(relative), dimension);
        const auto fraction = dimension == 0u ? 0.0f : static_cast<float>(static_cast<double>(position) / dimension);
        const auto value = static_cast<std::int32_t>(std::trunc(static_cast<double>(fraction) * span));
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
    if (dragging_thumb != 0u || page_click_active == 0u || (input.mouse_buttons & 1u) == 0u) return;
    const auto previous_time = (static_cast<std::uint64_t>(repeat_time_high) << 32u) | repeat_time_low;
    const auto elapsed = static_cast<float>(static_cast<double>(static_cast<std::int64_t>(Runtime::clockTicks() - previous_time)) / 10000.0);
    if (!(elapsed > 0.1f)) return;
    const auto now = Runtime::clockTicks();
    repeat_time_low = static_cast<std::uint32_t>(now);
    repeat_time_high = static_cast<std::uint32_t>(now >> 32u);
    const UiRect track{detail::addCoordinate(bounds.left, track_left), detail::addCoordinate(bounds.top, track_top), detail::subtractCoordinate(bounds.right, track_right), detail::subtractCoordinate(bounds.bottom, track_bottom)};
    if (!contains(track, input.mouse_x, input.mouse_y)) return;
    const auto dimension = static_cast<std::uint32_t>(horizontal ? detail::subtractCoordinate(track.right, track.left) : detail::subtractCoordinate(track.bottom, track.top));
    if (dimension == 0u) return;
    const auto position = detail::subtractCoordinate(horizontal ? input.mouse_x : input.mouse_y, horizontal ? track.left : track.top);
    const auto fraction = static_cast<float>(static_cast<double>(position) / dimension);
    const auto target = static_cast<std::int32_t>(std::trunc(static_cast<double>(fraction) * span));
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

void SphereUI::ScrollBar::destroy(bool free_storage) {
    destroyOwned(decrease_button);
    destroyOwned(increase_button);
    Window::destroy(free_storage);
}

void SphereUI::ScrollBar::updateControlState() {
    const auto span = detail::subtractCoordinate(maximum, minimum);
    normalized_position = span == 0 ? 0.0f : std::clamp(static_cast<float>(static_cast<double>(current) / span), 0.0f, 1.0f);
    const auto available_width = detail::subtractCoordinate(detail::subtractCoordinate(width, track_left), track_right);
    const auto available_height = detail::subtractCoordinate(detail::subtractCoordinate(height, track_top), track_bottom);
    const auto horizontal_space = detail::subtractCoordinate(available_width, thumb_width);
    const auto vertical_space = detail::subtractCoordinate(available_height, thumb_height);
    thumb_x = detail::addCoordinate(track_left, (orientation_flags & 1u) != 0u ? static_cast<std::int32_t>(std::trunc(static_cast<double>(horizontal_space) * normalized_position)) : horizontal_space / 2);
    thumb_y = detail::addCoordinate(track_top, (orientation_flags & 1u) != 0u ? vertical_space / 2 : static_cast<std::int32_t>(std::trunc(static_cast<double>(vertical_space) * normalized_position)));
}

void SphereUI::ScrollBar::loadControlParameters() {
    auto* owner = parent;
    if (owner == nullptr) return;
    const auto message = (orientation_flags & 1u) != 0u ? UiMessage::horizontalScroll : UiMessage::verticalScroll;
    owner->handleMessage(message, static_cast<std::uint32_t>(current), control_id);
    if (notify_changes != 0u) owner->queueEvent({this, control_id, message, static_cast<std::uint32_t>(current), 0u, 0u, 0u});
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

SphereUI::Window* SphereUI::SliderCtrl::clone() {
    return cloneControl(*this, [](SliderCtrl& destination, const SliderCtrl& source) {
        copyScrollFields(destination, source);
        std::copy(std::begin(source.value_text), std::end(source.value_text), std::begin(destination.value_text));
        destination.display_mode = source.display_mode;
        destination.status_x = source.status_x;
        destination.status_y = source.status_y;
    });
}

void SphereUI::SliderCtrl::draw() {
    if (hidden != 0u) return;
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
    if (display_mode == 1u) std::snprintf(value_text, sizeof(value_text), "%d%%", static_cast<std::int32_t>(std::trunc(normalized_position * 100.0)));
    else if (display_mode == 2u) std::snprintf(value_text, sizeof(value_text), "%d / %d", current, detail::subtractCoordinate(maximum, minimum));
}

void SphereUI::SliderCtrl::loadControlParameters() {
    if (auto* owner = parent) owner->queueEvent({this, control_id, UiMessage::sliderValueChanged, static_cast<std::uint32_t>(current), 0u, 0u, 0u});
}

bool SphereUI::SlotCtrl::hitTest(std::int32_t screen_x, std::int32_t screen_y) {
    (void)screen_x;
    (void)screen_y;
    if (hidden != 0u) return false;
    if (auto* owner = parent) owner->queueEvent({this, control_id, UiMessage::slotHitTest, 0u, 0u, 0u, 0u});
    return true;
}

void SphereUI::SpinButton::setRange(std::int32_t new_minimum, std::int32_t new_maximum) {
    minimum = new_minimum;
    maximum = new_maximum;
    status_valid = 0u;
}

void SphereUI::SpinButton::setCurrentValue(std::int32_t value) {
    current = value;
    status_valid = 0u;
    update_enabled = 0u;
}

void SphereUI::SpinButton::setStep(std::int32_t new_step) {
    step = new_step;
}

std::int32_t SphereUI::SpinButton::currentValue() const {
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
    status_valid = 0u;
    step = 1;
    return true;
}

SphereUI::Window* SphereUI::SpinButton::clone() {
    return cloneControl(*this, copySpinFields);
}

std::uint32_t SphereUI::SpinButton::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::setSpinValue:
            setCurrentValue(static_cast<std::int32_t>(first));
            return 1u;
        case UiMessage::setSpinRange:
            setRange(static_cast<std::int32_t>(first), static_cast<std::int32_t>(second));
            return 1u;
        case UiMessage::getSpinRange:
            storeValue(first, static_cast<std::uint32_t>(minimum));
            storeValue(second, static_cast<std::uint32_t>(maximum));
            return 1u;
        case UiMessage::updateSpinStatus:
            updateStatus();
            return 1u;
        case UiMessage::setSpinStep:
            setStep(static_cast<std::int32_t>(first));
            return 1u;
        case UiMessage::getSpinStep:
            storeValue(first, static_cast<std::uint32_t>(step));
            return 1u;
        case UiMessage::getSpinValue:
            storeValue(first, static_cast<std::uint32_t>(current));
            return 1u;
        default:
            break;
    }
    if (message == UiMessage::setEnabled || message == UiMessage::setHidden) {
        if (auto* window = decrease_button) window->handleMessage(message, first, second);
        if (auto* window = increase_button) window->handleMessage(message, first, second);
    }
    return Window::handleMessage(message, first, second);
}

void SphereUI::SpinButton::draw() {
    if (hidden != 0u) return;
    drawChild(decrease_button, alpha);
    drawChild(increase_button, alpha);
}

void SphereUI::SpinButton::handleInput(const WindowInput& input) {
    if (hidden != 0u) return;
    if (disabled == 0u) {
        if (auto* window = increase_button) window->handleMessage(UiMessage::setEnabled, current != maximum, 0u);
        if (auto* window = decrease_button) window->handleMessage(UiMessage::setEnabled, current != minimum, 0u);
    }
    inputChild(decrease_button, input);
    inputChild(increase_button, input);
    WindowEvent event{};
    while (pollEvent(event)) {
        if (event.message != UiMessage::leftClick) continue;
        if (event.control_id == 1u && current >= detail::addCoordinate(minimum, step)) {
            current = detail::subtractCoordinate(current, step);
            status_valid = 0u;
        }
        if (event.control_id == 2u && current <= detail::subtractCoordinate(maximum, step)) {
            current = detail::addCoordinate(current, step);
            status_valid = 0u;
        }
    }
    if (status_valid == 0u) updateStatus();
}

void SphereUI::SpinButton::destroy(bool free_storage) {
    destroyOwned(decrease_button);
    destroyOwned(increase_button);
    Window::destroy(free_storage);
}

void SphereUI::SpinButton::updateStatus() {
    auto* owner = parent;
    if (owner == nullptr) return;
    if (body == nullptr && body_index != invalidIndex) {
        if (body_index == 0u) body = parent;
        else {
            std::uint32_t index = 0u;
            detail::forEachChild(*owner, [&](Window& child) {
                if (++index == body_index) body = &child;
            });
        }
    }
    if (current < minimum) current = minimum;
    if (current > maximum) current = maximum;
    if (current != previous) {
        if (auto* window = body) {
            char value[32];
            std::snprintf(value, sizeof(value), "%d", current);
            window->setText(value);
        }
        if (notify_changes != 0u && update_enabled != 0u) owner->queueEvent({this, control_id, UiMessage::spinValueChanged, static_cast<std::uint32_t>(current), 0u, 0u, 0u});
        previous = current;
    }
    status_valid = 1u;
    update_enabled = 1u;
}

bool SphereUI::TextCtrl::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    (void)filename;
    UiReader reader(parser, range);
    if ((width == 0 || height == 0) && text_length != 0u) {
        const auto extent = InterfaceRenderer::measureText(getText(), font, font_initialized != 0u);
        width = extent.width;
        height = extent.height;
    }
    reader.flags("textStyle", text_style, textStyles, true);
    return true;
}

SphereUI::Window* SphereUI::TextCtrl::clone() {
    return cloneControl(*this, [](auto& target, const auto& source) {
        target.text_style = source.text_style;
    });
}

void SphereUI::TextCtrl::draw() {
    if (hidden == 0u && text_length != 0u) alignedLabel(*this, text_color);
}

void SphereUI::TextCtrl::handleInput(const WindowInput& input) {
    if ((text_style & 1u) != 0u && (input.mouse_flags & MouseInput::leftPress) != 0u && containsPoint(input.mouse_x, input.mouse_y)) notifyParent(*this, UiMessage::leftClick);
}

void SphereUI::Window::setParent(Window* new_parent) {
    parent = new_parent;
}

void SphereUI::Window::getAbsolutePosition(std::int32_t& screen_x, std::int32_t& screen_y) const {
    screen_x = x;
    screen_y = y;
    for (auto* ancestor = parent; ancestor != nullptr; ancestor = ancestor->parent) {
        screen_x = detail::addCoordinate(screen_x, ancestor->x);
        screen_y = detail::addCoordinate(screen_y, ancestor->y);
    }
}

bool SphereUI::Window::containsPoint(std::int32_t screen_x, std::int32_t screen_y) const {
    std::int32_t left = 0;
    std::int32_t top = 0;
    getAbsolutePosition(left, top);
    return screen_x >= left && screen_x < detail::addCoordinate(left, width) && screen_y >= top && screen_y < detail::addCoordinate(top, height);
}

std::int32_t SphereUI::Window::childControlAt(std::int32_t screen_x, std::int32_t screen_y) const {
    if (hidden != 0u) return 0;
    if (!containsPoint(screen_x, screen_y)) return -1;
    auto* sentinel = child_sentinel;
    if (sentinel == nullptr) return 0;
    for (auto* node = sentinel->previous; node != nullptr && node != sentinel; node = node->previous) {
        auto* child = node->value;
        if (child != nullptr && child->hidden == 0u && child->containsPoint(screen_x, screen_y)) return static_cast<std::int32_t>(child->control_id);
    }
    return 0;
}

void SphereUI::Window::clearEvents() {
    event_head = 0u;
    event_size = 0u;
    pending_event_count = 0u;
}

void SphereUI::Window::queueEvent(const WindowEvent& event) {
    appendWindowEvent(event_slots, event_capacity, event_head, event_size, pending_event_count, event);
}

bool SphereUI::Window::pollEvent(WindowEvent& event) {
    if (pending_event_count == 0u || event_size == 0u) return false;
    event = *event_slots[event_head];
    --event_size;
    --pending_event_count;
    event_head = event_size == 0u ? 0u : (event_head + 1u) % event_capacity;
    return true;
}

void SphereUI::Window::processEvents() {
    if (!g_sfera_interface.hasEventHandler(this)) return;
    WindowEvent event{};
    while (g_sfera_interface.isRegistered(this) && pollEvent(event)) g_sfera_interface.dispatchEvent(this, event);
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

    void storeValue(std::uint32_t address, std::uint32_t value) {
        if (auto* destination = reinterpret_cast<std::uint32_t*>(address)) *destination = value;
    }
}

const char* SphereUI::Window::getText() const {
    return detail::stringData(text, text_capacity);
}

const char* SphereUI::Window::getHelp() const {
    return detail::stringData(help, help_capacity);
}

void SphereUI::Window::setText(const char* value) {
    detail::assignString(text, text_length, text_capacity, value == nullptr ? "" : value);
}

void SphereUI::Window::setHelp(const char* value) {
    detail::assignString(help, help_length, help_capacity, value == nullptr ? "" : value);
}

const char* SphereUI::Window::getName() const {
    return detail::stringData(name, name_capacity);
}

const char* SphereUI::Window::getResourceName() const {
    return detail::stringData(resource_name, resource_name_capacity);
}

void SphereUI::Window::setName(const char* value) {
    detail::assignString(name, name_length, name_capacity, value == nullptr ? "" : value);
}

void SphereUI::Window::setResourceName(const char* value) {
    detail::assignString(resource_name, resource_name_length, resource_name_capacity, value == nullptr ? "" : value);
}

void SphereUI::ButtonCtrl::click() {
    if (auto* owner = parent) {
        WindowEvent event{this, control_id, UiMessage::leftClick, 0u, 0u, 0u, 0u};
        owner->queueEvent(event);
        if ((button_flags & ButtonStyle::sendClose) != 0u) {
            event.message = UiMessage::close;
            owner->queueEvent(event);
        }
    }
    if ((button_flags & ButtonStyle::showHelp) != 0u) g_sfera_interface.showHelpPage(getHelp());
}

void SphereUI::ImageCtrl::setImage(const ImageDescription* description) {
    if (description == nullptr) {
        resource_reference = nullptr;
        return;
    }
    if (resource_reference != nullptr && SferaSimpleParser::equalsIgnoreCase(resource_reference->name, description->name)) return;
    resource_reference = nullptr;
    if (auto* owner = parent) resource_reference = owner->findResource(description->name);
    if (resource_reference == nullptr) resource_reference = g_sfera_interface.sharedSprite(description->name);
    if (resource_reference != nullptr) return;
    if (fallback_image == nullptr) {
        fallback_image = UiSprite::create();
        if (fallback_image == nullptr) throw std::bad_alloc();
    }
    fallback_image->setDescription(*description);
    resource_reference = fallback_image;
}

SphereUI::Window* SphereUI::Window::createControl(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range, std::uint32_t kind, std::uint32_t id) {
    if (kind == anyControlKind) return nullptr;
    auto* control = Runtime::makeControl(kind);
    if (control == nullptr) return nullptr;
    UiReader reader(parser, range);
    try {
        SferaParserRange tip_range{};
        if (reader.block("tooltip", tip_range)) {
            auto* tip = Runtime::makeControl(UiControlKind::tooltip);
            if (tip != nullptr) {
                tip->setParent(control);
                control->tooltip = tip;
                if (!tip->loadUi(filename, parser, tip_range)) destroyOwned(control->tooltip);
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
            control->font_initialized = 1u;
        }
        reader.flags("textFormat", control->input_mask, textAlignments, true);
        reader.color("textColor", control->text_color);
        if (const char* value = reader.string("windowText")) control->setText(g_sfera_interface.localizedText(value));
        if (const char* value = reader.string("windowHelp", true)) control->setHelp(value);
        if (const char* value = reader.string("setWindowText", true)) control->setText(value);
        reader.boolean("canDragDrop", control->can_drag_drop);
        control->parent = parent == nullptr ? this : parent;
        if (!control->loadUi(filename, parser, range)) {
            control->destroy(true);
            return nullptr;
        }
        control->control_id = id;
        return control;
    } catch (...) {
        control->destroy(true);
        throw;
    }
}

void SphereUI::FontPicker::initialize() {
    Window::initialize();
    selector = nullptr;
    preview = nullptr;
    hidden = 0u;
    control_kind = UiControlKind::fontPicker;
}

void SphereUI::SpinButton::initialize() {
    Window::initialize();
    decrease_button = increase_button = nullptr;
    body = nullptr;
    minimum = current = 0;
    maximum = 100;
    previous = -1;
    step = 1;
    body_index = invalidIndex;
    status_valid = notify_changes = hidden = 0u;
    update_enabled = 1u;
    control_kind = UiControlKind::spinButton;
}

void SphereUI::ScrollBar::initialize() {
    Window::initialize();
    scroll_resource = nullptr;
    decrease_button = increase_button = nullptr;
    orientation_flags = 0u;
    thumb_width = thumb_height = thumb_x = thumb_y = minimum = current = track_left = track_top = track_right = track_bottom = 0;
    normalized_position = 0.0f;
    maximum = 100;
    step = 1;
    page_step = 20;
    dragging_thumb = explicit_step = notify_changes = scroll_reserved = page_click_active = hidden = 0u;
    repeat_alignment = 0;
    repeat_time_low = repeat_time_high = 0u;
    std::fill(std::begin(page_click_reserved), std::end(page_click_reserved), 0u);
    control_kind = UiControlKind::scrollBar;
}

void SphereUI::SliderCtrl::initialize() {
    ScrollBar::initialize();
    control_kind = UiControlKind::slider;
    orientation_flags = 1u;
    std::fill(std::begin(value_text), std::end(value_text), 0);
    display_mode = 0u;
    status_x = status_y = 0;
}

void SphereUI::ScrollBar::setParameters(const ScrollParameters& parameters) {
    if ((parameters.mask & ScrollField::range) != 0u) {
        minimum = parameters.minimum;
        maximum = parameters.maximum;
        enableNavigationButtons(*this);
    }
    if ((parameters.mask & ScrollField::position) != 0u) current = std::min(std::max(parameters.current, minimum), maximum);
    if ((parameters.mask & ScrollField::page) != 0u) page_step = parameters.page_step;
    if ((parameters.mask & ScrollField::step) != 0u && explicit_step == 0u) step = parameters.step;
    updateControlState();
}

void SphereUI::ScrollBar::getParameters(ScrollParameters& parameters) const {
    parameters.minimum = minimum;
    parameters.maximum = maximum;
    parameters.page_step = page_step;
    parameters.current = current;
    parameters.step = step;
}

void SphereUI::ToolTipCtrl::initialize() {
    Window::initialize();
    screen_x = screen_y = line_height = 0;
    hover_pending = dismissed = 0u;
    hover_started = fade_started = 0u;
    fade_opacity = 0.0f;
    background_color = UiColor::tooltipBackground;
    text_color = 0u;
    font = 2u;
    control_kind = UiControlKind::tooltip;
    hidden = 1u;
    tooltip_width = 52;
    tooltip_height = 12;
    margin_left = 3;
    margin_top = 1;
    margin_right = 2;
    margin_bottom = 1;
    lines = {};
}

void SphereUI::MiniHelpCtrl::initialize() {
    ToolTipCtrl::initialize();
    control_kind = UiControlKind::miniHelp;
}

void SphereUI::ToolTipCtrl::reset() {
    fade_opacity = 0.0f;
    hidden = 1u;
    hover_pending = dismissed = 0u;
}

void SphereUI::ToolTipCtrl::showAt(std::int32_t x, std::int32_t y) {
    if (fade_opacity == 0.0f) fade_started = Runtime::clockTicks();
    hidden = 0u;
    screen_x = detail::addCoordinate(x, 10);
    screen_y = detail::addCoordinate(y, 20);
}

void SphereUI::ToolTipCtrl::updateFade() {
    if (hidden != 0u || fade_opacity == 1.0f) return;
    const auto elapsed = static_cast<std::int64_t>(Runtime::clockTicks() - fade_started);
    fade_opacity = std::min(static_cast<float>(static_cast<double>(elapsed) / 10000.0) * 4.0f, 1.0f);
}

void SphereUI::ToolTipCtrl::updateLayout() {
    std::int32_t widest = 0, total = 0;
    line_height = 0;
    for (std::uint32_t index = 0u; index < lines.size(); ++index) {
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
    lines.append(text);
    updateLayout();
}

void SphereUI::ToolTipCtrl::setLine(std::uint32_t index, const char* text) {
    if (index >= lines.size()) {
        appendLine(text);
        return;
    }
    if (text == nullptr) text = "";
    if (std::strcmp(lines.at(index).data(), text) == 0) return;
    lines.at(index).assign(text);
    updateLayout();
}

void SphereUI::ToolTipCtrl::copyTipState(const ToolTipCtrl& source) {
    screen_x = source.screen_x;
    screen_y = source.screen_y;
    hover_pending = source.hover_pending;
    hover_started = source.hover_started;
    fade_opacity = source.fade_opacity;
    fade_started = source.fade_started;
    background_color = source.background_color;
    tooltip_width = source.tooltip_width;
    tooltip_height = source.tooltip_height;
    dismissed = source.dismissed;
    line_height = source.line_height;
    margin_left = source.margin_left;
    margin_top = source.margin_top;
    margin_right = source.margin_right;
    margin_bottom = source.margin_bottom;
    lines.copyFrom(source.lines);
}

void SphereUI::Window::resetToolTips() {
    if (auto* tip = tooltip) static_cast<ToolTipCtrl*>(tip)->reset();
    detail::forEachChild(*this, [](Window& child) {
        child.resetToolTips();
    });
}



void SphereUI::CDescriptionWindow::initialize() {
    auto* original = g_sfera_interface.templateWindow("objdesc2");
    if (original == nullptr) throw std::runtime_error("description template objdesc2 is missing");
    Window::initializeCopy(*original);
    reserved_198 = displayed_id = pending_id = show_deadline = hide_deadline = 0u;
    pinned = 0u;
    const char* names[] = {"window_caption", "window_bottom", "window_left", "window_right"};
    UiSprite** sprites[] = {&caption_sprite, &bottom_sprite, &left_sprite, &right_sprite};
    for (std::uint32_t index = 0u; index < 4u; ++index) {
        *sprites[index] = findResource(names[index]);
        if (*sprites[index] == 0u) throw std::runtime_error(std::string("description sprite is missing: ") + names[index]);
    }
    Window* content = nullptr;
    detail::forEachChild(*this, [&](Window& child) {
        if (content == nullptr) content = &child;
    });
    if (content == nullptr) throw std::runtime_error("description content control is missing");
    height_padding = detail::subtractCoordinate(height, content->height);
    g_sfera_interface.bindEventHandler(this, WindowEventHandler::description);
    close();
    g_sfera_interface.addTopLevelWindow(*this);
}

SphereUI::CDescriptionWindow* SphereUI::CDescriptionWindow::instance() {
    if (auto* existing = Runtime::descriptionWindow()) return existing;
    auto* result = createInitialized<CDescriptionWindow>();
    Runtime::setDescriptionWindow(result);
    return result;
}

void SphereUI::CDescriptionWindow::close() {
    displayed_id = pending_id = 0u;
    hidden = 1u;
    resetToolTips();
    input_enabled = 0u;
}

void SphereUI::CDescriptionWindow::update() {
    if (Runtime::keyDown(42u) || Runtime::keyDown(54u)) return;
    if ((!Runtime::descriptionAutoPopup() && pinned == 0u) || (hidden == 0u && Runtime::milliseconds() >= hide_deadline)) close();
}

void SphereUI::CDescriptionWindow::handleEvent(const WindowEvent& event) {
    if (event.message == UiMessage::close || (event.message == UiMessage::leftClick && event.control_id == 2u)) close();
}

SferaCursorPosition* SphereUI::CDescriptionWindow::calculatePosition(SferaCursorPosition* output) const {
    if (output == nullptr) return nullptr;
    const auto cursor = CCursorManager::instance().geometry();
    const auto screen = Runtime::screenSize();
    const auto axis = [](std::int32_t position, std::int32_t extent, std::int32_t limit, std::int32_t size, bool centered) {
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

void SphereUI::CDescriptionWindow::showDescription(const char* text, std::uint32_t id, std::uint32_t duration, bool pin) {
    if (text == nullptr) text = "";
    Window* content = nullptr;
    detail::forEachChild(*this, [&](Window& child) {
        if (content == nullptr) content = &child;
    });
    if (content == nullptr) throw std::runtime_error("description content control is missing");
    content->handleMessage(UiMessage::loadHyperTextBuffer, reinterpret_cast<std::uintptr_t>(text), static_cast<std::uint32_t>(std::strlen(text)));
    content->handleMessage(UiMessage::resizeToHyperText, 0u, 0u);
    height = detail::addCoordinate(height_padding, content->height);
    SferaCursorPosition position{};
    calculatePosition(&position);
    setPosition(position.x, position.y);
    displayed_id = pending_id = id;
    hide_deadline = Runtime::milliseconds() + duration;
    pinned = pin ? 1u : 0u;
    hidden = 0u;
    input_enabled = 1u;
}

void SphereUI::CDescriptionWindow::requestDescription(const char* text, bool force, std::uint32_t id) {
    if (text == nullptr || text[0] == '\0') return;
    if (force) {
        showDescription(text, id, 250u, false);
        return;
    }
    if (!Runtime::descriptionAutoPopup() || Runtime::keyDown(42u) || Runtime::keyDown(54u)) return;
    if (pending_id != id) {
        pending_id = id;
        show_deadline = Runtime::milliseconds() + 500u;
    }
    if (displayed_id == pending_id) hide_deadline = Runtime::milliseconds() + 250u;
    else if (Runtime::milliseconds() >= show_deadline) showDescription(text, pending_id, 250u, false);
}

void SphereUI::ListItemCtrl::initialize() {
    Window::initialize();
    item_template = nullptr;
    items = {};
    horizontal_offset = vertical_offset = visible_begin = visible_end = visible_capacity = cropped_x = cropped_y = maximum_y = maximum_x = 0;
    vertical_scroll = horizontal_scroll = nullptr;
    layout_dirty = can_select = horizontal = user_move = 0u;
    selection_sprite = nullptr;
    selected_index = -1;
    hidden = 0u;
    control_kind = UiControlKind::listItem;
}

SphereUI::Window* SphereUI::ListItemCtrl::itemAt(std::uint32_t index) const {
    return index < items.size() ? items.at(index) : nullptr;
}

std::int32_t SphereUI::ListItemCtrl::addItem() {
    auto* original = item_template;
    if (original == nullptr) return -1;
    auto* item = original->clone();
    if (item == nullptr) return -1;
    item->hidden = 0u;
    try {
        items.append(item);
    } catch (...) {
        item->destroy(true);
        throw;
    }
    return static_cast<std::int32_t>(items.size() - 1u);
}

void SphereUI::ListItemCtrl::clearItems() {
    const auto count = items.size();
    for (std::uint32_t index = 0u; index < count; ++index) destroyOwned(items.at(index));
    items.clear();
}

void SphereUI::ListItemCtrl::removeItem(std::uint32_t index) {
    if (index >= items.size()) return;
    destroyOwned(items.at(index));
    items.erase(index);
    bool changed = index == static_cast<std::uint32_t>(selected_index);
    if (changed) selected_index = -1;
    if (static_cast<std::uint32_t>(selected_index) >= items.size()) {
        selected_index = static_cast<std::int32_t>(items.size() - 1u);
        changed = true;
    }
    if (changed && can_select != 0u) notifyParent(*this, UiMessage::listItemSelectionChanged, static_cast<std::uint32_t>(selected_index));
}

void SphereUI::ListItemCtrl::updateVisibleRange() {
    const auto* original = item_template;
    if (original == nullptr) return;
    horizontal_offset = std::clamp(horizontal_offset, 0, std::max(maximum_x, 0));
    vertical_offset = std::clamp(vertical_offset, 0, std::max(maximum_y, 0));
    const auto extent = horizontal == 0u ? original->height : original->width;
    const auto offset = horizontal == 0u ? vertical_offset : horizontal_offset;
    const auto fraction = extent > 0 ? static_cast<float>(offset) / static_cast<float>(extent) : 0.0f;
    const auto integral = std::floor(fraction);
    const auto cropped = extent > 0 ? static_cast<std::int32_t>((fraction - integral) * static_cast<float>(extent)) : 0;
    visible_begin = static_cast<std::int32_t>(integral);
    visible_end = std::min(detail::addCoordinate(detail::addCoordinate(visible_begin, visible_capacity), 1), static_cast<std::int32_t>(items.size()));
    cropped_x = horizontal == 0u ? horizontal_offset : cropped;
    cropped_y = horizontal == 0u ? cropped : vertical_offset;
    if (user_move != 0u) {
        cropped_x = cropped_y = visible_begin = 0;
        visible_end = static_cast<std::int32_t>(items.size());
    }
    layout_dirty = 1u;
}

void SphereUI::ListItemCtrl::updateLayout() {
    const auto* original = item_template;
    if (original == nullptr) return;
    const auto extent = horizontal == 0u ? original->height : original->width;
    const auto available = horizontal == 0u ? height : width;
    visible_capacity = extent > 0 ? available / extent + 1 : 0;
    const auto total_width = horizontal != 0u ? static_cast<std::int32_t>(items.size() * static_cast<std::uint32_t>(original->width)) : original->width;
    const auto total_height = horizontal == 0u ? static_cast<std::int32_t>(items.size() * static_cast<std::uint32_t>(original->height)) : original->height;
    maximum_x = std::max(0, detail::subtractCoordinate(total_width, width));
    maximum_y = std::max(0, detail::subtractCoordinate(total_height, height));
    horizontal_offset = std::clamp(horizontal_offset, 0, maximum_x);
    vertical_offset = std::clamp(vertical_offset, 0, maximum_y);
    if (auto* bar = vertical_scroll) bar->setParameters({0u, ScrollField::all, 0, maximum_y, height, vertical_offset, static_cast<std::int32_t>(static_cast<std::uint32_t>(original->height) / 10u + 1u)});
    if (auto* bar = horizontal_scroll) bar->setParameters({0u, ScrollField::all, 0, maximum_x, width, horizontal_offset, static_cast<std::int32_t>(static_cast<std::uint32_t>(maximum_x) / 10u + 1u)});
    updateVisibleRange();
}

void SphereUI::ListItemCtrl::copyItemState(const ListItemCtrl& source) {
    if (this == &source) return;
    clearItems();
    horizontal_offset = source.horizontal_offset;
    vertical_offset = source.vertical_offset;
    visible_begin = source.visible_begin;
    visible_end = source.visible_end;
    visible_capacity = source.visible_capacity;
    cropped_x = source.cropped_x;
    cropped_y = source.cropped_y;
    maximum_x = source.maximum_x;
    maximum_y = source.maximum_y;
    layout_dirty = source.layout_dirty;
    can_select = source.can_select;
    selection_sprite = source.selection_sprite;
    selected_index = source.selected_index;
    horizontal = source.horizontal;
    user_move = source.user_move;
    cloneOwned(item_template, source.item_template, *this);
    if (auto* copy = item_template) copy->setParent(nullptr);
    for (std::uint32_t index = 0u; index < source.items.size(); ++index) if (addItem() < 0) throw std::bad_alloc();
    cloneOwned(vertical_scroll, source.vertical_scroll, *this);
    cloneOwned(horizontal_scroll, source.horizontal_scroll, *this);
}

void SphereUI::Window::drawToolTips() {
    detail::forEachChild(*this, [](Window& child) {
        if (child.hidden == 0u) if (auto* tip = child.tooltip) tip->draw();
    });
    if (auto* control = overlay) if (control->hidden == 0u) control->draw();
}

void SphereUI::ListCtrl::initialize() {
    Window::initialize();
    visible_begin = visible_end = 0;
    rows = {};
    maximum_items = write_index = 0u;
    maximum_scroll = visible_capacity = vertical_offset = cropped_y = 0;
    line_height = 1;
    chatlike = format_strings = continue_mark = can_select = click_pending = 0u;
    scrollbar = nullptr;
    selected_index = -1;
    selection_border = 3;
    selection_color = UiColor::listSelection;
    selection_line_color = 0u;
    click_time = 0u;
    hidden = 0u;
    control_kind = UiControlKind::textList;
}

void SphereUI::ListCtrl::copyListState(const ListCtrl& source) {
    if (this == &source) return;
    visible_begin = source.visible_begin;
    visible_end = source.visible_end;
    rows.copyFrom(source.rows);
    maximum_items = source.maximum_items;
    write_index = source.write_index;
    maximum_scroll = source.maximum_scroll;
    line_height = source.line_height;
    visible_capacity = source.visible_capacity;
    vertical_offset = source.vertical_offset;
    cropped_y = source.cropped_y;
    chatlike = source.chatlike;
    format_strings = source.format_strings;
    continue_mark = source.continue_mark;
    can_select = source.can_select;
    selected_index = source.selected_index;
    selection_border = source.selection_border;
    selection_color = source.selection_color;
    selection_line_color = source.selection_line_color;
    click_time = source.click_time;
    click_pending = source.click_pending;
    cloneOwned(scrollbar, source.scrollbar, *this);
}

std::uint32_t SphereUI::ListCtrl::physicalIndex(std::uint32_t logical_index) const {
    const auto count = rows.size();
    if (logical_index >= count) throw std::out_of_range("UI logical row index");
    return maximum_items == 0u ? logical_index : static_cast<std::uint32_t>((static_cast<std::uint64_t>(write_index) + logical_index) % count);
}

void SphereUI::ListCtrl::updateVisibleRange() {
    vertical_offset = std::clamp(vertical_offset, 0, std::max(maximum_scroll, 0));
    const auto fraction = line_height > 0 ? static_cast<float>(vertical_offset) / static_cast<float>(line_height) : 0.0f;
    const auto integral = std::floor(fraction);
    cropped_y = line_height > 0 ? static_cast<std::int32_t>((fraction - integral) * static_cast<float>(line_height)) : 0;
    visible_begin = static_cast<std::int32_t>(integral);
    visible_end = std::min(detail::addCoordinate(detail::addCoordinate(visible_begin, visible_capacity), 1), static_cast<std::int32_t>(rows.size()));
}

void SphereUI::ListCtrl::updateLayout() {
    visible_capacity = line_height > 0 ? height / line_height + 1 : 0;
    const auto extent = static_cast<std::int32_t>(rows.size() * static_cast<std::uint32_t>(line_height));
    maximum_scroll = height > extent ? 0 : std::max(0, detail::addCoordinate(detail::subtractCoordinate(extent, height), 1));
    if (auto* bar = scrollbar) bar->setParameters({0u, ScrollField::all, 0, maximum_scroll, height, vertical_offset, line_height});
    updateVisibleRange();
}

void SphereUI::ListCtrl::appendLine(const char* text, std::uint32_t color) {
    if (parent != nullptr && selected_index != -1) {
        selected_index = -1;
        notifyParent(*this, UiMessage::listSelectionChanged, invalidIndex);
    }
    std::int32_t offset = 0;
    if (input_mask != 0u && text != nullptr) {
        const auto extent = InterfaceRenderer::measureText(text, font, font_initialized != 0u);
        const auto remainder = detail::subtractCoordinate(width, extent.width);
        if ((input_mask & TextAlignment::right) != 0u) offset = remainder;
        if ((input_mask & TextAlignment::horizontalCenter) != 0u) offset = static_cast<std::int32_t>(std::abs(static_cast<std::int64_t>(remainder)) / 2);
    }
    appendCircular(rows, maximum_items, write_index, text, color, offset);
    updateLayout();
}

void SphereUI::ListCtrl::appendFormattedLine(const char* text, std::uint32_t color) {
    wrapTextLine(*this, text, format_strings != 0u, [&](const char* line) {
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

void SphereUI::ListCtrl::removeRow(std::uint32_t logical_index) {
    if (logical_index >= rows.size()) return;
    rows.erase(physicalIndex(logical_index));
    if (maximum_items != 0u) write_index = write_index == 0u ? 0u : write_index - 1u;
    if (parent != nullptr && selected_index != -1) {
        selected_index = -1;
        notifyParent(*this, UiMessage::listSelectionChanged, invalidIndex);
    }
    updateLayout();
}

void SphereUI::ListCtrl::selectRow(std::int32_t index) {
    if (index >= 0 && static_cast<std::uint32_t>(index) < rows.size()) selected_index = index;
}

void SphereUI::ListCtrl::alignRow(std::uint32_t index, std::uint32_t flags) {
    if (index >= rows.size()) return;
    auto& row = rows.at(index);
    if (flags == 0u) row.offset = 0;
    else {
        const auto extent = InterfaceRenderer::measureText(row.text.data(), font, font_initialized != 0u);
        const auto remainder = detail::subtractCoordinate(width, extent.width);
        if ((flags & 4u) != 0u) row.offset = static_cast<std::int32_t>(static_cast<std::uint32_t>(remainder) / 2u);
        if ((flags & 1u) != 0u) row.offset = remainder;
    }
}

void SphereUI::ListCtrl::drawSelection(std::int32_t screen_x, std::int32_t screen_y, std::int32_t row_y, bool restore_viewport) {
    const UiRect bounds{detail::subtractCoordinate(screen_x, selection_border), screen_y, detail::addCoordinate(detail::addCoordinate(screen_x, width), selection_border), detail::addCoordinate(screen_y, height)};
    ViewportScope viewport(bounds, restore_viewport);
    if (!viewport) return;
    const auto screen = Runtime::screenSize();
    const auto left = static_cast<float>(std::max(bounds.left, 0)), right = static_cast<float>(std::min(bounds.right, screen.width)), top = static_cast<float>(row_y), bottom = static_cast<float>(detail::addCoordinate(row_y, line_height));
    const auto fill = modulatedColor(selection_color, alpha), line = modulatedColor(selection_line_color, alpha);
    InterfaceRenderer::drawTexture(nullptr, left, top, right, bottom, fill, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, left, top, right, top + 1.0f, line, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, left, bottom, right, bottom + 1.0f, line, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, left, top, left + 1.0f, bottom, line, 0.0f, 0.0f, false);
    InterfaceRenderer::drawTexture(nullptr, right - 1.0f, top, right, bottom, line, 0.0f, 0.0f, false);
}

void SphereUI::FilterListCtrl::initialize() {
    ListCtrl::initialize();
    filter_mask = 255u;
    history = {};
    history_write = 0u;
    control_kind = UiControlKind::filteredList;
}

void SphereUI::FilterListCtrl::clearHistory() {
    history.clear();
    history_write = 0u;
}

void SphereUI::FilterListCtrl::appendHistory(const char* text, std::uint32_t color, std::uint32_t mask) {
    appendCircular(history, maximum_items, history_write, text, mask, static_cast<std::int32_t>(color));
}

void SphereUI::FilterListCtrl::applyFilter(std::uint32_t mask) {
    if (mask == filter_mask) return;
    filter_mask = mask;
    if (history.size() == 0u) return;
    clearRows();
    for (std::uint32_t index = 0u; index < history.size(); ++index) {
        const auto& row = history.at(index);
        if ((row.color & mask) != 0u) addText(row.text.data(), static_cast<std::uint32_t>(row.offset));
    }
}

namespace {
    void menuLabel(const SphereUI::Window& window, const char* text, const SphereUI::UiRect& margins, const SphereUI::TextExtent& size, std::uint32_t format, std::uint32_t color, std::int32_t left, std::int32_t top, const SphereUI::UiRect& clip) {
        const auto extent = SphereUI::InterfaceRenderer::measureText(text, window.font, true);
        const auto room_x = size.width - margins.left - margins.right - extent.width, room_y = size.height - margins.top - margins.bottom - extent.height;
        const auto dx = (format & 4u) != 0u ? room_x / 2 : (format & 1u) != 0u ? room_x : 0;
        const auto dy = (format & 8u) != 0u ? room_y / 2 : (format & 2u) != 0u ? room_y : 0;
        renderLabel(window, text, left + margins.left + dx, top + margins.top + dy, (color & kRgbColorMask) | (window.alpha << 24u), clip);
    }
}

void SphereUI::CMenuListControl::initialize() {
    Window::initialize();
    maximum_items = {};
    top_sprite = {};
    middle_sprite = {};
    hovered_sprite = {};
    bottom_sprite = {};
    title_color = {};
    normal_color = {};
    hovered_color = {};
    item_disabled_color = {};
    show_title = {};
    std::fill(std::begin(menu_reserved), std::end(menu_reserved), 0u);
    title_margin = {};
    title_format = {};
    item_margin = {};
    item_format = {};
    top_size = {};
    item_size = {};
    bottom_size = {};
    parent_screen_x = {};
    parent_screen_y = {};
    parent_width = {};
    parent_height = {};
    items = {};
    hovered_index = {};
    saved_viewport = {};
    maximum_items = hovered_index = 1u;
    control_kind = UiControlKind::menu;
}

void SphereUI::CMenuListControl::copyMenuState(const CMenuListControl& source) {
    if (this == &source) return;
    items.copyFrom(source.items);
    maximum_items = source.maximum_items;
    top_sprite = source.top_sprite;
    middle_sprite = source.middle_sprite;
    hovered_sprite = source.hovered_sprite;
    bottom_sprite = source.bottom_sprite;
    title_color = source.title_color;
    normal_color = source.normal_color;
    hovered_color = source.hovered_color;
    item_disabled_color = source.item_disabled_color;
    show_title = source.show_title;
    title_margin = source.title_margin;
    title_format = source.title_format;
    item_margin = source.item_margin;
    item_format = source.item_format;
    top_size = source.top_size;
    item_size = source.item_size;
    bottom_size = source.bottom_size;
    parent_screen_x = source.parent_screen_x;
    parent_screen_y = source.parent_screen_y;
    parent_width = source.parent_width;
    parent_height = source.parent_height;
    hovered_index = source.hovered_index;
    saved_viewport = source.saved_viewport;
}

bool SphereUI::CMenuListControl::loadUi(const char*, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    reader.sprite("topSprite", *this, top_sprite);
    reader.sprite("middleSprite", *this, middle_sprite);
    reader.sprite("bottomSprite", *this, bottom_sprite);
    if (top_sprite == nullptr || middle_sprite == nullptr || bottom_sprite == nullptr) return false;
    const auto dimensions = [](const UiSprite* sprite) {
        return TextExtent{static_cast<std::int32_t>(sprite->width), static_cast<std::int32_t>(sprite->height)};
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
    reader.integer("maxItems", maximum_items);
    hovered_index = maximum_items;
    height = top_size.height + bottom_size.height;
    font = std::max(font, std::uint8_t{2u});
    return true;
}

SphereUI::Window* SphereUI::CMenuListControl::clone() {
    return cloneControl(*this, [](auto& destination, const auto& source) {
        destination.copyMenuState(source);
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
    UiMenuItem value{};
    value.text.capacity = 15u;
    value.text.assign(text);
    value.enabled = enabled;
    try {
        items.append(value);
    } catch (...) {
        value.text.release();
        throw;
    }
    value.text.release();
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

std::uint32_t SphereUI::CMenuListControl::itemAtPoint(std::int32_t point_x, std::int32_t point_y) const {
    if (item_size.height <= 0) return maximum_items;
    const auto bounds = windowBounds(*this);
    const auto row_y = static_cast<std::int64_t>(point_y) - bounds.top - top_size.height;
    if (point_x < bounds.left || point_x >= bounds.right || row_y < 0) return maximum_items;
    const auto index = static_cast<std::uint64_t>(row_y / item_size.height);
    return index < items.size() ? static_cast<std::uint32_t>(index) : maximum_items;
}

std::uint32_t SphereUI::CMenuListControl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
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
            if (first < items.size()) items.at(first).text.assign(reinterpret_cast<const char*>(second));
            break;
        default:
            return Window::handleMessage(message, first, second);
    }
    return 1u;
}

void SphereUI::CMenuListControl::drawHeader() {
    const auto bounds = windowBounds(*this);
    if (top_sprite != nullptr) top_sprite->drawNatural(static_cast<float>(bounds.left), static_cast<float>(bounds.top), UiColor::whiteRgb | (alpha << 24u));
    if (show_title != 0u) {
        const UiRect clip{bounds.left + title_margin.left, bounds.top + title_margin.top, bounds.right - title_margin.right, bounds.bottom - title_margin.bottom};
        menuLabel(*this, getText(), title_margin, top_size, title_format, title_color, bounds.left, bounds.top, clip);
    }
}

void SphereUI::CMenuListControl::drawItem(std::uint32_t index, UiSprite* sprite, std::uint32_t color) {
    if (index >= items.size()) return;
    const auto bounds = windowBounds(*this);
    const auto row_top = bounds.top + top_size.height + static_cast<std::int32_t>(index) * item_size.height;
    if (sprite != nullptr) sprite->drawNatural(static_cast<float>(bounds.left), static_cast<float>(row_top), UiColor::whiteRgb | (alpha << 24u));
    const auto& item = items.at(index);
    const UiRect clip{bounds.left + item_margin.left, row_top + title_margin.top, bounds.right - item_margin.right, row_top + item_size.height - title_margin.bottom};
    menuLabel(*this, item.text.data(), item_margin, item_size, item_format, item.enabled != 0u ? color : item_disabled_color, bounds.left, row_top, clip);
}

void SphereUI::CMenuListControl::drawFooter() {
    const auto bounds = windowBounds(*this);
    if (bottom_sprite != nullptr) bottom_sprite->drawNatural(static_cast<float>(bounds.left), static_cast<float>(bounds.top + top_size.height + static_cast<std::int32_t>(items.size()) * item_size.height), UiColor::whiteRgb | (alpha << 24u));
}

void SphereUI::CMenuListControl::draw() {
    if (hidden != 0u || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    keepOnScreen();
    saved_viewport = InterfaceRenderer::viewport();
    ViewportScope viewport(windowBounds(*this));
    if (!viewport) return;
    drawHeader();
    for (std::uint32_t index = 0u; index < items.size(); ++index) drawItem(index, index == hovered_index ? hovered_sprite : middle_sprite, index == hovered_index ? hovered_color : normal_color);
    drawFooter();
}

void SphereUI::CMenuListControl::handleInput(const WindowInput& input) {
    if (hidden != 0u || items.size() == 0u) return;
    const auto position = CCursorManager::instance().position();
    hovered_index = itemAtPoint(position.x, position.y);
    if (hovered_index < items.size() && items.at(hovered_index).enabled != 0u && (input.mouse_flags & MouseInput::leftPress) != 0u) {
        notifyParent(*this, UiMessage::menuItemActivated, hovered_index, items.size());
        closeMenu();
    }
    if (const auto* owner = parent; owner != nullptr && !owner->containsPoint(position.x, position.y) && (input.mouse_flags & 3u) != 0u) closeMenu();
}

void SphereUI::CMenuListControl::destroy(bool free_storage) {
    items.release();
    Window::destroy(free_storage);
}

void SphereUI::CWebBrowserControl::initialize() {
    Window::initialize();
    url = {};
    url.capacity = 15u;
    surface = nullptr;
    browser = nullptr;
    mouse_pressed = 0u;
    std::fill(std::begin(browser_reserved), std::end(browser_reserved), 0u);
    hidden = 0u;
    control_kind = UiControlKind::webBrowser;
}

void SphereUI::CWebBrowserControl::copyBrowserState(const CWebBrowserControl& source) {
    if (this == &source) return;
    BrowserSurface* new_surface = nullptr;
    BrowserSession* new_browser = nullptr;
    try {
        if (const auto* image = source.surface) {
            new_surface = Runtime::createBrowserSurface(image->width, image->height);
            if (new_surface == nullptr) throw std::bad_alloc();
        }
        if (const auto* session = source.browser) {
            new_browser = Runtime::createBrowserSession(session->url.data(), session->width, session->height);
            if (new_browser == nullptr) throw std::bad_alloc();
        }
        url.assign(source.url.data());
    } catch (...) {
        Runtime::destroyBrowserSurface(new_surface);
        Runtime::destroyBrowserSession(new_browser);
        throw;
    }
    Runtime::destroyBrowserSurface(surface);
    Runtime::destroyBrowserSession(browser);
    surface = new_surface;
    browser = new_browser;
    mouse_pressed = 0u;
}

bool SphereUI::CWebBrowserControl::loadUi(const char*, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    if (const auto* value = reader.string("URL", true)) url.assign(value);
    return true;
}

SphereUI::Window* SphereUI::CWebBrowserControl::clone() {
    return cloneControl(*this, [](auto& destination, const auto& source) {
        destination.copyBrowserState(source);
    });
}

bool SphereUI::CWebBrowserControl::open(const char* address) {
    if (width <= 0 || height <= 0) return true;
    if (address != nullptr) url.assign(address);
    if (surface == nullptr) surface = Runtime::createBrowserSurface(width, height);
    if (browser == nullptr) browser = Runtime::createBrowserSession(url.data(), width, height);
    return true;
}

bool SphereUI::CWebBrowserControl::navigate(const char* address) {
    if (auto* session = browser; session != nullptr && address != nullptr) {
        url.assign(address);
        Runtime::browserNavigate(*session, url.data());
    }
    return true;
}

bool SphereUI::CWebBrowserControl::updateBrowser() {
    auto* image = surface;
    auto* session = browser;
    if (image == nullptr || session == nullptr) return true;
    const auto position = CCursorManager::instance().position();
    if (containsPoint(position.x, position.y)) {
        const auto bounds = windowBounds(*this);
        Runtime::browserMouse(*session, WM_MOUSEMOVE, position.x - bounds.left, position.y - bounds.top);
    }
    Runtime::browserPaint(*session, *image);
    return true;
}

std::uint32_t SphereUI::CWebBrowserControl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::openBrowser:
            return open(reinterpret_cast<const char*>(first));
        case UiMessage::updateBrowser:
            return updateBrowser();
        case UiMessage::navigateBrowser:
            return navigate(reinterpret_cast<const char*>(first));
        case UiMessage::refreshBrowser:
            if (auto* session = browser) Runtime::browserRefresh(*session);
            return 1u;
        case UiMessage::getBrowserLocation:
            if (auto* session = browser) Runtime::browserLocation(*session, reinterpret_cast<char*>(first), second);
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

void SphereUI::CWebBrowserControl::draw() {
    if (hidden != 0u) return;
    const auto* image = surface;
    if (image == nullptr || image->texture_size <= 0 || image->texture_resource == 0u) return;
    const auto bounds = windowBounds(*this);
    const auto* resource = image->texture_resource;
    InterfaceRenderer::drawTexture(resource->native_texture, static_cast<float>(bounds.left), static_cast<float>(bounds.top), static_cast<float>(bounds.left + image->width), static_cast<float>(bounds.top + image->height), UiColor::whiteRgb | (alpha << 24u), static_cast<float>(image->width) / image->texture_size, static_cast<float>(image->height) / image->texture_size);
}

void SphereUI::CWebBrowserControl::handleInput(const WindowInput& input) {
    auto* session = browser;
    if (session == nullptr) return;
    if (!containsPoint(input.mouse_x, input.mouse_y)) {
        if ((input.mouse_flags & MouseInput::leftPress) != 0u) {
            input_enabled = 0u;
            Runtime::focusMainWindow();
        }
        return;
    }
    const auto bounds = windowBounds(*this);
    const auto local_x = input.mouse_x - bounds.left, local_y = input.mouse_y - bounds.top;
    if ((input.mouse_flags & MouseInput::leftPress) != 0u && mouse_pressed == 0u) {
        mouse_pressed = input_enabled = 1u;
        Runtime::browserMouse(*session, WM_LBUTTONDOWN, local_x, local_y);
    } else if ((input.mouse_flags & MouseInput::leftRelease) != 0u && mouse_pressed != 0u) {
        mouse_pressed = 0u;
        Runtime::browserMouse(*session, WM_LBUTTONUP, local_x, local_y);
    }
    if (input.wheel_delta != 0) Runtime::browserMouse(*session, WM_MOUSEWHEEL, local_x, local_y, input.wheel_delta);
}

void SphereUI::CWebBrowserControl::destroy(bool free_storage) {
    Runtime::destroyBrowserSurface(surface);
    Runtime::destroyBrowserSession(browser);
    surface = nullptr;
    browser = nullptr;
    mouse_pressed = 0u;
    url.release();
    Window::destroy(free_storage);
}

void SphereUI::SlotCtrl::initialize() {
    Window::initialize();
    full_sprite = {};
    empty_sprite = {};
    border_sprite = {};
    fill_alpha = {};
    fill_color = {};
    border_color = {};
    image_offset_x = {};
    image_offset_y = {};
    item_image = {};
    show_full_background = {};
    has_item = {};
    slot_reserved = {};
    press_x = {};
    press_y = {};
    left_pressed = {};
    right_pressed = {};
    drag_started = {};
    slot_state_reserved = {};
    description = {};
    count_offset_x = {};
    count_offset_y = {};
    item_count = {};
    top_left_overlay = {};
    bottom_right_overlay = {};
    bottom_left_overlay = {};
    item_image.initialize();
    description.capacity = 15u;
    fill_alpha = 128u;
    fill_color = UiColor::slotFill;
    border_color = UiColor::slotBorder;
    count_offset_x = -2;
    count_offset_y = 2;
    font = 2u;
    hidden = 0u;
    control_kind = UiControlKind::slot;
    can_drag_drop = 1u;
    input_mask = TextAlignment::right;
    text_color = UiColor::white;
}

void SphereUI::SlotCtrl::copySlotState(const SlotCtrl& source) {
    if (this == &source) return;
    item_image.copyFrom(source.item_image);
    description.assign(source.description.data());
    const auto replace_overlay = [](UiSprite*& target, const UiSprite* original) {
        const auto copy = (original == nullptr ? nullptr : original->clone());
        if (target != nullptr) target->destroy();
        target = copy;
    };
    replace_overlay(top_left_overlay, source.top_left_overlay);
    replace_overlay(bottom_right_overlay, source.bottom_right_overlay);
    replace_overlay(bottom_left_overlay, source.bottom_left_overlay);
    full_sprite = source.full_sprite;
    empty_sprite = source.empty_sprite;
    border_sprite = source.border_sprite;
    fill_alpha = source.fill_alpha;
    fill_color = source.fill_color;
    border_color = source.border_color;
    image_offset_x = source.image_offset_x;
    image_offset_y = source.image_offset_y;
    show_full_background = source.show_full_background;
    has_item = source.has_item;
    slot_reserved = source.slot_reserved;
    press_x = source.press_x;
    press_y = source.press_y;
    left_pressed = source.left_pressed;
    right_pressed = source.right_pressed;
    drag_started = source.drag_started;
    slot_state_reserved = source.slot_state_reserved;
    count_offset_x = source.count_offset_x;
    count_offset_y = source.count_offset_y;
    item_count = source.item_count;
}

void SphereUI::SlotCtrl::setOverlay(UiSprite*& destination, const char* image) {
    if (image == nullptr) {
        if (destination != nullptr) destination->destroy();
        destination = 0u;
        return;
    }
    if (destination == 0u) {
        destination = UiSprite::create();
        if (destination == 0u) throw std::bad_alloc();
    }
    destination->setImage(image);
}

void SphereUI::SlotCtrl::setItem(const char* image) {
    if (image == nullptr) {
        show_full_background = 1u;
        has_item = 0u;
        setText("");
        description.assign("");
        item_count = 0u;
        setOverlay(top_left_overlay, nullptr);
        setOverlay(bottom_right_overlay, nullptr);
        setOverlay(bottom_left_overlay, nullptr);
        return;
    }
    if (item_image.name == 0u || std::strcmp(item_image.name, image) != 0) item_image.setImage(image);
    show_full_background = 0u;
    has_item = 1u;
}

void SphereUI::SlotCtrl::setItemCount(std::uint32_t count) {
    if (count == item_count) return;
    setText(count == 0u ? "" : std::to_string(static_cast<std::int32_t>(count)).c_str());
    item_count = count;
}

bool SphereUI::SlotCtrl::loadUi(const char*, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    if (parent == nullptr) return false;
    const bool background = reader.has("slotpic") || reader.has("slotFull");
    if (background) {
        reader.sprite(reader.has("slotpic") ? "slotpic" : "slotFull", *this, full_sprite);
        show_full_background = 1u;
        if (full_sprite == nullptr) return false;
    }
    reader.sprite("slotempty", *this, empty_sprite);
    reader.sprite("slotborder", *this, border_sprite);
    reader.pair("slotpicofs", image_offset_x, image_offset_y);
    reader.pair("textofs", count_offset_x, count_offset_y);
    std::int32_t number = 0;
    reader.integer("slotnumber", number);
    if (number != 0) setText(std::to_string(number).c_str());
    if (const char* image = reader.string("slotItem", true)) setItem(image);
    return true;
}

SphereUI::Window* SphereUI::SlotCtrl::clone() {
    return cloneControl(*this, [](auto& destination, const auto& source) {
        destination.copySlotState(source);
    });
}

std::uint32_t SphereUI::SlotCtrl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
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
            description.assign(reinterpret_cast<const char*>(first));
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
    if (hidden != 0u || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    const auto left = static_cast<float>(bounds.left), top = static_cast<float>(bounds.top);
    const auto white = UiColor::whiteRgb | (alpha << 24u);
    const auto background_color = (fill_color & kRgbColorMask) | (((fill_alpha * alpha) & alphaProductHighByteMask) << 16u);
    if (auto* background = show_full_background != 0u && full_sprite != nullptr ? full_sprite : empty_sprite) background->drawNatural(left + image_offset_x, top + image_offset_y, background_color);
    if (has_item != 0u) {
        const auto image_width = std::min(static_cast<std::uint32_t>(std::max(0, width)), item_image.width), image_height = std::min(static_cast<std::uint32_t>(std::max(0, height)), item_image.height);
        const auto image_left = left + (width - static_cast<std::int32_t>(image_width)) / 2, image_top = top + (height - static_cast<std::int32_t>(image_height)) / 2;
        item_image.draw(image_left, image_top, image_left + image_width, image_top + image_height, white);
    }
    if (top_left_overlay != nullptr) top_left_overlay->drawNatural(left + 1.0f, top, white);
    if (auto* sprite = bottom_right_overlay) sprite->drawNatural(left + width - sprite->width - 1.0f, top + height - sprite->height - 1.0f, white);
    if (auto* sprite = bottom_left_overlay) {
        const auto dx = image_offset_x == -2 ? 1.0f : 3.0f, dy = image_offset_x == -2 ? 0.0f : image_offset_x == -1 ? 1.0f : 2.0f;
        sprite->drawNatural(left + dx, top + height - sprite->height - dy - 1.0f, white);
    }
    if (text_length != 0u && (has_item != 0u || (behavior_flags & WindowStyle::showTitle) != 0u)) {
        const auto extent = InterfaceRenderer::measureText(getText(), font, font_initialized != 0u);
        auto dx = count_offset_x, dy = count_offset_y;
        if (extent.width < width) {
            if ((input_mask & TextAlignment::right) != 0u) dx += width - extent.width;
            if ((input_mask & TextAlignment::horizontalCenter) != 0u) dx = count_offset_x + (width - extent.width) / 2;
        }
        if (extent.height < height) {
            if ((input_mask & TextAlignment::bottom) != 0u) dy += height - extent.height;
            if ((input_mask & TextAlignment::verticalCenter) != 0u) dy = count_offset_y + (height - extent.height) / 2;
        }
        for (const auto offset : {TextExtent{1, 1}, TextExtent{-1, -1}, TextExtent{-1, 1}, TextExtent{1, -1}}) renderLabel(*this, getText(), bounds.left + dx + offset.width, bounds.top + dy + offset.height, alpha << 24u, bounds);
        renderLabel(*this, getText(), bounds.left + dx, bounds.top + dy, ((disabled != 0u ? disabled_color : text_color) & kRgbColorMask) | (alpha << 24u), bounds);
    }
    if (border_sprite != nullptr) border_sprite->drawNatural(left + image_offset_x, top + image_offset_y, (border_color & kRgbColorMask) | (alpha << 24u));
}

void SphereUI::SlotCtrl::handleInput(const WindowInput& input) {
    if (hidden != 0u) return;
    const bool shift = Runtime::keyDown(42u) || Runtime::keyDown(54u);
    if (containsPoint(input.mouse_x, input.mouse_y)) {
        if ((input.mouse_flags & MouseInput::leftPress) != 0u && left_pressed == 0u && drag_started == 0u && !shift) {
            left_pressed = 1u;
            press_x = input.mouse_x;
            press_y = input.mouse_y;
        }
        if ((input.mouse_flags & MouseInput::rightPress) != 0u) right_pressed = 1u;
        if (!g_sfera_interface.drag_drop_active) {
            if ((input.mouse_flags & MouseInput::leftRelease) != 0u && !shift && left_pressed != 0u) notifyParent(*this, UiMessage::leftClick);
            if ((input.mouse_flags & MouseInput::rightRelease) != 0u && !shift && right_pressed != 0u) notifyParent(*this, UiMessage::rightClick);
            if (auto* window = CDescriptionWindow::instance()) window->requestDescription(description.data(), shift && (input.mouse_flags & MouseInput::leftPress) != 0u, reinterpret_cast<std::uintptr_t>(this));
        }
    }
    if ((input.mouse_flags & MouseInput::rightRelease) != 0u) right_pressed = 0u;
    if ((input.mouse_buttons & 1u) == 0u) left_pressed = drag_started = 0u;
    if (left_pressed != 0u && drag_started == 0u && (std::abs(static_cast<std::int64_t>(press_x) - input.mouse_x) > 2 || std::abs(static_cast<std::int64_t>(press_y) - input.mouse_y) > 2)) {
        notifyParent(*this, UiMessage::slotDrag);
        left_pressed = 0u;
        drag_started = 1u;
    }
}

void SphereUI::SlotCtrl::destroy(bool free_storage) {
    for (auto* sprite : {&top_left_overlay, &bottom_right_overlay, &bottom_left_overlay}) {
        if (*sprite != nullptr) (*sprite)->destroy();
        *sprite = 0u;
    }
    description.release();
    item_image.release();
    Window::destroy(free_storage);
}

void SphereUI::RichEditCtrl::initialize() {
    Window::initialize();
    lines = {};
    caret_row = caret_column = 0;
    blink_started = 0u;
    cursor_visible = 1u;
    std::fill_n(rich_reserved, 3, std::uint8_t{});
    cursor_width = line_height = page_rows = first_row = 0;
    scrollbar = nullptr;
    control_kind = UiControlKind::richEdit;
    hidden = input_enabled = 0u;
    lines.append("");
}

void SphereUI::RichEditCtrl::copyRichState(const RichEditCtrl& source) {
    if (this == &source) return;
    lines.copyFrom(source.lines);
    caret_row = source.caret_row;
    caret_column = source.caret_column;
    blink_started = source.blink_started;
    cursor_visible = source.cursor_visible;
    cursor_width = source.cursor_width;
    line_height = source.line_height;
    page_rows = source.page_rows;
    first_row = source.first_row;
    destroyOwned(scrollbar);
    cloneOwned(scrollbar, source.scrollbar, *this);
}

void SphereUI::RichEditCtrl::updateMetrics(std::uint32_t font_id) {
    const auto extent = InterfaceRenderer::measureText("_", font_id, true);
    cursor_width = std::max(0, extent.width);
    line_height = std::max(1, extent.height);
    page_rows = std::max(0, height / line_height - 1);
}

void SphereUI::RichEditCtrl::updateScroll() {
    if (auto* scroll = scrollbar) scroll->setParameters({sizeof(ScrollParameters), ScrollField::all, 0, std::max(0, static_cast<std::int32_t>(lines.size()) - page_rows - 1), page_rows, first_row, 1});
}

void SphereUI::RichEditCtrl::ensureCaretVisible() {
    if (lines.size() == 0u) lines.append("");
    caret_row = std::clamp(caret_row, 0, static_cast<std::int32_t>(lines.size()) - 1);
    caret_column = std::clamp(caret_column, 0, static_cast<std::int32_t>(lines.at(caret_row).length));
    first_row = std::max(0, std::clamp(first_row, caret_row - std::max(0, page_rows), caret_row));
    updateScroll();
}

void SphereUI::RichEditCtrl::moveCaret(std::uint32_t key) {
    ensureCaretVisible();
    const auto length = static_cast<std::int32_t>(lines.at(caret_row).length);
    switch (key) {
        case VK_LEFT:
            if (caret_column > 0) --caret_column;
            else if (caret_row > 0) caret_column = static_cast<std::int32_t>(lines.at(--caret_row).length);
            break;
        case VK_RIGHT:
            if (caret_column < length) ++caret_column;
            else if (caret_row + 1 < static_cast<std::int32_t>(lines.size())) {
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
    UiStringVector replacement{};
    std::string line;
    std::int32_t used_width = 0;
    try {
        for (unsigned char character : source) {
            const char glyph[] = {static_cast<char>(character), 0};
            const auto extent = InterfaceRenderer::measureText(glyph, font, font_initialized != 0u);
            if (character == '\n' || used_width + extent.width + cursor_width > width) {
                replacement.append(line.c_str());
                line.clear();
                used_width = 0;
            } else {
                line.push_back(static_cast<char>(character));
                used_width += extent.width;
            }
        }
        if (!line.empty() || replacement.size() == 0u) replacement.append(line.c_str());
    } catch (...) {
        replacement.release();
        throw;
    }
    lines.release();
    lines = replacement;
    caret_row = static_cast<std::int32_t>(lines.size()) - 1;
    caret_column = static_cast<std::int32_t>(lines.at(caret_row).length);
    ensureCaretVisible();
}

void SphereUI::RichEditCtrl::copyContent(char* destination, std::uint32_t capacity) const {
    if (destination == nullptr || capacity == 0u) return;
    std::size_t copied = 0u;
    for (std::uint32_t index = 0u; index < lines.size() && copied + 1u < capacity; ++index) {
        const auto& line = lines.at(index);
        const auto count = std::min<std::size_t>(line.length, capacity - copied - 1u);
        std::memcpy(destination + copied, line.data(), count);
        copied += count;
        if (count < line.length) break;
        if (copied + 1u < capacity) destination[copied++] = '\n';
    }
    destination[copied] = 0;
}

void SphereUI::RichEditCtrl::insertAt(std::uint32_t column, std::uint8_t character, std::uint32_t row) {
    for (;;) {
        if (row >= lines.size()) {
            const char glyph[] = {static_cast<char>(character), 0};
            lines.append(glyph);
            return;
        }
        std::string text = lines.at(row).data();
        text.insert(std::min<std::size_t>(column, text.size()), 1u, static_cast<char>(character));
        if (text.size() < 2u || InterfaceRenderer::measureText(text.c_str(), font, font_initialized != 0u).width + cursor_width <= width) {
            lines.at(row).assign(text.c_str());
            return;
        }
        character = static_cast<std::uint8_t>(text.back());
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
    const auto prospective = InterfaceRenderer::measureText(row.data(), font, font_initialized != 0u).width + InterfaceRenderer::measureText(glyph, font, font_initialized != 0u).width + cursor_width;
    if (caret_column == static_cast<std::int32_t>(row.length) && prospective >= width) {
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
        if (InterfaceRenderer::measureText(text.c_str(), font, font_initialized != 0u).width + cursor_width > width) {
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
    auto row = static_cast<std::uint32_t>(caret_row);
    std::string text = lines.at(row).data();
    if (backward && caret_column > 0) {
        text.erase(--caret_column, 1u);
        lines.at(row).assign(text.c_str());
    } else if (!backward && caret_column < static_cast<std::int32_t>(text.size())) {
        text.erase(caret_column, 1u);
        lines.at(row).assign(text.c_str());
    } else {
        if (backward) {
            if (row == 0u) return;
            --row;
            --caret_row;
            caret_column = static_cast<std::int32_t>(lines.at(row).length);
        }
        if (row + 1u >= lines.size()) return;
        const auto transferred = mergeRows(row, row + 1u);
        std::string remainder = lines.at(row + 1u).data();
        remainder.erase(0u, transferred);
        if (remainder.empty()) lines.erase(row + 1u);
        else lines.at(row + 1u).assign(remainder.c_str());
    }
    ensureCaretVisible();
}

void SphereUI::RichEditCtrl::splitLine() {
    ensureCaretVisible();
    std::string text = lines.at(caret_row).data();
    const auto following = text.substr(caret_column);
    text.resize(caret_column);
    lines.insert(static_cast<std::uint32_t>(caret_row + 1), following.c_str());
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
    if (input_enabled == 0u || cursor_visible == 0u || caret_row < 0 || caret_row >= static_cast<std::int32_t>(lines.size())) return;
    const std::string prefix(lines.at(caret_row).data(), std::clamp(caret_column, 0, static_cast<std::int32_t>(lines.at(caret_row).length)));
    const auto extent = InterfaceRenderer::measureText(prefix.c_str(), font, font_initialized != 0u);
    InterfaceRenderer::drawText("_", static_cast<std::int32_t>(left) + extent.width, static_cast<std::int32_t>(top), text_color, font, font_initialized != 0u, windowBounds(*this), false);
}

bool SphereUI::RichEditCtrl::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    loadPart(*this, scrollbar, reader, "scrollbar", filename, parser, UiControlKind::scrollBar, 1u);
    updateMetrics(font);
    updateScroll();
    return true;
}

SphereUI::Window* SphereUI::RichEditCtrl::clone() {
    return cloneControl(*this, [](RichEditCtrl& copy, const RichEditCtrl& source) {
        copy.copyRichState(source);
        copy.updateMetrics(source.font);
        copy.updateScroll();
    });
}

std::uint32_t SphereUI::RichEditCtrl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::setRichEditContent:
            if (first != 0u) setContent(reinterpret_cast<const char*>(first));
            return 1u;
        case UiMessage::getRichEditContent:
            if (first != 0u) copyContent(reinterpret_cast<char*>(first), second);
            return 1u;
        case UiMessage::verticalScroll:
            first_row = std::max(0, static_cast<std::int32_t>(first));
            return 1u;
        case UiMessage::setInputEnabled:
            setInputFocus(first != 0u);
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

void SphereUI::RichEditCtrl::draw() {
    if (hidden != 0u || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    {
        ViewportScope viewport(bounds);
        if (viewport) {
            const auto start = std::clamp(first_row, 0, static_cast<std::int32_t>(lines.size()));
            const auto finish = std::min(static_cast<std::int32_t>(lines.size()), start + std::max(0, page_rows) + 1);
            for (auto row = start; row < finish; ++row) InterfaceRenderer::drawText(lines.at(row).data(), bounds.left, bounds.top + (row - start) * line_height, text_color, font, font_initialized != 0u, bounds, false);
            if (caret_row >= start && caret_row < finish) drawCaret(static_cast<float>(bounds.left), static_cast<float>(bounds.top + (caret_row - start) * line_height));
        }
    }
    drawChild(scrollbar, alpha);
}

void SphereUI::RichEditCtrl::handleInput(const WindowInput& input) {
    if (input_enabled != 0u) Runtime::setTextInputActive(true);
    if (hidden != 0u) return;
    if (input_enabled != 0u) {
        if (input.character >= 32u) insertCharacter(input.character);
        const auto key = input.key_code;
        if (key == VK_BACK || key == VK_DELETE) eraseCharacter(key == VK_BACK);
        else if (key == VK_RETURN) splitLine();
        else if (key >= VK_PRIOR && key <= VK_DOWN) moveCaret(key);
        if (key == VK_BACK || key == VK_DELETE || key == VK_RETURN || (key >= VK_PRIOR && key <= VK_DOWN)) input.key_code = 0u;
    }
    inputChild(scrollbar, input);
    if ((input.mouse_flags & MouseInput::leftPress) != 0u) setInputFocus(hitTest(input.mouse_x, input.mouse_y));
}

void SphereUI::RichEditCtrl::destroy(bool free_storage) {
    Runtime::setTextInputActive(false);
    destroyOwned(scrollbar);
    lines.release();
    Window::destroy(free_storage);
}

namespace {
    void releaseDocument(SphereUI::HyperTextDocument*& address) {
        auto* document = address;
        address = nullptr;
        delete document;
    }

    void copyDocument(SphereUI::HyperTextDocument*& destination, const SphereUI::HyperTextDocument* source, const SphereUI::Window& owner, std::uint32_t format) {
        auto* original = source;
        auto* copy = original == nullptr ? nullptr : original->clone(owner.width - (owner.font < 2u ? 2 : 0), format, owner.font);
        releaseDocument(destination);
        destination = copy;
    }
}

void SphereUI::HyperTextCtrl::initialize() {
    Window::initialize();
    document = nullptr;
    text_format = 0u;
    std::fill_n(pending_name, 256u, char{});
    remember_page = 0u;
    std::fill_n(hypertext_reserved, 3u, std::uint8_t{});
    maximum_scroll = scroll_position = first_line_offset = clip_offset = clip_height = previous_line_offset = previous_clip_offset = previous_clip_height = 0;
    previous_document = nullptr;
    transition_fraction = 1.0f;
    transition_active = 0u;
    std::fill_n(transition_reserved, 3u, std::uint8_t{});
    transition_started = 0u;
    scrollbar = nullptr;
    history = {};
    history.initialize();
    link_color = UiColor::hyperLink;
    hover_color = UiColor::hyperLinkHover;
    tooltip_index = -1;
    pending_buffer = nullptr;
    pending_bytes = 0u;
    discard_old_text = 0u;
    std::fill_n(discard_reserved, 7u, std::uint8_t{});
    hidden = 0u;
    control_kind = UiControlKind::hyperText;
}

void SphereUI::HyperTextCtrl::copyHyperTextState(const HyperTextCtrl& source) {
    if (this == &source) return;
    history.copyFrom(source.history);
    copyDocument(document, source.document, source, source.text_format);
    copyDocument(previous_document, source.previous_document, source, source.text_format);
    destroyOwned(scrollbar);
    cloneOwned(scrollbar, source.scrollbar, *this);
    text_format = source.text_format;
    std::copy_n(source.pending_name, 256u, pending_name);
    remember_page = source.remember_page;
    maximum_scroll = source.maximum_scroll;
    scroll_position = source.scroll_position;
    first_line_offset = source.first_line_offset;
    clip_offset = source.clip_offset;
    clip_height = source.clip_height;
    previous_line_offset = source.previous_line_offset;
    previous_clip_offset = source.previous_clip_offset;
    previous_clip_height = source.previous_clip_height;
    transition_fraction = source.transition_fraction;
    transition_active = source.transition_active;
    transition_started = source.transition_started;
    link_color = source.link_color;
    hover_color = source.hover_color;
    tooltip_index = -1;
    pending_buffer = source.pending_buffer;
    pending_bytes = source.pending_bytes;
    discard_old_text = source.discard_old_text;
}

std::uint32_t SphereUI::HyperTextCtrl::parseTextFormat(const char* name) {
    if (SferaSimpleParser::equalsIgnoreCase(name, "RIGHT")) return 1u;
    if (SferaSimpleParser::equalsIgnoreCase(name, "CENTER")) return 2u;
    if (SferaSimpleParser::equalsIgnoreCase(name, "PARAGRAPH")) return 3u;
    return 0u;
}

void SphereUI::HyperTextCtrl::queuePage(const char* name, bool remember) {
    if (transition_active != 0u) return;
    if (name == nullptr) {
        pending_name[0] = 0;
        return;
    }
    const std::string value(name);
    const auto count = std::min(value.size(), sizeof(pending_name) - 1u);
    std::memmove(pending_name, value.data(), count);
    pending_name[count] = 0;
    remember_page = remember ? 1u : 0u;
}

void SphereUI::HyperTextCtrl::queueBuffer(const char* buffer, std::uint32_t size) {
    if (transition_active != 0u || buffer == nullptr || size == 0u) return;
    std::memcpy(pending_name, "buffer", 7u);
    remember_page = 0u;
    pending_buffer = buffer;
    pending_bytes = size;
}

void SphereUI::HyperTextCtrl::updateScroll() {
    auto* page = document;
    if (page == nullptr) return;
    scroll_position = std::clamp(scroll_position, 0, std::max(0, maximum_scroll));
    first_line_offset = 0;
    clip_offset = -scroll_position;
    clip_height = height;
    page->resetRegions();
}

void SphereUI::HyperTextCtrl::updateDocument(bool resize_to_content) {
    if (pending_name[0] == 0) return;
    const auto page_width = width - (font < 2u ? 2 : 0);
    HyperTextDocument* replacement = nullptr;
    if (pending_buffer != nullptr) replacement = new HyperTextDocument(std::string_view(pending_buffer, pending_bytes), page_width, text_format, font);
    else if (auto* source = g_sfera_interface.findHyperText(pending_name)) replacement = source->clone(page_width, text_format, font);
    if (replacement != nullptr) {
        auto* current = document;
        try {
            if (current != nullptr && discard_old_text == 0u && remember_page != 0u && !current->name.empty()) history.append(current->name.c_str());
        } catch (...) {
            delete replacement;
            throw;
        }
        if (current != nullptr) {
            if (discard_old_text != 0u) releaseDocument(document);
            else {
                releaseDocument(previous_document);
                previous_document = document;
                previous_line_offset = first_line_offset;
                previous_clip_offset = clip_offset;
                previous_clip_height = clip_height;
                transition_fraction = 0.0f;
                transition_active = 1u;
                transition_started = Runtime::clockTicks();
            }
            notifyParent(*this, UiMessage::hyperTextPageChanged);
            if (auto* tip = tooltip) static_cast<ToolTipCtrl*>(tip)->reset();
        }
        document = replacement;
        replacement->link_color = link_color;
        replacement->hover_color = hover_color;
        tooltip_index = -1;
        const auto extent = replacement->totalHeight();
        if (resize_to_content && extent > 0) height = extent;
        maximum_scroll = std::max(0, extent - height);
        scroll_position = 0;
        updateScroll();
        if (auto* scroll = scrollbar) scroll->setParameters({sizeof(ScrollParameters), ScrollField::all, 0, maximum_scroll, height, 0, replacement->line_height});
    }
    pending_name[0] = 0;
    pending_buffer = nullptr;
    pending_bytes = 0u;
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
    if (const char* value = reader.string("flags")) if (SferaSimpleParser::equalsIgnoreCase(value, "DISCARD_OLD_TEXT")) discard_old_text = 1u;
    return true;
}

SphereUI::Window* SphereUI::HyperTextCtrl::clone() {
    return cloneControl(*this, [](HyperTextCtrl& copy, const HyperTextCtrl& source) {
        copy.copyHyperTextState(source);
        if (copy.tooltip == nullptr) copy.tooltip = createInitialized<ToolTipCtrl>();
    });
}

std::uint32_t SphereUI::HyperTextCtrl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
    switch (message) {
        case UiMessage::verticalScroll:
            if (document != nullptr) {
                scroll_position = static_cast<std::int32_t>(first);
                updateScroll();
            }
            return 1u;
        case UiMessage::previousHyperTextPage:
        case UiMessage::firstHyperTextPage:
            if (history.count != 0u) {
                if (message == UiMessage::firstHyperTextPage) while (history.count > 1u) history.popBack();
                const std::string name = history.at(history.count - 1u).data();
                history.popBack();
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
    if (hidden != 0u) return;
    if (auto* tip = tooltip) if (tip->hidden == 0u && tip->alpha != alpha) tip->setOpacity(static_cast<float>(alpha) / 255.0f);
    const auto bounds = windowBounds(*this);
    {
        ViewportScope viewport(bounds);
        if (viewport) {
            const auto fraction = std::clamp(transition_fraction, 0.0f, 1.0f);
            if (auto* page = previous_document) page->draw(bounds.left, bounds.top - previous_line_offset, previous_clip_offset, previous_clip_height, static_cast<std::uint32_t>((1.0f - fraction) * alpha));
            if (auto* page = document) page->draw(bounds.left, bounds.top - first_line_offset, clip_offset, clip_height, static_cast<std::uint32_t>(fraction * alpha));
        }
    }
    drawChild(scrollbar, alpha);
}

void SphereUI::HyperTextCtrl::handleInput(const WindowInput& input) {
    updateDocument(false);
    inputChild(scrollbar, input);
    if (transition_active != 0u) {
        const auto now = Runtime::clockTicks();
        const auto elapsed = now >= transition_started ? now - transition_started : 0u;
        transition_fraction = std::clamp(static_cast<float>(static_cast<double>(elapsed) / 5000.0), 0.0f, 1.0f);
        if (elapsed > 5000u) {
            transition_active = 0u;
            releaseDocument(previous_document);
        }
    }
    auto* page = document;
    if (page == nullptr) return;
    std::int32_t hovered = -1;
    for (std::uint32_t index = 0u; index < page->tooltips.size(); ++index) {
        auto& region = page->tooltips.at(index);
        region.hovered = region.contains(input.mouse_x, input.mouse_y) ? 1u : 0u;
        if (region.hovered != 0u && hovered < 0) hovered = static_cast<std::int32_t>(index);
    }
    if (hovered != tooltip_index) {
        if (auto* tip = static_cast<ToolTipCtrl*>(tooltip)) {
            tip->reset();
            if (hovered >= 0) {
                tip->setLine(0u, page->tooltips.at(hovered).target.c_str());
                tip->showAt(input.mouse_x, input.mouse_y);
            }
        }
        tooltip_index = hovered;
    }
    for (std::uint32_t index = 0u; index < page->links.size(); ++index) {
        auto& link = page->links.at(index);
        link.hovered = link.contains(input.mouse_x, input.mouse_y) ? 1u : 0u;
        if (link.hovered != 0u && (input.mouse_flags & MouseInput::leftPress) != 0u) {
            openLink(link.target.c_str());
            Runtime::playLinkSound();
        }
    }
}

void SphereUI::HyperTextCtrl::destroy(bool free_storage) {
    releaseDocument(document);
    releaseDocument(previous_document);
    destroyOwned(scrollbar);
    history.release();
    Window::destroy(free_storage);
}

void SphereUI::HyperTextChatListControl::initialize() {
    Window::initialize();
    control_kind = UiControlKind::hyperTextChat;
    messages = {};
    messages.initialize();
    visible_messages = {};
    channels = {};
    selected_link_text = {};
    selected_link_value = {};
    selected_plain_text = {};
    selected_hyper_text = {};
    player_link_color = item_link_color = link_color = UiColor::white;
    maximum_items = 256u;
    row_height = 15u;
    page_rows = 0u;
    parent_x = parent_y = 0;
    bottom_message = bottom_row = scroll_offset = 0u;
    scrollbar = nullptr;
    saved_viewport = {};
    rendered_rows = {};
}

void SphereUI::HyperTextChatListControl::copyChatState(const HyperTextChatListControl& source) {
    if (this == &source) return;
    messages.copyFrom(source.messages);
    visible_messages.copyFrom(source.visible_messages);
    channels.copyFrom(source.channels);
    selected_link_text.assign(source.selected_link_text.data());
    selected_link_value.assign(source.selected_link_value.data());
    selected_plain_text.assign(source.selected_plain_text.data());
    selected_hyper_text.assign(source.selected_hyper_text.data());
    player_link_color = source.player_link_color;
    item_link_color = source.item_link_color;
    link_color = source.link_color;
    maximum_items = source.maximum_items;
    row_height = source.row_height;
    page_rows = source.page_rows;
    parent_x = source.parent_x;
    parent_y = source.parent_y;
    bottom_message = source.bottom_message;
    bottom_row = source.bottom_row;
    scroll_offset = source.scroll_offset;
    saved_viewport = source.saved_viewport;
    rendered_rows.copyFrom(source.rendered_rows);
    destroyOwned(scrollbar);
    cloneOwned(scrollbar, source.scrollbar, *this);
}

SphereUI::Window* SphereUI::HyperTextChatListControl::clone() {
    return cloneControl(*this, [](auto& copy, const auto& source) {
        copy.copyChatState(source);
    });
}

void SphereUI::HyperTextChatListControl::destroy(bool free_storage) {
    destroyOwned(scrollbar);
    messages.release();
    visible_messages.release();
    channels.release();
    rendered_rows.release();
    selected_link_text.release();
    selected_link_value.release();
    selected_plain_text.release();
    selected_hyper_text.release();
    Window::destroy(free_storage);
}

bool SphereUI::HyperTextChatListControl::loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) {
    UiReader reader(parser, range);
    if (!reader.has("linkColor")) return false;
    reader.color("linkColor", link_color);
    player_link_color = item_link_color = link_color;
    reader.color("playerLinkColor", player_link_color);
    reader.color("itemLinkColor", item_link_color);
    maximum_items = 256u;
    row_height = 15u;
    reader.integer("maxItems", maximum_items);
    reader.integer("rowHeight", row_height);
    maximum_items = std::clamp(maximum_items, 1u, maximumScrollOffset);
    row_height = std::clamp(row_height, 1u, maximumScrollOffset);
    font = std::max<std::uint8_t>(font, 2u);
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
    for (std::uint32_t reverse = messages.count; reverse != 0u; --reverse) {
        const auto& item = messages.at(reverse - 1u);
        for (std::uint32_t channel = 0u; channel < channels.size(); ++channel) if (channels.at(channel) == item.channel) {
            visible_messages.append(reverse - 1u);
            break;
        }
    }
    if (visible_messages.size() == 0u) bottom_message = bottom_row = scroll_offset = 0u;
}

const char* SphereUI::HyperTextChatListControl::messageText(std::uint32_t index, bool plain) const {
    if (index >= visible_messages.size()) return "";
    const auto& item = messages.at(visible_messages.at(index));
    return plain ? item.plain_text.data() : item.hyper_text.data();
}

void SphereUI::HyperTextChatListControl::addMessage(const char* text, std::uint32_t channel, std::uint32_t color) {
    HyperTextChatListItem item{};
    try {
        item.initialize(text, channel, color);
        item.layout(width, font);
        if (item.rows.size() == 0u) {
            item.release();
            return;
        }
        messages.pushBack(item);
    } catch (...) {
        item.release();
        throw;
    }
    item.release();
    while (messages.count > std::max(maximum_items, 1u)) messages.popFront();
    bool visible = false;
    for (std::uint32_t index = 0u; index < channels.size(); ++index) visible |= channels.at(index) == channel;
    if (visible) scroll_offset = 0u;
    rebuildVisible();
    updateScroll(false);
}

void SphereUI::HyperTextChatListControl::addChannel(std::uint32_t channel) {
    for (std::uint32_t index = 0u; index < channels.size(); ++index) if (channels.at(index) == channel) return;
    channels.append(channel);
    scroll_offset = 0u;
    rebuildVisible();
    updateScroll(false);
}

void SphereUI::HyperTextChatListControl::setChannels(const std::uint32_t* values, std::uint32_t count) {
    if (values == nullptr && count != 0u) return;
    UiIndexVector replacement{};
    try {
        for (std::uint32_t index = 0u; index < count; ++index) replacement.append(values[index]);
    } catch (...) {
        replacement.release();
        throw;
    }
    channels.release();
    channels = replacement;
    scroll_offset = 0u;
    rebuildVisible();
    updateScroll(false);
}

void SphereUI::HyperTextChatListControl::clearChannels() {
    channels.clear();
    rebuildVisible();
    updateScroll(true);
}

void SphereUI::HyperTextChatListControl::setFont(std::uint32_t font_id) {
    if (font == font_id) return;
    Window::setFont(font_id);
    for (std::uint32_t index = 0u; index < messages.count; ++index) {
        auto& item = messages.at(index);
        const std::string text = item.hyper_text.data();
        const auto channel = item.channel;
        const auto color = item.color;
        HyperTextChatListItem replacement{};
        try {
            replacement.initialize(text.c_str(), channel, color);
            replacement.layout(width, font);
            item.copyFrom(replacement);
        } catch (...) {
            replacement.release();
            throw;
        }
        replacement.release();
    }
    scroll_offset = 0u;
    rebuildVisible();
    updateScroll(false);
}

void SphereUI::HyperTextChatListControl::updateParentPosition() {
    parent_x = parent_y = 0;
    if (auto* owner = parent) owner->getAbsolutePosition(parent_x, parent_y);
}

bool SphereUI::HyperTextChatListControl::visibleRowRange(std::uint32_t message, std::uint32_t drawn, std::uint32_t rows, std::uint32_t* first, std::uint32_t* last) const {
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
    for (std::uint32_t index = 0u; index < visible_messages.size(); ++index) total += messages.at(visible_messages.at(index)).rows.size();
    const auto maximum = static_cast<std::uint32_t>(std::min<std::uint64_t>(total > page_rows ? total - page_rows : 0u, maximumScrollOffset));
    scroll_offset = reset ? 0u : std::min(scroll_offset, maximum);
    bottom_message = bottom_row = 0u;
    auto skip = scroll_offset;
    for (std::uint32_t index = 0u; index < visible_messages.size(); ++index) {
        const auto count = messages.at(visible_messages.at(index)).rows.size();
        if (skip < count) {
            bottom_message = index;
            bottom_row = count - skip - 1u;
            break;
        }
        skip -= count;
    }
    if (auto* child = scrollbar) child->setParameters({sizeof(ScrollParameters), ScrollField::all, 0, static_cast<std::int32_t>(reset ? 0u : maximum), 1, static_cast<std::int32_t>(reset ? 0u : maximum - scroll_offset), 1});
}

void SphereUI::HyperTextChatListControl::readScroll() {
    if (auto* child = scrollbar) {
        ScrollParameters parameters{};
        child->getParameters(parameters);
        scroll_offset = static_cast<std::uint32_t>(std::max(parameters.maximum - parameters.current, 0));
        updateScroll(false);
    }
}

void SphereUI::HyperTextChatListControl::drawElement(HyperTextElement& element, std::int32_t left, std::int32_t top, std::uint32_t color) {
    auto* geometry = element.geometry();
    if (geometry == nullptr || (element.type != 4u && element.type != 5u)) return;
    geometry->x = left - detail::addCoordinate(parent_x, x);
    geometry->y = top - detail::addCoordinate(parent_y, y);
    if (element.type == 5u) {
        const auto kind = static_cast<HyperTextElement_Link&>(element).link_kind;
        if (kind == 1u) color = item_link_color;
        else if (kind == 2u) color = (color & UiColor::alphaMask) | ((((color >> 16u) & 255u) * 3u / 4u) << 16u) | ((((color >> 8u) & 255u) * 3u / 4u) << 8u) | ((color & 255u) * 3u / 4u);
        else color = link_color;
    }
    const UiRect clip{left, top, detail::addCoordinate(left, std::max(geometry->width, 1) - 1), detail::addCoordinate(top, std::max(geometry->height, 1) - 1)};
    InterfaceRenderer::drawText(element.text.data(), left, top, (color & kRgbColorMask) | (alpha << 24u), font, true, clip, false);
}

void SphereUI::HyperTextChatListControl::draw() {
    if (hidden != 0u || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    updateParentPosition();
    updateScroll(false);
    rendered_rows.clear();
    const auto bounds = windowBounds(*this);
    {
        ViewportScope viewport(bounds);
        for (std::uint32_t item_index = bottom_message; item_index < visible_messages.size() && rendered_rows.size() < page_rows; ++item_index) {
            auto& item = messages.at(visible_messages.at(item_index));
            std::uint32_t first = 0u, last = 0u;
            if (!visibleRowRange(item_index, rendered_rows.size(), item.rows.size(), &first, &last)) continue;
            for (std::uint32_t reverse = last + 1u; reverse > first; --reverse) {
                const auto row = reverse - 1u;
                const auto top = detail::subtractCoordinate(detail::subtractCoordinate(bounds.bottom, 1), static_cast<std::int32_t>((rendered_rows.size() + 1u) * row_height));
                rendered_rows.append({item_index, row});
                auto left = bounds.left;
                const auto range = item.rows.at(row);
                for (std::uint32_t index = range.first; index <= range.last && index < item.elements.count; ++index) if (auto* element = item.elements.at(index)) if (auto* geometry = element->geometry()) {
                    drawElement(*element, left, top, item.color);
                    left = detail::addCoordinate(left, geometry->width);
                }
            }
        }
    }
    drawChild(scrollbar, alpha);
}

void SphereUI::HyperTextChatListControl::handleInput(const WindowInput& input) {
    if (hidden != 0u || visible_messages.size() == 0u) return;
    inputChild(scrollbar, input);
    updateParentPosition();
    const auto bounds = windowBounds(*this);
    if (!contains(bounds, input.mouse_x, input.mouse_y) || (input.mouse_flags & MouseInput::anyRelease) == 0u) return;
    const auto row = static_cast<std::uint32_t>(std::max(bounds.bottom - 1 - input.mouse_y, 0)) / std::max(row_height, 1u);
    if (row >= rendered_rows.size()) return;
    const auto rendered = rendered_rows.at(row);
    if (rendered.first >= visible_messages.size()) return;
    auto& item = messages.at(visible_messages.at(rendered.first));
    if (rendered.last >= item.rows.size()) return;
    const auto range = item.rows.at(rendered.last);
    for (std::uint32_t index = range.first; index <= range.last && index < item.elements.count; ++index) {
        auto* element = item.elements.at(index);
        if (element == nullptr || element->type != 5u) continue;
        auto& link = *static_cast<HyperTextElement_Link*>(element);
        const auto& rectangle = link.bounds;
        const auto local_x = input.mouse_x - bounds.left;
        const auto local_y = input.mouse_y - bounds.top;
        if (local_x < rectangle.x || local_y < rectangle.y || local_x >= rectangle.x + rectangle.width || local_y >= rectangle.y + rectangle.height) continue;
        if ((input.mouse_flags & MouseInput::leftRelease) != 0u && (input.key_modifiers & 1u) != 0u) {
            if (auto* description = Runtime::descriptionWindow()) description->showDescription(link.linkValue(), 0u, 250u, false);
        } else if (link.link_kind == 1u && (input.mouse_flags & MouseInput::leftRelease) != 0u) {
            if (auto* description = Runtime::descriptionWindow()) description->showDescription(link.linkValue(), 0u, 5000u, true);
        } else if (link.link_kind == 2u) {
            selected_link_text.assign(link.text.data());
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

std::uint32_t SphereUI::HyperTextChatListControl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
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
    class OwnedHyperTextElements {
    public:
        SphereUI::UiDeque<HyperTextElement*> values{};
        OwnedHyperTextElements() = default;
        OwnedHyperTextElements(const OwnedHyperTextElements&) = delete;
        OwnedHyperTextElements& operator=(const OwnedHyperTextElements&) = delete;
        ~OwnedHyperTextElements() {
            SphereUI::HyperTextParser::releaseElements(values);
        }

        void append(HyperTextElement* element) {
            if (element == nullptr) return;
            try {
                values.pushBack(element);
            } catch (...) {
                element->release();
                throw;
            }
        }

        void copy(const HyperTextElement& element) {
            append(element.clone());
        }

        void plain(std::string_view text) {
            if (text.empty()) return;
            if (values.count != 0u) if (auto* last = (values.at(values.count - 1u)); last != nullptr && last->type == 4u) {
                const std::string merged = std::string(last->text.data(), last->text.length) + std::string(text);
                last->text.assign(merged.c_str());
                return;
            }
            auto* memory = SphereUI::Runtime::allocate(sizeof(HyperTextElement_PlainText));
            if (memory == nullptr) throw std::bad_alloc();
            auto* element = std::construct_at(static_cast<HyperTextElement_PlainText*>(memory));
            element->text = {};
            element->bounds = {};
            try {
                element->initializeText(4u, std::string(text).c_str());
            } catch (...) {
                element->release();
                throw;
            }
            append(element);
        }

        void take(SphereUI::UiDeque<HyperTextElement*>& destination) {
            SphereUI::HyperTextParser::releaseElements(destination);
            destination = values;
            values = {};
            if (destination.proxy != 0u) destination.proxy->owner = &destination;
        }
    };

    void appendEditorElement(OwnedHyperTextElements& destination, const HyperTextElement& element) {
        if (element.type == 4u) destination.plain(std::string_view(element.text.data(), element.text.length));
        else destination.copy(element);
    }

    void commitEditorElements(SphereUI::HyperTextEditControl& editor, OwnedHyperTextElements& replacement) {
        SphereUI::UiString raw{}, visible{};
        try {
            SphereUI::detail::serializeHyperTextElements(replacement.values, raw, visible);
        } catch (...) {
            raw.release();
            visible.release();
            throw;
        }
        editor.hyper_text.release();
        editor.visible_text.release();
        editor.hyper_text = raw;
        editor.visible_text = visible;
        replacement.take(editor.elements);
    }

    std::string editorHistoryPath(const SphereUI::HyperTextEditControl& editor) {
        const auto* parent = editor.parent;
        if (parent == nullptr || parent->resource_name_length == 0u) return {
        };
        SphereUI::UiString profile{};
        SphereUI::HyperTextEditControl::historyProfile(profile);
        const std::string path = std::string("players\\") + SphereUI::detail::stringData(parent->resource_name, parent->resource_name_capacity) + "_" + profile.data() + "_hyperTextEdit.log";
        profile.release();
        return path;
    }
}

void SphereUI::HyperTextEditControl::initialize() {
    Window::initialize();
    history = {};
    history_position = 0u;
    maximum_history = 256u;
    edit_modes = {};
    visible_text = {};
    hyper_text = {};
    elements = {};
    cursor_type = 1u;
    caret_position = blink_started = 0u;
    cursor_visible = 1u;
    std::fill_n(cursor_reserved, 3u, std::uint8_t{});
    text_margins = {};
    cursor_color = plain_color = player_link_color = item_link_color = link_color = UiColor::white;
    maximum_visible_length = 256u;
    maximum_hyper_length = 3072u;
    visible_first = visible_last = 0u;
    saved_viewport = {};
    parent_x = parent_y = 0;
    control_kind = UiControlKind::hyperTextEdit;
    history.initialize();
    elements.initialize();
    edit_modes.insert(0u);
}

void SphereUI::HyperTextEditControl::setContent(const char* text, std::uint32_t mode) {
    if (text == nullptr || mode > 1u) return;
    const std::string source(text);
    if (mode == 0u && source == hyper_text.data()) return;
    if (source.size() + (mode == 1u ? hyper_text.length : 0u) > maximum_hyper_length) return;
    UiString raw{}, plain{};
    OwnedHyperTextElements parsed, replacement;
    try {
        raw.assign(source.c_str());
        HyperTextParser::parseElements(raw, parsed.values, plain);
    } catch (...) {
        raw.release();
        plain.release();
        throw;
    }
    raw.release();
    const auto added_length = plain.length;
    plain.release();
    if (mode == 1u && static_cast<std::uint64_t>(visible_text.length) + added_length > maximum_visible_length) return;
    std::uint32_t used = 0u;
    const auto append = [&](const UiDeque<HyperTextElement*>& input) {
        for (std::uint32_t index = 0u; index < input.count; ++index) if (auto* element = input.at(index)) {
            const auto length = element->text.length;
            if (used >= maximum_visible_length) break;
            if (length > maximum_visible_length - used) {
                replacement.plain(std::string_view(element->text.data(), maximum_visible_length - used));
                used = maximum_visible_length;
            } else {
                appendEditorElement(replacement, *element);
                used += length;
            }
        }
    };
    if (mode == 1u) append(elements);
    append(parsed.values);
    commitEditorElements(*this, replacement);
    moveCaret(35u);
}

void SphereUI::HyperTextEditControl::insertPlainText(const char* text) {
    if (text == nullptr || visible_text.length >= maximum_visible_length) return;
    const std::string insertion(text, std::min<std::size_t>(std::strlen(text), maximum_visible_length - visible_text.length));
    if (insertion.empty()) return;
    caret_position = std::min(caret_position, visible_text.length);
    OwnedHyperTextElements replacement;
    std::uint32_t position = 0u;
    bool inserted = false;
    for (std::uint32_t index = 0u; index < elements.count; ++index) if (auto* element = elements.at(index)) {
        const auto length = element->text.length;
        if (!inserted && caret_position <= position + length) {
            const auto offset = caret_position - position;
            if (element->type == 5u && offset == 0u) {
                replacement.plain(insertion);
                replacement.copy(*element);
            } else if (element->type == 5u && offset == length) {
                replacement.copy(*element);
                replacement.plain(insertion);
            } else {
                std::string value(element->text.data(), length);
                value.insert(offset, insertion);
                replacement.plain(value);
            }
            inserted = true;
        } else appendEditorElement(replacement, *element);
        position += length;
    }
    if (!inserted) replacement.plain(insertion);
    const auto caret = caret_position + static_cast<std::uint32_t>(insertion.size());
    commitEditorElements(*this, replacement);
    caret_position = caret;
    visible_last = caret_position == 0u ? 0u : caret_position - 1u;
    updateVisibleStart();
    updateVisibleEnd();
}

void SphereUI::HyperTextEditControl::insertCharacter(std::uint8_t character) {
    if (!edit_modes.contains(0u) || character < 32u || (edit_modes.contains(1u) && (character < '0' || character > '9'))) return;
    const char text[] = {static_cast<char>(character), 0};
    insertPlainText(text);
}

void SphereUI::HyperTextEditControl::eraseCharacter(bool backspace) {
    caret_position = std::min(caret_position, visible_text.length);
    if ((backspace && caret_position == 0u) || (!backspace && caret_position == visible_text.length)) return;
    const auto target = caret_position - (backspace ? 1u : 0u);
    OwnedHyperTextElements replacement;
    std::uint32_t position = 0u;
    for (std::uint32_t index = 0u; index < elements.count; ++index) if (auto* element = elements.at(index)) {
        const auto length = element->text.length;
        if (target >= position && target < position + length) {
            std::string value(element->text.data(), length);
            value.erase(target - position, 1u);
            replacement.plain(value);
        } else appendEditorElement(replacement, *element);
        position += length;
    }
    commitEditorElements(*this, replacement);
    caret_position = target;
    visible_first = std::min(visible_first, caret_position);
    updateVisibleEnd();
}

std::uint32_t SphereUI::HyperTextEditControl::fitText(const char* text, std::uint32_t font, std::int32_t pixels, bool reverse) {
    const std::string_view value(text == nullptr ? "" : text);
    if (pixels <= 0 || value.empty()) return 0u;
    std::int64_t used = 0;
    for (std::size_t count = 0u; count < value.size(); ++count) {
        const auto index = reverse ? value.size() - count - 1u : count;
        const char glyph[] = {value[index], 0};
        used += InterfaceRenderer::measureText(glyph, font, true).width;
        if (used > pixels) return static_cast<std::uint32_t>(index);
    }
    return reverse ? 0u : static_cast<std::uint32_t>(value.size());
}

void SphereUI::HyperTextEditControl::updateVisibleEnd() {
    visible_first = std::min(visible_first, visible_text.length);
    if (visible_text.length == 0u) {
        visible_last = 0u;
        return;
    }
    const auto length = visible_text.length - visible_first;
    const auto fit = fitText(visible_text.data() + visible_first, font, std::max(0, width - text_margins.left - text_margins.right), false);
    visible_last = std::min(visible_text.length - 1u, visible_first + (fit == length ? (length == 0u ? 0u : length - 1u) : fit));
}

void SphereUI::HyperTextEditControl::updateVisibleStart() {
    if (visible_text.length == 0u) {
        visible_first = visible_last = 0u;
        return;
    }
    visible_last = std::min(visible_last, visible_text.length - 1u);
    const std::string prefix(visible_text.data(), visible_last + 1u);
    const auto first = fitText(prefix.c_str(), font, std::max(0, width - text_margins.left - text_margins.right), true);
    visible_first = first == 0u ? 0u : first + 1u;
}

void SphereUI::HyperTextEditControl::moveCaret(std::uint32_t key) {
    caret_position = std::min(caret_position, visible_text.length);
    if (key == VK_HOME) {
        caret_position = visible_first = 0u;
        updateVisibleEnd();
    } else if (key == VK_END) {
        caret_position = visible_text.length;
        visible_last = caret_position == 0u ? 0u : caret_position - 1u;
        updateVisibleStart();
    } else if (key == VK_LEFT && caret_position != 0u) {
        --caret_position;
        if (caret_position < visible_first) visible_first = caret_position;
        updateVisibleEnd();
    } else if (key == VK_RIGHT && caret_position < visible_text.length) {
        ++caret_position;
        if (caret_position > visible_last + 1u) {
            visible_last = caret_position - 1u;
            updateVisibleStart();
        }
        updateVisibleEnd();
    }
}

void SphereUI::HyperTextEditControl::drawElement(const TextExtent& point, HyperTextElement& element, std::uint32_t color, const UiIndexRange& range) {
    if (element.type != 4u && element.type != 5u) return;
    const auto first = std::min(range.first, element.text.length);
    const auto length = range.last == invalidIndex ? element.text.length - first : std::min(element.text.length - first, range.last >= first ? range.last - first + 1u : 0u);
    std::string display(element.text.data() + first, length);
    if (element.type == 4u && edit_modes.contains(2u)) display.assign(length, '*');
    if (element.type == 5u) {
        const auto kind = static_cast<HyperTextElement_Link&>(element).link_kind;
        color = kind == 1u ? item_link_color : kind == 2u ? player_link_color : link_color;
    }
    const auto extent = InterfaceRenderer::measureText(display.c_str(), font, true);
    if (auto* geometry = element.geometry()) *geometry = {point.width, point.height, extent.width, extent.height};
    InterfaceRenderer::drawText(display.c_str(), point.width, point.height, (color & kRgbColorMask) | (alpha << 24u), font, true, windowBounds(*this), false);
}

void SphereUI::HyperTextEditControl::drawCaret() {
    if (cursor_type == 0u) return;
    const auto bounds = windowBounds(*this);
    const auto start = std::min(visible_first, visible_text.length), caret = std::clamp(caret_position, start, visible_text.length);
    std::string prefix(visible_text.data() + start, caret - start);
    const auto left = bounds.left + text_margins.left + InterfaceRenderer::measureText(prefix.c_str(), font, true).width;
    const auto top = bounds.top + text_margins.top;
    const auto color = (cursor_color & kRgbColorMask) | (alpha << 24u);
    if (cursor_type == 2u) InterfaceRenderer::drawText("_", left, top, color, font, true, bounds, false);
    else if (cursor_type == 1u) InterfaceRenderer::drawTexture(nullptr, static_cast<float>(left), static_cast<float>(top + 2), static_cast<float>(left + 1), static_cast<float>(bounds.bottom - text_margins.bottom - 2), color, 0.0f, 0.0f, false);
}

void SphereUI::HyperTextEditControl::draw() {
    if (hidden != 0u || (behavior_flags & WindowStyle::skipDrawing) != 0u) return;
    const auto bounds = windowBounds(*this);
    saved_viewport = InterfaceRenderer::viewport();
    parent_x = parent_y = 0;
    if (const auto* owner = parent) owner->getAbsolutePosition(parent_x, parent_y);
    ViewportScope clip(bounds);
    if (!clip) return;
    const auto now = Runtime::milliseconds();
    if (now - blink_started > 500u) {
        blink_started = now;
        cursor_visible = cursor_visible == 0u ? 1u : 0u;
    }
    caret_position = std::min(caret_position, visible_text.length);
    updateVisibleEnd();
    if (cursor_visible != 0u && input_enabled != 0u) drawCaret();
    std::uint32_t position = 0u;
    TextExtent point{bounds.left + text_margins.left, bounds.top + text_margins.top};
    for (std::uint32_t index = 0u; index < elements.count; ++index) if (auto* element = elements.at(index)) {
        const auto length = element->text.length;
        if (length != 0u && position + length > visible_first && position <= visible_last) {
            const UiIndexRange range{visible_first > position ? visible_first - position : 0u, std::min(length - 1u, visible_last - position)};
            drawElement(point, *element, plain_color, range);
            if (const auto* geometry = element->geometry()) point.width = detail::addCoordinate(point.width, geometry->width);
        }
        position += length;
    }
}

void SphereUI::HyperTextEditControl::historyUp() {
    if (edit_modes.contains(2u) || history.count == 0u) return;
    history_position = std::min(history_position, history.count);
    if (history_position != 0u) --history_position;
    setContent(history.at(history_position).data());
}

void SphereUI::HyperTextEditControl::historyDown() {
    if (edit_modes.contains(2u) || history.count == 0u) return;
    if (history_position < history.count) ++history_position;
    setContent(history.at(std::min(history_position, history.count - 1u)).data());
}

void SphereUI::HyperTextEditControl::submitText() {
    notifyParent(*this, UiMessage::hyperEditSubmit);
    if (edit_modes.contains(2u) || hyper_text.length == 0u || maximum_history == 0u) return;
    UiStringDeque replacement{};
    try {
        for (std::uint32_t index = 0u; index < history.count; ++index) if (std::strcmp(history.at(index).data(), hyper_text.data()) != 0) replacement.append(history.at(index).data());
        while (replacement.count >= maximum_history) replacement.popFront();
        replacement.append(hyper_text.data());
    } catch (...) {
        replacement.release();
        throw;
    }
    history.release();
    history = replacement;
    if (history.proxy != 0u) history.proxy->owner = &history;
    history_position = history.count;
}

void SphereUI::HyperTextEditControl::pasteClipboard() {
    UiString clipboard{};
    Runtime::clipboardText(clipboard);
    std::string value(clipboard.data(), clipboard.length);
    clipboard.release();
    for (char& character : value) if (character == '\n' || character == '\r') character = ' ';
    insertPlainText(value.c_str());
}

void SphereUI::HyperTextEditControl::historyProfile(UiString& result) {
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

void SphereUI::HyperTextEditControl::transformHistory(UiString& result, const UiString& source, bool decode) {
    constexpr std::int8_t primary[] = {1, 2, 3, -2, 1, -1, -2, -3, 2, -1, 0, -2, 2};
    constexpr std::int8_t secondary[] = {0, -1, -2, 2, -1, 0, 1};
    std::string value(source.data(), source.length);
    for (std::size_t index = 0u; index < value.size(); ++index) {
        const auto shift = primary[index % 13u] + secondary[index % 7u];
        value[index] = static_cast<char>(static_cast<unsigned char>(value[index]) + (decode ? shift : -shift));
    }
    detail::assignString(result.storage, result.length, result.capacity, value);
}

void SphereUI::HyperTextEditControl::loadHistory() {
    if (edit_modes.contains(2u)) return;
    const auto path = editorHistoryPath(*this);
    if (path.empty()) return;
    std::ifstream stream(path, std::ios::binary);
    std::string line;
    while (history.count < maximum_history && std::getline(stream, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        UiString encoded{}, decoded{};
        try {
            detail::assignString(encoded.storage, encoded.length, encoded.capacity, line);
            transformHistory(decoded, encoded, true);
            history.pushBack(decoded);
        } catch (...) {
            encoded.release();
            decoded.release();
            throw;
        }
        encoded.release();
        decoded.release();
    }
    history_position = history.count;
}

void SphereUI::HyperTextEditControl::saveHistory() const {
    if (edit_modes.contains(2u) || history.count == 0u) return;
    const auto path = editorHistoryPath(*this);
    if (path.empty()) return;
    std::ofstream stream(path, std::ios::binary);
    for (std::uint32_t index = 0u; index < history.count && stream; ++index) {
        UiString encoded{};
        transformHistory(encoded, history.at(index), false);
        stream.write(encoded.data(), encoded.length);
        stream << "\r\n";
        encoded.release();
    }
}

void SphereUI::HyperTextEditControl::copyEditorState(const HyperTextEditControl& source) {
    if (this == &source) return;
    OwnedHyperTextElements copy;
    for (std::uint32_t index = 0u; index < source.elements.count; ++index) if (const auto* element = source.elements.at(index)) copy.copy(*element);
    history.copyFrom(source.history);
    edit_modes.copyFrom(source.edit_modes);
    visible_text.assign(source.visible_text.data());
    hyper_text.assign(source.hyper_text.data());
    copy.take(elements);
    history_position = source.history_position;
    maximum_history = source.maximum_history;
    cursor_type = source.cursor_type;
    caret_position = source.caret_position;
    blink_started = source.blink_started;
    cursor_visible = source.cursor_visible;
    text_margins = source.text_margins;
    cursor_color = source.cursor_color;
    plain_color = source.plain_color;
    player_link_color = source.player_link_color;
    item_link_color = source.item_link_color;
    link_color = source.link_color;
    maximum_visible_length = source.maximum_visible_length;
    maximum_hyper_length = source.maximum_hyper_length;
    visible_first = source.visible_first;
    visible_last = source.visible_last;
    saved_viewport = source.saved_viewport;
    parent_x = source.parent_x;
    parent_y = source.parent_y;
    std::copy_n(source.cursor_reserved, 3u, cursor_reserved);
}

SphereUI::Window* SphereUI::HyperTextEditControl::clone() {
    return cloneControl(*this, [](auto& target, const auto& source) {
        target.copyEditorState(source);
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
    reader.integer("maxVisibleTextLength", maximum_visible_length);
    reader.integer("maxHyperTextLength", maximum_hyper_length);
    reader.integer("maxHistoryLength", maximum_history);
    cursor_type = 1u;
    if (const char* value = reader.string("cursorType")) cursor_type = SferaSimpleParser::equalsIgnoreCase(value, "none") ? 0u : SferaSimpleParser::equalsIgnoreCase(value, "uline") ? 2u : 1u;
    edit_modes.clear();
    if (reader.has("editMode")) for (std::uint32_t index = 0u; index < parser.tokenCount(); ++index) {
        const char* value = reader.token(index);
        if (SferaSimpleParser::equalsIgnoreCase(value, "enterPlainText")) edit_modes.insert(0u);
        else if (SferaSimpleParser::equalsIgnoreCase(value, "numbersOnly")) {
            edit_modes.insert(0u);
            edit_modes.insert(1u);
        } else if (SferaSimpleParser::equalsIgnoreCase(value, "password")) {
            edit_modes.insert(0u);
            edit_modes.insert(2u);
        }
    }
    if (edit_modes.count == 0u) edit_modes.insert(0u);
    text_margins = {};
    reader.rectangle("titleTextMargin", text_margins.left, text_margins.top, text_margins.right, text_margins.bottom);
    loadHistory();
    updateVisibleEnd();
    return true;
}

std::uint32_t SphereUI::HyperTextEditControl::handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) {
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
            if (first != 0u) *reinterpret_cast<std::uint32_t*>(first) = visible_text.length;
            if (second != 0u) *reinterpret_cast<std::uint32_t*>(second) = hyper_text.length;
            return 1u;
        case UiMessage::setHyperEditTextColor:
            plain_color = first;
            return 1u;
        default:
            return Window::handleMessage(message, first, second);
    }
}

void SphereUI::HyperTextEditControl::handleInput(const WindowInput& input) {
    if (hidden != 0u) return;
    if (input_enabled != 0u) {
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
    if (input_enabled == 0u) setInputFocus(true);
    if (visible_text.length == 0u) return;
    const auto start = std::min(visible_first, visible_text.length);
    const auto end = std::min(visible_last + 1u, visible_text.length);
    const std::string visible(visible_text.data() + start, end > start ? end - start : 0u);
    caret_position = std::min(visible_text.length, start + fitText(visible.c_str(), font, cursor.x - bounds.left - text_margins.left, false));
    if ((input.key_modifiers & 1u) == 0u) return;
    std::uint32_t position = 0u;
    for (std::uint32_t index = 0u; index < elements.count; ++index) if (auto* element = elements.at(index)) {
        if (caret_position >= position && caret_position < position + element->text.length && element->type == 5u) {
            if (auto* description = Runtime::descriptionWindow()) description->showDescription(static_cast<HyperTextElement_Link*>(element)->linkValue(), 0u, 250u, false);
            break;
        }
        position += element->text.length;
    }
}

void SphereUI::HyperTextEditControl::destroy(bool free_storage) {
    if (is_reference == 1u) saveHistory();
    HyperTextParser::releaseElements(elements);
    visible_text.release();
    hyper_text.release();
    history.release();
    edit_modes.release();
    Runtime::setTextInputActive(false);
    Window::destroy(free_storage);
}

void SphereUI::ButtonCtrl::initialize() {
    Window::initialize();
    idle_image = pressed_image = hover_image = disabled_image = nullptr;
    visual_state = button_flags = hotkey = repeat_time_low = repeat_time_high = 0u;
    pressed = 0u;
    std::fill_n(pressed_reserved, 3u, std::uint8_t{});
    repeat_interval = 0.05f;
    hover_color = UiColor::white;
    hidden = 0u;
    control_kind = UiControlKind::button;
    input_mask = TextAlignment::center;
}

void SphereUI::CheckBox::initialize() {
    Window::initialize();
    unchecked_image = unchecked_hover_image = checked_image = checked_hover_image = nullptr;
    button_flags = 0u;
    checked = hovered = 0u;
    check_reserved = 0u;
    image_x = image_y = label_x = label_y = 0;
    hover_color = UiColor::white;
    hidden = 0u;
    control_kind = UiControlKind::checkBox;
}

void SphereUI::RadioButtonCtrl::initialize() {
    CheckBox::initialize();
    control_kind = UiControlKind::radioButton;
}

void SphereUI::TextCtrl::initialize() {
    Window::initialize();
    text_style = 0u;
    hidden = 0u;
    control_kind = UiControlKind::text;
}

void SphereUI::ImageCtrl::initialize() {
    Window::initialize();
    fallback_image = nullptr;
    image_style = 0u;
    interaction_active = rotated = 0u;
    rotation_radians = 0.0f;
    base_alpha = 255u;
    opacity = 1.0f;
    hidden = 0u;
    control_kind = UiControlKind::image;
}

void SphereUI::ProgressBar::initialize() {
    Window::initialize();
    initializeProgressState();
    hidden = 0u;
    control_kind = UiControlKind::progressBar;
}

void SphereUI::CMinimapControl::initialize() {
    Window::initialize();
    resource_reference = nullptr;
    hidden = 0u;
    control_kind = UiControlKind::minimap;
}

SphereUI::Window* SphereUI::Runtime::makeControl(std::uint32_t kind) {
    switch (kind) {
        case UiControlKind::window:
            return createInitialized<Window>();
        case UiControlKind::button:
            return createInitialized<ButtonCtrl>();
        case UiControlKind::text:
            return createInitialized<TextCtrl>();
        case UiControlKind::image:
            return createInitialized<ImageCtrl>();
        case UiControlKind::progressBar:
            return createInitialized<ProgressBar>();
        case UiControlKind::scrollBar:
            return createInitialized<ScrollBar>();
        case UiControlKind::hyperText:
            return createInitialized<HyperTextCtrl>();
        case UiControlKind::checkBox:
            return createInitialized<CheckBox>();
        case UiControlKind::radioButton:
            return createInitialized<RadioButtonCtrl>();
        case UiControlKind::tooltip:
            return createInitialized<ToolTipCtrl>();
        case UiControlKind::textList:
            return createInitialized<ListCtrl>();
        case UiControlKind::slider:
            return createInitialized<SliderCtrl>();
        case UiControlKind::listItem:
            return createInitialized<ListItemCtrl>();
        case UiControlKind::edit:
            return createInitialized<EditCtrl>();
        case UiControlKind::slot:
            return createInitialized<SlotCtrl>();
        case UiControlKind::miniHelp:
            return createInitialized<MiniHelpCtrl>();
        case UiControlKind::spinButton:
            return createInitialized<SpinButton>();
        case UiControlKind::richEdit:
            return createInitialized<RichEditCtrl>();
        case UiControlKind::filteredList:
            return createInitialized<FilterListCtrl>();
        case UiControlKind::webBrowser:
            return createInitialized<CWebBrowserControl>();
        case UiControlKind::minimap:
            return createInitialized<CMinimapControl>();
        case UiControlKind::menu:
            return createInitialized<CMenuListControl>();
        case UiControlKind::hyperTextChat:
            return createInitialized<HyperTextChatListControl>();
        case UiControlKind::hyperTextEdit:
            return createInitialized<HyperTextEditControl>();
        case UiControlKind::fontPicker:
            return createInitialized<FontPicker>();
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
    if ((alignment_flags & 8u) != 0u) x = detail::addCoordinate(x, static_cast<std::int32_t>(horizontal));
    if ((alignment_flags & 64u) != 0u) y = detail::addCoordinate(y, static_cast<std::int32_t>(vertical));
    if ((alignment_flags & 4u) != 0u) x = detail::addCoordinate(x, static_cast<std::int32_t>(horizontal >> 1u));
    if ((alignment_flags & 32u) != 0u) y = detail::addCoordinate(y, static_cast<std::int32_t>(vertical >> 1u));
}

void SphereUI::Window::applyAnimation(const WindowAnimation& effect, float fraction) {
    if (effect.kind == 1u || effect.kind == 2u) {
        setOpacity(effect.kind == 1u ? fraction : 1.0f - fraction);
        return;
    }
    if (effect.kind < 3u || effect.kind > 6u) return;
    const double distance = static_cast<double>(effect.distance) * fraction;
    const double value = effect.origin + ((effect.kind == 3u || effect.kind == 5u) ? -distance : distance);
    const auto coordinate = !std::isfinite(value) || value < -2147483648.0 || value >= 2147483648.0 ? std::numeric_limits<std::int32_t>::min() : static_cast<std::int32_t>(std::trunc(value));
    if (effect.kind <= 4u) setPosition(coordinate, y);
    else setPosition(x, coordinate);
}

void SphereUI::Window::startAnimation(std::uint32_t phase) {
    if (auto* previous = active_animation; animation_active == 1u && previous != nullptr) applyAnimation(*previous, 1.0f);
    if (phase == 0u || phase > 3u) {
        active_animation = nullptr;
        animation_active = 0u;
        return;
    }
    if (phase == 1u) setOpacity(1.0f);
    auto& effect = phase == 1u ? show_animation : hide_animation;
    if (effect.kind == 0u) {
        active_animation = nullptr;
        animation_active = 0u;
        return;
    }
    animation_active = 1u;
    active_animation = &effect;
    if (effect.kind >= 3u && effect.kind <= 6u) effect.origin = static_cast<float>(static_cast<double>(effect.kind <= 4u ? x : y) - ((effect.kind == 4u || effect.kind == 6u) ? effect.distance : 0.0f) + effect.offset);
    const auto now = Runtime::clockTicks();
    effect.start_time_low = static_cast<std::uint32_t>(now);
    effect.start_time_high = static_cast<std::uint32_t>(now >> 32u);
    effect.phase = phase;
    Runtime::playWindowSound(phase == 1u);
    updateAnimation();
}

void SphereUI::Window::updateAnimation() {
    auto* effect = active_animation;
    if (effect == nullptr) return;
    const auto started = (static_cast<std::uint64_t>(effect->start_time_high) << 32u) | effect->start_time_low;
    const auto elapsed = static_cast<float>(static_cast<double>(std::bit_cast<std::int64_t>(Runtime::clockTicks() - started)) / 10000.0);
    float fraction = elapsed / effect->duration;
    if (!std::isfinite(fraction) || fraction < 0.0f || fraction > 1.0f) fraction = 1.0f;
    applyAnimation(*effect, fraction);
    if (fraction == 1.0f) {
        if (effect->phase == 3u) animation_state = 1u;
        startAnimation(0u);
    }
}

void SphereUI::Window::beginClose(bool animated) {
    if (!animated) {
        hidden = animation_state = 1u;
        input_enabled = 0u;
        return;
    }
    startAnimation(3u);
    if (animation_active == 0u) animation_state = 1u;
    input_enabled = 0u;
}

void SphereUI::Window::animateVisibility(bool hide) {
    if (hide) {
        startAnimation(2u);
        hide_after_animation = animation_active != 0u;
        if (animation_active == 0u) handleMessage(UiMessage::setHidden, 1u, 0u);
    } else {
        hide_after_animation = 0u;
        handleMessage(UiMessage::setHidden, 0u, 0u);
        startAnimation(1u);
    }
}

SphereUI::Window* SphereUI::Window::controlAt(std::uint32_t index) const {
    if (index == 0u) return const_cast<Window*>(this);
    if (child_sentinel == nullptr) return nullptr;
    for (auto* node = child_sentinel->next; node != child_sentinel; node = node->next) if (--index == 0u) return node->value;
    return nullptr;
}

void SphereUI::Window::addModalReference(Window& window) {
    detail::appendNode(reference_sentinel, reference_count, &window);
}
