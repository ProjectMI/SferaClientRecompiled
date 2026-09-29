#include "script/NativeContext.h"
#include "script/MbcRuntime.h"

#include <algorithm>
#include <bit>
#include <stdexcept>
#include <string>

SferaNativeModuleState::SferaNativeModuleState(const SferaNativeModule &declaration, const std::shared_ptr<SferaNativeAddressSpace> &addressSpace)
    : module(&declaration), objects(declaration.object_types.size()), space(addressSpace),
      integers(declaration.integer_count), reals(declaration.real_count), bytes(declaration.byte_count)
{
    if (declaration.initial_integers.size() > integers.size() || declaration.initial_reals.size() > reals.size() ||
        declaration.initial_bytes.size() > bytes.size())
        throw std::invalid_argument("Native scalar initializer exceeds its module field storage");
    std::copy(declaration.initial_integers.begin(), declaration.initial_integers.end(), integers.begin());
    std::transform(declaration.initial_reals.begin(), declaration.initial_reals.end(), reals.begin(),
        [](std::uint32_t word) { return std::bit_cast<float>(word); });
    std::copy(declaration.initial_bytes.begin(), declaration.initial_bytes.end(), bytes.begin());
}

const std::shared_ptr<SferaNativeObject> &SferaNativeModuleState::object(std::size_t index) const
{
    if (!hasObject(index))
        throw std::out_of_range("Unknown native global field");
    auto &slot = objects[index];
    if (!slot)
        slot = space->create(SferaNativeCatalog::objectType(module->object_types[index]));
    return slot;
}

SferaSliceReference32 SferaNativeModuleState::reference(std::uint32_t access, std::uint32_t width) const
{
    return object(SferaNativeGlobalAccess::object(access))->reference(SferaNativeGlobalAccess::offset(access), width);
}

SferaNativeContext::SferaNativeContext(SferaMbcRuntime &owner, const SferaNativeBinding &binding, std::string_view function)
    : runtime(&owner), globals(binding.storage), function_name(function), program_base(binding.program_base),
      binding_index(binding.binding_index), process_id(owner.active_process->process_id), process_lifetime(owner.active_process->lifetime)
{
}

SferaNativeContext::SferaNativeContext(const SferaNativeContext &) noexcept = default;
SferaNativeContext::SferaNativeContext(SferaNativeContext &&) noexcept = default;
SferaNativeContext &SferaNativeContext::operator=(const SferaNativeContext &) noexcept = default;
SferaNativeContext &SferaNativeContext::operator=(SferaNativeContext &&) noexcept = default;
SferaNativeContext::~SferaNativeContext() noexcept = default;

void SferaNativeContext::checkpoint(std::uint32_t ordinal, std::uint32_t cost) const
{
    runtime->source_module = globals->module;
    runtime->source_function = function_name;
    runtime->native_checkpoint = ordinal;
    charge(cost);
}

void SferaNativeContext::charge(std::uint32_t cost) const
{
    const auto total = static_cast<std::uint64_t>(runtime->instruction_step_count) + cost;
    if (total > 3500001u)
    {
        runtime->instruction_step_count = 3500002;
        throw SferaNativeBudgetExceeded{};
    }
    runtime->instruction_step_count = static_cast<int>(total);
    if (runtime->execution_failed)
        throw SferaNativeExecutionFailed{};
    if (runtime->active_process == nullptr || runtime->active_process->process_id != process_id || runtime->active_process->lifetime != process_lifetime)
        fail("Native call resumed in a different process lifetime");
}

std::uint32_t SferaNativeContext::word(std::uint32_t access) const
{
    const auto offset = SferaNativeGlobalAccess::offset(access);
    if (runtime->native_call != nullptr)
        runtime->native_call->scratch.synchronize();
    return globals->object(SferaNativeGlobalAccess::object(access))->readWord(offset);
}

std::uint32_t SferaNativeContext::signedByte(std::uint32_t access) const
{
    const auto offset = SferaNativeGlobalAccess::offset(access);
    if (runtime->native_call != nullptr)
        runtime->native_call->scratch.synchronize();
    const auto byte = globals->object(SferaNativeGlobalAccess::object(access))->readWord(offset, 1);
    return static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(byte)));
}

void SferaNativeContext::setWord(std::uint32_t access, std::uint32_t word, std::uint32_t width) const
{
    const auto offset = SferaNativeGlobalAccess::offset(access);
    if (runtime->native_call != nullptr)
        runtime->native_call->scratch.synchronize();
    globals->object(SferaNativeGlobalAccess::object(access))->writeWord(offset, word, width);
    if (runtime->native_call != nullptr)
        runtime->native_call->scratch.synchronize();
}

SferaMbcValue SferaNativeContext::global(SferaMbcValueType type, std::uint32_t access) const
{
    SferaMbcValue value{};
    runtime->readValue(value, type, globals->reference(access, SferaNativeValues::referenceWidth(type)), true, true);
    return value;
}

SferaMbcValue SferaNativeContext::span(SferaMbcValueType type, std::uint32_t access, std::uint32_t length, bool lvalue) const
{
    SferaMbcValue value{};
    value.type = type;
    value.width = SferaSliceReference32::scriptWidth;
    value.value = globals->reference(access, length);
    if (lvalue)
        value.source = value.value;
    else
        value.detach();
    return value;
}

void SferaNativeContext::store(SferaMbcValue &left, const SferaMbcValue &right) const
{
    runtime->storeValue(left, right);
}

void SferaNativeContext::dereference(SferaMbcValue &value) const
{
    runtime->dereferenceValue(value);
}

void SferaNativeContext::indexAbsolute(SferaMbcValue &index, SferaMbcValueType type, std::uint32_t access, std::uint16_t stride,
                                      std::int32_t count, std::uint32_t span) const
{
    const auto base = globals->reference(access, 0);
    auto reference = runtime->indexedReference(stride, index.asInteger(), count, base.base, span, nullptr);
    reference.owner = base.owner;
    runtime->readValue(index, type, reference, count < 0);
}

void SferaNativeContext::indexRelative(SferaMbcValue &index, const SferaMbcValue &source, SferaMbcValueType type, std::uint16_t stride,
                                      std::int32_t count, bool checked) const
{
    auto reference = source.value;
    if (checked)
        reference = runtime->indexedReference(stride, index.asInteger(), count, 0, 0, &reference);
    else
        runtime->advanceReference(reference, index.asWord() * stride);
    runtime->readValue(index, type, reference, !checked || count < 0);
}

void SferaNativeContext::member(SferaMbcValue &value, SferaMbcValueType type, std::uint32_t displacement, std::uint32_t width, bool span) const
{
    auto reference = value.value;
    runtime->advanceReference(reference, displacement);
    const auto extent = span || type == SferaMbcValueTypeAddress ? width : SferaNativeValues::referenceWidth(type);
    reference.begin = reference.base;
    reference.end = reference.base + extent - 1u;
    if (span)
    {
        value.type = type;
        value.value = reference;
        value.width = SferaSliceReference32::scriptWidth;
        value.detach();
    }
    else
        runtime->readValue(value, type, reference, true);
}

void SferaNativeContext::change(SferaMbcValue &value, bool increment, bool prefix) const
{
    runtime->changeValue(value, increment, prefix);
}

void SferaNativeContext::changePointer(SferaMbcValue &value, std::uint16_t stride, bool increment, bool prefix) const
{
    runtime->changePointer(value, stride, increment, prefix);
}

void SferaNativeContext::validateParameters(std::span<const SferaMbcValue> arguments, int declaration) const
{
    const auto capacity = static_cast<std::size_t>(declaration < 0 ? -declaration : declaration);
    if ((declaration >= 0 && arguments.size() != capacity) || arguments.size() > capacity)
        fail("Wrong number of native function parameters");
}

void SferaNativeContext::parameter(std::span<const SferaMbcValue> arguments, std::size_t index, SferaMbcValueType type, std::uint32_t access) const
{
    SferaMbcValue value{};
    const auto supplied = index < arguments.size() ? arguments[index] : SferaMbcValue{};
    value.type = type;
    value.width = SferaNativeValues::referenceWidth(type);
    value.source = globals->reference(access, static_cast<std::uint32_t>(value.width));
    // Parameters retain the callee's declared type, including numeric conversion.
    if (type == SferaMbcValueTypeReal)
        value.setReal(supplied.asReal());
    else if (type == SferaMbcValueTypeInteger || type == SferaMbcValueTypeByte)
        value.value = {supplied.asWord(), 0, 0};
    else
        value.value = runtime->ownReference(supplied.isPointer() || supplied.type == SferaMbcValueTypeAddress ? supplied.value : SferaSliceReference32{supplied.asWord(), 0, 0});
    runtime->storeValue(value, value);
}

SferaNativeEntry SferaNativeContext::exportEntry(std::uint32_t symbol, std::span<const std::uint64_t> providers, SferaNativeCallable knownCallable) const
{
    // Retain the scheduling cost of the eliminated import instruction.
    charge(1);
    auto *process = runtime->active_process;
    const auto target = process->selectExport(binding_index, symbol, providers, knownCallable);
    if (!target.valid())
    {
        runtime->reportError("Native dependency is not active: ", SferaNativeCatalog::symbolName(symbol));
        throw SferaNativeExecutionFailed{};
    }
    return target;
}

SferaNativeContext SferaNativeContext::exportContext(SferaNativeEntry entry) const
{
    if (!entry.valid() || entry.binding_index >= runtime->active_process->native_bindings.size())
        throw std::out_of_range("Invalid native dependency entry");
    return SferaNativeContext(*runtime, runtime->active_process->native_bindings[entry.binding_index]);
}

void SferaNativeContext::restartProgram(std::uint32_t index, bool child) const
{
    index += program_base;
    auto &process = *runtime->active_process;
    if (index >= process.programs.size())
        fail("Invalid program restart");
    auto &program = process.programs[index];
    if (program.state < 0)
        process.linkProgram(index);
    program.state = 1;
    program.caller_program = child ? runtime->program_index : -1;
    program.select(program.entry);
    process.programs_queued = true;
    runtime->enqueueProcess(static_cast<int>(process_id), process);
}

void SferaNativeContext::activateProgram(std::uint32_t index) const
{
    auto &process = *runtime->active_process;
    if (!process.activateProgram(program_base + index))
        fail("Invalid program activation");
    runtime->enqueueProcess(static_cast<int>(process_id), process);
}

void SferaNativeContext::pauseProgram(std::uint32_t index) const
{
    runtime->active_process->programs.at(program_base + index).state = 0;
}

void SferaNativeContext::stopEntry(std::uint32_t index) const
{
    auto &program = runtime->active_process->programs.at(program_base + index);
    program.select(program.stop);
}

[[noreturn]] void SferaNativeContext::fail(const char *message) const
{
    runtime->reportError(message);
    throw SferaNativeExecutionFailed{};
}
