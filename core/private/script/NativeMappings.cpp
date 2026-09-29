#include "script/NativeMappings.h"

#include <algorithm>
#include <limits>
#include <set>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <vector>

struct SferaNativeMappings::State
{
    using Key = std::pair<std::uintptr_t, std::uint32_t>;
    struct Node
    {
        Key key;
        std::uintptr_t end;
        std::uintptr_t maximum_end;
        std::uint32_t minimum_address;
        std::uint64_t priority;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(Key value, std::size_t size) : key(value), end(value.first + size), maximum_end(end), minimum_address(value.second)
        {
            // Deterministic treap priorities avoid address-order degeneration.
            auto mixed = static_cast<std::uint64_t>(key.second) + 0x9e3779b97f4a7c15ull;
            mixed = (mixed ^ (mixed >> 30)) * 0xbf58476d1ce4e5b9ull;
            mixed = (mixed ^ (mixed >> 27)) * 0x94d049bb133111ebull;
            priority = mixed ^ (mixed >> 31);
        }
        void update() noexcept
        {
            maximum_end = end;
            minimum_address = key.second;
            for (const auto *child : {left.get(), right.get()})
                if (child)
                {
                    maximum_end = std::max(maximum_end, child->maximum_end);
                    minimum_address = std::min(minimum_address, child->minimum_address);
                }
        }
    };
    Regions regions;
    std::map<std::uint32_t, std::uint32_t> free{{addressBegin, UINT32_MAX - 2u - addressBegin}};
    std::unordered_map<const void *, std::set<std::uint32_t>> owners;
    std::unique_ptr<Node> physical;

    static void rotate(std::unique_ptr<Node> &root, bool left) noexcept
    {
        auto next = std::move(left ? root->right : root->left);
        (left ? root->right : root->left) = std::move(left ? next->left : next->right);
        root->update();
        (left ? next->left : next->right) = std::move(root);
        next->update();
        root = std::move(next);
    }
    static void add(std::unique_ptr<Node> &root, std::unique_ptr<Node> node) noexcept
    {
        if (!root)
        {
            root = std::move(node);
            return;
        }
        const bool right = root->key < node->key;
        auto &child = right ? root->right : root->left;
        add(child, std::move(node));
        if (child->priority < root->priority)
            rotate(root, right);
        root->update();
    }
    static void remove(std::unique_ptr<Node> &root, Key key) noexcept
    {
        if (!root)
            return;
        if (key == root->key)
        {
            if (!root->left || !root->right)
            {
                auto next = std::move(root->left ? root->left : root->right);
                root = std::move(next);
                return;
            }
            rotate(root, root->right->priority < root->left->priority);
        }
        remove(key < root->key ? root->left : root->right, key);
        root->update();
    }
    static void find(const Node *node, std::uintptr_t start, std::uintptr_t end, std::uint32_t &best) noexcept
    {
        if (!node || node->maximum_end < end || node->minimum_address >= best)
            return;
        find(node->left.get(), start, end, best);
        if (node->key.first <= start)
        {
            if (node->end >= end)
                best = std::min(best, node->key.second);
            find(node->right.get(), start, end, best);
        }
    }
    void release(std::uint32_t address, std::uint32_t count) noexcept
    {
        auto next = free.lower_bound(address);
        if (next != free.begin())
        {
            const auto previous = std::prev(next);
            if (previous->first + previous->second == address)
            {
                address = previous->first;
                count += previous->second;
                free.erase(previous);
            }
        }
        if (next != free.end() && address + count == next->first)
        {
            count += next->second;
            free.erase(next);
        }
        try { free.emplace(address, count); }
        catch (...) { /* Destruction may lose a reusable hole, never a live mapping. */ }
    }
    void erase(std::uint32_t address, bool updateOwner) noexcept
    {
        const auto entry = regions.find(address);
        if (entry == regions.end())
            return;
        const auto &region = entry->second;
        remove(physical, {reinterpret_cast<std::uintptr_t>(region.data), address});
        if (updateOwner)
        {
            const auto owner = owners.find(region.owner);
            if (owner != owners.end())
            {
                owner->second.erase(address);
                if (owner->second.empty()) owners.erase(owner);
            }
        }
        release(address, static_cast<std::uint32_t>(region.size + 1));
        regions.erase(entry);
    }
    void collectStarts(const Node *node, const void *owner, std::uintptr_t first, std::uintptr_t last,
                       bool exact, std::vector<std::uint32_t> &matches) const
    {
        if (!node)
            return;
        if (node->key.first >= first)
            collectStarts(node->left.get(), owner, first, last, exact, matches);
        if (node->key.first >= first && (exact ? node->key.first == first : node->key.first < last) &&
            regions.find(node->key.second)->second.owner == owner)
            matches.push_back(node->key.second);
        if (exact ? node->key.first <= first : node->key.first < last)
            collectStarts(node->right.get(), owner, first, last, exact, matches);
    }
};

SferaNativeMappings::SferaNativeMappings() : state_(std::make_unique<State>()) {}
SferaNativeMappings::~SferaNativeMappings() = default;
bool SferaNativeMappings::empty() const noexcept { return state_->regions.empty(); }
std::size_t SferaNativeMappings::size() const noexcept { return state_->regions.size(); }
SferaNativeMappings::const_iterator SferaNativeMappings::begin() const noexcept { return state_->regions.begin(); }
SferaNativeMappings::const_iterator SferaNativeMappings::end() const noexcept { return state_->regions.end(); }
SferaNativeMappings::const_iterator SferaNativeMappings::upper_bound(std::uint32_t address) const { return state_->regions.upper_bound(address); }

std::uint32_t SferaNativeMappings::insert(SferaMbcRuntimeMemoryRegion region)
{
    region.size = std::max<std::size_t>(region.size, 1);
    const auto physical = reinterpret_cast<std::uintptr_t>(region.data);
    if (region.size >= addressBegin || region.size > std::numeric_limits<std::uintptr_t>::max() - physical)
        throw std::length_error("Invalid mapped script range");
    const auto reserved = static_cast<std::uint32_t>(region.size + 1);
    auto hole = std::find_if(state_->free.begin(), state_->free.end(), [reserved](const auto &entry) { return entry.second >= reserved; });
    if (hole == state_->free.end())
        throw std::length_error("Script address space exhausted");
    const auto address = hole->first;
    auto node = std::make_unique<State::Node>(State::Key{physical, address}, region.size);
    const auto inserted = state_->regions.emplace(address, region).first;
    try
    {
        state_->owners[region.owner].insert(address);
    }
    catch (...)
    {
        state_->regions.erase(inserted);
        const auto owner = state_->owners.find(region.owner);
        if (owner != state_->owners.end() && owner->second.empty()) state_->owners.erase(owner);
        throw;
    }
    auto reservation = state_->free.extract(hole);
    if (reservation.mapped() > reserved)
    {
        reservation.key() += reserved;
        reservation.mapped() -= reserved;
        state_->free.insert(std::move(reservation));
    }
    State::add(state_->physical, std::move(node));
    return address;
}

std::uint32_t SferaNativeMappings::findAddress(const void *data, std::size_t size) const
{
    const auto start = reinterpret_cast<std::uintptr_t>(data);
    if (size > std::numeric_limits<std::uintptr_t>::max() - start)
        return 0;
    auto best = UINT32_MAX;
    State::find(state_->physical.get(), start, start + size, best);
    if (best == UINT32_MAX)
        return 0;
    const auto physical = reinterpret_cast<std::uintptr_t>(state_->regions.find(best)->second.data);
    return best + static_cast<std::uint32_t>(start - physical);
}

void SferaNativeMappings::forget(const void *owner) noexcept
{
    if (owner == nullptr)
        return;
    const auto entry = state_->owners.find(owner);
    if (entry == state_->owners.end())
        return;
    for (const auto address : entry->second)
        state_->erase(address, false);
    state_->owners.erase(entry);
}

void SferaNativeMappings::forget(const void *owner, const void *data)
{
    std::vector<std::uint32_t> matches;
    const auto address = reinterpret_cast<std::uintptr_t>(data);
    state_->collectStarts(state_->physical.get(), owner, address, address, true, matches);
    for (const auto mapping : matches) state_->erase(mapping, true);
}

void SferaNativeMappings::forget(const void *owner, const void *begin, const void *end)
{
    std::vector<std::uint32_t> matches;
    state_->collectStarts(state_->physical.get(), owner, reinterpret_cast<std::uintptr_t>(begin),
                          reinterpret_cast<std::uintptr_t>(end), false, matches);
    for (const auto mapping : matches) state_->erase(mapping, true);
}

void SferaNativeMappings::clear()
{
    auto replacement = std::make_unique<State>();
    state_.swap(replacement);
}
