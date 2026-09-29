#include "script/MbcRuntime.h"
#include "binary/Binary.h"
#include "text/TextBuffer.h"

#include <algorithm>
#include <stdexcept>

static_assert(SferaMbcRuntime::mappedAddressBegin == SferaNativeMappings::addressBegin);

std::uint8_t *SferaMbcRuntime::memoryAt(std::uint32_t address, std::size_t size, SferaMbcProcessRecord *) const
{
    if (address < mappedAddressBegin)
    {
        const auto object = native_space->find(address);
        if (!object)
            throw std::out_of_range("Unknown native object address");
        const auto offset = address - object->address();
        if (native_call != nullptr)
        {
            native_call->scratch.synchronize();
            return native_call->scratch.view(object, offset, size).data();
        }
        const auto bytes = object->contiguous(offset, size);
        if (bytes.size() != size)
            throw std::logic_error("Heterogeneous host buffer requested outside a native call");
        return bytes.data();
    }
    auto entry = mapped_memory.upper_bound(address);
    if (entry == mapped_memory.begin())
        throw std::out_of_range("Unknown host memory address");
    --entry;
    const auto &region = entry->second;
    const std::size_t offset = address - entry->first;
    if (offset > region.size || size > region.size - offset)
        throw std::out_of_range("Host memory access outside mapped region");
    return const_cast<std::uint8_t *>(region.data) + offset;
}

std::span<std::uint8_t> SferaMbcRuntime::memoryRange(std::uint32_t address, SferaMbcProcessRecord *) const
{
    if (address < mappedAddressBegin)
    {
        const auto object = native_space->find(address);
        if (!object)
            throw std::out_of_range("Unknown native object address");
        const auto offset = address - object->address();
        const auto size = object->extent() - offset;
        if (native_call != nullptr)
        {
            native_call->scratch.synchronize();
            return native_call->scratch.view(object, offset, size);
        }
        const auto bytes = object->contiguous(offset, size);
        if (bytes.size() != size)
            throw std::logic_error("Heterogeneous host buffer requested outside a native call");
        return bytes;
    }
    auto entry = mapped_memory.upper_bound(address);
    if (entry == mapped_memory.begin())
        throw std::out_of_range("Unknown mapped memory range");
    --entry;
    const auto offset = address - entry->first;
    const auto size = entry->second.size;
    if (offset > size)
        throw std::out_of_range("Invalid mapped memory range");
    return {memoryAt(address, size - offset), size - offset};
}
std::span<std::uint8_t> SferaMbcRuntime::memoryBytes(std::uint32_t address, std::size_t count, SferaMbcProcessRecord *process) const
{
    if (count == 0)
        return {};
    return {memoryAt(address, count, process), count};
}

SferaTextBuffer SferaMbcRuntime::textBufferAt(std::uint32_t address, SferaMbcProcessRecord *process) const
{
    if (const auto object = native_space->find(address))
    {
        const auto bytes = object->contiguousRemainder(address - object->address());
        if (!bytes.empty())
            return SferaTextBuffer(memoryBytes(address, bytes.size(), process));
    }
    return SferaTextBuffer(memoryRange(address, process));
}

std::uint64_t SferaMbcRuntime::memoryLifetime(std::uint32_t address) const
{
    if (address < mappedAddressBegin)
        return 0;
    auto entry = mapped_memory.upper_bound(address);
    if (entry == mapped_memory.begin())
        throw std::out_of_range("Unknown mapped memory lifetime");
    --entry;
    if (address - entry->first >= entry->second.size)
        throw std::out_of_range("Invalid mapped memory lifetime");
    return entry->second.lifetime;
}
std::span<std::uint8_t> SferaMbcRuntime::sliceBytes(const SferaSliceReference32 &slice, SferaMbcProcessRecord *process) const
{
    auto bytes = memoryRange(slice.base, process);
    if (slice.begin != 0)
    {
        if (slice.base < slice.begin || slice.base > slice.end)
            throw std::out_of_range("Invalid bounded script slice");
        const std::uint64_t end = slice.end;
        const auto count = end - slice.base + 1;
        if (count < bytes.size())
            bytes = bytes.first(count);
    }
    return bytes;
}

std::span<std::uint8_t> SferaMbcRuntime::sliceBytes(const SferaSliceReference32 &slice, std::size_t count, SferaMbcProcessRecord *process) const
{
    if (count == 0)
        return {};
    return SferaBinary::range(sliceBytes(slice, process), 0, count);
}

SferaTextBuffer SferaMbcRuntime::textBuffer(const SferaSliceReference32 &slice, SferaMbcProcessRecord *process) const
{
    return SferaTextBuffer(sliceBytes(slice, process));
}

namespace
{
std::span<std::uint8_t> nativeTextRange(const SferaMbcRuntime &runtime, std::uint32_t address, SferaMbcProcessRecord *process)
{
    if (const auto object = runtime.native_space->find(address))
    {
        const auto bytes = object->contiguousRemainder(address - object->address());
        if (!bytes.empty())
            return runtime.memoryBytes(address, bytes.size(), process);
    }
    return runtime.memoryRange(address, process);
}
}

std::string SferaMbcRuntime::textIn(const SferaSliceReference32 &slice, SferaMbcProcessRecord *process) const
{
    // Preserve the MBC string ABI: the declared extent may exclude the NUL or
    // describe an addressed element. The owning memory region is the hard boundary.
    return SferaText::terminated(nativeTextRange(*this, slice.base, process));
}

std::string SferaMbcRuntime::textIn(const SferaSliceReference32 &slice, std::size_t limit, SferaMbcProcessRecord *process) const
{
    if (limit == 0)
        return {};
    return SferaText::prefix(nativeTextRange(*this, slice.base, process), limit);
}

std::string SferaMbcRuntime::textAt(std::uint32_t address) const
{
    return textIn({address, 0, 0});
}
std::string SferaMbcRuntime::textAt(std::uint32_t address, std::size_t limit) const
{
    return textIn({address, 0, 0}, limit);
}

std::uint32_t SferaMbcRuntime::addMemoryRegion(SferaMbcRuntimeMemoryRegion region)
{
    if (next_memory_lifetime == 0)
        throw std::overflow_error("Memory mapping lifetime exhausted");
    region.lifetime = next_memory_lifetime++;
    return mapped_memory.insert(region);
}

std::uint32_t SferaMbcRuntime::mapMemory(const void *data, std::size_t size, const void *owner)
{
    if (data == nullptr)
        return 0;
    if (native_call != nullptr)
        if (const auto address = native_call->scratch.findAddress(data, size))
            return address;
    if (const auto address = native_space->findAddress(data, size))
        return address;
    if (const auto address = mapped_memory.findAddress(data, size))
        return address;
    return addMemoryRegion({static_cast<const std::uint8_t *>(data), size, nullptr, owner});
}





void SferaMbcRuntime::forgetMemory(const void *owner)
{
    mapped_memory.forget(owner);
}
