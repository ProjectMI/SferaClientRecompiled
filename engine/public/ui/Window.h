#pragma once

#include <cstddef>
#include <cstdint>
#include <deque>
#include <limits>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include "math/Color.h"
#include "text/Text.h"

struct SphereUIUiSprite;

struct SphereUIWindowAnimation;
struct SphereUIWindowAnimationPlayback;

enum class SphereUIWindowAnimationKind
{
    None,
    FadeIn,
    FadeOut,
    MoveLeft,
    MoveRight,
    MoveUp,
    MoveDown
};

enum class SphereUIWindowAnimationPhase
{
    Idle,
    Showing,
    Hiding,
    Closing
};

struct SphereUIWindowAnimation
{
    SphereUIWindowAnimationKind kind;

    float duration;
    float distance;
    float offset;
};
struct SphereUIWindowAnimationPlayback
{
    SphereUIWindowAnimation effect;
    std::uint64_t start_time{};
    float origin{};
    SphereUIWindowAnimationPhase phase{SphereUIWindowAnimationPhase::Idle};
};

class SphereUIWindow;
struct SphereUIWindowEvent;
struct SphereUIWindowInput;

struct SphereUIWindowInput
{
    int mouse_x;
    int mouse_y;
    int wheel_delta;
    std::uint32_t mouse_flags;
    std::uint32_t mouse_buttons;
    mutable std::uint8_t key_code; // Delivery consumes handled virtual keys without changing the event coordinates.
    mutable std::uint8_t character;

    std::uint32_t key_modifiers;
    std::string text() const
    {
        return SferaText::fromBytes(std::span(&character, 1u));
    }
};

enum class SphereUIUiMessage : std::uint32_t
{
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

struct SphereUIWindowEvent
{
    SphereUIWindow *source;
    std::uint32_t control_id;
    SphereUIUiMessage message;
    std::uint32_t first;
    std::uint32_t second;
};

enum class SphereUIUiControlKind
{
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

// Native window entry points used by the remaining ABI adapters.

struct SferaParserRange;
class SferaSimpleParser;
class SphereUIButtonCtrl;
class SphereUICDescriptionWindow;
class SphereUICMenuListControl;
class SphereUICheckBox;
class SphereUIEditCtrl;
class SphereUIFilterListCtrl;
class SphereUIFontPicker;
class SphereUIHyperTextChatListControl;
class SphereUIHyperTextCtrl;
class SphereUIHyperTextEditControl;
class SphereUIImageCtrl;
class SphereUIListCtrl;
class SphereUIListItemCtrl;
class SphereUIProgressBar;
class SphereUIRichEditCtrl;
class SphereUIScrollBar;
class SphereUISlotCtrl;
class SphereUISpinButton;
class SphereUIToolTipCtrl;
struct SphereUIWindowCloneContext;
class SphereUIWindowStyle;

enum SphereUIWindowAlignment : std::uint32_t
{
    SphereUIalignLeft = 1u << 1,
    SphereUIalignCenterX = 1u << 2,
    SphereUIalignRight = 1u << 3,
    SphereUIalignTop = 1u << 4,
    SphereUIalignCenterY = 1u << 5,
    SphereUIalignBottom = 1u << 6
};

class SphereUIWindow
{
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
    SphereUIUiControlKind control_kind{};
    std::string text;
    std::string help;
    int font{};
    bool font_initialized{};
    std::uint32_t text_color{};
    bool drag_over{};
    std::uint32_t disabled_color{};
    SphereUIWindow *parent{};
    std::vector<std::unique_ptr<SphereUIWindow>> children;
    std::vector<SphereUIWindow *> modal_references;
    SphereUIWindow *modal_owner{};
    std::deque<SphereUIWindowEvent> events;
    std::uint32_t control_id{};
    std::uint32_t alpha{};
    bool close_completed{};

    int text_offset_x{};
    int text_offset_y{};
    std::unique_ptr<SphereUIToolTipCtrl> tooltip;
    SphereUIWindow *overlay{};
    SphereUIWindow *resource_parent{};
    int caption_left{};
    int caption_top{};
    int caption_right{};
    int caption_bottom{};
    bool dragging{};

    int drag_offset_x{};
    int drag_offset_y{};
    std::uint32_t text_alignment{};
    bool hide_after_animation{};

    SphereUIWindowAnimation show_animation{};
    SphereUIWindowAnimation hide_animation{};

    std::optional<SphereUIWindowAnimationPlayback> animation;
    bool isAnimating() const noexcept
    {
        return animation.has_value();
    }
    std::vector<std::shared_ptr<const SphereUIUiSprite>> resources;
    std::string resource_name;
    std::shared_ptr<const SphereUIUiSprite> resource_reference{};
    SphereUIWindow();
    SphereUIWindow(const SphereUIWindow &) = delete;
    SphereUIWindow &operator=(const SphereUIWindow &) = delete;

    std::unique_ptr<SphereUIWindow> clone() const;
    virtual std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const;
    void initializeCopy(const SphereUIWindow &source, SphereUIWindowCloneContext &context);
    void resetToolTips();
    void alignToScreen(bool reset_position);
    void applyAnimation(const SphereUIWindowAnimationPlayback &playback, float fraction);
    void updateAnimation();
    void startAnimation(SphereUIWindowAnimationPhase phase);
    void beginClose(bool animated);
    void animateVisibility(bool hide);
    void drawToolTips();

    std::unique_ptr<SphereUIWindow> createControl(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range, SphereUIUiControlKind kind, std::uint32_t id);
    void appendChild(std::unique_ptr<SphereUIWindow> child);
    void appendResource(std::shared_ptr<const SphereUIUiSprite> resource);
    std::shared_ptr<const SphereUIUiSprite> findResource(std::string_view resource_name) const;
    std::shared_ptr<const SphereUIUiSprite> getResource(std::string_view resource_name);
    void setParent(SphereUIWindow *new_parent)
    {
        parent = new_parent;
    }
    void setInputFocus(bool focused, bool submit_on_blur = false);
    void getAbsolutePosition(int &screen_x, int &screen_y) const;
    bool containsPoint(int screen_x, int screen_y) const;
    int childControlAt(int screen_x, int screen_y) const;
    void clearEvents()
    {
        events.clear();
    }
    void queueEvent(const SphereUIWindowEvent &event);
    bool pollEvent(SphereUIWindowEvent &event);
    void processEvents();
    void setText(std::string_view value)
    {
        text.assign(value);
    }
    const std::string &getText() const
    {
        return text;
    }
    const std::string &getHelp() const
    {
        return help;
    }
    void setHelp(std::string_view value)
    {
        help.assign(value);
    }
    void setName(std::string_view value)
    {
        name.assign(value);
    }
    SphereUIWindow *controlAt(std::size_t index)
    {
        if (index == 0u)
            return this;
        return index <= children.size() ? children[index - 1u].get() : nullptr;
    }
    const SphereUIWindow *controlAt(std::size_t index) const
    {
        if (index == 0u)
            return this;
        return index <= children.size() ? children[index - 1u].get() : nullptr;
    }
    void addModalReference(SphereUIWindow &window)
    {
        modal_references.push_back(&window);
    }
    void beginModal(SphereUIWindow *owner);
    const std::string &getName() const
    {
        return name;
    }
    const std::string &getResourceName() const
    {
        return resource_name;
    }
    void setResourceName(std::string_view value)
    {
        resource_name.assign(value);
    }
    virtual bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range);
    virtual std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second);
    virtual void setPosition(int new_x, int new_y)
    {
        x = new_x;
        y = new_y;
    }
    virtual void draw();
    virtual void handleInput(const SphereUIWindowInput &input);
    virtual void setOpacity(float opacity);
    virtual bool hitTest(int screen_x, int screen_y);
    virtual void dispatchMessage(int target_group, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second, SphereUIUiControlKind target_kind);
    virtual void setFont(int font_id)
    {
        font = font_id;
    }
    virtual int getFont() const
    {
        return font;
    }
    virtual SphereUIButtonCtrl *asButtonCtrl() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIButtonCtrl *asButtonCtrl() const noexcept
    {
        return nullptr;
    }
    virtual SphereUICDescriptionWindow *asDescriptionWindow() noexcept
    {
        return nullptr;
    }
    virtual const SphereUICDescriptionWindow *asDescriptionWindow() const noexcept
    {
        return nullptr;
    }
    virtual SphereUICheckBox *asCheckBox() noexcept
    {
        return nullptr;
    }
    virtual const SphereUICheckBox *asCheckBox() const noexcept
    {
        return nullptr;
    }
    virtual SphereUIEditCtrl *asEditCtrl() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIEditCtrl *asEditCtrl() const noexcept
    {
        return nullptr;
    }
    virtual SphereUIListCtrl *asListCtrl() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIListCtrl *asListCtrl() const noexcept
    {
        return nullptr;
    }
    virtual SphereUIFilterListCtrl *asFilterListCtrl() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIFilterListCtrl *asFilterListCtrl() const noexcept
    {
        return nullptr;
    }
    virtual SphereUIFontPicker *asFontPicker() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIFontPicker *asFontPicker() const noexcept
    {
        return nullptr;
    }
    virtual SphereUIHyperTextChatListControl *asHyperTextChatListControl() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIHyperTextChatListControl *asHyperTextChatListControl() const noexcept
    {
        return nullptr;
    }
    virtual SphereUIHyperTextCtrl *asHyperTextCtrl() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIHyperTextCtrl *asHyperTextCtrl() const noexcept
    {
        return nullptr;
    }
    virtual SphereUIHyperTextEditControl *asHyperTextEditControl() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIHyperTextEditControl *asHyperTextEditControl() const noexcept
    {
        return nullptr;
    }
    virtual SphereUIImageCtrl *asImageCtrl() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIImageCtrl *asImageCtrl() const noexcept
    {
        return nullptr;
    }
    virtual SphereUIListItemCtrl *asListItemCtrl() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIListItemCtrl *asListItemCtrl() const noexcept
    {
        return nullptr;
    }
    virtual SphereUICMenuListControl *asMenuListControl() noexcept
    {
        return nullptr;
    }
    virtual const SphereUICMenuListControl *asMenuListControl() const noexcept
    {
        return nullptr;
    }
    virtual SphereUIProgressBar *asProgressBar() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIProgressBar *asProgressBar() const noexcept
    {
        return nullptr;
    }
    virtual SphereUIRichEditCtrl *asRichEditCtrl() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIRichEditCtrl *asRichEditCtrl() const noexcept
    {
        return nullptr;
    }
    virtual SphereUIScrollBar *asScrollBar() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIScrollBar *asScrollBar() const noexcept
    {
        return nullptr;
    }
    virtual SphereUISlotCtrl *asSlotCtrl() noexcept
    {
        return nullptr;
    }
    virtual const SphereUISlotCtrl *asSlotCtrl() const noexcept
    {
        return nullptr;
    }
    virtual SphereUISpinButton *asSpinButton() noexcept
    {
        return nullptr;
    }
    virtual const SphereUISpinButton *asSpinButton() const noexcept
    {
        return nullptr;
    }
    virtual SphereUIToolTipCtrl *asToolTipCtrl() noexcept
    {
        return nullptr;
    }
    virtual const SphereUIToolTipCtrl *asToolTipCtrl() const noexcept
    {
        return nullptr;
    }
    virtual ~SphereUIWindow();

  private:
    SphereUIWindow &copyStateFrom(const SphereUIWindow &source);

  private:
  private:
    static bool resourceNamed(std::string_view name_to_find, const std::shared_ptr<const SphereUIUiSprite> &resource);
    void hideOwnTooltip();
    static void drawChildWindow(SphereUIWindow &child)
    {
        child.draw();
    }
    static void inputChildWindow(const SphereUIWindowInput &input, SphereUIWindow &child);
    static void setChildOpacity(float opacity, SphereUIWindow &child)
    {
        child.setOpacity(opacity);
    }
    static void dispatchChildMessage(int target_group, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second, SphereUIUiControlKind target_kind, SphereUIWindow &child);
    static void resetChildToolTips(SphereUIWindow &child)
    {
        child.resetToolTips();
    }
    static void drawChildToolTips(SphereUIWindow &child);

  private:
    static void playWindowSound(bool opening);
    static void broadcastMessage(SphereUIWindow *root, int group, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second, SphereUIUiControlKind kind);
    static int findImage(std::string_view name);
};

class SphereUIWindowStyle
{
  public:
    static constexpr std::uint32_t skipDrawing = 1u << 1u;
    static constexpr std::uint32_t showTitle = 1u << 2u;
    static constexpr std::uint32_t handleEscape = 1u << 3u;
    static constexpr std::uint32_t preventOverlap = 1u << 4u;
};

inline constexpr std::uint32_t invalidIndex = UINT32_MAX;
inline constexpr int inheritFont = -1;
inline constexpr auto anyControlKind = SphereUIUiControlKind::any;
inline constexpr int maximumScrollOffset = INT32_MAX;
inline constexpr std::uint32_t missingConfigValue = UINT32_MAX;
inline constexpr std::uint32_t dragDropStateMask = 255u;
inline constexpr std::uint32_t uiWhite = SferaColor::rgba(255u, 255u, 255u).argb();
inline constexpr std::uint32_t uiInvalidTexture = std::numeric_limits<std::uint32_t>::max();
inline constexpr std::string_view numericWhitespace = " \t\n\r\f\v";
