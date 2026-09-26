#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include "audio/EffectVoice.h"
#include "audio/Sound.h"
#include "math/Vector.h"

struct CSoundEffectDefinition;
struct SferaSoundSource;
struct SferaSoundTimeGroup;

struct SferaSoundSource
{
    std::string filename;
    bool silence = false;
    float silence_duration = 0.0f;
};

struct SferaSoundTimeGroup
{
    float begin = 0.0f;
    float end = 0.0f;
    std::size_t source_begin = 0u;
    std::size_t source_end = 0u;
};

struct CSoundEffectDefinition : IEffectVoiceDefinition, std::enable_shared_from_this<CSoundEffectDefinition>
{
    std::unique_ptr<IEffectVoice> createVoice() const override;
    std::vector<SferaSoundSource> sources;
    std::vector<SferaSoundTimeGroup> time_groups;
    std::uint32_t effect_number{}, flags{};
    SferaVec3F offset{}, region_radius{};
    float mix_duration = 1.0f;
    int cache_lifetime = 4;
    SferaSound3DParameters parameters{};
};

class CSoundEffect;
class CSoundManager;
struct SferaParserRange;
class SferaSimpleParser;

class CSoundEffect : public IEffectVoice
{
  public:
    std::shared_ptr<const CSoundEffectDefinition> definition;
    bool silence_active = false, distance_paused = false;
    std::uint64_t silence_started_at{}, transition_started_at{};
    float silence_duration{}, saved_play_time{};
    SferaVec3F region_offset{}, last_position{};
    std::optional<std::size_t> last_source_index;
    std::shared_ptr<CSound> active_sound;
    SferaSound3DParameters sound_parameters{};

    static std::shared_ptr<const CSoundEffectDefinition> loadDefinition(SferaSimpleParser &parser, const SferaParserRange &range);
    explicit CSoundEffect(std::shared_ptr<const CSoundEffectDefinition> source);
    ~CSoundEffect() override;
    CSoundEffect(const CSoundEffect &) = delete;
    CSoundEffect &operator=(const CSoundEffect &) = delete;
    void reset() override;
    float startTime() const override
    {
        return sound_parameters.max_distance;
    }
    void start(const SferaVec3F *frame, bool after_start_time) override;
    void update(const SferaVec3F *frame, float age) override;
    void stop() override;
    bool isComplete() const override;

  private:
    static float sound_elapsed(std::uint64_t start);
    static std::uint32_t sound_flag(std::string_view token);
    static void release_active_sound(CSoundEffect &effect);
    static bool play_sound(CSound &sound, bool looped, float position);
    static std::shared_ptr<CSound> find_cached_sound(CSoundManager &manager, const std::string &filename);
    static std::shared_ptr<CSound> create_cached_sound(CSoundManager &manager, const std::string &filename, const SferaSound3DParameters *parameters, int cache_lifetime);
    static bool sound_time_matches(float value, const SferaSoundTimeGroup &group)
    {
        return group.end < group.begin ? value < group.end || value >= group.begin : value >= group.begin && value < group.end;
    }
    static std::size_t choose_sound_source(CSoundEffect &effect);
    static bool sound_distance_gate(CSoundEffect &effect, const SferaVec3F *frame, float distance);
    static int parseInteger(SferaSimpleParser &parser, std::size_t index);
    static float parseReal(SferaSimpleParser &parser, std::size_t index);
    static SferaVec3F parseVector(SferaSimpleParser &parser);
    static float randomComponent(float radius);
};

struct SferaSoundDefinitionSearchScope;
class SoundEffectRegistry;

class SoundEffectRegistry
{
  public:
    std::shared_ptr<const CSoundEffectDefinition> find(std::uint32_t id) const;
    bool load();

  private:
    static bool lessThanId(const std::shared_ptr<const CSoundEffectDefinition> &definition, std::uint32_t number);
    static bool lessById(const std::shared_ptr<const CSoundEffectDefinition> &first, const std::shared_ptr<const CSoundEffectDefinition> &second);
    std::vector<std::shared_ptr<const CSoundEffectDefinition>> definitions;
};

struct SferaSoundDefinitionSearchScope
{
    void *handle;
    ~SferaSoundDefinitionSearchScope();
};
