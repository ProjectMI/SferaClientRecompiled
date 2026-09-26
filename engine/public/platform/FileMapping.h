#pragma once

#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <string_view>

class SferaFileMap;

class SferaFileMap
{
  public:
    explicit SferaFileMap(const std::string &path);
    SferaFileMap(const SferaFileMap &) = delete;
    SferaFileMap &operator=(const SferaFileMap &) = delete;
    ~SferaFileMap() noexcept;
    bool open(const std::string &path);
    void close() noexcept;
    bool isOpen() const noexcept
    {
        return mapped_view != nullptr;
    }

    std::span<const std::uint8_t> bytes() const noexcept
    {
        return {mapped_view, file_size};
    }

  private:
    const std::uint8_t *mapped_view = nullptr;
    std::size_t file_size = 0u;
    std::string filename;
    void reportError(std::string_view operation) const noexcept;
};
