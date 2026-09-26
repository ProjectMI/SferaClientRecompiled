#pragma once

#include <bitset>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <limits>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

#include "text/HyperText.h"
#include "ui/UiTypes.h"
#include "ui/Window.h"
#include "ui/widgets/Controls.h"

struct SferaParserRange;
class SferaSimpleParser;
class SphereUIEditCtrl;
struct SphereUIWindowCloneContext;

class SphereUIEditCtrl : public SphereUIWindow
{
  public:
    SphereUIEditCtrl *asEditCtrl() noexcept override
    {
        return this;
    }
    const SphereUIEditCtrl *asEditCtrl() const noexcept override
    {
        return this;
    }
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
    void updatePassword()
    {
        if (password && password_text.size() != text.size())
            password_text.assign(text.size(), '*');
    }
    void setEditText(std::string_view value)
    {
        text.assign(value);
        updatePassword();
    }
    SphereUIEditCtrl();

    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;
    ~SphereUIEditCtrl() override;

  private:
    static void copyCloneState(SphereUIEditCtrl &target, const SphereUIEditCtrl &source, SphereUIWindowCloneContext &);
};

class SphereUIRichEditCtrl;

class SphereUIRichEditCtrl : public SphereUIWindow
{
  public:
    SphereUIRichEditCtrl *asRichEditCtrl() noexcept override
    {
        return this;
    }
    const SphereUIRichEditCtrl *asRichEditCtrl() const noexcept override
    {
        return this;
    }
    std::vector<std::string> lines{};
    std::ptrdiff_t caret_row{};
    std::ptrdiff_t caret_column{};
    std::uint64_t blink_started{};
    bool cursor_visible{};

    int cursor_width{};
    int line_height{};
    std::ptrdiff_t page_rows{};
    std::ptrdiff_t first_row{};
    std::unique_ptr<SphereUIScrollBar> scrollbar;
    SphereUIRichEditCtrl();

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
    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;
    ~SphereUIRichEditCtrl() override;

  private:
    static void copyCloneState(SphereUIRichEditCtrl &copy, const SphereUIRichEditCtrl &source, SphereUIWindowCloneContext &context);
};

class SphereUIHyperTextCtrl;
struct SphereUIHyperTextCtrlPageRequest;

struct SphereUIHyperTextCtrlPageRequest
{
    std::string name;
    bool remember{};
};

class SphereUIHyperTextCtrl : public SphereUIWindow
{
  public:
    SphereUIHyperTextCtrl *asHyperTextCtrl() noexcept override
    {
        return this;
    }
    const SphereUIHyperTextCtrl *asHyperTextCtrl() const noexcept override
    {
        return this;
    }
    std::unique_ptr<SphereUIHyperTextDocument> document;
    std::uint32_t text_format{};

    std::variant<std::monostate, SphereUIHyperTextCtrlPageRequest, std::string> pending_page;

    int maximum_scroll{};
    int scroll_position{};
    int first_line_offset{};
    int clip_offset{};
    int clip_height{};
    int previous_line_offset{};
    int previous_clip_offset{};
    int previous_clip_height{};
    std::unique_ptr<SphereUIHyperTextDocument> previous_document;
    float transition_fraction{};
    bool transition_active{};

    std::uint64_t transition_started{};
    std::unique_ptr<SphereUIScrollBar> scrollbar;
    std::deque<std::string> history{};
    std::uint32_t link_color{};
    std::uint32_t hover_color{};
    int tooltip_index{};
    bool discard_old_text{};

    SphereUIHyperTextCtrl();

    void copyHyperTextState(const SphereUIHyperTextCtrl &source, SphereUIWindowCloneContext &context);
    void queuePage(std::string_view name, bool remember);
    void queueBuffer(std::string_view buffer);
    void updateDocument(bool resize_to_content);
    void updateScroll();
    void openLink(std::string_view target);
    static std::uint32_t parseTextFormat(std::string_view name);
    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;

  private:
    static void copyDocument(std::unique_ptr<SphereUIHyperTextDocument> &destination, const std::unique_ptr<SphereUIHyperTextDocument> &source, const SphereUIWindow &owner, std::uint32_t format);

  private:
    static void copyCloneState(SphereUIHyperTextCtrl &copy, const SphereUIHyperTextCtrl &source, SphereUIWindowCloneContext &context);

  private:
    static void openExternalLink(std::string_view target, bool mail);
    static void playLinkSound();
};

class SphereUIHyperTextChatListControl;
struct SphereUIHyperTextChatListControlRenderedRow;
struct SphereUIHyperTextChatListItem;

struct SphereUIHyperTextChatListItem
{
    std::string hyper_text;
    std::string plain_text;
    std::uint32_t channel{};
    std::uint32_t color{};
    std::vector<HyperTextRun> elements;
    std::vector<SphereUIUiIndexRange> rows;
    void initialize(std::string_view text, std::uint32_t channel, std::uint32_t color);
    void layout(int width, int font);

  private:
    static void wrapLayoutRow(std::vector<HyperTextRun> &output, std::vector<SphereUIUiIndexRange> &replacement_rows, int &x, std::uint32_t &first, std::string_view separator);
    static void appendLayoutRun(std::vector<HyperTextRun> &output, int &x, int font, HyperTextRun element);
    static void flushLayoutText(std::vector<HyperTextRun> &output, int &x, int font, std::string &pending);
};

struct SphereUIHyperTextChatListControlRenderedRow
{
    std::size_t message_index{};
    std::size_t row_index{};
};

class SphereUIHyperTextChatListControl : public SphereUIWindow
{
  public:
    SphereUIHyperTextChatListControl *asHyperTextChatListControl() noexcept override
    {
        return this;
    }
    const SphereUIHyperTextChatListControl *asHyperTextChatListControl() const noexcept override
    {
        return this;
    }
    std::deque<SphereUIHyperTextChatListItem> messages{};
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
    std::unique_ptr<SphereUIScrollBar> scrollbar;

    std::vector<SphereUIHyperTextChatListControlRenderedRow> rendered_rows;
    void addMessage(std::string_view text, std::uint32_t channel, std::uint32_t color);
    void addChannel(std::uint32_t channel);
    void setChannels(std::span<const std::uint32_t> values);
    void clearChannels();
    void rebuildVisible();
    void updateParentPosition();
    bool visibleRowRange(std::size_t message, std::size_t drawn, std::size_t rows, std::size_t *first, std::size_t *last) const;
    void updateScroll(bool reset);
    void readScroll();
    std::string_view messageText(std::size_t index, bool plain) const;
    void drawElement(HyperTextRun &element, int x, int y, std::uint32_t color);
    SphereUIHyperTextChatListControl();

    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;
    void setFont(int font_id) override;

  private:
    static void cloneProperties(SphereUIHyperTextChatListControl &copy, const SphereUIHyperTextChatListControl &source, SphereUIWindowCloneContext &context);
};

class SphereUIHyperTextEditControl;

enum SphereUIHyperTextEditControlEditMode : std::size_t
{
    PlainText,
    Numeric,
    Password
};

class SphereUIHyperTextEditControl : public SphereUIWindow
{
  public:
    SphereUIHyperTextEditControl *asHyperTextEditControl() noexcept override
    {
        return this;
    }
    const SphereUIHyperTextEditControl *asHyperTextEditControl() const noexcept override
    {
        return this;
    }
    std::deque<std::string> history{};
    std::size_t history_position{};
    std::size_t maximum_history{};

    std::bitset<3> edit_modes{};
    std::string visible_text{};
    std::string hyper_text{};
    std::vector<HyperTextRun> elements{};
    std::uint32_t cursor_type{};
    std::size_t caret_position{};
    std::uint32_t blink_started{};
    bool cursor_visible{};

    SphereUIUiRect text_margins{};
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
    void drawElement(const SphereUITextExtent &point, HyperTextRun &element, std::uint32_t color, const SphereUIUiIndexRange &range);
    void historyUp();
    void historyDown();
    void submitText();
    void pasteClipboard();
    void loadHistory();
    void saveHistory() const;
    static void historyProfile(std::string &result);
    static void transformHistory(std::string &result, const std::string &source, bool decode);
    static std::size_t fitText(std::string_view text, int font, int pixels, bool reverse);
    SphereUIHyperTextEditControl();

    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;
    ~SphereUIHyperTextEditControl() override;

  private:
    static void appendPlainRun(std::vector<HyperTextRun> &destination, std::string_view text);
    static void appendEditorElement(std::vector<HyperTextRun> &destination, const HyperTextRun &element);
    static void commitEditorElements(SphereUIHyperTextEditControl &editor, std::vector<HyperTextRun> &replacement);
    static std::string editorHistoryPath(const SphereUIHyperTextEditControl &editor);

  private:
    static void cloneProperties(SphereUIHyperTextEditControl &target, const SphereUIHyperTextEditControl &source, SphereUIWindowCloneContext &);
    void appendContentRuns(const std::vector<HyperTextRun> &input, std::size_t &used, std::vector<HyperTextRun> &replacement);
    static int transformHistoryByte(std::size_t &index, bool decode, std::uint8_t byte);

  private:
    static void clipboardText(std::string &result);
};
