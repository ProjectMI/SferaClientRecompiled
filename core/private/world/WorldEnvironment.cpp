#include <algorithm>
#include <array>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <format>
#include <memory>
#include <span>
#include <string>
#include <utility>
#include <vector>

#include "diagnostics/ClientDiagnostics.h"
#include "geometry/Geometry.h"
#include "math/Color.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/Model.h"
#include "render/SceneRenderer.h"
#include "resources/ModelResources.h"
#include "resources/TerrainResources.h"
#include "runtime/Clock.h"
#include "script/MbcRuntime.h"
#include "terrain/Terrain.h"
#include "vegetation/Vegetation.h"
#include "world/GameCalendar.h"
#include "world/WorldObjects.h"

std::uint32_t SferaGameCalendar::ticks(std::uint32_t calendar)
{
    const auto days = (component(calendar, SferaGameCalendarComponentYear) - firstYear) * daysPerYear + daysBeforeMonth(component(calendar, SferaGameCalendarComponentMonth)) +
                      component(calendar, SferaGameCalendarComponentDay);
    const auto hours = days * hoursPerDay + component(calendar, SferaGameCalendarComponentHour);
    const auto minutes = hours * minutesPerHour + component(calendar, SferaGameCalendarComponentMinute);
    return minutes * quartersPerMinute + component(calendar, SferaGameCalendarComponentQuarter);
}

std::uint32_t SferaGameCalendar::fromUnixTime(std::int64_t timestamp)
{
    constexpr auto unixEpoch = std::chrono::sys_days{std::chrono::year{1970} / std::chrono::January / 1};
    constexpr auto calendarEpoch = std::chrono::sys_days{std::chrono::year{1349} / std::chrono::January / 1};
    constexpr auto epochOffset = std::chrono::duration_cast<std::chrono::seconds>(unixEpoch - calendarEpoch).count();
    constexpr std::int64_t quartersPerRealMinute = 48;
    constexpr std::uint32_t epochYear = 8192;
    const auto total = (timestamp + epochOffset) * quartersPerRealMinute / 60;
    const auto elapsedYears = total / quartersPerYear;
    const auto day = total % quartersPerYear / quartersPerDay;
    const auto time = total % quartersPerDay;
    std::uint32_t month = 1;
    while (month < 12 && day >= daysBeforeMonth(month + 1))
        ++month;
    const std::uint32_t date = SferaNumeric::lowWord(day - daysBeforeMonth(month) + 1);
    return pack(epochYear + SferaNumeric::lowWord(elapsedYears), month, date, SferaNumeric::lowWord(time / quartersPerHour), SferaNumeric::lowWord(time % quartersPerHour / quartersPerMinute),
                SferaNumeric::lowWord(time % quartersPerMinute));
}

std::uint32_t SferaGameCalendar::component(std::uint32_t calendar, int index)
{
    const auto &part = field(index);
    return ((calendar >> part.shift) & part.mask()) + part.bias;
}

std::uint32_t SferaGameCalendar::withComponent(std::uint32_t calendar, int index, std::uint32_t value)
{
    const auto &part = field(index);
    return (calendar & ~(part.mask() << part.shift)) | (((value - part.bias) & part.mask()) << part.shift);
}

std::uint32_t SferaGameCalendar::advance(std::uint32_t calendar)
{
    const auto quarter = component(calendar, SferaGameCalendarComponentQuarter);
    calendar = withComponent(calendar, SferaGameCalendarComponentQuarter, quarter + 1);
    if (quarter != 3)
        return calendar;
    calendar = withComponent(calendar, SferaGameCalendarComponentMinute, component(calendar, SferaGameCalendarComponentMinute) + 1);
    if (component(calendar, SferaGameCalendarComponentMinute) != 60)
        return calendar;
    calendar = withComponent(calendar, SferaGameCalendarComponentMinute, 0);
    calendar = withComponent(calendar, SferaGameCalendarComponentHour, component(calendar, SferaGameCalendarComponentHour) + 1);
    if (component(calendar, SferaGameCalendarComponentHour) != 24)
        return calendar;
    calendar = withComponent(calendar, SferaGameCalendarComponentHour, 0);
    const auto day = component(calendar, SferaGameCalendarComponentDay), month = component(calendar, SferaGameCalendarComponentMonth);
    calendar = withComponent(calendar, SferaGameCalendarComponentDay, day + 1);
    if (day < SferaGameCalendar::daysInMonth(month))
        return calendar;
    calendar = withComponent(calendar, SferaGameCalendarComponentDay, 1);
    calendar = withComponent(calendar, SferaGameCalendarComponentMonth, month + 1);
    if (component(calendar, SferaGameCalendarComponentMonth) <= 12)
        return calendar;
    calendar = withComponent(calendar, SferaGameCalendarComponentMonth, 1);
    return withComponent(calendar, SferaGameCalendarComponentYear, component(calendar, SferaGameCalendarComponentYear) + 1);
}

std::uint32_t WorldClock::calendarTicks()
{
    return SferaGameCalendar::ticks(g_sfera_mbc_runtime.game_calendar);
}

std::uint32_t SphereWorldVegetation::vegetationChoice(std::uint32_t count)
{
    return std::rand() * count / 32768u;
}

float SphereWorldVegetation::vegetationJitter(float center)
{
    return SferaNumeric::real32((std::rand() * 0.5 / 32767.0 - 0.25) * 8.33329963684082 + center);
}

void SphereWorldVegetation::createCell(int cell_x, int cell_z, SphereWorldGrassCell &cell)
{
    std::array<SphereWorldGrassInstance, 36> placements{};
    const float origin_x = SferaNumeric::real32(cell_x * 8.33329963684082), origin_z = SferaNumeric::real32(cell_z * 8.33329963684082);
    const std::array<std::array<float, 2>, 4> samples{{{6.24f, 3.73f}, {2.21f, 1.17f}, {2.21f, 5.60f}, {6.24f, 7.15f}}};
    std::array<std::uint32_t, 3> color{};
    std::array<std::size_t, 36> model_handles{};
    const SphereWorldVegetationPatternsGrassPattern *last_pattern = nullptr;
    std::size_t count = 0;
    bool scattered = false;
    cell.object_handle = 0;
    for (const auto &sample : samples)
    {
        const float x = origin_x + sample[0], z = origin_z + sample[1];
        std::array<std::uint32_t, 3> local_color{};
        TerrainQueries::sampleColor(x, z, local_color[0], local_color[1], local_color[2]);
        for (std::size_t channel = 0; channel < 3; ++channel)
            color[channel] += local_color[channel];
        auto type = g_sfera_vegetation.map_cache.grassType(x, z);
        if (!type)
            continue;
        if (alternatePatterns())
            type += 15;
        last_pattern = &patterns.grass(type);
        SferaVec3F angles{};
        SferaPlaneF plane{};
        float height = 0;
        if (TerrainQueries::placementOrientation(x, z, angles, height, plane) == 1u)
        {
            const auto name = "grass" + last_pattern->variants[SphereWorldVegetation::vegetationChoice(5)];
            model_handles[count] = g_sfera_models.find(name);
            placements[count++] = {nullptr, {x, height, z}, angles, 1, plane.normal};
        }
        else
        {
            for (std::uint32_t attempt = 0; attempt < 8u; ++attempt)
            {
                const float dx = SphereWorldVegetation::vegetationJitter(x);
                const float dz = SphereWorldVegetation::vegetationJitter(z);
                if (!TerrainQueries::surface(dx, dz, height, plane))
                    continue;
                scattered = true;
                const auto name = std::format("grass_s0{}", SphereWorldVegetation::vegetationChoice(4));
                model_handles[count] = g_sfera_models.find(name);
                auto &instance = placements[count++];
                instance.model = nullptr;
                instance.position = {dx, height, dz};
                instance.vertical_scale = SphereVegetationHelpers::vegetationRandom(0.5, 0.6000000238418579);
                const float tilt = SferaNumeric::real32(0.3141593337059021 - instance.vertical_scale * 0.1745329648256302);
                instance.rotation.x = SphereVegetationHelpers::vegetationRandom(6.283185958862305);
                instance.rotation.y = SphereVegetationHelpers::vegetationRandom(tilt);
                instance.rotation.z = SphereVegetationHelpers::vegetationRandom(tilt);
                instance.normal = plane.normal;
            }
        }
    }
    for (auto &channel : color)
        channel /= 4u;
    if (count == 4u && !scattered)
    {
        const auto attempts = SphereWorldVegetation::vegetationChoice(20);
        for (std::uint32_t attempt = 0; attempt < attempts; ++attempt)
        {
            const float x = SphereVegetationHelpers::vegetationRandom(8.33329963684082, origin_x), z = SphereVegetationHelpers::vegetationRandom(8.33329963684082, origin_z);
            SferaPlaneF plane{};
            float height = 0;
            if (!TerrainQueries::surface(x, z, height, plane))
                continue;
            const auto &variant = last_pattern->variants[SphereWorldVegetation::vegetationChoice(5) + 5];
            if (variant.empty())
                continue;
            const auto name = "flower" + variant;
            model_handles[count] = g_sfera_models.find(name);
            placements[count++] = {nullptr, {x, height, z}, {SphereVegetationHelpers::vegetationRandom(6.283185958862305), 0, 0}, 1, plane.normal};
        }
    }
    if (!count)
        return;
    float minimum = placements[0].position.y, maximum = minimum;
    for (std::size_t index = 1; index < count; ++index)
    {
        minimum = std::min(minimum, placements[index].position.y);
        maximum = std::max(maximum, placements[index].position.y);
    }
    const double precise_maximum = maximum;
    maximum = SferaNumeric::real32(precise_maximum + 1);
    minimum = SferaNumeric::real32(minimum - 2.5);
    const SferaVec3F center{origin_x + 4.16664981842041f, maximum, origin_z + 4.16664981842041f};
    for (std::size_t index = 0; index < count; ++index)
    {
        placements[index].position = placements[index].position - center;
        placements[index].model = g_sfera_models.model(model_handles[index]);
    }
    auto model = SphereWorldGrassGeometry::build(std::span<const SphereWorldGrassInstance>(placements.data(), count), maximum - minimum);
    const auto handle = g_sfera_world_objects.create("grass1_21", 0, 0, false);
    auto *object = g_sfera_world_objects.object(handle);
    if (object == nullptr)
        return;
    object->model_source = std::move(model);
    object->position = center;
    object->rotation = {};
    object->visible = false;
    object->lighting_color =
        SferaColor::rgba(SphereRenderSceneRenderer::color_remap[color[0]], SphereRenderSceneRenderer::color_remap[color[1]], SphereRenderSceneRenderer::color_remap[color[2]]).argb();
    try
    {
        g_sfera_world_objects.updateSpatialIndex(handle);
    }
    catch (...)
    {
        g_sfera_world_objects.destroy(handle);
        throw;
    }
    cell.object_handle = handle;
}

void SphereWorldVegetation::initialize()
{
    std::vector<SphereWorldGrassCell> cells(grid_side * grid_side), previous(cells.size());
    std::vector<std::array<bool, 2>> occupancy(cells.size());
    SphereWorldVegetationPatterns nextPatterns;
    nextPatterns.initializeGrass();
    auto nextAnimation = std::make_unique<SphereWorldDynamicVegetation>(cells);
    animation.reset();
    cells_ = std::move(cells);
    previous_ = std::move(previous);
    occupancy_ = std::move(occupancy);
    patterns = std::move(nextPatterns);
    animation = std::move(nextAnimation);
    last_cell_x_ = last_cell_z_ = 100000;
}

void SphereWorldVegetation::destroyOwnedModel(std::uint32_t &handle)
{
    if (!handle)
        return;
    g_sfera_world_objects.destroy(handle);
    handle = 0;
}

bool SphereWorldVegetation::alternatePatterns()
{
    const auto *reference = g_sfera_world_objects.object(1);
    return TerrainAssets::high_resolution_assets && reference->position.y > 300 && reference->position.y < 800;
}

void SphereVegetationHelpers::vegetationError(const std::string &message)
{
    WorldDiagnostics::fail(message);
}
