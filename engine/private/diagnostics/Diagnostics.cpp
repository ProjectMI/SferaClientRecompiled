#include <cstdio>
#include <ctime>
#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>

#include "diagnostics/Diagnostics.h"

void SferaEngineDiagnostics::fatal(std::string_view message)
{
    if (callbacks_.fatal_error != nullptr)
        callbacks_.fatal_error(message);
    throw std::runtime_error(std::string(message.empty() ? std::string_view{"Client error"} : message));
}

void SferaEngineDiagnostics::fail(std::string_view message)
{
    if (callbacks_.operation_failed != nullptr)
        callbacks_.operation_failed(message);
    throw std::runtime_error(std::string(message.empty() ? std::string_view{"World operation failed"} : message));
}

void SferaEngineDiagnostics::write(std::string_view message)
{
    if (callbacks_.write_log != nullptr)
        callbacks_.write_log(message);
}

void SferaEngineDiagnostics::write(int number)
{
    write(std::to_string(number) + '\n');
}

SferaEngineDiagnosticCallbacks SferaEngineDiagnostics::callbacks_{};

void COutputLogDevice::setFilename(const std::string &path)
{
    filename = path;
    if (filename.empty())
        return;
    auto file = SferaLogFileHelper::openLogFile(filename, "wt");
    if (!file)
        return;
    const auto now = std::time(nullptr);
    std::string created_at(32, '\0');
    if (ctime_s(created_at.data(), created_at.size(), &now) != 0)
        created_at.clear();
    else
        created_at.resize(created_at.find('\0'));
    std::fprintf(file.get(), "Sphere log file\nCreated: %s\n", created_at.c_str());
}

void COutputLogDevice::write(std::string_view text)
{
    if (filename.empty())
        return;
    auto file = SferaLogFileHelper::openLogFile(filename, "a+t");
    if (!file)
        return;
    std::fputs("- ", file.get());
    if (!text.empty())
        std::fwrite(text.data(), 1u, text.size(), file.get());
    std::fputc('\n', file.get());
}

void SferaLogRuntime::write(std::string_view text)
{
    if (path.empty())
        return;
    auto file = SferaLogFileHelper::openLogFile(path, "at");
    if (!file)
        return;
    if (!text.empty())
        std::fwrite(text.data(), 1u, text.size(), file.get());
    std::fflush(file.get());
}

void SferaLogRuntime::write(int number)
{
    const std::string line = std::to_string(number) + '\n';
    write(line);
}

void SferaLogRuntime::writeTimestamp(std::string_view prefix)
{
    write(prefix);
    const auto timestamp = ::_time64(nullptr);
    tm local{};
    ::_localtime64_s(&local, &timestamp);
    std::string date(128, '\0');
    date.resize(std::strftime(date.data(), date.size(), "%A, %d %B %Y", &local));
    write(date);
    write("  ");
    std::string time(9, '\0');
    if (::_strtime_s(time.data(), time.size()) != 0)
        time.clear();
    else
        time.resize(time.find('\0'));
    write(time);
    write("\n");
}

std::unique_ptr<FILE, decltype(&std::fclose)> SferaLogFileHelper::openLogFile(const std::string &path, const std::string &mode)
{
    FILE *file = nullptr;
    if (fopen_s(&file, path.c_str(), mode.c_str()) != 0)
        file = nullptr;
    return std::unique_ptr<FILE, decltype(&std::fclose)>(file, &std::fclose);
}
