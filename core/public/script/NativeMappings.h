#pragma once

#include <cstddef>
#include <cstdint>
#include <map>
#include <memory>
#include "script/MbcValue.h"

// Host/container buffers keep the engine's 32-bit handle ABI. Physical ranges,
// virtual reservations and owners have independent indexes; no process image
// or relocation table participates in these mappings.
class SferaNativeMappings
{
public:
    using Regions = std::map<std::uint32_t, SferaMbcRuntimeMemoryRegion>;
    using const_iterator = Regions::const_iterator;
    static constexpr std::uint32_t addressBegin = 0x80000000u;

    SferaNativeMappings();
    ~SferaNativeMappings();
    SferaNativeMappings(const SferaNativeMappings &) = delete;
    SferaNativeMappings &operator=(const SferaNativeMappings &) = delete;
    std::uint32_t insert(SferaMbcRuntimeMemoryRegion region);
    std::uint32_t findAddress(const void *data, std::size_t size) const;
    void forget(const void *owner) noexcept;
    void forget(const void *owner, const void *data);
    void forget(const void *owner, const void *begin, const void *end);
    void clear();
    bool empty() const noexcept;
    std::size_t size() const noexcept;
    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;
    const_iterator upper_bound(std::uint32_t address) const;

private:
    struct State;
    std::unique_ptr<State> state_;
};
