# Sfera frozen semantic model

## State

The processor-oriented execution layer has been removed from the project. The model now has three independent pieces:

- `semantic_native.h/.cpp` contains the recovered C++ domain model, STL-backed containers, verified semantic routines and the ABI catalogue.
- `semantic_bridge.h/.cpp` only attaches shared mapped-image storage and diagnostics to the semantic layer. It does not decode registers, simulate calls or dispatch functions.
- `runtime.h/.cpp` maps the original PE image into the current Win32 process, prefers the original `0x00400000` base, parses and applies the PE `.reloc` directory directly when rebasing is required, resolves the IAT, applies section protections and transfers control to the native x86 entry point. The former recovered-data and jump-table overlays were removed after byte-for-byte verification showed that all 1,394 jump-table entries and all 32 recovered-data ranges already match the embedded PE payload.

This is the freeze boundary for the current reconstruction. Processor simulation is gone. Exact legacy execution remains available through the mapped native image for ABI-heavy object graphs that have not yet been replaced one entry point at a time by verified typed C++ routines.

## Semantic coverage

The semantic catalogue covers all 4,892 recovered functions. The last 1,201 functions were classified manually by original module, diagnostics, constants, data layout, control-flow families and call relationships. Their compiler-expanded container code was collapsed to STL rather than reproduced mechanically.

The newly closed areas include client startup/configuration, model and material management, nature/sky/snow, object parameters, particles, path zones and spatial indexing, quick files, server walls, shadows, HTML/simple parsers, sound effects/tracks/manager, texture sets, updater logic, and the complete UI control family.

The main semantic namespaces used for the remainder are:

- `container_runtime`: bounds policy plus `std::vector`/`std::deque` aliases for recovered array and stack families.
- `content_runtime`: connection arguments, materials, model paths, object configuration, quick files, walls, spatial data and texture sets.
- `particle_runtime`: particle definitions, curves, emission and simulation.
- `markup_runtime`: HTML-like document tree and simple key/value parser.
- `environment_runtime`: sky timeline and snow field.
- `media_runtime`: sound-effect catalogue, tracks, playlists and mixer settings.
- `client_runtime`: network availability and client update state.
- `ui_runtime`: controls, lists, ranges, sprites, fonts, hypertext, slots, options, help index and interface state.

Existing namespaces remain responsible for scripting/STL values, networking, assets, characters, effects, rendering, services, world state, audio, shared runtime, compiler helpers, zlib 1.1.3 and DirectX helper behaviour.

## ABI status

Calling-convention hints exist for all 4,892 original entry addresses. Ninety-eight entry points have exact typed semantic ABI bindings and are covered by the semantic test suite. The previous stack-cleanup and return-value defects are represented in those verified signatures, including the destination return from the cross-product routine.

The native image runtime does not depend on this table for execution. The table is retained as a verification catalogue and as the migration surface for later replacing native entry points with exact C++ implementations.

## Verification

`semantic_native.cpp` and `semantic_native_tests.cpp` compile in portable C++20 mode with `-Wall -Wextra -Wpedantic -Werror`, and the semantic subsystem test suite passes. The embedded PE payload is byte-identical to `sphereclient_patched.exe` (2,060,192 bytes, SHA-256 `69d3f90cad4c79b32305af71e0a0bef9526a62e9b6db40c1301ea25c886bf5f3`). The generated Visual Studio project contains only C++ runtime/model sources and the embedded native-image descriptor; no processor-generated C shards, CPU state structure or dispatcher is part of the build.

See `semantic_model_report.json` for the per-address catalogue and the module mapping used for the final 1,201 functions.
