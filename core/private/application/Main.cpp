#include <windows.h>

#include "application/ClientApplication.h"

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE, LPWSTR, int)
{
    return SferaClientApplication::run(instance);
}
