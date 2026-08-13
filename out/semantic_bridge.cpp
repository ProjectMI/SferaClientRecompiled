#include "semantic_bridge.h"

#include "diagnostics.h"
#include "native_image.h"
#include "semantic_native.h"

#include <cstring>
#include <string>
#include <string_view>

namespace sfera::bridge {
namespace {

template <typename T>
T* image_pointer(std::uint32_t image_base, std::uint32_t source_va) noexcept {
    return reinterpret_cast<T*>(static_cast<std::uintptr_t>(image_base + (source_va - sfera::image::kSourceImageBase)));
}

void semantic_diagnostic(std::string_view message) {
    const std::string terminated(message);
    runtime::diagnostic_note(terminated.c_str());
}

void* semantic_copy(void* destination, const void* source, std::uint32_t size) {
    return std::memcpy(destination, source, size);
}

} // namespace

void attach_semantic_runtime(std::uint32_t image_base) noexcept {
    semantic::ConfigurationStorage configuration{
        image_pointer<char*>(image_base, UINT32_C(0x00916E40)),
        image_pointer<std::uint32_t>(image_base, UINT32_C(0x048F5A98)),
        image_pointer<char>(image_base, UINT32_C(0x006BEC00)),
        static_cast<std::size_t>(UINT32_C(0x00258240))
    };
    semantic::attach_runtime({configuration, &semantic_diagnostic, &semantic_copy});
}

} // namespace sfera::bridge
