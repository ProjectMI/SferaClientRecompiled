#pragma once

#include <cstdint>
#include <memory>
#include <span>

#include "script/NativeModule.h"

struct SferaNativeBinding;
struct SferaMbcRuntime;

// Passed by value into coroutine frames. Neither module activation nor process
// table growth can invalidate this native execution context.
struct SferaNativeContext
{
    SferaMbcRuntime *runtime;
    std::shared_ptr<SferaNativeModuleState> globals;
    std::string_view function_name;
    std::uint32_t program_base;
    std::uint32_t binding_index;
    std::uint32_t process_id;
    std::uint64_t process_lifetime;

    SferaNativeContext(SferaMbcRuntime &runtime, const SferaNativeBinding &binding, std::string_view function = {});
    SferaNativeContext(const SferaNativeContext &) noexcept;
    SferaNativeContext(SferaNativeContext &&) noexcept;
    SferaNativeContext &operator=(const SferaNativeContext &) noexcept;
    SferaNativeContext &operator=(SferaNativeContext &&) noexcept;
    ~SferaNativeContext() noexcept;
    void enter(std::string_view name) noexcept { function_name = name; }
    void checkpoint(std::uint32_t ordinal, std::uint32_t cost = 1) const;
    void charge(std::uint32_t cost) const;
    std::uint32_t word(std::uint32_t access) const;
    std::uint32_t signedByte(std::uint32_t access) const;
    void setWord(std::uint32_t access, std::uint32_t word, std::uint32_t width = 4) const;
    SferaMbcValue global(SferaMbcValueType type, std::uint32_t access) const;
    SferaMbcValue span(SferaMbcValueType type, std::uint32_t access, std::uint32_t length, bool lvalue) const;
    void store(SferaMbcValue &left, const SferaMbcValue &right) const;
    void dereference(SferaMbcValue &value) const;
    void indexAbsolute(SferaMbcValue &index, SferaMbcValueType type, std::uint32_t access, std::uint16_t stride,
                       std::int32_t count, std::uint32_t span) const;
    void indexRelative(SferaMbcValue &index, const SferaMbcValue &source, SferaMbcValueType type, std::uint16_t stride,
                       std::int32_t count, bool checked) const;
    void member(SferaMbcValue &value, SferaMbcValueType type, std::uint32_t displacement, std::uint32_t width, bool span) const;
    void change(SferaMbcValue &value, bool increment, bool prefix) const;
    void changePointer(SferaMbcValue &value, std::uint16_t stride, bool increment, bool prefix) const;
    void validateParameters(std::span<const SferaMbcValue> arguments, int declaration) const;
    void parameter(std::span<const SferaMbcValue> arguments, std::size_t index, SferaMbcValueType type, std::uint32_t access) const;
    SferaNativeEntry exportEntry(std::uint32_t symbol, std::span<const std::uint64_t> providers, SferaNativeCallable knownCallable = {}) const;
    SferaNativeContext exportContext(SferaNativeEntry entry) const;
    void restartProgram(std::uint32_t index, bool child) const;
    void activateProgram(std::uint32_t index) const;
    void pauseProgram(std::uint32_t index) const;
    void stopEntry(std::uint32_t index) const;
    [[noreturn]] void fail(const char *message) const;
};
