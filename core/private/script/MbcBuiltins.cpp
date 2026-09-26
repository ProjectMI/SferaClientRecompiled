#include <sys/utime.h>
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
#include <fcntl.h>
#include <format>
#include <functional>
#include <io.h>
#include <iterator>
#include <limits>
#include <memory>
#include <optional>
#include <share.h>
#include <string>
#include <string_view>
#include <sys/locking.h>
#include <sys/stat.h>
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
#include "script/ConfigText.h"
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

bool SferaMbcRuntime::executeBuiltin(SferaMbcRuntimeBuiltin builtin)
{
    switch (builtin)
    {
    case SferaMbcRuntimeBuiltin::Fail:
    case SferaMbcRuntimeBuiltin::FailAlternate:
    case SferaMbcRuntimeBuiltin::Exit:
    case SferaMbcRuntimeBuiltin::LoadProcess:
    case SferaMbcRuntimeBuiltin::UnloadProcess:
    case SferaMbcRuntimeBuiltin::LinkProcess:
    case SferaMbcRuntimeBuiltin::System:
    case SferaMbcRuntimeBuiltin::DiscardInteger:
    case SferaMbcRuntimeBuiltin::Reserved122:
    case SferaMbcRuntimeBuiltin::Reserved130:
    case SferaMbcRuntimeBuiltin::Reserved133:
    case SferaMbcRuntimeBuiltin::CallFunction:
    case SferaMbcRuntimeBuiltin::CallMainFunction:
    case SferaMbcRuntimeBuiltin::ThisProcessName:
    case SferaMbcRuntimeBuiltin::ProcessName:
    case SferaMbcRuntimeBuiltin::ModuleName:
    case SferaMbcRuntimeBuiltin::FindModule:
    case SferaMbcRuntimeBuiltin::FindProcess:
    case SferaMbcRuntimeBuiltin::SimulationTick:
    case SferaMbcRuntimeBuiltin::ProcessModule:
    case SferaMbcRuntimeBuiltin::ActiveTag:
    case SferaMbcRuntimeBuiltin::ArgumentCount:
    case SferaMbcRuntimeBuiltin::CurrentModule:
    case SferaMbcRuntimeBuiltin::CurrentProcess:
    case SferaMbcRuntimeBuiltin::ZeroResult:
    case SferaMbcRuntimeBuiltin::ZeroResultAlternate:
    case SferaMbcRuntimeBuiltin::ProfileValue:
    case SferaMbcRuntimeBuiltin::ProcessFlag:
    case SferaMbcRuntimeBuiltin::NextDefaultValue:
    case SferaMbcRuntimeBuiltin::CallerProcess:
    case SferaMbcRuntimeBuiltin::DiscardArgument:
    case SferaMbcRuntimeBuiltin::StopInterpreter:
    case SferaMbcRuntimeBuiltin::InvalidResult:
        return executeControlBuiltin(builtin);
    case SferaMbcRuntimeBuiltin::Connect:
    case SferaMbcRuntimeBuiltin::Disconnect:
    case SferaMbcRuntimeBuiltin::Send:
    case SferaMbcRuntimeBuiltin::Receive:
    case SferaMbcRuntimeBuiltin::TickDifference:
    case SferaMbcRuntimeBuiltin::NetworkInitialization:
        return executeNetworkBuiltin(builtin);
    case SferaMbcRuntimeBuiltin::FormatText:
    case SferaMbcRuntimeBuiltin::BoundedFormatText:
    case SferaMbcRuntimeBuiltin::FormattedLog:
    case SferaMbcRuntimeBuiltin::NamedFormattedLog:
    case SferaMbcRuntimeBuiltin::ScriptLog:
    case SferaMbcRuntimeBuiltin::ParseText:
    case SferaMbcRuntimeBuiltin::ChatUtility:
    case SferaMbcRuntimeBuiltin::ScanText:
    case SferaMbcRuntimeBuiltin::CopyString:
    case SferaMbcRuntimeBuiltin::CopyStringCount:
    case SferaMbcRuntimeBuiltin::AppendString:
    case SferaMbcRuntimeBuiltin::FindString:
    case SferaMbcRuntimeBuiltin::FindStringInsensitive:
    case SferaMbcRuntimeBuiltin::StringLength:
    case SferaMbcRuntimeBuiltin::CompareStrings:
    case SferaMbcRuntimeBuiltin::CompareStringsInsensitive:
    case SferaMbcRuntimeBuiltin::CompareStringsCount:
    case SferaMbcRuntimeBuiltin::CompareStringsCountInsensitive:
        return executeTextBuiltin(builtin);
    case SferaMbcRuntimeBuiltin::Window:
    case SferaMbcRuntimeBuiltin::MouseMotion:
    case SferaMbcRuntimeBuiltin::FontSettings:
    case SferaMbcRuntimeBuiltin::DestroyObject:
    case SferaMbcRuntimeBuiltin::DestroyText:
    case SferaMbcRuntimeBuiltin::DestroySprite:
    case SferaMbcRuntimeBuiltin::SetRenderEnabled:
    case SferaMbcRuntimeBuiltin::CreateObject:
    case SferaMbcRuntimeBuiltin::Text:
    case SferaMbcRuntimeBuiltin::TextColor:
    case SferaMbcRuntimeBuiltin::Sprite:
    case SferaMbcRuntimeBuiltin::Effect:
    case SferaMbcRuntimeBuiltin::SceneContext:
    case SferaMbcRuntimeBuiltin::KeyboardState:
        return executeVisualBuiltin(builtin);
    case SferaMbcRuntimeBuiltin::Distance:
    case SferaMbcRuntimeBuiltin::Sin:
    case SferaMbcRuntimeBuiltin::Cos:
    case SferaMbcRuntimeBuiltin::Exp:
    case SferaMbcRuntimeBuiltin::AbsoluteReal:
    case SferaMbcRuntimeBuiltin::SquareRoot:
    case SferaMbcRuntimeBuiltin::RealValue:
    case SferaMbcRuntimeBuiltin::ArcTangent:
    case SferaMbcRuntimeBuiltin::AbsoluteInteger:
    case SferaMbcRuntimeBuiltin::IntegerValue:
    case SferaMbcRuntimeBuiltin::RandomReal:
    case SferaMbcRuntimeBuiltin::PackColor:
    case SferaMbcRuntimeBuiltin::ScaleColor:
    case SferaMbcRuntimeBuiltin::BitAnd:
    case SferaMbcRuntimeBuiltin::BitOr:
    case SferaMbcRuntimeBuiltin::BitXor:
    case SferaMbcRuntimeBuiltin::BitNot:
    case SferaMbcRuntimeBuiltin::ShiftLeft:
    case SferaMbcRuntimeBuiltin::ShiftRight:
    case SferaMbcRuntimeBuiltin::ClearBit:
    case SferaMbcRuntimeBuiltin::SetBit:
    case SferaMbcRuntimeBuiltin::TestBit:
        return executeMathBuiltin(builtin);
    case SferaMbcRuntimeBuiltin::Configuration:
        return executeConfigurationBuiltin(builtin);
    case SferaMbcRuntimeBuiltin::CreateFile:
    case SferaMbcRuntimeBuiltin::OpenFile:
    case SferaMbcRuntimeBuiltin::CloseFile:
    case SferaMbcRuntimeBuiltin::ReadFile:
    case SferaMbcRuntimeBuiltin::WriteFile:
    case SferaMbcRuntimeBuiltin::ReadLine:
    case SferaMbcRuntimeBuiltin::LockFile:
    case SferaMbcRuntimeBuiltin::SeekFile:
    case SferaMbcRuntimeBuiltin::FileSize:
    case SferaMbcRuntimeBuiltin::FileTime:
    case SferaMbcRuntimeBuiltin::ResizeFile:
    case SferaMbcRuntimeBuiltin::SetFileTime:
    case SferaMbcRuntimeBuiltin::RemoveFile:
    case SferaMbcRuntimeBuiltin::RenameFile:
    case SferaMbcRuntimeBuiltin::FileChecksum:
        return executeFilesBuiltin(builtin);
    case SferaMbcRuntimeBuiltin::SetAnimation:
    case SferaMbcRuntimeBuiltin::SetFrame:
    case SferaMbcRuntimeBuiltin::AnimationLength:
    case SferaMbcRuntimeBuiltin::SetInterpolation:
    case SferaMbcRuntimeBuiltin::ObjectProcess:
    case SferaMbcRuntimeBuiltin::SetPosition:
    case SferaMbcRuntimeBuiltin::MoveWorld:
    case SferaMbcRuntimeBuiltin::CommandVelocity:
    case SferaMbcRuntimeBuiltin::VerticalVelocity:
    case SferaMbcRuntimeBuiltin::AngularVelocity:
    case SferaMbcRuntimeBuiltin::Airborne:
    case SferaMbcRuntimeBuiltin::ObjectBasis:
    case SferaMbcRuntimeBuiltin::ObjectPosition:
    case SferaMbcRuntimeBuiltin::ObjectRotation:
    case SferaMbcRuntimeBuiltin::EditorPick:
    case SferaMbcRuntimeBuiltin::MovementContact:
    case SferaMbcRuntimeBuiltin::PositionX:
    case SferaMbcRuntimeBuiltin::PositionY:
    case SferaMbcRuntimeBuiltin::PositionZ:
    case SferaMbcRuntimeBuiltin::RotationX:
    case SferaMbcRuntimeBuiltin::RotationY:
    case SferaMbcRuntimeBuiltin::RotationZ:
    case SferaMbcRuntimeBuiltin::SetRotation:
    case SferaMbcRuntimeBuiltin::MoveLocal:
    case SferaMbcRuntimeBuiltin::MoveForward:
    case SferaMbcRuntimeBuiltin::Rotate:
        return executeWorldBuiltin(builtin);
    case SferaMbcRuntimeBuiltin::AllocateMemory:
    case SferaMbcRuntimeBuiltin::AllocateDynamic:
    case SferaMbcRuntimeBuiltin::FreeDynamic:
    case SferaMbcRuntimeBuiltin::SetNamedValue:
    case SferaMbcRuntimeBuiltin::NamedValue:
    case SferaMbcRuntimeBuiltin::RebaseSlice:
    case SferaMbcRuntimeBuiltin::CopyProcessMemory:
    case SferaMbcRuntimeBuiltin::CopyProcessString:
    case SferaMbcRuntimeBuiltin::MemoryChecksum:
    case SferaMbcRuntimeBuiltin::CompareMemory:
    case SferaMbcRuntimeBuiltin::CopyMemory:
    case SferaMbcRuntimeBuiltin::MoveMemory:
    case SferaMbcRuntimeBuiltin::FillMemory:
    case SferaMbcRuntimeBuiltin::WriteByte:
    case SferaMbcRuntimeBuiltin::WriteShort:
    case SferaMbcRuntimeBuiltin::WriteThreeBytes:
    case SferaMbcRuntimeBuiltin::WriteWord:
    case SferaMbcRuntimeBuiltin::WriteReal:
    case SferaMbcRuntimeBuiltin::ReadByte:
    case SferaMbcRuntimeBuiltin::ReadShort:
    case SferaMbcRuntimeBuiltin::ReadThreeBytes:
    case SferaMbcRuntimeBuiltin::ReadWord:
    case SferaMbcRuntimeBuiltin::ReadReal:
    case SferaMbcRuntimeBuiltin::WriteString:
    case SferaMbcRuntimeBuiltin::ReadString:
    case SferaMbcRuntimeBuiltin::LowerBoundInteger:
        return executeMemoryBuiltin(builtin);
    case SferaMbcRuntimeBuiltin::PlayerLists:
        return executePlayersBuiltin(builtin);
    case SferaMbcRuntimeBuiltin::ContainerCommand:
    case SferaMbcRuntimeBuiltin::ContainerManagement:
        return executeContainersBuiltin(builtin);
    default:
        return false;
    }
}

bool SferaMbcRuntime::executeConfigurationBuiltin(SferaMbcRuntimeBuiltin builtin)
{
    switch (builtin)
    {
    case SferaMbcRuntimeBuiltin::Configuration:
    {
        auto &config = g_sfera_config_text_runtime;
        const auto operation = SferaNumeric::enumFromBits<SferaConfigTextRuntimeOperation>(nextInteger());
        switch (operation)
        {
        case SferaConfigTextRuntimeOperation::Write:
        {
            const auto keyOffset = nextWord();
            if (execution_failed)
                break;
            const std::string key(textAt(keyOffset));
            if (argument_cursor >= argument_end)
            {
                reportError("Too few parameters");
                break;
            }
            const auto type = SferaNumeric::enumBits(g_sfera_mbc_runtime.values[argument_cursor].type);
            std::string value;
            bool quoted = false;
            if (!key.empty() && key.front() == '*')
            {
                const auto offset = nextWord();
                const auto size = nextInteger();
                if (execution_failed)
                    break;
                if (size < 0 || size > (SferaConfigTextRuntime::text_capacity - 4) * 3 / 4)
                {
                    reportError("cfg_set: invalid binary size");
                    break;
                }
                value = SferaConfigTextRuntime::encodeBinary(memoryAt(offset, size), size);
            }
            else if (type == SferaMbcValueTypeByte || type == SferaMbcValueTypeInteger)
            {
                value = std::to_string(nextInteger());
            }
            else if (type == SferaMbcValueTypeReal)
            {
                value = std::format("{:f}", nextReal());
            }
            else if (type == SferaMbcValueTypeBytePointer)
            {
                const auto offset = nextWord();
                if (execution_failed)
                    break;
                value = textAt(offset);
                quoted = true;
            }
            else
            {
                reportError("cfg_set: unsupported value type");
                break;
            }
            if (!execution_failed)
                pushInteger(config.writeValue(key, value, quoted) ? 0u : UINT32_MAX);
            break;
        }
        case SferaConfigTextRuntimeOperation::Read:
        {
            const auto keyReference = nextSliceReference();
            if (execution_failed)
                break;
            const auto key = textIn(keyReference);
            if (argument_cursor >= argument_end)
            {
                reportError("Too few parameters");
                break;
            }
            const auto type = g_sfera_mbc_runtime.values[argument_cursor].type;
            const auto destination = nextSliceReference();
            const auto capacity = argument_count == 4 ? nextWord() : 10000000u;
            if (execution_failed)
                break;
            bool result = false;
            if (key.starts_with('*'))
            {
                auto bytes = sliceBytes(destination);
                result = config.readBinary(key, bytes.first(std::min<std::size_t>(capacity, bytes.size())));
            }
            else if (type == SferaMbcValueTypeIntegerPointer)
            {
                auto value = readMemory<int>(destination.base);
                result = config.readInteger(key, value);
                if (result)
                    writeMemory(destination.base, value);
            }
            else if (type == SferaMbcValueTypeRealPointer)
            {
                auto value = readMemory<float>(destination.base);
                result = config.readFloat(key, value);
                if (result)
                    writeMemory(destination.base, value);
            }
            else if (type == SferaMbcValueTypeBytePointer)
            {
                auto output = textBuffer(destination);
                output = output.limited(capacity);
                if (const auto value = config.readString(key); value && !output.empty())
                {
                    result = output.write(*value) == value->size();
                }
            }
            else
            {
                const auto message = std::format("wrong parameter in cfg_get, '{}'\n", key);
                ::OutputDebugStringA(message.c_str());
            }
            pushInteger(result ? 0u : UINT32_MAX);
            break;
        }
        case SferaConfigTextRuntimeOperation::Load:
        case SferaConfigTextRuntimeOperation::Clear:
        case SferaConfigTextRuntimeOperation::UseText:
        case SferaConfigTextRuntimeOperation::SetFilename:
        {
            const auto reference = nextSliceReference();
            if (reference.base == 0)
                reportError("poppointerup(): unexpected NULL-pointer fetched");
            if (execution_failed)
                break;
            const auto text = textIn(reference);
            if (operation == SferaConfigTextRuntimeOperation::UseText)
            {
                config.useText(reference.base, sliceBytes(reference).size(), active_process);
                pushInteger(0);
            }
            else if (operation == SferaConfigTextRuntimeOperation::Load)
                pushInteger(config.load(std::string(text)) ? 0u : UINT32_MAX);
            else
            {
                const auto length = text.size();
                if (length >= SferaConfigTextRuntime::filename_capacity)
                {
                    reportError("cfg: filename is too long");
                    break;
                }
                if (operation == SferaConfigTextRuntimeOperation::Clear)
                    config.clear(std::string(text));
                else
                    config.filename.assign(text);
            }
            break;
        }
        case SferaConfigTextRuntimeOperation::Save:
        case SferaConfigTextRuntimeOperation::SaveCompressed:
            pushInteger(config.save(operation == SferaConfigTextRuntimeOperation::SaveCompressed) ? 0u : UINT32_MAX);
            break;
        case SferaConfigTextRuntimeOperation::ReadCommands:
        {
            if (active_process->physics_commands.empty())
            {
                pushInteger(UINT32_MAX);
                break;
            }
            auto commands = std::exchange(active_process->physics_commands, {});
            g_sfera_config_text_runtime.copyText(commands);
            pushInteger(0);
            break;
        }
        case SferaConfigTextRuntimeOperation::CopyText:
        {
            const auto destination = nextSliceReference();
            if (destination.base == 0)
                reportError("poppointerup(): unexpected NULL-pointer fetched");
            const std::uint32_t capacity = nextWord();
            if (!execution_failed)
                pushInteger(SferaNumeric::lowWord(config.copyTo(sliceBytes(destination).first(std::min<std::size_t>(capacity, sliceBytes(destination).size())))));
            break;
        }
        case SferaConfigTextRuntimeOperation::Length:
            if (std::in_range<std::uint32_t>(config.text().size()))
                pushInteger(SferaNumeric::lowWord(config.text().size()));
            else
                reportError("cfg: text is too long for MBC");
            break;
        default:
            break;
        }
        return true;
    }
    default:
        return false;
    }
    return true;
}

bool SferaMbcRuntime::executeContainersBuiltin(SferaMbcRuntimeBuiltin builtin)
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
    default:
        return false;
    }
    return true;
}

bool SferaMbcRuntime::moduleMatches(std::int32_t address, const SferaMbcModuleRecord &module)
{
    return !module.name.empty() && SferaText::compareInsensitive(module.name, textAt(address)) == 0;
}

bool SferaMbcRuntime::executeControlBuiltin(SferaMbcRuntimeBuiltin builtin)
{
    switch (builtin)
    {
    case SferaMbcRuntimeBuiltin::Fail:
    case SferaMbcRuntimeBuiltin::FailAlternate:
    {
        std::string message;
        message = std::format("MBInter:\n {:f}", nextReal());
        SferaClientApplication::terminateWithError(message);
    }
    case SferaMbcRuntimeBuiltin::Exit:
    {
        if (argument_count == 0)
            throw SferaClientApplicationExitRequested{};
        if (argument_count > 1)
            g_sfera_mbc_runtime.dispatch_slot = -1;
        const auto message = nextSliceReference().base;
        SferaClientApplication::terminateWithError(textAt(message));
    }
    case SferaMbcRuntimeBuiltin::LoadProcess:
    {
        const auto name = nextSliceReference().base;
        const auto index = argument_count > 1 ? nextWord() : UINT32_MAX;
        if (execution_failed)
            break;
        if (name == 0)
            ::OutputDebugStringA("NULL-pointer dereferencing: ffprc_load\n");
        active_tag = loadProcess(textAt(name), index);
        pushInteger(active_tag);
        break;
    }
    case SferaMbcRuntimeBuiltin::UnloadProcess:
    {
        const std::uint32_t requested = nextInteger();
        const auto *process = findProcess(requested);
        const auto index = process == nullptr ? UINT32_MAX : requested;
        if (execution_failed)
            break;
        if (index == SferaNumeric::word(process_index))
            active_tag = UINT32_MAX;
        else
            active_tag = unloadProcess(index);
        pushInteger(active_tag);
        break;
    }
    case SferaMbcRuntimeBuiltin::LinkProcess:
    {
        const auto name = nextSliceReference().base;
        if (name == 0)
            ::OutputDebugStringA("NULL-pointer dereferencing: ffprc_link\n");
        active_tag = linkProcess(textAt(name));
        pushInteger(active_tag);
        break;
    }
    case SferaMbcRuntimeBuiltin::System:
        systemCommand();
        break;
    case SferaMbcRuntimeBuiltin::DiscardInteger:
        nextInteger();
        break;
    case SferaMbcRuntimeBuiltin::Reserved122:
    case SferaMbcRuntimeBuiltin::Reserved130:
    case SferaMbcRuntimeBuiltin::Reserved133:
        break;
    case SferaMbcRuntimeBuiltin::CallFunction:
    case SferaMbcRuntimeBuiltin::CallMainFunction:
        callFunction(builtin == SferaMbcRuntimeBuiltin::CallMainFunction);
        break;
    case SferaMbcRuntimeBuiltin::ThisProcessName:
    case SferaMbcRuntimeBuiltin::ProcessName:
    case SferaMbcRuntimeBuiltin::ModuleName:
    {
        const auto id = builtin == SferaMbcRuntimeBuiltin::ThisProcessName ? process_index : nextWord();
        const auto destination = nextWord();
        if (destination == 0 && builtin != SferaMbcRuntimeBuiltin::ModuleName)
            WorldDiagnostics::warning(builtin == SferaMbcRuntimeBuiltin::ThisProcessName ? "NULL-pointer dereferencing: thisname\n" : "NULL-pointer dereferencing: prc_name\n");
        if (execution_failed)
            break;
        std::optional<std::string_view> name;
        if (builtin == SferaMbcRuntimeBuiltin::ThisProcessName)
            name = active_process->name;
        else if (builtin == SferaMbcRuntimeBuiltin::ProcessName && id < std::size(processes) && processes[id].chain_prev_index >= 0)
            name = processes[id].name;
        else if (builtin == SferaMbcRuntimeBuiltin::ModuleName && id < std::size(g_sfera_mbc_runtime.modules))
            name = g_sfera_mbc_runtime.modules[id].name;
        if (name)
            copyText({destination, 0, 0}, *name);
        if (builtin != SferaMbcRuntimeBuiltin::ThisProcessName)
            pushInteger(name && (builtin != SferaMbcRuntimeBuiltin::ModuleName || !name->empty()) ? 0 : UINT32_MAX);
        break;
    }
    case SferaMbcRuntimeBuiltin::FindModule:
    {
        const auto name = nextInteger();
        if (execution_failed)
            break;
        const auto &loadedModules = g_sfera_mbc_runtime.modules;
        const auto found = std::find_if(std::begin(loadedModules), std::end(loadedModules), std::bind_front(&SferaMbcRuntime::moduleMatches, this, name));
        pushInteger(found == std::end(loadedModules) ? UINT32_MAX : SferaNumeric::lowWord(found - std::begin(loadedModules)));
        break;
    }
    case SferaMbcRuntimeBuiltin::FindProcess:
    {
        const bool byName = g_sfera_mbc_runtime.values[argument_cursor].type == SferaMbcValueTypeBytePointer;
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
    case SferaMbcRuntimeBuiltin::SimulationTick:
        pushInteger(g_sfera_mbc_runtime.simulation_tick);
        break;
    case SferaMbcRuntimeBuiltin::ProcessModule:
    {
        const std::uint32_t index = nextInteger();
        const bool valid = index < std::size(processes) && processes[index].process_id == index && processes[index].chain_prev_index >= 0;
        if (!execution_failed)
            pushInteger(valid ? processes[index].module_tag : UINT32_MAX);
        break;
    }
    case SferaMbcRuntimeBuiltin::ActiveTag:
        pushInteger(active_tag);
        break;
    case SferaMbcRuntimeBuiltin::ArgumentCount:
        pushInteger(argument_count);
        break;
    case SferaMbcRuntimeBuiltin::CurrentModule:
        pushInteger(processes[process_index].module_tag);
        break;
    case SferaMbcRuntimeBuiltin::CurrentProcess:
        pushInteger(processes[process_index].process_id);
        break;
    case SferaMbcRuntimeBuiltin::ZeroResult:
    case SferaMbcRuntimeBuiltin::ZeroResultAlternate:
        pushInteger(0);
        break;
    case SferaMbcRuntimeBuiltin::ProfileValue:
        nextInteger();
        if (!execution_failed)
            pushInteger(0);
        break;
    case SferaMbcRuntimeBuiltin::ProcessFlag:
        pushInteger(active_process->flags & SferaMbcProcessRecordFlagsunloadAfterExecution);
        break;
    case SferaMbcRuntimeBuiltin::NextDefaultValue:
        pushInteger(0);
        break;
    case SferaMbcRuntimeBuiltin::CallerProcess:
        pushInteger(execution_context_depth > 0 ? execution_context_stack[execution_context_depth - 1].process_id : UINT32_MAX);
        break;
    case SferaMbcRuntimeBuiltin::DiscardArgument:
    {
        const auto &argument = g_sfera_mbc_runtime.values[argument_cursor];
        if (!argument.isPointer() && argument.type == SferaMbcValueTypeReal)
            nextReal();
        else
            nextInteger();
        break;
    }
    case SferaMbcRuntimeBuiltin::StopInterpreter:
    {
        if (argument_count != 1)
            halt_state = SferaMbcRuntimeHaltState::Requested;
        else
        {
            const auto mode = nextInteger();
            if (mode == 0)
                halt_state = SferaMbcRuntimeHaltState::Requested;
            else if (mode == 1 || mode == -1)
                SferaClientApplication::quit_requested = true;
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::InvalidResult:
        pushInteger(UINT32_MAX);
        break;
    default:
        return false;
    }
    return true;
}

bool SferaMbcRuntime::executeFilesBuiltin(SferaMbcRuntimeBuiltin builtin)
{
    switch (builtin)
    {
    case SferaMbcRuntimeBuiltin::CreateFile:
    case SferaMbcRuntimeBuiltin::OpenFile:
    {
        const auto name = nextWord();
        if (name == 0)
            WorldDiagnostics::warning(builtin == SferaMbcRuntimeBuiltin::CreateFile ? "NULL-pointer dereferencing: ffcreate\n" : "NULL-pointer dereferencing: ffopen\n");
        if (builtin == SferaMbcRuntimeBuiltin::CreateFile && execution_failed)
            break;
        const auto path = textAt(name);
        ::_chmod(path.data(), _S_IREAD | _S_IWRITE);
        if (execution_failed)
            break;
        int flags = _O_BINARY | _O_RDWR;
        int sharing = _SH_DENYNO;
        if (builtin == SferaMbcRuntimeBuiltin::CreateFile)
            flags |= _O_CREAT | (argument_count == 2 ? 0 : _O_TRUNC);
        else if (argument_count > 1 && nextInteger() == 1)
            flags = _O_BINARY | _O_RDONLY;
        int file = -1;
        ::_sopen_s(&file, path.data(), flags, sharing, _S_IREAD | _S_IWRITE);
        if (file >= 0)
        {
            try
            {
                active_process->registerResource(file, SferaMbcRuntimeResourceKind::file);
            }
            catch (...)
            {
                ::_close(file);
                throw;
            }
        }
        pushInteger(file);
        break;
    }
    case SferaMbcRuntimeBuiltin::CloseFile:
    {
        const auto file = nextInteger();
        if (!execution_failed && file >= 0)
        {
            ::_close(file);
            active_process->unregisterResource(file, SferaMbcRuntimeResourceKind::file);
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::ReadFile:
    case SferaMbcRuntimeBuiltin::WriteFile:
    {
        const auto file = nextInteger();
        if (builtin == SferaMbcRuntimeBuiltin::ReadFile && execution_failed)
            break;
        auto &buffer = nextSliceReference();
        const std::uint32_t size = nextInteger();
        if (execution_failed)
            break;
        if (!buffer.contains(size))
            buffer.diagnoseRange(size);
        const auto data = memoryBytes(buffer.base, size);
        if (size == 0)
        {
            pushInteger(0);
            break;
        }
        const auto result = builtin == SferaMbcRuntimeBuiltin::ReadFile ? ::_read(file, data.data(), size) : file < 0 ? 0 : ::_write(file, data.data(), size);
        pushInteger(result);
        break;
    }
    case SferaMbcRuntimeBuiltin::ReadLine:
    {
        const auto file = nextInteger();
        if (execution_failed)
            break;
        const auto destination = nextAddress();
        if (destination.base == 0)
            WorldDiagnostics::warning("NULL-pointer dereferencing: ffread\n");
        const auto capacity = nextInteger();
        if (execution_failed)
            break;
        if (capacity < 0)
        {
            reportError("Negative line buffer capacity");
            break;
        }
        const auto output = memoryBytes(destination.base, capacity);
        int size = 0;
        // ReadLine has a byte-count ABI: a full buffer is not required to end in NUL.
        while (size < capacity)
        {
            std::uint8_t character;
            if (::_read(file, &character, sizeof(character)) != 1)
                break;
            if (character == '\n' || character == '\0')
            {
                output[size] = 0;
                break;
            }
            output[size++] = character;
        }
        pushInteger(size);
        break;
    }
    case SferaMbcRuntimeBuiltin::LockFile:
    {
        const auto file = nextInteger();
        const auto unlock = nextInteger();
        const auto size = nextInteger();
        if (!execution_failed)
            pushInteger(::_locking(file, unlock ? _LK_UNLCK : _LK_NBLCK, size));
        break;
    }
    case SferaMbcRuntimeBuiltin::SeekFile:
    {
        const auto file = nextInteger();
        const auto offset = nextInteger();
        const auto origin = nextInteger();
        if (!execution_failed)
            pushInteger(::_lseek(file, offset, origin == 1 ? SEEK_SET : origin == 2 ? SEEK_CUR : SEEK_END));
        break;
    }
    case SferaMbcRuntimeBuiltin::FileSize:
    {
        const auto file = nextInteger();
        if (!execution_failed)
            pushInteger(::_filelength(file));
        break;
    }
    case SferaMbcRuntimeBuiltin::FileTime:
    {
        const auto file = nextInteger();
        if (!execution_failed)
        {
            struct _stat64i32 status{};
            ::_fstat64i32(file, &status);
            pushInteger(SferaNumeric::lowWord(status.st_mtime));
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::ResizeFile:
    {
        const auto file = nextInteger();
        const auto size = nextInteger();
        if (!execution_failed)
            ::_chsize_s(file, size);
        break;
    }
    case SferaMbcRuntimeBuiltin::SetFileTime:
    {
        const auto file = nextInteger();
        const auto time = nextInteger();
        if (!execution_failed)
        {
            __utimbuf64 times{time, time};
            ::_futime64(file, &times);
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::RemoveFile:
    {
        const auto name = nextInteger();
        if (!execution_failed)
            pushInteger(std::remove(textAt(name).data()));
        break;
    }
    case SferaMbcRuntimeBuiltin::RenameFile:
    {
        const auto source = nextWord();
        const auto destination = nextWord();
        if (!execution_failed)
            pushInteger(std::rename(textAt(source).data(), textAt(destination).data()));
        break;
    }
    case SferaMbcRuntimeBuiltin::FileChecksum:
    {
        nextInteger();
        if (!execution_failed)
            pushInteger(0);
        break;
    }
    default:
        return false;
    }
    return true;
}

bool SferaMbcRuntime::executeMathBuiltin(SferaMbcRuntimeBuiltin builtin)
{
    switch (builtin)
    {
    case SferaMbcRuntimeBuiltin::Distance:
        calculateDistance();
        break;
    case SferaMbcRuntimeBuiltin::Sin:
    case SferaMbcRuntimeBuiltin::Cos:
    case SferaMbcRuntimeBuiltin::Exp:
    case SferaMbcRuntimeBuiltin::AbsoluteReal:
    case SferaMbcRuntimeBuiltin::SquareRoot:
    case SferaMbcRuntimeBuiltin::RealValue:
    {
        const double value = nextReal();
        double result = value;
        if (builtin == SferaMbcRuntimeBuiltin::Sin)
            result = std::sin(value);
        else if (builtin == SferaMbcRuntimeBuiltin::Cos)
            result = std::cos(value);
        else if (builtin == SferaMbcRuntimeBuiltin::Exp)
            result = std::exp(value);
        else if (builtin == SferaMbcRuntimeBuiltin::AbsoluteReal || builtin == SferaMbcRuntimeBuiltin::SquareRoot)
        {
            result = value < 0.0 ? -value : value;
            if (builtin == SferaMbcRuntimeBuiltin::SquareRoot)
                result = std::sqrt(result);
        }
        pushReal(result);
        break;
    }
    case SferaMbcRuntimeBuiltin::ArcTangent:
    {
        const double y = nextReal();
        const double x = nextReal();
        pushReal(std::atan2(y, x));
        break;
    }
    case SferaMbcRuntimeBuiltin::AbsoluteInteger:
    case SferaMbcRuntimeBuiltin::IntegerValue:
    {
        const auto value = nextInteger();
        if (builtin == SferaMbcRuntimeBuiltin::AbsoluteInteger && value < 0)
            pushInteger(0u - SferaNumeric::word(value));
        else
            pushInteger(value);
        break;
    }
    case SferaMbcRuntimeBuiltin::RandomReal:
        pushReal(std::rand() / 32768.0f);
        break;
    case SferaMbcRuntimeBuiltin::PackColor:
    {
        const auto red = nextInteger();
        const auto green = nextInteger();
        const auto blue = nextInteger();
        pushInteger(D3DCOLOR_XRGB(red, green, blue));
        break;
    }
    case SferaMbcRuntimeBuiltin::ScaleColor:
    {
        const auto color = SferaColor::fromArgb(nextWord());
        const double factor = nextReal();
        const std::uint8_t red = SferaNumeric::lowByte(SferaMbcValue::truncate(color.red() * factor));
        const std::uint8_t green = SferaNumeric::lowByte(SferaMbcValue::truncate(color.green() * factor));
        const std::uint8_t blue = SferaNumeric::lowByte(SferaMbcValue::truncate(color.blue() * factor));
        pushInteger(D3DCOLOR_XRGB(red, green, blue));
        break;
    }
    case SferaMbcRuntimeBuiltin::BitAnd:
    case SferaMbcRuntimeBuiltin::BitOr:
    case SferaMbcRuntimeBuiltin::BitXor:
    case SferaMbcRuntimeBuiltin::BitNot:
    case SferaMbcRuntimeBuiltin::ShiftLeft:
    case SferaMbcRuntimeBuiltin::ShiftRight:
    case SferaMbcRuntimeBuiltin::ClearBit:
    case SferaMbcRuntimeBuiltin::SetBit:
    case SferaMbcRuntimeBuiltin::TestBit:
    {
        std::uint32_t result = nextInteger();
        const auto argument = builtin == SferaMbcRuntimeBuiltin::BitNot ? 0u : nextWord();
        const auto shift = argument % std::numeric_limits<std::uint32_t>::digits;
        if (builtin == SferaMbcRuntimeBuiltin::BitAnd)
            result &= argument;
        else if (builtin == SferaMbcRuntimeBuiltin::BitOr)
            result |= argument;
        else if (builtin == SferaMbcRuntimeBuiltin::BitXor)
            result ^= argument;
        else if (builtin == SferaMbcRuntimeBuiltin::BitNot)
            result = ~result;
        else if (builtin == SferaMbcRuntimeBuiltin::ShiftLeft)
            result <<= shift;
        else if (builtin == SferaMbcRuntimeBuiltin::ShiftRight)
            result = SferaNumeric::signedWord(result) >> shift;
        else if (builtin == SferaMbcRuntimeBuiltin::ClearBit)
            result &= ~(1u << shift);
        else if (builtin == SferaMbcRuntimeBuiltin::SetBit)
            result |= 1u << shift;
        else
            result = SferaNumeric::signedWord(result & (1u << shift)) >> shift;
        pushInteger(result);
        break;
    }
    default:
        return false;
    }
    return true;
}

void SferaMbcRuntime::calculateDistance()
{
    std::array<double, 3> delta{};
    if (argument_count == 2)
    {
        auto first = nextSlice();
        auto second = nextSlice();
        if (!first.contains(sizeof(SferaVec3F)))
            first.diagnoseRange(sizeof(SferaVec3F));
        if (!second.contains(sizeof(SferaVec3F)))
            second.diagnoseRange(sizeof(SferaVec3F));
        if (execution_failed)
            return;
        const auto a = readMemory<SferaVec3F>(first.base);
        const auto b = readMemory<SferaVec3F>(second.base);
        const double ax = a.x;
        const double ay = a.y;
        const double az = a.z;
        delta = {ax - b.x, ay - b.y, az - b.z};
    }
    else
    {
        const auto dimensions = argument_count == 4 || argument_count == 5 ? 2u : 3u;
        std::array<float, 3> first{}, second{};
        for (std::uint32_t index = 0; index < dimensions; ++index)
            first[index] = nextReal();
        for (std::uint32_t index = 0; index < dimensions; ++index)
            second[index] = nextReal();
        for (std::uint32_t index = 0; index < dimensions; ++index)
        {
            const double value = first[index];
            delta[index] = value - second[index];
        }
    }
    const float square = SferaNumeric::real32(delta[1] * delta[1] + delta[0] * delta[0] + delta[2] * delta[2]);
    pushReal(argument_count == 2 || argument_count == 4 || argument_count == 6 ? std::sqrt(square) : square);
}

bool SferaMbcRuntime::executeMemoryBuiltin(SferaMbcRuntimeBuiltin builtin)
{
    switch (builtin)
    {
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
    case SferaMbcRuntimeBuiltin::SetNamedValue:
    case SferaMbcRuntimeBuiltin::NamedValue:
    {
        const auto name = nextInteger();
        const auto value = builtin == SferaMbcRuntimeBuiltin::SetNamedValue ? nextWord() : 0u;
        const auto index = argument_count > (builtin == SferaMbcRuntimeBuiltin::SetNamedValue ? 2 : 1) ? nextInteger() : 0;
        const auto text = textAt(name);
        if (builtin == SferaMbcRuntimeBuiltin::SetNamedValue)
            setNamedValue(text, value, index);
        else
            pushInteger(namedValue(text, index));
        break;
    }
    case SferaMbcRuntimeBuiltin::RebaseSlice:
    {
        auto process = UINT32_MAX;
        const auto store = argument_count == 1;
        if (store)
        {
            if (execution_context_depth != 0 && program_table_base[program_index].callDepth == 0)
                process = execution_context_stack[execution_context_depth - 1].process_id;
        }
        else
            process = nextInteger();
        auto slice = nextSlice();
        if (execution_failed)
            break;
        auto *owner = findProcess(process);
        if (owner == nullptr)
        {
            if (store)
                pushInteger(UINT32_MAX);
            else
            {
                active_tag = UINT32_MAX;
                pushSlice({}, SferaMbcValueTypeBytePointer);
            }
            break;
        }
        slice = rebaseSlice(slice, *owner);
        if (store)
        {
            writeMemory(g_sfera_mbc_runtime.values[argument_cursor - 1].source.base, slice);
            pushInteger(0);
        }
        else
            pushSlice(slice, SferaMbcValueTypeBytePointer);
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
    case SferaMbcRuntimeBuiltin::CompareMemory:
    {
        const auto left = nextSlice();
        if (left.base == 0)
            reportError("poppointerup(): unexpected NULL-pointer fetched");
        const auto right = nextSlice();
        if (right.base == 0)
            reportError("poppointerup(): unexpected NULL-pointer fetched");
        const std::uint32_t size = nextInteger();
        if (!execution_failed)
        {
            const auto result = size == 0 ? 0 : std::memcmp(memoryBytes(left.base, size).data(), memoryBytes(right.base, size).data(), size);
            pushInteger((result > 0) - (result < 0));
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::CopyMemory:
    case SferaMbcRuntimeBuiltin::MoveMemory:
    case SferaMbcRuntimeBuiltin::FillMemory:
    {
        auto &destination = nextSliceReference();
        const auto source = builtin == SferaMbcRuntimeBuiltin::FillMemory ? SferaSliceReference32{nextWord(), 0, 0} : nextSliceReference();
        const std::uint32_t count = nextInteger();
        if (execution_failed)
            break;
        if (count != 0 && !destination.contains(count))
            destination.diagnoseRange(count);
        const auto output = memoryBytes(destination.base, count);
        if (builtin == SferaMbcRuntimeBuiltin::FillMemory)
            std::fill(output.begin(), output.end(), SferaNumeric::lowByte(source.base));
        else
            SferaBinary::copy(output, memoryBytes(source.base, count));
        break;
    }
    case SferaMbcRuntimeBuiltin::WriteByte:
    case SferaMbcRuntimeBuiltin::WriteShort:
    case SferaMbcRuntimeBuiltin::WriteThreeBytes:
    case SferaMbcRuntimeBuiltin::WriteWord:
    case SferaMbcRuntimeBuiltin::WriteReal:
    {
        auto destination = nextSliceReference();
        const auto value = builtin == SferaMbcRuntimeBuiltin::WriteReal ? SferaBinary::floatBits(nextReal()) : nextWord();
        const std::uint32_t width = builtin == SferaMbcRuntimeBuiltin::WriteByte         ? 1u
                                    : builtin == SferaMbcRuntimeBuiltin::WriteShort      ? 2u
                                    : builtin == SferaMbcRuntimeBuiltin::WriteThreeBytes ? 3u
                                                                                         : 4u;
        if (execution_failed)
            break;
        if (!destination.contains(width))
            destination.diagnoseRange(width);
        else
        {
            std::memcpy(sliceBytes(destination, width).data(), &value, width);
            destination.base += width;
        }
        pushSlice(destination, SferaMbcValueTypeBytePointer);
        break;
    }
    case SferaMbcRuntimeBuiltin::ReadByte:
    case SferaMbcRuntimeBuiltin::ReadShort:
    case SferaMbcRuntimeBuiltin::ReadThreeBytes:
    case SferaMbcRuntimeBuiltin::ReadWord:
    case SferaMbcRuntimeBuiltin::ReadReal:
    {
        auto source = nextSliceReference();
        auto &destination = nextSliceReference();
        const std::uint32_t width = builtin == SferaMbcRuntimeBuiltin::ReadByte ? 1u : builtin == SferaMbcRuntimeBuiltin::ReadShort ? 2u : builtin == SferaMbcRuntimeBuiltin::ReadThreeBytes ? 3u : 4u;
        if (execution_failed)
            break;
        if (!source.contains(width))
        {
            source.diagnoseRange(width);
            if (builtin == SferaMbcRuntimeBuiltin::ReadReal)
                break;
        }
        else if (!destination.contains(width))
        {
            destination.diagnoseRange(width);
            if (builtin == SferaMbcRuntimeBuiltin::ReadReal)
                break;
        }
        else
        {
            const auto input = sliceBytes(source, width);
            const auto outputWidth = builtin == SferaMbcRuntimeBuiltin::ReadShort || builtin == SferaMbcRuntimeBuiltin::ReadThreeBytes ? sizeof(std::uint32_t) : width;
            const auto output = memoryBytes(destination.base, outputWidth);
            // Stage the word before clearing a potentially overlapping destination.
            std::uint32_t value = 0;
            std::memcpy(&value, input.data(), width);
            std::memcpy(output.data(), &value, outputWidth);
            source.base += width;
        }
        pushSlice(source, SferaMbcValueTypeBytePointer);
        break;
    }
    case SferaMbcRuntimeBuiltin::WriteString:
    case SferaMbcRuntimeBuiltin::ReadString:
    {
        auto cursor = nextSliceReference();
        auto &argument = nextSliceReference();
        const bool writing = builtin == SferaMbcRuntimeBuiltin::WriteString;
        auto &source = writing ? argument : cursor;
        auto &destination = writing ? cursor : argument;
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
        if (!cursor.contains(length))
            cursor.diagnoseRange(length);
        else
            cursor.base += length;
        pushSlice(cursor, SferaMbcValueTypeBytePointer);
        break;
    }
    case SferaMbcRuntimeBuiltin::LowerBoundInteger:
    {
        auto dataSlice = nextSlice();
        const auto count = nextInteger();
        const auto key = nextInteger();
        if (execution_failed)
            break;
        const auto length = SferaNumeric::word(count) * sizeof(int);
        if (!dataSlice.contains(SferaNumeric::lowWord(length)))
            dataSlice.diagnoseRange(SferaNumeric::lowWord(length));
        if (count < 0)
        {
            pushInteger(UINT32_MAX);
            break;
        }
        int begin = 0, end = count - 1;
        while (begin < end)
        {
            const auto middle = begin + (end - begin) / 2;
            if (readMemory<int>(dataSlice.base + middle * sizeof(int)) < key)
                begin = middle + 1;
            else
                end = middle;
        }
        pushInteger(begin);
        break;
    }
    default:
        return false;
    }
    return true;
}

bool SferaMbcRuntime::executeNetworkBuiltin(SferaMbcRuntimeBuiltin builtin)
{
    switch (builtin)
    {
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
    case SferaMbcRuntimeBuiltin::TickDifference:
    {
        const std::uint32_t first = nextInteger();
        const std::uint32_t second = nextInteger();
        pushInteger(SferaNetworkRuntime::tickDifference(first, second));
        break;
    }
    case SferaMbcRuntimeBuiltin::NetworkInitialization:
        pushInteger(g_sfera_network_runtime.initialization_result);
        break;
    default:
        return false;
    }
    return true;
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

bool SferaMbcRuntime::executePlayersBuiltin(SferaMbcRuntimeBuiltin builtin)
{
    switch (builtin)
    {
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
    default:
        return false;
    }
    return true;
}

bool SferaMbcRuntime::executeTextBuiltin(SferaMbcRuntimeBuiltin builtin)
{
    switch (builtin)
    {
    case SferaMbcRuntimeBuiltin::FormatText:
    case SferaMbcRuntimeBuiltin::BoundedFormatText:
        formatText(builtin == SferaMbcRuntimeBuiltin::BoundedFormatText);
        break;
    case SferaMbcRuntimeBuiltin::FormattedLog:
    case SferaMbcRuntimeBuiltin::NamedFormattedLog:
        writeFormattedLog(builtin == SferaMbcRuntimeBuiltin::NamedFormattedLog);
        break;
    case SferaMbcRuntimeBuiltin::ScriptLog:
        writeScriptLog();
        break;
    case SferaMbcRuntimeBuiltin::ParseText:
        parseText();
        break;
    case SferaMbcRuntimeBuiltin::ChatUtility:
        chatUtility();
        break;
    case SferaMbcRuntimeBuiltin::ScanText:
        scanText();
        break;
    case SferaMbcRuntimeBuiltin::CopyString:
    case SferaMbcRuntimeBuiltin::CopyStringCount:
    case SferaMbcRuntimeBuiltin::AppendString:
    {
        auto &destination = nextSliceReference();
        auto &source = nextSliceReference();
        const auto count = builtin == SferaMbcRuntimeBuiltin::CopyStringCount ? nextInteger() : 0;
        if (!source.contains())
        {
            source.diagnoseRange(0);
            ++value_stack_size;
            break;
        }
        if (count < 0)
        {
            reportError("Negative string length");
            break;
        }
        const auto input = builtin == SferaMbcRuntimeBuiltin::CopyStringCount ? textIn(source, count) : textIn(source);
        auto output = textBuffer(destination);
        std::uint32_t length = 0;
        if (builtin == SferaMbcRuntimeBuiltin::AppendString)
        {
            if (!destination.contains())
            {
                destination.diagnoseRange(0);
                break;
            }
            const auto prefix = output.length();
            const auto required = prefix + input.size() + 1;
            if (required > UINT32_MAX || required > output.size())
            {
                destination.diagnoseRange(SferaNumeric::lowWord(std::min<std::size_t>(required, UINT32_MAX)));
                break;
            }
            length = SferaNumeric::lowWord(required);
            if (argument_count > 2 && SferaNumeric::signedWord(length) > nextInteger())
            {
                WorldDiagnostics::warning("Size mismatch: ffstrcat\n");
                ++value_stack_size;
                break;
            }
            if (execution_failed)
                break;
            output.append(input);
        }
        else
        {
            const auto capacity = builtin == SferaMbcRuntimeBuiltin::CopyString && argument_count == 3 ? nextInteger() : 0;
            if (execution_failed)
                break;
            if (builtin == SferaMbcRuntimeBuiltin::CopyString)
                length = copyString(output, input, capacity);
            else
            {
                const std::size_t required = count + 1u;
                if (required > output.size())
                {
                    destination.diagnoseRange(SferaNumeric::lowWord(required));
                    break;
                }
                const auto copied = output.writePadded(input, count);
                length = SferaNumeric::lowWord(copied + 1);
            }
            if (!destination.contains(length))
                destination.diagnoseRange(length);
        }
        ++value_stack_size;
        break;
    }
    case SferaMbcRuntimeBuiltin::FindString:
    case SferaMbcRuntimeBuiltin::FindStringInsensitive:
    {
        auto &haystack = nextSliceReference();
        const auto needle = nextSliceReference();
        if (execution_failed)
            break;
        const auto text = textIn(haystack);
        const auto match = textIn(needle);
        const auto found = builtin == SferaMbcRuntimeBuiltin::FindString ? text.find(match) : SferaText::findInsensitive(text, match);
        if (found == std::string_view::npos)
            pushSlice({}, SferaMbcValueTypeBytePointer);
        else
        {
            haystack.base += SferaNumeric::lowWord(found);
            pushSlice(haystack, SferaMbcValueTypeBytePointer);
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::StringLength:
    {
        const auto slice = nextSliceReference();
        if (slice.base == 0)
            WorldDiagnostics::warning("ffstrlen(): NULL-pointer dereferencing\n");
        std::uint32_t length = 0;
        if (argument_count > 1)
        {
            const auto limit = nextInteger();
            if (limit > 0)
                length = SferaNumeric::lowWord(SferaText::length(memoryRange(slice.base), limit));
            if (SferaNumeric::signedWord(length) == limit)
                WorldDiagnostics::warning(std::format("ffstrlen(): end of string was not found in buffer of size {}\n", limit));
        }
        else
            length = SferaNumeric::lowWord(SferaText::length(memoryRange(slice.base)));
        pushInteger(length);
        break;
    }
    case SferaMbcRuntimeBuiltin::CompareStrings:
    case SferaMbcRuntimeBuiltin::CompareStringsInsensitive:
    case SferaMbcRuntimeBuiltin::CompareStringsCount:
    case SferaMbcRuntimeBuiltin::CompareStringsCountInsensitive:
    {
        const auto first = nextAddress();
        const auto second = nextAddress();
        const bool optionalInsensitiveCount = builtin == SferaMbcRuntimeBuiltin::CompareStringsInsensitive && argument_count >= 3;
        const bool bounded = optionalInsensitiveCount || builtin == SferaMbcRuntimeBuiltin::CompareStringsCount || builtin == SferaMbcRuntimeBuiltin::CompareStringsCountInsensitive;
        const auto count = bounded ? nextWord() : 0u;
        if (execution_failed)
            break;
        const auto left = bounded ? textIn(first, count) : textIn(first);
        const auto right = bounded ? textIn(second, count) : textIn(second);
        int result = builtin == SferaMbcRuntimeBuiltin::CompareStringsInsensitive || builtin == SferaMbcRuntimeBuiltin::CompareStringsCountInsensitive ? SferaText::compareInsensitive(left, right)
                                                                                                                                                       : SferaText::compare(left, right);
        if (builtin == SferaMbcRuntimeBuiltin::CompareStrings)
            result = (result > 0) - (result < 0);
        pushInteger(result);
        break;
    }
    default:
        return false;
    }
    return true;
}

bool SferaMbcRuntime::activeEffectMatches(const SferaActiveEffect *created, const std::shared_ptr<SferaActiveEffect> &item)
{
    return item.get() == created;
}

bool SferaMbcRuntime::executeVisualBuiltin(SferaMbcRuntimeBuiltin builtin)
{
    switch (builtin)
    {
    case SferaMbcRuntimeBuiltin::Window:
        windowCommand();
        break;
    case SferaMbcRuntimeBuiltin::MouseMotion:
    {
        const auto x = nextInteger();
        const auto y = nextInteger();
        if (!execution_failed)
            pushInteger(x == -2 && y == -2 ? g_sfera_direct_input_runtime.mouse.wheel : x == -1 ? g_sfera_direct_input_runtime.mouse.dx : y == -1 ? g_sfera_direct_input_runtime.mouse.dy : 0);
        break;
    }
    case SferaMbcRuntimeBuiltin::FontSettings:
    {
        const auto &suffix = g_sfera_font_runtime.language_suffix;
        const auto offset = mapMemory(suffix.c_str(), suffix.size() + 1);
        pushSlice({offset, offset, offset + SferaNumeric::lowWord(suffix.size())}, SferaMbcValueTypeBytePointer);
        break;
    }
    case SferaMbcRuntimeBuiltin::DestroyObject:
    case SferaMbcRuntimeBuiltin::DestroyText:
    case SferaMbcRuntimeBuiltin::DestroySprite:
    {
        const auto handle = nextInteger();
        if (execution_failed)
            break;
        if (builtin == SferaMbcRuntimeBuiltin::DestroyObject)
        {
            if (handle != -1)
                g_sfera_world_objects.destroy(handle);
        }
        else if (handle >= 0)
        {
            if (builtin == SferaMbcRuntimeBuiltin::DestroyText)
                WorldGuiControls::destroyText(handle);
            else
                WorldGuiControls::destroySprite(handle);
        }
        active_process->unregisterResource(handle, builtin == SferaMbcRuntimeBuiltin::DestroyObject ? SferaMbcRuntimeResourceKind::worldObject
                                                   : builtin == SferaMbcRuntimeBuiltin::DestroyText ? SferaMbcRuntimeResourceKind::textControl
                                                                                                    : SferaMbcRuntimeResourceKind::spriteControl);
        break;
    }
    case SferaMbcRuntimeBuiltin::SetRenderEnabled:
    {
        const auto handle = nextInteger();
        if (handle < 0)
            break;
        const auto enabled = nextInteger();
        if (!execution_failed)
            SphereRenderCharacterModels::checkedExtended(g_sfera_world_objects.object(handle, "GetObjectPointer"))->render_enabled = enabled != 0;
        break;
    }
    case SferaMbcRuntimeBuiltin::CreateObject:
    {
        const auto name = nextInteger();
        const std::uint32_t kind = nextInteger();
        const auto independent = argument_count > 2 ? nextInteger() : 0;
        if (execution_failed)
            break;
        static constexpr std::array<std::uint32_t, 11> factories{0, 1, 2, 3, 1, 4, 5, 6, 4, 5, 3};
        const auto factory = kind < factories.size() ? factories[kind] : 0;
        const auto filename = textAt(name);
        const auto handle = g_sfera_world_objects.create(filename, independent == 1 ? nullptr : active_process, factory, independent != 1);
        pushInteger(handle);
        if (SferaNumeric::signedWord(handle) < 0)
        {
            reportError(std::format("Error creating object: {}", filename));
            execution_failed = false;
            break;
        }
        auto *object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
        if (object->extended())
        {
            auto &extended = *object->extended();
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
        break;
    }
    case SferaMbcRuntimeBuiltin::Text:
    {
        const auto create = g_sfera_mbc_runtime.values[argument_cursor].type == SferaMbcValueTypeBytePointer;
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
    case SferaMbcRuntimeBuiltin::SceneContext:
    {
        if (argument_count == 0)
            pushInteger(g_sfera_direct_input_runtime.virtual_key);
        const auto kind = nextInteger();
        pushInteger(kind == 0 ? g_sfera_direct_input_runtime.virtual_key : kind == 1 ? g_sfera_direct_input_runtime.character : g_sfera_direct_input_runtime.scan_code);
        break;
    }
    case SferaMbcRuntimeBuiltin::KeyboardState:
    {
        const std::uint32_t key = nextInteger();
        pushInteger(SferaClientApplication::application_active && key < std::size(g_sfera_direct_input_runtime.keyboard_state)
                        ? SferaNumeric::signedByte(g_sfera_direct_input_runtime.keyboard_state[key])
                        : 0);
        break;
    }
    default:
        return false;
    }
    return true;
}

bool SferaMbcRuntime::executeWorldBuiltin(SferaMbcRuntimeBuiltin builtin)
{
    switch (builtin)
    {
    case SferaMbcRuntimeBuiltin::SetAnimation:
    case SferaMbcRuntimeBuiltin::SetFrame:
    {
        const auto handle = nextInteger();
        const auto value = nextInteger();
        const bool secondary = argument_count > 2 && nextInteger() != 0;
        if (argument_count <= 2 && execution_failed)
            break;
        auto *field = builtin == SferaMbcRuntimeBuiltin::SetAnimation ? (secondary ? SphereRenderModelPose::secondaryAnimation(handle) : SphereRenderModelPose::animation(handle))
                                                                      : (secondary ? SphereRenderModelPose::secondaryFrame(handle) : SphereRenderModelPose::frame(handle));
        if (field != nullptr)
            *field = value;
        break;
    }
    case SferaMbcRuntimeBuiltin::AnimationLength:
    {
        const auto handle = nextInteger();
        const auto animation = nextInteger();
        if (!execution_failed)
            pushInteger(SphereRenderModelPose::animationLength(handle, animation));
        break;
    }
    case SferaMbcRuntimeBuiltin::SetInterpolation:
    {
        const auto handle = nextInteger();
        const auto value = nextReal();
        if (!execution_failed)
        {
            auto *field = SphereRenderModelPose::interpolation(handle);
            if (field != nullptr)
                *field = value;
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::ObjectProcess:
    {
        const auto handle = nextInteger();
        if (execution_failed)
            break;
        const auto *object = handle >= 0 ? g_sfera_world_objects.object(handle, "GetProcess") : nullptr;
        const auto *owner = object != nullptr ? WorldObjects::boundProcess(*object) : nullptr;
        pushInteger(owner != nullptr ? owner->process_id : UINT32_MAX);
        break;
    }
    case SferaMbcRuntimeBuiltin::SetPosition:
    case SferaMbcRuntimeBuiltin::MoveWorld:
    {
        const auto handle = nextInteger();
        if (handle < 0)
            break;
        SferaVec3F position;
        position.x = nextReal();
        position.y = nextReal();
        position.z = nextReal();
        auto *object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
        if (object == nullptr)
        {
            active_tag = UINT32_MAX;
            break;
        }
        if (execution_failed)
            break;
        if (builtin == SferaMbcRuntimeBuiltin::SetPosition)
            object->position = position;
        else
            object->position = object->position + position;
        if (SferaNumeric::word(handle) == g_sfera_world_objects.controlled_object_handle)
        {
            g_sfera_motion.tracked_position.x = object->position.x + 333.0f;
            g_sfera_motion.tracked_position.y = object->position.y + 333.0f;
            g_sfera_motion.tracked_position.z = object->position.z + 333.0f;
        }
        if (builtin == SferaMbcRuntimeBuiltin::SetPosition && argument_count >= 5)
        {
            g_sfera_world_objects.updateSpatialIndex(handle);
            if (argument_count == 6)
            {
                nextInteger();
                object->spatial_membership = nextInteger();
            }
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::CommandVelocity:
    {
        const auto handle = nextInteger();
        if (handle < 0)
            break;
        const auto x = nextReal();
        const auto second = nextReal();
        auto *object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
        if (object == nullptr)
        {
            active_tag = UINT32_MAX;
            break;
        }
        if (execution_failed)
            break;
        auto *extended = SphereRenderCharacterModels::checkedExtended(object);
        extended->commanded_velocity.x = x;
        if (argument_count == 4)
        {
            const auto z = nextReal();
            extended->commanded_velocity.y = second;
            extended->commanded_velocity.z = z;
        }
        else
            extended->commanded_velocity.z = second;
        break;
    }
    case SferaMbcRuntimeBuiltin::VerticalVelocity:
    case SferaMbcRuntimeBuiltin::AngularVelocity:
    {
        const auto handle = nextInteger();
        if (handle < 0)
            break;
        float value = 0;
        if (builtin == SferaMbcRuntimeBuiltin::AngularVelocity)
            value = nextReal();
        auto *object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
        if (object == nullptr)
        {
            active_tag = UINT32_MAX;
            break;
        }
        if (builtin == SferaMbcRuntimeBuiltin::VerticalVelocity)
            value = argument_count == 3 ? g_sfera_motion.responseValue(nextInteger()) : nextReal();
        if (!execution_failed)
        {
            auto *extended = SphereRenderCharacterModels::checkedExtended(object);
            if (builtin == SferaMbcRuntimeBuiltin::VerticalVelocity)
                extended->physical_velocity.y = value;
            else
                extended->angular_velocity = value;
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
    case SferaMbcRuntimeBuiltin::ObjectBasis:
    case SferaMbcRuntimeBuiltin::ObjectPosition:
    case SferaMbcRuntimeBuiltin::ObjectRotation:
    {
        const auto handle = nextInteger();
        if (handle < 0)
            break;
        auto *object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
        if (object == nullptr)
        {
            active_tag = UINT32_MAX;
            break;
        }
        if (builtin == SferaMbcRuntimeBuiltin::ObjectPosition)
        {
            auto &destination = nextSliceReference();
            if (execution_failed)
                break;
            if (!destination.contains(sizeof(SferaVec3F)))
                destination.diagnoseRange(sizeof(SferaVec3F));
            writeMemory(destination.base, object->position);
        }
        else
        {
            if (builtin == SferaMbcRuntimeBuiltin::ObjectBasis && g_sfera_mbc_runtime.values[argument_cursor].type != SferaMbcValueTypeRealPointer)
            {
                WorldDiagnostics::warning("g_norm: wrong type of parameter (must be float pointer)\n");
                execution_failed = true;
            }
            const auto destination = nextInteger();
            if (execution_failed)
                break;
            if (builtin == SferaMbcRuntimeBuiltin::ObjectBasis)
            {
                const auto *extended = SphereRenderCharacterModels::checkedExtended(object);
                g_sfera_world_objects.recalculateBasis(handle);
                if (destination == 0)
                    WorldDiagnostics::warning("NULL-pointer dereferencing: ffg_norm\n");
                writeMemory(destination, extended->orientation_basis[0]);
            }
            else
            {
                if (destination == 0)
                    WorldDiagnostics::warning("NULL-pointer dereferencing: ffg_abg\n");
                writeMemory(destination, object->rotation);
            }
        }
        break;
    }
    case SferaMbcRuntimeBuiltin::EditorPick:
    {
        if (nextInteger() != 0)
            break;
        const auto distance = nextInteger();
        const auto position = nextInteger();
        if (!execution_failed)
        {
            if (distance != 0)
                writeMemory(distance, 0.0f);
            if (position != 0)
                writeMemory(position, SferaVec3F{});
            pushInteger(UINT32_MAX);
        }
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
    case SferaMbcRuntimeBuiltin::PositionX:
    case SferaMbcRuntimeBuiltin::PositionY:
    case SferaMbcRuntimeBuiltin::PositionZ:
    case SferaMbcRuntimeBuiltin::RotationX:
    case SferaMbcRuntimeBuiltin::RotationY:
    case SferaMbcRuntimeBuiltin::RotationZ:
    {
        const auto handle = nextInteger();
        const bool position = builtin <= SferaMbcRuntimeBuiltin::PositionZ;
        const auto *object = g_sfera_world_objects.object(handle, position ? "GetPos" : "GetAngles");
        if (object == nullptr)
        {
            pushReal(0.0f);
            break;
        }
        const std::size_t axis = builtin == SferaMbcRuntimeBuiltin::PositionX || builtin == SferaMbcRuntimeBuiltin::RotationX   ? 0
                                 : builtin == SferaMbcRuntimeBuiltin::PositionY || builtin == SferaMbcRuntimeBuiltin::RotationY ? 1
                                                                                                                                : 2;
        if (!position || !execution_failed)
            pushReal((position ? object->position : object->rotation).component(axis));
        break;
    }
    case SferaMbcRuntimeBuiltin::SetRotation:
    case SferaMbcRuntimeBuiltin::MoveLocal:
    case SferaMbcRuntimeBuiltin::MoveForward:
    case SferaMbcRuntimeBuiltin::Rotate:
    {
        const auto handle = nextInteger();
        if (builtin == SferaMbcRuntimeBuiltin::SetRotation && handle < 0)
            break;
        SferaVec3F value{};
        if (builtin == SferaMbcRuntimeBuiltin::MoveForward)
            value.z = nextReal();
        else
        {
            value.x = nextReal();
            value.y = nextReal();
            value.z = nextReal();
        }
        if (builtin == SferaMbcRuntimeBuiltin::SetRotation)
        {
            auto *object = g_sfera_world_objects.object(handle, "GetObjectPointer");
            if (object == nullptr)
                active_tag = UINT32_MAX;
            else if (!execution_failed)
                object->rotation = value;
        }
        else if (!execution_failed)
        {
            if (builtin == SferaMbcRuntimeBuiltin::Rotate)
                g_sfera_world_objects.rotate(handle, value);
            else
                g_sfera_world_objects.moveLocal(handle, value);
        }
        break;
    }
    default:
        return false;
    }
    return true;
}
