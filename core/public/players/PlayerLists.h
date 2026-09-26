#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include "math/Vector.h"

class PlayerList;
struct PlayerListEntry;
class PlayerLists;

struct PlayerListEntry
{
    std::string name;
    SferaVec3F position{};
    std::array<int, 3> attributes{};
    std::vector<std::uint8_t> payload;
};

class PlayerList
{
  public:
    std::string name;
    std::size_t minimum_size{};
    std::uint32_t publish_mode{};
    bool notify_relationships = false;

    PlayerList(std::string name, std::size_t minimum, std::uint32_t mode, bool notify);
    PlayerListEntry *find(std::string_view key);
    PlayerListEntry *first();
    PlayerListEntry *next()
    {
        return cursor_.has_value() ? scanFrom(*cursor_ + 1) : nullptr;
    }
    int insert(PlayerListEntry value);
    int remove(std::string_view key);
    const PlayerListEntry *select(const std::array<int, 3> &filters);
    std::size_t size() const noexcept
    {
        return index_.size();
    }

  private:
    // Slot order is visible through L_FFITEM/L_FNITEM; erasure must leave a hole.
    std::vector<std::unique_ptr<PlayerListEntry>> entries_;
    std::map<std::string, std::size_t, std::less<>> index_;
    std::optional<std::size_t> cursor_ = 0;
    PlayerListEntry *scanFrom(std::size_t begin);
    void finishNotificationScan();

  private:
    static auto matchesFilters(const std::array<int, 3> &filters, const PlayerListEntry &entry);
    static bool isEntryPresent(const std::unique_ptr<PlayerListEntry> &entry)
    {
        return entry != nullptr;
    }
    static bool isFilterUnset(int filter)
    {
        return filter == -1;
    }
};

class PlayerLists
{
  public:
    int create(std::string_view name, int minimum, std::uint32_t mode, bool notify);
    int erase(std::string_view name);
    int removeItem(PlayerList &list, std::string_view key);
    PlayerList *find(std::string_view name) const;
    PlayerList *selectList(std::string_view name)
    {
        return current_ = find(name);
    }
    PlayerList *currentList() const noexcept
    {
        return current_;
    }
    void clear() noexcept;

  private:
    std::map<std::string, std::unique_ptr<PlayerList>, std::less<>> lists_;
    PlayerList *current_ = nullptr;
};

extern PlayerLists g_sfera_player_lists;
