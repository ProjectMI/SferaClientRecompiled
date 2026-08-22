#include "semantic_static.h"
#include "lifted_functions.h"

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

namespace {

const LiftFunction kFilebufFunctions[] = {
    &sfera_sub_004B3B70, &sfera_sub_004B15E0, &sfera_sub_004B15F0, &sfera_sub_004B2680, &sfera_sub_004B16D0,
    &sfera_sub_004EF656, &sfera_sub_004B1600, &sfera_sub_004B28A0, &sfera_sub_004EF65C, &sfera_sub_004EF662,
    &sfera_sub_004B2EE0, &sfera_sub_004B2FE0, &sfera_sub_004B1760, &sfera_sub_004B1650, &sfera_sub_004B17F0
};
const LiftFunction kOfstreamFunctions[] = {&sfera_sub_004B4D90};
const LiftFunction kIfstreamFunctions[] = {&sfera_sub_004B5780};
const LiftFunction kStringbufFunctions[] = {
    &sfera_sub_004B9070, &sfera_sub_004EF668, &sfera_sub_004EF66E, &sfera_sub_004B8D40, &sfera_sub_004B8F00,
    &sfera_sub_004EF656, &sfera_sub_004B8B10, &sfera_sub_004EF674, &sfera_sub_004EF65C, &sfera_sub_004EF662,
    &sfera_sub_004B8B80, &sfera_sub_004B8F50, &sfera_sub_004EF67A, &sfera_sub_004EF680, &sfera_sub_004EF686
};
const LiftFunction kOstringstreamFunctions[] = {&sfera_sub_004B92A0};
const LiftFunction kBadAllocFunctions[] = {&sfera_sub_00401BB0, &sfera_sub_004EE924};
const LiftFunction kComErrorFunctions[] = {&sfera_sub_004EF740};

template <std::size_t N>
bool bindLegacyVtable(uint32_t (&slots)[N], const LiftFunction (&functions)[N]) {
    for (std::size_t slot = 0; slot < N; ++slot) {
        const uint32_t callback = lift_callback_address(functions[slot]);
        if (callback == 0u) {
            return false;
        }
        slots[slot] = callback;
    }
    return true;
}

}

int sfera_bind_legacy_cpp_vtables() {
    return bindLegacyVtable(g_sfera_msvcp100_vtable_basic_filebuf, kFilebufFunctions)
        && bindLegacyVtable(g_sfera_msvcp100_vtable_basic_ofstream, kOfstreamFunctions)
        && bindLegacyVtable(g_sfera_msvcp100_vtable_basic_ifstream, kIfstreamFunctions)
        && bindLegacyVtable(g_sfera_msvcp100_vtable_basic_stringbuf, kStringbufFunctions)
        && bindLegacyVtable(g_sfera_msvcp100_vtable_basic_ostringstream, kOstringstreamFunctions)
        && bindLegacyVtable(g_sfera_legacy_vtable_bad_alloc, kBadAllocFunctions)
        && bindLegacyVtable(g_sfera_legacy_vtable_com_error, kComErrorFunctions);
}
