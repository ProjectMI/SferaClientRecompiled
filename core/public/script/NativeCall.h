#pragma once

#include <array>
#include <cstddef>
#include <span>
#include <vector>

#include "script/NativeStorage.h"

struct SferaMbcRuntime;

// One ordinary C++ host invocation owns its arguments and result. No expression
// values or return addresses are stored in the runtime's argument interface.
struct SferaNativeCall
{
    std::span<SferaMbcValue> arguments;
    std::size_t cursor = 0;
    int count = 0;
    SferaMbcValue result{};
    SferaNativeScratch scratch;
};

class SferaNativeCallScope
{
public:
    SferaNativeCallScope(SferaMbcRuntime &runtime, std::span<const SferaMbcValue> arguments);
    ~SferaNativeCallScope();
    SferaNativeCallScope(const SferaNativeCallScope &) = delete;
    SferaNativeCallScope &operator=(const SferaNativeCallScope &) = delete;
    SferaMbcValue finish();

private:
    SferaMbcRuntime &runtime_;
    static constexpr std::size_t inlineCount = 12;
    alignas(SferaMbcValue) std::byte inline_arguments_[sizeof(SferaMbcValue) * inlineCount];
    std::vector<SferaMbcValue> overflow_arguments_;
    SferaNativeCall call_;
    SferaNativeCall *previous_;
    bool finished_ = false;
};
