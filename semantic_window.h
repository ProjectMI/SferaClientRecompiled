#pragma once
#include <cstddef>
#include <cstdint>
#include <array>
#include <bitset>
#include <type_traits>
#include <string>
#include <vector>
#include <deque>
#include <memory>
#include <variant>
#include <span>
#include <string_view>
#include <optional>

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

struct SferaScreenVertex {
    float x;
    float y;
    float z;
    float rhw;
    std::uint32_t diffuse;
    std::uint32_t specular;
    float u;
    float v;
};

class SferaSimpleParser;
struct SferaParserRange;
struct SferaCursorPosition;
namespace SphereUI {
    enum class UiMessage : std::uint32_t;
    enum class UiControlKind;
    enum WindowAlignment : std::uint32_t { alignLeft = 1u << 1, alignCenterX = 1u << 2, alignRight = 1u << 3, alignTop = 1u << 4, alignCenterY = 1u << 5, alignBottom = 1u << 6 };

}

struct HyperTextGeometry {
    int x;
    int y;
    int width;
    int height;
};

struct HyperTextRun {
    struct Link {
        HyperTextGeometry bounds{};
        std::string parameters;
        std::string target;
        std::uint32_t link_kind{};
        const char* linkValue() const;
    };

    std::string text;
    std::variant<std::monostate, HyperTextGeometry, Link> content;
    bool isWrap() const { return std::holds_alternative<std::monostate>(content); }
    bool isPlain() const { return std::holds_alternative<HyperTextGeometry>(content); }
    Link* link() { return std::get_if<Link>(&content); }
    const Link* link() const { return std::get_if<Link>(&content); }
    HyperTextGeometry* geometry();
    const HyperTextGeometry* geometry() const;
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
    class ToolTipCtrl;
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

        float duration;
        float distance;
        float offset;

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

    struct SpritePart {
        std::string texture_name;
        int texture{};
        float u[4]{};
        float v[4]{};
        UiRect rectangle{};
        void setTexture(const char* texture_name, const UiRect* texture_rectangle, const UiRect* sprite_rectangle);
    };

    struct UiSprite {
        std::string name;
        int width{};
        int height{};
        std::vector<SpritePart> parts;
        void drawNatural(float left, float top, std::uint32_t color) const;
        void draw(float left, float top, float right, float bottom, std::uint32_t color, float rotation = 0.0f) const;
        void setImage(const char* name);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range);
        void resetParts(std::size_t count);
        void setDescription(const struct ImageDescription& description);
    private:
        void drawParts(float left, float top, float right, float bottom, std::uint32_t color, bool natural) const;
        void drawRotated(float left, float top, float right, float bottom, std::uint32_t color, float rotation) const;
    };

    struct UiMenuItem {
        std::string text;
        bool enabled{};
    };

    struct UiTextRow {
        std::string text;
        std::uint32_t color{};
        int offset{};
    };

    class Window {
    public:
        std::string name;
        std::uint64_t registration_id{};
        std::uint32_t behavior_flags{};
        int width{};
        int height{};
        int x{};
        int y{};
        std::uint32_t alignment_flags{};
        int group{};
        int initial_x{};
        int initial_y{};
        bool hidden{};
        bool disabled{};
        bool input_enabled{};
        bool template_instance{};
        bool can_drag_drop{};
        bool can_go_top{};
        bool save_last_position{};
        bool hit_transparent{};
        UiControlKind control_kind{};
        std::string text;
        std::string help;
        int font{};
        bool font_initialized{};
        std::uint32_t text_color{};
        bool drag_over{};
        std::uint32_t disabled_color{};
        Window* parent{};
        std::vector<std::unique_ptr<Window>> children;
        std::vector<Window*> modal_references;
        Window* modal_owner{};
        std::deque<WindowEvent> events;
        std::uint32_t control_id{};
        std::uint32_t alpha{};
        bool close_completed{};

        int text_offset_x{};
        int text_offset_y{};
        std::unique_ptr<ToolTipCtrl> tooltip;
        Window* overlay{};
        Window* resource_parent{};
        int caption_left{};
        int caption_top{};
        int caption_right{};
        int caption_bottom{};
        bool dragging{};

        int drag_offset_x{};
        int drag_offset_y{};
        std::uint32_t text_alignment{};
        bool hide_after_animation{};

        WindowAnimation show_animation{};
        WindowAnimation hide_animation{};
        struct AnimationPlayback {
            WindowAnimation effect;
            std::uint64_t start_time{};
            float origin{};
            WindowAnimation::Phase phase{WindowAnimation::Phase::Idle};
        };
        std::optional<AnimationPlayback> animation;
        bool isAnimating() const noexcept { return animation.has_value(); }
        std::vector<std::shared_ptr<const UiSprite>> resources;
        std::string resource_name;
        std::shared_ptr<const UiSprite> resource_reference{};
        Window();
        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        struct CloneContext;
        std::unique_ptr<Window> clone() const;
        virtual std::unique_ptr<Window> cloneInto(CloneContext& context) const;
        void initializeCopy(const Window& source, CloneContext& context);
        void resetToolTips();
        void alignToScreen(bool reset_position);
        void applyAnimation(const AnimationPlayback& playback, float fraction);
        void updateAnimation();
        void startAnimation(SphereUI::WindowAnimation::Phase phase);
        void beginClose(bool animated);
        void animateVisibility(bool hide);
        void drawToolTips();

        std::unique_ptr<Window> createControl(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range, SphereUI::UiControlKind kind, std::uint32_t id);
        void appendChild(std::unique_ptr<Window> child);
        void appendResource(std::shared_ptr<const UiSprite> resource);
        std::shared_ptr<const UiSprite> findResource(const char* resource_name) const;
        std::shared_ptr<const UiSprite> getResource(const char* resource_name);
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
        virtual std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second);
        virtual void setPosition(int x, int y);
        virtual void draw();
        virtual void handleInput(const WindowInput& input);
        virtual void setOpacity(float opacity);
        virtual bool hitTest(int screen_x, int screen_y);
        virtual void dispatchMessage(int target_group, SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second, SphereUI::UiControlKind target_kind);
        virtual void setFont(int font_id);
        virtual int getFont() const;
        virtual ~Window();

    private:
        Window& copyStateFrom(const Window& source);
    };

    class ButtonCtrl : public Window {
    public:
        std::uint32_t visual_state{};
        std::shared_ptr<const UiSprite> idle_image{};
        std::shared_ptr<const UiSprite> pressed_image{};
        std::shared_ptr<const UiSprite> hover_image{};
        std::uint32_t button_flags{};
        std::uint32_t hotkey{};
        std::uint64_t repeat_started_at{};
        bool pressed{};

        float repeat_interval{};
        std::uint32_t hover_color{};
        std::shared_ptr<const UiSprite> disabled_image{};
        ButtonCtrl();

        void click();
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
    };

    class CheckBox : public Window {
    public:
        std::shared_ptr<const UiSprite> unchecked_image{};
        std::shared_ptr<const UiSprite> unchecked_hover_image{};
        std::shared_ptr<const UiSprite> checked_image{};
        std::shared_ptr<const UiSprite> checked_hover_image{};
        bool checked{};
        bool hovered{};

        int image_x{};
        int image_y{};
        std::uint32_t button_flags{};
        int label_x{};
        int label_y{};
        std::uint32_t hover_color{};
        void copyCheckState(const CheckBox& source);
        CheckBox();

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        virtual void playClickSound();
    };

    class CDescriptionWindow : public Window {
    public:

        const Window* displayed_source{};
        const Window* pending_source{};
        std::uint32_t show_deadline{};
        std::uint32_t hide_deadline{};
        std::shared_ptr<const UiSprite> caption_sprite{};
        std::shared_ptr<const UiSprite> bottom_sprite{};
        std::shared_ptr<const UiSprite> left_sprite{};
        std::shared_ptr<const UiSprite> right_sprite{};
        int frame_height{};
        bool pinned{};
        CDescriptionWindow();
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;

        static CDescriptionWindow* instance();
        void close();
        void update();
        void handleEvent(const WindowEvent& event);
        SferaCursorPosition* calculatePosition(SferaCursorPosition* output) const;
        void showDescription(const char* text, const Window* source, std::uint32_t duration, bool pin);
        void requestDescription(const char* text, bool force, const Window* source);
        void draw() override;
        ~CDescriptionWindow() override;
    private:
        explicit CDescriptionWindow(std::in_place_t) {}
    };

    class EditCtrl : public Window {
    public:
        int cursor_offset_y{};
        bool numeric{};
        bool password{};

        std::size_t maximum_symbols{};
        int cursor_width{};
        std::string password_text{};
        std::uint32_t cursor_color{};
        std::uint64_t blink_started{};
        bool cursor_visible{};
        bool cursor_uses_text_color{};
        bool submit_on_blur{};

        int caret_position{};
        std::size_t observed_length{};
        void updatePassword();
        EditCtrl();

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        ~EditCtrl() override;
    };

    class ListCtrl : public Window {
    public:
        int visible_begin{};
        int visible_end{};
        std::vector<UiTextRow> rows{};
        std::size_t maximum_items{};
        std::size_t write_index{};
        int maximum_scroll{};
        int line_height{};
        int visible_capacity{};
        int vertical_offset{};
        int cropped_y{};
        bool chatlike{};
        bool format_strings{};
        bool continue_mark{};

        std::unique_ptr<ScrollBar> scrollbar;
        bool can_select{};

        int selected_index{};
        int selection_border{};
        std::uint32_t selection_color{};
        std::uint32_t selection_line_color{};
        std::uint64_t click_time{};
        bool click_pending{};

        ListCtrl();

        void copyListState(const ListCtrl& source, CloneContext& context);
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
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
    };

    class FilterListCtrl : public ListCtrl {
    public:
        std::uint32_t filter_mask{};
        struct HistoryEntry {
            std::string text;
            std::uint32_t color{};
            std::uint32_t filter{};
        };
        std::vector<HistoryEntry> history;
        std::size_t history_write{};
        FilterListCtrl();

        void clearHistory();
        void appendHistory(const char* text, std::uint32_t color, std::uint32_t mask);
        void applyFilter(std::uint32_t mask);
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
    };

    class FontPicker : public Window {
    public:
        std::unique_ptr<SpinButton> selector;
        std::unique_ptr<Window> preview;
        FontPicker();

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setFont(int font_id) override;
        int getFont() const override;
    };

    class HyperTextDocument;

    struct UiIndexRange {
        std::size_t first;
        std::size_t last;
    };

    struct HyperTextChatListItem {
        std::string hyper_text;
        std::string plain_text;
        std::uint32_t channel{};
        std::uint32_t color{};
        std::vector<HyperTextRun> elements;
        std::vector<UiIndexRange> rows;
        void initialize(const char* text, std::uint32_t channel, std::uint32_t color);
        void layout(int width, int font);
    };

    class HyperTextChatListControl : public Window {
    public:
        std::deque<HyperTextChatListItem> messages{};
        std::vector<std::size_t> visible_messages{};
        std::vector<std::uint32_t> channels{};
        std::string selected_link_text{};
        std::string selected_link_value{};
        std::string selected_plain_text{};
        std::string selected_hyper_text{};
        std::uint32_t item_link_color{};
        std::uint32_t link_color{};
        std::size_t maximum_items{};
        std::uint32_t row_height{};
        std::size_t page_rows{};
        int parent_x{};
        int parent_y{};
        std::size_t bottom_message{};
        std::size_t bottom_row{};
        std::size_t scroll_offset{};
        std::unique_ptr<ScrollBar> scrollbar;
        struct RenderedRow {
            std::size_t message_index{};
            std::size_t row_index{};
        };
        std::vector<RenderedRow> rendered_rows;
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
        void drawElement(HyperTextRun& element, int x, int y, std::uint32_t color);
        HyperTextChatListControl();

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setFont(int font_id) override;
    };

    class HyperTextCtrl : public Window {
    public:
        std::unique_ptr<HyperTextDocument> document;
        std::uint32_t text_format{};
        struct PageRequest {
            std::string name;
            bool remember{};
        };
        std::variant<std::monostate, PageRequest, std::string> pending_page;

        int maximum_scroll{};
        int scroll_position{};
        int first_line_offset{};
        int clip_offset{};
        int clip_height{};
        int previous_line_offset{};
        int previous_clip_offset{};
        int previous_clip_height{};
        std::unique_ptr<HyperTextDocument> previous_document;
        float transition_fraction{};
        bool transition_active{};

        std::uint64_t transition_started{};
        std::unique_ptr<ScrollBar> scrollbar;
        std::deque<std::string> history{};
        std::uint32_t link_color{};
        std::uint32_t hover_color{};
        int tooltip_index{};
        bool discard_old_text{};

        HyperTextCtrl();

        void copyHyperTextState(const HyperTextCtrl& source, CloneContext& context);
        void queuePage(const char* name, bool remember);
        void queueBuffer(const char* buffer, std::size_t size);
        void updateDocument(bool resize_to_content);
        void updateScroll();
        void openLink(const char* target);
        static std::uint32_t parseTextFormat(const char* name);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
    };

    class HyperTextEditControl : public Window {
    public:
        std::deque<std::string> history{};
        std::size_t history_position{};
        std::size_t maximum_history{};
        enum EditMode : std::size_t { PlainText, Numeric, Password };
        std::bitset<3> edit_modes{};
        std::string visible_text{};
        std::string hyper_text{};
        std::vector<HyperTextRun> elements{};
        std::uint32_t cursor_type{};
        std::size_t caret_position{};
        std::uint32_t blink_started{};
        bool cursor_visible{};

        UiRect text_margins{};
        std::uint32_t cursor_color{};
        std::uint32_t plain_color{};
        std::uint32_t player_link_color{};
        std::uint32_t item_link_color{};
        std::uint32_t link_color{};
        std::size_t maximum_visible_length{};
        std::size_t maximum_hyper_length{};
        std::size_t visible_first{};
        std::size_t visible_last{};
        void setContent(const char* text, std::uint32_t mode = 0u);
        void insertPlainText(const char* text);
        void insertCharacter(std::uint8_t character);
        void eraseCharacter(bool backspace);
        void moveCaret(std::uint32_t key);
        void updateVisibleStart();
        void updateVisibleEnd();
        void drawCaret();
        void drawElement(const TextExtent& point, HyperTextRun& element, std::uint32_t color, const UiIndexRange& range);
        void historyUp();
        void historyDown();
        void submitText();
        void pasteClipboard();
        void loadHistory();
        void saveHistory() const;
        static void historyProfile(std::string& result);
        static void transformHistory(std::string& result, const std::string& source, bool decode);
        static std::size_t fitText(const char* text, int font, int pixels, bool reverse);
        HyperTextEditControl();

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        ~HyperTextEditControl() override;
    };

    class ImageCtrl : public Window {
    public:
        std::uint32_t image_style{};
        bool interaction_active{};
        std::shared_ptr<const UiSprite> fallback_image{};
        bool rotated{};
        float rotation_radians{};
        std::uint32_t base_alpha{};
        float opacity{};
        ImageCtrl();

        void setImage(const struct ImageDescription* description);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setOpacity(float opacity) override;
    };

    class ListItemCtrl : public Window {
    public:
        std::unique_ptr<Window> item_template;
        std::vector<std::unique_ptr<Window>> items;
        int horizontal_offset{};
        int vertical_offset{};
        int visible_begin{};
        int visible_end{};
        int visible_capacity{};
        int cropped_x{};
        int cropped_y{};
        int maximum_y{};
        int maximum_x{};
        std::unique_ptr<ScrollBar> vertical_scroll;
        std::unique_ptr<ScrollBar> horizontal_scroll;
        bool can_select{};

        std::shared_ptr<const UiSprite> selection_sprite{};
        int selected_index{};
        bool horizontal{};
        bool user_move{};

        ListItemCtrl();

        Window* itemAt(std::size_t index) const;
        int addItem();
        void removeItem(std::size_t index);
        void clearItems();
        void updateLayout();
        void updateVisibleRange();
        void copyItemState(const ListItemCtrl& source, CloneContext& context);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setOpacity(float opacity) override;
        bool hitTest(int screen_x, int screen_y) override;
        void dispatchMessage(int target_group, SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second, SphereUI::UiControlKind target_kind) override;
    };

    class CMenuListControl : public Window {
    public:
        std::size_t maximum_items{};
        std::shared_ptr<const UiSprite> top_sprite{};
        std::shared_ptr<const UiSprite> middle_sprite{};
        std::shared_ptr<const UiSprite> hovered_sprite{};
        std::shared_ptr<const UiSprite> bottom_sprite{};
        std::uint32_t title_color{};
        std::uint32_t normal_color{};
        std::uint32_t hovered_color{};
        std::uint32_t item_disabled_color{};
        bool show_title{};

        UiRect title_margin{};
        std::uint32_t title_format{};
        UiRect item_margin{};
        std::uint32_t item_format{};
        TextExtent top_size{};
        TextExtent item_size{};
        TextExtent bottom_size{};
        int parent_screen_x{};
        int parent_screen_y{};
        int parent_width{};
        int parent_height{};
        std::vector<UiMenuItem> items{};
        std::size_t hovered_index{};
        CMenuListControl();

        void addItem(const char* text, bool enabled);
        void clearItems();
        void closeMenu();
        void updateParentPosition();
        void keepOnScreen();
        std::size_t itemAtPoint(int x, int y) const;
        void drawHeader();
        void drawItem(std::size_t index, const std::shared_ptr<const UiSprite>& sprite, std::uint32_t color);
        void drawFooter();
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
    };

    class ToolTipCtrl : public Window {
    public:
        int screen_x{};
        int screen_y{};
        bool hover_pending{};

        std::uint64_t hover_started{};
        float fade_opacity{};

        std::uint64_t fade_started{};
        std::uint32_t background_color{};
        int tooltip_width{};
        int tooltip_height{};
        bool dismissed{};

        std::vector<std::string> lines{};
        int line_height{};
        int margin_left{};
        int margin_top{};
        int margin_right{};
        int margin_bottom{};
        ToolTipCtrl();

        void reset();
        void showAt(int x, int y);
        void updateFade();
        void updateLayout();
        void appendLine(const char* text);
        void setLine(std::uint32_t index, const char* text);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
    };

    class CMinimapControl : public Window {
    public:
        CMinimapControl();

        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        void draw() override;
    };

    class ProgressBar : public Window {
    public:
        int minimum{};
        int maximum{};
        int current{};
        float progress_ratio{};
        std::uint32_t display_mode{};
        std::string status_text;
        int status_x{};
        int status_y{};
        ProgressBar();

        void initializeProgressState();
        void setProgressValue(int value);
        void setProgressRange(int new_minimum, int new_maximum);
        void refreshProgressDisplay();
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
    };

    class RadioButtonCtrl : public CheckBox {
    public:
        RadioButtonCtrl();

        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        void playClickSound() override;
    };

    class RichEditCtrl : public Window {
    public:
        std::vector<std::string> lines{};
        int caret_row{};
        int caret_column{};
        std::uint64_t blink_started{};
        bool cursor_visible{};

        int cursor_width{};
        int line_height{};
        int page_rows{};
        int first_row{};
        std::unique_ptr<ScrollBar> scrollbar;
        RichEditCtrl();

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
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        ~RichEditCtrl() override;
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
        std::shared_ptr<const UiSprite> scroll_resource{};
        int thumb_width{};
        int thumb_height{};
        int thumb_x{};
        int thumb_y{};
        std::uint32_t orientation_flags{};
        std::unique_ptr<ButtonCtrl> decrease_button;
        std::unique_ptr<ButtonCtrl> increase_button;
        float normalized_position{};
        int minimum{};
        int maximum{};
        int current{};
        int step{};
        int page_step{};
        bool dragging_thumb{};
        bool explicit_step{};
        bool notify_changes{};

        std::uint64_t repeat_started_at{};
        int track_left{};
        int track_top{};
        int track_right{};
        int track_bottom{};
        bool page_click_active{};

        ScrollBar();

        void setParameters(const struct ScrollParameters& parameters);
        void getParameters(struct ScrollParameters& parameters) const;
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        virtual void updateControlState();
        virtual void loadControlParameters();
    };

    class SliderCtrl : public ScrollBar {
    public:
        std::string value_text;
        std::uint32_t display_mode{};
        int status_x{};
        int status_y{};
        SliderCtrl();

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        void draw() override;
        void updateControlState() override;
        void loadControlParameters() override;
    };

    class SlotCtrl : public Window {
    public:
        std::shared_ptr<const UiSprite> full_sprite{};
        std::shared_ptr<const UiSprite> empty_sprite{};
        std::shared_ptr<const UiSprite> border_sprite{};
        std::uint32_t fill_alpha{};
        std::uint32_t fill_color{};
        std::uint32_t border_color{};
        int image_offset_x{};
        int image_offset_y{};
        UiSprite item_image{};
        bool show_full_background{};
        bool has_item{};

        int press_x{};
        int press_y{};
        bool left_pressed{};
        bool right_pressed{};
        bool drag_started{};

        std::string description{};
        int count_offset_x{};
        int count_offset_y{};
        std::uint32_t item_count{};
        std::shared_ptr<const UiSprite> top_left_overlay{};
        std::shared_ptr<const UiSprite> bottom_right_overlay{};
        std::shared_ptr<const UiSprite> bottom_left_overlay{};
        SlotCtrl();

        void setItem(const char* image);
        void setItemCount(std::uint32_t count);
        void setOverlay(std::shared_ptr<const UiSprite>& destination, const char* image);
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        bool hitTest(int screen_x, int screen_y) override;
    };

    class SpinButton : public Window {
    public:
        std::unique_ptr<ButtonCtrl> decrease_button;
        std::unique_ptr<ButtonCtrl> increase_button;
        int minimum{};
        int maximum{};
        int current{};
        int previous{};
        int step{};
        std::uint32_t body_index{};
        bool status_valid{};
        bool notify_changes{};
        bool update_enabled{};
        SpinButton();

        void setRange(int minimum, int maximum);
        void setCurrentValue(int value);
        void setStep(int step);
        int currentValue() const;
        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        virtual void updateStatus();
    };

    class TextCtrl : public Window {
    public:
        std::uint32_t text_style{};
        TextCtrl();

        bool loadUi(const char* filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
    };

}

// Native window entry points used by the remaining ABI adapters.
namespace SphereUI::detail {
    void enqueueWindowEvent(std::deque<WindowEvent>& events, const WindowEvent& event);
    void serializeHyperTextElements(std::span<const HyperTextRun> elements, std::string& hyper_text, std::string& plain);
    std::string escapeHyperText(std::string_view source);
    SphereUI::UiControlKind controlKind(const char* name);
    SphereUI::WindowAnimation::Kind animationKind(const char* name);
    std::uint32_t alignmentFlag(const char* name);
}

namespace SphereUI::Runtime {
    void clipboardText(std::string& result);
    CDescriptionWindow* descriptionWindow();
    std::unique_ptr<Window> makeControl(SphereUI::UiControlKind kind);
    void broadcastMessage(Window* root, int group, SphereUI::UiMessage message, std::uintptr_t first, std::uintptr_t second, SphereUI::UiControlKind kind);
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
