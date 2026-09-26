#pragma once

#include <winsock2.h>

struct SferaTcpConnectionContextSocket;
struct SferaTcpConnectionContextWinsockSession;

struct SferaTcpConnectionContextWinsockSession
{
    bool active = false;
    bool start() noexcept;
    void reset() noexcept;
    ~SferaTcpConnectionContextWinsockSession()
    {
        reset();
    }
};
struct SferaTcpConnectionContextSocket
{
    SOCKET value = INVALID_SOCKET;
    void reset(SOCKET replacement = INVALID_SOCKET) noexcept;
    ~SferaTcpConnectionContextSocket()
    {
        reset();
    }
};

// The three workers retain their receive / dispatch / maintenance roles.
