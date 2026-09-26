#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <vector>

struct MbcScrollParameters32;
class MbcUiMessageCodec;
struct SferaMbcRuntime;
struct SphereUIImageDescription;
class SphereUIWindow;
class SphereUIToolTipCtrl;
enum class SphereUIUiMessage : std::uint32_t;

struct MbcScrollParameters32
{
    std::uint32_t size;
    std::uint32_t mask;
    std::int32_t minimum;
    std::int32_t maximum;
    std::int32_t page_step;
    std::int32_t current;
    std::int32_t step;
};

class MbcUiMessageCodec
{
    SferaMbcRuntime &runtime_;
    std::uint32_t flags_;

    std::string text(std::uint32_t address) const;

    std::optional<std::string> optionalText(std::uint32_t address) const;

    std::span<std::uint8_t> bytes(std::uint32_t address, std::size_t size) const;

    std::vector<std::uint32_t> words(std::uint32_t address, std::size_t count) const;

    template <class T> T read(std::uint32_t address) const;

    template <class T> void write(std::uint32_t address, const T &value) const;

    void writeBool(std::uint32_t address, bool value) const;

    void writeSize(std::uint32_t address, std::size_t value) const;

    void writeText(std::uint32_t address, std::string_view value, std::size_t explicit_capacity = std::numeric_limits<std::size_t>::max(),
                   std::size_t content_limit = std::numeric_limits<std::size_t>::max()) const;

    SphereUIToolTipCtrl *tooltip(SphereUIWindow *window) const;

    SphereUIImageDescription imageDescription(std::uint32_t address) const;

  public:
    MbcUiMessageCodec(SferaMbcRuntime &runtime, std::uint32_t flags);

    std::uint32_t dispatch(SphereUIWindow *window, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) const;
};
