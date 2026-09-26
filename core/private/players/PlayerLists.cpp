#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iterator>
#include <memory>
#include <new>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

#include "players/PlayerLists.h"

PlayerList::PlayerList(std::string list_name, std::size_t minimum, std::uint32_t mode, bool notify)
    : name(std::move(list_name)), minimum_size(minimum), publish_mode(mode), notify_relationships(notify), entries_(30)
{
}

PlayerListEntry *PlayerList::find(std::string_view key)
{
    const auto found = index_.find(key);
    return found == index_.end() ? nullptr : entries_[found->second].get();
}

PlayerListEntry *PlayerList::scanFrom(std::size_t begin)
{
    for (std::size_t slot = begin; slot < entries_.size(); ++slot)
        if (entries_[slot] != nullptr)
        {
            cursor_ = slot;
            return entries_[slot].get();
        }
    return nullptr;
}

PlayerListEntry *PlayerList::first()
{
    cursor_.reset();
    return scanFrom(0);
}



void PlayerList::finishNotificationScan()
{
    // The removed notification hooks were no-ops, but their traversal exhausted this cursor.
    const auto last = std::find_if(entries_.rbegin(), entries_.rend(), isEntryPresent);
    if (last == entries_.rend())
        cursor_.reset();
    else
        cursor_ = std::distance(last, entries_.rend()) - 1;
}

int PlayerList::insert(PlayerListEntry value)
{
    if (value.payload.size() > 256)
        return -3;
    const auto found = index_.find(value.name);
    if (found != index_.end())
    {
        *entries_[found->second] = std::move(value);
        if (notify_relationships)
            finishNotificationScan();
        return -105;
    }
    try
    {
        auto entry = std::make_unique<PlayerListEntry>(std::move(value));
        const auto vacant = std::find(entries_.begin(), entries_.end(), nullptr);
        const std::size_t slot = vacant - entries_.begin();
        if (vacant == entries_.end())
            entries_.push_back(nullptr);
        index_.emplace(entry->name, slot);
        entries_[slot] = std::move(entry);
        if (notify_relationships)
            finishNotificationScan();
        return 0;
    }
    catch (const std::bad_alloc &)
    {
        return -20;
    }
    catch (const std::length_error &)
    {
        return -20;
    }
}

int PlayerList::remove(std::string_view key)
{
    const auto found = index_.find(key);
    if (found == index_.end())
        return notify_relationships ? -10 : -8;
    if (notify_relationships)
        finishNotificationScan();
    const auto slot = found->second;
    index_.erase(found);
    entries_[slot].reset();
    return size() < minimum_size ? -6 : 0;
}

auto PlayerList::matchesFilters(const std::array<int, 3> &filters, const PlayerListEntry &entry)
{
    for (std::size_t index = 0; index < filters.size(); ++index)
    {
        if (filters[index] != -1 && filters[index] != entry.attributes[index])
            return false;
    }
    return true;
}


const PlayerListEntry *PlayerList::select(const std::array<int, 3> &filters)
{
    if (std::all_of(filters.begin(), filters.end(), isFilterUnset))
        return nullptr;

    std::size_t count = 0;
    for (auto *entry = first(); entry != nullptr; entry = next())
        if (matchesFilters(filters, *entry))
            ++count;
    if (count == 0)
        return nullptr;
    auto target = std::rand() % count;
    for (auto *entry = first(); entry != nullptr; entry = next())
        if (matchesFilters(filters, *entry) && target-- == 0)
            return entry;
    return nullptr;
}

PlayerList *PlayerLists::find(std::string_view name) const
{
    const auto found = lists_.find(name);
    return found == lists_.end() ? nullptr : found->second.get();
}

int PlayerLists::create(std::string_view name, int minimum, std::uint32_t mode, bool notify)
{
    if (find(name) != nullptr)
        return -101;
    std::unique_ptr<PlayerList> list;
    try
    {
        list = std::make_unique<PlayerList>(std::string(name), std::max(minimum, 0), mode, notify);
    }
    catch (const std::bad_alloc &)
    {
        return -14;
    }
    try
    {
        lists_.emplace(list->name, std::move(list));
    }
    catch (const std::bad_alloc &)
    {
        return -20;
    }
    return 0;
}

int PlayerLists::erase(std::string_view name)
{
    const auto found = lists_.find(name);
    if (found == lists_.end())
        return -8;
    if (current_ == found->second.get())
        current_ = nullptr;
    lists_.erase(found);
    return 0;
}

int PlayerLists::removeItem(PlayerList &list, std::string_view key)
{
    const auto result = list.remove(key);
    if (result == -6)
        erase(list.name);
    return result;
}

void PlayerLists::clear() noexcept
{
    current_ = nullptr;
    lists_.clear();
}
