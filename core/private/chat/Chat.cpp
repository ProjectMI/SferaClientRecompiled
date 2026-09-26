#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <ios>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "chat/ChatFilter.h"
#include "config/ConfigDocument.h"
#include "diagnostics/ClientDiagnostics.h"
#include "resources/FileResources.h"
#include "text/Fonts.h"
#include "text/HyperText.h"
#include "text/Text.h"
#include "ui/widgets/TextEditors.h"

void SphereUIChatFilter::applyCharacterAliases(std::array<std::array<std::uint8_t, 256>, 2> &result, std::size_t alphabet, std::string_view group)
{
    for (std::size_t alias = 1; alias < group.size(); ++alias)
        for (auto &value : result[alphabet])
            if (value == SferaText::byteValue(group[alias]))
                value = group.front();
}

std::array<std::array<std::uint8_t, 256>, 2> SphereUIChatFilter::createCharacterMaps()
{
    std::array<std::array<std::uint8_t, 256>, 2> result{};
    for (std::size_t character = 0; character < 256; ++character)
    {
        auto value = SferaText::lowercaseCp1251()[character];
        const auto letter = SferaText::unicodeCp1251()[value];
        if (!((letter >= U'a' && letter <= U'z') || (letter >= U'\u0430' && letter <= U'\u044f') || letter == U'\u0451'))
            value = ' ';
        result[0][character] = result[1][character] = value;
    }
    for (auto character : {'0', '3', '6'})
        result[0][character] = character;

    for (auto group : {"\345\270e", "\344g",
                       "\341"
                       "6b",
                       "\363y", "\352k", "\343r",
                       "\347"
                       "3",
                       "\365x", "\350\351u",
                       "\356"
                       "0o",
                       "\360p", "\361c", "\340a", "\354m", "\355h"})
        applyCharacterAliases(result, 0u, group);
    for (auto group : {"\350\351i", "\363u", "\352k", "\345e\270", "\366c", "\355n", "\343g", "\347z", "\365h", "\344d", "\353l",
                       "\356o",     "\360r", "\357p", "\340a",     "\342v", "\364f", "\361s", "\354m", "\362t", "\341b"})
        applyCharacterAliases(result, 1u, group);
    return result;
}

bool SphereUIChatFilter::chatRussianVowelOrSign(std::uint8_t value)
{
    constexpr std::u32string_view vowels = U"\u0443\u0435\u044b\u0430\u043e\u044d\u044f\u0438\u044e\u044c\u044a";
    return vowels.find(SferaText::unicodeCp1251()[value]) != std::u32string_view::npos;
}

bool SphereUIChatFilter::chatKeyboardAmbiguous(std::uint8_t value)
{
    constexpr std::u32string_view aliases = U"\u0435e\u0443y\u043ak\u0433r\u04373\u0445x\u0438u\u043e0o\u0440p\u0441c\u0430a\u0442mE\u0415\u0423YK\u041a\u0417X\u0425O\u041e\u0420PC\u0421A\u0410";
    return aliases.find(SferaText::unicodeCp1251()[value]) != std::u32string_view::npos;
}

const std::array<std::array<std::uint8_t, 256>, 2> &SphereUIChatFilter::chatCharacterMaps()
{
    static const auto maps = createCharacterMaps();
    return maps;
}

SphereUIChatFilter::SphereUIChatFilter()
{
    SphereRenderConfigDocument::setStorageMode(SphereRenderConfigDocumentStorageMode::Encoded);
    const std::string filename = std::string("xadd\\matbase") + g_sfera_font_runtime.language_suffix + ".dat";
    g_sfera_files.setErrorReporting(false);
    const auto size = g_sfera_files.fileSize(filename);
    g_sfera_files.setErrorReporting(true);
    if (size == -1)
        return;
    auto configuration = SphereRenderConfigDocument::open(filename);
    const auto count = configuration.arraySize("words");
    if (!count)
    {
        WorldDiagnostics::fail("CMatFilter::CMatFilter: array words absent in matbase.dat");
        return;
    }
    rules.reserve(*count);
    for (std::size_t index = 0u; index < *count; ++index)
    {
        const auto *item = configuration.objectAt("words", index);
        const auto word = item != nullptr ? item->text("w") : std::nullopt;
        if (!word)
        {
            WorldDiagnostics::fail("CMatFilter::CMatFilter: field 'w' absent in one of array's elements");
            continue;
        }
        const auto kind = item->integer("t");
        if (!kind)
        {
            WorldDiagnostics::fail("CMatFilter::CMatFilter: field 't' absent in one of array's elements");
            continue;
        }
        SphereUIChatFilterRule rule{std::string(*word), *kind};
        for (std::size_t exception = 0u; exception < item->arraySize("e").value_or(0u); ++exception)
        {
            if (const auto value = item->textAt("e", exception))
                rule.exceptions.emplace_back(*value);
            else
                WorldDiagnostics::fail("CMatFilter::CMatFilter: error reading exceptions");
        }
        rules.push_back(std::move(rule));
    }
}

SphereUIChatFilter::SphereUIChatFilter(std::vector<SphereUIChatFilterRule> entries) : rules(std::move(entries))
{
}

std::string SphereUIChatFilter::normalize(std::string_view text, std::size_t alphabet)
{
    std::string result(text);
    const auto &map = SphereUIChatFilter::chatCharacterMaps()[alphabet != 0u];
    for (auto &value : result)
        value = map[SferaText::byteValue(value)];
    return result;
}

bool SphereUIChatFilter::matchesWord(std::string_view word, std::size_t alphabet) const
{
    for (const auto &rule : rules)
    {
        const auto pattern = normalize(rule.word, alphabet);
        const auto position = word.find(pattern);
        if (position == std::string_view::npos)
            continue;
        switch (rule.kind)
        {
        case 0u:
            if (word != pattern)
                continue;
            break;
        case 1u:
            break;
        case 2u:
            if (position != 0u)
                continue;
            break;
        case 3u:
            if (position != 0u && !SphereUIChatFilter::chatRussianVowelOrSign(SferaText::byteValue(word[position - 1u])))
                continue;
            break;
        case 4u:
            if (position != 0u || (word.size() != pattern.size() && !SphereUIChatFilter::chatRussianVowelOrSign(SferaText::byteValue(word[pattern.size()]))))
                continue;
            break;
        default:
            continue;
        }
        bool excepted = false;
        for (const auto &exception : rule.exceptions)
        {
            if (exception.empty())
                continue;
            const auto text = normalize(std::string_view(exception).substr(1u), alphabet);
            if (exception.front() == '0' && position >= text.size())
                excepted = word.substr(position - text.size(), text.size()) == text;
            else if (exception.front() == '1')
                excepted = word.substr(position + pattern.size()).starts_with(text);
            if (excepted)
                break;
        }
        if (!excepted)
            return true;
    }
    return false;
}

bool SphereUIChatFilter::matchesMessage(std::string_view message, std::size_t alphabet) const
{
    auto text = normalize(message, alphabet);
    text.erase(std::unique(text.begin(), text.end()), text.end());
    std::vector<std::string_view> words;
    for (std::size_t first = 0u; first < text.size();)
    {
        first = text.find_first_not_of(' ', first);
        if (first == std::string::npos)
            break;
        auto last = text.find(' ', first);
        if (last == std::string::npos)
            last = text.size();
        words.emplace_back(text.data() + first, last - first);
        first = last;
    }
    for (std::size_t first = 0u; first < words.size(); ++first)
    {
        if (matchesWord(words[first], alphabet))
            return true;
        if (words[first].size() > 3u)
            continue;
        std::string joined(words[first]);
        for (auto next = first + 1u; next < words.size() && words[next].size() <= 3u; ++next)
        {
            joined += words[next];
            if (matchesWord(joined, alphabet))
                return true;
        }
    }
    return false;
}

bool SphereUIChatFilter::rejects(std::string_view message) const
{
    if (rules.empty())
        return false;
    std::string visible(message);
    bool tag = false;
    for (auto &character : visible)
    {
        const auto value = character;
        if (value == '<')
            tag = true;
        if (tag)
            character = ' ';
        if (value == '>')
            tag = false;
    }
    return matchesMessage(visible, 0u) || matchesMessage(visible, 1u);
}

bool SphereUIChatFilter::invalidIdentifier(std::string_view name)
{
    std::uint32_t alphabet = 0u;
    for (std::uint8_t character : name)
    {
        std::uint32_t current = 0u;
        if (character == '-' || character == ' ' || character == '_' || (character >= '0' && character <= '9'))
            current = 0u;
        else if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
            current = 1u;
        else if (const auto letter = SferaText::unicodeCp1251()[character]; (letter >= U'\u0410' && letter <= U'\u044f') || letter == U'\u0401' || letter == U'\u0451')
            current = 2u;
        else
            return true;
        if (alphabet == 0u)
            alphabet = current;
        else if (alphabet != current && SphereUIChatFilter::chatKeyboardAmbiguous(character))
            return true;
    }
    return false;
}

std::string SphereUIHyperTextEditControl::editorHistoryPath(const SphereUIHyperTextEditControl &editor)
{
    const auto *parent = editor.parent;
    if (parent == nullptr || parent->resource_name.empty())
        return {};
    std::string profile;
    SphereUIHyperTextEditControl::historyProfile(profile);
    return "players\\" + parent->resource_name + "_" + profile + "_hyperTextEdit.log";
}

void SphereUIHyperTextEditControl::historyProfile(std::string &result)
{
    std::ifstream stream("connectn.cfg");
    std::string line, value;
    while (std::getline(stream, line))
    {
        if (line.size() < 2u || line[0] != 'M' || line[1] != 'A')
            continue;
        const auto dot = line.rfind('.');
        if (dot == std::string::npos)
            continue;
        const auto end = line.find('"', dot + 1u);
        if (end != std::string::npos)
            value += line.substr(dot + 1u, end - dot - 1u);
    }
    result.assign(value);
}

void SphereUIHyperTextEditControl::loadHistory()
{
    if (edit_modes.test(Password))
        return;
    const auto path = SphereUIHyperTextEditControl::editorHistoryPath(*this);
    if (path.empty())
        return;
    std::ifstream stream(path, std::ios::binary);
    std::string line;
    while (history.size() < maximum_history && std::getline(stream, line))
    {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        if (line.empty())
            continue;
        std::string decoded;
        transformHistory(decoded, line, true);
        history.push_back(std::move(decoded));
    }
    history_position = history.size();
}

void SphereUIHyperTextEditControl::saveHistory() const
{
    if (edit_modes.test(Password) || history.size() == 0u)
        return;
    const auto path = SphereUIHyperTextEditControl::editorHistoryPath(*this);
    if (path.empty())
        return;
    std::ofstream stream(path, std::ios::binary);
    for (std::size_t index = 0u; index < history.size() && stream; ++index)
    {
        std::string encoded{};
        transformHistory(encoded, history.at(index), false);
        stream.write(encoded.data(), encoded.size());
        stream << "\r\n";
    }
}

bool SphereUIHyperTextParser::hasPlayerPrefix(std::span<const HyperTextRun> elements)
{
    return elements.size() >= 2u && elements[0].link() != nullptr && elements[0].link()->link_kind == 2u && elements[1].isPlain() && elements[1].text.starts_with(": ");
}

bool SphereUIHyperTextParser::extractPlayerPrefix(std::string_view input, std::string *output, std::string *plain)
{
    std::vector<HyperTextRun> elements;
    std::string visible;
    parseElements(input, elements, visible);
    if (!SphereUIHyperTextParser::hasPlayerPrefix(elements))
        return false;
    SphereUIHyperTextParser::serializeChatResult(std::span(elements).first(1u), output, plain);
    return true;
}

bool SphereUIHyperTextParser::removePlayerPrefix(std::string_view input, std::string *output, std::string *plain)
{
    std::vector<HyperTextRun> elements;
    std::string visible;
    parseElements(input, elements, visible);
    if (elements.empty())
        return false;
    if (SphereUIHyperTextParser::hasPlayerPrefix(elements))
    {
        elements[1].text.erase(0u, 2u);
        elements.erase(elements.begin(), elements.begin() + (elements[1].text.empty() ? 2u : 1u));
    }
    SphereUIHyperTextParser::serializeChatResult(elements, output, plain);
    return true;
}
