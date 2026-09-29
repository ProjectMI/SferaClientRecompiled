#pragma once

#include <cstddef>
#include <cstdint>
#include <map>
#include <memory>
#include <span>
#include <string_view>
#include <unordered_set>
#include <variant>
#include <vector>

#include "script/MbcValue.h"

// These are actual C++ objects. The old MBC byte coordinates are retained only
// for bounds, record-member addressing and the engine's 32-bit buffer ABI.
// No process-wide byte image is allocated or relocated.
enum class SferaNativeFieldKind : std::uint8_t
{
    Bytes,
    Integers,
    Reals,
    References,
    CommandArguments
};

using SferaCommandArgument = std::variant<std::uint32_t, float, SferaSliceReference32>;

struct SferaNativeFieldInitializer
{
    std::uint32_t offset;
    std::uint32_t count;
    SferaNativeFieldKind kind;
    std::span<const std::uint32_t> words;
    std::string_view bytes;
};

struct SferaNativeObjectInitializer
{
    std::uint32_t extent;
    std::span<const SferaNativeFieldInitializer> fields;
};

class SferaNativeAddressSpace;

class SferaNativeObject final : public std::enable_shared_from_this<SferaNativeObject>
{
public:
    ~SferaNativeObject();
    SferaNativeObject(const SferaNativeObject &) = delete;
    SferaNativeObject &operator=(const SferaNativeObject &) = delete;

    std::uint32_t address() const noexcept { return address_; }
    std::uint32_t extent() const noexcept { return extent_; }
    SferaSliceReference32 reference(std::uint32_t offset, std::uint32_t width);
    SferaMbcValue load(std::uint32_t offset, SferaMbcValueType type, bool loadAddress = false);
    void store(std::uint32_t offset, const SferaMbcValue &value, SferaMbcValueType type, std::size_t width);
    std::uint32_t readWord(std::uint32_t offset, std::size_t width = 4) const;
    void writeWord(std::uint32_t offset, std::uint32_t word, std::size_t width = 4);
    SferaSliceReference32 readReference(std::uint32_t offset) const;
    void writeReference(std::uint32_t offset, SferaSliceReference32 reference);
    std::span<std::uint8_t> contiguous(std::uint32_t offset, std::size_t count);
    std::span<std::uint8_t> contiguousRemainder(std::uint32_t offset);
    std::vector<std::uint8_t> serialize() const;
    void importChanges(std::span<const std::uint8_t> before, std::span<const std::uint8_t> after);
    bool copyTyped(std::uint32_t destination, SferaNativeObject &source, std::uint32_t sourceOffset, std::size_t count);
    SferaNativeFieldKind kindAt(std::uint32_t offset) const;

private:
    friend class SferaNativeAddressSpace;
    using Payload = std::variant<std::vector<std::uint8_t>, std::vector<std::uint32_t>, std::vector<float>,
                                 std::vector<SferaSliceReference32>, std::vector<SferaCommandArgument>>;
    struct Field
    {
        std::uint32_t offset;
        std::uint32_t extent;
        SferaNativeFieldKind kind;
        Payload payload;
    };
    SferaNativeObject(std::shared_ptr<SferaNativeAddressSpace> space, std::uint32_t address, const SferaNativeObjectInitializer &initializer);
    const Field &fieldAt(std::uint32_t offset, std::size_t width = 1) const;
    Field &fieldAt(std::uint32_t offset, std::size_t width = 1);
    static std::span<std::uint8_t> primitiveBytes(Field &field);
    std::uint8_t byteAt(std::uint32_t offset) const;
    void setByte(std::uint32_t offset, std::uint8_t value);
    void validate(std::uint32_t offset, std::size_t count) const;
    SferaSliceReference32 own(SferaSliceReference32 value) const;
    void promoteReference(std::uint32_t offset);
    void visitOwners(const std::function<void(std::shared_ptr<SferaNativeObject> &)> &visitor);
    static std::uint32_t commandWord(const SferaCommandArgument &argument);
    std::shared_ptr<SferaNativeAddressSpace> space_;
    std::uint32_t address_;
    std::uint32_t extent_;
    std::vector<Field> fields_;
};

// Native references retain their allocation. The address registry is weak and
// serves only legacy engine APIs accepting an integer address, never ownership.
class SferaNativeAddressSpace final : public std::enable_shared_from_this<SferaNativeAddressSpace>
{
public:
    SferaNativeAddressSpace();
    std::shared_ptr<SferaNativeObject> create(const SferaNativeObjectInitializer &initializer);
    std::shared_ptr<SferaNativeObject> createBytes(std::uint32_t size);
    std::shared_ptr<SferaNativeObject> find(std::uint32_t address) const;
    std::uint32_t findAddress(const void *data, std::size_t size) const;
    void collectCycles();
    void collectCyclesIfNeeded();
    void requestCollection() noexcept { collection_requested_ = true; }
    std::size_t liveObjects() const noexcept { return objects_.size(); }

private:
    friend class SferaNativeObject;
    void release(std::uint32_t address, std::uint32_t extent) noexcept;
    struct BufferRange
    {
        std::uint32_t address;
        std::size_t size;
        SferaNativeObject *owner;
    };
    void registerBuffers(SferaNativeObject &object);
    void unregisterBuffers(SferaNativeObject &object) noexcept;
    std::map<std::uintptr_t, BufferRange> buffers_;
    std::unordered_set<SferaNativeObject *> reference_objects_;
    std::uint32_t collection_ticks_ = 0;
    bool collection_requested_ = false;
    std::map<std::uint32_t, std::uint32_t> free_;
    std::map<std::uint32_t, std::weak_ptr<SferaNativeObject>> objects_;
};

// A short-lived adapter for host APIs requiring one contiguous byte buffer for
// a heterogeneous record. Copies exist only for the duration of that host call.
class SferaNativeScratch final
{
public:
    std::span<std::uint8_t> view(const std::shared_ptr<SferaNativeObject> &object, std::uint32_t offset, std::size_t count);
    void flush();
    void synchronize();
    std::uint32_t findAddress(const void *data, std::size_t count) const;
    bool empty() const noexcept { return buffers_.empty(); }

private:
    struct Buffer
    {
        std::shared_ptr<SferaNativeObject> object;
        std::vector<std::uint8_t> initial;
        std::vector<std::uint8_t> bytes;
    };
    std::vector<Buffer> buffers_;
};
