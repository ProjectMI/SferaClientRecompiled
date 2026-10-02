#include <windows.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <d3d9.h>
#include <format>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <utility>

#include "animation/Animation.h"
#include "application/ClientApplication.h"
#include "binary/Binary.h"
#include "collision/Collision.h"
#include "diagnostics/ClientDiagnostics.h"
#include "effects/ActiveEffect.h"
#include "effects/Effect.h"
#include "effects/EffectManager.h"
#include "gameplay/ActorMotion.h"
#include "input/DirectInputDevices.h"
#include "math/Color.h"
#include "math/Vector.h"
#include "network/Network.h"
#include "numeric/Numeric.h"
#include "players/PlayerLists.h"
#include "render/CharacterRenderer.h"
#include "scene/SceneObject.h"
#include "script/MbcCommands.h"
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"
#include "script/MbcValue.h"
#include "script/ScriptContainer.h"
#include "text/Fonts.h"
#include "text/Text.h"
#include "text/TextBuffer.h"
#include "ui/ScriptInterface.h"
#include "world/WorldObjects.h"

void SferaMbcRuntime::checkEngineFailure() const
{
    if (current.module && !alive(*current.module))
        throw std::runtime_error("Engine call from an expired native script");
    if (execution_failed)
        throw std::runtime_error(first_execution_error.empty() ? "Native script engine call failed" : first_execution_error);
}

std::int32_t SferaMbcRuntime::processModule(std::uint32_t id) const
{
    const bool valid = id < std::size(processes) && processes[id].process_id == id && processes[id].chain_prev_index >= 0;
    return SphereScripts::integerBits(valid ? processes[id].module_tag : UINT32_MAX);
}

std::int32_t SferaMbcRuntime::tickValue() const
{
    return SphereScripts::integerBits(simulation_tick);
}

std::int32_t SferaMbcRuntime::keyState(std::uint32_t key) const
{
    return SferaClientApplication::application_active && key < std::size(g_sfera_direct_input_runtime.keyboard_state)
               ? SferaNumeric::signedByte(g_sfera_direct_input_runtime.keyboard_state[key]) : 0;
}

std::string SferaMbcRuntime::stringValue(SphereScripts::Address value, std::size_t limit) const
{
    return textIn({value.base, value.begin, value.end}, limit);
}

void SferaMbcRuntime::setAnimation(std::int32_t handle, std::int32_t value, bool secondary)
{
    checkEngineFailure();
    auto *field = secondary ? SphereRenderModelPose::secondaryAnimation(handle) : SphereRenderModelPose::animation(handle);
    if (field != nullptr)
        *field = value;
    checkEngineFailure();
}

void SferaMbcRuntime::setFrame(std::int32_t handle, std::int32_t value, bool secondary)
{
    checkEngineFailure();
    auto *field = secondary ? SphereRenderModelPose::secondaryFrame(handle) : SphereRenderModelPose::frame(handle);
    if (field != nullptr)
        *field = value;
    checkEngineFailure();
}

std::int32_t SferaMbcRuntime::animationLength(std::int32_t handle, std::int32_t animation)
{
    checkEngineFailure();
    const auto result = SphereRenderModelPose::animationLength(handle, animation);
    checkEngineFailure();
    return SphereScripts::integerBits(result);
}

void SferaMbcRuntime::setInterpolation(std::int32_t handle, float value)
{
    checkEngineFailure();
    if (auto *field = SphereRenderModelPose::interpolation(handle))
        *field = value;
    checkEngineFailure();
}

std::int32_t SferaMbcRuntime::objectProcess(std::int32_t handle)
{
    checkEngineFailure();
    const auto *object = handle >= 0 ? g_sfera_world_objects.object(handle, "GetProcess") : nullptr;
    const auto *owner = object != nullptr ? WorldObjects::boundProcess(*object) : nullptr;
    checkEngineFailure();
    return SphereScripts::integerBits(owner != nullptr ? owner->process_id : UINT32_MAX);
}

WorldObject *SferaMbcRuntime::selectWorldObject(std::int32_t handle)
{
    checkEngineFailure();
    if (handle < 0)
        return nullptr;
    current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
    if (current_object == nullptr)
        active_tag = UINT32_MAX;
    checkEngineFailure();
    return current_object;
}

void SferaMbcRuntime::trackControlledPosition(std::int32_t handle, const WorldObject &object)
{
    if (SferaNumeric::word(handle) == g_sfera_world_objects.controlled_object_handle)
        g_sfera_motion.tracked_position = {object.position.x + 333.0f, object.position.y + 333.0f, object.position.z + 333.0f};
}

void SferaMbcRuntime::setPosition(std::int32_t handle, SferaVec3F value, bool updateSpatial,
                                  std::optional<std::int32_t> membership)
{
    if (auto *object = selectWorldObject(handle))
    {
        object->position = value;
        trackControlledPosition(handle, *object);
        if (updateSpatial)
        {
            g_sfera_world_objects.updateSpatialIndex(handle);
            if (membership)
                object->spatial_membership = *membership;
        }
    }
    checkEngineFailure();
}

void SferaMbcRuntime::moveWorld(std::int32_t handle, SferaVec3F value)
{
    if (auto *object = selectWorldObject(handle))
    {
        object->position = object->position + value;
        trackControlledPosition(handle, *object);
    }
    checkEngineFailure();
}

void SferaMbcRuntime::setRotation(std::int32_t handle, SferaVec3F value)
{
    checkEngineFailure();
    if (handle < 0)
        return;
    auto *object = g_sfera_world_objects.object(handle, "GetObjectPointer");
    if (object == nullptr)
        active_tag = UINT32_MAX;
    else if (!execution_failed)
        object->rotation = value;
    checkEngineFailure();
}

void SferaMbcRuntime::moveLocal(std::int32_t handle, SferaVec3F value)
{
    checkEngineFailure();
    g_sfera_world_objects.moveLocal(handle, value);
    checkEngineFailure();
}

void SferaMbcRuntime::rotateObject(std::int32_t handle, SferaVec3F value)
{
    checkEngineFailure();
    g_sfera_world_objects.rotate(handle, value);
    checkEngineFailure();
}

void SferaMbcRuntime::setCommandVelocity(std::int32_t handle, float x, float z, std::optional<float> y)
{
    if (auto *object = selectWorldObject(handle))
    {
        auto *extended = SphereRenderCharacterModels::checkedExtended(object);
        extended->commanded_velocity.x = x;
        extended->commanded_velocity.z = z;
        if (y)
            extended->commanded_velocity.y = *y;
    }
    checkEngineFailure();
}

void SferaMbcRuntime::setVerticalVelocity(std::int32_t handle, float value)
{
    if (auto *object = selectWorldObject(handle))
        SphereRenderCharacterModels::checkedExtended(object)->physical_velocity.y = value;
    checkEngineFailure();
}

void SferaMbcRuntime::setVerticalResponse(std::int32_t handle, std::int32_t response)
{
    if (auto *object = selectWorldObject(handle))
        SphereRenderCharacterModels::checkedExtended(object)->physical_velocity.y = g_sfera_motion.responseValue(response);
    checkEngineFailure();
}

void SferaMbcRuntime::setAngularVelocity(std::int32_t handle, float value)
{
    if (auto *object = selectWorldObject(handle))
        SphereRenderCharacterModels::checkedExtended(object)->angular_velocity = value;
    checkEngineFailure();
}

std::optional<SferaVec3F> SferaMbcRuntime::objectPosition(std::int32_t handle)
{
    const auto *object = selectWorldObject(handle);
    return object != nullptr ? std::optional{object->position} : std::nullopt;
}

std::optional<SferaVec3F> SferaMbcRuntime::objectRotation(std::int32_t handle)
{
    const auto *object = selectWorldObject(handle);
    return object != nullptr ? std::optional{object->rotation} : std::nullopt;
}

std::optional<SferaVec3F> SferaMbcRuntime::objectBasis(std::int32_t handle)
{
    auto *object = selectWorldObject(handle);
    if (object == nullptr)
        return std::nullopt;
    const auto *extended = SphereRenderCharacterModels::checkedExtended(object);
    g_sfera_world_objects.recalculateBasis(handle);
    checkEngineFailure();
    return extended->orientation_basis[0];
}

float SferaMbcRuntime::positionComponent(std::int32_t handle, std::size_t axis)
{
    checkEngineFailure();
    const auto *object = g_sfera_world_objects.object(handle, "GetPos");
    checkEngineFailure();
    return object != nullptr ? object->position.component(axis) : 0.0f;
}

float SferaMbcRuntime::rotationComponent(std::int32_t handle, std::size_t axis)
{
    checkEngineFailure();
    const auto *object = g_sfera_world_objects.object(handle, "GetAngles");
    checkEngineFailure();
    return object != nullptr ? object->rotation.component(axis) : 0.0f;
}

void SferaMbcRuntime::setRenderEnabled(std::int32_t handle, bool enabled)
{
    checkEngineFailure();
    if (handle >= 0)
    {
        auto *object = SphereRenderCharacterModels::checkedExtended(g_sfera_world_objects.object(handle, "GetObjectPointer"));
        if (object != nullptr)
            object->render_enabled = enabled;
    }
    checkEngineFailure();
}

void SferaMbcRuntime::destroyObject(std::int32_t handle)
{
    checkEngineFailure();
    if (handle != -1)
        g_sfera_world_objects.destroy(handle);
    active_process->unregisterResource(handle, SferaMbcRuntimeResourceKind::worldObject);
    checkEngineFailure();
}

void SferaMbcRuntime::destroyText(std::int32_t handle)
{
    checkEngineFailure();
    if (handle >= 0)
        WorldGuiControls::destroyText(handle);
    active_process->unregisterResource(handle, SferaMbcRuntimeResourceKind::textControl);
    checkEngineFailure();
}

void SferaMbcRuntime::destroySprite(std::int32_t handle)
{
    checkEngineFailure();
    if (handle >= 0)
        WorldGuiControls::destroySprite(handle);
    active_process->unregisterResource(handle, SferaMbcRuntimeResourceKind::spriteControl);
    checkEngineFailure();
}

std::int32_t SferaMbcRuntime::createObject(std::string_view name, std::uint32_t kind, std::int32_t independent)
{
    checkEngineFailure();
    static constexpr std::array<std::uint32_t, 11> factories{0, 1, 2, 3, 1, 4, 5, 6, 4, 5, 3};
    const auto factory = kind < factories.size() ? factories[kind] : 0;
    const std::string filename(name);
    const auto handle = g_sfera_world_objects.create(filename, independent == 1 ? nullptr : active_process, factory, independent != 1);
    if (SferaNumeric::signedWord(handle) < 0)
    {
        reportError(std::format("Error creating object: {}", filename));
        execution_failed = false;
        return SferaNumeric::signedWord(handle);
    }
    current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
    if (current_object->extended())
    {
        auto &extended = *current_object->extended();
        extended.simulation_enabled = kind == 10;
        extended.full_rate_simulation = (kind >= 1 && kind <= 4) || kind == 10;
        extended.gravity_enabled = kind == 2 || kind == 3 || kind == 5 || kind == 6 || kind == 10;
    }
    try
    {
        active_process->registerResource(handle, SferaMbcRuntimeResourceKind::worldObject);
    }
    catch (...)
    {
        g_sfera_world_objects.destroy(handle);
        throw;
    }
    checkEngineFailure();
    return SferaNumeric::signedWord(handle);
}

auto SferaMbcRuntime::executeBuiltinText(int offset)
{
    return textAt(offset);
}

auto SferaMbcRuntime::executeBuiltinName(int offset)
{
    return textAt(offset, 149);
}

auto SferaMbcRuntime::executeBuiltinLookup(PlayerLists &manager, int offset)
{
    return manager.find(executeBuiltinName(offset));
}

auto SferaMbcRuntime::executeBuiltinCopyName(std::uint32_t address, std::string_view value)
{
    auto *output = memoryAt(address, value.size() + 1);
    std::copy(value.begin(), value.end(), output);
    output[value.size()] = 0;
}

bool SferaMbcRuntime::activeEffectMatches(const SferaActiveEffect *created, const std::shared_ptr<SferaActiveEffect> &item)
{
    return item.get() == created;
}

bool SferaMbcRuntime::executeBuiltin(SferaMbcRuntimeBuiltin builtin)
{
    switch (builtin)
    {
    case SferaMbcRuntimeBuiltin::ContainerCommand:
    {
        auto *container = nativeResource<SferaScriptContainer *>(nextWord());
        if (container == nullptr)
            pushInteger(UINT32_MAX);
        else if (container->header.kind >= SferaDataContainerHeaderKind::List && container->header.kind <= SferaDataContainerHeaderKind::HashMap)
            container->execute(*this);
        break;
    }
    case SferaMbcRuntimeBuiltin::ContainerManagement:
    {
        const auto command = SferaNumeric::enumFromBits<SferaScriptContainerLifecycle>(nextInteger());
        if (command == SferaScriptContainerLifecycle::Create)
        {
            const auto kind = SferaNumeric::enumFromBits<SferaScriptContainerKind>(SferaNumeric::word(nextInteger()));
            if (kind < SferaScriptContainerKind::List || kind > SferaScriptContainerKind::HashMap)
            {
                pushInteger(0);
                break;
            }
            const auto keyType = kind == SferaScriptContainerKind::Map || kind == SferaScriptContainerKind::HashMap
                                     ? SferaNumeric::enumFromBits<SferaScriptContainerValueType>(SferaNumeric::word(nextInteger()))
                                     : SferaScriptContainerValueType::Integer;
            const auto valueType = SferaNumeric::enumFromBits<SferaScriptContainerValueType>(SferaNumeric::word(nextInteger()));
            auto container = SferaScriptContainer::create(kind, valueType, keyType);
            std::uint32_t handle = 0;
            if (container)
            {
                auto *pointer = container.get();
                try
                {
                    handle = nativeHandle(pointer);
                    containers.emplace(handle, std::move(container));
                    active_process->registerResource(handle, SferaMbcRuntimeResourceKind::container);
                }
                catch (...)
                {
                    forgetNativeResource(pointer);
                    containers.erase(handle);
                    throw;
                }
            }
            pushInteger(handle);
            break;
        }
        if (command < SferaScriptContainerLifecycle::Destroy || command > SferaScriptContainerLifecycle::KeyType)
        {
            pushInteger(UINT32_MAX);
            break;
        }
        const std::uint32_t handle = nextInteger();
        if (command == SferaScriptContainerLifecycle::Destroy)
            active_process->unregisterResource(handle, SferaMbcRuntimeResourceKind::container);
        auto *container = nativeResource<SferaScriptContainer *>(handle);
        if (container == nullptr)
        {
            pushInteger(UINT32_MAX);
            break;
        }
        const auto kind = container->header.kind;
        switch (command)
        {
        case SferaScriptContainerLifecycle::Destroy:
            if (kind >= SferaScriptContainerKind::List && kind <= SferaScriptContainerKind::HashMap)
            {
                destroyContainer(handle);
                pushInteger(0);
            }
            else
                pushInteger(UINT32_MAX);
            break;
        case SferaScriptContainerLifecycle::Kind:
            pushInteger(SferaNumeric::enumBits(kind));
            break;
        case SferaScriptContainerLifecycle::ValueType:
            pushInteger(kind == SferaScriptContainerKind::List || kind == SferaScriptContainerKind::Vector || kind == SferaScriptContainerKind::Map || kind == SferaScriptContainerKind::HashMap
                            ? SferaNumeric::enumBits(container->value_type)
                            : UINT32_MAX);
            break;
        case SferaScriptContainerLifecycle::KeyType:
            pushInteger(kind == SferaScriptContainerKind::Set                                                ? SferaNumeric::enumBits(container->value_type)
                        : kind == SferaScriptContainerKind::Map || kind == SferaScriptContainerKind::HashMap ? SferaNumeric::enumBits(container->key_type)
                                                                                                             : UINT32_MAX);
            break;
        default:
            break;
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::System:
        systemCommand();
        break;
    case SferaMbcRuntimeBuiltin::Reserved122:
        break;
    case SferaMbcRuntimeBuiltin::FindProcess:
    {
        const bool byName = g_sfera_mbc_runtime.engine_arguments[argument_cursor].type == SferaMbcValueTypeBytePointer;
        std::string name;
        std::uint32_t module = 0;
        if (byName)
        {
            const auto slice = nextSliceReference();
            if (slice.base == 0)
                WorldDiagnostics::warning("NULL-pointer dereferencing: ffprc_id\n");
            name = textIn(slice);
        }
        else
            module = nextInteger();
        auto index = process_chain_first;
        if (argument_count > 1)
        {
            const std::uint32_t previous = nextInteger();
            if (previous >= std::size(processes) || SferaNumeric::word(processes[previous].chain_next_index) == previous)
            {
                pushInteger(-1);
                break;
            }
            index = processes[previous].chain_next_index;
        }
        if (execution_failed)
            break;
        int result = -1;
        for (std::size_t visited = 0; visited < std::size(processes) && index >= 0 && index < std::size(processes); ++visited)
        {
            const auto &process = processes[index];
            if (process.chain_prev_index == -1)
                break;
            if (byName ? name == process.name : module == 0 || process.module_tag == module)
            {
                result = process.process_id;
                break;
            }
            if (process.chain_next_index == index)
                break;
            index = process.chain_next_index;
        }
        pushInteger(result);
        break;
    }
    case SferaMbcRuntimeBuiltin::AllocateMemory:
    {
        const auto size = nextInteger();
        if (execution_failed)
            break;
        if (size <= 0)
            pushInteger(0);
        else
        {
            const auto offset = active_process->growMemory(size);
            pushSlice({offset, offset, offset + size - 1}, SferaMbcValueTypeBytePointer);
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::AllocateDynamic:
    case SferaMbcRuntimeBuiltin::FreeDynamic:
    {
        const auto reference = nextSliceReference();
        const auto size = builtin == SferaMbcRuntimeBuiltin::AllocateDynamic ? nextInteger() : 0;
        if (execution_failed)
            break;
        if (!reference.contains(sizeof(SferaSliceReference32)))
        {
            reportError("Dynamic array reference outside slice");
            break;
        }
        // Validate the entire lvalue before creating or destroying any allocation.
        auto *destination = memoryAt(reference.base, sizeof(SferaSliceReference32));
        SferaSliceReference32 previous{};
        std::memcpy(&previous, destination, sizeof(previous));
        if (builtin == SferaMbcRuntimeBuiltin::AllocateDynamic)
        {
            const auto offset = size > 0 ? allocateDynamic(size) : 0u;
            try
            {
                if (offset != 0)
                    active_process->registerResource(reference.base, SferaMbcRuntimeResourceKind::dynamicArray);
            }
            catch (...)
            {
                releaseDynamic(offset);
                throw;
            }
            const SferaSliceReference32 replacement{offset, offset, offset == 0 ? 0u : offset + size - 1u};
            std::memcpy(destination, &replacement, sizeof(replacement));
            // Replacement is transactional; an old owned allocation cannot leak.
            if (previous.base != 0)
                releaseDynamic(previous.base);
            if (offset == 0)
                active_process->unregisterResource(reference.base, SferaMbcRuntimeResourceKind::dynamicArray);
        }
        else if (previous.base != 0)
        {
            if (!releaseDynamic(previous.base))
            {
                reportError("Dynamic array does not own this address");
                break;
            }
            const SferaSliceReference32 empty{};
            std::memcpy(destination, &empty, sizeof(empty));
            active_process->unregisterResource(reference.base, SferaMbcRuntimeResourceKind::dynamicArray);
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::CopyProcessMemory:
    case SferaMbcRuntimeBuiltin::CopyProcessString:
    {
        const std::uint32_t destinationProcess = nextInteger();
        auto &destination = nextSliceReference();
        if (destination.base == 0)
        {
            ::OutputDebugStringA("NULL-pointer dereferencing: ffmempcpy\n");
            break;
        }
        const std::uint32_t sourceProcess = nextInteger();
        const auto &source = nextSliceReference();
        const auto count = builtin == SferaMbcRuntimeBuiltin::CopyProcessMemory || argument_count == 5 ? nextInteger() : 0;
        if (execution_failed)
            break;
        auto *target = findProcess(destinationProcess);
        auto *origin = findProcess(sourceProcess);
        if (target == nullptr || origin == nullptr)
        {
            active_tag = UINT32_MAX;
            pushInteger(UINT32_MAX);
            break;
        }
        if (builtin == SferaMbcRuntimeBuiltin::CopyProcessMemory)
        {
            if (count < 0)
            {
                reportError("Negative process copy length");
                break;
            }
            const auto input = memoryBytes(source.base, count, origin);
            if (!destination.contains(count))
                destination.diagnoseRange(count);
            const auto output = memoryBytes(destination.base, count, target);
            SferaBinary::copy(output, input);
        }
        else
        {
            const auto text = textIn(source, origin);
            copyString(textBuffer(destination, target), text, count);
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::MemoryChecksum:
    {
        nextInteger();
        auto &slice = nextSliceReference();
        const std::uint32_t size = nextInteger();
        if (execution_failed)
            break;
        if (!slice.contains(size))
            slice.diagnoseRange(size);
        pushInteger(0);
        break;
    }
    case SferaMbcRuntimeBuiltin::ReadReal:
    {
        auto source = nextSliceReference();
        auto &destination = nextSliceReference();
        constexpr std::uint32_t width = sizeof(float);
        if (execution_failed)
            break;
        if (!source.contains(width))
        {
            source.diagnoseRange(width);
            break;
        }
        else if (!destination.contains(width))
        {
            destination.diagnoseRange(width);
            break;
        }
        else
        {
            const auto input = sliceBytes(source, width);
            const auto output = memoryBytes(destination.base, width);
            SferaBinary::readPacked(std::as_bytes(input), std::as_writable_bytes(output));
            source.base += width;
        }
        pushSlice(source, SferaMbcValueTypeBytePointer);
        break;
    }
    case SferaMbcRuntimeBuiltin::ReadString:
    {
        auto source = nextSliceReference();
        auto &destination = nextSliceReference();
        if (!source.contains())
        {
            source.diagnoseRange(0);
            break;
        }
        if (execution_failed)
            break;
        const auto input = textIn(source);
        if (input.size() >= UINT32_MAX)
        {
            reportError("String exceeds the MBC address range");
            break;
        }
        const std::uint32_t length = SferaNumeric::lowWord(input.size() + 1u);
        copyText(destination, input);
        if (!source.contains(length))
            source.diagnoseRange(length);
        else
            source.base += length;
        pushSlice(source, SferaMbcValueTypeBytePointer);
        break;
    }
    case SferaMbcRuntimeBuiltin::Connect:
    {
        const auto host = nextSliceReference().base;
        nextSliceReference();
        const auto mode = argument_count > 2 ? nextWord() : 3u;
        pushInteger(g_sfera_network_runtime.initialize(std::string(textAt(host)), mode));
        break;
    }
    case SferaMbcRuntimeBuiltin::Disconnect:
        g_sfera_network_runtime.shutdown();
        break;
    case SferaMbcRuntimeBuiltin::Send:
        buildRegion();
        break;
    case SferaMbcRuntimeBuiltin::Receive:
        receiveRegion();
        break;
    case SferaMbcRuntimeBuiltin::NetworkInitialization:
        pushInteger(g_sfera_network_runtime.initialization_result);
        break;
    case SferaMbcRuntimeBuiltin::PlayerLists:
    {
        const auto command = nextInteger();
        if (command < 1 || command > 11)
            break;
        auto &manager = g_sfera_player_lists;

        switch (command)
        {
        case 1:
        {
            const auto listName = nextInteger();
            const auto minimum = nextInteger();
            nextInteger();
            const auto mode = nextInteger();
            const auto parameter = nextInteger();
            if (!execution_failed)
                pushInteger(manager.create(executeBuiltinName(listName), minimum, mode, parameter != 0));
            break;
        }
        case 2:
        {
            const auto listName = nextInteger();
            if (!execution_failed)
                pushInteger(manager.erase(executeBuiltinName(listName)));
            break;
        }
        case 3:
        {
            const auto listName = nextInteger();
            const auto itemName = nextInteger();
            const auto a = nextInteger();
            const auto b = nextInteger();
            const auto c = nextInteger();
            const auto size = std::clamp(nextInteger(), 0, 256);
            const auto data = nextInteger();
            if (execution_failed)
                break;
            auto *list = executeBuiltinLookup(manager, listName);
            if (list == nullptr)
            {
                pushInteger(-1);
                break;
            }
            PlayerListEntry item;
            item.name = executeBuiltinName(itemName);
            item.attributes = {a, b, c};
            if (size != 0)
            {
                const auto *bytes = memoryAt(data, size);
                item.payload.assign(bytes, bytes + size);
            }
            pushInteger(list->insert(std::move(item)));
            break;
        }
        case 4:
        {
            const auto listName = nextInteger();
            const auto itemName = nextInteger();
            if (execution_failed)
                break;
            auto *list = executeBuiltinLookup(manager, listName);
            if (list == nullptr)
            {
                pushInteger(-1);
                break;
            }
            pushInteger(manager.removeItem(*list, executeBuiltinName(itemName)));
            break;
        }
        case 5:
        case 6:
        case 7:
        {
            const auto first = nextInteger();
            const auto second = command == 6 ? 0 : nextInteger();
            const std::string_view operation = command == 5 ? "L_FFITEM" : command == 6 ? "L_FNITEM" : "L_FINDITEM";
            std::array<int, 4> fields;
            for (std::size_t index = 0; index < fields.size(); ++index)
            {
                fields[index] = nextInteger();
                if (fields[index] == 0 && !(command == 7 && index == 3))
                {
                    std::string message;
                    message = std::format("NULL-pointer dereferencing: list, {}, {}\n", operation, (index + 1));
                    WorldDiagnostics::warning(message);
                }
            }
            const auto payload = nextInteger();
            if (execution_failed)
                break;
            auto *current = command == 6 ? manager.currentList() : manager.selectList(executeBuiltinName(first));
            const auto nameOutput = command == 6 ? first : second;
            if (current == nullptr)
            {
                if (command != 7)
                    executeBuiltinCopyName(nameOutput, {});
                pushInteger(-1);
                break;
            }
            auto *item = command == 7 ? current->find(executeBuiltinName(second)) : command == 5 ? current->first() : current->next();
            if (item == nullptr)
            {
                if (command != 7)
                    executeBuiltinCopyName(nameOutput, {});
                pushInteger(-2);
                break;
            }
            if (command != 7)
                executeBuiltinCopyName(nameOutput, item->name);
            writeMemory(fields[0], item->attributes[0]);
            writeMemory(fields[1], item->attributes[1]);
            writeMemory(fields[2], item->attributes[2]);
            if (command != 7)
                writeMemory(fields[3], SferaNumeric::lowWord(item->payload.size()));
            if (payload != 0 && !item->payload.empty())
                std::copy(item->payload.begin(), item->payload.end(), memoryAt(payload, item->payload.size()));
            if (command == 7)
            {
                if (fields[3] == 0)
                    WorldDiagnostics::warning("NULL-pointer dereferencing: list, L_FINDITEM, 4\n");
                writeMemory(fields[3], SferaNumeric::lowWord(item->payload.size()));
            }
            pushInteger(0);
            break;
        }
        case 8:
        {
            const auto listName = nextInteger();
            const auto output = nextInteger();
            const auto a = nextInteger();
            const auto b = nextInteger();
            const auto c = nextInteger();
            if (execution_failed)
                break;
            auto *list = executeBuiltinLookup(manager, listName);
            const auto *item = list == nullptr ? nullptr : list->select({a, b, c});
            executeBuiltinCopyName(output, item == nullptr ? std::string_view{} : item->name);
            pushInteger(item == nullptr || item->name.empty() ? -1 : 0);
            break;
        }
        case 9:
        {
            const auto listName = nextInteger();
            const auto itemName = nextInteger();
            const float x = nextReal();
            const float y = nextReal();
            const float z = nextReal();
            if (execution_failed)
                break;
            auto *list = executeBuiltinLookup(manager, listName);
            if (list == nullptr)
            {
                pushInteger(-1);
                break;
            }
            auto *item = list->find(executeBuiltinName(itemName));
            if (item == nullptr)
            {
                pushInteger(-1);
                break;
            }
            item->position = {x, y, z};
            pushInteger(list->publish_mode == 1 ? 0 : -1);
            break;
        }
        case 10:
        {
            const auto listName = nextInteger();
            const auto itemName = nextInteger();
            std::array<int, 3> outputs;
            for (std::size_t index = 0; index < outputs.size(); ++index)
            {
                outputs[index] = nextInteger();
                if (outputs[index] == 0)
                {
                    std::string message;
                    message = std::format("NULL-pointer dereferencing: list, L_FINDITEM, {}\n", (index + 1));
                    WorldDiagnostics::warning(message);
                }
            }
            if (execution_failed)
                break;
            auto *list = manager.selectList(executeBuiltinName(listName));
            if (list == nullptr)
            {
                pushInteger(-2);
                break;
            }
            const auto *item = list->find(executeBuiltinName(itemName));
            if (item == nullptr)
            {
                pushInteger(-1);
                break;
            }
            writeMemory(outputs[0], item->position.x);
            writeMemory(outputs[1], item->position.y);
            writeMemory(outputs[2], item->position.z);
            pushInteger(0);
            break;
        }
        case 11:
            pushInteger(0);
            break;
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::FormatText:
    case SferaMbcRuntimeBuiltin::BoundedFormatText:
        formatText(builtin == SferaMbcRuntimeBuiltin::BoundedFormatText);
        break;
    case SferaMbcRuntimeBuiltin::FormattedLog:
    case SferaMbcRuntimeBuiltin::NamedFormattedLog:
        writeFormattedLog(builtin == SferaMbcRuntimeBuiltin::NamedFormattedLog);
        break;
    case SferaMbcRuntimeBuiltin::FindString:
    {
        auto &haystack = nextSliceReference();
        const auto needle = nextSliceReference();
        if (execution_failed)
            break;
        const auto text = textIn(haystack);
        const auto match = textIn(needle);
        const auto found = text.find(match);
        if (found == std::string_view::npos)
            pushSlice({}, SferaMbcValueTypeBytePointer);
        else
        {
            haystack.base += SferaNumeric::lowWord(found);
            pushSlice(haystack, SferaMbcValueTypeBytePointer);
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::Window:
        windowCommand();
        break;
    case SferaMbcRuntimeBuiltin::FontSettings:
    {
        const auto &suffix = g_sfera_font_runtime.language_suffix;
        const auto offset = mapMemory(suffix.c_str(), suffix.size() + 1);
        pushSlice({offset, offset, offset + SferaNumeric::lowWord(suffix.size())}, SferaMbcValueTypeBytePointer);
        break;
    }
    case SferaMbcRuntimeBuiltin::Text:
    {
        const auto create = g_sfera_mbc_runtime.engine_arguments[argument_cursor].type == SferaMbcValueTypeBytePointer;
        const auto first = nextWord();
        if (!create)
        {
            const auto color = nextInteger();
            const auto style = nextInteger();
            const auto font = nextInteger();
            const auto scale = SferaMbcValue::truncate(nextReal());
            if (execution_failed)
                break;
            auto *window = GameInterface::window(first, "GetWindowPointer");
            if (window == nullptr)
            {
                reportError("Wrong parameters for 'text' function");
                break;
            }
            window->textColor = color;
            window->textStyle = style;
            window->font = font;
            window->fontScale = scale;
            break;
        }
        const auto parent = nextWord();
        const auto x = nextInteger();
        const auto y = nextInteger();
        if (argument_count >= 8)
        {
            auto *window = GameInterface::window(parent, "GetWindowPointer");
            if (window == nullptr)
            {
                reportError("Wrong parameters for 'text' function");
                break;
            }
            window->textColor = nextInteger();
            window->textStyle = nextInteger();
            window->font = nextInteger();
            window->fontScale = SferaMbcValue::truncate(nextReal());
        }
        if (argument_count == 9)
            nextInteger();
        if (execution_failed)
            break;
        const auto text = textAt(first);
        const auto length = text.size();
        if (length >= text_capacity)
        {
            reportError("Script text exceeds text buffer capacity");
            break;
        }
        text_buffer = text.empty() ? std::string_view{"?"} : text;
        const auto handle = WorldGuiControls::createText(x, y, text_buffer, parent);
        pushInteger(handle);
        if (handle != UINT32_MAX)
        {
            try
            {
                active_process->registerResource(handle, SferaMbcRuntimeResourceKind::textControl);
            }
            catch (...)
            {
                WorldGuiControls::destroyText(handle);
                throw;
            }
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::TextColor:
    {
        const auto handle = nextInteger();
        const auto color = nextInteger();
        if (argument_count == 3)
        {
            const auto alpha = nextInteger();
            if (!execution_failed)
                WorldGuiControls::setAppearance(handle, alpha, color);
        }
        else if (!execution_failed)
        {
            auto *control = WorldGuiControls::control(handle);
            if (control == nullptr)
                WorldDiagnostics::fail("text_color: wrong handle");
            control->color = color;
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::Sprite:
    {
        const auto texture = nextInteger();
        const auto parent = nextInteger();
        if (argument_count == 2)
        {
            WorldGuiControls::setAppearance(texture, parent);
            pushInteger(0);
            break;
        }
        const auto x = nextInteger();
        const auto y = nextInteger();
        const auto width = nextInteger();
        const auto height = nextInteger();
        const auto alpha = argument_count > 6 ? nextInteger() : std::numeric_limits<std::uint8_t>::max();
        if (argument_count > 7)
            nextInteger();
        if (argument_count > 8)
            nextInteger();
        if (argument_count > 9)
        {
            nextInteger();
            nextInteger();
        }
        if (execution_failed)
            break;
        const auto handle = WorldGuiControls::createSprite(x, y, width, height, textAt(texture), parent, alpha);
        if (handle < 0)
            reportError("Error creating sprite");
        else
        {
            try
            {
                active_process->registerResource(handle, SferaMbcRuntimeResourceKind::spriteControl);
            }
            catch (...)
            {
                WorldGuiControls::destroySprite(handle);
                throw;
            }
            pushInteger(handle);
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::Effect:
    {
        if (g_sfera_effect_manager.diagnostics.enabled)
            ++g_sfera_effect_manager.diagnostics.vm_requests;
        const auto handle = nextInteger();
        const auto effect = nextWord();
        const auto parameter = argument_count >= 3 ? nextWord() : 0u;
        if (argument_count == 4)
            nextInteger();
        if (execution_failed)
            break;
        SferaActiveEffect *created = nullptr;
        if (argument_count == 4)
        {
            if (handle == 0)
                reportError("Effect attached to zero handle!", "");
            created = g_sfera_effect_manager.createActiveEffect(textAt(effect), handle);
        }
        else
        {
            if (handle <= 0)
            {
                std::string message;
                message = std::format("Wrong Handler for Effect {}\n", active_process->name);
                ::OutputDebugStringA(message.c_str());
                pushInteger(UINT32_MAX);
                break;
            }
            if (argument_count >= 3 && parameter != 0)
            {
                SferaEffectParameter value;
                switch (effect)
                {
                case 1:
                {
                    const auto *bytes = memoryAt(parameter, 6);
                    SferaEffectParameterColor rgb;
                    for (std::size_t channel = 0; channel < rgb.channels.size(); ++channel)
                        rgb.channels[channel] = SferaBinary::readLittleEndian<std::uint16_t>(bytes + channel * 2);
                    value.value = rgb;
                    break;
                }
                case 2:
                    value.value = SferaEffectParameterRadius{readMemory<float>(parameter)};
                    break;
                case 3:
                    value.value = SferaEffectParameterJitter{readMemory<std::uint8_t>(parameter)};
                    break;
                case 4:
                    value.value = SferaEffectParameterFrequency{readMemory<std::uint8_t>(parameter)};
                    break;
                default:
                    break;
                }
                if (!execution_failed)
                    pushInteger(g_sfera_effect_manager.setEffectParameters(handle, {&value, 1}));
                break;
            }
            if (argument_count >= 3 && SferaNumeric::word(handle) == g_sfera_world_objects.controlled_object_handle)
            {
                pushInteger(UINT32_MAX);
                break;
            }
            created = g_sfera_effect_manager.createActiveEffect(effect, handle);
        }
        if (created == nullptr)
        {
            pushInteger(UINT32_MAX);
            break;
        }
        try
        {
            pushInteger(nativeHandle(created));
        }
        catch (...)
        {
            auto &manager = g_sfera_effect_manager;
            const auto found = std::find_if(manager.active_effects.begin(), manager.active_effects.end(), std::bind_front(&SferaMbcRuntime::activeEffectMatches, created));
            if (found != manager.active_effects.end())
            {
                const auto rollback = *found;
                try
                {
                    manager.removeActiveEffect(rollback.get());
                }
                catch (...)
                {
                }
                manager.retireEffect(*rollback);
            }
            throw;
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::Airborne:
    {
        const auto handle = nextInteger();
        if (handle < 0)
        {
            pushInteger(0);
            break;
        }
        auto *object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
        if (object == nullptr)
        {
            active_tag = UINT32_MAX;
            break;
        }
        if (execution_failed)
            break;
        const auto command = nextInteger();
        auto *extended = SphereRenderCharacterModels::checkedExtended(object);
        if (command == -1)
            pushInteger(extended->airborne);
        else
        {
            extended->airborne = true;
            pushInteger(0);
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::ObjectRotation:
    {
        const auto handle = nextInteger();
        if (handle < 0 || selectWorldObject(handle) == nullptr)
            break;
        const auto destination = nextInteger();
        if (execution_failed)
            break;
        const auto value = objectRotation(handle);
        if (!value)
            break;
        if (destination == 0)
            WorldDiagnostics::warning("NULL-pointer dereferencing: ffg_abg\n");
        writeMemory(destination, *value);
        break;
    }
    case SferaMbcRuntimeBuiltin::MovementContact:
    {
        const auto handle = nextInteger();
        if (handle < 0)
        {
            pushInteger(0);
            break;
        }
        std::uint32_t result = 0, direction = 0, depth = 0;
        if (argument_count == 5)
        {
            result = nextInteger();
            direction = nextInteger();
            depth = nextInteger();
            nextInteger();
        }
        if (execution_failed)
            break;
        if (argument_count <= 1)
        {
            pushInteger(g_sfera_contacts.testMovement(handle, false));
            break;
        }
        auto *object = g_sfera_world_objects.object(handle, "GetObjectPointer");
        g_sfera_mbc_runtime.current_object = object;
        if (object == nullptr)
        {
            active_tag = UINT32_MAX;
            break;
        }
        auto *extended = SphereRenderCharacterModels::checkedExtended(object);
        pushInteger(extended->movement_blocked ? 0 : UINT32_MAX);
        extended->movement_blocked = false;
        if (argument_count == 5)
        {
            const std::uint32_t avoidance_enabled = extended->avoidance_enabled;
            writeMemory(result, avoidance_enabled);
            if (extended->avoidance_enabled)
            {
                if (direction != 0)
                    writeMemory(direction, extended->avoidance_direction);
                if (depth != 0)
                    writeMemory(depth, extended->avoidance_depth);
            }
        }
        break;
    }
    default:
        return false;
    }
    return true;
}
