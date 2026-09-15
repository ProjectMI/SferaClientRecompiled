#pragma once
#include <cstddef>
#include <cstdint>
#include <array>

struct SferaColor {
    std::array<std::uint8_t, 4> channels;
    static constexpr SferaColor rgba(std::uint32_t red, std::uint32_t green, std::uint32_t blue, std::uint32_t alpha = 255u) { return {{static_cast<std::uint8_t>(red), static_cast<std::uint8_t>(green), static_cast<std::uint8_t>(blue), static_cast<std::uint8_t>(alpha)}}; }
    static constexpr SferaColor fromArgb(std::uint32_t value) { return rgba(value >> 16u, value >> 8u, value, value >> 24u); }
    constexpr std::uint8_t red() const { return channels[0]; }
    constexpr std::uint8_t green() const { return channels[1]; }
    constexpr std::uint8_t blue() const { return channels[2]; }
    constexpr std::uint8_t alpha() const { return channels[3]; }
    constexpr std::uint32_t argb() const { return (std::uint32_t(alpha()) << 24u) | (std::uint32_t(red()) << 16u) | (std::uint32_t(green()) << 8u) | blue(); }
    constexpr SferaColor withAlpha(std::uint32_t value) const { return rgba(red(), green(), blue(), value); }
    constexpr SferaColor scaledAlpha(std::uint32_t factor, std::uint32_t divisor = 255u) const { return withAlpha(std::uint32_t(alpha()) * factor / divisor); }
    constexpr SferaColor scaledRgb(std::uint32_t factor, std::uint32_t divisor) const { return rgba(std::uint32_t(red()) * factor / divisor, std::uint32_t(green()) * factor / divisor, std::uint32_t(blue()) * factor / divisor, alpha()); }
    constexpr std::uint16_t rgb565() const { return static_cast<std::uint16_t>(((red() >> 3u) << 11u) | ((green() >> 2u) << 5u) | (blue() >> 3u)); }
    static constexpr SferaColor fromArgb4444(std::uint16_t value) { return rgba(((value >> 8u) & 15u) * 17u, ((value >> 4u) & 15u) * 17u, (value & 15u) * 17u, (value >> 12u) * 17u); }
    constexpr std::uint16_t argb4444() const { return static_cast<std::uint16_t>(((alpha() >> 4u) << 12u) | ((red() >> 4u) << 8u) | ((green() >> 4u) << 4u) | (blue() >> 4u)); }
};

class SferaSimpleParser;
struct SferaParserRange;
struct SferaCursorPosition;
namespace SphereUI {
    enum class UiMessage : std::uint32_t;
    enum class UiControlKind;
    enum WindowAlignment : std::uint32_t { alignLeft = 1u << 1, alignCenterX = 1u << 2, alignRight = 1u << 3, alignTop = 1u << 4, alignCenterY = 1u << 5, alignBottom = 1u << 6 };
    struct UiString {
        char storage[16];
        std::size_t length;
        std::size_t capacity;
        const char* data() const;
        void assign(const char* text);
        void release();
    };
}

struct HyperTextGeometry {
    int x;
    int y;
    int width;
    int height;
};

class HyperTextElement {
public:
    std::uint32_t type = 0;
    SphereUI::UiString text{};
    HyperTextGeometry* geometry();
    const HyperTextGeometry* geometry() const;
    HyperTextElement* clone() const;
    void initializeText(std::uint32_t kind, const char* value);
    void release();
    HyperTextElement() {
    }

    virtual std::uint32_t elementType() const;
};

class HyperTextElement_WordWrap : public HyperTextElement {
public:
    HyperTextElement_WordWrap() {
    }
};

class HyperTextElementWithParameters : public HyperTextElement {
public:
    HyperTextGeometry bounds{};
    SphereUI::UiString parameters{};
    HyperTextElementWithParameters() {
    }
};

class HyperTextElement_PlainText : public HyperTextElement {
public:
    HyperTextGeometry bounds{};
    HyperTextElement_PlainText() {
    }
};

class HyperTextElement_Link : public HyperTextElementWithParameters {
public:
    SphereUI::UiString target{};
    std::uint32_t link_kind = 0;
    const char* linkValue() const;
    HyperTextElement_Link() {
    }
};

namespace SphereUI {
    enum class WindowEventHandler : std::uint8_t {
        none,
        description,
        help,
        authors,
        quit,
        sound_options,
        control_options,
        interface_options,
        graphics_options,
        options,
        font_options
    };

    class Window;
    class ScrollBar;
    class SpinButton;
    class ButtonCtrl;
    struct BrowserSurface;
    struct BrowserSession;
    struct UiContainerProxy;
    struct WindowInput {
        int mouse_x;
        int mouse_y;
        int wheel_delta;
        std::uint32_t mouse_flags;
        std::uint32_t mouse_buttons;
        mutable std::uint8_t key_code; // Delivery consumes handled virtual keys without changing the event coordinates.
        mutable std::uint8_t character;

        std::uint32_t key_modifiers;
    };

    struct WindowEvent {
        Window* source;
        std::uint32_t control_id;
        UiMessage message;
        std::uint32_t first;
        std::uint32_t second;

    };

    struct WindowAnimation {
        enum class Kind { None, FadeIn, FadeOut, MoveLeft, MoveRight, MoveUp, MoveDown };
        enum class Phase { Idle, Showing, Hiding, Closing };
        Kind kind;

        std::uint64_t start_time;
        float duration;
        float distance;
        float offset;
        float origin;
        Phase phase;

    };
    struct UiRect {
        int left;
        int top;
        int right;
        int bottom;
    };

    struct UiViewport {
        std::uint32_t x;
        std::uint32_t y;
        std::uint32_t width;
        std::uint32_t height;
        float minimum_z;
        float maximum_z;
    };

    struct TextExtent {
        int width;
        int height;
    };

    struct SpriteVertex {
        float x;
        float y;
        float z;
        float rhw;
        std::uint32_t color;
        std::uint32_t specular;
        float u;
        float v;
    };

    struct SpritePart {
        char* texture_name;
        int texture;
        float u[4];
        float v[4];
        UiRect rectangle;
        void setTexture(const char* texture_name, const UiRect* texture_rectangle, const UiRect* sprite_rectangle);
    };

    struct UiSprite {
        char* name;
        int width;
        int height;
        SpriteVertex vertices[4];
        std::size_t reference_count;
        SpritePart* parts;
        std::size_t part_count;
        void initialize();
        void drawNatural(float left, float top, std::uint32_t color);
        void draw(float left, float top, float right, float bottom, std::uint32_t color, float rotation = 0.0f);
        void copyFrom(const UiSprite& source);
        static UiSprite* create();
        UiSprite* clone() const;
        void destroy();
        void release();
        void setImage(const char* name);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range);
        void resizeParts(std::size_t count);
        void setColors(std::uint32_t color);
        void releaseReference();
        void setDescription(const struct ImageDescription& description);
    private:
        void drawParts(float left, float top, float right, float bottom, bool natural);
        void drawRotated(float left, float top, float right, float bottom, float rotation);
        void setQuad(const SpritePart& part, float left, float top, float right, float bottom);
    };

    template<class T> struct UiVector {
        T* begin;
        T* end;
        T* capacity;
        std::size_t size() const;
        T& at(std::size_t index);
        const T& at(std::size_t index) const;
        void reserve(std::size_t count);
        void append(const T& value);
        void erase(std::size_t index);
        void clear();
        void release();
        void copyFrom(const UiVector& source);
    };

    using UiIndexVector = UiVector<std::uint32_t>;
    struct UiMenuItem {
        UiString text;
        bool enabled;

    };

    template<class T> struct UiStringRecords {
        T* begin;
        T* end;
        T* capacity;
        std::size_t size() const;
        T& at(std::size_t index);
        const T& at(std::size_t index) const;
        void append(const T& value);
        void clear();
        void release();
        void copyFrom(const UiStringRecords& source);
    };

    template<class T> struct UiArray {
        void append(const T& value);
        void clear() {
            end = begin;
        }

        void release();
        void copyFrom(const UiArray& source);
        T* begin;
        T* end;
        T* capacity;
        std::size_t size() const {
            return begin == nullptr ? 0u : static_cast<std::size_t>(end - begin);
        }

        T& at(std::size_t index) {
            return begin[index];
        }

        const T& at(std::size_t index) const {
            return begin[index];
        }
    };

    struct UiContainerProxy {
        void* owner;
        void* first_iterator;
    };

    template<class T> struct UiDeque {
        UiContainerProxy* proxy;
        T** map;
        std::size_t map_size;
        std::size_t offset;
        std::size_t count;
        void initialize();
        T& at(std::size_t index);
        const T& at(std::size_t index) const;
        void pushBack(const T& value);
        void popBack();
        void popFront();
        void clear();
        void release();
        void copyFrom(const UiDeque& source);
    };

    struct UiIntegerSetNode {
        UiIntegerSetNode* left;
        UiIntegerSetNode* parent;
        UiIntegerSetNode* right;
        std::uint32_t value;
        bool black;
        bool is_nil;

    };

    struct UiIntegerSet {
        UiContainerProxy* proxy;
        UiIntegerSetNode* sentinel;
        std::size_t count;
        void initialize();
        bool contains(std::uint32_t value) const;
        void insert(std::uint32_t value);
        void clear();
        void release();
        void copyFrom(const UiIntegerSet& source);
    };

    struct UiStringDeque : UiDeque<UiString> {
        void append(const char* text);
    };

    struct UiStringVector {
        UiString* begin;
        UiString* end;
        UiString* capacity;
        std::size_t size() const;
        UiString& at(std::size_t index);
        const UiString& at(std::size_t index) const;
        void append(const char* text);
        void insert(std::size_t index, const char* text);
        void erase(std::size_t index);
        void clear();
        void release();
        void copyFrom(const UiStringVector& source);
    };

    struct UiTextRow {
        UiString text;
        std::uint32_t color;
        int offset;
    };

    struct UiTextRows {
        UiTextRow* begin;
        UiTextRow* end;
        UiTextRow* capacity;
        std::size_t size() const;
        UiTextRow& at(std::size_t index);
        const UiTextRow& at(std::size_t index) const;
        void append(const char* text, std::uint32_t color, int offset);
        void erase(std::size_t index);
        void clear();
        void release();
        void copyFrom(const UiTextRows& source);
    };

    template<class T> struct UiListNode {
        UiListNode* next;
        UiListNode* previous;
        T value;
    };

    using SferaWindowChildNode = UiListNode<Window*>;
    using UiResourceNode = UiListNode<UiSprite*>;
    struct WindowResourceList {
        UiResourceNode* sentinel;
        std::size_t count;

    };

    class Window {
    public:
        char name[16];
        std::size_t name_length;
        std::size_t name_capacity;
        std::uint32_t behavior_flags;
        int width;
        int height;
        int x;
        int y;
        std::uint32_t alignment_flags;
        int group;
        int initial_x;
        int initial_y;
        bool hidden;
        bool disabled;
        bool input_enabled;
        bool is_reference;
        bool can_drag_drop;
        bool can_go_top;
        bool save_last_position;
        bool hit_transparent;
        UiControlKind control_kind;
        char text[16];
        std::size_t text_length;
        std::size_t text_capacity;
        char help[16];
        std::size_t help_length;
        std::size_t help_capacity;
        int font;
        bool font_initialized;
        std::uint16_t font_attributes;
        std::uint32_t text_color;
        std::uint32_t text_state;
        std::uint32_t disabled_color;
        Window* parent;
        SferaWindowChildNode* child_sentinel;
        std::size_t child_count;
        SferaWindowChildNode* reference_sentinel;
        std::size_t reference_count;
        Window* modal_owner;
        UiContainerProxy* event_proxy;
        WindowEvent** event_slots;
        std::size_t event_capacity;
        std::size_t event_head;
        std::size_t event_size;
        std::size_t pending_event_count;
        std::uint32_t control_id;
        std::uint32_t alpha;
        bool animation_active;
        bool close_completed;

        int text_offset_x;
        int text_offset_y;
        Window* tooltip;
        Window* overlay;
        Window* resource_parent;
        std::uint32_t event_handler_token;
        int caption_left;
        int caption_top;
        int caption_right;
        int caption_bottom;
        bool dragging;

        int drag_offset_x;
        int drag_offset_y;
        std::uint32_t input_mask;
        bool hide_after_animation;

        WindowAnimation show_animation;
        WindowAnimation hide_animation;
        WindowAnimation* active_animation;
        WindowResourceList* resource_list;
        char resource_name[16];
        std::size_t resource_name_length;
        std::size_t resource_name_capacity;
        UiSprite* resource_reference;
        Window() {
        }

        void initialize();
        void initializeCopy(const Window& source);
        void resetToolTips();
        void alignToScreen(bool reset_position);
        void applyAnimation(const WindowAnimation& effect, float fraction);
        void updateAnimation();
        void startAnimation(SphereUI::WindowAnimation::Phase phase);
        void beginClose(bool animated);
        void animateVisibility(bool hide);
        void drawToolTips();
        Window& copyStateFrom(const Window& source);
        Window& copyStateFrom(const Window& source, bool copy_children);
        void release();
        Window* createControl(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range, SphereUI::UiControlKind kind, std::uint32_t id);
        void appendChild(Window* child);
        void appendResource(UiSprite* resource);
        UiSprite* findResource(const char* resource_name) const;
        UiSprite* getResource(const char* resource_name);
        void setParent(Window* new_parent);
        void setInputFocus(bool focused, bool submit_on_blur = false);
        void getAbsolutePosition(int& screen_x, int& screen_y) const;
        bool containsPoint(int screen_x, int screen_y) const;
        int childControlAt(int screen_x, int screen_y) const;
        void clearEvents();
        void queueEvent(const WindowEvent& event);
        bool pollEvent(WindowEvent& event);
        void processEvents();
        void setText(const char* value);
        const char* getText() const;
        const char* getHelp() const;
        void setHelp(const char* value);
        void setName(const char* value);
        Window* controlAt(std::size_t index) const;
        void addModalReference(Window& window);
        const char* getName() const;
        const char* getResourceName() const;
        void setResourceName(const char* value);
        virtual bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range);
        virtual Window* clone();
        virtual std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second);
        virtual void setPosition(int x, int y);
        virtual void draw();
        virtual void handleInput(const WindowInput& input);
        virtual void setOpacity(float opacity);
        virtual bool hitTest(int screen_x, int screen_y);
        virtual void dispatchMessage(int target_group, SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second, SphereUI::UiControlKind target_kind);
        virtual void setFont(int font_id);
        virtual int getFont() const;
        virtual void destroy(bool free_storage);
    };

    class ButtonCtrl : public Window {
    public:
        std::uint32_t visual_state;
        UiSprite* idle_image;
        UiSprite* pressed_image;
        UiSprite* hover_image;
        std::uint32_t button_flags;
        std::uint32_t hotkey;
        std::uint64_t repeat_started_at;
        bool pressed;

        float repeat_interval;
        std::uint32_t hover_color;
        UiSprite* disabled_image;
        void initialize();
        void copyButtonState(const ButtonCtrl& source);
        ButtonCtrl() {
        }

        void click();
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    class CheckBox : public Window {
    public:
        UiSprite* unchecked_image;
        UiSprite* unchecked_hover_image;
        UiSprite* checked_image;
        UiSprite* checked_hover_image;
        bool checked;
        bool hovered;

        int image_x;
        int image_y;
        std::uint32_t button_flags;
        int label_x;
        int label_y;
        std::uint32_t hover_color;
        void initialize();
        void copyCheckState(const CheckBox& source);
        CheckBox() {
        }

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        virtual void playClickSound();
    };

    class CDescriptionWindow : public Window {
    public:

        const Window* displayed_source;
        const Window* pending_source;
        std::uint32_t show_deadline;
        std::uint32_t hide_deadline;
        UiSprite* caption_sprite;
        UiSprite* bottom_sprite;
        UiSprite* left_sprite;
        UiSprite* right_sprite;
        int frame_height;
        bool pinned;
        CDescriptionWindow() {
        }

        void initialize();
        static CDescriptionWindow* instance();
        void close();
        void update();
        void handleEvent(const WindowEvent& event);
        SferaCursorPosition* calculatePosition(SferaCursorPosition* output) const;
        void showDescription(const char* text, const Window* source, std::uint32_t duration, bool pin);
        void requestDescription(const char* text, bool force, const Window* source);
        void draw() override;
        void destroy(bool free_storage) override;
    };

    class EditCtrl : public Window {
    public:
        int cursor_x;
        int cursor_y;
        int cursor_offset_x;
        int cursor_offset_y;
        bool numeric;
        bool password;

        std::size_t maximum_symbols;
        int cursor_width;
        UiString password_text;
        std::uint32_t cursor_color;
        std::uint32_t cursor_alignment;
        std::uint64_t blink_started;
        bool cursor_visible;
        bool cursor_uses_text_color;
        bool submit_on_blur;

        int caret_position;
        std::size_t observed_length;
        std::size_t history_count;
        std::size_t history_position;
        char history[100][256];
        void initialize();
        void copyEditState(const EditCtrl& source);
        void updatePassword();
        void rememberText();
        void loadHistory();
        void saveHistory() const;
        EditCtrl() {
        }

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    class ListCtrl : public Window {
    public:
        int visible_begin;
        int visible_end;
        UiTextRows rows;
        std::size_t maximum_items;
        std::size_t write_index;
        int maximum_scroll;
        int line_height;
        int visible_capacity;
        int vertical_offset;
        int cropped_y;
        bool chatlike;
        bool format_strings;
        bool continue_mark;

        ScrollBar* scrollbar;
        bool can_select;

        int selected_index;
        int selection_border;
        std::uint32_t selection_color;
        std::uint32_t selection_line_color;
        std::uint64_t click_time;
        bool click_pending;

        ListCtrl() {
        }

        void initialize();
        void copyListState(const ListCtrl& source);
        void updateLayout();
        void updateVisibleRange();
        std::size_t physicalIndex(std::size_t logical_index) const;
        void appendLine(const char* text, std::uint32_t color);
        void appendFormattedLine(const char* text, std::uint32_t color);
        void addText(const char* text, std::uint32_t color);
        void clearRows();
        void removeRow(std::size_t logical_index);
        void selectRow(int index);
        void alignRow(std::size_t index, std::uint32_t flags);
        void drawSelection(int x, int y, int row_y, bool restore_viewport);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    class FilterListCtrl : public ListCtrl {
    public:
        std::uint32_t filter_mask;
        UiTextRows history;
        std::size_t history_write;
        FilterListCtrl() {
        }

        void initialize();
        void clearHistory();
        void appendHistory(const char* text, std::uint32_t color, std::uint32_t mask);
        void applyFilter(std::uint32_t mask);
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void destroy(bool free_storage) override;
    };

    class FontPicker : public Window {
    public:
        SpinButton* selector;
        Window* preview;
        FontPicker() {
        }

        void initialize();
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setFont(int font_id) override;
        int getFont() const override;
        void destroy(bool free_storage) override;
    };

    class HyperTextDocument;

    struct UiIndexRange {
        std::size_t first;
        std::size_t last;
    };

    struct HyperTextChatListItem {
        UiString hyper_text;
        UiString plain_text;
        std::uint32_t channel;
        std::uint32_t color;
        UiDeque<HyperTextElement*> elements;
        UiArray<UiIndexRange> rows;
        void initialize(const char* text, std::uint32_t channel, std::uint32_t color);
        void release();
        void copyFrom(const HyperTextChatListItem& source);
        void layout(int width, int font);
    };

    class HyperTextChatListControl : public Window {
    public:
        UiDeque<HyperTextChatListItem> messages;
        UiVector<std::size_t> visible_messages;
        UiIndexVector channels;
        UiString selected_link_text;
        UiString selected_link_value;
        UiString selected_plain_text;
        UiString selected_hyper_text;
        std::uint32_t player_link_color;
        std::uint32_t item_link_color;
        std::uint32_t link_color;
        std::size_t maximum_items;
        std::uint32_t row_height;
        std::size_t page_rows;
        int parent_x;
        int parent_y;
        std::size_t bottom_message;
        std::size_t bottom_row;
        std::size_t scroll_offset;
        ScrollBar* scrollbar;
        UiViewport saved_viewport;
        UiArray<UiIndexRange> rendered_rows;
        void initialize();
        void copyChatState(const HyperTextChatListControl& source);
        void addMessage(const char* text, std::uint32_t channel, std::uint32_t color);
        void addChannel(std::uint32_t channel);
        void setChannels(const std::uint32_t* values, std::size_t count);
        void clearChannels();
        void rebuildVisible();
        void updateParentPosition();
        bool visibleRowRange(std::size_t message, std::size_t drawn, std::size_t rows, std::size_t* first, std::size_t* last) const;
        void updateScroll(bool reset);
        void readScroll();
        const char* messageText(std::size_t index, bool plain) const;
        void drawElement(HyperTextElement& element, int x, int y, std::uint32_t color);
        HyperTextChatListControl() {
        }

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setFont(int font_id) override;
        void destroy(bool free_storage) override;
    };

    class HyperTextCtrl : public Window {
    public:
        HyperTextDocument* document;
        std::uint32_t text_format;
        char pending_name[256];
        bool remember_page;

        int maximum_scroll;
        int scroll_position;
        int first_line_offset;
        int clip_offset;
        int clip_height;
        int previous_line_offset;
        int previous_clip_offset;
        int previous_clip_height;
        HyperTextDocument* previous_document;
        float transition_fraction;
        bool transition_active;

        std::uint64_t transition_started;
        ScrollBar* scrollbar;
        UiStringDeque history;
        std::uint32_t link_color;
        std::uint32_t hover_color;
        int tooltip_index;
        const char* pending_buffer;
        std::size_t pending_bytes;
        bool discard_old_text;

        HyperTextCtrl() {
        }

        void initialize();
        void copyHyperTextState(const HyperTextCtrl& source);
        void queuePage(const char* name, bool remember);
        void queueBuffer(const char* buffer, std::size_t size);
        void updateDocument(bool resize_to_content);
        void updateScroll();
        void openLink(const char* target);
        static std::uint32_t parseTextFormat(const char* name);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    class HyperTextEditControl : public Window {
    public:
        UiStringDeque history;
        std::size_t history_position;
        std::size_t maximum_history;
        UiIntegerSet edit_modes;
        UiString visible_text;
        UiString hyper_text;
        UiDeque<HyperTextElement*> elements;
        std::uint32_t cursor_type;
        std::size_t caret_position;
        std::uint32_t blink_started;
        bool cursor_visible;

        UiRect text_margins;
        std::uint32_t cursor_color;
        std::uint32_t plain_color;
        std::uint32_t player_link_color;
        std::uint32_t item_link_color;
        std::uint32_t link_color;
        std::size_t maximum_visible_length;
        std::size_t maximum_hyper_length;
        std::size_t visible_first;
        std::size_t visible_last;
        UiViewport saved_viewport;
        int parent_x;
        int parent_y;
        void initialize();
        void copyEditorState(const HyperTextEditControl& source);
        void setContent(const char* text, std::uint32_t mode = 0u);
        void insertPlainText(const char* text);
        void insertCharacter(std::uint8_t character);
        void eraseCharacter(bool backspace);
        void moveCaret(std::uint32_t key);
        void updateVisibleStart();
        void updateVisibleEnd();
        void drawCaret();
        void drawElement(const TextExtent& point, HyperTextElement& element, std::uint32_t color, const UiIndexRange& range);
        void historyUp();
        void historyDown();
        void submitText();
        void pasteClipboard();
        void loadHistory();
        void saveHistory() const;
        static void historyProfile(UiString& result);
        static void transformHistory(UiString& result, const UiString& source, bool decode);
        static std::size_t fitText(const char* text, int font, int pixels, bool reverse);
        HyperTextEditControl() {
        }

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    class ImageCtrl : public Window {
    public:
        std::uint32_t image_style;
        bool interaction_active;
        UiSprite* fallback_image;
        bool rotated;
        float rotation_radians;
        std::uint32_t base_alpha;
        float opacity;
        void initialize();
        void copyImageState(const ImageCtrl& source);
        ImageCtrl() {
        }

        void setImage(const struct ImageDescription* description);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setOpacity(float opacity) override;
        void destroy(bool free_storage) override;
    };

    class ListItemCtrl : public Window {
    public:
        Window* item_template;
        UiVector<Window*> items;
        int horizontal_offset;
        int vertical_offset;
        int visible_begin;
        int visible_end;
        int visible_capacity;
        int cropped_x;
        int cropped_y;
        int maximum_y;
        int maximum_x;
        ScrollBar* vertical_scroll;
        ScrollBar* horizontal_scroll;
        bool layout_dirty;
        bool can_select;

        UiSprite* selection_sprite;
        int selected_index;
        bool horizontal;
        bool user_move;

        ListItemCtrl() {
        }

        void initialize();
        Window* itemAt(std::size_t index) const;
        int addItem();
        void removeItem(std::size_t index);
        void clearItems();
        void updateLayout();
        void updateVisibleRange();
        void copyItemState(const ListItemCtrl& source);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setOpacity(float opacity) override;
        bool hitTest(int screen_x, int screen_y) override;
        void dispatchMessage(int target_group, SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second, SphereUI::UiControlKind target_kind) override;
        void destroy(bool free_storage) override;
    };

    class CMenuListControl : public Window {
    public:
        std::size_t maximum_items;
        UiSprite* top_sprite;
        UiSprite* middle_sprite;
        UiSprite* hovered_sprite;
        UiSprite* bottom_sprite;
        std::uint32_t title_color;
        std::uint32_t normal_color;
        std::uint32_t hovered_color;
        std::uint32_t item_disabled_color;
        bool show_title;

        UiRect title_margin;
        std::uint32_t title_format;
        UiRect item_margin;
        std::uint32_t item_format;
        TextExtent top_size;
        TextExtent item_size;
        TextExtent bottom_size;
        int parent_screen_x;
        int parent_screen_y;
        int parent_width;
        int parent_height;
        UiStringRecords<UiMenuItem> items;
        std::size_t hovered_index;
        UiViewport saved_viewport;
        CMenuListControl() {
        }

        void initialize();
        void copyMenuState(const CMenuListControl& source);
        void addItem(const char* text, bool enabled);
        void clearItems();
        void closeMenu();
        void updateParentPosition();
        void keepOnScreen();
        std::size_t itemAtPoint(int x, int y) const;
        void drawHeader();
        void drawItem(std::size_t index, UiSprite* sprite, std::uint32_t color);
        void drawFooter();
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    class ToolTipCtrl : public Window {
    public:
        int screen_x;
        int screen_y;
        bool hover_pending;

        std::uint64_t hover_started;
        float fade_opacity;

        std::uint64_t fade_started;
        std::uint32_t background_color;
        int tooltip_width;
        int tooltip_height;
        bool dismissed;

        UiStringVector lines;
        int line_height;
        int margin_left;
        int margin_top;
        int margin_right;
        int margin_bottom;
        ToolTipCtrl() {
        }

        void initialize();
        void reset();
        void showAt(int x, int y);
        void updateFade();
        void updateLayout();
        void appendLine(const char* text);
        void setLine(std::uint32_t index, const char* text);
        void copyTipState(const ToolTipCtrl& source);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    class MiniHelpCtrl : public ToolTipCtrl {
    public:
        MiniHelpCtrl() {
        }

        void initialize();
        Window* clone() override;
        void handleInput(const WindowInput& input) override;
    };

    class CMinimapControl : public Window {
    public:
        void initialize();
        CMinimapControl() {
        }

        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void destroy(bool free_storage) override;
    };

    class ProgressBar : public Window {
    public:
        int minimum;
        int maximum;
        int current;
        float progress_ratio;
        std::uint32_t display_mode;
        char status_text[64];
        int status_x;
        int status_y;
        void initialize();
        ProgressBar() {
        }

        void initializeProgressState();
        void setProgressValue(int value);
        void setProgressRange(int new_minimum, int new_maximum);
        void copyProgressState(const ProgressBar& source);
        void refreshProgressDisplay();
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
    };

    class RadioButtonCtrl : public CheckBox {
    public:
        void initialize();
        RadioButtonCtrl() {
        }

        Window* clone() override;
        void playClickSound() override;
    };

    class RichEditCtrl : public Window {
    public:
        UiStringVector lines;
        int caret_row;
        int caret_column;
        std::uint64_t blink_started;
        bool cursor_visible;

        int cursor_width;
        int line_height;
        int page_rows;
        int first_row;
        ScrollBar* scrollbar;
        RichEditCtrl() {
        }

        void initialize();
        void copyRichState(const RichEditCtrl& source);
        void updateMetrics(int font_id);
        void updateScroll();
        void ensureCaretVisible();
        void moveCaret(std::uint32_t key);
        void setContent(const char* text);
        void copyContent(char* destination, std::uint32_t capacity) const;
        void insertCharacter(std::uint8_t character);
        void insertAt(std::uint32_t column, std::uint8_t character, std::uint32_t row);
        std::uint32_t mergeRows(std::uint32_t destination, std::uint32_t source);
        void eraseCharacter(bool backward);
        void splitLine();
        void drawCaret(float left, float top);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    struct ScrollParameters {
        std::uint32_t size;
        std::uint32_t mask;
        int minimum;
        int maximum;
        int page_step;
        int current;
        int step;
    };

    class ScrollBar : public Window {
    public:
        UiSprite* scroll_resource;
        int thumb_width;
        int thumb_height;
        int thumb_x;
        int thumb_y;
        std::uint32_t orientation_flags;
        ButtonCtrl* decrease_button;
        ButtonCtrl* increase_button;
        float normalized_position;
        int minimum;
        int maximum;
        int current;
        int step;
        int page_step;
        bool dragging_thumb;
        bool explicit_step;
        bool notify_changes;

        std::uint64_t repeat_started_at;
        int track_left;
        int track_top;
        int track_right;
        int track_bottom;
        bool page_click_active;

        ScrollBar() {
        }

        void initialize();
        void setParameters(const struct ScrollParameters& parameters);
        void getParameters(struct ScrollParameters& parameters) const;
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
        virtual void updateControlState();
        virtual void loadControlParameters();
    };

    class SliderCtrl : public ScrollBar {
    public:
        char value_text[64];
        std::uint32_t display_mode;
        int status_x;
        int status_y;
        SliderCtrl() {
        }

        void initialize();
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        void draw() override;
        void updateControlState() override;
        void loadControlParameters() override;
    };

    class SlotCtrl : public Window {
    public:
        UiSprite* full_sprite;
        UiSprite* empty_sprite;
        UiSprite* border_sprite;
        std::uint32_t fill_alpha;
        std::uint32_t fill_color;
        std::uint32_t border_color;
        int image_offset_x;
        int image_offset_y;
        UiSprite item_image;
        bool show_full_background;
        bool has_item;

        int press_x;
        int press_y;
        bool left_pressed;
        bool right_pressed;
        bool drag_started;

        UiString description;
        int count_offset_x;
        int count_offset_y;
        std::uint32_t item_count;
        UiSprite* top_left_overlay;
        UiSprite* bottom_right_overlay;
        UiSprite* bottom_left_overlay;
        SlotCtrl() {
        }

        void initialize();
        void copySlotState(const SlotCtrl& source);
        void setItem(const char* image);
        void setItemCount(std::uint32_t count);
        void setOverlay(UiSprite*& destination, const char* image);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        bool hitTest(int screen_x, int screen_y) override;
        void destroy(bool free_storage) override;
    };

    class SpinButton : public Window {
    public:
        ButtonCtrl* decrease_button;
        ButtonCtrl* increase_button;
        int minimum;
        int maximum;
        int current;
        int previous;
        int step;
        Window* body;
        std::uint32_t body_index;
        bool status_valid;
        bool notify_changes;
        bool update_enabled;
        SpinButton() {
        }

        void initialize();
        void setRange(int minimum, int maximum);
        void setCurrentValue(int value);
        void setStep(int step);
        int currentValue() const;
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
        virtual void updateStatus();
    };

    class TextCtrl : public Window {
    public:
        std::uint32_t text_style;
        void initialize();
        TextCtrl() {
        }

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
    };

    class CWebBrowserControl : public Window {
    public:
        UiString url;
        BrowserSurface* surface;
        BrowserSession* browser;
        bool mouse_pressed;

        CWebBrowserControl() {
        }

        void initialize();
        void copyBrowserState(const CWebBrowserControl& source);
        bool open(const char* address);
        bool navigate(const char* address);
        bool updateBrowser();
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };
}

// Native window entry points used by the remaining ABI adapters.
namespace SphereUI::detail {
    void serializeHyperTextElements(const UiDeque<HyperTextElement*>& elements, UiString& hyper_text, UiString& plain);
    void escapeHyperText(UiString& output, const UiString& source);
    SphereUI::UiControlKind controlKind(const char* name);
    SphereUI::WindowAnimation::Kind animationKind(const char* name);
    std::uint32_t alignmentFlag(const char* name);
}

namespace SphereUI::Runtime {
    void clipboardText(UiString& result);
    CDescriptionWindow* descriptionWindow();
    Window* makeControl(SphereUI::UiControlKind kind);
    void broadcastMessage(Window* root, int group, SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second, SphereUI::UiControlKind kind);
    void* allocate(std::size_t size);
    void deallocate(void* memory);
}

namespace SphereUI::Runtime {
    void invokeEventHandler(WindowEventHandler handler, Window* window, const WindowEvent& event);
}

namespace SphereUI {
enum class UiMessage : std::uint32_t {
    none = 0,
    beginDragDrop = 10,
    showHelpPage = 14,
    refreshInterface = 16,
    close = 100u,
    horizontalScroll = 101u,
    verticalScroll = 102u,
    pointerEnter = 103u,
    pointerLeave = 104u,
    setInputEnabled = 105u,
    getInputEnabled = 106u,
    setTextRgb = 107u,
    setHidden = 108u,
    getHidden = 109u,
    setEnabled = 112u,
    getDisabled = 113u,
    setTextAlignment = 114u,
    animateVisibility = 115u,
    setPosition = 116u,
    getChildUnderCursor = 117u,
    updateScrollLayout = 118u,
    getModal = 119u,
    endModal = 120u,
    beginModal = 121u,
    setSize = 122u,
    setFont = 123u,
    leftClick = 1001u,
    setChecked = 1002u,
    getChecked = 1003u,
    activateButton = 1004u,
    rightClick = 1005u,
    setProgressValue = 2001u,
    setProgressRange = 2002u,
    getProgressRange = 2004u,
    getProgressValue = 2010u,
    setScrollValue = 2501u,
    setScrollRange = 2502u,
    getScrollRange = 2503u,
    setScrollParameters = 2504u,
    getScrollParameters = 2505u,
    increaseScroll = 2506u,
    decreaseScroll = 2507u,
    getScrollValue = 2600u,
    setImageName = 2601u,
    setImageRotation = 2602u,
    setImageDescription = 2603u,
    setImageAlpha = 2604u,
    previousHyperTextPage = 2701u,
    firstHyperTextPage = 2702u,
    loadHyperTextPage = 2703u,
    hyperTextPageChanged = 2704u,
    clearHyperTextHistory = 2705u,
    loadHyperTextBuffer = 2706u,
    resizeToHyperText = 2707u,
    setTooltipLine = 3001u,
    getTooltipLine = 3002u,
    appendTooltipLine = 3003u,
    setTooltipBackground = 3004u,
    setTooltipTextColor = 3500u,
    appendListText = 3601u,
    setListText = 3602u,
    setListColor = 3603u,
    setListFormatting = 3604u,
    alignListRow = 3605u,
    listSelectionChanged = 3606u,
    setListSelection = 3607u,
    getListSelection = 3608u,
    getListText = 3609u,
    getListSize = 3610u,
    getListColor = 3611u,
    listDoubleClick = 3612u,
    clearList = 3613u,
    removeListRow = 3614u,
    getListScroll = 3615u,
    setListScroll = 3616u,
    sliderValueChanged = 3800u,
    listItemEvent = 4001u,
    appendListItem = 4002u,
    listItemSelectionChanged = 4003u,
    getListItemSelection = 4004u,
    setListItemSelection = 4005u,
    getListItemCount = 4006u,
    removeListItem = 4007u,
    clearListItems = 4008u,
    editSubmit = 4501u,
    setEditText = 4502u,
    getEditText = 4503u,
    getEditFocus = 4504u,
    moveEditCaretToEnd = 4505u,
    editTab = 4506u,
    setSlotItem = 5001u,
    setSlotHighlight = 5002u,
    slotDrag = 5003u,
    slotHitTest = 5004u,
    setSlotDescription = 5005u,
    setSlotCount = 5006u,
    setSlotFillColor = 5007u,
    setSlotFillAlpha = 5008u,
    setSlotBorderColor = 5009u,
    setSlotTopLeftOverlay = 5010u,
    setSlotBottomRightOverlay = 5011u,
    setSlotBottomLeftOverlay = 5012u,
    spinValueChanged = 5501u,
    setSpinValue = 5502u,
    setSpinRange = 5503u,
    getSpinRange = 5504u,
    updateSpinStatus = 5505u,
    setSpinStep = 5506u,
    getSpinStep = 5507u,
    getSpinValue = 5600u,
    setRichEditContent = 6001u,
    getRichEditContent = 6002u,
    appendFilteredListText = 6501u,
    clearFilteredList = 6502u,
    setListFilter = 6503u,
    openBrowser = 7001u,
    updateBrowser = 7002u,
    navigateBrowser = 7003u,
    refreshBrowser = 7004u,
    getBrowserLocation = 7005u,
    menuItemActivated = 7100u,
    clearMenu = 7101u,
    appendMenuItem = 7102u,
    activateMenuItem = 7103u,
    setMenuItemEnabled = 7104u,
    setMenuItemText = 7105u,
    appendChatMessage = 7500u,
    addChatChannel = 7501u,
    setChatChannels = 7502u,
    clearChatChannels = 7503u,
    chatPlayerLeftClick = 7504u,
    chatPlayerRightClick = 7505u,
    getChatPlainText = 7508u,
    getChatHyperText = 7509u,
    getSelectedChatLink = 7510u,
    getSelectedChatHyperText = 7511u,
    getSelectedChatPlainText = 7512u,
    setHyperEditContent = 7600u,
    getHyperEditPlainText = 7601u,
    getHyperEditHyperText = 7602u,
    hyperEditSubmit = 7603u,
    getHyperEditLengths = 7604u,
    setHyperEditTextColor = 7606u,
    setSelectedFont = 7650u,
    getSelectedFont = 7651u,
    selectedFontChanged = 7652u,
    dropToScene = 13u,
    controlBindingCaptured = 15u,
    dragEnter = 110u,
    dragLeave = 111u,
};
namespace WindowStyle {
    constexpr std::uint32_t skipDrawing = 1u << 1u;
    constexpr std::uint32_t showTitle = 1u << 2u;
    constexpr std::uint32_t handleEscape = 1u << 3u;
    constexpr std::uint32_t preventOverlap = 1u << 4u;
}
namespace MouseInput {
    constexpr std::uint32_t leftPress = 1u << 0u;
    constexpr std::uint32_t rightPress = 1u << 1u;
    constexpr std::uint32_t leftRelease = 1u << 2u;
    constexpr std::uint32_t rightRelease = 1u << 3u;
    constexpr std::uint32_t anyRelease = leftRelease | rightRelease;
}
enum class UiControlKind {
    window = 0u,
    button = 1u,
    text = 2u,
    image = 3u,
    progressBar = 4u,
    scrollBar = 5u,
    hyperText = 6u,
    checkBox = 7u,
    radioButton = 8u,
    tooltip = 9u,
    textList = 10u,
    slider = 11u,
    listItem = 12u,
    edit = 13u,
    slot = 14u,
    miniHelp = 15u,
    spinButton = 16u,
    richEdit = 17u,
    filteredList = 18u,
    webBrowser = 19u,
    minimap = 20u,
    menu = 21u,
    hyperTextChat = 22u,
    hyperTextEdit = 23u,
    fontPicker = 24u,
    colorPicker = 25u,
    any = INT32_MAX
};
}


namespace SphereUI::Runtime { void setTextInputActive(bool active); }
