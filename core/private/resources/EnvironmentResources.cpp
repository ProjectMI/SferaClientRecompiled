#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <format>
#include <fstream>
#include <ios>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "binary/Binary.h"
#include "config/ConfigDocument.h"
#include "diagnostics/ClientDiagnostics.h"
#include "environment/Environment.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "resources/FileResources.h"
#include "resources/ModelResources.h"
#include "text/Text.h"
#include "vegetation/Vegetation.h"

void SkyEnvironment::skyConfigurationError(const std::string &section)
{
    CSphereError error;
    error.write(("Illegal format of Sky.txt, line: " + section));
}

void SkyEnvironment::load(const std::string &filename)
{
    SkyEnvironment replacement;
    SphereRenderModelParameters parameters;
    parameters.load(filename);

    for (std::size_t index = 0; index < 11; ++index)
    {
        const std::string suffix(std::string_view("0123456789a").substr(index, 1u));
        if (!parameters.hasModel("c" + suffix))
            continue;
        if (!parameters.contains("c" + suffix, "r"))
            SkyEnvironment::skyConfigurationError("c" + suffix);
        auto &state = replacement.states[index];

        loadGradient(parameters, suffix, "a", state.primary);
        loadGradient(parameters, suffix, "b", state.secondary);
        state.reference = parameterColor(parameters, "c" + suffix);
        const std::string section = "d" + suffix;
        state.time = parameterScalar(parameters, section, "time");
        state.sunPhase = parameterScalar(parameters, section, "sun");
        state.sunColor = parameterChannels(parameters, section, "s");
        state.ambientColor = parameterChannels(parameters, section, "a");
    }
    replacement.sunsetState = parameterInteger(parameters, "SunsetStateN", "n");
    replacement.sunriseState = parameterInteger(parameters, "SunriseStateN", "n");
    for (const auto state : {replacement.sunsetState, replacement.sunriseState})
    {
        if (state < 0 || state >= replacement.states.size())
            SkyEnvironment::skyConfigurationError("Sun state index");
    }
    *this = std::move(replacement);
}

void EnvironmentZones::load(const std::string &filename)
{
    SphereRenderConfigDocument::setStorageMode(SphereRenderConfigDocumentStorageMode::Plain);
    const auto document = SphereRenderConfigDocument::open(filename);
    const auto count = document.arraySize("zonesParams").value_or(0);
    std::vector<EnvironmentZone> replacement;
    replacement.reserve(count);

    for (std::size_t index = 0; index < count; ++index)
    {
        auto *configuration = document.objectAt("zonesParams", index);
        if (configuration == nullptr)
        {
            configurationError(index, "zoneParamsCfg is NULL");
            continue;
        }
        EnvironmentZone zone{};

        zone.originX = parameterScalar(*configuration, index, "xPatchMin");
        zone.originZ = parameterScalar(*configuration, index, "zPatchMin");
        zone.minimumX = parameterScalar(*configuration, index, "xMin");
        zone.maximumX = parameterScalar(*configuration, index, "xMax");
        zone.minimumZ = parameterScalar(*configuration, index, "zMin");
        zone.maximumZ = parameterScalar(*configuration, index, "zMax");
        zone.borderFade = parameterScalar(*configuration, index, "borderFadeDist");
        zone.fogParameters = {parameterScalar(*configuration, index, "skyFogAlpha"), parameterScalar(*configuration, index, "fogNear"), parameterScalar(*configuration, index, "fogFar")};
        if (configuration->arraySize("dayColors").value_or(0) != 8)
            configurationError(index, "wrong size of dayColors");
        for (std::size_t day = 0; day < 8; ++day)
        {
            auto *colors = configuration->objectAt("dayColors", day);
            if (colors == nullptr)
            {
                configurationError(index, "dayColorCfg is NULL");
                continue;
            }

            zone.fogColors[day] = parameterColor(*colors, index, day, "fogColor");
            zone.ambientColors[day] = parameterColor(*colors, index, day, "ambientColor");
            zone.sunColors[day] = parameterColor(*colors, index, day, "sunColor");
        }
        replacement.push_back(zone);
    }
    zones = std::move(replacement);
}

void EnvironmentZones::configurationError(std::size_t zone, std::string_view field)
{
    CSphereError error;
    error.write(std::format("Wrong format of \"Landscape\\zoning.cfg\" : zonesParams[{}] : {}", zone, field));
}

float EnvironmentZones::parameterScalar(const SphereRenderConfigDocument &configuration, std::size_t index, std::string_view name)
{
    const auto value = configuration.real(name);
    if (!value)
        configurationError(index, name);
    return value.value_or(0.0f);
}

float EnvironmentZones::colorComponent(const SphereRenderConfigDocument &colors, std::size_t index, std::size_t day, std::string_view name, std::size_t axis)
{
    const auto value = colors.realAt(name, axis);
    if (!value)
        configurationError(index, std::string(name) + "[" + std::to_string(day) + "]");
    return value.value_or(0.0f);
}

SferaVec3F EnvironmentZones::parameterColor(const SphereRenderConfigDocument &colors, std::size_t index, std::size_t day, std::string_view name)
{
    return {colorComponent(colors, index, day, name, 0), colorComponent(colors, index, day, name, 1), colorComponent(colors, index, day, name, 2)};
}

int SkyEnvironment::parameterInteger(const SphereRenderModelParameters &parameters, const std::string &section, std::string_view key)
{
    const auto value = parameters.intValue(section, key);
    if (!value)
        SkyEnvironment::skyConfigurationError(section);
    return value.value_or(0);
}

float SkyEnvironment::parameterScalar(const SphereRenderModelParameters &parameters, const std::string &section, std::string_view key)
{
    const auto value = parameters.floatValue(section, key);
    if (!value)
        SkyEnvironment::skyConfigurationError(section);
    return value.value_or(0.0f);
}

SferaVec3F SkyEnvironment::parameterChannels(const SphereRenderModelParameters &parameters, const std::string &section, std::string_view prefix)
{
    SferaVec3F result{};
    constexpr std::array<std::string_view, 3> names{"r", "g", "b"};
    for (std::size_t channel = 0; channel < names.size(); ++channel)
        result.setComponent(channel, SferaNumeric::real32(parameterInteger(parameters, section, std::string(prefix) + std::string(names[channel]))));
    return result;
}

SferaVec4F SkyEnvironment::parameterColor(const SphereRenderModelParameters &parameters, const std::string &section)
{
    const auto rgb = parameterChannels(parameters, section, {});
    const float alpha = SferaNumeric::real32(parameterInteger(parameters, section, "a"));
    return SferaVec4F{rgb.x, rgb.y, rgb.z, alpha};
}

void SkyEnvironment::loadGradient(const SphereRenderModelParameters &parameters, const std::string &suffix, std::string_view prefix, std::span<SkyStateGradientKey> keys)
{
    for (std::size_t sample = 0; sample < keys.size(); ++sample)
    {
        std::string section = std::string(prefix) + suffix;
        section += std::to_string(sample);
        keys[sample] = {parameterColor(parameters, section), parameterScalar(parameters, section, "p")};
    }
}

std::string WeatherScenarios::weatherIndex(std::string_view prefix, std::size_t index, std::size_t digits)
{
    const auto number = std::to_string(index);
    return std::string(prefix) + std::string(number.size() < digits ? digits - number.size() : 0u, '0') + number;
}

[[noreturn]] void WeatherScenarios::weatherFormatError(std::string_view model, std::string_view parameter)
{
    WorldDiagnostics::fail((std::string("wrong format of weather.txt\n") + std::string(model) + ", " + std::string(parameter)));
}

std::string WeatherScenarios::weatherName(std::string_view name)
{
    if (name.size() >= 20)
        WeatherScenarios::weatherFormatError(name, "texture name too long");
    return std::string(name);
}

void WeatherScenarios::load(const std::string &filename)
{
    WeatherScenarios replacement;
    SphereRenderModelParameters parameters;
    parameters.load(filename);

    constexpr std::string_view durationJitter = "05185514038799035566164306887187530785282430311941";
    for (std::size_t index = 0; index < 100; ++index)
    {
        const auto model = WeatherScenarios::weatherIndex("s", index);
        if (!parameters.hasModel(model))
            break;
        WeatherScenario scenario;
        const auto duration = 1LL * parameterInteger(parameters, model, "stime") + durationJitter[index % durationJitter.size()] - '0';
        if (duration <= 0 || duration > INT32_MAX)
            WeatherScenarios::weatherFormatError(model, "stime");
        scenario.duration = SferaNumeric::signedWord(SferaNumeric::lowWord(duration));
        scenario.sky = skyNames(parameters, model);
        scenario.skyStart = parameterNumber(parameters, model, "tsky1");
        scenario.skyEnd = parameterNumber(parameters, model, "tsky2");
        for (std::size_t frameIndex = 0; frameIndex < 10; ++frameIndex)
        {
            const auto key = model + "_" + std::to_string(frameIndex);
            if (!parameters.hasModel(key))
                break;
            const auto time = std::trunc((scenario.duration - 0.009999999776482582) * parameterNumber(parameters, key, "t"));
            if (!std::isfinite(time) || time < 0 || time >= scenario.duration)
                WeatherScenarios::weatherFormatError(key, "t");
            WeatherKeyframe frame{SferaNumeric::truncateInt(time),
                                  {parameterNumber(parameters, key, "r"), parameterNumber(parameters, key, "fl1"), parameterNumber(parameters, key, "fl2"), parameterNumber(parameters, key, "cs")}};
            if (!scenario.keyframes.empty() && frame.time < scenario.keyframes.back().time)
                WeatherScenarios::weatherFormatError(key, "keyframe order");
            scenario.keyframes.push_back(frame);
        }
        if (scenario.keyframes.empty())
            WeatherScenarios::weatherFormatError(model, "missing keyframes");
        replacement.scenarios.push_back(std::move(scenario));
    }
    for (std::size_t index = 0; index < 30; ++index)
    {
        const auto model = WeatherScenarios::weatherIndex("t", index);
        if (!parameters.hasModel(model))
            break;
        SceneSkyLayer texture;
        texture.texture = WeatherScenarios::weatherName(parameterText(parameters, model, "ntex"));
        texture.projectionWarp = parameterNumber(parameters, model, "sc1");
        texture.uvScale = parameterNumber(parameters, model, "sc2");
        texture.trackOffset = parameterInteger(parameters, model, "scrll") != 0;
        texture.minimumTime = parameterNumber(parameters, model, "time1");
        texture.maximumTime = parameterNumber(parameters, model, "time2");
        for (std::size_t sample = 0; sample < texture.colors.size(); ++sample)
        {
            texture.colors[sample] = {parameterNumber(parameters, model + "c", WeatherScenarios::weatherIndex("r", sample)),
                                      parameterNumber(parameters, model + "c", WeatherScenarios::weatherIndex("g", sample)),
                                      parameterNumber(parameters, model + "c", WeatherScenarios::weatherIndex("b", sample))};
        }
        replacement.textures.push_back(std::move(texture));
    }
    for (std::size_t item = 0; item < 200; ++item)
    {
        const auto model = WeatherScenarios::weatherIndex("q", item, 3);
        if (!parameters.hasModel(model))
            break;
        const auto index = parameterInteger(parameters, model, "s");
        if (index < 0 || std::cmp_greater_equal(index, replacement.scenarios.size()))
            WeatherScenarios::weatherFormatError(model, "s");
        const auto duration = replacement.scenarios[index].duration;
        if (duration > INT32_MAX - replacement.totalDuration)
            WeatherScenarios::weatherFormatError(model, "total duration overflow");
        replacement.sequence.push_back(SferaNumeric::lowHalf(SferaNumeric::word(index)));
        replacement.totalDuration += duration;
    }
    if (replacement.sequence.empty())
        WeatherScenarios::weatherFormatError(filename, "missing sequence");
    for (std::size_t index = 0; index < 30; ++index)
    {
        const auto model = WeatherScenarios::weatherIndex("c", index);
        if (!parameters.hasModel(model))
            break;
        replacement.pairs.push_back(skyNames(parameters, model));
    }
    *this = std::move(replacement);
}

float WeatherScenarios::parameterNumber(const SphereRenderModelParameters &parameters, std::string_view model, std::string_view key)
{
    const auto value = parameters.floatValue(model, key);
    if (!value)
        WeatherScenarios::weatherFormatError(model, key);
    return *value;
}

int WeatherScenarios::parameterInteger(const SphereRenderModelParameters &parameters, std::string_view model, std::string_view key)
{
    const auto value = parameters.intValue(model, key);
    if (!value)
        WeatherScenarios::weatherFormatError(model, key);
    return *value;
}

std::string_view WeatherScenarios::parameterText(const SphereRenderModelParameters &parameters, std::string_view model, std::string_view key)
{
    const auto value = parameters.stringValue(model, key);
    if (!value)
        WeatherScenarios::weatherFormatError(model, key);
    return *value;
}

std::string WeatherScenarios::skyTextureName(const SphereRenderModelParameters &parameters, std::string_view model, std::string_view key)
{
    auto result = WeatherScenarios::weatherName(parameterText(parameters, model, key));
    if (SferaText::asciiEqual(result, "none"))
        result.clear();
    return result;
}

WeatherSkyPair WeatherScenarios::skyNames(const SphereRenderModelParameters &parameters, std::string_view model)
{
    return {skyTextureName(parameters, model, "nsky1"), skyTextureName(parameters, model, "nsky2")};
}

void GrassMapMngr::loadGrassMap(int column, int row, std::span<std::uint8_t> destination)
{
    if (destination.empty())
        return;
    auto filename = std::format("Landscape\\GrassMap\\GrassMap_{:02d}_{:02d}.bin", column, row);
    std::ifstream stream;
    for (const std::string &path : g_sfera_files.candidatePaths(filename, true))
    {
        stream.open(path, std::ios::binary);
        if (stream.is_open())
            break;
        stream.clear();
    }
    if (stream.is_open())
        SferaBinary::read(stream, destination);
}

void SphereWorldVegetationPatterns::initializeGrass()
{
    grass_patterns_.clear();
    addGrass(1u, {"002", "002", "002", "014", "014", "1_21", "1_41", "", "", ""});
    addGrass(2u, {"018", "018", "018", "006", "003", "1_11", "1_31", "", "", ""});
    addGrass(3u, {"003", "003", "003", "009", "004", "1_21", "1_61", "", "", ""});
    addGrass(4u, {"010", "010", "002", "002", "005", "", "", "", "", ""});
    addGrass(5u, {"009", "009", "009", "004", "000", "1_21", "1_41", "1_41", "", ""});
    addGrass(6u, {"016", "016", "016", "004", "011", "1_11", "1_21", "1_31", "", ""});
    addGrass(7u, {"014", "014", "007", "007", "007", "1_41", "1_51", "", "", ""});
    addGrass(8u, {"013", "013", "013", "005", "004", "", "", "", "", ""});
    addGrass(9u, {"007", "007", "003", "003", "013", "", "", "", "", ""});
    addGrass(10u, {"002", "002", "009", "009", "003", "1_11", "1_31", "", "", ""});
    addGrass(11u, {"012", "012", "005", "005", "013", "", "", "", "", ""});
    addGrass(12u, {"012", "012", "012", "004", "009", "1_61", "", "", "", ""});
    addGrass(13u, {"007", "007", "007", "007", "015", "1_11", "1_21", "1_51", "", ""});
    addGrass(14u, {"017", "017", "017", "005", "005", "", "", "", "", ""});
    addGrass(15u, {"001", "001", "001", "001", "007", "", "", "", "", ""});
    addGrass(16u, {"000", "000", "000", "000", "000", "", "", "", "", ""});
    addGrass(17u, {"000", "000", "000", "000", "000", "", "", "", "", ""});
    addGrass(18u, {"000", "000", "000", "000", "000", "", "", "", "", ""});
    addGrass(19u, {"101", "101", "101", "101", "101", "", "", "", "", ""});
    addGrass(20u, {"102", "102", "102", "102", "102", "", "", "", "", ""});
    addGrass(21u, {"100", "100", "100", "101", "101", "", "", "", "", ""});
    addGrass(22u, {"101", "101", "101", "102", "102", "", "", "", "", ""});
    addGrass(23u, {"100", "100", "100", "102", "102", "", "", "", "", ""});
    addGrass(24u, {"100", "100", "100", "101", "102", "", "", "", "", ""});
    addGrass(25u, {"100", "100", "101", "102", "102", "", "", "", "", ""});
    addGrass(26u, {"101", "101", "101", "101", "101", "", "", "", "", ""});
    addGrass(27u, {"102", "102", "102", "102", "102", "", "", "", "", ""});
    addGrass(28u, {"100", "100", "100", "101", "101", "", "", "", "", ""});
    addGrass(29u, {"101", "101", "101", "102", "102", "", "", "", "", ""});
    addGrass(30u, {"100", "100", "100", "102", "102", "", "", "", "", ""});
}
