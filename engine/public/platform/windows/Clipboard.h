#pragma once

#include <windows.h>

struct SphereUIClipboardGuard;
struct SphereUIGlobalLockGuard;

struct SphereUIClipboardGuard
{
    ~SphereUIClipboardGuard()
    {
        ::CloseClipboard();
    }
};
struct SphereUIGlobalLockGuard
{
    HGLOBAL handle;
    ~SphereUIGlobalLockGuard()
    {
        ::GlobalUnlock(handle);
    }
};
