#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

#include "config/SimpleParser.h"
#include "math/Color.h"
#include "text/Parsing.h"
#include "text/Text.h"
#include "ui/Sprite.h"
#include "ui/UiTypes.h"
#include "ui/WidgetSupport.h"
#include "ui/Window.h"
#include "ui/widgets/Controls.h"

class SferaSimpleParser;
template <class T> struct SphereUINamedValue;
struct SphereUIParserScanScope;
class SphereUIReader;

class SphereUIReader
{
    SferaSimpleParser &parser;
    const SferaParserRange &range;
    SferaParserRange saved_block{};

  public:
    SphereUIReader(SferaSimpleParser &source, const SferaParserRange &scope) : parser(source), range(scope)
    {
        parser.getBlockRange(&saved_block);
    }

    SphereUIReader(const SphereUIReader &) = delete;
    SphereUIReader &operator=(const SphereUIReader &) = delete;

    ~SphereUIReader()
    {
        parser.setBlockRange(&saved_block);
    }

    bool block(std::string_view key, SferaParserRange &result)
    {
        return parser.findBlock(key, &result, &range, 1);
    }

    bool has(std::string_view key)
    {
        return parser.findValue(key, &range);
    }

    std::string token(std::size_t index = 0u, bool quoted = false)
    {
        std::string result;
        if (quoted)
            parser.readQuotedString(index, result);
        else
            parser.readString(index, result);
        return result;
    }

    std::optional<std::string> string(std::string_view key, bool quoted = false)
    {
        if (!has(key))
            return std::nullopt;
        std::string result;
        const bool present = quoted ? parser.readQuotedString(0u, result) : parser.readString(0u, result);
        if (!present)
            return std::nullopt;
        return result;
    }

    template <class T> void integer(std::string_view key, T &value)
    {
        if (!has(key))
            return;
        const int parsed = parser.readInt(0u);
        if (!std::in_range<T>(parsed))
            throw std::out_of_range("UI integer value is outside target range");
        value = parsed;
    }

    void count(std::string_view key, std::size_t &value)
    {
        int parsed = 0;
        if (has(key) && parser.tryReadInt(0u, parsed) && parsed >= 0)
            value = parsed;
    }

    void boolean(std::string_view key, bool &value)
    {
        if (has(key))
            value = parser.readBool(0u);
    }

    bool pair(std::string_view key, int &first, int &second)
    {
        if (!has(key))
            return false;
        int values[2]{};
        if (!parser.readIntSequence(0u, values))
            return false;
        first = values[0];
        second = values[1];
        return true;
    }

    bool rectangle(std::string_view key, int &left, int &top, int &right, int &bottom)
    {
        if (!has(key))
            return false;
        int values[4]{};
        if (!parser.readIntSequence(0u, values))
            return false;
        left = values[0];
        top = values[1];
        right = values[2];
        bottom = values[3];
        return true;
    }

    void color(std::string_view key, std::uint32_t &color)
    {
        if (!has(key))
            return;
        int values[3]{};
        if (!parser.readIntSequence(0u, values))
            return;
        color = SferaColor::rgba(values[0], values[1], values[2]).argb();
    }

    void rgba(std::string_view key, std::uint32_t &color)
    {
        if (!has(key))
            return;
        int values[4]{};
        if (!parser.readIntSequence(0u, values))
            return;
        color = SferaColor::rgba(values[0], values[1], values[2], values[3]).argb();
    }

    template <std::size_t Size> void flags(std::string_view key, std::uint32_t &value, const SphereUINamedValue<std::uint32_t> (&names)[Size], bool reset = false)
    {
        if (!has(key))
            return;
        if (reset)
            value = 0u;
        for (std::size_t index = 0u; index < parser.tokenCount(); index += 2u)
        {
            const auto name = token(index);
            for (const auto &flag : names)
                if (SferaText::asciiEqual(name, flag.name))
                    value |= flag.value;
        }
    }

    void sprite(std::string_view key, SphereUIWindow &window, std::shared_ptr<const SphereUIUiSprite> &destination)
    {
        const auto name = string(key, true);
        if (!name)
            return;
        auto *owner = window.parent;
        destination = (owner == nullptr ? window : *owner).getResource(*name);
    }

    void status(std::string_view key, std::uint32_t &mode)
    {
        const auto value = string(key);
        if (value)
            mode = SferaText::asciiEqual(*value, "PERCENT") ? 1u : SferaText::asciiEqual(*value, "STYLE1") ? 2u : 0u;
    }

    void drawMethod(SphereUIWindow &window, bool own_resources = false)
    {
        const auto method = string("drawMethod");
        if (!method)
            return;
        if (SferaText::asciiEqual(*method, "NONE"))
            window.behavior_flags |= SphereUIWindowStyle::skipDrawing;
        else if (SferaText::asciiEqual(*method, "SPRITE"))
        {
            const auto name = token(1u, true);
            auto *owner = own_resources ? &window : window.parent;
            window.resource_reference = (owner == nullptr ? window : *owner).getResource(name);
        }
    }
};
struct SphereUIParserScanScope
{
    SferaSimpleParser &parser;
    SferaParserRange saved{};
    explicit SphereUIParserScanScope(SferaSimpleParser &source) : parser(source)
    {
        parser.getScanRange(&saved);
    }

    ~SphereUIParserScanScope()
    {
        parser.setScanRange(&saved);
    }
};

template <class T> struct SphereUINamedValue;
class SphereUIResourceLoader;
class SphereUIWindow;

class SphereUIResourceLoader
{
  public:
    template <class T>
    static bool loadPart(SphereUIWindow &owner, std::unique_ptr<T> &destination, SphereUIReader &reader, std::string_view key, const std::string &filename, SferaSimpleParser &parser,
                         SphereUIUiControlKind kind, std::uint32_t id);
    template <class T> static void loadNavigationButtons(T &owner, SphereUIReader &reader, const std::string &filename, SferaSimpleParser &parser, bool defaults, float interval = 0.0f);
    static SphereUIUiControlKind controlKind(std::string_view name);
    static SphereUIWindowAnimationKind animationKind(std::string_view name);
    static std::uint32_t alignmentFlag(std::string_view name);
    static void readAnimation(SphereUIReader &reader, SferaSimpleParser &parser, std::string_view key, SphereUIWindowAnimation &animation);

  private:
    template <class T, std::size_t Size> static T lookup(std::string_view name, const SphereUINamedValue<T> (&values)[Size], T fallback);
};

template <class T, std::size_t Size> T SphereUIResourceLoader::lookup(std::string_view name, const SphereUINamedValue<T> (&values)[Size], T fallback)
{
    for (const auto &entry : values)
        if (SferaText::asciiEqual(name, entry.name))
            return entry.value;
    return fallback;
}

template <class T>
bool SphereUIResourceLoader::loadPart(SphereUIWindow &owner, std::unique_ptr<T> &destination, SphereUIReader &reader, std::string_view key, const std::string &filename, SferaSimpleParser &parser,
                                      SphereUIUiControlKind kind, std::uint32_t id)
{
    SferaParserRange part{};
    if (!reader.block(key, part))
        return false;
    auto control = owner.createControl(filename, parser, part, kind, id);
    auto *typed = SphereUIWidgetSupport::typedControl<T>(control.get());
    if (control && typed == nullptr)
        throw std::logic_error("UI factory returned unexpected control type");
    if (typed)
        typed->setParent(&owner);
    control.release();
    destination.reset(typed);
    return destination != nullptr;
}

template <class T> void SphereUIResourceLoader::loadNavigationButtons(T &owner, SphereUIReader &reader, const std::string &filename, SferaSimpleParser &parser, bool defaults, float interval)
{
    constexpr std::string_view names[] = {"leftbutton", "rightbutton"};
    std::unique_ptr<SphereUIButtonCtrl> *destinations[] = {&owner.decrease_button, &owner.increase_button};
    for (std::size_t index = 0u; index < 2u; ++index)
        if (SphereUIResourceLoader::loadPart(owner, *destinations[index], reader, names[index], filename, parser, SphereUIUiControlKind::button, SphereUIDetail::wireWord(index + 1u)) && defaults)
        {
            auto *button = destinations[index]->get();
            button->button_flags |= ButtonStyle::releaseOutside | ButtonStyle::repeatWhilePressed;
            if (interval != 0.0f)
                button->repeat_interval = interval;
        }
}

inline constexpr SphereUINamedValue<std::uint32_t> buttonStyles[] = {{"LOSTCHECK", ButtonStyle::releaseOutside},
                                                                     {"NOTIFY_LB", ButtonStyle::repeatWhilePressed},
                                                                     {"SEND_QUIT", ButtonStyle::sendClose},
                                                                     {"CENTER_TEXT", ButtonStyle::centerText},
                                                                     {"SEND_HELP", ButtonStyle::showHelp}};
inline constexpr SphereUINamedValue<std::uint32_t> textAlignments[] = {{"RIGHT_X", TextAlignment::right},
                                                                       {"RIGHT_Y", TextAlignment::bottom},
                                                                       {"CENTER_X", TextAlignment::horizontalCenter},
                                                                       {"CENTER_Y", TextAlignment::verticalCenter},
                                                                       {"CENTER", TextAlignment::center},
                                                                       {"RIGHT", TextAlignment::right | TextAlignment::bottom}};
inline constexpr SphereUINamedValue<std::uint32_t> imageStyles[] = {{"NOTIFY_LB", 1u}, {"NOTIFY_FOCUS", 2u}};
inline constexpr SphereUINamedValue<std::uint32_t> textStyles[] = {{"NOTIFY_CLICK", 1u}};
