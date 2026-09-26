#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <string_view>

#include "diagnostics/Diagnostics.h"

class CSphereError;

class CSphereError : public IOutputDevice
{
  public:
    CSphereError() = default;
    void write(std::string_view text) override;
};

class IOutputDevice;
struct SferaErrorLogRuntime;

struct SferaErrorLogRuntime
{
    IOutputDevice *outputs[2]{};
    std::unique_ptr<CSphereError> owned_error;
    std::unique_ptr<COutputLogDevice> owned_log;
    bool enabled = false;
    std::string user_name;
    void initialize(IOutputDevice *error = nullptr, IOutputDevice *log = nullptr);
    void clear();
};

extern SferaErrorLogRuntime g_sfera_error_log_runtime;

class SferaEngineDiagnosticsAdapter;

class SferaEngineDiagnosticsAdapter
{
  public:
    static void bind() noexcept;

  private:
    static void fatal(std::string_view message);
    static void fail(std::string_view message);
    static void report(std::string_view message);
    static void warning(std::string_view message);
    static void write(std::string_view message);
    static void lightActivated() noexcept;
};

class WorldDiagnostics;

class WorldDiagnostics
{
  public:
    static std::string message;

    static constexpr std::uint32_t codeBaseMismatch = 1u << 7u;
    static void appendScriptContext(std::string_view text);
    static void flushScriptContext();
    static std::uint32_t inspectInstruction(std::uint16_t &module, std::uint32_t &offset, std::uint8_t *bytes, std::uint32_t &count);
    static void describeScript(bool includeTime);
    static void appendCallStack(std::string &output);
    static std::optional<std::string_view> scriptContext();
    static void report(std::string_view message);
    static void warning(std::string_view message);
    [[noreturn]] static void fail(std::string_view message);
};
