#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

class SphereUIChatFilter;
struct SphereUIChatFilterRule;

struct SphereUIChatFilterRule
{
    std::string word;
    int kind = 0;
    std::vector<std::string> exceptions;
};

class SphereUIChatFilter
{
  public:
    SphereUIChatFilter();
    explicit SphereUIChatFilter(std::vector<SphereUIChatFilterRule> entries);
    bool rejects(std::string_view message) const;
    static bool invalidIdentifier(std::string_view name);
    static std::string normalize(std::string_view text, std::size_t alphabet);

  private:
    std::vector<SphereUIChatFilterRule> rules;
    bool matchesWord(std::string_view word, std::size_t alphabet) const;
    bool matchesMessage(std::string_view message, std::size_t alphabet) const;

  private:
    friend struct SphereUIChatFilterRule;

  private:
    static bool chatRussianVowelOrSign(std::uint8_t value);
    static bool chatKeyboardAmbiguous(std::uint8_t value);
    static const std::array<std::array<std::uint8_t, 256>, 2> &chatCharacterMaps();
    static std::array<std::array<std::uint8_t, 256>, 2> createCharacterMaps();
    static void applyCharacterAliases(std::array<std::array<std::uint8_t, 256>, 2> &result, std::size_t alphabet, std::string_view group);
};
