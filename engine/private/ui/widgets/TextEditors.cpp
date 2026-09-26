#include <windows.h>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <deque>
#include <exception>
#include <functional>
#include <iterator>
#include <memory>
#include <shellapi.h>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

#include "input/Cursors.h"
#include "input/MouseInput.h"
#include "math/Color.h"
#include "numeric/Numeric.h"
#include "platform/windows/ApplicationHost.h"
#include "platform/windows/Clipboard.h"
#include "text/HyperText.h"
#include "text/Text.h"
#include "ui/Rendering.h"
#include "ui/UiHost.h"
#include "ui/UiRuntime.h"
#include "ui/UiTypes.h"
#include "ui/WidgetSupport.h"
#include "ui/Window.h"
#include "ui/widgets/Controls.h"
#include "ui/widgets/Popups.h"
#include "ui/widgets/TextEditors.h"

SphereUIEditCtrl::SphereUIEditCtrl()
{
    maximum_symbols = 256u;
    cursor_width = 5;
    cursor_color = UiColor::whiteRgb;
    cursor_visible = cursor_uses_text_color = submit_on_blur = true;
    observed_length = invalidIndex;
    hidden = input_enabled = false;
    control_kind = SphereUIUiControlKind::edit;
}

std::unique_ptr<SphereUIWindow> SphereUIEditCtrl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIEditCtrl::copyCloneState);
}

std::uint32_t SphereUIEditCtrl::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::setInputEnabled:
        setInputFocus(first != 0u, submit_on_blur);
        return 1u;
    case SphereUIUiMessage::getEditFocus:
        return input_enabled;
    case SphereUIUiMessage::moveEditCaretToEnd:
        caret_position = text.size();
        break;
    default:
        break;
    }
    return SphereUIWindow::handleMessage(message, first, second);
}

void SphereUIEditCtrl::handleInput(const SphereUIWindowInput &input)
{
    if (input_enabled)
        SphereUIRuntime::setTextInputActive(true);
    if (hidden)
        return;
    if (input_enabled)
    {
        std::string value(getText());
        caret_position = std::min(caret_position, value.size());
        if (input.character >= 32u && value.size() < maximum_symbols && (!numeric || (input.character >= '0' && input.character <= '9')))
        {
            value.insert(caret_position, input.text());
            ++caret_position;
        }
        switch (input.key_code)
        {
        case VK_BACK:
            if (caret_position > 0)
            {
                value.erase(--caret_position, 1u);
            }
            break;
        case VK_DELETE:
            if (caret_position < value.size())
                value.erase(caret_position, 1u);
            break;
        case VK_LEFT:
            if (caret_position > 0)
                --caret_position;
            break;
        case VK_RIGHT:
            if (caret_position < value.size())
                ++caret_position;
            break;
        case VK_HOME:
            caret_position = 0;
            break;
        case VK_END:
            caret_position = value.size();
            break;
        default:
            break;
        }
        if (value != getText())
            setText(value);
        observed_length = text.size();
        updatePassword();
        if (input.key_code == VK_TAB)
            SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::editTab);
        if (input.key_code == VK_RETURN)
        {
            SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::editSubmit);
        }
    }
    if ((input.mouse_flags & SphereUIMouseInput::leftPress) != 0u)
    {
        if (!containsPoint(input.mouse_x, input.mouse_y))
            setInputFocus(false, submit_on_blur);
        else if (!input_enabled)
            setInputFocus(true);
    }
}

void SphereUIEditCtrl::draw()
{
    if (hidden || (behavior_flags & SphereUIWindowStyle::skipDrawing) != 0u)
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    SphereUIViewportScope viewport(bounds);
    if (!viewport)
        return;
    if (observed_length != text.size())
        caret_position = text.size();
    caret_position = std::min(caret_position, text.size());
    updatePassword();
    const std::string_view display = password ? password_text : getText();
    const auto extent = SphereUIInterfaceRenderer::measureText(display, font, font_initialized);
    const auto prefix = display.substr(0u, caret_position);
    const auto caret_x = SphereUIInterfaceRenderer::measureText(prefix, font, font_initialized).width;
    const auto full_width = SphereUIDetail::addCoordinate(extent.width, cursor_width);
    int dx = 0, dy = extent.height < height ? (height - extent.height) / 2 : 0;
    if (full_width > width)
    {
        dx = width - full_width;
        if (caret_x < -1LL * dx)
            dx = caret_position == 0 ? 0 : cursor_width - caret_x;
    }
    else
    {
        if ((text_alignment & TextAlignment::horizontalCenter) != 0u)
            dx = (width - extent.width) / 2;
        if ((text_alignment & TextAlignment::right) != 0u)
            dx = width - full_width;
    }
    if ((text_alignment & TextAlignment::bottom) != 0u && extent.height < height)
        dy = height - extent.height;
    const auto left = SphereUIDetail::addCoordinate(bounds.left, dx), top = SphereUIDetail::addCoordinate(bounds.top, dy);
    SphereUIWidgetSupport::renderLabel(*this, display, left, top, text_color, bounds);
    const auto now = SphereUIRuntime::clockTicks();
    if (blink_started == 0u || now < blink_started)
        blink_started = now;
    const auto elapsed = now - blink_started;
    if (elapsed > 4000u)
        cursor_visible = (((elapsed - 4000u) / 4000u) & 1u) != 0u;
    if (input_enabled && cursor_visible)
    {
        if (cursor_uses_text_color)
            cursor_color = text_color;
        SphereUIWidgetSupport::renderLabel(*this, "_", SphereUIDetail::addCoordinate(left, caret_x), SphereUIDetail::addCoordinate(top, cursor_offset_y),
                                           SferaColor::fromArgb(cursor_color).withAlpha(alpha).argb(), bounds);
    }
}

SphereUIEditCtrl::~SphereUIEditCtrl()
{
    SphereUIRuntime::setTextInputActive(false);
}

void SphereUIEditCtrl::copyCloneState(SphereUIEditCtrl &target, const SphereUIEditCtrl &source, SphereUIWindowCloneContext &)
{
    SphereUIWidgetSupport::copyProperties(target, source, &SphereUIEditCtrl::cursor_offset_y, &SphereUIEditCtrl::numeric, &SphereUIEditCtrl::password, &SphereUIEditCtrl::maximum_symbols,
                                          &SphereUIEditCtrl::cursor_width, &SphereUIEditCtrl::password_text, &SphereUIEditCtrl::cursor_color, &SphereUIEditCtrl::blink_started,
                                          &SphereUIEditCtrl::cursor_visible, &SphereUIEditCtrl::cursor_uses_text_color, &SphereUIEditCtrl::submit_on_blur, &SphereUIEditCtrl::caret_position,
                                          &SphereUIEditCtrl::observed_length);
}

SphereUIRichEditCtrl::SphereUIRichEditCtrl()
{
    cursor_visible = true;
    control_kind = SphereUIUiControlKind::richEdit;
    hidden = input_enabled = false;
    lines.push_back("");
}

void SphereUIRichEditCtrl::updateMetrics(int font_id)
{
    const auto extent = SphereUIInterfaceRenderer::measureText("_", font_id, true);
    cursor_width = std::max(0, extent.width);
    line_height = std::max(1, extent.height);
    page_rows = std::max(0, height / line_height - 1);
}

void SphereUIRichEditCtrl::updateScroll()
{
    auto *scroll = scrollbar.get();
    if (scroll == nullptr)
        return;
    SphereUIScrollParameters parameters{};
    parameters.mask = ScrollField::all;
    parameters.minimum = 0;
    parameters.maximum = SphereUIDetail::checkedInt(std::max(std::ptrdiff_t{}, std::ssize(lines) - page_rows - 1), "Rich edit scroll range exceeds int");
    parameters.page_step = SphereUIDetail::checkedInt(page_rows, "Rich edit page size exceeds int");
    parameters.current = SphereUIDetail::checkedInt(first_row, "Rich edit scroll position exceeds int");
    parameters.step = 1;
    scroll->setParameters(parameters);
}

void SphereUIRichEditCtrl::ensureCaretVisible()
{
    if (lines.size() == 0u)
        lines.push_back("");
    caret_row = std::clamp(caret_row, std::ptrdiff_t{}, std::ssize(lines) - 1);
    caret_column = std::clamp<std::ptrdiff_t>(caret_column, 0, std::ssize(lines.at(caret_row)));
    first_row = std::max(std::ptrdiff_t{}, std::clamp(first_row, caret_row - std::max(std::ptrdiff_t{}, page_rows), caret_row));
    updateScroll();
}

void SphereUIRichEditCtrl::moveCaret(std::uint32_t key)
{
    ensureCaretVisible();
    const auto length = std::ssize(lines.at(caret_row));
    switch (key)
    {
    case VK_LEFT:
        if (caret_column > 0)
            --caret_column;
        else if (caret_row > 0)
            caret_column = std::ssize(lines.at(--caret_row));
        break;
    case VK_RIGHT:
        if (caret_column < length)
            ++caret_column;
        else if (caret_row + 1 < std::ssize(lines))
        {
            ++caret_row;
            caret_column = 0;
        }
        break;
    case VK_UP:
        --caret_row;
        break;
    case VK_DOWN:
        ++caret_row;
        break;
    case VK_HOME:
        caret_column = 0;
        break;
    case VK_END:
        caret_column = length;
        break;
    case VK_PRIOR:
        caret_row -= std::max(std::ptrdiff_t{1}, page_rows);
        break;
    case VK_NEXT:
        caret_row += std::max(std::ptrdiff_t{1}, page_rows);
        break;
    default:
        return;
    }
    ensureCaretVisible();
}

void SphereUIRichEditCtrl::setContent(std::string_view content_text)
{
    const auto source = content_text;
    std::vector<std::string> replacement{};
    std::string line;
    int used_width = 0;
    for (std::size_t index = 0; index < source.size(); ++index)
    {
        const auto glyph = source.substr(index, 1u);
        const auto extent = SphereUIInterfaceRenderer::measureText(glyph, font, font_initialized);
        if (glyph == "\n" || used_width + extent.width + cursor_width > width)
        {
            replacement.push_back(line);
            line.clear();
            used_width = 0;
        }
        else
        {
            line.append(glyph);
            used_width += extent.width;
        }
    }
    if (!line.empty() || replacement.size() == 0u)
        replacement.push_back(line);
    lines = std::move(replacement);
    caret_row = std::ssize(lines) - 1;
    caret_column = lines.at(caret_row).size();
    ensureCaretVisible();
}

std::string SphereUIRichEditCtrl::content(std::size_t limit) const
{
    std::string result;
    for (const auto &line : lines)
    {
        if (result.size() == limit)
            break;
        const auto count = std::min(line.size(), limit - result.size());
        result.append(line, 0, count);
        if (count < line.size())
            break;
        if (result.size() < limit)
            result.push_back('\n');
    }
    return result;
}

void SphereUIRichEditCtrl::insertAt(std::ptrdiff_t column, std::string glyph, std::ptrdiff_t row)
{
    if (glyph.size() != 1u)
        throw std::invalid_argument("Rich edit insertion requires one code unit");
    for (;;)
    {
        if (row < 0 || row >= std::ssize(lines))
        {
            lines.push_back(std::move(glyph));
            return;
        }
        std::string line_text = lines.at(row);
        line_text.insert(std::min(column, std::ssize(line_text)), glyph);
        if (line_text.size() < 2u || SphereUIInterfaceRenderer::measureText(line_text, font, font_initialized).width + cursor_width <= width)
        {
            lines.at(row).assign(line_text);
            return;
        }
        glyph.assign(line_text, line_text.size() - 1u, 1u);
        line_text.pop_back();
        lines.at(row).assign(line_text);
        ++row;
        column = 0u;
    }
}

void SphereUIRichEditCtrl::insertCharacter(std::string_view glyph)
{
    if (glyph.size() != 1u)
        throw std::invalid_argument("Rich edit insertion requires one code unit");
    ensureCaretVisible();
    const auto &row = lines.at(caret_row);
    const auto prospective = SphereUIInterfaceRenderer::measureText(row, font, font_initialized).width + SphereUIInterfaceRenderer::measureText(glyph, font, font_initialized).width + cursor_width;
    if (caret_column == std::ssize(row) && prospective >= width)
    {
        insertAt(0u, std::string(glyph), ++caret_row);
        caret_column = 1;
    }
    else
    {
        insertAt(caret_column, std::string(glyph), caret_row);
        ++caret_column;
    }
    ensureCaretVisible();
}

std::ptrdiff_t SphereUIRichEditCtrl::mergeRows(std::ptrdiff_t destination, std::ptrdiff_t source)
{
    if (destination < 0 || source < 0 || destination >= std::ssize(lines) || source >= std::ssize(lines) || destination == source)
        return 0u;
    std::string merged_text = lines.at(destination).data();
    const std::string following = lines.at(source).data();
    std::ptrdiff_t count = 0;
    for (const auto character : following)
    {
        merged_text.push_back(character);
        if (SphereUIInterfaceRenderer::measureText(merged_text, font, font_initialized).width + cursor_width > width)
        {
            merged_text.pop_back();
            break;
        }
        ++count;
    }
    lines.at(destination).assign(merged_text);
    return count;
}

void SphereUIRichEditCtrl::eraseCharacter(bool backward)
{
    ensureCaretVisible();
    std::ptrdiff_t row = caret_row;
    std::string line_text = lines.at(row);
    if (backward && caret_column > 0)
    {
        line_text.erase(--caret_column, 1u);
        lines.at(row).assign(line_text);
    }
    else if (!backward && caret_column < std::ssize(line_text))
    {
        line_text.erase(caret_column, 1u);
        lines.at(row).assign(line_text);
    }
    else
    {
        if (backward)
        {
            if (row == 0u)
                return;
            --row;
            --caret_row;
            caret_column = lines.at(row).size();
        }
        if (row + 1 >= std::ssize(lines))
            return;
        const auto transferred = mergeRows(row, row + 1u);
        std::string remainder = lines.at(row + 1u).data();
        remainder.erase(0u, transferred);
        if (remainder.empty())
            lines.erase(lines.begin() + row + 1u);
        else
            lines.at(row + 1u).assign(remainder);
    }
    ensureCaretVisible();
}

void SphereUIRichEditCtrl::splitLine()
{
    ensureCaretVisible();
    std::string line_text = lines.at(caret_row).data();
    const auto following = line_text.substr(caret_column);
    line_text.resize(caret_column);
    lines.insert(lines.begin() + caret_row + 1, following);
    lines.at(caret_row).assign(line_text);
    ++caret_row;
    caret_column = 0;
    ensureCaretVisible();
}

void SphereUIRichEditCtrl::drawCaret(int left, int top)
{
    const auto now = SphereUIRuntime::clockTicks();
    if (blink_started == 0u || now < blink_started)
        blink_started = now;
    const auto elapsed = now - blink_started;
    if (elapsed > 4000u)
        cursor_visible = (((elapsed - 4000u) / 4000u) & 1u) != 0u;
    if (!input_enabled || !cursor_visible || caret_row < 0 || caret_row >= std::ssize(lines))
        return;
    const std::string prefix(lines.at(caret_row).data(), std::clamp<std::ptrdiff_t>(caret_column, 0, std::ssize(lines.at(caret_row))));
    const auto extent = SphereUIInterfaceRenderer::measureText(prefix, font, font_initialized);
    SphereUIInterfaceRenderer::drawText("_", left + extent.width, top, text_color, font, font_initialized, SphereUIWidgetSupport::windowBounds(*this), false);
}

std::unique_ptr<SphereUIWindow> SphereUIRichEditCtrl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIRichEditCtrl::copyCloneState);
}

std::uint32_t SphereUIRichEditCtrl::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::verticalScroll:
        first_row = std::max(0, SferaNumeric::signedWord(first));
        return 1u;
    case SphereUIUiMessage::setInputEnabled:
        setInputFocus(first != 0u);
        return 1u;
    default:
        return SphereUIWindow::handleMessage(message, first, second);
    }
}

void SphereUIRichEditCtrl::draw()
{
    if (hidden || (behavior_flags & SphereUIWindowStyle::skipDrawing) != 0u)
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    {
        SphereUIViewportScope viewport(bounds);
        if (viewport)
        {
            const auto start = std::clamp(first_row, std::ptrdiff_t{}, std::ssize(lines));
            const auto finish = std::min(std::ssize(lines), start + std::max(std::ptrdiff_t{}, page_rows) + 1);
            for (auto row = start; row < finish; ++row)
                SphereUIInterfaceRenderer::drawText(lines.at(row), bounds.left, SferaNumeric::signedWord(SferaNumeric::lowWord(bounds.top + (row - start) * line_height)), text_color, font,
                                                    font_initialized, bounds, false);
            if (caret_row >= start && caret_row < finish)
                drawCaret(bounds.left, SferaNumeric::signedWord(SferaNumeric::lowWord(bounds.top + (caret_row - start) * line_height)));
        }
    }
    SphereUIWidgetSupport::drawChild(scrollbar.get(), alpha);
}

void SphereUIRichEditCtrl::handleInput(const SphereUIWindowInput &input)
{
    if (input_enabled)
        SphereUIRuntime::setTextInputActive(true);
    if (hidden)
        return;
    if (input_enabled)
    {
        if (input.character >= 32u)
            insertCharacter(input.text());
        const auto key = input.key_code;
        if (key == VK_BACK || key == VK_DELETE)
            eraseCharacter(key == VK_BACK);
        else if (key == VK_RETURN)
            splitLine();
        else if (key >= VK_PRIOR && key <= VK_DOWN)
            moveCaret(key);
        if (key == VK_BACK || key == VK_DELETE || key == VK_RETURN || (key >= VK_PRIOR && key <= VK_DOWN))
            input.key_code = 0u;
    }
    SphereUIWidgetSupport::inputChild(scrollbar.get(), input);
    if ((input.mouse_flags & SphereUIMouseInput::leftPress) != 0u)
        setInputFocus(hitTest(input.mouse_x, input.mouse_y));
}

SphereUIRichEditCtrl::~SphereUIRichEditCtrl()
{
    SphereUIRuntime::setTextInputActive(false);
}

void SphereUIRichEditCtrl::copyCloneState(SphereUIRichEditCtrl &copy, const SphereUIRichEditCtrl &source, SphereUIWindowCloneContext &context)
{
    SphereUIWidgetSupport::copyProperties(copy, source, &SphereUIRichEditCtrl::lines, &SphereUIRichEditCtrl::caret_row, &SphereUIRichEditCtrl::caret_column, &SphereUIRichEditCtrl::blink_started,
                                          &SphereUIRichEditCtrl::cursor_visible, &SphereUIRichEditCtrl::cursor_width, &SphereUIRichEditCtrl::line_height, &SphereUIRichEditCtrl::page_rows,
                                          &SphereUIRichEditCtrl::first_row);
    SphereUIWidgetSupport::cloneOwned(copy.scrollbar, source.scrollbar, copy, context);
    copy.updateMetrics(source.font);
    copy.updateScroll();
}

void SphereUIHyperTextCtrl::openExternalLink(std::string_view target, bool mail)
{
    if (target.empty())
        return;
    // ShellExecuteA is a native NUL-terminated API; materialize only at this boundary.
    const std::string native_target(target);
    ::ShellExecuteA(nullptr, "open", mail ? native_target.c_str() : "explorer", mail ? nullptr : native_target.c_str(), nullptr, SW_SHOWNORMAL);
    ::ShowWindow(SferaApplicationHost::mainWindow(), SW_MINIMIZE);
}

void SphereUIHyperTextCtrl::copyDocument(std::unique_ptr<SphereUIHyperTextDocument> &destination, const std::unique_ptr<SphereUIHyperTextDocument> &source, const SphereUIWindow &owner,
                                         std::uint32_t format)
{
    destination = source ? source->clone(owner.width - (owner.font < 2 ? 2 : 0), format, owner.font) : nullptr;
}

SphereUIHyperTextCtrl::SphereUIHyperTextCtrl()
{
    transition_fraction = 1.0f;
    link_color = UiColor::hyperLink;
    hover_color = UiColor::hyperLinkHover;
    tooltip_index = -1;
    hidden = false;
    control_kind = SphereUIUiControlKind::hyperText;
}

void SphereUIHyperTextCtrl::copyHyperTextState(const SphereUIHyperTextCtrl &source, SphereUIWindowCloneContext &context)
{
    if (this == &source)
        return;
    history = source.history;
    SphereUIHyperTextCtrl::copyDocument(document, source.document, source, source.text_format);
    SphereUIHyperTextCtrl::copyDocument(previous_document, source.previous_document, source, source.text_format);
    scrollbar.reset();
    SphereUIWidgetSupport::cloneOwned(scrollbar, source.scrollbar, *this, context);
    SphereUIWidgetSupport::copyProperties(*this, source, &SphereUIHyperTextCtrl::text_format, &SphereUIHyperTextCtrl::pending_page, &SphereUIHyperTextCtrl::maximum_scroll,
                                          &SphereUIHyperTextCtrl::scroll_position, &SphereUIHyperTextCtrl::first_line_offset, &SphereUIHyperTextCtrl::clip_offset, &SphereUIHyperTextCtrl::clip_height,
                                          &SphereUIHyperTextCtrl::previous_line_offset, &SphereUIHyperTextCtrl::previous_clip_offset, &SphereUIHyperTextCtrl::previous_clip_height,
                                          &SphereUIHyperTextCtrl::transition_fraction, &SphereUIHyperTextCtrl::transition_active, &SphereUIHyperTextCtrl::transition_started,
                                          &SphereUIHyperTextCtrl::link_color, &SphereUIHyperTextCtrl::hover_color);
    tooltip_index = -1;
    discard_old_text = source.discard_old_text;
}

std::uint32_t SphereUIHyperTextCtrl::parseTextFormat(std::string_view name)
{
    if (SferaText::asciiEqual(name, "RIGHT"))
        return 1u;
    if (SferaText::asciiEqual(name, "CENTER"))
        return 2u;
    if (SferaText::asciiEqual(name, "PARAGRAPH"))
        return 3u;
    return 0u;
}

void SphereUIHyperTextCtrl::queuePage(std::string_view page_name, bool remember)
{
    if (transition_active)
        return;
    if (page_name.empty())
    {
        pending_page = std::monostate{};
        return;
    }
    SphereUIHyperTextCtrlPageRequest request{std::string(page_name.substr(0u, 255u)), remember};
    pending_page = std::move(request);
}

void SphereUIHyperTextCtrl::queueBuffer(std::string_view buffer)
{
    if (transition_active || buffer.empty())
        return;
    pending_page = std::string(buffer);
}

void SphereUIHyperTextCtrl::updateScroll()
{
    auto *page = document.get();
    if (page == nullptr)
        return;
    scroll_position = std::clamp(scroll_position, 0, std::max(0, maximum_scroll));
    first_line_offset = 0;
    clip_offset = -scroll_position;
    clip_height = height;
    page->resetRegions();
}

void SphereUIHyperTextCtrl::updateDocument(bool resize_to_content)
{
    if (std::holds_alternative<std::monostate>(pending_page))
        return;
    const auto page_width = width - (font < 2u ? 2 : 0);
    std::unique_ptr<SphereUIHyperTextDocument> replacement;
    bool remember = false;
    if (const auto *bytes = std::get_if<std::string>(&pending_page))
    {
        replacement = std::make_unique<SphereUIHyperTextDocument>(*bytes, page_width, text_format, font);
    }
    else if (const auto *request = std::get_if<SphereUIHyperTextCtrlPageRequest>(&pending_page))
    {
        remember = request->remember;
        if (auto *source = SphereUIHost::findHyperText(request->name))
            replacement = source->clone(page_width, text_format, font);
    }
    if (replacement != nullptr)
    {
        auto *current = document.get();
        if (current != nullptr && !discard_old_text && remember && !current->name.empty())
            history.push_back(current->name);
        if (current != nullptr)
        {
            if (discard_old_text)
                document.reset();
            else
            {
                previous_document = std::move(document);
                previous_line_offset = first_line_offset;
                previous_clip_offset = clip_offset;
                previous_clip_height = clip_height;
                transition_fraction = 0.0f;
                transition_active = true;
                transition_started = SphereUIRuntime::clockTicks();
            }
            SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::hyperTextPageChanged);
            if (auto *tip = tooltip.get())
                tip->reset();
        }
        document = std::move(replacement);
        document->link_color = link_color;
        document->hover_color = hover_color;
        tooltip_index = -1;
        const auto extent = document->totalHeight();
        if (resize_to_content && extent > 0)
            height = extent;
        maximum_scroll = std::max(0, extent - height);
        scroll_position = 0;
        updateScroll();
        if (auto *scroll = scrollbar.get())
            scroll->setParameters({SphereUIScrollParameters::wire_size, ScrollField::all, 0, maximum_scroll, height, 0, document->line_height});
    }
    pending_page = std::monostate{};
}

void SphereUIHyperTextCtrl::openLink(std::string_view target)
{
    if (target.empty())
        return;
    const auto value = target;
    const auto separator = value.find(':');
    const auto scheme = value.substr(0u, separator);
    if (SferaText::asciiEqual(scheme, "HTS"))
    {
        if (separator == std::string::npos)
            return;
        const auto first = value.find_first_not_of('\\', separator + 1u);
        if (first != std::string::npos)
            queuePage(value.substr(first), true);
    }
    else
        SphereUIHyperTextCtrl::openExternalLink(value, SferaText::asciiEqual(scheme, "mailto"));
}

std::unique_ptr<SphereUIWindow> SphereUIHyperTextCtrl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIHyperTextCtrl::copyCloneState);
}

std::uint32_t SphereUIHyperTextCtrl::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::verticalScroll:
        if (document != nullptr)
        {
            scroll_position = first;
            updateScroll();
        }
        return 1u;
    case SphereUIUiMessage::previousHyperTextPage:
    case SphereUIUiMessage::firstHyperTextPage:
        if (history.size() != 0u)
        {
            if (message == SphereUIUiMessage::firstHyperTextPage)
                while (history.size() > 1u)
                    history.pop_back();
            const std::string page_name = history.at(history.size() - 1u).data();
            history.pop_back();
            queuePage(page_name, false);
        }
        return 1u;
    case SphereUIUiMessage::clearHyperTextHistory:
        history.clear();
        return 1u;
    case SphereUIUiMessage::resizeToHyperText:
        updateDocument(true);
        return 1u;
    default:
        return SphereUIWindow::handleMessage(message, first, second);
    }
}

void SphereUIHyperTextCtrl::draw()
{
    if (hidden)
        return;
    if (auto *tip = tooltip.get())
        if (!tip->hidden && tip->alpha != alpha)
            tip->setOpacity(alpha / 255.0f);
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    {
        SphereUIViewportScope viewport(bounds);
        if (viewport)
        {
            const auto fraction = std::clamp(transition_fraction, 0.0f, 1.0f);
            if (auto *page = previous_document.get())
                page->draw(bounds.left, bounds.top - previous_line_offset, previous_clip_offset, previous_clip_height, SferaNumeric::truncatedWord((1.0f - fraction) * alpha));
            if (auto *page = document.get())
                page->draw(bounds.left, bounds.top - first_line_offset, clip_offset, clip_height, SferaNumeric::truncatedWord(fraction * alpha));
        }
    }
    SphereUIWidgetSupport::drawChild(scrollbar.get(), alpha);
}

void SphereUIHyperTextCtrl::handleInput(const SphereUIWindowInput &input)
{
    updateDocument(false);
    SphereUIWidgetSupport::inputChild(scrollbar.get(), input);
    if (transition_active)
    {
        const auto now = SphereUIRuntime::clockTicks();
        const auto elapsed = now >= transition_started ? now - transition_started : 0u;
        transition_fraction = std::clamp(elapsed / 5000.0f, 0.0f, 1.0f);
        if (elapsed > 5000u)
        {
            transition_active = false;
            previous_document.reset();
        }
    }
    auto *page = document.get();
    if (page == nullptr)
        return;
    int hovered = -1;
    for (std::size_t index = 0u; index < page->tooltips.size(); ++index)
    {
        auto &region = page->tooltips.at(index);
        region.hovered = region.contains(input.mouse_x, input.mouse_y) ? 1u : 0u;
        if (region.hovered && hovered < 0)
            hovered = SferaNumeric::signedWord(SferaNumeric::lowWord(index));
    }
    if (hovered != tooltip_index)
    {
        if (auto *tip = tooltip.get())
        {
            tip->reset();
            if (hovered >= 0)
            {
                tip->setLine(0u, page->tooltips.at(hovered).target);
                tip->showAt(input.mouse_x, input.mouse_y);
            }
        }
        tooltip_index = hovered;
    }
    for (std::size_t index = 0u; index < page->links.size(); ++index)
    {
        auto &link = page->links.at(index);
        link.hovered = link.contains(input.mouse_x, input.mouse_y) ? 1u : 0u;
        if (link.hovered && (input.mouse_flags & SphereUIMouseInput::leftPress) != 0u)
        {
            openLink(link.target);
            SphereUIHyperTextCtrl::playLinkSound();
        }
    }
}

void SphereUIHyperTextCtrl::copyCloneState(SphereUIHyperTextCtrl &copy, const SphereUIHyperTextCtrl &source, SphereUIWindowCloneContext &context)
{
    copy.copyHyperTextState(source, context);
    if (copy.tooltip == nullptr)
        copy.tooltip = std::make_unique<SphereUIToolTipCtrl>();
}

void SphereUIHyperTextChatListItem::initialize(std::string_view text, std::uint32_t channel_id, std::uint32_t text_color)
{
    SphereUIHyperTextChatListItem replacement;
    replacement.hyper_text = text;
    replacement.channel = channel_id;
    replacement.color = text_color;
    SphereUIHyperTextParser::parseElements(replacement.hyper_text, replacement.elements, replacement.plain_text);
    *this = std::move(replacement);
}

SphereUIHyperTextChatListControl::SphereUIHyperTextChatListControl()
{
    control_kind = SphereUIUiControlKind::hyperTextChat;
    item_link_color = link_color = UiColor::white;
    maximum_items = 256u;
    row_height = 15;
}

std::unique_ptr<SphereUIWindow> SphereUIHyperTextChatListControl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIHyperTextChatListControl::cloneProperties);
}

void SphereUIHyperTextChatListControl::rebuildVisible()
{
    visible_messages.clear();
    rendered_rows.clear();
    for (std::size_t reverse = messages.size(); reverse != 0u; --reverse)
    {
        const auto &item = messages.at(reverse - 1u);
        for (std::size_t channel = 0u; channel < channels.size(); ++channel)
            if (channels.at(channel) == item.channel)
            {
                visible_messages.push_back(reverse - 1u);
                break;
            }
    }
    if (visible_messages.size() == 0u)
        bottom_message = bottom_row = scroll_offset = 0u;
}

std::string_view SphereUIHyperTextChatListControl::messageText(std::size_t index, bool plain) const
{
    if (index >= visible_messages.size())
        return "";
    const auto &item = messages.at(visible_messages.at(index));
    return plain ? std::string_view(item.plain_text) : std::string_view(item.hyper_text);
}

void SphereUIHyperTextChatListControl::addMessage(std::string_view message_text, std::uint32_t channel, std::uint32_t color)
{
    SphereUIHyperTextChatListItem item{};
    item.initialize(message_text, channel, color);
    item.layout(width, font);
    if (item.rows.empty())
        return;
    messages.push_back(std::move(item));
    while (messages.size() > std::max(maximum_items, std::size_t{1}))
        messages.pop_front();
    bool visible = false;
    for (std::size_t index = 0u; index < channels.size(); ++index)
        visible |= channels.at(index) == channel;
    if (visible)
        scroll_offset = 0u;
    rebuildVisible();
    updateScroll(false);
}

void SphereUIHyperTextChatListControl::addChannel(std::uint32_t channel)
{
    for (std::size_t index = 0u; index < channels.size(); ++index)
        if (channels.at(index) == channel)
            return;
    channels.push_back(channel);
    scroll_offset = 0u;
    rebuildVisible();
    updateScroll(false);
}

void SphereUIHyperTextChatListControl::setChannels(std::span<const std::uint32_t> values)
{
    channels.assign(values.begin(), values.end());
    scroll_offset = 0u;
    rebuildVisible();
    updateScroll(false);
}

void SphereUIHyperTextChatListControl::clearChannels()
{
    channels.clear();
    rebuildVisible();
    updateScroll(true);
}

void SphereUIHyperTextChatListControl::setFont(int font_id)
{
    if (font == font_id)
        return;
    SphereUIWindow::setFont(font_id);
    for (auto &item : messages)
    {
        SphereUIHyperTextChatListItem replacement;
        replacement.initialize(item.hyper_text, item.channel, item.color);
        replacement.layout(width, font);
        item = std::move(replacement);
    }
    scroll_offset = 0u;
    rebuildVisible();
    updateScroll(false);
}

void SphereUIHyperTextChatListControl::updateParentPosition()
{
    parent_x = parent_y = 0;
    if (auto *owner = parent)
        owner->getAbsolutePosition(parent_x, parent_y);
}

bool SphereUIHyperTextChatListControl::visibleRowRange(std::size_t message, std::size_t drawn, std::size_t rows, std::size_t *first, std::size_t *last) const
{
    if (message < bottom_message || rows == 0u || drawn >= page_rows)
        return false;
    const auto end = message == bottom_message ? std::min(bottom_row, rows - 1u) : rows - 1u;
    const auto available = page_rows - drawn;
    const auto start = end + 1u > available ? end + 1u - available : 0u;
    if (first != nullptr)
        *first = start;
    if (last != nullptr)
        *last = end;
    return true;
}

void SphereUIHyperTextChatListControl::updateScroll(bool reset)
{
    page_rows = std::max(height, 0) / std::max(row_height, 1);
    std::uint64_t total = 0u;
    for (std::size_t index = 0u; index < visible_messages.size(); ++index)
        total += messages.at(visible_messages.at(index)).rows.size();
    const auto maximum = std::min<std::size_t>(total > page_rows ? total - page_rows : 0u, maximumScrollOffset);
    scroll_offset = reset ? 0u : std::min(scroll_offset, maximum);
    bottom_message = bottom_row = 0u;
    auto skip = scroll_offset;
    for (std::size_t index = 0u; index < visible_messages.size(); ++index)
    {
        const auto count = messages.at(visible_messages.at(index)).rows.size();
        if (skip < count)
        {
            bottom_message = index;
            bottom_row = count - skip - 1u;
            break;
        }
        skip -= count;
    }
    if (auto *child = scrollbar.get())
        child->setParameters({SphereUIScrollParameters::wire_size, ScrollField::all, 0, SferaNumeric::signedWord(SferaNumeric::lowWord(reset ? 0u : maximum)), 1,
                              SferaNumeric::signedWord(SferaNumeric::lowWord(reset ? 0u : maximum - scroll_offset)), 1});
}

void SphereUIHyperTextChatListControl::readScroll()
{
    if (auto *child = scrollbar.get())
    {
        SphereUIScrollParameters parameters{};
        child->getParameters(parameters);
        scroll_offset = std::max(parameters.maximum - parameters.current, 0);
        updateScroll(false);
    }
}

void SphereUIHyperTextChatListControl::drawElement(HyperTextRun &element, int left, int top, std::uint32_t color)
{
    auto *geometry = element.geometry();
    if (geometry == nullptr || (!element.isPlain() && element.link() == nullptr))
        return;
    geometry->x = left - SphereUIDetail::addCoordinate(parent_x, x);
    geometry->y = top - SphereUIDetail::addCoordinate(parent_y, y);
    if (element.link() != nullptr)
    {
        const auto kind = element.link()->link_kind;
        if (kind == 1u)
            color = item_link_color;
        else if (kind == 2u)
            color = SferaColor::fromArgb(color).scaledRgb(3u, 4u).argb();
        else
            color = link_color;
    }
    const SphereUIUiRect clip{left, top, SphereUIDetail::addCoordinate(left, std::max(geometry->width, 1) - 1), SphereUIDetail::addCoordinate(top, std::max(geometry->height, 1) - 1)};
    SphereUIInterfaceRenderer::drawText(element.text, left, top, SferaColor::fromArgb(color).withAlpha(alpha).argb(), font, true, clip, false);
}

void SphereUIHyperTextChatListControl::draw()
{
    if (hidden || (behavior_flags & SphereUIWindowStyle::skipDrawing) != 0u)
        return;
    updateParentPosition();
    updateScroll(false);
    rendered_rows.clear();
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    {
        SphereUIViewportScope viewport(bounds);
        for (std::size_t item_index = bottom_message; item_index < visible_messages.size() && rendered_rows.size() < page_rows; ++item_index)
        {
            auto &item = messages.at(visible_messages.at(item_index));
            std::size_t first = 0u, last = 0u;
            if (!visibleRowRange(item_index, rendered_rows.size(), item.rows.size(), &first, &last))
                continue;
            for (std::size_t reverse = last + 1u; reverse > first; --reverse)
            {
                const auto row = reverse - 1u;
                const auto top = SphereUIDetail::subtractCoordinate(SphereUIDetail::subtractCoordinate(bounds.bottom, 1), (rendered_rows.size() + 1u) * row_height);
                rendered_rows.push_back({item_index, row});
                auto left = bounds.left;
                const auto range = item.rows.at(row);
                for (std::size_t index = range.first; index <= range.last && index < item.elements.size(); ++index)
                    if (auto *element = &item.elements.at(index))
                        if (auto *geometry = element->geometry())
                        {
                            drawElement(*element, left, top, item.color);
                            left = SphereUIDetail::addCoordinate(left, geometry->width);
                        }
            }
        }
    }
    SphereUIWidgetSupport::drawChild(scrollbar.get(), alpha);
}

void SphereUIHyperTextChatListControl::handleInput(const SphereUIWindowInput &input)
{
    if (hidden || visible_messages.size() == 0u)
        return;
    SphereUIWidgetSupport::inputChild(scrollbar.get(), input);
    updateParentPosition();
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    if (!SphereUIWidgetSupport::contains(bounds, input.mouse_x, input.mouse_y) || (input.mouse_flags & SphereUIMouseInput::anyRelease) == 0u)
        return;
    const auto row = std::max(bounds.bottom - 1 - input.mouse_y, 0) / std::max(row_height, 1);
    if (row >= rendered_rows.size())
        return;
    const auto rendered = rendered_rows.at(row);
    if (rendered.message_index >= visible_messages.size())
        return;
    auto &item = messages.at(visible_messages.at(rendered.message_index));
    if (rendered.row_index >= item.rows.size())
        return;
    const auto range = item.rows.at(rendered.row_index);
    for (std::size_t index = range.first; index <= range.last && index < item.elements.size(); ++index)
    {
        auto *element = &item.elements.at(index);
        if (element == nullptr || element->link() == nullptr)
            continue;
        auto &link = *element->link();
        const auto &rectangle = link.bounds;
        const auto local_x = input.mouse_x - bounds.left;
        const auto local_y = input.mouse_y - bounds.top;
        if (local_x < rectangle.x || local_y < rectangle.y || local_x >= rectangle.x + rectangle.width || local_y >= rectangle.y + rectangle.height)
            continue;
        if ((input.mouse_flags & SphereUIMouseInput::leftRelease) != 0u && (input.key_modifiers & 1u) != 0u)
        {
            if (auto *description = SphereUIRuntime::descriptionWindow())
                description->showDescription(link.linkValue(), 0u, 250u, false);
        }
        else if (link.link_kind == 1u && (input.mouse_flags & SphereUIMouseInput::leftRelease) != 0u)
        {
            if (auto *description = SphereUIRuntime::descriptionWindow())
                description->showDescription(link.linkValue(), 0u, 5000u, true);
        }
        else if (link.link_kind == 2u)
        {
            selected_link_text = element->text;
            selected_link_value.assign(link.linkValue());
            if ((input.mouse_flags & SphereUIMouseInput::leftRelease) != 0u)
                SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::chatPlayerLeftClick, 0u, 0u);
            else
            {
                selected_hyper_text.assign(item.hyper_text.data());
                selected_plain_text.assign(item.plain_text.data());
                SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::chatPlayerRightClick, 0u, 0u);
            }
        }
    }
}

std::uint32_t SphereUIHyperTextChatListControl::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::verticalScroll:
        readScroll();
        return 1u;
    case SphereUIUiMessage::addChatChannel:
        addChannel(first);
        return 1u;
    case SphereUIUiMessage::clearChatChannels:
        clearChannels();
        return 1u;
    default:
        return SphereUIWindow::handleMessage(message, first, second);
    }
}

void SphereUIHyperTextChatListItem::layout(int width, int font)
{
    width = std::max(width, 1);
    std::vector<HyperTextRun> output{};
    std::vector<SphereUIUiIndexRange> replacement_rows{};
    int x = 0;
    std::uint32_t first = 0u;

    for (const auto &element : elements)
    {
        if (element.isWrap())
        {
            if (element.text.size() != 0u)
                wrapLayoutRow(output, replacement_rows, x, first, std::string_view(element.text));
            continue;
        }
        if (element.link() != nullptr)
        {
            const auto extent = SphereUIWidgetSupport::hyperTextExtent(std::string_view(element.text), font);
            if (x != 0 && x + extent.width > width)
                wrapLayoutRow(output, replacement_rows, x, first, {});
            appendLayoutRun(output, x, font, element);
            continue;
        }
        if (!element.isPlain())
            continue;
        const std::string_view text(element.text);
        std::string pending;

        for (std::size_t position = 0u; position < text.size();)
        {
            const auto end = SphereUIWidgetSupport::hyperWordEnd(text, position, true);
            const auto token = text.substr(position, end - position);
            const auto combined = pending + std::string(token);
            if (x + SphereUIWidgetSupport::hyperTextExtent(combined, font).width <= width || (x == 0 && pending.empty()))
                pending = combined;
            else
            {
                flushLayoutText(output, x, font, pending);
                auto visible = token;
                const auto leading = visible.find_first_not_of(" \t\r\n");
                const auto spaces = leading == std::string_view::npos ? visible.size() : leading;
                wrapLayoutRow(output, replacement_rows, x, first, visible.substr(0u, spaces));
                visible.remove_prefix(spaces);
                pending.assign(visible);
            }
            position = end;
        }
        flushLayoutText(output, x, font, pending);
    }
    if (output.size() > first)
        replacement_rows.push_back({first, output.size() - 1u});
    elements = std::move(output);
    rows = std::move(replacement_rows);
}

void SphereUIHyperTextChatListControl::cloneProperties(SphereUIHyperTextChatListControl &copy, const SphereUIHyperTextChatListControl &source, SphereUIWindowCloneContext &context)
{
    SphereUIWidgetSupport::copyProperties(copy, source, &SphereUIHyperTextChatListControl::messages, &SphereUIHyperTextChatListControl::visible_messages, &SphereUIHyperTextChatListControl::channels,
                                          &SphereUIHyperTextChatListControl::selected_link_text, &SphereUIHyperTextChatListControl::selected_link_value,
                                          &SphereUIHyperTextChatListControl::selected_plain_text, &SphereUIHyperTextChatListControl::selected_hyper_text,
                                          &SphereUIHyperTextChatListControl::item_link_color, &SphereUIHyperTextChatListControl::link_color, &SphereUIHyperTextChatListControl::maximum_items,
                                          &SphereUIHyperTextChatListControl::row_height, &SphereUIHyperTextChatListControl::page_rows, &SphereUIHyperTextChatListControl::parent_x,
                                          &SphereUIHyperTextChatListControl::parent_y, &SphereUIHyperTextChatListControl::bottom_message, &SphereUIHyperTextChatListControl::bottom_row,
                                          &SphereUIHyperTextChatListControl::scroll_offset, &SphereUIHyperTextChatListControl::rendered_rows);
    SphereUIWidgetSupport::cloneOwned(copy.scrollbar, source.scrollbar, copy, context);
}

void SphereUIHyperTextChatListItem::wrapLayoutRow(std::vector<HyperTextRun> &output, std::vector<SphereUIUiIndexRange> &replacement_rows, int &x, std::uint32_t &first, std::string_view separator)
{
    if (output.size() > first)
        replacement_rows.push_back({first, output.size() - 1u});
    output.push_back({std::string(separator), std::monostate{}});
    first = SphereUIDetail::wireWord(output.size());
    x = 0;
}

void SphereUIHyperTextChatListItem::appendLayoutRun(std::vector<HyperTextRun> &output, int &x, int font, HyperTextRun element)
{
    if (auto *geometry = element.geometry())
    {
        const auto extent = SphereUIWidgetSupport::hyperTextExtent(std::string_view(element.text), font);
        *geometry = {x, 0, extent.width, extent.height};
        x += extent.width;
    }
    output.push_back(std::move(element));
}

void SphereUIHyperTextChatListItem::flushLayoutText(std::vector<HyperTextRun> &output, int &x, int font, std::string &pending)
{
    if (!pending.empty())
    {
        appendLayoutRun(output, x, font, {pending, HyperTextGeometry{}});
        pending.clear();
    }
}

void SphereUIHyperTextEditControl::appendPlainRun(std::vector<HyperTextRun> &destination, std::string_view text)
{
    if (text.empty())
        return;
    if (!destination.empty() && destination.back().isPlain())
        destination.back().text.append(text);
    else
        destination.push_back({std::string(text), HyperTextGeometry{}});
}

void SphereUIHyperTextEditControl::appendEditorElement(std::vector<HyperTextRun> &destination, const HyperTextRun &element)
{
    if (element.isPlain())
        SphereUIHyperTextEditControl::appendPlainRun(destination, element.text);
    else
        destination.push_back(element);
}

void SphereUIHyperTextEditControl::commitEditorElements(SphereUIHyperTextEditControl &editor, std::vector<HyperTextRun> &replacement)
{
    std::string raw, visible;
    SphereUIDetail::serializeHyperTextElements(replacement, raw, visible);
    editor.hyper_text = std::move(raw);
    editor.visible_text = std::move(visible);
    editor.elements = std::move(replacement);
}

SphereUIHyperTextEditControl::SphereUIHyperTextEditControl()
{
    maximum_history = 256u;
    cursor_type = 1u;
    cursor_visible = true;
    cursor_color = plain_color = player_link_color = item_link_color = link_color = UiColor::white;
    maximum_visible_length = 256u;
    maximum_hyper_length = 3072u;
    control_kind = SphereUIUiControlKind::hyperTextEdit;
    edit_modes.set(PlainText);
}

void SphereUIHyperTextEditControl::setContent(std::string_view content_text, std::uint32_t mode)
{
    if (mode > 1u)
        return;
    const auto source = content_text;
    if (mode == 0u && source == hyper_text)
        return;
    if (source.size() + (mode == 1u ? hyper_text.size() : 0u) > maximum_hyper_length)
        return;
    std::string plain;
    std::vector<HyperTextRun> parsed, replacement;
    SphereUIHyperTextParser::parseElements(source, parsed, plain);
    const auto added_length = plain.size();
    if (mode == 1u && (visible_text.size() > maximum_visible_length || added_length > maximum_visible_length - visible_text.size()))
        return;
    std::size_t used = 0u;

    if (mode == 1u)
        appendContentRuns(elements, used, replacement);
    appendContentRuns(parsed, used, replacement);
    SphereUIHyperTextEditControl::commitEditorElements(*this, replacement);
    moveCaret(35u);
}

void SphereUIHyperTextEditControl::insertPlainText(std::string_view plain_text)
{
    if (visible_text.size() >= maximum_visible_length)
        return;
    const auto insertion = plain_text.substr(0u, maximum_visible_length - visible_text.size());
    if (insertion.empty())
        return;
    caret_position = std::min(caret_position, visible_text.size());
    std::vector<HyperTextRun> replacement;
    std::size_t position = 0u;
    bool inserted = false;
    for (const auto &element : elements)
    {
        const auto length = element.text.size();
        if (!inserted && caret_position <= position + length)
        {
            const auto offset = caret_position - position;
            if (element.link() != nullptr && offset == 0u)
            {
                SphereUIHyperTextEditControl::appendPlainRun(replacement, insertion);
                replacement.push_back(element);
            }
            else if (element.link() != nullptr && offset == length)
            {
                replacement.push_back(element);
                SphereUIHyperTextEditControl::appendPlainRun(replacement, insertion);
            }
            else
            {
                std::string value(element.text, length);
                value.insert(offset, insertion);
                SphereUIHyperTextEditControl::appendPlainRun(replacement, value);
            }
            inserted = true;
        }
        else
            SphereUIHyperTextEditControl::appendEditorElement(replacement, element);
        position += length;
    }
    if (!inserted)
        SphereUIHyperTextEditControl::appendPlainRun(replacement, insertion);
    const auto caret = caret_position + insertion.size();
    SphereUIHyperTextEditControl::commitEditorElements(*this, replacement);
    caret_position = caret;
    visible_last = caret_position == 0u ? 0u : caret_position - 1u;
    updateVisibleStart();
    updateVisibleEnd();
}

void SphereUIHyperTextEditControl::insertCharacter(std::string_view glyph)
{
    if (glyph.size() != 1u)
        throw std::invalid_argument("Hypertext insertion requires one code unit");
    if (!edit_modes.test(PlainText) || std::as_bytes(std::span(glyph)).front() < std::byte{32} || (edit_modes.test(Numeric) && (glyph < "0" || glyph > "9")))
        return;
    insertPlainText(glyph);
}

void SphereUIHyperTextEditControl::eraseCharacter(bool backspace)
{
    caret_position = std::min(caret_position, visible_text.size());
    if ((backspace && caret_position == 0u) || (!backspace && caret_position == visible_text.size()))
        return;
    const auto target = caret_position - (backspace ? 1u : 0u);
    std::vector<HyperTextRun> replacement;
    std::size_t position = 0u;
    for (const auto &element : elements)
    {
        const auto length = element.text.size();
        if (target >= position && target < position + length)
        {
            std::string value(element.text, length);
            value.erase(target - position, 1u);
            SphereUIHyperTextEditControl::appendPlainRun(replacement, value);
        }
        else
            SphereUIHyperTextEditControl::appendEditorElement(replacement, element);
        position += length;
    }
    SphereUIHyperTextEditControl::commitEditorElements(*this, replacement);
    caret_position = target;
    visible_first = std::min(visible_first, caret_position);
    updateVisibleEnd();
}

std::size_t SphereUIHyperTextEditControl::fitText(std::string_view text, int font, int pixels, bool reverse)
{
    const auto value = text;
    if (pixels <= 0 || value.empty())
        return 0u;
    std::int64_t used = 0;
    for (std::size_t count = 0u; count < value.size(); ++count)
    {
        const auto index = reverse ? value.size() - count - 1u : count;
        used += SphereUIInterfaceRenderer::measureText(value.substr(index, 1u), font, true).width;
        if (used > pixels)
            return index;
    }
    return reverse ? 0u : value.size();
}

void SphereUIHyperTextEditControl::updateVisibleEnd()
{
    visible_first = std::min(visible_first, visible_text.size());
    if (visible_text.size() == 0u)
    {
        visible_last = 0u;
        return;
    }
    const auto length = visible_text.size() - visible_first;
    const auto fit = fitText(visible_text.data() + visible_first, font, std::max(0, width - text_margins.left - text_margins.right), false);
    visible_last = std::min(visible_text.size() - 1u, visible_first + (fit == length ? (length == 0u ? 0u : length - 1u) : fit));
}

void SphereUIHyperTextEditControl::updateVisibleStart()
{
    if (visible_text.size() == 0u)
    {
        visible_first = visible_last = 0u;
        return;
    }
    visible_last = std::min(visible_last, visible_text.size() - 1u);
    const std::string prefix(visible_text.data(), visible_last + 1u);
    const auto first = fitText(prefix, font, std::max(0, width - text_margins.left - text_margins.right), true);
    visible_first = first == 0u ? 0u : first + 1u;
}

void SphereUIHyperTextEditControl::moveCaret(std::uint32_t key)
{
    caret_position = std::min(caret_position, visible_text.size());
    if (key == VK_HOME)
    {
        caret_position = visible_first = 0u;
        updateVisibleEnd();
    }
    else if (key == VK_END)
    {
        caret_position = visible_text.size();
        visible_last = caret_position == 0u ? 0u : caret_position - 1u;
        updateVisibleStart();
    }
    else if (key == VK_LEFT && caret_position != 0u)
    {
        --caret_position;
        if (caret_position < visible_first)
            visible_first = caret_position;
        updateVisibleEnd();
    }
    else if (key == VK_RIGHT && caret_position < visible_text.size())
    {
        ++caret_position;
        if (caret_position > visible_last + 1u)
        {
            visible_last = caret_position - 1u;
            updateVisibleStart();
        }
        updateVisibleEnd();
    }
}

void SphereUIHyperTextEditControl::drawElement(const SphereUITextExtent &point, HyperTextRun &element, std::uint32_t color, const SphereUIUiIndexRange &range)
{
    if (!element.isPlain() && element.link() == nullptr)
        return;
    const auto first = std::min(range.first, element.text.size());
    const auto length = range.last == invalidIndex ? element.text.size() - first : std::min(element.text.size() - first, range.last >= first ? range.last - first + 1u : 0u);
    std::string password;
    std::string_view display = std::string_view(element.text).substr(first, length);
    if (element.isPlain() && edit_modes.test(Password))
    {
        password.assign(length, '*');
        display = password;
    }
    if (element.link() != nullptr)
    {
        const auto kind = element.link()->link_kind;
        color = kind == 1u ? item_link_color : kind == 2u ? player_link_color : link_color;
    }
    const auto extent = SphereUIInterfaceRenderer::measureText(display, font, true);
    if (auto *geometry = element.geometry())
        *geometry = {point.width, point.height, extent.width, extent.height};
    SphereUIInterfaceRenderer::drawText(display, point.width, point.height, SferaColor::fromArgb(color).withAlpha(alpha).argb(), font, true, SphereUIWidgetSupport::windowBounds(*this), false);
}

void SphereUIHyperTextEditControl::drawCaret()
{
    if (cursor_type == 0u)
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    const auto start = std::min(visible_first, visible_text.size()), caret = std::clamp(caret_position, start, visible_text.size());
    std::string prefix(visible_text.data() + start, caret - start);
    const auto left = bounds.left + text_margins.left + SphereUIInterfaceRenderer::measureText(prefix, font, true).width;
    const auto top = bounds.top + text_margins.top;
    const auto color = SferaColor::fromArgb(cursor_color).withAlpha(alpha).argb();
    if (cursor_type == 2u)
        SphereUIInterfaceRenderer::drawText("_", left, top, color, font, true, bounds, false);
    else if (cursor_type == 1u)
        SphereUIInterfaceRenderer::drawTexture(nullptr, SferaNumeric::real32(left), SferaNumeric::real32(top + 2), SferaNumeric::real32(left + 1),
                                               SferaNumeric::real32(bounds.bottom - text_margins.bottom - 2), color, 0.0f, 0.0f, false);
}

void SphereUIHyperTextEditControl::draw()
{
    if (hidden || (behavior_flags & SphereUIWindowStyle::skipDrawing) != 0u)
        return;
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    SphereUIViewportScope clip(bounds);
    if (!clip)
        return;
    const auto now = SphereUIRuntime::milliseconds();
    if (now - blink_started > 500u)
    {
        blink_started = now;
        cursor_visible = !cursor_visible ? 1u : 0u;
    }
    caret_position = std::min(caret_position, visible_text.size());
    updateVisibleEnd();
    if (cursor_visible && input_enabled)
        drawCaret();
    std::size_t position = 0u;
    SphereUITextExtent point{bounds.left + text_margins.left, bounds.top + text_margins.top};
    for (auto &element : elements)
    {
        const auto length = element.text.size();
        if (length != 0u && position + length > visible_first && position <= visible_last)
        {
            const SphereUIUiIndexRange range{visible_first > position ? visible_first - position : 0u, std::min(length - 1u, visible_last - position)};
            drawElement(point, element, plain_color, range);
            if (const auto *geometry = element.geometry())
                point.width = SphereUIDetail::addCoordinate(point.width, geometry->width);
        }
        position += length;
    }
}

void SphereUIHyperTextEditControl::historyUp()
{
    if (edit_modes.test(Password) || history.size() == 0u)
        return;
    history_position = std::min(history_position, history.size());
    if (history_position != 0u)
        --history_position;
    setContent(history.at(history_position).data());
}

void SphereUIHyperTextEditControl::historyDown()
{
    if (edit_modes.test(Password) || history.size() == 0u)
        return;
    if (history_position < history.size())
        ++history_position;
    setContent(history.at(std::min(history_position, history.size() - 1u)).data());
}

void SphereUIHyperTextEditControl::submitText()
{
    SphereUIWidgetSupport::notifyParent(*this, SphereUIUiMessage::hyperEditSubmit);
    if (edit_modes.test(Password) || hyper_text.size() == 0u || maximum_history == 0u)
        return;
    std::deque<std::string> replacement;
    for (const auto &entry : history)
    {
        if (entry != hyper_text)
            replacement.emplace_back(entry);
    }
    while (replacement.size() >= maximum_history)
        replacement.pop_front();
    replacement.emplace_back(hyper_text);
    history = std::move(replacement);
    history_position = history.size();
}

void SphereUIHyperTextEditControl::pasteClipboard()
{
    std::string value;
    SphereUIHyperTextEditControl::clipboardText(value);
    for (auto &character : value)
        if (character == '\n' || character == '\r')
            character = ' ';
    insertPlainText(value);
}

void SphereUIHyperTextEditControl::transformHistory(std::string &result, const std::string &source, bool decode)
{
    std::string value(source);
    std::size_t index = 0;
    SferaText::transformBytes(value, std::bind(&SphereUIHyperTextEditControl::transformHistoryByte, std::ref(index), decode, std::placeholders::_1));
    result = std::move(value);
}

std::unique_ptr<SphereUIWindow> SphereUIHyperTextEditControl::cloneInto(SphereUIWindowCloneContext &context) const
{
    return SphereUIWidgetSupport::cloneControl(*this, context, &SphereUIHyperTextEditControl::cloneProperties);
}

std::uint32_t SphereUIHyperTextEditControl::handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second)
{
    switch (message)
    {
    case SphereUIUiMessage::setInputEnabled:
        setInputFocus(first != 0u);
        return 1u;
    case SphereUIUiMessage::setHyperEditTextColor:
        plain_color = first;
        return 1u;
    default:
        return SphereUIWindow::handleMessage(message, first, second);
    }
}

void SphereUIHyperTextEditControl::handleInput(const SphereUIWindowInput &input)
{
    if (hidden)
        return;
    if (input_enabled)
    {
        if (input.character >= 32u)
            insertCharacter(input.text());
        else if (input.character == 0u)
        {
            const auto key = input.key_code;
            if (key == VK_BACK || key == VK_DELETE)
                eraseCharacter(key == VK_BACK);
            else if (key == VK_END || key == VK_HOME || key == VK_LEFT || key == VK_RIGHT)
                moveCaret(key);
            else if (key == VK_UP)
                historyUp();
            else if (key == VK_DOWN)
                historyDown();
            else if (key == VK_RETURN)
                submitText();
            else if (key == VK_INSERT && (input.key_modifiers & 3u) != 0u)
                pasteClipboard();
            else if (key == VK_OEM_PLUS)
                insertCharacter("=");
        }
        input.key_code = input.character = 0u;
        SphereUIRuntime::setTextInputActive(true);
    }
    if ((input.mouse_flags & SphereUIMouseInput::leftPress) == 0u)
        return;
    const auto cursor = CCursorManager::instance().geometry();
    const auto bounds = SphereUIWidgetSupport::windowBounds(*this);
    if (cursor.x < bounds.left || cursor.x >= bounds.right || cursor.y < bounds.top || cursor.y >= bounds.bottom)
    {
        setInputFocus(false);
        return;
    }
    if (!input_enabled)
        setInputFocus(true);
    if (visible_text.size() == 0u)
        return;
    const auto start = std::min(visible_first, visible_text.size());
    const auto end = std::min(visible_last + 1u, visible_text.size());
    const std::string visible(visible_text.data() + start, end > start ? end - start : 0u);
    caret_position = std::min(visible_text.size(), start + fitText(visible, font, cursor.x - bounds.left - text_margins.left, false));
    if ((input.key_modifiers & 1u) == 0u)
        return;
    std::size_t position = 0u;
    for (const auto &element : elements)
    {
        if (caret_position >= position && caret_position < position + element.text.size() && element.link() != nullptr)
        {
            if (auto *description = SphereUIRuntime::descriptionWindow())
                description->showDescription(element.link()->linkValue(), 0u, 250u, false);
            break;
        }
        position += element.text.size();
    }
}

SphereUIHyperTextEditControl::~SphereUIHyperTextEditControl()
{
    if (template_instance)
    {
        try
        {
            saveHistory();
        }
        catch (const std::exception &)
        {
        }
    }
    SphereUIRuntime::setTextInputActive(false);
}

void SphereUIHyperTextEditControl::cloneProperties(SphereUIHyperTextEditControl &target, const SphereUIHyperTextEditControl &source, SphereUIWindowCloneContext &)
{
    SphereUIWidgetSupport::copyProperties(target, source, &SphereUIHyperTextEditControl::elements, &SphereUIHyperTextEditControl::history, &SphereUIHyperTextEditControl::edit_modes,
                                          &SphereUIHyperTextEditControl::visible_text, &SphereUIHyperTextEditControl::hyper_text, &SphereUIHyperTextEditControl::history_position,
                                          &SphereUIHyperTextEditControl::maximum_history, &SphereUIHyperTextEditControl::cursor_type, &SphereUIHyperTextEditControl::caret_position,
                                          &SphereUIHyperTextEditControl::blink_started, &SphereUIHyperTextEditControl::cursor_visible, &SphereUIHyperTextEditControl::text_margins,
                                          &SphereUIHyperTextEditControl::cursor_color, &SphereUIHyperTextEditControl::plain_color, &SphereUIHyperTextEditControl::player_link_color,
                                          &SphereUIHyperTextEditControl::item_link_color, &SphereUIHyperTextEditControl::link_color, &SphereUIHyperTextEditControl::maximum_visible_length,
                                          &SphereUIHyperTextEditControl::maximum_hyper_length, &SphereUIHyperTextEditControl::visible_first, &SphereUIHyperTextEditControl::visible_last);
}

void SphereUIHyperTextEditControl::appendContentRuns(const std::vector<HyperTextRun> &input, std::size_t &used, std::vector<HyperTextRun> &replacement)
{
    for (const auto &element : input)
    {
        const auto length = element.text.size();
        if (used >= maximum_visible_length)
            break;
        if (length > maximum_visible_length - used)
        {
            SphereUIHyperTextEditControl::appendPlainRun(replacement, std::string_view(element.text).substr(0u, maximum_visible_length - used));
            used = maximum_visible_length;
        }
        else
        {
            SphereUIHyperTextEditControl::appendEditorElement(replacement, element);
            used += length;
        }
    }
}

int SphereUIHyperTextEditControl::transformHistoryByte(std::size_t &index, bool decode, std::uint8_t byte)
{
    constexpr std::int8_t primary[] = {1, 2, 3, -2, 1, -1, -2, -3, 2, -1, 0, -2, 2};
    constexpr std::int8_t secondary[] = {0, -1, -2, 2, -1, 0, 1};

    const auto shift = primary[index % std::size(primary)] + secondary[index % std::size(secondary)];
    ++index;
    return byte + (decode ? shift : -shift);
}

void SphereUIHyperTextEditControl::clipboardText(std::string &result)
{
    result.clear();
    if (!::IsClipboardFormatAvailable(CF_TEXT) || !::OpenClipboard(nullptr))
        return;
    SphereUIClipboardGuard clipboard;
    const auto handle = ::GetClipboardData(CF_TEXT);
    if (handle == nullptr)
        return;
    const auto size = ::GlobalSize(handle);
    if (size == 0)
        return;
    const auto data = ::GlobalLock(handle);
    if (data == nullptr)
        return;
    SphereUIGlobalLockGuard lock{handle};
    std::vector<std::uint8_t> bytes(size);
    std::memcpy(bytes.data(), data, size);
    const auto end = std::find(bytes.begin(), bytes.end(), std::uint8_t{});
    if (end != bytes.end())
        result.assign(SferaText::fromBytes(std::span(bytes.begin(), end)));
}
