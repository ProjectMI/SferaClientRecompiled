#pragma once

#include <charconv>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <functional>
#include <limits>
#include <memory>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

#include "numeric/Numeric.h"
#include "ui/UiHost.h"
#include "ui/UiTypes.h"
#include "ui/Window.h"
#include "ui/widgets/Controls.h"
#include "ui/widgets/Popups.h"

struct HyperTextRun;

struct SphereUITextExtent;
struct SphereUIUiRect;
class SphereUIWidgetSupport;
struct SphereUIWindowCloneContext;

class SphereUIWidgetSupport
{
  public:
    template <class T, class... Members> static void copyProperties(T &target, const T &source, Members... members);
    template <class Integer> static bool readInteger(std::string_view &input, Integer &output, int base);
    static bool readHexColor(std::string_view text, std::uint32_t &color);
    static SphereUIUiRect windowBounds(const SphereUIWindow &window);
    static void renderLabel(const SphereUIWindow &window, std::string_view text, int x, int y, std::uint32_t color, const SphereUIUiRect &clip, int font = -1);
    static void alignedLabel(const SphereUIWindow &window, std::uint32_t color);
    template <class Row> static void appendCircular(std::vector<Row> &rows, std::size_t maximum, std::size_t &next, Row row);
    template <class T, class Copy> static std::unique_ptr<SphereUIWindow> cloneControl(const T &source, SphereUIWindowCloneContext &context, Copy copy);
    static void notifyParent(SphereUIWindow &window, SphereUIUiMessage message, std::size_t first = 0u, std::size_t second = 0u);

  public:
    template <class T> static T *typedControl(SphereUIWindow *control);

  public:
    template <class T> static void cloneOwned(std::unique_ptr<T> &destination, const std::unique_ptr<T> &source, SphereUIWindow &owner, SphereUIWindowCloneContext &context);

    static bool contains(const SphereUIUiRect &bounds, int x, int y)
    {
        return x >= bounds.left && x < bounds.right && y >= bounds.top && y < bounds.bottom;
    }

    template <class T> static void cloneNavigationButtons(T &destination, const T &source, SphereUIWindowCloneContext &context);
    static void copyScrollFields(SphereUIScrollBar &destination, const SphereUIScrollBar &source, SphereUIWindowCloneContext &context);
    static std::uint32_t opacity_alpha(double value);
    static void replace_color_alpha(std::uint32_t &color, std::uint32_t alpha);
    static void updateStatusText(std::string &text, std::uint32_t mode, double percent, int current, int range);
    static void drawChild(SphereUIWindow *address, std::uint32_t alpha);
    static void inputChild(SphereUIWindow *address, const SphereUIWindowInput &input);
    static float spriteTextureCoordinate(double pixel, int extent);
    static SphereUITextExtent hyperTextExtent(std::string_view text, int font);
    static std::size_t hyperWordEnd(std::string_view text, std::size_t first, bool controls = false);

  private:
  private:
    static bool isWordSeparator(bool controls, char character)
    {
        return character == ' ' || (controls && (character == '\t' || character == '\r' || character == '\n'));
    }
};

template <class T, class... Members> void SphereUIWidgetSupport::copyProperties(T &target, const T &source, Members... members)
{
    ((target.*members = source.*members), ...);
}
template <class Integer> bool SphereUIWidgetSupport::readInteger(std::string_view &input, Integer &output, int base)
{
    const auto first = input.find_first_not_of(numericWhitespace);
    if (first == std::string_view::npos)
        return false;
    auto digits = input.substr(first);
    const bool negative = digits.front() == '-';
    if (negative || digits.front() == '+')
        digits.remove_prefix(1u);
    const bool hex_prefix = base == 16 && digits.size() >= 2u && digits[0] == '0' && (digits[1] == 'x' || digits[1] == 'X');
    if (hex_prefix)
        digits.remove_prefix(2u);
    std::uint32_t magnitude = 0u;
    const auto result = std::from_chars(digits.data(), digits.data() + digits.size(), magnitude, base);
    // The legacy hex scanner accepts a bare 0x prefix as zero.
    if (result.ec != std::errc{} && !(hex_prefix && result.ec == std::errc::invalid_argument))
        return false;
    const std::uint64_t maximum = std::numeric_limits<Integer>::max();
    const auto limit = maximum + (std::numeric_limits<Integer>::is_signed && negative ? 1u : 0u);
    if (magnitude > limit)
        return false;
    if constexpr (std::numeric_limits<Integer>::is_signed)
    {
        const std::int64_t signed_magnitude = magnitude;
        const std::int64_t signed_value = negative ? -signed_magnitude : signed_magnitude;
        output = SferaNumeric::signedWord(SferaNumeric::lowWord(signed_value));
    }
    else if (negative)
    {
        Integer wrapped{};
        wrapped -= magnitude;
        output = wrapped;
    }
    else
        output = magnitude;
    input.remove_prefix(result.ptr - input.data());
    return true;
}
template <class Row> void SphereUIWidgetSupport::appendCircular(std::vector<Row> &rows, std::size_t maximum, std::size_t &next, Row row)
{
    if (maximum == 0u || rows.size() < maximum)
        rows.push_back(std::move(row));
    else
        rows.at(next % rows.size()) = std::move(row);
    if (maximum != 0u)
        next = (next + 1u) % maximum;
}
template <class T, class Copy> std::unique_ptr<SphereUIWindow> SphereUIWidgetSupport::cloneControl(const T &source, SphereUIWindowCloneContext &context, Copy copy)
{
    auto result = std::make_unique<T>();
    result->initializeCopy(source, context);
    copy(*result, source, context);
    return result;
}
template <class T> T *SphereUIWidgetSupport::typedControl(SphereUIWindow *control)
{
    if (control == nullptr)
        return nullptr;
    if constexpr (std::is_same_v<T, SphereUIWindow>)
        return control;
    else if constexpr (std::is_same_v<T, SphereUIButtonCtrl>)
        return control->asButtonCtrl();
    else if constexpr (std::is_same_v<T, SphereUIScrollBar>)
        return control->asScrollBar();
    else if constexpr (std::is_same_v<T, SphereUISpinButton>)
        return control->asSpinButton();
    else
        static_assert(std::is_same_v<T, void>, "Unsupported UI control ownership type");
}
template <class T> void SphereUIWidgetSupport::cloneOwned(std::unique_ptr<T> &destination, const std::unique_ptr<T> &source, SphereUIWindow &owner, SphereUIWindowCloneContext &context)
{
    auto copy = source ? source->cloneInto(context) : nullptr;
    auto *typed = SphereUIWidgetSupport::typedControl<T>(copy.get());
    if (copy && typed == nullptr)
        throw std::logic_error("UI clone changed control type");
    if (typed)
        typed->setParent(&owner);
    copy.release();
    destination.reset(typed);
}

template <class T> void SphereUIWidgetSupport::cloneNavigationButtons(T &destination, const T &source, SphereUIWindowCloneContext &context)
{
    SphereUIWidgetSupport::cloneOwned(destination.decrease_button, source.decrease_button, destination, context);
    SphereUIWidgetSupport::cloneOwned(destination.increase_button, source.increase_button, destination, context);
}

class SphereUIDetail;

class SphereUIDetail
{
  public:
    static void serializeHyperTextElements(std::span<const HyperTextRun> elements, std::string &hyper_text, std::string &plain);
    static std::string escapeHyperText(std::string_view source);
    static void enqueueWindowEvent(std::deque<SphereUIWindowEvent> &events, const SphereUIWindowEvent &event);
    template <class Integer> static std::uint32_t wireWord(Integer value);
    static std::int32_t signedWord(std::uint32_t value) noexcept;
    template <class Integer> static int checkedInt(Integer value, std::string_view context);
    template <class Integer>
        requires std::is_integral_v<Integer>
    static double real64(Integer value) noexcept;
    template <class Left, class Right> static int multiplyCoordinate(Left left, Right right);
    template <class Left, class Right> static int addCoordinate(Left left, Right right);
    template <class Left, class Right> static int subtractCoordinate(Left left, Right right);
    template <class Callback> static void forEachChild(const SphereUIWindow &window, Callback callback);

  private:
};

template <class Integer> std::uint32_t SphereUIDetail::wireWord(Integer value)
{
    static_assert(std::is_integral_v<Integer>);
    if constexpr (std::is_signed_v<Integer>)
    {
        if (!std::in_range<std::int32_t>(value))
            throw std::overflow_error("UI value exceeds 32-bit wire range");
    }
    else if (!std::in_range<std::uint32_t>(value))
    {
        throw std::overflow_error("UI value exceeds 32-bit wire range");
    }
    return SferaNumeric::lowWord(value);
}
template <class Integer> int SphereUIDetail::checkedInt(Integer value, std::string_view context)
{
    static_assert(std::is_integral_v<Integer>);
    if (!std::in_range<int>(value))
        throw std::overflow_error(std::string(context));
    return SferaNumeric::signedWord(SferaNumeric::lowWord(value));
}
template <class Integer>
    requires std::is_integral_v<Integer>
double SphereUIDetail::real64(Integer value) noexcept
{
    return static_cast<double>(value);
}
template <class Left, class Right> int SphereUIDetail::multiplyCoordinate(Left left, Right right)
{
    static_assert(std::is_integral_v<Left> && std::is_integral_v<Right>);
    const auto product = std::int64_t{SphereUIDetail::checkedInt(left, "UI coordinate factor exceeds int")} * SphereUIDetail::checkedInt(right, "UI coordinate factor exceeds int");
    return SphereUIDetail::checkedInt(product, "UI coordinate product exceeds int");
}
template <class Left, class Right> int SphereUIDetail::addCoordinate(Left left, Right right)
{
    static_assert(std::is_integral_v<Left> && std::is_integral_v<Right>);
    const auto sum = SphereUIDetail::wireWord(left) + SphereUIDetail::wireWord(right);
    return SphereUIDetail::signedWord(sum);
}
template <class Left, class Right> int SphereUIDetail::subtractCoordinate(Left left, Right right)
{
    static_assert(std::is_integral_v<Left> && std::is_integral_v<Right>);
    const auto difference = SphereUIDetail::wireWord(left) - SphereUIDetail::wireWord(right);
    return SphereUIDetail::signedWord(difference);
}
template <class Callback> void SphereUIDetail::forEachChild(const SphereUIWindow &window, Callback callback)
{
    const auto owner_id = window.registration_id;
    std::vector<std::pair<SphereUIWindow *, std::uint64_t>> snapshot;
    snapshot.reserve(window.children.size());
    for (const auto &child : window.children)
        if (child)
            snapshot.emplace_back(child.get(), child->registration_id);
    for (const auto &[child, identity] : snapshot)
    {
        if (!SphereUIHost::isRegistered(&window, owner_id))
            break;
        if (SphereUIHost::isRegistered(child, identity))
            callback(*child);
    }
}

struct SphereUIWindowEvent;

struct SphereUIWindowCloneContext
{
    std::unordered_map<const SphereUIWindow *, SphereUIWindow *> windows;

    template <class T>
        requires std::is_same_v<std::remove_const_t<T>, SphereUIWindow>
    T *resolve(T *source) const
    {
        if (source == nullptr)
            return nullptr;
        const auto found = windows.find(source);
        if (found != windows.end())
            return found->second;
        return SphereUIHost::isRegistered(source) ? source : nullptr;
    }

    void finish() const
    {
        for (const auto &[source, target] : windows)
        {
            target->parent = resolve(target->parent);
            target->resource_parent = resolve(target->resource_parent);
            target->modal_owner = resolve(target->modal_owner);
            target->overlay = resolve(target->overlay);
            for (auto *&reference : target->modal_references)
                reference = resolve(reference);
            std::erase(target->modal_references, nullptr);
            std::erase_if(target->events, std::bind_front(&SphereUIWindowCloneContext::resolveEvent, this));
            if (auto *description = target->asDescriptionWindow())
            {
                description->displayed_source = resolve(description->displayed_source);
                description->pending_source = resolve(description->pending_source);
            }
        }
        for (const auto &[source, target] : windows)
            target->template_instance = true;
    }

  private:
    bool resolveEvent(SphereUIWindowEvent &event) const
    {
        auto *source = event.source;
        event.source = resolve(source);
        return source != nullptr && event.source == nullptr;
    }
};
