#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <fstream>
#include <ios>
#include <iterator>
#include <limits>
#include <memory>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "application/ClientApplication.h"
#include "binary/Binary.h"
#include "config/InterfaceConfiguration.h"
#include "config/SimpleParser.h"
#include "diagnostics/ClientDiagnostics.h"
#include "image/PcxHeader.h"
#include "input/Cursors.h"
#include "math/Color.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "resources/FileResources.h"
#include "resources/TextureRepository.h"
#include "text/Fonts.h"
#include "text/HyperText.h"
#include "text/Parsing.h"
#include "text/Text.h"
#include "ui/GameInterfaceManager.h"
#include "ui/Rendering.h"
#include "ui/Sprite.h"
#include "ui/UiRuntime.h"
#include "ui/UiTypes.h"
#include "ui/WidgetResources.h"
#include "ui/WidgetSupport.h"
#include "ui/Window.h"
#include "ui/widgets/Controls.h"
#include "ui/widgets/Lists.h"
#include "ui/widgets/Popups.h"
#include "ui/widgets/TextEditors.h"

bool SphereUIButtonCtrl::loadUi(const std::string &, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    reader.sprite("checkedImage", *this, pressed_image);
    reader.sprite("focusedImage", *this, hover_image);
    reader.sprite("disabledImage", *this, disabled_image);
    reader.sprite("uncheckedImage", *this, idle_image);
    reader.flags("buttonStyle", button_flags, buttonStyles);
    const auto method = reader.string("drawMethod");
    if (method && SferaText::asciiEqual(*method, "SPRITE"))
        button_flags |= ButtonStyle::stateImages;
    if (method && SferaText::asciiEqual(*method, "NONE"))
        behavior_flags |= SphereUIWindowStyle::skipDrawing;
    if (const auto hotkey_name = reader.string("hotKey", true))
    {
        hotkey = SphereUIButtonCtrl::keyCode(*hotkey_name);
        std::string_view arguments(parser.valueText());
        const auto first = arguments.find_first_not_of(numericWhitespace);
        const auto end = first == std::string_view::npos ? first : arguments.find_first_of(numericWhitespace, first);
        arguments = end == std::string_view::npos ? std::string_view{} : arguments.substr(end);
        for (std::size_t index = 0u; index < 3u; ++index)
        {
            int modifier = 0;
            if (!SphereUIWidgetSupport::readInteger(arguments, modifier, 10))
                break;
            if (modifier == 1 || modifier == 2)
                hotkey |= modifier << (16u + 2u * index);
        }
    }
    hover_color = text_color;
    reader.color("focuscolor", hover_color);
    return true;
}

bool SphereUICheckBox::loadUi(const std::string &, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    hover_color = text_color;
    reader.sprite("checkedImage", *this, checked_image);
    reader.sprite("focusedImage", *this, unchecked_hover_image);
    reader.sprite("uncheckedImage", *this, unchecked_image);
    reader.sprite("checkfocusImage", *this, checked_hover_image);
    reader.pair("imageOffset", image_x, image_y);
    reader.pair("textOffset", label_x, label_y);
    reader.color("focuscolor", hover_color);
    reader.flags("buttonStyle", button_flags, buttonStyles);
    return true;
}

bool SferaInterfaceCursor::loadTextures()
{
    for (std::size_t index = 0u; index < textures.size(); ++index)
    {
        const auto name = SferaCursorTextureHelper::name(SphereUIDetail::wireWord(index));
        textures[index] = g_sfera_textures.find(name);
        if (textures[index] == -1)
            SphereUIInterfaceRenderer::reportError((std::string("Cursor texture '") + std::string(name) + "' not found"));
    }
    kind = 0u;
    images = {};
    labels = {};
    return true;
}

void SferaInterfaceCursor::setImage(std::size_t layer, std::optional<std::string_view> texture, int x, int y)
{
    if (layer >= images.size())
        return;
    auto &image = images[layer];
    image.x = x;
    image.y = y;
    image.texture = texture ? g_sfera_textures.find(*texture) : -1;
    const auto extent = image.texture == -1 ? SphereUITextExtent{32, 32} : g_sfera_textures.size(image.texture);
    image.width = extent.width;
    image.height = extent.height;
}

void SferaInterfaceCursor::setKind(std::uint32_t cursor_kind)
{
    if (cursor_kind >= textures.size() && cursor_kind != 255u)
        return;
    kind = SferaNumeric::lowByte(cursor_kind);
    centered_hotspot = cursor_kind >= 2u && cursor_kind < textures.size();
}

bool SphereUIEditCtrl::loadUi(const std::string &, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    reader.count("maxsymbols", maximum_symbols);
    reader.boolean("numeric", numeric);
    reader.boolean("password", password);
    reader.boolean("enteredOnFocus", submit_on_blur);
    if (reader.has("cursorcolor"))
    {
        reader.color("cursorcolor", cursor_color);
        cursor_color = SferaColor::fromArgb(cursor_color).withAlpha(0u).argb();
        cursor_uses_text_color = false;
    }
    int unused_horizontal_offset = 0;
    reader.pair("cursoroffset", unused_horizontal_offset, cursor_offset_y);
    if (maximum_symbols == 0u)
        maximum_symbols = 256u;
    cursor_width = SphereUIInterfaceRenderer::measureText("_", font, true).width + 1;
    input_enabled = false;
    updatePassword();
    return true;
}

bool SphereUIFontFace::load(std::optional<std::string_view> display_name, const std::string &filename, std::string_view texture_name)
{
    if (filename.empty())
        return false;
    std::ifstream stream(filename, std::ios::binary);
    if (!stream)
    {
        const std::string message = std::string("Can't open font '") + filename + "'";
        if (auto *log = g_sfera_error_log_runtime.outputs[1u]; log != nullptr)
            log->write(message);
        return false;
    }
    std::array<std::uint8_t, 4> signature{};
    if (!SferaBinary::read(stream, signature) || SferaText::fromBytes(signature) != "SFNT")
        return false;
    SphereUIFontFace replacement;
    const auto stored_name = SferaText::readTerminated(stream, 256u);
    if (!stored_name)
        return false;
    const auto stored_texture = SferaText::readTerminated(stream, 256u);
    if (!stored_texture)
        return false;
    replacement.name = display_name ? *display_name : std::string_view(*stored_name);
    const auto texture_id = g_sfera_textures.find(texture_name);
    if (texture_id == -1)
    {
        const std::string message = std::string("Can't load texture '") + std::string(texture_name) + "' for font '" + replacement.name + "'";
        SphereUIInterfaceRenderer::reportError(message);
        return false;
    }
    replacement.texture = texture_id;
    std::array<std::uint8_t, 8> metrics{};
    if (!SferaBinary::read(stream, metrics))
        return false;
    replacement.line_height = SferaBinary::readLittleEndian<int>(metrics.data());
    replacement.baseline = SferaBinary::readLittleEndian<int>(metrics.data() + 4);
    // SFNT stores 224 little-endian records, including a legacy two-byte gap after advance.
    std::array<std::uint8_t, SphereUIFontGlyph::encodedSize> record{};
    for (auto &glyph : std::span(replacement.glyphs).subspan(32u))
    {
        if (!SferaBinary::read(stream, record))
            return false;
        glyph = SphereUIFontGlyph::decode(record);
        glyph.bearing_y = SferaNumeric::signedHalf(SferaNumeric::lowHalf(SferaNumeric::word(glyph.bearing_y) - SferaNumeric::word(replacement.baseline)));
    }
    *this = std::move(replacement);
    return true;
}

bool SphereUIFontFactory::load(const std::string &filename, std::string_view texture_name)
{
    auto loaded = std::make_unique<SphereUIFontFace>();
    if (!loaded->load(std::nullopt, filename, texture_name))
        return false;
    faces.push_back(std::move(loaded));
    return true;
}

void SphereUIFontFactory::loadNamedFont(std::string_view name)
{
    if (name.empty())
        return;
    std::string localized_name(name);
    const auto &suffix = g_sfera_font_runtime.language_suffix;
    if (!suffix.empty() && !SferaText::asciiEqual(suffix, "_e"))
        localized_name += suffix;
    const std::string filename = "Effects\\" + localized_name + ".sfn";
    if (!load(filename, localized_name))
    {
        const std::string message = "Can't load font '" + localized_name + "'";
        SphereUIInterfaceRenderer::reportError(message);
    }
}

void SphereUIFontFactory::loadConfiguration()
{
    SphereUIInterfaceConfiguration::open("fonts.cfg");
    if (SphereUIInterfaceConfiguration::empty())
    {
        SphereUIInterfaceRenderer::reportError("File 'fonts.cfg' doesn't exist or contains no font configuration.");
        return;
    }
    const int count = std::max(0, SphereUIInterfaceConfiguration::readInteger("NEW_FONTS_NUMBER", 0));
    for (int index = 0; index < count; ++index)
    {
        const std::string key = "NEW_FONT_" + std::to_string(index);
        const auto text = SphereUIInterfaceConfiguration::value(key);
        const std::string_view value = text.value_or(std::string_view{});
        const auto end = value.find('"', 1u);
        if (value.empty() || value.front() != '"' || end == std::string_view::npos)
        {
            const std::string message = "Missing quoted font name for '" + key + "' in fonts.cfg.";
            SphereUIInterfaceRenderer::reportError(message);
            continue;
        }
        std::string name(value.substr(1u, end - 1u));
        std::replace(name.begin(), name.end(), '\r', ' ');
        std::erase(name, '\n');
        loadNamedFont(name);
    }
}

void GameFontAtlas::load(int font, const std::string &filename, int outline, int spacing, int emptyWidth)
{
    if (font < 0 || font >= faces.size() || outline < 0 || outline > 3)
        WorldDiagnostics::fail("Invalid bitmap font parameters");
    const auto image = g_sfera_files.readAll(filename);
    constexpr std::size_t sourceWidth = 280;
    constexpr std::size_t sourceCell = 26;
    constexpr std::size_t atlasWidth = 256;
    constexpr std::size_t atlasCell = 32;
    constexpr std::size_t paletteBytes = 256 * 3;
    if (image.size() < PcxHeader::encodedSize + paletteBytes)
        WorldDiagnostics::fail("Truncated font image");
    const auto header = PcxHeader::decode(image.data());
    if (header.maximum_y < header.minimum_y)
        WorldDiagnostics::fail("Invalid font image height");
    const std::uint32_t height = header.maximum_y - header.minimum_y + 1u;
    const auto palette = image.size() - paletteBytes;
    std::vector<std::uint8_t> mask(sourceWidth * height);
    std::size_t source = PcxHeader::encodedSize;
    for (std::size_t destination = 0; destination < mask.size();)
    {
        if (source >= palette)
            WorldDiagnostics::fail("Truncated font image pixels");
        auto color = image[source++];
        std::size_t count = 1;
        if (color > PcxHeader::runMarker)
        {
            count = color - PcxHeader::runMarker;
            if (source >= palette)
                WorldDiagnostics::fail("Truncated font image run");
            color = image[source++];
        }
        if (count > mask.size() - destination)
            WorldDiagnostics::fail("Font image run exceeds its dimensions");
        const auto entry = palette + color * 3u;
        const auto white = image[entry] > 240 && image[entry + 1] > 240 && image[entry + 2] > 240;
        std::fill_n(mask.begin() + destination, count, white ? std::uint8_t{1} : std::uint8_t{0});
        destination += count;
    }
    const auto language = SferaClientApplication::language;
    const auto mappingPath = language == 0 || language == 1 ? std::string("fonts\\font.txt") : std::string("fonts\\font") + language_suffix + ".txt";
    const auto mappingBytes = g_sfera_files.readAll(mappingPath);
    const auto mapping = SferaText::fromBytes(mappingBytes);
    std::array<SferaFontGlyphRuntime, 256> placements{};
    std::array<int, 256> widths{};
    std::array<std::uint16_t, atlasWidth * atlasWidth> pixels{};
    std::vector<Microsoft::WRL::ComPtr<IDirect3DTexture9>> pages;
    auto &graphics = *g_sfera_graphics_runtime.d3d_runtime;
    std::size_t symbols = 0;
    int firstRow = sourceCell;
    int lastRow = -1;
    for (std::size_t position = 0; (position = mapping.find('#', position)) != std::string_view::npos;)
    {
        auto end = position;
        while (end != 0 && mapping[end - 1] == ' ')
            --end;
        if (end < 2 || mapping[end - 2] < 'A' || mapping[end - 2] > 'Z' || mapping[end - 1] < '0' || mapping[end - 1] > '9')
            WorldDiagnostics::fail("wrong format of font1.txt");
        const auto sourceX = 20 + sourceCell * (mapping[end - 1] - '0');
        const auto sourceY = 20 + sourceCell * (mapping[end - 2] - 'A');
        ++position;
        while (position < mapping.size() && mapping[position] == ' ')
            ++position;
        if (position + 1 >= mapping.size() || mapping[position] != '\'')
            WorldDiagnostics::fail("wrong format of font1.txt");
        const std::uint8_t character = mapping[position + 1];
        position += 2;
        if (position < mapping.size() && mapping[position] == '\'')
            ++position;
        if (sourceX + sourceCell > sourceWidth || sourceY + sourceCell > height || symbols >= 256u * 64u)
            WorldDiagnostics::fail("Font glyph is outside its image");
        std::array<std::uint8_t, atlasCell * atlasCell> glyph{};
        std::array<std::uint8_t, atlasCell * atlasCell> shadow{};
        int rightmost = 0;
        for (int y = 0; y < sourceCell; ++y)
            for (int x = 0; x < sourceCell; ++x)
            {
                if (mask[(sourceY + y) * sourceWidth + sourceX + x] == 0)
                    continue;
                glyph[(y + 3) * atlasCell + x + 3] = 1;
                rightmost = std::max(rightmost, x + 1);
                firstRow = std::min(firstRow, y);
                lastRow = std::max(lastRow, y);
                for (int dy = 0; dy <= outline; ++dy)
                    for (int dx = 0; dx <= outline; ++dx)
                    {
                        const bool corner = (dx == -outline || dx == outline) && (dy == -outline || dy == outline);
                        if (outline == 1 || !corner)
                            shadow[(y + 3 + dy) * atlasCell + x + 3 + dx] = 1;
                    }
            }
        const auto tileX = symbols % 8 * atlasCell;
        const auto tileY = symbols / 8 % 8 * atlasCell;
        for (std::size_t y = 0; y < atlasCell; ++y)
            for (std::size_t x = 0; x < atlasCell; ++x)
                pixels[(tileY + y) * atlasWidth + tileX + x] = glyph[y * atlasCell + x]    ? std::numeric_limits<std::uint16_t>::max()
                                                               : shadow[y * atlasCell + x] ? SferaColor::rgba(0u, 0u, 0u, 240u).argb4444()
                                                                                           : 0u;
        widths[character] = rightmost == 0 ? emptyWidth : rightmost;
        placements[character] = {SphereUIDetail::wireWord(symbols / 64u), 1.0f * (tileX + 3 - outline) / atlasWidth, 1.0f * (tileY + 3 - outline) / atlasWidth, true};
        if (++symbols % 64 == 0)
            uploadPage(pixels, pages);
    }
    if (placements[124].defined == 0)
        WorldDiagnostics::fail("Symbol for CODE_FOR_UNDIFINED_SYMBOL is not found in font.txt");
    if (lastRow < firstRow)
        WorldDiagnostics::fail("Font contains no visible glyphs");
    if (symbols % 64 != 0)
        uploadPage(pixels, pages);
    GameFontAtlasFace replacement;
    replacement.widths = widths;
    replacement.pages = std::move(pages);
    replacement.span = lastRow - firstRow + 3;
    replacement.origin = firstRow;
    replacement.cell_step = 20 - firstRow;
    replacement.code_base = spacing;
    faces[font] = std::move(replacement);
    std::copy(placements.begin(), placements.end(), std::begin(glyphs));
}

bool SphereUIFontPicker::loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    SphereUIResourceLoader::loadPart(*this, preview, reader, "text", filename, parser, SphereUIUiControlKind::text, 2u);
    SphereUIResourceLoader::loadPart(*this, selector, reader, "spinButton", filename, parser, SphereUIUiControlKind::spinButton, 1u);
    return true;
}

bool SphereUIHyperTextDocument::load(const std::string &filename)
{
    SferaSimpleParser parser;
    parser.load(filename);
    SferaParserRange range{};
    const bool found = parser.findBlock("hypertext", &range, nullptr, 1);
    if (found)
        load(parser, range);
    return found;
}

void SphereUIHyperTextDocument::load(const SferaSimpleParser &parser, const SferaParserRange &range)
{
    std::string input;
    for (auto index = range.begin; index < range.end - 1; ++index)
    {
        auto line = parser.lineAt(index);
        if (line.data() == nullptr)
            continue;
        const auto first = line.find_first_not_of(' ');
        if (first != std::string_view::npos)
            input += line.substr(first);
        input += ' ';
    }
    parse(input);
}

bool SphereUIHyperTextChatListControl::loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    if (!reader.has("linkColor"))
        return false;
    reader.color("linkColor", link_color);
    item_link_color = link_color;
    std::uint32_t unused_player_color = link_color;
    reader.color("playerLinkColor", unused_player_color);
    reader.color("itemLinkColor", item_link_color);
    maximum_items = 256u;
    row_height = 15;
    reader.count("maxItems", maximum_items);
    reader.integer("rowHeight", row_height);
    maximum_items = std::clamp<std::size_t>(maximum_items, 1u, maximumScrollOffset);
    row_height = std::clamp(row_height, 1, maximumScrollOffset);
    font = std::max(font, 2);
    SferaParserRange block{};
    if (reader.block("scrollbar", block) && !SphereUIResourceLoader::loadPart(*this, scrollbar, reader, "scrollbar", filename, parser, SphereUIUiControlKind::scrollBar, 1u))
        return false;
    page_rows = std::max(height, 0) / row_height;
    rebuildVisible();
    updateScroll(false);
    return true;
}

bool SphereUIHyperTextEditControl::loadUi(const std::string &, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    if (font < 2u || !reader.has("linkColor"))
        return false;
    plain_color = cursor_color = UiColor::white;
    reader.color("textColor", plain_color);
    reader.color("cursorColor", cursor_color);
    reader.color("linkColor", link_color);
    player_link_color = item_link_color = link_color;
    reader.color("playerLinkColor", player_link_color);
    reader.color("itemLinkColor", item_link_color);
    maximum_visible_length = maximum_history = 256u;
    maximum_hyper_length = 3072u;
    reader.count("maxVisibleTextLength", maximum_visible_length);
    reader.count("maxHyperTextLength", maximum_hyper_length);
    reader.count("maxHistoryLength", maximum_history);
    cursor_type = 1u;
    if (const auto value = reader.string("cursorType"))
        cursor_type = SferaText::asciiEqual(*value, "none") ? 0u : SferaText::asciiEqual(*value, "uline") ? 2u : 1u;
    edit_modes.reset();
    if (reader.has("editMode"))
        for (std::size_t index = 0u; index < parser.tokenCount(); ++index)
        {
            const auto value = reader.token(index);
            if (SferaText::asciiEqual(value, "enterPlainText"))
                edit_modes.set(PlainText);
            else if (SferaText::asciiEqual(value, "numbersOnly"))
            {
                edit_modes.set(PlainText);
                edit_modes.set(Numeric);
            }
            else if (SferaText::asciiEqual(value, "password"))
            {
                edit_modes.set(PlainText);
                edit_modes.set(Password);
            }
        }
    if (edit_modes.none())
        edit_modes.set(PlainText);
    text_margins = {};
    reader.rectangle("titleTextMargin", text_margins.left, text_margins.top, text_margins.right, text_margins.bottom);
    loadHistory();
    updateVisibleEnd();
    return true;
}

bool SphereUIHyperTextCtrl::loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    if (const auto value = reader.string("textFormat"))
        text_format = parseTextFormat(*value);
    if (const auto value = reader.string("hyperText", true))
        queuePage(*value, false);
    SphereUIResourceLoader::loadPart(*this, scrollbar, reader, "scrollbar", filename, parser, SphereUIUiControlKind::scrollBar, 1u);
    if (reader.has("linkcolor"))
    {
        const auto first = reader.token(0u);
        SphereUIWidgetSupport::readHexColor(first, link_color);
        const auto second = reader.token(1u);
        SphereUIWidgetSupport::readHexColor(second, hover_color);
    }
    if (const auto value = reader.string("flags"))
        if (SferaText::asciiEqual(*value, "DISCARD_OLD_TEXT"))
            discard_old_text = true;
    return true;
}

bool SphereUIImageCtrl::loadUi(const std::string &, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    resource_reference = nullptr;
    reader.sprite("image", *this, resource_reference);
    reader.integer("alpha", base_alpha);
    reader.flags("imageStyle", image_style, imageStyles, true);
    if (reader.has("rotate"))
        setRotationDegrees(parser.readFloat(0u));
    return true;
}

void SphereUIImageCtrl::setImageName(std::string_view image_name)
{
    SphereUIImageDescription description{};
    description.name.assign(image_name);
    setImage(&description);
}

void SphereUIImageCtrl::setImage(const SphereUIImageDescription *description)
{
    if (description == nullptr)
    {
        resource_reference.reset();
        return;
    }
    if (resource_reference && SferaText::asciiEqual(resource_reference->name, description->name))
        return;
    auto replacement = parent ? parent->findResource(description->name) : nullptr;
    if (!replacement)
        replacement = g_sfera_interface.sharedSprite(description->name);
    if (!replacement)
    {
        auto image = std::make_shared<SphereUIUiSprite>();
        image->setDescription(*description);
        fallback_image = image;
        replacement = std::move(image);
    }
    resource_reference = std::move(replacement);
}

bool SphereUIListItemCtrl::loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    SphereUIResourceLoader::loadPart(*this, vertical_scroll, reader, "vscrollbar", filename, parser, SphereUIUiControlKind::scrollBar, 1u);
    if (SphereUIResourceLoader::loadPart(*this, horizontal_scroll, reader, "hscrollbar", filename, parser, SphereUIUiControlKind::scrollBar, 1u))
        horizontal_scroll->orientation_flags |= 1u;
    SferaParserRange part{};
    if (reader.block("itemTemplate", part))
    {
        auto original = std::make_unique<SphereUIWindow>();
        original->setParent(parent);
        if (!original->loadUi(filename, parser, part))
            throw std::runtime_error("list item template could not be loaded");
        original->setParent(nullptr);
        original->hidden = false;
        original->resource_parent = parent;
        original->input_enabled = true;
        item_template = std::move(original);
    }
    int count = 0;
    reader.integer("createItems", count);
    for (int index = 0; index < count; ++index)
        addItem();
    reader.sprite("selectSprite", *this, selection_sprite);
    reader.integer("selectedItem", selected_index);
    if (selected_index < 0 || selected_index >= std::ssize(items))
        selected_index = -1;
    reader.boolean("canSelectItems", can_select);
    reader.boolean("horizontal", horizontal);
    reader.boolean("userMove", user_move);
    updateLayout();
    return true;
}

bool SphereUISlotCtrl::loadUi(const std::string &, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    if (parent == nullptr)
        return false;
    const bool background = reader.has("slotpic") || reader.has("slotFull");
    if (background)
    {
        reader.sprite(reader.has("slotpic") ? "slotpic" : "slotFull", *this, full_sprite);
        show_full_background = true;
        if (full_sprite == nullptr)
            return false;
    }
    reader.sprite("slotempty", *this, empty_sprite);
    reader.sprite("slotborder", *this, border_sprite);
    reader.pair("slotpicofs", image_offset_x, image_offset_y);
    reader.pair("textofs", count_offset_x, count_offset_y);
    int number = 0;
    reader.integer("slotnumber", number);
    if (number != 0)
        setText(std::to_string(number));
    if (const auto image = reader.string("slotItem", true))
        setItem(*image);
    return true;
}

bool SphereUICMenuListControl::loadUi(const std::string &, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    reader.sprite("topSprite", *this, top_sprite);
    reader.sprite("middleSprite", *this, middle_sprite);
    reader.sprite("bottomSprite", *this, bottom_sprite);
    if (top_sprite == nullptr || middle_sprite == nullptr || bottom_sprite == nullptr)
        return false;

    top_size = spriteDimensions(top_sprite);
    item_size = spriteDimensions(middle_sprite);
    bottom_size = spriteDimensions(bottom_sprite);
    hovered_sprite = middle_sprite;
    reader.sprite("middleHoveredSprite", *this, hovered_sprite);
    if (!reader.has("normalColor"))
        return false;
    reader.color("normalColor", normal_color);
    item_disabled_color = hovered_color = title_color = normal_color;
    reader.color("disabledColor", item_disabled_color);
    reader.color("hoveredColor", hovered_color);
    reader.color("titleColor", title_color);
    item_margin = {};
    title_margin = {};
    item_format = title_format = 0u;
    reader.rectangle("listItemTextMargin", item_margin.left, item_margin.top, item_margin.right, item_margin.bottom);
    reader.rectangle("titleTextMargin", title_margin.left, title_margin.top, title_margin.right, title_margin.bottom);
    reader.flags("listItemTextFormat", item_format, textAlignments);
    reader.flags("titleTextFormat", title_format, textAlignments);
    show_title = reader.has("needShowTitle");
    maximum_items = 1u;
    reader.count("maxItems", maximum_items);
    hovered_index = maximum_items;
    height = top_size.height + bottom_size.height;
    font = std::max(font, 2);
    return true;
}

bool SphereUIProgressBar::loadUi(const std::string &, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    reader.drawMethod(*this);
    reader.status("statusShow", display_mode);
    if (reader.pair("range", minimum, maximum))
    {
        if (minimum > maximum)
            std::swap(minimum, maximum);
        if (minimum == maximum)
            maximum = SphereUIDetail::addCoordinate(maximum, 1);
    }
    reader.integer("progressPos", current);
    if (minimum <= maximum)
        current = std::clamp(current, minimum, maximum);
    reader.pair("statusPos", status_x, status_y);
    refreshProgressDisplay();
    return true;
}

bool SphereUIRichEditCtrl::loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    SphereUIResourceLoader::loadPart(*this, scrollbar, reader, "scrollbar", filename, parser, SphereUIUiControlKind::scrollBar, 1u);
    updateMetrics(font);
    updateScroll();
    return true;
}

bool SphereUIScrollBar::loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    if (reader.has("horizontal") && parser.readBool(0u))
        orientation_flags = 1u;
    reader.rectangle("bounds", track_left, track_top, track_right, track_bottom);
    reader.boolean("postMessage", notify_changes);
    reader.drawMethod(*this);
    if (reader.has("scrollSpr"))
    {
        const auto sprite_name = reader.token(0u, true);
        auto *owner = parent;
        scroll_resource = (owner == nullptr ? *this : *owner).getResource(sprite_name);
        thumb_width = parser.readInt(1u);
        thumb_height = parser.readInt(2u);
    }
    SphereUIResourceLoader::loadNavigationButtons(*this, reader, filename, parser, true);
    if (reader.has("deltaStep"))
    {
        step = parser.readInt(0u);
        explicit_step = true;
    }
    updateControlState();
    return true;
}

bool SphereUISliderCtrl::loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    reader.pair("range", minimum, maximum);
    reader.integer("defaultPos", current);
    reader.integer("step", step);
    reader.integer("page", page_step);
    reader.pair("statusPos", status_x, status_y);
    reader.status("statusShow", display_mode);
    return SphereUIScrollBar::loadUi(filename, parser, range);
}

bool SphereUISpinButton::loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    bool defaults = true;
    reader.boolean("defButtonStyle", defaults);
    SphereUIResourceLoader::loadNavigationButtons(*this, reader, filename, parser, defaults, 0.15f);
    reader.pair("range", minimum, maximum);
    reader.integer("spinPos", current);
    reader.integer("badyCtrlID", body_index);
    reader.boolean("notifyChange", notify_changes);
    status_valid = false;
    step = 1;
    return true;
}

bool SphereUIUiSprite::loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range)
{
    std::string text;
    if (parser.findValue("name", &range) && parser.readQuotedString(0u, text))
        name = text;
    else
        SphereUIUiSprite::uiSpriteLoadDiagnostic(filename, range, "Name not specified.");
    if (parser.findValue("size", &range))
    {
        width = parser.readInt(0u);
        height = parser.readInt(1u);
    }
    else
        SphereUIUiSprite::uiSpriteLoadDiagnostic(filename, range, "Size not specified.");
    SphereUIParserScanScope scan(parser);
    std::size_t count = 0u;
    parser.setScanRange(&range);
    while (parser.nextValue("texture"))
        ++count;
    if (count == 0u)
        SphereUIUiSprite::uiSpriteLoadDiagnostic(filename, range, "At least one texture must be specified.");
    resetParts(count);
    std::size_t index = 0u;
    parser.setScanRange(&range);
    while (parser.nextValue("texture"))
    {
        if (!parser.readQuotedString(0u, text))
            continue;
        int rectangles[8]{};
        if (!parser.readIntSequence(1u, rectangles))
            SphereUIUiSprite::uiSpriteLoadDiagnostic(filename, range, "Incorrect number of args in 'texture'.");
        const SphereUIUiRect source{rectangles[0], rectangles[1], rectangles[2], rectangles[3]};
        const SphereUIUiRect destination{rectangles[4], rectangles[5], rectangles[6], rectangles[7]};
        parts[index++].setTexture(text, &source, &destination);
    }
    parser.setScanRange(&range);
    while (parser.nextValue("tcoords"))
    {
        int values[9]{};
        if (!parser.readIntSequence(0u, values))
            SphereUIUiSprite::uiSpriteLoadDiagnostic(filename, range, "Incorrect number of args in 'tcoords'.");
        const int part_index = values[0];
        if (part_index < 0 || std::cmp_greater_equal(part_index, count) || parts[part_index].texture < 0)
            continue;
        const auto size = g_sfera_textures.size(parts[part_index].texture);
        for (std::size_t vertex = 0u; vertex < 4u; ++vertex)
        {
            parts[part_index].u[vertex] = SphereUIWidgetSupport::spriteTextureCoordinate(values[vertex * 2u + 1u], size.width);
            parts[part_index].v[vertex] = SphereUIWidgetSupport::spriteTextureCoordinate(values[vertex * 2u + 2u], size.height);
        }
    }
    return true;
}

void SphereUISpritePart::setTexture(std::string_view image_name, const SphereUIUiRect *texture_rectangle, const SphereUIUiRect *sprite_rectangle)
{
    texture_name = image_name;
    texture = g_sfera_textures.find(image_name);
    if (texture < 0)
    {
        const auto message = std::string("Sprite::Texture not found '") + std::string(image_name) + "'";
        SphereUIInterfaceRenderer::reportError(message);
    }
    const auto extent = g_sfera_textures.size(texture);
    const auto source = texture_rectangle == nullptr ? SphereUIUiRect{0, 0, extent.width, extent.height} : *texture_rectangle;
    const float left = texture_rectangle == nullptr ? 0.0f : SphereUIWidgetSupport::spriteTextureCoordinate(source.left, extent.width),
                top = texture_rectangle == nullptr ? 0.0f : SphereUIWidgetSupport::spriteTextureCoordinate(source.top, extent.height),
                right = texture_rectangle == nullptr ? 1.0f : SphereUIWidgetSupport::spriteTextureCoordinate(source.right, extent.width),
                bottom = texture_rectangle == nullptr ? 1.0f : SphereUIWidgetSupport::spriteTextureCoordinate(source.bottom, extent.height);
    for (std::size_t index = 0; index < 4; ++index)
    {
        u[index] = index == 0 || index == 3 ? left : right;
        v[index] = index < 2 ? top : bottom;
    }
    rectangle = sprite_rectangle == nullptr ? SphereUIUiRect{0, 0, extent.width, extent.height} : *sprite_rectangle;
}

void SphereUIUiSprite::uiSpriteLoadDiagnostic(const std::string &filename, const SferaParserRange &range, std::string_view message)
{
    const auto diagnostic = "Sprite::Load(" + filename + "," + std::to_string(range.begin) + "," + std::to_string(range.end) + ") -> " + std::string(message);
    SphereUIInterfaceRenderer::reportError(diagnostic);
}

void SphereUIUiSprite::setImage(std::string_view image_name)
{
    this->name = image_name;
    resetParts(1u);
    auto &part = parts.front();
    part.setTexture(image_name, nullptr, nullptr);
    width = part.rectangle.right;
    height = part.rectangle.bottom;
}

void SphereUIUiSprite::setDescription(const SphereUIImageDescription &description)
{
    name = description.name;
    resetParts(1u);
    const auto flags = description.image.flags;
    const auto *rectangle = (flags & 2u) != 0u ? &description.image.rectangle : nullptr;
    const std::string_view texture_name = (flags & 4u) != 0u ? description.image.texture_name : description.name;
    auto &part = parts.front();
    part.setTexture(texture_name, rectangle, rectangle);
    width = (flags & 1u) != 0u ? description.image.width : part.rectangle.right;
    height = (flags & 1u) != 0u ? description.image.height : part.rectangle.bottom;
}

bool SphereUIListCtrl::loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    line_height = SphereUIInterfaceRenderer::measureText(" ", font, true).height;
    SphereUIResourceLoader::loadPart(*this, scrollbar, reader, "scrollbar", filename, parser, SphereUIUiControlKind::scrollBar, 1u);
    reader.boolean("formatStrings", format_strings);
    reader.boolean("useContinueMark", continue_mark);
    reader.boolean("canSelect", can_select);
    reader.integer("selectionBorder", selection_border);
    reader.rgba("selectionColor", selection_color);
    reader.rgba("selectionLineColor", selection_line_color);
    if (reader.has("chatlike"))
    {
        chatlike = parser.readBool(0u) ? 1u : 0u;
        maximum_items = 64u;
    }
    reader.count("maxItems", maximum_items);
    parser.setScanRange(&range);
    while (parser.nextValue("addstring"))
    {
        std::string key, color_text;
        parser.readString(0u, key);
        parser.readString(1u, color_text);
        std::uint32_t color = 0u;
        if (!key.empty() && SphereUIWidgetSupport::readHexColor(color_text, color))
            addText(g_sfera_interface.localizedText(key), color);
    }
    parser.clearScanRange();
    updateLayout();
    return true;
}

bool SphereUITextCtrl::loadUi(const std::string &, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    if ((width == 0 || height == 0) && text.size() != 0u)
    {
        const auto extent = SphereUIInterfaceRenderer::measureText(getText(), font, font_initialized);
        width = extent.width;
        height = extent.height;
    }
    reader.flags("textStyle", text_style, textStyles, true);
    return true;
}

bool SphereUIToolTipCtrl::loadUi(const std::string &, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    reader.integer("font", font);
    reader.color("textColor", text_color);
    reader.color("backcolor", background_color);
    reader.rectangle("margin", margin_left, margin_top, margin_right, margin_bottom);
    parser.setScanRange(&range);
    try
    {
        while (parser.nextValue("toolstr"))
        {
            const auto key = reader.token();
            appendLine(g_sfera_interface.localizedText(key));
        }
    }
    catch (...)
    {
        parser.clearScanRange();
        throw;
    }
    parser.clearScanRange();
    return true;
}

SphereUIUiControlKind SphereUIResourceLoader::controlKind(std::string_view name)
{
    constexpr SphereUINamedValue<SphereUIUiControlKind> values[] = {{"BUTTON", SphereUIUiControlKind::button},
                                                                    {"TEXT", SphereUIUiControlKind::text},
                                                                    {"IMAGE", SphereUIUiControlKind::image},
                                                                    {"PROGRESS_BAR", SphereUIUiControlKind::progressBar},
                                                                    {"SCROLL_BAR", SphereUIUiControlKind::scrollBar},
                                                                    {"HYPER_TEXT", SphereUIUiControlKind::hyperText},
                                                                    {"CHECKBOX", SphereUIUiControlKind::checkBox},
                                                                    {"RADIOBUTTON", SphereUIUiControlKind::radioButton},
                                                                    {"TEXTLIST", SphereUIUiControlKind::textList},
                                                                    {"SLIDER", SphereUIUiControlKind::slider},
                                                                    {"LISTITEM", SphereUIUiControlKind::listItem},
                                                                    {"EDIT", SphereUIUiControlKind::edit},
                                                                    {"SLOT", SphereUIUiControlKind::slot},
                                                                    {"SPINBUTTON", SphereUIUiControlKind::spinButton},
                                                                    {"RICHEDIT", SphereUIUiControlKind::richEdit},
                                                                    {"FILTERLISTCTRL", SphereUIUiControlKind::filteredList},
                                                                    {"MINIMAP", SphereUIUiControlKind::minimap},
                                                                    {"MENULISTCTRL", SphereUIUiControlKind::menu},
                                                                    {"HTCHATLISTCTRL", SphereUIUiControlKind::hyperTextChat},
                                                                    {"HTEDIT", SphereUIUiControlKind::hyperTextEdit},
                                                                    {"FONTPICKER", SphereUIUiControlKind::fontPicker},
                                                                    {"COLORPICKER", SphereUIUiControlKind::colorPicker}};
    return SphereUIResourceLoader::lookup(name, values, anyControlKind);
}

SphereUIWindowAnimationKind SphereUIResourceLoader::animationKind(std::string_view name)
{
    constexpr SphereUINamedValue<SphereUIWindowAnimationKind> values[] = {{"ALPHA_IN", SphereUIWindowAnimationKind::FadeIn},    {"ALPHA_OUT", SphereUIWindowAnimationKind::FadeOut},
                                                                          {"MOVE_LEFT", SphereUIWindowAnimationKind::MoveLeft}, {"MOVE_RIGHT", SphereUIWindowAnimationKind::MoveRight},
                                                                          {"MOVE_TOP", SphereUIWindowAnimationKind::MoveUp},    {"MOVE_BOTTOM", SphereUIWindowAnimationKind::MoveDown}};
    return SphereUIResourceLoader::lookup(name, values, SphereUIWindowAnimationKind::None);
}

std::uint32_t SphereUIResourceLoader::alignmentFlag(std::string_view name)
{
    constexpr SphereUINamedValue<std::uint32_t> values[] = {{"LEFT_X", SphereUIalignLeft}, {"CENTER_X", SphereUIalignCenterX}, {"RIGHT_X", SphereUIalignRight},
                                                            {"LEFT_Y", SphereUIalignTop},  {"CENTER_Y", SphereUIalignCenterY}, {"RIGHT_Y", SphereUIalignBottom}};
    return SphereUIResourceLoader::lookup(name, values, 0u);
}

void SphereUIResourceLoader::readAnimation(SphereUIReader &reader, SferaSimpleParser &parser, std::string_view key, SphereUIWindowAnimation &animation)
{
    const auto name = reader.string(key);
    if (!name)
        return;
    animation.kind = SphereUIResourceLoader::animationKind(*name);
    animation.duration = parser.readFloat(1u);
    animation.distance = parser.readFloat(2u);
    animation.offset = parser.readFloat(3u);
    if (animation.duration == 0.0f)
        animation.duration = 0.25f;
}

int SphereUIWindow::findImage(std::string_view name)
{
    return g_sfera_textures.find(name);
}

bool SphereUIWindow::loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SphereUIReader reader(parser, range);
    reader.boolean("hitTransparent", hit_transparent);
    if (const auto value = reader.string("windowName", true))
        setResourceName(*value);
    SferaParserRange sprites{};
    if (reader.block("spritesDef", sprites))
    {
        parser.setBlockRange(&sprites);
        SferaParserRange entry{};
        while (parser.nextBlock("sprite", &entry))
        {
            auto sprite = std::make_shared<SphereUIUiSprite>();
            if (sprite->loadUi(filename, parser, entry))
                appendResource(std::move(sprite));
        }
        parser.clearBlockRange();
    }
    resource_reference = nullptr;
    reader.drawMethod(*this, true);
    if (reader.pair("showTitle", text_offset_x, text_offset_y))
        behavior_flags |= SphereUIWindowStyle::showTitle;
    if (reader.has("escapeHandle") && parser.readBool(0u))
        behavior_flags |= SphereUIWindowStyle::handleEscape;
    if (reader.pair("position", x, y))
    {
        initial_x = x;
        initial_y = y;
    }
    reader.pair("size", width, height);
    if (const auto value = reader.string("windowText"))
        setText(g_sfera_interface.localizedText(*value));
    if (const auto value = reader.string("windowHelp", true))
        setHelp(*value);
    reader.boolean("canDragDrop", can_drag_drop);
    reader.boolean("canGoTop", can_go_top);
    if (reader.has("canNotCross") && parser.readBool(0u))
        behavior_flags |= SphereUIWindowStyle::preventOverlap;
    reader.rectangle("rectTitle", caption_left, caption_top, caption_right, caption_bottom);
    reader.boolean("saveLastPosition", save_last_position);
    if (reader.has("font"))
    {
        font = parser.readInt(0u);
        font_initialized = true;
    }
    if (reader.has("alignWin"))
        for (std::size_t index = 0u; index < parser.tokenCount(); index += 2u)
            alignment_flags |= SphereUIResourceLoader::alignmentFlag(reader.token(index));
    reader.color("textColor", text_color);
    reader.color("disabledColor", disabled_color);
    SphereUIResourceLoader::readAnimation(reader, parser, "showEffect", show_animation);
    SphereUIResourceLoader::readAnimation(reader, parser, "hideEffect", hide_animation);
    parser.setBlockRange(&range);
    SferaParserRange entry{};
    std::uint32_t next_id = 1u;
    std::uint32_t ordinal = 1u;
    while (parser.nextBlock("control", &entry))
    {
        SphereUIReader child_reader(parser, entry);
        const auto class_name = child_reader.string("classID");
        if (class_name)
            if (auto child = createControl(filename, parser, entry, SphereUIResourceLoader::controlKind(*class_name), ordinal))
            {
                child->control_id = next_id++;
                appendChild(std::move(child));
            }
        ++ordinal;
    }
    return true;
}

std::shared_ptr<const SphereUIUiSprite> SphereUIWindow::getResource(std::string_view name_to_find)
{
    if (auto existing = findResource(name_to_find))
        return existing;
    if (SphereUIWindow::findImage(name_to_find) == -1)
        return {};
    auto sprite = std::make_shared<SphereUIUiSprite>();
    sprite->setImage(name_to_find);
    appendResource(sprite);
    return sprite;
}

std::unique_ptr<SphereUIWindow> SphereUIWindow::createControl(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range, SphereUIUiControlKind kind, std::uint32_t id)
{
    if (kind == anyControlKind)
        return nullptr;
    auto control = SphereUIRuntime::makeControl(kind);
    if (control == nullptr)
        return nullptr;
    SphereUIReader reader(parser, range);
    SferaParserRange tip_range{};
    if (reader.block("tooltip", tip_range))
    {
        auto tip = std::make_unique<SphereUIToolTipCtrl>();
        if (tip != nullptr)
        {
            tip->setParent(control.get());
            if (tip->loadUi(filename, parser, tip_range))
                control->tooltip = std::move(tip);
        }
    }
    reader.pair("position", control->x, control->y);
    reader.pair("size", control->width, control->height);
    reader.color("disabledColor", control->disabled_color);
    if (reader.pair("showTitle", control->text_offset_x, control->text_offset_y))
        control->behavior_flags |= SphereUIWindowStyle::showTitle;
    reader.boolean("disabled", control->disabled);
    reader.boolean("hidden", control->hidden);
    reader.integer("group", control->group);
    if (reader.has("font"))
    {
        control->font = parser.readInt(0u);
        control->font_initialized = true;
    }
    reader.flags("textFormat", control->text_alignment, textAlignments, true);
    reader.color("textColor", control->text_color);
    if (const auto value = reader.string("windowText"))
        control->setText(g_sfera_interface.localizedText(*value));
    if (const auto value = reader.string("windowHelp", true))
        control->setHelp(*value);
    if (const auto value = reader.string("setWindowText", true))
        control->setText(*value);
    reader.boolean("canDragDrop", control->can_drag_drop);
    control->parent = parent == nullptr ? this : parent;
    if (!control->loadUi(filename, parser, range))
        return nullptr;
    control->control_id = id;
    return control;
}
