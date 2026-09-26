#include <windows.h>
#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <format>
#include <fstream>
#include <functional>
#include <ios>
#include <iterator>
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

#include "audio/GameAudio.h"
#include "audio/SoundEffects.h"
#include "binary/Binary.h"
#include "diagnostics/Diagnostics.h"
#include "effects/ActiveEffect.h"
#include "effects/Effect.h"
#include "effects/EffectManager.h"
#include "effects/EffectRendering.h"
#include "effects/NatureManager.h"
#include "effects/ParticleEffects.h"
#include "effects/ScriptedEffects.h"
#include "environment/Environment.h"
#include "graphics/d3d9/Device.h"
#include "lighting/LightRuntime.h"
#include "math/Matrix.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "render/SceneRenderer.h"
#include "resources/FileResources.h"
#include "resources/TextureRepository.h"
#include "runtime/Clock.h"
#include "script/MbcRuntime.h"
#include "text/Text.h"
#include "ui/GameInterfaceManager.h"
#include "ui/ScriptInterface.h"
#include "world/ServerGeometry.h"
#include "world/WorldObjects.h"

void SferaBloodEffectListener::onEffectChanged(std::uint32_t, IEffect &effect, SferaActiveEffect &)
{
    auto &runtime = *this;
    if (runtime.active_count >= 30u)
        return;
    auto *scripted = effect.asScriptedEffect();
    if (scripted == nullptr || scripted->particle_systems.empty())
        return;
    auto &particles = *scripted->particle_systems[0];
    if (particles.render_slots.empty())
        return;
    const std::uint32_t requested = std::rand() % 3u + 4u;
    std::array<SferaVec3F, 6> origins{};
    std::uint32_t selected = 0u;
    float radius = 0.0f;
    for (std::size_t index = 0u; index < particles.render_slots.size() && selected < requested; ++index)
    {
        const auto &slot = particles.render_slots[index];
        if (slot.state.remaining_lifetime <= 0.0f)
            continue;
        auto &origin = origins[selected++];
        origin = {slot.state.render_position.x, effect.position.y - 0.5f, slot.state.render_position.z};
        const float dx = origin.x - effect.position.x, dy = origin.y - effect.position.y, dz = origin.z - effect.position.z;
        radius = std::max(radius, std::sqrt(dx * dx + dy * dy + dz * dz));
    }
    if (selected != requested)
        return;
    createSpots(effect.position, radius + 0.2f, {origins.data(), selected});
}

void SferaEffectManager::appendDefinition(std::shared_ptr<IEffect> effect)
{
    if (effect != nullptr)
        definitions.push_back(std::move(effect));
}

std::shared_ptr<IEffect> SferaEffectManager::findDefinition(uint32_t effect_id) const
{
    for (const auto &effect : definitions)
    {
        if (effect->effect_id == effect_id)
            return effect;
    }
    return nullptr;
}

std::shared_ptr<IEffect> SferaEffectManager::findDefinition(std::string_view script_name) const
{
    for (const auto &effect : definitions)
    {
        if (!effect->script_name.empty() && SferaText::asciiEqual(script_name, effect->script_name))
            return effect;
    }
    return nullptr;
}

std::uint32_t SferaEffectManager::findDefinitionId(std::string_view script_name) const
{
    const auto effect = findDefinition(script_name);
    return effect != nullptr ? effect->effect_id : UINT32_MAX;
}

void SferaEffectManager::initialize_particle_random_table(SferaEffectManager &manager)
{
    const auto seed = SferaNumeric::lowWord(std::chrono::steady_clock::now().time_since_epoch().count());
    std::srand(seed);
    for (auto &value : manager.particle_random_table)
        value = SferaNumeric::lowHalf(SferaNumeric::word(std::rand()));
    std::srand(SferaNumeric::lowWord(std::chrono::steady_clock::now().time_since_epoch().count()));
}

template <class T, class Initializer> void SferaEffectManager::append_fixed_effect(SferaEffectManager &manager, Initializer initialize)
{
    auto effect = std::make_shared<T>();
    initialize(*effect);
    manager.appendDefinition(std::move(effect));
}

void SferaEffectManager::initializeBloodEffect()
{
    if (blood != nullptr)
        return;
    auto runtime = std::make_unique<SferaBloodEffectListener>();
    runtime->change_tick = 64u;
    runtime->texture_id = g_sfera_textures.find("fx_bspot");
    if (registerListener(kBloodEffectId, *runtime))
        blood = std::move(runtime);
}
void SferaEffectManager::shutdownBloodEffect()
{
    if (blood == nullptr)
        return;
    unregisterListener(*blood);
    blood.reset();
}

auto SferaEffectManager::enumerateDefinitionFiles(std::error_code &error, const std::filesystem::path &directory, std::string_view extension, auto &&callback)
{
    if (!std::filesystem::exists(directory, error))
        return;
    for (const auto &entry : std::filesystem::directory_iterator(directory, error))
    {
        if (error || !entry.is_regular_file(error))
            continue;
        if (SferaText::asciiEqual(entry.path().extension().string(), extension))
            callback(entry.path());
    }
}

auto SferaEffectManager::loadDefinitionGroup(std::error_code &error, std::uint32_t &processed_count, std::uint32_t total_count, const std::filesystem::path &directory)
{
    enumerateDefinitionFiles(error, directory, ".sef", std::bind(&SferaEffectManager::loadDefinitionFile, this, std::ref(processed_count), total_count, std::placeholders::_1));
}

void SferaEffectManager::loadDefinitions()
{
    std::error_code error;

    enumerateDefinitionFiles(error, "Effects", ".ssm", std::bind(&SferaEffectManager::registerDefinitionMesh, this, std::placeholders::_1));
    std::uint32_t total_count = 0u;
    enumerateDefinitionFiles(error, "Effects", ".sef", std::bind(&SferaEffectManager::countDefinitionFile, std::ref(total_count), std::placeholders::_1));
    enumerateDefinitionFiles(error, "Players", ".sef", std::bind(&SferaEffectManager::countDefinitionFile, std::ref(total_count), std::placeholders::_1));
    const auto initial_count = definitions.size();
    std::uint32_t processed_count = 0u;

    loadDefinitionGroup(error, processed_count, total_count, "Effects");
    loadDefinitionGroup(error, processed_count, total_count, "Players");
    const auto loaded_count = definitions.size() - initial_count;
    const auto status = "Effects: loaded " + std::to_string(loaded_count) + " of " + std::to_string(total_count) + " SEF files from " + std::filesystem::current_path(error).string() + "\n";
    ::OutputDebugStringA(status.c_str());
    g_sfera_log_runtime.write(status);
    if (total_count == 0)
        reportError("No SEF files found in Effects or Players.");
}

void SferaEffectManager::destroyDefinitions()
{
    definitions.clear();
    mesh_resources.clear();
}

bool SferaEffectManager::initialize()
{
    SferaGameEffectHost::bind(*this);
    if (initialized)
        return true;
    if (shutting_down)
        return false;
    const bool traceEnabled = diagnostics.enabled;
    diagnostics = {};
    diagnostics.enabled = traceEnabled;
    try
    {
        effect_listeners.reserve(16);
        initialize_particle_random_table(*this);
        loadDefinitions();
        render_order.reserve(kMaximumRenderSlots);
        initializeBloodEffect();
        auto next_nature = std::make_unique<SferaNatureManager>();
        if (!next_nature->initialize())
        {
            shutdown();
            return false;
        }
        nature = std::move(next_nature);
        append_fixed_effect<CLightEffect>(*this, &SferaEffectManager::initializeLightDefinition);
        append_fixed_effect<CSpiralEffect>(*this, &SferaEffectManager::initializeSpiralDefinition);
        append_fixed_effect<CMolEffect>(*this, &SferaEffectManager::initializeMolDefinition);
        append_fixed_effect<CBladeEffect>(*this, &SferaEffectManager::initializeBladeDefinition);
        append_fixed_effect<CRainEffect>(*this, &SferaEffectManager::initializeRainDefinition);
        constexpr std::array lake_ids{kLakeEffectIdNear, kLakeEffectIdMiddle, kLakeEffectIdFar};
        for (std::size_t index = 0; index < lake_ids.size(); ++index)
        {
            append_fixed_effect<CGazerLakeEffect>(*this, std::bind(&SferaEffectManager::initializeLakeDefinition, lake_ids[index], index, std::placeholders::_1));
        }
        render_slot_count = 0u;
        initialized = true;
        return true;
    }
    catch (...)
    {
        shutdown();
        throw;
    }
}

void SferaEffectManager::loadDefinitionFile(std::uint32_t &processed_count, std::uint32_t total_count, const std::filesystem::path &path)
{
    auto effect = std::make_shared<CScriptedEffect>();
    effect->initializeScriptedState();
    try
    {
        if (effect->loadScript(path.string()))
            appendDefinition(std::move(effect));
    }
    catch (const std::logic_error &error)
    {
        reportError(path.string() + ": " + error.what());
    }
    ++processed_count;
    const std::uint32_t progress = total_count == 0u ? 30u : SferaNumeric::lowWord(std::uint64_t{processed_count} * 30u / total_count);
    reportLoadProgress(progress);
}

void SferaEffectManager::registerDefinitionMesh(const std::filesystem::path &path)
{
    const std::string value = path.string();
    registerEffectMeshFile(value);
}


void SferaEffectManager::initializeLightDefinition(CLightEffect &effect)
{
    effect.initializePreset();
    effect.assignScriptName("light_source.eff");
}

void SferaEffectManager::initializeSpiralDefinition(CSpiralEffect &effect)
{
    effect.initializePreset();
    effect.assignScriptName("spiral.effect0");
}

void SferaEffectManager::initializeMolDefinition(CMolEffect &effect)
{
    effect.initializePreset();
    effect.assignScriptName("molniya.effect110");
}

void SferaEffectManager::initializeBladeDefinition(CBladeEffect &effect)
{
    effect.initializePreset();
    effect.assignScriptName("blade");
}

void SferaEffectManager::initializeRainDefinition(CRainEffect &effect)
{
    effect.initializePreset();
    effect.assignScriptName("rain");
}

void SferaEffectManager::initializeLakeDefinition(std::uint32_t effect_id, std::size_t index, CGazerLakeEffect &effect)
{
    effect.initializePreset(effect_id, 5.0f * (index + 1), kFixedLakeFlags);
    effect.assignScriptName("gazer.lake");
}

constexpr std::array<std::string_view, 9> kEffectFailureNames{"stopping",      "active_limit",         "sound_unavailable", "missing_definition", "factory",
                                                              "filtered_type", "source_or_attachment", "listener",          "allocation"};

static_assert(kEffectFailureNames.size() == SferaNumeric::enumBits(SferaEffectManagerCreateFailure::Count));

void SferaEffectManager::reportError(std::string_view message) const
{
    if (!message.empty())
        std::fwrite(message.data(), 1u, message.size(), stderr);
    std::fputc('\n', stderr);
    ::OutputDebugStringA(std::string(message).c_str());
    ::OutputDebugStringA("\n");
    // Effect loading can continue after an error; preserve the reason in the existing client log.
    g_sfera_log_runtime.write("Effects: ");
    g_sfera_log_runtime.write(message);
    g_sfera_log_runtime.write("\n");
}
void SferaEffectManager::traceFailure(SferaEffectManagerCreateFailure failure, std::uint32_t effect, std::uint32_t source, std::optional<std::string_view> name) noexcept
{
    if (!diagnostics.enabled)
        return;
    const auto index = SferaNumeric::enumBits(failure);
    if (index >= diagnostics.failures.size())
        return;
    ++diagnostics.failures[index];
    if (diagnostics.details_written >= 24u)
        return;
    ++diagnostics.details_written;
    try
    {
        auto message = std::format("EffectDiag reject={} id={} source={} name={:.128} filter={} definitions={} active={}\n", kEffectFailureNames[index], effect, source, name.value_or("-"),
                                   effects_enabled, definitions.size(), active_effects.size());
        g_sfera_log_runtime.write(message);
    }
    catch (...)
    {
        // A diagnostic failure must not change the effect creation result.
    }
}

void SferaEffectManager::traceEffect(std::string_view event, const SferaActiveEffect &item) noexcept
{
    if (!diagnostics.enabled || !item.effect)
        return;
    try
    {
        const auto &effect = *item.effect;
        const auto position = item.position_source == 0 ? g_sfera_world_objects.objectPosition(item.source_handle) : item.position;
        auto message = std::format("EffectDiag {} id={} source={} name={:.96} age={} lifetime={} cycle={} flags={} blocked={} deactivated={} "
                                   "distance={:.3f} position={:.3f},{:.3f},{:.3f}\n",
                                   event, item.listener_key, item.source_handle, effect.script_name, item.age_ticks, effect.lifetime_ticks, effect.cycle_length, item.state_flags,
                                   effect.activation_blocked, effect.deactivated, item.viewer_distance, position.x, position.y, position.z);
        g_sfera_log_runtime.write(message);
    }
    catch (...)
    {
        // Recording a snapshot cannot affect the lifetime of the observed item.
    }
}

void SferaEffectManager::writeDiagnostics() noexcept
{
    if (!diagnostics.enabled || !initialized)
        return;
    const auto now = WorldClock::nowTicks();
    if (diagnostics.samples != 0 && now - diagnostics.last_sample < 50000u)
        return;
    diagnostics.last_sample = now;
    ++diagnostics.samples;
    try
    {
        std::size_t particleDefinitions = 0, lightDefinitions = 0;
        for (const auto &definition : definitions)
        {
            const auto *scripted = definition != nullptr ? definition->asScriptedEffect() : nullptr;
            if (scripted && scripted->definition)
            {
                if (!scripted->definition->particles.empty())
                    ++particleDefinitions;
                if (!scripted->definition->lights.empty())
                    ++lightDefinitions;
            }
        }
        const auto liveLights = std::count_if(g_sfera_light_runtime.handles.begin(), g_sfera_light_runtime.handles.end(), &SferaEffectManager::lightIsLive);
        const auto &fog = SphereRenderSceneRenderer::environment.fogParameters;
        auto message = std::format("EffectDiag sample={} ticks={} defs={} particle_defs={} light_defs={} vm={} requests={} created={} "
                                   "active={} updates={} far={} frustum={} activation={} daytime={} budget={} expired={} render={} slots={} "
                                   "submitted_quads={} alpha_vertices={} lights={} visible_lights={} light_enables={} fog={:.3f},{:.3f} "
                                   "filter={}\n",
                                   diagnostics.samples, now, definitions.size(), particleDefinitions, lightDefinitions, diagnostics.vm_requests, diagnostics.create_requests, diagnostics.created,
                                   active_effects.size(), diagnostics.updates, diagnostics.distance_culled, diagnostics.frustum_culled, diagnostics.activation_rejected, diagnostics.daytime_rejected,
                                   diagnostics.budget_rejected, diagnostics.expired, diagnostics.render_calls, render_slot_count, diagnostics.submitted_quads, diagnostics.alpha_vertices, liveLights,
                                   g_sfera_light_runtime.visible_handles.size(), diagnostics.light_activations, fog.y, fog.z, effects_enabled);
        g_sfera_log_runtime.write(message);
        for (std::size_t index = 0; index < diagnostics.failures.size(); ++index)
        {
            if (diagnostics.failures[index] == 0)
                continue;
            message = std::format("EffectDiag failures {}={}\n", kEffectFailureNames[index], diagnostics.failures[index]);
            g_sfera_log_runtime.write(message);
        }
        std::size_t printed = 0;
        for (const auto &item : active_effects)
        {
            if (!item->effect)
                continue;
            traceEffect("live", *item);
            if (++printed == 3)
                break;
        }
    }
    catch (...)
    {
        // Diagnostics never control rendering, resource lifetime or VM execution.
    }
}

std::unique_ptr<IEffect> CSpiralEffect::createEffectResources()
{
    auto effect = std::make_unique<CSpiralEffect>();
    effect->initializePreset();
    effect->assignScriptName("spiral.effect0");
    effect->resource_id = g_sfera_textures.find("fx_flare");
    return effect;
}

std::unique_ptr<IEffect> CMolEffect::createEffectResources()
{
    auto effect = std::make_unique<CMolEffect>();
    effect->initializePreset();
    effect->assignScriptName("molniya.effect110");
    effect->resource_id = g_sfera_textures.find("fx_light");
    if (effect->resource_id == -1)
        g_sfera_effect_manager.reportError("CMolEffect::Texture not found 'fx_light'");
    effect->sound_effect = g_sfera_sound_runtime.createEffect(110u);
    return effect;
}

std::unique_ptr<IEffect> CBladeEffect::createEffectResources()
{
    auto effect = std::make_unique<CBladeEffect>();
    effect->initializePreset();
    effect->assignScriptName("blade");
    effect->resource_id = g_sfera_textures.find("fx_blade");
    if (effect->resource_id == -1)
        g_sfera_effect_manager.reportError("CBladeEffect::Texture not found 'fx_blade'");
    return effect;
}

std::unique_ptr<IEffect> CGazerLakeEffect::createEffectResources()
{
    auto effect = std::make_unique<CGazerLakeEffect>();
    effect->initializePreset(effect_id, radius, emission_period);
    effect->assignScriptName("gazer.lake");
    auto source = g_sfera_effect_manager.findDefinition(729u);
    if (source != nullptr)
        for (auto &slot : effect->slots)
        {
            slot.effect = source->createEffectResources();
            slot.age = -1.0f;
        }
    return effect;
}

std::unique_ptr<IEffect> CRainEffect::createEffectResources()
{
    auto effect = std::make_unique<CRainEffect>();
    effect->initializePreset();
    effect->assignScriptName("rain");
    effect->resource_id = g_sfera_textures.find("fx_rain");
    if (effect->resource_id == -1)
        g_sfera_effect_manager.reportError("CRainEffect::Texture not found 'fx_rain'");
    effect->particles.resize(3000u);
    for (auto &particle : effect->particles)
        particle.remaining_life = -1.0f;
    return effect;
}

void SferaEffectManager::shutdown()
{
    if (shutting_down)
        return;
    shutting_down = true;
    initialized = false;
    shutdownBloodEffect();
    clearListeners();
    if (nature != nullptr)
        nature->shutdown();
    // Final shutdown cannot be vetoed. Each active handle is invalidated before its storage is released.
    while (!active_effects.empty())
    {
        const auto item = active_effects.front();
        retireEffect(*item);
    }
    nature.reset();
    destroyDefinitions();
    render_order.clear();
    render_slot_count = 0;
    shutting_down = false;
}

SferaActiveEffect *SferaEffectManager::createActiveEffect(std::uint32_t effect_id, std::uint32_t source_handle)
{
    if (diagnostics.enabled)
        ++diagnostics.create_requests;
    if (shutting_down)
    {
        traceFailure(SferaEffectManagerCreateFailure::Stopping, effect_id, source_handle);
        return nullptr;
    }
    if (active_effects.size() >= kMaximumActiveEffects)
    {
        traceFailure(SferaEffectManagerCreateFailure::Capacity, effect_id, source_handle);
        return nullptr;
    }
    if (source_handle == 0u)
        reportError("EffectManager::createActiveEffect: zero source handle");
    std::shared_ptr<SferaActiveEffect> item;
    try
    {
        item = std::make_shared<SferaActiveEffect>();
        if (effect_id >= kSoundEffectIdBase)
        {
            if (!g_sfera_sound_runtime.interfaceAvailable())
            {
                traceFailure(SferaEffectManagerCreateFailure::SoundUnavailable, effect_id, source_handle);
                return nullptr;
            }
            item->resource = g_sfera_sound_runtime.createEffect(effect_id);
            if (item->resource == nullptr)
            {
                traceFailure(SferaEffectManagerCreateFailure::Factory, effect_id, source_handle);
                return nullptr;
            }
        }
        else
        {
            item->definition = findDefinition(effect_id);
            if (item->definition == nullptr)
            {
                traceFailure(SferaEffectManagerCreateFailure::MissingDefinition, effect_id, source_handle);
                return nullptr;
            }
            item->effect = item->definition->createEffectResources();
            if (item->effect == nullptr)
            {
                traceFailure(SferaEffectManagerCreateFailure::Factory, effect_id, source_handle);
                return nullptr;
            }
            if (effects_enabled && item->effect->isEffectComplete())
            {
                traceFailure(SferaEffectManagerCreateFailure::FilteredType, effect_id, source_handle);
                return nullptr;
            }
        }
        item->state_flags = kUninitializedEffectState;
        item->source_handle = source_handle;
        item->listener_key = effect_id;
        item->viewer_distance = viewerDistance(source_handle);
        item->position = g_sfera_world_objects.objectPosition(source_handle);
        if (item->effect != nullptr)
            item->effect->position = item->position;
        if (!g_sfera_world_objects.attachEffect(source_handle, *item))
        {
            traceFailure(SferaEffectManagerCreateFailure::InvalidSource, effect_id, source_handle);
            return nullptr;
        }
        item->active = true;
        active_effects.push_back(item);
        if (item->effect != nullptr)
        {
            if (auto *listener = findListener(effect_id))
            {
                item->effect->listener = listener;
                if (!listener->onEffectAttached(*item->effect, *item, item->viewer_distance))
                {
                    traceFailure(SferaEffectManagerCreateFailure::Listener, effect_id, source_handle);
                    removeActiveEffect(item.get());
                    if (item->active)
                        retireEffect(*item);
                    return nullptr;
                }
            }
        }
        if (item->active && diagnostics.enabled)
        {
            ++diagnostics.created;
            if (diagnostics.details_written < 24u)
            {
                ++diagnostics.details_written;
                traceEffect("created", *item);
            }
        }
        return item->active ? item.get() : nullptr;
    }
    catch (const std::bad_alloc &)
    {
        traceFailure(SferaEffectManagerCreateFailure::Allocation, effect_id, source_handle);
        if (item != nullptr && item->active)
            retireEffect(*item);
        return nullptr;
    }
    catch (...)
    {
        if (item != nullptr && item->active)
            retireEffect(*item);
        throw;
    }
}

SferaActiveEffect *SferaEffectManager::createActiveEffect(std::string_view script_name, std::uint32_t source_handle)
{
    const auto definition = findDefinition(script_name);
    if (definition != nullptr && definition->effect_id > 0u)
        return createActiveEffect(definition->effect_id, source_handle);
    if (diagnostics.enabled)
        ++diagnostics.create_requests;
    traceFailure(SferaEffectManagerCreateFailure::MissingDefinition, definition ? definition->effect_id : UINT32_MAX, source_handle, script_name);
    return nullptr;
}


bool SferaEffectManager::removeActiveEffect(SferaActiveEffect *handle)
{
    auto found = active_effects.begin();
    while (found != active_effects.end() && found->get() != handle)
        ++found;
    if (found == active_effects.end())
        return false;
    const auto item = *found;
    if (item->removing)
        return false;
    item->removing = true;
    try
    {
        if (item->effect != nullptr)
        {
            auto *listener = item->effect->listener != nullptr ? item->effect->listener : findListener(item->listener_key);
            if (listener != nullptr && !listener->onEffectDetached(*item->effect, *item))
            {
                item->removing = false;
                return !item->active;
            }
        }
    }
    catch (...)
    {
        item->removing = false;
        throw;
    }
    retireEffect(*item);
    return true;
}

void SferaEffectManager::retireEffect(SferaActiveEffect &item)
{
    if (!item.active)
        return;
    item.active = false;
    g_sfera_mbc_runtime.forgetNativeResource(&item);
    if (g_sfera_effect_manager.pending_effect == &item)
        g_sfera_effect_manager.pending_effect = nullptr;
    if (nature != nullptr)
        nature->forgetEffect(item);
    if (item.position_source == 0u)
        g_sfera_world_objects.detachEffect(item.source_handle, item);
    if (item.effect != nullptr)
        item.effect->listener = nullptr;
    if (item.resource != nullptr)
        item.resource->stop();
    item.age_ticks = item.listener_key = kInvalidHandle;
    for (auto current = active_effects.begin(); current != active_effects.end();)
    {
        if (current->get() == &item)
            current = active_effects.erase(current);
        else
            ++current;
    }
}

SferaActiveEffect::~SferaActiveEffect()
{
    if (definition != nullptr && effect != nullptr)
        definition->recycleEffect(std::move(effect));
}

bool SferaEffectManager::setEffectParameters(std::uint32_t source_handle, std::span<const SferaEffectParameter> parameters)
{
    auto *item = g_sfera_world_objects.firstEffect(source_handle);
    if (item == nullptr || item->effect == nullptr)
        return false;
    item->effect->setParameters(parameters);
    return true;
}

IEffectListener *SferaEffectManager::findListener(uint32_t effect_id) const
{
    for (const auto &entry : effect_listeners)
    {
        if (entry.effect_id == effect_id)
            return entry.listener;
    }
    return nullptr;
}

bool SferaEffectManager::registerListener(std::uint32_t effect_id, IEffectListener &listener)
{
    if (auto *current = findListener(effect_id))
    {
        if (current == &listener)
            return true;
        reportError("EM_RegisterEffectListener::Multiple listeners not implemented.");
        return false;
    }
    if (effect_listeners.size() >= 16)
        return false;
    effect_listeners.push_back({effect_id, &listener});
    return true;
}

void SferaEffectManager::unregisterListener(IEffectListener &listener)
{
    for (auto entry = effect_listeners.begin(); entry != effect_listeners.end();)
    {
        if (entry->listener == &listener)
            entry = effect_listeners.erase(entry);
        else
            ++entry;
    }
    for (const auto &item : active_effects)
        if (item->effect != nullptr && item->effect->listener == &listener)
            item->effect->listener = nullptr;
}

void SferaEffectManager::clearListeners()
{
    for (const auto &item : active_effects)
        if (item->effect != nullptr)
            item->effect->listener = nullptr;
    effect_listeners.clear();
}

std::uint32_t SferaEffectManager::listenerKey(const SferaActiveEffect *handle) const
{
    for (const auto &item : active_effects)
    {
        if (item.get() == handle)
            return item->listener_key;
    }
    return 0u;
}

void SferaEffectManager::renderParticles()
{
    ++generation;
    SferaEffectRenderState::renderParticles(diagnostics);
}

void SferaEffectManager::drawFlare(int x, int y, int size, bool enabled)
{
    if (flare_enabled != enabled)
    {
        flare_enabled = enabled;
        flare_transition = enabled ? SferaEffectManagerFlareTransition::FadeIn : SferaEffectManagerFlareTransition::FadeOut;
    }
    if (!enabled && flare_alpha == 0u)
        return;
    const auto texture = g_sfera_textures.find("fx_flare");
    SferaEffectRenderState::drawFlare(texture, x, y, size, flare_alpha);
}

auto SferaEffectManager::readMeshCoordinate(SferaBinaryReader &input)
{
    const float value = input.read<float>();
    if (!std::isfinite(value))
        throw std::runtime_error("Nonfinite effect mesh coordinate");
    return value;
}

auto SferaEffectManager::readMeshIndices(SferaEffectMeshResource &resource, SferaBinaryReader &payload, auto member, std::size_t limit)
{
    for (auto &face : resource.faces)
        for (auto &index : face.*member)
        {
            const auto value = payload.read<std::uint32_t>();
            if (value >= limit)
                throw std::runtime_error("Invalid effect mesh index");
            index = value;
        }
}

void SferaEffectManager::registerEffectMeshFile(const std::string &filename)
{
    std::ifstream stream;
    for (const auto &path : g_sfera_files.candidatePaths(filename))
    {
        stream.open(path, std::ios::binary);
        if (stream.is_open())
            break;
        stream.clear();
    }
    if (!stream.is_open())
        return;
    stream.seekg(0, std::ios::end);
    const std::streamoff file_size = stream.tellg();
    std::vector<std::uint8_t> bytes;
    if (file_size < 0 || std::cmp_greater(file_size, std::numeric_limits<std::streamsize>::max()) || std::cmp_greater(file_size, bytes.max_size()))
        return;
    bytes.resize(file_size);
    stream.seekg(0, std::ios::beg);
    if (!bytes.empty() && !SferaBinary::read(stream, bytes))
        return;
    std::vector<std::shared_ptr<const SferaEffectMeshResource>> loaded;
    try
    {
        SferaBinaryReader reader(bytes);
        const auto magic = reader.take(4);
        if (!std::equal(magic.begin(), magic.end(), "SSM1") || reader.read<std::uint32_t>() != 1)
            return;
        const auto mesh_count = reader.read<std::uint32_t>();
        reader.read<std::uint32_t>(); // Reserved file word.
        if (mesh_count > (bytes.size() - 16) / 52)
            return;
        loaded.reserve(mesh_count);

        for (std::size_t mesh_index = 0; mesh_index < mesh_count; ++mesh_index)
        {
            auto mesh = std::make_shared<SferaEffectMeshResource>();
            const auto name = reader.take(32).first(31);
            mesh->name.assign(name.begin(), std::find(name.begin(), name.end(), 0));
            const auto vertex_count = reader.read<std::uint32_t>();
            const auto skipped_vertex_count = reader.read<std::uint32_t>();
            const auto uv_count = reader.read<std::uint32_t>();
            const auto face_count = reader.read<std::uint32_t>();
            reader.read<std::uint32_t>(); // Historical unused count, not an extra section.
            const auto payload_size = std::uint64_t{vertex_count} * 16 + std::uint64_t{skipped_vertex_count} * 12 + std::uint64_t{uv_count} * 8 + std::uint64_t{face_count} * 32;
            if (payload_size > bytes.size())
                return;
            // Establish the complete byte range before allocating any decoded arrays.
            SferaBinaryReader payload(reader.take(payload_size));
            mesh->vertices.resize(vertex_count);
            mesh->colors.resize(vertex_count);
            mesh->uv.resize(uv_count);
            mesh->faces.resize(face_count);
            for (auto &vertex : mesh->vertices)
                vertex = {readMeshCoordinate(payload), readMeshCoordinate(payload), readMeshCoordinate(payload)};
            payload.take(skipped_vertex_count * 12);

            readMeshIndices(*mesh, payload, &SferaEffectMeshResourceFace::vertices, mesh->vertices.size());
            for (auto &color : mesh->colors)
            {
                const auto channels = payload.take(4);
                std::copy(channels.begin(), channels.end(), color.channels.begin());
            }
            for (auto &uv : mesh->uv)
                for (auto &coordinate : uv)
                    coordinate = readMeshCoordinate(payload);
            readMeshIndices(*mesh, payload, &SferaEffectMeshResourceFace::uv, mesh->uv.size());
            loaded.push_back(std::move(mesh));
        }
    }
    catch (const std::runtime_error &)
    {
        return;
    }
    if (loaded.size() > mesh_resources.max_size() - mesh_resources.size())
        throw std::length_error("Too many effect meshes");
    mesh_resources.reserve(mesh_resources.size() + loaded.size());
    mesh_resources.insert(mesh_resources.end(), std::make_move_iterator(loaded.begin()), std::make_move_iterator(loaded.end()));
}

void SferaEffectManager::reportLoadProgress(std::uint32_t progress)
{
    GameInterface::loading_completed += progress;
    const int work = std::max(GameInterface::loading_total - 80, 1);
    int percent = GameInterface::loading_completed * 100 / work;
    percent = std::min(percent, 100);
    if (percent == g_sfera_graphics_runtime.rebuild_percent)
        return;
    g_sfera_graphics_runtime.rebuild_percent = percent;
    auto *device_runtime = g_sfera_graphics_runtime.d3d_runtime.get();
    if (!device_runtime)
        return;
    SceneScope scene(*device_runtime);
    if (!scene)
        return;
    g_sfera_interface.setLoadingProgress(percent);
    scene.finish();
    device_runtime->waitForGpu();
    device_runtime->present();
}

void CSpiralEffect::initializePreset()
{
    initializeBaseState(IEffectKind::Preset);
    effect_id = 0u;
    cycle_length = 400u;
    lifetime_ticks = 400u;
    bounds_min[0] = -0.4f;
    bounds_min[1] = -1.0f;
    bounds_min[2] = -0.4f;
    bounds_max[0] = 0.4f;
    bounds_max[1] = 0.1f;
    bounds_max[2] = 0.4f;
    resource_id = -1;
    spatial_gate_enabled = true;
    render_slot_budget = 80u;
}

void CMolEffect::initializePreset()
{
    initializeBaseState(IEffectKind::Preset);
    effect_id = 110u;
    cycle_length = 1u;
    lifetime_ticks = std::numeric_limits<std::uint32_t>::max();
    render_slot_budget = 4u;
    anchor = {};
    texture_phase = 0.0f;
    anchor_initialized = false;
    resource_id = -1;
    sound_effect = nullptr;
    sound_started = false;
}

void CBladeEffect::initializePreset()
{
    initializeBaseState(IEffectKind::Preset);
    effect_id = 340u;
    cycle_length = 64u;
    lifetime_ticks = 32u;
    render_slot_budget = 4u;
    anchor = {};
    progress = 0.0f;
    anchor_initialized = false;
    resource_id = -1;
}

void CGazerLakeEffect::initializePreset(std::uint32_t id, float effect_radius, std::size_t count)
{
    initializeBaseState(IEffectKind::Preset);
    emission_tick = 0u;
    emission_period = count;
    radius = effect_radius;
    effect_id = id;
    cycle_length = 192u;
    lifetime_ticks = std::numeric_limits<std::uint32_t>::max();
    spatial_gate_enabled = true;
    const float extent = effect_radius + 0.1f;
    bounds_min[0] = -extent;
    bounds_min[1] = -0.4f;
    bounds_min[2] = -extent;
    bounds_max[0] = extent;
    bounds_max[1] = 0.1f;
    bounds_max[2] = extent;
    for (auto &slot : slots)
    {
        slot.effect = nullptr;
        slot.age = -1.0f;
        slot.offset = {};
    }
}

void CRainEffect::initializePreset()
{
    initializeBaseState(IEffectKind::Preset);
    resource_id = -1;
    particles.clear();
    spawn_radius = 4.0f;
    spawn_radius_bias = 0.4f;
    spawn_rate = 120.0f;
    spawn_fraction = 0.0f;
    cycle_length = 64u;
    lifetime_ticks = std::numeric_limits<std::uint32_t>::max();
    effect_id = 400u;
    effect_kind = IEffectKind::Rain;
    render_slot_budget = 3000u;
}

void CLightEffect::initializePreset()
{
    initializeBaseState(IEffectKind::Preset);
    effect_id = 200u;
    cycle_length = 1u;
    lifetime_ticks = std::numeric_limits<std::uint32_t>::max();
    color[0] = 255.0f;
    color[1] = 255.0f;
    color[2] = 255.0f;
    color[3] = 255.0f;
    radius = 0.0f;
    registered = false;
    light_index = -1;
    brightness_jitter = 0.0f;
    brightness_frequency = 1u;
    brightness_tick = 0u;
}

float SferaEffectManager::viewerDistance(std::uint32_t source_handle) const
{
    return viewerDistance(g_sfera_world_objects.objectPosition(source_handle));
}

void SferaEffectManager::updateActiveEffect(SferaActiveEffect &item, std::uint16_t state_flags, float viewer_distance)
{
    if (!item.active || shutting_down)
        return;
    if (item.resource != nullptr && item.effect == nullptr)
    {
        if (!g_sfera_sound_runtime.interfaceAvailable())
        {
            removeActiveEffect(item);
            return;
        }
        const auto frame = item.position_source == 1u ? item.position : g_sfera_world_objects.objectPosition(item.source_handle);
        if (!item.sound_started)
        {
            item.resource->start(&frame, item.resource->startTime() < viewer_distance);
            item.sound_started = true;
        }
        else
        {
            item.resource->update(&frame, viewer_distance);
        }
        if (item.resource->isComplete())
            removeActiveEffect(item);
        return;
    }
    auto *effect = item.effect.get();
    if (effect == nullptr)
    {
        removeActiveEffect(item);
        return;
    }
    item.age_ticks += item.listener_key >= kBloodEffectId && item.listener_key <= kBloodEffectIdLast ? 1u : 2u;
    if (effect->lifetime_ticks != kInvalidHandle && item.age_ticks >= effect->lifetime_ticks)
    {
        if (diagnostics.enabled)
        {
            ++diagnostics.expired;
            if (diagnostics.details_written < 24u)
            {
                ++diagnostics.details_written;
                traceEffect("expired", item);
            }
        }
        removeActiveEffect(item);
        return;
    }
    if (effect->listener != nullptr && item.age_ticks == effect->listener->change_tick)
        effect->listener->onEffectChanged(item.age_ticks, *effect, item);
    if (!item.active || shutting_down)
        return;
    if (item.listener_key == kBloodEffectId && effect->listener != nullptr)
        effect->listener->onEffectChanged(item.age_ticks, *effect, item);
    if (!item.active || shutting_down)
        return;
    SferaEffectFrames frames;
    if (item.position_source == 1u)
    {
        for (auto &frame : frames.positions)
            frame = item.position;
        for (auto &frame : frames.transforms)
            frame = SferaMatrix4x4F::identity();
    }
    else
    {
        frames = g_sfera_world_objects.buildEffectFrames(item.source_handle);
    }
    if (g_sfera_sound_runtime.interfaceAvailable())
        effect->updateEffect({&frames.positions[0], viewer_distance});
    if (!item.active || shutting_down)
        return;
    const bool visible = state_flags == 0u;
    if (!effect->activation_blocked && !effect->activateEffect(visible))
    {
        if (diagnostics.enabled)
            ++diagnostics.activation_rejected;
        if (!effect->deactivated)
            effect->deactivateEffect(((state_flags >> 1u) & 1u) != 0u);
        effect->activation_blocked = true;
        return;
    }
    if (effect->range_min != -1.0f)
    {
        const float environment = g_sfera_graphics_runtime.environment_factor;
        const bool outside = effect->range_max < effect->range_min ? environment > effect->range_min || environment < effect->range_max
                                                                   : environment > effect->range_min && environment < effect->range_max;
        if (outside)
        {
            if (diagnostics.enabled)
                ++diagnostics.daytime_rejected;
            if (!effect->deactivated)
                effect->deactivateEffect(false);
            return;
        }
    }
    if (effect->cycle_length != 0u && item.age_ticks >= effect->cycle_length)
        item.age_ticks %= effect->cycle_length;
    if ((state_flags & 2u) != 0u)
    {
        if (effect->resources_released)
            effect->renderEffect();
        effect->queryEffectState({frames.positions, SferaNumeric::real32(item.age_ticks)});
        return;
    }
    if (effect->deactivated)
        effect->renderEffect();
    effect->initializeEffect({frames.positions, SferaNumeric::real32(item.age_ticks), visible, frames.transforms});
}

void SferaEffectManager::updateActiveEffects()
{
    if (updating || shutting_down)
        return;
    updating = true;
    if (diagnostics.enabled)
        ++diagnostics.updates;
    try
    {
        viewer_position = g_sfera_world_objects.referencePosition();
        if (flare_transition != SferaEffectManagerFlareTransition::Idle)
        {
            int alpha = flare_alpha + (flare_transition == SferaEffectManagerFlareTransition::FadeOut ? -kFlareAlphaStep : kFlareAlphaStep);
            if (alpha < 0)
            {
                alpha = 0;
                flare_transition = SferaEffectManagerFlareTransition::Idle;
            }
            else if (alpha > kMaximumAlpha)
            {
                alpha = kMaximumAlpha;
                flare_transition = SferaEffectManagerFlareTransition::Idle;
            }
            flare_alpha = alpha;
        }
        render_slot_count = 0u;
        bool refresh_visibility = false;
        if (++render_cycle == kVisibilityRefreshPeriod)
        {
            render_cycle = 0u;
            refresh_visibility = true;
        }
        const float visibility_distance = SphereRenderSceneRenderer::environment.fogParameters.z + 10.0f;
        // Callbacks can remove any item. Retain its storage until this update completes.
        const std::vector<std::shared_ptr<SferaActiveEffect>> snapshot(active_effects.begin(), active_effects.end());
        for (const auto &owner : snapshot)
        {
            auto &item = *owner;
            if (!item.active)
                continue;
            if (refresh_visibility || item.state_flags == kUninitializedEffectState)
            {
                item.state_flags = 0u;
                const auto position = item.position_source == 0u ? g_sfera_world_objects.objectPosition(item.source_handle) : item.position;
                item.viewer_distance = viewerDistance(position);
                if (visibility_distance < item.viewer_distance)
                    item.state_flags |= 1u;
                if (item.effect != nullptr && last_processed_generation != generation && (item.state_flags & 1u) == 0u && item.effect->spatial_gate_enabled)
                {
                    if (!SphereRenderSceneRenderer::effectVisible(*item.effect, position))
                        item.state_flags |= 2u;
                    else
                        item.state_flags &= 0xFFFDu;
                }
            }
            if (diagnostics.enabled)
            {
                if ((item.state_flags & 1u) != 0u)
                    ++diagnostics.distance_culled;
                if ((item.state_flags & 2u) != 0u)
                    ++diagnostics.frustum_culled;
            }
            bool call_update = true;
            if (item.effect != nullptr && item.effect->activation_blocked)
            {
                if (item.state_flags == 0u)
                    item.effect->activation_blocked = false;
                else if ((item.state_flags & 1u) != 0u)
                {
                    item.age_ticks += 2u;
                    if (item.effect->lifetime_ticks != kInvalidHandle && item.age_ticks >= item.effect->lifetime_ticks)
                    {
                        if (diagnostics.enabled)
                            ++diagnostics.expired;
                        removeActiveEffect(item);
                    }
                    call_update = false;
                }
            }
            if (call_update && item.active)
                updateActiveEffect(item, item.state_flags, item.viewer_distance);
        }
        g_sfera_server_wall.updateEffectRendering();
        if (blood != nullptr)
            blood->phase += 0.005f;
        sortRenderSlots();
        last_processed_generation = generation;
    }
    catch (...)
    {
        updating = false;
        throw;
    }
    updating = false;
}

SferaGameEffectHost::SferaGameEffectHost(SferaEffectManager &source) : manager(&source)
{
}
void SferaGameEffectHost::bind(SferaEffectManager &manager)
{
    static SferaGameEffectHost host(manager);
    host.manager = &manager;
    SferaEffectHost::bind(host);
}
SferaEffectRenderState &SferaGameEffectHost::renderState()
{
    return *manager;
}
void SferaGameEffectHost::rejectRenderBudget()
{
    if (manager->diagnostics.enabled)
        ++manager->diagnostics.budget_rejected;
}

bool NatureRainListener::onEffectAttached(IEffect &effect, SferaActiveEffect &, float)
{
    return SferaNatureAccess::manager() != nullptr && SferaNatureAccess::manager()->attachRainEffect(effect);
}

bool NatureRainListener::onEffectDetached(IEffect &, SferaActiveEffect &)
{
    if (auto *manager = SferaNatureAccess::manager())
        manager->detachRainEffect();
    return true;
}

void NatureRainListener::onEffectChanged(std::uint32_t, IEffect &, SferaActiveEffect &)
{
}

bool LightingListener::onEffectAttached(IEffect &effect, SferaActiveEffect &, float)
{
    return SferaNatureAccess::manager() != nullptr && SferaNatureAccess::manager()->attachLightingEffect(effect);
}

bool LightingListener::onEffectDetached(IEffect &, SferaActiveEffect &)
{
    if (auto *manager = SferaNatureAccess::manager())
        manager->detachLightingEffect();
    return true;
}

void LightingListener::onEffectChanged(std::uint32_t, IEffect &effect, SferaActiveEffect &item)
{
    if (auto *manager = SferaNatureAccess::manager())
        manager->onLightingEffectChanged(effect, item);
}

void SferaNatureManager::updateNatureWeather(float value, bool &enabled, void (SferaNatureManager::*start)(), void (SferaNatureManager::*stop)(), void (SferaNatureManager::*apply)(float))
{
    auto *nature = SferaNatureAccess::manager();
    if (value > 0.0010000000474974513f && SphereRenderSceneRenderer::interior_scene == 0u)
    {
        if (!enabled)
        {
            if (nature != nullptr)
                (nature->*start)();
            enabled = true;
        }
        if (nature != nullptr)
            (nature->*apply)(value);
    }
    else if (enabled)
    {
        if (nature != nullptr)
            (nature->*stop)();
        enabled = false;
    }
}

void SferaNatureManager::updateRain()
{
    SferaNatureManager::updateNatureWeather(g_sfera_weather_runtime.current.rain, g_sfera_effect_manager.rain_enabled, &SferaNatureManager::startRain, &SferaNatureManager::stopRain,
                                            &SferaNatureManager::setRainIntensity);
}

void SferaNatureManager::updateLightning()
{
    SferaNatureManager::updateNatureWeather(g_sfera_weather_runtime.current.lightning, g_sfera_effect_manager.lightning_enabled, &SferaNatureManager::startLighting, &SferaNatureManager::stopLighting,
                                            &SferaNatureManager::setLightingLevel);
}

SferaNatureManager *SferaNatureAccess::manager()
{
    return g_sfera_effect_manager.nature.get();
}

void SferaNatureManager::remove_nature_effect_handle(SferaActiveEffect *&handle)
{
    if (handle != nullptr)
        g_sfera_effect_manager.removeActiveEffect(handle);
}

bool SferaNatureManager::initialize()
{
    rain_listener.change_tick = lighting_listener.change_tick = kInvalidHandle;
    if (!g_sfera_effect_manager.registerListener(kRainEffectId, rain_listener))
        return false;
    try
    {
        if (g_sfera_effect_manager.registerListener(kLightingEffectId, lighting_listener))
            return true;
    }
    catch (...)
    {
        g_sfera_effect_manager.unregisterListener(rain_listener);
        throw;
    }
    g_sfera_effect_manager.unregisterListener(rain_listener);
    return false;
}

void SferaNatureManager::shutdown()
{
    stopRain();
    stopLighting();
    g_sfera_effect_manager.unregisterListener(rain_listener);
    g_sfera_effect_manager.unregisterListener(lighting_listener);
    rain_effect = nullptr;
    lighting_effect = nullptr;
}

void SferaNatureManager::forgetEffect(const SferaActiveEffect &item)
{
    if (rain_effect_handle == &item)
        rain_effect_handle = nullptr;
    if (lighting_effect_handle == &item)
        lighting_effect_handle = nullptr;
    for (auto &handle : ambient_rain_handles)
        if (handle == &item)
            handle = nullptr;
    if (rain_effect == item.effect.get())
        rain_effect = nullptr;
    if (lighting_effect == item.effect.get())
        lighting_effect = nullptr;
}

bool SferaNatureManager::attachRainEffect(IEffect &effect)
{
    if (rain_effect != nullptr)
        return false;
    auto *rain = effect.asRainEffect();
    if (rain == nullptr)
    {
        g_sfera_effect_manager.reportError("Unknown effect classID for rain.");
        return false;
    }
    if (effect.script_name != "rain")
        g_sfera_effect_manager.reportError("Unknown effect manager for 'rain' not found.");
    rain_effect = rain;
    rain_scale = 60.0f;
    rain->spawn_rate = rain_intensity * rain_scale;
    updateAmbientRainEffects();
    return true;
}

void SferaNatureManager::detachRainEffect()
{
    for (auto &handle : ambient_rain_handles)
        remove_nature_effect_handle(handle);
    rain_effect = nullptr;
}

bool SferaNatureManager::attachLightingEffect(IEffect &effect)
{
    if (lighting_effect != nullptr)
        return false;
    auto *scripted = effect.asScriptedEffect();
    if (scripted == nullptr)
    {
        g_sfera_effect_manager.reportError("Unknown effect classID for lighting.");
        return false;
    }
    lighting_effect = scripted;
    if (g_sfera_world_objects.controlled_object_handle != kInvalidHandle)
    {
        effect.cycle_length = SferaNumeric::truncatedWord((1.0f - lighting_level) * 640.0f + 320.0f);
        effect.lifetime_ticks = kInvalidHandle;
    }
    lighting_listener.change_tick = 1u;
    return true;
}


void SferaNatureManager::onLightingEffectChanged(IEffect &effect, SferaActiveEffect &item)
{
    if (effect.effect_kind != IEffectKind::Scripted)
        return;
    auto *scripted = effect.asScriptedEffect();
    if (scripted == nullptr || scripted->lights.empty() || scripted->particle_systems.empty())
        return;
    auto &particle = *scripted->particle_systems[0];
    if (particle.render_slots.empty())
        return;
    const SferaVec3F source = g_sfera_world_objects.objectPosition(item.source_handle);
    const SferaVec3F emitter = particle.render_slots[0].state.position;
    auto &light = scripted->lights[0];
    light.position = {emitter.x - source.x, emitter.y - source.y, emitter.z - source.z};
    const float distance = std::sqrt(light.position.x * light.position.x + light.position.y * light.position.y + light.position.z * light.position.z);
    g_sfera_effect_manager.createActiveEffect(distance < 15.0f ? kLightingSoundNearId : kLightingSoundFarId, item.source_handle);
}

void SferaNatureManager::startRain()
{
    if (rain_effect_handle == nullptr && g_sfera_world_objects.controlled_object_handle != kInvalidHandle)
        rain_effect_handle = g_sfera_effect_manager.createActiveEffect(kRainEffectId, g_sfera_world_objects.controlled_object_handle);
}
void SferaNatureManager::stopRain()
{
    remove_nature_effect_handle(rain_effect_handle);
    for (auto &handle : ambient_rain_handles)
        remove_nature_effect_handle(handle);
}
void SferaNatureManager::startLighting()
{
    if (lighting_effect_handle == nullptr && g_sfera_world_objects.controlled_object_handle != kInvalidHandle)
        lighting_effect_handle = g_sfera_effect_manager.createActiveEffect(kLightingEffectId, g_sfera_world_objects.controlled_object_handle);
}

void SferaNatureManager::setRainIntensity(float value)
{
    if (rain_effect == nullptr || g_sfera_world_objects.controlled_object_handle == kInvalidHandle)
        return;
    rain_intensity = value;
    rain_effect->spawn_rate = rain_intensity * rain_scale;
    updateAmbientRainEffects();
}
void SferaNatureManager::setLightingLevel(float value)
{
    if (lighting_effect == nullptr || g_sfera_world_objects.controlled_object_handle == kInvalidHandle)
        return;
    lighting_level = value;
    lighting_effect->cycle_length = SferaNumeric::truncatedWord((1.0f - lighting_level) * 640.0f + 320.0f);
    lighting_effect->lifetime_ticks = kInvalidHandle;
}

void SferaNatureManager::updateAmbientRainEffects()
{
    const auto source = g_sfera_world_objects.controlled_object_handle;
    if (source == kInvalidHandle)
        return;
    const std::size_t channels = rain_intensity == 0.0f ? 0 : rain_intensity <= 0.4f ? 1 : rain_intensity <= 0.8f ? 2 : 3;
    for (std::size_t index = 0; index < ambient_rain_handles.size(); ++index)
    {
        auto &handle = ambient_rain_handles[index];
        if (index >= channels)
            remove_nature_effect_handle(handle);
        else if (handle == nullptr)
            handle = g_sfera_effect_manager.createActiveEffect(kAmbientRainSoundId, source);
    }
}
