#include <winsock2.h>
#include <windows.h>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <format>
#include <limits>
#include <memory>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>

#include "platform/FileMapping.h"
#include "platform/WindowsSocket.h"
#include "runtime/Clock.h"

SferaFileMap::SferaFileMap(const std::string &path)
{
    open(path);
}

SferaFileMap::~SferaFileMap() noexcept
{
    close();
}

void SferaFileMap::reportError(std::string_view operation) const noexcept
{
    try
    {
        const auto message = std::format("{} {}", operation, filename);
        std::fprintf(stderr, "%s\n", message.c_str());
        ::OutputDebugStringA(message.c_str());
    }
    catch (...)
    {
        ::OutputDebugStringA("File mapping cleanup failed");
    }
}

void SferaFileMap::close() noexcept
{
    if (mapped_view && !::UnmapViewOfFile(mapped_view))
        reportError("Error unmapping file");
    mapped_view = nullptr;
    file_size = 0u;
    filename.clear();
}

bool SferaFileMap::open(const std::string &path)
{
    close();
    if (path.empty())
        return false;
    const auto separator = path.find_last_of('\\');
    filename = path.substr(separator == std::string::npos ? 0u : separator + 1u);

    HANDLE opened = ::CreateFileA(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, nullptr);
    std::unique_ptr<std::remove_pointer_t<HANDLE>, decltype(&::CloseHandle)> file(opened == INVALID_HANDLE_VALUE ? nullptr : opened, &::CloseHandle);
    if (!file)
        return false;
    LARGE_INTEGER length{};
    if (!::GetFileSizeEx(file.get(), &length) || length.QuadPart <= 0 || std::cmp_greater(length.QuadPart, std::numeric_limits<std::size_t>::max()))
        return false;
    std::unique_ptr<std::remove_pointer_t<HANDLE>, decltype(&::CloseHandle)> mapping(::CreateFileMappingA(file.get(), nullptr, PAGE_READONLY, 0u, 0u, nullptr), &::CloseHandle);
    file.reset();
    if (!mapping)
        return false;
    const auto *view = static_cast<const std::uint8_t *>(::MapViewOfFile(mapping.get(), FILE_MAP_READ, 0u, 0u, 0u));
    if (view == nullptr)
        return false;
    mapped_view = view;
    file_size = length.QuadPart;
    return true;
}

bool SferaTcpConnectionContextWinsockSession::start() noexcept
{
    if (active)
        return true;
    WSADATA data{};
    active = ::WSAStartup(MAKEWORD(2, 1), &data) == 0;
    return active;
}
void SferaTcpConnectionContextWinsockSession::reset() noexcept
{
    if (std::exchange(active, false))
        ::WSACleanup();
}
void SferaTcpConnectionContextSocket::reset(SOCKET replacement) noexcept
{
    const auto old = std::exchange(value, replacement);
    if (old != INVALID_SOCKET)
        ::closesocket(old);
}

std::uint64_t WorldClock::microseconds() noexcept
{
    static const auto epoch = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - epoch).count();
}
