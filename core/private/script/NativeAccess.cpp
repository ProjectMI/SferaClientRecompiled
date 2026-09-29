#include "diagnostics/ClientDiagnostics.h"

#include "script/MbcRuntime.h"

SferaSliceReference32 SferaMbcRuntime::ownReference(SferaSliceReference32 value) const
{
    if (!value.owner && value.base < mappedAddressBegin)
        value.owner = native_space->find(value.base);
    return value;
}

void SferaMbcRuntime::readValue(SferaMbcValue &slot, SferaMbcValueType type, const SferaSliceReference32 &reference, bool load, bool readAddress)
{
    const auto source = ownReference(reference);
    if (source.owner && load && (type != SferaMbcValueTypeAddress || readAddress))
    {
        if (native_call != nullptr)
            native_call->scratch.synchronize();
        slot = source.owner->load(source.base - source.owner->address(), type, readAddress);
        slot.source = source;
        return;
    }
    SferaNativeValues::initializeReference(slot, type, source, load);
    if (load && (type != SferaMbcValueTypeAddress || readAddress))
    {
        SferaNativeValues::readReference(slot, memoryBytes(source.base, SferaNativeValues::referenceWidth(type)));
        if (slot.isPointer())
            slot.value = ownReference(slot.value);
    }
}

void SferaMbcRuntime::storeValue(SferaMbcValue &left, const SferaMbcValue &right)
{
    if (!left.source.contains(static_cast<std::uint32_t>(left.width)))
        left.source.diagnoseRange(static_cast<std::uint32_t>(left.width));
    const auto source = ownReference(left.source);
    // Retain the payload before changing the destination; left and right can
    // denote the same value during parameter initialization.
    const auto payload = right;
    const auto storedWidth = SferaNativeValues::prepareAssignment(left, payload);
    if (source.owner)
    {
        if (native_call != nullptr)
            native_call->scratch.synchronize();
        source.owner->store(source.base - source.owner->address(), payload, left.type, storedWidth);
        if (source.owner->kindAt(source.base - source.owner->address()) == SferaNativeFieldKind::CommandArguments)
            left.value = source.owner->load(source.base - source.owner->address(), left.type).value;
        else if (!left.isPointer())
            left.value.owner.reset();
        if (native_call != nullptr)
            native_call->scratch.synchronize();
    }
    else if (storedWidth == 1)
        writeMemory(source.base, static_cast<std::uint8_t>(left.value.base));
    else if (storedWidth == 4)
        writeMemory(source.base, left.value.base);
    else
        writeMemory(source.base, ownReference(left.value));
}

void SferaMbcRuntime::dereferenceValue(SferaMbcValue &slot)
{
    const auto reference = slot.value;
    if (!reference.contains(1, true))
    {
        auto invalid = reference;
        invalid.diagnoseRange(0);
    }
    const auto type = SferaNumeric::enumFromBits<SferaMbcValueType>(SferaNumeric::lowByte(SferaNumeric::enumBits(slot.type) - 1u));
    readValue(slot, type, reference, true, true);
}

void SferaMbcRuntime::advanceReference(SferaSliceReference32 &source, std::uint32_t displacement)
{
    source.base += displacement;
    if (source.begin != 0 && (source.base < source.begin || source.base > source.end))
    {
        source.diagnoseRange(0);
    }
}

void SferaMbcRuntime::changeValue(SferaMbcValue &slot, bool increment, bool prefix)
{
    if (slot.type == SferaMbcValueTypeInteger || slot.type == SferaMbcValueTypeByte)
    {
        const auto value = slot.value.base + (increment ? 1 : UINT32_MAX);
        if (slot.width == 1)
        {
            writeMemory(slot.source.base, SferaNumeric::lowByte(value));
        }
        else
        {
            writeMemory(slot.source.base, value);
        }
        if (prefix)
        {
            slot.value.base = value;
        }
    }
    else
    {
        const double current = slot.real();
        const float value = SferaNumeric::real32(current + (increment ? 1.0 : -1.0));
        if (!increment && !prefix)
        {
            // Preserve the established floating postfix result and second decrement.
            slot.setReal(value);
            writeReal(slot.source.base, value - 1.0);
        }
        else
        {
            writeMemory(slot.source.base, value);
            if (prefix)
            {
                slot.setReal(value);
            }
        }
    }
}

void SferaMbcRuntime::changePointer(SferaMbcValue &slot, std::uint16_t stride, bool increment, bool prefix)
{
    auto replacement = slot.value;
    replacement.base = increment ? replacement.base + stride : replacement.base - stride;
    writeMemory(slot.source.base, replacement);
    if (prefix)
        slot.value = replacement;
}


SferaSliceReference32 SferaMbcRuntime::indexedReference(std::uint16_t stride, std::int32_t index, std::int32_t signedCount, std::uint32_t address, std::uint32_t width,
                                                       SferaSliceReference32 *source)
{
    const auto count = signedCount < 0 ? 0u - SferaNumeric::word(signedCount) : SferaNumeric::word(signedCount);
    if (index < 0 || std::cmp_greater_equal(index, count))
    {
        WorldDiagnostics::describeScript(true);
        auto message = diagnostic_context + "\n" + (source ? "Array2" : "Array") + " boundary error: array size = " +
            std::to_string(count) + ", index = " + std::to_string(index);
        WorldDiagnostics::warning(message);
        const auto last = SferaNumeric::signedWord(count - 1u);
        if (source)
        {
            index = index >= 0 && last < 0 ? 0 : last;
        }
        else
        {
            index = index < 0 ? 0 : last;
        }
    }
    const auto displacement = SferaNumeric::word(stride) * SferaNumeric::word(index);
    if (source)
    {
        source->base += displacement;
        return *source;
    }
    const auto element = address + displacement;
    return {element, element, element + width - 1u};
}

void SferaSliceReference32::diagnoseRange(std::uint32_t length)
{
    WorldDiagnostics::describeScript(true);
    std::string message = g_sfera_mbc_runtime.diagnostic_context + "\n Slice out of range! ptr = " + std::to_string(SferaNumeric::signedWord(base));
    if (length != 0)
        message += ", ptr+offset = " + std::to_string(SferaNumeric::signedWord(base + length));
    message += ", begin = " + std::to_string(SferaNumeric::signedWord(begin)) + ", end = " + std::to_string(SferaNumeric::signedWord(end + 1));
    WorldDiagnostics::warning(message);
    // The interpreter diagnoses and extends the recorded bounds; it does not clamp the pointer.
    if (base == 0 || begin == 0 || (base >= begin && base <= end))
        return;
    if (SferaNumeric::signedWord(base) < SferaNumeric::signedWord(begin))
        begin = base;
    else if (SferaNumeric::signedWord(base + length - 1) > SferaNumeric::signedWord(end))
        end = base + length - 1;
}
