#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <functional>
#include <memory>
#include <span>
#include <variant>

#include "numeric/Numeric.h"

struct SferaActiveEffect;
struct SferaMbcProcessRecord;
struct SferaMbcRuntimeMemoryRegion;
struct SferaScriptContainer;
class SphereUIWindow;

struct SferaMbcRuntimeMemoryRegion
{
    const std::uint8_t *data;
    std::size_t size;
    SferaMbcProcessRecord *process;
    const void *owner;
    std::uint64_t lifetime = 0;
    const void *address() const noexcept
    {
        return data;
    }
};
using SferaMbcRuntimeNativeResource = std::variant<SphereUIWindow *, SferaActiveEffect *, SferaScriptContainer *, std::intptr_t>;

class SferaNativeObject;
struct SferaMbcValue;
struct SferaSliceReference32;

struct SferaSliceReference32
{
    // The native owner survives calls, process changes and suspension.
    // The three words are bounds/host-ABI coordinates, never a serialized owner.
    static constexpr std::size_t scriptWidth = 12;
    std::uint32_t base;
    std::uint32_t begin;
    std::uint32_t end;
    std::shared_ptr<SferaNativeObject> owner{};
    bool contains(std::uint32_t length = 1, bool allowNull = false) const;
    void diagnoseRange(std::uint32_t length);
};

enum SferaMbcValueType : std::uint8_t
{
    SferaMbcValueTypeByte = 0,
    SferaMbcValueTypeBytePointer = 1,
    SferaMbcValueTypeInteger = 16,
    SferaMbcValueTypeIntegerPointer = 17,
    SferaMbcValueTypeReal = 32,
    SferaMbcValueTypeRealPointer = 33,
    SferaMbcValueTypeAddress = 48
};

struct SferaMbcValue
{
    // This is the dynamic ABI boundary, not the scalar representation used by
    // lowered expressions. Compile ownership operations once, outside callers.
    SferaMbcValue() noexcept;
    SferaMbcValue(SferaMbcValueType type, std::size_t width, SferaSliceReference32 source, SferaSliceReference32 value) noexcept;
    SferaMbcValue(const SferaMbcValue &) noexcept;
    SferaMbcValue(SferaMbcValue &&) noexcept;
    SferaMbcValue &operator=(const SferaMbcValue &) noexcept;
    SferaMbcValue &operator=(SferaMbcValue &&) noexcept;
    ~SferaMbcValue() noexcept;
    void reset() noexcept;

    SferaMbcValueType type;
    std::size_t width;
    SferaSliceReference32 source;
    SferaSliceReference32 value;
    bool isPointer() const
    {
        return type % 16 != 0;
    }
    static std::size_t storageSize(SferaMbcValueType valueType);
    std::size_t elementSize() const;
    std::int32_t integer() const
    {
        std::int32_t result{};
        std::memcpy(&result, &value.base, sizeof(result));
        return result;
    }
    std::uint32_t word() const noexcept
    {
        return value.base;
    }
    float real() const
    {
        float result{};
        std::memcpy(&result, &value.base, sizeof(result));
        return result;
    }
    std::int32_t asInteger() const;
    std::uint32_t asWord() const;
    float asReal() const;
    void setReal(float number)
    {
        value.owner.reset();
        std::memcpy(&value.base, &number, sizeof(number));
    }
    void setReal(double number)
    {
        setReal(SferaNumeric::real32(number));
    }
    void detach()
    {
        source = {UINT32_MAX, 1, 1};
    }
    SferaSliceReference32 &asSlice();
    static std::int32_t truncate(double number);
    static std::int64_t truncateReal(double number);
};

class SferaNativeValues
{
public:
    static void literal(SferaMbcValue &slot, SferaMbcValueType type, std::uint32_t word);
    static void slice(SferaMbcValue &slot, SferaMbcValueType type, std::uint32_t address, std::uint32_t length, bool reference);
    static std::uint32_t referenceWidth(SferaMbcValueType type);
    static void initializeReference(SferaMbcValue &slot, SferaMbcValueType type, const SferaSliceReference32 &reference, bool load);
    static void readReference(SferaMbcValue &slot, std::span<const std::uint8_t> bytes);
    static void loadVariable(SferaMbcValue &slot, SferaMbcValueType type, std::uint32_t address, std::span<const std::uint8_t> bytes);
    static std::uint32_t prepareAssignment(SferaMbcValue &left, const SferaMbcValue &right);
    static bool add(SferaMbcValue &left, const SferaMbcValue &right);
    static bool subtract(SferaMbcValue &left, const SferaMbcValue &right);
    static bool multiply(SferaMbcValue &left, const SferaMbcValue &right);
    static bool divide(SferaMbcValue &left, const SferaMbcValue &right);
    static bool remainder(SferaMbcValue &left, const SferaMbcValue &right);
    static void equal(SferaMbcValue &left, const SferaMbcValue &right);
    static void notEqual(SferaMbcValue &left, const SferaMbcValue &right);
    static void greater(SferaMbcValue &left, const SferaMbcValue &right);
    static void less(SferaMbcValue &left, const SferaMbcValue &right);
    static void greaterEqual(SferaMbcValue &left, const SferaMbcValue &right);
    static void lessEqual(SferaMbcValue &left, const SferaMbcValue &right);
    static void integerResult(SferaMbcValue &slot);
    static void integerPair(SferaMbcValue &left, SferaMbcValue &right);
    static void convert(SferaMbcValue &slot, bool toReal);
    static void negate(SferaMbcValue &slot, bool logical);
    static void addressOf(SferaMbcValue &slot);
    static void pointerOffset(SferaMbcValue &slot, std::uint32_t index, std::uint16_t stride, bool subtract);

private:
    static bool finishArithmetic(SferaMbcValue &left);

    template <class Operation> static bool applyArithmetic(SferaMbcValue &left, const SferaMbcValue &right);

    template <class Operation> static bool applyIntegerDivision(SferaMbcValue &left, const SferaMbcValue &right);

    template <class Predicate> static void applyComparison(SferaMbcValue &left, const SferaMbcValue &right);

};

// Script VM, transport and application contracts.
