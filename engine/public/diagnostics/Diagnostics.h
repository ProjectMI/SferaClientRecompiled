#pragma once

#include <cstdint>
#include <cstdio>
#include <memory>
#include <string>
#include <string_view>

struct SferaEngineDiagnosticCallbacks;
class SferaEngineDiagnostics;

struct SferaEngineDiagnosticCallbacks
{
    void (*fatal_error)(std::string_view) = nullptr;
    void (*operation_failed)(std::string_view) = nullptr;
    void (*write_log)(std::string_view) = nullptr;
    void (*light_activated)() noexcept = nullptr;
    void (*report_message)(std::string_view) = nullptr;
    void (*warning_message)(std::string_view) = nullptr;
};

class SferaEngineDiagnostics
{
  public:
    static void install(SferaEngineDiagnosticCallbacks callbacks) noexcept
    {
        callbacks_ = callbacks;
    }
    [[noreturn]] static void fatal(std::string_view message);
    [[noreturn]] static void fail(std::string_view message);
    static void report(std::string_view message)
    {
        if (callbacks_.report_message != nullptr)
            callbacks_.report_message(message);
    }
    static void warning(std::string_view message)
    {
        if (callbacks_.warning_message != nullptr)
            callbacks_.warning_message(message);
    }
    static void write(std::string_view message);
    static void write(int number);
    static void lightActivated() noexcept
    {
        if (callbacks_.light_activated != nullptr)
            callbacks_.light_activated();
    }

  private:
    static SferaEngineDiagnosticCallbacks callbacks_;
};

class IOutputDevice;

class IOutputDevice
{
  public:
    virtual ~IOutputDevice() = default;
    virtual void write(std::string_view text) = 0;
};

class COutputLogDevice;
struct SferaLogRuntime;

class COutputLogDevice : public IOutputDevice
{
  public:
    std::string filename;
    void setFilename(const std::string &path);
    void write(std::string_view text) override;
};

struct SferaLogRuntime
{
    std::string path;
    std::uint32_t size_limit = 0;
    void initialize();
    void write(std::string_view text);
    void write(int number);
    void writeTimestamp(std::string_view prefix);
};

extern SferaLogRuntime g_sfera_log_runtime;

class SferaLogFileHelper;

class SferaLogFileHelper
{
  public:
    static std::unique_ptr<FILE, decltype(&std::fclose)> openLogFile(const std::string &path, const std::string &mode);
};
