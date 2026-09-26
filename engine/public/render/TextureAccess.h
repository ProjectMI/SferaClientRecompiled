#pragma once

#include <string_view>

#include "ui/UiTypes.h"

struct IDirect3DBaseTexture9;

class SferaTextureAccess
{
  public:
    static int find(std::string_view name);
    static IDirect3DBaseTexture9 *resource(int index);
    static SphereUITextExtent size(int index);
    static bool hasAlpha(int index);
};
