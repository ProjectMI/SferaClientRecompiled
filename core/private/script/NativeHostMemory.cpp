#include "script/MbcRuntime.h"
#include "binary/Binary.h"
#include "diagnostics/ClientDiagnostics.h"
#include "text/TextBuffer.h"

#include <algorithm>
#include <cstring>
#include <string>
#include <stdexcept>

void SferaMbcRuntime::scriptCopyMemory(bool fill)
{
    auto &destination = nextSliceReference();
    const auto source = fill ? SferaSliceReference32{nextWord(), 0, 0} : nextSliceReference();
    const std::uint32_t count = nextInteger();
    if (execution_failed)
    {
        return;
    }
    if (count != 0 && !destination.contains(count))
    {
        destination.diagnoseRange(count);
    }
    if (!fill && count != 0)
    {
        const auto outputOwner = native_space->find(destination.base);
        const auto inputOwner = native_space->find(source.base);
        if (outputOwner && inputOwner)
        {
            native_call->scratch.flush();
            if (outputOwner->copyTyped(destination.base - outputOwner->address(), *inputOwner, source.base - inputOwner->address(), count))
            {
                native_call->scratch.synchronize();
                return;
            }
        }
    }
    const auto output = memoryBytes(destination.base, count);
    if (fill)
    {
        std::fill(output.begin(), output.end(), SferaNumeric::lowByte(source.base));
    }
    else
    {
        SferaBinary::copy(output, memoryBytes(source.base, count));
    }
}

void SferaMbcRuntime::scriptRebaseSlice()
{
    const bool store = native_call->count == 1;
    const auto process = store ? native_caller_process : nextWord();
    auto reference = ownReference(nextSlice());
    if (execution_failed)
        return;
    if (!store && findProcess(process) == nullptr)
    {
        active_tag = UINT32_MAX;
        pushSlice({}, SferaMbcValueTypeBytePointer);
        return;
    }
    if (store)
    {
        const auto &argument = native_call->arguments[native_call->cursor - 1u];
        writeMemory(argument.source.base, reference);
        pushInteger(0);
    }
    else
        pushSlice(reference, SferaMbcValueTypeBytePointer);
}

void SferaMbcRuntime::scriptRealValue()
{
    const double value = nextReal();
    pushReal(value);
}

void SferaMbcRuntime::scriptStringLength()
{
    const auto slice = nextSliceReference();
    if (slice.base == 0)
    {
        WorldDiagnostics::warning("ffstrlen(): NULL-pointer dereferencing\n");
    }
    std::uint32_t length = 0;
    if (native_call->count > 1)
    {
        const auto limit = nextInteger();
        if (limit > 0)
        {
            length = SferaNumeric::lowWord(SferaText::length(memoryRange(slice.base), limit));
        }
        if (SferaNumeric::signedWord(length) == limit)
        {
            WorldDiagnostics::warning("ffstrlen(): end of string was not found in buffer of size " + std::to_string(limit) + "\n");
        }
    }
    else
    {
        length = SferaNumeric::lowWord(SferaText::length(memoryRange(slice.base)));
    }
    pushInteger(length);
}

void SferaMbcRuntime::scriptWriteScalar(std::uint32_t width, bool real)
{
    auto destination = nextSliceReference();
    const auto value = real ? SferaBinary::floatBits(nextReal()) : nextWord();
    if (execution_failed)
    {
        return;
    }
    if (!destination.contains(width))
    {
        destination.diagnoseRange(width);
    }
    else
    {
        std::memcpy(sliceBytes(destination, width).data(), &value, width);
        destination.base += width;
    }
    pushSlice(destination, SferaMbcValueTypeBytePointer);
}

void SferaMbcRuntime::scriptReadScalar(std::uint32_t width, bool real)
{
    auto source = nextSliceReference();
    auto &destination = nextSliceReference();
    if (execution_failed)
    {
        return;
    }
    if (!source.contains(width))
    {
        source.diagnoseRange(width);
        if (real)
        {
            return;
        }
    }
    else if (!destination.contains(width))
    {
        destination.diagnoseRange(width);
        if (real)
        {
            return;
        }
    }
    else
    {
        const auto input = sliceBytes(source, width);
        const auto outputWidth = width == 2u || width == 3u ? sizeof(std::uint32_t) : width;
        const auto output = memoryBytes(destination.base, outputWidth);
        // Stage the word before clearing a potentially overlapping destination.
        std::uint32_t value = 0;
        std::memcpy(&value, input.data(), width);
        std::memcpy(output.data(), &value, outputWidth);
        source.base += width;
    }
    pushSlice(source, SferaMbcValueTypeBytePointer);
}

void SferaMbcRuntime::scriptCopyString(bool bounded, bool append)
{
    auto &destination = nextSliceReference();
    auto &source = nextSliceReference();
    const auto count = bounded ? nextInteger() : 0;
    if (!source.contains())
    {
        source.diagnoseRange(0);
        if (!native_call->arguments.empty()) native_call->result = native_call->arguments.front();
        return;
    }
    if (count < 0)
    {
        reportError("Negative string length");
        return;
    }
    const auto input = bounded ? textIn(source, count) : textIn(source);
    auto output = textBuffer(destination);
    std::uint32_t length = 0;
    if (append)
    {
        if (!destination.contains())
        {
            destination.diagnoseRange(0);
            return;
        }
        const auto prefix = output.length();
        const auto required = prefix + input.size() + 1;
        if (required > UINT32_MAX || required > output.size())
        {
            destination.diagnoseRange(SferaNumeric::lowWord(std::min<std::size_t>(required, UINT32_MAX)));
            return;
        }
        length = SferaNumeric::lowWord(required);
        if (native_call->count > 2 && SferaNumeric::signedWord(length) > nextInteger())
        {
            WorldDiagnostics::warning("Size mismatch: ffstrcat\n");
            if (!native_call->arguments.empty()) native_call->result = native_call->arguments.front();
            return;
        }
        if (execution_failed)
        {
            return;
        }
        output.append(input);
    }
    else
    {
        const auto capacity = (!bounded && !append) && native_call->count == 3 ? nextInteger() : 0;
        if (execution_failed)
        {
            return;
        }
        if ((!bounded && !append))
        {
            length = copyString(output, input, capacity);
        }
        else
        {
            const std::size_t required = count + 1u;
            if (required > output.size())
            {
                destination.diagnoseRange(SferaNumeric::lowWord(required));
                return;
            }
            const auto copied = output.writePadded(input, count);
            length = SferaNumeric::lowWord(copied + 1);
        }
        if (!destination.contains(length))
        {
            destination.diagnoseRange(length);
        }
    }
    if (!native_call->arguments.empty()) native_call->result = native_call->arguments.front();
}

std::uint32_t SferaMbcRuntime::copyString(SferaTextBuffer destination, std::string_view source, int capacity)
{
    const auto limit = capacity > 0 ? std::min<std::size_t>(capacity, destination.size()) : destination.size();
    if (limit == 0)
        throw std::out_of_range("Empty script string destination");
    if (capacity <= 0 && source.size() >= limit)
        throw std::out_of_range("Script string destination is too small");
    if (source.size() >= limit)
    {
        g_sfera_mbc_runtime.diagnostic_context = "MBINTER MESSAGE: Wrong string to copy: '" + std::string(source) + "', strlen: " + std::to_string(source.size()) + "\n";
        g_sfera_log_runtime.write(g_sfera_mbc_runtime.diagnostic_context);
    }
    const auto copied = destination.limited(limit).write(source);
    return SferaNumeric::lowWord(copied + 1);
}

void SferaMbcRuntime::scriptCompareStrings(bool insensitive, bool requiredCount, bool normalize)
{
    const auto first = nextAddress();
    const auto second = nextAddress();
    const bool optionalInsensitiveCount = insensitive && !requiredCount && native_call->count >= 3;
    const bool bounded = optionalInsensitiveCount || requiredCount;
    const auto count = bounded ? nextWord() : 0u;
    if (execution_failed)
    {
        return;
    }
    // The music manager initially compares its selected track with a null
    // previous track. Preserve the old empty-string sentinel at this API only;
    // raw memory access through address zero is still invalid.
    const auto read = [&](const SferaSliceReference32 &value)
    {
        return value.base == 0 ? std::string{} : bounded ? textIn(value, count) : textIn(value);
    };
    const auto left = read(first);
    const auto right = read(second);
    int result = insensitive ? SferaText::compareInsensitive(left, right) : SferaText::compare(left, right);
    if (normalize)
    {
        result = (result > 0) - (result < 0);
    }
    pushInteger(result);
}
