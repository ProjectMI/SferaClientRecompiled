#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

#include "numeric/Numeric.h"
#include "script/MbcRuntime.h"
#include "script/ScriptContainer.h"
#include "text/Text.h"

template <class C, bool Hashed>
template <class K>
bool SferaScriptContainerContent<C, Hashed>::keyMatches(const K &key, const typename C::value_type &value)
    requires Hashed
{
    return value.first == key;
}

template <class C, bool Hashed>
template <class K>
std::size_t SferaScriptContainerContent<C, Hashed>::bucketIndex(const K &key) const
    requires Hashed
{
    std::uint32_t hash;
    if constexpr (std::is_integral_v<K>)
    {
        // The script container uses the Park-Miller reduction, including signed keys.
        constexpr int quotient = 127773, multiplier = 16807, remainder = 2836, modulus = 2147483647;
        const auto reduced = (key % quotient) * multiplier - (key / quotient) * remainder;
        hash = reduced < 0 ? reduced + modulus : reduced;
    }
    else
    {
        // Its byte hash is FNV-1 with signed octets; FNV-1a changes script iteration order.
        constexpr std::uint32_t offsetBasis = 2166136261u, prime = 16777619u;
        hash = offsetBasis;
        const std::size_t step = std::is_same_v<K, std::string> ? key.size() / 10 + 1 : 1;
        for (std::size_t index = 0; index < key.size(); index += step)
            hash = (hash * prime) ^ SferaNumeric::signedByte(SferaText::byteValue(key[index]));
    }
    return hash % buckets.size();
}

template <class C, bool Hashed>
template <class K>
typename C::iterator SferaScriptContainerContent<C, Hashed>::find(const K &key)
    requires Hashed
{
    const auto &[first, last] = buckets[bucketIndex(key)];
    if (first == values.end())
        return values.end();
    const auto end = std::next(last);
    const auto found = std::find_if(first, end, std::bind_front(&SferaScriptContainerContent<C, Hashed>::template keyMatches<K>, std::cref(key)));
    return found == end ? values.end() : found;
}

template <class C, bool Hashed>
template <class K, class V>
void SferaScriptContainerContent<C, Hashed>::assign(K &&key, V &&value)
    requires Hashed
{
    const auto found = find(key);
    if (found != values.end())
    {
        found->second = std::forward<V>(value);
        return;
    }
    auto &[first, last] = buckets[bucketIndex(key)];
    const auto node = values.emplace(first, std::forward<K>(key), std::forward<V>(value));
    if (first == values.end())
        last = node;
    first = node;
    if (values.size() <= buckets.size())
        return;
    auto count = buckets.size();
    for (unsigned step = 0; step < 3; ++step)
    {
        if (count > buckets.max_size() / 2)
            throw std::length_error("Script hash container is too large");
        count *= 2;
    }
    rehash(count);
}

auto SferaScriptContainer::findStoredEntry(auto &state, const auto &key)
{
    if constexpr (std::remove_reference_t<decltype(state)>::Hashed)
        return state.find(key);
    else
        return state.values.find(key);
}

bool SferaScriptContainer::ownsMappedData(const void *data, const std::pair<const std::uint32_t, SferaMbcRuntimeMemoryRegion> &entry) const
{
    return entry.second.owner == this && entry.second.address() == data;
}

bool SferaScriptContainer::mappedAddressInRange(const void *begin, const void *end, const std::pair<const std::uint32_t, SferaMbcRuntimeMemoryRegion> &entry) const
{
    const std::less<const void *> less;
    const void *address = entry.second.data;
    return entry.second.owner == this && !less(address, begin) && less(address, end);
}

template <class C, bool Hashed> SferaScriptContainerContent<C, Hashed>::SferaScriptContainerContent()
{
    if constexpr (Hashed)
        buckets.assign(8, {values.end(), values.end()});
}

template <class C, bool Hashed>
void SferaScriptContainerContent<C, Hashed>::rehash(std::size_t count)
    requires Hashed
{
    decltype(buckets) replacement(count, {values.end(), values.end()});
    C pending;
    buckets.swap(replacement);
    pending.splice(pending.end(), values);
    while (!pending.empty())
    {
        const auto node = pending.begin();
        auto &[first, last] = buckets[bucketIndex(node->first)];
        if (first == values.end())
            last = node;
        values.splice(first, pending, node);
        first = node;
    }
}

template <class C, bool Hashed>
void SferaScriptContainerContent<C, Hashed>::erase(typename C::iterator position)
    requires Hashed
{
    auto &[first, last] = buckets[bucketIndex(position->first)];
    if (first == last)
        first = last = values.end();
    else if (position == first)
        first = std::next(position);
    else if (position == last)
        last = std::prev(position);
    values.erase(position);
}

template <class C, bool Hashed>
auto SferaScriptContainer::constructStorage(SferaScriptContainerKind kind, SferaScriptContainerValueType type, SferaScriptContainerValueType keyType) -> std::unique_ptr<SferaScriptContainer>
{
    return std::make_unique<SferaScriptContainer>(kind, type, std::in_place_type<SferaScriptContainerContent<C, Hashed>>, keyType);
}

template <class T>
auto SferaScriptContainer::selectStorage(SferaScriptContainerKind kind, SferaScriptContainerValueType type, SferaScriptContainerValueType keyType) -> std::unique_ptr<SferaScriptContainer>
{
    if constexpr (!std::is_same_v<T, std::uint8_t>)
        if (kind == SferaScriptContainerKind::Map)
        {
            if (keyType == SferaScriptContainerValueType::Integer)
                return constructStorage<std::map<int, T>>(kind, type, keyType);
            if (keyType == SferaScriptContainerValueType::String)
                return constructStorage<std::map<std::string, T>>(kind, type, keyType);
            return nullptr;
        }
    if constexpr (!std::is_same_v<T, std::uint8_t>)
        if (kind == SferaScriptContainerKind::HashMap)
        {
            if (keyType == SferaScriptContainerValueType::Integer)
                return constructStorage<std::list<std::pair<const int, T>>, true>(kind, type, keyType);
            if (keyType == SferaScriptContainerValueType::String)
                return constructStorage<std::list<std::pair<const std::string, T>>, true>(kind, type, keyType);
            if (keyType == SferaScriptContainerValueType::Binary)
                return constructStorage<std::list<std::pair<const SferaScriptContainerBinary, T>>, true>(kind, type, keyType);
            return nullptr;
        }
    if constexpr (!std::is_same_v<T, std::uint8_t>)
        if (kind == SferaScriptContainerKind::List)
            return constructStorage<std::list<T>>(kind, type, keyType);
    if (kind == SferaScriptContainerKind::Vector)
        return constructStorage<std::vector<T>>(kind, type, keyType);
    if constexpr (std::is_same_v<T, int> || std::is_same_v<T, std::string>)
        if (kind == SferaScriptContainerKind::Set)
            return constructStorage<std::set<T>>(kind, type, keyType);
    return nullptr;
}

std::unique_ptr<SferaScriptContainer> SferaScriptContainer::create(SferaScriptContainerKind kind, SferaScriptContainerValueType type, SferaScriptContainerValueType keyType)
{
    switch (type)
    {
    case SferaScriptContainerValueType::Integer:
        return selectStorage<int>(kind, type, keyType);
    case SferaScriptContainerValueType::Real:
        return selectStorage<float>(kind, type, keyType);
    case SferaScriptContainerValueType::Byte:
        return selectStorage<std::uint8_t>(kind, type, keyType);
    case SferaScriptContainerValueType::String:
        return selectStorage<std::string>(kind, type, keyType);
    case SferaScriptContainerValueType::Binary:
        return selectStorage<SferaScriptContainerBinary>(kind, type, keyType);
    default:
        return nullptr;
    }
}

auto SferaScriptContainer::forgetStoredValue(SferaMbcRuntime &runtime, const auto &value)
{
    if constexpr (std::is_same_v<std::remove_cvref_t<decltype(value)>, std::string> || std::is_same_v<std::remove_cvref_t<decltype(value)>, SferaScriptContainerBinary>)
        std::erase_if(runtime.mapped_memory, std::bind_front(&SferaScriptContainer::ownsMappedData, this, value.data()));
}

template <class T> auto SferaScriptContainer::readStoredValue(SferaMbcRuntime &runtime) -> T
{
    if constexpr (std::is_same_v<T, float>)
        return runtime.nextReal();
    else if constexpr (std::is_same_v<T, std::uint8_t>)
        return SferaNumeric::lowByte(SferaNumeric::word(runtime.nextInteger()));
    else if constexpr (std::is_integral_v<T>)
        return runtime.nextInteger();
    else
    {
        auto &source = runtime.nextSliceReference();
        if constexpr (std::is_same_v<T, std::string>)
            return runtime.textIn(source);
        else
        {
            const std::uint32_t length = runtime.nextInteger();
            if (!source.contains(length))
                source.diagnoseRange(length);
            const auto bytes = runtime.memoryBytes(source.base, length);
            T result(bytes.begin(), bytes.end());
            if (result.empty())
                result.reserve(1);
            return result;
        }
    }
}

auto SferaScriptContainer::writeStoredValue(SferaMbcRuntime &runtime, SferaSliceReference32 &destination, const auto &value)
{
    if constexpr (std::is_arithmetic_v<std::remove_cvref_t<decltype(value)>>)
        runtime.writeMemory(destination.base, value);
    else
        runtime.exportSlice(destination, value.data(), value.size() + (std::is_same_v<std::remove_cvref_t<decltype(value)>, std::string> ? 1 : 0), this);
}

auto SferaScriptContainer::elementAt(auto &values, int index)
{
    auto iterator = values.begin();
    if (index < 0 || std::cmp_greater_equal(index, values.size()))
        return values.end();
    std::advance(iterator, index);
    return iterator;
}

auto SferaScriptContainer::currentElement(auto &state, auto &values)
{
    if constexpr (std::remove_reference_t<decltype(state)>::Indexed)
        return state.cursor < values.size() ? values.begin() + state.cursor : values.end();
    else
        return state.cursor;
}

auto SferaScriptContainer::eraseElement(SferaMbcRuntime &runtime, auto &state, auto &values, auto iterator)
{
    forgetStoredValue(runtime, *iterator);
    if constexpr (std::remove_reference_t<decltype(state)>::Indexed)
    {
        const void *begin = &*iterator;
        const void *end = values.data() + values.size();

        std::erase_if(runtime.mapped_memory, std::bind_front(&SferaScriptContainer::mappedAddressInRange, this, begin, end));
        values.erase(iterator);
        if (header.iteration_active && state.cursor >= values.size())
            header.iteration_active = false;
    }
    else
    {
        if (header.iteration_active && state.cursor == iterator)
        {
            ++state.cursor;
            header.iteration_active = state.cursor != values.end();
        }
        values.erase(iterator);
    }
}

auto SferaScriptContainer::executeContent(SferaMbcRuntime &runtime, SferaScriptContainerCommand command, auto &state)
{
    auto &values = state.values;

    if constexpr (std::remove_reference_t<decltype(state)>::Mapped)
    {
        if (command == SferaScriptContainerCommand::IteratorState)
        {
            runtime.pushInteger(!header.iteration_active);
            return;
        }
        if (command == SferaScriptContainerCommand::First || command == SferaScriptContainerCommand::Next)
        {
            auto &keyDestination = runtime.nextSliceReference();
            auto &valueDestination = runtime.nextSliceReference();
            if (runtime.execution_failed)
                return;
            if (command == SferaScriptContainerCommand::First)
            {
                state.cursor = values.begin();
                header.iteration_active = state.cursor != values.end();
            }
            else if (header.iteration_active)
            {
                ++state.cursor;
                header.iteration_active = state.cursor != values.end();
            }
            if (!header.iteration_active)
            {
                runtime.pushInteger(UINT32_MAX);
                return;
            }
            writeStoredValue(runtime, keyDestination, state.cursor->first);
            writeStoredValue(runtime, valueDestination, state.cursor->second);
            runtime.pushInteger(0);
            return;
        }
        if (command == SferaScriptContainerCommand::Clear)
        {
            runtime.forgetMemory(this);
            values.clear();
            if constexpr (std::remove_reference_t<decltype(state)>::Hashed)
                state.buckets.assign(8, {values.end(), values.end()});
            state.cursor = values.end();
            header.iteration_active = false;
            runtime.pushInteger(0);
            return;
        }
        if (command >= SferaScriptContainerCommand::Write && command <= SferaScriptContainerCommand::Read)
        {
            auto key = readStoredValue<std::remove_const_t<typename std::remove_reference_t<decltype(state.values)>::value_type::first_type>>(runtime);
            if (command == SferaScriptContainerCommand::Write)
            {
                auto value = readStoredValue<typename std::remove_reference_t<decltype(state.values)>::value_type::second_type>(runtime);
                if (runtime.execution_failed)
                    return;
                const auto previous = findStoredEntry(state, key);
                if (previous != values.end())
                    forgetStoredValue(runtime, previous->second);
                if constexpr (std::remove_reference_t<decltype(state)>::Hashed)
                    state.assign(std::move(key), std::move(value));
                else
                    values.insert_or_assign(std::move(key), std::move(value));
            }
            else if (command == SferaScriptContainerCommand::Erase)
            {
                if (runtime.execution_failed)
                    return;
                // The script API cancels iteration even when the erased key is absent.
                header.iteration_active = false;
                const auto found = findStoredEntry(state, key);
                if (found != values.end())
                {
                    forgetStoredValue(runtime, found->first);
                    forgetStoredValue(runtime, found->second);
                    if constexpr (std::remove_reference_t<decltype(state)>::Hashed)
                        state.erase(found);
                    else
                        values.erase(found);
                }
                state.cursor = values.end();
            }
            else
            {
                auto &destination = runtime.nextSliceReference();
                if (runtime.execution_failed)
                    return;
                const auto found = findStoredEntry(state, key);
                if (found == values.end())
                {
                    runtime.pushInteger(UINT32_MAX);
                    return;
                }
                writeStoredValue(runtime, destination, found->second);
            }
            runtime.pushInteger(0);
            return;
        }
        runtime.pushInteger(UINT32_MAX);
    }
    else
    {
        if (command == SferaScriptContainerCommand::IteratorState)
        {
            runtime.pushInteger(std::remove_reference_t<decltype(state)>::Unique ? header.iteration_active : !header.iteration_active);
            return;
        }
        if (command == SferaScriptContainerCommand::First || command == SferaScriptContainerCommand::Next)
        {
            auto &destination = runtime.nextSliceReference();
            if (runtime.execution_failed)
                return;
            if (command == SferaScriptContainerCommand::First)
            {
                if constexpr (std::remove_reference_t<decltype(state)>::Indexed)
                    state.cursor = 0;
                else
                    state.cursor = values.begin();
                header.iteration_active = !values.empty();
            }
            else if (header.iteration_active)
            {
                ++state.cursor;
                header.iteration_active = currentElement(state, values) != values.end();
            }
            if (!header.iteration_active)
            {
                runtime.pushInteger(UINT32_MAX);
                return;
            }
            writeStoredValue(runtime, destination, *currentElement(state, values));
            runtime.pushInteger(0);
            return;
        }
        if constexpr (std::remove_reference_t<decltype(state)>::Unique)
        {
            if (command == SferaScriptContainerCommand::Clear)
            {
                runtime.forgetMemory(this);
                values.clear();
                state.cursor = values.end();
                header.iteration_active = false;
                runtime.pushInteger(0);
                return;
            }
            if (command >= SferaScriptContainerCommand::Write && command <= SferaScriptContainerCommand::Read)
            {
                const auto value = readStoredValue<typename std::remove_reference_t<decltype(state.values)>::value_type>(runtime);
                if (runtime.execution_failed)
                    return;
                if (command == SferaScriptContainerCommand::Write)
                    values.insert(value);
                else
                {
                    const auto found = values.find(value);
                    if (command == SferaScriptContainerCommand::Read)
                    {
                        runtime.pushInteger(found != values.end());
                        return;
                    }
                    if (found != values.end())
                        eraseElement(runtime, state, values, found);
                }
                runtime.pushInteger(0);
                return;
            }
        }
        else
        {
            if (command == SferaScriptContainerCommand::Append || (!std::remove_reference_t<decltype(state)>::Indexed && command == SferaScriptContainerCommand::Prepend))
            {
                auto value = readStoredValue<typename std::remove_reference_t<decltype(state.values)>::value_type>(runtime);
                if (runtime.execution_failed)
                    return;
                if constexpr (!std::remove_reference_t<decltype(state)>::Indexed)
                {
                    if (command == SferaScriptContainerCommand::Prepend)
                        values.push_front(std::move(value));
                    else
                        values.push_back(std::move(value));
                }
                else
                {
                    if (values.size() == values.capacity())
                        runtime.forgetMemory(this);
                    values.push_back(std::move(value));
                }
                runtime.pushInteger(0);
                return;
            }
            if (command >= SferaScriptContainerCommand::Write && command <= SferaScriptContainerCommand::Read)
            {
                const auto index = runtime.nextInteger();
                if (command == SferaScriptContainerCommand::Write)
                {
                    auto value = readStoredValue<typename std::remove_reference_t<decltype(state.values)>::value_type>(runtime);
                    if (runtime.execution_failed)
                        return;
                    const auto found = elementAt(values, index);
                    if (found == values.end())
                    {
                        runtime.pushInteger(UINT32_MAX);
                        return;
                    }
                    forgetStoredValue(runtime, *found);
                    *found = std::move(value);
                }
                else if (command == SferaScriptContainerCommand::Erase)
                {
                    if (runtime.execution_failed)
                        return;
                    const auto found = elementAt(values, index);
                    if (found == values.end())
                    {
                        runtime.pushInteger(UINT32_MAX);
                        return;
                    }
                    eraseElement(runtime, state, values, found);
                }
                else
                {
                    auto &destination = runtime.nextSliceReference();
                    if (runtime.execution_failed)
                        return;
                    const auto found = elementAt(values, index);
                    if (found == values.end())
                    {
                        runtime.pushInteger(UINT32_MAX);
                        return;
                    }
                    writeStoredValue(runtime, destination, *found);
                }
                runtime.pushInteger(0);
                return;
            }
        }
        runtime.pushInteger(UINT32_MAX);
    }
}

template <std::size_t Index> void SferaScriptContainer::executeVariant(SferaMbcRuntime &runtime, SferaScriptContainerCommand command)
{
    executeContent(runtime, command, std::get<Index>(content));
}

template <std::size_t... Indices> constexpr auto SferaScriptContainer::executionDispatch(std::index_sequence<Indices...>)
{
    return std::array{&SferaScriptContainer::executeVariant<Indices>...};
}

void SferaScriptContainer::execute(SferaMbcRuntime &runtime)
{
    const auto command = SferaNumeric::enumFromBits<SferaScriptContainerCommand>(runtime.nextInteger());
    static constexpr auto dispatch = executionDispatch(std::make_index_sequence<std::variant_size_v<decltype(content)>>{});
    if (content.valueless_by_exception())
        throw std::bad_variant_access();
    std::invoke(dispatch[content.index()], this, runtime, command);
}
