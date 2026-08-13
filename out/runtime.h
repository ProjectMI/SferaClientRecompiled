#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace sfera::runtime {

class ProcessImage {
public:
    ProcessImage();
    ProcessImage(const ProcessImage&) = delete;
    ProcessImage& operator=(const ProcessImage&) = delete;
    ~ProcessImage();

    std::uint32_t load_base() const noexcept;
    std::uint32_t entry_va() const noexcept;
    std::uint32_t source_address(std::uint32_t source_va) const;
    std::uint8_t* data() noexcept;
    const std::uint8_t* data() const noexcept;
    void initialize();
    [[noreturn]] void execute_entrypoint();

private:
    std::uint8_t* image_{};
    std::vector<HMODULE> loaded_modules_;

    void reserve_image();
    void copy_image();
    void apply_relocations();
    void patch_image_base();
    void resolve_imports();
    void protect_image();
    void release() noexcept;
};

std::string win32_error(const char* operation, DWORD error = GetLastError());
const std::wstring& client_root_directory();
void configure_process_environment();
int run_native_program();

} // namespace sfera::runtime
