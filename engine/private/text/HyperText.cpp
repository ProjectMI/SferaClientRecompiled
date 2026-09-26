#include <windows.h>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <d3d9types.h>
#include <functional>
#include <limits>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "math/Color.h"
#include "numeric/Numeric.h"
#include "text/HyperText.h"
#include "text/Text.h"
#include "ui/Rendering.h"
#include "ui/Sprite.h"
#include "ui/UiHost.h"
#include "ui/UiTypes.h"
#include "ui/WidgetSupport.h"

SphereUIHyperTextDocument::SphereUIHyperTextDocument(std::string_view text, int width, std::uint32_t format, int font)
{
    if (!text.empty())
    {
        parse(text);
        layout(width, format, font);
    }
}

void SphereUIHyperTextDocument::parse(std::string_view input)
{
    std::vector<SphereUIHyperDocumentNode> parsed(1);
    std::vector<SphereUIHyperTextRegion> parsed_links, parsed_tooltips;
    input = input.substr(0, input.find('\0'));
    for (std::size_t index = 0; index < input.size();)
    {
        if (input[index] != '<')
        {
            if (input[index] != '\n')
                parsed.back().text += input[index];
            ++index;
            continue;
        }
        const auto end = input.find('>', index + 1);
        if (end == std::string_view::npos)
        {
            parsed.back().text.append(input.substr(index));
            break;
        }
        SphereUIHyperDocumentNode node;
        std::string argument;
        if (!SphereUIHyperTextParser::parseCommand(input.substr(index + 1, end - index - 1), node, argument))
        {
            parsed.back().text += input[index++];
            continue;
        }
        if (node.command == SphereUIHyperTextCommand::linkStart || node.command == SphereUIHyperTextCommand::tooltipStart)
        {
            SphereUIHyperTextRegion region;
            const auto target = node.command == SphereUIHyperTextCommand::tooltipStart && !argument.empty() && argument.front() == '#'
                                    ? SphereUIHost::localizedText(std::string_view(argument).substr(1))
                                    : std::string_view(argument);
            region.target.assign(target);
            auto &regions = node.command == SphereUIHyperTextCommand::linkStart ? parsed_links : parsed_tooltips;
            node.region_index = regions.size();
            regions.push_back(std::move(region));
        }
        parsed.push_back(std::move(node));
        index = end + 1;
    }
    nodes = std::move(parsed);
    links = std::move(parsed_links);
    tooltips = std::move(parsed_tooltips);
    lines.clear();
    line_height = 0;
}

std::unique_ptr<SphereUIHyperTextDocument> SphereUIHyperTextDocument::clone(int width, std::uint32_t format, int font_id) const
{
    if (nodes.empty())
        return nullptr;
    auto document = std::make_unique<SphereUIHyperTextDocument>(*this);
    document->resetRegions();
    document->layout(width, format, font_id);
    return document;
}

void SphereUIHyperTextDocument::layout(int width, std::uint32_t format, int font_id)
{
    width = std::max(width, 1);
    const auto tracking = SphereUIInterfaceRenderer::tracking(font_id);
    const auto space = SphereUIWidgetSupport::hyperTextExtent(" ", font_id);
    line_height = std::max(space.height, 1);
    this->font = font_id;
    std::vector<SphereUIHyperDocumentFragment> originals;
    for (const auto &node : nodes)
        originals.push_back({node, node.text});
    std::vector<SphereUIHyperDocumentRow> rows(1u);
    rows.back().height = line_height;
    for (const auto &original : originals)
    {
        auto node = original.node;
        if (node.command == SphereUIHyperTextCommand::lineBreak)
            appendLayoutRow(rows, true);
        if (node.command == SphereUIHyperTextCommand::tab)
            node.spacing = std::max(space.width, 0) * 4;
        auto &row = rows.back();
        if (node.command == SphereUIHyperTextCommand::image)
        {
            row.width += node.image_width;
            row.height = std::max<int>(row.height, node.image_height);
            const auto shift = std::max(0, node.image_height - line_height);
            row.baseline = std::max(row.baseline, node.image_alignment == SphereUIHyperTextImageAlignment::bottom   ? shift
                                                  : node.image_alignment == SphereUIHyperTextImageAlignment::middle ? shift / 2
                                                                                                                    : 0);
        }
        else if (node.command == SphereUIHyperTextCommand::tab)
            row.width += node.spacing;
        row.fragments.push_back({node, {}});
        auto text = std::string_view(original.text);
        std::size_t start = 0u;
        while (start < text.size())
        {
            const auto remaining = text.substr(start);
            const auto full_extent = SphereUIWidgetSupport::hyperTextExtent(remaining, font_id);
            if (rows.back().width + full_extent.width <= width)
            {
                auto &current = rows.back();
                if (current.fragments.empty())
                    current.fragments.push_back({{}, {}});
                current.fragments.back().text.append(remaining);
                current.width += full_extent.width;
                break;
            }
            const auto end = SphereUIWidgetSupport::hyperWordEnd(text, start);
            const auto word = text.substr(start, end - start);
            const auto extent = SphereUIWidgetSupport::hyperTextExtent(word, font_id);
            auto visible = word;
            if (rows.back().width != 0 && rows.back().width + extent.width > width)
            {
                appendLayoutRow(rows, false);
                if (start != 0u && !visible.empty() && visible.front() == ' ')
                {
                    ++start;
                    visible.remove_prefix(1u);
                }
                if (SphereUIWidgetSupport::hyperTextExtent(text.substr(start), font_id).width <= width)
                    continue;
            }
            if (!visible.empty())
            {
                auto &current = rows.back();
                if (current.fragments.empty() || current.fragments.back().node.command == SphereUIHyperTextCommand::horizontalSpace)
                    current.fragments.push_back({{}, {}});
                auto &fragment = current.fragments.back();
                fragment.text.append(visible);
                current.width += SphereUIWidgetSupport::hyperTextExtent(visible, font_id).width + tracking;
            }
            start = end;
        }
    }
    if (originals.empty())
        rows.clear();
    for (auto &row : rows)
    {
        for (auto &fragment : row.fragments)
            if (!fragment.text.empty())
            {
                if (fragment.node.command != SphereUIHyperTextCommand::preserveSpaces)
                {
                    const auto first = fragment.text.find_first_not_of(' ');
                    fragment.text.erase(0u, first == std::string::npos ? fragment.text.size() : first);
                }
                break;
            }
        for (auto fragment = row.fragments.rbegin(); fragment != row.fragments.rend(); ++fragment)
            if (!fragment->text.empty())
            {
                const auto last = fragment->text.find_last_not_of(' ');
                fragment->text.resize(last == std::string::npos ? 0u : last + 1u);
                break;
            }
        row.width = 0;
        for (auto &fragment : row.fragments)
        {
            fragment.node.width = SphereUIWidgetSupport::hyperTextExtent(fragment.text, font_id).width;
            row.width += fragment.node.width;
            if (fragment.node.command == SphereUIHyperTextCommand::tab || fragment.node.command == SphereUIHyperTextCommand::horizontalSpace)
                row.width += fragment.node.spacing;
            else if (fragment.node.command == SphereUIHyperTextCommand::image)
                row.width += fragment.node.image_width;
        }
    }
    std::vector<SphereUIHyperDocumentRow> final_rows;
    final_rows.reserve(rows.size());
    std::uint32_t color = D3DCOLOR_XRGB(255, 255, 255);
    for (std::size_t index = 0u; index < rows.size(); ++index)
    {
        auto &row = rows[index];
        SphereUIHyperDocumentRow result{};
        result.height = row.height;
        result.baseline = row.baseline;
        result.initial_color = color;
        const auto spare = std::max(0, width - row.width);
        if (format == 1u || format == 2u)
        {
            SphereUIHyperDocumentNode padding{};
            padding.command = SphereUIHyperTextCommand::horizontalSpace;
            padding.spacing = format == 1u ? spare : spare / 2;
            result.fragments.push_back({padding, {}});
        }
        std::size_t gaps = 0u;
        if (format == 3u && !row.paragraph_end)
            for (const auto &fragment : row.fragments)
                for (std::size_t character = 0u; character < fragment.text.size(); ++character)
                    if (fragment.text[character] == ' ' && character != 0u && fragment.text[character - 1u] != ' ')
                        ++gaps;
        std::size_t used_gaps = 0u;
        int distributed = 0;
        for (auto &fragment : row.fragments)
        {
            if (fragment.node.command == SphereUIHyperTextCommand::color)
                color = fragment.node.color;
            if (gaps == 0u)
            {
                result.fragments.push_back(std::move(fragment));
                continue;
            }
            std::size_t start = 0u;
            bool command = true;
            while (start < fragment.text.size())
            {
                const auto word = fragment.text.find_first_not_of(' ', start);
                auto end = word == std::string::npos ? fragment.text.size() : fragment.text.find(' ', word);
                if (end == std::string::npos)
                    end = fragment.text.size();
                else
                {
                    while (end < fragment.text.size() && fragment.text[end] == ' ')
                        ++end;
                }
                auto node = command ? fragment.node : SphereUIHyperDocumentNode{};
                command = false;
                const auto text = fragment.text.substr(start, end - start);
                node.width = SphereUIWidgetSupport::hyperTextExtent(text, font_id).width + (end < fragment.text.size() ? tracking : 0);
                result.fragments.push_back({node, text});
                if (!text.empty() && text.back() == ' ' && text.find_first_not_of(' ') != std::string::npos)
                {
                    const auto added = ++used_gaps == gaps ? spare - distributed : std::cmp_greater(gaps, spare) ? 0 : spare / SphereUIDetail::checkedInt(gaps, "hypertext gap count exceeds int");
                    SphereUIHyperDocumentNode padding{};
                    padding.command = SphereUIHyperTextCommand::horizontalSpace;
                    padding.spacing = added;
                    distributed += added;
                    result.fragments.push_back({padding, {}});
                }
                start = end;
            }
            if (command)
                result.fragments.push_back(std::move(fragment));
        }
        final_rows.push_back(std::move(result));
    }
    std::vector<SphereUIHyperDocumentLine> replacement;
    replacement.reserve(final_rows.size());
    for (auto &row : final_rows)
    {
        SphereUIHyperDocumentLine line;
        line.height = row.height;
        line.baseline = row.baseline;
        line.initial_color = row.initial_color;
        line.nodes.reserve(row.fragments.size());
        for (auto &fragment : row.fragments)
        {
            fragment.node.text = std::move(fragment.text);
            line.nodes.push_back(std::move(fragment.node));
        }
        replacement.push_back(std::move(line));
    }
    lines = std::move(replacement);
}

bool SphereUIHyperTextRegion::contains(int x, int y) const
{
    if (!visible)
        return false;
    return std::any_of(rectangles.begin(), rectangles.end(), std::bind(&SphereUIWidgetSupport::contains, std::placeholders::_1, x, y));
}

void SphereUIHyperTextRegion::addRectangle(const SphereUIUiRect &rectangle, const SphereUIUiRect &clip)
{
    const SphereUIUiRect bounds{std::max(rectangle.left, clip.left), std::max(rectangle.top, clip.top), std::min(rectangle.right, clip.right), std::min(rectangle.bottom, clip.bottom)};
    if (bounds.right <= bounds.left || bounds.bottom <= bounds.top)
        return;
    rectangles.push_back(bounds);
    visible = true;
}

int SphereUIHyperTextDocument::totalHeight() const
{
    std::int64_t height = 0;
    for (const auto &line : lines)
        height += line.height;
    return SphereUIDetail::checkedInt(std::clamp<std::int64_t>(height, 0, std::numeric_limits<int>::max()), "hypertext height exceeds int");
}

void SphereUIHyperTextDocument::resetRegions()
{
    for (auto *group : {&links, &tooltips})
        for (auto &region : *group)
        {
            region.visible = false;
            region.hovered = false;
            region.rectangles.clear();
        }
}

SphereUIUiRect SphereUIHyperTextDocument::linkRectangle(int left, int right, int y, int baseline) const
{
    const auto inset = font < 2u ? 2 : 0;
    const auto bottom_inset = font == 0u ? 2 : font == 1u ? 3 : 0;
    return {left, y + baseline + inset, right + inset, y + baseline * 2 + line_height + bottom_inset};
}

void SphereUIHyperTextDocument::draw(int left, int top, int clip_offset, int clip_height, std::uint32_t alpha)
{
    const auto viewport = SphereUIInterfaceRenderer::viewport();
    const SphereUIUiRect clip{viewport.x, std::max(top, viewport.y), viewport.x + viewport.width, std::min(top + std::max(clip_height, 0), viewport.y + viewport.height)};
    for (auto *group : {&links, &tooltips})
        for (auto &region : *group)
        {
            region.rectangles.clear();
            region.visible = false;
        }
    const auto opacity = std::min(alpha, 255u);
    auto y = top + clip_offset;
    SphereUIHyperTextRegion *link = nullptr;
    SphereUIHyperTextRegion *tooltip = nullptr;
    for (const auto &line : lines)
    {
        auto x = left, link_left = left, tooltip_left = left;
        auto color = line.initial_color;
        const auto baseline = line.baseline;
        for (const auto &node : line.nodes)
        {
            if (node.command == SphereUIHyperTextCommand::color)
                color = node.color;
            else if (node.command == SphereUIHyperTextCommand::linkStart)
            {
                link = node.region_index < links.size() ? &links[node.region_index] : nullptr;
                link_left = x;
            }
            else if (node.command == SphereUIHyperTextCommand::linkEnd)
            {
                if (link != nullptr)
                    link->addRectangle(linkRectangle(link_left, x, y, baseline), clip);
                link = nullptr;
            }
            else if (node.command == SphereUIHyperTextCommand::tooltipStart)
            {
                tooltip = node.region_index < tooltips.size() ? &tooltips[node.region_index] : nullptr;
                tooltip_left = x;
            }
            else if (node.command == SphereUIHyperTextCommand::tooltipEnd)
            {
                if (tooltip != nullptr)
                    tooltip->addRectangle({tooltip_left, y, x, y + line.height}, clip);
                tooltip = nullptr;
            }
            else if (node.command == SphereUIHyperTextCommand::horizontalSpace || node.command == SphereUIHyperTextCommand::tab)
            {
                x += node.spacing;
                if (link != nullptr && link_left == left)
                    link_left = x;
                if (tooltip != nullptr && tooltip_left == left)
                    tooltip_left = x;
            }
            else if (node.command == SphereUIHyperTextCommand::image)
            {
                if (node.sprite != nullptr && y + line.height > clip.top && y < clip.bottom)
                    node.sprite->drawNatural(SferaNumeric::real32(x + node.image_x), SferaNumeric::real32(y + node.image_y), SferaColor::rgba(255u, 255u, 255u, opacity).argb());
                x += node.image_width;
            }
            if (!node.text.empty() && y + line.height > clip.top && y < clip.bottom)
            {
                const auto text_color = link == nullptr ? color : link->hovered ? hover_color : link_color;
                SphereUIInterfaceRenderer::drawText(node.text, x, y + baseline, SferaColor::fromArgb(text_color).withAlpha(opacity).argb(), font, true, clip, alpha == 255u);
            }
            x += node.width;
        }
        if (link != nullptr)
            link->addRectangle(linkRectangle(link_left, x, y, baseline), clip);
        if (tooltip != nullptr)
            tooltip->addRectangle({tooltip_left, y, x, y + line.height}, clip);
        y += line.height;
        if (y >= clip.bottom)
            break;
    }
}

void SphereUIHyperTextDocument::appendLayoutRow(std::vector<SphereUIHyperDocumentRow> &rows, bool paragraph)
{
    rows.back().paragraph_end = paragraph;
    rows.emplace_back();
    rows.back().height = line_height;
}

void SphereUIHyperTextParser::serializeChatResult(std::span<const HyperTextRun> elements, std::string *raw, std::string *visible)
{
    std::string ignored_raw, ignored_visible;
    SphereUIDetail::serializeHyperTextElements(elements, raw != nullptr ? *raw : ignored_raw, visible != nullptr ? *visible : ignored_visible);
}

std::string SphereUIHyperTextParser::plainText(std::string_view input)
{
    std::vector<HyperTextRun> elements;
    std::string plain;
    parseElements(input, elements, plain);
    return plain;
}

std::string SphereUIHyperTextParser::buildLink(std::string_view scheme, std::string_view target, std::string_view caption)
{
    return "<l=\"" + std::string(scheme) + "://" + SphereUIDetail::escapeHyperText(target) + "\">" + std::string(caption) + "</l>";
}

bool SphereUIHyperTextParser::eraseRange(std::string_view input, std::size_t first, std::size_t last, std::string *output, std::string *plain)
{
    std::vector<HyperTextRun> elements;
    std::string visible;
    parseElements(input, elements, visible);
    if (elements.empty())
        return false;
    const std::uint64_t end = 1ull + last;
    std::uint64_t offset = 0u;
    std::vector<HyperTextRun> selected;
    for (const auto &element : elements)
    {
        const std::uint64_t next = offset + element.text.size();
        const bool overlap = first <= last && offset < end && next > first;
        if (!overlap || offset < first || next > end || (first >= offset && last < next))
        {
            auto copy = element;
            if (overlap)
            {
                const std::size_t begin = first > offset ? first - offset : 0u;
                const std::size_t count = std::min(next, end) - offset - begin;
                copy.text.erase(begin, count);
            }
            selected.push_back(std::move(copy));
        }
        offset = next;
    }
    if (first <= last && first < offset)
        elements = std::move(selected);
    SphereUIHyperTextParser::serializeChatResult(elements, output, plain);
    return true;
}

std::string_view SphereUIHyperTextParser::hyperTrim(std::string_view text)
{
    const auto first = text.find_first_not_of(" \t\r\n");
    if (first == std::string_view::npos)
        return {};
    const auto last = text.find_last_not_of(" \t\r\n");
    return text.substr(first, last - first + 1u);
}

bool SphereUIHyperTextParser::hyperEquals(std::string_view text, std::string_view expected)
{
    return SferaText::asciiEqual(text, expected);
}

std::string SphereUIHyperTextParser::hyperUnescape(std::string_view text)
{
    std::string result;
    result.reserve(text.size());
    for (std::size_t index = 0u; index < text.size(); ++index)
    {
        auto character = text[index];
        if (character == '\\')
        {
            if (++index == text.size())
                break;
            character = text[index];
            if (character == '[')
                character = '<';
            else if (character == ']')
                character = '>';
        }
        result += character;
    }
    return result;
}

bool SphereUIHyperTextParser::hyperLinkParameters(std::string_view parameters, std::string &target, std::uint32_t &kind)
{
    auto value = SphereUIHyperTextParser::hyperTrim(parameters);
    if (value.empty() || value.front() != '=')
        return false;
    value = SphereUIHyperTextParser::hyperTrim(value.substr(1u));
    if (value.size() < 2u || value.front() != '"')
        return false;
    std::size_t end = 1u;
    for (; end < value.size(); ++end)
    {
        if (value[end] == '\\' && end + 1u < value.size())
            ++end;
        else if (value[end] == '"')
            break;
    }
    if (end == value.size())
        return false;
    value = value.substr(1u, end - 1u);
    target.assign(value);
    const auto colon = value.find(':');
    const auto scheme = value.substr(0u, colon);
    kind = SphereUIHyperTextParser::hyperEquals(scheme, "hts")      ? 0u
           : SphereUIHyperTextParser::hyperEquals(scheme, "item")   ? 1u
           : SphereUIHyperTextParser::hyperEquals(scheme, "player") ? 2u
           : SphereUIHyperTextParser::hyperEquals(scheme, "mailto") ? 3u
                                                                    : 4u;
    if (kind == 1u || kind == 2u)
        target = SphereUIHyperTextParser::hyperUnescape(target);
    return true;
}

SphereUIHyperTextCommand SphereUIHyperTextParser::command(std::string_view name)
{
    if (SphereUIHyperTextParser::hyperEquals(name, "br"))
        return SphereUIHyperTextCommand::lineBreak;
    if (SphereUIHyperTextParser::hyperEquals(name, "cl"))
        return SphereUIHyperTextCommand::color;
    if (SphereUIHyperTextParser::hyperEquals(name, "l"))
        return SphereUIHyperTextCommand::linkStart;
    if (SphereUIHyperTextParser::hyperEquals(name, "/l") || SphereUIHyperTextParser::hyperEquals(name, "\\l"))
        return SphereUIHyperTextCommand::linkEnd;
    if (SphereUIHyperTextParser::hyperEquals(name, "sp"))
        return SphereUIHyperTextCommand::preserveSpaces;
    if (SphereUIHyperTextParser::hyperEquals(name, "tab"))
        return SphereUIHyperTextCommand::tab;
    if (SphereUIHyperTextParser::hyperEquals(name, "img"))
        return SphereUIHyperTextCommand::image;
    if (SphereUIHyperTextParser::hyperEquals(name, "t"))
        return SphereUIHyperTextCommand::tooltipStart;
    if (SphereUIHyperTextParser::hyperEquals(name, "/t") || SphereUIHyperTextParser::hyperEquals(name, "\\t"))
        return SphereUIHyperTextCommand::tooltipEnd;
    return SphereUIHyperTextCommand::unknown;
}

bool SphereUIHyperTextParser::parseCommand(std::string_view tag, SphereUIHyperDocumentNode &node, std::string &argument)
{
    const auto equals = tag.find('=');
    std::string name;
    for (const auto character : SphereUIHyperTextParser::hyperTrim(tag.substr(0, equals)))
        if (character != ' ')
            name += character;
    node.command = command(name);
    if (node.command == SphereUIHyperTextCommand::unknown)
        return false;
    auto value = equals == std::string_view::npos ? std::string_view{} : SphereUIHyperTextParser::hyperTrim(tag.substr(equals + 1));
    if (!value.empty() && value.front() == '"')
    {
        value.remove_prefix(1);
        value = value.substr(0, value.find('"'));
    }
    argument.assign(value);
    if (node.command == SphereUIHyperTextCommand::color)
        node.color = std::strtoul(argument.c_str(), nullptr, 16) | D3DCOLOR_XRGB(0, 0, 0);
    else if (node.command == SphereUIHyperTextCommand::image)
        parseImage(argument, node);
    return true;
}

void SphereUIHyperTextParser::parseImage(std::string_view argument, SphereUIHyperDocumentNode &node)
{
    std::vector<std::string> fields;
    while (!argument.empty())
    {
        const auto comma = argument.find(',');
        const auto field = SphereUIHyperTextParser::hyperTrim(argument.substr(0, comma));
        if (!field.empty())
            fields.emplace_back(field);
        if (comma == std::string_view::npos)
            break;
        argument.remove_prefix(comma + 1);
    }
    if (fields.empty())
        return;
    node.sprite = SphereUIHost::acquireSprite(fields.front());
    if (node.sprite == nullptr)
        return;
    if (fields.size() > 1 && SphereUIHyperTextParser::hyperEquals(fields[1], "BOT"))
        node.image_alignment = SphereUIHyperTextImageAlignment::bottom;
    else if (fields.size() > 1 && SphereUIHyperTextParser::hyperEquals(fields[1], "MID"))
        node.image_alignment = SphereUIHyperTextImageAlignment::middle;
    int right = 0, bottom = 0;
    if (fields.size() == 4 || fields.size() >= 6)
    {
        node.image_x = imagePadding(fields, 2);
        node.image_y = imagePadding(fields, 3);
    }
    if (fields.size() >= 6)
    {
        right = imagePadding(fields, 4);
        bottom = imagePadding(fields, 5);
    }
    node.image_width = node.sprite->width + node.image_x + right;
    node.image_height = node.sprite->height + node.image_y + bottom;
}

void SphereUIHyperTextParser::parseElements(std::string_view text, std::vector<HyperTextRun> &elements, std::string &plain)
{
    std::vector<HyperTextRun> parsed{};
    std::string output, pending, parameters, target;
    std::uint32_t kind = 4u;
    bool link = false;
    const std::string input(text);
    for (std::size_t index = 0u; index < input.size();)
    {
        if (input[index] != '<')
        {
            pending += input[index++];
            continue;
        }
        const auto end = input.find('>', index + 1u);
        if (end == std::string::npos || end == index + 1u)
        {
            pending.append(input, index, std::string::npos);
            break;
        }
        const auto tag = SphereUIHyperTextParser::hyperTrim(std::string_view(input).substr(index + 1u, end - index - 1u));
        const auto name_end = tag.find_first_of(" =\t\r\n");
        const auto name = tag.substr(0u, name_end);
        if (SphereUIHyperTextParser::hyperEquals(name, "l"))
        {
            std::string new_target;
            std::uint32_t new_kind = 4u;
            const auto remainder = name_end == std::string_view::npos ? std::string_view{} : SphereUIHyperTextParser::hyperTrim(tag.substr(name_end));
            if (SphereUIHyperTextParser::hyperLinkParameters(remainder, new_target, new_kind))
            {
                flushParsedRun(pending, parsed, output, parameters, target, kind, false);
                parameters.assign(remainder);
                target = std::move(new_target);
                kind = new_kind;
                link = true;
            }
            else
                flushParsedRun(pending, parsed, output, parameters, target, kind, false);
        }
        else if (SphereUIHyperTextParser::hyperEquals(name, "/l") || SphereUIHyperTextParser::hyperEquals(name, "\\l"))
        {
            flushParsedRun(pending, parsed, output, parameters, target, kind, link);
            link = false;
        }
        else
            flushParsedRun(pending, parsed, output, parameters, target, kind, false);
        index = end + 1u;
    }
    if (!link)
        flushParsedRun(pending, parsed, output, parameters, target, kind, false);
    elements = std::move(parsed);
    plain = std::move(output);
}

long SphereUIHyperTextParser::imagePadding(const std::vector<std::string> &fields, std::size_t index)
{
    return std::strtol(fields[index].c_str(), nullptr, 10);
}

void SphereUIHyperTextParser::flushParsedRun(std::string &pending, std::vector<HyperTextRun> &parsed, std::string &output, const std::string &parameters, const std::string &target, std::uint32_t kind,
                                             bool linked)
{
    if (pending.empty())
        return;
    const auto decoded = SphereUIHyperTextParser::hyperUnescape(pending);
    if (!decoded.empty())
    {
        if (linked)
            parsed.push_back({decoded, HyperTextRunLink{{}, parameters, target, kind}});
        else
            parsed.push_back({decoded, HyperTextGeometry{}});
        output += decoded;
    }
    pending.clear();
}

std::string_view HyperTextRunLink::linkValue() const
{
    const auto separator = target.find("://");
    if (separator == std::string::npos)
        return "";
    auto offset = separator + 3u;
    if (offset < target.size() && target[offset] == '/')
        ++offset;
    return std::string_view(target).substr(offset);
}
