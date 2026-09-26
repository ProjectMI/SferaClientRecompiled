#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string_view>

struct SphereUIUiSprite;
struct SphereUIWindowEvent;
enum class SphereUIUiMessage : std::uint32_t;
enum class SphereUIUiControlKind;


class SferaInterfaceCursor;
class SphereUIHost;
class SphereUIHyperTextDocument;
class SphereUIWindow;

class SphereUIHost
{
  public:
    static void registerWindow(SphereUIWindow &window);
    static void unregisterWindow(SphereUIWindow &window);
    static bool isRegistered(const SphereUIWindow *window);
    static bool isRegistered(const SphereUIWindow *window, std::uint64_t identity);
    static void forgetWindowResource(SphereUIWindow *window);
    static void copyEventHandler(SphereUIWindow *destination, const SphereUIWindow *source);
    static void unbindEventHandler(const SphereUIWindow *window);
    static bool hasEventHandler(const SphereUIWindow *window);
    static void dispatchEvent(SphereUIWindow *window, const SphereUIWindowEvent &event);
    static void saveWindowPosition(SphereUIWindow &window);
    static void showHelpPage(std::optional<std::string_view> name);
    static SphereUIHyperTextDocument *findHyperText(std::string_view name);
    static std::shared_ptr<const SphereUIUiSprite> acquireSprite(std::string_view name);
    static std::string_view localizedText(std::string_view key);
    static bool dragDropActive();
    static SferaInterfaceCursor *cursor();
    static void broadcastMessage(int group, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second, SphereUIUiControlKind kind);
};
// The application implements this port; engine widgets only depend on its contracts.
