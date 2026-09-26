#pragma once

#include <cstddef>
#include <cstdint>
#include <span>
#include <variant>

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

struct SferaMbcValue;
struct SferaSliceReference32;

struct SferaSliceReference32
{
    // Byte offsets in script memory; end is inclusive and begin == 0 means unbounded.
    std::uint32_t base;
    std::uint32_t begin;
    std::uint32_t end;
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
    SferaMbcValueType type;
    std::size_t width;
    SferaSliceReference32 source;
    SferaSliceReference32 value;
    bool isPointer() const;
    static std::size_t storageSize(SferaMbcValueType valueType);
    std::size_t elementSize() const;
    std::int32_t integer() const;
    std::uint32_t word() const noexcept
    {
        return value.base;
    }
    float real() const;
    std::int32_t asInteger() const;
    std::uint32_t asWord() const;
    float asReal() const;
    void setReal(float number);
    void setReal(double number);
    void detach();
    SferaSliceReference32 &asSlice();
    void storeAs(SferaMbcValueType destinationType, std::span<std::uint8_t> destination) const;
    static std::int32_t truncate(double number);
    static std::int64_t truncateReal(double number);
};

// Script VM, transport and application contracts.
