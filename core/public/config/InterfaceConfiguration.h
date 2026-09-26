#pragma once

#include <optional>
#include <string>
#include <string_view>

class SphereUIInterfaceConfiguration;

class SphereUIInterfaceConfiguration
{
  public:
    static std::optional<std::string_view> value(std::string_view key);
    static bool empty() noexcept
    {
        return text_.empty();
    }
    static void close() noexcept
    {
        text_.clear();
        filename_.clear();
    }
    static void open(const std::string &filename);
    static int readInteger(std::string_view key, int fallback);
    static void writeInteger(std::string_view key, int value);
    static void save();

  private:
    static std::string text_;
    static std::string filename_;
};
