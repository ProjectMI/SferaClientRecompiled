#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <exception>
#include <functional>
#include <iterator>
#include <memory>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

#include "audio/SoundEffects.h"
#include "config/SimpleParser.h"
#include "effects/Effect.h"
#include "effects/EffectManager.h"
#include "effects/ParticleEffects.h"
#include "effects/ScriptedEffects.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "resources/EffectLoader.h"
#include "text/Parsing.h"
#include "text/Text.h"

int SferaEffectLoader::effect_integer(SferaSimpleParser &parser, std::size_t index)
{
    return parser.readInt(index);
}

float SferaEffectLoader::effect_real(SferaSimpleParser &parser, std::size_t index)
{
    return parser.readFloat(index);
}

void SferaEffectLoader::effect_vector(SferaSimpleParser &parser, std::size_t index, SferaVec3F &output)
{
    (void)parser.readVector(index, output);
}

template <class T> void SferaEffectLoader::effect_sequence(SferaSimpleParser &parser, std::size_t index, std::span<T> output)
{
    if constexpr (std::is_floating_point_v<T>)
        (void)parser.readFloatSequence(index, output);
    else
        (void)parser.readIntSequence(index, output);
}

template <class InitializeKey, class ParseKey>
std::shared_ptr<SferaEffectTrack> SferaEffectLoader::load_effect_track(SferaSimpleParser &parser, const SferaParserRange &range, std::size_t mode_count, InitializeKey initialize, ParseKey parse)
{
    if (!parser.findValue("numkeys", &range))
        return nullptr;
    const int count = parser.readInt(0u);
    if (count <= 0)
        return nullptr;
    auto track = std::make_shared<SferaEffectTrack>();
    const std::size_t key_count = count;
    track->keys.resize(key_count);
    for (auto &key : track->keys)
        initialize(key);
    constexpr std::array modes{std::pair{"key", SferaEffectTrackKeyMode::Fixed}, std::pair{"rkey", SferaEffectTrackKeyMode::Random}, std::pair{"mrkey", SferaEffectTrackKeyMode::MirroredRandom}};
    for (const auto &[token, mode] : std::span(modes).first(mode_count))
    {
        parser.setScanRange(&range);
        while (parser.nextValue(token))
        {
            const int index = parser.readInt(0u);
            if (index < 0 || index >= count)
                continue;
            SferaEffectTrackKey key{};
            key.mode = mode;
            initialize(key);
            key.time = parser.readFloat(1u);
            parse(key);
            const std::size_t key_index = index;
            track->keys[key_index] = std::move(key);
        }
    }
    parser.clearScanRange();
    return track;
}

template <class Value> void SferaEffectLoader::initializeTrackKey(SferaEffectTrackKey &key)
{
    key.value.emplace<Value>();
}

void SferaEffectLoader::parseScalarTrackKey(SferaSimpleParser *parser, SferaEffectTrackKey &key)
{
    auto &value = std::get<SferaEffectTrackKeyScalar>(key.value);
    value.minimum = parser->readFloat(2u);
    if (key.mode != SferaEffectTrackKeyMode::Fixed)
        value.range = parser->readFloat(3u);
}

std::shared_ptr<const SferaEffectTrack> SferaEffectLoader::loadScalarEffectTrack(SferaSimpleParser *parser, const SferaParserRange *range)
{
    if (parser == nullptr || range == nullptr)
        return nullptr;
    return SferaEffectLoader::load_effect_track(*parser, *range, 2, &SferaEffectLoader::initializeTrackKey<SferaEffectTrackKeyScalar>,
                                                std::bind_front(&SferaEffectLoader::parseScalarTrackKey, parser));
}

void SferaEffectLoader::parseVectorTrackKey(SferaSimpleParser *parser, SferaEffectTrackKey &key)
{
    auto &value = std::get<SferaEffectTrackKeyVector>(key.value);
    SferaEffectLoader::effect_vector(*parser, 2u, value.minimum);
    if (key.mode != SferaEffectTrackKeyMode::Fixed)
        SferaEffectLoader::effect_vector(*parser, 5u, value.range);
}

std::shared_ptr<const SferaEffectTrack> SferaEffectLoader::loadVectorEffectTrack(SferaSimpleParser *parser, const SferaParserRange *range)
{
    if (parser == nullptr || range == nullptr)
        return nullptr;
    return SferaEffectLoader::load_effect_track(*parser, *range, 3, &SferaEffectLoader::initializeTrackKey<SferaEffectTrackKeyVector>,
                                                std::bind_front(&SferaEffectLoader::parseVectorTrackKey, parser));
}

bool SferaLightDefinition::load(SferaSimpleParser &parser, const SferaParserRange &range)
{
    SferaParserRange previous_block_range{};
    parser.getBlockRange(&previous_block_range);
    if (parser.findValue("light_pos", &range))
        SferaEffectLoader::effect_vector(parser, 0u, position);
    if (parser.findValue("light_color", &range))
        SferaEffectLoader::effect_sequence<float>(parser, 0u, color);
    if (parser.findValue("random_color", &range))
    {
        SferaEffectLoader::effect_sequence<int>(parser, 0u, random_color);
        randomize_color = true;
    }
    if (parser.findValue("brightness", &range))
    {
        brightness = SferaEffectLoader::effect_real(parser, 0);
        if (parser.tokenCount() > 1)
            brightness_delta = SferaEffectLoader::effect_real(parser, 1);
        vary_brightness = true;
    }
    if (parser.findValue("brightFreq", &range))
        brightness_frequency = SferaNumeric::lowByte(SferaNumeric::word(SferaEffectLoader::effect_integer(parser, 0u)));
    std::string attach_name;
    if (parser.findValue("attach", &range) && parser.readString(0u, attach_name))
    {
        if (SferaText::asciiEqual(attach_name, "ATTACH_LEFTHAND"))
            attach_mode = 1u;
        else if (SferaText::asciiEqual(attach_name, "ATTACH_RIGHTHAND"))
            attach_mode = 2u;
        else if (SferaText::asciiEqual(attach_name, "ATTACH_BETWEENHANDS"))
            attach_mode = 3u;
    }
    SferaParserRange track_range{};
    if (parser.findBlock("color_track", &track_range, &range, 1))
        color_track = SferaEffectLoader::loadVectorEffectTrack(&parser, &track_range);
    if (parser.findBlock("alpha_track", &track_range, &range, 1))
        alpha_track = SferaEffectLoader::loadScalarEffectTrack(&parser, &track_range);
    if (parser.findBlock("position_track", &track_range, &range, 1))
        position_track = SferaEffectLoader::loadVectorEffectTrack(&parser, &track_range);
    if (alpha_track != nullptr)
        alpha_track->requireRandomCapacity(65536);
    parser.setBlockRange(&previous_block_range);
    return true;
}

auto CScriptedEffect::findDefinitionIndex(const auto &definitions, std::string_view name) -> int
{
    for (std::size_t index = 0; index < definitions.size(); ++index)
    {
        if (SferaText::asciiEqual(definitions[index]->name, name))
            return std::in_range<int>(index) ? static_cast<int>(index) : -1;
    }
    return -1;
}

auto CScriptedEffect::loadDefinitionBlocks(SferaSimpleParser &parser, std::string_view name, const SferaParserRange *scope, auto load)
{
    parser.setBlockRange(scope);
    SferaParserRange block;
    while (parser.nextBlock(name, &block))
    {
        SferaParserRange continuation;
        parser.getBlockRange(&continuation);
        load(block);
        parser.setBlockRange(&continuation);
    }
    parser.clearBlockRange();
}

auto CScriptedEffect::addRenderSlotBudget(CScriptedEffect &parsed, std::size_t kExpandedParticleSlotSafetyLimit, std::size_t slots)
{
    if (slots > kExpandedParticleSlotSafetyLimit - parsed.render_slot_budget)
        throw std::length_error("Effect definition exceeds expanded particle safety budget");
    parsed.render_slot_budget += slots;
}

void CScriptedEffect::loadMeshDefinitionBlock(const std::string &filename, SferaSimpleParser &parser, CScriptedEffect &parsed, std::size_t kExpandedParticleSlotSafetyLimit,
                                              const std::shared_ptr<CScriptedEffectDefinition> &data, const SferaParserRange &block)
{
    auto mesh = std::make_shared<SferaEffectMeshDefinition>();
    if (!mesh->loadDefinition(filename, parser, block))
        g_sfera_effect_manager.reportError((std::string("CScriptedEffect::LoadScript(") + filename + "): Can't load effectmesh_def block"));
    addRenderSlotBudget(parsed, kExpandedParticleSlotSafetyLimit, mesh->renderSlotCount());
    data->meshes.push_back(std::move(mesh));
}

void CScriptedEffect::loadParticleDefinitionBlock(const std::string &filename, SferaSimpleParser &parser, std::vector<std::shared_ptr<SferaParticleSystemDefinition>> &particles,
                                                  const SferaParserRange &block)
{
    auto particle = std::make_shared<SferaParticleSystemDefinition>();
    if (!particle->loadDefinition(filename, parser, block))
        g_sfera_effect_manager.reportError((std::string("CScriptedEffect::LoadScript(") + filename + "): Can't load psystem_def block"));
    CScriptedEffect::prepare_particle_definition(particle);
    particles.push_back(std::move(particle));
}

void CScriptedEffect::loadLightDefinitionBlock(const std::string &filename, SferaSimpleParser &parser, const std::shared_ptr<CScriptedEffectDefinition> &data, const SferaParserRange &light_range)
{
    auto light = std::make_shared<SferaLightDefinition>();
    if (!light->load(parser, light_range))
        g_sfera_effect_manager.reportError((std::string("CScriptedEffect::LoadScript(") + filename + "): Can't load light_def block"));
    data->lights.push_back(std::move(light));
}

bool CScriptedEffect::loadScript(const std::string &filename)
{
    if (filename.empty() || !meshes.empty() || !lights.empty() || !particle_systems.empty())
        return false;
    SferaSimpleParser parser;
    if (!parser.load(filename))
    {
        g_sfera_effect_manager.reportError((std::string("Cannot read effect script: ") + filename));
        return false;
    }
    try
    {
        CScriptedEffect parsed;
        parsed.initializeScriptedState();
        auto data = std::make_shared<CScriptedEffectDefinition>();
        std::vector<std::shared_ptr<SferaParticleSystemDefinition>> particles;

        // The renderer has a 10k per-frame submission pool, but SEF definitions can
        // legitimately describe a larger *potential* child-particle graph.  Keep a
        // separate allocation-safety ceiling here; actual frame pressure is handled
        // by SferaParticleSystemInstance::commit().
        constexpr std::size_t kExpandedParticleSlotSafetyLimit = 65536u;
        constexpr std::size_t kParticleInstanceSafetyLimit = 10000u;

        loadDefinitionBlocks(parser, "effectmesh_def", nullptr,
                             std::bind_front(&CScriptedEffect::loadMeshDefinitionBlock, std::cref(filename), std::ref(parser), std::ref(parsed), kExpandedParticleSlotSafetyLimit, std::cref(data)));
        loadDefinitionBlocks(parser, "psystem_def", nullptr, std::bind_front(&CScriptedEffect::loadParticleDefinitionBlock, std::cref(filename), std::ref(parser), std::ref(particles)));
        for (auto &particle : particles)
            for (auto &link : particle->links)
            {
                link.target_index = findDefinitionIndex(particles, link.target_name);
                // The legacy loader left unresolved child names detached.  Keep the
                // definition and let the corresponding particle slots run without a child.
                // Old prototype expansion consumed one seed triplet per direct child.
                // Keep that global CRT sequence without retaining a mutable prototype graph.
                for (std::size_t child = 0; link.target_index >= 0 && child < link.instance_count; ++child)
                {
                    for (int draw = 0; draw < 3; ++draw)
                        (void)std::rand();
                }
            }
        // Compute expanded sizes from leaves, rejecting cycles before allocating instances.
        std::vector<std::size_t> remaining(particles.size()), budget(particles.size()), nodes(particles.size(), 1), depth(particles.size(), 1);
        std::vector<std::vector<std::pair<std::size_t, std::size_t>>> parents(particles.size());
        std::vector<std::size_t> ready;
        for (std::size_t index = 0; index < particles.size(); ++index)
        {
            budget[index] = particles[index]->particles.size();
            for (const auto &link : particles[index]->links)
                if (link.instance_count != 0 && link.target_index >= 0 && std::cmp_less(link.target_index, particles.size()))
                {
                    const std::size_t target_index = link.target_index;
                    parents[target_index].push_back({index, link.instance_count});
                    ++remaining[index];
                }
            if (remaining[index] == 0)
                ready.push_back(index);
        }
        for (std::size_t cursor = 0; cursor < ready.size(); ++cursor)
        {
            const auto child = ready[cursor];
            for (const auto [parent, count] : parents[child])
            {
                if ((budget[child] != 0 && count > (kExpandedParticleSlotSafetyLimit - budget[parent]) / budget[child]) || count > (kParticleInstanceSafetyLimit - nodes[parent]) / nodes[child])
                {
                    throw std::length_error("Expanded particle graph exceeds its budget");
                }
                budget[parent] += budget[child] * count;
                nodes[parent] += nodes[child] * count;
                depth[parent] = std::max(depth[parent], depth[child] + 1);
                if (depth[parent] > 64)
                    throw std::length_error("Particle graph nesting exceeds 64");
                if (--remaining[parent] == 0)
                    ready.push_back(parent);
            }
        }
        if (ready.size() != particles.size())
            throw std::invalid_argument("Cyclic particle graph");
        std::size_t instance_count = 0;
        for (std::size_t index = 0; index < particles.size(); ++index)
        {
            addRenderSlotBudget(parsed, kExpandedParticleSlotSafetyLimit, budget[index]);
            if (nodes[index] > kParticleInstanceSafetyLimit - instance_count)
                throw std::length_error("Particle instance budget exceeded");
            instance_count += nodes[index];
            data->particles.push_back(std::move(particles[index]));
        }
        SferaParserRange range;
        if (parser.findBlock("effect_def", &range, nullptr, 1))
        {
            std::string text;
            if (parser.findValue("effect_name", &range) && parser.readQuotedString(0, text))
                parsed.assignScriptName(text);
            if (parser.findValue("effect_number", &range))
                parsed.effect_id = SferaEffectLoader::effect_integer(parser, 0);
            if (parser.findValue("effect_time", &range))
                parsed.cycle_length = parsed.lifetime_ticks = SferaEffectLoader::effect_integer(parser, 0);
            if (parser.findValue("effect_timelimit", &range))
                parsed.cycle_length = SferaEffectLoader::effect_integer(parser, 0);
            if (parser.findValue("updvisible_only", &range))
                data->update_visible_only = parser.readBool(0);
            if (parser.findValue("boundbox", &range))
            {
                std::array<float, 6> bounds{};
                if (parser.readFloatSequence(0, bounds))
                {
                    for (std::size_t axis = 0; axis < 3; ++axis)
                    {
                        parsed.bounds_max[axis] = bounds[axis];
                        parsed.bounds_min[axis] = bounds[axis + 3];
                    }
                    parsed.spatial_gate_enabled = true;
                }
            }
            if (parser.findValue("daytime_work", &range))
            {
                parsed.range_min = 1.0f - SferaEffectLoader::effect_real(parser, 0) / 24.0f;
                parsed.range_max = 1.0f - SferaEffectLoader::effect_real(parser, 1) / 24.0f;
            }
            if (parser.findValue("worktime", &range))
            {
                data->work_time_min = SferaEffectLoader::effect_integer(parser, 0);
                data->work_time_max = SferaEffectLoader::effect_integer(parser, 1);
            }
            if (parser.findValue("sleeptime", &range))
            {
                data->sleep_time_min = SferaEffectLoader::effect_integer(parser, 0);
                data->sleep_time_max = SferaEffectLoader::effect_integer(parser, 1);
            }
            if (parser.findValue("effftype", &range))
                data->completes_immediately = SferaEffectLoader::effect_integer(parser, 0) != 0;
            SferaParserRange block;
            if (parser.findBlock("sound_def", &block, &range, 1))
                data->sound = CSoundEffect::loadDefinition(parser, block);
            loadDefinitionBlocks(parser, "light_def", &range, std::bind_front(&CScriptedEffect::loadLightDefinitionBlock, std::cref(filename), std::ref(parser), std::cref(data)));
            if (parser.findValue("subeffects_num", &range))
            {
                const int count = parser.readInt(0u);
                if (count > 0)
                    data->subeffects.resize(count);
            }
            parser.setScanRange(&range);
            while (parser.nextValue("subeffect"))
            {
                const int index = parser.readInt(0u);
                if (index < 0 || std::cmp_greater_equal(index, data->subeffects.size()))
                    continue;
                auto &subeffect = data->subeffects[index];
                const auto kind = parser.tokenAt(1);
                if (parser.readQuotedString(2, text))
                {
                    if (SferaText::asciiEqual(kind, "EFF_MESH"))
                    {
                        subeffect.kind = SferaSubeffectDefinitionKind::Mesh;
                        subeffect.definition_index = findDefinitionIndex(data->meshes, text);
                    }
                    else if (SferaText::asciiEqual(kind, "EFF_PSYSTEM"))
                    {
                        subeffect.kind = SferaSubeffectDefinitionKind::ParticleSystem;
                        subeffect.definition_index = findDefinitionIndex(data->particles, text);
                    }
                }
                constexpr std::array attachments{"ATTACH_LEFTHAND", "ATTACH_RIGHTHAND", "ATTACH_BETWEENHANDS", "ATTACH_SWORD"};
                for (std::size_t attachment = 0; attachment < attachments.size(); ++attachment)
                {
                    if (SferaText::asciiEqual(parser.tokenAt(3), attachments[attachment]))
                        subeffect.attach_mode = attachment + 1u;
                }
            }
            parser.clearScanRange();
        }
        IEffect::operator=(std::move(parsed));
        definition = std::move(data);
        pooled_instances.clear();
        return true;
    }
    catch (const std::exception &error)
    {
        const auto message = std::string("CScriptedEffect::LoadScript(") + filename + "): " + error.what();
        g_sfera_effect_manager.reportError(message);
        return false;
    }
}

std::uint32_t SferaEffectLoader::effect_flag(std::string_view token)
{
    if (token.empty())
        return 0u;

    static constexpr SferaEffectflagFlag flags[] = {
        {"PS_ROTATEXYZ", 1u << 0u},       {"PS_ROTATEX", 1u << 1u},          {"PS_ROTATEY", 1u << 2u},          {"PS_ROTATEZ", 1u << 3u},         {"PS_USEROTSCALE", 1u << 4u},
        {"PS_TRANSLATEONLY", 1u << 5u},   {"PS_STATICEMITALL", 1u << 6u},    {"PS_DYNAMICEMITALL", 1u << 7u},   {"PS_USEMAGNITE", 1u << 8u},      {"PS_NOHEAVYATTACH", 1u << 10u},
        {"PS_NOFACECAMERA", 1u << 11u},   {"PS_NOLOCALTIME", 1u << 12u},     {"PS_NOLIFETIME", 1u << 13u},      {"PS_USEUVTRANSLATE", 1u << 14u}, {"PS_USECOLOR", 1u << 15u},
        {"PS_USEDISTORTION", 1u << 16u},  {"PS_MAGFACTORISLIFE", 1u << 17u}, {"PS_EMITONPOSCHANGE", 1u << 18u}, {"PS_RANDOMTEXFRAME", 1u << 19u}, {"PS_MAGISCHILDPS", 1u << 20u},
        {"PS_MAGFACTORGTIME", 1u << 21u}, {"PS_EMITCTRLRHW", 1u << 22u},     {"PS_PARENTALPHA", 1u << 23u},     {"PS_PARENTLIFETIME", 1u << 24u}, {"PS_DIRECTVELOCITY", 1u << 25u},
        {"PS_FOLLOWWITHSPIN", 1u << 27u},
    };
    for (const SferaEffectflagFlag &flag : flags)
        if (SferaText::asciiEqual(token, flag.name))
            return flag.value;
    return 0u;
}

std::shared_ptr<const SferaEffectMeshResource> SferaEffectMeshDefinition::find_mesh_resource(std::string_view name)
{
    if (name.empty())
        return nullptr;
    const auto &resources = g_sfera_effect_manager.mesh_resources;
    const auto found = std::find_if(resources.begin(), resources.end(), std::bind_front(&SferaEffectMeshDefinition::meshResourceNamed, name));
    return found == resources.end() ? nullptr : *found;
}

void SferaEffectLoader::parseMeshVectorTrackKey(SferaSimpleParser &parser, bool degrees, SferaEffectTrackKey &key)
{
    auto &value = std::get<SferaEffectTrackKeyVector>(key.value);
    SferaEffectLoader::effect_vector(parser, 2u, value.minimum);
    if (degrees)
    {
        value.minimum.x *= 0.01745329424738884f;
        value.minimum.y *= 0.01745329424738884f;
        value.minimum.z *= 0.01745329424738884f;
    }
}

std::shared_ptr<const SferaEffectTrack> SferaEffectLoader::load_mesh_vector_track(SferaSimpleParser &parser, const SferaParserRange &range, bool degrees)
{
    auto track = SferaEffectLoader::load_effect_track(parser, range, 1, &SferaEffectLoader::initializeTrackKey<SferaEffectTrackKeyVector>,
                                                      std::bind_front(&SferaEffectLoader::parseMeshVectorTrackKey, std::ref(parser), degrees));
    if (track != nullptr && parser.findValue("interpolation", &range) && SferaText::asciiEqual(parser.tokenAt(0u), "I_COSINE"))
        track->cosine_interpolation = true;
    return track;
}

void SferaEffectLoader::parseMeshColorTrackKey(SferaSimpleParser &parser, SferaEffectTrackKey &key)
{
    auto &color = std::get<SferaEffectTrackKeyColor>(key.value);
    for (std::size_t channel = 0; channel < 4; ++channel)
    {
        color.minimum.channels[channel] = SferaNumeric::word(parser.readInt(2u + channel)) & 0xffu;
        if (key.mode != SferaEffectTrackKeyMode::Fixed)
            color.range.channels[channel] = SferaNumeric::word(parser.readInt(6u + channel)) & 0xffu;
    }
}

std::shared_ptr<const SferaEffectTrack> SferaEffectLoader::load_mesh_color_track(SferaSimpleParser &parser, const SferaParserRange &range)
{
    return SferaEffectLoader::load_effect_track(parser, range, 2, &SferaEffectLoader::initializeTrackKey<SferaEffectTrackKeyColor>,
                                                std::bind_front(&SferaEffectLoader::parseMeshColorTrackKey, std::ref(parser)));
}

SferaParticleSystemDefinitionShape SferaParticleSystemDefinition::particle_shape(std::string_view name)
{
    if (SferaText::asciiEqual(name, "EMITSHAPE_LINE"))
        return SferaParticleSystemDefinitionShape::Line;
    if (SferaText::asciiEqual(name, "EMITSHAPE_DISK"))
        return SferaParticleSystemDefinitionShape::Disk;
    if (SferaText::asciiEqual(name, "EMITSHAPE_SPHERE"))
        return SferaParticleSystemDefinitionShape::Sphere;
    if (SferaText::asciiEqual(name, "EMITSHAPE_BOX"))
        return SferaParticleSystemDefinitionShape::Box;
    if (SferaText::asciiEqual(name, "EMITSHAPE_CYLINDER"))
        return SferaParticleSystemDefinitionShape::Cylinder;
    if (SferaText::asciiEqual(name, "EMITSHAPE_RING"))
        return SferaParticleSystemDefinitionShape::Ring;
    if (SferaText::asciiEqual(name, "EMITSHAPE_DISK2"))
        return SferaParticleSystemDefinitionShape::Annulus;
    return SferaParticleSystemDefinitionShape::Points;
}

void SferaParticleSystemDefinition::load_track_array(SferaSimpleParser &parser, const SferaParserRange &range, std::string_view block_name,
                                                     std::vector<std::shared_ptr<const SferaEffectTrack>> &tracks, bool color)
{
    if (tracks.empty() || parser.countBlocks(block_name, &range) <= 0)
        return;
    const bool scalar = SferaText::asciiEqual(block_name, "size_track");
    SferaParserRange block{};
    parser.setBlockRange(&range);
    while (parser.nextBlock(block_name, &block))
    {
        int index = 0;
        if (parser.findValue("track_num", &block))
            index = parser.readInt(0u);
        if (index < 0 || index >= tracks.size())
            continue;
        tracks[index] = scalar  ? SferaEffectLoader::loadScalarEffectTrack(&parser, &block)
                        : color ? SferaEffectLoader::load_mesh_color_track(parser, block)
                                : SferaEffectLoader::loadVectorEffectTrack(&parser, &block);
    }
    parser.clearBlockRange();
}

bool SferaEffectMeshDefinition::loadDefinition(const std::string &, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SferaParserRange previous{};
    parser.getBlockRange(&previous);
    std::string text;
    if (parser.findValue("effectmesh_name", &range))
    {
        parser.readQuotedString(0u, text);
        name = text;
    }
    if (parser.findValue("effectmesh_ssm", &range))
    {
        parser.readQuotedString(0u, text);
        mesh_resource = SferaEffectMeshDefinition::find_mesh_resource(text);
    }
    if (parser.findValue("effectmesh_flags", &range))
        for (std::size_t index = 0u; index < parser.tokenCount(); index += 2u)
            flags |= SferaEffectLoader::effect_flag(parser.tokenAt(index));
    if (parser.findValue("self_illumination", &range))
        self_illumination = SferaEffectLoader::effect_integer(parser, 0u);
    if (parser.findValue("color", &range))
        for (std::size_t channel = 0u; channel < 4u; ++channel)
            color.channels[channel] = SferaNumeric::lowByte(SferaNumeric::word(SferaEffectLoader::effect_integer(parser, channel)));
    SferaParserRange track_range{};
    if (parser.findBlock("rotation_track", &track_range, &range, 1))
        rotation_track = SferaEffectLoader::load_mesh_vector_track(parser, track_range, true);
    if (parser.findBlock("scale_track", &track_range, &range, 1))
        scale_track = SferaEffectLoader::load_mesh_vector_track(parser, track_range, false);
    if (parser.findBlock("position_track", &track_range, &range, 1))
        position_track = SferaEffectLoader::load_mesh_vector_track(parser, track_range, false);
    if (parser.findBlock("color_track", &track_range, &range, 1))
        color_track = SferaEffectLoader::load_mesh_color_track(parser, track_range);
    if (parser.findBlock("ucoord_track", &track_range, &range, 1))
        ucoord_track = SferaEffectLoader::loadScalarEffectTrack(&parser, &track_range);
    if (parser.findBlock("vcoord_track", &track_range, &range, 1))
        vcoord_track = SferaEffectLoader::loadScalarEffectTrack(&parser, &track_range);
    SferaParserRange texture_range{};
    if (parser.findBlock("texture_def", &texture_range, &range, 1))
    {
        custom_uv = true;
        if (parser.findValue("blendmode", &texture_range) && SferaText::asciiEqual(parser.tokenAt(0u), "PS_BLENDADD"))
            additive = true;
        if (parser.findValue("texture", &texture_range))
        {
            parser.readQuotedString(0u, text);
            texture_name = text;
        }
    }
    // Preserve the three CRT draws formerly used by the discarded prototype seed.
    for (int draw = 0; draw < 3; ++draw)
        (void)std::rand();
    parser.setBlockRange(&previous);
    return true;
}

auto SferaParticleSystemDefinition::setupTracks(SferaSimpleParser &parser, const SferaParserRange &block, std::string_view count_name, auto &tracks)
{
    if (!parser.findValue(count_name, &block))
        return;
    const int count = parser.readInt(0u);
    if (count > 0)
        tracks.resize(count);
}

auto SferaParticleSystemDefinition::assignTrack(SferaSimpleParser &parser, const SferaParserRange &particle_range, const std::vector<std::uint8_t> &selected, std::string_view key, auto member,
                                                const auto &tracks)
{
    if (!parser.findValue(key, &particle_range) || tracks.empty())
        return;
    const int parsed = parser.readInt(0u);
    if (parsed < 0 || std::cmp_greater_equal(parsed, tracks.size()))
        return;
    const auto *value = tracks[parsed].get();
    for (std::size_t index = 0; index < particles.size(); ++index)
        if (selected[index] == 1u)
            particles[index].*member = value;
}

bool SferaParticleSystemDefinition::loadDefinition(const std::string &, SferaSimpleParser &parser, const SferaParserRange &range)
{
    SferaParserRange caller_range{};
    parser.getBlockRange(&caller_range);
    SferaParserRange nested{};
    std::string text;
    if (parser.findValue("psystem_name", &range) && parser.readQuotedString(0u, text))
        name = text;
    if (parser.findValue("particles_num", &range))
    {
        const int count = parser.readInt(0u);
        if (count > 0)
            particles.resize(count);
    }
    if (parser.findValue("psystem_flags", &range))
        for (std::size_t index = 0u; index < parser.tokenCount(); index += 2u)
            flags |= SferaEffectLoader::effect_flag(parser.tokenAt(index));
    if (parser.findValue("transform_vec0", &range))
        SferaEffectLoader::effect_vector(parser, 0u, render_basis[0]);
    if (parser.findValue("transform_vec1", &range))
        SferaEffectLoader::effect_vector(parser, 0u, render_basis[1]);
    if (parser.findValue("transform_vec2", &range))
        SferaEffectLoader::effect_vector(parser, 0u, render_basis[2]);
    if (parser.findValue("transform_vec3", &range))
        SferaEffectLoader::effect_vector(parser, 0u, render_basis[3]);
    if (parser.findValue("distortion_vec", &range))
        SferaEffectLoader::effect_vector(parser, 0u, distortion);
    if (parser.findValue("self_illumination", &range))
        self_illumination = SferaEffectLoader::effect_integer(parser, 0u);
    if (parser.findValue("power", &range))
        power = SferaEffectLoader::effect_real(parser, 0u);
    SferaParserRange block{};
    if (parser.findBlock("power_track", &block, &range, 1))
        power_track = SferaEffectLoader::loadScalarEffectTrack(&parser, &block);
    if (parser.findBlock("position_track", &block, &range, 1))
        position_track = SferaEffectLoader::loadVectorEffectTrack(&parser, &block);
    if (parser.findBlock("scale_track", &block, &range, 1))
        scale_track = SferaEffectLoader::loadVectorEffectTrack(&parser, &block);
    if (parser.findBlock("rotation_track", &block, &range, 1))
        rotation_track = SferaEffectLoader::load_mesh_vector_track(parser, block, true);
    if (parser.findBlock("childs_def", &block, &range, 1))
    {
        if (parser.findValue("childs_num", &block))
        {
            const int count = parser.readInt(0u);
            if (count > 0)
            {
                links.resize(count);
                for (auto &link : links)
                    link.target_index = -1;
            }
        }
        parser.setScanRange(&block);
        while (!links.empty() && parser.nextValue("child"))
        {
            const int index = parser.readInt(0u);
            if (index < 0 || index >= links.size())
                continue;
            if (parser.readQuotedString(1u, text))
                links[index].target_name = text;
        }
        parser.clearScanRange();
    }
    if (parser.findBlock("magnite_def", &block, &range, 1))
    {
        if (parser.findBlock("magposition_track", &nested, &block, 1))
            magnet_position_track = SferaEffectLoader::loadVectorEffectTrack(&parser, &nested);
        if (parser.findBlock("magfactor_track", &nested, &block, 1))
            magnet_factor_track = SferaEffectLoader::loadVectorEffectTrack(&parser, &nested);
        if (parser.findValue("magchildps", &block))
        {
            magnet_child_index = SferaEffectLoader::effect_integer(parser, 0u);
            if (magnet_child_index >= 0 && magnet_child_index < links.size())
                ++links[magnet_child_index].instance_count;
            else
                magnet_child_index = -1;
        }
        if (parser.findValue("magfactor", &block))
        {
            float source[3]{};
            SferaEffectLoader::effect_sequence<float>(parser, 0u, source);
            magnet_factor = {source[0] == 0.0f ? 0.0f : 1.0f / source[0], source[1] == 0.0f ? 0.0f : 1.0f / source[1], source[2] == 0.0f ? 0.0f : 1.0f / source[2]};
        }
        if (parser.findValue("magpos", &block))
            SferaEffectLoader::effect_vector(parser, 0u, magnet_position);
    }
    if (parser.findBlock("emission_def", &block, &range, 1))
    {
        if (parser.findValue("shape", &block) && parser.readString(0u, text))
            shape = SferaParticleSystemDefinition::particle_shape(text);
        if (parser.findValue("randseed", &block))
            random_seed = SferaEffectLoader::effect_integer(parser, 0u);
        if (parser.findValue("randfactor", &block))
            random_factor = SferaEffectLoader::effect_integer(parser, 0u);
        if (parser.findValue("height", &block))
            height = SferaEffectLoader::effect_real(parser, 0u);
        if (parser.findValue("width", &block))
            width = SferaEffectLoader::effect_real(parser, 0u);
        if (parser.findValue("radius", &block))
            radius = SferaEffectLoader::effect_real(parser, 0u);
        if (parser.findValue("emit_num", &block))
            emission_count = SferaEffectLoader::effect_real(parser, 0u);
        if (parser.findValue("direction", &block))
            SferaEffectLoader::effect_vector(parser, 0u, direction);
        if (parser.findValue("emitter_pos", &block))
            SferaEffectLoader::effect_vector(parser, 0u, emitter_position);
        if (parser.findValue("shape_numpoints", &block))
        {
            const int count = parser.readInt(0u);
            if (count > 0)
                shape_points.resize(count);
        }
        parser.setScanRange(&block);
        while (!shape_points.empty() && parser.nextValue("point"))
        {
            const int index = parser.readInt(0u);
            if (index < 0 || index >= shape_points.size())
                continue;
            SferaEffectLoader::effect_vector(parser, 1u, shape_points[index]);
        }
        parser.clearScanRange();
        if (parser.findBlock("emission_track", &nested, &block, 1))
            emission_track = SferaEffectLoader::loadScalarEffectTrack(&parser, &nested);
        if (parser.findBlock("emissionpos_track", &nested, &block, 1))
            emission_position_track = SferaEffectLoader::loadVectorEffectTrack(&parser, &nested);
    }
    if (parser.findBlock("particleborn_def", &block, &range, 1))
    {
        if (parser.findValue("lifetime", &block))
            lifetime = SferaEffectLoader::effect_real(parser, 0u);
        if (parser.findValue("lifetime_rf", &block))
            lifetime_random_factor = SferaEffectLoader::effect_real(parser, 0u);
        if (parser.findBlock("lifetime_track", &nested, &block, 1))
            lifetime_track = SferaEffectLoader::loadScalarEffectTrack(&parser, &nested);
    }
    if (parser.findBlock("particletracks_def", &block, &range, 1))
    {
        setupTracks(parser, block, "nsize_tracks", size_tracks);
        setupTracks(parser, block, "ncolor_tracks", color_tracks);
        setupTracks(parser, block, "nvelocity_tracks", velocity_tracks);
        setupTracks(parser, block, "ngravitation_tracks", gravity_tracks);
        if (!size_tracks.empty())
            SferaParticleSystemDefinition::load_track_array(parser, block, "size_track", size_tracks, false);
        if (!color_tracks.empty())
            SferaParticleSystemDefinition::load_track_array(parser, block, "color_track", color_tracks, true);
        if (!velocity_tracks.empty())
            SferaParticleSystemDefinition::load_track_array(parser, block, "velocity_track", velocity_tracks, false);
        if (!gravity_tracks.empty())
            SferaParticleSystemDefinition::load_track_array(parser, block, "gravitation_track", gravity_tracks, false);
    }
    if (parser.findBlock("texture_def", &block, &range, 1))
    {
        if (parser.findValue("numframes", &block))
        {
            const int count = parser.readInt(0u);
            if (count > 0)
                texture_frames.resize(count);
        }
        if (parser.findValue("type", &block) && SferaText::asciiEqual(parser.tokenAt(0u), "PS_TANIMCOORD"))
            flags |= (1u << 9u);
        if (parser.findValue("blendmode", &block) && SferaText::asciiEqual(parser.tokenAt(0u), "PS_BLENDADD"))
            additive = true;
        if (parser.findValue("animspeed", &block))
            texture_animation_speed = SferaEffectLoader::effect_real(parser, 0u);
        if (!texture_frames.empty() && parser.findValue("texture", &block) && parser.readQuotedString(0u, text))
            texture_frames[0].texture_name = text;
        parser.setScanRange(&block);
        while (!texture_frames.empty() && parser.nextValue("frame"))
        {
            const int index = parser.readInt(0u);
            if (index < 0 || index >= texture_frames.size())
                continue;
            auto &frame = texture_frames[index];
            if ((flags & (1u << 9u)) != 0u)
            {
                SferaEffectLoader::effect_sequence<float>(parser, 1u, frame.uv);
                custom_uv = true;
            }
            else if (parser.readQuotedString(1u, text))
            {
                frame.texture_name = text;
            }
        }
        parser.clearScanRange();
    }
    if (!particles.empty() && parser.countBlocks("particles_def", &range) > 0)
    {
        std::vector<std::uint8_t> selected(particles.size(), std::uint8_t{1u});
        SferaParserRange particle_range{};
        parser.setBlockRange(&range);
        while (parser.nextBlock("particles_def", &particle_range))
        {
            std::fill(selected.begin(), selected.end(), std::uint8_t{1u});
            if (parser.findValue("select", &particle_range))
            {
                const auto mode = parser.tokenAt(0u);
                if (SferaText::asciiEqual(mode, "range"))
                {
                    std::fill(selected.begin(), selected.end(), std::uint8_t{0u});
                    std::ptrdiff_t begin = SferaEffectLoader::effect_integer(parser, 1u), end = SferaEffectLoader::effect_integer(parser, 2u);
                    if (begin > end)
                        std::swap(begin, end);
                    begin = std::max(begin, std::ptrdiff_t{0});
                    end = std::min<std::ptrdiff_t>(end, std::ssize(particles));
                    if (begin < end)
                        std::fill(selected.begin() + begin, selected.begin() + end, std::uint8_t{1u});
                }
                else if (SferaText::asciiEqual(mode, "number"))
                {
                    std::fill(selected.begin(), selected.end(), std::uint8_t{0u});
                    for (std::size_t token = 1u; token < parser.tokenCount(); ++token)
                    {
                        std::ptrdiff_t index = SferaEffectLoader::effect_integer(parser, token);
                        index = std::max(index, std::ptrdiff_t{0});
                        index = std::min<std::ptrdiff_t>(index, std::ssize(particles) - 1);
                        selected[index] = 1u;
                    }
                }
            }

            assignTrack(parser, particle_range, selected, "size_track", &SferaParticleSettings::size_track, size_tracks);
            assignTrack(parser, particle_range, selected, "color_track", &SferaParticleSettings::color_track, color_tracks);
            assignTrack(parser, particle_range, selected, "velocity_track", &SferaParticleSettings::velocity_track, velocity_tracks);
            assignTrack(parser, particle_range, selected, "gravitation_track", &SferaParticleSettings::gravity_track, gravity_tracks);
            if (parser.findValue("texture_frame", &particle_range) && SferaText::asciiEqual(parser.tokenAt(0u), "RANDOM"))
                flags |= (1u << 19u);
            if (parser.findValue("child_ps", &particle_range))
            {
                const int link = SferaEffectLoader::effect_integer(parser, 0u);
                // Match the legacy loader: store the raw link index.  -1 means no
                // child; any other unresolved/out-of-range value simply never binds.
                for (std::size_t index = 0u; index < this->particles.size(); ++index)
                    if (selected[index] == 1u)
                        this->particles[index].link_index = link;
            }
        }
        parser.clearBlockRange();
    }
    for (std::size_t index = 0u; index < particles.size(); ++index)
        if (particles[index].link_index >= 0 && particles[index].link_index < links.size())
            ++links[particles[index].link_index].instance_count;
    parser.setBlockRange(&caller_range);
    return true;
}
