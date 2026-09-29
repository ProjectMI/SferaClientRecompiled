#pragma once

#include <cstdint>
#include <initializer_list>
#include <span>
#include <string_view>
#include <vector>

#include "script/MbcValue.h"
#include "script/NativeTask.h"

// Valid only for a synchronous full-expression, exactly like std::span.
// Coroutine parameters retain the separate owning std::vector ABI.
class SferaNativeArguments
{
public:
    SferaNativeArguments(std::initializer_list<SferaMbcValue> values) : values_(values.begin(), values.size()) {}
    operator std::span<const SferaMbcValue>() const noexcept { return values_; }
private:
    std::span<const SferaMbcValue> values_;
};

struct SferaNativeContext;
using SferaNativeTask = SferaCoroutine<SferaMbcValue>;
using SferaNativeFunction = SferaMbcValue (*)(SferaNativeContext, std::span<const SferaMbcValue>);
using SferaNativeProgram = SferaNativeTask (*)(SferaNativeContext, std::vector<SferaMbcValue>);

// Only externally selected entries need a callable value. Local C++ calls have
// no descriptor, constant pool, callee array, or catalogue index.
struct SferaNativeCallable
{
private:
    union Pointer
    {
        SferaNativeFunction function;
        SferaNativeProgram coroutine;
        constexpr Pointer() noexcept : function(nullptr) {}
        constexpr Pointer(SferaNativeFunction value) noexcept : function(value) {}
        constexpr Pointer(SferaNativeProgram value) noexcept : coroutine(value) {}
    } pointer_;
    bool suspended_ = false;

public:
    // An unbound declaration has index zero. Selecting its module instance
    // copies the same callable and sets this index; no larger wrapper is needed.
    std::uint32_t binding_index = 0;
    constexpr SferaNativeCallable() noexcept = default;
    constexpr SferaNativeCallable(SferaNativeFunction value) noexcept : pointer_(value) {}
    constexpr SferaNativeCallable(SferaNativeProgram value) noexcept : pointer_(value), suspended_(true) {}
    constexpr SferaNativeCallable(const SferaNativeCallable &value, std::uint32_t binding) noexcept
        : pointer_(value.pointer_), suspended_(value.suspended_), binding_index(binding) {}
    constexpr SferaNativeFunction function() const noexcept { return suspended_ ? nullptr : pointer_.function; }
    constexpr SferaNativeProgram coroutine() const noexcept { return suspended_ ? pointer_.coroutine : nullptr; }
    constexpr bool valid() const noexcept { return suspended_ ? pointer_.coroutine != nullptr : pointer_.function != nullptr; }
    constexpr bool operator==(const SferaNativeCallable &other) const noexcept
    {
        return binding_index == other.binding_index && suspended_ == other.suspended_ &&
            (suspended_ ? pointer_.coroutine == other.pointer_.coroutine : pointer_.function == other.pointer_.function);
    }
};

using SferaNativeEntry = SferaNativeCallable;

enum class SferaAotStepResult
{
    Yield,
    EndProgram,
    BudgetExceeded,
    Failed
};

struct SferaNativeBudgetExceeded {};
struct SferaNativeExecutionFailed {};
