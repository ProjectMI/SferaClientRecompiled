#include "script/MbcValue.h"

#include <array>
#include <cmath>
#include <stdexcept>
#include <utility>

SferaMbcValue::SferaMbcValue() noexcept : type{}, width{}, source{}, value{} {}
SferaMbcValue::SferaMbcValue(SferaMbcValueType declared, std::size_t size, SferaSliceReference32 location, SferaSliceReference32 payload) noexcept
    : type(declared), width(size), source(std::move(location)), value(std::move(payload)) {}
SferaMbcValue::SferaMbcValue(const SferaMbcValue &) noexcept = default;
SferaMbcValue::SferaMbcValue(SferaMbcValue &&) noexcept = default;
SferaMbcValue &SferaMbcValue::operator=(const SferaMbcValue &) noexcept = default;
SferaMbcValue &SferaMbcValue::operator=(SferaMbcValue &&) noexcept = default;
SferaMbcValue::~SferaMbcValue() noexcept = default;
void SferaMbcValue::reset() noexcept
{
    type = SferaMbcValueTypeByte;
    width = 0;
    source = {};
    value = {};
}

bool SferaNativeValues::finishArithmetic(SferaMbcValue &left)
{
    left.detach();
    left.value.owner.reset();
    return true;
}

template <class Operation> bool SferaNativeValues::applyArithmetic(SferaMbcValue &left, const SferaMbcValue &right)
{
    if (left.type == SferaMbcValueTypeInteger)
    {
        left.value.base = Operation{}(left.value.base, right.value.base);
    }
    else
    {
        const double first = left.real();
        const double second = right.real();
        left.setReal(Operation{}(first, second));
    }
    return finishArithmetic(left);
}

template <class Operation> bool SferaNativeValues::applyIntegerDivision(SferaMbcValue &left, const SferaMbcValue &right)
{
    const auto divisor = right.integer();
    if (divisor == 0)
    {
        return false;
    }
    const std::int64_t dividend = left.integer();
    left.value.base = static_cast<std::uint32_t>(Operation{}(dividend, divisor));
    return finishArithmetic(left);
}

template <class Predicate> void SferaNativeValues::applyComparison(SferaMbcValue &left, const SferaMbcValue &right)
{
    double first = left.integer();
    double second = right.integer();
    if (left.type == SferaMbcValueTypeReal)
    {
        first = left.real();
        second = right.real();
    }
    const bool result = Predicate{}(first, second);
    left.detach();
    left.type = SferaMbcValueTypeInteger;
    left.value = {static_cast<std::uint32_t>(result), 0, 0};
}

bool SferaNativeValues::add(SferaMbcValue &left, const SferaMbcValue &right)
{
    return applyArithmetic<std::plus<>>(left, right);
}

bool SferaNativeValues::subtract(SferaMbcValue &left, const SferaMbcValue &right)
{
    return applyArithmetic<std::minus<>>(left, right);
}

bool SferaNativeValues::multiply(SferaMbcValue &left, const SferaMbcValue &right)
{
    return applyArithmetic<std::multiplies<>>(left, right);
}

void SferaNativeValues::equal(SferaMbcValue &left, const SferaMbcValue &right)
{
    applyComparison<std::equal_to<>>(left, right);
}

void SferaNativeValues::notEqual(SferaMbcValue &left, const SferaMbcValue &right)
{
    applyComparison<std::not_equal_to<>>(left, right);
}

void SferaNativeValues::greater(SferaMbcValue &left, const SferaMbcValue &right)
{
    applyComparison<std::greater<>>(left, right);
}

void SferaNativeValues::less(SferaMbcValue &left, const SferaMbcValue &right)
{
    applyComparison<std::less<>>(left, right);
}

void SferaNativeValues::greaterEqual(SferaMbcValue &left, const SferaMbcValue &right)
{
    applyComparison<std::greater_equal<>>(left, right);
}

void SferaNativeValues::lessEqual(SferaMbcValue &left, const SferaMbcValue &right)
{
    applyComparison<std::less_equal<>>(left, right);
}

bool SferaSliceReference32::contains(std::uint32_t length, bool allowNull) const
{
    return (allowNull || (base >= 4 && base < UINT32_MAX - 3)) && (begin == 0 || (base >= begin && base <= end && (length == 0 || length - 1 <= end - base)));
}

std::int32_t SferaMbcValue::truncate(double number)
{
    constexpr double minimum = INT32_MIN;
    constexpr double maximumExclusive = double{INT32_MAX} + 1.0;
    if (!std::isfinite(number) || number < minimum || number >= maximumExclusive)
        return INT32_MIN;
    return SferaNumeric::truncateInt(number);
}

std::int32_t SferaMbcValue::asInteger() const
{
    switch (type)
    {
    case SferaMbcValueTypeByte:
    {
        const std::uint8_t byte = value.base & 0xffu;
        std::int8_t signedByte{};
        std::memcpy(&signedByte, &byte, sizeof(byte));
        return signedByte;
    }
    case SferaMbcValueTypeReal:
        return truncate(real());
    default:
        return integer();
    }
}

std::uint32_t SferaMbcValue::asWord() const
{
    const std::int32_t number = asInteger();
    std::uint32_t result{};
    std::memcpy(&result, &number, sizeof(result));
    return result;
}

float SferaMbcValue::asReal() const
{
    if (type == SferaMbcValueTypeReal)
        return real();
    const std::int32_t number = asInteger();
    return SferaNumeric::real32(number);
}

std::size_t SferaMbcValue::storageSize(SferaMbcValueType valueType)
{
    return valueType == SferaMbcValueTypeByte ? sizeof(std::int8_t) : valueType % SferaMbcValueTypeInteger == 0 ? sizeof(std::uint32_t) : SferaSliceReference32::scriptWidth;
}

std::size_t SferaMbcValue::elementSize() const
{
    return storageSize(SferaNumeric::enumFromBits<SferaMbcValueType>(SferaNumeric::lowByte(SferaNumeric::enumBits(type) - 1u)));
}

std::int64_t SferaMbcValue::truncateReal(double number)
{
    return SferaNumeric::truncateInt64(number);
}

bool SferaNativeValues::divide(SferaMbcValue &left, const SferaMbcValue &right)
{
    if (left.type == SferaMbcValueTypeInteger)
    {
        return applyIntegerDivision<std::divides<>>(left, right);
    }
    return applyArithmetic<std::divides<>>(left, right);
}

bool SferaNativeValues::remainder(SferaMbcValue &left, const SferaMbcValue &right)
{
    return applyIntegerDivision<std::modulus<>>(left, right);
}

void SferaNativeValues::literal(SferaMbcValue &slot, SferaMbcValueType type, std::uint32_t word)
{
    slot.type = type;
    slot.width = sizeof(word);
    slot.value = {word, 0, 0};
    slot.detach();
}

void SferaNativeValues::slice(SferaMbcValue &slot, SferaMbcValueType type, std::uint32_t address, std::uint32_t length, bool reference)
{
    slot.type = type;
    slot.width = SferaSliceReference32::scriptWidth;
    slot.value = {address, address, address + length - 1};
    if (reference)
    {
        slot.source = slot.value;
    }
    else
    {
        slot.detach();
    }
}

void SferaNativeValues::addressOf(SferaMbcValue &slot)
{
    slot.value = slot.source;
    slot.detach();
    slot.type = SferaNumeric::enumFromBits<SferaMbcValueType>(SferaNumeric::lowByte(SferaNumeric::enumBits(slot.type) + 1u));
    slot.width = SferaSliceReference32::scriptWidth;
}

void SferaNativeValues::integerResult(SferaMbcValue &slot)
{
    slot.type = SferaMbcValueTypeInteger;
    slot.detach();
}

void SferaNativeValues::convert(SferaMbcValue &slot, bool toReal)
{
    if (toReal)
    {
        slot.setReal(SferaNumeric::real32(slot.integer()));
        slot.type = SferaMbcValueTypeReal;
    }
    else
    {
        slot.value.base = SferaMbcValue::truncate(slot.real());
        slot.type = SferaMbcValueTypeInteger;
    }
    slot.value.owner.reset();
}

void SferaNativeValues::negate(SferaMbcValue &slot, bool logical)
{
    if (logical)
    {
        slot.value.base = slot.value.base == 0;
        slot.type = SferaMbcValueTypeInteger;
    }
    else if (slot.type == SferaMbcValueTypeInteger)
    {
        slot.value.base = 0u - slot.value.base;
    }
    else
    {
        slot.setReal(-slot.real());
    }
    slot.detach();
    slot.value.owner.reset();
}

void SferaNativeValues::pointerOffset(SferaMbcValue &slot, std::uint32_t index, std::uint16_t stride, bool subtract)
{
    if (!subtract)
    {
        slot.value.base += index * stride;
    }
    else
    {
        slot.value.base -= index * stride;
    }
    slot.detach();
}

void SferaNativeValues::integerPair(SferaMbcValue &left, SferaMbcValue &right)
{
    left.type = right.type = SferaMbcValueTypeInteger;
}

std::uint32_t SferaNativeValues::referenceWidth(SferaMbcValueType type)
{
    if (type == SferaMbcValueTypeByte)
    {
        return sizeof(std::int8_t);
    }
    if (type == SferaMbcValueTypeInteger || type == SferaMbcValueTypeReal)
    {
        return sizeof(std::uint32_t);
    }
    return SferaSliceReference32::scriptWidth;
}

void SferaNativeValues::readReference(SferaMbcValue &slot, std::span<const std::uint8_t> bytes)
{
    const auto width = referenceWidth(slot.type);
    if (bytes.size() < width)
    {
        throw std::out_of_range("Script reference source is too small");
    }
    slot.value = {};
    if (slot.type == SferaMbcValueTypeByte)
    {
        std::int8_t value;
        std::memcpy(&value, bytes.data(), sizeof(value));
        slot.value.base = value;
        slot.type = SferaMbcValueTypeInteger;
    }
    else if (slot.type == SferaMbcValueTypeInteger || slot.type == SferaMbcValueTypeReal)
    {
        std::uint32_t value;
        std::memcpy(&value, bytes.data(), sizeof(value));
        slot.value.base = value;
    }
    else
    {
        std::array<std::uint32_t, 3> words{};
        std::memcpy(words.data(), bytes.data(), SferaSliceReference32::scriptWidth);
        slot.value = {words[0], words[1], words[2]};
    }
    slot.width = width;
}

void SferaNativeValues::loadVariable(SferaMbcValue &slot, SferaMbcValueType type, std::uint32_t address, std::span<const std::uint8_t> bytes)
{
    const auto width = referenceWidth(type);
    initializeReference(slot, type, {address, address, address + width - 1u}, true);
    readReference(slot, bytes);
}

std::uint32_t SferaNativeValues::prepareAssignment(SferaMbcValue &left, const SferaMbcValue &right)
{
    if (left.width == 1)
    {
        left.value.base = SferaNumeric::lowByte(right.value.base);
        return sizeof(std::uint8_t);
    }
    if (!left.isPointer())
    {
        left.value.base = right.value.base;
        return sizeof(std::uint32_t);
    }
    left.value = right.value;
    return SferaSliceReference32::scriptWidth;
}

SferaSliceReference32 &SferaMbcValue::asSlice()
{
    if (!isPointer())
        value.begin = value.end = 0;
    return value;
}

void SferaNativeValues::initializeReference(SferaMbcValue &slot, SferaMbcValueType type, const SferaSliceReference32 &reference, bool load)
{
    const auto source = reference;
    slot.source = source;
    slot.type = type;
    if (!load || type == SferaMbcValueTypeAddress)
    {
        slot.value = source;
        slot.width = SferaSliceReference32::scriptWidth;
    }
}
