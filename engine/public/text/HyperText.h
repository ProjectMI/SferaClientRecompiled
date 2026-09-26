#pragma once

#include <windows.h>
#include <cstddef>
#include <cstdint>
#include <d3d9types.h>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

#include "ui/UiTypes.h"

struct SphereUIUiSprite;

struct SferaParserRange;
class SferaSimpleParser;
struct SphereUIHyperDocumentFragment;
struct SphereUIHyperDocumentLine;
struct SphereUIHyperDocumentNode;
struct SphereUIHyperDocumentRow;
class SphereUIHyperTextDocument;
struct SphereUIHyperTextRegion;

enum class SphereUIHyperTextCommand
{
    text,
    lineBreak,
    color,
    linkStart,
    linkEnd,
    preserveSpaces,
    horizontalSpace,
    tab,
    image,
    tooltipStart,
    tooltipEnd,
    unknown
};

enum class SphereUIHyperTextImageAlignment
{
    top,
    bottom,
    middle
};

struct SphereUIHyperTextRegion
{
    std::string target;
    std::vector<SphereUIUiRect> rectangles;
    bool visible = false;
    bool hovered = false;
    bool contains(int x, int y) const;
    void addRectangle(const SphereUIUiRect &rectangle, const SphereUIUiRect &clip);
};

struct SphereUIHyperDocumentNode
{
    SphereUIHyperTextCommand command = SphereUIHyperTextCommand::text;
    std::string text;
    std::uint32_t color = D3DCOLOR_ARGB(255, 255, 255, 255);
    std::size_t region_index = 0;
    int spacing = 0;
    int width = 0;
    SphereUIHyperTextImageAlignment image_alignment = SphereUIHyperTextImageAlignment::top;
    int image_width = 0;
    int image_height = 0;
    int image_x = 0;
    int image_y = 0;
    std::shared_ptr<const SphereUIUiSprite> sprite;
};

struct SphereUIHyperDocumentLine
{
    std::vector<SphereUIHyperDocumentNode> nodes;
    int height = 0;
    int baseline = 0;
    std::uint32_t initial_color = D3DCOLOR_ARGB(255, 255, 255, 255);
};

struct SphereUIHyperDocumentFragment
{
    SphereUIHyperDocumentNode node{};
    std::string text;
};
struct SphereUIHyperDocumentRow
{
    std::vector<SphereUIHyperDocumentFragment> fragments;
    int width = 0;
    int height = 0;
    int baseline = 0;
    std::uint32_t initial_color = D3DCOLOR_XRGB(255, 255, 255);
    bool paragraph_end = false;
};
class SphereUIHyperTextDocument
{
  public:
    std::string name;
    std::vector<SphereUIHyperTextRegion> links;
    std::vector<SphereUIHyperTextRegion> tooltips;
    int line_height = 0;
    int font = 0;
    std::uint32_t link_color = D3DCOLOR_ARGB(255, 80, 160, 160);
    std::uint32_t hover_color = D3DCOLOR_ARGB(255, 255, 255, 0);
    SphereUIHyperTextDocument() = default;
    SphereUIHyperTextDocument(std::string_view text, int width, std::uint32_t format, int font);
    void setName(std::string_view value)
    {
        name = value;
    }
    bool load(const std::string &filename);
    void load(const SferaSimpleParser &parser, const SferaParserRange &range);
    void parse(std::string_view input);
    std::unique_ptr<SphereUIHyperTextDocument> clone(int width, std::uint32_t format, int font) const;
    void layout(int width, std::uint32_t format, int font);
    void draw(int left, int top, int clip_offset, int clip_height, std::uint32_t alpha);
    int totalHeight() const;
    void resetRegions();

  private:
    std::vector<SphereUIHyperDocumentNode> nodes;
    std::vector<SphereUIHyperDocumentLine> lines;
    SphereUIUiRect linkRectangle(int left, int right, int y, int baseline) const;

  private:
    void appendLayoutRow(std::vector<SphereUIHyperDocumentRow> &rows, bool paragraph);
};

struct HyperTextGeometry;
struct HyperTextRun;
struct HyperTextRunLink;

struct HyperTextGeometry
{
    int x;
    int y;
    int width;
    int height;
};

struct HyperTextRunLink
{
    HyperTextGeometry bounds{};
    std::string parameters;
    std::string target;
    std::uint32_t link_kind{};
    std::string_view linkValue() const;
};

struct HyperTextRun
{
    std::string text;
    std::variant<std::monostate, HyperTextGeometry, HyperTextRunLink> content;
    bool isWrap() const
    {
        return std::holds_alternative<std::monostate>(content);
    }
    bool isPlain() const
    {
        return std::holds_alternative<HyperTextGeometry>(content);
    }
    HyperTextRunLink *link()
    {
        return std::get_if<HyperTextRunLink>(&content);
    }
    const HyperTextRunLink *link() const
    {
        return std::get_if<HyperTextRunLink>(&content);
    }
    HyperTextGeometry *geometry()
    {
        if (auto *bounds = std::get_if<HyperTextGeometry>(&content))
            return bounds;
        if (auto *value = link())
            return &value->bounds;
        return nullptr;
    }
    const HyperTextGeometry *geometry() const
    {
        if (const auto *bounds = std::get_if<HyperTextGeometry>(&content))
            return bounds;
        if (const auto *value = link())
            return &value->bounds;
        return nullptr;
    }
};

class SphereUIHyperTextParser;

class SphereUIHyperTextParser
{
  public:
    static std::string plainText(std::string_view input);
    static std::string buildLink(std::string_view scheme, std::string_view target, std::string_view caption);
    static bool extractPlayerPrefix(std::string_view input, std::string *output, std::string *plain);
    static bool removePlayerPrefix(std::string_view input, std::string *output, std::string *plain);
    static bool eraseRange(std::string_view input, std::size_t first, std::size_t last, std::string *output, std::string *plain);
    static SphereUIHyperTextCommand command(std::string_view name);
    static bool parseCommand(std::string_view tag, SphereUIHyperDocumentNode &node, std::string &argument);
    static void parseImage(std::string_view argument, SphereUIHyperDocumentNode &node);
    static void parseElements(std::string_view text, std::vector<HyperTextRun> &elements, std::string &plain);

  private:
    static std::string_view hyperTrim(std::string_view text);
    static bool hyperEquals(std::string_view text, std::string_view expected);
    static std::string hyperUnescape(std::string_view text);
    static bool hyperLinkParameters(std::string_view parameters, std::string &target, std::uint32_t &kind);
    static bool hasPlayerPrefix(std::span<const HyperTextRun> elements);
    static void serializeChatResult(std::span<const HyperTextRun> elements, std::string *raw, std::string *visible);
    static long imagePadding(const std::vector<std::string> &fields, std::size_t index);
    static void flushParsedRun(std::string &pending, std::vector<HyperTextRun> &parsed, std::string &output, const std::string &parameters, const std::string &target, std::uint32_t kind, bool linked);
};
