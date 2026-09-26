#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <functional>
#include <list>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "chat/ChatFilter.h"
#include "text/HyperText.h"
#include "ui/Rendering.h"
#include "ui/Window.h"
#include "ui/widgets/Popups.h"

struct SphereUIUiSprite;

enum class SphereUIWindowEventHandler : std::uint8_t
{
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

struct SphereUIOptionsSession;

struct SphereUIOptionsSession
{
    uint32_t binding_slot = UINT32_MAX;
    uint32_t edited_bindings[64]{};
    uint32_t dialog_kind{};
    uint32_t graphics_page{};
    uint32_t edited_interface[9]{};
    uint32_t edited_graphics[13]{};
    uint32_t saved_interface[9]{};
    bool saved_lods_enabled{};
    float saved_lod_distance{};
    float saved_fog_distance{};
    std::uint32_t saved_field_of_view{};
    uint32_t saved_music_volume{};
    std::array<std::string, 7> labels{};
    uint32_t saved_graphics[7]{};
    std::string unknown_graphics_label;
    uint32_t saved_sound_volume{};
    std::string binding_key_name;
    uint32_t comparison_graphics_value{};
    bool binding_dialog_open{};
    std::vector<std::uint32_t> saved_chat_fonts{};
    std::vector<std::uint32_t> edited_chat_fonts{};
};

struct SphereUILocalizedTextEntry;

struct SphereUILocalizedTextEntry
{
    std::string key;
    std::string value;
};

struct SphereUISavedWindowPosition;

struct SphereUISavedWindowPosition
{
    std::string name;
    int x = 0;
    int y = 0;
};

struct SferaCursorPosition;
class SphereUIButtonCtrl;
class SphereUICDescriptionWindow;
struct SphereUIDisplayMode;
class SphereUIInterfaceManager;
struct SphereUIInterfaceManagerWindowPointerHash;

enum SphereUIInterfaceManagerOpenFlag : std::uint32_t
{
    SphereUIInterfaceManagerexplicitPosition = 1u,
    SphereUIInterfaceManagerpreserveVisibility = 2u,
    SphereUIInterfaceManagerskipOpeningAnimation = 4u,
    SphereUIInterfaceManagercenterOnScreen = 8u
};

struct SphereUIInterfaceManagerWindowPointerHash : std::equal_to<>
{
    std::size_t operator()(const SphereUIWindow *window) const noexcept
    {
        return std::hash<const SphereUIWindow *>{}(window);
    }
};

class SphereUIInterfaceManager
{
  public:
    std::string default_cursor_name;
    uint32_t overlay_alpha{};
    uint32_t cursor_kind{};
    bool ui_enabled = true;
    bool saved_ui_enabled = true;
    bool cross_enabled = true;
    bool sounds_enabled = true;
    bool description_auto_popup = true;
    bool invite_messages = true;
    SphereUICDescriptionWindow *description_control{};
    uint32_t previous_input_modifiers{};
    std::unique_ptr<SphereUIChatFilter> chat_filter{};
    bool world_interaction_enabled{};
    uint32_t world_input_buttons{};
    SphereUIOptionsSession options{};

    std::vector<std::unique_ptr<SphereUIWindow>> window_templates;
    std::vector<std::unique_ptr<SphereUIHyperTextDocument>> hypertext_documents;
    std::vector<std::shared_ptr<const SphereUIUiSprite>> sprites;
    std::vector<SphereUILocalizedTextEntry> localized_strings;
    std::list<SphereUISavedWindowPosition> saved_positions;
    std::string localizedPath(std::string_view filename);
    std::shared_ptr<const SphereUIUiSprite> sharedSprite(std::string_view name);
    std::shared_ptr<const SphereUIUiSprite> acquireSprite(std::string_view name);
    void loadSprites(const std::string &filename);
    void clearSprites()
    {
        sprites.clear();
    }
    bool loadWindowTemplates(const std::string &filename);
    SphereUIWindow *templateWindow(std::string_view name) const;
    void clearWindowTemplates()
    {
        window_templates.clear();
    }
    void loadHyperTexts();
    SphereUIHyperTextDocument *findHyperText(std::string_view name) const;
    void clearHyperTexts()
    {
        hypertext_documents.clear();
    }
    bool loadLocalizedStrings();
    std::string_view localizedValue(std::string_view key) const;
    std::string_view localizedText(std::string_view key) const;
    void clearLocalizedStrings()
    {
        localized_strings.clear();
    }
    SphereUISavedWindowPosition *savedPosition(std::string_view name, bool create);
    bool findSavedPosition(std::string_view name, SferaCursorPosition &position);
    void saveWindowPosition(SphereUIWindow &window);
    std::size_t savedPositionsSize() const;
    void writeSavedPositions(std::span<std::byte> destination) const;
    void readSavedPositions(std::span<const std::byte> source);

    bool initialized = false;
    bool drag_drop_active = false;
    bool capture_control_binding = false;
    bool tooltip_disabled = false;
    std::list<std::unique_ptr<SphereUIWindow>> windows;
    std::deque<SphereUIWindowEvent> events;

    std::unordered_set<SphereUIWindow *, SphereUIInterfaceManagerWindowPointerHash, std::equal_to<>> registered_windows;
    std::uint64_t next_registration_id = 1u;
    std::unordered_map<const SphereUIWindow *, SphereUIWindowEventHandler> event_handlers;
    std::unique_ptr<SferaInterfaceCursor> cursor;
    SphereUIWindow *help_window = nullptr;
    SphereUIWindow *load_screen = nullptr;
    std::unique_ptr<SphereUIToolTipCtrl> tooltip;
    std::string cursor_name;
    SphereUIInterfaceManager() = default;
    ~SphereUIInterfaceManager();
    SphereUIInterfaceManager(const SphereUIInterfaceManager &) = delete;
    SphereUIInterfaceManager &operator=(const SphereUIInterfaceManager &) = delete;
    void loadAllWindowTemplates();
    bool initializeResources();
    void showOptions(bool visible);
    bool prepareResources();
    void finishInitialization();
    bool shutdown();
    void clearWindows();
    void queueEvent(const SphereUIWindowEvent &event);
    bool pollEvent(SphereUIWindowEvent &event);
    SphereUIWindow *findWindow(std::string_view name, bool exact = false) const;
    SphereUIWindow *windowUnderCursor() const;
    bool hasEscapeWindow() const;
    SphereUIWindow *addTopLevelWindow(std::unique_ptr<SphereUIWindow> window);
    void raiseWindow(SphereUIWindow &window);
    void lowerWindow(SphereUIWindow &window);
    void collectCoveredWindows(SphereUIWindow &window);
    SphereUIWindow *openWindow(std::string_view name, int x = 0, int y = 0, std::uint32_t flags = 0u);
    void closeWindow(SphereUIWindow *window, bool animated = true);
    void showHelpPage(std::optional<std::string_view> name);
    void showHelpPage(std::nullptr_t) = delete;
    void setTooltipText(std::optional<std::string_view> text);
    void setTooltipText(std::nullptr_t) = delete;
    void setCursorKind(std::uint32_t kind, int x, int y);
    void setCursorImage(std::optional<std::string_view> texture, int x, int y);
    void setCursorImage(std::nullptr_t, int, int) = delete;
    void update(std::uint8_t key = 0u, std::uint8_t character = 0u, std::uint32_t mouse_buttons = 0u, int wheel_delta = 0);
    void draw();
    std::uint32_t sendMessage(SphereUIWindow *window, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second);
    void showLoadingScreen(bool visible, int width, int height, bool english);
    void setLoadingProgress(int percent);
    void registerWindow(SphereUIWindow &window);
    void unregisterWindow(SphereUIWindow &window);
    bool isRegistered(const SphereUIWindow *window) const
    {
        return window != nullptr && registered_windows.contains(window);
    }
    bool isRegistered(const SphereUIWindow *window, std::uint64_t registration_id) const
    {
        return isRegistered(window) && window->registration_id == registration_id;
    }
    void bindEventHandler(SphereUIWindow *window, SphereUIWindowEventHandler handler);
    void copyEventHandler(SphereUIWindow *destination, const SphereUIWindow *source);
    bool hasEventHandler(const SphereUIWindow *window) const
    {
        return window != nullptr && event_handlers.contains(window);
    }
    void dispatchEvent(SphereUIWindow *window, const SphereUIWindowEvent &event);
    void unbindEventHandler(const SphereUIWindow *window)
    {
        event_handlers.erase(window);
    }

  private:
    friend struct SphereUIInterfaceManagerWindowPointerHash;

  private:
    static bool spriteNamed(std::string_view name, const std::shared_ptr<const SphereUIUiSprite> &sprite);
    static bool templateNamed(std::string_view name, const std::unique_ptr<SphereUIWindow> &window);
    static bool hyperTextNamed(std::string_view name, const std::unique_ptr<SphereUIHyperTextDocument> &document);
    static bool localizedKey(std::string_view key, const SphereUILocalizedTextEntry &entry);
    static bool positionNamed(std::string_view name, const SphereUISavedWindowPosition &position)
    {
        return position.name == name;
    }
    static float normalizedPosition(double pixel, double dimension);
    static bool matchesWindowName(std::string_view name, bool exact, const std::unique_ptr<SphereUIWindow> &window);
    static bool windowContainsCursor(const SferaCursorPosition &position, const std::unique_ptr<SphereUIWindow> &window);
    static bool handlesEscape(const std::unique_ptr<SphereUIWindow> &window);
    static bool ownsWindow(const SphereUIWindow *window, const std::unique_ptr<SphereUIWindow> &owner)
    {
        return owner.get() == window;
    }
    bool registeredEscapeWindow(const std::unique_ptr<SphereUIWindow> &candidate) const;
    static bool eventFromWindow(const SphereUIWindow *window, const SphereUIWindowEvent &event)
    {
        return event.source == window;
    }

  private:
    static void queueInterfaceRefresh();
    static SphereUIWindow *optionChild(SphereUIWindow *window, std::uint32_t index);
    static SphereUIWindow *optionControl(SphereUIWindow *window, std::uint32_t control_id);
    static void optionMessage(SphereUIWindow *window, std::uint32_t index, SphereUIUiMessage message, std::uint32_t first = 0u, std::uint32_t second = 0u);
    static void optionText(SphereUIWindow *window, std::uint32_t index, std::string_view text);
    static void optionLabel(SphereUIWindow *window, std::uint32_t index, std::string_view key);
    static void optionToggleLabel(SphereUIWindow *window, std::uint32_t index, std::uint32_t value);
    static SphereUIWindow *beginOptionsDialog(std::string_view name, SphereUIWindowEventHandler handler, bool show);
    static void setOptionsVisible(bool show);
    static void setSoundOptionsVisible(bool show);
    static std::uint32_t bindingCount();
    static std::string_view bindingName(std::uint32_t key);
    static SphereUIWindow *bindingRow(SphereUIWindow *window, std::uint32_t slot);
    static void refreshBindingLabel(SphereUIWindow *window, std::uint32_t slot);
    static void refreshMouseBindingLabel(SphereUIWindow *window);
    static bool availableBinding(std::uint32_t key);
    static void setControlOptionsVisible(bool show);
    static void setInterfaceOptionsVisible(bool show);
    static void resetSavedWindowPositions();
    static std::vector<std::uint32_t> &savedChatFonts();
    static std::vector<std::uint32_t> &editedChatFonts();
    static void setFontOptionsVisible(bool show);
    static std::uint32_t findOptionsMode(const SphereUIDisplayMode &requested);
    static void setOptionsModeLabel(SphereUIWindow *window, std::uint32_t index);
    static std::string_view graphicsBooleanLabel(std::uint32_t value);
    static void optionSelection(SphereUIWindow *window, std::uint32_t index, std::uint32_t maximum, std::uint32_t value);
    static void setupLodOptions(SphereUIWindow *window);
    static void setupFogOptions(SphereUIWindow *window);
    static void updateFovLabel(SphereUIWindow *window);
    static void addFovControls(SphereUIWindow *window);
    static void setGraphicsOptionsVisible(bool show);
    static void handleHelpEvent(SphereUIWindow *window, const SphereUIWindowEvent &event);
    static void handleSoundOptionsEvent(SphereUIWindow *window, const SphereUIWindowEvent &event);
    static void handleControlOptionsEvent(SphereUIWindow *window, const SphereUIWindowEvent &event);
    static void handleInterfaceOptionsEvent(SphereUIWindow *window, const SphereUIWindowEvent &event);
    static void handleGraphicsOptionsEvent(SphereUIWindow *window, const SphereUIWindowEvent &event);
    static void handleFontOptionsEvent(const SphereUIWindowEvent &event);
    static void invokeEventHandler(SphereUIWindowEventHandler handler, SphereUIWindow *window, const SphereUIWindowEvent &event);

  private:
    static auto makeNavigationButtonVisible(SphereUIButtonCtrl *button);
};

extern SphereUIInterfaceManager g_sfera_interface;

extern SphereUIInterfaceManager g_sfera_interface;

// UI owners must be destroyed while the VM registration tables are still alive.
