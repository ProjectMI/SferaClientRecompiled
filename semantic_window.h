#pragma once
#include <cstddef>
#include <cstdint>
class SferaSimpleParser;
struct SferaParserRange;
struct SferaCursorPosition;
namespace SphereUI {
    struct UiString {
        char storage[16];
        std::uint32_t length;
        std::uint32_t capacity;
        std::uint32_t context;
        const char* data() const;
        void assign(const char* text);
        void release();
    };
}

struct HyperTextGeometry {
    std::int32_t x;
    std::int32_t y;
    std::int32_t width;
    std::int32_t height;
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
        std::int32_t mouse_x;
        std::int32_t mouse_y;
        std::int32_t wheel_delta;
        std::uint32_t mouse_flags;
        std::uint32_t mouse_buttons;
        mutable std::uint8_t key_code; // Delivery consumes handled virtual keys without changing the event coordinates.
        mutable std::uint8_t character;
        std::uint8_t key_reserved[2];
        std::uint32_t key_modifiers;
    };

    struct WindowEvent {
        Window* source;
        std::uint32_t control_id;
        std::uint32_t message;
        std::uint32_t first;
        std::uint32_t second;
        std::uint32_t extra_0;
        std::uint32_t extra_1;
    };

    struct alignas(8) WindowAnimation {
        std::uint8_t kind;
        std::uint8_t reserved[7];
        std::uint32_t start_time_low;
        std::uint32_t start_time_high;
        float duration;
        float distance;
        float offset;
        float origin;
        std::uint32_t phase;
        std::uint32_t reserved_tail;
    };
    struct UiRect {
        std::int32_t left;
        std::int32_t top;
        std::int32_t right;
        std::int32_t bottom;
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
        std::int32_t width;
        std::int32_t height;
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
        std::uint32_t texture;
        std::uint32_t flags;
        float u[4];
        float v[4];
        std::uint32_t left;
        std::uint32_t width;
        std::uint32_t top;
        std::uint32_t height;
        void setTexture(const char* texture_name, const std::uint32_t* texture_rectangle, const std::uint32_t* sprite_rectangle);
    };

    struct UiSprite {
        char* name;
        std::uint32_t width;
        std::uint32_t height;
        SpriteVertex vertices[4];
        std::uint32_t reference_count;
        SpritePart* parts;
        std::uint32_t part_count;
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
        void resizeParts(std::uint32_t count);
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
        std::uint32_t context;
        std::uint32_t size() const;
        T& at(std::uint32_t index);
        const T& at(std::uint32_t index) const;
        void reserve(std::uint32_t count);
        void append(const T& value);
        void erase(std::uint32_t index);
        void clear();
        void release();
        void copyFrom(const UiVector& source);
    };

    using UiIndexVector = UiVector<std::uint32_t>;
    struct UiMenuItem {
        UiString text;
        std::uint8_t enabled;
        std::uint8_t reserved[3];
    };

    template<class T> struct UiStringRecords {
        T* begin;
        T* end;
        T* capacity;
        std::uint32_t context;
        std::uint32_t size() const;
        T& at(std::uint32_t index);
        const T& at(std::uint32_t index) const;
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
        std::uint32_t context;
        std::uint32_t size() const {
            return begin == nullptr ? 0u : static_cast<std::uint32_t>(end - begin);
        }

        T& at(std::uint32_t index) {
            return begin[index];
        }

        const T& at(std::uint32_t index) const {
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
        std::uint32_t map_size;
        std::uint32_t offset;
        std::uint32_t count;
        std::uint32_t context;
        void initialize();
        T& at(std::uint32_t index);
        const T& at(std::uint32_t index) const;
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
        std::uint8_t black;
        std::uint8_t is_nil;
        std::uint8_t reserved[2];
    };

    struct UiIntegerSet {
        UiContainerProxy* proxy;
        UiIntegerSetNode* sentinel;
        std::uint32_t count;
        std::uint32_t context;
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
        std::uint32_t context;
        std::uint32_t size() const;
        UiString& at(std::uint32_t index);
        const UiString& at(std::uint32_t index) const;
        void append(const char* text);
        void insert(std::uint32_t index, const char* text);
        void erase(std::uint32_t index);
        void clear();
        void release();
        void copyFrom(const UiStringVector& source);
    };

    struct UiTextRow {
        UiString text;
        std::uint32_t color;
        std::int32_t offset;
    };

    struct UiTextRows {
        UiTextRow* begin;
        UiTextRow* end;
        UiTextRow* capacity;
        std::uint32_t context;
        std::uint32_t size() const;
        UiTextRow& at(std::uint32_t index);
        const UiTextRow& at(std::uint32_t index) const;
        void append(const char* text, std::uint32_t color, std::int32_t offset);
        void erase(std::uint32_t index);
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
        std::uint32_t count;
        std::uint32_t storage_context;
    };

    class Window {
    public:
        char name[16];
        std::uint32_t name_length;
        std::uint32_t name_capacity;
        std::uint32_t name_storage_context;
        std::uint32_t behavior_flags;
        std::int32_t width;
        std::int32_t height;
        std::int32_t x;
        std::int32_t y;
        std::uint32_t alignment_flags;
        std::int32_t group;
        std::int32_t initial_x;
        std::int32_t initial_y;
        std::uint8_t hidden;
        std::uint8_t disabled;
        std::uint8_t input_enabled;
        std::uint8_t is_reference;
        std::uint8_t can_drag_drop;
        std::uint8_t can_go_top;
        std::uint8_t save_last_position;
        std::uint8_t hit_transparent;
        std::uint32_t control_kind;
        char text[16];
        std::uint32_t text_length;
        std::uint32_t text_capacity;
        std::uint32_t text_storage_context;
        char help[16];
        std::uint32_t help_length;
        std::uint32_t help_capacity;
        std::uint32_t help_storage_context;
        std::uint8_t font;
        std::uint8_t font_initialized;
        std::uint16_t font_attributes;
        std::uint32_t text_color;
        std::uint32_t text_state;
        std::uint32_t disabled_color;
        Window* parent;
        SferaWindowChildNode* child_sentinel;
        std::uint32_t child_count;
        std::uint32_t child_storage_context;
        SferaWindowChildNode* reference_sentinel;
        std::uint32_t reference_count;
        std::uint32_t reference_storage_context;
        std::uint32_t modal_owner;
        UiContainerProxy* event_proxy;
        WindowEvent** event_slots;
        std::uint32_t event_capacity;
        std::uint32_t event_head;
        std::uint32_t event_size;
        std::uint32_t event_storage_context;
        std::uint32_t pending_event_count;
        std::uint32_t control_id;
        std::uint32_t alpha;
        std::uint8_t animation_active;
        std::uint8_t animation_state;
        std::uint16_t animation_reserved;
        std::int32_t text_offset_x;
        std::int32_t text_offset_y;
        Window* tooltip;
        Window* overlay;
        Window* resource_parent;
        std::uint32_t event_handler_token;
        std::int32_t caption_left;
        std::int32_t caption_top;
        std::int32_t caption_right;
        std::int32_t caption_bottom;
        std::uint8_t dragging;
        std::uint8_t drag_reserved[3];
        std::int32_t drag_offset_x;
        std::int32_t drag_offset_y;
        std::uint32_t input_mask;
        std::uint8_t hide_after_animation;
        std::uint8_t hide_reserved[3];
        WindowAnimation show_animation;
        WindowAnimation hide_animation;
        WindowAnimation* active_animation;
        WindowResourceList* resource_list;
        char resource_name[16];
        std::uint32_t resource_name_length;
        std::uint32_t resource_name_capacity;
        std::uint32_t resource_name_storage_context;
        UiSprite* resource_reference;
        Window() {
        }

        void initialize();
        void initializeCopy(const Window& source);
        void resetToolTips();
        void alignToScreen(bool reset_position);
        void applyAnimation(const WindowAnimation& effect, float fraction);
        void updateAnimation();
        void startAnimation(std::uint32_t phase);
        void beginClose(bool animated);
        void animateVisibility(bool hide);
        void drawToolTips();
        Window& copyStateFrom(const Window& source);
        Window& copyStateFrom(const Window& source, bool copy_children);
        void release();
        Window* createControl(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range, std::uint32_t kind, std::uint32_t id);
        void appendChild(Window* child);
        void appendResource(UiSprite* resource);
        UiSprite* findResource(const char* resource_name) const;
        UiSprite* getResource(const char* resource_name);
        void setParent(Window* new_parent);
        void setInputFocus(bool focused, bool submit_on_blur = false);
        void getAbsolutePosition(std::int32_t& screen_x, std::int32_t& screen_y) const;
        bool containsPoint(std::int32_t screen_x, std::int32_t screen_y) const;
        std::int32_t childControlAt(std::int32_t screen_x, std::int32_t screen_y) const;
        void clearEvents();
        void queueEvent(const WindowEvent& event);
        bool pollEvent(WindowEvent& event);
        void processEvents();
        void setText(const char* value);
        const char* getText() const;
        const char* getHelp() const;
        void setHelp(const char* value);
        void setName(const char* value);
        Window* controlAt(std::uint32_t index) const;
        void addModalReference(Window& window);
        const char* getName() const;
        const char* getResourceName() const;
        void setResourceName(const char* value);
        virtual bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range);
        virtual Window* clone();
        virtual std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second);
        virtual void setPosition(std::int32_t x, std::int32_t y);
        virtual void draw();
        virtual void handleInput(const WindowInput& input);
        virtual void setOpacity(float opacity);
        virtual bool hitTest(std::int32_t screen_x, std::int32_t screen_y);
        virtual void dispatchMessage(std::int32_t target_group, std::uint32_t message, std::uint32_t first, std::uint32_t second, std::uint32_t target_kind);
        virtual void setFont(std::uint32_t font_id);
        virtual std::uint32_t getFont() const;
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
        std::uint32_t repeat_time_low;
        std::uint32_t repeat_time_high;
        std::uint8_t pressed;
        std::uint8_t pressed_reserved[3];
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
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
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
        std::uint8_t checked;
        std::uint8_t hovered;
        std::uint16_t check_reserved;
        std::int32_t image_x;
        std::int32_t image_y;
        std::uint32_t button_flags;
        std::int32_t label_x;
        std::int32_t label_y;
        std::uint32_t hover_color;
        void initialize();
        void copyCheckState(const CheckBox& source);
        CheckBox() {
        }

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        virtual void playClickSound();
    };

    class CDescriptionWindow : public Window {
    public:
        std::uint32_t reserved_198;
        std::uint32_t displayed_id;
        std::uint32_t pending_id;
        std::uint32_t show_deadline;
        std::uint32_t hide_deadline;
        UiSprite* caption_sprite;
        UiSprite* bottom_sprite;
        UiSprite* left_sprite;
        UiSprite* right_sprite;
        std::int32_t height_padding;
        std::uint8_t pinned;
        CDescriptionWindow() {
        }

        void initialize();
        static CDescriptionWindow* instance();
        void close();
        void update();
        void handleEvent(const WindowEvent& event);
        SferaCursorPosition* calculatePosition(SferaCursorPosition* output) const;
        void showDescription(const char* text, std::uint32_t id, std::uint32_t duration, bool pin);
        void requestDescription(const char* text, bool force, std::uint32_t id);
        void draw() override;
        void destroy(bool free_storage) override;
    };

    class EditCtrl : public Window {
    public:
        std::int32_t cursor_x;
        std::int32_t cursor_y;
        std::int32_t cursor_offset_x;
        std::int32_t cursor_offset_y;
        std::uint8_t numeric;
        std::uint8_t password;
        std::uint16_t edit_reserved;
        std::uint32_t maximum_symbols;
        std::int32_t cursor_width;
        UiString password_text;
        std::uint32_t cursor_color;
        std::uint32_t cursor_alignment;
        std::uint64_t blink_started;
        std::uint8_t cursor_visible;
        std::uint8_t cursor_uses_text_color;
        std::uint8_t submit_on_blur;
        std::uint8_t cursor_reserved;
        std::int32_t caret_position;
        std::uint32_t observed_length;
        std::uint32_t history_count;
        std::uint32_t history_position;
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
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    class ListCtrl : public Window {
    public:
        std::int32_t visible_begin;
        std::int32_t visible_end;
        UiTextRows rows;
        std::uint32_t maximum_items;
        std::uint32_t write_index;
        std::int32_t maximum_scroll;
        std::int32_t line_height;
        std::int32_t visible_capacity;
        std::int32_t vertical_offset;
        std::int32_t cropped_y;
        std::uint8_t chatlike;
        std::uint8_t format_strings;
        std::uint8_t continue_mark;
        std::uint8_t list_reserved;
        ScrollBar* scrollbar;
        std::uint8_t can_select;
        std::uint8_t selection_reserved[3];
        std::int32_t selected_index;
        std::int32_t selection_border;
        std::uint32_t selection_color;
        std::uint32_t selection_line_color;
        std::uint64_t click_time;
        std::uint8_t click_pending;
        std::uint8_t click_reserved[7];
        ListCtrl() {
        }

        void initialize();
        void copyListState(const ListCtrl& source);
        void updateLayout();
        void updateVisibleRange();
        std::uint32_t physicalIndex(std::uint32_t logical_index) const;
        void appendLine(const char* text, std::uint32_t color);
        void appendFormattedLine(const char* text, std::uint32_t color);
        void addText(const char* text, std::uint32_t color);
        void clearRows();
        void removeRow(std::uint32_t logical_index);
        void selectRow(std::int32_t index);
        void alignRow(std::uint32_t index, std::uint32_t flags);
        void drawSelection(std::int32_t x, std::int32_t y, std::int32_t row_y, bool restore_viewport);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    class FilterListCtrl : public ListCtrl {
    public:
        std::uint32_t filter_mask;
        UiTextRows history;
        std::uint32_t history_write;
        FilterListCtrl() {
        }

        void initialize();
        void clearHistory();
        void appendHistory(const char* text, std::uint32_t color, std::uint32_t mask);
        void applyFilter(std::uint32_t mask);
        Window* clone() override;
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
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
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setFont(std::uint32_t font_id) override;
        std::uint32_t getFont() const override;
        void destroy(bool free_storage) override;
    };

    class HyperTextDocument;

    struct UiIndexRange {
        std::uint32_t first;
        std::uint32_t last;
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
        void layout(std::int32_t width, std::uint32_t font);
    };

    class HyperTextChatListControl : public Window {
    public:
        UiDeque<HyperTextChatListItem> messages;
        UiIndexVector visible_messages;
        UiIndexVector channels;
        UiString selected_link_text;
        UiString selected_link_value;
        UiString selected_plain_text;
        UiString selected_hyper_text;
        std::uint32_t player_link_color;
        std::uint32_t item_link_color;
        std::uint32_t link_color;
        std::uint32_t maximum_items;
        std::uint32_t row_height;
        std::uint32_t page_rows;
        std::int32_t parent_x;
        std::int32_t parent_y;
        std::uint32_t bottom_message;
        std::uint32_t bottom_row;
        std::uint32_t scroll_offset;
        ScrollBar* scrollbar;
        UiViewport saved_viewport;
        UiArray<UiIndexRange> rendered_rows;
        void initialize();
        void copyChatState(const HyperTextChatListControl& source);
        void addMessage(const char* text, std::uint32_t channel, std::uint32_t color);
        void addChannel(std::uint32_t channel);
        void setChannels(const std::uint32_t* values, std::uint32_t count);
        void clearChannels();
        void rebuildVisible();
        void updateParentPosition();
        bool visibleRowRange(std::uint32_t message, std::uint32_t drawn, std::uint32_t rows, std::uint32_t* first, std::uint32_t* last) const;
        void updateScroll(bool reset);
        void readScroll();
        const char* messageText(std::uint32_t index, bool plain) const;
        void drawElement(HyperTextElement& element, std::int32_t x, std::int32_t y, std::uint32_t color);
        HyperTextChatListControl() {
        }

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setFont(std::uint32_t font_id) override;
        void destroy(bool free_storage) override;
    };

    class HyperTextCtrl : public Window {
    public:
        HyperTextDocument* document;
        std::uint32_t text_format;
        char pending_name[256];
        std::uint8_t remember_page;
        std::uint8_t hypertext_reserved[3];
        std::int32_t maximum_scroll;
        std::int32_t scroll_position;
        std::int32_t first_line_offset;
        std::int32_t clip_offset;
        std::int32_t clip_height;
        std::int32_t previous_line_offset;
        std::int32_t previous_clip_offset;
        std::int32_t previous_clip_height;
        HyperTextDocument* previous_document;
        float transition_fraction;
        std::uint8_t transition_active;
        std::uint8_t transition_reserved[3];
        std::uint64_t transition_started;
        ScrollBar* scrollbar;
        UiStringDeque history;
        std::uint32_t link_color;
        std::uint32_t hover_color;
        std::int32_t tooltip_index;
        const char* pending_buffer;
        std::uint32_t pending_bytes;
        std::uint8_t discard_old_text;
        std::uint8_t discard_reserved[7];
        HyperTextCtrl() {
        }

        void initialize();
        void copyHyperTextState(const HyperTextCtrl& source);
        void queuePage(const char* name, bool remember);
        void queueBuffer(const char* buffer, std::uint32_t size);
        void updateDocument(bool resize_to_content);
        void updateScroll();
        void openLink(const char* target);
        static std::uint32_t parseTextFormat(const char* name);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    class HyperTextEditControl : public Window {
    public:
        UiStringDeque history;
        std::uint32_t history_position;
        std::uint32_t maximum_history;
        UiIntegerSet edit_modes;
        UiString visible_text;
        UiString hyper_text;
        UiDeque<HyperTextElement*> elements;
        std::uint32_t cursor_type;
        std::uint32_t caret_position;
        std::uint32_t blink_started;
        std::uint8_t cursor_visible;
        std::uint8_t cursor_reserved[3];
        UiRect text_margins;
        std::uint32_t cursor_color;
        std::uint32_t plain_color;
        std::uint32_t player_link_color;
        std::uint32_t item_link_color;
        std::uint32_t link_color;
        std::uint32_t maximum_visible_length;
        std::uint32_t maximum_hyper_length;
        std::uint32_t visible_first;
        std::uint32_t visible_last;
        UiViewport saved_viewport;
        std::int32_t parent_x;
        std::int32_t parent_y;
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
        static std::uint32_t fitText(const char* text, std::uint32_t font, std::int32_t pixels, bool reverse);
        HyperTextEditControl() {
        }

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    class ImageCtrl : public Window {
    public:
        std::uint32_t image_style;
        std::uint8_t interaction_active;
        UiSprite* fallback_image;
        std::uint8_t rotated;
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
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setOpacity(float opacity) override;
        void destroy(bool free_storage) override;
    };

    class ListItemCtrl : public Window {
    public:
        Window* item_template;
        UiVector<Window*> items;
        std::int32_t horizontal_offset;
        std::int32_t vertical_offset;
        std::int32_t visible_begin;
        std::int32_t visible_end;
        std::int32_t visible_capacity;
        std::int32_t cropped_x;
        std::int32_t cropped_y;
        std::int32_t maximum_y;
        std::int32_t maximum_x;
        ScrollBar* vertical_scroll;
        ScrollBar* horizontal_scroll;
        std::uint8_t layout_dirty;
        std::uint8_t can_select;
        std::uint16_t selection_reserved;
        UiSprite* selection_sprite;
        std::int32_t selected_index;
        std::uint8_t horizontal;
        std::uint8_t user_move;
        std::uint16_t interaction_reserved;
        ListItemCtrl() {
        }

        void initialize();
        Window* itemAt(std::uint32_t index) const;
        std::int32_t addItem();
        void removeItem(std::uint32_t index);
        void clearItems();
        void updateLayout();
        void updateVisibleRange();
        void copyItemState(const ListItemCtrl& source);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setOpacity(float opacity) override;
        bool hitTest(std::int32_t screen_x, std::int32_t screen_y) override;
        void dispatchMessage(std::int32_t target_group, std::uint32_t message, std::uint32_t first, std::uint32_t second, std::uint32_t target_kind) override;
        void destroy(bool free_storage) override;
    };

    class CMenuListControl : public Window {
    public:
        std::uint32_t maximum_items;
        UiSprite* top_sprite;
        UiSprite* middle_sprite;
        UiSprite* hovered_sprite;
        UiSprite* bottom_sprite;
        std::uint32_t title_color;
        std::uint32_t normal_color;
        std::uint32_t hovered_color;
        std::uint32_t item_disabled_color;
        std::uint8_t show_title;
        std::uint8_t menu_reserved[3];
        UiRect title_margin;
        std::uint32_t title_format;
        UiRect item_margin;
        std::uint32_t item_format;
        TextExtent top_size;
        TextExtent item_size;
        TextExtent bottom_size;
        std::int32_t parent_screen_x;
        std::int32_t parent_screen_y;
        std::int32_t parent_width;
        std::int32_t parent_height;
        UiStringRecords<UiMenuItem> items;
        std::uint32_t hovered_index;
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
        std::uint32_t itemAtPoint(std::int32_t x, std::int32_t y) const;
        void drawHeader();
        void drawItem(std::uint32_t index, UiSprite* sprite, std::uint32_t color);
        void drawFooter();
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    class ToolTipCtrl : public Window {
    public:
        std::int32_t screen_x;
        std::int32_t screen_y;
        std::uint8_t hover_pending;
        std::uint8_t hover_padding[7];
        std::uint64_t hover_started;
        float fade_opacity;
        std::uint32_t fade_padding;
        std::uint64_t fade_started;
        std::uint32_t background_color;
        std::int32_t tooltip_width;
        std::int32_t tooltip_height;
        std::uint8_t dismissed;
        std::uint8_t dismissed_padding[3];
        UiStringVector lines;
        std::int32_t line_height;
        std::int32_t margin_left;
        std::int32_t margin_top;
        std::int32_t margin_right;
        std::int32_t margin_bottom;
        ToolTipCtrl() {
        }

        void initialize();
        void reset();
        void showAt(std::int32_t x, std::int32_t y);
        void updateFade();
        void updateLayout();
        void appendLine(const char* text);
        void setLine(std::uint32_t index, const char* text);
        void copyTipState(const ToolTipCtrl& source);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
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
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void destroy(bool free_storage) override;
    };

    class ProgressBar : public Window {
    public:
        std::int32_t minimum;
        std::int32_t maximum;
        std::int32_t current;
        float progress_ratio;
        std::uint32_t display_mode;
        char status_text[64];
        std::int32_t status_x;
        std::int32_t status_y;
        void initialize();
        ProgressBar() {
        }

        void initializeProgressState();
        void setProgressValue(std::int32_t value);
        void setProgressRange(std::int32_t new_minimum, std::int32_t new_maximum);
        void copyProgressState(const ProgressBar& source);
        void refreshProgressDisplay();
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
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
        std::int32_t caret_row;
        std::int32_t caret_column;
        std::uint64_t blink_started;
        std::uint8_t cursor_visible;
        std::uint8_t rich_reserved[3];
        std::int32_t cursor_width;
        std::int32_t line_height;
        std::int32_t page_rows;
        std::int32_t first_row;
        ScrollBar* scrollbar;
        RichEditCtrl() {
        }

        void initialize();
        void copyRichState(const RichEditCtrl& source);
        void updateMetrics(std::uint32_t font_id);
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
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };

    struct ScrollParameters {
        std::uint32_t size;
        std::uint32_t mask;
        std::int32_t minimum;
        std::int32_t maximum;
        std::int32_t page_step;
        std::int32_t current;
        std::int32_t step;
    };

    class ScrollBar : public Window {
    public:
        UiSprite* scroll_resource;
        std::int32_t thumb_width;
        std::int32_t thumb_height;
        std::int32_t thumb_x;
        std::int32_t thumb_y;
        std::uint32_t orientation_flags;
        ButtonCtrl* decrease_button;
        ButtonCtrl* increase_button;
        float normalized_position;
        std::int32_t minimum;
        std::int32_t maximum;
        std::int32_t current;
        std::int32_t step;
        std::int32_t page_step;
        std::uint8_t dragging_thumb;
        std::uint8_t explicit_step;
        std::uint8_t notify_changes;
        std::uint8_t scroll_reserved;
        std::int32_t repeat_alignment;
        std::int32_t repeat_time_low;
        std::uint32_t repeat_time_high;
        std::int32_t track_left;
        std::int32_t track_top;
        std::int32_t track_right;
        std::int32_t track_bottom;
        std::uint8_t page_click_active;
        std::uint8_t page_click_reserved[7];
        ScrollBar() {
        }

        void initialize();
        void setParameters(const struct ScrollParameters& parameters);
        void getParameters(struct ScrollParameters& parameters) const;
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
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
        std::int32_t status_x;
        std::int32_t status_y;
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
        std::int32_t image_offset_x;
        std::int32_t image_offset_y;
        UiSprite item_image;
        std::uint8_t show_full_background;
        std::uint8_t has_item;
        std::uint16_t slot_reserved;
        std::int32_t press_x;
        std::int32_t press_y;
        std::uint8_t left_pressed;
        std::uint8_t right_pressed;
        std::uint8_t drag_started;
        std::uint8_t slot_state_reserved;
        UiString description;
        std::int32_t count_offset_x;
        std::int32_t count_offset_y;
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
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        bool hitTest(std::int32_t screen_x, std::int32_t screen_y) override;
        void destroy(bool free_storage) override;
    };

    class SpinButton : public Window {
    public:
        ButtonCtrl* decrease_button;
        ButtonCtrl* increase_button;
        std::int32_t minimum;
        std::int32_t maximum;
        std::int32_t current;
        std::int32_t previous;
        std::int32_t step;
        Window* body;
        std::uint32_t body_index;
        std::uint8_t status_valid;
        std::uint8_t notify_changes;
        std::uint8_t update_enabled;
        SpinButton() {
        }

        void initialize();
        void setRange(std::int32_t minimum, std::int32_t maximum);
        void setCurrentValue(std::int32_t value);
        void setStep(std::int32_t step);
        std::int32_t currentValue() const;
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
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
        std::uint8_t mouse_pressed;
        std::uint8_t browser_reserved[3];
        CWebBrowserControl() {
        }

        void initialize();
        void copyBrowserState(const CWebBrowserControl& source);
        bool open(const char* address);
        bool navigate(const char* address);
        bool updateBrowser();
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        Window* clone() override;
        std::uint32_t handleMessage(std::uint32_t message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void destroy(bool free_storage) override;
    };
}

// Native window entry points used by the remaining ABI adapters.
namespace SphereUI::detail {
    void serializeHyperTextElements(const UiDeque<HyperTextElement*>& elements, UiString& hyper_text, UiString& plain);
    void escapeHyperText(UiString& output, const UiString& source);
    std::uint32_t controlKind(const char* name);
    std::uint32_t animationKind(const char* name);
    std::uint32_t alignmentFlag(const char* name);
}

namespace SphereUI::Runtime {
    void clipboardText(UiString& result);
    CDescriptionWindow* descriptionWindow();
    Window* makeControl(std::uint32_t kind);
    void broadcastMessage(Window* root, std::int32_t group, std::uint32_t message, std::uint32_t first, std::uint32_t second, std::uint32_t kind);
    void* allocate(std::size_t size);
    void deallocate(void* memory);
}

namespace SphereUI::Runtime {
    void invokeEventHandler(WindowEventHandler handler, Window* window, const WindowEvent& event);
}

namespace SphereUI {
namespace UiMessage {
    constexpr std::uint32_t close = 100u;
    constexpr std::uint32_t horizontalScroll = 101u;
    constexpr std::uint32_t verticalScroll = 102u;
    constexpr std::uint32_t pointerEnter = 103u;
    constexpr std::uint32_t pointerLeave = 104u;
    constexpr std::uint32_t setInputEnabled = 105u;
    constexpr std::uint32_t getInputEnabled = 106u;
    constexpr std::uint32_t setTextRgb = 107u;
    constexpr std::uint32_t setHidden = 108u;
    constexpr std::uint32_t getHidden = 109u;
    constexpr std::uint32_t setEnabled = 112u;
    constexpr std::uint32_t getDisabled = 113u;
    constexpr std::uint32_t setTextAlignment = 114u;
    constexpr std::uint32_t animateVisibility = 115u;
    constexpr std::uint32_t setPosition = 116u;
    constexpr std::uint32_t getChildUnderCursor = 117u;
    constexpr std::uint32_t updateScrollLayout = 118u;
    constexpr std::uint32_t getModal = 119u;
    constexpr std::uint32_t endModal = 120u;
    constexpr std::uint32_t beginModal = 121u;
    constexpr std::uint32_t setSize = 122u;
    constexpr std::uint32_t setFont = 123u;
    constexpr std::uint32_t leftClick = 1001u;
    constexpr std::uint32_t setChecked = 1002u;
    constexpr std::uint32_t getChecked = 1003u;
    constexpr std::uint32_t activateButton = 1004u;
    constexpr std::uint32_t rightClick = 1005u;
    constexpr std::uint32_t setProgressValue = 2001u;
    constexpr std::uint32_t setProgressRange = 2002u;
    constexpr std::uint32_t getProgressRange = 2004u;
    constexpr std::uint32_t getProgressValue = 2010u;
    constexpr std::uint32_t setScrollValue = 2501u;
    constexpr std::uint32_t setScrollRange = 2502u;
    constexpr std::uint32_t getScrollRange = 2503u;
    constexpr std::uint32_t setScrollParameters = 2504u;
    constexpr std::uint32_t getScrollParameters = 2505u;
    constexpr std::uint32_t increaseScroll = 2506u;
    constexpr std::uint32_t decreaseScroll = 2507u;
    constexpr std::uint32_t getScrollValue = 2600u;
    constexpr std::uint32_t setImageName = 2601u;
    constexpr std::uint32_t setImageRotation = 2602u;
    constexpr std::uint32_t setImageDescription = 2603u;
    constexpr std::uint32_t setImageAlpha = 2604u;
    constexpr std::uint32_t previousHyperTextPage = 2701u;
    constexpr std::uint32_t firstHyperTextPage = 2702u;
    constexpr std::uint32_t loadHyperTextPage = 2703u;
    constexpr std::uint32_t hyperTextPageChanged = 2704u;
    constexpr std::uint32_t clearHyperTextHistory = 2705u;
    constexpr std::uint32_t loadHyperTextBuffer = 2706u;
    constexpr std::uint32_t resizeToHyperText = 2707u;
    constexpr std::uint32_t setTooltipLine = 3001u;
    constexpr std::uint32_t getTooltipLine = 3002u;
    constexpr std::uint32_t appendTooltipLine = 3003u;
    constexpr std::uint32_t setTooltipBackground = 3004u;
    constexpr std::uint32_t setTooltipTextColor = 3500u;
    constexpr std::uint32_t appendListText = 3601u;
    constexpr std::uint32_t setListText = 3602u;
    constexpr std::uint32_t setListColor = 3603u;
    constexpr std::uint32_t setListFormatting = 3604u;
    constexpr std::uint32_t alignListRow = 3605u;
    constexpr std::uint32_t listSelectionChanged = 3606u;
    constexpr std::uint32_t setListSelection = 3607u;
    constexpr std::uint32_t getListSelection = 3608u;
    constexpr std::uint32_t getListText = 3609u;
    constexpr std::uint32_t getListSize = 3610u;
    constexpr std::uint32_t getListColor = 3611u;
    constexpr std::uint32_t listDoubleClick = 3612u;
    constexpr std::uint32_t clearList = 3613u;
    constexpr std::uint32_t removeListRow = 3614u;
    constexpr std::uint32_t getListScroll = 3615u;
    constexpr std::uint32_t setListScroll = 3616u;
    constexpr std::uint32_t sliderValueChanged = 3800u;
    constexpr std::uint32_t listItemEvent = 4001u;
    constexpr std::uint32_t appendListItem = 4002u;
    constexpr std::uint32_t listItemSelectionChanged = 4003u;
    constexpr std::uint32_t getListItemSelection = 4004u;
    constexpr std::uint32_t setListItemSelection = 4005u;
    constexpr std::uint32_t getListItemCount = 4006u;
    constexpr std::uint32_t removeListItem = 4007u;
    constexpr std::uint32_t clearListItems = 4008u;
    constexpr std::uint32_t editSubmit = 4501u;
    constexpr std::uint32_t setEditText = 4502u;
    constexpr std::uint32_t getEditText = 4503u;
    constexpr std::uint32_t getEditFocus = 4504u;
    constexpr std::uint32_t moveEditCaretToEnd = 4505u;
    constexpr std::uint32_t editTab = 4506u;
    constexpr std::uint32_t setSlotItem = 5001u;
    constexpr std::uint32_t setSlotHighlight = 5002u;
    constexpr std::uint32_t slotDrag = 5003u;
    constexpr std::uint32_t slotHitTest = 5004u;
    constexpr std::uint32_t setSlotDescription = 5005u;
    constexpr std::uint32_t setSlotCount = 5006u;
    constexpr std::uint32_t setSlotFillColor = 5007u;
    constexpr std::uint32_t setSlotFillAlpha = 5008u;
    constexpr std::uint32_t setSlotBorderColor = 5009u;
    constexpr std::uint32_t setSlotTopLeftOverlay = 5010u;
    constexpr std::uint32_t setSlotBottomRightOverlay = 5011u;
    constexpr std::uint32_t setSlotBottomLeftOverlay = 5012u;
    constexpr std::uint32_t spinValueChanged = 5501u;
    constexpr std::uint32_t setSpinValue = 5502u;
    constexpr std::uint32_t setSpinRange = 5503u;
    constexpr std::uint32_t getSpinRange = 5504u;
    constexpr std::uint32_t updateSpinStatus = 5505u;
    constexpr std::uint32_t setSpinStep = 5506u;
    constexpr std::uint32_t getSpinStep = 5507u;
    constexpr std::uint32_t getSpinValue = 5600u;
    constexpr std::uint32_t setRichEditContent = 6001u;
    constexpr std::uint32_t getRichEditContent = 6002u;
    constexpr std::uint32_t appendFilteredListText = 6501u;
    constexpr std::uint32_t clearFilteredList = 6502u;
    constexpr std::uint32_t setListFilter = 6503u;
    constexpr std::uint32_t openBrowser = 7001u;
    constexpr std::uint32_t updateBrowser = 7002u;
    constexpr std::uint32_t navigateBrowser = 7003u;
    constexpr std::uint32_t refreshBrowser = 7004u;
    constexpr std::uint32_t getBrowserLocation = 7005u;
    constexpr std::uint32_t menuItemActivated = 7100u;
    constexpr std::uint32_t clearMenu = 7101u;
    constexpr std::uint32_t appendMenuItem = 7102u;
    constexpr std::uint32_t activateMenuItem = 7103u;
    constexpr std::uint32_t setMenuItemEnabled = 7104u;
    constexpr std::uint32_t setMenuItemText = 7105u;
    constexpr std::uint32_t appendChatMessage = 7500u;
    constexpr std::uint32_t addChatChannel = 7501u;
    constexpr std::uint32_t setChatChannels = 7502u;
    constexpr std::uint32_t clearChatChannels = 7503u;
    constexpr std::uint32_t chatPlayerLeftClick = 7504u;
    constexpr std::uint32_t chatPlayerRightClick = 7505u;
    constexpr std::uint32_t getChatPlainText = 7508u;
    constexpr std::uint32_t getChatHyperText = 7509u;
    constexpr std::uint32_t getSelectedChatLink = 7510u;
    constexpr std::uint32_t getSelectedChatHyperText = 7511u;
    constexpr std::uint32_t getSelectedChatPlainText = 7512u;
    constexpr std::uint32_t setHyperEditContent = 7600u;
    constexpr std::uint32_t getHyperEditPlainText = 7601u;
    constexpr std::uint32_t getHyperEditHyperText = 7602u;
    constexpr std::uint32_t hyperEditSubmit = 7603u;
    constexpr std::uint32_t getHyperEditLengths = 7604u;
    constexpr std::uint32_t setHyperEditTextColor = 7606u;
    constexpr std::uint32_t setSelectedFont = 7650u;
    constexpr std::uint32_t getSelectedFont = 7651u;
    constexpr std::uint32_t selectedFontChanged = 7652u;
}
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
namespace UiControlKind {
    constexpr std::uint32_t window = 0u;
    constexpr std::uint32_t button = 1u;
    constexpr std::uint32_t text = 2u;
    constexpr std::uint32_t image = 3u;
    constexpr std::uint32_t progressBar = 4u;
    constexpr std::uint32_t scrollBar = 5u;
    constexpr std::uint32_t hyperText = 6u;
    constexpr std::uint32_t checkBox = 7u;
    constexpr std::uint32_t radioButton = 8u;
    constexpr std::uint32_t tooltip = 9u;
    constexpr std::uint32_t textList = 10u;
    constexpr std::uint32_t slider = 11u;
    constexpr std::uint32_t listItem = 12u;
    constexpr std::uint32_t edit = 13u;
    constexpr std::uint32_t slot = 14u;
    constexpr std::uint32_t miniHelp = 15u;
    constexpr std::uint32_t spinButton = 16u;
    constexpr std::uint32_t richEdit = 17u;
    constexpr std::uint32_t filteredList = 18u;
    constexpr std::uint32_t webBrowser = 19u;
    constexpr std::uint32_t minimap = 20u;
    constexpr std::uint32_t menu = 21u;
    constexpr std::uint32_t hyperTextChat = 22u;
    constexpr std::uint32_t hyperTextEdit = 23u;
    constexpr std::uint32_t fontPicker = 24u;
    constexpr std::uint32_t colorPicker = 25u;
}
}
namespace SphereUI::UiMessage {
    constexpr std::uint32_t dropToScene = 13u;
    constexpr std::uint32_t controlBindingCaptured = 15u;
    constexpr std::uint32_t dragEnter = 110u;
    constexpr std::uint32_t dragLeave = 111u;
}

namespace SphereUI::Runtime { void setTextInputActive(bool active); }
