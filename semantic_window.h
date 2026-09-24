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

#include "semantic_types.h"

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
        std::string_view linkValue() const;
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
    class CDescriptionWindow;
    class CheckBox;
    class EditCtrl;
    class ListCtrl;
    class FilterListCtrl;
    class FontPicker;
    class HyperTextChatListControl;
    class HyperTextCtrl;
    class HyperTextEditControl;
    class ImageCtrl;
    class ListItemCtrl;
    class CMenuListControl;
    class ProgressBar;
    class RichEditCtrl;
    class ScrollBar;
    class SlotCtrl;
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
        std::string text() const { return SferaText::fromBytes(std::span(&character, 1u)); }
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
        int x;
        int y;
        int width;
        int height;
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
        void setTexture(std::string_view texture_name, const UiRect* texture_rectangle, const UiRect* sprite_rectangle);
    };

    struct UiSprite {
        std::string name;
        int width{};
        int height{};
        std::vector<SpritePart> parts;
        void drawNatural(float left, float top, std::uint32_t color) const;
        void draw(float left, float top, float right, float bottom, std::uint32_t color, float rotation = 0.0f) const;
        void setImage(std::string_view name);
        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range);
        void resetParts(std::size_t count);
        void setDescription(const struct ImageDescription& description);
    private:
        void drawParts(float left, float top, float right, float bottom, std::uint32_t color, bool natural) const;
        void drawRotated(float left, float top, float right, float bottom, std::uint32_t color, double rotation) const;
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

        std::unique_ptr<Window> createControl(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range, SphereUI::UiControlKind kind, std::uint32_t id);
        void appendChild(std::unique_ptr<Window> child);
        void appendResource(std::shared_ptr<const UiSprite> resource);
        std::shared_ptr<const UiSprite> findResource(std::string_view resource_name) const;
        std::shared_ptr<const UiSprite> getResource(std::string_view resource_name);
        void setParent(Window* new_parent);
        void setInputFocus(bool focused, bool submit_on_blur = false);
        void getAbsolutePosition(int& screen_x, int& screen_y) const;
        bool containsPoint(int screen_x, int screen_y) const;
        int childControlAt(int screen_x, int screen_y) const;
        void clearEvents();
        void queueEvent(const WindowEvent& event);
        bool pollEvent(WindowEvent& event);
        void processEvents();
        void setText(std::string_view value);
        const std::string& getText() const;
        const std::string& getHelp() const;
        void setHelp(std::string_view value);
        void setName(std::string_view value);
        Window* controlAt(std::size_t index);
        const Window* controlAt(std::size_t index) const;
        void addModalReference(Window& window);
        void beginModal(Window* owner);
        const std::string& getName() const;
        const std::string& getResourceName() const;
        void setResourceName(std::string_view value);
        virtual bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range);
        virtual std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second);
        virtual void setPosition(int x, int y);
        virtual void draw();
        virtual void handleInput(const WindowInput& input);
        virtual void setOpacity(float opacity);
        virtual bool hitTest(int screen_x, int screen_y);
        virtual void dispatchMessage(int target_group, SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second, SphereUI::UiControlKind target_kind);
        virtual void setFont(int font_id);
        virtual int getFont() const;
        virtual ButtonCtrl* asButtonCtrl() noexcept { return nullptr; }
        virtual const ButtonCtrl* asButtonCtrl() const noexcept { return nullptr; }
        virtual CDescriptionWindow* asDescriptionWindow() noexcept { return nullptr; }
        virtual const CDescriptionWindow* asDescriptionWindow() const noexcept { return nullptr; }
        virtual CheckBox* asCheckBox() noexcept { return nullptr; }
        virtual const CheckBox* asCheckBox() const noexcept { return nullptr; }
        virtual EditCtrl* asEditCtrl() noexcept { return nullptr; }
        virtual const EditCtrl* asEditCtrl() const noexcept { return nullptr; }
        virtual ListCtrl* asListCtrl() noexcept { return nullptr; }
        virtual const ListCtrl* asListCtrl() const noexcept { return nullptr; }
        virtual FilterListCtrl* asFilterListCtrl() noexcept { return nullptr; }
        virtual const FilterListCtrl* asFilterListCtrl() const noexcept { return nullptr; }
        virtual FontPicker* asFontPicker() noexcept { return nullptr; }
        virtual const FontPicker* asFontPicker() const noexcept { return nullptr; }
        virtual HyperTextChatListControl* asHyperTextChatListControl() noexcept { return nullptr; }
        virtual const HyperTextChatListControl* asHyperTextChatListControl() const noexcept { return nullptr; }
        virtual HyperTextCtrl* asHyperTextCtrl() noexcept { return nullptr; }
        virtual const HyperTextCtrl* asHyperTextCtrl() const noexcept { return nullptr; }
        virtual HyperTextEditControl* asHyperTextEditControl() noexcept { return nullptr; }
        virtual const HyperTextEditControl* asHyperTextEditControl() const noexcept { return nullptr; }
        virtual ImageCtrl* asImageCtrl() noexcept { return nullptr; }
        virtual const ImageCtrl* asImageCtrl() const noexcept { return nullptr; }
        virtual ListItemCtrl* asListItemCtrl() noexcept { return nullptr; }
        virtual const ListItemCtrl* asListItemCtrl() const noexcept { return nullptr; }
        virtual CMenuListControl* asMenuListControl() noexcept { return nullptr; }
        virtual const CMenuListControl* asMenuListControl() const noexcept { return nullptr; }
        virtual ProgressBar* asProgressBar() noexcept { return nullptr; }
        virtual const ProgressBar* asProgressBar() const noexcept { return nullptr; }
        virtual RichEditCtrl* asRichEditCtrl() noexcept { return nullptr; }
        virtual const RichEditCtrl* asRichEditCtrl() const noexcept { return nullptr; }
        virtual ScrollBar* asScrollBar() noexcept { return nullptr; }
        virtual const ScrollBar* asScrollBar() const noexcept { return nullptr; }
        virtual SlotCtrl* asSlotCtrl() noexcept { return nullptr; }
        virtual const SlotCtrl* asSlotCtrl() const noexcept { return nullptr; }
        virtual SpinButton* asSpinButton() noexcept { return nullptr; }
        virtual const SpinButton* asSpinButton() const noexcept { return nullptr; }
        virtual ToolTipCtrl* asToolTipCtrl() noexcept { return nullptr; }
        virtual const ToolTipCtrl* asToolTipCtrl() const noexcept { return nullptr; }
        virtual ~Window();

    private:
        Window& copyStateFrom(const Window& source);
    };

    class ButtonCtrl : public Window {
    public:
        ButtonCtrl* asButtonCtrl() noexcept override { return this; }
        const ButtonCtrl* asButtonCtrl() const noexcept override { return this; }
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
        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
    };

    class CheckBox : public Window {
    public:
        CheckBox* asCheckBox() noexcept override { return this; }
        const CheckBox* asCheckBox() const noexcept override { return this; }
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

        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        virtual void playClickSound();
    };

    class CDescriptionWindow : public Window {
    public:
        CDescriptionWindow* asDescriptionWindow() noexcept override { return this; }
        const CDescriptionWindow* asDescriptionWindow() const noexcept override { return this; }

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
        void showDescription(std::string_view text, const Window* source, std::uint32_t duration, bool pin);
        void requestDescription(std::string_view text, bool force, const Window* source);
        void draw() override;
        ~CDescriptionWindow() override;
    private:
        explicit CDescriptionWindow(std::in_place_t) {}
    };

    class EditCtrl : public Window {
    public:
        EditCtrl* asEditCtrl() noexcept override { return this; }
        const EditCtrl* asEditCtrl() const noexcept override { return this; }
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

        std::size_t caret_position{};
        std::size_t observed_length{};
        void updatePassword();
        void setEditText(std::string_view value);
        EditCtrl();

        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        ~EditCtrl() override;
    };

    class ListCtrl : public Window {
    public:
        ListCtrl* asListCtrl() noexcept override { return this; }
        const ListCtrl* asListCtrl() const noexcept override { return this; }
        std::ptrdiff_t visible_begin{};
        std::ptrdiff_t visible_end{};
        std::vector<UiTextRow> rows{};
        std::size_t maximum_items{};
        std::size_t write_index{};
        int maximum_scroll{};
        int line_height{};
        std::ptrdiff_t visible_capacity{};
        int vertical_offset{};
        int cropped_y{};
        bool chatlike{};
        bool format_strings{};
        bool continue_mark{};

        std::unique_ptr<ScrollBar> scrollbar;
        bool can_select{};

        std::ptrdiff_t selected_index{};
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
        void appendLine(std::string_view text, std::uint32_t color);
        void appendFormattedLine(std::string_view text, std::uint32_t color);
        void addText(std::string_view text, std::uint32_t color);
        void appendMessageText(std::string_view text, std::uint32_t color);
        bool setRowText(std::size_t index, std::string_view text);
        std::string_view rowText(std::size_t index) const;
        void clearRows();
        void removeRow(std::size_t logical_index);
        void selectRow(int index);
        void alignRow(std::size_t index, std::uint32_t flags);
        void drawSelection(int x, int y, int row_y, bool restore_viewport);
        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
    };

    class FilterListCtrl : public ListCtrl {
    public:
        FilterListCtrl* asFilterListCtrl() noexcept override { return this; }
        const FilterListCtrl* asFilterListCtrl() const noexcept override { return this; }
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
        void appendHistory(std::string_view text, std::uint32_t color, std::uint32_t mask);
        void appendFilteredText(std::string_view text, std::uint32_t packed_color);
        void applyFilter(std::uint32_t mask);
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
    };

    class FontPicker : public Window {
    public:
        FontPicker* asFontPicker() noexcept override { return this; }
        const FontPicker* asFontPicker() const noexcept override { return this; }
        std::unique_ptr<SpinButton> selector;
        std::unique_ptr<Window> preview;
        FontPicker();

        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
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
        void initialize(std::string_view text, std::uint32_t channel, std::uint32_t color);
        void layout(int width, int font);
    };

    class HyperTextChatListControl : public Window {
    public:
        HyperTextChatListControl* asHyperTextChatListControl() noexcept override { return this; }
        const HyperTextChatListControl* asHyperTextChatListControl() const noexcept override { return this; }
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
        int row_height{};
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
        void addMessage(std::string_view text, std::uint32_t channel, std::uint32_t color);
        void addChannel(std::uint32_t channel);
        void setChannels(std::span<const std::uint32_t> values);
        void clearChannels();
        void rebuildVisible();
        void updateParentPosition();
        bool visibleRowRange(std::size_t message, std::size_t drawn, std::size_t rows, std::size_t* first, std::size_t* last) const;
        void updateScroll(bool reset);
        void readScroll();
        std::string_view messageText(std::size_t index, bool plain) const;
        void drawElement(HyperTextRun& element, int x, int y, std::uint32_t color);
        HyperTextChatListControl();

        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setFont(int font_id) override;
    };

    class HyperTextCtrl : public Window {
    public:
        HyperTextCtrl* asHyperTextCtrl() noexcept override { return this; }
        const HyperTextCtrl* asHyperTextCtrl() const noexcept override { return this; }
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
        void queuePage(std::string_view name, bool remember);
        void queueBuffer(std::string_view buffer);
        void updateDocument(bool resize_to_content);
        void updateScroll();
        void openLink(std::string_view target);
        static std::uint32_t parseTextFormat(std::string_view name);
        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
    };

    class HyperTextEditControl : public Window {
    public:
        HyperTextEditControl* asHyperTextEditControl() noexcept override { return this; }
        const HyperTextEditControl* asHyperTextEditControl() const noexcept override { return this; }
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
        void setContent(std::string_view text, std::uint32_t mode = 0u);
        void insertPlainText(std::string_view text);
        void insertCharacter(std::string_view glyph);
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
        static std::size_t fitText(std::string_view text, int font, int pixels, bool reverse);
        HyperTextEditControl();

        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        ~HyperTextEditControl() override;
    };

    class ImageCtrl : public Window {
    public:
        ImageCtrl* asImageCtrl() noexcept override { return this; }
        const ImageCtrl* asImageCtrl() const noexcept override { return this; }
        std::uint32_t image_style{};
        bool interaction_active{};
        std::shared_ptr<const UiSprite> fallback_image{};
        bool rotated{};
        float rotation_radians{};
        std::uint32_t base_alpha{};
        float opacity{};
        ImageCtrl();

        void setImage(const struct ImageDescription* description);
        void setImageName(std::string_view name);
        void setRotationDegrees(float degrees);
        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setOpacity(float opacity) override;
    };

    class ListItemCtrl : public Window {
    public:
        ListItemCtrl* asListItemCtrl() noexcept override { return this; }
        const ListItemCtrl* asListItemCtrl() const noexcept override { return this; }
        std::unique_ptr<Window> item_template;
        std::vector<std::unique_ptr<Window>> items;
        int horizontal_offset{};
        int vertical_offset{};
        std::ptrdiff_t visible_begin{};
        std::ptrdiff_t visible_end{};
        std::ptrdiff_t visible_capacity{};
        int cropped_x{};
        int cropped_y{};
        int maximum_y{};
        int maximum_x{};
        std::unique_ptr<ScrollBar> vertical_scroll;
        std::unique_ptr<ScrollBar> horizontal_scroll;
        bool can_select{};

        std::shared_ptr<const UiSprite> selection_sprite{};
        std::ptrdiff_t selected_index{};
        bool horizontal{};
        bool user_move{};

        ListItemCtrl();

        Window* itemAt(std::size_t index) const;
        void addItem();
        void removeItem(std::size_t index);
        void clearItems();
        void updateLayout();
        void updateVisibleRange();
        void copyItemState(const ListItemCtrl& source, CloneContext& context);
        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        void setOpacity(float opacity) override;
        bool hitTest(int screen_x, int screen_y) override;
        void dispatchMessage(int target_group, SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second, SphereUI::UiControlKind target_kind) override;
    };

    class CMenuListControl : public Window {
    public:
        CMenuListControl* asMenuListControl() noexcept override { return this; }
        const CMenuListControl* asMenuListControl() const noexcept override { return this; }
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

        void addItem(std::string_view text, bool enabled);
        void clearItems();
        void closeMenu();
        void updateParentPosition();
        void keepOnScreen();
        std::size_t itemAtPoint(std::int64_t x, std::int64_t y) const;
        void drawHeader();
        void drawItem(std::size_t index, const std::shared_ptr<const UiSprite>& sprite, std::uint32_t color);
        void drawFooter();
        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
    };

    class ToolTipCtrl : public Window {
    public:
        ToolTipCtrl* asToolTipCtrl() noexcept override { return this; }
        const ToolTipCtrl* asToolTipCtrl() const noexcept override { return this; }
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
        void appendLine(std::string_view text);
        void setLine(std::uint32_t index, std::optional<std::string_view> text);
        void setLine(std::uint32_t, std::nullptr_t) = delete;
        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
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
        ProgressBar* asProgressBar() noexcept override { return this; }
        const ProgressBar* asProgressBar() const noexcept override { return this; }
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
        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
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
        RichEditCtrl* asRichEditCtrl() noexcept override { return this; }
        const RichEditCtrl* asRichEditCtrl() const noexcept override { return this; }
        std::vector<std::string> lines{};
        std::ptrdiff_t caret_row{};
        std::ptrdiff_t caret_column{};
        std::uint64_t blink_started{};
        bool cursor_visible{};

        int cursor_width{};
        int line_height{};
        std::ptrdiff_t page_rows{};
        std::ptrdiff_t first_row{};
        std::unique_ptr<ScrollBar> scrollbar;
        RichEditCtrl();

        void updateMetrics(int font_id);
        void updateScroll();
        void ensureCaretVisible();
        void moveCaret(std::uint32_t key);
        void setContent(std::string_view text);
        std::string content(std::size_t limit = std::numeric_limits<std::size_t>::max()) const;
        void insertCharacter(std::string_view glyph);
        void insertAt(std::ptrdiff_t column, std::string glyph, std::ptrdiff_t row);
        std::ptrdiff_t mergeRows(std::ptrdiff_t destination, std::ptrdiff_t source);
        void eraseCharacter(bool backward);
        void splitLine();
        void drawCaret(int left, int top);
        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        ~RichEditCtrl() override;
    };

    struct ScrollParameters {
        static constexpr std::uint32_t wire_size = 28u;
        std::uint32_t size = wire_size;
        std::uint32_t mask{};
        int minimum;
        int maximum;
        int page_step;
        int current;
        int step;
    };

    class ScrollBar : public Window {
    public:
        ScrollBar* asScrollBar() noexcept override { return this; }
        const ScrollBar* asScrollBar() const noexcept override { return this; }
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
        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
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

        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        void draw() override;
        void updateControlState() override;
        void loadControlParameters() override;
    };

    class SlotCtrl : public Window {
    public:
        SlotCtrl* asSlotCtrl() noexcept override { return this; }
        const SlotCtrl* asSlotCtrl() const noexcept override { return this; }
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

        std::int64_t press_x{};
        std::int64_t press_y{};
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

        void setItem(std::optional<std::string_view> image);
        void setItem(std::nullptr_t) = delete;
        void setItemCount(std::uint32_t count);
        void setOverlay(std::shared_ptr<const UiSprite>& destination, std::optional<std::string_view> image);
        void setOverlay(std::shared_ptr<const UiSprite>&, std::nullptr_t) = delete;
        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        bool hitTest(int screen_x, int screen_y) override;
    };

    class SpinButton : public Window {
    public:
        SpinButton* asSpinButton() noexcept override { return this; }
        const SpinButton* asSpinButton() const noexcept override { return this; }
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
        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
        std::unique_ptr<Window> cloneInto(CloneContext& context) const override;
        std::uint32_t handleMessage(SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second) override;
        void draw() override;
        void handleInput(const WindowInput& input) override;
        virtual void updateStatus();
    };

    class TextCtrl : public Window {
    public:
        std::uint32_t text_style{};
        TextCtrl();

        bool loadUi(const std::string& filename, SferaSimpleParser& parser, const SferaParserRange& range) override;
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
    SphereUI::UiControlKind controlKind(std::string_view name);
    SphereUI::WindowAnimation::Kind animationKind(std::string_view name);
    std::uint32_t alignmentFlag(std::string_view name);
}

namespace SphereUI::Runtime {
    void clipboardText(std::string& result);
    CDescriptionWindow* descriptionWindow();
    std::unique_ptr<Window> makeControl(SphereUI::UiControlKind kind);
    void broadcastMessage(Window* root, int group, SphereUI::UiMessage message, std::uint32_t first, std::uint32_t second, SphereUI::UiControlKind kind);
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

namespace SphereUI::Runtime {
    std::string_view keyName(std::uint32_t key);
    std::uint32_t scanCode(std::uint32_t virtualKey);
    std::uint32_t virtualKey(std::uint32_t scanCode);
    void setSystemCursorVisible(bool visible);
}
