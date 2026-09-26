#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>
#include <string_view>

class SferaEffectTrack;
struct SferaEffectTrackKey;

class SferaEffectLoader;
struct SferaParserRange;
class SferaSimpleParser;
struct SferaVec3F;

class SferaEffectLoader
{
  public:
    static std::shared_ptr<const SferaEffectTrack> loadScalarEffectTrack(SferaSimpleParser *parser, const SferaParserRange *range);
    static std::shared_ptr<const SferaEffectTrack> loadVectorEffectTrack(SferaSimpleParser *parser, const SferaParserRange *range);
    static int effect_integer(SferaSimpleParser &parser, std::size_t index);
    static float effect_real(SferaSimpleParser &parser, std::size_t index);
    static void effect_vector(SferaSimpleParser &parser, std::size_t index, SferaVec3F &output);
    template <class T> static void effect_sequence(SferaSimpleParser &parser, std::size_t index, std::span<T> output);
    static std::uint32_t effect_flag(std::string_view token);
    static std::shared_ptr<const SferaEffectTrack> load_mesh_vector_track(SferaSimpleParser &parser, const SferaParserRange &range, bool degrees);
    static std::shared_ptr<const SferaEffectTrack> load_mesh_color_track(SferaSimpleParser &parser, const SferaParserRange &range);

  private:
    template <class InitializeKey, class ParseKey>
    static std::shared_ptr<SferaEffectTrack> load_effect_track(SferaSimpleParser &parser, const SferaParserRange &range, std::size_t mode_count, InitializeKey initialize, ParseKey parse);
    template <class Value> static void initializeTrackKey(SferaEffectTrackKey &key);
    static void parseScalarTrackKey(SferaSimpleParser *parser, SferaEffectTrackKey &key);
    static void parseVectorTrackKey(SferaSimpleParser *parser, SferaEffectTrackKey &key);
    static void parseMeshVectorTrackKey(SferaSimpleParser &parser, bool degrees, SferaEffectTrackKey &key);
    static void parseMeshColorTrackKey(SferaSimpleParser &parser, SferaEffectTrackKey &key);
};

struct SferaEffectflagFlag;

struct SferaEffectflagFlag
{
    std::string_view name;
    std::uint32_t value;
};
