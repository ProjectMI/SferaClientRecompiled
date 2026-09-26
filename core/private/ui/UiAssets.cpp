#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <filesystem>
#include <functional>
#include <limits>
#include <memory>
#include <new>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <utility>
#include <vector>

#include "config/InterfaceConfiguration.h"
#include "config/SimpleParser.h"
#include "diagnostics/ClientDiagnostics.h"
#include "input/Cursors.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "resources/TextureRepository.h"
#include "text/Fonts.h"
#include "text/HyperText.h"
#include "text/Parsing.h"
#include "text/Text.h"
#include "ui/GameInterfaceManager.h"
#include "ui/Rendering.h"
#include "ui/ScriptInterface.h"
#include "ui/Sprite.h"
#include "ui/UiRuntime.h"
#include "ui/Window.h"

void SphereUIInterfaceManager::loadAllWindowTemplates()
{
    std::vector<std::filesystem::path> files;
    std::error_code error;
    for (std::filesystem::directory_iterator entry("Effects", error), end; !error && entry != end; entry.increment(error))
        if (!entry->is_directory(error) && SferaText::asciiEqual(entry->path().extension().string(), ".ui"))
            files.push_back(entry->path());
    float completed = 0.0f;
    const float fraction = files.empty() ? 0.0f : 1.0f / files.size();
    for (const auto &file : files)
    {
        if (SferaText::asciiEqual(file.filename().string(), "loadscreen.ui"))
            continue;
        loadWindowTemplates(file.string());
        completed += fraction;
        GameInterface::updateLoadingProgress(SferaNumeric::truncateInt(completed * 30.0 + 30.0));
    }
}

bool SphereUIInterfaceManager::initializeResources()
{
    if (!prepareResources())
        return false;
    GameInterface::updateLoadingProgress(15);
    loadHyperTexts();
    GameInterface::updateLoadingProgress(30);
    loadAllWindowTemplates();
    finishInitialization();
    return true;
}

std::string SphereUIInterfaceManager::localizedPath(std::string_view filename)
{
    std::string resolved(filename);
    const auto &suffix = g_sfera_font_runtime.language_suffix;
    if (!resolved.empty() && !suffix.empty())
    {
        const auto extension = resolved.rfind('.');
        resolved.insert(extension == std::string::npos ? resolved.size() : extension, suffix);
    }
    return resolved;
}

std::shared_ptr<const SphereUIUiSprite> SphereUIInterfaceManager::sharedSprite(std::string_view name)
{
    if (name.empty())
        return {};
    const auto found = std::find_if(sprites.begin(), sprites.end(), std::bind_front(&SphereUIInterfaceManager::spriteNamed, name));
    return found == sprites.end() ? nullptr : *found;
}

std::shared_ptr<const SphereUIUiSprite> SphereUIInterfaceManager::acquireSprite(std::string_view name)
{
    if (name.empty())
        return {};
    if (auto sprite = sharedSprite(name))
        return sprite;
    if (g_sfera_textures.find(name) == -1)
        return {};
    auto sprite = std::make_shared<SphereUIUiSprite>();
    sprite->setImage(name);
    return sprite;
}

void SphereUIInterfaceManager::loadSprites(const std::string &filename)
{
    SferaSimpleParser parser{};
    parser.load(filename);
    parser.setBlockRange(nullptr);
    SferaParserRange range{};
    std::vector<std::shared_ptr<const SphereUIUiSprite>> replacement;
    while (parser.nextBlock("sprite", &range))
    {
        auto sprite = std::make_shared<SphereUIUiSprite>();
        sprite->loadUi(filename, parser, range);
        replacement.push_back(std::move(sprite));
    }
    sprites = std::move(replacement);
}


bool SphereUIInterfaceManager::loadWindowTemplates(const std::string &filename)
{
    SferaSimpleParser parser{};
    parser.load(filename);
    parser.setBlockRange(nullptr);
    SferaParserRange range{};
    while (parser.nextBlock("windowUI", &range))
    {
        auto window = SphereUIRuntime::makeControl(SphereUIUiControlKind::window);
        if (window == nullptr)
            throw std::bad_alloc();
        if (!window->loadUi(filename, parser, range))
            continue;
        if (window->getResourceName().empty())
        {
            const auto message = std::string("Window name is missing in ") + filename + " at lines " + std::to_string(range.begin) + "-" + std::to_string(range.end);
            CSphereError error;
            error.write(message);
        }
        window_templates.push_back(std::move(window));
    }
    return true;
}

SphereUIWindow *SphereUIInterfaceManager::templateWindow(std::string_view name) const
{
    if (name.empty())
        return nullptr;
    const auto found = std::find_if(window_templates.begin(), window_templates.end(), std::bind_front(&SphereUIInterfaceManager::templateNamed, name));
    return found == window_templates.end() ? nullptr : found->get();
}


void SphereUIInterfaceManager::loadHyperTexts()
{
    const std::string suffix = std::string(g_sfera_font_runtime.language_suffix) + ".hts";
    std::error_code error;
    for (std::filesystem::directory_iterator entry("Language", error), end; !error && entry != end; entry.increment(error))
    {
        if (entry->is_directory(error))
            continue;
        const auto basename = entry->path().filename().string();
        if (basename.size() < suffix.size() || !SferaText::asciiEqual(std::string_view(basename).substr(basename.size() - suffix.size()), suffix))
            continue;
        auto document = std::make_unique<SphereUIHyperTextDocument>();
        if (!document->load(entry->path().string()))
            continue;
        auto name = entry->path().string();
        if (!g_sfera_font_runtime.language_suffix.empty())
            if (const auto language = name.rfind('_'); language != std::string::npos)
                name.replace(language, std::string::npos, ".hts");
        document->setName(name);
        hypertext_documents.push_back(std::move(document));
    }
}

SphereUIHyperTextDocument *SphereUIInterfaceManager::findHyperText(std::string_view name) const
{
    if (name.empty())
        return nullptr;
    const auto found = std::find_if(hypertext_documents.begin(), hypertext_documents.end(), std::bind_front(&SphereUIInterfaceManager::hyperTextNamed, name));
    return found == hypertext_documents.end() ? nullptr : found->get();
}


bool SphereUIInterfaceManager::loadLocalizedStrings()
{
    localized_strings.push_back({"null", "NULL"});
    SferaSimpleParser parser{};
    parser.load(localizedPath("Language\\strings.ui"));
    SferaParserRange range{};
    if (!parser.findBlock("stringsUI", &range, nullptr, 1))
        return true;
    parser.setScanRange(&range);
    while (parser.nextValue("string"))
    {
        std::string key, value;
        if (parser.readString(0u, key) && parser.readQuotedString(1u, value))
            localized_strings.push_back({key, value});
    }
    return true;
}

std::string_view SphereUIInterfaceManager::localizedValue(std::string_view key) const
{
    const auto found = std::find_if(localized_strings.begin(), localized_strings.end(), std::bind_front(&SphereUIInterfaceManager::localizedKey, key));
    if (found != localized_strings.end())
        return found->value;
    if (!localized_strings.empty())
        return localized_strings.front().value;
    return {};
}

std::string_view SphereUIInterfaceManager::localizedText(std::string_view key) const
{
    return localized_strings.empty() ? key : localizedValue(key);
}


SphereUISavedWindowPosition *SphereUIInterfaceManager::savedPosition(std::string_view name, bool create)
{
    if (name.empty())
        return nullptr;
    const auto found = std::find_if(saved_positions.begin(), saved_positions.end(), std::bind_front(&SphereUIInterfaceManager::positionNamed, name));
    if (found != saved_positions.end())
        return &*found;
    return create ? &saved_positions.emplace_back(SphereUISavedWindowPosition{std::string(name)}) : nullptr;
}

bool SphereUIInterfaceManager::findSavedPosition(std::string_view name, SferaCursorPosition &position)
{
    const auto *saved = savedPosition(name, false);
    if (saved == nullptr)
        return false;
    position = {saved->x, saved->y};
    return true;
}

void SphereUIInterfaceManager::saveWindowPosition(SphereUIWindow &window)
{
    auto *saved = savedPosition(window.getName(), true);
    if (saved != nullptr)
        window.getAbsolutePosition(saved->x, saved->y);
}

std::size_t SphereUIInterfaceManager::savedPositionsSize() const
{
    if (saved_positions.empty())
        return 0u;
    std::size_t size = 4u;
    for (const auto &position : saved_positions)
    {
        if (size > std::numeric_limits<std::size_t>::max() - 9u || position.name.size() > std::numeric_limits<std::size_t>::max() - 9u - size)
            throw std::length_error("Saved window positions exceed the native buffer size limit");
        size += position.name.size() + 9u;
    }
    return size;
}

void SphereUIInterfaceManager::writeSavedPositions(std::span<std::byte> destination) const
{
    if (destination.empty())
        return;
    if (destination.size() < std::max<std::size_t>(4u, savedPositionsSize()))
        throw std::length_error("Saved window positions do not fit in the destination");
    std::memcpy(destination.data(), "UIV1", 4u);
    destination = destination.subspan(4u);
    for (const auto &position : saved_positions)
    {
        std::memcpy(destination.data(), position.name.c_str(), position.name.size() + 1u);
        destination = destination.subspan(position.name.size() + 1u);
        std::array<double, 2> pixels;
        pixels[0] = position.x;
        pixels[1] = position.y;
        std::array<double, 2> extent;
        extent[0] = g_sfera_graphics_runtime.display_width;
        extent[1] = g_sfera_graphics_runtime.display_height;
        std::array<float, 2> coordinates;
        std::transform(pixels.begin(), pixels.end(), extent.begin(), coordinates.begin(), &SphereUIInterfaceManager::normalizedPosition);
        const auto bytes = std::as_bytes(std::span(coordinates));
        std::memcpy(destination.data(), bytes.data(), bytes.size());
        destination = destination.subspan(bytes.size());
    }
}

void SphereUIInterfaceManager::readSavedPositions(std::span<const std::byte> source)
{
    saved_positions.clear();
    if (source.size() < 4u || std::memcmp(source.data(), "UIV1", 4u) != 0)
        return;
    source = source.subspan(4u);
    while (!source.empty())
    {
        const auto end = std::find(source.begin(), source.end(), std::byte{});
        if (end == source.end())
            return;
        const std::size_t name_size = end - source.begin();
        if (source.size() - name_size - 1u < sizeof(float) * 2u)
            return;
        SphereUISavedWindowPosition position{std::string(SferaText::fromBytes(source.first(name_size)))};
        source = source.subspan(name_size + 1u);
        float coordinates[2]{};
        std::memcpy(coordinates, source.data(), sizeof(coordinates));
        source = source.subspan(sizeof(coordinates));
        const double normalized_x = coordinates[0], normalized_y = coordinates[1];
        const double x = normalized_x * g_sfera_graphics_runtime.display_width;
        const double y = normalized_y * g_sfera_graphics_runtime.display_height;
        if (!std::isfinite(x) || !std::isfinite(y) || x < std::numeric_limits<int>::min() || x > std::numeric_limits<int>::max() || y < std::numeric_limits<int>::min() ||
            y > std::numeric_limits<int>::max())
            return;
        position.x = SferaNumeric::truncateInt(x);
        position.y = SferaNumeric::truncateInt(y);
        saved_positions.push_back(std::move(position));
    }
}

bool SphereUIInterfaceManager::prepareResources()
{
    if (initialized)
        return false;
    g_sfera_fonts.initialize();
    SphereUIInterfaceConfiguration::open("control.cfg");
    g_sfera_interface.cross_enabled = true;
    g_sfera_interface.cross_enabled = SphereUIInterfaceConfiguration::readInteger("EN_CROSS", g_sfera_interface.cross_enabled) != 0;
    g_sfera_interface.sounds_enabled = SphereUIInterfaceConfiguration::readInteger("INTFS_SOUNDS", g_sfera_interface.sounds_enabled) != 0;
    if (!cursor)
    {
        cursor = std::make_unique<SferaInterfaceCursor>();
        cursor->loadTextures();
    }
    g_sfera_fonts.loadConfiguration();
    cursor->setKind(255u);
    setCursorKind(255u, 0, 0);
    setCursorImage(std::nullopt, 0, 0);
    loadLocalizedStrings();
    loadWindowTemplates("Effects\\loadscreen.ui");
    loadSprites("Effects\\sprites.ui");
    return true;
}

bool SphereUIInterfaceManager::spriteNamed(std::string_view name, const std::shared_ptr<const SphereUIUiSprite> &sprite)
{
    return SferaText::asciiEqual(sprite->name, name);
}

bool SphereUIInterfaceManager::templateNamed(std::string_view name, const std::unique_ptr<SphereUIWindow> &window)
{
    return window != nullptr && SferaText::asciiEqual(window->getResourceName(), name);
}

bool SphereUIInterfaceManager::hyperTextNamed(std::string_view name, const std::unique_ptr<SphereUIHyperTextDocument> &document)
{
    return document != nullptr && SferaText::asciiEqual(document->name, name);
}

bool SphereUIInterfaceManager::localizedKey(std::string_view key, const SphereUILocalizedTextEntry &entry)
{
    return SferaText::asciiEqual(entry.key, key);
}


float SphereUIInterfaceManager::normalizedPosition(double pixel, double dimension)
{
    return SferaNumeric::real32(pixel / dimension);
}
