#include "script/NativeCall.h"
#include "script/MbcRuntime.h"

#include <limits>
#include <memory>
#include <stdexcept>

SferaNativeCallScope::SferaNativeCallScope(SferaMbcRuntime &runtime, std::span<const SferaMbcValue> arguments)
    : runtime_(runtime), previous_(runtime.native_call)
{
    if (arguments.size() > static_cast<std::size_t>(std::numeric_limits<int>::max()))
        throw std::length_error("Too many native host arguments");
    if (arguments.size() <= inlineCount)
    {
        auto *values = reinterpret_cast<SferaMbcValue *>(inline_arguments_);
        std::uninitialized_copy(arguments.begin(), arguments.end(), values);
        call_.arguments = {values, arguments.size()};
    }
    else
    {
        overflow_arguments_.assign(arguments.begin(), arguments.end());
        call_.arguments = overflow_arguments_;
    }
    call_.count = static_cast<int>(arguments.size());
    runtime_.native_call = &call_;
}

SferaNativeCallScope::~SferaNativeCallScope()
{
    if (!finished_)
    {
        try { call_.scratch.flush(); }
        catch (...) { runtime_.execution_failed = true; }
    }
    runtime_.native_call = previous_;
    if (call_.arguments.size() <= inlineCount)
        std::destroy(call_.arguments.begin(), call_.arguments.end());
}

SferaMbcValue SferaNativeCallScope::finish()
{
    call_.scratch.flush();
    finished_ = true;
    return call_.result;
}

std::int32_t SferaMbcRuntime::nextInteger()
{
    if (native_call->cursor >= native_call->arguments.size())
    {
        reportError("Too few parameters");
        return 0;
    }
    return native_call->arguments[native_call->cursor++].asInteger();
}
std::uint32_t SferaMbcRuntime::nextWord()
{
    if (native_call->cursor >= native_call->arguments.size())
    {
        reportError("Too few parameters");
        return 0u;
    }
    return native_call->arguments[native_call->cursor++].asWord();
}
float SferaMbcRuntime::nextReal()
{
    if (native_call->cursor >= native_call->arguments.size())
    {
        reportError("Too few parameters");
        return 0;
    }
    return native_call->arguments[native_call->cursor++].asReal();
}
SferaSliceReference32 &SferaMbcRuntime::nextSliceReference(std::string_view diagnostic)
{
    if (native_call->cursor >= native_call->arguments.size())
    {
        reportError(diagnostic);
        g_sfera_mbc_runtime.sliceup_fallback = {};
        return g_sfera_mbc_runtime.sliceup_fallback;
    }
    return native_call->arguments[native_call->cursor++].asSlice();
}
SferaSliceReference32 SferaMbcRuntime::nextSlice()
{
    return nextSliceReference("popsliceup(): stack underflow");
}
SferaSliceReference32 SferaMbcRuntime::nextAddress()
{
    if (native_call->cursor >= native_call->arguments.size())
    {
        reportError("Too few parameters");
        return {};
    }
    const auto &argument = native_call->arguments[native_call->cursor++];
    if (argument.isPointer())
        return argument.value;
    return ownReference({argument.asWord(), 0, 0, argument.value.owner});
}
void SferaMbcRuntime::pushInteger(std::uint32_t number)
{
    if (native_call == nullptr)
        throw std::logic_error("Native host result outside a call");
    SferaNativeValues::literal(native_call->result, SferaMbcValueTypeInteger, number);
}
void SferaMbcRuntime::pushReal(float number)
{
    if (native_call == nullptr)
        throw std::logic_error("Native host result outside a call");
    SferaNativeValues::literal(native_call->result, SferaMbcValueTypeReal, 0);
    native_call->result.setReal(number);
}
void SferaMbcRuntime::pushReal(double number)
{
    pushReal(SferaNumeric::real32(number));
}
void SferaMbcRuntime::pushSlice(const SferaSliceReference32 &value, SferaMbcValueType type)
{
    if (native_call == nullptr)
        throw std::logic_error("Native host result outside a call");
    auto &slot = native_call->result;
    slot.type = type;
    slot.width = SferaSliceReference32::scriptWidth;
    slot.value = ownReference(value);
    slot.detach();
}




