#include "script/NativeStorage.h"

#include <algorithm>
#include <array>
#include <bit>
#include <cstring>
#include <limits>
#include <stdexcept>
#include <string>
#include <utility>
#include <unordered_map>

namespace
{
std::uint32_t elementWidth(SferaNativeFieldKind kind)
{
    return kind == SferaNativeFieldKind::Bytes ? 1u : kind == SferaNativeFieldKind::References ? 12u : 4u;
}

std::uint32_t replaceByte(std::uint32_t word, std::size_t index, std::uint8_t value)
{
    const auto shift = static_cast<unsigned>(index * 8);
    return (word & ~(0xffu << shift)) | (static_cast<std::uint32_t>(value) << shift);
}
}

SferaNativeAddressSpace::SferaNativeAddressSpace()
{
    // Leave zero as null and the upper half for existing engine mappings.
    free_.emplace(4u, 0x7ffffff8u);
}

std::shared_ptr<SferaNativeObject> SferaNativeAddressSpace::create(const SferaNativeObjectInitializer &initializer)
{
    if (initializer.extent == 0 || initializer.extent >= 0x7ffffff0u)
        throw std::length_error("Invalid native object size");
    const auto reserved = (initializer.extent + 7u) & ~3u;
    auto free = std::find_if(free_.begin(), free_.end(), [reserved](const auto &entry) { return entry.second >= reserved; });
    if (free == free_.end())
        throw std::length_error("Native host-address space exhausted");
    const auto address = free->first;
    const auto available = free->second;
    free_.erase(free);
    if (available > reserved)
        free_.emplace(address + reserved, available - reserved);
    std::shared_ptr<SferaNativeObject> result;
    try
    {
        result.reset(new SferaNativeObject(shared_from_this(), address, initializer));
    }
    catch (...)
    {
        release(address, initializer.extent);
        throw;
    }
    // If insertion throws, the object's destructor returns the reservation.
    objects_.emplace(address, result);
    registerBuffers(*result);
    return result;
}

std::shared_ptr<SferaNativeObject> SferaNativeAddressSpace::createBytes(std::uint32_t size)
{
    const SferaNativeFieldInitializer field{0, size, SferaNativeFieldKind::Bytes, {}, {}};
    return create({size, std::span(&field, 1)});
}

void SferaNativeAddressSpace::release(std::uint32_t address, std::uint32_t extent) noexcept
{
    objects_.erase(address);
    const auto reserved = (extent + 7u) & ~3u;
    auto next = free_.lower_bound(address);
    std::uint32_t start = address;
    std::uint32_t count = reserved;
    if (next != free_.begin())
    {
        const auto previous = std::prev(next);
        if (previous->first + previous->second == address)
        {
            start = previous->first;
            count += previous->second;
            free_.erase(previous);
        }
    }
    if (next != free_.end() && start + count == next->first)
    {
        count += next->second;
        free_.erase(next);
    }
    try
    {
        free_.emplace(start, count);
    }
    catch (...)
    {
        // An allocation failure during destruction can lose a reusable address
        // range, but must never invalidate a live object's reservation.
    }
}

std::shared_ptr<SferaNativeObject> SferaNativeAddressSpace::find(std::uint32_t address) const
{
    auto entry = objects_.upper_bound(address);
    if (entry == objects_.begin())
        return {};
    --entry;
    auto object = entry->second.lock();
    if (!object || address - entry->first > object->extent())
        return {};
    return object;
}

void SferaNativeAddressSpace::registerBuffers(SferaNativeObject &object)
{
    for (const auto &field : object.fields_)
    {
        auto bytes = object.contiguous(field.offset, field.extent);
        if (!bytes.empty())
            buffers_.emplace(reinterpret_cast<std::uintptr_t>(bytes.data()),
                             BufferRange{object.address() + field.offset, bytes.size(), &object});
    }
}

void SferaNativeAddressSpace::unregisterBuffers(SferaNativeObject &object) noexcept
{
    for (const auto &field : object.fields_)
    {
        auto bytes = object.contiguous(field.offset, field.extent);
        if (!bytes.empty())
        {
            const auto entry = buffers_.find(reinterpret_cast<std::uintptr_t>(bytes.data()));
            if (entry != buffers_.end() && entry->second.owner == &object)
                buffers_.erase(entry);
        }
    }
}

std::uint32_t SferaNativeAddressSpace::findAddress(const void *data, std::size_t size) const
{
    const auto address = reinterpret_cast<std::uintptr_t>(data);
    auto entry = buffers_.upper_bound(address);
    if (entry == buffers_.begin())
        return 0;
    --entry;
    const auto offset = address - entry->first;
    const auto &buffer = entry->second;
    return offset <= buffer.size && size <= buffer.size - offset
        ? buffer.address + static_cast<std::uint32_t>(offset) : 0;
}

SferaNativeObject::SferaNativeObject(std::shared_ptr<SferaNativeAddressSpace> space, std::uint32_t address,
                                   const SferaNativeObjectInitializer &initializer)
    : space_(std::move(space)), address_(address), extent_(initializer.extent)
{
    std::uint32_t end = 0;
    for (const auto &initial : initializer.fields)
    {
        const auto width = elementWidth(initial.kind);
        const auto extent = static_cast<std::uint64_t>(initial.count) * width;
        if (initial.offset != end || extent > extent_ - end)
            throw std::invalid_argument("Native fields must partition their object's declared extent");
        Field field{initial.offset, static_cast<std::uint32_t>(extent), initial.kind, {}};
        switch (initial.kind)
        {
        case SferaNativeFieldKind::Bytes:
        {
            std::vector<std::uint8_t> values(initial.count);
            if (initial.bytes.size() > values.size())
                throw std::invalid_argument("Too many byte initializers");
            std::copy(initial.bytes.begin(), initial.bytes.end(), values.begin());
            field.payload = std::move(values);
            break;
        }
        case SferaNativeFieldKind::Integers:
        {
            std::vector<std::uint32_t> values(initial.count);
            if (initial.words.size() > values.size())
                throw std::invalid_argument("Too many integer initializers");
            std::copy(initial.words.begin(), initial.words.end(), values.begin());
            field.payload = std::move(values);
            break;
        }
        case SferaNativeFieldKind::Reals:
        {
            std::vector<float> values(initial.count);
            if (initial.words.size() > values.size())
                throw std::invalid_argument("Too many real initializers");
            std::transform(initial.words.begin(), initial.words.end(), values.begin(), [](auto bits) { return std::bit_cast<float>(bits); });
            field.payload = std::move(values);
            break;
        }
        case SferaNativeFieldKind::References:
            if (!initial.words.empty() || !initial.bytes.empty())
                throw std::invalid_argument("Native references require symbolic initialization");
            field.payload = std::vector<SferaSliceReference32>(initial.count);
            break;
        case SferaNativeFieldKind::CommandArguments:
        {
            std::vector<SferaCommandArgument> values(initial.count);
            if (initial.words.size() > values.size())
                throw std::invalid_argument("Too many command argument initializers");
            std::copy(initial.words.begin(), initial.words.end(), values.begin());
            field.payload = std::move(values);
            break;
        }
        }
        end += field.extent;
        fields_.push_back(std::move(field));
    }
    if (end != extent_)
        throw std::invalid_argument("Incomplete native object declaration");
}

SferaNativeObject::~SferaNativeObject()
{
    space_->unregisterBuffers(*this);
    space_->reference_objects_.erase(this);
    space_->release(address_, extent_);
}

void SferaNativeObject::validate(std::uint32_t offset, std::size_t count) const
{
    if (offset > extent_ || count > extent_ - offset)
        throw std::out_of_range("Native object access outside its allocation (offset=" + std::to_string(offset) +
                                ", size=" + std::to_string(count) + ", allocation=" + std::to_string(extent_) + ")");
}

const SferaNativeObject::Field &SferaNativeObject::fieldAt(std::uint32_t offset, std::size_t width) const
{
    validate(offset, width);
    auto field = std::upper_bound(fields_.begin(), fields_.end(), offset, [](auto position, const Field &entry) { return position < entry.offset; });
    if (field == fields_.begin())
        throw std::out_of_range("No native field at this offset");
    --field;
    if (offset - field->offset > field->extent || width > field->extent - (offset - field->offset))
        throw std::out_of_range("Access crosses a typed native field boundary");
    return *field;
}

SferaNativeObject::Field &SferaNativeObject::fieldAt(std::uint32_t offset, std::size_t width)
{
    return const_cast<Field &>(std::as_const(*this).fieldAt(offset, width));
}

SferaNativeFieldKind SferaNativeObject::kindAt(std::uint32_t offset) const
{
    return fieldAt(offset).kind;
}

SferaSliceReference32 SferaNativeObject::reference(std::uint32_t offset, std::uint32_t width)
{
    validate(offset, 0);
    const auto base = address_ + offset;
    return {base, base, base + width - 1u, shared_from_this()};
}

SferaSliceReference32 SferaNativeObject::own(SferaSliceReference32 value) const
{
    value.owner = space_->find(value.base);
    return value;
}

std::uint32_t SferaNativeObject::commandWord(const SferaCommandArgument &argument)
{
    return std::visit([](const auto &value) -> std::uint32_t
    {
        using T = std::decay_t<decltype(value)>;
        if constexpr (std::is_same_v<T, SferaSliceReference32>)
            return value.base;
        else if constexpr (std::is_same_v<T, float>)
            return std::bit_cast<std::uint32_t>(value);
        else
            return value;
    }, argument);
}

std::uint8_t SferaNativeObject::byteAt(std::uint32_t offset) const
{
    const auto &field = fieldAt(offset);
    const auto relative = offset - field.offset;
    std::uint32_t word = 0;
    switch (field.kind)
    {
    case SferaNativeFieldKind::Bytes:
        return std::get<std::vector<std::uint8_t>>(field.payload)[relative];
    case SferaNativeFieldKind::Integers:
        word = std::get<std::vector<std::uint32_t>>(field.payload)[relative / 4];
        break;
    case SferaNativeFieldKind::Reals:
        word = std::bit_cast<std::uint32_t>(std::get<std::vector<float>>(field.payload)[relative / 4]);
        break;
    case SferaNativeFieldKind::References:
    {
        const auto &reference = std::get<std::vector<SferaSliceReference32>>(field.payload)[relative / 12];
        const std::array words{reference.base, reference.begin, reference.end};
        word = words[(relative % 12) / 4];
        break;
    }
    case SferaNativeFieldKind::CommandArguments:
        word = commandWord(std::get<std::vector<SferaCommandArgument>>(field.payload)[relative / 4]);
        break;
    }
    return static_cast<std::uint8_t>(word >> ((relative % 4) * 8));
}

std::uint32_t SferaNativeObject::readWord(std::uint32_t offset, std::size_t width) const
{
    validate(offset, width);
    if (width > 4)
        throw std::invalid_argument("Native word width exceeds four bytes");
    std::uint32_t result = 0;
    if (width == 0)
        return result;
    const auto &field = fieldAt(offset);
    const auto bytes = primitiveBytes(const_cast<Field &>(field));
    const auto relative = offset - field.offset;
    if (relative <= bytes.size() && width <= bytes.size() - relative)
    {
        std::memcpy(&result, bytes.data() + relative, width);
        return result;
    }
    for (std::size_t i = 0; i < width; ++i)
        result |= static_cast<std::uint32_t>(byteAt(offset + static_cast<std::uint32_t>(i))) << (i * 8);
    return result;
}

void SferaNativeObject::setByte(std::uint32_t offset, std::uint8_t value)
{
    auto &field = fieldAt(offset);
    const auto relative = offset - field.offset;
    switch (field.kind)
    {
    case SferaNativeFieldKind::Bytes:
        std::get<std::vector<std::uint8_t>>(field.payload)[relative] = value;
        break;
    case SferaNativeFieldKind::Integers:
    {
        auto &word = std::get<std::vector<std::uint32_t>>(field.payload)[relative / 4];
        word = replaceByte(word, relative % 4, value);
        break;
    }
    case SferaNativeFieldKind::Reals:
    {
        auto &number = std::get<std::vector<float>>(field.payload)[relative / 4];
        number = std::bit_cast<float>(replaceByte(std::bit_cast<std::uint32_t>(number), relative % 4, value));
        break;
    }
    case SferaNativeFieldKind::References:
    {
        auto &reference = std::get<std::vector<SferaSliceReference32>>(field.payload)[relative / 12];
        auto &word = relative % 12 < 4 ? reference.base : relative % 12 < 8 ? reference.begin : reference.end;
        word = replaceByte(word, relative % 4, value);
        if (relative % 12 < 4)
        {
            reference.owner = space_->find(reference.base);
            if (reference.owner)
                space_->reference_objects_.insert(this);
        }
        break;
    }
    case SferaNativeFieldKind::CommandArguments:
    {
        auto &argument = std::get<std::vector<SferaCommandArgument>>(field.payload)[relative / 4];
        argument = replaceByte(commandWord(argument), relative % 4, value);
        break;
    }
    }
}

void SferaNativeObject::writeWord(std::uint32_t offset, std::uint32_t word, std::size_t width)
{
    validate(offset, width);
    if (width > 4)
        throw std::invalid_argument("Native word width exceeds four bytes");
    if (width == 4)
    {
        auto &field = fieldAt(offset, 4);
        const auto relative = offset - field.offset;
        if (field.kind == SferaNativeFieldKind::References && relative % 12 == 0)
        {
            auto &reference = std::get<std::vector<SferaSliceReference32>>(field.payload)[relative / 12];
            reference.base = word;
            reference.owner = space_->find(word);
            if (reference.owner)
                space_->reference_objects_.insert(this);
            return;
        }
    }
    if (width != 0)
    {
        auto &field = fieldAt(offset);
        const auto bytes = primitiveBytes(field);
        const auto relative = offset - field.offset;
        if (relative <= bytes.size() && width <= bytes.size() - relative)
        {
            std::memcpy(bytes.data() + relative, &word, width);
            return;
        }
    }
    for (std::size_t i = 0; i < width; ++i)
        setByte(offset + static_cast<std::uint32_t>(i), static_cast<std::uint8_t>(word >> (i * 8)));
}

SferaSliceReference32 SferaNativeObject::readReference(std::uint32_t offset) const
{
    const auto &field = fieldAt(offset);
    const auto relative = offset - field.offset;
    if (field.kind == SferaNativeFieldKind::References && relative % 12 == 0)
        return std::get<std::vector<SferaSliceReference32>>(field.payload)[relative / 12];
    if (field.kind == SferaNativeFieldKind::CommandArguments && relative % 4 == 0)
    {
        const auto &argument = std::get<std::vector<SferaCommandArgument>>(field.payload)[relative / 4];
        if (const auto *reference = std::get_if<SferaSliceReference32>(&argument))
            return *reference;
        return own({commandWord(argument), 0, 0});
    }
    return own({readWord(offset), readWord(offset + 4), readWord(offset + 8)});
}

void SferaNativeObject::promoteReference(std::uint32_t offset)
{
    auto &field = fieldAt(offset, SferaSliceReference32::scriptWidth);
    if (field.kind == SferaNativeFieldKind::References)
        return;
    if (field.kind != SferaNativeFieldKind::Bytes)
        throw std::invalid_argument("Conflicting typed reference field");
    const auto saved = readReference(offset);
    const auto index = static_cast<std::size_t>(&field - fields_.data());
    const auto start = field.offset;
    const auto end = start + field.extent;
    const auto &bytes = std::get<std::vector<std::uint8_t>>(field.payload);
    std::vector<Field> replacement;
    replacement.reserve(3);
    if (offset != start)
        replacement.push_back({start, offset - start, SferaNativeFieldKind::Bytes,
                               std::vector<std::uint8_t>(bytes.begin(), bytes.begin() + offset - start)});
    replacement.push_back({offset, 12u, SferaNativeFieldKind::References, std::vector<SferaSliceReference32>{saved}});
    if (offset + 12u != end)
        replacement.push_back({offset + 12u, end - offset - 12u, SferaNativeFieldKind::Bytes,
                               std::vector<std::uint8_t>(bytes.begin() + offset + 12u - start, bytes.end())});
    // The allocation is stable. Native references name the object and logical
    // member offset, so introducing a typed field does not relocate aliases.
    fields_.reserve(fields_.size() + replacement.size() - 1);
    space_->unregisterBuffers(*this);
    fields_.erase(fields_.begin() + index);
    fields_.insert(fields_.begin() + index, std::make_move_iterator(replacement.begin()), std::make_move_iterator(replacement.end()));
    if (saved.owner)
        space_->reference_objects_.insert(this);
    space_->registerBuffers(*this);
}

void SferaNativeObject::writeReference(std::uint32_t offset, SferaSliceReference32 reference)
{
    if (kindAt(offset) == SferaNativeFieldKind::Bytes)
        promoteReference(offset);
    auto &field = fieldAt(offset);
    const auto relative = offset - field.offset;
    if (!reference.owner)
        reference = own(std::move(reference));
    if (reference.owner)
        space_->reference_objects_.insert(this);
    if (field.kind == SferaNativeFieldKind::References && relative % 12 == 0)
    {
        std::get<std::vector<SferaSliceReference32>>(field.payload)[relative / 12] = std::move(reference);
        return;
    }
    if (field.kind == SferaNativeFieldKind::CommandArguments && relative % 4 == 0)
    {
        std::get<std::vector<SferaCommandArgument>>(field.payload)[relative / 4] = std::move(reference);
        return;
    }
    throw std::invalid_argument("Reference store requires a typed reference field");
}

SferaMbcValue SferaNativeObject::load(std::uint32_t offset, SferaMbcValueType type, bool loadAddress)
{
    const auto width = static_cast<std::uint32_t>(SferaNativeValues::referenceWidth(type));
    SferaMbcValue result{};
    result.type = type;
    result.width = width;
    result.source = reference(offset, width);
    if (type == SferaMbcValueTypeAddress && !loadAddress)
        result.value = result.source;
    else if (type == SferaMbcValueTypeByte)
    {
        result.type = SferaMbcValueTypeInteger;
        result.value.base = static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(readWord(offset, 1))));
    }
    else if (type == SferaMbcValueTypeInteger || type == SferaMbcValueTypeReal)
    {
        result.value.base = readWord(offset);
        if (kindAt(offset) == SferaNativeFieldKind::CommandArguments)
        {
            const auto &field = fieldAt(offset);
            const auto &argument = std::get<std::vector<SferaCommandArgument>>(field.payload)[(offset - field.offset) / 4];
            if (const auto *reference = std::get_if<SferaSliceReference32>(&argument))
                result.value = *reference;
        }
    }
    else
        result.value = readReference(offset);
    return result;
}

void SferaNativeObject::store(std::uint32_t offset, const SferaMbcValue &value, SferaMbcValueType type, std::size_t width)
{
    if (kindAt(offset) == SferaNativeFieldKind::CommandArguments && (value.value.owner || value.isPointer()))
        writeReference(offset, value.value);
    else if (type % 16 != 0)
        writeReference(offset, value.value);
    else
        writeWord(offset, value.value.base, width == 1 ? 1 : 4);
}

std::span<std::uint8_t> SferaNativeObject::primitiveBytes(Field &field)
{
    switch (field.kind)
    {
    case SferaNativeFieldKind::Bytes:
        return std::get<std::vector<std::uint8_t>>(field.payload);
    case SferaNativeFieldKind::Integers:
        return {reinterpret_cast<std::uint8_t *>(std::get<std::vector<std::uint32_t>>(field.payload).data()), field.extent};
    case SferaNativeFieldKind::Reals:
        return {reinterpret_cast<std::uint8_t *>(std::get<std::vector<float>>(field.payload).data()), field.extent};
    default:
        return {};
    }
}

std::span<std::uint8_t> SferaNativeObject::contiguous(std::uint32_t offset, std::size_t count)
{
    validate(offset, count);
    if (count == 0)
        return {};
    auto &field = fieldAt(offset);
    const auto relative = offset - field.offset;
    auto bytes = primitiveBytes(field);
    return relative <= bytes.size() && count <= bytes.size() - relative ? bytes.subspan(relative, count) : std::span<std::uint8_t>{};
}

std::span<std::uint8_t> SferaNativeObject::contiguousRemainder(std::uint32_t offset)
{
    if (offset == extent_)
        return {};
    const auto &field = fieldAt(offset);
    return contiguous(offset, field.offset + field.extent - offset);
}

std::vector<std::uint8_t> SferaNativeObject::serialize() const
{
    std::vector<std::uint8_t> bytes(extent_);
    for (std::uint32_t i = 0; i < extent_; ++i)
        bytes[i] = byteAt(i);
    return bytes;
}

void SferaNativeObject::importChanges(std::span<const std::uint8_t> before, std::span<const std::uint8_t> after)
{
    if (before.size() != extent_ || after.size() != extent_)
        throw std::invalid_argument("Host buffer size changed during a native call");
    // Stage owners while words are assembled; partial byte writes must not free
    // the allocation whose final address is being transferred.
    std::vector<SferaSliceReference32> references;
    for (const auto &field : fields_)
    {
        if (field.kind == SferaNativeFieldKind::References)
        {
            const auto &values = std::get<std::vector<SferaSliceReference32>>(field.payload);
            references.insert(references.end(), values.begin(), values.end());
        }
    }
    for (std::uint32_t i = 0; i < extent_; ++i)
        if (before[i] != after[i])
            setByte(i, after[i]);
}

bool SferaNativeObject::copyTyped(std::uint32_t destination, SferaNativeObject &source, std::uint32_t sourceOffset, std::size_t count)
{
    validate(destination, count);
    source.validate(sourceOffset, count);
    if (count == 0)
        return true;
    auto &output = fieldAt(destination);
    const auto &input = source.fieldAt(sourceOffset);
    const auto outRelative = destination - output.offset;
    const auto inRelative = sourceOffset - input.offset;
    if (count == 4 && output.kind == SferaNativeFieldKind::CommandArguments && outRelative % 4 == 0)
    {
        auto &argument = std::get<std::vector<SferaCommandArgument>>(output.payload)[outRelative / 4];
        if (input.kind == SferaNativeFieldKind::References && inRelative % 12 == 0)
            argument = source.readReference(sourceOffset);
        else if (input.kind == SferaNativeFieldKind::CommandArguments && inRelative % 4 == 0)
            argument = std::get<std::vector<SferaCommandArgument>>(input.payload)[inRelative / 4];
        else if (input.kind == SferaNativeFieldKind::Reals && inRelative % 4 == 0)
            argument = std::bit_cast<float>(source.readWord(sourceOffset));
        else
            argument = source.readWord(sourceOffset);
        if (const auto *reference = std::get_if<SferaSliceReference32>(&argument); reference != nullptr && reference->owner)
            space_->reference_objects_.insert(this);
        return true;
    }
    if (count == 4 && output.kind == SferaNativeFieldKind::References && outRelative % 12 == 0 &&
        input.kind == SferaNativeFieldKind::CommandArguments && inRelative % 4 == 0)
    {
        writeReference(destination, source.readReference(sourceOffset));
        return true;
    }
    if (output.kind == SferaNativeFieldKind::References && input.kind == SferaNativeFieldKind::References &&
        outRelative % 12 == 0 && inRelative % 12 == 0 && count % 12 == 0 &&
        count <= output.extent - outRelative && count <= input.extent - inRelative)
    {
        std::vector<SferaSliceReference32> saved;
        for (std::size_t i = 0; i < count; i += 12)
            saved.push_back(source.readReference(sourceOffset + static_cast<std::uint32_t>(i)));
        for (std::size_t i = 0; i < saved.size(); ++i)
            writeReference(destination + static_cast<std::uint32_t>(i * 12), std::move(saved[i]));
        return true;
    }
    // Generic record/buffer copy stages both bytes and typed reference payloads.
    // This also covers dynamically allocated records whose pointer fields are
    // introduced by member access rather than an absolute global declaration.
    validate(destination, count);
    source.validate(sourceOffset, count);
    struct SavedReference
    {
        std::uint32_t displacement;
        std::uint32_t width;
        SferaSliceReference32 value;
    };
    std::vector<SavedReference> references;
    for (const auto &field : source.fields_)
    {
        const auto stride = field.kind == SferaNativeFieldKind::References ? 12u : 4u;
        if (field.kind != SferaNativeFieldKind::References && field.kind != SferaNativeFieldKind::CommandArguments)
            continue;
        for (std::uint32_t position = field.offset; position < field.offset + field.extent; position += stride)
            if (position >= sourceOffset && position - sourceOffset <= count && stride <= count - (position - sourceOffset))
            {
                if (field.kind == SferaNativeFieldKind::References)
                    references.push_back({position - sourceOffset, stride, source.readReference(position)});
                else
                {
                    const auto &argument = std::get<std::vector<SferaCommandArgument>>(field.payload)[(position - field.offset) / 4];
                    if (const auto *reference = std::get_if<SferaSliceReference32>(&argument))
                        references.push_back({position - sourceOffset, stride, *reference});
                }
            }
    }
    const auto bytes = source.serialize();
    for (std::size_t i = 0; i < count; ++i)
        setByte(destination + static_cast<std::uint32_t>(i), bytes[sourceOffset + i]);
    for (auto &saved : references)
    {
        const auto offset = destination + saved.displacement;
        const auto kind = kindAt(offset);
        if (kind == SferaNativeFieldKind::References || kind == SferaNativeFieldKind::CommandArguments ||
            (kind == SferaNativeFieldKind::Bytes && saved.width == 12u))
            writeReference(offset, std::move(saved.value));
    }
    return true;
}
std::span<std::uint8_t> SferaNativeScratch::view(const std::shared_ptr<SferaNativeObject> &object, std::uint32_t offset, std::size_t count)
{
    for (auto &buffer : buffers_)
        if (buffer.object == object)
            return std::span(buffer.bytes).subspan(offset, count);
    if (auto bytes = object->contiguous(offset, count); !bytes.empty() || count == 0)
        return bytes;
    auto initial = object->serialize();
    auto &buffer = buffers_.emplace_back(Buffer{object, initial, std::move(initial)});
    return std::span(buffer.bytes).subspan(offset, count);
}

void SferaNativeScratch::flush()
{
    for (auto &buffer : buffers_)
    {
        buffer.object->importChanges(buffer.initial, buffer.bytes);
        buffer.initial = buffer.bytes;
    }
}

std::uint32_t SferaNativeScratch::findAddress(const void *data, std::size_t count) const
{
    const auto address = reinterpret_cast<std::uintptr_t>(data);
    for (const auto &buffer : buffers_)
    {
        const auto base = reinterpret_cast<std::uintptr_t>(buffer.bytes.data());
        if (address >= base && address - base <= buffer.bytes.size() && count <= buffer.bytes.size() - (address - base))
            return buffer.object->address() + static_cast<std::uint32_t>(address - base);
    }
    return 0;
}

void SferaNativeObject::visitOwners(const std::function<void(std::shared_ptr<SferaNativeObject> &)> &visitor)
{
    for (auto &field : fields_)
    {
        if (field.kind == SferaNativeFieldKind::References)
            for (auto &reference : std::get<std::vector<SferaSliceReference32>>(field.payload))
                visitor(reference.owner);
        else if (field.kind == SferaNativeFieldKind::CommandArguments)
            for (auto &argument : std::get<std::vector<SferaCommandArgument>>(field.payload))
                if (auto *reference = std::get_if<SferaSliceReference32>(&argument))
                    visitor(reference->owner);
    }
}

void SferaNativeAddressSpace::collectCycles()
{
    // Trial deletion at a scheduler boundary. Coroutine locals, native call
    // arguments, module states and external leases are ordinary shared roots.
    // Only edges stored inside native objects are subtracted from use_count.
    std::vector<std::shared_ptr<SferaNativeObject>> objects;
    collection_requested_ = false;
    collection_ticks_ = 0;
    if (reference_objects_.empty())
        return;
    objects.reserve(reference_objects_.size());
    std::unordered_map<SferaNativeObject *, std::size_t> indexes;
    indexes.reserve(reference_objects_.size());
    for (auto *candidate : reference_objects_)
        if (auto object = candidate->weak_from_this().lock())
        {
            indexes.emplace(object.get(), objects.size());
            objects.push_back(std::move(object));
        }
    std::vector<std::size_t> incoming(objects.size());
    std::vector<std::vector<std::size_t>> edges(objects.size());
    for (std::size_t i = 0; i < objects.size(); ++i)
        objects[i]->visitOwners([&](auto &owner)
        {
            const auto found = indexes.find(owner.get());
            if (found != indexes.end())
            {
                ++incoming[found->second];
                edges[i].push_back(found->second);
            }
        });
    std::vector<bool> reachable(objects.size());
    std::vector<std::size_t> pending;
    for (std::size_t i = 0; i < objects.size(); ++i)
        if (objects[i].use_count() > static_cast<long>(incoming[i] + 1))
        {
            reachable[i] = true;
            pending.push_back(i);
        }
    while (!pending.empty())
    {
        const auto index = pending.back();
        pending.pop_back();
        for (const auto target : edges[index])
            if (!reachable[target])
            {
                reachable[target] = true;
                pending.push_back(target);
            }
    }
    for (std::size_t i = 0; i < objects.size(); ++i)
    {
        if (!reachable[i])
            objects[i]->visitOwners([](auto &owner) { owner.reset(); });
        bool hasOwner = false;
        objects[i]->visitOwners([&](auto &owner) { hasOwner |= static_cast<bool>(owner); });
        if (!hasOwner)
            reference_objects_.erase(objects[i].get());
    }
}

void SferaNativeAddressSpace::collectCyclesIfNeeded()
{
    // Root lifetimes can end without modifying an object, so retain a bounded
    // periodic fallback. Unloading requests collection at the next safe boundary.
    if (reference_objects_.empty())
        return;
    if (collection_requested_ || ++collection_ticks_ >= 64)
        collectCycles();
}

void SferaNativeScratch::synchronize()
{
    flush();
    for (auto &buffer : buffers_)
    {
        buffer.initial = buffer.object->serialize();
        std::copy(buffer.initial.begin(), buffer.initial.end(), buffer.bytes.begin());
    }
}
