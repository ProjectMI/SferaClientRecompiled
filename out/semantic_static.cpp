#include "semantic_static.h"

#include <cstdint>

uint32_t sfera_cursor_texture_name(uint32_t slot) {
    const char* name = nullptr;
    switch (slot) {
        case 0u: name = "_cursor1"; break;
        case 1u: name = "_cursor2"; break;
        case 2u: name = "cursor2"; break;
        case 3u: name = "cursor1"; break;
        default: return 0u;
    }
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(name));
}

