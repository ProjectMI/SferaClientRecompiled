#pragma once

#include <cstddef>
#include <cstdint>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

template <class C, bool HashStorage = false> struct SferaScriptContainerContent
{
    static constexpr bool Hashed = HashStorage;
    static constexpr bool Mapped = Hashed || requires { typename C::mapped_type; };
    static constexpr bool Indexed = !Mapped && requires(C &values) { values[0]; };
    static constexpr bool Unique = requires { typename C::key_type; };
    C values;
    std::conditional_t<Indexed, std::size_t, typename C::iterator> cursor{};
    std::conditional_t<Hashed, std::vector<std::pair<typename C::iterator, typename C::iterator>>, std::monostate> buckets;
    SferaScriptContainerContent();
    template <class K>
    std::size_t bucketIndex(const K &key) const
        requires Hashed;
    template <class K>
    typename C::iterator find(const K &key)
        requires Hashed;
    template <class K, class V>
    void assign(K &&key, V &&value)
        requires Hashed;
    void erase(typename C::iterator position)
        requires Hashed;
    void rehash(std::size_t count)
        requires Hashed;

  private:
    template <class K>
    static bool keyMatches(const K &key, const typename C::value_type &value)
        requires Hashed;
};

struct SferaDataContainerHeader;

enum class SferaDataContainerHeaderKind : std::uint32_t
{
    List = 1,
    Vector,
    Set,
    Map,
    HashMap
};
enum class SferaDataContainerHeaderValueType : std::uint32_t
{
    Integer = 1,
    Real,
    Byte,
    String,
    Binary
};

struct SferaDataContainerHeader
{
    SferaDataContainerHeaderKind kind;
    bool iteration_active;
};

using SferaScriptContainerKind = SferaDataContainerHeaderKind;
using SferaScriptContainerValueType = SferaDataContainerHeaderValueType;
using SferaScriptContainerBinary = std::vector<std::uint8_t>;
enum class SferaScriptContainerCommand : int
{
    Write = 0,
    Erase = 1,
    Read = 2,
    First = 3,
    Next = 4,
    IteratorState = 5,
    Clear = 9,
    Append = 10,
    Prepend = 11
};
enum class SferaScriptContainerLifecycle : int
{
    Create = 1,
    Destroy,
    Kind,
    ValueType,
    KeyType
};

struct SferaMbcRuntime;
struct SferaMbcRuntimeMemoryRegion;
struct SferaScriptContainer;
struct SferaSliceReference32;

struct SferaScriptContainer
{
    SferaDataContainerHeader header;
    SferaScriptContainerValueType value_type;
    SferaScriptContainerValueType key_type;
    std::variant<SferaScriptContainerContent<std::list<int>>, SferaScriptContainerContent<std::list<float>>, SferaScriptContainerContent<std::list<std::string>>,
                 SferaScriptContainerContent<std::list<SferaScriptContainerBinary>>, SferaScriptContainerContent<std::vector<int>>, SferaScriptContainerContent<std::vector<float>>,
                 SferaScriptContainerContent<std::vector<std::uint8_t>>, SferaScriptContainerContent<std::vector<std::string>>, SferaScriptContainerContent<std::vector<SferaScriptContainerBinary>>,
                 SferaScriptContainerContent<std::set<int>>, SferaScriptContainerContent<std::set<std::string>>, SferaScriptContainerContent<std::map<int, int>>,
                 SferaScriptContainerContent<std::map<int, float>>, SferaScriptContainerContent<std::map<int, std::string>>, SferaScriptContainerContent<std::map<int, SferaScriptContainerBinary>>,
                 SferaScriptContainerContent<std::map<std::string, int>>, SferaScriptContainerContent<std::map<std::string, float>>, SferaScriptContainerContent<std::map<std::string, std::string>>,
                 SferaScriptContainerContent<std::map<std::string, SferaScriptContainerBinary>>, SferaScriptContainerContent<std::list<std::pair<const int, int>>, true>,
                 SferaScriptContainerContent<std::list<std::pair<const int, float>>, true>, SferaScriptContainerContent<std::list<std::pair<const int, std::string>>, true>,
                 SferaScriptContainerContent<std::list<std::pair<const int, SferaScriptContainerBinary>>, true>, SferaScriptContainerContent<std::list<std::pair<const std::string, int>>, true>,
                 SferaScriptContainerContent<std::list<std::pair<const std::string, float>>, true>, SferaScriptContainerContent<std::list<std::pair<const std::string, std::string>>, true>,
                 SferaScriptContainerContent<std::list<std::pair<const std::string, SferaScriptContainerBinary>>, true>,
                 SferaScriptContainerContent<std::list<std::pair<const SferaScriptContainerBinary, int>>, true>,
                 SferaScriptContainerContent<std::list<std::pair<const SferaScriptContainerBinary, float>>, true>,
                 SferaScriptContainerContent<std::list<std::pair<const SferaScriptContainerBinary, std::string>>, true>,
                 SferaScriptContainerContent<std::list<std::pair<const SferaScriptContainerBinary, SferaScriptContainerBinary>>, true>>
        content;
    template <class C, bool Hashed>
    SferaScriptContainer(SferaScriptContainerKind kind, SferaScriptContainerValueType type, std::in_place_type_t<SferaScriptContainerContent<C, Hashed>>, SferaScriptContainerValueType keyType)
        : header{kind, false}, value_type(type), key_type(keyType), content(std::in_place_type<SferaScriptContainerContent<C, Hashed>>)
    {
    }
    SferaScriptContainer(const SferaScriptContainer &) = delete;
    SferaScriptContainer &operator=(const SferaScriptContainer &) = delete;
    static std::unique_ptr<SferaScriptContainer> create(SferaScriptContainerKind kind, SferaScriptContainerValueType type,
                                                        SferaScriptContainerValueType keyType = SferaScriptContainerValueType::Integer);
    void execute(SferaMbcRuntime &runtime);

  private:
    template <class C, bool Hashed = false>
    static auto constructStorage(SferaScriptContainerKind kind, SferaScriptContainerValueType type, SferaScriptContainerValueType keyType) -> std::unique_ptr<SferaScriptContainer>;
    template <class T> static auto selectStorage(SferaScriptContainerKind kind, SferaScriptContainerValueType type, SferaScriptContainerValueType keyType) -> std::unique_ptr<SferaScriptContainer>;
    auto forgetStoredValue(SferaMbcRuntime &runtime, const auto &value);
    template <class T> static auto readStoredValue(SferaMbcRuntime &runtime) -> T;
    auto writeStoredValue(SferaMbcRuntime &runtime, SferaSliceReference32 &destination, const auto &value);
    static auto elementAt(auto &values, int index);
    static auto currentElement(auto &state, auto &values);
    auto eraseElement(SferaMbcRuntime &runtime, auto &state, auto &values, auto iterator);

  private:
    static auto findStoredEntry(auto &state, const auto &key);
    bool ownsMappedData(const void *data, const std::pair<const std::uint32_t, SferaMbcRuntimeMemoryRegion> &entry) const;
    bool mappedAddressInRange(const void *begin, const void *end, const std::pair<const std::uint32_t, SferaMbcRuntimeMemoryRegion> &entry) const;
    auto executeContent(SferaMbcRuntime &runtime, SferaScriptContainerCommand command, auto &state);
    template <std::size_t Index> void executeVariant(SferaMbcRuntime &runtime, SferaScriptContainerCommand command);
    template <std::size_t... Indices> static constexpr auto executionDispatch(std::index_sequence<Indices...>);
};
